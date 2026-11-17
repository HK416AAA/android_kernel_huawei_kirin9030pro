/*
 * Button.c
 *
 * Powerbutton/LID Button driver for echub
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
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/notifier.h>
#include <linux/jiffies.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/pm_wakeup.h>
#include <asm/irq.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/i2c.h>
#include <linux/suspend.h>
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include "securec.h"
#include "ospm_printf.h"
#include "echub_i2c.h"
#include "echub_lid.h"

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
#include <linux/miscdevice.h>
#include <linux/ioctl.h>
#include "power/ec_state_sync.h"
#endif

#ifdef CONFIG_DFX_ZEROHUNG
#include <platform/trace/hooks/zerohung.h>
#endif

#define GPIO_KEY_PRESS                 (1)
#define GPIO_KEY_RELEASE               (0)

#define GPIO_HIGH_VOLTAGE              (1)
#define GPIO_LOW_VOLTAGE               (0)
#define TIMER_DEBOUNCE                 (10)
#define WAKELOCK_DELAY_TIME            (1000)
#define DELAY_FOR_INIT_REPORT          (20000) // 20s
#define DELAY_FOR_HIBERNATE_REPORT     (5000) // 5s

#define MFG_MODE_ACCESS_ADDR	0x0408
#define MFG_MODE_ADDR	0x0489
#define READ_LID_FLAG_ADDR	0x04e9
#define WRITE_LID_POWERON_ADDR 0x028f
#define READ_LID_POWERON_ADDR 0x0290

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
#define DEVICE_NAME                 "lid"
#define LID_MAGIC                   0xEF
#define WRITE_LID_FLAG_ADDR         0x0479
#define OPEN_LID                    (_IO(LID_MAGIC, 0x1))
#define CLOSE_LID                   (_IO(LID_MAGIC, 0x0))
#define READ_LID_STATUS             (_IO(LID_MAGIC, 0x2))
#define READ_SLEEP_COUNT            (_IO(LID_MAGIC, 0x3))
#define AT_OPEN_LID                 1
#define AT_CLOSE_LID    			0
#endif

#define POWER_KEY_RELEASE 0
#define POWER_KEY_PRESS 1

struct hw_gpio_key {
	struct echub_i2c_dev *echub_dev;
	struct input_dev *input_dev;
	struct device *wakeup_dev;

	struct delayed_work lid_irq_work;
	struct notifier_block hibernate_nb;
	int gpio_lid;
	int lid_irq;
	bool lid_close_wakeup_enable;
};

static struct hw_gpio_key *g_hw_gpio_key = NULL;
#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
static int dis_irq_flag = 0;
#endif
/* is the lid closed */
static bool g_lid_closed = false;
/* is the pc in s3 */
static bool g_suspended = false;

static struct device *g_hw_lid_dev = NULL;
/**********************************************************
*  Function:       hw_gpio_key_open
*  Discription:    open gpiokey
*  Parameters:     input_dev *dev
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_gpio_key_open(struct input_dev *dev)
{
	/* add input device open function */
	echub_info("%s\n", __func__);
	return 0;
}

static void hw_gpio_key_close(struct input_dev *dev)
{
	/* add input device close function */
	echub_info("%s\n", __func__);
}

/**********************************************************
*  Function:       hw_lid_irq_work
*  Discription:    report lid open work
*  Parameters:     work_struct *work
*  return value:   0-sucess or others-fail
**********************************************************/
static void hw_lid_irq_work(struct work_struct *work)
{
	struct hw_gpio_key *gpio_key = container_of(work,
		struct hw_gpio_key, lid_irq_work.work);
	unsigned int report_action = GPIO_KEY_RELEASE;
	int keyup_value = gpio_get_value((unsigned int)gpio_key->gpio_lid);
	if (keyup_value == GPIO_LOW_VOLTAGE) {
		g_lid_closed = true;
		report_action = GPIO_KEY_PRESS;
	} else if (keyup_value == GPIO_HIGH_VOLTAGE) {
		g_lid_closed = false;
		report_action = GPIO_KEY_RELEASE;
	} else {
		echub_err("[gpiokey][%s]invalid gpio key_value.\n", __func__);
		return;
	}
	echub_info("report lid status: %d", !g_lid_closed);
#ifdef CONFIG_DFX_ZEROHUNG
	trace_hck_hung_wp_screen_set_lid_status((int)g_lid_closed);
#endif
	input_report_switch(gpio_key->input_dev, SW_LID, report_action);
	input_sync(gpio_key->input_dev);
}

