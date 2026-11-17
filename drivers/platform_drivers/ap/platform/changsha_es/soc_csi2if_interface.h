#ifndef __SOC_CSI2IF_INTERFACE_H__
#define __SOC_CSI2IF_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CSI2IF_VERSION_ADDR(base) ((base) + (0x0UL))
#define SOC_CSI2IF_N_LANES_ADDR(base) ((base) + (0x4UL))
#define SOC_CSI2IF_CSI2_RESETN_ADDR(base) ((base) + (0x8UL))
#define SOC_CSI2IF_INT_ST_MAIN_ADDR(base) ((base) + (0xCUL))
#define SOC_CSI2IF_CSI_CFG_ADDR(base) ((base) + (0x10UL))
#define SOC_CSI2IF_PHY_SHUTDOWNZ_ADDR(base) ((base) + (0x14UL))
#define SOC_CSI2IF_PHY_RSTZ_ADDR(base) ((base) + (0x18UL))
#define SOC_CSI2IF_PHY_RX_ADDR(base) ((base) + (0x1CUL))
#define SOC_CSI2IF_PHY_STOPSTATE_ADDR(base) ((base) + (0x20UL))
#define SOC_CSI2IF_PHY_TEST_CTRL0_ADDR(base) ((base) + (0x24UL))
#define SOC_CSI2IF_PHY_TEST_CTRL1_ADDR(base) ((base) + (0x28UL))
#define SOC_CSI2IF_PHY_CAL_ADDR(base) ((base) + (0x2CUL))
#define SOC_CSI2IF_SCRAMBLING_ADDR(base) ((base) + (0x30UL))
#define SOC_CSI2IF_SCRAMBLING_SEED1_ADDR(base) ((base) + (0x34UL))
#define SOC_CSI2IF_SCRAMBLING_SEED2_ADDR(base) ((base) + (0x38UL))
#define SOC_CSI2IF_SCRAMBLING_SEED3_ADDR(base) ((base) + (0x3CUL))
#define SOC_CSI2IF_SCRAMBLING_SEED4_ADDR(base) ((base) + (0x40UL))
#define SOC_CSI2IF_SKEW_FIFO_CFG_ADDR(base) ((base) + (0x44UL))
#define SOC_CSI2IF_VCX_OVERRIDE_ADDR(base) ((base) + (0x48UL))
#define SOC_CSI2IF_PHY_DEBUG_OUT_ADDR(base) ((base) + (0x4CUL))
#define SOC_CSI2IF_DBG_TOTAL_FRAME_NUM_ADDR(base) ((base) + (0x50UL))
#define SOC_CSI2IF_DBG_TOTAL_PACKAGE_NUM_ADDR(base) ((base) + (0x54UL))
#define SOC_CSI2IF_INT_ST_PHY_FATAL_ADDR(base) ((base) + (0x58UL))
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_ADDR(base) ((base) + (0x5CUL))
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_ADDR(base) ((base) + (0x60UL))
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_ADDR(base) ((base) + (0x64UL))
#define SOC_CSI2IF_FRAME_FATAL_TYPE_ADDR(base) ((base) + (0x68UL))
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_ADDR(base) ((base) + (0x6CUL))
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_ADDR(base) ((base) + (0x70UL))
#define SOC_CSI2IF_INT_ST_PHY_ADDR(base) ((base) + (0x74UL))
#define SOC_CSI2IF_INT_MSK_PHY_ADDR(base) ((base) + (0x78UL))
#define SOC_CSI2IF_INT_FORCE_PHY_ADDR(base) ((base) + (0x7CUL))
#define SOC_CSI2IF_INT_SKEW_FIFO_ADDR(base) ((base) + (0x80UL))
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_ADDR(base) ((base) + (0x84UL))
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_ADDR(base) ((base) + (0x88UL))
#define SOC_CSI2IF_INT_ST_PKT_ADDR(base) ((base) + (0x8CUL))
#define SOC_CSI2IF_INT_ST_PKT_DT_ADDR(base) ((base) + (0x90UL))
#define SOC_CSI2IF_INT_ST_PKT_MASK_ADDR(base) ((base) + (0x94UL))
#define SOC_CSI2IF_INT_ST_PKT_FORCE_ADDR(base) ((base) + (0x98UL))
#define SOC_CSI2IF_ALP_ADDR(base) ((base) + (0x9CUL))
#define SOC_CSI2IF_PPI_MONITOR_CTRL_ADDR(base) ((base) + (0xA0UL))
#define SOC_CSI2IF_PPI_MONITOR_GRP_0_ADDR(base) ((base) + (0xA4UL))
#define SOC_CSI2IF_PPI_MONITOR_GRP_1_ADDR(base) ((base) + (0xA8UL))
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_ADDR(base) ((base) + (0xACUL))
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_ADDR(base) ((base) + (0xB0UL))
#define SOC_CSI2IF_VC0_MONITOR_INFO_ADDR(base) ((base) + (0xB4UL))
#define SOC_CSI2IF_VC1_MONITOR_INFO_ADDR(base) ((base) + (0xB8UL))
#define SOC_CSI2IF_VC2_MONITOR_INFO_ADDR(base) ((base) + (0xBCUL))
#define SOC_CSI2IF_VC3_MONITOR_INFO_ADDR(base) ((base) + (0xC0UL))
#define SOC_CSI2IF_VC4_MONITOR_INFO_ADDR(base) ((base) + (0xC4UL))
#define SOC_CSI2IF_VC5_MONITOR_INFO_ADDR(base) ((base) + (0xC8UL))
#define SOC_CSI2IF_VC6_MONITOR_INFO_ADDR(base) ((base) + (0xCCUL))
#define SOC_CSI2IF_VC7_MONITOR_INFO_ADDR(base) ((base) + (0xD0UL))
#define SOC_CSI2IF_VC8_MONITOR_INFO_ADDR(base) ((base) + (0xD4UL))
#define SOC_CSI2IF_VC9_MONITOR_INFO_ADDR(base) ((base) + (0xD8UL))
#define SOC_CSI2IF_VC10_MONITOR_INFO_ADDR(base) ((base) + (0xDCUL))
#define SOC_CSI2IF_VC11_MONITOR_INFO_ADDR(base) ((base) + (0xE0UL))
#define SOC_CSI2IF_VC12_MONITOR_INFO_ADDR(base) ((base) + (0xE4UL))
#define SOC_CSI2IF_VC13_MONITOR_INFO_ADDR(base) ((base) + (0xE8UL))
#define SOC_CSI2IF_VC14_MONITOR_INFO_ADDR(base) ((base) + (0xECUL))
#define SOC_CSI2IF_VC15_MONITOR_INFO_ADDR(base) ((base) + (0xF0UL))
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_ADDR(base) ((base) + (0x100UL))
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_ADDR(base) ((base) + (0x104UL))
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_ADDR(base) ((base) + (0x108UL))
#define SOC_CSI2IF_INT_LANE_SKEW_ERROR_ADDR(base) ((base) + (0x10CUL))
#define SOC_CSI2IF_INT_MSK_LANE_SKEW_ERROR_ADDR(base) ((base) + (0x110UL))
#define SOC_CSI2IF_INT_FORCE_LANE_SKEW_ERROR_ADDR(base) ((base) + (0x114UL))
#else
#define SOC_CSI2IF_VERSION_ADDR(base) ((base) + (0x0))
#define SOC_CSI2IF_N_LANES_ADDR(base) ((base) + (0x4))
#define SOC_CSI2IF_CSI2_RESETN_ADDR(base) ((base) + (0x8))
#define SOC_CSI2IF_INT_ST_MAIN_ADDR(base) ((base) + (0xC))
#define SOC_CSI2IF_CSI_CFG_ADDR(base) ((base) + (0x10))
#define SOC_CSI2IF_PHY_SHUTDOWNZ_ADDR(base) ((base) + (0x14))
#define SOC_CSI2IF_PHY_RSTZ_ADDR(base) ((base) + (0x18))
#define SOC_CSI2IF_PHY_RX_ADDR(base) ((base) + (0x1C))
#define SOC_CSI2IF_PHY_STOPSTATE_ADDR(base) ((base) + (0x20))
#define SOC_CSI2IF_PHY_TEST_CTRL0_ADDR(base) ((base) + (0x24))
#define SOC_CSI2IF_PHY_TEST_CTRL1_ADDR(base) ((base) + (0x28))
#define SOC_CSI2IF_PHY_CAL_ADDR(base) ((base) + (0x2C))
#define SOC_CSI2IF_SCRAMBLING_ADDR(base) ((base) + (0x30))
#define SOC_CSI2IF_SCRAMBLING_SEED1_ADDR(base) ((base) + (0x34))
#define SOC_CSI2IF_SCRAMBLING_SEED2_ADDR(base) ((base) + (0x38))
#define SOC_CSI2IF_SCRAMBLING_SEED3_ADDR(base) ((base) + (0x3C))
#define SOC_CSI2IF_SCRAMBLING_SEED4_ADDR(base) ((base) + (0x40))
#define SOC_CSI2IF_SKEW_FIFO_CFG_ADDR(base) ((base) + (0x44))
#define SOC_CSI2IF_VCX_OVERRIDE_ADDR(base) ((base) + (0x48))
#define SOC_CSI2IF_PHY_DEBUG_OUT_ADDR(base) ((base) + (0x4C))
#define SOC_CSI2IF_DBG_TOTAL_FRAME_NUM_ADDR(base) ((base) + (0x50))
#define SOC_CSI2IF_DBG_TOTAL_PACKAGE_NUM_ADDR(base) ((base) + (0x54))
#define SOC_CSI2IF_INT_ST_PHY_FATAL_ADDR(base) ((base) + (0x58))
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_ADDR(base) ((base) + (0x5C))
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_ADDR(base) ((base) + (0x60))
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_ADDR(base) ((base) + (0x64))
#define SOC_CSI2IF_FRAME_FATAL_TYPE_ADDR(base) ((base) + (0x68))
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_ADDR(base) ((base) + (0x6C))
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_ADDR(base) ((base) + (0x70))
#define SOC_CSI2IF_INT_ST_PHY_ADDR(base) ((base) + (0x74))
#define SOC_CSI2IF_INT_MSK_PHY_ADDR(base) ((base) + (0x78))
#define SOC_CSI2IF_INT_FORCE_PHY_ADDR(base) ((base) + (0x7C))
#define SOC_CSI2IF_INT_SKEW_FIFO_ADDR(base) ((base) + (0x80))
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_ADDR(base) ((base) + (0x84))
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_ADDR(base) ((base) + (0x88))
#define SOC_CSI2IF_INT_ST_PKT_ADDR(base) ((base) + (0x8C))
#define SOC_CSI2IF_INT_ST_PKT_DT_ADDR(base) ((base) + (0x90))
#define SOC_CSI2IF_INT_ST_PKT_MASK_ADDR(base) ((base) + (0x94))
#define SOC_CSI2IF_INT_ST_PKT_FORCE_ADDR(base) ((base) + (0x98))
#define SOC_CSI2IF_ALP_ADDR(base) ((base) + (0x9C))
#define SOC_CSI2IF_PPI_MONITOR_CTRL_ADDR(base) ((base) + (0xA0))
#define SOC_CSI2IF_PPI_MONITOR_GRP_0_ADDR(base) ((base) + (0xA4))
#define SOC_CSI2IF_PPI_MONITOR_GRP_1_ADDR(base) ((base) + (0xA8))
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_ADDR(base) ((base) + (0xAC))
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_ADDR(base) ((base) + (0xB0))
#define SOC_CSI2IF_VC0_MONITOR_INFO_ADDR(base) ((base) + (0xB4))
#define SOC_CSI2IF_VC1_MONITOR_INFO_ADDR(base) ((base) + (0xB8))
#define SOC_CSI2IF_VC2_MONITOR_INFO_ADDR(base) ((base) + (0xBC))
#define SOC_CSI2IF_VC3_MONITOR_INFO_ADDR(base) ((base) + (0xC0))
#define SOC_CSI2IF_VC4_MONITOR_INFO_ADDR(base) ((base) + (0xC4))
#define SOC_CSI2IF_VC5_MONITOR_INFO_ADDR(base) ((base) + (0xC8))
#define SOC_CSI2IF_VC6_MONITOR_INFO_ADDR(base) ((base) + (0xCC))
#define SOC_CSI2IF_VC7_MONITOR_INFO_ADDR(base) ((base) + (0xD0))
#define SOC_CSI2IF_VC8_MONITOR_INFO_ADDR(base) ((base) + (0xD4))
#define SOC_CSI2IF_VC9_MONITOR_INFO_ADDR(base) ((base) + (0xD8))
#define SOC_CSI2IF_VC10_MONITOR_INFO_ADDR(base) ((base) + (0xDC))
#define SOC_CSI2IF_VC11_MONITOR_INFO_ADDR(base) ((base) + (0xE0))
#define SOC_CSI2IF_VC12_MONITOR_INFO_ADDR(base) ((base) + (0xE4))
#define SOC_CSI2IF_VC13_MONITOR_INFO_ADDR(base) ((base) + (0xE8))
#define SOC_CSI2IF_VC14_MONITOR_INFO_ADDR(base) ((base) + (0xEC))
#define SOC_CSI2IF_VC15_MONITOR_INFO_ADDR(base) ((base) + (0xF0))
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_ADDR(base) ((base) + (0x100))
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_ADDR(base) ((base) + (0x104))
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_ADDR(base) ((base) + (0x108))
#define SOC_CSI2IF_INT_LANE_SKEW_ERROR_ADDR(base) ((base) + (0x10C))
#define SOC_CSI2IF_INT_MSK_LANE_SKEW_ERROR_ADDR(base) ((base) + (0x110))
#define SOC_CSI2IF_INT_FORCE_LANE_SKEW_ERROR_ADDR(base) ((base) + (0x114))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int version : 32;
    } reg;
} SOC_CSI2IF_VERSION_UNION;
#endif
#define SOC_CSI2IF_VERSION_version_START (0)
#define SOC_CSI2IF_VERSION_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int n_lanes : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI2IF_N_LANES_UNION;
#endif
#define SOC_CSI2IF_N_LANES_n_lanes_START (0)
#define SOC_CSI2IF_N_LANES_n_lanes_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csi2_resetn : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI2IF_CSI2_RESETN_UNION;
#endif
#define SOC_CSI2IF_CSI2_RESETN_csi2_resetn_START (0)
#define SOC_CSI2IF_CSI2_RESETN_csi2_resetn_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int status_int_phy_fatal : 1;
        unsigned int status_int_frame_fatal : 1;
        unsigned int reserved_0 : 14;
        unsigned int status_int_phy : 1;
        unsigned int status_int_pkt : 1;
        unsigned int status_int_skew_fifo : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_CSI2IF_INT_ST_MAIN_UNION;
