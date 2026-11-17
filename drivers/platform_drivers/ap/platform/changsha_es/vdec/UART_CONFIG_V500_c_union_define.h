#ifndef __UART_CONFIG_V500_C_UNION_DEFINE_H__
#define __UART_CONFIG_V500_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int baud_div_int : 16 ;
        unsigned int baud_div_frac : 6 ;
        unsigned int reserved_0 : 10 ;
    } bits;
    unsigned int u32;
} U_UART_BAUD_CFG;
typedef union {
    struct {
        unsigned int data_bit : 2 ;
        unsigned int parity_bit : 3 ;
        unsigned int stop_bit : 1 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_UART_FRAME_CFG;
typedef union {
    struct {
        unsigned int tx_fifo_level_sel : 3 ;
        unsigned int rx_fifo_level_sel : 3 ;
        unsigned int rts_fifo_level_sel : 3 ;
        unsigned int reserved_0 : 23 ;
    } bits;
    unsigned int u32;
} U_UART_FIFO_CFG;
typedef union {
    struct {
        unsigned int tx_fifo_data : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_UART_TX_FIFO;
typedef union {
    struct {
        unsigned int rx_fifo_data : 8 ;
        unsigned int frame_err : 1 ;
        unsigned int parity_err : 1 ;
        unsigned int break_err : 1 ;
        unsigned int overrun_err : 1 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_UART_RX_FIFO;
typedef union {
    struct {
        unsigned int tx_busy : 1 ;
        unsigned int rx_busy : 1 ;
        unsigned int tx_fifo_empty : 1 ;
        unsigned int tx_fifo_full : 1 ;
        unsigned int rx_fifo_empty : 1 ;
        unsigned int rx_fifo_full : 1 ;
        unsigned int uart_cts : 1 ;
        unsigned int uart_ri : 1 ;
        unsigned int uart_dcd : 1 ;
        unsigned int uart_dsr : 1 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_UART_STAT;
typedef union {
    struct {
        unsigned int rx_int_clr : 1 ;
        unsigned int tx_int_clr : 1 ;
        unsigned int rx_timeout_int_clr : 1 ;
        unsigned int frame_err_int_clr : 1 ;
        unsigned int parity_err_int_clr : 1 ;
        unsigned int break_err_int_clr : 1 ;
        unsigned int overrun_err_int_clr : 1 ;
        unsigned int uart_cts_int_clr : 1 ;
        unsigned int uart_ri_int_clr : 1 ;
        unsigned int uart_dcd_int_clr : 1 ;
        unsigned int uart_dsr_int_clr : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_UART_INT_CLR;
typedef union {
    struct {
        unsigned int rx_int_msk : 1 ;
        unsigned int tx_int_msk : 1 ;
        unsigned int rx_timeout_int_msk : 1 ;
        unsigned int frame_err_int_msk : 1 ;
        unsigned int parity_err_int_msk : 1 ;
        unsigned int break_err_int_msk : 1 ;
        unsigned int overrun_err_int_msk : 1 ;
        unsigned int uart_cts_int_msk : 1 ;
        unsigned int uart_ri_int_msk : 1 ;
        unsigned int uart_dcd_int_msk : 1 ;
        unsigned int uart_dsr_int_msk : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_UART_INT_MSK;
typedef union {
    struct {
        unsigned int rx_int_raw : 1 ;
        unsigned int tx_int_raw : 1 ;
        unsigned int rx_timeout_int_raw : 1 ;
        unsigned int frame_err_int_raw : 1 ;
        unsigned int parity_err_int_raw : 1 ;
        unsigned int break_err_int_raw : 1 ;
        unsigned int overrun_err_int_raw : 1 ;
        unsigned int uart_cts_int_raw : 1 ;
        unsigned int uart_ri_int_raw : 1 ;
        unsigned int uart_dcd_int_raw : 1 ;
        unsigned int uart_dsr_int_raw : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_UART_INT_RAW;
typedef union {
    struct {
        unsigned int rx_int_mskd : 1 ;
        unsigned int tx_int_mskd : 1 ;
        unsigned int rx_timeout_int_mskd : 1 ;
        unsigned int frame_err_int_mskd : 1 ;
        unsigned int parity_err_int_mskd : 1 ;
        unsigned int break_err_int_mskd : 1 ;
        unsigned int overrun_err_int_mskd : 1 ;
        unsigned int uart_cts_int_mskd : 1 ;
        unsigned int uart_ri_int_mskd : 1 ;
        unsigned int uart_dcd_int_mskd : 1 ;
        unsigned int uart_dsr_int_mskd : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_UART_INT_STAT;
typedef union {
    struct {
        unsigned int uart_en : 1 ;
        unsigned int uart_tx_en : 1 ;
        unsigned int uart_rx_en : 1 ;
        unsigned int uart_cts_en : 1 ;
        unsigned int uart_rts_en : 1 ;
        unsigned int tx_dma_en : 1 ;
        unsigned int rx_dma_en : 1 ;
        unsigned int break_req : 1 ;
        unsigned int err_intr_to_dmareq : 1 ;
        unsigned int loop_back_test : 1 ;
        unsigned int fifo_en : 1 ;
        unsigned int uart_dtr : 1 ;
        unsigned int uart_rts : 1 ;
        unsigned int uart_out1 : 1 ;
        unsigned int uart_out2 : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int uart_config_msk : 16 ;
    } bits;
    unsigned int u32;
} U_UART_CONFIG;
typedef union {
    struct {
        unsigned int baud0 : 1 ;
        unsigned int rx_ctl_state : 3 ;
        unsigned int rx_fifo_wr_en : 1 ;
        unsigned int rx_frame_end : 1 ;
        unsigned int clr_shift_reg : 1 ;
        unsigned int tx_ctl_state : 3 ;
        unsigned int tx_frame_end : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_UART_DEBUG;
typedef union {
    struct {
        unsigned int hi_uart_id : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_UART_ID;
typedef struct {
    volatile U_UART_BAUD_CFG UART_BAUD_CFG ;
    volatile U_UART_FRAME_CFG UART_FRAME_CFG ;
    volatile U_UART_FIFO_CFG UART_FIFO_CFG ;
    volatile U_UART_TX_FIFO UART_TX_FIFO ;
    volatile U_UART_RX_FIFO UART_RX_FIFO ;
    volatile U_UART_STAT UART_STAT ;
    volatile U_UART_INT_CLR UART_INT_CLR ;
    volatile U_UART_INT_MSK UART_INT_MSK ;
    volatile U_UART_INT_RAW UART_INT_RAW ;
    volatile U_UART_INT_STAT UART_INT_STAT ;
    volatile U_UART_CONFIG UART_CONFIG ;
    volatile unsigned int reserved_7[9] ;
    volatile U_UART_DEBUG UART_DEBUG ;
    volatile unsigned int reserved_8[43] ;
    volatile U_UART_ID UART_ID ;
} S_UART_CONFIG_V500_REGS_TYPE;
#endif
