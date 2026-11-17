/*
 * hw_usb_hub.c
 *
 * usb hub driver
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/usb.h>
#include <linux/io.h>
#include <linux/device.h>
#include <linux/pm.h>
#include <linux/suspend.h>
#include <linux/i2c.h>
#include <linux/syscore_ops.h>
#include <dfx/hiview_hisysevent.h>
#include <linux/errno.h>
#include <linux/printk.h>
#include <linux/time64.h>
#include <linux/workqueue.h>
#include <linux/platform_drivers/usb/tca.h>
#include "hw_usb_hub.h"
static struct usb_hub *g_uhub;

static int echub_i2c_write_regulator(u16 regoffset, char regdata)
{
	int ret;
	struct i2c_adapter *adap;
	struct i2c_msg msg[2];
	unsigned char data[4];
	unsigned char value[2];
	const unsigned char devaddr = REG_SEND_ADDR;

	adap = i2c_get_adapter(REG_SEND_ADAPTER);
	/* check adapter is valid */
	if (adap == NULL) {
		pr_err("%s adap error\n", __func__);
		return -ENODEV;
	}

	/* write data buffer */
	msg[0].addr = devaddr;
	msg[0].flags = 0;
	msg[0].len = ECHUB_SEND_BYTE_LEN;
	msg[0].buf = data;
	data[0] = (u8)(regoffset >> BIT_OFFSET);
	data[1] = (u8)(regoffset & 0xFF);
	data[2] = REG_DATE_LEN;
	data[3] = regdata;

	/* read data buffer */
	msg[1].addr = devaddr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = ECHUB_SEND_TRANS_LEN;
	msg[1].buf = value;

	ret = i2c_transfer(adap, msg, ECHUB_SEND_TRANS_LEN);
	i2c_put_adapter(adap);

	/* check i2c transfer result */
	if (ret != ECHUB_SEND_TRANS_LEN) {
		pr_err("%s TRANS_LEN error\n", __func__);
		return -ENODEV;
	}
	if (value[0]) {
		pr_err("%s value[0] error\n", __func__);
		return -EIO;
	}

	return 0;
}

static int set_gpio_output_val(u32 gpio_num, u32 gpio_val, u32 sleep_time)
{
	int ret = 0;

	if (gpio_num > 0) {
		ret = gpio_direction_output(gpio_num, gpio_val);
		if (ret) {
			pr_err("could not set gpio %u as output, ret = %d\n", gpio_num, ret);
			return ret;
		}
	}

	if (sleep_time > 0)
		msleep(sleep_time);
    return 0;
}

static int hw_usb_device_power_on(const struct usb_hub *uhub)
{
	if (uhub == NULL)
		return -ENODEV;

	pr_info("%s ++\n", __func__);
	if (uhub->usbcam_pwr_en_gpio > 0)
		gpio_set_value(uhub->usbcam_pwr_en_gpio, uhub->bios_usbcam_pwr_status);
	if (uhub->hub_cam_gpio_delay_time > 0)
		msleep(uhub->hub_cam_gpio_delay_time);

	if (uhub->usbnet_power_gpio > 0)
		gpio_set_value(uhub->usbnet_power_gpio, uhub->bios_usbnet_pwr_status);
	if (uhub->hub_net_gpio_delay_time > 0)
		msleep(uhub->hub_net_gpio_delay_time);
	pr_info("%s --\n", __func__);

	return 0;
}

static int hw_usb_device_power_off(const struct usb_hub *uhub)
{
	if (uhub == NULL) {
        return -ENODEV;
    }

	pr_info("%s ++\n", __func__);

	if (set_gpio_output_val(uhub->usbcam_pwr_en_gpio, GPIO_LOW, uhub->hub_cam_gpio_delay_time)) {
        return -EINVAL;
    }

	if (set_gpio_output_val(uhub->usbnet_power_gpio, GPIO_LOW, uhub->hub_net_gpio_delay_time)) {
        return -EINVAL;
    }

	pr_info("%s --\n", __func__);
	return 0;
}

static void usb_device_poweron_work(struct work_struct *work)
{
    if (work == NULL) {
		pr_err("%s : work is null!\n", __func__);
		return;
	}

	int ret;
	struct usb_hub *uhub = container_of(work, struct usb_hub, power_work.work);
	if (uhub) {
		ret = hw_usb_device_power_on(uhub);
		if (ret)
			pr_err("usb device power on failed\n");
	}
}