#endif
#define SOC_CSI2IF_INT_ST_MAIN_status_int_phy_fatal_START (0)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_phy_fatal_END (0)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_frame_fatal_START (1)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_frame_fatal_END (1)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_phy_START (16)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_phy_END (16)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_pkt_START (17)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_pkt_END (17)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_skew_fifo_START (18)
#define SOC_CSI2IF_INT_ST_MAIN_status_int_skew_fifo_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_mode : 1;
        unsigned int cphy_data_width : 1;
        unsigned int debug_cnt_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int auto_gt_idi_clk : 1;
        unsigned int legacy_yuv_8b_swap_disable : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_CSI2IF_CSI_CFG_UNION;
#endif
#define SOC_CSI2IF_CSI_CFG_phy_mode_START (0)
#define SOC_CSI2IF_CSI_CFG_phy_mode_END (0)
#define SOC_CSI2IF_CSI_CFG_cphy_data_width_START (1)
#define SOC_CSI2IF_CSI_CFG_cphy_data_width_END (1)
#define SOC_CSI2IF_CSI_CFG_debug_cnt_en_START (2)
#define SOC_CSI2IF_CSI_CFG_debug_cnt_en_END (2)
#define SOC_CSI2IF_CSI_CFG_auto_gt_idi_clk_START (4)
#define SOC_CSI2IF_CSI_CFG_auto_gt_idi_clk_END (4)
#define SOC_CSI2IF_CSI_CFG_legacy_yuv_8b_swap_disable_START (5)
#define SOC_CSI2IF_CSI_CFG_legacy_yuv_8b_swap_disable_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_shutdownz : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI2IF_PHY_SHUTDOWNZ_UNION;
#endif
#define SOC_CSI2IF_PHY_SHUTDOWNZ_phy_shutdownz_START (0)
#define SOC_CSI2IF_PHY_SHUTDOWNZ_phy_shutdownz_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_rstz : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI2IF_PHY_RSTZ_UNION;
#endif
#define SOC_CSI2IF_PHY_RSTZ_phy_rstz_START (0)
#define SOC_CSI2IF_PHY_RSTZ_phy_rstz_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 16;
        unsigned int phy_rxulpsclknot : 1;
        unsigned int phy_rxclkactivehs : 1;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_CSI2IF_PHY_RX_UNION;
