/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: venc register config
 */
#include "hal_venc.h"
#include "hal_venc_product.h"
#include <linux/mm_lb/mm_lb.h>
#include "soc_smmuv3_tbu_interface.h"
#include "smmu_cfg.h"
#include "smmu_regs.h"
#ifdef CONFIG_SOC_PG_INFO
#include <platform_include/basicplatform/linux/soc_spec.h>
#include "soc_spec_common.h"
#endif
#ifdef VENC_MCORE_ENABLE
#include "drv_venc_ipc.h"

void venc_dump_dfx_info(uint32_t *reg_base)
{
	U_VEDU_VCPI_MODE vcpi_mode;
	uint32_t vcpi_frame_no;
	U_VEDU_VCPI_INTRA_INTER_CU_EN vcpi_intra_inter_cu_en;
	uint32_t pmv_poc_0;
	U_VEDU_VCPI_PICSIZE_PIX vcpi_picsize_pix;

	if (reg_base == NULL) {
		VCODEC_ERR_VENC("reg_base is invalid");
		return;
	}
	U_VEDU_PPFD_ST_CFG d32;
	d32.u32 = readl(reg_base + 0x0048 / 4);
	// readback
	VCODEC_INFO_VENC("VEDU_VCPI_INTMASK      : %#x", readl(reg_base + 0x0000 / 4)); // VEDU_VCPI_INTMASK
	VCODEC_INFO_VENC("FUNC_VCPI_INTSTAT      : %#x", readl(reg_base + 0x3000 / 4)); // FUNC_VCPI_INTSTAT
	VCODEC_INFO_VENC("FUNC_VCPI_RAWINT : %#x", readl(reg_base + 0x3004 / 4)); // FUNC_VCPI_RAWINT
	VCODEC_INFO_VENC("FUNC_VCPI_VEDU_TIMER : %#x", readl(reg_base + 0x3008 / 4)); // FUNC_VCPI_VEDU_TIMER
	VCODEC_INFO_VENC("FUNC_VCPI_IDLE_TIMER : %#x", readl(reg_base + 0x300c / 4)); // FUNC_VCPI_IDLE_TIMER
	VCODEC_INFO_VENC("FUNC_VCPI_BUS_IDLE_FLAG : %#x", readl(reg_base + 0x3010 / 4)); // FUNC_VCPI_BUS_IDLE_FLAG
	VCODEC_INFO_VENC("FUNC_VLCST_STRM_LEN_CNT : %#x", readl(reg_base + 0x384c / 4)); // FUNC_VLCST_STRM_LEN_CNT

	// sub ctrl
	VCODEC_INFO_VENC("SUBCTRL_HW_BUF_LEN : %#x", readl(reg_base + 0x24040 / 4)); // SUBCTRL_HW_BUF_LEN

	// dfx
	// VCTRL_PIPE_STATE_L: reg_4104
	//   10:recst_lite2vctrl_picend[2] 11:vlcst_lite2vctrl_picend[2] 12:recst_lite2vctrl_picend[1]
	//   13:vlcst_lite2vctrl_picend[1] 14:recst_lite2vctrl_picend[0] 15:vlcst_lite2vctrl_picend[0]
	//   16:pmest2vctrl_pic_end        17:pmest_info2vctrl_pic_end   18:bgstr2vctrl_pic_end
	//   19:bgst_inf2vctrl_pic_end     20:bgld2vctrl_pic_end         21:bggen2vctrl_pic_end
	//   22:vlcst2vctrl_picend         23:recst2vctrl_picend         24:nbi2vctrl_picend
	//   25:qpg2vctrl_pic_end          26:tbldst2vctrl_picend
	// VENC MODULE STATUS: reg_4108
	//   1:curld_vaild 2:nbi_vailid 3:pmeld_valid 4:pmeinfo_ld_valid 5:pem_valid 6:curld_sw_valid
	//   6:curld_sw_valid 7:bggen_valid 8:refld_luma_valid 9:qpg_valid 10:ime_valid 11:pintra_valid
	//   12:refld_luma_valid 13:fme_valid 14:intra_valid 15:mrg_valid 16:pmv_valid 17:sel_valid
	//   18:rpintra_valid 19:mestat_valid 20:mcucfg_valid 22:dblk_valid 23:sao_valid 24:pack_valid
	//   25:ppfd_valid 28:cabac_valid 29:vlc_valid
	// FLBC WRAP DBG OUT: reg_446c
	//   20:indicate flbc decmp err
	// HEBCD DCMP ERR HISTORY: reg_5000
	//   15'd0, low_latency_cfg_check_err_history 4'd0, hebcd_dcmp_err_history[3:0] 4'd0, hebcd_dcmp_err[3:0]
	VCODEC_INFO_VENC("VCTRL PIPE STATE L     : %#x", readl(reg_base + 0x4104 / 4)); // vctrl pipe state l
	VCODEC_INFO_VENC("VENC MODULE STATUS L   : %#x", readl(reg_base + 0x4108 / 4)); // venc module state l
	VCODEC_INFO_VENC("VENC MODULE STATUS H   : %#x", readl(reg_base + 0x410c / 4)); // venc module state h
	VCODEC_INFO_VENC("VENC ENCODE MB         : %#x", readl(reg_base + 0x411c / 4)); // VENC ENCODE MB
	VCODEC_INFO_VENC("DFX_PIC_CNT            : %#x", readl(reg_base + 0x4400 / 4)); // dfx_pic_cnt
	VCODEC_INFO_VENC("DFX_LCU_CNT            : %#x", readl(reg_base + 0x4404 / 4)); // dfx_lcu_cnt
	VCODEC_INFO_VENC("DFX_LCU_X              : %#x", readl(reg_base + 0x4408 / 4)); // dfx_lcu_x
	VCODEC_INFO_VENC("DFX_LCU_Y              : %#x", readl(reg_base + 0x440c / 4)); // dfx_lcu_y
	VCODEC_INFO_VENC("HEBC DECMP STATUS      : %#x", readl(reg_base + 0x4438 / 4)); // 0:decmp_err 1:head len err
	VCODEC_INFO_VENC("FLBC WRAP DBG OUT      : %#x", readl(reg_base + 0x446C / 4)); // flbc wrap dbg out
	VCODEC_INFO_VENC("HEBCD DCMP ERR HISTORY : %#x", readl(reg_base + 0x5000 / 4)); // hebcd_dcmp_err_history

	// cfg
	vcpi_mode.u32 = readl(reg_base + offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_MODE.u32) / 4);
	vcpi_frame_no = readl(reg_base + offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_FRAMENO) / 4);
	vcpi_intra_inter_cu_en.u32 = readl(reg_base + offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_INTRA_INTER_CU_EN.u32) / 4);
	pmv_poc_0 = readl(reg_base + offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_PMV_POC_0) / 4);
	vcpi_picsize_pix.u32 = readl(reg_base + offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PICSIZE_PIX) / 4);

	VCODEC_INFO_VENC("FRAME INFO : %s %ux%u %dbits, frame number %u, poc %u, type %u",
		vcpi_mode.bits.vcpi_protocol == 0 ? "H265" : "H264",
		vcpi_picsize_pix.bits.vcpi_imgwidth_pix, vcpi_picsize_pix.bits.vcpi_imgheight_pix,
		vcpi_mode.bits.vcpi_10bit_mode ? 10 : 8,
		vcpi_frame_no, pmv_poc_0,
		vcpi_mode.bits.vcpi_frame_type);
	VCODEC_INFO_VENC("VEDU_VCPI_MODE : %#x", vcpi_mode.u32); // vcpi mode
	VCODEC_INFO_VENC("    vcpi_lcu_rdo_ctrl_en : %u", vcpi_mode.bits.vcpi_lcu_rdo_ctrl_en);
	VCODEC_INFO_VENC("    vcpi_time_en : %u", vcpi_mode.bits.vcpi_time_en);
	VCODEC_INFO_VENC("    vcpi_scaling_list_en : %u", vcpi_mode.bits.vcpi_scaling_list_en);
	VCODEC_INFO_VENC("    vcpi_ref_num : %u", vcpi_mode.bits.vcpi_ref_num);
	VCODEC_INFO_VENC("    vedu_selfrst_en : %u", vcpi_mode.bits.vedu_selfrst_en);
	VCODEC_INFO_VENC("VEDU_VCPI_INTRA_INTER_CU_EN : %#x", vcpi_intra_inter_cu_en.u32); // intra cu info
	VCODEC_INFO_VENC("    vcpi_mrg_cu_en : %u", vcpi_intra_inter_cu_en.bits.vcpi_mrg_cu_en);
	VCODEC_INFO_VENC("    vcpi_fme_cu_en : %u", vcpi_intra_inter_cu_en.bits.vcpi_fme_cu_en);
	VCODEC_INFO_VENC("    vcpi_intra_cu_en : %u", vcpi_intra_inter_cu_en.bits.vcpi_intra_cu_en);

