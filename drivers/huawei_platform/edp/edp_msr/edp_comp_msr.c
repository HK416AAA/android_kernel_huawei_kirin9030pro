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

#include <linux/delay.h>
#include <linux/slab.h>
#include "edp_comp_msr.h"
#include "edp_drv/edp_panel_drv.h"
#include "edp_log.h"
#include "tcon_i2c/tcon_i2c.h"
#include "dkmd_dp_interface.h"

#define MSEC_DELAY_HSD 600
#define MSR_SWITCH_ADDR 0XF10100F4
#define ENTER_MSR_VAL 0x1A2A3A4A
#define EXIT_MSR_VAL 0x1B2B3B4B

static int32_t edp_multi_screen_switch(bool is_msr)
{
	int ret = 0;

	edp_info("[msr] enter msr:%d", is_msr);
	mutex_lock(&tcon_i2c_mutex);
	if (is_msr) {
		ret = tcon_i2c_write_addr(MSR_SWITCH_ADDR, ENTER_MSR_VAL);
	} else {
		ret = tcon_i2c_write_addr(MSR_SWITCH_ADDR, EXIT_MSR_VAL);
	}
	mutex_unlock(&tcon_i2c_mutex);

	if (ret < 0) {
		edp_err("[msr] write addr failed\n");
		return -EINVAL;
	}

	return ret;
}

void edp_print_msr_ctrl_info(struct edp_comp_msr_ctrl *msr_ctrl)
{
    if (msr_ctrl == NULL) {
        edp_err("[msr] msr_ctrl is NULL\n");
        return;
    }

    edp_info("[msr] is_msr:%d, is_power_on:%d, left:%u, top:%u, right:%u, bottom:%u]\n",
        msr_ctrl->is_msr, msr_ctrl->is_power_on,
        msr_ctrl->display_region.left, msr_ctrl->display_region.top,
        msr_ctrl->display_region.right, msr_ctrl->display_region.bottom);
}

static int32_t edp_msr_state_check(struct edp_comp_msr_ctrl *msr_ctrl, struct edp_rect_coord *display_region)
{
    int ret = 0;
    bool is_msr;

    if (msr_ctrl == NULL) {
        edp_err("[msr] msr_ctrl is NULL\n");
        return -EINVAL;
    }

    if (display_region == NULL) {
        edp_err("[msr]display region is NULL\n");
        return -EINVAL;
    }

    if (display_region->left == 0 && display_region->top == 0 &&
        display_region->right == msr_ctrl->region.right && display_region->bottom == msr_ctrl->region.bottom) {
        is_msr = false;
    } else if (display_region->left == msr_ctrl->region.left && display_region->top == msr_ctrl->region.top &&
               display_region->right == msr_ctrl->region.right &&
               display_region->bottom == (msr_ctrl->region.bottom / 2)) {
        is_msr = true;
    } else {
            edp_warn("[msr] invalid region region[%u, %u, %u, %u]",
                display_region->left, display_region->top,
                display_region->right, display_region->bottom);
            return -EINVAL;
    }

    if (msr_ctrl->is_msr == is_msr) {
        edp_err("[msr] msr state not change, is_msr:%d\n", is_msr);
        edp_print_msr_ctrl_info(msr_ctrl);
        return ret;
    }

    edp_print_msr_ctrl_info(msr_ctrl);
    msr_ctrl->is_msr = is_msr;
    msr_ctrl->display_region = *display_region;
    edp_print_msr_ctrl_info(msr_ctrl);
    return ret;
}

static void edp_msr_preprocess_work_func(struct work_struct *work)
{
    struct edp_comp_msr_ctrl *msr_ctrl = NULL;

    if (work == NULL) {
        edp_err("[msr] work is NUL\n");
        return;
    }

    msr_ctrl = container_of(work, struct edp_comp_msr_ctrl, msr_preprocess_work);
    if (!msr_ctrl->is_power_on) {
        edp_err("[msr] power off, do not preprocess\n");
        return;
    }

    mdelay(MSEC_DELAY_HSD); //dealy 600 ms
}

