#ifndef __H265_FRM_C_UNION_DEFINE_H__
#define __H265_FRM_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int PicWidthInCtbsYMinus1 : 10 ;
        unsigned int PicHightInCtbsYMinus1 : 10 ;
        unsigned int pcm_enabled_flag : 1 ;
        unsigned int chroma_format_idc : 2 ;
        unsigned int amp_enabled_flag : 1 ;
        unsigned int sample_adaptive_offset_enabled_flag : 1 ;
        unsigned int pcm_loop_filter_disabled_flag : 1 ;
        unsigned int scaling_list_enabled_flag : 1 ;
        unsigned int strong_intra_smoothing_enabled_flag : 1 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D0;
typedef union {
    struct {
        unsigned int CtbLog2SizeY : 3 ;
        unsigned int Log2MinCbSizeY : 3 ;
        unsigned int MaxCuDepth : 3 ;
        unsigned int Log2MaxTrafoSize : 3 ;
        unsigned int Log2MinTrafoSize : 3 ;
        unsigned int Log2MaxIpcmCbSizeY : 3 ;
        unsigned int Log2MinIpcmCbSizeY : 3 ;
        unsigned int max_transform_hierarchy_depth_intra : 3 ;
        unsigned int max_transform_hierarchy_depth_inter : 3 ;
        unsigned int weighted_pred_flag : 1 ;
        unsigned int weighted_bipred_flag : 1 ;
        unsigned int log2_parallel_merge_level_minus2 : 3 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D2;
typedef union {
    struct {
        unsigned int BitDepthY : 4 ;
        unsigned int BitDepthC : 4 ;
        unsigned int PcmBitDepthY : 4 ;
        unsigned int PcmBitDepthC : 4 ;
        unsigned int QpBdOffsetY : 6 ;
        unsigned int QpBdOffsetC : 6 ;
        unsigned int reserved_0 : 4 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D3;
typedef union {
    struct {
        unsigned int pic_width_in_luma_samples : 14 ;
        unsigned int reserved_0 : 2 ;
        unsigned int pic_height_in_luma_samples : 14 ;
        unsigned int reserved_1 : 2 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D4;
typedef union {
    struct {
        unsigned int pps_cr_qp_offset : 5 ;
        unsigned int pps_cb_qp_offset : 5 ;
        unsigned int constrained_intra_pred_flag : 1 ;
        unsigned int transquant_bypass_enabled_flag : 1 ;
        unsigned int cu_qp_delta_enabled_flag : 1 ;
        unsigned int diff_cu_qp_delta_depth : 3 ;
        unsigned int Log2MinCuQpDeltaSize : 3 ;
        unsigned int tiles_enabled_flag : 1 ;
        unsigned int uniform_spacing_flag : 1 ;
        unsigned int entropy_coding_sync_enabled_flag : 1 ;
        unsigned int sign_data_hiding_enabled_flag : 1 ;
        unsigned int transform_skip_enabled_flag : 1 ;
        unsigned int loop_filter_across_tiles_enabled_flag : 1 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D5;
typedef union {
    struct {
        unsigned int num_tile_columns_minus1 : 8 ;
        unsigned int reserved_0 : 8 ;
        unsigned int num_tile_rows_minus1 : 8 ;
        unsigned int reserved_1 : 8 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D6;
typedef union {
    struct {
        unsigned int tile_column_width_minus1_tb_0 : 16 ;
        unsigned int tile_column_width_minus1_tb_1 : 16 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_H265_FRM_D32_41;
typedef union {
    struct {
        unsigned int tile_row_height_minus1_tb_0 : 16 ;
        unsigned int tile_row_height_minus1_tb_1 : 16 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_H265_FRM_D42_52;
typedef union {
    struct {
        unsigned int q16x16_dc0 : 8 ;
        unsigned int q16x16_dc1 : 8 ;
        unsigned int q16x16_dc2 : 8 ;
        unsigned int q16x16_dc3 : 8 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D312;
typedef union {
    struct {
        unsigned int q16x16_dc4 : 8 ;
        unsigned int q16x16_dc5 : 8 ;
        unsigned int q32x32_dc0 : 8 ;
        unsigned int q32x32_dc1 : 8 ;
    } bits;
    unsigned int u32;
} U_H265_FRM_D313;
typedef struct {
    volatile U_H265_FRM_D0 H265_FRM_D0 ;
    volatile unsigned int H265_FRM_D1 ;
    volatile U_H265_FRM_D2 H265_FRM_D2 ;
    volatile U_H265_FRM_D3 H265_FRM_D3 ;
    volatile U_H265_FRM_D4 H265_FRM_D4 ;
    volatile U_H265_FRM_D5 H265_FRM_D5 ;
    volatile U_H265_FRM_D6 H265_FRM_D6 ;
    volatile unsigned int H265_FRM_D7 ;
    volatile unsigned int H265_FRM_D8 ;
    volatile unsigned int H265_FRM_D9 ;
    volatile unsigned int H265_FRM_D10 ;
    volatile unsigned int H265_FRM_D11_15[5] ;
    volatile unsigned int H265_FRM_D16_31[16] ;
    volatile U_H265_FRM_H265_FRM_D32_41 H265_FRM_H265_FRM_D32_41[10] ;
    volatile U_H265_FRM_H265_FRM_D42_52 H265_FRM_H265_FRM_D42_52[11] ;
    volatile unsigned int H265_FRM_H265_FRM_D53 ;
    volatile unsigned int H265_FRM_H265_FRM_D54 ;
    volatile unsigned int H265_FRM_H265_FRM_D55 ;
    volatile unsigned int H265_FRM_H265_FRM_D56_63[8] ;
    volatile unsigned int H265_FRM_D64_79[16] ;
    volatile unsigned int H265_FRM_D80_95[16] ;
    volatile unsigned int H265_FRM_D96_111[16] ;
    volatile unsigned int H265_FRM_D112_127[16] ;
    volatile unsigned int H265_FRM_D128_143[16] ;
    volatile unsigned int H265_FRM_D144_159[16] ;
    volatile unsigned int H265_FRM_D160_175[16] ;
    volatile unsigned int H265_FRM_D176_191[16] ;
    volatile unsigned int H265_FRM_D192_207[16] ;
    volatile unsigned int H265_FRM_D208_223[16] ;
    volatile unsigned int H265_FRM_D224_239[16] ;
    volatile unsigned int H265_FRM_D240_255[16] ;
    volatile unsigned int H265_FRM_D256_271[16] ;
    volatile unsigned int H265_FRM_D272_287[16] ;
    volatile unsigned int H265_FRM_D288_291[4] ;
    volatile unsigned int H265_FRM_D292_295[4] ;
    volatile unsigned int H265_FRM_D296_299[4] ;
    volatile unsigned int H265_FRM_D300_303[4] ;
    volatile unsigned int H265_FRM_D304_307[4] ;
    volatile unsigned int H265_FRM_D308_311[4] ;
    volatile U_H265_FRM_D312 H265_FRM_D312 ;
    volatile U_H265_FRM_D313 H265_FRM_D313 ;
    volatile unsigned int RSV[6] ;
} S_H265_FRM_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_H265_FRM_D0 H265_FRM_D0;
    volatile U_H265_FRM_D2 H265_FRM_D2;
    volatile U_H265_FRM_D3 H265_FRM_D3;
    volatile U_H265_FRM_D4 H265_FRM_D4;
    volatile U_H265_FRM_D5 H265_FRM_D5;
    volatile U_H265_FRM_D6 H265_FRM_D6;
    volatile U_H265_FRM_H265_FRM_D32_41 H265_FRM_H265_FRM_D32_41;
    volatile U_H265_FRM_H265_FRM_D42_52 H265_FRM_H265_FRM_D42_52;
    volatile U_H265_FRM_D312 H265_FRM_D312;
    volatile U_H265_FRM_D313 H265_FRM_D313;
} U_H265_FRM_REGS_TYPE;
#endif
