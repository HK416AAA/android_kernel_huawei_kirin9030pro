#ifndef __PXP_SUBTASK_C_UNION_DEFINE_H__
#define __PXP_SUBTASK_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int pxp_subtask_slice_msg_addr_hi : 4 ;
        unsigned int pxp_subtask_mode : 2 ;
        unsigned int pxp_subtask_ld_slice_msg : 1 ;
        unsigned int pxp_subtask_bsp_id : 4 ;
        unsigned int pxp_subtask_slice_msg_len : 11 ;
        unsigned int pxp_subtask_tile_right_bound : 10 ;
    } bits;
    unsigned int u32;
} U_PXP_SUBTASK_D1;
typedef union {
    struct {
        unsigned int pxp_subtask_b1_ctu_x : 10 ;
        unsigned int pxp_subtask_a1_ctu_x : 10 ;
        unsigned int pxp_subtask_b_ctu_y : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_PXP_SUBTASK_D2;
typedef union {
    struct {
        unsigned int pxp_subtask_b_ctu_x : 10 ;
        unsigned int pxp_subtask_a_ctu_y : 10 ;
        unsigned int pxp_subtask_a_ctu_x : 10 ;
        unsigned int reserved_0 : 2 ;
    } bits;
    unsigned int u32;
} U_PXP_SUBTASK_D3;
typedef struct {
    volatile unsigned int PXP_SUBTASK_D0 ;
    volatile U_PXP_SUBTASK_D1 PXP_SUBTASK_D1 ;
    volatile U_PXP_SUBTASK_D2 PXP_SUBTASK_D2 ;
    volatile U_PXP_SUBTASK_D3 PXP_SUBTASK_D3 ;
} S_PXP_SUBTASK_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_PXP_SUBTASK_D1 PXP_SUBTASK_D1;
    volatile U_PXP_SUBTASK_D2 PXP_SUBTASK_D2;
    volatile U_PXP_SUBTASK_D3 PXP_SUBTASK_D3;
} U_PXP_SUBTASK_REGS_TYPE;
#endif
