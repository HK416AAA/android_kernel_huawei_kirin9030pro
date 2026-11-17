/*
 * echub_decimal.c
 *
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/of.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include "securec.h"
#include "echub_battery.h"
#include "ospm_printf.h"
#include "echub_decimal.h"

#define DECIMAL_COUNT_BASE 10000
#define DECIMAL_DIVISOR 100

#define DECIMAL_RD_BUF_SIZE        64
#define DECIMAL_WR_BUF_SIZE        32
#define DECIMAL_DEFAULT_LEVEL      (-1)

#define DECIMAL_WAIT_TIME          30
#define DECIMAL_DEFAULT_BASE       100

#define CALCULATE_DISABLE  0
#define CALCULATE_ENABLE   1

static struct echub_decimal_dev *g_decimal_dev = NULL;

struct echub_decimal_dev *echub_decimal_get_dev(void)
{
	if (!g_decimal_dev) {
		echub_err("[%s] g_soc_decimal_dev is null\n", __func__);
		return NULL;
	}
	return g_decimal_dev;
}

static int echub_get_filter_soc(void)
{
	int soc;
	struct echub_batt_device_info *di = echub_get_batt_di();
	if (di == NULL) {
		echub_err("%s di is null\n", __func__);
		return 0;
	}

	// eg: the capacity 65, and the decimal part is 33 (two digits are reserved). The total SOC value is 6533.
	soc = di->capacity * DECIMAL_DIVISOR;
	if (di->bat_fcc > 0)
		soc += (di->bat_rm * DECIMAL_COUNT_BASE / di->bat_fcc) % DECIMAL_DIVISOR;
	return soc;
}

static u32 echub_decimal_get_soc(struct echub_decimal_dev *l_dev)
{
	int soc;

	if (!l_dev->info.start || l_dev->info.level == DECIMAL_DEFAULT_LEVEL)
		soc = echub_get_filter_soc();
	else
		soc = l_dev->info.soc;
	return soc;
}

static void soc_decimal_init_fifo(struct echub_decimal_dev *l_dev)
{
	int curr_soc;
	int i;
	int ui_soc;
	int bat_cap = 0;
	
    if (!l_dev) {
		echub_err("[%s] echub_decimal_dev is NULL\n", __func__);
		return;
	}
    power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_CAPACITY, &bat_cap,
		POWER_SUPPLY_DEFAULT_CAPACITY, 1);
	echub_info("[%s] bat_cap = %d\n", __func__, bat_cap);
	curr_soc = echub_get_filter_soc();
	ui_soc = bat_cap * 100; // Increase 100 times to reserve two decimal places.
	curr_soc = curr_soc < ui_soc ? ui_soc : curr_soc;

	l_dev->info.fifo.sum = 0;
	for (i = 0; i < DECIMAL_WINDOW_LEN; i++) {
		l_dev->info.fifo.filter[i] = curr_soc;
		l_dev->info.fifo.sum += curr_soc;
	}

	l_dev->info.fifo.index = 0;
	l_dev->info.fifo.curr_samples = 0;
	l_dev->info.fifo.init_soc = curr_soc;
	l_dev->info.soc = curr_soc;
	echub_err("[%s] init decimal_soc=%d, ui_soc=%d\n", __func__, l_dev->info.fifo.init_soc, ui_soc);
}

static u32 soc_decimal_pulling_fifo(struct echub_decimal_dev *l_dev, u32 soc)
{
	int index;
	index = l_dev->info.fifo.index % DECIMAL_WINDOW_LEN;
	l_dev->info.fifo.sum -= l_dev->info.fifo.filter[index];
	l_dev->info.fifo.filter[index] = soc;
	l_dev->info.fifo.sum += soc;
	l_dev->info.fifo.index++;
	return l_dev->info.fifo.sum / DECIMAL_WINDOW_LEN;
}

static u32 soc_decimal_calculate_soc(struct echub_decimal_dev *l_dev)
{
	struct echub_decimal_calc calc;
	calc.base = l_dev->info.para.base;
	calc.samples = l_dev->info.para.samples;
	calc.curr_samples = l_dev->info.fifo.curr_samples;
	calc.init_soc = l_dev->info.fifo.init_soc;

	if (calc.base == 0) {
		echub_err("base is 0, use default base\n");
		calc.base = DECIMAL_DEFAULT_BASE;
	}

	/* first: get decimal soc */
	if (calc.curr_samples < calc.samples && (calc.init_soc < 100 * calc.base)) { // 100 is battery full
		if (calc.init_soc < 80 * calc.base)    // Battery Percentage < 80%
			calc.curr_soc = calc.init_soc + (calc.curr_samples / 3) + 3; // curr_soc + 1 every 3 cycles
		else if ((calc.init_soc >= 80 * calc.base) && (calc.init_soc < 90 * calc.base)) // Battery Percentage 80%~90%
			calc.curr_soc = calc.init_soc + (calc.curr_samples / 4); // curr_soc + 1 every 4 cycles
		else
			calc.curr_soc = calc.init_soc + (calc.curr_samples / 5); // curr_soc + 1 every 5 cycles
		l_dev->info.fifo.curr_samples++;
	} else {
		return echub_get_filter_soc();
	}

	/* second : filter decimal soc */
	calc.rep_soc = soc_decimal_pulling_fifo(l_dev, calc.curr_soc);
	calc.round_soc = calc.rep_soc / calc.base;
	calc.remain_soc = calc.rep_soc % calc.base;

	echub_info("[%s] samples[%d]: curr_soc=%d rep_soc=%d round=%d remain=%d\n",
		__func__, l_dev->info.fifo.curr_samples,
		calc.curr_soc, calc.rep_soc, calc.round_soc, calc.remain_soc);

	echub_capacity_sync_filter(calc.rep_soc, calc.round_soc, calc.base);
	return calc.rep_soc;
}

