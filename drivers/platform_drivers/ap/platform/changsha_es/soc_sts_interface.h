#ifndef __SOC_STS_INTERFACE_H__
#define __SOC_STS_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_STS_STA_CFG0_ADDR(base) (base)
#define SOC_STS_TRANS_CFG0_ADDR(base) ((base) + 0x0004UL)
#define SOC_STS_CLK_CFG_ADDR(base) ((base) + 0x0008UL)
#define SOC_STS_I2S_CFG_ADDR(base) ((base) + 0x000CUL)
#define SOC_STS_SPI_CFG0_ADDR(base) ((base) + 0x0010UL)
#define SOC_STS_SPI_CFG1_ADDR(base) ((base) + 0x0014UL)
#define SOC_STS_RFFE_CFG0_ADDR(base) ((base) + 0x0018UL)
#define SOC_STS_RFFE_CFG1_ADDR(base) ((base) + 0x001CUL)
#define SOC_STS_RFFE_CFG2_ADDR(base) ((base) + 0x0020UL)
#define SOC_STS_SPI_CFG2_ADDR(base) ((base) + 0x0024UL)
#define SOC_STS_USIM_CFG_ADDR(base) ((base) + 0x003CUL)
#define SOC_STS_GPIO_CFG_ADDR(base) ((base) + 0x0040UL)
#define SOC_STS_GPIO_OEN_A2B_CFG0_ADDR(base) ((base) + 0x0044UL)
#define SOC_STS_GPIO_OEN_A2B_CFG1_ADDR(base) ((base) + 0x0048UL)
#define SOC_STS_GPIO_OEN_B2A_CFG0_ADDR(base) ((base) + 0x004CUL)
#define SOC_STS_GPIO_OEN_B2A_CFG1_ADDR(base) ((base) + 0x0050UL)
#define SOC_STS_INTR_STATUS_ADDR(base) ((base) + 0x0054UL)
#define SOC_STS_INTR_STATUS_ENABLE_ADDR(base) ((base) + 0x0058UL)
#define SOC_STS_INTR_OUTPUT_ENABLE_ADDR(base) ((base) + 0x005CUL)
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_0_ADDR(base) ((base) + 0x0060UL)
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_1_ADDR(base) ((base) + 0x0064UL)
#define SOC_STS_INTR_STS_STA_B2A_P_ERR_INFO_ADDR(base) ((base) + 0x0068UL)
#define SOC_STS_INTR_RFFE_CMD_DATA_P_ERR_INFO_ADDR(base) ((base) + 0x006CUL)
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_0_ADDR(base) ((base) + 0x0070UL)
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_1_ADDR(base) ((base) + 0x0074UL)
#define SOC_STS_INTR_STS_STA_A2B_P_ERR_INFO_ADDR(base) ((base) + 0x0078UL)
#define SOC_STS_INTR_RFFE_READ_P_ERR_INFO_ADDR(base) ((base) + 0x007CUL)
#define SOC_STS_TRANS_PRIORITY_INDEX_ADDR(base) ((base) + 0x0080UL)
#define SOC_STS_I2S_CFG2_ADDR(base) ((base) + 0x0084UL)
#define SOC_STS_USIM0_OEN_DLY_ADDR(base) ((base) + 0x0088UL)
#define SOC_STS_I2C_CFG_ADDR(base) ((base) + 0x0090UL)
#define SOC_STS_I2C0_CFG_ADDR(base) ((base) + 0x0094UL)
#define SOC_STS_I2C1_CFG_ADDR(base) ((base) + 0x0098UL)
#define SOC_STS_I2C2_CFG_ADDR(base) ((base) + 0x009cUL)
#define SOC_STS_I2C3_CFG_ADDR(base) ((base) + 0x00a0UL)
#define SOC_STS_I2C4_CFG_ADDR(base) ((base) + 0x00a4UL)
#define SOC_STS_I2C0_DBC_CFG_ADDR(base) ((base) + 0x00a8UL)
#define SOC_STS_I2C1_DBC_CFG_ADDR(base) ((base) + 0x00acUL)
#define SOC_STS_I2C2_DBC_CFG_ADDR(base) ((base) + 0x00b0UL)
#define SOC_STS_I2C3_DBC_CFG_ADDR(base) ((base) + 0x00b4UL)
#define SOC_STS_I2C4_DBC_CFG_ADDR(base) ((base) + 0x00b8UL)
#define SOC_STS_I2C_B2A_HOLD_CFG0_ADDR(base) ((base) + 0x00bCUL)
#define SOC_STS_I2C_B2A_HOLD_CFG1_ADDR(base) ((base) + 0x00C0UL)
#define SOC_STS_I2C_B2A_HOLD_CFG2_ADDR(base) ((base) + 0x00C4UL)
#define SOC_STS_I2C_DLYCFG0_ADDR(base) ((base) + 0x00C8UL)
#define SOC_STS_I2C_DLYCFG1_ADDR(base) ((base) + 0x00CcUL)
#define SOC_STS_CLK_GATE_STAT_ADDR(base) ((base) + 0x00D0UL)
#define SOC_STS_SOFTWARE_RESET_ADDR(base) ((base) + 0xF0UL)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_ADDR(base) ((base) + 0xF4UL)
#define SOC_STS_ASIDE_IDLE_ADDR(base) ((base) + 0xF8UL)
#define SOC_STS_BSIDE_IDLE_ADDR(base) ((base) + 0xFCUL)
#define SOC_STS_TP_SEL_ADDR(base) ((base) + 0x100UL)
#define SOC_STS_RSV_CTRL0_ADDR(base) ((base) + 0x200UL)
#define SOC_STS_RSV_CTRL1_ADDR(base) ((base) + 0x204UL)
#define SOC_STS_RSV_CTRL2_ADDR(base) ((base) + 0x208UL)
#define SOC_STS_RSV_CTRL3_ADDR(base) ((base) + 0x20cUL)
#define SOC_STS_RSV_STAT0_ADDR(base) ((base) + 0x210UL)
#define SOC_STS_RSV_STAT1_ADDR(base) ((base) + 0x214UL)
#define SOC_STS_RSV_STAT2_ADDR(base) ((base) + 0x218UL)
#define SOC_STS_RSV_STAT3_ADDR(base) ((base) + 0x21CUL)
#define SOC_STS_DFX_SPI0_A_ADDR(base) ((base) + 0x800UL)
#define SOC_STS_DFX_SPI1_A_ADDR(base) ((base) + 0x804UL)
#define SOC_STS_DFX_SPI0_B_ADDR(base) ((base) + 0x808UL)
#define SOC_STS_DFX_SPI1_B_ADDR(base) ((base) + 0x80CUL)
#define SOC_STS_DFX_RFFE_A_ADDR(base) ((base) + 0x810UL)
#define SOC_STS_DFX_RFFE_B_ADDR(base) ((base) + 0x814UL)
#define SOC_STS_DFX_I2SA_ADDR(base) ((base) + 0x818UL)
#define SOC_STS_DFX_I2SB_ADDR(base) ((base) + 0x81cUL)
#define SOC_STS_DFX_I2C0_ADDR(base) ((base) + 0x820UL)
#define SOC_STS_DFX_I2C1_ADDR(base) ((base) + 0x824UL)
#define SOC_STS_DFX_I2C2_ADDR(base) ((base) + 0x828UL)
#define SOC_STS_DFX_I2C3_ADDR(base) ((base) + 0x82cUL)
#define SOC_STS_DFX_I2C4_ADDR(base) ((base) + 0x830UL)
#define SOC_STS_DFX_STS_TRANS_GEN_A2B_ADDR(base) ((base) + 0x834UL)
#define SOC_STS_DFX_STS_TRANS_GEN_B2A_ADDR(base) ((base) + 0x838UL)
#define SOC_STS_DFX_STS_TRANS_DEC_A2B_ADDR(base) ((base) + 0x83CUL)
#define SOC_STS_DFX_STS_TRANS_DEC_B2A_ADDR(base) ((base) + 0x840UL)
#define SOC_STS_DFX_STS_STA_GEN_A2B_ADDR(base) ((base) + 0x844UL)
#define SOC_STS_DFX_STS_STA_GEN_B2A_ADDR(base) ((base) + 0x848UL)
#define SOC_STS_DFX_STS_STA_DEC_A2B_ADDR(base) ((base) + 0x84CUL)
#define SOC_STS_DFX_STS_STA_DEC_B2A_ADDR(base) ((base) + 0x850UL)
#define SOC_STS_DFX_USIM_CLK_ADDR(base) ((base) + 0x854UL)
#else
#define SOC_STS_STA_CFG0_ADDR(base) (base)
#define SOC_STS_TRANS_CFG0_ADDR(base) ((base) + 0x0004)
#define SOC_STS_CLK_CFG_ADDR(base) ((base) + 0x0008)
#define SOC_STS_I2S_CFG_ADDR(base) ((base) + 0x000C)
#define SOC_STS_SPI_CFG0_ADDR(base) ((base) + 0x0010)
#define SOC_STS_SPI_CFG1_ADDR(base) ((base) + 0x0014)
#define SOC_STS_RFFE_CFG0_ADDR(base) ((base) + 0x0018)
#define SOC_STS_RFFE_CFG1_ADDR(base) ((base) + 0x001C)
#define SOC_STS_RFFE_CFG2_ADDR(base) ((base) + 0x0020)
#define SOC_STS_SPI_CFG2_ADDR(base) ((base) + 0x0024)
#define SOC_STS_USIM_CFG_ADDR(base) ((base) + 0x003C)
#define SOC_STS_GPIO_CFG_ADDR(base) ((base) + 0x0040)
#define SOC_STS_GPIO_OEN_A2B_CFG0_ADDR(base) ((base) + 0x0044)
#define SOC_STS_GPIO_OEN_A2B_CFG1_ADDR(base) ((base) + 0x0048)
#define SOC_STS_GPIO_OEN_B2A_CFG0_ADDR(base) ((base) + 0x004C)
#define SOC_STS_GPIO_OEN_B2A_CFG1_ADDR(base) ((base) + 0x0050)
#define SOC_STS_INTR_STATUS_ADDR(base) ((base) + 0x0054)
#define SOC_STS_INTR_STATUS_ENABLE_ADDR(base) ((base) + 0x0058)
#define SOC_STS_INTR_OUTPUT_ENABLE_ADDR(base) ((base) + 0x005C)
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_0_ADDR(base) ((base) + 0x0060)
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_1_ADDR(base) ((base) + 0x0064)
#define SOC_STS_INTR_STS_STA_B2A_P_ERR_INFO_ADDR(base) ((base) + 0x0068)
#define SOC_STS_INTR_RFFE_CMD_DATA_P_ERR_INFO_ADDR(base) ((base) + 0x006C)
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_0_ADDR(base) ((base) + 0x0070)
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_1_ADDR(base) ((base) + 0x0074)
#define SOC_STS_INTR_STS_STA_A2B_P_ERR_INFO_ADDR(base) ((base) + 0x0078)
#define SOC_STS_INTR_RFFE_READ_P_ERR_INFO_ADDR(base) ((base) + 0x007C)
#define SOC_STS_TRANS_PRIORITY_INDEX_ADDR(base) ((base) + 0x0080)
#define SOC_STS_I2S_CFG2_ADDR(base) ((base) + 0x0084)
#define SOC_STS_USIM0_OEN_DLY_ADDR(base) ((base) + 0x0088)
#define SOC_STS_I2C_CFG_ADDR(base) ((base) + 0x0090)
#define SOC_STS_I2C0_CFG_ADDR(base) ((base) + 0x0094)
#define SOC_STS_I2C1_CFG_ADDR(base) ((base) + 0x0098)
#define SOC_STS_I2C2_CFG_ADDR(base) ((base) + 0x009c)
#define SOC_STS_I2C3_CFG_ADDR(base) ((base) + 0x00a0)
#define SOC_STS_I2C4_CFG_ADDR(base) ((base) + 0x00a4)
#define SOC_STS_I2C0_DBC_CFG_ADDR(base) ((base) + 0x00a8)
#define SOC_STS_I2C1_DBC_CFG_ADDR(base) ((base) + 0x00ac)
#define SOC_STS_I2C2_DBC_CFG_ADDR(base) ((base) + 0x00b0)
#define SOC_STS_I2C3_DBC_CFG_ADDR(base) ((base) + 0x00b4)
#define SOC_STS_I2C4_DBC_CFG_ADDR(base) ((base) + 0x00b8)
#define SOC_STS_I2C_B2A_HOLD_CFG0_ADDR(base) ((base) + 0x00bC)
#define SOC_STS_I2C_B2A_HOLD_CFG1_ADDR(base) ((base) + 0x00C0)
#define SOC_STS_I2C_B2A_HOLD_CFG2_ADDR(base) ((base) + 0x00C4)
#define SOC_STS_I2C_DLYCFG0_ADDR(base) ((base) + 0x00C8)
#define SOC_STS_I2C_DLYCFG1_ADDR(base) ((base) + 0x00Cc)
#define SOC_STS_CLK_GATE_STAT_ADDR(base) ((base) + 0x00D0)
#define SOC_STS_SOFTWARE_RESET_ADDR(base) ((base) + 0xF0)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_ADDR(base) ((base) + 0xF4)
#define SOC_STS_ASIDE_IDLE_ADDR(base) ((base) + 0xF8)
#define SOC_STS_BSIDE_IDLE_ADDR(base) ((base) + 0xFC)
#define SOC_STS_TP_SEL_ADDR(base) ((base) + 0x100)
#define SOC_STS_RSV_CTRL0_ADDR(base) ((base) + 0x200)
#define SOC_STS_RSV_CTRL1_ADDR(base) ((base) + 0x204)
#define SOC_STS_RSV_CTRL2_ADDR(base) ((base) + 0x208)
#define SOC_STS_RSV_CTRL3_ADDR(base) ((base) + 0x20c)
#define SOC_STS_RSV_STAT0_ADDR(base) ((base) + 0x210)
#define SOC_STS_RSV_STAT1_ADDR(base) ((base) + 0x214)
#define SOC_STS_RSV_STAT2_ADDR(base) ((base) + 0x218)
#define SOC_STS_RSV_STAT3_ADDR(base) ((base) + 0x21C)
#define SOC_STS_DFX_SPI0_A_ADDR(base) ((base) + 0x800)
#define SOC_STS_DFX_SPI1_A_ADDR(base) ((base) + 0x804)
#define SOC_STS_DFX_SPI0_B_ADDR(base) ((base) + 0x808)
#define SOC_STS_DFX_SPI1_B_ADDR(base) ((base) + 0x80C)
#define SOC_STS_DFX_RFFE_A_ADDR(base) ((base) + 0x810)
#define SOC_STS_DFX_RFFE_B_ADDR(base) ((base) + 0x814)
#define SOC_STS_DFX_I2SA_ADDR(base) ((base) + 0x818)
#define SOC_STS_DFX_I2SB_ADDR(base) ((base) + 0x81c)
#define SOC_STS_DFX_I2C0_ADDR(base) ((base) + 0x820)
#define SOC_STS_DFX_I2C1_ADDR(base) ((base) + 0x824)
#define SOC_STS_DFX_I2C2_ADDR(base) ((base) + 0x828)
#define SOC_STS_DFX_I2C3_ADDR(base) ((base) + 0x82c)
#define SOC_STS_DFX_I2C4_ADDR(base) ((base) + 0x830)
#define SOC_STS_DFX_STS_TRANS_GEN_A2B_ADDR(base) ((base) + 0x834)
#define SOC_STS_DFX_STS_TRANS_GEN_B2A_ADDR(base) ((base) + 0x838)
#define SOC_STS_DFX_STS_TRANS_DEC_A2B_ADDR(base) ((base) + 0x83C)
#define SOC_STS_DFX_STS_TRANS_DEC_B2A_ADDR(base) ((base) + 0x840)
#define SOC_STS_DFX_STS_STA_GEN_A2B_ADDR(base) ((base) + 0x844)
#define SOC_STS_DFX_STS_STA_GEN_B2A_ADDR(base) ((base) + 0x848)
#define SOC_STS_DFX_STS_STA_DEC_A2B_ADDR(base) ((base) + 0x84C)
#define SOC_STS_DFX_STS_STA_DEC_B2A_ADDR(base) ((base) + 0x850)
#define SOC_STS_DFX_USIM_CLK_ADDR(base) ((base) + 0x854)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_i2c : 5;
        unsigned int bypass_usim : 2;
        unsigned int bypass_gpio_a2b : 1;
        unsigned int bypass_gpio_b2a : 1;
        unsigned int sts_sta_interval_a2b_en : 1;
        unsigned int sts_sta_interval_a2b : 4;
        unsigned int sts_sta_interval_b2a_en : 1;
        unsigned int sts_sta_interval_b2a : 4;
        unsigned int reserved : 13;
    } reg;
} SOC_STS_STA_CFG0_UNION;
#endif
#define SOC_STS_STA_CFG0_bypass_i2c_START (0)
#define SOC_STS_STA_CFG0_bypass_i2c_END (4)
#define SOC_STS_STA_CFG0_bypass_usim_START (5)
#define SOC_STS_STA_CFG0_bypass_usim_END (6)
#define SOC_STS_STA_CFG0_bypass_gpio_a2b_START (7)
#define SOC_STS_STA_CFG0_bypass_gpio_a2b_END (7)
#define SOC_STS_STA_CFG0_bypass_gpio_b2a_START (8)
#define SOC_STS_STA_CFG0_bypass_gpio_b2a_END (8)
#define SOC_STS_STA_CFG0_sts_sta_interval_a2b_en_START (9)
#define SOC_STS_STA_CFG0_sts_sta_interval_a2b_en_END (9)
#define SOC_STS_STA_CFG0_sts_sta_interval_a2b_START (10)
#define SOC_STS_STA_CFG0_sts_sta_interval_a2b_END (13)
#define SOC_STS_STA_CFG0_sts_sta_interval_b2a_en_START (14)
#define SOC_STS_STA_CFG0_sts_sta_interval_b2a_en_END (14)
#define SOC_STS_STA_CFG0_sts_sta_interval_b2a_START (15)
#define SOC_STS_STA_CFG0_sts_sta_interval_b2a_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_i2s : 1;
        unsigned int bypass_spi0 : 1;
        unsigned int bypass_spi1 : 1;
        unsigned int bypass_rffe : 1;
        unsigned int bypass_intr_b2a : 1;
        unsigned int sts_intr_b2a_shield_cycle : 9;
        unsigned int sts_trans_wire_mode_a2b : 1;
        unsigned int sts_trans_wire_mode_b2a : 1;
        unsigned int sts_trans_interval_a2b_en : 1;
        unsigned int sts_trans_interval_a2b : 4;
        unsigned int sts_trans_interval_b2a_en : 1;
        unsigned int sts_trans_interval_b2a : 4;
        unsigned int reserved : 6;
    } reg;
} SOC_STS_TRANS_CFG0_UNION;
#endif
#define SOC_STS_TRANS_CFG0_bypass_i2s_START (0)
#define SOC_STS_TRANS_CFG0_bypass_i2s_END (0)
#define SOC_STS_TRANS_CFG0_bypass_spi0_START (1)
#define SOC_STS_TRANS_CFG0_bypass_spi0_END (1)
#define SOC_STS_TRANS_CFG0_bypass_spi1_START (2)
#define SOC_STS_TRANS_CFG0_bypass_spi1_END (2)
#define SOC_STS_TRANS_CFG0_bypass_rffe_START (3)
#define SOC_STS_TRANS_CFG0_bypass_rffe_END (3)
#define SOC_STS_TRANS_CFG0_bypass_intr_b2a_START (4)
#define SOC_STS_TRANS_CFG0_bypass_intr_b2a_END (4)
#define SOC_STS_TRANS_CFG0_sts_intr_b2a_shield_cycle_START (5)
#define SOC_STS_TRANS_CFG0_sts_intr_b2a_shield_cycle_END (13)
#define SOC_STS_TRANS_CFG0_sts_trans_wire_mode_a2b_START (14)
#define SOC_STS_TRANS_CFG0_sts_trans_wire_mode_a2b_END (14)
#define SOC_STS_TRANS_CFG0_sts_trans_wire_mode_b2a_START (15)
#define SOC_STS_TRANS_CFG0_sts_trans_wire_mode_b2a_END (15)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_a2b_en_START (16)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_a2b_en_END (16)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_a2b_START (17)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_a2b_END (20)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_b2a_en_START (21)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_b2a_en_END (21)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_b2a_START (22)
#define SOC_STS_TRANS_CFG0_sts_trans_interval_b2a_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_packet_trans_enable_a2b : 1;
        unsigned int sts_clk_str2end_a2b : 1;
        unsigned int sts_clk_end_cycle_en_a2b : 1;
        unsigned int sts_clk_end_cycle_a2b : 5;
        unsigned int sts_packet_receive_enable_b2a : 1;
        unsigned int sts_sta_trans_enable_a2b : 1;
        unsigned int sts_sta_receive_enable_b2a : 1;
        unsigned int reserved_0 : 5;
        unsigned int sts_packet_trans_enable_b2a : 1;
        unsigned int sts_clk_str2end_b2a : 1;
        unsigned int sts_clk_end_cycle_en_b2a : 1;
        unsigned int sts_clk_end_cycle_b2a : 5;
        unsigned int sts_packet_receive_enable_a2b : 1;
        unsigned int sts_sta_trans_enable_b2a : 1;
        unsigned int sts_sta_receive_enable_a2b : 1;
        unsigned int bypass_pclk_auto_gate : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_STS_CLK_CFG_UNION;
