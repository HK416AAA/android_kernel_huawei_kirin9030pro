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

#ifndef AAE_CONFIG_UTILS_H
#define AAE_CONFIG_UTILS_H

#include <linux/platform_device.h>
#include <linux/types.h>
#include <linux/clk.h>
#include <aae/soc_dpu_define.h>
#include <platform_include/display/akmd/akmd_aae.h>
#include "aksm_debug.h"

#define DTS_OFFLINE_SCENE_ID_MAX 1
struct aae_config {
	union aae_version version;
	char __iomem *ip_base_addrs[AKMD_IP_MAX];
	struct clk *clk_gate_aae;
	uint32_t offline_scene_id_count;
	uint32_t offline_scene_ids[DTS_OFFLINE_SCENE_ID_MAX];
};

extern struct aae_config g_aae_config_data;

int32_t aae_res_init_config(struct platform_device *device);

static inline char __iomem *aae_config_get_ip_base(uint32_t ip)
{
	if (ip >= AKMD_IP_MAX)
		return NULL;

	return g_aae_config_data.ip_base_addrs[ip];
}

uint64_t aae_config_get_clk_rate(uint32_t level);
uint32_t aae_config_get_version(void);
static inline uint32_t aae_config_get_hw_type(void)
{
	return g_aae_config_data.version.info.hw_type;
}

static inline bool aae_is_smmu_bypass(void)
{
	return false;
}

static inline uint32_t* aae_config_get_offline_scene_ids(uint32_t *count)
{
	*count = g_aae_config_data.offline_scene_id_count;
	return g_aae_config_data.offline_scene_ids;
}

#endif /* AAE_CONFIG_UTILS_H */
