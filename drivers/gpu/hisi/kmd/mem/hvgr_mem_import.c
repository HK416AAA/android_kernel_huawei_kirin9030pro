/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mem_import.h"

#include <linux/kernel.h>
#include <linux/pfn.h>
#include <linux/dma-buf.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/sched/mm.h>
#include <linux/rcupdate.h>
#ifdef CONFIG_BG_DMABUF_RECLAIM
#include <linux/bg_dmabuf_reclaim/bg_dmabuf_ops.h>
#endif
#include "hvgr_mem_zone.h"
#include "hvgr_mem_api.h"
#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_mem_space.h"
#include "hvgr_platform_api.h"

/*
 * dma_buf_detach/dma_buf_put/dma_buf_attach has dmabuf_lock
 * DMABUF_RECLAIM's opts are in dmabuf_lock, then try lock area_mutex
 * so caller who has area_mutex cannt call dma_buf_detach/dma_buf_put/dma_buf_attach
 */

bool hvgr_mem_import_is_rsv(struct hvgr_mem_area *area)
{
	if ((area->gva >= HVGR_MEM_IMPORT_START) && (area->gva < HVGR_MEM_IMPORT_END))
		return true;

	return false;
}

void hvgr_add_bg_dmabuf_ctx_to_global_list(struct hvgr_ctx * const ctx)
{
	if (ctx->mem_ctx.bd_dmabuf_flag)
		return;

	if (ctx->mem_ctx.bg_dmabuf_cnt > 0U) {
		ctx->mem_ctx.bd_dmabuf_flag = true;
		list_add_tail(&ctx->dma_buf_link, &ctx->gdev->mem_dev.dmabuf_ctx_list_head);
	}
}

void hvgr_del_bg_dmabuf_ctx_from_global_list(struct hvgr_ctx * const ctx)
{
	mutex_lock(&ctx->gdev->mem_dev.dmabuf_rec_lock);
	mutex_lock(&ctx->mem_ctx.area_mutex);
	if (!ctx->mem_ctx.bd_dmabuf_flag)
		goto out;

	if (ctx->mem_ctx.bg_dmabuf_cnt == 0U) {
		list_del(&ctx->dma_buf_link);
		ctx->mem_ctx.bd_dmabuf_flag = false;
	}
out:
	mutex_unlock(&ctx->mem_ctx.area_mutex);
	mutex_unlock(&ctx->gdev->mem_dev.dmabuf_rec_lock);
}

#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
static void hvgr_record_dma_buf_locked(struct hvgr_ctx *ctx, struct dma_buf *dmabuf,
	uint32_t start_page_nr, struct hvgr_mem_area *area, struct hvgr_dma_buf_record *dma_buf_rec)
{
	dma_buf_rec->dmabuf = dmabuf;
	dma_buf_rec->area = area;
	dma_buf_rec->ctx = ctx;
	dma_buf_rec->start_page_nr = start_page_nr;
	dma_buf_rec->page_nr = (uint32_t)(area->pages - start_page_nr);
	dma_buf_rec->record_idx = area->import.data.umm.cnt;

	mutex_lock(&ctx->gdev->mem_dev.dmabuf_rec_lock);
	mutex_lock(&ctx->mem_ctx.area_mutex);
	area->import.data.umm.record[area->import.data.umm.cnt].dma_buf_rec = dma_buf_rec;
	list_add_tail(&dma_buf_rec->dma_buf_list, &ctx->mem_ctx.dma_buf_rec_head);
	ctx->mem_ctx.bg_dmabuf_cnt++;
	hvgr_add_bg_dmabuf_ctx_to_global_list(ctx);
	mutex_unlock(&ctx->mem_ctx.area_mutex);
	mutex_unlock(&ctx->gdev->mem_dev.dmabuf_rec_lock);
}

static void hvgr_erase_dma_buf_nolock(struct hvgr_ctx *ctx, struct hvgr_mem_area *area)
{
	uint32_t i;
	struct hvgr_mem_import_record *record = NULL;

	for (i = 0U; i < area->import.data.umm.cnt; i++) {
		record = &area->import.data.umm.record[i];
		if (record->dma_buf_rec != NULL) {
			list_del(&record->dma_buf_rec->dma_buf_list);
			kvfree(record->dma_buf_rec);
			if (area->zone->pmem->bg_dmabuf_cnt != 0U)
				area->zone->pmem->bg_dmabuf_cnt--;
			if (atomic_read(&area->import.data.umm.free_tlb_cnt) > 0)
				atomic_dec(&area->import.data.umm.free_tlb_cnt);
			if (atomic_read(&area->import.data.umm.restore_tlb_cnt) > 0)
				atomic_dec(&area->import.data.umm.restore_tlb_cnt);
			record->dma_buf_rec = NULL;
		}
	}
}
#endif

