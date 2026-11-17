#ifndef __SOC_HI_UART_V500_INTERFACE_H__
#define __SOC_HI_UART_V500_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HI_UART_V500_UART_BAUD_CFG_ADDR(base) ((base) + (0x000UL))
#define SOC_HI_UART_V500_UART_FRAME_CFG_ADDR(base) ((base) + (0x004UL))
#define SOC_HI_UART_V500_UART_FIFO_CFG_ADDR(base) ((base) + (0x008UL))
#define SOC_HI_UART_V500_UART_TX_FIFO_ADDR(base) ((base) + (0x400UL))
#define SOC_HI_UART_V500_UART_RX_FIFO_ADDR(base) ((base) + (0x800UL))
#define SOC_HI_UART_V500_UART_STAT_ADDR(base) ((base) + (0x014UL))
#define SOC_HI_UART_V500_UART_INT_CLR_ADDR(base) ((base) + (0x018UL))
#define SOC_HI_UART_V500_UART_INT_MSK_ADDR(base) ((base) + (0x01CUL))
#define SOC_HI_UART_V500_UART_INT_RAW_ADDR(base) ((base) + (0x020UL))
#define SOC_HI_UART_V500_UART_INT_STAT_ADDR(base) ((base) + (0x024UL))
#define SOC_HI_UART_V500_UART_CONFIG_ADDR(base) ((base) + (0x028UL))
#define SOC_HI_UART_V500_UART_DEBUG_ADDR(base) ((base) + (0x050UL))
#define SOC_HI_UART_V500_UART_ID_ADDR(base) ((base) + (0x100UL))
#else
#define SOC_HI_UART_V500_UART_BAUD_CFG_ADDR(base) ((base) + (0x000))
#define SOC_HI_UART_V500_UART_FRAME_CFG_ADDR(base) ((base) + (0x004))
#define SOC_HI_UART_V500_UART_FIFO_CFG_ADDR(base) ((base) + (0x008))
#define SOC_HI_UART_V500_UART_TX_FIFO_ADDR(base) ((base) + (0x400))
#define SOC_HI_UART_V500_UART_RX_FIFO_ADDR(base) ((base) + (0x800))
#define SOC_HI_UART_V500_UART_STAT_ADDR(base) ((base) + (0x014))
#define SOC_HI_UART_V500_UART_INT_CLR_ADDR(base) ((base) + (0x018))
#define SOC_HI_UART_V500_UART_INT_MSK_ADDR(base) ((base) + (0x01C))
#define SOC_HI_UART_V500_UART_INT_RAW_ADDR(base) ((base) + (0x020))
#define SOC_HI_UART_V500_UART_INT_STAT_ADDR(base) ((base) + (0x024))
#define SOC_HI_UART_V500_UART_CONFIG_ADDR(base) ((base) + (0x028))
#define SOC_HI_UART_V500_UART_DEBUG_ADDR(base) ((base) + (0x050))
#define SOC_HI_UART_V500_UART_ID_ADDR(base) ((base) + (0x100))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int baud_div_int : 16;
        unsigned int baud_div_frac : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_HI_UART_V500_UART_BAUD_CFG_UNION;
#endif
#define SOC_HI_UART_V500_UART_BAUD_CFG_baud_div_int_START (0)
#define SOC_HI_UART_V500_UART_BAUD_CFG_baud_div_int_END (15)
#define SOC_HI_UART_V500_UART_BAUD_CFG_baud_div_frac_START (16)
#define SOC_HI_UART_V500_UART_BAUD_CFG_baud_div_frac_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_bit : 2;
        unsigned int parity_bit : 3;
        unsigned int stop_bit : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_HI_UART_V500_UART_FRAME_CFG_UNION;
