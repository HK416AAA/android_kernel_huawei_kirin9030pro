/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/mm.h>
#include <securec.h>

#include "uniform_id.h"
#include "ffts_ffap1_connect.h"
#include "ffts_proc_block.h"
#include "ffts_types.h"

#include "hvgr_mmu_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_mem_opts.h"
#include "hvgr_log_api.h"
#include "hvgr_kmd_defs.h"
#include "hvgr_pm_api.h"
#include "hvgr_asid.h"
#include "hvgr_dm_comm_ctx.h"

#include "hvgr_ffts_api.h"
#include "hvgr_issueq_sched.h"
#include "hvgr_lock.h"

#define COMMON_CTX_DEFAULT_ATTRS	(HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_GPU_WR | \
	HVGR_MEM_ATTR_KMD_ACCESS)

/* 4M */
#define HVGR_ISSUEQ_SSIX_CTX_WLS_PAGE_CNT		1024
/* 64M */
#define HVGR_ISSUEQ_SSIX_CTX_TLS_PAGE_CNT		(16 * 1024)
#define HVGR_ISSUEQ_SSIX_CTX_PAGE_CNT			(HVGR_ISSUEQ_SSIX_CTX_TLS_PAGE_CNT + \
	HVGR_ISSUEQ_SSIX_CTX_TLS_PAGE_CNT)

static bool hvgr_issueq_alloc_sw(struct hvgr_device * const gdev, uint64_t gva_offset)
{
	uint64_t size = 0;
	struct hvgr_mem_alloc_para para = {0};
	struct hvgr_mem_area *area = NULL;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	size = hvgr_mem_page_align(cq_ringbuf_align(sizeof(struct hvgr_issueq_sw_ctx)));
	para.attribute = COMMON_CTX_DEFAULT_ATTRS;
	para.pages = (uint32_t)hvgr_page_nums(size);
	para.max_pages = para.pages;
	para.va = COMMON_CTX_FFTS_COMM_START + gva_offset;
	para.property = HVGR_MEM_COMM_CTX_DEFAULT;
	area = hvgr_comm_ctx_alloc_area(gdev, &para);
	if (area == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "%s alloc area failed", __func__);
		return false;
	}

	ffts->sw_area = area;
	ffts->sw_ctx = u64_to_ptr(area->kva);
	hvgr_info(gdev, HVGR_FFTS, "%s success 0x%llx 0x%llx", __func__,
		para.va, area->gva);
	return true;
}

static bool hvgr_issueq_alloc_hw(struct hvgr_device * const gdev, uint64_t gva_offset)
{
	uint64_t size = 16 * 1024;
	struct hvgr_mem_alloc_para para = {0};
	struct hvgr_mem_area *area = NULL;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	para.attribute = COMMON_CTX_DEFAULT_ATTRS;
	para.pages = (uint32_t)hvgr_page_nums(size);
	para.max_pages = para.pages;
	para.va = COMMON_CTX_FFTS_COMM_START + gva_offset;
	para.property = HVGR_MEM_COMM_CTX_DEFAULT;
	area = hvgr_comm_ctx_alloc_area(gdev, &para);
	if (area == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "%s alloc area failed", __func__);
		return false;
	}

	ffts->hw_area = area;
	ffts->hw_ctx = u64_to_ptr(area->kva);
	ffts->sw_ctx->hw_context_address = area->gva;
	hvgr_info(gdev, HVGR_FFTS, "%s success 0x%llx 0x%llx", __func__,
		para.va, area->gva);
	return true;
}

