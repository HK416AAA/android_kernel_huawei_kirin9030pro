/*
 * echub_tablet_switch.c
 *
 * table switch driver for echub
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/input.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/notifier.h>
#include <linux/jiffies.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/pm_wakeup.h>
#include <asm/irq.h>
#include <linux/suspend.h>
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include "securec.h"
#include "ospm_printf.h"
#include "echub_i2c.h"

#define GPIO_KEY_PRESS                 (1)
#define GPIO_KEY_RELEASE               (0)

#define GPIO_HIGH_VOLTAGE              (1)
#define GPIO_LOW_VOLTAGE               (0)
#define TIMER_DEBOUNCE                 (10)
#define WAKELOCK_DELAY_TIME            (1000)

#define SET_SAR_TEST_MODE_CMD    0x04A5   // sar test mode
#define SET_TABLET_SWITCH_CMD    0x04AA   // set sar status
#define TABLET_SWITCH_DL_MS 20000	// 20s

struct hw_gpio_key {
	struct echub_i2c_dev *echub_dev;
	struct input_dev *input_dev;
	struct device *wakeup_dev;

	struct delayed_work tablet_switch_irq_work;
	struct notifier_block hibernate_nb;
	int gpio_tablet_switch;
	int tablet_switch_irq;
};

static struct hw_gpio_key *g_hw_gpio_key = NULL;

/* is the pc in s3 */
static bool g_suspended = false;

static struct device *g_hw_tablet_switch_dev = NULL;

/**********************************************************
*  Function:       tablet_switch_open
*  Discription:    open gpiokey
*  Parameters:     input_dev *dev
*  return value:   0-sucess or others-fail
**********************************************************/
static int tablet_switch_open(struct input_dev *dev)
{
	/* add input device open function */
	echub_info("%s\n", __func__);
	return 0;
}

static void tablet_switch_close(struct input_dev *dev)
{
	/* add input device close function */
	echub_info("%s\n", __func__);
}

/**********************************************************
*  Function:       hw_tablet_switch_irq_work
*  Discription:    report tablet switch work
*  Parameters:     work_struct *work
*  Gpio-High = switch open = pc mode
*  Gpio-Low = switch close = tablet mode
**********************************************************/
static void hw_tablet_switch_irq_work(struct work_struct *work)
{
	struct hw_gpio_key *gpio_key = container_of(work,
		struct hw_gpio_key, tablet_switch_irq_work.work);
	unsigned int report_action = 0;
	int gpio_value = gpio_get_value((unsigned int)gpio_key->gpio_tablet_switch);
	if (gpio_value == GPIO_LOW_VOLTAGE) {
		report_action = 1;
	} else if (gpio_value == GPIO_HIGH_VOLTAGE) {
		report_action = 0;
	} else {
		echub_err("[gpiokey][%s]invalid gpio key_value.\n", __func__);
		return;
	}
	echub_info("report tablet switch is: %d (0:open, 1:close) \n", report_action);
	input_report_switch(gpio_key->input_dev, SW_TABLET_MODE, report_action);
	input_sync(gpio_key->input_dev);
}

static irqreturn_t hw_gpio_key_irq_handler(int irq, void *dev_id)
{
	int gpiovalue = 0;
	struct hw_gpio_key *gpio_key = (struct hw_gpio_key *)dev_id;
	if (gpio_key == NULL) {
		echub_err("gpio_key is NULL\n");
		return IRQ_HANDLED;
	}

	gpiovalue = gpio_get_value((unsigned int)gpio_key->gpio_tablet_switch);
	echub_info("tablet switch irq_handler gpio_value:%d g_suspended:%d\n", gpiovalue, g_suspended);

	cancel_delayed_work(&(gpio_key->tablet_switch_irq_work));
	schedule_delayed_work(&gpio_key->tablet_switch_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE));
	return IRQ_HANDLED;
}

static struct input_dev *init_input_dev(struct platform_device *pdev, void *data)
{
	struct input_dev *input_dev = NULL;

	if (!pdev)
		return NULL;

	input_dev = input_allocate_device();
	if (input_dev == NULL) {
		echub_err("Failed to allocate struct input_dev!\n");
		return NULL;
	}

