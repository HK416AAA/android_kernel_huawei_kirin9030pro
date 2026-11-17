#ifndef __H264_SLC_C_UNION_DEFINE_H__
#define __H264_SLC_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int first_mb_in_slice : 20 ;
        unsigned int reserved_0 : 4 ;
        unsigned int cabac_init_idc : 2 ;
        unsigned int SliceQpY : 6 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D0;
typedef union {
    struct {
        unsigned int slice_type : 2 ;
        unsigned int listsize0 : 6 ;
        unsigned int listsize1 : 6 ;
        unsigned int direct_8x8_inference_flag : 1 ;
        unsigned int direct_spatial_mv_pred_flag : 1 ;
        unsigned int num_ref_idx_l0_active_minus1 : 5 ;
        unsigned int num_ref_idx_l1_active_minus1 : 5 ;
        unsigned int reserved_0 : 6 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D1;
typedef union {
    struct {
        unsigned int mv_address_stride : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D3;
typedef union {
    struct {
        unsigned int disable_deblocking_filter_idc : 2 ;
        unsigned int reserved_0 : 6 ;
        unsigned int slice_beta_offset_div2 : 4 ;
        unsigned int reserved_1 : 4 ;
        unsigned int slice_alpha_c0_offset_div2 : 4 ;
        unsigned int reserved_2 : 12 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D4;
typedef union {
    struct {
        unsigned int luma_log2_weight_denom : 3 ;
        unsigned int luma_weight_l0_tb : 9 ;
        unsigned int luma_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D64_95;
typedef union {
    struct {
        unsigned int luma_log2_weight_denom : 3 ;
        unsigned int luma_weight_l1_tb : 9 ;
        unsigned int luma_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D96_127;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cb_weight_l0_tb : 9 ;
        unsigned int chroma_cb_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D128_159;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cb_weight_l1_tb : 9 ;
        unsigned int chroma_cb_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D160_191;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cr_weight_l0_tb : 9 ;
        unsigned int chroma_cr_offset_l0_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D192_223;
typedef union {
    struct {
        unsigned int chroma_log2_weight_denom : 3 ;
        unsigned int chroma_cr_weight_l1_tb : 9 ;
        unsigned int chroma_cr_offset_l1_tb : 8 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_H264_SLC_D224_255;
typedef struct {
    volatile U_H264_SLC_D0 H264_SLC_D0 ;
    volatile U_H264_SLC_D1 H264_SLC_D1 ;
    volatile unsigned int H264_SLC_D2 ;
    volatile U_H264_SLC_D3 H264_SLC_D3 ;
    volatile U_H264_SLC_D4 H264_SLC_D4 ;
    volatile unsigned int H264_SLC_D5 ;
    volatile unsigned int H264_SLC_D6 ;
    volatile unsigned int H264_SLC_D7 ;
    volatile unsigned int H264_SLC_D8_H264_SLC_D11[4] ;
    volatile unsigned int H264_SLC_D12_H264_SLC_D15[4] ;
    volatile unsigned int H264_SLC_D16_23[8] ;
    volatile unsigned int H264_SLC_D24_31[8] ;
    volatile unsigned int H264_SLC_D32_39[8] ;
    volatile unsigned int H264_SLC_D40 ;
    volatile unsigned int H264_SLC_D41 ;
    volatile unsigned int H264_SLC_D42 ;
    volatile unsigned int H264_SLC_D43 ;
    volatile unsigned int H264_SLC_D44_47[4] ;
    volatile unsigned int H264_SLC_D48_63[16] ;
    volatile U_H264_SLC_D64_95 H264_SLC_D64_95[32] ;
    volatile U_H264_SLC_D96_127 H264_SLC_D96_127[32] ;
    volatile U_H264_SLC_D128_159 H264_SLC_D128_159[32] ;
    volatile U_H264_SLC_D160_191 H264_SLC_D160_191[32] ;
    volatile U_H264_SLC_D192_223 H264_SLC_D192_223[32] ;
    volatile U_H264_SLC_D224_255 H264_SLC_D224_255[32] ;
} S_H264_SLC_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_H264_SLC_D0 H264_SLC_D0;
    volatile U_H264_SLC_D1 H264_SLC_D1;
    volatile U_H264_SLC_D3 H264_SLC_D3;
    volatile U_H264_SLC_D4 H264_SLC_D4;
    volatile U_H264_SLC_D64_95 H264_SLC_D64_95;
    volatile U_H264_SLC_D96_127 H264_SLC_D96_127;
    volatile U_H264_SLC_D128_159 H264_SLC_D128_159;
    volatile U_H264_SLC_D160_191 H264_SLC_D160_191;
    volatile U_H264_SLC_D192_223 H264_SLC_D192_223;
    volatile U_H264_SLC_D224_255 H264_SLC_D224_255;
} U_H264_SLC_REGS_TYPE;
#endif
