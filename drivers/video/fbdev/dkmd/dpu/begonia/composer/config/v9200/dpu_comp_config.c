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

#include "dkmd_log.h"
#include "dkmd_object.h"
#include "cmdlist_interface.h"
#include "dpu_comp_config_utils.h"
#include <dpu/dpu_lbuf.h>
#include <dpu/soc_dpu_define.h>
#include "soc_pctrl_interface.h"
#include "doze.h"
#if defined(CONFIG_DRMDRIVER)
#include <platform_include/see/bl31_smc.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#endif
#include "dpu/dpu_base_addr.h"

struct swid_info g_sdma_swid_tlb_info[SDMA_SWID_NUM] = {
	{DPU_SCENE_ONLINE_0,   0,  21},
	{DPU_SCENE_ONLINE_1,  22,  39},
	{DPU_SCENE_ONLINE_2,  40,  47},
	{DPU_SCENE_OFFLINE_0, 50,  57},
};

struct swid_info g_wch_swid_tlb_info[WCH_SWID_NUM] = {
	{DPU_SCENE_ONLINE_0,  49,  49},
	{DPU_SCENE_OFFLINE_0, 58,  58},
};

void dpu_comp_wch_axi_sel_set_reg(char __iomem *dpu_base)
{
	void_unused(dpu_base);
}

char __iomem *dpu_comp_get_tbu1_base(char __iomem *dpu_base)
{
	if (dpu_base == NULL) {
		dpu_pr_err("dpu_base is nullptr!\n");
		return NULL;
	}

	return dpu_base + DPU_SMMU1_OFFSET;
}

void dpu_sdma_config_init(char __iomem *dpu_base)
{
	set_reg(DPU_SDMA_DBG_CTRL0_ADDR(dpu_base + DPU_SDMA_OFFSET, 0), 1, 1, 20);
	set_reg(DPU_SDMA_DBG_CTRL0_ADDR(dpu_base + DPU_SDMA_OFFSET, 1), 1, 1, 20);
}

void dpu_level1_clock_lp(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_DPU;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00013100, 0x00000000); // TOP_ GLB
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00088000, 0x00400000); // AVHR_GLB
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D8000, 0x00000000); // DISP_GLB
}

