/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_dm_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_hts_api.h"

#include "hvgr_regmap.h"
#include "hvgr_dm_ctx.h"

#include "hvgr_pm_defs.h"
#include "hvgr_pm_dfx.h"

#include "hvgr_pm_driver.h"
#include "hvgr_pm_driver_base.h"
#include "hvgr_pm_driver_adapt_defs.h"
#include "hvgr_dm_comm_ctx.h"

#if hvgr_version_eq(350)
/*
 * ITCM size is 24K, the reg default value is 0x3000.
 * we set 0x4000 here means that reserve 16K for firmware self,
 * and the other 8k for const folding job.
 * If changed this value, the jmcp and compiler must be checked.
 */
#define ITCM_CFJ_START_ADDR          0x4000
#endif

bool hvgr_pm_driver_unreset_cores(struct hvgr_device *gdev)
{
	bool ret = true;
	uint64_t start_time;
	uint64_t dfx_time;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	start_time = hvgr_start_timing();
	dfx_time = hvgr_pm_dfx_get_curtime(gdev);

	if (hvgr_pm_fast_pwr_is_enable(gdev)) {
		if (pm_pwr->entire_booting) {
			/* For the first entire booting, fast_pwr is needed */
			pm_pwr->entire_booting = false;
			ret = (hvgr_pm_fast_pwr_on_and_wait_done(gdev) == 0);
		} else {
			/* If auto gpc is enabled, nothing need to do. */
			if (hvgr_pm_auto_gpc_is_enable(gdev))
				hvgr_info(gdev, HVGR_PM, "%s auto gpc power on", __func__);
			else
				ret = (hvgr_pm_fast_pwr_on_and_wait_done(gdev) == 0);
		}
	} else {
		ret = hvgr_pm_driver_gpc_pwr_on_cc(gdev);
	}

	hvgr_pm_dfx_core_on_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Unreset core");

	return ret;
}

bool hvgr_pm_driver_reset_cores(struct hvgr_device *gdev)
{
	bool ret = true;
	uint64_t start_time;
	uint64_t dfx_time;

	dfx_time = hvgr_pm_dfx_get_curtime(gdev);
	start_time = hvgr_start_timing();

	if (hvgr_pm_auto_gpc_is_enable(gdev)) {
		hvgr_info(gdev, HVGR_PM, "auto gpc power off");
		goto exit;
	}

	if (hvgr_pm_fast_pwr_is_enable(gdev)) {
		hvgr_info(gdev, HVGR_PM, "fast pwr power off");
		hvgr_pm_fast_pwr_off(gdev);
		goto exit;
	}

	ret = hvgr_pm_driver_gpc_pwr_off_cc(gdev);

exit:
	hvgr_pm_dfx_core_off_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Reset core");

	return ret;
}

bool hvgr_pm_wait_gpc_poweroff_ready(struct hvgr_device *gdev, bool force)
{
	bool ret = false;

	if (!hvgr_pm_fast_pwr_is_enable(gdev))
		return hvgr_pm_driver_wait_gpc_pwr_off_cc(gdev);

	if (hvgr_pm_auto_gpc_is_enable(gdev) && !force) {
		hvgr_info(gdev, HVGR_PM, "%s auto gpc bypass", __func__);
		return true;
	}

	if (hvgr_pm_fast_pwr_wait_done(gdev, false) == 0) {
		ret = true;
		hvgr_info(gdev, HVGR_PM, "Reset core succeeded.");
	} else {
		ret = false;
		hvgr_err(gdev, HVGR_PM, "Reset GPC failed when powering off gpc.");
	}

	return ret;
}

static void hvgr_pm_driver_config_before_boot(struct hvgr_device *gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	pm_pwr->entire_booting = true;
	/* set config value to real ctrl flag */
	atomic_set(&pm_pwr->cur_policy, pm_pwr->cur_policy_tmp);
	pm_pwr->tool_hwcnt = pm_pwr->tool_hwcnt_tmp;

	hvgr_pm_fast_pwr_request(gdev);
}

bool hvgr_pm_driver_gpu_config(struct hvgr_device *gdev)
{
	hvgr_pm_driver_config_before_boot(gdev);

	if (!hvgr_pm_driver_gpu_config_base(gdev))
		return false;
#if hvgr_version_eq(500)
	gdev->pm_dev.pm_pwr.rtu_pw_state = false;
	if ((!gdev->pm_dev.pm_pwr.sw_auto_rtu_enable) ||
		(atomic_read(&gdev->pm_dev.pm_pwr.cur_policy) == HVGR_PM_ALWAYS_ON)) {
		hvgr_pm_driver_update_rtu_status(gdev, RTU_PWRON_CMD, hvgr_pm_is_core_ready);
		gdev->pm_dev.pm_pwr.rtu_pw_state = true;
	}
#endif
	/* register should be set after config_common */
	if (hvgr_pm_auto_gpc_is_enable(gdev))
		hvgr_pm_auto_gpc_switch(gdev, true);
	else
		hvgr_pm_auto_gpc_switch(gdev, false);

	hvgr_dm_comm_ctx_enable(gdev);

	return true;
}

