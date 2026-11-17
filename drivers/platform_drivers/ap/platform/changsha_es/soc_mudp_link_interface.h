#ifndef __SOC_MUDP_LINK_INTERFACE_H__
#define __SOC_MUDP_LINK_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_LINK_VERSION_ADDR(base) (base)
#define SOC_MUDP_LINK_OPTION_MODE_ADDR(base) ((base) + 0x0004UL)
#define SOC_MUDP_LINK_LANE_CAPABILITY_ADDR(base) ((base) + 0x0008UL)
#define SOC_MUDP_LINK_RATE_CAPABILITY_ADDR(base) ((base) + 0x000cUL)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_ADDR(base) ((base) + 0x0010UL)
#define SOC_MUDP_LINK_LOW_POWER_CAP_ADDR(base) ((base) + 0x0014UL)
#define SOC_MUDP_LINK_PHY_DELAY_CAP_ADDR(base) ((base) + 0x0018UL)
#define SOC_MUDP_LINK_PHY_CONNECT_SETTING_ADDR(base) ((base) + 0x0050UL)
#define SOC_MUDP_LINK_TX_TIMING_ADDR(base) ((base) + 0x0100UL)
#define SOC_MUDP_LINK_OMC_SET_TX_ADDR(base) ((base) + 0x0104UL)
#define SOC_MUDP_LINK_OMC_SET_RX_ADDR(base) ((base) + 0x0108UL)
#define SOC_MUDP_LINK_OMC_START_ADDR(base) ((base) + 0x010cUL)
#define SOC_MUDP_LINK_OMC_STATUS_ADDR(base) ((base) + 0x0110UL)
#define SOC_MUDP_LINK_SLEEP_IDLE_LENGTH_SET_ADDR(base) ((base) + 0x0114UL)
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_ADDR(base) ((base) + 0x0118UL)
#define SOC_MUDP_LINK_PHY_DELAY_ADDR(base) ((base) + 0x011CUL)
#define SOC_MUDP_LINK_INTR_MASK_ADDR(base) ((base) + 0x0120UL)
#define SOC_MUDP_LINK_INT_STATUS_ADDR(base) ((base) + 0x0124UL)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_ADDR(base) ((base) + 0x0400UL)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_ADDR(base) ((base) + 0x0404UL)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_ADDR(base) ((base) + 0x0408UL)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_ERR_DATA_ADDR(base) ((base) + 0x040CUL)
#define SOC_MUDP_LINK_TL_RW_CMD_ADDR(base) ((base) + 0x0410UL)
#define SOC_MUDP_LINK_TL_RW_DAT0_ADDR(base) ((base) + 0x0414UL)
#define SOC_MUDP_LINK_TL_RW_DAT1_ADDR(base) ((base) + 0x0418UL)
#define SOC_MUDP_LINK_TL_RW_DAT2_ADDR(base) ((base) + 0x041cUL)
#define SOC_MUDP_LINK_TL_RW_DAT3_ADDR(base) ((base) + 0x0420UL)
#define SOC_MUDP_LINK_TL_RW_DAT4_ADDR(base) ((base) + 0x0424UL)
#define SOC_MUDP_LINK_TL_RW_DAT5_ADDR(base) ((base) + 0x0428UL)
#define SOC_MUDP_LINK_TL_RW_DAT6_ADDR(base) ((base) + 0x042cUL)
#define SOC_MUDP_LINK_TL_RW_DAT7_ADDR(base) ((base) + 0x0430UL)
#define SOC_MUDP_LINK_TL_RW_RST_ADDR(base) ((base) + 0x0434UL)
#define SOC_MUDP_LINK_TL_RR_CMD_ADDR(base) ((base) + 0x0440UL)
#define SOC_MUDP_LINK_TL_RR_DAT0_ADDR(base) ((base) + 0x0444UL)
#define SOC_MUDP_LINK_TL_RR_DAT1_ADDR(base) ((base) + 0x0448UL)
#define SOC_MUDP_LINK_TL_RR_DAT2_ADDR(base) ((base) + 0x044cUL)
#define SOC_MUDP_LINK_TL_RR_DAT3_ADDR(base) ((base) + 0x0450UL)
#define SOC_MUDP_LINK_TL_RR_DAT4_ADDR(base) ((base) + 0x0454UL)
#define SOC_MUDP_LINK_TL_RR_DAT5_ADDR(base) ((base) + 0x0458UL)
#define SOC_MUDP_LINK_TL_RR_DAT6_ADDR(base) ((base) + 0x045cUL)
#define SOC_MUDP_LINK_TL_RR_DAT7_ADDR(base) ((base) + 0x0460UL)
#define SOC_MUDP_LINK_TL_RR_RST_ADDR(base) ((base) + 0x0464UL)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_ADDR(base) ((base) + 0x0500UL)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_ADDR(base) ((base) + 0x0504UL)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_1_ADDR(base) ((base) + 0x0508UL)
#define SOC_MUDP_LINK_MAC_RX_SCRAMBLE_EN_ADDR(base) ((base) + 0x050CUL)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_ADDR(base) ((base) + 0x0510UL)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_1_ADDR(base) ((base) + 0x0514UL)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_ADDR(base) ((base) + 0x0518UL)
#define SOC_MUDP_LINK_MAC_RX_DESKEW_CTRL_ADDR(base) ((base) + 0x051CUL)
#define SOC_MUDP_LINK_MAC_RX_PHY_CTRL_ADDR(base) ((base) + 0x0520UL)
#define SOC_MUDP_LINK_MAC_RX_FEC_CTRL_ADDR(base) ((base) + 0x0524UL)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_SEL_ADDR(base) ((base) + 0x0538UL)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_FEC_ADDR(base) ((base) + 0x053CUL)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_0_ADDR(base,rx_ln) ((base) + 0x0540UL + (rx_ln) * 8)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_0_ADDR(base) ((base) + 0x0544UL)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_1_ADDR(base) ((base) + 0x054CUL)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_2_ADDR(base) ((base) + 0x0554UL)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_2_ADDR(base) ((base) + 0x0558UL)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_ADDR(base) ((base) + 0x055CUL)
#define SOC_MUDP_LINK_MAC_TX_CTRL_ADDR(base) ((base) + 0x0560UL)
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_ADDR(base) ((base) + 0x0564UL)
#define SOC_MUDP_LINK_MAC_TX_TS_SEQ_REQ_ADDR(base) ((base) + 0x0568UL)
#define SOC_MUDP_LINK_MAC_TX_SCRAMBLE_EN_ADDR(base) ((base) + 0x056cUL)
#define SOC_MUDP_LINK_MAC_TX_FEC_CTRL_ADDR(base) ((base) + 0x0572UL)
#define SOC_MUDP_LINK_MAC_TX_EVENT_ADDR(base,tx_ln) ((base) + 0x0576UL + (tx_ln) * 4)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_EQ_ADDR(base,tx_ln) ((base) + 0x0588UL + (tx_ln) * 4)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_0_ADDR(base) ((base) + 0x0594UL)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_1_ADDR(base) ((base) + 0x0598UL)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_2_ADDR(base) ((base) + 0x059CUL)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_EVENT_ADDR(base,tx_ln) ((base) + 0x05a0UL + (tx_ln) * 4)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_0_ADDR(base) ((base) + 0x05ACUL)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_1_ADDR(base) ((base) + 0x05B0UL)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_2_ADDR(base) ((base) + 0x05B4UL)
#define SOC_MUDP_LINK_MAC_TX_SYNC_DATA_128B_ADDR(base) ((base) + 0x05B8UL)
#define SOC_MUDP_LINK_MAC_TX_ALIGN_DATA_128B_ADDR(base) ((base) + 0x05BCUL)
#define SOC_MUDP_LINK_MC_CTRL0_ADDR(base) ((base) + 0x05C0UL)
#define SOC_MUDP_LINK_MC_STATUS_ADDR(base) ((base) + 0x05C4UL)
#define SOC_MUDP_LINK_MC_STATUS_1_ADDR(base) ((base) + 0x05C8UL)
#define SOC_MUDP_LINK_MC_STATUS_2_ADDR(base) ((base) + 0x05CCUL)
#define SOC_MUDP_LINK_MC_DEBUG_SEL0_ADDR(base) ((base) + 0x05D0UL)
#define SOC_MUDP_LINK_MC_DEBUG_BUS_ADDR(base) ((base) + 0x05D4UL)
#define SOC_MUDP_LINK_MC_CTRL1_ADDR(base) ((base) + 0x05D8UL)
#define SOC_MUDP_LINK_DL_CTRL_ADDR(base) ((base) + 0x0600UL)
#define SOC_MUDP_LINK_DL_IDLE_ADDR(base) ((base) + 0x0604UL)
#define SOC_MUDP_LINK_TL_IDLE_ADDR(base) ((base) + 0x0700UL)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_ADDR(base) ((base) + 0x0704UL)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_ADDR(base) ((base) + 0x0708UL)
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_ADDR(base) ((base) + 0x070CUL)
#define SOC_MUDP_LINK_TL_TST_DST_DEBUG_ADDR(base) ((base) + 0x0710UL)
#define SOC_MUDP_LINK_TL_RAC_TIMEOUT_CTRL_ADDR(base) ((base) + 0x071CUL)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_ADDR(base) ((base) + 0x0720UL)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_TIME_ADDR(base) ((base) + 0x0724UL)
#define SOC_MUDP_LINK_TL_ARB_MODE_ADDR(base) ((base) + 0x0728UL)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_ADDR(base) ((base) + 0x072CUL)
#define SOC_MUDP_LINK_LINK_STATUS_ADDR(base) ((base) + 0x0800UL)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_ADDR(base) ((base) + 0x080CUL)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_ADDR(base) ((base) + 0x0814UL)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_1_ADDR(base) ((base) + 0x0818UL)
#define SOC_MUDP_LINK_CFG_OMC_STATUS_ADDR(base) ((base) + 0x081CUL)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_0_ADDR(base) ((base) + 0x0820UL)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_1_ADDR(base) ((base) + 0x0824UL)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_2_ADDR(base) ((base) + 0x0828UL)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_3_ADDR(base) ((base) + 0x082CUL)
#define SOC_MUDP_LINK_CFG_OMC_PRE_CFG_ADDR(base) ((base) + 0x0830UL)
#define SOC_MUDP_LINK_CFG_OMC_EQ_CFG_ADDR(base) ((base) + 0x0834UL)
#define SOC_MUDP_LINK_CFG_CHG_INITIAL_MODE_EN_ADDR(base) ((base) + 0x0838UL)
#define SOC_MUDP_LINK_CFG_OMC_TX_PRE_CFG_ADDR(base) ((base) + 0x08F0UL)
#define SOC_MUDP_LINK_CFG_OMC_RX_PRE_CFG_ADDR(base) ((base) + 0x08F4UL)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_ADDR(base) ((base) + 0x08F8UL)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_ADDR(base) ((base) + 0x08FCUL)
#define SOC_MUDP_LINK_CRG_RST_CTRL_ADDR(base) ((base) + 0x0900UL)
#define SOC_MUDP_LINK_CRG_CLK_SEL_ADDR(base) ((base) + 0x0904UL)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_ADDR(base) ((base) + 0x0908UL)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_ADDR(base) ((base) + 0x090CUL)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_ADDR(base) ((base) + 0x0910UL)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_ADDR(base) ((base) + 0x0914UL)
#define SOC_MUDP_LINK_CRG_LINK_GT_EXP_ADDR(base) ((base) + 0x0918UL)
#define SOC_MUDP_LINK_DFX_CTRL_ADDR(base) ((base) + 0x0B00UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_ADDR(base) ((base) + 0x0B04UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_SET_ADDR(base) ((base) + 0x0B10UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_SET_ADDR(base) ((base) + 0x0B14UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_SET_ADDR(base) ((base) + 0x0B18UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_SET_ADDR(base) ((base) + 0x0B1CUL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_ADDR(base) ((base) + 0x0B20UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_ADDR(base) ((base) + 0x0B24UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_ADDR(base) ((base) + 0x0B28UL)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_ADDR(base) ((base) + 0x0B2CUL)
#define SOC_MUDP_LINK_DFX_MAC_TX_PHY_SEQ_INS_DBG_ADDR(base,tx_ln) ((base) + 0x0B30UL + (tx_ln) * 4)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG0_ADDR(base,rx_ln) ((base) + 0x0B3CUL + (rx_ln) * 4)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_ADDR(base) ((base) + 0x0B48UL)
#define SOC_MUDP_LINK_TEST_POINT_CTRL_ADDR(base) ((base) + 0x0B4CUL)
#define SOC_MUDP_LINK_TEST_POINT_ADDR(base) ((base) + 0x0B50UL)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG1_ADDR(base,rx_ln) ((base) + 0x0C00UL + (rx_ln) * 4)
#define SOC_MUDP_LINK_DFX_MAC_FEC_DBG_ADDR(base) ((base) + 0x0C0CUL)
#define SOC_MUDP_LINK_DFX_LDM_STATUS_ADDR(base) ((base) + 0x0C14UL)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_ADDR(base) ((base) + 0x0C18UL)
#else
#define SOC_MUDP_LINK_VERSION_ADDR(base) (base)
#define SOC_MUDP_LINK_OPTION_MODE_ADDR(base) ((base) + 0x0004)
#define SOC_MUDP_LINK_LANE_CAPABILITY_ADDR(base) ((base) + 0x0008)
#define SOC_MUDP_LINK_RATE_CAPABILITY_ADDR(base) ((base) + 0x000c)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_ADDR(base) ((base) + 0x0010)
#define SOC_MUDP_LINK_LOW_POWER_CAP_ADDR(base) ((base) + 0x0014)
#define SOC_MUDP_LINK_PHY_DELAY_CAP_ADDR(base) ((base) + 0x0018)
#define SOC_MUDP_LINK_PHY_CONNECT_SETTING_ADDR(base) ((base) + 0x0050)
#define SOC_MUDP_LINK_TX_TIMING_ADDR(base) ((base) + 0x0100)
#define SOC_MUDP_LINK_OMC_SET_TX_ADDR(base) ((base) + 0x0104)
#define SOC_MUDP_LINK_OMC_SET_RX_ADDR(base) ((base) + 0x0108)
#define SOC_MUDP_LINK_OMC_START_ADDR(base) ((base) + 0x010c)
#define SOC_MUDP_LINK_OMC_STATUS_ADDR(base) ((base) + 0x0110)
#define SOC_MUDP_LINK_SLEEP_IDLE_LENGTH_SET_ADDR(base) ((base) + 0x0114)
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_ADDR(base) ((base) + 0x0118)
#define SOC_MUDP_LINK_PHY_DELAY_ADDR(base) ((base) + 0x011C)
#define SOC_MUDP_LINK_INTR_MASK_ADDR(base) ((base) + 0x0120)
#define SOC_MUDP_LINK_INT_STATUS_ADDR(base) ((base) + 0x0124)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_ADDR(base) ((base) + 0x0400)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_ADDR(base) ((base) + 0x0404)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_ADDR(base) ((base) + 0x0408)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_ERR_DATA_ADDR(base) ((base) + 0x040C)
#define SOC_MUDP_LINK_TL_RW_CMD_ADDR(base) ((base) + 0x0410)
#define SOC_MUDP_LINK_TL_RW_DAT0_ADDR(base) ((base) + 0x0414)
#define SOC_MUDP_LINK_TL_RW_DAT1_ADDR(base) ((base) + 0x0418)
#define SOC_MUDP_LINK_TL_RW_DAT2_ADDR(base) ((base) + 0x041c)
#define SOC_MUDP_LINK_TL_RW_DAT3_ADDR(base) ((base) + 0x0420)
#define SOC_MUDP_LINK_TL_RW_DAT4_ADDR(base) ((base) + 0x0424)
#define SOC_MUDP_LINK_TL_RW_DAT5_ADDR(base) ((base) + 0x0428)
#define SOC_MUDP_LINK_TL_RW_DAT6_ADDR(base) ((base) + 0x042c)
#define SOC_MUDP_LINK_TL_RW_DAT7_ADDR(base) ((base) + 0x0430)
#define SOC_MUDP_LINK_TL_RW_RST_ADDR(base) ((base) + 0x0434)
#define SOC_MUDP_LINK_TL_RR_CMD_ADDR(base) ((base) + 0x0440)
#define SOC_MUDP_LINK_TL_RR_DAT0_ADDR(base) ((base) + 0x0444)
#define SOC_MUDP_LINK_TL_RR_DAT1_ADDR(base) ((base) + 0x0448)
#define SOC_MUDP_LINK_TL_RR_DAT2_ADDR(base) ((base) + 0x044c)
#define SOC_MUDP_LINK_TL_RR_DAT3_ADDR(base) ((base) + 0x0450)
#define SOC_MUDP_LINK_TL_RR_DAT4_ADDR(base) ((base) + 0x0454)
#define SOC_MUDP_LINK_TL_RR_DAT5_ADDR(base) ((base) + 0x0458)
#define SOC_MUDP_LINK_TL_RR_DAT6_ADDR(base) ((base) + 0x045c)
#define SOC_MUDP_LINK_TL_RR_DAT7_ADDR(base) ((base) + 0x0460)
#define SOC_MUDP_LINK_TL_RR_RST_ADDR(base) ((base) + 0x0464)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_ADDR(base) ((base) + 0x0500)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_ADDR(base) ((base) + 0x0504)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_1_ADDR(base) ((base) + 0x0508)
#define SOC_MUDP_LINK_MAC_RX_SCRAMBLE_EN_ADDR(base) ((base) + 0x050C)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_ADDR(base) ((base) + 0x0510)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_1_ADDR(base) ((base) + 0x0514)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_ADDR(base) ((base) + 0x0518)
#define SOC_MUDP_LINK_MAC_RX_DESKEW_CTRL_ADDR(base) ((base) + 0x051C)
#define SOC_MUDP_LINK_MAC_RX_PHY_CTRL_ADDR(base) ((base) + 0x0520)
#define SOC_MUDP_LINK_MAC_RX_FEC_CTRL_ADDR(base) ((base) + 0x0524)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_SEL_ADDR(base) ((base) + 0x0538)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_FEC_ADDR(base) ((base) + 0x053C)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_0_ADDR(base,rx_ln) ((base) + 0x0540 + (rx_ln) * 8)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_0_ADDR(base) ((base) + 0x0544)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_1_ADDR(base) ((base) + 0x054C)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_2_ADDR(base) ((base) + 0x0554)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_2_ADDR(base) ((base) + 0x0558)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_ADDR(base) ((base) + 0x055C)
#define SOC_MUDP_LINK_MAC_TX_CTRL_ADDR(base) ((base) + 0x0560)
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_ADDR(base) ((base) + 0x0564)
#define SOC_MUDP_LINK_MAC_TX_TS_SEQ_REQ_ADDR(base) ((base) + 0x0568)
#define SOC_MUDP_LINK_MAC_TX_SCRAMBLE_EN_ADDR(base) ((base) + 0x056c)
#define SOC_MUDP_LINK_MAC_TX_FEC_CTRL_ADDR(base) ((base) + 0x0572)
#define SOC_MUDP_LINK_MAC_TX_EVENT_ADDR(base,tx_ln) ((base) + 0x0576 + (tx_ln) * 4)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_EQ_ADDR(base,tx_ln) ((base) + 0x0588 + (tx_ln) * 4)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_0_ADDR(base) ((base) + 0x0594)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_1_ADDR(base) ((base) + 0x0598)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_2_ADDR(base) ((base) + 0x059C)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_EVENT_ADDR(base,tx_ln) ((base) + 0x05a0 + (tx_ln) * 4)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_0_ADDR(base) ((base) + 0x05AC)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_1_ADDR(base) ((base) + 0x05B0)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_2_ADDR(base) ((base) + 0x05B4)
#define SOC_MUDP_LINK_MAC_TX_SYNC_DATA_128B_ADDR(base) ((base) + 0x05B8)
#define SOC_MUDP_LINK_MAC_TX_ALIGN_DATA_128B_ADDR(base) ((base) + 0x05BC)
#define SOC_MUDP_LINK_MC_CTRL0_ADDR(base) ((base) + 0x05C0)
#define SOC_MUDP_LINK_MC_STATUS_ADDR(base) ((base) + 0x05C4)
#define SOC_MUDP_LINK_MC_STATUS_1_ADDR(base) ((base) + 0x05C8)
#define SOC_MUDP_LINK_MC_STATUS_2_ADDR(base) ((base) + 0x05CC)
#define SOC_MUDP_LINK_MC_DEBUG_SEL0_ADDR(base) ((base) + 0x05D0)
#define SOC_MUDP_LINK_MC_DEBUG_BUS_ADDR(base) ((base) + 0x05D4)
#define SOC_MUDP_LINK_MC_CTRL1_ADDR(base) ((base) + 0x05D8)
#define SOC_MUDP_LINK_DL_CTRL_ADDR(base) ((base) + 0x0600)
#define SOC_MUDP_LINK_DL_IDLE_ADDR(base) ((base) + 0x0604)
#define SOC_MUDP_LINK_TL_IDLE_ADDR(base) ((base) + 0x0700)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_ADDR(base) ((base) + 0x0704)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_ADDR(base) ((base) + 0x0708)
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_ADDR(base) ((base) + 0x070C)
#define SOC_MUDP_LINK_TL_TST_DST_DEBUG_ADDR(base) ((base) + 0x0710)
#define SOC_MUDP_LINK_TL_RAC_TIMEOUT_CTRL_ADDR(base) ((base) + 0x071C)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_ADDR(base) ((base) + 0x0720)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_TIME_ADDR(base) ((base) + 0x0724)
#define SOC_MUDP_LINK_TL_ARB_MODE_ADDR(base) ((base) + 0x0728)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_ADDR(base) ((base) + 0x072C)
#define SOC_MUDP_LINK_LINK_STATUS_ADDR(base) ((base) + 0x0800)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_ADDR(base) ((base) + 0x080C)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_ADDR(base) ((base) + 0x0814)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_1_ADDR(base) ((base) + 0x0818)
#define SOC_MUDP_LINK_CFG_OMC_STATUS_ADDR(base) ((base) + 0x081C)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_0_ADDR(base) ((base) + 0x0820)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_1_ADDR(base) ((base) + 0x0824)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_2_ADDR(base) ((base) + 0x0828)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_3_ADDR(base) ((base) + 0x082C)
#define SOC_MUDP_LINK_CFG_OMC_PRE_CFG_ADDR(base) ((base) + 0x0830)
#define SOC_MUDP_LINK_CFG_OMC_EQ_CFG_ADDR(base) ((base) + 0x0834)
#define SOC_MUDP_LINK_CFG_CHG_INITIAL_MODE_EN_ADDR(base) ((base) + 0x0838)
#define SOC_MUDP_LINK_CFG_OMC_TX_PRE_CFG_ADDR(base) ((base) + 0x08F0)
#define SOC_MUDP_LINK_CFG_OMC_RX_PRE_CFG_ADDR(base) ((base) + 0x08F4)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_ADDR(base) ((base) + 0x08F8)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_ADDR(base) ((base) + 0x08FC)
#define SOC_MUDP_LINK_CRG_RST_CTRL_ADDR(base) ((base) + 0x0900)
#define SOC_MUDP_LINK_CRG_CLK_SEL_ADDR(base) ((base) + 0x0904)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_ADDR(base) ((base) + 0x0908)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_ADDR(base) ((base) + 0x090C)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_ADDR(base) ((base) + 0x0910)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_ADDR(base) ((base) + 0x0914)
#define SOC_MUDP_LINK_CRG_LINK_GT_EXP_ADDR(base) ((base) + 0x0918)
#define SOC_MUDP_LINK_DFX_CTRL_ADDR(base) ((base) + 0x0B00)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_ADDR(base) ((base) + 0x0B04)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_SET_ADDR(base) ((base) + 0x0B10)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_SET_ADDR(base) ((base) + 0x0B14)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_SET_ADDR(base) ((base) + 0x0B18)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_SET_ADDR(base) ((base) + 0x0B1C)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_ADDR(base) ((base) + 0x0B20)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_ADDR(base) ((base) + 0x0B24)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_ADDR(base) ((base) + 0x0B28)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_ADDR(base) ((base) + 0x0B2C)
#define SOC_MUDP_LINK_DFX_MAC_TX_PHY_SEQ_INS_DBG_ADDR(base,tx_ln) ((base) + 0x0B30 + (tx_ln) * 4)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG0_ADDR(base,rx_ln) ((base) + 0x0B3C + (rx_ln) * 4)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_ADDR(base) ((base) + 0x0B48)
#define SOC_MUDP_LINK_TEST_POINT_CTRL_ADDR(base) ((base) + 0x0B4C)
#define SOC_MUDP_LINK_TEST_POINT_ADDR(base) ((base) + 0x0B50)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG1_ADDR(base,rx_ln) ((base) + 0x0C00 + (rx_ln) * 4)
#define SOC_MUDP_LINK_DFX_MAC_FEC_DBG_ADDR(base) ((base) + 0x0C0C)
#define SOC_MUDP_LINK_DFX_LDM_STATUS_ADDR(base) ((base) + 0x0C14)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_ADDR(base) ((base) + 0x0C18)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int version : 8;
        unsigned int vendor_id : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_LINK_VERSION_UNION;
