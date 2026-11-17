#ifndef __SOC_DDR_PHY_INTERFACE_H__
#define __SOC_DDR_PHY_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_PHY_ACCTRL_TRX0_ADDR(base) (base)
#define SOC_DDR_PHY_ACCTRL_TRX1_ADDR(base) ((base) + 0x004UL)
#define SOC_DDR_PHY_ACCTL_BYPASS_ADDR(base) ((base) + 0x008UL)
#define SOC_DDR_PHY_AC_IECTRL0_ADDR(base) ((base) + 0x00CUL)
#define SOC_DDR_PHY_AC_IECTRL1_ADDR(base) ((base) + 0x010UL)
#define SOC_DDR_PHY_AC_RX_SET_ADDR(base) ((base) + 0x014UL)
#define SOC_DDR_PHY_AC_RX_SET1_ADDR(base) ((base) + 0x018UL)
#define SOC_DDR_PHY_AC_IOMODE_ADDR(base) ((base) + 0x01CUL)
#define SOC_DDR_PHY_AC_IOREFCTRL0_ADDR(base) ((base) + 0x020UL)
#define SOC_DDR_PHY_AC_IOREFCTRL1_ADDR(base) ((base) + 0x024UL)
#define SOC_DDR_PHY_AC_IOREFCTRL2_ADDR(base) ((base) + 0x028UL)
#define SOC_DDR_PHY_AC_IOEQCTRL0_ADDR(base) ((base) + 0x02CUL)
#define SOC_DDR_PHY_AC_IOEQCTRL1_ADDR(base) ((base) + 0x030UL)
#define SOC_DDR_PHY_AC_IOEQCTRL2_ADDR(base) ((base) + 0x034UL)
#define SOC_DDR_PHY_AC_IOEQCTRL3_ADDR(base) ((base) + 0x038UL)
#define SOC_DDR_PHY_AC_PECTRL0_ADDR(base) ((base) + 0x03CUL)
#define SOC_DDR_PHY_AC_PECTRL1_ADDR(base) ((base) + 0x040UL)
#define SOC_DDR_PHY_AC_PUPDCTRL_ADDR(base) ((base) + 0x044UL)
#define SOC_DDR_PHY_AC_RONCTRL0_ADDR(base) ((base) + 0x048UL)
#define SOC_DDR_PHY_AC_RONCTRL1_ADDR(base) ((base) + 0x04CUL)
#define SOC_DDR_PHY_AC_ODTCTRL0_ADDR(base) ((base) + 0x050UL)
#define SOC_DDR_PHY_AC_ODTCTRL1_ADDR(base) ((base) + 0x054UL)
#define SOC_DDR_PHY_AC_ODTCTRL2_ADDR(base) ((base) + 0x058UL)
#define SOC_DDR_PHY_AC_ODTCTRL3_ADDR(base) ((base) + 0x05CUL)
#define SOC_DDR_PHY_AC_TESTCTRL0_ADDR(base) ((base) + 0x060UL)
#define SOC_DDR_PHY_AC_TESTCTRL1_ADDR(base) ((base) + 0x064UL)
#define SOC_DDR_PHY_AC_TESTCTRL2_ADDR(base) ((base) + 0x068UL)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_ADDR(base) ((base) + 0x06CUL)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_ADDR(base) ((base) + 0x070UL)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_ADDR(base) ((base) + 0x074UL)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_ADDR(base) ((base) + 0x078UL)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_ADDR(base) ((base) + 0x07CUL)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_ADDR(base) ((base) + 0x080UL)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_ADDR(base) ((base) + 0x084UL)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_ADDR(base) ((base) + 0x094UL)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_ADDR(base) ((base) + 0x098UL)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_ADDR(base) ((base) + 0x09CUL)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_ADDR(base) ((base) + 0x0A0UL)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_ADDR(base) ((base) + 0x0A4UL)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_ADDR(base) ((base) + 0x0A8UL)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_ADDR(base) ((base) + 0x0ACUL)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_ADDR(base) ((base) + 0x0B0UL)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_ADDR(base) ((base) + 0x0B4UL)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_ADDR(base) ((base) + 0x0B8UL)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_ADDR(base) ((base) + 0x0BCUL)
#define SOC_DDR_PHY_AC_DLL_CODE_ADDR(base) ((base) + 0x0C0UL)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_ADDR(base) ((base) + 0x0C4UL)
#define SOC_DDR_PHY_AC_SFIO_CTRL1_ADDR(base) ((base) + 0x0C8UL)
#define SOC_DDR_PHY_AC_BDL_CTRL0_ADDR(base) ((base) + 0x0CCUL)
#define SOC_DDR_PHY_AC_BDL_CTRL1_ADDR(base) ((base) + 0x0D0UL)
#define SOC_DDR_PHY_AC_BDL_CTRL2_ADDR(base) ((base) + 0x0D4UL)
#define SOC_DDR_PHY_AC_BDL_CTRL3_ADDR(base) ((base) + 0x0D8UL)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_ADDR(base) ((base) + 0x0DCUL)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_ADDR(base) ((base) + 0x0E0UL)
#define SOC_DDR_PHY_AC_PHYCLK_GATECTRL_ADDR(base) ((base) + 0x0E4UL)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_ADDR(base) ((base) + 0x0F0UL)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_ADDR(base) ((base) + 0x0F4UL)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_ADDR(base) ((base) + 0x0F8UL)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_ADDR(base) ((base) + 0x0FCUL)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_ADDR(base) ((base) + 0x100UL)
#define SOC_DDR_PHY_AC_PLL_RSV_CTRL_ADDR(base) ((base) + 0x104UL)
#define SOC_DDR_PHY_AC_PLL_DBG_A_ADDR(base) ((base) + 0x108UL)
#define SOC_DDR_PHY_AC_PLL_DBG_B_ADDR(base) ((base) + 0x10CUL)
#define SOC_DDR_PHY_AC_CTRL_1_ADDR(base) ((base) + 0x110UL)
#define SOC_DDR_PHY_AC_REV_REG_0_ADDR(base) ((base) + 0x114UL)
#define SOC_DDR_PHY_AC_REV_REG_OUT_0_ADDR(base) ((base) + 0x118UL)
#define SOC_DDR_PHY_AC_REV_REG_1_ADDR(base) ((base) + 0x11CUL)
#define SOC_DDR_PHY_AC_REV_REG_OUT_1_ADDR(base) ((base) + 0x120UL)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_ADDR(base) ((base) + 0x124UL)
#define SOC_DDR_PHY_AC_REV_REG_2_ADDR(base) ((base) + 0x128UL)
#define SOC_DDR_PHY_AC_REV_REG_OUT_2_ADDR(base) ((base) + 0x12CUL)
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_ADDR(base) ((base) + 0x130UL)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3B3_HSB_ADDR(base) ((base) + 0x134UL)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_ADDR(base) ((base) + 0x138UL)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_ADDR(base) ((base) + 0x13CUL)
#define SOC_DDR_PHY_AC_FAST_PROC_ADDR(base) ((base) + 0x140UL)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_ADDR(base) ((base) + 0x144UL)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_ADDR(base) ((base) + 0x148UL)
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_ADDR(base) ((base) + 0x14CUL)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_ADDR(base) ((base) + 0x150UL)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_ADDR(base) ((base) + 0x154UL)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_ADDR(base) ((base) + 0x158UL)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_ADDR(base) ((base) + 0x15CUL)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_ADDR(base) ((base) + 0x160UL)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_ADDR(base) ((base) + 0x164UL)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_ADDR(base) ((base) + 0x168UL)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_ADDR(base) ((base) + 0x170UL)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_ADDR(base) ((base) + 0x174UL)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_ADDR(base) ((base) + 0x180UL)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_ADDR(base) ((base) + 0x184UL)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_ADDR(base) ((base) + 0x188UL)
#define SOC_DDR_PHY_AC_PLL_DBG_A2_ADDR(base) ((base) + 0x18CUL)
#define SOC_DDR_PHY_AC_PLL_DBG_B2_ADDR(base) ((base) + 0x190UL)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_ADDR(base) ((base) + 0x194UL)
#define SOC_DDR_PHY_AC_IOMODE_EXT_ADDR(base) ((base) + 0x198UL)
#define SOC_DDR_PHY_SSDR_CFG_ADDR(base) ((base) + 0x19CUL)
#define SOC_DDR_PHY_SWIFT_TRK_CFG_ADDR(base) ((base) + 0x1A0UL)
#else
#define SOC_DDR_PHY_ACCTRL_TRX0_ADDR(base) (base)
#define SOC_DDR_PHY_ACCTRL_TRX1_ADDR(base) ((base) + 0x004)
#define SOC_DDR_PHY_ACCTL_BYPASS_ADDR(base) ((base) + 0x008)
#define SOC_DDR_PHY_AC_IECTRL0_ADDR(base) ((base) + 0x00C)
#define SOC_DDR_PHY_AC_IECTRL1_ADDR(base) ((base) + 0x010)
#define SOC_DDR_PHY_AC_RX_SET_ADDR(base) ((base) + 0x014)
#define SOC_DDR_PHY_AC_RX_SET1_ADDR(base) ((base) + 0x018)
#define SOC_DDR_PHY_AC_IOMODE_ADDR(base) ((base) + 0x01C)
#define SOC_DDR_PHY_AC_IOREFCTRL0_ADDR(base) ((base) + 0x020)
#define SOC_DDR_PHY_AC_IOREFCTRL1_ADDR(base) ((base) + 0x024)
#define SOC_DDR_PHY_AC_IOREFCTRL2_ADDR(base) ((base) + 0x028)
#define SOC_DDR_PHY_AC_IOEQCTRL0_ADDR(base) ((base) + 0x02C)
#define SOC_DDR_PHY_AC_IOEQCTRL1_ADDR(base) ((base) + 0x030)
#define SOC_DDR_PHY_AC_IOEQCTRL2_ADDR(base) ((base) + 0x034)
#define SOC_DDR_PHY_AC_IOEQCTRL3_ADDR(base) ((base) + 0x038)
#define SOC_DDR_PHY_AC_PECTRL0_ADDR(base) ((base) + 0x03C)
#define SOC_DDR_PHY_AC_PECTRL1_ADDR(base) ((base) + 0x040)
#define SOC_DDR_PHY_AC_PUPDCTRL_ADDR(base) ((base) + 0x044)
#define SOC_DDR_PHY_AC_RONCTRL0_ADDR(base) ((base) + 0x048)
#define SOC_DDR_PHY_AC_RONCTRL1_ADDR(base) ((base) + 0x04C)
#define SOC_DDR_PHY_AC_ODTCTRL0_ADDR(base) ((base) + 0x050)
#define SOC_DDR_PHY_AC_ODTCTRL1_ADDR(base) ((base) + 0x054)
#define SOC_DDR_PHY_AC_ODTCTRL2_ADDR(base) ((base) + 0x058)
#define SOC_DDR_PHY_AC_ODTCTRL3_ADDR(base) ((base) + 0x05C)
#define SOC_DDR_PHY_AC_TESTCTRL0_ADDR(base) ((base) + 0x060)
#define SOC_DDR_PHY_AC_TESTCTRL1_ADDR(base) ((base) + 0x064)
#define SOC_DDR_PHY_AC_TESTCTRL2_ADDR(base) ((base) + 0x068)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_ADDR(base) ((base) + 0x06C)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_ADDR(base) ((base) + 0x070)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_ADDR(base) ((base) + 0x074)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_ADDR(base) ((base) + 0x078)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_ADDR(base) ((base) + 0x07C)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_ADDR(base) ((base) + 0x080)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_ADDR(base) ((base) + 0x084)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_ADDR(base) ((base) + 0x094)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_ADDR(base) ((base) + 0x098)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_ADDR(base) ((base) + 0x09C)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_ADDR(base) ((base) + 0x0A0)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_ADDR(base) ((base) + 0x0A4)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_ADDR(base) ((base) + 0x0A8)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_ADDR(base) ((base) + 0x0AC)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_ADDR(base) ((base) + 0x0B0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_ADDR(base) ((base) + 0x0B4)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_ADDR(base) ((base) + 0x0B8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_ADDR(base) ((base) + 0x0BC)
#define SOC_DDR_PHY_AC_DLL_CODE_ADDR(base) ((base) + 0x0C0)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_ADDR(base) ((base) + 0x0C4)
#define SOC_DDR_PHY_AC_SFIO_CTRL1_ADDR(base) ((base) + 0x0C8)
#define SOC_DDR_PHY_AC_BDL_CTRL0_ADDR(base) ((base) + 0x0CC)
#define SOC_DDR_PHY_AC_BDL_CTRL1_ADDR(base) ((base) + 0x0D0)
#define SOC_DDR_PHY_AC_BDL_CTRL2_ADDR(base) ((base) + 0x0D4)
#define SOC_DDR_PHY_AC_BDL_CTRL3_ADDR(base) ((base) + 0x0D8)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_ADDR(base) ((base) + 0x0DC)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_ADDR(base) ((base) + 0x0E0)
#define SOC_DDR_PHY_AC_PHYCLK_GATECTRL_ADDR(base) ((base) + 0x0E4)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_ADDR(base) ((base) + 0x0F0)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_ADDR(base) ((base) + 0x0F4)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_ADDR(base) ((base) + 0x0F8)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_ADDR(base) ((base) + 0x0FC)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_ADDR(base) ((base) + 0x100)
#define SOC_DDR_PHY_AC_PLL_RSV_CTRL_ADDR(base) ((base) + 0x104)
#define SOC_DDR_PHY_AC_PLL_DBG_A_ADDR(base) ((base) + 0x108)
#define SOC_DDR_PHY_AC_PLL_DBG_B_ADDR(base) ((base) + 0x10C)
#define SOC_DDR_PHY_AC_CTRL_1_ADDR(base) ((base) + 0x110)
#define SOC_DDR_PHY_AC_REV_REG_0_ADDR(base) ((base) + 0x114)
#define SOC_DDR_PHY_AC_REV_REG_OUT_0_ADDR(base) ((base) + 0x118)
#define SOC_DDR_PHY_AC_REV_REG_1_ADDR(base) ((base) + 0x11C)
#define SOC_DDR_PHY_AC_REV_REG_OUT_1_ADDR(base) ((base) + 0x120)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_ADDR(base) ((base) + 0x124)
#define SOC_DDR_PHY_AC_REV_REG_2_ADDR(base) ((base) + 0x128)
#define SOC_DDR_PHY_AC_REV_REG_OUT_2_ADDR(base) ((base) + 0x12C)
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_ADDR(base) ((base) + 0x130)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3B3_HSB_ADDR(base) ((base) + 0x134)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_ADDR(base) ((base) + 0x138)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_ADDR(base) ((base) + 0x13C)
#define SOC_DDR_PHY_AC_FAST_PROC_ADDR(base) ((base) + 0x140)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_ADDR(base) ((base) + 0x144)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_ADDR(base) ((base) + 0x148)
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_ADDR(base) ((base) + 0x14C)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_ADDR(base) ((base) + 0x150)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_ADDR(base) ((base) + 0x154)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_ADDR(base) ((base) + 0x158)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_ADDR(base) ((base) + 0x15C)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_ADDR(base) ((base) + 0x160)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_ADDR(base) ((base) + 0x164)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_ADDR(base) ((base) + 0x168)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_ADDR(base) ((base) + 0x170)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_ADDR(base) ((base) + 0x174)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_ADDR(base) ((base) + 0x180)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_ADDR(base) ((base) + 0x184)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_ADDR(base) ((base) + 0x188)
#define SOC_DDR_PHY_AC_PLL_DBG_A2_ADDR(base) ((base) + 0x18C)
#define SOC_DDR_PHY_AC_PLL_DBG_B2_ADDR(base) ((base) + 0x190)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_ADDR(base) ((base) + 0x194)
#define SOC_DDR_PHY_AC_IOMODE_EXT_ADDR(base) ((base) + 0x198)
#define SOC_DDR_PHY_SSDR_CFG_ADDR(base) ((base) + 0x19C)
#define SOC_DDR_PHY_SWIFT_TRK_CFG_ADDR(base) ((base) + 0x1A0)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_PHY_DXCTRL_TRX0_ADDR(base) ((base) + 0x200UL)
#define SOC_DDR_PHY_DXCTRL_TRX1_ADDR(base,n) ((base) + 0x204UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DXCTL_BYPASS_ADDR(base,n) ((base) + 0x208UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IECTRL0_ADDR(base,n) ((base) + 0x20CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RX_SET_ADDR(base,n) ((base) + 0x210UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOMODE_ADDR(base,n) ((base) + 0x214UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOREFCTRL0_ADDR(base,n) ((base) + 0x218UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOREFCTRL1_ADDR(base,n) ((base) + 0x21CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOREFCTRL2_ADDR(base,n) ((base) + 0x220UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOEQCTRL0_ADDR(base,n) ((base) + 0x224UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOEQCTRL1_ADDR(base,n) ((base) + 0x228UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOEQCTRL2_ADDR(base,n) ((base) + 0x22cUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOEQCTRL3_ADDR(base,n) ((base) + 0x230UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_PECTRL0_ADDR(base,n) ((base) + 0x234UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_PECTRL1_ADDR(base,n) ((base) + 0x238UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RONCTRL0_ADDR(base,n) ((base) + 0x23CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RONCTRL1_ADDR(base,n) ((base) + 0x240UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_ODTCTRL1_ADDR(base,n) ((base) + 0x244UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_ODTCTRL2_ADDR(base,n) ((base) + 0x248UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TESTCTRL0_ADDR(base,n) ((base) + 0x24CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TESTCTRL1_ADDR(base,n) ((base) + 0x250UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TESTCTRL2_ADDR(base,n) ((base) + 0x254UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOEQCTRL4_ADDR(base,n) ((base) + 0x258UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + 0x25CUL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + 0x260UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + 0x264UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + 0x268UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_ADDR(base,n) ((base) + 0x26CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + 0x27CUL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + 0x280UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + 0x284UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + 0x288UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_ADDR(base,m,n) ((base) + 0x28CUL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_ADDR(base,m,n) ((base) + 0x290UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_ADDR(base,m,n) ((base) + 0x294UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_ADDR(base,m,n) ((base) + 0x298UL + (m) * 0x40UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_ADDR(base,n) ((base) + 0x2DCUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_ADDR(base,n) ((base) + 0x2E0UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_ADDR(base,n) ((base) + 0x2E4UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_TRACK_ERR_ADDR(base,m,n) ((base) + 0x2E8UL + (m) * 0x4UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_ADDR(base,m,n) ((base) + 0x2F0UL + (m) * 0x8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_ADDR(base,m,n) ((base) + 0x2F4UL + (m) * 0x8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_ADDR(base,n) ((base) + 0x400UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_OEBDL_CTL1_ADDR(base,n) ((base) + 0x404UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQS_DCC_ADDR(base,n) ((base) + 0x408UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_ADDR(base,n) ((base) + 0x40CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_GATE_ERR_ADDR(base,n) ((base) + 0x410UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_ADDR(base,n) ((base) + 0x414UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_ADDR(base,n) ((base) + 0x418UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_ADDR(base,n) ((base) + 0x41CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_ADDR(base,n) ((base) + 0x420UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_ADDR(base,n) ((base) + 0x424UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_ADDR(base,n) ((base) + 0x428UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_ADDR(base,m,n) ((base) + 0x430UL + (m) * 0x8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DM_MARGIN_EXT_ADDR(base,m,n) ((base) + 0x434UL + (m) * 0x8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_ADDR(base,n) ((base) + 0x440UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_ADDR(base,n) ((base) + 0x444UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_ADDR(base,n) ((base) + 0x448UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_HSB_ADDR(base,n) ((base) + 0x44CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_ADDR(base,n) ((base) + 0x450UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_ADDR(base,n) ((base) + 0x454UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_ADDR(base,n) ((base) + 0x458UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_ADDR(base,n) ((base) + 0x45CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_ADDR(base,n) ((base) + 0x460UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_ADDR(base,n) ((base) + 0x464UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_ADDR(base,n) ((base) + 0x468UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_ADDR(base,n) ((base) + 0x46CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_ADDR(base,n) ((base) + 0x470UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_ADDR(base,n) ((base) + 0x474UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_ADDR(base,n) ((base) + 0x478UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_FAST_PROC_ADDR(base) ((base) + 0x484UL)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_ADDR(base,n) ((base) + 0x488UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_ADDR(base,n) ((base) + 0x48CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_ADDR(base,n) ((base) + 0x490UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_ADDR(base,n) ((base) + 0x494UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_ADDR(base,n) ((base) + 0x498UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_ADDR(base,n) ((base) + 0x49CUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_ADDR(base,n) ((base) + 0x4A0UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RG_CLKBUFF_EN1_ADDR(base,n) ((base) + 0x4A8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_ADDR(base,n) ((base) + 0x4ACUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_ADDR(base,n) ((base) + 0x4B0UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG0_ADDR(base,n) ((base) + 0x4B4UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG1_ADDR(base,n) ((base) + 0x4B8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_ADDR(base,n) ((base) + 0x4C0UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4C4UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4C8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4CCUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4D0UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4D4UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_ADDR(base,n) ((base) + 0x4D8UL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_ADDR(base,n) ((base) + 0x4DCUL + (n) * 0x100UL)
#define SOC_DDR_PHY_DX_IOMODE_EXT_ADDR(base,n) ((base) + 0x4E0UL + (n) * 0x100UL)
#else
#define SOC_DDR_PHY_DXCTRL_TRX0_ADDR(base) ((base) + 0x200)
#define SOC_DDR_PHY_DXCTRL_TRX1_ADDR(base,n) ((base) + 0x204 + (n) * 0x100)
#define SOC_DDR_PHY_DXCTL_BYPASS_ADDR(base,n) ((base) + 0x208 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IECTRL0_ADDR(base,n) ((base) + 0x20C + (n) * 0x100)
#define SOC_DDR_PHY_DX_RX_SET_ADDR(base,n) ((base) + 0x210 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOMODE_ADDR(base,n) ((base) + 0x214 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOREFCTRL0_ADDR(base,n) ((base) + 0x218 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOREFCTRL1_ADDR(base,n) ((base) + 0x21C + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOREFCTRL2_ADDR(base,n) ((base) + 0x220 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOEQCTRL0_ADDR(base,n) ((base) + 0x224 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOEQCTRL1_ADDR(base,n) ((base) + 0x228 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOEQCTRL2_ADDR(base,n) ((base) + 0x22c + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOEQCTRL3_ADDR(base,n) ((base) + 0x230 + (n) * 0x100)
#define SOC_DDR_PHY_DX_PECTRL0_ADDR(base,n) ((base) + 0x234 + (n) * 0x100)
#define SOC_DDR_PHY_DX_PECTRL1_ADDR(base,n) ((base) + 0x238 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RONCTRL0_ADDR(base,n) ((base) + 0x23C + (n) * 0x100)
#define SOC_DDR_PHY_DX_RONCTRL1_ADDR(base,n) ((base) + 0x240 + (n) * 0x100)
#define SOC_DDR_PHY_DX_ODTCTRL1_ADDR(base,n) ((base) + 0x244 + (n) * 0x100)
#define SOC_DDR_PHY_DX_ODTCTRL2_ADDR(base,n) ((base) + 0x248 + (n) * 0x100)
#define SOC_DDR_PHY_DX_TESTCTRL0_ADDR(base,n) ((base) + 0x24C + (n) * 0x100)
#define SOC_DDR_PHY_DX_TESTCTRL1_ADDR(base,n) ((base) + 0x250 + (n) * 0x100)
#define SOC_DDR_PHY_DX_TESTCTRL2_ADDR(base,n) ((base) + 0x254 + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOEQCTRL4_ADDR(base,n) ((base) + 0x258 + (n) * 0x100)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + 0x25C + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + 0x260 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + 0x264 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + 0x268 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_ADDR(base,n) ((base) + 0x26C + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + 0x27C + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + 0x280 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + 0x284 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + 0x288 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_ADDR(base,m,n) ((base) + 0x28C + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_ADDR(base,m,n) ((base) + 0x290 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_ADDR(base,m,n) ((base) + 0x294 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_ADDR(base,m,n) ((base) + 0x298 + (m) * 0x40 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_ADDR(base,n) ((base) + 0x2DC + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_ADDR(base,n) ((base) + 0x2E0 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_ADDR(base,n) ((base) + 0x2E4 + (n) * 0x100)
#define SOC_DDR_PHY_DX_TRACK_ERR_ADDR(base,m,n) ((base) + 0x2E8 + (m) * 0x4 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_ADDR(base,m,n) ((base) + 0x2F0 + (m) * 0x8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_ADDR(base,m,n) ((base) + 0x2F4 + (m) * 0x8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_ADDR(base,n) ((base) + 0x400 + (n) * 0x100)
#define SOC_DDR_PHY_DX_OEBDL_CTL1_ADDR(base,n) ((base) + 0x404 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQS_DCC_ADDR(base,n) ((base) + 0x408 + (n) * 0x100)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_ADDR(base,n) ((base) + 0x40C + (n) * 0x100)
#define SOC_DDR_PHY_DX_GATE_ERR_ADDR(base,n) ((base) + 0x410 + (n) * 0x100)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_ADDR(base,n) ((base) + 0x414 + (n) * 0x100)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_ADDR(base,n) ((base) + 0x418 + (n) * 0x100)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_ADDR(base,n) ((base) + 0x41C + (n) * 0x100)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_ADDR(base,n) ((base) + 0x420 + (n) * 0x100)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_ADDR(base,n) ((base) + 0x424 + (n) * 0x100)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_ADDR(base,n) ((base) + 0x428 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_ADDR(base,m,n) ((base) + 0x430 + (m) * 0x8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DM_MARGIN_EXT_ADDR(base,m,n) ((base) + 0x434 + (m) * 0x8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_ADDR(base,n) ((base) + 0x440 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_ADDR(base,n) ((base) + 0x444 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_ADDR(base,n) ((base) + 0x448 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_HSB_ADDR(base,n) ((base) + 0x44C + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_ADDR(base,n) ((base) + 0x450 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_ADDR(base,n) ((base) + 0x454 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_ADDR(base,n) ((base) + 0x458 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_ADDR(base,n) ((base) + 0x45C + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_ADDR(base,n) ((base) + 0x460 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_ADDR(base,n) ((base) + 0x464 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_ADDR(base,n) ((base) + 0x468 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_ADDR(base,n) ((base) + 0x46C + (n) * 0x100)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_ADDR(base,n) ((base) + 0x470 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_ADDR(base,n) ((base) + 0x474 + (n) * 0x100)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_ADDR(base,n) ((base) + 0x478 + (n) * 0x100)
#define SOC_DDR_PHY_DX_FAST_PROC_ADDR(base) ((base) + 0x484)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_ADDR(base,n) ((base) + 0x488 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_ADDR(base,n) ((base) + 0x48C + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_ADDR(base,n) ((base) + 0x490 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_ADDR(base,n) ((base) + 0x494 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_ADDR(base,n) ((base) + 0x498 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_ADDR(base,n) ((base) + 0x49C + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_ADDR(base,n) ((base) + 0x4A0 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RG_CLKBUFF_EN1_ADDR(base,n) ((base) + 0x4A8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_ADDR(base,n) ((base) + 0x4AC + (n) * 0x100)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_ADDR(base,n) ((base) + 0x4B0 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG0_ADDR(base,n) ((base) + 0x4B4 + (n) * 0x100)
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG1_ADDR(base,n) ((base) + 0x4B8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_ADDR(base,n) ((base) + 0x4C0 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4C4 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4C8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4CC + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4D0 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_ADDR(base,n) ((base) + 0x4D4 + (n) * 0x100)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_ADDR(base,n) ((base) + 0x4D8 + (n) * 0x100)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_ADDR(base,n) ((base) + 0x4DC + (n) * 0x100)
#define SOC_DDR_PHY_DX_IOMODE_EXT_ADDR(base,n) ((base) + 0x4E0 + (n) * 0x100)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_PTX : 2;
        unsigned int ac_dqs_offset : 3;
        unsigned int ac_dq_offset : 3;
        unsigned int reserved_0 : 1;
        unsigned int ac_dummy_offset : 3;
        unsigned int lp_ckoen_disable_phy : 1;
        unsigned int gated_txbdl_on_dclk : 1;
        unsigned int cfg_tx_gcken : 1;
        unsigned int lp_csoen_disable_phy : 1;
        unsigned int AC_IO_CK_VREF_EN : 1;
        unsigned int acctl_lp5ck_en : 1;
        unsigned int lpbk_dqs_wck_sel : 1;
        unsigned int cs_cke_swap_en : 1;
        unsigned int AC_RG_TX_CKE_EN : 2;
        unsigned int acctl_rx_cke_en : 2;
        unsigned int ac_lpbk_ls : 3;
        unsigned int AC_IO_ADDR_VREF_EN : 1;
        unsigned int AC_IO_CS_VREF_EN : 1;
        unsigned int reg_ckdata_tick_sel : 1;
        unsigned int refsel_table_sel_ac : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_PHY_ACCTRL_TRX0_UNION;
#endif
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_RG_PTX_START (0)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_RG_PTX_END (1)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_dqs_offset_START (2)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_dqs_offset_END (4)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_dq_offset_START (5)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_dq_offset_END (7)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_dummy_offset_START (9)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_dummy_offset_END (11)
#define SOC_DDR_PHY_ACCTRL_TRX0_lp_ckoen_disable_phy_START (12)
#define SOC_DDR_PHY_ACCTRL_TRX0_lp_ckoen_disable_phy_END (12)
#define SOC_DDR_PHY_ACCTRL_TRX0_gated_txbdl_on_dclk_START (13)
#define SOC_DDR_PHY_ACCTRL_TRX0_gated_txbdl_on_dclk_END (13)
#define SOC_DDR_PHY_ACCTRL_TRX0_cfg_tx_gcken_START (14)
#define SOC_DDR_PHY_ACCTRL_TRX0_cfg_tx_gcken_END (14)
#define SOC_DDR_PHY_ACCTRL_TRX0_lp_csoen_disable_phy_START (15)
#define SOC_DDR_PHY_ACCTRL_TRX0_lp_csoen_disable_phy_END (15)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_IO_CK_VREF_EN_START (16)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_IO_CK_VREF_EN_END (16)
#define SOC_DDR_PHY_ACCTRL_TRX0_acctl_lp5ck_en_START (17)
#define SOC_DDR_PHY_ACCTRL_TRX0_acctl_lp5ck_en_END (17)
#define SOC_DDR_PHY_ACCTRL_TRX0_lpbk_dqs_wck_sel_START (18)
#define SOC_DDR_PHY_ACCTRL_TRX0_lpbk_dqs_wck_sel_END (18)
#define SOC_DDR_PHY_ACCTRL_TRX0_cs_cke_swap_en_START (19)
#define SOC_DDR_PHY_ACCTRL_TRX0_cs_cke_swap_en_END (19)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_RG_TX_CKE_EN_START (20)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_RG_TX_CKE_EN_END (21)
#define SOC_DDR_PHY_ACCTRL_TRX0_acctl_rx_cke_en_START (22)
#define SOC_DDR_PHY_ACCTRL_TRX0_acctl_rx_cke_en_END (23)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_lpbk_ls_START (24)
#define SOC_DDR_PHY_ACCTRL_TRX0_ac_lpbk_ls_END (26)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_IO_ADDR_VREF_EN_START (27)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_IO_ADDR_VREF_EN_END (27)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_IO_CS_VREF_EN_START (28)
#define SOC_DDR_PHY_ACCTRL_TRX0_AC_IO_CS_VREF_EN_END (28)
#define SOC_DDR_PHY_ACCTRL_TRX0_reg_ckdata_tick_sel_START (29)
#define SOC_DDR_PHY_ACCTRL_TRX0_reg_ckdata_tick_sel_END (29)
#define SOC_DDR_PHY_ACCTRL_TRX0_refsel_table_sel_ac_START (30)
#define SOC_DDR_PHY_ACCTRL_TRX0_refsel_table_sel_ac_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acctl_rx_en : 9;
        unsigned int acctl_ck_en : 1;
        unsigned int reserved_0 : 4;
        unsigned int acctl_reset_o : 1;
        unsigned int reserved_1 : 1;
        unsigned int AC_RG_TX_EN : 9;
        unsigned int reserved_2 : 4;
        unsigned int cfg_rxfifo_rstn : 1;
        unsigned int reserved_3 : 1;
        unsigned int cfg_dev_mode : 1;
    } reg;
} SOC_DDR_PHY_ACCTRL_TRX1_UNION;
#endif
#define SOC_DDR_PHY_ACCTRL_TRX1_acctl_rx_en_START (0)
#define SOC_DDR_PHY_ACCTRL_TRX1_acctl_rx_en_END (8)
#define SOC_DDR_PHY_ACCTRL_TRX1_acctl_ck_en_START (9)
#define SOC_DDR_PHY_ACCTRL_TRX1_acctl_ck_en_END (9)
#define SOC_DDR_PHY_ACCTRL_TRX1_acctl_reset_o_START (14)
#define SOC_DDR_PHY_ACCTRL_TRX1_acctl_reset_o_END (14)
#define SOC_DDR_PHY_ACCTRL_TRX1_AC_RG_TX_EN_START (16)
#define SOC_DDR_PHY_ACCTRL_TRX1_AC_RG_TX_EN_END (24)
#define SOC_DDR_PHY_ACCTRL_TRX1_cfg_rxfifo_rstn_START (29)
#define SOC_DDR_PHY_ACCTRL_TRX1_cfg_rxfifo_rstn_END (29)
#define SOC_DDR_PHY_ACCTRL_TRX1_cfg_dev_mode_START (31)
#define SOC_DDR_PHY_ACCTRL_TRX1_cfg_dev_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acctl_rx_bypass_en : 8;
        unsigned int acctl_rxclk_inv : 1;
        unsigned int cfg_ofst_k_gcken : 1;
        unsigned int cfg_ofst_k_bypass : 1;
        unsigned int reserved_0 : 14;
        unsigned int acctl_txclk_inv : 1;
        unsigned int reserved_1 : 2;
        unsigned int acctl_rx_cke_bypass_en : 2;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_DDR_PHY_ACCTL_BYPASS_UNION;
