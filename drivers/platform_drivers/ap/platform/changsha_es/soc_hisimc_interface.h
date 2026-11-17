#ifndef __SOC_HISIMC_INTERFACE_H__
#define __SOC_HISIMC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HISIMC_CTRL0_ADDR(base) (base)
#define SOC_HISIMC_CTRL1_ADDR(base) ((base) + 0x0004UL)
#define SOC_HISIMC_CTRL2_ADDR(base) ((base) + 0x0008UL)
#define SOC_HISIMC_CTRL3_ADDR(base) ((base) + 0x000CUL)
#define SOC_HISIMC_CLK_CTRL0_ADDR(base) ((base) + 0x0010UL)
#define SOC_HISIMC_CLK_CTRL1_ADDR(base) ((base) + 0x0014UL)
#define SOC_HISIMC_STATUS0_ADDR(base) ((base) + 0x0018UL)
#define SOC_HISIMC_TXDATA_STAT_ADDR(base) ((base) + 0x001CUL)
#define SOC_HISIMC_RXDATA_STAT_ADDR(base) ((base) + 0x0020UL)
#define SOC_HISIMC_TX_DATA_ADDR(base) ((base) + 0x0024UL)
#define SOC_HISIMC_RX_DATA_ADDR(base) ((base) + 0x0028UL)
#define SOC_HISIMC_FIFO_TIDE_ADDR(base) ((base) + 0x002CUL)
#define SOC_HISIMC_ACTIVETIME_ADDR(base) ((base) + 0x0038UL)
#define SOC_HISIMC_ATRWAITTIME_ADDR(base) ((base) + 0x003CUL)
#define SOC_HISIMC_ATRRECTIME_ADDR(base) ((base) + 0x0040UL)
#define SOC_HISIMC_DEACTIVETIME0_ADDR(base) ((base) + 0x0044UL)
#define SOC_HISIMC_DEACTIVETIME1_ADDR(base) ((base) + 0x0048UL)
#define SOC_HISIMC_CLKSTOPTIME_ADDR(base) ((base) + 0x004CUL)
#define SOC_HISIMC_CLKWAKEUPTIME_ADDR(base) ((base) + 0x0050UL)
#define SOC_HISIMC_TX_GARDTIME_ADDR(base) ((base) + 0x0054UL)
#define SOC_HISIMC_TX_GARDTIME_RETRY_ADDR(base) ((base) + 0x0058UL)
#define SOC_HISIMC_RXCHARTIME_ADDR(base) ((base) + 0x005CUL)
#define SOC_HISIMC_TX2RX_TURN_TIME_ADDR(base) ((base) + 0x0060UL)
#define SOC_HISIMC_RX2TX_TURN_GARD_TIME_ADDR(base) ((base) + 0x0064UL)
#define SOC_HISIMC_RDRXFIFOTIME_ADDR(base) ((base) + 0x0068UL)
#define SOC_HISIMC_RAWINTR_MSK_ADDR(base) ((base) + 0x006CUL)
#define SOC_HISIMC_RAWINTR_ADDR(base) ((base) + 0x0070UL)
#define SOC_HISIMC_RAWINTR_CLR_ADDR(base) ((base) + 0x0074UL)
#define SOC_HISIMC_RAWINTR_MASKED_ADDR(base) ((base) + 0x0078UL)
#define SOC_HISIMC_CTRL0_RESERVED_ADDR(base) ((base) + 0x007CUL)
#define SOC_HISIMC_CTRL1_RESERVED_ADDR(base) ((base) + 0x0080UL)
#define SOC_HISIMC_CTRL2_RESERVED_ADDR(base) ((base) + 0x0084UL)
#define SOC_HISIMC_CTRL3_RESERVED_ADDR(base) ((base) + 0x0088UL)
#define SOC_HISIMC_STATUS0_RESERVED_ADDR(base) ((base) + 0x008CUL)
#define SOC_HISIMC_STATUS1_RESERVED_ADDR(base) ((base) + 0x0090UL)
#define SOC_HISIMC_TEST_CTRL0_ADDR(base) ((base) + 0x0098UL)
#define SOC_HISIMC_TEST_STAT_ADDR(base) ((base) + 0x009CUL)
#define SOC_HISIMC_TXDATA_FLAG0_ADDR(base) ((base) + 0x0A0UL)
#define SOC_HISIMC_TXDATA_FLAG1_ADDR(base) ((base) + 0x0A4UL)
#define SOC_HISIMC_TXDATA_FLAG2_ADDR(base) ((base) + 0x0A8UL)
#define SOC_HISIMC_TXDATA_FLAG3_ADDR(base) ((base) + 0x0ACUL)
#define SOC_HISIMC_FIFO_CLR_DLY_ADDR(base) ((base) + 0x00B0UL)
#define SOC_HISIMC_SYNC_TO_PCLK_DLY_ADDR(base) ((base) + 0x00B4UL)
#define SOC_HISIMC_VERSION_ID_ADDR(base) ((base) + 0x00B8UL)
#else
#define SOC_HISIMC_CTRL0_ADDR(base) (base)
#define SOC_HISIMC_CTRL1_ADDR(base) ((base) + 0x0004)
#define SOC_HISIMC_CTRL2_ADDR(base) ((base) + 0x0008)
#define SOC_HISIMC_CTRL3_ADDR(base) ((base) + 0x000C)
#define SOC_HISIMC_CLK_CTRL0_ADDR(base) ((base) + 0x0010)
#define SOC_HISIMC_CLK_CTRL1_ADDR(base) ((base) + 0x0014)
#define SOC_HISIMC_STATUS0_ADDR(base) ((base) + 0x0018)
#define SOC_HISIMC_TXDATA_STAT_ADDR(base) ((base) + 0x001C)
#define SOC_HISIMC_RXDATA_STAT_ADDR(base) ((base) + 0x0020)
#define SOC_HISIMC_TX_DATA_ADDR(base) ((base) + 0x0024)
#define SOC_HISIMC_RX_DATA_ADDR(base) ((base) + 0x0028)
#define SOC_HISIMC_FIFO_TIDE_ADDR(base) ((base) + 0x002C)
#define SOC_HISIMC_ACTIVETIME_ADDR(base) ((base) + 0x0038)
#define SOC_HISIMC_ATRWAITTIME_ADDR(base) ((base) + 0x003C)
#define SOC_HISIMC_ATRRECTIME_ADDR(base) ((base) + 0x0040)
#define SOC_HISIMC_DEACTIVETIME0_ADDR(base) ((base) + 0x0044)
#define SOC_HISIMC_DEACTIVETIME1_ADDR(base) ((base) + 0x0048)
#define SOC_HISIMC_CLKSTOPTIME_ADDR(base) ((base) + 0x004C)
#define SOC_HISIMC_CLKWAKEUPTIME_ADDR(base) ((base) + 0x0050)
#define SOC_HISIMC_TX_GARDTIME_ADDR(base) ((base) + 0x0054)
#define SOC_HISIMC_TX_GARDTIME_RETRY_ADDR(base) ((base) + 0x0058)
#define SOC_HISIMC_RXCHARTIME_ADDR(base) ((base) + 0x005C)
#define SOC_HISIMC_TX2RX_TURN_TIME_ADDR(base) ((base) + 0x0060)
#define SOC_HISIMC_RX2TX_TURN_GARD_TIME_ADDR(base) ((base) + 0x0064)
#define SOC_HISIMC_RDRXFIFOTIME_ADDR(base) ((base) + 0x0068)
#define SOC_HISIMC_RAWINTR_MSK_ADDR(base) ((base) + 0x006C)
#define SOC_HISIMC_RAWINTR_ADDR(base) ((base) + 0x0070)
#define SOC_HISIMC_RAWINTR_CLR_ADDR(base) ((base) + 0x0074)
#define SOC_HISIMC_RAWINTR_MASKED_ADDR(base) ((base) + 0x0078)
#define SOC_HISIMC_CTRL0_RESERVED_ADDR(base) ((base) + 0x007C)
#define SOC_HISIMC_CTRL1_RESERVED_ADDR(base) ((base) + 0x0080)
#define SOC_HISIMC_CTRL2_RESERVED_ADDR(base) ((base) + 0x0084)
#define SOC_HISIMC_CTRL3_RESERVED_ADDR(base) ((base) + 0x0088)
#define SOC_HISIMC_STATUS0_RESERVED_ADDR(base) ((base) + 0x008C)
#define SOC_HISIMC_STATUS1_RESERVED_ADDR(base) ((base) + 0x0090)
#define SOC_HISIMC_TEST_CTRL0_ADDR(base) ((base) + 0x0098)
#define SOC_HISIMC_TEST_STAT_ADDR(base) ((base) + 0x009C)
#define SOC_HISIMC_TXDATA_FLAG0_ADDR(base) ((base) + 0x0A0)
#define SOC_HISIMC_TXDATA_FLAG1_ADDR(base) ((base) + 0x0A4)
#define SOC_HISIMC_TXDATA_FLAG2_ADDR(base) ((base) + 0x0A8)
#define SOC_HISIMC_TXDATA_FLAG3_ADDR(base) ((base) + 0x0AC)
#define SOC_HISIMC_FIFO_CLR_DLY_ADDR(base) ((base) + 0x00B0)
#define SOC_HISIMC_SYNC_TO_PCLK_DLY_ADDR(base) ((base) + 0x00B4)
#define SOC_HISIMC_VERSION_ID_ADDR(base) ((base) + 0x00B8)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mode : 1;
        unsigned int data_order : 1;
        unsigned int txretry_en : 1;
        unsigned int txparity_mode : 1;
        unsigned int rxretry_en : 1;
        unsigned int rxparity_mode : 1;
        unsigned int data_driver_mode : 1;
        unsigned int hisimc_datain_sel : 1;
        unsigned int hisimc_datain_tie : 1;
        unsigned int rxchar_timer_en_reg : 1;
        unsigned int tx2rx_turn_wt_en_reg : 1;
        unsigned int rx2tx_turn_gt_en_reg : 1;
        unsigned int atrrec_timer_en_reg : 1;
        unsigned int clkstop : 1;
        unsigned int clk_stop_level : 1;
        unsigned int reserved_0 : 8;
        unsigned int atrwaittout_bypass : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_HISIMC_CTRL0_UNION;
