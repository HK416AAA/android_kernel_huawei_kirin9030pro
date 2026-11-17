// SPDX-License-Identifier: GPL-2.0
/*
 * rtc_to_ship_mode.c
 *
 * rtc to ship mode for power module
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

#include <linux/alarmtimer.h>
#include <linux/delay.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/time.h>
#include <chipset_common/hwpower/common_module/power_debug.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/hardware_monitor/ship_mode.h>
#include <chipset_common/log/hw_log.h>
#include <huawei_platform/power/huawei_watch_charger.h>
#include <securec.h>

#define HWLOG_TAG rtc_to_ship_mode
#define SHIPMODE_PHONE_VERSION_MAX_LEN 28
#define SHIPMODE_DEMO_VERSION         1
#define SHIPMODE_NORMAL_VERSION       0
HWLOG_REGIST();

#define RTC_DEFAULT_TIME      259200
#define DEMO_RTC_DEFAULT_TIME 604800

struct rtc_to_ship_mode_device_info {
	struct device *dev;
	unsigned long time;
};
static struct rtc_to_ship_mode_device_info *g_di;

static uint8_t read_vendor_country_cmdline(void)
{
	char phone_version_buf[SHIPMODE_PHONE_VERSION_MAX_LEN] = { 0 };
	char *pstr = NULL;
	char *dstr = NULL;
	bool checklen = false;
	uint8_t phone_version = 0; // 1:demo 0:Normal
	int ret;

	pstr = strstr(saved_command_line, "vendorcountry=");
	if (!pstr) {
		hwlog_err(" No fastboot vendorcountry info\n");
		return 0;
	}
	pstr += strlen("vendorcountry=");
	dstr = strstr(pstr, " ");
	if (!dstr) {
		hwlog_err(" No find the vendorcountry end\n");
		return 0;
	}
	checklen = SHIPMODE_PHONE_VERSION_MAX_LEN > (unsigned long)(dstr - pstr);
	if (!checklen) {
		hwlog_err(" overrun vendorcountry\n");
		return 0;
	}
	ret = memcpy_s(phone_version_buf, sizeof(phone_version_buf),
		pstr, (unsigned long)(dstr - pstr));
	if (ret != EOK) {
		hwlog_err("phone_version_buf: memcpy_s fail!\n");
		return 0;
	}
	phone_version_buf[dstr - pstr] = '\0';

	hwlog_info("get vendorcountry:%s length:%d\n",
		phone_version_buf, (int)strlen(phone_version_buf));
	if (strstr(phone_version_buf, "demo") != NULL) {
		phone_version = SHIPMODE_DEMO_VERSION;
		hwlog_info("phone_version is demo version\n");
	} else {
		phone_version = SHIPMODE_NORMAL_VERSION;
		hwlog_info("phone_version is normal version\n");
	}
	return phone_version;
}

static inline void rtc_to_ship_mode_parse_dts(struct rtc_to_ship_mode_device_info *di,
	struct device_node *np)
{
	int ret;

	ret = of_property_read_u32(np, "time", (u32 *)&di->time);
	if (ret) {
		hwlog_err("get time fail\n");
		di->time = RTC_DEFAULT_TIME;
	}
	if (read_vendor_country_cmdline() == SHIPMODE_DEMO_VERSION) {
		di->time = DEMO_RTC_DEFAULT_TIME;
	}
}

static int rtc_to_ship_mode_reboot_handler(struct notifier_block *this,
	unsigned long mode, void *cmd)
{
	int ship_mode_status = 0;
	struct timespec tmp_time = {0};

	if (mode == SYS_POWER_OFF) {
		if (!g_di)
			return 0;

		if (!ship_mode_get_work_mode(&ship_mode_status) &&
#if defined(CONFIG_PRODUCT_GLASSES)
			watch_get_dis_shipmode() == STATUS_FALSE &&
#endif		
			ship_mode_status != SHIP_MODE_IN_SHUTDOWN_SHIP) {
			getnstimeofday(&tmp_time);
			set_power_on_alarm(tmp_time.tv_sec + g_di->time, true);
		}
	}
	return 0;
}

static struct notifier_block rtc_to_ship_mode_reboot_nb = {
	.notifier_call = rtc_to_ship_mode_reboot_handler,
	.priority = INT_MAX,
};

static int rtc_to_ship_mode_probe(struct platform_device *pdev)
{
	int ret;

	g_di = kzalloc(sizeof(*g_di), GFP_KERNEL);
	if (!g_di)
		return -ENOMEM;

	g_di->dev = &pdev->dev;
	rtc_to_ship_mode_parse_dts(g_di, g_di->dev->of_node);
	ret = register_reboot_notifier(&rtc_to_ship_mode_reboot_nb);
	if (ret) {
		kfree(g_di);
		g_di = NULL;
		hwlog_err("%s register_watch_reboot_handler fail\n", __func__);
		return ret;
	}

	hwlog_info("rtc to ship mode probe ok\n");
	return 0;
}

static int rtc_to_ship_mode_remove(struct platform_device *pdev)
{
	if (!g_di)
		return -ENODEV;

	kfree(g_di);
	g_di = NULL;
	unregister_reboot_notifier(&rtc_to_ship_mode_reboot_nb);
	hwlog_info("rtc to ship mode remove ok\n");
	return 0;
}

static const struct of_device_id rtc_to_ship_mode_match_table[] = {
	{
		.compatible = "huawei,rtc_to_ship_mode",
		.data = NULL,
	},
	{},
};

static struct platform_driver rtc_to_ship_mode_driver = {
	.probe = rtc_to_ship_mode_probe,
	.remove = rtc_to_ship_mode_remove,
	.driver = {
		.name = "huawei,rtc_to_ship_mode",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(rtc_to_ship_mode_match_table),
	},
};

static int __init rtc_to_ship_mode_init(void)
{
	return platform_driver_register(&rtc_to_ship_mode_driver);
}

static void __exit rtc_to_ship_mode_exit(void)
{
	platform_driver_unregister(&rtc_to_ship_mode_driver);
}

module_init(rtc_to_ship_mode_init);
module_exit(rtc_to_ship_mode_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("rtc to ship mode module driver");
MODULE_AUTHOR("HUAWEI Inc");
