/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mem_api.h"

#include <linux/mm.h>
#include <linux/dma-buf.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#ifdef HVGR_FEATURE_SYSTEM_CACHE
#include "hvgr_sc_api.h"
#endif

#include "hvgr_ioctl_mem.h"
#include "hvgr_mem_zone.h"
#include "hvgr_dm_api.h"
#include "hvgr_mem_alias.h"
#include "hvgr_mem_sparse.h"
#include "hvgr_mem_debugfs.h"
#include "hvgr_mem_import.h"
#include "hvgr_mem_opts.h"
#include "hvgr_mem_gpu.h"
#include "hvgr_mem_4gva.h"
#include "hvgr_kv.h"
#include "hvgr_log_api.h"
#include <securec.h>

static bool hvgr_mem_ioctl_alloc_para_is_valid(struct hvgr_ctx * const ctx, uint64_t property,
	uint64_t attr)
{
	/* Check the INVALID property from UMD */
	if ((!hvgr_ctx_flag(ctx, HVGR_CTX_FLAG_COMPAT) && property == HVGR_MEM_PROPERTY_GPU_MEM) ||
		(property == HVGR_MEM_PROPERTY_JIT) ||
		(property == HVGR_MEM_PROPERTY_DRIVER) ||
		(property == HVGR_MEM_PROPERTY_ALIAS) ||
		(property == HVGR_MEM_PROPERTY_IMPORT) ||
		((attr & HVGR_MEM_ATTR_KMD_ACCESS) != 0))
		return false;

	return true;
}

static bool hvgr_mem_ioctl_para_is_valid(struct hvgr_ctx * const ctx, uint64_t property)
{
	/* Check the INVALID property from UMD */
	if ((!hvgr_ctx_flag(ctx, HVGR_CTX_FLAG_COMPAT) && property == HVGR_MEM_PROPERTY_GPU_MEM) ||
		(property == HVGR_MEM_PROPERTY_JIT) ||
		(property == HVGR_MEM_PROPERTY_DRIVER) ||
		(property == HVGR_MEM_PROPERTY_SAME_VA))
		return false;

	return true;
}

static long hvgr_mem_ioctl_alloc_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_alloc_memory * const para)
{
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_alloc_para info = {0};
	struct hvgr_mem_area_va area_va = {0, 0};

	if (!hvgr_mem_ioctl_alloc_para_is_valid(ctx, para->in.property, para->in.attribute))
		return -EPERM;

	info.property = para->in.property;
	info.attribute = para->in.attribute;
	info.pages = para->in.pages;
	info.max_pages = para->in.max_pages;
	info.extent = para->in.extent;
	info.va = para->in.va;
	info.phy_pages = para->in.phy_pages;
	area = hvgr_mem_allocate(ctx, &info, &area_va, true);
	if (area == NULL)
		return -ENOMEM;

	para->out.gva = area_va.gva;
	para->out.attr = info.attribute;

	return 0;
}

static long hvgr_mem_ioctl_free_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_free_memory * const para)
{
	struct hvgr_mem_area *area = NULL;

	if (para->in.gva >= HVGR_MEM_BITMAP_START_OFFSET &&
		para->in.gva < HVGR_MEM_BITMAP_END_OFFSET) {
		hvgr_err(ctx->gdev, HVGR_MEM, "%s:%d ctx_%u dont support free pend 0x%lx",
			__func__, __LINE__, ctx->id, para->in.gva);
		return -EINVAL;
	}

	mutex_lock(&ctx->mem_ctx.area_mutex);
	area = hvgr_mem_zone_find_area_by_gva_range(&ctx->mem_ctx, para->in.gva);
	if (area == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "%s ctx_%u has no va 0x%lx",
			__func__, ctx->id, para->in.gva);
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		return -EINVAL;
	}

	if (!area->user_buf) {
		hvgr_err(ctx->gdev, HVGR_MEM, "%s ctx_%u perm deny: area 0x%lx 0x%lx:0x%lx",
			__func__, ctx->id, area->gva, area->property, area->attribute);
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		return -EPERM;
	}

	if ((area->property == HVGR_MEM_PROPERTY_IMPORT) && !hvgr_mem_import_is_rsv(area)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "%s ctx_%u ioctl free import not rsv area 0x%lx %lu:0x%lx",
			__func__, ctx->id, area->gva, area->property, area->attribute);
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		return -EPERM;
	}

	if (!hvgr_mem_ioctl_para_is_valid(ctx, area->property)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "%s ctx_%u prop deny: area 0x%lx 0x%lx:0x%lx",
			__func__, ctx->id, area->gva, area->property, area->attribute);
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		return -EPERM;
	}

	hvgr_mem_del_from_map_rec(ctx, area);
	area->is_freed = true;
	mutex_unlock(&ctx->mem_ctx.area_mutex);

	if (hvgr_mem_free_area_nolock(ctx, area) != 0)
		return -EINVAL;

	return 0;
}

