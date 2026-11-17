/*
 * ufs_led_dev.c
 *
 * ufs_led_dev driver
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
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

#include <linux/err.h>
#include <linux/gpio.h>
#include <linux/gpio/consumer.h>
#include <linux/kernel.h>
#include <linux/leds.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/property.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/device.h>
#include <securec.h>

#include "ufs_led_dev.h"
#define DELAY_TIME 250

#define UFS_LED_BLINK_TIMES 2

enum ufs_led_level {
	GPIO_OUT_LOW,
	GPIO_OUT_HIGH,
};

struct ufs_led_data {
	int led_gpio;
	unsigned int blink_times;
	bool is_blink_always;
	bool is_s3;
	struct led_classdev cdev;
	struct timer_list timer;
	struct work_struct blink_work;
	struct device dev;
};

static struct ufs_led_data *g_led_data = NULL;
static unsigned long test_mode = 0;

static ssize_t led_test_mode_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	return sprintf_s(buf, sizeof(buf), "%lu\n", test_mode);
}

static ssize_t led_test_mode_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);
	struct ufs_led_data *led_data =
		container_of(led_cdev, struct ufs_led_data, cdev);
	ssize_t ret;

	ret = kstrtoul(buf, 10, &test_mode);
	if (ret)
		return ret;

	led_data->is_blink_always = true;
	led_cdev->brightness_set(led_cdev, LED_OFF);
	return size;
}

static DEVICE_ATTR(test_mode, 0644, led_test_mode_show, led_test_mode_store);
static struct attribute *led_test_mode_set_attributes[] = {
	&dev_attr_test_mode.attr,
	NULL
};

static const struct attribute_group led_test_attr_group = {
	.attrs = led_test_mode_set_attributes,
};

static void led_gpio_set_value(struct ufs_led_data *led_data)
{
	if (led_data->cdev.brightness == LED_OFF)
		gpio_set_value(led_data->led_gpio, GPIO_OUT_LOW);
	else
		gpio_set_value(led_data->led_gpio, GPIO_OUT_HIGH);
}

static void led_blink_timer(struct timer_list *tmr)
{
	unsigned long delay;
	struct ufs_led_data *led_data = from_timer(led_data, tmr, timer);
	struct led_classdev *led_cdev = &led_data->cdev;

	if (!led_data->is_blink_always && led_data->blink_times == 0)
		return;

	led_data->blink_times--;
	led_cdev->brightness = led_cdev->brightness == LED_OFF ? LED_FULL : LED_OFF;
	delay = led_cdev->brightness == LED_OFF ? led_cdev->blink_delay_off :
											led_cdev->blink_delay_on;

	led_gpio_set_value(led_data);
	mod_timer(&led_data->timer, jiffies + msecs_to_jiffies(delay));
}

static void ufs_led_brightness_set(
	struct led_classdev *led_cdev, enum led_brightness brightness)
{
	struct ufs_led_data *led_data =
		container_of(led_cdev, struct ufs_led_data, cdev);

	del_timer(&led_data->timer);

	led_data->cdev.brightness = brightness;
	led_gpio_set_value(led_data);
}

static int ufs_led_blink_set(struct led_classdev *led_cdev,
	unsigned long *delay_on, unsigned long *delay_off)
{
	struct ufs_led_data *led_data =
		container_of(led_cdev, struct ufs_led_data, cdev);

	if (*delay_on > 0 || *delay_off > 0) {
		led_data->cdev.blink_delay_on = *delay_on;
		led_data->cdev.blink_delay_off = *delay_off;

		mod_timer(&led_data->timer, jiffies + 1);
	}

	return 0;
}

static void ufs_led_blink_work(struct work_struct *work)
{
	struct ufs_led_data *led_data =
		container_of(work, struct ufs_led_data, blink_work);
	struct led_classdev *led_cdev = &led_data->cdev;
	unsigned long delay = DELAY_TIME;

	led_cdev->brightness = LED_OFF;
	led_data->blink_times = 2 * UFS_LED_BLINK_TIMES;
	led_data->is_blink_always = false;

	ufs_led_blink_set(led_cdev, &delay, &delay);
}

void blink_set_ufs_led()
{
	if (g_led_data == NULL)
		return;

	if (test_mode != 0 || timer_pending(&g_led_data->timer) || g_led_data->is_s3)
		return;

	schedule_work(&g_led_data->blink_work);
}

static int of_ufs_led_init(struct ufs_led_data *led_data)
{
	struct device_node *np = led_data->dev.of_node;
	int ret;

	ret = of_property_read_u32(np, "led_gpio", (u32 *)&led_data->led_gpio);
	if (ret < 0) {
		dev_err(&led_data->dev, "led_gpio not found\n");
		return ret;
	}

	ret = devm_gpio_request(&led_data->dev, led_data->led_gpio, "ufs_led_gpio");
	if (ret < 0) {
		dev_err(&led_data->dev, "ufs led request gpio fail\n");
		return ret;
	}

	ret = gpio_direction_output(led_data->led_gpio, GPIO_OUT_LOW);
	if (ret < 0) {
		dev_err(&led_data->dev, "ufs led direction output fail\n");
		return ret;
	}

	return 0;
}

static int ufs_led_probe(struct platform_device *pdev)
{
	struct ufs_led_data *dat;
	int ret;

	dat = devm_kzalloc(&pdev->dev, sizeof(struct ufs_led_data), GFP_KERNEL);
	if (!dat)
		return -ENOMEM;

	dat->dev = pdev->dev;

	ret = of_ufs_led_init(dat);
	if (ret < 0)
		return ret;

	dat->cdev.name = "ufs_led";
	dat->cdev.default_trigger = "timer";
	dat->cdev.max_brightness = LED_FULL;
	dat->cdev.brightness = LED_OFF;
	dat->cdev.brightness_set = ufs_led_brightness_set;
	dat->cdev.blink_set = ufs_led_blink_set;
	dat->is_s3 = false;
	dat->is_blink_always = true;

	timer_setup(&dat->timer, led_blink_timer, 0);
	INIT_WORK(&dat->blink_work, ufs_led_blink_work);

	platform_set_drvdata(pdev, dat);
	g_led_data = dat;

	ret = led_classdev_register(&pdev->dev, &dat->cdev);
	if (ret < 0) {
		led_classdev_unregister(&dat->cdev);
		dev_err(&pdev->dev, "led_classdev register fail\n");
		return ret;
	}

	ret = device_add_group(dat->cdev.dev, &led_test_attr_group);
	if (ret)
		return ret;

	return 0;
}

static int ufs_led_remove(struct platform_device *pdev)
{
	struct ufs_led_data *led_data = platform_get_drvdata(pdev);
	if (led_data == NULL)
		return -ENODEV;

	gpio_free(led_data->led_gpio);
	del_timer(&led_data->timer);
	led_classdev_unregister(&led_data->cdev);
	platform_set_drvdata(pdev, NULL);
	kfree(led_data);
	return 0;
}

static int ufs_led_pm_suspend(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct ufs_led_data *led_data = platform_get_drvdata(pdev);

	if (led_data == NULL)
		return -ENODEV;

	led_data->is_s3 = true;
	ufs_led_brightness_set(&led_data->cdev, LED_OFF);

	return 0;
}

static int ufs_led_pm_resume(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct ufs_led_data *led_data = platform_get_drvdata(pdev);

	if (led_data == NULL)
		return -ENODEV;

	led_data->is_s3 = false;

	return 0;
}

static const struct dev_pm_ops ufs_led_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(ufs_led_pm_suspend, ufs_led_pm_resume)
};

static const struct of_device_id ufs_led_match[] = {
	{ .compatible = "huawei,ufs_led" },
	{},
};
MODULE_DEVICE_TABLE(of, ufs_led_match);

struct platform_driver ufs_led_driver = {
	.probe		= ufs_led_probe,
	.remove		= ufs_led_remove,
	.driver		= {
		.name	= "ufs_led_driver",
		.owner = THIS_MODULE,
		.pm = &ufs_led_pm_ops,
		.of_match_table = of_match_ptr(ufs_led_match),
	},
};

static int __init ufs_led_init(void)
{
	return platform_driver_register(&ufs_led_driver);
}

static void __exit ufs_led_exit(void)
{
	platform_driver_unregister(&ufs_led_driver);
}
module_init(ufs_led_init);
module_exit(ufs_led_exit);

MODULE_ALIAS("ufs led control module");
MODULE_DESCRIPTION("ufs led control driver");
MODULE_LICENSE("GPL");