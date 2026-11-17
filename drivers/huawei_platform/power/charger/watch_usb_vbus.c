// SPDX-License-Identifier: GPL-2.0
/*
 * watch_usb_vbus.c
 *
 * watch usb vbus for power module
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
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/log/hw_log.h>
#include <securec.h>
#include <linux/platform_drivers/usb/chip_usb.h>
#include <platform_include/basicplatform/linux/mfd/pmic_platform.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/workqueue.h>
#include <linux/pm_wakeup.h>

#define HWLOG_TAG watch_usb_vbus
HWLOG_REGIST();

#define WIRELESS_RX_DEFAULT      177

struct watch_usb_vbus_device_info {
	struct device *dev;
	int wireless_rx;
	struct delayed_work handle_work;
};
static struct watch_usb_vbus_device_info *g_di;

static inline void watch_usb_vbus_parse_dts(struct watch_usb_vbus_device_info *di,
	struct device_node *np)
{
	int ret;

	ret = of_property_read_u32(np, "wireless_rx", (u32 *)&di->wireless_rx);
	if (ret) {
		hwlog_err("get wireless_rx fail\n");
		di->wireless_rx = WIRELESS_RX_DEFAULT;
	}
}

static void watch_usb_vbus_handle_work(struct work_struct *work)
{
	hwlog_info("watch_usb_vbus_handle_work\n");
	if (!gpio_get_value(g_di->wireless_rx)) {
		if (pmic_get_vbus_status()) {
			power_event_bnc_notify(POWER_BNT_CONNECT, POWER_NE_USB_CONNECT, NULL);
			hwlog_info("USB CONNECT\n");
			chip_usb_otg_event(CHARGER_CONNECT_EVENT);
		} else {
			power_event_bnc_notify(POWER_BNT_CONNECT, POWER_NE_USB_DISCONNECT, NULL);
			hwlog_info("USB DISCONNECT\n");
			chip_usb_otg_event(CHARGER_DISCONNECT_EVENT);
		}
	}
	pm_relax(g_di->dev);
}

static int watch_usb_vbus_handler(struct notifier_block *this,
	unsigned long val, void *data)
{
	hwlog_info("watch_usb_vbus_handler\n");
	pm_stay_awake(g_di->dev);
	mod_delayed_work(system_wq, &g_di->handle_work, msecs_to_jiffies(200));
	return 0;
}

static struct notifier_block watch_usb_vbus_nb = {
	.notifier_call = watch_usb_vbus_handler,
	.priority = INT_MAX,
};

static int watch_usb_vbus_probe(struct platform_device *pdev)
{
	g_di = kzalloc(sizeof(*g_di), GFP_KERNEL);
	if (!g_di)
		return -ENOMEM;

	g_di->dev = &pdev->dev;
	device_init_wakeup(g_di->dev, true);
	watch_usb_vbus_parse_dts(g_di, g_di->dev->of_node);
	INIT_DELAYED_WORK(&g_di->handle_work, watch_usb_vbus_handle_work);
	usb_vbus_register_notify(&watch_usb_vbus_nb);

	hwlog_info("watch usb vbus probe ok\n");
	return 0;
}

static int watch_usb_vbus_remove(struct platform_device *pdev)
{
	if (!g_di)
		return -ENODEV;

	usb_vbus_unregister_notify(&watch_usb_vbus_nb);
	cancel_delayed_work_sync(&g_di->handle_work);
	device_init_wakeup(g_di->dev, false);
	kfree(g_di);
	g_di = NULL;
	hwlog_info("watch usb vbus remove ok\n");
	return 0;
}

static const struct of_device_id watch_usb_vbus_match_table[] = {
	{
		.compatible = "huawei,watch_usb_vbus",
		.data = NULL,
	},
	{},
};

static struct platform_driver watch_usb_vbus_driver = {
	.probe = watch_usb_vbus_probe,
	.remove = watch_usb_vbus_remove,
	.driver = {
		.name = "huawei,watch_usb_vbus",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(watch_usb_vbus_match_table),
	},
};

static int __init watch_usb_vbus_init(void)
{
	return platform_driver_register(&watch_usb_vbus_driver);
}

static void __exit watch_usb_vbus_exit(void)
{
	platform_driver_unregister(&watch_usb_vbus_driver);
}

module_init(watch_usb_vbus_init);
module_exit(watch_usb_vbus_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("watch usb vbus module driver");
MODULE_AUTHOR("HUAWEI Inc");