static bool hvgr_mem_import_map(struct hvgr_ctx * const ctx, struct hvgr_mem_area * const area)
{
	hvgr_mem_attr2flag(area);

	if (!hvgr_mem_map_gva(NULL, area)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import alloc map gva fail, uva/gva=0x%lx",
			ctx->id, area->gva);
		return false;
	}

	return true;
}

long hvgr_mem_import_map_gva_no_lock(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);

	if (atomic_read(&area->import.data.umm.free_tlb_cnt) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import 0x%lx alloc check cnt fail",
			ctx->id, area->gva);
		return -1;
	}

	if (area->import.data.umm.mapped) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import 0x%lx map gva again",
			ctx->id, area->gva);
		return -1;
	}

	if (!hvgr_mem_import_map(ctx, area))
		return -1;

	area->import.data.umm.mapped = true;

	hvgr_info(ctx->gdev, HVGR_IMPORT, "%s:%d ctx_%u import area map gva 0x%lx",
		__func__, __LINE__, ctx->id, area->gva);
	return 0;
}


long hvgr_mem_import_map_gva(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
	long ret;

	mutex_lock(&ctx->mem_ctx.area_mutex);
	ret = hvgr_mem_import_map_gva_no_lock(area);
	mutex_unlock(&ctx->mem_ctx.area_mutex);

	return ret;
}