#endif
#define SOC_MUDP_LINK_VERSION_version_START (0)
#define SOC_MUDP_LINK_VERSION_version_END (7)
#define SOC_MUDP_LINK_VERSION_vendor_id_START (8)
#define SOC_MUDP_LINK_VERSION_vendor_id_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int option_mode : 2;
        unsigned int control_mode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_LINK_OPTION_MODE_UNION;
#endif
#define SOC_MUDP_LINK_OPTION_MODE_option_mode_START (0)
#define SOC_MUDP_LINK_OPTION_MODE_option_mode_END (1)
#define SOC_MUDP_LINK_OPTION_MODE_control_mode_START (2)
#define SOC_MUDP_LINK_OPTION_MODE_control_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_lane_cap : 4;
        unsigned int rx_lane_cap : 4;
        unsigned int tx_fec_cap : 1;
        unsigned int rx_fec_cap : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_MUDP_LINK_LANE_CAPABILITY_UNION;
#endif
#define SOC_MUDP_LINK_LANE_CAPABILITY_tx_lane_cap_START (0)
#define SOC_MUDP_LINK_LANE_CAPABILITY_tx_lane_cap_END (3)
#define SOC_MUDP_LINK_LANE_CAPABILITY_rx_lane_cap_START (4)
#define SOC_MUDP_LINK_LANE_CAPABILITY_rx_lane_cap_END (7)
#define SOC_MUDP_LINK_LANE_CAPABILITY_tx_fec_cap_START (8)
#define SOC_MUDP_LINK_LANE_CAPABILITY_tx_fec_cap_END (8)
#define SOC_MUDP_LINK_LANE_CAPABILITY_rx_fec_cap_START (9)
#define SOC_MUDP_LINK_LANE_CAPABILITY_rx_fec_cap_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rate_mode_cap : 1;
        unsigned int series_cap : 3;
        unsigned int reserved_0 : 4;
        unsigned int tx_rate_cap : 8;
        unsigned int reserved_1 : 8;
        unsigned int rx_rate_cap : 8;
    } reg;
} SOC_MUDP_LINK_RATE_CAPABILITY_UNION;
#endif
#define SOC_MUDP_LINK_RATE_CAPABILITY_rate_mode_cap_START (0)
#define SOC_MUDP_LINK_RATE_CAPABILITY_rate_mode_cap_END (0)
#define SOC_MUDP_LINK_RATE_CAPABILITY_series_cap_START (1)
#define SOC_MUDP_LINK_RATE_CAPABILITY_series_cap_END (3)
#define SOC_MUDP_LINK_RATE_CAPABILITY_tx_rate_cap_START (8)
#define SOC_MUDP_LINK_RATE_CAPABILITY_tx_rate_cap_END (15)
#define SOC_MUDP_LINK_RATE_CAPABILITY_rx_rate_cap_START (24)
#define SOC_MUDP_LINK_RATE_CAPABILITY_rx_rate_cap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_drc_time_ss_cap : 4;
        unsigned int rx_drc_time_ds_cap : 4;
        unsigned int rx_eq_time_cap : 8;
        unsigned int rx_sync_time_ls_cap : 8;
        unsigned int rx_sync_time_hs_cap : 8;
    } reg;
} SOC_MUDP_LINK_RX_TIMING_CAPABILITY_UNION;
#endif
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_drc_time_ss_cap_START (0)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_drc_time_ss_cap_END (3)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_drc_time_ds_cap_START (4)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_drc_time_ds_cap_END (7)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_eq_time_cap_START (8)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_eq_time_cap_END (15)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_sync_time_ls_cap_START (16)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_sync_time_ls_cap_END (23)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_sync_time_hs_cap_START (24)
#define SOC_MUDP_LINK_RX_TIMING_CAPABILITY_rx_sync_time_hs_cap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stall_hold_time_cap : 8;
        unsigned int sleep_hold_time_cap : 8;
        unsigned int rx_sleep_idle_length_cap : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_LINK_LOW_POWER_CAP_UNION;
