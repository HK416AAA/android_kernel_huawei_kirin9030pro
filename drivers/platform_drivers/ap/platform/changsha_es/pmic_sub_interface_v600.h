#ifndef __SUB_PMIC_INTERFACE_H__
#define __SUB_PMIC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x00UL))
#define SUB_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x01UL))
#define SUB_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x02UL))
#define SUB_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x03UL))
#define SUB_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x04UL))
#define SUB_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x05UL))
#define SUB_PMIC_SYS_CTRL_RO_REG_1_ADDR(base) ((base) + (0x06UL))
#define SUB_PMIC_SYS_CTRL_RO_REG_2_ADDR(base) ((base) + (0x07UL))
#define SUB_PMIC_PG_STATUS_ADDR(base) ((base) + (0x08UL))
#define SUB_PMIC_VOK_STATUS_ADDR(base) ((base) + (0x09UL))
#define SUB_PMIC_STATUS_FLG_0_ADDR(base) ((base) + (0x0AUL))
#define SUB_PMIC_STATUS_FLG_1_ADDR(base) ((base) + (0x0BUL))
#define SUB_PMIC_THSD_EN_REG_ADDR(base) ((base) + (0x0CUL))
#define SUB_PMIC_LDO_PMUD_VSET_CFG_ADDR(base) ((base) + (0x0DUL))
#define SUB_PMIC_LDO_PMUH_VSET_CFG_ADDR(base) ((base) + (0x0EUL))
#define SUB_PMIC_LDO_PMUH_CFG_ADDR(base) ((base) + (0x0FUL))
#define SUB_PMIC_DEB_CTRL_ADDR(base) ((base) + (0x10UL))
#define SUB_PMIC_DEB_CTRL_1_ADDR(base) ((base) + (0x11UL))
#define SUB_PMIC_DEB_CTRL_2_ADDR(base) ((base) + (0x12UL))
#define SUB_PMIC_LOADLINE_CTRL_0_ADDR(base) ((base) + (0x13UL))
#define SUB_PMIC_LOADLINE_CTRL_1_ADDR(base) ((base) + (0x14UL))
#define SUB_PMIC_LOADLINE_CTRL_2_ADDR(base) ((base) + (0x15UL))
#define SUB_PMIC_LOADLINE_CTRL_3_ADDR(base) ((base) + (0x16UL))
#define SUB_PMIC_LOADLINE_CTRL_4_ADDR(base) ((base) + (0x17UL))
#define SUB_PMIC_LOADLINE_CTRL_5_ADDR(base) ((base) + (0x18UL))
#define SUB_PMIC_LOADLINE_CTRL_6_ADDR(base) ((base) + (0x19UL))
#define SUB_PMIC_LOADLINE_CTRL_7_ADDR(base) ((base) + (0x1AUL))
#define SUB_PMIC_LOADLINE_CTRL_8_ADDR(base) ((base) + (0x1BUL))
#define SUB_PMIC_LOADLINE_CTRL_9_ADDR(base) ((base) + (0x1CUL))
#define SUB_PMIC_LOADLINE_CTRL_10_ADDR(base) ((base) + (0x1DUL))
#define SUB_PMIC_LOADLINE_CTRL_11_ADDR(base) ((base) + (0x1EUL))
#define SUB_PMIC_LOADLINE_CTRL_12_ADDR(base) ((base) + (0x1FUL))
#define SUB_PMIC_LOADLINE_CTRL_13_ADDR(base) ((base) + (0x20UL))
#define SUB_PMIC_LOADLINE_CTRL_14_ADDR(base) ((base) + (0x21UL))
#define SUB_PMIC_LOADLINE_CTRL_15_ADDR(base) ((base) + (0x22UL))
#define SUB_PMIC_LOADLINE_EN_0_ADDR(base) ((base) + (0x23UL))
#define SUB_PMIC_LOADLINE_EN_1_ADDR(base) ((base) + (0x24UL))
#define SUB_PMIC_LOADLINE_EN_2_ADDR(base) ((base) + (0x25UL))
#define SUB_PMIC_LOADLINE_EN_3_ADDR(base) ((base) + (0x26UL))
#define SUB_PMIC_OC_FER_CFG_0_ADDR(base) ((base) + (0x27UL))
#define SUB_PMIC_OC_FER_CFG_1_ADDR(base) ((base) + (0x28UL))
#define SUB_PMIC_OC_FER_CFG_2_ADDR(base) ((base) + (0x29UL))
#define SUB_PMIC_OC_FER_CFG_3_ADDR(base) ((base) + (0x2AUL))
#define SUB_PMIC_OC_FER_CFG_4_ADDR(base) ((base) + (0x2BUL))
#define SUB_PMIC_OC_FER_CFG_5_ADDR(base) ((base) + (0x2CUL))
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_ADDR(base) ((base) + (0x2DUL))
#define SUB_PMIC_D2A_RESVER0_ADDR(base) ((base) + (0x2FUL))
#define SUB_PMIC_D2A_RESVER1_ADDR(base) ((base) + (0x30UL))
#define SUB_PMIC_D2A_RESVER2_ADDR(base) ((base) + (0x31UL))
#define SUB_PMIC_A2D_RESVER0_ADDR(base) ((base) + (0x32UL))
#define SUB_PMIC_A2D_RESVER1_ADDR(base) ((base) + (0x33UL))
#define SUB_PMIC_A2D_RESVER2_ADDR(base) ((base) + (0x34UL))
#define SUB_PMIC_A2D_RESVER3_ADDR(base) ((base) + (0x35UL))
#define SUB_PMIC_A2D_RESVER4_ADDR(base) ((base) + (0x36UL))
#define SUB_PMIC_DUMMY_SPMI_ADDR(base) ((base) + (0x37UL))
#define SUB_PMIC_REG_9M6_EN_ADDR(base) ((base) + (0x38UL))
#define SUB_PMIC_REG_9M6_OFF_ADDR(base) ((base) + (0x39UL))
#else
#define SUB_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x00))
#define SUB_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x01))
#define SUB_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x02))
#define SUB_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x03))
#define SUB_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x04))
#define SUB_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x05))
#define SUB_PMIC_SYS_CTRL_RO_REG_1_ADDR(base) ((base) + (0x06))
#define SUB_PMIC_SYS_CTRL_RO_REG_2_ADDR(base) ((base) + (0x07))
#define SUB_PMIC_PG_STATUS_ADDR(base) ((base) + (0x08))
#define SUB_PMIC_VOK_STATUS_ADDR(base) ((base) + (0x09))
#define SUB_PMIC_STATUS_FLG_0_ADDR(base) ((base) + (0x0A))
#define SUB_PMIC_STATUS_FLG_1_ADDR(base) ((base) + (0x0B))
#define SUB_PMIC_THSD_EN_REG_ADDR(base) ((base) + (0x0C))
#define SUB_PMIC_LDO_PMUD_VSET_CFG_ADDR(base) ((base) + (0x0D))
#define SUB_PMIC_LDO_PMUH_VSET_CFG_ADDR(base) ((base) + (0x0E))
#define SUB_PMIC_LDO_PMUH_CFG_ADDR(base) ((base) + (0x0F))
#define SUB_PMIC_DEB_CTRL_ADDR(base) ((base) + (0x10))
#define SUB_PMIC_DEB_CTRL_1_ADDR(base) ((base) + (0x11))
#define SUB_PMIC_DEB_CTRL_2_ADDR(base) ((base) + (0x12))
#define SUB_PMIC_LOADLINE_CTRL_0_ADDR(base) ((base) + (0x13))
#define SUB_PMIC_LOADLINE_CTRL_1_ADDR(base) ((base) + (0x14))
#define SUB_PMIC_LOADLINE_CTRL_2_ADDR(base) ((base) + (0x15))
#define SUB_PMIC_LOADLINE_CTRL_3_ADDR(base) ((base) + (0x16))
#define SUB_PMIC_LOADLINE_CTRL_4_ADDR(base) ((base) + (0x17))
#define SUB_PMIC_LOADLINE_CTRL_5_ADDR(base) ((base) + (0x18))
#define SUB_PMIC_LOADLINE_CTRL_6_ADDR(base) ((base) + (0x19))
#define SUB_PMIC_LOADLINE_CTRL_7_ADDR(base) ((base) + (0x1A))
#define SUB_PMIC_LOADLINE_CTRL_8_ADDR(base) ((base) + (0x1B))
#define SUB_PMIC_LOADLINE_CTRL_9_ADDR(base) ((base) + (0x1C))
#define SUB_PMIC_LOADLINE_CTRL_10_ADDR(base) ((base) + (0x1D))
#define SUB_PMIC_LOADLINE_CTRL_11_ADDR(base) ((base) + (0x1E))
#define SUB_PMIC_LOADLINE_CTRL_12_ADDR(base) ((base) + (0x1F))
#define SUB_PMIC_LOADLINE_CTRL_13_ADDR(base) ((base) + (0x20))
#define SUB_PMIC_LOADLINE_CTRL_14_ADDR(base) ((base) + (0x21))
#define SUB_PMIC_LOADLINE_CTRL_15_ADDR(base) ((base) + (0x22))
#define SUB_PMIC_LOADLINE_EN_0_ADDR(base) ((base) + (0x23))
#define SUB_PMIC_LOADLINE_EN_1_ADDR(base) ((base) + (0x24))
#define SUB_PMIC_LOADLINE_EN_2_ADDR(base) ((base) + (0x25))
#define SUB_PMIC_LOADLINE_EN_3_ADDR(base) ((base) + (0x26))
#define SUB_PMIC_OC_FER_CFG_0_ADDR(base) ((base) + (0x27))
#define SUB_PMIC_OC_FER_CFG_1_ADDR(base) ((base) + (0x28))
#define SUB_PMIC_OC_FER_CFG_2_ADDR(base) ((base) + (0x29))
#define SUB_PMIC_OC_FER_CFG_3_ADDR(base) ((base) + (0x2A))
#define SUB_PMIC_OC_FER_CFG_4_ADDR(base) ((base) + (0x2B))
#define SUB_PMIC_OC_FER_CFG_5_ADDR(base) ((base) + (0x2C))
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_ADDR(base) ((base) + (0x2D))
#define SUB_PMIC_D2A_RESVER0_ADDR(base) ((base) + (0x2F))
#define SUB_PMIC_D2A_RESVER1_ADDR(base) ((base) + (0x30))
#define SUB_PMIC_D2A_RESVER2_ADDR(base) ((base) + (0x31))
#define SUB_PMIC_A2D_RESVER0_ADDR(base) ((base) + (0x32))
#define SUB_PMIC_A2D_RESVER1_ADDR(base) ((base) + (0x33))
#define SUB_PMIC_A2D_RESVER2_ADDR(base) ((base) + (0x34))
#define SUB_PMIC_A2D_RESVER3_ADDR(base) ((base) + (0x35))
#define SUB_PMIC_A2D_RESVER4_ADDR(base) ((base) + (0x36))
#define SUB_PMIC_DUMMY_SPMI_ADDR(base) ((base) + (0x37))
#define SUB_PMIC_REG_9M6_EN_ADDR(base) ((base) + (0x38))
#define SUB_PMIC_REG_9M6_OFF_ADDR(base) ((base) + (0x39))
#endif
#define RAMP_CTRL_BASE (0x0100)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK0_RAMP_CFG_ADDR(base) ((base) + (0x00UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_RAMP_CHG_VSET_ADDR(base) ((base) + (0x01UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_ADDR(base) ((base) + (0x02UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_DLY_RU_CFG_ADDR(base) ((base) + (0x03UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_DLY_RD_CFG_ADDR(base) ((base) + (0x04UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_DLY_VOK_CFG_ADDR(base) ((base) + (0x05UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_RAMP_CFG_ADDR(base) ((base) + (0x06UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_RAMP_CHG_VSET_ADDR(base) ((base) + (0x07UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_ADDR(base) ((base) + (0x08UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_DLY_RU_CFG_ADDR(base) ((base) + (0x09UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_DLY_RD_CFG_ADDR(base) ((base) + (0x0AUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_DLY_VOK_CFG_ADDR(base) ((base) + (0x0BUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_RAMP_CFG_ADDR(base) ((base) + (0x0CUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_RAMP_CHG_VSET_ADDR(base) ((base) + (0x0DUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_ADDR(base) ((base) + (0x0EUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_DLY_RU_CFG_ADDR(base) ((base) + (0x0FUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_DLY_RD_CFG_ADDR(base) ((base) + (0x10UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_DLY_VOK_CFG_ADDR(base) ((base) + (0x11UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_RAMP_CFG_ADDR(base) ((base) + (0x12UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_RAMP_CHG_VSET_ADDR(base) ((base) + (0x13UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_ADDR(base) ((base) + (0x14UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_DLY_RU_CFG_ADDR(base) ((base) + (0x15UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_DLY_RD_CFG_ADDR(base) ((base) + (0x16UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_DLY_VOK_CFG_ADDR(base) ((base) + (0x17UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_RAMP_CFG_ADDR(base) ((base) + (0x18UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_RAMP_CHG_VSET_ADDR(base) ((base) + (0x19UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_ADDR(base) ((base) + (0x1AUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_DLY_RU_CFG_ADDR(base) ((base) + (0x1BUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_DLY_RD_CFG_ADDR(base) ((base) + (0x1CUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_DLY_VOK_CFG_ADDR(base) ((base) + (0x1DUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_RAMP_CFG_ADDR(base) ((base) + (0x1EUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_RAMP_CHG_VSET_ADDR(base) ((base) + (0x1FUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_ADDR(base) ((base) + (0x20UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_DLY_RU_CFG_ADDR(base) ((base) + (0x21UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_DLY_RD_CFG_ADDR(base) ((base) + (0x22UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_DLY_VOK_CFG_ADDR(base) ((base) + (0x23UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_LDO39_RAMP_CFG_ADDR(base) ((base) + (0x24UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ADDR(base) ((base) + (0x25UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_LDO39_DLY_VOK_CFG_ADDR(base) ((base) + (0x26UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_CPUM_BUCK_SEL_ADDR(base) ((base) + (0x27UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_VOK_CFG_ADDR(base) ((base) + (0x28UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_GATE_DEBUG_ADDR(base) ((base) + (0x29UL) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_CPUM_RO_ADDR(base) ((base) + (0x2AUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_MEM_RO_ADDR(base) ((base) + (0x2BUL) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_STATE_RO_ADDR(base) ((base) + (0x2CUL) + RAMP_CTRL_BASE)
#else
#define SUB_PMIC_BUCK0_RAMP_CFG_ADDR(base) ((base) + (0x00) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_RAMP_CHG_VSET_ADDR(base) ((base) + (0x01) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_ADDR(base) ((base) + (0x02) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_DLY_RU_CFG_ADDR(base) ((base) + (0x03) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_DLY_RD_CFG_ADDR(base) ((base) + (0x04) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK0_DLY_VOK_CFG_ADDR(base) ((base) + (0x05) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_RAMP_CFG_ADDR(base) ((base) + (0x06) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_RAMP_CHG_VSET_ADDR(base) ((base) + (0x07) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_ADDR(base) ((base) + (0x08) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_DLY_RU_CFG_ADDR(base) ((base) + (0x09) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_DLY_RD_CFG_ADDR(base) ((base) + (0x0A) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK2_DLY_VOK_CFG_ADDR(base) ((base) + (0x0B) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_RAMP_CFG_ADDR(base) ((base) + (0x0C) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_RAMP_CHG_VSET_ADDR(base) ((base) + (0x0D) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_ADDR(base) ((base) + (0x0E) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_DLY_RU_CFG_ADDR(base) ((base) + (0x0F) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_DLY_RD_CFG_ADDR(base) ((base) + (0x10) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK3_DLY_VOK_CFG_ADDR(base) ((base) + (0x11) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_RAMP_CFG_ADDR(base) ((base) + (0x12) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_RAMP_CHG_VSET_ADDR(base) ((base) + (0x13) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_ADDR(base) ((base) + (0x14) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_DLY_RU_CFG_ADDR(base) ((base) + (0x15) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_DLY_RD_CFG_ADDR(base) ((base) + (0x16) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK4_DLY_VOK_CFG_ADDR(base) ((base) + (0x17) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_RAMP_CFG_ADDR(base) ((base) + (0x18) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_RAMP_CHG_VSET_ADDR(base) ((base) + (0x19) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_ADDR(base) ((base) + (0x1A) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_DLY_RU_CFG_ADDR(base) ((base) + (0x1B) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_DLY_RD_CFG_ADDR(base) ((base) + (0x1C) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK6_DLY_VOK_CFG_ADDR(base) ((base) + (0x1D) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_RAMP_CFG_ADDR(base) ((base) + (0x1E) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_RAMP_CHG_VSET_ADDR(base) ((base) + (0x1F) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_ADDR(base) ((base) + (0x20) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_DLY_RU_CFG_ADDR(base) ((base) + (0x21) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_DLY_RD_CFG_ADDR(base) ((base) + (0x22) + RAMP_CTRL_BASE)
#define SUB_PMIC_BUCK7_DLY_VOK_CFG_ADDR(base) ((base) + (0x23) + RAMP_CTRL_BASE)
#define SUB_PMIC_LDO39_RAMP_CFG_ADDR(base) ((base) + (0x24) + RAMP_CTRL_BASE)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ADDR(base) ((base) + (0x25) + RAMP_CTRL_BASE)
#define SUB_PMIC_LDO39_DLY_VOK_CFG_ADDR(base) ((base) + (0x26) + RAMP_CTRL_BASE)
#define SUB_PMIC_CPUM_BUCK_SEL_ADDR(base) ((base) + (0x27) + RAMP_CTRL_BASE)
#define SUB_PMIC_VOK_CFG_ADDR(base) ((base) + (0x28) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_GATE_DEBUG_ADDR(base) ((base) + (0x29) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_CPUM_RO_ADDR(base) ((base) + (0x2A) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_MEM_RO_ADDR(base) ((base) + (0x2B) + RAMP_CTRL_BASE)
#define SUB_PMIC_RAMP_STATE_RO_ADDR(base) ((base) + (0x2C) + RAMP_CTRL_BASE)
#endif
#define IRQ_MASK_BASE (0x0200)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_IRQ1_MASK_ADDR(base) ((base) + (0x00UL) + IRQ_MASK_BASE)
#define SUB_PMIC_PWR_IRQ_MASK_ADDR(base) ((base) + (0x01UL) + IRQ_MASK_BASE)
#define SUB_PMIC_TEMP_THSD_IRQ_MASK_ADDR(base) ((base) + (0x02UL) + IRQ_MASK_BASE)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_ADDR(base) ((base) + (0x03UL) + IRQ_MASK_BASE)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_ADDR(base) ((base) + (0x04UL) + IRQ_MASK_BASE)
#define SUB_PMIC_OCP_IRQ_MASK_ADDR(base) ((base) + (0x05UL) + IRQ_MASK_BASE)
#define SUB_PMIC_OCP_IRQ_MASK_2_ADDR(base) ((base) + (0x06UL) + IRQ_MASK_BASE)
#define SUB_PMIC_SCP_IRQ_MASK_ADDR(base) ((base) + (0x07UL) + IRQ_MASK_BASE)
#define SUB_PMIC_OVP_IRQ_MASK_ADDR(base) ((base) + (0x08UL) + IRQ_MASK_BASE)
#define SUB_PMIC_OC_FER_IRQ_MASK_ADDR(base) ((base) + (0x09UL) + IRQ_MASK_BASE)
#define SUB_PMIC_RAMP_IRQ_MASK_ADDR(base) ((base) + (0x0AUL) + IRQ_MASK_BASE)
#else
#define SUB_PMIC_IRQ1_MASK_ADDR(base) ((base) + (0x00) + IRQ_MASK_BASE)
#define SUB_PMIC_PWR_IRQ_MASK_ADDR(base) ((base) + (0x01) + IRQ_MASK_BASE)
#define SUB_PMIC_TEMP_THSD_IRQ_MASK_ADDR(base) ((base) + (0x02) + IRQ_MASK_BASE)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_ADDR(base) ((base) + (0x03) + IRQ_MASK_BASE)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_ADDR(base) ((base) + (0x04) + IRQ_MASK_BASE)
#define SUB_PMIC_OCP_IRQ_MASK_ADDR(base) ((base) + (0x05) + IRQ_MASK_BASE)
#define SUB_PMIC_OCP_IRQ_MASK_2_ADDR(base) ((base) + (0x06) + IRQ_MASK_BASE)
#define SUB_PMIC_SCP_IRQ_MASK_ADDR(base) ((base) + (0x07) + IRQ_MASK_BASE)
#define SUB_PMIC_OVP_IRQ_MASK_ADDR(base) ((base) + (0x08) + IRQ_MASK_BASE)
#define SUB_PMIC_OC_FER_IRQ_MASK_ADDR(base) ((base) + (0x09) + IRQ_MASK_BASE)
#define SUB_PMIC_RAMP_IRQ_MASK_ADDR(base) ((base) + (0x0A) + IRQ_MASK_BASE)
#endif
#define IRQ_BASE (0x0300)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_IRQ1_ADDR(base) ((base) + (0x00UL) + IRQ_BASE)
#define SUB_PMIC_PWR_IRQ_ADDR(base) ((base) + (0x01UL) + IRQ_BASE)
#define SUB_PMIC_TEMP_THSD_IRQ_ADDR(base) ((base) + (0x02UL) + IRQ_BASE)
#define SUB_PMIC_TEMP_ALERT_IRQ_ADDR(base) ((base) + (0x03UL) + IRQ_BASE)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_ADDR(base) ((base) + (0x04UL) + IRQ_BASE)
#define SUB_PMIC_OCP_IRQ_ADDR(base) ((base) + (0x05UL) + IRQ_BASE)
#define SUB_PMIC_OCP_IRQ_2_ADDR(base) ((base) + (0x06UL) + IRQ_BASE)
#define SUB_PMIC_SCP_IRQ_ADDR(base) ((base) + (0x07UL) + IRQ_BASE)
#define SUB_PMIC_OVP_IRQ_ADDR(base) ((base) + (0x08UL) + IRQ_BASE)
#define SUB_PMIC_OC_FER_IRQ_ADDR(base) ((base) + (0x09UL) + IRQ_BASE)
#define SUB_PMIC_RAMP_IRQ_ADDR(base) ((base) + (0x0AUL) + IRQ_BASE)
#else
#define SUB_PMIC_IRQ1_ADDR(base) ((base) + (0x00) + IRQ_BASE)
#define SUB_PMIC_PWR_IRQ_ADDR(base) ((base) + (0x01) + IRQ_BASE)
#define SUB_PMIC_TEMP_THSD_IRQ_ADDR(base) ((base) + (0x02) + IRQ_BASE)
#define SUB_PMIC_TEMP_ALERT_IRQ_ADDR(base) ((base) + (0x03) + IRQ_BASE)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_ADDR(base) ((base) + (0x04) + IRQ_BASE)
#define SUB_PMIC_OCP_IRQ_ADDR(base) ((base) + (0x05) + IRQ_BASE)
#define SUB_PMIC_OCP_IRQ_2_ADDR(base) ((base) + (0x06) + IRQ_BASE)
#define SUB_PMIC_SCP_IRQ_ADDR(base) ((base) + (0x07) + IRQ_BASE)
#define SUB_PMIC_OVP_IRQ_ADDR(base) ((base) + (0x08) + IRQ_BASE)
#define SUB_PMIC_OC_FER_IRQ_ADDR(base) ((base) + (0x09) + IRQ_BASE)
#define SUB_PMIC_RAMP_IRQ_ADDR(base) ((base) + (0x0A) + IRQ_BASE)
#endif
#define NP_EVENT_BASE (0x0400)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_PWR_EVENT_ADDR(base) ((base) + (0x00UL) + NP_EVENT_BASE)
#define SUB_PMIC_TEMP_THSD_EVENT_ADDR(base) ((base) + (0x01UL) + NP_EVENT_BASE)
#define SUB_PMIC_TEMP_ALERT_EVENT_ADDR(base) ((base) + (0x02UL) + NP_EVENT_BASE)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_ADDR(base) ((base) + (0x03UL) + NP_EVENT_BASE)
#define SUB_PMIC_OCP_EVENT_ADDR(base) ((base) + (0x04UL) + NP_EVENT_BASE)
#define SUB_PMIC_OCP_EVENT_2_ADDR(base) ((base) + (0x05UL) + NP_EVENT_BASE)
#define SUB_PMIC_SCP_EVENT_ADDR(base) ((base) + (0x06UL) + NP_EVENT_BASE)
#define SUB_PMIC_OVP_EVENT_ADDR(base) ((base) + (0x07UL) + NP_EVENT_BASE)
#define SUB_PMIC_OC_FER_EVENT_ADDR(base) ((base) + (0x08UL) + NP_EVENT_BASE)
#define SUB_PMIC_RAMP_EVENT_ADDR(base) ((base) + (0x09UL) + NP_EVENT_BASE)
#define SUB_PMIC_RAMP_ECO_EVENT_ADDR(base) ((base) + (0x0AUL) + NP_EVENT_BASE)
#define SUB_PMIC_OC_LEVEL_EVENT_0_ADDR(base) ((base) + (0x0BUL) + NP_EVENT_BASE)
#define SUB_PMIC_OC_LEVEL_EVENT_1_ADDR(base) ((base) + (0x0CUL) + NP_EVENT_BASE)
#else
#define SUB_PMIC_PWR_EVENT_ADDR(base) ((base) + (0x00) + NP_EVENT_BASE)
#define SUB_PMIC_TEMP_THSD_EVENT_ADDR(base) ((base) + (0x01) + NP_EVENT_BASE)
#define SUB_PMIC_TEMP_ALERT_EVENT_ADDR(base) ((base) + (0x02) + NP_EVENT_BASE)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_ADDR(base) ((base) + (0x03) + NP_EVENT_BASE)
#define SUB_PMIC_OCP_EVENT_ADDR(base) ((base) + (0x04) + NP_EVENT_BASE)
#define SUB_PMIC_OCP_EVENT_2_ADDR(base) ((base) + (0x05) + NP_EVENT_BASE)
#define SUB_PMIC_SCP_EVENT_ADDR(base) ((base) + (0x06) + NP_EVENT_BASE)
#define SUB_PMIC_OVP_EVENT_ADDR(base) ((base) + (0x07) + NP_EVENT_BASE)
#define SUB_PMIC_OC_FER_EVENT_ADDR(base) ((base) + (0x08) + NP_EVENT_BASE)
#define SUB_PMIC_RAMP_EVENT_ADDR(base) ((base) + (0x09) + NP_EVENT_BASE)
#define SUB_PMIC_RAMP_ECO_EVENT_ADDR(base) ((base) + (0x0A) + NP_EVENT_BASE)
#define SUB_PMIC_OC_LEVEL_EVENT_0_ADDR(base) ((base) + (0x0B) + NP_EVENT_BASE)
#define SUB_PMIC_OC_LEVEL_EVENT_1_ADDR(base) ((base) + (0x0C) + NP_EVENT_BASE)
#endif
#define REG_EFUSE_BASE (0x0500)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_EFUSE_LOCK_ADDR(base) ((base) + (0x00UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CLK_CTRL_ADDR(base) ((base) + (0x01UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_LOOP_RD_CTRL_ADDR(base) ((base) + (0x02UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_WR_PULSE_CTRL_ADDR(base) ((base) + (0x03UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_D_ADDR(base) ((base) + (0x05UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_AEN_MODE_ADDR(base) ((base) + (0x06UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_MODE_CTRL_ADDR(base) ((base) + (0x07UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_RDEN_CFG_ADDR(base) ((base) + (0x09UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_PGMEN_CFG_ADDR(base) ((base) + (0x0AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_AEN_CFG_ADDR(base) ((base) + (0x0BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_ADDR_L_ADDR(base) ((base) + (0x0CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_ADDR_H_ADDR(base) ((base) + (0x0DUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_TESTBUS_EN_ADDR(base) ((base) + (0x0EUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_TESTBUS_SEL_ADDR(base) ((base) + (0x0FUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_TESTBUS_DATA_ADDR(base) ((base) + (0x10UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x11UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x12UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x13UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_FSM_RESET_ADDR(base) ((base) + (0x14UL) + REG_EFUSE_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_0_ADDR(base) ((base) + (0x15UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_0_ADDR(base) ((base) + (0x20UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_1_ADDR(base) ((base) + (0x21UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_2_ADDR(base) ((base) + (0x22UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_3_ADDR(base) ((base) + (0x23UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_4_ADDR(base) ((base) + (0x24UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_5_ADDR(base) ((base) + (0x25UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_6_ADDR(base) ((base) + (0x26UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_7_ADDR(base) ((base) + (0x27UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_9_ADDR(base) ((base) + (0x29UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_10_ADDR(base) ((base) + (0x2AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_11_ADDR(base) ((base) + (0x2BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_12_ADDR(base) ((base) + (0x2CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_13_ADDR(base) ((base) + (0x2DUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_14_ADDR(base) ((base) + (0x2EUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_15_ADDR(base) ((base) + (0x2FUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_16_ADDR(base) ((base) + (0x30UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_17_ADDR(base) ((base) + (0x31UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_18_ADDR(base) ((base) + (0x32UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_19_ADDR(base) ((base) + (0x33UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_20_ADDR(base) ((base) + (0x34UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_21_ADDR(base) ((base) + (0x35UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_22_ADDR(base) ((base) + (0x36UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_23_ADDR(base) ((base) + (0x37UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_24_ADDR(base) ((base) + (0x38UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_25_ADDR(base) ((base) + (0x39UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_26_ADDR(base) ((base) + (0x3AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_27_ADDR(base) ((base) + (0x3BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_28_ADDR(base) ((base) + (0x3CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_29_ADDR(base) ((base) + (0x3DUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_30_ADDR(base) ((base) + (0x3EUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_31_ADDR(base) ((base) + (0x3FUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_32_ADDR(base) ((base) + (0x40UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_33_ADDR(base) ((base) + (0x41UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_34_ADDR(base) ((base) + (0x42UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_35_ADDR(base) ((base) + (0x43UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_36_ADDR(base) ((base) + (0x44UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_37_ADDR(base) ((base) + (0x45UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_38_ADDR(base) ((base) + (0x46UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_39_ADDR(base) ((base) + (0x47UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_40_ADDR(base) ((base) + (0x48UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_41_ADDR(base) ((base) + (0x49UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_42_ADDR(base) ((base) + (0x4AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_43_ADDR(base) ((base) + (0x4BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_44_ADDR(base) ((base) + (0x4CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_45_ADDR(base) ((base) + (0x4DUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_46_ADDR(base) ((base) + (0x4EUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_47_ADDR(base) ((base) + (0x4FUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_48_ADDR(base) ((base) + (0x50UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_49_ADDR(base) ((base) + (0x51UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_50_ADDR(base) ((base) + (0x52UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_51_ADDR(base) ((base) + (0x53UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_52_ADDR(base) ((base) + (0x54UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_53_ADDR(base) ((base) + (0x55UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_54_ADDR(base) ((base) + (0x56UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_55_ADDR(base) ((base) + (0x57UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_56_ADDR(base) ((base) + (0x58UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_57_ADDR(base) ((base) + (0x59UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_58_ADDR(base) ((base) + (0x5AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_59_ADDR(base) ((base) + (0x5BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_60_ADDR(base) ((base) + (0x5CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_61_ADDR(base) ((base) + (0x5DUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_62_ADDR(base) ((base) + (0x5EUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_63_ADDR(base) ((base) + (0x5FUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_64_ADDR(base) ((base) + (0x60UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_65_ADDR(base) ((base) + (0x61UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_66_ADDR(base) ((base) + (0x62UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_67_ADDR(base) ((base) + (0x63UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_68_ADDR(base) ((base) + (0x64UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_69_ADDR(base) ((base) + (0x65UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_70_ADDR(base) ((base) + (0x66UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_71_ADDR(base) ((base) + (0x67UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_72_ADDR(base) ((base) + (0x68UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_73_ADDR(base) ((base) + (0x69UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_74_ADDR(base) ((base) + (0x6AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_75_ADDR(base) ((base) + (0x6BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_76_ADDR(base) ((base) + (0x6CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_77_ADDR(base) ((base) + (0x6DUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_78_ADDR(base) ((base) + (0x6EUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_79_ADDR(base) ((base) + (0x6FUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_80_ADDR(base) ((base) + (0x70UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_81_ADDR(base) ((base) + (0x71UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_82_ADDR(base) ((base) + (0x72UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_83_ADDR(base) ((base) + (0x73UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_84_ADDR(base) ((base) + (0x74UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_85_ADDR(base) ((base) + (0x75UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_86_ADDR(base) ((base) + (0x76UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_87_ADDR(base) ((base) + (0x77UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_88_ADDR(base) ((base) + (0x78UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_89_ADDR(base) ((base) + (0x79UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_90_ADDR(base) ((base) + (0x7AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_91_ADDR(base) ((base) + (0x7BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_92_ADDR(base) ((base) + (0x7CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_93_ADDR(base) ((base) + (0x7DUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_94_ADDR(base) ((base) + (0x7EUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_95_ADDR(base) ((base) + (0x7FUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_96_ADDR(base) ((base) + (0x80UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_97_ADDR(base) ((base) + (0x81UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_98_ADDR(base) ((base) + (0x82UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_99_ADDR(base) ((base) + (0x83UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_100_ADDR(base) ((base) + (0x84UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_101_ADDR(base) ((base) + (0x85UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_102_ADDR(base) ((base) + (0x86UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_103_ADDR(base) ((base) + (0x87UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_104_ADDR(base) ((base) + (0x88UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_105_ADDR(base) ((base) + (0x89UL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_106_ADDR(base) ((base) + (0x8AUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_107_ADDR(base) ((base) + (0x8BUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_108_ADDR(base) ((base) + (0x8CUL) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_109_ADDR(base) ((base) + (0x8DUL) + REG_EFUSE_BASE)
#else
#define SUB_PMIC_EFUSE_LOCK_ADDR(base) ((base) + (0x00) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CLK_CTRL_ADDR(base) ((base) + (0x01) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_LOOP_RD_CTRL_ADDR(base) ((base) + (0x02) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_WR_PULSE_CTRL_ADDR(base) ((base) + (0x03) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_D_ADDR(base) ((base) + (0x05) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_AEN_MODE_ADDR(base) ((base) + (0x06) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_MODE_CTRL_ADDR(base) ((base) + (0x07) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_RDEN_CFG_ADDR(base) ((base) + (0x09) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_PGMEN_CFG_ADDR(base) ((base) + (0x0A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_AEN_CFG_ADDR(base) ((base) + (0x0B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_ADDR_L_ADDR(base) ((base) + (0x0C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_ADDR_H_ADDR(base) ((base) + (0x0D) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_TESTBUS_EN_ADDR(base) ((base) + (0x0E) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_TESTBUS_SEL_ADDR(base) ((base) + (0x0F) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_TESTBUS_DATA_ADDR(base) ((base) + (0x10) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x11) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x12) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x13) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE0_FSM_RESET_ADDR(base) ((base) + (0x14) + REG_EFUSE_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_0_ADDR(base) ((base) + (0x15) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_0_ADDR(base) ((base) + (0x20) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_1_ADDR(base) ((base) + (0x21) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_2_ADDR(base) ((base) + (0x22) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_3_ADDR(base) ((base) + (0x23) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_4_ADDR(base) ((base) + (0x24) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_5_ADDR(base) ((base) + (0x25) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_6_ADDR(base) ((base) + (0x26) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_7_ADDR(base) ((base) + (0x27) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_9_ADDR(base) ((base) + (0x29) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_10_ADDR(base) ((base) + (0x2A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_11_ADDR(base) ((base) + (0x2B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_12_ADDR(base) ((base) + (0x2C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_13_ADDR(base) ((base) + (0x2D) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_14_ADDR(base) ((base) + (0x2E) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_15_ADDR(base) ((base) + (0x2F) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_16_ADDR(base) ((base) + (0x30) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_17_ADDR(base) ((base) + (0x31) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_18_ADDR(base) ((base) + (0x32) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_19_ADDR(base) ((base) + (0x33) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_20_ADDR(base) ((base) + (0x34) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_21_ADDR(base) ((base) + (0x35) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_22_ADDR(base) ((base) + (0x36) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_23_ADDR(base) ((base) + (0x37) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_24_ADDR(base) ((base) + (0x38) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_25_ADDR(base) ((base) + (0x39) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_26_ADDR(base) ((base) + (0x3A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_27_ADDR(base) ((base) + (0x3B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_28_ADDR(base) ((base) + (0x3C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_29_ADDR(base) ((base) + (0x3D) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_30_ADDR(base) ((base) + (0x3E) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_31_ADDR(base) ((base) + (0x3F) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_32_ADDR(base) ((base) + (0x40) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_33_ADDR(base) ((base) + (0x41) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_34_ADDR(base) ((base) + (0x42) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_35_ADDR(base) ((base) + (0x43) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_36_ADDR(base) ((base) + (0x44) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_37_ADDR(base) ((base) + (0x45) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_38_ADDR(base) ((base) + (0x46) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_39_ADDR(base) ((base) + (0x47) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_40_ADDR(base) ((base) + (0x48) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_41_ADDR(base) ((base) + (0x49) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_42_ADDR(base) ((base) + (0x4A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_43_ADDR(base) ((base) + (0x4B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_44_ADDR(base) ((base) + (0x4C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_45_ADDR(base) ((base) + (0x4D) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_46_ADDR(base) ((base) + (0x4E) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_47_ADDR(base) ((base) + (0x4F) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_48_ADDR(base) ((base) + (0x50) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_49_ADDR(base) ((base) + (0x51) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_50_ADDR(base) ((base) + (0x52) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_51_ADDR(base) ((base) + (0x53) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_52_ADDR(base) ((base) + (0x54) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_53_ADDR(base) ((base) + (0x55) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_54_ADDR(base) ((base) + (0x56) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_55_ADDR(base) ((base) + (0x57) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_56_ADDR(base) ((base) + (0x58) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_57_ADDR(base) ((base) + (0x59) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_58_ADDR(base) ((base) + (0x5A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_59_ADDR(base) ((base) + (0x5B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_60_ADDR(base) ((base) + (0x5C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_61_ADDR(base) ((base) + (0x5D) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_62_ADDR(base) ((base) + (0x5E) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_63_ADDR(base) ((base) + (0x5F) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_64_ADDR(base) ((base) + (0x60) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_65_ADDR(base) ((base) + (0x61) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_66_ADDR(base) ((base) + (0x62) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_67_ADDR(base) ((base) + (0x63) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_68_ADDR(base) ((base) + (0x64) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_69_ADDR(base) ((base) + (0x65) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_70_ADDR(base) ((base) + (0x66) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_71_ADDR(base) ((base) + (0x67) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_72_ADDR(base) ((base) + (0x68) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_73_ADDR(base) ((base) + (0x69) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_74_ADDR(base) ((base) + (0x6A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_75_ADDR(base) ((base) + (0x6B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_76_ADDR(base) ((base) + (0x6C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_77_ADDR(base) ((base) + (0x6D) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_78_ADDR(base) ((base) + (0x6E) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_79_ADDR(base) ((base) + (0x6F) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_80_ADDR(base) ((base) + (0x70) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_81_ADDR(base) ((base) + (0x71) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_82_ADDR(base) ((base) + (0x72) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_83_ADDR(base) ((base) + (0x73) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_84_ADDR(base) ((base) + (0x74) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_85_ADDR(base) ((base) + (0x75) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_86_ADDR(base) ((base) + (0x76) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_87_ADDR(base) ((base) + (0x77) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_88_ADDR(base) ((base) + (0x78) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_89_ADDR(base) ((base) + (0x79) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_90_ADDR(base) ((base) + (0x7A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_91_ADDR(base) ((base) + (0x7B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_92_ADDR(base) ((base) + (0x7C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_93_ADDR(base) ((base) + (0x7D) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_94_ADDR(base) ((base) + (0x7E) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_95_ADDR(base) ((base) + (0x7F) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_96_ADDR(base) ((base) + (0x80) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_97_ADDR(base) ((base) + (0x81) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_98_ADDR(base) ((base) + (0x82) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_99_ADDR(base) ((base) + (0x83) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_100_ADDR(base) ((base) + (0x84) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_101_ADDR(base) ((base) + (0x85) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_102_ADDR(base) ((base) + (0x86) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_103_ADDR(base) ((base) + (0x87) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_104_ADDR(base) ((base) + (0x88) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_105_ADDR(base) ((base) + (0x89) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_106_ADDR(base) ((base) + (0x8A) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_107_ADDR(base) ((base) + (0x8B) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_108_ADDR(base) ((base) + (0x8C) + REG_EFUSE_BASE)
#define SUB_PMIC_EFUSE_CFG_REG_109_ADDR(base) ((base) + (0x8D) + REG_EFUSE_BASE)
#endif
#define REG_NP_BASE (0x0600)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_LDP_PMUD_CFG_REG_ADDR(base) ((base) + (0x00UL) + REG_NP_BASE)
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_ADDR(base) ((base) + (0x01UL) + REG_NP_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_ADDR(base) ((base) + (0x02UL) + REG_NP_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_2_ADDR(base) ((base) + (0x03UL) + REG_NP_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_3_ADDR(base) ((base) + (0x04UL) + REG_NP_BASE)
#define SUB_PMIC_NP_CLK256K_ADDR(base) ((base) + (0x05UL) + REG_NP_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_ADDR(base) ((base) + (0x06UL) + REG_NP_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_3_ADDR(base) ((base) + (0x07UL) + REG_NP_BASE)
#define SUB_PMIC_NP_D2A_RESERVED_0_ADDR(base) ((base) + (0x08UL) + REG_NP_BASE)
#define SUB_PMIC_NP_D2A_RESERVED_1_ADDR(base) ((base) + (0x09UL) + REG_NP_BASE)
#define SUB_PMIC_NP_D2A_RESERVED_2_ADDR(base) ((base) + (0x0AUL) + REG_NP_BASE)
#define SUB_PMIC_NP_DEB_CTRL_ADDR(base) ((base) + (0x0BUL) + REG_NP_BASE)
#define SUB_PMIC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x0CUL) + REG_NP_BASE)
#define SUB_PMIC_NP_BUCK_ONOFF_ADDR(base) ((base) + (0x0DUL) + REG_NP_BASE)
#define SUB_PMIC_NP_PWROFF_MASK_ADDR(base) ((base) + (0x0EUL) + REG_NP_BASE)
#define SUB_PMIC_DIG_DEBUG_0_ADDR(base) ((base) + (0x0FUL) + REG_NP_BASE)
#define SUB_PMIC_DIG_DEBUG_1_ADDR(base) ((base) + (0x10UL) + REG_NP_BASE)
#define SUB_PMIC_NP_DEBUG_LOCK_ADDR(base) ((base) + (0x11UL) + REG_NP_BASE)
#define SUB_PMIC_DIG_IO_DS_SEL_ADDR(base) ((base) + (0x12UL) + REG_NP_BASE)
#define SUB_PMIC_DIG_IO_DS_CFG_ADDR(base) ((base) + (0x13UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_0_R_ADDR(base) ((base) + (0x20UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_1_R_ADDR(base) ((base) + (0x21UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_2_R_ADDR(base) ((base) + (0x22UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_3_R_ADDR(base) ((base) + (0x23UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_4_R_ADDR(base) ((base) + (0x24UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_5_R_ADDR(base) ((base) + (0x25UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_6_R_ADDR(base) ((base) + (0x26UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_7_R_ADDR(base) ((base) + (0x27UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_8_R_ADDR(base) ((base) + (0x28UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_9_R_ADDR(base) ((base) + (0x29UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_10_R_ADDR(base) ((base) + (0x2AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_11_R_ADDR(base) ((base) + (0x2BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_12_R_ADDR(base) ((base) + (0x2CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_13_R_ADDR(base) ((base) + (0x2DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_14_R_ADDR(base) ((base) + (0x2EUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_15_R_ADDR(base) ((base) + (0x2FUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_16_R_ADDR(base) ((base) + (0x30UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_17_R_ADDR(base) ((base) + (0x31UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_18_R_ADDR(base) ((base) + (0x32UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_19_R_ADDR(base) ((base) + (0x33UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_20_R_ADDR(base) ((base) + (0x34UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_21_R_ADDR(base) ((base) + (0x35UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_22_R_ADDR(base) ((base) + (0x36UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_23_R_ADDR(base) ((base) + (0x37UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_24_R_ADDR(base) ((base) + (0x38UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_25_R_ADDR(base) ((base) + (0x39UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_26_R_ADDR(base) ((base) + (0x3AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_27_R_ADDR(base) ((base) + (0x3BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_28_R_ADDR(base) ((base) + (0x3CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_29_R_ADDR(base) ((base) + (0x3DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_30_R_ADDR(base) ((base) + (0x3EUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_31_R_ADDR(base) ((base) + (0x3FUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_32_R_ADDR(base) ((base) + (0x40UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_33_R_ADDR(base) ((base) + (0x41UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_34_R_ADDR(base) ((base) + (0x42UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_35_R_ADDR(base) ((base) + (0x43UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_36_R_ADDR(base) ((base) + (0x44UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_37_R_ADDR(base) ((base) + (0x45UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_38_R_ADDR(base) ((base) + (0x46UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_39_R_ADDR(base) ((base) + (0x47UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_40_R_ADDR(base) ((base) + (0x48UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_41_R_ADDR(base) ((base) + (0x49UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_42_R_ADDR(base) ((base) + (0x4AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_43_R_ADDR(base) ((base) + (0x4BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_44_R_ADDR(base) ((base) + (0x4CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_45_R_ADDR(base) ((base) + (0x4DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_46_R_ADDR(base) ((base) + (0x4EUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_47_R_ADDR(base) ((base) + (0x4FUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_48_R_ADDR(base) ((base) + (0x50UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_49_R_ADDR(base) ((base) + (0x51UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_50_R_ADDR(base) ((base) + (0x52UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_51_R_ADDR(base) ((base) + (0x53UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_52_R_ADDR(base) ((base) + (0x54UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_53_R_ADDR(base) ((base) + (0x55UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_54_R_ADDR(base) ((base) + (0x56UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_55_R_ADDR(base) ((base) + (0x57UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_56_R_ADDR(base) ((base) + (0x58UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_57_R_ADDR(base) ((base) + (0x59UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_58_R_ADDR(base) ((base) + (0x5AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_59_R_ADDR(base) ((base) + (0x5BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_60_R_ADDR(base) ((base) + (0x5CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_61_R_ADDR(base) ((base) + (0x5DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_62_R_ADDR(base) ((base) + (0x5EUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_63_R_ADDR(base) ((base) + (0x5FUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_64_R_ADDR(base) ((base) + (0x60UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_65_R_ADDR(base) ((base) + (0x61UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_66_R_ADDR(base) ((base) + (0x62UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_67_R_ADDR(base) ((base) + (0x63UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_68_R_ADDR(base) ((base) + (0x64UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_69_R_ADDR(base) ((base) + (0x65UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_70_R_ADDR(base) ((base) + (0x66UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_71_R_ADDR(base) ((base) + (0x67UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_72_R_ADDR(base) ((base) + (0x68UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_73_R_ADDR(base) ((base) + (0x69UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_74_R_ADDR(base) ((base) + (0x6AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_75_R_ADDR(base) ((base) + (0x6BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_76_R_ADDR(base) ((base) + (0x6CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_77_R_ADDR(base) ((base) + (0x6DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_78_R_ADDR(base) ((base) + (0x6EUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_79_R_ADDR(base) ((base) + (0x6FUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_80_R_ADDR(base) ((base) + (0x70UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_81_R_ADDR(base) ((base) + (0x71UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_82_R_ADDR(base) ((base) + (0x72UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_83_R_ADDR(base) ((base) + (0x73UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_84_R_ADDR(base) ((base) + (0x74UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_85_R_ADDR(base) ((base) + (0x75UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_86_R_ADDR(base) ((base) + (0x76UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_87_R_ADDR(base) ((base) + (0x77UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_88_R_ADDR(base) ((base) + (0x78UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_89_R_ADDR(base) ((base) + (0x79UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_90_R_ADDR(base) ((base) + (0x7AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_91_R_ADDR(base) ((base) + (0x7BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_92_R_ADDR(base) ((base) + (0x7CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_93_R_ADDR(base) ((base) + (0x7DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_94_R_ADDR(base) ((base) + (0x7EUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_95_R_ADDR(base) ((base) + (0x7FUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_96_R_ADDR(base) ((base) + (0x80UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_97_R_ADDR(base) ((base) + (0x81UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_98_R_ADDR(base) ((base) + (0x82UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_99_R_ADDR(base) ((base) + (0x83UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_100_R_ADDR(base) ((base) + (0x84UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_101_R_ADDR(base) ((base) + (0x85UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_102_R_ADDR(base) ((base) + (0x86UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_103_R_ADDR(base) ((base) + (0x87UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_104_R_ADDR(base) ((base) + (0x88UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_105_R_ADDR(base) ((base) + (0x89UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_106_R_ADDR(base) ((base) + (0x8AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_107_R_ADDR(base) ((base) + (0x8BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_108_R_ADDR(base) ((base) + (0x8CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_109_R_ADDR(base) ((base) + (0x8DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_110_R_ADDR(base) ((base) + (0x8EUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_111_R_ADDR(base) ((base) + (0x8FUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_112_R_ADDR(base) ((base) + (0x90UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_113_R_ADDR(base) ((base) + (0x91UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_114_R_ADDR(base) ((base) + (0x92UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_115_R_ADDR(base) ((base) + (0x93UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_116_R_ADDR(base) ((base) + (0x94UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_117_R_ADDR(base) ((base) + (0x95UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_118_R_ADDR(base) ((base) + (0x96UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_119_R_ADDR(base) ((base) + (0x97UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_120_R_ADDR(base) ((base) + (0x98UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_121_R_ADDR(base) ((base) + (0x99UL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_122_R_ADDR(base) ((base) + (0x9AUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_123_R_ADDR(base) ((base) + (0x9BUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_124_R_ADDR(base) ((base) + (0x9CUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_125_R_ADDR(base) ((base) + (0x9DUL) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_126_R_ADDR(base) ((base) + (0x9EUL) + REG_NP_BASE)
#else
#define SUB_PMIC_LDP_PMUD_CFG_REG_ADDR(base) ((base) + (0x00) + REG_NP_BASE)
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_ADDR(base) ((base) + (0x01) + REG_NP_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_ADDR(base) ((base) + (0x02) + REG_NP_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_2_ADDR(base) ((base) + (0x03) + REG_NP_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_3_ADDR(base) ((base) + (0x04) + REG_NP_BASE)
#define SUB_PMIC_NP_CLK256K_ADDR(base) ((base) + (0x05) + REG_NP_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_ADDR(base) ((base) + (0x06) + REG_NP_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_3_ADDR(base) ((base) + (0x07) + REG_NP_BASE)
#define SUB_PMIC_NP_D2A_RESERVED_0_ADDR(base) ((base) + (0x08) + REG_NP_BASE)
#define SUB_PMIC_NP_D2A_RESERVED_1_ADDR(base) ((base) + (0x09) + REG_NP_BASE)
#define SUB_PMIC_NP_D2A_RESERVED_2_ADDR(base) ((base) + (0x0A) + REG_NP_BASE)
#define SUB_PMIC_NP_DEB_CTRL_ADDR(base) ((base) + (0x0B) + REG_NP_BASE)
#define SUB_PMIC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x0C) + REG_NP_BASE)
#define SUB_PMIC_NP_BUCK_ONOFF_ADDR(base) ((base) + (0x0D) + REG_NP_BASE)
#define SUB_PMIC_NP_PWROFF_MASK_ADDR(base) ((base) + (0x0E) + REG_NP_BASE)
#define SUB_PMIC_DIG_DEBUG_0_ADDR(base) ((base) + (0x0F) + REG_NP_BASE)
#define SUB_PMIC_DIG_DEBUG_1_ADDR(base) ((base) + (0x10) + REG_NP_BASE)
#define SUB_PMIC_NP_DEBUG_LOCK_ADDR(base) ((base) + (0x11) + REG_NP_BASE)
#define SUB_PMIC_DIG_IO_DS_SEL_ADDR(base) ((base) + (0x12) + REG_NP_BASE)
#define SUB_PMIC_DIG_IO_DS_CFG_ADDR(base) ((base) + (0x13) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_0_R_ADDR(base) ((base) + (0x20) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_1_R_ADDR(base) ((base) + (0x21) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_2_R_ADDR(base) ((base) + (0x22) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_3_R_ADDR(base) ((base) + (0x23) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_4_R_ADDR(base) ((base) + (0x24) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_5_R_ADDR(base) ((base) + (0x25) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_6_R_ADDR(base) ((base) + (0x26) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_7_R_ADDR(base) ((base) + (0x27) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_8_R_ADDR(base) ((base) + (0x28) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_9_R_ADDR(base) ((base) + (0x29) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_10_R_ADDR(base) ((base) + (0x2A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_11_R_ADDR(base) ((base) + (0x2B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_12_R_ADDR(base) ((base) + (0x2C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_13_R_ADDR(base) ((base) + (0x2D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_14_R_ADDR(base) ((base) + (0x2E) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_15_R_ADDR(base) ((base) + (0x2F) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_16_R_ADDR(base) ((base) + (0x30) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_17_R_ADDR(base) ((base) + (0x31) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_18_R_ADDR(base) ((base) + (0x32) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_19_R_ADDR(base) ((base) + (0x33) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_20_R_ADDR(base) ((base) + (0x34) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_21_R_ADDR(base) ((base) + (0x35) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_22_R_ADDR(base) ((base) + (0x36) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_23_R_ADDR(base) ((base) + (0x37) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_24_R_ADDR(base) ((base) + (0x38) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_25_R_ADDR(base) ((base) + (0x39) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_26_R_ADDR(base) ((base) + (0x3A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_27_R_ADDR(base) ((base) + (0x3B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_28_R_ADDR(base) ((base) + (0x3C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_29_R_ADDR(base) ((base) + (0x3D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_30_R_ADDR(base) ((base) + (0x3E) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_31_R_ADDR(base) ((base) + (0x3F) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_32_R_ADDR(base) ((base) + (0x40) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_33_R_ADDR(base) ((base) + (0x41) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_34_R_ADDR(base) ((base) + (0x42) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_35_R_ADDR(base) ((base) + (0x43) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_36_R_ADDR(base) ((base) + (0x44) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_37_R_ADDR(base) ((base) + (0x45) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_38_R_ADDR(base) ((base) + (0x46) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_39_R_ADDR(base) ((base) + (0x47) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_40_R_ADDR(base) ((base) + (0x48) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_41_R_ADDR(base) ((base) + (0x49) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_42_R_ADDR(base) ((base) + (0x4A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_43_R_ADDR(base) ((base) + (0x4B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_44_R_ADDR(base) ((base) + (0x4C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_45_R_ADDR(base) ((base) + (0x4D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_46_R_ADDR(base) ((base) + (0x4E) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_47_R_ADDR(base) ((base) + (0x4F) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_48_R_ADDR(base) ((base) + (0x50) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_49_R_ADDR(base) ((base) + (0x51) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_50_R_ADDR(base) ((base) + (0x52) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_51_R_ADDR(base) ((base) + (0x53) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_52_R_ADDR(base) ((base) + (0x54) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_53_R_ADDR(base) ((base) + (0x55) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_54_R_ADDR(base) ((base) + (0x56) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_55_R_ADDR(base) ((base) + (0x57) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_56_R_ADDR(base) ((base) + (0x58) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_57_R_ADDR(base) ((base) + (0x59) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_58_R_ADDR(base) ((base) + (0x5A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_59_R_ADDR(base) ((base) + (0x5B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_60_R_ADDR(base) ((base) + (0x5C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_61_R_ADDR(base) ((base) + (0x5D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_62_R_ADDR(base) ((base) + (0x5E) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_63_R_ADDR(base) ((base) + (0x5F) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_64_R_ADDR(base) ((base) + (0x60) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_65_R_ADDR(base) ((base) + (0x61) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_66_R_ADDR(base) ((base) + (0x62) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_67_R_ADDR(base) ((base) + (0x63) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_68_R_ADDR(base) ((base) + (0x64) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_69_R_ADDR(base) ((base) + (0x65) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_70_R_ADDR(base) ((base) + (0x66) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_71_R_ADDR(base) ((base) + (0x67) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_72_R_ADDR(base) ((base) + (0x68) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_73_R_ADDR(base) ((base) + (0x69) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_74_R_ADDR(base) ((base) + (0x6A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_75_R_ADDR(base) ((base) + (0x6B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_76_R_ADDR(base) ((base) + (0x6C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_77_R_ADDR(base) ((base) + (0x6D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_78_R_ADDR(base) ((base) + (0x6E) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_79_R_ADDR(base) ((base) + (0x6F) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_80_R_ADDR(base) ((base) + (0x70) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_81_R_ADDR(base) ((base) + (0x71) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_82_R_ADDR(base) ((base) + (0x72) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_83_R_ADDR(base) ((base) + (0x73) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_84_R_ADDR(base) ((base) + (0x74) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_85_R_ADDR(base) ((base) + (0x75) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_86_R_ADDR(base) ((base) + (0x76) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_87_R_ADDR(base) ((base) + (0x77) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_88_R_ADDR(base) ((base) + (0x78) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_89_R_ADDR(base) ((base) + (0x79) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_90_R_ADDR(base) ((base) + (0x7A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_91_R_ADDR(base) ((base) + (0x7B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_92_R_ADDR(base) ((base) + (0x7C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_93_R_ADDR(base) ((base) + (0x7D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_94_R_ADDR(base) ((base) + (0x7E) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_95_R_ADDR(base) ((base) + (0x7F) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_96_R_ADDR(base) ((base) + (0x80) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_97_R_ADDR(base) ((base) + (0x81) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_98_R_ADDR(base) ((base) + (0x82) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_99_R_ADDR(base) ((base) + (0x83) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_100_R_ADDR(base) ((base) + (0x84) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_101_R_ADDR(base) ((base) + (0x85) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_102_R_ADDR(base) ((base) + (0x86) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_103_R_ADDR(base) ((base) + (0x87) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_104_R_ADDR(base) ((base) + (0x88) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_105_R_ADDR(base) ((base) + (0x89) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_106_R_ADDR(base) ((base) + (0x8A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_107_R_ADDR(base) ((base) + (0x8B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_108_R_ADDR(base) ((base) + (0x8C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_109_R_ADDR(base) ((base) + (0x8D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_110_R_ADDR(base) ((base) + (0x8E) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_111_R_ADDR(base) ((base) + (0x8F) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_112_R_ADDR(base) ((base) + (0x90) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_113_R_ADDR(base) ((base) + (0x91) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_114_R_ADDR(base) ((base) + (0x92) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_115_R_ADDR(base) ((base) + (0x93) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_116_R_ADDR(base) ((base) + (0x94) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_117_R_ADDR(base) ((base) + (0x95) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_118_R_ADDR(base) ((base) + (0x96) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_119_R_ADDR(base) ((base) + (0x97) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_120_R_ADDR(base) ((base) + (0x98) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_121_R_ADDR(base) ((base) + (0x99) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_122_R_ADDR(base) ((base) + (0x9A) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_123_R_ADDR(base) ((base) + (0x9B) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_124_R_ADDR(base) ((base) + (0x9C) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_125_R_ADDR(base) ((base) + (0x9D) + REG_NP_BASE)
#define SUB_PMIC_EFUSE_126_R_ADDR(base) ((base) + (0x9E) + REG_NP_BASE)
#endif
#define PMU_SER_BASE (0x0C00)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK0_VSET_CFG_ADDR(base) ((base) + (0x00UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK0_EN_CFG_ADDR(base) ((base) + (0x01UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK2_VSET_CFG_ADDR(base) ((base) + (0x02UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK2_EN_CFG_ADDR(base) ((base) + (0x03UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK3_VSET_CFG_ADDR(base) ((base) + (0x04UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK3_EN_CFG_ADDR(base) ((base) + (0x05UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK4_VSET_CFG_ADDR(base) ((base) + (0x06UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK4_EN_CFG_ADDR(base) ((base) + (0x07UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK6_VSET_CFG_ADDR(base) ((base) + (0x08UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK6_EN_CFG_ADDR(base) ((base) + (0x09UL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK7_VSET_CFG_ADDR(base) ((base) + (0x0AUL) + PMU_SER_BASE)
#define SUB_PMIC_BUCK7_EN_CFG_ADDR(base) ((base) + (0x0BUL) + PMU_SER_BASE)
#define SUB_PMIC_LDO39_VSET_CFG_ADDR(base) ((base) + (0x0CUL) + PMU_SER_BASE)
#define SUB_PMIC_LDO39_EN_CFG_ADDR(base) ((base) + (0x0DUL) + PMU_SER_BASE)
#else
#define SUB_PMIC_BUCK0_VSET_CFG_ADDR(base) ((base) + (0x00) + PMU_SER_BASE)
#define SUB_PMIC_BUCK0_EN_CFG_ADDR(base) ((base) + (0x01) + PMU_SER_BASE)
#define SUB_PMIC_BUCK2_VSET_CFG_ADDR(base) ((base) + (0x02) + PMU_SER_BASE)
#define SUB_PMIC_BUCK2_EN_CFG_ADDR(base) ((base) + (0x03) + PMU_SER_BASE)
#define SUB_PMIC_BUCK3_VSET_CFG_ADDR(base) ((base) + (0x04) + PMU_SER_BASE)
#define SUB_PMIC_BUCK3_EN_CFG_ADDR(base) ((base) + (0x05) + PMU_SER_BASE)
#define SUB_PMIC_BUCK4_VSET_CFG_ADDR(base) ((base) + (0x06) + PMU_SER_BASE)
#define SUB_PMIC_BUCK4_EN_CFG_ADDR(base) ((base) + (0x07) + PMU_SER_BASE)
#define SUB_PMIC_BUCK6_VSET_CFG_ADDR(base) ((base) + (0x08) + PMU_SER_BASE)
#define SUB_PMIC_BUCK6_EN_CFG_ADDR(base) ((base) + (0x09) + PMU_SER_BASE)
#define SUB_PMIC_BUCK7_VSET_CFG_ADDR(base) ((base) + (0x0A) + PMU_SER_BASE)
#define SUB_PMIC_BUCK7_EN_CFG_ADDR(base) ((base) + (0x0B) + PMU_SER_BASE)
#define SUB_PMIC_LDO39_VSET_CFG_ADDR(base) ((base) + (0x0C) + PMU_SER_BASE)
#define SUB_PMIC_LDO39_EN_CFG_ADDR(base) ((base) + (0x0D) + PMU_SER_BASE)
#endif
#define REG_BUCK0123_NP_BASE (0x1000)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_NP_BUCK0_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_0_ADDR(base) ((base) + (0x05UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_1_ADDR(base) ((base) + (0x06UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_2_ADDR(base) ((base) + (0x07UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_3_ADDR(base) ((base) + (0x08UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_4_ADDR(base) ((base) + (0x09UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_0_ADDR(base) ((base) + (0x0AUL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_1_ADDR(base) ((base) + (0x0BUL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_2_ADDR(base) ((base) + (0x0CUL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_3_ADDR(base) ((base) + (0x0DUL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_4_ADDR(base) ((base) + (0x0EUL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_0_ADDR(base) ((base) + (0x0FUL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_1_ADDR(base) ((base) + (0x10UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_2_ADDR(base) ((base) + (0x11UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_3_ADDR(base) ((base) + (0x12UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_4_ADDR(base) ((base) + (0x13UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_0_ADDR(base) ((base) + (0x14UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_1_ADDR(base) ((base) + (0x15UL) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_2_ADDR(base) ((base) + (0x16UL) + REG_BUCK0123_NP_BASE)
#else
#define SUB_PMIC_NP_BUCK0_CFG_REG_0_ADDR(base) ((base) + (0x00) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_1_ADDR(base) ((base) + (0x01) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_2_ADDR(base) ((base) + (0x02) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_3_ADDR(base) ((base) + (0x03) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0_CFG_REG_4_ADDR(base) ((base) + (0x04) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_0_ADDR(base) ((base) + (0x05) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_1_ADDR(base) ((base) + (0x06) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_2_ADDR(base) ((base) + (0x07) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_3_ADDR(base) ((base) + (0x08) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK1_CFG_REG_4_ADDR(base) ((base) + (0x09) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_0_ADDR(base) ((base) + (0x0A) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_1_ADDR(base) ((base) + (0x0B) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_2_ADDR(base) ((base) + (0x0C) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_3_ADDR(base) ((base) + (0x0D) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK2_CFG_REG_4_ADDR(base) ((base) + (0x0E) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_0_ADDR(base) ((base) + (0x0F) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_1_ADDR(base) ((base) + (0x10) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_2_ADDR(base) ((base) + (0x11) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_3_ADDR(base) ((base) + (0x12) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK3_CFG_REG_4_ADDR(base) ((base) + (0x13) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_0_ADDR(base) ((base) + (0x14) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_1_ADDR(base) ((base) + (0x15) + REG_BUCK0123_NP_BASE)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_2_ADDR(base) ((base) + (0x16) + REG_BUCK0123_NP_BASE)
#endif
#define REG_BUCK4567_NP_BASE (0x1100)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_NP_BUCK4_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_0_ADDR(base) ((base) + (0x05UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_1_ADDR(base) ((base) + (0x06UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_2_ADDR(base) ((base) + (0x07UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_3_ADDR(base) ((base) + (0x08UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_4_ADDR(base) ((base) + (0x09UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_0_ADDR(base) ((base) + (0x0AUL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_1_ADDR(base) ((base) + (0x0BUL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_2_ADDR(base) ((base) + (0x0CUL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_3_ADDR(base) ((base) + (0x0DUL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_4_ADDR(base) ((base) + (0x0EUL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_0_ADDR(base) ((base) + (0x0FUL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_1_ADDR(base) ((base) + (0x10UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_2_ADDR(base) ((base) + (0x11UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_3_ADDR(base) ((base) + (0x12UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_4_ADDR(base) ((base) + (0x13UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_0_ADDR(base) ((base) + (0x14UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_1_ADDR(base) ((base) + (0x15UL) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_2_ADDR(base) ((base) + (0x16UL) + REG_BUCK4567_NP_BASE)
#else
#define SUB_PMIC_NP_BUCK4_CFG_REG_0_ADDR(base) ((base) + (0x00) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_1_ADDR(base) ((base) + (0x01) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_2_ADDR(base) ((base) + (0x02) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_3_ADDR(base) ((base) + (0x03) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4_CFG_REG_4_ADDR(base) ((base) + (0x04) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_0_ADDR(base) ((base) + (0x05) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_1_ADDR(base) ((base) + (0x06) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_2_ADDR(base) ((base) + (0x07) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_3_ADDR(base) ((base) + (0x08) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK5_CFG_REG_4_ADDR(base) ((base) + (0x09) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_0_ADDR(base) ((base) + (0x0A) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_1_ADDR(base) ((base) + (0x0B) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_2_ADDR(base) ((base) + (0x0C) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_3_ADDR(base) ((base) + (0x0D) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK6_CFG_REG_4_ADDR(base) ((base) + (0x0E) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_0_ADDR(base) ((base) + (0x0F) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_1_ADDR(base) ((base) + (0x10) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_2_ADDR(base) ((base) + (0x11) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_3_ADDR(base) ((base) + (0x12) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK7_CFG_REG_4_ADDR(base) ((base) + (0x13) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_0_ADDR(base) ((base) + (0x14) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_1_ADDR(base) ((base) + (0x15) + REG_BUCK4567_NP_BASE)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_2_ADDR(base) ((base) + (0x16) + REG_BUCK4567_NP_BASE)
#endif
#define PMU_CTRL_ANA_LDO_REG_BASE (0x1200)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_LDO39_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO39_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO_PMUH_CFG_REG_0_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO_PMUH_CFG_REG_1_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO_RESERVE_CFG_REG_0_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_OSC_9M6_CFG_REG_1_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_1_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_LDO_REG_BASE)
#else
#define SUB_PMIC_LDO39_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO39_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO_PMUH_CFG_REG_0_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO_PMUH_CFG_REG_1_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_LDO_RESERVE_CFG_REG_0_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_OSC_9M6_CFG_REG_1_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_LDO_REG_BASE)
#define SUB_PMIC_SYS_CTRL_CFG_REG_1_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_LDO_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK0_REG_BASE (0x1300)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK0_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_51_ADDR(base) ((base) + (0x33UL) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#else
#define SUB_PMIC_BUCK0_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#define SUB_PMIC_BUCK0_CFG_REG_51_ADDR(base) ((base) + (0x33) + PMU_CTRL_ANA_BUCK0_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK1_REG_BASE (0x1400)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK1_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_51_ADDR(base) ((base) + (0x33UL) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#else
#define SUB_PMIC_BUCK1_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#define SUB_PMIC_BUCK1_CFG_REG_51_ADDR(base) ((base) + (0x33) + PMU_CTRL_ANA_BUCK1_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK2_REG_BASE (0x1500)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK2_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_51_ADDR(base) ((base) + (0x33UL) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#else
#define SUB_PMIC_BUCK2_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#define SUB_PMIC_BUCK2_CFG_REG_51_ADDR(base) ((base) + (0x33) + PMU_CTRL_ANA_BUCK2_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK3_REG_BASE (0x1600)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK3_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_51_ADDR(base) ((base) + (0x33UL) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#else
#define SUB_PMIC_BUCK3_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#define SUB_PMIC_BUCK3_CFG_REG_51_ADDR(base) ((base) + (0x33) + PMU_CTRL_ANA_BUCK3_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK0123_REG_BASE (0x1700)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#else
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK0123_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK4_REG_BASE (0x1800)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK4_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#else
#define SUB_PMIC_BUCK4_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#define SUB_PMIC_BUCK4_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK4_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK5_REG_BASE (0x1900)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK5_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#else
#define SUB_PMIC_BUCK5_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#define SUB_PMIC_BUCK5_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK5_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK6_REG_BASE (0x1A00)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK6_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#else
#define SUB_PMIC_BUCK6_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#define SUB_PMIC_BUCK6_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK6_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK7_REG_BASE (0x1B00)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK7_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_16_ADDR(base) ((base) + (0x10UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_17_ADDR(base) ((base) + (0x11UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_18_ADDR(base) ((base) + (0x12UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_19_ADDR(base) ((base) + (0x13UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_20_ADDR(base) ((base) + (0x14UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_21_ADDR(base) ((base) + (0x15UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_22_ADDR(base) ((base) + (0x16UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_23_ADDR(base) ((base) + (0x17UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_24_ADDR(base) ((base) + (0x18UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_25_ADDR(base) ((base) + (0x19UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_26_ADDR(base) ((base) + (0x1AUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_27_ADDR(base) ((base) + (0x1BUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_28_ADDR(base) ((base) + (0x1CUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_29_ADDR(base) ((base) + (0x1DUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_30_ADDR(base) ((base) + (0x1EUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_31_ADDR(base) ((base) + (0x1FUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_32_ADDR(base) ((base) + (0x20UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_33_ADDR(base) ((base) + (0x21UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_34_ADDR(base) ((base) + (0x22UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_35_ADDR(base) ((base) + (0x23UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_36_ADDR(base) ((base) + (0x24UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_37_ADDR(base) ((base) + (0x25UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_38_ADDR(base) ((base) + (0x26UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_39_ADDR(base) ((base) + (0x27UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_40_ADDR(base) ((base) + (0x28UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_41_ADDR(base) ((base) + (0x29UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_42_ADDR(base) ((base) + (0x2AUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_43_ADDR(base) ((base) + (0x2BUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_44_ADDR(base) ((base) + (0x2CUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_45_ADDR(base) ((base) + (0x2DUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_46_ADDR(base) ((base) + (0x2EUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_47_ADDR(base) ((base) + (0x2FUL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_48_ADDR(base) ((base) + (0x30UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_49_ADDR(base) ((base) + (0x31UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_50_ADDR(base) ((base) + (0x32UL) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#else
#define SUB_PMIC_BUCK7_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_16_ADDR(base) ((base) + (0x10) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_17_ADDR(base) ((base) + (0x11) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_18_ADDR(base) ((base) + (0x12) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_19_ADDR(base) ((base) + (0x13) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_20_ADDR(base) ((base) + (0x14) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_21_ADDR(base) ((base) + (0x15) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_22_ADDR(base) ((base) + (0x16) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_23_ADDR(base) ((base) + (0x17) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_24_ADDR(base) ((base) + (0x18) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_25_ADDR(base) ((base) + (0x19) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_26_ADDR(base) ((base) + (0x1A) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_27_ADDR(base) ((base) + (0x1B) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_28_ADDR(base) ((base) + (0x1C) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_29_ADDR(base) ((base) + (0x1D) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_30_ADDR(base) ((base) + (0x1E) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_31_ADDR(base) ((base) + (0x1F) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_32_ADDR(base) ((base) + (0x20) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_33_ADDR(base) ((base) + (0x21) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_34_ADDR(base) ((base) + (0x22) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_35_ADDR(base) ((base) + (0x23) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_36_ADDR(base) ((base) + (0x24) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_37_ADDR(base) ((base) + (0x25) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_38_ADDR(base) ((base) + (0x26) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_39_ADDR(base) ((base) + (0x27) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_40_ADDR(base) ((base) + (0x28) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_41_ADDR(base) ((base) + (0x29) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_42_ADDR(base) ((base) + (0x2A) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_43_ADDR(base) ((base) + (0x2B) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_44_ADDR(base) ((base) + (0x2C) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_45_ADDR(base) ((base) + (0x2D) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_46_ADDR(base) ((base) + (0x2E) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_47_ADDR(base) ((base) + (0x2F) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_48_ADDR(base) ((base) + (0x30) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_49_ADDR(base) ((base) + (0x31) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#define SUB_PMIC_BUCK7_CFG_REG_50_ADDR(base) ((base) + (0x32) + PMU_CTRL_ANA_BUCK7_REG_BASE)
#endif
#define PMU_CTRL_ANA_BUCK4567_REG_BASE (0x1C00)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_0_ADDR(base) ((base) + (0x00UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_1_ADDR(base) ((base) + (0x01UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_2_ADDR(base) ((base) + (0x02UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_3_ADDR(base) ((base) + (0x03UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_4_ADDR(base) ((base) + (0x04UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_5_ADDR(base) ((base) + (0x05UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_6_ADDR(base) ((base) + (0x06UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_7_ADDR(base) ((base) + (0x07UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_8_ADDR(base) ((base) + (0x08UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_9_ADDR(base) ((base) + (0x09UL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_10_ADDR(base) ((base) + (0x0AUL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_11_ADDR(base) ((base) + (0x0BUL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_12_ADDR(base) ((base) + (0x0CUL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_13_ADDR(base) ((base) + (0x0DUL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_14_ADDR(base) ((base) + (0x0EUL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_15_ADDR(base) ((base) + (0x0FUL) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#else
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_0_ADDR(base) ((base) + (0x00) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_1_ADDR(base) ((base) + (0x01) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_2_ADDR(base) ((base) + (0x02) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_3_ADDR(base) ((base) + (0x03) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_4_ADDR(base) ((base) + (0x04) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_5_ADDR(base) ((base) + (0x05) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_6_ADDR(base) ((base) + (0x06) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_7_ADDR(base) ((base) + (0x07) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_8_ADDR(base) ((base) + (0x08) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_9_ADDR(base) ((base) + (0x09) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_10_ADDR(base) ((base) + (0x0A) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_11_ADDR(base) ((base) + (0x0B) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_12_ADDR(base) ((base) + (0x0C) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_13_ADDR(base) ((base) + (0x0D) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_14_ADDR(base) ((base) + (0x0E) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_15_ADDR(base) ((base) + (0x0F) + PMU_CTRL_ANA_BUCK4567_REG_BASE)
#endif
#define SUB_FER_BASE (0x1D00)
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_FER_CTRL_ADDR(base) ((base) + (0x0000UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_EVENT_LEVEL_ADDR(base) ((base) + (0x0001UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_PG_MSK_ADDR(base) ((base) + (0x0002UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_VOK_MSK_ADDR(base) ((base) + (0x0003UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_OC_MSK_ADDR(base) ((base) + (0x0004UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_OT_MSK_ADDR(base) ((base) + (0x0005UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_PMU_PSOK_MSK_ADDR(base) ((base) + (0x0006UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_PMU_IRQ_MSK0_ADDR(base) ((base) + (0x0007UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_PMU_IRQ_MSK1_ADDR(base) ((base) + (0x008UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_BUCK_PGVOK_ADDR(base) ((base) + (0x0009UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_BUCK_OCOT_ADDR(base) ((base) + (0x000aUL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_PMU_PSOK_ADDR(base) ((base) + (0x000bUL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_PMU_IRQ0_ADDR(base) ((base) + (0x000cUL) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_PMU_IRQ1_ADDR(base) ((base) + (0x000dUL) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_ABIT_DATA_ADDR(base) ((base) + (0x000eUL) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_ABIT_ADDR_ADDR(base) ((base) + (0x000fUL) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_SRBIT_DATA_ADDR(base) ((base) + (0x0010UL) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_SRBIT_ADDR_ADDR(base) ((base) + (0x0011UL) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG0_ADDR(base) ((base) + (0x0040UL) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG1_ADDR(base) ((base) + (0x0041UL) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG2_ADDR(base) ((base) + (0x0042UL) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG3_ADDR(base) ((base) + (0x0043UL) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG4_ADDR(base) ((base) + (0x0044UL) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG5_ADDR(base) ((base) + (0x0045UL) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG6_ADDR(base) ((base) + (0x0046UL) + SUB_FER_BASE)
#else
#define SUB_PMIC_FER_CTRL_ADDR(base) ((base) + (0x0000) + SUB_FER_BASE)
#define SUB_PMIC_FER_EVENT_LEVEL_ADDR(base) ((base) + (0x0001) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_PG_MSK_ADDR(base) ((base) + (0x0002) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_VOK_MSK_ADDR(base) ((base) + (0x0003) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_OC_MSK_ADDR(base) ((base) + (0x0004) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUCK_OT_MSK_ADDR(base) ((base) + (0x0005) + SUB_FER_BASE)
#define SUB_PMIC_FER_PMU_PSOK_MSK_ADDR(base) ((base) + (0x0006) + SUB_FER_BASE)
#define SUB_PMIC_FER_PMU_IRQ_MSK0_ADDR(base) ((base) + (0x0007) + SUB_FER_BASE)
#define SUB_PMIC_FER_PMU_IRQ_MSK1_ADDR(base) ((base) + (0x008) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_BUCK_PGVOK_ADDR(base) ((base) + (0x0009) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_BUCK_OCOT_ADDR(base) ((base) + (0x000a) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_PMU_PSOK_ADDR(base) ((base) + (0x000b) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_PMU_IRQ0_ADDR(base) ((base) + (0x000c) + SUB_FER_BASE)
#define SUB_PMIC_FER_BUF_PMU_IRQ1_ADDR(base) ((base) + (0x000d) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_ABIT_DATA_ADDR(base) ((base) + (0x000e) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_ABIT_ADDR_ADDR(base) ((base) + (0x000f) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_SRBIT_DATA_ADDR(base) ((base) + (0x0010) + SUB_FER_BASE)
#define SUB_PMIC_FER_TRANS_SRBIT_ADDR_ADDR(base) ((base) + (0x0011) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG0_ADDR(base) ((base) + (0x0040) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG1_ADDR(base) ((base) + (0x0041) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG2_ADDR(base) ((base) + (0x0042) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG3_ADDR(base) ((base) + (0x0043) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG4_ADDR(base) ((base) + (0x0044) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG5_ADDR(base) ((base) + (0x0045) + SUB_FER_BASE)
#define SUB_PMIC_SPMI_DEBUG6_ADDR(base) ((base) + (0x0046) + SUB_FER_BASE)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num0 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_1_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_1_project_num0_START (0)
#define SUB_PMIC_CHIP_VERSION_1_project_num0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num1 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_2_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_2_project_num1_START (0)
#define SUB_PMIC_CHIP_VERSION_2_project_num1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num2 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_3_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_3_project_num2_START (0)
#define SUB_PMIC_CHIP_VERSION_3_project_num2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num3 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_4_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_4_project_num3_START (0)
#define SUB_PMIC_CHIP_VERSION_4_project_num3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char version : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_5_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_5_version_START (0)
#define SUB_PMIC_CHIP_VERSION_5_version_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_0_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_0_chip_id_START (0)
#define SUB_PMIC_CHIP_VERSION_0_chip_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char vsys_pwroff_abs_ro : 1;
        unsigned char vsys_ov_ro : 1;
        unsigned char vin_ldo39_vld_ro : 1;
        unsigned char vin_3p45_vld_ro : 1;
        unsigned char pmuh_short_n_ro : 1;
        unsigned char vsys_pwron_ro : 1;
        unsigned char ad_pmu1_en_ro : 1;
        unsigned char ad_bst_max_sel : 1;
    } reg;
} SUB_PMIC_SYS_CTRL_RO_REG_1_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vsys_pwroff_abs_ro_START (0)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vsys_pwroff_abs_ro_END (0)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vsys_ov_ro_START (1)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vsys_ov_ro_END (1)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vin_ldo39_vld_ro_START (2)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vin_ldo39_vld_ro_END (2)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vin_3p45_vld_ro_START (3)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vin_3p45_vld_ro_END (3)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_pmuh_short_n_ro_START (4)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_pmuh_short_n_ro_END (4)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vsys_pwron_ro_START (5)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_vsys_pwron_ro_END (5)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_ad_pmu1_en_ro_START (6)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_ad_pmu1_en_ro_END (6)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_ad_bst_max_sel_START (7)
#define SUB_PMIC_SYS_CTRL_RO_REG_1_ad_bst_max_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char thsd_otmp140_ro : 1;
        unsigned char thsd_otmp125_ro : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_SYS_CTRL_RO_REG_2_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_RO_REG_2_thsd_otmp140_ro_START (0)
#define SUB_PMIC_SYS_CTRL_RO_REG_2_thsd_otmp140_ro_END (0)
#define SUB_PMIC_SYS_CTRL_RO_REG_2_thsd_otmp125_ro_START (1)
#define SUB_PMIC_SYS_CTRL_RO_REG_2_thsd_otmp125_ro_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_pg_ro : 1;
        unsigned char buck2_pg_ro : 1;
        unsigned char buck3_pg_ro : 1;
        unsigned char buck4_pg_ro : 1;
        unsigned char buck6_pg_ro : 1;
        unsigned char buck7_pg_ro : 1;
        unsigned char ldo39_pg_ro : 1;
        unsigned char reserved : 1;
    } reg;
} SUB_PMIC_PG_STATUS_UNION;
#endif
#define SUB_PMIC_PG_STATUS_buck0_pg_ro_START (0)
#define SUB_PMIC_PG_STATUS_buck0_pg_ro_END (0)
#define SUB_PMIC_PG_STATUS_buck2_pg_ro_START (1)
#define SUB_PMIC_PG_STATUS_buck2_pg_ro_END (1)
#define SUB_PMIC_PG_STATUS_buck3_pg_ro_START (2)
#define SUB_PMIC_PG_STATUS_buck3_pg_ro_END (2)
#define SUB_PMIC_PG_STATUS_buck4_pg_ro_START (3)
#define SUB_PMIC_PG_STATUS_buck4_pg_ro_END (3)
#define SUB_PMIC_PG_STATUS_buck6_pg_ro_START (4)
#define SUB_PMIC_PG_STATUS_buck6_pg_ro_END (4)
#define SUB_PMIC_PG_STATUS_buck7_pg_ro_START (5)
#define SUB_PMIC_PG_STATUS_buck7_pg_ro_END (5)
#define SUB_PMIC_PG_STATUS_ldo39_pg_ro_START (6)
#define SUB_PMIC_PG_STATUS_ldo39_pg_ro_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_vok_ana_ro : 1;
        unsigned char buck0_vok_ana_ro : 1;
        unsigned char buck2_vok_ana_ro : 1;
        unsigned char buck3_vok_ana_ro : 1;
        unsigned char buck4_vok_ana_ro : 1;
        unsigned char buck6_vok_ana_ro : 1;
        unsigned char buck7_vok_ana_ro : 1;
        unsigned char reserved : 1;
    } reg;
} SUB_PMIC_VOK_STATUS_UNION;
#endif
#define SUB_PMIC_VOK_STATUS_ldo39_vok_ana_ro_START (0)
#define SUB_PMIC_VOK_STATUS_ldo39_vok_ana_ro_END (0)
#define SUB_PMIC_VOK_STATUS_buck0_vok_ana_ro_START (1)
#define SUB_PMIC_VOK_STATUS_buck0_vok_ana_ro_END (1)
#define SUB_PMIC_VOK_STATUS_buck2_vok_ana_ro_START (2)
#define SUB_PMIC_VOK_STATUS_buck2_vok_ana_ro_END (2)
#define SUB_PMIC_VOK_STATUS_buck3_vok_ana_ro_START (3)
#define SUB_PMIC_VOK_STATUS_buck3_vok_ana_ro_END (3)
#define SUB_PMIC_VOK_STATUS_buck4_vok_ana_ro_START (4)
#define SUB_PMIC_VOK_STATUS_buck4_vok_ana_ro_END (4)
#define SUB_PMIC_VOK_STATUS_buck6_vok_ana_ro_START (5)
#define SUB_PMIC_VOK_STATUS_buck6_vok_ana_ro_END (5)
#define SUB_PMIC_VOK_STATUS_buck7_vok_ana_ro_START (6)
#define SUB_PMIC_VOK_STATUS_buck7_vok_ana_ro_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_state_flag : 2;
        unsigned char buck2_state_flag : 2;
        unsigned char buck3_state_flag : 2;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_STATUS_FLG_0_UNION;
#endif
#define SUB_PMIC_STATUS_FLG_0_buck0_state_flag_START (0)
#define SUB_PMIC_STATUS_FLG_0_buck0_state_flag_END (1)
#define SUB_PMIC_STATUS_FLG_0_buck2_state_flag_START (2)
#define SUB_PMIC_STATUS_FLG_0_buck2_state_flag_END (3)
#define SUB_PMIC_STATUS_FLG_0_buck3_state_flag_START (4)
#define SUB_PMIC_STATUS_FLG_0_buck3_state_flag_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_state_flag : 2;
        unsigned char buck6_state_flag : 2;
        unsigned char buck7_state_flag : 2;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_STATUS_FLG_1_UNION;
#endif
#define SUB_PMIC_STATUS_FLG_1_buck4_state_flag_START (0)
#define SUB_PMIC_STATUS_FLG_1_buck4_state_flag_END (1)
#define SUB_PMIC_STATUS_FLG_1_buck6_state_flag_START (2)
#define SUB_PMIC_STATUS_FLG_1_buck6_state_flag_END (3)
#define SUB_PMIC_STATUS_FLG_1_buck7_state_flag_START (4)
#define SUB_PMIC_STATUS_FLG_1_buck7_state_flag_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char thsd_en : 1;
        unsigned char thsd_en_sel : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_THSD_EN_REG_UNION;
#endif
#define SUB_PMIC_THSD_EN_REG_thsd_en_START (0)
#define SUB_PMIC_THSD_EN_REG_thsd_en_END (0)
#define SUB_PMIC_THSD_EN_REG_thsd_en_sel_START (1)
#define SUB_PMIC_THSD_EN_REG_thsd_en_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmud_vset : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_LDO_PMUD_VSET_CFG_UNION;
#endif
#define SUB_PMIC_LDO_PMUD_VSET_CFG_pmud_vset_START (0)
#define SUB_PMIC_LDO_PMUD_VSET_CFG_pmud_vset_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_vset : 3;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_LDO_PMUH_VSET_CFG_UNION;
#endif
#define SUB_PMIC_LDO_PMUH_VSET_CFG_pmuh_vset_START (0)
#define SUB_PMIC_LDO_PMUH_VSET_CFG_pmuh_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_pmuh_en : 1;
        unsigned char st_pmuh_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_pmuh_eco_en : 1;
        unsigned char st_pmuh_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_LDO_PMUH_CFG_UNION;
#endif
#define SUB_PMIC_LDO_PMUH_CFG_reg_pmuh_en_START (0)
#define SUB_PMIC_LDO_PMUH_CFG_reg_pmuh_en_END (0)
#define SUB_PMIC_LDO_PMUH_CFG_st_pmuh_en_START (1)
#define SUB_PMIC_LDO_PMUH_CFG_st_pmuh_en_END (1)
#define SUB_PMIC_LDO_PMUH_CFG_reg_pmuh_eco_en_START (4)
#define SUB_PMIC_LDO_PMUH_CFG_reg_pmuh_eco_en_END (4)
#define SUB_PMIC_LDO_PMUH_CFG_st_pmuh_eco_en_START (5)
#define SUB_PMIC_LDO_PMUH_CFG_st_pmuh_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_oc_deb_sel : 2;
        unsigned char buck_sc_deb_sel : 2;
        unsigned char buck_ov_deb_sel : 2;
        unsigned char temp_alert_deb_sel : 2;
    } reg;
} SUB_PMIC_DEB_CTRL_UNION;
#endif
#define SUB_PMIC_DEB_CTRL_buck_oc_deb_sel_START (0)
#define SUB_PMIC_DEB_CTRL_buck_oc_deb_sel_END (1)
#define SUB_PMIC_DEB_CTRL_buck_sc_deb_sel_START (2)
#define SUB_PMIC_DEB_CTRL_buck_sc_deb_sel_END (3)
#define SUB_PMIC_DEB_CTRL_buck_ov_deb_sel_START (4)
#define SUB_PMIC_DEB_CTRL_buck_ov_deb_sel_END (5)
#define SUB_PMIC_DEB_CTRL_temp_alert_deb_sel_START (6)
#define SUB_PMIC_DEB_CTRL_temp_alert_deb_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char temp_damage_deb_sel : 2;
        unsigned char oc_level_deb_sel : 2;
        unsigned char otmp140_deb_sel : 2;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_DEB_CTRL_1_UNION;
#endif
#define SUB_PMIC_DEB_CTRL_1_temp_damage_deb_sel_START (0)
#define SUB_PMIC_DEB_CTRL_1_temp_damage_deb_sel_END (1)
#define SUB_PMIC_DEB_CTRL_1_oc_level_deb_sel_START (2)
#define SUB_PMIC_DEB_CTRL_1_oc_level_deb_sel_END (3)
#define SUB_PMIC_DEB_CTRL_1_otmp140_deb_sel_START (4)
#define SUB_PMIC_DEB_CTRL_1_otmp140_deb_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_ocp_deb_sel : 2;
        unsigned char filter_en_pmuh_ocp : 1;
        unsigned char ldo39_ocp_deb_sel : 2;
        unsigned char filter_en_ldo39_ocp : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_DEB_CTRL_2_UNION;
#endif
#define SUB_PMIC_DEB_CTRL_2_pmuh_ocp_deb_sel_START (0)
#define SUB_PMIC_DEB_CTRL_2_pmuh_ocp_deb_sel_END (1)
#define SUB_PMIC_DEB_CTRL_2_filter_en_pmuh_ocp_START (2)
#define SUB_PMIC_DEB_CTRL_2_filter_en_pmuh_ocp_END (2)
#define SUB_PMIC_DEB_CTRL_2_ldo39_ocp_deb_sel_START (3)
#define SUB_PMIC_DEB_CTRL_2_ldo39_ocp_deb_sel_END (4)
#define SUB_PMIC_DEB_CTRL_2_filter_en_ldo39_ocp_START (5)
#define SUB_PMIC_DEB_CTRL_2_filter_en_ldo39_ocp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_loadline0_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_0_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_0_buck0_loadline0_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_0_buck0_loadline0_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_loadline1_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_1_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_1_buck0_loadline1_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_1_buck0_loadline1_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_loadline2_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_2_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_2_buck0_loadline2_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_2_buck0_loadline2_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_loadline3_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_3_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_3_buck0_loadline3_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_3_buck0_loadline3_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_loadline0_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_4_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_4_buck3_loadline0_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_4_buck3_loadline0_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_loadline1_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_5_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_5_buck3_loadline1_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_5_buck3_loadline1_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_loadline2_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_6_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_6_buck3_loadline2_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_6_buck3_loadline2_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_loadline3_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_7_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_7_buck3_loadline3_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_7_buck3_loadline3_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_loadline0_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_8_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_8_buck4_loadline0_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_8_buck4_loadline0_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_loadline1_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_9_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_9_buck4_loadline1_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_9_buck4_loadline1_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_loadline2_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_10_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_10_buck4_loadline2_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_10_buck4_loadline2_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_loadline3_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_11_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_11_buck4_loadline3_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_11_buck4_loadline3_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_loadline0_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_12_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_12_buck7_loadline0_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_12_buck7_loadline0_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_loadline1_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_13_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_13_buck7_loadline1_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_13_buck7_loadline1_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_loadline2_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_14_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_14_buck7_loadline2_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_14_buck7_loadline2_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_loadline3_vset : 8;
    } reg;
} SUB_PMIC_LOADLINE_CTRL_15_UNION;
#endif
#define SUB_PMIC_LOADLINE_CTRL_15_buck7_loadline3_vset_START (0)
#define SUB_PMIC_LOADLINE_CTRL_15_buck7_loadline3_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_loadline_cmp_en : 1;
        unsigned char buck0_loadline_en_cfg : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_LOADLINE_EN_0_UNION;
#endif
#define SUB_PMIC_LOADLINE_EN_0_buck0_loadline_cmp_en_START (0)
#define SUB_PMIC_LOADLINE_EN_0_buck0_loadline_cmp_en_END (0)
#define SUB_PMIC_LOADLINE_EN_0_buck0_loadline_en_cfg_START (1)
#define SUB_PMIC_LOADLINE_EN_0_buck0_loadline_en_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_loadline_cmp_en : 1;
        unsigned char buck3_loadline_en_cfg : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_LOADLINE_EN_1_UNION;
#endif
#define SUB_PMIC_LOADLINE_EN_1_buck3_loadline_cmp_en_START (0)
#define SUB_PMIC_LOADLINE_EN_1_buck3_loadline_cmp_en_END (0)
#define SUB_PMIC_LOADLINE_EN_1_buck3_loadline_en_cfg_START (1)
#define SUB_PMIC_LOADLINE_EN_1_buck3_loadline_en_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_loadline_cmp_en : 1;
        unsigned char buck4_loadline_en_cfg : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_LOADLINE_EN_2_UNION;
#endif
#define SUB_PMIC_LOADLINE_EN_2_buck4_loadline_cmp_en_START (0)
#define SUB_PMIC_LOADLINE_EN_2_buck4_loadline_cmp_en_END (0)
#define SUB_PMIC_LOADLINE_EN_2_buck4_loadline_en_cfg_START (1)
#define SUB_PMIC_LOADLINE_EN_2_buck4_loadline_en_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_loadline_cmp_en : 1;
        unsigned char buck7_loadline_en_cfg : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_LOADLINE_EN_3_UNION;
#endif
#define SUB_PMIC_LOADLINE_EN_3_buck7_loadline_cmp_en_START (0)
#define SUB_PMIC_LOADLINE_EN_3_buck7_loadline_cmp_en_END (0)
#define SUB_PMIC_LOADLINE_EN_3_buck7_loadline_en_cfg_START (1)
#define SUB_PMIC_LOADLINE_EN_3_buck7_loadline_en_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck0_oc_en : 1;
        unsigned char buck0_oc_mode : 1;
        unsigned char buck0_oc_step_sel : 3;
        unsigned char oc_fer_buck0_mode : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_CFG_0_UNION;
#endif
#define SUB_PMIC_OC_FER_CFG_0_reg_buck0_oc_en_START (0)
#define SUB_PMIC_OC_FER_CFG_0_reg_buck0_oc_en_END (0)
#define SUB_PMIC_OC_FER_CFG_0_buck0_oc_mode_START (1)
#define SUB_PMIC_OC_FER_CFG_0_buck0_oc_mode_END (1)
#define SUB_PMIC_OC_FER_CFG_0_buck0_oc_step_sel_START (2)
#define SUB_PMIC_OC_FER_CFG_0_buck0_oc_step_sel_END (4)
#define SUB_PMIC_OC_FER_CFG_0_oc_fer_buck0_mode_START (5)
#define SUB_PMIC_OC_FER_CFG_0_oc_fer_buck0_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck2_oc_en : 1;
        unsigned char buck2_oc_mode : 1;
        unsigned char buck2_oc_step_sel : 3;
        unsigned char oc_fer_buck2_mode : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_CFG_1_UNION;
#endif
#define SUB_PMIC_OC_FER_CFG_1_reg_buck2_oc_en_START (0)
#define SUB_PMIC_OC_FER_CFG_1_reg_buck2_oc_en_END (0)
#define SUB_PMIC_OC_FER_CFG_1_buck2_oc_mode_START (1)
#define SUB_PMIC_OC_FER_CFG_1_buck2_oc_mode_END (1)
#define SUB_PMIC_OC_FER_CFG_1_buck2_oc_step_sel_START (2)
#define SUB_PMIC_OC_FER_CFG_1_buck2_oc_step_sel_END (4)
#define SUB_PMIC_OC_FER_CFG_1_oc_fer_buck2_mode_START (5)
#define SUB_PMIC_OC_FER_CFG_1_oc_fer_buck2_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck3_oc_en : 1;
        unsigned char buck3_oc_mode : 1;
        unsigned char buck3_oc_step_sel : 3;
        unsigned char oc_fer_buck3_mode : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_CFG_2_UNION;
#endif
#define SUB_PMIC_OC_FER_CFG_2_reg_buck3_oc_en_START (0)
#define SUB_PMIC_OC_FER_CFG_2_reg_buck3_oc_en_END (0)
#define SUB_PMIC_OC_FER_CFG_2_buck3_oc_mode_START (1)
#define SUB_PMIC_OC_FER_CFG_2_buck3_oc_mode_END (1)
#define SUB_PMIC_OC_FER_CFG_2_buck3_oc_step_sel_START (2)
#define SUB_PMIC_OC_FER_CFG_2_buck3_oc_step_sel_END (4)
#define SUB_PMIC_OC_FER_CFG_2_oc_fer_buck3_mode_START (5)
#define SUB_PMIC_OC_FER_CFG_2_oc_fer_buck3_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck4_oc_en : 1;
        unsigned char buck4_oc_mode : 1;
        unsigned char buck4_oc_step_sel : 3;
        unsigned char oc_fer_buck4_mode : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_CFG_3_UNION;
#endif
#define SUB_PMIC_OC_FER_CFG_3_reg_buck4_oc_en_START (0)
#define SUB_PMIC_OC_FER_CFG_3_reg_buck4_oc_en_END (0)
#define SUB_PMIC_OC_FER_CFG_3_buck4_oc_mode_START (1)
#define SUB_PMIC_OC_FER_CFG_3_buck4_oc_mode_END (1)
#define SUB_PMIC_OC_FER_CFG_3_buck4_oc_step_sel_START (2)
#define SUB_PMIC_OC_FER_CFG_3_buck4_oc_step_sel_END (4)
#define SUB_PMIC_OC_FER_CFG_3_oc_fer_buck4_mode_START (5)
#define SUB_PMIC_OC_FER_CFG_3_oc_fer_buck4_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck6_oc_en : 1;
        unsigned char buck6_oc_mode : 1;
        unsigned char buck6_oc_step_sel : 3;
        unsigned char oc_fer_buck6_mode : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_CFG_4_UNION;
#endif
#define SUB_PMIC_OC_FER_CFG_4_reg_buck6_oc_en_START (0)
#define SUB_PMIC_OC_FER_CFG_4_reg_buck6_oc_en_END (0)
#define SUB_PMIC_OC_FER_CFG_4_buck6_oc_mode_START (1)
#define SUB_PMIC_OC_FER_CFG_4_buck6_oc_mode_END (1)
#define SUB_PMIC_OC_FER_CFG_4_buck6_oc_step_sel_START (2)
#define SUB_PMIC_OC_FER_CFG_4_buck6_oc_step_sel_END (4)
#define SUB_PMIC_OC_FER_CFG_4_oc_fer_buck6_mode_START (5)
#define SUB_PMIC_OC_FER_CFG_4_oc_fer_buck6_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck7_oc_en : 1;
        unsigned char buck7_oc_mode : 1;
        unsigned char buck7_oc_step_sel : 3;
        unsigned char oc_fer_buck7_mode : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_CFG_5_UNION;
#endif
#define SUB_PMIC_OC_FER_CFG_5_reg_buck7_oc_en_START (0)
#define SUB_PMIC_OC_FER_CFG_5_reg_buck7_oc_en_END (0)
#define SUB_PMIC_OC_FER_CFG_5_buck7_oc_mode_START (1)
#define SUB_PMIC_OC_FER_CFG_5_buck7_oc_mode_END (1)
#define SUB_PMIC_OC_FER_CFG_5_buck7_oc_step_sel_START (2)
#define SUB_PMIC_OC_FER_CFG_5_buck7_oc_step_sel_END (4)
#define SUB_PMIC_OC_FER_CFG_5_oc_fer_buck7_mode_START (5)
#define SUB_PMIC_OC_FER_CFG_5_oc_fer_buck7_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char vsys_ov_off_mk : 1;
        unsigned char vsys_pwroff_abs_off_mk : 1;
        unsigned char vsys_otmp_140_off_mk : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_VOK_PWR_OFF_MASK_CFG_UNION;
#endif
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_vsys_ov_off_mk_START (0)
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_vsys_ov_off_mk_END (0)
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_vsys_pwroff_abs_off_mk_START (1)
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_vsys_pwroff_abs_off_mk_END (1)
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_vsys_otmp_140_off_mk_START (2)
#define SUB_PMIC_VOK_PWR_OFF_MASK_CFG_vsys_otmp_140_off_mk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve0 : 8;
    } reg;
} SUB_PMIC_D2A_RESVER0_UNION;
#endif
#define SUB_PMIC_D2A_RESVER0_d2a_reserve0_START (0)
#define SUB_PMIC_D2A_RESVER0_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve1 : 8;
    } reg;
} SUB_PMIC_D2A_RESVER1_UNION;
#endif
#define SUB_PMIC_D2A_RESVER1_d2a_reserve1_START (0)
#define SUB_PMIC_D2A_RESVER1_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve2 : 8;
    } reg;
} SUB_PMIC_D2A_RESVER2_UNION;
#endif
#define SUB_PMIC_D2A_RESVER2_d2a_reserve2_START (0)
#define SUB_PMIC_D2A_RESVER2_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve0 : 8;
    } reg;
} SUB_PMIC_A2D_RESVER0_UNION;
#endif
#define SUB_PMIC_A2D_RESVER0_a2d_reserve0_START (0)
#define SUB_PMIC_A2D_RESVER0_a2d_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve1 : 8;
    } reg;
} SUB_PMIC_A2D_RESVER1_UNION;
#endif
#define SUB_PMIC_A2D_RESVER1_a2d_reserve1_START (0)
#define SUB_PMIC_A2D_RESVER1_a2d_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve2 : 8;
    } reg;
} SUB_PMIC_A2D_RESVER2_UNION;
#endif
#define SUB_PMIC_A2D_RESVER2_a2d_reserve2_START (0)
#define SUB_PMIC_A2D_RESVER2_a2d_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve3 : 8;
    } reg;
} SUB_PMIC_A2D_RESVER3_UNION;
#endif
#define SUB_PMIC_A2D_RESVER3_a2d_reserve3_START (0)
#define SUB_PMIC_A2D_RESVER3_a2d_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve4 : 8;
    } reg;
} SUB_PMIC_A2D_RESVER4_UNION;
#endif
#define SUB_PMIC_A2D_RESVER4_a2d_reserve4_START (0)
#define SUB_PMIC_A2D_RESVER4_a2d_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_dummy_spmi : 4;
        unsigned char st_dummy_spmi : 4;
    } reg;
} SUB_PMIC_DUMMY_SPMI_UNION;
#endif
#define SUB_PMIC_DUMMY_SPMI_sc_dummy_spmi_START (0)
#define SUB_PMIC_DUMMY_SPMI_sc_dummy_spmi_END (3)
#define SUB_PMIC_DUMMY_SPMI_st_dummy_spmi_START (4)
#define SUB_PMIC_DUMMY_SPMI_st_dummy_spmi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_9m6_en : 8;
    } reg;
} SUB_PMIC_REG_9M6_EN_UNION;
#endif
#define SUB_PMIC_REG_9M6_EN_reg_9m6_en_START (0)
#define SUB_PMIC_REG_9M6_EN_reg_9m6_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_9m6_off : 8;
    } reg;
} SUB_PMIC_REG_9M6_OFF_UNION;
#endif
#define SUB_PMIC_REG_9M6_OFF_reg_9m6_off_START (0)
#define SUB_PMIC_REG_9M6_OFF_reg_9m6_off_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_rampdown_rate : 3;
        unsigned char buck0_rampdown_en_cfg : 1;
        unsigned char buck0_rampup_rate : 3;
        unsigned char buck0_rampup_en_cfg : 1;
    } reg;
} SUB_PMIC_BUCK0_RAMP_CFG_UNION;
#endif
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampdown_rate_START (0)
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampdown_rate_END (2)
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampdown_en_cfg_START (3)
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampdown_en_cfg_END (3)
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampup_rate_START (4)
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampup_rate_END (6)
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampup_en_cfg_START (7)
#define SUB_PMIC_BUCK0_RAMP_CFG_buck0_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck0_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK0_RAMP_CHG_VSET_UNION;
#endif
#define SUB_PMIC_BUCK0_RAMP_CHG_VSET_buck0_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK0_RAMP_CHG_VSET_buck0_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK0_RAMP_CHG_VSET_buck0_rampup_chg_vset_START (4)
#define SUB_PMIC_BUCK0_RAMP_CHG_VSET_buck0_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_rampdown_chg_rate : 2;
        unsigned char buck0_rampdown_nochg_rate_sel : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck0_rampup_chg_rate : 2;
        unsigned char buck0_rampup_nochg_rate_sel : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK0_RAMP_CHG_CFG_UNION;
#endif
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampdown_chg_rate_START (0)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampdown_chg_rate_END (1)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampdown_nochg_rate_sel_START (2)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampdown_nochg_rate_sel_END (2)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampup_chg_rate_START (4)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampup_chg_rate_END (5)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampup_nochg_rate_sel_START (6)
#define SUB_PMIC_BUCK0_RAMP_CHG_CFG_buck0_rampup_nochg_rate_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck0_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK0_DLY_RU_CFG_UNION;
#endif
#define SUB_PMIC_BUCK0_DLY_RU_CFG_buck0_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK0_DLY_RU_CFG_buck0_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK0_DLY_RU_CFG_buck0_dly_ru_on_cfg_START (4)
#define SUB_PMIC_BUCK0_DLY_RU_CFG_buck0_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck0_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK0_DLY_RD_CFG_UNION;
#endif
#define SUB_PMIC_BUCK0_DLY_RD_CFG_buck0_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK0_DLY_RD_CFG_buck0_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK0_DLY_RD_CFG_buck0_dly_rd_on_cfg_START (4)
#define SUB_PMIC_BUCK0_DLY_RD_CFG_buck0_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_dly_rd_vok : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck0_dly_ru_vok : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK0_DLY_VOK_CFG_UNION;
#endif
#define SUB_PMIC_BUCK0_DLY_VOK_CFG_buck0_dly_rd_vok_START (0)
#define SUB_PMIC_BUCK0_DLY_VOK_CFG_buck0_dly_rd_vok_END (2)
#define SUB_PMIC_BUCK0_DLY_VOK_CFG_buck0_dly_ru_vok_START (4)
#define SUB_PMIC_BUCK0_DLY_VOK_CFG_buck0_dly_ru_vok_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampdown_rate : 3;
        unsigned char buck2_rampdown_en_cfg : 1;
        unsigned char buck2_rampup_rate : 3;
        unsigned char buck2_rampup_en_cfg : 1;
    } reg;
} SUB_PMIC_BUCK2_RAMP_CFG_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_rate_START (0)
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_rate_END (2)
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_en_cfg_START (3)
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_en_cfg_END (3)
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampup_rate_START (4)
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampup_rate_END (6)
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampup_en_cfg_START (7)
#define SUB_PMIC_BUCK2_RAMP_CFG_buck2_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck2_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK2_RAMP_CHG_VSET_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMP_CHG_VSET_buck2_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK2_RAMP_CHG_VSET_buck2_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK2_RAMP_CHG_VSET_buck2_rampup_chg_vset_START (4)
#define SUB_PMIC_BUCK2_RAMP_CHG_VSET_buck2_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampdown_chg_rate : 2;
        unsigned char buck2_rampdown_nochg_rate_sel : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck2_rampup_chg_rate : 2;
        unsigned char buck2_rampup_nochg_rate_sel : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK2_RAMP_CHG_CFG_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampdown_chg_rate_START (0)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampdown_chg_rate_END (1)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampdown_nochg_rate_sel_START (2)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampdown_nochg_rate_sel_END (2)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampup_chg_rate_START (4)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampup_chg_rate_END (5)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampup_nochg_rate_sel_START (6)
#define SUB_PMIC_BUCK2_RAMP_CHG_CFG_buck2_rampup_nochg_rate_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck2_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK2_DLY_RU_CFG_UNION;
#endif
#define SUB_PMIC_BUCK2_DLY_RU_CFG_buck2_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK2_DLY_RU_CFG_buck2_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK2_DLY_RU_CFG_buck2_dly_ru_on_cfg_START (4)
#define SUB_PMIC_BUCK2_DLY_RU_CFG_buck2_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck2_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK2_DLY_RD_CFG_UNION;
#endif
#define SUB_PMIC_BUCK2_DLY_RD_CFG_buck2_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK2_DLY_RD_CFG_buck2_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK2_DLY_RD_CFG_buck2_dly_rd_on_cfg_START (4)
#define SUB_PMIC_BUCK2_DLY_RD_CFG_buck2_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_dly_rd_vok : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck2_dly_ru_vok : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK2_DLY_VOK_CFG_UNION;
#endif
#define SUB_PMIC_BUCK2_DLY_VOK_CFG_buck2_dly_rd_vok_START (0)
#define SUB_PMIC_BUCK2_DLY_VOK_CFG_buck2_dly_rd_vok_END (2)
#define SUB_PMIC_BUCK2_DLY_VOK_CFG_buck2_dly_ru_vok_START (4)
#define SUB_PMIC_BUCK2_DLY_VOK_CFG_buck2_dly_ru_vok_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampdown_rate : 3;
        unsigned char buck3_rampdown_en_cfg : 1;
        unsigned char buck3_rampup_rate : 3;
        unsigned char buck3_rampup_en_cfg : 1;
    } reg;
} SUB_PMIC_BUCK3_RAMP_CFG_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_rate_START (0)
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_rate_END (2)
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_en_cfg_START (3)
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_en_cfg_END (3)
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampup_rate_START (4)
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampup_rate_END (6)
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampup_en_cfg_START (7)
#define SUB_PMIC_BUCK3_RAMP_CFG_buck3_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck3_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK3_RAMP_CHG_VSET_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMP_CHG_VSET_buck3_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK3_RAMP_CHG_VSET_buck3_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK3_RAMP_CHG_VSET_buck3_rampup_chg_vset_START (4)
#define SUB_PMIC_BUCK3_RAMP_CHG_VSET_buck3_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampdown_chg_rate : 2;
        unsigned char buck3_rampdown_nochg_rate_sel : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck3_rampup_chg_rate : 2;
        unsigned char buck3_rampup_nochg_rate_sel : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK3_RAMP_CHG_CFG_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampdown_chg_rate_START (0)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampdown_chg_rate_END (1)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampdown_nochg_rate_sel_START (2)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampdown_nochg_rate_sel_END (2)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampup_chg_rate_START (4)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampup_chg_rate_END (5)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampup_nochg_rate_sel_START (6)
#define SUB_PMIC_BUCK3_RAMP_CHG_CFG_buck3_rampup_nochg_rate_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck3_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK3_DLY_RU_CFG_UNION;
#endif
#define SUB_PMIC_BUCK3_DLY_RU_CFG_buck3_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK3_DLY_RU_CFG_buck3_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK3_DLY_RU_CFG_buck3_dly_ru_on_cfg_START (4)
#define SUB_PMIC_BUCK3_DLY_RU_CFG_buck3_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck3_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK3_DLY_RD_CFG_UNION;
#endif
#define SUB_PMIC_BUCK3_DLY_RD_CFG_buck3_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK3_DLY_RD_CFG_buck3_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK3_DLY_RD_CFG_buck3_dly_rd_on_cfg_START (4)
#define SUB_PMIC_BUCK3_DLY_RD_CFG_buck3_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_dly_rd_vok : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck3_dly_ru_vok : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK3_DLY_VOK_CFG_UNION;
#endif
#define SUB_PMIC_BUCK3_DLY_VOK_CFG_buck3_dly_rd_vok_START (0)
#define SUB_PMIC_BUCK3_DLY_VOK_CFG_buck3_dly_rd_vok_END (2)
#define SUB_PMIC_BUCK3_DLY_VOK_CFG_buck3_dly_ru_vok_START (4)
#define SUB_PMIC_BUCK3_DLY_VOK_CFG_buck3_dly_ru_vok_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_rampdown_rate : 3;
        unsigned char buck4_rampdown_en_cfg : 1;
        unsigned char buck4_rampup_rate : 3;
        unsigned char buck4_rampup_en_cfg : 1;
    } reg;
} SUB_PMIC_BUCK4_RAMP_CFG_UNION;
#endif
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampdown_rate_START (0)
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampdown_rate_END (2)
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampdown_en_cfg_START (3)
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampdown_en_cfg_END (3)
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampup_rate_START (4)
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampup_rate_END (6)
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampup_en_cfg_START (7)
#define SUB_PMIC_BUCK4_RAMP_CFG_buck4_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck4_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK4_RAMP_CHG_VSET_UNION;
#endif
#define SUB_PMIC_BUCK4_RAMP_CHG_VSET_buck4_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK4_RAMP_CHG_VSET_buck4_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK4_RAMP_CHG_VSET_buck4_rampup_chg_vset_START (4)
#define SUB_PMIC_BUCK4_RAMP_CHG_VSET_buck4_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_rampdown_chg_rate : 2;
        unsigned char buck4_rampdown_nochg_rate_sel : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck4_rampup_chg_rate : 2;
        unsigned char buck4_rampup_nochg_rate_sel : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK4_RAMP_CHG_CFG_UNION;
#endif
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampdown_chg_rate_START (0)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampdown_chg_rate_END (1)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampdown_nochg_rate_sel_START (2)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampdown_nochg_rate_sel_END (2)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampup_chg_rate_START (4)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampup_chg_rate_END (5)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampup_nochg_rate_sel_START (6)
#define SUB_PMIC_BUCK4_RAMP_CHG_CFG_buck4_rampup_nochg_rate_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck4_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK4_DLY_RU_CFG_UNION;
#endif
#define SUB_PMIC_BUCK4_DLY_RU_CFG_buck4_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK4_DLY_RU_CFG_buck4_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK4_DLY_RU_CFG_buck4_dly_ru_on_cfg_START (4)
#define SUB_PMIC_BUCK4_DLY_RU_CFG_buck4_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck4_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK4_DLY_RD_CFG_UNION;
#endif
#define SUB_PMIC_BUCK4_DLY_RD_CFG_buck4_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK4_DLY_RD_CFG_buck4_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK4_DLY_RD_CFG_buck4_dly_rd_on_cfg_START (4)
#define SUB_PMIC_BUCK4_DLY_RD_CFG_buck4_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_dly_rd_vok : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck4_dly_ru_vok : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK4_DLY_VOK_CFG_UNION;
#endif
#define SUB_PMIC_BUCK4_DLY_VOK_CFG_buck4_dly_rd_vok_START (0)
#define SUB_PMIC_BUCK4_DLY_VOK_CFG_buck4_dly_rd_vok_END (2)
#define SUB_PMIC_BUCK4_DLY_VOK_CFG_buck4_dly_ru_vok_START (4)
#define SUB_PMIC_BUCK4_DLY_VOK_CFG_buck4_dly_ru_vok_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_rampdown_rate : 3;
        unsigned char buck6_rampdown_en_cfg : 1;
        unsigned char buck6_rampup_rate : 3;
        unsigned char buck6_rampup_en_cfg : 1;
    } reg;
} SUB_PMIC_BUCK6_RAMP_CFG_UNION;
#endif
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampdown_rate_START (0)
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampdown_rate_END (2)
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampdown_en_cfg_START (3)
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampdown_en_cfg_END (3)
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampup_rate_START (4)
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampup_rate_END (6)
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampup_en_cfg_START (7)
#define SUB_PMIC_BUCK6_RAMP_CFG_buck6_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck6_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK6_RAMP_CHG_VSET_UNION;
#endif
#define SUB_PMIC_BUCK6_RAMP_CHG_VSET_buck6_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK6_RAMP_CHG_VSET_buck6_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK6_RAMP_CHG_VSET_buck6_rampup_chg_vset_START (4)
#define SUB_PMIC_BUCK6_RAMP_CHG_VSET_buck6_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_rampdown_chg_rate : 2;
        unsigned char buck6_rampdown_nochg_rate_sel : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck6_rampup_chg_rate : 2;
        unsigned char buck6_rampup_nochg_rate_sel : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK6_RAMP_CHG_CFG_UNION;
#endif
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampdown_chg_rate_START (0)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampdown_chg_rate_END (1)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampdown_nochg_rate_sel_START (2)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampdown_nochg_rate_sel_END (2)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampup_chg_rate_START (4)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampup_chg_rate_END (5)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampup_nochg_rate_sel_START (6)
#define SUB_PMIC_BUCK6_RAMP_CHG_CFG_buck6_rampup_nochg_rate_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck6_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK6_DLY_RU_CFG_UNION;
#endif
#define SUB_PMIC_BUCK6_DLY_RU_CFG_buck6_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK6_DLY_RU_CFG_buck6_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK6_DLY_RU_CFG_buck6_dly_ru_on_cfg_START (4)
#define SUB_PMIC_BUCK6_DLY_RU_CFG_buck6_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck6_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK6_DLY_RD_CFG_UNION;
#endif
#define SUB_PMIC_BUCK6_DLY_RD_CFG_buck6_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK6_DLY_RD_CFG_buck6_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK6_DLY_RD_CFG_buck6_dly_rd_on_cfg_START (4)
#define SUB_PMIC_BUCK6_DLY_RD_CFG_buck6_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_dly_rd_vok : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck6_dly_ru_vok : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK6_DLY_VOK_CFG_UNION;
#endif
#define SUB_PMIC_BUCK6_DLY_VOK_CFG_buck6_dly_rd_vok_START (0)
#define SUB_PMIC_BUCK6_DLY_VOK_CFG_buck6_dly_rd_vok_END (2)
#define SUB_PMIC_BUCK6_DLY_VOK_CFG_buck6_dly_ru_vok_START (4)
#define SUB_PMIC_BUCK6_DLY_VOK_CFG_buck6_dly_ru_vok_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_rampdown_rate : 3;
        unsigned char buck7_rampdown_en_cfg : 1;
        unsigned char buck7_rampup_rate : 3;
        unsigned char buck7_rampup_en_cfg : 1;
    } reg;
} SUB_PMIC_BUCK7_RAMP_CFG_UNION;
#endif
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampdown_rate_START (0)
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampdown_rate_END (2)
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampdown_en_cfg_START (3)
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampdown_en_cfg_END (3)
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampup_rate_START (4)
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampup_rate_END (6)
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampup_en_cfg_START (7)
#define SUB_PMIC_BUCK7_RAMP_CFG_buck7_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck7_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK7_RAMP_CHG_VSET_UNION;
#endif
#define SUB_PMIC_BUCK7_RAMP_CHG_VSET_buck7_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK7_RAMP_CHG_VSET_buck7_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK7_RAMP_CHG_VSET_buck7_rampup_chg_vset_START (4)
#define SUB_PMIC_BUCK7_RAMP_CHG_VSET_buck7_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_rampdown_chg_rate : 2;
        unsigned char buck7_rampdown_nochg_rate_sel : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck7_rampup_chg_rate : 2;
        unsigned char buck7_rampup_nochg_rate_sel : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK7_RAMP_CHG_CFG_UNION;
#endif
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampdown_chg_rate_START (0)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampdown_chg_rate_END (1)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampdown_nochg_rate_sel_START (2)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampdown_nochg_rate_sel_END (2)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampup_chg_rate_START (4)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampup_chg_rate_END (5)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampup_nochg_rate_sel_START (6)
#define SUB_PMIC_BUCK7_RAMP_CHG_CFG_buck7_rampup_nochg_rate_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck7_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK7_DLY_RU_CFG_UNION;
#endif
#define SUB_PMIC_BUCK7_DLY_RU_CFG_buck7_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK7_DLY_RU_CFG_buck7_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK7_DLY_RU_CFG_buck7_dly_ru_on_cfg_START (4)
#define SUB_PMIC_BUCK7_DLY_RU_CFG_buck7_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck7_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK7_DLY_RD_CFG_UNION;
#endif
#define SUB_PMIC_BUCK7_DLY_RD_CFG_buck7_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK7_DLY_RD_CFG_buck7_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK7_DLY_RD_CFG_buck7_dly_rd_on_cfg_START (4)
#define SUB_PMIC_BUCK7_DLY_RD_CFG_buck7_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_dly_rd_vok : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck7_dly_ru_vok : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK7_DLY_VOK_CFG_UNION;
#endif
#define SUB_PMIC_BUCK7_DLY_VOK_CFG_buck7_dly_rd_vok_START (0)
#define SUB_PMIC_BUCK7_DLY_VOK_CFG_buck7_dly_rd_vok_END (2)
#define SUB_PMIC_BUCK7_DLY_VOK_CFG_buck7_dly_ru_vok_START (4)
#define SUB_PMIC_BUCK7_DLY_VOK_CFG_buck7_dly_ru_vok_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_rampdown_rate : 3;
        unsigned char ldo39_rampdown_en_cfg : 1;
        unsigned char ldo39_rampup_rate : 3;
        unsigned char ldo39_rampup_en_cfg : 1;
    } reg;
} SUB_PMIC_LDO39_RAMP_CFG_UNION;
#endif
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampdown_rate_START (0)
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampdown_rate_END (2)
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampdown_en_cfg_START (3)
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampdown_en_cfg_END (3)
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampup_rate_START (4)
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampup_rate_END (6)
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampup_en_cfg_START (7)
#define SUB_PMIC_LDO39_RAMP_CFG_ldo39_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_dly_pd_off_cfg : 3;
        unsigned char ldo39_dly_pd_on_cfg : 3;
        unsigned char ldo39_pull_down_cfg : 1;
        unsigned char ldo39_pull_down_mode : 1;
    } reg;
} SUB_PMIC_LDO39_DLY_PD_CFG_UNION;
#endif
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_dly_pd_off_cfg_START (0)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_dly_pd_off_cfg_END (2)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_dly_pd_on_cfg_START (3)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_dly_pd_on_cfg_END (5)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_pull_down_cfg_START (6)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_pull_down_cfg_END (6)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_pull_down_mode_START (7)
#define SUB_PMIC_LDO39_DLY_PD_CFG_ldo39_pull_down_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_dly_rd_vok : 3;
        unsigned char reserved_0 : 1;
        unsigned char ldo39_dly_ru_vok : 3;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_LDO39_DLY_VOK_CFG_UNION;
#endif
#define SUB_PMIC_LDO39_DLY_VOK_CFG_ldo39_dly_rd_vok_START (0)
#define SUB_PMIC_LDO39_DLY_VOK_CFG_ldo39_dly_rd_vok_END (2)
#define SUB_PMIC_LDO39_DLY_VOK_CFG_ldo39_dly_ru_vok_START (4)
#define SUB_PMIC_LDO39_DLY_VOK_CFG_ldo39_dly_ru_vok_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char cpum_buck_sel : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_CPUM_BUCK_SEL_UNION;
#endif
#define SUB_PMIC_CPUM_BUCK_SEL_cpum_buck_sel_START (0)
#define SUB_PMIC_CPUM_BUCK_SEL_cpum_buck_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char vok_sel : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_VOK_CFG_UNION;
#endif
#define SUB_PMIC_VOK_CFG_vok_sel_START (0)
#define SUB_PMIC_VOK_CFG_vok_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ramp_gt_debug : 8;
    } reg;
} SUB_PMIC_RAMP_GATE_DEBUG_UNION;
#endif
#define SUB_PMIC_RAMP_GATE_DEBUG_ramp_gt_debug_START (0)
#define SUB_PMIC_RAMP_GATE_DEBUG_ramp_gt_debug_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_cpum_vset : 8;
    } reg;
} SUB_PMIC_RAMP_CPUM_RO_UNION;
#endif
#define SUB_PMIC_RAMP_CPUM_RO_st_cpum_vset_START (0)
#define SUB_PMIC_RAMP_CPUM_RO_st_cpum_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_mem_vset : 6;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_RAMP_MEM_RO_UNION;
#endif
#define SUB_PMIC_RAMP_MEM_RO_st_mem_vset_START (0)
#define SUB_PMIC_RAMP_MEM_RO_st_mem_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_ramp_state : 1;
        unsigned char buck2_ramp_state : 1;
        unsigned char buck3_ramp_state : 1;
        unsigned char buck4_ramp_state : 1;
        unsigned char buck6_ramp_state : 1;
        unsigned char buck7_ramp_state : 1;
        unsigned char ldo39_ramp_state : 1;
        unsigned char reserved : 1;
    } reg;
} SUB_PMIC_RAMP_STATE_RO_UNION;
#endif
#define SUB_PMIC_RAMP_STATE_RO_buck0_ramp_state_START (0)
#define SUB_PMIC_RAMP_STATE_RO_buck0_ramp_state_END (0)
#define SUB_PMIC_RAMP_STATE_RO_buck2_ramp_state_START (1)
#define SUB_PMIC_RAMP_STATE_RO_buck2_ramp_state_END (1)
#define SUB_PMIC_RAMP_STATE_RO_buck3_ramp_state_START (2)
#define SUB_PMIC_RAMP_STATE_RO_buck3_ramp_state_END (2)
#define SUB_PMIC_RAMP_STATE_RO_buck4_ramp_state_START (3)
#define SUB_PMIC_RAMP_STATE_RO_buck4_ramp_state_END (3)
#define SUB_PMIC_RAMP_STATE_RO_buck6_ramp_state_START (4)
#define SUB_PMIC_RAMP_STATE_RO_buck6_ramp_state_END (4)
#define SUB_PMIC_RAMP_STATE_RO_buck7_ramp_state_START (5)
#define SUB_PMIC_RAMP_STATE_RO_buck7_ramp_state_END (5)
#define SUB_PMIC_RAMP_STATE_RO_ldo39_ramp_state_START (6)
#define SUB_PMIC_RAMP_STATE_RO_ldo39_ramp_state_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_0_mk : 1;
        unsigned char irq_1_mk : 1;
        unsigned char irq_2_mk : 1;
        unsigned char irq_3_mk : 1;
        unsigned char irq_4_mk : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_IRQ1_MASK_UNION;
#endif
#define SUB_PMIC_IRQ1_MASK_irq_0_mk_START (0)
#define SUB_PMIC_IRQ1_MASK_irq_0_mk_END (0)
#define SUB_PMIC_IRQ1_MASK_irq_1_mk_START (1)
#define SUB_PMIC_IRQ1_MASK_irq_1_mk_END (1)
#define SUB_PMIC_IRQ1_MASK_irq_2_mk_START (2)
#define SUB_PMIC_IRQ1_MASK_irq_2_mk_END (2)
#define SUB_PMIC_IRQ1_MASK_irq_3_mk_START (3)
#define SUB_PMIC_IRQ1_MASK_irq_3_mk_END (3)
#define SUB_PMIC_IRQ1_MASK_irq_4_mk_START (4)
#define SUB_PMIC_IRQ1_MASK_irq_4_mk_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char vsys_ov_mk : 1;
        unsigned char vsys_pwron_mk : 1;
        unsigned char vsys_pwroff_abs_mk : 1;
        unsigned char vin_ldo39_vld_mk : 1;
        unsigned char vin_3p45_vld_mk : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_PWR_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_PWR_IRQ_MASK_vsys_ov_mk_START (0)
#define SUB_PMIC_PWR_IRQ_MASK_vsys_ov_mk_END (0)
#define SUB_PMIC_PWR_IRQ_MASK_vsys_pwron_mk_START (1)
#define SUB_PMIC_PWR_IRQ_MASK_vsys_pwron_mk_END (1)
#define SUB_PMIC_PWR_IRQ_MASK_vsys_pwroff_abs_mk_START (2)
#define SUB_PMIC_PWR_IRQ_MASK_vsys_pwroff_abs_mk_END (2)
#define SUB_PMIC_PWR_IRQ_MASK_vin_ldo39_vld_mk_START (3)
#define SUB_PMIC_PWR_IRQ_MASK_vin_ldo39_vld_mk_END (3)
#define SUB_PMIC_PWR_IRQ_MASK_vin_3p45_vld_mk_START (4)
#define SUB_PMIC_PWR_IRQ_MASK_vin_3p45_vld_mk_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char thsd_otmp125_mk : 1;
        unsigned char thsd_otmp140_mk : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_TEMP_THSD_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_TEMP_THSD_IRQ_MASK_thsd_otmp125_mk_START (0)
#define SUB_PMIC_TEMP_THSD_IRQ_MASK_thsd_otmp125_mk_END (0)
#define SUB_PMIC_TEMP_THSD_IRQ_MASK_thsd_otmp140_mk_START (1)
#define SUB_PMIC_TEMP_THSD_IRQ_MASK_thsd_otmp140_mk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_temp_alert_mk : 1;
        unsigned char buck1_temp_alert_mk : 1;
        unsigned char buck2_temp_alert_mk : 1;
        unsigned char buck3_temp_alert_mk : 1;
        unsigned char buck4_temp_alert_mk : 1;
        unsigned char buck5_temp_alert_mk : 1;
        unsigned char buck6_temp_alert_mk : 1;
        unsigned char buck7_temp_alert_mk : 1;
    } reg;
} SUB_PMIC_TEMP_ALERT_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck0_temp_alert_mk_START (0)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck0_temp_alert_mk_END (0)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck1_temp_alert_mk_START (1)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck1_temp_alert_mk_END (1)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck2_temp_alert_mk_START (2)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck2_temp_alert_mk_END (2)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck3_temp_alert_mk_START (3)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck3_temp_alert_mk_END (3)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck4_temp_alert_mk_START (4)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck4_temp_alert_mk_END (4)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck5_temp_alert_mk_START (5)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck5_temp_alert_mk_END (5)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck6_temp_alert_mk_START (6)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck6_temp_alert_mk_END (6)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck7_temp_alert_mk_START (7)
#define SUB_PMIC_TEMP_ALERT_IRQ_MASK_buck7_temp_alert_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_temp_damage_mk : 1;
        unsigned char buck1_temp_damage_mk : 1;
        unsigned char buck2_temp_damage_mk : 1;
        unsigned char buck3_temp_damage_mk : 1;
        unsigned char buck4_temp_damage_mk : 1;
        unsigned char buck5_temp_damage_mk : 1;
        unsigned char buck6_temp_damage_mk : 1;
        unsigned char buck7_temp_damage_mk : 1;
    } reg;
} SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck0_temp_damage_mk_START (0)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck0_temp_damage_mk_END (0)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck1_temp_damage_mk_START (1)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck1_temp_damage_mk_END (1)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck2_temp_damage_mk_START (2)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck2_temp_damage_mk_END (2)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck3_temp_damage_mk_START (3)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck3_temp_damage_mk_END (3)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck4_temp_damage_mk_START (4)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck4_temp_damage_mk_END (4)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck5_temp_damage_mk_START (5)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck5_temp_damage_mk_END (5)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck6_temp_damage_mk_START (6)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck6_temp_damage_mk_END (6)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck7_temp_damage_mk_START (7)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_MASK_buck7_temp_damage_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_ocp_mk : 1;
        unsigned char buck1_ocp_mk : 1;
        unsigned char buck2_ocp_mk : 1;
        unsigned char buck3_ocp_mk : 1;
        unsigned char buck4_ocp_mk : 1;
        unsigned char buck5_ocp_mk : 1;
        unsigned char buck6_ocp_mk : 1;
        unsigned char buck7_ocp_mk : 1;
    } reg;
} SUB_PMIC_OCP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_OCP_IRQ_MASK_buck0_ocp_mk_START (0)
#define SUB_PMIC_OCP_IRQ_MASK_buck0_ocp_mk_END (0)
#define SUB_PMIC_OCP_IRQ_MASK_buck1_ocp_mk_START (1)
#define SUB_PMIC_OCP_IRQ_MASK_buck1_ocp_mk_END (1)
#define SUB_PMIC_OCP_IRQ_MASK_buck2_ocp_mk_START (2)
#define SUB_PMIC_OCP_IRQ_MASK_buck2_ocp_mk_END (2)
#define SUB_PMIC_OCP_IRQ_MASK_buck3_ocp_mk_START (3)
#define SUB_PMIC_OCP_IRQ_MASK_buck3_ocp_mk_END (3)
#define SUB_PMIC_OCP_IRQ_MASK_buck4_ocp_mk_START (4)
#define SUB_PMIC_OCP_IRQ_MASK_buck4_ocp_mk_END (4)
#define SUB_PMIC_OCP_IRQ_MASK_buck5_ocp_mk_START (5)
#define SUB_PMIC_OCP_IRQ_MASK_buck5_ocp_mk_END (5)
#define SUB_PMIC_OCP_IRQ_MASK_buck6_ocp_mk_START (6)
#define SUB_PMIC_OCP_IRQ_MASK_buck6_ocp_mk_END (6)
#define SUB_PMIC_OCP_IRQ_MASK_buck7_ocp_mk_START (7)
#define SUB_PMIC_OCP_IRQ_MASK_buck7_ocp_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_ocp_mk : 1;
        unsigned char pmuh_ocp_mk : 1;
        unsigned char pmuh_short_n_mk : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_OCP_IRQ_MASK_2_UNION;
