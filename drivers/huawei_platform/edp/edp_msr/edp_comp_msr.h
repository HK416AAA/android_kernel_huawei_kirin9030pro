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

#ifndef __EDP_COMP_MSR_H__
#define __EDP_COMP_MSR_H__

#include <linux/mutex.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include "edp_sysfs/edp_sysfs_common.h"

struct edp_rect_coord {
    uint32_t left;
    uint32_t top;
    uint32_t right;
    uint32_t bottom;
};

struct edp_comp_msr_ctrl {
    struct workqueue_struct *msr_switch_wq;
    struct work_struct msr_preprocess_work;
    struct work_struct msr_switch_work;
    struct mutex msr_lock;
    struct edp_rect_coord region;
    struct edp_rect_coord display_region;
    uint32_t is_multi_screen_support;
    bool is_power_on;
    bool is_msr;

    int32_t (*preprocess)(struct edp_comp_msr_ctrl *msr_ctrl);
    int32_t (*set_display_active_region)(struct edp_comp_msr_ctrl *msr_ctrl, struct edp_rect_coord *region);
};

void edp_comp_msr_setup(struct edp_comp_msr_ctrl *msr_ctrl);
void edp_print_msr_ctrl_info(struct edp_comp_msr_ctrl *msr_ctrl);

#endif