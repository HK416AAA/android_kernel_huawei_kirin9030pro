#ifndef __V860_INTERFACE_H__
#define __V860_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#define V860_REG_GLB_BASE 0x0000
#define V860_REG_HKADC_BASE 0x0100
#define V860_REG_IRQ_BASE 0x0200
#define V860_REG_ANA_BASE 0x0300
#ifndef __SOC_H_FOR_ASM__
#define V860_CHIP_ID_0_ADDR(base) ((base) + (0x00UL))
#define V860_CHIP_ID_1_ADDR(base) ((base) + (0x01UL))
#define V860_CHIP_ID_2_ADDR(base) ((base) + (0x02UL))
#define V860_CHIP_ID_3_ADDR(base) ((base) + (0x03UL))
#define V860_CHIP_ID_4_ADDR(base) ((base) + (0x04UL))
#define V860_CHIP_ID_5_ADDR(base) ((base) + (0x05UL))
#define V860_GLB_SOFT_RST_CTRL_ADDR(base) ((base) + (0x06UL))
#define V860_EFUSE_SOFT_RST_CTRL_ADDR(base) ((base) + (0x07UL))
#define V860_HKADC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x08UL))
#define V860_CRG_CLK_EN_CTRL_ADDR(base) ((base) + (0x09UL))
#define V860_CRG_TESTBUS_CFG_ADDR(base) ((base) + (0x0AUL))
#define V860_CRG_TESTBUS_RDATA_ADDR(base) ((base) + (0x0BUL))
#define V860_I2C_SLV_ID_SEL_ADDR(base) ((base) + (0x0CUL))
#define V860_SC_WDT_EN_ADDR(base) ((base) + (0x10UL))
#define V860_WDT_SOFT_RST_ADDR(base) ((base) + (0x11UL))
#define V860_WDT_CTRL_ADDR(base) ((base) + (0x12UL))
#define V860_DIG_STATUS0_ADDR(base) ((base) + (0x13UL))
#define V860_DA_FBPS_EN_RO_ADDR(base) ((base) + (0x14UL))
#define V860_CHG_TB_CFG_ADDR(base) ((base) + (0x15UL))
#define V860_SC_SC_MODE_SHIELD_ADDR(base) ((base) + (0x16UL))
#define V860_DA_SC_MODE_ADDR(base) ((base) + (0x17UL))
#define V860_SYS_LOGIC_RO_REG_3_ADDR(base) ((base) + (0x18UL))
#define V860_DA_ECO_EN_ADDR(base) ((base) + (0x19UL))
#define V860_DA_OVP_EN_ADDR(base) ((base) + (0x1AUL))
#define V860_DA_DC_EN_ADDR(base) ((base) + (0x1BUL))
#define V860_DA_SC_EN_ADDR(base) ((base) + (0x1CUL))
#define V860_ECO_MODE_SHIELD_ADDR(base) ((base) + (0x1DUL))
#define V860_REG_CLK_GT_BYP_ADDR(base) ((base) + (0x1FUL))
#define V860_I2C_TB_CFG_1_ADDR(base) ((base) + (0x20UL))
#define V860_PMBUS_TB_CFG_1_ADDR(base) ((base) + (0x21UL))
#define V860_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x30UL))
#define V860_EFUSE_MODE_ADDR(base) ((base) + (0x31UL))
#define V860_EFUSE_RD_CTRL_ADDR(base) ((base) + (0x32UL))
#define V860_EFUSE_AEN_ADDR(base) ((base) + (0x33UL))
#define V860_EFUSE_PGMEN_ADDR(base) ((base) + (0x34UL))
#define V860_EFUSE_RDEN_ADDR(base) ((base) + (0x35UL))
#define V860_EFUSE_ADDR_ADDR(base) ((base) + (0x36UL))
#define V860_EFUSE_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x37UL))
#define V860_EFUSE_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x38UL))
#define V860_EFUSE_STATUS_ADDR(base) ((base) + (0x39UL))
#define V860_EFUSE_FSM_RESET_ADDR(base) ((base) + (0x3AUL))
#define V860_EFUSE_TESTBUS_CFG_ADDR(base) ((base) + (0x3BUL))
#define V860_EFUSE_TESTBUS_RDATA_ADDR(base) ((base) + (0x3CUL))
#define V860_EFUSE_ADDR_CAL_SEL_ADDR(base) ((base) + (0x3DUL))
#else
#define V860_CHIP_ID_0_ADDR(base) ((base) + (0x00))
#define V860_CHIP_ID_1_ADDR(base) ((base) + (0x01))
#define V860_CHIP_ID_2_ADDR(base) ((base) + (0x02))
#define V860_CHIP_ID_3_ADDR(base) ((base) + (0x03))
#define V860_CHIP_ID_4_ADDR(base) ((base) + (0x04))
#define V860_CHIP_ID_5_ADDR(base) ((base) + (0x05))
#define V860_GLB_SOFT_RST_CTRL_ADDR(base) ((base) + (0x06))
#define V860_EFUSE_SOFT_RST_CTRL_ADDR(base) ((base) + (0x07))
#define V860_HKADC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x08))
#define V860_CRG_CLK_EN_CTRL_ADDR(base) ((base) + (0x09))
#define V860_CRG_TESTBUS_CFG_ADDR(base) ((base) + (0x0A))
#define V860_CRG_TESTBUS_RDATA_ADDR(base) ((base) + (0x0B))
#define V860_I2C_SLV_ID_SEL_ADDR(base) ((base) + (0x0C))
#define V860_SC_WDT_EN_ADDR(base) ((base) + (0x10))
#define V860_WDT_SOFT_RST_ADDR(base) ((base) + (0x11))
#define V860_WDT_CTRL_ADDR(base) ((base) + (0x12))
#define V860_DIG_STATUS0_ADDR(base) ((base) + (0x13))
#define V860_DA_FBPS_EN_RO_ADDR(base) ((base) + (0x14))
#define V860_CHG_TB_CFG_ADDR(base) ((base) + (0x15))
#define V860_SC_SC_MODE_SHIELD_ADDR(base) ((base) + (0x16))
#define V860_DA_SC_MODE_ADDR(base) ((base) + (0x17))
#define V860_SYS_LOGIC_RO_REG_3_ADDR(base) ((base) + (0x18))
#define V860_DA_ECO_EN_ADDR(base) ((base) + (0x19))
#define V860_DA_OVP_EN_ADDR(base) ((base) + (0x1A))
#define V860_DA_DC_EN_ADDR(base) ((base) + (0x1B))
#define V860_DA_SC_EN_ADDR(base) ((base) + (0x1C))
#define V860_ECO_MODE_SHIELD_ADDR(base) ((base) + (0x1D))
#define V860_REG_CLK_GT_BYP_ADDR(base) ((base) + (0x1F))
#define V860_I2C_TB_CFG_1_ADDR(base) ((base) + (0x20))
#define V860_PMBUS_TB_CFG_1_ADDR(base) ((base) + (0x21))
#define V860_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x30))
#define V860_EFUSE_MODE_ADDR(base) ((base) + (0x31))
#define V860_EFUSE_RD_CTRL_ADDR(base) ((base) + (0x32))
#define V860_EFUSE_AEN_ADDR(base) ((base) + (0x33))
#define V860_EFUSE_PGMEN_ADDR(base) ((base) + (0x34))
#define V860_EFUSE_RDEN_ADDR(base) ((base) + (0x35))
#define V860_EFUSE_ADDR_ADDR(base) ((base) + (0x36))
#define V860_EFUSE_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x37))
#define V860_EFUSE_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x38))
#define V860_EFUSE_STATUS_ADDR(base) ((base) + (0x39))
#define V860_EFUSE_FSM_RESET_ADDR(base) ((base) + (0x3A))
#define V860_EFUSE_TESTBUS_CFG_ADDR(base) ((base) + (0x3B))
#define V860_EFUSE_TESTBUS_RDATA_ADDR(base) ((base) + (0x3C))
#define V860_EFUSE_ADDR_CAL_SEL_ADDR(base) ((base) + (0x3D))
#endif
#ifndef __SOC_H_FOR_ASM__
#define V860_HKADC_EN_ADDR(base) ((base) + (0x00UL))
#define V860_HKADC_START_ADDR(base) ((base) + (0x01UL))
#define V860_HKADC_CTRL1_ADDR(base) ((base) + (0x02UL))
#define V860_HKADC_SEQ_CH_H_ADDR(base) ((base) + (0x03UL))
#define V860_HKADC_SEQ_CH_L_ADDR(base) ((base) + (0x04UL))
#define V860_HKADC_RD_SEQ_ADDR(base) ((base) + (0x05UL))
#define V860_HKADC_DATA_VALID_ADDR(base) ((base) + (0x06UL))
#define V860_CH0_ADC_L_ADDR(base) ((base) + (0x07UL))
#define V860_CH0_ADC_H_ADDR(base) ((base) + (0x08UL))
#define V860_CH1_ADC_L_ADDR(base) ((base) + (0x09UL))
#define V860_CH1_ADC_H_ADDR(base) ((base) + (0x0AUL))
#define V860_CH2_ADC_L_ADDR(base) ((base) + (0x0BUL))
#define V860_CH2_ADC_H_ADDR(base) ((base) + (0x0CUL))
#define V860_CH3_ADC_L_ADDR(base) ((base) + (0x0DUL))
#define V860_CH3_ADC_H_ADDR(base) ((base) + (0x0EUL))
#define V860_CH4_ADC_L_ADDR(base) ((base) + (0x0FUL))
#define V860_CH4_ADC_H_ADDR(base) ((base) + (0x10UL))
#define V860_CH5_ADC_L_ADDR(base) ((base) + (0x11UL))
#define V860_CH5_ADC_H_ADDR(base) ((base) + (0x12UL))
#define V860_CH6_ADC_L_ADDR(base) ((base) + (0x13UL))
#define V860_CH6_ADC_H_ADDR(base) ((base) + (0x14UL))
#define V860_CH7_ADC_L_ADDR(base) ((base) + (0x15UL))
#define V860_CH7_ADC_H_ADDR(base) ((base) + (0x16UL))
#define V860_CH8_ADC_L_ADDR(base) ((base) + (0x17UL))
#define V860_CH8_ADC_H_ADDR(base) ((base) + (0x18UL))
#define V860_CH9_ADC_L_ADDR(base) ((base) + (0x19UL))
#define V860_CH9_ADC_H_ADDR(base) ((base) + (0x1AUL))
#define V860_CH10_ADC_L_ADDR(base) ((base) + (0x1BUL))
#define V860_CH10_ADC_H_ADDR(base) ((base) + (0x1CUL))
#define V860_CH11_ADC_L_ADDR(base) ((base) + (0x1DUL))
#define V860_CH11_ADC_H_ADDR(base) ((base) + (0x1EUL))
#define V860_CH12_ADC_L_ADDR(base) ((base) + (0x1FUL))
#define V860_CH12_ADC_H_ADDR(base) ((base) + (0x20UL))
#define V860_CH13_ADC_L_ADDR(base) ((base) + (0x21UL))
#define V860_CH13_ADC_H_ADDR(base) ((base) + (0x22UL))
#define V860_CH14_ADC_L_ADDR(base) ((base) + (0x23UL))
#define V860_CH14_ADC_H_ADDR(base) ((base) + (0x24UL))
#define V860_CH15_ADC_L_ADDR(base) ((base) + (0x25UL))
#define V860_CH15_ADC_H_ADDR(base) ((base) + (0x26UL))
#define V860_HKADC_CLK_EN_ADDR(base) ((base) + (0x27UL))
#define V860_HKADC_TB_EN_SEL_ADDR(base) ((base) + (0x28UL))
#define V860_HKADC_TB_DATA0_ADDR(base) ((base) + (0x29UL))
#define V860_HKADC_TB_DATA1_ADDR(base) ((base) + (0x2AUL))
#else
#define V860_HKADC_EN_ADDR(base) ((base) + (0x00))
#define V860_HKADC_START_ADDR(base) ((base) + (0x01))
#define V860_HKADC_CTRL1_ADDR(base) ((base) + (0x02))
#define V860_HKADC_SEQ_CH_H_ADDR(base) ((base) + (0x03))
#define V860_HKADC_SEQ_CH_L_ADDR(base) ((base) + (0x04))
#define V860_HKADC_RD_SEQ_ADDR(base) ((base) + (0x05))
#define V860_HKADC_DATA_VALID_ADDR(base) ((base) + (0x06))
#define V860_CH0_ADC_L_ADDR(base) ((base) + (0x07))
#define V860_CH0_ADC_H_ADDR(base) ((base) + (0x08))
#define V860_CH1_ADC_L_ADDR(base) ((base) + (0x09))
#define V860_CH1_ADC_H_ADDR(base) ((base) + (0x0A))
#define V860_CH2_ADC_L_ADDR(base) ((base) + (0x0B))
#define V860_CH2_ADC_H_ADDR(base) ((base) + (0x0C))
#define V860_CH3_ADC_L_ADDR(base) ((base) + (0x0D))
#define V860_CH3_ADC_H_ADDR(base) ((base) + (0x0E))
#define V860_CH4_ADC_L_ADDR(base) ((base) + (0x0F))
#define V860_CH4_ADC_H_ADDR(base) ((base) + (0x10))
#define V860_CH5_ADC_L_ADDR(base) ((base) + (0x11))
#define V860_CH5_ADC_H_ADDR(base) ((base) + (0x12))
#define V860_CH6_ADC_L_ADDR(base) ((base) + (0x13))
#define V860_CH6_ADC_H_ADDR(base) ((base) + (0x14))
#define V860_CH7_ADC_L_ADDR(base) ((base) + (0x15))
#define V860_CH7_ADC_H_ADDR(base) ((base) + (0x16))
#define V860_CH8_ADC_L_ADDR(base) ((base) + (0x17))
#define V860_CH8_ADC_H_ADDR(base) ((base) + (0x18))
#define V860_CH9_ADC_L_ADDR(base) ((base) + (0x19))
#define V860_CH9_ADC_H_ADDR(base) ((base) + (0x1A))
#define V860_CH10_ADC_L_ADDR(base) ((base) + (0x1B))
#define V860_CH10_ADC_H_ADDR(base) ((base) + (0x1C))
#define V860_CH11_ADC_L_ADDR(base) ((base) + (0x1D))
#define V860_CH11_ADC_H_ADDR(base) ((base) + (0x1E))
#define V860_CH12_ADC_L_ADDR(base) ((base) + (0x1F))
#define V860_CH12_ADC_H_ADDR(base) ((base) + (0x20))
#define V860_CH13_ADC_L_ADDR(base) ((base) + (0x21))
#define V860_CH13_ADC_H_ADDR(base) ((base) + (0x22))
#define V860_CH14_ADC_L_ADDR(base) ((base) + (0x23))
#define V860_CH14_ADC_H_ADDR(base) ((base) + (0x24))
#define V860_CH15_ADC_L_ADDR(base) ((base) + (0x25))
#define V860_CH15_ADC_H_ADDR(base) ((base) + (0x26))
#define V860_HKADC_CLK_EN_ADDR(base) ((base) + (0x27))
#define V860_HKADC_TB_EN_SEL_ADDR(base) ((base) + (0x28))
#define V860_HKADC_TB_DATA0_ADDR(base) ((base) + (0x29))
#define V860_HKADC_TB_DATA1_ADDR(base) ((base) + (0x2A))
#endif
#ifndef __SOC_H_FOR_ASM__
#define V860_IRQ_FLAG_ADDR(base) ((base) + (0x00UL))
#define V860_IRQ_FLAG_0_ADDR(base) ((base) + (0x01UL))
#define V860_IRQ_FLAG_1_ADDR(base) ((base) + (0x02UL))
#define V860_IRQ_FLAG_2_ADDR(base) ((base) + (0x03UL))
#define V860_IRQ_FLAG_3_ADDR(base) ((base) + (0x04UL))
#define V860_IRQ_FLAG_4_ADDR(base) ((base) + (0x05UL))
#define V860_IRQ_FLAG_5_ADDR(base) ((base) + (0x06UL))
#define V860_IRQ_MASK_ADDR(base) ((base) + (0x10UL))
#define V860_IRQ_MASK_0_ADDR(base) ((base) + (0x11UL))
#define V860_IRQ_MASK_1_ADDR(base) ((base) + (0x12UL))
#define V860_IRQ_MASK_2_ADDR(base) ((base) + (0x13UL))
#define V860_IRQ_MASK_3_ADDR(base) ((base) + (0x14UL))
#define V860_IRQ_MASK_4_ADDR(base) ((base) + (0x15UL))
#define V860_IRQ_MASK_5_ADDR(base) ((base) + (0x16UL))
#define V860_IRQ_STATUS_0_ADDR(base) ((base) + (0x20UL))
#define V860_IRQ_STATUS_1_ADDR(base) ((base) + (0x21UL))
#define V860_IRQ_STATUS_2_ADDR(base) ((base) + (0x22UL))
#define V860_IRQ_STATUS_3_ADDR(base) ((base) + (0x23UL))
#define V860_IRQ_STATUS_4_ADDR(base) ((base) + (0x24UL))
#define V860_IRQ_STATUS_5_ADDR(base) ((base) + (0x25UL))
#else
#define V860_IRQ_FLAG_ADDR(base) ((base) + (0x00))
#define V860_IRQ_FLAG_0_ADDR(base) ((base) + (0x01))
#define V860_IRQ_FLAG_1_ADDR(base) ((base) + (0x02))
#define V860_IRQ_FLAG_2_ADDR(base) ((base) + (0x03))
#define V860_IRQ_FLAG_3_ADDR(base) ((base) + (0x04))
#define V860_IRQ_FLAG_4_ADDR(base) ((base) + (0x05))
#define V860_IRQ_FLAG_5_ADDR(base) ((base) + (0x06))
#define V860_IRQ_MASK_ADDR(base) ((base) + (0x10))
#define V860_IRQ_MASK_0_ADDR(base) ((base) + (0x11))
#define V860_IRQ_MASK_1_ADDR(base) ((base) + (0x12))
#define V860_IRQ_MASK_2_ADDR(base) ((base) + (0x13))
#define V860_IRQ_MASK_3_ADDR(base) ((base) + (0x14))
#define V860_IRQ_MASK_4_ADDR(base) ((base) + (0x15))
#define V860_IRQ_MASK_5_ADDR(base) ((base) + (0x16))
#define V860_IRQ_STATUS_0_ADDR(base) ((base) + (0x20))
#define V860_IRQ_STATUS_1_ADDR(base) ((base) + (0x21))
#define V860_IRQ_STATUS_2_ADDR(base) ((base) + (0x22))
#define V860_IRQ_STATUS_3_ADDR(base) ((base) + (0x23))
#define V860_IRQ_STATUS_4_ADDR(base) ((base) + (0x24))
#define V860_IRQ_STATUS_5_ADDR(base) ((base) + (0x25))
#endif
#ifndef __SOC_H_FOR_ASM__
#define V860_SYS_LOGIC_CFG_REG_0_ADDR(base) ((base) + (0x00UL))
#define V860_DS_SYS_RESERVE0_ADDR(base) ((base) + (0x01UL))
#define V860_SYS_LOGIC_CFG_REG_3_ADDR(base) ((base) + (0x02UL))
#define V860_SC_TOP_RO_REG_0_ADDR(base) ((base) + (0x03UL))
#define V860_DA_LDO33_EN_ADDR(base) ((base) + (0x04UL))
#define V860_SYS_LOGIC_CFG_REG_1_ADDR(base) ((base) + (0x05UL))
#define V860_SYS_LOGIC_CFG_REG_2_ADDR(base) ((base) + (0x06UL))
#define V860_SYS_LOGIC_RO_REG_4_ADDR(base) ((base) + (0x07UL))
#define V860_OSC_TOP_CFG_REG_0_ADDR(base) ((base) + (0x08UL))
#define V860_REF_TOP_CFG_REG_0_ADDR(base) ((base) + (0x09UL))
#define V860_REF_TOP_CFG_REG_1_ADDR(base) ((base) + (0x0AUL))
#define V860_REF_TOP_CFG_REG_2_ADDR(base) ((base) + (0x0BUL))
#define V860_SC_TOP_CFG_REG_0_ADDR(base) ((base) + (0x0CUL))
#define V860_SC_TOP_CFG_REG_1_ADDR(base) ((base) + (0x0DUL))
#define V860_SC_TOP_CFG_REG_2_ADDR(base) ((base) + (0x0EUL))
#define V860_SC_TOP_CFG_REG_3_ADDR(base) ((base) + (0x0FUL))
#define V860_SC_TOP_CFG_REG_4_ADDR(base) ((base) + (0x10UL))
#define V860_SC_TOP_CFG_REG_5_ADDR(base) ((base) + (0x11UL))
#define V860_SC_TOP_CFG_REG_6_ADDR(base) ((base) + (0x12UL))
#define V860_SC_TOP_CFG_REG_7_ADDR(base) ((base) + (0x13UL))
#define V860_SC_TOP_CFG_REG_8_ADDR(base) ((base) + (0x14UL))
#define V860_SC_TOP_CFG_REG_9_ADDR(base) ((base) + (0x15UL))
#define V860_SC_TOP_CFG_REG_10_ADDR(base) ((base) + (0x16UL))
#define V860_SC_TOP_CFG_REG_11_ADDR(base) ((base) + (0x17UL))
#define V860_SC_TOP_CFG_REG_12_ADDR(base) ((base) + (0x18UL))
#define V860_SC_TOP_CFG_REG_13_ADDR(base) ((base) + (0x19UL))
#define V860_SC_TOP_CFG_REG_14_ADDR(base) ((base) + (0x1AUL))
#define V860_SC_TOP_CFG_REG_15_ADDR(base) ((base) + (0x1BUL))
#define V860_ADC_CFG_REG_1_ADDR(base) ((base) + (0x1CUL))
#define V860_ADC_CFG_REG_2_ADDR(base) ((base) + (0x1DUL))
#define V860_ADC_CFG_REG_3_ADDR(base) ((base) + (0x1EUL))
#define V860_ADC_RO_REG_4_ADDR(base) ((base) + (0x1FUL))
#define V860_ADC_RO_REG_5_ADDR(base) ((base) + (0x20UL))
#define V860_USB_OVP_CFG_REG_0_ADDR(base) ((base) + (0x21UL))
#define V860_USB_OVP_CFG_REG_1_ADDR(base) ((base) + (0x22UL))
#define V860_USB_OVP_CFG_REG_2_ADDR(base) ((base) + (0x23UL))
#define V860_OVP1_CFG_REG_0_ADDR(base) ((base) + (0x24UL))
#define V860_OVP1_CFG_REG_1_ADDR(base) ((base) + (0x25UL))
#define V860_OVP1_CFG_REG_2_ADDR(base) ((base) + (0x26UL))
#define V860_OVP1_CFG_REG_3_ADDR(base) ((base) + (0x27UL))
#define V860_OVP1_CFG_REG_4_ADDR(base) ((base) + (0x28UL))
#define V860_SC_DET_TOP_CFG_REG_0_ADDR(base) ((base) + (0x29UL))
#define V860_SC_DET_TOP_CFG_REG_1_ADDR(base) ((base) + (0x2AUL))
#define V860_SC_DET_TOP_CFG_REG_2_ADDR(base) ((base) + (0x2BUL))
#define V860_SC_DET_TOP_CFG_REG_3_ADDR(base) ((base) + (0x2CUL))
#define V860_SC_DET_TOP_CFG_REG_4_ADDR(base) ((base) + (0x2DUL))
#define V860_SC_DET_TOP_CFG_REG_5_ADDR(base) ((base) + (0x2EUL))
#define V860_SC_DET_TOP_CFG_REG_6_ADDR(base) ((base) + (0x2FUL))
#define V860_SC_DET_TOP_CFG_REG_7_ADDR(base) ((base) + (0x30UL))
#define V860_BLK_TOP_CFG_REG_0_ADDR(base) ((base) + (0x31UL))
#define V860_EFUSE_IO_CFG_REG_0_ADDR(base) ((base) + (0x32UL))
#define V860_SC_PRO_CFG_REG_0_ADDR(base) ((base) + (0x33UL))
#define V860_SC_PRO_CFG_REG_1_ADDR(base) ((base) + (0x34UL))
#define V860_SC_PRO_CFG_REG_2_ADDR(base) ((base) + (0x35UL))
#define V860_SC_PRO_CFG_REG_3_ADDR(base) ((base) + (0x36UL))
#define V860_SC_PRO_CFG_REG_4_ADDR(base) ((base) + (0x37UL))
#define V860_SC_PRO_CFG_REG_5_ADDR(base) ((base) + (0x38UL))
#define V860_SC_PRO_CFG_REG_6_ADDR(base) ((base) + (0x39UL))
#define V860_SC_PRO_CFG_REG_7_ADDR(base) ((base) + (0x3AUL))
#define V860_SC_PRO_CFG_REG_8_ADDR(base) ((base) + (0x3BUL))
#define V860_SC_PRO_CFG_REG_9_ADDR(base) ((base) + (0x3CUL))
#define V860_DA_BAT_RES_MODE_ADDR(base) ((base) + (0x3DUL))
#define V860_SYS_DET_CFG_REG_0_ADDR(base) ((base) + (0x3EUL))
#define V860_DA_SCPRO_RESERVE2_ADDR(base) ((base) + (0x3FUL))
#define V860_DA_SCPRO_TESTMD_ADDR(base) ((base) + (0x40UL))
#define V860_PSEL_CFG_REG_0_ADDR(base) ((base) + (0x41UL))
#define V860_PSEL_CFG_REG_1_ADDR(base) ((base) + (0x42UL))
#define V860_PSEL_CFG_REG_2_ADDR(base) ((base) + (0x43UL))
#define V860_PSEL_CFG_REG_3_ADDR(base) ((base) + (0x44UL))
#define V860_BLOCK_SNS_CFG_REG_0_ADDR(base) ((base) + (0x45UL))
#define V860_BLOCK_SNS_CFG_REG_1_ADDR(base) ((base) + (0x46UL))
#define V860_BLOCK_SNS_CFG_REG_2_ADDR(base) ((base) + (0x47UL))
#define V860_BLOCK_SNS_CFG_REG_3_ADDR(base) ((base) + (0x48UL))
#define V860_BLOCK_SNS_CFG_REG_4_ADDR(base) ((base) + (0x49UL))
#define V860_BLOCK_SNS_CFG_REG_5_ADDR(base) ((base) + (0x4AUL))
#define V860_BLOCK_SNS_CFG_REG_6_ADDR(base) ((base) + (0x4BUL))
#define V860_BLOCK_SNS_CFG_REG_7_ADDR(base) ((base) + (0x4CUL))
#define V860_BLOCK_SNS_CFG_REG_8_ADDR(base) ((base) + (0x4DUL))
#define V860_DS_SYS_RESVO1_ADDR(base) ((base) + (0x4EUL))
#define V860_BLOCK_SNS_RO_REG_0_ADDR(base) ((base) + (0x4FUL))
#define V860_DA_SC_PHASE1_EN_ADDR(base) ((base) + (0x50UL))
#else
#define V860_SYS_LOGIC_CFG_REG_0_ADDR(base) ((base) + (0x00))
#define V860_DS_SYS_RESERVE0_ADDR(base) ((base) + (0x01))
#define V860_SYS_LOGIC_CFG_REG_3_ADDR(base) ((base) + (0x02))
#define V860_SC_TOP_RO_REG_0_ADDR(base) ((base) + (0x03))
#define V860_DA_LDO33_EN_ADDR(base) ((base) + (0x04))
#define V860_SYS_LOGIC_CFG_REG_1_ADDR(base) ((base) + (0x05))
#define V860_SYS_LOGIC_CFG_REG_2_ADDR(base) ((base) + (0x06))
#define V860_SYS_LOGIC_RO_REG_4_ADDR(base) ((base) + (0x07))
#define V860_OSC_TOP_CFG_REG_0_ADDR(base) ((base) + (0x08))
#define V860_REF_TOP_CFG_REG_0_ADDR(base) ((base) + (0x09))
#define V860_REF_TOP_CFG_REG_1_ADDR(base) ((base) + (0x0A))
#define V860_REF_TOP_CFG_REG_2_ADDR(base) ((base) + (0x0B))
#define V860_SC_TOP_CFG_REG_0_ADDR(base) ((base) + (0x0C))
#define V860_SC_TOP_CFG_REG_1_ADDR(base) ((base) + (0x0D))
#define V860_SC_TOP_CFG_REG_2_ADDR(base) ((base) + (0x0E))
#define V860_SC_TOP_CFG_REG_3_ADDR(base) ((base) + (0x0F))
#define V860_SC_TOP_CFG_REG_4_ADDR(base) ((base) + (0x10))
#define V860_SC_TOP_CFG_REG_5_ADDR(base) ((base) + (0x11))
#define V860_SC_TOP_CFG_REG_6_ADDR(base) ((base) + (0x12))
#define V860_SC_TOP_CFG_REG_7_ADDR(base) ((base) + (0x13))
#define V860_SC_TOP_CFG_REG_8_ADDR(base) ((base) + (0x14))
#define V860_SC_TOP_CFG_REG_9_ADDR(base) ((base) + (0x15))
#define V860_SC_TOP_CFG_REG_10_ADDR(base) ((base) + (0x16))
#define V860_SC_TOP_CFG_REG_11_ADDR(base) ((base) + (0x17))
#define V860_SC_TOP_CFG_REG_12_ADDR(base) ((base) + (0x18))
#define V860_SC_TOP_CFG_REG_13_ADDR(base) ((base) + (0x19))
#define V860_SC_TOP_CFG_REG_14_ADDR(base) ((base) + (0x1A))
#define V860_SC_TOP_CFG_REG_15_ADDR(base) ((base) + (0x1B))
#define V860_ADC_CFG_REG_1_ADDR(base) ((base) + (0x1C))
#define V860_ADC_CFG_REG_2_ADDR(base) ((base) + (0x1D))
#define V860_ADC_CFG_REG_3_ADDR(base) ((base) + (0x1E))
#define V860_ADC_RO_REG_4_ADDR(base) ((base) + (0x1F))
#define V860_ADC_RO_REG_5_ADDR(base) ((base) + (0x20))
#define V860_USB_OVP_CFG_REG_0_ADDR(base) ((base) + (0x21))
#define V860_USB_OVP_CFG_REG_1_ADDR(base) ((base) + (0x22))
#define V860_USB_OVP_CFG_REG_2_ADDR(base) ((base) + (0x23))
#define V860_OVP1_CFG_REG_0_ADDR(base) ((base) + (0x24))
#define V860_OVP1_CFG_REG_1_ADDR(base) ((base) + (0x25))
#define V860_OVP1_CFG_REG_2_ADDR(base) ((base) + (0x26))
#define V860_OVP1_CFG_REG_3_ADDR(base) ((base) + (0x27))
#define V860_OVP1_CFG_REG_4_ADDR(base) ((base) + (0x28))
#define V860_SC_DET_TOP_CFG_REG_0_ADDR(base) ((base) + (0x29))
#define V860_SC_DET_TOP_CFG_REG_1_ADDR(base) ((base) + (0x2A))
#define V860_SC_DET_TOP_CFG_REG_2_ADDR(base) ((base) + (0x2B))
#define V860_SC_DET_TOP_CFG_REG_3_ADDR(base) ((base) + (0x2C))
#define V860_SC_DET_TOP_CFG_REG_4_ADDR(base) ((base) + (0x2D))
#define V860_SC_DET_TOP_CFG_REG_5_ADDR(base) ((base) + (0x2E))
#define V860_SC_DET_TOP_CFG_REG_6_ADDR(base) ((base) + (0x2F))
#define V860_SC_DET_TOP_CFG_REG_7_ADDR(base) ((base) + (0x30))
#define V860_BLK_TOP_CFG_REG_0_ADDR(base) ((base) + (0x31))
#define V860_EFUSE_IO_CFG_REG_0_ADDR(base) ((base) + (0x32))
#define V860_SC_PRO_CFG_REG_0_ADDR(base) ((base) + (0x33))
#define V860_SC_PRO_CFG_REG_1_ADDR(base) ((base) + (0x34))
#define V860_SC_PRO_CFG_REG_2_ADDR(base) ((base) + (0x35))
#define V860_SC_PRO_CFG_REG_3_ADDR(base) ((base) + (0x36))
#define V860_SC_PRO_CFG_REG_4_ADDR(base) ((base) + (0x37))
#define V860_SC_PRO_CFG_REG_5_ADDR(base) ((base) + (0x38))
#define V860_SC_PRO_CFG_REG_6_ADDR(base) ((base) + (0x39))
#define V860_SC_PRO_CFG_REG_7_ADDR(base) ((base) + (0x3A))
#define V860_SC_PRO_CFG_REG_8_ADDR(base) ((base) + (0x3B))
#define V860_SC_PRO_CFG_REG_9_ADDR(base) ((base) + (0x3C))
#define V860_DA_BAT_RES_MODE_ADDR(base) ((base) + (0x3D))
#define V860_SYS_DET_CFG_REG_0_ADDR(base) ((base) + (0x3E))
#define V860_DA_SCPRO_RESERVE2_ADDR(base) ((base) + (0x3F))
#define V860_DA_SCPRO_TESTMD_ADDR(base) ((base) + (0x40))
#define V860_PSEL_CFG_REG_0_ADDR(base) ((base) + (0x41))
#define V860_PSEL_CFG_REG_1_ADDR(base) ((base) + (0x42))
#define V860_PSEL_CFG_REG_2_ADDR(base) ((base) + (0x43))
#define V860_PSEL_CFG_REG_3_ADDR(base) ((base) + (0x44))
#define V860_BLOCK_SNS_CFG_REG_0_ADDR(base) ((base) + (0x45))
#define V860_BLOCK_SNS_CFG_REG_1_ADDR(base) ((base) + (0x46))
#define V860_BLOCK_SNS_CFG_REG_2_ADDR(base) ((base) + (0x47))
#define V860_BLOCK_SNS_CFG_REG_3_ADDR(base) ((base) + (0x48))
#define V860_BLOCK_SNS_CFG_REG_4_ADDR(base) ((base) + (0x49))
#define V860_BLOCK_SNS_CFG_REG_5_ADDR(base) ((base) + (0x4A))
#define V860_BLOCK_SNS_CFG_REG_6_ADDR(base) ((base) + (0x4B))
#define V860_BLOCK_SNS_CFG_REG_7_ADDR(base) ((base) + (0x4C))
#define V860_BLOCK_SNS_CFG_REG_8_ADDR(base) ((base) + (0x4D))
#define V860_DS_SYS_RESVO1_ADDR(base) ((base) + (0x4E))
#define V860_BLOCK_SNS_RO_REG_0_ADDR(base) ((base) + (0x4F))
#define V860_DA_SC_PHASE1_EN_ADDR(base) ((base) + (0x50))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id0 : 8;
    } reg;
} V860_CHIP_ID_0_UNION;
#endif
#define V860_CHIP_ID_0_chip_id0_START (0)
#define V860_CHIP_ID_0_chip_id0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id1 : 8;
    } reg;
} V860_CHIP_ID_1_UNION;
#endif
#define V860_CHIP_ID_1_chip_id1_START (0)
#define V860_CHIP_ID_1_chip_id1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id2 : 8;
    } reg;
} V860_CHIP_ID_2_UNION;
#endif
#define V860_CHIP_ID_2_chip_id2_START (0)
#define V860_CHIP_ID_2_chip_id2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id3 : 8;
    } reg;
} V860_CHIP_ID_3_UNION;
#endif
#define V860_CHIP_ID_3_chip_id3_START (0)
#define V860_CHIP_ID_3_chip_id3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id4 : 8;
    } reg;
} V860_CHIP_ID_4_UNION;
#endif
#define V860_CHIP_ID_4_chip_id4_START (0)
#define V860_CHIP_ID_4_chip_id4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id5 : 8;
    } reg;
} V860_CHIP_ID_5_UNION;
#endif
#define V860_CHIP_ID_5_chip_id5_START (0)
#define V860_CHIP_ID_5_chip_id5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_glb_soft_rst_n : 8;
    } reg;
} V860_GLB_SOFT_RST_CTRL_UNION;
#endif
#define V860_GLB_SOFT_RST_CTRL_sc_glb_soft_rst_n_START (0)
#define V860_GLB_SOFT_RST_CTRL_sc_glb_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efu_soft_rst_n : 8;
    } reg;
} V860_EFUSE_SOFT_RST_CTRL_UNION;
#endif
#define V860_EFUSE_SOFT_RST_CTRL_sc_efu_soft_rst_n_START (0)
#define V860_EFUSE_SOFT_RST_CTRL_sc_efu_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_cg_adc_soft_rst_n : 8;
    } reg;
} V860_HKADC_SOFT_RST_CTRL_UNION;
#endif
#define V860_HKADC_SOFT_RST_CTRL_sc_cg_adc_soft_rst_n_START (0)
#define V860_HKADC_SOFT_RST_CTRL_sc_cg_adc_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_cg_com_clk_en : 1;
        unsigned char sc_cg_1m_clk_en_sel : 1;
        unsigned char sc_cg_2m_clk_en : 1;
        unsigned char sc_cg_2m_clk_en_sel : 1;
        unsigned char reserved : 4;
    } reg;
} V860_CRG_CLK_EN_CTRL_UNION;
#endif
#define V860_CRG_CLK_EN_CTRL_sc_cg_com_clk_en_START (0)
#define V860_CRG_CLK_EN_CTRL_sc_cg_com_clk_en_END (0)
#define V860_CRG_CLK_EN_CTRL_sc_cg_1m_clk_en_sel_START (1)
#define V860_CRG_CLK_EN_CTRL_sc_cg_1m_clk_en_sel_END (1)
#define V860_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_START (2)
#define V860_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_END (2)
#define V860_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_sel_START (3)
#define V860_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_cg_testbus_sel : 4;
        unsigned char sc_cg_testsig_sel : 3;
        unsigned char sc_cg_testbus_en : 1;
    } reg;
} V860_CRG_TESTBUS_CFG_UNION;
#endif
#define V860_CRG_TESTBUS_CFG_sc_cg_testbus_sel_START (0)
#define V860_CRG_TESTBUS_CFG_sc_cg_testbus_sel_END (3)
#define V860_CRG_TESTBUS_CFG_sc_cg_testsig_sel_START (4)
#define V860_CRG_TESTBUS_CFG_sc_cg_testsig_sel_END (6)
#define V860_CRG_TESTBUS_CFG_sc_cg_testbus_en_START (7)
#define V860_CRG_TESTBUS_CFG_sc_cg_testbus_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char cg_testbus_rdata : 8;
    } reg;
} V860_CRG_TESTBUS_RDATA_UNION;
#endif
#define V860_CRG_TESTBUS_RDATA_cg_testbus_rdata_START (0)
#define V860_CRG_TESTBUS_RDATA_cg_testbus_rdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reserved : 8;
    } reg;
} V860_I2C_SLV_ID_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_wdt_en : 1;
        unsigned char reserved : 7;
    } reg;
} V860_SC_WDT_EN_UNION;
#endif
#define V860_SC_WDT_EN_sc_wdt_en_START (0)
#define V860_SC_WDT_EN_sc_wdt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char wd_rst_n : 1;
        unsigned char reserved : 7;
    } reg;
} V860_WDT_SOFT_RST_UNION;
#endif
#define V860_WDT_SOFT_RST_wd_rst_n_START (0)
#define V860_WDT_SOFT_RST_wd_rst_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_watchdog_timer : 2;
        unsigned char reserved_0 : 2;
        unsigned char sc_wdt_test_sel : 1;
        unsigned char reserved_1 : 3;
    } reg;
} V860_WDT_CTRL_UNION;
#endif
#define V860_WDT_CTRL_sc_watchdog_timer_START (0)
#define V860_WDT_CTRL_sc_watchdog_timer_END (1)
#define V860_WDT_CTRL_sc_wdt_test_sel_START (4)
#define V860_WDT_CTRL_sc_wdt_test_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char wdt_time_out_n : 1;
        unsigned char reserved : 7;
    } reg;
} V860_DIG_STATUS0_UNION;
#endif
#define V860_DIG_STATUS0_wdt_time_out_n_START (0)
#define V860_DIG_STATUS0_wdt_time_out_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_f41sc_en_ro : 1;
        unsigned char da_f21sc_en_ro : 1;
        unsigned char da_fbps_en_ro : 1;
        unsigned char reserved : 5;
    } reg;
} V860_DA_FBPS_EN_RO_UNION;
#endif
#define V860_DA_FBPS_EN_RO_da_f41sc_en_ro_START (0)
#define V860_DA_FBPS_EN_RO_da_f41sc_en_ro_END (0)
#define V860_DA_FBPS_EN_RO_da_f21sc_en_ro_START (1)
#define V860_DA_FBPS_EN_RO_da_f21sc_en_ro_END (1)
#define V860_DA_FBPS_EN_RO_da_fbps_en_ro_START (2)
#define V860_DA_FBPS_EN_RO_da_fbps_en_ro_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_chg_tb_sel : 6;
        unsigned char sc_chg_tb_en : 1;
        unsigned char chg_tb_sig : 1;
    } reg;
} V860_CHG_TB_CFG_UNION;
#endif
#define V860_CHG_TB_CFG_sc_chg_tb_sel_START (0)
#define V860_CHG_TB_CFG_sc_chg_tb_sel_END (5)
#define V860_CHG_TB_CFG_sc_chg_tb_en_START (6)
#define V860_CHG_TB_CFG_sc_chg_tb_en_END (6)
#define V860_CHG_TB_CFG_chg_tb_sig_START (7)
#define V860_CHG_TB_CFG_chg_tb_sig_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_sc_mode_shield : 1;
        unsigned char reserved : 7;
    } reg;
} V860_SC_SC_MODE_SHIELD_UNION;
#endif
#define V860_SC_SC_MODE_SHIELD_sc_sc_mode_shield_START (0)
#define V860_SC_SC_MODE_SHIELD_sc_sc_mode_shield_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_mode : 3;
        unsigned char reserved : 5;
    } reg;
} V860_DA_SC_MODE_UNION;
#endif
#define V860_DA_SC_MODE_da_sc_mode_START (0)
#define V860_DA_SC_MODE_da_sc_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ad_i2c_sel_ro : 1;
        unsigned char ad_eco1_enb_pin_ro : 1;
        unsigned char ad_clk2m_en_ro : 1;
        unsigned char reserved : 5;
    } reg;
} V860_SYS_LOGIC_RO_REG_3_UNION;
#endif
#define V860_SYS_LOGIC_RO_REG_3_ad_i2c_sel_ro_START (0)
#define V860_SYS_LOGIC_RO_REG_3_ad_i2c_sel_ro_END (0)
#define V860_SYS_LOGIC_RO_REG_3_ad_eco1_enb_pin_ro_START (1)
#define V860_SYS_LOGIC_RO_REG_3_ad_eco1_enb_pin_ro_END (1)
#define V860_SYS_LOGIC_RO_REG_3_ad_clk2m_en_ro_START (2)
#define V860_SYS_LOGIC_RO_REG_3_ad_clk2m_en_ro_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_eco_en : 1;
        unsigned char reserved : 7;
    } reg;
} V860_DA_ECO_EN_UNION;
#endif
#define V860_DA_ECO_EN_da_eco_en_START (0)
#define V860_DA_ECO_EN_da_eco_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_ovp_en : 1;
        unsigned char reserved : 7;
    } reg;
} V860_DA_OVP_EN_UNION;
#endif
#define V860_DA_OVP_EN_da_ovp_en_START (0)
#define V860_DA_OVP_EN_da_ovp_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_dc_en : 1;
        unsigned char reserved : 7;
    } reg;
} V860_DA_DC_EN_UNION;
#endif
#define V860_DA_DC_EN_da_dc_en_START (0)
#define V860_DA_DC_EN_da_dc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_en : 1;
        unsigned char reserved : 7;
    } reg;
} V860_DA_SC_EN_UNION;
#endif
#define V860_DA_SC_EN_da_sc_en_START (0)
#define V860_DA_SC_EN_da_sc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_eco2_mode_shield : 1;
        unsigned char reserved : 7;
    } reg;
} V860_ECO_MODE_SHIELD_UNION;
#endif
#define V860_ECO_MODE_SHIELD_da_eco2_mode_shield_START (0)
#define V860_ECO_MODE_SHIELD_da_eco2_mode_shield_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_clk_gt_byp : 1;
        unsigned char reserved : 7;
    } reg;
} V860_REG_CLK_GT_BYP_UNION;
#endif
#define V860_REG_CLK_GT_BYP_reg_clk_gt_byp_START (0)
#define V860_REG_CLK_GT_BYP_reg_clk_gt_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char i2c_tb_sel_1 : 4;
        unsigned char i2c_tb_sig_en_1 : 1;
        unsigned char reserved : 3;
    } reg;
} V860_I2C_TB_CFG_1_UNION;
#endif
#define V860_I2C_TB_CFG_1_i2c_tb_sel_1_START (0)
#define V860_I2C_TB_CFG_1_i2c_tb_sel_1_END (3)
#define V860_I2C_TB_CFG_1_i2c_tb_sig_en_1_START (4)
#define V860_I2C_TB_CFG_1_i2c_tb_sig_en_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmbus_tb_sel_1 : 4;
        unsigned char pmbus_tb_sig_en_1 : 1;
        unsigned char dig_test_sel_1 : 1;
        unsigned char reserved : 2;
    } reg;
} V860_PMBUS_TB_CFG_1_UNION;
#endif
#define V860_PMBUS_TB_CFG_1_pmbus_tb_sel_1_START (0)
#define V860_PMBUS_TB_CFG_1_pmbus_tb_sel_1_END (3)
#define V860_PMBUS_TB_CFG_1_pmbus_tb_sig_en_1_START (4)
#define V860_PMBUS_TB_CFG_1_pmbus_tb_sig_en_1_END (4)
#define V860_PMBUS_TB_CFG_1_dig_test_sel_1_START (5)
#define V860_PMBUS_TB_CFG_1_dig_test_sel_1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_pdob_sel : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_PDOB_SEL_UNION;
#endif
#define V860_EFUSE_PDOB_SEL_sc_efuse_pdob_sel_START (0)
#define V860_EFUSE_PDOB_SEL_sc_efuse_pdob_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_prog_int : 1;
        unsigned char sc_efuse_prog_sel : 1;
        unsigned char sc_efuse_inctrl_sel : 1;
        unsigned char reserved : 5;
    } reg;
} V860_EFUSE_MODE_UNION;
#endif
#define V860_EFUSE_MODE_sc_efuse_prog_int_START (0)
#define V860_EFUSE_MODE_sc_efuse_prog_int_END (0)
#define V860_EFUSE_MODE_sc_efuse_prog_sel_START (1)
#define V860_EFUSE_MODE_sc_efuse_prog_sel_END (1)
#define V860_EFUSE_MODE_sc_efuse_inctrl_sel_START (2)
#define V860_EFUSE_MODE_sc_efuse_inctrl_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_rd_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_RD_CTRL_UNION;
#endif
#define V860_EFUSE_RD_CTRL_sc_efuse_rd_ctrl_START (0)
#define V860_EFUSE_RD_CTRL_sc_efuse_rd_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_aen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_AEN_UNION;
#endif
#define V860_EFUSE_AEN_sc_efuse_aen_cfg_START (0)
#define V860_EFUSE_AEN_sc_efuse_aen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_pgmen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_PGMEN_UNION;
#endif
#define V860_EFUSE_PGMEN_sc_efuse_pgmen_cfg_START (0)
#define V860_EFUSE_PGMEN_sc_efuse_pgmen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_rden_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_RDEN_UNION;
#endif
#define V860_EFUSE_RDEN_sc_efuse_rden_cfg_START (0)
#define V860_EFUSE_RDEN_sc_efuse_rden_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_a_cfg : 8;
    } reg;
} V860_EFUSE_ADDR_UNION;
#endif
#define V860_EFUSE_ADDR_sc_efuse_a_cfg_START (0)
#define V860_EFUSE_ADDR_sc_efuse_a_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_pdob_pre_addr : 5;
        unsigned char reserved : 2;
        unsigned char sc_efuse_pdob_pre_we : 1;
    } reg;
} V860_EFUSE_PDOB_PRE_ADDR_WE_UNION;
#endif
#define V860_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_addr_START (0)
#define V860_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_addr_END (4)
#define V860_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_we_START (7)
#define V860_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_we_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_pdob_pre_wdata : 8;
    } reg;
} V860_EFUSE_PDOB_PRE_WDATA_UNION;
#endif
#define V860_EFUSE_PDOB_PRE_WDATA_sc_efuse_pdob_pre_wdata_START (0)
#define V860_EFUSE_PDOB_PRE_WDATA_sc_efuse_pdob_pre_wdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char tb_efuse_state : 4;
        unsigned char tb_efuse_por_int_ro : 1;
        unsigned char tb_efuse_rd_done : 1;
        unsigned char reserved : 2;
    } reg;
} V860_EFUSE_STATUS_UNION;
#endif
#define V860_EFUSE_STATUS_tb_efuse_state_START (0)
#define V860_EFUSE_STATUS_tb_efuse_state_END (3)
#define V860_EFUSE_STATUS_tb_efuse_por_int_ro_START (4)
#define V860_EFUSE_STATUS_tb_efuse_por_int_ro_END (4)
#define V860_EFUSE_STATUS_tb_efuse_rd_done_START (5)
#define V860_EFUSE_STATUS_tb_efuse_rd_done_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_state_reset : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_FSM_RESET_UNION;
#endif
#define V860_EFUSE_FSM_RESET_sc_efuse_state_reset_START (0)
#define V860_EFUSE_FSM_RESET_sc_efuse_state_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_testbus_sel : 7;
        unsigned char sc_efuse_testbus_en : 1;
    } reg;
} V860_EFUSE_TESTBUS_CFG_UNION;
#endif
#define V860_EFUSE_TESTBUS_CFG_sc_efuse_testbus_sel_START (0)
#define V860_EFUSE_TESTBUS_CFG_sc_efuse_testbus_sel_END (6)
#define V860_EFUSE_TESTBUS_CFG_sc_efuse_testbus_en_START (7)
#define V860_EFUSE_TESTBUS_CFG_sc_efuse_testbus_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_testbus_rdata : 8;
    } reg;
} V860_EFUSE_TESTBUS_RDATA_UNION;
#endif
#define V860_EFUSE_TESTBUS_RDATA_efuse_testbus_rdata_START (0)
#define V860_EFUSE_TESTBUS_RDATA_efuse_testbus_rdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_a_cal_sel : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_ADDR_CAL_SEL_UNION;
#endif
#define V860_EFUSE_ADDR_CAL_SEL_sc_efuse_a_cal_sel_START (0)
#define V860_EFUSE_ADDR_CAL_SEL_sc_efuse_a_cal_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hkadc_en : 1;
        unsigned char reserved : 7;
    } reg;
} V860_HKADC_EN_UNION;
#endif
#define V860_HKADC_EN_sc_hkadc_en_START (0)
#define V860_HKADC_EN_sc_hkadc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hkadc_start : 1;
        unsigned char reserved : 7;
    } reg;
} V860_HKADC_START_UNION;
#endif
#define V860_HKADC_START_sc_hkadc_start_START (0)
#define V860_HKADC_START_sc_hkadc_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hkadc_avg_times : 2;
        unsigned char reserved_0 : 2;
        unsigned char sc_hkadc_seq_loop : 1;
        unsigned char sc_hkadc_cul_time : 1;
        unsigned char sc_hkadc_chopper_time : 1;
        unsigned char reserved_1 : 1;
    } reg;
} V860_HKADC_CTRL1_UNION;
#endif
#define V860_HKADC_CTRL1_sc_hkadc_avg_times_START (0)
#define V860_HKADC_CTRL1_sc_hkadc_avg_times_END (1)
#define V860_HKADC_CTRL1_sc_hkadc_seq_loop_START (4)
#define V860_HKADC_CTRL1_sc_hkadc_seq_loop_END (4)
#define V860_HKADC_CTRL1_sc_hkadc_cul_time_START (5)
#define V860_HKADC_CTRL1_sc_hkadc_cul_time_END (5)
#define V860_HKADC_CTRL1_sc_hkadc_chopper_time_START (6)
#define V860_HKADC_CTRL1_sc_hkadc_chopper_time_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hkadc_seq_chanel_h : 8;
    } reg;
} V860_HKADC_SEQ_CH_H_UNION;
#endif
#define V860_HKADC_SEQ_CH_H_sc_hkadc_seq_chanel_h_START (0)
#define V860_HKADC_SEQ_CH_H_sc_hkadc_seq_chanel_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hkadc_seq_chanel_l : 8;
    } reg;
} V860_HKADC_SEQ_CH_L_UNION;
#endif
#define V860_HKADC_SEQ_CH_L_sc_hkadc_seq_chanel_l_START (0)
#define V860_HKADC_SEQ_CH_L_sc_hkadc_seq_chanel_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hkadc_rd_req : 1;
        unsigned char reserved : 7;
    } reg;
} V860_HKADC_RD_SEQ_UNION;
#endif
#define V860_HKADC_RD_SEQ_sc_hkadc_rd_req_START (0)
#define V860_HKADC_RD_SEQ_sc_hkadc_rd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char hkadc_data_valid : 1;
        unsigned char reserved : 7;
    } reg;
} V860_HKADC_DATA_VALID_UNION;
#endif
#define V860_HKADC_DATA_VALID_hkadc_data_valid_START (0)
#define V860_HKADC_DATA_VALID_hkadc_data_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch0_adc_out_l : 8;
    } reg;
} V860_CH0_ADC_L_UNION;
#endif
#define V860_CH0_ADC_L_ch0_adc_out_l_START (0)
#define V860_CH0_ADC_L_ch0_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch0_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH0_ADC_H_UNION;
#endif
#define V860_CH0_ADC_H_ch0_adc_out_h_START (0)
#define V860_CH0_ADC_H_ch0_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch1_adc_out_l : 8;
    } reg;
} V860_CH1_ADC_L_UNION;
#endif
#define V860_CH1_ADC_L_ch1_adc_out_l_START (0)
#define V860_CH1_ADC_L_ch1_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch1_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH1_ADC_H_UNION;
#endif
#define V860_CH1_ADC_H_ch1_adc_out_h_START (0)
#define V860_CH1_ADC_H_ch1_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch2_adc_out_l : 8;
    } reg;
} V860_CH2_ADC_L_UNION;
#endif
#define V860_CH2_ADC_L_ch2_adc_out_l_START (0)
#define V860_CH2_ADC_L_ch2_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch2_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH2_ADC_H_UNION;
#endif
#define V860_CH2_ADC_H_ch2_adc_out_h_START (0)
#define V860_CH2_ADC_H_ch2_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch3_adc_out_l : 8;
    } reg;
} V860_CH3_ADC_L_UNION;
#endif
#define V860_CH3_ADC_L_ch3_adc_out_l_START (0)
#define V860_CH3_ADC_L_ch3_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch3_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH3_ADC_H_UNION;
#endif
#define V860_CH3_ADC_H_ch3_adc_out_h_START (0)
#define V860_CH3_ADC_H_ch3_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch4_adc_out_l : 8;
    } reg;
} V860_CH4_ADC_L_UNION;
#endif
#define V860_CH4_ADC_L_ch4_adc_out_l_START (0)
#define V860_CH4_ADC_L_ch4_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch4_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH4_ADC_H_UNION;
#endif
#define V860_CH4_ADC_H_ch4_adc_out_h_START (0)
#define V860_CH4_ADC_H_ch4_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch5_adc_out_l : 8;
    } reg;
} V860_CH5_ADC_L_UNION;
#endif
#define V860_CH5_ADC_L_ch5_adc_out_l_START (0)
#define V860_CH5_ADC_L_ch5_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch5_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH5_ADC_H_UNION;
#endif
#define V860_CH5_ADC_H_ch5_adc_out_h_START (0)
#define V860_CH5_ADC_H_ch5_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch6_adc_out_l : 8;
    } reg;
} V860_CH6_ADC_L_UNION;
#endif
#define V860_CH6_ADC_L_ch6_adc_out_l_START (0)
#define V860_CH6_ADC_L_ch6_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch6_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH6_ADC_H_UNION;
#endif
#define V860_CH6_ADC_H_ch6_adc_out_h_START (0)
#define V860_CH6_ADC_H_ch6_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch7_adc_out_l : 8;
    } reg;
} V860_CH7_ADC_L_UNION;
#endif
#define V860_CH7_ADC_L_ch7_adc_out_l_START (0)
#define V860_CH7_ADC_L_ch7_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch7_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH7_ADC_H_UNION;
#endif
#define V860_CH7_ADC_H_ch7_adc_out_h_START (0)
#define V860_CH7_ADC_H_ch7_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch8_adc_out_l : 8;
    } reg;
} V860_CH8_ADC_L_UNION;
#endif
#define V860_CH8_ADC_L_ch8_adc_out_l_START (0)
#define V860_CH8_ADC_L_ch8_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch8_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH8_ADC_H_UNION;
#endif
#define V860_CH8_ADC_H_ch8_adc_out_h_START (0)
#define V860_CH8_ADC_H_ch8_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch9_adc_out_l : 8;
    } reg;
} V860_CH9_ADC_L_UNION;
#endif
#define V860_CH9_ADC_L_ch9_adc_out_l_START (0)
#define V860_CH9_ADC_L_ch9_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch9_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH9_ADC_H_UNION;
#endif
#define V860_CH9_ADC_H_ch9_adc_out_h_START (0)
#define V860_CH9_ADC_H_ch9_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch10_adc_out_l : 8;
    } reg;
} V860_CH10_ADC_L_UNION;
#endif
#define V860_CH10_ADC_L_ch10_adc_out_l_START (0)
#define V860_CH10_ADC_L_ch10_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch10_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH10_ADC_H_UNION;
#endif
#define V860_CH10_ADC_H_ch10_adc_out_h_START (0)
#define V860_CH10_ADC_H_ch10_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch11_adc_out_l : 8;
    } reg;
} V860_CH11_ADC_L_UNION;
#endif
#define V860_CH11_ADC_L_ch11_adc_out_l_START (0)
#define V860_CH11_ADC_L_ch11_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch11_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH11_ADC_H_UNION;
#endif
#define V860_CH11_ADC_H_ch11_adc_out_h_START (0)
#define V860_CH11_ADC_H_ch11_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch12_adc_out_l : 8;
    } reg;
} V860_CH12_ADC_L_UNION;
#endif
#define V860_CH12_ADC_L_ch12_adc_out_l_START (0)
#define V860_CH12_ADC_L_ch12_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch12_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH12_ADC_H_UNION;
#endif
#define V860_CH12_ADC_H_ch12_adc_out_h_START (0)
#define V860_CH12_ADC_H_ch12_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch13_adc_out_l : 8;
    } reg;
} V860_CH13_ADC_L_UNION;
#endif
#define V860_CH13_ADC_L_ch13_adc_out_l_START (0)
#define V860_CH13_ADC_L_ch13_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch13_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH13_ADC_H_UNION;
#endif
#define V860_CH13_ADC_H_ch13_adc_out_h_START (0)
#define V860_CH13_ADC_H_ch13_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch14_adc_out_l : 8;
    } reg;
} V860_CH14_ADC_L_UNION;
#endif
#define V860_CH14_ADC_L_ch14_adc_out_l_START (0)
#define V860_CH14_ADC_L_ch14_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch14_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH14_ADC_H_UNION;
#endif
#define V860_CH14_ADC_H_ch14_adc_out_h_START (0)
#define V860_CH14_ADC_H_ch14_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch15_adc_out_l : 8;
    } reg;
} V860_CH15_ADC_L_UNION;
#endif
#define V860_CH15_ADC_L_ch15_adc_out_l_START (0)
#define V860_CH15_ADC_L_ch15_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ch15_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} V860_CH15_ADC_H_UNION;
#endif
#define V860_CH15_ADC_H_ch15_adc_out_h_START (0)
#define V860_CH15_ADC_H_ch15_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hk_clk_en : 1;
        unsigned char reserved : 7;
    } reg;
} V860_HKADC_CLK_EN_UNION;
#endif
#define V860_HKADC_CLK_EN_sc_hk_clk_en_START (0)
#define V860_HKADC_CLK_EN_sc_hk_clk_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_hkadc_tb_sel : 5;
        unsigned char reserved : 2;
        unsigned char sc_hkadc_tb_en : 1;
    } reg;
} V860_HKADC_TB_EN_SEL_UNION;
#endif
#define V860_HKADC_TB_EN_SEL_sc_hkadc_tb_sel_START (0)
#define V860_HKADC_TB_EN_SEL_sc_hkadc_tb_sel_END (4)
#define V860_HKADC_TB_EN_SEL_sc_hkadc_tb_en_START (7)
#define V860_HKADC_TB_EN_SEL_sc_hkadc_tb_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char hkadc_tb_bus_0 : 8;
    } reg;
} V860_HKADC_TB_DATA0_UNION;
#endif
#define V860_HKADC_TB_DATA0_hkadc_tb_bus_0_START (0)
#define V860_HKADC_TB_DATA0_hkadc_tb_bus_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char hkadc_tb_bus_1 : 8;
    } reg;
} V860_HKADC_TB_DATA1_UNION;
#endif
#define V860_HKADC_TB_DATA1_hkadc_tb_bus_1_START (0)
#define V860_HKADC_TB_DATA1_hkadc_tb_bus_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_group_others : 1;
        unsigned char irq_group_dc : 1;
        unsigned char irq_group_sc : 1;
        unsigned char irq_group_ovp : 1;
        unsigned char irq_group_res0 : 1;
        unsigned char irq_group_res1 : 1;
        unsigned char irq_group_res2 : 1;
        unsigned char irq_group_res3 : 1;
    } reg;
} V860_IRQ_FLAG_UNION;
#endif
#define V860_IRQ_FLAG_irq_group_others_START (0)
#define V860_IRQ_FLAG_irq_group_others_END (0)
#define V860_IRQ_FLAG_irq_group_dc_START (1)
#define V860_IRQ_FLAG_irq_group_dc_END (1)
#define V860_IRQ_FLAG_irq_group_sc_START (2)
#define V860_IRQ_FLAG_irq_group_sc_END (2)
#define V860_IRQ_FLAG_irq_group_ovp_START (3)
#define V860_IRQ_FLAG_irq_group_ovp_END (3)
#define V860_IRQ_FLAG_irq_group_res0_START (4)
#define V860_IRQ_FLAG_irq_group_res0_END (4)
#define V860_IRQ_FLAG_irq_group_res1_START (5)
#define V860_IRQ_FLAG_irq_group_res1_END (5)
#define V860_IRQ_FLAG_irq_group_res2_START (6)
#define V860_IRQ_FLAG_irq_group_res2_END (6)
#define V860_IRQ_FLAG_irq_group_res3_START (7)
#define V860_IRQ_FLAG_irq_group_res3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ovp_vusb_ovp : 1;
        unsigned char irq_ovp_pwron : 1;
        unsigned char irq_ovp_vbus_uvp : 1;
        unsigned char irq_ovp_res0 : 1;
        unsigned char irq_ovp_res1 : 1;
        unsigned char irq_ovp_res2 : 1;
        unsigned char irq_ovp_res3 : 1;
        unsigned char irq_ovp_res4 : 1;
    } reg;
} V860_IRQ_FLAG_0_UNION;
#endif
#define V860_IRQ_FLAG_0_irq_ovp_vusb_ovp_START (0)
#define V860_IRQ_FLAG_0_irq_ovp_vusb_ovp_END (0)
#define V860_IRQ_FLAG_0_irq_ovp_pwron_START (1)
#define V860_IRQ_FLAG_0_irq_ovp_pwron_END (1)
#define V860_IRQ_FLAG_0_irq_ovp_vbus_uvp_START (2)
#define V860_IRQ_FLAG_0_irq_ovp_vbus_uvp_END (2)
#define V860_IRQ_FLAG_0_irq_ovp_res0_START (3)
#define V860_IRQ_FLAG_0_irq_ovp_res0_END (3)
#define V860_IRQ_FLAG_0_irq_ovp_res1_START (4)
#define V860_IRQ_FLAG_0_irq_ovp_res1_END (4)
#define V860_IRQ_FLAG_0_irq_ovp_res2_START (5)
#define V860_IRQ_FLAG_0_irq_ovp_res2_END (5)
#define V860_IRQ_FLAG_0_irq_ovp_res3_START (6)
#define V860_IRQ_FLAG_0_irq_ovp_res3_END (6)
#define V860_IRQ_FLAG_0_irq_ovp_res4_START (7)
#define V860_IRQ_FLAG_0_irq_ovp_res4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_sc1_dsw_q7_ocp_pea : 1;
        unsigned char irq_sc1_dsw_q5_ocp_peak : 1;
        unsigned char irq_sc_q1_ocp_peak : 1;
        unsigned char irq_sc_vbat_ovp : 1;
        unsigned char irq_sc_vout_ovp : 1;
        unsigned char irq_sc_vbus_ovp : 1;
        unsigned char irq_tdie_otp : 1;
        unsigned char irq_tdie_otp_alarm : 1;
    } reg;
} V860_IRQ_FLAG_1_UNION;
#endif
#define V860_IRQ_FLAG_1_irq_sc1_dsw_q7_ocp_pea_START (0)
#define V860_IRQ_FLAG_1_irq_sc1_dsw_q7_ocp_pea_END (0)
#define V860_IRQ_FLAG_1_irq_sc1_dsw_q5_ocp_peak_START (1)
#define V860_IRQ_FLAG_1_irq_sc1_dsw_q5_ocp_peak_END (1)
#define V860_IRQ_FLAG_1_irq_sc_q1_ocp_peak_START (2)
#define V860_IRQ_FLAG_1_irq_sc_q1_ocp_peak_END (2)
#define V860_IRQ_FLAG_1_irq_sc_vbat_ovp_START (3)
#define V860_IRQ_FLAG_1_irq_sc_vbat_ovp_END (3)
#define V860_IRQ_FLAG_1_irq_sc_vout_ovp_START (4)
#define V860_IRQ_FLAG_1_irq_sc_vout_ovp_END (4)
#define V860_IRQ_FLAG_1_irq_sc_vbus_ovp_START (5)
#define V860_IRQ_FLAG_1_irq_sc_vbus_ovp_END (5)
#define V860_IRQ_FLAG_1_irq_tdie_otp_START (6)
#define V860_IRQ_FLAG_1_irq_tdie_otp_END (6)
#define V860_IRQ_FLAG_1_irq_tdie_otp_alarm_START (7)
#define V860_IRQ_FLAG_1_irq_tdie_otp_alarm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ibat_ocp : 1;
        unsigned char irq_ibus_rcp : 1;
        unsigned char irq_ibus_ucp : 1;
        unsigned char irq_ibus_ocp : 1;
        unsigned char irq_sc_vdrop_ovp : 1;
        unsigned char irq_sc_vdrop_min : 1;
        unsigned char irq_sc2_dsw_q7_ocp_peak : 1;
        unsigned char irq_sc2_dsw_q5_ocp_peak : 1;
    } reg;
} V860_IRQ_FLAG_2_UNION;
#endif
#define V860_IRQ_FLAG_2_irq_ibat_ocp_START (0)
#define V860_IRQ_FLAG_2_irq_ibat_ocp_END (0)
#define V860_IRQ_FLAG_2_irq_ibus_rcp_START (1)
#define V860_IRQ_FLAG_2_irq_ibus_rcp_END (1)
#define V860_IRQ_FLAG_2_irq_ibus_ucp_START (2)
#define V860_IRQ_FLAG_2_irq_ibus_ucp_END (2)
#define V860_IRQ_FLAG_2_irq_ibus_ocp_START (3)
#define V860_IRQ_FLAG_2_irq_ibus_ocp_END (3)
#define V860_IRQ_FLAG_2_irq_sc_vdrop_ovp_START (4)
#define V860_IRQ_FLAG_2_irq_sc_vdrop_ovp_END (4)
#define V860_IRQ_FLAG_2_irq_sc_vdrop_min_START (5)
#define V860_IRQ_FLAG_2_irq_sc_vdrop_min_END (5)
#define V860_IRQ_FLAG_2_irq_sc2_dsw_q7_ocp_peak_START (6)
#define V860_IRQ_FLAG_2_irq_sc2_dsw_q7_ocp_peak_END (6)
#define V860_IRQ_FLAG_2_irq_sc2_dsw_q5_ocp_peak_START (7)
#define V860_IRQ_FLAG_2_irq_sc2_dsw_q5_ocp_peak_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_dc_drop_min : 1;
        unsigned char irq_dc_drop_ovp : 1;
        unsigned char irq_vout_dc_ovp : 1;
        unsigned char irq_vusb_dc_ovp : 1;
        unsigned char irq_dc_pwron : 1;
        unsigned char irq_vusb_dc_uvp : 1;
        unsigned char irq_dc_res0 : 1;
        unsigned char irq_dc_res1 : 1;
    } reg;
} V860_IRQ_FLAG_3_UNION;
#endif
#define V860_IRQ_FLAG_3_irq_dc_drop_min_START (0)
#define V860_IRQ_FLAG_3_irq_dc_drop_min_END (0)
#define V860_IRQ_FLAG_3_irq_dc_drop_ovp_START (1)
#define V860_IRQ_FLAG_3_irq_dc_drop_ovp_END (1)
#define V860_IRQ_FLAG_3_irq_vout_dc_ovp_START (2)
#define V860_IRQ_FLAG_3_irq_vout_dc_ovp_END (2)
#define V860_IRQ_FLAG_3_irq_vusb_dc_ovp_START (3)
#define V860_IRQ_FLAG_3_irq_vusb_dc_ovp_END (3)
#define V860_IRQ_FLAG_3_irq_dc_pwron_START (4)
#define V860_IRQ_FLAG_3_irq_dc_pwron_END (4)
#define V860_IRQ_FLAG_3_irq_vusb_dc_uvp_START (5)
#define V860_IRQ_FLAG_3_irq_vusb_dc_uvp_END (5)
#define V860_IRQ_FLAG_3_irq_dc_res0_START (6)
#define V860_IRQ_FLAG_3_irq_dc_res0_END (6)
#define V860_IRQ_FLAG_3_irq_dc_res1_START (7)
#define V860_IRQ_FLAG_3_irq_dc_res1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_s2_cfly2_scp : 1;
        unsigned char irq_s2_cfly1_scp : 1;
        unsigned char irq_s1_cfly2_scp : 1;
        unsigned char irq_s1_cfly1_scp : 1;
        unsigned char irq_sc_wgt_tot : 1;
        unsigned char irq_others_res2 : 1;
        unsigned char irq_others_res3 : 1;
        unsigned char irq_others_res4 : 1;
    } reg;
} V860_IRQ_FLAG_4_UNION;
#endif
#define V860_IRQ_FLAG_4_irq_s2_cfly2_scp_START (0)
#define V860_IRQ_FLAG_4_irq_s2_cfly2_scp_END (0)
#define V860_IRQ_FLAG_4_irq_s2_cfly1_scp_START (1)
#define V860_IRQ_FLAG_4_irq_s2_cfly1_scp_END (1)
#define V860_IRQ_FLAG_4_irq_s1_cfly2_scp_START (2)
#define V860_IRQ_FLAG_4_irq_s1_cfly2_scp_END (2)
#define V860_IRQ_FLAG_4_irq_s1_cfly1_scp_START (3)
#define V860_IRQ_FLAG_4_irq_s1_cfly1_scp_END (3)
#define V860_IRQ_FLAG_4_irq_sc_wgt_tot_START (4)
#define V860_IRQ_FLAG_4_irq_sc_wgt_tot_END (4)
#define V860_IRQ_FLAG_4_irq_others_res2_START (5)
#define V860_IRQ_FLAG_4_irq_others_res2_END (5)
#define V860_IRQ_FLAG_4_irq_others_res3_START (6)
#define V860_IRQ_FLAG_4_irq_others_res3_END (6)
#define V860_IRQ_FLAG_4_irq_others_res4_START (7)
#define V860_IRQ_FLAG_4_irq_others_res4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_regn_ocp : 1;
        unsigned char irq_ldo33_scp : 1;
        unsigned char irq_reserved_0 : 1;
        unsigned char irq_reserved_1 : 1;
        unsigned char irq_reserved_2 : 1;
        unsigned char irq_reserved_3 : 1;
        unsigned char irq_others_res0 : 1;
        unsigned char irq_others_res1 : 1;
    } reg;
} V860_IRQ_FLAG_5_UNION;
#endif
#define V860_IRQ_FLAG_5_irq_regn_ocp_START (0)
#define V860_IRQ_FLAG_5_irq_regn_ocp_END (0)
#define V860_IRQ_FLAG_5_irq_ldo33_scp_START (1)
#define V860_IRQ_FLAG_5_irq_ldo33_scp_END (1)
#define V860_IRQ_FLAG_5_irq_reserved_0_START (2)
#define V860_IRQ_FLAG_5_irq_reserved_0_END (2)
#define V860_IRQ_FLAG_5_irq_reserved_1_START (3)
#define V860_IRQ_FLAG_5_irq_reserved_1_END (3)
#define V860_IRQ_FLAG_5_irq_reserved_2_START (4)
#define V860_IRQ_FLAG_5_irq_reserved_2_END (4)
#define V860_IRQ_FLAG_5_irq_reserved_3_START (5)
#define V860_IRQ_FLAG_5_irq_reserved_3_END (5)
#define V860_IRQ_FLAG_5_irq_others_res0_START (6)
#define V860_IRQ_FLAG_5_irq_others_res0_END (6)
#define V860_IRQ_FLAG_5_irq_others_res1_START (7)
#define V860_IRQ_FLAG_5_irq_others_res1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_group_others_mask : 1;
        unsigned char irq_group_dc_mask : 1;
        unsigned char irq_group_sc_mask : 1;
        unsigned char irq_group_ovp_mask : 1;
        unsigned char irq_group_res0_mask : 1;
        unsigned char irq_group_res1_mask : 1;
        unsigned char irq_group_res2_mask : 1;
        unsigned char irq_group_res3_mask : 1;
    } reg;
} V860_IRQ_MASK_UNION;
#endif
#define V860_IRQ_MASK_irq_group_others_mask_START (0)
#define V860_IRQ_MASK_irq_group_others_mask_END (0)
#define V860_IRQ_MASK_irq_group_dc_mask_START (1)
#define V860_IRQ_MASK_irq_group_dc_mask_END (1)
#define V860_IRQ_MASK_irq_group_sc_mask_START (2)
#define V860_IRQ_MASK_irq_group_sc_mask_END (2)
#define V860_IRQ_MASK_irq_group_ovp_mask_START (3)
#define V860_IRQ_MASK_irq_group_ovp_mask_END (3)
#define V860_IRQ_MASK_irq_group_res0_mask_START (4)
#define V860_IRQ_MASK_irq_group_res0_mask_END (4)
#define V860_IRQ_MASK_irq_group_res1_mask_START (5)
#define V860_IRQ_MASK_irq_group_res1_mask_END (5)
#define V860_IRQ_MASK_irq_group_res2_mask_START (6)
#define V860_IRQ_MASK_irq_group_res2_mask_END (6)
#define V860_IRQ_MASK_irq_group_res3_mask_START (7)
#define V860_IRQ_MASK_irq_group_res3_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ovp_vusb_ovp_mask : 1;
        unsigned char irq_ovp_pwron_mask : 1;
        unsigned char irq_ovp_vbus_uvp_mask : 1;
        unsigned char irq_ovp_res0_mask : 1;
        unsigned char irq_ovp_res1_mask : 1;
        unsigned char irq_ovp_res2_mask : 1;
        unsigned char irq_ovp_res3_mask : 1;
        unsigned char irq_ovp_res4_mask : 1;
    } reg;
} V860_IRQ_MASK_0_UNION;
#endif
#define V860_IRQ_MASK_0_irq_ovp_vusb_ovp_mask_START (0)
#define V860_IRQ_MASK_0_irq_ovp_vusb_ovp_mask_END (0)
#define V860_IRQ_MASK_0_irq_ovp_pwron_mask_START (1)
#define V860_IRQ_MASK_0_irq_ovp_pwron_mask_END (1)
#define V860_IRQ_MASK_0_irq_ovp_vbus_uvp_mask_START (2)
#define V860_IRQ_MASK_0_irq_ovp_vbus_uvp_mask_END (2)
#define V860_IRQ_MASK_0_irq_ovp_res0_mask_START (3)
#define V860_IRQ_MASK_0_irq_ovp_res0_mask_END (3)
#define V860_IRQ_MASK_0_irq_ovp_res1_mask_START (4)
#define V860_IRQ_MASK_0_irq_ovp_res1_mask_END (4)
#define V860_IRQ_MASK_0_irq_ovp_res2_mask_START (5)
#define V860_IRQ_MASK_0_irq_ovp_res2_mask_END (5)
#define V860_IRQ_MASK_0_irq_ovp_res3_mask_START (6)
#define V860_IRQ_MASK_0_irq_ovp_res3_mask_END (6)
#define V860_IRQ_MASK_0_irq_ovp_res4_mask_START (7)
#define V860_IRQ_MASK_0_irq_ovp_res4_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_sc1_dsw_q7_ocp_pea_mask : 1;
        unsigned char irq_sc1_dsw_q5_ocp_peak_mask : 1;
        unsigned char irq_sc_q1_ocp_peak_mask : 1;
        unsigned char irq_sc_vbat_ovp_mask : 1;
        unsigned char irq_sc_vout_ovp_mask : 1;
        unsigned char irq_sc_vbus_ovp_mask : 1;
        unsigned char irq_tdie_otp_mask : 1;
        unsigned char irq_tdie_otp_alarm_mask : 1;
    } reg;
} V860_IRQ_MASK_1_UNION;
#endif
#define V860_IRQ_MASK_1_irq_sc1_dsw_q7_ocp_pea_mask_START (0)
#define V860_IRQ_MASK_1_irq_sc1_dsw_q7_ocp_pea_mask_END (0)
#define V860_IRQ_MASK_1_irq_sc1_dsw_q5_ocp_peak_mask_START (1)
#define V860_IRQ_MASK_1_irq_sc1_dsw_q5_ocp_peak_mask_END (1)
#define V860_IRQ_MASK_1_irq_sc_q1_ocp_peak_mask_START (2)
#define V860_IRQ_MASK_1_irq_sc_q1_ocp_peak_mask_END (2)
#define V860_IRQ_MASK_1_irq_sc_vbat_ovp_mask_START (3)
#define V860_IRQ_MASK_1_irq_sc_vbat_ovp_mask_END (3)
#define V860_IRQ_MASK_1_irq_sc_vout_ovp_mask_START (4)
#define V860_IRQ_MASK_1_irq_sc_vout_ovp_mask_END (4)
#define V860_IRQ_MASK_1_irq_sc_vbus_ovp_mask_START (5)
#define V860_IRQ_MASK_1_irq_sc_vbus_ovp_mask_END (5)
#define V860_IRQ_MASK_1_irq_tdie_otp_mask_START (6)
#define V860_IRQ_MASK_1_irq_tdie_otp_mask_END (6)
#define V860_IRQ_MASK_1_irq_tdie_otp_alarm_mask_START (7)
#define V860_IRQ_MASK_1_irq_tdie_otp_alarm_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ibat_ocp_mask : 1;
        unsigned char irq_ibus_rcp_mask : 1;
        unsigned char irq_ibus_ucp_mask : 1;
        unsigned char irq_ibus_ocp_mask : 1;
        unsigned char irq_sc_vdrop_ovp_mask : 1;
        unsigned char irq_sc_vdrop_min_mask : 1;
        unsigned char irq_sc2_dsw_q7_ocp_peak_mask : 1;
        unsigned char irq_sc2_dsw_q5_ocp_peak_mask : 1;
    } reg;
} V860_IRQ_MASK_2_UNION;
#endif
#define V860_IRQ_MASK_2_irq_ibat_ocp_mask_START (0)
#define V860_IRQ_MASK_2_irq_ibat_ocp_mask_END (0)
#define V860_IRQ_MASK_2_irq_ibus_rcp_mask_START (1)
#define V860_IRQ_MASK_2_irq_ibus_rcp_mask_END (1)
#define V860_IRQ_MASK_2_irq_ibus_ucp_mask_START (2)
#define V860_IRQ_MASK_2_irq_ibus_ucp_mask_END (2)
#define V860_IRQ_MASK_2_irq_ibus_ocp_mask_START (3)
#define V860_IRQ_MASK_2_irq_ibus_ocp_mask_END (3)
#define V860_IRQ_MASK_2_irq_sc_vdrop_ovp_mask_START (4)
#define V860_IRQ_MASK_2_irq_sc_vdrop_ovp_mask_END (4)
#define V860_IRQ_MASK_2_irq_sc_vdrop_min_mask_START (5)
#define V860_IRQ_MASK_2_irq_sc_vdrop_min_mask_END (5)
#define V860_IRQ_MASK_2_irq_sc2_dsw_q7_ocp_peak_mask_START (6)
#define V860_IRQ_MASK_2_irq_sc2_dsw_q7_ocp_peak_mask_END (6)
#define V860_IRQ_MASK_2_irq_sc2_dsw_q5_ocp_peak_mask_START (7)
#define V860_IRQ_MASK_2_irq_sc2_dsw_q5_ocp_peak_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_dc_drop_min_mask : 1;
        unsigned char irq_dc_drop_ovp_mask : 1;
        unsigned char irq_vout_dc_ovp_mask : 1;
        unsigned char irq_vusb_dc_ovp_mask : 1;
        unsigned char irq_dc_pwron_mask : 1;
        unsigned char irq_vusb_dc_uvp_mask : 1;
        unsigned char irq_dc_res0_mask : 1;
        unsigned char irq_dc_res1_mask : 1;
    } reg;
} V860_IRQ_MASK_3_UNION;
#endif
#define V860_IRQ_MASK_3_irq_dc_drop_min_mask_START (0)
#define V860_IRQ_MASK_3_irq_dc_drop_min_mask_END (0)
#define V860_IRQ_MASK_3_irq_dc_drop_ovp_mask_START (1)
#define V860_IRQ_MASK_3_irq_dc_drop_ovp_mask_END (1)
#define V860_IRQ_MASK_3_irq_vout_dc_ovp_mask_START (2)
#define V860_IRQ_MASK_3_irq_vout_dc_ovp_mask_END (2)
#define V860_IRQ_MASK_3_irq_vusb_dc_ovp_mask_START (3)
#define V860_IRQ_MASK_3_irq_vusb_dc_ovp_mask_END (3)
#define V860_IRQ_MASK_3_irq_dc_pwron_mask_START (4)
#define V860_IRQ_MASK_3_irq_dc_pwron_mask_END (4)
#define V860_IRQ_MASK_3_irq_vusb_dc_uvp_mask_START (5)
#define V860_IRQ_MASK_3_irq_vusb_dc_uvp_mask_END (5)
#define V860_IRQ_MASK_3_irq_dc_res0_mask_START (6)
#define V860_IRQ_MASK_3_irq_dc_res0_mask_END (6)
#define V860_IRQ_MASK_3_irq_dc_res1_mask_START (7)
#define V860_IRQ_MASK_3_irq_dc_res1_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_s2_cfly2_scp_mask : 1;
        unsigned char irq_s2_cfly1_scp_mask : 1;
        unsigned char irq_s1_cfly2_scp_mask : 1;
        unsigned char irq_s1_cfly1_scp_mask : 1;
        unsigned char irq_sc_wgt_tot_mask : 1;
        unsigned char irq_others_res2_mask : 1;
        unsigned char irq_others_res3_mask : 1;
        unsigned char irq_others_res4_mask : 1;
    } reg;
} V860_IRQ_MASK_4_UNION;
#endif
#define V860_IRQ_MASK_4_irq_s2_cfly2_scp_mask_START (0)
#define V860_IRQ_MASK_4_irq_s2_cfly2_scp_mask_END (0)
#define V860_IRQ_MASK_4_irq_s2_cfly1_scp_mask_START (1)
#define V860_IRQ_MASK_4_irq_s2_cfly1_scp_mask_END (1)
#define V860_IRQ_MASK_4_irq_s1_cfly2_scp_mask_START (2)
#define V860_IRQ_MASK_4_irq_s1_cfly2_scp_mask_END (2)
#define V860_IRQ_MASK_4_irq_s1_cfly1_scp_mask_START (3)
#define V860_IRQ_MASK_4_irq_s1_cfly1_scp_mask_END (3)
#define V860_IRQ_MASK_4_irq_sc_wgt_tot_mask_START (4)
#define V860_IRQ_MASK_4_irq_sc_wgt_tot_mask_END (4)
#define V860_IRQ_MASK_4_irq_others_res2_mask_START (5)
#define V860_IRQ_MASK_4_irq_others_res2_mask_END (5)
#define V860_IRQ_MASK_4_irq_others_res3_mask_START (6)
#define V860_IRQ_MASK_4_irq_others_res3_mask_END (6)
#define V860_IRQ_MASK_4_irq_others_res4_mask_START (7)
#define V860_IRQ_MASK_4_irq_others_res4_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_regn_ocp_mask : 1;
        unsigned char irq_ldo33_scp_mask : 1;
        unsigned char irq_reserved_0_mask : 1;
        unsigned char irq_reserved_1_mask : 1;
        unsigned char irq_reserved_2_mask : 1;
        unsigned char irq_reserved_3_mask : 1;
        unsigned char irq_others_res0_mask : 1;
        unsigned char irq_others_res1_mask : 1;
    } reg;
} V860_IRQ_MASK_5_UNION;
#endif
#define V860_IRQ_MASK_5_irq_regn_ocp_mask_START (0)
#define V860_IRQ_MASK_5_irq_regn_ocp_mask_END (0)
#define V860_IRQ_MASK_5_irq_ldo33_scp_mask_START (1)
#define V860_IRQ_MASK_5_irq_ldo33_scp_mask_END (1)
#define V860_IRQ_MASK_5_irq_reserved_0_mask_START (2)
#define V860_IRQ_MASK_5_irq_reserved_0_mask_END (2)
#define V860_IRQ_MASK_5_irq_reserved_1_mask_START (3)
#define V860_IRQ_MASK_5_irq_reserved_1_mask_END (3)
#define V860_IRQ_MASK_5_irq_reserved_2_mask_START (4)
#define V860_IRQ_MASK_5_irq_reserved_2_mask_END (4)
#define V860_IRQ_MASK_5_irq_reserved_3_mask_START (5)
#define V860_IRQ_MASK_5_irq_reserved_3_mask_END (5)
#define V860_IRQ_MASK_5_irq_others_res0_mask_START (6)
#define V860_IRQ_MASK_5_irq_others_res0_mask_END (6)
#define V860_IRQ_MASK_5_irq_others_res1_mask_START (7)
#define V860_IRQ_MASK_5_irq_others_res1_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_irq_ovp_vusb_ovp : 1;
        unsigned char st_irq_ovp_pwron : 1;
        unsigned char st_irq_ovp_vbus_uvp : 1;
        unsigned char st_irq_ovp_res0 : 1;
        unsigned char st_irq_ovp_res1 : 1;
        unsigned char st_irq_ovp_res2 : 1;
        unsigned char st_irq_ovp_res3 : 1;
        unsigned char st_irq_ovp_res4 : 1;
    } reg;
} V860_IRQ_STATUS_0_UNION;
#endif
#define V860_IRQ_STATUS_0_st_irq_ovp_vusb_ovp_START (0)
#define V860_IRQ_STATUS_0_st_irq_ovp_vusb_ovp_END (0)
#define V860_IRQ_STATUS_0_st_irq_ovp_pwron_START (1)
#define V860_IRQ_STATUS_0_st_irq_ovp_pwron_END (1)
#define V860_IRQ_STATUS_0_st_irq_ovp_vbus_uvp_START (2)
#define V860_IRQ_STATUS_0_st_irq_ovp_vbus_uvp_END (2)
#define V860_IRQ_STATUS_0_st_irq_ovp_res0_START (3)
#define V860_IRQ_STATUS_0_st_irq_ovp_res0_END (3)
#define V860_IRQ_STATUS_0_st_irq_ovp_res1_START (4)
#define V860_IRQ_STATUS_0_st_irq_ovp_res1_END (4)
#define V860_IRQ_STATUS_0_st_irq_ovp_res2_START (5)
#define V860_IRQ_STATUS_0_st_irq_ovp_res2_END (5)
#define V860_IRQ_STATUS_0_st_irq_ovp_res3_START (6)
#define V860_IRQ_STATUS_0_st_irq_ovp_res3_END (6)
#define V860_IRQ_STATUS_0_st_irq_ovp_res4_START (7)
#define V860_IRQ_STATUS_0_st_irq_ovp_res4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_irq_sc1_dsw_q7_ocp_pea : 1;
        unsigned char st_irq_sc1_dsw_q5_ocp_peak : 1;
        unsigned char st_irq_sc_q1_ocp_peak : 1;
        unsigned char st_irq_sc_vbat_ovp : 1;
        unsigned char st_irq_sc_vout_ovp : 1;
        unsigned char st_irq_sc_vbus_ovp : 1;
        unsigned char st_irq_tdie_otp : 1;
        unsigned char st_irq_tdie_otp_alarm : 1;
    } reg;
} V860_IRQ_STATUS_1_UNION;
#endif
#define V860_IRQ_STATUS_1_st_irq_sc1_dsw_q7_ocp_pea_START (0)
#define V860_IRQ_STATUS_1_st_irq_sc1_dsw_q7_ocp_pea_END (0)
#define V860_IRQ_STATUS_1_st_irq_sc1_dsw_q5_ocp_peak_START (1)
#define V860_IRQ_STATUS_1_st_irq_sc1_dsw_q5_ocp_peak_END (1)
#define V860_IRQ_STATUS_1_st_irq_sc_q1_ocp_peak_START (2)
#define V860_IRQ_STATUS_1_st_irq_sc_q1_ocp_peak_END (2)
#define V860_IRQ_STATUS_1_st_irq_sc_vbat_ovp_START (3)
#define V860_IRQ_STATUS_1_st_irq_sc_vbat_ovp_END (3)
#define V860_IRQ_STATUS_1_st_irq_sc_vout_ovp_START (4)
#define V860_IRQ_STATUS_1_st_irq_sc_vout_ovp_END (4)
#define V860_IRQ_STATUS_1_st_irq_sc_vbus_ovp_START (5)
#define V860_IRQ_STATUS_1_st_irq_sc_vbus_ovp_END (5)
#define V860_IRQ_STATUS_1_st_irq_tdie_otp_START (6)
#define V860_IRQ_STATUS_1_st_irq_tdie_otp_END (6)
#define V860_IRQ_STATUS_1_st_irq_tdie_otp_alarm_START (7)
#define V860_IRQ_STATUS_1_st_irq_tdie_otp_alarm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_irq_ibat_ocp : 1;
        unsigned char st_irq_ibus_rcp : 1;
        unsigned char st_irq_ibus_ucp : 1;
        unsigned char st_irq_ibus_ocp : 1;
        unsigned char st_irq_sc_vdrop_ovp : 1;
        unsigned char st_irq_sc_vdrop_min : 1;
        unsigned char st_irq_sc2_dsw_q7_ocp_peak : 1;
        unsigned char st_irq_sc2_dsw_q5_ocp_peak : 1;
    } reg;
} V860_IRQ_STATUS_2_UNION;
#endif
#define V860_IRQ_STATUS_2_st_irq_ibat_ocp_START (0)
#define V860_IRQ_STATUS_2_st_irq_ibat_ocp_END (0)
#define V860_IRQ_STATUS_2_st_irq_ibus_rcp_START (1)
#define V860_IRQ_STATUS_2_st_irq_ibus_rcp_END (1)
#define V860_IRQ_STATUS_2_st_irq_ibus_ucp_START (2)
#define V860_IRQ_STATUS_2_st_irq_ibus_ucp_END (2)
#define V860_IRQ_STATUS_2_st_irq_ibus_ocp_START (3)
#define V860_IRQ_STATUS_2_st_irq_ibus_ocp_END (3)
#define V860_IRQ_STATUS_2_st_irq_sc_vdrop_ovp_START (4)
#define V860_IRQ_STATUS_2_st_irq_sc_vdrop_ovp_END (4)
#define V860_IRQ_STATUS_2_st_irq_sc_vdrop_min_START (5)
#define V860_IRQ_STATUS_2_st_irq_sc_vdrop_min_END (5)
#define V860_IRQ_STATUS_2_st_irq_sc2_dsw_q7_ocp_peak_START (6)
#define V860_IRQ_STATUS_2_st_irq_sc2_dsw_q7_ocp_peak_END (6)
#define V860_IRQ_STATUS_2_st_irq_sc2_dsw_q5_ocp_peak_START (7)
#define V860_IRQ_STATUS_2_st_irq_sc2_dsw_q5_ocp_peak_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_irq_dc_drop_min : 1;
        unsigned char st_irq_dc_drop_ovp : 1;
        unsigned char st_irq_vout_dc_ovp : 1;
        unsigned char st_irq_vusb_dc_ovp : 1;
        unsigned char st_irq_dc_pwron : 1;
        unsigned char st_irq_vusb_dc_uvp : 1;
        unsigned char st_irq_dc_res0 : 1;
        unsigned char st_irq_dc_res1 : 1;
    } reg;
} V860_IRQ_STATUS_3_UNION;
#endif
#define V860_IRQ_STATUS_3_st_irq_dc_drop_min_START (0)
#define V860_IRQ_STATUS_3_st_irq_dc_drop_min_END (0)
#define V860_IRQ_STATUS_3_st_irq_dc_drop_ovp_START (1)
#define V860_IRQ_STATUS_3_st_irq_dc_drop_ovp_END (1)
#define V860_IRQ_STATUS_3_st_irq_vout_dc_ovp_START (2)
#define V860_IRQ_STATUS_3_st_irq_vout_dc_ovp_END (2)
#define V860_IRQ_STATUS_3_st_irq_vusb_dc_ovp_START (3)
#define V860_IRQ_STATUS_3_st_irq_vusb_dc_ovp_END (3)
#define V860_IRQ_STATUS_3_st_irq_dc_pwron_START (4)
#define V860_IRQ_STATUS_3_st_irq_dc_pwron_END (4)
#define V860_IRQ_STATUS_3_st_irq_vusb_dc_uvp_START (5)
#define V860_IRQ_STATUS_3_st_irq_vusb_dc_uvp_END (5)
#define V860_IRQ_STATUS_3_st_irq_dc_res0_START (6)
#define V860_IRQ_STATUS_3_st_irq_dc_res0_END (6)
#define V860_IRQ_STATUS_3_st_irq_dc_res1_START (7)
#define V860_IRQ_STATUS_3_st_irq_dc_res1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_irq_s2_cfly2_scp : 1;
        unsigned char st_irq_s2_cfly1_scp : 1;
        unsigned char st_irq_s1_cfly2_scp : 1;
        unsigned char st_irq_s1_cfly1_scp : 1;
        unsigned char st_irq_sc_wgt_tot : 1;
        unsigned char st_irq_others_res2 : 1;
        unsigned char st_irq_others_res3 : 1;
        unsigned char st_irq_others_res4 : 1;
    } reg;
} V860_IRQ_STATUS_4_UNION;
#endif
#define V860_IRQ_STATUS_4_st_irq_s2_cfly2_scp_START (0)
#define V860_IRQ_STATUS_4_st_irq_s2_cfly2_scp_END (0)
#define V860_IRQ_STATUS_4_st_irq_s2_cfly1_scp_START (1)
#define V860_IRQ_STATUS_4_st_irq_s2_cfly1_scp_END (1)
#define V860_IRQ_STATUS_4_st_irq_s1_cfly2_scp_START (2)
#define V860_IRQ_STATUS_4_st_irq_s1_cfly2_scp_END (2)
#define V860_IRQ_STATUS_4_st_irq_s1_cfly1_scp_START (3)
#define V860_IRQ_STATUS_4_st_irq_s1_cfly1_scp_END (3)
#define V860_IRQ_STATUS_4_st_irq_sc_wgt_tot_START (4)
#define V860_IRQ_STATUS_4_st_irq_sc_wgt_tot_END (4)
#define V860_IRQ_STATUS_4_st_irq_others_res2_START (5)
#define V860_IRQ_STATUS_4_st_irq_others_res2_END (5)
#define V860_IRQ_STATUS_4_st_irq_others_res3_START (6)
#define V860_IRQ_STATUS_4_st_irq_others_res3_END (6)
#define V860_IRQ_STATUS_4_st_irq_others_res4_START (7)
#define V860_IRQ_STATUS_4_st_irq_others_res4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_irq_regn_ocp : 1;
        unsigned char st_irq_ldo33_scp : 1;
        unsigned char st_irq_reserved_0 : 1;
        unsigned char st_irq_reserved_1 : 1;
        unsigned char st_irq_reserved_2 : 1;
        unsigned char st_irq_reserved_3 : 1;
        unsigned char st_irq_others_res0 : 1;
        unsigned char st_irq_others_res1 : 1;
    } reg;
} V860_IRQ_STATUS_5_UNION;
#endif
#define V860_IRQ_STATUS_5_st_irq_regn_ocp_START (0)
#define V860_IRQ_STATUS_5_st_irq_regn_ocp_END (0)
#define V860_IRQ_STATUS_5_st_irq_ldo33_scp_START (1)
#define V860_IRQ_STATUS_5_st_irq_ldo33_scp_END (1)
#define V860_IRQ_STATUS_5_st_irq_reserved_0_START (2)
#define V860_IRQ_STATUS_5_st_irq_reserved_0_END (2)
#define V860_IRQ_STATUS_5_st_irq_reserved_1_START (3)
#define V860_IRQ_STATUS_5_st_irq_reserved_1_END (3)
#define V860_IRQ_STATUS_5_st_irq_reserved_2_START (4)
#define V860_IRQ_STATUS_5_st_irq_reserved_2_END (4)
#define V860_IRQ_STATUS_5_st_irq_reserved_3_START (5)
#define V860_IRQ_STATUS_5_st_irq_reserved_3_END (5)
#define V860_IRQ_STATUS_5_st_irq_others_res0_START (6)
#define V860_IRQ_STATUS_5_st_irq_others_res0_END (6)
#define V860_IRQ_STATUS_5_st_irq_others_res1_START (7)
#define V860_IRQ_STATUS_5_st_irq_others_res1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_ldo33_shield : 1;
        unsigned char da_dig_sync_test : 1;
        unsigned char reserved : 6;
    } reg;
} V860_SYS_LOGIC_CFG_REG_0_UNION;
#endif
#define V860_SYS_LOGIC_CFG_REG_0_da_ldo33_shield_START (0)
#define V860_SYS_LOGIC_CFG_REG_0_da_ldo33_shield_END (0)
#define V860_SYS_LOGIC_CFG_REG_0_da_dig_sync_test_START (1)
#define V860_SYS_LOGIC_CFG_REG_0_da_dig_sync_test_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sys_reserve0 : 8;
    } reg;
} V860_DS_SYS_RESERVE0_UNION;
#endif
#define V860_DS_SYS_RESERVE0_da_sys_reserve0_START (0)
#define V860_DS_SYS_RESERVE0_da_sys_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sys_reserve1 : 8;
    } reg;
} V860_SYS_LOGIC_CFG_REG_3_UNION;
#endif
#define V860_SYS_LOGIC_CFG_REG_3_da_sys_reserve1_START (0)
#define V860_SYS_LOGIC_CFG_REG_3_da_sys_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ad_sc_rdy : 1;
        unsigned char reserved : 7;
    } reg;
} V860_SC_TOP_RO_REG_0_UNION;
#endif
#define V860_SC_TOP_RO_REG_0_ad_sc_rdy_START (0)
#define V860_SC_TOP_RO_REG_0_ad_sc_rdy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_vout_sel : 1;
        unsigned char da_ldo33_en : 1;
        unsigned char reserved : 6;
    } reg;
} V860_DA_LDO33_EN_UNION;
#endif
#define V860_DA_LDO33_EN_da_sc_vout_sel_START (0)
#define V860_DA_LDO33_EN_da_sc_vout_sel_END (0)
#define V860_DA_LDO33_EN_da_ldo33_en_START (1)
#define V860_DA_LDO33_EN_da_ldo33_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sys_rev_efuse : 8;
    } reg;
} V860_SYS_LOGIC_CFG_REG_1_UNION;
#endif
#define V860_SYS_LOGIC_CFG_REG_1_da_sys_rev_efuse_START (0)
#define V860_SYS_LOGIC_CFG_REG_1_da_sys_rev_efuse_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_timer_test : 1;
        unsigned char reserved : 7;
    } reg;
} V860_SYS_LOGIC_CFG_REG_2_UNION;
#endif
#define V860_SYS_LOGIC_CFG_REG_2_da_timer_test_START (0)
#define V860_SYS_LOGIC_CFG_REG_2_da_timer_test_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ad_sys_reserve_ro : 8;
    } reg;
} V860_SYS_LOGIC_RO_REG_4_UNION;
#endif
#define V860_SYS_LOGIC_RO_REG_4_ad_sys_reserve_ro_START (0)
#define V860_SYS_LOGIC_RO_REG_4_ad_sys_reserve_ro_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_osc_test_mode : 2;
        unsigned char reserved : 6;
    } reg;
} V860_OSC_TOP_CFG_REG_0_UNION;
#endif
#define V860_OSC_TOP_CFG_REG_0_da_osc_test_mode_START (0)
#define V860_OSC_TOP_CFG_REG_0_da_osc_test_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_ref_selgate_en : 1;
        unsigned char da_ref_fakeload : 1;
        unsigned char da_ref_clk_chop_sel : 2;
        unsigned char da_ref_chop_en : 1;
        unsigned char da_otp_en : 1;
        unsigned char da_otp_alm_en : 1;
        unsigned char reserved : 1;
    } reg;
} V860_REF_TOP_CFG_REG_0_UNION;
#endif
#define V860_REF_TOP_CFG_REG_0_da_ref_selgate_en_START (0)
#define V860_REF_TOP_CFG_REG_0_da_ref_selgate_en_END (0)
#define V860_REF_TOP_CFG_REG_0_da_ref_fakeload_START (1)
#define V860_REF_TOP_CFG_REG_0_da_ref_fakeload_END (1)
#define V860_REF_TOP_CFG_REG_0_da_ref_clk_chop_sel_START (2)
#define V860_REF_TOP_CFG_REG_0_da_ref_clk_chop_sel_END (3)
#define V860_REF_TOP_CFG_REG_0_da_ref_chop_en_START (4)
#define V860_REF_TOP_CFG_REG_0_da_ref_chop_en_END (4)
#define V860_REF_TOP_CFG_REG_0_da_otp_en_START (5)
#define V860_REF_TOP_CFG_REG_0_da_otp_en_END (5)
#define V860_REF_TOP_CFG_REG_0_da_otp_alm_en_START (6)
#define V860_REF_TOP_CFG_REG_0_da_otp_alm_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_ref_vbgout_en : 1;
        unsigned char da_ref_trim_en : 1;
        unsigned char da_ref_testib_en : 1;
        unsigned char da_ref_testbg_en : 1;
        unsigned char da_ref_test_mode : 4;
    } reg;
} V860_REF_TOP_CFG_REG_1_UNION;
#endif
#define V860_REF_TOP_CFG_REG_1_da_ref_vbgout_en_START (0)
#define V860_REF_TOP_CFG_REG_1_da_ref_vbgout_en_END (0)
#define V860_REF_TOP_CFG_REG_1_da_ref_trim_en_START (1)
#define V860_REF_TOP_CFG_REG_1_da_ref_trim_en_END (1)
#define V860_REF_TOP_CFG_REG_1_da_ref_testib_en_START (2)
#define V860_REF_TOP_CFG_REG_1_da_ref_testib_en_END (2)
#define V860_REF_TOP_CFG_REG_1_da_ref_testbg_en_START (3)
#define V860_REF_TOP_CFG_REG_1_da_ref_testbg_en_END (3)
#define V860_REF_TOP_CFG_REG_1_da_ref_test_mode_START (4)
#define V860_REF_TOP_CFG_REG_1_da_ref_test_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_tdie_otp_set : 2;
        unsigned char da_tdie_otp_alm_set : 2;
        unsigned char da_tdie_otp_adj : 2;
        unsigned char da_ref_vrc_en : 1;
        unsigned char reserved : 1;
    } reg;
} V860_REF_TOP_CFG_REG_2_UNION;
#endif
#define V860_REF_TOP_CFG_REG_2_da_tdie_otp_set_START (0)
#define V860_REF_TOP_CFG_REG_2_da_tdie_otp_set_END (1)
#define V860_REF_TOP_CFG_REG_2_da_tdie_otp_alm_set_START (2)
#define V860_REF_TOP_CFG_REG_2_da_tdie_otp_alm_set_END (3)
#define V860_REF_TOP_CFG_REG_2_da_tdie_otp_adj_START (4)
#define V860_REF_TOP_CFG_REG_2_da_tdie_otp_adj_END (5)
#define V860_REF_TOP_CFG_REG_2_da_ref_vrc_en_START (6)
#define V860_REF_TOP_CFG_REG_2_da_ref_vrc_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_drvq2f : 2;
        unsigned char da_sc_drvq1r : 2;
        unsigned char da_sc_drvq1f : 2;
        unsigned char da_sc_cfly_pd_mask : 1;
        unsigned char reserved : 1;
    } reg;
} V860_SC_TOP_CFG_REG_0_UNION;
#endif
#define V860_SC_TOP_CFG_REG_0_da_sc_drvq2f_START (0)
#define V860_SC_TOP_CFG_REG_0_da_sc_drvq2f_END (1)
#define V860_SC_TOP_CFG_REG_0_da_sc_drvq1r_START (2)
#define V860_SC_TOP_CFG_REG_0_da_sc_drvq1r_END (3)
#define V860_SC_TOP_CFG_REG_0_da_sc_drvq1f_START (4)
#define V860_SC_TOP_CFG_REG_0_da_sc_drvq1f_END (5)
#define V860_SC_TOP_CFG_REG_0_da_sc_cfly_pd_mask_START (6)
#define V860_SC_TOP_CFG_REG_0_da_sc_cfly_pd_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_drvq4f : 2;
        unsigned char da_sc_drvq3r : 2;
        unsigned char da_sc_drvq3f : 2;
        unsigned char da_sc_drvq2r : 2;
    } reg;
} V860_SC_TOP_CFG_REG_1_UNION;
#endif
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq4f_START (0)
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq4f_END (1)
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq3r_START (2)
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq3r_END (3)
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq3f_START (4)
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq3f_END (5)
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq2r_START (6)
#define V860_SC_TOP_CFG_REG_1_da_sc_drvq2r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_drvq6f : 2;
        unsigned char da_sc_drvq5r : 2;
        unsigned char da_sc_drvq5f : 2;
        unsigned char da_sc_drvq4r : 2;
    } reg;
} V860_SC_TOP_CFG_REG_2_UNION;
#endif
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq6f_START (0)
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq6f_END (1)
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq5r_START (2)
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq5r_END (3)
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq5f_START (4)
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq5f_END (5)
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq4r_START (6)
#define V860_SC_TOP_CFG_REG_2_da_sc_drvq4r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_freq_random_en : 1;
        unsigned char da_sc_fd_en_delay_sel : 1;
        unsigned char da_sc_drvq7r : 2;
        unsigned char da_sc_drvq7f : 2;
        unsigned char da_sc_drvq6r : 2;
    } reg;
} V860_SC_TOP_CFG_REG_3_UNION;
#endif
#define V860_SC_TOP_CFG_REG_3_da_sc_freq_random_en_START (0)
#define V860_SC_TOP_CFG_REG_3_da_sc_freq_random_en_END (0)
#define V860_SC_TOP_CFG_REG_3_da_sc_fd_en_delay_sel_START (1)
#define V860_SC_TOP_CFG_REG_3_da_sc_fd_en_delay_sel_END (1)
#define V860_SC_TOP_CFG_REG_3_da_sc_drvq7r_START (2)
#define V860_SC_TOP_CFG_REG_3_da_sc_drvq7r_END (3)
#define V860_SC_TOP_CFG_REG_3_da_sc_drvq7f_START (4)
#define V860_SC_TOP_CFG_REG_3_da_sc_drvq7f_END (5)
#define V860_SC_TOP_CFG_REG_3_da_sc_drvq6r_START (6)
#define V860_SC_TOP_CFG_REG_3_da_sc_drvq6r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_hs_fd_sel : 3;
        unsigned char da_sc_freq_sel : 3;
        unsigned char da_sc_freq_random_sel : 2;
    } reg;
} V860_SC_TOP_CFG_REG_4_UNION;
#endif
#define V860_SC_TOP_CFG_REG_4_da_sc_hs_fd_sel_START (0)
#define V860_SC_TOP_CFG_REG_4_da_sc_hs_fd_sel_END (2)
#define V860_SC_TOP_CFG_REG_4_da_sc_freq_sel_START (3)
#define V860_SC_TOP_CFG_REG_4_da_sc_freq_sel_END (5)
#define V860_SC_TOP_CFG_REG_4_da_sc_freq_random_sel_START (6)
#define V860_SC_TOP_CFG_REG_4_da_sc_freq_random_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reserved : 1;
        unsigned char da_sc_lvc_bstchg_sel : 2;
        unsigned char da_sc_lvc_bst_res : 2;
        unsigned char da_sc_ls_fd_sel : 3;
    } reg;
} V860_SC_TOP_CFG_REG_5_UNION;
#endif
#define V860_SC_TOP_CFG_REG_5_da_sc_lvc_bstchg_sel_START (1)
#define V860_SC_TOP_CFG_REG_5_da_sc_lvc_bstchg_sel_END (2)
#define V860_SC_TOP_CFG_REG_5_da_sc_lvc_bst_res_START (3)
#define V860_SC_TOP_CFG_REG_5_da_sc_lvc_bst_res_END (4)
#define V860_SC_TOP_CFG_REG_5_da_sc_ls_fd_sel_START (5)
#define V860_SC_TOP_CFG_REG_5_da_sc_ls_fd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_pwr_ts : 2;
        unsigned char reserved : 6;
    } reg;
} V860_SC_TOP_CFG_REG_6_UNION;
#endif
#define V860_SC_TOP_CFG_REG_6_da_sc_pwr_ts_START (0)
#define V860_SC_TOP_CFG_REG_6_da_sc_pwr_ts_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_reserve0 : 8;
    } reg;
} V860_SC_TOP_CFG_REG_7_UNION;
#endif
#define V860_SC_TOP_CFG_REG_7_da_sc_reserve0_START (0)
#define V860_SC_TOP_CFG_REG_7_da_sc_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_reserve1 : 8;
    } reg;
} V860_SC_TOP_CFG_REG_8_UNION;
#endif
#define V860_SC_TOP_CFG_REG_8_da_sc_reserve1_START (0)
#define V860_SC_TOP_CFG_REG_8_da_sc_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_reserve2 : 8;
    } reg;
} V860_SC_TOP_CFG_REG_9_UNION;
#endif
#define V860_SC_TOP_CFG_REG_9_da_sc_reserve2_START (0)
#define V860_SC_TOP_CFG_REG_9_da_sc_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_reserve3 : 8;
    } reg;
} V860_SC_TOP_CFG_REG_10_UNION;
#endif
#define V860_SC_TOP_CFG_REG_10_da_sc_reserve3_START (0)
#define V860_SC_TOP_CFG_REG_10_da_sc_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_reserve4 : 8;
    } reg;
} V860_SC_TOP_CFG_REG_11_UNION;
#endif
#define V860_SC_TOP_CFG_REG_11_da_sc_reserve4_START (0)
#define V860_SC_TOP_CFG_REG_11_da_sc_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_reserve5 : 8;
    } reg;
} V860_SC_TOP_CFG_REG_12_UNION;
#endif
#define V860_SC_TOP_CFG_REG_12_da_sc_reserve5_START (0)
#define V860_SC_TOP_CFG_REG_12_da_sc_reserve5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_reserve6 : 8;
    } reg;
} V860_SC_TOP_CFG_REG_13_UNION;
#endif
#define V860_SC_TOP_CFG_REG_13_da_sc_reserve6_START (0)
#define V860_SC_TOP_CFG_REG_13_da_sc_reserve6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_ts_mod : 1;
        unsigned char da_sc_ss_cf2_st_sel : 2;
        unsigned char da_sc_ss_cf1_st_sel : 2;
        unsigned char da_sc_ss_bps_st_sel : 2;
        unsigned char reserved : 1;
    } reg;
} V860_SC_TOP_CFG_REG_14_UNION;
#endif
#define V860_SC_TOP_CFG_REG_14_da_sc_ts_mod_START (0)
#define V860_SC_TOP_CFG_REG_14_da_sc_ts_mod_END (0)
#define V860_SC_TOP_CFG_REG_14_da_sc_ss_cf2_st_sel_START (1)
#define V860_SC_TOP_CFG_REG_14_da_sc_ss_cf2_st_sel_END (2)
#define V860_SC_TOP_CFG_REG_14_da_sc_ss_cf1_st_sel_START (3)
#define V860_SC_TOP_CFG_REG_14_da_sc_ss_cf1_st_sel_END (4)
#define V860_SC_TOP_CFG_REG_14_da_sc_ss_bps_st_sel_START (5)
#define V860_SC_TOP_CFG_REG_14_da_sc_ss_bps_st_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_ts_pathb : 1;
        unsigned char da_sc_ts_patha : 1;
        unsigned char da_sc_ts_muxselb : 3;
        unsigned char da_sc_ts_muxsela : 3;
    } reg;
} V860_SC_TOP_CFG_REG_15_UNION;
#endif
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_pathb_START (0)
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_pathb_END (0)
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_patha_START (1)
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_patha_END (1)
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_muxselb_START (2)
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_muxselb_END (4)
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_muxsela_START (5)
#define V860_SC_TOP_CFG_REG_15_da_sc_ts_muxsela_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_hkadc_ibias_sel : 8;
    } reg;
} V860_ADC_CFG_REG_1_UNION;
#endif
#define V860_ADC_CFG_REG_1_da_hkadc_ibias_sel_START (0)
#define V860_ADC_CFG_REG_1_da_hkadc_ibias_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_hkadc_reset : 1;
        unsigned char da_hkadc_reserved : 4;
        unsigned char da_hkadc_ibsel : 3;
    } reg;
} V860_ADC_CFG_REG_2_UNION;
#endif
#define V860_ADC_CFG_REG_2_da_hkadc_reset_START (0)
#define V860_ADC_CFG_REG_2_da_hkadc_reset_END (0)
#define V860_ADC_CFG_REG_2_da_hkadc_reserved_START (1)
#define V860_ADC_CFG_REG_2_da_hkadc_reserved_END (4)
#define V860_ADC_CFG_REG_2_da_hkadc_ibsel_START (5)
#define V860_ADC_CFG_REG_2_da_hkadc_ibsel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_hkadc_buffer_sel : 1;
        unsigned char reserved : 7;
    } reg;
} V860_ADC_CFG_REG_3_UNION;
#endif
#define V860_ADC_CFG_REG_3_da_hkadc_buffer_sel_START (0)
#define V860_ADC_CFG_REG_3_da_hkadc_buffer_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ad_hkadc_data_0 : 8;
    } reg;
} V860_ADC_RO_REG_4_UNION;
#endif
#define V860_ADC_RO_REG_4_ad_hkadc_data_0_START (0)
#define V860_ADC_RO_REG_4_ad_hkadc_data_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ad_hkadc_data_1 : 4;
        unsigned char reserved : 4;
    } reg;
} V860_ADC_RO_REG_5_UNION;
#endif
#define V860_ADC_RO_REG_5_ad_hkadc_data_1_START (0)
#define V860_ADC_RO_REG_5_ad_hkadc_data_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_usb_ovp_pro_en : 1;
        unsigned char da_usb_ovp_ichg_sel : 2;
        unsigned char da_usb_ovp_dt_sel : 1;
        unsigned char reserved : 4;
    } reg;
} V860_USB_OVP_CFG_REG_0_UNION;
#endif
#define V860_USB_OVP_CFG_REG_0_da_usb_ovp_pro_en_START (0)
#define V860_USB_OVP_CFG_REG_0_da_usb_ovp_pro_en_END (0)
#define V860_USB_OVP_CFG_REG_0_da_usb_ovp_ichg_sel_START (1)
#define V860_USB_OVP_CFG_REG_0_da_usb_ovp_ichg_sel_END (2)
#define V860_USB_OVP_CFG_REG_0_da_usb_ovp_dt_sel_START (3)
#define V860_USB_OVP_CFG_REG_0_da_usb_ovp_dt_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_usb_ovp_resved : 8;
    } reg;
} V860_USB_OVP_CFG_REG_1_UNION;
#endif
#define V860_USB_OVP_CFG_REG_1_da_usb_ovp_resved_START (0)
#define V860_USB_OVP_CFG_REG_1_da_usb_ovp_resved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_usb_uvlo_en : 1;
        unsigned char da_usb_ovpsub_pd_enb : 1;
        unsigned char da_usb_ovp_test_md : 1;
        unsigned char da_usb_ovp_shdn_dt_sel : 1;
        unsigned char da_usb_ovp_set : 3;
        unsigned char reserved : 1;
    } reg;
} V860_USB_OVP_CFG_REG_2_UNION;
#endif
#define V860_USB_OVP_CFG_REG_2_da_usb_uvlo_en_START (0)
#define V860_USB_OVP_CFG_REG_2_da_usb_uvlo_en_END (0)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovpsub_pd_enb_START (1)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovpsub_pd_enb_END (1)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovp_test_md_START (2)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovp_test_md_END (2)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovp_shdn_dt_sel_START (3)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovp_shdn_dt_sel_END (3)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovp_set_START (4)
#define V860_USB_OVP_CFG_REG_2_da_usb_ovp_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_dropovp_ovpsub_pd_enb : 1;
        unsigned char da_dropmin_ovp1_set : 2;
        unsigned char da_dropmin_ovp_dt_sel : 2;
        unsigned char da_cp_clk_sel : 2;
        unsigned char reserved : 1;
    } reg;
} V860_OVP1_CFG_REG_0_UNION;
#endif
#define V860_OVP1_CFG_REG_0_da_dropovp_ovpsub_pd_enb_START (0)
#define V860_OVP1_CFG_REG_0_da_dropovp_ovpsub_pd_enb_END (0)
#define V860_OVP1_CFG_REG_0_da_dropmin_ovp1_set_START (1)
#define V860_OVP1_CFG_REG_0_da_dropmin_ovp1_set_END (2)
#define V860_OVP1_CFG_REG_0_da_dropmin_ovp_dt_sel_START (3)
#define V860_OVP1_CFG_REG_0_da_dropmin_ovp_dt_sel_END (4)
#define V860_OVP1_CFG_REG_0_da_cp_clk_sel_START (5)
#define V860_OVP1_CFG_REG_0_da_cp_clk_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_usb_dropovp_en : 1;
        unsigned char da_usb_dropmin_ovp_en : 1;
        unsigned char da_psw_ovp_ichg_sel : 2;
        unsigned char da_dropovp1_sel : 2;
        unsigned char da_dropovp_shdn_dt_sel : 1;
        unsigned char reserved : 1;
    } reg;
} V860_OVP1_CFG_REG_1_UNION;
#endif
#define V860_OVP1_CFG_REG_1_da_usb_dropovp_en_START (0)
#define V860_OVP1_CFG_REG_1_da_usb_dropovp_en_END (0)
#define V860_OVP1_CFG_REG_1_da_usb_dropmin_ovp_en_START (1)
#define V860_OVP1_CFG_REG_1_da_usb_dropmin_ovp_en_END (1)
#define V860_OVP1_CFG_REG_1_da_psw_ovp_ichg_sel_START (2)
#define V860_OVP1_CFG_REG_1_da_psw_ovp_ichg_sel_END (3)
#define V860_OVP1_CFG_REG_1_da_dropovp1_sel_START (4)
#define V860_OVP1_CFG_REG_1_da_dropovp1_sel_END (5)
#define V860_OVP1_CFG_REG_1_da_dropovp_shdn_dt_sel_START (6)
#define V860_OVP1_CFG_REG_1_da_dropovp_shdn_dt_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_usb_dropovp_resved : 8;
    } reg;
} V860_OVP1_CFG_REG_2_UNION;
#endif
#define V860_OVP1_CFG_REG_2_da_usb_dropovp_resved_START (0)
#define V860_OVP1_CFG_REG_2_da_usb_dropovp_resved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_vdrop_ovp_dt_sel : 2;
        unsigned char da_vbat_dropmin_trim : 4;
        unsigned char da_usb_ovp1_ovp_set : 2;
    } reg;
} V860_OVP1_CFG_REG_3_UNION;
#endif
#define V860_OVP1_CFG_REG_3_da_vdrop_ovp_dt_sel_START (0)
#define V860_OVP1_CFG_REG_3_da_vdrop_ovp_dt_sel_END (1)
#define V860_OVP1_CFG_REG_3_da_vbat_dropmin_trim_START (2)
#define V860_OVP1_CFG_REG_3_da_vbat_dropmin_trim_END (5)
#define V860_OVP1_CFG_REG_3_da_usb_ovp1_ovp_set_START (6)
#define V860_OVP1_CFG_REG_3_da_usb_ovp1_ovp_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_vusb_dc_uvp_en : 1;
        unsigned char da_vusb_dc_ovp_en : 1;
        unsigned char da_vout_ovp1_ovp_set : 2;
        unsigned char da_vout_ovp1_dt_sel : 2;
        unsigned char da_vout_dc_ovp_en : 1;
        unsigned char reserved : 1;
    } reg;
} V860_OVP1_CFG_REG_4_UNION;
#endif
#define V860_OVP1_CFG_REG_4_da_vusb_dc_uvp_en_START (0)
#define V860_OVP1_CFG_REG_4_da_vusb_dc_uvp_en_END (0)
#define V860_OVP1_CFG_REG_4_da_vusb_dc_ovp_en_START (1)
#define V860_OVP1_CFG_REG_4_da_vusb_dc_ovp_en_END (1)
#define V860_OVP1_CFG_REG_4_da_vout_ovp1_ovp_set_START (2)
#define V860_OVP1_CFG_REG_4_da_vout_ovp1_ovp_set_END (3)
#define V860_OVP1_CFG_REG_4_da_vout_ovp1_dt_sel_START (4)
#define V860_OVP1_CFG_REG_4_da_vout_ovp1_dt_sel_END (5)
#define V860_OVP1_CFG_REG_4_da_vout_dc_ovp_en_START (6)
#define V860_OVP1_CFG_REG_4_da_vout_dc_ovp_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_fwd_vbat2_ovp_dbt : 1;
        unsigned char da_fwd_vbat1_ovp_sel : 3;
        unsigned char da_fwd_vbat1_ovp_en : 1;
        unsigned char da_fwd_vbat1_ovp_dbt : 1;
        unsigned char da_adc_det_sel : 1;
        unsigned char da_adc_det_psechop_en : 1;
    } reg;
} V860_SC_DET_TOP_CFG_REG_0_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat2_ovp_dbt_START (0)
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat2_ovp_dbt_END (0)
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat1_ovp_sel_START (1)
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat1_ovp_sel_END (3)
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat1_ovp_en_START (4)
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat1_ovp_en_END (4)
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat1_ovp_dbt_START (5)
#define V860_SC_DET_TOP_CFG_REG_0_da_fwd_vbat1_ovp_dbt_END (5)
#define V860_SC_DET_TOP_CFG_REG_0_da_adc_det_sel_START (6)
#define V860_SC_DET_TOP_CFG_REG_0_da_adc_det_sel_END (6)
#define V860_SC_DET_TOP_CFG_REG_0_da_adc_det_psechop_en_START (7)
#define V860_SC_DET_TOP_CFG_REG_0_da_adc_det_psechop_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_rvs_vout_uvlo_en : 1;
        unsigned char da_fwd_vbus_uvp_en : 1;
        unsigned char da_fwd_vbus_uvp_4xsc_sel : 1;
        unsigned char da_fwd_vbus_uvp_2xsc_sel : 1;
        unsigned char da_fwd_vbus_uvlo_fall_tdt : 1;
        unsigned char da_fwd_vbus_uvlo_en : 1;
        unsigned char reserved : 2;
    } reg;
} V860_SC_DET_TOP_CFG_REG_1_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_1_da_rvs_vout_uvlo_en_START (0)
#define V860_SC_DET_TOP_CFG_REG_1_da_rvs_vout_uvlo_en_END (0)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvp_en_START (1)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvp_en_END (1)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvp_4xsc_sel_START (2)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvp_4xsc_sel_END (2)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvp_2xsc_sel_START (3)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvp_2xsc_sel_END (3)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvlo_fall_tdt_START (4)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvlo_fall_tdt_END (4)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvlo_en_START (5)
#define V860_SC_DET_TOP_CFG_REG_1_da_fwd_vbus_uvlo_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_det_reserve0 : 8;
    } reg;
} V860_SC_DET_TOP_CFG_REG_2_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_2_da_sc_det_reserve0_START (0)
#define V860_SC_DET_TOP_CFG_REG_2_da_sc_det_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_det_reserve1 : 8;
    } reg;
} V860_SC_DET_TOP_CFG_REG_3_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_3_da_sc_det_reserve1_START (0)
#define V860_SC_DET_TOP_CFG_REG_3_da_sc_det_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_det_reserve2 : 8;
    } reg;
} V860_SC_DET_TOP_CFG_REG_4_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_4_da_sc_det_reserve2_START (0)
#define V860_SC_DET_TOP_CFG_REG_4_da_sc_det_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_vbus_ovp_en : 1;
        unsigned char da_sc_vbus_nf_mask : 1;
        unsigned char da_sc_drop_ovp_sel : 2;
        unsigned char da_sc_drop_ovp_dt_sel : 1;
        unsigned char da_sc_drop_min_sel : 2;
        unsigned char da_sc_drop_min_dt_sel : 1;
    } reg;
} V860_SC_DET_TOP_CFG_REG_5_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_vbus_ovp_en_START (0)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_vbus_ovp_en_END (0)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_vbus_nf_mask_START (1)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_vbus_nf_mask_END (1)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_ovp_sel_START (2)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_ovp_sel_END (3)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_ovp_dt_sel_START (4)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_ovp_dt_sel_END (4)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_min_sel_START (5)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_min_sel_END (6)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_min_dt_sel_START (7)
#define V860_SC_DET_TOP_CFG_REG_5_da_sc_drop_min_dt_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_vout_ovp_en : 1;
        unsigned char da_sc_vout_ovp_dbt : 1;
        unsigned char da_sc_vbus_plugout_en : 1;
        unsigned char da_sc_vbus_plugin_en : 1;
        unsigned char da_sc_vbus_ovp_fbps_sel : 1;
        unsigned char da_sc_vbus_ovp_f41sc_sel : 1;
        unsigned char da_sc_vbus_ovp_f21sc_sel : 1;
        unsigned char reserved : 1;
    } reg;
} V860_SC_DET_TOP_CFG_REG_6_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vout_ovp_en_START (0)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vout_ovp_en_END (0)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vout_ovp_dbt_START (1)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vout_ovp_dbt_END (1)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_plugout_en_START (2)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_plugout_en_END (2)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_plugin_en_START (3)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_plugin_en_END (3)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_ovp_fbps_sel_START (4)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_ovp_fbps_sel_END (4)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_ovp_f41sc_sel_START (5)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_ovp_f41sc_sel_END (5)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_ovp_f21sc_sel_START (6)
#define V860_SC_DET_TOP_CFG_REG_6_da_sc_vbus_ovp_f21sc_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_vout_ovp_sel : 2;
        unsigned char reserved : 6;
    } reg;
} V860_SC_DET_TOP_CFG_REG_7_UNION;
#endif
#define V860_SC_DET_TOP_CFG_REG_7_da_sc_vout_ovp_sel_START (0)
#define V860_SC_DET_TOP_CFG_REG_7_da_sc_vout_ovp_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_vbus_pulldown : 1;
        unsigned char da_rev_md_pro_enb : 1;
        unsigned char reserved : 6;
    } reg;
} V860_BLK_TOP_CFG_REG_0_UNION;
#endif
#define V860_BLK_TOP_CFG_REG_0_da_vbus_pulldown_START (0)
#define V860_BLK_TOP_CFG_REG_0_da_vbus_pulldown_END (0)
#define V860_BLK_TOP_CFG_REG_0_da_rev_md_pro_enb_START (1)
#define V860_BLK_TOP_CFG_REG_0_da_rev_md_pro_enb_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_efuse_aen_sel : 1;
        unsigned char reserved : 7;
    } reg;
} V860_EFUSE_IO_CFG_REG_0_UNION;
#endif
#define V860_EFUSE_IO_CFG_REG_0_da_efuse_aen_sel_START (0)
#define V860_EFUSE_IO_CFG_REG_0_da_efuse_aen_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_ibat_ocp_dbt : 1;
        unsigned char da_sc_ibat_ocp_chopper_en : 1;
        unsigned char da_s2_cfly2_scp_en : 1;
        unsigned char da_s2_cfly1_scp_en : 1;
        unsigned char da_s1_cfly2_scp_en : 1;
        unsigned char da_s1_cfly1_scp_en : 1;
        unsigned char da_bat_res_sel : 2;
    } reg;
} V860_SC_PRO_CFG_REG_0_UNION;
#endif
#define V860_SC_PRO_CFG_REG_0_da_sc_ibat_ocp_dbt_START (0)
#define V860_SC_PRO_CFG_REG_0_da_sc_ibat_ocp_dbt_END (0)
#define V860_SC_PRO_CFG_REG_0_da_sc_ibat_ocp_chopper_en_START (1)
#define V860_SC_PRO_CFG_REG_0_da_sc_ibat_ocp_chopper_en_END (1)
#define V860_SC_PRO_CFG_REG_0_da_s2_cfly2_scp_en_START (2)
#define V860_SC_PRO_CFG_REG_0_da_s2_cfly2_scp_en_END (2)
#define V860_SC_PRO_CFG_REG_0_da_s2_cfly1_scp_en_START (3)
#define V860_SC_PRO_CFG_REG_0_da_s2_cfly1_scp_en_END (3)
#define V860_SC_PRO_CFG_REG_0_da_s1_cfly2_scp_en_START (4)
#define V860_SC_PRO_CFG_REG_0_da_s1_cfly2_scp_en_END (4)
#define V860_SC_PRO_CFG_REG_0_da_s1_cfly1_scp_en_START (5)
#define V860_SC_PRO_CFG_REG_0_da_s1_cfly1_scp_en_END (5)
#define V860_SC_PRO_CFG_REG_0_da_bat_res_sel_START (6)
#define V860_SC_PRO_CFG_REG_0_da_bat_res_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_ibat_ocp_offset_adj : 4;
        unsigned char da_sc_ibat_ocp_en : 1;
        unsigned char reserved : 3;
    } reg;
} V860_SC_PRO_CFG_REG_1_UNION;
#endif
#define V860_SC_PRO_CFG_REG_1_da_sc_ibat_ocp_offset_adj_START (0)
#define V860_SC_PRO_CFG_REG_1_da_sc_ibat_ocp_offset_adj_END (3)
#define V860_SC_PRO_CFG_REG_1_da_sc_ibat_ocp_en_START (4)
#define V860_SC_PRO_CFG_REG_1_da_sc_ibat_ocp_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc1q5_dsw_ocp_en : 1;
        unsigned char da_sc_pro_en : 1;
        unsigned char da_sc_ibat_ocp_set : 4;
        unsigned char reserved : 2;
    } reg;
} V860_SC_PRO_CFG_REG_2_UNION;
#endif
#define V860_SC_PRO_CFG_REG_2_da_sc1q5_dsw_ocp_en_START (0)
#define V860_SC_PRO_CFG_REG_2_da_sc1q5_dsw_ocp_en_END (0)
#define V860_SC_PRO_CFG_REG_2_da_sc_pro_en_START (1)
#define V860_SC_PRO_CFG_REG_2_da_sc_pro_en_END (1)
#define V860_SC_PRO_CFG_REG_2_da_sc_ibat_ocp_set_START (2)
#define V860_SC_PRO_CFG_REG_2_da_sc_ibat_ocp_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc1q7_dsw_ocp_en : 1;
        unsigned char da_sc1q5_dsw_ocp_set : 5;
        unsigned char reserved : 2;
    } reg;
} V860_SC_PRO_CFG_REG_3_UNION;
#endif
#define V860_SC_PRO_CFG_REG_3_da_sc1q7_dsw_ocp_en_START (0)
#define V860_SC_PRO_CFG_REG_3_da_sc1q7_dsw_ocp_en_END (0)
#define V860_SC_PRO_CFG_REG_3_da_sc1q5_dsw_ocp_set_START (1)
#define V860_SC_PRO_CFG_REG_3_da_sc1q5_dsw_ocp_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc1q7_dsw_ocp_set : 5;
        unsigned char reserved : 3;
    } reg;
} V860_SC_PRO_CFG_REG_4_UNION;
#endif
#define V860_SC_PRO_CFG_REG_4_da_sc1q7_dsw_ocp_set_START (0)
#define V860_SC_PRO_CFG_REG_4_da_sc1q7_dsw_ocp_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc2q5_dsw_ocp_en : 1;
        unsigned char da_sc2_dsw_offset_adj : 6;
        unsigned char reserved : 1;
    } reg;
} V860_SC_PRO_CFG_REG_5_UNION;
#endif
#define V860_SC_PRO_CFG_REG_5_da_sc2q5_dsw_ocp_en_START (0)
#define V860_SC_PRO_CFG_REG_5_da_sc2q5_dsw_ocp_en_END (0)
#define V860_SC_PRO_CFG_REG_5_da_sc2_dsw_offset_adj_START (1)
#define V860_SC_PRO_CFG_REG_5_da_sc2_dsw_offset_adj_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc2q7_dsw_ocp_en : 1;
        unsigned char da_sc2q5_dsw_ocp_set : 5;
        unsigned char reserved : 2;
    } reg;
} V860_SC_PRO_CFG_REG_6_UNION;
#endif
#define V860_SC_PRO_CFG_REG_6_da_sc2q7_dsw_ocp_en_START (0)
#define V860_SC_PRO_CFG_REG_6_da_sc2q7_dsw_ocp_en_END (0)
#define V860_SC_PRO_CFG_REG_6_da_sc2q5_dsw_ocp_set_START (1)
#define V860_SC_PRO_CFG_REG_6_da_sc2q5_dsw_ocp_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc2q7_dsw_ocp_set : 5;
        unsigned char reserved : 3;
    } reg;
} V860_SC_PRO_CFG_REG_7_UNION;
#endif
#define V860_SC_PRO_CFG_REG_7_da_sc2q7_dsw_ocp_set_START (0)
#define V860_SC_PRO_CFG_REG_7_da_sc2q7_dsw_ocp_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_scpro_reserve : 8;
    } reg;
} V860_SC_PRO_CFG_REG_8_UNION;
#endif
#define V860_SC_PRO_CFG_REG_8_da_scpro_reserve_START (0)
#define V860_SC_PRO_CFG_REG_8_da_scpro_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_scpro_reserve1 : 8;
    } reg;
} V860_SC_PRO_CFG_REG_9_UNION;
#endif
#define V860_SC_PRO_CFG_REG_9_da_scpro_reserve1_START (0)
#define V860_SC_PRO_CFG_REG_9_da_scpro_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_bat_res_mode : 1;
        unsigned char reserved : 7;
    } reg;
} V860_DA_BAT_RES_MODE_UNION;
#endif
#define V860_DA_BAT_RES_MODE_da_bat_res_mode_START (0)
#define V860_DA_BAT_RES_MODE_da_bat_res_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_q1_ocp_dbt : 1;
        unsigned char reserved : 7;
    } reg;
} V860_SYS_DET_CFG_REG_0_UNION;
#endif
#define V860_SYS_DET_CFG_REG_0_da_sc_q1_ocp_dbt_START (0)
#define V860_SYS_DET_CFG_REG_0_da_sc_q1_ocp_dbt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_scpro_reserve2 : 8;
    } reg;
} V860_DA_SCPRO_RESERVE2_UNION;
#endif
#define V860_DA_SCPRO_RESERVE2_da_scpro_reserve2_START (0)
#define V860_DA_SCPRO_RESERVE2_da_scpro_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_scpro_testmd : 8;
    } reg;
} V860_DA_SCPRO_TESTMD_UNION;
#endif
#define V860_DA_SCPRO_TESTMD_da_scpro_testmd_START (0)
#define V860_DA_SCPRO_TESTMD_da_scpro_testmd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_psel_regn_vset : 2;
        unsigned char da_psel_ref_set : 2;
        unsigned char da_psel_ocp_shield : 1;
        unsigned char da_psel_ldo3p3_tsmod : 1;
        unsigned char da_psel_force_off : 1;
        unsigned char da_psel_cp_en : 1;
    } reg;
} V860_PSEL_CFG_REG_0_UNION;
#endif
#define V860_PSEL_CFG_REG_0_da_psel_regn_vset_START (0)
#define V860_PSEL_CFG_REG_0_da_psel_regn_vset_END (1)
#define V860_PSEL_CFG_REG_0_da_psel_ref_set_START (2)
#define V860_PSEL_CFG_REG_0_da_psel_ref_set_END (3)
#define V860_PSEL_CFG_REG_0_da_psel_ocp_shield_START (4)
#define V860_PSEL_CFG_REG_0_da_psel_ocp_shield_END (4)
#define V860_PSEL_CFG_REG_0_da_psel_ldo3p3_tsmod_START (5)
#define V860_PSEL_CFG_REG_0_da_psel_ldo3p3_tsmod_END (5)
#define V860_PSEL_CFG_REG_0_da_psel_force_off_START (6)
#define V860_PSEL_CFG_REG_0_da_psel_force_off_END (6)
#define V860_PSEL_CFG_REG_0_da_psel_cp_en_START (7)
#define V860_PSEL_CFG_REG_0_da_psel_cp_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_psel_reserve1 : 8;
    } reg;
} V860_PSEL_CFG_REG_1_UNION;
#endif
#define V860_PSEL_CFG_REG_1_da_psel_reserve1_START (0)
#define V860_PSEL_CFG_REG_1_da_psel_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_psel_reserved : 8;
    } reg;
} V860_PSEL_CFG_REG_2_UNION;
#endif
#define V860_PSEL_CFG_REG_2_da_psel_reserved_START (0)
#define V860_PSEL_CFG_REG_2_da_psel_reserved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_regn_ocp_irq_shield : 2;
        unsigned char da_regn_en : 1;
        unsigned char reserved : 5;
    } reg;
} V860_PSEL_CFG_REG_3_UNION;
#endif
#define V860_PSEL_CFG_REG_3_da_regn_ocp_irq_shield_START (0)
#define V860_PSEL_CFG_REG_3_da_regn_ocp_irq_shield_END (1)
#define V860_PSEL_CFG_REG_3_da_regn_en_START (2)
#define V860_PSEL_CFG_REG_3_da_regn_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_s1q1_ocp_rvs_peak_set : 2;
        unsigned char da_s1q1_ocp_fwd_set : 2;
        unsigned char da_s1q1_ocp_fwd_peak_set : 2;
        unsigned char da_s1q1_ocp_en : 1;
        unsigned char reserved : 1;
    } reg;
} V860_BLOCK_SNS_CFG_REG_0_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_rvs_peak_set_START (0)
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_rvs_peak_set_END (1)
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_fwd_set_START (2)
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_fwd_set_END (3)
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_fwd_peak_set_START (4)
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_fwd_peak_set_END (5)
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_en_START (6)
#define V860_BLOCK_SNS_CFG_REG_0_da_s1q1_ocp_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_s2q1_ocp_en : 1;
        unsigned char da_s1q1_ucp_en : 1;
        unsigned char da_s1q1_rcp_en : 1;
        unsigned char da_s1q1_peak_ocp_en : 1;
        unsigned char da_s1q1_ocp_rvs_set : 3;
        unsigned char reserved : 1;
    } reg;
} V860_BLOCK_SNS_CFG_REG_1_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_1_da_s2q1_ocp_en_START (0)
#define V860_BLOCK_SNS_CFG_REG_1_da_s2q1_ocp_en_END (0)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_ucp_en_START (1)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_ucp_en_END (1)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_rcp_en_START (2)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_rcp_en_END (2)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_peak_ocp_en_START (3)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_peak_ocp_en_END (3)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_ocp_rvs_set_START (4)
#define V860_BLOCK_SNS_CFG_REG_1_da_s1q1_ocp_rvs_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_s2q1_ocp_rvs_peak_set : 2;
        unsigned char da_s2q1_ocp_fwd_set : 2;
        unsigned char da_s2q1_ocp_fwd_peak_set : 2;
        unsigned char reserved : 2;
    } reg;
} V860_BLOCK_SNS_CFG_REG_2_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_2_da_s2q1_ocp_rvs_peak_set_START (0)
#define V860_BLOCK_SNS_CFG_REG_2_da_s2q1_ocp_rvs_peak_set_END (1)
#define V860_BLOCK_SNS_CFG_REG_2_da_s2q1_ocp_fwd_set_START (2)
#define V860_BLOCK_SNS_CFG_REG_2_da_s2q1_ocp_fwd_set_END (3)
#define V860_BLOCK_SNS_CFG_REG_2_da_s2q1_ocp_fwd_peak_set_START (4)
#define V860_BLOCK_SNS_CFG_REG_2_da_s2q1_ocp_fwd_peak_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_q1_rcp_dbt : 1;
        unsigned char da_s2q1_ucp_en : 1;
        unsigned char da_s2q1_rcp_en : 1;
        unsigned char da_s2q1_peak_ocp_en : 1;
        unsigned char da_s2q1_ocp_rvs_set : 3;
        unsigned char reserved : 1;
    } reg;
} V860_BLOCK_SNS_CFG_REG_3_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_3_da_sc_q1_rcp_dbt_START (0)
#define V860_BLOCK_SNS_CFG_REG_3_da_sc_q1_rcp_dbt_END (0)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_ucp_en_START (1)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_ucp_en_END (1)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_rcp_en_START (2)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_rcp_en_END (2)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_peak_ocp_en_START (3)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_peak_ocp_en_END (3)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_ocp_rvs_set_START (4)
#define V860_BLOCK_SNS_CFG_REG_3_da_s2q1_ocp_rvs_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_q1_ucp_set : 2;
        unsigned char da_sc_q1_ucp_dbt : 1;
        unsigned char da_sc_q1_rcp_shield_time : 2;
        unsigned char da_sc_q1_rcp_set : 2;
        unsigned char reserved : 1;
    } reg;
} V860_BLOCK_SNS_CFG_REG_4_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_ucp_set_START (0)
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_ucp_set_END (1)
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_ucp_dbt_START (2)
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_ucp_dbt_END (2)
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_rcp_shield_time_START (3)
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_rcp_shield_time_END (4)
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_rcp_set_START (5)
#define V860_BLOCK_SNS_CFG_REG_4_da_sc_q1_rcp_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sns_ocp_test : 1;
        unsigned char da_sc2_pro_trim : 3;
        unsigned char da_sc1_pro_trim : 3;
        unsigned char reserved : 1;
    } reg;
} V860_BLOCK_SNS_CFG_REG_5_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_5_da_sns_ocp_test_START (0)
#define V860_BLOCK_SNS_CFG_REG_5_da_sns_ocp_test_END (0)
#define V860_BLOCK_SNS_CFG_REG_5_da_sc2_pro_trim_START (1)
#define V860_BLOCK_SNS_CFG_REG_5_da_sc2_pro_trim_END (3)
#define V860_BLOCK_SNS_CFG_REG_5_da_sc1_pro_trim_START (4)
#define V860_BLOCK_SNS_CFG_REG_5_da_sc1_pro_trim_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sns_reserve1 : 8;
    } reg;
} V860_BLOCK_SNS_CFG_REG_6_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_6_da_sns_reserve1_START (0)
#define V860_BLOCK_SNS_CFG_REG_6_da_sns_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sns_reserve2 : 8;
    } reg;
} V860_BLOCK_SNS_CFG_REG_7_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_7_da_sns_reserve2_START (0)
#define V860_BLOCK_SNS_CFG_REG_7_da_sns_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sns_reserve3 : 8;
    } reg;
} V860_BLOCK_SNS_CFG_REG_8_UNION;
#endif
#define V860_BLOCK_SNS_CFG_REG_8_da_sns_reserve3_START (0)
#define V860_BLOCK_SNS_CFG_REG_8_da_sns_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sys_resvo1 : 8;
    } reg;
} V860_DS_SYS_RESVO1_UNION;
#endif
#define V860_DS_SYS_RESVO1_da_sys_resvo1_START (0)
#define V860_DS_SYS_RESVO1_da_sys_resvo1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ad_sc_ibus_ocp_peak : 1;
        unsigned char ad_sc_ibus_ocp : 1;
        unsigned char reserved : 6;
    } reg;
} V860_BLOCK_SNS_RO_REG_0_UNION;
#endif
#define V860_BLOCK_SNS_RO_REG_0_ad_sc_ibus_ocp_peak_START (0)
#define V860_BLOCK_SNS_RO_REG_0_ad_sc_ibus_ocp_peak_END (0)
#define V860_BLOCK_SNS_RO_REG_0_ad_sc_ibus_ocp_START (1)
#define V860_BLOCK_SNS_RO_REG_0_ad_sc_ibus_ocp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char da_sc_phase1_en : 8;
    } reg;
} V860_DA_SC_PHASE1_EN_UNION;
#endif
#define V860_DA_SC_PHASE1_EN_da_sc_phase1_en_START (0)
#define V860_DA_SC_PHASE1_EN_da_sc_phase1_en_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
