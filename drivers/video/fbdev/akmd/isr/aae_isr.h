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

#ifndef AKMD_AAE_ISR_H
#define AKMD_AAE_ISR_H

#include "akmd_isr.h"

struct aae_manager;

void aae_isr_init(void *parent, struct ukmd_isr *isr_ctrl,
	int32_t irq_no, char *irq_name, uint32_t unmask, irqreturn_t (*isr_fnc)(int32_t, void *));
uint32_t aae_glb_isr_get_unmask(void);
uint32_t aae_xpu_isr_get_unmask(void);

irqreturn_t aae_glb_isr(int32_t irq, void *ptr);
irqreturn_t aae_xpu_isr(int32_t irq, void *ptr);

void aae_glb_isr_enable(struct aae_manager *aae_mgr);
void aae_glb_isr_disable(struct aae_manager *aae_mgr);
#endif /* AAE_ISR_H */
