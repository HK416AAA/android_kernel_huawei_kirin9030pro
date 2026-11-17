/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022.
 * All rights reserved.
 *
 * Description: This is dmd report module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <securec.h>
#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_platform_api.h"
#include "hvgr_pm_api.h"
#ifdef CONFIG_HVGR_DFX_DEBUG_BUS_DUMP
#include "hvgr_debug_bus_dump.h"
#endif

#ifdef CONFIG_HVGR_DFX_DMD_REPORT
#include <linux/version.h>
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#include <dfx_bbox_diaginfo.h>
#else
#include <platform_include/basicplatform/linux/dfx_bbox_diaginfo.h>
#endif
#endif

#ifdef CONFIG_HVGR_DFX_DMD_REPORT

static unsigned int hvgr_get_higpu_dmd_id(enum hvgr_dmd_id dmd_id)
{
	switch (dmd_id) {
	case DMD_JOB_FAIL:
		return DMD_HIGPU_JOB_FAIL;
	case DMD_JOB_HANG:
		return DMD_HIGPU_JOB_HANG;
	case DMD_FCP_LOAD_FAIL:
		return DMD_HIGPU_FCP_LOAD_FAIL;
	case DMD_BUS_FAULT:
		return DMD_HIGPU_BUS_FAULT;
	case DMD_PAGE_FAULT:
		return DMD_HIGPU_PAGE_FAULT;
	case DMD_PW_ONOFF_FAIL:
		return DMD_HIGPU_PW_ONOFF_FAIL;
	case DMD_HARD_RESET:
		return DMD_HIGPU_HARD_RESET;
#ifdef CONFIG_HVGR_DFX_SH
	case DMD_SH_NV_MARK:
		return DMD_HIGPU_SH_INFO;
#endif
	default :
		return INVALID_DMD_ID;
	}
}
int hvgr_dmd_msg_init(struct hvgr_device *gdev)
{
	struct gpu_dmd_msg *dmd_msg = NULL;

	if (gdev == NULL)
		return -EINVAL;

	dmd_msg = kzalloc(sizeof(*dmd_msg), GFP_KERNEL);
	if (dmd_msg == NULL) {
		hvgr_err(gdev, HVGR_DM, "%s kzalloc failed.", __func__);
		return -ENOMEM;
	}

	mutex_init(&dmd_msg->dmd_lock);
	atomic_set(&dmd_msg->dmd_flag, 0);
#ifdef CONFIG_HVGR_DFX_SH
	dmd_msg->dmd_sh_flag = 0;
#endif

#if defined( CONFIG_HVGR_DFX_SH) || defined(HVGR_FACTORY_MODE)
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	dmd_msg->sr_wakeup_lock = wakeup_source_register("sr wakelock");
#else
	dmd_msg->sr_wakeup_lock = wakeup_source_register(NULL, "sr wakelock");
#endif
	if (dmd_msg->sr_wakeup_lock == NULL)
		hvgr_err(gdev, HVGR_DM, "%s reg sr wakelock fail.", __func__);
#endif

	gdev->dm_dev.dmd_msg = dmd_msg;
	return 0;
}

void hvgr_dmd_msg_term(struct hvgr_device *gdev)
{
	if (gdev == NULL)
		return;

	if (gdev->dm_dev.dmd_msg == NULL)
		return;
#if defined( CONFIG_HVGR_DFX_SH) || defined(HVGR_FACTORY_MODE)
	if (gdev->dm_dev.dmd_msg->sr_wakeup_lock != NULL)
		wakeup_source_unregister(gdev->dm_dev.dmd_msg->sr_wakeup_lock);
#endif
	kfree(gdev->dm_dev.dmd_msg);
}