static void hvgr_mem_import_umm_free_pages(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
	uint32_t i;
	struct hvgr_mem_import_record *record = NULL;
#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
	bool need_unlock = false;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	if (unlikely(__mutex_owner(&ctx->mem_ctx.area_mutex) == current)) {
#else
	if (unlikely(mutex_owner(&ctx->mem_ctx.area_mutex) == current)) {
#endif
		/* do nothing */
	} else {
		need_unlock = true;
		mutex_lock(&ctx->mem_ctx.area_mutex);
	}
	hvgr_erase_dma_buf_nolock(ctx, area);
	if (need_unlock)
		mutex_unlock(&ctx->mem_ctx.area_mutex);
	hvgr_del_bg_dmabuf_ctx_from_global_list(ctx);
#endif

	for (i = 0U; i < area->import.data.umm.cnt; i++) {
		record = &area->import.data.umm.record[i];
		if (record->dmabuf_attach != NULL && record->sg_table != NULL) {
			dma_buf_unmap_attachment(record->dmabuf_attach, record->sg_table,
				DMA_BIDIRECTIONAL);
			dma_buf_detach(record->dmabuf, record->dmabuf_attach);
			record->dmabuf_attach = NULL;
			record->sg_table = NULL;
		}
		dma_buf_put(record->dmabuf);
		record->dmabuf = NULL;
	}
	kvfree(area->page_array);

	hvgr_info(ctx->gdev, HVGR_IMPORT, "%s:%d ctx_%u import destroy page_array",
		__func__, __LINE__, ctx->id);
}

void hvgr_mem_import_unmap_gva(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
	bool need_unlock = false;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	if (unlikely(__mutex_owner(&ctx->mem_ctx.area_mutex) == current)) {
#else
	if (unlikely(mutex_owner(&ctx->mem_ctx.area_mutex) == current)) {
#endif
		/* do nothing */
	} else {
		need_unlock = true;
		mutex_lock(&ctx->mem_ctx.area_mutex);
	}
#endif
	if (area->import.data.umm.mapped && (atomic_read(&area->import.data.umm.free_tlb_cnt) == 0))
		hvgr_mem_unmap_gva(NULL, area);
	else
		hvgr_debug(ctx->gdev, HVGR_MEM, "ctx_%u import 0x%lx dont unmap %d %d",
			ctx->id, area->gva, (int)area->import.data.umm.mapped,
			atomic_read(&area->import.data.umm.free_tlb_cnt));

#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
	if (need_unlock)
		mutex_unlock(&ctx->mem_ctx.area_mutex);
#endif
	if (hvgr_mem_import_is_rsv(area))
		hvgr_mem_zone_free_gva(area->zone->pmem, ZONE_TYPE_IMPORT, area->gva,
			(area->max_pages << PAGE_SHIFT));

	hvgr_info(ctx->gdev, HVGR_IMPORT, "%s:%d ctx_%u import area unmap gva 0x%lx",
		__func__, __LINE__, ctx->id, area->gva);
}

static long hvgr_mem_import_free(struct hvgr_mem_area * const area)
{
	hvgr_mem_import_unmap_gva(area);
	hvgr_mem_area_ref_put(area);
	return 0;
}

void hvgr_mem_import_free_when_term(struct hvgr_mem_area *area)
{
	hvgr_mem_import_unmap_gva(area);
	hvgr_mem_import_umm_free_pages(area);
	hvgr_mem_free_area(area);
}

static uint32_t hvgr_mem_import_insert_pages(struct hvgr_ctx *ctx, struct hvgr_mem_area *area,
	struct sg_table *sg_table, uint64_t need_pages, uint32_t start_page_nr)
{
	struct scatterlist *sg = NULL;
	uint32_t i;
	uint64_t page_cnt = 0U;
	uint32_t pages;

	pages = start_page_nr;
	for_each_sg(sg_table->sgl, sg, sg_table->nents, i) {
		uint32_t j;
		uint32_t page_num = PFN_UP(sg_dma_len(sg));
		struct page *page = NULL;
		struct page **page_arr = NULL;

		WARN_ONCE(sg_dma_len(sg) & (u32)(PAGE_SIZE - 1U),
			"dma len %u is not a multiple of PAGE_SIZE\n", sg_dma_len(sg));

		WARN_ONCE(sg_dma_address(sg) & (u32)(PAGE_SIZE - 1U),
			"dma addr %llx is not aligned to PAGE_SIZE\n",
			(unsigned long long)sg_dma_address(sg));

		page = sg_page(sg);
		page_arr = &area->page_array[pages];
		for (j = 0U; (j < page_num) && (page_cnt < need_pages); j++, page_cnt++) {
			page_arr[j] = &page[j];
			pages++;
		}
	}
	return (pages - start_page_nr);
}

long hvgr_mem_import_get_dmabuf(struct hvgr_ctx *ctx, int fd, struct hvgr_mem_import_record *record)
{
	struct dma_buf *dmabuf = NULL;
	struct dma_buf_attachment *dmabuf_attach = NULL;
	struct sg_table *sg_table = NULL;

	dmabuf = dma_buf_get(fd);
	if (IS_ERR_OR_NULL(dmabuf)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import get buf fd %d fail", ctx->id, fd);
		goto get_buf_fail;
	}

	dmabuf_attach = dma_buf_attach(dmabuf, ctx->gdev->dev);
	if (IS_ERR_OR_NULL(dmabuf_attach)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import attach fd %d fail", ctx->id, fd);
		goto attach_fail;
	}

	sg_table = dma_buf_map_attachment(dmabuf_attach, DMA_BIDIRECTIONAL);
	if (IS_ERR_OR_NULL(sg_table)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import buf map fd %d fail", ctx->id, fd);
		goto map_fail;
	}

	record->dmabuf = dmabuf;
	record->dmabuf_attach = dmabuf_attach;
	record->sg_table = sg_table;
	return 0;

map_fail:
	dma_buf_detach(dmabuf, dmabuf_attach);
attach_fail:
	dma_buf_put(dmabuf);
get_buf_fail:
	return -EFAULT;
}

void hvgr_mem_import_put_dmabuf(struct hvgr_ctx *ctx, struct hvgr_mem_import_record *record)
{
	dma_buf_unmap_attachment(record->dmabuf_attach, record->sg_table, DMA_BIDIRECTIONAL);
	dma_buf_detach(record->dmabuf, record->dmabuf_attach);
	dma_buf_put(record->dmabuf);
}

long hvgr_mem_import_get_page(struct hvgr_ctx *ctx, struct hvgr_mem_area *area,
	struct hvgr_mem_import_record *record)
{
	struct hvgr_mem_import_record *import_record = NULL;
	uint64_t pages;
	uint32_t insert_pages;
#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
	uint32_t start_page_nr;
	struct hvgr_dma_buf_record *dma_buf_rec = NULL;
#endif

	pages = (PAGE_ALIGN(record->dmabuf->size) >> PAGE_SHIFT);
	if (pages == 0U || (pages + area->pages) > area->max_pages) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import 0x%lx pages 0x%lx 0x%lx out of range (0x%lx:0x%lx)",
			ctx->id, area->gva, pages, (u64)record->dmabuf->size, area->pages,
			area->max_pages);
		return -1;
	}
#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
	dma_buf_rec = kzalloc(sizeof(*dma_buf_rec), GFP_KERNEL);
	if (dma_buf_rec == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u import 0x%lx pages 0x%lx 0x%lx alloc dma buffer record fail (0x%lx:0x%lx)",
			ctx->id, area->gva, pages, (u64)record->dmabuf->size, area->pages,
			area->max_pages);
		return -ENOMEM;
	}
	start_page_nr = (uint32_t)area->pages;
