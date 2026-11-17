#ifndef __BSP_SUBTASK1_C_UNION_DEFINE_H__
#define __BSP_SUBTASK1_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int bsp_subtask_mode : 1 ;
        unsigned int reserved_0 : 2 ;
        unsigned int bsp_subtask_intr_flag : 1 ;
        unsigned int bsp_subtask_end_flag : 1 ;
        unsigned int bsp_subtask_inner_intr_flag : 1 ;
        unsigned int bsp_subtask_inner_intr_gap : 6 ;
        unsigned int bsp_nxsubtask_bitstream_addr_h : 4 ;
        unsigned int bsp_subtask_startctu_y : 10 ;
        unsigned int slice_size_type : 2 ;
        unsigned int reserved_1 : 4 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA0;
typedef union {
    struct {
        unsigned int bsp_subtask_startctu_x : 10 ;
        unsigned int bsp_nxsubtask_startctu_y : 10 ;
        unsigned int bsp_nxsubtask_startctu_x : 12 ;
    } bits;
    unsigned int u32;
} U_BSP_SUBTASK_PARA1;
typedef struct {
    volatile U_BSP_SUBTASK_PARA0 BSP_SUBTASK_PARA0 ;
    volatile U_BSP_SUBTASK_PARA1 BSP_SUBTASK_PARA1 ;
    volatile unsigned int BSP_SUBTASK_PARA2 ;
    volatile unsigned int BSP_SUBTASK_PARA3 ;
} S_BSP_SUBTASK1_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_BSP_SUBTASK_PARA0 BSP_SUBTASK_PARA0;
    volatile U_BSP_SUBTASK_PARA1 BSP_SUBTASK_PARA1;
} U_BSP_SUBTASK1_REGS_TYPE;
#endif