static int hw_usb_hub_power_on(const struct usb_hub *uhub)
{
	int i, ret;

	if (uhub == NULL)
		return -ENODEV;

	pr_info("%s ++\n", __func__);
	if (uhub->ec_addr > 0 && uhub->ec_cmd_nums > 0) {
		pr_info("ec register is %x\n", uhub->ec_addr);
		for (i = 0; i < uhub->ec_cmd_nums && uhub->ec_cmd_on_list[i] > 0; i++) {
			pr_info("ec_cmd_on_list[%d] = %x\n", i, uhub->ec_cmd_on_list[i]);
			ret = echub_i2c_write_regulator(uhub->ec_addr, uhub->ec_cmd_on_list[i]);
			if (ret)
				pr_err("power on error, cmd is %x, ret = %d\n", uhub->ec_cmd_on_list[i], ret);
			if (uhub->ec_cmd_delay_time_list[i] > 0)
				msleep(uhub->ec_cmd_delay_time_list[i]);
		}
	}

	if (uhub->usbhub_1v05_gpio > 0)
		gpio_set_value(uhub->usbhub_1v05_gpio, GPIO_HIGH);
	if (uhub->hub_1v05_gpio_delay_time > 0)
		msleep(uhub->hub_1v05_gpio_delay_time);

	if (uhub->usbhub_vdd_on_gpio > 0)
		gpio_set_value(uhub->usbhub_vdd_on_gpio, GPIO_HIGH);
	if (uhub->hub_vdd_gpio_delay_time > 0)
		msleep(uhub->hub_vdd_gpio_delay_time);

	if (uhub->poweron_time > 0)
		msleep(uhub->poweron_time);
	pr_info("%s --\n", __func__);

	return 0;
}

static int hw_usb_hub_level2_power_on(const struct usb_hub *uhub)
{
	if (uhub == NULL)
		return -ENODEV;
 
	pr_info("%s ++\n", __func__);
	if (uhub->usbhub_level2_vdd_on_gpio > 0) {
		gpio_set_value(uhub->usbhub_level2_vdd_on_gpio, GPIO_HIGH);
		if (uhub->hub_vdd_gpio_delay_time > 0)
			msleep(uhub->hub_vdd_gpio_delay_time);
	}
	return 0;
}

static int hw_usb_hub_power_off(const struct usb_hub *uhub)
{
	int i, ret;

	if (uhub == NULL)
		return -ENODEV;

	pr_info("%s ++\n", __func__);
	if (uhub->ec_addr > 0 && uhub->ec_cmd_nums > 0) {
		pr_info("ec register is %x\n", uhub->ec_addr);
		for (i = 0; i < uhub->ec_cmd_nums && uhub->ec_cmd_off_list[i] > 0; i++) {
			pr_info("ec_cmd_off_list[%d] = %x\n", i, uhub->ec_cmd_off_list[i]);
			ret = echub_i2c_write_regulator(uhub->ec_addr, uhub->ec_cmd_off_list[i]);
			if (ret)
				pr_err("power off error, cmd is %x, ret = %d\n", uhub->ec_cmd_off_list[i], ret);
			if (uhub->ec_cmd_delay_time_list[i] > 0)
				msleep(uhub->ec_cmd_delay_time_list[i]);
		}
	}

	ret = hw_usb_device_power_off(uhub);
	if (ret)
		pr_err("usb devices poweroff failed\n");

	set_gpio_output_val(uhub->usbhub_1v05_gpio, GPIO_LOW, uhub->hub_1v05_gpio_delay_time);

	set_gpio_output_val(uhub->usbhub_vdd_on_gpio, GPIO_LOW, uhub->hub_vdd_gpio_delay_time);

	set_gpio_output_val(uhub->usbhub_level2_vdd_on_gpio, GPIO_LOW, uhub->hub_vdd_gpio_delay_time);

	if (uhub->poweroff_time > 0)
		msleep(uhub->poweroff_time);

	pr_info("%s --\n", __func__);
	return 0;
}

static int hw_usb_hub_reset(struct usb_hub *uhub)
{
	if (uhub == NULL)
		return -ENODEV;

	pr_info("%s ++\n", __func__);

	set_gpio_output_val(uhub->hub_bpwr_gpio, GPIO_HIGH, DEFAULT_DELAY_TIME);
	set_gpio_output_val(uhub->back_hub_reset_gpio, GPIO_LOW, DEFAULT_DELAY_TIME);

	if (uhub->reset_or_bpwr_delay_time > 0)
		msleep(uhub->reset_or_bpwr_delay_time);

	set_gpio_output_val(uhub->hub_level2_bpwr_gpio, GPIO_HIGH, DEFAULT_DELAY_TIME);
	set_gpio_output_val(uhub->hub_level2_bpwr2_gpio, GPIO_HIGH, uhub->reset_or_bpwr2_delay_time);

	pr_info("%s --\n", __func__);

	return 0;
}

static int hw_usb_hub_dereset(struct usb_hub *uhub)
{
	if (uhub == NULL) {
		pr_err("%s, uhub is NULL\n", __func__);
		return -ENODEV;
	}

	pr_info("%s ++\n", __func__);

	if (uhub->hub_bpwr_gpio > 0)
		gpio_set_value(uhub->hub_bpwr_gpio, GPIO_LOW);
	if (uhub->back_hub_reset_gpio > 0)
		gpio_set_value(uhub->back_hub_reset_gpio, GPIO_HIGH);
	if (uhub->reset_or_bpwr_delay_time > 0)
		msleep(uhub->reset_or_bpwr_delay_time);

	pr_info("%s --\n", __func__);

	return 0;
}

