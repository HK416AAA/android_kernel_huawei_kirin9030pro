#ifndef __H266_SLC_C_UNION_DEFINE_H__
#define __H266_SLC_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int sh_subpic_id : 10 ;
        unsigned int sh_slice_address : 10 ;
        unsigned int sh_num_tiles_in_slice_minus1 : 9 ;
        unsigned int reserved_0 : 1 ;
        unsigned int sh_slice_type : 2 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D0;
typedef union {
    struct {
        unsigned int subpic_ctu_top_left_y : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int subpic_ctu_top_left_x : 12 ;
        unsigned int reserved_1 : 1 ;
        unsigned int loop_filter_across_subpic_enabled_flag : 1 ;
        unsigned int subpic_treated_as_pic_flag : 1 ;
        unsigned int independent_subpics_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D1;
typedef union {
    struct {
        unsigned int subpic_height_minus1 : 12 ;
        unsigned int reserved_0 : 4 ;
        unsigned int subpic_width_minus1 : 12 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D2;
typedef union {
    struct {
        unsigned int sh_cabac_init_flag : 1 ;
        unsigned int sh_dep_quant_used_flag : 1 ;
        unsigned int sh_sign_data_hiding_used_flag : 1 ;
        unsigned int sh_ts_residual_coding_disabled_flag : 1 ;
        unsigned int sh_cu_chroma_qp_offset_enabled_flag : 1 ;
        unsigned int sh_lmcs_used_flag : 1 ;
        unsigned int sh_explicit_scaling_list_used_flag : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int sh_jccr_qp_offset : 5 ;
        unsigned int sh_cr_qp_offset : 5 ;
        unsigned int sh_cb_qp_offset : 5 ;
        unsigned int slice_qpy : 7 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D3;
typedef union {
    struct {
        unsigned int RefIdxSymL1 : 5 ;
        unsigned int RefIdxSymL0 : 5 ;
        unsigned int reserved_0 : 6 ;
        unsigned int NumRefIdxActive0 : 4 ;
        unsigned int NumRefIdxActive1 : 4 ;
        unsigned int NoBackwardPredFlag : 1 ;
        unsigned int mvd_l1_zero_flag : 1 ;
        unsigned int temporal_mvp_enabled_flag : 1 ;
        unsigned int collocated_from_l0_flag : 1 ;
        unsigned int CollocatedApc : 4 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D4;
typedef union {
    struct {
        unsigned int cr_beta_offset_div2 : 5 ;
        unsigned int cb_beta_offset_div2 : 5 ;
        unsigned int luma_beta_offset_div2 : 5 ;
        unsigned int cr_tc_offset_div2 : 5 ;
        unsigned int cb_tc_offset_div2 : 5 ;
        unsigned int luma_tc_offset_div2 : 5 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D5;
typedef union {
    struct {
        unsigned int alf_cc_cr_filters_signalled_minus1 : 2 ;
        unsigned int alf_cc_cr_aps_id : 3 ;
        unsigned int alf_cc_cb_filters_signalled_minus1 : 2 ;
        unsigned int alf_cc_cb_aps_id : 3 ;
        unsigned int alf_chroma_num_alt_filters_minus1 : 3 ;
        unsigned int alf_aps_id_chroma : 3 ;
        unsigned int num_alf_aps_ids_luma : 4 ;
        unsigned int reserved_0 : 4 ;
        unsigned int deblocking_filter_disabled_flag : 1 ;
        unsigned int sh_sao_chroma_used_flag : 1 ;
        unsigned int sh_sao_luma_used_flag : 1 ;
        unsigned int alf_enabled_flag : 1 ;
        unsigned int alf_cr_enabled_flag : 1 ;
        unsigned int alf_cb_enabled_flag : 1 ;
        unsigned int alf_cc_cr_enabled_flag : 1 ;
        unsigned int alf_cc_cb_enabled_flag : 1 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D6;
typedef union {
    struct {
        unsigned int alf_aps_ids_luma_tb : 24 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D7;
typedef union {
    struct {
        unsigned int l0_is_long_term_tb : 15 ;
        unsigned int reserved_0 : 17 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D8;
typedef union {
    struct {
        unsigned int l1_is_long_term_tb : 15 ;
        unsigned int reserved_0 : 17 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D9;
typedef union {
    struct {
        unsigned int luma_weight_l0_flag_tb : 16 ;
        unsigned int luma_weight_l1_flag_tb : 16 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D15;
typedef union {
    struct {
        unsigned int chroma_weight_l0_flag_tb : 16 ;
        unsigned int chroma_weight_l1_flag_tb : 16 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D16;
typedef union {
    struct {
        unsigned int mv_stride : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D17;
typedef union {
    struct {
        unsigned int luma_log2_weight_denom : 3 ;
        unsigned int luma_weight_l0_tb : 9 ;
        unsigned int luma_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D32;
typedef union {
    struct {
        unsigned int luma_log2_weight_denom : 3 ;
        unsigned int luma_weight_l1_tb : 9 ;
        unsigned int luma_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D48;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cb_weight_l0_tb : 9 ;
        unsigned int chroma_cb_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D64;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cb_weight_l1_tb : 9 ;
        unsigned int chroma_cb_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D80;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cr_weight_l0_tb : 9 ;
        unsigned int chroma_cr_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D96;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cr_weight_l1_tb : 9 ;
        unsigned int chroma_cr_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H266_SLC_D112;
typedef struct {
    volatile U_H266_SLC_D0 H266_SLC_D0 ;
    volatile U_H266_SLC_D1 H266_SLC_D1 ;
    volatile U_H266_SLC_D2 H266_SLC_D2 ;
    volatile U_H266_SLC_D3 H266_SLC_D3 ;
    volatile U_H266_SLC_D4 H266_SLC_D4 ;
    volatile U_H266_SLC_D5 H266_SLC_D5 ;
    volatile U_H266_SLC_D6 H266_SLC_D6 ;
    volatile U_H266_SLC_D7 H266_SLC_D7 ;
    volatile U_H266_SLC_D8 H266_SLC_D8 ;
    volatile U_H266_SLC_D9 H266_SLC_D9 ;
    volatile unsigned int H266_SLC_D10[2] ;
    volatile unsigned int H266_SLC_D12[2] ;
    volatile unsigned int H266_SLC_D14 ;
    volatile U_H266_SLC_D15 H266_SLC_D15 ;
    volatile U_H266_SLC_D16 H266_SLC_D16 ;
    volatile U_H266_SLC_D17 H266_SLC_D17 ;
    volatile unsigned int reserved_0[14] ;
    volatile U_H266_SLC_D32 H266_SLC_D32[16] ;
    volatile U_H266_SLC_D48 H266_SLC_D48[16] ;
    volatile U_H266_SLC_D64 H266_SLC_D64[16] ;
    volatile U_H266_SLC_D80 H266_SLC_D80[16] ;
    volatile U_H266_SLC_D96 H266_SLC_D96[16] ;
    volatile U_H266_SLC_D112 H266_SLC_D112[16] ;
} S_H266_SLC_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_H266_SLC_D0 H266_SLC_D0;
    volatile U_H266_SLC_D1 H266_SLC_D1;
    volatile U_H266_SLC_D2 H266_SLC_D2;
    volatile U_H266_SLC_D3 H266_SLC_D3;
    volatile U_H266_SLC_D4 H266_SLC_D4;
    volatile U_H266_SLC_D5 H266_SLC_D5;
    volatile U_H266_SLC_D6 H266_SLC_D6;
    volatile U_H266_SLC_D7 H266_SLC_D7;
    volatile U_H266_SLC_D8 H266_SLC_D8;
    volatile U_H266_SLC_D9 H266_SLC_D9;
    volatile U_H266_SLC_D15 H266_SLC_D15;
    volatile U_H266_SLC_D16 H266_SLC_D16;
    volatile U_H266_SLC_D17 H266_SLC_D17;
    volatile U_H266_SLC_D32 H266_SLC_D32;
    volatile U_H266_SLC_D48 H266_SLC_D48;
    volatile U_H266_SLC_D64 H266_SLC_D64;
    volatile U_H266_SLC_D80 H266_SLC_D80;
    volatile U_H266_SLC_D96 H266_SLC_D96;
    volatile U_H266_SLC_D112 H266_SLC_D112;
} U_H266_SLC_REGS_TYPE;
#endif