#endif
#define SOC_CSI2IF_PHY_RX_phy_rxulpsclknot_START (16)
#define SOC_CSI2IF_PHY_RX_phy_rxulpsclknot_END (16)
#define SOC_CSI2IF_PHY_RX_phy_rxclkactivehs_START (17)
#define SOC_CSI2IF_PHY_RX_phy_rxclkactivehs_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_stopstatedata_0 : 1;
        unsigned int phy_stopstatedata_1 : 1;
        unsigned int phy_stopstatedata_2 : 1;
        unsigned int phy_stopstatedata_3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 8;
        unsigned int phy_stopstateclk : 1;
        unsigned int reserved_5 : 15;
    } reg;
} SOC_CSI2IF_PHY_STOPSTATE_UNION;
#endif
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_0_START (0)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_0_END (0)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_1_START (1)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_1_END (1)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_2_START (2)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_2_END (2)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_3_START (3)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstatedata_3_END (3)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstateclk_START (16)
#define SOC_CSI2IF_PHY_STOPSTATE_phy_stopstateclk_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_testclr : 1;
        unsigned int phy_testclk : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI2IF_PHY_TEST_CTRL0_UNION;
#endif
#define SOC_CSI2IF_PHY_TEST_CTRL0_phy_testclr_START (0)
#define SOC_CSI2IF_PHY_TEST_CTRL0_phy_testclr_END (0)
#define SOC_CSI2IF_PHY_TEST_CTRL0_phy_testclk_START (1)
#define SOC_CSI2IF_PHY_TEST_CTRL0_phy_testclk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_testdin : 8;
        unsigned int phy_testdout : 8;
        unsigned int phy_testen : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_CSI2IF_PHY_TEST_CTRL1_UNION;
#endif
#define SOC_CSI2IF_PHY_TEST_CTRL1_phy_testdin_START (0)
#define SOC_CSI2IF_PHY_TEST_CTRL1_phy_testdin_END (7)
#define SOC_CSI2IF_PHY_TEST_CTRL1_phy_testdout_START (8)
#define SOC_CSI2IF_PHY_TEST_CTRL1_phy_testdout_END (15)
#define SOC_CSI2IF_PHY_TEST_CTRL1_phy_testen_START (16)
#define SOC_CSI2IF_PHY_TEST_CTRL1_phy_testen_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxskewcalhs_0 : 1;
        unsigned int rxskewcalhs_1 : 1;
        unsigned int rxskewcalhs_2 : 1;
        unsigned int rxskewcalhs_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI2IF_PHY_CAL_UNION;