static int hw_usb_hub_level2_dereset(struct usb_hub *uhub)
{
	if (uhub == NULL) {
		pr_err("%s, uhub is NULL\n", __func__);
		return -ENODEV;
	}
 
	pr_info("%s ++\n", __func__);
	if (uhub->hub_level2_bpwr_gpio > 0)
		gpio_set_value(uhub->hub_level2_bpwr_gpio, GPIO_LOW);
	if (uhub->hub_level2_bpwr2_gpio > 0)
		gpio_set_value(uhub->hub_level2_bpwr2_gpio, GPIO_LOW);
	if (uhub->reset_or_bpwr2_delay_time > 0)
		msleep(uhub->reset_or_bpwr2_delay_time);
 
	pr_info("%s --\n", __func__);
 
	return 0;
}

static void usb_hub2_poweron_work(struct work_struct *work)
{
    if (work == NULL) {
		pr_err("%s : work is null!\n", __func__);
		return;
	}

	pr_info("%s enter\n", __func__);
	int ret;
	if (g_uhub) {
		ret = hw_usb_hub_level2_power_on(g_uhub);
		if (ret) {
			pr_warn("usb hub level2 poweron failed: %d\n", ret);
		}

		ret = hw_usb_hub_level2_dereset(g_uhub);
		if (ret) {
			pr_warn("usb hub level2 dereset failed: %d\n", ret);
		}
	}
}

static void pull_usb_hub_reset_gpio(struct usb_hub *uhub, int operation)
{
	if (uhub->xh_hub_level1_reset_gpio > 0) {
		pr_info("%s xh_hub_level1_reset_gpio handling\n", __func__);
		gpio_direction_output(uhub->xh_hub_level1_reset_gpio, operation);
	}

	if (uhub->hub_bpwr_gpio > 0) {
		pr_info("%s hub_bpwr_gpio handling\n", __func__);
		gpio_direction_output(uhub->hub_bpwr_gpio, operation);
	}

	pr_info("%s: XH HUB reset gpio: %s\n", __func__, (operation == 0) ? "low" : "high");
}

static void force_usb_reset(struct usb_hub *uhub)
{
	if (uhub == NULL) {
		pr_err("%s, uhub is NULL\n", __func__);
		return;
	}
	pr_info("[%s] reset combophy++\n", __func__);
	gpio_set_value(DP2VGA_RESET_GPIO, GPIO_LOW);
	pull_usb_hub_reset_gpio(uhub, GPIO_HIGH);
	hw_usb_device_power_off(uhub);

	pd_event_notify(TCA_IRQ_HPD_OUT, TCPC_USB31_AND_DP_2LINE, TCA_DP_OUT, TYPEC_ORIEN_POSITIVE);
	pd_event_notify(TCA_IRQ_HPD_OUT, TCPC_USB31_AND_DP_2LINE, TCA_ID_RISE_EVENT, TYPEC_ORIEN_POSITIVE);
	msleep(HUB_RESET_TIME);
	pd_event_notify(TCA_IRQ_HPD_IN, TCPC_USB31_AND_DP_2LINE, TCA_ID_FALL_EVENT, TYPEC_ORIEN_POSITIVE);
	pd_event_notify(TCA_IRQ_HPD_IN, TCPC_USB31_AND_DP_2LINE, TCA_DP_IN, TYPEC_ORIEN_POSITIVE);
	msleep(RESET_TIME);
	pull_usb_hub_reset_gpio(uhub, GPIO_LOW);
	schedule_delayed_work(&uhub->power_work,
					msecs_to_jiffies(uhub->usb_device_poweron_wait_time));
	gpio_set_value(DP2VGA_RESET_GPIO, GPIO_HIGH);
	pr_info("[%s] reset combophy--\n", __func__);


}

static void force_usb_device_reset(struct usb_hub *uhub)
{
	if (uhub == NULL) {
		pr_err("%s, uhub is NULL\n", __func__);
		return;
	}
	pr_info("force_usb_device_reset\n");
	hw_usb_device_power_off(uhub);

	msleep(DEVICE_RESET_TIME);

	hw_usb_device_power_on(uhub);
}

static ssize_t hub_reset_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	if (buf == NULL) {
		pr_err("%s, buf is NULL\n", __func__);
		return -EINVAL;
	}
	uint64_t val = 0;

	if (g_uhub == NULL) {
		pr_err("g_uhub is null\n");
		return -EINVAL;
	}

	if (kstrtoull(buf, 10, &val) != 0) {
		pr_err("invalid parameters!\n");
		return -EINVAL;
	}

	if (val == 1)
		force_usb_reset(g_uhub);
	else
		force_usb_device_reset(g_uhub);

	return count;
}

static DEVICE_ATTR(hub_reset, 0644, NULL, hub_reset_store);
static struct attribute *usb_hub_ctrl_attributes[] = {
	&dev_attr_hub_reset.attr,
	NULL
};

static const struct attribute_group usb_hub_attr_group = {
	.attrs = usb_hub_ctrl_attributes,
};