#endif
#define SOC_MUDP_LINK_LOW_POWER_CAP_stall_hold_time_cap_START (0)
#define SOC_MUDP_LINK_LOW_POWER_CAP_stall_hold_time_cap_END (7)
#define SOC_MUDP_LINK_LOW_POWER_CAP_sleep_hold_time_cap_START (8)
#define SOC_MUDP_LINK_LOW_POWER_CAP_sleep_hold_time_cap_END (15)
#define SOC_MUDP_LINK_LOW_POWER_CAP_rx_sleep_idle_length_cap_START (16)
#define SOC_MUDP_LINK_LOW_POWER_CAP_rx_sleep_idle_length_cap_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int local_tx_phy_delay_cap : 12;
        unsigned int reserved_0 : 4;
        unsigned int local_rx_phy_delay_cap : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MUDP_LINK_PHY_DELAY_CAP_UNION;
#endif
#define SOC_MUDP_LINK_PHY_DELAY_CAP_local_tx_phy_delay_cap_START (0)
#define SOC_MUDP_LINK_PHY_DELAY_CAP_local_tx_phy_delay_cap_END (11)
#define SOC_MUDP_LINK_PHY_DELAY_CAP_local_rx_phy_delay_cap_START (16)
#define SOC_MUDP_LINK_PHY_DELAY_CAP_local_rx_phy_delay_cap_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_connect_phy_cnt : 4;
        unsigned int tx_connect_phy_cnt : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_LINK_PHY_CONNECT_SETTING_UNION;
#endif
#define SOC_MUDP_LINK_PHY_CONNECT_SETTING_rx_connect_phy_cnt_START (0)
#define SOC_MUDP_LINK_PHY_CONNECT_SETTING_rx_connect_phy_cnt_END (3)
#define SOC_MUDP_LINK_PHY_CONNECT_SETTING_tx_connect_phy_cnt_START (4)
#define SOC_MUDP_LINK_PHY_CONNECT_SETTING_tx_connect_phy_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_drc_time_ss : 4;
        unsigned int tx_drc_time_ds : 4;
        unsigned int tx_sync_time_ls : 8;
        unsigned int tx_sync_time_hs : 8;
        unsigned int tx_eq_time : 8;
    } reg;
} SOC_MUDP_LINK_TX_TIMING_UNION;
#endif
#define SOC_MUDP_LINK_TX_TIMING_tx_drc_time_ss_START (0)
#define SOC_MUDP_LINK_TX_TIMING_tx_drc_time_ss_END (3)
#define SOC_MUDP_LINK_TX_TIMING_tx_drc_time_ds_START (4)
#define SOC_MUDP_LINK_TX_TIMING_tx_drc_time_ds_END (7)
#define SOC_MUDP_LINK_TX_TIMING_tx_sync_time_ls_START (8)
#define SOC_MUDP_LINK_TX_TIMING_tx_sync_time_ls_END (15)
#define SOC_MUDP_LINK_TX_TIMING_tx_sync_time_hs_START (16)
#define SOC_MUDP_LINK_TX_TIMING_tx_sync_time_hs_END (23)
#define SOC_MUDP_LINK_TX_TIMING_tx_eq_time_START (24)
#define SOC_MUDP_LINK_TX_TIMING_tx_eq_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_rate : 8;
        unsigned int tx_series : 2;
        unsigned int tx_fec_en : 1;
        unsigned int tx_code_mode : 1;
        unsigned int tx_lane_num : 4;
        unsigned int tx_swing_level : 4;
        unsigned int tx_swing_level_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tx_preset_level : 4;
        unsigned int tx_preset_level_en : 1;
        unsigned int tx_skew_en : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_MUDP_LINK_OMC_SET_TX_UNION;
#endif
#define SOC_MUDP_LINK_OMC_SET_TX_tx_rate_START (0)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_rate_END (7)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_series_START (8)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_series_END (9)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_fec_en_START (10)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_fec_en_END (10)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_code_mode_START (11)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_code_mode_END (11)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_lane_num_START (12)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_lane_num_END (15)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_swing_level_START (16)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_swing_level_END (19)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_swing_level_en_START (20)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_swing_level_en_END (20)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_preset_level_START (24)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_preset_level_END (27)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_preset_level_en_START (28)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_preset_level_en_END (28)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_skew_en_START (29)
#define SOC_MUDP_LINK_OMC_SET_TX_tx_skew_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_rate : 8;
        unsigned int rx_series : 2;
        unsigned int rx_fec_en : 1;
        unsigned int rx_code_mode : 1;
        unsigned int rx_lane_num : 4;
        unsigned int rx_swing_level_req : 4;
        unsigned int rx_swing_req_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int rx_preset_level_req : 4;
        unsigned int rx_preset_req_en : 1;
        unsigned int rx_skew_en : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_MUDP_LINK_OMC_SET_RX_UNION;
#endif
#define SOC_MUDP_LINK_OMC_SET_RX_rx_rate_START (0)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_rate_END (7)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_series_START (8)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_series_END (9)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_fec_en_START (10)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_fec_en_END (10)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_code_mode_START (11)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_code_mode_END (11)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_lane_num_START (12)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_lane_num_END (15)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_swing_level_req_START (16)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_swing_level_req_END (19)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_swing_req_en_START (20)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_swing_req_en_END (20)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_preset_level_req_START (24)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_preset_level_req_END (27)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_preset_req_en_START (28)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_preset_req_en_END (28)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_skew_en_START (29)
#define SOC_MUDP_LINK_OMC_SET_RX_rx_skew_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_start : 1;
        unsigned int rx_rate_chg_en : 1;
        unsigned int rx_eq_en : 1;
        unsigned int tx_rate_chg_en : 1;
        unsigned int tx_eq_en : 1;
        unsigned int rate_chg_init_mode : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_LINK_OMC_START_UNION;
#endif
#define SOC_MUDP_LINK_OMC_START_omc_start_START (0)
#define SOC_MUDP_LINK_OMC_START_omc_start_END (0)
#define SOC_MUDP_LINK_OMC_START_rx_rate_chg_en_START (1)
#define SOC_MUDP_LINK_OMC_START_rx_rate_chg_en_END (1)
#define SOC_MUDP_LINK_OMC_START_rx_eq_en_START (2)
#define SOC_MUDP_LINK_OMC_START_rx_eq_en_END (2)
#define SOC_MUDP_LINK_OMC_START_tx_rate_chg_en_START (3)
#define SOC_MUDP_LINK_OMC_START_tx_rate_chg_en_END (3)
#define SOC_MUDP_LINK_OMC_START_tx_eq_en_START (4)
#define SOC_MUDP_LINK_OMC_START_tx_eq_en_END (4)
#define SOC_MUDP_LINK_OMC_START_rate_chg_init_mode_START (5)
#define SOC_MUDP_LINK_OMC_START_rate_chg_init_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_LINK_OMC_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_OMC_STATUS_omc_status_START (0)
#define SOC_MUDP_LINK_OMC_STATUS_omc_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_sleep_idle_length : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_LINK_SLEEP_IDLE_LENGTH_SET_UNION;
#endif
#define SOC_MUDP_LINK_SLEEP_IDLE_LENGTH_SET_tx_sleep_idle_length_START (0)
#define SOC_MUDP_LINK_SLEEP_IDLE_LENGTH_SET_tx_sleep_idle_length_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_hold_time : 8;
        unsigned int sleep_exit_time_slot_mask : 4;
        unsigned int reserved : 4;
        unsigned int sleep_exit_time_slot_en : 16;
    } reg;
} SOC_MUDP_LINK_SLEEP_TIMING_SET_UNION;
#endif
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_sleep_hold_time_START (0)
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_sleep_hold_time_END (7)
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_sleep_exit_time_slot_mask_START (8)
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_sleep_exit_time_slot_mask_END (11)
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_sleep_exit_time_slot_en_START (16)
#define SOC_MUDP_LINK_SLEEP_TIMING_SET_sleep_exit_time_slot_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peer_tx_phy_delay : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MUDP_LINK_PHY_DELAY_UNION;
#endif
#define SOC_MUDP_LINK_PHY_DELAY_peer_tx_phy_delay_START (0)
#define SOC_MUDP_LINK_PHY_DELAY_peer_tx_phy_delay_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_omc_done_enable : 1;
        unsigned int int_cmd_read_done_enable : 1;
        unsigned int int_cmd_write_done_enable : 1;
        unsigned int int_cmd_timeout_enable : 1;
        unsigned int int_link_lost_enable : 1;
        unsigned int int_link_fatal_error_enable : 1;
        unsigned int int_static_done_enable : 1;
        unsigned int reserved_0 : 9;
        unsigned int int_mac_mode_force_chg_enable : 1;
        unsigned int int_max_rx_deskew_timeout_enable : 1;
        unsigned int int_mac_rx_deskew_done_enable : 1;
        unsigned int int_mac_event_ack_timeout_enable : 1;
        unsigned int int_tl_errr_flag_unexpect_apid_enable : 1;
        unsigned int int_mod2cfg_sleep_entry_flag_enable : 1;
        unsigned int int_mod2cfg_sleep_exit_flag_enable : 1;
        unsigned int int_mac_rx_align_det_timeout_flag_enable : 1;
        unsigned int int_fec_buf_wr_over_rd_flag_enable : 1;
        unsigned int int_mac_rx_fec_dec2_err_uncor_flag_enable : 1;
        unsigned int int_mac_rx_fec_dec1_err_uncor_flag_enable : 1;
        unsigned int int_mac_rx_fec_dec0_err_uncor_flag_enable : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MUDP_LINK_INTR_MASK_UNION;
