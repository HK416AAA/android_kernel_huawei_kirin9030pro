#ifndef AAE_ARSR_H
#define AAE_ARSR_H 
#include "soc_aae_interface.h"
#include "soc_dpu_define.h"
#define SCF_COEF_6TAP_NUM 264
#define SCF_COEF_5TAP_NUM 272
#define SCF_COEF_4TAP_NUM 136
#define ARSR_COEF_V_NUM 36
#define ARSR_COEF_H_NUM 100
#define EFFECT_PARAM_SIZE 65
static int g_arsr_scale_none_effect_param[EFFECT_PARAM_SIZE] = {
 1, 1, 1, 300, 332, 600, 20, 40, 452, 24, 48, 580, 512, 12,
 819, 682, 372, 20, -80, 8, 15, 128, 192, 40, 160, 0, 0, 8,
 10, 6, 16, 160, 2, 2, 120, 0, 200, 100, 160, 80, 640, 5120,
 320, 6400, 64, 300, 300, 0, 128, 300, 260, 5120, 16, 16,
 128, 384, 0, 0, 192, 256, 16, 32, 64, 80, 8
};
static int g_arsr_scale_up_effect_param[EFFECT_PARAM_SIZE] = {
 1, 1, 1, 300, 332, 600, 20, 40, 452, 24, 48, 580, 512, 12,
 819, 682, 372, 5, -80, 8, 15, 128, 192, 40, 160, 0, 0, 8,
 10, 6, 16, 160, 2, 2, 100, 0, 220, 100, 220, 80, 400, 816,
 320, 6400, 64, 300, 300, 0, 128, 300, 260, 5120, 16, 16,
 128, 384, 0, 0, 192, 256, 16, 32, 64, 80, 8
};
static int g_arsr_scale_down_effect_param[EFFECT_PARAM_SIZE] = {
 1, 1, 1, 300, 332, 600, 20, 40, 452, 24, 48, 580, 512, 12,
 819, 682, 372, 20, -80, 8, 15, 128, 192, 40, 160, 0, 0, 8,
 10, 6, 16, 160, 2, 2, 0, 0, 80, 50, 0, 0, 1280, 5120,
 800, 3200, 64, 300, 300, 0, 128, 300, 260, 5120, 16, 16,
 128, 384, 0, 0, 192, 256, 16, 32, 64, 80, 8
};
enum {
 ARSR1_PRE_SEL_SDMA,
 ARSR1_PRE_SEL_HDR,
 ARSR1_PRE_SEL_DEFAULT,
};
struct dpu_arsr_arsr_top_reg {
 AAE_ARSR_RD_SHADOW_UNION rd_shadow;
 AAE_ARSR_REG_DEFAULT_UNION reg_default;
 AAE_ARSR_TOP_CLK_SEL_UNION top_clk_sel;
 AAE_ARSR_TOP_CLK_EN_UNION top_clk_en;
 AAE_ARSR_REG_CTRL_UNION reg_ctrl;
 AAE_ARSR_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
 AAE_ARSR_REG_CTRL_DEBUG_UNION reg_ctrl_debug;
 AAE_ARSR_REG_CTRL_STATE_UNION reg_ctrl_state;
 AAE_ARSR_R_LB_DEBUG0_UNION r_lb_debug0;
 AAE_ARSR_R_LB_DEBUG1_UNION r_lb_debug1;
 AAE_ARSR_R_LB_DEBUG2_UNION r_lb_debug2;
 AAE_ARSR_R_LB_DEBUG3_UNION r_lb_debug3;
 AAE_ARSR_W_LB_DEBUG0_UNION w_lb_debug0;
 AAE_ARSR_W_LB_DEBUG1_UNION w_lb_debug1;
 AAE_ARSR_W_LB_DEBUG2_UNION w_lb_debug2;
 AAE_ARSR_W_LB_DEBUG3_UNION w_lb_debug3;
 AAE_ARSR_REG_CTRL_LAYER_ID_UNION reg_ctrl_layer_id;
};
struct dpu_arsr_dfc {
 AAE_ARSR_DFC_DISP_SIZE_UNION dfc_disp_size;
 AAE_ARSR_DFC_PIX_IN_NUM_UNION dfc_pix_in_num;
 AAE_ARSR_DFC_GLB_ALPHA01_UNION dfc_glb_alpha01;
 AAE_ARSR_DFC_DISP_FMT_UNION dfc_disp_fmt;
 AAE_ARSR_DFC_CLIP_CTL_HRZ_UNION dfc_clip_ctl_hrz;
 AAE_ARSR_DFC_CLIP_CTL_VRZ_UNION dfc_clip_ctl_vrz;
 AAE_ARSR_DFC_CTL_CLIP_EN_UNION dfc_ctl_clip_en;
 AAE_ARSR_DFC_ICG_MODULE_UNION dfc_icg_module;
 AAE_ARSR_DFC_DITHER_ENABLE_UNION dfc_dither_enable;
 AAE_ARSR_DFC_PADDING_CTL_UNION dfc_padding_ctl;
 AAE_ARSR_DFC_GLB_ALPHA23_UNION dfc_glb_alpha23;
};
struct dpu_arsr_bitext {
 AAE_ARSR_BITEXT_CTL_UNION bitext_ctl;
 AAE_ARSR_BITEXT_REG_INI0_0_UNION bitext_reg_ini0_0;
 AAE_ARSR_BITEXT_REG_INI0_1_UNION bitext_reg_ini0_1;
 AAE_ARSR_BITEXT_REG_INI0_2_UNION bitext_reg_ini0_2;
 AAE_ARSR_BITEXT_REG_INI0_3_UNION bitext_reg_ini0_3;
 AAE_ARSR_BITEXT_REG_INI1_0_UNION bitext_reg_ini1_0;
 AAE_ARSR_BITEXT_REG_INI1_1_UNION bitext_reg_ini1_1;
 AAE_ARSR_BITEXT_REG_INI1_2_UNION bitext_reg_ini1_2;
 AAE_ARSR_BITEXT_REG_INI1_3_UNION bitext_reg_ini1_3;
 AAE_ARSR_BITEXT_REG_INI2_0_UNION bitext_reg_ini2_0;
 AAE_ARSR_BITEXT_REG_INI2_1_UNION bitext_reg_ini2_1;
 AAE_ARSR_BITEXT_REG_INI2_2_UNION bitext_reg_ini2_2;
 AAE_ARSR_BITEXT_REG_INI2_3_UNION bitext_reg_ini2_3;
 AAE_ARSR_BITEXT_POWER_CTRL_C_UNION bitext_power_ctrl_c;
 AAE_ARSR_BITEXT_POWER_CTRL_SHIFT_UNION bitext_power_ctrl_shift;
 AAE_ARSR_BITEXT_FILT_00_UNION bitext_filt_00;
 AAE_ARSR_BITEXT_FILT_01_UNION bitext_filt_01;
 AAE_ARSR_BITEXT_FILT_02_UNION bitext_filt_02;
 AAE_ARSR_BITEXT_FILT_10_UNION bitext_filt_10;
 AAE_ARSR_BITEXT_FILT_11_UNION bitext_filt_11;
 AAE_ARSR_BITEXT_FILT_12_UNION bitext_filt_12;
 AAE_ARSR_BITEXT_FILT_20_UNION bitext_filt_20;
 unsigned int rsv[2];
 AAE_ARSR_BITEXT_FILT_21_UNION bitext_filt_21;
 AAE_ARSR_BITEXT_FILT_22_UNION bitext_filt_22;
 AAE_ARSR_BITEXT_THD_R0_UNION bitext_thd_r0;
 AAE_ARSR_BITEXT_THD_R1_UNION bitext_thd_r1;
 AAE_ARSR_BITEXT_THD_G0_UNION bitext_thd_g0;
 AAE_ARSR_BITEXT_THD_G1_UNION bitext_thd_g1;
 AAE_ARSR_BITEXT_THD_B0_UNION bitext_thd_b0;
 AAE_ARSR_BITEXT_THD_B1_UNION bitext_thd_b1;
 AAE_ARSR_BITEXT0_DBG0_UNION bitext0_dbg0;
};
struct dpu_arsr_csc_coef {
 AAE_ARSR_CSC_IDC0_UNION idc0;
 AAE_ARSR_CSC_IDC2_UNION idc2;
 AAE_ARSR_CSC_ODC0_UNION odc0;
 AAE_ARSR_CSC_ODC2_UNION odc2;
 AAE_ARSR_CSC_P00_UNION p00;
 AAE_ARSR_CSC_P01_UNION p01;
 AAE_ARSR_CSC_P02_UNION p02;
 AAE_ARSR_CSC_P10_UNION p10;
 AAE_ARSR_CSC_P11_UNION p11;
 AAE_ARSR_CSC_P12_UNION p12;
 AAE_ARSR_CSC_P20_UNION p20;
 AAE_ARSR_CSC_P21_UNION p21;
 AAE_ARSR_CSC_P22_UNION p22;
};
struct dpu_arsr_csc {
 struct dpu_arsr_csc_coef csc_coef;
 AAE_ARSR_CSC_ICG_MODULE_UNION csc_icg_module;
 AAE_ARSR_CSC_MPREC_UNION csc_mprec;
};
struct dpu_arsr_scf {
 AAE_ARSR_SCF_EN_HSCL_STR_UNION scf_en_hscl_str;
 AAE_ARSR_SCF_EN_VSCL_STR_UNION scf_en_vscl_str;
 AAE_ARSR_SCF_H_V_ORDER_UNION scf_h_v_order;
 AAE_ARSR_SCF_CH_CORE_GT_UNION scf_ch_core_gt;
 AAE_ARSR_SCF_INPUT_WIDTH_HEIGHT_UNION scf_input_width_height;
 AAE_ARSR_SCF_OUTPUT_WIDTH_HEIGHT_UNION scf_output_width_height;
 AAE_ARSR_SCF_COEF_MEM_CTRL_UNION scf_coef_mem_ctrl;
 AAE_ARSR_SCF_EN_HSCL_UNION scf_en_hscl;
 AAE_ARSR_SCF_EN_VSCL_UNION scf_en_vscl;
 AAE_ARSR_SCF_ACC_HSCL_UNION scf_acc_hscl;
 AAE_ARSR_SCF_ACC_HSCL1_UNION scf_acc_hscl1;
 unsigned int rsv0[2];
 AAE_ARSR_SCF_INC_HSCL_UNION scf_inc_hscl;
 AAE_ARSR_SCF_ACC_VSCL_UNION scf_acc_vscl;
 AAE_ARSR_SCF_ACC_VSCL1_UNION scf_acc_vscl1;
 unsigned int rsv1[2];
 AAE_ARSR_SCF_INC_VSCL_UNION scf_inc_vscl;
 AAE_ARSR_SCF_EN_NONLINEAR_UNION scf_en_nonlinear;
 unsigned int rsv2[11];
 AAE_ARSR_SCF_EN_MMP_UNION scf_en_mmp;
 AAE_ARSR_SCF_DB_H0_UNION scf_db_h0;
 AAE_ARSR_SCF_DB_H1_UNION scf_db_h1;
 AAE_ARSR_SCF_DB_V0_UNION scf_db_v0;
 AAE_ARSR_SCF_DB_V1_UNION scf_db_v1;
 AAE_ARSR_SCF_LB_MEM_CTRL_UNION scf_lb_mem_ctrl;
};
struct dpu_arsr_arsr {
 AAE_ARSR_INPUT_WIDTH_HEIGHT_UNION input_width_height;
 AAE_ARSR_OUTPUT_WIDTH_HEIGHT_UNION output_width_height;
 AAE_ARSR_IHLEFT_UNION ihleft;
 AAE_ARSR_IHLEFT1_UNION ihleft1;
 AAE_ARSR_IHRIGHT_UNION ihright;
 AAE_ARSR_IHRIGHT1_UNION ihright1;
 AAE_ARSR_IVTOP_UNION ivtop;
 AAE_ARSR_IVBOTTOM_UNION ivbottom;
 AAE_ARSR_IVBOTTOM1_UNION ivbottom1;
 AAE_ARSR_IHINC_UNION ihinc;
 AAE_ARSR_IVINC_UNION ivinc;
 AAE_ARSR_OFFSET_UNION offset;
 AAE_ARSR_MODE_UNION mode;
 AAE_ARSR_SKIN_THRES_Y_UNION skin_thres_y;
 AAE_ARSR_SKIN_THRES_U_UNION skin_thres_u;
 AAE_ARSR_SKIN_THRES_V_UNION skin_thres_v;
 AAE_ARSR_SKIN_CFG0_UNION skin_cfg0;
 AAE_ARSR_SKIN_CFG1_UNION skin_cfg1;
 AAE_ARSR_SKIN_CFG2_UNION skin_cfg2;
 AAE_ARSR_SHOOT_CFG1_UNION shoot_cfg1;
 AAE_ARSR_SHOOT_CFG2_UNION shoot_cfg2;
 AAE_ARSR_SHOOT_CFG3_UNION shoot_cfg3;
 AAE_ARSR_SHARP_CFG3_UNION sharp_cfg3;
 AAE_ARSR_SHARP_CFG4_UNION sharp_cfg4;
 AAE_ARSR_SHARP_CFG5_UNION sharp_cfg5;
 AAE_ARSR_SHARP_CFG6_UNION sharp_cfg6;
 AAE_ARSR_SHARP_CFG7_UNION sharp_cfg7;
 AAE_ARSR_SHARP_CFG8_UNION sharp_cfg8;
 AAE_ARSR_SHARPLEVEL_UNION sharplevel;
 AAE_ARSR_SHPGAIN_LOW_UNION shpgain_low;
 AAE_ARSR_SHPGAIN_MID_UNION shpgain_mid;
 AAE_ARSR_SHPGAIN_HIGH_UNION shpgain_high;
 AAE_ARSR_GAINCTRLSLOPH_MF_UNION gainctrlsloph_mf;
 AAE_ARSR_GAINCTRLSLOPL_MF_UNION gainctrlslopl_mf;
 AAE_ARSR_GAINCTRLSLOPH_HF_UNION gainctrlsloph_hf;
 AAE_ARSR_GAINCTRLSLOPL_HF_UNION gainctrlslopl_hf;
 AAE_ARSR_MF_LMT_UNION mf_lmt;
 AAE_ARSR_GAIN_MF_UNION gain_mf;
 AAE_ARSR_MF_B_UNION mf_b;
 AAE_ARSR_HF_LMT_UNION hf_lmt;
 AAE_ARSR_GAIN_HF_UNION gain_hf;
 AAE_ARSR_HF_B_UNION hf_b;
 AAE_ARSR_LF_CTRL_UNION lf_ctrl;
 AAE_ARSR_LF_VAR_UNION lf_var;
 AAE_ARSR_LF_CTRL_SLOP_UNION lf_ctrl_slop;
 AAE_ARSR_HF_SELECT_UNION hf_select;
 AAE_ARSR_SHARP_CFG2_H_UNION sharp_cfg2_h;
 AAE_ARSR_SHARP_CFG2_L_UNION sharp_cfg2_l;
 unsigned int rsv[4];
 AAE_ARSR_TEXTURW_ANALYSTS_UNION texturw_analysts;
 AAE_ARSR_INTPLSHOOTCTRL_UNION intplshootctrl;
 AAE_ARSR_ARSR2P_DEBUG0_UNION arsr2p_debug0;
 AAE_ARSR_ARSR2P_DEBUG1_UNION arsr2p_debug1;
 AAE_ARSR_ARSR2P_DEBUG2_UNION arsr2p_debug2;
 AAE_ARSR_ARSR2P_DEBUG3_UNION arsr2p_debug3;
 AAE_ARSR_ARSR2P_LB_MEM_CTRL_UNION arsr2p_lb_mem_ctrl;
 AAE_ARSR_COEF_MEM_CTRL_UNION coef_mem_ctrl;
};
struct dpu_arsr_post_csc {
 AAE_ARSR_POST_CSC_IDC0_UNION post_csc_idc0;
 AAE_ARSR_POST_CSC_IDC2_UNION post_csc_idc2;
 AAE_ARSR_POST_CSC_ODC0_UNION post_csc_odc0;
 AAE_ARSR_POST_CSC_ODC2_UNION post_csc_odc2;
 AAE_ARSR_POST_CSC_P00_UNION post_csc_p00;
 AAE_ARSR_POST_CSC_P01_UNION post_csc_p01;
 AAE_ARSR_POST_CSC_P02_UNION post_csc_p02;
 AAE_ARSR_POST_CSC_P10_UNION post_csc_p10;
 AAE_ARSR_POST_CSC_P11_UNION post_csc_p11;
 AAE_ARSR_POST_CSC_P12_UNION post_csc_p12;
 AAE_ARSR_POST_CSC_P20_UNION post_csc_p20;
 AAE_ARSR_POST_CSC_P21_UNION post_csc_p21;
 AAE_ARSR_POST_CSC_P22_UNION post_csc_p22;
 AAE_ARSR_POST_CSC_MODULE_EN_UNION post_csc_module_en;
 AAE_ARSR_POST_CSC_MPREC_UNION post_csc_mprec;
};
struct dpu_arsr_post_clip {
 AAE_ARSR_POST_CLIP_DISP_SIZE_UNION post_clip_disp_size;
 AAE_ARSR_POST_CLIP_CTL_HRZ_UNION post_clip_ctl_hrz;
 AAE_ARSR_POST_CLIP_CTL_VRZ_UNION post_clip_ctl_vrz;
 AAE_ARSR_POST_CLIP_EN_UNION post_clip_en;
};
struct dpu_arsr_scf_lut_6tap {
 AAE_ARSR_V0_SCF_VIDEO_6TAP_COEF_UNION scf_6tap_coef[SCF_COEF_6TAP_NUM];
};
struct dpu_arsr_scf_lut_5tap {
 AAE_ARSR_V0_SCF_VIDEO_5TAP_COEF_UNION scf_5tap_coef[SCF_COEF_5TAP_NUM];
};
struct dpu_arsr_scf_lut_4tap {
 AAE_ARSR_V0_SCF_VIDEO_4TAP_COEF_UNION scf_4tap_coef[SCF_COEF_4TAP_NUM];
};
struct dpu_arsr_arsr_lut_yv {
 AAE_ARSR_COEFY_V_UNION coefy_v[ARSR_COEF_V_NUM];
};
struct dpu_arsr_arsr_lut_yh {
 AAE_ARSR_COEFY_H_UNION coefy_h[ARSR_COEF_H_NUM];
};
struct dpu_arsr_arsr_lut_av {
 AAE_ARSR_COEFA_V_UNION coefa_v[ARSR_COEF_V_NUM];
};
struct dpu_arsr_arsr_lut_ah {
 AAE_ARSR_COEFA_H_UNION coefa_h[ARSR_COEF_H_NUM];
};
struct dpu_arsr_arsr_lut_uv_v {
 AAE_ARSR_COEFUV_V_UNION coefuv_v[ARSR_COEF_V_NUM];
};
struct dpu_arsr_arsr_lut_uv_h {
 AAE_ARSR_COEFUV_H_UNION coefuv_h[ARSR_COEF_H_NUM];
};
struct dpu_arsr_params {
 struct dpu_arsr_arsr_top_reg top_reg;
 struct dpu_arsr_dfc dfc;
 struct dpu_arsr_bitext bitext;
 struct dpu_arsr_csc csc;
 struct dpu_arsr_scf scf;
 struct dpu_arsr_arsr arsr;
 struct dpu_arsr_post_csc post_csc;
 struct dpu_arsr_post_clip post_clip;
};
#endif
