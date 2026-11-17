/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef TASK_BINDER_H
#define TASK_BINDER_H

#include <linux/types.h>
#include <linux/list.h>
#include <linux/platform_device.h>
#include <linux/semaphore.h>
#include <linux/regulator/consumer.h>

#define BIND_ID_USER_TGID_MAX 16

struct mm_svm;
struct aae_binder_info_node {
	int32_t user_tgid;
	uint16_t user_ssid;
	uint16_t reserved; /* for memory alignment */
	int32_t ref_cnt;
	struct mm_svm *aae_svm;
	struct list_head info_head;
};

struct aae_task_binder {
	struct platform_device *pdev;
	struct semaphore sem;
	struct list_head task_info_head;
	uint16_t list_len;

	struct workqueue_struct *tcu_poweroff_wq;
	struct work_struct tcu_poweroff_work;
};

void aae_res_register_task_binder(struct list_head *resource_head);

#endif