#endif
#define SOC_MUDP_LINK_INTR_MASK_int_omc_done_enable_START (0)
#define SOC_MUDP_LINK_INTR_MASK_int_omc_done_enable_END (0)
#define SOC_MUDP_LINK_INTR_MASK_int_cmd_read_done_enable_START (1)
#define SOC_MUDP_LINK_INTR_MASK_int_cmd_read_done_enable_END (1)
#define SOC_MUDP_LINK_INTR_MASK_int_cmd_write_done_enable_START (2)
#define SOC_MUDP_LINK_INTR_MASK_int_cmd_write_done_enable_END (2)
#define SOC_MUDP_LINK_INTR_MASK_int_cmd_timeout_enable_START (3)
#define SOC_MUDP_LINK_INTR_MASK_int_cmd_timeout_enable_END (3)
#define SOC_MUDP_LINK_INTR_MASK_int_link_lost_enable_START (4)
#define SOC_MUDP_LINK_INTR_MASK_int_link_lost_enable_END (4)
#define SOC_MUDP_LINK_INTR_MASK_int_link_fatal_error_enable_START (5)
#define SOC_MUDP_LINK_INTR_MASK_int_link_fatal_error_enable_END (5)
#define SOC_MUDP_LINK_INTR_MASK_int_static_done_enable_START (6)
#define SOC_MUDP_LINK_INTR_MASK_int_static_done_enable_END (6)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_mode_force_chg_enable_START (16)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_mode_force_chg_enable_END (16)
#define SOC_MUDP_LINK_INTR_MASK_int_max_rx_deskew_timeout_enable_START (17)
#define SOC_MUDP_LINK_INTR_MASK_int_max_rx_deskew_timeout_enable_END (17)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_deskew_done_enable_START (18)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_deskew_done_enable_END (18)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_event_ack_timeout_enable_START (19)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_event_ack_timeout_enable_END (19)
#define SOC_MUDP_LINK_INTR_MASK_int_tl_errr_flag_unexpect_apid_enable_START (20)
#define SOC_MUDP_LINK_INTR_MASK_int_tl_errr_flag_unexpect_apid_enable_END (20)
#define SOC_MUDP_LINK_INTR_MASK_int_mod2cfg_sleep_entry_flag_enable_START (21)
#define SOC_MUDP_LINK_INTR_MASK_int_mod2cfg_sleep_entry_flag_enable_END (21)
#define SOC_MUDP_LINK_INTR_MASK_int_mod2cfg_sleep_exit_flag_enable_START (22)
#define SOC_MUDP_LINK_INTR_MASK_int_mod2cfg_sleep_exit_flag_enable_END (22)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_align_det_timeout_flag_enable_START (23)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_align_det_timeout_flag_enable_END (23)
#define SOC_MUDP_LINK_INTR_MASK_int_fec_buf_wr_over_rd_flag_enable_START (24)
#define SOC_MUDP_LINK_INTR_MASK_int_fec_buf_wr_over_rd_flag_enable_END (24)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_fec_dec2_err_uncor_flag_enable_START (25)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_fec_dec2_err_uncor_flag_enable_END (25)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_fec_dec1_err_uncor_flag_enable_START (26)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_fec_dec1_err_uncor_flag_enable_END (26)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_fec_dec0_err_uncor_flag_enable_START (27)
#define SOC_MUDP_LINK_INTR_MASK_int_mac_rx_fec_dec0_err_uncor_flag_enable_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_omc_done : 1;
        unsigned int int_cmd_read_done : 1;
        unsigned int int_cmd_write_done : 1;
        unsigned int int_cmd_timeout : 1;
        unsigned int int_link_lost : 1;
        unsigned int int_link_fatal_error : 1;
        unsigned int int_static_done : 1;
        unsigned int reserved_0 : 9;
        unsigned int int_mac_mode_force_chg : 1;
        unsigned int int_max_rx_deskew_timeout : 1;
        unsigned int int_mac_rx_deskew_done : 1;
        unsigned int int_mac_event_ack_timeout : 1;
        unsigned int int_tl_errr_flag_unexpect_apid : 1;
        unsigned int int_mod2cfg_sleep_entry_flag : 1;
        unsigned int int_mod2cfg_sleep_exit_flag : 1;
        unsigned int int_mac_rx_align_det_timeout_flag : 1;
        unsigned int int_fec_buf_wr_over_rd_flag : 1;
        unsigned int int_mac_rx_fec_dec2_err_uncor_flag : 1;
        unsigned int int_mac_rx_fec_dec1_err_uncor_flag : 1;
        unsigned int int_mac_rx_fec_dec0_err_uncor_flag : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MUDP_LINK_INT_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_INT_STATUS_int_omc_done_START (0)
#define SOC_MUDP_LINK_INT_STATUS_int_omc_done_END (0)
#define SOC_MUDP_LINK_INT_STATUS_int_cmd_read_done_START (1)
#define SOC_MUDP_LINK_INT_STATUS_int_cmd_read_done_END (1)
#define SOC_MUDP_LINK_INT_STATUS_int_cmd_write_done_START (2)
#define SOC_MUDP_LINK_INT_STATUS_int_cmd_write_done_END (2)
#define SOC_MUDP_LINK_INT_STATUS_int_cmd_timeout_START (3)
#define SOC_MUDP_LINK_INT_STATUS_int_cmd_timeout_END (3)
#define SOC_MUDP_LINK_INT_STATUS_int_link_lost_START (4)
#define SOC_MUDP_LINK_INT_STATUS_int_link_lost_END (4)
#define SOC_MUDP_LINK_INT_STATUS_int_link_fatal_error_START (5)
#define SOC_MUDP_LINK_INT_STATUS_int_link_fatal_error_END (5)
#define SOC_MUDP_LINK_INT_STATUS_int_static_done_START (6)
#define SOC_MUDP_LINK_INT_STATUS_int_static_done_END (6)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_mode_force_chg_START (16)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_mode_force_chg_END (16)
#define SOC_MUDP_LINK_INT_STATUS_int_max_rx_deskew_timeout_START (17)
#define SOC_MUDP_LINK_INT_STATUS_int_max_rx_deskew_timeout_END (17)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_deskew_done_START (18)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_deskew_done_END (18)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_event_ack_timeout_START (19)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_event_ack_timeout_END (19)
#define SOC_MUDP_LINK_INT_STATUS_int_tl_errr_flag_unexpect_apid_START (20)
#define SOC_MUDP_LINK_INT_STATUS_int_tl_errr_flag_unexpect_apid_END (20)
#define SOC_MUDP_LINK_INT_STATUS_int_mod2cfg_sleep_entry_flag_START (21)
#define SOC_MUDP_LINK_INT_STATUS_int_mod2cfg_sleep_entry_flag_END (21)
#define SOC_MUDP_LINK_INT_STATUS_int_mod2cfg_sleep_exit_flag_START (22)
#define SOC_MUDP_LINK_INT_STATUS_int_mod2cfg_sleep_exit_flag_END (22)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_align_det_timeout_flag_START (23)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_align_det_timeout_flag_END (23)
#define SOC_MUDP_LINK_INT_STATUS_int_fec_buf_wr_over_rd_flag_START (24)
#define SOC_MUDP_LINK_INT_STATUS_int_fec_buf_wr_over_rd_flag_END (24)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_fec_dec2_err_uncor_flag_START (25)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_fec_dec2_err_uncor_flag_END (25)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_fec_dec1_err_uncor_flag_START (26)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_fec_dec1_err_uncor_flag_END (26)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_fec_dec0_err_uncor_flag_START (27)
#define SOC_MUDP_LINK_INT_STATUS_int_mac_rx_fec_dec0_err_uncor_flag_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_src_gen_pattern_start : 1;
        unsigned int tst_src_gen_pattern_mode : 1;
        unsigned int tst_src_gen_pattern_length : 14;
        unsigned int tst_src_gen_pattern_gap : 8;
        unsigned int tst_src_gen_pattern_group_num : 8;
    } reg;
} SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_UNION;
#endif
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_start_START (0)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_start_END (0)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_mode_START (1)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_mode_END (1)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_length_START (2)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_length_END (15)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_gap_START (16)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_gap_END (23)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_group_num_START (24)
#define SOC_MUDP_LINK_TL_TST_SRC_GEN_PT_tst_src_gen_pattern_group_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_chk_pattern_start : 1;
        unsigned int tst_dst_chk_pattern_mode : 1;
        unsigned int tst_dst_chk_pattern_length : 14;
        unsigned int reserved : 8;
        unsigned int tst_dst_chk_pattern_group_num : 8;
    } reg;
} SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_UNION;
#endif
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_start_START (0)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_start_END (0)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_mode_START (1)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_mode_END (1)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_length_START (2)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_length_END (15)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_group_num_START (24)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_PT_tst_dst_chk_pattern_group_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_chk_rst : 1;
        unsigned int reserved_0 : 1;
        unsigned int tst_dst_chk_rst_err_loc : 14;
        unsigned int reserved_1 : 8;
        unsigned int tst_dst_chk_rst_err_group_num : 8;
    } reg;
} SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_UNION;
#endif
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_tst_dst_chk_rst_START (0)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_tst_dst_chk_rst_END (0)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_tst_dst_chk_rst_err_loc_START (2)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_tst_dst_chk_rst_err_loc_END (15)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_tst_dst_chk_rst_err_group_num_START (24)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_RST_tst_dst_chk_rst_err_group_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_chk_rst_err_data : 32;
    } reg;
} SOC_MUDP_LINK_TL_TEST_DST_CHK_ERR_DATA_UNION;
#endif
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_ERR_DATA_tst_dst_chk_rst_err_data_START (0)
#define SOC_MUDP_LINK_TL_TEST_DST_CHK_ERR_DATA_tst_dst_chk_rst_err_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int cmd_write_address : 16;
        unsigned int reserved_1 : 2;
        unsigned int cmd_write_length : 3;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_MUDP_LINK_TL_RW_CMD_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_CMD_cmd_write_address_START (8)
#define SOC_MUDP_LINK_TL_RW_CMD_cmd_write_address_END (23)
#define SOC_MUDP_LINK_TL_RW_CMD_cmd_write_length_START (26)
#define SOC_MUDP_LINK_TL_RW_CMD_cmd_write_length_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data0 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT0_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT0_cmd_write_data0_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT0_cmd_write_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data1 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT1_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT1_cmd_write_data1_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT1_cmd_write_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data2 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT2_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT2_cmd_write_data2_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT2_cmd_write_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data3 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT3_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT3_cmd_write_data3_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT3_cmd_write_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data4 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT4_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT4_cmd_write_data4_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT4_cmd_write_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data5 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT5_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT5_cmd_write_data5_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT5_cmd_write_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data6 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT6_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT6_cmd_write_data6_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT6_cmd_write_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_data7 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RW_DAT7_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_DAT7_cmd_write_data7_START (0)
#define SOC_MUDP_LINK_TL_RW_DAT7_cmd_write_data7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_write_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_LINK_TL_RW_RST_UNION;
#endif
#define SOC_MUDP_LINK_TL_RW_RST_cmd_write_status_START (0)
#define SOC_MUDP_LINK_TL_RW_RST_cmd_write_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int cmd_read_address : 16;
        unsigned int reserved_1 : 2;
        unsigned int cmd_read_length : 3;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_MUDP_LINK_TL_RR_CMD_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_CMD_cmd_read_address_START (8)
