/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/mutex.h>
#include <linux/platform_device.h>
#include <linux/wait.h>

#include "hvgr_sch_api.h"

#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_platform_api.h"
#include "hvgr_datan_api.h"
#include "hvgr_pm_defs.h"
#include "hvgr_pm_dvfs.h"
#include "hvgr_pm_power.h"
#include "hvgr_sch_dfx.h"
#include "hvgr_hts_api.h"
#include "hvgr_mem_api.h"

#define HVGR_SUSPEND_TEST_TIMEOUT (1 * HZ)      /* 1s */

static inline bool hvgr_gpu_is_power_off(struct hvgr_device *gdev)
{
	return gdev->pm_dev.pm_pwr.cur_status == HVGR_PM_POWER_OFF;
}

int hvgr_pm_suspend(struct hvgr_device *gdev)
{
	int ret;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	hvgr_systrace_begin("%s get power_lock", __func__);
	mutex_lock(&pm_pwr->power_lock);
	hvgr_systrace_end();
	atomic_set(&pm_pwr->sr_state, HVGR_PM_SUSPENDING);
	mutex_unlock(&pm_pwr->power_lock);
	/*
	 * Suspend job scheduler and associated components, so that
	 * it releases all the PM active count references
	 */
	ret = hvgr_sch_suspend(gdev);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_CQ, "%s submit_allow=%d,sch_switch_kref=%d.\n", __func__,
			gdev->cq_dev.submit_allow, atomic_read(&gdev->cq_dev.sch_switch_kref));
		hvgr_sch_stop(gdev);
		hvgr_err(gdev, HVGR_PM, "cq suspend timeout.");
	}


	hvgr_pm_power_off_sync(gdev);
	ret = (int)wait_event_timeout(pm_pwr->power_off_done_wait,
		hvgr_gpu_is_power_off(gdev), HVGR_SUSPEND_TEST_TIMEOUT);
	if (ret == 0) {
		hvgr_err(gdev, HVGR_PM, " %s suspend 1s timeout.ref=%d cur_sts=%d wq_sts=(%u:%u:%u)",
			__func__, atomic_read(&pm_pwr->user_ref), pm_pwr->cur_status,
			gdev->pm_dev.wq_status.start_flush,
			gdev->pm_dev.wq_status.wq_begin,
			gdev->pm_dev.wq_status.wq_end);
		wait_event(pm_pwr->power_off_done_wait, hvgr_gpu_is_power_off(gdev));
	}
	atomic_set(&pm_pwr->sr_state, HVGR_PM_SUSPENDED);
	hvgr_hts_power_ref_dec(gdev);
#ifndef CONFIG_GPUFREQ_INDEPDENT
	hvgr_pm_cancel_timer(gdev);
#endif

#if hvgr_version_eq(350)
	hvgr_mem_recycle_pt(gdev);
#endif

	return 0;
}

void hvgr_pm_resume(struct hvgr_device *gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	hvgr_systrace_begin("%s", __func__);
	atomic_set(&pm_pwr->sr_state, HVGR_PM_RESUMEING);
	hvgr_hts_power_ref_inc(gdev);
	/*
	 * The AS needs to be refreshed after being resumed.
	 * AS will be refreshed during the GPU power-on process.
	 */
	(void)hvgr_pm_request_gpu(gdev, false);
	hvgr_sch_resume(gdev);
	hvgr_pm_release_gpu(gdev);

#ifndef CONFIG_GPUFREQ_INDEPDENT
	hvgr_pm_start_timer(gdev);
#endif
	atomic_set(&pm_pwr->sr_state, HVGR_PM_ACTIVE);
	hvgr_systrace_end();
}

bool hvgr_pm_is_suspending(struct hvgr_device *gdev)
{
	int sr_state;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	sr_state = atomic_read(&pm_pwr->sr_state);
	if (sr_state == HVGR_PM_SUSPENDED || sr_state == HVGR_PM_SUSPENDING)
		return true;

	return false;
}
