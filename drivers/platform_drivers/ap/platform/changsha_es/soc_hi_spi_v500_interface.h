#ifndef __SOC_HI_SPI_V500_INTERFACE_H__
#define __SOC_HI_SPI_V500_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HI_SPI_V500_SPI_CS_CTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_ADDR(base) ((base) + (0x004UL))
#define SOC_HI_SPI_V500_SPI_EN_ADDR(base) ((base) + (0x008UL))
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_ADDR(base) ((base) + (0x00CUL))
#define SOC_HI_SPI_V500_INTR_SPI_MASK_ADDR(base) ((base) + (0x010UL))
#define SOC_HI_SPI_V500_SPI_DIN_ADDR(base) ((base) + (0x014UL))
#define SOC_HI_SPI_V500_SPI_DOUT_ADDR(base) ((base) + (0x018UL))
#define SOC_HI_SPI_V500_SPI_STATE_ADDR(base) ((base) + (0x01CUL))
#define SOC_HI_SPI_V500_INTR_SPI_RAW_ADDR(base) ((base) + (0x020UL))
#define SOC_HI_SPI_V500_INTR_SPI_ADDR(base) ((base) + (0x024UL))
#define SOC_HI_SPI_V500_INTR_SPI_CLR_ADDR(base) ((base) + (0x028UL))
#define SOC_HI_SPI_V500_SPIVERSION_ADDR(base) ((base) + (0xFE0UL))
#else
#define SOC_HI_SPI_V500_SPI_CS_CTRL_ADDR(base) ((base) + (0x000))
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_ADDR(base) ((base) + (0x004))
#define SOC_HI_SPI_V500_SPI_EN_ADDR(base) ((base) + (0x008))
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_ADDR(base) ((base) + (0x00C))
#define SOC_HI_SPI_V500_INTR_SPI_MASK_ADDR(base) ((base) + (0x010))
#define SOC_HI_SPI_V500_SPI_DIN_ADDR(base) ((base) + (0x014))
#define SOC_HI_SPI_V500_SPI_DOUT_ADDR(base) ((base) + (0x018))
#define SOC_HI_SPI_V500_SPI_STATE_ADDR(base) ((base) + (0x01C))
#define SOC_HI_SPI_V500_INTR_SPI_RAW_ADDR(base) ((base) + (0x020))
#define SOC_HI_SPI_V500_INTR_SPI_ADDR(base) ((base) + (0x024))
#define SOC_HI_SPI_V500_INTR_SPI_CLR_ADDR(base) ((base) + (0x028))
#define SOC_HI_SPI_V500_SPIVERSION_ADDR(base) ((base) + (0xFE0))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_ctrl_en : 1;
        unsigned int cs_cnt_ini : 31;
    } reg;
} SOC_HI_SPI_V500_SPI_CS_CTRL_UNION;
#endif
#define SOC_HI_SPI_V500_SPI_CS_CTRL_cs_ctrl_en_START (0)
#define SOC_HI_SPI_V500_SPI_CS_CTRL_cs_ctrl_en_END (0)
#define SOC_HI_SPI_V500_SPI_CS_CTRL_cs_cnt_ini_START (1)
#define SOC_HI_SPI_V500_SPI_CS_CTRL_cs_cnt_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int loop_back : 1;
        unsigned int clk_polarity : 1;
        unsigned int clk_phase : 1;
        unsigned int div_ratio_pre : 8;
        unsigned int div_ratio_post : 8;
        unsigned int frame_size : 5;
        unsigned int hi_spd : 1;
        unsigned int dma_en_tx : 1;
        unsigned int dma_en_rx : 1;
        unsigned int timeout_limit_cnt_sel : 2;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_HI_SPI_V500_SPI_COMMON_CTRL_UNION;
#endif
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_loop_back_START (1)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_loop_back_END (1)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_clk_polarity_START (2)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_clk_polarity_END (2)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_clk_phase_START (3)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_clk_phase_END (3)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_div_ratio_pre_START (4)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_div_ratio_pre_END (11)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_div_ratio_post_START (12)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_div_ratio_post_END (19)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_frame_size_START (20)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_frame_size_END (24)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_hi_spd_START (25)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_hi_spd_END (25)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_dma_en_tx_START (26)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_dma_en_tx_END (26)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_dma_en_rx_START (27)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_dma_en_rx_END (27)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_timeout_limit_cnt_sel_START (28)
#define SOC_HI_SPI_V500_SPI_COMMON_CTRL_timeout_limit_cnt_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_SPI_V500_SPI_EN_UNION;
#endif
#define SOC_HI_SPI_V500_SPI_EN_spi_en_START (0)
#define SOC_HI_SPI_V500_SPI_EN_spi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_busrt_lvl_tx : 3;
        unsigned int intr_lvl_tx : 3;
        unsigned int dma_busrt_lvl_rx : 3;
        unsigned int intr_lvl_rx : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_UNION;
