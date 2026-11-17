#ifndef __SOC_HI_SPI_V600_INTERFACE_H__
#define __SOC_HI_SPI_V600_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HI_SPI_V600_SPI_CS_CTRL_ADDR(base) (base)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_ADDR(base) ((base) + 0x004UL)
#define SOC_HI_SPI_V600_SPI_EN_ADDR(base) ((base) + 0x008UL)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_ADDR(base) ((base) + 0x00CUL)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_ADDR(base) ((base) + 0x010UL)
#define SOC_HI_SPI_V600_SPI_DIN_ADDR(base) ((base) + 0x014UL)
#define SOC_HI_SPI_V600_SPI_DOUT_ADDR(base) ((base) + 0x018UL)
#define SOC_HI_SPI_V600_SPI_STATE_ADDR(base) ((base) + 0x01CUL)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_ADDR(base) ((base) + 0x020UL)
#define SOC_HI_SPI_V600_INTR_SPI_ADDR(base) ((base) + 0x024UL)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_ADDR(base) ((base) + 0x028UL)
#define SOC_HI_SPI_V600_SPI_FLASH_CTRL_ADDR(base) ((base) + 0x02CUL)
#define SOC_HI_SPI_V600_FRAME_FORMAT_CTRL_ADDR(base) ((base) + 0x030UL)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_ADDR(base) ((base) + 0x034UL)
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_ADDR(base) ((base) + 0x038UL)
#define SOC_HI_SPI_V600_TPM_FLOW_STATE_ADDR(base) ((base) + 0x03CUL)
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_ADDR(base) ((base) + 0x0100UL)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_R_ADDR(base) ((base) + 0x0104UL)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_R_ADDR(base) ((base) + 0x0108UL)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_W_ADDR(base) ((base) + 0x010CUL)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_W_ADDR(base) ((base) + 0x0110UL)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_R_ADDR(base) ((base) + 0x0114UL)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_R_ADDR(base) ((base) + 0x0118UL)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_W_ADDR(base) ((base) + 0x011CUL)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_W_ADDR(base) ((base) + 0x0120UL)
#define SOC_HI_SPI_V600_SPI_DMA_CMD_START_ADDR(base) ((base) + 0x0124UL)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_ADDR(base) ((base) + 0x0128UL)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_ADDR(base) ((base) + 0x012CUL)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_ADDR(base) ((base) + 0x0130UL)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_ADDR(base) ((base) + 0x0134UL)
#define SOC_HI_SPI_V600_SPI_DMA_DFX_SEL_ADDR(base) ((base) + 0x0138UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_0_ADDR(base) ((base) + 0x013CUL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_1_ADDR(base) ((base) + 0x0140UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_2_ADDR(base) ((base) + 0x0144UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_3_ADDR(base) ((base) + 0x0148UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_4_ADDR(base) ((base) + 0x014CUL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_5_ADDR(base) ((base) + 0x0150UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_6_ADDR(base) ((base) + 0x0154UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_7_ADDR(base) ((base) + 0x0158UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_8_ADDR(base) ((base) + 0x015CUL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_9_ADDR(base) ((base) + 0x0160UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_10_ADDR(base) ((base) + 0x0164UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_11_ADDR(base) ((base) + 0x0168UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_12_ADDR(base) ((base) + 0x016CUL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_13_ADDR(base) ((base) + 0x0170UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_14_ADDR(base) ((base) + 0x0174UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_15_ADDR(base) ((base) + 0x0178UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_16_ADDR(base) ((base) + 0x017CUL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_17_ADDR(base) ((base) + 0x0180UL)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_18_ADDR(base) ((base) + 0x0184UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_0_ADDR(base) ((base) + 0x0188UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_1_ADDR(base) ((base) + 0x018CUL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_2_ADDR(base) ((base) + 0x0190UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_3_ADDR(base) ((base) + 0x0194UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_4_ADDR(base) ((base) + 0x0198UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_5_ADDR(base) ((base) + 0x019CUL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_6_ADDR(base) ((base) + 0x01A0UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_7_ADDR(base) ((base) + 0x01A4UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_8_ADDR(base) ((base) + 0x01A8UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_9_ADDR(base) ((base) + 0x01ACUL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_10_ADDR(base) ((base) + 0x01B0UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_11_ADDR(base) ((base) + 0x01B4UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_12_ADDR(base) ((base) + 0x01B8UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_13_ADDR(base) ((base) + 0x01BCUL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_14_ADDR(base) ((base) + 0x01C0UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_15_ADDR(base) ((base) + 0x01C4UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_16_ADDR(base) ((base) + 0x01C8UL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_17_ADDR(base) ((base) + 0x01CCUL)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_18_ADDR(base) ((base) + 0x01D0UL)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_ADDR(base) ((base) + 0x01D4UL)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_ADDR(base) ((base) + 0x01D8UL)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO0_ADDR(base) ((base) + 0x01DCUL)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO1_ADDR(base) ((base) + 0x01E0UL)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO2_ADDR(base) ((base) + 0x01E4UL)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO3_ADDR(base) ((base) + 0x01E8UL)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO0_ADDR(base) ((base) + 0x01ECUL)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO1_ADDR(base) ((base) + 0x01F0UL)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO2_ADDR(base) ((base) + 0x01F4UL)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO3_ADDR(base) ((base) + 0x01F8UL)
#define SOC_HI_SPI_V600_SPI_DMA_SOFT_RST_ADDR(base) ((base) + 0x01FCUL)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_0_ADDR(base) ((base) + 0x0200UL)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_1_ADDR(base) ((base) + 0x0204UL)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_2_ADDR(base) ((base) + 0x0208UL)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_3_ADDR(base) ((base) + 0x020CUL)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_0_ADDR(base) ((base) + 0x0210UL)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_1_ADDR(base) ((base) + 0x0214UL)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_2_ADDR(base) ((base) + 0x0218UL)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_3_ADDR(base) ((base) + 0x021CUL)
#define SOC_HI_SPI_V600_SPIVERSION_ADDR(base) ((base) + 0xFE0UL)
#else
#define SOC_HI_SPI_V600_SPI_CS_CTRL_ADDR(base) (base)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_ADDR(base) ((base) + 0x004)
#define SOC_HI_SPI_V600_SPI_EN_ADDR(base) ((base) + 0x008)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_ADDR(base) ((base) + 0x00C)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_ADDR(base) ((base) + 0x010)
#define SOC_HI_SPI_V600_SPI_DIN_ADDR(base) ((base) + 0x014)
#define SOC_HI_SPI_V600_SPI_DOUT_ADDR(base) ((base) + 0x018)
#define SOC_HI_SPI_V600_SPI_STATE_ADDR(base) ((base) + 0x01C)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_ADDR(base) ((base) + 0x020)
#define SOC_HI_SPI_V600_INTR_SPI_ADDR(base) ((base) + 0x024)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_ADDR(base) ((base) + 0x028)
#define SOC_HI_SPI_V600_SPI_FLASH_CTRL_ADDR(base) ((base) + 0x02C)
#define SOC_HI_SPI_V600_FRAME_FORMAT_CTRL_ADDR(base) ((base) + 0x030)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_ADDR(base) ((base) + 0x034)
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_ADDR(base) ((base) + 0x038)
#define SOC_HI_SPI_V600_TPM_FLOW_STATE_ADDR(base) ((base) + 0x03C)
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_ADDR(base) ((base) + 0x0100)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_R_ADDR(base) ((base) + 0x0104)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_R_ADDR(base) ((base) + 0x0108)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_W_ADDR(base) ((base) + 0x010C)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_W_ADDR(base) ((base) + 0x0110)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_R_ADDR(base) ((base) + 0x0114)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_R_ADDR(base) ((base) + 0x0118)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_W_ADDR(base) ((base) + 0x011C)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_W_ADDR(base) ((base) + 0x0120)
#define SOC_HI_SPI_V600_SPI_DMA_CMD_START_ADDR(base) ((base) + 0x0124)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_ADDR(base) ((base) + 0x0128)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_ADDR(base) ((base) + 0x012C)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_ADDR(base) ((base) + 0x0130)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_ADDR(base) ((base) + 0x0134)
#define SOC_HI_SPI_V600_SPI_DMA_DFX_SEL_ADDR(base) ((base) + 0x0138)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_0_ADDR(base) ((base) + 0x013C)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_1_ADDR(base) ((base) + 0x0140)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_2_ADDR(base) ((base) + 0x0144)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_3_ADDR(base) ((base) + 0x0148)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_4_ADDR(base) ((base) + 0x014C)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_5_ADDR(base) ((base) + 0x0150)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_6_ADDR(base) ((base) + 0x0154)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_7_ADDR(base) ((base) + 0x0158)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_8_ADDR(base) ((base) + 0x015C)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_9_ADDR(base) ((base) + 0x0160)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_10_ADDR(base) ((base) + 0x0164)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_11_ADDR(base) ((base) + 0x0168)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_12_ADDR(base) ((base) + 0x016C)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_13_ADDR(base) ((base) + 0x0170)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_14_ADDR(base) ((base) + 0x0174)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_15_ADDR(base) ((base) + 0x0178)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_16_ADDR(base) ((base) + 0x017C)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_17_ADDR(base) ((base) + 0x0180)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_18_ADDR(base) ((base) + 0x0184)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_0_ADDR(base) ((base) + 0x0188)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_1_ADDR(base) ((base) + 0x018C)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_2_ADDR(base) ((base) + 0x0190)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_3_ADDR(base) ((base) + 0x0194)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_4_ADDR(base) ((base) + 0x0198)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_5_ADDR(base) ((base) + 0x019C)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_6_ADDR(base) ((base) + 0x01A0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_7_ADDR(base) ((base) + 0x01A4)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_8_ADDR(base) ((base) + 0x01A8)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_9_ADDR(base) ((base) + 0x01AC)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_10_ADDR(base) ((base) + 0x01B0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_11_ADDR(base) ((base) + 0x01B4)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_12_ADDR(base) ((base) + 0x01B8)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_13_ADDR(base) ((base) + 0x01BC)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_14_ADDR(base) ((base) + 0x01C0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_15_ADDR(base) ((base) + 0x01C4)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_16_ADDR(base) ((base) + 0x01C8)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_17_ADDR(base) ((base) + 0x01CC)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_18_ADDR(base) ((base) + 0x01D0)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_ADDR(base) ((base) + 0x01D4)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_ADDR(base) ((base) + 0x01D8)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO0_ADDR(base) ((base) + 0x01DC)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO1_ADDR(base) ((base) + 0x01E0)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO2_ADDR(base) ((base) + 0x01E4)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO3_ADDR(base) ((base) + 0x01E8)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO0_ADDR(base) ((base) + 0x01EC)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO1_ADDR(base) ((base) + 0x01F0)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO2_ADDR(base) ((base) + 0x01F4)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO3_ADDR(base) ((base) + 0x01F8)
#define SOC_HI_SPI_V600_SPI_DMA_SOFT_RST_ADDR(base) ((base) + 0x01FC)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_0_ADDR(base) ((base) + 0x0200)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_1_ADDR(base) ((base) + 0x0204)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_2_ADDR(base) ((base) + 0x0208)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_3_ADDR(base) ((base) + 0x020C)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_0_ADDR(base) ((base) + 0x0210)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_1_ADDR(base) ((base) + 0x0214)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_2_ADDR(base) ((base) + 0x0218)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_3_ADDR(base) ((base) + 0x021C)
#define SOC_HI_SPI_V600_SPIVERSION_ADDR(base) ((base) + 0xFE0)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_ctrl_en : 1;
        unsigned int cs_cnt_ini : 31;
    } reg;
} SOC_HI_SPI_V600_SPI_CS_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_CS_CTRL_cs_ctrl_en_START (0)
#define SOC_HI_SPI_V600_SPI_CS_CTRL_cs_ctrl_en_END (0)
#define SOC_HI_SPI_V600_SPI_CS_CTRL_cs_cnt_ini_START (1)
#define SOC_HI_SPI_V600_SPI_CS_CTRL_cs_cnt_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ms_sel : 1;
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
        unsigned int mode_sel : 2;
    } reg;
} SOC_HI_SPI_V600_SPI_COMMON_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_ms_sel_START (0)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_ms_sel_END (0)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_loop_back_START (1)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_loop_back_END (1)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_clk_polarity_START (2)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_clk_polarity_END (2)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_clk_phase_START (3)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_clk_phase_END (3)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_div_ratio_pre_START (4)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_div_ratio_pre_END (11)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_div_ratio_post_START (12)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_div_ratio_post_END (19)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_frame_size_START (20)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_frame_size_END (24)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_hi_spd_START (25)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_hi_spd_END (25)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_dma_en_tx_START (26)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_dma_en_tx_END (26)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_dma_en_rx_START (27)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_dma_en_rx_END (27)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_timeout_limit_cnt_sel_START (28)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_timeout_limit_cnt_sel_END (29)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_mode_sel_START (30)
#define SOC_HI_SPI_V600_SPI_COMMON_CTRL_mode_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_en : 1;
        unsigned int rx_delay : 4;
        unsigned int phase0_cs_toggle : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int empty_data_out : 8;
        unsigned int rx_loop_delay : 4;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_HI_SPI_V600_SPI_EN_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_EN_spi_en_START (0)