static bool hvgr_issueq_alloc_ring_buf(struct hvgr_device * const gdev, uint64_t gva_offset)
{
	uint64_t size = CQ_BIN_RING_BUF_SIZE + CQ_BIN_RING_BUF_SIZE;
	struct hvgr_mem_alloc_para para = {0};
	struct hvgr_mem_area *area = NULL;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	para.attribute = HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_GPU_WR;
	para.pages = (uint32_t)hvgr_page_nums(size);
	para.max_pages = para.pages;
	para.va = COMMON_CTX_FFTS_COMM_START + gva_offset;
	para.property = HVGR_MEM_COMM_CTX_DEFAULT;
	area = hvgr_comm_ctx_alloc_area(gdev, &para);
	if (area == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "%s alloc area failed", __func__);
		return false;
	}

	ffts->ring_buf_area = area;
	ffts->sw_ctx->task0_ring_buf_struct_ptr = area->gva;
	ffts->sw_ctx->task0_ring_buf_struct_size = CQ_BIN_RING_BUF_SIZE / sizeof(uint32_t);
	ffts->sw_ctx->task1_ring_buf_struct_ptr = area->gva + CQ_BIN_RING_BUF_SIZE;
	ffts->sw_ctx->task1_ring_buf_struct_size = CQ_BIN_RING_BUF_SIZE / sizeof(uint32_t);
	hvgr_info(gdev, HVGR_FFTS, "%s success 0x%llx", __func__, para.va);
	return true;
}

static bool hvgr_issueq_alloc_ssid_ctx(struct hvgr_device * const gdev, uint64_t gva_offset)
{
	uint64_t size = 256 * 4096 / 8;
	struct hvgr_mem_alloc_para para = {0};
	struct hvgr_mem_area *area = NULL;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	para.attribute = COMMON_CTX_DEFAULT_ATTRS;
	para.pages = (uint32_t)hvgr_page_nums(size);
	para.max_pages = para.pages;
	para.va = COMMON_CTX_FFTS_COMM_START + gva_offset;
	para.property = HVGR_MEM_COMM_CTX_DEFAULT;
	area = hvgr_comm_ctx_alloc_area(gdev, &para);
	if (area == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "%s alloc area failed", __func__);
		return false;
	}

	ffts->ssid_ctx_area = area;
	ffts->ssid_ctx = u64_to_ptr(area->kva);
	ffts->sw_ctx->ssid_context_address = area->gva;
	hvgr_info(gdev, HVGR_FFTS, "%s success 0x%llx 0x%llx", __func__,
		para.va, area->gva);
	return true;
}

static void hvgr_issueq_ctx_add(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	list_add(&ctx->ffts_link, &ffts->ctx_list);
	ffts->ref_cnt++;
}

static void hvgr_issueq_ctx_map(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	if (q->sch_state == ISSUEQ_SCH_RUNNING) {
		hvgr_info(gdev, HVGR_FFTS, "%s ctx_%u map to gpu", __func__, ctx->id);
		hvgr_mmu_flush_tlb(ctx);
		ctx->issueq_binded = true;
	}
}

static void hvgr_issueq_ctx_unmap(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	if (q->sch_state == ISSUEQ_SCH_RUNNING) {
		hvgr_info(gdev, HVGR_FFTS, "%s ctx_%u unmap from gpu", __func__, ctx->id);
		(void)hvgr_mmu_hal_disable(ctx);
		ctx->issueq_binded = false;
	}
}

void hvgr_issueq_unmap_all_ctx(struct hvgr_device * const gdev)
{
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *iter = NULL;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	list_for_each_entry_safe(iter, tmp, &ffts->ctx_list, ffts_link) {
		hvgr_info(gdev, HVGR_FFTS, "%s ctx_%u unmap from gpu", __func__, iter->id);
		hvgr_mmu_hal_disable(iter);
		iter->issueq_binded = false;
	}
}

void hvgr_issueq_map_all_ctx(struct hvgr_device * const gdev)
{
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *iter = NULL;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	list_for_each_entry_safe(iter, tmp, &ffts->ctx_list, ffts_link) {
		hvgr_info(gdev, HVGR_FFTS, "%s ctx_%u map to gpu", __func__, iter->id);
		hvgr_mmu_flush_tlb(iter);
		iter->issueq_binded = true;
	}
}

static void hvgr_issueq_ctx_remove(struct hvgr_ctx *const ctx)
{
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	list_del(&ctx->ffts_link);
	ffts->ref_cnt--;
}