static void hvgr_pm_driver_set_core_mask_auto_gpc(struct hvgr_device *gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	hvgr_info(gdev, HVGR_PM, "%s enter", __func__);
	/* auto gpc, wait power off */
	if (hvgr_pm_fast_pwr_wait_done(gdev, false) != 0) {
		hvgr_err(gdev, HVGR_PM, "%s wait pwr off failed", __func__);
		return;
	}

	/* power on */
	hvgr_pm_fast_pwr_update_cores(gdev, pm_pwr->core_mask_desire);
	if (hvgr_pm_auto_gpc_wait_pwr_on_done(gdev) != 0) {
		hvgr_err(gdev, HVGR_PM, "%s wait pwr on failed", __func__);
		return;
	}
}

static void hvgr_pm_driver_set_core_mask_fast_pwr(struct hvgr_device *gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	hvgr_info(gdev, HVGR_PM, "%s enter", __func__);
	/* power off and wait */
	hvgr_pm_fast_pwr_off(gdev);
	if (hvgr_pm_fast_pwr_wait_done(gdev, false) != 0) {
		hvgr_err(gdev, HVGR_PM, "%s wait pwr off failed", __func__);
		return;
	}

	/* power on */
	hvgr_pm_fast_pwr_update_cores(gdev, pm_pwr->core_mask_desire);
	if (hvgr_pm_fast_pwr_wait_done(gdev, true) != 0) {
		hvgr_err(gdev, HVGR_PM, "%s wait pwr on failed", __func__);
		return;
	}
}

void hvgr_pm_driver_set_core_mask(struct hvgr_device *gdev)
{
	if (!hvgr_pm_fast_pwr_is_enable(gdev))
		return hvgr_pm_driver_set_core_mask_cc(gdev);

	if (hvgr_pm_auto_gpc_is_enable(gdev))
		hvgr_pm_driver_set_core_mask_auto_gpc(gdev);
	else
		hvgr_pm_driver_set_core_mask_fast_pwr(gdev);
}

static void hvgr_pm_driver_cbit_call_en(struct hvgr_device *gdev)
{
	uint32_t fcm_cfg;

	fcm_cfg = hvgr_read_reg(gdev, misc_control_reg(gdev, FCM_CONFIG_0));
	fcm_cfg |= FCM_CFG0_CALL_EN;
#if hvgr_version_eq(500) || hvgr_version_eq(520) || hvgr_version_eq(600)
	fcm_cfg |= FCM_CFG0_ST2_CLOSE;
#endif
	hvgr_write_reg(gdev, misc_control_reg(gdev, FCM_CONFIG_0), fcm_cfg);
}

#if hvgr_version_eq(350)
static void hvgr_pm_driver_set_itcm_cfj_start(struct hvgr_device *gdev)
{
	hvgr_fast_pwr_write_reg(gdev, misc_control_reg(gdev, FCM_CONFIG_2), ITCM_CFJ_START_ADDR);
}
#endif




void hvgr_pm_driver_cbit_config(struct hvgr_device *gdev)
{
	hvgr_pm_driver_cbit_config_base(gdev);

	hvgr_pm_driver_cbit_call_en(gdev);

#if hvgr_version_eq(350)
	hvgr_pm_driver_set_itcm_cfj_start(gdev);
#endif



	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2MCU0_MASKINT,
		FCP_INT_UNMASK);
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2MCU1_MASKINT,
		FCP_INT_UNMASK);
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2FCM_MASKINT,
		FCP_INT_MASK);
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2HOST_MASKINT,
		FCP_INT_UNMASK);
}

int hvgr_pm_driver_clock_on(struct hvgr_device *gdev)
{
	hvgr_pm_driver_config_before_boot(gdev);

	if (hvgr_pm_driver_clock_on_base(gdev) != HVGR_PM_OK)
		return HVGR_PM_CORE_FAIL;

	/* register should be set after clock_on_common */
	if (hvgr_pm_fast_pwr_is_enable(gdev))
		hvgr_write_reg(gdev, misc_control_reg(gdev, GPC_PARA_NUM),
			HVGR_MAX_GPC_NUM_POWER_UPDATE_ONCE);

	if (hvgr_pm_auto_gpc_is_enable(gdev))
		hvgr_pm_auto_gpc_switch(gdev, true);
	else
		hvgr_pm_auto_gpc_switch(gdev, false);

	hvgr_dm_comm_ctx_enable(gdev);
	hvgr_hts_load_event_table(gdev);

	return HVGR_PM_OK;
}

int hvgr_pm_driver_clock_off(struct hvgr_device *gdev)
{
	return hvgr_pm_driver_clock_off_base(gdev);
}
