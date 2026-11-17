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

#include "aae_dvfs_config.h"
#include "aae_config_utils.h"
#include "akmd_log.h"

void aae_enable_core_clock(void)
{
	aae_pr_debug("+");

	if (g_aae_config_data.clk_gate_aae == NULL) {
		aae_pr_err("clk_gate_aae is null!");
		return;
	}

	if (clk_prepare_enable(g_aae_config_data.clk_gate_aae) != 0) {
		aae_pr_err("enable clk_gate_aae failed!");
		return;
	}

	aae_pr_debug("-");
}

void aae_disable_core_clock(void)
{
	aae_pr_debug("+");

	if (g_aae_config_data.clk_gate_aae != NULL)
		clk_disable_unprepare(g_aae_config_data.clk_gate_aae);
}

void aae_qos_qic_media1_config(uint32_t level)
{
	void_unused(level);
}

void aae_config_dvfs_vote_exec(uint64_t clk_rate)
{
	int ret = 0;

	if (g_aae_config_data.clk_gate_aae == NULL)
		return;

	ret = clk_set_rate(g_aae_config_data.clk_gate_aae, clk_rate);
	if (ret)
		aae_pr_err("set edc clk rate=%llu failed, error=%d!", clk_rate, ret);

	aae_pr_info("set clk rate = %llu, get clk rate=%llu",
			clk_rate, clk_get_rate(g_aae_config_data.clk_gate_aae));
}

/* qos qic-media1 config should follow dvfs level, after regulater is enabled */
void aae_legacy_dvfs_vote(uint32_t vote_level, bool need_config_qos)
{
	uint32_t clk_rate = aae_config_get_clk_rate(vote_level);

	aae_pr_info("config clk rate=%llu vote_level=%u", clk_rate, vote_level);

	aae_config_dvfs_vote_exec(clk_rate);

	if (need_config_qos)
		aae_qos_qic_media1_config(vote_level);
}