#endif
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_rx_bypass_en_START (0)
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_rx_bypass_en_END (7)
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_rxclk_inv_START (8)
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_rxclk_inv_END (8)
#define SOC_DDR_PHY_ACCTL_BYPASS_cfg_ofst_k_gcken_START (9)
#define SOC_DDR_PHY_ACCTL_BYPASS_cfg_ofst_k_gcken_END (9)
#define SOC_DDR_PHY_ACCTL_BYPASS_cfg_ofst_k_bypass_START (10)
#define SOC_DDR_PHY_ACCTL_BYPASS_cfg_ofst_k_bypass_END (10)
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_txclk_inv_START (25)
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_txclk_inv_END (25)
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_rx_cke_bypass_en_START (28)
#define SOC_DDR_PHY_ACCTL_BYPASS_acctl_rx_cke_bypass_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_BIAS_EN : 11;
        unsigned int reg_CKE_RG_PGX : 6;
        unsigned int reg_CKE_RG_NGX : 6;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_PHY_AC_IECTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_IECTRL0_AC_BIAS_EN_START (0)
#define SOC_DDR_PHY_AC_IECTRL0_AC_BIAS_EN_END (10)
#define SOC_DDR_PHY_AC_IECTRL0_reg_CKE_RG_PGX_START (11)
#define SOC_DDR_PHY_AC_IECTRL0_reg_CKE_RG_PGX_END (16)
#define SOC_DDR_PHY_AC_IECTRL0_reg_CKE_RG_NGX_START (17)
#define SOC_DDR_PHY_AC_IECTRL0_reg_CKE_RG_NGX_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_CK_RG_EQ_RP : 6;
        unsigned int reserved_0 : 2;
        unsigned int reg_CK_RG_EQ_C : 5;
        unsigned int reserved_1 : 3;
        unsigned int AC_IE : 11;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_DDR_PHY_AC_IECTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_IECTRL1_reg_CK_RG_EQ_RP_START (0)
#define SOC_DDR_PHY_AC_IECTRL1_reg_CK_RG_EQ_RP_END (5)
#define SOC_DDR_PHY_AC_IECTRL1_reg_CK_RG_EQ_C_START (8)
#define SOC_DDR_PHY_AC_IECTRL1_reg_CK_RG_EQ_C_END (12)
#define SOC_DDR_PHY_AC_IECTRL1_AC_IE_START (16)
#define SOC_DDR_PHY_AC_IECTRL1_AC_IE_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_SE_CLKD_4_7 : 4;
        unsigned int reserved_0 : 4;
        unsigned int AC_SE_CLKD : 4;
        unsigned int reserved_1 : 3;
        unsigned int reg_AC_DA_SIG_SW : 1;
        unsigned int reg_AC_RG_PRESET_DQS : 2;
        unsigned int reg_AC_DA_OE_OPTION : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_DDR_PHY_AC_RX_SET_UNION;
#endif
#define SOC_DDR_PHY_AC_RX_SET_AC_SE_CLKD_4_7_START (0)
#define SOC_DDR_PHY_AC_RX_SET_AC_SE_CLKD_4_7_END (3)
#define SOC_DDR_PHY_AC_RX_SET_AC_SE_CLKD_START (8)
#define SOC_DDR_PHY_AC_RX_SET_AC_SE_CLKD_END (11)
#define SOC_DDR_PHY_AC_RX_SET_reg_AC_DA_SIG_SW_START (15)
#define SOC_DDR_PHY_AC_RX_SET_reg_AC_DA_SIG_SW_END (15)
#define SOC_DDR_PHY_AC_RX_SET_reg_AC_RG_PRESET_DQS_START (16)
#define SOC_DDR_PHY_AC_RX_SET_reg_AC_RG_PRESET_DQS_END (17)
#define SOC_DDR_PHY_AC_RX_SET_reg_AC_DA_OE_OPTION_START (18)
#define SOC_DDR_PHY_AC_RX_SET_reg_AC_DA_OE_OPTION_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RT_UPDNCOUNT : 1;
        unsigned int reserved_0 : 15;
        unsigned int AC_RX_PRESET_DQ : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_DDR_PHY_AC_RX_SET1_UNION;
#endif
#define SOC_DDR_PHY_AC_RX_SET1_AC_RT_UPDNCOUNT_START (0)
#define SOC_DDR_PHY_AC_RX_SET1_AC_RT_UPDNCOUNT_END (0)
#define SOC_DDR_PHY_AC_RX_SET1_AC_RX_PRESET_DQ_START (16)
#define SOC_DDR_PHY_AC_RX_SET1_AC_RX_PRESET_DQ_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_MODE0 : 2;
        unsigned int AC_IO_MODE1 : 2;
        unsigned int AC_IO_MODE2 : 2;
        unsigned int AC_IO_MODE3 : 2;
        unsigned int AC_IO_MODE4 : 2;
        unsigned int AC_IO_MODE5 : 2;
        unsigned int AC_IO_MODE6 : 2;
        unsigned int AC_IO_MODE7 : 2;
        unsigned int AC_IO_MODE8 : 2;
        unsigned int AC_IO_MODE9 : 2;
        unsigned int reserved_0 : 4;
        unsigned int AC_IO_RXMODE : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_TXMODE : 2;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_DDR_PHY_AC_IOMODE_UNION;
#endif
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE0_START (0)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE0_END (1)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE1_START (2)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE1_END (3)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE2_START (4)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE2_END (5)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE3_START (6)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE3_END (7)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE4_START (8)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE4_END (9)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE5_START (10)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE5_END (11)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE6_START (12)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE6_END (13)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE7_START (14)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE7_END (15)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE8_START (16)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE8_END (17)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE9_START (18)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_MODE9_END (19)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_RXMODE_START (24)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_RXMODE_END (26)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_TXMODE_START (28)
#define SOC_DDR_PHY_AC_IOMODE_AC_IO_TXMODE_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_REFRANGE0 : 4;
        unsigned int AC_IO_REFRANGE1 : 4;
        unsigned int AC_IO_REFRANGE2 : 4;
        unsigned int AC_IO_REFRANGE3 : 4;
        unsigned int AC_IO_REFRANGE4 : 4;
        unsigned int AC_IO_REFRANGE5 : 4;
        unsigned int AC_IO_REFRANGE6 : 4;
        unsigned int AC_IO_REFRANGE7 : 4;
    } reg;
} SOC_DDR_PHY_AC_IOREFCTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE0_START (0)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE0_END (3)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE1_START (4)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE1_END (7)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE2_START (8)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE2_END (11)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE3_START (12)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE3_END (15)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE4_START (16)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE4_END (19)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE5_START (20)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE5_END (23)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE6_START (24)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE6_END (27)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE7_START (28)
#define SOC_DDR_PHY_AC_IOREFCTRL0_AC_IO_REFRANGE7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_REFRANGE8 : 4;
        unsigned int AC_IO_REFRANGE9 : 4;
        unsigned int AC_IO_REFRANGE10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_PHY_AC_IOREFCTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_IOREFCTRL1_AC_IO_REFRANGE8_START (0)
#define SOC_DDR_PHY_AC_IOREFCTRL1_AC_IO_REFRANGE8_END (3)
#define SOC_DDR_PHY_AC_IOREFCTRL1_AC_IO_REFRANGE9_START (4)
#define SOC_DDR_PHY_AC_IOREFCTRL1_AC_IO_REFRANGE9_END (7)
#define SOC_DDR_PHY_AC_IOREFCTRL1_AC_IO_REFRANGE10_START (8)
#define SOC_DDR_PHY_AC_IOREFCTRL1_AC_IO_REFRANGE10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_REFSEL0 : 2;
        unsigned int AC_IO_REFSEL1 : 2;
        unsigned int AC_IO_REFSEL2 : 2;
        unsigned int AC_IO_REFSEL3 : 2;
        unsigned int AC_IO_REFSEL4 : 2;
        unsigned int AC_IO_REFSEL5 : 2;
        unsigned int AC_IO_REFSEL6 : 2;
        unsigned int AC_IO_REFSEL7 : 2;
        unsigned int AC_IO_REFSEL8 : 2;
        unsigned int AC_IO_REFSEL9 : 2;
        unsigned int AC_IO_REFSEL10 : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_DDR_PHY_AC_IOREFCTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL0_START (0)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL0_END (1)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL1_START (2)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL1_END (3)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL2_START (4)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL2_END (5)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL3_START (6)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL3_END (7)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL4_START (8)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL4_END (9)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL5_START (10)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL5_END (11)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL6_START (12)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL6_END (13)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL7_START (14)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL7_END (15)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL8_START (16)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL8_END (17)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL9_START (18)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL9_END (19)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL10_START (20)
#define SOC_DDR_PHY_AC_IOREFCTRL2_AC_IO_REFSEL10_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_EQ_C0 : 5;
        unsigned int AC_RG_D2S_CUR0 : 3;
        unsigned int AC_IO_EQ_C1 : 5;
        unsigned int AC_RG_D2S_CUR1 : 3;
        unsigned int AC_IO_EQ_C2 : 5;
        unsigned int AC_RG_D2S_CUR2 : 3;
        unsigned int AC_IO_EQ_C3 : 5;
        unsigned int AC_RG_D2S_CUR3 : 3;
    } reg;
} SOC_DDR_PHY_AC_IOEQCTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C0_START (0)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C0_END (4)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR0_START (5)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR0_END (7)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C1_START (8)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C1_END (12)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR1_START (13)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR1_END (15)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C2_START (16)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C2_END (20)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR2_START (21)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR2_END (23)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C3_START (24)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_IO_EQ_C3_END (28)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR3_START (29)
#define SOC_DDR_PHY_AC_IOEQCTRL0_AC_RG_D2S_CUR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_EQ_C4 : 5;
        unsigned int AC_RG_D2S_CUR4 : 3;
        unsigned int AC_IO_EQ_C5 : 5;
        unsigned int AC_RG_D2S_CUR5 : 3;
        unsigned int AC_IO_EQ_C6 : 5;
        unsigned int AC_RG_D2S_CUR6 : 3;
        unsigned int AC_IO_EQ_C7 : 5;
        unsigned int AC_RG_D2S_CUR7 : 3;
    } reg;
} SOC_DDR_PHY_AC_IOEQCTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C4_START (0)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C4_END (4)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR4_START (5)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR4_END (7)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C5_START (8)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C5_END (12)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR5_START (13)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR5_END (15)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C6_START (16)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C6_END (20)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR6_START (21)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR6_END (23)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C7_START (24)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_IO_EQ_C7_END (28)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR7_START (29)
#define SOC_DDR_PHY_AC_IOEQCTRL1_AC_RG_D2S_CUR7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_EQ_RP0_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP0 : 1;
        unsigned int AC_RG_D2SBIAS_BYP0 : 1;
        unsigned int AC_RG_VREF_CTRL0 : 1;
        unsigned int AC_IO_EQ_RP1_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP1 : 1;
        unsigned int AC_RG_D2SBIAS_BYP1 : 1;
        unsigned int AC_RG_VREF_CTRL1 : 1;
        unsigned int AC_IO_EQ_RP2_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP2 : 1;
        unsigned int AC_RG_D2SBIAS_BYP2 : 1;
        unsigned int AC_RG_VREF_CTRL2 : 1;
        unsigned int AC_IO_EQ_RP3_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP3 : 1;
        unsigned int AC_RG_D2SBIAS_BYP3 : 1;
        unsigned int AC_RG_VREF_CTRL3 : 1;
    } reg;
} SOC_DDR_PHY_AC_IOEQCTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP0_0_START (0)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP0_0_END (4)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP0_START (5)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP0_END (5)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP0_START (6)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP0_END (6)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL0_START (7)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL0_END (7)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP1_0_START (8)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP1_0_END (12)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP1_START (13)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP1_END (13)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP1_START (14)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP1_END (14)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL1_START (15)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL1_END (15)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP2_0_START (16)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP2_0_END (20)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP2_START (21)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP2_END (21)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP2_START (22)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP2_END (22)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL2_START (23)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL2_END (23)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP3_0_START (24)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_IO_EQ_RP3_0_END (28)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP3_START (29)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_CTLEBIASEN_BYP3_END (29)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP3_START (30)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_D2SBIAS_BYP3_END (30)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL3_START (31)
#define SOC_DDR_PHY_AC_IOEQCTRL2_AC_RG_VREF_CTRL3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_EQ_RP4_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP4 : 1;
        unsigned int AC_RG_D2SBIAS_BYP4 : 1;
        unsigned int AC_RG_VREF_CTRL4 : 1;
        unsigned int AC_IO_EQ_RP5_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP5 : 1;
        unsigned int AC_RG_D2SBIAS_BYP5 : 1;
        unsigned int AC_RG_VREF_CTRL5 : 1;
        unsigned int AC_IO_EQ_RP6_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP6 : 1;
        unsigned int AC_RG_D2SBIAS_BYP6 : 1;
        unsigned int AC_RG_VREF_CTRL6 : 1;
        unsigned int AC_IO_EQ_RP7_0 : 5;
        unsigned int AC_RG_CTLEBIASEN_BYP7 : 1;
        unsigned int AC_RG_D2SBIAS_BYP7 : 1;
        unsigned int AC_RG_VREF_CTRL7 : 1;
    } reg;
} SOC_DDR_PHY_AC_IOEQCTRL3_UNION;
#endif
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP4_0_START (0)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP4_0_END (4)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP4_START (5)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP4_END (5)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP4_START (6)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP4_END (6)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL4_START (7)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL4_END (7)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP5_0_START (8)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP5_0_END (12)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP5_START (13)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP5_END (13)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP5_START (14)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP5_END (14)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL5_START (15)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL5_END (15)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP6_0_START (16)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP6_0_END (20)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP6_START (21)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP6_END (21)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP6_START (22)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP6_END (22)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL6_START (23)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL6_END (23)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP7_0_START (24)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_IO_EQ_RP7_0_END (28)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP7_START (29)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_CTLEBIASEN_BYP7_END (29)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP7_START (30)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_D2SBIAS_BYP7_END (30)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL7_START (31)
#define SOC_DDR_PHY_AC_IOEQCTRL3_AC_RG_VREF_CTRL7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_PE_C0 : 1;
        unsigned int reserved_0 : 2;
        unsigned int AC_IO_PRE_EN0 : 1;
        unsigned int AC_IO_PE_C1 : 1;
        unsigned int reserved_1 : 2;
        unsigned int AC_IO_PRE_EN1 : 1;
        unsigned int AC_IO_PE_C2 : 1;
        unsigned int reserved_2 : 2;
        unsigned int AC_IO_PRE_EN2 : 1;
        unsigned int AC_IO_PE_C3 : 1;
        unsigned int reserved_3 : 2;
        unsigned int AC_IO_PRE_EN3 : 1;
        unsigned int AC_IO_PE_C4 : 1;
        unsigned int reserved_4 : 2;
        unsigned int AC_IO_PRE_EN4 : 1;
        unsigned int AC_IO_PE_C5 : 1;
        unsigned int reserved_5 : 2;
        unsigned int AC_IO_PRE_EN5 : 1;
        unsigned int AC_IO_PE_C6 : 1;
        unsigned int reserved_6 : 2;
        unsigned int AC_IO_PRE_EN6 : 1;
        unsigned int AC_IO_PE_C7 : 1;
        unsigned int reserved_7 : 2;
        unsigned int AC_IO_PRE_EN7 : 1;
    } reg;
} SOC_DDR_PHY_AC_PECTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C0_START (0)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C0_END (0)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN0_START (3)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN0_END (3)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C1_START (4)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C1_END (4)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN1_START (7)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN1_END (7)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C2_START (8)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C2_END (8)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN2_START (11)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN2_END (11)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C3_START (12)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C3_END (12)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN3_START (15)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN3_END (15)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C4_START (16)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C4_END (16)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN4_START (19)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN4_END (19)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C5_START (20)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C5_END (20)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN5_START (23)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN5_END (23)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C6_START (24)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C6_END (24)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN6_START (27)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN6_END (27)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C7_START (28)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PE_C7_END (28)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN7_START (31)
#define SOC_DDR_PHY_AC_PECTRL0_AC_IO_PRE_EN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_PE_C8 : 1;
        unsigned int reserved_0 : 2;
        unsigned int AC_IO_PRE_EN8 : 1;
        unsigned int AC_IO_PE_C9 : 1;
        unsigned int reserved_1 : 3;
        unsigned int AC_IO_PE_C10 : 1;
        unsigned int reserved_2 : 3;
        unsigned int AC_RG_VOS_STEP_SEL0 : 1;
        unsigned int AC_RG_VOS_STEP_SEL1 : 1;
        unsigned int AC_RG_VOS_STEP_SEL2 : 1;
        unsigned int AC_RG_VOS_STEP_SEL3 : 1;
        unsigned int AC_RG_VOS_STEP_SEL4 : 1;
        unsigned int AC_RG_VOS_STEP_SEL5 : 1;
        unsigned int AC_RG_VOS_STEP_SEL6 : 1;
        unsigned int AC_RG_VOS_STEP_SEL7 : 1;
        unsigned int AC_IO_PRE_EN8_1 : 1;
        unsigned int reserved_3 : 2;
        unsigned int AC_IO_PUPDEN_CK : 1;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_DDR_PHY_AC_PECTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PE_C8_START (0)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PE_C8_END (0)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PRE_EN8_START (3)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PRE_EN8_END (3)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PE_C9_START (4)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PE_C9_END (4)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PE_C10_START (8)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PE_C10_END (8)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL0_START (12)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL0_END (12)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL1_START (13)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL1_END (13)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL2_START (14)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL2_END (14)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL3_START (15)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL3_END (15)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL4_START (16)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL4_END (16)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL5_START (17)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL5_END (17)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL6_START (18)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL6_END (18)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL7_START (19)
#define SOC_DDR_PHY_AC_PECTRL1_AC_RG_VOS_STEP_SEL7_END (19)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PRE_EN8_1_START (20)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PRE_EN8_1_END (20)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PUPDEN_CK_START (23)
#define SOC_DDR_PHY_AC_PECTRL1_AC_IO_PUPDEN_CK_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_PULLDN0 : 1;
        unsigned int AC_IO_PULLDN1 : 1;
        unsigned int AC_IO_PULLDN2 : 1;
        unsigned int AC_IO_PULLDN3 : 1;
        unsigned int AC_IO_PULLDN4 : 1;
        unsigned int AC_IO_PULLDN5 : 1;
        unsigned int AC_IO_PULLDN6 : 1;
        unsigned int AC_IO_PULLDN7 : 1;
        unsigned int AC_IO_PULLDN8 : 1;
        unsigned int AC_IO_PULLDN9 : 1;
        unsigned int AC_IO_PULLDN10 : 1;
        unsigned int reserved_0 : 5;
        unsigned int AC_IO_PUPDMODE : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_DDR_PHY_AC_PUPDCTRL_UNION;
#endif
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN0_START (0)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN0_END (0)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN1_START (1)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN1_END (1)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN2_START (2)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN2_END (2)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN3_START (3)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN3_END (3)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN4_START (4)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN4_END (4)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN5_START (5)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN5_END (5)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN6_START (6)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN6_END (6)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN7_START (7)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN7_END (7)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN8_START (8)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN8_END (8)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN9_START (9)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN9_END (9)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN10_START (10)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PULLDN10_END (10)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PUPDMODE_START (16)
#define SOC_DDR_PHY_AC_PUPDCTRL_AC_IO_PUPDMODE_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_RONSEL0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_RONSEL1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_RONSEL2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int AC_IO_RONSEL3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int AC_IO_RONSEL4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int AC_IO_RONSEL5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int AC_IO_RONSEL6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int AC_IO_RONSEL7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_DDR_PHY_AC_RONCTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL0_START (0)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL0_END (2)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL1_START (4)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL1_END (6)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL2_START (8)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL2_END (10)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL3_START (12)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL3_END (14)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL4_START (16)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL4_END (18)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL5_START (20)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL5_END (22)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL6_START (24)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL6_END (26)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL7_START (28)
#define SOC_DDR_PHY_AC_RONCTRL0_AC_IO_RONSEL7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_RONSEL8 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_RONBSEL : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_RONSEL9 : 3;
        unsigned int reserved_2 : 1;
        unsigned int AC_IO_RONSEL10 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} SOC_DDR_PHY_AC_RONCTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONSEL8_START (0)
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONSEL8_END (2)
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONBSEL_START (4)
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONBSEL_END (6)
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONSEL9_START (8)
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONSEL9_END (10)
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONSEL10_START (12)
#define SOC_DDR_PHY_AC_RONCTRL1_AC_IO_RONSEL10_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_REG_ODTEN : 1;
        unsigned int reserved_0 : 15;
        unsigned int AC_IO_ODTTEST : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_DDR_PHY_AC_ODTCTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_ODTCTRL0_AC_IO_REG_ODTEN_START (0)
#define SOC_DDR_PHY_AC_ODTCTRL0_AC_IO_REG_ODTEN_END (0)
#define SOC_DDR_PHY_AC_ODTCTRL0_AC_IO_ODTTEST_START (16)
#define SOC_DDR_PHY_AC_ODTCTRL0_AC_IO_ODTTEST_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_ODTEN : 11;
        unsigned int reserved_0 : 5;
        unsigned int AC_IO_TODTEN : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_DDR_PHY_AC_ODTCTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_ODTCTRL1_AC_IO_ODTEN_START (0)
#define SOC_DDR_PHY_AC_ODTCTRL1_AC_IO_ODTEN_END (10)
#define SOC_DDR_PHY_AC_ODTCTRL1_AC_IO_TODTEN_START (16)
#define SOC_DDR_PHY_AC_ODTCTRL1_AC_IO_TODTEN_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_ODTSEL0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_ODTSEL1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_ODTSEL2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int AC_IO_ODTSEL3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int AC_IO_ODTSEL4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int AC_IO_ODTSEL5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int AC_IO_ODTSEL6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int AC_IO_ODTSEL7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_DDR_PHY_AC_ODTCTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL0_START (0)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL0_END (2)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL1_START (4)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL1_END (6)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL2_START (8)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL2_END (10)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL3_START (12)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL3_END (14)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL4_START (16)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL4_END (18)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL5_START (20)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL5_END (22)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL6_START (24)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL6_END (26)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL7_START (28)
#define SOC_DDR_PHY_AC_ODTCTRL2_AC_IO_ODTSEL7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_ODTSEL8 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_ODTSEL9 : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_ODTSEL10 : 3;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_DDR_PHY_AC_ODTCTRL3_UNION;
#endif
#define SOC_DDR_PHY_AC_ODTCTRL3_AC_IO_ODTSEL8_START (0)
#define SOC_DDR_PHY_AC_ODTCTRL3_AC_IO_ODTSEL8_END (2)
#define SOC_DDR_PHY_AC_ODTCTRL3_AC_IO_ODTSEL9_START (4)
#define SOC_DDR_PHY_AC_ODTCTRL3_AC_IO_ODTSEL9_END (6)
#define SOC_DDR_PHY_AC_ODTCTRL3_AC_IO_ODTSEL10_START (8)
#define SOC_DDR_PHY_AC_ODTCTRL3_AC_IO_ODTSEL10_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_IOTEST : 11;
        unsigned int reserved_0 : 5;
        unsigned int AC_IO_IETEST : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_DDR_PHY_AC_TESTCTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_TESTCTRL0_AC_IO_IOTEST_START (0)