#endif
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_0_START (0)
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_0_END (0)
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_1_START (1)
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_1_END (1)
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_2_START (2)
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_2_END (2)
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_3_START (3)
#define SOC_CSI2IF_PHY_CAL_rxskewcalhs_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scramble_enable : 1;
        unsigned int syntype_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI2IF_SCRAMBLING_UNION;
#endif
#define SOC_CSI2IF_SCRAMBLING_scramble_enable_START (0)
#define SOC_CSI2IF_SCRAMBLING_scramble_enable_END (0)
#define SOC_CSI2IF_SCRAMBLING_syntype_en_START (1)
#define SOC_CSI2IF_SCRAMBLING_syntype_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scrambling_seed1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CSI2IF_SCRAMBLING_SEED1_UNION;
#endif
#define SOC_CSI2IF_SCRAMBLING_SEED1_scrambling_seed1_START (0)
#define SOC_CSI2IF_SCRAMBLING_SEED1_scrambling_seed1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scrambling_seed2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CSI2IF_SCRAMBLING_SEED2_UNION;
#endif
#define SOC_CSI2IF_SCRAMBLING_SEED2_scrambling_seed2_START (0)
#define SOC_CSI2IF_SCRAMBLING_SEED2_scrambling_seed2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scrambling_seed3 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CSI2IF_SCRAMBLING_SEED3_UNION;
#endif
#define SOC_CSI2IF_SCRAMBLING_SEED3_scrambling_seed3_START (0)
#define SOC_CSI2IF_SCRAMBLING_SEED3_scrambling_seed3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scrambling_seed4 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CSI2IF_SCRAMBLING_SEED4_UNION;
#endif
#define SOC_CSI2IF_SCRAMBLING_SEED4_scrambling_seed4_START (0)
#define SOC_CSI2IF_SCRAMBLING_SEED4_scrambling_seed4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int skew_threshold : 8;
        unsigned int skew_wait_cycles : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_CSI2IF_SKEW_FIFO_CFG_UNION;
#endif
#define SOC_CSI2IF_SKEW_FIFO_CFG_skew_threshold_START (0)
#define SOC_CSI2IF_SKEW_FIFO_CFG_skew_threshold_END (7)
#define SOC_CSI2IF_SKEW_FIFO_CFG_skew_wait_cycles_START (8)
#define SOC_CSI2IF_SKEW_FIFO_CFG_skew_wait_cycles_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vcx_override : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI2IF_VCX_OVERRIDE_UNION;
#endif
#define SOC_CSI2IF_VCX_OVERRIDE_vcx_override_START (0)
#define SOC_CSI2IF_VCX_OVERRIDE_vcx_override_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_debug_out : 32;
    } reg;
} SOC_CSI2IF_PHY_DEBUG_OUT_UNION;
#endif
#define SOC_CSI2IF_PHY_DEBUG_OUT_phy_debug_out_START (0)
#define SOC_CSI2IF_PHY_DEBUG_OUT_phy_debug_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_total_frame_number : 32;
    } reg;
} SOC_CSI2IF_DBG_TOTAL_FRAME_NUM_UNION;
#endif
#define SOC_CSI2IF_DBG_TOTAL_FRAME_NUM_debug_total_frame_number_START (0)
#define SOC_CSI2IF_DBG_TOTAL_FRAME_NUM_debug_total_frame_number_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_total_package_number : 32;
    } reg;
} SOC_CSI2IF_DBG_TOTAL_PACKAGE_NUM_UNION;
#endif
#define SOC_CSI2IF_DBG_TOTAL_PACKAGE_NUM_debug_total_package_number_START (0)
#define SOC_CSI2IF_DBG_TOTAL_PACKAGE_NUM_debug_total_package_number_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_errsotsynchs_0 : 1;
        unsigned int phy_errsotsynchs_1 : 1;
        unsigned int phy_errsotsynchs_2 : 1;
        unsigned int phy_errsotsynchs_3 : 1;
        unsigned int reserved_0 : 4;
        unsigned int phy_rxinvalidcodehs_0 : 2;
        unsigned int phy_rxinvalidcodehs_1 : 2;
        unsigned int phy_rxinvalidcodehs_2 : 2;
        unsigned int phy_rxinvalidcodehs_3 : 2;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CSI2IF_INT_ST_PHY_FATAL_UNION;
#endif
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_0_START (0)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_0_END (0)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_1_START (1)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_1_END (1)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_2_START (2)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_2_END (2)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_3_START (3)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_errsotsynchs_3_END (3)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_0_START (8)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_0_END (9)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_1_START (10)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_1_END (11)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_2_START (12)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_2_END (13)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_3_START (14)
#define SOC_CSI2IF_INT_ST_PHY_FATAL_phy_rxinvalidcodehs_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_phy_errsotsynchs_0 : 1;
        unsigned int mask_phy_errsotsynchs_1 : 1;
        unsigned int mask_phy_errsotsynchs_2 : 1;
        unsigned int mask_phy_errsotsynchs_3 : 1;
        unsigned int reserved_0 : 12;
        unsigned int mask_phy_rxinvalidcodehs_0 : 2;
        unsigned int mask_phy_rxinvalidcodehs_1 : 2;
        unsigned int mask_phy_rxinvalidcodehs_2 : 2;
        unsigned int mask_phy_rxinvalidcodehs_3 : 2;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CSI2IF_INT_MSK_PHY_FATAL_UNION;
#endif
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_START (0)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_END (0)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_START (1)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_END (1)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_2_START (2)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_2_END (2)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_3_START (3)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_3_END (3)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_0_START (16)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_0_END (17)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_1_START (18)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_1_END (19)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_2_START (20)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_2_END (21)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_3_START (22)
#define SOC_CSI2IF_INT_MSK_PHY_FATAL_mask_phy_rxinvalidcodehs_3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_phy_errsotsynchs_0 : 1;
        unsigned int force_phy_errsotsynchs_1 : 1;
        unsigned int force_phy_errsotsynchs_2 : 1;
        unsigned int force_phy_errsotsynchs_3 : 1;
        unsigned int reserved_0 : 12;
        unsigned int force_phy_rxinvalidcodehs_0 : 2;
        unsigned int force_phy_rxinvalidcodehs_1 : 2;
        unsigned int force_phy_rxinvalidcodehs_2 : 2;
        unsigned int force_phy_rxinvalidcodehs_3 : 2;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CSI2IF_INT_FORCE_PHY_FATAL_UNION;
