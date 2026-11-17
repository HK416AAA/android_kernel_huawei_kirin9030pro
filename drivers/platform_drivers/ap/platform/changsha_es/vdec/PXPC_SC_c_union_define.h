#ifndef __PXPC_SC_C_UNION_DEFINE_H__
#define __PXPC_SC_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int pxpc_core0_nmi_int_ena : 1 ;
        unsigned int pxpc_core1_nmi_int_ena : 1 ;
        unsigned int reserved_0 : 2 ;
        unsigned int pxpc_core0_nmi_int_clr : 1 ;
        unsigned int pxpc_core1_nmi_int_clr : 1 ;
        unsigned int reserved_1 : 2 ;
        unsigned int pxpc_core0_nmi_int_sta : 1 ;
        unsigned int pxpc_core1_nmi_int_sta : 1 ;
        unsigned int reserved_2 : 22 ;
    } bits;
    unsigned int u32;
} U_PXPC_NMI_INT;
typedef union {
    struct {
        unsigned int pxpc_nmi_maskw_reg : 16 ;
        unsigned int pxpc_nmi_maskw_bitsel : 16 ;
    } bits;
    unsigned int u32;
} U_PXPC_NMI_MASKW_REG;
typedef union {
    struct {
        unsigned int pxpc_core0_halt_ena : 1 ;
        unsigned int pxpc_core1_halt_ena : 1 ;
        unsigned int reserved_0 : 2 ;
        unsigned int pxpc_core0_halt_clr : 1 ;
        unsigned int pxpc_core1_halt_clr : 1 ;
        unsigned int reserved_1 : 2 ;
        unsigned int pxpc_core0_halt_sta : 1 ;
        unsigned int pxpc_core1_halt_sta : 1 ;
        unsigned int reserved_2 : 22 ;
    } bits;
    unsigned int u32;
} U_PXPC_CORE_HALT;
typedef union {
    struct {
        unsigned int core0_clk_ctrl : 1 ;
        unsigned int core1_clk_ctrl : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int dmc_auto_icg_byp : 1 ;
        unsigned int scdbg_clk_en : 1 ;
        unsigned int mpu_clk_en : 1 ;
        unsigned int pdma_if_auto_icg_byp : 1 ;
        unsigned int core0_srst_req : 1 ;
        unsigned int core1_srst_req : 1 ;
        unsigned int pdma_srst_req : 1 ;
        unsigned int reserved_1 : 1 ;
        unsigned int core0_ic_clk_en : 1 ;
        unsigned int core1_ic_clk_en : 1 ;
        unsigned int reserved_2 : 3 ;
        unsigned int crg_ctrl1_mask : 16 ;
    } bits;
    unsigned int u32;
} U_CRG_CTRL1;
typedef union {
    struct {
        unsigned int pxpc_dma_ch_idle : 1 ;
        unsigned int hdma_idle : 1 ;
        unsigned int pxpc_dma_ch0_idle : 1 ;
        unsigned int pxpc_dma_ch1_idle : 1 ;
        unsigned int qsp2lbus_busy : 1 ;
        unsigned int lbus_idle : 1 ;
        unsigned int io2qspm_idle : 1 ;
        unsigned int busy : 1 ;
        unsigned int core0_wfi : 1 ;
        unsigned int core1_wfi : 1 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_SYS_IDLE_STAT;
typedef struct {
    volatile U_PXPC_NMI_INT PXPC_NMI_INT ;
    volatile U_PXPC_NMI_MASKW_REG PXPC_NMI_MASKW_REG ;
    volatile U_PXPC_CORE_HALT PXPC_CORE_HALT ;
    volatile unsigned int reserved_0 ;
    volatile unsigned int SC_CTRL_EN_S ;
    volatile unsigned int SC_CTRL_DIS_S ;
    volatile unsigned int SC_CTRL_STAT_S ;
    volatile unsigned int SC_CTRL_MASK_S ;
    volatile unsigned int SC_CTRL_STAT_MSK_S ;
    volatile unsigned int RV_TASK_QUENE_IDX ;
    volatile unsigned int reserved_1[2] ;
    volatile unsigned int RV_CFG_S_0 ;
    volatile unsigned int RV_CFG_S_1 ;
    volatile unsigned int RV_CFG_S_2 ;
    volatile unsigned int RV_CFG_S_3 ;
    volatile unsigned int reserved_2[241] ;
    volatile U_CRG_CTRL1 CRG_CTRL1 ;
    volatile unsigned int reserved_3[10] ;
    volatile U_SYS_IDLE_STAT SYS_IDLE_STAT ;
    volatile unsigned int reserved_4[499] ;
    volatile unsigned int SC_CTRL_EN_NS ;
    volatile unsigned int SC_CTRL_DIS_NS ;
    volatile unsigned int SC_CTRL_STAT_NS ;
    volatile unsigned int SC_CTRL_MASK_NS ;
    volatile unsigned int SC_CTRL_STAT_MSK_NS ;
    volatile unsigned int RV_TASK_QUENE_IDX_NS ;
    volatile unsigned int reserved_5[2] ;
    volatile unsigned int RV_CFG_NS_0 ;
    volatile unsigned int RV_CFG_NS_1 ;
} S_PXPC_SC_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_PXPC_NMI_INT PXPC_NMI_INT;
    volatile U_PXPC_NMI_MASKW_REG PXPC_NMI_MASKW_REG;
    volatile U_PXPC_CORE_HALT PXPC_CORE_HALT;
    volatile U_CRG_CTRL1 CRG_CTRL1;
    volatile U_SYS_IDLE_STAT SYS_IDLE_STAT;
} U_PXPC_SC_REGS_TYPE;
#endif
