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
#include <dpu/dpu_dm.h>
#include <linux/interrupt.h>
#include "dpu/dpu_base_addr.h"
#include "dpu_comp_mgr.h"
#include "dpu_comp_vactive.h"
#include "dpu_comp_abnormal_handle.h"
#include "dpu_comp_smmu.h"
#include "dpu_opr_config.h"
#include "dpu_config_utils.h"
#include "dksm_debug.h"
#include "dpu_config_utils.h"
#include "dpu_debug_dump.h"

void dpu_comp_abnormal_dump_lbuf(char __iomem *dpu_base)
{
	dpu_check_and_no_retval(!dpu_base, err, "dpu_base is NULL!\n");

	char __iomem *module_base0 = NULL;
	char __iomem *module_base1 = NULL;
	char __iomem *module_base2 = NULL;
	char __iomem *module_base3 = NULL;
	char __iomem *module_base4 = NULL;
	module_base0 = dpu_base + DPU_LB_WARP0_OFFSET;
	module_base1 = dpu_base + DPU_LB_WARP1_OFFSET;
	module_base2 = dpu_base + DPU_LB_WARP2_OFFSET;
	module_base3 = dpu_base + DPU_LB_WARP3_OFFSET;
	module_base4 = dpu_base + DPU_INFO_SRC_OFFSET;
 
	dpu_pr_warn("LBUF CNT:\n"
		"LB0 info: LBUF0_RF_USE_NUM=%#x, LBUF0_DBG_RF_NUM=%#x, LBUF0_DBG_RF_NUM1=%#x, LBUF0_DBG_FRM_CNT=%#x\n"
		"LB1 info: LBUF1_RF_USE_NUM=%#x, LBUF1_DBG_RF_NUM=%#x, LBUF1_DBG_RF_NUM1=%#x, LBUF1_DBG_FRM_CNT=%#x\n"
		"LB2 info: LBUF2_RF_USE_NUM=%#x, LBUF2_DBG_RF_NUM=%#x, LBUF2_DBG_RF_NUM1=%#x, LBUF2_DBG_FRM_CNT=%#x\n"
		"LB3 info: LBUF3_RF_USE_NUM=%#x, LBUF3_DBG_RF_NUM=%#x, LBUF3_DBG_RF_NUM1=%#x, LBUF3_DBG_FRM_CNT=%#x\n",
		inp32(DPU_LB_WRAP_LBUF_RF_USE_NUM_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM1_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_DBG_FRM_CNT_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_RF_USE_NUM_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM1_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_DBG_FRM_CNT_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_RF_USE_NUM_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM1_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_DBG_FRM_CNT_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_RF_USE_NUM_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_DBG_RF_NUM1_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_DBG_FRM_CNT_ADDR(module_base3)));

	dpu_pr_warn("LBUF STATE:\n"
		"LB0 info: CTL_STATE=%#x, APPLY&RESP=%#x %#x, QUERY&RESP=%#x %#x, LBUF_PART_WR&RD=%#x %#x\n"
		"LB1 info: CTL_STATE=%#x, APPLY&RESP=%#x %#x, QUERY&RESP=%#x %#x, LBUF_PART_WR&RD=%#x %#x\n"
		"LB2 info: CTL_STATE=%#x, APPLY&RESP=%#x %#x, QUERY&RESP=%#x %#x, LBUF_PART_WR&RD=%#x %#x\n"
		"LB3 info: CTL_STATE=%#x, APPLY&RESP=%#x %#x, QUERY&RESP=%#x %#x, LBUF_PART_WR&RD=%#x %#x\n",
		inp32(DPU_LB_WRAP_LBUF_CTL_STATE_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_STATE_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_RESP_STATE_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_STATE_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_RESP_STATE_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_PART_WR_STATE_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_PART_RD_STATE_ADDR(module_base0)),
		inp32(DPU_LB_WRAP_LBUF_CTL_STATE_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_STATE_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_RESP_STATE_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_STATE_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_RESP_STATE_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_PART_WR_STATE_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_PART_RD_STATE_ADDR(module_base1)),
		inp32(DPU_LB_WRAP_LBUF_CTL_STATE_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_STATE_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_RESP_STATE_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_STATE_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_RESP_STATE_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_PART_WR_STATE_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_PART_RD_STATE_ADDR(module_base2)),
		inp32(DPU_LB_WRAP_LBUF_CTL_STATE_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_STATE_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_APPLY_RESP_STATE_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_STATE_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_QUERY_RESP_STATE_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_PART_WR_STATE_ADDR(module_base3)),
		inp32(DPU_LB_WRAP_LBUF_PART_RD_STATE_ADDR(module_base3)));

	dpu_pr_warn("INFO SRC:\n"
		"SCENE0_INFO_DEBUG0=%#x, SCENE1_INFO_DEBUG0=%#x, SCENE2_INFO_DEBUG0=%#x, SCENE4_INFO_DEBUG0=%#x\n",
		inp32(DPU_INFO_SRC_SCENE0_INFO_DEBUG0_ADDR(module_base4)),
		inp32(DPU_INFO_SRC_SCENE1_INFO_DEBUG0_ADDR(module_base4)),
		inp32(DPU_INFO_SRC_SCENE2_INFO_DEBUG0_ADDR(module_base4)),
		inp32(DPU_INFO_SRC_SCENE4_INFO_DEBUG0_ADDR(module_base4)));
	g_dpu_dsm_info.info_src = inp32(DPU_INFO_SRC_SCENE0_INFO_DEBUG0_ADDR(module_base0));
}

