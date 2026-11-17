/*
 * ec_charge_status.c
 *
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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
#include <linux/uaccess.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/i2c.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include "securec.h"
#include "ospm_printf.h"
#include "echub_i2c.h"

#define DEVICE_NAME "echub_charge_status"
#define START_SINK "startsink\x0a"
#define STOP_SINK "stopsink\x0a"
#define EC_I2C_CMD_TEST_MODE 0x0440
#define EC_I2C_CMD_SINK_SWITCH 0x0455
#define EC_I2C_CMD_READ_ELECTRIC 0x0451
#define EC_I2C_DATA_OPEN 0x01
#define EC_I2C_DATA_CLOSED 0
#define EC_I2C_DATA_READ_LEN 5

static struct echub_i2c_dev *echub_dev;

/**********************************************************
*  Function:       enter_battery_test_mode
*  Discription:    You can enter the battery test mode only in EC factory mode.
**********************************************************/
static void enter_battery_test_mode(void)
{
	if (echub_dev == NULL) {
		echub_err("enter_battery_test_mode echub_dev is NULL\n");
		return;
	}
	int ret;
	ret = echub_dev->write_func(echub_dev, EC_I2C_CMD_TEST_MODE, EC_I2C_DATA_OPEN);
	echub_info("enter_battery_test_mode ret:%d\n", ret);
}

static void leave_battery_test_mode(void)
{
	if (echub_dev == NULL) {
		echub_err("leave_battery_test_mode echub_dev is NULL\n");
		return;
	}
	int ret;
	ret = echub_dev->write_func(echub_dev, EC_I2C_CMD_TEST_MODE, EC_I2C_DATA_CLOSED);
	echub_info("leave_battery_test_mode ret:%d\n", ret);
}

static void startsink(void)
{
	if (echub_dev == NULL) {
		echub_err("startsink echub_dev is NULL\n");
		return;
	}
	int ret;
	ret = echub_dev->write_func(echub_dev, EC_I2C_CMD_SINK_SWITCH, EC_I2C_DATA_CLOSED);
	echub_err("write startsink ret:%d\n", ret);
}

static void stopsink(void)
{
	if (echub_dev == NULL) {
		echub_err("stopsink echub_dev is NULL\n");
		return;
	}
	int ret;
	ret = echub_dev->write_func(echub_dev, EC_I2C_CMD_SINK_SWITCH, EC_I2C_DATA_OPEN);
	echub_info("stopsink write ret:%d\n", ret);
}

static ssize_t ec_charge_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (echub_dev == NULL || buf == NULL) {
		echub_err("echub_dev is NULL\n");
		return -EINVAL;
	}
	int ret;
	unsigned char value[EC_I2C_DATA_READ_LEN] = {0};
	ret = echub_dev->read_func(echub_dev, EC_I2C_CMD_READ_ELECTRIC, EC_I2C_DATA_OPEN, value, EC_I2C_DATA_READ_LEN);
	if (ret) {
		echub_err("%s, read electric failed: %d\n", __func__, ret);
		return -EINVAL;
	}
	return sprintf_s(buf, PAGE_SIZE, "%x, %x\n", value[2], value[3]); // status2, status3
}

static ssize_t ec_charge_status_write(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t len)
{
	if (strcmp(buf, START_SINK) == 0) {
		enter_battery_test_mode();
		startsink();
		leave_battery_test_mode();
	} else if (strcmp(buf, STOP_SINK) == 0) {
		enter_battery_test_mode();
		stopsink();
	} else {
		echub_err("%s, Invalid command \n", __func__);
		return -EINVAL;
	}
	return len;
}

static DEVICE_ATTR(status, S_IWUSR | S_IRUSR, ec_charge_status_show, ec_charge_status_write);

struct file_operations status_ops = {
	.owner = THIS_MODULE,
};

static int major;
static struct class *echub_cls;
struct device *mydev;

static int echub_charge_state_probe(struct platform_device *pdev)
{
	int err;
	if (!pdev || !pdev->dev.parent) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_err("[%s:%dL] echub_dev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	major = register_chrdev(0, "echub_charge_status", &status_ops);
	echub_info("register_chrdev major:%d\n", major);
	if (major < 0) {
		echub_err("register_chrdev fail\n");
		return -ENODEV;
	}
	echub_cls = class_create(THIS_MODULE, "echub_charging_status");
	if (IS_ERR(echub_cls)) {
		echub_err("class_create fail\n");
		err = PTR_ERR(echub_cls);
		goto err_unregister_chrdev;
	}
	mydev = device_create(echub_cls, 0, MKDEV(major, 0), NULL, DEVICE_NAME);
	if (IS_ERR(mydev)) {
		err = PTR_ERR(mydev);
        goto err_destroy_class;
	}
	if (sysfs_create_file(&(mydev->kobj), &dev_attr_status.attr)) {
		echub_err("sysfs_create_file fail\n");
        err = -EFAULT;
        goto err_remove_device;
	}
	return 0;
err_remove_device:
    device_destroy(echub_cls, major);
err_destroy_class:
    class_destroy(echub_cls);
err_unregister_chrdev:
    unregister_chrdev(major, "echub_charge_status");
    return err;
}

static const struct of_device_id of_echub_charge_state_match_tbl[] = {
	{ .compatible = "huawei,echub_charge_status" },
	{},
};

static struct platform_driver echub_charge_state_driver = {
	.driver = {
		.name = "echub_charge_status",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(of_echub_charge_state_match_tbl),
	},
	.probe = echub_charge_state_probe,
};

static int __init echub_charge_state_init(void)
{
	return platform_driver_register(&echub_charge_state_driver);
}

static void __exit echub_charge_state_exit(void)
{
	device_destroy(echub_cls, MKDEV(major, 0));
	class_destroy(echub_cls);
	unregister_chrdev(major, "echub_charge_status");
	platform_driver_unregister(&echub_charge_state_driver);
}

module_init(echub_charge_state_init);
module_exit(echub_charge_state_exit);

MODULE_DESCRIPTION("echub_charge_status  driver");
MODULE_LICENSE("GPL");
