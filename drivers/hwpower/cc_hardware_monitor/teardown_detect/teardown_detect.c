// SPDX-License-Identifier: GPL-2.0
/*
 * teardown_detect.c
 *
 * teardown detect driver
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <chipset_common/hwpower/hardware_monitor/teardown_detect.h>
#include <linux/string.h>
#include <linux/time.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/timekeeping.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwpower/common_module/power_temp.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_nv.h>
#include <chipset_common/hwpower/common_module/power_time.h>
#include <huawei_platform/inputhub/default/contexthub_drop_event.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>

#define HWLOG_TAG teardown_detect
HWLOG_REGIST();

#define MAX_PER_EVENT_LEN		64

static struct teardown_detect_dev *g_teardown_detect_dev;
static unsigned int g_teardown_battery_devices_total = 0;
static LIST_HEAD(teardown_detect_devinfo_list);

int teardown_battery_device_info_register(const char *dev_name, int poweroff_flag)
{
	struct teardown_battery_info_data *temp = NULL;

	if (!dev_name) {
		hwlog_err("dev_name is null\n");
		return -EINVAL;
	}

	if (g_teardown_battery_devices_total >= MAX_TEARDOWN_BATTERY_DEV_TOTAL) {
		hwlog_err("too much %u valid teardown battery devices info\n", g_teardown_battery_devices_total);
		return -EINVAL;
	}

	temp = kzalloc(sizeof(*temp), GFP_KERNEL);
	if (!temp) {
		hwlog_err("temp null\n");
		return -ENOMEM;
	}

	temp->dev_name = dev_name;
	temp->poweroff_flag = poweroff_flag;
	hwlog_info("teardown_battery_device_info dev_name: %s poweroff_flag: %d\n",
        temp->dev_name, temp->poweroff_flag);
	list_add_tail(&temp->info_node, &teardown_detect_devinfo_list);
	g_teardown_battery_devices_total++;

	return 0;
}

static struct teardown_detect_dev *teardown_detect_get_dev(void)
{
	if (!g_teardown_detect_dev) {
		hwlog_err("g_teardown_detect_dev is null\n");
		return NULL;
	}

	return g_teardown_detect_dev;
}

static void teardown_detect_get_time(struct rtc_time *tm)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct timespec64 event_time_temp;
#else
	struct timeval event_time_temp;
#endif

	power_get_timeofday(&event_time_temp);
	power_get_local_time(&event_time_temp, tm);
}

static int teardown_event_write(int info_in, struct teardown_event_nv_data *event_nv_read,
	struct teardown_event_nv_data *event_nv_save)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	uint8_t event_save = (uint8_t)info_in;
	struct rtc_time tm = { 0 };

	if (!l_dev)
		return -ENODEV;

	teardown_detect_get_time(&tm);
	hwlog_info("event_save:%d, date time is %04d-%02d-%02d %02d:%02d:%02d\n",
		event_save, tm.tm_year + YEAR_SAVE_OFFSET, tm.tm_mon + MOUTH_SAVE_OFFSET,
		tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	if (memcpy_s(&(event_nv_save->event[1]), sizeof(struct teardown_detect_event) * (TEARDOWN_DETECT_EVENT_MAX_NUM - 1),
		event_nv_read, sizeof(struct teardown_detect_event) * (TEARDOWN_DETECT_EVENT_MAX_NUM - 1)))
		return -ENODEV;

	if ((event_save != TEARDOWN_EVENT_BATTERY_MASK) && (event_save != TEARDOWN_EVENT_COVER_MASK)) {
		hwlog_err("save event error\n");
		return -ENODEV;
	}

	event_nv_save->event[0].event_info |= event_save;
	event_nv_save->event[0].time.year = (int8_t)tm.tm_year;
	event_nv_save->event[0].time.month = (int8_t)tm.tm_mon;
	event_nv_save->event[0].time.day = (int8_t)tm.tm_mday;
	event_nv_save->event[0].time.hour = (int8_t)tm.tm_hour;
	if (tm.tm_year + YEAR_SAVE_OFFSET >= YEAR_SAVE_CALI_BENCHMARK) {
		event_nv_save->event[0].event_info |= TEARDOWN_EVENT_TIMECALI_MASK;
		return 0;
	}

	l_dev->refresh_flag = 0;

	return 0;
}

static int teardown_event_aftersale_mark(int info_in, struct teardown_event_nv_data *event_nv_read,
	struct teardown_event_nv_data *event_nv_save)
{
	int ret = -ENODEV;
	int i;
	int time_concat;
	int aftersale_time = info_in;

	if (memcpy_s(event_nv_save, sizeof(struct teardown_event_nv_data),
		event_nv_read, sizeof(struct teardown_event_nv_data)))
		return -ENODEV;

	for (i = 0; i < TEARDOWN_DETECT_EVENT_MAX_NUM; i++) {
		if (!(event_nv_save->event[i].event_info & (TEARDOWN_EVENT_BATTERY_MASK | TEARDOWN_EVENT_COVER_MASK)))
			break;

		if (!(event_nv_save->event[i].event_info & TEARDOWN_EVENT_TIMECALI_MASK)) {
			event_nv_save->event[i].event_info |= TEARDOWN_EVENT_AFTERSALE_MASK;
			ret = 0;
			break;
		}

		time_concat = (event_nv_save->event[i].time.year + YEAR_SAVE_OFFSET) * YEAR_CAL_OFFSET +
			(event_nv_save->event[i].time.month + MOUTH_SAVE_OFFSET) * MOUTH_CAL_OFFSET +
			event_nv_save->event[i].time.day * DAY_CAL_OFFSET +
			event_nv_save->event[i].time.hour;
		hwlog_info("time_concat:%d, aftersale_time:%d\n", time_concat, aftersale_time);

		if (time_concat < aftersale_time)
			break;

		event_nv_save->event[i].event_info |= TEARDOWN_EVENT_AFTERSALE_MASK;
		ret = 0;
	}

	return ret;
}

static int teardown_event_time_refresh(int info_in, struct teardown_event_nv_data *event_nv_read,
	struct teardown_event_nv_data *event_nv_save)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	int ret = -ENODEV;
	int i;
	struct rtc_time tm = { 0 };

	if (!l_dev)
		return -ENODEV;

	teardown_detect_get_time(&tm);
	hwlog_info("date time is %04d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + YEAR_SAVE_OFFSET,
		tm.tm_mon + MOUTH_SAVE_OFFSET, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	if (!(tm.tm_year + YEAR_SAVE_OFFSET >= YEAR_SAVE_CALI_BENCHMARK))
		return -ENODEV;

	if (memcpy_s(event_nv_save, sizeof(struct teardown_event_nv_data),
		event_nv_read, sizeof(struct teardown_event_nv_data)))
		return -ENODEV;

	hwlog_info("time refresh\n");
	for (i = 0; i < TEARDOWN_DETECT_EVENT_MAX_NUM; i++) {
		if (!(event_nv_save->event[i].event_info & (TEARDOWN_EVENT_BATTERY_MASK | TEARDOWN_EVENT_COVER_MASK)) ||
			(event_nv_save->event[i].event_info & TEARDOWN_EVENT_TIMECALI_MASK))
			break;

		event_nv_save->event[i].time.year = (int8_t)tm.tm_year;
		event_nv_save->event[i].time.month = (int8_t)tm.tm_mon;
		event_nv_save->event[i].time.day = (int8_t)tm.tm_mday;
		event_nv_save->event[i].time.hour = (int8_t)tm.tm_hour;
		event_nv_save->event[i].event_info |= TEARDOWN_EVENT_TIMECALI_MASK;
		ret = 0;
	}

	l_dev->refresh_flag = 1;

	return ret;
}

static event_nv_info event_nv_info_array[] = {
	[EVENT_WRITE] = teardown_event_write,
	[EVENT_AFTERSALE_MARK] = teardown_event_aftersale_mark,
	[EVENT_TIME_REFRESH] = teardown_event_time_refresh,
};

static int teardown_read_write_nv_event(int info_in, uint8_t type)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	int ret;
	struct teardown_event_nv_data event_nv_read = {0};
	struct teardown_event_nv_data event_nv_save = {0};

	if (!l_dev)
		return -ENODEV;

	if (type >= EVENT_NV_TYPE_END)
		return -ENODEV;

	mutex_lock(&(l_dev->nv_write_lock));
	ret = power_nv_read(POWER_NV_TEARDOWN, &event_nv_read, sizeof(event_nv_read));
	if (ret) {
		hwlog_err("read power nv read fail\n");
		mutex_unlock(&(l_dev->nv_write_lock));
		return -ENODEV;
	}

	if (event_nv_info_array[type](info_in, &event_nv_read, &event_nv_save)) {
		mutex_unlock(&(l_dev->nv_write_lock));
		return -ENODEV;
	}

	if (!power_cmdline_is_factory_mode()) {
		ret = power_nv_write(POWER_NV_TEARDOWN, &event_nv_save, sizeof(event_nv_save));
		if (ret) {
			hwlog_err("write power nv write fail\n");
			mutex_unlock(&(l_dev->nv_write_lock));
			return -ENODEV;
		}
	}

	mutex_unlock(&(l_dev->nv_write_lock));
	return 0;
}

static int teardown_process_event(int event)
{
	int ret;
	char buf[POWER_DSM_BUF_SIZE_0128] = { 0 };

	if (snprintf_s(buf, sizeof(buf), sizeof(buf) - 1, "teardown_event = %d\n", event) < 0)
		return -ENODEV;
	hwlog_info("teardown_event dmd content: %s\n", buf);
	power_dsm_report_dmd(POWER_DSM_BATTERY, POWER_DSM_BATTERY_TEARDOWN_DETECT, buf);

	ret = teardown_read_write_nv_event(event, EVENT_WRITE);
	if (ret)
		return -ENODEV;

	ret = liblinux_pal_report_hkids_teardown_event(event, "{}");
	if (ret) {
		hwlog_err("liblinux pal report ret value:%d\n", ret);
		return -ENODEV;
	}

	return 0;
}

static int teardown_judge_battery_remove(void)
{
	unsigned int count = 0;
	unsigned int count_poweroff_devices = 0;
	int is_battery_changed;
	struct teardown_battery_info_data *temp = NULL;

	if (g_teardown_battery_devices_total == 0) {
		hwlog_err("none teardown battery device register\n");
		return 0;
	}

	list_for_each_entry(temp, &teardown_detect_devinfo_list, info_node) {
		if (count++ >= g_teardown_battery_devices_total)
			break;

		if (!temp->dev_name)
			continue;

		hwlog_info("teardown_detect_devinfo_list dev_name: %s poweroff_flag: %d\n",
			temp->dev_name, temp->poweroff_flag);
		if (temp->poweroff_flag)
			count_poweroff_devices++;
	}

	is_battery_changed = power_platform_is_battery_removed();
	hwlog_info("power platform is battery changed: %d\n", is_battery_changed);
	if ((count_poweroff_devices == g_teardown_battery_devices_total) && is_battery_changed) {
		hwlog_info("teardown battery remove\n");
		return 1;
	}

	return 0;
}

static void teardown_detect_monitor_work(struct work_struct *work)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	int delay = DELAY_TEARDOWN_DETECT_WORK;
	int soc = 0;
	int ret;
	struct teardown_event_nv_data event_nv = {0};

	if (!l_dev)
		return;

	if (!l_dev->refresh_flag)
		teardown_read_write_nv_event(0, EVENT_TIME_REFRESH);

	if (!l_dev->init_reset_en) {
		l_dev->init_reset_en = 1;
		power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY, &soc, 0, 1);
		hwlog_info("real soc: %d\n", soc);

		if (teardown_judge_battery_remove() && (soc > EVENT_SAVE_SOC_TH))
			teardown_process_event(TEARDOWN_EVENT_BATTERY_MASK);
	}

	if (l_dev->aftersale_en) {
		l_dev->aftersale_en = 0;
		if (teardown_read_write_nv_event(l_dev->aftersale_time, EVENT_AFTERSALE_MARK))
			hwlog_err("aftersale mark fail\n");
	}

	if (l_dev->newboard_clear_en) {
		mutex_lock(&(l_dev->nv_write_lock));
		ret = power_nv_write(POWER_NV_TEARDOWN, &event_nv, sizeof(event_nv));
		mutex_unlock(&(l_dev->nv_write_lock));
		if (ret)
			hwlog_err("newboard clear fail\n");
		else
			l_dev->newboard_clear_en = 0;
	}

	if (!l_dev->refresh_flag | l_dev->newboard_clear_en)
		queue_delayed_work(system_freezable_power_efficient_wq, &l_dev->monitor_work, msecs_to_jiffies(delay));
}

static void teardown_detect_start(struct teardown_detect_dev *l_dev)
{
	int delay = DELAY_TEARDOWN_DETECT_WORK;

	cancel_delayed_work(&l_dev->monitor_work);
	queue_delayed_work(system_freezable_power_efficient_wq, &l_dev->monitor_work, msecs_to_jiffies(delay));
}

static int teardown_cover_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();

	hwlog_info("cover notifier call event:%d\n", event);

	if (!l_dev)
		return NOTIFY_OK;

	if (event == SENSOR_TEARDOWN) {
		if (teardown_process_event(TEARDOWN_EVENT_COVER_MASK))
			return NOTIFY_DONE;
		teardown_detect_start(l_dev);
	}

	return NOTIFY_OK;
}

#ifdef CONFIG_SYSFS
static ssize_t teardown_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	int ret;
	int i;
	int len = 0;
	struct teardown_event_nv_data event_nv_read;

	hwlog_info("teardown_info_show\n");

	if (!l_dev)
		return len;

	mutex_lock(&(l_dev->nv_write_lock));
	ret = power_nv_read(POWER_NV_TEARDOWN, &event_nv_read, sizeof(event_nv_read));
	mutex_unlock(&(l_dev->nv_write_lock));
	if (ret) {
		hwlog_info("read power nv read fail\n");
		return len;
	}

	for (i = 0; i < TEARDOWN_DETECT_EVENT_MAX_NUM; i++) {
		if (!(event_nv_read.event[i].event_info & (TEARDOWN_EVENT_BATTERY_MASK | TEARDOWN_EVENT_COVER_MASK)) ||
			!(event_nv_read.event[i].event_info & TEARDOWN_EVENT_TIMECALI_MASK))
			continue;

		ret = snprintf_s(buf + len, MAX_PER_EVENT_LEN, MAX_PER_EVENT_LEN - 1, "%x:%04d%02d%02d%02d,",
			event_nv_read.event[i].event_info, event_nv_read.event[i].time.year + YEAR_SAVE_OFFSET,
			event_nv_read.event[i].time.month + MOUTH_SAVE_OFFSET,
			event_nv_read.event[i].time.day, event_nv_read.event[i].time.hour);
		if (ret < 0)
			break;
		len += ret;
	}

	return len;
}

static ssize_t teardown_info_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	int aftersale_time;

	if (!l_dev)
		return -EINVAL;

	hwlog_info("teardown_info_store str:%s\n", buf);

	if (!strncmp(buf, "clear_event", strlen("clear_event"))) {
		l_dev->newboard_clear_en = 1;
		teardown_detect_start(l_dev);
		return count;
	}

	if (kstrtoint(buf, POWER_BASE_DEC, &aftersale_time)) {
		hwlog_err("kstrtoint fail\n");
		return -EINVAL;
	}

	if (aftersale_time <= 0 || ((aftersale_time / YEAR_CAL_OFFSET) < YEAR_SAVE_CALI_BENCHMARK)) {
		hwlog_err("aftersale_time out of range\n");
		return -EINVAL;
	}

	l_dev->aftersale_time = aftersale_time;
	l_dev->aftersale_en = 1;
	teardown_detect_start(l_dev);

	return count;
}

static ssize_t teardown_info_nv_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	int ret;
	int i;
	int len = 0;
	int len_ret = 0;
	struct teardown_event_nv_data event_nv_read;

	hwlog_info("teardown_info_nv_show\n");

	if (!l_dev)
		return len;

	mutex_lock(&(l_dev->nv_write_lock));
	ret = power_nv_read(POWER_NV_TEARDOWN, &event_nv_read, sizeof(event_nv_read));
	mutex_unlock(&(l_dev->nv_write_lock));
	if (ret) {
		hwlog_info("read power nv read fail\n");
		return len;
	}

	for (i = 0; i < TEARDOWN_DETECT_EVENT_MAX_NUM; i++) {
		len_ret = snprintf_s(buf + len, MAX_PER_EVENT_LEN, MAX_PER_EVENT_LEN - 1, "event:0x%x, time:%04d-%02d-%02d %02d\n",
			event_nv_read.event[i].event_info, event_nv_read.event[i].time.year + YEAR_SAVE_OFFSET,
			event_nv_read.event[i].time.month + MOUTH_SAVE_OFFSET,
			event_nv_read.event[i].time.day, event_nv_read.event[i].time.hour);
		if (len_ret < 0)
			return len;
		len += len_ret;
	}

	return len;
}

static ssize_t teardown_info_nv_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct teardown_detect_dev *l_dev = teardown_detect_get_dev();
	int ret;
	struct teardown_event_nv_data event_nv = {0};

	hwlog_info("teardown_info_nv_store str:%s\n", buf);

	if (!l_dev)
		return -EINVAL;

	if (!strncmp(buf, "clear", strlen("clear"))) {
		mutex_lock(&(l_dev->nv_write_lock));
		ret = power_nv_write(POWER_NV_TEARDOWN, &event_nv, sizeof(event_nv));
		mutex_unlock(&(l_dev->nv_write_lock));
		if (ret)
			return -EINVAL;
	} else if (!strncmp(buf, "battery", strlen("battery"))) {
		ret = teardown_read_write_nv_event(TEARDOWN_EVENT_BATTERY_MASK, EVENT_WRITE);
		if (ret)
			return -EINVAL;
		teardown_detect_start(l_dev);
		ret = liblinux_pal_report_hkids_teardown_event(TEARDOWN_EVENT_BATTERY_MASK, "{}");
		if (ret) {
			hwlog_err("liblinux pal report ret value:%d\n", ret);
			return -EINVAL;
		}
	} else if (!strncmp(buf, "cover", strlen("cover"))) {
		ret = teardown_read_write_nv_event(TEARDOWN_EVENT_COVER_MASK, EVENT_WRITE);
		if (ret)
			return -EINVAL;
		teardown_detect_start(l_dev);
		ret = liblinux_pal_report_hkids_teardown_event(TEARDOWN_EVENT_COVER_MASK, "{}");
		if (ret) {
			hwlog_err("liblinux pal report ret value:%d\n", ret);
			return -EINVAL;
		}
	} else {
		return -EINVAL;
	}

	return count;
}

static DEVICE_ATTR(teardown_info, 0660, teardown_info_show, teardown_info_store);
static DEVICE_ATTR(teardown_info_nv, 0660, teardown_info_nv_show, teardown_info_nv_store);
static struct attribute *teardown_info_attrs[] = {
	&dev_attr_teardown_info.attr,
	&dev_attr_teardown_info_nv.attr,
	NULL,
};

static const struct attribute_group teardown_info_attr_group = {
	.attrs = teardown_info_attrs,
};

static struct device *teardown_info_create_group(void)
{
	return power_sysfs_create_group("hw_power", "teardown_info",
		&teardown_info_attr_group);
}

static void teardown_info_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &teardown_info_attr_group);
}
#else
static inline struct device *teardown_info_create_group(void)
{
	return NULL;
}

static inline void teardown_info_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static int teardown_detect_probe(struct platform_device *pdev)
{
	struct teardown_detect_dev *l_dev = NULL;
	int ret;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;

	mutex_init(&(l_dev->nv_write_lock));
	INIT_DELAYED_WORK(&l_dev->monitor_work, teardown_detect_monitor_work);

	l_dev->cover_notify.notifier_call = teardown_cover_notifier_call;
	ret = drop_register_blocking_notifier(&(l_dev->cover_notify));
	if (ret < 0)
		goto fail_free_mem;

	l_dev->dev = teardown_info_create_group();

	platform_set_drvdata(pdev, l_dev);
	g_teardown_detect_dev = l_dev;

	teardown_detect_start(l_dev);

	return 0;

fail_free_mem:
	kfree(l_dev);
	g_teardown_detect_dev = NULL;
	return ret;
}

static int teardown_detect_remove(struct platform_device *pdev)
{
	struct teardown_detect_dev *l_dev = platform_get_drvdata(pdev);

	if (!l_dev)
		return -ENODEV;

	cancel_delayed_work(&l_dev->monitor_work);
	drop_unregister_blocking_notifier(&(l_dev->cover_notify));
	teardown_info_remove_group(l_dev->dev);
	platform_set_drvdata(pdev, NULL);
	kfree(l_dev);
	g_teardown_detect_dev = NULL;

	return 0;
}

#ifdef CONFIG_PM
static int teardown_detect_suspend(struct platform_device *pdev,
	pm_message_t state)
{
	struct teardown_detect_dev *l_dev = platform_get_drvdata(pdev);

	hwlog_info("suspend begin\n");

	if (!l_dev)
		return 0;

	cancel_delayed_work(&l_dev->monitor_work);
	return 0;
}

static int teardown_detect_resume(struct platform_device *pdev)
{
	struct teardown_detect_dev *l_dev = platform_get_drvdata(pdev);

	hwlog_info("resume begin\n");

	if (!l_dev)
		return 0;

	if (!l_dev->refresh_flag)
		teardown_detect_start(l_dev);
	return 0;
}
#endif /* CONFIG_PM */

static const struct of_device_id teardown_detect_match_table[] = {
	{
		.compatible = "huawei,teardown_detect",
		.data = NULL,
	},
	{},
};

static struct platform_driver teardown_detect_driver = {
	.probe = teardown_detect_probe,
	.remove = teardown_detect_remove,
#ifdef CONFIG_PM
	.suspend = teardown_detect_suspend,
	.resume = teardown_detect_resume,
#endif /* CONFIG_PM */
	.driver = {
		.name = "huawei,teardown_detect",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(teardown_detect_match_table),
	},
};

static int __init teardown_detect_init(void)
{
	return platform_driver_register(&teardown_detect_driver);
}

static void __exit teardown_detect_exit(void)
{
	platform_driver_unregister(&teardown_detect_driver);
}

device_initcall(teardown_detect_init);
module_exit(teardown_detect_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei teardown detect driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