#define SOC_MUDP_LINK_TL_RR_CMD_cmd_read_address_END (23)
#define SOC_MUDP_LINK_TL_RR_CMD_cmd_read_length_START (26)
#define SOC_MUDP_LINK_TL_RR_CMD_cmd_read_length_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data0 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT0_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT0_cmd_read_data0_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT0_cmd_read_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data1 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT1_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT1_cmd_read_data1_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT1_cmd_read_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data2 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT2_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT2_cmd_read_data2_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT2_cmd_read_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data3 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT3_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT3_cmd_read_data3_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT3_cmd_read_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data4 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT4_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT4_cmd_read_data4_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT4_cmd_read_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data5 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT5_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT5_cmd_read_data5_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT5_cmd_read_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data6 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT6_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT6_cmd_read_data6_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT6_cmd_read_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_data7 : 32;
    } reg;
} SOC_MUDP_LINK_TL_RR_DAT7_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_DAT7_cmd_read_data7_START (0)
#define SOC_MUDP_LINK_TL_RR_DAT7_cmd_read_data7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_read_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_LINK_TL_RR_RST_UNION;
#endif
#define SOC_MUDP_LINK_TL_RR_RST_cmd_read_status_START (0)
#define SOC_MUDP_LINK_TL_RR_RST_cmd_read_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_lost_128b_err_thre : 4;
        unsigned int reserved_0 : 12;
        unsigned int mac_rx_128b_err_mode : 2;
        unsigned int mac_rx_128b_seq_msk : 1;
        unsigned int reserved_1 : 5;
        unsigned int seq_128b_det_num : 4;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_MUDP_LINK_MAC_RX_128B_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_link_lost_128b_err_thre_START (0)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_link_lost_128b_err_thre_END (3)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_mac_rx_128b_err_mode_START (16)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_mac_rx_128b_err_mode_END (17)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_mac_rx_128b_seq_msk_START (18)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_mac_rx_128b_seq_msk_END (18)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_seq_128b_det_num_START (24)
#define SOC_MUDP_LINK_MAC_RX_128B_CTRL_seq_128b_det_num_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_lost_8b_err_thre : 16;
        unsigned int mac_rx_8b_err_mode : 2;
        unsigned int mac_rx_8b_seq_msk : 1;
        unsigned int reserved : 5;
        unsigned int seq_8b_det_num : 4;
        unsigned int ts_refclk_div : 4;
    } reg;
} SOC_MUDP_LINK_MAC_RX_8B_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_link_lost_8b_err_thre_START (0)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_link_lost_8b_err_thre_END (15)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_mac_rx_8b_err_mode_START (16)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_mac_rx_8b_err_mode_END (17)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_mac_rx_8b_seq_msk_START (18)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_mac_rx_8b_seq_msk_END (18)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_seq_8b_det_num_START (24)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_seq_8b_det_num_END (27)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_ts_refclk_div_START (28)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_ts_refclk_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int macrx_8b_err_clr_time : 16;
    } reg;
} SOC_MUDP_LINK_MAC_RX_8B_CTRL_1_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_1_macrx_8b_err_clr_time_START (16)
#define SOC_MUDP_LINK_MAC_RX_8B_CTRL_1_macrx_8b_err_clr_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_scramble_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_LINK_MAC_RX_SCRAMBLE_EN_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_SCRAMBLE_EN_rx_scramble_en_START (0)
#define SOC_MUDP_LINK_MAC_RX_SCRAMBLE_EN_rx_scramble_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int macrx_align_comp_diff_thre : 8;
        unsigned int macrx_align_det_timeout : 12;
        unsigned int macrx_align_det_timeout_en : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_MUDP_LINK_MAC_RX_ALIGN_DET_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_macrx_align_comp_diff_thre_START (0)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_macrx_align_comp_diff_thre_END (7)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_macrx_align_det_timeout_START (8)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_macrx_align_det_timeout_END (19)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_macrx_align_det_timeout_en_START (20)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_macrx_align_det_timeout_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int macrx_align_seq_128b : 32;
    } reg;
} SOC_MUDP_LINK_MAC_RX_ALIGN_DET_1_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_1_macrx_align_seq_128b_START (0)
#define SOC_MUDP_LINK_MAC_RX_ALIGN_DET_1_macrx_align_seq_128b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int macrx_eob_comp_diff_8b_thre : 4;
        unsigned int macrx_eob_comp32_diff_thre : 6;
        unsigned int macrx_eob_comp64_diff_thre : 7;
        unsigned int macrx_eob_comp_diff_thre : 8;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_LINK_MAC_RX_EOB_DET_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp_diff_8b_thre_START (0)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp_diff_8b_thre_END (3)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp32_diff_thre_START (4)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp32_diff_thre_END (9)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp64_diff_thre_START (10)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp64_diff_thre_END (16)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp_diff_thre_START (17)
#define SOC_MUDP_LINK_MAC_RX_EOB_DET_macrx_eob_comp_diff_thre_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int macrx_deskew_timeout_en : 1;
        unsigned int macrx_deskew_timeout : 4;
        unsigned int reserved : 27;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DESKEW_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DESKEW_CTRL_macrx_deskew_timeout_en_START (0)
#define SOC_MUDP_LINK_MAC_RX_DESKEW_CTRL_macrx_deskew_timeout_en_END (0)
#define SOC_MUDP_LINK_MAC_RX_DESKEW_CTRL_macrx_deskew_timeout_START (1)
#define SOC_MUDP_LINK_MAC_RX_DESKEW_CTRL_macrx_deskew_timeout_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_event_ack_timeout : 12;
        unsigned int rx_event_ack_timeout_en : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_MUDP_LINK_MAC_RX_PHY_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_PHY_CTRL_rx_event_ack_timeout_START (0)
#define SOC_MUDP_LINK_MAC_RX_PHY_CTRL_rx_event_ack_timeout_END (11)
#define SOC_MUDP_LINK_MAC_RX_PHY_CTRL_rx_event_ack_timeout_en_START (12)
#define SOC_MUDP_LINK_MAC_RX_PHY_CTRL_rx_event_ack_timeout_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int mac_rx_pre_coding_en : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_MUDP_LINK_MAC_RX_FEC_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_FEC_CTRL_mac_rx_pre_coding_en_START (4)
#define SOC_MUDP_LINK_MAC_RX_FEC_CTRL_mac_rx_pre_coding_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_phy_ctrl_test_sel : 4;
        unsigned int dbg_rx_fec_cor_sel : 3;
        unsigned int reserved : 25;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DEBUG_SEL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DEBUG_SEL_rx_phy_ctrl_test_sel_START (0)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_SEL_rx_phy_ctrl_test_sel_END (3)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_SEL_dbg_rx_fec_cor_sel_START (4)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_SEL_dbg_rx_fec_cor_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_macrx_fec_err_cnt : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DEBUG_FEC_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DEBUG_FEC_dbg_macrx_fec_err_cnt_START (0)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_FEC_dbg_macrx_fec_err_cnt_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_macrx_align : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_0_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_0_dbg_macrx_align_START (0)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_0_dbg_macrx_align_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_rx_phy_ctrl_0 : 16;
        unsigned int dbg_mac_rx_afifo_0 : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_0_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_0_dbg_mac_rx_phy_ctrl_0_START (0)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_0_dbg_mac_rx_phy_ctrl_0_END (15)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_0_dbg_mac_rx_afifo_0_START (16)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_0_dbg_mac_rx_afifo_0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_rx_phy_ctrl_1 : 16;
        unsigned int dbg_mac_rx_afifo_1 : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_1_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_1_dbg_mac_rx_phy_ctrl_1_START (0)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_1_dbg_mac_rx_phy_ctrl_1_END (15)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_1_dbg_mac_rx_afifo_1_START (16)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_1_dbg_mac_rx_afifo_1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_rx_phy_ctrl_2 : 16;
        unsigned int dbg_mac_rx_afifo_2 : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_2_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_2_dbg_mac_rx_phy_ctrl_2_START (0)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_2_dbg_mac_rx_phy_ctrl_2_END (15)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_2_dbg_mac_rx_afifo_2_START (16)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_1_2_dbg_mac_rx_afifo_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_rx_fec_buf : 16;
        unsigned int dbg_mac_rx_fec_correct : 16;
    } reg;
} SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_2_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_2_dbg_mac_rx_fec_buf_START (0)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_2_dbg_mac_rx_fec_buf_END (15)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_2_dbg_mac_rx_fec_correct_START (16)
#define SOC_MUDP_LINK_MAC_RX_DEBUG_BUS_2_dbg_mac_rx_fec_correct_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lane0_link_lost : 1;
        unsigned int lane1_link_lost : 1;
        unsigned int lane2_link_lost : 1;
        unsigned int lane0_phy_tx_timeout : 1;
        unsigned int lane1_phy_tx_timeout : 1;
        unsigned int lane2_phy_tx_timeout : 1;
        unsigned int lane0_phy_rx_timeout : 1;
        unsigned int lane1_phy_rx_timeout : 1;
        unsigned int lane2_phy_rx_timeout : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MUDP_LINK_MAC_RX_LINK_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane0_link_lost_START (0)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane0_link_lost_END (0)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane1_link_lost_START (1)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane1_link_lost_END (1)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane2_link_lost_START (2)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane2_link_lost_END (2)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane0_phy_tx_timeout_START (3)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane0_phy_tx_timeout_END (3)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane1_phy_tx_timeout_START (4)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane1_phy_tx_timeout_END (4)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane2_phy_tx_timeout_START (5)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane2_phy_tx_timeout_END (5)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane0_phy_rx_timeout_START (6)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane0_phy_rx_timeout_END (6)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane1_phy_rx_timeout_START (7)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane1_phy_rx_timeout_END (7)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane2_phy_rx_timeout_START (8)
#define SOC_MUDP_LINK_MAC_RX_LINK_STATUS_lane2_phy_rx_timeout_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_idle_symbol_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_LINK_MAC_TX_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_CTRL_mac_tx_idle_symbol_num_START (0)
#define SOC_MUDP_LINK_MAC_TX_CTRL_mac_tx_idle_symbol_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_event_ack_timeout : 12;
        unsigned int tx_event_ack_timeout_en : 1;
        unsigned int tx_state_timeout_en : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_LINK_MAC_TX_PHY_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_tx_event_ack_timeout_START (0)
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_tx_event_ack_timeout_END (11)
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_tx_event_ack_timeout_en_START (12)
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_tx_event_ack_timeout_en_END (12)
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_tx_state_timeout_en_START (13)
#define SOC_MUDP_LINK_MAC_TX_PHY_CTRL_tx_state_timeout_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_ts_seq_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_LINK_MAC_TX_TS_SEQ_REQ_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_TS_SEQ_REQ_tx_ts_seq_req_START (0)
#define SOC_MUDP_LINK_MAC_TX_TS_SEQ_REQ_tx_ts_seq_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_scramble_en : 1;
        unsigned int tx_sync_data_8b : 10;
        unsigned int reserved : 21;
    } reg;
} SOC_MUDP_LINK_MAC_TX_SCRAMBLE_EN_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_SCRAMBLE_EN_tx_scramble_en_START (0)
#define SOC_MUDP_LINK_MAC_TX_SCRAMBLE_EN_tx_scramble_en_END (0)
#define SOC_MUDP_LINK_MAC_TX_SCRAMBLE_EN_tx_sync_data_8b_START (1)
#define SOC_MUDP_LINK_MAC_TX_SCRAMBLE_EN_tx_sync_data_8b_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_dbg_fec_sel : 4;
        unsigned int tx_pre_coding_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MUDP_LINK_MAC_TX_FEC_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_FEC_CTRL_tx_dbg_fec_sel_START (0)
#define SOC_MUDP_LINK_MAC_TX_FEC_CTRL_tx_dbg_fec_sel_END (3)
#define SOC_MUDP_LINK_MAC_TX_FEC_CTRL_tx_pre_coding_en_START (4)
#define SOC_MUDP_LINK_MAC_TX_FEC_CTRL_tx_pre_coding_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_event_status : 16;
        unsigned int tx_event_ack_timeout_flg : 1;
        unsigned int tx_phy_timeout_fail : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_LINK_MAC_TX_EVENT_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_EVENT_tx_event_status_START (0)
