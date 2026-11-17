#ifndef __BSP_SUBTASK2_H264_C_UNION_DEFINE_H__
#define __BSP_SUBTASK2_H264_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int first_mb_in_slice : 20 ;
        unsigned int slice_type : 2 ;
        unsigned int direct_8x8_inference_flag : 1 ;
        unsigned int direct_spatial_mv_pred_flag : 1 ;
        unsigned int cabac_init_idc : 2 ;
        unsigned int sliceqpy : 6 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA5_H264;
typedef union {
    struct {
        unsigned int end_mb_in_slice : 20 ;
        unsigned int bottom_field_flag : 1 ;
        unsigned int field_pic_flag : 1 ;
        unsigned int num_ref_idx_l0_active_minus1 : 5 ;
        unsigned int num_ref_idx_l1_active_minus1 : 5 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA6_H264;
typedef union {
    struct {
        unsigned int bit_offset : 3 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA7_H264;
typedef struct {
    volatile unsigned int BSP_SUBTASK_PARA4_H264 ;
    volatile U_BSP_SUBTASK_PARA5_H264 BSP_SUBTASK_PARA5_H264 ;
    volatile U_BSP_SUBTASK_PARA6_H264 BSP_SUBTASK_PARA6_H264 ;
    volatile U_BSP_SUBTASK_PARA7_H264 BSP_SUBTASK_PARA7_H264 ;
} S_BSP_SUBTASK2_H264_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_BSP_SUBTASK_PARA5_H264 BSP_SUBTASK_PARA5_H264;
    volatile U_BSP_SUBTASK_PARA6_H264 BSP_SUBTASK_PARA6_H264;
    volatile U_BSP_SUBTASK_PARA7_H264 BSP_SUBTASK_PARA7_H264;
} U_BSP_SUBTASK2_H264_REGS_TYPE;
#endif
