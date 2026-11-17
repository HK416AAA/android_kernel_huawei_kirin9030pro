/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_mem_sc.h"

#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/version.h>
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#include <linux/hisi/mm_lb.h>
#else
#include <linux/mm_lb/mm_lb.h>
#endif
#include <linux/highmem.h>

#include "hvgr_mem_sc_hal.h"
#include "hvgr_mem_pool.h"
#include "hvgr_log_api.h"
#include <securec.h>

struct hvgr_mem_pool *hvgr_sc_mem_find_pool(struct list_head *head, uint32_t pool_id)
{
	struct list_head *node = NULL;
	struct hvgr_sc_mem_pool *sc_mem_pool = NULL;

	list_for_each(node, head) {
		sc_mem_pool = container_of(node, struct hvgr_sc_mem_pool, node);
		if (sc_mem_pool->pool_id == pool_id)
			return &sc_mem_pool->pool;
	}

	return NULL;
}

struct hvgr_mem_pool *hvgr_sc_mem_find_pt_pool(struct hvgr_ctx *ctx, uint32_t index)
{
	struct hvgr_mem_pool *pool = NULL;

	if (ctx == NULL)
		return NULL;

	if (ctx->mem_ctx.sc_data.pgd_mem_gid != 0)
		pool = hvgr_sc_mem_find_pool(&ctx->mem_ctx.sc_data.mem_pool_list[index],
			hvgr_policy_id_to_pool_id(ctx->mem_ctx.sc_data.pgd_mem_gid));
	return pool;
}

static void hvgr_sc_mem_deinit_pool(struct list_head *pool_list)
{
	struct hvgr_sc_mem_pool *sc_pool = NULL;
	struct list_head *node = NULL;
	struct list_head *next_node = NULL;

	if (pool_list == NULL)
		return;

	list_for_each_safe(node, next_node, pool_list) {
		sc_pool = container_of(node, struct hvgr_sc_mem_pool, node);
		hvgr_mem_pool_term(&sc_pool->pool);
		list_del_init(&sc_pool->node);
		kfree(sc_pool);
	}
}

static bool hvgr_sc_mem_pool_exist(struct list_head *pool_list, uint32_t pool_id)
{
	struct hvgr_sc_mem_pool *sc_pool = NULL;
	struct list_head *node = NULL;
	struct list_head *next_node = NULL;

	list_for_each_safe(node, next_node, pool_list) {
		sc_pool = container_of(node, struct hvgr_sc_mem_pool, node);
		if (sc_pool->pool_id == pool_id)
			return true;
	}

	return false;
}

static long hvgr_sc_mem_init_pool(void *target, bool is_dev, struct list_head *pool_list,
	uint32_t pool_size, uint32_t flag)
{
	long ret;
	struct hvgr_device *gdev = NULL;
	struct hvgr_ctx *ctx = NULL;
	struct list_head *info_node = NULL;
	const struct hvgr_sc_policy_info *policy_info = NULL;
	struct hvgr_sc_mem_pool *sc_pool = NULL;

	if (is_dev) {
		gdev = (struct hvgr_device *)target;
	} else {
		ctx = (struct hvgr_ctx *)target;
		gdev = ctx->gdev;
	}

	INIT_LIST_HEAD(pool_list);

	list_for_each(info_node, &gdev->mem_dev.sc_data.policy_info_list) {
		policy_info = container_of(info_node, struct hvgr_sc_policy_info, node);
		if (hvgr_sc_mem_pool_exist(pool_list,
			hvgr_policy_id_to_pool_id(policy_info->policy_id)))
			continue;

		sc_pool = kzalloc(sizeof(*sc_pool), GFP_KERNEL);
		if (sc_pool == NULL) {
			hvgr_sc_mem_deinit_pool(pool_list);
			return -ENOMEM;
		}

		if (is_dev) {
#if hvgr_version_ge(300)
			sc_pool->pool.growable = true;
			sc_pool->pool.prefill = false;
#endif
			ret = hvgr_mem_pool_dev_init(gdev, &sc_pool->pool, pool_size, 0);
		} else {
			ret = hvgr_mem_pool_ctx_init(ctx, &sc_pool->pool, pool_size, 0);
		}

		if (ret != 0) {
			kfree(sc_pool);
			hvgr_err(gdev, HVGR_MEM, "policy id %u init mem pool fail",
				policy_info->policy_id);
		} else {
			INIT_LIST_HEAD(&sc_pool->node);
			sc_pool->pool_id = hvgr_policy_id_to_pool_id(policy_info->policy_id);
			sc_pool->pool.pool_id = hvgr_policy_id_to_pool_id(policy_info->policy_id);
			sc_pool->pool.flag = flag;
			sc_pool->pool.pool.pool_id = sc_pool->pool_id;
			list_add(&sc_pool->node, pool_list);
			if (is_dev)
				hvgr_debug(gdev, HVGR_MEM, "%s dev create pool %u by policy %u",
					__func__, sc_pool->pool_id, policy_info->policy_id);
		}
	}

	return 0;
}