#define SOC_DDR_PHY_AC_TESTCTRL0_AC_IO_IOTEST_END (10)
#define SOC_DDR_PHY_AC_TESTCTRL0_AC_IO_IETEST_START (16)
#define SOC_DDR_PHY_AC_TESTCTRL0_AC_IO_IETEST_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_TE : 11;
        unsigned int reserved_0: 5;
        unsigned int AC_IO_TI : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_DDR_PHY_AC_TESTCTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_TESTCTRL1_AC_IO_TE_START (0)
#define SOC_DDR_PHY_AC_TESTCTRL1_AC_IO_TE_END (10)
#define SOC_DDR_PHY_AC_TESTCTRL1_AC_IO_TI_START (16)
#define SOC_DDR_PHY_AC_TESTCTRL1_AC_IO_TI_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_TIE : 11;
        unsigned int reserved_0: 5;
        unsigned int AC_IO_TO : 11;
        unsigned int reserved_1: 4;
        unsigned int AC_IO_NE : 1;
    } reg;
} SOC_DDR_PHY_AC_TESTCTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_TESTCTRL2_AC_IO_TIE_START (0)
#define SOC_DDR_PHY_AC_TESTCTRL2_AC_IO_TIE_END (10)
#define SOC_DDR_PHY_AC_TESTCTRL2_AC_IO_TO_START (16)
#define SOC_DDR_PHY_AC_TESTCTRL2_AC_IO_TO_END (26)
#define SOC_DDR_PHY_AC_TESTCTRL2_AC_IO_NE_START (31)
#define SOC_DDR_PHY_AC_TESTCTRL2_AC_IO_NE_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_freq_det_ref_div_cnt : 7;
        unsigned int reg_freq_det_enable : 1;
        unsigned int reg_o_freq_det_done : 1;
        unsigned int reg_o_freq_det_count_value : 12;
        unsigned int RG_SQ_DI_WCK : 3;
        unsigned int RG_SQ_DI_DQS : 3;
        unsigned int reserved : 1;
        unsigned int SE_CLKD_WCK : 4;
    } reg;
} SOC_DDR_PHY_DLL_DCC_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_freq_det_ref_div_cnt_START (0)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_freq_det_ref_div_cnt_END (6)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_freq_det_enable_START (7)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_freq_det_enable_END (7)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_o_freq_det_done_START (8)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_o_freq_det_done_END (8)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_o_freq_det_count_value_START (9)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_reg_o_freq_det_count_value_END (20)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_RG_SQ_DI_WCK_START (21)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_RG_SQ_DI_WCK_END (23)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_RG_SQ_DI_DQS_START (24)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_RG_SQ_DI_DQS_END (26)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_SE_CLKD_WCK_START (28)
#define SOC_DDR_PHY_DLL_DCC_CTRL0_SE_CLKD_WCK_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DLL_EN : 1;
        unsigned int DLL_PRE_DIV : 2;
        unsigned int DLL_RG_CLK_DIV : 1;
        unsigned int DLL_DOUT : 1;
        unsigned int reserved_0 : 2;
        unsigned int DLL_RSTN : 1;
        unsigned int DLL_MASK : 2;
        unsigned int RG_SQ_DI_CK : 3;
        unsigned int reserved_1 : 2;
        unsigned int EN_SP_WCK : 1;
        unsigned int DLL_INITIAL : 10;
        unsigned int SE_CLKD_DQS : 4;
        unsigned int EN_SP_DQS : 1;
        unsigned int reg_freq_det_free_run_en : 1;
    } reg;
} SOC_DDR_PHY_DLL_DCC_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_EN_START (0)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_EN_END (0)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_PRE_DIV_START (1)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_PRE_DIV_END (2)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_RG_CLK_DIV_START (3)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_RG_CLK_DIV_END (3)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_DOUT_START (4)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_DOUT_END (4)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_RSTN_START (7)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_RSTN_END (7)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_MASK_START (8)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_MASK_END (9)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_RG_SQ_DI_CK_START (10)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_RG_SQ_DI_CK_END (12)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_EN_SP_WCK_START (15)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_EN_SP_WCK_END (15)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_INITIAL_START (16)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_DLL_INITIAL_END (25)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_SE_CLKD_DQS_START (26)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_SE_CLKD_DQS_END (29)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_EN_SP_DQS_START (30)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_EN_SP_DQS_END (30)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_reg_freq_det_free_run_en_START (31)
#define SOC_DDR_PHY_DLL_DCC_CTRL1_reg_freq_det_free_run_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_TX_DCC_P_DN0 : 4;
        unsigned int AC_TX_DCC_P_DN1 : 4;
        unsigned int AC_TX_DCC_P_DN2 : 4;
        unsigned int AC_TX_DCC_P_DN3 : 4;
        unsigned int AC_TX_DCC_P_DN4 : 4;
        unsigned int AC_TX_DCC_P_DN5 : 4;
        unsigned int AC_TX_DCC_P_DN6 : 4;
        unsigned int AC_TX_DCC_P_DN7 : 4;
    } reg;
} SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN0_START (0)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN0_END (3)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN1_START (4)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN1_END (7)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN2_START (8)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN2_END (11)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN3_START (12)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN3_END (15)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN4_START (16)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN4_END (19)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN5_START (20)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN5_END (23)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN6_START (24)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN6_END (27)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN7_START (28)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_TX_DCC_P_DN8 : 4;
        unsigned int AC_TX_DCC_P_DN9 : 4;
        unsigned int AC_TX_DCC_P_DN10 : 4;
        unsigned int reg_freq_det_th : 12;
        unsigned int reg_freq_det_th_mrg : 8;
    } reg;
} SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN8_START (0)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN8_END (3)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN9_START (4)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN9_END (7)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN10_START (8)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN10_END (11)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_START (12)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_END (23)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_mrg_START (24)
#define SOC_DDR_PHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_mrg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_TX_DCC_N_DN0 : 4;
        unsigned int AC_TX_DCC_N_DN1 : 4;
        unsigned int AC_TX_DCC_N_DN2 : 4;
        unsigned int AC_TX_DCC_N_DN3 : 4;
        unsigned int AC_TX_DCC_N_DN4 : 4;
        unsigned int AC_TX_DCC_N_DN5 : 4;
        unsigned int AC_TX_DCC_N_DN6 : 4;
        unsigned int AC_TX_DCC_N_DN7 : 4;
    } reg;
} SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN0_START (0)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN0_END (3)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN1_START (4)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN1_END (7)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN2_START (8)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN2_END (11)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN3_START (12)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN3_END (15)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN4_START (16)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN4_END (19)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN5_START (20)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN5_END (23)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN6_START (24)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN6_END (27)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN7_START (28)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_TX_DCC_N_DN8 : 4;
        unsigned int AC_TX_DCC_N_DN9 : 4;
        unsigned int AC_TX_DCC_N_DN10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN8_START (0)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN8_END (3)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN9_START (4)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN9_END (7)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN10_START (8)
#define SOC_DDR_PHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int CK_DA_RX_DIO_VOS : 5;
        unsigned int CK_DA_RX_DIO_VOSK_EN : 1;
        unsigned int CK_DA_RX_DIO_VOSK_INSHORT : 1;
        unsigned int CK_DA_RX_DIO_VOSK_SEL : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_UNION;
#endif
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOS_START (0)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOS_END (4)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOSK_EN_START (5)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOSK_EN_END (5)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOSK_INSHORT_START (6)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOSK_INSHORT_END (6)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOSK_SEL_START (7)
#define SOC_DDR_PHY_AC_RX_DIO_VOS_CTRL_CK_DA_RX_DIO_VOSK_SEL_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_P_DN0 : 4;
        unsigned int AC_RX_DCC_P_DN1 : 4;
        unsigned int AC_RX_DCC_P_DN2 : 4;
        unsigned int AC_RX_DCC_P_DN3 : 4;
        unsigned int AC_RX_DCC_P_DN4 : 4;
        unsigned int AC_RX_DCC_P_DN5 : 4;
        unsigned int AC_RX_DCC_P_DN6 : 4;
        unsigned int AC_RX_DCC_P_DN7 : 4;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN0_START (0)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN0_END (3)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN1_START (4)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN1_END (7)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN2_START (8)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN2_END (11)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN3_START (12)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN3_END (15)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN4_START (16)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN4_END (19)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN5_START (20)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN5_END (23)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN6_START (24)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN6_END (27)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN7_START (28)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_P_DN8 : 4;
        unsigned int AC_RX_DCC_P_DN9 : 4;
        unsigned int AC_RX_DCC_P_DN10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN8_START (0)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN8_END (3)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN9_START (4)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN9_END (7)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN10_START (8)
#define SOC_DDR_PHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_N_DN0 : 4;
        unsigned int AC_RX_DCC_N_DN1 : 4;
        unsigned int AC_RX_DCC_N_DN2 : 4;
        unsigned int AC_RX_DCC_N_DN3 : 4;
        unsigned int AC_RX_DCC_N_DN4 : 4;
        unsigned int AC_RX_DCC_N_DN5 : 4;
        unsigned int AC_RX_DCC_N_DN6 : 4;
        unsigned int AC_RX_DCC_N_DN7 : 4;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN0_START (0)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN0_END (3)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN1_START (4)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN1_END (7)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN2_START (8)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN2_END (11)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN3_START (12)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN3_END (15)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN4_START (16)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN4_END (19)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN5_START (20)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN5_END (23)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN6_START (24)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN6_END (27)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN7_START (28)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_N_DN8 : 4;
        unsigned int AC_RX_DCC_N_DN9 : 4;
        unsigned int AC_RX_DCC_N_DN10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN8_START (0)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN8_END (3)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN9_START (4)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN9_END (7)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN10_START (8)
#define SOC_DDR_PHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_P_UP0 : 4;
        unsigned int AC_RX_DCC_P_UP1 : 4;
        unsigned int AC_RX_DCC_P_UP2 : 4;
        unsigned int AC_RX_DCC_P_UP3 : 4;
        unsigned int AC_RX_DCC_P_UP4 : 4;
        unsigned int AC_RX_DCC_P_UP5 : 4;
        unsigned int AC_RX_DCC_P_UP6 : 4;
        unsigned int AC_RX_DCC_P_UP7 : 4;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP0_START (0)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP0_END (3)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP1_START (4)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP1_END (7)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP2_START (8)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP2_END (11)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP3_START (12)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP3_END (15)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP4_START (16)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP4_END (19)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP5_START (20)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP5_END (23)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP6_START (24)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP6_END (27)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP7_START (28)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_P_UP8 : 4;
        unsigned int AC_RX_DCC_P_UP9 : 4;
        unsigned int AC_RX_DCC_P_UP10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP8_START (0)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP8_END (3)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP9_START (4)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP9_END (7)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP10_START (8)
#define SOC_DDR_PHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_N_UP0 : 4;
        unsigned int AC_RX_DCC_N_UP1 : 4;
        unsigned int AC_RX_DCC_N_UP2 : 4;
        unsigned int AC_RX_DCC_N_UP3 : 4;
        unsigned int AC_RX_DCC_N_UP4 : 4;
        unsigned int AC_RX_DCC_N_UP5 : 4;
        unsigned int AC_RX_DCC_N_UP6 : 4;
        unsigned int AC_RX_DCC_N_UP7 : 4;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP0_START (0)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP0_END (3)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP1_START (4)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP1_END (7)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP2_START (8)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP2_END (11)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP3_START (12)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP3_END (15)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP4_START (16)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP4_END (19)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP5_START (20)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP5_END (23)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP6_START (24)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP6_END (27)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP7_START (28)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RX_DCC_N_UP8 : 4;
        unsigned int AC_RX_DCC_N_UP9 : 4;
        unsigned int AC_RX_DCC_N_UP10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_UNION;
