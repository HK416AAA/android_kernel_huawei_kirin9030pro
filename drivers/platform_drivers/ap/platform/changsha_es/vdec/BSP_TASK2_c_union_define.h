#ifndef __BSP_TASK2_C_UNION_DEFINE_H__
#define __BSP_TASK2_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int bsp_nringbuff_res_addr_hi : 4 ;
        unsigned int bsp_nringbuff_res_lenth : 16 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_BSP_TASK_PARA9;
typedef union {
    struct {
        unsigned int bsp_nringbuff_info_addr_hi : 4 ;
        unsigned int bsp_nringbuff_info_lenth : 15 ;
        unsigned int reserved_0 : 13 ;
    } bits;
    unsigned int u32;
} U_BSP_TASK_PARA11;
typedef struct {
    volatile unsigned int BSP_TASK_PARA8 ;
    volatile U_BSP_TASK_PARA9 BSP_TASK_PARA9 ;
    volatile unsigned int BSP_TASK_PARA10 ;
    volatile U_BSP_TASK_PARA11 BSP_TASK_PARA11 ;
    volatile unsigned int BSP_TASK_PARA12 ;
    volatile unsigned int BSP_TASK_PARA13 ;
    volatile unsigned int BSP_TASK_PARA14 ;
    volatile unsigned int BSP_TASK_PARA15 ;
} S_BSP_TASK2_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_BSP_TASK_PARA9 BSP_TASK_PARA9;
    volatile U_BSP_TASK_PARA11 BSP_TASK_PARA11;
} U_BSP_TASK2_REGS_TYPE;
#endif