static inline long hvgr_mem_ioctl_sync_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_sync_memory * const para)
{
	return hvgr_mem_sync(ctx, para->in.uva, para->in.size, para->in.direct);
}

static long hvgr_mem_ioctl_query_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_query_memory * const para)
{
	struct hvgr_mem_area *area = NULL;

	mutex_lock(&ctx->mem_ctx.area_mutex);
	/* Find area by gva range */
	area = hvgr_mem_zone_find_area_by_gva(&ctx->mem_ctx, para->in.gva);
	if (area == NULL) {
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		return -EINVAL;
	}

	para->out.property = area->property;
	para->out.attribute = area->attribute;
	para->out.pages = area->pages;
	para->out.max_pages = area->max_pages;
	para->out.va = area->gva;
	para->out.phy_pages = area->phy_pages;
	mutex_unlock(&ctx->mem_ctx.area_mutex);
	return 0;
}

static inline long hvgr_mem_ioctl_resize_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_resize_memory * const para)
{
	if (hvgr_mem_is_illegal_mm(ctx))
		return -EPERM;

	return hvgr_mem_resize(ctx, para->in.gva, para->in.pages);
}

static long hvgr_mem_ioctl_get_fd_size_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_get_fd_size_memory * const para)
{
	struct dma_buf *dmabuf = NULL;

	dmabuf = dma_buf_get(para->in.fd);
	if (IS_ERR_OR_NULL(dmabuf)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u get fd (%d) dma buf fail",
			ctx->id, para->in.fd);
		return -EINVAL;
	}

	para->out.pages = (PAGE_ALIGN(dmabuf->size) >> PAGE_SHIFT);

	dma_buf_put(dmabuf);
	return 0;
}

long hvgr_mem_ioctl_alias_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_alias_memory * const para)
{
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_alias_para info;

	info.attribute = para->in.attribute;
	info.stride = para->in.stride;
	info.count = para->in.count;
	info.alias_info_ptr = para->in.alias_info_ptr;
	area = hvgr_mem_alias(ctx, &info, &para->out.pages, &para->out.gva);
	if (area == NULL)
		return -ENOMEM;

	return 0;
}

static inline long hvgr_mem_ioctl_add_profile_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_profile_memory * const para)
{
	return hvgr_mem_add_profile(ctx, para->in.user_buf, para->in.size);
}


static inline long hvgr_mem_ioctl_bind_sparse_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_sparse_bind * const para)
{
	return hvgr_mem_sparse_bind(ctx, para->sparse_addr, para->mem_addr, para->pages, false);
}

static inline long hvgr_mem_ioctl_unbind_sparse_memory(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_sparse_unbind * const para)
{
	return hvgr_mem_sparse_unbind(ctx, para->sparse_addr, para->pages);
}