#endif
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP8_START (0)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP8_END (3)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP9_START (4)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP9_END (7)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP10_START (8)
#define SOC_DDR_PHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST0_0 : 1;
        unsigned int AC_RG_TEST0_1 : 1;
        unsigned int AC_RG_TEST0_2 : 2;
        unsigned int AC_RG_TEST0_3 : 1;
        unsigned int AC_RG_TEST0_4 : 3;
        unsigned int AC_RG_TEST1_0 : 1;
        unsigned int AC_RG_TEST1_1 : 1;
        unsigned int AC_RG_TEST1_2 : 2;
        unsigned int AC_RG_TEST1_3 : 1;
        unsigned int AC_RG_TEST1_4 : 3;
        unsigned int AC_RG_TEST2_0 : 1;
        unsigned int AC_RG_TEST2_1 : 1;
        unsigned int AC_RG_TEST2_2 : 2;
        unsigned int AC_RG_TEST2_3 : 1;
        unsigned int AC_RG_TEST2_4 : 3;
        unsigned int AC_RG_TEST3_0 : 1;
        unsigned int AC_RG_TEST3_1 : 1;
        unsigned int AC_RG_TEST3_2 : 2;
        unsigned int AC_RG_TEST3_3 : 1;
        unsigned int AC_RG_TEST3_4 : 3;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_CTL0_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_0_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_0_END (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_1_START (1)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_1_END (1)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_2_START (2)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_2_END (3)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_3_START (4)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_3_END (4)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_4_START (5)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST0_4_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_0_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_0_END (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_1_START (9)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_1_END (9)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_2_START (10)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_2_END (11)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_3_START (12)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_3_END (12)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_4_START (13)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST1_4_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_0_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_0_END (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_1_START (17)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_1_END (17)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_2_START (18)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_2_END (19)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_3_START (20)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_3_END (20)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_4_START (21)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST2_4_END (23)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_0_START (24)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_0_END (24)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_1_START (25)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_1_END (25)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_2_START (26)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_2_END (27)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_3_START (28)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_3_END (28)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_4_START (29)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_AC_RG_TEST3_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST4_0 : 1;
        unsigned int AC_RG_TEST4_1 : 1;
        unsigned int AC_RG_TEST4_2 : 2;
        unsigned int AC_RG_TEST4_3 : 1;
        unsigned int AC_RG_TEST4_4 : 3;
        unsigned int AC_RG_TEST5_0 : 1;
        unsigned int AC_RG_TEST5_1 : 1;
        unsigned int AC_RG_TEST5_2 : 2;
        unsigned int AC_RG_TEST5_3 : 1;
        unsigned int AC_RG_TEST5_4 : 3;
        unsigned int AC_RG_TEST6_0 : 1;
        unsigned int AC_RG_TEST6_1 : 1;
        unsigned int AC_RG_TEST6_2 : 2;
        unsigned int AC_RG_TEST6_3 : 1;
        unsigned int AC_RG_TEST6_4 : 3;
        unsigned int AC_RG_TEST7_0 : 1;
        unsigned int AC_RG_TEST7_1 : 1;
        unsigned int AC_RG_TEST7_2 : 2;
        unsigned int AC_RG_TEST7_3 : 1;
        unsigned int AC_RG_TEST7 : 3;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_CTL1_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_0_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_0_END (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_1_START (1)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_1_END (1)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_2_START (2)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_2_END (3)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_3_START (4)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_3_END (4)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_4_START (5)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST4_4_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_0_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_0_END (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_1_START (9)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_1_END (9)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_2_START (10)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_2_END (11)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_3_START (12)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_3_END (12)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_4_START (13)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST5_4_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_0_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_0_END (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_1_START (17)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_1_END (17)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_2_START (18)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_2_END (19)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_3_START (20)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_3_END (20)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_4_START (21)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST6_4_END (23)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_0_START (24)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_0_END (24)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_1_START (25)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_1_END (25)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_2_START (26)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_2_END (27)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_3_START (28)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_3_END (28)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_START (29)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_AC_RG_TEST7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST8_0 : 1;
        unsigned int AC_RG_TEST8_1 : 1;
        unsigned int AC_RG_TEST8_2 : 1;
        unsigned int AC_RG_TEST8_3 : 1;
        unsigned int AC_RG_TEST8_4 : 4;
        unsigned int AC_RG_TEST9_0 : 1;
        unsigned int AC_RG_TEST9_1 : 1;
        unsigned int AC_RG_TEST9_2 : 6;
        unsigned int AC_RG_TEST10_0 : 1;
        unsigned int AC_RG_TEST10_1 : 1;
        unsigned int AC_RG_TEST10_2 : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_CTL2_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_0_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_0_END (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_1_START (1)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_1_END (1)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_2_START (2)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_2_END (2)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_3_START (3)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_3_END (3)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_4_START (4)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST8_4_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST9_0_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST9_0_END (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST9_1_START (9)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST9_1_END (9)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST9_2_START (10)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST9_2_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST10_0_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST10_0_END (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST10_1_START (17)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST10_1_END (17)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST10_2_START (18)
#define SOC_DDR_PHY_AC_RG_TEST_CTL2_AC_RG_TEST10_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DLL_MEA_CODE : 10;
        unsigned int DLL_MEA_DONE : 1;
        unsigned int DLL_MEA_EN : 1;
        unsigned int DLL_cfg_match_0 : 1;
        unsigned int DLL_cfg_match_1 : 1;
        unsigned int DLL_MEA_GCKEN : 1;
        unsigned int DLL_cfg_mulsmp_en : 1;
        unsigned int DLL_cfg_cstep : 4;
        unsigned int DLL_cfg_timer : 3;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_PHY_AC_DLL_CODE_UNION;
#endif
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_CODE_START (0)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_CODE_END (9)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_DONE_START (10)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_DONE_END (10)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_EN_START (11)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_EN_END (11)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_match_0_START (12)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_match_0_END (12)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_match_1_START (13)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_match_1_END (13)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_GCKEN_START (14)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_MEA_GCKEN_END (14)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_mulsmp_en_START (15)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_mulsmp_en_END (15)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_cstep_START (16)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_cstep_END (19)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_timer_START (20)
#define SOC_DDR_PHY_AC_DLL_CODE_DLL_cfg_timer_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_ZQ_OFFSETK : 4;
        unsigned int SFIO_MODE : 3;
        unsigned int reg_ZQ_OFFSETK_EN : 1;
        unsigned int SFIO_PULLDN : 3;
        unsigned int reg_ZQ_COMPIN_SWAP : 1;
        unsigned int SFIO_IOTEST : 3;
        unsigned int reserved_0 : 1;
        unsigned int SFIO_IETEST : 3;
        unsigned int reserved_1 : 1;
        unsigned int SFIO_TI : 3;
        unsigned int reserved_2 : 1;
        unsigned int SFIO_TE : 3;
        unsigned int reserved_3 : 1;
        unsigned int SFIO_TIE : 3;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_DDR_PHY_AC_SFIO_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_START (0)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_END (3)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_MODE_START (4)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_MODE_END (6)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_EN_START (7)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_EN_END (7)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_PULLDN_START (8)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_PULLDN_END (10)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_reg_ZQ_COMPIN_SWAP_START (11)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_reg_ZQ_COMPIN_SWAP_END (11)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_IOTEST_START (12)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_IOTEST_END (14)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_IETEST_START (16)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_IETEST_END (18)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_TI_START (20)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_TI_END (22)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_TE_START (24)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_TE_END (26)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_TIE_START (28)
#define SOC_DDR_PHY_AC_SFIO_CTRL0_SFIO_TIE_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int SFIO_RONSEL : 9;
        unsigned int reserved_0 : 7;
        unsigned int SFIO_TO : 3;
        unsigned int reserved_1 : 12;
        unsigned int reg_ZQ_EN : 1;
    } reg;
} SOC_DDR_PHY_AC_SFIO_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_SFIO_CTRL1_SFIO_RONSEL_START (0)
#define SOC_DDR_PHY_AC_SFIO_CTRL1_SFIO_RONSEL_END (8)
#define SOC_DDR_PHY_AC_SFIO_CTRL1_SFIO_TO_START (16)
#define SOC_DDR_PHY_AC_SFIO_CTRL1_SFIO_TO_END (18)
#define SOC_DDR_PHY_AC_SFIO_CTRL1_reg_ZQ_EN_START (31)
#define SOC_DDR_PHY_AC_SFIO_CTRL1_reg_ZQ_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxaddr0_bdl : 10;
        unsigned int rxaddr1_bdl : 10;
        unsigned int rxaddr2_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_AC_BDL_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_AC_BDL_CTRL0_rxaddr0_bdl_START (0)
#define SOC_DDR_PHY_AC_BDL_CTRL0_rxaddr0_bdl_END (9)
#define SOC_DDR_PHY_AC_BDL_CTRL0_rxaddr1_bdl_START (10)
#define SOC_DDR_PHY_AC_BDL_CTRL0_rxaddr1_bdl_END (19)
#define SOC_DDR_PHY_AC_BDL_CTRL0_rxaddr2_bdl_START (20)
#define SOC_DDR_PHY_AC_BDL_CTRL0_rxaddr2_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxaddr3_bdl : 10;
        unsigned int rxaddr4_bdl : 10;
        unsigned int rxaddr5_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_AC_BDL_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_AC_BDL_CTRL1_rxaddr3_bdl_START (0)
#define SOC_DDR_PHY_AC_BDL_CTRL1_rxaddr3_bdl_END (9)
#define SOC_DDR_PHY_AC_BDL_CTRL1_rxaddr4_bdl_START (10)
#define SOC_DDR_PHY_AC_BDL_CTRL1_rxaddr4_bdl_END (19)
#define SOC_DDR_PHY_AC_BDL_CTRL1_rxaddr5_bdl_START (20)
#define SOC_DDR_PHY_AC_BDL_CTRL1_rxaddr5_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ck_bdl : 10;
        unsigned int rxck_bdl : 10;
        unsigned int rxcs0_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_AC_BDL_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_BDL_CTRL2_ck_bdl_START (0)
#define SOC_DDR_PHY_AC_BDL_CTRL2_ck_bdl_END (9)
#define SOC_DDR_PHY_AC_BDL_CTRL2_rxck_bdl_START (10)
#define SOC_DDR_PHY_AC_BDL_CTRL2_rxck_bdl_END (19)
#define SOC_DDR_PHY_AC_BDL_CTRL2_rxcs0_bdl_START (20)
#define SOC_DDR_PHY_AC_BDL_CTRL2_rxcs0_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcs1_bdl : 10;
        unsigned int rxcke0_bdl : 10;
        unsigned int rxcke1_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_AC_BDL_CTRL3_UNION;
#endif
#define SOC_DDR_PHY_AC_BDL_CTRL3_rxcs1_bdl_START (0)
#define SOC_DDR_PHY_AC_BDL_CTRL3_rxcs1_bdl_END (9)
#define SOC_DDR_PHY_AC_BDL_CTRL3_rxcke0_bdl_START (10)
#define SOC_DDR_PHY_AC_BDL_CTRL3_rxcke0_bdl_END (19)
#define SOC_DDR_PHY_AC_BDL_CTRL3_rxcke1_bdl_START (20)
#define SOC_DDR_PHY_AC_BDL_CTRL3_rxcke1_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int PLL_EN_BIAS_A : 1;
        unsigned int reserved_0 : 3;
        unsigned int RG_PLL_LPF_R_A : 2;
        unsigned int RG_PLL_PLL_POSDIV_A : 9;
        unsigned int RG_PLL_DLL_POSDIV_A : 9;
        unsigned int RG_PLL_PREDIV_A : 3;
        unsigned int RG_SSC_resetn_A : 1;
        unsigned int reserved_1 : 1;
        unsigned int EN_PLL_LOAD_BAND_EN_A : 1;
        unsigned int RG_SSC_resetj_A : 1;
        unsigned int RG_SSC_resetsj_A : 1;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_A_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_A_PLL_EN_BIAS_A_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_PLL_EN_BIAS_A_END (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_LPF_R_A_START (4)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_LPF_R_A_END (5)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_PLL_POSDIV_A_START (6)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_PLL_POSDIV_A_END (14)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_DLL_POSDIV_A_START (15)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_DLL_POSDIV_A_END (23)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_PREDIV_A_START (24)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_PLL_PREDIV_A_END (26)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_SSC_resetn_A_START (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_SSC_resetn_A_END (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_EN_PLL_LOAD_BAND_EN_A_START (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_EN_PLL_LOAD_BAND_EN_A_END (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_SSC_resetj_A_START (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_SSC_resetj_A_END (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_SSC_resetsj_A_START (31)
#define SOC_DDR_PHY_AC_PLL_CTRL_A_RG_SSC_resetsj_A_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int PLL_EN_BIAS_B : 1;
        unsigned int reserved_0 : 3;
        unsigned int RG_PLL_LPF_R_B : 2;
        unsigned int RG_PLL_PLL_POSDIV_B : 9;
        unsigned int RG_PLL_DLL_POSDIV_B : 9;
        unsigned int RG_PLL_PREDIV_B : 3;
        unsigned int RG_SSC_resetn_B : 1;
        unsigned int reserved_1 : 1;
        unsigned int EN_PLL_LOAD_BAND_EN_B : 1;
        unsigned int RG_SSC_resetj_B : 1;
        unsigned int RG_SSC_resetsj_B : 1;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_B_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_B_PLL_EN_BIAS_B_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_PLL_EN_BIAS_B_END (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_LPF_R_B_START (4)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_LPF_R_B_END (5)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_PLL_POSDIV_B_START (6)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_PLL_POSDIV_B_END (14)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_DLL_POSDIV_B_START (15)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_DLL_POSDIV_B_END (23)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_PREDIV_B_START (24)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_PLL_PREDIV_B_END (26)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_SSC_resetn_B_START (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_SSC_resetn_B_END (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_EN_PLL_LOAD_BAND_EN_B_START (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_EN_PLL_LOAD_BAND_EN_B_END (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_SSC_resetj_B_START (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_SSC_resetj_B_END (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_SSC_resetsj_B_START (31)
#define SOC_DDR_PHY_AC_PLL_CTRL_B_RG_SSC_resetsj_B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_gate_en : 1;
        unsigned int phyclk_gate_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_PHY_AC_PHYCLK_GATECTRL_UNION;
#endif
#define SOC_DDR_PHY_AC_PHYCLK_GATECTRL_pll_gate_en_START (0)
#define SOC_DDR_PHY_AC_PHYCLK_GATECTRL_pll_gate_en_END (0)
#define SOC_DDR_PHY_AC_PHYCLK_GATECTRL_phyclk_gate_en_START (1)
#define SOC_DDR_PHY_AC_PHYCLK_GATECTRL_phyclk_gate_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_PLL_LOCKDET_A : 8;
        unsigned int reserved_0 : 2;
        unsigned int RG_SSC_r_triangular_sel_A : 1;
        unsigned int RG_SSC_r_ups_en_A : 1;
        unsigned int RG_SSC_r_frac_en_A : 1;
        unsigned int RG_SSC_r_sdmtype_A : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_A2_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_PLL_LOCKDET_A_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_PLL_LOCKDET_A_END (7)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_triangular_sel_A_START (10)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_triangular_sel_A_END (10)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_ups_en_A_START (11)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_ups_en_A_END (11)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_frac_en_A_START (12)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_frac_en_A_END (12)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_sdmtype_A_START (13)
#define SOC_DDR_PHY_AC_PLL_CTRL_A2_RG_SSC_r_sdmtype_A_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_SSC_r_triinc_A : 8;
        unsigned int RG_SSC_r_div_frac_A : 8;
        unsigned int RG_SSC_r_spreadmax_A : 8;
        unsigned int RG_SSC_r_sscdivnum_A : 4;
        unsigned int RG_SSC_r_sscdiv_en_A : 1;
        unsigned int RG_SSC_r_prbs3_en_A : 1;
        unsigned int RG_SSC_r_prbs2_en_A : 1;
        unsigned int RG_SSC_r_prbs1_en_A : 1;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_A3_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_triinc_A_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_triinc_A_END (7)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_div_frac_A_START (8)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_div_frac_A_END (15)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_spreadmax_A_START (16)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_spreadmax_A_END (23)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdivnum_A_START (24)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdivnum_A_END (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdiv_en_A_START (28)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdiv_en_A_END (28)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs3_en_A_START (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs3_en_A_END (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs2_en_A_START (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs2_en_A_END (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs1_en_A_START (31)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs1_en_A_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_PLL_LOCKDET_B : 8;
        unsigned int reserved_0 : 2;
        unsigned int RG_SSC_r_triangular_sel_B : 1;
        unsigned int RG_SSC_r_ups_en_B : 1;
        unsigned int RG_SSC_r_frac_en_B : 1;
        unsigned int RG_SSC_r_sdmtype_B : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_B2_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_PLL_LOCKDET_B_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_PLL_LOCKDET_B_END (7)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_triangular_sel_B_START (10)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_triangular_sel_B_END (10)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_ups_en_B_START (11)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_ups_en_B_END (11)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_frac_en_B_START (12)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_frac_en_B_END (12)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_sdmtype_B_START (13)
#define SOC_DDR_PHY_AC_PLL_CTRL_B2_RG_SSC_r_sdmtype_B_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_SSC_r_triinc_B : 8;
        unsigned int RG_SSC_r_div_frac_B : 8;
        unsigned int RG_SSC_r_spreadmax_B : 8;
        unsigned int RG_SSC_r_sscdivnum_B : 4;
        unsigned int RG_SSC_r_sscdiv_en_B : 1;
        unsigned int RG_SSC_r_prbs3_en_B : 1;
        unsigned int RG_SSC_r_prbs2_en_B : 1;
        unsigned int RG_SSC_r_prbs1_en_B : 1;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_B3_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_triinc_B_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_triinc_B_END (7)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_div_frac_B_START (8)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_div_frac_B_END (15)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_spreadmax_B_START (16)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_spreadmax_B_END (23)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdivnum_B_START (24)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdivnum_B_END (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdiv_en_B_START (28)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdiv_en_B_END (28)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs3_en_B_START (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs3_en_B_END (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs2_en_B_START (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs2_en_B_END (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs1_en_B_START (31)
#define SOC_DDR_PHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs1_en_B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_SSC_r_div_int_A : 11;
        unsigned int RG_SSC_r_fracssc_en_A : 1;
        unsigned int RG_SSC_r_spread_en_A : 1;
        unsigned int PLL_LOCK_A : 1;
        unsigned int PLL_EN_A : 1;
        unsigned int reserved_0 : 1;
        unsigned int RG_SSC_r_div_int_B : 11;
        unsigned int RG_SSC_r_fracssc_en_B : 1;
        unsigned int RG_SSC_r_spread_en_B : 1;
        unsigned int PLL_LOCK_B : 1;
        unsigned int PLL_EN_B : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_AB_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_A_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_A_END (10)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_A_START (11)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_A_END (11)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_A_START (12)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_A_END (12)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_LOCK_A_START (13)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_LOCK_A_END (13)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_EN_A_START (14)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_EN_A_END (14)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_B_START (16)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_B_END (26)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_B_START (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_B_END (27)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_B_START (28)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_B_END (28)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_LOCK_B_START (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_LOCK_B_END (29)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_EN_B_START (30)
#define SOC_DDR_PHY_AC_PLL_CTRL_AB_PLL_EN_B_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_PLL_KBAND_RESERVE_B : 16;
        unsigned int RG_PLL_KBAND_RESERVE_A : 16;
    } reg;
} SOC_DDR_PHY_AC_PLL_RSV_CTRL_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_RSV_CTRL_RG_PLL_KBAND_RESERVE_B_START (0)
#define SOC_DDR_PHY_AC_PLL_RSV_CTRL_RG_PLL_KBAND_RESERVE_B_END (15)
#define SOC_DDR_PHY_AC_PLL_RSV_CTRL_RG_PLL_KBAND_RESERVE_A_START (16)
#define SOC_DDR_PHY_AC_PLL_RSV_CTRL_RG_PLL_KBAND_RESERVE_A_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AD_SSC_div_mode_dbgo_A : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_DDR_PHY_AC_PLL_DBG_A_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_DBG_A_AD_SSC_div_mode_dbgo_A_START (0)
#define SOC_DDR_PHY_AC_PLL_DBG_A_AD_SSC_div_mode_dbgo_A_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AD_SSC_div_mode_dbgo_B : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_DDR_PHY_AC_PLL_DBG_B_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_DBG_B_AD_SSC_div_mode_dbgo_B_START (0)
#define SOC_DDR_PHY_AC_PLL_DBG_B_AD_SSC_div_mode_dbgo_B_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_dbg_sel : 3;
        unsigned int reg_dbg_mode : 1;
        unsigned int reg_acctl_csoe_gated : 1;
        unsigned int reg_acctl_ckeoe_gated : 1;
        unsigned int reg_bdl_sw_rst : 1;
        unsigned int reg_dlyline_gate_bypass : 1;
        unsigned int reg_bypclk_gated_bypass : 1;
        unsigned int reg_non_ovlp_en : 1;
        unsigned int reg_acctl_addroe_gated : 6;
        unsigned int reg_pll_lock_en : 1;
        unsigned int reg_pll_lock_sel : 1;
        unsigned int reserved : 9;
        unsigned int reg_gds_rank_en : 1;
        unsigned int reg_odten_sel : 1;
        unsigned int reg_ac_lpbk_en : 1;
        unsigned int reg_phgck_rst : 1;
        unsigned int reg_dqs_pupd_mask : 1;
    } reg;
} SOC_DDR_PHY_AC_CTRL_1_UNION;
#endif
#define SOC_DDR_PHY_AC_CTRL_1_reg_dbg_sel_START (0)
#define SOC_DDR_PHY_AC_CTRL_1_reg_dbg_sel_END (2)
#define SOC_DDR_PHY_AC_CTRL_1_reg_dbg_mode_START (3)
#define SOC_DDR_PHY_AC_CTRL_1_reg_dbg_mode_END (3)
#define SOC_DDR_PHY_AC_CTRL_1_reg_acctl_csoe_gated_START (4)
#define SOC_DDR_PHY_AC_CTRL_1_reg_acctl_csoe_gated_END (4)
#define SOC_DDR_PHY_AC_CTRL_1_reg_acctl_ckeoe_gated_START (5)
#define SOC_DDR_PHY_AC_CTRL_1_reg_acctl_ckeoe_gated_END (5)
#define SOC_DDR_PHY_AC_CTRL_1_reg_bdl_sw_rst_START (6)
#define SOC_DDR_PHY_AC_CTRL_1_reg_bdl_sw_rst_END (6)
#define SOC_DDR_PHY_AC_CTRL_1_reg_dlyline_gate_bypass_START (7)
#define SOC_DDR_PHY_AC_CTRL_1_reg_dlyline_gate_bypass_END (7)
#define SOC_DDR_PHY_AC_CTRL_1_reg_bypclk_gated_bypass_START (8)
#define SOC_DDR_PHY_AC_CTRL_1_reg_bypclk_gated_bypass_END (8)
#define SOC_DDR_PHY_AC_CTRL_1_reg_non_ovlp_en_START (9)
#define SOC_DDR_PHY_AC_CTRL_1_reg_non_ovlp_en_END (9)
#define SOC_DDR_PHY_AC_CTRL_1_reg_acctl_addroe_gated_START (10)
#define SOC_DDR_PHY_AC_CTRL_1_reg_acctl_addroe_gated_END (15)
#define SOC_DDR_PHY_AC_CTRL_1_reg_pll_lock_en_START (16)
#define SOC_DDR_PHY_AC_CTRL_1_reg_pll_lock_en_END (16)
#define SOC_DDR_PHY_AC_CTRL_1_reg_pll_lock_sel_START (17)
#define SOC_DDR_PHY_AC_CTRL_1_reg_pll_lock_sel_END (17)
#define SOC_DDR_PHY_AC_CTRL_1_reg_gds_rank_en_START (27)
#define SOC_DDR_PHY_AC_CTRL_1_reg_gds_rank_en_END (27)
#define SOC_DDR_PHY_AC_CTRL_1_reg_odten_sel_START (28)
#define SOC_DDR_PHY_AC_CTRL_1_reg_odten_sel_END (28)
#define SOC_DDR_PHY_AC_CTRL_1_reg_ac_lpbk_en_START (29)
#define SOC_DDR_PHY_AC_CTRL_1_reg_ac_lpbk_en_END (29)
#define SOC_DDR_PHY_AC_CTRL_1_reg_phgck_rst_START (30)
#define SOC_DDR_PHY_AC_CTRL_1_reg_phgck_rst_END (30)
#define SOC_DDR_PHY_AC_CTRL_1_reg_dqs_pupd_mask_START (31)
#define SOC_DDR_PHY_AC_CTRL_1_reg_dqs_pupd_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_rev_reg_0_3 : 1;
        unsigned int ac_rev_reg_0_2 : 15;
        unsigned int ac_rev_reg_0_1 : 2;
        unsigned int ac_rev_reg_0_0 : 14;
    } reg;
} SOC_DDR_PHY_AC_REV_REG_0_UNION;
#endif
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_3_START (0)
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_3_END (0)
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_2_START (1)
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_2_END (15)
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_1_START (16)
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_1_END (17)
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_0_START (18)
#define SOC_DDR_PHY_AC_REV_REG_0_ac_rev_reg_0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_rev_reg_out_0 : 32;
    } reg;
} SOC_DDR_PHY_AC_REV_REG_OUT_0_UNION;
#endif
#define SOC_DDR_PHY_AC_REV_REG_OUT_0_ac_rev_reg_out_0_START (0)
#define SOC_DDR_PHY_AC_REV_REG_OUT_0_ac_rev_reg_out_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_rev_reg_1_14 : 1;
        unsigned int ac_rev_reg_1_13 : 1;
        unsigned int ac_rev_reg_1_12 : 2;
        unsigned int ac_rev_reg_1_11 : 1;
        unsigned int ac_rev_reg_1_10 : 1;
        unsigned int ac_rev_reg_1_9 : 1;
        unsigned int ac_rev_reg_1_8 : 1;
        unsigned int ac_rev_reg_1_7 : 1;
        unsigned int ac_rev_reg_1_6 : 1;
        unsigned int ac_rev_reg_1_5 : 1;
        unsigned int ac_rev_reg_1_4 : 1;
        unsigned int ac_rev_reg_1_3 : 1;
        unsigned int ac_rev_reg_1_2 : 2;
        unsigned int ac_rev_reg_1_1 : 1;
        unsigned int ac_rev_reg_1_0 : 16;
    } reg;
} SOC_DDR_PHY_AC_REV_REG_1_UNION;
#endif
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_14_START (0)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_14_END (0)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_13_START (1)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_13_END (1)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_12_START (2)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_12_END (3)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_11_START (4)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_11_END (4)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_10_START (5)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_10_END (5)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_9_START (6)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_9_END (6)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_8_START (7)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_8_END (7)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_7_START (8)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_7_END (8)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_6_START (9)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_6_END (9)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_5_START (10)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_5_END (10)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_4_START (11)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_4_END (11)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_3_START (12)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_3_END (12)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_2_START (13)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_2_END (14)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_1_START (15)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_1_END (15)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_0_START (16)
#define SOC_DDR_PHY_AC_REV_REG_1_ac_rev_reg_1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_rev_reg_out_1 : 32;
    } reg;
} SOC_DDR_PHY_AC_REV_REG_OUT_1_UNION;
#endif
#define SOC_DDR_PHY_AC_REV_REG_OUT_1_ac_rev_reg_out_1_START (0)
#define SOC_DDR_PHY_AC_REV_REG_OUT_1_ac_rev_reg_out_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_ac_txadr_gcken : 1;
        unsigned int reg_ac_txcs_gcken : 1;
        unsigned int reg_ac_txcke_gcken : 1;
        unsigned int reg_ac_txck_gcken : 1;
        unsigned int reg_ac_txadr_phcfg : 2;
        unsigned int reg_ac_txcs_phcfg : 2;
        unsigned int reg_ac_txcke_phcfg : 2;
        unsigned int reg_ac_txck_phcfg : 2;
        unsigned int reg_ac_phcfg_auto : 1;
        unsigned int reg_ac_rx_gcken : 1;
        unsigned int reg_apb_static_reg_gcken : 1;
        unsigned int reg_pll_gate_auto_en : 1;
        unsigned int reg_pll_gate_timer : 8;
        unsigned int reg_8x_gcken : 1;
        unsigned int reserved : 4;
        unsigned int reg_ac_tx_cs_mask : 2;
        unsigned int reg_ac_tx_ck_mask : 1;
    } reg;
} SOC_DDR_PHY_AC_GCKEN_CTRL_UNION;
#endif
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txadr_gcken_START (0)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txadr_gcken_END (0)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcs_gcken_START (1)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcs_gcken_END (1)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcke_gcken_START (2)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcke_gcken_END (2)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txck_gcken_START (3)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txck_gcken_END (3)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txadr_phcfg_START (4)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txadr_phcfg_END (5)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcs_phcfg_START (6)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcs_phcfg_END (7)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcke_phcfg_START (8)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txcke_phcfg_END (9)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txck_phcfg_START (10)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_txck_phcfg_END (11)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_phcfg_auto_START (12)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_phcfg_auto_END (12)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_rx_gcken_START (13)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_rx_gcken_END (13)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_apb_static_reg_gcken_START (14)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_apb_static_reg_gcken_END (14)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_pll_gate_auto_en_START (15)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_pll_gate_auto_en_END (15)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_pll_gate_timer_START (16)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_pll_gate_timer_END (23)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_8x_gcken_START (24)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_8x_gcken_END (24)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_tx_cs_mask_START (29)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_tx_cs_mask_END (30)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_tx_ck_mask_START (31)
#define SOC_DDR_PHY_AC_GCKEN_CTRL_reg_ac_tx_ck_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_rev_reg_2_10 : 1;
        unsigned int ac_rev_reg_2_9 : 2;
        unsigned int ac_rev_reg_2_8 : 4;
        unsigned int ac_rev_reg_2_7 : 7;
        unsigned int ac_rev_reg_2_6 : 1;
        unsigned int ac_rev_reg_2_5 : 1;
        unsigned int ac_rev_reg_2_4 : 2;
        unsigned int ac_rev_reg_2_3 : 2;
        unsigned int ac_rev_reg_2_2 : 4;
        unsigned int ac_rev_reg_2_1 : 4;
        unsigned int ac_rev_reg_2_0 : 4;
    } reg;
} SOC_DDR_PHY_AC_REV_REG_2_UNION;
#endif
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_10_START (0)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_10_END (0)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_9_START (1)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_9_END (2)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_8_START (3)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_8_END (6)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_7_START (7)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_7_END (13)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_6_START (14)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_6_END (14)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_5_START (15)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_5_END (15)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_4_START (16)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_4_END (17)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_3_START (18)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_3_END (19)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_2_START (20)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_2_END (23)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_1_START (24)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_1_END (27)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_0_START (28)
#define SOC_DDR_PHY_AC_REV_REG_2_ac_rev_reg_2_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_rev_reg_out_2 : 32;
    } reg;
} SOC_DDR_PHY_AC_REV_REG_OUT_2_UNION;
#endif
#define SOC_DDR_PHY_AC_REV_REG_OUT_2_ac_rev_reg_out_2_START (0)
#define SOC_DDR_PHY_AC_REV_REG_OUT_2_ac_rev_reg_out_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST8_HSB : 8;
        unsigned int AC_RG_TEST9_HSB : 8;
        unsigned int AC_RG_TEST10_HSB : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_CTL3_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_AC_RG_TEST8_HSB_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_AC_RG_TEST8_HSB_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_AC_RG_TEST9_HSB_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_AC_RG_TEST9_HSB_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_AC_RG_TEST10_HSB_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL3_AC_RG_TEST10_HSB_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_SSC_r_div_frac_B_HSB : 16;
        unsigned int RG_SSC_r_div_frac_A_HSB : 16;
    } reg;
} SOC_DDR_PHY_AC_PLL_CTRL_A3B3_HSB_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_CTRL_A3B3_HSB_RG_SSC_r_div_frac_B_HSB_START (0)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3B3_HSB_RG_SSC_r_div_frac_B_HSB_END (15)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3B3_HSB_RG_SSC_r_div_frac_A_HSB_START (16)
#define SOC_DDR_PHY_AC_PLL_CTRL_A3B3_HSB_RG_SSC_r_div_frac_A_HSB_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST0_HSB : 8;
        unsigned int AC_RG_TEST1_HSB : 8;
        unsigned int AC_RG_TEST2_HSB : 8;
        unsigned int AC_RG_TEST3_HSB : 8;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST0_HSB_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST0_HSB_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST1_HSB_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST1_HSB_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST2_HSB_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST2_HSB_END (23)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST3_HSB_START (24)
#define SOC_DDR_PHY_AC_RG_TEST_CTL0_HSB_AC_RG_TEST3_HSB_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST4_HSB : 8;
        unsigned int AC_RG_TEST5_HSB : 8;
        unsigned int AC_RG_TEST6_HSB : 8;
        unsigned int AC_RG_TEST7_HSB : 8;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST4_HSB_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST4_HSB_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST5_HSB_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST5_HSB_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST6_HSB_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST6_HSB_END (23)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST7_HSB_START (24)
#define SOC_DDR_PHY_AC_RG_TEST_CTL1_HSB_AC_RG_TEST7_HSB_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_proc_ac_mux : 1;
        unsigned int fast_proc_ac_reg_ac_txadr_gcken : 1;
        unsigned int fast_proc_ac_reg_ac_txcs_gcken : 1;
        unsigned int fast_proc_ac_reg_ac_txcke_gcken : 1;
        unsigned int fast_proc_ac_reg_ac_txck_gcken : 1;
        unsigned int fast_proc_ac_reg_ac_rx_gcken : 1;
        unsigned int fast_proc_ac_reg_8x_gcken : 1;
        unsigned int fast_proc_ac_phyclk_gate_en : 1;
        unsigned int fast_proc_ac_pll_gate_en : 1;
        unsigned int fast_proc_ac_pll_gate_woph : 1;
        unsigned int fast_proc_ac_rg_tx_cke_en : 1;
        unsigned int fast_proc_ac_rg_tx_en : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_PHY_AC_FAST_PROC_UNION;
#endif
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_mux_START (0)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_mux_END (0)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txadr_gcken_START (1)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txadr_gcken_END (1)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txcs_gcken_START (2)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txcs_gcken_END (2)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txcke_gcken_START (3)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txcke_gcken_END (3)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txck_gcken_START (4)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_txck_gcken_END (4)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_rx_gcken_START (5)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_ac_rx_gcken_END (5)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_8x_gcken_START (6)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_reg_8x_gcken_END (6)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_phyclk_gate_en_START (7)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_phyclk_gate_en_END (7)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_pll_gate_en_START (8)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_pll_gate_en_END (8)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_pll_gate_woph_START (9)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_pll_gate_woph_END (9)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_rg_tx_cke_en_START (10)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_rg_tx_cke_en_END (10)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_rg_tx_en_START (11)
#define SOC_DDR_PHY_AC_FAST_PROC_fast_proc_ac_rg_tx_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST0_NSV : 8;
        unsigned int AC_RG_TEST1_NSV : 8;
        unsigned int AC_RG_TEST2_NSV : 8;
        unsigned int AC_RG_TEST3_NSV : 8;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_NSV0_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST0_NSV_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST0_NSV_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST1_NSV_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST1_NSV_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST2_NSV_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST2_NSV_END (23)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST3_NSV_START (24)
#define SOC_DDR_PHY_AC_RG_TEST_NSV0_AC_RG_TEST3_NSV_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST4_NSV : 8;
        unsigned int AC_RG_TEST5_NSV : 8;
        unsigned int AC_RG_TEST6_NSV : 8;
        unsigned int AC_RG_TEST7_NSV : 8;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_NSV1_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST4_NSV_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST4_NSV_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST5_NSV_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST5_NSV_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST6_NSV_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST6_NSV_END (23)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST7_NSV_START (24)
#define SOC_DDR_PHY_AC_RG_TEST_NSV1_AC_RG_TEST7_NSV_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST8_NSV : 8;
        unsigned int AC_RG_TEST9_NSV : 8;
        unsigned int AC_RG_TEST10_NSV : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_PHY_AC_RG_TEST_NSV2_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_AC_RG_TEST8_NSV_START (0)
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_AC_RG_TEST8_NSV_END (7)
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_AC_RG_TEST9_NSV_START (8)
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_AC_RG_TEST9_NSV_END (15)
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_AC_RG_TEST10_NSV_START (16)
#define SOC_DDR_PHY_AC_RG_TEST_NSV2_AC_RG_TEST10_NSV_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_BHS_DEC_CFG_ADDR : 12;
        unsigned int AC_RG_BHS_DEC_CFG_CS : 4;
        unsigned int AC_RG_BHS_DEC_CFG_CK : 2;
        unsigned int AC_DA_BHS_PR_EN : 1;
        unsigned int AC_DA_BHS_EN : 1;
        unsigned int AC_AD_BHS_REQ : 1;
        unsigned int AC_AD_BHS_PR : 9;
        unsigned int AC_AD_LDO_PR : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PHY_AC_RG_BHS_CTL_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_RG_BHS_DEC_CFG_ADDR_START (0)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_RG_BHS_DEC_CFG_ADDR_END (11)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_RG_BHS_DEC_CFG_CS_START (12)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_RG_BHS_DEC_CFG_CS_END (15)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_RG_BHS_DEC_CFG_CK_START (16)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_RG_BHS_DEC_CFG_CK_END (17)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_DA_BHS_PR_EN_START (18)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_DA_BHS_PR_EN_END (18)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_DA_BHS_EN_START (19)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_DA_BHS_EN_END (19)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_AD_BHS_REQ_START (20)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_AD_BHS_REQ_END (20)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_AD_BHS_PR_START (21)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_AD_BHS_PR_END (29)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_AD_LDO_PR_START (30)
#define SOC_DDR_PHY_AC_RG_BHS_CTL_AC_AD_LDO_PR_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_ATB_TEST_CK : 3;
        unsigned int AC_DA_GATE_EN : 1;
        unsigned int AC_DA_RDQS_EN : 1;
        unsigned int AC_AD_DLL_PR : 1;
        unsigned int AC_AD_RSV_OUT : 8;
        unsigned int AC_AD_BHS_DIS_ACK : 9;
        unsigned int ocldo_pr_delay_cfg : 8;
        unsigned int ocldo_pr_delay_bypass : 1;
    } reg;
} SOC_DDR_PHY_AC_RG_PHCFG_CTL_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_RG_ATB_TEST_CK_START (0)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_RG_ATB_TEST_CK_END (2)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_DA_GATE_EN_START (3)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_DA_GATE_EN_END (3)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_DA_RDQS_EN_START (4)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_DA_RDQS_EN_END (4)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_AD_DLL_PR_START (5)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_AD_DLL_PR_END (5)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_AD_RSV_OUT_START (6)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_AD_RSV_OUT_END (13)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_AD_BHS_DIS_ACK_START (14)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_AC_AD_BHS_DIS_ACK_END (22)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_ocldo_pr_delay_cfg_START (23)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_ocldo_pr_delay_cfg_END (30)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_ocldo_pr_delay_bypass_START (31)
#define SOC_DDR_PHY_AC_RG_PHCFG_CTL_ocldo_pr_delay_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_LDO_PR_DEC_CFG : 2;
        unsigned int AC_RG_LDO_CUR_COMP_SR : 3;
        unsigned int AC_RG_LDO_CUR_COMP_SLICE : 4;
        unsigned int AC_RG_LDO_CUR_COMP_EN : 1;
        unsigned int AC_RG_LDO_R_BIAS_ADJ : 6;
        unsigned int AC_RG_LDO_FVF2_BIAS_ADJ : 2;
        unsigned int AC_RG_LDO_FVF2_EN : 1;
        unsigned int AC_RG_LDO_SRE_EN : 1;
        unsigned int AC_RG_LDO_FVF_BIAS_ADJ : 2;
        unsigned int AC_RG_LDO_REG_BIAS_ADJ : 2;
        unsigned int AC_RG_LDO_COM_CAP_ADJ : 2;
        unsigned int AC_RG_LDO_VOUT_ADJ : 3;
        unsigned int AC_DA_LDO_LP_EN : 1;
        unsigned int AC_DA_LDO_BYPASS : 1;
        unsigned int AC_DA_LDO_EN : 1;
    } reg;
} SOC_DDR_PHY_AC_RG_LDO_CTL_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_PR_DEC_CFG_START (0)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_PR_DEC_CFG_END (1)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_CUR_COMP_SR_START (2)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_CUR_COMP_SR_END (4)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_CUR_COMP_SLICE_START (5)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_CUR_COMP_SLICE_END (8)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_CUR_COMP_EN_START (9)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_CUR_COMP_EN_END (9)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_R_BIAS_ADJ_START (10)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_R_BIAS_ADJ_END (15)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_FVF2_BIAS_ADJ_START (16)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_FVF2_BIAS_ADJ_END (17)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_FVF2_EN_START (18)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_FVF2_EN_END (18)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_SRE_EN_START (19)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_SRE_EN_END (19)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_FVF_BIAS_ADJ_START (20)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_FVF_BIAS_ADJ_END (21)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_REG_BIAS_ADJ_START (22)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_REG_BIAS_ADJ_END (23)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_COM_CAP_ADJ_START (24)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_COM_CAP_ADJ_END (25)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_VOUT_ADJ_START (26)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_RG_LDO_VOUT_ADJ_END (28)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_DA_LDO_LP_EN_START (29)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_DA_LDO_LP_EN_END (29)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_DA_LDO_BYPASS_START (30)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_DA_LDO_BYPASS_END (30)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_DA_LDO_EN_START (31)
#define SOC_DDR_PHY_AC_RG_LDO_CTL_AC_DA_LDO_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_RG_TEST_COMMON : 13;
        unsigned int ac_ph_gck_tgval_0 : 1;
        unsigned int ac_ph_gck_tgval_1 : 1;
        unsigned int AC_DA_ANTIAGING_EN : 1;
        unsigned int AC_RG_TEST_DLM : 2;
        unsigned int AC_RG_TEST_DLL : 2;
        unsigned int AC_RG_DLL_DIV : 3;
        unsigned int AC_RG_BUF_EN_D : 1;
        unsigned int AC_RG_BUF_EN_C : 1;
        unsigned int AC_RG_BUF_EN_B : 1;
        unsigned int AC_RG_BUF_EN_A : 1;
        unsigned int AC_DA_LDO_PR_EN : 1;
        unsigned int dll_dlm_sel : 2;
        unsigned int bhs_8x_gcken_bypass : 1;
        unsigned int bhs_8x_txrxen_bypass : 1;
    } reg;
} SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_TEST_COMMON_START (0)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_TEST_COMMON_END (12)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_ac_ph_gck_tgval_0_START (13)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_ac_ph_gck_tgval_0_END (13)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_ac_ph_gck_tgval_1_START (14)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_ac_ph_gck_tgval_1_END (14)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_DA_ANTIAGING_EN_START (15)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_DA_ANTIAGING_EN_END (15)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_TEST_DLM_START (16)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_TEST_DLM_END (17)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_TEST_DLL_START (18)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_TEST_DLL_END (19)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_DLL_DIV_START (20)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_DLL_DIV_END (22)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_D_START (23)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_D_END (23)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_C_START (24)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_C_END (24)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_B_START (25)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_B_END (25)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_A_START (26)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_RG_BUF_EN_A_END (26)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_DA_LDO_PR_EN_START (27)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_AC_DA_LDO_PR_EN_END (27)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_dll_dlm_sel_START (28)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_dll_dlm_sel_END (29)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_bhs_8x_gcken_bypass_START (30)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_bhs_8x_gcken_bypass_END (30)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_bhs_8x_txrxen_bypass_START (31)
#define SOC_DDR_PHY_AC_RG_BIT_COMMON_CTL_bhs_8x_txrxen_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_KBAND_LOAD_SEL_A : 1;
        unsigned int RG_TARG_CNT_A : 9;
        unsigned int RG_FAST_CAL_EN_A : 1;
        unsigned int RG_COARSE_BANK_A : 9;
        unsigned int RG_CLK_TEST_SEL_A : 3;
        unsigned int RG_CLK_TEST_EN_A : 1;
        unsigned int RG_GCNT_DIV_A : 2;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_KBAND_LOAD_SEL_A_START (0)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_KBAND_LOAD_SEL_A_END (0)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_TARG_CNT_A_START (1)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_TARG_CNT_A_END (9)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_FAST_CAL_EN_A_START (10)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_FAST_CAL_EN_A_END (10)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_COARSE_BANK_A_START (11)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_COARSE_BANK_A_END (19)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_CLK_TEST_SEL_A_START (20)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_CLK_TEST_SEL_A_END (22)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_CLK_TEST_EN_A_START (23)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_CLK_TEST_EN_A_END (23)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_GCNT_DIV_A_START (24)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_A_RG_GCNT_DIV_A_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_KBAND_LOAD_SEL_B : 1;
        unsigned int RG_TARG_CNT_B : 9;
        unsigned int RG_FAST_CAL_EN_B : 1;
        unsigned int RG_COARSE_BANK_B : 9;
        unsigned int RG_CLK_TEST_SEL_B : 3;
        unsigned int RG_CLK_TEST_EN_B : 1;
        unsigned int RG_GCNT_DIV_B : 2;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_KBAND_LOAD_SEL_B_START (0)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_KBAND_LOAD_SEL_B_END (0)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_TARG_CNT_B_START (1)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_TARG_CNT_B_END (9)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_FAST_CAL_EN_B_START (10)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_FAST_CAL_EN_B_END (10)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_COARSE_BANK_B_START (11)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_COARSE_BANK_B_END (19)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_CLK_TEST_SEL_B_START (20)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_CLK_TEST_SEL_B_END (22)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_CLK_TEST_EN_B_START (23)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_CLK_TEST_EN_B_END (23)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_GCNT_DIV_B_START (24)
#define SOC_DDR_PHY_AC_RG_NSV_PLL_CAL_B_RG_GCNT_DIV_B_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_FLL_PREDIV_CTRL : 1;
        unsigned int reserved_0 : 2;
        unsigned int RG_FLL_PD : 1;
        unsigned int RG_FLL_LOCKDET_RSTN : 1;
        unsigned int RG_FLL_LOCKDET_CTRL : 8;
        unsigned int RG_FLL_FBDIV_CTRL : 3;
        unsigned int RG_FLL_EN : 1;
        unsigned int RG_FLL_OUT_EN : 1;
        unsigned int RG_FLL_ICP_CTRL : 1;
        unsigned int RG_PLL_TESTBUF_IOUT_EN : 1;
        unsigned int RG_PLL_TESTBUF_DIV : 1;
        unsigned int RG_PLL_TESTBUF_CLK_SEL : 1;
        unsigned int RG_PLL_TESTBUF_CLKOUT_EN : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_PREDIV_CTRL_START (0)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_PREDIV_CTRL_END (0)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_PD_START (3)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_PD_END (3)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_LOCKDET_RSTN_START (4)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_LOCKDET_RSTN_END (4)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_LOCKDET_CTRL_START (5)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_LOCKDET_CTRL_END (12)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_FBDIV_CTRL_START (13)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_FBDIV_CTRL_END (15)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_EN_START (16)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_EN_END (16)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_OUT_EN_START (17)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_OUT_EN_END (17)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_ICP_CTRL_START (18)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_FLL_ICP_CTRL_END (18)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_IOUT_EN_START (19)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_IOUT_EN_END (19)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_DIV_START (20)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_DIV_END (20)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_CLK_SEL_START (21)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_CLK_SEL_END (21)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_CLKOUT_EN_START (22)
#define SOC_DDR_PHY_AC_RG_NSV_FLL_CTL_RG_PLL_TESTBUF_CLKOUT_EN_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_PLL_RESERVE_A : 8;
        unsigned int RG_KBAND_FBK_CNT_A : 9;
        unsigned int RG_LDO_CTRL_A : 2;
        unsigned int RG_KBAND_SEAECH_RANGE_A : 1;
        unsigned int RG_KBAND_FINE_PREC_A : 3;
        unsigned int RG_IBAND_CUR_CTRL_A : 2;
        unsigned int RG_FVF_ENB_A : 2;
        unsigned int RG_KBAND_RST_CYCLE_A : 2;
        unsigned int RG_BIAS_SEL_A : 1;
        unsigned int RG_IBAND_TEST_EN_A : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_PLL_RESERVE_A_START (0)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_PLL_RESERVE_A_END (7)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_FBK_CNT_A_START (8)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_FBK_CNT_A_END (16)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_LDO_CTRL_A_START (17)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_LDO_CTRL_A_END (18)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_SEAECH_RANGE_A_START (19)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_SEAECH_RANGE_A_END (19)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_FINE_PREC_A_START (20)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_FINE_PREC_A_END (22)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_IBAND_CUR_CTRL_A_START (23)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_IBAND_CUR_CTRL_A_END (24)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_FVF_ENB_A_START (25)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_FVF_ENB_A_END (26)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_RST_CYCLE_A_START (27)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_KBAND_RST_CYCLE_A_END (28)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_BIAS_SEL_A_START (29)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_BIAS_SEL_A_END (29)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_IBAND_TEST_EN_A_START (30)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_A_RG_IBAND_TEST_EN_A_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_PLL_RESERVE_B : 8;
        unsigned int RG_KBAND_FBK_CNT_B : 9;
        unsigned int RG_LDO_CTRL_B : 2;
        unsigned int RG_KBAND_SEAECH_RANGE_B : 1;
        unsigned int RG_KBAND_FINE_PREC_B : 3;
        unsigned int RG_IBAND_CUR_CTRL_B : 2;
        unsigned int RG_FVF_ENB_B : 2;
        unsigned int RG_KBAND_RST_CYCLE_B : 2;
        unsigned int RG_BIAS_SEL_B : 1;
        unsigned int RG_IBAND_TEST_EN_B : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_UNION;
#endif
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_PLL_RESERVE_B_START (0)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_PLL_RESERVE_B_END (7)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_FBK_CNT_B_START (8)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_FBK_CNT_B_END (16)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_LDO_CTRL_B_START (17)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_LDO_CTRL_B_END (18)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_SEAECH_RANGE_B_START (19)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_SEAECH_RANGE_B_END (19)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_FINE_PREC_B_START (20)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_FINE_PREC_B_END (22)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_IBAND_CUR_CTRL_B_START (23)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_IBAND_CUR_CTRL_B_END (24)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_FVF_ENB_B_START (25)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_FVF_ENB_B_END (26)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_RST_CYCLE_B_START (27)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_KBAND_RST_CYCLE_B_END (28)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_BIAS_SEL_B_START (29)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_BIAS_SEL_B_END (29)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_IBAND_TEST_EN_B_START (30)
#define SOC_DDR_PHY_AC_RG_NSV_KBAND_CTL_B_RG_IBAND_TEST_EN_B_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_DA_BDLSEL_DQS : 2;
        unsigned int AC_DA_BDLSEL_DQ : 2;
        unsigned int AC_DA_PHASE_INVERSE_DQS_EN : 1;
        unsigned int AC_DA_PHASE_INVERSE_DQ_EN : 10;
        unsigned int AC_DA_PHASE_DELAY_DQ_EN : 10;
        unsigned int sync_sel_b1 : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_PHY_AC_DA_PHASE_CTRL_UNION;
#endif
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_BDLSEL_DQS_START (0)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_BDLSEL_DQS_END (1)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_BDLSEL_DQ_START (2)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_BDLSEL_DQ_END (3)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_PHASE_INVERSE_DQS_EN_START (4)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_PHASE_INVERSE_DQS_EN_END (4)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_PHASE_INVERSE_DQ_EN_START (5)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_PHASE_INVERSE_DQ_EN_END (14)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_PHASE_DELAY_DQ_EN_START (15)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_AC_DA_PHASE_DELAY_DQ_EN_END (24)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_sync_sel_b1_START (25)
#define SOC_DDR_PHY_AC_DA_PHASE_CTRL_sync_sel_b1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AD_RGS_TARG_CNT_A : 9;
        unsigned int AD_RGS_GCNT_SUM_A : 9;
        unsigned int AD_PLL_RELEASE_A : 8;
        unsigned int AD_KBAND_INIT_CNT_A : 4;
        unsigned int AD_FLL_LOCK : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PHY_AC_PLL_DBG_A_2_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_RGS_TARG_CNT_A_START (0)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_RGS_TARG_CNT_A_END (8)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_RGS_GCNT_SUM_A_START (9)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_RGS_GCNT_SUM_A_END (17)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_PLL_RELEASE_A_START (18)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_PLL_RELEASE_A_END (25)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_KBAND_INIT_CNT_A_START (26)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_KBAND_INIT_CNT_A_END (29)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_FLL_LOCK_START (30)
#define SOC_DDR_PHY_AC_PLL_DBG_A_2_AD_FLL_LOCK_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AD_RGS_TARG_CNT_B : 9;
        unsigned int AD_RGS_GCNT_SUM_B : 9;
        unsigned int AD_PLL_RELEASE_B : 8;
        unsigned int AD_KBAND_INIT_CNT_B : 4;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_AC_PLL_DBG_B_2_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_RGS_TARG_CNT_B_START (0)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_RGS_TARG_CNT_B_END (8)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_RGS_GCNT_SUM_B_START (9)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_RGS_GCNT_SUM_B_END (17)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_PLL_RELEASE_B_START (18)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_PLL_RELEASE_B_END (25)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_KBAND_INIT_CNT_B_START (26)
#define SOC_DDR_PHY_AC_PLL_DBG_B_2_AD_KBAND_INIT_CNT_B_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AD_PLL_DAPD_OUT_A : 12;
        unsigned int AD_FINE_BAND_A : 2;
        unsigned int AD_COARSE_BAND_A : 9;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_PHY_AC_PLL_DBG_A2_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_DBG_A2_AD_PLL_DAPD_OUT_A_START (0)
#define SOC_DDR_PHY_AC_PLL_DBG_A2_AD_PLL_DAPD_OUT_A_END (11)
#define SOC_DDR_PHY_AC_PLL_DBG_A2_AD_FINE_BAND_A_START (12)
#define SOC_DDR_PHY_AC_PLL_DBG_A2_AD_FINE_BAND_A_END (13)
#define SOC_DDR_PHY_AC_PLL_DBG_A2_AD_COARSE_BAND_A_START (14)
#define SOC_DDR_PHY_AC_PLL_DBG_A2_AD_COARSE_BAND_A_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AD_PLL_DAPD_OUT_B : 12;
        unsigned int AD_FINE_BAND_B : 2;
        unsigned int AD_COARSE_BAND_B : 9;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_PHY_AC_PLL_DBG_B2_UNION;
#endif
#define SOC_DDR_PHY_AC_PLL_DBG_B2_AD_PLL_DAPD_OUT_B_START (0)
#define SOC_DDR_PHY_AC_PLL_DBG_B2_AD_PLL_DAPD_OUT_B_END (11)
#define SOC_DDR_PHY_AC_PLL_DBG_B2_AD_FINE_BAND_B_START (12)
#define SOC_DDR_PHY_AC_PLL_DBG_B2_AD_FINE_BAND_B_END (13)
#define SOC_DDR_PHY_AC_PLL_DBG_B2_AD_COARSE_BAND_B_START (14)
#define SOC_DDR_PHY_AC_PLL_DBG_B2_AD_COARSE_BAND_B_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_lpbk_exd : 3;
        unsigned int ac_lpbk_ie_en : 1;
        unsigned int cfg_ssdr_demux_en : 1;
        unsigned int cfg_ssdr_phase_inv : 1;
        unsigned int cfg_ssdr_pclk_bypass : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_PHY_AC_LPBK_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_AC_LPBK_CTRL2_ac_lpbk_exd_START (0)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_ac_lpbk_exd_END (2)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_ac_lpbk_ie_en_START (3)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_ac_lpbk_ie_en_END (3)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_cfg_ssdr_demux_en_START (4)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_cfg_ssdr_demux_en_END (4)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_cfg_ssdr_phase_inv_START (5)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_cfg_ssdr_phase_inv_END (5)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_cfg_ssdr_pclk_bypass_START (6)
#define SOC_DDR_PHY_AC_LPBK_CTRL2_cfg_ssdr_pclk_bypass_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AC_IO_MODE0_ext : 1;
        unsigned int AC_IO_MODE1_ext : 1;
        unsigned int AC_IO_MODE2_ext : 1;
        unsigned int AC_IO_MODE3_ext : 1;
        unsigned int AC_IO_MODE4_ext : 1;
        unsigned int AC_IO_MODE5_ext : 1;
        unsigned int AC_IO_MODE6_ext : 1;
        unsigned int AC_IO_MODE7_ext : 1;
        unsigned int AC_IO_MODE8_ext : 1;
        unsigned int AC_IO_MODE9_ext : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PHY_AC_IOMODE_EXT_UNION;
#endif
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE0_ext_START (0)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE0_ext_END (0)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE1_ext_START (1)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE1_ext_END (1)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE2_ext_START (2)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE2_ext_END (2)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE3_ext_START (3)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE3_ext_END (3)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE4_ext_START (4)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE4_ext_END (4)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE5_ext_START (5)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE5_ext_END (5)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE6_ext_START (6)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE6_ext_END (6)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE7_ext_START (7)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE7_ext_END (7)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE8_ext_START (8)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE8_ext_END (8)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE9_ext_START (9)
#define SOC_DDR_PHY_AC_IOMODE_EXT_AC_IO_MODE9_ext_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_SSDR_MODE : 1;
        unsigned int RG_CLK4X_EN : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_PHY_SSDR_CFG_UNION;
#endif
#define SOC_DDR_PHY_SSDR_CFG_RG_SSDR_MODE_START (0)
#define SOC_DDR_PHY_SSDR_CFG_RG_SSDR_MODE_END (0)
#define SOC_DDR_PHY_SSDR_CFG_RG_CLK4X_EN_START (1)
#define SOC_DDR_PHY_SSDR_CFG_RG_CLK4X_EN_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swift_trk_ca_glitch_mask_en : 1;
        unsigned int swift_trk_ckecs_glitch_mask_en : 1;
        unsigned int swift_trk_ck_glitch_mask_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_PHY_SWIFT_TRK_CFG_UNION;
#endif
#define SOC_DDR_PHY_SWIFT_TRK_CFG_swift_trk_ca_glitch_mask_en_START (0)
#define SOC_DDR_PHY_SWIFT_TRK_CFG_swift_trk_ca_glitch_mask_en_END (0)
#define SOC_DDR_PHY_SWIFT_TRK_CFG_swift_trk_ckecs_glitch_mask_en_START (1)
#define SOC_DDR_PHY_SWIFT_TRK_CFG_swift_trk_ckecs_glitch_mask_en_END (1)
#define SOC_DDR_PHY_SWIFT_TRK_CFG_swift_trk_ck_glitch_mask_en_START (2)
#define SOC_DDR_PHY_SWIFT_TRK_CFG_swift_trk_ck_glitch_mask_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_PTX : 2;
        unsigned int gds_improve_bypass : 1;
        unsigned int trx_reserved : 1;
        unsigned int gcken_dx_phy_dyn_track_auto : 1;
        unsigned int rxdqs_inv_b0 : 1;
        unsigned int rxdqs_inv_b1 : 1;
        unsigned int cfg_gcken_dx_phy_dyn_track : 1;
        unsigned int cfg_upd_duty_mode : 4;
        unsigned int wdqs_single_mode : 1;
        unsigned int wr_pst_en : 1;
        unsigned int lp5wck_ie_gate : 1;
        unsigned int wr_pre_en : 2;
        unsigned int cfg_upd_track_gate_margin_en : 1;
        unsigned int cfg_upd_track_dq_margin_en : 1;
        unsigned int cfg_dyn_update_count_val : 3;
        unsigned int cfg_rank0_only : 1;
        unsigned int tx_dqs_inv_b0 : 1;
        unsigned int tx_dqs_inv_b1 : 1;
        unsigned int pll_switch : 2;
        unsigned int dll_in_sel : 2;
        unsigned int reg_dcc_track_rank_en : 1;
        unsigned int dqsg_track_flag_valid_en : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_PHY_DXCTRL_TRX0_UNION;
#endif
#define SOC_DDR_PHY_DXCTRL_TRX0_DX_RG_PTX_START (0)
#define SOC_DDR_PHY_DXCTRL_TRX0_DX_RG_PTX_END (1)
#define SOC_DDR_PHY_DXCTRL_TRX0_gds_improve_bypass_START (2)
#define SOC_DDR_PHY_DXCTRL_TRX0_gds_improve_bypass_END (2)
#define SOC_DDR_PHY_DXCTRL_TRX0_trx_reserved_START (3)
#define SOC_DDR_PHY_DXCTRL_TRX0_trx_reserved_END (3)
#define SOC_DDR_PHY_DXCTRL_TRX0_gcken_dx_phy_dyn_track_auto_START (4)
#define SOC_DDR_PHY_DXCTRL_TRX0_gcken_dx_phy_dyn_track_auto_END (4)
#define SOC_DDR_PHY_DXCTRL_TRX0_rxdqs_inv_b0_START (5)
#define SOC_DDR_PHY_DXCTRL_TRX0_rxdqs_inv_b0_END (5)
#define SOC_DDR_PHY_DXCTRL_TRX0_rxdqs_inv_b1_START (6)
#define SOC_DDR_PHY_DXCTRL_TRX0_rxdqs_inv_b1_END (6)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_gcken_dx_phy_dyn_track_START (7)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_gcken_dx_phy_dyn_track_END (7)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_upd_duty_mode_START (8)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_upd_duty_mode_END (11)
#define SOC_DDR_PHY_DXCTRL_TRX0_wdqs_single_mode_START (12)
#define SOC_DDR_PHY_DXCTRL_TRX0_wdqs_single_mode_END (12)
#define SOC_DDR_PHY_DXCTRL_TRX0_wr_pst_en_START (13)
#define SOC_DDR_PHY_DXCTRL_TRX0_wr_pst_en_END (13)
#define SOC_DDR_PHY_DXCTRL_TRX0_lp5wck_ie_gate_START (14)
#define SOC_DDR_PHY_DXCTRL_TRX0_lp5wck_ie_gate_END (14)
#define SOC_DDR_PHY_DXCTRL_TRX0_wr_pre_en_START (15)
#define SOC_DDR_PHY_DXCTRL_TRX0_wr_pre_en_END (16)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_upd_track_gate_margin_en_START (17)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_upd_track_gate_margin_en_END (17)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_upd_track_dq_margin_en_START (18)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_upd_track_dq_margin_en_END (18)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_dyn_update_count_val_START (19)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_dyn_update_count_val_END (21)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_rank0_only_START (22)
#define SOC_DDR_PHY_DXCTRL_TRX0_cfg_rank0_only_END (22)
#define SOC_DDR_PHY_DXCTRL_TRX0_tx_dqs_inv_b0_START (23)
#define SOC_DDR_PHY_DXCTRL_TRX0_tx_dqs_inv_b0_END (23)
#define SOC_DDR_PHY_DXCTRL_TRX0_tx_dqs_inv_b1_START (24)
#define SOC_DDR_PHY_DXCTRL_TRX0_tx_dqs_inv_b1_END (24)
#define SOC_DDR_PHY_DXCTRL_TRX0_pll_switch_START (25)
#define SOC_DDR_PHY_DXCTRL_TRX0_pll_switch_END (26)
#define SOC_DDR_PHY_DXCTRL_TRX0_dll_in_sel_START (27)
#define SOC_DDR_PHY_DXCTRL_TRX0_dll_in_sel_END (28)
#define SOC_DDR_PHY_DXCTRL_TRX0_reg_dcc_track_rank_en_START (29)
#define SOC_DDR_PHY_DXCTRL_TRX0_reg_dcc_track_rank_en_END (29)
#define SOC_DDR_PHY_DXCTRL_TRX0_dqsg_track_flag_valid_en_START (30)
#define SOC_DDR_PHY_DXCTRL_TRX0_dqsg_track_flag_valid_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dxctl_rx_en : 12;
        unsigned int dqs_oe_extend : 3;
        unsigned int DX_RG_TX_EN : 11;
        unsigned int dq_oe_extend : 3;
        unsigned int DX_IO_RXMODE_3_5 : 3;
    } reg;
} SOC_DDR_PHY_DXCTRL_TRX1_UNION;
#endif
#define SOC_DDR_PHY_DXCTRL_TRX1_dxctl_rx_en_START (0)
#define SOC_DDR_PHY_DXCTRL_TRX1_dxctl_rx_en_END (11)
#define SOC_DDR_PHY_DXCTRL_TRX1_dqs_oe_extend_START (12)
#define SOC_DDR_PHY_DXCTRL_TRX1_dqs_oe_extend_END (14)
#define SOC_DDR_PHY_DXCTRL_TRX1_DX_RG_TX_EN_START (15)
#define SOC_DDR_PHY_DXCTRL_TRX1_DX_RG_TX_EN_END (25)
#define SOC_DDR_PHY_DXCTRL_TRX1_dq_oe_extend_START (26)
#define SOC_DDR_PHY_DXCTRL_TRX1_dq_oe_extend_END (28)
#define SOC_DDR_PHY_DXCTRL_TRX1_DX_IO_RXMODE_3_5_START (29)
#define SOC_DDR_PHY_DXCTRL_TRX1_DX_IO_RXMODE_3_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dxctl_rx_bypass_en : 9;
        unsigned int DX_IO_DQ_VREF_EN : 1;
        unsigned int DX_IO_DQS_VREF_EN : 1;
        unsigned int DX_IO_WCK_VREF_EN : 1;
        unsigned int dxctl_wren_rank_phase_offset : 4;
        unsigned int dxctl_wren_rank_mask_offset : 4;
        unsigned int DX_BIAS_EN : 12;
    } reg;
} SOC_DDR_PHY_DXCTL_BYPASS_UNION;
#endif
#define SOC_DDR_PHY_DXCTL_BYPASS_dxctl_rx_bypass_en_START (0)
#define SOC_DDR_PHY_DXCTL_BYPASS_dxctl_rx_bypass_en_END (8)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_IO_DQ_VREF_EN_START (9)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_IO_DQ_VREF_EN_END (9)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_IO_DQS_VREF_EN_START (10)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_IO_DQS_VREF_EN_END (10)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_IO_WCK_VREF_EN_START (11)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_IO_WCK_VREF_EN_END (11)
#define SOC_DDR_PHY_DXCTL_BYPASS_dxctl_wren_rank_phase_offset_START (12)
#define SOC_DDR_PHY_DXCTL_BYPASS_dxctl_wren_rank_phase_offset_END (15)
#define SOC_DDR_PHY_DXCTL_BYPASS_dxctl_wren_rank_mask_offset_START (16)
#define SOC_DDR_PHY_DXCTL_BYPASS_dxctl_wren_rank_mask_offset_END (19)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_BIAS_EN_START (20)
#define SOC_DDR_PHY_DXCTL_BYPASS_DX_BIAS_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_DQS_RG_EQ_C : 5;
        unsigned int reg_WCK_RG_EQ_C : 5;
        unsigned int reserved : 1;
        unsigned int dxctl_rx_ie_extend : 4;
        unsigned int reg_DQS_RG_EQ_RP : 6;
        unsigned int reg_WCK_RG_EQ_RP : 6;
        unsigned int ie_extend : 5;
    } reg;
} SOC_DDR_PHY_DX_IECTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_IECTRL0_reg_DQS_RG_EQ_C_START (0)
#define SOC_DDR_PHY_DX_IECTRL0_reg_DQS_RG_EQ_C_END (4)
#define SOC_DDR_PHY_DX_IECTRL0_reg_WCK_RG_EQ_C_START (5)
#define SOC_DDR_PHY_DX_IECTRL0_reg_WCK_RG_EQ_C_END (9)
#define SOC_DDR_PHY_DX_IECTRL0_dxctl_rx_ie_extend_START (11)
#define SOC_DDR_PHY_DX_IECTRL0_dxctl_rx_ie_extend_END (14)
#define SOC_DDR_PHY_DX_IECTRL0_reg_DQS_RG_EQ_RP_START (15)
#define SOC_DDR_PHY_DX_IECTRL0_reg_DQS_RG_EQ_RP_END (20)
#define SOC_DDR_PHY_DX_IECTRL0_reg_WCK_RG_EQ_RP_START (21)
#define SOC_DDR_PHY_DX_IECTRL0_reg_WCK_RG_EQ_RP_END (26)
#define SOC_DDR_PHY_DX_IECTRL0_ie_extend_START (27)
#define SOC_DDR_PHY_DX_IECTRL0_ie_extend_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_SE_CLKD_4_7 : 4;
        unsigned int DX_RX_PRESET_DQ : 2;
        unsigned int reserved_0 : 1;
        unsigned int DX_IE_SEL_11 : 1;
        unsigned int DX_SE_CLKD : 4;
        unsigned int DX_IO_TXMODE_2_3 : 2;
        unsigned int reserved_1 : 1;
        unsigned int DX_RG_TX_EN_11 : 1;
        unsigned int reg_DA_PREAM_TM_WCK : 2;
        unsigned int reserved_2 : 1;
        unsigned int refsel_table_sel : 1;
        unsigned int dummy_oe_aux : 1;
        unsigned int reg_DA_PREAM_TM_DQS : 2;
        unsigned int reg_dx_lpbk_sel_dmy : 1;
        unsigned int dxctl_wck_rank_phase_offset : 4;
        unsigned int dxctl_wck_rank_mask_offset : 4;
    } reg;
} SOC_DDR_PHY_DX_RX_SET_UNION;
#endif
#define SOC_DDR_PHY_DX_RX_SET_DX_SE_CLKD_4_7_START (0)
#define SOC_DDR_PHY_DX_RX_SET_DX_SE_CLKD_4_7_END (3)
#define SOC_DDR_PHY_DX_RX_SET_DX_RX_PRESET_DQ_START (4)
#define SOC_DDR_PHY_DX_RX_SET_DX_RX_PRESET_DQ_END (5)
#define SOC_DDR_PHY_DX_RX_SET_DX_IE_SEL_11_START (7)
#define SOC_DDR_PHY_DX_RX_SET_DX_IE_SEL_11_END (7)
#define SOC_DDR_PHY_DX_RX_SET_DX_SE_CLKD_START (8)
#define SOC_DDR_PHY_DX_RX_SET_DX_SE_CLKD_END (11)
#define SOC_DDR_PHY_DX_RX_SET_DX_IO_TXMODE_2_3_START (12)
#define SOC_DDR_PHY_DX_RX_SET_DX_IO_TXMODE_2_3_END (13)
#define SOC_DDR_PHY_DX_RX_SET_DX_RG_TX_EN_11_START (15)
#define SOC_DDR_PHY_DX_RX_SET_DX_RG_TX_EN_11_END (15)
#define SOC_DDR_PHY_DX_RX_SET_reg_DA_PREAM_TM_WCK_START (16)
#define SOC_DDR_PHY_DX_RX_SET_reg_DA_PREAM_TM_WCK_END (17)
#define SOC_DDR_PHY_DX_RX_SET_refsel_table_sel_START (19)
#define SOC_DDR_PHY_DX_RX_SET_refsel_table_sel_END (19)
#define SOC_DDR_PHY_DX_RX_SET_dummy_oe_aux_START (20)
#define SOC_DDR_PHY_DX_RX_SET_dummy_oe_aux_END (20)
#define SOC_DDR_PHY_DX_RX_SET_reg_DA_PREAM_TM_DQS_START (21)
#define SOC_DDR_PHY_DX_RX_SET_reg_DA_PREAM_TM_DQS_END (22)
#define SOC_DDR_PHY_DX_RX_SET_reg_dx_lpbk_sel_dmy_START (23)
#define SOC_DDR_PHY_DX_RX_SET_reg_dx_lpbk_sel_dmy_END (23)
#define SOC_DDR_PHY_DX_RX_SET_dxctl_wck_rank_phase_offset_START (24)
#define SOC_DDR_PHY_DX_RX_SET_dxctl_wck_rank_phase_offset_END (27)
#define SOC_DDR_PHY_DX_RX_SET_dxctl_wck_rank_mask_offset_START (28)
#define SOC_DDR_PHY_DX_RX_SET_dxctl_wck_rank_mask_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_MODE0 : 2;
        unsigned int DX_IO_MODE1 : 2;
        unsigned int DX_IO_MODE2 : 2;
        unsigned int DX_IO_MODE3 : 2;
        unsigned int DX_IO_MODE4 : 2;
        unsigned int DX_IO_MODE5 : 2;
        unsigned int DX_IO_MODE6 : 2;
        unsigned int DX_IO_MODE7 : 2;
        unsigned int DX_IO_MODE8 : 2;
        unsigned int DX_IO_MODE9 : 2;
        unsigned int DX_IO_RXMODE : 3;
        unsigned int DX_IO_TXMODE : 2;
        unsigned int DX_RT_UPDNCOUNT : 3;
        unsigned int reserved : 3;
        unsigned int lp5dqs_oe_gate : 1;
    } reg;
} SOC_DDR_PHY_DX_IOMODE_UNION;
#endif
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE0_START (0)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE0_END (1)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE1_START (2)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE1_END (3)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE2_START (4)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE2_END (5)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE3_START (6)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE3_END (7)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE4_START (8)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE4_END (9)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE5_START (10)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE5_END (11)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE6_START (12)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE6_END (13)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE7_START (14)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE7_END (15)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE8_START (16)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE8_END (17)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE9_START (18)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_MODE9_END (19)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_RXMODE_START (20)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_RXMODE_END (22)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_TXMODE_START (23)
#define SOC_DDR_PHY_DX_IOMODE_DX_IO_TXMODE_END (24)
#define SOC_DDR_PHY_DX_IOMODE_DX_RT_UPDNCOUNT_START (25)
#define SOC_DDR_PHY_DX_IOMODE_DX_RT_UPDNCOUNT_END (27)
#define SOC_DDR_PHY_DX_IOMODE_lp5dqs_oe_gate_START (31)
#define SOC_DDR_PHY_DX_IOMODE_lp5dqs_oe_gate_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_REFRANGE0 : 4;
        unsigned int DX_IO_REFRANGE1 : 4;
        unsigned int DX_IO_REFRANGE2 : 4;
        unsigned int DX_IO_REFRANGE3 : 4;
        unsigned int DX_IO_REFRANGE4 : 4;
        unsigned int DX_IO_REFRANGE5 : 4;
        unsigned int DX_IO_REFRANGE6 : 4;
        unsigned int DX_IO_REFRANGE7 : 4;
    } reg;
} SOC_DDR_PHY_DX_IOREFCTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE0_START (0)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE0_END (3)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE1_START (4)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE1_END (7)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE2_START (8)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE2_END (11)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE3_START (12)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE3_END (15)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE4_START (16)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE4_END (19)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE5_START (20)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE5_END (23)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE6_START (24)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE6_END (27)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE7_START (28)
#define SOC_DDR_PHY_DX_IOREFCTRL0_DX_IO_REFRANGE7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_REFRANGE8 : 4;
        unsigned int DX_IO_REFRANGE9 : 4;
        unsigned int DX_IO_REFRANGE10 : 4;
        unsigned int DX_IO_REFRANGE11 : 4;
        unsigned int dx_wck_offset : 3;
        unsigned int dx_wck_oe_extend : 3;
        unsigned int rxwck_bdl_b0_all_rank : 9;
        unsigned int DA_GTC_EN : 1;
    } reg;
} SOC_DDR_PHY_DX_IOREFCTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE8_START (0)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE8_END (3)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE9_START (4)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE9_END (7)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE10_START (8)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE10_END (11)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE11_START (12)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DX_IO_REFRANGE11_END (15)
#define SOC_DDR_PHY_DX_IOREFCTRL1_dx_wck_offset_START (16)
#define SOC_DDR_PHY_DX_IOREFCTRL1_dx_wck_offset_END (18)
#define SOC_DDR_PHY_DX_IOREFCTRL1_dx_wck_oe_extend_START (19)
#define SOC_DDR_PHY_DX_IOREFCTRL1_dx_wck_oe_extend_END (21)
#define SOC_DDR_PHY_DX_IOREFCTRL1_rxwck_bdl_b0_all_rank_START (22)
#define SOC_DDR_PHY_DX_IOREFCTRL1_rxwck_bdl_b0_all_rank_END (30)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DA_GTC_EN_START (31)
#define SOC_DDR_PHY_DX_IOREFCTRL1_DA_GTC_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_REFSEL0 : 2;
        unsigned int DX_IO_REFSEL1 : 2;
        unsigned int DX_IO_REFSEL2 : 2;
        unsigned int DX_IO_REFSEL3 : 2;
        unsigned int DX_IO_REFSEL4 : 2;
        unsigned int DX_IO_REFSEL5 : 2;
        unsigned int DX_IO_REFSEL6 : 2;
        unsigned int DX_IO_REFSEL7 : 2;
        unsigned int DX_IO_REFSEL8 : 2;
        unsigned int DX_IO_REFSEL9 : 2;
        unsigned int DX_IO_REFSEL10 : 2;
        unsigned int DX_IO_REFSEL11 : 2;
        unsigned int AD_GTCOUT : 8;
    } reg;
} SOC_DDR_PHY_DX_IOREFCTRL2_UNION;
#endif
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL0_START (0)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL0_END (1)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL1_START (2)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL1_END (3)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL2_START (4)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL2_END (5)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL3_START (6)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL3_END (7)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL4_START (8)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL4_END (9)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL5_START (10)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL5_END (11)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL6_START (12)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL6_END (13)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL7_START (14)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL7_END (15)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL8_START (16)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL8_END (17)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL9_START (18)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL9_END (19)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL10_START (20)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL10_END (21)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL11_START (22)
#define SOC_DDR_PHY_DX_IOREFCTRL2_DX_IO_REFSEL11_END (23)
#define SOC_DDR_PHY_DX_IOREFCTRL2_AD_GTCOUT_START (24)
#define SOC_DDR_PHY_DX_IOREFCTRL2_AD_GTCOUT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_EQ_C0 : 5;
        unsigned int DX_RG_D2S_CUR0 : 3;
        unsigned int DX_IO_EQ_C1 : 5;
        unsigned int DX_RG_D2S_CUR1 : 3;
        unsigned int DX_IO_EQ_C2 : 5;
        unsigned int DX_RG_D2S_CUR2 : 3;
        unsigned int DX_IO_EQ_C3 : 5;
        unsigned int DX_RG_D2S_CUR3 : 3;
    } reg;
} SOC_DDR_PHY_DX_IOEQCTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C0_START (0)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C0_END (4)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR0_START (5)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR0_END (7)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C1_START (8)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C1_END (12)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR1_START (13)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR1_END (15)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C2_START (16)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C2_END (20)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR2_START (21)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR2_END (23)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C3_START (24)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_IO_EQ_C3_END (28)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR3_START (29)
#define SOC_DDR_PHY_DX_IOEQCTRL0_DX_RG_D2S_CUR3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_EQ_C4 : 5;
        unsigned int DX_RG_D2S_CUR4 : 3;
        unsigned int DX_IO_EQ_C5 : 5;
        unsigned int DX_RG_D2S_CUR5 : 3;
        unsigned int DX_IO_EQ_C6 : 5;
        unsigned int DX_RG_D2S_CUR6 : 3;
        unsigned int DX_IO_EQ_C7 : 5;
        unsigned int DX_RG_D2S_CUR7 : 3;
    } reg;
} SOC_DDR_PHY_DX_IOEQCTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C4_START (0)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C4_END (4)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR4_START (5)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR4_END (7)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C5_START (8)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C5_END (12)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR5_START (13)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR5_END (15)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C6_START (16)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C6_END (20)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR6_START (21)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR6_END (23)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C7_START (24)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_IO_EQ_C7_END (28)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR7_START (29)
#define SOC_DDR_PHY_DX_IOEQCTRL1_DX_RG_D2S_CUR7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_EQ_RP0 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP0 : 1;
        unsigned int DX_RG_D2SBIAS_BYP0 : 1;
        unsigned int DX_RG_VREF_CTRL0 : 1;
        unsigned int DX_IO_EQ_RP1 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP1 : 1;
        unsigned int DX_RG_D2SBIAS_BYP1 : 1;
        unsigned int DX_RG_VREF_CTRL1 : 1;
        unsigned int DX_IO_EQ_RP2 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP2 : 1;
        unsigned int DX_RG_D2SBIAS_BYP2 : 1;
        unsigned int DX_RG_VREF_CTRL2 : 1;
        unsigned int DX_IO_EQ_RP3 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP3 : 1;
        unsigned int DX_RG_D2SBIAS_BYP3 : 1;
        unsigned int DX_RG_VREF_CTRL3 : 1;
    } reg;
} SOC_DDR_PHY_DX_IOEQCTRL2_UNION;
#endif
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP0_START (0)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP0_END (4)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP0_START (5)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP0_END (5)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP0_START (6)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP0_END (6)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL0_START (7)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL0_END (7)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP1_START (8)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP1_END (12)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP1_START (13)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP1_END (13)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP1_START (14)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP1_END (14)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL1_START (15)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL1_END (15)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP2_START (16)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP2_END (20)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP2_START (21)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP2_END (21)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP2_START (22)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP2_END (22)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL2_START (23)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL2_END (23)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP3_START (24)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_IO_EQ_RP3_END (28)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP3_START (29)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_CTLEBIASEN_BYP3_END (29)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP3_START (30)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_D2SBIAS_BYP3_END (30)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL3_START (31)
#define SOC_DDR_PHY_DX_IOEQCTRL2_DX_RG_VREF_CTRL3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_EQ_RP4 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP4 : 1;
        unsigned int DX_RG_D2SBIAS_BYP4 : 1;
        unsigned int DX_RG_VREF_CTRL4 : 1;
        unsigned int DX_IO_EQ_RP5 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP5 : 1;
        unsigned int DX_RG_D2SBIAS_BYP5 : 1;
        unsigned int DX_RG_VREF_CTRL5 : 1;
        unsigned int DX_IO_EQ_RP6 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP6 : 1;
        unsigned int DX_RG_D2SBIAS_BYP6 : 1;
        unsigned int DX_RG_VREF_CTRL6 : 1;
        unsigned int DX_IO_EQ_RP7 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP7 : 1;
        unsigned int DX_RG_D2SBIAS_BYP7 : 1;
        unsigned int DX_RG_VREF_CTRL7 : 1;
    } reg;
} SOC_DDR_PHY_DX_IOEQCTRL3_UNION;
#endif
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP4_START (0)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP4_END (4)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP4_START (5)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP4_END (5)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP4_START (6)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP4_END (6)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL4_START (7)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL4_END (7)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP5_START (8)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP5_END (12)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP5_START (13)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP5_END (13)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP5_START (14)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP5_END (14)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL5_START (15)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL5_END (15)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP6_START (16)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP6_END (20)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP6_START (21)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP6_END (21)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP6_START (22)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP6_END (22)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL6_START (23)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL6_END (23)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP7_START (24)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_IO_EQ_RP7_END (28)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP7_START (29)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_CTLEBIASEN_BYP7_END (29)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP7_START (30)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_D2SBIAS_BYP7_END (30)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL7_START (31)
#define SOC_DDR_PHY_DX_IOEQCTRL3_DX_RG_VREF_CTRL7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_PE_C0 : 1;
        unsigned int reserved_0 : 2;
        unsigned int DX_IO_PRE_EN0 : 1;
        unsigned int DX_IO_PE_C1 : 1;
        unsigned int reserved_1 : 2;
        unsigned int DX_IO_PRE_EN1 : 1;
        unsigned int DX_IO_PE_C2 : 1;
        unsigned int reserved_2 : 2;
        unsigned int DX_IO_PRE_EN2 : 1;
        unsigned int DX_IO_PE_C3 : 1;
        unsigned int reserved_3 : 2;
        unsigned int DX_IO_PRE_EN3 : 1;
        unsigned int DX_IO_PE_C4 : 1;
        unsigned int reserved_4 : 2;
        unsigned int DX_IO_PRE_EN4 : 1;
        unsigned int DX_IO_PE_C5 : 1;
        unsigned int reserved_5 : 2;
        unsigned int DX_IO_PRE_EN5 : 1;
        unsigned int DX_IO_PE_C6 : 1;
        unsigned int reserved_6 : 2;
        unsigned int DX_IO_PRE_EN6 : 1;
        unsigned int DX_IO_PE_C7 : 1;
        unsigned int reserved_7 : 2;
        unsigned int DX_IO_PRE_EN7 : 1;
    } reg;
} SOC_DDR_PHY_DX_PECTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C0_START (0)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C0_END (0)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN0_START (3)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN0_END (3)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C1_START (4)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C1_END (4)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN1_START (7)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN1_END (7)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C2_START (8)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C2_END (8)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN2_START (11)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN2_END (11)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C3_START (12)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C3_END (12)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN3_START (15)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN3_END (15)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C4_START (16)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C4_END (16)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN4_START (19)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN4_END (19)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C5_START (20)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C5_END (20)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN5_START (23)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN5_END (23)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C6_START (24)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C6_END (24)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN6_START (27)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN6_END (27)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C7_START (28)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PE_C7_END (28)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN7_START (31)
#define SOC_DDR_PHY_DX_PECTRL0_DX_IO_PRE_EN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_PE_C8 : 1;
        unsigned int reserved_0 : 2;
        unsigned int DX_IO_PRE_EN8 : 1;
        unsigned int DX_IO_PE_C9 : 1;
        unsigned int reserved_1 : 2;
        unsigned int DX_IO_PRE_EN9 : 1;
        unsigned int DX_IO_PE_C10 : 1;
        unsigned int reserved_2 : 2;
        unsigned int DX_IO_PRE_EN10 : 1;
        unsigned int DX_IO_PE_C11 : 1;
        unsigned int reserved_3 : 2;
        unsigned int DX_IO_PRE_EN11 : 1;
        unsigned int DX_IO_RONSEL11 : 3;
        unsigned int DX_IO_RONBSEL_3_5 : 3;
        unsigned int dxctl_rden_dfi_offset : 3;
        unsigned int dxctl_rden_fifo_offset : 3;
        unsigned int dxctl_rden_rank_offset : 4;
    } reg;
} SOC_DDR_PHY_DX_PECTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C8_START (0)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C8_END (0)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN8_START (3)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN8_END (3)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C9_START (4)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C9_END (4)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN9_START (7)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN9_END (7)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C10_START (8)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C10_END (8)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN10_START (11)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN10_END (11)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C11_START (12)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PE_C11_END (12)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN11_START (15)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_PRE_EN11_END (15)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_RONSEL11_START (16)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_RONSEL11_END (18)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_RONBSEL_3_5_START (19)
#define SOC_DDR_PHY_DX_PECTRL1_DX_IO_RONBSEL_3_5_END (21)
#define SOC_DDR_PHY_DX_PECTRL1_dxctl_rden_dfi_offset_START (22)
#define SOC_DDR_PHY_DX_PECTRL1_dxctl_rden_dfi_offset_END (24)
#define SOC_DDR_PHY_DX_PECTRL1_dxctl_rden_fifo_offset_START (25)
#define SOC_DDR_PHY_DX_PECTRL1_dxctl_rden_fifo_offset_END (27)
#define SOC_DDR_PHY_DX_PECTRL1_dxctl_rden_rank_offset_START (28)
#define SOC_DDR_PHY_DX_PECTRL1_dxctl_rden_rank_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_RONSEL0 : 3;
        unsigned int DX_IO_PULLDN0 : 1;
        unsigned int DX_IO_RONSEL1 : 3;
        unsigned int DX_IO_PULLDN1 : 1;
        unsigned int DX_IO_RONSEL2 : 3;
        unsigned int DX_IO_PULLDN2 : 1;
        unsigned int DX_IO_RONSEL3 : 3;
        unsigned int DX_IO_PULLDN3 : 1;
        unsigned int DX_IO_RONSEL4 : 3;
        unsigned int DX_IO_PULLDN4 : 1;
        unsigned int DX_IO_RONSEL5 : 3;
        unsigned int DX_IO_PULLDN5 : 1;
        unsigned int DX_IO_RONSEL6 : 3;
        unsigned int DX_IO_PULLDN6 : 1;
        unsigned int DX_IO_RONSEL7 : 3;
        unsigned int DX_IO_PULLDN7 : 1;
    } reg;
} SOC_DDR_PHY_DX_RONCTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL0_START (0)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL0_END (2)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN0_START (3)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN0_END (3)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL1_START (4)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL1_END (6)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN1_START (7)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN1_END (7)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL2_START (8)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL2_END (10)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN2_START (11)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN2_END (11)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL3_START (12)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL3_END (14)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN3_START (15)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN3_END (15)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL4_START (16)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL4_END (18)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN4_START (19)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN4_END (19)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL5_START (20)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL5_END (22)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN5_START (23)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN5_END (23)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL6_START (24)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL6_END (26)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN6_START (27)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN6_END (27)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL7_START (28)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_RONSEL7_END (30)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN7_START (31)
#define SOC_DDR_PHY_DX_RONCTRL0_DX_IO_PULLDN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_RONSEL8 : 3;
        unsigned int DX_IO_PULLDN8 : 1;
        unsigned int DX_IO_RONSEL9 : 3;
        unsigned int DX_IO_PULLDN9 : 1;
        unsigned int DX_IO_RONSEL10 : 3;
        unsigned int DX_IO_PULLDN10 : 1;
        unsigned int DX_IO_RONBSEL : 3;
        unsigned int DX_IO_PULLDN11 : 1;
        unsigned int DX_IO_PUPDMODE_DQS : 2;
        unsigned int DX_IO_REG_ODTEN : 1;
        unsigned int DX_IO_ODTEN_B : 10;
        unsigned int DX_IO_ODTEN_A : 2;
        unsigned int DX_IO_TODTEN_11 : 1;
    } reg;
} SOC_DDR_PHY_DX_RONCTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONSEL8_START (0)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONSEL8_END (2)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN8_START (3)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN8_END (3)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONSEL9_START (4)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONSEL9_END (6)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN9_START (7)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN9_END (7)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONSEL10_START (8)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONSEL10_END (10)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN10_START (11)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN10_END (11)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONBSEL_START (12)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_RONBSEL_END (14)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN11_START (15)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PULLDN11_END (15)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PUPDMODE_DQS_START (16)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_PUPDMODE_DQS_END (17)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_REG_ODTEN_START (18)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_REG_ODTEN_END (18)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_ODTEN_B_START (19)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_ODTEN_B_END (28)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_ODTEN_A_START (29)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_ODTEN_A_END (30)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_TODTEN_11_START (31)
#define SOC_DDR_PHY_DX_RONCTRL1_DX_IO_TODTEN_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_ODTSEL0 : 3;
        unsigned int DX_IO_ODTSEL1 : 3;
        unsigned int DX_IO_ODTSEL2 : 3;
        unsigned int DX_IO_ODTSEL3 : 3;
        unsigned int DX_IO_ODTSEL4 : 3;
        unsigned int DX_IO_ODTSEL5 : 3;
        unsigned int DX_IO_ODTSEL6 : 3;
        unsigned int DX_IO_ODTSEL7 : 3;
        unsigned int DX_IO_ODTSEL11 : 3;
        unsigned int rxwck_bdl_b0_all_rank_msb : 1;
        unsigned int dxctl_wren_rank_offset : 4;
    } reg;
} SOC_DDR_PHY_DX_ODTCTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL0_START (0)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL0_END (2)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL1_START (3)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL1_END (5)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL2_START (6)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL2_END (8)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL3_START (9)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL3_END (11)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL4_START (12)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL4_END (14)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL5_START (15)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL5_END (17)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL6_START (18)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL6_END (20)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL7_START (21)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL7_END (23)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL11_START (24)
#define SOC_DDR_PHY_DX_ODTCTRL1_DX_IO_ODTSEL11_END (26)
#define SOC_DDR_PHY_DX_ODTCTRL1_rxwck_bdl_b0_all_rank_msb_START (27)
#define SOC_DDR_PHY_DX_ODTCTRL1_rxwck_bdl_b0_all_rank_msb_END (27)
#define SOC_DDR_PHY_DX_ODTCTRL1_dxctl_wren_rank_offset_START (28)
#define SOC_DDR_PHY_DX_ODTCTRL1_dxctl_wren_rank_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_ODTSEL8 : 3;
        unsigned int DX_IO_ODTSEL9 : 3;
        unsigned int DX_IO_ODTSEL10 : 3;
        unsigned int DX_IO_TODTEN : 11;
        unsigned int DX_IO_ODTTEST : 12;
    } reg;
} SOC_DDR_PHY_DX_ODTCTRL2_UNION;
#endif
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTSEL8_START (0)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTSEL8_END (2)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTSEL9_START (3)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTSEL9_END (5)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTSEL10_START (6)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTSEL10_END (8)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_TODTEN_START (9)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_TODTEN_END (19)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTTEST_START (20)
#define SOC_DDR_PHY_DX_ODTCTRL2_DX_IO_ODTTEST_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_IOTEST : 12;
        unsigned int dummy_wen_offset : 3;
        unsigned int cfg_tx_gcken : 1;
        unsigned int DX_IO_IETEST : 12;
        unsigned int dummy_extend : 3;
        unsigned int reg_wdqs_iotest : 1;
    } reg;
} SOC_DDR_PHY_DX_TESTCTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_TESTCTRL0_DX_IO_IOTEST_START (0)
#define SOC_DDR_PHY_DX_TESTCTRL0_DX_IO_IOTEST_END (11)
#define SOC_DDR_PHY_DX_TESTCTRL0_dummy_wen_offset_START (12)
#define SOC_DDR_PHY_DX_TESTCTRL0_dummy_wen_offset_END (14)
#define SOC_DDR_PHY_DX_TESTCTRL0_cfg_tx_gcken_START (15)
#define SOC_DDR_PHY_DX_TESTCTRL0_cfg_tx_gcken_END (15)
#define SOC_DDR_PHY_DX_TESTCTRL0_DX_IO_IETEST_START (16)
#define SOC_DDR_PHY_DX_TESTCTRL0_DX_IO_IETEST_END (27)
#define SOC_DDR_PHY_DX_TESTCTRL0_dummy_extend_START (28)
#define SOC_DDR_PHY_DX_TESTCTRL0_dummy_extend_END (30)
#define SOC_DDR_PHY_DX_TESTCTRL0_reg_wdqs_iotest_START (31)
#define SOC_DDR_PHY_DX_TESTCTRL0_reg_wdqs_iotest_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_TE : 12;
        unsigned int dummy_t_extend : 3;
        unsigned int RG_ECC_HZ : 1;
        unsigned int DX_IO_TI : 12;
        unsigned int rank_sw_gate_length : 4;
    } reg;
} SOC_DDR_PHY_DX_TESTCTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_TESTCTRL1_DX_IO_TE_START (0)
#define SOC_DDR_PHY_DX_TESTCTRL1_DX_IO_TE_END (11)
#define SOC_DDR_PHY_DX_TESTCTRL1_dummy_t_extend_START (12)
#define SOC_DDR_PHY_DX_TESTCTRL1_dummy_t_extend_END (14)
#define SOC_DDR_PHY_DX_TESTCTRL1_RG_ECC_HZ_START (15)
#define SOC_DDR_PHY_DX_TESTCTRL1_RG_ECC_HZ_END (15)
#define SOC_DDR_PHY_DX_TESTCTRL1_DX_IO_TI_START (16)
#define SOC_DDR_PHY_DX_TESTCTRL1_DX_IO_TI_END (27)
#define SOC_DDR_PHY_DX_TESTCTRL1_rank_sw_gate_length_START (28)
#define SOC_DDR_PHY_DX_TESTCTRL1_rank_sw_gate_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_TIE : 12;
        unsigned int dummy_wen_extend : 3;
        unsigned int DX_IO_TO : 12;
        unsigned int dummy_wen_t_extend : 3;
        unsigned int reserved : 1;
        unsigned int DX_IO_NE : 1;
    } reg;
} SOC_DDR_PHY_DX_TESTCTRL2_UNION;
#endif
#define SOC_DDR_PHY_DX_TESTCTRL2_DX_IO_TIE_START (0)
#define SOC_DDR_PHY_DX_TESTCTRL2_DX_IO_TIE_END (11)
#define SOC_DDR_PHY_DX_TESTCTRL2_dummy_wen_extend_START (12)
#define SOC_DDR_PHY_DX_TESTCTRL2_dummy_wen_extend_END (14)
#define SOC_DDR_PHY_DX_TESTCTRL2_DX_IO_TO_START (15)
#define SOC_DDR_PHY_DX_TESTCTRL2_DX_IO_TO_END (26)
#define SOC_DDR_PHY_DX_TESTCTRL2_dummy_wen_t_extend_START (27)
#define SOC_DDR_PHY_DX_TESTCTRL2_dummy_wen_t_extend_END (29)
#define SOC_DDR_PHY_DX_TESTCTRL2_DX_IO_NE_START (31)
#define SOC_DDR_PHY_DX_TESTCTRL2_DX_IO_NE_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_EQ_C8 : 5;
        unsigned int DX_RG_D2S_CUR8 : 3;
        unsigned int DX_IO_EQ_RP8 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP8 : 1;
        unsigned int DX_RG_D2SBIAS_BYP8 : 1;
        unsigned int DX_RG_VREF_CTRL8 : 1;
        unsigned int DX_IO_EQ_C9 : 5;
        unsigned int DX_RG_D2S_CUR9 : 3;
        unsigned int DX_IO_EQ_RP9 : 5;
        unsigned int DX_RG_CTLEBIASEN_BYP9 : 1;
        unsigned int DX_RG_D2SBIAS_BYP9 : 1;
        unsigned int DX_RG_VREF_CTRL9 : 1;
    } reg;
} SOC_DDR_PHY_DX_IOEQCTRL4_UNION;
#endif
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_C8_START (0)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_C8_END (4)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2S_CUR8_START (5)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2S_CUR8_END (7)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_RP8_START (8)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_RP8_END (12)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_CTLEBIASEN_BYP8_START (13)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_CTLEBIASEN_BYP8_END (13)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2SBIAS_BYP8_START (14)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2SBIAS_BYP8_END (14)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_VREF_CTRL8_START (15)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_VREF_CTRL8_END (15)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_C9_START (16)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_C9_END (20)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2S_CUR9_START (21)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2S_CUR9_END (23)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_RP9_START (24)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_IO_EQ_RP9_END (28)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_CTLEBIASEN_BYP9_START (29)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_CTLEBIASEN_BYP9_END (29)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2SBIAS_BYP9_START (30)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_D2SBIAS_BYP9_END (30)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_VREF_CTRL9_START (31)
#define SOC_DDR_PHY_DX_IOEQCTRL4_DX_RG_VREF_CTRL9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int TX_RG_DCC_P_DN0 : 4;
        unsigned int TX_RG_DCC_P_DN1 : 4;
        unsigned int TX_RG_DCC_P_DN2 : 4;
        unsigned int TX_RG_DCC_P_DN3 : 4;
        unsigned int TX_RG_DCC_P_DN4 : 4;
        unsigned int TX_RG_DCC_P_DN5 : 4;
        unsigned int TX_RG_DCC_P_DN6 : 4;
        unsigned int TX_RG_DCC_P_DN7 : 4;
    } reg;
} SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN0_START (0)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN0_END (3)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN1_START (4)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN1_END (7)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN2_START (8)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN2_END (11)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN3_START (12)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN3_END (15)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN4_START (16)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN4_END (19)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN5_START (20)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN5_END (23)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN6_START (24)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN6_END (27)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN7_START (28)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int TX_RG_DCC_P_DN8 : 4;
        unsigned int TX_RG_DCC_P_DN9 : 4;
        unsigned int TX_RG_DCC_P_DN10 : 4;
        unsigned int TX_RG_DCC_P_DN11 : 4;
        unsigned int cfg_rdqsg_offset : 2;
        unsigned int cfg_wdq_offset : 2;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN8_START (0)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN8_END (3)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN9_START (4)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN9_END (7)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN10_START (8)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN10_END (11)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN11_START (12)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN11_END (15)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_cfg_rdqsg_offset_START (16)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_cfg_rdqsg_offset_END (17)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_cfg_wdq_offset_START (18)