#endif
#define SOC_HISIMC_CTRL0_mode_START (0)
#define SOC_HISIMC_CTRL0_mode_END (0)
#define SOC_HISIMC_CTRL0_data_order_START (1)
#define SOC_HISIMC_CTRL0_data_order_END (1)
#define SOC_HISIMC_CTRL0_txretry_en_START (2)
#define SOC_HISIMC_CTRL0_txretry_en_END (2)
#define SOC_HISIMC_CTRL0_txparity_mode_START (3)
#define SOC_HISIMC_CTRL0_txparity_mode_END (3)
#define SOC_HISIMC_CTRL0_rxretry_en_START (4)
#define SOC_HISIMC_CTRL0_rxretry_en_END (4)
#define SOC_HISIMC_CTRL0_rxparity_mode_START (5)
#define SOC_HISIMC_CTRL0_rxparity_mode_END (5)
#define SOC_HISIMC_CTRL0_data_driver_mode_START (6)
#define SOC_HISIMC_CTRL0_data_driver_mode_END (6)
#define SOC_HISIMC_CTRL0_hisimc_datain_sel_START (7)
#define SOC_HISIMC_CTRL0_hisimc_datain_sel_END (7)
#define SOC_HISIMC_CTRL0_hisimc_datain_tie_START (8)
#define SOC_HISIMC_CTRL0_hisimc_datain_tie_END (8)
#define SOC_HISIMC_CTRL0_rxchar_timer_en_reg_START (9)
#define SOC_HISIMC_CTRL0_rxchar_timer_en_reg_END (9)
#define SOC_HISIMC_CTRL0_tx2rx_turn_wt_en_reg_START (10)
#define SOC_HISIMC_CTRL0_tx2rx_turn_wt_en_reg_END (10)
#define SOC_HISIMC_CTRL0_rx2tx_turn_gt_en_reg_START (11)
#define SOC_HISIMC_CTRL0_rx2tx_turn_gt_en_reg_END (11)
#define SOC_HISIMC_CTRL0_atrrec_timer_en_reg_START (12)
#define SOC_HISIMC_CTRL0_atrrec_timer_en_reg_END (12)
#define SOC_HISIMC_CTRL0_clkstop_START (13)
#define SOC_HISIMC_CTRL0_clkstop_END (13)
#define SOC_HISIMC_CTRL0_clk_stop_level_START (14)
#define SOC_HISIMC_CTRL0_clk_stop_level_END (14)
#define SOC_HISIMC_CTRL0_atrwaittout_bypass_START (23)
#define SOC_HISIMC_CTRL0_atrwaittout_bypass_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxretry_num : 3;
        unsigned int reserved_0 : 1;
        unsigned int txretry_num : 3;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_HISIMC_CTRL1_UNION;
#endif
#define SOC_HISIMC_CTRL1_rxretry_num_START (0)
#define SOC_HISIMC_CTRL1_rxretry_num_END (2)
#define SOC_HISIMC_CTRL1_txretry_num_START (4)
#define SOC_HISIMC_CTRL1_txretry_num_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int active : 1;
        unsigned int warmreset : 1;
        unsigned int deactive : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HISIMC_CTRL2_UNION;
#endif
#define SOC_HISIMC_CTRL2_active_START (0)
#define SOC_HISIMC_CTRL2_active_END (0)
#define SOC_HISIMC_CTRL2_warmreset_START (1)
#define SOC_HISIMC_CTRL2_warmreset_END (1)
#define SOC_HISIMC_CTRL2_deactive_START (2)
#define SOC_HISIMC_CTRL2_deactive_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxfifo_clr : 1;
        unsigned int txfifo_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HISIMC_CTRL3_UNION;