#define SOC_MUDP_LINK_MAC_TX_EVENT_tx_event_status_END (15)
#define SOC_MUDP_LINK_MAC_TX_EVENT_tx_event_ack_timeout_flg_START (16)
#define SOC_MUDP_LINK_MAC_TX_EVENT_tx_event_ack_timeout_flg_END (16)
#define SOC_MUDP_LINK_MAC_TX_EVENT_tx_phy_timeout_fail_START (17)
#define SOC_MUDP_LINK_MAC_TX_EVENT_tx_phy_timeout_fail_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_phy_eq : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_PHY_EQ_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_EQ_mac_tx_dbg_phy_eq_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_EQ_mac_tx_dbg_phy_eq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_phy_int_ctrl_status_0 : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_0_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_0_mac_tx_dbg_phy_int_ctrl_status_0_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_0_mac_tx_dbg_phy_int_ctrl_status_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_phy_int_ctrl_status_1 : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_1_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_1_mac_tx_dbg_phy_int_ctrl_status_1_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_1_mac_tx_dbg_phy_int_ctrl_status_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_phy_int_ctrl_status_2 : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_2_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_2_mac_tx_dbg_phy_int_ctrl_status_2_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_STATUS_2_mac_tx_dbg_phy_int_ctrl_status_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_phy_int_ctrl_event : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_EVENT_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_EVENT_mac_tx_dbg_phy_int_ctrl_event_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_PHY_INT_CTRL_EVENT_mac_tx_dbg_phy_int_ctrl_event_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_burst_seq_ins_0 : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_0_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_0_mac_tx_dbg_burst_seq_ins_0_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_0_mac_tx_dbg_burst_seq_ins_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_burst_seq_ins_1 : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_1_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_1_mac_tx_dbg_burst_seq_ins_1_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_1_mac_tx_dbg_burst_seq_ins_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_dbg_burst_seq_ins_2 : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_2_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_2_mac_tx_dbg_burst_seq_ins_2_START (0)
#define SOC_MUDP_LINK_MAC_TX_DBG_BURST_SEQ_INS_2_mac_tx_dbg_burst_seq_ins_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_sync_data_128b : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_SYNC_DATA_128B_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_SYNC_DATA_128B_mac_tx_sync_data_128b_START (0)
#define SOC_MUDP_LINK_MAC_TX_SYNC_DATA_128B_mac_tx_sync_data_128b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mac_tx_align_data_128b : 32;
    } reg;
} SOC_MUDP_LINK_MAC_TX_ALIGN_DATA_128B_UNION;
#endif
#define SOC_MUDP_LINK_MAC_TX_ALIGN_DATA_128B_mac_tx_align_data_128b_START (0)
#define SOC_MUDP_LINK_MAC_TX_ALIGN_DATA_128B_mac_tx_align_data_128b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_wait_timeout : 12;
        unsigned int rx_wait_timeout : 12;
        unsigned int standby_before_burst : 1;
        unsigned int phy_ready_det_en : 1;
        unsigned int host_device_mode : 1;
        unsigned int host_device_mode_en : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_MUDP_LINK_MC_CTRL0_UNION;
#endif
#define SOC_MUDP_LINK_MC_CTRL0_tx_wait_timeout_START (0)
#define SOC_MUDP_LINK_MC_CTRL0_tx_wait_timeout_END (11)
#define SOC_MUDP_LINK_MC_CTRL0_rx_wait_timeout_START (12)
#define SOC_MUDP_LINK_MC_CTRL0_rx_wait_timeout_END (23)
#define SOC_MUDP_LINK_MC_CTRL0_standby_before_burst_START (24)
#define SOC_MUDP_LINK_MC_CTRL0_standby_before_burst_END (24)
#define SOC_MUDP_LINK_MC_CTRL0_phy_ready_det_en_START (25)
#define SOC_MUDP_LINK_MC_CTRL0_phy_ready_det_en_END (25)
#define SOC_MUDP_LINK_MC_CTRL0_host_device_mode_START (26)
#define SOC_MUDP_LINK_MC_CTRL0_host_device_mode_END (26)
#define SOC_MUDP_LINK_MC_CTRL0_host_device_mode_en_START (27)
#define SOC_MUDP_LINK_MC_CTRL0_host_device_mode_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_state : 3;
        unsigned int reserved_0 : 1;
        unsigned int half_rx_state : 3;
        unsigned int reserved_1 : 1;
        unsigned int half_tx_state : 3;
        unsigned int reserved_2 : 1;
        unsigned int simplex_state : 3;
        unsigned int reserved_3 : 17;
    } reg;
} SOC_MUDP_LINK_MC_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_MC_STATUS_sleep_state_START (0)
#define SOC_MUDP_LINK_MC_STATUS_sleep_state_END (2)
#define SOC_MUDP_LINK_MC_STATUS_half_rx_state_START (4)
#define SOC_MUDP_LINK_MC_STATUS_half_rx_state_END (6)
#define SOC_MUDP_LINK_MC_STATUS_half_tx_state_START (8)
#define SOC_MUDP_LINK_MC_STATUS_half_tx_state_END (10)
#define SOC_MUDP_LINK_MC_STATUS_simplex_state_START (12)
#define SOC_MUDP_LINK_MC_STATUS_simplex_state_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_status : 1;
        unsigned int sleep_phy_status : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_LINK_MC_STATUS_1_UNION;
#endif
#define SOC_MUDP_LINK_MC_STATUS_1_sleep_status_START (0)
#define SOC_MUDP_LINK_MC_STATUS_1_sleep_status_END (0)
#define SOC_MUDP_LINK_MC_STATUS_1_sleep_phy_status_START (1)
#define SOC_MUDP_LINK_MC_STATUS_1_sleep_phy_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int macrx_phy_status : 2;
        unsigned int mactx_phy_status : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_MUDP_LINK_MC_STATUS_2_UNION;
#endif
#define SOC_MUDP_LINK_MC_STATUS_2_macrx_phy_status_START (0)
#define SOC_MUDP_LINK_MC_STATUS_2_macrx_phy_status_END (1)
#define SOC_MUDP_LINK_MC_STATUS_2_mactx_phy_status_START (2)
#define SOC_MUDP_LINK_MC_STATUS_2_mactx_phy_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mod_dbg_sel : 4;
        unsigned int mod_test_sel : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_LINK_MC_DEBUG_SEL0_UNION;
#endif
#define SOC_MUDP_LINK_MC_DEBUG_SEL0_mod_dbg_sel_START (0)
#define SOC_MUDP_LINK_MC_DEBUG_SEL0_mod_dbg_sel_END (3)
#define SOC_MUDP_LINK_MC_DEBUG_SEL0_mod_test_sel_START (4)
#define SOC_MUDP_LINK_MC_DEBUG_SEL0_mod_test_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mod : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_LINK_MC_DEBUG_BUS_UNION;
#endif
#define SOC_MUDP_LINK_MC_DEBUG_BUS_dbg_mod_START (0)
#define SOC_MUDP_LINK_MC_DEBUG_BUS_dbg_mod_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stall_idle_trans_period : 8;
        unsigned int stall_idle_trans_en : 1;
        unsigned int phyevent_rxclk_gate_mod_req_en : 1;
        unsigned int phyevent_txclk_gate_mod_req_en : 1;
        unsigned int phy_ini_cfg_done : 1;
        unsigned int reserved : 4;
        unsigned int simplex_stall_det_wait_cnt : 8;
        unsigned int half_sleep_wakeup_stall_wait_cnt : 8;
    } reg;
} SOC_MUDP_LINK_MC_CTRL1_UNION;
#endif
#define SOC_MUDP_LINK_MC_CTRL1_stall_idle_trans_period_START (0)
#define SOC_MUDP_LINK_MC_CTRL1_stall_idle_trans_period_END (7)
#define SOC_MUDP_LINK_MC_CTRL1_stall_idle_trans_en_START (8)
#define SOC_MUDP_LINK_MC_CTRL1_stall_idle_trans_en_END (8)
#define SOC_MUDP_LINK_MC_CTRL1_phyevent_rxclk_gate_mod_req_en_START (9)
#define SOC_MUDP_LINK_MC_CTRL1_phyevent_rxclk_gate_mod_req_en_END (9)
#define SOC_MUDP_LINK_MC_CTRL1_phyevent_txclk_gate_mod_req_en_START (10)
#define SOC_MUDP_LINK_MC_CTRL1_phyevent_txclk_gate_mod_req_en_END (10)
#define SOC_MUDP_LINK_MC_CTRL1_phy_ini_cfg_done_START (11)
#define SOC_MUDP_LINK_MC_CTRL1_phy_ini_cfg_done_END (11)
#define SOC_MUDP_LINK_MC_CTRL1_simplex_stall_det_wait_cnt_START (16)
#define SOC_MUDP_LINK_MC_CTRL1_simplex_stall_det_wait_cnt_END (23)
#define SOC_MUDP_LINK_MC_CTRL1_half_sleep_wakeup_stall_wait_cnt_START (24)
#define SOC_MUDP_LINK_MC_CTRL1_half_sleep_wakeup_stall_wait_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dl_err_num : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_LINK_DL_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_DL_CTRL_dl_err_num_START (0)
#define SOC_MUDP_LINK_DL_CTRL_dl_err_num_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dl_tx_idle : 1;
        unsigned int dl_rx_idle : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_LINK_DL_IDLE_UNION;
#endif
#define SOC_MUDP_LINK_DL_IDLE_dl_tx_idle_START (0)
#define SOC_MUDP_LINK_DL_IDLE_dl_tx_idle_END (0)
#define SOC_MUDP_LINK_DL_IDLE_dl_rx_idle_START (1)
#define SOC_MUDP_LINK_DL_IDLE_dl_rx_idle_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tl_tx_idle : 1;
        unsigned int tl_rx_idle : 1;
        unsigned int tl_init_done : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_LINK_TL_IDLE_UNION;
#endif
#define SOC_MUDP_LINK_TL_IDLE_tl_tx_idle_START (0)
#define SOC_MUDP_LINK_TL_IDLE_tl_tx_idle_END (0)
#define SOC_MUDP_LINK_TL_IDLE_tl_rx_idle_START (1)
#define SOC_MUDP_LINK_TL_IDLE_tl_rx_idle_END (1)
#define SOC_MUDP_LINK_TL_IDLE_tl_init_done_START (2)
#define SOC_MUDP_LINK_TL_IDLE_tl_init_done_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apid_pix : 6;
        unsigned int reserved_0 : 2;
        unsigned int apid_cch : 6;
        unsigned int reserved_1 : 2;
        unsigned int apid_rac : 6;
        unsigned int reserved_2 : 2;
        unsigned int apid_test_gen : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_MUDP_LINK_TL_AP_ID_CTRL_0_UNION;
#endif
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_pix_START (0)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_pix_END (5)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_cch_START (8)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_cch_END (13)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_rac_START (16)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_rac_END (21)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_test_gen_START (24)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_0_apid_test_gen_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ap2_apid : 6;
        unsigned int reserved_0 : 2;
        unsigned int ap3_apid : 6;
        unsigned int reserved_1 : 2;
        unsigned int tl_ap_id_err : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_MUDP_LINK_TL_AP_ID_CTRL_1_UNION;
#endif
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_ap2_apid_START (0)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_ap2_apid_END (5)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_ap3_apid_START (8)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_ap3_apid_END (13)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_tl_ap_id_err_START (16)
#define SOC_MUDP_LINK_TL_AP_ID_CTRL_1_tl_ap_id_err_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_timeout_th : 8;
        unsigned int tst_dst_timeout_en : 1;
        unsigned int tst_dst_timeout_st : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_UNION;
#endif
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_tst_dst_timeout_th_START (0)
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_tst_dst_timeout_th_END (7)
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_tst_dst_timeout_en_START (8)
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_tst_dst_timeout_en_END (8)
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_tst_dst_timeout_st_START (9)
#define SOC_MUDP_LINK_TL_TST_DST_TIMEOUT_tst_dst_timeout_st_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_cur_loc : 8;
        unsigned int tst_dst_cur_group : 14;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_LINK_TL_TST_DST_DEBUG_UNION;