static bool hvgr_issueq_alloc_assid(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	uint32_t ssid;

	ssid = ffrt_get_uniform_id(ctx->tgid);
	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	/* get ssid from ffrt */
	ctx->ssid = ssid;
	if (ctx->ssid == FFRT_INVALID_UNIFORM_ID) {
		ctx->ssid = HVGR_SSID_INVALID;
		hvgr_err(ctx->gdev, HVGR_FFTS, "ctx_%u tgid_%d, get ssid failed",
			ctx->id, ctx->tgid);
		goto fail_ssid;
	}

	/* get asid from 64-256 */
	ctx->asid = hvgr_alloc_ffrt_asid(ctx);
	if (ctx->asid == (uint32_t)HVGR_AS_NR_INVALID) {
		hvgr_err(ctx->gdev, HVGR_FFTS, "ctx_%u get asid failed", ctx->id);
		goto fail_ssid;
	}

	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
	hvgr_info(ctx->gdev, HVGR_FFTS, "ctx_%u alloc_issueq, asid=%u, ssid=%u",
		ctx->id, ctx->asid, ctx->ssid);

	return true;

fail_ssid:
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
	hvgr_err(gdev, HVGR_FFTS, "%s failed", __func__);
	return false;
}

static void hvgr_issueq_free_assid(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	if (ctx->asid == (uint32_t)HVGR_AS_NR_INVALID) {
		hvgr_err(gdev, HVGR_FFTS, "%s ctx_%u invalid asid", __func__, ctx->id);
		hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
		return;
	}

	hvgr_issueq_ctx_unmap(ctx);
	hvgr_release_asid(ctx);
	ctx->asid = (uint32_t)HVGR_AS_NR_INVALID;
	ctx->ssid = (uint32_t)HVGR_SSID_INVALID;
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
}

static void hvgr_issueq_free_comm_resc(struct hvgr_device * const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	if (ffts->ref_cnt != 0) {
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		hvgr_info(gdev, HVGR_FFTS, "no need to free common resc");
		return;
	}
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);

	hvgr_issueq_unsubmit_sync_nolock(gdev);

	if (ffts->sw_area != NULL) {
		hvgr_comm_ctx_free_area(gdev, ffts->sw_area);
		ffts->sw_area = NULL;
		ffts->sw_ctx = NULL;
	}

	if (ffts->hw_area != NULL) {
		hvgr_comm_ctx_free_area(gdev, ffts->hw_area);
		ffts->hw_area = NULL;
	}

	if (ffts->ring_buf_area != NULL) {
		hvgr_comm_ctx_free_area(gdev, ffts->ring_buf_area);
		ffts->ring_buf_area = NULL;
	}

	if (ffts->ssid_ctx_area != NULL) {
		hvgr_comm_ctx_free_area(gdev, ffts->ssid_ctx_area);
		ffts->ssid_ctx_area = NULL;
		ffts->ssid_ctx = NULL;
	}
}

/* one process one issueq ctx */
static bool hvgr_issueq_check_ctx_vld(struct hvgr_ctx *const ctx)
{
	struct hvgr_ctx *iter = NULL;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	list_for_each_entry_safe(iter, tmp, &ffts->ctx_list, ffts_link) {
		if (iter->tgid == ctx->tgid) {
			hvgr_err(gdev, HVGR_FFTS, "ctx_%u/ctx_%u tgid_%d, already exist issueq",
				ctx->id, iter->id, ctx->tgid);
			return false;
		}
	}

	return true;
}

static bool hvgr_issueq_check_ctx_exist(struct hvgr_ctx *const ctx)
{
	struct hvgr_ctx *iter = NULL;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	list_for_each_entry_safe(iter, tmp, &ffts->ctx_list, ffts_link) {
		if (iter == ctx)
			return true;
	}

	return false;
}