	input_dev->name = pdev->name;
	input_dev->id.bustype = BUS_HOST;
	input_dev->dev.parent = &pdev->dev;
	input_set_drvdata(input_dev, data);

	set_bit(EV_SW, input_dev->evbit);
	set_bit(EV_SYN, input_dev->evbit);
	set_bit(SW_TABLET_MODE, input_dev->swbit);
	set_bit(EV_KEY, input_dev->evbit);
	set_bit(KEY_POWER, input_dev->keybit);

	input_dev->open = tablet_switch_open;
	input_dev->close = tablet_switch_close;

	return input_dev;
}

static int init_tablet_switch_gpio(struct platform_device *pdev, struct hw_gpio_key *gpio_key)
{
	int err = 0;

	if (!pdev || !gpio_key)
		return -EINVAL;

	/* initial work before we use it. */
	INIT_DELAYED_WORK(&(gpio_key->tablet_switch_irq_work), hw_tablet_switch_irq_work);

	/* inital gpio_tablet_switch */
	err = of_property_read_u32(pdev->dev.of_node, "gpio-key-tablet-switch", (u32 *)&gpio_key->gpio_tablet_switch);
	if (err) {
		gpio_key->gpio_tablet_switch = 0;
		echub_info("%s: Not support gpio_key tablet switch\n", __func__);
		return -EFAULT;
	} else {
		echub_info("%s: Support gpio_key tablet switch: %d\n", __func__, gpio_key->gpio_tablet_switch);
	}

	if (!gpio_is_valid(gpio_key->gpio_tablet_switch)) {
		echub_err("%s: gpio of tablet switch is not valid, check DTS\n", __func__);
		return -EFAULT;
	}

	err = devm_gpio_request(&pdev->dev, (unsigned int)gpio_key->gpio_tablet_switch, "gpio_tablet_switch");
	if (err < 0) {
		echub_err("Fail request gpio:%d\n", gpio_key->gpio_tablet_switch);
		return -EFAULT;
	}

	err = gpio_direction_input((unsigned int)gpio_key->gpio_tablet_switch);
	if (err < 0) {
		echub_err("Failed to set gpio_tablet_switch directoin!\n");
		return -EFAULT;
	}

	gpio_key->tablet_switch_irq = gpio_to_irq((unsigned int)gpio_key->gpio_tablet_switch);
	if (gpio_key->tablet_switch_irq < 0) {
		echub_err("Failed to get gpio key press irq!\n");
		return -EFAULT;
	}

	err = request_irq(gpio_key->tablet_switch_irq, hw_gpio_key_irq_handler,
		IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING, pdev->name, gpio_key);
	if (err) {
		echub_err("Failed to request press interupt handler!\n");
		return -EFAULT;
	}

	return 0;
}

#ifdef CONFIG_SYSFS
static ssize_t tablet_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int report_action = 0;
	int gpio_value;

	if (!buf)
		return 0;

	if (!g_hw_gpio_key || !gpio_is_valid(g_hw_gpio_key->gpio_tablet_switch)) {
		echub_err("%s: gpio of tablet switch is not valid\n", __func__);
		return 0;
	}

	gpio_value = gpio_get_value((unsigned int)g_hw_gpio_key->gpio_tablet_switch);
	if (gpio_value == GPIO_LOW_VOLTAGE) {
		report_action = 1;
	} else if (gpio_value == GPIO_HIGH_VOLTAGE) {
		report_action = 0;
	} else {
		echub_err("[gpiokey][%s]invalid gpio key_value.\n", __func__);
		return 0;
	}

	echub_info("show tablet switch is: %d (0:open, 1:close) \n", report_action);
	return sprintf_s(buf, PAGE_SIZE, "%d\n", report_action);
}