#ifdef CONFIG_HVGR_DFX_SH
static void hvgr_dmd_count_peri_status(struct hvgr_device *gdev, u32 higpu_dmd_id)
{
	struct gpu_dmd_msg *dmd_msg = gdev->dm_dev.dmd_msg;
	struct timespec64 cur_ts;
	u32 check_idx;

	if (!dmd_msg->enable_sh_peri)
		return;

	if (higpu_dmd_id != DMD_HIGPU_PW_ONOFF_FAIL &&
		higpu_dmd_id != DMD_HIGPU_FCP_LOAD_FAIL &&
		higpu_dmd_id != DMD_HIGPU_JOB_HANG &&
		higpu_dmd_id != DMD_HIGPU_JOB_FAIL &&
		higpu_dmd_id != DMD_HIGPU_PAGE_FAULT)
		return;

	ktime_get_boottime_ts64(&cur_ts);
	check_idx = dmd_msg->dmd_fault_peri_cnt % MAX_DMD_CHECK_PERI_CNT;
	dmd_msg->dmd_check_peri_ts[check_idx] = (u64)cur_ts.tv_sec;
	++dmd_msg->dmd_fault_peri_cnt;
	if (higpu_dmd_id == DMD_HIGPU_FCP_LOAD_FAIL)
		dmd_msg->dmd_fault_peri_idx = dmd_msg->dmd_fault_peri_cnt;

	hvgr_debug(gdev, HVGR_DM, "gpu peri fault happened %u times fcp idx %u!",
		dmd_msg->dmd_fault_peri_cnt, dmd_msg->dmd_fault_peri_idx);
}
#endif

#ifdef CONFIG_HVGR_DFX_DEBUG_BUS_DUMP
#define ACTIVE_GPC_PER_REG  8U
static uint32_t hvgr_gpc_active_to_core_mask(uint32_t active, uint32_t bitpergpc)
{
	uint32_t index = 0U;
	uint32_t core_mask = 0U;

	for (; index < ACTIVE_GPC_PER_REG; index++)
		if (((active >> (index * bitpergpc)) & ((1U << bitpergpc) - 1U)) != 0U)
			core_mask |= (1U << index);

	return core_mask;
}

static void hvgr_dmd_get_hang_mask(struct hvgr_device *gdev,
	uint32_t *core_mask, uint32_t *rend_mask, uint32_t *comp_mask)
{
	*core_mask = hvgr_pm_get_availiable_cores(gdev);
	*rend_mask = hvgr_gpc_active_to_core_mask(kdatan_debug_bus_read(gdev, 0x6800202U), 4U);
	*comp_mask = hvgr_gpc_active_to_core_mask(kdatan_debug_bus_read(gdev, 0x6800204U), 3U);

	hvgr_debug(gdev, HVGR_DM, "Active GPC mask: available 0x%x, render 0x%x, compute 0x%x",
		*core_mask, *rend_mask, *comp_mask);
}

static void hvgr_dmd_add_gpc_msg(struct hvgr_device *gdev, enum hvgr_dmd_id dmd_id,
	char *buffer, uint32_t buffer_len)
{
	int ret;
	uint32_t core_mask = 0U;
	uint32_t rend_mask = 0U;
	uint32_t comp_mask = 0U;

	if (dmd_id != DMD_JOB_HANG)
		return;

	hvgr_dmd_get_hang_mask(gdev, &core_mask, &rend_mask, &comp_mask);

	ret = snprintf_s(buffer + strlen(buffer), buffer_len - strlen(buffer),
		buffer_len - strlen(buffer) - 1U, ",A:%x,R:%x,C:%x",
		core_mask, rend_mask, comp_mask);
	if (ret <= 0)
		hvgr_err(gdev, HVGR_DM, "higpu_dmd add gpc info failed!");
}
#endif

#ifdef CONFIG_HVGR_DFX_SH
static void hvgr_dmd_dsc_set(struct hvgr_device *gdev, u32 higpu_dmd_id)
{
	struct gpu_dmd_msg *dmd_msg = gdev->dm_dev.dmd_msg;
	uint32_t mask;
	uint32_t core_mask;
#ifdef CONFIG_HVGR_DFX_DEBUG_BUS_DUMP
	uint32_t rend_mask = 0U;
	uint32_t comp_mask = 0U;
#endif

	if (!dmd_msg->enable_sh_act || !dmd_msg->enable_sh_dsc)
		return;

	if (!gdev->datan_dev.gpu_fault_msg.is_dsc_flag ||
		higpu_dmd_id == DMD_HIGPU_SH_INFO)
		return;

	if (higpu_dmd_id != DMD_HIGPU_JOB_HANG &&
		higpu_dmd_id != DMD_HIGPU_PAGE_FAULT) {
		dmd_msg->dmd_dsc_mask = 0U;
		dmd_msg->dmd_dsc_cnt = 0U;
		return;
	}

	core_mask = hvgr_pm_get_availiable_cores(gdev);
	if (higpu_dmd_id == DMD_HIGPU_PAGE_FAULT)
		mask = core_mask & gdev->datan_dev.gpu_fault_msg.fault_gpc_mask;

#ifdef CONFIG_HVGR_DFX_DEBUG_BUS_DUMP
	if (higpu_dmd_id == DMD_HIGPU_JOB_HANG) {
		hvgr_dmd_get_hang_mask(gdev, &core_mask, &rend_mask, &comp_mask);
		mask = (rend_mask | comp_mask) & core_mask;
	}
#endif
	/* only single bit is valid */
	mask = hvgr_is_single_bit(mask) ? mask : 0U;
	if (mask == 0U) {
		dmd_msg->dmd_dsc_rollback_cnt++;
		return;
	}

	if (dmd_msg->enable_dsc_flag) {
		if (dmd_msg->dmd_dsc_mask != mask)
			dmd_msg->dmd_dsc_rollback_cnt++;
		return;
	}

	if (dmd_msg->dmd_dsc_mask == mask) {
		dmd_msg->dmd_dsc_cnt++;
	} else {
		dmd_msg->dmd_dsc_mask = mask;
		dmd_msg->dmd_dsc_cnt = 1U;
	}
}
#endif

