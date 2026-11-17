#ifndef __SOC_HIPHYIO_INTERFACE_H__
#define __SOC_HIPHYIO_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIPHYIO_Version_ADDR(base) (base)
#define SOC_HIPHYIO_INT_enable_ADDR(base) ((base) + 0x0004UL)
#define SOC_HIPHYIO_INT_status_ADDR(base) ((base) + 0x0008UL)
#define SOC_HIPHYIO_OPTION_MODE_TX_ADDR(base) ((base) + 0x000CUL)
#define SOC_HIPHYIO_OPTION_MODE_RX_ADDR(base) ((base) + 0x0010UL)
#define SOC_HIPHYIO_OPTION_MODE_CHANGE_ADDR(base) ((base) + 0x0014UL)
#define SOC_HIPHYIO_RATE_CHANGE_VOTE_ADDR(base) ((base) + 0x0018UL)
#define SOC_HIPHYIO_RATE_CHANGE_VOTE_STATUS_ADDR(base) ((base) + 0x001CUL)
#define SOC_HIPHYIO_RATE_STATUS_ADDR(base) ((base) + 0x0020UL)
#define SOC_HIPHYIO_RATE_CHANGE_ADDR(base) ((base) + 0x0024UL)
#define SOC_HIPHYIO_AUTO_ECC_MODE_ADDR(base) ((base) + 0x0028UL)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_ADDR(base) ((base) + 0x002CUL)
#define SOC_HIPHYIO_SE_MODE_PERIOD_SET_ADDR(base) ((base) + 0x0030UL)
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_ADDR(base) ((base) + 0x0034UL)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_ADDR(base) ((base) + 0x0038UL)
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_ADDR(base) ((base) + 0x003CUL)
#define SOC_HIPHYIO_SLP_EXIT_SW_TRG_ADDR(base) ((base) + 0x0040UL)
#define SOC_HIPHYIO_SLP_VOTE_EN_ADDR(base) ((base) + 0x0044UL)
#define SOC_HIPHYIO_SLP_VOTE_ADDR(base) ((base) + 0x0048UL)
#define SOC_HIPHYIO_SLP_VOTE_STATUS_ADDR(base) ((base) + 0x004CUL)
#define SOC_HIPHYIO_TEST_COMMON_ADDR(base) ((base) + 0x0050UL)
#define SOC_HIPHYIO_TST_SRC_ADDR(base) ((base) + 0x0054UL)
#define SOC_HIPHYIO_TST_DST_ADDR(base) ((base) + 0x0058UL)
#define SOC_HIPHYIO_TST_DST_STATUS0_ADDR(base) ((base) + 0x005CUL)
#define SOC_HIPHYIO_TST_DST_STATUS1_ADDR(base) ((base) + 0x0060UL)
#define SOC_HIPHYIO_TST_DST_STATUS_2_ADDR(base) ((base) + 0x0064UL)
#define SOC_HIPHYIO_TST_DST_STATUS_3_ADDR(base) ((base) + 0x0068UL)
#define SOC_HIPHYIO_AXI_INF_SET_ADDR(base) ((base) + 0x006CUL)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_ADDR(base) ((base) + 0x0070UL)
#define SOC_HIPHYIO_AXI_FIX_WADDR_ADDR(base,ip_fifo_num) (base) + 0x0074 + 8 * (ip_fifo_num)
#define SOC_HIPHYIO_AXI_FIX_RADDR_ADDR(base,ip_fifo_num) (base) + 0x0078 + 8 * (ip_fifo_num)
#define SOC_HIPHYIO_MID_MAP_0_ADDR(base) ((base) + 0x0174UL)
#define SOC_HIPHYIO_MID_MAP_1_ADDR(base) ((base) + 0x0178UL)
#define SOC_HIPHYIO_MID_MAP_2_ADDR(base) ((base) + 0x017CUL)
#define SOC_HIPHYIO_MID_MAP_3_ADDR(base) ((base) + 0x0180UL)
#define SOC_HIPHYIO_IDLE_LENGTH_CTRL_ADDR(base) ((base) + 0x0184UL)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_ADDR(base) ((base) + 0x01A4UL)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_ADDR(base) ((base) + 0x0200UL)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_ADDR(base) ((base) + 0x0204UL)
#define SOC_HIPHYIO_DESKEW_SET_ADDR(base) ((base) + 0x0208UL)
#define SOC_HIPHYIO_Powor_status_ADDR(base) ((base) + 0x020CUL)
#define SOC_HIPHYIO_PERF_MONITOR_GLB_ADDR(base) ((base) + 0x0210UL)
#define SOC_HIPHYIO_PERF_MONITOR_EVENT_ADDR(base,perf_num) (base) + 0x0214 + 8 * (perf_num)
#define SOC_HIPHYIO_PERF_MONITOR_TIME_ADDR(base,perf_num) (base) + 0x0218 + 8 * (perf_num)
#define SOC_HIPHYIO_LINKT_TX_ADDR(base) ((base) + 0x0234UL)
#define SOC_HIPHYIO_LINKT_TX_1_ADDR(base) ((base) + 0x0238UL)
#define SOC_HIPHYIO_LINK_RX_DELAY_ADDR(base) ((base) + 0x023CUL)
#define SOC_HIPHYIO_LINK_RX_BYPASS_ADDR(base) ((base) + 0x0240UL)
#define SOC_HIPHYIO_LINK_RX_STATUS_ADDR(base) ((base) + 0x0244UL)
#define SOC_HIPHYIO_LSS_DLY_ADDR(base) ((base) + 0x0248UL)
#define SOC_HIPHYIO_LSS_TX_DLY_1_0_ADDR(base) ((base) + 0x024CUL)
#define SOC_HIPHYIO_LSS_TX_DLY_3_2_ADDR(base) ((base) + 0x0250UL)
#define SOC_HIPHYIO_LSS_TX_DLY_5_4_ADDR(base) ((base) + 0x0254UL)
#define SOC_HIPHYIO_LSS_TX_DLY_7_6_ADDR(base) ((base) + 0x0258UL)
#define SOC_HIPHYIO_LSS_RX_DLY_1_0_ADDR(base) ((base) + 0x025CUL)
#define SOC_HIPHYIO_LSS_RX_DLY_3_2_ADDR(base) ((base) + 0x0260UL)
#define SOC_HIPHYIO_LSS_RX_DLY_5_4_ADDR(base) ((base) + 0x0264UL)
#define SOC_HIPHYIO_LSS_RX_DLY_7_6_ADDR(base) ((base) + 0x0268UL)
#define SOC_HIPHYIO_LSS_RX_STATUS1_ADDR(base) ((base) + 0x026CUL)
#define SOC_HIPHYIO_TX_PRBS_CUST_PATT_ADDR(base,lane_num) (base) + 0x0270 + 4 * (lane_num)
#define SOC_HIPHYIO_TX_PRBS_CFG_ADDR(base,lane_num) (base) + 0x0278 + 4 * (lane_num)
#define SOC_HIPHYIO_RX_OSPD_ADDR(base,lane_num) (base) + 0x0280 + 4 * (lane_num)
#define SOC_HIPHYIO_RX_PRBS_ADDR(base,lane_num) (base) + 0x0288 + 4 * (lane_num)
#define SOC_HIPHYIO_PCS_CRG_ADDR(base) ((base) + 0x290UL)
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_0_ADDR(base) ((base) + 0x0294UL)
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_1_ADDR(base) ((base) + 0x0298UL)
#define SOC_HIPHYIO_PKR_RT_BYPASS_ADDR(base) ((base) + 0x029CUL)
#define SOC_HIPHYIO_PKT_RT_ERR_HEAD_ADDR(base) ((base) + 0x02A0UL)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ADDR(base) ((base) + 0x02A4UL)
#define SOC_HIPHYIO_I2S_CFG0_ADDR(base,i2s_num) (base) + 0x02A8 + 0xC * (i2s_num)
#define SOC_HIPHYIO_I2S_CFG1_ADDR(base,i2s_num) (base) + 0x02AC + 0xC * (i2s_num)
#define SOC_HIPHYIO_I2S_CFG2_ADDR(base,i2s_num) (base) + 0x02B0 + 0xC * (i2s_num)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_ADDR(base) ((base) + 0x02D4UL)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_ADDR(base) ((base) + 0x02D8UL)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_ADDR(base) ((base) + 0x02DCUL)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_0_ADDR(base) ((base) + 0x02E0UL)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_1_ADDR(base) ((base) + 0x02E4UL)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_2_ADDR(base) ((base) + 0x02E8UL)
#define SOC_HIPHYIO_INTR_I2S_PKT_DEC_ERR_INFO_0_ADDR(base) ((base) + 0x02ECUL)
#define SOC_HIPHYIO_DFX_I2S_TX_PKT_GEN_ADDR(base) ((base) + 0x02F0UL)
#define SOC_HIPHYIO_DFX_I2S_RX_PKT_DEC_ADDR(base) ((base) + 0x02F4UL)
#define SOC_HIPHYIO_DFX_I2S_TX_CTRL_INTF_ADDR(base,i2s_num) (base) + 0x02F8 + 8 * (i2s_num)
#define SOC_HIPHYIO_DFX_I2S_RX_CTRL_INTF_ADDR(base,i2s_num) (base) + 0x02FC + 8 * (i2s_num)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ADDR(base) ((base) + 0x030CUL)
#define SOC_HIPHYIO_SPI_CFG0_ADDR(base,spi_num) (base) + 0x0310 + 0xC * (spi_num)
#define SOC_HIPHYIO_SPI_CFG1_ADDR(base,spi_num) (base) + 0x0314 + 0xC * (spi_num)
#define SOC_HIPHYIO_SPI_CFG2_ADDR(base,spi_num) (base) + 0x0318 + 0xC * (spi_num)
#define SOC_HIPHYIO_SPI_INTR_STATUS0_ADDR(base) ((base) + 0x0370UL)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE0_ADDR(base) ((base) + 0x0374UL)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE0_ADDR(base) ((base) + 0x0378UL)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_ADDR(base) ((base) + 0x037CUL)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_ADDR(base) ((base) + 0x0380UL)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_ADDR(base) ((base) + 0x0384UL)
#define SOC_HIPHYIO_SPI_INTR_STATUS2_ADDR(base) ((base) + 0x0388UL)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE2_ADDR(base) ((base) + 0x038CUL)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE2_ADDR(base) ((base) + 0x0390UL)
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_0_ADDR(base) ((base) + 0x0394UL)
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_1_ADDR(base) ((base) + 0x0398UL)
#define SOC_HIPHYIO_INTR_SPI_PKT_DEC_ERR_INFO_0_ADDR(base) ((base) + 0x039CUL)
#define SOC_HIPHYIO_DFX_SPI_TX_PKT_GEN_ADDR(base) ((base) + 0x03A0UL)
#define SOC_HIPHYIO_DFX_SPI_RX_PKT_DEC_ADDR(base) ((base) + 0x03A4UL)
#define SOC_HIPHYIO_DFX_SPI_TX_CTRL_INTF_ADDR(base,spi_num) (base) + 0x03A8 + 8 * (spi_num)
#define SOC_HIPHYIO_DFX_SPI_RX_CTRL_INTF_ADDR(base,spi_num) (base) + 0x03AC + 8 * (spi_num)
#define SOC_HIPHYIO_ECC_Err_status_ADDR(base) ((base) + 0x03E8UL)
#define SOC_HIPHYIO_PKT_ERR_STATUS_ADDR(base) ((base) + 0x03ECUL)
#define SOC_HIPHYIO_DESKEW_ERR_STATUS_ADDR(base) ((base) + 0x03F0UL)
#define SOC_HIPHYIO_LANE_ERR_STATUS_ADDR(base,lane_num) (base) + 0x03F4 + 4 * (lane_num)
#define SOC_HIPHYIO_DECODE_ERR_STATUS_ADDR(base) ((base) + 0x03FCUL)
#define SOC_HIPHYIO_PHY_CFG_ADDR(base) ((base) + 0x0400UL)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_ADDR(base) ((base) + 0x0404UL)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_ADDR(base) ((base) + 0x0408UL)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_ADDR(base) ((base) + 0x040CUL)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_ADDR(base) ((base) + 0x0410UL)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_ADDR(base) ((base) + 0x0414UL)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_ADDR(base) ((base) + 0x0418UL)
#define SOC_HIPHYIO_TE_CTRL_ADDR(base) ((base) + 0x041CUL)
#define SOC_HIPHYIO_PHY_SLEEP_CTRL_ADDR(base) ((base) + 0x0420UL)
#define SOC_HIPHYIO_PHY_SLEEP_INT_ADDR(base) ((base) + 0x0424UL)
#define SOC_HIPHYIO_CLK_MUX_ADDR(base) ((base) + 0x0428UL)
#define SOC_HIPHYIO_PHY_DS_COMMON_ADDR(base) ((base) + 0x042CUL)
#define SOC_HIPHYIO_PHY_DS_TX_0_ADDR(base) ((base) + 0x0430UL)
#define SOC_HIPHYIO_PHY_DS_TX_1_ADDR(base) ((base) + 0x0434UL)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_ADDR(base) ((base) + 0x0438UL)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_ADDR(base) ((base) + 0x043CUL)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_ADDR(base) ((base) + 0x0440UL)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_ADDR(base) ((base) + 0x0444UL)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_ADDR(base) ((base) + 0x0448UL)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_ADDR(base) ((base) + 0x044CUL)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_ADDR(base) ((base) + 0x0450UL)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_ADDR(base) ((base) + 0x0454UL)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_ADDR(base) ((base) + 0x0458UL)
#define SOC_HIPHYIO_PHY_STALL_DET_READ_ADDR(base) ((base) + 0x045CUL)
#define SOC_HIPHYIO_SE_CLK_CAL_START_ADDR(base) ((base) + 0x0460UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_ADDR(base) ((base) + 0x0464UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_ADDR(base) ((base) + 0x0468UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_ADDR(base) ((base) + 0x046CUL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_ADDR(base) ((base) + 0x0470UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_ADDR(base) ((base) + 0x0474UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_ADDR(base) ((base) + 0x0478UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_ADDR(base) ((base) + 0x047CUL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_1_ADDR(base) ((base) + 0x0480UL)
#define SOC_HIPHYIO_SE_CLK_CAL_START_L1_ADDR(base) ((base) + 0x0484UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_L1_ADDR(base) ((base) + 0x0488UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_L1_ADDR(base) ((base) + 0x048CUL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_L1_ADDR(base) ((base) + 0x0490UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_L1_ADDR(base) ((base) + 0x0494UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_L1_ADDR(base) ((base) + 0x0498UL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_L1_ADDR(base) ((base) + 0x049CUL)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_L1_ADDR(base) ((base) + 0x04A0UL)
#define SOC_HIPHYIO_RATE_CHANGE_CTRL_ADDR(base) ((base) + 0x04A4UL)
#define SOC_HIPHYIO_CRG_GT_CTRL_ADDR(base) ((base) + 0x0500UL)
#define SOC_HIPHYIO_CRG_GT_STATUS_ADDR(base) ((base) + 0x0504UL)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_ADDR(base) ((base) + 0x0508UL)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_ADDR(base) ((base) + 0x050CUL)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_ADDR(base) ((base) + 0x0510UL)
#define SOC_HIPHYIO_CRG_DIV_STATUS_ADDR(base) ((base) + 0x0514UL)
#define SOC_HIPHYIO_CRG_RST_CTRL_ADDR(base) ((base) + 0x0518UL)
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_ADDR(base) ((base) + 0x051CUL)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_ADDR(base) ((base) + 0x0520UL)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_ADDR(base) ((base) + 0x0524UL)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_ADDR(base) ((base) + 0x0528UL)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_ADDR(base) ((base) + 0x052CUL)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_ADDR(base) ((base) + 0x530UL)
#define SOC_HIPHYIO_FNPLL_CFG0_ADDR(base) ((base) + 0x534UL)
#define SOC_HIPHYIO_FNPLL_CFG1_ADDR(base) ((base) + 0x538UL)
#define SOC_HIPHYIO_FNPLL_CFG2_ADDR(base) ((base) + 0x53CUL)
#define SOC_HIPHYIO_FNPLL_CFG3_ADDR(base) ((base) + 0x540UL)
#define SOC_HIPHYIO_FNPLL_STATE0_ADDR(base) ((base) + 0x544UL)
#define SOC_HIPHYIO_FNPLL_STATE1_ADDR(base) ((base) + 0x548UL)
#define SOC_HIPHYIO_ULPPLL_GT_CFG_ADDR(base) ((base) + 0x0560UL)
#define SOC_HIPHYIO_ULPPLL_CFG0_ADDR(base) ((base) + 0x0564UL)
#define SOC_HIPHYIO_ULPPLL_CFG1_ADDR(base) ((base) + 0x0568UL)
#define SOC_HIPHYIO_ULPPLL_CFG2_ADDR(base) ((base) + 0x056CUL)
#define SOC_HIPHYIO_ULPPLL_CFG3_ADDR(base) ((base) + 0x0570UL)
#define SOC_HIPHYIO_ULPPLL_CFG4_ADDR(base) ((base) + 0x0574UL)
#define SOC_HIPHYIO_ULPPLL_CFG5_ADDR(base) ((base) + 0x0578UL)
#define SOC_HIPHYIO_ULPPLL_CFG6_ADDR(base) ((base) + 0x057CUL)
#define SOC_HIPHYIO_ULPPLL_CFG7_ADDR(base) ((base) + 0x0580UL)
#define SOC_HIPHYIO_ULPPLL_CFG8_ADDR(base) ((base) + 0x0584UL)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ADDR(base) ((base) + 0x0588UL)
#define SOC_HIPHYIO_ULPPLL_STATE0_ADDR(base) ((base) + 0x058CUL)
#define SOC_HIPHYIO_ULPPLL_STATE1_ADDR(base) ((base) + 0x0590UL)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_ADDR(base) ((base) + 0x0594UL)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_ADDR(base) ((base) + 0x0598UL)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_ADDR(base) ((base) + 0x059CUL)
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_ADDR(base) ((base) + 0x05A0UL)
#define SOC_HIPHYIO_RSV_CTRL0_ADDR(base) ((base) + 0x600UL)
#define SOC_HIPHYIO_RSV_CTRL1_ADDR(base) ((base) + 0x604UL)
#define SOC_HIPHYIO_RSV_CTRL2_ADDR(base) ((base) + 0x608UL)
#define SOC_HIPHYIO_RSV_CTRL3_ADDR(base) ((base) + 0x60cUL)
#define SOC_HIPHYIO_DFX_COUNTER_0_ADDR(base) ((base) + 0x0610UL)
#define SOC_HIPHYIO_DFX_COUNTER_1_ADDR(base) ((base) + 0x0614UL)
#define SOC_HIPHYIO_DFX_COUNTER_2_ADDR(base) ((base) + 0x0618UL)
#define SOC_HIPHYIO_DFX_COUNTER_3_ADDR(base) ((base) + 0x061CUL)
#define SOC_HIPHYIO_LSS_RX_STATUS2_ADDR(base) ((base) + 0x0620UL)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_ADDR(base) ((base) + 0x0624UL)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_ADDR(base) ((base) + 0x0628UL)
#define SOC_HIPHYIO_DFX_VALID_READY_ADDR(base) ((base) + 0x062CUL)
#define SOC_HIPHYIO_DFX_TX_ARB_ADDR(base) ((base) + 0x0630UL)
#define SOC_HIPHYIO_TESTPOINT_SEL_ADDR(base) ((base) + 0x0634UL)
#define SOC_HIPHYIO_ARB_FATAL_BLOCK_EN_ADDR(base) ((base) + 0x0638UL)
#define SOC_HIPHYIO_DFX_CTRL_STATE_ADDR(base) ((base) + 0x063CUL)
#define SOC_HIPHYIO_DFX_CTRL_SIG_ADDR(base) ((base) + 0x0640UL)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_ADDR(base) ((base) + 0x0644UL)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_L_ADDR(base) ((base) + 0x0648UL)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_H_ADDR(base) ((base) + 0x064CUL)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_L_ADDR(base) ((base) + 0x0650UL)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_H_ADDR(base) ((base) + 0x0654UL)
#define SOC_HIPHYIO_AXI_TIMEOUT_MID_ADDR(base) ((base) + 0x0658UL)
#define SOC_HIPHYIO_IODIE_RESET_SW_ADDR(base) ((base) + 0x065CUL)
#define SOC_HIPHYIO_MID_TABLE_LOCK_ADDR(base) ((base) + 0x0700UL)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE0_ADDR(base) ((base) + 0x3000UL)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE1_ADDR(base) ((base) + 0x3004UL)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE2_ADDR(base) ((base) + 0x3008UL)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE3_ADDR(base) ((base) + 0x300CUL)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_ADDR(base) ((base) + 0x3010UL)
#define SOC_HIPHYIO_FNPLL_CTRL_HW_SW_ADDR(base) ((base) + 0x3014UL)
#define SOC_HIPHYIO_FNPLL_SHADOW_READ_ADDR(base) ((base) + 0x3018UL)
#define SOC_HIPHYIO_FNPLL_EN_SW_VOTE_ADDR(base) ((base) + 0x301CUL)
#else
#define SOC_HIPHYIO_Version_ADDR(base) (base)
#define SOC_HIPHYIO_INT_enable_ADDR(base) ((base) + 0x0004)
#define SOC_HIPHYIO_INT_status_ADDR(base) ((base) + 0x0008)
#define SOC_HIPHYIO_OPTION_MODE_TX_ADDR(base) ((base) + 0x000C)
#define SOC_HIPHYIO_OPTION_MODE_RX_ADDR(base) ((base) + 0x0010)
#define SOC_HIPHYIO_OPTION_MODE_CHANGE_ADDR(base) ((base) + 0x0014)
#define SOC_HIPHYIO_RATE_CHANGE_VOTE_ADDR(base) ((base) + 0x0018)
#define SOC_HIPHYIO_RATE_CHANGE_VOTE_STATUS_ADDR(base) ((base) + 0x001C)
#define SOC_HIPHYIO_RATE_STATUS_ADDR(base) ((base) + 0x0020)
#define SOC_HIPHYIO_RATE_CHANGE_ADDR(base) ((base) + 0x0024)
#define SOC_HIPHYIO_AUTO_ECC_MODE_ADDR(base) ((base) + 0x0028)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_ADDR(base) ((base) + 0x002C)
#define SOC_HIPHYIO_SE_MODE_PERIOD_SET_ADDR(base) ((base) + 0x0030)
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_ADDR(base) ((base) + 0x0034)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_ADDR(base) ((base) + 0x0038)
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_ADDR(base) ((base) + 0x003C)
#define SOC_HIPHYIO_SLP_EXIT_SW_TRG_ADDR(base) ((base) + 0x0040)
#define SOC_HIPHYIO_SLP_VOTE_EN_ADDR(base) ((base) + 0x0044)
#define SOC_HIPHYIO_SLP_VOTE_ADDR(base) ((base) + 0x0048)
#define SOC_HIPHYIO_SLP_VOTE_STATUS_ADDR(base) ((base) + 0x004C)
#define SOC_HIPHYIO_TEST_COMMON_ADDR(base) ((base) + 0x0050)
#define SOC_HIPHYIO_TST_SRC_ADDR(base) ((base) + 0x0054)
#define SOC_HIPHYIO_TST_DST_ADDR(base) ((base) + 0x0058)
#define SOC_HIPHYIO_TST_DST_STATUS0_ADDR(base) ((base) + 0x005C)
#define SOC_HIPHYIO_TST_DST_STATUS1_ADDR(base) ((base) + 0x0060)
#define SOC_HIPHYIO_TST_DST_STATUS_2_ADDR(base) ((base) + 0x0064)
#define SOC_HIPHYIO_TST_DST_STATUS_3_ADDR(base) ((base) + 0x0068)
#define SOC_HIPHYIO_AXI_INF_SET_ADDR(base) ((base) + 0x006C)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_ADDR(base) ((base) + 0x0070)
#define SOC_HIPHYIO_AXI_FIX_WADDR_ADDR(base,ip_fifo_num) (base) + 0x0074 + 8 * (ip_fifo_num)
#define SOC_HIPHYIO_AXI_FIX_RADDR_ADDR(base,ip_fifo_num) (base) + 0x0078 + 8 * (ip_fifo_num)
#define SOC_HIPHYIO_MID_MAP_0_ADDR(base) ((base) + 0x0174)
#define SOC_HIPHYIO_MID_MAP_1_ADDR(base) ((base) + 0x0178)
#define SOC_HIPHYIO_MID_MAP_2_ADDR(base) ((base) + 0x017C)
#define SOC_HIPHYIO_MID_MAP_3_ADDR(base) ((base) + 0x0180)
#define SOC_HIPHYIO_IDLE_LENGTH_CTRL_ADDR(base) ((base) + 0x0184)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_ADDR(base) ((base) + 0x01A4)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_ADDR(base) ((base) + 0x0200)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_ADDR(base) ((base) + 0x0204)
#define SOC_HIPHYIO_DESKEW_SET_ADDR(base) ((base) + 0x0208)
#define SOC_HIPHYIO_Powor_status_ADDR(base) ((base) + 0x020C)
#define SOC_HIPHYIO_PERF_MONITOR_GLB_ADDR(base) ((base) + 0x0210)
#define SOC_HIPHYIO_PERF_MONITOR_EVENT_ADDR(base,perf_num) (base) + 0x0214 + 8 * (perf_num)
#define SOC_HIPHYIO_PERF_MONITOR_TIME_ADDR(base,perf_num) (base) + 0x0218 + 8 * (perf_num)
#define SOC_HIPHYIO_LINKT_TX_ADDR(base) ((base) + 0x0234)
#define SOC_HIPHYIO_LINKT_TX_1_ADDR(base) ((base) + 0x0238)
#define SOC_HIPHYIO_LINK_RX_DELAY_ADDR(base) ((base) + 0x023C)
#define SOC_HIPHYIO_LINK_RX_BYPASS_ADDR(base) ((base) + 0x0240)
#define SOC_HIPHYIO_LINK_RX_STATUS_ADDR(base) ((base) + 0x0244)
#define SOC_HIPHYIO_LSS_DLY_ADDR(base) ((base) + 0x0248)
#define SOC_HIPHYIO_LSS_TX_DLY_1_0_ADDR(base) ((base) + 0x024C)
#define SOC_HIPHYIO_LSS_TX_DLY_3_2_ADDR(base) ((base) + 0x0250)
#define SOC_HIPHYIO_LSS_TX_DLY_5_4_ADDR(base) ((base) + 0x0254)
#define SOC_HIPHYIO_LSS_TX_DLY_7_6_ADDR(base) ((base) + 0x0258)
#define SOC_HIPHYIO_LSS_RX_DLY_1_0_ADDR(base) ((base) + 0x025C)
#define SOC_HIPHYIO_LSS_RX_DLY_3_2_ADDR(base) ((base) + 0x0260)
#define SOC_HIPHYIO_LSS_RX_DLY_5_4_ADDR(base) ((base) + 0x0264)
#define SOC_HIPHYIO_LSS_RX_DLY_7_6_ADDR(base) ((base) + 0x0268)
#define SOC_HIPHYIO_LSS_RX_STATUS1_ADDR(base) ((base) + 0x026C)
#define SOC_HIPHYIO_TX_PRBS_CUST_PATT_ADDR(base,lane_num) (base) + 0x0270 + 4 * (lane_num)
#define SOC_HIPHYIO_TX_PRBS_CFG_ADDR(base,lane_num) (base) + 0x0278 + 4 * (lane_num)
#define SOC_HIPHYIO_RX_OSPD_ADDR(base,lane_num) (base) + 0x0280 + 4 * (lane_num)
#define SOC_HIPHYIO_RX_PRBS_ADDR(base,lane_num) (base) + 0x0288 + 4 * (lane_num)
#define SOC_HIPHYIO_PCS_CRG_ADDR(base) ((base) + 0x290)
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_0_ADDR(base) ((base) + 0x0294)
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_1_ADDR(base) ((base) + 0x0298)
#define SOC_HIPHYIO_PKR_RT_BYPASS_ADDR(base) ((base) + 0x029C)
#define SOC_HIPHYIO_PKT_RT_ERR_HEAD_ADDR(base) ((base) + 0x02A0)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ADDR(base) ((base) + 0x02A4)
#define SOC_HIPHYIO_I2S_CFG0_ADDR(base,i2s_num) (base) + 0x02A8 + 0xC * (i2s_num)
#define SOC_HIPHYIO_I2S_CFG1_ADDR(base,i2s_num) (base) + 0x02AC + 0xC * (i2s_num)
#define SOC_HIPHYIO_I2S_CFG2_ADDR(base,i2s_num) (base) + 0x02B0 + 0xC * (i2s_num)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_ADDR(base) ((base) + 0x02D4)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_ADDR(base) ((base) + 0x02D8)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_ADDR(base) ((base) + 0x02DC)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_0_ADDR(base) ((base) + 0x02E0)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_1_ADDR(base) ((base) + 0x02E4)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_2_ADDR(base) ((base) + 0x02E8)
#define SOC_HIPHYIO_INTR_I2S_PKT_DEC_ERR_INFO_0_ADDR(base) ((base) + 0x02EC)
#define SOC_HIPHYIO_DFX_I2S_TX_PKT_GEN_ADDR(base) ((base) + 0x02F0)
#define SOC_HIPHYIO_DFX_I2S_RX_PKT_DEC_ADDR(base) ((base) + 0x02F4)
#define SOC_HIPHYIO_DFX_I2S_TX_CTRL_INTF_ADDR(base,i2s_num) (base) + 0x02F8 + 8 * (i2s_num)
#define SOC_HIPHYIO_DFX_I2S_RX_CTRL_INTF_ADDR(base,i2s_num) (base) + 0x02FC + 8 * (i2s_num)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ADDR(base) ((base) + 0x030C)
#define SOC_HIPHYIO_SPI_CFG0_ADDR(base,spi_num) (base) + 0x0310 + 0xC * (spi_num)
#define SOC_HIPHYIO_SPI_CFG1_ADDR(base,spi_num) (base) + 0x0314 + 0xC * (spi_num)
#define SOC_HIPHYIO_SPI_CFG2_ADDR(base,spi_num) (base) + 0x0318 + 0xC * (spi_num)
#define SOC_HIPHYIO_SPI_INTR_STATUS0_ADDR(base) ((base) + 0x0370)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE0_ADDR(base) ((base) + 0x0374)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE0_ADDR(base) ((base) + 0x0378)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_ADDR(base) ((base) + 0x037C)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_ADDR(base) ((base) + 0x0380)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_ADDR(base) ((base) + 0x0384)
#define SOC_HIPHYIO_SPI_INTR_STATUS2_ADDR(base) ((base) + 0x0388)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE2_ADDR(base) ((base) + 0x038C)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE2_ADDR(base) ((base) + 0x0390)
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_0_ADDR(base) ((base) + 0x0394)
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_1_ADDR(base) ((base) + 0x0398)
#define SOC_HIPHYIO_INTR_SPI_PKT_DEC_ERR_INFO_0_ADDR(base) ((base) + 0x039C)
#define SOC_HIPHYIO_DFX_SPI_TX_PKT_GEN_ADDR(base) ((base) + 0x03A0)
#define SOC_HIPHYIO_DFX_SPI_RX_PKT_DEC_ADDR(base) ((base) + 0x03A4)
#define SOC_HIPHYIO_DFX_SPI_TX_CTRL_INTF_ADDR(base,spi_num) (base) + 0x03A8 + 8 * (spi_num)
#define SOC_HIPHYIO_DFX_SPI_RX_CTRL_INTF_ADDR(base,spi_num) (base) + 0x03AC + 8 * (spi_num)
#define SOC_HIPHYIO_ECC_Err_status_ADDR(base) ((base) + 0x03E8)
#define SOC_HIPHYIO_PKT_ERR_STATUS_ADDR(base) ((base) + 0x03EC)
#define SOC_HIPHYIO_DESKEW_ERR_STATUS_ADDR(base) ((base) + 0x03F0)
#define SOC_HIPHYIO_LANE_ERR_STATUS_ADDR(base,lane_num) (base) + 0x03F4 + 4 * (lane_num)
#define SOC_HIPHYIO_DECODE_ERR_STATUS_ADDR(base) ((base) + 0x03FC)
#define SOC_HIPHYIO_PHY_CFG_ADDR(base) ((base) + 0x0400)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_ADDR(base) ((base) + 0x0404)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_ADDR(base) ((base) + 0x0408)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_ADDR(base) ((base) + 0x040C)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_ADDR(base) ((base) + 0x0410)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_ADDR(base) ((base) + 0x0414)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_ADDR(base) ((base) + 0x0418)
#define SOC_HIPHYIO_TE_CTRL_ADDR(base) ((base) + 0x041C)
#define SOC_HIPHYIO_PHY_SLEEP_CTRL_ADDR(base) ((base) + 0x0420)
#define SOC_HIPHYIO_PHY_SLEEP_INT_ADDR(base) ((base) + 0x0424)
#define SOC_HIPHYIO_CLK_MUX_ADDR(base) ((base) + 0x0428)
#define SOC_HIPHYIO_PHY_DS_COMMON_ADDR(base) ((base) + 0x042C)
#define SOC_HIPHYIO_PHY_DS_TX_0_ADDR(base) ((base) + 0x0430)
#define SOC_HIPHYIO_PHY_DS_TX_1_ADDR(base) ((base) + 0x0434)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_ADDR(base) ((base) + 0x0438)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_ADDR(base) ((base) + 0x043C)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_ADDR(base) ((base) + 0x0440)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_ADDR(base) ((base) + 0x0444)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_ADDR(base) ((base) + 0x0448)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_ADDR(base) ((base) + 0x044C)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_ADDR(base) ((base) + 0x0450)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_ADDR(base) ((base) + 0x0454)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_ADDR(base) ((base) + 0x0458)
#define SOC_HIPHYIO_PHY_STALL_DET_READ_ADDR(base) ((base) + 0x045C)
#define SOC_HIPHYIO_SE_CLK_CAL_START_ADDR(base) ((base) + 0x0460)
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_ADDR(base) ((base) + 0x0464)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_ADDR(base) ((base) + 0x0468)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_ADDR(base) ((base) + 0x046C)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_ADDR(base) ((base) + 0x0470)
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_ADDR(base) ((base) + 0x0474)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_ADDR(base) ((base) + 0x0478)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_ADDR(base) ((base) + 0x047C)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_1_ADDR(base) ((base) + 0x0480)
#define SOC_HIPHYIO_SE_CLK_CAL_START_L1_ADDR(base) ((base) + 0x0484)
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_L1_ADDR(base) ((base) + 0x0488)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_L1_ADDR(base) ((base) + 0x048C)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_L1_ADDR(base) ((base) + 0x0490)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_L1_ADDR(base) ((base) + 0x0494)
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_L1_ADDR(base) ((base) + 0x0498)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_L1_ADDR(base) ((base) + 0x049C)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_L1_ADDR(base) ((base) + 0x04A0)
#define SOC_HIPHYIO_RATE_CHANGE_CTRL_ADDR(base) ((base) + 0x04A4)
#define SOC_HIPHYIO_CRG_GT_CTRL_ADDR(base) ((base) + 0x0500)
#define SOC_HIPHYIO_CRG_GT_STATUS_ADDR(base) ((base) + 0x0504)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_ADDR(base) ((base) + 0x0508)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_ADDR(base) ((base) + 0x050C)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_ADDR(base) ((base) + 0x0510)
#define SOC_HIPHYIO_CRG_DIV_STATUS_ADDR(base) ((base) + 0x0514)
#define SOC_HIPHYIO_CRG_RST_CTRL_ADDR(base) ((base) + 0x0518)
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_ADDR(base) ((base) + 0x051C)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_ADDR(base) ((base) + 0x0520)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_ADDR(base) ((base) + 0x0524)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_ADDR(base) ((base) + 0x0528)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_ADDR(base) ((base) + 0x052C)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_ADDR(base) ((base) + 0x530)
#define SOC_HIPHYIO_FNPLL_CFG0_ADDR(base) ((base) + 0x534)
#define SOC_HIPHYIO_FNPLL_CFG1_ADDR(base) ((base) + 0x538)
#define SOC_HIPHYIO_FNPLL_CFG2_ADDR(base) ((base) + 0x53C)
#define SOC_HIPHYIO_FNPLL_CFG3_ADDR(base) ((base) + 0x540)
#define SOC_HIPHYIO_FNPLL_STATE0_ADDR(base) ((base) + 0x544)
#define SOC_HIPHYIO_FNPLL_STATE1_ADDR(base) ((base) + 0x548)
#define SOC_HIPHYIO_ULPPLL_GT_CFG_ADDR(base) ((base) + 0x0560)
#define SOC_HIPHYIO_ULPPLL_CFG0_ADDR(base) ((base) + 0x0564)
#define SOC_HIPHYIO_ULPPLL_CFG1_ADDR(base) ((base) + 0x0568)
#define SOC_HIPHYIO_ULPPLL_CFG2_ADDR(base) ((base) + 0x056C)
#define SOC_HIPHYIO_ULPPLL_CFG3_ADDR(base) ((base) + 0x0570)
#define SOC_HIPHYIO_ULPPLL_CFG4_ADDR(base) ((base) + 0x0574)
#define SOC_HIPHYIO_ULPPLL_CFG5_ADDR(base) ((base) + 0x0578)
#define SOC_HIPHYIO_ULPPLL_CFG6_ADDR(base) ((base) + 0x057C)
#define SOC_HIPHYIO_ULPPLL_CFG7_ADDR(base) ((base) + 0x0580)
#define SOC_HIPHYIO_ULPPLL_CFG8_ADDR(base) ((base) + 0x0584)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ADDR(base) ((base) + 0x0588)
#define SOC_HIPHYIO_ULPPLL_STATE0_ADDR(base) ((base) + 0x058C)
#define SOC_HIPHYIO_ULPPLL_STATE1_ADDR(base) ((base) + 0x0590)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_ADDR(base) ((base) + 0x0594)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_ADDR(base) ((base) + 0x0598)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_ADDR(base) ((base) + 0x059C)
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_ADDR(base) ((base) + 0x05A0)
#define SOC_HIPHYIO_RSV_CTRL0_ADDR(base) ((base) + 0x600)
#define SOC_HIPHYIO_RSV_CTRL1_ADDR(base) ((base) + 0x604)
#define SOC_HIPHYIO_RSV_CTRL2_ADDR(base) ((base) + 0x608)
#define SOC_HIPHYIO_RSV_CTRL3_ADDR(base) ((base) + 0x60c)
#define SOC_HIPHYIO_DFX_COUNTER_0_ADDR(base) ((base) + 0x0610)
#define SOC_HIPHYIO_DFX_COUNTER_1_ADDR(base) ((base) + 0x0614)
#define SOC_HIPHYIO_DFX_COUNTER_2_ADDR(base) ((base) + 0x0618)
#define SOC_HIPHYIO_DFX_COUNTER_3_ADDR(base) ((base) + 0x061C)
#define SOC_HIPHYIO_LSS_RX_STATUS2_ADDR(base) ((base) + 0x0620)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_ADDR(base) ((base) + 0x0624)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_ADDR(base) ((base) + 0x0628)
#define SOC_HIPHYIO_DFX_VALID_READY_ADDR(base) ((base) + 0x062C)
#define SOC_HIPHYIO_DFX_TX_ARB_ADDR(base) ((base) + 0x0630)
#define SOC_HIPHYIO_TESTPOINT_SEL_ADDR(base) ((base) + 0x0634)
#define SOC_HIPHYIO_ARB_FATAL_BLOCK_EN_ADDR(base) ((base) + 0x0638)
#define SOC_HIPHYIO_DFX_CTRL_STATE_ADDR(base) ((base) + 0x063C)
#define SOC_HIPHYIO_DFX_CTRL_SIG_ADDR(base) ((base) + 0x0640)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_ADDR(base) ((base) + 0x0644)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_L_ADDR(base) ((base) + 0x0648)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_H_ADDR(base) ((base) + 0x064C)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_L_ADDR(base) ((base) + 0x0650)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_H_ADDR(base) ((base) + 0x0654)
#define SOC_HIPHYIO_AXI_TIMEOUT_MID_ADDR(base) ((base) + 0x0658)
#define SOC_HIPHYIO_IODIE_RESET_SW_ADDR(base) ((base) + 0x065C)
#define SOC_HIPHYIO_MID_TABLE_LOCK_ADDR(base) ((base) + 0x0700)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE0_ADDR(base) ((base) + 0x3000)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE1_ADDR(base) ((base) + 0x3004)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE2_ADDR(base) ((base) + 0x3008)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE3_ADDR(base) ((base) + 0x300C)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_ADDR(base) ((base) + 0x3010)
#define SOC_HIPHYIO_FNPLL_CTRL_HW_SW_ADDR(base) ((base) + 0x3014)
#define SOC_HIPHYIO_FNPLL_SHADOW_READ_ADDR(base) ((base) + 0x3018)
#define SOC_HIPHYIO_FNPLL_EN_SW_VOTE_ADDR(base) ((base) + 0x301C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Version : 8;
        unsigned int Vendor_ID : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_Version_UNION;