#endif
#define SOC_STS_CLK_CFG_sts_packet_trans_enable_a2b_START (0)
#define SOC_STS_CLK_CFG_sts_packet_trans_enable_a2b_END (0)
#define SOC_STS_CLK_CFG_sts_clk_str2end_a2b_START (1)
#define SOC_STS_CLK_CFG_sts_clk_str2end_a2b_END (1)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_en_a2b_START (2)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_en_a2b_END (2)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_a2b_START (3)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_a2b_END (7)
#define SOC_STS_CLK_CFG_sts_packet_receive_enable_b2a_START (8)
#define SOC_STS_CLK_CFG_sts_packet_receive_enable_b2a_END (8)
#define SOC_STS_CLK_CFG_sts_sta_trans_enable_a2b_START (9)
#define SOC_STS_CLK_CFG_sts_sta_trans_enable_a2b_END (9)
#define SOC_STS_CLK_CFG_sts_sta_receive_enable_b2a_START (10)
#define SOC_STS_CLK_CFG_sts_sta_receive_enable_b2a_END (10)
#define SOC_STS_CLK_CFG_sts_packet_trans_enable_b2a_START (16)
#define SOC_STS_CLK_CFG_sts_packet_trans_enable_b2a_END (16)
#define SOC_STS_CLK_CFG_sts_clk_str2end_b2a_START (17)
#define SOC_STS_CLK_CFG_sts_clk_str2end_b2a_END (17)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_en_b2a_START (18)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_en_b2a_END (18)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_b2a_START (19)
#define SOC_STS_CLK_CFG_sts_clk_end_cycle_b2a_END (23)
#define SOC_STS_CLK_CFG_sts_packet_receive_enable_a2b_START (24)
#define SOC_STS_CLK_CFG_sts_packet_receive_enable_a2b_END (24)
#define SOC_STS_CLK_CFG_sts_sta_trans_enable_b2a_START (25)
#define SOC_STS_CLK_CFG_sts_sta_trans_enable_b2a_END (25)
#define SOC_STS_CLK_CFG_sts_sta_receive_enable_a2b_START (26)
#define SOC_STS_CLK_CFG_sts_sta_receive_enable_a2b_END (26)
#define SOC_STS_CLK_CFG_bypass_pclk_auto_gate_START (27)
#define SOC_STS_CLK_CFG_bypass_pclk_auto_gate_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_func_mode : 2;
        unsigned int i2s_miso_edge_sel : 1;
        unsigned int i2s_mosi_edge_sel : 1;
        unsigned int i2s_device_clk_gate_bypass : 1;
        unsigned int i2s_first_sync_edge_mode : 1;
        unsigned int tdm_invld_frame_num : 2;
        unsigned int i2s_invld_frame_num : 3;
        unsigned int i2s_timeout_alarm_en : 1;
        unsigned int i2s_timeout_clk_num : 8;
        unsigned int i2s_send_data_only_en : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_STS_I2S_CFG_UNION;
#endif
#define SOC_STS_I2S_CFG_i2s_func_mode_START (0)
#define SOC_STS_I2S_CFG_i2s_func_mode_END (1)
#define SOC_STS_I2S_CFG_i2s_miso_edge_sel_START (2)
#define SOC_STS_I2S_CFG_i2s_miso_edge_sel_END (2)
#define SOC_STS_I2S_CFG_i2s_mosi_edge_sel_START (3)
#define SOC_STS_I2S_CFG_i2s_mosi_edge_sel_END (3)
#define SOC_STS_I2S_CFG_i2s_device_clk_gate_bypass_START (4)
#define SOC_STS_I2S_CFG_i2s_device_clk_gate_bypass_END (4)
#define SOC_STS_I2S_CFG_i2s_first_sync_edge_mode_START (5)
#define SOC_STS_I2S_CFG_i2s_first_sync_edge_mode_END (5)
#define SOC_STS_I2S_CFG_tdm_invld_frame_num_START (6)
#define SOC_STS_I2S_CFG_tdm_invld_frame_num_END (7)
#define SOC_STS_I2S_CFG_i2s_invld_frame_num_START (8)
#define SOC_STS_I2S_CFG_i2s_invld_frame_num_END (10)
#define SOC_STS_I2S_CFG_i2s_timeout_alarm_en_START (11)
#define SOC_STS_I2S_CFG_i2s_timeout_alarm_en_END (11)
#define SOC_STS_I2S_CFG_i2s_timeout_clk_num_START (12)
#define SOC_STS_I2S_CFG_i2s_timeout_clk_num_END (19)
#define SOC_STS_I2S_CFG_i2s_send_data_only_en_START (20)
#define SOC_STS_I2S_CFG_i2s_send_data_only_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi0_data_width : 5;
        unsigned int spi0_cfg_en : 1;
        unsigned int spi0_clock_polarity : 1;
        unsigned int spi0_clock_phase : 1;
        unsigned int spi0_invalid_frame_num : 4;
        unsigned int reserved_0 : 4;
        unsigned int spi1_data_width : 5;
        unsigned int spi1_cfg_en : 1;
        unsigned int spi1_clock_polarity : 1;
        unsigned int spi1_clock_phase : 1;
        unsigned int spi1_invalid_frame_num : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_STS_SPI_CFG0_UNION;
#endif
#define SOC_STS_SPI_CFG0_spi0_data_width_START (0)
#define SOC_STS_SPI_CFG0_spi0_data_width_END (4)
#define SOC_STS_SPI_CFG0_spi0_cfg_en_START (5)
#define SOC_STS_SPI_CFG0_spi0_cfg_en_END (5)
#define SOC_STS_SPI_CFG0_spi0_clock_polarity_START (6)
#define SOC_STS_SPI_CFG0_spi0_clock_polarity_END (6)
#define SOC_STS_SPI_CFG0_spi0_clock_phase_START (7)
#define SOC_STS_SPI_CFG0_spi0_clock_phase_END (7)
#define SOC_STS_SPI_CFG0_spi0_invalid_frame_num_START (8)
#define SOC_STS_SPI_CFG0_spi0_invalid_frame_num_END (11)
#define SOC_STS_SPI_CFG0_spi1_data_width_START (16)
#define SOC_STS_SPI_CFG0_spi1_data_width_END (20)
#define SOC_STS_SPI_CFG0_spi1_cfg_en_START (21)
#define SOC_STS_SPI_CFG0_spi1_cfg_en_END (21)
#define SOC_STS_SPI_CFG0_spi1_clock_polarity_START (22)
#define SOC_STS_SPI_CFG0_spi1_clock_polarity_END (22)
#define SOC_STS_SPI_CFG0_spi1_clock_phase_START (23)
#define SOC_STS_SPI_CFG0_spi1_clock_phase_END (23)
#define SOC_STS_SPI_CFG0_spi1_invalid_frame_num_START (24)
#define SOC_STS_SPI_CFG0_spi1_invalid_frame_num_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int spi0_data_data_phase0_interval_num : 3;
        unsigned int spi0_data_data_phase1_interval_num : 3;
        unsigned int spi0_cs_data_interval_num : 3;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 3;
        unsigned int spi1_data_data_phase0_interval_num : 3;
        unsigned int spi1_data_data_phase1_interval_num : 3;
        unsigned int spi1_cs_data_interval_num : 3;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_STS_SPI_CFG1_UNION;
