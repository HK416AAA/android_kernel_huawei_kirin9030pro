#ifndef DPU_VSCF_H
#define DPU_VSCF_H 
#include "soc_dpu_interface.h"
#include "soc_dpu_define.h"
#define COEF_6TAP_NUM 264
#define COEF_5TAP_NUM 272
#define COEF_4TAP_NUM 136
struct dpu_vscf_scf_top_reg {
 DPU_VSCF_RD_SHADOW_UNION rd_shadow;
 DPU_VSCF_REG_DEFAULT_UNION reg_default;
 DPU_VSCF_TOP_CLK_SEL_UNION top_clk_sel;
 DPU_VSCF_TOP_CLK_EN_UNION top_clk_en;
 DPU_VSCF_REG_CTRL_UNION reg_ctrl;
 DPU_VSCF_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
 DPU_VSCF_REG_CTRL_DEBUG_UNION reg_ctrl_debug;
 DPU_VSCF_REG_CTRL_STATE_UNION reg_ctrl_state;
 DPU_VSCF_R_LB_DEBUG0_UNION r_lb_debug0;
 DPU_VSCF_R_LB_DEBUG1_UNION r_lb_debug1;
 DPU_VSCF_R_LB_DEBUG2_UNION r_lb_debug2;
 DPU_VSCF_R_LB_DEBUG3_UNION r_lb_debug3;
 DPU_VSCF_W_LB_DEBUG0_UNION w_lb_debug0;
 DPU_VSCF_W_LB_DEBUG1_UNION w_lb_debug1;
 DPU_VSCF_W_LB_DEBUG2_UNION w_lb_debug2;
 DPU_VSCF_W_LB_DEBUG3_UNION w_lb_debug3;
 DPU_VSCF_REG_CTRL_LAYER_ID_UNION reg_ctrl_layer_id;
};
struct dpu_vscf_dfc {
 DPU_VSCF_DFC_DISP_SIZE_UNION dfc_disp_size;
 DPU_VSCF_DFC_PIX_IN_NUM_UNION dfc_pix_in_num;
 DPU_VSCF_DFC_GLB_ALPHA01_UNION dfc_glb_alpha01;
 DPU_VSCF_DFC_DISP_FMT_UNION dfc_disp_fmt;
 DPU_VSCF_DFC_CLIP_CTL_HRZ_UNION dfc_clip_ctl_hrz;
 DPU_VSCF_DFC_CLIP_CTL_VRZ_UNION dfc_clip_ctl_vrz;
 DPU_VSCF_DFC_CTL_CLIP_EN_UNION dfc_ctl_clip_en;
 DPU_VSCF_DFC_ICG_MODULE_UNION dfc_icg_module;
 DPU_VSCF_DFC_DITHER_ENABLE_UNION dfc_dither_enable;
 DPU_VSCF_DFC_PADDING_CTL_UNION dfc_padding_ctl;
 DPU_VSCF_DFC_GLB_ALPHA23_UNION dfc_glb_alpha23;
};
struct dpu_vscf_bitext {
 DPU_VSCF_BITEXT_CTL_UNION bitext_ctl;
 DPU_VSCF_BITEXT_REG_INI0_0_UNION bitext_reg_ini0_0;
 DPU_VSCF_BITEXT_REG_INI0_1_UNION bitext_reg_ini0_1;
 DPU_VSCF_BITEXT_REG_INI0_2_UNION bitext_reg_ini0_2;
 DPU_VSCF_BITEXT_REG_INI0_3_UNION bitext_reg_ini0_3;
 DPU_VSCF_BITEXT_REG_INI1_0_UNION bitext_reg_ini1_0;
 DPU_VSCF_BITEXT_REG_INI1_1_UNION bitext_reg_ini1_1;
 DPU_VSCF_BITEXT_REG_INI1_2_UNION bitext_reg_ini1_2;
 DPU_VSCF_BITEXT_REG_INI1_3_UNION bitext_reg_ini1_3;
 DPU_VSCF_BITEXT_REG_INI2_0_UNION bitext_reg_ini2_0;
 DPU_VSCF_BITEXT_REG_INI2_1_UNION bitext_reg_ini2_1;
 DPU_VSCF_BITEXT_REG_INI2_2_UNION bitext_reg_ini2_2;
 DPU_VSCF_BITEXT_REG_INI2_3_UNION bitext_reg_ini2_3;
 DPU_VSCF_BITEXT_POWER_CTRL_C_UNION bitext_power_ctrl_c;
 DPU_VSCF_BITEXT_POWER_CTRL_SHIFT_UNION bitext_power_ctrl_shift;
 DPU_VSCF_BITEXT_FILT_00_UNION bitext_filt_00;
 DPU_VSCF_BITEXT_FILT_01_UNION bitext_filt_01;
 DPU_VSCF_BITEXT_FILT_02_UNION bitext_filt_02;
 DPU_VSCF_BITEXT_FILT_10_UNION bitext_filt_10;
 DPU_VSCF_BITEXT_FILT_11_UNION bitext_filt_11;
 DPU_VSCF_BITEXT_FILT_12_UNION bitext_filt_12;
 DPU_VSCF_BITEXT_FILT_20_UNION bitext_filt_20;
 unsigned int rsv[2];
 DPU_VSCF_BITEXT_FILT_21_UNION bitext_filt_21;
 DPU_VSCF_BITEXT_FILT_22_UNION bitext_filt_22;
 DPU_VSCF_BITEXT_THD_R0_UNION bitext_thd_r0;
 DPU_VSCF_BITEXT_THD_R1_UNION bitext_thd_r1;
 DPU_VSCF_BITEXT_THD_G0_UNION bitext_thd_g0;
 DPU_VSCF_BITEXT_THD_G1_UNION bitext_thd_g1;
 DPU_VSCF_BITEXT_THD_B0_UNION bitext_thd_b0;
 DPU_VSCF_BITEXT_THD_B1_UNION bitext_thd_b1;
 DPU_VSCF_BITEXT0_DBG0_UNION bitext0_dbg0;
};
struct dpu_vscf_csc_coef {
 DPU_VSCF_CSC_IDC0_UNION idc0;
 DPU_VSCF_CSC_IDC2_UNION idc2;
 DPU_VSCF_CSC_ODC0_UNION odc0;
 DPU_VSCF_CSC_ODC2_UNION odc2;
 DPU_VSCF_CSC_P00_UNION p00;
 DPU_VSCF_CSC_P01_UNION p01;
 DPU_VSCF_CSC_P02_UNION p02;
 DPU_VSCF_CSC_P10_UNION p10;
 DPU_VSCF_CSC_P11_UNION p11;
 DPU_VSCF_CSC_P12_UNION p12;
 DPU_VSCF_CSC_P20_UNION p20;
 DPU_VSCF_CSC_P21_UNION p21;
 DPU_VSCF_CSC_P22_UNION p22;
};
struct dpu_vscf_csc {
 struct dpu_vscf_csc_coef csc_coef;
 DPU_VSCF_CSC_ICG_MODULE_UNION csc_icg_module;
 DPU_VSCF_CSC_MPREC_UNION csc_mprec;
};
struct dpu_vscf_scf {
 DPU_VSCF_SCF_EN_HSCL_STR_UNION en_hscl_str;
 DPU_VSCF_SCF_EN_VSCL_STR_UNION en_vscl_str;
 DPU_VSCF_SCF_H_V_ORDER_UNION h_v_order;
 DPU_VSCF_SCF_CH_CORE_GT_UNION ch_core_gt;
 DPU_VSCF_SCF_INPUT_WIDTH_HEIGHT_UNION input_width_height;
 DPU_VSCF_SCF_OUTPUT_WIDTH_HEIGHT_UNION output_width_height;
 DPU_VSCF_SCF_COEF_MEM_CTRL_UNION coef_mem_ctrl;
 DPU_VSCF_SCF_EN_HSCL_UNION en_hscl;
 DPU_VSCF_SCF_EN_VSCL_UNION en_vscl;
 DPU_VSCF_SCF_ACC_HSCL_UNION acc_hscl;
 DPU_VSCF_SCF_ACC_HSCL1_UNION acc_hscl1;
 unsigned int rsv0[2];
 DPU_VSCF_SCF_INC_HSCL_UNION inc_hscl;
 DPU_VSCF_SCF_ACC_VSCL_UNION acc_vscl;
 DPU_VSCF_SCF_ACC_VSCL1_UNION acc_vscl1;
 unsigned int rsv1[2];
 DPU_VSCF_SCF_INC_VSCL_UNION inc_vscl;
 DPU_VSCF_SCF_EN_NONLINEAR_UNION en_nonlinear;
 unsigned int rsv2[11];
 DPU_VSCF_SCF_EN_MMP_UNION en_mmp;
 DPU_VSCF_SCF_DB_H0_UNION db_h0;
 DPU_VSCF_SCF_DB_H1_UNION db_h1;
 DPU_VSCF_SCF_DB_V0_UNION db_v0;
 DPU_VSCF_SCF_DB_V1_UNION db_v1;
 DPU_VSCF_SCF_LB_MEM_CTRL_UNION lb_mem_ctrl;
};
struct dpu_vscf_post_clip {
 DPU_VSCF_POST_CLIP_DISP_SIZE_UNION post_clip_disp_size;
 DPU_VSCF_POST_CLIP_CTL_HRZ_UNION post_clip_ctl_hrz;
 DPU_VSCF_POST_CLIP_CTL_VRZ_UNION post_clip_ctl_vrz;
 DPU_VSCF_POST_CLIP_EN_UNION post_clip_en;
};
struct dpu_vscf_scf_lut_6tap {
 DPU_VSCF_V0_SCF_VIDEO_6TAP_COEF_UNION scf_6tap_coef[COEF_6TAP_NUM];
};
struct dpu_vscf_scf_lut_5tap {
 DPU_VSCF_V0_SCF_VIDEO_5TAP_COEF_UNION scf_5tap_coef[COEF_5TAP_NUM];
};
struct dpu_vscf_scf_lut_4tap {
 DPU_VSCF_V0_SCF_VIDEO_4TAP_COEF_UNION scf_4tap_coef[COEF_4TAP_NUM];
};
struct dpu_vscf_params {
 struct dpu_vscf_scf_top_reg scf_top_reg;
 struct dpu_vscf_dfc dfc;
 struct dpu_vscf_bitext bitext;
 struct dpu_vscf_csc csc;
 struct dpu_vscf_scf scf;
 struct dpu_vscf_post_clip post_clip;
};
struct ScfParams {
    DPU_VSCF_SCF_EN_HSCL_STR_UNION en_hscl_str;
    DPU_VSCF_SCF_EN_VSCL_STR_UNION en_vscl_str;
    DPU_VSCF_SCF_H_V_ORDER_UNION h_v_order;
    DPU_VSCF_SCF_CH_CORE_GT_UNION ch_core_gt;
    DPU_VSCF_SCF_INPUT_WIDTH_HEIGHT_UNION input_width_height;
    DPU_VSCF_SCF_OUTPUT_WIDTH_HEIGHT_UNION output_width_height;
    DPU_VSCF_SCF_COEF_MEM_CTRL_UNION coef_mem_ctrl;
    DPU_VSCF_SCF_EN_HSCL_UNION en_hscl;
    DPU_VSCF_SCF_EN_VSCL_UNION en_vscl;
    DPU_VSCF_SCF_ACC_HSCL_UNION acc_hscl;
    DPU_VSCF_SCF_ACC_HSCL1_UNION acc_hscl1;
    DPU_VSCF_SCF_INC_HSCL_UNION inc_hscl;
    DPU_VSCF_SCF_ACC_VSCL_UNION acc_vscl;
    DPU_VSCF_SCF_ACC_VSCL1_UNION acc_vscl1;
    DPU_VSCF_SCF_INC_VSCL_UNION inc_vscl;
    DPU_VSCF_SCF_EN_NONLINEAR_UNION en_nonlinear;
    DPU_VSCF_SCF_EN_MMP_UNION en_mmp;
    DPU_VSCF_SCF_DB_H0_UNION db_h0;
    DPU_VSCF_SCF_DB_H1_UNION db_h1;
    DPU_VSCF_SCF_DB_V0_UNION db_v0;
    DPU_VSCF_SCF_DB_V1_UNION db_v1;
    DPU_VSCF_SCF_LB_MEM_CTRL_UNION lb_mem_ctrl;
};
struct DfcParams {
    DPU_VSCF_DFC_DISP_SIZE_UNION disp_size;
    DPU_VSCF_DFC_PIX_IN_NUM_UNION pix_in_num;
    DPU_VSCF_DFC_GLB_ALPHA01_UNION glb_alpha01;
    DPU_VSCF_DFC_DISP_FMT_UNION disp_fmt;
    DPU_VSCF_DFC_CLIP_CTL_HRZ_UNION clip_ctl_hrz;
    DPU_VSCF_DFC_CLIP_CTL_VRZ_UNION clip_ctl_vrz;
    DPU_VSCF_DFC_CTL_CLIP_EN_UNION ctl_clip_en;
    DPU_VSCF_DFC_ICG_MODULE_UNION icg_module;
    DPU_VSCF_DFC_DITHER_ENABLE_UNION dither_enable;
    DPU_VSCF_DFC_PADDING_CTL_UNION padding_ctl;
    DPU_VSCF_DFC_GLB_ALPHA23_UNION glb_alpha23;
};
#endif
