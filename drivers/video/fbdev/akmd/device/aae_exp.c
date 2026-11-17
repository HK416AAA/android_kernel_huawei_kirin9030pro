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
#include <aae/soc_aae_interface.h>
#include <aae/soc_aae_define.h>
#include <aae/soc_aae_addr_define.h>
#include <aae/soc_aae_dacc_interface.h>
#include <soc_ffap1_interface.h>
#include <aae/dpu_dm.h>
#include "aae_manager.h"
#include "aae_smmu.h"
#include "akmd_log.h"
#include "ukmd_utils.h"
#include "aae_init.h"
#include "aae_power.h"
#include "aae_res_mgr.h"
#include "aae_ffts_ctrl.h"
#include "aae_opr_config.h"
#include "aae_config_utils.h"
#include "aae_exp.h"
#include "aae_exp_dump.h"
#include "aae_exp_power.h"
#include "aae_dacc_log_read.h"

#define AAE_DACC_LOG_DUMP_REG_COUNT 768
#define AAE_DACC_INTR_TRACE_DUMP_SIZE 24
#define AAE_DACC_CMDLIST_TRACE_DUMP_REG_COUNT 16
#define AAE_ONE_LINE_PRINT_REG_COUNT 4
#define AAE_DM_LAYER_INFO_REG_COUNT 5
#define AAE_GLB_PART0_MODULE_CLK_ENABLE 0x3
#define AAE_OPR_DUMP_FIRST_REG_OFFSET 0x4
#define AAE_OPR_DUMP_SECOND_REG_OFFSET 0x8
#define AAE_OPR_DUMP_THIRD_REG_OFFSET 0xC
#define AAE_REG_INDEX_ZERO 0
#define AAE_REG_INDEX_ONE 1
#define AAE_REG_INDEX_TWO 2
#define AAE_REG_INDEX_THREE 3

static void dump_aae_dacc_cmdlist_status(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + AAE_CMDLIST_OFFSET;

	aae_pr_warn("CMDLIST:\n"
		"\tCMDLIST_DBG=%#x\tSCE0_CFG_SIGNAL=%#x\n\n",
		inp32(SOC_DACC_AAE_CH0_CFG_TIME_CNT_ADDR(module_base)),
		inp32(SOC_DACC_AAE_SCE0_CFG_SIGNAL_ADDR(module_base)));
	aae_pr_warn("CMDLIST:\n"
		"\tCMDLIST_CH_CURAD=%#x\n\n",
		inp32(SOC_DACC_AAE_CMDLIST_CH_CURAD_ADDR(module_base, 0)));
	aae_pr_warn("CMDLIST:\n\n"
		"CMDLIST_CH_STATUS=%#x\t\tCMDLIST_CH_INTS=%#x\n\n",
		inp32(SOC_DACC_AAE_CMDLIST_CH_STATUS_ADDR(module_base, 0)),
		inp32(SOC_DACC_AAE_CMDLIST_CH_INTE_ADDR(module_base, 0)));
	aae_pr_warn("CMDLIST:\n"
		"\tSW_CMD_REG0=%#x\tSW_CMD_REG1=%#x\n\n",
		inp32(SOC_DACC_AAE_SW_CMD_REG0_ADDR(aae_base + DMC_OFFSET)),
		inp32(SOC_DACC_AAE_SW_CMD_REG1_ADDR(aae_base + DMC_OFFSET)));
}