#endif
#define SUB_PMIC_OCP_IRQ_MASK_2_ldo39_ocp_mk_START (0)
#define SUB_PMIC_OCP_IRQ_MASK_2_ldo39_ocp_mk_END (0)
#define SUB_PMIC_OCP_IRQ_MASK_2_pmuh_ocp_mk_START (1)
#define SUB_PMIC_OCP_IRQ_MASK_2_pmuh_ocp_mk_END (1)
#define SUB_PMIC_OCP_IRQ_MASK_2_pmuh_short_n_mk_START (2)
#define SUB_PMIC_OCP_IRQ_MASK_2_pmuh_short_n_mk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_scp_mk : 1;
        unsigned char buck2_scp_mk : 1;
        unsigned char buck3_scp_mk : 1;
        unsigned char buck4_scp_mk : 1;
        unsigned char buck6_scp_mk : 1;
        unsigned char buck7_scp_mk : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_SCP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_SCP_IRQ_MASK_buck0_scp_mk_START (0)
#define SUB_PMIC_SCP_IRQ_MASK_buck0_scp_mk_END (0)
#define SUB_PMIC_SCP_IRQ_MASK_buck2_scp_mk_START (1)
#define SUB_PMIC_SCP_IRQ_MASK_buck2_scp_mk_END (1)
#define SUB_PMIC_SCP_IRQ_MASK_buck3_scp_mk_START (2)
#define SUB_PMIC_SCP_IRQ_MASK_buck3_scp_mk_END (2)
#define SUB_PMIC_SCP_IRQ_MASK_buck4_scp_mk_START (3)
#define SUB_PMIC_SCP_IRQ_MASK_buck4_scp_mk_END (3)
#define SUB_PMIC_SCP_IRQ_MASK_buck6_scp_mk_START (4)
#define SUB_PMIC_SCP_IRQ_MASK_buck6_scp_mk_END (4)
#define SUB_PMIC_SCP_IRQ_MASK_buck7_scp_mk_START (5)
#define SUB_PMIC_SCP_IRQ_MASK_buck7_scp_mk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_ovp_mk : 1;
        unsigned char buck2_ovp_mk : 1;
        unsigned char buck3_ovp_mk : 1;
        unsigned char buck4_ovp_mk : 1;
        unsigned char buck6_ovp_mk : 1;
        unsigned char buck7_ovp_mk : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OVP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_OVP_IRQ_MASK_buck0_ovp_mk_START (0)