static int hub_port_setup_sysfs(struct usb_hub *uhub)
{
	int ret;

	if (uhub == NULL)
		return -ENODEV;

	uhub->usb_hub_class = class_create(THIS_MODULE, "usb_hub");
	if (IS_ERR(uhub->usb_hub_class)) {
		pr_err("cannot create class!\n");
		ret = PTR_ERR(uhub->usb_hub_class);
		goto fail_create_class;
	}

	uhub->dev = device_create(uhub->usb_hub_class, NULL, 0, NULL, "hub");
	if (IS_ERR(uhub->dev)) {
		pr_err("sysfs device create failed!\n");
		ret = PTR_ERR(uhub->dev);
		goto fail_create_device;
	}

	ret = sysfs_create_group(&uhub->dev->kobj, &usb_hub_attr_group);
	if (ret < 0) {
		pr_err("sysfs group create failed! ret = %d\n", ret);
		goto fail_create_sysfs;
	}
	return ret;

fail_create_sysfs:
	device_destroy(uhub->usb_hub_class, uhub->dev->devt);

fail_create_device:
	class_destroy(uhub->usb_hub_class);
	uhub->usb_hub_class = NULL;

fail_create_class:
	return ret;
}

static void hub_port_destroy_sysfs(const struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s, pdev is NULL\n", __func__);
		return;
	}

	struct usb_hub *uhub = platform_get_drvdata(pdev);
	if (uhub == NULL || uhub->dev == NULL) {
		pr_err("uhub or uhub->dev is NULL\n");
		return;
	}

	sysfs_remove_group(&uhub->dev->kobj, &usb_hub_attr_group);

	device_destroy(uhub->usb_hub_class, uhub->dev->devt);

	class_destroy(uhub->usb_hub_class);
	uhub->usb_hub_class = NULL;
}


static irqreturn_t hub_resume_soc_irq_handler(int irq, void *dev_id)
{
    pr_info("%s ++\n", __func__);

	int gpio_value = 0;
	if (g_uhub == NULL) {
		pr_info("g_uhub in hub_pwren_irq_handler is null !!!\n");
		return IRQ_HANDLED;
	}
	gpio_value = gpio_get_value(g_uhub->hub_resume_soc_gpio);
	pr_info("wakeup system by usb device!, gpio val = %d\n", gpio_value);

    pr_info("%s --\n", __func__);
	return IRQ_HANDLED;
}
 
static int roothub_resume_notify(struct notifier_block *self, unsigned long action, void *dev)
{
	if (self == NULL || dev == NULL) {
		pr_err("%s, self or dev is NULL\n", __func__);
		return -EINVAL;
	}

	int ret = 0;
	int resume_count = 0;
	struct usb_hub *uhub = container_of(self, struct usb_hub, roothub_nb);
	struct usb_device *udev = (struct usb_device *)dev;
	if (uhub == NULL || udev == NULL) {
		pr_err("%s uhub %p or udev %p is NULL", __func__, uhub, udev);
		return -EINVAL;
	}

    if (action == USB_DEV_RESUME) {
        mutex_lock(&uhub->notify_count_lock);
        resume_count = ++uhub->notify_roothub_resume_count;
        mutex_unlock(&uhub->notify_count_lock);
        pr_info("notify: %s usb devnum %d add, roothub resume count %d, serial = %s\n",
            __func__, udev->devnum, resume_count, udev->serial);
        if (resume_count == uhub->roothub_num) {
            pr_info("[%s] roothub_resume completed\n", __func__);
        }
    }
	return ret;
}

static int verify_gpionum_and_request(struct device *dev, const char *propname, u32 *gpio_ptr)
{
    if (dev == NULL || gpio_ptr == NULL) {
        pr_err("%s dev or ptr of gpio_ptr is NULL\n", __func__);
        return INIT_GPIO_FAIL;
    }

	if (of_property_read_u32(dev->of_node, propname, gpio_ptr)) {
        pr_err("%s can't get %s\n", __func__, propname);
        return NO_GPIO_IN_DTS;
    }
		

    if (!gpio_is_valid(*gpio_ptr)) {
        pr_err("%s : %u is unvalid!\n", propname, *gpio_ptr);
        return INIT_GPIO_FAIL;
    }

    if (devm_gpio_request(dev, *gpio_ptr, propname)) {
        pr_err("request %s : %u failed\n", propname, *gpio_ptr);
        return INIT_GPIO_FAIL;
    }

    return INIT_GPIO_SUCC;
}