static void dump_aae_dacc_trace_reg(char __iomem *aae_base)
{
	uint32_t i = 0;
	aae_pr_warn("DACC TRACE:\tffap1 intr cnt:%#x\t\t%#x\t\t%#x\t\t%#x\n\n",
		inp32(AAE_DACC_FFAP1_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_ZERO)),
		inp32(AAE_DACC_FFAP1_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_ONE)),
		inp32(AAE_DACC_FFAP1_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_TWO)),
		inp32(AAE_DACC_FFAP1_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_THREE)));

	aae_pr_warn("DACC TRACE:\tffap1 payload:%#x\t\t%#x\t\t%#x\t\t%#x\n\n",
		inp32(AAE_DACC_FFAP1_PAYLOAD_PARSE_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_ZERO)),
		inp32(AAE_DACC_FFAP1_PAYLOAD_PARSE_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_ONE)),
		inp32(AAE_DACC_FFAP1_PAYLOAD_PARSE_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_TWO)),
		inp32(AAE_DACC_FFAP1_PAYLOAD_PARSE_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_THREE)));

	aae_pr_warn("DACC TRACE:\tintr trace cnt:\n");
	for (i = 0; i < AAE_DACC_INTR_TRACE_DUMP_SIZE;  i += AAE_ONE_LINE_PRINT_REG_COUNT) {
		aae_pr_warn("\t%#x\t\t%#x\t\t%#x\t\t%#x\n\n",
			inp32(AAE_DACC_INTR_CNT_DUMP_REG_ADDR(aae_base, i)),
			inp32(AAE_DACC_INTR_CNT_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_ONE)),
			inp32(AAE_DACC_INTR_CNT_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_TWO)),
			inp32(AAE_DACC_INTR_CNT_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_THREE)));
	}

	aae_pr_warn("DACC TRACE:\tfrm end cnt:%#x\t\t%#x\t\t%#x\t\t%#x\n\n",
		inp32(AAE_DACC_FRAME_END_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_ZERO)),
		inp32(AAE_DACC_FRAME_END_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_ONE)),
		inp32(AAE_DACC_FRAME_END_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_TWO)),
		inp32(AAE_DACC_FRAME_END_INTR_CNT_DUMP_REG_ADDR(aae_base, AAE_REG_INDEX_THREE)));

	aae_pr_warn("DACC TRACE:\tcmdlist carry result:\n");
	for (i = 0; i < AAE_DACC_CMDLIST_TRACE_DUMP_REG_COUNT; i += AAE_ONE_LINE_PRINT_REG_COUNT) {
		aae_pr_warn("\t%#x\t\t%#x\t\t%#x\t\t%#x\n\n",
			inp32(AAE_DACC_CMDLIST_CARRY_RESULT_DUMP_REG_ADDR(aae_base, i)),
			inp32(AAE_DACC_CMDLIST_CARRY_RESULT_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_ONE)),
			inp32(AAE_DACC_CMDLIST_CARRY_RESULT_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_TWO)),
			inp32(AAE_DACC_CMDLIST_CARRY_RESULT_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_THREE)));
	}
}

static void dump_aae_dacc_reg(char __iomem *aae_base)
{
	uint32_t i = 0;
	char __iomem *module_base = aae_base + DACC_AAE_OFFSET + DMC_OFFSET;
	aae_pr_warn("DACC image time\n\t :%8x%12x%12x%12x\n",
			inp32(AAE_DACC_AAE_IMAGE_TIME_DUMP_REG_ADDR(aae_base, i)),
			inp32(AAE_DACC_AAE_IMAGE_TIME_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_ONE)),
			inp32(AAE_DACC_AAE_IMAGE_TIME_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_TWO)),
			inp32(AAE_DACC_AAE_IMAGE_TIME_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_THREE)));

	aae_pr_warn("DACC:\n\tCORE_STATUS_REG=%#x\t\tDACC_CORE_MON_PC_REG=%#x\t\tMISC_INT_CLR_REG=%#x\n\n",
		inp32(SOC_DACC_AAE_CORE_STATUS_REG_ADDR(module_base)), inp32(SOC_DACC_AAE_CORE_MON_PC_REG_ADDR(module_base)),
		inp32(SOC_DACC_AAE_MISC_INT_CLR_REG_ADDR(module_base)));

	module_base = aae_base + AAE_FFTS_OFFSET;
	aae_pr_warn("DACC FFAP1:\n\tCPUIF_WKINTR_ST=%#x\t\tCPUIF_INTR_ST=%#x\t\tCPUIF_DRAIN_UID=%#x\n\n",
		inp32(SOC_FFAP1_CPUIF_WKINTR_ST_ADDR(module_base)), inp32(SOC_FFAP1_CPUIF_INTR_ST_ADDR(module_base)),
		inp32(SOC_FFAP1_CPUIF_DRAIN_UID_ADDR(module_base)));

	dump_aae_dacc_trace_reg(aae_base);
	dump_aae_dacc_cmdlist_status(aae_base);

	aae_pr_warn("DACC LOG:\n");
	for (i = 0; i < AAE_DACC_LOG_DUMP_REG_COUNT; i += AAE_ONE_LINE_PRINT_REG_COUNT) {
		aae_pr_warn("\t :%8x%12x%12x%12x\n",
			inp32(AAE_DACC_LOG_DUMP_REG_ADDR(aae_base, i)),
			inp32(AAE_DACC_LOG_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_ONE)),
			inp32(AAE_DACC_LOG_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_TWO)),
			inp32(AAE_DACC_LOG_DUMP_REG_ADDR(aae_base, i + AAE_REG_INDEX_THREE)));
	}
}