#define SUB_PMIC_OVP_IRQ_MASK_buck0_ovp_mk_END (0)
#define SUB_PMIC_OVP_IRQ_MASK_buck2_ovp_mk_START (1)
#define SUB_PMIC_OVP_IRQ_MASK_buck2_ovp_mk_END (1)
#define SUB_PMIC_OVP_IRQ_MASK_buck3_ovp_mk_START (2)
#define SUB_PMIC_OVP_IRQ_MASK_buck3_ovp_mk_END (2)
#define SUB_PMIC_OVP_IRQ_MASK_buck4_ovp_mk_START (3)
#define SUB_PMIC_OVP_IRQ_MASK_buck4_ovp_mk_END (3)
#define SUB_PMIC_OVP_IRQ_MASK_buck6_ovp_mk_START (4)
#define SUB_PMIC_OVP_IRQ_MASK_buck6_ovp_mk_END (4)
#define SUB_PMIC_OVP_IRQ_MASK_buck7_ovp_mk_START (5)
#define SUB_PMIC_OVP_IRQ_MASK_buck7_ovp_mk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_oc_fer_mk : 1;
        unsigned char buck2_oc_fer_mk : 1;
        unsigned char buck3_oc_fer_mk : 1;
        unsigned char buck4_oc_fer_mk : 1;
        unsigned char buck6_oc_fer_mk : 1;
        unsigned char buck7_oc_fer_mk : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_OC_FER_IRQ_MASK_buck0_oc_fer_mk_START (0)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck0_oc_fer_mk_END (0)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck2_oc_fer_mk_START (1)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck2_oc_fer_mk_END (1)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck3_oc_fer_mk_START (2)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck3_oc_fer_mk_END (2)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck4_oc_fer_mk_START (3)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck4_oc_fer_mk_END (3)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck6_oc_fer_mk_START (4)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck6_oc_fer_mk_END (4)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck7_oc_fer_mk_START (5)