static long hvgr_mem_change_mem_attr(struct hvgr_ctx * const ctx, uint64_t gva, uint64_t attr)
{
	struct hvgr_mem_area *area = NULL;
	long ret = -EINVAL;

	if (gva == 0 || attr == 0)
		return -EINVAL;

	mutex_lock(&ctx->mem_ctx.area_mutex);
	area = hvgr_mem_zone_find_area_by_gva(&ctx->mem_ctx, gva);
	if (area == NULL) {
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u change attr no area for 0x%lx", ctx->id, gva);
		return -EINVAL;
	}

	/* Until now, only sparse mem/gpu mem/4g mem(debug) can change attribute */
	switch (area->property) {
	case HVGR_MEM_PROPERTY_SPARSE:
		ret = hvgr_sparse_mem_change_attr(ctx, area, attr);
		if (ret != 0)
			hvgr_err(ctx->gdev, HVGR_MEM,
				"ctx_%u change sparse mem attr fail, attr=%lx:0x%lx, gva=0x%lx, %ld",
				ctx->id, attr, area->attribute, gva, ret);
		break;
	case HVGR_MEM_PROPERTY_GPU_MEM:
		ret = hvgr_gpu_mem_change_attr(ctx, area, attr);
		if (ret != 0)
			hvgr_err(ctx->gdev, HVGR_MEM,
				"ctx_%u change gpu mem attr fail, attr=%lx:0x%lx, gva=0x%lx, %ld",
				ctx->id, attr, area->attribute, gva, ret);
		break;
	default:
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u area prop 0x%lx don't support attr change",
			ctx->id, area->property);
		break;
	}

	mutex_unlock(&ctx->mem_ctx.area_mutex);
	return ret;
}

static inline long hvgr_mem_ioctl_change_memory_attr(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_change_memory_attr * const para)
{
	return hvgr_mem_change_mem_attr(ctx, para->gva, para->attribute);
}

#ifdef HVGR_FEATURE_SYSTEM_CACHE
static inline long hvgr_mem_ioctl_change_pgid_attr(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_change_pgid_attr * const para)
{
	return hvgr_sc_set_gid_policy(para->pgid, para->attribute);
}
#endif

long hvgr_mem_ioctl_query_rsv(struct hvgr_ctx * const ctx, hvgr_ioctl_para_rsv * const para)
{
	struct hvgr_mem_process_res_cb *res_cb = NULL;
	struct hvgr_kv_node *node = NULL;
	uint64_t op = para->in.op;

	mutex_lock(&ctx->gdev->mem_dev.mem_process_res_lock);
	node = hvgr_kv_get(&ctx->gdev->mem_dev.mem_process_res_rec,
		(uint64_t)ctx->mem_ctx.process_mm);
	if (node == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u (%d:%d) query rsv find cb fail",
			ctx->id, ctx->tgid, ctx->pid);
		mutex_unlock(&ctx->gdev->mem_dev.mem_process_res_lock);
		return -EINVAL;
	}

	res_cb = container_of(node, struct hvgr_mem_process_res_cb, kv_node);
	para->out.cnts = 0;
	para->out.addr = 0U;

	if (res_cb->mem_4gva != NULL)
		para->out.addr = res_cb->mem_4gva->va_space.start;

	if (op == HVGR_RSV_QUREY_ADD) {
		para->out.cnts = atomic_add_return(1, &res_cb->rsv_cnt);
	} else if (op == HVGR_RSV_QUREY_SUB) {
		para->out.cnts = atomic_sub_return(1, &res_cb->rsv_cnt);
		if (para->out.cnts < 0)
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u (%d:%d) rsv_cnt err %ld",
				ctx->id, ctx->tgid, ctx->pid, para->out.cnts);
	}

	mutex_unlock(&ctx->gdev->mem_dev.mem_process_res_lock);
	return 0;
}

