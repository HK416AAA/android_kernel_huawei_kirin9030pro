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
#include <aae/soc_dpu_define.h>
#include <aae/soc_aae_define.h>
#include <aae/soc_aae_dacc_interface.h>
#include "aae_cmdlist.h"
#include "cmdlist_interface.h"
#include "aae_res_mgr.h"
#include "aae_smmu.h"
#include "ukmd_utils.h"
#include "akmd_log.h"

static void aae_cmdlist_init_ch(char __iomem *aae_base)
{
	uint32_t i;
	uint32_t val;

	/* cmdlist select srt0 */
	set_reg(aae_base + AAE_DBCU_OFFSET + 0x1C, 0x1, 2, 0); // AAE_DBCU_CMDLIST_AXI_SEL_ADDR
	
	if (!ukmd_cmdlist_is_va_enable(CMDLIST_DEV_ID_DPU)) {
		set_reg(AAE_DBCU_MMU0_ID_ATTR_NS_ADDR(aae_base + AAE_DBCU_OFFSET), 0x3F, 32, 0);
	} else {
		set_reg(AAE_DBCU_MMU0_ID_ATTR_NS_ADDR(aae_base + AAE_DBCU_OFFSET), 0x20001, 32, 0);
		val = DPU_SSID_MAX_NUM * DPU_SCENE_INITAIL;
		set_reg(AAE_DBCU_MMU1_ID_ATTR_NS_ADDR(aae_base + AAE_DBCU_OFFSET), (val << 4), 32, 0);
	}

	set_reg(aae_base + AAE_DBCU_OFFSET + 0xB0C, 0x1, 1, 0); // DBCU_AIF_CMD_RELOAD_ADDR

	set_reg(aae_base + AAE_CMDLIST_OFFSET + 0x7a0, 0x1, 1, 0); // TWO_SAME_FRAME_BYPASS
	// Notice: cmdlist scene number must use same as dpu
	for (i = 0; i < (uint32_t)DPU_SCENE_MAX; ++i) {
		outp32(SOC_DACC_AAE_CMDLIST_CH_INTE_ADDR(aae_base + AAE_CMDLIST_OFFSET, i), 0xE4); // CMDLIST_CH_INTE
		set_reg(SOC_DACC_AAE_CMDLIST_CH_CTRL_ADDR(aae_base + AAE_CMDLIST_OFFSET, i), 1, 1, 0);
	}
}

void aae_cmdlist_pip_commit(char __iomem *aae_base, uint32_t scene_id, uint32_t cmdlist_id)
{
	dma_addr_t cmdlist_buf_addr;
	uint64_t cur_ts;

	aae_assert(!aae_base);

	if (scene_id >= AAE_SCENE_MAX) {
		aae_pr_err("scene_id = %u is out of range", scene_id);
		return;
	}

	dsb(sy);

	aae_pr_info("scene_id=%u cmdlist_id=%u", scene_id, cmdlist_id);

	cmdlist_buf_addr = ukmd_cmdlist_get_dma_addr(CMDLIST_DEV_ID_AAE, scene_id, cmdlist_id);
	if (cmdlist_buf_addr != 0) {
		cur_ts = (uint64_t)ktime_to_us(ktime_get());
		outp32(AAE_DM_CMDLIST_ADDR0_ADDR(aae_base + g_dm_tlb_info[scene_id].dm_data_addr), cmdlist_buf_addr);
		aae_pr_debug("cur_ts=%llu scene_id=%u cmdlist_id=%u", cur_ts, scene_id, cmdlist_id);
	}
}

