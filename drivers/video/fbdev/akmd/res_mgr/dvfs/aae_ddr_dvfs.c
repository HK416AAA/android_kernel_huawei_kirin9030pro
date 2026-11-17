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

#include <linux/device.h>
#include <linux/bits.h>
#include <linux/platform_drivers/platform_qos.h>
#include <securec.h>
#include <aae/soc_aae_define.h>
#include "aae/aae_base_addr.h"
#include "akmd_log.h"
#include "ukmd_utils.h"
#include "aae_res_mgr.h"
#include "aae_config_utils.h"
#include "aae_ddr_dvfs.h"
#include "akmd_res_mgr.h"

static int32_t g_aae_ddr_bandwidth;
static struct platform_qos_request g_aae_qos_req_perf;

static struct aae_bw_vote_node* aae_ddr_find_dvfs_node(struct list_head *vote_bw_list, uint32_t uid)
{
	struct aae_bw_vote_node *node = NULL;
	struct aae_bw_vote_node *_node_ = NULL;

	list_for_each_entry_safe(node, _node_, vote_bw_list, list_node) {
		if (!node)
			continue;

		if (node->uid == uid)
			return node;
	}

	return NULL;
}


static bool find_tgid(struct aae_bw_vote_node *node, int32_t tgid, int32_t *index)
{
	uint32_t i;

	if (node->tgid_cnt == 0) {
		*index = 0;
		return false;
	}

	for (i = 0; i < AAE_DDR_DVFS_TGID_MAX; i++) {
		if (node->user_tgid[i] == tgid) {
			*index = i;
			return true;
		}

		// empty index
		if (node->user_tgid[i] == 0)
			*index = i;
	}
	return false;
}

static bool insert_tgid(struct aae_bw_vote_node *node, int32_t tgid)
{
	int32_t index = AAE_DDR_DVFS_TGID_MAX;

	if (!find_tgid(node, tgid, &index)) {
		if (index >= AAE_DDR_DVFS_TGID_MAX || index < 0) {
			aae_pr_err("[DVFS] insert tgid index is overflow %d", index);
			return false;
		}

		node->user_tgid[index] = tgid;
		++node->tgid_cnt;
		aae_pr_debug("[DVFS] insert tgid %d at index %d", tgid, index);
		return true;
	}
	return false;
}

static bool remove_tgid(struct aae_bw_vote_node *node, int32_t tgid)
{
	int32_t index = AAE_DDR_DVFS_TGID_MAX;

	if (find_tgid(node, tgid, &index)) {
		node->user_tgid[index] = 0;
		--node->tgid_cnt;
		aae_pr_debug("[DVFS] remove tgid %d at index %d", tgid, index);
		return true;
	}
	return false;
}

static uint32_t aae_ddr_get_max_bw(struct list_head *vote_bw_list)
{
	uint32_t max_bw = 0;
	
	struct aae_bw_vote_node *node = NULL;
	struct aae_bw_vote_node *_node_ = NULL;
	list_for_each_entry_safe(node, _node_, vote_bw_list, list_node) {
		if (!node)
			continue;

		max_bw = max_bw > node->bw ? max_bw : node->bw;
	}
	return max_bw;
}

static void aae_ddr_free_dvfs_list(struct list_head *vote_bw_list)
{
	struct aae_bw_vote_node *node = NULL;
	struct aae_bw_vote_node *_node_ = NULL;

	list_for_each_entry_safe(node, _node_, vote_bw_list, list_node) {
		if (!node)
			continue;

		list_del(&node->list_node);
		kfree(node);
		node = NULL;
	}
}

static uint32_t aae_ddr_add_dvfs(struct aae_ddr_bw_mgr *ddr_bw_mgr, void __user *argp)
{
	struct aae_bw_vote_info aae_bw_info = {0};
	struct aae_bw_vote_node *bw_vote_node = NULL;
	int32_t max_bw = 0;

	if (copy_from_user(&aae_bw_info, argp, sizeof(aae_bw_info)) != 0) {
		aae_pr_err("[DVFS] copy from user client types fail");
		return -1;
	}

	down(&ddr_bw_mgr->sem);
	bw_vote_node = aae_ddr_find_dvfs_node(&ddr_bw_mgr->vote_bw_list, aae_bw_info.uid);
	if (!bw_vote_node) {
		bw_vote_node = kzalloc(sizeof(struct aae_bw_vote_node), GFP_KERNEL);
		if (!bw_vote_node) {
			aae_pr_err("[DVFS] kzalloc aae bw node fail");
			up(&ddr_bw_mgr->sem);
			return -1;
		}
		atomic_set(&bw_vote_node->ref_cnt, 0);
		bw_vote_node->uid = aae_bw_info.uid;
		bw_vote_node->bw = aae_bw_info.bw;
		list_add_tail(&bw_vote_node->list_node, &ddr_bw_mgr->vote_bw_list);
	} else {
		bw_vote_node->bw = aae_bw_info.bw;
		aae_pr_debug("[DVFS] update aae bw[%u]", bw_vote_node->bw);
	}

	if (insert_tgid(bw_vote_node, current->tgid)) {
		atomic_inc(&bw_vote_node->ref_cnt);
	}

	max_bw = (int32_t)aae_ddr_get_max_bw(&ddr_bw_mgr->vote_bw_list);
	up(&ddr_bw_mgr->sem);
#ifdef CONFIG_DEVFREQ_GOV_PLATFORM_QOS
	if (g_aae_ddr_bandwidth < max_bw) {
		g_aae_ddr_bandwidth = max_bw;
		platform_qos_update_request(&g_aae_qos_req_perf, g_aae_ddr_bandwidth);
	}
#endif

	aae_pr_debug("[DVFS] aae_bw_info : uid[%u] bw[%lu] g_aae_ddr_bandwidth[%d]",
		aae_bw_info.uid, aae_bw_info.bw, g_aae_ddr_bandwidth);
	return 0;
}