#endif
#define SOC_HISIMC_CTRL3_rxfifo_clr_START (0)
#define SOC_HISIMC_CTRL3_rxfifo_clr_END (0)
#define SOC_HISIMC_CTRL3_txfifo_clr_START (1)
#define SOC_HISIMC_CTRL3_txfifo_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int etu_sample_rxdata : 16;
        unsigned int etucount : 16;
    } reg;
} SOC_HISIMC_CLK_CTRL0_UNION;
#endif
#define SOC_HISIMC_CLK_CTRL0_etu_sample_rxdata_START (0)
#define SOC_HISIMC_CLK_CTRL0_etu_sample_rxdata_END (15)
#define SOC_HISIMC_CLK_CTRL0_etucount_START (16)
#define SOC_HISIMC_CLK_CTRL0_etucount_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clkout_div : 5;
        unsigned int reserved_0 : 3;
        unsigned int etucount_dec : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_HISIMC_CLK_CTRL1_UNION;
#endif
#define SOC_HISIMC_CLK_CTRL1_clkout_div_START (0)
#define SOC_HISIMC_CLK_CTRL1_clkout_div_END (4)
#define SOC_HISIMC_CLK_CTRL1_etucount_dec_START (8)
#define SOC_HISIMC_CLK_CTRL1_etucount_dec_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxfifo_empty : 1;
        unsigned int rxfifo_full : 1;
        unsigned int txfifo_empty : 1;
        unsigned int txfifo_full : 1;
        unsigned int rxfifo_count : 6;
        unsigned int reserved_0 : 2;
        unsigned int txfifo_count : 6;
        unsigned int reserved_1 : 2;
        unsigned int hisimc_current_stat : 4;
        unsigned int hisimc_clkout_stat : 1;
        unsigned int hisimc_rstn_stat : 1;
        unsigned int hisimc_dataout_oen_stat : 1;
        unsigned int rxfifo_clr_ok : 1;
        unsigned int txfifo_clr_ok : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_HISIMC_STATUS0_UNION;
#endif
#define SOC_HISIMC_STATUS0_rxfifo_empty_START (0)
#define SOC_HISIMC_STATUS0_rxfifo_empty_END (0)
#define SOC_HISIMC_STATUS0_rxfifo_full_START (1)
#define SOC_HISIMC_STATUS0_rxfifo_full_END (1)
#define SOC_HISIMC_STATUS0_txfifo_empty_START (2)
#define SOC_HISIMC_STATUS0_txfifo_empty_END (2)
#define SOC_HISIMC_STATUS0_txfifo_full_START (3)
#define SOC_HISIMC_STATUS0_txfifo_full_END (3)
#define SOC_HISIMC_STATUS0_rxfifo_count_START (4)
#define SOC_HISIMC_STATUS0_rxfifo_count_END (9)
#define SOC_HISIMC_STATUS0_txfifo_count_START (12)
#define SOC_HISIMC_STATUS0_txfifo_count_END (17)
#define SOC_HISIMC_STATUS0_hisimc_current_stat_START (20)
#define SOC_HISIMC_STATUS0_hisimc_current_stat_END (23)
#define SOC_HISIMC_STATUS0_hisimc_clkout_stat_START (24)
#define SOC_HISIMC_STATUS0_hisimc_clkout_stat_END (24)
#define SOC_HISIMC_STATUS0_hisimc_rstn_stat_START (25)
#define SOC_HISIMC_STATUS0_hisimc_rstn_stat_END (25)
#define SOC_HISIMC_STATUS0_hisimc_dataout_oen_stat_START (26)
#define SOC_HISIMC_STATUS0_hisimc_dataout_oen_stat_END (26)
#define SOC_HISIMC_STATUS0_rxfifo_clr_ok_START (27)
#define SOC_HISIMC_STATUS0_rxfifo_clr_ok_END (27)
#define SOC_HISIMC_STATUS0_txfifo_clr_ok_START (28)
#define SOC_HISIMC_STATUS0_txfifo_clr_ok_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txfifo_data0 : 8;
        unsigned int txfifo_data1 : 8;
        unsigned int txfifo_data2 : 8;
        unsigned int txfifo_data3 : 8;
    } reg;
} SOC_HISIMC_TXDATA_STAT_UNION;
#endif
#define SOC_HISIMC_TXDATA_STAT_txfifo_data0_START (0)
#define SOC_HISIMC_TXDATA_STAT_txfifo_data0_END (7)
#define SOC_HISIMC_TXDATA_STAT_txfifo_data1_START (8)
#define SOC_HISIMC_TXDATA_STAT_txfifo_data1_END (15)
#define SOC_HISIMC_TXDATA_STAT_txfifo_data2_START (16)
#define SOC_HISIMC_TXDATA_STAT_txfifo_data2_END (23)
#define SOC_HISIMC_TXDATA_STAT_txfifo_data3_START (24)
#define SOC_HISIMC_TXDATA_STAT_txfifo_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxfifo_data0 : 8;
        unsigned int rxfifo_data1 : 8;
        unsigned int rxfifo_data2 : 8;
        unsigned int rxfifo_data3 : 8;
    } reg;
} SOC_HISIMC_RXDATA_STAT_UNION;
#endif
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data0_START (0)
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data0_END (7)
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data1_START (8)
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data1_END (15)
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data2_START (16)
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data2_END (23)
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data3_START (24)
#define SOC_HISIMC_RXDATA_STAT_rxfifo_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisimc_tx_data : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HISIMC_TX_DATA_UNION;
#endif
#define SOC_HISIMC_TX_DATA_hisimc_tx_data_START (0)
#define SOC_HISIMC_TX_DATA_hisimc_tx_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisimc_rx_data : 8;
        unsigned int rx_parity_bit : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_HISIMC_RX_DATA_UNION;
#endif
#define SOC_HISIMC_RX_DATA_hisimc_rx_data_START (0)
#define SOC_HISIMC_RX_DATA_hisimc_rx_data_END (7)
#define SOC_HISIMC_RX_DATA_rx_parity_bit_START (8)
#define SOC_HISIMC_RX_DATA_rx_parity_bit_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxfifo_tide : 6;
        unsigned int reserved_0 : 2;
        unsigned int txfifo_tide : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_HISIMC_FIFO_TIDE_UNION;