#endif
#define SOC_HI_UART_V500_UART_FRAME_CFG_data_bit_START (0)
#define SOC_HI_UART_V500_UART_FRAME_CFG_data_bit_END (1)
#define SOC_HI_UART_V500_UART_FRAME_CFG_parity_bit_START (2)
#define SOC_HI_UART_V500_UART_FRAME_CFG_parity_bit_END (4)
#define SOC_HI_UART_V500_UART_FRAME_CFG_stop_bit_START (5)
#define SOC_HI_UART_V500_UART_FRAME_CFG_stop_bit_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_fifo_level_sel : 3;
        unsigned int rx_fifo_level_sel : 3;
        unsigned int rts_fifo_level_sel : 3;
        unsigned int reserved : 23;
    } reg;
} SOC_HI_UART_V500_UART_FIFO_CFG_UNION;
#endif
#define SOC_HI_UART_V500_UART_FIFO_CFG_tx_fifo_level_sel_START (0)
#define SOC_HI_UART_V500_UART_FIFO_CFG_tx_fifo_level_sel_END (2)
#define SOC_HI_UART_V500_UART_FIFO_CFG_rx_fifo_level_sel_START (3)
#define SOC_HI_UART_V500_UART_FIFO_CFG_rx_fifo_level_sel_END (5)
#define SOC_HI_UART_V500_UART_FIFO_CFG_rts_fifo_level_sel_START (6)
#define SOC_HI_UART_V500_UART_FIFO_CFG_rts_fifo_level_sel_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_fifo_data : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HI_UART_V500_UART_TX_FIFO_UNION;
#endif
#define SOC_HI_UART_V500_UART_TX_FIFO_tx_fifo_data_START (0)
#define SOC_HI_UART_V500_UART_TX_FIFO_tx_fifo_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_fifo_data : 8;
        unsigned int frame_err : 1;
        unsigned int parity_err : 1;
        unsigned int break_err : 1;
        unsigned int overrun_err : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_HI_UART_V500_UART_RX_FIFO_UNION;
#endif
#define SOC_HI_UART_V500_UART_RX_FIFO_rx_fifo_data_START (0)
#define SOC_HI_UART_V500_UART_RX_FIFO_rx_fifo_data_END (7)
#define SOC_HI_UART_V500_UART_RX_FIFO_frame_err_START (8)
#define SOC_HI_UART_V500_UART_RX_FIFO_frame_err_END (8)
#define SOC_HI_UART_V500_UART_RX_FIFO_parity_err_START (9)
#define SOC_HI_UART_V500_UART_RX_FIFO_parity_err_END (9)
#define SOC_HI_UART_V500_UART_RX_FIFO_break_err_START (10)
#define SOC_HI_UART_V500_UART_RX_FIFO_break_err_END (10)
#define SOC_HI_UART_V500_UART_RX_FIFO_overrun_err_START (11)
#define SOC_HI_UART_V500_UART_RX_FIFO_overrun_err_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_busy : 1;
        unsigned int rx_busy : 1;
        unsigned int tx_fifo_empty : 1;
        unsigned int tx_fifo_full : 1;
        unsigned int rx_fifo_empty : 1;
        unsigned int rx_fifo_full : 1;
        unsigned int uart_cts : 1;
        unsigned int uart_ri : 1;
        unsigned int uart_dcd : 1;
        unsigned int uart_dsr : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_HI_UART_V500_UART_STAT_UNION;