static long aae_ddr_dvfs_ioctl(struct aae_res_resouce_node *res_node, uint32_t cmd, void __user *argp)
{
	struct aae_ddr_bw_mgr *ddr_bw_mgr;
	aae_pr_debug("[DVFS] aae_ddr_dvfs_ioctl +");

	if (!res_node || !res_node->data || !argp) {
		aae_pr_err("[DVFS] res_node or node data or argp is NULL");
		return -EINVAL;
	}

	ddr_bw_mgr = (struct aae_ddr_bw_mgr*)res_node->data;
	switch (cmd) {
		case RES_VOTE_BW:
			return aae_ddr_add_dvfs(ddr_bw_mgr, argp);
		default:
			aae_pr_debug("[DVFS] dvfs unsupport cmd, need processed by other module");
			return 1;
	}
}

static void* aae_ddr_init_dvfs(struct aae_res_data *rm_data)
{
	struct aae_ddr_bw_mgr *ddr_bw_mgr = kzalloc(sizeof(struct aae_ddr_bw_mgr), GFP_KERNEL);

	aae_pr_debug("[DVFS] aae_ddr_init_dvfs +");

	if (ddr_bw_mgr == NULL)
		return NULL;
	sema_init(&ddr_bw_mgr->sem, 1);
	INIT_LIST_HEAD(&ddr_bw_mgr->vote_bw_list);
	aae_pr_debug("[DVFS] aae_ddr_init_dvfs -");

#ifdef CONFIG_DEVFREQ_GOV_PLATFORM_QOS
	platform_qos_add_request(&g_aae_qos_req_perf, PLATFORM_QOS_MEMORY_THROUGHPUT, 0);
#endif
	return ddr_bw_mgr;
}

static void aae_ddr_deinit_dvfs(void *data)
{
	struct aae_ddr_bw_mgr *ddr_bw_mgr = (struct aae_ddr_bw_mgr *)data;

	aae_pr_debug("[DVFS] aae_ddr_deinit_dvfs +");

	if (ddr_bw_mgr == NULL)
		return;

	down(&ddr_bw_mgr->sem);
	aae_ddr_free_dvfs_list(&(ddr_bw_mgr->vote_bw_list));
	up(&ddr_bw_mgr->sem);
	kfree(ddr_bw_mgr);
	ddr_bw_mgr = NULL;
#ifdef CONFIG_DEVFREQ_GOV_PLATFORM_QOS
	g_aae_ddr_bandwidth = 0;
	platform_qos_remove_request(&g_aae_qos_req_perf);
#endif
	aae_pr_debug("[DVFS] aae_ddr_deinit_dvfs -");
}

static void aae_ddr_release_dvfs(void *data, int32_t tgid)
{
	struct aae_ddr_bw_mgr *ddr_bw_mgr = NULL;
	struct aae_bw_vote_node *bw_vote_node = NULL;
	struct aae_bw_vote_node *_node_ = NULL;
	int32_t max_bw = 0;

	aae_pr_debug("[DVFS] aae_ddr_release_dvfs +");
	void_unused(tgid);
	ddr_bw_mgr = (struct aae_ddr_bw_mgr *)data;
	if (!ddr_bw_mgr)
		return;

	down(&ddr_bw_mgr->sem);
	list_for_each_entry_safe(bw_vote_node, _node_, &ddr_bw_mgr->vote_bw_list, list_node) {
		if (!bw_vote_node)
			continue;

		if (!remove_tgid(bw_vote_node, current->tgid)) {
			aae_pr_debug("[DVFS] remove tgid fail tgid[%d]", current->tgid);
			continue;
		}

		if (atomic_dec_and_test(&bw_vote_node->ref_cnt)) {
			aae_pr_debug("[DVFS] remove node[%d]", bw_vote_node->uid);
			list_del(&bw_vote_node->list_node);
			kfree(bw_vote_node);
			bw_vote_node = NULL;
		}
	}
	max_bw = (int32_t)aae_ddr_get_max_bw(&ddr_bw_mgr->vote_bw_list);
	up(&ddr_bw_mgr->sem);

#ifdef CONFIG_DEVFREQ_GOV_PLATFORM_QOS
	g_aae_ddr_bandwidth = max_bw;
	platform_qos_update_request(&g_aae_qos_req_perf, g_aae_ddr_bandwidth);

#endif
}

void aae_res_register_ddr_dvfs(struct list_head *res_head)
{
	struct aae_res_resouce_node *dvfs_node = NULL;
	aae_pr_debug("[DVFS] aae_res_register_ddr_dvfs +");

	aae_assert(!res_head);

	dvfs_node = kzalloc(sizeof(*dvfs_node), GFP_KERNEL);
	if (unlikely(!dvfs_node))
		return;

	dvfs_node->res_type = RES_DVFS;
	dvfs_node->init = aae_ddr_init_dvfs;
	dvfs_node->deinit = aae_ddr_deinit_dvfs;
	dvfs_node->ioctl = aae_ddr_dvfs_ioctl;
	dvfs_node->release = aae_ddr_release_dvfs;

	list_add_tail(&dvfs_node->list_node, res_head);
	aae_pr_debug("[DVFS] aae_res_register_ddr_dvfs -");
}