#endif
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_START (0)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_END (0)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_START (1)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_END (1)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_2_START (2)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_2_END (2)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_3_START (3)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_3_END (3)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_0_START (16)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_0_END (17)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_1_START (18)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_1_END (19)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_2_START (20)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_2_END (21)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_3_START (22)
#define SOC_CSI2IF_INT_FORCE_PHY_FATAL_force_phy_rxinvalidcodehs_3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int err_frame_number_nomatch : 1;
        unsigned int err_two_continuous_fend : 1;
        unsigned int err_two_continuous_fstart : 1;
        unsigned int err_f_seq : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI2IF_INT_ST_FRAME_FATAL_UNION;
#endif
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_frame_number_nomatch_START (0)
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_frame_number_nomatch_END (0)
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_two_continuous_fend_START (1)
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_two_continuous_fend_END (1)
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_two_continuous_fstart_START (2)
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_two_continuous_fstart_END (2)
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_f_seq_START (3)
#define SOC_CSI2IF_INT_ST_FRAME_FATAL_err_f_seq_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int frame_fatal_sequence_id : 16;
        unsigned int frame_fatal_channel_id : 5;
        unsigned int reserved_0 : 3;
        unsigned int frame_fatal_debug_en : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_CSI2IF_FRAME_FATAL_TYPE_UNION;
#endif
#define SOC_CSI2IF_FRAME_FATAL_TYPE_frame_fatal_sequence_id_START (0)
#define SOC_CSI2IF_FRAME_FATAL_TYPE_frame_fatal_sequence_id_END (15)
#define SOC_CSI2IF_FRAME_FATAL_TYPE_frame_fatal_channel_id_START (16)
#define SOC_CSI2IF_FRAME_FATAL_TYPE_frame_fatal_channel_id_END (20)
#define SOC_CSI2IF_FRAME_FATAL_TYPE_frame_fatal_debug_en_START (24)
#define SOC_CSI2IF_FRAME_FATAL_TYPE_frame_fatal_debug_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_err_frame_number_nomatch : 1;
        unsigned int mask_err_two_con_fend : 1;
        unsigned int mask_err_two_con_fstart : 1;
        unsigned int mask_err_f_seq : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI2IF_INT_MSK_FRAME_FATAL_UNION;
#endif
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_frame_number_nomatch_START (0)
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_frame_number_nomatch_END (0)
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_two_con_fend_START (1)
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_two_con_fend_END (1)
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_two_con_fstart_START (2)
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_two_con_fstart_END (2)
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_f_seq_START (3)
#define SOC_CSI2IF_INT_MSK_FRAME_FATAL_mask_err_f_seq_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_err_frame_number_nomatch : 1;
        unsigned int force_err_two_con_fend : 1;
        unsigned int force_err_two_con_fstart : 1;
        unsigned int force_err_f_seq : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI2IF_INT_FORCE_FRAME_FATAL_UNION;
#endif
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_frame_number_nomatch_START (0)
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_frame_number_nomatch_END (0)
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_two_con_fend_START (1)
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_two_con_fend_END (1)
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_two_con_fstart_START (2)
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_two_con_fstart_END (2)
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_f_seq_START (3)
#define SOC_CSI2IF_INT_FORCE_FRAME_FATAL_force_err_f_seq_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_errsoths_0 : 1;
        unsigned int phy_errsoths_1 : 1;
        unsigned int phy_errsoths_2 : 1;
        unsigned int phy_errsoths_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI2IF_INT_ST_PHY_UNION;
#endif
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_0_START (0)
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_0_END (0)
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_1_START (1)
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_1_END (1)
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_2_START (2)
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_2_END (2)
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_3_START (3)
#define SOC_CSI2IF_INT_ST_PHY_phy_errsoths_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_phy_errsoths_0 : 1;
        unsigned int mask_phy_errsoths_1 : 1;
        unsigned int mask_phy_errsoths_2 : 1;
        unsigned int mask_phy_errsoths_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI2IF_INT_MSK_PHY_UNION;
#endif
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_0_START (0)
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_0_END (0)
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_1_START (1)
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_1_END (1)
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_2_START (2)
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_2_END (2)
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_3_START (3)
#define SOC_CSI2IF_INT_MSK_PHY_mask_phy_errsoths_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_phy_errsoths_0 : 1;
        unsigned int force_phy_errsoths_1 : 1;
        unsigned int force_phy_errsoths_2 : 1;
        unsigned int force_phy_errsoths_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI2IF_INT_FORCE_PHY_UNION;
#endif
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_0_START (0)
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_0_END (0)
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_1_START (1)
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_1_END (1)
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_2_START (2)
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_2_END (2)
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_3_START (3)
#define SOC_CSI2IF_INT_FORCE_PHY_force_phy_errsoths_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_full_push : 4;
        unsigned int fifo_empty_pop : 4;
        unsigned int skew_err : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CSI2IF_INT_SKEW_FIFO_UNION;
#endif
#define SOC_CSI2IF_INT_SKEW_FIFO_fifo_full_push_START (0)
#define SOC_CSI2IF_INT_SKEW_FIFO_fifo_full_push_END (3)
#define SOC_CSI2IF_INT_SKEW_FIFO_fifo_empty_pop_START (4)
#define SOC_CSI2IF_INT_SKEW_FIFO_fifo_empty_pop_END (7)
#define SOC_CSI2IF_INT_SKEW_FIFO_skew_err_START (8)
#define SOC_CSI2IF_INT_SKEW_FIFO_skew_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_fifo_full_push : 4;
        unsigned int mask_fifo_empty_pop : 4;
        unsigned int mask_skew_err : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CSI2IF_INT_SKEW_FIFO_MASK_UNION;
#endif
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_mask_fifo_full_push_START (0)
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_mask_fifo_full_push_END (3)
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_mask_fifo_empty_pop_START (4)
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_mask_fifo_empty_pop_END (7)
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_mask_skew_err_START (8)
#define SOC_CSI2IF_INT_SKEW_FIFO_MASK_mask_skew_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_fifo_full_push : 4;
        unsigned int force_fifo_empty_pop : 4;
        unsigned int force_skew_err : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CSI2IF_INT_SKEW_FIFO_FORCE_UNION;
#endif
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_force_fifo_full_push_START (0)
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_force_fifo_full_push_END (3)
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_force_fifo_empty_pop_START (4)
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_force_fifo_empty_pop_END (7)
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_force_skew_err_START (8)
#define SOC_CSI2IF_INT_SKEW_FIFO_FORCE_force_skew_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int err_ecc_double : 1;
        unsigned int err_cphy_header_crc : 1;
        unsigned int err_payload_crc_err : 1;
        unsigned int err_data_type : 1;
        unsigned int err_ecc_corrected : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CSI2IF_INT_ST_PKT_UNION;