#endif
#define SOC_HISIMC_FIFO_TIDE_rxfifo_tide_START (0)
#define SOC_HISIMC_FIFO_TIDE_rxfifo_tide_END (5)
#define SOC_HISIMC_FIFO_TIDE_txfifo_tide_START (8)
#define SOC_HISIMC_FIFO_TIDE_txfifo_tide_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int activetime : 32;
    } reg;
} SOC_HISIMC_ACTIVETIME_UNION;
#endif
#define SOC_HISIMC_ACTIVETIME_activetime_START (0)
#define SOC_HISIMC_ACTIVETIME_activetime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int atrwaittime : 32;
    } reg;
} SOC_HISIMC_ATRWAITTIME_UNION;
#endif
#define SOC_HISIMC_ATRWAITTIME_atrwaittime_START (0)
#define SOC_HISIMC_ATRWAITTIME_atrwaittime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int atrrectime : 32;
    } reg;
} SOC_HISIMC_ATRRECTIME_UNION;
#endif
#define SOC_HISIMC_ATRRECTIME_atrrectime_START (0)
#define SOC_HISIMC_ATRRECTIME_atrrectime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deactivetime0 : 32;
    } reg;
} SOC_HISIMC_DEACTIVETIME0_UNION;
#endif
#define SOC_HISIMC_DEACTIVETIME0_deactivetime0_START (0)
#define SOC_HISIMC_DEACTIVETIME0_deactivetime0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deactivetime1 : 32;
    } reg;
} SOC_HISIMC_DEACTIVETIME1_UNION;
#endif
#define SOC_HISIMC_DEACTIVETIME1_deactivetime1_START (0)
#define SOC_HISIMC_DEACTIVETIME1_deactivetime1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clkstoptime : 32;
    } reg;
} SOC_HISIMC_CLKSTOPTIME_UNION;
#endif
#define SOC_HISIMC_CLKSTOPTIME_clkstoptime_START (0)
#define SOC_HISIMC_CLKSTOPTIME_clkstoptime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clkwakeuptime : 32;
    } reg;
} SOC_HISIMC_CLKWAKEUPTIME_UNION;
#endif
#define SOC_HISIMC_CLKWAKEUPTIME_clkwakeuptime_START (0)
#define SOC_HISIMC_CLKWAKEUPTIME_clkwakeuptime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_gardtime : 32;
    } reg;
} SOC_HISIMC_TX_GARDTIME_UNION;
#endif
#define SOC_HISIMC_TX_GARDTIME_tx_gardtime_START (0)
#define SOC_HISIMC_TX_GARDTIME_tx_gardtime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_gardtime_retry : 32;
    } reg;
} SOC_HISIMC_TX_GARDTIME_RETRY_UNION;
#endif
#define SOC_HISIMC_TX_GARDTIME_RETRY_tx_gardtime_retry_START (0)
#define SOC_HISIMC_TX_GARDTIME_RETRY_tx_gardtime_retry_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxchartime : 32;
    } reg;
} SOC_HISIMC_RXCHARTIME_UNION;
#endif
#define SOC_HISIMC_RXCHARTIME_rxchartime_START (0)
#define SOC_HISIMC_RXCHARTIME_rxchartime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx2rx_turn_time : 32;
    } reg;
} SOC_HISIMC_TX2RX_TURN_TIME_UNION;
#endif
#define SOC_HISIMC_TX2RX_TURN_TIME_tx2rx_turn_time_START (0)
#define SOC_HISIMC_TX2RX_TURN_TIME_tx2rx_turn_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx2tx_turn_gard_time : 32;
    } reg;
} SOC_HISIMC_RX2TX_TURN_GARD_TIME_UNION;
#endif
#define SOC_HISIMC_RX2TX_TURN_GARD_TIME_rx2tx_turn_gard_time_START (0)
#define SOC_HISIMC_RX2TX_TURN_GARD_TIME_rx2tx_turn_gard_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdrxfifotime : 32;
    } reg;
} SOC_HISIMC_RDRXFIFOTIME_UNION;
#endif
#define SOC_HISIMC_RDRXFIFOTIME_rdrxfifotime_START (0)
#define SOC_HISIMC_RDRXFIFOTIME_rdrxfifotime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simup_rawintr_msk : 1;
        unsigned int simdone_rawintr_msk : 1;
        unsigned int warmrstdone_rawintr_msk : 1;
        unsigned int clkstop_rawintr_msk : 1;
        unsigned int clkwakeup_rawintr_msk : 1;
        unsigned int rdrxfifo_rawintr_msk : 1;
        unsigned int writetxfifo_rawintr_msk : 1;
        unsigned int reserved : 9;
        unsigned int atrwaittout_rawintr_msk : 1;
        unsigned int atr_start_error_rawintr_msk : 1;
        unsigned int atrrectout_rawintr_msk : 1;
        unsigned int clkstop_enter_error_rawintr_msk : 1;
        unsigned int hisimctxerr_rawintr_msk : 1;
        unsigned int hisimcrxerr_rawintr_msk : 1;
        unsigned int rxchartout_rawintr_msk : 1;
        unsigned int tx2rx_turn_tout_rawintr_msk : 1;
        unsigned int txovfull_rawintr_msk : 1;
        unsigned int rdtxfifo_empty_rawintr_msk : 1;
        unsigned int rdrxfifotout_rawintr_msk : 1;
        unsigned int rxovfull_rawintr_msk : 1;
        unsigned int rdrxfifo_empty_rawintr_msk : 1;
        unsigned int rawintr_msk_reserved : 3;
    } reg;
} SOC_HISIMC_RAWINTR_MSK_UNION;
#endif
#define SOC_HISIMC_RAWINTR_MSK_simup_rawintr_msk_START (0)
#define SOC_HISIMC_RAWINTR_MSK_simup_rawintr_msk_END (0)
#define SOC_HISIMC_RAWINTR_MSK_simdone_rawintr_msk_START (1)
#define SOC_HISIMC_RAWINTR_MSK_simdone_rawintr_msk_END (1)
#define SOC_HISIMC_RAWINTR_MSK_warmrstdone_rawintr_msk_START (2)
#define SOC_HISIMC_RAWINTR_MSK_warmrstdone_rawintr_msk_END (2)
#define SOC_HISIMC_RAWINTR_MSK_clkstop_rawintr_msk_START (3)
#define SOC_HISIMC_RAWINTR_MSK_clkstop_rawintr_msk_END (3)
#define SOC_HISIMC_RAWINTR_MSK_clkwakeup_rawintr_msk_START (4)
#define SOC_HISIMC_RAWINTR_MSK_clkwakeup_rawintr_msk_END (4)
#define SOC_HISIMC_RAWINTR_MSK_rdrxfifo_rawintr_msk_START (5)
#define SOC_HISIMC_RAWINTR_MSK_rdrxfifo_rawintr_msk_END (5)
#define SOC_HISIMC_RAWINTR_MSK_writetxfifo_rawintr_msk_START (6)
#define SOC_HISIMC_RAWINTR_MSK_writetxfifo_rawintr_msk_END (6)
#define SOC_HISIMC_RAWINTR_MSK_atrwaittout_rawintr_msk_START (16)
#define SOC_HISIMC_RAWINTR_MSK_atrwaittout_rawintr_msk_END (16)
#define SOC_HISIMC_RAWINTR_MSK_atr_start_error_rawintr_msk_START (17)
#define SOC_HISIMC_RAWINTR_MSK_atr_start_error_rawintr_msk_END (17)
#define SOC_HISIMC_RAWINTR_MSK_atrrectout_rawintr_msk_START (18)
#define SOC_HISIMC_RAWINTR_MSK_atrrectout_rawintr_msk_END (18)
#define SOC_HISIMC_RAWINTR_MSK_clkstop_enter_error_rawintr_msk_START (19)
#define SOC_HISIMC_RAWINTR_MSK_clkstop_enter_error_rawintr_msk_END (19)
#define SOC_HISIMC_RAWINTR_MSK_hisimctxerr_rawintr_msk_START (20)
#define SOC_HISIMC_RAWINTR_MSK_hisimctxerr_rawintr_msk_END (20)
#define SOC_HISIMC_RAWINTR_MSK_hisimcrxerr_rawintr_msk_START (21)
#define SOC_HISIMC_RAWINTR_MSK_hisimcrxerr_rawintr_msk_END (21)
#define SOC_HISIMC_RAWINTR_MSK_rxchartout_rawintr_msk_START (22)
#define SOC_HISIMC_RAWINTR_MSK_rxchartout_rawintr_msk_END (22)
#define SOC_HISIMC_RAWINTR_MSK_tx2rx_turn_tout_rawintr_msk_START (23)
#define SOC_HISIMC_RAWINTR_MSK_tx2rx_turn_tout_rawintr_msk_END (23)
#define SOC_HISIMC_RAWINTR_MSK_txovfull_rawintr_msk_START (24)
#define SOC_HISIMC_RAWINTR_MSK_txovfull_rawintr_msk_END (24)
#define SOC_HISIMC_RAWINTR_MSK_rdtxfifo_empty_rawintr_msk_START (25)
#define SOC_HISIMC_RAWINTR_MSK_rdtxfifo_empty_rawintr_msk_END (25)
#define SOC_HISIMC_RAWINTR_MSK_rdrxfifotout_rawintr_msk_START (26)
#define SOC_HISIMC_RAWINTR_MSK_rdrxfifotout_rawintr_msk_END (26)
#define SOC_HISIMC_RAWINTR_MSK_rxovfull_rawintr_msk_START (27)
#define SOC_HISIMC_RAWINTR_MSK_rxovfull_rawintr_msk_END (27)
#define SOC_HISIMC_RAWINTR_MSK_rdrxfifo_empty_rawintr_msk_START (28)
#define SOC_HISIMC_RAWINTR_MSK_rdrxfifo_empty_rawintr_msk_END (28)
#define SOC_HISIMC_RAWINTR_MSK_rawintr_msk_reserved_START (29)
#define SOC_HISIMC_RAWINTR_MSK_rawintr_msk_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simup_rawintr : 1;
        unsigned int simdone_rawintr : 1;
        unsigned int warmrstdone_rawintr : 1;
        unsigned int clkstop_rawintr : 1;
        unsigned int clkwakeup_rawintr : 1;
        unsigned int rdrxfifo_rawintr : 1;
        unsigned int writetxfifo_rawintr : 1;
        unsigned int reserved : 9;
        unsigned int atrwaittout_rawintr : 1;
        unsigned int atr_start_error_rawintr : 1;
        unsigned int atrrectout_rawintr : 1;
        unsigned int clkstop_enter_error_rawintr : 1;
        unsigned int hisimctxerr_rawintr : 1;
        unsigned int hisimcrxerr_rawintr : 1;
        unsigned int rxchartout_rawintr : 1;
        unsigned int tx2rx_turn_tout_rawintr : 1;
        unsigned int txovfull_rawintr : 1;
        unsigned int rdtxfifo_empty_rawintr : 1;
        unsigned int rdrxfifotout_rawintr : 1;
        unsigned int rxovfull_rawintr : 1;
        unsigned int rdrxfifo_empty_rawintr : 1;
        unsigned int rawintr_reserved : 3;
    } reg;
} SOC_HISIMC_RAWINTR_UNION;
#endif
#define SOC_HISIMC_RAWINTR_simup_rawintr_START (0)
#define SOC_HISIMC_RAWINTR_simup_rawintr_END (0)
#define SOC_HISIMC_RAWINTR_simdone_rawintr_START (1)
#define SOC_HISIMC_RAWINTR_simdone_rawintr_END (1)
#define SOC_HISIMC_RAWINTR_warmrstdone_rawintr_START (2)
#define SOC_HISIMC_RAWINTR_warmrstdone_rawintr_END (2)
#define SOC_HISIMC_RAWINTR_clkstop_rawintr_START (3)
#define SOC_HISIMC_RAWINTR_clkstop_rawintr_END (3)
#define SOC_HISIMC_RAWINTR_clkwakeup_rawintr_START (4)
#define SOC_HISIMC_RAWINTR_clkwakeup_rawintr_END (4)
#define SOC_HISIMC_RAWINTR_rdrxfifo_rawintr_START (5)
#define SOC_HISIMC_RAWINTR_rdrxfifo_rawintr_END (5)
#define SOC_HISIMC_RAWINTR_writetxfifo_rawintr_START (6)
#define SOC_HISIMC_RAWINTR_writetxfifo_rawintr_END (6)
#define SOC_HISIMC_RAWINTR_atrwaittout_rawintr_START (16)
#define SOC_HISIMC_RAWINTR_atrwaittout_rawintr_END (16)
#define SOC_HISIMC_RAWINTR_atr_start_error_rawintr_START (17)
#define SOC_HISIMC_RAWINTR_atr_start_error_rawintr_END (17)
#define SOC_HISIMC_RAWINTR_atrrectout_rawintr_START (18)
#define SOC_HISIMC_RAWINTR_atrrectout_rawintr_END (18)
#define SOC_HISIMC_RAWINTR_clkstop_enter_error_rawintr_START (19)
#define SOC_HISIMC_RAWINTR_clkstop_enter_error_rawintr_END (19)
#define SOC_HISIMC_RAWINTR_hisimctxerr_rawintr_START (20)
#define SOC_HISIMC_RAWINTR_hisimctxerr_rawintr_END (20)
#define SOC_HISIMC_RAWINTR_hisimcrxerr_rawintr_START (21)
#define SOC_HISIMC_RAWINTR_hisimcrxerr_rawintr_END (21)
#define SOC_HISIMC_RAWINTR_rxchartout_rawintr_START (22)
#define SOC_HISIMC_RAWINTR_rxchartout_rawintr_END (22)
#define SOC_HISIMC_RAWINTR_tx2rx_turn_tout_rawintr_START (23)
#define SOC_HISIMC_RAWINTR_tx2rx_turn_tout_rawintr_END (23)
#define SOC_HISIMC_RAWINTR_txovfull_rawintr_START (24)
#define SOC_HISIMC_RAWINTR_txovfull_rawintr_END (24)
#define SOC_HISIMC_RAWINTR_rdtxfifo_empty_rawintr_START (25)
#define SOC_HISIMC_RAWINTR_rdtxfifo_empty_rawintr_END (25)
#define SOC_HISIMC_RAWINTR_rdrxfifotout_rawintr_START (26)
#define SOC_HISIMC_RAWINTR_rdrxfifotout_rawintr_END (26)
#define SOC_HISIMC_RAWINTR_rxovfull_rawintr_START (27)
#define SOC_HISIMC_RAWINTR_rxovfull_rawintr_END (27)
#define SOC_HISIMC_RAWINTR_rdrxfifo_empty_rawintr_START (28)
#define SOC_HISIMC_RAWINTR_rdrxfifo_empty_rawintr_END (28)
#define SOC_HISIMC_RAWINTR_rawintr_reserved_START (29)
#define SOC_HISIMC_RAWINTR_rawintr_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simup_rawintr_clr : 1;
        unsigned int simdone_rawintr_clr : 1;
        unsigned int warmrstdone_rawintr_clr : 1;
        unsigned int clkstop_rawintr_clr : 1;
        unsigned int clkwakeup_rawintr_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 9;
        unsigned int atrwaittout_rawintr_clr : 1;
        unsigned int atr_start_error_rawintr_clr : 1;
        unsigned int atrrectout_rawintr_clr : 1;
        unsigned int clkstop_enter_error_rawintr_clr : 1;
        unsigned int hisimctxerr_rawintr_clr : 1;
        unsigned int hisimcrxerr_rawintr_clr : 1;
        unsigned int rxchartout_rawintr_clr : 1;
        unsigned int tx2rx_turn_tout_rawintr_clr : 1;
        unsigned int txovfull_rawintr_clr : 1;
        unsigned int rdtxfifo_empty_rawintr_clr : 1;
        unsigned int rdrxfifotout_rawintr_clr : 1;
        unsigned int rxovfull_rawintr_clr : 1;
        unsigned int rdrxfifo_empty_rawintr_clr : 1;
        unsigned int rawintr_clr_reserved : 3;
    } reg;
} SOC_HISIMC_RAWINTR_CLR_UNION;
#endif
#define SOC_HISIMC_RAWINTR_CLR_simup_rawintr_clr_START (0)
#define SOC_HISIMC_RAWINTR_CLR_simup_rawintr_clr_END (0)
#define SOC_HISIMC_RAWINTR_CLR_simdone_rawintr_clr_START (1)
#define SOC_HISIMC_RAWINTR_CLR_simdone_rawintr_clr_END (1)
#define SOC_HISIMC_RAWINTR_CLR_warmrstdone_rawintr_clr_START (2)
#define SOC_HISIMC_RAWINTR_CLR_warmrstdone_rawintr_clr_END (2)
#define SOC_HISIMC_RAWINTR_CLR_clkstop_rawintr_clr_START (3)
#define SOC_HISIMC_RAWINTR_CLR_clkstop_rawintr_clr_END (3)
#define SOC_HISIMC_RAWINTR_CLR_clkwakeup_rawintr_clr_START (4)
#define SOC_HISIMC_RAWINTR_CLR_clkwakeup_rawintr_clr_END (4)
#define SOC_HISIMC_RAWINTR_CLR_atrwaittout_rawintr_clr_START (16)
#define SOC_HISIMC_RAWINTR_CLR_atrwaittout_rawintr_clr_END (16)
#define SOC_HISIMC_RAWINTR_CLR_atr_start_error_rawintr_clr_START (17)
#define SOC_HISIMC_RAWINTR_CLR_atr_start_error_rawintr_clr_END (17)
#define SOC_HISIMC_RAWINTR_CLR_atrrectout_rawintr_clr_START (18)
#define SOC_HISIMC_RAWINTR_CLR_atrrectout_rawintr_clr_END (18)
#define SOC_HISIMC_RAWINTR_CLR_clkstop_enter_error_rawintr_clr_START (19)
#define SOC_HISIMC_RAWINTR_CLR_clkstop_enter_error_rawintr_clr_END (19)
#define SOC_HISIMC_RAWINTR_CLR_hisimctxerr_rawintr_clr_START (20)
#define SOC_HISIMC_RAWINTR_CLR_hisimctxerr_rawintr_clr_END (20)
#define SOC_HISIMC_RAWINTR_CLR_hisimcrxerr_rawintr_clr_START (21)
#define SOC_HISIMC_RAWINTR_CLR_hisimcrxerr_rawintr_clr_END (21)
#define SOC_HISIMC_RAWINTR_CLR_rxchartout_rawintr_clr_START (22)
#define SOC_HISIMC_RAWINTR_CLR_rxchartout_rawintr_clr_END (22)
#define SOC_HISIMC_RAWINTR_CLR_tx2rx_turn_tout_rawintr_clr_START (23)
#define SOC_HISIMC_RAWINTR_CLR_tx2rx_turn_tout_rawintr_clr_END (23)
#define SOC_HISIMC_RAWINTR_CLR_txovfull_rawintr_clr_START (24)
#define SOC_HISIMC_RAWINTR_CLR_txovfull_rawintr_clr_END (24)
#define SOC_HISIMC_RAWINTR_CLR_rdtxfifo_empty_rawintr_clr_START (25)
#define SOC_HISIMC_RAWINTR_CLR_rdtxfifo_empty_rawintr_clr_END (25)
#define SOC_HISIMC_RAWINTR_CLR_rdrxfifotout_rawintr_clr_START (26)
#define SOC_HISIMC_RAWINTR_CLR_rdrxfifotout_rawintr_clr_END (26)
#define SOC_HISIMC_RAWINTR_CLR_rxovfull_rawintr_clr_START (27)
#define SOC_HISIMC_RAWINTR_CLR_rxovfull_rawintr_clr_END (27)
#define SOC_HISIMC_RAWINTR_CLR_rdrxfifo_empty_rawintr_clr_START (28)
#define SOC_HISIMC_RAWINTR_CLR_rdrxfifo_empty_rawintr_clr_END (28)
#define SOC_HISIMC_RAWINTR_CLR_rawintr_clr_reserved_START (29)
#define SOC_HISIMC_RAWINTR_CLR_rawintr_clr_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simup_rawintr_masked : 1;
        unsigned int simdone_rawintr_masked : 1;
        unsigned int warmrstdone_rawintr_masked : 1;
        unsigned int clkstop_rawintr_masked : 1;
        unsigned int clkwakeup_rawintr_masked : 1;
        unsigned int rdrxfifo_rawintr_masked : 1;
        unsigned int writetxfifo_rawintr_masked : 1;
        unsigned int reserved : 9;
        unsigned int atrwaittout_rawintr_masked : 1;
        unsigned int atr_start_error_rawintr_masked : 1;
        unsigned int atrrectout_rawintr_masked : 1;
        unsigned int clkstop_enter_error_rawintr_masked : 1;
        unsigned int hisimctxerr_rawintr_masked : 1;
        unsigned int hisimcrxerr_rawintr_masked : 1;
        unsigned int rxchartout_rawintr_masked : 1;
        unsigned int tx2rx_turn_tout_rawintr_masked : 1;
        unsigned int txovfull_rawintr_masked : 1;
        unsigned int rdtxfifo_empty_rawintr_masked : 1;
        unsigned int rdrxfifotout_rawintr_masked : 1;
        unsigned int rxovfull_rawintr_masked : 1;
        unsigned int rdrxfifo_empty_rawintr_masked : 1;
        unsigned int rawintr_masked_reserved : 3;
    } reg;
} SOC_HISIMC_RAWINTR_MASKED_UNION;
#endif
#define SOC_HISIMC_RAWINTR_MASKED_simup_rawintr_masked_START (0)
#define SOC_HISIMC_RAWINTR_MASKED_simup_rawintr_masked_END (0)
#define SOC_HISIMC_RAWINTR_MASKED_simdone_rawintr_masked_START (1)
#define SOC_HISIMC_RAWINTR_MASKED_simdone_rawintr_masked_END (1)
#define SOC_HISIMC_RAWINTR_MASKED_warmrstdone_rawintr_masked_START (2)
#define SOC_HISIMC_RAWINTR_MASKED_warmrstdone_rawintr_masked_END (2)
#define SOC_HISIMC_RAWINTR_MASKED_clkstop_rawintr_masked_START (3)
#define SOC_HISIMC_RAWINTR_MASKED_clkstop_rawintr_masked_END (3)
#define SOC_HISIMC_RAWINTR_MASKED_clkwakeup_rawintr_masked_START (4)
#define SOC_HISIMC_RAWINTR_MASKED_clkwakeup_rawintr_masked_END (4)
#define SOC_HISIMC_RAWINTR_MASKED_rdrxfifo_rawintr_masked_START (5)
#define SOC_HISIMC_RAWINTR_MASKED_rdrxfifo_rawintr_masked_END (5)
#define SOC_HISIMC_RAWINTR_MASKED_writetxfifo_rawintr_masked_START (6)
#define SOC_HISIMC_RAWINTR_MASKED_writetxfifo_rawintr_masked_END (6)
#define SOC_HISIMC_RAWINTR_MASKED_atrwaittout_rawintr_masked_START (16)
#define SOC_HISIMC_RAWINTR_MASKED_atrwaittout_rawintr_masked_END (16)
#define SOC_HISIMC_RAWINTR_MASKED_atr_start_error_rawintr_masked_START (17)
#define SOC_HISIMC_RAWINTR_MASKED_atr_start_error_rawintr_masked_END (17)
#define SOC_HISIMC_RAWINTR_MASKED_atrrectout_rawintr_masked_START (18)
#define SOC_HISIMC_RAWINTR_MASKED_atrrectout_rawintr_masked_END (18)
#define SOC_HISIMC_RAWINTR_MASKED_clkstop_enter_error_rawintr_masked_START (19)
#define SOC_HISIMC_RAWINTR_MASKED_clkstop_enter_error_rawintr_masked_END (19)
#define SOC_HISIMC_RAWINTR_MASKED_hisimctxerr_rawintr_masked_START (20)
#define SOC_HISIMC_RAWINTR_MASKED_hisimctxerr_rawintr_masked_END (20)
#define SOC_HISIMC_RAWINTR_MASKED_hisimcrxerr_rawintr_masked_START (21)
#define SOC_HISIMC_RAWINTR_MASKED_hisimcrxerr_rawintr_masked_END (21)
#define SOC_HISIMC_RAWINTR_MASKED_rxchartout_rawintr_masked_START (22)
#define SOC_HISIMC_RAWINTR_MASKED_rxchartout_rawintr_masked_END (22)
#define SOC_HISIMC_RAWINTR_MASKED_tx2rx_turn_tout_rawintr_masked_START (23)
#define SOC_HISIMC_RAWINTR_MASKED_tx2rx_turn_tout_rawintr_masked_END (23)
#define SOC_HISIMC_RAWINTR_MASKED_txovfull_rawintr_masked_START (24)
#define SOC_HISIMC_RAWINTR_MASKED_txovfull_rawintr_masked_END (24)
#define SOC_HISIMC_RAWINTR_MASKED_rdtxfifo_empty_rawintr_masked_START (25)
#define SOC_HISIMC_RAWINTR_MASKED_rdtxfifo_empty_rawintr_masked_END (25)
#define SOC_HISIMC_RAWINTR_MASKED_rdrxfifotout_rawintr_masked_START (26)
#define SOC_HISIMC_RAWINTR_MASKED_rdrxfifotout_rawintr_masked_END (26)
#define SOC_HISIMC_RAWINTR_MASKED_rxovfull_rawintr_masked_START (27)
#define SOC_HISIMC_RAWINTR_MASKED_rxovfull_rawintr_masked_END (27)
#define SOC_HISIMC_RAWINTR_MASKED_rdrxfifo_empty_rawintr_masked_START (28)
#define SOC_HISIMC_RAWINTR_MASKED_rdrxfifo_empty_rawintr_masked_END (28)
#define SOC_HISIMC_RAWINTR_MASKED_rawintr_masked_reserved_START (29)
#define SOC_HISIMC_RAWINTR_MASKED_rawintr_masked_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctrl0_reserved : 32;
    } reg;
} SOC_HISIMC_CTRL0_RESERVED_UNION;
#endif
#define SOC_HISIMC_CTRL0_RESERVED_ctrl0_reserved_START (0)
#define SOC_HISIMC_CTRL0_RESERVED_ctrl0_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctrl1_reserved : 32;
    } reg;
} SOC_HISIMC_CTRL1_RESERVED_UNION;
#endif
#define SOC_HISIMC_CTRL1_RESERVED_ctrl1_reserved_START (0)
#define SOC_HISIMC_CTRL1_RESERVED_ctrl1_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctrl2_reserved : 32;
    } reg;
} SOC_HISIMC_CTRL2_RESERVED_UNION;
#endif
#define SOC_HISIMC_CTRL2_RESERVED_ctrl2_reserved_START (0)
#define SOC_HISIMC_CTRL2_RESERVED_ctrl2_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctrl3_reserved : 32;
    } reg;
} SOC_HISIMC_CTRL3_RESERVED_UNION;
#endif
#define SOC_HISIMC_CTRL3_RESERVED_ctrl3_reserved_START (0)
#define SOC_HISIMC_CTRL3_RESERVED_ctrl3_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int status0_reserved : 32;
    } reg;
} SOC_HISIMC_STATUS0_RESERVED_UNION;
#endif
#define SOC_HISIMC_STATUS0_RESERVED_status0_reserved_START (0)
#define SOC_HISIMC_STATUS0_RESERVED_status0_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int status1_reserved : 32;
    } reg;
} SOC_HISIMC_STATUS1_RESERVED_UNION;
#endif
#define SOC_HISIMC_STATUS1_RESERVED_status1_reserved_START (0)
#define SOC_HISIMC_STATUS1_RESERVED_status1_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_mode : 1;
        unsigned int dataout_test : 1;
        unsigned int dataout_oen_test : 1;
        unsigned int clkout_test : 1;
        unsigned int rstn_out_test : 1;
        unsigned int simup_intr_test : 1;
        unsigned int simdone_intr_test : 1;
        unsigned int warmrstdone_intr_test : 1;
        unsigned int atrwaittout_intr_test : 1;
        unsigned int atrrectout_intr_test : 1;
        unsigned int hisimctxerr_intr_test : 1;
        unsigned int hisimcrxerr_intr_test : 1;
        unsigned int rxchartout_intr_test : 1;
        unsigned int tx2rx_turn_tout_intr_test : 1;
        unsigned int rdrxfifotout_intr_test : 1;
        unsigned int rxovfull_intr_test : 1;
        unsigned int txovfull_intr_test : 1;
        unsigned int clkstop_intr_test : 1;
        unsigned int clkwakeup_intr_test : 1;
        unsigned int writetxfifo_intr_test : 1;
        unsigned int rdrxfifo_intr_test : 1;
        unsigned int atr_start_error_intr_test : 1;
        unsigned int clkstop_enter_error_intr_test : 1;
        unsigned int rdtxfifo_empty_intr_test : 1;
        unsigned int rdrxfifo_empty_intr_test : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_HISIMC_TEST_CTRL0_UNION;