#endif
	insert_pages = hvgr_mem_import_insert_pages(ctx, area, record->sg_table, pages,
		(uint32_t)area->pages);
	area->pages += insert_pages;

	hvgr_platform_mem_import_osh(record->dmabuf, area);

	import_record = &(area->import.data.umm.record[area->import.data.umm.cnt]);
	import_record->sg_table = record->sg_table;
	import_record->dmabuf_attach = record->dmabuf_attach;
	import_record->dmabuf = record->dmabuf;
	import_record->dma_buf_rec = NULL;
#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
	hvgr_record_dma_buf_locked(ctx, record->dmabuf, start_page_nr, area, dma_buf_rec);
#endif
	area->import.data.umm.cnt++;
	area->import.type = HVGR_MEM_IMPORT_UMM;
	return 0;
}

void hvgr_mem_import_put_page(struct hvgr_ctx *ctx, struct hvgr_mem_area *area)
{
#if (defined(CONFIG_BG_DMABUF_RECLAIM) || defined(CONFIG_DMABUF_RECLAIM))
	mutex_lock(&ctx->mem_ctx.area_mutex);
	hvgr_erase_dma_buf_nolock(ctx, area);
	mutex_unlock(&ctx->mem_ctx.area_mutex);
#endif
}

static bool hvgr_mem_import_check_para(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = NULL;

	if (unlikely((area == NULL) || (area->zone == NULL)))
		return false;

	ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
	if (area->import.type != HVGR_MEM_IMPORT_UMM || area->pages != area->max_pages) {
		hvgr_err(ctx->gdev, HVGR_MEM,
			"ctx_%u import attribute INVALID. type:%u 0x%lx:0x%lx",
			ctx->id, area->import.type, area->pages, area->max_pages);
		return false;
	}

	return true;
}

static const struct hvgr_zone_opts g_mem_zone_import = {
	.init = hvgr_mem_opt_init,
	.term = hvgr_mem_opt_term,
	.check_para = hvgr_mem_import_check_para,
	.alloc = NULL,
	.free = hvgr_mem_import_free,
	.import = NULL,
};

bool hvgr_mem_import_config(struct hvgr_mem_ctx * const pmem)
{
	if (unlikely(pmem == NULL))
		return false;

	return hvgr_mem_zone_create(pmem, HVGR_MEM_PROPERTY_IMPORT,
		&g_mem_zone_import, NULL);
}

void hvgr_mem_import_free_pages(struct hvgr_mem_area *area)
{
	hvgr_mem_import_umm_free_pages(area);
}

static bool hvgr_mem_is_dmabuf_rec_invalid(struct dma_buf *dmabuf,
	struct hvgr_dma_buf_record *dmabuf_rec)
{
	struct hvgr_mem_import_record *record = NULL;
	struct hvgr_mem_area *area = NULL;

	area = dmabuf_rec->area;
	if (unlikely(dmabuf_rec->record_idx >= HVGR_MEM_IMPORT_MAX)) {
		hvgr_err(dmabuf_rec->ctx->gdev, HVGR_MEM, "record idx is invalid, record idx = %u",
			dmabuf_rec->record_idx);
		return false;
	}

