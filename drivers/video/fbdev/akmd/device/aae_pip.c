/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/dma-buf.h>
#include <linux/delay.h>
#include <securec.h>
#include <aae/soc_dpu_define.h>
#include <aae/dpu_smmu.h>
#include "aae_pip.h"
#include "aae_pip_hw.h"
#include "dacc_aae.h"
#include "aae_cmdlist.h"
#include "aae_dvfs.h"
#include "aae_isr.h"
#include "aae_manager.h"
#include "aae_smmu.h"
#include "cmdlist_interface.h"
#include "aae_res_mgr.h"
#include "aae_config_utils.h"
#include "ukmd_acquire_fence.h"
#include "ukmd_utils.h"
#include "akmd_log.h"

static void aae_pip_postprocess(struct aae_pipeline_sw *pip_sw, bool timeout)
{
	uint32_t i;
	struct ukmd_dma_buf *buffer = NULL;
	struct aae_commit *commit = &pip_sw->commit;

	// reset dvfs level to normal lowest level
	aae_dvfs_vote_level(pip_sw->index, AAE_CLK_LEVEL_ON, true, false);
	aae_pip_smmu_tlb_flush(commit->scene_id, commit->commit_index);
	ukmd_cmdlist_present_release_locked(CMDLIST_DEV_ID_AAE, commit->scene_id, commit->cmdlist_id);

	for (i = 0; i < commit->layer_count; ++i) {
		buffer = &(pip_sw->layer_dma_buf[i]);
		if ((buffer->share_fd > 0) && !IS_ERR_OR_NULL(buffer->buf_handle)) {
			aae_pr_debug("release %s", buffer->name);
			dma_buf_put(buffer->buf_handle);
			buffer->share_fd = -1;
			buffer->buf_handle = NULL;
		}
	}
	pip_sw->wb_done = 0;
	pip_sw->wb_committed = 0;

	if (unlikely(timeout)) {
		up(&pip_sw->sem);
		aae_manager_lock_all();
		pip_sw->reset_func(pip_sw);
		aae_manager_unlock_all();
		down(&pip_sw->sem);
	}

	pip_sw->off_func_no_lock(pip_sw);
}

static void aae_pip_check_wb_finish(struct aae_pipeline_sw *pip_sw)
{
	int32_t ret = 0;
	uint64_t end_tv;
	uint32_t timeout_interval = g_debug_aae_pip_wait_time ? g_debug_aae_pip_wait_time :
		((aae_config_get_hw_type() == AAE_HW_TYPE_ASIC) ? ASIC_EVENT_TIMEOUT_MS : FPGA_EVENT_TIMEOUT_MS);
	int times = 0;
	aae_trace_ts_begin(&end_tv);

	if (unlikely(pip_sw->index >= AAE_PIP_MAX)) {
		aae_pr_err("aae pip index=%u", pip_sw->index);
		return;
	}

	while (true) {
		ret = (int32_t)wait_event_interruptible_timeout(pip_sw->wb_wq,
			(pip_sw->wb_done == 1), /* wb type status is true */
			(long)msecs_to_jiffies(timeout_interval));
		if ((ret == -ERESTARTSYS) && (times++ < 50))
			mdelay(10);
		else
			break;
	}

	if (ret <= 0) {
		aae_pr_warn("aae pip index=%u work timeout!!", pip_sw->index);
		if (g_debug_aae_clear_enable) {
			aae_pr_info("power_status=0x%llx pip_sw.index=%d power=%u",
				pip_sw->aae_mgr->power_status.status, pip_sw->index,
				pip_sw->aae_mgr->power_status.refcount.value[pip_sw->index]);
			if (pip_sw->aae_mgr->power_status.status == 0) {
				aae_pr_info("already power off, do not need handle underflow clear!");
				return;
			}

			ret = (int32_t)dacc_aae_handle_clear(pip_sw->aae_mgr->aae_base, pip_sw->commit.scene_id);
			if (ret != 0) {
				aae_pr_warn("aae pip index=%u clear failed, reset hardware", pip_sw->index);
				aae_pip_postprocess(pip_sw, true);
				aae_trace_ts_end(&end_tv, "aae pip work failed");
				return;
			}
		}
	} else {
		pip_sw->offline_succ = 1;
	}

	aae_pip_postprocess(pip_sw, false);
	aae_trace_ts_end(&end_tv, "aae pip work");
}

