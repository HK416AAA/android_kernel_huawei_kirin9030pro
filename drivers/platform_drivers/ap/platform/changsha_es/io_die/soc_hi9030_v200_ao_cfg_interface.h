#ifndef __SOC_HI9030_V200_AO_CFG_INTERFACE_H__
#define __SOC_HI9030_V200_AO_CFG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_ADDR(base) (base)
#define SOC_Hi9030_V200_AO_CFG_I3C_STAT_ADDR(base) ((base) + 0x0004UL)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_STAT_ADDR(base) ((base) + 0x0008UL)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_MASK_ADDR(base) ((base) + 0x000CUL)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_CLR_ADDR(base) ((base) + 0x0010UL)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_ADDR_ADDR(base) ((base) + 0x0014UL)
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_ADDR(base) ((base) + 0x0100UL)
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_SD_AFDFT_ADDR(base) ((base) + 0x0104UL)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_ADDR(base) ((base) + 0x010CUL)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_SD_ADDR(base) ((base) + 0x0110UL)
#define SOC_Hi9030_V200_AO_CFG_MEM_CTRL_SEL_ADDR(base) ((base) + 0x0114UL)
#define SOC_Hi9030_V200_AO_CFG_ISO_EN_ADDR(base) ((base) + 0x0200UL)
#define SOC_Hi9030_V200_AO_CFG_MTCMOS_EN_ADDR(base) ((base) + 0x0204UL)
#define SOC_Hi9030_V200_AO_CFG_ISO_MTCMOS_SEL_ADDR(base) ((base) + 0x0208UL)
#define SOC_Hi9030_V200_AO_CFG_TEST_POINT_CTRL_ADDR(base) ((base) + 0x0300UL)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_ADDR(base) ((base) + 0x0304UL)
#define SOC_Hi9030_V200_AO_CFG_VOICE_DEBC_ADDR(base) ((base) + 0x0308UL)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ADDR(base) ((base) + 0x0400UL)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG1_ADDR(base) ((base) + 0x0404UL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA0_ADDR(base) ((base) + 0x0500UL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA1_ADDR(base) ((base) + 0x0504UL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA2_ADDR(base) ((base) + 0x0508UL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA3_ADDR(base) ((base) + 0x050CUL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA4_ADDR(base) ((base) + 0x0510UL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA5_ADDR(base) ((base) + 0x0514UL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA6_ADDR(base) ((base) + 0x0518UL)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA7_ADDR(base) ((base) + 0x051CUL)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_ADDR(base) ((base) + 0x0600UL)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_ADDR(base) ((base) + 0x0604UL)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_ADDR(base) ((base) + 0x0608UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_ADDR(base) ((base) + 0x060CUL)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_ADDR(base) ((base) + 0x0610UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_ADDR(base) ((base) + 0x0614UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_SET_ADDR(base) ((base) + 0x0624UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_CLR_ADDR(base) ((base) + 0x0628UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_STA_ADDR(base) ((base) + 0x062CUL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_SET_ADDR(base) ((base) + 0x0630UL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_CLR_ADDR(base) ((base) + 0x0634UL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_STA_ADDR(base) ((base) + 0x0638UL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_SET_ADDR(base) ((base) + 0x063CUL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_CLR_ADDR(base) ((base) + 0x0640UL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_STA_ADDR(base) ((base) + 0x0644UL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_SET_ADDR(base) ((base) + 0x0648UL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_CLR_ADDR(base) ((base) + 0x064CUL)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_STA_ADDR(base) ((base) + 0x0650UL)
#define SOC_Hi9030_V200_AO_CFG_AO_PERI_LOCK_ADDR(base) ((base) + 0x0654UL)
#define SOC_Hi9030_V200_AO_CFG_PCLK_CG_BYP_ADDR(base) ((base) + 0x0800UL)
#define SOC_Hi9030_V200_AO_CFG_USIM_DATA_DISABLE_ADDR(base) ((base) + 0x0804UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_REQ_ADDR(base) ((base) + 0x0808UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_ADDR(base) ((base) + 0x080CUL)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_ADDR(base) ((base) + 0x0810UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_ADDR(base) ((base) + 0x0900UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_ADDR(base) ((base) + 0x0904UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_ADDR(base) ((base) + 0x0908UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_ADDR(base) ((base) + 0x090CUL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_ADDR(base) ((base) + 0x0910UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_ADDR(base) ((base) + 0x0914UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_ADDR(base) ((base) + 0x0918UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_ADDR(base) ((base) + 0x091CUL)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_ADDR(base) ((base) + 0x0920UL)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_MWC_F_ADDR(base) ((base) + 0x0924UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_MWC_F_ADDR(base) ((base) + 0x0928UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_MWC_F_ADDR(base) ((base) + 0x092CUL)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_MWC_F_ADDR(base) ((base) + 0x0930UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_MWC_F_ADDR(base) ((base) + 0x0934UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_MWC_F_ADDR(base) ((base) + 0x0938UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_MWC_F_ADDR(base) ((base) + 0x093CUL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_MWC_F_ADDR(base) ((base) + 0x0940UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_MWC_F_ADDR(base) ((base) + 0x0944UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_MWC_F_ADDR(base) ((base) + 0x0948UL)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_MWC_F_ADDR(base) ((base) + 0x094CUL)
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_ADDR(base) ((base) + 0x0950UL)
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_AO_ADDR(base) ((base) + 0x0954UL)
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_PERI_ADDR(base) ((base) + 0x0958UL)
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_AO_ADDR(base) ((base) + 0x095CUL)
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_PERI_ADDR(base) ((base) + 0x0960UL)
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_AO_ADDR(base) ((base) + 0x0964UL)
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_PERI_ADDR(base) ((base) + 0x0968UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_SYSPDC_PWRD_REQ_SEL_ADDR(base) ((base) + 0x096CUL)
#define SOC_Hi9030_V200_AO_CFG_MASK_INTR_ADDR(base) ((base) + 0x0970UL)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_EN_ADDR(base) ((base) + 0x0974UL)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_AO_MSK_ADDR(base) ((base) + 0x0978UL)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_PERI_MSK_ADDR(base) ((base) + 0x097CUL)
#define SOC_Hi9030_V200_AO_CFG_QIC_REQ_ACK_SEL_ADDR(base) ((base) + 0x0980UL)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_EN_ADDR(base) ((base) + 0x0B00UL)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_DIS_ADDR(base) ((base) + 0x0B04UL)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_STA_ADDR(base) ((base) + 0x0B08UL)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_ADDR(base) ((base) + 0x0B0CUL)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_ADDR(base) ((base) + 0x0B10UL)
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_LOCK_ADDR(base) ((base) + 0x0C00UL)
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_CFG_ADDR(base) ((base) + 0x0C04UL)
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_LOCK_ADDR(base) ((base) + 0x0C08UL)
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_CFG_ADDR(base) ((base) + 0x0C0CUL)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_CFGDMA_ADDR(base) ((base) + 0x0D00UL)
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVE0_ADDR(base) ((base) + 0x0E00UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_ADDR(base) ((base) + 0x0FC0UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_ADDR(base) ((base) + 0x0FC4UL)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_ADDR(base) ((base) + 0x0FC8UL)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ADDR(base) ((base) + 0x0FE0UL)
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVED1_ADDR(base) ((base) + 0x0FF0UL)
#else
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_ADDR(base) (base)
#define SOC_Hi9030_V200_AO_CFG_I3C_STAT_ADDR(base) ((base) + 0x0004)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_STAT_ADDR(base) ((base) + 0x0008)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_MASK_ADDR(base) ((base) + 0x000C)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_CLR_ADDR(base) ((base) + 0x0010)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_ADDR_ADDR(base) ((base) + 0x0014)
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_ADDR(base) ((base) + 0x0100)
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_SD_AFDFT_ADDR(base) ((base) + 0x0104)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_ADDR(base) ((base) + 0x010C)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_SD_ADDR(base) ((base) + 0x0110)
#define SOC_Hi9030_V200_AO_CFG_MEM_CTRL_SEL_ADDR(base) ((base) + 0x0114)
#define SOC_Hi9030_V200_AO_CFG_ISO_EN_ADDR(base) ((base) + 0x0200)
#define SOC_Hi9030_V200_AO_CFG_MTCMOS_EN_ADDR(base) ((base) + 0x0204)
#define SOC_Hi9030_V200_AO_CFG_ISO_MTCMOS_SEL_ADDR(base) ((base) + 0x0208)
#define SOC_Hi9030_V200_AO_CFG_TEST_POINT_CTRL_ADDR(base) ((base) + 0x0300)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_ADDR(base) ((base) + 0x0304)
#define SOC_Hi9030_V200_AO_CFG_VOICE_DEBC_ADDR(base) ((base) + 0x0308)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ADDR(base) ((base) + 0x0400)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG1_ADDR(base) ((base) + 0x0404)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA0_ADDR(base) ((base) + 0x0500)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA1_ADDR(base) ((base) + 0x0504)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA2_ADDR(base) ((base) + 0x0508)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA3_ADDR(base) ((base) + 0x050C)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA4_ADDR(base) ((base) + 0x0510)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA5_ADDR(base) ((base) + 0x0514)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA6_ADDR(base) ((base) + 0x0518)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA7_ADDR(base) ((base) + 0x051C)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_ADDR(base) ((base) + 0x0600)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_ADDR(base) ((base) + 0x0604)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_ADDR(base) ((base) + 0x0608)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_ADDR(base) ((base) + 0x060C)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_ADDR(base) ((base) + 0x0610)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_ADDR(base) ((base) + 0x0614)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_SET_ADDR(base) ((base) + 0x0624)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_CLR_ADDR(base) ((base) + 0x0628)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_STA_ADDR(base) ((base) + 0x062C)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_SET_ADDR(base) ((base) + 0x0630)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_CLR_ADDR(base) ((base) + 0x0634)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_STA_ADDR(base) ((base) + 0x0638)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_SET_ADDR(base) ((base) + 0x063C)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_CLR_ADDR(base) ((base) + 0x0640)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_STA_ADDR(base) ((base) + 0x0644)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_SET_ADDR(base) ((base) + 0x0648)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_CLR_ADDR(base) ((base) + 0x064C)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_STA_ADDR(base) ((base) + 0x0650)
#define SOC_Hi9030_V200_AO_CFG_AO_PERI_LOCK_ADDR(base) ((base) + 0x0654)
#define SOC_Hi9030_V200_AO_CFG_PCLK_CG_BYP_ADDR(base) ((base) + 0x0800)
#define SOC_Hi9030_V200_AO_CFG_USIM_DATA_DISABLE_ADDR(base) ((base) + 0x0804)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_REQ_ADDR(base) ((base) + 0x0808)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_ADDR(base) ((base) + 0x080C)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_ADDR(base) ((base) + 0x0810)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_ADDR(base) ((base) + 0x0900)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_ADDR(base) ((base) + 0x0904)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_ADDR(base) ((base) + 0x0908)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_ADDR(base) ((base) + 0x090C)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_ADDR(base) ((base) + 0x0910)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_ADDR(base) ((base) + 0x0914)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_ADDR(base) ((base) + 0x0918)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_ADDR(base) ((base) + 0x091C)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_ADDR(base) ((base) + 0x0920)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_MWC_F_ADDR(base) ((base) + 0x0924)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_MWC_F_ADDR(base) ((base) + 0x0928)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_MWC_F_ADDR(base) ((base) + 0x092C)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_MWC_F_ADDR(base) ((base) + 0x0930)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_MWC_F_ADDR(base) ((base) + 0x0934)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_MWC_F_ADDR(base) ((base) + 0x0938)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_MWC_F_ADDR(base) ((base) + 0x093C)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_MWC_F_ADDR(base) ((base) + 0x0940)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_MWC_F_ADDR(base) ((base) + 0x0944)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_MWC_F_ADDR(base) ((base) + 0x0948)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_MWC_F_ADDR(base) ((base) + 0x094C)
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_ADDR(base) ((base) + 0x0950)
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_AO_ADDR(base) ((base) + 0x0954)
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_PERI_ADDR(base) ((base) + 0x0958)
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_AO_ADDR(base) ((base) + 0x095C)
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_PERI_ADDR(base) ((base) + 0x0960)
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_AO_ADDR(base) ((base) + 0x0964)
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_PERI_ADDR(base) ((base) + 0x0968)
#define SOC_Hi9030_V200_AO_CFG_PERI_SYSPDC_PWRD_REQ_SEL_ADDR(base) ((base) + 0x096C)
#define SOC_Hi9030_V200_AO_CFG_MASK_INTR_ADDR(base) ((base) + 0x0970)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_EN_ADDR(base) ((base) + 0x0974)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_AO_MSK_ADDR(base) ((base) + 0x0978)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_PERI_MSK_ADDR(base) ((base) + 0x097C)
#define SOC_Hi9030_V200_AO_CFG_QIC_REQ_ACK_SEL_ADDR(base) ((base) + 0x0980)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_EN_ADDR(base) ((base) + 0x0B00)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_DIS_ADDR(base) ((base) + 0x0B04)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_STA_ADDR(base) ((base) + 0x0B08)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_ADDR(base) ((base) + 0x0B0C)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_ADDR(base) ((base) + 0x0B10)
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_LOCK_ADDR(base) ((base) + 0x0C00)
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_CFG_ADDR(base) ((base) + 0x0C04)
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_LOCK_ADDR(base) ((base) + 0x0C08)
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_CFG_ADDR(base) ((base) + 0x0C0C)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_CFGDMA_ADDR(base) ((base) + 0x0D00)
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVE0_ADDR(base) ((base) + 0x0E00)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_ADDR(base) ((base) + 0x0FC0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_ADDR(base) ((base) + 0x0FC4)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_ADDR(base) ((base) + 0x0FC8)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ADDR(base) ((base) + 0x0FE0)
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVED1_ADDR(base) ((base) + 0x0FF0)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int addr_sel : 2;
        unsigned int broadcast_addr_en : 1;
        unsigned int broadcast_addr : 7;
        unsigned int reserved_1 : 1;
        unsigned int sda_hold_cnt_thre : 8;
        unsigned int sda_setup_cnt_thre : 8;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_Hi9030_V200_AO_CFG_I3C_CFG_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_addr_sel_START (1)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_addr_sel_END (2)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_broadcast_addr_en_START (3)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_broadcast_addr_en_END (3)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_broadcast_addr_START (4)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_broadcast_addr_END (10)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_sda_hold_cnt_thre_START (12)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_sda_hold_cnt_thre_END (19)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_sda_setup_cnt_thre_START (20)
#define SOC_Hi9030_V200_AO_CFG_I3C_CFG_sda_setup_cnt_thre_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3cs_diag : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_I3C_STAT_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_I3C_STAT_i3cs_diag_START (0)
#define SOC_Hi9030_V200_AO_CFG_I3C_STAT_i3cs_diag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_i3c_buserr_ini : 1;
        unsigned int int_i3c_buserr_masked : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_STAT_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_STAT_int_i3c_buserr_ini_START (0)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_STAT_int_i3c_buserr_ini_END (0)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_STAT_int_i3c_buserr_masked_START (1)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_STAT_int_i3c_buserr_masked_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_i3c_buserr_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_MASK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_MASK_int_i3c_buserr_mask_START (0)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_MASK_int_i3c_buserr_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_i3c_buserr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_CLR_int_i3c_buserr_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_CLR_int_i3c_buserr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3c_buserr_addr : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_ADDR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_ADDR_i3c_buserr_addr_START (0)
#define SOC_Hi9030_V200_AO_CFG_I3C_BUS_ERR_ADDR_i3c_buserr_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_mem_ctrl : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_sp_mem_ctrl_START (0)
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_sp_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_mem_ctrl_sd_afdft : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_SD_AFDFT_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_SD_AFDFT_sp_mem_ctrl_sd_afdft_START (0)
#define SOC_Hi9030_V200_AO_CFG_SP_MEM_CTRL_SD_AFDFT_sp_mem_ctrl_sd_afdft_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_mem_ctrl : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_tp_mem_ctrl_START (0)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_tp_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_mem_ctrl_sd_dma0 : 1;
        unsigned int tp_mem_ctrl_sd_qspi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_SD_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_dma0_START (0)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_dma0_END (0)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_qspi_START (1)
#define SOC_Hi9030_V200_AO_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_qspi_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ram_sd_en_peri_sel : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MEM_CTRL_SEL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MEM_CTRL_SEL_cpu_ram_sd_en_peri_sel_START (0)
#define SOC_Hi9030_V200_AO_CFG_MEM_CTRL_SEL_cpu_ram_sd_en_peri_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iso_en_peri_cfg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_ISO_EN_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_ISO_EN_iso_en_peri_cfg_START (0)
#define SOC_Hi9030_V200_AO_CFG_ISO_EN_iso_en_peri_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mtcmos_en_peri_cfg : 1;
        unsigned int reserved_0 : 1;
        unsigned int mtcmos_ack_peri : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MTCMOS_EN_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MTCMOS_EN_mtcmos_en_peri_cfg_START (0)
#define SOC_Hi9030_V200_AO_CFG_MTCMOS_EN_mtcmos_en_peri_cfg_END (0)
#define SOC_Hi9030_V200_AO_CFG_MTCMOS_EN_mtcmos_ack_peri_START (2)
#define SOC_Hi9030_V200_AO_CFG_MTCMOS_EN_mtcmos_ack_peri_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mtcmos_en_peri_sel : 1;
        unsigned int cpu_iso_en_peri_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_ISO_MTCMOS_SEL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_ISO_MTCMOS_SEL_cpu_mtcmos_en_peri_sel_START (0)
#define SOC_Hi9030_V200_AO_CFG_ISO_MTCMOS_SEL_cpu_mtcmos_en_peri_sel_END (0)
#define SOC_Hi9030_V200_AO_CFG_ISO_MTCMOS_SEL_cpu_iso_en_peri_sel_START (1)
#define SOC_Hi9030_V200_AO_CFG_ISO_MTCMOS_SEL_cpu_iso_en_peri_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_point_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_TEST_POINT_CTRL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_TEST_POINT_CTRL_test_point_ctrl_START (0)
#define SOC_Hi9030_V200_AO_CFG_TEST_POINT_CTRL_test_point_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ms_usim0 : 1;
        unsigned int ms_usim1 : 1;
        unsigned int rte_odio : 1;
        unsigned int reserved_0 : 1;
        unsigned int rte_gpio_ao : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_ms_usim0_START (0)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_ms_usim0_END (0)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_ms_usim1_START (1)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_ms_usim1_END (1)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_rte_odio_START (2)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_rte_odio_END (2)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_rte_gpio_ao_START (4)
#define SOC_Hi9030_V200_AO_CFG_RTE_AND_MSIO_rte_gpio_ao_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int voice_debc_en : 1;
        unsigned int key_push_func_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_VOICE_DEBC_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_VOICE_DEBC_voice_debc_en_START (0)
#define SOC_Hi9030_V200_AO_CFG_VOICE_DEBC_voice_debc_en_END (0)
#define SOC_Hi9030_V200_AO_CFG_VOICE_DEBC_key_push_func_mask_START (1)
#define SOC_Hi9030_V200_AO_CFG_VOICE_DEBC_key_push_func_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldo_vset : 7;
        unsigned int ldo_debug_scan : 1;
        unsigned int ldo_hiz_en : 1;
        unsigned int ldo_ocp_en : 1;
        unsigned int ldo_ocp : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_Hi9030_V200_AO_CFG_LDO_CFG0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_vset_START (0)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_vset_END (6)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_debug_scan_START (7)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_debug_scan_END (7)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_hiz_en_START (8)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_hiz_en_END (8)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_ocp_en_START (9)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_ocp_en_END (9)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_ocp_START (10)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG0_ldo_ocp_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldo_rsv : 16;
        unsigned int ldo_cfg : 16;
    } reg;
} SOC_Hi9030_V200_AO_CFG_LDO_CFG1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG1_ldo_rsv_START (0)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG1_ldo_rsv_END (15)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG1_ldo_cfg_START (16)
#define SOC_Hi9030_V200_AO_CFG_LDO_CFG1_ldo_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA0_efuse_data0_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA0_efuse_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA1_efuse_data1_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA1_efuse_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data2 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA2_efuse_data2_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA2_efuse_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data3 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA3_efuse_data3_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA3_efuse_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data4 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA4_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA4_efuse_data4_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA4_efuse_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data5 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA5_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA5_efuse_data5_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA5_efuse_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data6 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA6_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA6_efuse_data6_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA6_efuse_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_data7 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_EFUSE_DATA7_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA7_efuse_data7_START (0)
#define SOC_Hi9030_V200_AO_CFG_EFUSE_DATA7_efuse_data7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_cfg_set : 1;
        unsigned int tz_secure_n_ao_efuse_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int tz_secure_n_ao_i2c0_set : 1;
        unsigned int tz_secure_n_ao_i2c1_set : 1;
        unsigned int tz_secure_n_ao_i2c3_set : 1;
        unsigned int tz_secure_n_ao_i2c5_set : 1;
        unsigned int tz_secure_n_ao_i3c1_set : 1;
        unsigned int tz_secure_n_ao_usim0_set : 1;
        unsigned int tz_secure_n_ao_usim1_set : 1;
        unsigned int tz_secure_n_ao_gpio0_set : 1;
        unsigned int tz_secure_n_ao_gpio1_set : 1;
        unsigned int tz_secure_n_ao_gpio2_set : 1;
        unsigned int tz_secure_n_ao_gpio3_set : 1;
        unsigned int tz_secure_n_ao_gpio4_set : 1;
        unsigned int tz_secure_n_ao_adc_set : 1;
        unsigned int tz_secure_n_ao_qic_dfx_set : 1;
        unsigned int tz_secure_n_ao_sec_region_set : 1;
        unsigned int tz_secure_n_ao_crg_set : 3;
        unsigned int tz_secure_n_ao_hiphyio_set : 2;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_cfg_set_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_cfg_set_END (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_efuse_set_START (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_efuse_set_END (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c0_set_START (3)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c0_set_END (3)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c1_set_START (4)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c1_set_END (4)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c3_set_START (5)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c3_set_END (5)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c5_set_START (6)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i2c5_set_END (6)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i3c1_set_START (7)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_i3c1_set_END (7)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_usim0_set_START (8)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_usim0_set_END (8)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_usim1_set_START (9)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_usim1_set_END (9)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio0_set_START (10)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio0_set_END (10)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio1_set_START (11)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio1_set_END (11)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio2_set_START (12)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio2_set_END (12)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio3_set_START (13)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio3_set_END (13)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio4_set_START (14)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_gpio4_set_END (14)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_adc_set_START (15)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_adc_set_END (15)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_qic_dfx_set_START (16)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_qic_dfx_set_END (16)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_sec_region_set_START (17)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_sec_region_set_END (17)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_crg_set_START (18)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_crg_set_END (20)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_hiphyio_set_START (21)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_SET_tz_secure_n_ao_hiphyio_set_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_cfg_clr : 1;
        unsigned int tz_secure_n_ao_efuse_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int tz_secure_n_ao_i2c0_clr : 1;
        unsigned int tz_secure_n_ao_i2c1_clr : 1;
        unsigned int tz_secure_n_ao_i2c3_clr : 1;
        unsigned int tz_secure_n_ao_i2c5_clr : 1;
        unsigned int tz_secure_n_ao_i3c1_clr : 1;
        unsigned int tz_secure_n_ao_usim0_clr : 1;
        unsigned int tz_secure_n_ao_usim1_clr : 1;
        unsigned int tz_secure_n_ao_gpio0_clr : 1;
        unsigned int tz_secure_n_ao_gpio1_clr : 1;
        unsigned int tz_secure_n_ao_gpio2_clr : 1;
        unsigned int tz_secure_n_ao_gpio3_clr : 1;
        unsigned int tz_secure_n_ao_gpio4_clr : 1;
        unsigned int tz_secure_n_ao_adc_clr : 1;
        unsigned int tz_secure_n_ao_qic_dfx_clr : 1;
        unsigned int tz_secure_n_ao_sec_region_clr : 1;
        unsigned int tz_secure_n_ao_crg_clr : 3;
        unsigned int tz_secure_n_ao_hiphyio_clr : 2;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_cfg_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_cfg_clr_END (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_efuse_clr_START (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_efuse_clr_END (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c0_clr_START (3)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c0_clr_END (3)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c1_clr_START (4)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c1_clr_END (4)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c3_clr_START (5)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c3_clr_END (5)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c5_clr_START (6)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i2c5_clr_END (6)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i3c1_clr_START (7)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_i3c1_clr_END (7)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_usim0_clr_START (8)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_usim0_clr_END (8)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_usim1_clr_START (9)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_usim1_clr_END (9)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio0_clr_START (10)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio0_clr_END (10)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio1_clr_START (11)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio1_clr_END (11)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio2_clr_START (12)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio2_clr_END (12)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio3_clr_START (13)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio3_clr_END (13)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio4_clr_START (14)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_gpio4_clr_END (14)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_adc_clr_START (15)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_adc_clr_END (15)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_qic_dfx_clr_START (16)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_qic_dfx_clr_END (16)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_sec_region_clr_START (17)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_sec_region_clr_END (17)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_crg_clr_START (18)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_crg_clr_END (20)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_hiphyio_clr_START (21)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_CLR_tz_secure_n_ao_hiphyio_clr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_cfg : 1;
        unsigned int tz_secure_n_ao_efuse : 1;
        unsigned int reserved_0 : 1;
        unsigned int tz_secure_n_ao_i2c0 : 1;
        unsigned int tz_secure_n_ao_i2c1 : 1;
        unsigned int tz_secure_n_ao_i2c3 : 1;
        unsigned int tz_secure_n_ao_i2c5 : 1;
        unsigned int tz_secure_n_ao_i3c1 : 1;
        unsigned int tz_secure_n_ao_usim0 : 1;
        unsigned int tz_secure_n_ao_usim1 : 1;
        unsigned int tz_secure_n_ao_gpio0 : 1;
        unsigned int tz_secure_n_ao_gpio1 : 1;
        unsigned int tz_secure_n_ao_gpio2 : 1;
        unsigned int tz_secure_n_ao_gpio3 : 1;
        unsigned int tz_secure_n_ao_gpio4 : 1;
        unsigned int tz_secure_n_ao_adc : 1;
        unsigned int tz_secure_n_ao_qic_dfx : 1;
        unsigned int tz_secure_n_ao_sec_region : 1;
        unsigned int tz_secure_n_ao_crg : 3;
        unsigned int tz_secure_n_ao_hiphyio : 2;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_cfg_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_cfg_END (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_efuse_START (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_efuse_END (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c0_START (3)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c0_END (3)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c1_START (4)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c1_END (4)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c3_START (5)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c3_END (5)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c5_START (6)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i2c5_END (6)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i3c1_START (7)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_i3c1_END (7)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_usim0_START (8)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_usim0_END (8)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_usim1_START (9)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_usim1_END (9)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio0_START (10)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio0_END (10)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio1_START (11)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio1_END (11)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio2_START (12)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio2_END (12)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio3_START (13)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio3_END (13)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio4_START (14)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_gpio4_END (14)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_adc_START (15)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_adc_END (15)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_qic_dfx_START (16)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_qic_dfx_END (16)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_sec_region_START (17)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_sec_region_END (17)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_crg_START (18)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_crg_END (20)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_hiphyio_START (21)
#define SOC_Hi9030_V200_AO_CFG_AO_SECURE_STA_tz_secure_n_ao_hiphyio_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_dma0_set : 1;
        unsigned int tz_secure_n_peri_cfg_set : 1;
        unsigned int tz_secure_n_peri_i3c0_set : 1;
        unsigned int tz_secure_n_peri_i3c2_set : 1;
        unsigned int tz_secure_n_peri_i2c2_set : 1;
        unsigned int tz_secure_n_peri_i2c4_set : 1;
        unsigned int tz_secure_n_peri_uart0_set : 1;
        unsigned int tz_secure_n_peri_uart2_set : 1;
        unsigned int tz_secure_n_peri_spmi_set : 1;
        unsigned int tz_secure_n_peri_uart_audio_set : 1;
        unsigned int tz_secure_n_peri_onewire0_set : 1;
        unsigned int tz_secure_n_peri_onewire1_set : 1;
        unsigned int tz_secure_n_peri_qic_dfx_set : 1;
        unsigned int tz_secure_n_peri_sec_region_set : 1;
        unsigned int tz_secure_n_peri_crg_set : 3;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_dma0_set_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_dma0_set_END (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_cfg_set_START (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_cfg_set_END (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i3c0_set_START (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i3c0_set_END (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i3c2_set_START (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i3c2_set_END (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i2c2_set_START (4)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i2c2_set_END (4)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i2c4_set_START (5)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_i2c4_set_END (5)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_uart0_set_START (6)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_uart0_set_END (6)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_uart2_set_START (7)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_uart2_set_END (7)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_spmi_set_START (8)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_spmi_set_END (8)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_uart_audio_set_START (9)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_uart_audio_set_END (9)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_onewire0_set_START (10)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_onewire0_set_END (10)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_onewire1_set_START (11)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_onewire1_set_END (11)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_qic_dfx_set_START (12)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_qic_dfx_set_END (12)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_sec_region_set_START (13)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_sec_region_set_END (13)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_crg_set_START (14)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_SET_tz_secure_n_peri_crg_set_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_dma0_clr : 1;
        unsigned int tz_secure_n_peri_cfg_clr : 1;
        unsigned int tz_secure_n_peri_i3c0_clr : 1;
        unsigned int tz_secure_n_peri_i3c2_clr : 1;
        unsigned int tz_secure_n_peri_i2c2_clr : 1;
        unsigned int tz_secure_n_peri_i2c4_clr : 1;
        unsigned int tz_secure_n_peri_uart0_clr : 1;
        unsigned int tz_secure_n_peri_uart2_clr : 1;
        unsigned int tz_secure_n_peri_spmi_clr : 1;
        unsigned int tz_secure_n_peri_uart_audio_clr : 1;
        unsigned int tz_secure_n_peri_onewire0_clr : 1;
        unsigned int tz_secure_n_peri_onewire1_clr : 1;
        unsigned int tz_secure_n_peri_qic_dfx_clr : 1;
        unsigned int tz_secure_n_peri_sec_region_clr : 1;
        unsigned int tz_secure_n_peri_crg_clr : 3;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_dma0_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_dma0_clr_END (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_cfg_clr_START (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_cfg_clr_END (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i3c0_clr_START (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i3c0_clr_END (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i3c2_clr_START (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i3c2_clr_END (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i2c2_clr_START (4)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i2c2_clr_END (4)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i2c4_clr_START (5)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_i2c4_clr_END (5)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_uart0_clr_START (6)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_uart0_clr_END (6)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_uart2_clr_START (7)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_uart2_clr_END (7)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_spmi_clr_START (8)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_spmi_clr_END (8)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_uart_audio_clr_START (9)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_uart_audio_clr_END (9)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_onewire0_clr_START (10)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_onewire0_clr_END (10)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_onewire1_clr_START (11)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_onewire1_clr_END (11)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_qic_dfx_clr_START (12)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_qic_dfx_clr_END (12)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_sec_region_clr_START (13)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_sec_region_clr_END (13)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_crg_clr_START (14)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_CLR_tz_secure_n_peri_crg_clr_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_dma0 : 1;
        unsigned int tz_secure_n_peri_cfg : 1;
        unsigned int tz_secure_n_peri_i3c0 : 1;
        unsigned int tz_secure_n_peri_i3c2 : 1;
        unsigned int tz_secure_n_peri_i2c2 : 1;
        unsigned int tz_secure_n_peri_i2c4 : 1;
        unsigned int tz_secure_n_peri_uart0 : 1;
        unsigned int tz_secure_n_peri_uart2 : 1;
        unsigned int tz_secure_n_peri_spmi : 1;
        unsigned int tz_secure_n_peri_uart_audio : 1;
        unsigned int tz_secure_n_peri_onewire0 : 1;
        unsigned int tz_secure_n_peri_onewire1 : 1;
        unsigned int tz_secure_n_peri_qic_dfx : 1;
        unsigned int tz_secure_n_peri_sec_region : 1;
        unsigned int tz_secure_n_peri_crg : 3;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_dma0_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_dma0_END (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_cfg_START (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_cfg_END (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i3c0_START (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i3c0_END (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i3c2_START (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i3c2_END (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i2c2_START (4)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i2c2_END (4)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i2c4_START (5)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_i2c4_END (5)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_uart0_START (6)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_uart0_END (6)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_uart2_START (7)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_uart2_END (7)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_spmi_START (8)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_spmi_END (8)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_uart_audio_START (9)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_uart_audio_END (9)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_onewire0_START (10)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_onewire0_END (10)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_onewire1_START (11)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_onewire1_END (11)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_qic_dfx_START (12)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_qic_dfx_END (12)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_sec_region_START (13)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_sec_region_END (13)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_crg_START (14)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_STA_tz_secure_n_peri_crg_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_ram_set : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_SET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_SET_tz_secure_n_peri_ram_set_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_SET_tz_secure_n_peri_ram_set_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_ram_clr : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_CLR_tz_secure_n_peri_ram_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_CLR_tz_secure_n_peri_ram_clr_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_ram : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_STA_tz_secure_n_peri_ram_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_RAM_SECURE_STA_tz_secure_n_peri_ram_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc0_set : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_SET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_SET_tz_secure_n_ao_ioc0_set_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_SET_tz_secure_n_ao_ioc0_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc0_clr : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_CLR_tz_secure_n_ao_ioc0_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_CLR_tz_secure_n_ao_ioc0_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_STA_tz_secure_n_ao_ioc0_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC0_SECURE_STA_tz_secure_n_ao_ioc0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc1_set : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_SET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_SET_tz_secure_n_ao_ioc1_set_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_SET_tz_secure_n_ao_ioc1_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc1_clr : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_CLR_tz_secure_n_ao_ioc1_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_CLR_tz_secure_n_ao_ioc1_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_STA_tz_secure_n_ao_ioc1_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC1_SECURE_STA_tz_secure_n_ao_ioc1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc2_set : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_SET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_SET_tz_secure_n_ao_ioc2_set_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_SET_tz_secure_n_ao_ioc2_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc2_clr : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_CLR_tz_secure_n_ao_ioc2_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_CLR_tz_secure_n_ao_ioc2_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_ao_ioc2 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_STA_tz_secure_n_ao_ioc2_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_IOC2_SECURE_STA_tz_secure_n_ao_ioc2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_PERI_LOCK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_PERI_LOCK_lock_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_PERI_LOCK_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_cg_byp : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PCLK_CG_BYP_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PCLK_CG_BYP_clk_cg_byp_START (0)
#define SOC_Hi9030_V200_AO_CFG_PCLK_CG_BYP_clk_cg_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisimc_data_disable : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_USIM_DATA_DISABLE_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_USIM_DATA_DISABLE_hisimc_data_disable_START (0)
#define SOC_Hi9030_V200_AO_CFG_USIM_DATA_DISABLE_hisimc_data_disable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pdc_ao_syspdc_pwrd_req : 1;
        unsigned int cpu_pdc_peri_syspdc_pwrd_req : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_REQ_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_REQ_cpu_pdc_ao_syspdc_pwrd_req_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_REQ_cpu_pdc_ao_syspdc_pwrd_req_END (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_REQ_cpu_pdc_peri_syspdc_pwrd_req_START (1)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_REQ_cpu_pdc_peri_syspdc_pwrd_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_ao_syspdc_pwrd_ack : 1;
        unsigned int pdc_peri_syspdc_pwrd_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_pdc_ao_syspdc_pwrd_ack_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_pdc_ao_syspdc_pwrd_ack_END (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_pdc_peri_syspdc_pwrd_ack_START (1)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_pdc_peri_syspdc_pwrd_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_intr_emc_ao : 1;
        unsigned int qic_intr_emc_peri : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 27;
    } reg;
} SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_qic_intr_emc_ao_START (0)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_qic_intr_emc_ao_END (0)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_qic_intr_emc_peri_START (1)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_qic_intr_emc_peri_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_nopending_qic_ao_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_qic_nopending_qic_ao_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_qic_nopending_qic_ao_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_nopending_qic_peri_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_qic_nopending_qic_peri_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_qic_nopending_qic_peri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_ao_bus_nopending_combo : 1;
        unsigned int qic_peri_bus_nopending_combo : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_qic_ao_bus_nopending_combo_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_qic_ao_bus_nopending_combo_END (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_qic_peri_bus_nopending_combo_START (1)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_qic_peri_bus_nopending_combo_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_qic_ao_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_qic_timeout_st_qic_ao_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_qic_timeout_st_qic_ao_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_qic_peri_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_qic_timeout_st_qic_peri_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_qic_timeout_st_qic_peri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_qic_ao_0_aftmsk : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_qic_timeout_st_qic_ao_0_aftmsk_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_qic_timeout_st_qic_ao_0_aftmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_qic_peri_0_aftmsk : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_qic_timeout_st_qic_peri_0_aftmsk_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_qic_timeout_st_qic_peri_0_aftmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_qic_ao_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_qic_pdm_state_pdm_qic_ao_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_qic_pdm_state_pdm_qic_ao_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_qic_peri_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_qic_pdm_state_pdm_qic_peri_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_qic_pdm_state_pdm_qic_peri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_intr_emc_ao : 1;
        unsigned int w_qic_intr_emc_peri : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 27;
    } reg;
} SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_MWC_F_w_qic_intr_emc_ao_START (0)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_MWC_F_w_qic_intr_emc_ao_END (0)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_MWC_F_w_qic_intr_emc_peri_START (1)
#define SOC_Hi9030_V200_AO_CFG_FIREWALL_STATE_MWC_F_w_qic_intr_emc_peri_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_pdc_ao_syspdc_pwrd_ack : 1;
        unsigned int w_pdc_peri_syspdc_pwrd_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_MWC_F_w_pdc_ao_syspdc_pwrd_ack_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_MWC_F_w_pdc_ao_syspdc_pwrd_ack_END (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_MWC_F_w_pdc_peri_syspdc_pwrd_ack_START (1)
#define SOC_Hi9030_V200_AO_CFG_QIC_SYSPDC_ACK_MWC_F_w_pdc_peri_syspdc_pwrd_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_nopending_qic_ao_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_MWC_F_w_qic_nopending_qic_ao_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_AO_MWC_F_w_qic_nopending_qic_ao_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_nopending_qic_peri_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_MWC_F_w_qic_nopending_qic_peri_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_PERI_MWC_F_w_qic_nopending_qic_peri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_ao_bus_nopending_combo : 1;
        unsigned int w_qic_peri_bus_nopending_combo : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_MWC_F_w_qic_ao_bus_nopending_combo_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_MWC_F_w_qic_ao_bus_nopending_combo_END (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_MWC_F_w_qic_peri_bus_nopending_combo_START (1)
#define SOC_Hi9030_V200_AO_CFG_QIC_NOPENDING_COMB_MWC_F_w_qic_peri_bus_nopending_combo_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_timeout_st_qic_ao_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_MWC_F_w_qic_timeout_st_qic_ao_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_MWC_F_w_qic_timeout_st_qic_ao_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_timeout_st_qic_peri_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_MWC_F_w_qic_timeout_st_qic_peri_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_MWC_F_w_qic_timeout_st_qic_peri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_timeout_st_qic_ao_0_aftmsk : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_MWC_F_w_qic_timeout_st_qic_ao_0_aftmsk_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_AO_AFTMSK_MWC_F_w_qic_timeout_st_qic_ao_0_aftmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_timeout_st_qic_peri_0_aftmsk : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_MWC_F_w_qic_timeout_st_qic_peri_0_aftmsk_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_TIMEOUT_PERI_AFTMSK_MWC_F_w_qic_timeout_st_qic_peri_0_aftmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_pdm_state_pdm_qic_ao_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_MWC_F_w_qic_pdm_state_pdm_qic_ao_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_AO_MWC_F_w_qic_pdm_state_pdm_qic_ao_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int w_qic_pdm_state_pdm_qic_peri_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_MWC_F_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_MWC_F_w_qic_pdm_state_pdm_qic_peri_0_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_PDM_PERI_MWC_F_w_qic_pdm_state_pdm_qic_peri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_qic_req : 2;
        unsigned int cpu_mask_qic_ack : 2;
        unsigned int cpu_mask_qic_intr : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_QIC_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_cpu_mask_qic_req_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_cpu_mask_qic_req_END (1)
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_cpu_mask_qic_ack_START (2)
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_cpu_mask_qic_ack_END (3)
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_cpu_mask_qic_intr_START (4)
#define SOC_Hi9030_V200_AO_CFG_MASK_QIC_cpu_mask_qic_intr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_qic_nopending_ao : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_AO_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_AO_cpu_mask_qic_nopending_ao_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_AO_cpu_mask_qic_nopending_ao_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_qic_nopending_peri : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_PERI_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_PERI_cpu_mask_qic_nopending_peri_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_NOPENDING_PERI_cpu_mask_qic_nopending_peri_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_qic_timeout_ao : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_AO_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_AO_cpu_mask_qic_timeout_ao_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_AO_cpu_mask_qic_timeout_ao_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_qic_timeout_peri : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_PERI_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_PERI_cpu_mask_qic_timeout_peri_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_TIMEOUT_PERI_cpu_mask_qic_timeout_peri_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_qic_pdm_ao : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_PDM_AO_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_AO_cpu_mask_qic_pdm_ao_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_AO_cpu_mask_qic_pdm_ao_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_qic_pdm_peri : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_PDM_PERI_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_PERI_cpu_mask_qic_pdm_peri_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_PDM_PERI_cpu_mask_qic_pdm_peri_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_syspdc_pwrd_req_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_SYSPDC_PWRD_REQ_SEL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_SYSPDC_PWRD_REQ_SEL_cpu_peri_syspdc_pwrd_req_sel_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SYSPDC_PWRD_REQ_SEL_cpu_peri_syspdc_pwrd_req_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_mask_hio_intr : 1;
        unsigned int cpu_mask_i3c_intr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_MASK_INTR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_MASK_INTR_cpu_mask_hio_intr_START (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_INTR_cpu_mask_hio_intr_END (0)
#define SOC_Hi9030_V200_AO_CFG_MASK_INTR_cpu_mask_i3c_intr_START (1)
#define SOC_Hi9030_V200_AO_CFG_MASK_INTR_cpu_mask_i3c_intr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_ao_bus : 1;
        unsigned int qic_timeout_en_peri_bus : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_AO_CFG_TIMEOUT_EN_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_EN_qic_timeout_en_ao_bus_START (0)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_EN_qic_timeout_en_ao_bus_END (0)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_EN_qic_timeout_en_peri_bus_START (1)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_EN_qic_timeout_en_peri_bus_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_ao_bus_msk : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_AO_MSK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_AO_MSK_qic_timeout_st_ao_bus_msk_START (0)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_AO_MSK_qic_timeout_st_ao_bus_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_peri_bus_msk : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_PERI_MSK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_PERI_MSK_qic_timeout_st_peri_bus_msk_START (0)
#define SOC_Hi9030_V200_AO_CFG_TIMEOUT_ST_PERI_MSK_qic_timeout_st_peri_bus_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_qic_req_sel : 2;
        unsigned int cpu_qic_ack_sel : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_AO_CFG_QIC_REQ_ACK_SEL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_QIC_REQ_ACK_SEL_cpu_qic_req_sel_START (0)
#define SOC_Hi9030_V200_AO_CFG_QIC_REQ_ACK_SEL_cpu_qic_req_sel_END (1)
#define SOC_Hi9030_V200_AO_CFG_QIC_REQ_ACK_SEL_cpu_qic_ack_sel_START (2)
#define SOC_Hi9030_V200_AO_CFG_QIC_REQ_ACK_SEL_cpu_qic_ack_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_gpio_mask_en : 21;
        unsigned int intr_crg_mask_en : 5;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_Hi9030_V200_AO_CFG_INTR_GPIO_EN_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_EN_intr_gpio_mask_en_START (0)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_EN_intr_gpio_mask_en_END (20)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_EN_intr_crg_mask_en_START (21)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_EN_intr_crg_mask_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_gpio_mask_dis : 21;
        unsigned int intr_crg_mask_dis : 5;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_Hi9030_V200_AO_CFG_INTR_GPIO_DIS_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_DIS_intr_gpio_mask_dis_START (0)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_DIS_intr_gpio_mask_dis_END (20)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_DIS_intr_crg_mask_dis_START (21)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_DIS_intr_crg_mask_dis_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_gpio_mask : 21;
        unsigned int intr_crg_mask : 5;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_Hi9030_V200_AO_CFG_INTR_GPIO_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_STA_intr_gpio_mask_START (0)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_STA_intr_gpio_mask_END (20)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_STA_intr_crg_mask_START (21)
#define SOC_Hi9030_V200_AO_CFG_INTR_GPIO_STA_intr_crg_mask_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_gpio_all_ini : 21;
        unsigned int intr_crg_all_ini : 5;
        unsigned int intr_hiphy_fatal_ini : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_intr_gpio_all_ini_START (0)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_intr_gpio_all_ini_END (20)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_intr_crg_all_ini_START (21)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_intr_crg_all_ini_END (25)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_intr_hiphy_fatal_ini_START (26)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_INI_intr_hiphy_fatal_ini_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_gpio_all_masked : 21;
        unsigned int intr_crg_all_masked : 5;
        unsigned int intr_hiphy_fatal_masked : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_intr_gpio_all_masked_START (0)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_intr_gpio_all_masked_END (20)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_intr_crg_all_masked_START (21)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_intr_crg_all_masked_END (25)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_intr_hiphy_fatal_masked_START (26)
#define SOC_Hi9030_V200_AO_CFG_INTR_RPT_MASK_intr_hiphy_fatal_masked_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ram_fw_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CFG_RAM_FW_LOCK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_LOCK_ram_fw_lock_START (0)
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_LOCK_ram_fw_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ram_fw : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_Hi9030_V200_AO_CFG_RAM_FW_CFG_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_CFG_ram_fw_START (0)
#define SOC_Hi9030_V200_AO_CFG_RAM_FW_CFG_ram_fw_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_peri_fw_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_LOCK_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_LOCK_apb_peri_fw_lock_START (0)
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_LOCK_apb_peri_fw_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_peri_fw : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_CFG_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_CFG_apb_peri_fw_START (0)
#define SOC_Hi9030_V200_AO_CFG_APB_PERI_FW_CFG_apb_peri_fw_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_sec_cfgdma : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_SEC_CFGDMA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_CFGDMA_ao_sec_cfgdma_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_CFGDMA_ao_sec_cfgdma_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao2peri_cfg_reserve0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVE0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVE0_ao2peri_cfg_reserve0_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVE0_ao2peri_cfg_reserve0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_isp_i2c0_set : 1;
        unsigned int tz_secure_n_peri_isp_i2c1_set : 1;
        unsigned int tz_secure_n_peri_uart1_set : 1;
        unsigned int tz_secure_n_peri_dspi_set : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_isp_i2c0_set_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_isp_i2c0_set_END (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_isp_i2c1_set_START (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_isp_i2c1_set_END (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_uart1_set_START (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_uart1_set_END (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_dspi_set_START (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_SET_tz_secure_n_peri_dspi_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_isp_i2c0_clr : 1;
        unsigned int tz_secure_n_peri_isp_i2c1_clr : 1;
        unsigned int tz_secure_n_peri_uart1_clr : 1;
        unsigned int tz_secure_n_peri_dspi_clr : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_isp_i2c0_clr_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_isp_i2c0_clr_END (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_isp_i2c1_clr_START (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_isp_i2c1_clr_END (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_uart1_clr_START (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_uart1_clr_END (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_dspi_clr_START (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK__CLR_tz_secure_n_peri_dspi_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_peri_isp_i2c0 : 1;
        unsigned int tz_secure_n_peri_isp_i2c1 : 1;
        unsigned int tz_secure_n_peri_uart1 : 1;
        unsigned int tz_secure_n_peri_dspi : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_isp_i2c0_START (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_isp_i2c0_END (0)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_isp_i2c1_START (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_isp_i2c1_END (1)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_uart1_START (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_uart1_END (2)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_dspi_START (3)
#define SOC_Hi9030_V200_AO_CFG_PERI_SECURE_UNLOCK_STA_tz_secure_n_peri_dspi_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_crg_en : 1;
        unsigned int ao_cfg_en : 1;
        unsigned int ao_hiphy_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ao_crg_en_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ao_crg_en_END (0)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ao_cfg_en_START (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ao_cfg_en_END (1)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ao_hiphy_en_START (2)
#define SOC_Hi9030_V200_AO_CFG_AO_SEC_EN_ao_hiphy_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao2peri_cfg_reserve1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVED1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVED1_ao2peri_cfg_reserve1_START (0)
#define SOC_Hi9030_V200_AO_CFG_AO2PERI_CFG_RESERVED1_ao2peri_cfg_reserve1_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