#endif
#define SOC_HIPHYIO_Version_Version_START (0)
#define SOC_HIPHYIO_Version_Version_END (7)
#define SOC_HIPHYIO_Version_Vendor_ID_START (8)
#define SOC_HIPHYIO_Version_Vendor_ID_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_enter_int_en : 1;
        unsigned int sleep_exit_int_en : 1;
        unsigned int option_mode_done_int_en : 1;
        unsigned int perf_mon_done_int_en : 1;
        unsigned int spi_err_int_en : 1;
        unsigned int i2s_err_int_en : 1;
        unsigned int ecc_1b_err_int_en : 1;
        unsigned int ecc_2b_err_int_en : 1;
        unsigned int decode_err_int_en : 1;
        unsigned int pkt_err_int_en : 1;
        unsigned int deskew_err_int_en : 1;
        unsigned int lane_err_int_en : 1;
        unsigned int axi_timeout_int_en : 1;
        unsigned int rx_ospd_lock_los_int_en : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_HIPHYIO_INT_enable_UNION;
#endif
#define SOC_HIPHYIO_INT_enable_sleep_enter_int_en_START (0)
#define SOC_HIPHYIO_INT_enable_sleep_enter_int_en_END (0)
#define SOC_HIPHYIO_INT_enable_sleep_exit_int_en_START (1)
#define SOC_HIPHYIO_INT_enable_sleep_exit_int_en_END (1)
#define SOC_HIPHYIO_INT_enable_option_mode_done_int_en_START (2)
#define SOC_HIPHYIO_INT_enable_option_mode_done_int_en_END (2)
#define SOC_HIPHYIO_INT_enable_perf_mon_done_int_en_START (3)
#define SOC_HIPHYIO_INT_enable_perf_mon_done_int_en_END (3)
#define SOC_HIPHYIO_INT_enable_spi_err_int_en_START (4)
#define SOC_HIPHYIO_INT_enable_spi_err_int_en_END (4)
#define SOC_HIPHYIO_INT_enable_i2s_err_int_en_START (5)
#define SOC_HIPHYIO_INT_enable_i2s_err_int_en_END (5)
#define SOC_HIPHYIO_INT_enable_ecc_1b_err_int_en_START (6)
#define SOC_HIPHYIO_INT_enable_ecc_1b_err_int_en_END (6)
#define SOC_HIPHYIO_INT_enable_ecc_2b_err_int_en_START (7)
#define SOC_HIPHYIO_INT_enable_ecc_2b_err_int_en_END (7)
#define SOC_HIPHYIO_INT_enable_decode_err_int_en_START (8)
#define SOC_HIPHYIO_INT_enable_decode_err_int_en_END (8)
#define SOC_HIPHYIO_INT_enable_pkt_err_int_en_START (9)
#define SOC_HIPHYIO_INT_enable_pkt_err_int_en_END (9)
#define SOC_HIPHYIO_INT_enable_deskew_err_int_en_START (10)
#define SOC_HIPHYIO_INT_enable_deskew_err_int_en_END (10)
#define SOC_HIPHYIO_INT_enable_lane_err_int_en_START (11)
#define SOC_HIPHYIO_INT_enable_lane_err_int_en_END (11)
#define SOC_HIPHYIO_INT_enable_axi_timeout_int_en_START (12)
#define SOC_HIPHYIO_INT_enable_axi_timeout_int_en_END (12)
#define SOC_HIPHYIO_INT_enable_rx_ospd_lock_los_int_en_START (13)
#define SOC_HIPHYIO_INT_enable_rx_ospd_lock_los_int_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_enter_int : 1;
        unsigned int sleep_exit_int : 1;
        unsigned int option_mode_done_int : 1;
        unsigned int perf_mon_done_int : 1;
        unsigned int spi_err_int : 1;
        unsigned int i2s_err_int : 1;
        unsigned int ecc_1b_err_int : 1;
        unsigned int ecc_2b_err_int : 1;
        unsigned int decode_err_int : 1;
        unsigned int pkt_err_int : 1;
        unsigned int deskew_err_int : 1;
        unsigned int lane_err_int : 1;
        unsigned int axi_timeout_int : 1;
        unsigned int rx_ospd_lock_los_int : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_HIPHYIO_INT_status_UNION;
#endif
#define SOC_HIPHYIO_INT_status_sleep_enter_int_START (0)
#define SOC_HIPHYIO_INT_status_sleep_enter_int_END (0)
#define SOC_HIPHYIO_INT_status_sleep_exit_int_START (1)
#define SOC_HIPHYIO_INT_status_sleep_exit_int_END (1)
#define SOC_HIPHYIO_INT_status_option_mode_done_int_START (2)
#define SOC_HIPHYIO_INT_status_option_mode_done_int_END (2)
#define SOC_HIPHYIO_INT_status_perf_mon_done_int_START (3)
#define SOC_HIPHYIO_INT_status_perf_mon_done_int_END (3)
#define SOC_HIPHYIO_INT_status_spi_err_int_START (4)
#define SOC_HIPHYIO_INT_status_spi_err_int_END (4)
#define SOC_HIPHYIO_INT_status_i2s_err_int_START (5)
#define SOC_HIPHYIO_INT_status_i2s_err_int_END (5)
#define SOC_HIPHYIO_INT_status_ecc_1b_err_int_START (6)
#define SOC_HIPHYIO_INT_status_ecc_1b_err_int_END (6)
#define SOC_HIPHYIO_INT_status_ecc_2b_err_int_START (7)
#define SOC_HIPHYIO_INT_status_ecc_2b_err_int_END (7)
#define SOC_HIPHYIO_INT_status_decode_err_int_START (8)
#define SOC_HIPHYIO_INT_status_decode_err_int_END (8)
#define SOC_HIPHYIO_INT_status_pkt_err_int_START (9)
#define SOC_HIPHYIO_INT_status_pkt_err_int_END (9)
#define SOC_HIPHYIO_INT_status_deskew_err_int_START (10)
#define SOC_HIPHYIO_INT_status_deskew_err_int_END (10)
#define SOC_HIPHYIO_INT_status_lane_err_int_START (11)
#define SOC_HIPHYIO_INT_status_lane_err_int_END (11)
#define SOC_HIPHYIO_INT_status_axi_timeout_int_START (12)
#define SOC_HIPHYIO_INT_status_axi_timeout_int_END (12)
#define SOC_HIPHYIO_INT_status_rx_ospd_lock_los_int_START (13)
#define SOC_HIPHYIO_INT_status_rx_ospd_lock_los_int_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_option_mode : 1;
        unsigned int tx_encode_en : 1;
        unsigned int tx_data_scramble_en : 1;
        unsigned int tx_ecc_scramble_en : 1;
        unsigned int tx_ecc_mode : 3;
        unsigned int tx_lane_num : 3;
        unsigned int clk_sel : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_OPTION_MODE_TX_UNION;
