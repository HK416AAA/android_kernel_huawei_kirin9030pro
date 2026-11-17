/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_FFTS_API_H
#define HVGR_FFTS_API_H

#include "hvgr_ffts_defs.h"

bool hvgr_issueq_alloc(struct hvgr_ctx *const ctx);

void hvgr_issueq_free(struct hvgr_ctx *const ctx);

int hvgr_ffts_init(struct hvgr_device * const gdev);

void hvgr_ffts_term(struct hvgr_device *gdev);

bool hvgr_issueq_is_idle(struct hvgr_device * const gdev);

/*
 * @brief issueq irq process with sch lock
 */
void hvgr_issueq_irq_proc(struct hvgr_device * const gdev);

/*
 * @brief submit issue queue from inner processs with sch lock
 */
void hvgr_issueq_submit_inner_proc(struct hvgr_device * const gdev);

/*
 * @brief unsubmit issue queue when reset end with sch lock,
 * waiting until issueq idle
 */
void hvgr_issueq_reset_job_done_proc(struct hvgr_device * const gdev);

/*
 * @brief unsubmit issue queue from inner processs with sch lock
 */
void hvgr_issueq_unsubmit_inner_proc(struct hvgr_device * const gdev);

/*
 * @brief unsubmit issue queue from inner processs without sch lock
 */
void hvgr_issueq_unsubmit_inner_proc_nolock(struct hvgr_device * const gdev);

/*
 * @brief config issueq task when power on
 */
void hvgr_issueq_task_config(struct hvgr_device *gdev);

#endif