static void aae_dump_opr_rxx_wxx(char* opr, uint32_t opr_idx,
	char __iomem *read_base, char __iomem *write_base)
{
	uint32_t rxx_ycnt, wxx_ycnt;

	if (read_base != NULL) {
		/* rxx_ycnt: R_LB_DEBUG2.bit13~25 */
		rxx_ycnt = inp32(read_base + AAE_OPR_DUMP_SECOND_REG_OFFSET);
		rxx_ycnt &= (BIT(26) - 1);
		rxx_ycnt >>= 13;
	}

	if (write_base != NULL) {
		/* wxx_ycnt: W_LB_DEBUG1.bit19~31 */
		wxx_ycnt = inp32(write_base + AAE_OPR_DUMP_FIRST_REG_OFFSET);
		wxx_ycnt >>= 19;
	}

	if (read_base != NULL && write_base != NULL) {
		aae_pr_warn("%s[%u]:rxx_ycnt=%u, wxx_ycnt=%u\n"
			"\tR_LB_DEBUG0=%#x\t\tR_LB_DEBUG1=%#x\t\tR_LB_DEBUG2=%#x\t\tR_LB_DEBUG3=%#x\n"
			"\tW_LB_DEBUG0=%#x\t\tW_LB_DEBUG1=%#x\t\tW_LB_DEBUG2=%#x\t\tW_LB_DEBUG3=%#x\n\n",
			opr, opr_idx, rxx_ycnt, wxx_ycnt,
			inp32(read_base), inp32(read_base + AAE_OPR_DUMP_FIRST_REG_OFFSET),
			inp32(read_base + AAE_OPR_DUMP_SECOND_REG_OFFSET), inp32(read_base + AAE_OPR_DUMP_THIRD_REG_OFFSET),
			inp32(write_base), inp32(write_base + AAE_OPR_DUMP_FIRST_REG_OFFSET),
			inp32(write_base + AAE_OPR_DUMP_SECOND_REG_OFFSET), inp32(write_base + AAE_OPR_DUMP_THIRD_REG_OFFSET));
		return;
	}
	return;
}

static void dump_aae_opr_reg(char __iomem *aae_base)
{
	uint32_t i = 0;
	char __iomem *module_base = NULL;
	for (i = 0; i < OPR_CLD_NUM; ++i) {
		module_base = aae_base + g_aae_cld_offset[i];
		aae_dump_opr_rxx_wxx("CLD", i,
			AAE_CLD_R_LB_DEBUG0_ADDR(module_base), AAE_CLD_W_LB_DEBUG0_ADDR(module_base));
	}
	for (i = 0; i < OPR_VSCF_NUM; ++i) {
		module_base = aae_base + g_aae_vscf_offset[i];
		aae_dump_opr_rxx_wxx("VSCF", i,
			AAE_VSCF_R_LB_DEBUG0_ADDR(module_base), AAE_VSCF_W_LB_DEBUG0_ADDR(module_base));
	}
	for (i = 0; i < OPR_ARSR_NUM; ++i) {
		if(g_aae_arsr_offset[i] == AAE_INVALID_OFFSET)
			continue;
		module_base = aae_base + g_aae_arsr_offset[i];
		aae_dump_opr_rxx_wxx("ARSR", i,
			AAE_ARSR_R_LB_DEBUG0_ADDR(module_base), AAE_ARSR_W_LB_DEBUG0_ADDR(module_base));
	}
	module_base = aae_base + AAE_WDFC_OFFSET;
	aae_pr_warn("WDFC:\n\tBITEXT0_DBG0=%#x\n\n",
		inp32(AAE_WDFC_BITEXT0_DBG0_ADDR(module_base)));
	module_base = aae_base + AAE_BLUR_OFFSET;
	aae_pr_warn("BLUR:\n\tBLUR_DBG0=%#x\t\tBLUR_DBG1=%#x\t\tGFILT_DBG0=%#x\t\tGFILT_DBG0=%#x\n\n",
		inp32(AAE_BLUR_DBG0_ADDR(module_base)), inp32(AAE_BLUR_DBG1_ADDR(module_base)),
		inp32(AAE_BLUR_GFILT_DBG0_ADDR(module_base)), inp32(AAE_BLUR_GFILT_DBG1_ADDR(module_base)));
	module_base = aae_base + AAE_HIOF_OFFSET;
	aae_pr_warn("HIOF:\n\tDEBUG_RO1=%#x\t\tDEBUG_RO2=%#x\n\n",
		inp32(AAE_HIOF_DEBUG_RO1_ADDR(module_base)), inp32(AAE_HIOF_DEBUG_RO2_ADDR(module_base)));
	module_base = aae_base + AAE_BLPP_OFFSET;
	aae_pr_warn("BLPP:\n\tBLPP_DBG0=%#x\t\tBLPP_DBG1=%#x\n\n",
		inp32(AAE_BLPP_DBG0_ADDR(module_base)), inp32(AAE_BLPP_DBG1_ADDR(module_base)));
}

