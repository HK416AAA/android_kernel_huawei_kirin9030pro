#ifndef __SOC_UFS_SYSCTRL_INTERFACE_H__
#define __SOC_UFS_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_ADDR(base) ((base) + (0x000UL))
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ADDR(base) ((base) + (0x008UL))
#define SOC_UFS_SYSCTRL_CRG_DIV_GATE_CFG_ADDR(base) ((base) + (0x030UL))
#define SOC_UFS_SYSCTRL_CRG_DIV_CFG_ADDR(base) ((base) + (0x034UL))
#define SOC_UFS_SYSCTRL_CRG_UFS_STAT_ADDR(base) ((base) + (0x080UL))
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ADDR(base) ((base) + (0x0F0UL))
#define SOC_UFS_SYSCTRL_MPHYMCU_TEST_POINT_ADDR(base) ((base) + (0x100UL))
#define SOC_UFS_SYSCTRL_TESTPOINT_CTRL_ADDR(base) ((base) + (0x104UL))
#define SOC_UFS_SYSCTRL_DEBUG_CLK_EN_ADDR(base) ((base) + (0x108UL))
#define SOC_UFS_SYSCTRL_UFS_DEVICE_RESET_ADDR(base) ((base) + (0x10CUL))
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_ADDR(base) ((base) + (0x110UL))
#define SOC_UFS_SYSCTRL_HIUFS_DEBUG_ADDR(base) ((base) + (0x120UL))
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ADDR(base) ((base) + (0x200UL))
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ADDR(base) ((base) + (0x204UL))
#define SOC_UFS_SYSCTRL_UFS_AXI_CTRL_ADDR(base) ((base) + (0x210UL))
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_TP_ADDR(base) ((base) + (0x280UL))
#define SOC_UFS_SYSCTRL_AO_MEMORY_CTRL_ADDR(base) ((base) + (0x284UL))
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_ADDR(base) ((base) + (0x288UL))
#define SOC_UFS_SYSCTRL_UFS_AXUSER_CFG_ADDR(base) ((base) + (0x300UL))
#define SOC_UFS_SYSCTRL_UFS_AXCACHE_CFG_ADDR(base) ((base) + (0x304UL))
#define SOC_UFS_SYSCTRL_UFS_SMMU_MEM_CTRL_SD_ADDR(base) ((base) + (0x400UL))
#define SOC_UFS_SYSCTRL_UFS_ENHANCE_CTRL_ADDR(base) ((base) + (0xF00UL))
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ADDR(base) ((base) + (0x1000UL))
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ADDR(base) ((base) + (0x1004UL))
#define SOC_UFS_SYSCTRL_SC_UFS_MMU_ID_SEL_ADDR(base) ((base) + (0x1800UL))
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_ADDR(base) ((base) + (0x1804UL))
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_ADDR(base) ((base) + (0x1808UL))
#define SOC_UFS_SYSCTRL_SC_TCU_TRACE_AXI_MUX_SEL_ADDR(base) ((base) + (0x1810UL))
#else
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_ADDR(base) ((base) + (0x000))
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ADDR(base) ((base) + (0x008))
#define SOC_UFS_SYSCTRL_CRG_DIV_GATE_CFG_ADDR(base) ((base) + (0x030))
#define SOC_UFS_SYSCTRL_CRG_DIV_CFG_ADDR(base) ((base) + (0x034))
#define SOC_UFS_SYSCTRL_CRG_UFS_STAT_ADDR(base) ((base) + (0x080))
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ADDR(base) ((base) + (0x0F0))
#define SOC_UFS_SYSCTRL_MPHYMCU_TEST_POINT_ADDR(base) ((base) + (0x100))
#define SOC_UFS_SYSCTRL_TESTPOINT_CTRL_ADDR(base) ((base) + (0x104))
#define SOC_UFS_SYSCTRL_DEBUG_CLK_EN_ADDR(base) ((base) + (0x108))
#define SOC_UFS_SYSCTRL_UFS_DEVICE_RESET_ADDR(base) ((base) + (0x10C))
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_ADDR(base) ((base) + (0x110))
#define SOC_UFS_SYSCTRL_HIUFS_DEBUG_ADDR(base) ((base) + (0x120))
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ADDR(base) ((base) + (0x200))
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ADDR(base) ((base) + (0x204))
#define SOC_UFS_SYSCTRL_UFS_AXI_CTRL_ADDR(base) ((base) + (0x210))
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_TP_ADDR(base) ((base) + (0x280))
#define SOC_UFS_SYSCTRL_AO_MEMORY_CTRL_ADDR(base) ((base) + (0x284))
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_ADDR(base) ((base) + (0x288))
#define SOC_UFS_SYSCTRL_UFS_AXUSER_CFG_ADDR(base) ((base) + (0x300))
#define SOC_UFS_SYSCTRL_UFS_AXCACHE_CFG_ADDR(base) ((base) + (0x304))
#define SOC_UFS_SYSCTRL_UFS_SMMU_MEM_CTRL_SD_ADDR(base) ((base) + (0x400))
#define SOC_UFS_SYSCTRL_UFS_ENHANCE_CTRL_ADDR(base) ((base) + (0xF00))
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ADDR(base) ((base) + (0x1000))
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ADDR(base) ((base) + (0x1004))
#define SOC_UFS_SYSCTRL_SC_UFS_MMU_ID_SEL_ADDR(base) ((base) + (0x1800))
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_ADDR(base) ((base) + (0x1804))
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_ADDR(base) ((base) + (0x1808))
#define SOC_UFS_SYSCTRL_SC_TCU_TRACE_AXI_MUX_SEL_ADDR(base) ((base) + (0x1810))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_ufs : 1;
        unsigned int gt_hclk_ufs_top : 1;
        unsigned int gt_pclk_ufs_mphy_apb : 1;
        unsigned int gt_clk_ufsphy_cfg : 1;
        unsigned int gt_clk_ufs_mphymcu_bus : 1;
        unsigned int gt_clk_ufs_mphymcu : 1;
        unsigned int gt_pclk_ufs_debug : 1;
        unsigned int gt_pclk_ufs_djtag_s : 1;
        unsigned int gt_clk_ufs_32k : 1;
        unsigned int gt_clk_ufs_tick : 1;
        unsigned int gt_clk_ufs_km : 1;
        unsigned int gt_clk_ufs_mphymcu_19p2 : 1;
        unsigned int gt_clk_ufs_km_19p2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_UFS_SYSCTRL_CRG_CLK_CFG0_UNION;