static void soc_decimal_timer_start(struct echub_decimal_dev *l_dev)
{
	int time;

	if (!l_dev) {
		echub_err("[%s] echub_decimal_dev is NULL\n", __func__);
		return;
	}
	time = l_dev->info.para.interval;
	hrtimer_start(&l_dev->timer,
		ktime_set(time / MSEC_PER_SEC, (time % MSEC_PER_SEC) * USEC_PER_SEC), HRTIMER_MODE_REL);
}

static void echub_decimal_timer_work(struct work_struct *work)
{
	struct echub_decimal_dev *l_dev = echub_decimal_get_dev();
	if (!l_dev) {
		echub_err("[%s] echub_decimal_dev is NULL\n", __func__);
		return;
	}

	if (!l_dev->info.start)
		goto restart_work;
	if (l_dev->info.level == DECIMAL_DEFAULT_LEVEL)
		goto restart_work;
	/* must exit timer when current samples is exceed specified samples */
	if (l_dev->info.fifo.curr_samples >= l_dev->info.para.samples)
		goto restart_work;
	l_dev->info.soc = soc_decimal_calculate_soc(l_dev);
	soc_decimal_timer_start(l_dev);
	return;

restart_work:
	echub_err("[%s] restart_work do nothing\n", __func__);
}

static enum hrtimer_restart soc_decimal_timer_func(struct hrtimer *timer)
{
	struct echub_decimal_dev *l_dev = echub_decimal_get_dev();
	if (!l_dev || !timer) {
		echub_err("[%s] l_dev or timer is NULL\n", __func__);
		return HRTIMER_NORESTART;
	}
	queue_work(system_highpri_wq, &l_dev->echub_decimal_timer_work);
	return HRTIMER_NORESTART;
}

static void soc_decimal_select_para_level(struct echub_decimal_dev *l_dev,
	int type, const void *data)
{
	u32 power;
	int i;

	if (!l_dev || !data) {
		echub_err("input para is null\n");
		goto fail_get_level;
	}

	power = *(u32 *)data;
	echub_info("[%s] power=%d, para_level=%d\n", __func__, power, l_dev->para_level);

	for (i = 0; i < l_dev->para_level; i++) {
		echub_info("l_dev->para[%d].min_pwr=%d, l_dev->para[%d].max_pwr=%d\n",
					i, l_dev->para[i].min_pwr, i, l_dev->para[i].max_pwr);
		if ((type == l_dev->para[i].type) &&
			(power >= l_dev->para[i].min_pwr) &&
			(power < l_dev->para[i].max_pwr)) {
			l_dev->info.level = i;
			return;
		}
	}

fail_get_level:
	l_dev->info.level = DECIMAL_DEFAULT_LEVEL;
}

static void soc_decimal_reset_para(struct echub_decimal_dev *l_dev)
{
	int ret;
    
    ret = memset_s(&l_dev->info, sizeof(l_dev->info), 0, sizeof(l_dev->info));
    if (ret != 0) {
        echub_err("memset_s failed:%s--%d\n", __FUNCTION__, __LINE__);
        return;
    }
	l_dev->info.level = DECIMAL_DEFAULT_LEVEL;
	l_dev->info.soc = echub_get_filter_soc();
}

