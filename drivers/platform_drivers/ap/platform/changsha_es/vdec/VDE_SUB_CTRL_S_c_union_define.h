#ifndef __VDE_SUB_CTRL_S_C_UNION_DEFINE_H__
#define __VDE_SUB_CTRL_S_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int reserved_0 : 1 ;
        unsigned int mcu_secure_n_s : 1 ;
        unsigned int mcu_itcm_secure_n_s : 1 ;
        unsigned int reserved_1 : 29 ;
    } bits;
    unsigned int u32;
} U_VDEC_SECURE;
typedef union {
    struct {
        unsigned int task_indicator_bsp0_s : 8 ;
        unsigned int task_thredth_bsp0_s : 8 ;
        unsigned int task_indicator_bsp1_s : 8 ;
        unsigned int task_thredth_bsp1 : 8 ;
    } bits;
    unsigned int u32;
} U_BSP_TASK_INDICATOR0_S;
typedef union {
    struct {
        unsigned int task_indicator_pxpc_s : 8 ;
        unsigned int task_thredth_pxpc_s : 8 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_PXPC_TASK_INDICATOR_S;
typedef union {
    struct {
        unsigned int new_task_pause_bsp0_s : 1 ;
        unsigned int new_task_pause_bsp1_s : 1 ;
        unsigned int reserved_0 : 14 ;
        unsigned int new_task_pause_pxpc_s : 1 ;
        unsigned int reserved_1 : 15 ;
    } bits;
    unsigned int u32;
} U_NEW_TASK_S;
typedef union {
    struct {
        unsigned int intr_pxpc_wr_s : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_S_PXPC_WR0;
typedef union {
    struct {
        unsigned int intr_pxpc_s : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_S_PXPC0;
typedef union {
    struct {
        unsigned int intr_pxpc_mask_s : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_MASK_S_PXPC;
typedef union {
    struct {
        unsigned int intr_pxpc_clr_s : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_CLR_S_PXPC;
typedef union {
    struct {
        unsigned int intr_120hz_sel_s : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_INTR_SEL_S_DSS_SYNC;
typedef union {
    struct {
        unsigned int bsp_subtask_intr0_cnt_s : 4 ;
        unsigned int bsp_subtask_intr1_cnt_s : 4 ;
        unsigned int reserved_0 : 8 ;
        unsigned int bsp_task_intr0_cnt_s : 4 ;
        unsigned int bsp_task_intr1_cnt_s : 4 ;
        unsigned int reserved_1 : 8 ;
    } bits;
    unsigned int u32;
} U_INTR_CNT_STAT0_S;
typedef union {
    struct {
        unsigned int reserved_0 : 4 ;
        unsigned int pxpc_frm_intr_cnt_s : 4 ;
        unsigned int pxpc_task_intr_cnt_s : 4 ;
        unsigned int pxpc_maintask_intr_cnt_s : 4 ;
        unsigned int reserved_1 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_CNT_STAT1_S;
typedef union {
    struct {
        unsigned int intr_cnt_rsv_s : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_INTR_CNT_RSV_S;
typedef union {
    struct {
        unsigned int mcu_reg_base_addr : 17 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_MCU_REG_BASE_ADDR;
typedef union {
    struct {
        unsigned int vdeccore_cfg_qic_device_s : 24 ;
        unsigned int vdec_cfg_qic_device_s : 8 ;
    } bits;
    unsigned int u32;
} U_QIC_DEVICE_CFG_S;
typedef struct {
    volatile U_VDEC_SECURE VDEC_SECURE ;
    volatile unsigned int reserved_0[7] ;
    volatile U_BSP_TASK_INDICATOR0_S BSP_TASK_INDICATOR0_S ;
    volatile unsigned int BSP_TASK_INDICATOR1_S ;
    volatile U_PXPC_TASK_INDICATOR_S PXPC_TASK_INDICATOR_S ;
    volatile U_NEW_TASK_S NEW_TASK_S ;
    volatile unsigned int reserved_1[4] ;
    volatile U_INTR_S_PXPC_WR0 INTR_S_PXPC_WR0 ;
    volatile U_INTR_S_PXPC0 INTR_S_PXPC0 ;
    volatile unsigned int reserved_2 ;
    volatile unsigned int INTR_S_BSP_WR0 ;
    volatile unsigned int INTR_S_BSP0 ;
    volatile unsigned int reserved_3[4] ;
    volatile unsigned int INTR_S_VDEC ;
    volatile unsigned int reserved_4[2] ;
    volatile U_INTR_MASK_S_PXPC INTR_MASK_S_PXPC ;
    volatile unsigned int reserved_5[2] ;
    volatile unsigned int INTR_MASK_S_BSP0 ;
    volatile unsigned int reserved_6[4] ;
    volatile unsigned int INTR_MASK_S_VDEC ;
    volatile unsigned int reserved_7[3] ;
    volatile U_INTR_CLR_S_PXPC INTR_CLR_S_PXPC ;
    volatile unsigned int reserved_8[2] ;
    volatile unsigned int INTR_CLR_S_BSP0 ;
    volatile unsigned int reserved_9[4] ;
    volatile unsigned int INTR_CLR_S_VDEC ;
    volatile unsigned int reserved_10[3] ;
    volatile U_INTR_SEL_S_DSS_SYNC INTR_SEL_S_DSS_SYNC ;
    volatile U_INTR_CNT_STAT0_S INTR_CNT_STAT0_S ;
    volatile U_INTR_CNT_STAT1_S INTR_CNT_STAT1_S ;
    volatile U_INTR_CNT_RSV_S INTR_CNT_RSV_S[8] ;
    volatile unsigned int reserved_11 ;
    volatile unsigned int MCU_ITCM_BASE_ADDR ;
    volatile unsigned int MCU_DTCM_BASE_ADDR ;
    volatile U_MCU_REG_BASE_ADDR MCU_REG_BASE_ADDR ;
    volatile unsigned int MCU_MMEM_START_ADDR ;
    volatile unsigned int MCU_MMEM_END_ADDR ;
    volatile unsigned int MCU_PMEM_START_ADDR ;
    volatile unsigned int MCU_PMEM_END_ADDR ;
    volatile unsigned int reserved_12[57] ;
    volatile U_QIC_DEVICE_CFG_S QIC_DEVICE_CFG_S ;
} S_VDE_SUB_CTRL_S_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_VDEC_SECURE VDEC_SECURE;
    volatile U_BSP_TASK_INDICATOR0_S BSP_TASK_INDICATOR0_S;
    volatile U_PXPC_TASK_INDICATOR_S PXPC_TASK_INDICATOR_S;
    volatile U_NEW_TASK_S NEW_TASK_S;
    volatile U_INTR_S_PXPC_WR0 INTR_S_PXPC_WR0;
    volatile U_INTR_S_PXPC0 INTR_S_PXPC0;
    volatile U_INTR_MASK_S_PXPC INTR_MASK_S_PXPC;
    volatile U_INTR_CLR_S_PXPC INTR_CLR_S_PXPC;
    volatile U_INTR_SEL_S_DSS_SYNC INTR_SEL_S_DSS_SYNC;
    volatile U_INTR_CNT_STAT0_S INTR_CNT_STAT0_S;
    volatile U_INTR_CNT_STAT1_S INTR_CNT_STAT1_S;
    volatile U_INTR_CNT_RSV_S INTR_CNT_RSV_S;
    volatile U_MCU_REG_BASE_ADDR MCU_REG_BASE_ADDR;
    volatile U_QIC_DEVICE_CFG_S QIC_DEVICE_CFG_S;
} U_VDE_SUB_CTRL_S_REGS_TYPE;
#endif