#endif
#define SOC_HI_UART_V500_UART_STAT_tx_busy_START (0)
#define SOC_HI_UART_V500_UART_STAT_tx_busy_END (0)
#define SOC_HI_UART_V500_UART_STAT_rx_busy_START (1)
#define SOC_HI_UART_V500_UART_STAT_rx_busy_END (1)
#define SOC_HI_UART_V500_UART_STAT_tx_fifo_empty_START (2)
#define SOC_HI_UART_V500_UART_STAT_tx_fifo_empty_END (2)
#define SOC_HI_UART_V500_UART_STAT_tx_fifo_full_START (3)
#define SOC_HI_UART_V500_UART_STAT_tx_fifo_full_END (3)
#define SOC_HI_UART_V500_UART_STAT_rx_fifo_empty_START (4)
#define SOC_HI_UART_V500_UART_STAT_rx_fifo_empty_END (4)
#define SOC_HI_UART_V500_UART_STAT_rx_fifo_full_START (5)
#define SOC_HI_UART_V500_UART_STAT_rx_fifo_full_END (5)
#define SOC_HI_UART_V500_UART_STAT_uart_cts_START (6)
#define SOC_HI_UART_V500_UART_STAT_uart_cts_END (6)
#define SOC_HI_UART_V500_UART_STAT_uart_ri_START (7)
#define SOC_HI_UART_V500_UART_STAT_uart_ri_END (7)
#define SOC_HI_UART_V500_UART_STAT_uart_dcd_START (8)
#define SOC_HI_UART_V500_UART_STAT_uart_dcd_END (8)
#define SOC_HI_UART_V500_UART_STAT_uart_dsr_START (9)
#define SOC_HI_UART_V500_UART_STAT_uart_dsr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_int_clr : 1;
        unsigned int tx_int_clr : 1;
        unsigned int rx_timeout_int_clr : 1;
        unsigned int frame_err_int_clr : 1;
        unsigned int parity_err_int_clr : 1;
        unsigned int break_err_int_clr : 1;
        unsigned int overrun_err_int_clr : 1;
        unsigned int uart_cts_int_clr : 1;
        unsigned int uart_ri_int_clr : 1;
        unsigned int uart_dcd_int_clr : 1;
        unsigned int uart_dsr_int_clr : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_HI_UART_V500_UART_INT_CLR_UNION;
#endif
#define SOC_HI_UART_V500_UART_INT_CLR_rx_int_clr_START (0)
#define SOC_HI_UART_V500_UART_INT_CLR_rx_int_clr_END (0)
#define SOC_HI_UART_V500_UART_INT_CLR_tx_int_clr_START (1)
#define SOC_HI_UART_V500_UART_INT_CLR_tx_int_clr_END (1)
#define SOC_HI_UART_V500_UART_INT_CLR_rx_timeout_int_clr_START (2)
#define SOC_HI_UART_V500_UART_INT_CLR_rx_timeout_int_clr_END (2)
#define SOC_HI_UART_V500_UART_INT_CLR_frame_err_int_clr_START (3)
#define SOC_HI_UART_V500_UART_INT_CLR_frame_err_int_clr_END (3)
#define SOC_HI_UART_V500_UART_INT_CLR_parity_err_int_clr_START (4)
#define SOC_HI_UART_V500_UART_INT_CLR_parity_err_int_clr_END (4)
#define SOC_HI_UART_V500_UART_INT_CLR_break_err_int_clr_START (5)
#define SOC_HI_UART_V500_UART_INT_CLR_break_err_int_clr_END (5)
#define SOC_HI_UART_V500_UART_INT_CLR_overrun_err_int_clr_START (6)
#define SOC_HI_UART_V500_UART_INT_CLR_overrun_err_int_clr_END (6)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_cts_int_clr_START (7)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_cts_int_clr_END (7)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_ri_int_clr_START (8)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_ri_int_clr_END (8)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_dcd_int_clr_START (9)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_dcd_int_clr_END (9)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_dsr_int_clr_START (10)
#define SOC_HI_UART_V500_UART_INT_CLR_uart_dsr_int_clr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_int_msk : 1;
        unsigned int tx_int_msk : 1;
        unsigned int rx_timeout_int_msk : 1;
        unsigned int frame_err_int_msk : 1;
        unsigned int parity_err_int_msk : 1;
        unsigned int break_err_int_msk : 1;
        unsigned int overrun_err_int_msk : 1;
        unsigned int uart_cts_int_msk : 1;
        unsigned int uart_ri_int_msk : 1;
        unsigned int uart_dcd_int_msk : 1;
        unsigned int uart_dsr_int_msk : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_HI_UART_V500_UART_INT_MSK_UNION;