static void aae_pip_preprocess(struct aae_pipeline_sw *pip_sw)
{
	uint32_t i;
	struct aae_layer *layer = NULL;
	struct aae_commit *commit = &pip_sw->commit;
	int ret;

	aae_dvfs_vote_level(pip_sw->index, commit->perf_level, true, false);

	/* wait layer acquired fence and lock dma buf */
	for (i = 0; i < commit->layer_count; ++i) {
		layer = &commit->layer[i];
		if (layer->acquired_fence > 0) {
			ukmd_acquire_fence_wait_fd(layer->acquired_fence, ACQUIRE_FENCE_TIMEOUT_MSEC);
			layer->acquired_fence = -1;
		}
		if (layer->share_fd > 0) {
			pip_sw->layer_dma_buf[i].share_fd = layer->share_fd;
			pip_sw->layer_dma_buf[i].buf_handle = dma_buf_get(layer->share_fd);
			ret = snprintf_s(pip_sw->layer_dma_buf[i].name, UKMD_SYNC_NAME_SIZE, UKMD_SYNC_NAME_SIZE - 1, \
								"aae_buf_fd_%d", layer->share_fd);
			if (ret < 0)
				aae_pr_err("layer%u format string failed", i);
		}
	}
}

static int32_t aae_pip_commit(struct aae_pipeline_sw *pip_sw)
{
	int32_t ret = 0;
	struct aae_commit *commit = &pip_sw->commit;

	pip_sw->wb_committed = 1;
	aae_pip_preprocess(pip_sw);

	/* commit to hardware, but sometimes hardware is handling exceptions,
	 */
	aae_cmdlist_pip_commit(pip_sw->aae_mgr->aae_base, commit->scene_id, commit->cmdlist_id);
	dacc_aae_config_scene(pip_sw->aae_mgr->aae_base, commit->scene_id, true);
	aae_pip_check_wb_finish(pip_sw);
	if (pip_sw->offline_succ)
		pip_sw->offline_succ = 0;
	else
		ret = -1; // offline fail

	return ret;
}

void aae_pip_setup(struct aae_pipeline_sw *pip_sw)
{
	aae_pr_debug("+");

	aae_assert(!pip_sw);

	aae_pip_isr_setup(pip_sw);
	pip_sw->commit_func = aae_pip_commit;

	aae_pr_debug("-");
}

void aae_pip_release(struct aae_pipeline_sw *pip_sw)
{
	aae_assert(!pip_sw);

	aae_pip_isr_release(pip_sw);
}

int32_t aae_pip_parse_dt(struct aae_pipeline_sw *pip_sw, struct device_node *np)
{
	aae_assert(!pip_sw);
	return aae_pip_hw_parse_dt(pip_sw, np);
}

int32_t aae_pip_init(struct aae_pipeline_sw **pip_sw)
{
	struct aae_pipeline_sw *pip = NULL;

	aae_assert(!pip_sw);

	if (aae_pip_hw_init(pip_sw) != 0) {
		aae_pr_err("pip_sw init fail");
		return -1;
	}

	pip = *pip_sw;
	sema_init(&pip->sem, 1);
	init_waitqueue_head(&pip->wb_wq);
	
	return 0;
}

void aae_pip_deinit(struct aae_pipeline_sw **pip_sw)
{
	aae_assert(!pip_sw);

	aae_pip_hw_deinit(pip_sw);
}

void aae_pip_close(struct aae_pipeline_sw *pip_sw)
{
	aae_assert(!pip_sw);
	
	aae_pr_debug("+");
	aae_pip_hw_close(pip_sw);
	aae_pr_debug("-");
}