/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2023. All rights reserved.
 */

#include <linux/security.h>
#include <linux/version.h>
#include <linux/kthread.h>
#include <linux/device.h>

#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_dm_api.h"
#include "hvgr_platform_api.h"

void hvgr_dmd_msg_check(struct hvgr_device *gdev)
{
	struct task_struct *tsk = NULL;

	if (unlikely(gdev == NULL))
		return;

	if (gdev->dm_dev.dmd_msg->dmd_sh_flag != 0u || gdev->dm_dev.dmd_msg->dmd_fault_cnt == 0u ||
		!hvgr_dmd_need_check_nv(gdev))
		return;

	gdev->dm_dev.dmd_msg->dmd_sh_flag = 1u;

	tsk = kthread_run(hvgr_dmd_sh_process, (void *)gdev, "dmd_sh_process");
	if (IS_ERR(tsk)) {
		gdev->dm_dev.dmd_msg->dmd_sh_flag = 0u;
		hvgr_err(gdev, HVGR_DM, "higpu_dmd: sh tsk fail");
	}
}

void hvgr_dfv_health_check(struct hvgr_device *gdev)
{
	struct task_struct *tsk = NULL;

	if (unlikely(gdev == NULL))
		return;

	if (gdev->dm_dev.dmd_msg->dfv_sh_triggered || gdev->dm_dev.dmd_msg->dmd_fault_cnt == 0u ||
		gdev->dm_dev.dmd_msg->dfv_sh_enabled || !hvgr_dfv_check_time(gdev))
		return;

	gdev->dm_dev.dmd_msg->dfv_sh_triggered = true;

	tsk = kthread_run(hvgr_dmd_dfv_process, (void *)gdev, "dmd_dfv_process");
	if (IS_ERR(tsk)) {
		gdev->dm_dev.dmd_msg->dfv_sh_triggered = false;
		hvgr_err(gdev, HVGR_DM, "higpu_dmd: dfv tsk fail");
	}
}

static bool hvgr_sh_dsc_check_cnt(struct hvgr_device *gdev)
{
	struct gpu_dmd_msg *dmd_msg = gdev->dm_dev.dmd_msg;

	if (dmd_msg->dmd_dsc_cnt == 0U && dmd_msg->dmd_dsc_rollback_cnt == 0U) 
		return false;

	if (hweight32(hvgr_pm_get_availiable_cores(gdev)) < MIN_DMD_CHECK_GPC_NUM)
		return false;

	if (dmd_msg->enable_dsc_flag &&
		dmd_msg->dmd_dsc_rollback_cnt > MAX_DMD_CHECK_DSC_ROLLBACK_CNT)
		return true;

	if (!dmd_msg->enable_dsc_flag &&
		dmd_msg->dmd_dsc_cnt > MAX_DMD_CHECK_DSC_CNT &&
		hvgr_is_single_bit(dmd_msg->dmd_dsc_mask))
		return true;

	return false;
}

void hvgr_dmd_dsc_check(struct hvgr_device *gdev)
{
	struct task_struct *tsk = NULL;
	struct gpu_dmd_msg *dmd_msg = NULL;

	if (unlikely(gdev == NULL))
		return;

	dmd_msg = gdev->dm_dev.dmd_msg;

	/* Check if the feature switch is enabled */
	if (!dmd_msg->enable_sh_act || !dmd_msg->enable_sh_dsc)
		return;
	if (dmd_msg->dmd_dsc_flag != 0U ||
		!hvgr_sh_dsc_check_cnt(gdev))
		return;

	dmd_msg->dmd_dsc_flag = 1U;

	tsk = kthread_run(hvgr_dmd_sh_dsc_process, (void *)gdev, "dmd_sh_dsc_process");
	if (IS_ERR(tsk)) {
		dmd_msg->dmd_dsc_flag = 0U;
		hvgr_err(gdev, HVGR_DM, "higpu_dmd: sh dsc tsk fail");
	}
}
