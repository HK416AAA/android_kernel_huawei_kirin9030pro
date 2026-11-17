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

#ifndef AKMD_AAE_DVFS_CONFIG_H
#define AKMD_AAE_DVFS_CONFIG_H

#include <linux/types.h>

void aae_enable_core_clock(void);
void aae_disable_core_clock(void);
uint32_t aae_config_get_clk_level(uint64_t freq);
void aae_qos_qic_media1_config(uint32_t level);
void aae_legacy_dvfs_vote(uint32_t vote_level, bool need_config_qos);
void aae_config_dvfs_vote_exec(uint64_t clk_rate);

#endif /* AAE_DVFS_CONFIG_H */