#endif
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_START (0)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_END (0)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_hclk_ufs_top_START (1)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_hclk_ufs_top_END (1)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_pclk_ufs_mphy_apb_START (2)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_pclk_ufs_mphy_apb_END (2)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufsphy_cfg_START (3)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufsphy_cfg_END (3)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_mphymcu_bus_START (4)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_mphymcu_bus_END (4)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_mphymcu_START (5)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_mphymcu_END (5)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_pclk_ufs_debug_START (6)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_pclk_ufs_debug_END (6)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_pclk_ufs_djtag_s_START (7)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_pclk_ufs_djtag_s_END (7)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_32k_START (8)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_32k_END (8)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_tick_START (9)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_tick_END (9)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_km_START (10)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_km_END (10)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_mphymcu_19p2_START (11)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_mphymcu_19p2_END (11)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_km_19p2_START (12)
#define SOC_UFS_SYSCTRL_CRG_CLK_CFG0_gt_clk_ufs_km_19p2_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_ufs : 1;
        unsigned int ip_arst_ufs : 1;
        unsigned int ip_prst_ufs_debug : 1;
        unsigned int ip_prst_dgtag_s : 1;
        unsigned int ip_rst_mphymcu_bus : 1;
        unsigned int ip_rst_mphymcu_arc4 : 1;
        unsigned int ip_rst_mphymcu_19p2 : 1;
        unsigned int ip_prst_mphy_apb : 1;
        unsigned int ip_hrst_ufs_dcdr : 1;
        unsigned int ip_rst_ufs_km : 1;
        unsigned int ip_rst_ufs_km_19p2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 16;
    } reg;
} SOC_UFS_SYSCTRL_CRG_RST_CFG0_UNION;
#endif
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_ufs_START (0)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_ufs_END (0)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_arst_ufs_START (1)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_arst_ufs_END (1)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_prst_ufs_debug_START (2)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_prst_ufs_debug_END (2)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_prst_dgtag_s_START (3)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_prst_dgtag_s_END (3)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_mphymcu_bus_START (4)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_mphymcu_bus_END (4)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_mphymcu_arc4_START (5)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_mphymcu_arc4_END (5)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_mphymcu_19p2_START (6)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_mphymcu_19p2_END (6)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_prst_mphy_apb_START (7)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_prst_mphy_apb_END (7)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_hrst_ufs_dcdr_START (8)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_hrst_ufs_dcdr_END (8)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_ufs_km_START (9)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_ufs_km_END (9)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_ufs_km_19p2_START (10)
#define SOC_UFS_SYSCTRL_CRG_RST_CFG0_ip_rst_ufs_km_19p2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_ufs_tick_div : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_UFS_SYSCTRL_CRG_DIV_GATE_CFG_UNION;
#endif
#define SOC_UFS_SYSCTRL_CRG_DIV_GATE_CFG_sc_gt_clk_ufs_tick_div_START (0)
#define SOC_UFS_SYSCTRL_CRG_DIV_GATE_CFG_sc_gt_clk_ufs_tick_div_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_ufs_tick : 6;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_UFS_SYSCTRL_CRG_DIV_CFG_UNION;
#endif
#define SOC_UFS_SYSCTRL_CRG_DIV_CFG_div_ufs_tick_START (0)
#define SOC_UFS_SYSCTRL_CRG_DIV_CFG_div_ufs_tick_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crg_ufs_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_SYSCTRL_CRG_UFS_STAT_UNION;
#endif
#define SOC_UFS_SYSCTRL_CRG_UFS_STAT_crg_ufs_stat_START (0)
#define SOC_UFS_SYSCTRL_CRG_UFS_STAT_crg_ufs_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_ufshc_unipro_cfg_clkrst_bypass : 1;
        unsigned int ufs_mphy_cfg_clkrst_bypass : 1;
        unsigned int ufs_ahbcfg_clkrst_bypass : 1;
        unsigned int ufs_trace_clkrst_bypass : 1;
        unsigned int ufs_km_clkrst_bypass : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_UNION;