#endif
#define SOC_STS_SPI_CFG1_spi0_data_data_phase0_interval_num_START (3)
#define SOC_STS_SPI_CFG1_spi0_data_data_phase0_interval_num_END (5)
#define SOC_STS_SPI_CFG1_spi0_data_data_phase1_interval_num_START (6)
#define SOC_STS_SPI_CFG1_spi0_data_data_phase1_interval_num_END (8)
#define SOC_STS_SPI_CFG1_spi0_cs_data_interval_num_START (9)
#define SOC_STS_SPI_CFG1_spi0_cs_data_interval_num_END (11)
#define SOC_STS_SPI_CFG1_spi1_data_data_phase0_interval_num_START (19)
#define SOC_STS_SPI_CFG1_spi1_data_data_phase0_interval_num_END (21)
#define SOC_STS_SPI_CFG1_spi1_data_data_phase1_interval_num_START (22)
#define SOC_STS_SPI_CFG1_spi1_data_data_phase1_interval_num_END (24)
#define SOC_STS_SPI_CFG1_spi1_cs_data_interval_num_START (25)
#define SOC_STS_SPI_CFG1_spi1_cs_data_interval_num_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_vld_sa0 : 32;
    } reg;
} SOC_STS_RFFE_CFG0_UNION;
#endif
#define SOC_STS_RFFE_CFG0_rffe_vld_sa0_START (0)
#define SOC_STS_RFFE_CFG0_rffe_vld_sa0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_vld_sa1 : 32;
    } reg;
} SOC_STS_RFFE_CFG1_UNION;
#endif
#define SOC_STS_RFFE_CFG1_rffe_vld_sa1_START (0)
#define SOC_STS_RFFE_CFG1_rffe_vld_sa1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_invld_rd_frame_num : 3;
        unsigned int rffe_parity_chk_enable : 1;
        unsigned int rffe_parity_err_intercept_enable : 1;
        unsigned int rffe_synchro_read_enable : 1;
        unsigned int rffe_sdata_release_enable : 1;
        unsigned int rffe_half_speed_enable : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_STS_RFFE_CFG2_UNION;
#endif
#define SOC_STS_RFFE_CFG2_rffe_invld_rd_frame_num_START (0)
#define SOC_STS_RFFE_CFG2_rffe_invld_rd_frame_num_END (2)
#define SOC_STS_RFFE_CFG2_rffe_parity_chk_enable_START (3)
#define SOC_STS_RFFE_CFG2_rffe_parity_chk_enable_END (3)
#define SOC_STS_RFFE_CFG2_rffe_parity_err_intercept_enable_START (4)
#define SOC_STS_RFFE_CFG2_rffe_parity_err_intercept_enable_END (4)
#define SOC_STS_RFFE_CFG2_rffe_synchro_read_enable_START (5)
#define SOC_STS_RFFE_CFG2_rffe_synchro_read_enable_END (5)
#define SOC_STS_RFFE_CFG2_rffe_sdata_release_enable_START (6)
#define SOC_STS_RFFE_CFG2_rffe_sdata_release_enable_END (6)
#define SOC_STS_RFFE_CFG2_rffe_half_speed_enable_START (7)
#define SOC_STS_RFFE_CFG2_rffe_half_speed_enable_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi0_div_ratio_pre : 8;
        unsigned int spi0_div_ratio_post : 8;
        unsigned int spi1_div_ratio_pre : 8;
        unsigned int spi1_div_ratio_post : 8;
    } reg;
} SOC_STS_SPI_CFG2_UNION;
#endif
#define SOC_STS_SPI_CFG2_spi0_div_ratio_pre_START (0)
#define SOC_STS_SPI_CFG2_spi0_div_ratio_pre_END (7)
#define SOC_STS_SPI_CFG2_spi0_div_ratio_post_START (8)
#define SOC_STS_SPI_CFG2_spi0_div_ratio_post_END (15)
#define SOC_STS_SPI_CFG2_spi1_div_ratio_pre_START (16)
#define SOC_STS_SPI_CFG2_spi1_div_ratio_pre_END (23)
#define SOC_STS_SPI_CFG2_spi1_div_ratio_post_START (24)
#define SOC_STS_SPI_CFG2_spi1_div_ratio_post_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int usim0_clk_timeout_num : 7;
        unsigned int usim1_clk_timeout_num : 7;
        unsigned int bypass_usim0_auto_clk : 1;
        unsigned int bypass_usim1_auto_clk : 1;
        unsigned int softcontrl_usim0_clk_en : 1;
        unsigned int softcontrl_usim1_clk_en : 1;
        unsigned int softcontrl_usim0_clk_stop_level : 1;
        unsigned int softcontrl_usim1_clk_stop_level : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_STS_USIM_CFG_UNION;
#endif
#define SOC_STS_USIM_CFG_usim0_clk_timeout_num_START (0)
#define SOC_STS_USIM_CFG_usim0_clk_timeout_num_END (6)
#define SOC_STS_USIM_CFG_usim1_clk_timeout_num_START (7)
#define SOC_STS_USIM_CFG_usim1_clk_timeout_num_END (13)
#define SOC_STS_USIM_CFG_bypass_usim0_auto_clk_START (14)
#define SOC_STS_USIM_CFG_bypass_usim0_auto_clk_END (14)
#define SOC_STS_USIM_CFG_bypass_usim1_auto_clk_START (15)
#define SOC_STS_USIM_CFG_bypass_usim1_auto_clk_END (15)
#define SOC_STS_USIM_CFG_softcontrl_usim0_clk_en_START (16)
#define SOC_STS_USIM_CFG_softcontrl_usim0_clk_en_END (16)
#define SOC_STS_USIM_CFG_softcontrl_usim1_clk_en_START (17)
#define SOC_STS_USIM_CFG_softcontrl_usim1_clk_en_END (17)
#define SOC_STS_USIM_CFG_softcontrl_usim0_clk_stop_level_START (18)
#define SOC_STS_USIM_CFG_softcontrl_usim0_clk_stop_level_END (18)
#define SOC_STS_USIM_CFG_softcontrl_usim1_clk_stop_level_START (19)
#define SOC_STS_USIM_CFG_softcontrl_usim1_clk_stop_level_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpio_group_enable_a2b : 7;
        unsigned int gpio_group_enable_b2a : 7;
        unsigned int reserved : 18;
    } reg;
} SOC_STS_GPIO_CFG_UNION;
#endif
#define SOC_STS_GPIO_CFG_gpio_group_enable_a2b_START (0)
#define SOC_STS_GPIO_CFG_gpio_group_enable_a2b_END (6)
#define SOC_STS_GPIO_CFG_gpio_group_enable_b2a_START (7)
#define SOC_STS_GPIO_CFG_gpio_group_enable_b2a_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stsb_gpio_oen_00 : 1;
        unsigned int stsb_gpio_oen_01 : 1;
        unsigned int stsb_gpio_oen_02 : 1;
        unsigned int stsb_gpio_oen_03 : 1;
        unsigned int stsb_gpio_oen_04 : 1;
        unsigned int stsb_gpio_oen_05 : 1;
        unsigned int stsb_gpio_oen_06 : 1;
        unsigned int stsb_gpio_oen_07 : 1;
        unsigned int stsb_gpio_oen_08 : 1;
        unsigned int stsb_gpio_oen_09 : 1;
        unsigned int stsb_gpio_oen_10 : 1;
        unsigned int stsb_gpio_oen_11 : 1;
        unsigned int stsb_gpio_oen_12 : 1;
        unsigned int stsb_gpio_oen_13 : 1;
        unsigned int stsb_gpio_oen_14 : 1;
        unsigned int stsb_gpio_oen_15 : 1;
        unsigned int stsb_gpio_oen_16 : 1;
        unsigned int stsb_gpio_oen_17 : 1;
        unsigned int stsb_gpio_oen_18 : 1;
        unsigned int stsb_gpio_oen_19 : 1;
        unsigned int stsb_gpio_oen_20 : 1;
        unsigned int stsb_gpio_oen_21 : 1;
        unsigned int stsb_gpio_oen_22 : 1;
        unsigned int stsb_gpio_oen_23 : 1;
        unsigned int stsb_gpio_oen_24 : 1;
        unsigned int stsb_gpio_oen_25 : 1;
        unsigned int stsb_gpio_oen_26 : 1;
        unsigned int stsb_gpio_oen_27 : 1;
        unsigned int stsb_gpio_oen_28 : 1;
        unsigned int stsb_gpio_oen_29 : 1;
        unsigned int stsb_gpio_oen_30 : 1;
        unsigned int stsb_gpio_oen_31 : 1;
    } reg;
} SOC_STS_GPIO_OEN_A2B_CFG0_UNION;
#endif
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_00_START (0)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_00_END (0)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_01_START (1)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_01_END (1)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_02_START (2)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_02_END (2)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_03_START (3)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_03_END (3)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_04_START (4)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_04_END (4)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_05_START (5)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_05_END (5)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_06_START (6)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_06_END (6)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_07_START (7)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_07_END (7)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_08_START (8)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_08_END (8)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_09_START (9)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_09_END (9)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_10_START (10)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_10_END (10)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_11_START (11)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_11_END (11)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_12_START (12)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_12_END (12)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_13_START (13)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_13_END (13)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_14_START (14)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_14_END (14)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_15_START (15)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_15_END (15)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_16_START (16)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_16_END (16)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_17_START (17)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_17_END (17)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_18_START (18)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_18_END (18)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_19_START (19)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_19_END (19)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_20_START (20)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_20_END (20)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_21_START (21)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_21_END (21)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_22_START (22)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_22_END (22)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_23_START (23)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_23_END (23)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_24_START (24)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_24_END (24)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_25_START (25)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_25_END (25)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_26_START (26)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_26_END (26)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_27_START (27)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_27_END (27)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_28_START (28)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_28_END (28)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_29_START (29)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_29_END (29)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_30_START (30)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_30_END (30)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_31_START (31)
#define SOC_STS_GPIO_OEN_A2B_CFG0_stsb_gpio_oen_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stsb_gpio_oen_32 : 1;
        unsigned int stsb_gpio_oen_33 : 1;
        unsigned int stsb_gpio_oen_34 : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_STS_GPIO_OEN_A2B_CFG1_UNION;
#endif
#define SOC_STS_GPIO_OEN_A2B_CFG1_stsb_gpio_oen_32_START (0)
#define SOC_STS_GPIO_OEN_A2B_CFG1_stsb_gpio_oen_32_END (0)
#define SOC_STS_GPIO_OEN_A2B_CFG1_stsb_gpio_oen_33_START (1)
#define SOC_STS_GPIO_OEN_A2B_CFG1_stsb_gpio_oen_33_END (1)
#define SOC_STS_GPIO_OEN_A2B_CFG1_stsb_gpio_oen_34_START (2)
#define SOC_STS_GPIO_OEN_A2B_CFG1_stsb_gpio_oen_34_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stsa_gpio_oen_00 : 1;
        unsigned int stsa_gpio_oen_01 : 1;
        unsigned int stsa_gpio_oen_02 : 1;
        unsigned int stsa_gpio_oen_03 : 1;
        unsigned int stsa_gpio_oen_04 : 1;
        unsigned int stsa_gpio_oen_05 : 1;
        unsigned int stsa_gpio_oen_06 : 1;
        unsigned int stsa_gpio_oen_07 : 1;
        unsigned int stsa_gpio_oen_08 : 1;
        unsigned int stsa_gpio_oen_09 : 1;
        unsigned int stsa_gpio_oen_10 : 1;
        unsigned int stsa_gpio_oen_11 : 1;
        unsigned int stsa_gpio_oen_12 : 1;
        unsigned int stsa_gpio_oen_13 : 1;
        unsigned int stsa_gpio_oen_14 : 1;
        unsigned int stsa_gpio_oen_15 : 1;
        unsigned int stsa_gpio_oen_16 : 1;
        unsigned int stsa_gpio_oen_17 : 1;
        unsigned int stsa_gpio_oen_18 : 1;
        unsigned int stsa_gpio_oen_19 : 1;
        unsigned int stsa_gpio_oen_20 : 1;
        unsigned int stsa_gpio_oen_21 : 1;
        unsigned int stsa_gpio_oen_22 : 1;
        unsigned int stsa_gpio_oen_23 : 1;
        unsigned int stsa_gpio_oen_24 : 1;
        unsigned int stsa_gpio_oen_25 : 1;
        unsigned int stsa_gpio_oen_26 : 1;
        unsigned int stsa_gpio_oen_27 : 1;
        unsigned int stsa_gpio_oen_28 : 1;
        unsigned int stsa_gpio_oen_29 : 1;
        unsigned int stsa_gpio_oen_30 : 1;
        unsigned int stsa_gpio_oen_31 : 1;
    } reg;
} SOC_STS_GPIO_OEN_B2A_CFG0_UNION;
#endif
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_00_START (0)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_00_END (0)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_01_START (1)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_01_END (1)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_02_START (2)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_02_END (2)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_03_START (3)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_03_END (3)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_04_START (4)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_04_END (4)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_05_START (5)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_05_END (5)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_06_START (6)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_06_END (6)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_07_START (7)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_07_END (7)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_08_START (8)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_08_END (8)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_09_START (9)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_09_END (9)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_10_START (10)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_10_END (10)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_11_START (11)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_11_END (11)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_12_START (12)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_12_END (12)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_13_START (13)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_13_END (13)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_14_START (14)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_14_END (14)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_15_START (15)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_15_END (15)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_16_START (16)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_16_END (16)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_17_START (17)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_17_END (17)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_18_START (18)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_18_END (18)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_19_START (19)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_19_END (19)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_20_START (20)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_20_END (20)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_21_START (21)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_21_END (21)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_22_START (22)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_22_END (22)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_23_START (23)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_23_END (23)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_24_START (24)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_24_END (24)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_25_START (25)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_25_END (25)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_26_START (26)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_26_END (26)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_27_START (27)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_27_END (27)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_28_START (28)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_28_END (28)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_29_START (29)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_29_END (29)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_30_START (30)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_30_END (30)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_31_START (31)
#define SOC_STS_GPIO_OEN_B2A_CFG0_stsa_gpio_oen_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stsa_gpio_oen_32 : 1;
        unsigned int stsa_gpio_oen_33 : 1;
        unsigned int stsa_gpio_oen_34 : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_STS_GPIO_OEN_B2A_CFG1_UNION;