/**********************************************************
*  Function:       hw_gpio_key_irq_handler
*  Discription:    gpio irq handler
*  Parameters:     int irq, void *dev_id
*  return value:   void
**********************************************************/
static irqreturn_t hw_gpio_key_irq_handler(int irq, void *dev_id)
{
	int key_value = 0;
	struct hw_gpio_key *gpio_key = (struct hw_gpio_key *)dev_id;
	if (gpio_key == NULL) {
		echub_err("gpio_key is NULL\n");
		return IRQ_HANDLED;
	}

	pm_wakeup_dev_event(gpio_key->wakeup_dev, WAKELOCK_DELAY_TIME, false);
	key_value = gpio_get_value((unsigned int)gpio_key->gpio_lid);
	echub_info("irq_handler hander key_value:%d g_lid_closed:%d g_suspended:%d\n",
		key_value,
		g_lid_closed,
		g_suspended);
	cancel_delayed_work(&(gpio_key->lid_irq_work));
	schedule_delayed_work(&gpio_key->lid_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE));
	return IRQ_HANDLED;
}

/**********************************************************
*  Function:       set_lid_status
*  Discription:    Enable or disable the LID irq based on the MFG mode and LID flag.
*  Parameters:     struct hw_gpio_key *gpio_key
*  return value:   0-sucess or others-fail
**********************************************************/
static int set_lid_status(struct hw_gpio_key *gpio_key)
{
	int ret = 0;
	u8 value = 0;

	/* Read lid flag */
	ret = gpio_key->echub_dev->transfer_func(gpio_key->echub_dev, READ_LID_FLAG_ADDR, NULL, 0, &value, 1);
	echub_info("Get lid flag form EC. ret = %d value = %d\n", ret, value);
	if (ret)
	    echub_info("Read lid flag failed: %d\n", ret);

	if (value == 1) {
	    echub_info("Disable lid irq\n");
	    disable_irq(gpio_key->lid_irq);
#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
        dis_irq_flag = 1;
#endif
	}

	return ret;
}

#ifdef CONFIG_OF
static const struct of_device_id hw_gpio_key_match[] = {
	{ .compatible = "huawei,echub-lid" },
	{},
};
MODULE_DEVICE_TABLE(of, hw_gpio_key_match);
#endif

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
	set_bit(SW_LID, input_dev->swbit);
	set_bit(EV_KEY, input_dev->evbit);
	set_bit(KEY_POWER, input_dev->keybit);

	input_dev->open = hw_gpio_key_open;
	input_dev->close = hw_gpio_key_close;

	return input_dev;
}

static int init_lid_gpio(struct platform_device *pdev, struct hw_gpio_key *gpio_key)
{
	int err = 0;

	if (!pdev || !gpio_key)
		return -EINVAL;

	/* initial work before we use it. */
	INIT_DELAYED_WORK(&(gpio_key->lid_irq_work), hw_lid_irq_work);

	gpio_key->lid_close_wakeup_enable = of_property_read_bool(pdev->dev.of_node, "lid-close-wakeup-enable");

	/* inital gpio_lid */
	err = of_property_read_u32(pdev->dev.of_node, "gpio-key-lid", (u32 *)&gpio_key->gpio_lid);
	if (err) {
		gpio_key->gpio_lid = 0;
		echub_info("%s: Not support gpio_key lid\n", __func__);
		return -EFAULT;
	} else {
		echub_info("%s: Support gpio_key lid: %d\n", __func__, gpio_key->gpio_lid);
	}

	if (!gpio_is_valid(gpio_key->gpio_lid)) {
		echub_err("%s: gpio of lid is not valid, check DTS\n", __func__);
		return -EFAULT;
	}

	err = devm_gpio_request(&pdev->dev, (unsigned int)gpio_key->gpio_lid, "gpio_lid");
	if (err < 0) {
		echub_err("Fail request gpio:%d\n", gpio_key->gpio_lid);
		return -EFAULT;
	}

	err = gpio_direction_input((unsigned int)gpio_key->gpio_lid);
	if (err < 0) {
		echub_err("Failed to set gpio_lid directoin!\n");
		return -EFAULT;
	}

	gpio_key->lid_irq = gpio_to_irq((unsigned int)gpio_key->gpio_lid);
	if (gpio_key->lid_irq < 0) {
		echub_err("Failed to get gpio key press irq!\n");
		return -EFAULT;
	}

	err = request_irq(gpio_key->lid_irq, hw_gpio_key_irq_handler,
		IRQF_NO_SUSPEND | IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING, pdev->name, gpio_key);
	if (err) {
		echub_err("Failed to request press interupt handler!\n");
		return -EFAULT;
	}

	return 0;
}

