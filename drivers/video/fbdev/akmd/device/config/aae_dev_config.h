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

#ifndef AAE_DEV_CONFIG_H
#define AAE_DEV_CONFIG_H

#include <linux/types.h>

static inline bool aae_is_smmu_bypass(void)
{
	return false;
}

bool aae_enable_lp_flag(void);

void aae_clock_lp(uint32_t cmdlist_id);
void aae_memory_lp(uint32_t cmdlist_id);
void aae_memory_no_lp(uint32_t cmdlist_id);
void aae_sdma_debug_init(uint32_t cmdlist_id);
void aae_sdma_load_balance_config(char __iomem *aae_base);

uint32_t *aae_config_get_scf_lut_addr_tlb(uint32_t *length);
uint32_t *aae_config_get_arsr_lut_addr_tlb(uint32_t *length);

#endif /* AAE_DEV_CONFIG_H */