#endif
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_option_mode_START (0)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_option_mode_END (0)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_encode_en_START (1)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_encode_en_END (1)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_data_scramble_en_START (2)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_data_scramble_en_END (2)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_ecc_scramble_en_START (3)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_ecc_scramble_en_END (3)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_ecc_mode_START (4)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_ecc_mode_END (6)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_lane_num_START (7)
#define SOC_HIPHYIO_OPTION_MODE_TX_tx_lane_num_END (9)
#define SOC_HIPHYIO_OPTION_MODE_TX_clk_sel_START (10)
#define SOC_HIPHYIO_OPTION_MODE_TX_clk_sel_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_option_mode : 1;
        unsigned int rx_encode_en : 1;
        unsigned int rx_data_scramble_en : 1;
        unsigned int rx_ecc_scramble_en : 1;
        unsigned int rx_ecc_mode : 3;
        unsigned int rx_lane_num : 3;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPHYIO_OPTION_MODE_RX_UNION;
#endif
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_option_mode_START (0)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_option_mode_END (0)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_encode_en_START (1)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_encode_en_END (1)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_data_scramble_en_START (2)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_data_scramble_en_END (2)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_ecc_scramble_en_START (3)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_ecc_scramble_en_END (3)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_ecc_mode_START (4)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_ecc_mode_END (6)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_lane_num_START (7)
#define SOC_HIPHYIO_OPTION_MODE_RX_rx_lane_num_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int option_mode_change : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_OPTION_MODE_CHANGE_UNION;
#endif
#define SOC_HIPHYIO_OPTION_MODE_CHANGE_option_mode_change_START (0)
#define SOC_HIPHYIO_OPTION_MODE_CHANGE_option_mode_change_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_HIPHYIO_RATE_CHANGE_VOTE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_HIPHYIO_RATE_CHANGE_VOTE_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rate_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_RATE_STATUS_UNION;
#endif
#define SOC_HIPHYIO_RATE_STATUS_rate_status_START (0)
#define SOC_HIPHYIO_RATE_STATUS_rate_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rate_change_wait_time : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPHYIO_RATE_CHANGE_UNION;
#endif
#define SOC_HIPHYIO_RATE_CHANGE_rate_change_wait_time_START (0)
#define SOC_HIPHYIO_RATE_CHANGE_rate_change_wait_time_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int block_length : 8;
        unsigned int ecc_inc_thd : 8;
        unsigned int ecc_dec_thd : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPHYIO_AUTO_ECC_MODE_UNION;
#endif
#define SOC_HIPHYIO_AUTO_ECC_MODE_block_length_START (0)
#define SOC_HIPHYIO_AUTO_ECC_MODE_block_length_END (7)
#define SOC_HIPHYIO_AUTO_ECC_MODE_ecc_inc_thd_START (8)
#define SOC_HIPHYIO_AUTO_ECC_MODE_ecc_inc_thd_END (15)
#define SOC_HIPHYIO_AUTO_ECC_MODE_ecc_dec_thd_START (16)
#define SOC_HIPHYIO_AUTO_ECC_MODE_ecc_dec_thd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int se_mode_sync_length : 8;
        unsigned int se_mode_stall_hold_time : 8;
        unsigned int se_mode_stall_enter_thd : 8;
        unsigned int se_mode_rx_stall_enter_time : 8;
    } reg;
} SOC_HIPHYIO_SE_MODE_STALL_SET_UNION;
#endif
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_sync_length_START (0)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_sync_length_END (7)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_stall_hold_time_START (8)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_stall_hold_time_END (15)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_stall_enter_thd_START (16)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_stall_enter_thd_END (23)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_rx_stall_enter_time_START (24)
#define SOC_HIPHYIO_SE_MODE_STALL_SET_se_mode_rx_stall_enter_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int se_mode_clk_period : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_SE_MODE_PERIOD_SET_UNION;
#endif
#define SOC_HIPHYIO_SE_MODE_PERIOD_SET_se_mode_clk_period_START (0)
#define SOC_HIPHYIO_SE_MODE_PERIOD_SET_se_mode_clk_period_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int se_mode_sleep_exit_time : 8;
        unsigned int se_mode_sleep_hold_time : 8;
        unsigned int se_mode_sleep_enter_thd : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPHYIO_CLK_MODE_SLEEP_SET_UNION;
#endif
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_se_mode_sleep_exit_time_START (0)
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_se_mode_sleep_exit_time_END (7)
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_se_mode_sleep_hold_time_START (8)
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_se_mode_sleep_hold_time_END (15)
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_se_mode_sleep_enter_thd_START (16)
#define SOC_HIPHYIO_CLK_MODE_SLEEP_SET_se_mode_sleep_enter_thd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int diff_mode_sync_length : 8;
        unsigned int diff_mode_stall_hold_time : 8;
        unsigned int diff_mode_stall_enter_thd : 8;
        unsigned int diff_mode_rx_stall_enter_time : 8;
    } reg;
} SOC_HIPHYIO_DIFF_MODE_STALL_SET_UNION;
#endif
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_sync_length_START (0)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_sync_length_END (7)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_stall_hold_time_START (8)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_stall_hold_time_END (15)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_stall_enter_thd_START (16)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_stall_enter_thd_END (23)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_rx_stall_enter_time_START (24)
#define SOC_HIPHYIO_DIFF_MODE_STALL_SET_diff_mode_rx_stall_enter_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int diff_mode_sleep_exit_time : 8;
        unsigned int diff_mode_sleep_hold_time : 8;
        unsigned int diff_mode_sleep_enter_thd : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_UNION;
#endif
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_diff_mode_sleep_exit_time_START (0)
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_diff_mode_sleep_exit_time_END (7)
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_diff_mode_sleep_hold_time_START (8)
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_diff_mode_sleep_hold_time_END (15)
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_diff_mode_sleep_enter_thd_START (16)
#define SOC_HIPHYIO_DIFF_MODE_SLEEP_SET_diff_mode_sleep_enter_thd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_exit_sw_trg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_SLP_EXIT_SW_TRG_UNION;
#endif
#define SOC_HIPHYIO_SLP_EXIT_SW_TRG_slp_exit_sw_trg_START (0)
#define SOC_HIPHYIO_SLP_EXIT_SW_TRG_slp_exit_sw_trg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_volt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_SLP_VOTE_EN_UNION;
#endif
#define SOC_HIPHYIO_SLP_VOTE_EN_slp_volt_en_START (0)
#define SOC_HIPHYIO_SLP_VOTE_EN_slp_volt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_enter_volt : 16;
        unsigned int slp_exit_volt : 16;
    } reg;
} SOC_HIPHYIO_SLP_VOTE_UNION;
#endif
#define SOC_HIPHYIO_SLP_VOTE_slp_enter_volt_START (0)
#define SOC_HIPHYIO_SLP_VOTE_slp_enter_volt_END (15)
#define SOC_HIPHYIO_SLP_VOTE_slp_exit_volt_START (16)
#define SOC_HIPHYIO_SLP_VOTE_slp_exit_volt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_volt_status : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_SLP_VOTE_STATUS_UNION;
#endif
#define SOC_HIPHYIO_SLP_VOTE_STATUS_slp_volt_status_START (0)
#define SOC_HIPHYIO_SLP_VOTE_STATUS_slp_volt_status_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_pkt_length : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_TEST_COMMON_UNION;
#endif
#define SOC_HIPHYIO_TEST_COMMON_tst_pkt_length_START (0)
#define SOC_HIPHYIO_TEST_COMMON_tst_pkt_length_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_src_start : 1;
        unsigned int tst_src_pkt_num : 15;
        unsigned int tst_src_pkt_continue_num : 8;
        unsigned int tst_src_pkt_gap : 8;
    } reg;
} SOC_HIPHYIO_TST_SRC_UNION;
#endif
#define SOC_HIPHYIO_TST_SRC_tst_src_start_START (0)
#define SOC_HIPHYIO_TST_SRC_tst_src_start_END (0)
#define SOC_HIPHYIO_TST_SRC_tst_src_pkt_num_START (1)
#define SOC_HIPHYIO_TST_SRC_tst_src_pkt_num_END (15)
#define SOC_HIPHYIO_TST_SRC_tst_src_pkt_continue_num_START (16)
#define SOC_HIPHYIO_TST_SRC_tst_src_pkt_continue_num_END (23)
#define SOC_HIPHYIO_TST_SRC_tst_src_pkt_gap_START (24)
#define SOC_HIPHYIO_TST_SRC_tst_src_pkt_gap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_start : 1;
        unsigned int tst_dst_pkt_num : 15;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_TST_DST_UNION;
#endif
#define SOC_HIPHYIO_TST_DST_tst_dst_start_START (0)
#define SOC_HIPHYIO_TST_DST_tst_dst_start_END (0)
#define SOC_HIPHYIO_TST_DST_tst_dst_pkt_num_START (1)
#define SOC_HIPHYIO_TST_DST_tst_dst_pkt_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_err_loc : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_HIPHYIO_TST_DST_STATUS0_UNION;
#endif
#define SOC_HIPHYIO_TST_DST_STATUS0_tst_dst_err_loc_START (0)
#define SOC_HIPHYIO_TST_DST_STATUS0_tst_dst_err_loc_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_err_num : 16;
        unsigned int tst_dst_err_byte : 16;
    } reg;
} SOC_HIPHYIO_TST_DST_STATUS1_UNION;
#endif
#define SOC_HIPHYIO_TST_DST_STATUS1_tst_dst_err_num_START (0)
#define SOC_HIPHYIO_TST_DST_STATUS1_tst_dst_err_num_END (15)
#define SOC_HIPHYIO_TST_DST_STATUS1_tst_dst_err_byte_START (16)
#define SOC_HIPHYIO_TST_DST_STATUS1_tst_dst_err_byte_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tst_dst_err_pkt_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_TST_DST_STATUS_2_UNION;
#endif
#define SOC_HIPHYIO_TST_DST_STATUS_2_tst_dst_err_pkt_num_START (0)
#define SOC_HIPHYIO_TST_DST_STATUS_2_tst_dst_err_pkt_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rt2tst_head_err : 1;
        unsigned int dfx_rt2tst_vld_err : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HIPHYIO_TST_DST_STATUS_3_UNION;
#endif
#define SOC_HIPHYIO_TST_DST_STATUS_3_dfx_rt2tst_head_err_START (0)
#define SOC_HIPHYIO_TST_DST_STATUS_3_dfx_rt2tst_head_err_END (0)
#define SOC_HIPHYIO_TST_DST_STATUS_3_dfx_rt2tst_vld_err_START (1)
#define SOC_HIPHYIO_TST_DST_STATUS_3_dfx_rt2tst_vld_err_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int write_ost_num : 4;
        unsigned int read_ost_num : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPHYIO_AXI_INF_SET_UNION;
#endif
#define SOC_HIPHYIO_AXI_INF_SET_write_ost_num_START (0)
#define SOC_HIPHYIO_AXI_INF_SET_write_ost_num_END (3)
#define SOC_HIPHYIO_AXI_INF_SET_read_ost_num_START (4)
#define SOC_HIPHYIO_AXI_INF_SET_read_ost_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_reset_flag : 1;
        unsigned int cfg_axi_timeout_en : 1;
        unsigned int cfg_axi_timeout_resp : 2;
        unsigned int cfg_axi_timeout_time : 18;
        unsigned int cfg_axi_timeout_mask : 1;
        unsigned int cfg_iso_en : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPHYIO_AXI_TIMEOUT_CTRL_UNION;
#endif
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_reset_flag_START (0)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_reset_flag_END (0)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_en_START (1)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_en_END (1)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_resp_START (2)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_resp_END (3)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_time_START (4)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_time_END (21)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_mask_START (22)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_axi_timeout_mask_END (22)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_iso_en_START (23)
#define SOC_HIPHYIO_AXI_TIMEOUT_CTRL_cfg_iso_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_fix_w_addr : 19;
        unsigned int fifo_fix_w_nSecurity : 1;
        unsigned int reserved_0 : 1;
        unsigned int fifo_fix_w_MID : 4;
        unsigned int fifo_fix_w_addr_en : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPHYIO_AXI_FIX_WADDR_UNION;
#endif
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_addr_START (0)
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_addr_END (18)
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_nSecurity_START (19)
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_nSecurity_END (19)
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_MID_START (21)
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_MID_END (24)
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_addr_en_START (25)
#define SOC_HIPHYIO_AXI_FIX_WADDR_fifo_fix_w_addr_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_fix_r_addr : 19;
        unsigned int fifo_fix_r_nSecurity : 1;
        unsigned int reserved_0 : 1;
        unsigned int fifo_fix_r_MID : 4;
        unsigned int fifo_fix_r_addr_en : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPHYIO_AXI_FIX_RADDR_UNION;
#endif
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_addr_START (0)
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_addr_END (18)
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_nSecurity_START (19)
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_nSecurity_END (19)
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_MID_START (21)
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_MID_END (24)
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_addr_en_START (25)
#define SOC_HIPHYIO_AXI_FIX_RADDR_fifo_fix_r_addr_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid0 : 8;
        unsigned int mid1 : 8;
        unsigned int mid2 : 8;
        unsigned int mid3 : 8;
    } reg;
} SOC_HIPHYIO_MID_MAP_0_UNION;
#endif
#define SOC_HIPHYIO_MID_MAP_0_mid0_START (0)
#define SOC_HIPHYIO_MID_MAP_0_mid0_END (7)
#define SOC_HIPHYIO_MID_MAP_0_mid1_START (8)
#define SOC_HIPHYIO_MID_MAP_0_mid1_END (15)
#define SOC_HIPHYIO_MID_MAP_0_mid2_START (16)
#define SOC_HIPHYIO_MID_MAP_0_mid2_END (23)
#define SOC_HIPHYIO_MID_MAP_0_mid3_START (24)
#define SOC_HIPHYIO_MID_MAP_0_mid3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid4 : 8;
        unsigned int mid5 : 8;
        unsigned int mid6 : 8;
        unsigned int mid7 : 8;
    } reg;
} SOC_HIPHYIO_MID_MAP_1_UNION;
#endif
#define SOC_HIPHYIO_MID_MAP_1_mid4_START (0)
#define SOC_HIPHYIO_MID_MAP_1_mid4_END (7)
#define SOC_HIPHYIO_MID_MAP_1_mid5_START (8)
#define SOC_HIPHYIO_MID_MAP_1_mid5_END (15)
#define SOC_HIPHYIO_MID_MAP_1_mid6_START (16)
#define SOC_HIPHYIO_MID_MAP_1_mid6_END (23)
#define SOC_HIPHYIO_MID_MAP_1_mid7_START (24)
#define SOC_HIPHYIO_MID_MAP_1_mid7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid8 : 8;
        unsigned int mid9 : 8;
        unsigned int mid10 : 8;
        unsigned int mid11 : 8;
    } reg;
} SOC_HIPHYIO_MID_MAP_2_UNION;
#endif
#define SOC_HIPHYIO_MID_MAP_2_mid8_START (0)
#define SOC_HIPHYIO_MID_MAP_2_mid8_END (7)
#define SOC_HIPHYIO_MID_MAP_2_mid9_START (8)
#define SOC_HIPHYIO_MID_MAP_2_mid9_END (15)
#define SOC_HIPHYIO_MID_MAP_2_mid10_START (16)
#define SOC_HIPHYIO_MID_MAP_2_mid10_END (23)
#define SOC_HIPHYIO_MID_MAP_2_mid11_START (24)
#define SOC_HIPHYIO_MID_MAP_2_mid11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid12 : 8;
        unsigned int mid13 : 8;
        unsigned int mid14 : 8;
        unsigned int mid15 : 8;
    } reg;
} SOC_HIPHYIO_MID_MAP_3_UNION;
#endif
#define SOC_HIPHYIO_MID_MAP_3_mid12_START (0)
#define SOC_HIPHYIO_MID_MAP_3_mid12_END (7)
#define SOC_HIPHYIO_MID_MAP_3_mid13_START (8)
#define SOC_HIPHYIO_MID_MAP_3_mid13_END (15)
#define SOC_HIPHYIO_MID_MAP_3_mid14_START (16)
#define SOC_HIPHYIO_MID_MAP_3_mid14_END (23)
#define SOC_HIPHYIO_MID_MAP_3_mid15_START (24)
#define SOC_HIPHYIO_MID_MAP_3_mid15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eob_idle_trans : 8;
        unsigned int ecc_mode_idle_num : 5;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_IDLE_LENGTH_CTRL_UNION;
#endif
#define SOC_HIPHYIO_IDLE_LENGTH_CTRL_eob_idle_trans_START (0)
#define SOC_HIPHYIO_IDLE_LENGTH_CTRL_eob_idle_trans_END (7)
#define SOC_HIPHYIO_IDLE_LENGTH_CTRL_ecc_mode_idle_num_START (8)
#define SOC_HIPHYIO_IDLE_LENGTH_CTRL_ecc_mode_idle_num_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_vote_clk_sel_l : 2;
        unsigned int cfg_vote_clk_sel_h : 2;
        unsigned int cfg_vote_option_mode_l : 1;
        unsigned int cfg_vote_option_mode_h : 1;
        unsigned int cfg_rate_chg_enable_sw : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_UNION;
#endif
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_clk_sel_l_START (0)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_clk_sel_l_END (1)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_clk_sel_h_START (2)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_clk_sel_h_END (3)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_option_mode_l_START (4)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_option_mode_l_END (4)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_option_mode_h_START (5)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_vote_option_mode_h_END (5)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_rate_chg_enable_sw_START (6)
#define SOC_HIPHYIO_VOTE_RATE_CHG_CTRL_cfg_rate_chg_enable_sw_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ar_fifo_status_rx : 2;
        unsigned int dfx_ar_fifo_status_tx : 2;
        unsigned int dfx_id_fifo_status_rx : 2;
        unsigned int dfx_b_fifo_status_rx : 2;
        unsigned int dfx_b_fifo_status_tx : 2;
        unsigned int dfx_aw_fifo_status_rx : 2;
        unsigned int dfx_aw_fifo_status_tx : 2;
        unsigned int dfx_w_fifo_status_rx : 2;
        unsigned int dfx_w_fifo_status_tx : 2;
        unsigned int dfx_r_fifo_status_rx : 2;
        unsigned int dfx_info_fifo_status : 2;
        unsigned int dfx_r_fifo_status_tx : 2;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_UNION;
#endif
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_ar_fifo_status_rx_START (0)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_ar_fifo_status_rx_END (1)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_ar_fifo_status_tx_START (2)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_ar_fifo_status_tx_END (3)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_id_fifo_status_rx_START (4)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_id_fifo_status_rx_END (5)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_b_fifo_status_rx_START (6)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_b_fifo_status_rx_END (7)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_b_fifo_status_tx_START (8)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_b_fifo_status_tx_END (9)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_aw_fifo_status_rx_START (10)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_aw_fifo_status_rx_END (11)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_aw_fifo_status_tx_START (12)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_aw_fifo_status_tx_END (13)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_w_fifo_status_rx_START (14)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_w_fifo_status_rx_END (15)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_w_fifo_status_tx_START (16)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_w_fifo_status_tx_END (17)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_r_fifo_status_rx_START (18)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_r_fifo_status_rx_END (19)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_info_fifo_status_START (20)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_info_fifo_status_END (21)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_r_fifo_status_tx_START (22)
#define SOC_HIPHYIO_DFX_AXI_FIFO_STATUS_dfx_r_fifo_status_tx_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_fix_packet_w : 6;
        unsigned int dfx_fix_packet_r : 6;
        unsigned int dfx_axireq_valid_ready : 6;
        unsigned int dfx_axirsq_valid_ready : 4;
        unsigned int dfx_ost_write : 4;
        unsigned int dfx_ost_read : 4;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_UNION;
#endif
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_fix_packet_w_START (0)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_fix_packet_w_END (5)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_fix_packet_r_START (6)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_fix_packet_r_END (11)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_axireq_valid_ready_START (12)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_axireq_valid_ready_END (17)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_axirsq_valid_ready_START (18)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_axirsq_valid_ready_END (21)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_ost_write_START (22)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_ost_write_END (25)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_ost_read_START (26)
#define SOC_HIPHYIO_DFX_AXI_OTHER_STATUS_dfx_ost_read_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deskew_timeout_en : 1;
        unsigned int align_timeout_en : 1;
        unsigned int align_1b_err_en : 1;
        unsigned int tx_idle_num : 5;
        unsigned int deskew_timeout_thd : 8;
        unsigned int align_timeout_thd : 8;
        unsigned int align_det_wait_time : 8;
    } reg;
} SOC_HIPHYIO_DESKEW_SET_UNION;
#endif
#define SOC_HIPHYIO_DESKEW_SET_deskew_timeout_en_START (0)
#define SOC_HIPHYIO_DESKEW_SET_deskew_timeout_en_END (0)
#define SOC_HIPHYIO_DESKEW_SET_align_timeout_en_START (1)
#define SOC_HIPHYIO_DESKEW_SET_align_timeout_en_END (1)
#define SOC_HIPHYIO_DESKEW_SET_align_1b_err_en_START (2)
#define SOC_HIPHYIO_DESKEW_SET_align_1b_err_en_END (2)
#define SOC_HIPHYIO_DESKEW_SET_tx_idle_num_START (3)
#define SOC_HIPHYIO_DESKEW_SET_tx_idle_num_END (7)
#define SOC_HIPHYIO_DESKEW_SET_deskew_timeout_thd_START (8)
#define SOC_HIPHYIO_DESKEW_SET_deskew_timeout_thd_END (15)
#define SOC_HIPHYIO_DESKEW_SET_align_timeout_thd_START (16)
#define SOC_HIPHYIO_DESKEW_SET_align_timeout_thd_END (23)
#define SOC_HIPHYIO_DESKEW_SET_align_det_wait_time_START (24)
#define SOC_HIPHYIO_DESKEW_SET_align_det_wait_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_status : 2;
        unsigned int rx_status : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_HIPHYIO_Powor_status_UNION;
#endif
#define SOC_HIPHYIO_Powor_status_tx_status_START (0)
#define SOC_HIPHYIO_Powor_status_tx_status_END (1)
#define SOC_HIPHYIO_Powor_status_rx_status_START (2)
#define SOC_HIPHYIO_Powor_status_rx_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_glb_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_PERF_MONITOR_GLB_UNION;
#endif
#define SOC_HIPHYIO_PERF_MONITOR_GLB_perf_glb_en_START (0)
#define SOC_HIPHYIO_PERF_MONITOR_GLB_perf_glb_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_mon_event_sel : 6;
        unsigned int reserved : 25;
        unsigned int perf_mon_en : 1;
    } reg;
} SOC_HIPHYIO_PERF_MONITOR_EVENT_UNION;
#endif
#define SOC_HIPHYIO_PERF_MONITOR_EVENT_perf_mon_event_sel_START (0)
#define SOC_HIPHYIO_PERF_MONITOR_EVENT_perf_mon_event_sel_END (5)
#define SOC_HIPHYIO_PERF_MONITOR_EVENT_perf_mon_en_START (31)
#define SOC_HIPHYIO_PERF_MONITOR_EVENT_perf_mon_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_mon_timeout_thd : 32;
    } reg;
} SOC_HIPHYIO_PERF_MONITOR_TIME_UNION;
#endif
#define SOC_HIPHYIO_PERF_MONITOR_TIME_perf_mon_timeout_thd_START (0)
#define SOC_HIPHYIO_PERF_MONITOR_TIME_perf_mon_timeout_thd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tx_valid_neg_cnt : 4;
        unsigned int dfx_arb_valid_neg_cnt : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPHYIO_LINKT_TX_UNION;