#define SUB_PMIC_OC_FER_IRQ_MASK_buck7_oc_fer_mk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_ramp_abn_mk : 1;
        unsigned char irq_buck2_ramp_abn_mk : 1;
        unsigned char irq_buck3_ramp_abn_mk : 1;
        unsigned char irq_buck4_ramp_abn_mk : 1;
        unsigned char irq_buck6_ramp_abn_mk : 1;
        unsigned char irq_buck7_ramp_abn_mk : 1;
        unsigned char irq_ldo39_ramp_abn_mk : 1;
        unsigned char irq_linkage_ramp_abn_mk : 1;
    } reg;
} SUB_PMIC_RAMP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck0_ramp_abn_mk_START (0)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck0_ramp_abn_mk_END (0)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck2_ramp_abn_mk_START (1)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck2_ramp_abn_mk_END (1)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck3_ramp_abn_mk_START (2)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck3_ramp_abn_mk_END (2)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck4_ramp_abn_mk_START (3)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck4_ramp_abn_mk_END (3)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck6_ramp_abn_mk_START (4)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck6_ramp_abn_mk_END (4)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck7_ramp_abn_mk_START (5)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_buck7_ramp_abn_mk_END (5)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_ldo39_ramp_abn_mk_START (6)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_ldo39_ramp_abn_mk_END (6)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_linkage_ramp_abn_mk_START (7)
#define SUB_PMIC_RAMP_IRQ_MASK_irq_linkage_ramp_abn_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_0_ro : 1;
        unsigned char irq_1_ro : 1;
        unsigned char irq_2_ro : 1;
        unsigned char irq_3_ro : 1;
        unsigned char irq_4_ro : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_IRQ1_UNION;
#endif
#define SUB_PMIC_IRQ1_irq_0_ro_START (0)
#define SUB_PMIC_IRQ1_irq_0_ro_END (0)
#define SUB_PMIC_IRQ1_irq_1_ro_START (1)
#define SUB_PMIC_IRQ1_irq_1_ro_END (1)
#define SUB_PMIC_IRQ1_irq_2_ro_START (2)
#define SUB_PMIC_IRQ1_irq_2_ro_END (2)
#define SUB_PMIC_IRQ1_irq_3_ro_START (3)
#define SUB_PMIC_IRQ1_irq_3_ro_END (3)
#define SUB_PMIC_IRQ1_irq_4_ro_START (4)
#define SUB_PMIC_IRQ1_irq_4_ro_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_vsys_ov : 1;
        unsigned char irq_vsys_pwron : 1;
        unsigned char irq_vsys_pwroff_abs : 1;
        unsigned char irq_vin_ldo39_vld : 1;
        unsigned char irq_vin_3p45_vld : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_PWR_IRQ_UNION;
