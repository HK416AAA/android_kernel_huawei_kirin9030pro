/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/kernel.h>
#include <linux/rbtree.h>
#include <securec.h>

#include "hvgr_defs.h"
#include "hvgr_memory_data.h"
#include "hvgr_log_api.h"

static bool hvgr_dfx_find_pa_in_area(struct hvgr_mem_area *area, uint64_t pa)
{
	size_t i;

	if (unlikely(area->page_array == NULL))
		return false;

	for (i = 0; i < area->pages; i++) {
		if ((uint64_t)page_to_phys(area->page_array[i]) == pa)
			return true;
	}

	return false;
}

void hvgr_dfx_find_pa_in_ctx(struct hvgr_ctx *ctx, uint64_t align_pa)
{
	struct hvgr_mem_area *area = NULL;
	struct hvgr_kv_map *map = NULL;
	struct rb_root *rbtree = NULL;
	struct rb_node *rbnode = NULL;
	struct hvgr_kv_node *kvnode = NULL;
	char process_info[HVGR_PROCESS_DATA_LEN] = {0};

	hvgr_get_process_info(process_info, HVGR_PROCESS_DATA_LEN, ctx);
 	hvgr_debug(ctx->gdev, HVGR_DM, "ctx_%u pid: %d find pa start", ctx->id, ctx->pid);
	mutex_lock(&ctx->mem_ctx.area_mutex);
	map = &ctx->mem_ctx.area_rec;
	rbtree = &map->root;
	rbnode = rb_first(rbtree);

	while (rbnode) {
		kvnode = rb_entry(rbnode, struct hvgr_kv_node, node);
		area = container_of(kvnode, struct hvgr_mem_area, node);

		if (hvgr_dfx_find_pa_in_area(area, align_pa)) {
			hvgr_debug(ctx->gdev, HVGR_DM, "find pa 0x%lx in ctx_%u %s, prop %lx,"
				" attr 0x%lx, pages: %lu/%lu, gva: %pK",
				align_pa, ctx->id, process_info, area->property, area->attribute,
				area->pages, area->max_pages, (void *)area->gva);

			break;
		}

		rbnode = rb_next(rbnode);
	}

	mutex_unlock(&ctx->mem_ctx.area_mutex);
	hvgr_debug(ctx->gdev, HVGR_DM, "ctx_%u pid: %d find pa end", ctx->id, ctx->pid);
}

void hvgr_dfx_show_pa(struct hvgr_device *gdev, uint64_t pa)
{
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx_tmp = NULL;
	uint64_t align_pa = pa & 0xffffffffffff0000ULL;

	if (unlikely(gdev == NULL))
		return;

	hvgr_debug(gdev, HVGR_DM, "show pa:0x%lx, align:0x%lx", pa, align_pa);
	mutex_lock(&gdev->dm_dev.ctx_list_mutex);
	list_for_each_entry_safe(ctx_tmp, tmp, &gdev->dm_dev.ctx_list, dev_link) {
		if (unlikely(ctx_tmp == NULL))
			continue;

		hvgr_dfx_find_pa_in_ctx(ctx_tmp, align_pa);
	}
	mutex_unlock(&gdev->dm_dev.ctx_list_mutex);

	return;
}
