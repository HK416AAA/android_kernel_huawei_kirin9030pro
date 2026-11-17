#ifndef DPU_UVUP_H
#define DPU_UVUP_H 
#include "soc_dpu_interface.h"
#include "soc_dpu_define.h"
struct dpu_uvup_uvsamp_top {
 DPU_UVSAMP_RD_SHADOW_UNION rd_shadow;
 DPU_UVSAMP_REG_DEFAULT_UNION reg_default;
 DPU_UVSAMP_TOP_CLK_SEL_UNION top_clk_sel;
 DPU_UVSAMP_TOP_CLK_EN_UNION top_clk_en;
 DPU_UVSAMP_REG_CTRL_UNION reg_ctrl;
 DPU_UVSAMP_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
 DPU_UVSAMP_REG_CTRL_DEBUG_UNION reg_ctrl_debug;
 DPU_UVSAMP_REG_CTRL_STATE_UNION reg_ctrl_state;
};
struct dpu_uvup_csc_coef {
 DPU_UVSAMP_CSC_IDC0_UNION csc_idc0;
 DPU_UVSAMP_CSC_IDC2_UNION csc_idc2;
 DPU_UVSAMP_CSC_ODC0_UNION csc_odc0;
 DPU_UVSAMP_CSC_ODC2_UNION csc_odc2;
 DPU_UVSAMP_CSC_P00_UNION csc_p00;
 DPU_UVSAMP_CSC_P01_UNION csc_p01;
 DPU_UVSAMP_CSC_P02_UNION csc_p02;
 DPU_UVSAMP_CSC_P10_UNION csc_p10;
 DPU_UVSAMP_CSC_P11_UNION csc_p11;
 DPU_UVSAMP_CSC_P12_UNION csc_p12;
 DPU_UVSAMP_CSC_P20_UNION csc_p20;
 DPU_UVSAMP_CSC_P21_UNION csc_p21;
 DPU_UVSAMP_CSC_P22_UNION csc_p22;
};
struct dpu_uvup_csc {
 struct dpu_uvup_csc_coef csc_coef;
 DPU_UVSAMP_CSC_ICG_MODULE_UNION csc_icg_module;
 DPU_UVSAMP_CSC_MPREC_UNION csc_mprec;
};
struct dpu_uvup_uvsamp {
 DPU_UVSAMP_MEM_CTRL_UNION uvsamp_mem_ctrl;
 DPU_UVSAMP_SIZE_UNION uvsamp_size;
 DPU_UVSAMP_CTRL_UNION uvsamp_ctrl;
 DPU_UVSAMP_COEF_0_UNION uvsamp_coef_0;
 DPU_UVSAMP_COEF_1_UNION uvsamp_coef_1;
 DPU_UVSAMP_COEF_2_UNION uvsamp_coef_2;
 DPU_UVSAMP_COEF_3_UNION uvsamp_coef_3;
 DPU_UVSAMP_DEBUG_UNION uvsamp_debug;
};
struct dpu_uvup_dblk {
 DPU_UVSAMP_DBLK_MEM_CTRL_UNION dblk_mem_ctrl;
 DPU_UVSAMP_DBLK_SIZE_UNION dblk_size;
 DPU_UVSAMP_DBLK_CTRL_UNION dblk_ctrl;
 DPU_UVSAMP_DBLK_SLICE0_FRAME_INFO_UNION dblk_slice0_frame_info;
 DPU_UVSAMP_DBLK_SLICE1_FRAME_INFO_UNION dblk_slice1_frame_info;
 DPU_UVSAMP_DBLK_SLICE2_FRAME_INFO_UNION dblk_slice2_frame_info;
 DPU_UVSAMP_DBLK_SLICE3_FRAME_INFO_UNION dblk_slice3_frame_info;
 DPU_UVSAMP_DBLK_SLICE0_INFO_UNION dblk_slice0_info;
 DPU_UVSAMP_DBLK_SLICE1_INFO_UNION dblk_slice1_info;
 DPU_UVSAMP_DBLK_SLICE2_INFO_UNION dblk_slice2_info;
 DPU_UVSAMP_DBLK_SLICE3_INFO_UNION dblk_slice3_info;
};
struct dpu_uvup_post_clip {
 DPU_UVSAMP_POST_CLIP_TOP_UNION post_clip_top;
 DPU_UVSAMP_POST_CLIP_BOTTOM_UNION post_clip_bottom;
 DPU_UVSAMP_POST_CLIP_LEFT_UNION post_clip_left;
 DPU_UVSAMP_POST_CLIP_RIGHT_UNION post_clip_right;
 DPU_UVSAMP_POST_CLIP_EN_UNION post_clip_en;
 DPU_UVSAMP_POST_CLIP_DBG_UNION post_clip_dbg;
 DPU_UVSAMP_POST_CLIP_IMG_SIZE_UNION post_img_size;
};
struct dpu_uvup_params {
 struct dpu_uvup_uvsamp_top uvsamp_top;
 struct dpu_uvup_csc uvup_csc;
 struct dpu_uvup_uvsamp uvsamp;
 struct dpu_uvup_dblk uvup_dblk;
 struct dpu_uvup_post_clip uvup_post_clip;
};
#endif
