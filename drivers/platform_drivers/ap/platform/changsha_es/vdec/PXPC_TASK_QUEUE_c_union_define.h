#ifndef __PXPC_TASK_QUEUE_C_UNION_DEFINE_H__
#define __PXPC_TASK_QUEUE_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int pxpc_task_addr_hi : 4 ;
        unsigned int pxpc_task_lenth : 14 ;
        unsigned int pxpc_task_destroy_res_ptr_lo : 14 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA1;
typedef union {
    struct {
        unsigned int pxpc_task_destroy_res_ptr_hi : 10 ;
        unsigned int pxpc_task_destroy_syntax_ptr_lo : 22 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA2;
typedef union {
    struct {
        unsigned int pxpc_task_destroy_syntax_ptr_hi : 2 ;
        unsigned int pxpc_task_destroy_bsp_num : 3 ;
        unsigned int pxpc_frm_num : 6 ;
        unsigned int pxpc_task_first_ind : 1 ;
        unsigned int pxpc_task_destroy_last_ind : 1 ;
        unsigned int reserved_0 : 17 ;
        unsigned int pxpc_task_exe_flag : 1 ;
        unsigned int pxpc_task_type : 1 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA3;
typedef struct {
    volatile unsigned int TASK_QUEUE_PARA0;
    volatile U_TASK_QUEUE_PARA1 TASK_QUEUE_PARA1;
    volatile U_TASK_QUEUE_PARA2 TASK_QUEUE_PARA2;
    volatile U_TASK_QUEUE_PARA3 TASK_QUEUE_PARA3;
} S_PXPC_TASK_QUEUE_REGS_TASK_0_TYPE;
typedef struct {
    volatile S_PXPC_TASK_QUEUE_REGS_TASK_0_TYPE TASK_REG[8] ;
} S_PXPC_TASK_QUEUE_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_TASK_QUEUE_PARA1 TASK_QUEUE_PARA1;
    volatile U_TASK_QUEUE_PARA2 TASK_QUEUE_PARA2;
    volatile U_TASK_QUEUE_PARA3 TASK_QUEUE_PARA3;
} U_PXPC_TASK_QUEUE_REGS_TYPE;
#endif