#endif
#define SOC_CSI2IF_INT_ST_PKT_err_ecc_double_START (0)
#define SOC_CSI2IF_INT_ST_PKT_err_ecc_double_END (0)
#define SOC_CSI2IF_INT_ST_PKT_err_cphy_header_crc_START (1)
#define SOC_CSI2IF_INT_ST_PKT_err_cphy_header_crc_END (1)
#define SOC_CSI2IF_INT_ST_PKT_err_payload_crc_err_START (2)
#define SOC_CSI2IF_INT_ST_PKT_err_payload_crc_err_END (2)
#define SOC_CSI2IF_INT_ST_PKT_err_data_type_START (3)
#define SOC_CSI2IF_INT_ST_PKT_err_data_type_END (3)
#define SOC_CSI2IF_INT_ST_PKT_err_ecc_corrected_START (4)
#define SOC_CSI2IF_INT_ST_PKT_err_ecc_corrected_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int err_pkt_channel_id : 5;
        unsigned int reserved_0 : 3;
        unsigned int err_pkt_data_type : 6;
        unsigned int reserved_1 : 2;
        unsigned int err_pkt_f_seq_numb : 16;
    } reg;
} SOC_CSI2IF_INT_ST_PKT_DT_UNION;
#endif
#define SOC_CSI2IF_INT_ST_PKT_DT_err_pkt_channel_id_START (0)
#define SOC_CSI2IF_INT_ST_PKT_DT_err_pkt_channel_id_END (4)
#define SOC_CSI2IF_INT_ST_PKT_DT_err_pkt_data_type_START (8)
#define SOC_CSI2IF_INT_ST_PKT_DT_err_pkt_data_type_END (13)
#define SOC_CSI2IF_INT_ST_PKT_DT_err_pkt_f_seq_numb_START (16)
#define SOC_CSI2IF_INT_ST_PKT_DT_err_pkt_f_seq_numb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_ecc_double : 1;
        unsigned int mask_cphy_header_crc : 1;
        unsigned int mask_payload_crc_err : 1;
        unsigned int mask_data_type : 1;
        unsigned int mask_ecc_corrected : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CSI2IF_INT_ST_PKT_MASK_UNION;
#endif
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_ecc_double_START (0)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_ecc_double_END (0)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_cphy_header_crc_START (1)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_cphy_header_crc_END (1)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_payload_crc_err_START (2)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_payload_crc_err_END (2)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_data_type_START (3)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_data_type_END (3)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_ecc_corrected_START (4)
#define SOC_CSI2IF_INT_ST_PKT_MASK_mask_ecc_corrected_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_ecc_double : 1;
        unsigned int force_cphy_header_crc : 1;
        unsigned int force_payload_crc_err : 1;
        unsigned int force_data_type : 1;
        unsigned int force_ecc_corrected : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CSI2IF_INT_ST_PKT_FORCE_UNION;
#endif
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_ecc_double_START (0)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_ecc_double_END (0)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_cphy_header_crc_START (1)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_cphy_header_crc_END (1)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_payload_crc_err_START (2)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_payload_crc_err_END (2)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_data_type_START (3)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_data_type_END (3)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_ecc_corrected_START (4)
#define SOC_CSI2IF_INT_ST_PKT_FORCE_force_ecc_corrected_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxalpnibble0_0 : 4;
        unsigned int rxalpnibble1_0 : 4;
        unsigned int rxalpcode0_0 : 4;
        unsigned int rxalpcode1_0 : 4;
        unsigned int rxalpvalidhs_0 : 2;
        unsigned int reserved_0 : 2;
        unsigned int rxsynctypehs0_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int rxsynctypehs1_0 : 3;
        unsigned int reserved_2 : 1;
        unsigned int alp_mode_en : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_CSI2IF_ALP_UNION;
#endif
#define SOC_CSI2IF_ALP_rxalpnibble0_0_START (0)
#define SOC_CSI2IF_ALP_rxalpnibble0_0_END (3)
#define SOC_CSI2IF_ALP_rxalpnibble1_0_START (4)
#define SOC_CSI2IF_ALP_rxalpnibble1_0_END (7)
#define SOC_CSI2IF_ALP_rxalpcode0_0_START (8)
#define SOC_CSI2IF_ALP_rxalpcode0_0_END (11)
#define SOC_CSI2IF_ALP_rxalpcode1_0_START (12)
#define SOC_CSI2IF_ALP_rxalpcode1_0_END (15)
#define SOC_CSI2IF_ALP_rxalpvalidhs_0_START (16)
#define SOC_CSI2IF_ALP_rxalpvalidhs_0_END (17)
#define SOC_CSI2IF_ALP_rxsynctypehs0_0_START (20)
#define SOC_CSI2IF_ALP_rxsynctypehs0_0_END (22)
#define SOC_CSI2IF_ALP_rxsynctypehs1_0_START (24)
#define SOC_CSI2IF_ALP_rxsynctypehs1_0_END (26)
#define SOC_CSI2IF_ALP_alp_mode_en_START (28)
#define SOC_CSI2IF_ALP_alp_mode_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppi_mon_en : 1;
        unsigned int time_out_mon_en : 1;
        unsigned int reserved_0 : 6;
        unsigned int time_out_period : 16;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CSI2IF_PPI_MONITOR_CTRL_UNION;
