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

#include <linux/delay.h>
#include <linux/list.h>
#include <linux/slab.h>
#include "aae_res_mgr.h"
#include "aae_dvfs.h"
#include "akmd_log.h"
#include "ukmd_utils.h"
#include "aae_config_utils.h"
#include "aae_dvfs_config.h"

#define PERF_INIT_VALUE 0xFFFF
#define DVFS_PMCTRL_PERI_CTRL4_TEMPERATURE_MASK GENMASK(27, 26)
#define DVFS_PMCTRL_PERI_CTRL4_TEMPERATURE_SHIFT 26
#define DVFS_MIDIA_PERI_CTRL4 0x350

// g_aae_dvfs_mgr protected by sem lock in dvfs.c
struct aae_dvfs *g_aae_dvfs_mgr = NULL;

uint32_t aae_dvfs_check_low_temperature(void)
{
	uint32_t perictrl4;
	char __iomem *pmctrl_base = aae_config_get_ip_base(AKMD_IP_BASE_PMCTRL);

	aae_check_and_return(!pmctrl_base, false, err, "pmctrl_base is NULL!");

	perictrl4 = inp32(pmctrl_base + DVFS_MIDIA_PERI_CTRL4);
	perictrl4 &= DVFS_PMCTRL_PERI_CTRL4_TEMPERATURE_MASK;
	perictrl4 = (perictrl4 >> DVFS_PMCTRL_PERI_CTRL4_TEMPERATURE_SHIFT);
	aae_pr_debug("Get current temperature: %d", perictrl4);
	return perictrl4;
}

static uint32_t aae_dvfs_get_vote_level(void)
{
	uint32_t i = 0;
	uint32_t voted_level = 0;
	uint32_t max_voted_level = 0;

	for (; i < AAE_PIP_MAX; ++i) {
		voted_level = g_aae_dvfs_mgr->pip_voted_level[i];
		aae_pr_debug("voted_level=%u max_voted_level=%u", voted_level, max_voted_level);
		max_voted_level = voted_level > max_voted_level ? voted_level : max_voted_level;
	}

	return max_voted_level;
}

void aae_dvfs_vote_level(uint32_t pip_index, uint32_t perf_level,
	bool need_config_qos, bool direct_vote)
{
	uint32_t i = 0;
	uint32_t vote_level = 0;
	
	aae_pr_debug("+");

	aae_check_and_no_retval((pip_index > AAE_PIP_MAX), err, "pip_index=%u is out of range!", pip_index);
	aae_check_and_no_retval((vote_level > AAE_CLK_LEVEL_MAX), err, "don't support perf level=%u!", perf_level);

	g_aae_dvfs_mgr->pip_voted_level[pip_index] = perf_level;

	if (perf_level != AAE_CLK_LEVEL_OFF) {
		if (g_debug_aae_perf_level == 0 || g_debug_aae_perf_level > AAE_CLK_LEVEL_MAX)
			vote_level = direct_vote ? perf_level : aae_dvfs_get_vote_level();
		else
			vote_level = g_debug_aae_perf_level;
	} else {
		for (; i < (uint32_t)AAE_PIP_MAX; ++i)
			g_aae_dvfs_mgr->pip_voted_level[i] = AAE_CLK_LEVEL_OFF;
		vote_level = AAE_CLK_LEVEL_OFF;
	}

	if (vote_level == g_aae_dvfs_mgr->voted_level)
		return;

	aae_legacy_dvfs_vote(vote_level, need_config_qos);

	g_aae_dvfs_mgr->voted_level = vote_level;

	aae_pr_debug("-");
}

void aae_dvfs_enable_core_clock(void)
{
	aae_pr_debug("+");

	if (unlikely(g_aae_dvfs_mgr == NULL)) {
		aae_pr_err("g_aae_dvfs_mgr is NULL");
		return;
	}

	down(&g_aae_dvfs_mgr->sem);

	aae_enable_core_clock();

	up(&g_aae_dvfs_mgr->sem);

	aae_pr_debug("-");
	return;
}

void aae_dvfs_disable_core_clock(void)
{
	aae_pr_debug("+");

	if (unlikely(g_aae_dvfs_mgr == NULL)) {
		aae_pr_err("g_aae_dvfs_mgr is NULL");
		return;
	}

	down(&g_aae_dvfs_mgr->sem);
	aae_disable_core_clock();
	up(&g_aae_dvfs_mgr->sem);

	aae_pr_debug("-");
}

void aae_dvfs_qos_qic_media1_config(uint32_t level)
{
	aae_qos_qic_media1_config(level);
}

static void* dvfs_init(struct aae_res_data *rm_data)
{
	struct aae_dvfs *dvfs_mgr = NULL;

	aae_check_and_return(!rm_data, NULL, err, "res_data is nullptr!");
	dvfs_mgr = (struct aae_dvfs *)kzalloc(sizeof(*dvfs_mgr), GFP_KERNEL);
	aae_check_and_return(!dvfs_mgr, NULL, err, "dvfs_mgr alloc failed!");

	sema_init(&dvfs_mgr->sem, 1);
	dvfs_mgr->voted_level = PERF_INIT_VALUE;
	g_aae_dvfs_mgr = dvfs_mgr;

	return dvfs_mgr;
}

static void dvfs_deinit(void *dvfs)
{
	struct aae_dvfs *dvfs_mgr = (struct aae_dvfs *)dvfs;

	aae_check_and_no_retval(!dvfs_mgr, err, "dvfs_mgr is nullptr!");
	kfree(dvfs_mgr);
	g_aae_dvfs_mgr = NULL;
	dvfs = NULL;
}

void aae_res_register_dvfs(struct list_head *res_head)
{
	struct aae_res_resouce_node *dvfs_node = NULL;

	aae_assert(!res_head);

	dvfs_node = kzalloc(sizeof(*dvfs_node), GFP_KERNEL);
	if (unlikely(!dvfs_node))
		return;

	dvfs_node->res_type = RES_DVFS;
	dvfs_node->init = dvfs_init;
	dvfs_node->deinit = dvfs_deinit;
	dvfs_node->ioctl = NULL;

	list_add_tail(&dvfs_node->list_node, res_head);
}