#endif
#define SOC_HI_UART_V500_UART_INT_MSK_rx_int_msk_START (0)
#define SOC_HI_UART_V500_UART_INT_MSK_rx_int_msk_END (0)
#define SOC_HI_UART_V500_UART_INT_MSK_tx_int_msk_START (1)
#define SOC_HI_UART_V500_UART_INT_MSK_tx_int_msk_END (1)
#define SOC_HI_UART_V500_UART_INT_MSK_rx_timeout_int_msk_START (2)
#define SOC_HI_UART_V500_UART_INT_MSK_rx_timeout_int_msk_END (2)
#define SOC_HI_UART_V500_UART_INT_MSK_frame_err_int_msk_START (3)
#define SOC_HI_UART_V500_UART_INT_MSK_frame_err_int_msk_END (3)
#define SOC_HI_UART_V500_UART_INT_MSK_parity_err_int_msk_START (4)
#define SOC_HI_UART_V500_UART_INT_MSK_parity_err_int_msk_END (4)
#define SOC_HI_UART_V500_UART_INT_MSK_break_err_int_msk_START (5)
#define SOC_HI_UART_V500_UART_INT_MSK_break_err_int_msk_END (5)
#define SOC_HI_UART_V500_UART_INT_MSK_overrun_err_int_msk_START (6)
#define SOC_HI_UART_V500_UART_INT_MSK_overrun_err_int_msk_END (6)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_cts_int_msk_START (7)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_cts_int_msk_END (7)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_ri_int_msk_START (8)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_ri_int_msk_END (8)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_dcd_int_msk_START (9)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_dcd_int_msk_END (9)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_dsr_int_msk_START (10)
#define SOC_HI_UART_V500_UART_INT_MSK_uart_dsr_int_msk_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_int_raw : 1;
        unsigned int tx_int_raw : 1;
        unsigned int rx_timeout_int_raw : 1;
        unsigned int frame_err_int_raw : 1;
        unsigned int parity_err_int_raw : 1;
        unsigned int break_err_int_raw : 1;
        unsigned int overrun_err_int_raw : 1;
        unsigned int uart_cts_int_raw : 1;
        unsigned int uart_ri_int_raw : 1;
        unsigned int uart_dcd_int_raw : 1;
        unsigned int uart_dsr_int_raw : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_HI_UART_V500_UART_INT_RAW_UNION;
#endif
#define SOC_HI_UART_V500_UART_INT_RAW_rx_int_raw_START (0)
#define SOC_HI_UART_V500_UART_INT_RAW_rx_int_raw_END (0)
#define SOC_HI_UART_V500_UART_INT_RAW_tx_int_raw_START (1)
#define SOC_HI_UART_V500_UART_INT_RAW_tx_int_raw_END (1)
#define SOC_HI_UART_V500_UART_INT_RAW_rx_timeout_int_raw_START (2)
#define SOC_HI_UART_V500_UART_INT_RAW_rx_timeout_int_raw_END (2)
#define SOC_HI_UART_V500_UART_INT_RAW_frame_err_int_raw_START (3)
#define SOC_HI_UART_V500_UART_INT_RAW_frame_err_int_raw_END (3)
#define SOC_HI_UART_V500_UART_INT_RAW_parity_err_int_raw_START (4)
#define SOC_HI_UART_V500_UART_INT_RAW_parity_err_int_raw_END (4)
#define SOC_HI_UART_V500_UART_INT_RAW_break_err_int_raw_START (5)
#define SOC_HI_UART_V500_UART_INT_RAW_break_err_int_raw_END (5)
#define SOC_HI_UART_V500_UART_INT_RAW_overrun_err_int_raw_START (6)
#define SOC_HI_UART_V500_UART_INT_RAW_overrun_err_int_raw_END (6)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_cts_int_raw_START (7)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_cts_int_raw_END (7)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_ri_int_raw_START (8)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_ri_int_raw_END (8)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_dcd_int_raw_START (9)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_dcd_int_raw_END (9)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_dsr_int_raw_START (10)
#define SOC_HI_UART_V500_UART_INT_RAW_uart_dsr_int_raw_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_int_mskd : 1;
        unsigned int tx_int_mskd : 1;
        unsigned int rx_timeout_int_mskd : 1;
        unsigned int frame_err_int_mskd : 1;
        unsigned int parity_err_int_mskd : 1;
        unsigned int break_err_int_mskd : 1;
        unsigned int overrun_err_int_mskd : 1;
        unsigned int uart_cts_int_mskd : 1;
        unsigned int uart_ri_int_mskd : 1;
        unsigned int uart_dcd_int_mskd : 1;
        unsigned int uart_dsr_int_mskd : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_HI_UART_V500_UART_INT_STAT_UNION;