bool hvgr_issueq_alloc_comm_resc(struct hvgr_device * const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	uint64_t gva_offset = 0;

	/* alloc common resc */
	if (!hvgr_issueq_alloc_sw(gdev, gva_offset))
		goto failed;

	gva_offset += (ffts->sw_area->max_pages + 1) << PAGE_SHIFT;
	if (!hvgr_issueq_alloc_hw(gdev, gva_offset))
		goto failed;

	gva_offset += (ffts->hw_area->max_pages + 1) << PAGE_SHIFT;
	if (!hvgr_issueq_alloc_ring_buf(gdev, gva_offset))
		goto failed;

	gva_offset += (ffts->ring_buf_area->max_pages + 1) << PAGE_SHIFT;
	if (!hvgr_issueq_alloc_ssid_ctx(gdev, gva_offset))
		goto failed;

	ffts_ffap1_cb_regist(hvgr_issueq_submit, hvgr_issueq_unsubmit, FFTS_HW_GPU);
	hvgr_info(gdev, HVGR_FFTS, "%s success", __func__);
	return true;

failed:
	hvgr_issueq_free_comm_resc(gdev);

	return false;
}

static void hvgr_issueq_ssid_ctx_config(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_ssid_ctx *sctx = NULL;
	if (unlikely((ctx->ssid < HVGR_NORMAL_SSID_NUM) || (ctx->ssid >= HVGR_FFRT_SSID_MAX))) {
		hvgr_err(gdev, HVGR_FFTS, "%s ssid is invalid ctx%u ssid %u",
			__func__, ctx->id, ctx->ssid);
		return;
	}
	sctx = &ffts->ssid_ctx[ctx->ssid];
#if hvgr_version_ge(600)
	sctx->double_cs_disable = 1;
#else
#if hvgr_version_eq(350)
	sctx->process_priority = 7;
	sctx->priority_attribute = 2;
#endif
	sctx->warp_priority = 0;
	sctx->defer_cs_issue_en = 0;
#endif
	sctx->jd_msb = ctx->same_va_4g_base_page;
	sctx->sk_base_ptr = 0;

	hvgr_info(gdev, HVGR_FFTS, "%s ctx_%u %u 0x%x ok", __func__,
		ctx->id, ctx->ssid, sctx->jd_msb);
}

static bool hvgr_issueq_alloc_ctx_ssid_ctx(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_ssid_ctx *sctx = NULL;
	struct hvgr_mem_area *wls_area = NULL;
	struct hvgr_mem_area *tls_area = NULL;
	struct hvgr_mem_alloc_para para = {0};

	if (unlikely((ctx->ssid < HVGR_NORMAL_SSID_NUM) || (ctx->ssid >= HVGR_FFRT_SSID_MAX))) {
		hvgr_err(gdev, HVGR_FFTS, "%s ssid is invalid ctx%u ssid %u",
			__func__, ctx->id, ctx->ssid);
		return false;
	}
	sctx = &ffts->ssid_ctx[ctx->ssid];

	para.property = HVGR_MEM_PROPERTY_GPU_MEM;
	para.attribute = HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_GPU_WR;
	para.pages = HVGR_ISSUEQ_SSIX_CTX_WLS_PAGE_CNT;
	para.max_pages = para.pages;
	wls_area = hvgr_mem_allocate(ctx, &para, NULL, false);
	if (wls_area == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "%s alloc wls_area failed", __func__);
		return false;
	}

	para.pages = HVGR_ISSUEQ_SSIX_CTX_TLS_PAGE_CNT;
	para.max_pages = para.pages;
	tls_area = hvgr_mem_allocate(ctx, &para, NULL, false);
	if (tls_area == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "%s alloc tls_area failed", __func__);
		hvgr_mem_free(ctx, wls_area->gva);
		return false;
	}

	hvgr_issueq_ssid_ctx_config(ctx);
	sctx->wls_size = 15;
	sctx->tls_size = 8;
	sctx->wls_base_ptr = wls_area->gva;
	sctx->tls_base_ptr = tls_area->gva;
	hvgr_info(gdev, HVGR_FFTS, "%s success", __func__);

	return true;
}

