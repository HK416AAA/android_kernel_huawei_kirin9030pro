/*
 * qevent.c
 *
 * hmi qevent driver for echub
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
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/jiffies.h>
#include <linux/kobject.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <asm/irq.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include "hmi_private.h"
#include "hmi.h"
#include "ospm_printf.h"

static const char * const g_hmi_event_table[HMI_EVENT_END] = {
	[HMI_KEYBOARD_EVENT] = "keyboard_event",
	[HMI_PD_EVENT] = "pd_event",
	[HMI_BATTERY_EVENT] = "battery_event",
	[HMI_WAKEUP_EVENT ] = "wakeup_event",
};

#define QUEUE_COUNT_CLEAR 0
static atomic_t work_queue_count = ATOMIC_INIT(QUEUE_COUNT_CLEAR);
static struct blocking_notifier_head g_hmi_event_bnh[HMI_EVENT_END];

static const char *hmi_get_event_name(unsigned int event)
{
	if (event < HMI_EVENT_END)
		return g_hmi_event_table[event];

	return "hmi event type error.\n";
}

static int __init hmi_event_bnh_init(void)
{
	int i;

	for (i = 0; i < HMI_EVENT_END; i++)
		BLOCKING_INIT_NOTIFIER_HEAD(&g_hmi_event_bnh[i]);
	echub_info("hmi_event_bnh_init done.\n");
	return 0;
}

module_init(hmi_event_bnh_init);

int hmi_event_bnc_register(unsigned int type, struct notifier_block *nb)
{
	if (type >= HMI_EVENT_END) {
		echub_err("invalid type=%u\n", type);
		return -EINVAL;
	}
	if (!nb) {
		echub_err("nb is null\n");
		return -EINVAL;
	}
	echub_info("hmi_event_bnc_register type = %u\n", type);
	return blocking_notifier_chain_register(&g_hmi_event_bnh[type], nb);
}

int hmi_event_bnc_unregister(unsigned int type, struct notifier_block *nb)
{
	if (type >= HMI_EVENT_END) {
		echub_err("invalid type=%u\n", type);
		return NOTIFY_OK;
	}
	if (!nb) {
		echub_err("nb is null\n");
		return NOTIFY_OK;
	}
	echub_info("hmi_event_bnc_unregister type = %u\n", type);
	return blocking_notifier_chain_unregister(&g_hmi_event_bnh[type], nb);
}

static void hmi_event_bnc_notify(unsigned int type, unsigned long event, void *data)
{
	if (type >= HMI_EVENT_END) {
		echub_err("invalid type=%u\n", type);
		return;
	}
	echub_info("receive blocking event type=%u event=%lu,%s\n",
		type, event, hmi_get_event_name(type));
	blocking_notifier_call_chain(&g_hmi_event_bnh[type], event, data);
}

static void hw_echmi_event_work(struct work_struct *work)
{
	int ret;
	struct hmi_dev *echmi = get_hmi_dev();
	u8 event_id;

	if (!echmi) {
		echub_err("[%s:%dL] echmi is null\n", __func__, __LINE__);
		return;
	}
	ret = hmi_transfer(GET_EC_QEVENT_ID, NULL, 0, &event_id, 1);
	if (ret) {
		echub_err("hmi get event failed, ret = %d.\n", ret);
	} else {
		echub_info("hmi get a event %d.\n", event_id);
		if ((echmi->qid_nid_map[event_id]) != 0) {
			hmi_event_bnc_notify(echmi->qid_nid_map[event_id], event_id, NULL);
		} else {
			echub_err("hmi get a unsupported event %d.\n", event_id);
		}
	}
	atomic_dec(&work_queue_count); /* if transfer error try again */
}

static irqreturn_t hw_hmi_qevent_irq_handler(int irq, void *dev_id)
{
	struct hmi_dev *echmi = NULL;
	int queue_count;

	echmi = get_hmi_dev();
	if (echmi == NULL) {
		return -ENODEV;
	}
	echub_debug("hmi qevent handler entry.\n");
	queue_count = atomic_read(&work_queue_count);
	if (queue_count == 0) {
		schedule_delayed_work(&echmi->get_event_work, msecs_to_jiffies(0));
		atomic_inc(&work_queue_count);
	}

	return IRQ_HANDLED;
}

int hmi_init_qevent(struct platform_device *pdev, struct hmi_dev *echmi)
{
	int err;

	if (pdev == NULL || echmi == NULL) {
		return -EINVAL;
	}

	INIT_DELAYED_WORK(&echmi->get_event_work, hw_echmi_event_work);

	echmi->qevent_gpio = of_get_named_gpio(pdev->dev.of_node, "qevent_gpio", 0);
	if (echmi->qevent_gpio < 0) {
		echub_err("Get qevent gpio failed\n");
		return -EINVAL;
	}
	if (!gpio_is_valid(echmi->qevent_gpio)) {
		echub_err("%s: gpio of qevent is not valid, check DTS\n", __func__);
		return -EINVAL;
	}
	err = devm_gpio_request(&pdev->dev, (unsigned int)echmi->qevent_gpio, "qevent_gpio");
	if (err < 0) {
		echub_err("Fail request gpio:%d\n", echmi->qevent_gpio);
		return err;
	}
	err = gpio_direction_input((unsigned int)echmi->qevent_gpio);
	if (err < 0) {
		echub_err("Failed to set qevent_gpio directoin!\n");
		return -EFAULT;
	}
	echmi->qevent_irq = gpio_to_irq((unsigned int)echmi->qevent_gpio);
	if (echmi->qevent_irq < 0) {
		echub_err("Failed to get gpio key press irq!\n");
		return -EFAULT;
	}
    if (of_property_read_bool(pdev->dev.of_node, "gpio_irq_wakeup")) {
		err = request_irq(echmi->qevent_irq, hw_hmi_qevent_irq_handler,
			IRQF_TRIGGER_FALLING | IRQF_NO_SUSPEND, "hmi_qevent", echmi);
	} else {
		err = request_irq(echmi->qevent_irq, hw_hmi_qevent_irq_handler,
			IRQF_TRIGGER_FALLING, "hmi_qevent", echmi);
	}
	if (err) {
		echub_err("Failed to request hmi interupt handler!\n");
		return -EFAULT;
	}
	echub_info("hmi init qevent success!\n");

	return 0;
}