#endif
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_ufshc_unipro_cfg_clkrst_bypass_START (0)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_ufshc_unipro_cfg_clkrst_bypass_END (0)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_mphy_cfg_clkrst_bypass_START (1)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_mphy_cfg_clkrst_bypass_END (1)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_ahbcfg_clkrst_bypass_START (2)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_ahbcfg_clkrst_bypass_END (2)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_trace_clkrst_bypass_START (3)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_trace_clkrst_bypass_END (3)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_km_clkrst_bypass_START (4)
#define SOC_UFS_SYSCTRL_CRG_CLKRST_BYPASS_ufs_km_clkrst_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mphymcu_test_point : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_SYSCTRL_MPHYMCU_TEST_POINT_UNION;
#endif
#define SOC_UFS_SYSCTRL_MPHYMCU_TEST_POINT_mphymcu_test_point_START (0)
#define SOC_UFS_SYSCTRL_MPHYMCU_TEST_POINT_mphymcu_test_point_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_tp_observe_ctrl : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_UFS_SYSCTRL_TESTPOINT_CTRL_UNION;
#endif
#define SOC_UFS_SYSCTRL_TESTPOINT_CTRL_sc_tp_observe_ctrl_START (0)
#define SOC_UFS_SYSCTRL_TESTPOINT_CTRL_sc_tp_observe_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_debug_clk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_SYSCTRL_DEBUG_CLK_EN_UNION;
#endif
#define SOC_UFS_SYSCTRL_DEBUG_CLK_EN_sc_gt_debug_clk_START (0)
#define SOC_UFS_SYSCTRL_DEBUG_CLK_EN_sc_gt_debug_clk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_device_rst_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_SYSCTRL_UFS_DEVICE_RESET_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_DEVICE_RESET_ufs_device_rst_n_START (0)
#define SOC_UFS_SYSCTRL_UFS_DEVICE_RESET_ufs_device_rst_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mphy_reg_bypass_40to20 : 1;
        unsigned int mphy_ufs_en : 1;
        unsigned int mphy_i2c_sel : 1;
        unsigned int mphymcu_jtag_sel : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_UNION;