#endif
#define SOC_STS_GPIO_OEN_B2A_CFG1_stsa_gpio_oen_32_START (0)
#define SOC_STS_GPIO_OEN_B2A_CFG1_stsa_gpio_oen_32_END (0)
#define SOC_STS_GPIO_OEN_B2A_CFG1_stsa_gpio_oen_33_START (1)
#define SOC_STS_GPIO_OEN_B2A_CFG1_stsa_gpio_oen_33_END (1)
#define SOC_STS_GPIO_OEN_B2A_CFG1_stsa_gpio_oen_34_START (2)
#define SOC_STS_GPIO_OEN_B2A_CFG1_stsa_gpio_oen_34_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_sts_trans_a2b_prt_err : 1;
        unsigned int intr_sts_trans_b2a_prt_err : 1;
        unsigned int intr_sts_sta_a2b_prt_err : 1;
        unsigned int intr_sts_sta_b2a_prt_err : 1;
        unsigned int intr_sts_bside_err : 1;
        unsigned int intr_rffe_read_fifo_emp_err : 1;
        unsigned int intr_rffe_cmd_prt_err : 1;
        unsigned int intr_rffe_data_prt_err : 1;
        unsigned int intr_rffe_read_prt_err : 1;
        unsigned int intr_spi0_intf_b2a_fifo_read_empty : 1;
        unsigned int intr_spi1_intf_b2a_fifo_read_empty : 1;
        unsigned int intr_i2s_intf_b2a_fifo_read_empty : 1;
        unsigned int intr_rffe_a2b_frame_fifo_full_err_aside : 1;
        unsigned int intr_spi0_a2b_frame_fifo_full_err_aside : 1;
        unsigned int intr_spi1_a2b_frame_fifo_full_err_aside : 1;
        unsigned int intr_i2s_a2b_frame_fifo_full_err_aside : 1;
        unsigned int intr_rffe_b2a_frame_fifo_full_err_aside : 1;
        unsigned int intr_spi0_b2a_frame_fifo_full_err_aside : 1;
        unsigned int intr_spi1_b2a_frame_fifo_full_err_aside : 1;
        unsigned int intr_i2s_b2a_frame_fifo_full_err_aside : 1;
        unsigned int intr_rffe_a2b_frame_fifo_full_err_bside : 1;
        unsigned int intr_spi0_a2b_frame_fifo_full_err_bside : 1;
        unsigned int intr_spi1_a2b_frame_fifo_full_err_bside : 1;
        unsigned int intr_i2s_a2b_frame_fifo_full_err_bside : 1;
        unsigned int intr_rffe_b2a_frame_fifo_full_err_bside : 1;
        unsigned int intr_spi0_b2a_frame_fifo_full_err_bside : 1;
        unsigned int intr_spi1_b2a_frame_fifo_full_err_bside : 1;
        unsigned int intr_i2s_b2a_frame_fifo_full_err_bside : 1;
        unsigned int intr_spi0_a2b_intf_fifo_full_err : 1;
        unsigned int intr_spi1_a2b_intf_fifo_full_err : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_STS_INTR_STATUS_UNION;
#endif
#define SOC_STS_INTR_STATUS_intr_sts_trans_a2b_prt_err_START (0)
#define SOC_STS_INTR_STATUS_intr_sts_trans_a2b_prt_err_END (0)
#define SOC_STS_INTR_STATUS_intr_sts_trans_b2a_prt_err_START (1)
#define SOC_STS_INTR_STATUS_intr_sts_trans_b2a_prt_err_END (1)
#define SOC_STS_INTR_STATUS_intr_sts_sta_a2b_prt_err_START (2)
#define SOC_STS_INTR_STATUS_intr_sts_sta_a2b_prt_err_END (2)
#define SOC_STS_INTR_STATUS_intr_sts_sta_b2a_prt_err_START (3)
#define SOC_STS_INTR_STATUS_intr_sts_sta_b2a_prt_err_END (3)
#define SOC_STS_INTR_STATUS_intr_sts_bside_err_START (4)
#define SOC_STS_INTR_STATUS_intr_sts_bside_err_END (4)
#define SOC_STS_INTR_STATUS_intr_rffe_read_fifo_emp_err_START (5)
#define SOC_STS_INTR_STATUS_intr_rffe_read_fifo_emp_err_END (5)
#define SOC_STS_INTR_STATUS_intr_rffe_cmd_prt_err_START (6)
#define SOC_STS_INTR_STATUS_intr_rffe_cmd_prt_err_END (6)
#define SOC_STS_INTR_STATUS_intr_rffe_data_prt_err_START (7)
#define SOC_STS_INTR_STATUS_intr_rffe_data_prt_err_END (7)
#define SOC_STS_INTR_STATUS_intr_rffe_read_prt_err_START (8)
#define SOC_STS_INTR_STATUS_intr_rffe_read_prt_err_END (8)
#define SOC_STS_INTR_STATUS_intr_spi0_intf_b2a_fifo_read_empty_START (9)
#define SOC_STS_INTR_STATUS_intr_spi0_intf_b2a_fifo_read_empty_END (9)
#define SOC_STS_INTR_STATUS_intr_spi1_intf_b2a_fifo_read_empty_START (10)
#define SOC_STS_INTR_STATUS_intr_spi1_intf_b2a_fifo_read_empty_END (10)
#define SOC_STS_INTR_STATUS_intr_i2s_intf_b2a_fifo_read_empty_START (11)
#define SOC_STS_INTR_STATUS_intr_i2s_intf_b2a_fifo_read_empty_END (11)
#define SOC_STS_INTR_STATUS_intr_rffe_a2b_frame_fifo_full_err_aside_START (12)
#define SOC_STS_INTR_STATUS_intr_rffe_a2b_frame_fifo_full_err_aside_END (12)
#define SOC_STS_INTR_STATUS_intr_spi0_a2b_frame_fifo_full_err_aside_START (13)
#define SOC_STS_INTR_STATUS_intr_spi0_a2b_frame_fifo_full_err_aside_END (13)
#define SOC_STS_INTR_STATUS_intr_spi1_a2b_frame_fifo_full_err_aside_START (14)
#define SOC_STS_INTR_STATUS_intr_spi1_a2b_frame_fifo_full_err_aside_END (14)
#define SOC_STS_INTR_STATUS_intr_i2s_a2b_frame_fifo_full_err_aside_START (15)
#define SOC_STS_INTR_STATUS_intr_i2s_a2b_frame_fifo_full_err_aside_END (15)
#define SOC_STS_INTR_STATUS_intr_rffe_b2a_frame_fifo_full_err_aside_START (16)
#define SOC_STS_INTR_STATUS_intr_rffe_b2a_frame_fifo_full_err_aside_END (16)
#define SOC_STS_INTR_STATUS_intr_spi0_b2a_frame_fifo_full_err_aside_START (17)
#define SOC_STS_INTR_STATUS_intr_spi0_b2a_frame_fifo_full_err_aside_END (17)
#define SOC_STS_INTR_STATUS_intr_spi1_b2a_frame_fifo_full_err_aside_START (18)
#define SOC_STS_INTR_STATUS_intr_spi1_b2a_frame_fifo_full_err_aside_END (18)
#define SOC_STS_INTR_STATUS_intr_i2s_b2a_frame_fifo_full_err_aside_START (19)
#define SOC_STS_INTR_STATUS_intr_i2s_b2a_frame_fifo_full_err_aside_END (19)
#define SOC_STS_INTR_STATUS_intr_rffe_a2b_frame_fifo_full_err_bside_START (20)
#define SOC_STS_INTR_STATUS_intr_rffe_a2b_frame_fifo_full_err_bside_END (20)
#define SOC_STS_INTR_STATUS_intr_spi0_a2b_frame_fifo_full_err_bside_START (21)
#define SOC_STS_INTR_STATUS_intr_spi0_a2b_frame_fifo_full_err_bside_END (21)
#define SOC_STS_INTR_STATUS_intr_spi1_a2b_frame_fifo_full_err_bside_START (22)
#define SOC_STS_INTR_STATUS_intr_spi1_a2b_frame_fifo_full_err_bside_END (22)
#define SOC_STS_INTR_STATUS_intr_i2s_a2b_frame_fifo_full_err_bside_START (23)
#define SOC_STS_INTR_STATUS_intr_i2s_a2b_frame_fifo_full_err_bside_END (23)
#define SOC_STS_INTR_STATUS_intr_rffe_b2a_frame_fifo_full_err_bside_START (24)
#define SOC_STS_INTR_STATUS_intr_rffe_b2a_frame_fifo_full_err_bside_END (24)
#define SOC_STS_INTR_STATUS_intr_spi0_b2a_frame_fifo_full_err_bside_START (25)
#define SOC_STS_INTR_STATUS_intr_spi0_b2a_frame_fifo_full_err_bside_END (25)
#define SOC_STS_INTR_STATUS_intr_spi1_b2a_frame_fifo_full_err_bside_START (26)
#define SOC_STS_INTR_STATUS_intr_spi1_b2a_frame_fifo_full_err_bside_END (26)
#define SOC_STS_INTR_STATUS_intr_i2s_b2a_frame_fifo_full_err_bside_START (27)
#define SOC_STS_INTR_STATUS_intr_i2s_b2a_frame_fifo_full_err_bside_END (27)
#define SOC_STS_INTR_STATUS_intr_spi0_a2b_intf_fifo_full_err_START (28)
#define SOC_STS_INTR_STATUS_intr_spi0_a2b_intf_fifo_full_err_END (28)
#define SOC_STS_INTR_STATUS_intr_spi1_a2b_intf_fifo_full_err_START (29)
#define SOC_STS_INTR_STATUS_intr_spi1_a2b_intf_fifo_full_err_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_sts_trans_a2b_prt_err_msk : 1;
        unsigned int intr_sts_trans_b2a_prt_err_msk : 1;
        unsigned int intr_sts_sta_a2b_prt_err_msk : 1;
        unsigned int intr_sts_sta_b2a_prt_err_msk : 1;
        unsigned int intr_sts_bside_err_msk : 1;
        unsigned int intr_rffe_read_fifo_emp_err_msk : 1;
        unsigned int intr_rffe_cmd_prt_err_msk : 1;
        unsigned int intr_rffe_data_prt_err_msk : 1;
        unsigned int intr_rffe_read_prt_err_msk : 1;
        unsigned int intr_spi0_intf_b2a_fifo_read_empty_msk : 1;
        unsigned int intr_spi1_intf_b2a_fifo_read_empty_msk : 1;
        unsigned int intr_i2s_intf_b2a_fifo_read_empty_msk : 1;
        unsigned int intr_rffe_a2b_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_spi0_a2b_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_spi1_a2b_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_i2s_a2b_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_rffe_b2a_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_spi0_b2a_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_spi1_b2a_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_i2s_b2a_frame_fifo_full_err_aside_msk : 1;
        unsigned int intr_rffe_a2b_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_spi0_a2b_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_spi1_a2b_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_i2s_a2b_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_rffe_b2a_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_spi0_b2a_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_spi1_b2a_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_i2s_b2a_frame_fifo_full_err_bside_msk : 1;
        unsigned int intr_spi0_a2b_intf_fifo_full_err_msk : 1;
        unsigned int intr_spi1_a2b_intf_fifo_full_err_msk : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_STS_INTR_STATUS_ENABLE_UNION;
#endif
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_trans_a2b_prt_err_msk_START (0)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_trans_a2b_prt_err_msk_END (0)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_trans_b2a_prt_err_msk_START (1)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_trans_b2a_prt_err_msk_END (1)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_sta_a2b_prt_err_msk_START (2)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_sta_a2b_prt_err_msk_END (2)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_sta_b2a_prt_err_msk_START (3)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_sta_b2a_prt_err_msk_END (3)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_bside_err_msk_START (4)
#define SOC_STS_INTR_STATUS_ENABLE_intr_sts_bside_err_msk_END (4)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_read_fifo_emp_err_msk_START (5)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_read_fifo_emp_err_msk_END (5)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_cmd_prt_err_msk_START (6)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_cmd_prt_err_msk_END (6)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_data_prt_err_msk_START (7)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_data_prt_err_msk_END (7)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_read_prt_err_msk_START (8)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_read_prt_err_msk_END (8)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_intf_b2a_fifo_read_empty_msk_START (9)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_intf_b2a_fifo_read_empty_msk_END (9)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_intf_b2a_fifo_read_empty_msk_START (10)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_intf_b2a_fifo_read_empty_msk_END (10)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_intf_b2a_fifo_read_empty_msk_START (11)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_intf_b2a_fifo_read_empty_msk_END (11)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_a2b_frame_fifo_full_err_aside_msk_START (12)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_a2b_frame_fifo_full_err_aside_msk_END (12)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_a2b_frame_fifo_full_err_aside_msk_START (13)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_a2b_frame_fifo_full_err_aside_msk_END (13)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_a2b_frame_fifo_full_err_aside_msk_START (14)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_a2b_frame_fifo_full_err_aside_msk_END (14)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_a2b_frame_fifo_full_err_aside_msk_START (15)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_a2b_frame_fifo_full_err_aside_msk_END (15)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_b2a_frame_fifo_full_err_aside_msk_START (16)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_b2a_frame_fifo_full_err_aside_msk_END (16)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_b2a_frame_fifo_full_err_aside_msk_START (17)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_b2a_frame_fifo_full_err_aside_msk_END (17)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_b2a_frame_fifo_full_err_aside_msk_START (18)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_b2a_frame_fifo_full_err_aside_msk_END (18)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_b2a_frame_fifo_full_err_aside_msk_START (19)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_b2a_frame_fifo_full_err_aside_msk_END (19)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_a2b_frame_fifo_full_err_bside_msk_START (20)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_a2b_frame_fifo_full_err_bside_msk_END (20)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_a2b_frame_fifo_full_err_bside_msk_START (21)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_a2b_frame_fifo_full_err_bside_msk_END (21)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_a2b_frame_fifo_full_err_bside_msk_START (22)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_a2b_frame_fifo_full_err_bside_msk_END (22)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_a2b_frame_fifo_full_err_bside_msk_START (23)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_a2b_frame_fifo_full_err_bside_msk_END (23)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_b2a_frame_fifo_full_err_bside_msk_START (24)
#define SOC_STS_INTR_STATUS_ENABLE_intr_rffe_b2a_frame_fifo_full_err_bside_msk_END (24)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_b2a_frame_fifo_full_err_bside_msk_START (25)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_b2a_frame_fifo_full_err_bside_msk_END (25)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_b2a_frame_fifo_full_err_bside_msk_START (26)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_b2a_frame_fifo_full_err_bside_msk_END (26)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_b2a_frame_fifo_full_err_bside_msk_START (27)
#define SOC_STS_INTR_STATUS_ENABLE_intr_i2s_b2a_frame_fifo_full_err_bside_msk_END (27)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_a2b_intf_fifo_full_err_msk_START (28)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi0_a2b_intf_fifo_full_err_msk_END (28)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_a2b_intf_fifo_full_err_msk_START (29)
#define SOC_STS_INTR_STATUS_ENABLE_intr_spi1_a2b_intf_fifo_full_err_msk_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_sts_trans_a2b_prt_err_output_enable : 1;
        unsigned int intr_sts_trans_b2a_prt_err_output_enable : 1;
        unsigned int intr_sts_sta_a2b_prt_err_output_enable : 1;
        unsigned int intr_sts_sta_b2a_prt_err_output_enable : 1;
        unsigned int intr_sts_bside_err_output_enable : 1;
        unsigned int intr_rffe_read_fifo_emp_err_output_enable : 1;
        unsigned int intr_rffe_cmd_prt_err_output_enable : 1;
        unsigned int intr_rffe_data_prt_err_output_enable : 1;
        unsigned int intr_rffe_read_prt_err_output_enable : 1;
        unsigned int intr_spi0_intf_b2a_fifo_read_empty_output_enable : 1;
        unsigned int intr_spi1_intf_b2a_fifo_read_empty_output_enable : 1;
        unsigned int intr_i2s_intf_b2a_fifo_read_empty_output_enable : 1;
        unsigned int intr_rffe_a2b_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_spi0_a2b_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_spi1_a2b_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_i2s_a2b_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_rffe_b2a_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_spi0_b2a_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_spi1_b2a_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_i2s_b2a_frame_fifo_full_err_aside_output_enable : 1;
        unsigned int intr_rffe_a2b_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_spi0_a2b_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_spi1_a2b_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_i2s_a2b_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_rffe_b2a_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_spi0_b2a_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_spi1_b2a_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_i2s_b2a_frame_fifo_full_err_bside_output_enable : 1;
        unsigned int intr_spi0_a2b_intf_fifo_full_err_output_enable : 1;
        unsigned int intr_spi1_a2b_intf_fifo_full_err_output_enable : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_STS_INTR_OUTPUT_ENABLE_UNION;