#ifdef VENC_SC_HINT_PGID_BY_MASTER
	VCODEC_INFO_VENC("lb_pgid_cnt : %u", lb_pgid_cnt(PID_VENC));
#endif
}

void venc_mcore_start_encode(struct encode_info *info, S_HEVC_AVC_REGS_TYPE *vedu_reg)
{
	struct ipc_message msg = {0};
	msg.id = IPC_MSG_START_ENCODE;
	msg.data[0] = info->channel.id;
	venc_ipc_send_msg(MBX1, &msg);
}

static void vedu_hal_set_int_mcu(uint32_t *reg_base)
{
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_INTMASK.u32),
				 VENC_MASK_WITH_MCU); /* slice_end/soft int1 */
}
#endif

#ifndef VENC_MCORE_ENABLE
static void vedu_hal_set_int_without_mcu(uint32_t *reg_base)
{
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_INTMASK.u32),
		CMDLIST_MASK); /* slice_end/soft int0 */
}
#endif

void vedu_hal_set_int(uint32_t *reg_base)
{
#ifdef VENC_MCORE_ENABLE
	vedu_hal_set_int_mcu(reg_base);
#else
	vedu_hal_set_int_without_mcu(reg_base);
#endif
}

#ifndef VENC_MCORE_ENABLE
static void vedu_hal_cfg_without_mcu(volatile uint32_t *base, uint32_t offset, uint32_t value)
{
	hal_cmdlist_wr_cmd_in_len0(offset, value);
}
#endif

void vedu_hal_cfg(volatile uint32_t *base, uint32_t offset, uint32_t value)
{
#ifdef VENC_MCORE_ENABLE
	base[offset / 4] = value;
#else
	vedu_hal_cfg_without_mcu(base, offset, value);
#endif
}

void venc_hal_get_reg_stream_len(struct stream_info *stream_info, uint32_t *reg_base)
{
	int i;
	S_HEVC_AVC_REGS_TYPE *all_reg = (S_HEVC_AVC_REGS_TYPE *)reg_base; /*lint !e826 */
	volatile U_FUNC_VLCST_DSRPTR00 *base0 = all_reg->FUNC_VLCST_DSRPTR00;
	volatile U_FUNC_VLCST_DSRPTR01 *base1 = all_reg->FUNC_VLCST_DSRPTR01;

	for (i = 0; i < MAX_SLICE_NUM; i++) {
		stream_info->slice_len[i] = base0[i].bits.slc_len0 - base1[i].bits.invalidnum0;
		stream_info->aligned_slice_len[i] = base0[i].bits.slc_len0;
		stream_info->slice_num++;
		if (base1[i].bits.islastslc0)
			break;
	}
}