static int of_device_init_power_gpios(struct platform_device *pdev)
{
	if (pdev == NULL)
		return -ENODEV;

    int ret = 0;
	int usbcam_init_state = 0;
	int usbnet_init_state = 0;
	struct device_node *np = pdev->dev.of_node;
	struct usb_hub *uhub = platform_get_drvdata(pdev);

	if (uhub == NULL)
		return -ENODEV;

    ret = verify_gpionum_and_request(&pdev->dev, "usbcam_pwr_en_gpio", &uhub->usbcam_pwr_en_gpio);
	if (ret == INIT_GPIO_SUCC) {
        if (of_property_read_u32(np, "usbcam_init_state", &usbcam_init_state))
            uhub->bios_usbcam_pwr_status = gpio_get_value(uhub->usbcam_pwr_en_gpio);
        else
            uhub->bios_usbcam_pwr_status = usbcam_init_state;
    } else if (ret == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

    ret = verify_gpionum_and_request(&pdev->dev, "usbnet_power_gpio", &uhub->usbnet_power_gpio);
    if (ret == INIT_GPIO_SUCC) {
        if (of_property_read_u32(np, "usbnet_init_state", &usbnet_init_state))
            uhub->bios_usbnet_pwr_status = gpio_get_value(uhub->usbnet_power_gpio);
        else
            uhub->bios_usbnet_pwr_status = usbnet_init_state;
    } else if (ret == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	return 0;
}

static int of_hub_init_wakeup_soc_gpios(struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s pdev is null\n", __func__);
		return -ENODEV;
	}
		

	int ret;
	struct usb_hub *uhub = platform_get_drvdata(pdev);

	if (uhub == NULL) {
		pr_err("%s uhub is null\n", __func__);
		return -ENODEV;
	}

    if (verify_gpionum_and_request(&pdev->dev, "hub_resume_soc_gpio", &uhub->hub_resume_soc_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	ret = gpio_direction_input(uhub->hub_resume_soc_gpio);
	if (ret < 0) {
		pr_err("Failed to set hub_resume_soc_gpio directoin!\n");
	}

	uhub->wakeup_irq = gpio_to_irq(uhub->hub_resume_soc_gpio);
	if (uhub->wakeup_irq < 0) {
		pr_err("Failed to map hub_resume_soc_gpio %d to IRQ\n", uhub->hub_resume_soc_gpio);
	}

	ret = request_threaded_irq(uhub->wakeup_irq, NULL, hub_resume_soc_irq_handler,
		IRQF_TRIGGER_FALLING | IRQF_ONESHOT | IRQF_NO_SUSPEND, "gpio_interrupt", uhub);
	if (ret) {
		pr_err("Failed to request IRQ %d, ret = %d\n", uhub->wakeup_irq, ret);
	}
	enable_irq_wake(uhub->wakeup_irq);
	pr_info("hub_resume_soc_gpio irq = %d!!\n", uhub->wakeup_irq);

	return 0;
}

static int of_hub_init_power_gpios(struct platform_device *pdev)
{
	if (pdev == NULL)
		return -ENODEV;

	struct device_node *np = pdev->dev.of_node;
	struct usb_hub *uhub = platform_get_drvdata(pdev);
	if (uhub == NULL)
		return -ENODEV;

    if (verify_gpionum_and_request(&pdev->dev, "hub_bpwr_gpio",
        &uhub->hub_bpwr_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (verify_gpionum_and_request(&pdev->dev, "hub_level2_bpwr_gpio",
        &uhub->hub_level2_bpwr_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (verify_gpionum_and_request(&pdev->dev, "hub_level2_bpwr2_gpio",
        &uhub->hub_level2_bpwr2_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (verify_gpionum_and_request(&pdev->dev, "back_hub_reset_gpio",
        &uhub->back_hub_reset_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (verify_gpionum_and_request(&pdev->dev, "usbhub_vdd_on_gpio",
        &uhub->usbhub_vdd_on_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (verify_gpionum_and_request(&pdev->dev, "usbhub_level2_vdd_on_gpio",
        &uhub->usbhub_level2_vdd_on_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (verify_gpionum_and_request(&pdev->dev, "usbhub_1v05_gpio",
        &uhub->usbhub_1v05_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (verify_gpionum_and_request(&pdev->dev, "xh_hub_level1_reset_gpio",
        &uhub->xh_hub_level1_reset_gpio) == INIT_GPIO_FAIL) {
        return -EINVAL;
    }

	if (of_device_init_power_gpios(pdev)) {
        pr_err("Init device power gpios failed\n");
        return -EINVAL;
    }

	if (of_hub_init_wakeup_soc_gpios(pdev)) {
        pr_err("Init wakeup soc gpios failed\n");
        return -EINVAL;
    }

	return 0;
}

static int of_hub_init_power_ec(const struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s pdev is null!\n", __func__);
		return -EINVAL;
	}
	int ret;
	struct device_node *np = pdev->dev.of_node;
	struct usb_hub *uhub = platform_get_drvdata(pdev);

	if (uhub == NULL)
		return -ENODEV;

	ret = of_property_read_u32(np, "ec_addr", &uhub->ec_addr);
	if (ret) {
		pr_info("can't get ec_addr, ret = %d\n", ret);
		return ret;
	}

	ret = of_property_read_u32(np, "ec_cmd_nums", &uhub->ec_cmd_nums);
	if (ret) {
		pr_err("can't get ec_cmd_nums, ret = %d\n", ret);
		return ret;
	}

	if (uhub->ec_cmd_nums > MAX_CMD_NUM) {
		pr_err("ec_cmd_nums Overflow in dts!\n");
		uhub->ec_cmd_nums = MAX_CMD_NUM;
	}

	if (uhub->ec_cmd_nums <= 0) {
		pr_err("ec_cmd_nums is invalid: %d\n", uhub->ec_cmd_nums);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "ec_cmd_off_list", &uhub->ec_cmd_off_list[0], uhub->ec_cmd_nums);
	if (ret) {
		pr_err("can't get ec_cmd_off_list, ret = %d\n", ret);
		return ret;
	}
	ret = of_property_read_u32_array(np, "ec_cmd_on_list", &uhub->ec_cmd_on_list[0], uhub->ec_cmd_nums);
	if (ret) {
		pr_err("can't get ec_cmd_on_list, ret = %d\n", ret);
		return ret;
	}
	ret = of_property_read_u32_array(np, "ec_cmd_delay_time_list", &uhub->ec_cmd_delay_time_list[0], uhub->ec_cmd_nums);
	if (ret)
		pr_err("can't get ec_cmd_delay_time_list, ret = %d\n", ret);

	return 0;
}

static int of_hub_init_timing_paras(const struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s pdev is null\n", __func__);
		return -EINVAL;
	}

	struct device_node *np = pdev->dev.of_node;
	struct usb_hub *uhub = platform_get_drvdata(pdev);

	if (uhub == NULL)
		return -ENODEV;

	if (of_property_read_u32(np, "reset_or_bpwr_delay_time", &uhub->reset_or_bpwr_delay_time))
		pr_info("can't get reset_or_bpwr_delay_time.\n");

	if (of_property_read_u32(np, "reset_or_bpwr2_delay_time", &uhub->reset_or_bpwr2_delay_time))
		pr_info("can't get reset_or_bpwr2_delay_time.\n");

	if (of_property_read_u32(np, "hub_1v05_gpio_delay_time", &uhub->hub_1v05_gpio_delay_time))
		pr_info("can't get hub_1v05_gpio_delay_time.\n");

	if (of_property_read_u32(np, "hub_vdd_gpio_delay_time", &uhub->hub_vdd_gpio_delay_time))
		pr_info("can't get hub_vdd_gpio_delay_time.\n");

	if (of_property_read_u32(np, "hub_cam_gpio_delay_time", &uhub->hub_cam_gpio_delay_time))
		pr_info("can't get hub_cam_gpio_delay_time.\n");

	if (of_property_read_u32(np, "hub_net_gpio_delay_time", &uhub->hub_net_gpio_delay_time))
		pr_info("can't get hub_net_gpio_delay_time.\n");

	if (of_property_read_u32(np, "usbnet_reset_time", &uhub->usbnet_reset_time))
		pr_info("can't get usbnet_reset_time.\n");

	if (of_property_read_u32(np, "usb_device_poweron_wait_time", &uhub->usb_device_poweron_wait_time))
		pr_info("can't get usb_device_poweron_wait_time.\n");

	if (of_property_read_u32(np, "poweroff_time", &uhub->poweroff_time))
		pr_info("can't get poweroff_time.\n");

	if (of_property_read_u32(np, "poweron_time", &uhub->poweron_time))
		pr_info("can't get poweron_time\n");

	if (of_property_read_u32(np, "s3_is_off", &uhub->s3_is_off))
		pr_info("can't get s3_is_off.\n");

	if (of_property_read_u32(np, "roothub_num", &uhub->roothub_num)) {
        pr_info("can't get roothub_num\n");
    }
    
	if (of_property_read_u32(np, "hub_num", &uhub->hub_num)) {
        pr_info("can't get hub_num\n");
    }
	
	return 0;
}

static int of_usb_hub_init(struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s pdev is null\n", __func__);
		return -EINVAL;
	}

	int ret;

	ret = of_hub_init_power_gpios(pdev);
	if (ret)
		pr_err("Init power gpios failed, ret = %d\n", ret);

	ret = of_hub_init_power_ec(pdev);
	if (ret)
		pr_err("Init power ec failed: %d, no ec parameters?\n", ret);

	ret = of_hub_init_timing_paras(pdev);
	if (ret)
		pr_err("Init timing paras failed, ret = %d\n", ret);

	return ret;
}

static int usbhub_dev_notify(struct notifier_block *self, unsigned long action, void *dev)
{
	if (self == NULL || dev == NULL) {
		pr_err("%s self or dev is null\n", __func__);
		return -EINVAL;
	}

	int ret = 0;
	struct usb_hub *uhub = container_of(self, struct usb_hub, usbhub_nb);
	if (uhub == NULL) {
		pr_err("%s uhub is null\n", __func__);
		return -EINVAL;
	}

	switch (action) {
    case USB_BUS_ADD:
		if (uhub->notify_bus_add_count <= 0) {
			msleep(S5_HUB_POWEROFF_TIME);

			ret = hw_usb_hub_power_on(uhub);
			if (ret)
				pr_err("usb hub poweron failed: %d\n", ret);

			ret = hw_usb_hub_dereset(uhub);
			if (ret)
				pr_err("usb hub dereset failed: %d\n", ret);

			schedule_delayed_work(&uhub->power_work2, msecs_to_jiffies(S5_HUB_LEVEL2_POWERON_DELAYTIME));
			schedule_delayed_work(&uhub->power_work,
				msecs_to_jiffies(uhub->usb_device_poweron_wait_time));
			uhub->notify_bus_add_count++;
		}
		break;
    case USB_BUS_REMOVE:
		/* fall-through */
    default:
		break;
	}
	return ret;
}

static int hw_usb_hub_pm_notify(struct notifier_block *notify_block,
			  unsigned long mode, void *unused)
{
	pr_info("%s get in", __func__);

	if (g_uhub == NULL) {
		pr_err("g_uhub is null\n");
		return -1;
	}

	switch (mode) {
	case PM_SUSPEND_PREPARE:
		pr_info("%s get in PM_SUSPEND_PREPARE", __func__);
		hw_usb_hub_power_off(g_uhub);
		break;
	case PM_POST_SUSPEND:
		pr_info("%s get in PM_POST_SUSPEND", __func__);
		hw_usb_hub_power_on(g_uhub);
		schedule_delayed_work(&g_uhub->power_work,
			msecs_to_jiffies(g_uhub->usb_device_poweron_wait_time));
		break;
	default:
		break;
	}
	return 0;
}

static struct notifier_block hw_usb_hub_pm_notifier = {
	.notifier_call = hw_usb_hub_pm_notify,
	.priority = INT_MAX,
};

static void hw_usb_hub_syscore_resume(void)
{
	pr_info("%s\n", __func__);
}

static struct syscore_ops hw_usb_hub_syscore_ops = {
	.resume  = hw_usb_hub_syscore_resume,
};

static int usb_hub_probe(struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s pdev is null\n", __func__);
		return -EINVAL;
	}

	int ret;
	struct usb_hub *uhub = NULL;
	struct device_node *node = pdev->dev.of_node;

	pr_info("%s ++\n", __func__);
	uhub = devm_kzalloc(&pdev->dev, sizeof(struct usb_hub), GFP_KERNEL);
	if (uhub == NULL)
		return -ENOMEM;

	uhub->dev = &pdev->dev;
	uhub->usb_device_poweron_wait_time = 0;
	platform_set_drvdata(pdev, uhub);

	ret = of_usb_hub_init(pdev);
	if (ret) {
        pr_err("usb hub init failed: %d\n", ret);
        return ret;
    }

	ret = hw_usb_hub_reset(uhub);
	if (ret)
		pr_err("usb hub reset failed: %d\n", ret);

	ret = hw_usb_hub_power_off(uhub);
	if (ret)
		pr_err("usb hub poweroff failed: %d\n", ret);

	uhub->notify_bus_add_count = 0;
	uhub->usbhub_nb.notifier_call = usbhub_dev_notify;
	usb_register_notify(&uhub->usbhub_nb);

	uhub->notify_roothub_resume_count = 0;
	uhub->roothub_nb.notifier_call = roothub_resume_notify;
	usb_register_notify(&uhub->roothub_nb);

	INIT_DELAYED_WORK(&uhub->power_work, usb_device_poweron_work);
	INIT_DELAYED_WORK(&uhub->power_work2, usb_hub2_poweron_work);

	ret = hub_port_setup_sysfs(uhub);
	if (ret)
		pr_err("setup sysfs failed: %d\n", ret);

	uhub->disable_usbhub_notifier = of_property_read_bool(node, "disable_usbhub_notifier");
	pr_info("disable_usbhub_notifier is %s\n", uhub->disable_usbhub_notifier ? "true" : "false");
	if (!uhub->disable_usbhub_notifier) {
		register_pm_notifier(&hw_usb_hub_pm_notifier);
		register_syscore_ops(&hw_usb_hub_syscore_ops);
	}

	uhub->skip_s4 = of_property_read_bool(node, "skip_s4");
	pr_info("skip_s4 is %s\n", uhub->skip_s4 ? "true" : "false");

	g_uhub = uhub;
	pr_info("%s --\n", __func__);

	return 0;
}

static int usb_hub_remove(struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s pdev is null\n", __func__);
		return -EINVAL;
	}
	pr_info("%s ++\n", __func__);
	struct usb_hub *uhub = platform_get_drvdata(pdev);

	if (uhub == NULL) {
		pr_err("%s uhub is null\n", __func__);
		return -EINVAL;
	}

	usb_unregister_notify(&uhub->usbhub_nb);
	hub_port_destroy_sysfs(pdev);
	if (!uhub->disable_usbhub_notifier)
		unregister_pm_notifier(&hw_usb_hub_pm_notifier);
	cancel_delayed_work(&uhub->power_work);
	cancel_delayed_work(&uhub->power_work2);

	pr_info("%s --\n", __func__);

	return 0;
}

static int usb_hub_pm_suspend(struct device *dev)
{
	if (dev == NULL) {
		pr_err("%s dev is null\n", __func__);
		return -EINVAL;
	}

	int ret;
	struct platform_device *pdev = to_platform_device(dev);
	struct usb_hub *uhub = platform_get_drvdata(pdev);

	if (uhub == NULL)
		return -ENODEV;

	uhub->notify_roothub_resume_count = 0;
    pr_info("notify_roothub_resume_count = %d\n", uhub->notify_roothub_resume_count);

	if (uhub->s3_is_off) {
		pr_info("%s ++\n", __func__);
		ret = hw_usb_hub_reset(uhub);
		if (ret)
			pr_err("usb hub reset failed: %d\n", ret);
		ret = hw_usb_hub_power_off(uhub);
		if (ret)
			pr_err("usb hub poweroff failed: %d\n", ret);
		pr_info("%s --\n", __func__);
	}
	return 0;
}

static int usb_hub_pm_resume(struct device *dev)
{
	if (dev == NULL) {
		pr_err("%s dev is null\n", __func__);
		return -EINVAL;
	}

	int ret;
	struct platform_device *pdev = to_platform_device(dev);
	if (pdev == NULL)
		return -ENODEV;

	struct usb_hub *uhub = platform_get_drvdata(pdev);
	if (uhub == NULL)
		return -ENODEV;

	if (uhub->s3_is_off) {
		pr_info("%s ++\n", __func__);

		ret = hw_usb_hub_power_on(uhub);
		if (ret)
			pr_err("usb hub poweron failed: %d\n", ret);
		ret = hw_usb_hub_dereset(uhub);
		if (ret)
			pr_err("usb hub dereset failed: %d\n", ret);

		ret = hw_usb_hub_level2_power_on(uhub);
		if (ret)
			pr_err("usb hub level2 poweron failed: %d\n", ret);
 
		ret = hw_usb_hub_level2_dereset(uhub);
		if (ret)
			pr_err("usb hub level2 dereset failed: %d\n", ret);

		schedule_delayed_work(&uhub->power_work,
			msecs_to_jiffies(uhub->usb_device_poweron_wait_time));

		pr_info("%s --\n", __func__);
	} else if (uhub->usbnet_reset_time > 0) {
		ret = hw_usb_device_power_off(uhub);
		if (ret)
			pr_err("usb device poweroff failed: %d\n", ret);
		msleep(uhub->usbnet_reset_time);
		ret = hw_usb_device_power_on(uhub);
		if (ret)
			pr_err("usb device poweron failed: %d\n", ret);
	}

	return 0;
}

static int usb_hub_pm_freeze(struct device *dev)
{
	if (dev == NULL) {
		pr_err("%s dev is null\n", __func__);
		return -EINVAL;
	}

	struct platform_device *pdev = to_platform_device(dev);
	if (pdev == NULL) {
        pr_err("%s pdev is null\n", __func__);
        return -ENODEV;
    }
		

	struct usb_hub *uhub = platform_get_drvdata(pdev);
	if (uhub == NULL) {
        pr_err("%s uhub is null\n", __func__);
        return -ENODEV;
    }
		

	uhub->notify_roothub_resume_count = 0;
	pr_info("notify_roothub_resume_count = %d\n", uhub->notify_roothub_resume_count);

	if (uhub->skip_s4)
		return 0;

	return usb_hub_pm_suspend(dev);
}

static int usb_hub_pm_restore(struct device *dev)
{
	if (dev == NULL) {
		pr_err("%s dev is null\n", __func__);
		return -EINVAL;
	}

	struct platform_device *pdev = to_platform_device(dev);
	if (pdev == NULL) {
        pr_err("%s pdev is null\n", __func__);
        return -ENODEV;
    }
		

	struct usb_hub *uhub = platform_get_drvdata(pdev);
	if (uhub == NULL) {
        pr_err("%s uhub is null\n", __func__);
        return -ENODEV;
    }

	if (uhub->skip_s4)
		return 0;

	return usb_hub_pm_resume(dev);
}

static void usb_hub_shutdown(struct platform_device *pdev)
{
	if (pdev == NULL) {
		pr_err("%s pdev is null\n", __func__);
		return;
	}

	pr_info("usb hub shutdown\n");
	struct usb_hub *uhub = platform_get_drvdata(pdev);
	if (uhub == NULL) {
		pr_err("%s uhub is null\n", __func__);
		return;
	}

	if (hw_usb_hub_reset(uhub))
		pr_err("usb hub reset failed\n");
	if (hw_usb_hub_power_off(uhub))
		pr_err("usb hub poweroff failed\n");
}

static const struct dev_pm_ops usb_hub_pm_ops = {
	.suspend = usb_hub_pm_suspend,
	.resume = usb_hub_pm_resume,
	.freeze = usb_hub_pm_freeze,
	.restore = usb_hub_pm_restore,
	.thaw = usb_hub_pm_resume,
	.poweroff = usb_hub_pm_suspend,
};

static const struct of_device_id hw_usb_hub_match[] = {
	{ .compatible = "huawei,hw_usb_hub" },
	{},
};

static struct platform_driver usb_hub_driver = {
	.probe = usb_hub_probe,
	.remove = usb_hub_remove,
	.driver = {
		.name = "hw_usb_hub",
		.owner = THIS_MODULE,
		.pm = &usb_hub_pm_ops,
		.of_match_table = of_match_ptr(hw_usb_hub_match),
	},
	.shutdown = usb_hub_shutdown,
};

static int __init hw_usb_hub_init(void)
{
	return platform_driver_register(&usb_hub_driver);
}

static void __exit hw_usb_hub_exit(void)
{
	platform_driver_unregister(&usb_hub_driver);
}

fs_initcall(hw_usb_hub_init);
module_exit(hw_usb_hub_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei usb hub module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