static void dump_aae_dm_layer_info(char __iomem *aae_base)
{
	uint32_t i = 0;
	char __iomem *module_base = aae_base + g_dm_tlb_info[AAE_SCENE_0].dm_data_addr;
	aae_pr_warn("SCENE_INFO:\n\tLAYER_NUMBER=%#x\n\n", inp32(AAE_DM_LAYER_NUMBER_ADDR(module_base)));
	for (i = 0; i < AAE_DM_LAYER_INFO_REG_COUNT; ++i) {
		aae_pr_warn("Layer[%d]:\n"
			"\tlayer_height=%#x\t\tlayer_mask_y0=%#x\t\tlayer_mask_y1=%#x\t\tlayer_rot_en=%#x\t\tlayer_sblk_type=%#x\n"
			"\tlayer_stretch3_line=%#x\t\tlayer_start_addr3_h=%#x\t\tlayer_start_addr0_l=%#x\t\tlayer_start_addr1_l=%#x\n"
			"\tlayer_start_addr2_l=%#x\t\tlayer_start_addr3_l=%#x\t\tlayer_stride0=%#x\t\tlayer_stride1=%#x\n"
			"\tlayer_stride2=%#x\t\tlayer_rsv0=%#x\t\tlayer_bot_crop=%#x\t\tlayer_clip_left=%#x\n"
			"\tlayer_ov_mitm_degamma_reg_sel=%#x\t\tlayer_ov_starty=%#x\t\tlayer_ov_endy=%#x\t\tlayer_ov_partern=%#x\n"
			"\tlayer_ov_partern_rgb=%#x\t\tlayer_ov_mode=%#x\t\tlayer_ov_alpga=%#x\n\n", i,
			inp32(AAE_DM_LAYER_HEIGHT_ADDR(module_base, i)), inp32(AAE_DM_LAYER_MASK_Y0_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_MASK_Y1_ADDR(module_base, i)), inp32(AAE_DM_LAYER_ROT_EN_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_SBLK_TYPE_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_STRETCH3_LINE_ADDR(module_base, i)), inp32(AAE_DM_LAYER_START_ADDR3_H_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_START_ADDR0_L_ADDR(module_base, i)), inp32(AAE_DM_LAYER_START_ADDR1_L_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_START_ADDR2_L_ADDR(module_base, i)), inp32(AAE_DM_LAYER_START_ADDR3_L_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_STRIDE0_ADDR(module_base, i)), inp32(AAE_DM_LAYER_STRIDE1_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_STRIDE2_ADDR(module_base, i)), inp32(AAE_DM_LAYER_STRIDE3_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_BOT_CROP_ADDR(module_base, i)), inp32(AAE_DM_LAYER_CLIP_LEFT_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_OV_DFC_CFG_ADDR(module_base, i)), inp32(AAE_DM_LAYER_OV_STARTY_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_OV_ENDY_ADDR(module_base, i)), inp32(AAE_DM_LAYER_OV_PATTERN_A_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_OV_PATTERN_RGB_ADDR(module_base, i)), inp32(AAE_DM_LAYER_OV_MODE_ADDR(module_base, i)),
			inp32(AAE_DM_LAYER_OV_ALPHA_ADDR(module_base, i)));
	}
}