void dpu_level2_clock_lp(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_DPU;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00012740, 0x00000000); // CMD
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000178E4, 0x00000000); // WCH0

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00019868, 0x00000000); // DBCU
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001986C, 0x00000000); // DBCU

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00015000, 0x00000000); // PIPE_CTRL0 (SDMA)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001A000, 0x00000000); // PIPE_CTRL1 (PRE_WRAP)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001B000, 0x00000000); // PIPE_CTRL2 (OV)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6C00, 0x00000000); // PIPE_CTRL3 (POST_WRAP)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00016000, 0x00000000); // PIPE_CTRL4 (ITF)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005E000, 0x00000000); // LB_WRAP (LBUF_WRAP0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005E020, 0x00000000); // LB_WRAP (LBUF_CLT0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005E028, 0x00000000); // LB_WRAP (LBUF_IDX_CLT0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005E300, 0x00000000); // LB_WRAP (LBUF_PART0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E000, 0x00000000); // LB_WRAP (LBUF_WRAP1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E020, 0x00000000); // LB_WRAP (LBUF_CLT1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E028, 0x00000000); // LB_WRAP (LBUF_IDX_CLT1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E300, 0x00000000); // LB_WRAP (LBUF_PART1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E800, 0x00000000); // LB_WRAP (LBUF_WRAP2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E820, 0x00000000); // LB_WRAP (LBUF_CLT2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E828, 0x00000000); // LB_WRAP (LBUF_IDX_CLT2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008EB00, 0x00000000); // LB_WRAP (LBUF_PART2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6000, 0x00000000); // LB_WRAP (LBUF_WRAP3)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6020, 0x00000000); // LB_WRAP (LBUF_CLT3)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6028, 0x00000000); // LB_WRAP (LBUF_IDX_CLT3)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6300, 0x00000000); // LB_WRAP (LBUF_PART3)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00017250, 0x00000000); // RD_CTRL(ITF)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00018A50, 0x00000000); // RD_CTRL(PRE_WRAP)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00018E50, 0x00000000); // RD_CTRL(OV)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D7E50, 0x00000000); // RD_CTRL(PST_WRAP)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00089880, 0x00000000); // AVHR_GLB(WR_CTRL1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00089C80, 0x00000000); // AVHR_GLB(WR_CTRL2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6880, 0x00000000); // DISP_GLB(WR_CTRL3)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000CD008, 0x00000000); // ARSR0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00078008, 0x00000000); // ARSR1

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0007F008, 0x00000000); // VSCF0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00083008, 0x00000000); // VSCF1

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00060008, 0x00000000); // HDR

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008D008, 0x00000000); // CLD0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C000, 0x00000000); // RCH_OV0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C008, 0x00000000); // RCH_OV1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C010, 0x00000000); // RCH_OV2
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C018, 0x00000000); // RCH_OV3
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C020, 0x00000000); // RCH_OV WRAP

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B4008, 0x00000000); // DPP0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000DD008, 0x00000000); // DPP1

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B0008, 0x00000000); // DDIC TOP

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D407C, 0x00000000); // DSC0 DIV
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D4248, 0x00000000); // DSC0 TOP

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00040340, 0x00000000); // DACC_CFG (scene0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00040348, 0x00000000); // DACC_CFG (scene1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00040350, 0x00000000); // DACC_CFG (scene2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00040360, 0x00000000); // DACC_CFG (scene4)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00011070, 0x00000001); // ITF_CH0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00011170, 0x00000001); // ITF_CH1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00011270, 0x00000001); // ITF_CH2

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000114F4, 0x00000000); // PIPE_SW
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00011414, 0x00000000); // PIPE_SW
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001144C, 0x00000000); // PIPE_SW
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00011468, 0x00000000); // PIPE_SW
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00011484, 0x00000000); // PIPE_SW

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008F008, 0x00000000); // UVSAM_WRAP

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00000024, 0x00050000); // DSI

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00075008, 0x00000000); // SCF2D
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00087008, 0x00000000); // VCLD
}

void dpu_ch1_level2_clock_lp(uint32_t cmdlist_id)
{
}

void dpu_memory_lp(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_DPU;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005E030, 0x00000001); // TOP_GLB->LB_WRAP_0  (LBUF_CTL0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E030, 0x00000001); // AVHR_GLB->LB_WRAP_1 (LBUF_CTL1 )
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E830, 0x00000001); // AVHR_GLB->LB_WRAP_2 (LBUF_CTL2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6030, 0x00000001); // DISP_GLB->LB_WRAP_3  (LBUF_CTL3)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00013580, 0x00001000); // SW DVFS
}

