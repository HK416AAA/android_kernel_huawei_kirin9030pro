/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * usb_pm.c
 *
 * usb pm driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, pmicstributed, and mopmicfied under those terms.
 *
 * This program is pmicstributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/hid.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/platform_device.h>
#include <linux/platform_drivers/usb/hiusb.h>
#include <linux/pm_runtime.h>
#include <linux/suspend.h>
#include <linux/usb.h>
#include "../../ospm/echub/lid/echub_lid.h"
#include "../../ospm/usb/multi_port/cs32g050/cs32g050.h"

#define NO_SET 0

struct usb_pm_resource{
	uint8_t hid_get_descriptor_tries_min;
	uint8_t hid_get_descriptor_tries_max;
	struct usb_port_cfgs usb_port_reties_min;
	struct usb_port_cfgs usb_port_reties_max;
};

static struct usb_pm_resource g_usb_pm_resource;

static int usb_pm_prepare(struct device *dev)
{
	int lid_status; // 0:close  1: open
	int dp_status; // have external screen connected  0:no  1:yes 
	bool s3_power_down_flag = false;

	lid_status = get_lid_status();
	dp_status = cs32g050_get_dp_status();
	pr_info("%s get lid_status = %d dp_status = %d\n", __func__, lid_status, dp_status);

	if ((!lid_status) && (!dp_status)) // lid close & don't connect external screen, let usb power down
		s3_power_down_flag = true;
	hiusb_set_s3_power_down_flag(s3_power_down_flag);

	/* set retries */
	if (g_usb_pm_resource.hid_get_descriptor_tries_min) {
		pr_info("set hid get descriptor tries %d\n", g_usb_pm_resource.hid_get_descriptor_tries_min);
		usb_set_hid_get_desc_tries(g_usb_pm_resource.hid_get_descriptor_tries_min);
	}
	usb_set_port_tries(g_usb_pm_resource.usb_port_reties_min);
	return 0;
}

static void usb_pm_complete(struct device *dev)
{
	if (g_usb_pm_resource.hid_get_descriptor_tries_max) {
		pr_info("set hid get descriptor tries %d\n", g_usb_pm_resource.hid_get_descriptor_tries_max);
		usb_set_hid_get_desc_tries(g_usb_pm_resource.hid_get_descriptor_tries_max);
	}
	usb_set_port_tries(g_usb_pm_resource.usb_port_reties_max);
}

static u32 read_property(struct device_node *node, const char *name)
{
	if (!node || !name)
		return NO_SET;

    u32 ret = 0;
	if (of_property_read_u32(node, name, &ret)) {
		pr_err("of property read error, name = %s , ret = %d\n", name, ret);
		return NO_SET;
	}
    return ret;
}

static void usb_pm_get_resource(struct device *dev)
{
    if (!dev || !dev->of_node)
		return;
	g_usb_pm_resource.hid_get_descriptor_tries_min = read_property(dev->of_node, "hid_get_descriptor_tries_min");
	g_usb_pm_resource.usb_port_reties_min.port_init_tries = read_property(dev->of_node, "usb_port_init_tries_min");
	g_usb_pm_resource.usb_port_reties_min.get_maxpacket0_tries = read_property(dev->of_node, "get_maxpacket0_tries_min");
	g_usb_pm_resource.usb_port_reties_min.get_descriptor_tries = read_property(dev->of_node, "get_descriptor_tries_min");
	g_usb_pm_resource.usb_port_reties_min.set_address_tries = read_property(dev->of_node, "set_address_tries_min");
	g_usb_pm_resource.usb_port_reties_min.port_reset_tries = read_property(dev->of_node, "port_reset_tries_min");
	g_usb_pm_resource.hid_get_descriptor_tries_max = read_property(dev->of_node, "hid_get_descriptor_tries_max");
	g_usb_pm_resource.usb_port_reties_max.port_init_tries = read_property(dev->of_node, "usb_port_init_tries_max");
	g_usb_pm_resource.usb_port_reties_max.get_maxpacket0_tries = read_property(dev->of_node, "get_maxpacket0_tries_max");
	g_usb_pm_resource.usb_port_reties_max.get_descriptor_tries = read_property(dev->of_node, "get_descriptor_tries_max");
	g_usb_pm_resource.usb_port_reties_max.set_address_tries = read_property(dev->of_node, "set_address_tries_max");
	g_usb_pm_resource.usb_port_reties_max.port_reset_tries = read_property(dev->of_node, "port_reset_tries_max");	
}

static int usb_pm_probe(struct platform_device *pdev)
{
	pr_info("%s +\n", __func__);
	if (!pdev)
		return 0;

    usb_pm_get_resource(&pdev->dev);
	return 0;
}

static int usb_pm_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct dev_pm_ops usb_pm_ops = {
	.prepare = usb_pm_prepare,
	.complete = usb_pm_complete,
};

static const struct of_device_id usb_pm_match[] = {
	{ .compatible = "huawei,usb-pm" },
	{},
};
MODULE_DEVICE_TABLE(of, usb_pm_match);

struct platform_driver usb_pm_driver = {
	.probe = usb_pm_probe,
	.remove = usb_pm_remove,
	.driver = {
		.name = "usb_pm_drv",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(usb_pm_match),
		.pm = &usb_pm_ops,
	},
};

int __init usb_pm_init(void)
{
	int ret;

	ret = platform_driver_register(&usb_pm_driver);
	if (ret)
		pr_err("usb_pm_notif_block register err\n");

	return ret;
}

void __exit usb_pm_exit(void)
{
	platform_driver_unregister(&usb_pm_driver);
}

module_init(usb_pm_init);
module_exit(usb_pm_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei usb pm driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");