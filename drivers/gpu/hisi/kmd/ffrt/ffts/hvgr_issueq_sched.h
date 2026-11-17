/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_ISSUEQ_SCHED_H
#define HVGR_ISSUEQ_SCHED_H

void hvgr_issueq_submit(void);

void hvgr_issueq_unsubmit(void);

int hvgr_issueq_sched_init(struct hvgr_device * const gdev);

void hvgr_issueq_sched_term(struct hvgr_device *gdev);

void hvgr_issueq_unsubmit_sync_nolock(struct hvgr_device * const gdev);

int hvgr_issueq_debugfs_init(struct hvgr_device * const gdev);

void hvgr_issueq_unmap_all_ctx(struct hvgr_device * const gdev);

void hvgr_issueq_map_all_ctx(struct hvgr_device * const gdev);

#endif