void venc_hal_cfg_curld_osd01(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	U_VEDU_CURLD_RGB_CLIP D32;

	D32.bits.rgb_clip_min = channel_cfg->all_reg.VEDU_CURLD_RGB_CLIP.bits.rgb_clip_min;
	D32.bits.rgb_clip_max = channel_cfg->all_reg.VEDU_CURLD_RGB_CLIP.bits.rgb_clip_max;
	D32.bits.curld_cmp_clk_gt_en = channel_cfg->all_reg.VEDU_CURLD_RGB_CLIP.bits.curld_cmp_clk_gt_en;
	D32.bits.curld_cmp_tag_en = channel_cfg->all_reg.VEDU_CURLD_RGB_CLIP.bits.curld_cmp_tag_en;
	D32.bits.curld_cmp_raw_en = channel_cfg->all_reg.VEDU_CURLD_RGB_CLIP.bits.curld_cmp_raw_en;
	D32.bits.flbc_lut_qp_delta = channel_cfg->all_reg.VEDU_CURLD_RGB_CLIP.bits.flbc_lut_qp_delta;
	D32.bits.flbc_chroma_qp_offset_strength = channel_cfg->all_reg.VEDU_CURLD_RGB_CLIP.bits.flbc_chroma_qp_offset_strength;

	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_RGB_CLIP.u32), D32.u32);
}

static void venc_hal_cfg_ime(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	uint32_t i;

	/* according to <VcodecV800 IT Environment Constrain> 2.1.1 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_INTER_MODE.u32),
		channel_cfg->all_reg.VEDU_IME_INTER_MODE.u32);

	/* according to <VcodecV800 IT Environment Constrain> 2.2 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO2_THR.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO2_THR.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO2_THR1.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO2_THR1.u32);

	/* according to <VcodecV800 IT Environment Constrain> 2.3 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO1_THR.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO1_THR.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO1_THR1.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO1_THR1.u32);

	/* according to <VcodecV800 IT Environment Constrain> 2.4 ~ 2.8 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_ET_THR.u32),
		channel_cfg->all_reg.VEDU_ME_ET_THR.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_ET_THR_ME_STAT.u32),
		channel_cfg->all_reg.VEDU_ME_ET_THR_ME_STAT.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_REF_BUF_WORD_NUM.u32),
		channel_cfg->all_reg.VEDU_IME_REF_BUF_WORD_NUM.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_INTERPOLATION_FLAG.u32),
		channel_cfg->all_reg.VEDU_IME_INTERPOLATION_FLAG.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_MAX_REGION.u32),
		channel_cfg->all_reg.VEDU_ME_MAX_REGION.u32);

	/* according to <VcodecV800 IT Environment Constrain> 2.4 ~ 2.8 */
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_TMV_EN.u32),
		channel_cfg->all_reg.VEDU_ME_TMV_EN.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_TMV_SCALE),
		channel_cfg->all_reg.VEDU_ME_TMV_SCALE);
	// v900 add
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_TMV_SCALE_1),
		channel_cfg->all_reg.VEDU_ME_TMV_SCALE_1);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_TMV_SCALE_2),
		channel_cfg->all_reg.VEDU_ME_TMV_SCALE_2);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_TMV_SCALE_3),
		channel_cfg->all_reg.VEDU_ME_TMV_SCALE_3);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ISPLD_REF1_CENTER_SCALE),
		channel_cfg->all_reg.VEDU_ISPLD_REF1_CENTER_SCALE);

	/* according to <VcodecV800 IT Environment Constrain> 2.9 */
	for (i = 0; i < 20; i++)
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_ADD1_RANDOM_POINT_LIST.u32) + i * sizeof(uint32_t),
			*(&channel_cfg->all_reg.VEDU_ME_ADD1_RANDOM_POINT_LIST.u32 + i));
	// v900 add
	for (i = 0; i < 20; i++)
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_ADD1_RANDOM_POINT_LIST_B.u32) + i * sizeof(uint32_t),
			*(&channel_cfg->all_reg.VEDU_ME_ADD1_RANDOM_POINT_LIST_B.u32 + i));
}

static void venc_hal_cfg_buffer(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	uint32_t i;

	/* according to <VcodecV800 IT Environment Constrain> 1.16 and 1.17 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_REC_HEADER_STRIDE.u32),
		channel_cfg->all_reg.VEDU_VCPI_REC_HEADER_STRIDE.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_REF_L0_HEADER_STRIDE.u32),
		channel_cfg->all_reg.VEDU_VCPI_REF_L0_HEADER_STRIDE.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_REF_L1_HEADER_STRIDE.u32),
		channel_cfg->all_reg.VEDU_VCPI_REF_L1_HEADER_STRIDE.u32);

	/* according to <VcodecV800 IT Environment Constrain> 4.1 */
	for (i = 0; i < 16; i++) {
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMADDR_L_NEW[i]),
			channel_cfg->all_reg.VEDU_VCPI_STRMADDR_L_NEW[i]);

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMADDR_H_NEW[i]),
			channel_cfg->all_reg.VEDU_VCPI_STRMADDR_H_NEW[i]);

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMBUFLEN_NEW[i]),
			channel_cfg->all_reg.VEDU_VCPI_STRMBUFLEN_NEW[i]);
	}
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SLCINFOADDR_L_NEW),
		channel_cfg->all_reg.VEDU_VCPI_SLCINFOADDR_L_NEW);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SLCINFOADDR_H_NEW),
		channel_cfg->all_reg.VEDU_VCPI_SLCINFOADDR_H_NEW);
}