#define SOC_DDR_PHY_DX_TXDCC_PDN_CTRL1_cfg_wdq_offset_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int TX_RG_DCC_N_DN0 : 4;
        unsigned int TX_RG_DCC_N_DN1 : 4;
        unsigned int TX_RG_DCC_N_DN2 : 4;
        unsigned int TX_RG_DCC_N_DN3 : 4;
        unsigned int TX_RG_DCC_N_DN4 : 4;
        unsigned int TX_RG_DCC_N_DN5 : 4;
        unsigned int TX_RG_DCC_N_DN6 : 4;
        unsigned int TX_RG_DCC_N_DN7 : 4;
    } reg;
} SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN0_START (0)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN0_END (3)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN1_START (4)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN1_END (7)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN2_START (8)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN2_END (11)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN3_START (12)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN3_END (15)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN4_START (16)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN4_END (19)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN5_START (20)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN5_END (23)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN6_START (24)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN6_END (27)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN7_START (28)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int TX_RG_DCC_N_DN8 : 4;
        unsigned int TX_RG_DCC_N_DN9 : 4;
        unsigned int TX_RG_DCC_N_DN10 : 4;
        unsigned int TX_RG_DCC_N_DN11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN8_START (0)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN8_END (3)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN9_START (4)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN9_END (7)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN10_START (8)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN10_END (11)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN11_START (12)