#define SOC_HI_SPI_V600_SPI_EN_spi_en_END (0)
#define SOC_HI_SPI_V600_SPI_EN_rx_delay_START (1)
#define SOC_HI_SPI_V600_SPI_EN_rx_delay_END (4)
#define SOC_HI_SPI_V600_SPI_EN_phase0_cs_toggle_START (5)
#define SOC_HI_SPI_V600_SPI_EN_phase0_cs_toggle_END (5)
#define SOC_HI_SPI_V600_SPI_EN_empty_data_out_START (8)
#define SOC_HI_SPI_V600_SPI_EN_empty_data_out_END (15)
#define SOC_HI_SPI_V600_SPI_EN_rx_loop_delay_START (16)
#define SOC_HI_SPI_V600_SPI_EN_rx_loop_delay_END (19)
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
} SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_tx_START (0)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_tx_END (2)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_intr_lvl_tx_START (3)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_intr_lvl_tx_END (5)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_rx_START (6)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_dma_busrt_lvl_rx_END (8)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_intr_lvl_rx_START (9)
#define SOC_HI_SPI_V600_SPI_FIFO_LEVEL_CTRL_intr_lvl_rx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow_mask : 1;
        unsigned int intr_rx_timeout_mask : 1;
        unsigned int intr_rx_mask : 1;
        unsigned int intr_tx_mask : 1;
        unsigned int intr_tx_empty_mask : 1;
        unsigned int intr_burst_end_mask : 1;
        unsigned int intr_tx_overflow_mask : 1;
        unsigned int intr_rx_underflow_mask : 1;
        unsigned int intr_new_start_mask : 1;
        unsigned int intr_rx_not_empty_mask : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_MASK_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_overflow_mask_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_overflow_mask_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_timeout_mask_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_timeout_mask_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_mask_START (2)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_mask_END (2)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_tx_mask_START (3)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_tx_mask_END (3)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_tx_empty_mask_START (4)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_tx_empty_mask_END (4)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_burst_end_mask_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_burst_end_mask_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_tx_overflow_mask_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_tx_overflow_mask_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_underflow_mask_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_underflow_mask_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_new_start_mask_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_new_start_mask_END (8)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_not_empty_mask_START (9)
