#ifndef __BSP_SUBTASK2_H265_C_UNION_DEFINE_H__
#define __BSP_SUBTASK2_H265_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int slice_segment_address : 20 ;
        unsigned int cabac_init_flag : 1 ;
        unsigned int SliceQpY : 7 ;
        unsigned int dependent_slice_segment_flag : 1 ;
        unsigned int slice_loop_filter_across_slice_enable_flag : 1 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA5_H265;
typedef union {
    struct {
        unsigned int slice_type : 2 ;
        unsigned int slice_sao_chroma_flag : 1 ;
        unsigned int slice_sao_luma_flag : 1 ;
        unsigned int reserved_0 : 11 ;
        unsigned int mvd_l1_zero_flag : 1 ;
        unsigned int num_ref_idx_l0_active_minus1 : 4 ;
        unsigned int num_ref_idx_l1_active_minus1 : 4 ;
        unsigned int MaxNumMergeCand : 3 ;
        unsigned int reserved_1 : 5 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA6_H265;
typedef union {
    struct {
        unsigned int num_entry_point_offsets : 16 ;
        unsigned int IndependentSliceSegmentAddr : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA7_H265;
typedef struct {
    volatile unsigned int BSP_SUBTASK_PARA4_H265 ;
    volatile U_BSP_SUBTASK_PARA5_H265 BSP_SUBTASK_PARA5_H265 ;
    volatile U_BSP_SUBTASK_PARA6_H265 BSP_SUBTASK_PARA6_H265 ;
    volatile U_BSP_SUBTASK_PARA7_H265 BSP_SUBTASK_PARA7_H265 ;
} S_BSP_SUBTASK2_H265_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_BSP_SUBTASK_PARA5_H265 BSP_SUBTASK_PARA5_H265;
    volatile U_BSP_SUBTASK_PARA6_H265 BSP_SUBTASK_PARA6_H265;
    volatile U_BSP_SUBTASK_PARA7_H265 BSP_SUBTASK_PARA7_H265;
} U_BSP_SUBTASK2_H265_REGS_TYPE;
#endif
