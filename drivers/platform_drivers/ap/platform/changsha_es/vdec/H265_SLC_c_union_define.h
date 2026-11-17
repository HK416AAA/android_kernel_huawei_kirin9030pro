#ifndef __H265_SLC_C_UNION_DEFINE_H__
#define __H265_SLC_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int IndependentSliceSegmentAddr : 20 ;
        unsigned int cabac_init_flag : 1 ;
        unsigned int SliceQpY : 7 ;
        unsigned int dependent_slice_segment_flag : 1 ;
        unsigned int LowDelayFlag : 1 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D0;
typedef union {
    struct {
        unsigned int slice_type : 2 ;
        unsigned int listsize0 : 6 ;
        unsigned int listsize1 : 6 ;
        unsigned int mvd_l1_zero_flag : 1 ;
        unsigned int slice_temporal_mvp_enabled_flag : 1 ;
        unsigned int num_ref_idx_l0_active_minus1 : 4 ;
        unsigned int num_ref_idx_l1_active_minus1 : 4 ;
        unsigned int MaxNumMergeCand : 3 ;
        unsigned int collocated_from_l0_flag : 1 ;
        unsigned int CollocatedApc : 4 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D1;
typedef union {
    struct {
        unsigned int slice_cr_qp_offset : 5 ;
        unsigned int reserved_0 : 3 ;
        unsigned int slice_cb_qp_offset : 5 ;
        unsigned int reserved_1 : 19 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D2;
typedef union {
    struct {
        unsigned int slice_loop_filter_across_slices_enabled_flag : 1 ;
        unsigned int slice_deblocking_filter_disabled_flag : 1 ;
        unsigned int slice_sao_chroma_flag : 1 ;
        unsigned int slice_sao_luma_flag : 1 ;
        unsigned int reserved_0 : 4 ;
        unsigned int slice_beta_offset_div2 : 4 ;
        unsigned int reserved_1 : 4 ;
        unsigned int slice_tc_offset_div2 : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D3;
typedef union {
    struct {
        unsigned int l0_is_long_term_tb : 15 ;
        unsigned int reserved_0 : 17 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D4;
typedef union {
    struct {
        unsigned int l1_is_long_term_tb : 15 ;
        unsigned int reserved_0 : 17 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D5;
typedef union {
    struct {
        unsigned int mv_stride : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D11;
typedef union {
    struct {
        unsigned int luma_log2_weight_denom : 3 ;
        unsigned int luma_weight_l0_tb : 9 ;
        unsigned int luma_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D32_47;
typedef union {
    struct {
        unsigned int luma_log2_weight_denom : 3 ;
        unsigned int luma_weight_l1_tb : 9 ;
        unsigned int luma_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D48_63;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cb_weight_l0_tb : 9 ;
        unsigned int chroma_cb_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D64_79;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cb_weight_l1_tb : 9 ;
        unsigned int chroma_cb_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D80_95;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cr_weight_l0_tb : 9 ;
        unsigned int chroma_cr_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D96_111;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cr_weight_l1_tb : 9 ;
        unsigned int chroma_cr_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H265_SLC_D112_127;
typedef struct {
    volatile U_H265_SLC_D0 H265_SLC_D0 ;
    volatile U_H265_SLC_D1 H265_SLC_D1 ;
    volatile U_H265_SLC_D2 H265_SLC_D2 ;
    volatile U_H265_SLC_D3 H265_SLC_D3 ;
    volatile U_H265_SLC_D4 H265_SLC_D4 ;
    volatile U_H265_SLC_D5 H265_SLC_D5 ;
    volatile unsigned int H265_SLC_D6_7[2] ;
    volatile unsigned int H265_SLC_D8_9[2] ;
    volatile unsigned int H265_SLC_D10 ;
    volatile U_H265_SLC_D11 H265_SLC_D11 ;
    volatile unsigned int H265_SLC_D12_15[4] ;
    volatile unsigned int H265_SLC_D15_31[16] ;
    volatile U_H265_SLC_D32_47 H265_SLC_D32_47[16] ;
    volatile U_H265_SLC_D48_63 H265_SLC_D48_63[16] ;
    volatile U_H265_SLC_D64_79 H265_SLC_D64_79[16] ;
    volatile U_H265_SLC_D80_95 H265_SLC_D80_95[16] ;
    volatile U_H265_SLC_D96_111 H265_SLC_D96_111[16] ;
    volatile U_H265_SLC_D112_127 H265_SLC_D112_127[16] ;
} S_H265_SLC_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_H265_SLC_D0 H265_SLC_D0;
    volatile U_H265_SLC_D1 H265_SLC_D1;
    volatile U_H265_SLC_D2 H265_SLC_D2;
    volatile U_H265_SLC_D3 H265_SLC_D3;
    volatile U_H265_SLC_D4 H265_SLC_D4;
    volatile U_H265_SLC_D5 H265_SLC_D5;
    volatile U_H265_SLC_D11 H265_SLC_D11;
    volatile U_H265_SLC_D32_47 H265_SLC_D32_47;
    volatile U_H265_SLC_D48_63 H265_SLC_D48_63;
    volatile U_H265_SLC_D64_79 H265_SLC_D64_79;
    volatile U_H265_SLC_D80_95 H265_SLC_D80_95;
    volatile U_H265_SLC_D96_111 H265_SLC_D96_111;
    volatile U_H265_SLC_D112_127 H265_SLC_D112_127;
} U_H265_SLC_REGS_TYPE;
#endif
