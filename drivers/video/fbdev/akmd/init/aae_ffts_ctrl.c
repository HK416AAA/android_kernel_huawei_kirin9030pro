/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: provide ffap1 handle function interfaces.
 */

#include <linux/delay.h>
#include <soc_ffap1_interface.h>
#include <aae/soc_aae_define.h>
#include <aae/soc_aae_addr_define.h>
#include "ukmd_utils.h"
#include "akmd_log.h"
#include "aae_manager.h"
#include "aae_ffts_ctrl.h"

enum ffap_link_type {
	PUSH_TASK_LINK = 0,
	TASK_DONE_LINK,
	MAX_LINK_TYPE
};

static char __iomem* get_aae_ffap_link_addr(char __iomem *aae_base, uint32_t link_type)
{
	char __iomem *aae_ffts = aae_base + AAE_FFTS_OFFSET;
	char __iomem *addr = NULL;
	if (link_type == PUSH_TASK_LINK) {
		addr = SOC_FFAP1_CPUIF_LINK_PT_ADDR(aae_ffts);
	} else if (link_type == TASK_DONE_LINK) {
		addr = SOC_FFAP1_CPUIF_LINK_TD_ADDR(aae_ffts);
	} else {
		aae_pr_err("link type error");
	}
	return addr;
}

static int32_t config_aae_ffap_link_req(char __iomem *aae_base, uint32_t val, uint32_t link_type)
{
	struct ukmd_reg_state reg_status;
	uint32_t try_times = 1000;
	uint32_t udelay_time = 1;
	char __iomem *addr = get_aae_ffap_link_addr(aae_base, link_type);
	aae_check_and_return(!addr, -1, err, "ffap link addr is null!");
	/* link cfg */
	set_reg(addr, val, 1, 0);
	reg_status.bs = 1;
	reg_status.bw = 1;
	reg_status.expected_val = val;
	if (!wait_reg_state(addr, &reg_status, udelay_time, try_times)) {
		aae_pr_err("link type:%d config failed", link_type);
		return -1;
	}
	aae_pr_debug("link type:%d config set done", link_type);
	return 0;
}

static void print_ffap_exp_debug(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + AAE_FFTS_OFFSET;
	aae_pr_warn("FFAP1:\n\tFFAP1_DFX_PT_CNT=%#x\t\tFFAP1_DFX_TD_CNT=%#x\t\tFFAP1_CPUIF_DFX_TASK=%#x\n"
		"\tFFAP1_DFX_PUSHTASK=%8x%12x%12x\n\tFFAP1_DFX_TASKDONE=%#x\n\n",
		inp32(SOC_FFAP1_DFX_PT_CNT_ADDR(module_base)), inp32(SOC_FFAP1_DFX_TD_CNT_ADDR(module_base)),
		inp32(SOC_FFAP1_CPUIF_DFX_TASK_ADDR(module_base)), inp32(SOC_FFAP1_DFX_PUSHTASK_ADDR(module_base, 0)),
		inp32(SOC_FFAP1_DFX_PUSHTASK_ADDR(module_base, 1)), inp32(SOC_FFAP1_DFX_PUSHTASK_ADDR(module_base, 2)),
		inp32(SOC_FFAP1_DFX_TASKDONE_ADDR(module_base)));
}

int32_t aae_ffts_connect(char __iomem *aae_base)
{
	aae_check_and_return(!aae_base, -1, err, "aae_base is null!");
	set_reg(SOC_FFAP1_DRAIN_TH_ADDR(aae_base + AAE_FFTS_OFFSET), 0x20, 8, 0);
	/* push task link cfg */
	if (config_aae_ffap_link_req(aae_base, 0x1, PUSH_TASK_LINK)) {
		aae_pr_err("pt link failed!, link pt:0x%x",
			readl(SOC_FFAP1_CPUIF_LINK_PT_ADDR(aae_base + AAE_FFTS_OFFSET)));
		return -1;
	}

    /* task done link cfg */
	if (config_aae_ffap_link_req(aae_base, 0x1, TASK_DONE_LINK)) {
		aae_pr_err("td link failed!, link td:0x%x",
			readl(SOC_FFAP1_CPUIF_LINK_TD_ADDR(aae_base + AAE_FFTS_OFFSET)));
		return -1;
	}

    aae_pr_debug("aae ffts connect success");
    return 0;
}

int32_t config_ffap_exp_handle(char __iomem *aae_base)
{
	struct ukmd_reg_state reg_status;
	uint32_t try_times = 100000;
	uint32_t udelay_time = 1;
	aae_pr_info("+");
	aae_check_and_return(!aae_base, -1, err, "aae_base is null!");
	if (config_aae_ffap_link_req(aae_base, 0x0, PUSH_TASK_LINK)) {
		aae_pr_err("aae ffts push task unlink failed!");
		return -1;
	}
	print_ffap_exp_debug(aae_base);
	/* enable ffap exception handle */
	set_reg(SOC_FFAP1_CPUIF_ABNORMAL_ADDR(aae_base + AAE_FFTS_OFFSET), 0x1, 1, 0);
	aae_pr_debug("ffap exp config set done");
	/* wait ffap exception handle done */
	reg_status.bs = 1;
	reg_status.bw = 1;
	reg_status.expected_val = 0x0;
	if (!wait_reg_state(SOC_FFAP1_CPUIF_ABNORMAL_ADDR(aae_base + AAE_FFTS_OFFSET), &reg_status, udelay_time, try_times)) {
		aae_pr_err("ffap exp config failed");
		return -1;
	}
	if (config_aae_ffap_link_req(aae_base, 0x0, TASK_DONE_LINK)) {
		aae_pr_err("aae ffts task done unlink failed!");
		return -1;
	}
	print_ffap_exp_debug(aae_base);
	aae_pr_info("-");
	return 0;
}

int32_t wait_ffap_pt_link(char __iomem *aae_base)
{
	struct ukmd_reg_state reg_status;
	uint32_t try_times = 1000000;  // max wait time is about 1s
	uint32_t udelay_time = 1;
	char __iomem *addr = SOC_FFAP1_CPUIF_LINK_PT_ADDR(aae_base + AAE_FFTS_OFFSET);

	aae_pr_info("+");

	aae_check_and_return(!aae_base, -1, err, "aae_base is null!");

	reg_status.bs = 0;
	reg_status.bw = 2;
	reg_status.expected_val = 0x3;
	if (!wait_reg_state(addr, &reg_status, udelay_time, try_times)) {
		aae_pr_err("ffap1 pt link wait timeout!");
		return -1;
	}

	aae_pr_info("-");
	return 0;
}