#endif
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_trans_a2b_prt_err_output_enable_START (0)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_trans_a2b_prt_err_output_enable_END (0)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_trans_b2a_prt_err_output_enable_START (1)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_trans_b2a_prt_err_output_enable_END (1)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_sta_a2b_prt_err_output_enable_START (2)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_sta_a2b_prt_err_output_enable_END (2)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_sta_b2a_prt_err_output_enable_START (3)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_sta_b2a_prt_err_output_enable_END (3)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_bside_err_output_enable_START (4)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_sts_bside_err_output_enable_END (4)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_read_fifo_emp_err_output_enable_START (5)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_read_fifo_emp_err_output_enable_END (5)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_cmd_prt_err_output_enable_START (6)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_cmd_prt_err_output_enable_END (6)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_data_prt_err_output_enable_START (7)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_data_prt_err_output_enable_END (7)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_read_prt_err_output_enable_START (8)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_read_prt_err_output_enable_END (8)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_intf_b2a_fifo_read_empty_output_enable_START (9)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_intf_b2a_fifo_read_empty_output_enable_END (9)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_intf_b2a_fifo_read_empty_output_enable_START (10)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_intf_b2a_fifo_read_empty_output_enable_END (10)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_intf_b2a_fifo_read_empty_output_enable_START (11)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_intf_b2a_fifo_read_empty_output_enable_END (11)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_a2b_frame_fifo_full_err_aside_output_enable_START (12)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_a2b_frame_fifo_full_err_aside_output_enable_END (12)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_a2b_frame_fifo_full_err_aside_output_enable_START (13)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_a2b_frame_fifo_full_err_aside_output_enable_END (13)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_a2b_frame_fifo_full_err_aside_output_enable_START (14)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_a2b_frame_fifo_full_err_aside_output_enable_END (14)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_a2b_frame_fifo_full_err_aside_output_enable_START (15)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_a2b_frame_fifo_full_err_aside_output_enable_END (15)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_b2a_frame_fifo_full_err_aside_output_enable_START (16)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_b2a_frame_fifo_full_err_aside_output_enable_END (16)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_b2a_frame_fifo_full_err_aside_output_enable_START (17)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_b2a_frame_fifo_full_err_aside_output_enable_END (17)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_b2a_frame_fifo_full_err_aside_output_enable_START (18)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_b2a_frame_fifo_full_err_aside_output_enable_END (18)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_b2a_frame_fifo_full_err_aside_output_enable_START (19)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_b2a_frame_fifo_full_err_aside_output_enable_END (19)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_a2b_frame_fifo_full_err_bside_output_enable_START (20)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_a2b_frame_fifo_full_err_bside_output_enable_END (20)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_a2b_frame_fifo_full_err_bside_output_enable_START (21)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_a2b_frame_fifo_full_err_bside_output_enable_END (21)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_a2b_frame_fifo_full_err_bside_output_enable_START (22)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_a2b_frame_fifo_full_err_bside_output_enable_END (22)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_a2b_frame_fifo_full_err_bside_output_enable_START (23)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_a2b_frame_fifo_full_err_bside_output_enable_END (23)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_b2a_frame_fifo_full_err_bside_output_enable_START (24)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_rffe_b2a_frame_fifo_full_err_bside_output_enable_END (24)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_b2a_frame_fifo_full_err_bside_output_enable_START (25)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_b2a_frame_fifo_full_err_bside_output_enable_END (25)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_b2a_frame_fifo_full_err_bside_output_enable_START (26)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_b2a_frame_fifo_full_err_bside_output_enable_END (26)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_b2a_frame_fifo_full_err_bside_output_enable_START (27)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_i2s_b2a_frame_fifo_full_err_bside_output_enable_END (27)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_a2b_intf_fifo_full_err_output_enable_START (28)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi0_a2b_intf_fifo_full_err_output_enable_END (28)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_a2b_intf_fifo_full_err_output_enable_START (29)
#define SOC_STS_INTR_OUTPUT_ENABLE_intr_spi1_a2b_intf_fifo_full_err_output_enable_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_trans_b2a_prt_err_info_0 : 32;
    } reg;
} SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_0_UNION;
#endif
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_0_sts_trans_b2a_prt_err_info_0_START (0)
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_0_sts_trans_b2a_prt_err_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_trans_b2a_prt_err_info_1 : 32;
    } reg;
} SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_1_UNION;
#endif
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_1_sts_trans_b2a_prt_err_info_1_START (0)
#define SOC_STS_INTR_STS_TRANS_B2A_P_ERR_INFO_1_sts_trans_b2a_prt_err_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_sta_b2a_prt_err_info : 32;
    } reg;
} SOC_STS_INTR_STS_STA_B2A_P_ERR_INFO_UNION;
#endif
#define SOC_STS_INTR_STS_STA_B2A_P_ERR_INFO_sts_sta_b2a_prt_err_info_START (0)
#define SOC_STS_INTR_STS_STA_B2A_P_ERR_INFO_sts_sta_b2a_prt_err_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_cmd_prt_err_info : 12;
        unsigned int rffe_data_prt_err_info : 20;
    } reg;
} SOC_STS_INTR_RFFE_CMD_DATA_P_ERR_INFO_UNION;
#endif
#define SOC_STS_INTR_RFFE_CMD_DATA_P_ERR_INFO_rffe_cmd_prt_err_info_START (0)
#define SOC_STS_INTR_RFFE_CMD_DATA_P_ERR_INFO_rffe_cmd_prt_err_info_END (11)
#define SOC_STS_INTR_RFFE_CMD_DATA_P_ERR_INFO_rffe_data_prt_err_info_START (12)
#define SOC_STS_INTR_RFFE_CMD_DATA_P_ERR_INFO_rffe_data_prt_err_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_trans_a2b_prt_err_info_0 : 32;
    } reg;
} SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_0_UNION;
#endif
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_0_sts_trans_a2b_prt_err_info_0_START (0)
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_0_sts_trans_a2b_prt_err_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_trans_a2b_prt_err_info_1 : 32;
    } reg;
} SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_1_UNION;
#endif
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_1_sts_trans_a2b_prt_err_info_1_START (0)
#define SOC_STS_INTR_STS_TRANS_A2B_P_ERR_INFO_1_sts_trans_a2b_prt_err_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_sta_a2b_prt_err_info : 32;
    } reg;
} SOC_STS_INTR_STS_STA_A2B_P_ERR_INFO_UNION;
#endif
#define SOC_STS_INTR_STS_STA_A2B_P_ERR_INFO_sts_sta_a2b_prt_err_info_START (0)
#define SOC_STS_INTR_STS_STA_A2B_P_ERR_INFO_sts_sta_a2b_prt_err_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rffe_read_prt_err_info : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_STS_INTR_RFFE_READ_P_ERR_INFO_UNION;
#endif
#define SOC_STS_INTR_RFFE_READ_P_ERR_INFO_rffe_read_prt_err_info_START (0)
#define SOC_STS_INTR_RFFE_READ_P_ERR_INFO_rffe_read_prt_err_info_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_trans_pri_index_0 : 3;
        unsigned int sts_trans_pri_index_1 : 3;
        unsigned int sts_trans_pri_index_2 : 3;
        unsigned int sts_trans_pri_index_3 : 3;
        unsigned int sts_trans_pri_index_4 : 3;
        unsigned int sts_trans_pri_index_5 : 3;
        unsigned int reserved : 14;
    } reg;
} SOC_STS_TRANS_PRIORITY_INDEX_UNION;
#endif
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_0_START (0)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_0_END (2)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_1_START (3)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_1_END (5)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_2_START (6)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_2_END (8)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_3_START (9)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_3_END (11)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_4_START (12)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_4_END (14)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_5_START (15)
#define SOC_STS_TRANS_PRIORITY_INDEX_sts_trans_pri_index_5_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s_b_start_clken_cnt : 10;
        unsigned int i2s_b_start_wait_cnt : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_STS_I2S_CFG2_UNION;
#endif
#define SOC_STS_I2S_CFG2_i2s_b_start_clken_cnt_START (0)
#define SOC_STS_I2S_CFG2_i2s_b_start_clken_cnt_END (9)
#define SOC_STS_I2S_CFG2_i2s_b_start_wait_cnt_START (10)
#define SOC_STS_I2S_CFG2_i2s_b_start_wait_cnt_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int usim0_oen_dly_num : 8;
        unsigned int usim1_oen_dly_num : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_STS_USIM0_OEN_DLY_UNION;
#endif
#define SOC_STS_USIM0_OEN_DLY_usim0_oen_dly_num_START (0)
#define SOC_STS_USIM0_OEN_DLY_usim0_oen_dly_num_END (7)
#define SOC_STS_USIM0_OEN_DLY_usim1_oen_dly_num_START (8)
#define SOC_STS_USIM0_OEN_DLY_usim1_oen_dly_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c0_cfg_scl_stretch_enable : 1;
        unsigned int i2c1_cfg_scl_stretch_enable : 1;
        unsigned int i2c2_cfg_scl_stretch_enable : 1;
        unsigned int i2c3_cfg_scl_stretch_enable : 1;
        unsigned int i2c4_cfg_scl_stretch_enable : 1;
        unsigned int i2c0_cfg_scl_stretch_int_only : 1;
        unsigned int i2c1_cfg_scl_stretch_int_only : 1;
        unsigned int i2c2_cfg_scl_stretch_int_only : 1;
        unsigned int i2c3_cfg_scl_stretch_int_only : 1;
        unsigned int i2c4_cfg_scl_stretch_int_only : 1;
        unsigned int reserved_0 : 6;
        unsigned int i2c0_cfg_scl_bus_clr_en : 1;
        unsigned int i2c0_cfg_scl_bus_clr_pp : 1;
        unsigned int i2c0_cfg_scl_bus_clr_value : 1;
        unsigned int i2c1_cfg_scl_bus_clr_en : 1;
        unsigned int i2c1_cfg_scl_bus_clr_pp : 1;
        unsigned int i2c1_cfg_scl_bus_clr_value : 1;
        unsigned int i2c2_cfg_scl_bus_clr_en : 1;
        unsigned int i2c2_cfg_scl_bus_clr_pp : 1;
        unsigned int i2c2_cfg_scl_bus_clr_value : 1;
        unsigned int i2c3_cfg_scl_bus_clr_en : 1;
        unsigned int i2c3_cfg_scl_bus_clr_pp : 1;
        unsigned int i2c3_cfg_scl_bus_clr_value : 1;
        unsigned int i2c4_cfg_scl_bus_clr_en : 1;
        unsigned int i2c4_cfg_scl_bus_clr_pp : 1;
        unsigned int i2c4_cfg_scl_bus_clr_value : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_STS_I2C_CFG_UNION;