#endif
#define SOC_HIPHYIO_LINKT_TX_dfx_tx_valid_neg_cnt_START (0)
#define SOC_HIPHYIO_LINKT_TX_dfx_tx_valid_neg_cnt_END (3)
#define SOC_HIPHYIO_LINKT_TX_dfx_arb_valid_neg_cnt_START (4)
#define SOC_HIPHYIO_LINKT_TX_dfx_arb_valid_neg_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_linktx_lane_data_buffer_info : 8;
        unsigned int dfx_linktx_expander_buffer_info : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_LINKT_TX_1_UNION;
#endif
#define SOC_HIPHYIO_LINKT_TX_1_dfx_linktx_lane_data_buffer_info_START (0)
#define SOC_HIPHYIO_LINKT_TX_1_dfx_linktx_lane_data_buffer_info_END (7)
#define SOC_HIPHYIO_LINKT_TX_1_dfx_linktx_expander_buffer_info_START (8)
#define SOC_HIPHYIO_LINKT_TX_1_dfx_linktx_expander_buffer_info_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rx_8b10b_err_dly : 2;
        unsigned int cfg_rx_ecc1_pkt_rt_bypass_8b10b_dly : 3;
        unsigned int cfg_rx_ecc23_pkt_rt_bypass_8b10b_dly : 3;
        unsigned int cfg_rx_ecc1_pkt_rt_do_8b10b_dly : 3;
        unsigned int cfg_rx_ecc23_pkt_rt_do_8b10b_dly : 3;
        unsigned int reserved : 18;
    } reg;
} SOC_HIPHYIO_LINK_RX_DELAY_UNION;
#endif
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_8b10b_err_dly_START (0)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_8b10b_err_dly_END (1)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc1_pkt_rt_bypass_8b10b_dly_START (2)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc1_pkt_rt_bypass_8b10b_dly_END (4)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc23_pkt_rt_bypass_8b10b_dly_START (5)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc23_pkt_rt_bypass_8b10b_dly_END (7)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc1_pkt_rt_do_8b10b_dly_START (8)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc1_pkt_rt_do_8b10b_dly_END (10)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc23_pkt_rt_do_8b10b_dly_START (11)
#define SOC_HIPHYIO_LINK_RX_DELAY_cfg_rx_ecc23_pkt_rt_do_8b10b_dly_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rx_afifo0_overflow_bypass : 1;
        unsigned int cfg_rx_afifo1_overflow_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HIPHYIO_LINK_RX_BYPASS_UNION;
#endif
#define SOC_HIPHYIO_LINK_RX_BYPASS_cfg_rx_afifo0_overflow_bypass_START (0)
#define SOC_HIPHYIO_LINK_RX_BYPASS_cfg_rx_afifo0_overflow_bypass_END (0)
#define SOC_HIPHYIO_LINK_RX_BYPASS_cfg_rx_afifo1_overflow_bypass_START (1)
#define SOC_HIPHYIO_LINK_RX_BYPASS_cfg_rx_afifo1_overflow_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rx_1lane_2vld_dismatch : 1;
        unsigned int dfx_rx_vld_shift_connect1_num : 8;
        unsigned int dfx_rx_vld_shift_connect2_num : 8;
        unsigned int dfx_rx_afifo_group : 1;
        unsigned int dfx_rx_full_afifo0 : 1;
        unsigned int dfx_rx_empty_afifo0 : 1;
        unsigned int dfx_rx_full_afifo1 : 1;
        unsigned int dfx_rx_empty_afifo1 : 1;
        unsigned int dfx_rx_vld_afifo_shiftconn : 1;
        unsigned int dfx_rx_vld_shiftconn_ecc : 1;
        unsigned int dfx_rx_vld_bypass_ecc : 1;
        unsigned int dfx_rx_vld_ecc_cutshiftconn : 1;
        unsigned int dfx_rx_vld_cutshiftconn_8b10b : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_HIPHYIO_LINK_RX_STATUS_UNION;
#endif
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_1lane_2vld_dismatch_START (0)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_1lane_2vld_dismatch_END (0)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_shift_connect1_num_START (1)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_shift_connect1_num_END (8)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_shift_connect2_num_START (9)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_shift_connect2_num_END (16)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_afifo_group_START (17)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_afifo_group_END (17)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_full_afifo0_START (18)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_full_afifo0_END (18)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_empty_afifo0_START (19)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_empty_afifo0_END (19)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_full_afifo1_START (20)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_full_afifo1_END (20)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_empty_afifo1_START (21)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_empty_afifo1_END (21)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_afifo_shiftconn_START (22)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_afifo_shiftconn_END (22)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_shiftconn_ecc_START (23)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_shiftconn_ecc_END (23)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_bypass_ecc_START (24)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_bypass_ecc_END (24)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_ecc_cutshiftconn_START (25)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_ecc_cutshiftconn_END (25)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_cutshiftconn_8b10b_START (26)
#define SOC_HIPHYIO_LINK_RX_STATUS_dfx_rx_vld_cutshiftconn_8b10b_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lss_sample_interval_se : 8;
        unsigned int lss_sample_interval_dif : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_LSS_DLY_UNION;
#endif
#define SOC_HIPHYIO_LSS_DLY_lss_sample_interval_se_START (0)
#define SOC_HIPHYIO_LSS_DLY_lss_sample_interval_se_END (7)
#define SOC_HIPHYIO_LSS_DLY_lss_sample_interval_dif_START (8)
#define SOC_HIPHYIO_LSS_DLY_lss_sample_interval_dif_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lss2tx_mask_1_0 : 32;
    } reg;
} SOC_HIPHYIO_LSS_TX_DLY_1_0_UNION;
#endif
#define SOC_HIPHYIO_LSS_TX_DLY_1_0_lss2tx_mask_1_0_START (0)
#define SOC_HIPHYIO_LSS_TX_DLY_1_0_lss2tx_mask_1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lss2tx_mask_3_2 : 32;
    } reg;
} SOC_HIPHYIO_LSS_TX_DLY_3_2_UNION;
#endif
#define SOC_HIPHYIO_LSS_TX_DLY_3_2_lss2tx_mask_3_2_START (0)
#define SOC_HIPHYIO_LSS_TX_DLY_3_2_lss2tx_mask_3_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lss2tx_mask_5_4 : 32;
    } reg;
} SOC_HIPHYIO_LSS_TX_DLY_5_4_UNION;
#endif
#define SOC_HIPHYIO_LSS_TX_DLY_5_4_lss2tx_mask_5_4_START (0)
#define SOC_HIPHYIO_LSS_TX_DLY_5_4_lss2tx_mask_5_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lss2tx_mask_7_6 : 32;
    } reg;
} SOC_HIPHYIO_LSS_TX_DLY_7_6_UNION;
#endif
#define SOC_HIPHYIO_LSS_TX_DLY_7_6_lss2tx_mask_7_6_START (0)
#define SOC_HIPHYIO_LSS_TX_DLY_7_6_lss2tx_mask_7_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx2lss_mask_1_0 : 32;
    } reg;
} SOC_HIPHYIO_LSS_RX_DLY_1_0_UNION;
#endif
#define SOC_HIPHYIO_LSS_RX_DLY_1_0_rx2lss_mask_1_0_START (0)
#define SOC_HIPHYIO_LSS_RX_DLY_1_0_rx2lss_mask_1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx2lss_mask_3_2 : 32;
    } reg;
} SOC_HIPHYIO_LSS_RX_DLY_3_2_UNION;
#endif
#define SOC_HIPHYIO_LSS_RX_DLY_3_2_rx2lss_mask_3_2_START (0)
#define SOC_HIPHYIO_LSS_RX_DLY_3_2_rx2lss_mask_3_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx2lss_mask_5_4 : 32;
    } reg;
} SOC_HIPHYIO_LSS_RX_DLY_5_4_UNION;
#endif
#define SOC_HIPHYIO_LSS_RX_DLY_5_4_rx2lss_mask_5_4_START (0)
#define SOC_HIPHYIO_LSS_RX_DLY_5_4_rx2lss_mask_5_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx2lss_mask_7_6 : 32;
    } reg;
} SOC_HIPHYIO_LSS_RX_DLY_7_6_UNION;
#endif
#define SOC_HIPHYIO_LSS_RX_DLY_7_6_rx2lss_mask_7_6_START (0)
#define SOC_HIPHYIO_LSS_RX_DLY_7_6_rx2lss_mask_7_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_lss_rx_head_err : 1;
        unsigned int dfx_lss_rx_vld_err : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HIPHYIO_LSS_RX_STATUS1_UNION;
#endif
#define SOC_HIPHYIO_LSS_RX_STATUS1_dfx_lss_rx_head_err_START (0)
#define SOC_HIPHYIO_LSS_RX_STATUS1_dfx_lss_rx_head_err_END (0)
#define SOC_HIPHYIO_LSS_RX_STATUS1_dfx_lss_rx_vld_err_START (1)
#define SOC_HIPHYIO_LSS_RX_STATUS1_dfx_lss_rx_vld_err_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_prbs_cust_patt : 32;
    } reg;
} SOC_HIPHYIO_TX_PRBS_CUST_PATT_UNION;
#endif
#define SOC_HIPHYIO_TX_PRBS_CUST_PATT_tx_prbs_cust_patt_START (0)
#define SOC_HIPHYIO_TX_PRBS_CUST_PATT_tx_prbs_cust_patt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_prbs_err_inj_position : 2;
        unsigned int tx_prbs_err_inj_once : 1;
        unsigned int tx_prbs_err_inj_en : 1;
        unsigned int tx_prbs_patt_sel : 2;
        unsigned int tx_prbs_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HIPHYIO_TX_PRBS_CFG_UNION;
#endif
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_err_inj_position_START (0)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_err_inj_position_END (1)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_err_inj_once_START (2)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_err_inj_once_END (2)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_err_inj_en_START (3)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_err_inj_en_END (3)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_patt_sel_START (4)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_patt_sel_END (5)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_en_START (6)
#define SOC_HIPHYIO_TX_PRBS_CFG_tx_prbs_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rx_ospd_cdata_loca : 4;
        unsigned int dfx_rx_ospd_cdata_loca_delta : 4;
        unsigned int dfx_rx_ospd_lock_los : 1;
        unsigned int dfx_rx_ospd_channel_sel : 2;
        unsigned int rx_ospd_channel_force : 2;
        unsigned int rx_ospd_channel_shift : 1;
        unsigned int rx_ospd_mode : 1;
        unsigned int rx_ospd_clear : 1;
        unsigned int rx_ospd_read_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_HIPHYIO_RX_OSPD_UNION;
#endif
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_cdata_loca_START (0)
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_cdata_loca_END (3)
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_cdata_loca_delta_START (4)
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_cdata_loca_delta_END (7)
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_lock_los_START (8)
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_lock_los_END (8)
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_channel_sel_START (9)
#define SOC_HIPHYIO_RX_OSPD_dfx_rx_ospd_channel_sel_END (10)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_channel_force_START (11)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_channel_force_END (12)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_channel_shift_START (13)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_channel_shift_END (13)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_mode_START (14)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_mode_END (14)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_clear_START (15)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_clear_END (15)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_read_en_START (16)
#define SOC_HIPHYIO_RX_OSPD_rx_ospd_read_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rx_prbs_chk_err : 1;
        unsigned int dfx_rx_prbs_err_cnt_base : 11;
        unsigned int dfx_rx_prbs_err_cnt_exp : 4;
        unsigned int rx_prbs_patt_sel : 2;
        unsigned int rx_prbs_chk_mode : 1;
        unsigned int rx_prbs_chk_en : 1;
        unsigned int rx_prbs_csr_read_clear : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_HIPHYIO_RX_PRBS_UNION;
#endif
#define SOC_HIPHYIO_RX_PRBS_dfx_rx_prbs_chk_err_START (0)
#define SOC_HIPHYIO_RX_PRBS_dfx_rx_prbs_chk_err_END (0)
#define SOC_HIPHYIO_RX_PRBS_dfx_rx_prbs_err_cnt_base_START (1)
#define SOC_HIPHYIO_RX_PRBS_dfx_rx_prbs_err_cnt_base_END (11)
#define SOC_HIPHYIO_RX_PRBS_dfx_rx_prbs_err_cnt_exp_START (12)
#define SOC_HIPHYIO_RX_PRBS_dfx_rx_prbs_err_cnt_exp_END (15)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_patt_sel_START (16)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_patt_sel_END (17)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_chk_mode_START (18)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_chk_mode_END (18)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_chk_en_START (19)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_chk_en_END (19)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_csr_read_clear_START (20)
#define SOC_HIPHYIO_RX_PRBS_rx_prbs_csr_read_clear_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_prbs_wclk_en : 1;
        unsigned int rx_prbs_soft_rstn : 1;
        unsigned int rx_ospd_wclk_en : 1;
        unsigned int rx_ospd_soft_rstn : 1;
        unsigned int tx_prbs_clk_en : 1;
        unsigned int tx_prbs_soft_rstn : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HIPHYIO_PCS_CRG_UNION;
#endif
#define SOC_HIPHYIO_PCS_CRG_rx_prbs_wclk_en_START (0)
#define SOC_HIPHYIO_PCS_CRG_rx_prbs_wclk_en_END (0)
#define SOC_HIPHYIO_PCS_CRG_rx_prbs_soft_rstn_START (1)
#define SOC_HIPHYIO_PCS_CRG_rx_prbs_soft_rstn_END (1)
#define SOC_HIPHYIO_PCS_CRG_rx_ospd_wclk_en_START (2)
#define SOC_HIPHYIO_PCS_CRG_rx_ospd_wclk_en_END (2)
#define SOC_HIPHYIO_PCS_CRG_rx_ospd_soft_rstn_START (3)
#define SOC_HIPHYIO_PCS_CRG_rx_ospd_soft_rstn_END (3)
#define SOC_HIPHYIO_PCS_CRG_tx_prbs_clk_en_START (4)
#define SOC_HIPHYIO_PCS_CRG_tx_prbs_clk_en_END (4)
#define SOC_HIPHYIO_PCS_CRG_tx_prbs_soft_rstn_START (5)
#define SOC_HIPHYIO_PCS_CRG_tx_prbs_soft_rstn_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rx_align_det_0 : 32;
    } reg;
} SOC_HIPHYIO_ALIGN_DET_DEBUG_0_UNION;
#endif
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_0_dfx_rx_align_det_0_START (0)
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_0_dfx_rx_align_det_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rx_align_det_1 : 32;
    } reg;
} SOC_HIPHYIO_ALIGN_DET_DEBUG_1_UNION;
#endif
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_1_dfx_rx_align_det_1_START (0)
#define SOC_HIPHYIO_ALIGN_DET_DEBUG_1_dfx_rx_align_det_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rx_err_2err_stop_bypass : 1;
        unsigned int cfg_rx_8b10b_sym_err_stop_bypass : 1;
        unsigned int cfg_rx_pkt_err_stop_bypass : 1;
        unsigned int cfg_rx_pkt_stop_bypass : 1;
        unsigned int cfg_rx_eob_stop_bypass : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HIPHYIO_PKR_RT_BYPASS_UNION;
#endif
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_err_2err_stop_bypass_START (0)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_err_2err_stop_bypass_END (0)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_8b10b_sym_err_stop_bypass_START (1)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_8b10b_sym_err_stop_bypass_END (1)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_pkt_err_stop_bypass_START (2)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_pkt_err_stop_bypass_END (2)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_pkt_stop_bypass_START (3)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_pkt_stop_bypass_END (3)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_eob_stop_bypass_START (4)
#define SOC_HIPHYIO_PKR_RT_BYPASS_cfg_rx_eob_stop_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rx_pkt_err_head_out : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPHYIO_PKT_RT_ERR_HEAD_UNION;
#endif
#define SOC_HIPHYIO_PKT_RT_ERR_HEAD_cfg_rx_pkt_err_head_out_START (0)
#define SOC_HIPHYIO_PKT_RT_ERR_HEAD_cfg_rx_pkt_err_head_out_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_packet_receive_enable : 1;
        unsigned int i2s_packet_trans_enable : 1;
        unsigned int soft_reset_i2s_packet_send : 1;
        unsigned int soft_reset_i2s_packet_receive : 1;
        unsigned int i2s_trans_interval_en : 1;
        unsigned int i2s_trans_interval : 4;
        unsigned int reserved_0 : 3;
        unsigned int i2s_receive_fatal_err_handle_mode : 3;
        unsigned int reserved_1 : 1;
        unsigned int ckg_byp_link_i2s_tx_glb : 1;
        unsigned int ckg_link_i2s_tx_glb_ext_ena : 1;
        unsigned int ckg_byp_link_i2s_rx_glb : 1;
        unsigned int ckg_link_i2s_rx_glb_ext_ena : 1;
        unsigned int i2s_tx_test_sel : 5;
        unsigned int i2s_rx_test_sel : 5;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_HIPHYIO_I2S_TRANS_CFG0_UNION;
#endif
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_packet_receive_enable_START (0)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_packet_receive_enable_END (0)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_packet_trans_enable_START (1)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_packet_trans_enable_END (1)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_soft_reset_i2s_packet_send_START (2)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_soft_reset_i2s_packet_send_END (2)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_soft_reset_i2s_packet_receive_START (3)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_soft_reset_i2s_packet_receive_END (3)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_trans_interval_en_START (4)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_trans_interval_en_END (4)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_trans_interval_START (5)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_trans_interval_END (8)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_receive_fatal_err_handle_mode_START (12)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_receive_fatal_err_handle_mode_END (14)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_byp_link_i2s_tx_glb_START (16)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_byp_link_i2s_tx_glb_END (16)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_link_i2s_tx_glb_ext_ena_START (17)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_link_i2s_tx_glb_ext_ena_END (17)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_byp_link_i2s_rx_glb_START (18)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_byp_link_i2s_rx_glb_END (18)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_link_i2s_rx_glb_ext_ena_START (19)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_ckg_link_i2s_rx_glb_ext_ena_END (19)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_tx_test_sel_START (20)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_tx_test_sel_END (24)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_rx_test_sel_START (25)
#define SOC_HIPHYIO_I2S_TRANS_CFG0_i2s_rx_test_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_i2s : 1;
        unsigned int i2s_func_mode : 2;
        unsigned int i2s_miso_edge_sel : 1;
        unsigned int i2s_mosi_edge_sel : 1;
        unsigned int i2s_first_sync_edge_mode : 1;
        unsigned int tdm_invld_frame_num : 3;
        unsigned int i2s_invld_frame_num : 4;
        unsigned int pcm_invld_frame_num : 5;
        unsigned int reserved_0 : 2;
        unsigned int i2s_dec_start_th : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPHYIO_I2S_CFG0_UNION;
#endif
#define SOC_HIPHYIO_I2S_CFG0_bypass_i2s_START (0)
#define SOC_HIPHYIO_I2S_CFG0_bypass_i2s_END (0)
#define SOC_HIPHYIO_I2S_CFG0_i2s_func_mode_START (1)
#define SOC_HIPHYIO_I2S_CFG0_i2s_func_mode_END (2)
#define SOC_HIPHYIO_I2S_CFG0_i2s_miso_edge_sel_START (3)
#define SOC_HIPHYIO_I2S_CFG0_i2s_miso_edge_sel_END (3)
#define SOC_HIPHYIO_I2S_CFG0_i2s_mosi_edge_sel_START (4)
#define SOC_HIPHYIO_I2S_CFG0_i2s_mosi_edge_sel_END (4)
#define SOC_HIPHYIO_I2S_CFG0_i2s_first_sync_edge_mode_START (5)
#define SOC_HIPHYIO_I2S_CFG0_i2s_first_sync_edge_mode_END (5)
#define SOC_HIPHYIO_I2S_CFG0_tdm_invld_frame_num_START (6)
#define SOC_HIPHYIO_I2S_CFG0_tdm_invld_frame_num_END (8)
#define SOC_HIPHYIO_I2S_CFG0_i2s_invld_frame_num_START (9)
#define SOC_HIPHYIO_I2S_CFG0_i2s_invld_frame_num_END (12)
#define SOC_HIPHYIO_I2S_CFG0_pcm_invld_frame_num_START (13)
#define SOC_HIPHYIO_I2S_CFG0_pcm_invld_frame_num_END (17)
#define SOC_HIPHYIO_I2S_CFG0_i2s_dec_start_th_START (20)
#define SOC_HIPHYIO_I2S_CFG0_i2s_dec_start_th_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_start_clken_cnt : 10;
        unsigned int i2s_start_wait_cnt : 10;
        unsigned int i2s_send_data_only_en : 1;
        unsigned int soft_reset_i2s : 1;
        unsigned int soft_clk_switch_i2s : 1;
        unsigned int i2s_stop_fifo_wr_release : 1;
        unsigned int i2s_device_clk_gate_bypass : 1;
        unsigned int ckg_byp_link_i2s_tx_loc : 1;
        unsigned int ckg_link_i2s_tx_loc_ext_ena : 1;
        unsigned int ckg_byp_link_i2s_rx_loc : 1;
        unsigned int ckg_link_i2s_rx_loc_ext_ena : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_HIPHYIO_I2S_CFG1_UNION;
#endif
#define SOC_HIPHYIO_I2S_CFG1_i2s_start_clken_cnt_START (0)
#define SOC_HIPHYIO_I2S_CFG1_i2s_start_clken_cnt_END (9)
#define SOC_HIPHYIO_I2S_CFG1_i2s_start_wait_cnt_START (10)
#define SOC_HIPHYIO_I2S_CFG1_i2s_start_wait_cnt_END (19)
#define SOC_HIPHYIO_I2S_CFG1_i2s_send_data_only_en_START (20)
#define SOC_HIPHYIO_I2S_CFG1_i2s_send_data_only_en_END (20)
#define SOC_HIPHYIO_I2S_CFG1_soft_reset_i2s_START (21)
#define SOC_HIPHYIO_I2S_CFG1_soft_reset_i2s_END (21)
#define SOC_HIPHYIO_I2S_CFG1_soft_clk_switch_i2s_START (22)
#define SOC_HIPHYIO_I2S_CFG1_soft_clk_switch_i2s_END (22)
#define SOC_HIPHYIO_I2S_CFG1_i2s_stop_fifo_wr_release_START (23)
#define SOC_HIPHYIO_I2S_CFG1_i2s_stop_fifo_wr_release_END (23)
#define SOC_HIPHYIO_I2S_CFG1_i2s_device_clk_gate_bypass_START (24)
#define SOC_HIPHYIO_I2S_CFG1_i2s_device_clk_gate_bypass_END (24)
#define SOC_HIPHYIO_I2S_CFG1_ckg_byp_link_i2s_tx_loc_START (25)
#define SOC_HIPHYIO_I2S_CFG1_ckg_byp_link_i2s_tx_loc_END (25)
#define SOC_HIPHYIO_I2S_CFG1_ckg_link_i2s_tx_loc_ext_ena_START (26)
#define SOC_HIPHYIO_I2S_CFG1_ckg_link_i2s_tx_loc_ext_ena_END (26)
#define SOC_HIPHYIO_I2S_CFG1_ckg_byp_link_i2s_rx_loc_START (27)
#define SOC_HIPHYIO_I2S_CFG1_ckg_byp_link_i2s_rx_loc_END (27)
#define SOC_HIPHYIO_I2S_CFG1_ckg_link_i2s_rx_loc_ext_ena_START (28)
#define SOC_HIPHYIO_I2S_CFG1_ckg_link_i2s_rx_loc_ext_ena_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_timeout_clk_num : 12;
        unsigned int i2s_timeout_alarm_en : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_I2S_CFG2_UNION;