void dpu_memory_no_lp(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_DPU;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001273C, 0x00000008); // CMD

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001783C, 0x08888888); // WCH0 DMA MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001784C, 0x08888888); // WCH0 DMA MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00018018, 0x00000088); // WCH0 SCF MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00018090, 0x00000008); // WCH0 SCF_LB_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00018388, 0x00000008); // WCH0 ROT_MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005E308, 0x00000008); // TOP_GLB  (LBUF PART0)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008E308, 0x00000008); // AVHR_GLB (LBUF PART1)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008EB08, 0x00000008); // AVHR_GLB (LBUF PART2)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D6308, 0x00000008); // DISP_GLB ( LBUF PART3)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005F3E0, 0x00000008); // (SDMA)
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0005F3E4, 0x00000008); // (SDMA)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D8800, 0x00000080); // DISP_GLB ( WCH_DBUF)

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000CD218, 0x00000088); // ARSR0 SCF_COEF MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000CD290, 0x00000008); // ARSR0 SCF_LB MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000CD3E8, 0x00000008); // ARSR0 LB MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000CD3EC, 0x00000088); // ARSR0 COEF MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00078218, 0x00000088); // ARSR1 SCF_COEF MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00078290, 0x00000008); // ARSR1 SCF_LB MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000783E8, 0x00000008); // ARSR1 LB MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000783EC, 0x00000088); // ARSR1 COEF MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0007F290, 0x00000008); // VSCF0_LB_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0007F218, 0x00000088); // VSCF0_COEF_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00083290, 0x00000008); // VSCF1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00083218, 0x00000088); // VSCF1_COEF_MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00060238, 0x00000008); // HDR GTM_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00060A04, 0x00000008); // HDR DEGAMMA_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00060A18, 0x00000008); // HDR GMP_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00060A34, 0x00000008); // HDR GAMMA_MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C060, 0x00000008); // RCH_OV0
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C064, 0x00000008); // RCH_OV1
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C068, 0x00000008); // RCH_OV2
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0001C06C, 0x00000008); // RCH_OV3

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B40B0, 0x00000008); // DPP0 CTC MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B4500, 0x00000008); // DPP0 SPR MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B4704, 0x00000008); // DPP0 DEGAMMA MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B4804, 0x00000008); // DPP0 ROIGAMMA0 MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B4904, 0x00000008); // DPP0 ROIGAMMA0 MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B49A4, 0x00000008); // DPP0 GMP MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B55BC, 0x00000008); // DPP0 DITHER_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B58A4, 0x00000008); // DPP0 SPR_GAMMA MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B5904, 0x00000008); // DPP0 ALSC_DEGAMMA_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000C9130, 0x00000008); // DPP0 HIACE_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000C9134, 0x00000008); // DPP0 HIACE_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000C9138, 0x00000008); // DPP0 HIACE_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000C9498, 0x00000008); // DPP0 HIACE_MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000DD704, 0x00000008); // DPP1 DEGAMA_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000DD9A4, 0x00000008); // DPP1 GMP_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000DE5BC, 0x00000008); // DPP1  DITHER_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000DE8A4, 0x00000008); // DPP1  SPR_GAMA_MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B010C, 0x00000008); // DDIC0 DITHER_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B0154, 0x00000008); // DDIC0 DLBCD_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B0404, 0x00000008); // DDIC0 ODC_ MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B188C, 0x00000000); // DDIC0 DeBurnin_ MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000B2C84, 0x00000008); // DDIC0 DEMURA MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000AD000, 0x00080008); // DDIC0 IRC MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x000D4084, 0x00000088); // DSC0

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008F060, 0x00000008); // UYSAMP_MEM
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0008F100, 0x00000008); // UYSAMP_DBLK_MEM

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x0007674C, 0x00000008); // AIHDR
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00075180, 0x00000008); // SCF2D

	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id, 0x00013580, 0x00001000); // SW DVFS
}

void dpu_ch1_memory_no_lp(uint32_t cmdlist_id)
{
}