void aae_cmdlist_init_commit(char __iomem *aae_base, dma_addr_t cmdlist_buf_addr)
{
	uint32_t times = 0;
	SOC_DACC_AAE_CMDLIST_CH_INTS_UNION intr_status;

	aae_assert(!aae_base);

	if (unlikely(cmdlist_buf_addr == 0)) {
		aae_pr_err("cmdlist_buf_addr is null");
		return;
	}

	dsb(sy);
    
	// aae need open part1&part0 clk before cmdlist commit
    set_reg(AAE_GLB_PART0_AAE_PART_CLK_EN_ADDR(aae_base + AAE_GLB0_OFFSET), 0xf, 32, 0);

	aae_cmdlist_init_ch(aae_base);

	set_reg(SOC_DACC_AAE_CMDLIST_CH_STAAD_ADDR(aae_base + AAE_CMDLIST_OFFSET, DPU_SCENE_INITAIL),
		cmdlist_buf_addr, 32, 0);

	writel(~BIT(DPU_SCENE_INITAIL), SOC_DACC_AAE_CMDLIST_ADDR_MASK_DIS_ADDR(aae_base + AAE_CMDLIST_OFFSET));

	/* start */
	set_reg(SOC_DACC_AAE_CMDLIST_START_ADDR(aae_base + AAE_CMDLIST_OFFSET), BIT(DPU_SCENE_INITAIL), 8, 0);

	while (true) {
		intr_status.value =
			inp32(SOC_DACC_AAE_CMDLIST_CH_INTS_ADDR((aae_base + AAE_CMDLIST_OFFSET), DPU_SCENE_INITAIL));

		if (intr_status.reg.ch_taskdone_ints) {
			aae_pr_debug("wait init finish inte for %u us", (times * 50));
			break;
		} else if (times >= 100){
			aae_pr_err("wait init finish timeout");
			break;
		} else {
			udelay(50);
			times++;
		}
	}

	if (ukmd_cmdlist_is_va_enable(CMDLIST_DEV_ID_AAE))
		aae_pip_smmu_tlb_flush(DPU_SCENE_INITAIL, 0);
}

static void cmdlist_dbcu_cfg(char __iomem *aae_base)
{
	/* cmdlist select srt0 */
	set_reg(AAE_DBCU_CMDLIST_AXI_SEL_ADDR(aae_base + AAE_DBCU_OFFSET), 0x1, 2, 0);
	set_reg(AAE_DBCU_MMU0_ID_ATTR_ADDR(aae_base + AAE_DBCU_OFFSET), 0x3F, 32, 0);
	set_reg(AAE_DBCU_MMU0_ID_ATTR_NS_ADDR(aae_base + AAE_DBCU_OFFSET), 0x3F, 32, 0);
	set_reg(AAE_DBCU_AIF_CMD_RELOAD_ADDR(aae_base + AAE_DBCU_OFFSET), 0x1, 1, 0);
}

static void cmdlist_intr_cfg(char __iomem *aae_base)
{
	uint32_t i;
	for (i = 0; i < (uint32_t)DPU_SCENE_MAX; ++i) {
		set_reg(SOC_DACC_AAE_CMDLIST_CH_INTC_ADDR(aae_base + AAE_CMDLIST_OFFSET, i), 0xFFFFFFFF, 32, 0); // clear
		set_reg(SOC_DACC_AAE_CMDLIST_CH_INTE_ADDR(aae_base + AAE_CMDLIST_OFFSET, i), 0xE4, 32, 0); // CMDLIST_CH_INTE
		set_reg(SOC_DACC_AAE_CMDLIST_CH_CTRL_ADDR(aae_base + AAE_CMDLIST_OFFSET, i), 1, 1, 0);
	}
}

static void cmdlist_ctl_cfg_mode(char __iomem *aae_base)
{
	uint32_t i;
	for (i = 0; i < (uint32_t)DPU_SCENE_MAX; ++i)
		set_reg(SOC_DACC_AAE_CTL_CFG_MODE0_ADDR(aae_base + DMC_OFFSET, i), 0x1, 2, 0);
}

void cmdlist_init(char __iomem *aae_base)
{
	aae_check_and_no_retval(!aae_base, err, "aae_base is null!");
	cmdlist_dbcu_cfg(aae_base);
	cmdlist_intr_cfg(aae_base);
	cmdlist_ctl_cfg_mode(aae_base);
}