#endif
#define SOC_HI_UART_V500_UART_INT_STAT_rx_int_mskd_START (0)
#define SOC_HI_UART_V500_UART_INT_STAT_rx_int_mskd_END (0)
#define SOC_HI_UART_V500_UART_INT_STAT_tx_int_mskd_START (1)
#define SOC_HI_UART_V500_UART_INT_STAT_tx_int_mskd_END (1)
#define SOC_HI_UART_V500_UART_INT_STAT_rx_timeout_int_mskd_START (2)
#define SOC_HI_UART_V500_UART_INT_STAT_rx_timeout_int_mskd_END (2)
#define SOC_HI_UART_V500_UART_INT_STAT_frame_err_int_mskd_START (3)
#define SOC_HI_UART_V500_UART_INT_STAT_frame_err_int_mskd_END (3)
#define SOC_HI_UART_V500_UART_INT_STAT_parity_err_int_mskd_START (4)
#define SOC_HI_UART_V500_UART_INT_STAT_parity_err_int_mskd_END (4)
#define SOC_HI_UART_V500_UART_INT_STAT_break_err_int_mskd_START (5)
#define SOC_HI_UART_V500_UART_INT_STAT_break_err_int_mskd_END (5)
#define SOC_HI_UART_V500_UART_INT_STAT_overrun_err_int_mskd_START (6)
#define SOC_HI_UART_V500_UART_INT_STAT_overrun_err_int_mskd_END (6)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_cts_int_mskd_START (7)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_cts_int_mskd_END (7)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_ri_int_mskd_START (8)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_ri_int_mskd_END (8)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_dcd_int_mskd_START (9)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_dcd_int_mskd_END (9)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_dsr_int_mskd_START (10)
#define SOC_HI_UART_V500_UART_INT_STAT_uart_dsr_int_mskd_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uart_en : 1;
        unsigned int uart_tx_en : 1;
        unsigned int uart_rx_en : 1;
        unsigned int uart_cts_en : 1;
        unsigned int uart_rts_en : 1;
        unsigned int tx_dma_en : 1;
        unsigned int rx_dma_en : 1;
        unsigned int break_req : 1;
        unsigned int err_intr_to_dmareq : 1;
        unsigned int loop_back_test : 1;
        unsigned int fifo_en : 1;
        unsigned int uart_dtr : 1;
        unsigned int uart_rts : 1;
        unsigned int uart_out1 : 1;
        unsigned int uart_out2 : 1;
        unsigned int reserved : 1;
        unsigned int uart_config_msk : 16;
    } reg;
} SOC_HI_UART_V500_UART_CONFIG_UNION;
#endif
#define SOC_HI_UART_V500_UART_CONFIG_uart_en_START (0)
#define SOC_HI_UART_V500_UART_CONFIG_uart_en_END (0)
#define SOC_HI_UART_V500_UART_CONFIG_uart_tx_en_START (1)
#define SOC_HI_UART_V500_UART_CONFIG_uart_tx_en_END (1)
#define SOC_HI_UART_V500_UART_CONFIG_uart_rx_en_START (2)
#define SOC_HI_UART_V500_UART_CONFIG_uart_rx_en_END (2)
#define SOC_HI_UART_V500_UART_CONFIG_uart_cts_en_START (3)
#define SOC_HI_UART_V500_UART_CONFIG_uart_cts_en_END (3)
#define SOC_HI_UART_V500_UART_CONFIG_uart_rts_en_START (4)
#define SOC_HI_UART_V500_UART_CONFIG_uart_rts_en_END (4)
#define SOC_HI_UART_V500_UART_CONFIG_tx_dma_en_START (5)
#define SOC_HI_UART_V500_UART_CONFIG_tx_dma_en_END (5)
#define SOC_HI_UART_V500_UART_CONFIG_rx_dma_en_START (6)
#define SOC_HI_UART_V500_UART_CONFIG_rx_dma_en_END (6)
#define SOC_HI_UART_V500_UART_CONFIG_break_req_START (7)
#define SOC_HI_UART_V500_UART_CONFIG_break_req_END (7)
#define SOC_HI_UART_V500_UART_CONFIG_err_intr_to_dmareq_START (8)
#define SOC_HI_UART_V500_UART_CONFIG_err_intr_to_dmareq_END (8)
#define SOC_HI_UART_V500_UART_CONFIG_loop_back_test_START (9)
#define SOC_HI_UART_V500_UART_CONFIG_loop_back_test_END (9)
#define SOC_HI_UART_V500_UART_CONFIG_fifo_en_START (10)
#define SOC_HI_UART_V500_UART_CONFIG_fifo_en_END (10)
#define SOC_HI_UART_V500_UART_CONFIG_uart_dtr_START (11)
#define SOC_HI_UART_V500_UART_CONFIG_uart_dtr_END (11)
#define SOC_HI_UART_V500_UART_CONFIG_uart_rts_START (12)
#define SOC_HI_UART_V500_UART_CONFIG_uart_rts_END (12)
#define SOC_HI_UART_V500_UART_CONFIG_uart_out1_START (13)
#define SOC_HI_UART_V500_UART_CONFIG_uart_out1_END (13)
#define SOC_HI_UART_V500_UART_CONFIG_uart_out2_START (14)
#define SOC_HI_UART_V500_UART_CONFIG_uart_out2_END (14)
#define SOC_HI_UART_V500_UART_CONFIG_uart_config_msk_START (16)
#define SOC_HI_UART_V500_UART_CONFIG_uart_config_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int baud0 : 1;
        unsigned int rx_ctl_state : 3;
        unsigned int rx_fifo_wr_en : 1;
        unsigned int rx_frame_end : 1;
        unsigned int clr_shift_reg : 1;
        unsigned int tx_ctl_state : 3;
        unsigned int tx_frame_end : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_HI_UART_V500_UART_DEBUG_UNION;
