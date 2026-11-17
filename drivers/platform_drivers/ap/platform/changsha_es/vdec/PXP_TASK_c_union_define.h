#ifndef __PXP_TASK_C_UNION_DEFINE_H__
#define __PXP_TASK_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int pxp_task_frame_msg_addr_hi : 4 ;
        unsigned int pxp_task_vdec_ver : 4 ;
        unsigned int pxp_task_rsc_num : 10 ;
        unsigned int pxp_task_frame_start : 1 ;
        unsigned int pxp_task_frame_msg_len : 13 ;
    } bits;
    unsigned int u32;
} U_PXP_TASK_D1;
typedef union {
    struct {
        unsigned int pxp_task_ctu_header_addr_hi : 4 ;
        unsigned int pxp_task_frame_end : 1 ;
        unsigned int pxp_task_ctu_header_stride : 16 ;
        unsigned int pxp_task_intr_flag : 1 ;
        unsigned int reserved_0 : 10 ;
    } bits;
    unsigned int u32;
} U_PXP_TASK_D3;
typedef struct {
    volatile unsigned int PXP_TASK_D0 ;
    volatile U_PXP_TASK_D1 PXP_TASK_D1 ;
    volatile unsigned int PXP_TASK_D2 ;
    volatile U_PXP_TASK_D3 PXP_TASK_D3 ;
} S_PXP_TASK_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_PXP_TASK_D1 PXP_TASK_D1;
    volatile U_PXP_TASK_D3 PXP_TASK_D3;
} U_PXP_TASK_REGS_TYPE;
#endif
