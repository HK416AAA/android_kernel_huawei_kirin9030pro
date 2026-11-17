#ifndef DPU_WCH_H
#define DPU_WCH_H 
#include "soc_dpu_interface.h"
#include "soc_dpu_define.h"
enum wch_num_idx {
 WCH_0 = 0,
 WCH_1,
 WCH_2,
};
struct dpu_wch_wdma {
 DPU_WCH_DMA_CTRL0_UNION dma_ctrl0;
 DPU_WCH_DMA_CTRL1_UNION dma_ctrl1;
 DPU_WCH_DMA_IMG_SIZE_UNION dma_img_size;
 DPU_WCH_DMA_PTR0_UNION dma_ptr0;
 DPU_WCH_DMA_STRIDE0_UNION dma_stride0;
 DPU_WCH_DMA_PTR1_UNION dma_ptr1;
 DPU_WCH_DMA_STRIDE1_UNION dma_stride1;
 DPU_WCH_DMA_PTR2_UNION dma_ptr2;
 DPU_WCH_DMA_STRIDE2_UNION dma_stride2;
 DPU_WCH_DMA_PTR3_UNION dma_ptr3;
 DPU_WCH_DMA_STRIDE3_UNION dma_stride3;
 DPU_WCH_DMA_CMP_HDR_PTR_OFT_UNION dma_cmp_hdr_ptr_oft;
 DPU_WCH_DMA_CH_SEGMENT_CTRL_UNION dma_ch_segment_ctrl;
 DPU_WCH_DMA_CMP_CTRL_UNION dma_cmp_ctrl;
 DPU_WCH_DMA_CMP_PIC_BLKS_UNION dma_cmp_pic_blks;
 DPU_WCH_DMA_CMP_MEM_CTRL0_UNION dma_cmp_mem_ctrl0;
 DPU_WCH_DMA_CMP_MEM_CTRL1_UNION dma_cmp_mem_ctrl1;
 DPU_WCH_DMA_CMP_RESEVED_UNION dma_cmp_reserved;
 DPU_WCH_DMA_CMP_INFO_OUT0_UNION dma_cmp_inf0_out0;
 DPU_WCH_DMA_CMP_INFO_OUT1_UNION dma_cmp_inf0_out1;
 DPU_WCH_DMA_INTR_UNION dma_intr;
 DPU_WCH_DMA_RSV_IN0_UNION dma_rsv_in0;
 DPU_WCH_DMA_RSV_IN1_UNION dma_rsv_in1;
 DPU_WCH_DMA_RSV_IN2_UNION dma_rsv_in2;
 DPU_WCH_DMA_RSV_IN3_UNION dma_rsv_in3;
 DPU_WCH_DMA_MONITOR_OUT0_UNION dma_monitor_out0;
 DPU_WCH_DMA_MONITOR_OUT1_UNION dma_monitor_out1;
 DPU_WCH_DMA_MONITOR_OUT2_UNION dma_monitor_out2;
 DPU_WCH_DMA_MONITOR_OUT3_UNION dma_monitor_out3;
 DPU_WCH_DMA_MONITOR_OUT4_UNION dma_monitor_out4;
 DPU_WCH_DMA_MONITOR_OUT5_UNION dma_monitor_out5;
};
struct dpu_wch_wlt {
 DPU_WCH_WTL_CTRL_UNION wlt_ctrl;
 DPU_WCH_WLT_LINE_THRESHOLD1_UNION wlt_line_threshold1;
 DPU_WCH_WLT_LINE_THRESHOLD3_UNION wlt_line_threshold3;
 DPU_WCH_WLT_BASE_LINE_OFFSET_UNION wlt_base_line_offset;
 DPU_WCH_WLT_DMA_ADDR_UNION wlt_dma_addr;
 DPU_WCH_WLT_DMA_QOS_UNION wlt_dma_qos;
 DPU_WCH_WLT_C_LINE_NUM_UNION wlt_c_line_num;
 DPU_WCH_WLT_C_SLICE_NUM_UNION wlt_c_slice_num;
};
struct dpu_wch_reg {
 DPU_WCH_REG_DEFAULT_UNION reg_default;
 DPU_WCH_CH_RD_SHADOW_UNION ch_rd_shadow;
 DPU_WCH_CH_CTL_UNION ch_ctl;
 DPU_WCH_CH_SECU_EN_UNION ch_secu_en;
 DPU_WCH_CH_SW_END_REQ_UNION ch_sw_end_req;
 DPU_WCH_CH_CLK_SEL_UNION ch_clk_sel;
 DPU_WCH_CH_CLK_EN_UNION ch_clk_en;
 DPU_WCH_CH_DBG0_UNION ch_dbg0;
 DPU_WCH_CH_DBG1_UNION ch_dbg1;
 DPU_WCH_CH_DBG2_UNION ch_dbg2;
 DPU_WCH_CH_DBG3_UNION ch_dbg3;
 DPU_WCH_CH_DBG4_UNION ch_dbg4;
 DPU_WCH_CH_DBG5_UNION ch_dbg5;
 DPU_WCH_FRM_END_WCH_DELAY_UNION frm_end_wch_delay;
};
struct dpu_wch_dfc {
 DPU_WCH_DFC_DISP_SIZE_UNION disp_size;
 DPU_WCH_DFC_PIX_IN_NUM_UNION pix_in_num;
 DPU_WCH_DFC_GLB_ALPHA01_UNION glb_alpha01;
 DPU_WCH_DFC_DISP_FMT_UNION disp_fmt;
 DPU_WCH_DFC_CLIP_CTL_HRZ_UNION clip_ctl_hrz;
 DPU_WCH_DFC_CLIP_CTL_VRZ_UNION clip_ctl_vrz;
 DPU_WCH_DFC_CTL_CLIP_EN_UNION ctl_clip_en;
 DPU_WCH_DFC_ICG_MODULE_UNION icg_module;
 DPU_WCH_DFC_DITHER_ENABLE_UNION dither_enable;
 DPU_WCH_DFC_PADDING_CTL_UNION padding_ctl;
 DPU_WCH_DFC_GLB_ALPHA23_UNION glb_alpha23;
 DPU_WCH_DFC_GLB_ALPHA_UNION glb_alpha;
 DPU_WCH_DFC_ALPHA_CTL_UNION alpha_ctl;
 DPU_WCH_DFC_ALPHA_THD_UNION alpha_thd;
};
struct dpu_wch_bitext {
 DPU_WCH_BITEXT_CTL_UNION bitext_ctl;
 DPU_WCH_BITEXT_REG_INI0_0_UNION bitext_reg_ini0_0;
 DPU_WCH_BITEXT_REG_INI0_1_UNION bitext_reg_ini0_1;
 DPU_WCH_BITEXT_REG_INI0_2_UNION bitext_reg_ini0_2;
 DPU_WCH_BITEXT_REG_INI0_3_UNION bitext_reg_ini0_3;
 DPU_WCH_BITEXT_REG_INI1_0_UNION bitext_reg_ini1_0;
 DPU_WCH_BITEXT_REG_INI1_1_UNION bitext_reg_ini1_1;
 DPU_WCH_BITEXT_REG_INI1_2_UNION bitext_reg_ini1_2;
 DPU_WCH_BITEXT_REG_INI1_3_UNION bitext_reg_ini1_3;
 DPU_WCH_BITEXT_REG_INI2_0_UNION bitext_reg_ini2_0;
 DPU_WCH_BITEXT_REG_INI2_1_UNION bitext_reg_ini2_1;
 DPU_WCH_BITEXT_REG_INI2_2_UNION bitext_reg_ini2_2;
 DPU_WCH_BITEXT_REG_INI2_3_UNION bitext_reg_ini2_3;
 DPU_WCH_BITEXT_POWER_CTRL_C_UNION bitext_power_ctrl_c;
 DPU_WCH_BITEXT_POWER_CTRL_SHIFT_UNION bitext_power_ctrl_shift;
 DPU_WCH_BITEXT_FILT_00_UNION bitext_filt_00;
 DPU_WCH_BITEXT_FILT_01_UNION bitext_filt_01;
 DPU_WCH_BITEXT_FILT_02_UNION bitext_filt_02;
 DPU_WCH_BITEXT_FILT_10_UNION bitext_filt_10;
 DPU_WCH_BITEXT_FILT_11_UNION bitext_filt_11;
 DPU_WCH_BITEXT_FILT_12_UNION bitext_filt_12;
 DPU_WCH_BITEXT_FILT_20_UNION bitext_filt_20;
 unsigned int rsv[2];
 DPU_WCH_BITEXT_FILT_21_UNION bitext_filt_21;
 DPU_WCH_BITEXT_FILT_22_UNION bitext_filt_22;
 DPU_WCH_BITEXT_THD_R0_UNION bitext_thd_r0;
 DPU_WCH_BITEXT_THD_R1_UNION bitext_thd_r1;
 DPU_WCH_BITEXT_THD_G0_UNION bitext_thd_g0;
 DPU_WCH_BITEXT_THD_G1_UNION bitext_thd_g1;
 DPU_WCH_BITEXT_THD_B0_UNION bitext_thd_b0;
 DPU_WCH_BITEXT_THD_B1_UNION bitext_thd_b1;
 DPU_WCH_BITEXT0_DBG0_UNION bitext0_dbg0;
};
struct dpu_wch_dither {
 DPU_WCH_DITHER_CTL1_UNION ctl1;
 DPU_WCH_DITHER_TRI_THD10_UNION tri_thd10;
 DPU_WCH_DITHER_TRI_THD10_UNI_UNION tri_thd10_uni;
 DPU_WCH_BAYER_CTL_UNION bayer_ctl;
 DPU_WCH_BAYER_MATRIX_PART1_UNION bayer_matrix_part1;
 DPU_WCH_BAYER_MATRIX_PART0_UNION bayer_matrix_part0;
};
struct dpu_wch_scf {
 DPU_WCH_SCF_EN_HSCL_STR_UNION en_hscl_str;
 DPU_WCH_SCF_EN_VSCL_STR_UNION en_vscl_str;
 DPU_WCH_SCF_H_V_ORDER_UNION h_v_order;
 DPU_WCH_SCF_CH_CORE_GT_UNION ch_core_gt;
 DPU_WCH_SCF_INPUT_WIDTH_HEIGHT_UNION input_width_height;
 DPU_WCH_SCF_OUTPUT_WIDTH_HEIGHT_UNION output_width_height;
 DPU_WCH_SCF_COEF_MEM_CTRL_UNION coef_mem_ctrl;
 DPU_WCH_SCF_EN_HSCL_UNION en_hscl;
 DPU_WCH_SCF_EN_VSCL_UNION en_vscl;
 DPU_WCH_SCF_ACC_HSCL_UNION acc_hscl;
 DPU_WCH_SCF_ACC_HSCL1_UNION acc_hscl1;
 unsigned int rsv0[2];
 DPU_WCH_SCF_INC_HSCL_UNION inc_hscl;
 DPU_WCH_SCF_ACC_VSCL_UNION acc_vscl;
 DPU_WCH_SCF_ACC_VSCL1_UNION acc_vscl1;
 unsigned int rsv1[2];
 DPU_WCH_SCF_INC_VSCL_UNION inc_vscl;
 DPU_WCH_SCF_EN_NONLINEAR_UNION en_nonlinear;
 unsigned int rsv2[11];
 DPU_WCH_SCF_EN_MMP_UNION en_mmp;
 DPU_WCH_SCF_DB_H0_UNION db_h0;
 DPU_WCH_SCF_DB_H1_UNION db_h1;
 DPU_WCH_SCF_DB_V0_UNION db_v0;
 DPU_WCH_SCF_DB_V1_UNION db_v1;
 DPU_WCH_SCF_LB_MEM_CTRL_UNION lb_mem_ctrl;
};
struct dpu_wch_csc_coef {
 DPU_WCH_CSC_IDC0_UNION idc0;
 DPU_WCH_CSC_IDC2_UNION idc2;
 DPU_WCH_CSC_ODC0_UNION odc0;
 DPU_WCH_CSC_ODC2_UNION odc2;
 DPU_WCH_CSC_P00_UNION p00;
 DPU_WCH_CSC_P01_UNION p01;
 DPU_WCH_CSC_P02_UNION p02;
 DPU_WCH_CSC_P10_UNION p10;
 DPU_WCH_CSC_P11_UNION p11;
 DPU_WCH_CSC_P12_UNION p12;
 DPU_WCH_CSC_P20_UNION p20;
 DPU_WCH_CSC_P21_UNION p21;
 DPU_WCH_CSC_P22_UNION p22;
};
struct dpu_wch_pcsc {
 struct dpu_wch_csc_coef pcsc_coef;
 DPU_WCH_PCSC_ICG_MODULE_UNION pcsc_icg_module;
};
struct dpu_wch_post_clip {
 DPU_WCH_POST_CLIP_DISP_SIZE_UNION disp_size;
 DPU_WCH_POST_CLIP_CTL_HRZ_UNION clip_ctl_hrz;
 DPU_WCH_POST_CLIP_CTL_VRZ_UNION clip_ctl_vrz;
 DPU_WCH_POST_CLIP_EN_UNION ctl_clip_en;
};
struct dpu_wch_csc {
 struct dpu_wch_csc_coef csc_coef;
 DPU_WCH_CSC_ICG_MODULE_UNION csc_icg_module;
};
struct dpu_wch_rot {
 DPU_WCH_ROT_FIRST_LNS_UNION rot_first_lns;
 DPU_WCH_ROT_STATE_UNION rot_state;
 DPU_WCH_ROT_MEM_CTRL_UNION rot_mem_ctrl;
 DPU_WCH_ROT_SIZE_UNION rot_size;
 DPU_WCH_ROT_422_MODE_UNION rot_422_mode;
};
struct dpu_wch_wrap_ctrl {
 DPU_WCH_REG_CTRL_UNION reg_ctrl;
 DPU_WCH_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
 DPU_WCH_REG_CTRL_DEBUG_UNION reg_ctrl_debug;
 DPU_WCH_REG_CTRL_STATE_UNION reg_ctrl_state;
 DPU_WCH_R_LB_DEBUG0_UNION r_lb_debug0;
 DPU_WCH_R_LB_DEBUG1_UNION r_lb_debug1;
 DPU_WCH_R_LB_DEBUG2_UNION r_lb_debug2;
 DPU_WCH_R_LB_DEBUG3_UNION r_lb_debug3;
 DPU_WCH_REG_CTRL_LAYER_ID_UNION reg_ctrl_layer_id;
};
#endif