#endif
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphy_reg_bypass_40to20_START (0)
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphy_reg_bypass_40to20_END (0)
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphy_ufs_en_START (1)
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphy_ufs_en_END (1)
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphy_i2c_sel_START (2)
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphy_i2c_sel_END (2)
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphymcu_jtag_sel_START (3)
#define SOC_UFS_SYSCTRL_HIUFS_MPHY_CFG_mphymcu_jtag_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_remote_hibernate_exit : 1;
        unsigned int mphy_pll_lock : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_SYSCTRL_HIUFS_DEBUG_UNION;
#endif
#define SOC_UFS_SYSCTRL_HIUFS_DEBUG_intr_remote_hibernate_exit_START (0)
#define SOC_UFS_SYSCTRL_HIUFS_DEBUG_intr_remote_hibernate_exit_END (0)
#define SOC_UFS_SYSCTRL_HIUFS_DEBUG_mphy_pll_lock_START (1)
#define SOC_UFS_SYSCTRL_HIUFS_DEBUG_mphy_pll_lock_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufsaxi_w_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int ufsaxi_w_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int ufsaxi_w_lmtr_en : 1;
    } reg;
} SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ufsaxi_w_lmtr_saturation_START (0)
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ufsaxi_w_lmtr_saturation_END (13)
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ufsaxi_w_lmtr_bandwidth_START (16)
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ufsaxi_w_lmtr_bandwidth_END (28)
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ufsaxi_w_lmtr_en_START (31)
#define SOC_UFS_SYSCTRL_UFSAXI_W_QOS_LMTR_ufsaxi_w_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufsaxi_r_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int ufsaxi_r_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int ufsaxi_r_lmtr_en : 1;
    } reg;
} SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ufsaxi_r_lmtr_saturation_START (0)
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ufsaxi_r_lmtr_saturation_END (13)
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ufsaxi_r_lmtr_bandwidth_START (16)
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ufsaxi_r_lmtr_bandwidth_END (28)
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ufsaxi_r_lmtr_en_START (31)
#define SOC_UFS_SYSCTRL_UFSAXI_R_QOS_LMTR_ufsaxi_r_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_axcache_mask : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_SYSCTRL_UFS_AXI_CTRL_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_AXI_CTRL_sc_axcache_mask_START (0)
#define SOC_UFS_SYSCTRL_UFS_AXI_CTRL_sc_axcache_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_mem_ctrl_tpl : 16;
        unsigned int sc_ufspsw_mem_sdo : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_UFS_SYSCTRL_MEMORY_CTRL_TP_UNION;
#endif
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_TP_ufs_mem_ctrl_tpl_START (0)
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_TP_ufs_mem_ctrl_tpl_END (15)
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_TP_sc_ufspsw_mem_sdo_START (16)
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_TP_sc_ufspsw_mem_sdo_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_ao_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_UFS_SYSCTRL_AO_MEMORY_CTRL_UNION;
#endif
#define SOC_UFS_SYSCTRL_AO_MEMORY_CTRL_ufs_ao_mem_ctrl_START (0)
#define SOC_UFS_SYSCTRL_AO_MEMORY_CTRL_ufs_ao_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_UFS_SYSCTRL_MEMORY_CTRL_UNION;
#endif
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_ufs_mem_ctrl_START (0)
#define SOC_UFS_SYSCTRL_MEMORY_CTRL_ufs_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_axuser_cfg : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_UFS_SYSCTRL_UFS_AXUSER_CFG_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_AXUSER_CFG_ufs_axuser_cfg_START (0)
#define SOC_UFS_SYSCTRL_UFS_AXUSER_CFG_ufs_axuser_cfg_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_axcache_cfg : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_SYSCTRL_UFS_AXCACHE_CFG_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_AXCACHE_CFG_ufs_axcache_cfg_START (0)
#define SOC_UFS_SYSCTRL_UFS_AXCACHE_CFG_ufs_axcache_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_smmu_mem_ctrl_sd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_SYSCTRL_UFS_SMMU_MEM_CTRL_SD_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_SMMU_MEM_CTRL_SD_ufs_smmu_mem_ctrl_sd_START (0)
#define SOC_UFS_SYSCTRL_UFS_SMMU_MEM_CTRL_SD_ufs_smmu_mem_ctrl_sd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_enhanced_op_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_SYSCTRL_UFS_ENHANCE_CTRL_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_ENHANCE_CTRL_sc_enhanced_op_en_START (0)
#define SOC_UFS_SYSCTRL_UFS_ENHANCE_CTRL_sc_enhanced_op_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_ar_mmu_swid : 8;
        unsigned int ufs_ar_mmu_ssid : 6;
        unsigned int reserved_0 : 2;
        unsigned int ufs_ar_mmu_sid : 6;
        unsigned int reserved_1 : 2;
        unsigned int ufs_ar_mmu_ssidv : 1;
        unsigned int ufs_ar_mmu_secsid : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_swid_START (0)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_swid_END (7)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_ssid_START (8)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_ssid_END (13)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_sid_START (16)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_sid_END (21)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_ssidv_START (24)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_ssidv_END (24)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_secsid_START (25)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AR_ID_ufs_ar_mmu_secsid_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_aw_mmu_swid : 8;
        unsigned int ufs_aw_mmu_ssid : 6;
        unsigned int reserved_0 : 2;
        unsigned int ufs_aw_mmu_sid : 6;
        unsigned int reserved_1 : 2;
        unsigned int ufs_aw_mmu_ssidv : 1;
        unsigned int ufs_aw_mmu_secsid : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_UNION;