#define SOC_HI_SPI_V600_INTR_SPI_MASK_intr_rx_not_empty_mask_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int din : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DIN_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DIN_din_START (0)
#define SOC_HI_SPI_V600_SPI_DIN_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dout : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DOUT_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DOUT_dout_START (0)
#define SOC_HI_SPI_V600_SPI_DOUT_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fifo_empty : 1;
        unsigned int tx_fifo_not_full : 1;
        unsigned int rx_fifo_not_empty : 1;
        unsigned int rx_fifo_full : 1;
        unsigned int busy : 1;
        unsigned int rx_fifo_lvl : 9;
        unsigned int tx_fifo_lvl : 9;
        unsigned int spi_afifo_not_rempty : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_HI_SPI_V600_SPI_STATE_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_STATE_tx_fifo_empty_START (0)
#define SOC_HI_SPI_V600_SPI_STATE_tx_fifo_empty_END (0)
#define SOC_HI_SPI_V600_SPI_STATE_tx_fifo_not_full_START (1)
#define SOC_HI_SPI_V600_SPI_STATE_tx_fifo_not_full_END (1)
#define SOC_HI_SPI_V600_SPI_STATE_rx_fifo_not_empty_START (2)
#define SOC_HI_SPI_V600_SPI_STATE_rx_fifo_not_empty_END (2)
#define SOC_HI_SPI_V600_SPI_STATE_rx_fifo_full_START (3)
#define SOC_HI_SPI_V600_SPI_STATE_rx_fifo_full_END (3)
#define SOC_HI_SPI_V600_SPI_STATE_busy_START (4)
#define SOC_HI_SPI_V600_SPI_STATE_busy_END (4)
#define SOC_HI_SPI_V600_SPI_STATE_rx_fifo_lvl_START (5)
#define SOC_HI_SPI_V600_SPI_STATE_rx_fifo_lvl_END (13)
#define SOC_HI_SPI_V600_SPI_STATE_tx_fifo_lvl_START (14)
#define SOC_HI_SPI_V600_SPI_STATE_tx_fifo_lvl_END (22)
#define SOC_HI_SPI_V600_SPI_STATE_spi_afifo_not_rempty_START (23)
#define SOC_HI_SPI_V600_SPI_STATE_spi_afifo_not_rempty_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow_raw : 1;
        unsigned int intr_rx_timeout_raw : 1;
        unsigned int intr_rx_raw : 1;
        unsigned int intr_tx_raw : 1;
        unsigned int intr_tx_empty_raw : 1;
        unsigned int intr_burst_end_raw : 1;
        unsigned int intr_tx_overflow_raw : 1;
        unsigned int intr_rx_underflow_raw : 1;
        unsigned int intr_new_start_raw : 1;
        unsigned int intr_rx_not_empty_raw : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_RAW_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_overflow_raw_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_overflow_raw_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_timeout_raw_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_timeout_raw_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_raw_START (2)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_raw_END (2)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_tx_raw_START (3)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_tx_raw_END (3)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_tx_empty_raw_START (4)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_tx_empty_raw_END (4)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_burst_end_raw_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_burst_end_raw_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_tx_overflow_raw_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_tx_overflow_raw_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_underflow_raw_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_underflow_raw_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_new_start_raw_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_new_start_raw_END (8)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_not_empty_raw_START (9)