static int hvgr_mem_check_import_paras(struct hvgr_ctx * const ctx, uint64_t attribute,
	uint64_t pages, uint32_t fd_num, int *fds)
{
	uint32_t i;

	if (pages == 0U || (pages >= (U64_MAX / sizeof(struct page *))) ||
		fd_num > HVGR_MEM_IMPORT_MAX ||
		(attribute & HVGR_MEM_MASK_GPU_ACCESS) == 0 ||
		(attribute & HVGR_MEM_ATTR_GPU_EXEC) != 0 ||
		(attribute & HVGR_MEM_ATTR_GROWABLE) != 0 ||
		(attribute & HVGR_MEM_ATTR_KMD_ACCESS) != 0 ||
		(attribute & HVGR_MEM_MASK_UMD_ACCESS) != 0 ||
		((attribute & HVGR_MEM_ATTR_SECURE) != 0 &&
		(attribute & HVGR_MEM_MASK_UMD_MAP_ACCESS) != 0) ||
		(attribute & HVGR_MEM_MASK_COHERENT) != 0 ||
		(attribute & HVGR_MEM_ATTR_MEM_SPARSE) != 0) {
		hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import fds para error, %u:0x%lx:0x%lx",
			ctx->id, fd_num, pages, attribute);
		return -1;
	}

#ifdef HVGR_FEATURE_SYSTEM_CACHE
	if (hvgr_get_policy_id(attribute) > 0U) {
		hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import no support SC, %u:0x%lx:0x%lx",
			ctx->id, fd_num, pages, attribute);
		return -1;
	}
#endif

	for (i = 0U; i < fd_num; i++) {
		if (fds[i] < 0) {
			hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import %u fd %d err",
				ctx->id, i, fds[i]);
			return -1;
		}
	}

	return 0;
}

static long hvgr_mem_import_try_rsv(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_import_fds * const para, struct hvgr_mem_area *area)
{
	uint64_t gva;

	gva = hvgr_mem_zone_alloc_gva(&ctx->mem_ctx, ZONE_TYPE_IMPORT, 0U,
		(area->max_pages << PAGE_SHIFT));
	if (gva == 0U) {
		hvgr_debug(ctx->gdev, HVGR_IMPORT, "%s:%d ctx_%u import %lu pages alloc rsv fail",
			__func__, __LINE__, ctx->id, area->max_pages);
		return ENOMEM;
	}

	area->gva = gva;
	if (hvgr_mem_import_map_gva_no_lock(area) != 0) {
		hvgr_err(ctx->gdev, HVGR_IMPORT, "%s:%d ctx_%u import map %lu pages to 0x%lx fail",
			__func__, __LINE__, ctx->id, area->max_pages, area->gva);
		hvgr_mem_zone_free_gva(area->zone->pmem, ZONE_TYPE_IMPORT, area->gva,
			(area->max_pages << PAGE_SHIFT));
		return EPERM;
	}

	area->node.key = area->gva;
	area->node.size = area->max_pages << PAGE_SHIFT;

	if (unlikely(hvgr_mem_add_to_map_rec(ctx, area) != 0)) {
		hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import add to map_rec fail", ctx->id);
		hvgr_mem_import_unmap_gva(area);
		return EPERM;
	}
	area->import.flag = HVGR_MEM_IMPORT_FlAG_RSV;

	para->out.gva = gva;
	para->out.flag = HVGR_MEM_IMPORT_FlAG_RSV;

	hvgr_info(ctx->gdev, HVGR_IMPORT, "%s:%d ctx_%u import area 0x%lx:0x%lx:%lu",
		__func__, __LINE__, ctx->id, area->gva, area->attribute, area->max_pages);
	return 0;
}

