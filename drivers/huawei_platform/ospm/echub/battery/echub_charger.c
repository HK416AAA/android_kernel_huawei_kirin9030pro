/*
 * echub_charger.c
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
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/i2c.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include "securec.h"
#include "ospm_printf.h"
#include "echub_i2c.h"

#define EC_I2C_CMD_STORE          0x0268
#define TYPE_SOC_LIMIT_LOW        0x01
#define TYPE_SOC_LIMIT_HIGH       0x02
#define TYPE_SOC_LIMIT_SWITCH     0x03
#define FLOAT_MODE_OPEN           0x5a
#define FLOAT_MODE_CLOSE          0x55
#define MAX_BAT_CAP               100
#define WRITE_BUF_LEN             2
#define READ_BUF_LEN              3
#define INVALID_NUM               (-1)

static struct ec_charge_device_info *g_chrg_di = NULL;
static struct device *g_dev = NULL;

struct ec_charge_device_info {
	struct echub_i2c_dev *echub_dev;
	struct class *cls;
	struct device *dev;
	struct device *pdev;
	int major;
	bool chrg_limit;
};

static void set_soc_limit_value(int type, int num, struct ec_charge_device_info *di)
{
	int ret;
	u8 write_buf[WRITE_BUF_LEN] = {0};

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s di is NULL\n", __func__);
		return;
	}

	write_buf[0] = type;
	write_buf[1] = num;
	ret = di->echub_dev->transfer_func(di->echub_dev,
		EC_I2C_CMD_STORE, write_buf, WRITE_BUF_LEN, NULL, 0);
	echub_info("%s num:%d type:%d ret:%d\n", __func__, num, type, ret);
}

static void set_floating_mode(int flag, struct ec_charge_device_info *di)
{
	int ret;
	u8 write_buf[WRITE_BUF_LEN] = {0};

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s di is NULL\n", __func__);
		return;
	}

	write_buf[0] = TYPE_SOC_LIMIT_SWITCH;
	write_buf[1] = flag;
	ret = di->echub_dev->transfer_func(di->echub_dev,
		EC_I2C_CMD_STORE, write_buf, WRITE_BUF_LEN, NULL, 0);
	echub_info("%s ret:%d flag:%d\n", __func__, ret, flag);
}

#ifdef CONFIG_SYSFS
static ssize_t chrg_limit_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t len)
{
	int num[2] = {INVALID_NUM};
	struct ec_charge_device_info *di = NULL;

	di = g_chrg_di;
	if (!di || !di->echub_dev || !buf) {
		echub_err("%s g_chrg_di is NULL\n", __func__);
		return -EINVAL;
	}

	if (sscanf_s(buf, "%d %d", &num[0], &num[1]) != WRITE_BUF_LEN) {
		echub_err("%s incorrect format\n", __func__);
		return -EINVAL;
	}

	if ((num[0] >= 0 && num[0] <= MAX_BAT_CAP) &&
		(num[1] >= 0 && num[1] <= MAX_BAT_CAP)) {
		set_floating_mode(FLOAT_MODE_OPEN, di);
		set_soc_limit_value(TYPE_SOC_LIMIT_HIGH, num[0], di);
		set_soc_limit_value(TYPE_SOC_LIMIT_LOW, num[1], di);
	} else {
		set_floating_mode(FLOAT_MODE_CLOSE, di);
	}

	return len;
}

static DEVICE_ATTR(chrg_limit, (S_IWUSR|S_IWGRP), NULL, chrg_limit_store);

static struct attribute *ec_charger_attributes[] = {
	&dev_attr_chrg_limit.attr,
	NULL,
};

static const struct attribute_group ec_attr_group = {
	.attrs = ec_charger_attributes,
};

static struct device *ec_charger_create_group(void)
{
	return power_sysfs_create_group("hw_echub", "charger",
		&ec_attr_group);
}

static void ec_charger_remove_group(struct device *dev)
{
	if (!dev) {
		echub_err("[%s:%dL] dev is NULL\n", __func__, __LINE__);
		return;
	}
	power_sysfs_remove_group(dev, &ec_attr_group);
}
#else
static inline struct device *ec_charger_create_group(void)
{
	return NULL;
}

static inline void ec_charger_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static struct ec_charge_device_info *create_device_info(struct platform_device *pdev,
	struct echub_i2c_dev *echub_dev)
{
	struct ec_charge_device_info *di = NULL;

	if (!pdev || !echub_dev) {
		echub_err("[%s:%dL] pdev or echub_dev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = devm_kzalloc(&pdev->dev, sizeof(struct ec_charge_device_info), GFP_KERNEL);
	if (!di)
		return NULL;

	di->echub_dev = echub_dev;
	di->pdev = &pdev->dev;
	if (!di->pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return NULL;
	}

	return di;
}

static int charger_parse_dts(struct device_node *dev_node, struct ec_charge_device_info *di)
{
	if (!dev_node || !di) {
		echub_err("%s dev_node is NULL\n", __func__);
		return -ENODEV;
	}
	di->chrg_limit = of_property_read_bool(dev_node, "chrg_limit");

	return 0;
}

static int ec_chrg_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct echub_i2c_dev *echub_dev = NULL;

	if (!pdev || !pdev->dev.parent || !pdev->dev.of_node) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}

	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (!echub_dev) {
		echub_err("%s echub_dev is null\n", __func__);
		return -ENODEV;
	}

	g_chrg_di = create_device_info(pdev, echub_dev);
	if (!g_chrg_di) {
		echub_err("%s g_chrg_di is null\n", __func__);
		return -ENOMEM;
	}

	ret = charger_parse_dts(pdev->dev.of_node, g_chrg_di);
	g_dev = ec_charger_create_group();

	return 0;
}

static int ec_chrg_remove(struct platform_device *pdev)
{
	ec_charger_remove_group(g_dev);
	g_dev = NULL;

	return 0;
}

static const struct of_device_id of_ec_chrg_match_tbl[] = {
	{ .compatible = "huawei,echub_charger" },
	{},
};

static struct platform_driver echub_charger_driver = {
	.probe = ec_chrg_probe,
	.remove = ec_chrg_remove,
	.driver = {
		.name = "echub_charger",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(of_ec_chrg_match_tbl),
	},
};

static int __init echub_charger_init(void)
{
	return platform_driver_register(&echub_charger_driver);
}

static void __exit echub_charger_exit(void)
{
	platform_driver_unregister(&echub_charger_driver);
}

module_init(echub_charger_init);
module_exit(echub_charger_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("echub charger driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