void dpu_comp_abnormal_dump_dbuf(char __iomem *dpu_base, uint32_t scene_id)
{
	dpu_check_and_no_retval(!dpu_base, err, "dpu_base is NULL!\n");
	char __iomem *module_base = NULL;

	// waterline-related registers
	dpu_pr_warn("DISP: dbuf freq: debuf0_lev_cnt=%#x.\t debuf1_lev_cnt=%#x. \t debuf2_lev_cnt=%#x.",
		inp32(DPU_LB_WRAP_DBUF0_STATE_ADDR(dpu_base + DPU_LB_WARP3_OFFSET)),
		inp32(DPU_LB_WRAP_DBUF1_STATE_ADDR(dpu_base + DPU_LB_WARP3_OFFSET)),
		inp32(DPU_LB_WRAP_DBUF2_STATE_ADDR(dpu_base + DPU_LB_WARP3_OFFSET)));

	// waterline status
	dpu_pr_warn("LBUF: dbuf0 trigger fluex_req, state=0x%x, ctrl=0x%x, fluex_req_bef=0x%x, fluex_req_aft=0x%x",
		inp32(DPU_LBUF_DBUF0_STATE_ADDR(dpu_base + DPU_LBUF_OFFSET)),
		inp32(DPU_LBUF_DBUF0_CTRL_ADDR(dpu_base + DPU_LBUF_OFFSET)),
		inp32(DPU_LBUF_DBUF0_THD_FLUX_REQ_BEF_ADDR(dpu_base + DPU_LBUF_OFFSET)),
		inp32(DPU_LBUF_DBUF0_THD_FLUX_REQ_AFT_ADDR(dpu_base + DPU_LBUF_OFFSET)));

	if (scene_id > DPU_SCENE_ONLINE_2) {
		dpu_pr_warn("scene id=%u over", scene_id);
		return;
	}
	module_base = dpu_base + DPU_INFO_SRC_OFFSET + DPU_INFO_SRC_SCNX_OFFSET(scene_id);
	// waterline LBUF
	dpu_pr_warn("GLB DUBF DEBUG LB config online0:\n"
		"\t SCENE0_LAYER_SIZE: 0x%x\t SCENE0_DBUF_DEPTH: 0x%x\t SCENE0_PRE_OS_NUM: 0x%x\t, SCENE0_INFO_SEL: 0x%x\n"
		"\t SCENE0_INFO_PAUSE_NUM: 0x%x",
		inp32(DPU_INFO_SRC_SCENE0_LAYER_SIZE_ADDR(module_base)),
		inp32(DPU_INFO_SRC_SCENE0_DBUF_DEPTH_ADDR(module_base)),
		inp32(DPU_INFO_SRC_SCENE0_PRE_OS_NUM_ADDR(module_base)),
		inp32(DPU_INFO_SRC_SCENE0_INFO_SEL_ADDR(module_base)),
		inp32(DPU_INFO_SRC_SCENE0_INFO_PAUSE_NUM_ADDR(module_base)));
}

void dpu_comp_abnormal_dump_pll(struct dpu_composer *dpu_comp)
{
	(void)dpu_comp;
}