#endif
#define SOC_HIPHYIO_I2S_CFG2_i2s_timeout_clk_num_START (0)
#define SOC_HIPHYIO_I2S_CFG2_i2s_timeout_clk_num_END (11)
#define SOC_HIPHYIO_I2S_CFG2_i2s_timeout_alarm_en_START (12)
#define SOC_HIPHYIO_I2S_CFG2_i2s_timeout_alarm_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_i2s_frame_tx_fifo_full_err : 4;
        unsigned int intr_i2s_frame_rx_fifo_full_err : 4;
        unsigned int intr_i2s_intf_fifo_read_empty : 4;
        unsigned int intr_i2s_timeout : 4;
        unsigned int intr_i2s_long_frame_err : 4;
        unsigned int intr_i2s_short_frame_err : 4;
        unsigned int intr_i2s_pkt_rx_vld_err : 1;
        unsigned int intr_i2s_pkt_dec_err : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_HIPHYIO_I2S_INTR_STATUS0_UNION;
#endif
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_frame_tx_fifo_full_err_START (0)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_frame_tx_fifo_full_err_END (3)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_frame_rx_fifo_full_err_START (4)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_frame_rx_fifo_full_err_END (7)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_intf_fifo_read_empty_START (8)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_intf_fifo_read_empty_END (11)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_timeout_START (12)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_timeout_END (15)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_long_frame_err_START (16)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_long_frame_err_END (19)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_short_frame_err_START (20)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_short_frame_err_END (23)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_pkt_rx_vld_err_START (24)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_pkt_rx_vld_err_END (24)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_pkt_dec_err_START (25)
#define SOC_HIPHYIO_I2S_INTR_STATUS0_intr_i2s_pkt_dec_err_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_i2s_frame_tx_fifo_full_err_mask : 4;
        unsigned int intr_i2s_frame_rx_fifo_full_err_mask : 4;
        unsigned int intr_i2s_intf_b2a_fifo_read_empty_mask : 4;
        unsigned int intr_i2s_timeout_mask : 4;
        unsigned int intr_i2s_long_frame_err_mask : 4;
        unsigned int intr_i2s_short_frame_err_mask : 4;
        unsigned int intr_i2s_pkt_rx_vld_err_mask : 1;
        unsigned int intr_i2s_pkt_dec_err_mask : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_UNION;
#endif
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_frame_tx_fifo_full_err_mask_START (0)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_frame_tx_fifo_full_err_mask_END (3)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_frame_rx_fifo_full_err_mask_START (4)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_frame_rx_fifo_full_err_mask_END (7)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_intf_b2a_fifo_read_empty_mask_START (8)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_intf_b2a_fifo_read_empty_mask_END (11)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_timeout_mask_START (12)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_timeout_mask_END (15)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_long_frame_err_mask_START (16)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_long_frame_err_mask_END (19)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_short_frame_err_mask_START (20)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_short_frame_err_mask_END (23)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_pkt_rx_vld_err_mask_START (24)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_pkt_rx_vld_err_mask_END (24)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_pkt_dec_err_mask_START (25)
#define SOC_HIPHYIO_I2S_INTR_STATUS_ENABLE0_intr_i2s_pkt_dec_err_mask_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_i2s_frame_tx_fifo_full_err_output_enable : 4;
        unsigned int intr_i2s_frame_rx_fifo_full_err_output_enable : 4;
        unsigned int intr_i2s_intf_b2a_fifo_read_empty_output_enable : 4;
        unsigned int intr_i2s_timeout_output_enable : 4;
        unsigned int intr_i2s_long_frame_err_output_enable : 4;
        unsigned int intr_i2s_short_frame_err_output_enable : 4;
        unsigned int intr_i2s_pkt_rx_vld_err_output_enable : 1;
        unsigned int intr_i2s_pkt_dec_err_output_enable : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_UNION;
#endif
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_frame_tx_fifo_full_err_output_enable_START (0)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_frame_tx_fifo_full_err_output_enable_END (3)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_frame_rx_fifo_full_err_output_enable_START (4)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_frame_rx_fifo_full_err_output_enable_END (7)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_intf_b2a_fifo_read_empty_output_enable_START (8)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_intf_b2a_fifo_read_empty_output_enable_END (11)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_timeout_output_enable_START (12)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_timeout_output_enable_END (15)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_long_frame_err_output_enable_START (16)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_long_frame_err_output_enable_END (19)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_short_frame_err_output_enable_START (20)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_short_frame_err_output_enable_END (23)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_pkt_rx_vld_err_output_enable_START (24)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_pkt_rx_vld_err_output_enable_END (24)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_pkt_dec_err_output_enable_START (25)
#define SOC_HIPHYIO_I2S_INTR_OUTPUT_ENABLE0_intr_i2s_pkt_dec_err_output_enable_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_pkt_rx_vld_err_info0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_0_UNION;
#endif
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_0_i2s_pkt_rx_vld_err_info0_START (0)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_0_i2s_pkt_rx_vld_err_info0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_pkt_rx_vld_err_info1 : 32;
    } reg;
} SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_1_UNION;
#endif
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_1_i2s_pkt_rx_vld_err_info1_START (0)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_1_i2s_pkt_rx_vld_err_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_pkt_rx_vld_err_info2 : 32;
    } reg;
} SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_2_UNION;
#endif
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_2_i2s_pkt_rx_vld_err_info2_START (0)
#define SOC_HIPHYIO_INTR_I2S_PKT_RX_VLD_ERR_INFO_2_i2s_pkt_rx_vld_err_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_pkt_dec_err_info : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HIPHYIO_INTR_I2S_PKT_DEC_ERR_INFO_0_UNION;
#endif
#define SOC_HIPHYIO_INTR_I2S_PKT_DEC_ERR_INFO_0_i2s_pkt_dec_err_info_START (0)
#define SOC_HIPHYIO_INTR_I2S_PKT_DEC_ERR_INFO_0_i2s_pkt_dec_err_info_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2s_tx_pkt_gen : 32;
    } reg;
} SOC_HIPHYIO_DFX_I2S_TX_PKT_GEN_UNION;
#endif
#define SOC_HIPHYIO_DFX_I2S_TX_PKT_GEN_dfx_i2s_tx_pkt_gen_START (0)
#define SOC_HIPHYIO_DFX_I2S_TX_PKT_GEN_dfx_i2s_tx_pkt_gen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2s_rx_pkt_dec : 32;
    } reg;
} SOC_HIPHYIO_DFX_I2S_RX_PKT_DEC_UNION;
#endif
#define SOC_HIPHYIO_DFX_I2S_RX_PKT_DEC_dfx_i2s_rx_pkt_dec_START (0)
#define SOC_HIPHYIO_DFX_I2S_RX_PKT_DEC_dfx_i2s_rx_pkt_dec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2s_tx_ctrl_intf : 32;
    } reg;
} SOC_HIPHYIO_DFX_I2S_TX_CTRL_INTF_UNION;
#endif
#define SOC_HIPHYIO_DFX_I2S_TX_CTRL_INTF_dfx_i2s_tx_ctrl_intf_START (0)
#define SOC_HIPHYIO_DFX_I2S_TX_CTRL_INTF_dfx_i2s_tx_ctrl_intf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2s_rx_ctrl_intf : 32;
    } reg;
} SOC_HIPHYIO_DFX_I2S_RX_CTRL_INTF_UNION;
#endif
#define SOC_HIPHYIO_DFX_I2S_RX_CTRL_INTF_dfx_i2s_rx_ctrl_intf_START (0)
#define SOC_HIPHYIO_DFX_I2S_RX_CTRL_INTF_dfx_i2s_rx_ctrl_intf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_packet_receive_enable : 1;
        unsigned int spi_packet_trans_enable : 1;
        unsigned int soft_reset_spi_packet_send : 1;
        unsigned int soft_reset_spi_packet_receive : 1;
        unsigned int spi_trans_interval_en : 1;
        unsigned int spi_trans_interval : 4;
        unsigned int reserved_0 : 3;
        unsigned int spi_receive_fatal_err_handle_mode : 3;
        unsigned int reserved_1 : 1;
        unsigned int ckg_byp_link_spi_tx_glb : 1;
        unsigned int ckg_link_spi_tx_glb_ext_ena : 1;
        unsigned int ckg_byp_link_spi_rx_glb : 1;
        unsigned int ckg_link_spi_rx_glb_ext_ena : 1;
        unsigned int spi_tx_test_sel : 5;
        unsigned int spi_rx_test_sel : 5;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_HIPHYIO_SPI_TRANS_CFG0_UNION;
#endif
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_packet_receive_enable_START (0)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_packet_receive_enable_END (0)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_packet_trans_enable_START (1)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_packet_trans_enable_END (1)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_soft_reset_spi_packet_send_START (2)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_soft_reset_spi_packet_send_END (2)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_soft_reset_spi_packet_receive_START (3)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_soft_reset_spi_packet_receive_END (3)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_trans_interval_en_START (4)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_trans_interval_en_END (4)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_trans_interval_START (5)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_trans_interval_END (8)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_receive_fatal_err_handle_mode_START (12)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_receive_fatal_err_handle_mode_END (14)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_byp_link_spi_tx_glb_START (16)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_byp_link_spi_tx_glb_END (16)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_link_spi_tx_glb_ext_ena_START (17)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_link_spi_tx_glb_ext_ena_END (17)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_byp_link_spi_rx_glb_START (18)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_byp_link_spi_rx_glb_END (18)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_link_spi_rx_glb_ext_ena_START (19)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_ckg_link_spi_rx_glb_ext_ena_END (19)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_tx_test_sel_START (20)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_tx_test_sel_END (24)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_rx_test_sel_START (25)
#define SOC_HIPHYIO_SPI_TRANS_CFG0_spi_rx_test_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_spi : 1;
        unsigned int spi_cfg_en : 1;
        unsigned int spi_clock_polarity : 1;
        unsigned int spi_clock_phase : 1;
        unsigned int spi_sample_hi_spd : 1;
        unsigned int spi_sample_clk_rx_delay : 3;
        unsigned int spi_cs2_n : 1;
        unsigned int reserved_0 : 3;
        unsigned int spi_invalid_frame_num : 8;
        unsigned int ckg_byp_link_spi_tx_loc : 1;
        unsigned int ckg_link_spi_tx_loc_ext_ena : 1;
        unsigned int ckg_byp_link_spi_rx_loc : 1;
        unsigned int ckg_link_spi_rx_loc_ext_ena : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_HIPHYIO_SPI_CFG0_UNION;
#endif
#define SOC_HIPHYIO_SPI_CFG0_bypass_spi_START (0)
#define SOC_HIPHYIO_SPI_CFG0_bypass_spi_END (0)
#define SOC_HIPHYIO_SPI_CFG0_spi_cfg_en_START (1)
#define SOC_HIPHYIO_SPI_CFG0_spi_cfg_en_END (1)
#define SOC_HIPHYIO_SPI_CFG0_spi_clock_polarity_START (2)
#define SOC_HIPHYIO_SPI_CFG0_spi_clock_polarity_END (2)
#define SOC_HIPHYIO_SPI_CFG0_spi_clock_phase_START (3)
#define SOC_HIPHYIO_SPI_CFG0_spi_clock_phase_END (3)
#define SOC_HIPHYIO_SPI_CFG0_spi_sample_hi_spd_START (4)
#define SOC_HIPHYIO_SPI_CFG0_spi_sample_hi_spd_END (4)
#define SOC_HIPHYIO_SPI_CFG0_spi_sample_clk_rx_delay_START (5)
#define SOC_HIPHYIO_SPI_CFG0_spi_sample_clk_rx_delay_END (7)
#define SOC_HIPHYIO_SPI_CFG0_spi_cs2_n_START (8)
#define SOC_HIPHYIO_SPI_CFG0_spi_cs2_n_END (8)
#define SOC_HIPHYIO_SPI_CFG0_spi_invalid_frame_num_START (12)
#define SOC_HIPHYIO_SPI_CFG0_spi_invalid_frame_num_END (19)
#define SOC_HIPHYIO_SPI_CFG0_ckg_byp_link_spi_tx_loc_START (20)
#define SOC_HIPHYIO_SPI_CFG0_ckg_byp_link_spi_tx_loc_END (20)
#define SOC_HIPHYIO_SPI_CFG0_ckg_link_spi_tx_loc_ext_ena_START (21)
#define SOC_HIPHYIO_SPI_CFG0_ckg_link_spi_tx_loc_ext_ena_END (21)
#define SOC_HIPHYIO_SPI_CFG0_ckg_byp_link_spi_rx_loc_START (22)
#define SOC_HIPHYIO_SPI_CFG0_ckg_byp_link_spi_rx_loc_END (22)
#define SOC_HIPHYIO_SPI_CFG0_ckg_link_spi_rx_loc_ext_ena_START (23)
#define SOC_HIPHYIO_SPI_CFG0_ckg_link_spi_rx_loc_ext_ena_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int spi_data_data_phase0_interval_num : 3;
        unsigned int spi_data_data_phase1_interval_num : 3;
        unsigned int spi_cs_data_interval_num : 3;
        unsigned int soft_reset_spi : 1;
        unsigned int soft_clk_switch_spi : 1;
        unsigned int spi_stop_fifo_wr_release : 1;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_HIPHYIO_SPI_CFG1_UNION;
#endif
#define SOC_HIPHYIO_SPI_CFG1_spi_data_data_phase0_interval_num_START (3)
#define SOC_HIPHYIO_SPI_CFG1_spi_data_data_phase0_interval_num_END (5)
#define SOC_HIPHYIO_SPI_CFG1_spi_data_data_phase1_interval_num_START (6)
#define SOC_HIPHYIO_SPI_CFG1_spi_data_data_phase1_interval_num_END (8)
#define SOC_HIPHYIO_SPI_CFG1_spi_cs_data_interval_num_START (9)
#define SOC_HIPHYIO_SPI_CFG1_spi_cs_data_interval_num_END (11)
#define SOC_HIPHYIO_SPI_CFG1_soft_reset_spi_START (12)
#define SOC_HIPHYIO_SPI_CFG1_soft_reset_spi_END (12)
#define SOC_HIPHYIO_SPI_CFG1_soft_clk_switch_spi_START (13)
#define SOC_HIPHYIO_SPI_CFG1_soft_clk_switch_spi_END (13)
#define SOC_HIPHYIO_SPI_CFG1_spi_stop_fifo_wr_release_START (14)
#define SOC_HIPHYIO_SPI_CFG1_spi_stop_fifo_wr_release_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_div_ratio_pre : 8;
        unsigned int spi_div_ratio_post : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_SPI_CFG2_UNION;
#endif
#define SOC_HIPHYIO_SPI_CFG2_spi_div_ratio_pre_START (0)
#define SOC_HIPHYIO_SPI_CFG2_spi_div_ratio_pre_END (7)
#define SOC_HIPHYIO_SPI_CFG2_spi_div_ratio_post_START (8)
#define SOC_HIPHYIO_SPI_CFG2_spi_div_ratio_post_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_intf_b2a_fifo_read_empty : 15;
        unsigned int intr_spi_a2b_intf_fifo_full_err : 15;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPHYIO_SPI_INTR_STATUS0_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_STATUS0_intr_spi_intf_b2a_fifo_read_empty_START (0)
#define SOC_HIPHYIO_SPI_INTR_STATUS0_intr_spi_intf_b2a_fifo_read_empty_END (14)
#define SOC_HIPHYIO_SPI_INTR_STATUS0_intr_spi_a2b_intf_fifo_full_err_START (15)
#define SOC_HIPHYIO_SPI_INTR_STATUS0_intr_spi_a2b_intf_fifo_full_err_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_intf_b2a_fifo_read_empty_mask : 15;
        unsigned int intr_spi_a2b_intf_fifo_full_err_mask : 15;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE0_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE0_intr_spi_intf_b2a_fifo_read_empty_mask_START (0)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE0_intr_spi_intf_b2a_fifo_read_empty_mask_END (14)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE0_intr_spi_a2b_intf_fifo_full_err_mask_START (15)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE0_intr_spi_a2b_intf_fifo_full_err_mask_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_intf_b2a_fifo_read_empty_output_enable : 15;
        unsigned int intr_spi_a2b_intf_fifo_full_err_output_enable : 15;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE0_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE0_intr_spi_intf_b2a_fifo_read_empty_output_enable_START (0)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE0_intr_spi_intf_b2a_fifo_read_empty_output_enable_END (14)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE0_intr_spi_a2b_intf_fifo_full_err_output_enable_START (15)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE0_intr_spi_a2b_intf_fifo_full_err_output_enable_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_frame_tx_fifo_full_err : 15;
        unsigned int intr_spi_cs_err : 15;
        unsigned int intr_spi_pkt_rx_vld_err : 1;
        unsigned int intr_spi_pkt_dec_err : 1;
    } reg;
} SOC_HIPHYIO_SPI_INTR_STATUS1_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_frame_tx_fifo_full_err_START (0)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_frame_tx_fifo_full_err_END (14)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_cs_err_START (15)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_cs_err_END (29)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_pkt_rx_vld_err_START (30)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_pkt_rx_vld_err_END (30)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_pkt_dec_err_START (31)
#define SOC_HIPHYIO_SPI_INTR_STATUS1_intr_spi_pkt_dec_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_frame_tx_fifo_full_err_msk : 15;
        unsigned int intr_spi_cs_err_msk : 15;
        unsigned int intr_spi_pkt_rx_vld_err_msk : 1;
        unsigned int intr_spi_pkt_dec_err_msk : 1;
    } reg;
} SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_frame_tx_fifo_full_err_msk_START (0)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_frame_tx_fifo_full_err_msk_END (14)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_cs_err_msk_START (15)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_cs_err_msk_END (29)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_pkt_rx_vld_err_msk_START (30)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_pkt_rx_vld_err_msk_END (30)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_pkt_dec_err_msk_START (31)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE1_intr_spi_pkt_dec_err_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_frame_tx_fifo_full_err_ouput_enable : 15;
        unsigned int intr_spi_cs_err_ouput_enable : 15;
        unsigned int intr_spi_pkt_rx_vld_err_ouput_enable : 1;
        unsigned int intr_spi_pkt_dec_err_ouput_enabl : 1;
    } reg;
} SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_frame_tx_fifo_full_err_ouput_enable_START (0)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_frame_tx_fifo_full_err_ouput_enable_END (14)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_cs_err_ouput_enable_START (15)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_cs_err_ouput_enable_END (29)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_pkt_rx_vld_err_ouput_enable_START (30)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_pkt_rx_vld_err_ouput_enable_END (30)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_pkt_dec_err_ouput_enabl_START (31)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE1_intr_spi_pkt_dec_err_ouput_enabl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_frame_rx_fifo_full_err : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HIPHYIO_SPI_INTR_STATUS2_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_STATUS2_intr_spi_frame_rx_fifo_full_err_START (0)
#define SOC_HIPHYIO_SPI_INTR_STATUS2_intr_spi_frame_rx_fifo_full_err_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_frame_rx_fifo_full_err_msk : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE2_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE2_intr_spi_frame_rx_fifo_full_err_msk_START (0)
#define SOC_HIPHYIO_SPI_INTR_STATUS_ENABLE2_intr_spi_frame_rx_fifo_full_err_msk_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_spi_frame_rx_fifo_full_err_ouput_enable : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE2_UNION;
#endif
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE2_intr_spi_frame_rx_fifo_full_err_ouput_enable_START (0)
#define SOC_HIPHYIO_SPI_INTR_OUTPUT_ENABLE2_intr_spi_frame_rx_fifo_full_err_ouput_enable_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_pkt_rx_vld_err_info0 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_0_UNION;
#endif
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_0_spi_pkt_rx_vld_err_info0_START (0)
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_0_spi_pkt_rx_vld_err_info0_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_pkt_rx_vld_err_info1 : 32;
    } reg;
} SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_1_UNION;
#endif
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_1_spi_pkt_rx_vld_err_info1_START (0)
#define SOC_HIPHYIO_INTR_SPI_PKT_RX_VLD_ERR_INFO_1_spi_pkt_rx_vld_err_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_pkt_dec_err_info : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_HIPHYIO_INTR_SPI_PKT_DEC_ERR_INFO_0_UNION;
#endif
#define SOC_HIPHYIO_INTR_SPI_PKT_DEC_ERR_INFO_0_spi_pkt_dec_err_info_START (0)
#define SOC_HIPHYIO_INTR_SPI_PKT_DEC_ERR_INFO_0_spi_pkt_dec_err_info_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi_tx_pkt_gen : 32;
    } reg;
} SOC_HIPHYIO_DFX_SPI_TX_PKT_GEN_UNION;
#endif
#define SOC_HIPHYIO_DFX_SPI_TX_PKT_GEN_dfx_spi_tx_pkt_gen_START (0)
#define SOC_HIPHYIO_DFX_SPI_TX_PKT_GEN_dfx_spi_tx_pkt_gen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi_rx_pkt_dec : 32;
    } reg;
} SOC_HIPHYIO_DFX_SPI_RX_PKT_DEC_UNION;
#endif
#define SOC_HIPHYIO_DFX_SPI_RX_PKT_DEC_dfx_spi_rx_pkt_dec_START (0)
#define SOC_HIPHYIO_DFX_SPI_RX_PKT_DEC_dfx_spi_rx_pkt_dec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi_tx_ctrl_intf : 32;
    } reg;
} SOC_HIPHYIO_DFX_SPI_TX_CTRL_INTF_UNION;
#endif
#define SOC_HIPHYIO_DFX_SPI_TX_CTRL_INTF_dfx_spi_tx_ctrl_intf_START (0)
#define SOC_HIPHYIO_DFX_SPI_TX_CTRL_INTF_dfx_spi_tx_ctrl_intf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi_rx_ctrl_intf : 32;
    } reg;
} SOC_HIPHYIO_DFX_SPI_RX_CTRL_INTF_UNION;
#endif
#define SOC_HIPHYIO_DFX_SPI_RX_CTRL_INTF_dfx_spi_rx_ctrl_intf_START (0)
#define SOC_HIPHYIO_DFX_SPI_RX_CTRL_INTF_dfx_spi_rx_ctrl_intf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pkt_ecc_1b_error : 1;
        unsigned int pkt_ecc_2b_error : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HIPHYIO_ECC_Err_status_UNION;
#endif
#define SOC_HIPHYIO_ECC_Err_status_pkt_ecc_1b_error_START (0)
#define SOC_HIPHYIO_ECC_Err_status_pkt_ecc_1b_error_END (0)
#define SOC_HIPHYIO_ECC_Err_status_pkt_ecc_2b_error_START (1)
#define SOC_HIPHYIO_ECC_Err_status_pkt_ecc_2b_error_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pkt_type_err : 1;
        unsigned int pkt_other_err : 1;
        unsigned int reserved_0 : 6;
        unsigned int pkt_err_data : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HIPHYIO_PKT_ERR_STATUS_UNION;