#define SOC_HI_SPI_V600_INTR_SPI_RAW_intr_rx_not_empty_raw_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow : 1;
        unsigned int intr_rx_timeout : 1;
        unsigned int intr_rx : 1;
        unsigned int intr_tx : 1;
        unsigned int intr_tx_empty : 1;
        unsigned int intr_burst_end : 1;
        unsigned int intr_tx_overflow : 1;
        unsigned int intr_rx_underflow : 1;
        unsigned int intr_new_start : 1;
        unsigned int intr_rx_not_empty : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_overflow_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_overflow_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_timeout_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_timeout_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_START (2)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_END (2)
#define SOC_HI_SPI_V600_INTR_SPI_intr_tx_START (3)
#define SOC_HI_SPI_V600_INTR_SPI_intr_tx_END (3)
#define SOC_HI_SPI_V600_INTR_SPI_intr_tx_empty_START (4)
#define SOC_HI_SPI_V600_INTR_SPI_intr_tx_empty_END (4)
#define SOC_HI_SPI_V600_INTR_SPI_intr_burst_end_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_intr_burst_end_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_intr_tx_overflow_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_intr_tx_overflow_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_underflow_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_underflow_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_intr_new_start_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_intr_new_start_END (8)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_not_empty_START (9)
#define SOC_HI_SPI_V600_INTR_SPI_intr_rx_not_empty_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rx_overflow_clr : 1;
        unsigned int intr_rx_timeout_clr : 1;
        unsigned int reserved_0 : 3;
        unsigned int intr_burst_end_clr : 1;
        unsigned int intr_tx_overflow_clr : 1;
        unsigned int intr_rx_underflow_clr : 1;
        unsigned int intr_new_start_clr : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_CLR_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_rx_overflow_clr_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_rx_overflow_clr_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_rx_timeout_clr_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_rx_timeout_clr_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_burst_end_clr_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_burst_end_clr_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_tx_overflow_clr_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_tx_overflow_clr_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_rx_underflow_clr_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_rx_underflow_clr_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_new_start_clr_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_CLR_intr_new_start_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int receive_frame_num : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_FLASH_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_FLASH_CTRL_receive_frame_num_START (0)