#define SOC_DDR_PHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DQS_DA_RX_DIO_VOS : 5;
        unsigned int DQS_DA_RX_DIO_VOSK_EN : 1;
        unsigned int DQS_DA_RX_DIO_VOSK_INSHORT : 1;
        unsigned int DQS_DA_RX_DIO_VOSK_SEL : 1;
        unsigned int WCK_DA_RX_DIO_VOS : 5;
        unsigned int WCK_DA_RX_DIO_VOSK_EN : 1;
        unsigned int WCK_DA_RX_DIO_VOSK_INSHORT : 1;
        unsigned int WCK_DA_RX_DIO_VOSK_SEL : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_UNION;
#endif
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOS_START (0)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOS_END (4)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOSK_EN_START (5)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOSK_EN_END (5)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOSK_INSHORT_START (6)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOSK_INSHORT_END (6)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOSK_SEL_START (7)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_DQS_DA_RX_DIO_VOSK_SEL_END (7)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOS_START (8)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOS_END (12)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOSK_EN_START (13)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOSK_EN_END (13)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOSK_INSHORT_START (14)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOSK_INSHORT_END (14)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOSK_SEL_START (15)
#define SOC_DDR_PHY_DX_RX_DIO_VOS_CTRL_WCK_DA_RX_DIO_VOSK_SEL_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_P_DN0 : 4;
        unsigned int RX_RG_DCC_P_DN1 : 4;
        unsigned int RX_RG_DCC_P_DN2 : 4;
        unsigned int RX_RG_DCC_P_DN3 : 4;
        unsigned int RX_RG_DCC_P_DN4 : 4;
        unsigned int RX_RG_DCC_P_DN5 : 4;
        unsigned int RX_RG_DCC_P_DN6 : 4;
        unsigned int RX_RG_DCC_P_DN7 : 4;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN0_START (0)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN0_END (3)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN1_START (4)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN1_END (7)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN2_START (8)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN2_END (11)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN3_START (12)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN3_END (15)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN4_START (16)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN4_END (19)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN5_START (20)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN5_END (23)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN6_START (24)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN6_END (27)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN7_START (28)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_P_DN8 : 4;
        unsigned int RX_RG_DCC_P_DN9 : 4;
        unsigned int RX_RG_DCC_P_DN10 : 4;
        unsigned int RX_RG_DCC_P_DN11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN8_START (0)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN8_END (3)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN9_START (4)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN9_END (7)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN10_START (8)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN10_END (11)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN11_START (12)