#endif
#define SOC_CSI2IF_PPI_MONITOR_CTRL_ppi_mon_en_START (0)
#define SOC_CSI2IF_PPI_MONITOR_CTRL_ppi_mon_en_END (0)
#define SOC_CSI2IF_PPI_MONITOR_CTRL_time_out_mon_en_START (1)
#define SOC_CSI2IF_PPI_MONITOR_CTRL_time_out_mon_en_END (1)
#define SOC_CSI2IF_PPI_MONITOR_CTRL_time_out_period_START (8)
#define SOC_CSI2IF_PPI_MONITOR_CTRL_time_out_period_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lane0_rcvd_synchs : 16;
        unsigned int lane1_rcvd_synchs : 16;
    } reg;
} SOC_CSI2IF_PPI_MONITOR_GRP_0_UNION;
#endif
#define SOC_CSI2IF_PPI_MONITOR_GRP_0_lane0_rcvd_synchs_START (0)
#define SOC_CSI2IF_PPI_MONITOR_GRP_0_lane0_rcvd_synchs_END (15)
#define SOC_CSI2IF_PPI_MONITOR_GRP_0_lane1_rcvd_synchs_START (16)
#define SOC_CSI2IF_PPI_MONITOR_GRP_0_lane1_rcvd_synchs_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lane2_rcvd_synchs : 16;
        unsigned int lane3_rcvd_synchs : 16;
    } reg;
} SOC_CSI2IF_PPI_MONITOR_GRP_1_UNION;
#endif
#define SOC_CSI2IF_PPI_MONITOR_GRP_1_lane2_rcvd_synchs_START (0)
#define SOC_CSI2IF_PPI_MONITOR_GRP_1_lane2_rcvd_synchs_END (15)
#define SOC_CSI2IF_PPI_MONITOR_GRP_1_lane3_rcvd_synchs_START (16)
#define SOC_CSI2IF_PPI_MONITOR_GRP_1_lane3_rcvd_synchs_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lane0_timeout : 1;
        unsigned int lane1_timeout : 1;
        unsigned int lane2_timeout : 1;
        unsigned int lane3_timeout : 1;
        unsigned int timeout_clear : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CSI2IF_PPI_MONITOR_GRP_2_UNION;
#endif
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane0_timeout_START (0)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane0_timeout_END (0)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane1_timeout_START (1)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane1_timeout_END (1)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane2_timeout_START (2)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane2_timeout_END (2)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane3_timeout_START (3)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_lane3_timeout_END (3)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_timeout_clear_START (4)
#define SOC_CSI2IF_PPI_MONITOR_GRP_2_timeout_clear_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc0_mon_en : 1;
        unsigned int vc1_mon_en : 1;
        unsigned int vc2_mon_en : 1;
        unsigned int vc3_mon_en : 1;
        unsigned int vc4_mon_en : 1;
        unsigned int vc5_mon_en : 1;
        unsigned int vc6_mon_en : 1;
        unsigned int vc7_mon_en : 1;
        unsigned int vc8_mon_en : 1;
        unsigned int vc9_mon_en : 1;
        unsigned int vc10_mon_en : 1;
        unsigned int vc11_mon_en : 1;
        unsigned int vc12_mon_en : 1;
        unsigned int vc13_mon_en : 1;
        unsigned int vc14_mon_en : 1;
        unsigned int vc15_mon_en : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_UNION;
#endif
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc0_mon_en_START (0)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc0_mon_en_END (0)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc1_mon_en_START (1)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc1_mon_en_END (1)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc2_mon_en_START (2)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc2_mon_en_END (2)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc3_mon_en_START (3)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc3_mon_en_END (3)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc4_mon_en_START (4)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc4_mon_en_END (4)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc5_mon_en_START (5)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc5_mon_en_END (5)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc6_mon_en_START (6)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc6_mon_en_END (6)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc7_mon_en_START (7)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc7_mon_en_END (7)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc8_mon_en_START (8)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc8_mon_en_END (8)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc9_mon_en_START (9)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc9_mon_en_END (9)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc10_mon_en_START (10)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc10_mon_en_END (10)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc11_mon_en_START (11)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc11_mon_en_END (11)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc12_mon_en_START (12)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc12_mon_en_END (12)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc13_mon_en_START (13)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc13_mon_en_END (13)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc14_mon_en_START (14)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc14_mon_en_END (14)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc15_mon_en_START (15)
#define SOC_CSI2IF_VC_FRAME_PACKET_MONITOR_CTRL_vc15_mon_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc0_long_pkt_num : 16;
        unsigned int vc0_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC0_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC0_MONITOR_INFO_vc0_long_pkt_num_START (0)
#define SOC_CSI2IF_VC0_MONITOR_INFO_vc0_long_pkt_num_END (15)
#define SOC_CSI2IF_VC0_MONITOR_INFO_vc0_frame_num_START (16)
#define SOC_CSI2IF_VC0_MONITOR_INFO_vc0_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc1_long_pkt_num : 16;
        unsigned int vc1_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC1_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC1_MONITOR_INFO_vc1_long_pkt_num_START (0)
#define SOC_CSI2IF_VC1_MONITOR_INFO_vc1_long_pkt_num_END (15)
#define SOC_CSI2IF_VC1_MONITOR_INFO_vc1_frame_num_START (16)
#define SOC_CSI2IF_VC1_MONITOR_INFO_vc1_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc2_long_pkt_num : 16;
        unsigned int vc2_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC2_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC2_MONITOR_INFO_vc2_long_pkt_num_START (0)
#define SOC_CSI2IF_VC2_MONITOR_INFO_vc2_long_pkt_num_END (15)
#define SOC_CSI2IF_VC2_MONITOR_INFO_vc2_frame_num_START (16)
#define SOC_CSI2IF_VC2_MONITOR_INFO_vc2_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc3_long_pkt_num : 16;
        unsigned int vc3_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC3_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC3_MONITOR_INFO_vc3_long_pkt_num_START (0)
#define SOC_CSI2IF_VC3_MONITOR_INFO_vc3_long_pkt_num_END (15)
#define SOC_CSI2IF_VC3_MONITOR_INFO_vc3_frame_num_START (16)
#define SOC_CSI2IF_VC3_MONITOR_INFO_vc3_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc4_long_pkt_num : 16;
        unsigned int vc4_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC4_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC4_MONITOR_INFO_vc4_long_pkt_num_START (0)
#define SOC_CSI2IF_VC4_MONITOR_INFO_vc4_long_pkt_num_END (15)
#define SOC_CSI2IF_VC4_MONITOR_INFO_vc4_frame_num_START (16)
#define SOC_CSI2IF_VC4_MONITOR_INFO_vc4_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc5_long_pkt_num : 16;
        unsigned int vc5_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC5_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC5_MONITOR_INFO_vc5_long_pkt_num_START (0)
#define SOC_CSI2IF_VC5_MONITOR_INFO_vc5_long_pkt_num_END (15)
#define SOC_CSI2IF_VC5_MONITOR_INFO_vc5_frame_num_START (16)
#define SOC_CSI2IF_VC5_MONITOR_INFO_vc5_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc6_long_pkt_num : 16;
        unsigned int vc6_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC6_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC6_MONITOR_INFO_vc6_long_pkt_num_START (0)
#define SOC_CSI2IF_VC6_MONITOR_INFO_vc6_long_pkt_num_END (15)
#define SOC_CSI2IF_VC6_MONITOR_INFO_vc6_frame_num_START (16)
#define SOC_CSI2IF_VC6_MONITOR_INFO_vc6_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc7_long_pkt_num : 16;
        unsigned int vc7_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC7_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC7_MONITOR_INFO_vc7_long_pkt_num_START (0)
