/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mem_debugfs.h"

#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/seq_file.h>
#include <securec.h>

#include "hvgr_debugfs_api.h"
#include "hvgr_dm_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_log_api.h"
#ifdef HVGR_FEATURE_SYSTEM_CACHE
#include "hvgr_mem_sc.h"
#endif

#define HVGR_MEM_PROFILE_MAX_SIZE ((64 + ((80 + (56 * 64)) * 3 * 15) + (56 * 6)))

static void hvgr_mem_get_jit_total_pages(struct hvgr_ctx *ctx, uint64_t *using,
	uint64_t *pool, uint64_t *using_cnt, uint64_t *pool_cnt)
{
	struct hvgr_mem_area *iter = NULL;
	struct hvgr_mem_area *temp = NULL;

	mutex_lock(&ctx->mem_ctx.jit_shrink_mutex);
	list_for_each_entry_safe(iter, temp, &ctx->mem_ctx.jit_pool_head, jit_node) {
		(*pool) += iter->pages;
		(*pool_cnt)++;
	}

	list_for_each_entry_safe(iter, temp, &ctx->mem_ctx.jit_using_head, jit_node) {
		(*using) += iter->pages;
		(*using_cnt)++;
	}

	mutex_unlock(&ctx->mem_ctx.jit_shrink_mutex);
}

struct hvgr_mem_usage_stat {
	uint64_t summary;
	uint64_t grow;
	uint64_t pt;
	uint64_t kmd;
	uint64_t jit_using;
	uint64_t jit_pool;
	uint64_t jit_using_cnt;
	uint64_t jit_pool_cnt;
	int map_a_cnt;
	int map_m_cnt;
	int map_i_cnt;
};

static void hvgr_mem_get_used_memory_statistic(struct hvgr_ctx *ctx,
	struct hvgr_mem_usage_stat *used)
{
	used->summary = ((uint64_t)hvgr_mem_get_ctx_using_page(ctx)) * PAGE_SIZE;
	used->grow = ((uint64_t)atomic_read(&(ctx->mem_ctx.used_grow_pages))) * PAGE_SIZE;
	used->pt = ((uint64_t)atomic_read(&(ctx->mem_ctx.used_pt_pages))) * PAGE_SIZE;
	used->kmd = ((uint64_t)atomic_read(&(ctx->mem_ctx.used_kmd_pages))) * PAGE_SIZE;
	used->map_a_cnt = atomic_read(&(ctx->mem_ctx.map_a_cnt));
	used->map_m_cnt = atomic_read(&(ctx->mem_ctx.map_m_cnt));
	used->map_i_cnt = atomic_read(&(ctx->mem_ctx.map_i_cnt));

	used->jit_using = 0U;
	used->jit_pool = 0U;
	used->jit_using_cnt = 0U;
	used->jit_pool_cnt = 0U;
	hvgr_mem_get_jit_total_pages(ctx, &used->jit_using, &used->jit_pool, &used->jit_using_cnt,
		&used->jit_pool_cnt);
	used->jit_using *= PAGE_SIZE;
	used->jit_pool *= PAGE_SIZE;
}


long hvgr_mem_add_profile(struct hvgr_ctx * const ctx, uint64_t user_buf, uint64_t size)
{
	char *kbuf = NULL;

	if (unlikely(user_buf == 0 || size == 0 || size > HVGR_MEM_PROFILE_MAX_SIZE)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mem profile size %lu addr 0x%lx error",
			size, user_buf);
		return -EINVAL;
	}

	kbuf = kvzalloc(size + 1, GFP_KERNEL);
	if (kbuf == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mem profile malloc fail");
		return -ENOMEM;
	}

	if (copy_from_user(kbuf, u64_to_user_ptr(user_buf), size) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mem profile copy from user fail");
		kvfree(kbuf);
		return -EFAULT;
	}

	kbuf[size] = '\0';
	if (unlikely((uint64_t)strlen(kbuf) != size)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mem profile buffer len %lu and size %lu not match",
			(uint64_t)strlen(kbuf), size);
		kvfree(kbuf);
		return -EINVAL;
	}

	mutex_lock(&ctx->mem_ctx.profile_mutex);

	if (ctx->mem_profile_buf != NULL)
		kvfree(ctx->mem_profile_buf);

	ctx->mem_profile_buf = kbuf;
	ctx->mem_profile_size = size;

	mutex_unlock(&ctx->mem_ctx.profile_mutex);
	return 0;
}

void hvgr_mem_remove_profile(struct hvgr_ctx * const ctx)
{
	mutex_lock(&ctx->mem_ctx.profile_mutex);

	if (ctx->mem_profile_buf != NULL)
		kvfree(ctx->mem_profile_buf);

	ctx->mem_profile_buf = NULL;
	ctx->mem_profile_size = 0;
	mutex_unlock(&ctx->mem_ctx.profile_mutex);
}

