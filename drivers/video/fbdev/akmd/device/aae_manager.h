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

#ifndef AKMD_AAE_MANAGER_H
#define AKMD_AAE_MANAGER_H

#include <linux/miscdevice.h>
#include <linux/types.h>
#include <linux/platform_device.h>
#include <linux/semaphore.h>
#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/regulator/consumer.h>

#include "akmd_isr.h"
#include "akmd_pip.h"

typedef union {
	volatile uint64_t status;
	struct {
		uint8_t value[AAE_PIP_MAX];
	} refcount;
} aae_power_status_t;

struct aae_pipeline;

struct aae_manager {
	struct platform_device *pdev;
	struct device_node *parent_node;

	struct regulator *aae_regulator;
	struct regulator *media1_subsys_regulator;
	struct regulator *vivobus_regulator;

	struct mutex tbu_sr_lock;
	struct mutex vote_pw_lock;

	/* Base address register, power supply, clock is public */
	char __iomem *aae_base;
	char __iomem *pctrl_base;
	char __iomem *media1_ctrl_base;
    char __iomem *media1_pmc_base;
	char __iomem *media_lpctrl_apb_base;
	char __iomem *media1_crg_base;
	char __iomem *bisr_ctrl_base;
	char __iomem *actrl_base;

	aae_power_status_t power_status;
	struct semaphore power_sem;
	struct list_head isr_list;
	int32_t glb_irq;
	struct ukmd_isr isr_ctrl;
	int32_t xpu_irq;
	struct ukmd_isr xpu_isr_ctrl;
	uint32_t hardware_reseted;

	struct aae_pipeline_sw *pip_sws[AAE_PIP_MAX];

	atomic_t xpu_aae_power_status;
	int32_t vote_pw_refcount;

#ifdef CONFIG_MDFX_KMD
	/* aae dacc log read */
	struct kthread_work aae_dacc_log_work;
	struct kthread_worker aae_dacc_log_worker;
	struct task_struct *aae_dacc_log_thread;
#endif
};

void register_aae_pipeline(struct aae_pipeline_sw *pip_sw);
void unregister_aae_pipeline(struct aae_pipeline_sw *pip_sw);
void aae_manager_lock_all(void);
void aae_manager_unlock_all(void);
bool is_aae_manager_available(void);
#endif /* AAE_MANAGER_H */
