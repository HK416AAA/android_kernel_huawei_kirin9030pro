/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: flat vibrator ctrl driver
 * Author: tianyunhang 30013707
 * Create: 2025/03/04
 */

#include <securec.h>
#include <linux/leds.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <linux/delay.h>

extern volatile int vibrator_shake;

#define GPIO_VIBRATOR_TIMEOUT_MIN 30
#define DELAY_VIBRATOR_60MS 60

enum {
    VIBRATOR_OFF = 0,
    VIBRATOR_ON = 1,
};

struct delayed_work vibrator_work_ctl;
struct work_struct vibrator_gpio_ctrl_work;
static bool work_state = 0;
static enum led_brightness state_cur = 0;

static struct gpio_vibrator_data *g_vdata = NULL;

/**
 * struct gpio_vibrator_data
 * @dev: device struct
 * @cdev: LED class device for this vibrator
 * @lock: resource lock
 * @vib_gpio: power supply
 */
struct gpio_vibrator_data {
	struct device *dev;
	struct led_classdev cdev;
	int vib_gpio;
	int vib_ctrl_time_enable;
	unsigned int vib_start_time;
	unsigned int vib_stop_time;
};

static void vibrator_ctl(struct work_struct *work)
{
	if (!state_cur) {
		gpio_set_value(g_vdata->vib_gpio, 0);
		pr_info("%s: exit", __func__);
		return;
	}
	work_state = ! work_state;
	if (work_state) {
		pr_info("%s: Entering vibrator start", __func__);
		gpio_set_value(g_vdata->vib_gpio, 1);
		schedule_delayed_work(&vibrator_work_ctl, msecs_to_jiffies(g_vdata->vib_start_time));
	} else {
		pr_info("%s: Entering vibrator stop", __func__);
		gpio_set_value(g_vdata->vib_gpio, 0);
		schedule_delayed_work(&vibrator_work_ctl, msecs_to_jiffies(g_vdata->vib_stop_time));
	}
}

static void gpio_vibrator_gpio_ctrl_func(struct work_struct *work)
{
	if (state_cur) { 
		vibrator_shake = VIBRATOR_ON;
		work_state = 0;
		schedule_delayed_work(&vibrator_work_ctl, msecs_to_jiffies(1));
		dev_info(g_vdata->dev, "flat vibrator gpio open\n");
	} else {
		vibrator_shake = VIBRATOR_OFF;
		cancel_delayed_work_sync(&vibrator_work_ctl);
		gpio_set_value(g_vdata->vib_gpio, 0);
		dev_info(g_vdata->dev, "flat vibrator gpio close\n");
	}
}

static void gpio_vibrator_gpio_ctrl_by_time(struct led_classdev *cdev, enum led_brightness state_new)
{
	struct gpio_vibrator_data *vdata = container_of(cdev, struct gpio_vibrator_data, cdev);
	if (vdata == NULL || state_new == state_cur) {
		pr_err("%s: vibrator data is NULL or state_cur same", __func__);
		return;
	}
	g_vdata = vdata;
	state_cur = state_new;
	schedule_work(&vibrator_gpio_ctrl_work);
}

static void gpio_vibrator_gpio_ctrl(struct led_classdev *cdev, enum led_brightness state)
{
	struct gpio_vibrator_data *vdata = container_of(cdev, struct gpio_vibrator_data, cdev);

	if (vdata == NULL) {
		pr_err("%s: vibrator data is NULL", __func__);
		return;
	}
	/* no blocking, the lock should not be used */
	if (state) {
		vibrator_shake = 1;
		gpio_direction_output(vdata->vib_gpio, 1);
		dev_info(vdata->dev, "flat vibrator gpio open\n");
	} else {
		vibrator_shake = 0;
		gpio_direction_output(vdata->vib_gpio, 0);
		dev_info(vdata->dev, "flat vibrator gpio close\n");
	}
}

static ssize_t gpio_vibrator_min_timeout_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	u32 val = GPIO_VIBRATOR_TIMEOUT_MIN;

	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", val);
}

static DEVICE_ATTR(vibrator_min_timeout, 0444, gpio_vibrator_min_timeout_show, NULL);

static struct attribute *gpio_vb_attributes[] = {
	&dev_attr_vibrator_min_timeout.attr, NULL
};

static const struct attribute_group gpio_vb_attr_group = {
	.attrs = gpio_vb_attributes,
};

static const struct of_device_id gpio_vibrator_match[] = {
	{.compatible = "hisilicon,gpio-vibrator"}, {},
};

MODULE_DEVICE_TABLE(of, gpio_vibrator_match);

static int gpio_vibrator_register_led_classdev_gpio(struct gpio_vibrator_data *vdata)
{
	struct led_classdev *cdev = &vdata->cdev;

	cdev->name = "vibrator";
	cdev->flags = LED_CORE_SUSPENDRESUME;
	cdev->default_trigger = "transient";

	if (vdata->vib_ctrl_time_enable) {
		cdev->brightness_set = gpio_vibrator_gpio_ctrl_by_time;
	} else {
		cdev->brightness_set = gpio_vibrator_gpio_ctrl;
	}

	return devm_led_classdev_register(vdata->dev, cdev);
}