long hvgr_mem_ioctl_import_fds(struct hvgr_ctx * const ctx, hvgr_ioctl_para_import_fds * const para)
{
	struct hvgr_mem_import_record record[HVGR_MEM_IMPORT_MAX] = { 0 };
	uint64_t attribute = para->in.attribute;
	uint64_t pages = para->in.pages;
	uint32_t fd_num = para->in.fd_num;
	int fds[HVGR_MEM_IMPORT_MAX];
	uint32_t i;
	long ret;
	struct hvgr_mem_alloc_para area_para = {HVGR_MEM_PROPERTY_IMPORT, attribute, 0U,
		pages, 0U, 0U, 0U};
	struct hvgr_mem_area *area = NULL;
	uint64_t gva;

	(void)memcpy_s(fds, sizeof(fds), para->in.fds, sizeof(fds));

	if (hvgr_mem_check_import_paras(ctx, attribute, pages, fd_num, fds) != 0)
		return -1;

	area = hvgr_mem_new_area(&ctx->mem_ctx, &area_para);
	if (area == NULL) {
		hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import create area fail", ctx->id);
		return -1;
	}

	area->user_buf = true;

	if (area->max_pages <= MEM_PHY_ALLOC_THRESHOLD)
		area->page_array = kcalloc(area->max_pages, sizeof(struct page *), GFP_KERNEL);
	else
		area->page_array = vzalloc((area->max_pages * sizeof(struct page *)));
	if (area->page_array == NULL) {
		hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import create page array fail", ctx->id);
		hvgr_mem_free_area(area);
		return -1;
	}

	for (i = 0U; i < fd_num; i++) {
		ret = hvgr_mem_import_get_dmabuf(ctx, fds[i], &record[i]);
		if (ret != 0) {
			hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import %u fd %d get dmabuf fail",
				ctx->id, i, fds[i]);
			goto put_dambufs;
		}
	}

	for (i = 0U; i < fd_num; i++) {
		ret = hvgr_mem_import_get_page(ctx, area, &record[i]);
		if (ret != 0) {
			hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import %u fd %d get page fail",
				ctx->id, i, fds[i]);
			i = fd_num;
			goto put_page;
		}
	}

	para->out.flag = 0U;

	mutex_lock(&ctx->mem_ctx.area_mutex);
	ret = hvgr_mem_import_try_rsv(ctx, para, area);
	if (ret == 0) {
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		return 0;
	} else if (ret == ENOMEM) {
		/* try to mmap */
	} else {
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		i = fd_num;
		goto put_page;
	}

	/* alloc va by mmap */
	gva = hvgr_mem_pend_area_add(&ctx->mem_ctx, area);
	if (gva == 0U) {
		hvgr_err(ctx->gdev, HVGR_IMPORT, "ctx_%u import add pend fail", ctx->id);
		i = fd_num;
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		goto put_page;
	}
	area->import.flag = HVGR_MEM_IMPORT_FlAG_MMAP;
	mutex_unlock(&ctx->mem_ctx.area_mutex);

	para->out.gva = gva;
	para->out.flag = HVGR_MEM_IMPORT_FlAG_MMAP;

	hvgr_info(ctx->gdev, HVGR_IMPORT, "%s:%d ctx_%u import %u fd get area 0x%lx %lu 0x%lx",
		__func__, __LINE__, ctx->id, fd_num, attribute, pages, gva);
	return 0;

put_page:
	hvgr_mem_import_put_page(ctx, area);
	hvgr_del_bg_dmabuf_ctx_from_global_list(ctx);
put_dambufs:
	while (i != 0U) {
		i--;
		hvgr_mem_import_put_dmabuf(ctx, &record[i]);
	}

	kvfree(area->page_array);
	hvgr_mem_free_area(area);
	return -1;
}