#define SOC_HI_SPI_V600_SPI_FLASH_CTRL_receive_frame_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int frf : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_SPI_V600_FRAME_FORMAT_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_FRAME_FORMAT_CTRL_frf_START (0)
#define SOC_HI_SPI_V600_FRAME_FORMAT_CTRL_frf_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mw_mode : 1;
        unsigned int mw_cfs : 5;
        unsigned int mw_dummy_cyc : 4;
        unsigned int mw_sample_phase : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_HI_SPI_V600_NMW_COMMON_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_mode_START (0)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_mode_END (0)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_cfs_START (1)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_cfs_END (5)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_dummy_cyc_START (6)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_dummy_cyc_END (9)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_sample_phase_START (10)
#define SOC_HI_SPI_V600_NMW_COMMON_CTRL_mw_sample_phase_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpm_flow_en : 1;
        unsigned int tpm_read : 1;
        unsigned int tpm_cmd_size : 3;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_SPI_V600_TPM_FLOW_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_tpm_flow_en_START (0)
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_tpm_flow_en_END (0)
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_tpm_read_START (1)
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_tpm_read_END (1)
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_tpm_cmd_size_START (2)
#define SOC_HI_SPI_V600_TPM_FLOW_CTRL_tpm_cmd_size_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpm_debug_status : 32;
    } reg;
} SOC_HI_SPI_V600_TPM_FLOW_STATE_UNION;
#endif
#define SOC_HI_SPI_V600_TPM_FLOW_STATE_tpm_debug_status_START (0)
#define SOC_HI_SPI_V600_TPM_FLOW_STATE_tpm_debug_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_blk_size : 20;
        unsigned int dma_mode_sel : 1;
        unsigned int dma_enable_apb : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_CTRL_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_dma_blk_size_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_dma_blk_size_END (19)
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_dma_mode_sel_START (20)
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_dma_mode_sel_END (20)
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_dma_enable_apb_START (21)
#define SOC_HI_SPI_V600_SPI_DMA_CTRL_dma_enable_apb_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdma_addr_arg_h_r : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_R_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_R_sdma_addr_arg_h_r_START (0)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_R_sdma_addr_arg_h_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdma_addr_arg_l_r : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_R_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_R_sdma_addr_arg_l_r_START (0)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_R_sdma_addr_arg_l_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdma_addr_arg_h_w : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_W_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_W_sdma_addr_arg_h_w_START (0)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_H_W_sdma_addr_arg_h_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdma_addr_arg_l_w : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_W_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_W_sdma_addr_arg_l_w_START (0)
#define SOC_HI_SPI_V600_SPI_SDMA_ADDR_L_W_sdma_addr_arg_l_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_system_addr_h_r : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_R_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_R_adma_system_addr_h_r_START (0)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_R_adma_system_addr_h_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_system_addr_l_r : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_R_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_R_adma_system_addr_l_r_START (0)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_R_adma_system_addr_l_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_system_addr_h_w : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_W_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_W_adma_system_addr_h_w_START (0)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_H_W_adma_system_addr_h_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_system_addr_l_w : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_W_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_W_adma_system_addr_l_w_START (0)
#define SOC_HI_SPI_V600_SPI_ADMA_ADDR_L_W_adma_system_addr_l_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_cmd_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_CMD_START_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_CMD_START_dma_cmd_start_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_CMD_START_dma_cmd_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dma_tx_overflow_mask : 1;
        unsigned int int_dma_rx_underflow_mask : 1;
        unsigned int int_dma_rx_overflow_mask : 1;
        unsigned int int_dma_wr_bresp_mask : 1;
        unsigned int int_dma_wr_rresp_mask : 1;
        unsigned int int_dma_rd_rresp_mask : 1;
        unsigned int int_dma_wr_descr_addr_mask : 1;
        unsigned int int_adma_wr_descr_invld_mask : 1;
        unsigned int int_adma_wr_len_mismatch_mask : 1;
        unsigned int int_dma_rd_descr_addr_mask : 1;
        unsigned int int_adma_rd_descr_invld_mask : 1;
        unsigned int int_adma_rd_len_mismatch_mask : 1;
        unsigned int int_dma_complete_mask : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_tx_overflow_mask_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_tx_overflow_mask_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rx_underflow_mask_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rx_underflow_mask_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rx_overflow_mask_START (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rx_overflow_mask_END (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_wr_bresp_mask_START (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_wr_bresp_mask_END (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_wr_rresp_mask_START (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_wr_rresp_mask_END (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rd_rresp_mask_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rd_rresp_mask_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_wr_descr_addr_mask_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_wr_descr_addr_mask_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_wr_descr_invld_mask_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_wr_descr_invld_mask_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_wr_len_mismatch_mask_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_wr_len_mismatch_mask_END (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rd_descr_addr_mask_START (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_rd_descr_addr_mask_END (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_rd_descr_invld_mask_START (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_rd_descr_invld_mask_END (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_rd_len_mismatch_mask_START (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_adma_rd_len_mismatch_mask_END (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_complete_mask_START (12)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_MASK_int_dma_complete_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dma_tx_overflow_clr : 1;
        unsigned int int_dma_rx_underflow_clr : 1;
        unsigned int int_dma_rx_overflow_clr : 1;
        unsigned int int_dma_wr_bresp_clr : 1;
        unsigned int int_dma_wr_rresp_clr : 1;
        unsigned int int_dma_rd_rresp_clr : 1;
        unsigned int int_dma_wr_descr_addr_clr : 1;
        unsigned int int_adma_wr_descr_invld_clr : 1;
        unsigned int int_adma_wr_len_mismatch_clr : 1;
        unsigned int int_dma_rd_descr_addr_clr : 1;
        unsigned int int_adma_rd_descr_invld_clr : 1;
        unsigned int int_adma_rd_len_mismatch_clr : 1;
        unsigned int int_dma_complete_clr : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_tx_overflow_clr_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_tx_overflow_clr_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rx_underflow_clr_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rx_underflow_clr_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rx_overflow_clr_START (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rx_overflow_clr_END (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_wr_bresp_clr_START (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_wr_bresp_clr_END (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_wr_rresp_clr_START (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_wr_rresp_clr_END (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rd_rresp_clr_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rd_rresp_clr_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_wr_descr_addr_clr_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_wr_descr_addr_clr_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_wr_descr_invld_clr_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_wr_descr_invld_clr_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_wr_len_mismatch_clr_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_wr_len_mismatch_clr_END (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rd_descr_addr_clr_START (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_rd_descr_addr_clr_END (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_rd_descr_invld_clr_START (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_rd_descr_invld_clr_END (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_rd_len_mismatch_clr_START (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_adma_rd_len_mismatch_clr_END (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_complete_clr_START (12)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_CLR_int_dma_complete_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dma_tx_overflow_raw : 1;
        unsigned int int_dma_rx_underflow_raw : 1;
        unsigned int int_dma_rx_overflow_raw : 1;
        unsigned int int_dma_wr_bresp_raw : 1;
        unsigned int int_dma_wr_rresp_raw : 1;
        unsigned int int_dma_rd_rresp_raw : 1;
        unsigned int int_adma_wr_descr_invld_raw : 1;
        unsigned int int_dma_wr_descr_addr_raw : 1;
        unsigned int int_adma_wr_len_mismatch_raw : 1;
        unsigned int int_dma_rd_descr_addr_raw : 1;
        unsigned int int_adma_rd_descr_invld_raw : 1;
        unsigned int int_adma_rd_len_mismatch_raw : 1;
        unsigned int int_dma_complete_raw : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_tx_overflow_raw_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_tx_overflow_raw_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rx_underflow_raw_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rx_underflow_raw_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rx_overflow_raw_START (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rx_overflow_raw_END (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_wr_bresp_raw_START (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_wr_bresp_raw_END (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_wr_rresp_raw_START (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_wr_rresp_raw_END (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rd_rresp_raw_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rd_rresp_raw_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_wr_descr_invld_raw_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_wr_descr_invld_raw_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_wr_descr_addr_raw_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_wr_descr_addr_raw_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_wr_len_mismatch_raw_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_wr_len_mismatch_raw_END (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rd_descr_addr_raw_START (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_rd_descr_addr_raw_END (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_rd_descr_invld_raw_START (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_rd_descr_invld_raw_END (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_rd_len_mismatch_raw_START (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_adma_rd_len_mismatch_raw_END (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_complete_raw_START (12)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_RAW_int_dma_complete_raw_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dma_tx_overflow : 1;
        unsigned int int_dma_rx_underflow : 1;
        unsigned int int_dma_rx_overflow : 1;
        unsigned int int_dma_wr_bresp : 1;
        unsigned int int_dma_wr_rresp : 1;
        unsigned int int_dma_rd_rresp : 1;
        unsigned int int_dma_wr_descr_addr : 1;
        unsigned int int_adma_wr_descr_invld : 1;
        unsigned int int_adma_wr_len_mismatch : 1;
        unsigned int int_dma_rd_descr_addr : 1;
        unsigned int int_adma_rd_descr_invld : 1;
        unsigned int int_adma_rd_len_mismatch : 1;
        unsigned int int_dma_complete : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_SPI_V600_INTR_SPI_DMA_UNION;
#endif
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_tx_overflow_START (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_tx_overflow_END (0)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rx_underflow_START (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rx_underflow_END (1)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rx_overflow_START (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rx_overflow_END (2)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_wr_bresp_START (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_wr_bresp_END (3)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_wr_rresp_START (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_wr_rresp_END (4)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rd_rresp_START (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rd_rresp_END (5)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_wr_descr_addr_START (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_wr_descr_addr_END (6)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_wr_descr_invld_START (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_wr_descr_invld_END (7)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_wr_len_mismatch_START (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_wr_len_mismatch_END (8)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rd_descr_addr_START (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_rd_descr_addr_END (9)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_rd_descr_invld_START (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_rd_descr_invld_END (10)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_rd_len_mismatch_START (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_adma_rd_len_mismatch_END (11)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_complete_START (12)
#define SOC_HI_SPI_V600_INTR_SPI_DMA_int_dma_complete_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_sel : 4;
        unsigned int dma_rd_dfx_sel : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_DFX_SEL_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_DFX_SEL_dma_wr_dfx_sel_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_DFX_SEL_dma_wr_dfx_sel_END (3)
#define SOC_HI_SPI_V600_SPI_DMA_DFX_SEL_dma_rd_dfx_sel_START (4)
#define SOC_HI_SPI_V600_SPI_DMA_DFX_SEL_dma_rd_dfx_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_0 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_0_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_0_dma_rd_dfx_0_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_0_dma_rd_dfx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_1 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_1_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_1_dma_rd_dfx_1_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_1_dma_rd_dfx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_2 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_2_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_2_dma_rd_dfx_2_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_2_dma_rd_dfx_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_3 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_3_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_3_dma_rd_dfx_3_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_3_dma_rd_dfx_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_4 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_4_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_4_dma_rd_dfx_4_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_4_dma_rd_dfx_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_5 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_5_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_5_dma_rd_dfx_5_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_5_dma_rd_dfx_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_6 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_6_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_6_dma_rd_dfx_6_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_6_dma_rd_dfx_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_7 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_7_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_7_dma_rd_dfx_7_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_7_dma_rd_dfx_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_8 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_8_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_8_dma_rd_dfx_8_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_8_dma_rd_dfx_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_9 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_9_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_9_dma_rd_dfx_9_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_9_dma_rd_dfx_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_10 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_10_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_10_dma_rd_dfx_10_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_10_dma_rd_dfx_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_11 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_11_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_11_dma_rd_dfx_11_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_11_dma_rd_dfx_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_12 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_12_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_12_dma_rd_dfx_12_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_12_dma_rd_dfx_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_13 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_13_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_13_dma_rd_dfx_13_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_13_dma_rd_dfx_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_14 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_14_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_14_dma_rd_dfx_14_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_14_dma_rd_dfx_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_15 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_15_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_15_dma_rd_dfx_15_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_15_dma_rd_dfx_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_16 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_16_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_16_dma_rd_dfx_16_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_16_dma_rd_dfx_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_17 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_17_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_17_dma_rd_dfx_17_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_17_dma_rd_dfx_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_dfx_18 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_RD_DFX_18_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_18_dma_rd_dfx_18_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_RD_DFX_18_dma_rd_dfx_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_0 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_0_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_0_dma_wr_dfx_0_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_0_dma_wr_dfx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_1 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_1_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_1_dma_wr_dfx_1_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_1_dma_wr_dfx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_2 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_2_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_2_dma_wr_dfx_2_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_2_dma_wr_dfx_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_3 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_3_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_3_dma_wr_dfx_3_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_3_dma_wr_dfx_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_4 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_4_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_4_dma_wr_dfx_4_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_4_dma_wr_dfx_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_5 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_5_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_5_dma_wr_dfx_5_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_5_dma_wr_dfx_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_6 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_6_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_6_dma_wr_dfx_6_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_6_dma_wr_dfx_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_7 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_7_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_7_dma_wr_dfx_7_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_7_dma_wr_dfx_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_8 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_8_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_8_dma_wr_dfx_8_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_8_dma_wr_dfx_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_9 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_9_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_9_dma_wr_dfx_9_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_9_dma_wr_dfx_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_10 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_10_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_10_dma_wr_dfx_10_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_10_dma_wr_dfx_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_11 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_11_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_11_dma_wr_dfx_11_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_11_dma_wr_dfx_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_12 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_12_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_12_dma_wr_dfx_12_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_12_dma_wr_dfx_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_13 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_13_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_13_dma_wr_dfx_13_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_13_dma_wr_dfx_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_14 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_14_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_14_dma_wr_dfx_14_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_14_dma_wr_dfx_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_15 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_15_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_15_dma_wr_dfx_15_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_15_dma_wr_dfx_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_16 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_16_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_16_dma_wr_dfx_16_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_16_dma_wr_dfx_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_17 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_17_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_17_dma_wr_dfx_17_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_17_dma_wr_dfx_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_dfx_18 : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_WR_DFX_18_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_18_dma_wr_dfx_18_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_WR_DFX_18_dma_wr_dfx_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rx_fifo_trans : 1;
        unsigned int dma_tx_fifo_trans : 1;
        unsigned int dma_axi_rd_trans : 1;
        unsigned int dma_axi_wr_trans : 1;
        unsigned int dma_soft_rst_done : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_rx_fifo_trans_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_rx_fifo_trans_END (0)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_tx_fifo_trans_START (1)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_tx_fifo_trans_END (1)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_axi_rd_trans_START (2)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_axi_rd_trans_END (2)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_axi_wr_trans_START (3)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_axi_wr_trans_END (3)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_soft_rst_done_START (4)
#define SOC_HI_SPI_V600_SPI_DMA_TRANS_STAT_dma_soft_rst_done_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_rd_descr_invld : 1;
        unsigned int adma_wr_descr_invld : 1;
        unsigned int adma_rd_len_mismach : 1;
        unsigned int adma_wr_len_mismach : 1;
        unsigned int dma_rd_addr_err_state : 4;
        unsigned int dma_wr_addr_err_state : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_rd_descr_invld_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_rd_descr_invld_END (0)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_wr_descr_invld_START (1)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_wr_descr_invld_END (1)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_rd_len_mismach_START (2)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_rd_len_mismach_END (2)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_wr_len_mismach_START (3)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_adma_wr_len_mismach_END (3)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_dma_rd_addr_err_state_START (4)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_dma_rd_addr_err_state_END (7)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_dma_wr_addr_err_state_START (8)
#define SOC_HI_SPI_V600_SPI_DMA_ERR_STAT_dma_wr_addr_err_state_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_rd_trans_addr_info_h : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO0_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO0_adma_rd_trans_addr_info_h_START (0)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO0_adma_rd_trans_addr_info_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_rd_trans_addr_info_l : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO1_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO1_adma_rd_trans_addr_info_l_START (0)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO1_adma_rd_trans_addr_info_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_rd_link_addr_info_h : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO2_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO2_adma_rd_link_addr_info_h_START (0)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO2_adma_rd_link_addr_info_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_rd_link_addr_info_l : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO3_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO3_adma_rd_link_addr_info_l_START (0)
#define SOC_HI_SPI_V600_SPI_RD_DMA_ERR_ADDR_INFO3_adma_rd_link_addr_info_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_wr_trans_addr_info_h : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO0_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO0_adma_wr_trans_addr_info_h_START (0)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO0_adma_wr_trans_addr_info_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_wr_trans_addr_info_l : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO1_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO1_adma_wr_trans_addr_info_l_START (0)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO1_adma_wr_trans_addr_info_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_wr_link_addr_info_h : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO2_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO2_adma_wr_link_addr_info_h_START (0)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO2_adma_wr_link_addr_info_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_wr_link_addr_info_l : 32;
    } reg;
} SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO3_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO3_adma_wr_link_addr_info_l_START (0)
#define SOC_HI_SPI_V600_SPI_WR_DMA_ERR_ADDR_INFO3_adma_wr_link_addr_info_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_soft_rst_set : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_SPI_V600_SPI_DMA_SOFT_RST_UNION;
#endif
#define SOC_HI_SPI_V600_SPI_DMA_SOFT_RST_dma_soft_rst_set_START (0)
#define SOC_HI_SPI_V600_SPI_DMA_SOFT_RST_dma_soft_rst_set_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_ctrl0 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RW_RESERVED_0_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_0_dma_reserved_ctrl0_START (0)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_0_dma_reserved_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_ctrl1 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RW_RESERVED_1_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_1_dma_reserved_ctrl1_START (0)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_1_dma_reserved_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_ctrl2 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RW_RESERVED_2_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_2_dma_reserved_ctrl2_START (0)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_2_dma_reserved_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_ctrl3 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RW_RESERVED_3_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_3_dma_reserved_ctrl3_START (0)
#define SOC_HI_SPI_V600_DMA_RW_RESERVED_3_dma_reserved_ctrl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_status0 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RO_RESERVED_0_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_0_dma_reserved_status0_START (0)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_0_dma_reserved_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_status1 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RO_RESERVED_1_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_1_dma_reserved_status1_START (0)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_1_dma_reserved_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_status2 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RO_RESERVED_2_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_2_dma_reserved_status2_START (0)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_2_dma_reserved_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_reserved_status3 : 32;
    } reg;
} SOC_HI_SPI_V600_DMA_RO_RESERVED_3_UNION;
#endif
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_3_dma_reserved_status3_START (0)
#define SOC_HI_SPI_V600_DMA_RO_RESERVED_3_dma_reserved_status3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi_version : 32;
    } reg;
} SOC_HI_SPI_V600_SPIVERSION_UNION;
#endif
#define SOC_HI_SPI_V600_SPIVERSION_spi_version_START (0)
#define SOC_HI_SPI_V600_SPIVERSION_spi_version_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