static void venc_hal_cfg_curld_clip(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	{
		U_VEDU_CURLD_CLIP_THR_Y clip_thr;

		clip_thr.bits.clip_min_y =
			channel_cfg->all_reg.VEDU_CURLD_CLIP_THR_Y.bits.clip_min_y;
		clip_thr.bits.clip_max_y =
			channel_cfg->all_reg.VEDU_CURLD_CLIP_THR_Y.bits.clip_max_y;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_CLIP_THR_Y.u32), clip_thr.u32);
	}

	{
		U_VEDU_CURLD_CLIP_THR_C clip_thr;

		clip_thr.bits.clip_min_c =
			channel_cfg->all_reg.VEDU_CURLD_CLIP_THR_C.bits.clip_min_c;
		clip_thr.bits.clip_max_c =
			channel_cfg->all_reg.VEDU_CURLD_CLIP_THR_C.bits.clip_max_c;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_CLIP_THR_C.u32), clip_thr.u32);
	}
}

static void venc_hal_cfg_curld_pre_mod_para(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	{
		U_VEDU_RGB2YUV_COEF_P3 coef_p3;

		coef_p3.bits.rgb2yuv_v_0coef =
			channel_cfg->all_reg.VEDU_RGB2YUV_COEF_P3.bits.rgb2yuv_v_0coef;
		coef_p3.bits.rgb2yuv_v_1coef =
			channel_cfg->all_reg.VEDU_RGB2YUV_COEF_P3.bits.rgb2yuv_v_1coef;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_RGB2YUV_COEF_P3.u32), coef_p3.u32);
	}

	{
		U_VEDU_RGB2YUV_COEF_P4 coef_p4;

		coef_p4.bits.rgb2yuv_v_2coef =
			channel_cfg->all_reg.VEDU_RGB2YUV_COEF_P4.bits.rgb2yuv_v_2coef;
		coef_p4.bits.rgb_v_rnd =
			channel_cfg->all_reg.VEDU_RGB2YUV_COEF_P4.bits.rgb_v_rnd;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_RGB2YUV_COEF_P4.u32), coef_p4.u32);
	}

	{
		U_VEDU_CURLD_NARROW_CHRM narrow_chrm;

		narrow_chrm.bits.curld_narrow_chrm_max =
			channel_cfg->all_reg.VEDU_CURLD_NARROW_CHRM.bits.curld_narrow_chrm_max;
		narrow_chrm.bits.curld_narrow_chrm_min =
			channel_cfg->all_reg.VEDU_CURLD_NARROW_CHRM.bits.curld_narrow_chrm_min;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_NARROW_CHRM.u32), narrow_chrm.u32);
	}

	{
		U_VEDU_CURLD_NARROW_LUMA narrow_luma;

		narrow_luma.bits.curld_narrow_luma_max =
			channel_cfg->all_reg.VEDU_CURLD_NARROW_LUMA.bits.curld_narrow_luma_max;
		narrow_luma.bits.curld_narrow_luma_min =
			channel_cfg->all_reg.VEDU_CURLD_NARROW_LUMA.bits.curld_narrow_luma_min;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_NARROW_LUMA.u32), narrow_luma.u32);
	}

	{
		U_VEDU_CURLD_SRCH_STRIDE src_header_stride;

		src_header_stride.bits.srcyh_stride =
			channel_cfg->all_reg.VEDU_CURLD_SRCH_STRIDE.bits.srcyh_stride;
		src_header_stride.bits.srcch_stride =
			channel_cfg->all_reg.VEDU_CURLD_SRCH_STRIDE.bits.srcch_stride;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_SRCH_STRIDE.u32), src_header_stride.u32);
	}
	venc_hal_cfg_curld_clip(channel_cfg, reg_base);
}

static void venc_hal_cfg_rc_cloudphoto(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	const uint32_t vedu_vcpi_raw_iso_addr = 0xd8; // v900 reserved
	const uint32_t vedu_vcpi_raw_exposure_addr = 0xdc; // v900 reserved
	const uint32_t vedu_vcpi_raw_rc_addr = 0xe0; // v900 reserved
	const uint32_t vedu_vcpi_raw_rc_rggb_addr = 0xe4; // v900 reserved
	// we use these registers to share cloudphoto rate control information with mcu
	struct qp_rate_control_params qp_rc_params;
	raw_rc_params raw_rc_reg;
	raw_rc_rggb_params raw_rc_rggb_reg;

	qp_rc_params.iso = channel_cfg->channel.qp_rc_params.iso;
	qp_rc_params.exposure = channel_cfg->channel.qp_rc_params.exposure;
	raw_rc_reg.bits.is_ref = channel_cfg->channel.qp_rc_params.is_ref;
	raw_rc_reg.bits.frame_type = channel_cfg->channel.qp_rc_params.frame_type;
	raw_rc_reg.bits.pixel_mode = channel_cfg->channel.qp_rc_params.pixel_mode;
	raw_rc_reg.bits.is_enable_mcu_rc = channel_cfg->channel.qp_rc_params.is_enable_mcu_rc;
	raw_rc_rggb_reg.bits.plane = channel_cfg->channel.qp_rc_params.plane;
	raw_rc_rggb_reg.bits.r_greater_b_plus_one = channel_cfg->channel.qp_rc_params.r_greater_b_plus_one;

    VCODEC_DBG_VENC(
        "set cur frame iso:%u, exposure:%u, isRef:%u, frameType:%u, pixelMode:%u, isEnableMcuRc:%u, plane:%u, r_greater_b_plus_one:%u",
        qp_rc_params.iso, qp_rc_params.exposure, raw_rc_reg.bits.is_ref, raw_rc_reg.bits.frame_type,
        raw_rc_reg.bits.pixel_mode, raw_rc_reg.bits.is_enable_mcu_rc, raw_rc_rggb_reg.bits.plane, raw_rc_rggb_reg.bits.r_greater_b_plus_one);

	vedu_hal_cfg(reg_base, vedu_vcpi_raw_iso_addr, qp_rc_params.iso);
	vedu_hal_cfg(reg_base, vedu_vcpi_raw_exposure_addr, qp_rc_params.exposure);
	vedu_hal_cfg(reg_base, vedu_vcpi_raw_rc_addr, raw_rc_reg.u32);
	vedu_hal_cfg(reg_base, vedu_vcpi_raw_rc_rggb_addr, raw_rc_rggb_reg.u32);
}