#endif
#define SOC_HIPHYIO_PKT_ERR_STATUS_pkt_type_err_START (0)
#define SOC_HIPHYIO_PKT_ERR_STATUS_pkt_type_err_END (0)
#define SOC_HIPHYIO_PKT_ERR_STATUS_pkt_other_err_START (1)
#define SOC_HIPHYIO_PKT_ERR_STATUS_pkt_other_err_END (1)
#define SOC_HIPHYIO_PKT_ERR_STATUS_pkt_err_data_START (8)
#define SOC_HIPHYIO_PKT_ERR_STATUS_pkt_err_data_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deskew_timeout : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_DESKEW_ERR_STATUS_UNION;
#endif
#define SOC_HIPHYIO_DESKEW_ERR_STATUS_deskew_timeout_START (0)
#define SOC_HIPHYIO_DESKEW_ERR_STATUS_deskew_timeout_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int align_ecc_1b_error : 1;
        unsigned int align_ecc_2b_error : 1;
        unsigned int align_data_1b_error : 1;
        unsigned int align_timeout : 1;
        unsigned int Afifo_overflow : 1;
        unsigned int reserved : 11;
        unsigned int align_err_data : 16;
    } reg;
} SOC_HIPHYIO_LANE_ERR_STATUS_UNION;
#endif
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_ecc_1b_error_START (0)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_ecc_1b_error_END (0)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_ecc_2b_error_START (1)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_ecc_2b_error_END (1)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_data_1b_error_START (2)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_data_1b_error_END (2)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_timeout_START (3)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_timeout_END (3)
#define SOC_HIPHYIO_LANE_ERR_STATUS_Afifo_overflow_START (4)
#define SOC_HIPHYIO_LANE_ERR_STATUS_Afifo_overflow_END (4)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_err_data_START (16)
#define SOC_HIPHYIO_LANE_ERR_STATUS_align_err_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int decode_err : 1;
        unsigned int polarity_err : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HIPHYIO_DECODE_ERR_STATUS_UNION;
#endif
#define SOC_HIPHYIO_DECODE_ERR_STATUS_decode_err_START (0)
#define SOC_HIPHYIO_DECODE_ERR_STATUS_decode_err_END (0)
#define SOC_HIPHYIO_DECODE_ERR_STATUS_polarity_err_START (1)
#define SOC_HIPHYIO_DECODE_ERR_STATUS_polarity_err_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_cfg_en_sw : 1;
        unsigned int phy_init_done : 1;
        unsigned int init_cfg_sw : 1;
        unsigned int reserved_0 : 1;
        unsigned int se_phy_sync_seq : 8;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_HIPHYIO_PHY_CFG_UNION;
#endif
#define SOC_HIPHYIO_PHY_CFG_phy_cfg_en_sw_START (0)
#define SOC_HIPHYIO_PHY_CFG_phy_cfg_en_sw_END (0)
#define SOC_HIPHYIO_PHY_CFG_phy_init_done_START (1)
#define SOC_HIPHYIO_PHY_CFG_phy_init_done_END (1)
#define SOC_HIPHYIO_PHY_CFG_init_cfg_sw_START (2)
#define SOC_HIPHYIO_PHY_CFG_init_cfg_sw_END (2)
#define SOC_HIPHYIO_PHY_CFG_se_phy_sync_seq_START (4)
#define SOC_HIPHYIO_PHY_CFG_se_phy_sync_seq_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_phy_stable_time_dif : 4;
        unsigned int vcm_respond_time_dif : 4;
        unsigned int tx_pulldn_time_dif : 4;
        unsigned int reserved_0 : 4;
        unsigned int tx_drv_pwrup_respond_time_dif : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_UNION;
#endif
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_rx_phy_stable_time_dif_START (0)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_rx_phy_stable_time_dif_END (3)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_vcm_respond_time_dif_START (4)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_vcm_respond_time_dif_END (7)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_tx_pulldn_time_dif_START (8)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_tx_pulldn_time_dif_END (11)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_tx_drv_pwrup_respond_time_dif_START (16)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_DIFF_tx_drv_pwrup_respond_time_dif_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_phy_stable_time_se : 4;
        unsigned int vcm_respond_time_se : 4;
        unsigned int tx_pulldn_time_se : 4;
        unsigned int reserved_0 : 4;
        unsigned int tx_drv_pwrup_respond_time_se : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_HIPHYIO_PHY_TIMING_CTEL_SE_UNION;
#endif
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_rx_phy_stable_time_se_START (0)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_rx_phy_stable_time_se_END (3)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_vcm_respond_time_se_START (4)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_vcm_respond_time_se_END (7)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_tx_pulldn_time_se_START (8)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_tx_pulldn_time_se_END (11)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_tx_drv_pwrup_respond_time_se_START (16)
#define SOC_HIPHYIO_PHY_TIMING_CTEL_SE_tx_drv_pwrup_respond_time_se_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dscp_hsclkrcv_pwrdnb : 1;
        unsigned int phy_txcp_clktree_pwrdnb : 1;
        unsigned int phy_txdp_p2s_pwrdnb : 1;
        unsigned int phy_txdrv_pwrdnb : 1;
        unsigned int phy_txdrv_idle_pwrdnb : 1;
        unsigned int phy_txdrv_idle_pulldn_en : 1;
        unsigned int phy_txreg_drv_ref_pwrdnb : 1;
        unsigned int phy_txreg_drv_pwrdnb : 1;
        unsigned int phy_txreg_drv_bleed_en : 1;
        unsigned int phy_txreg_drv_fast_startup : 1;
        unsigned int reserved : 6;
        unsigned int phy_txdrv_oc : 16;
    } reg;
} SOC_HIPHYIO_PHY_TX_CTEL_LANE0_UNION;
#endif
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_dscp_hsclkrcv_pwrdnb_START (0)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_dscp_hsclkrcv_pwrdnb_END (0)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txcp_clktree_pwrdnb_START (1)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txcp_clktree_pwrdnb_END (1)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdp_p2s_pwrdnb_START (2)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdp_p2s_pwrdnb_END (2)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_pwrdnb_START (3)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_pwrdnb_END (3)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_idle_pwrdnb_START (4)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_idle_pwrdnb_END (4)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_idle_pulldn_en_START (5)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_idle_pulldn_en_END (5)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_ref_pwrdnb_START (6)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_ref_pwrdnb_END (6)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_pwrdnb_START (7)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_pwrdnb_END (7)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_bleed_en_START (8)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_bleed_en_END (8)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_fast_startup_START (9)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txreg_drv_fast_startup_END (9)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_oc_START (16)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE0_phy_txdrv_oc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_rxterm_cal : 4;
        unsigned int phy_rx_1k_hiz_sel_reg : 1;
        unsigned int phy_rxcp_clktree_pwrdnb : 1;
        unsigned int phy_rxcp_iqgen_pwrdnb : 1;
        unsigned int phy_rxcp_wordclk_pwrdnb : 1;
        unsigned int phy_rxdp_sliceri_pwrdnb : 1;
        unsigned int phy_rxdp_slicerib_pwrdnb : 1;
        unsigned int phy_rxdp_slicerq_pwrdnb : 1;
        unsigned int phy_rxdp_slicerqb_pwrdnb : 1;
        unsigned int phy_rxdp_demuxi_pwrdnb : 1;
        unsigned int phy_rxdp_demuxq_pwrdnb : 1;
        unsigned int phy_ds_lvr_enb : 1;
        unsigned int phy_rx_frontend_pwrdnb : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_PHY_RX_CTEL_LANE0_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxterm_cal_START (0)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxterm_cal_END (3)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rx_1k_hiz_sel_reg_START (4)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rx_1k_hiz_sel_reg_END (4)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxcp_clktree_pwrdnb_START (5)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxcp_clktree_pwrdnb_END (5)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxcp_iqgen_pwrdnb_START (6)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxcp_iqgen_pwrdnb_END (6)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxcp_wordclk_pwrdnb_START (7)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxcp_wordclk_pwrdnb_END (7)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_sliceri_pwrdnb_START (8)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_sliceri_pwrdnb_END (8)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_slicerib_pwrdnb_START (9)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_slicerib_pwrdnb_END (9)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_slicerq_pwrdnb_START (10)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_slicerq_pwrdnb_END (10)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_slicerqb_pwrdnb_START (11)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_slicerqb_pwrdnb_END (11)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_demuxi_pwrdnb_START (12)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_demuxi_pwrdnb_END (12)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_demuxq_pwrdnb_START (13)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rxdp_demuxq_pwrdnb_END (13)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_ds_lvr_enb_START (14)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_ds_lvr_enb_END (14)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rx_frontend_pwrdnb_START (15)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE0_phy_rx_frontend_pwrdnb_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dscp_hsclkrcv_pwrdnb_l1 : 1;
        unsigned int phy_txcp_clktree_pwrdnb_l1 : 1;
        unsigned int phy_txdp_p2s_pwrdnb_l1 : 1;
        unsigned int phy_txdrv_pwrdnb_l1 : 1;
        unsigned int phy_txdrv_idle_pwrdnb_l1 : 1;
        unsigned int phy_txdrv_idle_pulldn_en_l1 : 1;
        unsigned int phy_txreg_drv_ref_pwrdnb_l1 : 1;
        unsigned int phy_txreg_drv_pwrdnb_l1 : 1;
        unsigned int phy_txreg_drv_bleed_en_l1 : 1;
        unsigned int phy_txreg_drv_fast_startup_l1 : 1;
        unsigned int reserved : 6;
        unsigned int phy_txdrv_oc_l1 : 16;
    } reg;
} SOC_HIPHYIO_PHY_TX_CTEL_LANE1_UNION;
#endif
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_dscp_hsclkrcv_pwrdnb_l1_START (0)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_dscp_hsclkrcv_pwrdnb_l1_END (0)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txcp_clktree_pwrdnb_l1_START (1)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txcp_clktree_pwrdnb_l1_END (1)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdp_p2s_pwrdnb_l1_START (2)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdp_p2s_pwrdnb_l1_END (2)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_pwrdnb_l1_START (3)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_pwrdnb_l1_END (3)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_idle_pwrdnb_l1_START (4)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_idle_pwrdnb_l1_END (4)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_idle_pulldn_en_l1_START (5)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_idle_pulldn_en_l1_END (5)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_ref_pwrdnb_l1_START (6)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_ref_pwrdnb_l1_END (6)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_pwrdnb_l1_START (7)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_pwrdnb_l1_END (7)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_bleed_en_l1_START (8)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_bleed_en_l1_END (8)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_fast_startup_l1_START (9)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txreg_drv_fast_startup_l1_END (9)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_oc_l1_START (16)
#define SOC_HIPHYIO_PHY_TX_CTEL_LANE1_phy_txdrv_oc_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_rxterm_cal_l1 : 4;
        unsigned int phy_rx_1k_hiz_sel_reg_l1 : 1;
        unsigned int phy_rxcp_clktree_pwrdnb_l1 : 1;
        unsigned int phy_rxcp_iqgen_pwrdnb_l1 : 1;
        unsigned int phy_rxcp_wordclk_pwrdnb_l1 : 1;
        unsigned int phy_rxdp_sliceri_pwrdnb_l1 : 1;
        unsigned int phy_rxdp_slicerib_pwrdnb_l1 : 1;
        unsigned int phy_rxdp_slicerq_pwrdnb_l1 : 1;
        unsigned int phy_rxdp_slicerqb_pwrdnb_l1 : 1;
        unsigned int phy_rxdp_demuxi_pwrdnb_l1 : 1;
        unsigned int phy_rxdp_demuxq_pwrdnb_l1 : 1;
        unsigned int phy_ds_lvr_enb_l1 : 1;
        unsigned int phy_rx_frontend_pwrdnb_l1 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_PHY_RX_CTEL_LANE1_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxterm_cal_l1_START (0)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxterm_cal_l1_END (3)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rx_1k_hiz_sel_reg_l1_START (4)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rx_1k_hiz_sel_reg_l1_END (4)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxcp_clktree_pwrdnb_l1_START (5)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxcp_clktree_pwrdnb_l1_END (5)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxcp_iqgen_pwrdnb_l1_START (6)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxcp_iqgen_pwrdnb_l1_END (6)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxcp_wordclk_pwrdnb_l1_START (7)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxcp_wordclk_pwrdnb_l1_END (7)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_sliceri_pwrdnb_l1_START (8)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_sliceri_pwrdnb_l1_END (8)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_slicerib_pwrdnb_l1_START (9)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_slicerib_pwrdnb_l1_END (9)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_slicerq_pwrdnb_l1_START (10)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_slicerq_pwrdnb_l1_END (10)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_slicerqb_pwrdnb_l1_START (11)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_slicerqb_pwrdnb_l1_END (11)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_demuxi_pwrdnb_l1_START (12)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_demuxi_pwrdnb_l1_END (12)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_demuxq_pwrdnb_l1_START (13)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rxdp_demuxq_pwrdnb_l1_END (13)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_ds_lvr_enb_l1_START (14)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_ds_lvr_enb_l1_END (14)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rx_frontend_pwrdnb_l1_START (15)
#define SOC_HIPHYIO_PHY_RX_CTEL_LANE1_phy_rx_frontend_pwrdnb_l1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int te_window : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_TE_CTRL_UNION;
#endif
#define SOC_HIPHYIO_TE_CTRL_te_window_START (0)
#define SOC_HIPHYIO_TE_CTRL_te_window_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_ack_timeout : 8;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_HIPHYIO_PHY_SLEEP_CTRL_UNION;
#endif
#define SOC_HIPHYIO_PHY_SLEEP_CTRL_sleep_ack_timeout_START (0)
#define SOC_HIPHYIO_PHY_SLEEP_CTRL_sleep_ack_timeout_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_sleep_ack_timeout : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_PHY_SLEEP_INT_UNION;
#endif
#define SOC_HIPHYIO_PHY_SLEEP_INT_intr_sleep_ack_timeout_START (0)
#define SOC_HIPHYIO_PHY_SLEEP_INT_intr_sleep_ack_timeout_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int sw_ack_clk_hio_sw : 5;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_HIPHYIO_CLK_MUX_UNION;
#endif
#define SOC_HIPHYIO_CLK_MUX_sw_ack_clk_hio_sw_START (4)
#define SOC_HIPHYIO_CLK_MUX_sw_ack_clk_hio_sw_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_ds_ldo_htol_en : 1;
        unsigned int d2a_txreg_drv_atb_sel : 3;
        unsigned int d2a_txreg_drv_eospro_dio_en : 1;
        unsigned int d2a_txreg_drv_lo_selb : 1;
        unsigned int a2d_ds_ana_id : 3;
        unsigned int d2a_txreg_drv_vref_sel : 3;
        unsigned int d2a_ds_atb_sel : 3;
        unsigned int reserved_0 : 1;
        unsigned int d2a_ds_ldo_htol_en_l1 : 1;
        unsigned int d2a_txreg_drv_atb_sel_l1 : 3;
        unsigned int d2a_txreg_drv_eospro_dio_en_l1 : 1;
        unsigned int d2a_txreg_drv_lo_selb_l1 : 1;
        unsigned int a2d_ds_ana_id_l1 : 3;
        unsigned int d2a_txreg_drv_vref_sel_l1 : 3;
        unsigned int d2a_ds_atb_sel_l1 : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_HIPHYIO_PHY_DS_COMMON_UNION;
#endif
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_ldo_htol_en_START (0)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_ldo_htol_en_END (0)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_atb_sel_START (1)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_atb_sel_END (3)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_eospro_dio_en_START (4)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_eospro_dio_en_END (4)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_lo_selb_START (5)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_lo_selb_END (5)
#define SOC_HIPHYIO_PHY_DS_COMMON_a2d_ds_ana_id_START (6)
#define SOC_HIPHYIO_PHY_DS_COMMON_a2d_ds_ana_id_END (8)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_vref_sel_START (9)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_vref_sel_END (11)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_atb_sel_START (12)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_atb_sel_END (14)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_ldo_htol_en_l1_START (16)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_ldo_htol_en_l1_END (16)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_atb_sel_l1_START (17)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_atb_sel_l1_END (19)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_eospro_dio_en_l1_START (20)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_eospro_dio_en_l1_END (20)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_lo_selb_l1_START (21)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_lo_selb_l1_END (21)
#define SOC_HIPHYIO_PHY_DS_COMMON_a2d_ds_ana_id_l1_START (22)
#define SOC_HIPHYIO_PHY_DS_COMMON_a2d_ds_ana_id_l1_END (24)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_vref_sel_l1_START (25)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_txreg_drv_vref_sel_l1_END (27)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_atb_sel_l1_START (28)
#define SOC_HIPHYIO_PHY_DS_COMMON_d2a_ds_atb_sel_l1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_txcp_prediv_sel : 1;
        unsigned int d2a_txmode_ctrl : 1;
        unsigned int d2a_tx_div_rstb : 1;
        unsigned int reserved_0 : 13;
        unsigned int d2a_txcp_prediv_sel_l1 : 1;
        unsigned int d2a_txmode_ctrl_l1 : 1;
        unsigned int d2a_tx_div_rstb_l1 : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_HIPHYIO_PHY_DS_TX_0_UNION;
#endif
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txcp_prediv_sel_START (0)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txcp_prediv_sel_END (0)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txmode_ctrl_START (1)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txmode_ctrl_END (1)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_tx_div_rstb_START (2)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_tx_div_rstb_END (2)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txcp_prediv_sel_l1_START (16)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txcp_prediv_sel_l1_END (16)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txmode_ctrl_l1_START (17)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_txmode_ctrl_l1_END (17)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_tx_div_rstb_l1_START (18)
#define SOC_HIPHYIO_PHY_DS_TX_0_d2a_tx_div_rstb_l1_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_txcp_ctb_localsel : 1;
        unsigned int d2a_txcp_ctb_pwrdnb : 1;
        unsigned int d2a_txcp_ctb_local_pwrdnb : 1;
        unsigned int d2a_txatb_top_sel : 3;
        unsigned int d2a_txdp_lpbk_pwrdnb : 1;
        unsigned int reserved_0 : 1;
        unsigned int d2a_txdrv_dn_cal : 4;
        unsigned int d2a_txdrv_up_cal : 4;
        unsigned int d2a_txcp_ctb_localsel_l1 : 1;
        unsigned int d2a_txcp_ctb_pwrdnb_l1 : 1;
        unsigned int d2a_txcp_ctb_local_pwrdnb_l1 : 1;
        unsigned int d2a_txatb_top_sel_l1 : 3;
        unsigned int d2a_txdp_lpbk_pwrdnb_l1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int d2a_txdrv_dn_cal_l1 : 4;
        unsigned int d2a_txdrv_up_cal_l1 : 4;
    } reg;
} SOC_HIPHYIO_PHY_DS_TX_1_UNION;
#endif
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_localsel_START (0)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_localsel_END (0)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_pwrdnb_START (1)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_pwrdnb_END (1)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_local_pwrdnb_START (2)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_local_pwrdnb_END (2)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txatb_top_sel_START (3)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txatb_top_sel_END (5)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdp_lpbk_pwrdnb_START (6)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdp_lpbk_pwrdnb_END (6)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_dn_cal_START (8)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_dn_cal_END (11)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_up_cal_START (12)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_up_cal_END (15)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_localsel_l1_START (16)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_localsel_l1_END (16)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_pwrdnb_l1_START (17)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_pwrdnb_l1_END (17)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_local_pwrdnb_l1_START (18)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txcp_ctb_local_pwrdnb_l1_END (18)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txatb_top_sel_l1_START (19)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txatb_top_sel_l1_END (21)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdp_lpbk_pwrdnb_l1_START (22)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdp_lpbk_pwrdnb_l1_END (22)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_dn_cal_l1_START (24)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_dn_cal_l1_END (27)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_up_cal_l1_START (28)
#define SOC_HIPHYIO_PHY_DS_TX_1_d2a_txdrv_up_cal_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_rx_stalldet_hys_sel : 3;
        unsigned int d2a_rx_stalldet_pwrdnb : 1;
        unsigned int d2a_rxterm_floating_en : 1;
        unsigned int d2a_rxcp_qdiv_bypass : 1;
        unsigned int d2a_rxcp_lsclk_dir_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int d2a_rxcp_delay_sel : 3;
        unsigned int d2a_rx_frontend_tielo_enb : 1;
        unsigned int d2a_rxmode_ctrl : 1;
        unsigned int reserved_1 : 3;
        unsigned int d2a_rx_stalldet_hys_sel_l1 : 3;
        unsigned int d2a_rx_stalldet_pwrdnb_l1 : 1;
        unsigned int d2a_rxterm_floating_en_l1 : 1;
        unsigned int d2a_rxcp_qdiv_bypass_l1 : 1;
        unsigned int d2a_rxcp_lsclk_dir_sel_l1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int d2a_rxcp_delay_sel_l1 : 3;
        unsigned int d2a_rx_frontend_tielo_enb_l1 : 1;
        unsigned int d2a_rxmode_ctrl_l1 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_HIPHYIO_PHY_RX_PATH_CTRL_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_hys_sel_START (0)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_hys_sel_END (2)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_pwrdnb_START (3)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_pwrdnb_END (3)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxterm_floating_en_START (4)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxterm_floating_en_END (4)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_qdiv_bypass_START (5)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_qdiv_bypass_END (5)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_lsclk_dir_sel_START (6)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_lsclk_dir_sel_END (6)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_delay_sel_START (8)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_delay_sel_END (10)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_frontend_tielo_enb_START (11)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_frontend_tielo_enb_END (11)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxmode_ctrl_START (12)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxmode_ctrl_END (12)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_hys_sel_l1_START (16)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_hys_sel_l1_END (18)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_pwrdnb_l1_START (19)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_stalldet_pwrdnb_l1_END (19)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxterm_floating_en_l1_START (20)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxterm_floating_en_l1_END (20)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_qdiv_bypass_l1_START (21)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_qdiv_bypass_l1_END (21)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_lsclk_dir_sel_l1_START (22)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_lsclk_dir_sel_l1_END (22)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_delay_sel_l1_START (24)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxcp_delay_sel_l1_END (26)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_frontend_tielo_enb_l1_START (27)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rx_frontend_tielo_enb_l1_END (27)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxmode_ctrl_l1_START (28)
#define SOC_HIPHYIO_PHY_RX_PATH_CTRL_d2a_rxmode_ctrl_l1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_rxdp_center_latchq_offsetm : 8;
        unsigned int d2a_rxdp_center_latchq_offsetp : 8;
        unsigned int d2a_rxdp_center_latchq_offsetm_l1 : 8;
        unsigned int d2a_rxdp_center_latchq_offsetp_l1 : 8;
    } reg;
} SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetm_START (0)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetm_END (7)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetp_START (8)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetp_END (15)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetm_l1_START (16)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetm_l1_END (23)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetp_l1_START (24)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_0_d2a_rxdp_center_latchq_offsetp_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_rxdp_center_latchi_offsetm : 8;
        unsigned int d2a_rxdp_center_latchi_offsetp : 8;
        unsigned int d2a_rxdp_center_latchi_offsetm_l1 : 8;
        unsigned int d2a_rxdp_center_latchi_offsetp_l1 : 8;
    } reg;
} SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetm_START (0)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetm_END (7)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetp_START (8)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetp_END (15)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetm_l1_START (16)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetm_l1_END (23)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetp_l1_START (24)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_1_d2a_rxdp_center_latchi_offsetp_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_rxdp_center_latchqb_offsetm : 8;
        unsigned int d2a_rxdp_center_latchqb_offsetp : 8;
        unsigned int d2a_rxdp_center_latchqb_offsetm_l1 : 8;
        unsigned int d2a_rxdp_center_latchqb_offsetp_l1 : 8;
    } reg;
} SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetm_START (0)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetm_END (7)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetp_START (8)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetp_END (15)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetm_l1_START (16)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetm_l1_END (23)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetp_l1_START (24)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_2_d2a_rxdp_center_latchqb_offsetp_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_rxdp_center_latchib_offsetm : 8;
        unsigned int d2a_rxdp_center_latchib_offsetp : 8;
        unsigned int d2a_rxdp_center_latchib_offsetm_l1 : 8;
        unsigned int d2a_rxdp_center_latchib_offsetp_l1 : 8;
    } reg;
} SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetm_START (0)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetm_END (7)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetp_START (8)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetp_END (15)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetm_l1_START (16)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetm_l1_END (23)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetp_l1_START (24)
#define SOC_HIPHYIO_PHY_RX_DATAPATH_CTRL_3_d2a_rxdp_center_latchib_offsetp_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_rxlpbk_cml_offsetm : 7;
        unsigned int reserved_0 : 1;
        unsigned int d2a_rxlpbk_cml_offsetp : 7;
        unsigned int d2a_rxlpbk_offset_pwrdnb : 1;
        unsigned int d2a_rxlpbk_latch_offsetcal_enb : 1;
        unsigned int d2a_rxlpbk_cml_pwrdnb : 1;
        unsigned int d2a_rxlpbk_prebuf_pwrdnb : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_cml_offsetm_START (0)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_cml_offsetm_END (6)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_cml_offsetp_START (8)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_cml_offsetp_END (14)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_offset_pwrdnb_START (15)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_offset_pwrdnb_END (15)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_latch_offsetcal_enb_START (16)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_latch_offsetcal_enb_END (16)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_cml_pwrdnb_START (17)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_cml_pwrdnb_END (17)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_prebuf_pwrdnb_START (18)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_d2a_rxlpbk_prebuf_pwrdnb_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_rxlpbk_cml_offsetm_l1 : 7;
        unsigned int reserved_0 : 1;
        unsigned int d2a_rxlpbk_cml_offsetp_l1 : 7;
        unsigned int d2a_rxlpbk_offset_pwrdnb_l1 : 1;
        unsigned int d2a_rxlpbk_latch_offsetcal_enb_l1 : 1;
        unsigned int d2a_rxlpbk_cml_pwrdnb_l1 : 1;
        unsigned int d2a_rxlpbk_prebuf_pwrdnb_l1 : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_cml_offsetm_l1_START (0)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_cml_offsetm_l1_END (6)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_cml_offsetp_l1_START (8)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_cml_offsetp_l1_END (14)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_offset_pwrdnb_l1_START (15)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_offset_pwrdnb_l1_END (15)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_latch_offsetcal_enb_l1_START (16)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_latch_offsetcal_enb_l1_END (16)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_cml_pwrdnb_l1_START (17)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_cml_pwrdnb_l1_END (17)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_prebuf_pwrdnb_l1_START (18)