void hvgr_dmd_msg_set(struct hvgr_device *gdev, enum hvgr_dmd_id dmd_id,
	const char *dmd_log)
{
	unsigned int higpu_dmd_id = hvgr_get_higpu_dmd_id(dmd_id);
	int ret;
	struct gpu_dmd_msg *dmd_msg = NULL;
#if defined(CONFIG_HVGR_DFX_SH) || defined(CONFIG_HVGR_VIRTUAL_HOST)
	struct timespec64 cur_ts;
	u32 check_idx;
#endif

	if (gdev == NULL || dmd_log == NULL)
		return;

	dmd_msg = gdev->dm_dev.dmd_msg;

	if (higpu_dmd_id == INVALID_DMD_ID) {
		hvgr_debug(gdev, HVGR_DM, "%s higpu_dmd_id is INVALID ID.", __func__);
		return;
	}

	if (atomic_cmpxchg(&dmd_msg->dmd_flag, 0, 1) != 0) {
		hvgr_err(gdev, HVGR_DM, "higpu_dmd flag error: set %u when %u is reporting",
			dmd_id, dmd_msg->dmd_id);
		return;
	}

	if (unlikely(dmd_msg->dmd_id != INVALID_DMD_ID)) {
		hvgr_err(gdev, HVGR_DM, "higpu_dmd error: set %u when %u is reporting",
			dmd_id, dmd_msg->dmd_id);
		return;
	}

#if defined(CONFIG_HVGR_DFX_SH) || defined(CONFIG_HVGR_VIRTUAL_HOST)
	if (higpu_dmd_id == DMD_HIGPU_PW_ONOFF_FAIL ||
		higpu_dmd_id == DMD_HIGPU_FCP_LOAD_FAIL ||
		higpu_dmd_id == DMD_HIGPU_JOB_HANG ||
		higpu_dmd_id == DMD_HIGPU_HARD_RESET) {
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		get_monotonic_boottime64(&cur_ts);
#else
		ktime_get_boottime_ts64(&cur_ts);
#endif
		check_idx = dmd_msg->dmd_fault_cnt % MAX_DMD_CHECK_CNT;
		dmd_msg->dmd_check_ts[check_idx] = (u64)cur_ts.tv_sec;
		check_idx = dmd_msg->dmd_fault_cnt % MAX_DFV_CHECK_CNT;
		dmd_msg->dfv_check_ts[check_idx] = (u64)cur_ts.tv_sec;
		++dmd_msg->dmd_fault_cnt;
		hvgr_debug(gdev, HVGR_DM, "gpu fault happened %u times!",
			dmd_msg->dmd_fault_cnt);
	}

	hvgr_dmd_count_peri_status(gdev, higpu_dmd_id);
	hvgr_dmd_dsc_set(gdev, higpu_dmd_id);
#endif
	hvgr_debug(gdev, HVGR_DM, "higpu_dmd set dmd %u", dmd_id);

	ret = strncpy_s(dmd_msg->dmd_log,
		MAX_DMD_LOG_LENTH, dmd_log, strlen(dmd_log));
	if (ret != EOK)
		hvgr_err(gdev, HVGR_DM, "higpu_dmd set dmd log failed!");
#ifdef CONFIG_HVGR_DFX_DEBUG_BUS_DUMP
	hvgr_dmd_add_gpc_msg(gdev, dmd_id, dmd_msg->dmd_log, MAX_DMD_LOG_LENTH);
#endif
	dmd_msg->dmd_id = higpu_dmd_id;
}