static void venc_hal_cfg_rc(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	/* according to <VcodecV800 IT Environment Constrain> 3.1 */
	uint32_t i;
	uint32_t vedu_vcpi_bgl_addr_l = 0xc8; // v800 reserved
	uint32_t vedu_vcpi_bgl_addr_h = 0xcc; // v800 reserved
	uint32_t vedu_vcpi_bgc_addr_l = 0xd0; // v800 reserved
	uint32_t vedu_vcpi_bref_addr = 0xd4; // v900 reserved
	uint32_t vedu_vcpi_bginf_addr_l = 0xe8; // v900 reserved
	uint32_t vedu_vcpi_bginf_addr_h = 0xec; // v900 reserved
	// we use these registers to share rate control information with mcu
	bgll_reg_type bgll_reg;
	bglh_reg_type bglh_reg;
	bginfh_reg_type bginfh_reg;
	bref_reg_type bref_reg;

	for (i = 0; i < 80; i++)
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_QP_LAMBDA_CTRL_REG00.u32) + i * sizeof(uint32_t),
			*(&channel_cfg->all_reg.VEDU_QPG_QP_LAMBDA_CTRL_REG00.u32 + i));

	for (i = 0; i < 48; i++)
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_QP_LAMBDA_CTRL_REG80.u32) + i * sizeof(uint32_t),
			*(&channel_cfg->all_reg.VEDU_QPG_QP_LAMBDA_CTRL_REG80.u32 + i));

	bgll_reg.bits.scenemode = channel_cfg->channel.scenemode;
	bgll_reg.bits.is_reset_rc = channel_cfg->channel.is_reset_rc;
	bgll_reg.bits.rcmode = channel_cfg->channel.rcmode;
	bgll_reg.bits.id = channel_cfg->channel.id;
	bgll_reg.bits.slice_chroma_qp_offsets_en = channel_cfg->channel.slice_chroma_qp_offsets_en;
	bglh_reg.bits.gop = channel_cfg->channel.gop;
	bglh_reg.bits.framerate = channel_cfg->channel.framerate;
	bginfh_reg.bits.qualityFactor = channel_cfg->channel.targetQP;
	bginfh_reg.bits.sqrDominate = channel_cfg->channel.sqrDominate;
	bref_reg.bits.gop_rc_type = channel_cfg->channel.muti_ref_info.gop_type;
	bref_reg.bits.skip_ratio = channel_cfg->channel.muti_ref_info.skip_ratio;
	bref_reg.bits.low_mv_ratio = channel_cfg->channel.muti_ref_info.low_mv_ratio;
	vedu_hal_cfg(reg_base, vedu_vcpi_bgl_addr_l, bgll_reg.u32);
	vedu_hal_cfg(reg_base, vedu_vcpi_bgl_addr_h, bglh_reg.u32);
	vedu_hal_cfg(reg_base, vedu_vcpi_bgc_addr_l, channel_cfg->channel.bitrate);
	vedu_hal_cfg(reg_base, vedu_vcpi_bref_addr, bref_reg.u32);

	venc_hal_cfg_rc_cloudphoto(channel_cfg, reg_base);
	vedu_hal_cfg(reg_base, vedu_vcpi_bginf_addr_l, channel_cfg->channel.peakBitRate);
	vedu_hal_cfg(reg_base, vedu_vcpi_bginf_addr_h, bginfh_reg.u32);
}

static void venc_hal_cfg_misc(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_REFLD_CMP_CLKGATE_EN.u32),
		channel_cfg->all_reg.VEDU_REFLD_CMP_CLKGATE_EN.u32);
}

static void venc_hal_cfg_srdo(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	uint32_t i;
	uint32_t offs_min = offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SRDO_MIN_WEIGHT0.u32);
	uint32_t *min_weight = (uint32_t *)&channel_cfg->all_reg.VEDU_VCPI_SRDO_MIN_WEIGHT0.u32;
	uint32_t offs_max = offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SRDO_MAX_WEIGHT0.u32);
	uint32_t *max_weight = (uint32_t *)&channel_cfg->all_reg.VEDU_VCPI_SRDO_MAX_WEIGHT0.u32;

	for (i = 0; i < 26; i++) { // 26 : min / max
		vedu_hal_cfg(reg_base, offs_min + 4 * i, min_weight[i]);
		vedu_hal_cfg(reg_base, offs_max + 4 * i, max_weight[i]);
	}

	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_INTRA_INTER_CU_EN.u32),
		channel_cfg->all_reg.VEDU_VCPI_INTRA_INTER_CU_EN.u32);
}

static void venc_hal_cfg_water_mark(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	if (!channel_cfg->all_reg.VEDU_CURLD_GCFG.bits.curld_watermark_en &&
		!channel_cfg->all_reg.VEDU_CURLD_GCFG.bits.curld_raw_data_bitdepth)
		return;

	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_WATERMARK_ADDR_L),
		channel_cfg->all_reg.VEDU_CURLD_WATERMARK_ADDR_L);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_WATERMARK_ADDR_H),
		channel_cfg->all_reg.VEDU_CURLD_WATERMARK_ADDR_H);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_WATERMARK_CFG.u32),
		channel_cfg->all_reg.VEDU_CURLD_WATERMARK_CFG.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_WATERMARK_SIZE.u32),
		channel_cfg->all_reg.VEDU_CURLD_WATERMARK_SIZE.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_WATERMARK_STRIDE.u32),
		channel_cfg->all_reg.VEDU_CURLD_WATERMARK_STRIDE.u32);
}

