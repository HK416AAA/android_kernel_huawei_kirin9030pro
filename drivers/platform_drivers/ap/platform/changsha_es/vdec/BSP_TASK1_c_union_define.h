#ifndef __BSP_TASK1_C_UNION_DEFINE_H__
#define __BSP_TASK1_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int bsp_task_vdec_ver : 4 ;
        unsigned int bsp_task_rsc_num : 10 ;
        unsigned int bsp_task_frame_msg_addr_hi : 4 ;
        unsigned int bsp_task_bitstream_addr_hi : 4 ;
        unsigned int bsp_task_ctu_header_addr_hi : 4 ;
        unsigned int reserved_0 : 6 ;
    } bits;
    unsigned int u32;
} U_BSP_TASK_PARA0;
typedef union {
    struct {
        unsigned int bsp_task_ctu_header_stride : 16 ;
        unsigned int bsp_task_frame_msg_len : 13 ;
        unsigned int reserved_0 : 2 ;
        unsigned int bsp_upmsg_st_en : 1 ;
    } bits;
    unsigned int u32;
} U_BSP_TASK_PARA3;
typedef struct {
    volatile U_BSP_TASK_PARA0 BSP_TASK_PARA0 ;
    volatile unsigned int BSP_TASK_PARA1 ;
    volatile unsigned int BSP_TASK_PARA2 ;
    volatile U_BSP_TASK_PARA3 BSP_TASK_PARA3 ;
    volatile unsigned int BSP_TASK_PARA4 ;
    volatile unsigned int BSP_TASK_PARA5 ;
    volatile unsigned int BSP_TASK_PARA6 ;
    volatile unsigned int BSP_TASK_PARA7 ;
} S_BSP_TASK1_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_BSP_TASK_PARA0 BSP_TASK_PARA0;
    volatile U_BSP_TASK_PARA3 BSP_TASK_PARA3;
} U_BSP_TASK1_REGS_TYPE;
#endif