void hvgr_dmd_msg_report(struct hvgr_device *gdev)
{
	struct gpu_dmd_msg *dmd_msg = NULL;

	if (gdev == NULL)
		return;

	dmd_msg = gdev->dm_dev.dmd_msg;
	if (dmd_msg == NULL) {
		hvgr_err(gdev, HVGR_DM, "dmd_msg is NULL.");
		return;
	}

	mutex_lock(&dmd_msg->dmd_lock);
	if (dmd_msg->dmd_id == INVALID_DMD_ID) {
		hvgr_debug(gdev, HVGR_DM, "higpu_dmd error: report invalid dmd msg");
		mutex_unlock(&dmd_msg->dmd_lock);
		return;
	}

	hvgr_debug(gdev, HVGR_DM, "higpu_dmd: report dmd %u", dmd_msg->dmd_id);

	bbox_diaginfo_record(dmd_msg->dmd_id, NULL, dmd_msg->dmd_log);
#if defined(CONFIG_HVGR_DFX_SH) || defined(CONFIG_HVGR_VIRTUAL_HOST)
	hvgr_dmd_msg_check(gdev);
	if (dmd_msg->dfv_feature_supported)
		hvgr_dfv_health_check(gdev);
	hvgr_dmd_dsc_check(gdev);
#endif
	/* init dmd msg after report */
	dmd_msg->dmd_id = INVALID_DMD_ID;
	atomic_set(&dmd_msg->dmd_flag, 0);
	mutex_unlock(&dmd_msg->dmd_lock);
}

bool hvgr_dmd_id_check(struct hvgr_device *gdev)
{
	return gdev->dm_dev.dmd_msg->dmd_id == INVALID_DMD_ID;
}

void hvgr_dmd_msg_clear(struct hvgr_device *gdev)
{
	if (hvgr_dmd_id_check(gdev))
		return;
	/* clear dmd msg after gpu reset done if dmdmsg is not null. */
	mutex_lock(&gdev->dm_dev.dmd_msg->dmd_lock);
	gdev->dm_dev.dmd_msg->dmd_id = INVALID_DMD_ID;
	atomic_set(&gdev->dm_dev.dmd_msg->dmd_flag, 0);
	mutex_unlock(&gdev->dm_dev.dmd_msg->dmd_lock);
}

void hvgr_dmd_sr_awake(struct hvgr_device *gdev)
{
	if (gdev->dm_dev.dmd_msg->sr_wakeup_lock != NULL)
		__pm_stay_awake(gdev->dm_dev.dmd_msg->sr_wakeup_lock);
}

void hvgr_dmd_sr_relax(struct hvgr_device *gdev)
{
	if (gdev->dm_dev.dmd_msg->sr_wakeup_lock != NULL)
		__pm_relax(gdev->dm_dev.dmd_msg->sr_wakeup_lock);
}

#else
int hvgr_dmd_msg_init(struct hvgr_device *gdev)
{
	return 0;
}

void hvgr_dmd_msg_term(struct hvgr_device *gdev)
{
}

void hvgr_dmd_msg_set(struct hvgr_device *gdev, enum hvgr_dmd_id dmd_id,
	const char *dmd_log)
{
}

void hvgr_dmd_msg_report(struct hvgr_device *gdev)
{
}

bool hvgr_dmd_id_check(struct hvgr_device *gdev)
{
	return true;
}

void hvgr_dmd_msg_clear(struct hvgr_device *gdev)
{
}

void hvgr_dmd_sr_awake(struct hvgr_device *gdev)
{
}

void hvgr_dmd_sr_relax(struct hvgr_device *gdev)
{
}
#endif

#define BIT32    32
#define BIT64    64
int hvgr_get_ctx_compat(struct hvgr_ctx *ctx)
{
	if (ctx == NULL)
		return 0;

	return hvgr_ctx_flag(ctx, HVGR_CTX_FLAG_COMPAT) ? BIT32 : BIT64;
}

char *hvgr_get_main_process_name(struct hvgr_ctx *ctx)
{
	if (ctx == NULL)
		return "unknown";

	if (likely(ctx->leader != NULL)) {
		if (((strlen(ctx->group_name) + 1U) == (size_t)TASK_COMM_LEN) &&
			((strlen(ctx->full_task_name) != 0U)))
			return ctx->full_task_name;
		else
			return ctx->group_name;
	}

	return ctx->process_name;
}