static void venc_hal_cfg_vcpi_mode(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	U_VEDU_VCPI_MODE d32;

	d32.u32 = channel_cfg->all_reg.VEDU_VCPI_MODE.u32;
	if (channel_cfg->all_reg.VEDU_VCPI_MODE.bits.vcpi_frame_type == 0)
		d32.bits.vcpi_idr_pic = 1;
	else
		d32.bits.vcpi_idr_pic = 0;
	d32.bits.vedu_selfrst_en = 1;
	d32.bits.vcpi_lcu_rdo_ctrl_en =
		channel_cfg->all_reg.VEDU_VCPI_MODE.bits.vcpi_lcu_rdo_ctrl_en; // v800 add
	d32.bits.vcpi_lcu_zeromotion_en =
		channel_cfg->all_reg.VEDU_VCPI_MODE.bits.vcpi_lcu_zeromotion_en; // v800 add
	d32.bits.vcpi_scaling_list_en =
		channel_cfg->all_reg.VEDU_VCPI_MODE.bits.vcpi_scaling_list_en; // v900 add

	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_MODE.u32), d32.u32);

	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_MODE2.u32),
		channel_cfg->all_reg.VEDU_VCPI_MODE2.u32); // v900 add
}

static void venc_hal_cfg_rdo_chroma_weight_pq(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	U_VEDU_VCPI_QPCFG reg;
	reg.u32 = channel_cfg->all_reg.VEDU_VCPI_QPCFG.u32;
	reg.bits.vcpi_chromaRdoWeightingIntraEn =
		channel_cfg->all_reg.VEDU_VCPI_QPCFG.bits.vcpi_chromaRdoWeightingIntraEn; // v900 add
	reg.bits.vcpi_slice_cb_qp_offset = channel_cfg->all_reg.VEDU_VCPI_QPCFG.bits.vcpi_slice_cb_qp_offset;
	reg.bits.vcpi_slice_cr_qp_offset = channel_cfg->all_reg.VEDU_VCPI_QPCFG.bits.vcpi_slice_cr_qp_offset;
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_QPCFG.u32),
		reg.u32);

	if (!reg.bits.vcpi_chromaRdoWeightingIntraEn)
		return;

	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_0.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_0.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_1.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_1.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_2.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_2.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_3.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_3.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_4.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_4.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_5.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_5.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_6.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_6.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_7.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_7.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_8.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_8.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_9.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_9.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_10.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_10.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_11.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_11.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_12.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_12.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_13.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_13.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_14.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_14.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_15.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_15.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_16.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_16.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_17.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_17.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_18.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_18.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_19.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_19.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_20.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_20.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_CHROMA_WEIGHTING_21.u32),
		channel_cfg->all_reg.VEDU_QPG_CHROMA_WEIGHTING_21.u32);
}

static void venc_hal_cfg_raw_encode(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	if (channel_cfg->all_reg.VEDU_CURLD_GCFG.bits.curld_raw_data_bitdepth == 0) {
		return;
	}
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_RAW_DATA_MODE.u32),
		channel_cfg->all_reg.VEDU_RAW_DATA_MODE.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_QPINFO_ADDR_L),
		channel_cfg->all_reg.VEDU_VCPI_QPINFO_ADDR_L);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_QPINFO_ADDR_H),
		channel_cfg->all_reg.VEDU_VCPI_QPINFO_ADDR_H);
}

// platform differences configured only in the vedu_hal_cfg_reg interface
void venc_hal_cfg_plat_diff_all_cfg(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	venc_hal_cfg_curld_pre_mod_para(channel_cfg, reg_base);
	venc_hal_cfg_srdo(channel_cfg, reg_base);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PINTRA_THRESH2.u32),
		channel_cfg->all_reg.VEDU_VCPI_PINTRA_THRESH2.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_MRG_FORCE_SKIP_EN.u32),
		channel_cfg->all_reg.VEDU_MRG_FORCE_SKIP_EN.u32);
	vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PIC_STRONG_EN.u32),
			channel_cfg->all_reg.VEDU_VCPI_PIC_STRONG_EN.u32);
}

static void venc_hal_set_smmu_pre_sc(uint32_t *reg_base)
{
	uint32_t i;
	uint32_t offset;
	U_VEDU_REFLD_ESP_HINT ref_esp_cache_hint = {0};
	U_VEDU_CACHE_AS_FUL cache_as_ful = {0};
	uint32_t refld_esp_hind_offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE[0]) + 0x28;

	ref_esp_cache_hint.bits.sc_esp_hint_en = 1;
	ref_esp_cache_hint.bits.sc_esp_hint_l0 = 0x8; // middle b'1000, do not read allocate
	ref_esp_cache_hint.bits.sc_esp_hint_l1 = 0x9; // first  b'1001, read allocate
	ref_esp_cache_hint.bits.sc_esp_hint_l2 = 0xB; // last   b'1011, read deallocate and drop
	vedu_hal_cfg(reg_base, refld_esp_hind_offset, ref_esp_cache_hint.u32);

	for (i = VENC_REFLD_DATA_START_SID; i < VENC_REFLD_DATA_END_SID; i++) {
		offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE[0]) + i * 0x4 + 0xA00;
		cache_as_ful.bits.domain = 0x3; // L3 cache
		cache_as_ful.bits.cache = 0x3; // L3 cache
		cache_as_ful.bits.sc_gid_hint = PID_VENC; // gid 40
		cache_as_ful.bits.sc_new_hint = 0x8; // no care, hardware will choose ref_esp_cache_hint
		vedu_hal_cfg(reg_base, offset, cache_as_ful.u32);
	}

#ifdef VENC_SC_HINT_PGID_BY_MASTER
	for (i = VENC_REC_DATA_START_SID; i < VENC_REC_DATA_END_SID; i++) {
		offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE[0]) + i * 0x4 + 0xA00;
		cache_as_ful.bits.domain = 0x3; // L3 cache
		cache_as_ful.bits.cache = 0x3; // L3 cache
		cache_as_ful.bits.sc_gid_hint = PID_VENC; // gid 40
		cache_as_ful.bits.sc_new_hint = 0x8;
		vedu_hal_cfg(reg_base, offset, cache_as_ful.u32);
	}
