/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: keyboard smart led
 * Notes      :
 * History    :
 */

#include <securec.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/mfd/core.h>
#include <linux/of.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include "ospm_printf.h"
#include "echub_i2c.h"

#define WRITE_BUF_LEN     2
#define INVALID_DUR_TIME (-1)

#define ECHUB_SEND_CMD_LEN 5
#define ECHUB_CMD_02C9 0x02c9

enum echub_keyboard_smart_led_type {
	ECHUB_SMART_LED_OFF = 0,
	ECHUB_SMART_LED_BREATHING,
	ECHUB_SMART_LED_BLINKING,
	ECHUB_SMART_LED_BUTT
};

struct echub_keyboard_smart_led_info {
	struct device *dev;
	struct echub_i2c_dev *echub_dev;
	int led_type;
	int dur_time;
};

static struct device *g_dev = NULL;

static struct echub_keyboard_smart_led_info *g_led_di = NULL;

static bool echub_check_para(int led_type, int dur_time)
{
	if (led_type < ECHUB_SMART_LED_OFF || led_type >= ECHUB_SMART_LED_BUTT) {
		echub_err("%s led type is invalid\n", __func__);
		return false;
	}

	if (dur_time < INVALID_DUR_TIME) {
		echub_err("%s dur_time is invalid\n", __func__);
		return false;
	}

	return true;
}

static ssize_t echub_keyboard_smart_led_set(int led_type, int dur_time)
{
	int ret;
	char cmd_buf[ECHUB_SEND_CMD_LEN] = { 0x0 };

	struct echub_keyboard_smart_led_info *di = g_led_di;
	if (!di || !di->echub_dev) {
		echub_err("%s g_chrg_di is NULL\n", __func__);
		return -EINVAL;
	}

	cmd_buf[0] = led_type;
	cmd_buf[1] = dur_time & 0x000000ff; // 0x00000ff bit0 ~ bit7 > buf1
	cmd_buf[2] = (dur_time & 0x0000ff00) >> 8; // 0x0000ff00  bit8 ~ bit15 > buf2
	cmd_buf[3] = (dur_time & 0x00ff0000) >> 16; // 0x00ff0000  bit16 ~ bit23 > buf3
	cmd_buf[4] = (dur_time & 0xff000000) >> 24; // 0xff000000  bit24 ~ bit31 > buf4
	ret = di->echub_dev->transfer_func(di->echub_dev, ECHUB_CMD_02C9, cmd_buf, sizeof(cmd_buf), NULL, 0x0);
	echub_info("led_type %d dur_time %d ret:%d\n", led_type, dur_time, ret);

	return ret;
}

#ifdef CONFIG_SYSFS

static ssize_t echub_keyboard_smart_led_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t len)
{
	int num[WRITE_BUF_LEN] = {ECHUB_SMART_LED_BUTT, INVALID_DUR_TIME};

	if (buf == NULL) {
		echub_err("[%s:%dL] buf is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	if (sscanf_s(buf, "%d %d", &num[0], &num[1]) != WRITE_BUF_LEN) {
		echub_err("%s incorrect format\n", __func__);
		return -EINVAL;
	}

	if (!echub_check_para(num[0], num[1])) {
		return -EINVAL;
	}

	int ret = echub_keyboard_smart_led_set(num[0], num[1]);
	if (ret < 0) {
		return ret;
	}

	return len;
}

static DEVICE_ATTR(keyboard_smart_led, S_IWUSR | S_IWGRP, NULL, echub_keyboard_smart_led_store);

static struct attribute *echub_keyboard_smart_led_attrs[] = {
	&dev_attr_keyboard_smart_led.attr,
	NULL,
};

static const struct attribute_group echub_keyboard_smart_led_sysfs_attr_group = {
	.attrs = echub_keyboard_smart_led_attrs,
};

static struct device *smart_led_create_group(void)
{
	return power_sysfs_create_group("hw_echub", "keyboard_led", &echub_keyboard_smart_led_sysfs_attr_group);
}

static void smart_led_remove_group(struct device *dev)
{
	return power_sysfs_remove_group(dev, &echub_keyboard_smart_led_sysfs_attr_group);
}

#else

static inline struct device *smart_led_create_group(void)
{
	return NULL;
}

static inline void smart_led_remove_group(struct device *dev)
{
	return;
}

#endif /* CONFIG_SYSFS */

static int echub_keyboard_smart_led_probe(struct platform_device *pdev)
{
	struct echub_keyboard_smart_led_info *ew = NULL;

	if (!pdev || !pdev->dev.parent || !pdev->dev.of_node) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}

	struct echub_i2c_dev *echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (!echub_dev) {
		echub_err("echub_dev is null\n");
		return -ENODEV;
	}

	ew = devm_kzalloc(&pdev->dev, sizeof(struct echub_keyboard_smart_led_info), GFP_KERNEL);
	if (!ew) {
		return -ENOMEM;
	}

	ew->dev = &pdev->dev;
	ew->echub_dev = echub_dev;
	ew->dur_time = ECHUB_SMART_LED_OFF;
	ew->dur_time = INVALID_DUR_TIME;

	g_led_di = ew;

	g_dev = smart_led_create_group();
	if (g_dev == NULL) {
		echub_err("register sysfs echub smart_led_sysfs failed\n");
	}

	return 0;
}

static int echub_keyboard_smart_led_remove(struct platform_device *pdev)
{
	smart_led_remove_group(g_dev);
	g_dev = NULL;

	return 0;
}

static const struct of_device_id of_echub_keyboard_smart_led_match_tbl[] = {
	{ .compatible = "huawei,echub_keyboard_smart_led" },
	{},
};

static struct platform_driver echub_keyboard_smart_led_driver = {
	.driver = {
		.name = "echub_keyboard_smart_led",
		.owner  = THIS_MODULE,
		.of_match_table = of_match_ptr(of_echub_keyboard_smart_led_match_tbl),
	},
	.probe = echub_keyboard_smart_led_probe,
	.remove = echub_keyboard_smart_led_remove,
};

/*
 * keyboard_smart_led_init
 */
static int __init echub_keyboard_smart_led_init(void)
{
	echub_info("echub keyboard_smart_led init\n");
	return platform_driver_register(&echub_keyboard_smart_led_driver);
}

/*
 * keyboard_smart_led_exit
 */
static void __exit echub_keyboard_smart_led_exit(void)
{
	echub_info("echub keyboard_smart_led exit\n");
	platform_driver_unregister(&echub_keyboard_smart_led_driver);
}

module_init(echub_keyboard_smart_led_init);
module_exit(echub_keyboard_smart_led_exit);

MODULE_DESCRIPTION("echub keyboard smart led init driver");
MODULE_LICENSE("GPL");