static ssize_t tablet_switch_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    unsigned int mode = 0;
	int ret;
	struct hw_gpio_key *di = g_hw_gpio_key;

	if (di == NULL || di->echub_dev == NULL || di->echub_dev->write_func == NULL)
		return -EINVAL;

	ret = kstrtouint(buf, 0, &mode);
	if (ret < 0)
		return -EINVAL;

	echub_info("set tablet switch:%d\n", mode);
	// 0: SAR open; 1: SAR close;  config sar status must enter test mode first
	if (mode == 0 || mode == 1) {
		ret = di->echub_dev->write_func(di->echub_dev, SET_SAR_TEST_MODE_CMD, 1);
		if (ret) {
			echub_err("enter SAR test mode failed: %d\n", ret);
			return ret;
		}
	}

	ret = di->echub_dev->write_func(di->echub_dev, SET_TABLET_SWITCH_CMD, (unsigned char)mode);
	if (ret) {
		echub_err("set tablet switch failed: %d\n", ret);
		return ret;
	}

	// others: exit SAR config,  exit test mode last
	if (mode != 0 && mode != 1) {
		ret = di->echub_dev->write_func(di->echub_dev, SET_SAR_TEST_MODE_CMD, 0);
		if (ret) {
			echub_err("exit SAR test mode failed: %d\n", ret);
			return ret;
		}
	}

	return count;
}

static DEVICE_ATTR(tablet_switch, 0660, tablet_switch_show, tablet_switch_store);

static struct attribute *hw_tablet_switch_attributes[] = {
	&dev_attr_tablet_switch.attr,
	NULL,
};

static const struct attribute_group hw_tablet_switch_attr_group = {
	.attrs = hw_tablet_switch_attributes,
};

static struct device *hw_tablet_switch_create_group(void)
{
	return power_sysfs_create_group("hw_echub", "tablet_switch",
		&hw_tablet_switch_attr_group);
}

static void hw_tablet_switch_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &hw_tablet_switch_attr_group);
}
#else
static inline struct device *hw_tablet_switch_create_group(void)
{
	return NULL;
}

static inline void hw_tablet_switch_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static int echub_tablet_switch_hibernate_callback(struct notifier_block *nb, unsigned long event, void *ptr)
{
	struct hw_gpio_key *di = g_hw_gpio_key;

	if (!di) {
		echub_err("tablet_switch hibernate nb callback error!");
		return NOTIFY_BAD;
	}

	switch (event) {
	case PM_HIBERNATION_PREPARE:
		echub_info("tablet switch receive hibernate event %d, disable irq\n", event);
		disable_irq(di->tablet_switch_irq);
		break;
	case PM_POST_HIBERNATION:
		echub_info("tablet switch receive hibernate event %d, enable irq\n", event);
		enable_irq(di->tablet_switch_irq);
		schedule_delayed_work(&di->tablet_switch_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE + 5000)); // 5000: 5s
		break;
	default:
		break;
	}

    return NOTIFY_OK;
}

static void init_tablet_switch_pm(struct hw_gpio_key *gpio_key)
{
	gpio_key->hibernate_nb.notifier_call  = echub_tablet_switch_hibernate_callback;
	register_pm_notifier(&gpio_key->hibernate_nb);

	schedule_delayed_work(&gpio_key->tablet_switch_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE + TABLET_SWITCH_DL_MS));
}

