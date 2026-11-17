/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * File name: cable_in_detect.c
 * Description: This program detect the cable_in status
 * Author: zhangjunsheng
 * Version: 1.0
 * Date:  2024/07/16
 *
 */
#include "cable_in_detect.h"
#include <linux/device.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <huawei_platform/log/hw_log.h>
#include <securec.h>
#define HWLOG_TAG cable_in_detect
HWLOG_REGIST();

#define CABLE_MAX_NUMS 25

static int cable_in_nums = -1;
char *cable_in_gpio = NULL;
static int cable_in_gpio_total = 0;
static int cable_in_gpio_atoi[CABLE_MAX_NUMS * 4 + 1] = {0};

static int s_ret = 0;
static struct cable_in_info *di = NULL;
static struct device *cable_in_dev = NULL;
static struct class *hw_cable_in_detect_class = NULL;

static ssize_t cable_in_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	char gpio_value[CABLE_MAX_NUMS * 4 + 1] = {0};

	int i = 0;
	int ret = 0;

	if ((cable_in_nums <= 0) || (cable_in_nums > CABLE_MAX_NUMS)) {
		hwlog_err("%s : The cable_in_nums is error!\n", __func__);
		return 0;
	}

	hwlog_err("%s cable_in_nums is %d\n", __func__, cable_in_nums);
	hwlog_err("%s cable_in_gpio is %s\n", __func__, cable_in_gpio);

	for (i = 0; i < cable_in_nums * 4 - 1; i++) {
		cable_in_gpio_atoi[i] = (int)(cable_in_gpio[i]);
		if (i % 4 == 3) {
			if (cable_in_gpio_atoi[i] != ' ') {
				hwlog_err("%s cable_in_gpio is invalid,i=%d.\n", __func__, i);
				return 0;
			}
		} else {
			if ((cable_in_gpio_atoi[i] < '0') || (cable_in_gpio_atoi[i] > '9')) {
				hwlog_err("%s cable_in_gpio is invalid,i=%d.\n", __func__, i);
				return 0;
			}
		}
		hwlog_err("%s cable_in_gpio_atoi[i] is %d\n", __func__, cable_in_gpio_atoi[i]);
	}

	for (i = 0; i < cable_in_nums; i++) {
		cable_in_gpio_total = (cable_in_gpio_atoi[i * 4] - '0') * 100 +
							  (cable_in_gpio_atoi[i * 4 + 1] - '0') * 10 +
							  cable_in_gpio_atoi[i * 4 + 2] - '0';
		hwlog_err("%s cable_in_gpio_total is %d\n", __func__, cable_in_gpio_total);
		gpio_value[i] = gpio_get_value(cable_in_gpio_total) + '0';
	}

	ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n", gpio_value);

	hwlog_err("%s ret is %d\n", __func__, ret);

	return ret;
}

/* files create */
static DEVICE_ATTR(cable_in_status, S_IRUGO, cable_in_show, NULL);

static struct attribute *cable_in_attrs[] = {
	&dev_attr_cable_in_status.attr,
	NULL
};

static const struct attribute_group cable_in_sysfs_attr_group = {
	.attrs = cable_in_attrs,
};

static int cable_in_detect_probe(struct platform_device *pdev)
{
	struct device_node *cable_in_node = pdev->dev.of_node;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;

	if (of_property_read_u32(cable_in_node, "cable_in_nums", (u32 *)(&cable_in_nums))) {
		s_ret = -1;
		goto free_di;
	}

	if (of_property_read_string(cable_in_node, "cable_in_gpio", (const char **)(&cable_in_gpio))) {
		s_ret = -1;
		goto free_di;
	}

	hw_cable_in_detect_class = class_create(THIS_MODULE, "hw_cable_in");
	if (IS_ERR(hw_cable_in_detect_class)) {
		s_ret = PTR_ERR(hw_cable_in_detect_class);
		goto free_di;
	}

	cable_in_dev = device_create(hw_cable_in_detect_class, NULL, 0, NULL, "cable_in");
	if (cable_in_dev == NULL) {
		s_ret = -1;
		goto free_class;
	}
	s_ret = sysfs_create_group(&di->dev->kobj, &cable_in_sysfs_attr_group);
	if (s_ret) {
		s_ret = -1;
		goto free_device;
	}

	s_ret = sysfs_create_link(&cable_in_dev->kobj, &di->dev->kobj, "cable_in_data");
	if (s_ret) {
		s_ret = -1;
		goto free_group;
	}

	return 0;

free_group:
	sysfs_remove_group(&di->dev->kobj, &cable_in_sysfs_attr_group);
free_device:
	device_destroy(hw_cable_in_detect_class, 0);
	cable_in_dev = NULL;
free_class:
	class_destroy(hw_cable_in_detect_class);
	hw_cable_in_detect_class = NULL;
free_di:
	di->dev = NULL;
	kfree(di);
	di = NULL;
	return s_ret;
}

/*
 * probe match table
 */
static const struct of_device_id cable_in_detect_table[] = {
	{
		.compatible = "huawei,cable_in_detect",
		.data = NULL,
	},
	{},
};

/*
 * card tray detect driver
 */
static struct platform_driver cable_in_detect_driver = {
	.probe = cable_in_detect_probe,
	.driver = {
		.name = "huawei,cable_in_detect",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(cable_in_detect_table),
	},
};

/*
 * Function: cable_in_detect_init
 * Description: card tray status gpio detect module initialization
 * Parameters:	Null
 * return value: 0-sucess or others-fail
 */
static int __init cable_in_detect_init(void)
{
	int ret = 0;

	hwlog_info("into init");
	ret = platform_driver_register(&cable_in_detect_driver);
	return ret;
}

/*
 * Function:	   cable_in_detect_exit
 * Description:	   card tray status gpio detect module exit
 * Parameters:	 NULL
 * return value:  NULL
 */
static void __exit cable_in_detect_exit(void)
{
	platform_driver_unregister(&cable_in_detect_driver);
}

module_init(cable_in_detect_init);
module_exit(cable_in_detect_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("huawei cable in detect driver");
MODULE_AUTHOR("HUAWEI Inc");