#endif
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_stretch_enable_START (0)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_stretch_enable_END (0)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_stretch_enable_START (1)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_stretch_enable_END (1)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_stretch_enable_START (2)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_stretch_enable_END (2)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_stretch_enable_START (3)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_stretch_enable_END (3)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_stretch_enable_START (4)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_stretch_enable_END (4)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_stretch_int_only_START (5)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_stretch_int_only_END (5)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_stretch_int_only_START (6)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_stretch_int_only_END (6)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_stretch_int_only_START (7)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_stretch_int_only_END (7)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_stretch_int_only_START (8)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_stretch_int_only_END (8)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_stretch_int_only_START (9)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_stretch_int_only_END (9)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_bus_clr_en_START (16)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_bus_clr_en_END (16)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_bus_clr_pp_START (17)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_bus_clr_pp_END (17)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_bus_clr_value_START (18)
#define SOC_STS_I2C_CFG_i2c0_cfg_scl_bus_clr_value_END (18)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_bus_clr_en_START (19)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_bus_clr_en_END (19)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_bus_clr_pp_START (20)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_bus_clr_pp_END (20)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_bus_clr_value_START (21)
#define SOC_STS_I2C_CFG_i2c1_cfg_scl_bus_clr_value_END (21)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_bus_clr_en_START (22)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_bus_clr_en_END (22)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_bus_clr_pp_START (23)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_bus_clr_pp_END (23)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_bus_clr_value_START (24)
#define SOC_STS_I2C_CFG_i2c2_cfg_scl_bus_clr_value_END (24)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_bus_clr_en_START (25)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_bus_clr_en_END (25)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_bus_clr_pp_START (26)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_bus_clr_pp_END (26)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_bus_clr_value_START (27)
#define SOC_STS_I2C_CFG_i2c3_cfg_scl_bus_clr_value_END (27)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_bus_clr_en_START (28)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_bus_clr_en_END (28)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_bus_clr_pp_START (29)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_bus_clr_pp_END (29)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_bus_clr_value_START (30)
#define SOC_STS_I2C_CFG_i2c4_cfg_scl_bus_clr_value_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c0_cfg_scl_low_num : 16;
        unsigned int i2c0_cfg_pos_dly_num : 16;
    } reg;
} SOC_STS_I2C0_CFG_UNION;
#endif
#define SOC_STS_I2C0_CFG_i2c0_cfg_scl_low_num_START (0)
#define SOC_STS_I2C0_CFG_i2c0_cfg_scl_low_num_END (15)
#define SOC_STS_I2C0_CFG_i2c0_cfg_pos_dly_num_START (16)
#define SOC_STS_I2C0_CFG_i2c0_cfg_pos_dly_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c1_cfg_scl_low_num : 16;
        unsigned int i2c1_cfg_pos_dly_num : 16;
    } reg;
} SOC_STS_I2C1_CFG_UNION;
#endif
#define SOC_STS_I2C1_CFG_i2c1_cfg_scl_low_num_START (0)
#define SOC_STS_I2C1_CFG_i2c1_cfg_scl_low_num_END (15)
#define SOC_STS_I2C1_CFG_i2c1_cfg_pos_dly_num_START (16)
#define SOC_STS_I2C1_CFG_i2c1_cfg_pos_dly_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c2_cfg_scl_low_num : 16;
        unsigned int i2c2_cfg_pos_dly_num : 16;
    } reg;
} SOC_STS_I2C2_CFG_UNION;
#endif
#define SOC_STS_I2C2_CFG_i2c2_cfg_scl_low_num_START (0)
#define SOC_STS_I2C2_CFG_i2c2_cfg_scl_low_num_END (15)
#define SOC_STS_I2C2_CFG_i2c2_cfg_pos_dly_num_START (16)
#define SOC_STS_I2C2_CFG_i2c2_cfg_pos_dly_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c3_cfg_scl_low_num : 16;
        unsigned int i2c3_cfg_pos_dly_num : 16;
    } reg;
} SOC_STS_I2C3_CFG_UNION;
#endif
#define SOC_STS_I2C3_CFG_i2c3_cfg_scl_low_num_START (0)
#define SOC_STS_I2C3_CFG_i2c3_cfg_scl_low_num_END (15)
#define SOC_STS_I2C3_CFG_i2c3_cfg_pos_dly_num_START (16)
#define SOC_STS_I2C3_CFG_i2c3_cfg_pos_dly_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c4_cfg_scl_low_num : 16;
        unsigned int i2c4_cfg_pos_dly_num : 16;
    } reg;
} SOC_STS_I2C4_CFG_UNION;
#endif
#define SOC_STS_I2C4_CFG_i2c4_cfg_scl_low_num_START (0)
#define SOC_STS_I2C4_CFG_i2c4_cfg_scl_low_num_END (15)
#define SOC_STS_I2C4_CFG_i2c4_cfg_pos_dly_num_START (16)
#define SOC_STS_I2C4_CFG_i2c4_cfg_pos_dly_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c0_scl_debounce_out : 8;
        unsigned int i2c0_scl_debounce_in : 8;
        unsigned int i2c0_sda_debounce_out : 8;
        unsigned int i2c0_sda_debounce_in : 8;
    } reg;
} SOC_STS_I2C0_DBC_CFG_UNION;
#endif
#define SOC_STS_I2C0_DBC_CFG_i2c0_scl_debounce_out_START (0)
#define SOC_STS_I2C0_DBC_CFG_i2c0_scl_debounce_out_END (7)
#define SOC_STS_I2C0_DBC_CFG_i2c0_scl_debounce_in_START (8)
#define SOC_STS_I2C0_DBC_CFG_i2c0_scl_debounce_in_END (15)
#define SOC_STS_I2C0_DBC_CFG_i2c0_sda_debounce_out_START (16)
#define SOC_STS_I2C0_DBC_CFG_i2c0_sda_debounce_out_END (23)
#define SOC_STS_I2C0_DBC_CFG_i2c0_sda_debounce_in_START (24)
#define SOC_STS_I2C0_DBC_CFG_i2c0_sda_debounce_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c1_scl_debounce_out : 8;
        unsigned int i2c1_scl_debounce_in : 8;
        unsigned int i2c1_sda_debounce_out : 8;
        unsigned int i2c1_sda_debounce_in : 8;
    } reg;
} SOC_STS_I2C1_DBC_CFG_UNION;
#endif
#define SOC_STS_I2C1_DBC_CFG_i2c1_scl_debounce_out_START (0)
#define SOC_STS_I2C1_DBC_CFG_i2c1_scl_debounce_out_END (7)
#define SOC_STS_I2C1_DBC_CFG_i2c1_scl_debounce_in_START (8)
#define SOC_STS_I2C1_DBC_CFG_i2c1_scl_debounce_in_END (15)
#define SOC_STS_I2C1_DBC_CFG_i2c1_sda_debounce_out_START (16)
#define SOC_STS_I2C1_DBC_CFG_i2c1_sda_debounce_out_END (23)
#define SOC_STS_I2C1_DBC_CFG_i2c1_sda_debounce_in_START (24)
#define SOC_STS_I2C1_DBC_CFG_i2c1_sda_debounce_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c2_scl_debounce_out : 8;
        unsigned int i2c2_scl_debounce_in : 8;
        unsigned int i2c2_sda_debounce_out : 8;
        unsigned int i2c2_sda_debounce_in : 8;
    } reg;
} SOC_STS_I2C2_DBC_CFG_UNION;
#endif
#define SOC_STS_I2C2_DBC_CFG_i2c2_scl_debounce_out_START (0)
#define SOC_STS_I2C2_DBC_CFG_i2c2_scl_debounce_out_END (7)
#define SOC_STS_I2C2_DBC_CFG_i2c2_scl_debounce_in_START (8)
#define SOC_STS_I2C2_DBC_CFG_i2c2_scl_debounce_in_END (15)
#define SOC_STS_I2C2_DBC_CFG_i2c2_sda_debounce_out_START (16)
#define SOC_STS_I2C2_DBC_CFG_i2c2_sda_debounce_out_END (23)
#define SOC_STS_I2C2_DBC_CFG_i2c2_sda_debounce_in_START (24)
#define SOC_STS_I2C2_DBC_CFG_i2c2_sda_debounce_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c3_scl_debounce_out : 8;
        unsigned int i2c3_scl_debounce_in : 8;
        unsigned int i2c3_sda_debounce_out : 8;
        unsigned int i2c3_sda_debounce_in : 8;
    } reg;
} SOC_STS_I2C3_DBC_CFG_UNION;
#endif
#define SOC_STS_I2C3_DBC_CFG_i2c3_scl_debounce_out_START (0)
#define SOC_STS_I2C3_DBC_CFG_i2c3_scl_debounce_out_END (7)
#define SOC_STS_I2C3_DBC_CFG_i2c3_scl_debounce_in_START (8)
#define SOC_STS_I2C3_DBC_CFG_i2c3_scl_debounce_in_END (15)
#define SOC_STS_I2C3_DBC_CFG_i2c3_sda_debounce_out_START (16)
#define SOC_STS_I2C3_DBC_CFG_i2c3_sda_debounce_out_END (23)
#define SOC_STS_I2C3_DBC_CFG_i2c3_sda_debounce_in_START (24)
#define SOC_STS_I2C3_DBC_CFG_i2c3_sda_debounce_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c4_scl_debounce_out : 8;
        unsigned int i2c4_scl_debounce_in : 8;
        unsigned int i2c4_sda_debounce_out : 8;
        unsigned int i2c4_sda_debounce_in : 8;
    } reg;
} SOC_STS_I2C4_DBC_CFG_UNION;
#endif
#define SOC_STS_I2C4_DBC_CFG_i2c4_scl_debounce_out_START (0)
#define SOC_STS_I2C4_DBC_CFG_i2c4_scl_debounce_out_END (7)
#define SOC_STS_I2C4_DBC_CFG_i2c4_scl_debounce_in_START (8)
#define SOC_STS_I2C4_DBC_CFG_i2c4_scl_debounce_in_END (15)
#define SOC_STS_I2C4_DBC_CFG_i2c4_sda_debounce_out_START (16)
#define SOC_STS_I2C4_DBC_CFG_i2c4_sda_debounce_out_END (23)
#define SOC_STS_I2C4_DBC_CFG_i2c4_sda_debounce_in_START (24)
#define SOC_STS_I2C4_DBC_CFG_i2c4_sda_debounce_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c0_b2a_en_hold_dly : 16;
        unsigned int i2c1_b2a_en_hold_dly : 16;
    } reg;
} SOC_STS_I2C_B2A_HOLD_CFG0_UNION;
#endif
#define SOC_STS_I2C_B2A_HOLD_CFG0_i2c0_b2a_en_hold_dly_START (0)
#define SOC_STS_I2C_B2A_HOLD_CFG0_i2c0_b2a_en_hold_dly_END (15)
#define SOC_STS_I2C_B2A_HOLD_CFG0_i2c1_b2a_en_hold_dly_START (16)
#define SOC_STS_I2C_B2A_HOLD_CFG0_i2c1_b2a_en_hold_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c2_b2a_en_hold_dly : 16;
        unsigned int i2c3_b2a_en_hold_dly : 16;
    } reg;
} SOC_STS_I2C_B2A_HOLD_CFG1_UNION;
#endif
#define SOC_STS_I2C_B2A_HOLD_CFG1_i2c2_b2a_en_hold_dly_START (0)
#define SOC_STS_I2C_B2A_HOLD_CFG1_i2c2_b2a_en_hold_dly_END (15)
#define SOC_STS_I2C_B2A_HOLD_CFG1_i2c3_b2a_en_hold_dly_START (16)
#define SOC_STS_I2C_B2A_HOLD_CFG1_i2c3_b2a_en_hold_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c4_b2a_en_hold_dly : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_STS_I2C_B2A_HOLD_CFG2_UNION;
#endif
#define SOC_STS_I2C_B2A_HOLD_CFG2_i2c4_b2a_en_hold_dly_START (0)
#define SOC_STS_I2C_B2A_HOLD_CFG2_i2c4_b2a_en_hold_dly_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c0_scl_match_dly : 8;
        unsigned int i2c1_scl_match_dly : 8;
        unsigned int i2c2_scl_match_dly : 8;
        unsigned int i2c3_scl_match_dly : 8;
    } reg;
} SOC_STS_I2C_DLYCFG0_UNION;
#endif
#define SOC_STS_I2C_DLYCFG0_i2c0_scl_match_dly_START (0)
#define SOC_STS_I2C_DLYCFG0_i2c0_scl_match_dly_END (7)
#define SOC_STS_I2C_DLYCFG0_i2c1_scl_match_dly_START (8)
#define SOC_STS_I2C_DLYCFG0_i2c1_scl_match_dly_END (15)
#define SOC_STS_I2C_DLYCFG0_i2c2_scl_match_dly_START (16)
#define SOC_STS_I2C_DLYCFG0_i2c2_scl_match_dly_END (23)
#define SOC_STS_I2C_DLYCFG0_i2c3_scl_match_dly_START (24)
#define SOC_STS_I2C_DLYCFG0_i2c3_scl_match_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c4_scl_match_dly : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_STS_I2C_DLYCFG1_UNION;
#endif
#define SOC_STS_I2C_DLYCFG1_i2c4_scl_match_dly_START (0)
#define SOC_STS_I2C_DLYCFG1_i2c4_scl_match_dly_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_spi0_b : 1;
        unsigned int st_clk_spi1_b : 1;
        unsigned int st_clk_i2s_b : 1;
        unsigned int st_clk_rffe_b : 1;
        unsigned int st_clk_rffe_ssc_a : 1;
        unsigned int st_clk_sts_a : 1;
        unsigned int st_clk_sts_b : 1;
        unsigned int st_clk_sts_i2c0_a : 1;
        unsigned int st_clk_sts_i2c0_b : 1;
        unsigned int st_clk_sts_i2c1_a : 1;
        unsigned int st_clk_sts_i2c1_b : 1;
        unsigned int st_clk_sts_i2c2_a : 1;
        unsigned int st_clk_sts_i2c2_b : 1;
        unsigned int st_clk_sts_i2c3_a : 1;
        unsigned int st_clk_sts_i2c3_b : 1;
        unsigned int st_clk_sts_i2c4_a : 1;
        unsigned int st_clk_sts_i2c4_b : 1;
        unsigned int st_clk_sts_i2s_a : 1;
        unsigned int st_clk_sts_i2s_b : 1;
        unsigned int st_clk_sts_spi0_a : 1;
        unsigned int st_clk_sts_spi0_b : 1;
        unsigned int st_clk_sts_spi1_a : 1;
        unsigned int st_clk_sts_spi1_b : 1;
        unsigned int st_clk_sts_rffe_a : 1;
        unsigned int st_clk_sts_rffe_b : 1;
        unsigned int st_clk_sts_usim0_a : 1;
        unsigned int st_clk_sts_usim0_b : 1;
        unsigned int st_clk_sts_usim1_a : 1;
        unsigned int st_clk_sts_usim1_b : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_STS_CLK_GATE_STAT_UNION;