void dpu_pipe_ctrl_init(uint32_t cmdlist_id)
{
	uint32_t cmdlist_dev_id = CMDLIST_DEV_ID_DPU;
	dpu_pr_debug("pipe_ctrl_init !!");

	DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX0_UNION rd_ch_inx0;
	DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX1_UNION rd_ch_inx1;
	DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX2_UNION rd_ch_inx2;
	DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX3_UNION rd_ch_inx3;
	DPU_PIPE_CTRL_PIPE_CTL_WR_CH_IDX0_UNION wr_ch_inx0;
	DPU_PIPE_CTRL_PIPE_CTL_WR_CH_IDX1_UNION wr_ch_inx1;
	DPU_PIPE_CTRL_PIPE_CTL_WR_CH_IDX2_UNION wr_ch_inx2;

	rd_ch_inx0.value = 0;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx0 = OPR_MOD_IDX_UVUP0;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx1 = OPR_MOD_IDX_ARSR1;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx2 = OPR_MOD_IDX_HDR;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx3 = OPR_MOD_IDX_VSCF0;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx4 = OPR_MOD_IDX_VSCF1;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX0_ADDR(DPU_PRE_PIPE_CTRL_OFFSET), rd_ch_inx0.value);

	rd_ch_inx0.value = 0;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx0 = OPR_MOD_IDX_DPP0;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx1 = OPR_MOD_IDX_DPP1;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx2 = OPR_MOD_IDX_DSC0;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX0_ADDR(DPU_POST_PIPE_CTRL_OFFSET), rd_ch_inx0.value);

	rd_ch_inx0.value = 0;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx0 = OPR_MOD_IDX_ITFSW0;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx1 = OPR_MOD_IDX_ITFSW1;
	rd_ch_inx0.reg.pipe_ctl_rd_ch_idx2 = OPR_MOD_IDX_ITFSW2;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX0_ADDR(DPU_ITF_PIPE_CTRL_OFFSET), rd_ch_inx0.value);

	rd_ch_inx1.value = 0;
	rd_ch_inx1.reg.pipe_ctl_rd_ch_idx5 = OPR_MOD_IDX_PRE_BYPASS0;
	rd_ch_inx1.reg.pipe_ctl_rd_ch_idx6 = OPR_MOD_IDX_PRE_BYPASS1;
	rd_ch_inx1.reg.pipe_ctl_rd_ch_idx7 = OPR_MOD_IDX_PRE_BYPASS2;
	rd_ch_inx1.reg.pipe_ctl_rd_ch_idx8 = OPR_MOD_IDX_CLD0;
	rd_ch_inx1.reg.pipe_ctl_rd_ch_idx9 = OPR_MOD_IDX_SCF2D0;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX1_ADDR(DPU_PRE_PIPE_CTRL_OFFSET), rd_ch_inx1.value);

	rd_ch_inx2.value = 0;
	rd_ch_inx2.reg.pipe_ctl_rd_ch_idx10 = OPR_MOD_IDX_AIHDR;
	rd_ch_inx2.reg.pipe_ctl_rd_ch_idx11 = OPR_MOD_IDX_AIHDR_GRID;
	rd_ch_inx2.reg.pipe_ctl_rd_ch_idx12 = OPR_MOD_IDX_VIDEO_CLD;
	rd_ch_inx2.reg.pipe_ctl_rd_ch_idx13 = OPR_MOD_IDX_DDIC0_DEMURA_LUT;
	rd_ch_inx2.reg.pipe_ctl_rd_ch_idx14 = OPR_MOD_IDX_DDIC0_ODC_LUT;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX2_ADDR(DPU_PRE_PIPE_CTRL_OFFSET), rd_ch_inx2.value);

	rd_ch_inx3.value = 0;
	rd_ch_inx3.reg.pipe_ctl_rd_ch_idx15 = OPR_MOD_IDX_DDIC0_DEBURNIN_LUT;
	rd_ch_inx3.reg.pipe_ctl_rd_ch_idx16 = OPR_MOD_IDX_IDLE_DISP;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_RD_CH_IDX3_ADDR(DPU_PRE_PIPE_CTRL_OFFSET), rd_ch_inx3.value);

	wr_ch_inx0.value = 0;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx0 = OPR_MOD_IDX_UVUP0;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx1 = OPR_MOD_IDX_ARSR1;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx2 = OPR_MOD_IDX_HDR;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx3 = OPR_MOD_IDX_VSCF0;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx4 = OPR_MOD_IDX_VSCF1;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_WR_CH_IDX0_ADDR(DPU_PRE_PIPE_CTRL_OFFSET), wr_ch_inx0.value);

	wr_ch_inx0.value = 0;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx0 = OPR_MOD_IDX_DPP0;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx1 = OPR_MOD_IDX_DPP1;
	wr_ch_inx0.reg.pipe_ctl_wr_ch_idx2 = OPR_MOD_IDX_DSC0;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_WR_CH_IDX0_ADDR(DPU_POST_PIPE_CTRL_OFFSET), wr_ch_inx0.value);

	wr_ch_inx1.value = 0;
	wr_ch_inx1.reg.pipe_ctl_wr_ch_idx5 = OPR_MOD_IDX_PRE_BYPASS0;
	wr_ch_inx1.reg.pipe_ctl_wr_ch_idx6 = OPR_MOD_IDX_PRE_BYPASS1;
	wr_ch_inx1.reg.pipe_ctl_wr_ch_idx7 = OPR_MOD_IDX_PRE_BYPASS2;
	wr_ch_inx1.reg.pipe_ctl_wr_ch_idx8 = OPR_MOD_IDX_CLD0;
	wr_ch_inx1.reg.pipe_ctl_wr_ch_idx9 = OPR_MOD_IDX_SCF2D0;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_WR_CH_IDX1_ADDR(DPU_PRE_PIPE_CTRL_OFFSET), wr_ch_inx1.value);

	wr_ch_inx2.value = 0;
	wr_ch_inx2.reg.pipe_ctl_wr_ch_idx10 = OPR_MOD_IDX_AIHDR;
	wr_ch_inx2.reg.pipe_ctl_wr_ch_idx11 = OPR_MOD_IDX_VIDEO_CLD;
	ukmd_set_reg(cmdlist_dev_id, DPU_SCENE_INITAIL, cmdlist_id,
		DPU_PIPE_CTRL_PIPE_CTL_WR_CH_IDX2_ADDR(DPU_PRE_PIPE_CTRL_OFFSET), wr_ch_inx2.value);
}

