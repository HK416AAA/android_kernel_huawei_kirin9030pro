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

#ifndef __AAE_DDR_DVFS_H__
#define __AAE_DDR_DVFS_H__
#include <linux/types.h>
#include <linux/semaphore.h>
#include "ukmd_chrdev.h"

#define AAE_DDR_DVFS_TGID_MAX 5
struct aae_bw_vote_node {
	struct list_head list_node;
    uint64_t bw;
    uint32_t uid;
	uint32_t tgid_cnt;
	int32_t user_tgid[AAE_DDR_DVFS_TGID_MAX];
	atomic_t ref_cnt;
};

struct aae_ddr_bw_mgr {
	struct list_head vote_bw_list;
	struct semaphore sem;
};

void aae_res_register_ddr_dvfs(struct list_head *res_head);

#endif