#endif
#define SOC_STS_CLK_GATE_STAT_st_clk_spi0_b_START (0)
#define SOC_STS_CLK_GATE_STAT_st_clk_spi0_b_END (0)
#define SOC_STS_CLK_GATE_STAT_st_clk_spi1_b_START (1)
#define SOC_STS_CLK_GATE_STAT_st_clk_spi1_b_END (1)
#define SOC_STS_CLK_GATE_STAT_st_clk_i2s_b_START (2)
#define SOC_STS_CLK_GATE_STAT_st_clk_i2s_b_END (2)
#define SOC_STS_CLK_GATE_STAT_st_clk_rffe_b_START (3)
#define SOC_STS_CLK_GATE_STAT_st_clk_rffe_b_END (3)
#define SOC_STS_CLK_GATE_STAT_st_clk_rffe_ssc_a_START (4)
#define SOC_STS_CLK_GATE_STAT_st_clk_rffe_ssc_a_END (4)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_a_START (5)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_a_END (5)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_b_START (6)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_b_END (6)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c0_a_START (7)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c0_a_END (7)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c0_b_START (8)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c0_b_END (8)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c1_a_START (9)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c1_a_END (9)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c1_b_START (10)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c1_b_END (10)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c2_a_START (11)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c2_a_END (11)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c2_b_START (12)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c2_b_END (12)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c3_a_START (13)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c3_a_END (13)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c3_b_START (14)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c3_b_END (14)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c4_a_START (15)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c4_a_END (15)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c4_b_START (16)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2c4_b_END (16)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2s_a_START (17)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2s_a_END (17)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2s_b_START (18)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_i2s_b_END (18)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi0_a_START (19)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi0_a_END (19)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi0_b_START (20)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi0_b_END (20)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi1_a_START (21)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi1_a_END (21)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi1_b_START (22)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_spi1_b_END (22)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_rffe_a_START (23)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_rffe_a_END (23)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_rffe_b_START (24)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_rffe_b_END (24)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim0_a_START (25)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim0_a_END (25)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim0_b_START (26)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim0_b_END (26)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim1_a_START (27)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim1_a_END (27)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim1_b_START (28)
#define SOC_STS_CLK_GATE_STAT_st_clk_sts_usim1_b_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_reset_a_spi0 : 1;
        unsigned int soft_reset_a_spi1 : 1;
        unsigned int soft_reset_a_rffe : 1;
        unsigned int soft_reset_a_i2s : 1;
        unsigned int soft_reset_a_i2c0 : 1;
        unsigned int soft_reset_a_i2c1 : 1;
        unsigned int soft_reset_a_i2c2 : 1;
        unsigned int soft_reset_a_i2c3 : 1;
        unsigned int soft_reset_a_i2c4 : 1;
        unsigned int soft_reset_a_usim0 : 1;
        unsigned int soft_reset_a_usim1 : 1;
        unsigned int soft_reset_a_sts_packet_send : 1;
        unsigned int soft_reset_a_sts_stat_send : 1;
        unsigned int soft_reset_a_sts_packet_receive : 1;
        unsigned int soft_reset_a_sts_stat_receive : 1;
        unsigned int reserved_0 : 1;
        unsigned int soft_reset_b_spi0 : 1;
        unsigned int soft_reset_b_spi1 : 1;
        unsigned int soft_reset_b_rffe : 1;
        unsigned int soft_reset_b_i2s : 1;
        unsigned int soft_reset_b_i2c0 : 1;
        unsigned int soft_reset_b_i2c1 : 1;
        unsigned int soft_reset_b_i2c2 : 1;
        unsigned int soft_reset_b_i2c3 : 1;
        unsigned int soft_reset_b_i2c4 : 1;
        unsigned int soft_reset_b_usim0 : 1;
        unsigned int soft_reset_b_usim1 : 1;
        unsigned int soft_reset_b_sts_packet_send : 1;
        unsigned int soft_reset_b_sts_stat_send : 1;
        unsigned int soft_reset_b_sts_packet_receive : 1;
        unsigned int soft_reset_b_sts_stat_receive : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_STS_SOFTWARE_RESET_UNION;
#endif
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_spi0_START (0)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_spi0_END (0)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_spi1_START (1)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_spi1_END (1)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_rffe_START (2)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_rffe_END (2)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2s_START (3)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2s_END (3)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c0_START (4)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c0_END (4)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c1_START (5)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c1_END (5)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c2_START (6)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c2_END (6)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c3_START (7)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c3_END (7)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c4_START (8)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_i2c4_END (8)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_usim0_START (9)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_usim0_END (9)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_usim1_START (10)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_usim1_END (10)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_packet_send_START (11)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_packet_send_END (11)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_stat_send_START (12)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_stat_send_END (12)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_packet_receive_START (13)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_packet_receive_END (13)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_stat_receive_START (14)
#define SOC_STS_SOFTWARE_RESET_soft_reset_a_sts_stat_receive_END (14)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_spi0_START (16)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_spi0_END (16)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_spi1_START (17)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_spi1_END (17)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_rffe_START (18)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_rffe_END (18)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2s_START (19)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2s_END (19)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c0_START (20)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c0_END (20)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c1_START (21)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c1_END (21)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c2_START (22)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c2_END (22)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c3_START (23)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c3_END (23)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c4_START (24)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_i2c4_END (24)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_usim0_START (25)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_usim0_END (25)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_usim1_START (26)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_usim1_END (26)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_packet_send_START (27)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_packet_send_END (27)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_stat_send_START (28)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_stat_send_END (28)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_packet_receive_START (29)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_packet_receive_END (29)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_stat_receive_START (30)
#define SOC_STS_SOFTWARE_RESET_soft_reset_b_sts_stat_receive_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_clk_switch_spi0 : 1;
        unsigned int soft_clk_switch_spi1 : 1;
        unsigned int soft_clk_switch_rffe : 1;
        unsigned int soft_clk_switch_i2s : 1;
        unsigned int sts_idle_cnt_num : 10;
        unsigned int sts_idle : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_UNION;
#endif
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_spi0_START (0)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_spi0_END (0)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_spi1_START (1)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_spi1_END (1)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_rffe_START (2)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_rffe_END (2)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_i2s_START (3)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_soft_clk_switch_i2s_END (3)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_sts_idle_cnt_num_START (4)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_sts_idle_cnt_num_END (13)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_sts_idle_START (14)
#define SOC_STS_SOFTWARE_CLK_SWITCH_IDLE_CFG_sts_idle_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_sta_dec_fsm_idle_b2a : 1;
        unsigned int sts_sta_gen_fsm_idle_a2b : 1;
        unsigned int sts_trans_dec_fsm_idle_b2a : 1;
        unsigned int sts_trans_gen_fsm_idle_a2b : 1;
        unsigned int sts_clk_gate_idle_a2b : 1;
        unsigned int usim0_a_clk_state_idle : 1;
        unsigned int usim1_a_clk_state_idle : 1;
        unsigned int i2c4_a_ctrl_fsm_idle : 1;
        unsigned int i2c3_a_ctrl_fsm_idle : 1;
        unsigned int i2c2_a_ctrl_fsm_idle : 1;
        unsigned int i2c1_a_ctrl_fsm_idle : 1;
        unsigned int i2c0_a_ctrl_fsm_idle : 1;
        unsigned int spi1_ctrl_gen_a_fsm_idle : 1;
        unsigned int spi1_frame_a2b_afifo_empty : 1;
        unsigned int spi1_intf_a2b_afifo_empty : 1;
        unsigned int spi0_ctrl_gen_a_fsm_idle : 1;
        unsigned int spi0_frame_a2b_afifo_empty : 1;
        unsigned int spi0_intf_a2b_afifo_empty : 1;
        unsigned int rffe_ctrl_intf_a_fsm_idle : 1;
        unsigned int rffe_frame_a2b_afifo_empty : 1;
        unsigned int i2s_ctrl_gen_a_fsm_idle : 1;
        unsigned int i2s_frame_a2b_afifo_empty : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_STS_ASIDE_IDLE_UNION;
#endif
#define SOC_STS_ASIDE_IDLE_sts_sta_dec_fsm_idle_b2a_START (0)
#define SOC_STS_ASIDE_IDLE_sts_sta_dec_fsm_idle_b2a_END (0)
#define SOC_STS_ASIDE_IDLE_sts_sta_gen_fsm_idle_a2b_START (1)
#define SOC_STS_ASIDE_IDLE_sts_sta_gen_fsm_idle_a2b_END (1)
#define SOC_STS_ASIDE_IDLE_sts_trans_dec_fsm_idle_b2a_START (2)
#define SOC_STS_ASIDE_IDLE_sts_trans_dec_fsm_idle_b2a_END (2)
#define SOC_STS_ASIDE_IDLE_sts_trans_gen_fsm_idle_a2b_START (3)
#define SOC_STS_ASIDE_IDLE_sts_trans_gen_fsm_idle_a2b_END (3)
#define SOC_STS_ASIDE_IDLE_sts_clk_gate_idle_a2b_START (4)
#define SOC_STS_ASIDE_IDLE_sts_clk_gate_idle_a2b_END (4)
#define SOC_STS_ASIDE_IDLE_usim0_a_clk_state_idle_START (5)
#define SOC_STS_ASIDE_IDLE_usim0_a_clk_state_idle_END (5)
#define SOC_STS_ASIDE_IDLE_usim1_a_clk_state_idle_START (6)
#define SOC_STS_ASIDE_IDLE_usim1_a_clk_state_idle_END (6)
#define SOC_STS_ASIDE_IDLE_i2c4_a_ctrl_fsm_idle_START (7)
#define SOC_STS_ASIDE_IDLE_i2c4_a_ctrl_fsm_idle_END (7)
#define SOC_STS_ASIDE_IDLE_i2c3_a_ctrl_fsm_idle_START (8)
#define SOC_STS_ASIDE_IDLE_i2c3_a_ctrl_fsm_idle_END (8)
#define SOC_STS_ASIDE_IDLE_i2c2_a_ctrl_fsm_idle_START (9)
#define SOC_STS_ASIDE_IDLE_i2c2_a_ctrl_fsm_idle_END (9)
#define SOC_STS_ASIDE_IDLE_i2c1_a_ctrl_fsm_idle_START (10)
#define SOC_STS_ASIDE_IDLE_i2c1_a_ctrl_fsm_idle_END (10)
#define SOC_STS_ASIDE_IDLE_i2c0_a_ctrl_fsm_idle_START (11)
#define SOC_STS_ASIDE_IDLE_i2c0_a_ctrl_fsm_idle_END (11)
#define SOC_STS_ASIDE_IDLE_spi1_ctrl_gen_a_fsm_idle_START (12)
#define SOC_STS_ASIDE_IDLE_spi1_ctrl_gen_a_fsm_idle_END (12)
#define SOC_STS_ASIDE_IDLE_spi1_frame_a2b_afifo_empty_START (13)
#define SOC_STS_ASIDE_IDLE_spi1_frame_a2b_afifo_empty_END (13)
#define SOC_STS_ASIDE_IDLE_spi1_intf_a2b_afifo_empty_START (14)
#define SOC_STS_ASIDE_IDLE_spi1_intf_a2b_afifo_empty_END (14)
#define SOC_STS_ASIDE_IDLE_spi0_ctrl_gen_a_fsm_idle_START (15)
#define SOC_STS_ASIDE_IDLE_spi0_ctrl_gen_a_fsm_idle_END (15)
#define SOC_STS_ASIDE_IDLE_spi0_frame_a2b_afifo_empty_START (16)
#define SOC_STS_ASIDE_IDLE_spi0_frame_a2b_afifo_empty_END (16)
#define SOC_STS_ASIDE_IDLE_spi0_intf_a2b_afifo_empty_START (17)
#define SOC_STS_ASIDE_IDLE_spi0_intf_a2b_afifo_empty_END (17)
#define SOC_STS_ASIDE_IDLE_rffe_ctrl_intf_a_fsm_idle_START (18)
#define SOC_STS_ASIDE_IDLE_rffe_ctrl_intf_a_fsm_idle_END (18)
#define SOC_STS_ASIDE_IDLE_rffe_frame_a2b_afifo_empty_START (19)
#define SOC_STS_ASIDE_IDLE_rffe_frame_a2b_afifo_empty_END (19)
#define SOC_STS_ASIDE_IDLE_i2s_ctrl_gen_a_fsm_idle_START (20)
#define SOC_STS_ASIDE_IDLE_i2s_ctrl_gen_a_fsm_idle_END (20)
#define SOC_STS_ASIDE_IDLE_i2s_frame_a2b_afifo_empty_START (21)
#define SOC_STS_ASIDE_IDLE_i2s_frame_a2b_afifo_empty_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_sta_dec_fsm_idle_a2b : 1;
        unsigned int sts_sta_gen_fsm_idle_b2a : 1;
        unsigned int sts_trans_dec_fsm_idle_a2b : 1;
        unsigned int sts_trans_gen_fsm_idle_b2a : 1;
        unsigned int sts_clk_gate_idle_b2a : 1;
        unsigned int usim0_b_clk_state_idle : 1;
        unsigned int usim1_b_clk_state_idle : 1;
        unsigned int i2c4_b_ctrl_fsm_idle : 1;
        unsigned int i2c3_b_ctrl_fsm_idle : 1;
        unsigned int i2c2_b_ctrl_fsm_idle : 1;
        unsigned int i2c1_b_ctrl_fsm_idle : 1;
        unsigned int i2c0_b_ctrl_fsm_idle : 1;
        unsigned int spi1_ctrl_intf_b_fsm_idle : 1;
        unsigned int spi1_frame_b2a_bfifo_empty : 1;
        unsigned int spi1_frame_a2b_bfifo_empty : 1;
        unsigned int spi0_ctrl_intf_b_fsm_idle : 1;
        unsigned int spi0_frame_b2a_bfifo_empty : 1;
        unsigned int spi0_frame_a2b_bfifo_empty : 1;
        unsigned int rffe_ctrl_intf_b_fsm_idle : 1;
        unsigned int rffe_frame_b2a_bfifo_empty : 1;
        unsigned int rffe_frame_a2b_bfifo_empty : 1;
        unsigned int i2s_ctrl_intf_b_fsm_idle : 1;
        unsigned int i2s_frame_b2a_bfifo_empty : 1;
        unsigned int i2s_frame_a2b_bfifo_empty : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_STS_BSIDE_IDLE_UNION;