void dpu_lbuf_init(uint32_t cmdlist_id)
{
	dpu_pipe_ctrl_init(cmdlist_id);
}

void dpu_comp_lbuf_init(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}

void dpu_sdma_debug_init(uint32_t cmdlist_id)
{
	void_unused(cmdlist_id);
}

/* set this bit to indicate LPMCU dpu power on, then LPMCU need check dpu lbuf before ddr dfs
 * clear this bit to indicate LPMCU dpu power off, then LPMCU needn't check dpu lbuf before ddr dfs
 */
void dpu_power_on_state_for_ddr_dfs(char __iomem *pctrl_base, bool is_power_on)
{
	if (unlikely(!pctrl_base)) {
		dpu_pr_debug("pctrl_base is null");
		return;
	}

	set_reg(SOC_PCTRL_PERI_CTRL25_ADDR(pctrl_base), (uint32_t)is_power_on, 1, 12);
}

void dpu_enable_m1_qic_intr(char __iomem *actrl_base)
{
	void_unused(actrl_base);
}

/* dynamic on and off are not supported */
bool dpu_enable_lp_flag(void)
{
	return false;
}

uint32_t dpu_get_ch_sid(void)
{
	uint32_t ch_sid = 1;
	return ch_sid;
}

void dpu_dacc_resume(char __iomem *dpu_base)
{
	if (unlikely(!dpu_base)) {
		dpu_pr_err("dpu_base is NULL");
		return;
	}
	/* set DFR_DACC_RESUME flag */
	outp32(DPU_DFR_DACC_RESUME_ADDR(dpu_base), 1);
}

void dpu_check_dbuf_state(char __iomem *dpu_base, uint32_t scene_id)
{
	uint32_t dbuf0_state;

	dbuf0_state = inp32(DPU_LBUF_DBUF0_STATE_ADDR(dpu_base + DPU_LBUF_OFFSET));
	dpu_pr_debug("dbuf0_state = 0x%x, scene_id = %u", dbuf0_state, scene_id);
	if ((dbuf0_state & BIT(5)) == BIT(5)) /* dbuf0_flux_req */
		dpu_pr_warn("dbuf0 trigger fluex_req %d, state=0x%x, ctrl=0x%x, fluex_req_bef=0x%x, fluex_req_aft=0x%x",
			scene_id, dbuf0_state,
			inp32(DPU_LBUF_DBUF0_CTRL_ADDR(dpu_base + DPU_LBUF_OFFSET + DPU_LBUF_SCNX_DBUF_THD_OFFSET(scene_id))),
			inp32(DPU_LBUF_DBUF0_THD_FLUX_REQ_BEF_ADDR(dpu_base +
				DPU_LBUF_OFFSET + DPU_LBUF_SCNX_DBUF_THD_OFFSET(scene_id))),
			inp32(DPU_LBUF_DBUF0_THD_FLUX_REQ_AFT_ADDR(dpu_base +
				DPU_LBUF_OFFSET + DPU_LBUF_SCNX_DBUF_THD_OFFSET(scene_id))));
}