#define SOC_HIPHYIO_PHY_RX_LOOPBACK_CTRL_L1_d2a_rxlpbk_prebuf_pwrdnb_l1_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_ds_spare : 8;
        unsigned int d2a_rxcp_ctbout_pm_sel : 1;
        unsigned int d2a_rxabe_ctb_sel : 2;
        unsigned int d2a_rxcp_ctb_sel : 2;
        unsigned int d2a_rxatb_top_sel : 3;
        unsigned int d2a_rxlpbk_cml_atbsel : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_ds_spare_START (0)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_ds_spare_END (7)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxcp_ctbout_pm_sel_START (8)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxcp_ctbout_pm_sel_END (8)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxabe_ctb_sel_START (9)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxabe_ctb_sel_END (10)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxcp_ctb_sel_START (11)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxcp_ctb_sel_END (12)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxatb_top_sel_START (13)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxatb_top_sel_END (15)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxlpbk_cml_atbsel_START (16)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_d2a_rxlpbk_cml_atbsel_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_ds_spare_l1 : 8;
        unsigned int d2a_rxcp_ctbout_pm_sel_l1 : 1;
        unsigned int d2a_rxabe_ctb_sel_l1 : 2;
        unsigned int d2a_rxcp_ctb_sel_l1 : 2;
        unsigned int d2a_rxatb_top_sel_l1 : 3;
        unsigned int d2a_rxlpbk_cml_atbsel_l1 : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_UNION;
#endif
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_ds_spare_l1_START (0)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_ds_spare_l1_END (7)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxcp_ctbout_pm_sel_l1_START (8)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxcp_ctbout_pm_sel_l1_END (8)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxabe_ctb_sel_l1_START (9)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxabe_ctb_sel_l1_END (10)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxcp_ctb_sel_l1_START (11)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxcp_ctb_sel_l1_END (12)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxatb_top_sel_l1_START (13)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxatb_top_sel_l1_END (15)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxlpbk_cml_atbsel_l1_START (16)
#define SOC_HIPHYIO_PHY_RX_ATB_CTB_SPARE_CTRL_L1_d2a_rxlpbk_cml_atbsel_l1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_rx_stall_det_l1 : 1;
        unsigned int phy_rx_stall_det_l0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HIPHYIO_PHY_STALL_DET_READ_UNION;
#endif
#define SOC_HIPHYIO_PHY_STALL_DET_READ_phy_rx_stall_det_l1_START (0)
#define SOC_HIPHYIO_PHY_STALL_DET_READ_phy_rx_stall_det_l1_END (0)
#define SOC_HIPHYIO_PHY_STALL_DET_READ_phy_rx_stall_det_l0_START (1)
#define SOC_HIPHYIO_PHY_STALL_DET_READ_phy_rx_stall_det_l0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int se_clk_cal_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_SE_CLK_CAL_START_UNION;
#endif
#define SOC_HIPHYIO_SE_CLK_CAL_START_se_clk_cal_start_START (0)
#define SOC_HIPHYIO_SE_CLK_CAL_START_se_clk_cal_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_sw : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_SW_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_rxcp_dly_cal_sw_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_rxcp_dly_cal_sw_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_vctrl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_rxcp_dly_cal_vctrl_en_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_rxcp_dly_cal_vctrl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_vctrl_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_rxcp_dly_cal_vctrl_sel_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_rxcp_dly_cal_vctrl_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_val : 32;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_VAL_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_rxcp_dly_cal_val_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_rxcp_dly_cal_val_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_out : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_OUT_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_rxcp_dly_cal_out_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_rxcp_dly_cal_out_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_timeout_th : 16;
        unsigned int rxcp_dly_cal_timeout : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_rxcp_dly_cal_timeout_th_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_rxcp_dly_cal_timeout_th_END (15)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_rxcp_dly_cal_timeout_START (16)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_rxcp_dly_cal_timeout_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_direction : 1;
        unsigned int rxcp_dly_cal_trans_max : 4;
        unsigned int rxcp_dly_cal_init_ctrl_code : 5;
        unsigned int rxcp_dly_cal_ctrl_code_min : 5;
        unsigned int rxcp_dly_cal_ctrl_code_max : 5;
        unsigned int rxcp_dly_cal_code_get_type : 3;
        unsigned int rxcp_dly_cal_timer_cnt_thr : 9;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_direction_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_direction_END (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_trans_max_START (1)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_trans_max_END (4)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_init_ctrl_code_START (5)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_init_ctrl_code_END (9)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_ctrl_code_min_START (10)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_ctrl_code_min_END (14)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_ctrl_code_max_START (15)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_ctrl_code_max_END (19)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_code_get_type_START (20)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_code_get_type_END (22)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_timer_cnt_thr_START (23)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_0_rxcp_dly_cal_timer_cnt_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_ctrl : 32;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_1_rxcp_dly_cal_ctrl_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_1_rxcp_dly_cal_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int se_clk_cal_start_l1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_SE_CLK_CAL_START_L1_UNION;
#endif
#define SOC_HIPHYIO_SE_CLK_CAL_START_L1_se_clk_cal_start_l1_START (0)
#define SOC_HIPHYIO_SE_CLK_CAL_START_L1_se_clk_cal_start_l1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_sw_l1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_SW_L1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_L1_rxcp_dly_cal_sw_l1_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_SW_L1_rxcp_dly_cal_sw_l1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_vctrl_en_l1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_L1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_L1_rxcp_dly_cal_vctrl_en_l1_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_EN_L1_rxcp_dly_cal_vctrl_en_l1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_vctrl_sel_l1 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_L1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_L1_rxcp_dly_cal_vctrl_sel_l1_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VCTRL_SEL_L1_rxcp_dly_cal_vctrl_sel_l1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_val_l1 : 32;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_VAL_L1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_L1_rxcp_dly_cal_val_l1_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_VAL_L1_rxcp_dly_cal_val_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_out_l1 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_OUT_L1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_L1_rxcp_dly_cal_out_l1_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_OUT_L1_rxcp_dly_cal_out_l1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 16;
        unsigned int rxcp_dly_cal_timeout_l1 : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_L1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_L1_rxcp_dly_cal_timeout_l1_START (16)
#define SOC_HIPHYIO_RXCP_DLY_CAL_TIMEOUT_L1_rxcp_dly_cal_timeout_l1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_dly_cal_ctrl_l1 : 32;
    } reg;
} SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_L1_UNION;
#endif
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_L1_rxcp_dly_cal_ctrl_l1_START (0)
#define SOC_HIPHYIO_RXCP_DLY_CAL_CTRL_L1_rxcp_dly_cal_ctrl_l1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rc_stall_wait_time : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPHYIO_RATE_CHANGE_CTRL_UNION;
#endif
#define SOC_HIPHYIO_RATE_CHANGE_CTRL_rc_stall_wait_time_START (0)
#define SOC_HIPHYIO_RATE_CHANGE_CTRL_rc_stall_wait_time_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_idle : 1;
        unsigned int gt_clk_rx_trans : 1;
        unsigned int gt_clk_phy_bit : 1;
        unsigned int gt_clk_tx_phy_word : 1;
        unsigned int gt_clk_hio_tx : 1;
        unsigned int gt_clk_hio_rx : 1;
        unsigned int gt_clk_hio_ctrl : 1;
        unsigned int gt_clk_axi_asyncbrg : 1;
        unsigned int gt_clk_asp : 1;
        unsigned int gt_clk_hio : 1;
        unsigned int gt_clk_spi_0 : 1;
        unsigned int gt_clk_spi_1 : 1;
        unsigned int gt_clk_spi_2 : 1;
        unsigned int gt_clk_spi_3 : 1;
        unsigned int gt_clk_spi_4 : 1;
        unsigned int gt_clk_spi_5 : 1;
        unsigned int gt_clk_spi_6 : 1;
        unsigned int gt_clk_spi_7 : 1;
        unsigned int gt_clk_i2s_0 : 1;
        unsigned int gt_clk_i2s_1 : 1;
        unsigned int gt_clk_dfx : 1;
        unsigned int gt_clk_cal : 1;
        unsigned int gt_clk_test_pll : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_HIPHYIO_CRG_GT_CTRL_UNION;
#endif
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_idle_START (0)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_idle_END (0)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_rx_trans_START (1)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_rx_trans_END (1)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_phy_bit_START (2)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_phy_bit_END (2)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_tx_phy_word_START (3)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_tx_phy_word_END (3)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_tx_START (4)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_tx_END (4)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_rx_START (5)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_rx_END (5)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_ctrl_START (6)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_ctrl_END (6)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_axi_asyncbrg_START (7)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_axi_asyncbrg_END (7)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_asp_START (8)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_asp_END (8)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_START (9)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_hio_END (9)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_0_START (10)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_0_END (10)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_1_START (11)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_1_END (11)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_2_START (12)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_2_END (12)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_3_START (13)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_3_END (13)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_4_START (14)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_4_END (14)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_5_START (15)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_5_END (15)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_6_START (16)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_6_END (16)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_7_START (17)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_spi_7_END (17)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_i2s_0_START (18)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_i2s_0_END (18)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_i2s_1_START (19)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_i2s_1_END (19)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_dfx_START (20)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_dfx_END (20)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_cal_START (21)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_cal_END (21)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_test_pll_START (22)
#define SOC_HIPHYIO_CRG_GT_CTRL_gt_clk_test_pll_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_idle : 1;
        unsigned int st_clk_rx_trans : 1;
        unsigned int st_clk_phy_bit : 1;
        unsigned int st_clk_tx_phy_word : 1;
        unsigned int st_clk_hio_tx : 1;
        unsigned int st_clk_hio_rx : 1;
        unsigned int st_clk_hio_ctrl : 1;
        unsigned int st_clk_axi_asyncbrg : 1;
        unsigned int st_clk_asp : 1;
        unsigned int st_clk_hio : 1;
        unsigned int st_clk_spi_0 : 1;
        unsigned int st_clk_spi_1 : 1;
        unsigned int st_clk_spi_2 : 1;
        unsigned int st_clk_spi_3 : 1;
        unsigned int st_clk_spi_4 : 1;
        unsigned int st_clk_spi_5 : 1;
        unsigned int st_clk_spi_6 : 1;
        unsigned int st_clk_spi_7 : 1;
        unsigned int st_clk_i2s_0 : 1;
        unsigned int st_clk_i2s_1 : 1;
        unsigned int st_clk_apb : 1;
        unsigned int st_clk_dfx : 1;
        unsigned int st_clk_cal : 1;
        unsigned int st_clk_test_pll : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPHYIO_CRG_GT_STATUS_UNION;
#endif
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_idle_START (0)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_idle_END (0)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_rx_trans_START (1)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_rx_trans_END (1)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_phy_bit_START (2)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_phy_bit_END (2)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_tx_phy_word_START (3)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_tx_phy_word_END (3)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_tx_START (4)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_tx_END (4)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_rx_START (5)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_rx_END (5)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_ctrl_START (6)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_ctrl_END (6)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_axi_asyncbrg_START (7)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_axi_asyncbrg_END (7)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_asp_START (8)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_asp_END (8)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_START (9)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_hio_END (9)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_0_START (10)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_0_END (10)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_1_START (11)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_1_END (11)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_2_START (12)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_2_END (12)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_3_START (13)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_3_END (13)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_4_START (14)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_4_END (14)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_5_START (15)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_5_END (15)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_6_START (16)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_6_END (16)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_7_START (17)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_spi_7_END (17)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_i2s_0_START (18)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_i2s_0_END (18)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_i2s_1_START (19)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_i2s_1_END (19)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_apb_START (20)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_apb_END (20)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_dfx_START (21)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_dfx_END (21)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_cal_START (22)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_cal_END (22)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_test_pll_START (23)
#define SOC_HIPHYIO_CRG_GT_STATUS_st_clk_test_pll_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hio_spi_0_se : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_hio_spi_1_se : 6;
        unsigned int reserved_1 : 2;
        unsigned int div_hio_spi_2_se : 6;
        unsigned int reserved_2 : 2;
        unsigned int div_hio_spi_3_se : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_HIPHYIO_CRG_DIV_SE_CTRL0_UNION;
#endif
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_0_se_START (0)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_0_se_END (5)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_1_se_START (8)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_1_se_END (13)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_2_se_START (16)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_2_se_END (21)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_3_se_START (24)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL0_div_hio_spi_3_se_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hio_spi_4_se : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_hio_spi_5_se : 6;
        unsigned int reserved_1 : 2;
        unsigned int div_hio_spi_6_se : 6;
        unsigned int reserved_2 : 2;
        unsigned int div_hio_spi_7_se : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_HIPHYIO_CRG_DIV_SE_CTRL1_UNION;
#endif
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_4_se_START (0)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_4_se_END (5)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_5_se_START (8)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_5_se_END (13)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_6_se_START (16)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_6_se_END (21)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_7_se_START (24)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL1_div_hio_spi_7_se_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hio_asp_se : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_hio_ctrl_se : 5;
        unsigned int reserved_1 : 3;
        unsigned int div_hio_tx_phy_word_se : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_HIPHYIO_CRG_DIV_SE_CTRL2_UNION;
#endif
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_div_hio_asp_se_START (0)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_div_hio_asp_se_END (5)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_div_hio_ctrl_se_START (8)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_div_hio_ctrl_se_END (12)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_div_hio_tx_phy_word_se_START (16)
#define SOC_HIPHYIO_CRG_DIV_SE_CTRL2_div_hio_tx_phy_word_se_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swdone_clk_tx_phy_word_div : 1;
        unsigned int swdone_clk_hio_ctrl : 1;
        unsigned int swdone_clk_hio_asp_div : 1;
        unsigned int swdone_clk_hio_spi_0_div : 1;
        unsigned int swdone_clk_hio_spi_1_div : 1;
        unsigned int swdone_clk_hio_spi_2_div : 1;
        unsigned int swdone_clk_hio_spi_3_div : 1;
        unsigned int swdone_clk_hio_spi_4_div : 1;
        unsigned int swdone_clk_hio_spi_5_div : 1;
        unsigned int swdone_clk_hio_spi_6_div : 1;
        unsigned int swdone_clk_hio_spi_7_div : 1;
        unsigned int swdone_clk_hio_spi_fix : 1;
        unsigned int swdone_clk_rx_trans_div : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_CRG_DIV_STATUS_UNION;
#endif
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_tx_phy_word_div_START (0)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_tx_phy_word_div_END (0)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_ctrl_START (1)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_ctrl_END (1)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_asp_div_START (2)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_asp_div_END (2)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_0_div_START (3)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_0_div_END (3)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_1_div_START (4)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_1_div_END (4)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_2_div_START (5)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_2_div_END (5)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_3_div_START (6)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_3_div_END (6)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_4_div_START (7)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_4_div_END (7)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_5_div_START (8)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_5_div_END (8)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_6_div_START (9)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_6_div_END (9)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_7_div_START (10)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_7_div_END (10)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_fix_START (11)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_hio_spi_fix_END (11)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_rx_trans_div_START (12)
#define SOC_HIPHYIO_CRG_DIV_STATUS_swdone_clk_rx_trans_div_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_sys : 1;
        unsigned int rst_pcs : 1;
        unsigned int rst_32k : 1;
        unsigned int rst_hio_ctrl : 1;
        unsigned int rst_tst : 1;
        unsigned int rst_lss : 1;
        unsigned int rst_axi : 1;
        unsigned int rst_i2s : 1;
        unsigned int rst_spi : 1;
        unsigned int rst_link : 1;
        unsigned int rst_apb : 1;
        unsigned int rst_cal : 1;
        unsigned int rst_spi_0 : 1;
        unsigned int rst_spi_1 : 1;
        unsigned int rst_spi_2 : 1;
        unsigned int rst_spi_3 : 1;
        unsigned int rst_spi_4 : 1;
        unsigned int rst_spi_5 : 1;
        unsigned int rst_spi_6 : 1;
        unsigned int rst_spi_7 : 1;
        unsigned int rst_i2s_0 : 1;
        unsigned int rst_i2s_1 : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_HIPHYIO_CRG_RST_CTRL_UNION;
#endif
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_sys_START (0)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_sys_END (0)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_pcs_START (1)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_pcs_END (1)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_32k_START (2)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_32k_END (2)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_hio_ctrl_START (3)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_hio_ctrl_END (3)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_tst_START (4)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_tst_END (4)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_lss_START (5)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_lss_END (5)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_axi_START (6)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_axi_END (6)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_i2s_START (7)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_i2s_END (7)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_START (8)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_END (8)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_link_START (9)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_link_END (9)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_apb_START (10)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_apb_END (10)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_cal_START (11)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_cal_END (11)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_0_START (12)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_0_END (12)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_1_START (13)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_1_END (13)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_2_START (14)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_2_END (14)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_3_START (15)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_3_END (15)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_4_START (16)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_4_END (16)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_5_START (17)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_5_END (17)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_6_START (18)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_6_END (18)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_7_START (19)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_spi_7_END (19)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_i2s_0_START (20)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_i2s_0_END (20)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_i2s_1_START (21)
#define SOC_HIPHYIO_CRG_RST_CTRL_rst_i2s_1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int sel_hio_lp : 3;
        unsigned int sel_hio_lp_en : 1;
        unsigned int ck_off_sc_sync : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_HIPHYIO_CRG_CLK_MUX_CTRL_UNION;
#endif
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_sel_hio_lp_START (4)
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_sel_hio_lp_END (6)
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_sel_hio_lp_en_START (7)
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_sel_hio_lp_en_END (7)
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_ck_off_sc_sync_START (8)
#define SOC_HIPHYIO_CRG_CLK_MUX_CTRL_ck_off_sc_sync_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_sel_hio_ctrl_gt : 1;
        unsigned int clk_sel_link_rx : 1;
        unsigned int clk_sel_link_tx : 1;
        unsigned int clk_sel_inf_apb_gt : 1;
        unsigned int clk_sel_inf_rx_tst : 1;
        unsigned int clk_sel_inf_rx_lss : 1;
        unsigned int clk_sel_inf_rx_spi : 1;
        unsigned int clk_sel_inf_rx_i2s : 1;
        unsigned int clk_sel_inf_rx_axi : 1;
        unsigned int clk_sel_inf_tx_tst : 1;
        unsigned int clk_sel_inf_tx_lss : 1;
        unsigned int clk_sel_inf_tx_axi : 1;
        unsigned int clk_sel_phy_word_gt : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_CRG_CLK_SEL_CTRL_UNION;
#endif
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_hio_ctrl_gt_START (0)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_hio_ctrl_gt_END (0)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_link_rx_START (1)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_link_rx_END (1)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_link_tx_START (2)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_link_tx_END (2)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_apb_gt_START (3)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_apb_gt_END (3)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_tst_START (4)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_tst_END (4)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_lss_START (5)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_lss_END (5)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_spi_START (6)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_spi_END (6)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_i2s_START (7)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_i2s_END (7)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_axi_START (8)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_rx_axi_END (8)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_tx_tst_START (9)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_tx_tst_END (9)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_tx_lss_START (10)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_tx_lss_END (10)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_tx_axi_START (11)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_inf_tx_axi_END (11)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_phy_word_gt_START (12)
#define SOC_HIPHYIO_CRG_CLK_SEL_CTRL_clk_sel_phy_word_gt_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int auto_clk_en_hio_ctrl_gt : 1;
        unsigned int auto_clk_en_link_rx : 1;
        unsigned int auto_clk_en_link_tx : 1;
        unsigned int auto_clk_en_inf_apb_gt : 1;
        unsigned int auto_clk_en_inf_rx_tst : 1;
        unsigned int auto_clk_en_inf_rx_lss : 1;
        unsigned int auto_clk_en_inf_rx_spi : 1;
        unsigned int auto_clk_en_inf_rx_i2s : 1;
        unsigned int auto_clk_en_inf_rx_axi : 1;
        unsigned int auto_clk_en_inf_tx_tst : 1;
        unsigned int auto_clk_en_inf_tx_lss : 1;
        unsigned int auto_clk_en_inf_tx_axi : 1;
        unsigned int auto_clk_en_phy_word_gt : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_UNION;
#endif
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_hio_ctrl_gt_START (0)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_hio_ctrl_gt_END (0)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_link_rx_START (1)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_link_rx_END (1)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_link_tx_START (2)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_link_tx_END (2)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_apb_gt_START (3)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_apb_gt_END (3)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_tst_START (4)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_tst_END (4)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_lss_START (5)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_lss_END (5)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_spi_START (6)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_spi_END (6)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_i2s_START (7)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_i2s_END (7)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_axi_START (8)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_rx_axi_END (8)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_tx_tst_START (9)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_tx_tst_END (9)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_tx_lss_START (10)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_tx_lss_END (10)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_tx_axi_START (11)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_inf_tx_axi_END (11)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_phy_word_gt_START (12)
#define SOC_HIPHYIO_CRG_ATUO_CLK_EN_CTRL_auto_clk_en_phy_word_gt_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_status_hio_ctrl_gt : 1;
        unsigned int clk_status_link_rx : 1;
        unsigned int clk_status_link_tx : 1;
        unsigned int clk_status_inf_apb_gt : 1;
        unsigned int clk_status_inf_rx_tst : 1;
        unsigned int clk_status_inf_rx_lss : 1;
        unsigned int clk_status_inf_rx_spi : 1;
        unsigned int clk_status_inf_rx_i2s : 1;
        unsigned int clk_status_inf_rx_axi : 1;
        unsigned int clk_status_inf_tx_tst : 1;
        unsigned int clk_status_inf_tx_lss : 1;
        unsigned int clk_status_inf_tx_axi : 1;
        unsigned int clk_status_phy_word_gt : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_UNION;