#define SOC_DDR_PHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_N_DN0 : 4;
        unsigned int RX_RG_DCC_N_DN1 : 4;
        unsigned int RX_RG_DCC_N_DN2 : 4;
        unsigned int RX_RG_DCC_N_DN3 : 4;
        unsigned int RX_RG_DCC_N_DN4 : 4;
        unsigned int RX_RG_DCC_N_DN5 : 4;
        unsigned int RX_RG_DCC_N_DN6 : 4;
        unsigned int RX_RG_DCC_N_DN7 : 4;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN0_START (0)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN0_END (3)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN1_START (4)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN1_END (7)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN2_START (8)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN2_END (11)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN3_START (12)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN3_END (15)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN4_START (16)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN4_END (19)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN5_START (20)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN5_END (23)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN6_START (24)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN6_END (27)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN7_START (28)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_N_DN8 : 4;
        unsigned int RX_RG_DCC_N_DN9 : 4;
        unsigned int RX_RG_DCC_N_DN10 : 4;
        unsigned int RX_RG_DCC_N_DN11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN8_START (0)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN8_END (3)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN9_START (4)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN9_END (7)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN10_START (8)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN10_END (11)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN11_START (12)
#define SOC_DDR_PHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_P_UP0 : 4;
        unsigned int RX_RG_DCC_P_UP1 : 4;
        unsigned int RX_RG_DCC_P_UP2 : 4;
        unsigned int RX_RG_DCC_P_UP3 : 4;
        unsigned int RX_RG_DCC_P_UP4 : 4;
        unsigned int RX_RG_DCC_P_UP5 : 4;
        unsigned int RX_RG_DCC_P_UP6 : 4;
        unsigned int RX_RG_DCC_P_UP7 : 4;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP0_START (0)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP0_END (3)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP1_START (4)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP1_END (7)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP2_START (8)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP2_END (11)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP3_START (12)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP3_END (15)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP4_START (16)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP4_END (19)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP5_START (20)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP5_END (23)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP6_START (24)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP6_END (27)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP7_START (28)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_P_UP8 : 4;
        unsigned int RX_RG_DCC_P_UP9 : 4;
        unsigned int RX_RG_DCC_P_UP10 : 4;
        unsigned int RX_RG_DCC_P_UP11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP8_START (0)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP8_END (3)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP9_START (4)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP9_END (7)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP10_START (8)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP10_END (11)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP11_START (12)
#define SOC_DDR_PHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_N_UP0 : 4;
        unsigned int RX_RG_DCC_N_UP1 : 4;
        unsigned int RX_RG_DCC_N_UP2 : 4;
        unsigned int RX_RG_DCC_N_UP3 : 4;
        unsigned int RX_RG_DCC_N_UP4 : 4;
        unsigned int RX_RG_DCC_N_UP5 : 4;
        unsigned int RX_RG_DCC_N_UP6 : 4;
        unsigned int RX_RG_DCC_N_UP7 : 4;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP0_START (0)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP0_END (3)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP1_START (4)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP1_END (7)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP2_START (8)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP2_END (11)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP3_START (12)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP3_END (15)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP4_START (16)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP4_END (19)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP5_START (20)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP5_END (23)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP6_START (24)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP6_END (27)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP7_START (28)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RX_RG_DCC_N_UP8 : 4;
        unsigned int RX_RG_DCC_N_UP9 : 4;
        unsigned int RX_RG_DCC_N_UP10 : 4;
        unsigned int RX_RG_DCC_N_UP11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_UNION;
#endif
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP8_START (0)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP8_END (3)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP9_START (4)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP9_END (7)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP10_START (8)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP10_END (11)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP11_START (12)
#define SOC_DDR_PHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST0_0 : 1;
        unsigned int DX_RG_TEST0_1 : 1;
        unsigned int DX_RG_TEST0_2 : 1;
        unsigned int DX_RG_TEST0_3 : 2;
        unsigned int DX_RG_TEST0_4 : 3;
        unsigned int DX_RG_TEST1_0 : 1;
        unsigned int DX_RG_TEST1_1 : 1;
        unsigned int DX_RG_TEST1_2 : 1;
        unsigned int DX_RG_TEST1_3 : 2;
        unsigned int DX_RG_TEST1_4 : 3;
        unsigned int DX_RG_TEST2_0 : 1;
        unsigned int DX_RG_TEST2_1 : 1;
        unsigned int DX_RG_TEST2_2 : 1;
        unsigned int DX_RG_TEST2_3 : 2;
        unsigned int DX_RG_TEST2_4 : 3;
        unsigned int DX_RG_TEST3_0 : 1;
        unsigned int DX_RG_TEST3_1 : 1;
        unsigned int DX_RG_TEST3_2 : 1;
        unsigned int DX_RG_TEST3_3 : 2;
        unsigned int DX_RG_TEST3_4 : 3;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_CTL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_0_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_0_END (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_1_START (1)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_1_END (1)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_2_START (2)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_2_END (2)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_3_START (3)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_3_END (4)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_4_START (5)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST0_4_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_0_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_0_END (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_1_START (9)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_1_END (9)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_2_START (10)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_2_END (10)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_3_START (11)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_3_END (12)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_4_START (13)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST1_4_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_0_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_0_END (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_1_START (17)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_1_END (17)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_2_START (18)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_2_END (18)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_3_START (19)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_3_END (20)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_4_START (21)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST2_4_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_0_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_0_END (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_1_START (25)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_1_END (25)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_2_START (26)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_2_END (26)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_3_START (27)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_3_END (28)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_4_START (29)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_DX_RG_TEST3_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST4_0 : 1;
        unsigned int DX_RG_TEST4_1 : 1;
        unsigned int DX_RG_TEST4_2 : 1;
        unsigned int DX_RG_TEST4_3 : 2;
        unsigned int DX_RG_TEST4_4 : 3;
        unsigned int DX_RG_TEST5_0 : 1;
        unsigned int DX_RG_TEST5_1 : 1;
        unsigned int DX_RG_TEST5_2 : 1;
        unsigned int DX_RG_TEST5_3 : 2;
        unsigned int DX_RG_TEST5_4 : 3;
        unsigned int DX_RG_TEST6_0 : 1;
        unsigned int DX_RG_TEST6_1 : 1;
        unsigned int DX_RG_TEST6_2 : 1;
        unsigned int DX_RG_TEST6_3 : 2;
        unsigned int DX_RG_TEST6_4 : 3;
        unsigned int DX_RG_TEST7_0 : 1;
        unsigned int DX_RG_TEST7_1 : 1;
        unsigned int DX_RG_TEST7_2 : 1;
        unsigned int DX_RG_TEST7_3 : 2;
        unsigned int DX_RG_TEST7_4 : 3;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_CTL1_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_0_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_0_END (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_1_START (1)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_1_END (1)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_2_START (2)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_2_END (2)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_3_START (3)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_3_END (4)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_4_START (5)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST4_4_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_0_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_0_END (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_1_START (9)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_1_END (9)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_2_START (10)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_2_END (10)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_3_START (11)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_3_END (12)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_4_START (13)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST5_4_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_0_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_0_END (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_1_START (17)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_1_END (17)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_2_START (18)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_2_END (18)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_3_START (19)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_3_END (20)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_4_START (21)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST6_4_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_0_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_0_END (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_1_START (25)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_1_END (25)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_2_START (26)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_2_END (26)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_3_START (27)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_3_END (28)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_4_START (29)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_DX_RG_TEST7_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST8_0 : 1;
        unsigned int DX_RG_TEST8_1 : 1;
        unsigned int DX_RG_TEST8_2 : 1;
        unsigned int DX_RG_TEST8_3 : 2;
        unsigned int DX_RG_TEST8_4 : 3;
        unsigned int DX_RG_TEST9_0 : 1;
        unsigned int DX_RG_TEST9_1 : 1;
        unsigned int DX_RG_TEST9_2 : 1;
        unsigned int DX_RG_TEST9_3 : 1;
        unsigned int DX_RG_TEST9_4 : 4;
        unsigned int DX_RG_TEST10_0 : 1;
        unsigned int DX_RG_TEST10_1 : 1;
        unsigned int DX_RG_TEST10_2 : 1;
        unsigned int DX_RG_TEST10_3 : 2;
        unsigned int DX_RG_TEST10_4 : 3;
        unsigned int DX_RG_TEST11_0 : 1;
        unsigned int DX_RG_TEST11_1 : 1;
        unsigned int DX_RG_TEST11_2 : 1;
        unsigned int DX_RG_TEST11_3 : 1;
        unsigned int DX_RG_TEST11_4 : 4;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_CTL2_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_0_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_0_END (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_1_START (1)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_1_END (1)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_2_START (2)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_2_END (2)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_3_START (3)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_3_END (4)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_4_START (5)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST8_4_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_0_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_0_END (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_1_START (9)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_1_END (9)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_2_START (10)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_2_END (10)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_3_START (11)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_3_END (11)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_4_START (12)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST9_4_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_0_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_0_END (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_1_START (17)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_1_END (17)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_2_START (18)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_2_END (18)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_3_START (19)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_3_END (20)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_4_START (21)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST10_4_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_0_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_0_END (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_1_START (25)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_1_END (25)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_2_START (26)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_2_END (26)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_3_START (27)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_3_END (27)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_4_START (28)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_DX_RG_TEST11_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int err_dq_margin_0 : 1;
        unsigned int err_dq_margin_1 : 1;
        unsigned int err_dq_margin_2 : 1;
        unsigned int err_dq_margin_3 : 1;
        unsigned int err_dq_margin_4 : 1;
        unsigned int err_dq_margin_5 : 1;
        unsigned int err_dq_margin_6 : 1;
        unsigned int err_dq_margin_7 : 1;
        unsigned int err_dq_margin_8 : 1;
        unsigned int err_dyn_duty : 1;
        unsigned int err_gate_margin : 1;
        unsigned int cfg_upd_dm_track_de_en_f : 1;
        unsigned int cfg_upd_dm_track_de_en : 1;
        unsigned int cfg_upd_dq_track_de_en_f : 1;
        unsigned int cfg_upd_dq_track_de_en : 1;
        unsigned int cfg_upd_track_gate_en : 1;
        unsigned int gate_margin : 8;
        unsigned int dq_margin_8 : 8;
    } reg;
} SOC_DDR_PHY_DX_TRACK_ERR_UNION;
#endif
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_0_START (0)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_0_END (0)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_1_START (1)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_1_END (1)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_2_START (2)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_2_END (2)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_3_START (3)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_3_END (3)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_4_START (4)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_4_END (4)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_5_START (5)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_5_END (5)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_6_START (6)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_6_END (6)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_7_START (7)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_7_END (7)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_8_START (8)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dq_margin_8_END (8)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dyn_duty_START (9)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_dyn_duty_END (9)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_gate_margin_START (10)
#define SOC_DDR_PHY_DX_TRACK_ERR_err_gate_margin_END (10)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_f_START (11)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_f_END (11)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_START (12)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_END (12)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_f_START (13)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_f_END (13)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_START (14)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_END (14)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_track_gate_en_START (15)
#define SOC_DDR_PHY_DX_TRACK_ERR_cfg_upd_track_gate_en_END (15)
#define SOC_DDR_PHY_DX_TRACK_ERR_gate_margin_START (16)
#define SOC_DDR_PHY_DX_TRACK_ERR_gate_margin_END (23)
#define SOC_DDR_PHY_DX_TRACK_ERR_dq_margin_8_START (24)
#define SOC_DDR_PHY_DX_TRACK_ERR_dq_margin_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq_margin_0 : 8;
        unsigned int dq_margin_1 : 8;
        unsigned int dq_margin_2 : 8;
        unsigned int dq_margin_3 : 8;
    } reg;
} SOC_DDR_PHY_DX_DQ_MARGIN0_UNION;
#endif
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_0_START (0)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_0_END (7)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_1_START (8)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_1_END (15)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_2_START (16)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_2_END (23)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_3_START (24)
#define SOC_DDR_PHY_DX_DQ_MARGIN0_dq_margin_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq_margin_4 : 8;
        unsigned int dq_margin_5 : 8;
        unsigned int dq_margin_6 : 8;
        unsigned int dq_margin_7 : 8;
    } reg;
} SOC_DDR_PHY_DX_DQ_MARGIN1_UNION;
#endif
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_4_START (0)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_4_END (7)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_5_START (8)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_5_END (15)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_6_START (16)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_6_END (23)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_7_START (24)
#define SOC_DDR_PHY_DX_DQ_MARGIN1_dq_margin_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 12;
        unsigned int dxctl_wcken_rank_mask_bypass : 1;
        unsigned int dxctl_wren_rank_mask_bypass : 1;
        unsigned int dxctl_wren_rank_offset_halfT : 1;
        unsigned int dxctl_wren_rank_phase_offset_halfT : 1;
        unsigned int dxctl_wren_rank_mask_offset_halfT : 1;
        unsigned int dxctl_wck_rank_offset_halfT : 1;
        unsigned int dxctl_wck_rank_phase_offset_halfT : 1;
        unsigned int dxctl_wck_rank_mask_offset_halfT : 1;
        unsigned int dxctl_wck_rank_offset : 4;
        unsigned int rst_g_len : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_PHY_DX_OEBDL_CTL0_UNION;
#endif
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wcken_rank_mask_bypass_START (12)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wcken_rank_mask_bypass_END (12)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_mask_bypass_START (13)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_mask_bypass_END (13)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_offset_halfT_START (14)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_offset_halfT_END (14)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_phase_offset_halfT_START (15)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_phase_offset_halfT_END (15)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_mask_offset_halfT_START (16)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wren_rank_mask_offset_halfT_END (16)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_offset_halfT_START (17)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_offset_halfT_END (17)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_phase_offset_halfT_START (18)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_phase_offset_halfT_END (18)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_mask_offset_halfT_START (19)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_mask_offset_halfT_END (19)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_offset_START (20)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_dxctl_wck_rank_offset_END (23)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_rst_g_len_START (24)
#define SOC_DDR_PHY_DX_OEBDL_CTL0_rst_g_len_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_PHY_DX_OEBDL_CTL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DIT_DQS_REG : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_PHY_DX_DQS_DCC_UNION;
#endif
#define SOC_DDR_PHY_DX_DQS_DCC_DIT_DQS_REG_START (0)
#define SOC_DDR_PHY_DX_DQS_DCC_DIT_DQS_REG_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_VOS_STEP_SEL0 : 1;
        unsigned int DX_RG_VOS_STEP_SEL1 : 1;
        unsigned int DX_RG_VOS_STEP_SEL2 : 1;
        unsigned int DX_RG_VOS_STEP_SEL3 : 1;
        unsigned int DX_RG_VOS_STEP_SEL4 : 1;
        unsigned int DX_RG_VOS_STEP_SEL5 : 1;
        unsigned int DX_RG_VOS_STEP_SEL6 : 1;
        unsigned int DX_RG_VOS_STEP_SEL7 : 1;
        unsigned int DX_RG_VOS_STEP_SEL8 : 1;
        unsigned int DX_IO_PRE_EN9_1 : 1;
        unsigned int DX_RG_VOS_STEP_SEL10 : 1;
        unsigned int DX_IO_PRE_EN11_1 : 1;
        unsigned int DX_IO_PUPDEN_DQS : 1;
        unsigned int DX_IO_PUPDEN_WCK : 1;
        unsigned int DX_IO_PUPDMODE_WCK : 2;
        unsigned int reg_fast_gt_en : 1;
        unsigned int reg_DX_WCK_DA_SIG_SW : 1;
        unsigned int reg_DX_WCK_RG_PRESET_DQS : 2;
        unsigned int reg_DX_WCK_DA_OE_OPTION : 1;
        unsigned int reserved_0 : 3;
        unsigned int reg_DX_DQS_DA_SIG_SW : 1;
        unsigned int reg_DX_DQS_RG_PRESET_DQS : 2;
        unsigned int reg_DX_DQS_DA_OE_OPTION : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_PHY_DX_PRE_EN_BIT1_UNION;
#endif
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL0_START (0)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL0_END (0)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL1_START (1)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL1_END (1)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL2_START (2)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL2_END (2)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL3_START (3)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL3_END (3)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL4_START (4)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL4_END (4)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL5_START (5)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL5_END (5)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL6_START (6)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL6_END (6)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL7_START (7)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL7_END (7)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL8_START (8)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL8_END (8)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN9_1_START (9)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN9_1_END (9)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL10_START (10)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_RG_VOS_STEP_SEL10_END (10)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN11_1_START (11)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN11_1_END (11)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_DQS_START (12)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_DQS_END (12)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_WCK_START (13)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_WCK_END (13)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PUPDMODE_WCK_START (14)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_DX_IO_PUPDMODE_WCK_END (15)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_fast_gt_en_START (16)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_fast_gt_en_END (16)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_SIG_SW_START (17)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_SIG_SW_END (17)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_WCK_RG_PRESET_DQS_START (18)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_WCK_RG_PRESET_DQS_END (19)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_OE_OPTION_START (20)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_OE_OPTION_END (20)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_SIG_SW_START (24)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_SIG_SW_END (24)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_DQS_RG_PRESET_DQS_START (25)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_DQS_RG_PRESET_DQS_END (26)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_OE_OPTION_START (27)
#define SOC_DDR_PHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_OE_OPTION_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rden_stable_thrshld : 8;
        unsigned int rden_stable_max : 8;
        unsigned int gate_err_en : 1;
        unsigned int gate_err_int : 1;
        unsigned int gate_to_int : 1;
        unsigned int gate_uf_int : 1;
        unsigned int rden_lat_gate_num : 3;
        unsigned int reserved_0 : 1;
        unsigned int rden_gate_offset : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_DDR_PHY_DX_GATE_ERR_UNION;
#endif
#define SOC_DDR_PHY_DX_GATE_ERR_rden_stable_thrshld_START (0)
#define SOC_DDR_PHY_DX_GATE_ERR_rden_stable_thrshld_END (7)
#define SOC_DDR_PHY_DX_GATE_ERR_rden_stable_max_START (8)
#define SOC_DDR_PHY_DX_GATE_ERR_rden_stable_max_END (15)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_err_en_START (16)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_err_en_END (16)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_err_int_START (17)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_err_int_END (17)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_to_int_START (18)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_to_int_END (18)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_uf_int_START (19)
#define SOC_DDR_PHY_DX_GATE_ERR_gate_uf_int_END (19)
#define SOC_DDR_PHY_DX_GATE_ERR_rden_lat_gate_num_START (20)
#define SOC_DDR_PHY_DX_GATE_ERR_rden_lat_gate_num_END (22)
#define SOC_DDR_PHY_DX_GATE_ERR_rden_gate_offset_START (24)
#define SOC_DDR_PHY_DX_GATE_ERR_rden_gate_offset_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_dx_txdqm_gcken : 1;
        unsigned int reg_dx_txdqs_gcken : 1;
        unsigned int reg_dx_txwck_gcken : 1;
        unsigned int reg_dx_txdmy_gcken : 1;
        unsigned int reg_dx_txdqm_phcfg : 2;
        unsigned int reg_dx_txdqs_phcfg : 2;
        unsigned int reg_dx_txwck_phcfg : 2;
        unsigned int reg_dx_txdmy_phcfg : 2;
        unsigned int reg_dx_phcfg_auto : 1;
        unsigned int reg_dx_rx_gcken : 1;
        unsigned int reserved : 4;
        unsigned int reg_dx_tx_dq_out_gated_en : 1;
        unsigned int reg_dx_tx_wck_out_gated_en : 1;
        unsigned int reg_dx_tx_dqm_mask : 9;
        unsigned int reg_dx_tx_dmy_mask : 1;
        unsigned int reg_dx_tx_dqs_mask : 1;
        unsigned int reg_dx_tx_wck_mask : 1;
    } reg;
} SOC_DDR_PHY_DX_GCKEN_CTRL_UNION;
#endif
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqm_gcken_START (0)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqm_gcken_END (0)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqs_gcken_START (1)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqs_gcken_END (1)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txwck_gcken_START (2)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txwck_gcken_END (2)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdmy_gcken_START (3)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdmy_gcken_END (3)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqm_phcfg_START (4)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqm_phcfg_END (5)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqs_phcfg_START (6)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdqs_phcfg_END (7)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txwck_phcfg_START (8)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txwck_phcfg_END (9)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdmy_phcfg_START (10)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_txdmy_phcfg_END (11)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_phcfg_auto_START (12)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_phcfg_auto_END (12)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_rx_gcken_START (13)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_rx_gcken_END (13)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dq_out_gated_en_START (18)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dq_out_gated_en_END (18)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_wck_out_gated_en_START (19)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_wck_out_gated_en_END (19)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dqm_mask_START (20)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dqm_mask_END (28)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dmy_mask_START (29)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dmy_mask_END (29)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dqs_mask_START (30)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_dqs_mask_END (30)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_wck_mask_START (31)
#define SOC_DDR_PHY_DX_GCKEN_CTRL_reg_dx_tx_wck_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_RG_OFFSET_K_EN_DQ : 1;
        unsigned int reg_RG_OFFSET_K_EN_DMY : 1;
        unsigned int reg_RG_XRANK_DMY : 3;
        unsigned int reg_RG_XRANK_DM : 3;
        unsigned int reg_DA_OFFSET_DMY_rank0 : 5;
        unsigned int reg_DA_OFFSET_DMY_rank1 : 5;
        unsigned int reg_DA_OFFSET_DM_rank0 : 5;
        unsigned int reg_DA_OFFSET_DM_rank1 : 5;
        unsigned int reg_RG_XRANK_K_EN_DQ : 1;
        unsigned int reg_RG_XRANK_K_EN_DMY : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_DX_XRANK_CTRL_0_UNION;
#endif
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DQ_START (0)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DQ_END (0)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DMY_START (1)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DMY_END (1)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DMY_START (2)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DMY_END (4)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DM_START (5)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DM_END (7)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank0_START (8)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank0_END (12)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank1_START (13)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank1_END (17)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank0_START (18)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank0_END (22)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank1_START (23)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank1_END (27)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DQ_START (28)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DQ_END (28)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DMY_START (29)
#define SOC_DDR_PHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DMY_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_RG_XRANK_DQ0 : 3;
        unsigned int reg_RG_XRANK_DQ1 : 3;
        unsigned int reg_RG_XRANK_DQ2 : 3;
        unsigned int reg_RG_XRANK_DQ3 : 3;
        unsigned int reg_RG_XRANK_DQ4 : 3;
        unsigned int reg_RG_XRANK_DQ5 : 3;
        unsigned int reg_RG_XRANK_DQ6 : 3;
        unsigned int reg_RG_XRANK_DQ7 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_PHY_DX_XRANK_CTRL_1_UNION;
#endif
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ0_START (0)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ0_END (2)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ1_START (3)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ1_END (5)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ2_START (6)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ2_END (8)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ3_START (9)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ3_END (11)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ4_START (12)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ4_END (14)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ5_START (15)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ5_END (17)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ6_START (18)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ6_END (20)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ7_START (21)
#define SOC_DDR_PHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ7_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_DA_OFFSET_DQ0_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ0_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ1_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ1_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ2_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ2_rank1 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_DX_XRANK_CTRL_2_UNION;
#endif
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank0_START (0)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank0_END (4)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank1_START (5)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank1_END (9)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank0_START (10)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank0_END (14)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank1_START (15)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank1_END (19)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank0_START (20)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank0_END (24)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank1_START (25)
#define SOC_DDR_PHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_DA_OFFSET_DQ3_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ3_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ4_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ4_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ5_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ5_rank1 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_DX_XRANK_CTRL_3_UNION;
#endif
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank0_START (0)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank0_END (4)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank1_START (5)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank1_END (9)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank0_START (10)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank0_END (14)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank1_START (15)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank1_END (19)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank0_START (20)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank0_END (24)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank1_START (25)
#define SOC_DDR_PHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_DA_OFFSET_DQ6_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ6_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ7_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ7_rank1 : 5;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_PHY_DX_XRANK_CTRL_4_UNION;
#endif
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank0_START (0)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank0_END (4)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank1_START (5)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank1_END (9)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank0_START (10)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank0_END (14)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank1_START (15)
#define SOC_DDR_PHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq_margin_ext_0 : 4;
        unsigned int dq_margin_ext_1 : 4;
        unsigned int dq_margin_ext_2 : 4;
        unsigned int dq_margin_ext_3 : 4;
        unsigned int dq_margin_ext_4 : 4;
        unsigned int dq_margin_ext_5 : 4;
        unsigned int dq_margin_ext_6 : 4;
        unsigned int dq_margin_ext_7 : 4;
    } reg;
} SOC_DDR_PHY_DX_DQ_MARGIN_EXT_UNION;
#endif
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_0_START (0)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_0_END (3)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_1_START (4)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_1_END (7)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_2_START (8)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_2_END (11)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_3_START (12)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_3_END (15)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_4_START (16)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_4_END (19)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_5_START (20)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_5_END (23)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_6_START (24)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_6_END (27)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_7_START (28)
#define SOC_DDR_PHY_DX_DQ_MARGIN_EXT_dq_margin_ext_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq_margin_ext_8 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_PHY_DX_DM_MARGIN_EXT_UNION;
#endif
#define SOC_DDR_PHY_DX_DM_MARGIN_EXT_dq_margin_ext_8_START (0)
#define SOC_DDR_PHY_DX_DM_MARGIN_EXT_dq_margin_ext_8_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ie_extend_hynix : 5;
        unsigned int reserved_0 : 3;
        unsigned int DX_RG_TEST9_HSB : 8;
        unsigned int DX_RG_TEST11_HSB : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_PHY_DX_DQS_IE_EXTEND_UNION;
#endif
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_ie_extend_hynix_START (0)
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_ie_extend_hynix_END (4)
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_DX_RG_TEST9_HSB_START (8)
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_DX_RG_TEST9_HSB_END (15)
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_DX_RG_TEST11_HSB_START (16)
#define SOC_DDR_PHY_DX_DQS_IE_EXTEND_DX_RG_TEST11_HSB_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST0_HSB : 8;
        unsigned int DX_RG_TEST1_HSB : 8;
        unsigned int DX_RG_TEST2_HSB : 8;
        unsigned int DX_RG_TEST3_HSB : 8;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST0_HSB_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST0_HSB_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST1_HSB_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST1_HSB_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST2_HSB_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST2_HSB_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST3_HSB_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL0_HSB_DX_RG_TEST3_HSB_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST4_HSB : 8;
        unsigned int DX_RG_TEST5_HSB : 8;
        unsigned int DX_RG_TEST6_HSB : 8;
        unsigned int DX_RG_TEST7_HSB : 8;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST4_HSB_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST4_HSB_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST5_HSB_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST5_HSB_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST6_HSB_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST6_HSB_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST7_HSB_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_CTL1_HSB_DX_RG_TEST7_HSB_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST8_HSB : 8;
        unsigned int reserved_0 : 8;
        unsigned int DX_RG_TEST10_HSB : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_CTL2_HSB_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_HSB_DX_RG_TEST8_HSB_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_HSB_DX_RG_TEST8_HSB_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_HSB_DX_RG_TEST10_HSB_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_CTL2_HSB_DX_RG_TEST10_HSB_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_0 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_0 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_0 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_0 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_0_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LEADINGEDGE_P_0_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LEADINGEDGE_P_0_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LEADINGEDGE_N_0_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LEADINGEDGE_N_0_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LAGGINGEDGE_P_0_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LAGGINGEDGE_P_0_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LAGGINGEDGE_N_0_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_LAGGINGEDGE_N_0_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_DFE_EN_0_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_0_DA_DFE_EN_0_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_1 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_1 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_1 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_1 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_1_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LEADINGEDGE_P_1_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LEADINGEDGE_P_1_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LEADINGEDGE_N_1_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LEADINGEDGE_N_1_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LAGGINGEDGE_P_1_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LAGGINGEDGE_P_1_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LAGGINGEDGE_N_1_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_LAGGINGEDGE_N_1_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_DFE_EN_1_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_1_DA_DFE_EN_1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_2 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_2 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_2 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_2 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_2_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LEADINGEDGE_P_2_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LEADINGEDGE_P_2_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LEADINGEDGE_N_2_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LEADINGEDGE_N_2_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LAGGINGEDGE_P_2_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LAGGINGEDGE_P_2_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LAGGINGEDGE_N_2_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_LAGGINGEDGE_N_2_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_DFE_EN_2_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_2_DA_DFE_EN_2_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_3 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_3 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_3 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_3 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_3 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_3_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LEADINGEDGE_P_3_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LEADINGEDGE_P_3_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LEADINGEDGE_N_3_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LEADINGEDGE_N_3_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LAGGINGEDGE_P_3_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LAGGINGEDGE_P_3_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LAGGINGEDGE_N_3_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_LAGGINGEDGE_N_3_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_DFE_EN_3_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_3_DA_DFE_EN_3_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_4 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_4 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_4 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_4 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_4 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_4_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LEADINGEDGE_P_4_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LEADINGEDGE_P_4_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LEADINGEDGE_N_4_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LEADINGEDGE_N_4_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LAGGINGEDGE_P_4_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LAGGINGEDGE_P_4_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LAGGINGEDGE_N_4_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_LAGGINGEDGE_N_4_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_DFE_EN_4_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_4_DA_DFE_EN_4_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_5 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_5 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_5 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_5 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_5 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_5_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LEADINGEDGE_P_5_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LEADINGEDGE_P_5_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LEADINGEDGE_N_5_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LEADINGEDGE_N_5_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LAGGINGEDGE_P_5_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LAGGINGEDGE_P_5_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LAGGINGEDGE_N_5_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_LAGGINGEDGE_N_5_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_DFE_EN_5_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_5_DA_DFE_EN_5_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_6 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_6 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_6 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_6 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_6 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_6_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LEADINGEDGE_P_6_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LEADINGEDGE_P_6_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LEADINGEDGE_N_6_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LEADINGEDGE_N_6_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LAGGINGEDGE_P_6_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LAGGINGEDGE_P_6_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LAGGINGEDGE_N_6_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_LAGGINGEDGE_N_6_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_DFE_EN_6_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_6_DA_DFE_EN_6_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_7 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_7 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_7 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_7 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_7 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_7_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LEADINGEDGE_P_7_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LEADINGEDGE_P_7_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LEADINGEDGE_N_7_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LEADINGEDGE_N_7_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LAGGINGEDGE_P_7_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LAGGINGEDGE_P_7_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LAGGINGEDGE_N_7_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_LAGGINGEDGE_N_7_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_DFE_EN_7_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_7_DA_DFE_EN_7_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DA_LEADINGEDGE_P_8 : 2;
        unsigned int reserved_0 : 2;
        unsigned int DA_LEADINGEDGE_N_8 : 2;
        unsigned int reserved_1 : 2;
        unsigned int DA_LAGGINGEDGE_P_8 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_LAGGINGEDGE_N_8 : 2;
        unsigned int reserved_3 : 2;
        unsigned int DA_DFE_EN_8 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_DDR_PHY_DA_DFE_CTRL_8_UNION;
#endif
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LEADINGEDGE_P_8_START (0)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LEADINGEDGE_P_8_END (1)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LEADINGEDGE_N_8_START (4)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LEADINGEDGE_N_8_END (5)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LAGGINGEDGE_P_8_START (8)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LAGGINGEDGE_P_8_END (9)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LAGGINGEDGE_N_8_START (12)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_LAGGINGEDGE_N_8_END (13)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_DFE_EN_8_START (16)
#define SOC_DDR_PHY_DA_DFE_CTRL_8_DA_DFE_EN_8_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_DCM_SHRES_SEL_0 : 2;
        unsigned int reserved_0 : 2;
        unsigned int RG_DCM_SEL_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int RG_DCM_OFFSETSEL_0 : 4;
        unsigned int RG_DCM_DIV_0 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_DCM_EN_0 : 1;
        unsigned int AD_DCM_CMPT_0 : 1;
        unsigned int AD_DCM_OUT_0 : 8;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_DDR_PHY_DA_DCM_WCK_CTRL_UNION;
#endif
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_SHRES_SEL_0_START (0)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_SHRES_SEL_0_END (1)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_SEL_0_START (4)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_SEL_0_END (4)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_OFFSETSEL_0_START (8)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_OFFSETSEL_0_END (11)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_DIV_0_START (12)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_RG_DCM_DIV_0_END (13)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_DA_DCM_EN_0_START (16)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_DA_DCM_EN_0_END (16)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_AD_DCM_CMPT_0_START (17)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_AD_DCM_CMPT_0_END (17)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_AD_DCM_OUT_0_START (18)
#define SOC_DDR_PHY_DA_DCM_WCK_CTRL_AD_DCM_OUT_0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RG_DCM_SHRES_SEL_1 : 2;
        unsigned int reserved_0 : 2;
        unsigned int RG_DCM_SEL_1 : 1;
        unsigned int reserved_1 : 3;
        unsigned int RG_DCM_OFFSETSEL_1 : 4;
        unsigned int RG_DCM_DIV_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int DA_DCM_EN_1 : 1;
        unsigned int AD_DCM_CMPT_1 : 1;
        unsigned int AD_DCM_OUT_1 : 8;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_DDR_PHY_DA_DCM_DQS_CTRL_UNION;
#endif
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_SHRES_SEL_1_START (0)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_SHRES_SEL_1_END (1)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_SEL_1_START (4)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_SEL_1_END (4)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_OFFSETSEL_1_START (8)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_OFFSETSEL_1_END (11)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_DIV_1_START (12)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_RG_DCM_DIV_1_END (13)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_DA_DCM_EN_1_START (16)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_DA_DCM_EN_1_END (16)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_AD_DCM_CMPT_1_START (17)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_AD_DCM_CMPT_1_END (17)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_AD_DCM_OUT_1_START (18)
#define SOC_DDR_PHY_DA_DCM_DQS_CTRL_AD_DCM_OUT_1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_proc_dx_mux : 1;
        unsigned int fast_proc_dx_dfs_cfg : 1;
        unsigned int fast_proc_dx_rg_tx_en_11 : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_PHY_DX_FAST_PROC_UNION;
#endif
#define SOC_DDR_PHY_DX_FAST_PROC_fast_proc_dx_mux_START (0)
#define SOC_DDR_PHY_DX_FAST_PROC_fast_proc_dx_mux_END (0)
#define SOC_DDR_PHY_DX_FAST_PROC_fast_proc_dx_dfs_cfg_START (1)
#define SOC_DDR_PHY_DX_FAST_PROC_fast_proc_dx_dfs_cfg_END (1)
#define SOC_DDR_PHY_DX_FAST_PROC_fast_proc_dx_rg_tx_en_11_START (2)
#define SOC_DDR_PHY_DX_FAST_PROC_fast_proc_dx_rg_tx_en_11_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST0_NSV : 8;
        unsigned int DX_RG_TEST1_NSV : 8;
        unsigned int DX_RG_TEST2_NSV : 8;
        unsigned int DX_RG_TEST3_NSV : 8;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_NSV0_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST0_NSV_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST0_NSV_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST1_NSV_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST1_NSV_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST2_NSV_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST2_NSV_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST3_NSV_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_NSV0_DX_RG_TEST3_NSV_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST4_NSV : 8;
        unsigned int DX_RG_TEST5_NSV : 8;
        unsigned int DX_RG_TEST6_NSV : 8;
        unsigned int DX_RG_TEST7_NSV : 8;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_NSV1_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST4_NSV_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST4_NSV_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST5_NSV_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST5_NSV_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST6_NSV_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST6_NSV_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST7_NSV_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_NSV1_DX_RG_TEST7_NSV_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST8_NSV : 8;
        unsigned int DX_RG_TEST9_NSV : 8;
        unsigned int DX_RG_TEST10_NSV : 8;
        unsigned int DX_RG_TEST11_NSV : 8;
    } reg;
} SOC_DDR_PHY_DX_RG_TEST_NSV2_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST8_NSV_START (0)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST8_NSV_END (7)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST9_NSV_START (8)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST9_NSV_END (15)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST10_NSV_START (16)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST10_NSV_END (23)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST11_NSV_START (24)
#define SOC_DDR_PHY_DX_RG_TEST_NSV2_DX_RG_TEST11_NSV_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_BHS_DEC_CFG_DQ : 16;
        unsigned int DX_RG_BHS_DEC_CFG_DM : 2;
        unsigned int DX_RG_BHS_DEC_CFG_DQS : 2;
        unsigned int DX_RG_BHS_DEC_CFG_DUMMY : 2;
        unsigned int DX_RG_BHS_DEC_CFG_WCK : 2;
        unsigned int DX_AD_LDO_PR : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_PHY_DX_RG_BHS_CTL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DQ_START (0)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DQ_END (15)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DM_START (16)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DM_END (17)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DQS_START (18)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DQS_END (19)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DUMMY_START (20)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_DUMMY_END (21)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_WCK_START (22)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_RG_BHS_DEC_CFG_WCK_END (23)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_AD_LDO_PR_START (24)
