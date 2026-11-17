/*
 * echub_ladder_standby.c
 *
 * ladder_standby driver for send ec
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
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/err.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/syscore_ops.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/notifier.h>
#include <linux/pm_wakeup.h>
 
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#include "echub_i2c.h"
#include "ospm_printf.h"
#include "hmi/hmi.h"
 
#define EC_LADDER_STANDBY_CMD      0x02A9
 
#define THRESHOLD_MIN   0
#define THRESHOLD_MAX 100
 
struct ec_ladder_standby_info {
	struct device *dev;
	struct echub_i2c_dev *echub_dev;
	int power_threshold;
};
 
static struct ec_ladder_standby_info *g_ec_standby_di = NULL;
static struct device *g_dev = NULL;
 
#ifdef CONFIG_SYSFS
static ssize_t power_threshold_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct ec_ladder_standby_info *di = g_ec_standby_di;
	if (!di) {
        echub_err("%s:%d di is null\n", __func__, __LINE__);
        return -ENODEV;
    }
    return scnprintf(buf, PAGE_SIZE, "%u\n", di->power_threshold);
}
 
static ssize_t power_threshold_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	struct ec_ladder_standby_info *di = g_ec_standby_di;
	int power_threshold = 0x0;

	if (!di) {
        echub_err("%s:%d di is null\n", __func__, __LINE__);
        return -ENODEV;
    }
	ret = kstrtouint(buf, 0, &power_threshold);
	if (ret < 0) {
		echub_err("transfer to int fail\n");
        return ret;
	}
 
	if ((power_threshold < THRESHOLD_MIN) || (power_threshold > THRESHOLD_MAX)) {
		echub_err("Input power_threshold is invalid!\n");
		return -EINVAL;
	}
	di->power_threshold = power_threshold;

	ret = di->echub_dev->write_func(di->echub_dev, EC_LADDER_STANDBY_CMD, di->power_threshold);
	if (ret) {
		echub_err("set low battery thres failed. ret=%d\n", ret);
		return ret;
	}
 
	return count;
}
 
static DEVICE_ATTR(power_threshold, 0660, power_threshold_show, power_threshold_store);
 
static struct attribute *ec_ladder_standby_attributes[] = {
	&dev_attr_power_threshold.attr,
	NULL
};
 
static const struct attribute_group echub_ladder_standby_sysfs_attr_group = {
	.attrs = ec_ladder_standby_attributes,
};
 
static struct device *ladder_standby_create_group(void)
{
	return power_sysfs_create_group("hw_echub", "ladder_standby", &echub_ladder_standby_sysfs_attr_group);
}
 
static void ladder_standby_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &echub_ladder_standby_sysfs_attr_group);
}
#else
static inline struct device *ladder_standby_create_group(void)
{
    return NULL;
}
 
static inline void ladder_standby_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */
 
static int power_threshold_parse_dts(struct device_node *dev_node, struct ec_ladder_standby_info *di)
{
	if (!dev_node || !di) {
		echub_err("%s dev_node is NULL!\n", __func__);
		return -ENODEV;
	}
 
	return 0;
}
 
/**********************************************************
*  Function:       echub_ladder_standby_probe
*  Discription:    module probe
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_ladder_standby_probe(struct platform_device *pdev)
{
	struct ec_ladder_standby_info *di = NULL;
	struct echub_i2c_dev *echub_dev = dev_get_drvdata(pdev->dev.parent);
    int ret;
 
    if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form tmp\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("echub_dev is NULL return\n");
			return -ENODEV;
		}
	}
 
	di = devm_kzalloc(&pdev->dev, sizeof(struct ec_ladder_standby_info), GFP_KERNEL);
	if (di == NULL) {
		echub_err("ec_ladder_standby_info is NULL!\n");
		return -ENOMEM;
	}
   
    di->dev = &pdev->dev;
	di->echub_dev = echub_dev;
 
	platform_set_drvdata(pdev, di);
	g_ec_standby_di = di;
    ret = power_threshold_parse_dts(pdev->dev.of_node, g_ec_standby_di);
    g_dev = ladder_standby_create_group();
	if (ret < 0)
		echub_err("register sysfs create group failed\n");
	return 0;
}
 
/**********************************************************
*  Function:       echub_ladder_standby_remove
*  Discription:    module remove
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_ladder_standby_remove(struct platform_device *pdev)
{
	struct ec_ladder_standby_info *di = platform_get_drvdata(pdev);

    if (di == NULL) {
		echub_err("[%s]di is NULL!\n", __func__);
		return -ENODEV;
	}

    ladder_standby_remove_group(g_dev);
	g_dev = NULL;
    platform_set_drvdata(pdev, NULL);
	return 0;
}

static struct of_device_id echub_ladder_standby_match_table[] = {
	{
		.compatible = "huawei,echub_ladder_standby",
		.data = NULL,
	},
	{
	},
};
static struct platform_driver echub_ladder_standby_driver = {
	.probe        = echub_ladder_standby_probe,
	.remove       = echub_ladder_standby_remove,
	.driver       = {
		.name           = "huawei,echub_ladder_standby",
		.owner          = THIS_MODULE,
		.of_match_table = of_match_ptr(echub_ladder_standby_match_table),
	},
};

/**********************************************************
*  Function:       echub_ladder_standby_init
*  Discription:    module initialization
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
int __init echub_ladder_standby_init(void)
{
	return platform_driver_register(&echub_ladder_standby_driver);
}
 
/**********************************************************
*  Function:       echub_ladder_standby_exit
*  Discription:    module exit
*  Parameters:     NULL
*  return value:   NULL
**********************************************************/
void __exit echub_ladder_standby_exit(void)
{
	platform_driver_unregister(&echub_ladder_standby_driver);
}
 
module_init(echub_ladder_standby_init);
module_exit(echub_ladder_standby_exit);
 
MODULE_ALIAS("armpc echub_ladder_standby");
MODULE_LICENSE("GPL");