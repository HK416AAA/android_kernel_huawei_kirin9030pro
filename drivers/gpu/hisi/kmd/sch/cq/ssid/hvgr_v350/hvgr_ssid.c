/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/bitmap.h>
#include <linux/types.h>

#include "hvgr_schedule.h"
#include "hvgr_log_api.h"
#include "hvgr_defs.h"

uint32_t hvgr_alloc_ffrt_ssid(struct hvgr_ctx * ctx)
{
	uint32_t end = HVGR_ALL_SSID_NUM;
	uint32_t start = HVGR_NORMAL_SSID_NUM;
	uint32_t free_ssid;

	free_ssid = find_next_zero_bit(ctx->gdev->cq_dev.ssid_bitmap, end, start);
	if (free_ssid >= end) {
		hvgr_info(ctx->gdev, HVGR_CQ, "%s ctx_%u, alloc ffrt ssid fail\n", __func__, ctx->id);
		return (uint32_t)HVGR_SSID_INVALID;
	}

	bitmap_set(ctx->gdev->cq_dev.ssid_bitmap, free_ssid, 1);
	return free_ssid;
}

uint32_t hvgr_alloc_normal_static_ssid(struct hvgr_ctx * ctx)
{
	uint32_t end = HVGR_NORMAL_SSID_NUM;
	uint32_t start = HVGR_NORMAL_DYNAMIC_SSID_NUM + 1;
	uint32_t free_ssid;

	free_ssid = find_next_zero_bit(ctx->gdev->cq_dev.ssid_bitmap, end, start);
	if (free_ssid >= end) {
		hvgr_info(ctx->gdev, HVGR_CQ, "%s ctx_%u, alloc normal static ssid fail\n", __func__, ctx->id);
		return (uint32_t)HVGR_SSID_INVALID;
	}

	bitmap_set(ctx->gdev->cq_dev.ssid_bitmap, free_ssid, 1);
	return free_ssid;
}

void hvgr_release_ssid(struct hvgr_ctx * ctx)
{
	uint32_t ssid = ctx->ssid;

	if (ssid >= HVGR_ALL_SSID_NUM || ssid == 0)
		return;
	
	hvgr_info(ctx->gdev, HVGR_CQ, "%s ctx_%u release ssid(%d)\n", __func__, ctx->id, ssid);
	bitmap_clear(ctx->gdev->cq_dev.ssid_bitmap, ssid, 1);
}