#endif
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_hio_ctrl_gt_START (0)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_hio_ctrl_gt_END (0)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_link_rx_START (1)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_link_rx_END (1)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_link_tx_START (2)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_link_tx_END (2)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_apb_gt_START (3)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_apb_gt_END (3)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_tst_START (4)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_tst_END (4)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_lss_START (5)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_lss_END (5)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_spi_START (6)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_spi_END (6)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_i2s_START (7)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_i2s_END (7)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_axi_START (8)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_rx_axi_END (8)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_tx_tst_START (9)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_tx_tst_END (9)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_tx_lss_START (10)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_tx_lss_END (10)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_tx_axi_START (11)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_inf_tx_axi_END (11)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_phy_word_gt_START (12)
#define SOC_HIPHYIO_CRG_ATUO_CLK_STATUS_clk_status_phy_word_gt_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_en : 1;
        unsigned int pll_bp : 1;
        unsigned int pll_refdiv : 6;
        unsigned int pll_fbdiv : 12;
        unsigned int pll_postdiv1 : 3;
        unsigned int pll_postdiv2 : 3;
        unsigned int pll_lock : 1;
        unsigned int pll_cfg_en_sw : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_HIPHYIO_PLL_HIO_CTRL0_UNION;
#endif
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_en_START (0)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_en_END (0)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_bp_START (1)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_bp_END (1)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_refdiv_START (2)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_refdiv_END (7)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_fbdiv_START (8)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_fbdiv_END (19)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_postdiv1_START (20)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_postdiv1_END (22)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_postdiv2_START (23)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_postdiv2_END (25)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_lock_START (26)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_lock_END (26)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_cfg_en_sw_START (27)
#define SOC_HIPHYIO_PLL_HIO_CTRL0_pll_cfg_en_sw_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_fracdiv : 24;
        unsigned int pll_int_mod : 1;
        unsigned int pll_cfg_vld : 1;
        unsigned int gt_clk_pll : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_HIPHYIO_PLL_HIO_CTRL1_UNION;
#endif
#define SOC_HIPHYIO_PLL_HIO_CTRL1_pll_fracdiv_START (0)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_pll_fracdiv_END (23)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_pll_int_mod_START (24)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_pll_int_mod_END (24)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_pll_cfg_vld_START (25)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_pll_cfg_vld_END (25)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_gt_clk_pll_START (26)
#define SOC_HIPHYIO_PLL_HIO_CTRL1_gt_clk_pll_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG0 : 32;
    } reg;
} SOC_HIPHYIO_FNPLL_CFG0_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_CFG0_FNPLL_CFG0_START (0)
#define SOC_HIPHYIO_FNPLL_CFG0_FNPLL_CFG0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG1 : 32;
    } reg;
} SOC_HIPHYIO_FNPLL_CFG1_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_CFG1_FNPLL_CFG1_START (0)
#define SOC_HIPHYIO_FNPLL_CFG1_FNPLL_CFG1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG2 : 32;
    } reg;
} SOC_HIPHYIO_FNPLL_CFG2_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_CFG2_FNPLL_CFG2_START (0)
#define SOC_HIPHYIO_FNPLL_CFG2_FNPLL_CFG2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG3 : 32;
    } reg;
} SOC_HIPHYIO_FNPLL_CFG3_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_CFG3_FNPLL_CFG3_START (0)
#define SOC_HIPHYIO_FNPLL_CFG3_FNPLL_CFG3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_STATE0 : 32;
    } reg;
} SOC_HIPHYIO_FNPLL_STATE0_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_STATE0_FNPLL_STATE0_START (0)
#define SOC_HIPHYIO_FNPLL_STATE0_FNPLL_STATE0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_en_stat : 1;
        unsigned int pll_sscg_idle : 1;
        unsigned int st_clk_pll_sscg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HIPHYIO_FNPLL_STATE1_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_STATE1_pll_en_stat_START (0)
#define SOC_HIPHYIO_FNPLL_STATE1_pll_en_stat_END (0)
#define SOC_HIPHYIO_FNPLL_STATE1_pll_sscg_idle_START (1)
#define SOC_HIPHYIO_FNPLL_STATE1_pll_sscg_idle_END (1)
#define SOC_HIPHYIO_FNPLL_STATE1_st_clk_pll_sscg_START (2)
#define SOC_HIPHYIO_FNPLL_STATE1_st_clk_pll_sscg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_gt_cfg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_ULPPLL_GT_CFG_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_GT_CFG_ulppll_gt_cfg_START (0)
#define SOC_HIPHYIO_ULPPLL_GT_CFG_ulppll_gt_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg0 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG0_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG0_ulppll_cfg0_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG0_ulppll_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg1 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG1_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG1_ulppll_cfg1_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG1_ulppll_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg2 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG2_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG2_ulppll_cfg2_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG2_ulppll_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg3 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG3_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG3_ulppll_cfg3_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG3_ulppll_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg4 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG4_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG4_ulppll_cfg4_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG4_ulppll_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg5 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG5_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG5_ulppll_cfg5_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG5_ulppll_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg6 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG6_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG6_ulppll_cfg6_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG6_ulppll_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg7 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG7_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG7_ulppll_cfg7_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG7_ulppll_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg8 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_CFG8_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CFG8_ulppll_cfg8_START (0)
#define SOC_HIPHYIO_ULPPLL_CFG8_ulppll_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_en : 1;
        unsigned int ulppll_bypass : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int ulppll_fbdiv : 15;
        unsigned int ulppll_cfg_en_sw : 1;
        unsigned int ulppll_en_hw_sw : 1;
        unsigned int reserved_3 : 7;
    } reg;
} SOC_HIPHYIO_ULPPLL_CTRL0_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_en_START (0)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_en_END (0)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_bypass_START (1)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_bypass_END (1)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_fbdiv_START (8)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_fbdiv_END (22)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_cfg_en_sw_START (23)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_cfg_en_sw_END (23)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_en_hw_sw_START (24)
#define SOC_HIPHYIO_ULPPLL_CTRL0_ulppll_en_hw_sw_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_stat0 : 32;
    } reg;
} SOC_HIPHYIO_ULPPLL_STATE0_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_STATE0_ulppll_stat0_START (0)
#define SOC_HIPHYIO_ULPPLL_STATE0_ulppll_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_ULPPLL_STATE1_UNION;
#endif
#define SOC_HIPHYIO_ULPPLL_STATE1_ulppll_lock_START (0)
#define SOC_HIPHYIO_ULPPLL_STATE1_ulppll_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hio_spi_0_dif : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_hio_spi_1_dif : 6;
        unsigned int reserved_1 : 2;
        unsigned int div_hio_spi_2_dif : 6;
        unsigned int reserved_2 : 2;
        unsigned int div_hio_spi_3_dif : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_UNION;
#endif
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_0_dif_START (0)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_0_dif_END (5)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_1_dif_START (8)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_1_dif_END (13)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_2_dif_START (16)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_2_dif_END (21)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_3_dif_START (24)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL0_div_hio_spi_3_dif_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hio_spi_4_dif : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_hio_spi_5_dif : 6;
        unsigned int reserved_1 : 2;
        unsigned int div_hio_spi_6_dif : 6;
        unsigned int reserved_2 : 2;
        unsigned int div_hio_spi_7_dif : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_UNION;
#endif
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_4_dif_START (0)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_4_dif_END (5)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_5_dif_START (8)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_5_dif_END (13)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_6_dif_START (16)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_6_dif_END (21)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_7_dif_START (24)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL1_div_hio_spi_7_dif_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hio_asp_dif : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_hio_ctrl_dif : 5;
        unsigned int reserved_1 : 3;
        unsigned int div_hio_tx_phy_word_dif : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_UNION;
#endif
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_div_hio_asp_dif_START (0)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_div_hio_asp_dif_END (5)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_div_hio_ctrl_dif_START (8)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_div_hio_ctrl_dif_END (12)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_div_hio_tx_phy_word_dif_START (16)
#define SOC_HIPHYIO_CRG_DIV_DIF_CTRL2_div_hio_tx_phy_word_dif_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_test_pll : 6;
        unsigned int reserved_0 : 2;
        unsigned int test_pll_sel : 1;
        unsigned int swdone_clk_test_pll : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_HIPHYIO_CRG_TEST_PLL_CTRL_UNION;
#endif
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_div_test_pll_START (0)
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_div_test_pll_END (5)
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_test_pll_sel_START (8)
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_test_pll_sel_END (8)
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_swdone_clk_test_pll_START (9)
#define SOC_HIPHYIO_CRG_TEST_PLL_CTRL_swdone_clk_test_pll_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl0 : 32;
    } reg;
} SOC_HIPHYIO_RSV_CTRL0_UNION;
#endif
#define SOC_HIPHYIO_RSV_CTRL0_sts_reserved_ctrl0_START (0)
#define SOC_HIPHYIO_RSV_CTRL0_sts_reserved_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl1 : 32;
    } reg;
} SOC_HIPHYIO_RSV_CTRL1_UNION;
#endif
#define SOC_HIPHYIO_RSV_CTRL1_sts_reserved_ctrl1_START (0)
#define SOC_HIPHYIO_RSV_CTRL1_sts_reserved_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl2 : 32;
    } reg;
} SOC_HIPHYIO_RSV_CTRL2_UNION;
#endif
#define SOC_HIPHYIO_RSV_CTRL2_sts_reserved_ctrl2_START (0)
#define SOC_HIPHYIO_RSV_CTRL2_sts_reserved_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl3 : 32;
    } reg;
} SOC_HIPHYIO_RSV_CTRL3_UNION;
#endif
#define SOC_HIPHYIO_RSV_CTRL3_sts_reserved_ctrl3_START (0)
#define SOC_HIPHYIO_RSV_CTRL3_sts_reserved_ctrl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_counter_0 : 32;
    } reg;
} SOC_HIPHYIO_DFX_COUNTER_0_UNION;
#endif
#define SOC_HIPHYIO_DFX_COUNTER_0_dfx_counter_0_START (0)
#define SOC_HIPHYIO_DFX_COUNTER_0_dfx_counter_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_counter_1 : 32;
    } reg;
} SOC_HIPHYIO_DFX_COUNTER_1_UNION;
#endif
#define SOC_HIPHYIO_DFX_COUNTER_1_dfx_counter_1_START (0)
#define SOC_HIPHYIO_DFX_COUNTER_1_dfx_counter_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_counter_2 : 32;
    } reg;
} SOC_HIPHYIO_DFX_COUNTER_2_UNION;
#endif
#define SOC_HIPHYIO_DFX_COUNTER_2_dfx_counter_2_START (0)
#define SOC_HIPHYIO_DFX_COUNTER_2_dfx_counter_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_counter_3 : 32;
    } reg;
} SOC_HIPHYIO_DFX_COUNTER_3_UNION;
#endif
#define SOC_HIPHYIO_DFX_COUNTER_3_dfx_counter_3_START (0)
#define SOC_HIPHYIO_DFX_COUNTER_3_dfx_counter_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_lss_rx_buffer_num : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPHYIO_LSS_RX_STATUS2_UNION;
#endif
#define SOC_HIPHYIO_LSS_RX_STATUS2_dfx_lss_rx_buffer_num_START (0)
#define SOC_HIPHYIO_LSS_RX_STATUS2_dfx_lss_rx_buffer_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_axi_wrsp_block : 1;
        unsigned int dfx_axi_wreq_block : 1;
        unsigned int dfx_axi_wrsp_block_rcv : 1;
        unsigned int dfx_axi_wreq_block_rcv : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HIPHYIO_DFX_AXI_W_BLOCK_UNION;
#endif
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wrsp_block_START (0)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wrsp_block_END (0)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wreq_block_START (1)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wreq_block_END (1)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wrsp_block_rcv_START (2)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wrsp_block_rcv_END (2)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wreq_block_rcv_START (3)
#define SOC_HIPHYIO_DFX_AXI_W_BLOCK_dfx_axi_wreq_block_rcv_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_axi_rrsp_block : 1;
        unsigned int dfx_axi_rreq_block : 1;
        unsigned int dfx_axi_rrsp_block_rcv : 1;
        unsigned int dfx_axi_rreq_block_rcv : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HIPHYIO_DFX_AXI_R_BLOCK_UNION;
#endif
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rrsp_block_START (0)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rrsp_block_END (0)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rreq_block_START (1)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rreq_block_END (1)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rrsp_block_rcv_START (2)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rrsp_block_rcv_END (2)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rreq_block_rcv_START (3)
#define SOC_HIPHYIO_DFX_AXI_R_BLOCK_dfx_axi_rreq_block_rcv_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_linktx2inf_ready : 1;
        unsigned int dfx_inf2linktx_valid : 1;
        unsigned int dfx_pcstx2linktx_ready : 2;
        unsigned int dfx_linktx2pcstx_valid : 2;
        unsigned int dfx_pcstx2phy_ctrl_valid : 2;
        unsigned int dfx_pcs_rx_eob_valid : 2;
        unsigned int dfx_pcsrx2linkrx_valid : 2;
        unsigned int dfx_linkrx2inf_valid : 1;
        unsigned int dfx_rx_pkt_rt_r2p_rx_cs : 8;
        unsigned int reserved : 11;
    } reg;
} SOC_HIPHYIO_DFX_VALID_READY_UNION;
#endif
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_linktx2inf_ready_START (0)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_linktx2inf_ready_END (0)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_inf2linktx_valid_START (1)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_inf2linktx_valid_END (1)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcstx2linktx_ready_START (2)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcstx2linktx_ready_END (3)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_linktx2pcstx_valid_START (4)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_linktx2pcstx_valid_END (5)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcstx2phy_ctrl_valid_START (6)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcstx2phy_ctrl_valid_END (7)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcs_rx_eob_valid_START (8)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcs_rx_eob_valid_END (9)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcsrx2linkrx_valid_START (10)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_pcsrx2linkrx_valid_END (11)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_linkrx2inf_valid_START (12)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_linkrx2inf_valid_END (12)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_rx_pkt_rt_r2p_rx_cs_START (13)
#define SOC_HIPHYIO_DFX_VALID_READY_dfx_rx_pkt_rt_r2p_rx_cs_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tstpat2arb_valid : 1;
        unsigned int dfx_arb2tstpat_ready : 1;
        unsigned int dfx_lss2arb_valid : 1;
        unsigned int dfx_arb2lss_ready : 1;
        unsigned int dfx_spi2arb_valid : 1;
        unsigned int dfx_arb2spi_ready : 1;
        unsigned int dfx_i2s2arb_valid : 1;
        unsigned int dfx_arb2i2s_ready : 1;
        unsigned int dfx_axi2arb_valid : 1;
        unsigned int dfx_arb2axi_ready : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPHYIO_DFX_TX_ARB_UNION;
#endif
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_tstpat2arb_valid_START (0)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_tstpat2arb_valid_END (0)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2tstpat_ready_START (1)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2tstpat_ready_END (1)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_lss2arb_valid_START (2)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_lss2arb_valid_END (2)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2lss_ready_START (3)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2lss_ready_END (3)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_spi2arb_valid_START (4)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_spi2arb_valid_END (4)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2spi_ready_START (5)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2spi_ready_END (5)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_i2s2arb_valid_START (6)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_i2s2arb_valid_END (6)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2i2s_ready_START (7)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2i2s_ready_END (7)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_axi2arb_valid_START (8)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_axi2arb_valid_END (8)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2axi_ready_START (9)
#define SOC_HIPHYIO_DFX_TX_ARB_dfx_arb2axi_ready_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hio_testpoint_sel : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPHYIO_TESTPOINT_SEL_UNION;
#endif
#define SOC_HIPHYIO_TESTPOINT_SEL_hio_testpoint_sel_START (0)
#define SOC_HIPHYIO_TESTPOINT_SEL_hio_testpoint_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_fatal_err_block_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_ARB_FATAL_BLOCK_EN_UNION;
#endif
#define SOC_HIPHYIO_ARB_FATAL_BLOCK_EN_intr_fatal_err_block_en_START (0)
#define SOC_HIPHYIO_ARB_FATAL_BLOCK_EN_intr_fatal_err_block_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tx_phy_state : 3;
        unsigned int reserved_0 : 1;
        unsigned int dfx_rx_phy_state : 3;
        unsigned int reserved_1 : 1;
        unsigned int dfx_sleep_state : 3;
        unsigned int reserved_2 : 1;
        unsigned int dfx_rc_state : 4;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_HIPHYIO_DFX_CTRL_STATE_UNION;
#endif
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_tx_phy_state_START (0)
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_tx_phy_state_END (2)
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_rx_phy_state_START (4)
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_rx_phy_state_END (6)
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_sleep_state_START (8)
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_sleep_state_END (10)
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_rc_state_START (12)
#define SOC_HIPHYIO_DFX_CTRL_STATE_dfx_rc_state_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tx_block : 1;
        unsigned int dfx_tx_block_rc : 1;
        unsigned int dfx_tx_block_eob : 1;
        unsigned int dfx_tx_idle_block_rc : 1;
        unsigned int dfx_ulppll_en : 1;
        unsigned int dfx_fnpll_en : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HIPHYIO_DFX_CTRL_SIG_UNION;
#endif
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_block_START (0)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_block_END (0)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_block_rc_START (1)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_block_rc_END (1)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_block_eob_START (2)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_block_eob_END (2)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_idle_block_rc_START (3)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_tx_idle_block_rc_END (3)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_ulppll_en_START (4)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_ulppll_en_END (4)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_fnpll_en_START (5)
#define SOC_HIPHYIO_DFX_CTRL_SIG_dfx_fnpll_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ctrl_rc_busy : 1;
        unsigned int dfx_axipack_wreq_busy : 1;
        unsigned int dfx_axipack_rreq_busy : 1;
        unsigned int dfx_axipack_wrsp_busy : 1;
        unsigned int dfx_axipack_rrsp_busy : 1;
        unsigned int dfx_axi_rx_wreq_busy : 1;
        unsigned int dfx_axi_rx_rrsp_busy : 1;
        unsigned int dfx_axi_rx_wrsp_busy : 1;
        unsigned int dfx_crg_apb_wake : 1;
        unsigned int dfx_crg_axi_rx_wake : 1;
        unsigned int dfx_crg_rx_wake : 1;
        unsigned int dfx_ctrl_tx_busy : 1;
        unsigned int dfx_ctrl_rx_busy : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HIPHYIO_DFX_CRG_BUSY_SIG_UNION;
#endif
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_ctrl_rc_busy_START (0)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_ctrl_rc_busy_END (0)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_wreq_busy_START (1)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_wreq_busy_END (1)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_rreq_busy_START (2)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_rreq_busy_END (2)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_wrsp_busy_START (3)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_wrsp_busy_END (3)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_rrsp_busy_START (4)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axipack_rrsp_busy_END (4)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axi_rx_wreq_busy_START (5)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axi_rx_wreq_busy_END (5)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axi_rx_rrsp_busy_START (6)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axi_rx_rrsp_busy_END (6)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axi_rx_wrsp_busy_START (7)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_axi_rx_wrsp_busy_END (7)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_crg_apb_wake_START (8)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_crg_apb_wake_END (8)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_crg_axi_rx_wake_START (9)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_crg_axi_rx_wake_END (9)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_crg_rx_wake_START (10)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_crg_rx_wake_END (10)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_ctrl_tx_busy_START (11)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_ctrl_tx_busy_END (11)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_ctrl_rx_busy_START (12)
#define SOC_HIPHYIO_DFX_CRG_BUSY_SIG_dfx_ctrl_rx_busy_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_axi_timeout_addr_w_l : 32;
    } reg;
} SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_L_UNION;
#endif
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_L_debug_axi_timeout_addr_w_l_START (0)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_L_debug_axi_timeout_addr_w_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_axi_timeout_addr_w_h : 32;
    } reg;
} SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_H_UNION;
#endif
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_H_debug_axi_timeout_addr_w_h_START (0)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_W_H_debug_axi_timeout_addr_w_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_axi_timeout_addr_r_l : 32;
    } reg;
} SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_L_UNION;
#endif
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_L_debug_axi_timeout_addr_r_l_START (0)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_L_debug_axi_timeout_addr_r_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_axi_timeout_addr_r_h : 32;
    } reg;
} SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_H_UNION;
#endif
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_H_debug_axi_timeout_addr_r_h_START (0)
#define SOC_HIPHYIO_AXI_TIMEOUT_ADDR_R_H_debug_axi_timeout_addr_r_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_axi_timeout_mid_w : 16;
        unsigned int debug_axi_timeout_mid_r : 16;
    } reg;
} SOC_HIPHYIO_AXI_TIMEOUT_MID_UNION;
#endif
#define SOC_HIPHYIO_AXI_TIMEOUT_MID_debug_axi_timeout_mid_w_START (0)
#define SOC_HIPHYIO_AXI_TIMEOUT_MID_debug_axi_timeout_mid_w_END (15)
#define SOC_HIPHYIO_AXI_TIMEOUT_MID_debug_axi_timeout_mid_r_START (16)
#define SOC_HIPHYIO_AXI_TIMEOUT_MID_debug_axi_timeout_mid_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_iodie_sw : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_IODIE_RESET_SW_UNION;
#endif
#define SOC_HIPHYIO_IODIE_RESET_SW_rst_iodie_sw_START (0)
#define SOC_HIPHYIO_IODIE_RESET_SW_rst_iodie_sw_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiphyio_mid_table_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_MID_TABLE_LOCK_UNION;
#endif
#define SOC_HIPHYIO_MID_TABLE_LOCK_hiphyio_mid_table_lock_START (0)
#define SOC_HIPHYIO_MID_TABLE_LOCK_hiphyio_mid_table_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iodie_lp_vote_gp0_gp7 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE0_UNION;
#endif
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE0_iodie_lp_vote_gp0_gp7_START (0)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE0_iodie_lp_vote_gp0_gp7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iodie_lp_vote_gp8_gp15 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE1_UNION;
#endif
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE1_iodie_lp_vote_gp8_gp15_START (0)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE1_iodie_lp_vote_gp8_gp15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iodie_lp_vote_gp16_gp23 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE2_UNION;
#endif
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE2_iodie_lp_vote_gp16_gp23_START (0)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE2_iodie_lp_vote_gp16_gp23_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iodie_lp_vote_gp24_gp31 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE3_UNION;
#endif
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE3_iodie_lp_vote_gp24_gp31_START (0)
#define SOC_HIPHYIO_BITMSK_NONSEC_CTRL_HIPHY_IODIE_VOTE3_iodie_lp_vote_gp24_gp31_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iodie_peri_status : 1;
        unsigned int iodie_hiphy_status : 1;
        unsigned int iodie_peri_vote_status : 1;
        unsigned int iodie_hiphy_vote_status : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_UNION;
#endif
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_peri_status_START (0)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_peri_status_END (0)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_hiphy_status_START (1)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_hiphy_status_END (1)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_peri_vote_status_START (2)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_peri_vote_status_END (2)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_hiphy_vote_status_START (3)
#define SOC_HIPHYIO_HIPHY_IODIE_LP_STATUS_iodie_hiphy_vote_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fnpll_en_hw_sw : 1;
        unsigned int reserved_0 : 3;
        unsigned int fnpll_en_min_gap : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HIPHYIO_FNPLL_CTRL_HW_SW_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_CTRL_HW_SW_fnpll_en_hw_sw_START (0)
#define SOC_HIPHYIO_FNPLL_CTRL_HW_SW_fnpll_en_hw_sw_END (0)
#define SOC_HIPHYIO_FNPLL_CTRL_HW_SW_fnpll_en_min_gap_START (4)
#define SOC_HIPHYIO_FNPLL_CTRL_HW_SW_fnpll_en_min_gap_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fnpll_lock_masked : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIPHYIO_FNPLL_SHADOW_READ_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_SHADOW_READ_fnpll_lock_masked_START (0)
#define SOC_HIPHYIO_FNPLL_SHADOW_READ_fnpll_lock_masked_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iodie_fnpll_en_sw_vote : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HIPHYIO_FNPLL_EN_SW_VOTE_UNION;
#endif
#define SOC_HIPHYIO_FNPLL_EN_SW_VOTE_iodie_fnpll_en_sw_vote_START (0)
#define SOC_HIPHYIO_FNPLL_EN_SW_VOTE_iodie_fnpll_en_sw_vote_END (3)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