#endif
#define SUB_PMIC_PWR_IRQ_irq_vsys_ov_START (0)
#define SUB_PMIC_PWR_IRQ_irq_vsys_ov_END (0)
#define SUB_PMIC_PWR_IRQ_irq_vsys_pwron_START (1)
#define SUB_PMIC_PWR_IRQ_irq_vsys_pwron_END (1)
#define SUB_PMIC_PWR_IRQ_irq_vsys_pwroff_abs_START (2)
#define SUB_PMIC_PWR_IRQ_irq_vsys_pwroff_abs_END (2)
#define SUB_PMIC_PWR_IRQ_irq_vin_ldo39_vld_START (3)
#define SUB_PMIC_PWR_IRQ_irq_vin_ldo39_vld_END (3)
#define SUB_PMIC_PWR_IRQ_irq_vin_3p45_vld_START (4)
#define SUB_PMIC_PWR_IRQ_irq_vin_3p45_vld_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_thsd_otmp125 : 1;
        unsigned char irq_thsd_otmp140 : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_TEMP_THSD_IRQ_UNION;
#endif
#define SUB_PMIC_TEMP_THSD_IRQ_irq_thsd_otmp125_START (0)
#define SUB_PMIC_TEMP_THSD_IRQ_irq_thsd_otmp125_END (0)
#define SUB_PMIC_TEMP_THSD_IRQ_irq_thsd_otmp140_START (1)
#define SUB_PMIC_TEMP_THSD_IRQ_irq_thsd_otmp140_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_temp_alert : 1;
        unsigned char irq_buck1_temp_alert : 1;
        unsigned char irq_buck2_temp_alert : 1;
        unsigned char irq_buck3_temp_alert : 1;
        unsigned char irq_buck4_temp_alert : 1;
        unsigned char irq_buck5_temp_alert : 1;
        unsigned char irq_buck6_temp_alert : 1;
        unsigned char irq_buck7_temp_alert : 1;
    } reg;
} SUB_PMIC_TEMP_ALERT_IRQ_UNION;
#endif
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck0_temp_alert_START (0)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck0_temp_alert_END (0)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck1_temp_alert_START (1)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck1_temp_alert_END (1)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck2_temp_alert_START (2)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck2_temp_alert_END (2)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck3_temp_alert_START (3)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck3_temp_alert_END (3)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck4_temp_alert_START (4)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck4_temp_alert_END (4)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck5_temp_alert_START (5)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck5_temp_alert_END (5)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck6_temp_alert_START (6)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck6_temp_alert_END (6)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck7_temp_alert_START (7)
#define SUB_PMIC_TEMP_ALERT_IRQ_irq_buck7_temp_alert_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_temp_damage : 1;
        unsigned char irq_buck1_temp_damage : 1;
        unsigned char irq_buck2_temp_damage : 1;
        unsigned char irq_buck3_temp_damage : 1;
        unsigned char irq_buck4_temp_damage : 1;
        unsigned char irq_buck5_temp_damage : 1;
        unsigned char irq_buck6_temp_damage : 1;
        unsigned char irq_buck7_temp_damage : 1;
    } reg;
} SUB_PMIC_TEMP_DAMAGE_IRQ_UNION;
#endif
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck0_temp_damage_START (0)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck0_temp_damage_END (0)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck1_temp_damage_START (1)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck1_temp_damage_END (1)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck2_temp_damage_START (2)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck2_temp_damage_END (2)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck3_temp_damage_START (3)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck3_temp_damage_END (3)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck4_temp_damage_START (4)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck4_temp_damage_END (4)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck5_temp_damage_START (5)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck5_temp_damage_END (5)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck6_temp_damage_START (6)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck6_temp_damage_END (6)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck7_temp_damage_START (7)
#define SUB_PMIC_TEMP_DAMAGE_IRQ_irq_buck7_temp_damage_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_ocp : 1;
        unsigned char irq_buck1_ocp : 1;
        unsigned char irq_buck2_ocp : 1;
        unsigned char irq_buck3_ocp : 1;
        unsigned char irq_buck4_ocp : 1;
        unsigned char irq_buck5_ocp : 1;
        unsigned char irq_buck6_ocp : 1;
        unsigned char irq_buck7_ocp : 1;
    } reg;
} SUB_PMIC_OCP_IRQ_UNION;
#endif
#define SUB_PMIC_OCP_IRQ_irq_buck0_ocp_START (0)
#define SUB_PMIC_OCP_IRQ_irq_buck0_ocp_END (0)
#define SUB_PMIC_OCP_IRQ_irq_buck1_ocp_START (1)
#define SUB_PMIC_OCP_IRQ_irq_buck1_ocp_END (1)
#define SUB_PMIC_OCP_IRQ_irq_buck2_ocp_START (2)
#define SUB_PMIC_OCP_IRQ_irq_buck2_ocp_END (2)
#define SUB_PMIC_OCP_IRQ_irq_buck3_ocp_START (3)
#define SUB_PMIC_OCP_IRQ_irq_buck3_ocp_END (3)
#define SUB_PMIC_OCP_IRQ_irq_buck4_ocp_START (4)
#define SUB_PMIC_OCP_IRQ_irq_buck4_ocp_END (4)
#define SUB_PMIC_OCP_IRQ_irq_buck5_ocp_START (5)
#define SUB_PMIC_OCP_IRQ_irq_buck5_ocp_END (5)
#define SUB_PMIC_OCP_IRQ_irq_buck6_ocp_START (6)
#define SUB_PMIC_OCP_IRQ_irq_buck6_ocp_END (6)
#define SUB_PMIC_OCP_IRQ_irq_buck7_ocp_START (7)
#define SUB_PMIC_OCP_IRQ_irq_buck7_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ldo39_ocp : 1;
        unsigned char irq_pmuh_ocp : 1;
        unsigned char irq_pmuh_short_n : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_OCP_IRQ_2_UNION;
#endif
#define SUB_PMIC_OCP_IRQ_2_irq_ldo39_ocp_START (0)
#define SUB_PMIC_OCP_IRQ_2_irq_ldo39_ocp_END (0)
#define SUB_PMIC_OCP_IRQ_2_irq_pmuh_ocp_START (1)
#define SUB_PMIC_OCP_IRQ_2_irq_pmuh_ocp_END (1)
#define SUB_PMIC_OCP_IRQ_2_irq_pmuh_short_n_START (2)
#define SUB_PMIC_OCP_IRQ_2_irq_pmuh_short_n_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_scp : 1;
        unsigned char irq_buck2_scp : 1;
        unsigned char irq_buck3_scp : 1;
        unsigned char irq_buck4_scp : 1;
        unsigned char irq_buck6_scp : 1;
        unsigned char irq_buck7_scp : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_SCP_IRQ_UNION;
#endif
#define SUB_PMIC_SCP_IRQ_irq_buck0_scp_START (0)
#define SUB_PMIC_SCP_IRQ_irq_buck0_scp_END (0)
#define SUB_PMIC_SCP_IRQ_irq_buck2_scp_START (1)
#define SUB_PMIC_SCP_IRQ_irq_buck2_scp_END (1)
#define SUB_PMIC_SCP_IRQ_irq_buck3_scp_START (2)
#define SUB_PMIC_SCP_IRQ_irq_buck3_scp_END (2)
#define SUB_PMIC_SCP_IRQ_irq_buck4_scp_START (3)
#define SUB_PMIC_SCP_IRQ_irq_buck4_scp_END (3)
#define SUB_PMIC_SCP_IRQ_irq_buck6_scp_START (4)
#define SUB_PMIC_SCP_IRQ_irq_buck6_scp_END (4)
#define SUB_PMIC_SCP_IRQ_irq_buck7_scp_START (5)
#define SUB_PMIC_SCP_IRQ_irq_buck7_scp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_ovp : 1;
        unsigned char irq_buck2_ovp : 1;
        unsigned char irq_buck3_ovp : 1;
        unsigned char irq_buck4_ovp : 1;
        unsigned char irq_buck6_ovp : 1;
        unsigned char irq_buck7_ovp : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OVP_IRQ_UNION;
#endif
#define SUB_PMIC_OVP_IRQ_irq_buck0_ovp_START (0)
#define SUB_PMIC_OVP_IRQ_irq_buck0_ovp_END (0)
#define SUB_PMIC_OVP_IRQ_irq_buck2_ovp_START (1)
#define SUB_PMIC_OVP_IRQ_irq_buck2_ovp_END (1)
#define SUB_PMIC_OVP_IRQ_irq_buck3_ovp_START (2)
#define SUB_PMIC_OVP_IRQ_irq_buck3_ovp_END (2)
#define SUB_PMIC_OVP_IRQ_irq_buck4_ovp_START (3)
#define SUB_PMIC_OVP_IRQ_irq_buck4_ovp_END (3)
#define SUB_PMIC_OVP_IRQ_irq_buck6_ovp_START (4)
#define SUB_PMIC_OVP_IRQ_irq_buck6_ovp_END (4)
#define SUB_PMIC_OVP_IRQ_irq_buck7_ovp_START (5)
#define SUB_PMIC_OVP_IRQ_irq_buck7_ovp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_oc_fer : 1;
        unsigned char irq_buck2_oc_fer : 1;
        unsigned char irq_buck3_oc_fer : 1;
        unsigned char irq_buck4_oc_fer : 1;
        unsigned char irq_buck6_oc_fer : 1;
        unsigned char irq_buck7_oc_fer : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_IRQ_UNION;
#endif
#define SUB_PMIC_OC_FER_IRQ_irq_buck0_oc_fer_START (0)
#define SUB_PMIC_OC_FER_IRQ_irq_buck0_oc_fer_END (0)
#define SUB_PMIC_OC_FER_IRQ_irq_buck2_oc_fer_START (1)
#define SUB_PMIC_OC_FER_IRQ_irq_buck2_oc_fer_END (1)
#define SUB_PMIC_OC_FER_IRQ_irq_buck3_oc_fer_START (2)
#define SUB_PMIC_OC_FER_IRQ_irq_buck3_oc_fer_END (2)
#define SUB_PMIC_OC_FER_IRQ_irq_buck4_oc_fer_START (3)
#define SUB_PMIC_OC_FER_IRQ_irq_buck4_oc_fer_END (3)
#define SUB_PMIC_OC_FER_IRQ_irq_buck6_oc_fer_START (4)
#define SUB_PMIC_OC_FER_IRQ_irq_buck6_oc_fer_END (4)
#define SUB_PMIC_OC_FER_IRQ_irq_buck7_oc_fer_START (5)
#define SUB_PMIC_OC_FER_IRQ_irq_buck7_oc_fer_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_buck0_ramp_abn : 1;
        unsigned char irq_buck2_ramp_abn : 1;
        unsigned char irq_buck3_ramp_abn : 1;
        unsigned char irq_buck4_ramp_abn : 1;
        unsigned char irq_buck6_ramp_abn : 1;
        unsigned char irq_buck7_ramp_abn : 1;
        unsigned char irq_ldo39_ramp_abn : 1;
        unsigned char irq_linkage_ramp_abn : 1;
    } reg;
} SUB_PMIC_RAMP_IRQ_UNION;
#endif
#define SUB_PMIC_RAMP_IRQ_irq_buck0_ramp_abn_START (0)
#define SUB_PMIC_RAMP_IRQ_irq_buck0_ramp_abn_END (0)
#define SUB_PMIC_RAMP_IRQ_irq_buck2_ramp_abn_START (1)
#define SUB_PMIC_RAMP_IRQ_irq_buck2_ramp_abn_END (1)
#define SUB_PMIC_RAMP_IRQ_irq_buck3_ramp_abn_START (2)
#define SUB_PMIC_RAMP_IRQ_irq_buck3_ramp_abn_END (2)
#define SUB_PMIC_RAMP_IRQ_irq_buck4_ramp_abn_START (3)
#define SUB_PMIC_RAMP_IRQ_irq_buck4_ramp_abn_END (3)
#define SUB_PMIC_RAMP_IRQ_irq_buck6_ramp_abn_START (4)
#define SUB_PMIC_RAMP_IRQ_irq_buck6_ramp_abn_END (4)
#define SUB_PMIC_RAMP_IRQ_irq_buck7_ramp_abn_START (5)
#define SUB_PMIC_RAMP_IRQ_irq_buck7_ramp_abn_END (5)
#define SUB_PMIC_RAMP_IRQ_irq_ldo39_ramp_abn_START (6)
#define SUB_PMIC_RAMP_IRQ_irq_ldo39_ramp_abn_END (6)
#define SUB_PMIC_RAMP_IRQ_irq_linkage_ramp_abn_START (7)
#define SUB_PMIC_RAMP_IRQ_irq_linkage_ramp_abn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vsys_ov : 1;
        unsigned char np_vsys_pwron : 1;
        unsigned char np_vsys_pwroff_abs : 1;
        unsigned char np_vin_ldo39_vld : 1;
        unsigned char np_vin_3p45_vld : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_PWR_EVENT_UNION;
#endif
#define SUB_PMIC_PWR_EVENT_np_vsys_ov_START (0)
#define SUB_PMIC_PWR_EVENT_np_vsys_ov_END (0)
#define SUB_PMIC_PWR_EVENT_np_vsys_pwron_START (1)
#define SUB_PMIC_PWR_EVENT_np_vsys_pwron_END (1)
#define SUB_PMIC_PWR_EVENT_np_vsys_pwroff_abs_START (2)
#define SUB_PMIC_PWR_EVENT_np_vsys_pwroff_abs_END (2)
#define SUB_PMIC_PWR_EVENT_np_vin_ldo39_vld_START (3)
#define SUB_PMIC_PWR_EVENT_np_vin_ldo39_vld_END (3)
#define SUB_PMIC_PWR_EVENT_np_vin_3p45_vld_START (4)
#define SUB_PMIC_PWR_EVENT_np_vin_3p45_vld_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_thsd_otmp125 : 1;
        unsigned char np_thsd_otmp140 : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_TEMP_THSD_EVENT_UNION;
#endif
#define SUB_PMIC_TEMP_THSD_EVENT_np_thsd_otmp125_START (0)
#define SUB_PMIC_TEMP_THSD_EVENT_np_thsd_otmp125_END (0)
#define SUB_PMIC_TEMP_THSD_EVENT_np_thsd_otmp140_START (1)
#define SUB_PMIC_TEMP_THSD_EVENT_np_thsd_otmp140_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_temp_alert : 1;
        unsigned char np_buck1_temp_alert : 1;
        unsigned char np_buck2_temp_alert : 1;
        unsigned char np_buck3_temp_alert : 1;
        unsigned char np_buck4_temp_alert : 1;
        unsigned char np_buck5_temp_alert : 1;
        unsigned char np_buck6_temp_alert : 1;
        unsigned char np_buck7_temp_alert : 1;
    } reg;
} SUB_PMIC_TEMP_ALERT_EVENT_UNION;
#endif
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck0_temp_alert_START (0)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck0_temp_alert_END (0)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck1_temp_alert_START (1)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck1_temp_alert_END (1)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck2_temp_alert_START (2)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck2_temp_alert_END (2)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck3_temp_alert_START (3)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck3_temp_alert_END (3)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck4_temp_alert_START (4)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck4_temp_alert_END (4)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck5_temp_alert_START (5)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck5_temp_alert_END (5)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck6_temp_alert_START (6)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck6_temp_alert_END (6)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck7_temp_alert_START (7)
#define SUB_PMIC_TEMP_ALERT_EVENT_np_buck7_temp_alert_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_temp_damage : 1;
        unsigned char np_buck1_temp_damage : 1;
        unsigned char np_buck2_temp_damage : 1;
        unsigned char np_buck3_temp_damage : 1;
        unsigned char np_buck4_temp_damage : 1;
        unsigned char np_buck5_temp_damage : 1;
        unsigned char np_buck6_temp_damage : 1;
        unsigned char np_buck7_temp_damage : 1;
    } reg;
} SUB_PMIC_TEMP_DAMAGE_EVENT_UNION;
#endif
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck0_temp_damage_START (0)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck0_temp_damage_END (0)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck1_temp_damage_START (1)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck1_temp_damage_END (1)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck2_temp_damage_START (2)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck2_temp_damage_END (2)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck3_temp_damage_START (3)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck3_temp_damage_END (3)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck4_temp_damage_START (4)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck4_temp_damage_END (4)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck5_temp_damage_START (5)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck5_temp_damage_END (5)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck6_temp_damage_START (6)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck6_temp_damage_END (6)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck7_temp_damage_START (7)
#define SUB_PMIC_TEMP_DAMAGE_EVENT_np_buck7_temp_damage_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_ocp : 1;
        unsigned char np_buck1_ocp : 1;
        unsigned char np_buck2_ocp : 1;
        unsigned char np_buck3_ocp : 1;
        unsigned char np_buck4_ocp : 1;
        unsigned char np_buck5_ocp : 1;
        unsigned char np_buck6_ocp : 1;
        unsigned char np_buck7_ocp : 1;
    } reg;
} SUB_PMIC_OCP_EVENT_UNION;
#endif
#define SUB_PMIC_OCP_EVENT_np_buck0_ocp_START (0)
#define SUB_PMIC_OCP_EVENT_np_buck0_ocp_END (0)
#define SUB_PMIC_OCP_EVENT_np_buck1_ocp_START (1)
#define SUB_PMIC_OCP_EVENT_np_buck1_ocp_END (1)
#define SUB_PMIC_OCP_EVENT_np_buck2_ocp_START (2)
#define SUB_PMIC_OCP_EVENT_np_buck2_ocp_END (2)
#define SUB_PMIC_OCP_EVENT_np_buck3_ocp_START (3)
#define SUB_PMIC_OCP_EVENT_np_buck3_ocp_END (3)
#define SUB_PMIC_OCP_EVENT_np_buck4_ocp_START (4)
#define SUB_PMIC_OCP_EVENT_np_buck4_ocp_END (4)
#define SUB_PMIC_OCP_EVENT_np_buck5_ocp_START (5)
#define SUB_PMIC_OCP_EVENT_np_buck5_ocp_END (5)
#define SUB_PMIC_OCP_EVENT_np_buck6_ocp_START (6)
#define SUB_PMIC_OCP_EVENT_np_buck6_ocp_END (6)
#define SUB_PMIC_OCP_EVENT_np_buck7_ocp_START (7)
#define SUB_PMIC_OCP_EVENT_np_buck7_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo39_ocp : 1;
        unsigned char np_pmuh_ocp : 1;
        unsigned char np_pmuh_short_n : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_OCP_EVENT_2_UNION;
#endif
#define SUB_PMIC_OCP_EVENT_2_np_ldo39_ocp_START (0)
#define SUB_PMIC_OCP_EVENT_2_np_ldo39_ocp_END (0)
#define SUB_PMIC_OCP_EVENT_2_np_pmuh_ocp_START (1)
#define SUB_PMIC_OCP_EVENT_2_np_pmuh_ocp_END (1)
#define SUB_PMIC_OCP_EVENT_2_np_pmuh_short_n_START (2)
#define SUB_PMIC_OCP_EVENT_2_np_pmuh_short_n_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_scp : 1;
        unsigned char np_buck2_scp : 1;
        unsigned char np_buck3_scp : 1;
        unsigned char np_buck4_scp : 1;
        unsigned char np_buck6_scp : 1;
        unsigned char np_buck7_scp : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_SCP_EVENT_UNION;
#endif
#define SUB_PMIC_SCP_EVENT_np_buck0_scp_START (0)
#define SUB_PMIC_SCP_EVENT_np_buck0_scp_END (0)
#define SUB_PMIC_SCP_EVENT_np_buck2_scp_START (1)
#define SUB_PMIC_SCP_EVENT_np_buck2_scp_END (1)
#define SUB_PMIC_SCP_EVENT_np_buck3_scp_START (2)
#define SUB_PMIC_SCP_EVENT_np_buck3_scp_END (2)
#define SUB_PMIC_SCP_EVENT_np_buck4_scp_START (3)
#define SUB_PMIC_SCP_EVENT_np_buck4_scp_END (3)
#define SUB_PMIC_SCP_EVENT_np_buck6_scp_START (4)
#define SUB_PMIC_SCP_EVENT_np_buck6_scp_END (4)
#define SUB_PMIC_SCP_EVENT_np_buck7_scp_START (5)
#define SUB_PMIC_SCP_EVENT_np_buck7_scp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_ovp : 1;
        unsigned char np_buck2_ovp : 1;
        unsigned char np_buck3_ovp : 1;
        unsigned char np_buck4_ovp : 1;
        unsigned char np_buck6_ovp : 1;
        unsigned char np_buck7_ovp : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OVP_EVENT_UNION;
#endif
#define SUB_PMIC_OVP_EVENT_np_buck0_ovp_START (0)
#define SUB_PMIC_OVP_EVENT_np_buck0_ovp_END (0)
#define SUB_PMIC_OVP_EVENT_np_buck2_ovp_START (1)
#define SUB_PMIC_OVP_EVENT_np_buck2_ovp_END (1)
#define SUB_PMIC_OVP_EVENT_np_buck3_ovp_START (2)
#define SUB_PMIC_OVP_EVENT_np_buck3_ovp_END (2)
#define SUB_PMIC_OVP_EVENT_np_buck4_ovp_START (3)
#define SUB_PMIC_OVP_EVENT_np_buck4_ovp_END (3)
#define SUB_PMIC_OVP_EVENT_np_buck6_ovp_START (4)
#define SUB_PMIC_OVP_EVENT_np_buck6_ovp_END (4)
#define SUB_PMIC_OVP_EVENT_np_buck7_ovp_START (5)
#define SUB_PMIC_OVP_EVENT_np_buck7_ovp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_oc_fer : 1;
        unsigned char np_buck2_oc_fer : 1;
        unsigned char np_buck3_oc_fer : 1;
        unsigned char np_buck4_oc_fer : 1;
        unsigned char np_buck6_oc_fer : 1;
        unsigned char np_buck7_oc_fer : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OC_FER_EVENT_UNION;
#endif
#define SUB_PMIC_OC_FER_EVENT_np_buck0_oc_fer_START (0)
#define SUB_PMIC_OC_FER_EVENT_np_buck0_oc_fer_END (0)
#define SUB_PMIC_OC_FER_EVENT_np_buck2_oc_fer_START (1)
#define SUB_PMIC_OC_FER_EVENT_np_buck2_oc_fer_END (1)
#define SUB_PMIC_OC_FER_EVENT_np_buck3_oc_fer_START (2)
#define SUB_PMIC_OC_FER_EVENT_np_buck3_oc_fer_END (2)
#define SUB_PMIC_OC_FER_EVENT_np_buck4_oc_fer_START (3)
#define SUB_PMIC_OC_FER_EVENT_np_buck4_oc_fer_END (3)
#define SUB_PMIC_OC_FER_EVENT_np_buck6_oc_fer_START (4)
#define SUB_PMIC_OC_FER_EVENT_np_buck6_oc_fer_END (4)
#define SUB_PMIC_OC_FER_EVENT_np_buck7_oc_fer_START (5)
#define SUB_PMIC_OC_FER_EVENT_np_buck7_oc_fer_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_ramp_abn : 1;
        unsigned char np_buck2_ramp_abn : 1;
        unsigned char np_buck3_ramp_abn : 1;
        unsigned char np_buck4_ramp_abn : 1;
        unsigned char np_buck6_ramp_abn : 1;
        unsigned char np_buck7_ramp_abn : 1;
        unsigned char np_ldo39_ramp_abn : 1;
        unsigned char np_linkage_ramp_abn : 1;
    } reg;
} SUB_PMIC_RAMP_EVENT_UNION;
#endif
#define SUB_PMIC_RAMP_EVENT_np_buck0_ramp_abn_START (0)
#define SUB_PMIC_RAMP_EVENT_np_buck0_ramp_abn_END (0)
#define SUB_PMIC_RAMP_EVENT_np_buck2_ramp_abn_START (1)
#define SUB_PMIC_RAMP_EVENT_np_buck2_ramp_abn_END (1)
#define SUB_PMIC_RAMP_EVENT_np_buck3_ramp_abn_START (2)
#define SUB_PMIC_RAMP_EVENT_np_buck3_ramp_abn_END (2)
#define SUB_PMIC_RAMP_EVENT_np_buck4_ramp_abn_START (3)
#define SUB_PMIC_RAMP_EVENT_np_buck4_ramp_abn_END (3)
#define SUB_PMIC_RAMP_EVENT_np_buck6_ramp_abn_START (4)
#define SUB_PMIC_RAMP_EVENT_np_buck6_ramp_abn_END (4)
#define SUB_PMIC_RAMP_EVENT_np_buck7_ramp_abn_START (5)
#define SUB_PMIC_RAMP_EVENT_np_buck7_ramp_abn_END (5)
#define SUB_PMIC_RAMP_EVENT_np_ldo39_ramp_abn_START (6)
#define SUB_PMIC_RAMP_EVENT_np_ldo39_ramp_abn_END (6)
#define SUB_PMIC_RAMP_EVENT_np_linkage_ramp_abn_START (7)
#define SUB_PMIC_RAMP_EVENT_np_linkage_ramp_abn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_ramp_eco : 1;
        unsigned char np_buck2_ramp_eco : 1;
        unsigned char np_buck3_ramp_eco : 1;
        unsigned char np_buck4_ramp_eco : 1;
        unsigned char np_buck6_ramp_eco : 1;
        unsigned char np_buck7_ramp_eco : 1;
        unsigned char np_ldo39_ramp_eco : 1;
        unsigned char reserved : 1;
    } reg;
} SUB_PMIC_RAMP_ECO_EVENT_UNION;
#endif
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck0_ramp_eco_START (0)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck0_ramp_eco_END (0)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck2_ramp_eco_START (1)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck2_ramp_eco_END (1)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck3_ramp_eco_START (2)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck3_ramp_eco_END (2)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck4_ramp_eco_START (3)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck4_ramp_eco_END (3)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck6_ramp_eco_START (4)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck6_ramp_eco_END (4)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck7_ramp_eco_START (5)
#define SUB_PMIC_RAMP_ECO_EVENT_np_buck7_ramp_eco_END (5)
#define SUB_PMIC_RAMP_ECO_EVENT_np_ldo39_ramp_eco_START (6)
#define SUB_PMIC_RAMP_ECO_EVENT_np_ldo39_ramp_eco_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_oc_level_0b : 1;
        unsigned char np_buck0_oc_level_1b : 1;
        unsigned char np_buck2_oc_level_0b : 1;
        unsigned char np_buck2_oc_level_1b : 1;
        unsigned char np_buck3_oc_level_0b : 1;
        unsigned char np_buck3_oc_level_1b : 1;
        unsigned char np_buck4_oc_level_0b : 1;
        unsigned char np_buck4_oc_level_1b : 1;
    } reg;
} SUB_PMIC_OC_LEVEL_EVENT_0_UNION;
#endif
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck0_oc_level_0b_START (0)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck0_oc_level_0b_END (0)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck0_oc_level_1b_START (1)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck0_oc_level_1b_END (1)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck2_oc_level_0b_START (2)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck2_oc_level_0b_END (2)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck2_oc_level_1b_START (3)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck2_oc_level_1b_END (3)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck3_oc_level_0b_START (4)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck3_oc_level_0b_END (4)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck3_oc_level_1b_START (5)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck3_oc_level_1b_END (5)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck4_oc_level_0b_START (6)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck4_oc_level_0b_END (6)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck4_oc_level_1b_START (7)
#define SUB_PMIC_OC_LEVEL_EVENT_0_np_buck4_oc_level_1b_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck6_oc_level_0b : 1;
        unsigned char np_buck6_oc_level_1b : 1;
        unsigned char np_buck7_oc_level_0b : 1;
        unsigned char np_buck7_oc_level_1b : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_OC_LEVEL_EVENT_1_UNION;
#endif
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck6_oc_level_0b_START (0)
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck6_oc_level_0b_END (0)
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck6_oc_level_1b_START (1)
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck6_oc_level_1b_END (1)
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck7_oc_level_0b_START (2)
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck7_oc_level_0b_END (2)
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck7_oc_level_1b_START (3)
#define SUB_PMIC_OC_LEVEL_EVENT_1_np_buck7_oc_level_1b_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_lock : 8;
    } reg;
} SUB_PMIC_EFUSE_LOCK_UNION;
#endif
#define SUB_PMIC_EFUSE_LOCK_efuse_lock_START (0)
#define SUB_PMIC_EFUSE_LOCK_efuse_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_clk_ctrl : 8;
    } reg;
} SUB_PMIC_EFUSE_CLK_CTRL_UNION;
#endif
#define SUB_PMIC_EFUSE_CLK_CTRL_efuse_clk_ctrl_START (0)
#define SUB_PMIC_EFUSE_CLK_CTRL_efuse_clk_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_loop_rd_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE_LOOP_RD_CTRL_UNION;
#endif
#define SUB_PMIC_EFUSE_LOOP_RD_CTRL_sc_efuse_loop_rd_ctrl_START (0)
#define SUB_PMIC_EFUSE_LOOP_RD_CTRL_sc_efuse_loop_rd_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_wr_pulse : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE_WR_PULSE_CTRL_UNION;
#endif
#define SUB_PMIC_EFUSE_WR_PULSE_CTRL_efuse_wr_pulse_START (0)
#define SUB_PMIC_EFUSE_WR_PULSE_CTRL_efuse_wr_pulse_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_data : 8;
    } reg;
} SUB_PMIC_EFUSE0_D_UNION;
#endif
#define SUB_PMIC_EFUSE0_D_efuse0_data_START (0)
#define SUB_PMIC_EFUSE0_D_efuse0_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_aen_mode_sel : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE0_AEN_MODE_UNION;
#endif
#define SUB_PMIC_EFUSE0_AEN_MODE_efuse0_aen_mode_sel_START (0)
#define SUB_PMIC_EFUSE0_AEN_MODE_efuse0_aen_mode_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_prog_sel : 1;
        unsigned char efuse0_inctrl_sel : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_EFUSE0_MODE_CTRL_UNION;