#endif
#define SOC_HISIMC_TEST_CTRL0_test_mode_START (0)
#define SOC_HISIMC_TEST_CTRL0_test_mode_END (0)
#define SOC_HISIMC_TEST_CTRL0_dataout_test_START (1)
#define SOC_HISIMC_TEST_CTRL0_dataout_test_END (1)
#define SOC_HISIMC_TEST_CTRL0_dataout_oen_test_START (2)
#define SOC_HISIMC_TEST_CTRL0_dataout_oen_test_END (2)
#define SOC_HISIMC_TEST_CTRL0_clkout_test_START (3)
#define SOC_HISIMC_TEST_CTRL0_clkout_test_END (3)
#define SOC_HISIMC_TEST_CTRL0_rstn_out_test_START (4)
#define SOC_HISIMC_TEST_CTRL0_rstn_out_test_END (4)
#define SOC_HISIMC_TEST_CTRL0_simup_intr_test_START (5)
#define SOC_HISIMC_TEST_CTRL0_simup_intr_test_END (5)
#define SOC_HISIMC_TEST_CTRL0_simdone_intr_test_START (6)
#define SOC_HISIMC_TEST_CTRL0_simdone_intr_test_END (6)
#define SOC_HISIMC_TEST_CTRL0_warmrstdone_intr_test_START (7)
#define SOC_HISIMC_TEST_CTRL0_warmrstdone_intr_test_END (7)
#define SOC_HISIMC_TEST_CTRL0_atrwaittout_intr_test_START (8)
#define SOC_HISIMC_TEST_CTRL0_atrwaittout_intr_test_END (8)
#define SOC_HISIMC_TEST_CTRL0_atrrectout_intr_test_START (9)
#define SOC_HISIMC_TEST_CTRL0_atrrectout_intr_test_END (9)
#define SOC_HISIMC_TEST_CTRL0_hisimctxerr_intr_test_START (10)
#define SOC_HISIMC_TEST_CTRL0_hisimctxerr_intr_test_END (10)
#define SOC_HISIMC_TEST_CTRL0_hisimcrxerr_intr_test_START (11)
#define SOC_HISIMC_TEST_CTRL0_hisimcrxerr_intr_test_END (11)
#define SOC_HISIMC_TEST_CTRL0_rxchartout_intr_test_START (12)
#define SOC_HISIMC_TEST_CTRL0_rxchartout_intr_test_END (12)
#define SOC_HISIMC_TEST_CTRL0_tx2rx_turn_tout_intr_test_START (13)
#define SOC_HISIMC_TEST_CTRL0_tx2rx_turn_tout_intr_test_END (13)
#define SOC_HISIMC_TEST_CTRL0_rdrxfifotout_intr_test_START (14)
#define SOC_HISIMC_TEST_CTRL0_rdrxfifotout_intr_test_END (14)
#define SOC_HISIMC_TEST_CTRL0_rxovfull_intr_test_START (15)
#define SOC_HISIMC_TEST_CTRL0_rxovfull_intr_test_END (15)
#define SOC_HISIMC_TEST_CTRL0_txovfull_intr_test_START (16)
#define SOC_HISIMC_TEST_CTRL0_txovfull_intr_test_END (16)
#define SOC_HISIMC_TEST_CTRL0_clkstop_intr_test_START (17)
#define SOC_HISIMC_TEST_CTRL0_clkstop_intr_test_END (17)
#define SOC_HISIMC_TEST_CTRL0_clkwakeup_intr_test_START (18)
#define SOC_HISIMC_TEST_CTRL0_clkwakeup_intr_test_END (18)
#define SOC_HISIMC_TEST_CTRL0_writetxfifo_intr_test_START (19)
#define SOC_HISIMC_TEST_CTRL0_writetxfifo_intr_test_END (19)
#define SOC_HISIMC_TEST_CTRL0_rdrxfifo_intr_test_START (20)
#define SOC_HISIMC_TEST_CTRL0_rdrxfifo_intr_test_END (20)
#define SOC_HISIMC_TEST_CTRL0_atr_start_error_intr_test_START (21)
#define SOC_HISIMC_TEST_CTRL0_atr_start_error_intr_test_END (21)
#define SOC_HISIMC_TEST_CTRL0_clkstop_enter_error_intr_test_START (22)
#define SOC_HISIMC_TEST_CTRL0_clkstop_enter_error_intr_test_END (22)
#define SOC_HISIMC_TEST_CTRL0_rdtxfifo_empty_intr_test_START (23)
#define SOC_HISIMC_TEST_CTRL0_rdtxfifo_empty_intr_test_END (23)
#define SOC_HISIMC_TEST_CTRL0_rdrxfifo_empty_intr_test_START (24)
#define SOC_HISIMC_TEST_CTRL0_rdrxfifo_empty_intr_test_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisimc_datain : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HISIMC_TEST_STAT_UNION;
#endif
#define SOC_HISIMC_TEST_STAT_hisimc_datain_START (0)
#define SOC_HISIMC_TEST_STAT_hisimc_datain_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txfifo_data_flag0 : 32;
    } reg;
} SOC_HISIMC_TXDATA_FLAG0_UNION;
#endif
#define SOC_HISIMC_TXDATA_FLAG0_txfifo_data_flag0_START (0)
#define SOC_HISIMC_TXDATA_FLAG0_txfifo_data_flag0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txfifo_data_flag1 : 32;
    } reg;
} SOC_HISIMC_TXDATA_FLAG1_UNION;
#endif
#define SOC_HISIMC_TXDATA_FLAG1_txfifo_data_flag1_START (0)
#define SOC_HISIMC_TXDATA_FLAG1_txfifo_data_flag1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txfifo_data_flag2 : 32;
    } reg;
} SOC_HISIMC_TXDATA_FLAG2_UNION;
#endif
#define SOC_HISIMC_TXDATA_FLAG2_txfifo_data_flag2_START (0)
#define SOC_HISIMC_TXDATA_FLAG2_txfifo_data_flag2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txfifo_data_flag3 : 32;
    } reg;
} SOC_HISIMC_TXDATA_FLAG3_UNION;
#endif
#define SOC_HISIMC_TXDATA_FLAG3_txfifo_data_flag3_START (0)
#define SOC_HISIMC_TXDATA_FLAG3_txfifo_data_flag3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxfifo_clr_dly_num : 6;
        unsigned int txfifo_clr_dly_num : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_HISIMC_FIFO_CLR_DLY_UNION;
#endif
#define SOC_HISIMC_FIFO_CLR_DLY_rxfifo_clr_dly_num_START (0)
#define SOC_HISIMC_FIFO_CLR_DLY_rxfifo_clr_dly_num_END (5)
#define SOC_HISIMC_FIFO_CLR_DLY_txfifo_clr_dly_num_START (6)
#define SOC_HISIMC_FIFO_CLR_DLY_txfifo_clr_dly_num_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sync2pclk_dly_num : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HISIMC_SYNC_TO_PCLK_DLY_UNION;
#endif
#define SOC_HISIMC_SYNC_TO_PCLK_DLY_sync2pclk_dly_num_START (0)
#define SOC_HISIMC_SYNC_TO_PCLK_DLY_sync2pclk_dly_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisimc_version_id : 32;
    } reg;
} SOC_HISIMC_VERSION_ID_UNION;
#endif
#define SOC_HISIMC_VERSION_ID_hisimc_version_id_START (0)
#define SOC_HISIMC_VERSION_ID_hisimc_version_id_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