static void dump_aae_dm_wch_info(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + g_dm_tlb_info[AAE_SCENE_0].dm_data_addr;
	aae_pr_warn("WCH:\n\twch_input_img_width=%#x\t\twch_input_img_stry=%#x\t\twch_sel=%#x\t\twch_reserved_1=%#x\n\n",
		inp32(AAE_DM_WCH_INPUT_IMG_WIDTH_ADDR(module_base)), inp32(AAE_DM_WCH_INPUT_IMG_STRY_ADDR(module_base)),
		inp32(AAE_DM_WCH_SEL_ADDR(module_base)), inp32(AAE_DM_WCH_RESERVED_1_ADDR(module_base)));
}

static void dump_aae_dm_wdma_info(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + AAE_WCH_OFFSET;
	aae_pr_warn("WDMA:\n\tDMA_CTRL0=%#x\t\tDMA_CTRL1=%#x\t\tDMA_IMG_SIZE=%#x\n"
		"\tDMA_PTR0=%#x\t\tDMA_STRIDE0=%#x\t\tDMA_PTR1=%#x\t\tDMA_STRIDE1=%#x\n"
		"\tDMA_PTR2=%#x\t\tDMA_STRIDE2=%#x\t\tDMA_PTR3=%#x\t\tDMA_STRIDE3=%#x\n"
		"\tDMA_PTR0_H=%#x\t\tDMA_PTR1_H=%#x\t\tDMA_PTR2_H=%#x\t\tDMA_PTR3_H=%#x\n",
		inp32(module_base + 0x0000), inp32(module_base + 0x0004), inp32(module_base + 0x0008),
		inp32(module_base + 0x000C), inp32(module_base + 0x0010), inp32(module_base + 0x0014), inp32(module_base + 0x0018),
		inp32(module_base + 0x001C), inp32(module_base + 0x0020), inp32(module_base + 0x0024), inp32(module_base + 0x0028),
		inp32(module_base + 0x007C), inp32(module_base + 0x0080), inp32(module_base + 0x0084), inp32(module_base + 0x0088)
		);
}

static void dump_aae_dm_cmdlist_addr_info(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + g_dm_tlb_info[AAE_SCENE_0].dm_data_addr;
	aae_pr_warn("CMDLIST_ADDR:\n\tcmdlist_addr_h=%#x\t\tcmdlist_addr0=%#x\t\tcmdlist_addr1=%#x\n"
		"\tcmdlist_addr2=%#x\t\tcmdlist_addr3=%#x\t\tcmdlist_addr4=%#x\n"
		"\tcmdlist_addr5=%#x\t\tcmdlist_addr6=%#x\t\tcmdlist_addr7=%#x\t\tcmdlist_addr8=%#x\n\n",
		inp32(AAE_DM_CMDLIST_ADDR_H_ADDR(module_base)), inp32(AAE_DM_CMDLIST_ADDR0_ADDR(module_base)),
		inp32(AAE_DM_CMDLIST_ADDR1_ADDR(module_base)), inp32(AAE_DM_CMDLIST_ADDR2_ADDR(module_base)),
		inp32(AAE_DM_CMDLIST_ADDR3_ADDR(module_base)), inp32(AAE_DM_CMDLIST_ADDR4_ADDR(module_base)),
		inp32(AAE_DM_CMDLIST_ADDR5_ADDR(module_base)), inp32(AAE_DM_CMDLIST_ADDR6_ADDR(module_base)),
		inp32(AAE_DM_CMDLIST_ADDR7_ADDR(module_base)), inp32(AAE_DM_CMDLIST_ADDR8_ADDR(module_base)));
}