#endif
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_tx_START (0)
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_tx_END (2)
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_intr_lvl_tx_START (3)
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_intr_lvl_tx_END (5)
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_rx_START (6)
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_rx_END (8)
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_intr_lvl_rx_START (9)
#define SOC_HI_SPI_V500_SPI_FIFO_LEVEL_CTRL_intr_lvl_rx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow_mask : 1;
        unsigned int intr_rx_timeout_mask : 1;
        unsigned int intr_rx_mask : 1;
        unsigned int intr_tx_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HI_SPI_V500_INTR_SPI_MASK_UNION;
#endif
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_rx_overflow_mask_START (0)
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_rx_overflow_mask_END (0)
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_rx_timeout_mask_START (1)
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_rx_timeout_mask_END (1)
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_rx_mask_START (2)
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_rx_mask_END (2)
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_tx_mask_START (3)
#define SOC_HI_SPI_V500_INTR_SPI_MASK_intr_tx_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int din : 32;
    } reg;
} SOC_HI_SPI_V500_SPI_DIN_UNION;
#endif
#define SOC_HI_SPI_V500_SPI_DIN_din_START (0)
#define SOC_HI_SPI_V500_SPI_DIN_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dout : 32;
    } reg;
} SOC_HI_SPI_V500_SPI_DOUT_UNION;
#endif
#define SOC_HI_SPI_V500_SPI_DOUT_dout_START (0)
#define SOC_HI_SPI_V500_SPI_DOUT_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fifo_empty : 1;
        unsigned int tx_fifo_not_full : 1;
        unsigned int rx_fifo_not_empty : 1;
        unsigned int rx_fifo_full : 1;
        unsigned int busy : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_SPI_V500_SPI_STATE_UNION;
#endif
#define SOC_HI_SPI_V500_SPI_STATE_tx_fifo_empty_START (0)
#define SOC_HI_SPI_V500_SPI_STATE_tx_fifo_empty_END (0)
#define SOC_HI_SPI_V500_SPI_STATE_tx_fifo_not_full_START (1)
#define SOC_HI_SPI_V500_SPI_STATE_tx_fifo_not_full_END (1)
#define SOC_HI_SPI_V500_SPI_STATE_rx_fifo_not_empty_START (2)
#define SOC_HI_SPI_V500_SPI_STATE_rx_fifo_not_empty_END (2)
#define SOC_HI_SPI_V500_SPI_STATE_rx_fifo_full_START (3)
#define SOC_HI_SPI_V500_SPI_STATE_rx_fifo_full_END (3)
#define SOC_HI_SPI_V500_SPI_STATE_busy_START (4)
#define SOC_HI_SPI_V500_SPI_STATE_busy_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow_raw : 1;
        unsigned int intr_rx_timeout_raw : 1;
        unsigned int intr_rx_raw : 1;
        unsigned int intr_tx_raw : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HI_SPI_V500_INTR_SPI_RAW_UNION;
#endif
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_rx_overflow_raw_START (0)
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_rx_overflow_raw_END (0)
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_rx_timeout_raw_START (1)
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_rx_timeout_raw_END (1)
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_rx_raw_START (2)
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_rx_raw_END (2)
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_tx_raw_START (3)
#define SOC_HI_SPI_V500_INTR_SPI_RAW_intr_tx_raw_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow : 1;
        unsigned int intr_rx_timeout : 1;
        unsigned int intr_rx : 1;
        unsigned int intr_tx : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HI_SPI_V500_INTR_SPI_UNION;
#endif
#define SOC_HI_SPI_V500_INTR_SPI_intr_rx_overflow_START (0)
#define SOC_HI_SPI_V500_INTR_SPI_intr_rx_overflow_END (0)
#define SOC_HI_SPI_V500_INTR_SPI_intr_rx_timeout_START (1)
#define SOC_HI_SPI_V500_INTR_SPI_intr_rx_timeout_END (1)
#define SOC_HI_SPI_V500_INTR_SPI_intr_rx_START (2)
#define SOC_HI_SPI_V500_INTR_SPI_intr_rx_END (2)
#define SOC_HI_SPI_V500_INTR_SPI_intr_tx_START (3)
#define SOC_HI_SPI_V500_INTR_SPI_intr_tx_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow_clr : 1;
        unsigned int intr_rx_timeout_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HI_SPI_V500_INTR_SPI_CLR_UNION;
#endif
#define SOC_HI_SPI_V500_INTR_SPI_CLR_intr_rx_overflow_clr_START (0)
#define SOC_HI_SPI_V500_INTR_SPI_CLR_intr_rx_overflow_clr_END (0)
#define SOC_HI_SPI_V500_INTR_SPI_CLR_intr_rx_timeout_clr_START (1)
#define SOC_HI_SPI_V500_INTR_SPI_CLR_intr_rx_timeout_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_version : 32;
    } reg;
} SOC_HI_SPI_V500_SPIVERSION_UNION;
#endif
#define SOC_HI_SPI_V500_SPIVERSION_spi_version_START (0)
#define SOC_HI_SPI_V500_SPIVERSION_spi_version_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
