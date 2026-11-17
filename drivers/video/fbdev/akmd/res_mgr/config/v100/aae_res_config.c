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

#include <linux/kernel.h>
#include <platform_include/display/akmd/akmd_aae.h>
#include <aae/soc_dpu_define.h>
#include "aae_config_utils.h"
#include "aae_dvfs_config.h"

static uint64_t s_aae_clk_rate_tbl[] = {
	AAE_CLK_FREQ_OFF, /* L0_POWER_OFF */
	AAE_CLK_FREQ0, /* L1_060V CDC CDC_ACE not support */
	AAE_CLK_FREQ1, /* L2_070V */
	AAE_CLK_FREQ2, /* L3_080V */
	AAE_CLK_FREQ3  /* L4_090V */
};

uint32_t aae_config_get_clk_level(uint64_t freq)
{
	uint32_t i;
	/* AAE_CLK_LEVEL_ON means L1_060V */
	for (i = AAE_CLK_LEVEL_ON; i <= AAE_CLK_LEVEL_MAX; ++i) {
		if (freq <= s_aae_clk_rate_tbl[i])
			return i;
	}
	return AAE_CLK_LEVEL_MAX;
}

uint64_t aae_config_get_clk_rate(uint32_t level)
{
	if (level >= ARRAY_SIZE(s_aae_clk_rate_tbl))
		return s_aae_clk_rate_tbl[AAE_CLK_LEVEL_MAX];

	return s_aae_clk_rate_tbl[level];
}

uint32_t aae_config_get_version(void)
{
	return AAE_ACCEL_V100;
}