#ifndef __BSP_SUBTASK2_H266_C_UNION_DEFINE_H__
#define __BSP_SUBTASK2_H266_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int alf_cc_cr_filters_signalled_minus1 : 2 ;
        unsigned int alf_cc_cb_filters_signalled_minus1 : 2 ;
        unsigned int alf_chroma_num_alt_filters_minus1 : 3 ;
        unsigned int RefIdxSymL1 : 5 ;
        unsigned int RefIdxSymL0 : 5 ;
        unsigned int NoBackwardPredFlag : 1 ;
        unsigned int NumRefIdxActive0 : 4 ;
        unsigned int NumRefIdxActive1 : 4 ;
        unsigned int reserved_0 : 6 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA5_H266;
typedef union {
    struct {
        unsigned int sh_slice_type : 2 ;
        unsigned int sh_cabac_init_flag : 1 ;
        unsigned int sh_cu_chroma_qp_offset_enabled_flag : 1 ;
        unsigned int sh_ts_residual_coding_disabled_flag : 1 ;
        unsigned int sh_sign_data_hiding_used_flag : 1 ;
        unsigned int sh_dep_quant_used_flag : 1 ;
        unsigned int sh_alf_cb_enabled_flag : 1 ;
        unsigned int sh_alf_cc_cr_enabled_flag : 1 ;
        unsigned int sh_alf_cc_cb_enabled_flag : 1 ;
        unsigned int sh_alf_cr_enabled_flag : 1 ;
        unsigned int sh_num_alf_aps_ids_luma : 3 ;
        unsigned int sh_alf_enabled_flag : 1 ;
        unsigned int sh_sao_chroma_used_flag : 1 ;
        unsigned int sh_sao_luma_used_flag : 1 ;
        unsigned int SliceQpY : 8 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA4_H266;
typedef union {
    struct {
        unsigned int luma_weight_l0_flag : 16 ;
        unsigned int luma_weight_l1_flag : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA6_H266;
typedef union {
    struct {
        unsigned int chroma_weight_l0_flag : 16 ;
        unsigned int chroma_weight_l1_flag : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA7_H266;
typedef struct {
    volatile U_BSP_SUBTASK_PARA5_H266 BSP_SUBTASK_PARA5_H266 ;
    volatile U_BSP_SUBTASK_PARA4_H266 BSP_SUBTASK_PARA4_H266 ;
    volatile U_BSP_SUBTASK_PARA6_H266 BSP_SUBTASK_PARA6_H266 ;
    volatile U_BSP_SUBTASK_PARA7_H266 BSP_SUBTASK_PARA7_H266 ;
} S_BSP_SUBTASK2_H266_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_BSP_SUBTASK_PARA5_H266 BSP_SUBTASK_PARA5_H266;
    volatile U_BSP_SUBTASK_PARA4_H266 BSP_SUBTASK_PARA4_H266;
    volatile U_BSP_SUBTASK_PARA6_H266 BSP_SUBTASK_PARA6_H266;
    volatile U_BSP_SUBTASK_PARA7_H266 BSP_SUBTASK_PARA7_H266;
} U_BSP_SUBTASK2_H266_REGS_TYPE;
#endif
