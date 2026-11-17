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

#ifndef AKMD_AAE_DVFS_H
#define AKMD_AAE_DVFS_H

#include <linux/types.h>
#include <linux/semaphore.h>
#include <platform_include/display/akmd/akmd_aae.h>
#include "akmd_pip.h"

struct aae_dvfs {
	struct semaphore sem;
	uint32_t voted_level; // record last perf level
	uint32_t pip_voted_level[AAE_PIP_MAX];
};

void aae_res_register_dvfs(struct list_head *res_head);
void aae_dvfs_enable_core_clock(void);
void aae_dvfs_disable_core_clock(void);
void aae_dvfs_vote_level(uint32_t pip_index, uint32_t perf_level,
	bool need_config_qos, bool direct_vote);
void aae_dvfs_qos_qic_media1_config(uint32_t level);

#endif