#endif
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_swid_START (0)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_swid_END (7)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_ssid_START (8)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_ssid_END (13)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_sid_START (16)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_sid_END (21)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_ssidv_START (24)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_ssidv_END (24)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_secsid_START (25)
#define SOC_UFS_SYSCTRL_UFS_SMMU_AW_ID_ufs_aw_mmu_secsid_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_ufs_mmu_id_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_SYSCTRL_SC_UFS_MMU_ID_SEL_UNION;
#endif
#define SOC_UFS_SYSCTRL_SC_UFS_MMU_ID_SEL_sc_ufs_mmu_id_sel_START (0)
#define SOC_UFS_SYSCTRL_SC_UFS_MMU_ID_SEL_sc_ufs_mmu_id_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_ufs_ar_mmu_swid : 8;
        unsigned int sec_ufs_ar_mmu_ssid : 6;
        unsigned int reserved_0 : 2;
        unsigned int sec_ufs_ar_mmu_sid : 6;
        unsigned int reserved_1 : 2;
        unsigned int sec_ufs_ar_mmu_ssidv : 1;
        unsigned int sec_ufs_ar_mmu_secsid : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_UNION;
#endif
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_swid_START (0)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_swid_END (7)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_ssid_START (8)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_ssid_END (13)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_sid_START (16)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_sid_END (21)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_ssidv_START (24)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_ssidv_END (24)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_secsid_START (25)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AR_ID_sec_ufs_ar_mmu_secsid_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_ufs_aw_mmu_swid : 8;
        unsigned int sec_ufs_aw_mmu_ssid : 6;
        unsigned int reserved_0 : 2;
        unsigned int sec_ufs_aw_mmu_sid : 6;
        unsigned int reserved_1 : 2;
        unsigned int sec_ufs_aw_mmu_ssidv : 1;
        unsigned int sec_ufs_aw_mmu_secsid : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_UNION;
#endif
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_swid_START (0)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_swid_END (7)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_ssid_START (8)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_ssid_END (13)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_sid_START (16)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_sid_END (21)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_ssidv_START (24)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_ssidv_END (24)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_secsid_START (25)
#define SOC_UFS_SYSCTRL_SEC_UFS_SMMU_AW_ID_sec_ufs_aw_mmu_secsid_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_tcu_trace_axi_mux_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_SYSCTRL_SC_TCU_TRACE_AXI_MUX_SEL_UNION;
#endif
#define SOC_UFS_SYSCTRL_SC_TCU_TRACE_AXI_MUX_SEL_sc_tcu_trace_axi_mux_sel_START (0)
#define SOC_UFS_SYSCTRL_SC_TCU_TRACE_AXI_MUX_SEL_sc_tcu_trace_axi_mux_sel_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