static void dump_aae_dbcu_info(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + AAE_DBCU_OFFSET;
	aae_pr_warn("DBCU:\n"
		"\tMONITOR_OS_R0=%#x\t\tMONITOR_OS_R1=%#x\t\tMONITOR_OS_R2=%#x\t\tMONITOR_OS_R3=%#x\t\tMONITOR_OS_R4=%#x\n"
		"\tMONITOR_OS_W0=%#x\t\tMONITOR_OS_W1=%#x\t\tMONITOR_OS_W2=%#x\t\tMONITOR_OS_W3=%#x\n"
		"\tAIF_STAT_0=%#x\t\tAIF_STAT_1=%#x\t\tAIF_STAT_2=%#x\t\tAIF_STAT_3=%#x\n"
		"\tAIF_STAT_4=%#x\t\tAIF_STAT_5=%#x\t\tAIF_STAT_6=%#x\t\tAIF_STAT_7=%#x\n"
		"\tAIF_STAT_8=%#x\t\tAIF_STAT_9=%#x\t\tAIF_STAT_10=%#x\t\tAIF_STAT_11=%#x\n"
		"\tAIF_STAT_12=%#x\t\tAIF_STAT_13=%#x\t\tAIF_STAT_14=%#x\t\tAIF_STAT_15=%#x\n\n",
		inp32(AAE_DBCU_MONITOR_OS_R0_ADDR(module_base)), inp32(AAE_DBCU_MONITOR_OS_R1_ADDR(module_base)),
		inp32(AAE_DBCU_MONITOR_OS_R2_ADDR(module_base)), inp32(AAE_DBCU_MONITOR_OS_R3_ADDR(module_base)),
		inp32(AAE_DBCU_MONITOR_OS_R4_ADDR(module_base)),
		inp32(AAE_DBCU_MONITOR_OS_W0_ADDR(module_base)), inp32(AAE_DBCU_MONITOR_OS_W1_ADDR(module_base)),
		inp32(AAE_DBCU_MONITOR_OS_W2_ADDR(module_base)), inp32(AAE_DBCU_MONITOR_OS_W3_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_0_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_1_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_2_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_3_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_4_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_5_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_6_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_7_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_8_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_9_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_10_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_11_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_12_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_13_ADDR(module_base)),
		inp32(AAE_DBCU_AIF_STAT_14_ADDR(module_base)), inp32(AAE_DBCU_AIF_STAT_15_ADDR(module_base)));
}

static bool is_aae_clk_open(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + AAE_GLB0_OFFSET;
	uint32_t glb0_clk_en = 0;
	glb0_clk_en = inp32(AAE_GLB_PART0_AAE_PART_CLK_EN_ADDR(module_base));
	if ((glb0_clk_en & AAE_GLB_PART0_MODULE_CLK_ENABLE) == AAE_GLB_PART0_MODULE_CLK_ENABLE) {
		return true;
	}
	return false;
}

static void dump_aae_exp_reg(char __iomem *aae_base)
{
	char __iomem *module_base = aae_base + AAE_GLB0_OFFSET;
	aae_pr_warn("CRG:\n\nAAE_PART_CLK_EN=%#x\t\tAAE_PART_RST_EN=%#x\t\tMODULE_CLK_SEL=%#x\t\tMODULE_CLK_EN=%#x\n\n",
		inp32(AAE_GLB_PART0_AAE_PART_CLK_EN_ADDR(module_base)),
		inp32(AAE_GLB_PART0_AAE_PART_RST_EN_ADDR(module_base)),
		inp32(AAE_GLB_PART0_MODULE_CLK_SEL_ADDR(module_base)),
		inp32(AAE_GLB_PART0_MODULE_CLK_EN_ADDR(module_base)));
	aae_pr_warn("ip_status: DBG_IP_STATE0=%#x DBG_IP_STATE1=%#x",
		inp32(AAE_GLB_PART0_DBG_IP_STATE0_ADDR(module_base)), inp32(AAE_GLB_PART0_DBG_IP_STATE1_ADDR(module_base)));
	aae_pr_warn("OV:\n\tDBG_OV_YCNT0=%#x\n\n",
		inp32(AAE_GLB_PART0_DBG_OV_YCNT0_ADDR(module_base)));
	udelay(10);
	aae_pr_warn("OV:\n\tDBG_OV_YCNT0=%#x\n\n",
		inp32(AAE_GLB_PART0_DBG_OV_YCNT0_ADDR(module_base)));
	udelay(10);
	aae_pr_warn("OV:\n\tDBG_OV_YCNT0=%#x\n\n",
		inp32(AAE_GLB_PART0_DBG_OV_YCNT0_ADDR(module_base)));
	dump_aae_sdma_dbg_info(module_base);
	dump_aae_dm_layer_info(aae_base);
	dump_aae_dm_wch_info(aae_base);
	dump_aae_dm_wdma_info(aae_base);
	dump_aae_dm_cmdlist_addr_info(aae_base);
	if (is_aae_clk_open(aae_base)) {
		dump_aae_opr_reg(aae_base);
	}
	dump_aae_dbcu_info(aae_base);
	dump_aae_dacc_reg(aae_base);
	aae_exception_dacc_log_dump();
}

