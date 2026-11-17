/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_cq.h"

#include "hvgr_cq_schedule.h"
#include "hvgr_pm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_hts_api.h"
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#include "hvgr_mcu_common.h"
#endif
#if hvgr_fe_enabled(HVGR_FE_FFTS)
#include "hvgr_ffts_api.h"
#endif

static irqreturn_t hvgr_cq_irq_handle(struct hvgr_device * const gdev, uint32_t irq_top)
{
	if ((irq_top & HVGR_CQ_NORMAL_Q_IRQ_MASK) == 0)
		return IRQ_NONE;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY) {
		hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
		hvgr_cq_schedule_irq(gdev);
		hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
		return IRQ_HANDLED;
	} else {
		hvgr_err(gdev, HVGR_CQ, "%s gpu_pm_sts=%d, not excepted, ignore cq irq.",
			__func__, hvgr_pm_get_gpu_status(gdev));
		return IRQ_NONE;
	}
}

#if defined(HVGR_FEATURE_HTS) && HVGR_FEATURE_HTS != 0
static irqreturn_t hvgr_hts_irq_handle(struct hvgr_device * const gdev)
{
	uint32_t irq_no_consumer;

	irq_no_consumer = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_IRQ_TOP_STATUS));
	if ((irq_no_consumer & NO_CONSUMER_IRQ) == 0)
		return IRQ_NONE;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY ||
		hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPC_POWERING_OFF ||
		hvgr_pm_get_gpu_status(gdev) == HVGR_PM_POWER_ON) {
		hvgr_hts_no_consumer_irq(gdev, irq_no_consumer);
		return IRQ_HANDLED;
	} else {
		hvgr_err(gdev, HVGR_CQ, "%s gpu_pm_sts=%d, not excepted, ignore hts irq.",
			__func__, hvgr_pm_get_gpu_status(gdev));
		return IRQ_NONE;
	}
}
#endif

#if hvgr_fe_enabled(HVGR_FE_FFTS)
static irqreturn_t hvgr_issueq_irq_handle(struct hvgr_device * const gdev, uint32_t irq_top)
{
	if ((irq_top & CQ_IRQ_STATUS_ISSUEQ_MASK) == 0)
		return IRQ_NONE;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY) {
		hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
		hvgr_issueq_irq_proc(gdev);
		hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
		return IRQ_HANDLED;
	} else {
		hvgr_err(gdev, HVGR_CQ, "%s gpu_pm_sts=%d, not excepted, ignore issueq irq.",
			__func__, hvgr_pm_get_gpu_status(gdev));
		return IRQ_NONE;
	}
}
#endif

irqreturn_t hvgr_cq_irq_handler(int irq, void *data)
{
	struct hvgr_device * const gdev = (struct hvgr_device * const)data;
	irqreturn_t ret = IRQ_HANDLED;
	uint32_t irq_top;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_POWER_OFF ||
		hvgr_pm_get_gpu_status(gdev) == HVGR_PM_CORE_ERROR) {
		hvgr_err(gdev, HVGR_CQ, "%s gpu_pm_sts=%d, not excepted, ignore irq.",
			__func__, hvgr_pm_get_gpu_status(gdev));
		return IRQ_NONE;
	}

	irq_top = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_IRQ_TOP));
	while (irq_top != 0) {
#if defined(HVGR_FEATURE_HTS) && HVGR_FEATURE_HTS != 0
		ret |= hvgr_hts_irq_handle(gdev);
#endif
#if hvgr_fe_enabled(HVGR_FE_FFTS)
		ret |= hvgr_issueq_irq_handle(gdev, irq_top);
#endif
		ret |= hvgr_cq_irq_handle(gdev, irq_top);
		irq_top = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_IRQ_TOP));
	}

	return ret;
}