static void hvgr_issueq_free_ctx_ssid_ctx(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_ssid_ctx *sctx = NULL;

	if (unlikely((ctx->ssid < HVGR_NORMAL_SSID_NUM) || (ctx->ssid >= HVGR_FFRT_SSID_MAX))) {
		hvgr_err(gdev, HVGR_FFTS, "%s ssid is invalid ctx%u ssid %u",
			__func__, ctx->id, ctx->ssid);
		return;
	}
	sctx = &ffts->ssid_ctx[ctx->ssid];

	hvgr_mem_free(ctx, sctx->wls_base_ptr);
	hvgr_mem_free(ctx, sctx->tls_base_ptr);
}

static void hvgr_issueq_close_ctx(void *data, int32_t tgid)
{
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_device *gdev = hvgr_get_device();

	ctx = (struct hvgr_ctx *)data;
	if (ctx == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "%s %u ctx is NULL", __func__, tgid);
		return;
	}

	(void)kref_put(&ctx->ctx_kref, hvgr_ctx_kref_release);
	hvgr_debug(gdev, HVGR_FFTS, "%s close", __func__);
}

/* issueq resource alloc, include
 * 1. global resc, when refcnt is zero;
 * 2. alloc ssid and asid.
 * 3. wls\tls for each issueq ctx.
 * 4. map issueq_ctx to gpu.
 */
bool hvgr_issueq_alloc(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	bool need_alloc = false;

	mutex_lock(&ffts->lock);
	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	if (!hvgr_issueq_check_ctx_vld(ctx)) {
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		goto fail_comm_resc;
	}
	need_alloc = (ffts->ref_cnt == 0);
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);

	if (need_alloc && !hvgr_issueq_alloc_comm_resc(gdev))
		goto fail_comm_resc;

	if (!hvgr_issueq_alloc_assid(ctx))
		goto fail_alloc_assid;

	if (!hvgr_issueq_alloc_ctx_ssid_ctx(ctx))
		goto fail_ssid_ctx;

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	hvgr_issueq_ctx_add(ctx);
	hvgr_issueq_ctx_map(ctx);
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);

	mutex_unlock(&ffts->lock);
	kref_get(&ctx->ctx_kref);
	ffts_proc_release_register(FFTS_HW_GPU, hvgr_issueq_close_ctx, ctx, (int32_t)ctx->tgid);

	hvgr_info(gdev, HVGR_FFTS, "%s success", __func__);
	return true;

fail_ssid_ctx:
	hvgr_issueq_free_assid(ctx);

fail_alloc_assid:
	hvgr_issueq_free_comm_resc(gdev);

fail_comm_resc:
	mutex_unlock(&ffts->lock);
	hvgr_err(gdev, HVGR_FFTS, "%s failed", __func__);

	return false;
}

void hvgr_issueq_free(struct hvgr_ctx *const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	if (ctx->ffts_flag == 0)
		return;

	mutex_lock(&ffts->lock);

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	if (!hvgr_issueq_check_ctx_exist(ctx)) {
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		mutex_unlock(&ffts->lock);
		hvgr_info(gdev, HVGR_FFTS, "%s already free", __func__);
		return;
	}

	hvgr_info(gdev, HVGR_FFTS, "%s enter", __func__);
	hvgr_issueq_ctx_remove(ctx);
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);

	hvgr_issueq_free_ctx_ssid_ctx(ctx);
	hvgr_issueq_free_assid(ctx);
	hvgr_issueq_free_comm_resc(gdev);

	mutex_unlock(&ffts->lock);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

int hvgr_ffts_init(struct hvgr_device * const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	INIT_LIST_HEAD(&ffts->ctx_list);
	mutex_init(&ffts->lock);
	hvgr_issueq_sched_init(gdev);


	return 0;
}

void hvgr_ffts_term(struct hvgr_device *gdev)
{
	hvgr_issueq_sched_term(gdev);
}