static int32_t reset_aae(struct aae_manager *aae_mgr)
{
	int32_t ret = 0;
	aae_pr_info("+");
	ret = aae_tbu_disconnect(aae_mgr->aae_base);
	if (ret < 0) {
		aae_pr_err("tbu disconnect failed");
		return ret;
	}
	aae_power_down(aae_mgr);
	aae_power_up(aae_mgr);
	ret = aae_init(aae_mgr);
	if (ret < 0) {
		aae_pr_err("aae init failed");
		return ret;
	}
	aae_pr_info("-");
	return ret;
}

void mask_aae_dacc_isr(char __iomem *aae_base)
{
	aae_check_and_no_retval(!aae_base, err, "aae_base is null!");
	/* interrupt mask */
	set_reg(AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_GIC_MSK_ADDR(aae_base + AAE_GLB0_OFFSET), 1, 1, 3);
	set_reg(AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_GIC_MSK_ADDR(aae_base + AAE_GLB0_OFFSET), 1, 1, 3);
	set_reg(AAE_GLB_PART0_DACC_NS_INT_MSK_ADDR(aae_base + AAE_GLB0_OFFSET), 1, 1, 16);
}

void umask_aae_dacc_isr(char __iomem *aae_base)
{
	aae_check_and_no_retval(!aae_base, err, "aae_base is null!");
	/* interrupt mask */
	set_reg(AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_GIC_MSK_ADDR(aae_base + AAE_GLB0_OFFSET), 0, 1, 3);
	set_reg(AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_GIC_MSK_ADDR(aae_base + AAE_GLB0_OFFSET), 0, 1, 3);
	set_reg(AAE_GLB_PART0_DACC_NS_INT_MSK_ADDR(aae_base + AAE_GLB0_OFFSET), 0, 1, 16);
}

int32_t aae_exp_handle(struct aae_manager *aae_mgr)
{
	int32_t ret = 0;
	aae_pr_info("+");
	aae_check_and_return(!aae_mgr, -1, err, "aae_mgr is null!");
	aae_check_and_return(!aae_mgr->aae_regulator, -1, err, "aae_regulator is null!");
	aae_check_and_return(!aae_mgr->aae_base, -1, err, "aae_base is null!");

	/* ensure that aae is not powered off during exp handling. */
	ret = aae_regulator_enable(aae_mgr);
	if (ret) {
		aae_pr_err("aae_regulator enable failed, error=%d!", ret);
		return ret;
	}

	/*
	 * regulator_enable interface is returned after the XPU clear the interrupt.
	 * this interface does not wait for the completion of AAE initialization,
	 * so here, need wait until the AAE initialization is complete.
	 */
	ret = wait_ffap_pt_link(aae_mgr->aae_base);
	if (ret) {
		aae_pr_err("wait ffap pt link timeout");
		goto err;
	}

	aae_send_uevent(AAE_RES_EVENT_AAE_RESET);
	config_ffap_exp_handle(aae_mgr->aae_base);
	dump_aae_exp_reg(aae_mgr->aae_base);
	ret = reset_aae(aae_mgr);
	if (ret) {
		aae_pr_err("reset aae failed, error=%d!", ret);
	}
	aae_send_uevent(AAE_RES_EVENT_AAE_READY);

err:
	umask_aae_dacc_isr(aae_mgr->aae_base);
	ret = aae_regulator_disable(aae_mgr);
	if (ret) {
		aae_pr_err("aae_regulator disable failed, error=%d!", ret);
		return ret;
	}
	aae_pr_info("-");
	return ret;
}