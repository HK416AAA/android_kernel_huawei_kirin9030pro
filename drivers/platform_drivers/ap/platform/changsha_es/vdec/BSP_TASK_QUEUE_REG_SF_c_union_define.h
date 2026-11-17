#ifndef __BSP_TASK_QUEUE_REG_SF_C_UNION_DEFINE_H__
#define __BSP_TASK_QUEUE_REG_SF_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int bsp_task0_addr_hi : 4 ;
        unsigned int bsp_task0_lenth : 14 ;
        unsigned int bsp_task0_flag : 1 ;
        unsigned int bsp_task0_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA0_H;
typedef union {
    struct {
        unsigned int bsp_task_addr_hi : 4 ;
        unsigned int bsp_task_lenth : 14 ;
        unsigned int bsp_task_flag : 1 ;
        unsigned int bsp_task_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA1_H;
typedef union {
    struct {
        unsigned int bsp_task2_addr_hi : 4 ;
        unsigned int bsp_task2_lenth : 14 ;
        unsigned int bsp_task2_flag : 1 ;
        unsigned int bsp_task2_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA2_H;
typedef union {
    struct {
        unsigned int bsp_task3_addr_hi : 4 ;
        unsigned int bsp_task3_lenth : 14 ;
        unsigned int bsp_task3_flag : 1 ;
        unsigned int bsp_task3_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA3_H;
typedef union {
    struct {
        unsigned int bsp_task4_addr_hi : 4 ;
        unsigned int bsp_task4_lenth : 14 ;
        unsigned int bsp_task4_flag : 1 ;
        unsigned int bsp_task4_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA4_H;
typedef union {
    struct {
        unsigned int bsp_task5_addr_hi : 4 ;
        unsigned int bsp_task5_lenth : 14 ;
        unsigned int bsp_task5_flag : 1 ;
        unsigned int bsp_task5_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA5_H;
typedef union {
    struct {
        unsigned int bsp_task6_addr_hi : 4 ;
        unsigned int bsp_task6_lenth : 14 ;
        unsigned int bsp_task6_flag : 1 ;
        unsigned int bsp_task6_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA6_H;
typedef union {
    struct {
        unsigned int bsp_task7_addr_hi : 4 ;
        unsigned int bsp_task7_lenth : 14 ;
        unsigned int bsp_task7_flag : 1 ;
        unsigned int bsp_task7_frm_no : 6 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_TASK_QUEUE_PARA7_H;
typedef union {
    struct {
        unsigned int bsp_ringbuff_res_addr_hi : 4 ;
        unsigned int bsp_ringbuff_res_lenth : 16 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_PARA1;
typedef union {
    struct {
        unsigned int bsp_ringbuff_info_addr_hi : 4 ;
        unsigned int bsp_ringbuff_info_lenth : 16 ;
        unsigned int reserved_0 : 12 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_PARA3;
typedef union {
    struct {
        unsigned int bsp_ringbuff_info_afull_th : 16 ;
        unsigned int bsp_ringbuff_res_afull_th : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_PARA4;
typedef union {
    struct {
        unsigned int bsp_ringbuff_info_wrap_th : 16 ;
        unsigned int bsp_ringbuff_res_wrap_th : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_PARA5;
typedef union {
    struct {
        unsigned int bsp_ringbuff_info_aempty_th : 16 ;
        unsigned int bsp_ringbuff_res_aempty_th : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_PARA6;
typedef union {
    struct {
        unsigned int bsp_ringbuff_info_rptr_en_th : 16 ;
        unsigned int bsp_ringbuff_res_rptr_en_th : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_PARA7;
typedef union {
    struct {
        unsigned int curr_proc_subtask_cnt : 16 ;
        unsigned int curr_proc_ctu_cnt : 16 ;
    } bits;
    unsigned int u32;
} U_RPT_DATA0;
typedef union {
    struct {
        unsigned int ctu_x_cur : 16 ;
        unsigned int ctu_y_cur : 16 ;
    } bits;
    unsigned int u32;
} U_RPT_DATA1;
typedef union {
    struct {
        unsigned int info_wptr_h : 4 ;
        unsigned int res_wptr_h : 4 ;
        unsigned int ctu_row_dec_done_cnt : 16 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_RPT_DATA2;
typedef struct {
    volatile unsigned int TASK_QUEUE_PARA0_L;
    volatile U_TASK_QUEUE_PARA0_H TASK_QUEUE_PARA0_H;
    volatile unsigned int TASK_QUEUE_PARA1_L;
    volatile U_TASK_QUEUE_PARA1_H TASK_QUEUE_PARA1_H;
    volatile unsigned int TASK_QUEUE_PARA2_L;
    volatile U_TASK_QUEUE_PARA2_H TASK_QUEUE_PARA2_H;
    volatile unsigned int TASK_QUEUE_PARA3_L;
    volatile U_TASK_QUEUE_PARA3_H TASK_QUEUE_PARA3_H;
    volatile unsigned int TASK_QUEUE_PARA4_L;
    volatile U_TASK_QUEUE_PARA4_H TASK_QUEUE_PARA4_H;
    volatile unsigned int TASK_QUEUE_PARA5_L;
    volatile U_TASK_QUEUE_PARA5_H TASK_QUEUE_PARA5_H;
    volatile unsigned int TASK_QUEUE_PARA6_L;
    volatile U_TASK_QUEUE_PARA6_H TASK_QUEUE_PARA6_H;
    volatile unsigned int TASK_QUEUE_PARA7_L;
    volatile U_TASK_QUEUE_PARA7_H TASK_QUEUE_PARA7_H;
} S_BSP_TASK_QUEUE_REG_SF_REGS_TASK_0_TYPE;
typedef struct {
    volatile unsigned int BSP_INIT_PARA0;
    volatile U_BSP_INIT_PARA1 BSP_INIT_PARA1;
    volatile unsigned int BSP_INIT_PARA2;
    volatile U_BSP_INIT_PARA3 BSP_INIT_PARA3;
    volatile U_BSP_INIT_PARA4 BSP_INIT_PARA4;
    volatile U_BSP_INIT_PARA5 BSP_INIT_PARA5;
    volatile U_BSP_INIT_PARA6 BSP_INIT_PARA6;
    volatile U_BSP_INIT_PARA7 BSP_INIT_PARA7;
    volatile unsigned int BSP_RENEW_WPTR0_SAFE;
    volatile unsigned int BSP_RENEW_WPTR1_SAFE;
    volatile unsigned int RSV2;
    volatile unsigned int RSV3;
    volatile U_RPT_DATA0 RPT_DATA0;
    volatile U_RPT_DATA1 RPT_DATA1;
    volatile U_RPT_DATA2 RPT_DATA2;
    volatile unsigned int RPT_DATA3;
    volatile unsigned int RPT_DATA4;
    volatile unsigned int RPT_RSV0;
    volatile unsigned int RPT_RSV1;
    volatile unsigned int RPT_RSV2;
} S_BSP_TASK_QUEUE_REG_SF_REGS_BSP_80_TYPE;
typedef union {
    unsigned int u32;
    volatile U_TASK_QUEUE_PARA0_H TASK_QUEUE_PARA0_H;
    volatile U_TASK_QUEUE_PARA1_H TASK_QUEUE_PARA1_H;
    volatile U_TASK_QUEUE_PARA2_H TASK_QUEUE_PARA2_H;
    volatile U_TASK_QUEUE_PARA3_H TASK_QUEUE_PARA3_H;
    volatile U_TASK_QUEUE_PARA4_H TASK_QUEUE_PARA4_H;
    volatile U_TASK_QUEUE_PARA5_H TASK_QUEUE_PARA5_H;
    volatile U_TASK_QUEUE_PARA6_H TASK_QUEUE_PARA6_H;
    volatile U_TASK_QUEUE_PARA7_H TASK_QUEUE_PARA7_H;
    volatile U_BSP_INIT_PARA1 BSP_INIT_PARA1;
    volatile U_BSP_INIT_PARA3 BSP_INIT_PARA3;
    volatile U_BSP_INIT_PARA4 BSP_INIT_PARA4;
    volatile U_BSP_INIT_PARA5 BSP_INIT_PARA5;
    volatile U_BSP_INIT_PARA6 BSP_INIT_PARA6;
    volatile U_BSP_INIT_PARA7 BSP_INIT_PARA7;
    volatile U_RPT_DATA0 RPT_DATA0;
    volatile U_RPT_DATA1 RPT_DATA1;
    volatile U_RPT_DATA2 RPT_DATA2;
} U_BSP_TASK_QUEUE_REG_SF_REGS_TYPE;
typedef struct {
 volatile unsigned int TASK_QUEUE_PARA0_L;
 volatile U_TASK_QUEUE_PARA0_H TASK_QUEUE_PARA0_H;
} S_TASK_QUEUE_PARA;
typedef struct {
 volatile S_TASK_QUEUE_PARA TASK_QUEUE_PARA[8];
 volatile unsigned int RSV[16];
 volatile unsigned int BSP_INIT_PARA0;
 volatile U_BSP_INIT_PARA1 BSP_INIT_PARA1;
 volatile unsigned int BSP_INIT_PARA2;
 volatile U_BSP_INIT_PARA3 BSP_INIT_PARA3;
 volatile U_BSP_INIT_PARA4 BSP_INIT_PARA4;
 volatile U_BSP_INIT_PARA5 BSP_INIT_PARA5;
 volatile U_BSP_INIT_PARA6 BSP_INIT_PARA6;
 volatile U_BSP_INIT_PARA7 BSP_INIT_PARA7;
    volatile unsigned int BSP_RENEW_WPTR0_SAFE;
    volatile unsigned int BSP_RENEW_WPTR1_SAFE;
 volatile unsigned int RSV2;
 volatile unsigned int RSV3;
 volatile U_RPT_DATA0 RPT_DATA0;
 volatile U_RPT_DATA1 RPT_DATA1;
 volatile U_RPT_DATA2 RPT_DATA2;
 volatile unsigned int RPT_DATA3;
 volatile unsigned int RPT_DATA4;
 volatile unsigned int RPT_RSV0;
 volatile unsigned int RPT_RSV1;
 volatile unsigned int RPT_RSV2;
 volatile unsigned int RSV4[12];
} S_ONE_BSP_TASK_QUEUE_REGS_TYPE;
typedef struct {
 volatile S_ONE_BSP_TASK_QUEUE_REGS_TYPE BSP[4];
} S_BSP_TASK_QUEUE_REG_SF_REGS_TYPE;
#endif