static void hvgr_mem_show_profile_buffer(struct hvgr_ctx *ctx)
{
	pr_err("%.*s\n", (int)ctx->mem_profile_size, ctx->mem_profile_buf);
}

static void hvgr_mem_profile_kmsg(struct hvgr_ctx *ctx, struct hvgr_mem_usage_stat *used)
{
	pr_err("ctx_%u %10d %10d used summary:%llu grow:%llu driver:%llu kmd:%llu jit:%llu map:%d %d %d\n",
		ctx->id, ctx->pid, ctx->tgid,
		used->summary, used->grow, used->pt + used->kmd, used->kmd, used->jit_using,
		used->map_a_cnt, used->map_m_cnt, used->map_i_cnt);

	if (ctx->mem_profile_buf == NULL)
		return;

	hvgr_mem_show_profile_buffer(ctx);
}

#ifdef HVGR_FEATURE_SYSTEM_CACHE
uint32_t hvgr_mem_get_sc_pool_pages(struct list_head *pool_list)
{
	struct hvgr_sc_mem_pool *sc_pool = NULL;
	struct list_head *node = NULL;
	struct list_head *next_node = NULL;
	uint32_t pages = 0U;

	if (pool_list == NULL)
		return 0U;

	list_for_each_safe(node, next_node, pool_list) {
		sc_pool = container_of(node, struct hvgr_sc_mem_pool, node);
		pages += sc_pool->pool.pool.cur_size;
	}

	return pages;
}
#endif

int hvgr_mem_profile_all_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *dev = hvgr_get_device();
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_pool *pool = NULL;
	struct hvgr_mem_dev *mem_dev = NULL;
	struct hvgr_mem_usage_stat used = {0};
	uint32_t pool_pages = 0;
	uint32_t dev_pool_pages = 0;
	uint32_t i;
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	struct common_mcu *mcu_data = &dev->dm_dev.mcu_data;
#endif

	if (unlikely(dev == NULL))
		return -EINVAL;

	mutex_lock(&dev->dm_dev.ctx_list_mutex);
	list_for_each_entry_safe(ctx, tmp, &dev->dm_dev.ctx_list, dev_link) {
		mutex_lock(&ctx->mem_ctx.profile_mutex);
		hvgr_mem_get_used_memory_statistic(ctx, &used);
		if (sfile != NULL) {
			seq_printf(sfile,
				"ctx_%u %10d %10d used summary:%llu grow:%llu "
				"driver:%llu kmd:%llu jit:%llu map:%d %d %d\n",
				ctx->id, ctx->pid, ctx->tgid, used.summary, used.grow,
				used.pt + used.kmd, used.kmd, used.jit_using, used.map_a_cnt,
				used.map_m_cnt, used.map_i_cnt);
			if (ctx->mem_profile_buf != NULL) {
				seq_write(sfile, ctx->mem_profile_buf,
					(size_t)ctx->mem_profile_size);
				seq_printf(sfile, "%s", "\n");
			}
		} else {
			hvgr_mem_profile_kmsg(ctx, &used);
		}
		mutex_unlock(&ctx->mem_ctx.profile_mutex);
		for (i = 0; i < MEM_POOL_NUM; i++) {
			pool = &ctx->mem_ctx.mem_pool[i].pool;
			pool_pages += pool->cur_size;
		}

#ifdef HVGR_FEATURE_SYSTEM_CACHE
		for (i = 0; i < SC_MEM_POOL_NUM; i++)
			pool_pages +=
				hvgr_mem_get_sc_pool_pages(&ctx->mem_ctx.sc_data.mem_pool_list[i]);
#endif
	}
	mutex_unlock(&dev->dm_dev.ctx_list_mutex);

	mem_dev = &dev->mem_dev;
	for (i = 0; i < MEM_POOL_NUM; i++) {
		pool = &mem_dev->mem_pool[i].pool;
		dev_pool_pages += pool->cur_size;
	}
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	for (i = 0; i < SC_MEM_POOL_NUM; i++)
		dev_pool_pages +=
			hvgr_mem_get_sc_pool_pages(&mem_dev->sc_data.mem_pool_list[i]);
#endif

	if (sfile != NULL)
		seq_printf(sfile, "pool pages:%u %u\n", dev_pool_pages, pool_pages);
	else
		pr_err("pool pages:%u %u\n", dev_pool_pages, pool_pages);
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	if (sfile != NULL)
		seq_printf(sfile, "kmd-mcu pages %u\n", mcu_data->alloc_page_size);
	else
		pr_err("kmd-mcu pages %u\n", mcu_data->alloc_page_size);
#endif

	return 0;
}