/**********************************************************
*  Function:       hw_lid_is_closed
*  Discription:    get lid status
*  return value:   true-closed or false-open
**********************************************************/
bool hw_lid_is_closed()
{
    return g_lid_closed;
}
EXPORT_SYMBOL(hw_lid_is_closed);

int get_lid_status(void)
{
	int status;

	if (!g_hw_gpio_key || !gpio_is_valid(g_hw_gpio_key->gpio_lid)) {
		echub_err("%s: gpio of lid is not valid\n", __func__);
		return -ENODEV;
	}
	status = gpio_get_value((unsigned int)g_hw_gpio_key->gpio_lid);
	return status;
}

#ifdef CONFIG_SYSFS
static ssize_t status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int status;

	if (!buf)
		return 0;

	status = get_lid_status();
	return sprintf_s(buf, PAGE_SIZE, "%d", status);
}

static ssize_t poweron_enable_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int ret;
	unsigned char value = 0;
	struct hw_gpio_key *di = g_hw_gpio_key;

	if (di == NULL || di->echub_dev == NULL || di->echub_dev->transfer_func == NULL)
		return -EINVAL;

	ret = di->echub_dev->transfer_func(di->echub_dev, READ_LID_POWERON_ADDR, NULL, 0, &value, 1);
	if (ret) {
		echub_err("get poweron trans failed: %d\n", ret);
		return ret;
	}
	echub_info("get poweron enable:%d\n", value);

	return sprintf_s(buf, PAGE_SIZE, "%d\n", value);
}

static ssize_t poweron_enable_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int enable = 0;
	int ret;
	struct hw_gpio_key *di = g_hw_gpio_key;

	if (di == NULL || di->echub_dev == NULL || di->echub_dev->write_func == NULL)
		return -EINVAL;

	ret = kstrtouint(buf, 0, &enable);
	if (ret < 0)
		return -EINVAL;

	if (enable != 0 && enable != 1) {
		echub_err("enable is invalid\n");
		return -EINVAL;
	}
	echub_info("set poweron enable:%d\n", enable);

	ret = di->echub_dev->write_func(di->echub_dev, WRITE_LID_POWERON_ADDR, (unsigned char)enable);
	if (ret) {
		echub_err("set poweron failed: %d\n", ret);
		return ret;
	}

	return count;
}

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
static ssize_t status_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
static DEVICE_ATTR(status, S_IWUSR | S_IRUGO, status_show, status_store);
#else
static DEVICE_ATTR(status, 0664, status_show, NULL);
#endif /*CONFIG_ARMPC_ECHUB_LID_TEST*/
static DEVICE_ATTR(poweron_enable, 0660, poweron_enable_show, poweron_enable_store);

static struct attribute *hw_lid_attributes[] = {
	&dev_attr_status.attr,
	&dev_attr_poweron_enable.attr,
	NULL,
};

static const struct attribute_group hw_lid_attr_group = {
	.attrs = hw_lid_attributes,
};

static struct device *hw_lid_create_group(void)
{
	return power_sysfs_create_group("hw_echub", "lid",
		&hw_lid_attr_group);
}

static void hw_lid_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &hw_lid_attr_group);
}
#else
static inline struct device *hw_lid_create_group(void)
{
	return NULL;
}

static inline void hw_lid_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static int echub_lid_hibernate_callback(struct notifier_block *nb, unsigned long event, void *ptr)
{
	struct hw_gpio_key *di = g_hw_gpio_key;

	if (!di) {
		echub_err("lid hibernate nb callback error!");
		return NOTIFY_BAD;
	}

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
	if (dis_irq_flag) {
		echub_info("lid diasble, do nothing");
		return NOTIFY_OK;
	}
#endif

	switch (event) {
	case PM_HIBERNATION_PREPARE:
		disable_irq(di->lid_irq);
		break;
	case PM_POST_HIBERNATION:
		enable_irq(di->lid_irq);
		schedule_delayed_work(&di->lid_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE + DELAY_FOR_HIBERNATE_REPORT));
		break;
	default:
		break;
	}
	echub_info("lid receive hibernate event %d", event);
    return NOTIFY_OK;
}

