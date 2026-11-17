#ifndef __H266_FRM_C_UNION_DEFINE_H__
#define __H266_FRM_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int sps_chroma_format_idc : 2 ;
        unsigned int sps_explicit_mts_inter_enabled_flag : 1 ;
        unsigned int sps_explicit_mts_intra_enabled_flag : 1 ;
        unsigned int sps_mts_enabled_flag : 1 ;
        unsigned int sps_lfnst_enabled_flag : 1 ;
        unsigned int sps_transform_skip_enabled_flag : 1 ;
        unsigned int sps_joint_cbcr_enabled_flag : 1 ;
        unsigned int sps_mmvd_enabled_flag : 1 ;
        unsigned int sps_gpm_enabled_flag : 1 ;
        unsigned int sps_ciip_enabled_flag : 1 ;
        unsigned int sps_sbt_enabled_flag : 1 ;
        unsigned int sps_bcw_enabled_flag : 1 ;
        unsigned int sps_affine_amvr_enabled_flag : 1 ;
        unsigned int sps_smvd_enabled_flag : 1 ;
        unsigned int sps_6param_affine_enabled_flag : 1 ;
        unsigned int sps_affine_enabled_flag : 1 ;
        unsigned int sps_amvr_enabled_flag : 1 ;
        unsigned int sps_max_luma_transform_size_64_flag : 1 ;
        unsigned int sps_isp_enabled_flag : 1 ;
        unsigned int sps_mrl_enabled_flag : 1 ;
        unsigned int sps_mip_enabled_flag : 1 ;
        unsigned int sps_bdpcm_enabled_flag : 1 ;
        unsigned int sps_act_enabled_flag : 1 ;
        unsigned int sps_palette_enabled_flag : 1 ;
        unsigned int sps_ibc_enabled_flag : 1 ;
        unsigned int sps_qtbtt_dual_tree_intra_flag : 1 ;
        unsigned int sps_entropy_coding_sync_enabled_flag : 1 ;
        unsigned int sps_chroma_vertical_collocated_flag : 1 ;
        unsigned int sps_chroma_horizontal_collocated_flag : 1 ;
        unsigned int sps_cclm_enabled_flag : 1 ;
        unsigned int sps_temporal_mvp_enabled_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D0;