#endif
#define SOC_MUDP_LINK_TL_TST_DST_DEBUG_tst_dst_cur_loc_START (0)
#define SOC_MUDP_LINK_TL_TST_DST_DEBUG_tst_dst_cur_loc_END (7)
#define SOC_MUDP_LINK_TL_TST_DST_DEBUG_tst_dst_cur_group_START (8)
#define SOC_MUDP_LINK_TL_TST_DST_DEBUG_tst_dst_cur_group_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rac_timeout_cnt_thd : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_LINK_TL_RAC_TIMEOUT_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_TL_RAC_TIMEOUT_CTRL_rac_timeout_cnt_thd_START (0)
#define SOC_MUDP_LINK_TL_RAC_TIMEOUT_CTRL_rac_timeout_cnt_thd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rac_period_mode : 2;
        unsigned int rac_period_err_cnt_thd : 3;
        unsigned int rac_period_err_to_ap_enable : 1;
        unsigned int rac_period_err_to_omc_enable : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_mode_START (0)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_mode_END (1)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_err_cnt_thd_START (2)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_err_cnt_thd_END (4)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_err_to_ap_enable_START (5)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_err_to_ap_enable_END (5)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_err_to_omc_enable_START (6)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_CTRL_rac_period_err_to_omc_enable_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int period_cnt_thd : 16;
        unsigned int period_wait_time : 16;
    } reg;
} SOC_MUDP_LINK_TL_RAC_PERIOD_TIME_UNION;
#endif
#define SOC_MUDP_LINK_TL_RAC_PERIOD_TIME_period_cnt_thd_START (0)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_TIME_period_cnt_thd_END (15)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_TIME_period_wait_time_START (16)
#define SOC_MUDP_LINK_TL_RAC_PERIOD_TIME_period_wait_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ap_arb_mode : 6;
        unsigned int arb_mode : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MUDP_LINK_TL_ARB_MODE_UNION;
#endif
#define SOC_MUDP_LINK_TL_ARB_MODE_ap_arb_mode_START (0)
#define SOC_MUDP_LINK_TL_ARB_MODE_ap_arb_mode_END (5)
#define SOC_MUDP_LINK_TL_ARB_MODE_arb_mode_START (6)
#define SOC_MUDP_LINK_TL_ARB_MODE_arb_mode_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_modem_en : 2;
        unsigned int omc_modem_swing_en : 1;
        unsigned int omc_modem_fec_en : 1;
        unsigned int omc_modem_sleep_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MUDP_LINK_TL_MODEM_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_en_START (0)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_en_END (1)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_swing_en_START (2)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_swing_en_END (2)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_fec_en_START (3)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_fec_en_END (3)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_sleep_en_START (4)
#define SOC_MUDP_LINK_TL_MODEM_CTRL_omc_modem_sleep_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_connect : 1;
        unsigned int link_transf_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_LINK_LINK_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_LINK_STATUS_link_connect_START (0)
#define SOC_MUDP_LINK_LINK_STATUS_link_connect_END (0)
#define SOC_MUDP_LINK_LINK_STATUS_link_transf_en_START (1)
#define SOC_MUDP_LINK_LINK_STATUS_link_transf_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_en_ap_mask : 8;
        unsigned int sleep_sw_en : 1;
        unsigned int sleep_en_sel : 1;
        unsigned int auto_sleep_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 8;
        unsigned int sleep_en_status : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_en_ap_mask_START (0)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_en_ap_mask_END (7)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_sw_en_START (8)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_sw_en_END (8)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_en_sel_START (9)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_en_sel_END (9)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_auto_sleep_en_START (10)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_auto_sleep_en_END (10)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_en_status_START (24)
#define SOC_MUDP_LINK_CFG_SLEEP_EN_CTRL_sleep_en_status_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_fsm_timeout_th : 22;
        unsigned int omc_fsm_timeout_en : 1;
        unsigned int omc_txrx_setting_sw_en : 1;
        unsigned int pulse_100ns_cycle : 8;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_CTRL_0_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_omc_fsm_timeout_th_START (0)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_omc_fsm_timeout_th_END (21)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_omc_fsm_timeout_en_START (22)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_omc_fsm_timeout_en_END (22)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_omc_txrx_setting_sw_en_START (23)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_omc_txrx_setting_sw_en_END (23)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_pulse_100ns_cycle_START (24)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_0_pulse_100ns_cycle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_chg_timeout : 16;
        unsigned int omc_stall2cfg_delay : 16;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_CTRL_1_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_CTRL_1_omc_chg_timeout_START (0)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_1_omc_chg_timeout_END (15)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_1_omc_stall2cfg_delay_START (16)
#define SOC_MUDP_LINK_CFG_OMC_CTRL_1_omc_stall2cfg_delay_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_cur_status : 4;
        unsigned int omc_eq_cur_status : 4;
        unsigned int omc_fsm_timeout : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_STATUS_omc_cur_status_START (0)
#define SOC_MUDP_LINK_CFG_OMC_STATUS_omc_cur_status_END (3)
#define SOC_MUDP_LINK_CFG_OMC_STATUS_omc_eq_cur_status_START (4)
#define SOC_MUDP_LINK_CFG_OMC_STATUS_omc_eq_cur_status_END (7)
#define SOC_MUDP_LINK_CFG_OMC_STATUS_omc_fsm_timeout_START (8)
#define SOC_MUDP_LINK_CFG_OMC_STATUS_omc_fsm_timeout_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_apb_slv0 : 32;
    } reg;
} SOC_MUDP_LINK_CFG_APB_ARB_DBG_0_UNION;
#endif
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_0_dbg_info_apb_slv0_START (0)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_0_dbg_info_apb_slv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_apb_slv1 : 32;
    } reg;
} SOC_MUDP_LINK_CFG_APB_ARB_DBG_1_UNION;
#endif
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_1_dbg_info_apb_slv1_START (0)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_1_dbg_info_apb_slv1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_apb_slv0 : 32;
    } reg;
} SOC_MUDP_LINK_CFG_APB_ARB_DBG_2_UNION;
#endif
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_2_dbg_data_apb_slv0_START (0)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_2_dbg_data_apb_slv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_apb_slv1 : 32;
    } reg;
} SOC_MUDP_LINK_CFG_APB_ARB_DBG_3_UNION;
#endif
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_3_dbg_data_apb_slv1_START (0)
#define SOC_MUDP_LINK_CFG_APB_ARB_DBG_3_dbg_data_apb_slv1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_tx_pre_cfg : 32;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_PRE_CFG_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_PRE_CFG_omc_tx_pre_cfg_START (0)
#define SOC_MUDP_LINK_CFG_OMC_PRE_CFG_omc_tx_pre_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_rx_eq_cfg : 32;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_EQ_CFG_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_EQ_CFG_omc_rx_eq_cfg_START (0)
#define SOC_MUDP_LINK_CFG_OMC_EQ_CFG_omc_rx_eq_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chg_initial_mode_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_LINK_CFG_CHG_INITIAL_MODE_EN_UNION;
#endif
#define SOC_MUDP_LINK_CFG_CHG_INITIAL_MODE_EN_chg_initial_mode_en_START (0)
#define SOC_MUDP_LINK_CFG_CHG_INITIAL_MODE_EN_chg_initial_mode_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_tx_pre_config : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_TX_PRE_CFG_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_TX_PRE_CFG_omc_tx_pre_config_START (0)
#define SOC_MUDP_LINK_CFG_OMC_TX_PRE_CFG_omc_tx_pre_config_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_rx_eq_config : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_RX_PRE_CFG_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_RX_PRE_CFG_omc_rx_eq_config_START (0)
#define SOC_MUDP_LINK_CFG_OMC_RX_PRE_CFG_omc_rx_eq_config_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_tx_rate : 8;
        unsigned int reserved_0 : 2;
        unsigned int omc_tx_fec_en : 1;
        unsigned int omc_tx_code_mode : 1;
        unsigned int omc_tx_lane_num : 4;
        unsigned int omc_tx_swing_level : 4;
        unsigned int omc_tx_swing_level_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int omc_tx_preset_level : 4;
        unsigned int omc_tx_preset_level_en : 1;
        unsigned int omc_tx_skew_en : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_TX_SETTING_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_rate_START (0)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_rate_END (7)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_fec_en_START (10)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_fec_en_END (10)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_code_mode_START (11)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_code_mode_END (11)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_lane_num_START (12)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_lane_num_END (15)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_swing_level_START (16)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_swing_level_END (19)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_swing_level_en_START (20)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_swing_level_en_END (20)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_preset_level_START (24)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_preset_level_END (27)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_preset_level_en_START (28)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_preset_level_en_END (28)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_skew_en_START (29)
#define SOC_MUDP_LINK_CFG_OMC_TX_SETTING_omc_tx_skew_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int omc_rx_rate : 8;
        unsigned int reserved_0 : 2;
        unsigned int omc_rx_fec_en : 1;
        unsigned int omc_rx_code_mode : 1;
        unsigned int omc_rx_lane_num : 4;
        unsigned int omc_rx_swing_level_req : 4;
        unsigned int omc_rx_swing_req_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int omc_rx_preset_level_req : 4;
        unsigned int omc_rx_preset_req_en : 1;
        unsigned int omc_rx_skew_en : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MUDP_LINK_CFG_OMC_RX_SETTING_UNION;
#endif
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_rate_START (0)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_rate_END (7)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_fec_en_START (10)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_fec_en_END (10)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_code_mode_START (11)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_code_mode_END (11)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_lane_num_START (12)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_lane_num_END (15)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_swing_level_req_START (16)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_swing_level_req_END (19)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_swing_req_en_START (20)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_swing_req_en_END (20)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_preset_level_req_START (24)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_preset_level_req_END (27)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_preset_req_en_START (28)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_preset_req_en_END (28)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_skew_en_START (29)
#define SOC_MUDP_LINK_CFG_OMC_RX_SETTING_omc_rx_skew_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_link_tx_n : 1;
        unsigned int rst_link_rx_n : 1;
        unsigned int rst_mode_ctrl_n : 1;
        unsigned int rst_fec_enc_n : 1;
        unsigned int rst_fec_dec_n : 1;
        unsigned int rst_omc_n : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_LINK_CRG_RST_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_link_tx_n_START (0)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_link_tx_n_END (0)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_link_rx_n_START (1)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_link_rx_n_END (1)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_mode_ctrl_n_START (2)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_mode_ctrl_n_END (2)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_fec_enc_n_START (3)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_fec_enc_n_END (3)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_fec_dec_n_START (4)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_fec_dec_n_END (4)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_omc_n_START (5)
#define SOC_MUDP_LINK_CRG_RST_CTRL_rst_omc_n_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_sel_tx_link : 3;
        unsigned int clk_sel_tx_fec : 1;
        unsigned int clk_sel_tx_8b : 1;
        unsigned int clk_sel_tx_128b : 1;
        unsigned int clk_sel_rx_link : 3;
        unsigned int clk_sel_rx_fec : 1;
        unsigned int clk_sel_rx_8b : 1;
        unsigned int clk_sel_rx_128b : 1;
        unsigned int clk_sel_omc : 1;
        unsigned int clk_sel_event : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_LINK_CRG_CLK_SEL_UNION;
#endif
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_link_START (0)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_link_END (2)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_fec_START (3)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_fec_END (3)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_8b_START (4)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_8b_END (4)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_128b_START (5)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_tx_128b_END (5)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_link_START (6)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_link_END (8)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_fec_START (9)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_fec_END (9)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_8b_START (10)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_8b_END (10)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_128b_START (11)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_rx_128b_END (11)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_omc_START (12)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_omc_END (12)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_event_START (13)
#define SOC_MUDP_LINK_CRG_CLK_SEL_clk_sel_event_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int auto_clk_en_tx_link : 3;
        unsigned int auto_clk_en_tx_fec : 1;
        unsigned int auto_clk_en_tx_8b : 1;
        unsigned int auto_clk_en_tx_128b : 1;
        unsigned int auto_clk_en_rx_link : 3;
        unsigned int auto_clk_en_rx_fec : 1;
        unsigned int auto_clk_en_rx_8b : 1;
        unsigned int auto_clk_en_rx_128b : 1;
        unsigned int auto_clk_en_omc : 1;
        unsigned int auto_clk_en_event : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_LINK_CRG_CLK_AUTO_EN_UNION;
#endif
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_link_START (0)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_link_END (2)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_fec_START (3)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_fec_END (3)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_8b_START (4)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_8b_END (4)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_128b_START (5)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_tx_128b_END (5)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_link_START (6)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_link_END (8)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_fec_START (9)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_fec_END (9)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_8b_START (10)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_8b_END (10)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_128b_START (11)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_rx_128b_END (11)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_omc_START (12)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_omc_END (12)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_event_START (13)
#define SOC_MUDP_LINK_CRG_CLK_AUTO_EN_auto_clk_en_event_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_status_tx_link : 3;
        unsigned int clk_status_tx_fec : 3;
        unsigned int clk_status_tx_8b : 3;
        unsigned int clk_status_tx_128b : 3;
        unsigned int clk_status_rx_link : 3;
        unsigned int clk_status_rx_fec : 3;
        unsigned int clk_status_rx_8b : 3;
        unsigned int clk_status_rx_128b : 3;
        unsigned int clk_status_event : 1;
        unsigned int clk_status_omc : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_LINK_CRG_CLK_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_link_START (0)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_link_END (2)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_fec_START (3)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_fec_END (5)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_8b_START (6)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_8b_END (8)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_128b_START (9)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_tx_128b_END (11)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_link_START (12)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_link_END (14)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_fec_START (15)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_fec_END (17)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_8b_START (18)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_8b_END (20)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_128b_START (21)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_rx_128b_END (23)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_event_START (24)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_event_END (24)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_omc_START (25)