bool dpu_is_smmu_bypass(void)
{
	return false;
}

ktime_t get_te_hw_timestamp_us(char __iomem *dpu_base, int32_t sw_itfch_idx)
{
	void_unused(dpu_base);
	void_unused(sw_itfch_idx);
	ktime_t timestamp;

	timestamp = ktime_get();

	return ktime_to_us(timestamp);
}

void dpu_comp_abnormal_dump_axi(char __iomem *dpu_base)
{
	void_unused(dpu_base);
}
void dpu_comp_abnormal_dump_qic(char __iomem *media1_ctrl_base)
{
	void_unused(media1_ctrl_base);
}

void dpu_comp_set_glb_rs_reg(struct dpu_composer *dpu_comp, bool enable)
{
	uint32_t clear_bit = 0;
	struct dkmd_connector_info *pinfo = NULL;

	if (unlikely(!dpu_comp || !dpu_comp->conn_info || !dpu_comp->comp_mgr || !dpu_comp->comp_mgr->dpu_base)) {
		dpu_pr_err("dpu_comp or conn_info or dpu_base is null");
		return;
	}

	if (!enable) {
		outp32(DPU_GLB_RS_CLEAR_ADDR(dpu_comp->comp_mgr->dpu_base + DPU_GLB0_OFFSET), 0);
		return;
	}

	pinfo = dpu_comp->conn_info;
	clear_bit = BIT(pinfo->sw_post_chn_idx[PRIMARY_CONNECT_CHN_IDX]);
	if (pinfo->sw_post_chn_num > 1)
		clear_bit = clear_bit | BIT(pinfo->sw_post_chn_idx[EXTERNAL_CONNECT_CHN_IDX]);
	outp32(DPU_GLB_RS_CLEAR_ADDR(dpu_comp->comp_mgr->dpu_base + DPU_GLB0_OFFSET), clear_bit);

	dpu_pr_info("sw_post_chn_idx:%d, clear_bit:%#x", pinfo->sw_post_chn_idx[PRIMARY_CONNECT_CHN_IDX], clear_bit);
}

void dpu_ppc_set_1st_part_cmd_addr(char __iomem *dpu_base, struct panel_partial_ctrl *priv, uint32_t config_id)
{
	dpu_pr_info("+");

	void_unused(dpu_base);
	void_unused(priv);
	void_unused(config_id);
}

void dpu_ppc_set_2nd_part_cmd_addr(char __iomem *dpu_base, struct panel_partial_ctrl *priv, uint32_t config_id)
{
	void_unused(dpu_base);
	void_unused(priv);
	void_unused(config_id);
}

void dpu_ppc_init_interactive_reg(char __iomem *dpu_base, struct panel_partial_ctrl *priv)
{
	void_unused(dpu_base);
	void_unused(priv);
}

static void dpu_vote_doze1_status(uint32_t doze1_status)
{
    if (g_debug_doze1_inter_flag_enable == 0) {
        dpu_pr_debug("doze1 inter vote is not disabled");
		return;
	}

#if defined(CONFIG_DRMDRIVER)
	/* 1:vote entry doze1;0:vote exit doze1 */
	configure_dss_service_security(DSS_DOZE1_CONFIG, doze1_status, 0, BIG_DPU);

    /* only for auto test  */
	if (g_debug_dvfs_auto_test_enable == 1) {
		char __iomem *sctrl_base = dpu_config_get_ip_base(DISP_IP_BASE_SCTRL);
	    if (unlikely(!sctrl_base)) {
			dpu_pr_err("sctrl_base is NULL");
		    return;
		}
        set_reg(SOC_SCTRL_SCBAKDATA11_ADDR(sctrl_base), doze1_status, 1, 14);
	}
#endif
}