typedef union {
    struct {
        unsigned int reserved_0 : 4 ;
        unsigned int reserved_1 : 4 ;
        unsigned int pps_chroma_qp_offset_list_len_minus1 : 4 ;
        unsigned int ph_intra_slice_allowed_flag : 1 ;
        unsigned int ph_inter_slice_allowed_flag : 1 ;
        unsigned int ph_mmvd_fullpel_only_flag : 1 ;
        unsigned int sps_log2_parallel_merge_level_minus2 : 3 ;
        unsigned int MaxNumIbcMergeCand : 3 ;
        unsigned int MaxNumMergeCand : 3 ;
        unsigned int MaxNumGpmMergeCand : 3 ;
        unsigned int MaxNumSubblockMergeCand : 3 ;
        unsigned int ph_temporal_mvp_enabled_flag : 1 ;
        unsigned int sps_sbtmvp_enabled_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D1;
typedef union {
    struct {
        unsigned int sps_log2_ctu_size_minus5 : 2 ;
        unsigned int sps_log2_min_luma_coding_block_size_minus2 : 4 ;
        unsigned int BitDepth : 4 ;
        unsigned int reserved_0 : 8 ;
        unsigned int sps_same_qp_table_for_chroma_flag : 1 ;
        unsigned int sps_virtual_boundaries_enabled_flag : 1 ;
        unsigned int sps_num_subpics_minus1 : 10 ;
        unsigned int sps_res_change_in_clvs_allowed_flag : 1 ;
        unsigned int sps_ref_pic_resampling_enabled_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D2;
typedef union {
    struct {
        unsigned int pps_int_qp : 8 ;
        unsigned int ph_mvd_l1_zero_flag : 1 ;
        unsigned int pps_cu_qp_delta_enabled_flag : 1 ;
        unsigned int sps_ladf_enabled_flag : 1 ;
        unsigned int sps_min_qp_prime_ts : 4 ;
        unsigned int sps_log2_transform_skip_max_size_minus2 : 2 ;
        unsigned int reserved_0 : 5 ;
        unsigned int ph_joint_cbcr_sign_flag : 1 ;
        unsigned int ph_chroma_residual_scale_flag : 1 ;
        unsigned int ph_lmcs_aps_id : 2 ;
        unsigned int lmcs_enabled_flag : 1 ;
        unsigned int sps_scaling_matrix_for_lfnst_disabled_flag : 1 ;
        unsigned int ph_scaling_list_aps_id : 3 ;
        unsigned int explicit_scaling_list_enabled_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D3;
typedef union {
    struct {
        unsigned int log2_diff_max_tt_min_qt_inter_slice : 3 ;
        unsigned int log2_diff_max_bt_min_qt_inter_slice : 3 ;
        unsigned int log2_diff_min_qt_min_cb_inter_slice : 3 ;
        unsigned int max_mtt_hierarchy_depth_inter_slice : 4 ;
        unsigned int ph_cu_chroma_qp_offset_subdiv_inter_slice : 5 ;
        unsigned int ph_cu_chroma_qp_offset_subdiv_intra_slice : 5 ;
        unsigned int ph_cu_qp_delta_subdiv_inter_slice : 5 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D4;
typedef union {
    struct {
        unsigned int log2_diff_min_qt_min_cb_intra_slice_luma : 3 ;
        unsigned int log2_diff_max_bt_min_qt_intra_slice_luma : 3 ;
        unsigned int log2_diff_max_tt_min_qt_intra_slice_luma : 3 ;
        unsigned int max_mtt_hierarchy_depth_intra_slice_luma : 4 ;
        unsigned int log2_diff_max_tt_min_qt_intra_slice_chroma : 3 ;
        unsigned int log2_diff_max_bt_min_qt_intra_slice_chroma : 3 ;
        unsigned int log2_diff_min_qt_min_cb_intra_slice_chroma : 3 ;
        unsigned int max_mtt_hierarchy_depth_intra_slice_chroma : 4 ;
        unsigned int ph_cu_qp_delta_subdiv_intra_slice : 5 ;
        unsigned int reserved_0 : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D5;
typedef union {
    struct {
        unsigned int pps_pic_width_in_luma_samples : 14 ;
        unsigned int reserved_0 : 2 ;
        unsigned int pps_pic_height_in_luma_samples : 14 ;
        unsigned int reserved_1 : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D6;
typedef union {
    struct {
        unsigned int pps_tile_column_width_minus1 : 8 ;
        unsigned int reserved_0 : 8 ;
        unsigned int pps_tile_row_height_minus1 : 9 ;
        unsigned int reserved_1 : 5 ;
        unsigned int pps_loop_filter_across_tiles_enabled_flag : 1 ;
        unsigned int pps_no_pic_partition_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D7;
typedef union {
    struct {
        unsigned int ref_wraparound_offset : 13 ;
        unsigned int reserved_0 : 3 ;
        unsigned int ref_wraparound_enabled_flag : 1 ;
        unsigned int weighted_bipred_flag : 1 ;
        unsigned int weighted_pred_flag : 1 ;
        unsigned int pps_loop_filter_across_slices_enabled_flag : 1 ;
        unsigned int pps_num_slices_in_pic_minus1 : 10 ;
        unsigned int pps_single_slice_per_subpic_flag : 1 ;
        unsigned int pps_rect_slice_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D8;
typedef union {
    struct {
        unsigned int pps_cb_qp_offset : 5 ;
        unsigned int pps_cr_qp_offset : 5 ;
        unsigned int pps_joint_cbcr_qp_offset_value : 5 ;
        unsigned int reserved_0 : 1 ;
        unsigned int reserved_1 : 12 ;
        unsigned int pps_cu_chroma_qp_offset_list_enabled_flag : 1 ;
        unsigned int pps_slice_chroma_qp_offsets_present_flag : 1 ;
        unsigned int pps_joint_cbcr_qp_offset_present_flag : 1 ;
        unsigned int pps_chroma_tool_offsets_present_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D9;
typedef union {
    struct {
        unsigned int virtual_boundary_pos_x0_minus1 : 13 ;
        unsigned int virtual_boundary_pos_x1_minus1 : 13 ;
        unsigned int reserved_0 : 4 ;
        unsigned int num_ver_virtual_boundaries : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D11;
typedef union {
    struct {
        unsigned int virtual_boundary_pos_y0_minus1 : 13 ;
        unsigned int virtual_boundary_pos_y1_minus1 : 13 ;
        unsigned int reserved_0 : 4 ;
        unsigned int num_hor_virtual_boundaries : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D12;
typedef union {
    struct {
        unsigned int virtual_boundary_pos_x2_minus1 : 13 ;
        unsigned int virtual_boundary_pos_y2_minus1 : 13 ;
        unsigned int reserved_0 : 4 ;
        unsigned int reserved_1 : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D13;
typedef union {
    struct {
        unsigned int ladf_qp_offset4 : 8 ;
        unsigned int ladf_lower_bound4 : 10 ;
        unsigned int reserved_0 : 11 ;
        unsigned int ladf_interval_num : 3 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D14;
typedef union {
    struct {
        unsigned int ladf_lower_bound1 : 10 ;
        unsigned int ladf_lower_bound2 : 10 ;
        unsigned int ladf_lower_bound3 : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D15;
typedef union {
    struct {
        unsigned int ladf_qp_offset0 : 8 ;
        unsigned int ladf_qp_offset1 : 8 ;
        unsigned int ladf_qp_offset2 : 8 ;
        unsigned int ladf_qp_offset3 : 8 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D16;
typedef union {
    struct {
        unsigned int cur_scale_win_left_offset : 21 ;
        unsigned int reserved_0 : 11 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D17;
typedef union {
    struct {
        unsigned int cur_scale_win_top_offset : 21 ;
        unsigned int reserved_0 : 11 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D18;
typedef union {
    struct {
        unsigned int cur_scale_win_right_offset : 21 ;
        unsigned int reserved_0 : 11 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D19;
typedef union {
    struct {
        unsigned int cur_scale_win_bottom_offset : 21 ;
        unsigned int reserved_0 : 11 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D20;
typedef union {
    struct {
        unsigned int cu_cb_qp_offset0 : 5 ;
        unsigned int cu_cb_qp_offset1 : 5 ;
        unsigned int cu_cb_qp_offset2 : 5 ;
        unsigned int cu_cb_qp_offset3 : 5 ;
        unsigned int cu_cb_qp_offset4 : 5 ;
        unsigned int cu_cb_qp_offset5 : 5 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D21;
typedef union {
    struct {
        unsigned int cu_cr_qp_offset0 : 5 ;
        unsigned int cu_cr_qp_offset1 : 5 ;
        unsigned int cu_cr_qp_offset2 : 5 ;
        unsigned int cu_cr_qp_offset3 : 5 ;
        unsigned int cu_cr_qp_offset4 : 5 ;
        unsigned int cu_cr_qp_offset5 : 5 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D22;
typedef union {
    struct {
        unsigned int cu_jccr_qp_offset0 : 5 ;
        unsigned int cu_jccr_qp_offset1 : 5 ;
        unsigned int cu_jccr_qp_offset2 : 5 ;
        unsigned int cu_jccr_qp_offset3 : 5 ;
        unsigned int cu_jccr_qp_offset4 : 5 ;
        unsigned int cu_jccr_qp_offset5 : 5 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D23;
typedef union {
    struct {
        unsigned int tile_column_width_minus1_tb_0 : 16 ;
        unsigned int tile_column_width_minus1_tb_1 : 16 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D32_41;
typedef union {
    struct {
        unsigned int tile_row_height_minus1_tb_0 : 16 ;
        unsigned int tile_row_height_minus1_tb_1 : 16 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D42_52;
typedef union {
    struct {
        unsigned int rpr_constraints_inactive_tb : 16 ;
        unsigned int ref_num_subpics_eq1_tb : 16 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D54;
typedef union {
    struct {
        unsigned int ref_scaleup_x_tb : 16 ;
        unsigned int ref_scaleup_y_tb : 16 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D55;
typedef union {
    struct {
        unsigned int ref_scale_y_tb : 16 ;
        unsigned int ref_scale_x_tb : 16 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D80_95;
typedef union {
    struct {
        unsigned int ref_scale_win_left_tb : 21 ;
        unsigned int reserved_0 : 11 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D96_111;
typedef union {
    struct {
        unsigned int ref_scale_win_top_tb : 21 ;
        unsigned int reserved_0 : 11 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D112_127;
typedef union {
    struct {
        unsigned int tile_row_height_minus1_tb_2 : 16 ;
        unsigned int tile_row_height_minus1_tb_3 : 16 ;
    } bits;
    unsigned int u32;
} U_H266_FRM_D192;
typedef struct {
    volatile U_H266_FRM_D0 H266_FRM_D0 ;
    volatile U_H266_FRM_D1 H266_FRM_D1 ;
    volatile U_H266_FRM_D2 H266_FRM_D2 ;
    volatile U_H266_FRM_D3 H266_FRM_D3 ;
    volatile U_H266_FRM_D4 H266_FRM_D4 ;
    volatile U_H266_FRM_D5 H266_FRM_D5 ;
    volatile U_H266_FRM_D6 H266_FRM_D6 ;
    volatile U_H266_FRM_D7 H266_FRM_D7 ;
    volatile U_H266_FRM_D8 H266_FRM_D8 ;
    volatile U_H266_FRM_D9 H266_FRM_D9 ;
    volatile unsigned int H266_FRM_D10 ;
    volatile U_H266_FRM_D11 H266_FRM_D11 ;
    volatile U_H266_FRM_D12 H266_FRM_D12 ;
    volatile U_H266_FRM_D13 H266_FRM_D13 ;
    volatile U_H266_FRM_D14 H266_FRM_D14 ;
    volatile U_H266_FRM_D15 H266_FRM_D15 ;
    volatile U_H266_FRM_D16 H266_FRM_D16 ;
    volatile U_H266_FRM_D17 H266_FRM_D17 ;
    volatile U_H266_FRM_D18 H266_FRM_D18 ;
    volatile U_H266_FRM_D19 H266_FRM_D19 ;
    volatile U_H266_FRM_D20 H266_FRM_D20 ;
    volatile U_H266_FRM_D21 H266_FRM_D21 ;
    volatile U_H266_FRM_D22 H266_FRM_D22 ;
    volatile U_H266_FRM_D23 H266_FRM_D23 ;
    volatile unsigned int reserved_0[6] ;
    volatile unsigned int H266_FRM_D30 ;
    volatile unsigned int H266_FRM_D31 ;
    volatile U_H266_FRM_D32_41 H266_FRM_D32_41[10] ;
    volatile U_H266_FRM_D42_52 H266_FRM_D42_52[11] ;
    volatile unsigned int reserved_1 ;
    volatile U_H266_FRM_D54 H266_FRM_D54 ;
    volatile U_H266_FRM_D55 H266_FRM_D55 ;
    volatile unsigned int H266_FRM_D56_63[8] ;
    volatile unsigned int H266_FRM_D64_79[16] ;
    volatile U_H266_FRM_D80_95 H266_FRM_D80_95[16] ;
    volatile U_H266_FRM_D96_111 H266_FRM_D96_111[16] ;
    volatile U_H266_FRM_D112_127 H266_FRM_D112_127[16] ;
    volatile unsigned int H266_FRM_D128[19] ;
    volatile unsigned int reserved_2 ;
    volatile unsigned int H266_FRM_D148[19] ;
    volatile unsigned int reserved_3 ;
    volatile unsigned int H266_FRM_D168[19] ;
    volatile unsigned int reserved_4[5] ;
    volatile U_H266_FRM_D192 H266_FRM_D192[44] ;
    volatile unsigned int H266_FRM_D236_RESERVED[16] ;
    volatile unsigned int H266_FRM_D252_RESERVED[4] ;
} S_H266_FRM_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_H266_FRM_D0 H266_FRM_D0;
    volatile U_H266_FRM_D1 H266_FRM_D1;
    volatile U_H266_FRM_D2 H266_FRM_D2;
    volatile U_H266_FRM_D3 H266_FRM_D3;
    volatile U_H266_FRM_D4 H266_FRM_D4;
    volatile U_H266_FRM_D5 H266_FRM_D5;
    volatile U_H266_FRM_D6 H266_FRM_D6;
    volatile U_H266_FRM_D7 H266_FRM_D7;
    volatile U_H266_FRM_D8 H266_FRM_D8;
    volatile U_H266_FRM_D9 H266_FRM_D9;
    volatile U_H266_FRM_D11 H266_FRM_D11;
    volatile U_H266_FRM_D12 H266_FRM_D12;
    volatile U_H266_FRM_D13 H266_FRM_D13;
    volatile U_H266_FRM_D14 H266_FRM_D14;
    volatile U_H266_FRM_D15 H266_FRM_D15;
    volatile U_H266_FRM_D16 H266_FRM_D16;
    volatile U_H266_FRM_D17 H266_FRM_D17;
    volatile U_H266_FRM_D18 H266_FRM_D18;
    volatile U_H266_FRM_D19 H266_FRM_D19;
    volatile U_H266_FRM_D20 H266_FRM_D20;
    volatile U_H266_FRM_D21 H266_FRM_D21;
    volatile U_H266_FRM_D22 H266_FRM_D22;
    volatile U_H266_FRM_D23 H266_FRM_D23;
    volatile U_H266_FRM_D32_41 H266_FRM_D32_41;
    volatile U_H266_FRM_D42_52 H266_FRM_D42_52;
    volatile U_H266_FRM_D54 H266_FRM_D54;
    volatile U_H266_FRM_D55 H266_FRM_D55;
    volatile U_H266_FRM_D80_95 H266_FRM_D80_95;
    volatile U_H266_FRM_D96_111 H266_FRM_D96_111;
    volatile U_H266_FRM_D112_127 H266_FRM_D112_127;
    volatile U_H266_FRM_D192 H266_FRM_D192;
} U_H266_FRM_REGS_TYPE;
#endif