#endif
#define SOC_HI_UART_V500_UART_DEBUG_baud0_START (0)
#define SOC_HI_UART_V500_UART_DEBUG_baud0_END (0)
#define SOC_HI_UART_V500_UART_DEBUG_rx_ctl_state_START (1)
#define SOC_HI_UART_V500_UART_DEBUG_rx_ctl_state_END (3)
#define SOC_HI_UART_V500_UART_DEBUG_rx_fifo_wr_en_START (4)
#define SOC_HI_UART_V500_UART_DEBUG_rx_fifo_wr_en_END (4)
#define SOC_HI_UART_V500_UART_DEBUG_rx_frame_end_START (5)
#define SOC_HI_UART_V500_UART_DEBUG_rx_frame_end_END (5)
#define SOC_HI_UART_V500_UART_DEBUG_clr_shift_reg_START (6)
#define SOC_HI_UART_V500_UART_DEBUG_clr_shift_reg_END (6)
#define SOC_HI_UART_V500_UART_DEBUG_tx_ctl_state_START (7)
#define SOC_HI_UART_V500_UART_DEBUG_tx_ctl_state_END (9)
#define SOC_HI_UART_V500_UART_DEBUG_tx_frame_end_START (10)
#define SOC_HI_UART_V500_UART_DEBUG_tx_frame_end_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hi_uart_id : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_UART_V500_UART_ID_UNION;
#endif
#define SOC_HI_UART_V500_UART_ID_hi_uart_id_START (0)
#define SOC_HI_UART_V500_UART_ID_hi_uart_id_END (15)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