	record = &area->import.data.umm.record[dmabuf_rec->record_idx];
	if (record->dmabuf != dmabuf) {
		hvgr_err(dmabuf_rec->ctx->gdev, HVGR_MEM, "record dmabuf is invalid, record idx = %u",
			dmabuf_rec->record_idx);
		return false;
	}

	return true;
}

static bool hvgr_mem_release_tlb_by_dmabuf_rec(struct hvgr_ctx *ctx,
	struct hvgr_dma_buf_record *dmabuf_rec, struct dma_buf *dmabuf)
{
	struct hvgr_mem_import_record *record = NULL;
	struct hvgr_mem_area *area = NULL;
	uint64_t ref_limit = 1U;

	/* Check dmabuf is invalid */
	if (!hvgr_mem_is_dmabuf_rec_invalid(dmabuf, dmabuf_rec))
		return false;

	area = dmabuf_rec->area;

	if (area->import.flag == HVGR_MEM_IMPORT_FlAG_MMAP)
		ref_limit = 2U;

	if (!area->import.data.umm.mapped || hvgr_mem_area_ref_read(area) > ref_limit ||
		area->is_freed || (hvgr_mem_area_ref_read(area) == ref_limit && area->mmap_cnt > 0U))
		return false;

	record = &area->import.data.umm.record[dmabuf_rec->record_idx];
	hvgr_info(ctx->gdev, HVGR_MEM, "%s ctx_%d", __func__, ctx->id);
	/* Delete cpu and gpu tlb */
	if (atomic_inc_return(&area->import.data.umm.free_tlb_cnt) == 1) {
		hvgr_mem_unmap_gva(NULL, area);
		hvgr_debug(ctx->gdev, HVGR_IMPORT, "ctx_%u area 0x%lx 0x%lx:%lu:%lu dambuf release",
			ctx->id, area->attribute, area->gva, area->pages, area->max_pages);
	}
	area->import.data.umm.fault = false;

	/* Detachment sg table */
	dma_buf_unmap_attachment(record->dmabuf_attach, record->sg_table, DMA_BIDIRECTIONAL);
	dma_buf_detach(record->dmabuf, record->dmabuf_attach);
	record->sg_table = NULL;
	record->dmabuf_attach = NULL;

	hvgr_info(ctx->gdev, HVGR_IMPORT, "%s ctx_%u area 0x%lx %lu:0x%lx:0x%lx",
		__func__, ctx->id, area->gva, area->property, area->attribute, area->pages);
	return true;
}

static void hvgr_mem_rollback_dmabuf_tlb(struct hvgr_ctx *ctx,
	struct hvgr_dma_buf_record *dmabuf_rec, struct dma_buf *dmabuf)
{
	struct hvgr_mem_import_record *record = NULL;
	struct hvgr_mem_area *area = NULL;

	/* Check dmabuf is invalid */
	if (!hvgr_mem_is_dmabuf_rec_invalid(dmabuf, dmabuf_rec))
		return;

	area = dmabuf_rec->area;
	if (area->is_freed) {
		hvgr_debug(ctx->gdev, HVGR_IMPORT, "ctx_%u area 0x%lx %lu:%lu is freed cant dambuf rollback",
			ctx->id, area->attribute, area->pages, area->max_pages);
		return;
	}

	record = &area->import.data.umm.record[dmabuf_rec->record_idx];
	if (record->dmabuf_attach != NULL || record->sg_table != NULL)
		return;

	record->dmabuf_attach = dma_buf_attach(dmabuf, ctx->gdev->dev);
	record->sg_table = dma_buf_map_attachment(record->dmabuf_attach, DMA_BIDIRECTIONAL);

	hvgr_info(ctx->gdev, HVGR_MEM, "%s ctx_%d", __func__, ctx->id);
	if (area->import.data.umm.mapped && atomic_read(&area->import.data.umm.free_tlb_cnt) == 1) {
		hvgr_mem_map_gva(NULL, area);
		hvgr_debug(ctx->gdev, HVGR_IMPORT, "ctx_%u area 0x%lx %lu:%lu dambuf rollback",
			ctx->id, area->attribute, area->pages, area->max_pages);
	}

	atomic_dec(&area->import.data.umm.free_tlb_cnt);
	return;
}