#endif
}

static void venc_hal_set_smmu_pre_1_sc(uint32_t *reg_base)
{
	uint32_t i;
	uint32_t offset;
	U_VEDU_REFLD_ESP_HINT ref_esp_cache_hint = {0};
	U_VEDU_CACHE_AS_FUL cache_as_ful = {0};
	uint32_t refld_esp_hind_offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE_1[0]) + 0x14;

	ref_esp_cache_hint.bits.sc_esp_hint_en = 1;
	ref_esp_cache_hint.bits.sc_esp_hint_l0 = 0x8;
	ref_esp_cache_hint.bits.sc_esp_hint_l1 = 0x9;
	ref_esp_cache_hint.bits.sc_esp_hint_l2 = 0xB;
	vedu_hal_cfg(reg_base, refld_esp_hind_offset, ref_esp_cache_hint.u32);

	for (i = VENC_REFLD_DATA_START_SID; i < VENC_REFLD_DATA_END_SID; i++) {
		offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE_1[0]) + i * 0x4 + 0x220;
		cache_as_ful.bits.domain = 0x3; // L3 cache
		cache_as_ful.bits.cache = 0x3; // L3 cache
		cache_as_ful.bits.sc_gid_hint = PID_VENC; // gid
		cache_as_ful.bits.sc_new_hint = 0x8; // no care, hardware will choose ref_esp_cache_hint
		vedu_hal_cfg(reg_base, offset, cache_as_ful.u32);
	}
}

void venc_hal_set_tbu_swid(uint32_t *reg_base)
{
	uint32_t i;
	SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_UNION swid_reg;
	uint32_t venc_stream_num = 62; // SMMU SW_ID
	uint32_t smmu_tbu_swid_cfg_offset = VCODEC_VENC_SMMU_TBU_OFFSET + SMMU_TBU_SWID_CFG_N;

	for (i = 0; i < venc_stream_num; i++) {
		uint32_t swif_cfg = readl(reg_base + smmu_tbu_swid_cfg_offset / 4 + i);
		swid_reg.value = swif_cfg;
#ifdef VENC_SC_HINT_PGID_BY_MASTER
		swid_reg.reg.syscache_hint_sel = 2; // pgid by master
#else
		swid_reg.reg.syscache_hint_sel = 1; // PBHA
#endif
		vedu_hal_cfg(reg_base, smmu_tbu_swid_cfg_offset + i * 4, swid_reg.value);
	}

	venc_hal_set_smmu_pre_sc(reg_base);
	venc_hal_set_smmu_pre_1_sc(reg_base);
}

void venc_hal_cfg_set_hint_en(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	U_VEDU_REFLD_ESP_HINT ref_esp_cache_hint = {0};
	uint32_t refld_esp_hind_pre_offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE[0]) + 0x28;
	uint32_t refld_esp_hind_pre1_offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE_1[0]) + 0x14;

#ifdef VENC_SC_HINT_PGID_BY_MASTER
	ref_esp_cache_hint.bits.sc_esp_hint_en =
		(channel_cfg->all_reg.VEDU_ISPLD_CFG.bits.vcpi_adaptive_ref_mode == 0 &&
		channel_cfg->all_reg.VEDU_VCPI_MODE.bits.vcpi_lcu_zeromotion_en == 0) ? 1 : 0;
#else
	ref_esp_cache_hint.bits.sc_esp_hint_en =
		(channel_cfg->all_reg.VEDU_ISPLD_CFG.bits.vcpi_adaptive_ref_mode == 0) ? 1 : 0;
#endif

	ref_esp_cache_hint.bits.sc_esp_hint_l0 = 0x8;
	ref_esp_cache_hint.bits.sc_esp_hint_l1 = 0x9;
	ref_esp_cache_hint.bits.sc_esp_hint_l2 = 0xB;

	vedu_hal_cfg(reg_base, refld_esp_hind_pre_offset, ref_esp_cache_hint.u32);
	vedu_hal_cfg(reg_base, refld_esp_hind_pre1_offset, ref_esp_cache_hint.u32);
}

void venc_hal_cfg_platform_diff(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	venc_hal_cfg_ime(channel_cfg, reg_base);
	venc_hal_cfg_buffer(channel_cfg, reg_base);
	venc_hal_cfg_rc(channel_cfg, reg_base);
	venc_hal_cfg_misc(channel_cfg, reg_base);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE,
		VEDU_ISPLD_CFG.u32), channel_cfg->all_reg.VEDU_ISPLD_CFG.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE,
		VEDU_VCPI_FORCE_ZEROMV.u32), channel_cfg->all_reg.VEDU_VCPI_FORCE_ZEROMV.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE,
		VEDU_CURLD_DEPTHCODING.u32), channel_cfg->all_reg.VEDU_CURLD_DEPTHCODING.u32);
	venc_hal_cfg_vcpi_mode(channel_cfg, reg_base);
	venc_hal_cfg_water_mark(channel_cfg, reg_base);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_FORCE_INTRAPU32_NUM.u32),
			channel_cfg->all_reg.VEDU_VCPI_FORCE_INTRAPU32_NUM.u32);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_RPINTRA_CFG.u32),
		channel_cfg->all_reg.VEDU_RPINTRA_CFG.u32);
	// v900 add
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_QPINFO_LD_ST_STRIDE.u32),
		channel_cfg->all_reg.VEDU_VCPI_QPINFO_LD_ST_STRIDE.u32);
	venc_hal_cfg_rdo_chroma_weight_pq(channel_cfg, reg_base);
	venc_hal_cfg_raw_encode(channel_cfg, reg_base);
	venc_hal_cfg_set_hint_en(channel_cfg, reg_base);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_LOW_POWER.u32),
		channel_cfg->all_reg.VEDU_VCPI_LOW_POWER.u32);
}

