/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2026-2026. All rights reserved.
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
#include "dpu_comp_abnormal_handle.h"
#include <securec.h>
#include <platform_include/display/linux/dpu_improve_yield.h>
#include <platform_include/basicplatform/linux/improve_yield.h>
#include <platform_include/basicplatform/linux/ipc_rproc.h>
#include <platform_include/basicplatform/linux/ipc_msg.h>
#include "vcodec_improve_yield.h"
#include "dkmd_log.h"

#define DPU_IY_NV_INFO_MAX_LENGTH 256
#define DIAGINFO_MBX_MSG_LEN 2
#define PSCI_MSG_TYPE_AP_MEDIA1_IY IPC_CMD(OBJ_AP, OBJ_LPM3, CMD_INQUIRY, 9)

#if defined(CONFIG_DFX_IMPROVE_YIELD) && defined(CONFIG_FACTORY_MODE)
int dpu_set_iy_nv_flag(void)
{
	/* The current platform use vdec NV, and it will be changed to Media1 in the next platform. */
	improve_yield_vdec_info nvData = {};
	int ret = get_improve_yield_nv_info(MODULE_ID_VDEC, (char *)&nvData, sizeof(improve_yield_vdec_info));
	if (ret != 0) {
		dpu_pr_err("get nv info fail, ret = %d", ret);
		return ret;
	}

	nvData.nv_flag.bits.dpu_pv_flag = 1;
	nvData.nv_flag.bits.pv_flag = 1;

	ret = set_improve_yield_nv_info(MODULE_ID_VDEC, (char *)&nvData, sizeof(improve_yield_vdec_info));
	if (ret != 0) {
		dpu_pr_err("set nv info fail, ret = %d", ret);
		return ret;
	}

	dpu_pr_info("set nv info succ");
	return ret;
}

int dpu_register_iy_nvme(char *buffer, unsigned int *length)
{
	if (buffer == NULL || length == NULL) {
		dpu_pr_err("input param invalid");
		return -EINVAL;
	}

	*length = 0;
	/* The current platform use vdec NV, and it will be changed to Media1 in the next platform. */
	improve_yield_vdec_info nvData = {};
	int ret = get_improve_yield_nv_info(MODULE_ID_VDEC, (char *)&nvData, sizeof(improve_yield_vdec_info));
	if (ret != 0) {
		dpu_pr_err("get nv info fail, ret = %d", ret);
		return -EFAULT;
	}

	if (nvData.nv_flag.bits.dpu_pv_flag == 0) {
		dpu_pr_err("test pass, no need to improve yield");
		return 0;
	}

	ret = sprintf_s(buffer, DPU_IY_NV_INFO_MAX_LENGTH, "%s", "dpu_pv_flag=1");
	if (ret <= 0) {
		dpu_pr_err("sprintf_s fail");
		return -EFAULT;
	}
	dpu_pr_info("sprintf_s succ, ret = %d", ret);
	*length = (ret > DPU_IY_NV_INFO_MAX_LENGTH) ? DPU_IY_NV_INFO_MAX_LENGTH : ret;
	return 0;
}
#endif

bool dpu_is_pv_flag_true(void)
{
	/* The current platform use vdec NV, and it will be changed to Media1 in the next platform. */
	improve_yield_vdec_info nvData = {};
	int ret = get_improve_yield_nv_info(MODULE_ID_VDEC, (char *)&nvData, sizeof(improve_yield_vdec_info));
	if (ret != 0) {
		dpu_pr_err("get nv info fail, ret = %d", ret);
		return false;
	}

	dpu_pr_info("nv_flag = 0x%x", nvData.nv_flag.value);
	return !!(nvData.nv_flag.bits.pv_flag);
}

static void dpu_send_iy_lpm3_msg(void)
{
	int msg[DIAGINFO_MBX_MSG_LEN] = {PSCI_MSG_TYPE_AP_MEDIA1_IY, 0};
	int ret = RPROC_SYNC_SEND(IPC_ACPU_LPM3_MBX_5, (mbox_msg_t *)msg, DIAGINFO_MBX_MSG_LEN, NULL, 0);
	if (ret != 0)
		dpu_pr_err("RPROC_SYNC_SEND failed! return 0x%x, msg:[0x%x]", ret, msg[0]);
	else
		dpu_pr_info("dpu iy notify lpmcu succ");
}

void dpu_comp_improve_yield(void)
{
	/* send ipc msg to lpm3 to improve yield, must act before access any register */
	dpu_pr_debug("dpu iy enter");
	if (dpu_is_pv_flag_true())
		dpu_send_iy_lpm3_msg();
}