static int hvgr_mem_dmabuf_restore_pages(struct dma_buf *dmabuf,
	struct hvgr_dma_buf_record *dmabuf_rec)
{
	struct dma_buf_attachment *dmabuf_attach = NULL;
	struct sg_table *sg_table = NULL;
	uint64_t pages;
	struct hvgr_mem_import_record *record = NULL;
	struct hvgr_mem_area *area = NULL;

	area = dmabuf_rec->area;
	record = &area->import.data.umm.record[dmabuf_rec->record_idx];
	/*
	 * if sg_table or dmabuf_attach is not null, it means the dmabuffer not released,
	 * abort restore.
	 */
	if (record->sg_table != NULL || record->dmabuf_attach != NULL)
		return -1;

	pages = (PAGE_ALIGN(dmabuf->size) >> PAGE_SHIFT);
	if (pages < dmabuf_rec->page_nr) {
		hvgr_err(dmabuf_rec->ctx->gdev, HVGR_MEM,
			"ctx_%u restore tlb dma buf size[%lu] is smaller than needed[%u]",
			dmabuf_rec->ctx->id, pages, dmabuf_rec->page_nr);
		return -1;
	}

	dmabuf_attach = dma_buf_attach(dmabuf, dmabuf_rec->ctx->gdev->dev);
	if (IS_ERR_OR_NULL(dmabuf_attach)) {
		hvgr_err(dmabuf_rec->ctx->gdev, HVGR_MEM, "ctx_%u restore tlb 0x%lx attach buf fail",
			dmabuf_rec->ctx->id, dmabuf_rec->area->gva);
		return -1;
	}

	sg_table = dma_buf_map_attachment(dmabuf_attach, DMA_BIDIRECTIONAL);
	if (IS_ERR_OR_NULL(sg_table)) {
		hvgr_err(dmabuf_rec->ctx->gdev, HVGR_MEM, "ctx_%u restore tlb 0x%lx map fail",
			dmabuf_rec->ctx->id, dmabuf_rec->area->gva);
		dma_buf_detach(dmabuf, dmabuf_attach);
		return -1;
	}
	(void)hvgr_mem_import_insert_pages(dmabuf_rec->ctx, dmabuf_rec->area, sg_table,
		dmabuf_rec->page_nr, dmabuf_rec->start_page_nr);

	record->sg_table = sg_table;
	record->dmabuf_attach = dmabuf_attach;
	atomic_inc(&area->import.data.umm.restore_tlb_cnt);

	return 0;
}

static void hvgr_mem_restore_tlb_by_dmabuf_rec(struct hvgr_ctx *ctx,
	struct hvgr_dma_buf_record *dmabuf_rec, struct dma_buf *dmabuf)
{
	struct hvgr_mem_area *area = NULL;

	/* Check dmabuf is invalid */
	if (!hvgr_mem_is_dmabuf_rec_invalid(dmabuf, dmabuf_rec))
		return;

	area = dmabuf_rec->area;
	if (area->is_freed) {
		hvgr_debug(ctx->gdev, HVGR_IMPORT, "ctx_%u area 0x%lx %lu:%lu is freed cant dambuf restore",
			ctx->id, area->attribute, area->pages, area->max_pages);
		return;
	}

	hvgr_info(ctx->gdev, HVGR_MEM, "%s ctx_%d", __func__, ctx->id);
	/* Get new pages from dma buf */
	if (hvgr_mem_dmabuf_restore_pages(dmabuf, dmabuf_rec) != 0)
		return;

	/* Restore cpu and gpu tlb */
	if (atomic_read(&area->import.data.umm.restore_tlb_cnt) ==
		atomic_read(&area->import.data.umm.free_tlb_cnt)) {
		if (area->import.data.umm.mapped) {
			(void)hvgr_mem_import_map(ctx, area);
			hvgr_debug(ctx->gdev, HVGR_IMPORT, "ctx_%u area 0x%lx %lu:%lu dambuf restore gva 0x%llx",
				ctx->id, area->attribute, area->pages, area->max_pages, area->gva);
		}

		area->import.data.umm.fault = false;
		atomic_set(&area->import.data.umm.free_tlb_cnt, 0);
		atomic_set(&area->import.data.umm.restore_tlb_cnt, 0);
	}

	hvgr_info(ctx->gdev, HVGR_IMPORT, "%s ctx_%u area 0x%lx %lu:0x%lx:0x%lx",
		__func__, ctx->id, area->gva, area->property, area->attribute, area->pages);
}