long hvgr_ioctl_mem(struct hvgr_ctx * const ctx, unsigned int cmd, unsigned long arg)
{
	long ret = -EINVAL;

	switch (cmd) {
	case HVGR_IOCTL_ALLOC_MEM:
		hvgr_ioctl_handle_wr(ctx, HVGR_IOCTL_ALLOC_MEM,
			hvgr_mem_ioctl_alloc_memory, arg, hvgr_ioctl_para_alloc_memory);
		break;
	case HVGR_IOCTL_FREE_MEM:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_FREE_MEM,
			hvgr_mem_ioctl_free_memory, arg, hvgr_ioctl_para_free_memory);
		break;
	case HVGR_IOCTL_SYNC_MEM:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_SYNC_MEM,
			hvgr_mem_ioctl_sync_memory, arg, hvgr_ioctl_para_sync_memory);
		break;
	case HVGR_IOCTL_IMPORT_FDS:
		hvgr_ioctl_handle_wr(ctx, HVGR_IOCTL_IMPORT_FDS,
			hvgr_mem_ioctl_import_fds, arg, hvgr_ioctl_para_import_fds);
		break;
	case HVGR_IOCTL_QUERY_MEM:
		hvgr_ioctl_handle_wr(ctx, HVGR_IOCTL_QUERY_MEM,
			hvgr_mem_ioctl_query_memory, arg, hvgr_ioctl_para_query_memory);
		break;
	case HVGR_IOCTL_RESIZE_MEM:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_RESIZE_MEM,
			hvgr_mem_ioctl_resize_memory, arg, hvgr_ioctl_para_resize_memory);
		break;
	case HVGR_IOCTL_GET_FD_SIZE_MEM:
		hvgr_ioctl_handle_wr(ctx, HVGR_IOCTL_GET_FD_SIZE_MEM,
			hvgr_mem_ioctl_get_fd_size_memory, arg, hvgr_ioctl_para_get_fd_size_memory);
		break;
#if hvgr_version_lt(350)
	case HVGR_IOCTL_ALIAS_MEMORY:
		hvgr_ioctl_handle_wr(ctx, HVGR_IOCTL_ALIAS_MEMORY,
			hvgr_mem_ioctl_alias_memory, arg, hvgr_ioctl_para_alias_memory);
		break;
#endif
	case HVGR_IOCTL_ADD_PROFILE_MEM:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_ADD_PROFILE_MEM,
			hvgr_mem_ioctl_add_profile_memory, arg, hvgr_ioctl_para_profile_memory);
		break;
	case HVGR_IOCTL_SPARSE_MEM_BIND:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_SPARSE_MEM_BIND,
			hvgr_mem_ioctl_bind_sparse_memory, arg, hvgr_ioctl_para_sparse_bind);
		break;
	case HVGR_IOCTL_SPARSE_MEM_UNBIND:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_SPARSE_MEM_UNBIND,
			hvgr_mem_ioctl_unbind_sparse_memory, arg, hvgr_ioctl_para_sparse_unbind);
		break;
	case HVGR_IOCTL_CHANGE_MEM_ATTR:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_CHANGE_MEM_ATTR,
			hvgr_mem_ioctl_change_memory_attr, arg, hvgr_ioctl_para_change_memory_attr);
		break;
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	case HVGR_IOCTL_CHANGE_PGID_ATTR:
		hvgr_ioctl_handle_w(ctx, HVGR_IOCTL_CHANGE_PGID_ATTR,
			hvgr_mem_ioctl_change_pgid_attr, arg, hvgr_ioctl_para_change_pgid_attr);
		break;
#endif
	default:
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u ioctl cmd 0x%x is INVALID", ctx->id, cmd);
		break;
	}

exit:
	return ret;
}

unsigned long hvgr_mem_get_ctx_using_page(struct hvgr_ctx * const ctx)
{
	int used_pages;
	int jit_pool_pages;

	used_pages = atomic_read(&(ctx->mem_ctx.used_pages));
	jit_pool_pages = atomic_read(&(ctx->mem_ctx.jit_pool_pages));
	if (jit_pool_pages >= 0 && jit_pool_pages < used_pages)
		return (unsigned long)(used_pages - jit_pool_pages);

	return (unsigned long)used_pages;
}

unsigned long hvgr_mem_get_dev_using_page(struct hvgr_device * const gdev)
{
	int used_pages;
	int jit_pool_pages;

	used_pages = atomic_read(&(gdev->mem_dev.used_pages));
	jit_pool_pages = atomic_read(&(gdev->mem_dev.jit_pool_pages));
	if (jit_pool_pages >= 0 && jit_pool_pages < used_pages)
		return (unsigned long)(used_pages - jit_pool_pages);

	return (unsigned long)used_pages;
}