int32_t dpu_vote_enable_doze2(void)
{
	int32_t ret = 0;

	if (g_debug_doze2_enable == 0) {
		dpu_pr_debug("doze vote is not enabled");
		return 0;
	}

	dpu_vote_enable_doze1();

	dpu_pr_debug("vote enable doze2!");
	ret = vote_enable_doze2(DOZE_CLIENT_DSS_UNSEC);
	if (ret != 0)
		dpu_pr_err("vote enable doze2 failed!");

	return ret;
}

int32_t dpu_vote_disable_doze2(void)
{
	int32_t ret = 0;

	if (g_debug_doze2_enable == 0) {
		dpu_pr_debug("doze vote is not enabled");
		return 0;
	}
	dpu_pr_debug("vote disable doze2!");
	ret = vote_disable_doze2(DOZE_CLIENT_DSS_UNSEC);
	if (ret != 0)
		dpu_pr_err("vote disable doze2 failed!");

	dpu_vote_disable_doze1();

	return ret;
}

void dpu_vote_enable_doze1(void)
{
	dpu_vote_doze1_status(1);
}

void dpu_vote_disable_doze1(void)
{
	dpu_vote_doze1_status(0);
}

void dpu_sdma_load_balance_config(char __iomem *dpu_base)
{
	if (unlikely(!dpu_base)) {
		dpu_pr_err("dpu_base is NULL");
		return;
	}

	// sdma0, bit14=1, bit13=1, bit12=1, meanwhile pref_en_r2=1
	set_reg(DPU_SDMA_CTRL0_ADDR(dpu_base + DPU_SDMA_OFFSET, 0), 0x7, 3, 12);
	set_reg(DPU_DBCU_MIF_CTRL_SMARTDMA_0_ADDR(dpu_base + DPU_DBCU_OFFSET), 0x1, 1, 0);
	// sdma1, bit14=1, bit13=1, bit12=1, meanwhile pref_en_r2=1
	set_reg(DPU_SDMA_CTRL0_ADDR(dpu_base + DPU_SDMA_OFFSET, 1), 0x7, 3, 12);
	set_reg(DPU_DBCU_MIF_CTRL_SMARTDMA_1_ADDR(dpu_base + DPU_DBCU_OFFSET), 0x1, 1, 0);
}

bool is_async_mode(struct dpu_bl_ctrl *bl_ctrl)
{
	struct dfr_info *dfr_info = NULL;
	if(!bl_ctrl){
		dpu_pr_info("bl_ctrl is nullptr");
		return false;
	}

	dfr_info = dkmd_get_dfr_info(bl_ctrl->conn_info);
	if(!dfr_info){
		dpu_pr_info("dfr_info is nullptr");
		return false;
	}

	if (dfr_info->dfr_mode == DFR_MODE_TE_SKIP_BY_MCU || dfr_info->dfr_mode == DFR_MODE_LONGH_TE_SKIP_BY_MCU)
		return true;

	return false;
}

int32_t dpu_send_bl_cmds(struct dpu_bl_ctrl *bl_ctrl)
{
	if(!bl_ctrl){
		dpu_pr_err("bl_ctrl is nullptr");
		return -1;
	}

    if (!is_async_mode(bl_ctrl)) {
        if (!bl_ctrl->conn_info) {
            dpu_pr_err("bl_ctrl->conn_info is nullptr");
            return -1;
        }

        return pipeline_next_ops_handle(
            bl_ctrl->conn_info->conn_device, bl_ctrl->conn_info, SET_BACKLIGHT, &bl_ctrl->bl_level);
    }

    return composer_present_dfr_send_dcs_by_riscv(bl_ctrl->parent_composer, bl_ctrl->bl_level);
}

