/*
 * echub/hmi_private.h
 *
 * echub hmi function interface & definition
 *
 * Copyright (c) 2018-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef _ARMPC_HMI_PRIVATE
#define _ARMPC_HMI_PRIVATE

#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/init.h>
#include "ospm_printf.h"
#include "echub_i2c.h"

#define MAX_EVENT_LEN 256
struct hmi_dev {
	struct device *dev;
	struct echub_i2c_dev *echub;
	int qevent_gpio;
	int qevent_irq;
	bool gpio_irq_wakeup;
	u8  qid_nid_map[MAX_EVENT_LEN];  /* value is event type */
	struct notifier_block hibernate_nb;
	struct delayed_work get_event_work;
	struct mutex lock;
};

struct hmi_dev *get_hmi_dev(void);
int hmi_init_qevent(struct platform_device *pdev, struct hmi_dev *echmi);

#endif /* ARMPC_HMI_PRIVATE */