/**********************************************************
*  Function:       hw_tablet_switch_probe
*  Discription:    module probe
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_tablet_switch_probe(struct platform_device *pdev)
{
	struct echub_i2c_dev *echub_dev = dev_get_drvdata(pdev->dev.parent);
	struct hw_gpio_key *gpio_key = NULL;
	struct input_dev *input_dev = NULL;
	int err = 0;

	if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form tmp\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("echub_dev is NULL return\n");
			return -ENODEV;
		}
	}

	echub_info("armpc echub tablet switch driver probes start!\n");
	gpio_key = devm_kzalloc(&pdev->dev, sizeof(struct hw_gpio_key), GFP_KERNEL);
	if (gpio_key == NULL) {
		echub_err("Failed to allocate struct hw_gpio_key!\n");
		return -ENOMEM;
	}

	input_dev = init_input_dev(pdev, gpio_key);
	if (input_dev == NULL)
		return -ENOMEM;

	gpio_key->input_dev = input_dev;
	gpio_key->echub_dev = echub_dev;
	gpio_key->wakeup_dev = &pdev->dev;
	g_hw_tablet_switch_dev = hw_tablet_switch_create_group();

	err = init_tablet_switch_gpio(pdev, gpio_key);
	if (err) {
		echub_err("Failed to init tablet switch gpio!\n");
		goto err_switch_gpio;
	}

	err = input_register_device(gpio_key->input_dev);
	if (err) {
		echub_err("Failed to register input device!\n");
		goto err_register_dev;
	}

	device_init_wakeup(&pdev->dev, true);
	platform_set_drvdata(pdev, gpio_key);

	g_hw_gpio_key = gpio_key;
	init_tablet_switch_pm(gpio_key);

	echub_info("armpc gpio key driver probes successfully!\n");
	return 0;

err_register_dev:
	free_irq(gpio_key->tablet_switch_irq, gpio_key);
err_switch_gpio:
	input_free_device(input_dev);
	echub_err("[gpiokey] gpio key probe failed! ret = %d.\n", err);
	return err;
}

/**********************************************************
*  Function:       hw_tablet_switch_remove
*  Discription:    module remove
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_tablet_switch_remove(struct platform_device *pdev)
{
	struct hw_gpio_key *gpio_key = platform_get_drvdata(pdev);

	if (gpio_key == NULL) {
		echub_err("get invalid gpio_key pointer\n");
		return -EINVAL;
	}

	unregister_pm_notifier(&gpio_key->hibernate_nb);
	hw_tablet_switch_remove_group(g_hw_tablet_switch_dev);
	g_hw_tablet_switch_dev = NULL;

	free_irq(gpio_key->tablet_switch_irq, gpio_key);
	cancel_delayed_work(&(gpio_key->tablet_switch_irq_work));

	input_unregister_device(gpio_key->input_dev);
	platform_set_drvdata(pdev, NULL);
	return 0;
}

#ifdef CONFIG_PM
/**********************************************************
*  Function:       hw_gpio_key_suspend
*  Discription:    module remove
*  Parameters:     pdev:platform_device pm_message_t state
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_gpio_key_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct hw_gpio_key *gpio_key = platform_get_drvdata(pdev);

	g_suspended = true;
#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
		echub_info("tablet switch ulsr disable irq\n");
		disable_irq(gpio_key->tablet_switch_irq);
		return 0;
	}
#endif
	return 0;
}

/**********************************************************
*  Function:       hw_gpio_key_resume
*  Discription:    module remove
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_gpio_key_resume(struct platform_device *pdev)
{
	struct hw_gpio_key *gpio_key = platform_get_drvdata(pdev);

	g_suspended = false;
	irq_set_irq_type(gpio_key->tablet_switch_irq, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING);

#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
		echub_info("tablet switch ulsr enable irq\n");
		enable_irq(gpio_key->tablet_switch_irq);
		cancel_delayed_work_sync(&gpio_key->tablet_switch_irq_work);
		schedule_delayed_work(&gpio_key->tablet_switch_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE));
	}
#endif
	return 0;
}
#endif

static const struct of_device_id hw_gpio_key_match[] = {
	{ .compatible = "huawei,echub_tablet_switch" },
	{},
};
MODULE_DEVICE_TABLE(of, hw_gpio_key_match);

struct platform_driver echub_tablet_switch_driver = {
	.probe = hw_tablet_switch_probe,
	.remove = hw_tablet_switch_remove,
	.driver = {
		.name = "echub_tablet_switch",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(hw_gpio_key_match),
	},
#ifdef CONFIG_PM
	.suspend = hw_gpio_key_suspend,
	.resume = hw_gpio_key_resume,
#endif
};

int __init hw_echub_tablet_switch_init(void)
{
	int ret;

	echub_info("%s\n", __func__);
	ret = platform_driver_register(&echub_tablet_switch_driver);
	if (ret)
		echub_err("tablet switch device register err\n");

	return ret;
}

void __exit hw_echub_tablet_switch_exit(void)
{
	echub_info("%s\n", __func__);
	platform_driver_unregister(&echub_tablet_switch_driver);
}

module_init(hw_echub_tablet_switch_init);
module_exit(hw_echub_tablet_switch_exit);

MODULE_ALIAS("armpc echub switch module");
MODULE_DESCRIPTION("armpc echub switch driver");
MODULE_LICENSE("GPL");