#endif
#define SUB_PMIC_EFUSE0_MODE_CTRL_efuse0_prog_sel_START (0)
#define SUB_PMIC_EFUSE0_MODE_CTRL_efuse0_prog_sel_END (0)
#define SUB_PMIC_EFUSE0_MODE_CTRL_efuse0_inctrl_sel_START (1)
#define SUB_PMIC_EFUSE0_MODE_CTRL_efuse0_inctrl_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_rden_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE0_RDEN_CFG_UNION;
#endif
#define SUB_PMIC_EFUSE0_RDEN_CFG_efuse0_rden_cfg_START (0)
#define SUB_PMIC_EFUSE0_RDEN_CFG_efuse0_rden_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pgmen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE0_PGMEN_CFG_UNION;
#endif
#define SUB_PMIC_EFUSE0_PGMEN_CFG_efuse0_pgmen_cfg_START (0)
#define SUB_PMIC_EFUSE0_PGMEN_CFG_efuse0_pgmen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_aen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE0_AEN_CFG_UNION;
#endif
#define SUB_PMIC_EFUSE0_AEN_CFG_efuse0_aen_cfg_START (0)
#define SUB_PMIC_EFUSE0_AEN_CFG_efuse0_aen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_addr_l_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE0_ADDR_L_UNION;
#endif
#define SUB_PMIC_EFUSE0_ADDR_L_efuse0_addr_l_cfg_START (0)
#define SUB_PMIC_EFUSE0_ADDR_L_efuse0_addr_l_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_addr_h_cfg : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_EFUSE0_ADDR_H_UNION;
#endif
#define SUB_PMIC_EFUSE0_ADDR_H_efuse0_addr_h_cfg_START (0)
#define SUB_PMIC_EFUSE0_ADDR_H_efuse0_addr_h_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_testbus_en : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE0_TESTBUS_EN_UNION;
#endif
#define SUB_PMIC_EFUSE0_TESTBUS_EN_efuse0_testbus_en_START (0)
#define SUB_PMIC_EFUSE0_TESTBUS_EN_efuse0_testbus_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_testbus_sel : 8;
    } reg;
} SUB_PMIC_EFUSE0_TESTBUS_SEL_UNION;
#endif
#define SUB_PMIC_EFUSE0_TESTBUS_SEL_efuse0_testbus_sel_START (0)
#define SUB_PMIC_EFUSE0_TESTBUS_SEL_efuse0_testbus_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_testbus_data : 8;
    } reg;
} SUB_PMIC_EFUSE0_TESTBUS_DATA_UNION;
#endif
#define SUB_PMIC_EFUSE0_TESTBUS_DATA_efuse0_testbus_data_START (0)
#define SUB_PMIC_EFUSE0_TESTBUS_DATA_efuse0_testbus_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse0_trim_pre_addr : 7;
        unsigned char sc_efuse0_trim_pre_we : 1;
    } reg;
} SUB_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_UNION;
#endif
#define SUB_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_addr_START (0)
#define SUB_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_addr_END (6)
#define SUB_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_we_START (7)
#define SUB_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_we_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse0_trim_pre_wdata : 8;
    } reg;
} SUB_PMIC_EFUSE0_PDOB_PRE_WDATA_UNION;
#endif
#define SUB_PMIC_EFUSE0_PDOB_PRE_WDATA_sc_efuse0_trim_pre_wdata_START (0)
#define SUB_PMIC_EFUSE0_PDOB_PRE_WDATA_sc_efuse0_trim_pre_wdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_pdob_sel : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE_PDOB_SEL_UNION;
#endif
#define SUB_PMIC_EFUSE_PDOB_SEL_sc_efuse_pdob_sel_START (0)
#define SUB_PMIC_EFUSE_PDOB_SEL_sc_efuse_pdob_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse0_state_reset : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_EFUSE0_FSM_RESET_UNION;
#endif
#define SUB_PMIC_EFUSE0_FSM_RESET_sc_efuse0_state_reset_START (0)
#define SUB_PMIC_EFUSE0_FSM_RESET_sc_efuse0_state_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_efuse_aen_lock : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_SYS_CTRL_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_CFG_REG_0_d2a_efuse_aen_lock_START (0)
#define SUB_PMIC_SYS_CTRL_CFG_REG_0_d2a_efuse_aen_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob0_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_0_efuse_d2a_pdob0_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_0_efuse_d2a_pdob0_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob1_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_1_efuse_d2a_pdob1_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_1_efuse_d2a_pdob1_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob2_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_2_efuse_d2a_pdob2_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_2_efuse_d2a_pdob2_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob3_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_3_efuse_d2a_pdob3_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_3_efuse_d2a_pdob3_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob4_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_4_efuse_d2a_pdob4_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_4_efuse_d2a_pdob4_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob5_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_5_efuse_d2a_pdob5_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_5_efuse_d2a_pdob5_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob6_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_6_efuse_d2a_pdob6_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_6_efuse_d2a_pdob6_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob7_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_7_efuse_d2a_pdob7_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_7_efuse_d2a_pdob7_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob9_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_9_efuse_d2a_pdob9_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_9_efuse_d2a_pdob9_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob10_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_10_efuse_d2a_pdob10_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_10_efuse_d2a_pdob10_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob11_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_11_efuse_d2a_pdob11_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_11_efuse_d2a_pdob11_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob12_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_12_efuse_d2a_pdob12_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_12_efuse_d2a_pdob12_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob13_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_13_efuse_d2a_pdob13_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_13_efuse_d2a_pdob13_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob14_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_14_efuse_d2a_pdob14_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_14_efuse_d2a_pdob14_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob15_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_15_efuse_d2a_pdob15_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_15_efuse_d2a_pdob15_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob16_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_16_efuse_d2a_pdob16_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_16_efuse_d2a_pdob16_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob17_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_17_efuse_d2a_pdob17_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_17_efuse_d2a_pdob17_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob18_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_18_efuse_d2a_pdob18_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_18_efuse_d2a_pdob18_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob19_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_19_efuse_d2a_pdob19_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_19_efuse_d2a_pdob19_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob20_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_20_efuse_d2a_pdob20_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_20_efuse_d2a_pdob20_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob21_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_21_efuse_d2a_pdob21_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_21_efuse_d2a_pdob21_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob22_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_22_efuse_d2a_pdob22_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_22_efuse_d2a_pdob22_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob23_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_23_efuse_d2a_pdob23_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_23_efuse_d2a_pdob23_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob24_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_24_efuse_d2a_pdob24_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_24_efuse_d2a_pdob24_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob25_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_25_efuse_d2a_pdob25_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_25_efuse_d2a_pdob25_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob26_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_26_efuse_d2a_pdob26_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_26_efuse_d2a_pdob26_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob27_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_27_efuse_d2a_pdob27_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_27_efuse_d2a_pdob27_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob28_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_28_efuse_d2a_pdob28_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_28_efuse_d2a_pdob28_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob29_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_29_efuse_d2a_pdob29_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_29_efuse_d2a_pdob29_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob30_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_30_efuse_d2a_pdob30_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_30_efuse_d2a_pdob30_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob31_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_31_efuse_d2a_pdob31_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_31_efuse_d2a_pdob31_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob32_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_32_efuse_d2a_pdob32_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_32_efuse_d2a_pdob32_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob33_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_33_efuse_d2a_pdob33_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_33_efuse_d2a_pdob33_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob34_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_34_efuse_d2a_pdob34_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_34_efuse_d2a_pdob34_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob35_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_35_efuse_d2a_pdob35_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_35_efuse_d2a_pdob35_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob36_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_36_efuse_d2a_pdob36_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_36_efuse_d2a_pdob36_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob37_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_37_efuse_d2a_pdob37_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_37_efuse_d2a_pdob37_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob38_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_38_efuse_d2a_pdob38_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_38_efuse_d2a_pdob38_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob39_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_39_efuse_d2a_pdob39_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_39_efuse_d2a_pdob39_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob40_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_40_efuse_d2a_pdob40_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_40_efuse_d2a_pdob40_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob41_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_41_efuse_d2a_pdob41_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_41_efuse_d2a_pdob41_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob42_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_42_efuse_d2a_pdob42_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_42_efuse_d2a_pdob42_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob43_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_43_efuse_d2a_pdob43_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_43_efuse_d2a_pdob43_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob44_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_44_efuse_d2a_pdob44_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_44_efuse_d2a_pdob44_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob45_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_45_efuse_d2a_pdob45_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_45_efuse_d2a_pdob45_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob46_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_46_efuse_d2a_pdob46_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_46_efuse_d2a_pdob46_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob47_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_47_efuse_d2a_pdob47_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_47_efuse_d2a_pdob47_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob48_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_48_efuse_d2a_pdob48_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_48_efuse_d2a_pdob48_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob49_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_49_efuse_d2a_pdob49_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_49_efuse_d2a_pdob49_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob50_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_50_efuse_d2a_pdob50_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_50_efuse_d2a_pdob50_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob51_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_51_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_51_efuse_d2a_pdob51_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_51_efuse_d2a_pdob51_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob52_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_52_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_52_efuse_d2a_pdob52_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_52_efuse_d2a_pdob52_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob53_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_53_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_53_efuse_d2a_pdob53_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_53_efuse_d2a_pdob53_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob54_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_54_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_54_efuse_d2a_pdob54_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_54_efuse_d2a_pdob54_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob55_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_55_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_55_efuse_d2a_pdob55_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_55_efuse_d2a_pdob55_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob56_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_56_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_56_efuse_d2a_pdob56_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_56_efuse_d2a_pdob56_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob57_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_57_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_57_efuse_d2a_pdob57_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_57_efuse_d2a_pdob57_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob58_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_58_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_58_efuse_d2a_pdob58_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_58_efuse_d2a_pdob58_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob59_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_59_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_59_efuse_d2a_pdob59_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_59_efuse_d2a_pdob59_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob60_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_60_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_60_efuse_d2a_pdob60_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_60_efuse_d2a_pdob60_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob61_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_61_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_61_efuse_d2a_pdob61_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_61_efuse_d2a_pdob61_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob62_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_62_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_62_efuse_d2a_pdob62_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_62_efuse_d2a_pdob62_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob63_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_63_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_63_efuse_d2a_pdob63_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_63_efuse_d2a_pdob63_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob64_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_64_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_64_efuse_d2a_pdob64_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_64_efuse_d2a_pdob64_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob65_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_65_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_65_efuse_d2a_pdob65_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_65_efuse_d2a_pdob65_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob66_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_66_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_66_efuse_d2a_pdob66_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_66_efuse_d2a_pdob66_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob67_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_67_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_67_efuse_d2a_pdob67_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_67_efuse_d2a_pdob67_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob68_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_68_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_68_efuse_d2a_pdob68_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_68_efuse_d2a_pdob68_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob69_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_69_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_69_efuse_d2a_pdob69_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_69_efuse_d2a_pdob69_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob70_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_70_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_70_efuse_d2a_pdob70_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_70_efuse_d2a_pdob70_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob71_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_71_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_71_efuse_d2a_pdob71_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_71_efuse_d2a_pdob71_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob72_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_72_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_72_efuse_d2a_pdob72_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_72_efuse_d2a_pdob72_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob73_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_73_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_73_efuse_d2a_pdob73_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_73_efuse_d2a_pdob73_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob74_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_74_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_74_efuse_d2a_pdob74_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_74_efuse_d2a_pdob74_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob75_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_75_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_75_efuse_d2a_pdob75_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_75_efuse_d2a_pdob75_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob76_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_76_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_76_efuse_d2a_pdob76_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_76_efuse_d2a_pdob76_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob77_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_77_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_77_efuse_d2a_pdob77_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_77_efuse_d2a_pdob77_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob78_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_78_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_78_efuse_d2a_pdob78_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_78_efuse_d2a_pdob78_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob79_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_79_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_79_efuse_d2a_pdob79_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_79_efuse_d2a_pdob79_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob80_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_80_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_80_efuse_d2a_pdob80_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_80_efuse_d2a_pdob80_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob81_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_81_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_81_efuse_d2a_pdob81_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_81_efuse_d2a_pdob81_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob82_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_82_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_82_efuse_d2a_pdob82_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_82_efuse_d2a_pdob82_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob83_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_83_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_83_efuse_d2a_pdob83_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_83_efuse_d2a_pdob83_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob84_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_84_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_84_efuse_d2a_pdob84_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_84_efuse_d2a_pdob84_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob85_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_85_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_85_efuse_d2a_pdob85_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_85_efuse_d2a_pdob85_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob86_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_86_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_86_efuse_d2a_pdob86_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_86_efuse_d2a_pdob86_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob87_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_87_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_87_efuse_d2a_pdob87_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_87_efuse_d2a_pdob87_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob88_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_88_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_88_efuse_d2a_pdob88_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_88_efuse_d2a_pdob88_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob89_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_89_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_89_efuse_d2a_pdob89_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_89_efuse_d2a_pdob89_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob90_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_90_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_90_efuse_d2a_pdob90_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_90_efuse_d2a_pdob90_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob91_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_91_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_91_efuse_d2a_pdob91_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_91_efuse_d2a_pdob91_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob92_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_92_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_92_efuse_d2a_pdob92_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_92_efuse_d2a_pdob92_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob93_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_93_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_93_efuse_d2a_pdob93_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_93_efuse_d2a_pdob93_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob94_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_94_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_94_efuse_d2a_pdob94_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_94_efuse_d2a_pdob94_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob95_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_95_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_95_efuse_d2a_pdob95_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_95_efuse_d2a_pdob95_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob96_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_96_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_96_efuse_d2a_pdob96_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_96_efuse_d2a_pdob96_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob97_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_97_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_97_efuse_d2a_pdob97_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_97_efuse_d2a_pdob97_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob98_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_98_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_98_efuse_d2a_pdob98_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_98_efuse_d2a_pdob98_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob99_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_99_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_99_efuse_d2a_pdob99_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_99_efuse_d2a_pdob99_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob100_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_100_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_100_efuse_d2a_pdob100_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_100_efuse_d2a_pdob100_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob101_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_101_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_101_efuse_d2a_pdob101_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_101_efuse_d2a_pdob101_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob102_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_102_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_102_efuse_d2a_pdob102_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_102_efuse_d2a_pdob102_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob103_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_103_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_103_efuse_d2a_pdob103_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_103_efuse_d2a_pdob103_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob104_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_104_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_104_efuse_d2a_pdob104_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_104_efuse_d2a_pdob104_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob105_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_105_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_105_efuse_d2a_pdob105_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_105_efuse_d2a_pdob105_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob106_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_106_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_106_efuse_d2a_pdob106_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_106_efuse_d2a_pdob106_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob107_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_107_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_107_efuse_d2a_pdob107_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_107_efuse_d2a_pdob107_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob108_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_108_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_108_efuse_d2a_pdob108_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_108_efuse_d2a_pdob108_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_d2a_pdob109_cfg : 8;
    } reg;
} SUB_PMIC_EFUSE_CFG_REG_109_UNION;
#endif
#define SUB_PMIC_EFUSE_CFG_REG_109_efuse_d2a_pdob109_cfg_START (0)
#define SUB_PMIC_EFUSE_CFG_REG_109_efuse_d2a_pdob109_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmud_switch_set : 2;
        unsigned char np_pmud_vsys_ctrl : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_LDP_PMUD_CFG_REG_UNION;
#endif
#define SUB_PMIC_LDP_PMUD_CFG_REG_np_pmud_switch_set_START (0)
#define SUB_PMIC_LDP_PMUD_CFG_REG_np_pmud_switch_set_END (1)
#define SUB_PMIC_LDP_PMUD_CFG_REG_np_pmud_vsys_ctrl_START (2)
#define SUB_PMIC_LDP_PMUD_CFG_REG_np_pmud_vsys_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_buffer_sel : 6;
        unsigned char np_ref_eco_shield : 1;
        unsigned char np_ref_ibias_sel : 1;
    } reg;
} SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_np_ref_buffer_sel_START (0)
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_np_ref_buffer_sel_END (5)
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_np_ref_eco_shield_START (6)
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_np_ref_eco_shield_END (6)
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_np_ref_ibias_sel_START (7)
#define SUB_PMIC_NP_BANDGAP_THSD_CFG_REG_0_np_ref_ibias_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_thsd_tmp_set : 2;
        unsigned char np_ref_chop_sel : 1;
        unsigned char np_ref_chop_clk_sel : 2;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_BANDGAP_THSD_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_np_thsd_tmp_set_START (0)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_np_thsd_tmp_set_END (1)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_np_ref_chop_sel_START (2)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_np_ref_chop_sel_END (2)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_np_ref_chop_clk_sel_START (3)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_1_np_ref_chop_clk_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_reserve0 : 8;
    } reg;
} SUB_PMIC_BANDGAP_THSD_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_2_np_ref_reserve0_START (0)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_2_np_ref_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_reserve1 : 8;
    } reg;
} SUB_PMIC_BANDGAP_THSD_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_3_np_ref_reserve1_START (0)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_3_np_ref_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_rc_clk_en_n : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_NP_CLK256K_UNION;
#endif
#define SUB_PMIC_NP_CLK256K_np_rc_clk_en_n_START (0)
#define SUB_PMIC_NP_CLK256K_np_rc_clk_en_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vsys_ov_set : 1;
        unsigned char np_vsys_pwroff_abs_set : 3;
        unsigned char np_vsys_pwron_set : 3;
        unsigned char reserved : 1;
    } reg;
} SUB_PMIC_SYS_CTRL_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_np_vsys_ov_set_START (0)
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_np_vsys_ov_set_END (0)
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_np_vsys_pwroff_abs_set_START (1)
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_np_vsys_pwroff_abs_set_END (3)
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_np_vsys_pwron_set_START (4)
#define SUB_PMIC_SYS_CTRL_CFG_REG_2_np_vsys_pwron_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_sys_ctrl_reserve : 8;
    } reg;
} SUB_PMIC_SYS_CTRL_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_CFG_REG_3_np_sys_ctrl_reserve_START (0)
#define SUB_PMIC_SYS_CTRL_CFG_REG_3_np_sys_ctrl_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve0 : 8;
    } reg;
} SUB_PMIC_NP_D2A_RESERVED_0_UNION;
#endif
#define SUB_PMIC_NP_D2A_RESERVED_0_np_d2a_reserve0_START (0)
#define SUB_PMIC_NP_D2A_RESERVED_0_np_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve1 : 8;
    } reg;
} SUB_PMIC_NP_D2A_RESERVED_1_UNION;
#endif
#define SUB_PMIC_NP_D2A_RESERVED_1_np_d2a_reserve1_START (0)
#define SUB_PMIC_NP_D2A_RESERVED_1_np_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve2 : 8;
    } reg;
} SUB_PMIC_NP_D2A_RESERVED_2_UNION;
#endif
#define SUB_PMIC_NP_D2A_RESERVED_2_np_d2a_reserve2_START (0)
#define SUB_PMIC_NP_D2A_RESERVED_2_np_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmu1_en_deb_sel : 2;
        unsigned char np_otmp125_deb_sel : 2;
        unsigned char np_vin_ldo39_deb_sel : 2;
        unsigned char np_vin_3p45_deb_sel : 2;
    } reg;
} SUB_PMIC_NP_DEB_CTRL_UNION;
#endif
#define SUB_PMIC_NP_DEB_CTRL_np_pmu1_en_deb_sel_START (0)
#define SUB_PMIC_NP_DEB_CTRL_np_pmu1_en_deb_sel_END (1)
#define SUB_PMIC_NP_DEB_CTRL_np_otmp125_deb_sel_START (2)
#define SUB_PMIC_NP_DEB_CTRL_np_otmp125_deb_sel_END (3)
#define SUB_PMIC_NP_DEB_CTRL_np_vin_ldo39_deb_sel_START (4)
#define SUB_PMIC_NP_DEB_CTRL_np_vin_ldo39_deb_sel_END (5)
#define SUB_PMIC_NP_DEB_CTRL_np_vin_3p45_deb_sel_START (6)
#define SUB_PMIC_NP_DEB_CTRL_np_vin_3p45_deb_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char soft_rst_cfg : 8;
    } reg;
} SUB_PMIC_SOFT_RST_CTRL_UNION;
#endif
#define SUB_PMIC_SOFT_RST_CTRL_soft_rst_cfg_START (0)
#define SUB_PMIC_SOFT_RST_CTRL_soft_rst_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck_onoff_mode : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_NP_BUCK_ONOFF_UNION;
#endif
#define SUB_PMIC_NP_BUCK_ONOFF_np_buck_onoff_mode_START (0)
#define SUB_PMIC_NP_BUCK_ONOFF_np_buck_onoff_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vin_3p45_vld_off_mk : 1;
        unsigned char np_vin_ldo39_vld_off_mk : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_NP_PWROFF_MASK_UNION;
#endif
#define SUB_PMIC_NP_PWROFF_MASK_np_vin_3p45_vld_off_mk_START (0)
#define SUB_PMIC_NP_PWROFF_MASK_np_vin_3p45_vld_off_mk_END (0)
#define SUB_PMIC_NP_PWROFF_MASK_np_vin_ldo39_vld_off_mk_START (1)
#define SUB_PMIC_NP_PWROFF_MASK_np_vin_ldo39_vld_off_mk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_dig_debug_lock : 8;
    } reg;
} SUB_PMIC_DIG_DEBUG_0_UNION;
#endif
#define SUB_PMIC_DIG_DEBUG_0_np_dig_debug_lock_START (0)
#define SUB_PMIC_DIG_DEBUG_0_np_dig_debug_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_dig_debug_cfg : 8;
    } reg;
} SUB_PMIC_DIG_DEBUG_1_UNION;
#endif
#define SUB_PMIC_DIG_DEBUG_1_np_dig_debug_cfg_START (0)
#define SUB_PMIC_DIG_DEBUG_1_np_dig_debug_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_debug_lock : 8;
    } reg;
} SUB_PMIC_NP_DEBUG_LOCK_UNION;
#endif
#define SUB_PMIC_NP_DEBUG_LOCK_np_debug_lock_START (0)
#define SUB_PMIC_NP_DEBUG_LOCK_np_debug_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_data_sel : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_DIG_IO_DS_SEL_UNION;
#endif
#define SUB_PMIC_DIG_IO_DS_SEL_spmi_data_sel_START (0)
#define SUB_PMIC_DIG_IO_DS_SEL_spmi_data_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_data_ds_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_DIG_IO_DS_CFG_UNION;
#endif
#define SUB_PMIC_DIG_IO_DS_CFG_spmi_data_ds_sel_START (0)
#define SUB_PMIC_DIG_IO_DS_CFG_spmi_data_ds_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob0_r : 8;
    } reg;
} SUB_PMIC_EFUSE_0_R_UNION;
#endif
#define SUB_PMIC_EFUSE_0_R_efuse_pdob0_r_START (0)
#define SUB_PMIC_EFUSE_0_R_efuse_pdob0_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob1_r : 8;
    } reg;
} SUB_PMIC_EFUSE_1_R_UNION;
#endif
#define SUB_PMIC_EFUSE_1_R_efuse_pdob1_r_START (0)
#define SUB_PMIC_EFUSE_1_R_efuse_pdob1_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob2_r : 8;
    } reg;
} SUB_PMIC_EFUSE_2_R_UNION;
#endif
#define SUB_PMIC_EFUSE_2_R_efuse_pdob2_r_START (0)
#define SUB_PMIC_EFUSE_2_R_efuse_pdob2_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob3_r : 8;
    } reg;
} SUB_PMIC_EFUSE_3_R_UNION;
#endif
#define SUB_PMIC_EFUSE_3_R_efuse_pdob3_r_START (0)
#define SUB_PMIC_EFUSE_3_R_efuse_pdob3_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob4_r : 8;
    } reg;
} SUB_PMIC_EFUSE_4_R_UNION;
#endif
#define SUB_PMIC_EFUSE_4_R_efuse_pdob4_r_START (0)
#define SUB_PMIC_EFUSE_4_R_efuse_pdob4_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob5_r : 8;
    } reg;
} SUB_PMIC_EFUSE_5_R_UNION;
#endif
#define SUB_PMIC_EFUSE_5_R_efuse_pdob5_r_START (0)
#define SUB_PMIC_EFUSE_5_R_efuse_pdob5_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob6_r : 8;
    } reg;
} SUB_PMIC_EFUSE_6_R_UNION;
#endif
#define SUB_PMIC_EFUSE_6_R_efuse_pdob6_r_START (0)
#define SUB_PMIC_EFUSE_6_R_efuse_pdob6_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob7_r : 8;
    } reg;
} SUB_PMIC_EFUSE_7_R_UNION;
#endif
#define SUB_PMIC_EFUSE_7_R_efuse_pdob7_r_START (0)
#define SUB_PMIC_EFUSE_7_R_efuse_pdob7_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob8_r : 8;
    } reg;
} SUB_PMIC_EFUSE_8_R_UNION;
#endif
#define SUB_PMIC_EFUSE_8_R_efuse_pdob8_r_START (0)
#define SUB_PMIC_EFUSE_8_R_efuse_pdob8_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob9_r : 8;
    } reg;
} SUB_PMIC_EFUSE_9_R_UNION;
#endif
#define SUB_PMIC_EFUSE_9_R_efuse_pdob9_r_START (0)
#define SUB_PMIC_EFUSE_9_R_efuse_pdob9_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob10_r : 8;
    } reg;
} SUB_PMIC_EFUSE_10_R_UNION;
#endif
#define SUB_PMIC_EFUSE_10_R_efuse_pdob10_r_START (0)
#define SUB_PMIC_EFUSE_10_R_efuse_pdob10_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob11_r : 8;
    } reg;
} SUB_PMIC_EFUSE_11_R_UNION;
#endif
#define SUB_PMIC_EFUSE_11_R_efuse_pdob11_r_START (0)
#define SUB_PMIC_EFUSE_11_R_efuse_pdob11_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob12_r : 8;
    } reg;
} SUB_PMIC_EFUSE_12_R_UNION;
#endif
#define SUB_PMIC_EFUSE_12_R_efuse_pdob12_r_START (0)
#define SUB_PMIC_EFUSE_12_R_efuse_pdob12_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob13_r : 8;
    } reg;
} SUB_PMIC_EFUSE_13_R_UNION;
#endif
#define SUB_PMIC_EFUSE_13_R_efuse_pdob13_r_START (0)
#define SUB_PMIC_EFUSE_13_R_efuse_pdob13_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob14_r : 8;
    } reg;
} SUB_PMIC_EFUSE_14_R_UNION;
#endif
#define SUB_PMIC_EFUSE_14_R_efuse_pdob14_r_START (0)
#define SUB_PMIC_EFUSE_14_R_efuse_pdob14_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob15_r : 8;
    } reg;
} SUB_PMIC_EFUSE_15_R_UNION;
#endif
#define SUB_PMIC_EFUSE_15_R_efuse_pdob15_r_START (0)
#define SUB_PMIC_EFUSE_15_R_efuse_pdob15_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob16_r : 8;
    } reg;
} SUB_PMIC_EFUSE_16_R_UNION;
#endif
#define SUB_PMIC_EFUSE_16_R_efuse_pdob16_r_START (0)
#define SUB_PMIC_EFUSE_16_R_efuse_pdob16_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob17_r : 8;
    } reg;
} SUB_PMIC_EFUSE_17_R_UNION;
#endif
#define SUB_PMIC_EFUSE_17_R_efuse_pdob17_r_START (0)
#define SUB_PMIC_EFUSE_17_R_efuse_pdob17_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob18_r : 8;
    } reg;
} SUB_PMIC_EFUSE_18_R_UNION;
#endif
#define SUB_PMIC_EFUSE_18_R_efuse_pdob18_r_START (0)
#define SUB_PMIC_EFUSE_18_R_efuse_pdob18_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob19_r : 8;
    } reg;
} SUB_PMIC_EFUSE_19_R_UNION;
#endif
#define SUB_PMIC_EFUSE_19_R_efuse_pdob19_r_START (0)
#define SUB_PMIC_EFUSE_19_R_efuse_pdob19_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob20_r : 8;
    } reg;
} SUB_PMIC_EFUSE_20_R_UNION;
#endif
#define SUB_PMIC_EFUSE_20_R_efuse_pdob20_r_START (0)
#define SUB_PMIC_EFUSE_20_R_efuse_pdob20_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob21_r : 8;
    } reg;
} SUB_PMIC_EFUSE_21_R_UNION;
#endif
#define SUB_PMIC_EFUSE_21_R_efuse_pdob21_r_START (0)
#define SUB_PMIC_EFUSE_21_R_efuse_pdob21_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob22_r : 8;
    } reg;
} SUB_PMIC_EFUSE_22_R_UNION;
#endif
#define SUB_PMIC_EFUSE_22_R_efuse_pdob22_r_START (0)
#define SUB_PMIC_EFUSE_22_R_efuse_pdob22_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob23_r : 8;
    } reg;
} SUB_PMIC_EFUSE_23_R_UNION;
#endif
#define SUB_PMIC_EFUSE_23_R_efuse_pdob23_r_START (0)
#define SUB_PMIC_EFUSE_23_R_efuse_pdob23_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob24_r : 8;
    } reg;
} SUB_PMIC_EFUSE_24_R_UNION;
#endif
#define SUB_PMIC_EFUSE_24_R_efuse_pdob24_r_START (0)
#define SUB_PMIC_EFUSE_24_R_efuse_pdob24_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob25_r : 8;
    } reg;
} SUB_PMIC_EFUSE_25_R_UNION;
#endif
#define SUB_PMIC_EFUSE_25_R_efuse_pdob25_r_START (0)
#define SUB_PMIC_EFUSE_25_R_efuse_pdob25_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob26_r : 8;
    } reg;
} SUB_PMIC_EFUSE_26_R_UNION;
#endif
#define SUB_PMIC_EFUSE_26_R_efuse_pdob26_r_START (0)
#define SUB_PMIC_EFUSE_26_R_efuse_pdob26_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob27_r : 8;
    } reg;
} SUB_PMIC_EFUSE_27_R_UNION;
#endif
#define SUB_PMIC_EFUSE_27_R_efuse_pdob27_r_START (0)
#define SUB_PMIC_EFUSE_27_R_efuse_pdob27_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob28_r : 8;
    } reg;
} SUB_PMIC_EFUSE_28_R_UNION;
#endif
#define SUB_PMIC_EFUSE_28_R_efuse_pdob28_r_START (0)
#define SUB_PMIC_EFUSE_28_R_efuse_pdob28_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob29_r : 8;
    } reg;
} SUB_PMIC_EFUSE_29_R_UNION;
#endif
#define SUB_PMIC_EFUSE_29_R_efuse_pdob29_r_START (0)
#define SUB_PMIC_EFUSE_29_R_efuse_pdob29_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob30_r : 8;
    } reg;
} SUB_PMIC_EFUSE_30_R_UNION;
#endif
#define SUB_PMIC_EFUSE_30_R_efuse_pdob30_r_START (0)
#define SUB_PMIC_EFUSE_30_R_efuse_pdob30_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob31_r : 8;
    } reg;
} SUB_PMIC_EFUSE_31_R_UNION;
#endif
#define SUB_PMIC_EFUSE_31_R_efuse_pdob31_r_START (0)
#define SUB_PMIC_EFUSE_31_R_efuse_pdob31_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob32_r : 8;
    } reg;
} SUB_PMIC_EFUSE_32_R_UNION;
#endif
#define SUB_PMIC_EFUSE_32_R_efuse_pdob32_r_START (0)
#define SUB_PMIC_EFUSE_32_R_efuse_pdob32_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob33_r : 8;
    } reg;
} SUB_PMIC_EFUSE_33_R_UNION;
#endif
#define SUB_PMIC_EFUSE_33_R_efuse_pdob33_r_START (0)
#define SUB_PMIC_EFUSE_33_R_efuse_pdob33_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob34_r : 8;
    } reg;
} SUB_PMIC_EFUSE_34_R_UNION;
#endif
#define SUB_PMIC_EFUSE_34_R_efuse_pdob34_r_START (0)
#define SUB_PMIC_EFUSE_34_R_efuse_pdob34_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob35_r : 8;
    } reg;
} SUB_PMIC_EFUSE_35_R_UNION;
#endif
#define SUB_PMIC_EFUSE_35_R_efuse_pdob35_r_START (0)
#define SUB_PMIC_EFUSE_35_R_efuse_pdob35_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob36_r : 8;
    } reg;
} SUB_PMIC_EFUSE_36_R_UNION;
#endif
#define SUB_PMIC_EFUSE_36_R_efuse_pdob36_r_START (0)
#define SUB_PMIC_EFUSE_36_R_efuse_pdob36_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob37_r : 8;
    } reg;
} SUB_PMIC_EFUSE_37_R_UNION;
#endif
#define SUB_PMIC_EFUSE_37_R_efuse_pdob37_r_START (0)
#define SUB_PMIC_EFUSE_37_R_efuse_pdob37_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob38_r : 8;
    } reg;
} SUB_PMIC_EFUSE_38_R_UNION;
#endif
#define SUB_PMIC_EFUSE_38_R_efuse_pdob38_r_START (0)
#define SUB_PMIC_EFUSE_38_R_efuse_pdob38_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob39_r : 8;
    } reg;
} SUB_PMIC_EFUSE_39_R_UNION;
#endif
#define SUB_PMIC_EFUSE_39_R_efuse_pdob39_r_START (0)
#define SUB_PMIC_EFUSE_39_R_efuse_pdob39_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob40_r : 8;
    } reg;
} SUB_PMIC_EFUSE_40_R_UNION;
#endif
#define SUB_PMIC_EFUSE_40_R_efuse_pdob40_r_START (0)
#define SUB_PMIC_EFUSE_40_R_efuse_pdob40_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob41_r : 8;
    } reg;
} SUB_PMIC_EFUSE_41_R_UNION;
#endif
#define SUB_PMIC_EFUSE_41_R_efuse_pdob41_r_START (0)
#define SUB_PMIC_EFUSE_41_R_efuse_pdob41_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob42_r : 8;
    } reg;
} SUB_PMIC_EFUSE_42_R_UNION;
#endif
#define SUB_PMIC_EFUSE_42_R_efuse_pdob42_r_START (0)
#define SUB_PMIC_EFUSE_42_R_efuse_pdob42_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob43_r : 8;
    } reg;
} SUB_PMIC_EFUSE_43_R_UNION;
#endif
#define SUB_PMIC_EFUSE_43_R_efuse_pdob43_r_START (0)
#define SUB_PMIC_EFUSE_43_R_efuse_pdob43_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob44_r : 8;
    } reg;
} SUB_PMIC_EFUSE_44_R_UNION;
#endif
#define SUB_PMIC_EFUSE_44_R_efuse_pdob44_r_START (0)
#define SUB_PMIC_EFUSE_44_R_efuse_pdob44_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob45_r : 8;
    } reg;
} SUB_PMIC_EFUSE_45_R_UNION;
#endif
#define SUB_PMIC_EFUSE_45_R_efuse_pdob45_r_START (0)
#define SUB_PMIC_EFUSE_45_R_efuse_pdob45_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob46_r : 8;
    } reg;
} SUB_PMIC_EFUSE_46_R_UNION;
#endif
#define SUB_PMIC_EFUSE_46_R_efuse_pdob46_r_START (0)
#define SUB_PMIC_EFUSE_46_R_efuse_pdob46_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob47_r : 8;
    } reg;
} SUB_PMIC_EFUSE_47_R_UNION;
#endif
#define SUB_PMIC_EFUSE_47_R_efuse_pdob47_r_START (0)
#define SUB_PMIC_EFUSE_47_R_efuse_pdob47_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob48_r : 8;
    } reg;
} SUB_PMIC_EFUSE_48_R_UNION;
#endif
#define SUB_PMIC_EFUSE_48_R_efuse_pdob48_r_START (0)
#define SUB_PMIC_EFUSE_48_R_efuse_pdob48_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob49_r : 8;
    } reg;
} SUB_PMIC_EFUSE_49_R_UNION;
#endif
#define SUB_PMIC_EFUSE_49_R_efuse_pdob49_r_START (0)
#define SUB_PMIC_EFUSE_49_R_efuse_pdob49_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob50_r : 8;
    } reg;
} SUB_PMIC_EFUSE_50_R_UNION;
#endif
#define SUB_PMIC_EFUSE_50_R_efuse_pdob50_r_START (0)
#define SUB_PMIC_EFUSE_50_R_efuse_pdob50_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob51_r : 8;
    } reg;
} SUB_PMIC_EFUSE_51_R_UNION;
#endif
#define SUB_PMIC_EFUSE_51_R_efuse_pdob51_r_START (0)
#define SUB_PMIC_EFUSE_51_R_efuse_pdob51_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob52_r : 8;
    } reg;
} SUB_PMIC_EFUSE_52_R_UNION;
#endif
#define SUB_PMIC_EFUSE_52_R_efuse_pdob52_r_START (0)
#define SUB_PMIC_EFUSE_52_R_efuse_pdob52_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob53_r : 8;
    } reg;
} SUB_PMIC_EFUSE_53_R_UNION;
#endif
#define SUB_PMIC_EFUSE_53_R_efuse_pdob53_r_START (0)
#define SUB_PMIC_EFUSE_53_R_efuse_pdob53_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob54_r : 8;
    } reg;
} SUB_PMIC_EFUSE_54_R_UNION;
#endif
#define SUB_PMIC_EFUSE_54_R_efuse_pdob54_r_START (0)
#define SUB_PMIC_EFUSE_54_R_efuse_pdob54_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob55_r : 8;
    } reg;
} SUB_PMIC_EFUSE_55_R_UNION;
#endif
#define SUB_PMIC_EFUSE_55_R_efuse_pdob55_r_START (0)
#define SUB_PMIC_EFUSE_55_R_efuse_pdob55_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob56_r : 8;
    } reg;
} SUB_PMIC_EFUSE_56_R_UNION;
#endif
#define SUB_PMIC_EFUSE_56_R_efuse_pdob56_r_START (0)
#define SUB_PMIC_EFUSE_56_R_efuse_pdob56_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob57_r : 8;
    } reg;
} SUB_PMIC_EFUSE_57_R_UNION;
#endif
#define SUB_PMIC_EFUSE_57_R_efuse_pdob57_r_START (0)
#define SUB_PMIC_EFUSE_57_R_efuse_pdob57_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob58_r : 8;
    } reg;
} SUB_PMIC_EFUSE_58_R_UNION;
#endif
#define SUB_PMIC_EFUSE_58_R_efuse_pdob58_r_START (0)
#define SUB_PMIC_EFUSE_58_R_efuse_pdob58_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob59_r : 8;
    } reg;
} SUB_PMIC_EFUSE_59_R_UNION;
#endif
#define SUB_PMIC_EFUSE_59_R_efuse_pdob59_r_START (0)
#define SUB_PMIC_EFUSE_59_R_efuse_pdob59_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob60_r : 8;
    } reg;
} SUB_PMIC_EFUSE_60_R_UNION;
#endif
#define SUB_PMIC_EFUSE_60_R_efuse_pdob60_r_START (0)
#define SUB_PMIC_EFUSE_60_R_efuse_pdob60_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob61_r : 8;
    } reg;
} SUB_PMIC_EFUSE_61_R_UNION;
#endif
#define SUB_PMIC_EFUSE_61_R_efuse_pdob61_r_START (0)
#define SUB_PMIC_EFUSE_61_R_efuse_pdob61_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob62_r : 8;
    } reg;
} SUB_PMIC_EFUSE_62_R_UNION;
#endif
#define SUB_PMIC_EFUSE_62_R_efuse_pdob62_r_START (0)
#define SUB_PMIC_EFUSE_62_R_efuse_pdob62_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob63_r : 8;
    } reg;
} SUB_PMIC_EFUSE_63_R_UNION;
#endif
#define SUB_PMIC_EFUSE_63_R_efuse_pdob63_r_START (0)
#define SUB_PMIC_EFUSE_63_R_efuse_pdob63_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob64_r : 8;
    } reg;
} SUB_PMIC_EFUSE_64_R_UNION;
#endif
#define SUB_PMIC_EFUSE_64_R_efuse_pdob64_r_START (0)
#define SUB_PMIC_EFUSE_64_R_efuse_pdob64_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob65_r : 8;
    } reg;
} SUB_PMIC_EFUSE_65_R_UNION;
#endif
#define SUB_PMIC_EFUSE_65_R_efuse_pdob65_r_START (0)
#define SUB_PMIC_EFUSE_65_R_efuse_pdob65_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob66_r : 8;
    } reg;
} SUB_PMIC_EFUSE_66_R_UNION;
#endif
#define SUB_PMIC_EFUSE_66_R_efuse_pdob66_r_START (0)
#define SUB_PMIC_EFUSE_66_R_efuse_pdob66_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob67_r : 8;
    } reg;
} SUB_PMIC_EFUSE_67_R_UNION;
#endif
#define SUB_PMIC_EFUSE_67_R_efuse_pdob67_r_START (0)
#define SUB_PMIC_EFUSE_67_R_efuse_pdob67_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob68_r : 8;
    } reg;
} SUB_PMIC_EFUSE_68_R_UNION;
#endif
#define SUB_PMIC_EFUSE_68_R_efuse_pdob68_r_START (0)
#define SUB_PMIC_EFUSE_68_R_efuse_pdob68_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob69_r : 8;
    } reg;
} SUB_PMIC_EFUSE_69_R_UNION;
#endif
#define SUB_PMIC_EFUSE_69_R_efuse_pdob69_r_START (0)
#define SUB_PMIC_EFUSE_69_R_efuse_pdob69_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob70_r : 8;
    } reg;
} SUB_PMIC_EFUSE_70_R_UNION;
#endif
#define SUB_PMIC_EFUSE_70_R_efuse_pdob70_r_START (0)
#define SUB_PMIC_EFUSE_70_R_efuse_pdob70_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob71_r : 8;
    } reg;
} SUB_PMIC_EFUSE_71_R_UNION;
#endif
#define SUB_PMIC_EFUSE_71_R_efuse_pdob71_r_START (0)
#define SUB_PMIC_EFUSE_71_R_efuse_pdob71_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob72_r : 8;
    } reg;
} SUB_PMIC_EFUSE_72_R_UNION;
#endif
#define SUB_PMIC_EFUSE_72_R_efuse_pdob72_r_START (0)
#define SUB_PMIC_EFUSE_72_R_efuse_pdob72_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob73_r : 8;
    } reg;
} SUB_PMIC_EFUSE_73_R_UNION;
#endif
#define SUB_PMIC_EFUSE_73_R_efuse_pdob73_r_START (0)
#define SUB_PMIC_EFUSE_73_R_efuse_pdob73_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob74_r : 8;
    } reg;
} SUB_PMIC_EFUSE_74_R_UNION;
#endif
#define SUB_PMIC_EFUSE_74_R_efuse_pdob74_r_START (0)
#define SUB_PMIC_EFUSE_74_R_efuse_pdob74_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob75_r : 8;
    } reg;
} SUB_PMIC_EFUSE_75_R_UNION;
#endif
#define SUB_PMIC_EFUSE_75_R_efuse_pdob75_r_START (0)
#define SUB_PMIC_EFUSE_75_R_efuse_pdob75_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob76_r : 8;
    } reg;
} SUB_PMIC_EFUSE_76_R_UNION;
#endif
#define SUB_PMIC_EFUSE_76_R_efuse_pdob76_r_START (0)
#define SUB_PMIC_EFUSE_76_R_efuse_pdob76_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob77_r : 8;
    } reg;
} SUB_PMIC_EFUSE_77_R_UNION;
#endif
#define SUB_PMIC_EFUSE_77_R_efuse_pdob77_r_START (0)
#define SUB_PMIC_EFUSE_77_R_efuse_pdob77_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob78_r : 8;
    } reg;
} SUB_PMIC_EFUSE_78_R_UNION;
#endif
#define SUB_PMIC_EFUSE_78_R_efuse_pdob78_r_START (0)
#define SUB_PMIC_EFUSE_78_R_efuse_pdob78_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob79_r : 8;
    } reg;
} SUB_PMIC_EFUSE_79_R_UNION;
#endif
#define SUB_PMIC_EFUSE_79_R_efuse_pdob79_r_START (0)
#define SUB_PMIC_EFUSE_79_R_efuse_pdob79_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob80_r : 8;
    } reg;
} SUB_PMIC_EFUSE_80_R_UNION;
#endif
#define SUB_PMIC_EFUSE_80_R_efuse_pdob80_r_START (0)
#define SUB_PMIC_EFUSE_80_R_efuse_pdob80_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob81_r : 8;
    } reg;
} SUB_PMIC_EFUSE_81_R_UNION;
#endif
#define SUB_PMIC_EFUSE_81_R_efuse_pdob81_r_START (0)
#define SUB_PMIC_EFUSE_81_R_efuse_pdob81_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob82_r : 8;
    } reg;
} SUB_PMIC_EFUSE_82_R_UNION;
#endif
#define SUB_PMIC_EFUSE_82_R_efuse_pdob82_r_START (0)
#define SUB_PMIC_EFUSE_82_R_efuse_pdob82_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob83_r : 8;
    } reg;
} SUB_PMIC_EFUSE_83_R_UNION;
#endif
#define SUB_PMIC_EFUSE_83_R_efuse_pdob83_r_START (0)
#define SUB_PMIC_EFUSE_83_R_efuse_pdob83_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob84_r : 8;
    } reg;
} SUB_PMIC_EFUSE_84_R_UNION;
#endif
#define SUB_PMIC_EFUSE_84_R_efuse_pdob84_r_START (0)
#define SUB_PMIC_EFUSE_84_R_efuse_pdob84_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob85_r : 8;
    } reg;
} SUB_PMIC_EFUSE_85_R_UNION;
#endif
#define SUB_PMIC_EFUSE_85_R_efuse_pdob85_r_START (0)
#define SUB_PMIC_EFUSE_85_R_efuse_pdob85_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob86_r : 8;
    } reg;
} SUB_PMIC_EFUSE_86_R_UNION;
#endif
#define SUB_PMIC_EFUSE_86_R_efuse_pdob86_r_START (0)
#define SUB_PMIC_EFUSE_86_R_efuse_pdob86_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob87_r : 8;
    } reg;
} SUB_PMIC_EFUSE_87_R_UNION;
#endif
#define SUB_PMIC_EFUSE_87_R_efuse_pdob87_r_START (0)
#define SUB_PMIC_EFUSE_87_R_efuse_pdob87_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob88_r : 8;
    } reg;
} SUB_PMIC_EFUSE_88_R_UNION;
#endif
#define SUB_PMIC_EFUSE_88_R_efuse_pdob88_r_START (0)
#define SUB_PMIC_EFUSE_88_R_efuse_pdob88_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob89_r : 8;
    } reg;
} SUB_PMIC_EFUSE_89_R_UNION;
#endif
#define SUB_PMIC_EFUSE_89_R_efuse_pdob89_r_START (0)
#define SUB_PMIC_EFUSE_89_R_efuse_pdob89_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob90_r : 8;
    } reg;
} SUB_PMIC_EFUSE_90_R_UNION;
#endif
#define SUB_PMIC_EFUSE_90_R_efuse_pdob90_r_START (0)
#define SUB_PMIC_EFUSE_90_R_efuse_pdob90_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob91_r : 8;
    } reg;
} SUB_PMIC_EFUSE_91_R_UNION;
#endif
#define SUB_PMIC_EFUSE_91_R_efuse_pdob91_r_START (0)
#define SUB_PMIC_EFUSE_91_R_efuse_pdob91_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob92_r : 8;
    } reg;
} SUB_PMIC_EFUSE_92_R_UNION;
#endif
#define SUB_PMIC_EFUSE_92_R_efuse_pdob92_r_START (0)
#define SUB_PMIC_EFUSE_92_R_efuse_pdob92_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob93_r : 8;
    } reg;
} SUB_PMIC_EFUSE_93_R_UNION;
#endif
#define SUB_PMIC_EFUSE_93_R_efuse_pdob93_r_START (0)
#define SUB_PMIC_EFUSE_93_R_efuse_pdob93_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob94_r : 8;
    } reg;
} SUB_PMIC_EFUSE_94_R_UNION;
#endif
#define SUB_PMIC_EFUSE_94_R_efuse_pdob94_r_START (0)
#define SUB_PMIC_EFUSE_94_R_efuse_pdob94_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob95_r : 8;
    } reg;
} SUB_PMIC_EFUSE_95_R_UNION;
#endif
#define SUB_PMIC_EFUSE_95_R_efuse_pdob95_r_START (0)
#define SUB_PMIC_EFUSE_95_R_efuse_pdob95_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob96_r : 8;
    } reg;
} SUB_PMIC_EFUSE_96_R_UNION;
#endif
#define SUB_PMIC_EFUSE_96_R_efuse_pdob96_r_START (0)
#define SUB_PMIC_EFUSE_96_R_efuse_pdob96_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob97_r : 8;
    } reg;
} SUB_PMIC_EFUSE_97_R_UNION;
#endif
#define SUB_PMIC_EFUSE_97_R_efuse_pdob97_r_START (0)
#define SUB_PMIC_EFUSE_97_R_efuse_pdob97_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob98_r : 8;
    } reg;
} SUB_PMIC_EFUSE_98_R_UNION;
#endif
#define SUB_PMIC_EFUSE_98_R_efuse_pdob98_r_START (0)
#define SUB_PMIC_EFUSE_98_R_efuse_pdob98_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob99_r : 8;
    } reg;
} SUB_PMIC_EFUSE_99_R_UNION;
#endif
#define SUB_PMIC_EFUSE_99_R_efuse_pdob99_r_START (0)
#define SUB_PMIC_EFUSE_99_R_efuse_pdob99_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob100_r : 8;
    } reg;
} SUB_PMIC_EFUSE_100_R_UNION;
#endif
#define SUB_PMIC_EFUSE_100_R_efuse_pdob100_r_START (0)
#define SUB_PMIC_EFUSE_100_R_efuse_pdob100_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob101_r : 8;
    } reg;
} SUB_PMIC_EFUSE_101_R_UNION;
#endif
#define SUB_PMIC_EFUSE_101_R_efuse_pdob101_r_START (0)
#define SUB_PMIC_EFUSE_101_R_efuse_pdob101_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob102_r : 8;
    } reg;
} SUB_PMIC_EFUSE_102_R_UNION;
#endif
#define SUB_PMIC_EFUSE_102_R_efuse_pdob102_r_START (0)
#define SUB_PMIC_EFUSE_102_R_efuse_pdob102_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob103_r : 8;
    } reg;
} SUB_PMIC_EFUSE_103_R_UNION;
#endif
#define SUB_PMIC_EFUSE_103_R_efuse_pdob103_r_START (0)
#define SUB_PMIC_EFUSE_103_R_efuse_pdob103_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob104_r : 8;
    } reg;
} SUB_PMIC_EFUSE_104_R_UNION;
#endif
#define SUB_PMIC_EFUSE_104_R_efuse_pdob104_r_START (0)
#define SUB_PMIC_EFUSE_104_R_efuse_pdob104_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob105_r : 8;
    } reg;
} SUB_PMIC_EFUSE_105_R_UNION;
#endif
#define SUB_PMIC_EFUSE_105_R_efuse_pdob105_r_START (0)
#define SUB_PMIC_EFUSE_105_R_efuse_pdob105_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob106_r : 8;
    } reg;
} SUB_PMIC_EFUSE_106_R_UNION;
#endif
#define SUB_PMIC_EFUSE_106_R_efuse_pdob106_r_START (0)
#define SUB_PMIC_EFUSE_106_R_efuse_pdob106_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob107_r : 8;
    } reg;
} SUB_PMIC_EFUSE_107_R_UNION;
#endif
#define SUB_PMIC_EFUSE_107_R_efuse_pdob107_r_START (0)
#define SUB_PMIC_EFUSE_107_R_efuse_pdob107_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob108_r : 8;
    } reg;
} SUB_PMIC_EFUSE_108_R_UNION;
#endif
#define SUB_PMIC_EFUSE_108_R_efuse_pdob108_r_START (0)
#define SUB_PMIC_EFUSE_108_R_efuse_pdob108_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob109_r : 8;
    } reg;
} SUB_PMIC_EFUSE_109_R_UNION;
#endif
#define SUB_PMIC_EFUSE_109_R_efuse_pdob109_r_START (0)
#define SUB_PMIC_EFUSE_109_R_efuse_pdob109_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob110_r : 8;
    } reg;
} SUB_PMIC_EFUSE_110_R_UNION;
#endif
#define SUB_PMIC_EFUSE_110_R_efuse_pdob110_r_START (0)
#define SUB_PMIC_EFUSE_110_R_efuse_pdob110_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob111_r : 8;
    } reg;
} SUB_PMIC_EFUSE_111_R_UNION;
#endif
#define SUB_PMIC_EFUSE_111_R_efuse_pdob111_r_START (0)
#define SUB_PMIC_EFUSE_111_R_efuse_pdob111_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob112_r : 8;
    } reg;
} SUB_PMIC_EFUSE_112_R_UNION;
#endif
#define SUB_PMIC_EFUSE_112_R_efuse_pdob112_r_START (0)
#define SUB_PMIC_EFUSE_112_R_efuse_pdob112_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob113_r : 8;
    } reg;
} SUB_PMIC_EFUSE_113_R_UNION;
#endif
#define SUB_PMIC_EFUSE_113_R_efuse_pdob113_r_START (0)
#define SUB_PMIC_EFUSE_113_R_efuse_pdob113_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob114_r : 8;
    } reg;
} SUB_PMIC_EFUSE_114_R_UNION;
#endif
#define SUB_PMIC_EFUSE_114_R_efuse_pdob114_r_START (0)
#define SUB_PMIC_EFUSE_114_R_efuse_pdob114_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob115_r : 8;
    } reg;
} SUB_PMIC_EFUSE_115_R_UNION;
#endif
#define SUB_PMIC_EFUSE_115_R_efuse_pdob115_r_START (0)
#define SUB_PMIC_EFUSE_115_R_efuse_pdob115_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob116_r : 8;
    } reg;
} SUB_PMIC_EFUSE_116_R_UNION;
#endif
#define SUB_PMIC_EFUSE_116_R_efuse_pdob116_r_START (0)
#define SUB_PMIC_EFUSE_116_R_efuse_pdob116_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob117_r : 8;
    } reg;
} SUB_PMIC_EFUSE_117_R_UNION;
#endif
#define SUB_PMIC_EFUSE_117_R_efuse_pdob117_r_START (0)
#define SUB_PMIC_EFUSE_117_R_efuse_pdob117_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob118_r : 8;
    } reg;
} SUB_PMIC_EFUSE_118_R_UNION;
#endif
#define SUB_PMIC_EFUSE_118_R_efuse_pdob118_r_START (0)
#define SUB_PMIC_EFUSE_118_R_efuse_pdob118_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob119_r : 8;
    } reg;
} SUB_PMIC_EFUSE_119_R_UNION;
#endif
#define SUB_PMIC_EFUSE_119_R_efuse_pdob119_r_START (0)
#define SUB_PMIC_EFUSE_119_R_efuse_pdob119_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob120_r : 8;
    } reg;
} SUB_PMIC_EFUSE_120_R_UNION;
#endif
#define SUB_PMIC_EFUSE_120_R_efuse_pdob120_r_START (0)
#define SUB_PMIC_EFUSE_120_R_efuse_pdob120_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob121_r : 8;
    } reg;
} SUB_PMIC_EFUSE_121_R_UNION;
#endif
#define SUB_PMIC_EFUSE_121_R_efuse_pdob121_r_START (0)
#define SUB_PMIC_EFUSE_121_R_efuse_pdob121_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob122_r : 8;
    } reg;
} SUB_PMIC_EFUSE_122_R_UNION;
#endif
#define SUB_PMIC_EFUSE_122_R_efuse_pdob122_r_START (0)
#define SUB_PMIC_EFUSE_122_R_efuse_pdob122_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob123_r : 8;
    } reg;
} SUB_PMIC_EFUSE_123_R_UNION;
#endif
#define SUB_PMIC_EFUSE_123_R_efuse_pdob123_r_START (0)
#define SUB_PMIC_EFUSE_123_R_efuse_pdob123_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob124_r : 8;
    } reg;
} SUB_PMIC_EFUSE_124_R_UNION;
#endif
#define SUB_PMIC_EFUSE_124_R_efuse_pdob124_r_START (0)
#define SUB_PMIC_EFUSE_124_R_efuse_pdob124_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob125_r : 8;
    } reg;
} SUB_PMIC_EFUSE_125_R_UNION;
#endif
#define SUB_PMIC_EFUSE_125_R_efuse_pdob125_r_START (0)
#define SUB_PMIC_EFUSE_125_R_efuse_pdob125_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob126_r : 8;
    } reg;
} SUB_PMIC_EFUSE_126_R_UNION;
#endif
#define SUB_PMIC_EFUSE_126_R_efuse_pdob126_r_START (0)
#define SUB_PMIC_EFUSE_126_R_efuse_pdob126_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_vset_cfg : 8;
    } reg;
} SUB_PMIC_BUCK0_VSET_CFG_UNION;
#endif
#define SUB_PMIC_BUCK0_VSET_CFG_buck0_vset_cfg_START (0)
#define SUB_PMIC_BUCK0_VSET_CFG_buck0_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck0_en : 1;
        unsigned char st_buck0_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck0_eco_en : 1;
        unsigned char st_buck0_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_BUCK0_EN_CFG_UNION;