static bool hvgr_mem_dmabuf_area_operation(struct hvgr_device *gdev, struct dma_buf *dmabuf,
	uint32_t oper)
{
	struct hvgr_mem_dev *mem_dev = NULL;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx = NULL;

	struct hvgr_dma_buf_record *iter_dmabuf = NULL;
	struct hvgr_dma_buf_record *tmp_dmabuf = NULL;

	mem_dev = &gdev->mem_dev;
	list_for_each_entry_safe(ctx, tmp, &mem_dev->dmabuf_ctx_list_head, dma_buf_link) {
		mutex_lock(&ctx->mem_ctx.area_mutex);
		if (list_empty(&ctx->mem_ctx.dma_buf_rec_head)) {
			mutex_unlock(&ctx->mem_ctx.area_mutex);
			continue;
		}
		list_for_each_entry_safe(iter_dmabuf, tmp_dmabuf, &ctx->mem_ctx.dma_buf_rec_head,
			dma_buf_list) {
			if (iter_dmabuf->dmabuf != dmabuf)
				continue;

			switch (oper) {
			case HVGR_DMA_RELEASE_TLB:
				if (!hvgr_mem_release_tlb_by_dmabuf_rec(ctx, iter_dmabuf, dmabuf)) {
					mutex_unlock(&ctx->mem_ctx.area_mutex);
					return false;
				}
				break;
			case HVGR_DMA_ROLLBACK_TLB:
				hvgr_mem_rollback_dmabuf_tlb(ctx, iter_dmabuf, dmabuf);
				break;
			case HVGR_DMA_RESTORE_TLB:
				hvgr_mem_restore_tlb_by_dmabuf_rec(ctx, iter_dmabuf, dmabuf);
				break;
			default:
				break;
			}
		}
		mutex_unlock(&ctx->mem_ctx.area_mutex);
	}
	return true;
}

int hvgr_mem_release_dmabuf_mmu_tlb(struct dma_buf *dmabuf)
{
	struct hvgr_device *gdev = NULL;

	gdev = hvgr_get_device();
	if (gdev == NULL)
		return -EFAULT;

	mutex_lock(&gdev->mem_dev.dmabuf_rec_lock);
	if (list_empty(&gdev->mem_dev.dmabuf_ctx_list_head))
		goto out;

	if (!hvgr_mem_dmabuf_area_operation(gdev, dmabuf, HVGR_DMA_RELEASE_TLB))
		goto fail;

out:
	mutex_unlock(&gdev->mem_dev.dmabuf_rec_lock);
	return 0;
fail:
	/*
	 * delete tlb fail, recover the tlb which has been deleted and return -EFAULT. so the
	 * physical will not be freed.
	 */
	hvgr_mem_dmabuf_area_operation(gdev, dmabuf, HVGR_DMA_ROLLBACK_TLB);
	mutex_unlock(&gdev->mem_dev.dmabuf_rec_lock);
	return -EFAULT;
}

int hvgr_mem_restore_dmabuf_mmu_tlb(struct dma_buf *dmabuf)
{
	struct hvgr_device *gdev = NULL;

	gdev = hvgr_get_device();
	if (gdev == NULL)
		return -EFAULT;

	mutex_lock(&gdev->mem_dev.dmabuf_rec_lock);
	if (list_empty(&gdev->mem_dev.dmabuf_ctx_list_head))
		goto out;
	hvgr_mem_dmabuf_area_operation(gdev, dmabuf, HVGR_DMA_RESTORE_TLB);
out:
	mutex_unlock(&gdev->mem_dev.dmabuf_rec_lock);
	return 0;
}

void hvgr_ion_mem_reclaim_init(struct hvgr_device * const gdev)
{
	struct hvgr_mem_dev *mem_dev = &gdev->mem_dev;

#ifdef CONFIG_BG_DMABUF_RECLAIM
	(void)bg_buffer_register_callback(BG_BUF_CB_GPU_UNMAP, hvgr_mem_release_dmabuf_mmu_tlb);
	(void)bg_buffer_register_callback(BG_BUF_CB_GPU_MAP, hvgr_mem_restore_dmabuf_mmu_tlb);
#endif
	mutex_init(&mem_dev->dmabuf_rec_lock);
	INIT_LIST_HEAD(&mem_dev->dmabuf_ctx_list_head);
}