static int soc_decimal_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct echub_decimal_dev *l_dev = echub_decimal_get_dev();
	if (!l_dev || !data) {
		echub_err("[%s] echub_decimal_dev is NULL\n", __func__);
		return NOTIFY_OK;
	}
	switch (event) {
	case POWER_NE_SOC_DECIMAL_DC:
		soc_decimal_select_para_level(l_dev, 0, data);
		break;
	case POWER_NE_CHARGING_STOP:
		soc_decimal_reset_para(l_dev);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

#ifdef CONFIG_SYSFS
static ssize_t decimal_start_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t len)
{
	struct echub_decimal_dev *l_dev = echub_decimal_get_dev();
	int start = 0xff;
	char user[DECIMAL_WR_BUF_SIZE] = { 0 };

	if (!buf || !l_dev) {
		echub_err("[%s] buf is NULL\n", __func__);
        return -EINVAL;
	}
	/* 2: the fields of "user value" */
	if (sscanf_s(buf, "%s %d", user, sizeof(user), &start) != 2) { // 2: num of scanf para
		echub_err("[%s] unable to parse input:%s\n", __func__, buf);
		return -EINVAL;
	}
	// 3: exit when get start invalid(<0 or >1)
	if ((start < CALCULATE_DISABLE) || (start > CALCULATE_ENABLE)) {
		echub_err("[%s] start value is invalid\n", __func__);
		return -EINVAL;
	}
	echub_info("[%s]set: start=%d, level=%d, para_level=%d\n", __func__, start, l_dev->info.level, l_dev->para_level);
	// 4: exit when get start = 0, info.start set to 0
	if (start == CALCULATE_DISABLE) {
		echub_info("[%s] get start is 0, return with info.start 0\n", __func__);
		l_dev->info.start = start;
		return len;
	}
	// 5: exit when info.start=start= 1, info.start set to 1
	if (l_dev->info.start == start) {
		echub_err("[%s] ignore the same start event\n", __func__);
		return len;
	}
	/* 6. delay 30 ms and wait for info.level to update when info.level is default level*/
	if (l_dev->info.level == DECIMAL_DEFAULT_LEVEL)
		msleep(DECIMAL_WAIT_TIME);
    // 7. exit when info.level invalid
	if ((l_dev->info.level == DECIMAL_DEFAULT_LEVEL) ||
		(l_dev->info.level < 0) ||
		(l_dev->info.level >= l_dev->para_level)) {
		echub_err("[%s] get l_dev->info.level fail:%d\n", __func__, l_dev->info.level);
		return len;
	}
	// 8. int para and do deciaml work
	l_dev->info.start = start;
	l_dev->info.para.type = l_dev->para[l_dev->info.level].type;
	l_dev->info.para.min_pwr = l_dev->para[l_dev->info.level].min_pwr;
	l_dev->info.para.max_pwr = l_dev->para[l_dev->info.level].max_pwr;
	l_dev->info.para.base = l_dev->para[l_dev->info.level].base;
	l_dev->info.para.samples = l_dev->para[l_dev->info.level].samples;
	l_dev->info.para.interval = l_dev->para[l_dev->info.level].interval;
	soc_decimal_init_fifo(l_dev);
	soc_decimal_timer_start(l_dev);
	return len;
}

static ssize_t decimal_soc_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int ret;
	struct echub_decimal_dev *l_dev = echub_decimal_get_dev();

    if (!l_dev || !buf) {
		echub_err("[%s] input paras is NULL\n", __func__);
		return -EINVAL;
	}
	ret = snprintf_s(buf, DECIMAL_RD_BUF_SIZE, DECIMAL_RD_BUF_SIZE, "%d\n", echub_decimal_get_soc(l_dev));
	return ret;
}

static DEVICE_ATTR(start, 0220, NULL, decimal_start_store);
static DEVICE_ATTR(soc, 0440, decimal_soc_show, NULL);

static struct attribute *echub_decimal_attributes[] = {
	&dev_attr_start.attr,
	&dev_attr_soc.attr,
	NULL,
};

static const struct attribute_group echub_decimal_group = {
	.attrs = echub_decimal_attributes,
};

static struct device *echub_decimal_create_group(struct device *dev)
{
	return power_sysfs_create_group("hw_power", "soc_decimal",
		&echub_decimal_group);
}