#endif
#define SUB_PMIC_BUCK0_EN_CFG_reg_buck0_en_START (0)
#define SUB_PMIC_BUCK0_EN_CFG_reg_buck0_en_END (0)
#define SUB_PMIC_BUCK0_EN_CFG_st_buck0_en_START (1)
#define SUB_PMIC_BUCK0_EN_CFG_st_buck0_en_END (1)
#define SUB_PMIC_BUCK0_EN_CFG_reg_buck0_eco_en_START (4)
#define SUB_PMIC_BUCK0_EN_CFG_reg_buck0_eco_en_END (4)
#define SUB_PMIC_BUCK0_EN_CFG_st_buck0_eco_en_START (5)
#define SUB_PMIC_BUCK0_EN_CFG_st_buck0_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_vset_cfg : 8;
    } reg;
} SUB_PMIC_BUCK2_VSET_CFG_UNION;
#endif
#define SUB_PMIC_BUCK2_VSET_CFG_buck2_vset_cfg_START (0)
#define SUB_PMIC_BUCK2_VSET_CFG_buck2_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck2_en : 1;
        unsigned char st_buck2_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck2_eco_en : 1;
        unsigned char st_buck2_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_BUCK2_EN_CFG_UNION;
#endif
#define SUB_PMIC_BUCK2_EN_CFG_reg_buck2_en_START (0)
#define SUB_PMIC_BUCK2_EN_CFG_reg_buck2_en_END (0)
#define SUB_PMIC_BUCK2_EN_CFG_st_buck2_en_START (1)
#define SUB_PMIC_BUCK2_EN_CFG_st_buck2_en_END (1)
#define SUB_PMIC_BUCK2_EN_CFG_reg_buck2_eco_en_START (4)
#define SUB_PMIC_BUCK2_EN_CFG_reg_buck2_eco_en_END (4)
#define SUB_PMIC_BUCK2_EN_CFG_st_buck2_eco_en_START (5)
#define SUB_PMIC_BUCK2_EN_CFG_st_buck2_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_vset_cfg : 8;
    } reg;
} SUB_PMIC_BUCK3_VSET_CFG_UNION;
#endif
#define SUB_PMIC_BUCK3_VSET_CFG_buck3_vset_cfg_START (0)
#define SUB_PMIC_BUCK3_VSET_CFG_buck3_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck3_en : 1;
        unsigned char st_buck3_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck3_eco_en : 1;
        unsigned char st_buck3_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_BUCK3_EN_CFG_UNION;
#endif
#define SUB_PMIC_BUCK3_EN_CFG_reg_buck3_en_START (0)
#define SUB_PMIC_BUCK3_EN_CFG_reg_buck3_en_END (0)
#define SUB_PMIC_BUCK3_EN_CFG_st_buck3_en_START (1)
#define SUB_PMIC_BUCK3_EN_CFG_st_buck3_en_END (1)
#define SUB_PMIC_BUCK3_EN_CFG_reg_buck3_eco_en_START (4)
#define SUB_PMIC_BUCK3_EN_CFG_reg_buck3_eco_en_END (4)
#define SUB_PMIC_BUCK3_EN_CFG_st_buck3_eco_en_START (5)
#define SUB_PMIC_BUCK3_EN_CFG_st_buck3_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_vset_cfg : 8;
    } reg;
} SUB_PMIC_BUCK4_VSET_CFG_UNION;
#endif
#define SUB_PMIC_BUCK4_VSET_CFG_buck4_vset_cfg_START (0)
#define SUB_PMIC_BUCK4_VSET_CFG_buck4_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck4_en : 1;
        unsigned char st_buck4_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck4_eco_en : 1;
        unsigned char st_buck4_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_BUCK4_EN_CFG_UNION;
#endif
#define SUB_PMIC_BUCK4_EN_CFG_reg_buck4_en_START (0)
#define SUB_PMIC_BUCK4_EN_CFG_reg_buck4_en_END (0)
#define SUB_PMIC_BUCK4_EN_CFG_st_buck4_en_START (1)
#define SUB_PMIC_BUCK4_EN_CFG_st_buck4_en_END (1)
#define SUB_PMIC_BUCK4_EN_CFG_reg_buck4_eco_en_START (4)
#define SUB_PMIC_BUCK4_EN_CFG_reg_buck4_eco_en_END (4)
#define SUB_PMIC_BUCK4_EN_CFG_st_buck4_eco_en_START (5)
#define SUB_PMIC_BUCK4_EN_CFG_st_buck4_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_vset_cfg : 8;
    } reg;
} SUB_PMIC_BUCK6_VSET_CFG_UNION;
#endif
#define SUB_PMIC_BUCK6_VSET_CFG_buck6_vset_cfg_START (0)
#define SUB_PMIC_BUCK6_VSET_CFG_buck6_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck6_en : 1;
        unsigned char st_buck6_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck6_eco_en : 1;
        unsigned char st_buck6_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_BUCK6_EN_CFG_UNION;
#endif
#define SUB_PMIC_BUCK6_EN_CFG_reg_buck6_en_START (0)
#define SUB_PMIC_BUCK6_EN_CFG_reg_buck6_en_END (0)
#define SUB_PMIC_BUCK6_EN_CFG_st_buck6_en_START (1)
#define SUB_PMIC_BUCK6_EN_CFG_st_buck6_en_END (1)
#define SUB_PMIC_BUCK6_EN_CFG_reg_buck6_eco_en_START (4)
#define SUB_PMIC_BUCK6_EN_CFG_reg_buck6_eco_en_END (4)
#define SUB_PMIC_BUCK6_EN_CFG_st_buck6_eco_en_START (5)
#define SUB_PMIC_BUCK6_EN_CFG_st_buck6_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_vset_cfg : 8;
    } reg;
} SUB_PMIC_BUCK7_VSET_CFG_UNION;
#endif
#define SUB_PMIC_BUCK7_VSET_CFG_buck7_vset_cfg_START (0)
#define SUB_PMIC_BUCK7_VSET_CFG_buck7_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_buck7_en : 1;
        unsigned char st_buck7_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck7_eco_en : 1;
        unsigned char st_buck7_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_BUCK7_EN_CFG_UNION;
#endif
#define SUB_PMIC_BUCK7_EN_CFG_reg_buck7_en_START (0)
#define SUB_PMIC_BUCK7_EN_CFG_reg_buck7_en_END (0)
#define SUB_PMIC_BUCK7_EN_CFG_st_buck7_en_START (1)
#define SUB_PMIC_BUCK7_EN_CFG_st_buck7_en_END (1)
#define SUB_PMIC_BUCK7_EN_CFG_reg_buck7_eco_en_START (4)
#define SUB_PMIC_BUCK7_EN_CFG_reg_buck7_eco_en_END (4)
#define SUB_PMIC_BUCK7_EN_CFG_st_buck7_eco_en_START (5)
#define SUB_PMIC_BUCK7_EN_CFG_st_buck7_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_vset_cfg : 6;
        unsigned char reserved : 1;
        unsigned char ldo39_linkage_en : 1;
    } reg;
} SUB_PMIC_LDO39_VSET_CFG_UNION;
#endif
#define SUB_PMIC_LDO39_VSET_CFG_ldo39_vset_cfg_START (0)
#define SUB_PMIC_LDO39_VSET_CFG_ldo39_vset_cfg_END (5)
#define SUB_PMIC_LDO39_VSET_CFG_ldo39_linkage_en_START (7)
#define SUB_PMIC_LDO39_VSET_CFG_ldo39_linkage_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo39_en : 1;
        unsigned char st_ldo39_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo39_eco_en : 1;
        unsigned char st_ldo39_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SUB_PMIC_LDO39_EN_CFG_UNION;
#endif
#define SUB_PMIC_LDO39_EN_CFG_reg_ldo39_en_START (0)
#define SUB_PMIC_LDO39_EN_CFG_reg_ldo39_en_END (0)
#define SUB_PMIC_LDO39_EN_CFG_st_ldo39_en_START (1)
#define SUB_PMIC_LDO39_EN_CFG_st_ldo39_en_END (1)
#define SUB_PMIC_LDO39_EN_CFG_reg_ldo39_eco_en_START (4)
#define SUB_PMIC_LDO39_EN_CFG_reg_ldo39_eco_en_END (4)
#define SUB_PMIC_LDO39_EN_CFG_st_ldo39_eco_en_START (5)
#define SUB_PMIC_LDO39_EN_CFG_st_ldo39_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK0_CFG_REG_0_np_buck0_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK0_CFG_REG_0_np_buck0_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK0_CFG_REG_1_np_buck0_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK0_CFG_REG_1_np_buck0_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK0_CFG_REG_2_np_buck0_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK0_CFG_REG_2_np_buck0_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK0_CFG_REG_3_np_buck0_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK0_CFG_REG_3_np_buck0_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK0_CFG_REG_4_np_buck0_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK0_CFG_REG_4_np_buck0_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck1_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK1_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK1_CFG_REG_0_np_buck1_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK1_CFG_REG_0_np_buck1_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck1_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK1_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK1_CFG_REG_1_np_buck1_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK1_CFG_REG_1_np_buck1_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck1_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK1_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK1_CFG_REG_2_np_buck1_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK1_CFG_REG_2_np_buck1_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck1_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK1_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK1_CFG_REG_3_np_buck1_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK1_CFG_REG_3_np_buck1_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck1_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK1_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK1_CFG_REG_4_np_buck1_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK1_CFG_REG_4_np_buck1_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck2_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK2_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK2_CFG_REG_0_np_buck2_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK2_CFG_REG_0_np_buck2_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck2_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK2_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK2_CFG_REG_1_np_buck2_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK2_CFG_REG_1_np_buck2_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck2_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK2_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK2_CFG_REG_2_np_buck2_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK2_CFG_REG_2_np_buck2_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck2_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK2_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK2_CFG_REG_3_np_buck2_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK2_CFG_REG_3_np_buck2_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck2_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK2_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK2_CFG_REG_4_np_buck2_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK2_CFG_REG_4_np_buck2_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck3_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK3_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK3_CFG_REG_0_np_buck3_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK3_CFG_REG_0_np_buck3_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck3_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK3_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK3_CFG_REG_1_np_buck3_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK3_CFG_REG_1_np_buck3_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck3_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK3_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK3_CFG_REG_2_np_buck3_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK3_CFG_REG_2_np_buck3_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck3_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK3_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK3_CFG_REG_3_np_buck3_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK3_CFG_REG_3_np_buck3_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck3_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK3_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK3_CFG_REG_4_np_buck3_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK3_CFG_REG_4_np_buck3_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0123_reserve0 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0123_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK0123_CFG_REG_0_np_buck0123_reserve0_START (0)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_0_np_buck0123_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0123_reserve1 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0123_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK0123_CFG_REG_1_np_buck0123_reserve1_START (0)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_1_np_buck0123_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck0123_reserve2 : 8;
    } reg;
} SUB_PMIC_NP_BUCK0123_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK0123_CFG_REG_2_np_buck0123_reserve2_START (0)
#define SUB_PMIC_NP_BUCK0123_CFG_REG_2_np_buck0123_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK4_CFG_REG_0_np_buck4_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK4_CFG_REG_0_np_buck4_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK4_CFG_REG_1_np_buck4_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK4_CFG_REG_1_np_buck4_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK4_CFG_REG_2_np_buck4_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK4_CFG_REG_2_np_buck4_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK4_CFG_REG_3_np_buck4_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK4_CFG_REG_3_np_buck4_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK4_CFG_REG_4_np_buck4_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK4_CFG_REG_4_np_buck4_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck5_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK5_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK5_CFG_REG_0_np_buck5_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK5_CFG_REG_0_np_buck5_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck5_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK5_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK5_CFG_REG_1_np_buck5_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK5_CFG_REG_1_np_buck5_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck5_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK5_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK5_CFG_REG_2_np_buck5_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK5_CFG_REG_2_np_buck5_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck5_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK5_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK5_CFG_REG_3_np_buck5_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK5_CFG_REG_3_np_buck5_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck5_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK5_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK5_CFG_REG_4_np_buck5_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK5_CFG_REG_4_np_buck5_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck6_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK6_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK6_CFG_REG_0_np_buck6_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK6_CFG_REG_0_np_buck6_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck6_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK6_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK6_CFG_REG_1_np_buck6_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK6_CFG_REG_1_np_buck6_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck6_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK6_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK6_CFG_REG_2_np_buck6_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK6_CFG_REG_2_np_buck6_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck6_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK6_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK6_CFG_REG_3_np_buck6_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK6_CFG_REG_3_np_buck6_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck6_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK6_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK6_CFG_REG_4_np_buck6_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK6_CFG_REG_4_np_buck6_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck7_regconfig00 : 8;
    } reg;
} SUB_PMIC_NP_BUCK7_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK7_CFG_REG_0_np_buck7_regconfig00_START (0)
#define SUB_PMIC_NP_BUCK7_CFG_REG_0_np_buck7_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck7_regconfig01 : 8;
    } reg;
} SUB_PMIC_NP_BUCK7_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK7_CFG_REG_1_np_buck7_regconfig01_START (0)
#define SUB_PMIC_NP_BUCK7_CFG_REG_1_np_buck7_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck7_regconfig02 : 8;
    } reg;
} SUB_PMIC_NP_BUCK7_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK7_CFG_REG_2_np_buck7_regconfig02_START (0)
#define SUB_PMIC_NP_BUCK7_CFG_REG_2_np_buck7_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck7_regconfig03 : 8;
    } reg;
} SUB_PMIC_NP_BUCK7_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_NP_BUCK7_CFG_REG_3_np_buck7_regconfig03_START (0)
#define SUB_PMIC_NP_BUCK7_CFG_REG_3_np_buck7_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck7_regconfig04 : 8;
    } reg;
} SUB_PMIC_NP_BUCK7_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_NP_BUCK7_CFG_REG_4_np_buck7_regconfig04_START (0)
#define SUB_PMIC_NP_BUCK7_CFG_REG_4_np_buck7_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4567_reserve0 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4567_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_NP_BUCK4567_CFG_REG_0_np_buck4567_reserve0_START (0)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_0_np_buck4567_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4567_reserve1 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4567_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_NP_BUCK4567_CFG_REG_1_np_buck4567_reserve1_START (0)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_1_np_buck4567_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck4567_reserve2 : 8;
    } reg;
} SUB_PMIC_NP_BUCK4567_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_NP_BUCK4567_CFG_REG_2_np_buck4567_reserve2_START (0)
#define SUB_PMIC_NP_BUCK4567_CFG_REG_2_np_buck4567_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_config : 8;
    } reg;
} SUB_PMIC_LDO39_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_LDO39_CFG_REG_0_ldo39_config_START (0)
#define SUB_PMIC_LDO39_CFG_REG_0_ldo39_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo39_ocp_test : 1;
        unsigned char ldo39_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_LDO39_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_LDO39_CFG_REG_1_ldo39_ocp_test_START (0)
#define SUB_PMIC_LDO39_CFG_REG_1_ldo39_ocp_test_END (0)
#define SUB_PMIC_LDO39_CFG_REG_1_ldo39_ocp_set_START (1)
#define SUB_PMIC_LDO39_CFG_REG_1_ldo39_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_config : 4;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_LDO_PMUH_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_LDO_PMUH_CFG_REG_0_pmuh_config_START (0)
#define SUB_PMIC_LDO_PMUH_CFG_REG_0_pmuh_config_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_stb_set : 4;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_LDO_PMUH_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_LDO_PMUH_CFG_REG_1_pmuh_stb_set_START (0)
#define SUB_PMIC_LDO_PMUH_CFG_REG_1_pmuh_stb_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve0 : 8;
    } reg;
} SUB_PMIC_LDO_RESERVE_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_LDO_RESERVE_CFG_REG_0_ldo_reserve0_START (0)
#define SUB_PMIC_LDO_RESERVE_CFG_REG_0_ldo_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_res_sel_cfg : 1;
        unsigned char ref_ibias_trim_en : 2;
        unsigned char ref_eco_en : 1;
        unsigned char ref_bg_test : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_BANDGAP_THSD_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_res_sel_cfg_START (0)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_res_sel_cfg_END (0)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_ibias_trim_en_START (1)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_ibias_trim_en_END (2)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_eco_en_START (3)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_eco_en_END (3)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_bg_test_START (4)