#define SOC_MUDP_LINK_CRG_CLK_STATUS_clk_status_omc_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mclk2rx_fec_div_force : 5;
        unsigned int mclk2rx_fec_div_force_en : 1;
        unsigned int mclk2rx_div_force : 5;
        unsigned int mclk2rx_div_force_en : 1;
        unsigned int mclk2tx_div_force : 5;
        unsigned int mclk2tx_div_force_en : 1;
        unsigned int cfg_ck_off_sc_sync : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_LINK_CRG_DIV_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_fec_div_force_START (0)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_fec_div_force_END (4)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_fec_div_force_en_START (5)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_fec_div_force_en_END (5)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_div_force_START (6)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_div_force_END (10)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_div_force_en_START (11)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2rx_div_force_en_END (11)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2tx_div_force_START (12)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2tx_div_force_END (16)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2tx_div_force_en_START (17)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_mclk2tx_div_force_en_END (17)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_cfg_ck_off_sc_sync_START (18)
#define SOC_MUDP_LINK_CRG_DIV_CTRL_cfg_ck_off_sc_sync_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mclk2rx_fec_div : 5;
        unsigned int swdone_mclk2rx_fec_div : 1;
        unsigned int mclk2rx_div : 5;
        unsigned int swdone_mclk2rx_div : 1;
        unsigned int mclk2tx_div : 5;
        unsigned int swdone_mclk2tx_div : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_LINK_CRG_DIV_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_CRG_DIV_STATUS_mclk2rx_fec_div_START (0)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_mclk2rx_fec_div_END (4)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_swdone_mclk2rx_fec_div_START (5)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_swdone_mclk2rx_fec_div_END (5)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_mclk2rx_div_START (6)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_mclk2rx_div_END (10)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_swdone_mclk2rx_div_START (11)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_swdone_mclk2rx_div_END (11)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_mclk2tx_div_START (12)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_mclk2tx_div_END (16)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_swdone_mclk2tx_div_START (17)
#define SOC_MUDP_LINK_CRG_DIV_STATUS_swdone_mclk2tx_div_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_linktx_in_sys_exp_num : 16;
        unsigned int gt_linkrx_in_sys_exp_num : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_LINK_CRG_LINK_GT_EXP_UNION;
#endif
#define SOC_MUDP_LINK_CRG_LINK_GT_EXP_gt_linktx_in_sys_exp_num_START (0)
#define SOC_MUDP_LINK_CRG_LINK_GT_EXP_gt_linktx_in_sys_exp_num_END (15)
#define SOC_MUDP_LINK_CRG_LINK_GT_EXP_gt_linkrx_in_sys_exp_num_START (16)
#define SOC_MUDP_LINK_CRG_LINK_GT_EXP_gt_linkrx_in_sys_exp_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_en : 1;
        unsigned int dfx_stat_cnt0_en : 1;
        unsigned int dfx_stat_cnt1_en : 1;
        unsigned int dfx_stat_cnt2_en : 1;
        unsigned int dfx_stat_cnt3_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MUDP_LINK_DFX_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_en_START (0)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_en_END (0)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt0_en_START (1)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt0_en_END (1)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt1_en_START (2)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt1_en_END (2)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt2_en_START (3)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt2_en_END (3)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt3_en_START (4)
#define SOC_MUDP_LINK_DFX_CTRL_dfx_stat_cnt3_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt0_sel : 8;
        unsigned int dfx_stat_cnt1_sel : 8;
        unsigned int dfx_stat_cnt2_sel : 8;
        unsigned int dfx_stat_cnt3_sel : 8;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_SEL_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt0_sel_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt0_sel_END (7)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt1_sel_START (8)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt1_sel_END (15)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt2_sel_START (16)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt2_sel_END (23)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt3_sel_START (24)
#define SOC_MUDP_LINK_DFX_STATISTICS_SEL_dfx_stat_cnt3_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt0_init : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT0_SET_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_SET_dfx_stat_cnt0_init_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_SET_dfx_stat_cnt0_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt1_init : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT1_SET_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_SET_dfx_stat_cnt1_init_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_SET_dfx_stat_cnt1_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt2_init : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT2_SET_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_SET_dfx_stat_cnt2_init_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_SET_dfx_stat_cnt2_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt3_init : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT3_SET_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_SET_dfx_stat_cnt3_init_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_SET_dfx_stat_cnt3_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt0 : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT0_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_dfx_stat_cnt0_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT0_dfx_stat_cnt0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt1 : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT1_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_dfx_stat_cnt1_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT1_dfx_stat_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt2 : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT2_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_dfx_stat_cnt2_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT2_dfx_stat_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_stat_cnt3 : 32;
    } reg;
} SOC_MUDP_LINK_DFX_STATISTICS_CNT3_UNION;
#endif
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_dfx_stat_cnt3_START (0)
#define SOC_MUDP_LINK_DFX_STATISTICS_CNT3_dfx_stat_cnt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_tx_phy_seq_ins : 32;
    } reg;
} SOC_MUDP_LINK_DFX_MAC_TX_PHY_SEQ_INS_DBG_UNION;
#endif
#define SOC_MUDP_LINK_DFX_MAC_TX_PHY_SEQ_INS_DBG_dbg_mac_tx_phy_seq_ins_START (0)
#define SOC_MUDP_LINK_DFX_MAC_TX_PHY_SEQ_INS_DBG_dbg_mac_tx_phy_seq_ins_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_rx_sym_err_cnt : 16;
        unsigned int dbg_mac_rx_phy_event_status : 16;
    } reg;
} SOC_MUDP_LINK_DFX_MAC_RX_DBG0_UNION;
#endif
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG0_dbg_mac_rx_sym_err_cnt_START (0)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG0_dbg_mac_rx_sym_err_cnt_END (15)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG0_dbg_mac_rx_phy_event_status_START (16)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG0_dbg_mac_rx_phy_event_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rac_dbg_curstate : 5;
        unsigned int rac_dbg_period_err_cnt : 3;
        unsigned int rac_dbg_cmdreq : 4;
        unsigned int rac_dbg_curcmd : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_UNION;
#endif
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_curstate_START (0)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_curstate_END (4)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_period_err_cnt_START (5)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_period_err_cnt_END (7)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_cmdreq_START (8)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_cmdreq_END (11)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_curcmd_START (12)
#define SOC_MUDP_LINK_DFX_TL_RAC_DEBUG_0_rac_dbg_curcmd_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_tp_sel : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_LINK_TEST_POINT_CTRL_UNION;
#endif
#define SOC_MUDP_LINK_TEST_POINT_CTRL_cfg_tp_sel_START (0)
#define SOC_MUDP_LINK_TEST_POINT_CTRL_cfg_tp_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_tp : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_LINK_TEST_POINT_UNION;
#endif
#define SOC_MUDP_LINK_TEST_POINT_link_tp_START (0)
#define SOC_MUDP_LINK_TEST_POINT_link_tp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_rx_phy_ctrl_state : 3;
        unsigned int reserved_0 : 1;
        unsigned int dbg_mac_rx_align_err_cnt : 8;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_MUDP_LINK_DFX_MAC_RX_DBG1_UNION;
#endif
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG1_dbg_mac_rx_phy_ctrl_state_START (0)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG1_dbg_mac_rx_phy_ctrl_state_END (2)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG1_dbg_mac_rx_align_err_cnt_START (4)
#define SOC_MUDP_LINK_DFX_MAC_RX_DBG1_dbg_mac_rx_align_err_cnt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mac_tx_fec : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_MUDP_LINK_DFX_MAC_FEC_DBG_UNION;
#endif
#define SOC_MUDP_LINK_DFX_MAC_FEC_DBG_dbg_mac_tx_fec_START (0)
#define SOC_MUDP_LINK_DFX_MAC_FEC_DBG_dbg_mac_tx_fec_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mudp_ldm_active : 1;
        unsigned int dbg_mudp_ldm_stall : 1;
        unsigned int dbg_mudp_ldm_sleep : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_LINK_DFX_LDM_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_DFX_LDM_STATUS_dbg_mudp_ldm_active_START (0)
#define SOC_MUDP_LINK_DFX_LDM_STATUS_dbg_mudp_ldm_active_END (0)
#define SOC_MUDP_LINK_DFX_LDM_STATUS_dbg_mudp_ldm_stall_START (1)
#define SOC_MUDP_LINK_DFX_LDM_STATUS_dbg_mudp_ldm_stall_END (1)
#define SOC_MUDP_LINK_DFX_LDM_STATUS_dbg_mudp_ldm_sleep_START (2)
#define SOC_MUDP_LINK_DFX_LDM_STATUS_dbg_mudp_ldm_sleep_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_ap0_to_link_valid : 1;
        unsigned int dbg_ap0_to_link_ready : 1;
        unsigned int dbg_ap1_to_link_valid : 1;
        unsigned int dbg_ap1_to_link_ready : 1;
        unsigned int dbg_a2t0_valid : 1;
        unsigned int dbg_a2t0_ready : 1;
        unsigned int dbg_a2t1_valid : 1;
        unsigned int dbg_a2t1_ready : 1;
        unsigned int dbg_t12dl_valid : 1;
        unsigned int dbg_t12dl_ready : 1;
        unsigned int dbg_dl2mactx_valid : 1;
        unsigned int dbg_dl2mactx_ready : 1;
        unsigned int dbg_link_to_ap0_valid : 1;
        unsigned int dbg_link_to_ap0_ready : 1;
        unsigned int dbg_link_to_ap1_valid : 1;
        unsigned int dbg_link_to_ap1_ready : 1;
        unsigned int dbg_rac_valid : 1;
        unsigned int dbg_rac_ready : 1;
        unsigned int dbg_tg_valid : 1;
        unsigned int dbg_tg_ready : 1;
        unsigned int dbg_arb2hdrins_valid : 1;
        unsigned int dbg_arb2hdrins_ready : 1;
        unsigned int dbg_hdrrmv2dis_valid : 1;
        unsigned int dbg_macrx2dl_valid : 1;
        unsigned int dbg_dl2tl_valid : 1;
        unsigned int dbg_tc_valid : 1;
        unsigned int dbg_rar_valid : 1;
        unsigned int dbg_t2a0_valid : 1;
        unsigned int dbg_t2a1_valid : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_MUDP_LINK_DFX_VALID_READY_STATUS_UNION;
#endif
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap0_to_link_valid_START (0)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap0_to_link_valid_END (0)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap0_to_link_ready_START (1)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap0_to_link_ready_END (1)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap1_to_link_valid_START (2)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap1_to_link_valid_END (2)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap1_to_link_ready_START (3)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_ap1_to_link_ready_END (3)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t0_valid_START (4)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t0_valid_END (4)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t0_ready_START (5)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t0_ready_END (5)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t1_valid_START (6)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t1_valid_END (6)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t1_ready_START (7)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_a2t1_ready_END (7)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t12dl_valid_START (8)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t12dl_valid_END (8)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t12dl_ready_START (9)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t12dl_ready_END (9)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_dl2mactx_valid_START (10)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_dl2mactx_valid_END (10)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_dl2mactx_ready_START (11)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_dl2mactx_ready_END (11)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap0_valid_START (12)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap0_valid_END (12)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap0_ready_START (13)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap0_ready_END (13)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap1_valid_START (14)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap1_valid_END (14)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap1_ready_START (15)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_link_to_ap1_ready_END (15)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_rac_valid_START (16)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_rac_valid_END (16)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_rac_ready_START (17)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_rac_ready_END (17)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_tg_valid_START (18)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_tg_valid_END (18)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_tg_ready_START (19)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_tg_ready_END (19)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_arb2hdrins_valid_START (20)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_arb2hdrins_valid_END (20)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_arb2hdrins_ready_START (21)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_arb2hdrins_ready_END (21)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_hdrrmv2dis_valid_START (22)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_hdrrmv2dis_valid_END (22)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_macrx2dl_valid_START (23)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_macrx2dl_valid_END (23)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_dl2tl_valid_START (24)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_dl2tl_valid_END (24)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_tc_valid_START (25)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_tc_valid_END (25)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_rar_valid_START (26)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_rar_valid_END (26)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t2a0_valid_START (27)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t2a0_valid_END (27)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t2a1_valid_START (28)
#define SOC_MUDP_LINK_DFX_VALID_READY_STATUS_dbg_t2a1_valid_END (28)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