static void init_lid_pm(struct hw_gpio_key *gpio_key)
{
	gpio_key->hibernate_nb.notifier_call  = echub_lid_hibernate_callback;
	register_pm_notifier(&gpio_key->hibernate_nb);

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
	if (dis_irq_flag) {
		echub_info("lid diasble, init do nothing");
		return;
	}
#endif
	schedule_delayed_work(&gpio_key->lid_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE + DELAY_FOR_INIT_REPORT));
}

/**********************************************************
*  Function:       hw_gpio_key_probe
*  Discription:    module probe
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_gpio_key_probe(struct platform_device *pdev)
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

	echub_info("armpc gpio key driver probes start!\n");

	gpio_key = devm_kzalloc(&pdev->dev, sizeof(struct hw_gpio_key), GFP_KERNEL);
	if (gpio_key == NULL) {
		echub_info("Failed to allocate struct hw_gpio_key!\n");
		return -ENOMEM;
	}

	input_dev = init_input_dev(pdev, gpio_key);
	if (input_dev == NULL)
		return -ENOMEM;

	gpio_key->input_dev = input_dev;
	gpio_key->echub_dev = echub_dev;
	gpio_key->wakeup_dev = &pdev->dev;
	g_hw_lid_dev = hw_lid_create_group();

	err = init_lid_gpio(pdev, gpio_key);
	if (err)
		goto err_lid_gpio;

	err = input_register_device(gpio_key->input_dev);
	if (err) {
		echub_err("Failed to register input device!\n");
		goto err_register_dev;
	}

	device_init_wakeup(&pdev->dev, true);
	platform_set_drvdata(pdev, gpio_key);

	g_hw_gpio_key = gpio_key;
	set_lid_status(gpio_key);
	init_lid_pm(gpio_key);

	echub_info("armpc gpio key driver probes successfully!\n");
	return 0;

err_register_dev:
	free_irq(gpio_key->lid_irq, gpio_key);
err_lid_gpio:
	input_free_device(input_dev);
	echub_err("[gpiokey] gpio key probe failed! ret = %d.\n", err);
	return err;
}

/**********************************************************
*  Function:       hw_gpio_key_remove
*  Discription:    module remove
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_gpio_key_remove(struct platform_device *pdev)
{
	struct hw_gpio_key *gpio_key = platform_get_drvdata(pdev);

	if (gpio_key == NULL) {
		echub_err("get invalid gpio_key pointer\n");
		return -EINVAL;
	}

	unregister_pm_notifier(&gpio_key->hibernate_nb);
	hw_lid_remove_group(g_hw_lid_dev);
	g_hw_lid_dev = NULL;

	free_irq(gpio_key->lid_irq, gpio_key);
	cancel_delayed_work(&(gpio_key->lid_irq_work));

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
		echub_info("lid ulsr disable irq\n");
		disable_irq(gpio_key->lid_irq);
		return 0;
	}
#endif
	if (gpio_key->lid_close_wakeup_enable)
		irq_set_irq_type(gpio_key->lid_irq, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING);
	else
		irq_set_irq_type(gpio_key->lid_irq, IRQF_TRIGGER_RISING);
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
	irq_set_irq_type(gpio_key->lid_irq, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING);
#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
	if (dis_irq_flag) {
		return 0;
	}
#endif
#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
		echub_info("lid ulsr enable irq\n");
		enable_irq(gpio_key->lid_irq);
		cancel_delayed_work_sync(&gpio_key->lid_irq_work);
		schedule_delayed_work(&gpio_key->lid_irq_work, msecs_to_jiffies(TIMER_DEBOUNCE));
	}
#endif
	return 0;
}
#endif

struct platform_driver hw_gpio_key_driver = {
	.probe = hw_gpio_key_probe,
	.remove = hw_gpio_key_remove,
	.driver = {
		.name = "hw_gpio_key",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(hw_gpio_key_match),
	},
#ifdef CONFIG_PM
	.suspend = hw_gpio_key_suspend,
	.resume = hw_gpio_key_resume,
#endif
};

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
static int open_lid(struct hw_gpio_key *gpio_key)
{
	int ret;
	
	if (!gpio_key) {
		echub_err("[%s:%dL] gpio_key is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}

	enable_irq(gpio_key->lid_irq);
	ret = gpio_key->echub_dev->write_func(gpio_key->echub_dev, WRITE_LID_FLAG_ADDR, 0);
	if (ret)
		echub_err("write 0x0 to EC failed\n");

	return 0;
}

static int close_lid(struct hw_gpio_key *gpio_key)
{
	int ret;
	
	if (!gpio_key) {
		echub_err("[%s:%dL] gpio_key is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	disable_irq(gpio_key->lid_irq);
	ret = gpio_key->echub_dev->write_func(gpio_key->echub_dev, WRITE_LID_FLAG_ADDR, 1);
	if (ret)
		echub_err("write 0x1 to EC failed\n");
	return 0;
}

static int read_lid_status(struct hw_gpio_key *gpio_key)
{
	int lid_status;

	if (!gpio_key) {
		echub_err("[%s:%dL] gpio_key is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	lid_status = gpio_get_value((unsigned int)gpio_key->gpio_lid);
	return !!lid_status;
}

static int read_sleep_count(void)
{
	return get_sleep_count();
}

static int lid_open(struct inode *inode, struct file *flip)
{
	if (!flip) {
		echub_err("[%s:%dL] flip is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	flip->private_data = g_hw_gpio_key;
	return 0;
}

static int lid_release(struct inode *inode, struct file *flip)
{
	return 0;
}

static long lid_ioctl(struct file *flip, unsigned int cmd, unsigned long arg)
{
	int ret = 0;

	switch (cmd) {
	case OPEN_LID:
		echub_err("lid_dev: enable lid irq by ioctl\n");
		ret = open_lid(g_hw_gpio_key);
		if (!ret)
			dis_irq_flag = 0;
		break;
	case CLOSE_LID:
		echub_err("lid_dev: disable lid irq by ioctl\n");
		ret = close_lid(g_hw_gpio_key);
		if (!ret)
			dis_irq_flag = 1;
		break;
	case READ_LID_STATUS:
		ret = read_lid_status(g_hw_gpio_key);
		if (ret != 0 && ret != 1)
			echub_err("lid_dev: read lid status error\n");
		break;
	case READ_SLEEP_COUNT:
		ret = read_sleep_count();
		if (ret < 0)
			echub_err("read sleep count error\n");
		break;
	default:
		echub_err("lid_dev ioctl cmd error: open: 1; close: 0; read: 2\n");
		return -EINVAL;
	}
	return ret;
}

static struct file_operations lid_dev_fops = {
	.owner          = THIS_MODULE,
	.unlocked_ioctl = lid_ioctl,
	.open			= lid_open,
	.release		= lid_release,
};

static struct miscdevice lid_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name  = DEVICE_NAME,
	.fops  = &lid_dev_fops,
};
#endif

#ifdef CONFIG_SYSFS
#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
static ssize_t status_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	int ret, wb;

	if (buf == NULL) {
		echub_err("[%s:%dL] buf is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("%s incorrect format\n", __func__);
		return -EINVAL;
    }

	switch (wb) {
	case AT_OPEN_LID:
		echub_err("lid_dev: enable lid irq by AT cmd\n");
		ret = open_lid(g_hw_gpio_key);
		if (!ret)
			dis_irq_flag = 0;
		break;
	case AT_CLOSE_LID:
		echub_err("lid_dev: disable lid irq by AT cmd\n");
		ret = close_lid(g_hw_gpio_key);
		if (!ret)
			dis_irq_flag = 1;
		break;
	default:
		echub_err("%s cmd error: open: 1; close: 0\n",  __func__);
		return -EINVAL;
	}
	return count;
}
#endif /*CONFIG_ARMPC_ECHUB_LID_TEST*/
#endif /* CONFIG_SYSFS */

/**********************************************************
*  Function:       hw_gpio_key_init
*  Discription:    module initialization
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
int __init hw_gpio_key_init(void)
{
	int ret;

	echub_info("%s\n", __func__);
	ret = platform_driver_register(&hw_gpio_key_driver);
	if (ret)
		echub_err("lid_dev misc_register err\n");

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
	ret = misc_register(&lid_dev);
	if (ret)
		echub_err("lid_dev misc_register err\n");
#endif
	return ret;
}

/**********************************************************
*  Function:       hw_gpio_key_exit
*  Discription:    module exit
*  Parameters:     NULL
*  return value:   NULL
**********************************************************/
void __exit hw_gpio_key_exit(void)
{
	echub_info("%s\n", __func__);
#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
	misc_deregister(&lid_dev);
#endif
	platform_driver_unregister(&hw_gpio_key_driver);
}

module_init(hw_gpio_key_init);
module_exit(hw_gpio_key_exit);

MODULE_ALIAS("armpc echub button module");
MODULE_DESCRIPTION("armpc echub button driver");
MODULE_LICENSE("GPL");
