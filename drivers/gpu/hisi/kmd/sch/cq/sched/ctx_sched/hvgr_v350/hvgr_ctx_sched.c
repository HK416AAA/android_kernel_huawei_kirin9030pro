/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_ctx_sched.h"

#include "hvgr_pm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_mmu_api.h"
#include "hvgr_datan_api.h"
#include "hvgr_hts_api.h"
#include "hvgr_ssid.h"
#include "hvgr_asid.h"
#include "hvgr_lock.h"

bool hvgr_ctx_is_asid_valid(uint32_t asid)
{
	if (unlikely((asid == (uint32_t)HVGR_AS_NR_INVALID) || (asid >= HVGR_MAX_NR_AS)))
		return false;
	return true;
}

struct hvgr_ctx *hvgr_cq_lookup_ctx(struct hvgr_device *gdev, int asid)
{
	struct hvgr_ctx *found_ctx = NULL;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	if (hvgr_ctx_is_asid_valid((uint32_t)asid)) {
		found_ctx = gdev->as_to_ctx[asid];
		if (found_ctx == NULL) {
			hvgr_info(gdev, HVGR_CQ, " %s not found ctx by asid(%d)\n", __func__, asid);
			hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
			return NULL;
		}

		atomic_inc(&found_ctx->refcount);
	}
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
	return found_ctx;
}

struct hvgr_ctx *hvgr_cq_lookup_ctx_noretain(
	struct hvgr_device *gdev, int asid)
{
	struct hvgr_ctx *found_ctx = NULL;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	if (hvgr_ctx_is_asid_valid(asid))
		found_ctx = gdev->as_to_ctx[asid];
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);

	return found_ctx;
}

void hvgr_cq_sched_release_ctx_without_lock(struct hvgr_device *gdev,
	struct hvgr_ctx *ctx)
{
	if (atomic_dec_return(&ctx->refcount) == 0)
		hvgr_free_asid(ctx, ctx->asid);
}

void hvgr_cq_sched_release_ctx(struct hvgr_device *gdev,
	struct hvgr_ctx *ctx)
{
	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	hvgr_info(gdev, HVGR_CQ, "%s ctx_%u refcount old(%d)->new(%d) ,ctx->asid=%d\n",
		__func__, ctx->id, atomic_read(&ctx->refcount),
		atomic_read(&ctx->refcount) - 1, ctx->asid);
	if (atomic_dec_return(&ctx->refcount) == 0)
		hvgr_free_asid(ctx, ctx->asid);

	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
}

void hvgr_ctx_alloc_static_asid_and_ssid(struct hvgr_ctx * const ctx)
{
	hvgr_spin_lock_irqsave_macro(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
	ctx->ssid = hvgr_alloc_normal_static_ssid(ctx);
	if (ctx->ssid == (uint32_t)HVGR_SSID_INVALID) {
		ctx->asid = HVGR_AS_NR_INVALID;
		hvgr_info(ctx->gdev, HVGR_CQ, "ctx_%u alloc static asid fail", ctx->id);
	} else {
		hvgr_alloc_normal_static_asid(ctx, ctx->ssid);
		atomic_inc(&ctx->refcount);
		hvgr_info(ctx->gdev, HVGR_CQ, "ctx_%u alloc static asid=%d, ssid=%d", ctx->id, ctx->asid, ctx->ssid);
	}
	hvgr_spin_unlock_irqrestore(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
}

void hvgr_ctx_free_normalq_static_assid(struct hvgr_ctx *ctx)
{
	struct hvgr_device *const gdev = ctx->gdev;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	/* free normal q static ssid */
	if (ctx->ssid > HVGR_NORMAL_DYNAMIC_SSID_NUM && ctx->ssid < HVGR_NORMAL_SSID_NUM) {
		if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY)
			(void)hvgr_mmu_hal_disable(ctx);

		hvgr_info(gdev, HVGR_CQ, "ctx_%u free asid=%d, ssid=%d", ctx->id, ctx->asid, ctx->ssid);
		atomic_dec(&ctx->refcount);
		hvgr_release_asid(ctx);
		hvgr_release_ssid(ctx);
		ctx->asid = (uint32_t)HVGR_AS_NR_INVALID;
		ctx->ssid = (uint32_t)HVGR_SSID_INVALID;
	}
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
}

static void hvgr_ctx_free_dynamic_assid(struct hvgr_ctx *ctx)
{
	struct hvgr_device *const gdev = ctx->gdev;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	/* free dynamic ssid */
	WARN_ON(atomic_read(&ctx->refcount) != 0);
	if (hvgr_ctx_is_asid_valid(ctx->asid)) {
		if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY)
			(void)hvgr_mmu_hal_disable(ctx);

		gdev->as_to_ctx[ctx->asid] = NULL;
		ctx->asid = HVGR_AS_NR_INVALID;
		ctx->ssid = HVGR_SSID_INVALID;
		hvgr_info(gdev, HVGR_CQ, "%s ctx->asid = 0x%x ssid = 0x%x", __func__, ctx->asid, ctx->ssid);
	}
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
}

