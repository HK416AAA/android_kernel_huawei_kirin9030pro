#ifndef __VEDU_CONFIG_H__
#define __VEDU_CONFIG_H__ 
typedef union {
    struct {
        unsigned int vcpi_enable_ve_eop : 1 ;
        unsigned int vcpi_enable_vedu_slice_end : 1 ;
        unsigned int vcpi_enable_ve_buffull : 1 ;
        unsigned int vcpi_enable_ve_pbitsover : 1 ;
        unsigned int vcpi_enable_line_pos : 1 ;
        unsigned int vcpi_enable_ppdf_dec_err : 1 ;
        unsigned int vcpi_enable_vedu_timeout : 1 ;
        unsigned int vcpi_cmdlst_sop_mask : 1 ;
        unsigned int vcpi_cmdlst_eop_mask : 1 ;
        unsigned int vcpi_soft_int0_mask : 1 ;
        unsigned int vcpi_soft_int1_mask : 1 ;
        unsigned int vcpi_soft_int2_mask : 1 ;
        unsigned int vcpi_soft_int3_mask : 1 ;
        unsigned int vcpi_lowlatency_slcint_mask : 1 ;
        unsigned int vcpi_enhance0_buffull_int_mask : 1 ;
        unsigned int vcpi_enhance0_pbitsover_int_mask : 1 ;
        unsigned int vcpi_enhance1_buffull_int_mask : 1 ;
        unsigned int vcpi_enhance1_pbitsover_int_mask : 1 ;
        unsigned int vcpi_enhance2_buffull_int_mask : 1 ;
        unsigned int vcpi_enhance2_pbitsover_int_mask : 1 ;
        unsigned int vcpi_hts_error_int_mask : 1 ;
        unsigned int vcpi_hts_event_int_mask : 1 ;
        unsigned int vcpi_hts_master_error_int_mask : 1 ;
        unsigned int reserved_0 : 9 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INTMASK;
typedef union {
    struct {
        unsigned int vcpi_clr_ve_eop : 1 ;
        unsigned int vcpi_clr_vedu_slice_end : 1 ;
        unsigned int vcpi_clr_ve_buffull : 1 ;
        unsigned int vcpi_clr_ve_pbitsover : 1 ;
        unsigned int vcpi_clr_line_pos : 1 ;
        unsigned int vcpi_clr_ppdf_dec_err : 1 ;
        unsigned int vcpi_clr_vedu_timeout : 1 ;
        unsigned int vcpi_clr_cmdlst_sop : 1 ;
        unsigned int vcpi_clr_cmdlst_eop : 1 ;
        unsigned int vcpi_clr_soft_int0 : 1 ;
        unsigned int vcpi_clr_soft_int1 : 1 ;
        unsigned int vcpi_clr_soft_int2 : 1 ;
        unsigned int vcpi_clr_soft_int3 : 1 ;
        unsigned int vcpi_clr_lowlatency_slcint : 1 ;
        unsigned int vcpi_clr_enhance0_buffull_int : 1 ;
        unsigned int vcpi_clr_enhance0_pbitsover_int : 1 ;
        unsigned int vcpi_clr_enhance1_buffull_int : 1 ;
        unsigned int vcpi_clr_enhance1_pbitsover_int : 1 ;
        unsigned int vcpi_clr_enhance2_buffull_int : 1 ;
        unsigned int vcpi_clr_enhance2_pbitsover_int : 1 ;
        unsigned int vcpi_clr_hts_error_int : 1 ;
        unsigned int vcpi_clr_hts_event_int : 1 ;
        unsigned int vcpi_clr_hts_master_error_int : 1 ;
        unsigned int reserved_0 : 9 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INTCLR;
typedef union {
    struct {
        unsigned int vcpi_vstart : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_START;
typedef union {
    struct {
        unsigned int vedu_bus_idle_req : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_BUS_IDLE_REQ;
typedef union {
    struct {
        unsigned int vcpi_vedsel : 1 ;
        unsigned int vedu_selfrst_en : 1 ;
        unsigned int vcpi_protocol : 2 ;
        unsigned int vcpi_cfg_mode : 1 ;
        unsigned int vcpi_slice_int_en : 1 ;
        unsigned int vcpi_sao_luma : 1 ;
        unsigned int vcpi_sao_chroma : 1 ;
        unsigned int vcpi_rec_cmp_en : 1 ;
        unsigned int vcpi_img_improve_en : 1 ;
        unsigned int vcpi_frame_type : 2 ;
        unsigned int vcpi_entropy_mode : 1 ;
        unsigned int vcpi_long_term_refpic : 1 ;
        unsigned int vcpi_ref_num : 1 ;
        unsigned int vcpi_pr_inter_en : 1 ;
        unsigned int vcpi_idr_pic : 1 ;
        unsigned int vcpi_pskip_en : 1 ;
        unsigned int vcpi_trans_mode : 2 ;
        unsigned int vcpi_blk8_inter : 1 ;
        unsigned int vcpi_sobel_weight_en : 1 ;
        unsigned int vcpi_high_speed_en : 1 ;
        unsigned int vcpi_tiles_en : 1 ;
        unsigned int vcpi_10bit_mode : 2 ;
        unsigned int vcpi_lcu_zeromotion_en : 1 ;
        unsigned int vcpi_scaling_list_en : 1 ;
        unsigned int vcpi_time_en : 1 ;
        unsigned int vcpi_lcu_rdo_ctrl_en : 1 ;
        unsigned int vcpi_ref_cmp_en : 1 ;
        unsigned int vcpi_refc_nload : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_MODE;
typedef union {
    struct {
        unsigned int vcpi_set_soft_int0 : 1 ;
        unsigned int vcpi_set_soft_int1 : 1 ;
        unsigned int vcpi_set_soft_int2 : 1 ;
        unsigned int vcpi_set_soft_int3 : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SOFTINTSET;
typedef union {
    struct {
        unsigned int vcpi_cmdlst_clkgate : 1 ;
        unsigned int vcpi_vcpi2cmdlst_eop_en : 1 ;
        unsigned int vcpi_mcu2cmdlst_eop_en : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_CMDLST_CLKGATE;
typedef union {
    struct {
        unsigned int vcpi_dpm_softrst : 1 ;
        unsigned int vcpi_cmdlst_softrst : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_CMD_DPM_SOFTRST;
typedef union {
    struct {
        unsigned int vcpi_ime_with_isp_en : 1 ;
        unsigned int vcpi_adaptive_ref_mode : 2 ;
        unsigned int vcpi_adapref_skip_mb_num : 6 ;
        unsigned int vcpi_ime_isp_mvconfidient_thr : 4 ;
        unsigned int vcpi_ispld_input_detection_en : 1 ;
        unsigned int vcpi_adaptive_ref_mode2 : 2 ;
        unsigned int vcpi_ispld_lcu_bound_x : 4 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_ISPLD_CFG;
typedef union {
    struct {
        unsigned int vcpi_raw_data_transform_precision_en : 1 ;
        unsigned int vcpi_raw_data_distortion_precision_en : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_RAW_DATA_MODE;
typedef union {
    struct {
        unsigned int emar_rec_b7_scramble : 1 ;
        unsigned int emar_rec_b8_scramble : 2 ;
        unsigned int emar_ori_y_b7_scramble : 2 ;
        unsigned int emar_ori_y_b8_scramble : 2 ;
        unsigned int emar_ori_y_b9_scramble : 2 ;
        unsigned int emar_ori_uv_b7_scramble : 2 ;
        unsigned int emar_ori_uv_b8_scramble : 2 ;
        unsigned int emar_ori_uv_b9_scramble : 2 ;
        unsigned int reserved_0 : 17 ;
    } bits;
    unsigned int u32;
} U_VEDU_EMAR_SCRAMBLE_TYPE;
typedef union {
    struct {
        unsigned int vcpi_rc_cu_qp_en : 1 ;
        unsigned int vcpi_rc_row_qp_en : 1 ;
        unsigned int vcpi_move_scene_en : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int vcpi_strong_edge_move_en : 1 ;
        unsigned int reserved_1 : 1 ;
        unsigned int reserved_2 : 2 ;
        unsigned int vcpi_rc_low_luma_en : 1 ;
        unsigned int reserved_3 : 1 ;
        unsigned int reserved_4 : 1 ;
        unsigned int vcpi_rd_min_sad_flag_en : 1 ;
        unsigned int reserved_5 : 2 ;
        unsigned int vcpi_low_min_sad_en : 1 ;
        unsigned int vcpi_prev_min_sad_en : 1 ;
        unsigned int vcpi_qpgld_en : 1 ;
        unsigned int vcpi_map_roikeep_en : 1 ;
        unsigned int vcpi_flat_region_en : 1 ;
        unsigned int vcpi_qp_restrain_large_sad : 1 ;
        unsigned int reserved_6 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_RC_ENABLE;
typedef union {
    struct {
        unsigned int vlcst_ptbits_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_VLCST_PTBITS_EN;
typedef union {
    struct {
        unsigned int ppfd_st_bypass_en : 1 ;
        unsigned int sqrt_lambda_ini : 17 ;
        unsigned int rc_mode : 1 ;
        unsigned int slice_mvd_l1_zero_flag : 1 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_PPFD_ST_CFG;
typedef union {
    struct {
        unsigned int vcpi_cr_qp_offset : 5 ;
        unsigned int vcpi_cb_qp_offset : 5 ;
        unsigned int vcpi_frm_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int vcpi_intra_det_qp_en : 1 ;
        unsigned int vcpi_rc_cu_madi_en : 1 ;
        unsigned int vcpi_slice_cr_qp_offset : 5 ;
        unsigned int vcpi_slice_cb_qp_offset : 5 ;
        unsigned int vcpi_chromaRdoWeightingIntraEn : 1 ;
        unsigned int reserved_1 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_QPCFG;
typedef union {
    struct {
        unsigned int qpg_min_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_max_qp : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_cu_qp_delta_enable_flag : 1 ;
        unsigned int reserved_2 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_MAX_MIN_QP;
typedef union {
    struct {
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_smart_get_cu32_qp_mode : 2 ;
        unsigned int qpg_smart_get_cu64_qp_mode : 2 ;
        unsigned int qpg_qp_detlta_size_cu64 : 1 ;
        unsigned int reserved_1 : 25 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_SMART_REG;
typedef union {
    struct {
        unsigned int qpg_qp_delta : 4 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_row_target_bits : 25 ;
        unsigned int reserved_1 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_ROW_TARGET_BITS;
typedef union {
    struct {
        unsigned int qpg_ave_lcu_bits : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_AVERAGE_LCU_BITS;
typedef union {
    struct {
        unsigned int qpg_cu_qp_delta_thresh0 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh1 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh2 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh3 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CU_QP_DELTA_THRESH_REG0;
typedef union {
    struct {
        unsigned int qpg_cu_qp_delta_thresh4 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh5 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh6 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh7 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CU_QP_DELTA_THRESH_REG1;
typedef union {
    struct {
        unsigned int qpg_cu_qp_delta_thresh8 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh9 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh10 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh11 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CU_QP_DELTA_THRESH_REG2;
typedef union {
    struct {
        unsigned int qpg_cu_qp_delta_thresh12 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh13 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh14 : 8 ;
        unsigned int qpg_cu_qp_delta_thresh15 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CU_QP_DELTA_THRESH_REG3;
typedef union {
    struct {
        unsigned int qpg_qp_delta_level_0 : 2 ;
        unsigned int qpg_qp_delta_level_1 : 2 ;
        unsigned int qpg_qp_delta_level_2 : 2 ;
        unsigned int qpg_qp_delta_level_3 : 2 ;
        unsigned int qpg_qp_delta_level_4 : 2 ;
        unsigned int qpg_qp_delta_level_5 : 2 ;
        unsigned int qpg_qp_delta_level_6 : 2 ;
        unsigned int qpg_qp_delta_level_7 : 2 ;
        unsigned int qpg_qp_delta_level_8 : 2 ;
        unsigned int qpg_qp_delta_level_9 : 2 ;
        unsigned int qpg_qp_delta_level_10 : 2 ;
        unsigned int qpg_qp_delta_level_11 : 2 ;
        unsigned int qpg_qp_delta_level_12 : 2 ;
        unsigned int qpg_qp_delta_level_13 : 2 ;
        unsigned int qpg_qp_delta_level_14 : 2 ;
        unsigned int qpg_qp_delta_level_15 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_DELTA_LEVEL;
typedef union {
    struct {
        unsigned int qpg_qp_madi_switch_thr : 5 ;
        unsigned int reserved_0 : 27 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_MADI_SWITCH_THR;
typedef union {
    struct {
        unsigned int vcpi_rc_cu_sad_en : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vcpi_sad_switch_thr : 5 ;
        unsigned int reserved_1 : 7 ;
        unsigned int vcpi_rc_cu_sad_mod : 2 ;
        unsigned int vcpi_rc_cu_sad_offset : 8 ;
        unsigned int vcpi_rc_cu_sad_gain : 4 ;
        unsigned int reserved_2 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CURR_SAD_EN;
typedef union {
    struct {
        unsigned int vcpi_curr_sad_level_0 : 2 ;
        unsigned int vcpi_curr_sad_level_1 : 2 ;
        unsigned int vcpi_curr_sad_level_2 : 2 ;
        unsigned int vcpi_curr_sad_level_3 : 2 ;
        unsigned int vcpi_curr_sad_level_4 : 2 ;
        unsigned int vcpi_curr_sad_level_5 : 2 ;
        unsigned int vcpi_curr_sad_level_6 : 2 ;
        unsigned int vcpi_curr_sad_level_7 : 2 ;
        unsigned int vcpi_curr_sad_level_8 : 2 ;
        unsigned int vcpi_curr_sad_level_9 : 2 ;
        unsigned int vcpi_curr_sad_level_10 : 2 ;
        unsigned int vcpi_curr_sad_level_11 : 2 ;
        unsigned int vcpi_curr_sad_level_12 : 2 ;
        unsigned int vcpi_curr_sad_level_13 : 2 ;
        unsigned int vcpi_curr_sad_level_14 : 2 ;
        unsigned int vcpi_curr_sad_level_15 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CURR_SAD_LEVEL;
typedef union {
    struct {
        unsigned int vcpi_curr_sad_thresh_0 : 8 ;
        unsigned int vcpi_curr_sad_thresh_1 : 8 ;
        unsigned int vcpi_curr_sad_thresh_2 : 8 ;
        unsigned int vcpi_curr_sad_thresh_3 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CURR_SAD_THRESH0;
typedef union {
    struct {
        unsigned int vcpi_curr_sad_thresh_4 : 8 ;
        unsigned int vcpi_curr_sad_thresh_5 : 8 ;
        unsigned int vcpi_curr_sad_thresh_6 : 8 ;
        unsigned int vcpi_curr_sad_thresh_7 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CURR_SAD_THRESH1;
typedef union {
    struct {
        unsigned int vcpi_curr_sad_thresh_8 : 8 ;
        unsigned int vcpi_curr_sad_thresh_9 : 8 ;
        unsigned int vcpi_curr_sad_thresh_10 : 8 ;
        unsigned int vcpi_curr_sad_thresh_11 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CURR_SAD_THRESH2;
typedef union {
    struct {
        unsigned int vcpi_curr_sad_thresh_12 : 8 ;
        unsigned int vcpi_curr_sad_thresh_13 : 8 ;
        unsigned int vcpi_curr_sad_thresh_14 : 8 ;
        unsigned int vcpi_curr_sad_thresh_15 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CURR_SAD_THRESH3;
typedef union {
    struct {
        unsigned int vcpi_rc_luma_en : 1 ;
        unsigned int vcpi_rc_luma_mode : 2 ;
        unsigned int reserved_0 : 1 ;
        unsigned int vcpi_rc_luma_switch_thr : 5 ;
        unsigned int reserved_1 : 3 ;
        unsigned int vcpi_rc_luma_low_madi_thr : 8 ;
        unsigned int vcpi_rc_luma_high_madi_thr : 8 ;
        unsigned int reserved_2 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_LUMA_RC;
typedef union {
    struct {
        unsigned int vcpi_rc_luma_level_0 : 2 ;
        unsigned int vcpi_rc_luma_level_1 : 2 ;
        unsigned int vcpi_rc_luma_level_2 : 2 ;
        unsigned int vcpi_rc_luma_level_3 : 2 ;
        unsigned int vcpi_rc_luma_level_4 : 2 ;
        unsigned int vcpi_rc_luma_level_5 : 2 ;
        unsigned int vcpi_rc_luma_level_6 : 2 ;
        unsigned int vcpi_rc_luma_level_7 : 2 ;
        unsigned int vcpi_rc_luma_level_8 : 2 ;
        unsigned int vcpi_rc_luma_level_9 : 2 ;
        unsigned int vcpi_rc_luma_level_10 : 2 ;
        unsigned int vcpi_rc_luma_level_11 : 2 ;
        unsigned int vcpi_rc_luma_level_12 : 2 ;
        unsigned int vcpi_rc_luma_level_13 : 2 ;
        unsigned int vcpi_rc_luma_level_14 : 2 ;
        unsigned int vcpi_rc_luma_level_15 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_LUMA_LEVEL;
typedef union {
    struct {
        unsigned int vcpi_rc_luma_thresh_0 : 8 ;
        unsigned int vcpi_rc_luma_thresh_1 : 8 ;
        unsigned int vcpi_rc_luma_thresh_2 : 8 ;
        unsigned int vcpi_rc_luma_thresh_3 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_LUMA_THRESH0;
typedef union {
    struct {
        unsigned int vcpi_rc_luma_thresh_4 : 8 ;
        unsigned int vcpi_rc_luma_thresh_5 : 8 ;
        unsigned int vcpi_rc_luma_thresh_6 : 8 ;
        unsigned int vcpi_rc_luma_thresh_7 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_LUMA_THRESH1;
typedef union {
    struct {
        unsigned int vcpi_rc_luma_thresh_8 : 8 ;
        unsigned int vcpi_rc_luma_thresh_9 : 8 ;
        unsigned int vcpi_rc_luma_thresh_10 : 8 ;
        unsigned int vcpi_rc_luma_thresh_11 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_LUMA_THRESH2;
typedef union {
    struct {
        unsigned int vcpi_rc_luma_thresh_12 : 8 ;
        unsigned int vcpi_rc_luma_thresh_13 : 8 ;
        unsigned int vcpi_rc_luma_thresh_14 : 8 ;
        unsigned int vcpi_rc_luma_thresh_15 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_LUMA_THRESH3;
typedef union {
    struct {
        unsigned int vcpi_hts_master_idle_bypass : 1 ;
        unsigned int vcpi_hts_slave_idle_bypass : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_MISC_CFG;
typedef union {
    struct {
        unsigned int vcpi_r_outstanding0 : 7 ;
        unsigned int vcpi_w_outstanding : 5 ;
        unsigned int vcpi_r_outstanding1 : 7 ;
        unsigned int reserved_0 : 13 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_OUTSTD;
typedef union {
    struct {
        unsigned int vctrl_lcu_performance_baseline : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_LCU_BASELINE;
typedef union {
    unsigned int u32;
} U_VEDU_VCPI_SPMEM_CTRL_1;
typedef union {
    struct {
        unsigned int rasshcms_svt_rtsel : 2 ;
        unsigned int rasshcms_lvt_rtsel : 2 ;
        unsigned int rasshcms_svt_wtsel : 2 ;
        unsigned int rasshcms_lvt_wtsel : 2 ;
        unsigned int rasshcmu_svt_rtsel : 2 ;
        unsigned int rasshcmu_lvt_rtsel : 2 ;
        unsigned int rasshcmu_svt_wtsel : 2 ;
        unsigned int rasshcmu_lvt_wtsel : 2 ;
        unsigned int ras_svt_rtsel : 2 ;
        unsigned int ras_lvt_rtsel : 2 ;
        unsigned int ras_svt_wtsel : 2 ;
        unsigned int ras_lvt_wtsel : 2 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SPMEM_CTRL_2;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda00 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG00;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda01 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG01;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda02 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG02;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda03 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG03;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda04 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG04;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda05 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG05;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda06 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG06;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda07 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG07;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda08 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG08;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda09 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG09;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda10 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG10;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda11 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG11;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda12 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG12;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda13 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG13;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda14 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG14;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda15 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG15;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda16 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG16;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda17 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG17;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda18 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG18;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda19 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG19;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda20 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG20;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda21 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG21;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda22 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG22;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda23 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG23;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda24 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG24;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda25 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG25;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda26 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG26;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda27 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG27;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda28 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG28;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda29 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG29;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda30 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG30;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda31 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG31;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda32 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG32;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda33 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG33;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda34 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG34;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda35 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG35;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda36 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG36;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda37 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG37;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda38 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG38;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda39 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG39;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda40 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG40;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda41 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG41;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda42 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG42;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda43 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG43;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda44 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG44;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda45 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG45;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda46 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG46;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda47 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG47;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda48 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG48;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda49 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG49;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda50 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG50;
typedef union {
    struct {
        unsigned int vctrl_enhanced_layer_lambda51 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG51;
typedef union {
    struct {
        unsigned int layer_en : 4 ;
        unsigned int reserved_0 : 4 ;
        unsigned int flux_req_en_l : 1 ;
        unsigned int flux_req_en_h : 1 ;
        unsigned int reserved_1 : 22 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_GCFG;
typedef union {
    struct {
        unsigned int flux_req_gran_l : 8 ;
        unsigned int flux_req_gran_h : 8 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_GRAN;
typedef union {
    struct {
        unsigned int flux_req_thres_l : 16 ;
        unsigned int flux_req_recover_l : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_THRESHOLD_L;
typedef union {
    struct {
        unsigned int flux_req_thres_h : 16 ;
        unsigned int flux_req_recover_h : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_THRESHOLD_H;
typedef union {
    struct {
        unsigned int flux_req_thres_intrapu4_offset : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_INTRAPU4_OFFSET;
typedef union {
    struct {
        unsigned int curld_depthcoding_u_pixel : 10 ;
        unsigned int curld_depthcoding_v_pixel : 10 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_DEPTHCODING;
typedef union {
    struct {
        unsigned int curld_watermark_startx : 16 ;
        unsigned int curld_watermark_starty : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_WATERMARK_CFG;
typedef union {
    struct {
        unsigned int curld_watermark_width : 16 ;
        unsigned int curld_watermark_height : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_WATERMARK_SIZE;
typedef union {
    struct {
        unsigned int vcpi_pmest_enable : 1 ;
        unsigned int vcpi_best_ref_prejudge_en : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_MODE2;
typedef union {
    struct {
        unsigned int wide_ynarrow_en : 1 ;
        unsigned int wide_cnarrow_en : 1 ;
        unsigned int rgb_clip_en : 1 ;
        unsigned int mlsb_sel : 1 ;
        unsigned int curld_watermark_en : 1 ;
        unsigned int curld_depthcoding_en : 1 ;
        unsigned int curld_raw_data_mode : 2 ;
        unsigned int curld_raw_data_bitdepth : 2 ;
        unsigned int vcpi_raw_data_qpinfo_store_en : 1 ;
        unsigned int vcpi_raw_data_qpinfo_load_en : 1 ;
        unsigned int reserved_0 : 2 ;
        unsigned int curld_col2gray_en : 1 ;
        unsigned int curld_clip_en : 1 ;
        unsigned int reserved_1 : 4 ;
        unsigned int curld_read_interval : 8 ;
        unsigned int curld_read_interval_mode : 1 ;
        unsigned int reserved_2 : 1 ;
        unsigned int reserved_3 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_GCFG;
typedef union {
    struct {
        unsigned int reserved_0 : 16 ;
        unsigned int vcpi_roi_osd_sel_0 : 1 ;
        unsigned int vcpi_roi_osd_sel_1 : 1 ;
        unsigned int vcpi_roi_osd_sel_2 : 1 ;
        unsigned int vcpi_roi_osd_sel_3 : 1 ;
        unsigned int vcpi_roi_osd_sel_4 : 1 ;
        unsigned int vcpi_roi_osd_sel_5 : 1 ;
        unsigned int vcpi_roi_osd_sel_6 : 1 ;
        unsigned int vcpi_roi_osd_sel_7 : 1 ;
        unsigned int reserved_1 : 1 ;
        unsigned int reserved_2 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_OSD_ENABLE;
typedef union {
    struct {
        unsigned int vcpi_crop_en : 1 ;
        unsigned int vcpi_scale_en : 1 ;
        unsigned int vcpi_store_mode : 1 ;
        unsigned int vcpi_blk_type : 3 ;
        unsigned int vcpi_str_fmt : 4 ;
        unsigned int vcpi_package_sel : 4 ;
        unsigned int vcpi_recst_disable : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int reserved_1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_STRFMT;
typedef union {
    struct {
        unsigned int vcpi_intra_cu_en : 4 ;
        unsigned int vcpi_ipcm_en : 1 ;
        unsigned int vcpi_intra_h264_cutdiag : 1 ;
        unsigned int vcpi_cu8_rdo_distortion_sel : 1 ;
        unsigned int vcpi_subjective_rdo_en : 1 ;
        unsigned int vcpi_fme_cu_en : 4 ;
        unsigned int vcpi_mrg_cu_en : 4 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INTRA_INTER_CU_EN;
typedef union {
    struct {
        unsigned int vcpi_cross_slice : 1 ;
        unsigned int vcpi_cross_tile : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_CROSS_TILE_SLC;
typedef union {
    struct {
        unsigned int vcpi_slice_size : 16 ;
        unsigned int vcpi_slcspilt_mod : 1 ;
        unsigned int vcpi_multislc_en : 1 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_MULTISLC;
typedef union {
    struct {
        unsigned int vctrl_lcu_target_bit : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_LCU_TARGET_BIT;
typedef union {
    struct {
        unsigned int vcpi_sw_l0_width : 7 ;
        unsigned int reserved_0 : 9 ;
        unsigned int vcpi_sw_l0_height : 7 ;
        unsigned int reserved_1 : 9 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SW_L0_SIZE;
typedef union {
    struct {
        unsigned int vcpi_insert_i_slc_idx : 8 ;
        unsigned int vcpi_insert_i_slc_en : 1 ;
        unsigned int reserved_0 : 23 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_I_SLC_INSERT;
typedef union {
    struct {
        unsigned int pme_safe_line : 16 ;
        unsigned int pme_safe_line_val : 1 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SAFE_CFG;
typedef union {
    struct {
        unsigned int pme_iblk_refresh_start_num : 18 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_IBLK_REFRESH;
typedef union {
    struct {
        unsigned int pme_iblk_refresh_num : 18 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_IBLK_REFRESH_NUM;
typedef union {
    struct {
        unsigned int intra_cu4_mode0_en : 1 ;
        unsigned int intra_cu4_mode1_en : 1 ;
        unsigned int intra_cu4_mode2_en : 1 ;
        unsigned int intra_cu4_mode3_en : 1 ;
        unsigned int intra_cu4_mode4_en : 1 ;
        unsigned int intra_cu4_mode5_en : 1 ;
        unsigned int intra_cu4_mode6_en : 1 ;
        unsigned int intra_cu4_mode7_en : 1 ;
        unsigned int intra_cu4_mode8_en : 1 ;
        unsigned int intra_cu4_mode9_en : 1 ;
        unsigned int intra_cu4_mode10_en : 1 ;
        unsigned int intra_cu4_mode11_en : 1 ;
        unsigned int intra_cu4_mode12_en : 1 ;
        unsigned int intra_cu4_mode13_en : 1 ;
        unsigned int intra_cu4_mode14_en : 1 ;
        unsigned int intra_cu4_mode15_en : 1 ;
        unsigned int intra_cu4_mode16_en : 1 ;
        unsigned int intra_cu4_mode17_en : 1 ;
        unsigned int intra_cu4_mode18_en : 1 ;
        unsigned int intra_cu4_mode19_en : 1 ;
        unsigned int intra_cu4_mode20_en : 1 ;
        unsigned int intra_cu4_mode21_en : 1 ;
        unsigned int intra_cu4_mode22_en : 1 ;
        unsigned int intra_cu4_mode23_en : 1 ;
        unsigned int intra_cu4_mode24_en : 1 ;
        unsigned int intra_cu4_mode25_en : 1 ;
        unsigned int intra_cu4_mode26_en : 1 ;
        unsigned int intra_cu4_mode27_en : 1 ;
        unsigned int intra_cu4_mode28_en : 1 ;
        unsigned int intra_cu4_mode29_en : 1 ;
        unsigned int intra_cu4_mode30_en : 1 ;
        unsigned int intra_cu4_mode31_en : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL4_ANG_0EN;
typedef union {
    struct {
        unsigned int intra_cu4_mode32_en : 1 ;
        unsigned int intra_cu4_mode33_en : 1 ;
        unsigned int intra_cu4_mode34_en : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL4_ANG_1EN;
typedef union {
    struct {
        unsigned int intra_cu8_mode0_en : 1 ;
        unsigned int intra_cu8_mode1_en : 1 ;
        unsigned int intra_cu8_mode2_en : 1 ;
        unsigned int intra_cu8_mode3_en : 1 ;
        unsigned int intra_cu8_mode4_en : 1 ;
        unsigned int intra_cu8_mode5_en : 1 ;
        unsigned int intra_cu8_mode6_en : 1 ;
        unsigned int intra_cu8_mode7_en : 1 ;
        unsigned int intra_cu8_mode8_en : 1 ;
        unsigned int intra_cu8_mode9_en : 1 ;
        unsigned int intra_cu8_mode10_en : 1 ;
        unsigned int intra_cu8_mode11_en : 1 ;
        unsigned int intra_cu8_mode12_en : 1 ;
        unsigned int intra_cu8_mode13_en : 1 ;
        unsigned int intra_cu8_mode14_en : 1 ;
        unsigned int intra_cu8_mode15_en : 1 ;
        unsigned int intra_cu8_mode16_en : 1 ;
        unsigned int intra_cu8_mode17_en : 1 ;
        unsigned int intra_cu8_mode18_en : 1 ;
        unsigned int intra_cu8_mode19_en : 1 ;
        unsigned int intra_cu8_mode20_en : 1 ;
        unsigned int intra_cu8_mode21_en : 1 ;
        unsigned int intra_cu8_mode22_en : 1 ;
        unsigned int intra_cu8_mode23_en : 1 ;
        unsigned int intra_cu8_mode24_en : 1 ;
        unsigned int intra_cu8_mode25_en : 1 ;
        unsigned int intra_cu8_mode26_en : 1 ;
        unsigned int intra_cu8_mode27_en : 1 ;
        unsigned int intra_cu8_mode28_en : 1 ;
        unsigned int intra_cu8_mode29_en : 1 ;
        unsigned int intra_cu8_mode30_en : 1 ;
        unsigned int intra_cu8_mode31_en : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL8_ANG_0EN;
typedef union {
    struct {
        unsigned int intra_cu8_mode32_en : 1 ;
        unsigned int intra_cu8_mode33_en : 1 ;
        unsigned int intra_cu8_mode34_en : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL8_ANG_1EN;
typedef union {
    struct {
        unsigned int intra_cu16_mode0_en : 1 ;
        unsigned int intra_cu16_mode1_en : 1 ;
        unsigned int intra_cu16_mode2_en : 1 ;
        unsigned int intra_cu16_mode3_en : 1 ;
        unsigned int intra_cu16_mode4_en : 1 ;
        unsigned int intra_cu16_mode5_en : 1 ;
        unsigned int intra_cu16_mode6_en : 1 ;
        unsigned int intra_cu16_mode7_en : 1 ;
        unsigned int intra_cu16_mode8_en : 1 ;
        unsigned int intra_cu16_mode9_en : 1 ;
        unsigned int intra_cu16_mode10_en : 1 ;
        unsigned int intra_cu16_mode11_en : 1 ;
        unsigned int intra_cu16_mode12_en : 1 ;
        unsigned int intra_cu16_mode13_en : 1 ;
        unsigned int intra_cu16_mode14_en : 1 ;
        unsigned int intra_cu16_mode15_en : 1 ;
        unsigned int intra_cu16_mode16_en : 1 ;
        unsigned int intra_cu16_mode17_en : 1 ;
        unsigned int intra_cu16_mode18_en : 1 ;
        unsigned int intra_cu16_mode19_en : 1 ;
        unsigned int intra_cu16_mode20_en : 1 ;
        unsigned int intra_cu16_mode21_en : 1 ;
        unsigned int intra_cu16_mode22_en : 1 ;
        unsigned int intra_cu16_mode23_en : 1 ;
        unsigned int intra_cu16_mode24_en : 1 ;
        unsigned int intra_cu16_mode25_en : 1 ;
        unsigned int intra_cu16_mode26_en : 1 ;
        unsigned int intra_cu16_mode27_en : 1 ;
        unsigned int intra_cu16_mode28_en : 1 ;
        unsigned int intra_cu16_mode29_en : 1 ;
        unsigned int intra_cu16_mode30_en : 1 ;
        unsigned int intra_cu16_mode31_en : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL16_ANG_0EN;
typedef union {
    struct {
        unsigned int intra_cu16_mode32_en : 1 ;
        unsigned int intra_cu16_mode33_en : 1 ;
        unsigned int intra_cu16_mode34_en : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL16_ANG_1EN;
typedef union {
    struct {
        unsigned int intra_cu32_mode0_en : 1 ;
        unsigned int intra_cu32_mode1_en : 1 ;
        unsigned int intra_cu32_mode2_en : 1 ;
        unsigned int intra_cu32_mode3_en : 1 ;
        unsigned int intra_cu32_mode4_en : 1 ;
        unsigned int intra_cu32_mode5_en : 1 ;
        unsigned int intra_cu32_mode6_en : 1 ;
        unsigned int intra_cu32_mode7_en : 1 ;
        unsigned int intra_cu32_mode8_en : 1 ;
        unsigned int intra_cu32_mode9_en : 1 ;
        unsigned int intra_cu32_mode10_en : 1 ;
        unsigned int intra_cu32_mode11_en : 1 ;
        unsigned int intra_cu32_mode12_en : 1 ;
        unsigned int intra_cu32_mode13_en : 1 ;
        unsigned int intra_cu32_mode14_en : 1 ;
        unsigned int intra_cu32_mode15_en : 1 ;
        unsigned int intra_cu32_mode16_en : 1 ;
        unsigned int intra_cu32_mode17_en : 1 ;
        unsigned int intra_cu32_mode18_en : 1 ;
        unsigned int intra_cu32_mode19_en : 1 ;
        unsigned int intra_cu32_mode20_en : 1 ;
        unsigned int intra_cu32_mode21_en : 1 ;
        unsigned int intra_cu32_mode22_en : 1 ;
        unsigned int intra_cu32_mode23_en : 1 ;
        unsigned int intra_cu32_mode24_en : 1 ;
        unsigned int intra_cu32_mode25_en : 1 ;
        unsigned int intra_cu32_mode26_en : 1 ;
        unsigned int intra_cu32_mode27_en : 1 ;
        unsigned int intra_cu32_mode28_en : 1 ;
        unsigned int intra_cu32_mode29_en : 1 ;
        unsigned int intra_cu32_mode30_en : 1 ;
        unsigned int intra_cu32_mode31_en : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL32_ANG_0EN;
typedef union {
    struct {
        unsigned int intra_cu32_mode32_en : 1 ;
        unsigned int intra_cu32_mode33_en : 1 ;
        unsigned int intra_cu32_mode34_en : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CHNL32_ANG_1EN;
typedef union {
    struct {
        unsigned int pack_vcpi2cu_tq_bypass_enabled_flag : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int pack_vcpi2cu_qp_min_cu_size : 3 ;
        unsigned int reserved_1 : 25 ;
    } bits;
    unsigned int u32;
} U_VEDU_PACK_CU_PARAMETER;
typedef union {
    struct {
        unsigned int pack_vcpi2pu_log2_min_ipcm_cbsizey : 3 ;
        unsigned int reserved_0 : 1 ;
        unsigned int pack_vcpi2pu_log2_max_ipcm_cbsizey : 3 ;
        unsigned int reserved_1 : 25 ;
    } bits;
    unsigned int u32;
} U_VEDU_PACK_PCM_PARAMETER;
typedef union {
    struct {
        unsigned int vcpi_tile_qpg_readline_interval : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_READLINE_INTERVAL;
typedef union {
    struct {
        unsigned int vcpi_pmv_readline_interval : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_PMV_READLINE_INTERVAL;
typedef union {
    struct {
        unsigned int rgb2yuv_y_0coef : 15 ;
        unsigned int reserved_0 : 1 ;
        unsigned int rgb2yuv_y_1coef : 15 ;
        unsigned int reserved_1 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_RGB2YUV_COEF_P0;
typedef union {
    struct {
        unsigned int rgb2yuv_y_2coef : 15 ;
        unsigned int reserved_0 : 1 ;
        unsigned int rgb2yuv_u_0coef : 15 ;
        unsigned int reserved_1 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_RGB2YUV_COEF_P1;
typedef union {
    struct {
        unsigned int rgb2yuv_u_1coef : 15 ;
        unsigned int reserved_0 : 1 ;
        unsigned int rgb2yuv_u_2coef : 15 ;
        unsigned int reserved_1 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_RGB2YUV_COEF_P2;
typedef union {
    struct {
        unsigned int rgb_y_rnd : 16 ;
        unsigned int rgb_u_rnd : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_RGB2YUV_OFFSET;
typedef union {
    struct {
        unsigned int clip_min_y : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int clip_max_y : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_CLIP_THR_Y;
typedef union {
    struct {
        unsigned int clip_min_c : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int clip_max_c : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_CLIP_THR_C;
typedef union {
    struct {
        unsigned int rgb2yuv_shift_width : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VEDU_RGB2YUV_SHIFT_WIDTH;
typedef union {
    struct {
        unsigned int rgb2yuv_v_0coef : 15 ;
        unsigned int reserved_0 : 1 ;
        unsigned int rgb2yuv_v_1coef : 15 ;
        unsigned int reserved_1 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_RGB2YUV_COEF_P3;
typedef union {
    struct {
        unsigned int rgb2yuv_v_2coef : 15 ;
        unsigned int reserved_0 : 1 ;
        unsigned int rgb_v_rnd : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_RGB2YUV_COEF_P4;
typedef union {
    struct {
        unsigned int curld_narrow_chrm_min : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int curld_narrow_chrm_max : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_NARROW_CHRM;
typedef union {
    struct {
        unsigned int curld_narrow_luma_min : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int curld_narrow_luma_max : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_NARROW_LUMA;
typedef union {
    struct {
        unsigned int reserved_0 : 16 ;
        unsigned int vcpi_curld_watermark_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_WATERMARK_STRIDE;
typedef union {
    struct {
        unsigned int rgb_clip_min : 10 ;
        unsigned int rgb_clip_max : 10 ;
        unsigned int curld_cmp_clk_gt_en : 1 ;
        unsigned int curld_cmp_tag_en : 1 ;
        unsigned int curld_cmp_raw_en : 1 ;
        unsigned int flbc_lut_qp_delta : 2 ;
        unsigned int flbc_chroma_qp_offset_strength : 2 ;
        unsigned int reserved_0 : 5 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_RGB_CLIP;
typedef union {
    struct {
        unsigned int srcyh_stride : 16 ;
        unsigned int srcch_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_SRCH_STRIDE;
typedef union {
    struct {
        unsigned int chroma_weighing_qp0 : 10 ;
        unsigned int chroma_weighing_qp1 : 10 ;
        unsigned int chroma_weighing_qp2 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_0;
typedef union {
    struct {
        unsigned int chroma_weighing_qp3 : 10 ;
        unsigned int chroma_weighing_qp4 : 10 ;
        unsigned int chroma_weighing_qp5 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_1;
typedef union {
    struct {
        unsigned int chroma_weighing_qp6 : 10 ;
        unsigned int chroma_weighing_qp7 : 10 ;
        unsigned int chroma_weighing_qp8 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_2;
typedef union {
    struct {
        unsigned int chroma_weighing_qp9 : 10 ;
        unsigned int chroma_weighing_qp10 : 10 ;
        unsigned int chroma_weighing_qp11 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_3;
typedef union {
    struct {
        unsigned int chroma_weighing_qp12 : 10 ;
        unsigned int chroma_weighing_qp13 : 10 ;
        unsigned int chroma_weighing_qp14 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_4;
typedef union {
    struct {
        unsigned int chroma_weighing_qp15 : 10 ;
        unsigned int chroma_weighing_qp16 : 10 ;
        unsigned int chroma_weighing_qp17 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_5;
typedef union {
    struct {
        unsigned int chroma_weighing_qp18 : 10 ;
        unsigned int chroma_weighing_qp19 : 10 ;
        unsigned int chroma_weighing_qp20 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_6;
typedef union {
    struct {
        unsigned int chroma_weighing_qp21 : 10 ;
        unsigned int chroma_weighing_qp22 : 10 ;
        unsigned int chroma_weighing_qp23 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_7;
typedef union {
    struct {
        unsigned int chroma_weighing_qp24 : 10 ;
        unsigned int chroma_weighing_qp25 : 10 ;
        unsigned int chroma_weighing_qp26 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_8;
typedef union {
    struct {
        unsigned int chroma_weighing_qp27 : 10 ;
        unsigned int chroma_weighing_qp28 : 10 ;
        unsigned int chroma_weighing_qp29 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_9;
typedef union {
    struct {
        unsigned int chroma_weighing_qp30 : 10 ;
        unsigned int chroma_weighing_qp31 : 10 ;
        unsigned int chroma_weighing_qp32 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_10;
typedef union {
    struct {
        unsigned int chroma_weighing_qp33 : 10 ;
        unsigned int chroma_weighing_qp34 : 10 ;
        unsigned int chroma_weighing_qp35 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_11;
typedef union {
    struct {
        unsigned int chroma_weighing_qp36 : 10 ;
        unsigned int chroma_weighing_qp37 : 10 ;
        unsigned int chroma_weighing_qp38 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_12;
typedef union {
    struct {
        unsigned int chroma_weighing_qp39 : 10 ;
        unsigned int chroma_weighing_qp40 : 10 ;
        unsigned int chroma_weighing_qp41 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_13;
typedef union {
    struct {
        unsigned int chroma_weighing_qp42 : 10 ;
        unsigned int chroma_weighing_qp43 : 10 ;
        unsigned int chroma_weighing_qp44 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_14;
typedef union {
    struct {
        unsigned int chroma_weighing_qp45 : 10 ;
        unsigned int chroma_weighing_qp46 : 10 ;
        unsigned int chroma_weighing_qp47 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_15;
typedef union {
    struct {
        unsigned int chroma_weighing_qp48 : 10 ;
        unsigned int chroma_weighing_qp49 : 10 ;
        unsigned int chroma_weighing_qp50 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_16;
typedef union {
    struct {
        unsigned int chroma_weighing_qp51 : 10 ;
        unsigned int chroma_weighing_qp52 : 10 ;
        unsigned int chroma_weighing_qp53 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_17;
typedef union {
    struct {
        unsigned int chroma_weighing_qp54 : 10 ;
        unsigned int chroma_weighing_qp55 : 10 ;
        unsigned int chroma_weighing_qp56 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_18;
typedef union {
    struct {
        unsigned int chroma_weighing_qp57 : 10 ;
        unsigned int chroma_weighing_qp58 : 10 ;
        unsigned int chroma_weighing_qp59 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_19;
typedef union {
    struct {
        unsigned int chroma_weighing_qp60 : 10 ;
        unsigned int chroma_weighing_qp61 : 10 ;
        unsigned int chroma_weighing_qp62 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_20;
typedef union {
    struct {
        unsigned int chroma_weighing_qp63 : 10 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CHROMA_WEIGHTING_21;
typedef union {
    struct {
        unsigned int irq_position_cnt_y : 10 ;
        unsigned int reserved_0 : 7 ;
        unsigned int reserved_1 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_NEW_CFG0;
typedef union {
    struct {
        unsigned int vctrl_region0en : 1 ;
        unsigned int vctrl_region1en : 1 ;
        unsigned int vctrl_region2en : 1 ;
        unsigned int vctrl_region3en : 1 ;
        unsigned int vctrl_region4en : 1 ;
        unsigned int vctrl_region5en : 1 ;
        unsigned int vctrl_region6en : 1 ;
        unsigned int vctrl_region7en : 1 ;
        unsigned int vctrl_absqp0 : 1 ;
        unsigned int vctrl_absqp1 : 1 ;
        unsigned int vctrl_absqp2 : 1 ;
        unsigned int vctrl_absqp3 : 1 ;
        unsigned int vctrl_absqp4 : 1 ;
        unsigned int vctrl_absqp5 : 1 ;
        unsigned int vctrl_absqp6 : 1 ;
        unsigned int vctrl_absqp7 : 1 ;
        unsigned int vctrl_region0keep : 1 ;
        unsigned int vctrl_region1keep : 1 ;
        unsigned int vctrl_region2keep : 1 ;
        unsigned int vctrl_region3keep : 1 ;
        unsigned int vctrl_region4keep : 1 ;
        unsigned int vctrl_region5keep : 1 ;
        unsigned int vctrl_region6keep : 1 ;
        unsigned int vctrl_region7keep : 1 ;
        unsigned int vctrl_roi_en : 1 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_CFG0;
typedef union {
    struct {
        unsigned int vctrl_roiqp0 : 7 ;
        unsigned int reserved_0 : 1 ;
        unsigned int vctrl_roiqp1 : 7 ;
        unsigned int reserved_1 : 1 ;
        unsigned int vctrl_roiqp2 : 7 ;
        unsigned int reserved_2 : 1 ;
        unsigned int vctrl_roiqp3 : 7 ;
        unsigned int reserved_3 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_CFG1;
typedef union {
    struct {
        unsigned int vctrl_roiqp4 : 7 ;
        unsigned int reserved_0 : 1 ;
        unsigned int vctrl_roiqp5 : 7 ;
        unsigned int reserved_1 : 1 ;
        unsigned int vctrl_roiqp6 : 7 ;
        unsigned int reserved_2 : 1 ;
        unsigned int vctrl_roiqp7 : 7 ;
        unsigned int reserved_3 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_CFG2;
typedef union {
    struct {
        unsigned int vctrl_size0_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size0_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_0;
typedef union {
    struct {
        unsigned int vctrl_size1_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size1_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_1;
typedef union {
    struct {
        unsigned int vctrl_size2_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size2_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_2;
typedef union {
    struct {
        unsigned int vctrl_size3_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size3_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_3;
typedef union {
    struct {
        unsigned int vctrl_size4_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size4_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_4;
typedef union {
    struct {
        unsigned int vctrl_size5_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size5_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_5;
typedef union {
    struct {
        unsigned int vctrl_size6_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size6_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_6;
typedef union {
    struct {
        unsigned int vctrl_size7_roiwidth : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vctrl_size7_roiheight : 13 ;
        unsigned int reserved_1 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_SIZE_7;
typedef union {
    struct {
        unsigned int vctrl_start0_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start0_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_0;
typedef union {
    struct {
        unsigned int vctrl_start1_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start1_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_1;
typedef union {
    struct {
        unsigned int vctrl_start2_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start2_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_2;
typedef union {
    struct {
        unsigned int vctrl_start3_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start3_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_3;
typedef union {
    struct {
        unsigned int vctrl_start4_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start4_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_4;
typedef union {
    struct {
        unsigned int vctrl_start5_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start5_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_5;
typedef union {
    struct {
        unsigned int vctrl_start6_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start6_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_6;
typedef union {
    struct {
        unsigned int vctrl_start7_roistartx : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vctrl_start7_roistarty : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ROI_START_7;
typedef union {
    struct {
        unsigned int vcpi_spec_luma_thr_l : 16 ;
        unsigned int vcpi_spec_luma_thr_h : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_PMESTAT_SPEC_PIX_THR_Y;
typedef union {
    struct {
        unsigned int vcpi_spec_cb_thr_l : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int vcpi_spec_cb_thr_h : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_PMESTAT_SPEC_PIX_THR_CB;
typedef union {
    struct {
        unsigned int vcpi_spec_cr_thr_l : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int vcpi_spec_cr_thr_h : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_PMESTAT_SPEC_PIX_THR_CR;
typedef union {
    struct {
        unsigned int vcpi_imgwidth_pix : 16 ;
        unsigned int vcpi_imgheight_pix : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PICSIZE_PIX;
typedef union {
    struct {
        unsigned int vcpi_ref_idc : 2 ;
        unsigned int reserved_0 : 2 ;
        unsigned int vcpi_cabac_init_idc : 2 ;
        unsigned int reserved_1 : 6 ;
        unsigned int vcpi_byte_stuffing : 1 ;
        unsigned int reserved_2 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_VLC_CONFIG;
typedef union {
    struct {
        unsigned int vcpi_lowDelay_flag : 1 ;
        unsigned int vcpi_col_from_l0_flag : 1 ;
        unsigned int vcpi_curr_ref_long_flag : 2 ;
        unsigned int vcpi_col_long_flag : 2 ;
        unsigned int vcpi_predflag_sel : 2 ;
        unsigned int vcpi_col_frame_type : 2 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_FLAG;
typedef union {
    struct {
        unsigned int pmv_tmv_en : 1 ;
        unsigned int pmv_mv_statistic_multi_ref_en : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_PMV_TMV_EN;
typedef union {
    struct {
        unsigned int vcpi_tmv_wr_rd_avail : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_TMV_LOAD;
typedef union {
    struct {
        unsigned int reserved_0 : 8 ;
        unsigned int cabac_max_num_mergecand : 3 ;
        unsigned int reserved_1 : 5 ;
        unsigned int cabac_nal_unit_head : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CABAC_GLB_CFG;
typedef union {
    struct {
        unsigned int cabac_slchdr_size_part1 : 5 ;
        unsigned int reserved_0 : 11 ;
        unsigned int cabac_slchdr_size_part2 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CABAC_SLCHDR_SIZE;
typedef union {
    struct {
        unsigned int cabac_slchdr_part1 : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CABAC_SLCHDR_PART1;
typedef union {
    struct {
        unsigned int cabac_slchdr_size_part1_i : 5 ;
        unsigned int reserved_0 : 11 ;
        unsigned int cabac_slchdr_size_part2_i : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CABAC_SLCHDR_SIZE_I;
typedef union {
    struct {
        unsigned int cabac_slchdr_part1_i : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_CABAC_SLCHDR_PART1_I;
typedef union {
    struct {
        unsigned int vlc_markingbit : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int vlc_reorderbit : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int vlc_parabit : 7 ;
        unsigned int reserved_2 : 9 ;
    } bits;
    unsigned int u32;
} U_VEDU_VLC_SLCHDRPARA;
typedef union {
    struct {
        unsigned int vlc_svc_en : 1 ;
        unsigned int vlc_svc_strm : 24 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_VLC_SVC;
typedef union {
    struct {
        unsigned int vlc_markingbit_i : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int vlc_reorderbit_i : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int vlc_parabit_i : 7 ;
        unsigned int reserved_2 : 9 ;
    } bits;
    unsigned int u32;
} U_VEDU_VLC_SLCHDRPARA_I;
typedef union {
    struct {
        unsigned int vcfg_hebc_clkgate_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_REFLD_CMP_CLKGATE_EN;
typedef union {
    struct {
        unsigned int rpintra_lpw_pu4_thr : 12 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VEDU_RPINTRA_CFG;
typedef union {
    struct {
        unsigned int qpg_lowluma_min_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_lowluma_max_qp : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_lowluma_qp_delta : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_LOWLUMA;
typedef union {
    struct {
        unsigned int qpg_hedge_mim_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_hedge_max_qp : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_hedge_qp_delta : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_HEDGE;
typedef union {
    struct {
        unsigned int qpg_hedge_move_min_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_hedge_move_max_qp : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_hedge_move_qp_delta : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_HEDGE_MOVE;
typedef union {
    struct {
        unsigned int qpg_skin_min_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_skin_max_qp : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_skin_qp_delta : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_SKIN;
typedef union {
    struct {
        unsigned int qpg_intra_det_min_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_intra_det_max_qp : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_intra_det_qp_delta : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_INTRA_DET;
typedef union {
    struct {
        unsigned int qpg_cu32_delta_low : 4 ;
        unsigned int qpg_cu32_delta_high : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CU32_DELTA;
typedef union {
    struct {
        unsigned int qpg_lambda_qp_offset : 5 ;
        unsigned int reserved_0 : 3 ;
        unsigned int qpg_rdo_lambda_choose_mode : 2 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_lambda_inter_stredge_en : 1 ;
        unsigned int reserved_2 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_LAMBDA_MODE;
typedef union {
    struct {
        unsigned int qpg_qp_restrain_madi_thr : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_qp_restrain_en : 1 ;
        unsigned int qpg_qp_restrain_mode : 2 ;
        unsigned int reserved_1 : 1 ;
        unsigned int qpg_qp_restrain_delta_blk16 : 4 ;
        unsigned int qpg_qp_restrain_delta_blk32 : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_RESTRAIN;
typedef union {
    struct {
        unsigned int qpg_min_sad_level : 8 ;
        unsigned int reserved_0 : 8 ;
        unsigned int qpg_low_min_sad_mode : 2 ;
        unsigned int reserved_1 : 2 ;
        unsigned int qpg_min_sad_madi_en : 1 ;
        unsigned int qpg_min_sad_qp_restrain_en : 1 ;
        unsigned int reserved_2 : 10 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_CU_MIN_SAD_REG;
typedef union {
    struct {
        unsigned int qpg_flat_region_qp_delta : 4 ;
        unsigned int qpg_flat_region_max_qp : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int qpg_flat_region_min_qp : 6 ;
        unsigned int reserved_1 : 6 ;
        unsigned int vcpi_cu32_use_cu16_mean_en : 1 ;
        unsigned int reserved_2 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_FLAT_REGION;
typedef union {
    struct {
        unsigned int vcpi_res_coef_en : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vcpi_large_res_coef : 5 ;
        unsigned int reserved_1 : 3 ;
        unsigned int vcpi_small_res_coef : 5 ;
        unsigned int reserved_2 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_RES_COEF;
typedef union {
    struct {
        unsigned int vcpi_chroma_prot_en : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vcpi_chroma_max_qp : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int vcpi_chroma_in_qp : 6 ;
        unsigned int reserved_2 : 2 ;
        unsigned int vcpi_chroma_qp_delta : 4 ;
        unsigned int reserved_3 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_PROTECT;
typedef union {
    struct {
        unsigned int reserved_0 : 16 ;
        unsigned int pme_madi_dif_thr : 7 ;
        unsigned int pme_cur_madi_dif_thr : 7 ;
        unsigned int reserved_1 : 2 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_QPG_RC_THR0;
typedef union {
    struct {
        unsigned int pme_min_sad_thr_offset : 8 ;
        unsigned int pme_min_sad_thr_gain : 4 ;
        unsigned int reserved_0 : 8 ;
        unsigned int pme_min_sad_thr_offset_cur : 8 ;
        unsigned int pme_min_sad_thr_gain_cur : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_QPG_RC_THR1;
typedef union {
    struct {
        unsigned int pme_low_luma_thr : 8 ;
        unsigned int pme_low_luma_madi_thr : 8 ;
        unsigned int pme_high_luma_thr : 8 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_LOW_LUMA_THR;
typedef union {
    struct {
        unsigned int pme_flat_v_thr_high : 8 ;
        unsigned int pme_flat_v_thr_low : 8 ;
        unsigned int pme_flat_u_thr_high : 8 ;
        unsigned int pme_flat_u_thr_low : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_CHROMA_FLAT;
typedef union {
    struct {
        unsigned int pme_flat_pmemv_thr : 8 ;
        unsigned int pme_flat_luma_madi_thr : 8 ;
        unsigned int pme_flat_low_luma_thr : 8 ;
        unsigned int pme_flat_high_luma_thr : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_LUMA_FLAT;
typedef union {
    struct {
        unsigned int pme_flat_pmesad_thr : 14 ;
        unsigned int pme_flat_icount_thr : 9 ;
        unsigned int pme_flat_region_cnt : 5 ;
        unsigned int pme_flat_madi_times : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_MADI_FLAT;
typedef union {
    struct {
        unsigned int vlcst_idrind : 1 ;
        unsigned int reserved_0 : 15 ;
        unsigned int vlcst_chnid : 8 ;
        unsigned int reserved_1 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_VLCST_DESCRIPTOR;
typedef union {
    struct {
        unsigned int curld_clip_luma_min : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int curld_clip_luma_max : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_CLIP_LUMA;
typedef union {
    struct {
        unsigned int curld_clip_chroma_min : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int curld_clip_chroma_max : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_CURLD_CLIP_CHROMA;
typedef union {
    struct {
        unsigned int tqitq_deadzone_intra_slice : 8 ;
        unsigned int tqitq_deadzone_inter_slice : 8 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_TQITQ_DEADZONE;
typedef union {
    struct {
        unsigned int reserved_0 : 1 ;
        unsigned int vcpi_move_sad_en : 1 ;
        unsigned int reserved_1 : 14 ;
        unsigned int vcpi_pblk_pre_mvx_thr : 8 ;
        unsigned int vcpi_pblk_pre_mvy_thr : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PME_PARAM;
typedef union
{
    struct
    {
        unsigned int vcpi_skin_en : 1 ;
        unsigned int vcpi_strong_edge_en : 1 ;
        unsigned int vcpi_still_en : 1 ;
        unsigned int vcpi_skin_close_angle : 1 ;
        unsigned int vcpi_rounding_sobel_en : 1 ;
        unsigned int vcpi_pintra_structure_edge_thr : 18;
        unsigned int vcpi_pintra_structure_edge_qp_offset : 6;
        unsigned int reserved_0 : 3;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PIC_STRONG_EN;
typedef union {
    struct {
        unsigned int vcpi_pintra_pu16_amp_th : 8 ;
        unsigned int vcpi_pintra_pu32_amp_th : 8 ;
        unsigned int vcpi_pintra_pu64_amp_th : 8 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PINTRA_THRESH0;
typedef union {
    struct {
        unsigned int vcpi_pintra_pu16_std_th : 8 ;
        unsigned int vcpi_pintra_pu32_std_th : 8 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PINTRA_THRESH1;
typedef union {
    struct {
        unsigned int vcpi_pintra_pu16_angel_cost_th : 10 ;
        unsigned int vcpi_pintra_pu32_angel_cost_th : 10 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vcpi_rpintra_only_once : 1 ;
        unsigned int vcpi_rpintra_pu4_strong_edge_th : 3 ;
        unsigned int reserved_1 : 1 ;
        unsigned int vcpi_rpintra_pu4_mode_distance_th : 2 ;
        unsigned int vcpi_rpintra_bypass : 1 ;
        unsigned int reserved_2 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PINTRA_THRESH2;
typedef union {
    struct {
        unsigned int vcpi_intra32_low_power_thr : 16 ;
        unsigned int vcpi_intra32_low_power_en : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vcpi_intra32_low_power_gain : 6 ;
        unsigned int vcpi_intra32_low_power_offset : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INTRA32_LOW_POWER;
typedef union {
    struct {
        unsigned int vcpi_intra16_low_power_thr : 16 ;
        unsigned int vcpi_intra16_low_power_en : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vcpi_intra16_low_power_gain : 6 ;
        unsigned int vcpi_intra16_low_power_offset : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INTRA16_LOW_POWER;
typedef union {
    struct {
        unsigned int vcpi_intra_reduce_rdo_num_thr : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vcpi_intra_reduce_rdo_num_en : 1 ;
        unsigned int reserved_1 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INTRA_REDUCE_RDO_NUM;
typedef union {
    struct {
        unsigned int vcpi_bislayer0flag : 1 ;
        unsigned int vcpi_bnoforcezero_flag : 1 ;
        unsigned int vcpi_bnoforcezero_posx : 4 ;
        unsigned int vcpi_bnoforcezero_posy : 4 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_NOFORCEZERO;
typedef union {
    struct {
        unsigned int pme_skip_sad_thr_offset : 8 ;
        unsigned int pme_skip_sad_thr_gain : 4 ;
        unsigned int pme_skip_large_res_det : 1 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SKIP_LARGE_RES;
typedef union {
    struct {
        unsigned int vcpi_skin_sad_thr_offset : 8 ;
        unsigned int reserved_0 : 4 ;
        unsigned int vcpi_skin_sad_thr_gain : 4 ;
        unsigned int reserved_1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SKIN_SAD_THR;
typedef union {
    struct {
        unsigned int vctrl_ChosOthBlkSpecOffset : 4 ;
        unsigned int vctrl_ChosOthBlkOffset16 : 4 ;
        unsigned int vctrl_IChosCurBlkOffset16 : 4 ;
        unsigned int vctrl_LowFreqACBlk16 : 4 ;
        unsigned int vctrl_ChosOthBlkOffset32 : 4 ;
        unsigned int vctrl_IChosCurBlkOffset32 : 4 ;
        unsigned int vctrl_LowFreqACBlk32 : 4 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_NM_ACOFFSET_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_ChosOthBlkSpecThr : 4 ;
        unsigned int vctrl_ChosOthBlkEngThr : 4 ;
        unsigned int vctrl_ChosOthBlkThr3 : 6 ;
        unsigned int vctrl_ChosOthBlkThr2 : 6 ;
        unsigned int vctrl_ChosOthBlkThr : 5 ;
        unsigned int vctrl_RmAllHighACThr : 4 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_NM_ENGTHR_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_RingEngThr : 4 ;
        unsigned int vctrl_RingACThr : 4 ;
        unsigned int vctrl_PChosOthBlkOffset : 4 ;
        unsigned int vctrl_PChosOthBlkOffset8 : 4 ;
        unsigned int vctrl_IChosCurBlkOffset8 : 4 ;
        unsigned int vctrl_LowFreqACBlk8 : 3 ;
        unsigned int vctrl_Blk8EnableFlag : 1 ;
        unsigned int vctrl_ChosOthBlkOffsetSec16 : 4 ;
        unsigned int vctrl_ChosOthBlkOffsetSec32 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_NM_TU8_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_SkinChosOthBlkSpecOffset : 4 ;
        unsigned int vctrl_SkinChosOthBlkOffset16 : 4 ;
        unsigned int vctrl_SkinIChosCurBlkOffset16 : 4 ;
        unsigned int vctrl_SkinLowFreqACBlk16 : 4 ;
        unsigned int vctrl_SkinChosOthBlkOffset32 : 4 ;
        unsigned int vctrl_SkinIChosCurBlkOffset32 : 4 ;
        unsigned int vctrl_SkinLowFreqACBlk32 : 4 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SK_ACOFFSET_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_SkinChosOthBlkSpecThr : 4 ;
        unsigned int vctrl_SkinChosOthBlkEngThr : 4 ;
        unsigned int vctrl_SkinChosOthBlkThr3 : 6 ;
        unsigned int vctrl_SkinChosOthBlkThr2 : 6 ;
        unsigned int vctrl_SkinChosOthBlkThr : 5 ;
        unsigned int vctrl_SkinRmAllHighACThr : 4 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SK_ENGTHR_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_SkinRingEngThr : 4 ;
        unsigned int vctrl_SkinRingACThr : 4 ;
        unsigned int vctrl_SkinPChosOthBlkOffset : 4 ;
        unsigned int vctrl_SkinPChosOthBlkOffset8 : 4 ;
        unsigned int vctrl_SkinIChosCurBlkOffset8 : 4 ;
        unsigned int vctrl_SkinLowFreqACBlk8 : 3 ;
        unsigned int vctrl_SkinBlk8EnableFlag : 1 ;
        unsigned int vctrl_SkinChosOthBlkOffsetSec16 : 4 ;
        unsigned int vctrl_SkinChosOthBlkOffsetSec32 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SK_TU8_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_StillChosOthBlkSpecOffset : 4 ;
        unsigned int vctrl_StillChosOthBlkOffset16 : 4 ;
        unsigned int vctrl_StillIChosCurBlkOffset16 : 4 ;
        unsigned int vctrl_StillLowFreqACBlk16 : 4 ;
        unsigned int vctrl_StillChosOthBlkOffset32 : 4 ;
        unsigned int vctrl_StillIChosCurBlkOffset32 : 4 ;
        unsigned int vctrl_StillLowFreqACBlk32 : 4 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ST_ACOFFSET_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_StillChosOthBlkSpecThr : 4 ;
        unsigned int vctrl_StillChosOthBlkEngThr : 4 ;
        unsigned int vctrl_StillChosOthBlkThr3 : 6 ;
        unsigned int vctrl_StillChosOthBlkThr2 : 6 ;
        unsigned int vctrl_StillChosOthBlkThr : 5 ;
        unsigned int vctrl_StillRmAllHighACThr : 4 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ST_ENGTHR_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_StillRingEngThr : 4 ;
        unsigned int vctrl_StillRingACThr : 4 ;
        unsigned int vctrl_StillPChosOthBlkOffset : 4 ;
        unsigned int vctrl_StillPChosOthBlkOffset8 : 4 ;
        unsigned int vctrl_StillIChosCurBlkOffset8 : 4 ;
        unsigned int vctrl_StillLowFreqACBlk8 : 3 ;
        unsigned int vctrl_StillBlk8EnableFlag : 1 ;
        unsigned int vctrl_StillChosOthBlkOffsetSec16 : 4 ;
        unsigned int vctrl_StillChosOthBlkOffsetSec32 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_ST_TU8_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_EdgeChosOthBlkSpecOffset : 4 ;
        unsigned int vctrl_EdgeChosOthBlkOffset16 : 4 ;
        unsigned int vctrl_EdgeIChosCurBlkOffset16 : 4 ;
        unsigned int vctrl_EdgeLowFreqACBlk16 : 4 ;
        unsigned int vctrl_EdgeChosOthBlkOffset32 : 4 ;
        unsigned int vctrl_EdgeIChosCurBlkOffset32 : 4 ;
        unsigned int vctrl_EdgeLowFreqACBlk32 : 4 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SE_ACOFFSET_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_EdgeChosOthBlkSpecThr : 4 ;
        unsigned int vctrl_EdgeChosOthBlkEngThr : 4 ;
        unsigned int vctrl_EdgeChosOthBlkThr3 : 6 ;
        unsigned int vctrl_EdgeChosOthBlkThr2 : 6 ;
        unsigned int vctrl_EdgeChosOthBlkThr : 5 ;
        unsigned int vctrl_EdgeRmAllHighACThr : 4 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SE_ENGTHR_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_EdgeRingEngThr : 4 ;
        unsigned int vctrl_EdgeRingACThr : 4 ;
        unsigned int vctrl_EdgePChosOthBlkOffset : 4 ;
        unsigned int vctrl_EdgePChosOthBlkOffset8 : 4 ;
        unsigned int vctrl_EdgeIChosCurBlkOffset8 : 4 ;
        unsigned int vctrl_EdgeLowFreqACBlk8 : 3 ;
        unsigned int vctrl_EdgeBlk8EnableFlag : 1 ;
        unsigned int vctrl_EdgeChosOthBlkOffsetSec16 : 4 ;
        unsigned int vctrl_EdgeChosOthBlkOffsetSec32 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SE_TU8_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_EdgeAndMoveChosOthBlkSpecOffset : 4 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkOffset16 : 4 ;
        unsigned int vctrl_EdgeAndMoveIChosCurBlkOffset16 : 4 ;
        unsigned int vctrl_EdgeAndMoveLowFreqACBlk16 : 4 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkOffset32 : 4 ;
        unsigned int vctrl_EdgeAndMoveIChosCurBlkOffset32 : 4 ;
        unsigned int vctrl_EdgeAndMoveLowFreqACBlk32 : 4 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SELM_ACOFFSET_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_EdgeAndMoveChosOthBlkSpecThr : 4 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkEngThr : 4 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkThr3 : 6 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkThr2 : 6 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkThr : 5 ;
        unsigned int vctrl_EdgeAndMoveRmAllHighACThr : 4 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SELM_ENGTHR_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_EdgeAndMoveRingEngThr : 4 ;
        unsigned int vctrl_EdgeAndMoveRingACThr : 4 ;
        unsigned int vctrl_EdgeAndMovePChosOthBlkOffset : 4 ;
        unsigned int vctrl_EdgeAndMovePChosOthBlkOffset8 : 4 ;
        unsigned int vctrl_EdgeAndMoveIChosCurBlkOffset8 : 4 ;
        unsigned int vctrl_EdgeAndMoveLowFreqACBlk8 : 3 ;
        unsigned int vctrl_EdgeAndMoveBlk8EnableFlag : 1 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkOffsetSec16 : 4 ;
        unsigned int vctrl_EdgeAndMoveChosOthBlkOffsetSec32 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SELM_TU8_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_WeakChosOthBlkSpecOffset : 4 ;
        unsigned int vctrl_WeakChosOthBlkOffset16 : 4 ;
        unsigned int vctrl_WeakIChosCurBlkOffset16 : 4 ;
        unsigned int vctrl_WeakLowFreqACBlk16 : 4 ;
        unsigned int vctrl_WeakChosOthBlkOffset32 : 4 ;
        unsigned int vctrl_WeakIChosCurBlkOffset32 : 4 ;
        unsigned int vctrl_WeakLowFreqACBlk32 : 4 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_WS_ACOFFSET_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_WeakChosOthBlkSpecThr : 4 ;
        unsigned int vctrl_WeakChosOthBlkEngThr : 4 ;
        unsigned int vctrl_WeakChosOthBlkThr3 : 6 ;
        unsigned int vctrl_WeakChosOthBlkThr2 : 6 ;
        unsigned int vctrl_WeakChosOthBlkThr : 5 ;
        unsigned int vctrl_WeakRmAllHighACThr : 4 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_WS_ENGTHR_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_WeakRingEngThr : 4 ;
        unsigned int vctrl_WeakRingACThr : 4 ;
        unsigned int vctrl_WeakPChosOthBlkOffset : 4 ;
        unsigned int vctrl_WeakPChosOthBlkOffset8 : 4 ;
        unsigned int vctrl_WeakIChosCurBlkOffset8 : 4 ;
        unsigned int vctrl_WeakLowFreqACBlk8 : 3 ;
        unsigned int vctrl_WeakBlk8EnableFlag : 1 ;
        unsigned int vctrl_WeakChosOthBlkOffsetSec16 : 4 ;
        unsigned int vctrl_WeakChosOthBlkOffsetSec32 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_WS_TU8_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_StrongChosOthBlkSpecOffset : 4 ;
        unsigned int vctrl_StrongChosOthBlkOffset16 : 4 ;
        unsigned int vctrl_StrongIChosCurBlkOffset16 : 4 ;
        unsigned int vctrl_StrongLowFreqACBlk16 : 4 ;
        unsigned int vctrl_StrongChosOthBlkOffset32 : 4 ;
        unsigned int vctrl_StrongIChosCurBlkOffset32 : 4 ;
        unsigned int vctrl_StrongLowFreqACBlk32 : 4 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SSSE_ACOFFSET_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_StrongChosOthBlkSpecThr : 4 ;
        unsigned int vctrl_StrongChosOthBlkEngThr : 4 ;
        unsigned int vctrl_StrongChosOthBlkThr3 : 6 ;
        unsigned int vctrl_StrongChosOthBlkThr2 : 6 ;
        unsigned int vctrl_StrongChosOthBlkThr : 5 ;
        unsigned int vctrl_StrongRmAllHighACThr : 4 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SSSE_ENGTHR_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_StrongRingEngThr : 4 ;
        unsigned int vctrl_StrongRingACThr : 4 ;
        unsigned int vctrl_StrongPChosOthBlkOffset : 4 ;
        unsigned int vctrl_StrongPChosOthBlkOffset8 : 4 ;
        unsigned int vctrl_StrongIChosCurBlkOffset8 : 4 ;
        unsigned int vctrl_StrongLowFreqACBlk8 : 3 ;
        unsigned int vctrl_StrongBlk8EnableFlag : 1 ;
        unsigned int vctrl_StrongChosOthBlkOffsetSec16 : 4 ;
        unsigned int vctrl_StrongChosOthBlkOffsetSec32 : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_SSSE_TU8_DENOISE;
typedef union {
    struct {
        unsigned int vctrl_norm_intra_cu4_rdcost_offset : 4 ;
        unsigned int vctrl_norm_intra_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_norm_intra_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_norm_intra_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_intra_cu4_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_intra_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_intra_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_intra_cu32_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_INTRA_RDO_FACTOR_0;
typedef union {
    struct {
        unsigned int vctrl_skin_intra_cu4_rdcost_offset : 4 ;
        unsigned int vctrl_skin_intra_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_skin_intra_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_skin_intra_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_intra_cu4_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_intra_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_intra_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_intra_cu32_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_INTRA_RDO_FACTOR_1;
typedef union {
    struct {
        unsigned int vctrl_hedge_intra_cu4_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_intra_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_intra_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_intra_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_intra_cu4_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_intra_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_intra_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_intra_cu32_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_INTRA_RDO_FACTOR_2;
typedef union {
    struct {
        unsigned int vctrl_norm_mrg_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_norm_mrg_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_norm_mrg_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_norm_mrg_cu64_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_mrg_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_mrg_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_mrg_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_mrg_cu64_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_MRG_RDO_FACTOR_0;
typedef union {
    struct {
        unsigned int vctrl_skin_mrg_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_skin_mrg_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_skin_mrg_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_skin_mrg_cu64_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_mrg_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_mrg_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_mrg_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_mrg_cu64_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_MRG_RDO_FACTOR_1;
typedef union {
    struct {
        unsigned int vctrl_hedge_mrg_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_mrg_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_mrg_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_mrg_cu64_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_mrg_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_mrg_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_mrg_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_mrg_cu64_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_MRG_RDO_FACTOR_2;
typedef union {
    struct {
        unsigned int vctrl_norm_fme_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_norm_fme_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_norm_fme_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_norm_fme_cu64_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_fme_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_fme_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_fme_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_strmov_fme_cu64_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_FME_RDO_FACTOR_0;
typedef union {
    struct {
        unsigned int vctrl_skin_fme_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_skin_fme_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_skin_fme_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_skin_fme_cu64_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_fme_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_fme_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_fme_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_str_fme_cu64_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_FME_RDO_FACTOR_1;
typedef union {
    struct {
        unsigned int vctrl_hedge_fme_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_fme_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_fme_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_hedge_fme_cu64_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_fme_cu8_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_fme_cu16_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_fme_cu32_rdcost_offset : 4 ;
        unsigned int vctrl_sobel_tex_fme_cu64_rdcost_offset : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_FME_RDO_FACTOR_2;
typedef union {
    struct {
        unsigned int pme_cost_lamda0 : 4 ;
        unsigned int pme_cost_lamda1 : 4 ;
        unsigned int pme_cost_lamda2 : 4 ;
        unsigned int pme_new_cost_en : 2 ;
        unsigned int reserved_0 : 2 ;
        unsigned int pme_cost_lamda_en : 2 ;
        unsigned int pme_mvp3median_en : 1 ;
        unsigned int reserved_1 : 13 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_NEW_COST;
typedef union {
    struct {
        unsigned int pme_l0_cost_offset : 16 ;
        unsigned int pme_l1_cost_offset : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_COST_OFFSET;
typedef union {
    struct {
        unsigned int pme_intrablk_det_cost_thr0 : 16 ;
        unsigned int pme_pskip_mvy_consistency_thr : 8 ;
        unsigned int pme_pskip_mvx_consistency_thr : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_INTRABLK_DET;
typedef union {
    struct {
        unsigned int pme_intrablk_det_mv_dif_thr1 : 8 ;
        unsigned int pme_intrablk_det_mv_dif_thr0 : 8 ;
        unsigned int pme_intrablk_det_mvy_thr : 8 ;
        unsigned int pme_intrablk_det_mvx_thr : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_INTRABLK_DET_THR;
typedef union {
    struct {
        unsigned int pme_skin_u_max_thr : 8 ;
        unsigned int pme_skin_u_min_thr : 8 ;
        unsigned int pme_skin_v_max_thr : 8 ;
        unsigned int pme_skin_v_min_thr : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SKIN_THR;
typedef union {
    struct {
        unsigned int pme_skin_num : 9 ;
        unsigned int pme_strong_edge_thr : 8 ;
        unsigned int pme_strong_edge_cnt : 5 ;
        unsigned int pme_still_scene_thr : 9 ;
        unsigned int reserved_0 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_STRONG_EDGE;
typedef union {
    struct {
        unsigned int pme_move_scene_thr : 8 ;
        unsigned int pme_move_sad_thr : 14 ;
        unsigned int reserved_0 : 10 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_LARGE_MOVE_THR;
typedef union {
    struct {
        unsigned int pme_interdiff_max_min_madi_abs : 8 ;
        unsigned int pme_interdiff_max_min_madi_times : 8 ;
        unsigned int pme_interstrongedge_madi_thr : 8 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_INTER_STRONG_EDGE;
typedef union {
    struct {
        unsigned int vcpi_strong_edge_thr_u : 8 ;
        unsigned int reserved_0 : 2 ;
        unsigned int vcpi_strong_edge_cnt_u : 5 ;
        unsigned int reserved_1 : 1 ;
        unsigned int vcpi_strong_edge_thr_v : 8 ;
        unsigned int reserved_2 : 2 ;
        unsigned int vcpi_strong_edge_cnt_v : 5 ;
        unsigned int reserved_3 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_CHROMA_STRONG_EDGE;
typedef union {
    struct {
        unsigned int vcpi_chroma_sad_thr_offset : 8 ;
        unsigned int vcpi_chroma_sad_thr_gain : 4 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_SAD_THR;
typedef union {
    struct {
        unsigned int vcpi_chroma_u0_thr_min : 8 ;
        unsigned int vcpi_chroma_u0_thr_max : 8 ;
        unsigned int vcpi_chroma_v0_thr_min : 8 ;
        unsigned int vcpi_chroma_v0_thr_max : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_FG_THR;
typedef union {
    struct {
        unsigned int vcpi_chroma_u1_thr_min : 8 ;
        unsigned int vcpi_chroma_u1_thr_max : 8 ;
        unsigned int vcpi_chroma_v1_thr_min : 8 ;
        unsigned int vcpi_chroma_v1_thr_max : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_BG_THR;
typedef union {
    struct {
        unsigned int vcpi_chroma_uv0_thr_min : 9 ;
        unsigned int reserved_0 : 7 ;
        unsigned int vcpi_chroma_uv0_thr_max : 9 ;
        unsigned int reserved_1 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_SUM_FG_THR;
typedef union {
    struct {
        unsigned int vcpi_chroma_uv1_thr_min : 9 ;
        unsigned int reserved_0 : 7 ;
        unsigned int vcpi_chroma_uv1_thr_max : 9 ;
        unsigned int reserved_1 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_SUM_BG_THR;
typedef union {
    struct {
        unsigned int vcpi_chroma_count0_thr_min : 9 ;
        unsigned int reserved_0 : 7 ;
        unsigned int vcpi_chroma_count0_thr_max : 9 ;
        unsigned int reserved_1 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_FG_COUNT_THR;
typedef union {
    struct {
        unsigned int vcpi_chroma_count1_thr_min : 9 ;
        unsigned int reserved_0 : 7 ;
        unsigned int vcpi_chroma_count1_thr_max : 9 ;
        unsigned int reserved_1 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_CHROMA_BG_COUNT_THR;
typedef union {
    struct {
        unsigned int vcpi_move_scene_mv_thr : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int vcpi_move_scene_mv_en : 1 ;
        unsigned int reserved_1 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_MOVE_SCENE_THR;
typedef union {
    struct {
        unsigned int vcpi_new_madi_th0 : 8 ;
        unsigned int vcpi_new_madi_th1 : 8 ;
        unsigned int vcpi_new_madi_th2 : 8 ;
        unsigned int vcpi_new_madi_th3 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_NEW_MADI_TH;
typedef union {
    struct {
        unsigned int vcpi_new_lambda : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_NEW_LAMBDA;
typedef union {
    struct {
        unsigned int vcpi_dblk_beta : 4 ;
        unsigned int vcpi_dblk_alpha : 4 ;
        unsigned int vcpi_dblk_filter_flag : 2 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_DBLKCFG;
typedef union {
    struct {
        unsigned int fme_pu8_bias_cost : 16 ;
        unsigned int fme_pu16_bias_cost : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_FME_BIAS_COST0;
typedef union {
    struct {
        unsigned int fme_pu32_bias_cost : 16 ;
        unsigned int fme_pu64_bias_cost : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_FME_BIAS_COST1;
typedef union {
    struct {
        unsigned int mrg_pu8_bias_cost : 16 ;
        unsigned int mrg_pu16_bias_cost : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_MRG_BIAS_COST0;
typedef union {
    struct {
        unsigned int mrg_pu32_bias_cost : 16 ;
        unsigned int mrg_pu64_bias_cost : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_MRG_BIAS_COST1;
typedef union {
    struct {
        unsigned int mrg_pu8_abs_offset : 16 ;
        unsigned int mrg_pu16_abs_offset : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_MRG_ABS_OFFSET0;
typedef union {
    struct {
        unsigned int mrg_pu32_abs_offset : 16 ;
        unsigned int mrg_pu64_abs_offset : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_MRG_ABS_OFFSET1;
typedef union {
    struct {
        unsigned int cu8_fz_weight : 4 ;
        unsigned int cu16_fz_weight : 4 ;
        unsigned int cu32_fz_weight : 4 ;
        unsigned int cu64_fz_weight : 4 ;
        unsigned int cu8_fz_adapt_weight : 4 ;
        unsigned int cu16_fz_adapt_weight : 4 ;
        unsigned int cu32_fz_adapt_weight : 4 ;
        unsigned int cu64_fz_adapt_weight : 4 ;
    } bits;
    unsigned int u32;
} U_VEDU_MRG_ADJ_WEIGHT;
typedef union {
    struct {
        unsigned int intra_bit_weight : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_BIT_WEIGHT;
typedef union {
    struct {
        unsigned int intra_cu16_rdo_cost_offset : 16 ;
        unsigned int intra_cu32_rdo_cost_offset : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_RDO_COST_OFFSET_0;
typedef union {
    struct {
        unsigned int intra_cu4_rdo_cost_offset : 16 ;
        unsigned int intra_cu8_rdo_cost_offset : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_RDO_COST_OFFSET_1;
typedef union {
    struct {
        unsigned int intra_cu16_non_dc_mode_offset : 16 ;
        unsigned int intra_cu32_non_dc_mode_offset : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_NO_DC_COST_OFFSET_0;
typedef union {
    struct {
        unsigned int intra_cu4_non_dc_mode_offset : 16 ;
        unsigned int intra_cu8_non_dc_mode_offset : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_NO_DC_COST_OFFSET_1;
typedef union {
    struct {
        unsigned int intra_h264_rdo_cost_offset : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_RDO_COST_OFFSET_3;
typedef union {
    struct {
        unsigned int sel_offset_strength : 3 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_SEL_OFFSET_STRENGTH;
typedef union {
    struct {
        unsigned int qpg_lambda00 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG00;
typedef union {
    struct {
        unsigned int qpg_lambda01 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG01;
typedef union {
    struct {
        unsigned int qpg_lambda02 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG02;
typedef union {
    struct {
        unsigned int qpg_lambda03 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG03;
typedef union {
    struct {
        unsigned int qpg_lambda04 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG04;
typedef union {
    struct {
        unsigned int qpg_lambda05 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG05;
typedef union {
    struct {
        unsigned int qpg_lambda06 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG06;
typedef union {
    struct {
        unsigned int qpg_lambda07 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG07;
typedef union {
    struct {
        unsigned int qpg_lambda08 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG08;
typedef union {
    struct {
        unsigned int qpg_lambda09 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG09;
typedef union {
    struct {
        unsigned int qpg_lambda10 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG10;
typedef union {
    struct {
        unsigned int qpg_lambda11 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG11;
typedef union {
    struct {
        unsigned int qpg_lambda12 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG12;
typedef union {
    struct {
        unsigned int qpg_lambda13 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG13;
typedef union {
    struct {
        unsigned int qpg_lambda14 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG14;
typedef union {
    struct {
        unsigned int qpg_lambda15 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG15;
typedef union {
    struct {
        unsigned int qpg_lambda16 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG16;
typedef union {
    struct {
        unsigned int qpg_lambda17 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG17;
typedef union {
    struct {
        unsigned int qpg_lambda18 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG18;
typedef union {
    struct {
        unsigned int qpg_lambda19 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG19;
typedef union {
    struct {
        unsigned int qpg_lambda20 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG20;
typedef union {
    struct {
        unsigned int qpg_lambda21 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG21;
typedef union {
    struct {
        unsigned int qpg_lambda22 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG22;
typedef union {
    struct {
        unsigned int qpg_lambda23 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG23;
typedef union {
    struct {
        unsigned int qpg_lambda24 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG24;
typedef union {
    struct {
        unsigned int qpg_lambda25 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG25;
typedef union {
    struct {
        unsigned int qpg_lambda26 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG26;
typedef union {
    struct {
        unsigned int qpg_lambda27 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG27;
typedef union {
    struct {
        unsigned int qpg_lambda28 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG28;
typedef union {
    struct {
        unsigned int qpg_lambda29 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG29;
typedef union {
    struct {
        unsigned int qpg_lambda30 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG30;
typedef union {
    struct {
        unsigned int qpg_lambda31 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG31;
typedef union {
    struct {
        unsigned int qpg_lambda32 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG32;
typedef union {
    struct {
        unsigned int qpg_lambda33 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG33;
typedef union {
    struct {
        unsigned int qpg_lambda34 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG34;
typedef union {
    struct {
        unsigned int qpg_lambda35 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG35;
typedef union {
    struct {
        unsigned int qpg_lambda36 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG36;
typedef union {
    struct {
        unsigned int qpg_lambda37 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG37;
typedef union {
    struct {
        unsigned int qpg_lambda38 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG38;
typedef union {
    struct {
        unsigned int qpg_lambda39 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG39;
typedef union {
    struct {
        unsigned int qpg_lambda40 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG40;
typedef union {
    struct {
        unsigned int qpg_lambda41 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG41;
typedef union {
    struct {
        unsigned int qpg_lambda42 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG42;
typedef union {
    struct {
        unsigned int qpg_lambda43 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG43;
typedef union {
    struct {
        unsigned int qpg_lambda44 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG44;
typedef union {
    struct {
        unsigned int qpg_lambda45 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG45;
typedef union {
    struct {
        unsigned int qpg_lambda46 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG46;
typedef union {
    struct {
        unsigned int qpg_lambda47 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG47;
typedef union {
    struct {
        unsigned int qpg_lambda48 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG48;
typedef union {
    struct {
        unsigned int qpg_lambda49 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG49;
typedef union {
    struct {
        unsigned int qpg_lambda50 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG50;
typedef union {
    struct {
        unsigned int qpg_lambda51 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG51;
typedef union {
    struct {
        unsigned int qpg_lambda52 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG52;
typedef union {
    struct {
        unsigned int qpg_lambda53 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG53;
typedef union {
    struct {
        unsigned int qpg_lambda54 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG54;
typedef union {
    struct {
        unsigned int qpg_lambda55 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG55;
typedef union {
    struct {
        unsigned int qpg_lambda56 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG56;
typedef union {
    struct {
        unsigned int qpg_lambda57 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG57;
typedef union {
    struct {
        unsigned int qpg_lambda58 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG58;
typedef union {
    struct {
        unsigned int qpg_lambda59 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG59;
typedef union {
    struct {
        unsigned int qpg_lambda60 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG60;
typedef union {
    struct {
        unsigned int qpg_lambda61 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG61;
typedef union {
    struct {
        unsigned int qpg_lambda62 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG62;
typedef union {
    struct {
        unsigned int qpg_lambda63 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG63;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda00 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG64;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda01 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG65;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda02 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG66;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda03 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG67;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda04 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG68;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda05 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG69;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda06 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG70;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda07 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG71;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda08 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG72;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda09 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG73;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda10 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG74;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda11 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG75;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda12 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG76;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda13 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG77;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda14 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG78;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda15 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG79;
typedef union {
    struct {
        unsigned int ime_lambdaoff8 : 16 ;
        unsigned int ime_lambdaoff16 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_RDOCFG;
typedef union {
    struct {
        unsigned int mrg_force_zero_en : 1 ;
        unsigned int mrg_force_y_zero_en : 1 ;
        unsigned int mrg_force_u_zero_en : 1 ;
        unsigned int mrg_force_v_zero_en : 1 ;
        unsigned int fme_rdo_lpw_en : 1 ;
        unsigned int dct4_en : 1 ;
        unsigned int force_adapt_en : 1 ;
        unsigned int reserved_0 : 5 ;
        unsigned int rqt_bias_weight : 4 ;
        unsigned int fme_rdo_lpw_th : 10 ;
        unsigned int mrg_skip_weight_en : 1 ;
        unsigned int reserved_1 : 5 ;
    } bits;
    unsigned int u32;
} U_VEDU_MRG_FORCE_ZERO_EN;
typedef union {
    struct {
        unsigned int vcpi_intra_lowpow_en : 1 ;
        unsigned int vcpi_fme_lowpow_en : 1 ;
        unsigned int vcpi_ime_lowpow_en : 1 ;
        unsigned int powerpro_func_bypass : 1 ;
        unsigned int vcpi_ddr_cross_idx : 11 ;
        unsigned int reserved_0 : 1 ;
        unsigned int vcpi_tqitq_gtck_en : 1 ;
        unsigned int vcpi_mrg_gtck_en : 1 ;
        unsigned int vcpi_recst_hebc_clkgate_en : 1 ;
        unsigned int vcpi_clkgate_en : 2 ;
        unsigned int vcpi_mem_clkgate_en : 1 ;
        unsigned int venc_dpm_apb_clk_en : 1 ;
        unsigned int vcpi_ddr_cross_en : 1 ;
        unsigned int vcpi_osd_clkgete_en : 1 ;
        unsigned int vcpi_ghdr_clkgate_en : 1 ;
        unsigned int vcpi_curld_dcmp_clkgate_en : 1 ;
        unsigned int vcpi_refld_dcmp_clkgate_en : 1 ;
        unsigned int vcpi_cpi_clkgate_en : 1 ;
        unsigned int vcpi_vlc_clkgate_en : 1 ;
        unsigned int venc_axi_dfx_clk_en : 1 ;
        unsigned int venc_apb_cfg_force_clk_on : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_LOW_POWER;
typedef union {
    struct {
        unsigned int ime_layer3to2_en : 1 ;
        unsigned int ime_inter8x8_en : 1 ;
        unsigned int ime_flat_region_force_low3layer : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int ime_high3pre_en : 2 ;
        unsigned int reserved_1 : 2 ;
        unsigned int ime_intra4_lowpow_en : 1 ;
        unsigned int tile_boundry_improve_en : 1 ;
        unsigned int vcpi_ime_center_candi_en : 1 ;
        unsigned int vcpi_ime_with_pme_candi_en : 1 ;
        unsigned int reserved_2 : 20 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_INTER_MODE;
typedef union {
    struct {
        unsigned int reserved_0 : 1 ;
        unsigned int vcpi_pblk_pre_en : 1 ;
        unsigned int vcpi_force_inter : 1 ;
        unsigned int vcpi_pintra_inter_flag_disable : 1 ;
        unsigned int vcpi_ext_edge_en : 1 ;
        unsigned int reserved_1 : 27 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PRE_JUDGE_EXT_EN;
typedef union {
    struct {
        unsigned int pme_l0_psw_adapt_en : 1 ;
        unsigned int pme_l1_psw_adapt_en : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SW_ADAPT_EN;
typedef union {
    struct {
        unsigned int pme_l0_win0_width : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int pme_l0_win0_height : 9 ;
        unsigned int reserved_1 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_WINDOW_SIZE0_L0;
typedef union {
    struct {
        unsigned int pme_skipblk_pre_cost_thr : 16 ;
        unsigned int pme_skipblk_pre_en : 1 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SKIP_PRE;
typedef union {
    struct {
        unsigned int pme_pblk_pre_mv_dif_thr1 : 8 ;
        unsigned int pme_pblk_pre_mv_dif_thr0 : 8 ;
        unsigned int pme_pblk_pre_mv_dif_cost_thr : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_PBLK_PRE1;
typedef union {
    struct {
        unsigned int vcpi_iblk_pre_cost_thr : 16 ;
        unsigned int vcpi_pblk_pre_cost_thr : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PRE_JUDGE_COST_THR;
typedef union {
    struct {
        unsigned int vcpi_iblk_pre_mv_dif_thr0 : 8 ;
        unsigned int vcpi_iblk_pre_mv_dif_thr1 : 8 ;
        unsigned int vcpi_iblk_pre_mvx_thr : 8 ;
        unsigned int vcpi_iblk_pre_mvy_thr : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_IBLK_PRE_MV_THR;
typedef union {
    struct {
        unsigned int pme_iblk_pre_cost_thr_h264 : 16 ;
        unsigned int pme_intrablk_det_cost_thr1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_IBLK_COST_THR;
typedef union {
    struct {
        unsigned int pme_tr_weightx_0 : 9 ;
        unsigned int pme_tr_weightx_1 : 9 ;
        unsigned int pme_tr_weightx_2 : 9 ;
        unsigned int reserved_0 : 5 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_TR_WEIGHTX;
typedef union {
    struct {
        unsigned int pme_tr_weighty_0 : 8 ;
        unsigned int pme_tr_weighty_1 : 8 ;
        unsigned int pme_tr_weighty_2 : 8 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_TR_WEIGHTY;
typedef union {
    struct {
        unsigned int pme_sr_weight_0 : 4 ;
        unsigned int pme_sr_weight_1 : 4 ;
        unsigned int pme_sr_weight_2 : 4 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SR_WEIGHT;
typedef union {
    struct {
        unsigned int pme_intra16_madi_thr : 8 ;
        unsigned int pme_intra32_madi_thr : 8 ;
        unsigned int pme_intra_lowpow_en : 1 ;
        unsigned int pme_inter_first : 1 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_INTRA_LOWPOW;
typedef union {
    struct {
        unsigned int ime_lowpow_fme_thr0 : 6 ;
        unsigned int ime_lowpow_fme_thr1 : 6 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_FME_LPOW_THR;
typedef union {
    struct {
        unsigned int vcpi_pskip_strongedge_madi_thr : 8 ;
        unsigned int vcpi_pskip_strongedge_madi_times : 8 ;
        unsigned int vcpi_pskip_flatregion_madi_thr : 8 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_SKIP_FLAG;
typedef union {
    struct {
        unsigned int pme_psw_lp_diff_thy : 4 ;
        unsigned int reserved_0 : 4 ;
        unsigned int pme_psw_lp_diff_thx : 4 ;
        unsigned int reserved_1 : 20 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_PSW_LPW;
typedef union {
    struct {
        unsigned int pme_pblk_pre_madi_times : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_PME_PBLK_PRE2;
typedef union {
    struct {
        unsigned int ime_layer3to2_thr0 : 10 ;
        unsigned int reserved_0 : 6 ;
        unsigned int ime_layer3to2_thr1 : 10 ;
        unsigned int reserved_1 : 6 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_LAYER3TO2_THR;
typedef union {
    struct {
        unsigned int ime_layer3to2_cost_diff_thr : 10 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_LAYER3TO2_THR1;
typedef union {
    struct {
        unsigned int ime_layer3to1_en : 1 ;
        unsigned int reserved_0 : 7 ;
        unsigned int ime_layer3to1_pu64_madi_thr : 7 ;
        unsigned int reserved_1 : 17 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_LAYER3TO1_THR;
typedef union {
    struct {
        unsigned int ime_layer3to1_pu32_cost_thr : 16 ;
        unsigned int ime_layer3to1_pu64_cost_thr : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_LAYER3TO1_THR1;
typedef union {
    struct {
        unsigned int fme_pu64_lwp_flag : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_FME_PU64_LWP;
typedef union {
    struct {
        unsigned int inter32_use_tu16_en : 1 ;
        unsigned int mrg_not_use_sad_en : 1 ;
        unsigned int mrg_pu32_no_sad_pk_en : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int mrg_force_skip_en : 1 ;
        unsigned int mrg_not_use_sad_th : 18 ;
        unsigned int reserved_1 : 9 ;
    } bits;
    unsigned int u32;
} U_VEDU_MRG_FORCE_SKIP_EN;
typedef union {
    struct {
        unsigned int constrained_intra_pred_flag : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int intra_smooth : 1 ;
        unsigned int reserved_1 : 3 ;
        unsigned int vcpi_force_cu16_low_pow : 1 ;
        unsigned int reserved_2 : 3 ;
        unsigned int vcpi_force_cu32_low_pow : 1 ;
        unsigned int reserved_3 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_CFG;
typedef union {
    struct {
        unsigned int cu16_weak_ang_thr : 4 ;
        unsigned int cu16_medium_ang_thr : 4 ;
        unsigned int cu16_strong_ang_thr : 4 ;
        unsigned int cu16_rdo_num : 3 ;
        unsigned int cu16_adaptive_reduce_rdo_en : 1 ;
        unsigned int cu32_weak_ang_thr : 4 ;
        unsigned int cu32_medium_ang_thr : 4 ;
        unsigned int cu32_strong_ang_thr : 4 ;
        unsigned int cu32_rdo_num : 3 ;
        unsigned int cu32_adaptive_reduce_rdo_en : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_INTRA_LOW_POW;
typedef union {
    struct {
        unsigned int vcpi_inforld_mv_confidence_stride : 16 ;
        unsigned int vcpi_inforld_mv_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INFORLD_MV_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_inforld_last_feature_detect_stride : 16 ;
        unsigned int vcpi_inforld_feature_detect_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_INFORLD_FEATURE_DETECT_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp1 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT0;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp3 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp2 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT1;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp5 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp4 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT2;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp7 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp6 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT3;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp9 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp8 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT4;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp11 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp10 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT5;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp13 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp12 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT6;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp15 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp14 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT7;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp17 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp16 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT8;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp19 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp18 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT9;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp21 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp20 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT10;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp23 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp22 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT11;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp25 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp24 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT12;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp27 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp26 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT13;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp29 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp28 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT14;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp31 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp30 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT15;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp33 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp32 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT16;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp35 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp34 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT17;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp37 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp36 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT18;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp39 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp38 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT19;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp41 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp40 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT20;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp43 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp42 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT21;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp45 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp44 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT22;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp47 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp46 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT23;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp49 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp48 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT24;
typedef union {
    struct {
        unsigned int vcpi_srdo_max_weight_qp51 : 16 ;
        unsigned int vcpi_srdo_max_weight_qp50 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MAX_WEIGHT25;
typedef union {
    struct {
        unsigned int sao_area0_start_lcux : 16 ;
        unsigned int sao_area0_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA0_START;
typedef union {
    struct {
        unsigned int sao_area0_end_lcux : 16 ;
        unsigned int sao_area0_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA0_END;
typedef union {
    struct {
        unsigned int sao_area1_start_lcux : 16 ;
        unsigned int sao_area1_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA1_START;
typedef union {
    struct {
        unsigned int sao_area1_end_lcux : 16 ;
        unsigned int sao_area1_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA1_END;
typedef union {
    struct {
        unsigned int sao_area2_start_lcux : 16 ;
        unsigned int sao_area2_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA2_START;
typedef union {
    struct {
        unsigned int sao_area2_end_lcux : 16 ;
        unsigned int sao_area2_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA2_END;
typedef union {
    struct {
        unsigned int sao_area3_start_lcux : 16 ;
        unsigned int sao_area3_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA3_START;
typedef union {
    struct {
        unsigned int sao_area3_end_lcux : 16 ;
        unsigned int sao_area3_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA3_END;
typedef union {
    struct {
        unsigned int sao_area4_start_lcux : 16 ;
        unsigned int sao_area4_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA4_START;
typedef union {
    struct {
        unsigned int sao_area4_end_lcux : 16 ;
        unsigned int sao_area4_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA4_END;
typedef union {
    struct {
        unsigned int sao_area5_start_lcux : 16 ;
        unsigned int sao_area5_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA5_START;
typedef union {
    struct {
        unsigned int sao_area5_end_lcux : 16 ;
        unsigned int sao_area5_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA5_END;
typedef union {
    struct {
        unsigned int sao_area6_start_lcux : 16 ;
        unsigned int sao_area6_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA6_START;
typedef union {
    struct {
        unsigned int sao_area6_end_lcux : 16 ;
        unsigned int sao_area6_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA6_END;
typedef union {
    struct {
        unsigned int sao_area7_start_lcux : 16 ;
        unsigned int sao_area7_start_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA7_START;
typedef union {
    struct {
        unsigned int sao_area7_end_lcux : 16 ;
        unsigned int sao_area7_end_lcuy : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_SAO_SSD_AREA7_END;
typedef union {
    struct {
        unsigned int vcpi_curld_c_stride : 16 ;
        unsigned int vcpi_curld_y_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_curld_ext_c_stride : 16 ;
        unsigned int vcpi_curld_ext_y_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_EXT_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_refc_l0_stride : 16 ;
        unsigned int vcpi_refy_l0_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_L0_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_refc_l1_stride : 16 ;
        unsigned int vcpi_refy_l1_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_L1_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_recst_ystride : 16 ;
        unsigned int vcpi_recst_cstride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REC_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_recst_yhstride : 16 ;
        unsigned int vcpi_recst_chstride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REC_HEADER_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_refc_l0_hstride : 16 ;
        unsigned int vcpi_refy_l0_hstride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_L0_HEADER_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_refc_l1_hstride : 16 ;
        unsigned int vcpi_refy_l1_hstride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_L1_HEADER_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_qpinfo_ld_stride : 16 ;
        unsigned int vcpi_qpinfo_st_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_QPINFO_LD_ST_STRIDE;
typedef union {
    struct {
        unsigned int ime_early_termi_thr : 13 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ET_THR;
typedef union {
    struct {
        unsigned int ime_mestat_output_thr : 13 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ET_THR_ME_STAT;
typedef union {
    struct {
        unsigned int ime_refbuf_ver_words_num : 8 ;
        unsigned int ime_refbuf_hor_words_num : 5 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_REF_BUF_WORD_NUM;
typedef union {
    struct {
        unsigned int ime_interpolation_flag : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_IME_INTERPOLATION_FLAG;
typedef union {
    struct {
        unsigned int ime_max_region : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_MAX_REGION;
typedef union {
    struct {
        unsigned int ime_add1_random_point0 : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD1_RANDOM_POINT_LIST;
typedef union {
    struct {
        unsigned int ime_add2_random_point0 : 16 ;
        unsigned int ime_add2_random_point1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD2_RANDOM_POINT_LIST;
typedef union {
    struct {
        unsigned int ime_add3_random_point0 : 16 ;
        unsigned int ime_add3_random_point1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD3_RANDOM_POINT_LIST0;
typedef union {
    struct {
        unsigned int ime_add3_random_point2 : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD3_RANDOM_POINT_LIST1;
typedef union {
    struct {
        unsigned int ime_add4_random_point0 : 16 ;
        unsigned int ime_add4_random_point1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD4_RANDOM_POINT_LIST0;
typedef union {
    struct {
        unsigned int ime_add4_random_point2 : 16 ;
        unsigned int ime_add4_random_point3 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD4_RANDOM_POINT_LIST1;
typedef union {
    struct {
        unsigned int ime_add5_random_point0 : 16 ;
        unsigned int ime_add5_random_point1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD5_RANDOM_POINT_LIST0;
typedef union {
    struct {
        unsigned int ime_add5_random_point2 : 16 ;
        unsigned int ime_add5_random_point3 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD5_RANDOM_POINT_LIST1;
typedef union {
    struct {
        unsigned int ime_add5_random_point4 : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD5_RANDOM_POINT_LIST2;
typedef union {
    struct {
        unsigned int ime_add6_random_point0 : 16 ;
        unsigned int ime_add6_random_point1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD6_RANDOM_POINT_LIST0;
typedef union {
    struct {
        unsigned int ime_add6_random_point2 : 16 ;
        unsigned int ime_add6_random_point3 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD6_RANDOM_POINT_LIST1;
typedef union {
    struct {
        unsigned int ime_add6_random_point4 : 16 ;
        unsigned int ime_add6_random_point5 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD6_RANDOM_POINT_LIST2;
typedef union {
    struct {
        unsigned int ime_add7_random_point0 : 16 ;
        unsigned int ime_add7_random_point1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST0;
typedef union {
    struct {
        unsigned int ime_add7_random_point2 : 16 ;
        unsigned int ime_add7_random_point3 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST1;
typedef union {
    struct {
        unsigned int ime_add7_random_point4 : 16 ;
        unsigned int ime_add7_random_point5 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST2;
typedef union {
    struct {
        unsigned int ime_add7_random_point6 : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST3;
typedef union {
    struct {
        unsigned int ime_add8_random_point0 : 16 ;
        unsigned int ime_add8_random_point1 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST0;
typedef union {
    struct {
        unsigned int ime_add8_random_point2 : 16 ;
        unsigned int ime_add8_random_point3 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST1;
typedef union {
    struct {
        unsigned int ime_add8_random_point4 : 16 ;
        unsigned int ime_add8_random_point5 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST2;
typedef union {
    struct {
        unsigned int ime_add8_random_point6 : 16 ;
        unsigned int ime_add8_random_point7 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST3;
typedef union {
    struct {
        unsigned int vcpi_ime_temporal_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_TMV_EN;
typedef union {
    struct {
        unsigned int ime_add1_random_point0_b : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD1_RANDOM_POINT_LIST_B;
typedef union {
    struct {
        unsigned int ime_add2_random_point0_b : 16 ;
        unsigned int ime_add2_random_point1_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD2_RANDOM_POINT_LIST_B;
typedef union {
    struct {
        unsigned int ime_add3_random_point0_b : 16 ;
        unsigned int ime_add3_random_point1_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD3_RANDOM_POINT_LIST0_B;
typedef union {
    struct {
        unsigned int ime_add3_random_point2_b : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD3_RANDOM_POINT_LIST1_B;
typedef union {
    struct {
        unsigned int ime_add4_random_point0_b : 16 ;
        unsigned int ime_add4_random_point1_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD4_RANDOM_POINT_LIST0_B;
typedef union {
    struct {
        unsigned int ime_add4_random_point2_b : 16 ;
        unsigned int ime_add4_random_point3_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD4_RANDOM_POINT_LIST1_B;
typedef union {
    struct {
        unsigned int ime_add5_random_point0_b : 16 ;
        unsigned int ime_add5_random_point1_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD5_RANDOM_POINT_LIST0_B;
typedef union {
    struct {
        unsigned int ime_add5_random_point2_b : 16 ;
        unsigned int ime_add5_random_point3_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD5_RANDOM_POINT_LIST1_B;
typedef union {
    struct {
        unsigned int ime_add5_random_point4_b : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD5_RANDOM_POINT_LIST2_B;
typedef union {
    struct {
        unsigned int ime_add6_random_point0_b : 16 ;
        unsigned int ime_add6_random_point1_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD6_RANDOM_POINT_LIST0_B;
typedef union {
    struct {
        unsigned int ime_add6_random_point2_b : 16 ;
        unsigned int ime_add6_random_point3_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD6_RANDOM_POINT_LIST1_B;
typedef union {
    struct {
        unsigned int ime_add6_random_point4_b : 16 ;
        unsigned int ime_add6_random_point5_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD6_RANDOM_POINT_LIST2_B;
typedef union {
    struct {
        unsigned int ime_add7_random_point0_b : 16 ;
        unsigned int ime_add7_random_point1_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST0_B;
typedef union {
    struct {
        unsigned int ime_add7_random_point2_b : 16 ;
        unsigned int ime_add7_random_point3_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST1_B;
typedef union {
    struct {
        unsigned int ime_add7_random_point4_b : 16 ;
        unsigned int ime_add7_random_point5_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST2_B;
typedef union {
    struct {
        unsigned int ime_add7_random_point6_b : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD7_RANDOM_POINT_LIST3_B;
typedef union {
    struct {
        unsigned int ime_add8_random_point0_b : 16 ;
        unsigned int ime_add8_random_point1_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST0_B;
typedef union {
    struct {
        unsigned int ime_add8_random_point2_b : 16 ;
        unsigned int ime_add8_random_point3_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST1_B;
typedef union {
    struct {
        unsigned int ime_add8_random_point4_b : 16 ;
        unsigned int ime_add8_random_point5_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST2_B;
typedef union {
    struct {
        unsigned int ime_add8_random_point6_b : 16 ;
        unsigned int ime_add8_random_point7_b : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_ME_ADD8_RANDOM_POINT_LIST3_B;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp1 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT0;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp3 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp2 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT1;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp5 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp4 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT2;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp7 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp6 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT3;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp9 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp8 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT4;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp11 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp10 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT5;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp13 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp12 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT6;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp15 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp14 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT7;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp17 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp16 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT8;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp19 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp18 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT9;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp21 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp20 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT10;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp23 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp22 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT11;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp25 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp24 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT12;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp27 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp26 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT13;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp29 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp28 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT14;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp31 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp30 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT15;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp33 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp32 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT16;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp35 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp34 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT17;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp37 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp36 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT18;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp39 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp38 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT19;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp41 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp40 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT20;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp43 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp42 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT21;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp45 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp44 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT22;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp47 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp46 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT23;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp49 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp48 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT24;
typedef union {
    struct {
        unsigned int vcpi_srdo_min_weight_qp51 : 16 ;
        unsigned int vcpi_srdo_min_weight_qp50 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_SRDO_MIN_WEIGHT25;
typedef union {
    struct {
        unsigned int vcpi_refc_downboundary_stride : 16 ;
        unsigned int vcpi_refy_downboundary_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_DOWNBOUNDARY_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_refch_downboundary_stride : 16 ;
        unsigned int vcpi_refyh_downboundary_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_DOWNBOUNDARY_HEADER_STRIDE;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda16 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG80;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda17 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG81;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda18 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG82;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda19 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG83;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda20 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG84;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda21 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG85;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda22 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG86;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda23 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG87;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda24 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG88;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda25 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG89;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda26 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG90;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda27 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG91;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda28 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG92;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda29 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG93;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda30 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG94;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda31 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG95;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda32 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG96;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda33 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG97;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda34 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG98;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda35 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG99;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda36 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG100;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda37 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG101;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda38 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG102;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda39 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG103;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda40 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG104;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda41 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG105;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda42 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG106;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda43 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG107;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda44 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG108;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda45 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG109;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda46 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG110;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda47 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG111;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda48 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG112;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda49 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG113;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda50 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG114;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda51 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG115;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda52 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG116;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda53 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG117;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda54 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG118;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda55 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG119;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda56 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG120;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda57 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG121;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda58 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG122;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda59 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG123;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda60 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG124;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda61 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG125;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda62 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG126;
typedef union {
    struct {
        unsigned int qpg_sqrt_lambda63 : 20 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_VEDU_QPG_QP_LAMBDA_CTRL_REG127;
typedef union {
    struct {
        unsigned int vcpi_curld_current_slicenum : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_LUMA_START_ROWNUM;
typedef union {
    struct {
        unsigned int vcpi_curld_start_slicenum : 16 ;
        unsigned int vcpi_curld_inquire_mod : 2 ;
        unsigned int vcpi_curld_hts_en : 1 ;
        unsigned int reserved_0 : 13 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_CURLD_START_SLICENUM;
typedef union {
    struct {
        unsigned int vcpi_ref_boundary_mod : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REFLD_BOUNDARY_MOD;
typedef union {
    struct {
        unsigned int vcpi_refc_upboundary_stride : 16 ;
        unsigned int vcpi_refy_upboundary_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_UPBOUNDARY_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_refch_upboundary_stride : 16 ;
        unsigned int vcpi_refyh_upboundary_stride : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_REF_UPBOUNFARY_HEADER_STRIDE;
typedef union {
    struct {
        unsigned int vcpi_private_slchdr_part0 : 1 ;
        unsigned int vcpi_private_slcadd_size0 : 5 ;
        unsigned int vcpi_private_slcadd_size1 : 5 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PRIVATE_SLCHDR_PART0;
typedef union {
    struct {
        unsigned int vcpi_lowlatency_slice_inten : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_LOWLATENCY_SLICE_INTEN;
typedef union {
    struct {
        unsigned int vcpi_intrapu4_refresh_startx : 12 ;
        unsigned int vcpi_intrapu4_refresh_starty : 12 ;
        unsigned int vcpi_intrapu4_refresh_en : 1 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_INTRAPU4_REFRESH_START;
typedef union {
    struct {
        unsigned int vcpi_intrapu4_refresh_endx : 12 ;
        unsigned int vcpi_intrapu4_refresh_endy : 12 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCTRL_INTRAPU4_REFRESH_END;
typedef union {
    struct {
        unsigned int vcpi_cmdlst_grp_num : 16 ;
        unsigned int vcpi_cmdlst_grp_start : 1 ;
        unsigned int vcpi_cmdlst_wait_en : 1 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_CMDLST_GRP_NUM;
typedef union {
    struct {
        unsigned int vcpi_cmdlst_soft_finish_num : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_CMDLST_SOFT_FINISH_NUM;
typedef union {
    struct {
        unsigned int vcpi_force_zeromv : 1 ;
        unsigned int vcpi_vlcst_payload_len : 11 ;
        unsigned int vcpi_vlcst_packet_en : 1 ;
        unsigned int vcpi_private_slchdr_en : 1 ;
        unsigned int vcpi_search_window_height_mode : 2 ;
        unsigned int vcpi_search_window_height_mode_ref1 : 2 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_FORCE_ZEROMV;
typedef union {
    struct {
        unsigned int vcpi_force_intrapu4_num : 4 ;
        unsigned int vcpi_force_intrapu8_num : 4 ;
        unsigned int vcpi_force_intrapu16_num : 4 ;
        unsigned int vcpi_force_intrapu32_num : 4 ;
        unsigned int vcpi_force_intrapu_num_en : 1 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_FORCE_INTRAPU32_NUM;
typedef union {
    struct {
        unsigned int vcpi_vlcst_sah : 16 ;
        unsigned int vcpi_vlcst_rah : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_VLCST_RAH_SAH;
typedef union {
    struct {
        unsigned int vcpi_vlcst_type : 16 ;
        unsigned int vcpi_vlcst_qos : 16 ;
    } bits;
    unsigned int u32;
} U_VEDU_VCPI_PACKET_INFO;
typedef union {
    struct {
        unsigned int venc_top_secure_n : 1 ;
        unsigned int mcu_secure_n : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_SECURE_SET;
typedef struct {
    volatile U_VEDU_VCPI_INTMASK VEDU_VCPI_INTMASK ;
    volatile U_VEDU_VCPI_INTCLR VEDU_VCPI_INTCLR ;
    volatile U_VEDU_VCPI_START VEDU_VCPI_START ;
    volatile U_VEDU_BUS_IDLE_REQ VEDU_BUS_IDLE_REQ ;
    volatile unsigned int VEDU_VCPI_FRAMENO ;
    volatile unsigned int VEDU_VCPI_TIMEOUT ;
    volatile U_VEDU_VCPI_MODE VEDU_VCPI_MODE ;
    volatile U_VEDU_VCPI_SOFTINTSET VEDU_VCPI_SOFTINTSET ;
    volatile U_VEDU_VCPI_CMDLST_CLKGATE VEDU_VCPI_CMDLST_CLKGATE ;
    volatile U_VEDU_VCPI_CMD_DPM_SOFTRST VEDU_VCPI_CMD_DPM_SOFTRST ;
    volatile U_VEDU_ISPLD_CFG VEDU_ISPLD_CFG ;
    volatile U_VEDU_RAW_DATA_MODE VEDU_RAW_DATA_MODE ;
    volatile U_VEDU_EMAR_SCRAMBLE_TYPE VEDU_EMAR_SCRAMBLE_TYPE ;
    volatile unsigned int VEDU_VCPI_LLILD_ADDR_L ;
    volatile unsigned int VEDU_VCPI_LLILD_ADDR_H ;
    volatile U_VEDU_VCPI_RC_ENABLE VEDU_VCPI_RC_ENABLE ;
    volatile U_VEDU_VLCST_PTBITS_EN VEDU_VLCST_PTBITS_EN ;
    volatile unsigned int VEDU_VLCST_PTBITS ;
    volatile U_VEDU_PPFD_ST_CFG VEDU_PPFD_ST_CFG ;
    volatile U_VEDU_VCPI_QPCFG VEDU_VCPI_QPCFG ;
    volatile U_VEDU_QPG_MAX_MIN_QP VEDU_QPG_MAX_MIN_QP ;
    volatile U_VEDU_QPG_SMART_REG VEDU_QPG_SMART_REG ;
    volatile U_VEDU_QPG_ROW_TARGET_BITS VEDU_QPG_ROW_TARGET_BITS ;
    volatile U_VEDU_QPG_AVERAGE_LCU_BITS VEDU_QPG_AVERAGE_LCU_BITS ;
    volatile U_VEDU_QPG_CU_QP_DELTA_THRESH_REG0 VEDU_QPG_CU_QP_DELTA_THRESH_REG0 ;
    volatile U_VEDU_QPG_CU_QP_DELTA_THRESH_REG1 VEDU_QPG_CU_QP_DELTA_THRESH_REG1 ;
    volatile U_VEDU_QPG_CU_QP_DELTA_THRESH_REG2 VEDU_QPG_CU_QP_DELTA_THRESH_REG2 ;
    volatile U_VEDU_QPG_CU_QP_DELTA_THRESH_REG3 VEDU_QPG_CU_QP_DELTA_THRESH_REG3 ;
    volatile U_VEDU_QPG_DELTA_LEVEL VEDU_QPG_DELTA_LEVEL ;
    volatile U_VEDU_QPG_MADI_SWITCH_THR VEDU_QPG_MADI_SWITCH_THR ;
    volatile U_VEDU_QPG_CURR_SAD_EN VEDU_QPG_CURR_SAD_EN ;
    volatile U_VEDU_QPG_CURR_SAD_LEVEL VEDU_QPG_CURR_SAD_LEVEL ;
    volatile U_VEDU_QPG_CURR_SAD_THRESH0 VEDU_QPG_CURR_SAD_THRESH0 ;
    volatile U_VEDU_QPG_CURR_SAD_THRESH1 VEDU_QPG_CURR_SAD_THRESH1 ;
    volatile U_VEDU_QPG_CURR_SAD_THRESH2 VEDU_QPG_CURR_SAD_THRESH2 ;
    volatile U_VEDU_QPG_CURR_SAD_THRESH3 VEDU_QPG_CURR_SAD_THRESH3 ;
    volatile U_VEDU_LUMA_RC VEDU_LUMA_RC ;
    volatile U_VEDU_LUMA_LEVEL VEDU_LUMA_LEVEL ;
    volatile U_VEDU_LUMA_THRESH0 VEDU_LUMA_THRESH0 ;
    volatile U_VEDU_LUMA_THRESH1 VEDU_LUMA_THRESH1 ;
    volatile U_VEDU_LUMA_THRESH2 VEDU_LUMA_THRESH2 ;
    volatile U_VEDU_LUMA_THRESH3 VEDU_LUMA_THRESH3 ;
    volatile U_VEDU_MISC_CFG VEDU_MISC_CFG ;
    volatile unsigned int VEDU_RESERVED_05 ;
    volatile unsigned int reserved_0[16] ;
    volatile U_VEDU_VCPI_OUTSTD VEDU_VCPI_OUTSTD ;
    volatile U_VEDU_VCTRL_LCU_BASELINE VEDU_VCTRL_LCU_BASELINE ;
    volatile unsigned int VEDU_VCPI_SPMEM_CTRL_0 ;
    volatile U_VEDU_VCPI_SPMEM_CTRL_1 VEDU_VCPI_SPMEM_CTRL_1 ;
    volatile U_VEDU_VCPI_SPMEM_CTRL_2 VEDU_VCPI_SPMEM_CTRL_2 ;
    volatile unsigned int VEDU_VCPI_TPMEM_CTRL_0 ;
    volatile unsigned int VEDU_VCPI_TPMEM_CTRL_1 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG00 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG00 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG01 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG01 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG02 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG02 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG03 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG03 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG04 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG04 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG05 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG05 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG06 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG06 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG07 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG07 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG08 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG08 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG09 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG09 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG10 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG10 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG11 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG11 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG12 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG12 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG13 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG13 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG14 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG14 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG15 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG15 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG16 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG16 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG17 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG17 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG18 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG18 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG19 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG19 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG20 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG20 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG21 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG21 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG22 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG22 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG23 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG23 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG24 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG24 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG25 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG25 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG26 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG26 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG27 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG27 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG28 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG28 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG29 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG29 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG30 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG30 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG31 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG31 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG32 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG32 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG33 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG33 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG34 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG34 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG35 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG35 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG36 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG36 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG37 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG37 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG38 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG38 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG39 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG39 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG40 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG40 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG41 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG41 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG42 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG42 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG43 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG43 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG44 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG44 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG45 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG45 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG46 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG46 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG47 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG47 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG48 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG48 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG49 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG49 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG50 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG50 ;
    volatile U_VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG51 VEDU_VCTRL_QP_LAMBDA_CTRL_ENHANCED_LAYER_REG51 ;
    volatile U_VEDU_VCTRL_GCFG VEDU_VCTRL_GCFG ;
    volatile U_VEDU_VCTRL_GRAN VEDU_VCTRL_GRAN ;
    volatile U_VEDU_VCTRL_THRESHOLD_L VEDU_VCTRL_THRESHOLD_L ;
    volatile U_VEDU_VCTRL_THRESHOLD_H VEDU_VCTRL_THRESHOLD_H ;
    volatile U_VEDU_VCTRL_INTRAPU4_OFFSET VEDU_VCTRL_INTRAPU4_OFFSET ;
    volatile U_VEDU_CURLD_DEPTHCODING VEDU_CURLD_DEPTHCODING ;
    volatile U_VEDU_CURLD_WATERMARK_CFG VEDU_CURLD_WATERMARK_CFG ;
    volatile U_VEDU_CURLD_WATERMARK_SIZE VEDU_CURLD_WATERMARK_SIZE ;
    volatile U_VEDU_VCPI_MODE2 VEDU_VCPI_MODE2 ;
    volatile U_VEDU_CURLD_GCFG VEDU_CURLD_GCFG ;
    volatile U_VEDU_VCPI_OSD_ENABLE VEDU_VCPI_OSD_ENABLE ;
    volatile U_VEDU_VCPI_STRFMT VEDU_VCPI_STRFMT ;
    volatile U_VEDU_VCPI_INTRA_INTER_CU_EN VEDU_VCPI_INTRA_INTER_CU_EN ;
    volatile U_VEDU_VCPI_CROSS_TILE_SLC VEDU_VCPI_CROSS_TILE_SLC ;
    volatile U_VEDU_VCPI_MULTISLC VEDU_VCPI_MULTISLC ;
    volatile U_VEDU_VCTRL_LCU_TARGET_BIT VEDU_VCTRL_LCU_TARGET_BIT ;
    volatile U_VEDU_VCPI_SW_L0_SIZE VEDU_VCPI_SW_L0_SIZE ;
    volatile unsigned int VEDU_RESERVED_0220 ;
    volatile U_VEDU_VCPI_I_SLC_INSERT VEDU_VCPI_I_SLC_INSERT ;
    volatile U_VEDU_PME_SAFE_CFG VEDU_PME_SAFE_CFG ;
    volatile U_VEDU_PME_IBLK_REFRESH VEDU_PME_IBLK_REFRESH ;
    volatile U_VEDU_PME_IBLK_REFRESH_NUM VEDU_PME_IBLK_REFRESH_NUM ;
    volatile U_VEDU_INTRA_CHNL4_ANG_0EN VEDU_INTRA_CHNL4_ANG_0EN ;
    volatile U_VEDU_INTRA_CHNL4_ANG_1EN VEDU_INTRA_CHNL4_ANG_1EN ;
    volatile U_VEDU_INTRA_CHNL8_ANG_0EN VEDU_INTRA_CHNL8_ANG_0EN ;
    volatile U_VEDU_INTRA_CHNL8_ANG_1EN VEDU_INTRA_CHNL8_ANG_1EN ;
    volatile U_VEDU_INTRA_CHNL16_ANG_0EN VEDU_INTRA_CHNL16_ANG_0EN ;
    volatile U_VEDU_INTRA_CHNL16_ANG_1EN VEDU_INTRA_CHNL16_ANG_1EN ;
    volatile U_VEDU_INTRA_CHNL32_ANG_0EN VEDU_INTRA_CHNL32_ANG_0EN ;
    volatile U_VEDU_INTRA_CHNL32_ANG_1EN VEDU_INTRA_CHNL32_ANG_1EN ;
    volatile U_VEDU_PACK_CU_PARAMETER VEDU_PACK_CU_PARAMETER ;
    volatile U_VEDU_PACK_PCM_PARAMETER VEDU_PACK_PCM_PARAMETER ;
    volatile U_VEDU_QPG_READLINE_INTERVAL VEDU_QPG_READLINE_INTERVAL ;
    volatile U_VEDU_PMV_READLINE_INTERVAL VEDU_PMV_READLINE_INTERVAL ;
    volatile U_VEDU_RGB2YUV_COEF_P0 VEDU_RGB2YUV_COEF_P0 ;
    volatile U_VEDU_RGB2YUV_COEF_P1 VEDU_RGB2YUV_COEF_P1 ;
    volatile U_VEDU_RGB2YUV_COEF_P2 VEDU_RGB2YUV_COEF_P2 ;
    volatile U_VEDU_RGB2YUV_OFFSET VEDU_RGB2YUV_OFFSET ;
    volatile U_VEDU_CURLD_CLIP_THR_Y VEDU_CURLD_CLIP_THR_Y ;
    volatile U_VEDU_CURLD_CLIP_THR_C VEDU_CURLD_CLIP_THR_C ;
    volatile U_VEDU_RGB2YUV_SHIFT_WIDTH VEDU_RGB2YUV_SHIFT_WIDTH ;
    volatile U_VEDU_RGB2YUV_COEF_P3 VEDU_RGB2YUV_COEF_P3 ;
    volatile U_VEDU_RGB2YUV_COEF_P4 VEDU_RGB2YUV_COEF_P4 ;
    volatile unsigned int VEDU_CURLD_HEBC_CTRL ;
    volatile unsigned int VEDU_RECST_HEBC_CTRL ;
    volatile U_VEDU_CURLD_NARROW_CHRM VEDU_CURLD_NARROW_CHRM ;
    volatile U_VEDU_CURLD_NARROW_LUMA VEDU_CURLD_NARROW_LUMA ;
    volatile unsigned int VEDU_REFLD_DBG_CTRL ;
    volatile unsigned int VEDU_REFLD_DBG_CTRL_REF2 ;
    volatile unsigned int VEDU_CURLD_WATERMARK_ADDR_L ;
    volatile unsigned int VEDU_CURLD_WATERMARK_ADDR_H ;
    volatile U_VEDU_CURLD_WATERMARK_STRIDE VEDU_CURLD_WATERMARK_STRIDE ;
    volatile unsigned int VEDU_RESERVED_02AC ;
    volatile unsigned int reserved_1[7] ;
    volatile U_VEDU_CURLD_RGB_CLIP VEDU_CURLD_RGB_CLIP ;
    volatile unsigned int VEDU_RESERVED_02D0 ;
    volatile unsigned int reserved_2 ;
    volatile U_VEDU_CURLD_SRCH_STRIDE VEDU_CURLD_SRCH_STRIDE ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_0 VEDU_QPG_CHROMA_WEIGHTING_0 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_1 VEDU_QPG_CHROMA_WEIGHTING_1 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_2 VEDU_QPG_CHROMA_WEIGHTING_2 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_3 VEDU_QPG_CHROMA_WEIGHTING_3 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_4 VEDU_QPG_CHROMA_WEIGHTING_4 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_5 VEDU_QPG_CHROMA_WEIGHTING_5 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_6 VEDU_QPG_CHROMA_WEIGHTING_6 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_7 VEDU_QPG_CHROMA_WEIGHTING_7 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_8 VEDU_QPG_CHROMA_WEIGHTING_8 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_9 VEDU_QPG_CHROMA_WEIGHTING_9 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_10 VEDU_QPG_CHROMA_WEIGHTING_10 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_11 VEDU_QPG_CHROMA_WEIGHTING_11 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_12 VEDU_QPG_CHROMA_WEIGHTING_12 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_13 VEDU_QPG_CHROMA_WEIGHTING_13 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_14 VEDU_QPG_CHROMA_WEIGHTING_14 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_15 VEDU_QPG_CHROMA_WEIGHTING_15 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_16 VEDU_QPG_CHROMA_WEIGHTING_16 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_17 VEDU_QPG_CHROMA_WEIGHTING_17 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_18 VEDU_QPG_CHROMA_WEIGHTING_18 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_19 VEDU_QPG_CHROMA_WEIGHTING_19 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_20 VEDU_QPG_CHROMA_WEIGHTING_20 ;
    volatile U_VEDU_QPG_CHROMA_WEIGHTING_21 VEDU_QPG_CHROMA_WEIGHTING_21 ;
    volatile unsigned int VEDU_RESERVED_07 ;
    volatile unsigned int reserved_3[6] ;
    volatile U_VEDU_NEW_CFG0 VEDU_NEW_CFG0 ;
    volatile unsigned int reserved_4[11] ;
    volatile U_VEDU_VCTRL_ROI_CFG0 VEDU_VCTRL_ROI_CFG0 ;
    volatile U_VEDU_VCTRL_ROI_CFG1 VEDU_VCTRL_ROI_CFG1 ;
    volatile U_VEDU_VCTRL_ROI_CFG2 VEDU_VCTRL_ROI_CFG2 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_0 VEDU_VCTRL_ROI_SIZE_0 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_1 VEDU_VCTRL_ROI_SIZE_1 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_2 VEDU_VCTRL_ROI_SIZE_2 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_3 VEDU_VCTRL_ROI_SIZE_3 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_4 VEDU_VCTRL_ROI_SIZE_4 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_5 VEDU_VCTRL_ROI_SIZE_5 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_6 VEDU_VCTRL_ROI_SIZE_6 ;
    volatile U_VEDU_VCTRL_ROI_SIZE_7 VEDU_VCTRL_ROI_SIZE_7 ;
    volatile U_VEDU_VCTRL_ROI_START_0 VEDU_VCTRL_ROI_START_0 ;
    volatile U_VEDU_VCTRL_ROI_START_1 VEDU_VCTRL_ROI_START_1 ;
    volatile U_VEDU_VCTRL_ROI_START_2 VEDU_VCTRL_ROI_START_2 ;
    volatile U_VEDU_VCTRL_ROI_START_3 VEDU_VCTRL_ROI_START_3 ;
    volatile U_VEDU_VCTRL_ROI_START_4 VEDU_VCTRL_ROI_START_4 ;
    volatile U_VEDU_VCTRL_ROI_START_5 VEDU_VCTRL_ROI_START_5 ;
    volatile U_VEDU_VCTRL_ROI_START_6 VEDU_VCTRL_ROI_START_6 ;
    volatile U_VEDU_VCTRL_ROI_START_7 VEDU_VCTRL_ROI_START_7 ;
    volatile U_VEDU_PMESTAT_SPEC_PIX_THR_Y VEDU_PMESTAT_SPEC_PIX_THR_Y ;
    volatile U_VEDU_PMESTAT_SPEC_PIX_THR_CB VEDU_PMESTAT_SPEC_PIX_THR_CB ;
    volatile U_VEDU_PMESTAT_SPEC_PIX_THR_CR VEDU_PMESTAT_SPEC_PIX_THR_CR ;
    volatile unsigned int VEDU_RESERVED_09 ;
    volatile unsigned int reserved_5[10] ;
    volatile U_VEDU_VCPI_PICSIZE_PIX VEDU_VCPI_PICSIZE_PIX ;
    volatile unsigned int VEDU_RESERVED_0408 ;
    volatile unsigned int reserved_6 ;
    volatile U_VEDU_VCPI_VLC_CONFIG VEDU_VCPI_VLC_CONFIG ;
    volatile U_VEDU_VCPI_REF_FLAG VEDU_VCPI_REF_FLAG ;
    volatile U_VEDU_PMV_TMV_EN VEDU_PMV_TMV_EN ;
    volatile U_VEDU_VCPI_TMV_LOAD VEDU_VCPI_TMV_LOAD ;
    volatile unsigned int VEDU_PMV_POC_0 ;
    volatile unsigned int VEDU_PMV_POC_1 ;
    volatile unsigned int VEDU_PMV_POC_2 ;
    volatile unsigned int VEDU_PMV_POC_3 ;
    volatile unsigned int VEDU_PMV_POC_4 ;
    volatile unsigned int VEDU_PMV_POC_5 ;
    volatile U_VEDU_CABAC_GLB_CFG VEDU_CABAC_GLB_CFG ;
    volatile U_VEDU_CABAC_SLCHDR_SIZE VEDU_CABAC_SLCHDR_SIZE ;
    volatile U_VEDU_CABAC_SLCHDR_PART1 VEDU_CABAC_SLCHDR_PART1 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG1 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG2 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG3 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG4 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG5 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG6 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG7 ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG8 ;
    volatile U_VEDU_CABAC_SLCHDR_SIZE_I VEDU_CABAC_SLCHDR_SIZE_I ;
    volatile U_VEDU_CABAC_SLCHDR_PART1_I VEDU_CABAC_SLCHDR_PART1_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG1_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG2_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG3_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG4_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG5_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG6_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG7_I ;
    volatile unsigned int VEDU_CABAC_SLCHDR_PART2_SEG8_I ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM0 ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM1 ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM2 ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM3 ;
    volatile unsigned int VEDU_VLC_REORDERSTRM0 ;
    volatile unsigned int VEDU_VLC_REORDERSTRM1 ;
    volatile unsigned int VEDU_VLC_MARKINGSTRM0 ;
    volatile unsigned int VEDU_VLC_MARKINGSTRM1 ;
    volatile U_VEDU_VLC_SLCHDRPARA VEDU_VLC_SLCHDRPARA ;
    volatile U_VEDU_VLC_SVC VEDU_VLC_SVC ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM0_I ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM1_I ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM2_I ;
    volatile unsigned int VEDU_VLC_SLCHDRSTRM3_I ;
    volatile unsigned int VEDU_VLC_REORDERSTRM0_I ;
    volatile unsigned int VEDU_VLC_REORDERSTRM1_I ;
    volatile unsigned int VEDU_VLC_MARKINGSTRM0_I ;
    volatile unsigned int VEDU_VLC_MARKINGSTRM1_I ;
    volatile U_VEDU_VLC_SLCHDRPARA_I VEDU_VLC_SLCHDRPARA_I ;
    volatile unsigned int VEDU_VLCST_STRMBUFLEN ;
    volatile unsigned int VEDU_VLCST_SLC_CFG0 ;
    volatile unsigned int VEDU_VLCST_SLC_CFG1 ;
    volatile unsigned int VEDU_VLCST_SLC_CFG2 ;
    volatile unsigned int VEDU_VLCST_SLC_CFG3 ;
    volatile unsigned int VEDU_ICE_V2R1_SEG_256X1_DCMP_CTRL ;
    volatile U_VEDU_REFLD_CMP_CLKGATE_EN VEDU_REFLD_CMP_CLKGATE_EN ;
    volatile U_VEDU_RPINTRA_CFG VEDU_RPINTRA_CFG ;
    volatile unsigned int VEDU_RESERVED_10 ;
    volatile unsigned int reserved_7 ;
    volatile U_VEDU_QPG_LOWLUMA VEDU_QPG_LOWLUMA ;
    volatile U_VEDU_QPG_HEDGE VEDU_QPG_HEDGE ;
    volatile U_VEDU_QPG_HEDGE_MOVE VEDU_QPG_HEDGE_MOVE ;
    volatile U_VEDU_QPG_SKIN VEDU_QPG_SKIN ;
    volatile U_VEDU_QPG_INTRA_DET VEDU_QPG_INTRA_DET ;
    volatile unsigned int VEDU_QPG_H264_SMOOTH ;
    volatile U_VEDU_QPG_CU32_DELTA VEDU_QPG_CU32_DELTA ;
    volatile U_VEDU_QPG_LAMBDA_MODE VEDU_QPG_LAMBDA_MODE ;
    volatile U_VEDU_QPG_QP_RESTRAIN VEDU_QPG_QP_RESTRAIN ;
    volatile unsigned int VEDU_QPG_CU_MIN_SAD_THRESH_0 ;
    volatile U_VEDU_QPG_CU_MIN_SAD_REG VEDU_QPG_CU_MIN_SAD_REG ;
    volatile U_VEDU_QPG_FLAT_REGION VEDU_QPG_FLAT_REGION ;
    volatile U_VEDU_QPG_RES_COEF VEDU_QPG_RES_COEF ;
    volatile unsigned int VEDU_TILE_RC ;
    volatile U_VEDU_CHROMA_PROTECT VEDU_CHROMA_PROTECT ;
    volatile U_VEDU_PME_QPG_RC_THR0 VEDU_PME_QPG_RC_THR0 ;
    volatile U_VEDU_PME_QPG_RC_THR1 VEDU_PME_QPG_RC_THR1 ;
    volatile U_VEDU_PME_LOW_LUMA_THR VEDU_PME_LOW_LUMA_THR ;
    volatile U_VEDU_PME_CHROMA_FLAT VEDU_PME_CHROMA_FLAT ;
    volatile U_VEDU_PME_LUMA_FLAT VEDU_PME_LUMA_FLAT ;
    volatile U_VEDU_PME_MADI_FLAT VEDU_PME_MADI_FLAT ;
    volatile U_VEDU_VLCST_DESCRIPTOR VEDU_VLCST_DESCRIPTOR ;
    volatile unsigned int VEDU_PPFD_ST_LEN0 ;
    volatile U_VEDU_CURLD_CLIP_LUMA VEDU_CURLD_CLIP_LUMA ;
    volatile U_VEDU_CURLD_CLIP_CHROMA VEDU_CURLD_CLIP_CHROMA ;
    volatile U_VEDU_TQITQ_DEADZONE VEDU_TQITQ_DEADZONE ;
    volatile U_VEDU_VCPI_PME_PARAM VEDU_VCPI_PME_PARAM ;
    volatile U_VEDU_VCPI_PIC_STRONG_EN VEDU_VCPI_PIC_STRONG_EN ;
    volatile U_VEDU_VCPI_PINTRA_THRESH0 VEDU_VCPI_PINTRA_THRESH0 ;
    volatile U_VEDU_VCPI_PINTRA_THRESH1 VEDU_VCPI_PINTRA_THRESH1 ;
    volatile U_VEDU_VCPI_PINTRA_THRESH2 VEDU_VCPI_PINTRA_THRESH2 ;
    volatile U_VEDU_VCPI_INTRA32_LOW_POWER VEDU_VCPI_INTRA32_LOW_POWER ;
    volatile U_VEDU_VCPI_INTRA16_LOW_POWER VEDU_VCPI_INTRA16_LOW_POWER ;
    volatile U_VEDU_VCPI_INTRA_REDUCE_RDO_NUM VEDU_VCPI_INTRA_REDUCE_RDO_NUM ;
    volatile U_VEDU_VCPI_NOFORCEZERO VEDU_VCPI_NOFORCEZERO ;
    volatile U_VEDU_PME_SKIP_LARGE_RES VEDU_PME_SKIP_LARGE_RES ;
    volatile U_VEDU_PME_SKIN_SAD_THR VEDU_PME_SKIN_SAD_THR ;
    volatile U_VEDU_VCTRL_NM_ACOFFSET_DENOISE VEDU_VCTRL_NM_ACOFFSET_DENOISE ;
    volatile U_VEDU_VCTRL_NM_ENGTHR_DENOISE VEDU_VCTRL_NM_ENGTHR_DENOISE ;
    volatile U_VEDU_VCTRL_NM_TU8_DENOISE VEDU_VCTRL_NM_TU8_DENOISE ;
    volatile U_VEDU_VCTRL_SK_ACOFFSET_DENOISE VEDU_VCTRL_SK_ACOFFSET_DENOISE ;
    volatile U_VEDU_VCTRL_SK_ENGTHR_DENOISE VEDU_VCTRL_SK_ENGTHR_DENOISE ;
    volatile U_VEDU_VCTRL_SK_TU8_DENOISE VEDU_VCTRL_SK_TU8_DENOISE ;
    volatile U_VEDU_VCTRL_ST_ACOFFSET_DENOISE VEDU_VCTRL_ST_ACOFFSET_DENOISE ;
    volatile U_VEDU_VCTRL_ST_ENGTHR_DENOISE VEDU_VCTRL_ST_ENGTHR_DENOISE ;
    volatile U_VEDU_VCTRL_ST_TU8_DENOISE VEDU_VCTRL_ST_TU8_DENOISE ;
    volatile U_VEDU_VCTRL_SE_ACOFFSET_DENOISE VEDU_VCTRL_SE_ACOFFSET_DENOISE ;
    volatile U_VEDU_VCTRL_SE_ENGTHR_DENOISE VEDU_VCTRL_SE_ENGTHR_DENOISE ;
    volatile U_VEDU_VCTRL_SE_TU8_DENOISE VEDU_VCTRL_SE_TU8_DENOISE ;
    volatile U_VEDU_VCTRL_SELM_ACOFFSET_DENOISE VEDU_VCTRL_SELM_ACOFFSET_DENOISE ;
    volatile U_VEDU_VCTRL_SELM_ENGTHR_DENOISE VEDU_VCTRL_SELM_ENGTHR_DENOISE ;
    volatile U_VEDU_VCTRL_SELM_TU8_DENOISE VEDU_VCTRL_SELM_TU8_DENOISE ;
    volatile U_VEDU_VCTRL_WS_ACOFFSET_DENOISE VEDU_VCTRL_WS_ACOFFSET_DENOISE ;
    volatile U_VEDU_VCTRL_WS_ENGTHR_DENOISE VEDU_VCTRL_WS_ENGTHR_DENOISE ;
    volatile U_VEDU_VCTRL_WS_TU8_DENOISE VEDU_VCTRL_WS_TU8_DENOISE ;
    volatile U_VEDU_VCTRL_SSSE_ACOFFSET_DENOISE VEDU_VCTRL_SSSE_ACOFFSET_DENOISE ;
    volatile U_VEDU_VCTRL_SSSE_ENGTHR_DENOISE VEDU_VCTRL_SSSE_ENGTHR_DENOISE ;
    volatile U_VEDU_VCTRL_SSSE_TU8_DENOISE VEDU_VCTRL_SSSE_TU8_DENOISE ;
    volatile unsigned int VEDU_RESERVED_11 ;
    volatile unsigned int reserved_9[5] ;
    volatile U_VEDU_VCTRL_INTRA_RDO_FACTOR_0 VEDU_VCTRL_INTRA_RDO_FACTOR_0 ;
    volatile U_VEDU_VCTRL_INTRA_RDO_FACTOR_1 VEDU_VCTRL_INTRA_RDO_FACTOR_1 ;
    volatile U_VEDU_VCTRL_INTRA_RDO_FACTOR_2 VEDU_VCTRL_INTRA_RDO_FACTOR_2 ;
    volatile U_VEDU_VCTRL_MRG_RDO_FACTOR_0 VEDU_VCTRL_MRG_RDO_FACTOR_0 ;
    volatile U_VEDU_VCTRL_MRG_RDO_FACTOR_1 VEDU_VCTRL_MRG_RDO_FACTOR_1 ;
    volatile U_VEDU_VCTRL_MRG_RDO_FACTOR_2 VEDU_VCTRL_MRG_RDO_FACTOR_2 ;
    volatile U_VEDU_VCTRL_FME_RDO_FACTOR_0 VEDU_VCTRL_FME_RDO_FACTOR_0 ;
    volatile U_VEDU_VCTRL_FME_RDO_FACTOR_1 VEDU_VCTRL_FME_RDO_FACTOR_1 ;
    volatile U_VEDU_VCTRL_FME_RDO_FACTOR_2 VEDU_VCTRL_FME_RDO_FACTOR_2 ;
    volatile U_VEDU_PME_NEW_COST VEDU_PME_NEW_COST ;
    volatile U_VEDU_PME_COST_OFFSET VEDU_PME_COST_OFFSET ;
    volatile unsigned int VEDU_RESERVED_062C ;
    volatile U_VEDU_PME_INTRABLK_DET VEDU_PME_INTRABLK_DET ;
    volatile U_VEDU_PME_INTRABLK_DET_THR VEDU_PME_INTRABLK_DET_THR ;
    volatile U_VEDU_PME_SKIN_THR VEDU_PME_SKIN_THR ;
    volatile U_VEDU_PME_STRONG_EDGE VEDU_PME_STRONG_EDGE ;
    volatile U_VEDU_PME_LARGE_MOVE_THR VEDU_PME_LARGE_MOVE_THR ;
    volatile U_VEDU_PME_INTER_STRONG_EDGE VEDU_PME_INTER_STRONG_EDGE ;
    volatile U_VEDU_PME_CHROMA_STRONG_EDGE VEDU_PME_CHROMA_STRONG_EDGE ;
    volatile U_VEDU_CHROMA_SAD_THR VEDU_CHROMA_SAD_THR ;
    volatile U_VEDU_CHROMA_FG_THR VEDU_CHROMA_FG_THR ;
    volatile U_VEDU_CHROMA_BG_THR VEDU_CHROMA_BG_THR ;
    volatile U_VEDU_CHROMA_SUM_FG_THR VEDU_CHROMA_SUM_FG_THR ;
    volatile U_VEDU_CHROMA_SUM_BG_THR VEDU_CHROMA_SUM_BG_THR ;
    volatile U_VEDU_CHROMA_FG_COUNT_THR VEDU_CHROMA_FG_COUNT_THR ;
    volatile U_VEDU_CHROMA_BG_COUNT_THR VEDU_CHROMA_BG_COUNT_THR ;
    volatile U_VEDU_PME_MOVE_SCENE_THR VEDU_PME_MOVE_SCENE_THR ;
    volatile U_VEDU_PME_NEW_MADI_TH VEDU_PME_NEW_MADI_TH ;
    volatile U_VEDU_PME_NEW_LAMBDA VEDU_PME_NEW_LAMBDA ;
    volatile U_VEDU_VCPI_DBLKCFG VEDU_VCPI_DBLKCFG ;
    volatile U_VEDU_FME_BIAS_COST0 VEDU_FME_BIAS_COST0 ;
    volatile U_VEDU_FME_BIAS_COST1 VEDU_FME_BIAS_COST1 ;
    volatile U_VEDU_MRG_BIAS_COST0 VEDU_MRG_BIAS_COST0 ;
    volatile U_VEDU_MRG_BIAS_COST1 VEDU_MRG_BIAS_COST1 ;
    volatile U_VEDU_MRG_ABS_OFFSET0 VEDU_MRG_ABS_OFFSET0 ;
    volatile U_VEDU_MRG_ABS_OFFSET1 VEDU_MRG_ABS_OFFSET1 ;
    volatile U_VEDU_MRG_ADJ_WEIGHT VEDU_MRG_ADJ_WEIGHT ;
    volatile U_VEDU_INTRA_BIT_WEIGHT VEDU_INTRA_BIT_WEIGHT ;
    volatile U_VEDU_INTRA_RDO_COST_OFFSET_0 VEDU_INTRA_RDO_COST_OFFSET_0 ;
    volatile U_VEDU_INTRA_RDO_COST_OFFSET_1 VEDU_INTRA_RDO_COST_OFFSET_1 ;
    volatile U_VEDU_INTRA_NO_DC_COST_OFFSET_0 VEDU_INTRA_NO_DC_COST_OFFSET_0 ;
    volatile U_VEDU_INTRA_NO_DC_COST_OFFSET_1 VEDU_INTRA_NO_DC_COST_OFFSET_1 ;
    volatile U_VEDU_INTRA_RDO_COST_OFFSET_3 VEDU_INTRA_RDO_COST_OFFSET_3 ;
    volatile U_VEDU_SEL_OFFSET_STRENGTH VEDU_SEL_OFFSET_STRENGTH ;
    volatile unsigned int VEDU_RESERVED_12 ;
    volatile unsigned int reserved_10[19] ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG00 VEDU_QPG_QP_LAMBDA_CTRL_REG00 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG01 VEDU_QPG_QP_LAMBDA_CTRL_REG01 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG02 VEDU_QPG_QP_LAMBDA_CTRL_REG02 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG03 VEDU_QPG_QP_LAMBDA_CTRL_REG03 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG04 VEDU_QPG_QP_LAMBDA_CTRL_REG04 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG05 VEDU_QPG_QP_LAMBDA_CTRL_REG05 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG06 VEDU_QPG_QP_LAMBDA_CTRL_REG06 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG07 VEDU_QPG_QP_LAMBDA_CTRL_REG07 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG08 VEDU_QPG_QP_LAMBDA_CTRL_REG08 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG09 VEDU_QPG_QP_LAMBDA_CTRL_REG09 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG10 VEDU_QPG_QP_LAMBDA_CTRL_REG10 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG11 VEDU_QPG_QP_LAMBDA_CTRL_REG11 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG12 VEDU_QPG_QP_LAMBDA_CTRL_REG12 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG13 VEDU_QPG_QP_LAMBDA_CTRL_REG13 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG14 VEDU_QPG_QP_LAMBDA_CTRL_REG14 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG15 VEDU_QPG_QP_LAMBDA_CTRL_REG15 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG16 VEDU_QPG_QP_LAMBDA_CTRL_REG16 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG17 VEDU_QPG_QP_LAMBDA_CTRL_REG17 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG18 VEDU_QPG_QP_LAMBDA_CTRL_REG18 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG19 VEDU_QPG_QP_LAMBDA_CTRL_REG19 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG20 VEDU_QPG_QP_LAMBDA_CTRL_REG20 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG21 VEDU_QPG_QP_LAMBDA_CTRL_REG21 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG22 VEDU_QPG_QP_LAMBDA_CTRL_REG22 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG23 VEDU_QPG_QP_LAMBDA_CTRL_REG23 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG24 VEDU_QPG_QP_LAMBDA_CTRL_REG24 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG25 VEDU_QPG_QP_LAMBDA_CTRL_REG25 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG26 VEDU_QPG_QP_LAMBDA_CTRL_REG26 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG27 VEDU_QPG_QP_LAMBDA_CTRL_REG27 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG28 VEDU_QPG_QP_LAMBDA_CTRL_REG28 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG29 VEDU_QPG_QP_LAMBDA_CTRL_REG29 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG30 VEDU_QPG_QP_LAMBDA_CTRL_REG30 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG31 VEDU_QPG_QP_LAMBDA_CTRL_REG31 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG32 VEDU_QPG_QP_LAMBDA_CTRL_REG32 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG33 VEDU_QPG_QP_LAMBDA_CTRL_REG33 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG34 VEDU_QPG_QP_LAMBDA_CTRL_REG34 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG35 VEDU_QPG_QP_LAMBDA_CTRL_REG35 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG36 VEDU_QPG_QP_LAMBDA_CTRL_REG36 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG37 VEDU_QPG_QP_LAMBDA_CTRL_REG37 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG38 VEDU_QPG_QP_LAMBDA_CTRL_REG38 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG39 VEDU_QPG_QP_LAMBDA_CTRL_REG39 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG40 VEDU_QPG_QP_LAMBDA_CTRL_REG40 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG41 VEDU_QPG_QP_LAMBDA_CTRL_REG41 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG42 VEDU_QPG_QP_LAMBDA_CTRL_REG42 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG43 VEDU_QPG_QP_LAMBDA_CTRL_REG43 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG44 VEDU_QPG_QP_LAMBDA_CTRL_REG44 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG45 VEDU_QPG_QP_LAMBDA_CTRL_REG45 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG46 VEDU_QPG_QP_LAMBDA_CTRL_REG46 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG47 VEDU_QPG_QP_LAMBDA_CTRL_REG47 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG48 VEDU_QPG_QP_LAMBDA_CTRL_REG48 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG49 VEDU_QPG_QP_LAMBDA_CTRL_REG49 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG50 VEDU_QPG_QP_LAMBDA_CTRL_REG50 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG51 VEDU_QPG_QP_LAMBDA_CTRL_REG51 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG52 VEDU_QPG_QP_LAMBDA_CTRL_REG52 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG53 VEDU_QPG_QP_LAMBDA_CTRL_REG53 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG54 VEDU_QPG_QP_LAMBDA_CTRL_REG54 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG55 VEDU_QPG_QP_LAMBDA_CTRL_REG55 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG56 VEDU_QPG_QP_LAMBDA_CTRL_REG56 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG57 VEDU_QPG_QP_LAMBDA_CTRL_REG57 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG58 VEDU_QPG_QP_LAMBDA_CTRL_REG58 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG59 VEDU_QPG_QP_LAMBDA_CTRL_REG59 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG60 VEDU_QPG_QP_LAMBDA_CTRL_REG60 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG61 VEDU_QPG_QP_LAMBDA_CTRL_REG61 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG62 VEDU_QPG_QP_LAMBDA_CTRL_REG62 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG63 VEDU_QPG_QP_LAMBDA_CTRL_REG63 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG64 VEDU_QPG_QP_LAMBDA_CTRL_REG64 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG65 VEDU_QPG_QP_LAMBDA_CTRL_REG65 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG66 VEDU_QPG_QP_LAMBDA_CTRL_REG66 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG67 VEDU_QPG_QP_LAMBDA_CTRL_REG67 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG68 VEDU_QPG_QP_LAMBDA_CTRL_REG68 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG69 VEDU_QPG_QP_LAMBDA_CTRL_REG69 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG70 VEDU_QPG_QP_LAMBDA_CTRL_REG70 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG71 VEDU_QPG_QP_LAMBDA_CTRL_REG71 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG72 VEDU_QPG_QP_LAMBDA_CTRL_REG72 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG73 VEDU_QPG_QP_LAMBDA_CTRL_REG73 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG74 VEDU_QPG_QP_LAMBDA_CTRL_REG74 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG75 VEDU_QPG_QP_LAMBDA_CTRL_REG75 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG76 VEDU_QPG_QP_LAMBDA_CTRL_REG76 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG77 VEDU_QPG_QP_LAMBDA_CTRL_REG77 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG78 VEDU_QPG_QP_LAMBDA_CTRL_REG78 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG79 VEDU_QPG_QP_LAMBDA_CTRL_REG79 ;
    volatile U_VEDU_IME_RDOCFG VEDU_IME_RDOCFG ;
    volatile U_VEDU_MRG_FORCE_ZERO_EN VEDU_MRG_FORCE_ZERO_EN ;
    volatile unsigned int VEDU_VCPI_INTRA8_LOW_POWER ;
    volatile U_VEDU_VCPI_LOW_POWER VEDU_VCPI_LOW_POWER ;
    volatile U_VEDU_IME_INTER_MODE VEDU_IME_INTER_MODE ;
    volatile U_VEDU_VCPI_PRE_JUDGE_EXT_EN VEDU_VCPI_PRE_JUDGE_EXT_EN ;
    volatile unsigned int VEDU_RESERVED_13 ;
    volatile unsigned int reserved_11[9] ;
    volatile U_VEDU_PME_SW_ADAPT_EN VEDU_PME_SW_ADAPT_EN ;
    volatile U_VEDU_PME_WINDOW_SIZE0_L0 VEDU_PME_WINDOW_SIZE0_L0 ;
    volatile unsigned int reserved_12 ;
    volatile U_VEDU_PME_SKIP_PRE VEDU_PME_SKIP_PRE ;
    volatile U_VEDU_PME_PBLK_PRE1 VEDU_PME_PBLK_PRE1 ;
    volatile U_VEDU_VCPI_PRE_JUDGE_COST_THR VEDU_VCPI_PRE_JUDGE_COST_THR ;
    volatile U_VEDU_VCPI_IBLK_PRE_MV_THR VEDU_VCPI_IBLK_PRE_MV_THR ;
    volatile U_VEDU_PME_IBLK_COST_THR VEDU_PME_IBLK_COST_THR ;
    volatile U_VEDU_PME_TR_WEIGHTX VEDU_PME_TR_WEIGHTX ;
    volatile U_VEDU_PME_TR_WEIGHTY VEDU_PME_TR_WEIGHTY ;
    volatile U_VEDU_PME_SR_WEIGHT VEDU_PME_SR_WEIGHT ;
    volatile U_VEDU_PME_INTRA_LOWPOW VEDU_PME_INTRA_LOWPOW ;
    volatile U_VEDU_IME_FME_LPOW_THR VEDU_IME_FME_LPOW_THR ;
    volatile U_VEDU_PME_SKIP_FLAG VEDU_PME_SKIP_FLAG ;
    volatile U_VEDU_PME_PSW_LPW VEDU_PME_PSW_LPW ;
    volatile U_VEDU_PME_PBLK_PRE2 VEDU_PME_PBLK_PRE2 ;
    volatile U_VEDU_IME_LAYER3TO2_THR VEDU_IME_LAYER3TO2_THR ;
    volatile U_VEDU_IME_LAYER3TO2_THR1 VEDU_IME_LAYER3TO2_THR1 ;
    volatile U_VEDU_IME_LAYER3TO1_THR VEDU_IME_LAYER3TO1_THR ;
    volatile U_VEDU_IME_LAYER3TO1_THR1 VEDU_IME_LAYER3TO1_THR1 ;
    volatile U_VEDU_FME_PU64_LWP VEDU_FME_PU64_LWP ;
    volatile U_VEDU_MRG_FORCE_SKIP_EN VEDU_MRG_FORCE_SKIP_EN ;
    volatile U_VEDU_INTRA_CFG VEDU_INTRA_CFG ;
    volatile U_VEDU_INTRA_LOW_POW VEDU_INTRA_LOW_POW ;
    volatile unsigned int VEDU_VCPI_QPINFO_ADDR_L ;
    volatile unsigned int VEDU_VCPI_QPINFO_ADDR_H ;
    volatile unsigned int VEDU_RESERVED_14 ;
    volatile unsigned int reserved_13[5] ;
    volatile unsigned int VEDU_VCPI_TUNLCELL_ADDR_L ;
    volatile unsigned int VEDU_VCPI_TUNLCELL_ADDR_H ;
    volatile unsigned int VEDU_VCPI_SRC_YADDR_L ;
    volatile unsigned int VEDU_VCPI_SRC_YADDR_H ;
    volatile unsigned int VEDU_VCPI_SRC_EXT_YADDR_L ;
    volatile unsigned int VEDU_VCPI_SRC_EXT_YADDR_H ;
    volatile unsigned int VEDU_VCPI_SRC_CADDR_L ;
    volatile unsigned int VEDU_VCPI_SRC_CADDR_H ;
    volatile unsigned int VEDU_VCPI_SRC_EXT_CADDR_L ;
    volatile unsigned int VEDU_VCPI_SRC_EXT_CADDR_H ;
    volatile unsigned int VEDU_VCPI_SRC_VADDR_L ;
    volatile unsigned int VEDU_VCPI_SRC_VADDR_H ;
    volatile unsigned int VEDU_VCPI_YH_ADDR_L ;
    volatile unsigned int VEDU_VCPI_YH_ADDR_H ;
    volatile unsigned int VEDU_VCPI_CH_ADDR_L ;
    volatile unsigned int VEDU_VCPI_CH_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFY_L0_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFY_L0_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFC_L0_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFC_L0_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFYH_L0_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFYH_L0_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFCH_L0_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFCH_L0_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFY_L1_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFY_L1_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFC_L1_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFC_L1_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFYH_L1_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFYH_L1_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFCH_L1_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFCH_L1_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REC_YADDR_L ;
    volatile unsigned int VEDU_VCPI_REC_YADDR_H ;
    volatile unsigned int VEDU_VCPI_REC_CADDR_L ;
    volatile unsigned int VEDU_VCPI_REC_CADDR_H ;
    volatile unsigned int VEDU_VCPI_REC_YH_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REC_YH_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REC_CH_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REC_CH_ADDR_H ;
    volatile unsigned int VEDU_VCPI_PMELD_L0_ADDR_L ;
    volatile unsigned int VEDU_VCPI_PMELD_L0_ADDR_H ;
    volatile unsigned int VEDU_VCPI_PMELD_L1_ADDR_L ;
    volatile unsigned int VEDU_VCPI_PMELD_L1_ADDR_H ;
    volatile unsigned int VEDU_VCPI_PMEST_ADDR_L ;
    volatile unsigned int VEDU_VCPI_PMEST_ADDR_H ;
    volatile unsigned int VEDU_VCPI_NBI_MVST_ADDR_L ;
    volatile unsigned int VEDU_VCPI_NBI_MVST_ADDR_H ;
    volatile unsigned int VEDU_VCPI_NBI_MVLD_ADDR_L ;
    volatile unsigned int VEDU_VCPI_NBI_MVLD_ADDR_H ;
    volatile unsigned int VEDU_VCPI_INFORLD_MV_ADDR_L ;
    volatile unsigned int VEDU_VCPI_INFORLD_MV_ADDR_H ;
    volatile unsigned int VEDU_VCPI_INFORLD_MV_STAT_ADDR_L ;
    volatile unsigned int VEDU_VCPI_INFORLD_MV_STAT_ADDR_H ;
    volatile unsigned int VEDU_VCPI_INFORLD_FEATURE_DETECT_ADDR_L ;
    volatile unsigned int VEDU_VCPI_INFORLD_FEATURE_DETECT_ADDR_H ;
    volatile unsigned int VEDU_VCPI_LAST_INFORLD_FEATURE_DETECT_ADDR_L ;
    volatile unsigned int VEDU_VCPI_LAST_INFORLD_FEATURE_DETECT_ADDR_H ;
    volatile U_VEDU_VCPI_INFORLD_MV_STRIDE VEDU_VCPI_INFORLD_MV_STRIDE ;
    volatile U_VEDU_VCPI_INFORLD_FEATURE_DETECT_STRIDE VEDU_VCPI_INFORLD_FEATURE_DETECT_STRIDE ;
    volatile unsigned int VEDU_VCPI_INFORLD_MV_CONFIDENCE_ADDR_L ;
    volatile unsigned int VEDU_VCPI_INFORLD_MV_CONFIDENCE_ADDR_H ;
    volatile unsigned int VEDU_VCPI_QPGLD_INF_ADDR_L ;
    volatile unsigned int VEDU_VCPI_QPGLD_INF_ADDR_H ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT0 VEDU_VCPI_SRDO_MAX_WEIGHT0 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT1 VEDU_VCPI_SRDO_MAX_WEIGHT1 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT2 VEDU_VCPI_SRDO_MAX_WEIGHT2 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT3 VEDU_VCPI_SRDO_MAX_WEIGHT3 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT4 VEDU_VCPI_SRDO_MAX_WEIGHT4 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT5 VEDU_VCPI_SRDO_MAX_WEIGHT5 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT6 VEDU_VCPI_SRDO_MAX_WEIGHT6 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT7 VEDU_VCPI_SRDO_MAX_WEIGHT7 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT8 VEDU_VCPI_SRDO_MAX_WEIGHT8 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT9 VEDU_VCPI_SRDO_MAX_WEIGHT9 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT10 VEDU_VCPI_SRDO_MAX_WEIGHT10 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT11 VEDU_VCPI_SRDO_MAX_WEIGHT11 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT12 VEDU_VCPI_SRDO_MAX_WEIGHT12 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT13 VEDU_VCPI_SRDO_MAX_WEIGHT13 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT14 VEDU_VCPI_SRDO_MAX_WEIGHT14 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT15 VEDU_VCPI_SRDO_MAX_WEIGHT15 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT16 VEDU_VCPI_SRDO_MAX_WEIGHT16 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT17 VEDU_VCPI_SRDO_MAX_WEIGHT17 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT18 VEDU_VCPI_SRDO_MAX_WEIGHT18 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT19 VEDU_VCPI_SRDO_MAX_WEIGHT19 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT20 VEDU_VCPI_SRDO_MAX_WEIGHT20 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT21 VEDU_VCPI_SRDO_MAX_WEIGHT21 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT22 VEDU_VCPI_SRDO_MAX_WEIGHT22 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT23 VEDU_VCPI_SRDO_MAX_WEIGHT23 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT24 VEDU_VCPI_SRDO_MAX_WEIGHT24 ;
    volatile U_VEDU_VCPI_SRDO_MAX_WEIGHT25 VEDU_VCPI_SRDO_MAX_WEIGHT25 ;
    volatile unsigned int VEDU_RESERVED_0A68 ;
    volatile unsigned int reserved_14[7] ;
    volatile unsigned int VEDU_SKIPWEIGHT_LD_ADDR_L ;
    volatile unsigned int VEDU_SKIPWEIGHT_LD_ADDR_H ;
    volatile unsigned int VEDU_RESERVED_15 ;
    volatile unsigned int reserved_15[27] ;
    volatile U_VEDU_SAO_SSD_AREA0_START VEDU_SAO_SSD_AREA0_START ;
    volatile U_VEDU_SAO_SSD_AREA0_END VEDU_SAO_SSD_AREA0_END ;
    volatile U_VEDU_SAO_SSD_AREA1_START VEDU_SAO_SSD_AREA1_START ;
    volatile U_VEDU_SAO_SSD_AREA1_END VEDU_SAO_SSD_AREA1_END ;
    volatile U_VEDU_SAO_SSD_AREA2_START VEDU_SAO_SSD_AREA2_START ;
    volatile U_VEDU_SAO_SSD_AREA2_END VEDU_SAO_SSD_AREA2_END ;
    volatile U_VEDU_SAO_SSD_AREA3_START VEDU_SAO_SSD_AREA3_START ;
    volatile U_VEDU_SAO_SSD_AREA3_END VEDU_SAO_SSD_AREA3_END ;
    volatile U_VEDU_SAO_SSD_AREA4_START VEDU_SAO_SSD_AREA4_START ;
    volatile U_VEDU_SAO_SSD_AREA4_END VEDU_SAO_SSD_AREA4_END ;
    volatile U_VEDU_SAO_SSD_AREA5_START VEDU_SAO_SSD_AREA5_START ;
    volatile U_VEDU_SAO_SSD_AREA5_END VEDU_SAO_SSD_AREA5_END ;
    volatile U_VEDU_SAO_SSD_AREA6_START VEDU_SAO_SSD_AREA6_START ;
    volatile U_VEDU_SAO_SSD_AREA6_END VEDU_SAO_SSD_AREA6_END ;
    volatile U_VEDU_SAO_SSD_AREA7_START VEDU_SAO_SSD_AREA7_START ;
    volatile U_VEDU_SAO_SSD_AREA7_END VEDU_SAO_SSD_AREA7_END ;
    volatile unsigned int VEDU_RESERVED_16 ;
    volatile unsigned int reserved_16[15] ;
    volatile U_VEDU_VCPI_STRIDE VEDU_VCPI_STRIDE ;
    volatile U_VEDU_VCPI_EXT_STRIDE VEDU_VCPI_EXT_STRIDE ;
    volatile U_VEDU_VCPI_REF_L0_STRIDE VEDU_VCPI_REF_L0_STRIDE ;
    volatile U_VEDU_VCPI_REF_L1_STRIDE VEDU_VCPI_REF_L1_STRIDE ;
    volatile U_VEDU_VCPI_REC_STRIDE VEDU_VCPI_REC_STRIDE ;
    volatile unsigned int VEDU_VCPI_PMEST_STRIDE ;
    volatile unsigned int VEDU_VCPI_PMELD_STRIDE ;
    volatile U_VEDU_VCPI_REC_HEADER_STRIDE VEDU_VCPI_REC_HEADER_STRIDE ;
    volatile U_VEDU_VCPI_REF_L0_HEADER_STRIDE VEDU_VCPI_REF_L0_HEADER_STRIDE ;
    volatile U_VEDU_VCPI_REF_L1_HEADER_STRIDE VEDU_VCPI_REF_L1_HEADER_STRIDE ;
    volatile U_VEDU_VCPI_QPINFO_LD_ST_STRIDE VEDU_VCPI_QPINFO_LD_ST_STRIDE ;
    volatile unsigned int VEDU_RESERVED_17 ;
    volatile unsigned int reserved_17[20] ;
    volatile U_VEDU_ME_ET_THR VEDU_ME_ET_THR ;
    volatile U_VEDU_ME_ET_THR_ME_STAT VEDU_ME_ET_THR_ME_STAT ;
    volatile U_VEDU_IME_REF_BUF_WORD_NUM VEDU_IME_REF_BUF_WORD_NUM ;
    volatile U_VEDU_IME_INTERPOLATION_FLAG VEDU_IME_INTERPOLATION_FLAG ;
    volatile U_VEDU_ME_MAX_REGION VEDU_ME_MAX_REGION ;
    volatile U_VEDU_ME_ADD1_RANDOM_POINT_LIST VEDU_ME_ADD1_RANDOM_POINT_LIST ;
    volatile U_VEDU_ME_ADD2_RANDOM_POINT_LIST VEDU_ME_ADD2_RANDOM_POINT_LIST ;
    volatile U_VEDU_ME_ADD3_RANDOM_POINT_LIST0 VEDU_ME_ADD3_RANDOM_POINT_LIST0 ;
    volatile U_VEDU_ME_ADD3_RANDOM_POINT_LIST1 VEDU_ME_ADD3_RANDOM_POINT_LIST1 ;
    volatile U_VEDU_ME_ADD4_RANDOM_POINT_LIST0 VEDU_ME_ADD4_RANDOM_POINT_LIST0 ;
    volatile U_VEDU_ME_ADD4_RANDOM_POINT_LIST1 VEDU_ME_ADD4_RANDOM_POINT_LIST1 ;
    volatile U_VEDU_ME_ADD5_RANDOM_POINT_LIST0 VEDU_ME_ADD5_RANDOM_POINT_LIST0 ;
    volatile U_VEDU_ME_ADD5_RANDOM_POINT_LIST1 VEDU_ME_ADD5_RANDOM_POINT_LIST1 ;
    volatile U_VEDU_ME_ADD5_RANDOM_POINT_LIST2 VEDU_ME_ADD5_RANDOM_POINT_LIST2 ;
    volatile U_VEDU_ME_ADD6_RANDOM_POINT_LIST0 VEDU_ME_ADD6_RANDOM_POINT_LIST0 ;
    volatile U_VEDU_ME_ADD6_RANDOM_POINT_LIST1 VEDU_ME_ADD6_RANDOM_POINT_LIST1 ;
    volatile U_VEDU_ME_ADD6_RANDOM_POINT_LIST2 VEDU_ME_ADD6_RANDOM_POINT_LIST2 ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST0 VEDU_ME_ADD7_RANDOM_POINT_LIST0 ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST1 VEDU_ME_ADD7_RANDOM_POINT_LIST1 ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST2 VEDU_ME_ADD7_RANDOM_POINT_LIST2 ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST3 VEDU_ME_ADD7_RANDOM_POINT_LIST3 ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST0 VEDU_ME_ADD8_RANDOM_POINT_LIST0 ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST1 VEDU_ME_ADD8_RANDOM_POINT_LIST1 ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST2 VEDU_ME_ADD8_RANDOM_POINT_LIST2 ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST3 VEDU_ME_ADD8_RANDOM_POINT_LIST3 ;
    volatile unsigned int VEDU_ME_TMV_SCALE ;
    volatile U_VEDU_ME_TMV_EN VEDU_ME_TMV_EN ;
    volatile unsigned int VEDU_CABAC_NAL_UNIT_HEADL ;
    volatile U_VEDU_ME_ADD1_RANDOM_POINT_LIST_B VEDU_ME_ADD1_RANDOM_POINT_LIST_B ;
    volatile U_VEDU_ME_ADD2_RANDOM_POINT_LIST_B VEDU_ME_ADD2_RANDOM_POINT_LIST_B ;
    volatile U_VEDU_ME_ADD3_RANDOM_POINT_LIST0_B VEDU_ME_ADD3_RANDOM_POINT_LIST0_B ;
    volatile U_VEDU_ME_ADD3_RANDOM_POINT_LIST1_B VEDU_ME_ADD3_RANDOM_POINT_LIST1_B ;
    volatile U_VEDU_ME_ADD4_RANDOM_POINT_LIST0_B VEDU_ME_ADD4_RANDOM_POINT_LIST0_B ;
    volatile U_VEDU_ME_ADD4_RANDOM_POINT_LIST1_B VEDU_ME_ADD4_RANDOM_POINT_LIST1_B ;
    volatile U_VEDU_ME_ADD5_RANDOM_POINT_LIST0_B VEDU_ME_ADD5_RANDOM_POINT_LIST0_B ;
    volatile U_VEDU_ME_ADD5_RANDOM_POINT_LIST1_B VEDU_ME_ADD5_RANDOM_POINT_LIST1_B ;
    volatile U_VEDU_ME_ADD5_RANDOM_POINT_LIST2_B VEDU_ME_ADD5_RANDOM_POINT_LIST2_B ;
    volatile U_VEDU_ME_ADD6_RANDOM_POINT_LIST0_B VEDU_ME_ADD6_RANDOM_POINT_LIST0_B ;
    volatile U_VEDU_ME_ADD6_RANDOM_POINT_LIST1_B VEDU_ME_ADD6_RANDOM_POINT_LIST1_B ;
    volatile U_VEDU_ME_ADD6_RANDOM_POINT_LIST2_B VEDU_ME_ADD6_RANDOM_POINT_LIST2_B ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST0_B VEDU_ME_ADD7_RANDOM_POINT_LIST0_B ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST1_B VEDU_ME_ADD7_RANDOM_POINT_LIST1_B ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST2_B VEDU_ME_ADD7_RANDOM_POINT_LIST2_B ;
    volatile U_VEDU_ME_ADD7_RANDOM_POINT_LIST3_B VEDU_ME_ADD7_RANDOM_POINT_LIST3_B ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST0_B VEDU_ME_ADD8_RANDOM_POINT_LIST0_B ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST1_B VEDU_ME_ADD8_RANDOM_POINT_LIST1_B ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST2_B VEDU_ME_ADD8_RANDOM_POINT_LIST2_B ;
    volatile U_VEDU_ME_ADD8_RANDOM_POINT_LIST3_B VEDU_ME_ADD8_RANDOM_POINT_LIST3_B ;
    volatile unsigned int VEDU_ME_TMV_SCALE_1 ;
    volatile unsigned int VEDU_ME_TMV_SCALE_2 ;
    volatile unsigned int VEDU_ME_TMV_SCALE_3 ;
    volatile unsigned int VEDU_ISPLD_REF1_CENTER_SCALE ;
    volatile unsigned int VEDU_RESERVED_17_new ;
    volatile unsigned int reserved_18[11] ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT0 VEDU_VCPI_SRDO_MIN_WEIGHT0 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT1 VEDU_VCPI_SRDO_MIN_WEIGHT1 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT2 VEDU_VCPI_SRDO_MIN_WEIGHT2 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT3 VEDU_VCPI_SRDO_MIN_WEIGHT3 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT4 VEDU_VCPI_SRDO_MIN_WEIGHT4 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT5 VEDU_VCPI_SRDO_MIN_WEIGHT5 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT6 VEDU_VCPI_SRDO_MIN_WEIGHT6 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT7 VEDU_VCPI_SRDO_MIN_WEIGHT7 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT8 VEDU_VCPI_SRDO_MIN_WEIGHT8 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT9 VEDU_VCPI_SRDO_MIN_WEIGHT9 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT10 VEDU_VCPI_SRDO_MIN_WEIGHT10 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT11 VEDU_VCPI_SRDO_MIN_WEIGHT11 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT12 VEDU_VCPI_SRDO_MIN_WEIGHT12 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT13 VEDU_VCPI_SRDO_MIN_WEIGHT13 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT14 VEDU_VCPI_SRDO_MIN_WEIGHT14 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT15 VEDU_VCPI_SRDO_MIN_WEIGHT15 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT16 VEDU_VCPI_SRDO_MIN_WEIGHT16 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT17 VEDU_VCPI_SRDO_MIN_WEIGHT17 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT18 VEDU_VCPI_SRDO_MIN_WEIGHT18 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT19 VEDU_VCPI_SRDO_MIN_WEIGHT19 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT20 VEDU_VCPI_SRDO_MIN_WEIGHT20 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT21 VEDU_VCPI_SRDO_MIN_WEIGHT21 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT22 VEDU_VCPI_SRDO_MIN_WEIGHT22 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT23 VEDU_VCPI_SRDO_MIN_WEIGHT23 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT24 VEDU_VCPI_SRDO_MIN_WEIGHT24 ;
    volatile U_VEDU_VCPI_SRDO_MIN_WEIGHT25 VEDU_VCPI_SRDO_MIN_WEIGHT25 ;
    volatile unsigned int VEDU_RESERVED_0D68 ;
    volatile unsigned int reserved_19[16] ;
    volatile unsigned int VEDU_VCPI_REFY_DOWNBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFY_DOWNBOUNDARY_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFYH_DOWNBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFYH_DOWNBOUNDARY_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFC_DOWNBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFC_DOWNBOUNDARY_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFCH_DOWNBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFCH_DOWNBOUNDARY_ADDR_H ;
    volatile U_VEDU_VCPI_REF_DOWNBOUNDARY_STRIDE VEDU_VCPI_REF_DOWNBOUNDARY_STRIDE ;
    volatile U_VEDU_VCPI_REF_DOWNBOUNDARY_HEADER_STRIDE VEDU_VCPI_REF_DOWNBOUNDARY_HEADER_STRIDE ;
    volatile unsigned int VEDU_VCPI_PACKET_RESERVED_INFO_L ;
    volatile unsigned int VEDU_VCPI_PACKET_RESERVED_INFO_M ;
    volatile unsigned int VEDU_VCPI_PACKET_RESERVED_INFO_H ;
    volatile unsigned int VEDU_RESERVED_18 ;
    volatile unsigned int reserved_20[7] ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG80 VEDU_QPG_QP_LAMBDA_CTRL_REG80 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG81 VEDU_QPG_QP_LAMBDA_CTRL_REG81 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG82 VEDU_QPG_QP_LAMBDA_CTRL_REG82 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG83 VEDU_QPG_QP_LAMBDA_CTRL_REG83 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG84 VEDU_QPG_QP_LAMBDA_CTRL_REG84 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG85 VEDU_QPG_QP_LAMBDA_CTRL_REG85 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG86 VEDU_QPG_QP_LAMBDA_CTRL_REG86 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG87 VEDU_QPG_QP_LAMBDA_CTRL_REG87 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG88 VEDU_QPG_QP_LAMBDA_CTRL_REG88 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG89 VEDU_QPG_QP_LAMBDA_CTRL_REG89 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG90 VEDU_QPG_QP_LAMBDA_CTRL_REG90 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG91 VEDU_QPG_QP_LAMBDA_CTRL_REG91 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG92 VEDU_QPG_QP_LAMBDA_CTRL_REG92 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG93 VEDU_QPG_QP_LAMBDA_CTRL_REG93 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG94 VEDU_QPG_QP_LAMBDA_CTRL_REG94 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG95 VEDU_QPG_QP_LAMBDA_CTRL_REG95 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG96 VEDU_QPG_QP_LAMBDA_CTRL_REG96 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG97 VEDU_QPG_QP_LAMBDA_CTRL_REG97 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG98 VEDU_QPG_QP_LAMBDA_CTRL_REG98 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG99 VEDU_QPG_QP_LAMBDA_CTRL_REG99 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG100 VEDU_QPG_QP_LAMBDA_CTRL_REG100 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG101 VEDU_QPG_QP_LAMBDA_CTRL_REG101 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG102 VEDU_QPG_QP_LAMBDA_CTRL_REG102 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG103 VEDU_QPG_QP_LAMBDA_CTRL_REG103 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG104 VEDU_QPG_QP_LAMBDA_CTRL_REG104 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG105 VEDU_QPG_QP_LAMBDA_CTRL_REG105 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG106 VEDU_QPG_QP_LAMBDA_CTRL_REG106 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG107 VEDU_QPG_QP_LAMBDA_CTRL_REG107 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG108 VEDU_QPG_QP_LAMBDA_CTRL_REG108 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG109 VEDU_QPG_QP_LAMBDA_CTRL_REG109 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG110 VEDU_QPG_QP_LAMBDA_CTRL_REG110 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG111 VEDU_QPG_QP_LAMBDA_CTRL_REG111 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG112 VEDU_QPG_QP_LAMBDA_CTRL_REG112 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG113 VEDU_QPG_QP_LAMBDA_CTRL_REG113 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG114 VEDU_QPG_QP_LAMBDA_CTRL_REG114 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG115 VEDU_QPG_QP_LAMBDA_CTRL_REG115 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG116 VEDU_QPG_QP_LAMBDA_CTRL_REG116 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG117 VEDU_QPG_QP_LAMBDA_CTRL_REG117 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG118 VEDU_QPG_QP_LAMBDA_CTRL_REG118 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG119 VEDU_QPG_QP_LAMBDA_CTRL_REG119 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG120 VEDU_QPG_QP_LAMBDA_CTRL_REG120 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG121 VEDU_QPG_QP_LAMBDA_CTRL_REG121 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG122 VEDU_QPG_QP_LAMBDA_CTRL_REG122 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG123 VEDU_QPG_QP_LAMBDA_CTRL_REG123 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG124 VEDU_QPG_QP_LAMBDA_CTRL_REG124 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG125 VEDU_QPG_QP_LAMBDA_CTRL_REG125 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG126 VEDU_QPG_QP_LAMBDA_CTRL_REG126 ;
    volatile U_VEDU_QPG_QP_LAMBDA_CTRL_REG127 VEDU_QPG_QP_LAMBDA_CTRL_REG127 ;
    volatile U_VEDU_VCPI_LUMA_START_ROWNUM VEDU_VCPI_LUMA_START_ROWNUM ;
    volatile U_VEDU_VCPI_CURLD_START_SLICENUM VEDU_VCPI_CURLD_START_SLICENUM ;
    volatile U_VEDU_VCPI_REFLD_BOUNDARY_MOD VEDU_VCPI_REFLD_BOUNDARY_MOD ;
    volatile unsigned int VEDU_VCPI_REFY_UPBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFY_UPBOUNDARY_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFYH_UPBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFYH_UPBOUNDARY_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFC_UPBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFC_UPBOUNDARY_ADDR_H ;
    volatile unsigned int VEDU_VCPI_REFCH_UPBOUNDARY_ADDR_L ;
    volatile unsigned int VEDU_VCPI_REFCH_UPBOUNDARY_ADDR_H ;
    volatile U_VEDU_VCPI_REF_UPBOUNDARY_STRIDE VEDU_VCPI_REF_UPBOUNDARY_STRIDE ;
    volatile U_VEDU_VCPI_REF_UPBOUNFARY_HEADER_STRIDE VEDU_VCPI_REF_UPBOUNFARY_HEADER_STRIDE ;
    volatile U_VEDU_VCPI_PRIVATE_SLCHDR_PART0 VEDU_VCPI_PRIVATE_SLCHDR_PART0 ;
    volatile unsigned int VEDU_VCPI_PRIVATE_SLCHDR_PART1 ;
    volatile U_VEDU_VCPI_LOWLATENCY_SLICE_INTEN VEDU_VCPI_LOWLATENCY_SLICE_INTEN ;
    volatile unsigned int VEDU_VCPI_STRMADDR_L_NEW[16] ;
    volatile unsigned int VEDU_VCPI_STRMADDR_H_NEW[16] ;
    volatile unsigned int VEDU_VCPI_STRMBUFLEN_NEW[16] ;
    volatile unsigned int VEDU_VCPI_SLCINFOADDR_L_NEW ;
    volatile unsigned int VEDU_VCPI_SLCINFOADDR_H_NEW ;
    volatile U_VEDU_VCTRL_INTRAPU4_REFRESH_START VEDU_VCTRL_INTRAPU4_REFRESH_START ;
    volatile U_VEDU_VCTRL_INTRAPU4_REFRESH_END VEDU_VCTRL_INTRAPU4_REFRESH_END ;
    volatile U_VEDU_VCPI_CMDLST_GRP_NUM VEDU_VCPI_CMDLST_GRP_NUM ;
    volatile U_VEDU_VCPI_CMDLST_SOFT_FINISH_NUM VEDU_VCPI_CMDLST_SOFT_FINISH_NUM ;
    volatile U_VEDU_VCPI_FORCE_ZEROMV VEDU_VCPI_FORCE_ZEROMV ;
    volatile U_VEDU_VCPI_FORCE_INTRAPU32_NUM VEDU_VCPI_FORCE_INTRAPU32_NUM ;
    volatile unsigned int VEDU_VCPI_VLCST_RAL ;
    volatile unsigned int VEDU_VCPI_VLCST_SAL ;
    volatile U_VEDU_VCPI_VLCST_RAH_SAH VEDU_VCPI_VLCST_RAH_SAH ;
    volatile U_VEDU_VCPI_PACKET_INFO VEDU_VCPI_PACKET_INFO ;
    volatile U_VEDU_SECURE_SET VEDU_SECURE_SET ;
    volatile unsigned int VEDU_RESERVED_21 ;
    volatile unsigned int reserved_21[2] ;
    volatile unsigned int VEDU_RESERVED_22[2048] ;
} S_VEDU_CONFIG_REGS_TYPE;
#endif