#define SOC_DDR_PHY_DX_RG_BHS_CTL0_DX_AD_LDO_PR_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_ATB_TEST_DQS : 3;
        unsigned int DX_RG_ATB_TEST_WCK : 3;
        unsigned int DX_AD_DLL_PR : 1;
        unsigned int DX_AD_RSV_OUT : 8;
        unsigned int DX_DA_BHS_PR_EN : 12;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_PHY_DX_RG_PHCFG_CTL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_RG_ATB_TEST_DQS_START (0)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_RG_ATB_TEST_DQS_END (2)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_RG_ATB_TEST_WCK_START (3)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_RG_ATB_TEST_WCK_END (5)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_AD_DLL_PR_START (6)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_AD_DLL_PR_END (6)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_AD_RSV_OUT_START (7)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_AD_RSV_OUT_END (14)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_DA_BHS_PR_EN_START (15)
#define SOC_DDR_PHY_DX_RG_PHCFG_CTL0_DX_DA_BHS_PR_EN_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_LDO_PR_DEC_CFG : 2;
        unsigned int DX_RG_LDO_CUR_COMP_SR : 3;
        unsigned int DX_RG_LDO_CUR_COMP_SLICE : 4;
        unsigned int DX_RG_LDO_CUR_COMP_EN : 1;
        unsigned int DX_RG_LDO_R_BIAS_ADJ : 6;
        unsigned int DX_RG_LDO_FVF2_BIAS_ADJ : 2;
        unsigned int DX_RG_LDO_FVF2_EN : 1;
        unsigned int DX_RG_LDO_SRE_EN : 1;
        unsigned int DX_RG_LDO_FVF_BIAS_ADJ : 2;
        unsigned int DX_RG_LDO_REG_BIAS_ADJ : 2;
        unsigned int DX_RG_LDO_COM_CAP_ADJ : 2;
        unsigned int DX_RG_LDO_VOUT_ADJ : 3;
        unsigned int DX_DA_LDO_LP_EN : 1;
        unsigned int DX_DA_LDO_BYPASS : 1;
        unsigned int DX_DA_LDO_EN : 1;
    } reg;
} SOC_DDR_PHY_DX_RG_LDO_CTL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_PR_DEC_CFG_START (0)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_PR_DEC_CFG_END (1)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_CUR_COMP_SR_START (2)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_CUR_COMP_SR_END (4)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_CUR_COMP_SLICE_START (5)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_CUR_COMP_SLICE_END (8)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_CUR_COMP_EN_START (9)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_CUR_COMP_EN_END (9)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_R_BIAS_ADJ_START (10)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_R_BIAS_ADJ_END (15)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_FVF2_BIAS_ADJ_START (16)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_FVF2_BIAS_ADJ_END (17)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_FVF2_EN_START (18)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_FVF2_EN_END (18)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_SRE_EN_START (19)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_SRE_EN_END (19)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_FVF_BIAS_ADJ_START (20)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_FVF_BIAS_ADJ_END (21)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_REG_BIAS_ADJ_START (22)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_REG_BIAS_ADJ_END (23)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_COM_CAP_ADJ_START (24)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_COM_CAP_ADJ_END (25)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_VOUT_ADJ_START (26)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_RG_LDO_VOUT_ADJ_END (28)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_DA_LDO_LP_EN_START (29)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_DA_LDO_LP_EN_END (29)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_DA_LDO_BYPASS_START (30)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_DA_LDO_BYPASS_END (30)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_DA_LDO_EN_START (31)
#define SOC_DDR_PHY_DX_RG_LDO_CTL0_DX_DA_LDO_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_RG_TEST_COMMON : 15;
        unsigned int reserved_0 : 1;
        unsigned int DX_RG_TEST_DLM : 2;
        unsigned int DX_RG_TEST_DLL : 2;
        unsigned int DX_RG_DLL_DIV : 3;
        unsigned int DX_RG_BUF_EN_D : 1;
        unsigned int DX_RG_BUF_EN_C : 1;
        unsigned int DX_RG_BUF_EN_B : 1;
        unsigned int DX_RG_BUF_EN_A : 1;
        unsigned int DX_DA_LDO_PR_EN : 1;
        unsigned int dx_ph_gck_tgval_0 : 1;
        unsigned int dx_ph_gck_tgval_1 : 1;
        unsigned int DX_DA_ANTIAGING_EN : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_TEST_COMMON_START (0)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_TEST_COMMON_END (14)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_TEST_DLM_START (16)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_TEST_DLM_END (17)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_TEST_DLL_START (18)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_TEST_DLL_END (19)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_DLL_DIV_START (20)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_DLL_DIV_END (22)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_D_START (23)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_D_END (23)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_C_START (24)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_C_END (24)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_B_START (25)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_B_END (25)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_A_START (26)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_RG_BUF_EN_A_END (26)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_DA_LDO_PR_EN_START (27)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_DA_LDO_PR_EN_END (27)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_dx_ph_gck_tgval_0_START (28)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_dx_ph_gck_tgval_0_END (28)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_dx_ph_gck_tgval_1_START (29)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_dx_ph_gck_tgval_1_END (29)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_DA_ANTIAGING_EN_START (30)
#define SOC_DDR_PHY_DX_RG_BIT_COMMON_CTL0_DX_DA_ANTIAGING_EN_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_DA_GATE_EN_DQS : 1;
        unsigned int DX_AD_BHS_PR : 12;
        unsigned int reserved : 19;
    } reg;
} SOC_DDR_PHY_DX_RG_CLKBUFF_EN1_UNION;
#endif
#define SOC_DDR_PHY_DX_RG_CLKBUFF_EN1_DX_DA_GATE_EN_DQS_START (0)
#define SOC_DDR_PHY_DX_RG_CLKBUFF_EN1_DX_DA_GATE_EN_DQS_END (0)
#define SOC_DDR_PHY_DX_RG_CLKBUFF_EN1_DX_AD_BHS_PR_START (1)
#define SOC_DDR_PHY_DX_RG_CLKBUFF_EN1_DX_AD_BHS_PR_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_DA_BDLSEL_WCK : 2;
        unsigned int DX_DA_BDLSEL_DQS : 2;
        unsigned int DX_DA_BDLSEL_DQ : 2;
        unsigned int DX_DA_PHASE_INVERSE_WCK_EN : 1;
        unsigned int DX_DA_PHASE_INVERSE_DQS_EN : 1;
        unsigned int DX_DA_PHASE_INVERSE_DQ_EN : 10;
        unsigned int DX_DA_PHASE_DELAY_DQ_EN : 10;
        unsigned int DX_DA_BDLSEL_DMY : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_PHY_DX_DA_PHASE_CTRL_UNION;
#endif
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_WCK_START (0)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_WCK_END (1)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_DQS_START (2)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_DQS_END (3)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_DQ_START (4)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_DQ_END (5)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_INVERSE_WCK_EN_START (6)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_INVERSE_WCK_EN_END (6)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_INVERSE_DQS_EN_START (7)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_INVERSE_DQS_EN_END (7)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_INVERSE_DQ_EN_START (8)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_INVERSE_DQ_EN_END (17)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_DELAY_DQ_EN_START (18)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_PHASE_DELAY_DQ_EN_END (27)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_DMY_START (28)
#define SOC_DDR_PHY_DX_DA_PHASE_CTRL_DX_DA_BDLSEL_DMY_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ie_extend_swift_trk : 5;
        unsigned int swift_trk_rst_gt_bypass : 1;
        unsigned int swift_trk_rst_rdet_bypass : 1;
        unsigned int swift_trk_rdet_bit_en : 9;
        unsigned int swift_trk_dq_glitch_mask_en : 1;
        unsigned int swift_trk_dqs_glitch_mask_en : 1;
        unsigned int swift_trk_wck_glitch_mask_en : 1;
        unsigned int swift_trk_dmy_glitch_mask_en : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_UNION;
#endif
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_ie_extend_swift_trk_START (0)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_ie_extend_swift_trk_END (4)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_rst_gt_bypass_START (5)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_rst_gt_bypass_END (5)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_rst_rdet_bypass_START (6)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_rst_rdet_bypass_END (6)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_rdet_bit_en_START (7)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_rdet_bit_en_END (15)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_dq_glitch_mask_en_START (16)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_dq_glitch_mask_en_END (16)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_dqs_glitch_mask_en_START (17)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_dqs_glitch_mask_en_END (17)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_wck_glitch_mask_en_START (18)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_wck_glitch_mask_en_END (18)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_dmy_glitch_mask_en_START (19)
#define SOC_DDR_PHY_DX_SWIFT_TRK_CTRL_swift_trk_dmy_glitch_mask_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdet_trk_flag_inc : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_PHY_DX_RDET_TRK_FLAG0_UNION;
#endif
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG0_rdet_trk_flag_inc_START (0)
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG0_rdet_trk_flag_inc_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdet_trk_flag_dec : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_PHY_DX_RDET_TRK_FLAG1_UNION;
#endif
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG1_rdet_trk_flag_dec_START (0)
#define SOC_DDR_PHY_DX_RDET_TRK_FLAG1_rdet_trk_flag_dec_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_offset_cal_en : 1;
        unsigned int rxsio_d2s_n_cal_en : 1;
        unsigned int rxsio_d2s_p_cal_en : 1;
        unsigned int rxsio_cal_en : 1;
        unsigned int rxdio_d2s_n_cal_en : 1;
        unsigned int rxdio_cal_en : 1;
        unsigned int reg_ofst_k_cnt_stable_time : 8;
        unsigned int reg_ofst_k_cnt_timeout : 4;
        unsigned int ofst_k_force_timeout : 1;
        unsigned int reg_ofst_k_init_sel : 7;
        unsigned int reg_ofst_k_mod_dir_polar : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_UNION;
#endif
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_hw_offset_cal_en_START (0)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_hw_offset_cal_en_END (0)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxsio_d2s_n_cal_en_START (1)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxsio_d2s_n_cal_en_END (1)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxsio_d2s_p_cal_en_START (2)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxsio_d2s_p_cal_en_END (2)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxsio_cal_en_START (3)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxsio_cal_en_END (3)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxdio_d2s_n_cal_en_START (4)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxdio_d2s_n_cal_en_END (4)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxdio_cal_en_START (5)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_rxdio_cal_en_END (5)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_cnt_stable_time_START (6)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_cnt_stable_time_END (13)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_cnt_timeout_START (14)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_cnt_timeout_END (17)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_ofst_k_force_timeout_START (18)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_ofst_k_force_timeout_END (18)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_init_sel_START (19)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_init_sel_END (25)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_mod_dir_polar_START (26)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL0_reg_ofst_k_mod_dir_polar_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dqs_da_sq_di : 7;
        unsigned int dqs_da_ctle_cal : 7;
        unsigned int reserved_0 : 2;
        unsigned int dm_da_sq_di : 7;
        unsigned int dm_da_ctle_cal : 7;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_UNION;
#endif
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dqs_da_sq_di_START (0)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dqs_da_sq_di_END (6)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dqs_da_ctle_cal_START (7)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dqs_da_ctle_cal_END (13)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dm_da_sq_di_START (16)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dm_da_sq_di_END (22)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dm_da_ctle_cal_START (23)
#define SOC_DDR_PHY_DX_DQSDM_CTLESSTL_CAL_dm_da_ctle_cal_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq1_da_sq_di : 7;
        unsigned int dq1_da_ctle_cal : 7;
        unsigned int reserved_0 : 2;
        unsigned int dq0_da_sq_di : 7;
        unsigned int dq0_da_ctle_cal : 7;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_UNION;
#endif
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq1_da_sq_di_START (0)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq1_da_sq_di_END (6)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq1_da_ctle_cal_START (7)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq1_da_ctle_cal_END (13)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq0_da_sq_di_START (16)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq0_da_sq_di_END (22)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq0_da_ctle_cal_START (23)
#define SOC_DDR_PHY_DX_DQ01_CTLESSTL_CAL_dq0_da_ctle_cal_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq3_da_sq_di : 7;
        unsigned int dq3_da_ctle_cal : 7;
        unsigned int reserved_0 : 2;
        unsigned int dq2_da_sq_di : 7;
        unsigned int dq2_da_ctle_cal : 7;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_UNION;
#endif
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq3_da_sq_di_START (0)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq3_da_sq_di_END (6)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq3_da_ctle_cal_START (7)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq3_da_ctle_cal_END (13)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq2_da_sq_di_START (16)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq2_da_sq_di_END (22)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq2_da_ctle_cal_START (23)
#define SOC_DDR_PHY_DX_DQ23_CTLESSTL_CAL_dq2_da_ctle_cal_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq5_da_sq_di : 7;
        unsigned int dq5_da_ctle_cal : 7;
        unsigned int reserved_0 : 2;
        unsigned int dq4_da_sq_di : 7;
        unsigned int dq4_da_ctle_cal : 7;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_UNION;
#endif
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq5_da_sq_di_START (0)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq5_da_sq_di_END (6)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq5_da_ctle_cal_START (7)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq5_da_ctle_cal_END (13)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq4_da_sq_di_START (16)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq4_da_sq_di_END (22)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq4_da_ctle_cal_START (23)
#define SOC_DDR_PHY_DX_DQ45_CTLESSTL_CAL_dq4_da_ctle_cal_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dq7_da_sq_di : 7;
        unsigned int dq7_da_ctle_cal : 7;
        unsigned int reserved_0 : 2;
        unsigned int dq6_da_sq_di : 7;
        unsigned int dq6_da_ctle_cal : 7;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_UNION;
#endif
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq7_da_sq_di_START (0)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq7_da_sq_di_END (6)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq7_da_ctle_cal_START (7)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq7_da_ctle_cal_END (13)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq6_da_sq_di_START (16)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq6_da_sq_di_END (22)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq6_da_ctle_cal_START (23)
#define SOC_DDR_PHY_DX_DQ67_CTLESSTL_CAL_dq6_da_ctle_cal_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_ofst_k_ofst_sel : 7;
        unsigned int reg_ofst_k_mod_adapt_th : 3;
        unsigned int reg_ofst_k_mod_toggle_th : 3;
        unsigned int reg_ofst_last_upd : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_UNION;
#endif
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_k_ofst_sel_START (0)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_k_ofst_sel_END (6)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_k_mod_adapt_th_START (7)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_k_mod_adapt_th_END (9)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_k_mod_toggle_th_START (10)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_k_mod_toggle_th_END (12)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_last_upd_START (13)
#define SOC_DDR_PHY_DX_CTLESSTL_CAL_CTRL1_reg_ofst_last_upd_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 9;
        unsigned int dq0_cal_flag_ovud : 1;
        unsigned int dq1_cal_flag_ovud : 1;
        unsigned int dq2_cal_flag_ovud : 1;
        unsigned int dq3_cal_flag_ovud : 1;
        unsigned int dq4_cal_flag_ovud : 1;
        unsigned int dq5_cal_flag_ovud : 1;
        unsigned int dq6_cal_flag_ovud : 1;
        unsigned int dq7_cal_flag_ovud : 1;
        unsigned int dm_cal_flag_ovud : 1;
        unsigned int dqs_cal_flag_ovud : 1;
        unsigned int wck_cal_flag_ovud : 1;
        unsigned int dq0_cal_flag_timeout : 1;
        unsigned int dq1_cal_flag_timeout : 1;
        unsigned int dq2_cal_flag_timeout : 1;
        unsigned int dq3_cal_flag_timeout : 1;
        unsigned int dq4_cal_flag_timeout : 1;
        unsigned int dq5_cal_flag_timeout : 1;
        unsigned int dq6_cal_flag_timeout : 1;
        unsigned int dq7_cal_flag_timeout : 1;
        unsigned int dm_cal_flag_timeout : 1;
        unsigned int dqs_cal_flag_timeout : 1;
        unsigned int wck_cal_flag_timeout : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_PHY_DX_DEBUG_SIG_0_UNION;
#endif
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq0_cal_flag_ovud_START (9)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq0_cal_flag_ovud_END (9)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq1_cal_flag_ovud_START (10)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq1_cal_flag_ovud_END (10)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq2_cal_flag_ovud_START (11)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq2_cal_flag_ovud_END (11)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq3_cal_flag_ovud_START (12)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq3_cal_flag_ovud_END (12)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq4_cal_flag_ovud_START (13)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq4_cal_flag_ovud_END (13)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq5_cal_flag_ovud_START (14)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq5_cal_flag_ovud_END (14)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq6_cal_flag_ovud_START (15)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq6_cal_flag_ovud_END (15)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq7_cal_flag_ovud_START (16)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq7_cal_flag_ovud_END (16)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dm_cal_flag_ovud_START (17)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dm_cal_flag_ovud_END (17)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dqs_cal_flag_ovud_START (18)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dqs_cal_flag_ovud_END (18)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_wck_cal_flag_ovud_START (19)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_wck_cal_flag_ovud_END (19)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq0_cal_flag_timeout_START (20)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq0_cal_flag_timeout_END (20)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq1_cal_flag_timeout_START (21)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq1_cal_flag_timeout_END (21)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq2_cal_flag_timeout_START (22)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq2_cal_flag_timeout_END (22)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq3_cal_flag_timeout_START (23)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq3_cal_flag_timeout_END (23)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq4_cal_flag_timeout_START (24)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq4_cal_flag_timeout_END (24)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq5_cal_flag_timeout_START (25)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq5_cal_flag_timeout_END (25)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq6_cal_flag_timeout_START (26)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq6_cal_flag_timeout_END (26)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq7_cal_flag_timeout_START (27)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dq7_cal_flag_timeout_END (27)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dm_cal_flag_timeout_START (28)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dm_cal_flag_timeout_END (28)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dqs_cal_flag_timeout_START (29)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_dqs_cal_flag_timeout_END (29)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_wck_cal_flag_timeout_START (30)
#define SOC_DDR_PHY_DX_DEBUG_SIG_0_wck_cal_flag_timeout_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DX_IO_MODE0_ext : 1;
        unsigned int DX_IO_MODE1_ext : 1;
        unsigned int DX_IO_MODE2_ext : 1;
        unsigned int DX_IO_MODE3_ext : 1;
        unsigned int DX_IO_MODE4_ext : 1;
        unsigned int DX_IO_MODE5_ext : 1;
        unsigned int DX_IO_MODE6_ext : 1;
        unsigned int DX_IO_MODE7_ext : 1;
        unsigned int DX_IO_MODE8_ext : 1;
        unsigned int DX_IO_MODE9_ext : 1;
        unsigned int DX_TX_DCC_BYP_DQ : 1;
        unsigned int DX_TX_DCC_BYP_DQS : 1;
        unsigned int DX_TX_DCC_BYP_WCK : 1;
        unsigned int DX_RX_DCC_BYP_DQ : 1;
        unsigned int DX_RX_DCC_BYP_DQS : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_DDR_PHY_DX_IOMODE_EXT_UNION;
#endif
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE0_ext_START (0)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE0_ext_END (0)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE1_ext_START (1)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE1_ext_END (1)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE2_ext_START (2)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE2_ext_END (2)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE3_ext_START (3)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE3_ext_END (3)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE4_ext_START (4)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE4_ext_END (4)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE5_ext_START (5)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE5_ext_END (5)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE6_ext_START (6)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE6_ext_END (6)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE7_ext_START (7)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE7_ext_END (7)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE8_ext_START (8)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE8_ext_END (8)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE9_ext_START (9)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_IO_MODE9_ext_END (9)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_TX_DCC_BYP_DQ_START (10)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_TX_DCC_BYP_DQ_END (10)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_TX_DCC_BYP_DQS_START (11)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_TX_DCC_BYP_DQS_END (11)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_TX_DCC_BYP_WCK_START (12)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_TX_DCC_BYP_WCK_END (12)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_RX_DCC_BYP_DQ_START (13)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_RX_DCC_BYP_DQ_END (13)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_RX_DCC_BYP_DQS_START (14)
#define SOC_DDR_PHY_DX_IOMODE_EXT_DX_RX_DCC_BYP_DQS_END (14)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
