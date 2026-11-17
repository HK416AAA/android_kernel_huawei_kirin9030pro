/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/bitmap.h>
#include <linux/atomic.h>

#include "hvgr_schedule.h"
#include "hvgr_log_api.h"
#include "hvgr_asid.h"

void hvgr_alloc_normal_static_asid(struct hvgr_ctx * ctx, uint32_t ssid)
{
	ctx->asid = ssid;
	if (ssid >= HVGR_MAX_NR_AS) 
		return;
	bitmap_set(ctx->gdev->asid_bitmap, ssid, 1);
	ctx->gdev->as_to_ctx[ssid] = ctx;
}

uint32_t hvgr_alloc_ffrt_asid(struct hvgr_ctx *ctx)
{
	uint32_t start = HVGR_NORMAL_SSID_NUM;
	uint32_t end = HVGR_MAX_NR_AS;
	uint32_t free_asid;

	free_asid = find_next_zero_bit(ctx->gdev->asid_bitmap, end, start);
	if (free_asid >= end) {
		hvgr_info(ctx->gdev, HVGR_CQ, "%s ctx_%u, alloc ffrt asid fail\n", __func__, ctx->id);
		return (uint32_t)HVGR_AS_NR_INVALID;
	}

	bitmap_set(ctx->gdev->asid_bitmap, free_asid, 1);
	ctx->gdev->as_to_ctx[free_asid] = ctx;
	return free_asid;
}

void hvgr_release_asid(struct hvgr_ctx * ctx)
{
	uint32_t asid = ctx->asid;

	if (asid >= HVGR_MAX_NR_AS || asid == 0) 
		return;
		
	hvgr_info(ctx->gdev, HVGR_CQ, "%s ctx_%u release asid(%d)\n", __func__, ctx->id, asid);
	bitmap_clear(ctx->gdev->asid_bitmap, asid, 1);
	ctx->gdev->as_to_ctx[asid] = NULL;
}