static void flat_vibrator_delay(struct gpio_vibrator_data *vdata, u32 delay)
{
    gpio_set_value(vdata->vib_gpio, 1);
    msleep(delay);
    gpio_set_value(vdata->vib_gpio, 0);
    dev_info(vdata->dev, "Boot vibrator delay %d ms\n", delay);
}

static int gpio_vibrator_get_gpio_ctrl(struct platform_device *pdev)
{
	struct device_node *dn = NULL;
	struct gpio_vibrator_data *vdata = NULL;
	int ret;

	vdata = devm_kzalloc(&pdev->dev, sizeof(struct gpio_vibrator_data), GFP_KERNEL);
	if (vdata == NULL)
		return -ENOMEM;

	vdata->dev = &pdev->dev;

	dn = vdata->dev->of_node;

	vdata->vib_gpio = of_get_named_gpio(dn, "vibrator_gpio", 0);
	dev_err(vdata->dev, "flat vibrator gpio value %d\n", vdata->vib_gpio);

	if (vdata->vib_gpio < 0) {
		dev_err(vdata->dev, "vibrator gpio is not found\n");
		return -ENODEV;
	}

	ret = gpio_request(vdata->vib_gpio, "vibrator-en");
	if (ret) {
		dev_err(vdata->dev, "vibrator gpio request fail\n");
		return ret;
	}

	gpio_direction_output(vdata->vib_gpio, 0);

	if (!of_property_read_u32(dn, "vibrator_ctrl_time_enable", &vdata->vib_ctrl_time_enable)) {
		if (!of_property_read_u32(dn, "vibrator_start_time", &vdata->vib_start_time)) {
			dev_info(vdata->dev, "start time %d\n", vdata->vib_start_time);
		}
 
		if (!of_property_read_u32(dn, "vibrator_stop_time", &vdata->vib_stop_time)) {
			dev_info(vdata->dev, "stop time %d\n", vdata->vib_stop_time);
		}

		INIT_DELAYED_WORK(&vibrator_work_ctl, vibrator_ctl);
		INIT_WORK(&vibrator_gpio_ctrl_work, gpio_vibrator_gpio_ctrl_func);
    }

	/* register led classdev, use "transient" as default trigger */
	ret = gpio_vibrator_register_led_classdev_gpio(vdata);
	if (ret) {
		dev_err(&pdev->dev, "failed to register led classdev\n");
		return ret;
	}

	ret = sysfs_create_group(&vdata->cdev.dev->kobj, &gpio_vb_attr_group);
	if (ret)
		dev_err(&pdev->dev, "unable create vibrator's min_timeout\n");

	platform_set_drvdata(pdev, vdata);

	flat_vibrator_delay(vdata, DELAY_VIBRATOR_60MS);

	return ret;
}

static int gpio_vibrator_probe(struct platform_device *pdev)
{
	struct gpio_vibrator_data *vdata = NULL;
	int ret;

	dev_info(&pdev->dev, "flat gpio vibrator probe");

	if (!of_match_node(gpio_vibrator_match, pdev->dev.of_node)) {
		dev_err(&pdev->dev, "dev node is not match. exiting.\n");
		return -ENODEV;
	}

	ret = gpio_vibrator_get_gpio_ctrl(pdev);
	if (!ret) {
		dev_info(&pdev->dev, "gpio vibrator gpio ctrl mode ret=%d\n", ret);
		return ret;
	}

	return 0;
}

static int gpio_vibrator_remove(struct platform_device *pdev)
{
	struct gpio_vibrator_data *vdata = NULL;

	vdata = dev_get_drvdata(&pdev->dev);
	if (vdata == NULL) {
		pr_err("%s:failed to get drvdata\n", __func__);
		return -ENODEV;
	}

	sysfs_remove_group(&vdata->cdev.dev->kobj, &gpio_vb_attr_group);

	if (vdata->vib_gpio >= 0) {
		gpio_free(vdata->vib_gpio);
	}

	return 0;
}

static struct platform_driver gpio_vibrator_driver = {
	.probe = gpio_vibrator_probe,
	.remove = gpio_vibrator_remove,
	.driver = {
		.name = "gpio-vibrator",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(gpio_vibrator_match),
	},
};

static int __init gpio_vibrator_init(void)
{
	return platform_driver_register(&gpio_vibrator_driver);
}

static void __exit gpio_vibrator_exit(void)
{
	platform_driver_unregister(&gpio_vibrator_driver);
}

module_init(gpio_vibrator_init);
module_exit(gpio_vibrator_exit);

MODULE_DESCRIPTION("FLAT vibrator driver");
MODULE_LICENSE("GPL");