bool venc_device_need_bypass(void)
{
#if defined(CONFIG_SOC_PG_INFO)
	struct soc_component_pg_info pg_info;
	get_soc_pg_info_by_index(SOC_COMPONENT_VENC_INFO, &pg_info);
	switch (pg_info.tailor_strategy) {
		case SOC_COMPONENT_TAILOR_STRATEGY_1:
			return true;
		case SOC_COMPONENT_NOT_TAILOR:
		case SOC_COMPONENT_NOT_TAILOR_EFUSE_NONE:
			return false;
		default:
			VCODEC_FATAL_VENC("invalid pg info index: %d", pg_info.tailor_strategy);
			return true;
	}
#else
	return false;
#endif
}

static int32_t check_internal_buffer_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg, const mem_buffer_t *buffer)
{
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_YADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_CADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_YH_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_CH_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFY_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFC_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFYH_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFCH_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMELD_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFY_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFC_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFYH_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFCH_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMELD_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMEST_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_NBI_MVST_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_NBI_MVLD_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_QPGLD_INF_ADDR_L, buffer->size);

	return 0;
}

static int32_t check_image_buffer_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg, const mem_buffer_t *buffer)
{
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_TUNLCELL_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_SRC_YADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_SRC_CADDR_L, buffer->size);

	if (reg->VEDU_VCPI_STRFMT.bits.vcpi_str_fmt == YUV420_PLANAR ||
		reg->VEDU_VCPI_STRFMT.bits.vcpi_str_fmt == YUV422_PLANAR)
		d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_SRC_VADDR_L, buffer->size);

	if (reg->VEDU_VCPI_STRFMT.bits.vcpi_str_fmt == YUV420_SEMIPLANAR_CMP) {
		d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_YH_ADDR_L, buffer->size);
		d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_CH_ADDR_L, buffer->size);
	}

	return 0;
}

static int32_t check_image_stream_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg,
		const mem_buffer_t *stream_buffer, const mem_buffer_t *head_buffer)
{
	uint32_t i;
	uint64_t start_addr, end_addr;

	/* according to <VcodecV700 IT Environment Constrain> 4.1 */
	for (i = 0; i < MAX_SLICE_NUM; i++) {
		start_addr = (((uint64_t)reg->VEDU_VCPI_STRMADDR_H_NEW[i] << 32) & 0xFFFFFFFF00000000) |
			(uint64_t)reg->VEDU_VCPI_STRMADDR_L_NEW[i];
		end_addr = start_addr + (uint64_t)reg->VEDU_VCPI_STRMBUFLEN_NEW[i];

		d_venc_check_cfg_reg_streamaddr_ret(stream_buffer[i].start_phys_addr,
				start_addr, stream_buffer[i].size, stream_buffer[i].share_fd);

		d_venc_check_cfg_reg_streamendaddr_ret(stream_buffer[i].start_phys_addr,
				end_addr, stream_buffer[i].size, stream_buffer[i].share_fd);
	}

	return 0;
}

static int32_t check_watermark_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg, const mem_buffer_t *buffer)
{
	if (reg->VEDU_CURLD_GCFG.bits.curld_watermark_en) {
		d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_CURLD_WATERMARK_ADDR_L, buffer->size);
	}

	return 0;
}

int32_t vedu_hal_check_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg, venc_buffer_info_t *mem_info)
{
	int32_t ret;

	ret = check_internal_buffer_addr(reg, &mem_info->internal_buffer);
	if (ret) {
		VCODEC_FATAL_VENC("check internal buffer addr failed");
		return VCODEC_FAILURE;
	}

	ret = check_image_buffer_addr(reg, &mem_info->image_buffer);
	if (ret) {
		VCODEC_FATAL_VENC("check image buffer addr failed");
		return VCODEC_FAILURE;
	}

	ret = check_image_stream_addr(reg, &mem_info->stream_buffer[0], &mem_info->stream_head_buffer);
	if (ret) {
		VCODEC_FATAL_VENC("check stream buffer addr failed");
		return VCODEC_FAILURE;
	}

	ret = check_watermark_addr(reg, &mem_info->watermark_buffer);
	if (ret) {
		VCODEC_FATAL_VENC("check water buffer addr failed");
		return VCODEC_FAILURE;
	}
	return 0;
}

void venc_hal_get_reg_mse(struct stream_info *stream_info, uint32_t *reg_base, uint32_t lcu_block_cnt)
{
	S_HEVC_AVC_REGS_TYPE *all_reg = (S_HEVC_AVC_REGS_TYPE *)reg_base;
	uint64_t sum_mse_h;
	uint64_t sum_mse;
	if (all_reg->VEDU_VCPI_MODE.bits.vcpi_protocol == VEDU_H264)
		return;

	sum_mse_h = (uint64_t)all_reg->FUNC_SAO_MSE_CNT.bits.sao2vcpi_mse_sumh;
	lcu_block_cnt = all_reg->FUNC_SAO_MSE_CNT.bits.sao2vcpi_mse_cnt > 0 ?
					all_reg->FUNC_SAO_MSE_CNT.bits.sao2vcpi_mse_cnt : lcu_block_cnt;
	sum_mse = (uint64_t)all_reg->FUNC_SAO_MSE_SUM + (sum_mse_h << LCU_MSE_HIGH_BITS_SHIFT);
	if (all_reg->VEDU_VCPI_MODE.bits.vcpi_10bit_mode == 0)
		// Restore the calculation process of the chip and multiply 1000 to keep three decimal places.
		stream_info->average_lcu_mse = (sum_mse << LCU_MSE_8BIT_SHIFT) * 1000 / LCU_MSE_STAT_AREA / lcu_block_cnt;
	else if (all_reg->VEDU_VCPI_MODE.bits.vcpi_10bit_mode == 1)
		stream_info->average_lcu_mse = (sum_mse << LCU_MSE_10BIT_SHIFT) * 1000 / LCU_MSE_STAT_AREA / lcu_block_cnt;
}