#endif
#define SOC_STS_BSIDE_IDLE_sts_sta_dec_fsm_idle_a2b_START (0)
#define SOC_STS_BSIDE_IDLE_sts_sta_dec_fsm_idle_a2b_END (0)
#define SOC_STS_BSIDE_IDLE_sts_sta_gen_fsm_idle_b2a_START (1)
#define SOC_STS_BSIDE_IDLE_sts_sta_gen_fsm_idle_b2a_END (1)
#define SOC_STS_BSIDE_IDLE_sts_trans_dec_fsm_idle_a2b_START (2)
#define SOC_STS_BSIDE_IDLE_sts_trans_dec_fsm_idle_a2b_END (2)
#define SOC_STS_BSIDE_IDLE_sts_trans_gen_fsm_idle_b2a_START (3)
#define SOC_STS_BSIDE_IDLE_sts_trans_gen_fsm_idle_b2a_END (3)
#define SOC_STS_BSIDE_IDLE_sts_clk_gate_idle_b2a_START (4)
#define SOC_STS_BSIDE_IDLE_sts_clk_gate_idle_b2a_END (4)
#define SOC_STS_BSIDE_IDLE_usim0_b_clk_state_idle_START (5)
#define SOC_STS_BSIDE_IDLE_usim0_b_clk_state_idle_END (5)
#define SOC_STS_BSIDE_IDLE_usim1_b_clk_state_idle_START (6)
#define SOC_STS_BSIDE_IDLE_usim1_b_clk_state_idle_END (6)
#define SOC_STS_BSIDE_IDLE_i2c4_b_ctrl_fsm_idle_START (7)
#define SOC_STS_BSIDE_IDLE_i2c4_b_ctrl_fsm_idle_END (7)
#define SOC_STS_BSIDE_IDLE_i2c3_b_ctrl_fsm_idle_START (8)
#define SOC_STS_BSIDE_IDLE_i2c3_b_ctrl_fsm_idle_END (8)
#define SOC_STS_BSIDE_IDLE_i2c2_b_ctrl_fsm_idle_START (9)
#define SOC_STS_BSIDE_IDLE_i2c2_b_ctrl_fsm_idle_END (9)
#define SOC_STS_BSIDE_IDLE_i2c1_b_ctrl_fsm_idle_START (10)
#define SOC_STS_BSIDE_IDLE_i2c1_b_ctrl_fsm_idle_END (10)
#define SOC_STS_BSIDE_IDLE_i2c0_b_ctrl_fsm_idle_START (11)
#define SOC_STS_BSIDE_IDLE_i2c0_b_ctrl_fsm_idle_END (11)
#define SOC_STS_BSIDE_IDLE_spi1_ctrl_intf_b_fsm_idle_START (12)
#define SOC_STS_BSIDE_IDLE_spi1_ctrl_intf_b_fsm_idle_END (12)
#define SOC_STS_BSIDE_IDLE_spi1_frame_b2a_bfifo_empty_START (13)
#define SOC_STS_BSIDE_IDLE_spi1_frame_b2a_bfifo_empty_END (13)
#define SOC_STS_BSIDE_IDLE_spi1_frame_a2b_bfifo_empty_START (14)
#define SOC_STS_BSIDE_IDLE_spi1_frame_a2b_bfifo_empty_END (14)
#define SOC_STS_BSIDE_IDLE_spi0_ctrl_intf_b_fsm_idle_START (15)
#define SOC_STS_BSIDE_IDLE_spi0_ctrl_intf_b_fsm_idle_END (15)
#define SOC_STS_BSIDE_IDLE_spi0_frame_b2a_bfifo_empty_START (16)
#define SOC_STS_BSIDE_IDLE_spi0_frame_b2a_bfifo_empty_END (16)
#define SOC_STS_BSIDE_IDLE_spi0_frame_a2b_bfifo_empty_START (17)
#define SOC_STS_BSIDE_IDLE_spi0_frame_a2b_bfifo_empty_END (17)
#define SOC_STS_BSIDE_IDLE_rffe_ctrl_intf_b_fsm_idle_START (18)
#define SOC_STS_BSIDE_IDLE_rffe_ctrl_intf_b_fsm_idle_END (18)
#define SOC_STS_BSIDE_IDLE_rffe_frame_b2a_bfifo_empty_START (19)
#define SOC_STS_BSIDE_IDLE_rffe_frame_b2a_bfifo_empty_END (19)
#define SOC_STS_BSIDE_IDLE_rffe_frame_a2b_bfifo_empty_START (20)
#define SOC_STS_BSIDE_IDLE_rffe_frame_a2b_bfifo_empty_END (20)
#define SOC_STS_BSIDE_IDLE_i2s_ctrl_intf_b_fsm_idle_START (21)
#define SOC_STS_BSIDE_IDLE_i2s_ctrl_intf_b_fsm_idle_END (21)
#define SOC_STS_BSIDE_IDLE_i2s_frame_b2a_bfifo_empty_START (22)
#define SOC_STS_BSIDE_IDLE_i2s_frame_b2a_bfifo_empty_END (22)
#define SOC_STS_BSIDE_IDLE_i2s_frame_a2b_bfifo_empty_START (23)
#define SOC_STS_BSIDE_IDLE_i2s_frame_a2b_bfifo_empty_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_point_sel : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_STS_TP_SEL_UNION;
#endif
#define SOC_STS_TP_SEL_test_point_sel_START (0)
#define SOC_STS_TP_SEL_test_point_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl0 : 32;
    } reg;
} SOC_STS_RSV_CTRL0_UNION;
#endif
#define SOC_STS_RSV_CTRL0_sts_reserved_ctrl0_START (0)
#define SOC_STS_RSV_CTRL0_sts_reserved_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl1 : 32;
    } reg;
} SOC_STS_RSV_CTRL1_UNION;
#endif
#define SOC_STS_RSV_CTRL1_sts_reserved_ctrl1_START (0)
#define SOC_STS_RSV_CTRL1_sts_reserved_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl2 : 32;
    } reg;
} SOC_STS_RSV_CTRL2_UNION;
#endif
#define SOC_STS_RSV_CTRL2_sts_reserved_ctrl2_START (0)
#define SOC_STS_RSV_CTRL2_sts_reserved_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_ctrl3 : 32;
    } reg;
} SOC_STS_RSV_CTRL3_UNION;
#endif
#define SOC_STS_RSV_CTRL3_sts_reserved_ctrl3_START (0)
#define SOC_STS_RSV_CTRL3_sts_reserved_ctrl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_stat0 : 32;
    } reg;
} SOC_STS_RSV_STAT0_UNION;
#endif
#define SOC_STS_RSV_STAT0_sts_reserved_stat0_START (0)
#define SOC_STS_RSV_STAT0_sts_reserved_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_stat1 : 32;
    } reg;
} SOC_STS_RSV_STAT1_UNION;
#endif
#define SOC_STS_RSV_STAT1_sts_reserved_stat1_START (0)
#define SOC_STS_RSV_STAT1_sts_reserved_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_stat2 : 32;
    } reg;
} SOC_STS_RSV_STAT2_UNION;
#endif
#define SOC_STS_RSV_STAT2_sts_reserved_stat2_START (0)
#define SOC_STS_RSV_STAT2_sts_reserved_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sts_reserved_stat3 : 32;
    } reg;
} SOC_STS_RSV_STAT3_UNION;
#endif
#define SOC_STS_RSV_STAT3_sts_reserved_stat3_START (0)
#define SOC_STS_RSV_STAT3_sts_reserved_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi0_a : 32;
    } reg;
} SOC_STS_DFX_SPI0_A_UNION;
#endif
#define SOC_STS_DFX_SPI0_A_dfx_spi0_a_START (0)
#define SOC_STS_DFX_SPI0_A_dfx_spi0_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi1_a : 32;
    } reg;
} SOC_STS_DFX_SPI1_A_UNION;
#endif
#define SOC_STS_DFX_SPI1_A_dfx_spi1_a_START (0)
#define SOC_STS_DFX_SPI1_A_dfx_spi1_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi0_b : 32;
    } reg;
} SOC_STS_DFX_SPI0_B_UNION;
#endif
#define SOC_STS_DFX_SPI0_B_dfx_spi0_b_START (0)
#define SOC_STS_DFX_SPI0_B_dfx_spi0_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_spi1_b : 32;
    } reg;
} SOC_STS_DFX_SPI1_B_UNION;
#endif
#define SOC_STS_DFX_SPI1_B_dfx_spi1_b_START (0)
#define SOC_STS_DFX_SPI1_B_dfx_spi1_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rffe_a : 32;
    } reg;
} SOC_STS_DFX_RFFE_A_UNION;
#endif
#define SOC_STS_DFX_RFFE_A_dfx_rffe_a_START (0)
#define SOC_STS_DFX_RFFE_A_dfx_rffe_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rffe_b : 32;
    } reg;
} SOC_STS_DFX_RFFE_B_UNION;
#endif
#define SOC_STS_DFX_RFFE_B_dfx_rffe_b_START (0)
#define SOC_STS_DFX_RFFE_B_dfx_rffe_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2s_a_gen : 16;
        unsigned int dfx_i2s_a_intf : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_STS_DFX_I2SA_UNION;
#endif
#define SOC_STS_DFX_I2SA_dfx_i2s_a_gen_START (0)
#define SOC_STS_DFX_I2SA_dfx_i2s_a_gen_END (15)
#define SOC_STS_DFX_I2SA_dfx_i2s_a_intf_START (16)
#define SOC_STS_DFX_I2SA_dfx_i2s_a_intf_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2s_b : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_STS_DFX_I2SB_UNION;
#endif
#define SOC_STS_DFX_I2SB_dfx_i2s_b_START (0)
#define SOC_STS_DFX_I2SB_dfx_i2s_b_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2c0_a : 16;
        unsigned int dfx_i2c0_b : 16;
    } reg;
} SOC_STS_DFX_I2C0_UNION;
#endif
#define SOC_STS_DFX_I2C0_dfx_i2c0_a_START (0)
#define SOC_STS_DFX_I2C0_dfx_i2c0_a_END (15)
#define SOC_STS_DFX_I2C0_dfx_i2c0_b_START (16)
#define SOC_STS_DFX_I2C0_dfx_i2c0_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2c1_a : 16;
        unsigned int dfx_i2c1_b : 16;
    } reg;
} SOC_STS_DFX_I2C1_UNION;
#endif
#define SOC_STS_DFX_I2C1_dfx_i2c1_a_START (0)
#define SOC_STS_DFX_I2C1_dfx_i2c1_a_END (15)
#define SOC_STS_DFX_I2C1_dfx_i2c1_b_START (16)
#define SOC_STS_DFX_I2C1_dfx_i2c1_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2c2_a : 16;
        unsigned int dfx_i2c2_b : 16;
    } reg;
} SOC_STS_DFX_I2C2_UNION;
#endif
#define SOC_STS_DFX_I2C2_dfx_i2c2_a_START (0)
#define SOC_STS_DFX_I2C2_dfx_i2c2_a_END (15)
#define SOC_STS_DFX_I2C2_dfx_i2c2_b_START (16)
#define SOC_STS_DFX_I2C2_dfx_i2c2_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2c3_a : 16;
        unsigned int dfx_i2c3_b : 16;
    } reg;
} SOC_STS_DFX_I2C3_UNION;
#endif
#define SOC_STS_DFX_I2C3_dfx_i2c3_a_START (0)
#define SOC_STS_DFX_I2C3_dfx_i2c3_a_END (15)
#define SOC_STS_DFX_I2C3_dfx_i2c3_b_START (16)
#define SOC_STS_DFX_I2C3_dfx_i2c3_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2c4_a : 16;
        unsigned int dfx_i2c4_b : 16;
    } reg;
} SOC_STS_DFX_I2C4_UNION;
#endif
#define SOC_STS_DFX_I2C4_dfx_i2c4_a_START (0)
#define SOC_STS_DFX_I2C4_dfx_i2c4_a_END (15)
#define SOC_STS_DFX_I2C4_dfx_i2c4_b_START (16)
#define SOC_STS_DFX_I2C4_dfx_i2c4_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_trans_gen_a2b : 32;
    } reg;
} SOC_STS_DFX_STS_TRANS_GEN_A2B_UNION;
#endif
#define SOC_STS_DFX_STS_TRANS_GEN_A2B_dfx_sts_trans_gen_a2b_START (0)
#define SOC_STS_DFX_STS_TRANS_GEN_A2B_dfx_sts_trans_gen_a2b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_trans_gen_b2a : 32;
    } reg;
} SOC_STS_DFX_STS_TRANS_GEN_B2A_UNION;
#endif
#define SOC_STS_DFX_STS_TRANS_GEN_B2A_dfx_sts_trans_gen_b2a_START (0)
#define SOC_STS_DFX_STS_TRANS_GEN_B2A_dfx_sts_trans_gen_b2a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_trans_dec_a2b : 32;
    } reg;
} SOC_STS_DFX_STS_TRANS_DEC_A2B_UNION;
#endif
#define SOC_STS_DFX_STS_TRANS_DEC_A2B_dfx_sts_trans_dec_a2b_START (0)
#define SOC_STS_DFX_STS_TRANS_DEC_A2B_dfx_sts_trans_dec_a2b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_trans_dec_b2a : 32;
    } reg;
} SOC_STS_DFX_STS_TRANS_DEC_B2A_UNION;
#endif
#define SOC_STS_DFX_STS_TRANS_DEC_B2A_dfx_sts_trans_dec_b2a_START (0)
#define SOC_STS_DFX_STS_TRANS_DEC_B2A_dfx_sts_trans_dec_b2a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_sta_gen_a2b : 32;
    } reg;
} SOC_STS_DFX_STS_STA_GEN_A2B_UNION;
#endif
#define SOC_STS_DFX_STS_STA_GEN_A2B_dfx_sts_sta_gen_a2b_START (0)
#define SOC_STS_DFX_STS_STA_GEN_A2B_dfx_sts_sta_gen_a2b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_sta_gen_b2a : 32;
    } reg;
} SOC_STS_DFX_STS_STA_GEN_B2A_UNION;
#endif
#define SOC_STS_DFX_STS_STA_GEN_B2A_dfx_sts_sta_gen_b2a_START (0)
#define SOC_STS_DFX_STS_STA_GEN_B2A_dfx_sts_sta_gen_b2a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_sta_dec_a2b : 32;
    } reg;
} SOC_STS_DFX_STS_STA_DEC_A2B_UNION;
#endif
#define SOC_STS_DFX_STS_STA_DEC_A2B_dfx_sts_sta_dec_a2b_START (0)
#define SOC_STS_DFX_STS_STA_DEC_A2B_dfx_sts_sta_dec_a2b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sts_sta_dec_b2a : 32;
    } reg;
} SOC_STS_DFX_STS_STA_DEC_B2A_UNION;
#endif
#define SOC_STS_DFX_STS_STA_DEC_B2A_dfx_sts_sta_dec_b2a_START (0)
#define SOC_STS_DFX_STS_STA_DEC_B2A_dfx_sts_sta_dec_b2a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_usim0_clk_a : 8;
        unsigned int dfx_usim1_clk_a : 8;
        unsigned int dfx_usim0_clk_b : 8;
        unsigned int dfx_usim1_clk_b : 8;
    } reg;
} SOC_STS_DFX_USIM_CLK_UNION;
#endif
#define SOC_STS_DFX_USIM_CLK_dfx_usim0_clk_a_START (0)
#define SOC_STS_DFX_USIM_CLK_dfx_usim0_clk_a_END (7)
#define SOC_STS_DFX_USIM_CLK_dfx_usim1_clk_a_START (8)
#define SOC_STS_DFX_USIM_CLK_dfx_usim1_clk_a_END (15)
#define SOC_STS_DFX_USIM_CLK_dfx_usim0_clk_b_START (16)
#define SOC_STS_DFX_USIM_CLK_dfx_usim0_clk_b_END (23)
#define SOC_STS_DFX_USIM_CLK_dfx_usim1_clk_b_START (24)
#define SOC_STS_DFX_USIM_CLK_dfx_usim1_clk_b_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