#define SOC_CSI2IF_VC7_MONITOR_INFO_vc7_long_pkt_num_END (15)
#define SOC_CSI2IF_VC7_MONITOR_INFO_vc7_frame_num_START (16)
#define SOC_CSI2IF_VC7_MONITOR_INFO_vc7_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc8_long_pkt_num : 16;
        unsigned int vc8_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC8_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC8_MONITOR_INFO_vc8_long_pkt_num_START (0)
#define SOC_CSI2IF_VC8_MONITOR_INFO_vc8_long_pkt_num_END (15)
#define SOC_CSI2IF_VC8_MONITOR_INFO_vc8_frame_num_START (16)
#define SOC_CSI2IF_VC8_MONITOR_INFO_vc8_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc9_long_pkt_num : 16;
        unsigned int vc9_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC9_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC9_MONITOR_INFO_vc9_long_pkt_num_START (0)
#define SOC_CSI2IF_VC9_MONITOR_INFO_vc9_long_pkt_num_END (15)
#define SOC_CSI2IF_VC9_MONITOR_INFO_vc9_frame_num_START (16)
#define SOC_CSI2IF_VC9_MONITOR_INFO_vc9_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc10_long_pkt_num : 16;
        unsigned int vc10_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC10_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC10_MONITOR_INFO_vc10_long_pkt_num_START (0)
#define SOC_CSI2IF_VC10_MONITOR_INFO_vc10_long_pkt_num_END (15)
#define SOC_CSI2IF_VC10_MONITOR_INFO_vc10_frame_num_START (16)
#define SOC_CSI2IF_VC10_MONITOR_INFO_vc10_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc11_long_pkt_num : 16;
        unsigned int vc11_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC11_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC11_MONITOR_INFO_vc11_long_pkt_num_START (0)
#define SOC_CSI2IF_VC11_MONITOR_INFO_vc11_long_pkt_num_END (15)
#define SOC_CSI2IF_VC11_MONITOR_INFO_vc11_frame_num_START (16)
#define SOC_CSI2IF_VC11_MONITOR_INFO_vc11_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc12_long_pkt_num : 16;
        unsigned int vc12_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC12_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC12_MONITOR_INFO_vc12_long_pkt_num_START (0)
#define SOC_CSI2IF_VC12_MONITOR_INFO_vc12_long_pkt_num_END (15)
#define SOC_CSI2IF_VC12_MONITOR_INFO_vc12_frame_num_START (16)
#define SOC_CSI2IF_VC12_MONITOR_INFO_vc12_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc13_long_pkt_num : 16;
        unsigned int vc13_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC13_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC13_MONITOR_INFO_vc13_long_pkt_num_START (0)
#define SOC_CSI2IF_VC13_MONITOR_INFO_vc13_long_pkt_num_END (15)
#define SOC_CSI2IF_VC13_MONITOR_INFO_vc13_frame_num_START (16)
#define SOC_CSI2IF_VC13_MONITOR_INFO_vc13_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc14_long_pkt_num : 16;
        unsigned int vc14_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC14_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC14_MONITOR_INFO_vc14_long_pkt_num_START (0)
#define SOC_CSI2IF_VC14_MONITOR_INFO_vc14_long_pkt_num_END (15)
#define SOC_CSI2IF_VC14_MONITOR_INFO_vc14_frame_num_START (16)
#define SOC_CSI2IF_VC14_MONITOR_INFO_vc14_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc15_long_pkt_num : 16;
        unsigned int vc15_frame_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI2IF_VC15_MONITOR_INFO_UNION;
#endif
#define SOC_CSI2IF_VC15_MONITOR_INFO_vc15_long_pkt_num_START (0)
#define SOC_CSI2IF_VC15_MONITOR_INFO_vc15_long_pkt_num_END (15)
#define SOC_CSI2IF_VC15_MONITOR_INFO_vc15_frame_num_START (16)
#define SOC_CSI2IF_VC15_MONITOR_INFO_vc15_frame_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int status_ecc_double_error : 1;
        unsigned int status_header_crc_error : 1;
        unsigned int status_payload_crc_error : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_UNION;
#endif
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_status_ecc_double_error_START (0)
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_status_ecc_double_error_END (0)
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_status_header_crc_error_START (1)
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_status_header_crc_error_END (1)
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_status_payload_crc_error_START (2)
#define SOC_CSI2IF_INT_ST_CRC_OR_ECC_ERROR_status_payload_crc_error_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_ecc_double_error : 1;
        unsigned int mask_header_crc_error : 1;
        unsigned int mask_payload_crc_error : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_UNION;
#endif
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_mask_ecc_double_error_START (0)
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_mask_ecc_double_error_END (0)
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_mask_header_crc_error_START (1)
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_mask_header_crc_error_END (1)
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_mask_payload_crc_error_START (2)
#define SOC_CSI2IF_INT_MSK_CRC_OR_ECC_ERROR_mask_payload_crc_error_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_ecc_double_error : 1;
        unsigned int force_header_crc_error : 1;
        unsigned int force_payload_crc_error : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_UNION;
#endif
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_force_ecc_double_error_START (0)
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_force_ecc_double_error_END (0)
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_force_header_crc_error_START (1)
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_force_header_crc_error_END (1)
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_force_payload_crc_error_START (2)
#define SOC_CSI2IF_INT_FORCE_CRC_OR_ECC_ERROR_force_payload_crc_error_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int status_lane_skew_error : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI2IF_INT_LANE_SKEW_ERROR_UNION;
#endif
#define SOC_CSI2IF_INT_LANE_SKEW_ERROR_status_lane_skew_error_START (0)
#define SOC_CSI2IF_INT_LANE_SKEW_ERROR_status_lane_skew_error_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mask_lane_skew_error : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI2IF_INT_MSK_LANE_SKEW_ERROR_UNION;
#endif
#define SOC_CSI2IF_INT_MSK_LANE_SKEW_ERROR_mask_lane_skew_error_START (0)
#define SOC_CSI2IF_INT_MSK_LANE_SKEW_ERROR_mask_lane_skew_error_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_lane_skew_error : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI2IF_INT_FORCE_LANE_SKEW_ERROR_UNION;
#endif
#define SOC_CSI2IF_INT_FORCE_LANE_SKEW_ERROR_force_lane_skew_error_START (0)
#define SOC_CSI2IF_INT_FORCE_LANE_SKEW_ERROR_force_lane_skew_error_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
