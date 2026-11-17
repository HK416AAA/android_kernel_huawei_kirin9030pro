/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#include <linux/string.h>
#include <linux/unistd.h>
#include <linux/fcntl.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/zlib.h>
#include <linux/syscalls.h>

#include "dpu/soc_dpu_define.h"
#include "dpu_comp_vsync.h"
#include "dkmd_log.h"
#include "ukmd_dacc_log_funcs.h"
#include "dpu_dacc_log_read.h"

static struct ukmd_dacc_log_dump_infos g_dpu_dacc_log_info;

void dpu_dacc_log_read_init(char __iomem *dpu_base)
{
	dpu_pr_info("dpu dacc log init");
	ukmd_dacc_log_read_init(dpu_base, DACC_OFFSET, DPU_DACC_LOG, &g_dpu_dacc_log_info);
}

void dpu_dacc_log_read_deinit(void)
{
	dpu_pr_info("dpu dacc log deinit");
	ukmd_dacc_log_read_deinit(&g_dpu_dacc_log_info);
}

static void dpu_dacc_log_read(struct kthread_work *work)
{
	struct composer_manager *comp_mgr = NULL;

	dpu_pr_debug("read log work");
	comp_mgr = container_of(work, struct composer_manager, dpu_dacc_log_work);
	dpu_check_and_no_retval(!comp_mgr, err, "comp_mgr is NULL");

	/* exit idle when dump dpu dacc's reg */
	dpu_comp_active_vsync(comp_mgr->dpu_comps[DEVICE_COMP_PRIMARY_ID]);
	ukmd_read_dacc_log_to_file(&g_dpu_dacc_log_info);
	dpu_comp_deactive_vsync(comp_mgr->dpu_comps[DEVICE_COMP_PRIMARY_ID]);
}

/*
* set up thread for dpu dacc log read
*/
void dpu_dacc_log_thread_setup(struct composer_manager *comp_mgr)
{
	dpu_pr_info("create and wake up dacc log thread");
	dpu_check_and_no_retval(!comp_mgr, err, "comp_mgr is NULL");
	kthread_init_worker(&comp_mgr->dpu_dacc_log_worker);
	kthread_init_work(&comp_mgr->dpu_dacc_log_work, dpu_dacc_log_read);
	comp_mgr->dpu_dacc_log_thread = kthread_create(kthread_worker_fn, &comp_mgr->dpu_dacc_log_worker, "dacc log thread");
	if (IS_ERR_OR_NULL(comp_mgr->dpu_dacc_log_thread)) {
		dpu_pr_err("failed to create dpu dacc log thread!");
		comp_mgr->dpu_dacc_log_thread = NULL;
		return;
	}
	wake_up_process(comp_mgr->dpu_dacc_log_thread);
}

/*
* relseae thread for dpu dacc log read
*/
void dpu_dacc_log_thread_release(struct composer_manager *comp_mgr)
{
	dpu_pr_info("release log thread");
	dpu_check_and_no_retval(!comp_mgr, err, "comp_mgr is NULL");
	if (IS_ERR_OR_NULL(comp_mgr->dpu_dacc_log_thread))
		return;

	kthread_stop(comp_mgr->dpu_dacc_log_thread);
	comp_mgr->dpu_dacc_log_thread = NULL;
}

void dpu_mdp_dacc_log_isr_handler(struct composer_manager *comp_mgr)
{
	dpu_pr_debug("dacc log isr");
	dpu_check_and_no_retval(!comp_mgr, err, "comp_mgr is NULL");
	kthread_queue_work(&comp_mgr->dpu_dacc_log_worker, &comp_mgr->dpu_dacc_log_work);
}

/* trans frm idx to dacc */
void dpu_dacc_log_trans_frm_idx(char __iomem *dpu_base, uint32_t frame_index, uint32_t scene_id)
{
	writel(frame_index, dpu_base + DACC_OFFSET + DACC_LOG_OFFSET_FRM_INDX(scene_id));
}

/*
* ecall dump dpu dacc' reserved log, which cannot be read by 
* buf full irq
*/
uint32_t dpu_dacc_dump_reserved_log(void)
{
	return ukmd_dacc_dump_reserved_log(&g_dpu_dacc_log_info);
}
EXPORT_SYMBOL_GPL(dpu_dacc_dump_reserved_log);

/*
*	for exception dump or ecall, dump all dpu dacc' s log, 
*	poen dacc's overwrite
*/
#ifdef CONFIG_MDFX_KMD
uint32_t dpu_exception_dacc_log_dump(void)
{
	return ukmd_exception_dacc_log_dump(&g_dpu_dacc_log_info);
}
EXPORT_SYMBOL_GPL(dpu_exception_dacc_log_dump);
#endif

