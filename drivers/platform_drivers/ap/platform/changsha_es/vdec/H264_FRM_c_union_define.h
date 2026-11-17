#ifndef __H264_FRM_C_UNION_DEFINE_H__
#define __H264_FRM_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int reserved_0 : 13 ;
        unsigned int frame_mbs_only_flag : 1 ;
        unsigned int pic_structure : 2 ;
        unsigned int reserved_1 : 9 ;
        unsigned int chroma_format : 1 ;
        unsigned int constrained_intra_pred_flag : 1 ;
        unsigned int entropy_coding_mode_flag : 1 ;
        unsigned int transform_8x8_mode_flag : 1 ;
        unsigned int reserved_2 : 2 ;
        unsigned int Nal_ref_idc : 1 ;
    } bits;
    unsigned int u32;
} U_H264_FRM_D0;
typedef union {
    struct {
        unsigned int pic_width_in_mb : 11 ;
        unsigned int reserved_0 : 5 ;
        unsigned int pic_height_in_mb : 11 ;
        unsigned int reserved_1 : 5 ;
    } bits;
    unsigned int u32;
} U_H264_FRM_D1;
typedef union {
    struct {
        unsigned int second_chroma_qp_index_offset : 5 ;
        unsigned int reserved_0 : 3 ;
        unsigned int chroma_qp_index_offset : 5 ;
        unsigned int reserved_1 : 3 ;
        unsigned int weighted_bipred_idc : 2 ;
        unsigned int weighted_pred_flag : 1 ;
        unsigned int reserved_2 : 13 ;
    } bits;
    unsigned int u32;
} U_H264_FRM_D5;
typedef struct {
    volatile U_H264_FRM_D0 H264_FRM_D0 ;
    volatile U_H264_FRM_D1 H264_FRM_D1 ;
    volatile unsigned int H264_FRM_D2 ;
    volatile unsigned int H264_FRM_D3 ;
    volatile unsigned int H264_FRM_D4 ;
    volatile U_H264_FRM_D5 H264_FRM_D5 ;
    volatile unsigned int H264_FRM_D6 ;
    volatile unsigned int H264_FRM_D7 ;
    volatile unsigned int H264_FRM_D8 ;
    volatile unsigned int H264_FRM_D9 ;
    volatile unsigned int H264_FRM_D10_15[6] ;
    volatile unsigned int H264_FRM_D16_31[16] ;
    volatile unsigned int H264_FRM_D32_63[32] ;
    volatile unsigned int H264_FRM_D64_67[4] ;
    volatile unsigned int H264_FRM_D68_71[4] ;
    volatile unsigned int H264_FRM_D72_75[4] ;
    volatile unsigned int H264_FRM_D76_79[4] ;
    volatile unsigned int H264_FRM_D80_83[4] ;
    volatile unsigned int H264_FRM_D84_87[4] ;
    volatile unsigned int H264_FRM_D88_95[8] ;
    volatile unsigned int H264_FRM_D96_111[16] ;
    volatile unsigned int H264_FRM_D112_127[16] ;
} S_H264_FRM_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_H264_FRM_D0 H264_FRM_D0;
    volatile U_H264_FRM_D1 H264_FRM_D1;
    volatile U_H264_FRM_D5 H264_FRM_D5;
} U_H264_FRM_REGS_TYPE;
#endif
