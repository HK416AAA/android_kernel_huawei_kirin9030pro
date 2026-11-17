#ifndef __SUB_CTRL_H__
#define __SUB_CTRL_H__ 
typedef union
{
    struct
    {
        unsigned int mcu_por_rst : 1 ;
        unsigned int mcu_wdt_rst : 1 ;
        unsigned int reserved_0 : 6 ;
        unsigned int mcu_core_wait : 1 ;
        unsigned int reserved_1 : 23 ;
    } bits;
    unsigned int u32;
} U_SUBCTRL_CRG0;
typedef union
{
    struct
    {
        unsigned int mcu_clk_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SUBCTRL_CRG1;
typedef union
{
    struct
    {
        unsigned int reserved_0 : 1 ;
        unsigned int ipc_soft_rst : 1 ;
        unsigned int tim_soft_rst : 1 ;
        unsigned int uart_soft_rst : 1 ;
        unsigned int reserved_1 : 12 ;
        unsigned int vedu_core_soft_rst : 1 ;
        unsigned int axi_core_soft_rst : 1 ;
        unsigned int reserved_2 : 14 ;
    } bits;
    unsigned int u32;
} U_SUBCTRL_CRG2;
typedef union
{
    struct
    {
        unsigned int reserved_0 : 1 ;
        unsigned int ipc_clk_en : 1 ;
        unsigned int tim_clk_en : 1 ;
        unsigned int uart_clk_en : 1 ;
        unsigned int reserved_1 : 28 ;
    } bits;
    unsigned int u32;
} U_SUBCTRL_CRG3;
typedef union
{
    struct
    {
        unsigned int mcu_soft_nmi : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SUBCTRL_MCU_NMI;
typedef union
{
    struct
    {
        unsigned int core_sleep_mode : 1 ;
        unsigned int core_debug_mode : 1 ;
        unsigned int core_hard_fault_mode : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int venc_mcu_dbgen : 1 ;
        unsigned int reserved_1 : 27 ;
    } bits;
    unsigned int u32;
} U_SUBCTRL_HW_BUF_LEN;
typedef union
{
    struct
    {
        unsigned int ahb_mst_pri : 2 ;
        unsigned int reserved_0 : 6 ;
        unsigned int reserved_1 : 1 ;
        unsigned int reserved_2 : 1 ;
        unsigned int reserved_3 : 1 ;
        unsigned int reserved_4 : 21 ;
    } bits;
    unsigned int u32;
} U_SUBCTRL_AHB_MATRIX_PRI;
typedef union
{
    struct
    {
        unsigned int mcu_lcu_latency_cnt : 10 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_MCU_LCU_LATENCY_CNT;
typedef struct
{
    volatile U_SUBCTRL_CRG0 SUBCTRL_CRG0;
    volatile U_SUBCTRL_CRG1 SUBCTRL_CRG1;
    volatile U_SUBCTRL_CRG2 SUBCTRL_CRG2;
    volatile U_SUBCTRL_CRG3 SUBCTRL_CRG3;
    volatile unsigned int SUBCTRL_MCU_POR_PC;
    volatile unsigned int SUBCTRL_RESERVED_0;
    volatile U_SUBCTRL_MCU_NMI SUBCTRL_MCU_NMI;
    volatile unsigned int SUBCTRL_RESERVED_1[9];
    volatile U_SUBCTRL_HW_BUF_LEN SUBCTRL_HW_BUF_LEN;
    volatile unsigned int SUBCTRL_RESERVED_2[3];
    volatile U_SUBCTRL_AHB_MATRIX_PRI SUBCTRL_AHB_MATRIX_PRI;
    volatile unsigned int reserved_3[7] ;
    volatile U_MCU_LCU_LATENCY_CNT MCU_LCU_LATENCY_CNT ;
    volatile unsigned int reserved_4[995];
} S_VE_SUB_CTRL_REGS_TYPE;
#endif
