/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <securec.h>
#include <linux/errno.h>
#include <linux/string.h>

#include "hvgr_defs.h"
#include "hvgr_dm_dfx.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_dm_driver_base.h"
#include "mem/hvgr_mem_zone.h"
#include "hvgr_lock.h"
#include "hvgr_mem_dfx.h"


void hvgr_dfx_init(struct hvgr_device * const gdev)
{
}

void hvgr_dfx_term(struct hvgr_device * const gdev)
{
}

static void hvgr_gpu_fault_process_detail(struct hvgr_device *gdev,
	struct hvgr_job_fault_data *data, struct hvgr_ctx *ctx[CQ_CHANNEL_NUM])
{
}

void hvgr_gpu_fault_show_process(struct hvgr_device *gdev,
	struct hvgr_job_fault_data *data, char *process_info, uint32_t info_len)
{
	uint32_t chn;
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_ctx *ctx_array[CQ_CHANNEL_NUM] = {NULL};
	struct hvgr_cq_dev * const cq_dev = &gdev->cq_dev;
	char process[HVGR_PROCESS_DATA_LEN] = {0};
	int len = 0;
	int ret;

	hvgr_spin_lock_irqsave_macro(gdev, &cq_dev->schedule_lock);

	for (chn = 0; chn < CQ_CHANNEL_NUM; chn++) {
		struct hvgr_cq_ctx *cq_ctx = cq_dev->channel_info[chn].running_queue;

		if (cq_ctx == NULL)
			continue;

		ctx = cq_ctx->ctx;
		ctx_array[chn] = ctx;
		hvgr_get_process_info(process, HVGR_PROCESS_DATA_LEN, ctx);
		hvgr_err(gdev, HVGR_DM, "GPU FAULT ch%u %s, asid: %u, apimode: %u, cq-pri: %u",
			chn, process, ctx->asid, ctx->api_mode, cq_ctx->priority);
		ret = snprintf_s(process_info + len, info_len - len, info_len - 1 - len,
			" %s:%u,%d,%u,%u", hvgr_get_main_process_name(ctx), chn,
			hvgr_get_ctx_compat(ctx), ctx->api_mode, cq_ctx->priority);
		if (likely(ret >= 0))
			len += ret;
	}

	/* inside lock to make sure ctx not release */
	hvgr_gpu_fault_process_detail(gdev, data, ctx_array);
	hvgr_spin_unlock_irqrestore(gdev, &cq_dev->schedule_lock);
}

