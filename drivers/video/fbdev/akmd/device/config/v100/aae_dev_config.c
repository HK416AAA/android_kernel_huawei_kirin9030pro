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

#include <aae/soc_aae_interface.h>
#include <aae/soc_dpu_define.h>
#include <aae/dpu_dm.h>
#include "aae_dev_config.h"
#include "aae_opr_config.h"
#include "cmdlist_interface.h"
#include "aae_res_mgr.h"
#include "ukmd_utils.h"
#include "akmd_log.h"

static uint32_t s_scf_lut_addr_tlb[] = {
	AAE_ARSR1_OFFSET,
	AAE_VSCF0_OFFSET,
};

bool aae_enable_lp_flag(void)
{
	return true;
}

static void aae_level1_clock_lp(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_AAE;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00040020, 0x00000800); // GLB(Part0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00080000, 0x00000000); // GLB(Part1)
}

static void aae_level2_clock_lp(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_AAE;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00073000, 0x00000000); // DGP0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008A000, 0x00000000); // DGP1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00042000, 0x00000000); // WR_CTRL1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00043000, 0x00000000); // WR_CTRL2
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00044004, 0x00000000); // PIPE0(SDMA)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00045004, 0x00000000); // PIPE1(PRE)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00046004, 0x00000000); // PIPE2(POST)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00047004, 0x00000000); // PIPE3(WDMA)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00049250, 0x00000000); // RD_CTRL1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0004A250, 0x00000000); // RD_CTRL2
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00050868, 0x00000000); // DBCU
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000520E4, 0x00000000); // ROT_WDMA
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00053000, 0x00000000); // RCH_OV0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00053008, 0x00000000); // RCH_OV1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00053010, 0x00000000); // RCH_OV2
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00053018, 0x00000000); // RCH_OV3
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00053024, 0x00000000); // RCH_OV WRAP
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00055008, 0x00000000); // HDR
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00065008, 0x00000000); // ARSR
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0006D008, 0x00000000); // VSCF
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00071008, 0x00000000); // CLD
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00074000, 0x00000000); // LB_WRAP
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00074020, 0x00000000); // LB_CTRL
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000750E4, 0x00000000); // WDFC
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00084008, 0x00000000); // SCF2D0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00085008, 0x00000000); // SCF2D1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00086008, 0x00000000); // BLUR
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00087008, 0x00000000); // HIOF
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008B008, 0x00000000); // BLPP
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00022340, 0x00000000); // RISCV_CFG (scene0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00022348, 0x00000000); // RISCV_CFG (scene1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0003e740, 0x00000000); // RISICV_CMDLIST

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,  0x00040310, 0x00000000); // TOP GLB
}

void aae_clock_lp(uint32_t cmdlist_id)
{
	aae_level1_clock_lp(cmdlist_id);
	aae_level2_clock_lp(cmdlist_id);
}

void aae_memory_lp(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_AAE;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00074028, 0x00000001); // LB_WRAP
}

void aae_memory_no_lp(uint32_t cmdlist_id)
{
	// aae mem is no lp by default
}

void aae_sdma_debug_init(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_AAE;

	// TOP_GLB (SDMA0) smda anti-hanging
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, AAE_GLB_PART0_DBG_CFG_CTRL_ADDR(AAE_GLB0_OFFSET), 0x3);
}

void aae_sdma_load_balance_config(char __iomem *aae_base)
{
	aae_assert(!aae_base);

	// sdma0, bit14=0, bit13=0, bit12=1, meanwhile pref_en_r2=1
	set_reg(AAE_GLB_PART0_SDMA_CTRL0_ADDR(aae_base + DPU_GLB0_OFFSET, 0), 0x1, 3, 12);
	set_reg(AAE_DBCU_MIF_CTRL_SMARTDMA_0_ADDR(aae_base + DPU_DBCU_OFFSET), 0x1, 1, 0);
}

uint32_t *aae_config_get_scf_lut_addr_tlb(uint32_t *length)
{
	// TODO: According to the different DTS to parse platform

	*length = (uint32_t)ARRAY_SIZE(s_scf_lut_addr_tlb);
	return s_scf_lut_addr_tlb;
}

uint32_t *aae_config_get_arsr_lut_addr_tlb(uint32_t *length)
{
	// TODO: According to the different DTS to parse platform

	*length = (uint32_t)ARRAY_SIZE(g_aae_arsr_offset);
	return g_aae_arsr_offset;
}