static void echub_decimal_remove_group(struct device *dev)
{
	if (!dev) {
		echub_err("[%s] dev is NULL\n", __func__);
		return;
	}
	power_sysfs_remove_group(dev, &echub_decimal_group);
}
#else
static inline struct device *echub_decimal_create_group(struct device *dev)
{
	return NULL;
}

static inline void echub_decimal_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */
static int echub_decimal_parse_dts(struct device_node *np, struct echub_decimal_dev *l_dev)
{
	int len, ret, i, j;
	u32 para[DECIMAL_PARA_LEVEL * DECIMAL_ITEM_NUM] = { 0 };

	if (!np || !l_dev) {
		echub_err("[%s] input paras NULL\n", __func__);
		return -EINVAL;
	}
    len = of_property_count_u32_elems(np, "para");
	if (len < 0)
		return -EINVAL;
	ret = of_property_read_u32_array(np, "para", para, len);
	if (ret < 0)
		return -EINVAL;
	l_dev->para_level = len / DECIMAL_ITEM_NUM;
	for (i = 0; i < len / DECIMAL_ITEM_NUM; i++) {
		j = DECIMAL_ITEM_NUM * i;
		l_dev->para[i].type = para[j + DECIMAL_ITEM_TYPE];
		l_dev->para[i].min_pwr = para[j + DECIMAL_ITEM_MIN_PWR];
		l_dev->para[i].max_pwr = para[j + DECIMAL_ITEM_MAX_PWR];
		l_dev->para[i].base = para[j + DECIMAL_ITEM_BASE];
		l_dev->para[i].samples = para[j + DECIMAL_ITEM_SAMPLES];
		l_dev->para[i].interval = para[j + DECIMAL_ITEM_INTERVAL];
	}
	return 0;
}

static int echub_decimal_probe(struct platform_device *pdev)
{
	int ret;
	struct echub_decimal_dev *l_dev = NULL;
	struct device_node *np = NULL;

	echub_info("[%s] echub_decimal_probe start\n", __func__);
	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;
	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;
	g_decimal_dev = l_dev;
	np = pdev->dev.of_node;
	l_dev->info.level = DECIMAL_DEFAULT_LEVEL;
	l_dev->info.start = 0;

	ret = echub_decimal_parse_dts(np, l_dev);
	if (ret)
		goto fail_free_mem;

	l_dev->soc_nb.notifier_call = soc_decimal_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_SOC_DECIMAL, &l_dev->soc_nb);
	if (ret)
		goto fail_free_mem;
	l_dev->nb.notifier_call = soc_decimal_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CHARGING, &l_dev->nb);
	if (ret)
		goto fail_regist_event;

	INIT_WORK(&l_dev->echub_decimal_timer_work, echub_decimal_timer_work);
	l_dev->dev = echub_decimal_create_group(&pdev->dev);
	hrtimer_init(&l_dev->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	l_dev->timer.function = soc_decimal_timer_func;
    echub_info("[%s] echub_decimal_probe end\n", __func__);
	return 0;

fail_regist_event:
	power_event_bnc_unregister(POWER_BNT_CHARGING, &l_dev->nb);
	power_event_bnc_unregister(POWER_BNT_SOC_DECIMAL, &l_dev->soc_nb);

fail_free_mem:
	kfree(l_dev);
	g_decimal_dev = NULL;
	return ret;
}

static int echub_decimal_remove(struct platform_device *pdev)
{
	struct echub_decimal_dev *l_dev = g_decimal_dev;

	if (!l_dev)
		return -ENODEV;

	power_event_bnc_unregister(POWER_BNT_SOC_DECIMAL, &l_dev->soc_nb);
	power_event_bnc_unregister(POWER_BNT_CHARGING, &l_dev->nb);
	echub_decimal_remove_group(l_dev->dev);
	hrtimer_cancel(&l_dev->timer);
	kfree(l_dev);
	g_decimal_dev = NULL;

	return 0;
}

static const struct of_device_id of_echub_decimal_match_tbl[] = {
	{ .compatible = "huawei,echub_decimal" },
	{},
};

static struct platform_driver echub_decimal_driver = {
	.probe = echub_decimal_probe,
	.remove = echub_decimal_remove,
	.driver = {
		.name = "echub_decimal",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(of_echub_decimal_match_tbl),
	},
};

static int __init echub_decimal_init(void)
{
	int ret = platform_driver_register(&echub_decimal_driver);
	return ret;
}

static void __exit echub_decimal_exit(void)
{
	platform_driver_unregister(&echub_decimal_driver);
}

module_init(echub_decimal_init);
module_exit(echub_decimal_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("echub decimal driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