static void edp_msr_switch_work_func(struct work_struct *work)
{
    struct edp_comp_msr_ctrl *msr_ctrl = NULL;

    if (work == NULL) {
        edp_err("[msr] work is NUL\n");
        return;
    }

    msr_ctrl = container_of(work, struct edp_comp_msr_ctrl, msr_switch_work);

    mutex_lock(&msr_ctrl->msr_lock);
    if (!msr_ctrl->is_power_on) {
        edp_err("[msr] power off, remaining switch_work works, do not switch\n");
        goto err_out;
    }

    if (work_pending(&msr_ctrl->msr_preprocess_work)) {
        edp_err("[msr] remaining switch_work works after power on, do not switch\n");
        goto err_out;
    }

    edp_multi_screen_switch(msr_ctrl->is_msr);

err_out:
    mutex_unlock(&msr_ctrl->msr_lock);
    return;
}

static int32_t edp_msr_preprocess(struct edp_comp_msr_ctrl *msr_ctrl)
{
    if (msr_ctrl == NULL) {
        edp_err("[msr] msr_ctrl is NULL\n");
        return -EINVAL;
    }

    if (msr_ctrl->msr_switch_wq == NULL) {
        edp_err("[msr] msr_switch_wq is NULL\n");
        return -EINVAL;
    }

    if (work_pending(&msr_ctrl->msr_preprocess_work) &&
        cancel_work_sync(&msr_ctrl->msr_preprocess_work)) {
        edp_info("[msr] cancel msr_preprocess_work success\n");
    }

    queue_work(msr_ctrl->msr_switch_wq, &msr_ctrl->msr_preprocess_work);
    return 0;
}

static int32_t edp_msr_set_display_active_region(struct edp_comp_msr_ctrl *msr_ctrl, struct edp_rect_coord *region)
{
    int ret = 0;

    if (msr_ctrl == NULL) {
        edp_err("[msr] msr_ctrl is NULL\n");
        return -EINVAL;
    }

    if (region == NULL) {
        edp_err("[msr] region is NULL\n");
        return -EINVAL;
    }

    if (edp_msr_state_check(msr_ctrl, region) != 0) {
        edp_err("[msr] msr_state_check failed\n");
        return -EINVAL;
    }

    if (!msr_ctrl->is_power_on) {
        edp_info("[msr] power off, do not switch\n");
        return ret;
    }

    if (msr_ctrl->msr_switch_wq == NULL) {
        edp_err("[msr] msr_switch_wq is NULL\n");
        return -EINVAL;
    }

    if (work_pending(&msr_ctrl->msr_switch_work) &&
        cancel_work_sync(&msr_ctrl->msr_switch_work)) {
        edp_info("[msr] cancel msr_switch_work success\n");
    }

    queue_work(msr_ctrl->msr_switch_wq, &msr_ctrl->msr_switch_work);
    return ret;
}

void edp_comp_msr_setup(struct edp_comp_msr_ctrl *msr_ctrl)
{
    int ret = 0;

    msr_ctrl->is_msr = false;
    msr_ctrl->is_power_on = false;
    msr_ctrl->preprocess = edp_msr_preprocess;
    msr_ctrl->set_display_active_region = edp_msr_set_display_active_region;
    mutex_init(&msr_ctrl->msr_lock);
    edp_info("[msr] msr_ctrl init success\n");

    msr_ctrl->msr_switch_wq = alloc_ordered_workqueue("msr_switch_wq", WQ_HIGHPRI | WQ_UNBOUND);
    if (msr_ctrl->msr_switch_wq == NULL) {
        edp_err("[msr] create msr_switch_wq failed\n");
        return;
    }

    INIT_WORK(&msr_ctrl->msr_preprocess_work, edp_msr_preprocess_work_func);
    INIT_WORK(&msr_ctrl->msr_switch_work, edp_msr_switch_work_func);
}