#define SUB_PMIC_BANDGAP_THSD_CFG_REG_0_ref_bg_test_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_osc_9m6_sel : 8;
    } reg;
} SUB_PMIC_OSC_9M6_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_OSC_9M6_CFG_REG_1_d2a_osc_9m6_sel_START (0)
#define SUB_PMIC_OSC_9M6_CFG_REG_1_d2a_osc_9m6_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sys_ctrl_reserve : 8;
    } reg;
} SUB_PMIC_SYS_CTRL_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_CFG_REG_1_sys_ctrl_reserve_START (0)
#define SUB_PMIC_SYS_CTRL_CFG_REG_1_sys_ctrl_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_0_buck0_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_0_buck0_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_1_buck0_regconfig00_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_1_buck0_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_2_buck0_regconfig01_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_2_buck0_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_3_buck0_regconfig02_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_3_buck0_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_4_buck0_regconfig03_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_4_buck0_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_5_buck0_regconfig04_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_5_buck0_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_6_buck0_regconfig05_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_6_buck0_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_7_buck0_regconfig06_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_7_buck0_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_8_buck0_regconfig07_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_8_buck0_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_9_buck0_regconfig08_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_9_buck0_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_10_buck0_regconfig09_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_10_buck0_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_11_buck0_regconfig10_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_11_buck0_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_12_buck0_regconfig11_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_12_buck0_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_13_buck0_regconfig12_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_13_buck0_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_14_buck0_regconfig13_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_14_buck0_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_15_buck0_regconfig14_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_15_buck0_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_16_buck0_regconfig15_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_16_buck0_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_17_buck0_regconfig16_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_17_buck0_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_18_buck0_regconfig17_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_18_buck0_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_19_buck0_regconfig18_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_19_buck0_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_20_buck0_regconfig19_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_20_buck0_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_21_buck0_regconfig20_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_21_buck0_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_22_buck0_regconfig21_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_22_buck0_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_23_buck0_regconfig22_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_23_buck0_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_24_buck0_regconfig23_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_24_buck0_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_25_buck0_regconfig24_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_25_buck0_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_26_buck0_regconfig25_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_26_buck0_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_27_buck0_regconfig26_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_27_buck0_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_28_buck0_regconfig27_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_28_buck0_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_29_buck0_regconfig28_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_29_buck0_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_30_buck0_regconfig29_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_30_buck0_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_31_buck0_regconfig30_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_31_buck0_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_32_buck0_regconfig31_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_32_buck0_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_33_buck0_regconfig32_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_33_buck0_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_34_buck0_regconfig33_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_34_buck0_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_35_buck0_regconfig34_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_35_buck0_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_36_buck0_regconfig35_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_36_buck0_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_37_buck0_regconfig36_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_37_buck0_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_38_buck0_regconfig37_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_38_buck0_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_39_buck0_regconfig38_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_39_buck0_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_40_buck0_regconfig39_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_40_buck0_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_41_buck0_regconfig40_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_41_buck0_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_42_buck0_regconfig41_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_42_buck0_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_43_buck0_regconfig42_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_43_buck0_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_44_buck0_regconfig43_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_44_buck0_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_45_buck0_regconfig44_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_45_buck0_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_46_buck0_regconfig45_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_46_buck0_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_47_buck0_regconfig46_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_47_buck0_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_48_buck0_regconfig47_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_48_buck0_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_49_buck0_regconfig48_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_49_buck0_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_50_buck0_regconfig49_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_50_buck0_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0_regconfig50 : 8;
    } reg;
} SUB_PMIC_BUCK0_CFG_REG_51_UNION;
#endif
#define SUB_PMIC_BUCK0_CFG_REG_51_buck0_regconfig50_START (0)
#define SUB_PMIC_BUCK0_CFG_REG_51_buck0_regconfig50_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_0_buck1_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_0_buck1_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_1_buck1_regconfig00_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_1_buck1_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_2_buck1_regconfig01_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_2_buck1_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_3_buck1_regconfig02_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_3_buck1_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_4_buck1_regconfig03_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_4_buck1_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_5_buck1_regconfig04_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_5_buck1_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_6_buck1_regconfig05_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_6_buck1_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_7_buck1_regconfig06_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_7_buck1_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_8_buck1_regconfig07_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_8_buck1_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_9_buck1_regconfig08_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_9_buck1_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_10_buck1_regconfig09_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_10_buck1_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_11_buck1_regconfig10_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_11_buck1_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_12_buck1_regconfig11_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_12_buck1_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_13_buck1_regconfig12_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_13_buck1_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_14_buck1_regconfig13_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_14_buck1_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_15_buck1_regconfig14_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_15_buck1_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_16_buck1_regconfig15_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_16_buck1_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_17_buck1_regconfig16_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_17_buck1_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_18_buck1_regconfig17_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_18_buck1_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_19_buck1_regconfig18_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_19_buck1_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_20_buck1_regconfig19_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_20_buck1_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_21_buck1_regconfig20_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_21_buck1_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_22_buck1_regconfig21_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_22_buck1_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_23_buck1_regconfig22_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_23_buck1_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_24_buck1_regconfig23_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_24_buck1_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_25_buck1_regconfig24_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_25_buck1_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_26_buck1_regconfig25_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_26_buck1_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_27_buck1_regconfig26_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_27_buck1_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_28_buck1_regconfig27_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_28_buck1_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_29_buck1_regconfig28_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_29_buck1_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_30_buck1_regconfig29_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_30_buck1_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_31_buck1_regconfig30_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_31_buck1_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_32_buck1_regconfig31_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_32_buck1_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_33_buck1_regconfig32_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_33_buck1_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_34_buck1_regconfig33_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_34_buck1_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_35_buck1_regconfig34_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_35_buck1_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_36_buck1_regconfig35_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_36_buck1_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_37_buck1_regconfig36_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_37_buck1_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_38_buck1_regconfig37_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_38_buck1_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_39_buck1_regconfig38_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_39_buck1_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_40_buck1_regconfig39_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_40_buck1_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_41_buck1_regconfig40_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_41_buck1_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_42_buck1_regconfig41_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_42_buck1_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_43_buck1_regconfig42_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_43_buck1_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_44_buck1_regconfig43_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_44_buck1_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_45_buck1_regconfig44_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_45_buck1_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_46_buck1_regconfig45_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_46_buck1_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_47_buck1_regconfig46_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_47_buck1_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_48_buck1_regconfig47_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_48_buck1_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_49_buck1_regconfig48_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_49_buck1_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_50_buck1_regconfig49_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_50_buck1_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_regconfig50 : 8;
    } reg;
} SUB_PMIC_BUCK1_CFG_REG_51_UNION;
#endif
#define SUB_PMIC_BUCK1_CFG_REG_51_buck1_regconfig50_START (0)
#define SUB_PMIC_BUCK1_CFG_REG_51_buck1_regconfig50_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_0_buck2_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_0_buck2_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_1_buck2_regconfig00_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_1_buck2_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_2_buck2_regconfig01_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_2_buck2_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_3_buck2_regconfig02_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_3_buck2_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_4_buck2_regconfig03_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_4_buck2_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_5_buck2_regconfig04_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_5_buck2_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_6_buck2_regconfig05_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_6_buck2_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_7_buck2_regconfig06_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_7_buck2_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_8_buck2_regconfig07_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_8_buck2_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_9_buck2_regconfig08_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_9_buck2_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_10_buck2_regconfig09_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_10_buck2_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_11_buck2_regconfig10_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_11_buck2_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_12_buck2_regconfig11_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_12_buck2_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_13_buck2_regconfig12_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_13_buck2_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_14_buck2_regconfig13_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_14_buck2_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_15_buck2_regconfig14_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_15_buck2_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_16_buck2_regconfig15_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_16_buck2_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_17_buck2_regconfig16_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_17_buck2_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_18_buck2_regconfig17_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_18_buck2_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_19_buck2_regconfig18_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_19_buck2_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_20_buck2_regconfig19_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_20_buck2_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_21_buck2_regconfig20_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_21_buck2_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_22_buck2_regconfig21_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_22_buck2_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_23_buck2_regconfig22_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_23_buck2_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_24_buck2_regconfig23_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_24_buck2_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_25_buck2_regconfig24_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_25_buck2_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_26_buck2_regconfig25_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_26_buck2_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_27_buck2_regconfig26_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_27_buck2_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_28_buck2_regconfig27_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_28_buck2_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_29_buck2_regconfig28_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_29_buck2_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_30_buck2_regconfig29_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_30_buck2_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_31_buck2_regconfig30_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_31_buck2_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_32_buck2_regconfig31_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_32_buck2_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_33_buck2_regconfig32_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_33_buck2_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_34_buck2_regconfig33_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_34_buck2_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_35_buck2_regconfig34_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_35_buck2_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_36_buck2_regconfig35_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_36_buck2_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_37_buck2_regconfig36_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_37_buck2_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_38_buck2_regconfig37_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_38_buck2_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_39_buck2_regconfig38_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_39_buck2_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_40_buck2_regconfig39_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_40_buck2_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_41_buck2_regconfig40_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_41_buck2_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_42_buck2_regconfig41_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_42_buck2_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_43_buck2_regconfig42_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_43_buck2_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_44_buck2_regconfig43_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_44_buck2_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_45_buck2_regconfig44_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_45_buck2_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_46_buck2_regconfig45_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_46_buck2_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_47_buck2_regconfig46_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_47_buck2_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_48_buck2_regconfig47_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_48_buck2_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_49_buck2_regconfig48_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_49_buck2_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_50_buck2_regconfig49_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_50_buck2_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_regconfig50 : 8;
    } reg;
} SUB_PMIC_BUCK2_CFG_REG_51_UNION;
#endif
#define SUB_PMIC_BUCK2_CFG_REG_51_buck2_regconfig50_START (0)
#define SUB_PMIC_BUCK2_CFG_REG_51_buck2_regconfig50_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_0_buck3_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_0_buck3_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_1_buck3_regconfig00_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_1_buck3_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_2_buck3_regconfig01_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_2_buck3_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_3_buck3_regconfig02_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_3_buck3_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_4_buck3_regconfig03_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_4_buck3_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_5_buck3_regconfig04_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_5_buck3_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_6_buck3_regconfig05_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_6_buck3_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_7_buck3_regconfig06_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_7_buck3_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_8_buck3_regconfig07_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_8_buck3_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_9_buck3_regconfig08_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_9_buck3_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_10_buck3_regconfig09_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_10_buck3_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_11_buck3_regconfig10_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_11_buck3_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_12_buck3_regconfig11_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_12_buck3_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_13_buck3_regconfig12_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_13_buck3_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_14_buck3_regconfig13_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_14_buck3_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_15_buck3_regconfig14_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_15_buck3_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_16_buck3_regconfig15_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_16_buck3_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_17_buck3_regconfig16_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_17_buck3_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_18_buck3_regconfig17_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_18_buck3_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_19_buck3_regconfig18_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_19_buck3_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_20_buck3_regconfig19_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_20_buck3_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_21_buck3_regconfig20_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_21_buck3_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_22_buck3_regconfig21_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_22_buck3_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_23_buck3_regconfig22_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_23_buck3_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_24_buck3_regconfig23_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_24_buck3_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_25_buck3_regconfig24_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_25_buck3_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_26_buck3_regconfig25_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_26_buck3_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_27_buck3_regconfig26_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_27_buck3_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_28_buck3_regconfig27_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_28_buck3_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_29_buck3_regconfig28_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_29_buck3_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_30_buck3_regconfig29_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_30_buck3_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_31_buck3_regconfig30_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_31_buck3_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_32_buck3_regconfig31_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_32_buck3_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_33_buck3_regconfig32_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_33_buck3_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_34_buck3_regconfig33_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_34_buck3_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_35_buck3_regconfig34_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_35_buck3_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_36_buck3_regconfig35_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_36_buck3_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_37_buck3_regconfig36_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_37_buck3_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_38_buck3_regconfig37_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_38_buck3_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_39_buck3_regconfig38_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_39_buck3_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_40_buck3_regconfig39_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_40_buck3_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_41_buck3_regconfig40_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_41_buck3_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_42_buck3_regconfig41_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_42_buck3_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_43_buck3_regconfig42_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_43_buck3_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_44_buck3_regconfig43_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_44_buck3_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_45_buck3_regconfig44_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_45_buck3_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_46_buck3_regconfig45_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_46_buck3_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_47_buck3_regconfig46_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_47_buck3_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_48_buck3_regconfig47_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_48_buck3_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_49_buck3_regconfig48_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_49_buck3_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_50_buck3_regconfig49_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_50_buck3_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_regconfig50 : 8;
    } reg;
} SUB_PMIC_BUCK3_CFG_REG_51_UNION;
#endif
#define SUB_PMIC_BUCK3_CFG_REG_51_buck3_regconfig50_START (0)
#define SUB_PMIC_BUCK3_CFG_REG_51_buck3_regconfig50_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve0 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_0_buck0123_reserve0_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_0_buck0123_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve1 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_1_buck0123_reserve1_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_1_buck0123_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve10 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_2_buck0123_reserve10_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_2_buck0123_reserve10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve11 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_3_buck0123_reserve11_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_3_buck0123_reserve11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve12 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_4_buck0123_reserve12_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_4_buck0123_reserve12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve13 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_5_buck0123_reserve13_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_5_buck0123_reserve13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve14 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_6_buck0123_reserve14_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_6_buck0123_reserve14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve15 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_7_buck0123_reserve15_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_7_buck0123_reserve15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve2 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_8_buck0123_reserve2_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_8_buck0123_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve3 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_9_buck0123_reserve3_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_9_buck0123_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve4 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_10_buck0123_reserve4_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_10_buck0123_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve5 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_11_buck0123_reserve5_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_11_buck0123_reserve5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve6 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_12_buck0123_reserve6_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_12_buck0123_reserve6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve7 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_13_buck0123_reserve7_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_13_buck0123_reserve7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve8 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_14_buck0123_reserve8_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_14_buck0123_reserve8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck0123_reserve9 : 8;
    } reg;
} SUB_PMIC_BUCK0123_RESERVES_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_15_buck0123_reserve9_START (0)
#define SUB_PMIC_BUCK0123_RESERVES_CFG_REG_15_buck0123_reserve9_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_0_buck4_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_0_buck4_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_1_buck4_regconfig00_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_1_buck4_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_2_buck4_regconfig01_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_2_buck4_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_3_buck4_regconfig02_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_3_buck4_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_4_buck4_regconfig03_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_4_buck4_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_5_buck4_regconfig04_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_5_buck4_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_6_buck4_regconfig05_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_6_buck4_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_7_buck4_regconfig06_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_7_buck4_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_8_buck4_regconfig07_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_8_buck4_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_9_buck4_regconfig08_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_9_buck4_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_10_buck4_regconfig09_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_10_buck4_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_11_buck4_regconfig10_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_11_buck4_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_12_buck4_regconfig11_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_12_buck4_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_13_buck4_regconfig12_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_13_buck4_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_14_buck4_regconfig13_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_14_buck4_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_15_buck4_regconfig14_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_15_buck4_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_16_buck4_regconfig15_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_16_buck4_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_17_buck4_regconfig16_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_17_buck4_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_18_buck4_regconfig17_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_18_buck4_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_19_buck4_regconfig18_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_19_buck4_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_20_buck4_regconfig19_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_20_buck4_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_21_buck4_regconfig20_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_21_buck4_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_22_buck4_regconfig21_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_22_buck4_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_23_buck4_regconfig22_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_23_buck4_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_24_buck4_regconfig23_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_24_buck4_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_25_buck4_regconfig24_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_25_buck4_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_26_buck4_regconfig25_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_26_buck4_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_27_buck4_regconfig26_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_27_buck4_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_28_buck4_regconfig27_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_28_buck4_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_29_buck4_regconfig28_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_29_buck4_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_30_buck4_regconfig29_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_30_buck4_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_31_buck4_regconfig30_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_31_buck4_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_32_buck4_regconfig31_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_32_buck4_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_33_buck4_regconfig32_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_33_buck4_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_34_buck4_regconfig33_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_34_buck4_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_35_buck4_regconfig34_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_35_buck4_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_36_buck4_regconfig35_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_36_buck4_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_37_buck4_regconfig36_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_37_buck4_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_38_buck4_regconfig37_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_38_buck4_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_39_buck4_regconfig38_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_39_buck4_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_40_buck4_regconfig39_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_40_buck4_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_41_buck4_regconfig40_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_41_buck4_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_42_buck4_regconfig41_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_42_buck4_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_43_buck4_regconfig42_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_43_buck4_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_44_buck4_regconfig43_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_44_buck4_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_45_buck4_regconfig44_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_45_buck4_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_46_buck4_regconfig45_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_46_buck4_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_47_buck4_regconfig46_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_47_buck4_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_48_buck4_regconfig47_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_48_buck4_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_49_buck4_regconfig48_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_49_buck4_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK4_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK4_CFG_REG_50_buck4_regconfig49_START (0)
#define SUB_PMIC_BUCK4_CFG_REG_50_buck4_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_0_buck5_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_0_buck5_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_1_buck5_regconfig00_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_1_buck5_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_2_buck5_regconfig01_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_2_buck5_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_3_buck5_regconfig02_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_3_buck5_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_4_buck5_regconfig03_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_4_buck5_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_5_buck5_regconfig04_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_5_buck5_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_6_buck5_regconfig05_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_6_buck5_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_7_buck5_regconfig06_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_7_buck5_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_8_buck5_regconfig07_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_8_buck5_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_9_buck5_regconfig08_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_9_buck5_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_10_buck5_regconfig09_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_10_buck5_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_11_buck5_regconfig10_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_11_buck5_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_12_buck5_regconfig11_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_12_buck5_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_13_buck5_regconfig12_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_13_buck5_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_14_buck5_regconfig13_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_14_buck5_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_15_buck5_regconfig14_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_15_buck5_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_16_buck5_regconfig15_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_16_buck5_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_17_buck5_regconfig16_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_17_buck5_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_18_buck5_regconfig17_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_18_buck5_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_19_buck5_regconfig18_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_19_buck5_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_20_buck5_regconfig19_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_20_buck5_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_21_buck5_regconfig20_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_21_buck5_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_22_buck5_regconfig21_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_22_buck5_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_23_buck5_regconfig22_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_23_buck5_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_24_buck5_regconfig23_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_24_buck5_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_25_buck5_regconfig24_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_25_buck5_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_26_buck5_regconfig25_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_26_buck5_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_27_buck5_regconfig26_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_27_buck5_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_28_buck5_regconfig27_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_28_buck5_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_29_buck5_regconfig28_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_29_buck5_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_30_buck5_regconfig29_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_30_buck5_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_31_buck5_regconfig30_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_31_buck5_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_32_buck5_regconfig31_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_32_buck5_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_33_buck5_regconfig32_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_33_buck5_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_34_buck5_regconfig33_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_34_buck5_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_35_buck5_regconfig34_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_35_buck5_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_36_buck5_regconfig35_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_36_buck5_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_37_buck5_regconfig36_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_37_buck5_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_38_buck5_regconfig37_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_38_buck5_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_39_buck5_regconfig38_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_39_buck5_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_40_buck5_regconfig39_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_40_buck5_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_41_buck5_regconfig40_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_41_buck5_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_42_buck5_regconfig41_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_42_buck5_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_43_buck5_regconfig42_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_43_buck5_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_44_buck5_regconfig43_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_44_buck5_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_45_buck5_regconfig44_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_45_buck5_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_46_buck5_regconfig45_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_46_buck5_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_47_buck5_regconfig46_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_47_buck5_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_48_buck5_regconfig47_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_48_buck5_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_49_buck5_regconfig48_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_49_buck5_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck5_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK5_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK5_CFG_REG_50_buck5_regconfig49_START (0)
#define SUB_PMIC_BUCK5_CFG_REG_50_buck5_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_0_buck6_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_0_buck6_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_1_buck6_regconfig00_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_1_buck6_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_2_buck6_regconfig01_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_2_buck6_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_3_buck6_regconfig02_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_3_buck6_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_4_buck6_regconfig03_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_4_buck6_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_5_buck6_regconfig04_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_5_buck6_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_6_buck6_regconfig05_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_6_buck6_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_7_buck6_regconfig06_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_7_buck6_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_8_buck6_regconfig07_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_8_buck6_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_9_buck6_regconfig08_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_9_buck6_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_10_buck6_regconfig09_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_10_buck6_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_11_buck6_regconfig10_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_11_buck6_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_12_buck6_regconfig11_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_12_buck6_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_13_buck6_regconfig12_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_13_buck6_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_14_buck6_regconfig13_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_14_buck6_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_15_buck6_regconfig14_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_15_buck6_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_16_buck6_regconfig15_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_16_buck6_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_17_buck6_regconfig16_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_17_buck6_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_18_buck6_regconfig17_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_18_buck6_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_19_buck6_regconfig18_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_19_buck6_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_20_buck6_regconfig19_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_20_buck6_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_21_buck6_regconfig20_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_21_buck6_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_22_buck6_regconfig21_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_22_buck6_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_23_buck6_regconfig22_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_23_buck6_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_24_buck6_regconfig23_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_24_buck6_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_25_buck6_regconfig24_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_25_buck6_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_26_buck6_regconfig25_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_26_buck6_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_27_buck6_regconfig26_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_27_buck6_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_28_buck6_regconfig27_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_28_buck6_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_29_buck6_regconfig28_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_29_buck6_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_30_buck6_regconfig29_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_30_buck6_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_31_buck6_regconfig30_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_31_buck6_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_32_buck6_regconfig31_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_32_buck6_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_33_buck6_regconfig32_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_33_buck6_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_34_buck6_regconfig33_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_34_buck6_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_35_buck6_regconfig34_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_35_buck6_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_36_buck6_regconfig35_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_36_buck6_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_37_buck6_regconfig36_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_37_buck6_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_38_buck6_regconfig37_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_38_buck6_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_39_buck6_regconfig38_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_39_buck6_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_40_buck6_regconfig39_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_40_buck6_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_41_buck6_regconfig40_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_41_buck6_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_42_buck6_regconfig41_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_42_buck6_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_43_buck6_regconfig42_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_43_buck6_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_44_buck6_regconfig43_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_44_buck6_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_45_buck6_regconfig44_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_45_buck6_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_46_buck6_regconfig45_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_46_buck6_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_47_buck6_regconfig46_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_47_buck6_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_48_buck6_regconfig47_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_48_buck6_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_49_buck6_regconfig48_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_49_buck6_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck6_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK6_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK6_CFG_REG_50_buck6_regconfig49_START (0)
#define SUB_PMIC_BUCK6_CFG_REG_50_buck6_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_pwr_rontst_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_0_buck7_pwr_rontst_sel_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_0_buck7_pwr_rontst_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig00 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_1_buck7_regconfig00_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_1_buck7_regconfig00_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig01 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_2_buck7_regconfig01_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_2_buck7_regconfig01_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig02 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_3_buck7_regconfig02_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_3_buck7_regconfig02_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig03 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_4_buck7_regconfig03_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_4_buck7_regconfig03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig04 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_5_buck7_regconfig04_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_5_buck7_regconfig04_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig05 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_6_buck7_regconfig05_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_6_buck7_regconfig05_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig06 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_7_buck7_regconfig06_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_7_buck7_regconfig06_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig07 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_8_buck7_regconfig07_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_8_buck7_regconfig07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig08 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_9_buck7_regconfig08_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_9_buck7_regconfig08_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig09 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_10_buck7_regconfig09_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_10_buck7_regconfig09_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig10 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_11_buck7_regconfig10_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_11_buck7_regconfig10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig11 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_12_buck7_regconfig11_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_12_buck7_regconfig11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig12 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_13_buck7_regconfig12_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_13_buck7_regconfig12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig13 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_14_buck7_regconfig13_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_14_buck7_regconfig13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig14 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_15_buck7_regconfig14_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_15_buck7_regconfig14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig15 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_16_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_16_buck7_regconfig15_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_16_buck7_regconfig15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig16 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_17_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_17_buck7_regconfig16_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_17_buck7_regconfig16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig17 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_18_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_18_buck7_regconfig17_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_18_buck7_regconfig17_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig18 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_19_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_19_buck7_regconfig18_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_19_buck7_regconfig18_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig19 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_20_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_20_buck7_regconfig19_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_20_buck7_regconfig19_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig20 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_21_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_21_buck7_regconfig20_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_21_buck7_regconfig20_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig21 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_22_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_22_buck7_regconfig21_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_22_buck7_regconfig21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig22 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_23_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_23_buck7_regconfig22_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_23_buck7_regconfig22_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig23 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_24_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_24_buck7_regconfig23_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_24_buck7_regconfig23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig24 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_25_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_25_buck7_regconfig24_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_25_buck7_regconfig24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig25 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_26_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_26_buck7_regconfig25_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_26_buck7_regconfig25_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig26 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_27_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_27_buck7_regconfig26_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_27_buck7_regconfig26_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig27 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_28_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_28_buck7_regconfig27_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_28_buck7_regconfig27_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig28 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_29_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_29_buck7_regconfig28_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_29_buck7_regconfig28_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig29 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_30_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_30_buck7_regconfig29_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_30_buck7_regconfig29_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig30 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_31_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_31_buck7_regconfig30_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_31_buck7_regconfig30_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig31 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_32_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_32_buck7_regconfig31_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_32_buck7_regconfig31_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig32 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_33_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_33_buck7_regconfig32_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_33_buck7_regconfig32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig33 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_34_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_34_buck7_regconfig33_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_34_buck7_regconfig33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig34 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_35_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_35_buck7_regconfig34_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_35_buck7_regconfig34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig35 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_36_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_36_buck7_regconfig35_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_36_buck7_regconfig35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig36 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_37_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_37_buck7_regconfig36_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_37_buck7_regconfig36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig37 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_38_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_38_buck7_regconfig37_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_38_buck7_regconfig37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig38 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_39_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_39_buck7_regconfig38_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_39_buck7_regconfig38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig39 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_40_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_40_buck7_regconfig39_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_40_buck7_regconfig39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig40 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_41_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_41_buck7_regconfig40_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_41_buck7_regconfig40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig41 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_42_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_42_buck7_regconfig41_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_42_buck7_regconfig41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig42 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_43_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_43_buck7_regconfig42_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_43_buck7_regconfig42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig43 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_44_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_44_buck7_regconfig43_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_44_buck7_regconfig43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig44 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_45_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_45_buck7_regconfig44_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_45_buck7_regconfig44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig45 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_46_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_46_buck7_regconfig45_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_46_buck7_regconfig45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig46 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_47_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_47_buck7_regconfig46_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_47_buck7_regconfig46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig47 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_48_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_48_buck7_regconfig47_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_48_buck7_regconfig47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig48 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_49_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_49_buck7_regconfig48_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_49_buck7_regconfig48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck7_regconfig49 : 8;
    } reg;
} SUB_PMIC_BUCK7_CFG_REG_50_UNION;
#endif
#define SUB_PMIC_BUCK7_CFG_REG_50_buck7_regconfig49_START (0)
#define SUB_PMIC_BUCK7_CFG_REG_50_buck7_regconfig49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve0 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_0_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_0_buck4567_reserve0_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_0_buck4567_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve1 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_1_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_1_buck4567_reserve1_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_1_buck4567_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve10 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_2_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_2_buck4567_reserve10_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_2_buck4567_reserve10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve11 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_3_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_3_buck4567_reserve11_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_3_buck4567_reserve11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve12 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_4_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_4_buck4567_reserve12_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_4_buck4567_reserve12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve13 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_5_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_5_buck4567_reserve13_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_5_buck4567_reserve13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve14 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_6_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_6_buck4567_reserve14_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_6_buck4567_reserve14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve15 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_7_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_7_buck4567_reserve15_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_7_buck4567_reserve15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve2 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_8_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_8_buck4567_reserve2_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_8_buck4567_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve3 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_9_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_9_buck4567_reserve3_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_9_buck4567_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve4 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_10_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_10_buck4567_reserve4_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_10_buck4567_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve5 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_11_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_11_buck4567_reserve5_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_11_buck4567_reserve5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve6 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_12_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_12_buck4567_reserve6_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_12_buck4567_reserve6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve7 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_13_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_13_buck4567_reserve7_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_13_buck4567_reserve7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve8 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_14_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_14_buck4567_reserve8_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_14_buck4567_reserve8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck4567_reserve9 : 8;
    } reg;
} SUB_PMIC_BUCK4567_RESERVES_CFG_REG_15_UNION;
#endif
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_15_buck4567_reserve9_START (0)
#define SUB_PMIC_BUCK4567_RESERVES_CFG_REG_15_buck4567_reserve9_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_bypass : 1;
        unsigned char fer_test : 1;
        unsigned char fer_snapshot : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_FER_CTRL_UNION;
#endif
#define SUB_PMIC_FER_CTRL_fer_bypass_START (0)
#define SUB_PMIC_FER_CTRL_fer_bypass_END (0)
#define SUB_PMIC_FER_CTRL_fer_test_START (1)
#define SUB_PMIC_FER_CTRL_fer_test_END (1)
#define SUB_PMIC_FER_CTRL_fer_snapshot_START (2)
#define SUB_PMIC_FER_CTRL_fer_snapshot_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_psok_level : 1;
        unsigned char fer_pmu_irq_level : 1;
        unsigned char fer_buck_ocot_level : 1;
        unsigned char fer_buck_pgvok_level : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_FER_EVENT_LEVEL_UNION;
#endif
#define SUB_PMIC_FER_EVENT_LEVEL_fer_pmu_psok_level_START (0)
#define SUB_PMIC_FER_EVENT_LEVEL_fer_pmu_psok_level_END (0)
#define SUB_PMIC_FER_EVENT_LEVEL_fer_pmu_irq_level_START (1)
#define SUB_PMIC_FER_EVENT_LEVEL_fer_pmu_irq_level_END (1)
#define SUB_PMIC_FER_EVENT_LEVEL_fer_buck_ocot_level_START (2)
#define SUB_PMIC_FER_EVENT_LEVEL_fer_buck_ocot_level_END (2)
#define SUB_PMIC_FER_EVENT_LEVEL_fer_buck_pgvok_level_START (3)
#define SUB_PMIC_FER_EVENT_LEVEL_fer_buck_pgvok_level_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_pg_msk : 8;
    } reg;
} SUB_PMIC_FER_BUCK_PG_MSK_UNION;
#endif
#define SUB_PMIC_FER_BUCK_PG_MSK_fer_buck_pg_msk_START (0)
#define SUB_PMIC_FER_BUCK_PG_MSK_fer_buck_pg_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_vok_msk : 8;
    } reg;
} SUB_PMIC_FER_BUCK_VOK_MSK_UNION;
#endif
#define SUB_PMIC_FER_BUCK_VOK_MSK_fer_buck_vok_msk_START (0)
#define SUB_PMIC_FER_BUCK_VOK_MSK_fer_buck_vok_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_oc_msk : 8;
    } reg;
} SUB_PMIC_FER_BUCK_OC_MSK_UNION;
#endif
#define SUB_PMIC_FER_BUCK_OC_MSK_fer_buck_oc_msk_START (0)
#define SUB_PMIC_FER_BUCK_OC_MSK_fer_buck_oc_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_ot_msk : 8;
    } reg;
} SUB_PMIC_FER_BUCK_OT_MSK_UNION;
#endif
#define SUB_PMIC_FER_BUCK_OT_MSK_fer_buck_ot_msk_START (0)
#define SUB_PMIC_FER_BUCK_OT_MSK_fer_buck_ot_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_psok_msk : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_FER_PMU_PSOK_MSK_UNION;
#endif
#define SUB_PMIC_FER_PMU_PSOK_MSK_fer_pmu_psok_msk_START (0)
#define SUB_PMIC_FER_PMU_PSOK_MSK_fer_pmu_psok_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_irq_msk0 : 8;
    } reg;
} SUB_PMIC_FER_PMU_IRQ_MSK0_UNION;
#endif
#define SUB_PMIC_FER_PMU_IRQ_MSK0_fer_pmu_irq_msk0_START (0)
#define SUB_PMIC_FER_PMU_IRQ_MSK0_fer_pmu_irq_msk0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_irq_msk1 : 4;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_FER_PMU_IRQ_MSK1_UNION;
#endif
#define SUB_PMIC_FER_PMU_IRQ_MSK1_fer_pmu_irq_msk1_START (0)
#define SUB_PMIC_FER_PMU_IRQ_MSK1_fer_pmu_irq_msk1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_buck_pgvok : 8;
    } reg;
} SUB_PMIC_FER_BUF_BUCK_PGVOK_UNION;
#endif
#define SUB_PMIC_FER_BUF_BUCK_PGVOK_fer_buf_buck_pgvok_START (0)
#define SUB_PMIC_FER_BUF_BUCK_PGVOK_fer_buf_buck_pgvok_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_buck_ocot : 8;
    } reg;
} SUB_PMIC_FER_BUF_BUCK_OCOT_UNION;
#endif
#define SUB_PMIC_FER_BUF_BUCK_OCOT_fer_buf_buck_ocot_START (0)
#define SUB_PMIC_FER_BUF_BUCK_OCOT_fer_buf_buck_ocot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_pmu_psok : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_FER_BUF_PMU_PSOK_UNION;
#endif
#define SUB_PMIC_FER_BUF_PMU_PSOK_fer_buf_pmu_psok_START (0)
#define SUB_PMIC_FER_BUF_PMU_PSOK_fer_buf_pmu_psok_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_pmu_irq0 : 8;
    } reg;
} SUB_PMIC_FER_BUF_PMU_IRQ0_UNION;
#endif
#define SUB_PMIC_FER_BUF_PMU_IRQ0_fer_buf_pmu_irq0_START (0)
#define SUB_PMIC_FER_BUF_PMU_IRQ0_fer_buf_pmu_irq0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_pmu_irq1 : 4;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_FER_BUF_PMU_IRQ1_UNION;
#endif
#define SUB_PMIC_FER_BUF_PMU_IRQ1_fer_buf_pmu_irq1_START (0)
#define SUB_PMIC_FER_BUF_PMU_IRQ1_fer_buf_pmu_irq1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_abit_data : 8;
    } reg;
} SUB_PMIC_FER_TRANS_ABIT_DATA_UNION;
#endif
#define SUB_PMIC_FER_TRANS_ABIT_DATA_fer_trans_abit_data_START (0)
#define SUB_PMIC_FER_TRANS_ABIT_DATA_fer_trans_abit_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_abit_addr : 8;
    } reg;
} SUB_PMIC_FER_TRANS_ABIT_ADDR_UNION;
#endif
#define SUB_PMIC_FER_TRANS_ABIT_ADDR_fer_trans_abit_addr_START (0)
#define SUB_PMIC_FER_TRANS_ABIT_ADDR_fer_trans_abit_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_srbit_data : 8;
    } reg;
} SUB_PMIC_FER_TRANS_SRBIT_DATA_UNION;
#endif
#define SUB_PMIC_FER_TRANS_SRBIT_DATA_fer_trans_srbit_data_START (0)
#define SUB_PMIC_FER_TRANS_SRBIT_DATA_fer_trans_srbit_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_srbit_addr : 8;
    } reg;
} SUB_PMIC_FER_TRANS_SRBIT_ADDR_UNION;
#endif
#define SUB_PMIC_FER_TRANS_SRBIT_ADDR_fer_trans_srbit_addr_START (0)
#define SUB_PMIC_FER_TRANS_SRBIT_ADDR_fer_trans_srbit_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug0 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG0_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG0_spmi_debug0_START (0)
#define SUB_PMIC_SPMI_DEBUG0_spmi_debug0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug1 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG1_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG1_spmi_debug1_START (0)
#define SUB_PMIC_SPMI_DEBUG1_spmi_debug1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug2 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG2_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG2_spmi_debug2_START (0)
#define SUB_PMIC_SPMI_DEBUG2_spmi_debug2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug3 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG3_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG3_spmi_debug3_START (0)
#define SUB_PMIC_SPMI_DEBUG3_spmi_debug3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug4 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG4_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG4_spmi_debug4_START (0)
#define SUB_PMIC_SPMI_DEBUG4_spmi_debug4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug5 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG5_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG5_spmi_debug5_START (0)
#define SUB_PMIC_SPMI_DEBUG5_spmi_debug5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug6 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG6_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG6_spmi_debug6_START (0)
#define SUB_PMIC_SPMI_DEBUG6_spmi_debug6_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
