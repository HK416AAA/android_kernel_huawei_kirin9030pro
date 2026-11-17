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

#ifndef AKMD_PIP_H
#define AKMD_PIP_H

#include <linux/types.h>
#include <linux/semaphore.h>
#include <linux/workqueue.h>
#include <platform_include/display/akmd/akmd_aae.h>
#include "akmd_isr.h"
#include "ukmd_timeline.h"

enum akmd_aae_pipeline_type {
	AAE_PIP_0,
	AAE_PIP_MAX,
};

struct aae_pipeline_sw {
	uint32_t index;
	uint32_t commit_index;
	bool power_on;
	struct semaphore sem;
	struct aae_manager *aae_mgr;

	uint32_t wb_done;
	uint32_t offline_succ;
	uint32_t wb_committed;
	wait_queue_head_t wb_wq;
	struct aae_commit commit;
	struct ukmd_dma_buf layer_dma_buf[AAE_LAYER_MAX_COUNT];
	struct workqueue_struct *aae_exp_wq;
	struct work_struct aae_exp_work;

	int32_t (*on_func_no_lock)(struct aae_pipeline_sw *pip_sw);
	int32_t (*off_func_no_lock)(struct aae_pipeline_sw *pip_sw);
	void (*reset_func)(struct aae_pipeline_sw *pip_sw);
	int32_t (*commit_func)(struct aae_pipeline_sw *pip_sw);
	int32_t (*ops_handle_func)(struct aae_pipeline_sw *pip_sw, uint32_t ops_cmd_id, void *value);
};

#endif /* AKMD_PIP_H */