void dpu_config_lp_mode_stub(struct composer_manager *comp_mgr)
{
	void_unused(comp_mgr);
}

#define CRC_INDEX_MAX 3
static uint32_t get_crc_index(uint32_t bit_mask)
{
	uint32_t i;

	for (i = 0; i < CRC_INDEX_MAX; i++) {
		if (bit_mask & (1 << i))
			break;
	}

	return i;
}

void dpu_composer_get_online_crc(struct composer *comp, uint32_t *crc_val)
{
	uint32_t crc_index = 0;
	struct dpu_composer *dpu_comp = to_dpu_composer(comp);
	char __iomem *dpu_base;

	if (!dpu_comp) {
		dpu_pr_info("dpu_comp is nullptr");
		return;
	}

	dpu_base = dpu_comp->comp_mgr->dpu_base;
	if (!dpu_base) {
		dpu_pr_info("dpu_base is nullptr");
		return;
	}

	if ((g_debug_online_crc_enable != 0) && (g_debug_idle_enable == 0)) {
		crc_index = get_crc_index(g_debug_online_crc_enable);
		*crc_val = inp32(DPU_GLB_CRC_RESULT0_ADDR(dpu_base + DPU_GLB0_OFFSET + DPU_GLB_CRC_INDEX_OFFSET(crc_index)));
	}

	dpu_pr_info("get glb crc value 0x%x", *crc_val);
}

void dpu_get_cur_peri_level(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}

void dpu_comp_abnormal_dsm_dump_dvfs(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}

void dpu_print_vsync_connect_info(struct dpu_composer *dpu_comp)
{
    void_unused(dpu_comp);
}

void dpu_idle_enter_sd(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}

void dpu_idle_exit_sd(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}

void dpu_ops_deep_sleep_enter(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}

bool is_edp_cmd_mode(struct dkmd_connector_info *conn_info)
{
	return false;
}

uint32_t dpu_get_refresh_type(char __iomem *dpu_base)
{
	if (unlikely(dpu_base == NULL)) {
		dpu_pr_err("dpu_base is nullptr!");
		return PANEL_REFRESH_TYPE_INVALID;
	}

	return inp32(DPU_DFR_REFRESH_TYPE_ADDR(dpu_base));
}

bool dpu_comp_enter_idle_check(struct dkmd_connector_info *pinfo, struct dpu_composer *dpu_comp)
{
	void_unused(pinfo);
	void_unused(dpu_comp);
    return false;
}

uint32_t dpu_read_clear_extra_refresh_cnt(char __iomem *dpu_base)
{
	void_unused(dpu_base);

	return 0;
}

uint32_t get_mdp_irq_unmask(void)
{
	return ~(DPU_DACC_NS_INT | DPU_WCH0_NS_INT | DPU_WBUF_NS_INT | DPU_DDIC0_DLBCD_NS_INT);
}

void dpu_comp_set_data_continue_cnt(struct dpu_composer *dpu_comp, uint64_t dss_clk)
{
	void_unused(dpu_comp);
	void_unused(dss_clk);
}

void dpu_ppc_set_1st_cmdlist_cnt(char __iomem *dpu_base, struct panel_partial_ctrl *priv, uint32_t cmdlist_cnt)
{
	void_unused(dpu_base);
	void_unused(priv);
	void_unused(cmdlist_cnt);
}

void dpu_disable_ppc(char __iomem *dpu_base, struct panel_partial_ctrl *priv)
{
	void_unused(dpu_base);
	void_unused(priv);
}

void dpu_start_ppc(char __iomem *dpu_base, struct panel_partial_ctrl *priv)
{
	void_unused(dpu_base);
	void_unused(priv);
}

bool dpu_is_single_tbu(void)
{
	return false;
}

bool can_pre_init_config(void)
{
	return false;
}