static void hvgr_sc_mem_deinit_dev_pool(struct hvgr_device * const gdev, uint32_t num)
{
	uint32_t index;

	for (index = 0; index < num; index++)
		hvgr_sc_mem_deinit_pool(&gdev->mem_dev.sc_data.mem_pool_list[index]);
}

long hvgr_sc_mem_init_dev_pool(struct hvgr_device * const gdev, uint32_t pool_size)
{
	uint32_t index;
	long ret;

	/* 0: NOOSH-BIG 1:NOOSH-LBW 2:OSH-BIG 3:OSH-LBW */
	for (index = 0; index < SC_MEM_POOL_NUM; index++) {
		ret = hvgr_sc_mem_init_pool(gdev, true, &gdev->mem_dev.sc_data.mem_pool_list[index],
			pool_size, index);
		if (ret != 0) {
			hvgr_sc_mem_deinit_dev_pool(gdev, index);
			return -1;
		}
	}

	return 0;
}

void hvgr_sc_mem_deinit_ctx_pool(struct hvgr_ctx *ctx, uint32_t num)
{
	uint32_t index;

	for (index = 0; index < num; index++)
		hvgr_sc_mem_deinit_pool(&ctx->mem_ctx.sc_data.mem_pool_list[index]);
}

long hvgr_sc_mem_init_ctx_pool(struct hvgr_ctx *ctx, uint32_t pool_size)
{
	uint32_t index;
	long ret;

	/* 0: NOOSH-BIG 1:NOOSH-LBW 2:OSH-BIG 3:OSH-LBW */
	for (index = 0; index < SC_MEM_POOL_NUM; index++) {
		ret = hvgr_sc_mem_init_pool(ctx, false, &ctx->mem_ctx.sc_data.mem_pool_list[index],
			pool_size, index);
		if (ret != 0) {
			hvgr_sc_mem_deinit_ctx_pool(ctx, index);
			return -1;
		}
	}

	return 0;
}

void hvgr_sc_mem_init(struct hvgr_device * const gdev)
{
	long ret;

	ret = hvgr_sc_mem_init_dev_pool(gdev, HVGR_MEM_POOL_DEV_SIZE);
	if (ret != 0)
		hvgr_err(gdev, HVGR_MEM, "Init dev sc mem pool fail %d", ret);
}

void hvgr_sc_mem_deinit(struct hvgr_device * const gdev)
{
	hvgr_sc_mem_deinit_dev_pool(gdev, SC_MEM_POOL_NUM);
}

void hvgr_sc_mem_free_page(struct page *page, uint32_t policy_id, uint32_t order)
{
	if (policy_id != 0)
		lb_free_pages(policy_id, page, order);
	else
		__free_pages(page, order);
}

void hvgr_sc_mem_clear_page(struct page *page)
{
#ifdef CONFIG_MM_LB
	if (PageLB(page)) {
		(void)memset_s(lb_page_to_virt(page), PAGE_SIZE, 0x0, PAGE_SIZE);
		return;
	}
#endif
	clear_highpage(page);
}

#ifdef HVGR_FEATURE_SYSTEM_CACHE
/* enable or bypass LB */
void hvgr_enable_sc_lb(struct hvgr_device *gdev, unsigned int enable)
{
	struct list_head *info_node = NULL;
	struct hvgr_sc_policy_info *policy_info = NULL;
	unsigned int pid;

	if (gdev->lb_enable == enable)
		return;

	gdev->lb_enable = enable;
	list_for_each(info_node, &gdev->mem_dev.sc_data.policy_info_list) {
		policy_info = container_of(info_node, struct hvgr_sc_policy_info, node);
		pid = policy_info->policy_id;
		if (enable == 1) {
			hvgr_info(gdev, HVGR_PM, "%s: pid = %u, enable lb\n", __func__, pid);
			lb_gid_enable(pid);
		} else {
			hvgr_info(gdev, HVGR_PM, "%s: pid = %u, bypass lb\n", __func__, pid);
			lb_gid_bypass(pid);
		}
	}
}
#endif /* HVGR_FEATURE_SYSTEM_CACHE */