void kmd_ctx_sched_remove_ctx(struct hvgr_ctx *ctx)
{
	struct hvgr_device *const gdev = ctx->gdev;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	if (ctx->ffts_flag > 0)
		return;

	mutex_lock(&pm_pwr->power_lock);
#if defined(HVGR_FEATURE_HTS) && HVGR_FEATURE_HTS != 0
	hvgr_ctx_free_hts_static_assid(ctx);
#endif
	hvgr_ctx_free_normalq_static_assid(ctx);
	hvgr_ctx_free_dynamic_assid(ctx);
	mutex_unlock(&pm_pwr->power_lock);
}

bool hvgr_cq_retain_active_ctx(struct hvgr_device * const gdev,
	struct hvgr_ctx * const ctx)
{
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	uint32_t chn_idx;

	for (chn_idx = 0; chn_idx < CQ_CHANNEL_NUM; chn_idx++) {
		if (gcqctx->channel_info[chn_idx].running_queue == NULL)
			continue;

		if (gcqctx->channel_info[chn_idx].running_queue->ctx == ctx) {
			atomic_inc(&ctx->refcount);
			return true;
		}
	}

#if hvgr_fe_enabled(HVGR_FE_FFTS)
	if (ctx->issueq_binded) {
		atomic_inc(&ctx->refcount);
		return true;
	}
#endif

	return false;
}

bool hvgr_ctx_sched_in(struct hvgr_ctx * const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;

#if (defined(HVGR_FEATURE_HTS) && HVGR_FEATURE_HTS != 0) || hvgr_fe_enabled(HVGR_FE_FFTS)
	/* ffts/hts static asid and ssid, 64 =< asid < 4096, 64 =< ssid < 256 */
	if (ctx->ssid >= HVGR_NORMAL_SSID_NUM && ctx->ssid < HVGR_ALL_IP_SSID_NUM &&
		ctx->asid != (uint32_t)HVGR_AS_NR_INVALID && ctx->asid >= (uint32_t)HVGR_NORMAL_SSID_NUM) {
		hvgr_datan_jobtrace(ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_RET_AS_CTX, ctx, ctx->asid);
		hvgr_mmu_flush_tlb(ctx);
		return true;
	}
#endif

	/* normal q static asid and ssid, 8 < asid = ssid < 64 */
	if (ctx->ssid > HVGR_NORMAL_DYNAMIC_SSID_NUM && ctx->ssid < HVGR_NORMAL_SSID_NUM) {
		hvgr_datan_jobtrace(ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_RET_AS_CTX, ctx, ctx->asid);
		hvgr_mmu_flush_tlb(ctx);
		return true;
	}

	/* alloc dynamic asid */
	ctx->asid = hvgr_alloc_asid(ctx);
	/* remove hts ssid situation */
	if (ctx->ssid <= HVGR_NORMAL_DYNAMIC_SSID_NUM || ctx->ssid == (uint32_t)HVGR_SSID_INVALID)
		ctx->ssid = ctx->asid;
	hvgr_info(gdev, HVGR_CQ, "%s asid=%d.\n", __func__, ctx->asid);
	if (unlikely(!hvgr_ctx_is_asid_valid(ctx->asid))) {
		hvgr_err(gdev, HVGR_CQ, "%s get asid fail.\n", __func__);
		return false;
	}
	hvgr_datan_jobtrace(ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_RET_AS_CTX, ctx, ctx->asid);
	hvgr_mmu_flush_tlb(ctx);
	return true;
}

void hvgr_ctx_sched_out(struct hvgr_ctx * const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;

	if (unlikely(!hvgr_ctx_is_asid_valid(ctx->asid))) {
		hvgr_err(gdev, HVGR_CQ, "%s asid invalid.\n", __func__);
		return;
	}

#if (defined(HVGR_FEATURE_HTS) && HVGR_FEATURE_HTS != 0) || hvgr_fe_enabled(HVGR_FE_FFTS)
	if (ctx->ssid >= HVGR_NORMAL_SSID_NUM && ctx->ssid < HVGR_ALL_IP_SSID_NUM &&
		ctx->asid != (uint32_t)HVGR_AS_NR_INVALID && ctx->asid >= (uint32_t)HVGR_NORMAL_SSID_NUM)
		return;
#endif

	if (ctx->ssid > HVGR_NORMAL_DYNAMIC_SSID_NUM && ctx->ssid < HVGR_NORMAL_SSID_NUM)
		return;

	if (hvgr_pm_get_gpu_status(ctx->gdev) == HVGR_PM_GPU_READY)
		(void)hvgr_mmu_hal_disable(ctx);

	if (atomic_read(&ctx->refcount) == 0) {
		hvgr_err(gdev, HVGR_CQ, "%s ctx_%u refcount is already 0.\n", __func__, ctx->id);
		return;
	}

	if (atomic_dec_return(&ctx->refcount) == 0)
		hvgr_free_asid(ctx, ctx->asid);
}

bool hvgr_ctx_sched_in_with_lock(struct hvgr_ctx * const ctx)
{
	bool ret = false;
	struct hvgr_device *gdev = ctx->gdev;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	ret = hvgr_ctx_sched_in(ctx);
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
	return ret;
}

void hvgr_ctx_sched_out_with_lock(struct hvgr_ctx * const ctx)
{
	struct hvgr_device *gdev = ctx->gdev;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	hvgr_ctx_sched_out(ctx);
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
}
