#ifndef __BSP_TOP_SCTRL_C_UNION_DEFINE_H__
#define __BSP_TOP_SCTRL_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int bsp_clk_en : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_BSP_CRG_EN;
typedef union {
    struct {
        unsigned int bsp_clk_dis : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_BSP_CRG_DIS;
typedef union {
    struct {
        unsigned int bsp_clk_stat : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_BSP_CRG_ST;
typedef union {
    struct {
        unsigned int bsp_rst_en : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_BSP_RST_EN;
typedef union {
    struct {
        unsigned int bsp_rst_dis : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_BSP_RST_DIS;
typedef union {
    struct {
        unsigned int bsp_rst_stat : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_BSP_RST_ST;
typedef union {
    struct {
        unsigned int bsp_acc0_ckg_bypass : 1 ;
        unsigned int bsp_acc1_ckg_bypass : 1 ;
        unsigned int bsp_acc2_ckg_bypass : 1 ;
        unsigned int bsp_acc3_ckg_bypass : 1 ;
        unsigned int hac2qsp_ckg_bypass : 1 ;
        unsigned int bsp_lbus_ckg_bypass : 1 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_BSP_CKG_BYPASS;
typedef union {
    struct {
        unsigned int bsp_sw_init_addr_hi_sf : 4 ;
        unsigned int reserved_0 : 27 ;
        unsigned int reserved_1 : 1 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_MODE_2;
typedef union {
    struct {
        unsigned int bsp_halt_ena : 1 ;
        unsigned int reserved_0 : 15 ;
        unsigned int bsp_halt_clr : 1 ;
        unsigned int reserved_1 : 15 ;
    } bits;
    unsigned int u32;
} U_BSP_CORE_CFG;
typedef union {
    struct {
        unsigned int bsp_halt_sta : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int reserved_1 : 2 ;
        unsigned int bsp_wfi_sta : 1 ;
        unsigned int reserved_2 : 1 ;
        unsigned int reserved_3 : 2 ;
        unsigned int bsp_core_subsys_busy : 1 ;
        unsigned int reserved_4 : 1 ;
        unsigned int reserved_5 : 2 ;
        unsigned int reserved_6 : 1 ;
        unsigned int reserved_7 : 19 ;
    } bits;
    unsigned int u32;
} U_BSP_CORE_STAT_0;
typedef union {
    struct {
        unsigned int bsp_nmi_int_ena : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int bsp_nmi_int_clr : 1 ;
        unsigned int reserved_1 : 3 ;
        unsigned int bsp_nmi_int_sta : 1 ;
        unsigned int reserved_2 : 23 ;
    } bits;
    unsigned int u32;
} U_BSP_NMI_INT;
typedef union {
    struct {
        unsigned int bsp_sw_init_addr_hi : 4 ;
        unsigned int bsp_retention_en : 1 ;
        unsigned int bsp_ringbuff_mode_flag : 1 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_BSP_INIT_MODE_0;
typedef struct {
    volatile U_BSP_CRG_EN BSP_CRG_EN ;
    volatile U_BSP_CRG_DIS BSP_CRG_DIS ;
    volatile unsigned int BSP_CRG_2 ;
    volatile U_BSP_CRG_ST BSP_CRG_ST ;
    volatile U_BSP_RST_EN BSP_RST_EN ;
    volatile U_BSP_RST_DIS BSP_RST_DIS ;
    volatile unsigned int BSP_CRG_6 ;
    volatile U_BSP_RST_ST BSP_RST_ST ;
    volatile U_BSP_CKG_BYPASS BSP_CKG_BYPASS ;
    volatile unsigned int reserved_0 ;
    volatile unsigned int reserved_1[1014] ;
    volatile U_BSP_CORE_CFG BSP_CORE_CFG ;
    volatile U_BSP_CORE_STAT_0 BSP_CORE_STAT_0 ;
    volatile unsigned int BSP_CORE_STAT_1 ;
    volatile U_BSP_NMI_INT BSP_NMI_INT ;
    volatile unsigned int BSP_NMI_MASKW_REG ;
    volatile unsigned int SUBCTRL_IPC_ADDR_0 ;
    volatile unsigned int SUBCTRL_IPC_ADDR_1 ;
    volatile unsigned int reserved_2 ;
    volatile U_BSP_INIT_MODE_0 BSP_INIT_MODE_0 ;
    volatile unsigned int BSP_INIT_MODE_1 ;
    volatile U_BSP_INIT_MODE_2 BSP_INIT_MODE_2 ;
    volatile unsigned int BSP_INIT_MODE_3 ;
} S_BSP_TOP_SCTRL_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_BSP_CRG_EN BSP_CRG_EN;
    volatile U_BSP_CRG_DIS BSP_CRG_DIS;
    volatile U_BSP_CRG_ST BSP_CRG_ST;
    volatile U_BSP_RST_EN BSP_RST_EN;
    volatile U_BSP_RST_DIS BSP_RST_DIS;
    volatile U_BSP_RST_ST BSP_RST_ST;
    volatile U_BSP_CKG_BYPASS BSP_CKG_BYPASS;
    volatile U_BSP_INIT_MODE_2 BSP_INIT_MODE_2;
    volatile U_BSP_CORE_CFG BSP_CORE_CFG;
    volatile U_BSP_CORE_STAT_0 BSP_CORE_STAT_0;
    volatile U_BSP_NMI_INT BSP_NMI_INT;
    volatile U_BSP_INIT_MODE_0 BSP_INIT_MODE_0;
} U_BSP_TOP_SCTRL_REGS_TYPE;
#endif
