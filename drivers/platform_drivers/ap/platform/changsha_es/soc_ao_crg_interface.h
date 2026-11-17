#ifndef __SOC_AO_CRG_INTERFACE_H__
#define __SOC_AO_CRG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_AO_CRG_SCSYSSTAT_ADDR(base) ((base) + (0x004UL))
#define SOC_AO_CRG_SCSYSSTAT_1_ADDR(base) ((base) + (0x008UL))
#define SOC_AO_CRG_SC_ULPPLL_GT_CFG_ADDR(base) ((base) + (0x088UL))
#define SOC_AO_CRG_SC_ULPPLL_1_GT_CFG_ADDR(base) ((base) + (0x08CUL))
#define SOC_AO_CRG_SC_PLL_STAT_ADDR(base) ((base) + (0x0CCUL))
#define SOC_AO_CRG_ULPPLL_DT_WORK_EN_VOTE_ADDR(base) ((base) + (0x0D0UL))
#define SOC_AO_CRG_SC_PLL_EN_VOTE_1_ADDR(base) ((base) + (0x0D4UL))
#define SOC_AO_CRG_SC_PLL_EN_VOTE_3_ADDR(base) ((base) + (0x0DCUL))
#define SOC_AO_CRG_SC_PLL_GT_VOTE_1_ADDR(base) ((base) + (0x0E0UL))
#define SOC_AO_CRG_SC_PLL_GT_VOTE_3_ADDR(base) ((base) + (0x0E4UL))
#define SOC_AO_CRG_SC_PLL_BP_VOTE_1_ADDR(base) ((base) + (0x0E8UL))
#define SOC_AO_CRG_SC_PLL_BP_VOTE_3_ADDR(base) ((base) + (0x0ECUL))
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ADDR(base) ((base) + (0x0F0UL))
#define SOC_AO_CRG_SC_ULPPLL_CFG1_ADDR(base) ((base) + (0x0F4UL))
#define SOC_AO_CRG_SC_ULPPLL_CFG2_ADDR(base) ((base) + (0x0F8UL))
#define SOC_AO_CRG_SC_ULPPLL_CFG3_ADDR(base) ((base) + (0x0FCUL))
#define SOC_AO_CRG_SC_ULPPLL_CFG4_ADDR(base) ((base) + (0x100UL))
#define SOC_AO_CRG_SC_ULPPLL_CFG5_ADDR(base) ((base) + (0x104UL))
#define SOC_AO_CRG_SC_ULPPLL_CFG6_ADDR(base) ((base) + (0x108UL))
#define SOC_AO_CRG_SC_ULPPLL_CFG7_ADDR(base) ((base) + (0x10CUL))
#define SOC_AO_CRG_SC_ULPPLL_CFG8_ADDR(base) ((base) + (0x110UL))
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ADDR(base) ((base) + (0x11CUL))
#define SOC_AO_CRG_SC_ULPPLL_STATE0_ADDR(base) ((base) + (0x120UL))
#define SOC_AO_CRG_ULPPLL1_DT_WORK_EN_VOTE_ADDR(base) ((base) + (0x124UL))
#define SOC_AO_CRG_SCPEREN0_ADDR(base) ((base) + (0x160UL))
#define SOC_AO_CRG_SCPERDIS0_ADDR(base) ((base) + (0x164UL))
#define SOC_AO_CRG_SCPERCLKEN0_ADDR(base) ((base) + (0x168UL))
#define SOC_AO_CRG_SCPERSTAT0_ADDR(base) ((base) + (0x16CUL))
#define SOC_AO_CRG_SCPEREN1_ADDR(base) ((base) + (0x170UL))
#define SOC_AO_CRG_SCPERDIS1_ADDR(base) ((base) + (0x174UL))
#define SOC_AO_CRG_SCPERCLKEN1_ADDR(base) ((base) + (0x178UL))
#define SOC_AO_CRG_SCPERSTAT1_ADDR(base) ((base) + (0x17CUL))
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_ADDR(base) ((base) + (0x188UL))
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x18CUL))
#define SOC_AO_CRG_SCPEREN2_ADDR(base) ((base) + (0x190UL))
#define SOC_AO_CRG_SCPERDIS2_ADDR(base) ((base) + (0x194UL))
#define SOC_AO_CRG_SCPERCLKEN2_ADDR(base) ((base) + (0x198UL))
#define SOC_AO_CRG_SCPERSTAT2_ADDR(base) ((base) + (0x19CUL))
#define SOC_AO_CRG_SCPEREN3_ADDR(base) ((base) + (0x1A0UL))
#define SOC_AO_CRG_SCPERDIS3_ADDR(base) ((base) + (0x1A4UL))
#define SOC_AO_CRG_SCPERCLKEN3_ADDR(base) ((base) + (0x1A8UL))
#define SOC_AO_CRG_SCPERSTAT3_ADDR(base) ((base) + (0x1ACUL))
#define SOC_AO_CRG_SCPEREN4_ADDR(base) ((base) + (0x1B0UL))
#define SOC_AO_CRG_SCPERDIS4_ADDR(base) ((base) + (0x1B4UL))
#define SOC_AO_CRG_SCPERCLKEN4_ADDR(base) ((base) + (0x1B8UL))
#define SOC_AO_CRG_SCPERSTAT4_ADDR(base) ((base) + (0x1BCUL))
#define SOC_AO_CRG_SCPEREN5_ADDR(base) ((base) + (0x1C0UL))
#define SOC_AO_CRG_SCPERDIS5_ADDR(base) ((base) + (0x1C4UL))
#define SOC_AO_CRG_SCPERCLKEN5_ADDR(base) ((base) + (0x1C8UL))
#define SOC_AO_CRG_SCPERSTAT5_ADDR(base) ((base) + (0x1CCUL))
#define SOC_AO_CRG_SCPEREN6_ADDR(base) ((base) + (0x1D0UL))
#define SOC_AO_CRG_SCPERDIS6_ADDR(base) ((base) + (0x1D4UL))
#define SOC_AO_CRG_SCPERCLKEN6_ADDR(base) ((base) + (0x1D8UL))
#define SOC_AO_CRG_SCPERSTAT6_ADDR(base) ((base) + (0x1DCUL))
#define SOC_AO_CRG_FNPLL_STATE0_ADDR(base) ((base) + (0x1E8UL))
#define SOC_AO_CRG_SCPERRSTEN0_ADDR(base) ((base) + (0x200UL))
#define SOC_AO_CRG_SCPERRSTDIS0_ADDR(base) ((base) + (0x204UL))
#define SOC_AO_CRG_SCPERRSTSTAT0_ADDR(base) ((base) + (0x208UL))
#define SOC_AO_CRG_SCPERRSTEN1_ADDR(base) ((base) + (0x20CUL))
#define SOC_AO_CRG_SCPERRSTDIS1_ADDR(base) ((base) + (0x210UL))
#define SOC_AO_CRG_SCPERRSTSTAT1_ADDR(base) ((base) + (0x214UL))
#define SOC_AO_CRG_SCPERRSTEN2_ADDR(base) ((base) + (0x218UL))
#define SOC_AO_CRG_SCPERRSTDIS2_ADDR(base) ((base) + (0x21CUL))
#define SOC_AO_CRG_SCPERRSTSTAT2_ADDR(base) ((base) + (0x220UL))
#define SOC_AO_CRG_SCCLKDIV0_ADDR(base) ((base) + (0x250UL))
#define SOC_AO_CRG_SCCLKDIV1_ADDR(base) ((base) + (0x254UL))
#define SOC_AO_CRG_SCCLKDIV2_ADDR(base) ((base) + (0x258UL))
#define SOC_AO_CRG_SCCLKDIV3_ADDR(base) ((base) + (0x25CUL))
#define SOC_AO_CRG_SCCLKDIV4_ADDR(base) ((base) + (0x260UL))
#define SOC_AO_CRG_SCCLKDIV5_ADDR(base) ((base) + (0x264UL))
#define SOC_AO_CRG_SCCLKDIV6_ADDR(base) ((base) + (0x268UL))
#define SOC_AO_CRG_SCCLKDIV7_ADDR(base) ((base) + (0x26CUL))
#define SOC_AO_CRG_SCCLKDIV8_ADDR(base) ((base) + (0x270UL))
#define SOC_AO_CRG_SCCLKDIV9_ADDR(base) ((base) + (0x274UL))
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_ADDR(base) ((base) + (0x27CUL))
#define SOC_AO_CRG_SCCLKDIV10_ADDR(base) ((base) + (0x280UL))
#define SOC_AO_CRG_SCCLKDIV11_ADDR(base) ((base) + (0x284UL))
#define SOC_AO_CRG_SCCLKDIV12_ADDR(base) ((base) + (0x288UL))
#define SOC_AO_CRG_SCCLKDIV13_ADDR(base) ((base) + (0x28CUL))
#define SOC_AO_CRG_SCCLKDIV14_ADDR(base) ((base) + (0x290UL))
#define SOC_AO_CRG_SCCLKDIV15_ADDR(base) ((base) + (0x294UL))
#define SOC_AO_CRG_SCCLKDIV16_ADDR(base) ((base) + (0x298UL))
#define SOC_AO_CRG_SCCLKDIV17_ADDR(base) ((base) + (0x29CUL))
#define SOC_AO_CRG_SCCLKDIV18_ADDR(base) ((base) + (0x2A0UL))
#define SOC_AO_CRG_SCCLKDIV19_ADDR(base) ((base) + (0x2A4UL))
#define SOC_AO_CRG_SCCLKDIV20_ADDR(base) ((base) + (0x2A8UL))
#define SOC_AO_CRG_SCCLKDIV21_ADDR(base) ((base) + (0x2ACUL))
#define SOC_AO_CRG_SCCLKDIV22_ADDR(base) ((base) + (0x2B0UL))
#define SOC_AO_CRG_SCCLKDIV23_ADDR(base) ((base) + (0x2B8UL))
#define SOC_AO_CRG_SCCLKDIV24_ADDR(base) ((base) + (0x2BCUL))
#define SOC_AO_CRG_SC_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x2B4UL))
#define SOC_AO_CRG_SCCLKDIV25_ADDR(base) ((base) + (0x2C0UL))
#define SOC_AO_CRG_SCCLKDIV26_ADDR(base) ((base) + (0x2C4UL))
#define SOC_AO_CRG_SCCLKDIV27_ADDR(base) ((base) + (0x2C8UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ADDR(base) ((base) + (0x2e0UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_ADDR(base) ((base) + (0x2e4UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG2_ADDR(base) ((base) + (0x2e8UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG3_ADDR(base) ((base) + (0x2ecUL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG4_ADDR(base) ((base) + (0x2d0UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG5_ADDR(base) ((base) + (0x2d4UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG6_ADDR(base) ((base) + (0x2d8UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG7_ADDR(base) ((base) + (0x2dCUL))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG8_ADDR(base) ((base) + (0x2f0UL))
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ADDR(base) ((base) + (0x2f4UL))
#define SOC_AO_CRG_SC_ULPPLL_1_STATE0_ADDR(base) ((base) + (0x2f8UL))
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_ADDR(base) ((base) + (0x354UL))
#define SOC_AO_CRG_SCPERSTATUS17_ADDR(base) ((base) + (0x358UL))
#define SOC_AO_CRG_SCPERSTATUS16_ADDR(base) ((base) + (0x35CUL))
#define SOC_AO_CRG_SCPERSTATUS18_ADDR(base) ((base) + (0x360UL))
#define SOC_AO_CRG_SCPERSTATUS19_ADDR(base) ((base) + (0x364UL))
#define SOC_AO_CRG_SCAUPLLCTRL0_ADDR(base) ((base) + (0x490UL))
#define SOC_AO_CRG_SCAUPLLCTRL1_ADDR(base) ((base) + (0x494UL))
#define SOC_AO_CRG_SCAUPLLSSCCTRL_ADDR(base) ((base) + (0x498UL))
#define SOC_AO_CRG_AUFNPLL_CFG0_ADDR(base) ((base) + (0x49CUL))
#define SOC_AO_CRG_AUFNPLL_CFG1_ADDR(base) ((base) + (0x4A0UL))
#define SOC_AO_CRG_AUFNPLL_CFG2_ADDR(base) ((base) + (0x4A4UL))
#define SOC_AO_CRG_AUFNPLL_CFG3_ADDR(base) ((base) + (0x4A8UL))
#define SOC_AO_CRG_AUFNPLL_STATE0_ADDR(base) ((base) + (0x4B4UL))
#define SOC_AO_CRG_AO_AUTODIV2_ADDR(base) ((base) + (0x500UL))
#define SOC_AO_CRG_SCPEREN0_SEC_ADDR(base) ((base) + (0x900UL))
#define SOC_AO_CRG_SCPERDIS0_SEC_ADDR(base) ((base) + (0x904UL))
#define SOC_AO_CRG_SCPERCLKEN0_SEC_ADDR(base) ((base) + (0x908UL))
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ADDR(base) ((base) + (0x910UL))
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ADDR(base) ((base) + (0x914UL))
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ADDR(base) ((base) + (0x918UL))
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ADDR(base) ((base) + (0x990UL))
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ADDR(base) ((base) + (0x994UL))
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ADDR(base) ((base) + (0x998UL))
#define SOC_AO_CRG_SCPERRSTEN2_SEC_ADDR(base) ((base) + (0x9A0UL))
#define SOC_AO_CRG_SCPERRSTDIS2_SEC_ADDR(base) ((base) + (0x9A4UL))
#define SOC_AO_CRG_SCPERRSTSTAT2_SEC_ADDR(base) ((base) + (0x9A8UL))
#define SOC_AO_CRG_SCPEREN3_SEC_ADDR(base) ((base) + (0x9C0UL))
#define SOC_AO_CRG_SCPERDIS3_SEC_ADDR(base) ((base) + (0x9C4UL))
#define SOC_AO_CRG_SCPERCLKEN3_SEC_ADDR(base) ((base) + (0x9C8UL))
#define SOC_AO_CRG_SCPEREN4_SEC_ADDR(base) ((base) + (0x9D0UL))
#define SOC_AO_CRG_SCPERDIS4_SEC_ADDR(base) ((base) + (0x9D4UL))
#define SOC_AO_CRG_SCPERCLKEN4_SEC_ADDR(base) ((base) + (0x9D8UL))
#define SOC_AO_CRG_SCCLKDIV0_SEC_ADDR(base) ((base) + (0x9E0UL))
#define SOC_AO_CRG_SCCLKDIV1_SEC_ADDR(base) ((base) + (0x9E4UL))
#define SOC_AO_CRG_SCCLKDIV2_SEC_ADDR(base) ((base) + (0x9E8UL))
#define SOC_AO_CRG_SCCLKDIV3_SEC_ADDR(base) ((base) + (0x9ECUL))
#define SOC_AO_CRG_SCCLKDIV4_SEC_ADDR(base) ((base) + (0x9F0UL))
#define SOC_AO_CRG_SCCLKDIV5_SEC_ADDR(base) ((base) + (0x9F4UL))
#define SOC_AO_CRG_SCCLKDIV6_SEC_ADDR(base) ((base) + (0x9F8UL))
#define SOC_AO_CRG_SCCLKDIV7_SEC_ADDR(base) ((base) + (0x9FCUL))
#define SOC_AO_CRG_SCCLKDIV8_SEC_ADDR(base) ((base) + (0xA00UL))
#define SOC_AO_CRG_SCCLKDIV9_SEC_ADDR(base) ((base) + (0xA04UL))
#define SOC_AO_CRG_SCCLKDIV10_SEC_ADDR(base) ((base) + (0xA08UL))
#define SOC_AO_CRG_SCCLKDIV11_SEC_ADDR(base) ((base) + (0xA0CUL))
#define SOC_AO_CRG_SCCLKDIV12_SEC_ADDR(base) ((base) + (0xA10UL))
#define SOC_AO_CRG_SCCLKDIV13_SEC_ADDR(base) ((base) + (0xA14UL))
#define SOC_AO_CRG_SCCLKDIV14_SEC_ADDR(base) ((base) + (0xA18UL))
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ADDR(base) ((base) + (0xA84UL))
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ADDR(base) ((base) + (0xA88UL))
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_ADDR(base) ((base) + (0xA8CUL))
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_ADDR(base) ((base) + (0xA90UL))
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_ADDR(base) ((base) + (0xA94UL))
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_ADDR(base) ((base) + (0xA98UL))
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_ADDR(base) ((base) + (0xA9CUL))
#define SOC_AO_CRG_AO_AUTODIV0_ADDR(base) ((base) + (0xB00UL))
#define SOC_AO_CRG_AO_AUTODIV1_ADDR(base) ((base) + (0xB04UL))
#define SOC_AO_CRG_SC_DDRC_CTRL_ADDR(base) ((base) + (0xE38UL))
#define SOC_AO_CRG_SCSPLLCTRL0_ADDR(base) ((base) + (0xF14UL))
#define SOC_AO_CRG_SCSPLLCTRL1_ADDR(base) ((base) + (0xF18UL))
#define SOC_AO_CRG_SCSPLLSSCCTRL_ADDR(base) ((base) + (0xF1CUL))
#define SOC_AO_CRG_SCSPLLCTRL0_LOCK_STAT_ADDR(base) ((base) + (0xF20UL))
#define SOC_AO_CRG_SCSPLLCTRL1_LOCK_STAT_ADDR(base) ((base) + (0xF24UL))
#define SOC_AO_CRG_SCSPLLSSCCTRL_LOCK_STAT_ADDR(base) ((base) + (0xF28UL))
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_ADDR(base) ((base) + (0xF2CUL))
#define SOC_AO_CRG_FNPLL_CFG0_ADDR(base) ((base) + (0xF30UL))
#define SOC_AO_CRG_FNPLL_CFG1_ADDR(base) ((base) + (0xF34UL))
#define SOC_AO_CRG_FNPLL_CFG2_ADDR(base) ((base) + (0xF38UL))
#define SOC_AO_CRG_FNPLL_CFG3_ADDR(base) ((base) + (0xF3CUL))
#define SOC_AO_CRG_FNPLL_LP_CFG0_ADDR(base) ((base) + (0xF40UL))
#define SOC_AO_CRG_FNPLL_LP_CFG1_ADDR(base) ((base) + (0xF44UL))
#define SOC_AO_CRG_FNPLL_LP_CFG2_ADDR(base) ((base) + (0xF48UL))
#define SOC_AO_CRG_FNPLL_LP_CFG3_ADDR(base) ((base) + (0xF4CUL))
#else
#define SOC_AO_CRG_SCSYSSTAT_ADDR(base) ((base) + (0x004))
#define SOC_AO_CRG_SCSYSSTAT_1_ADDR(base) ((base) + (0x008))
#define SOC_AO_CRG_SC_ULPPLL_GT_CFG_ADDR(base) ((base) + (0x088))
#define SOC_AO_CRG_SC_ULPPLL_1_GT_CFG_ADDR(base) ((base) + (0x08C))
#define SOC_AO_CRG_SC_PLL_STAT_ADDR(base) ((base) + (0x0CC))
#define SOC_AO_CRG_ULPPLL_DT_WORK_EN_VOTE_ADDR(base) ((base) + (0x0D0))
#define SOC_AO_CRG_SC_PLL_EN_VOTE_1_ADDR(base) ((base) + (0x0D4))
#define SOC_AO_CRG_SC_PLL_EN_VOTE_3_ADDR(base) ((base) + (0x0DC))
#define SOC_AO_CRG_SC_PLL_GT_VOTE_1_ADDR(base) ((base) + (0x0E0))
#define SOC_AO_CRG_SC_PLL_GT_VOTE_3_ADDR(base) ((base) + (0x0E4))
#define SOC_AO_CRG_SC_PLL_BP_VOTE_1_ADDR(base) ((base) + (0x0E8))
#define SOC_AO_CRG_SC_PLL_BP_VOTE_3_ADDR(base) ((base) + (0x0EC))
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ADDR(base) ((base) + (0x0F0))
#define SOC_AO_CRG_SC_ULPPLL_CFG1_ADDR(base) ((base) + (0x0F4))
#define SOC_AO_CRG_SC_ULPPLL_CFG2_ADDR(base) ((base) + (0x0F8))
#define SOC_AO_CRG_SC_ULPPLL_CFG3_ADDR(base) ((base) + (0x0FC))
#define SOC_AO_CRG_SC_ULPPLL_CFG4_ADDR(base) ((base) + (0x100))
#define SOC_AO_CRG_SC_ULPPLL_CFG5_ADDR(base) ((base) + (0x104))
#define SOC_AO_CRG_SC_ULPPLL_CFG6_ADDR(base) ((base) + (0x108))
#define SOC_AO_CRG_SC_ULPPLL_CFG7_ADDR(base) ((base) + (0x10C))
#define SOC_AO_CRG_SC_ULPPLL_CFG8_ADDR(base) ((base) + (0x110))
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ADDR(base) ((base) + (0x11C))
#define SOC_AO_CRG_SC_ULPPLL_STATE0_ADDR(base) ((base) + (0x120))
#define SOC_AO_CRG_ULPPLL1_DT_WORK_EN_VOTE_ADDR(base) ((base) + (0x124))
#define SOC_AO_CRG_SCPEREN0_ADDR(base) ((base) + (0x160))
#define SOC_AO_CRG_SCPERDIS0_ADDR(base) ((base) + (0x164))
#define SOC_AO_CRG_SCPERCLKEN0_ADDR(base) ((base) + (0x168))
#define SOC_AO_CRG_SCPERSTAT0_ADDR(base) ((base) + (0x16C))
#define SOC_AO_CRG_SCPEREN1_ADDR(base) ((base) + (0x170))
#define SOC_AO_CRG_SCPERDIS1_ADDR(base) ((base) + (0x174))
#define SOC_AO_CRG_SCPERCLKEN1_ADDR(base) ((base) + (0x178))
#define SOC_AO_CRG_SCPERSTAT1_ADDR(base) ((base) + (0x17C))
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_ADDR(base) ((base) + (0x188))
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x18C))
#define SOC_AO_CRG_SCPEREN2_ADDR(base) ((base) + (0x190))
#define SOC_AO_CRG_SCPERDIS2_ADDR(base) ((base) + (0x194))
#define SOC_AO_CRG_SCPERCLKEN2_ADDR(base) ((base) + (0x198))
#define SOC_AO_CRG_SCPERSTAT2_ADDR(base) ((base) + (0x19C))
#define SOC_AO_CRG_SCPEREN3_ADDR(base) ((base) + (0x1A0))
#define SOC_AO_CRG_SCPERDIS3_ADDR(base) ((base) + (0x1A4))
#define SOC_AO_CRG_SCPERCLKEN3_ADDR(base) ((base) + (0x1A8))
#define SOC_AO_CRG_SCPERSTAT3_ADDR(base) ((base) + (0x1AC))
#define SOC_AO_CRG_SCPEREN4_ADDR(base) ((base) + (0x1B0))
#define SOC_AO_CRG_SCPERDIS4_ADDR(base) ((base) + (0x1B4))
#define SOC_AO_CRG_SCPERCLKEN4_ADDR(base) ((base) + (0x1B8))
#define SOC_AO_CRG_SCPERSTAT4_ADDR(base) ((base) + (0x1BC))
#define SOC_AO_CRG_SCPEREN5_ADDR(base) ((base) + (0x1C0))
#define SOC_AO_CRG_SCPERDIS5_ADDR(base) ((base) + (0x1C4))
#define SOC_AO_CRG_SCPERCLKEN5_ADDR(base) ((base) + (0x1C8))
#define SOC_AO_CRG_SCPERSTAT5_ADDR(base) ((base) + (0x1CC))
#define SOC_AO_CRG_SCPEREN6_ADDR(base) ((base) + (0x1D0))
#define SOC_AO_CRG_SCPERDIS6_ADDR(base) ((base) + (0x1D4))
#define SOC_AO_CRG_SCPERCLKEN6_ADDR(base) ((base) + (0x1D8))
#define SOC_AO_CRG_SCPERSTAT6_ADDR(base) ((base) + (0x1DC))
#define SOC_AO_CRG_FNPLL_STATE0_ADDR(base) ((base) + (0x1E8))
#define SOC_AO_CRG_SCPERRSTEN0_ADDR(base) ((base) + (0x200))
#define SOC_AO_CRG_SCPERRSTDIS0_ADDR(base) ((base) + (0x204))
#define SOC_AO_CRG_SCPERRSTSTAT0_ADDR(base) ((base) + (0x208))
#define SOC_AO_CRG_SCPERRSTEN1_ADDR(base) ((base) + (0x20C))
#define SOC_AO_CRG_SCPERRSTDIS1_ADDR(base) ((base) + (0x210))
#define SOC_AO_CRG_SCPERRSTSTAT1_ADDR(base) ((base) + (0x214))
#define SOC_AO_CRG_SCPERRSTEN2_ADDR(base) ((base) + (0x218))
#define SOC_AO_CRG_SCPERRSTDIS2_ADDR(base) ((base) + (0x21C))
#define SOC_AO_CRG_SCPERRSTSTAT2_ADDR(base) ((base) + (0x220))
#define SOC_AO_CRG_SCCLKDIV0_ADDR(base) ((base) + (0x250))
#define SOC_AO_CRG_SCCLKDIV1_ADDR(base) ((base) + (0x254))
#define SOC_AO_CRG_SCCLKDIV2_ADDR(base) ((base) + (0x258))
#define SOC_AO_CRG_SCCLKDIV3_ADDR(base) ((base) + (0x25C))
#define SOC_AO_CRG_SCCLKDIV4_ADDR(base) ((base) + (0x260))
#define SOC_AO_CRG_SCCLKDIV5_ADDR(base) ((base) + (0x264))
#define SOC_AO_CRG_SCCLKDIV6_ADDR(base) ((base) + (0x268))
#define SOC_AO_CRG_SCCLKDIV7_ADDR(base) ((base) + (0x26C))
#define SOC_AO_CRG_SCCLKDIV8_ADDR(base) ((base) + (0x270))
#define SOC_AO_CRG_SCCLKDIV9_ADDR(base) ((base) + (0x274))
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_ADDR(base) ((base) + (0x27C))
#define SOC_AO_CRG_SCCLKDIV10_ADDR(base) ((base) + (0x280))
#define SOC_AO_CRG_SCCLKDIV11_ADDR(base) ((base) + (0x284))
#define SOC_AO_CRG_SCCLKDIV12_ADDR(base) ((base) + (0x288))
#define SOC_AO_CRG_SCCLKDIV13_ADDR(base) ((base) + (0x28C))
#define SOC_AO_CRG_SCCLKDIV14_ADDR(base) ((base) + (0x290))
#define SOC_AO_CRG_SCCLKDIV15_ADDR(base) ((base) + (0x294))
#define SOC_AO_CRG_SCCLKDIV16_ADDR(base) ((base) + (0x298))
#define SOC_AO_CRG_SCCLKDIV17_ADDR(base) ((base) + (0x29C))
#define SOC_AO_CRG_SCCLKDIV18_ADDR(base) ((base) + (0x2A0))
#define SOC_AO_CRG_SCCLKDIV19_ADDR(base) ((base) + (0x2A4))
#define SOC_AO_CRG_SCCLKDIV20_ADDR(base) ((base) + (0x2A8))
#define SOC_AO_CRG_SCCLKDIV21_ADDR(base) ((base) + (0x2AC))
#define SOC_AO_CRG_SCCLKDIV22_ADDR(base) ((base) + (0x2B0))
#define SOC_AO_CRG_SCCLKDIV23_ADDR(base) ((base) + (0x2B8))
#define SOC_AO_CRG_SCCLKDIV24_ADDR(base) ((base) + (0x2BC))
#define SOC_AO_CRG_SC_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x2B4))
#define SOC_AO_CRG_SCCLKDIV25_ADDR(base) ((base) + (0x2C0))
#define SOC_AO_CRG_SCCLKDIV26_ADDR(base) ((base) + (0x2C4))
#define SOC_AO_CRG_SCCLKDIV27_ADDR(base) ((base) + (0x2C8))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ADDR(base) ((base) + (0x2e0))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_ADDR(base) ((base) + (0x2e4))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG2_ADDR(base) ((base) + (0x2e8))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG3_ADDR(base) ((base) + (0x2ec))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG4_ADDR(base) ((base) + (0x2d0))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG5_ADDR(base) ((base) + (0x2d4))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG6_ADDR(base) ((base) + (0x2d8))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG7_ADDR(base) ((base) + (0x2dC))
#define SOC_AO_CRG_SC_ULPPLL_1_CFG8_ADDR(base) ((base) + (0x2f0))
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ADDR(base) ((base) + (0x2f4))
#define SOC_AO_CRG_SC_ULPPLL_1_STATE0_ADDR(base) ((base) + (0x2f8))
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_ADDR(base) ((base) + (0x354))
#define SOC_AO_CRG_SCPERSTATUS17_ADDR(base) ((base) + (0x358))
#define SOC_AO_CRG_SCPERSTATUS16_ADDR(base) ((base) + (0x35C))
#define SOC_AO_CRG_SCPERSTATUS18_ADDR(base) ((base) + (0x360))
#define SOC_AO_CRG_SCPERSTATUS19_ADDR(base) ((base) + (0x364))
#define SOC_AO_CRG_SCAUPLLCTRL0_ADDR(base) ((base) + (0x490))
#define SOC_AO_CRG_SCAUPLLCTRL1_ADDR(base) ((base) + (0x494))
#define SOC_AO_CRG_SCAUPLLSSCCTRL_ADDR(base) ((base) + (0x498))
#define SOC_AO_CRG_AUFNPLL_CFG0_ADDR(base) ((base) + (0x49C))
#define SOC_AO_CRG_AUFNPLL_CFG1_ADDR(base) ((base) + (0x4A0))
#define SOC_AO_CRG_AUFNPLL_CFG2_ADDR(base) ((base) + (0x4A4))
#define SOC_AO_CRG_AUFNPLL_CFG3_ADDR(base) ((base) + (0x4A8))
#define SOC_AO_CRG_AUFNPLL_STATE0_ADDR(base) ((base) + (0x4B4))
#define SOC_AO_CRG_AO_AUTODIV2_ADDR(base) ((base) + (0x500))
#define SOC_AO_CRG_SCPEREN0_SEC_ADDR(base) ((base) + (0x900))
#define SOC_AO_CRG_SCPERDIS0_SEC_ADDR(base) ((base) + (0x904))
#define SOC_AO_CRG_SCPERCLKEN0_SEC_ADDR(base) ((base) + (0x908))
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ADDR(base) ((base) + (0x910))
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ADDR(base) ((base) + (0x914))
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ADDR(base) ((base) + (0x918))
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ADDR(base) ((base) + (0x990))
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ADDR(base) ((base) + (0x994))
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ADDR(base) ((base) + (0x998))
#define SOC_AO_CRG_SCPERRSTEN2_SEC_ADDR(base) ((base) + (0x9A0))
#define SOC_AO_CRG_SCPERRSTDIS2_SEC_ADDR(base) ((base) + (0x9A4))
#define SOC_AO_CRG_SCPERRSTSTAT2_SEC_ADDR(base) ((base) + (0x9A8))
#define SOC_AO_CRG_SCPEREN3_SEC_ADDR(base) ((base) + (0x9C0))
#define SOC_AO_CRG_SCPERDIS3_SEC_ADDR(base) ((base) + (0x9C4))
#define SOC_AO_CRG_SCPERCLKEN3_SEC_ADDR(base) ((base) + (0x9C8))
#define SOC_AO_CRG_SCPEREN4_SEC_ADDR(base) ((base) + (0x9D0))
#define SOC_AO_CRG_SCPERDIS4_SEC_ADDR(base) ((base) + (0x9D4))
#define SOC_AO_CRG_SCPERCLKEN4_SEC_ADDR(base) ((base) + (0x9D8))
#define SOC_AO_CRG_SCCLKDIV0_SEC_ADDR(base) ((base) + (0x9E0))
#define SOC_AO_CRG_SCCLKDIV1_SEC_ADDR(base) ((base) + (0x9E4))
#define SOC_AO_CRG_SCCLKDIV2_SEC_ADDR(base) ((base) + (0x9E8))
#define SOC_AO_CRG_SCCLKDIV3_SEC_ADDR(base) ((base) + (0x9EC))
#define SOC_AO_CRG_SCCLKDIV4_SEC_ADDR(base) ((base) + (0x9F0))
#define SOC_AO_CRG_SCCLKDIV5_SEC_ADDR(base) ((base) + (0x9F4))
#define SOC_AO_CRG_SCCLKDIV6_SEC_ADDR(base) ((base) + (0x9F8))
#define SOC_AO_CRG_SCCLKDIV7_SEC_ADDR(base) ((base) + (0x9FC))
#define SOC_AO_CRG_SCCLKDIV8_SEC_ADDR(base) ((base) + (0xA00))
#define SOC_AO_CRG_SCCLKDIV9_SEC_ADDR(base) ((base) + (0xA04))
#define SOC_AO_CRG_SCCLKDIV10_SEC_ADDR(base) ((base) + (0xA08))
#define SOC_AO_CRG_SCCLKDIV11_SEC_ADDR(base) ((base) + (0xA0C))
#define SOC_AO_CRG_SCCLKDIV12_SEC_ADDR(base) ((base) + (0xA10))
#define SOC_AO_CRG_SCCLKDIV13_SEC_ADDR(base) ((base) + (0xA14))
#define SOC_AO_CRG_SCCLKDIV14_SEC_ADDR(base) ((base) + (0xA18))
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ADDR(base) ((base) + (0xA84))
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ADDR(base) ((base) + (0xA88))
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_ADDR(base) ((base) + (0xA8C))
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_ADDR(base) ((base) + (0xA90))
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_ADDR(base) ((base) + (0xA94))
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_ADDR(base) ((base) + (0xA98))
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_ADDR(base) ((base) + (0xA9C))
#define SOC_AO_CRG_AO_AUTODIV0_ADDR(base) ((base) + (0xB00))
#define SOC_AO_CRG_AO_AUTODIV1_ADDR(base) ((base) + (0xB04))
#define SOC_AO_CRG_SC_DDRC_CTRL_ADDR(base) ((base) + (0xE38))
#define SOC_AO_CRG_SCSPLLCTRL0_ADDR(base) ((base) + (0xF14))
#define SOC_AO_CRG_SCSPLLCTRL1_ADDR(base) ((base) + (0xF18))
#define SOC_AO_CRG_SCSPLLSSCCTRL_ADDR(base) ((base) + (0xF1C))
#define SOC_AO_CRG_SCSPLLCTRL0_LOCK_STAT_ADDR(base) ((base) + (0xF20))
#define SOC_AO_CRG_SCSPLLCTRL1_LOCK_STAT_ADDR(base) ((base) + (0xF24))
#define SOC_AO_CRG_SCSPLLSSCCTRL_LOCK_STAT_ADDR(base) ((base) + (0xF28))
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_ADDR(base) ((base) + (0xF2C))
#define SOC_AO_CRG_FNPLL_CFG0_ADDR(base) ((base) + (0xF30))
#define SOC_AO_CRG_FNPLL_CFG1_ADDR(base) ((base) + (0xF34))
#define SOC_AO_CRG_FNPLL_CFG2_ADDR(base) ((base) + (0xF38))
#define SOC_AO_CRG_FNPLL_CFG3_ADDR(base) ((base) + (0xF3C))
#define SOC_AO_CRG_FNPLL_LP_CFG0_ADDR(base) ((base) + (0xF40))
#define SOC_AO_CRG_FNPLL_LP_CFG1_ADDR(base) ((base) + (0xF44))
#define SOC_AO_CRG_FNPLL_LP_CFG2_ADDR(base) ((base) + (0xF48))
#define SOC_AO_CRG_FNPLL_LP_CFG3_ADDR(base) ((base) + (0xF4C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_req : 1;
        unsigned int wd0_rst_req : 1;
        unsigned int wd1_rst_req : 1;
        unsigned int lpmcu_rst_req : 1;
        unsigned int iomcu_rst_req : 1;
        unsigned int asp_subsys_wd_req : 1;
        unsigned int venc_wd_rst_req : 1;
        unsigned int modem_wd_rst_req : 1;
        unsigned int vdec_wd_rst_req : 1;
        unsigned int wait_ddr_selfreflash_timeout : 1;
        unsigned int ddr_fatal_intr : 4;
        unsigned int ddr_uce_wd_rst_req : 4;
        unsigned int ao_wd_rst_req : 1;
        unsigned int dpa_wdt_sys_rst_req : 1;
        unsigned int ao_wd1_rst_req : 1;
        unsigned int ddr_lp_ctrl_wd_rst_req : 1;
        unsigned int sys_ctrl_wd_rst_req : 1;
        unsigned int gpu_lp_ctrl_wd_rst_req : 1;
        unsigned int cpu_lp_ctrl_wd_rst_req : 1;
        unsigned int meida_lp_ctrl_wd_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_AO_CRG_SCSYSSTAT_UNION;
#endif
#define SOC_AO_CRG_SCSYSSTAT_soft_rst_req_START (0)
#define SOC_AO_CRG_SCSYSSTAT_soft_rst_req_END (0)
#define SOC_AO_CRG_SCSYSSTAT_wd0_rst_req_START (1)
#define SOC_AO_CRG_SCSYSSTAT_wd0_rst_req_END (1)
#define SOC_AO_CRG_SCSYSSTAT_wd1_rst_req_START (2)
#define SOC_AO_CRG_SCSYSSTAT_wd1_rst_req_END (2)
#define SOC_AO_CRG_SCSYSSTAT_lpmcu_rst_req_START (3)
#define SOC_AO_CRG_SCSYSSTAT_lpmcu_rst_req_END (3)
#define SOC_AO_CRG_SCSYSSTAT_iomcu_rst_req_START (4)
#define SOC_AO_CRG_SCSYSSTAT_iomcu_rst_req_END (4)
#define SOC_AO_CRG_SCSYSSTAT_asp_subsys_wd_req_START (5)
#define SOC_AO_CRG_SCSYSSTAT_asp_subsys_wd_req_END (5)
#define SOC_AO_CRG_SCSYSSTAT_venc_wd_rst_req_START (6)
#define SOC_AO_CRG_SCSYSSTAT_venc_wd_rst_req_END (6)
#define SOC_AO_CRG_SCSYSSTAT_modem_wd_rst_req_START (7)
#define SOC_AO_CRG_SCSYSSTAT_modem_wd_rst_req_END (7)
#define SOC_AO_CRG_SCSYSSTAT_vdec_wd_rst_req_START (8)
#define SOC_AO_CRG_SCSYSSTAT_vdec_wd_rst_req_END (8)
#define SOC_AO_CRG_SCSYSSTAT_wait_ddr_selfreflash_timeout_START (9)
#define SOC_AO_CRG_SCSYSSTAT_wait_ddr_selfreflash_timeout_END (9)
#define SOC_AO_CRG_SCSYSSTAT_ddr_fatal_intr_START (10)
#define SOC_AO_CRG_SCSYSSTAT_ddr_fatal_intr_END (13)
#define SOC_AO_CRG_SCSYSSTAT_ddr_uce_wd_rst_req_START (14)
#define SOC_AO_CRG_SCSYSSTAT_ddr_uce_wd_rst_req_END (17)
#define SOC_AO_CRG_SCSYSSTAT_ao_wd_rst_req_START (18)
#define SOC_AO_CRG_SCSYSSTAT_ao_wd_rst_req_END (18)
#define SOC_AO_CRG_SCSYSSTAT_dpa_wdt_sys_rst_req_START (19)
#define SOC_AO_CRG_SCSYSSTAT_dpa_wdt_sys_rst_req_END (19)
#define SOC_AO_CRG_SCSYSSTAT_ao_wd1_rst_req_START (20)
#define SOC_AO_CRG_SCSYSSTAT_ao_wd1_rst_req_END (20)
#define SOC_AO_CRG_SCSYSSTAT_ddr_lp_ctrl_wd_rst_req_START (21)
#define SOC_AO_CRG_SCSYSSTAT_ddr_lp_ctrl_wd_rst_req_END (21)
#define SOC_AO_CRG_SCSYSSTAT_sys_ctrl_wd_rst_req_START (22)
#define SOC_AO_CRG_SCSYSSTAT_sys_ctrl_wd_rst_req_END (22)
#define SOC_AO_CRG_SCSYSSTAT_gpu_lp_ctrl_wd_rst_req_START (23)
#define SOC_AO_CRG_SCSYSSTAT_gpu_lp_ctrl_wd_rst_req_END (23)
#define SOC_AO_CRG_SCSYSSTAT_cpu_lp_ctrl_wd_rst_req_START (24)
#define SOC_AO_CRG_SCSYSSTAT_cpu_lp_ctrl_wd_rst_req_END (24)
#define SOC_AO_CRG_SCSYSSTAT_meida_lp_ctrl_wd_rst_req_START (25)
#define SOC_AO_CRG_SCSYSSTAT_meida_lp_ctrl_wd_rst_req_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_digtsen_dig_temp_rst : 1;
        unsigned int gpu_digtsen_dig_temp_rst : 1;
        unsigned int dig_temp_rst_npu : 1;
        unsigned int tsensor_rst_req_1 : 1;
        unsigned int tsensor_rst_req_0 : 1;
        unsigned int gpu_tsensor1_rst_req : 1;
        unsigned int gpu_tsensor0_rst_req : 1;
        unsigned int cpu_tsensor1_rst_req : 1;
        unsigned int cpu_tsensor0_rst_req : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_AO_CRG_SCSYSSTAT_1_UNION;
#endif
#define SOC_AO_CRG_SCSYSSTAT_1_cpu_digtsen_dig_temp_rst_START (0)
#define SOC_AO_CRG_SCSYSSTAT_1_cpu_digtsen_dig_temp_rst_END (0)
#define SOC_AO_CRG_SCSYSSTAT_1_gpu_digtsen_dig_temp_rst_START (1)
#define SOC_AO_CRG_SCSYSSTAT_1_gpu_digtsen_dig_temp_rst_END (1)
#define SOC_AO_CRG_SCSYSSTAT_1_dig_temp_rst_npu_START (2)
#define SOC_AO_CRG_SCSYSSTAT_1_dig_temp_rst_npu_END (2)
#define SOC_AO_CRG_SCSYSSTAT_1_tsensor_rst_req_1_START (3)
#define SOC_AO_CRG_SCSYSSTAT_1_tsensor_rst_req_1_END (3)
#define SOC_AO_CRG_SCSYSSTAT_1_tsensor_rst_req_0_START (4)
#define SOC_AO_CRG_SCSYSSTAT_1_tsensor_rst_req_0_END (4)
#define SOC_AO_CRG_SCSYSSTAT_1_gpu_tsensor1_rst_req_START (5)
#define SOC_AO_CRG_SCSYSSTAT_1_gpu_tsensor1_rst_req_END (5)
#define SOC_AO_CRG_SCSYSSTAT_1_gpu_tsensor0_rst_req_START (6)
#define SOC_AO_CRG_SCSYSSTAT_1_gpu_tsensor0_rst_req_END (6)
#define SOC_AO_CRG_SCSYSSTAT_1_cpu_tsensor1_rst_req_START (7)
#define SOC_AO_CRG_SCSYSSTAT_1_cpu_tsensor1_rst_req_END (7)
#define SOC_AO_CRG_SCSYSSTAT_1_cpu_tsensor0_rst_req_START (8)
#define SOC_AO_CRG_SCSYSSTAT_1_cpu_tsensor0_rst_req_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_gt_cfg : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_GT_CFG_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_GT_CFG_ulppll_gt_cfg_START (0)
#define SOC_AO_CRG_SC_ULPPLL_GT_CFG_ulppll_gt_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_1_gt_cfg : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_GT_CFG_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_1_GT_CFG_ulppll_1_gt_cfg_START (0)
#define SOC_AO_CRG_SC_ULPPLL_1_GT_CFG_ulppll_1_gt_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_lock : 1;
        unsigned int spll_en_stat : 1;
        unsigned int spll_gt_stat : 1;
        unsigned int spll_bypass_stat : 1;
        unsigned int ulppll_en_stat : 1;
        unsigned int ulppll_gt_stat : 1;
        unsigned int ulppll_bp_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ulppll_1_op_freq_flag : 1;
        unsigned int ulppll_1_sleep_en : 1;
        unsigned int ulppll_op_freq_flag : 1;
        unsigned int ulppll_1_en_stat : 1;
        unsigned int ulppll_1_gt_stat : 1;
        unsigned int ulppll_1_bp_stat : 1;
        unsigned int ulppll_sleep_en : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_STAT_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_STAT_spll_lock_START (0)
#define SOC_AO_CRG_SC_PLL_STAT_spll_lock_END (0)
#define SOC_AO_CRG_SC_PLL_STAT_spll_en_stat_START (1)
#define SOC_AO_CRG_SC_PLL_STAT_spll_en_stat_END (1)
#define SOC_AO_CRG_SC_PLL_STAT_spll_gt_stat_START (2)
#define SOC_AO_CRG_SC_PLL_STAT_spll_gt_stat_END (2)
#define SOC_AO_CRG_SC_PLL_STAT_spll_bypass_stat_START (3)
#define SOC_AO_CRG_SC_PLL_STAT_spll_bypass_stat_END (3)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_en_stat_START (4)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_en_stat_END (4)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_gt_stat_START (5)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_gt_stat_END (5)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_bp_stat_START (6)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_bp_stat_END (6)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_op_freq_flag_START (9)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_op_freq_flag_END (9)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_sleep_en_START (10)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_sleep_en_END (10)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_op_freq_flag_START (11)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_op_freq_flag_END (11)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_en_stat_START (12)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_en_stat_END (12)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_gt_stat_START (13)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_gt_stat_END (13)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_bp_stat_START (14)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_1_bp_stat_END (14)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_sleep_en_START (15)
#define SOC_AO_CRG_SC_PLL_STAT_ulppll_sleep_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_dt_work_en_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_ULPPLL_DT_WORK_EN_VOTE_UNION;
#endif
#define SOC_AO_CRG_ULPPLL_DT_WORK_EN_VOTE_ulppll_dt_work_en_vote_START (0)
#define SOC_AO_CRG_ULPPLL_DT_WORK_EN_VOTE_ulppll_dt_work_en_vote_END (15)
#define SOC_AO_CRG_ULPPLL_DT_WORK_EN_VOTE_bitmasken_START (16)
#define SOC_AO_CRG_ULPPLL_DT_WORK_EN_VOTE_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_en_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_EN_VOTE_1_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_EN_VOTE_1_ulppll_en_vote_START (0)
#define SOC_AO_CRG_SC_PLL_EN_VOTE_1_ulppll_en_vote_END (15)
#define SOC_AO_CRG_SC_PLL_EN_VOTE_1_bitmasken_START (16)
#define SOC_AO_CRG_SC_PLL_EN_VOTE_1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_1_en_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_EN_VOTE_3_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_EN_VOTE_3_ulppll_1_en_vote_START (0)
#define SOC_AO_CRG_SC_PLL_EN_VOTE_3_ulppll_1_en_vote_END (15)
#define SOC_AO_CRG_SC_PLL_EN_VOTE_3_bitmasken_START (16)
#define SOC_AO_CRG_SC_PLL_EN_VOTE_3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_gt_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_GT_VOTE_1_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_GT_VOTE_1_ulppll_gt_vote_START (0)
#define SOC_AO_CRG_SC_PLL_GT_VOTE_1_ulppll_gt_vote_END (15)
#define SOC_AO_CRG_SC_PLL_GT_VOTE_1_bitmasken_START (16)
#define SOC_AO_CRG_SC_PLL_GT_VOTE_1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_1_gt_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_GT_VOTE_3_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_GT_VOTE_3_ulppll_1_gt_vote_START (0)
#define SOC_AO_CRG_SC_PLL_GT_VOTE_3_ulppll_1_gt_vote_END (15)
#define SOC_AO_CRG_SC_PLL_GT_VOTE_3_bitmasken_START (16)
#define SOC_AO_CRG_SC_PLL_GT_VOTE_3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_bp_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_BP_VOTE_1_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_BP_VOTE_1_ulppll_bp_vote_START (0)
#define SOC_AO_CRG_SC_PLL_BP_VOTE_1_ulppll_bp_vote_END (15)
#define SOC_AO_CRG_SC_PLL_BP_VOTE_1_bitmasken_START (16)
#define SOC_AO_CRG_SC_PLL_BP_VOTE_1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_1_bp_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_BP_VOTE_3_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_BP_VOTE_3_ulppll_1_bp_vote_START (0)
#define SOC_AO_CRG_SC_PLL_BP_VOTE_3_ulppll_1_bp_vote_END (15)
#define SOC_AO_CRG_SC_PLL_BP_VOTE_3_bitmasken_START (16)
#define SOC_AO_CRG_SC_PLL_BP_VOTE_3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int x2_en_cfg : 1;
        unsigned int reserved : 1;
        unsigned int ki_s : 4;
        unsigned int ki_e : 3;
        unsigned int kp_s : 3;
        unsigned int kp_e : 3;
        unsigned int ki_s_x2 : 4;
        unsigned int ki_e_x2 : 3;
        unsigned int kp_s_x2 : 3;
        unsigned int kp_e_x2 : 3;
        unsigned int kdco_ctrl_cfg_en : 1;
        unsigned int kdco_ctrl_cfg : 3;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG0_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_CFG0_x2_en_cfg_START (0)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_x2_en_cfg_END (0)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_s_START (2)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_s_END (5)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_e_START (6)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_e_END (8)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_s_START (9)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_s_END (11)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_e_START (12)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_e_END (14)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_s_x2_START (15)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_s_x2_END (18)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_e_x2_START (19)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_ki_e_x2_END (21)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_s_x2_START (22)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_s_x2_END (24)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_e_x2_START (25)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kp_e_x2_END (27)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kdco_ctrl_cfg_en_START (28)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kdco_ctrl_cfg_en_END (28)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kdco_ctrl_cfg_START (29)
#define SOC_AO_CRG_SC_ULPPLL_CFG0_kdco_ctrl_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_vld : 1;
        unsigned int cfg_sel : 2;
        unsigned int rst_cfg_n : 1;
        unsigned int test_data_sel : 4;
        unsigned int read_en : 1;
        unsigned int test_ck_en : 1;
        unsigned int filter_rhm_sw_pll : 1;
        unsigned int swcap_en : 1;
        unsigned int delay_sel : 4;
        unsigned int sel_d2a_swcap : 2;
        unsigned int ulppll_ana_cfg : 5;
        unsigned int reserved : 9;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG1_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_CFG1_cfg_vld_START (0)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_cfg_vld_END (0)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_cfg_sel_START (1)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_cfg_sel_END (2)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_rst_cfg_n_START (3)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_rst_cfg_n_END (3)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_test_data_sel_START (4)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_test_data_sel_END (7)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_read_en_START (8)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_read_en_END (8)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_test_ck_en_START (9)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_test_ck_en_END (9)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_filter_rhm_sw_pll_START (10)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_filter_rhm_sw_pll_END (10)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_swcap_en_START (11)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_swcap_en_END (11)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_delay_sel_START (12)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_delay_sel_END (15)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_sel_d2a_swcap_START (16)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_sel_d2a_swcap_END (17)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_ulppll_ana_cfg_START (18)
#define SOC_AO_CRG_SC_ULPPLL_CFG1_ulppll_ana_cfg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CFG8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_en : 1;
        unsigned int ulppll_bypass : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int ulppll_fbdiv : 15;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_CTRL0_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ulppll_en_START (0)
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ulppll_en_END (0)
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ulppll_bypass_START (1)
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ulppll_bypass_END (1)
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ulppll_fbdiv_START (8)
#define SOC_AO_CRG_SC_ULPPLL_CTRL0_ulppll_fbdiv_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_STATE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll1_dt_work_en_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_ULPPLL1_DT_WORK_EN_VOTE_UNION;
#endif
#define SOC_AO_CRG_ULPPLL1_DT_WORK_EN_VOTE_ulppll1_dt_work_en_vote_START (0)
#define SOC_AO_CRG_ULPPLL1_DT_WORK_EN_VOTE_ulppll1_dt_work_en_vote_END (15)
#define SOC_AO_CRG_ULPPLL1_DT_WORK_EN_VOTE_bitmasken_START (16)
#define SOC_AO_CRG_ULPPLL1_DT_WORK_EN_VOTE_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_rtc : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer0 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_mad_32k : 1;
        unsigned int gt_clk_fll_test_src : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_pclk_blpwm0 : 1;
        unsigned int gt_clk_isp_snclk3 : 1;
        unsigned int gt_clk_isp_snclk2 : 1;
        unsigned int gt_clk_isp_snclk1 : 1;
        unsigned int gt_clk_isp_snclk0 : 1;
        unsigned int gt_pclk_ao_ioc : 1;
        unsigned int gt_pclk_blpwm2 : 1;
        unsigned int gt_clk_mad_acpu : 1;
        unsigned int gt_clk_jtag_auth : 1;
        unsigned int gt_pclk_syscnt : 1;
        unsigned int gt_clk_syscnt : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_clk_asp_tcxo : 1;
        unsigned int gt_pclk_bbpdrx : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_AO_CRG_SCPEREN0_UNION;
#endif
#define SOC_AO_CRG_SCPEREN0_gt_pclk_rtc_START (1)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_rtc_END (1)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_timer0_START (3)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_timer0_END (3)
#define SOC_AO_CRG_SCPEREN0_gt_clk_mad_32k_START (5)
#define SOC_AO_CRG_SCPEREN0_gt_clk_mad_32k_END (5)
#define SOC_AO_CRG_SCPEREN0_gt_clk_fll_test_src_START (6)
#define SOC_AO_CRG_SCPEREN0_gt_clk_fll_test_src_END (6)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_blpwm0_START (10)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_blpwm0_END (10)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk3_START (11)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk3_END (11)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk2_START (12)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk2_END (12)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk1_START (13)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk1_END (13)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk0_START (14)
#define SOC_AO_CRG_SCPEREN0_gt_clk_isp_snclk0_END (14)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_ao_ioc_START (15)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_ao_ioc_END (15)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_blpwm2_START (16)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_blpwm2_END (16)
#define SOC_AO_CRG_SCPEREN0_gt_clk_mad_acpu_START (17)
#define SOC_AO_CRG_SCPEREN0_gt_clk_mad_acpu_END (17)
#define SOC_AO_CRG_SCPEREN0_gt_clk_jtag_auth_START (18)
#define SOC_AO_CRG_SCPEREN0_gt_clk_jtag_auth_END (18)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_syscnt_START (19)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_syscnt_END (19)
#define SOC_AO_CRG_SCPEREN0_gt_clk_syscnt_START (20)
#define SOC_AO_CRG_SCPEREN0_gt_clk_syscnt_END (20)
#define SOC_AO_CRG_SCPEREN0_gt_clk_asp_tcxo_START (27)
#define SOC_AO_CRG_SCPEREN0_gt_clk_asp_tcxo_END (27)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_bbpdrx_START (28)
#define SOC_AO_CRG_SCPEREN0_gt_pclk_bbpdrx_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_rtc : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer0 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_mad_32k : 1;
        unsigned int gt_clk_fll_test_src : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_pclk_blpwm0 : 1;
        unsigned int gt_clk_isp_snclk3 : 1;
        unsigned int gt_clk_isp_snclk2 : 1;
        unsigned int gt_clk_isp_snclk1 : 1;
        unsigned int gt_clk_isp_snclk0 : 1;
        unsigned int gt_pclk_ao_ioc : 1;
        unsigned int gt_pclk_blpwm2 : 1;
        unsigned int gt_clk_mad_acpu : 1;
        unsigned int gt_clk_jtag_auth : 1;
        unsigned int gt_pclk_syscnt : 1;
        unsigned int gt_clk_syscnt : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_clk_asp_tcxo : 1;
        unsigned int gt_pclk_bbpdrx : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS0_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_rtc_START (1)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_rtc_END (1)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_timer0_START (3)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_timer0_END (3)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_mad_32k_START (5)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_mad_32k_END (5)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_fll_test_src_START (6)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_fll_test_src_END (6)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_blpwm0_START (10)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_blpwm0_END (10)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk3_START (11)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk3_END (11)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk2_START (12)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk2_END (12)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk1_START (13)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk1_END (13)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk0_START (14)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_isp_snclk0_END (14)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_ao_ioc_START (15)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_ao_ioc_END (15)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_blpwm2_START (16)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_blpwm2_END (16)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_mad_acpu_START (17)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_mad_acpu_END (17)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_jtag_auth_START (18)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_jtag_auth_END (18)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_syscnt_START (19)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_syscnt_END (19)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_syscnt_START (20)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_syscnt_END (20)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_asp_tcxo_START (27)
#define SOC_AO_CRG_SCPERDIS0_gt_clk_asp_tcxo_END (27)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_bbpdrx_START (28)
#define SOC_AO_CRG_SCPERDIS0_gt_pclk_bbpdrx_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_rtc : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer0 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_mad_32k : 1;
        unsigned int gt_clk_fll_test_src : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_pclk_blpwm0 : 1;
        unsigned int gt_clk_isp_snclk3 : 1;
        unsigned int gt_clk_isp_snclk2 : 1;
        unsigned int gt_clk_isp_snclk1 : 1;
        unsigned int gt_clk_isp_snclk0 : 1;
        unsigned int gt_pclk_ao_ioc : 1;
        unsigned int gt_pclk_blpwm2 : 1;
        unsigned int gt_clk_mad_acpu : 1;
        unsigned int gt_clk_jtag_auth : 1;
        unsigned int gt_pclk_syscnt : 1;
        unsigned int gt_clk_syscnt : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_clk_asp_tcxo : 1;
        unsigned int gt_pclk_bbpdrx : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN0_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_rtc_START (1)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_rtc_END (1)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_timer0_START (3)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_timer0_END (3)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_mad_32k_START (5)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_mad_32k_END (5)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_fll_test_src_START (6)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_fll_test_src_END (6)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_blpwm0_START (10)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_blpwm0_END (10)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk3_START (11)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk3_END (11)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk2_START (12)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk2_END (12)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk1_START (13)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk1_END (13)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk0_START (14)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_isp_snclk0_END (14)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_ao_ioc_START (15)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_ao_ioc_END (15)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_blpwm2_START (16)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_blpwm2_END (16)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_mad_acpu_START (17)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_mad_acpu_END (17)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_jtag_auth_START (18)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_jtag_auth_END (18)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_syscnt_START (19)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_syscnt_END (19)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_syscnt_START (20)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_syscnt_END (20)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_asp_tcxo_START (27)
#define SOC_AO_CRG_SCPERCLKEN0_gt_clk_asp_tcxo_END (27)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_bbpdrx_START (28)
#define SOC_AO_CRG_SCPERCLKEN0_gt_pclk_bbpdrx_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_ref_crc : 1;
        unsigned int st_pclk_rtc : 1;
        unsigned int st_pclk_rtc1 : 1;
        unsigned int st_pclk_timer0 : 1;
        unsigned int reserved : 1;
        unsigned int st_pclk_timer1 : 1;
        unsigned int st_pclk_blpwm0 : 1;
        unsigned int st_pclk_timer2 : 1;
        unsigned int st_clk_isp_snclk3 : 1;
        unsigned int st_pclk_timer3 : 1;
        unsigned int st_clk_isp_snclk2 : 1;
        unsigned int aupll_sscg_idle : 1;
        unsigned int spll_sscg_idle : 1;
        unsigned int st_clk_pcie0_aux : 1;
        unsigned int st_clk_pcie1_aux : 1;
        unsigned int st_pclk_ao_ioc : 1;
        unsigned int st_pclk_blpwm2 : 1;
        unsigned int st_clk_out0 : 1;
        unsigned int st_clk_jtag_auth : 1;
        unsigned int st_pclk_syscnt : 1;
        unsigned int st_clk_syscnt : 1;
        unsigned int st_clk_out2 : 1;
        unsigned int st_clk_isp_snclk1 : 1;
        unsigned int st_clk_sci0 : 1;
        unsigned int st_clk_sci1 : 1;
        unsigned int st_clk_mad : 1;
        unsigned int st_clk_asp_subsys : 1;
        unsigned int st_clk_asp_tcxo : 1;
        unsigned int st_pclk_bbpdrx : 1;
        unsigned int st_clk_isp_snclk0 : 1;
        unsigned int st_pclk_efusec : 1;
        unsigned int st_clk_spll_sscg : 1;
    } reg;
} SOC_AO_CRG_SCPERSTAT0_UNION;
#endif
#define SOC_AO_CRG_SCPERSTAT0_st_clk_ref_crc_START (0)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_ref_crc_END (0)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_rtc_START (1)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_rtc_END (1)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_rtc1_START (2)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_rtc1_END (2)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer0_START (3)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer0_END (3)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer1_START (5)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer1_END (5)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_blpwm0_START (6)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_blpwm0_END (6)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer2_START (7)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer2_END (7)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk3_START (8)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk3_END (8)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer3_START (9)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_timer3_END (9)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk2_START (10)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk2_END (10)
#define SOC_AO_CRG_SCPERSTAT0_aupll_sscg_idle_START (11)
#define SOC_AO_CRG_SCPERSTAT0_aupll_sscg_idle_END (11)
#define SOC_AO_CRG_SCPERSTAT0_spll_sscg_idle_START (12)
#define SOC_AO_CRG_SCPERSTAT0_spll_sscg_idle_END (12)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_pcie0_aux_START (13)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_pcie0_aux_END (13)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_pcie1_aux_START (14)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_pcie1_aux_END (14)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_ao_ioc_START (15)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_ao_ioc_END (15)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_blpwm2_START (16)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_blpwm2_END (16)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_out0_START (17)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_out0_END (17)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_jtag_auth_START (18)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_jtag_auth_END (18)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_syscnt_START (19)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_syscnt_END (19)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_syscnt_START (20)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_syscnt_END (20)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_out2_START (21)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_out2_END (21)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk1_START (22)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk1_END (22)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_sci0_START (23)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_sci0_END (23)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_sci1_START (24)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_sci1_END (24)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_mad_START (25)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_mad_END (25)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_asp_subsys_START (26)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_asp_subsys_END (26)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_asp_tcxo_START (27)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_asp_tcxo_END (27)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_bbpdrx_START (28)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_bbpdrx_END (28)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk0_START (29)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_isp_snclk0_END (29)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_efusec_START (30)
#define SOC_AO_CRG_SCPERSTAT0_st_pclk_efusec_END (30)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_spll_sscg_START (31)
#define SOC_AO_CRG_SCPERSTAT0_st_clk_spll_sscg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_asp_dw_axi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_asp_cfg : 1;
        unsigned int gt_clk_asp_subsys_acpu : 1;
        unsigned int gt_clk_em_sync_top : 1;
        unsigned int gt_clk_ao_camera : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_hsdt0_pcie_aux : 1;
        unsigned int gt_clk_fll_src_tp : 1;
        unsigned int gt_pclk_timer4 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_timer5 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_pclk_timer6 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_pclk_timer8 : 1;
        unsigned int gt_clk_pcie0_aux : 1;
        unsigned int gt_clk_pcie1_aux : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_noc_aobus2aspbus : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_asp_codec_acpu : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int wait_ddr_selfreflash_done_bypass : 1;
    } reg;
} SOC_AO_CRG_SCPEREN1_UNION;
#endif
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_dw_axi_START (0)
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_dw_axi_END (0)
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_cfg_START (3)
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_cfg_END (3)
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_subsys_acpu_START (4)
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_subsys_acpu_END (4)
#define SOC_AO_CRG_SCPEREN1_gt_clk_em_sync_top_START (5)
#define SOC_AO_CRG_SCPEREN1_gt_clk_em_sync_top_END (5)
#define SOC_AO_CRG_SCPEREN1_gt_clk_ao_camera_START (6)
#define SOC_AO_CRG_SCPEREN1_gt_clk_ao_camera_END (6)
#define SOC_AO_CRG_SCPEREN1_gt_clk_hsdt0_pcie_aux_START (8)
#define SOC_AO_CRG_SCPEREN1_gt_clk_hsdt0_pcie_aux_END (8)
#define SOC_AO_CRG_SCPEREN1_gt_clk_fll_src_tp_START (9)
#define SOC_AO_CRG_SCPEREN1_gt_clk_fll_src_tp_END (9)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer4_START (10)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer4_END (10)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer5_START (12)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer5_END (12)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer6_START (14)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer6_END (14)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer8_START (18)
#define SOC_AO_CRG_SCPEREN1_gt_pclk_timer8_END (18)
#define SOC_AO_CRG_SCPEREN1_gt_clk_pcie0_aux_START (19)
#define SOC_AO_CRG_SCPEREN1_gt_clk_pcie0_aux_END (19)
#define SOC_AO_CRG_SCPEREN1_gt_clk_pcie1_aux_START (20)
#define SOC_AO_CRG_SCPEREN1_gt_clk_pcie1_aux_END (20)
#define SOC_AO_CRG_SCPEREN1_gt_clk_noc_aobus2aspbus_START (24)
#define SOC_AO_CRG_SCPEREN1_gt_clk_noc_aobus2aspbus_END (24)
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_codec_acpu_START (27)
#define SOC_AO_CRG_SCPEREN1_gt_clk_asp_codec_acpu_END (27)
#define SOC_AO_CRG_SCPEREN1_wait_ddr_selfreflash_done_bypass_START (31)
#define SOC_AO_CRG_SCPEREN1_wait_ddr_selfreflash_done_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_asp_dw_axi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_asp_cfg : 1;
        unsigned int gt_clk_asp_subsys_acpu : 1;
        unsigned int gt_clk_em_sync_top : 1;
        unsigned int gt_clk_ao_camera : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_hsdt0_pcie_aux : 1;
        unsigned int gt_clk_fll_src_tp : 1;
        unsigned int gt_pclk_timer4 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_timer5 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_pclk_timer6 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_pclk_timer8 : 1;
        unsigned int gt_clk_pcie0_aux : 1;
        unsigned int gt_clk_pcie1_aux : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_noc_aobus2aspbus : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_asp_codec_acpu : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int wait_ddr_selfreflash_done_bypass : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS1_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_dw_axi_START (0)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_dw_axi_END (0)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_cfg_START (3)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_cfg_END (3)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_subsys_acpu_START (4)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_subsys_acpu_END (4)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_em_sync_top_START (5)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_em_sync_top_END (5)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_ao_camera_START (6)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_ao_camera_END (6)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_hsdt0_pcie_aux_START (8)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_hsdt0_pcie_aux_END (8)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_fll_src_tp_START (9)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_fll_src_tp_END (9)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer4_START (10)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer4_END (10)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer5_START (12)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer5_END (12)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer6_START (14)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer6_END (14)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer8_START (18)
#define SOC_AO_CRG_SCPERDIS1_gt_pclk_timer8_END (18)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_pcie0_aux_START (19)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_pcie0_aux_END (19)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_pcie1_aux_START (20)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_pcie1_aux_END (20)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_noc_aobus2aspbus_START (24)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_noc_aobus2aspbus_END (24)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_codec_acpu_START (27)
#define SOC_AO_CRG_SCPERDIS1_gt_clk_asp_codec_acpu_END (27)
#define SOC_AO_CRG_SCPERDIS1_wait_ddr_selfreflash_done_bypass_START (31)
#define SOC_AO_CRG_SCPERDIS1_wait_ddr_selfreflash_done_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_asp_dw_axi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_asp_cfg : 1;
        unsigned int gt_clk_asp_subsys_acpu : 1;
        unsigned int gt_clk_em_sync_top : 1;
        unsigned int gt_clk_ao_camera : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_hsdt0_pcie_aux : 1;
        unsigned int gt_clk_fll_src_tp : 1;
        unsigned int gt_pclk_timer4 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_timer5 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_pclk_timer6 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_pclk_timer8 : 1;
        unsigned int gt_clk_pcie0_aux : 1;
        unsigned int gt_clk_pcie1_aux : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_noc_aobus2aspbus : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_asp_codec_acpu : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int wait_ddr_selfreflash_done_bypass : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN1_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_dw_axi_START (0)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_dw_axi_END (0)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_cfg_START (3)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_cfg_END (3)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_subsys_acpu_START (4)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_subsys_acpu_END (4)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_em_sync_top_START (5)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_em_sync_top_END (5)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_ao_camera_START (6)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_ao_camera_END (6)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_hsdt0_pcie_aux_START (8)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_hsdt0_pcie_aux_END (8)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_fll_src_tp_START (9)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_fll_src_tp_END (9)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer4_START (10)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer4_END (10)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer5_START (12)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer5_END (12)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer6_START (14)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer6_END (14)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer8_START (18)
#define SOC_AO_CRG_SCPERCLKEN1_gt_pclk_timer8_END (18)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_pcie0_aux_START (19)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_pcie0_aux_END (19)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_pcie1_aux_START (20)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_pcie1_aux_END (20)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_noc_aobus2aspbus_START (24)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_noc_aobus2aspbus_END (24)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_codec_acpu_START (27)
#define SOC_AO_CRG_SCPERCLKEN1_gt_clk_asp_codec_acpu_END (27)
#define SOC_AO_CRG_SCPERCLKEN1_wait_ddr_selfreflash_done_bypass_START (31)
#define SOC_AO_CRG_SCPERCLKEN1_wait_ddr_selfreflash_done_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_asp_dw_axi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_asp_cfg : 1;
        unsigned int st_clk_mad_axi : 1;
        unsigned int st_clk_noc_aobus2sysbusddrc : 1;
        unsigned int st_clk_ao_camera : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_mad_32k : 1;
        unsigned int st_clk_fll_src_tp : 1;
        unsigned int st_pclk_timer4 : 1;
        unsigned int st_clk_sts_spi1 : 1;
        unsigned int st_pclk_timer5 : 1;
        unsigned int st_clk_sts_spi0 : 1;
        unsigned int st_pclk_timer6 : 1;
        unsigned int st_clk_sts_rffe_ssc : 1;
        unsigned int st_pclk_timer7 : 1;
        unsigned int st_clk_sts_i2s : 1;
        unsigned int st_pclk_timer8 : 1;
        unsigned int st_clk_sts : 1;
        unsigned int st_timerclk_refh : 1;
        unsigned int st_clk_em_sync_top : 1;
        unsigned int swdone_clk_iomcu_fll_src_div : 1;
        unsigned int swdone_clk_aobus_div : 1;
        unsigned int st_clk_noc_aobus2aspbus : 1;
        unsigned int st_clk_noc_aobus2iomcubus : 1;
        unsigned int st_clk_hsdt_subsys : 1;
        unsigned int swdone_clk_asp_subsys_div : 1;
        unsigned int swdone_clk_sci_div : 1;
        unsigned int sw_ack_clk_aobus_sw : 3;
    } reg;
} SOC_AO_CRG_SCPERSTAT1_UNION;
#endif
#define SOC_AO_CRG_SCPERSTAT1_st_clk_asp_dw_axi_START (0)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_asp_dw_axi_END (0)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_asp_cfg_START (3)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_asp_cfg_END (3)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_mad_axi_START (4)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_mad_axi_END (4)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_noc_aobus2sysbusddrc_START (5)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_noc_aobus2sysbusddrc_END (5)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_ao_camera_START (6)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_ao_camera_END (6)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_mad_32k_START (8)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_mad_32k_END (8)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_fll_src_tp_START (9)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_fll_src_tp_END (9)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer4_START (10)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer4_END (10)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_spi1_START (11)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_spi1_END (11)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer5_START (12)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer5_END (12)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_spi0_START (13)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_spi0_END (13)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer6_START (14)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer6_END (14)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_rffe_ssc_START (15)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_rffe_ssc_END (15)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer7_START (16)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer7_END (16)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_i2s_START (17)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_i2s_END (17)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer8_START (18)
#define SOC_AO_CRG_SCPERSTAT1_st_pclk_timer8_END (18)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_START (19)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_sts_END (19)
#define SOC_AO_CRG_SCPERSTAT1_st_timerclk_refh_START (20)
#define SOC_AO_CRG_SCPERSTAT1_st_timerclk_refh_END (20)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_em_sync_top_START (21)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_em_sync_top_END (21)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_iomcu_fll_src_div_START (22)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_iomcu_fll_src_div_END (22)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_aobus_div_START (23)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_aobus_div_END (23)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_noc_aobus2aspbus_START (24)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_noc_aobus2aspbus_END (24)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_noc_aobus2iomcubus_START (25)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_noc_aobus2iomcubus_END (25)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_hsdt_subsys_START (26)
#define SOC_AO_CRG_SCPERSTAT1_st_clk_hsdt_subsys_END (26)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_asp_subsys_div_START (27)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_asp_subsys_div_END (27)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_sci_div_START (28)
#define SOC_AO_CRG_SCPERSTAT1_swdone_clk_sci_div_END (28)
#define SOC_AO_CRG_SCPERSTAT1_sw_ack_clk_aobus_sw_START (29)
#define SOC_AO_CRG_SCPERSTAT1_sw_ack_clk_aobus_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int aupll_en_stat : 1;
        unsigned int aupll_bypass_stat : 1;
        unsigned int aupll_gt_stat : 1;
        unsigned int aupll_lock : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_AO_CRG_SC_AO_CRG_STA_SEP0_UNION;
#endif
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_en_stat_START (1)
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_en_stat_END (1)
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_bypass_stat_START (2)
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_bypass_stat_END (2)
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_gt_stat_START (3)
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_gt_stat_END (3)
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_lock_START (4)
#define SOC_AO_CRG_SC_AO_CRG_STA_SEP0_aupll_lock_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aoqic_sys_idle_flag : 1;
        unsigned int aoqic_cc_idle_flag : 1;
        unsigned int autodiv_pcie_stat : 1;
        unsigned int asp_flag_0 : 1;
        unsigned int asp_perf_idle : 1;
        unsigned int iomcu_flag_1 : 1;
        unsigned int ao_flag_0 : 1;
        unsigned int qspi_idle : 1;
        unsigned int tcp_busy : 1;
        unsigned int mspc_flag_0 : 1;
        unsigned int cc2ao_idle_flag : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 10;
    } reg;
} SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_UNION;
#endif
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_aoqic_sys_idle_flag_START (0)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_aoqic_sys_idle_flag_END (0)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_aoqic_cc_idle_flag_START (1)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_aoqic_cc_idle_flag_END (1)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_autodiv_pcie_stat_START (2)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_autodiv_pcie_stat_END (2)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_asp_flag_0_START (3)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_asp_flag_0_END (3)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_asp_perf_idle_START (4)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_asp_perf_idle_END (4)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_iomcu_flag_1_START (5)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_iomcu_flag_1_END (5)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_ao_flag_0_START (6)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_ao_flag_0_END (6)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_qspi_idle_START (7)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_qspi_idle_END (7)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_tcp_busy_START (8)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_tcp_busy_END (8)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_mspc_flag_0_START (9)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_mspc_flag_0_END (9)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_cc2ao_idle_flag_START (10)
#define SOC_AO_CRG_AO_AUTODIV_INUSE_STAT_cc2ao_idle_flag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_hsdt_subsys : 6;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_clk_ao_tof : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int gt_clk_mad_axi : 1;
    } reg;
} SOC_AO_CRG_SCPEREN2_UNION;
#endif
#define SOC_AO_CRG_SCPEREN2_gt_clk_hsdt_subsys_START (11)
#define SOC_AO_CRG_SCPEREN2_gt_clk_hsdt_subsys_END (16)
#define SOC_AO_CRG_SCPEREN2_gt_clk_ao_tof_START (26)
#define SOC_AO_CRG_SCPEREN2_gt_clk_ao_tof_END (26)
#define SOC_AO_CRG_SCPEREN2_gt_clk_mad_axi_START (31)
#define SOC_AO_CRG_SCPEREN2_gt_clk_mad_axi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_hsdt_subsys : 6;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_clk_ao_tof : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int gt_clk_mad_axi : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS2_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS2_gt_clk_hsdt_subsys_START (11)
#define SOC_AO_CRG_SCPERDIS2_gt_clk_hsdt_subsys_END (16)
#define SOC_AO_CRG_SCPERDIS2_gt_clk_ao_tof_START (26)
#define SOC_AO_CRG_SCPERDIS2_gt_clk_ao_tof_END (26)
#define SOC_AO_CRG_SCPERDIS2_gt_clk_mad_axi_START (31)
#define SOC_AO_CRG_SCPERDIS2_gt_clk_mad_axi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_hsdt_subsys : 6;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_clk_ao_tof : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int gt_clk_mad_axi : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN2_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN2_gt_clk_hsdt_subsys_START (11)
#define SOC_AO_CRG_SCPERCLKEN2_gt_clk_hsdt_subsys_END (16)
#define SOC_AO_CRG_SCPERCLKEN2_gt_clk_ao_tof_START (26)
#define SOC_AO_CRG_SCPERCLKEN2_gt_clk_ao_tof_END (26)
#define SOC_AO_CRG_SCPERCLKEN2_gt_clk_mad_axi_START (31)
#define SOC_AO_CRG_SCPERCLKEN2_gt_clk_mad_axi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int swdone_clk_iomcu_pll_div : 1;
        unsigned int reserved_2 : 4;
        unsigned int swdone_clk_spi3_ulppll : 1;
        unsigned int swdone_clk_spi3 : 1;
        unsigned int sw_ack_clk_asp_subsys_ini : 4;
        unsigned int reserved_3 : 1;
        unsigned int swdone_clk_spi5_ulppll : 1;
        unsigned int swdone_clk_spi5 : 1;
        unsigned int swdone_clk_pcie_aux_32kpll_div : 1;
        unsigned int st_clk_hsdt0_pcie_aux : 1;
        unsigned int swdone_clk_dp_audio_pll_ao_div : 1;
        unsigned int st_clk_iomcu_fll_src : 1;
        unsigned int st_pclk_ao_wd : 1;
        unsigned int st_clk_iomcu_pll_div : 1;
        unsigned int reserved_4 : 1;
        unsigned int swdone_clk_mad_fll_div : 1;
        unsigned int st_clk_fll_test_src : 1;
        unsigned int st_pclkdbg_to_iomcu : 1;
        unsigned int st_clk_asp_codec : 1;
        unsigned int swdone_clk_out0_div : 1;
        unsigned int swdone_clk_asp_subsys_fll_div : 1;
        unsigned int swdone_clk_aonoc_fll_div : 1;
        unsigned int swdone_clk_noc_timeout_extref_div : 1;
    } reg;
} SOC_AO_CRG_SCPERSTAT2_UNION;
#endif
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_iomcu_pll_div_START (3)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_iomcu_pll_div_END (3)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi3_ulppll_START (8)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi3_ulppll_END (8)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi3_START (9)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi3_END (9)
#define SOC_AO_CRG_SCPERSTAT2_sw_ack_clk_asp_subsys_ini_START (10)
#define SOC_AO_CRG_SCPERSTAT2_sw_ack_clk_asp_subsys_ini_END (13)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi5_ulppll_START (15)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi5_ulppll_END (15)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi5_START (16)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_spi5_END (16)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_pcie_aux_32kpll_div_START (17)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_pcie_aux_32kpll_div_END (17)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_hsdt0_pcie_aux_START (18)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_hsdt0_pcie_aux_END (18)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_dp_audio_pll_ao_div_START (19)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_dp_audio_pll_ao_div_END (19)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_iomcu_fll_src_START (20)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_iomcu_fll_src_END (20)
#define SOC_AO_CRG_SCPERSTAT2_st_pclk_ao_wd_START (21)
#define SOC_AO_CRG_SCPERSTAT2_st_pclk_ao_wd_END (21)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_iomcu_pll_div_START (22)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_iomcu_pll_div_END (22)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_mad_fll_div_START (24)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_mad_fll_div_END (24)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_fll_test_src_START (25)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_fll_test_src_END (25)
#define SOC_AO_CRG_SCPERSTAT2_st_pclkdbg_to_iomcu_START (26)
#define SOC_AO_CRG_SCPERSTAT2_st_pclkdbg_to_iomcu_END (26)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_asp_codec_START (27)
#define SOC_AO_CRG_SCPERSTAT2_st_clk_asp_codec_END (27)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_out0_div_START (28)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_out0_div_END (28)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_asp_subsys_fll_div_START (29)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_asp_subsys_fll_div_END (29)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_aonoc_fll_div_START (30)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_aonoc_fll_div_END (30)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_noc_timeout_extref_div_START (31)
#define SOC_AO_CRG_SCPERSTAT2_swdone_clk_noc_timeout_extref_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_AO_CRG_SCPEREN3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_AO_CRG_SCPERDIS3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int st_pclk_ao_gpio1_se : 1;
        unsigned int gt_aobus_noc_ini : 1;
        unsigned int autodiv_aonoc_pll_stat : 1;
        unsigned int autodiv_aonoc_fll_stat : 1;
        unsigned int st_pclk_timer17 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_pclk_timer16 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_pclk_timer15 : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_pclk_timer14 : 1;
        unsigned int st_clk_aupll_media2 : 1;
        unsigned int st_pclk_timer13 : 1;
        unsigned int swdone_clk_out2_div : 1;
        unsigned int st_pclk_ao_ipc : 1;
        unsigned int st_clk_dp_audio_pll_tp : 1;
        unsigned int sw_ack_clk_pcie_aux : 2;
        unsigned int sw_ack_clk_timer_sw : 2;
        unsigned int st_atclk_to_iomcu : 1;
        unsigned int st_clk_noc_timeout_extref_peri : 1;
        unsigned int st_timerclk_refh_peri : 1;
        unsigned int st_clkin_sys_peri : 1;
        unsigned int st_clkin_ref_peri : 1;
        unsigned int st_clk_sys_ini_peri : 1;
        unsigned int swdone_clk_em_sync_top_div : 1;
        unsigned int st_clk_ref_peri : 1;
        unsigned int st_clk_sys_peri : 1;
        unsigned int st_clk_aobus_peri : 1;
        unsigned int st_clk_fll_src_peri : 1;
    } reg;
} SOC_AO_CRG_SCPERSTAT3_UNION;
#endif
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_ao_gpio1_se_START (1)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_ao_gpio1_se_END (1)
#define SOC_AO_CRG_SCPERSTAT3_gt_aobus_noc_ini_START (2)
#define SOC_AO_CRG_SCPERSTAT3_gt_aobus_noc_ini_END (2)
#define SOC_AO_CRG_SCPERSTAT3_autodiv_aonoc_pll_stat_START (3)
#define SOC_AO_CRG_SCPERSTAT3_autodiv_aonoc_pll_stat_END (3)
#define SOC_AO_CRG_SCPERSTAT3_autodiv_aonoc_fll_stat_START (4)
#define SOC_AO_CRG_SCPERSTAT3_autodiv_aonoc_fll_stat_END (4)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer17_START (5)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer17_END (5)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer16_START (7)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer16_END (7)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer15_START (9)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer15_END (9)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer14_START (11)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer14_END (11)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_aupll_media2_START (12)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_aupll_media2_END (12)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer13_START (13)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_timer13_END (13)
#define SOC_AO_CRG_SCPERSTAT3_swdone_clk_out2_div_START (14)
#define SOC_AO_CRG_SCPERSTAT3_swdone_clk_out2_div_END (14)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_ao_ipc_START (15)
#define SOC_AO_CRG_SCPERSTAT3_st_pclk_ao_ipc_END (15)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_dp_audio_pll_tp_START (16)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_dp_audio_pll_tp_END (16)
#define SOC_AO_CRG_SCPERSTAT3_sw_ack_clk_pcie_aux_START (17)
#define SOC_AO_CRG_SCPERSTAT3_sw_ack_clk_pcie_aux_END (18)
#define SOC_AO_CRG_SCPERSTAT3_sw_ack_clk_timer_sw_START (19)
#define SOC_AO_CRG_SCPERSTAT3_sw_ack_clk_timer_sw_END (20)
#define SOC_AO_CRG_SCPERSTAT3_st_atclk_to_iomcu_START (21)
#define SOC_AO_CRG_SCPERSTAT3_st_atclk_to_iomcu_END (21)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_noc_timeout_extref_peri_START (22)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_noc_timeout_extref_peri_END (22)
#define SOC_AO_CRG_SCPERSTAT3_st_timerclk_refh_peri_START (23)
#define SOC_AO_CRG_SCPERSTAT3_st_timerclk_refh_peri_END (23)
#define SOC_AO_CRG_SCPERSTAT3_st_clkin_sys_peri_START (24)
#define SOC_AO_CRG_SCPERSTAT3_st_clkin_sys_peri_END (24)
#define SOC_AO_CRG_SCPERSTAT3_st_clkin_ref_peri_START (25)
#define SOC_AO_CRG_SCPERSTAT3_st_clkin_ref_peri_END (25)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_sys_ini_peri_START (26)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_sys_ini_peri_END (26)
#define SOC_AO_CRG_SCPERSTAT3_swdone_clk_em_sync_top_div_START (27)
#define SOC_AO_CRG_SCPERSTAT3_swdone_clk_em_sync_top_div_END (27)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_ref_peri_START (28)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_ref_peri_END (28)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_sys_peri_START (29)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_sys_peri_END (29)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_aobus_peri_START (30)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_aobus_peri_END (30)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_fll_src_peri_START (31)
#define SOC_AO_CRG_SCPERSTAT3_st_clk_fll_src_peri_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_memrepair_ao : 1;
        unsigned int gt_clk_memrepair_peri : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_ao_ipc_ns : 1;
        unsigned int gt_pclk_ao_loadmonitor : 1;
        unsigned int gt_clk_ao_loadmonitor : 1;
        unsigned int gt_clk_spi5 : 1;
        unsigned int gt_clk_dp_audio_pll : 1;
        unsigned int gt_clk_out2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_spi3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int gt_clk_ufs_ref_test : 1;
        unsigned int gt_pclk_ao_loadmonitor_m3 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
    } reg;
} SOC_AO_CRG_SCPEREN4_UNION;
#endif
#define SOC_AO_CRG_SCPEREN4_gt_clk_memrepair_ao_START (0)
#define SOC_AO_CRG_SCPEREN4_gt_clk_memrepair_ao_END (0)
#define SOC_AO_CRG_SCPEREN4_gt_clk_memrepair_peri_START (1)
#define SOC_AO_CRG_SCPEREN4_gt_clk_memrepair_peri_END (1)
#define SOC_AO_CRG_SCPEREN4_gt_pclk_ao_ipc_ns_START (3)
#define SOC_AO_CRG_SCPEREN4_gt_pclk_ao_ipc_ns_END (3)
#define SOC_AO_CRG_SCPEREN4_gt_pclk_ao_loadmonitor_START (4)
#define SOC_AO_CRG_SCPEREN4_gt_pclk_ao_loadmonitor_END (4)
#define SOC_AO_CRG_SCPEREN4_gt_clk_ao_loadmonitor_START (5)
#define SOC_AO_CRG_SCPEREN4_gt_clk_ao_loadmonitor_END (5)
#define SOC_AO_CRG_SCPEREN4_gt_clk_spi5_START (6)
#define SOC_AO_CRG_SCPEREN4_gt_clk_spi5_END (6)
#define SOC_AO_CRG_SCPEREN4_gt_clk_dp_audio_pll_START (7)
#define SOC_AO_CRG_SCPEREN4_gt_clk_dp_audio_pll_END (7)
#define SOC_AO_CRG_SCPEREN4_gt_clk_out2_START (8)
#define SOC_AO_CRG_SCPEREN4_gt_clk_out2_END (8)
#define SOC_AO_CRG_SCPEREN4_gt_clk_spi3_START (10)
#define SOC_AO_CRG_SCPEREN4_gt_clk_spi3_END (10)
#define SOC_AO_CRG_SCPEREN4_gt_clk_ufs_ref_test_START (25)
#define SOC_AO_CRG_SCPEREN4_gt_clk_ufs_ref_test_END (25)
#define SOC_AO_CRG_SCPEREN4_gt_pclk_ao_loadmonitor_m3_START (26)
#define SOC_AO_CRG_SCPEREN4_gt_pclk_ao_loadmonitor_m3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_memrepair_ao : 1;
        unsigned int gt_clk_memrepair_peri : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_ao_ipc_ns : 1;
        unsigned int gt_pclk_ao_loadmonitor : 1;
        unsigned int gt_clk_ao_loadmonitor : 1;
        unsigned int gt_clk_spi5 : 1;
        unsigned int gt_clk_dp_audio_pll : 1;
        unsigned int gt_clk_out2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_spi3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int gt_clk_ufs_ref_test : 1;
        unsigned int gt_pclk_ao_loadmonitor_m3 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS4_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS4_gt_clk_memrepair_ao_START (0)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_memrepair_ao_END (0)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_memrepair_peri_START (1)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_memrepair_peri_END (1)
#define SOC_AO_CRG_SCPERDIS4_gt_pclk_ao_ipc_ns_START (3)
#define SOC_AO_CRG_SCPERDIS4_gt_pclk_ao_ipc_ns_END (3)
#define SOC_AO_CRG_SCPERDIS4_gt_pclk_ao_loadmonitor_START (4)
#define SOC_AO_CRG_SCPERDIS4_gt_pclk_ao_loadmonitor_END (4)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_ao_loadmonitor_START (5)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_ao_loadmonitor_END (5)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_spi5_START (6)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_spi5_END (6)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_dp_audio_pll_START (7)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_dp_audio_pll_END (7)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_out2_START (8)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_out2_END (8)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_spi3_START (10)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_spi3_END (10)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_ufs_ref_test_START (25)
#define SOC_AO_CRG_SCPERDIS4_gt_clk_ufs_ref_test_END (25)
#define SOC_AO_CRG_SCPERDIS4_gt_pclk_ao_loadmonitor_m3_START (26)
#define SOC_AO_CRG_SCPERDIS4_gt_pclk_ao_loadmonitor_m3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_memrepair_ao : 1;
        unsigned int gt_clk_memrepair_peri : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_ao_ipc_ns : 1;
        unsigned int gt_pclk_ao_loadmonitor : 1;
        unsigned int gt_clk_ao_loadmonitor : 1;
        unsigned int gt_clk_spi5 : 1;
        unsigned int gt_clk_dp_audio_pll : 1;
        unsigned int gt_clk_out2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_spi3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int gt_clk_ufs_ref_test : 1;
        unsigned int gt_pclk_ao_loadmonitor_m3 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN4_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_memrepair_ao_START (0)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_memrepair_ao_END (0)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_memrepair_peri_START (1)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_memrepair_peri_END (1)
#define SOC_AO_CRG_SCPERCLKEN4_gt_pclk_ao_ipc_ns_START (3)
#define SOC_AO_CRG_SCPERCLKEN4_gt_pclk_ao_ipc_ns_END (3)
#define SOC_AO_CRG_SCPERCLKEN4_gt_pclk_ao_loadmonitor_START (4)
#define SOC_AO_CRG_SCPERCLKEN4_gt_pclk_ao_loadmonitor_END (4)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_ao_loadmonitor_START (5)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_ao_loadmonitor_END (5)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_spi5_START (6)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_spi5_END (6)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_dp_audio_pll_START (7)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_dp_audio_pll_END (7)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_out2_START (8)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_out2_END (8)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_spi3_START (10)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_spi3_END (10)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_ufs_ref_test_START (25)
#define SOC_AO_CRG_SCPERCLKEN4_gt_clk_ufs_ref_test_END (25)
#define SOC_AO_CRG_SCPERCLKEN4_gt_pclk_ao_loadmonitor_m3_START (26)
#define SOC_AO_CRG_SCPERCLKEN4_gt_pclk_ao_loadmonitor_m3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_memrepair_ao : 1;
        unsigned int st_clk_spmi_mst : 1;
        unsigned int st_pclk_ao_tzpc : 1;
        unsigned int st_pclk_ao_ipc_ns : 1;
        unsigned int st_pclk_ao_loadmonitor : 1;
        unsigned int st_clk_ao_loadmonitor : 1;
        unsigned int st_ulppll_1_out : 1;
        unsigned int st_clk_dp_audio_pll : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_qic_spidma : 1;
        unsigned int st_clk_spi3 : 1;
        unsigned int st_clk_spi5 : 1;
        unsigned int sw_ack_clk_sts_sw : 2;
        unsigned int reserved_1 : 1;
        unsigned int sw_ack_clk_mad_sw : 2;
        unsigned int sw_ack_clk_sts_spi_sw : 2;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_pll_fsm : 1;
        unsigned int st_clk_memrepair_peri : 1;
        unsigned int st_pclk_intr_hub : 1;
        unsigned int swdone_clk_sts_fll_div : 1;
        unsigned int st_clk_aupll_sscg : 1;
        unsigned int st_clk_ufs_ref_test : 1;
        unsigned int swdone_clk_sts_spi_fll_div : 1;
        unsigned int swdone_clk_timer_div : 1;
        unsigned int swdone_clk_sts_spll_div : 1;
        unsigned int swdone_clk_sts_spi_div : 1;
        unsigned int swdone_clk_sts_rffe_ssc : 1;
        unsigned int swdone_clk_ao_332m_div : 1;
    } reg;
} SOC_AO_CRG_SCPERSTAT4_UNION;
#endif
#define SOC_AO_CRG_SCPERSTAT4_st_clk_memrepair_ao_START (0)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_memrepair_ao_END (0)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_spmi_mst_START (1)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_spmi_mst_END (1)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_ao_tzpc_START (2)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_ao_tzpc_END (2)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_ao_ipc_ns_START (3)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_ao_ipc_ns_END (3)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_ao_loadmonitor_START (4)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_ao_loadmonitor_END (4)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_ao_loadmonitor_START (5)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_ao_loadmonitor_END (5)
#define SOC_AO_CRG_SCPERSTAT4_st_ulppll_1_out_START (6)
#define SOC_AO_CRG_SCPERSTAT4_st_ulppll_1_out_END (6)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_dp_audio_pll_START (7)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_dp_audio_pll_END (7)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_qic_spidma_START (9)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_qic_spidma_END (9)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_spi3_START (10)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_spi3_END (10)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_spi5_START (11)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_spi5_END (11)
#define SOC_AO_CRG_SCPERSTAT4_sw_ack_clk_sts_sw_START (12)
#define SOC_AO_CRG_SCPERSTAT4_sw_ack_clk_sts_sw_END (13)
#define SOC_AO_CRG_SCPERSTAT4_sw_ack_clk_mad_sw_START (15)
#define SOC_AO_CRG_SCPERSTAT4_sw_ack_clk_mad_sw_END (16)
#define SOC_AO_CRG_SCPERSTAT4_sw_ack_clk_sts_spi_sw_START (17)
#define SOC_AO_CRG_SCPERSTAT4_sw_ack_clk_sts_spi_sw_END (18)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_pll_fsm_START (20)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_pll_fsm_END (20)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_memrepair_peri_START (21)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_memrepair_peri_END (21)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_intr_hub_START (22)
#define SOC_AO_CRG_SCPERSTAT4_st_pclk_intr_hub_END (22)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_fll_div_START (23)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_fll_div_END (23)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_aupll_sscg_START (24)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_aupll_sscg_END (24)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_ufs_ref_test_START (25)
#define SOC_AO_CRG_SCPERSTAT4_st_clk_ufs_ref_test_END (25)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_spi_fll_div_START (26)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_spi_fll_div_END (26)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_timer_div_START (27)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_timer_div_END (27)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_spll_div_START (28)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_spll_div_END (28)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_spi_div_START (29)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_spi_div_END (29)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_rffe_ssc_START (30)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_sts_rffe_ssc_END (30)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_ao_332m_div_START (31)
#define SOC_AO_CRG_SCPERSTAT4_swdone_clk_ao_332m_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_timer17 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_timer16 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer15 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_pclk_timer14 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_timer13 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_pclk_intr_hub : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
    } reg;
} SOC_AO_CRG_SCPEREN5_UNION;
#endif
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer17_START (0)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer17_END (0)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer16_START (2)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer16_END (2)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer15_START (4)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer15_END (4)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer14_START (6)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer14_END (6)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer13_START (8)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_timer13_END (8)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_intr_hub_START (14)
#define SOC_AO_CRG_SCPEREN5_gt_pclk_intr_hub_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_timer17 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_timer16 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer15 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_pclk_timer14 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_timer13 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_pclk_intr_hub : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS5_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer17_START (0)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer17_END (0)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer16_START (2)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer16_END (2)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer15_START (4)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer15_END (4)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer14_START (6)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer14_END (6)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer13_START (8)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_timer13_END (8)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_intr_hub_START (14)
#define SOC_AO_CRG_SCPERDIS5_gt_pclk_intr_hub_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_timer17 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_timer16 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer15 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_pclk_timer14 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_timer13 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_pclk_intr_hub : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN5_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer17_START (0)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer17_END (0)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer16_START (2)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer16_END (2)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer15_START (4)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer15_END (4)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer14_START (6)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer14_END (6)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer13_START (8)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_timer13_END (8)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_intr_hub_START (14)
#define SOC_AO_CRG_SCPERCLKEN5_gt_pclk_intr_hub_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int ulppll_1_lock : 1;
        unsigned int ulppll_lock : 1;
        unsigned int swdone_clk_blpwm2_div : 1;
        unsigned int st_clk_ao_tcp_h2x : 1;
        unsigned int st_clk_ao_tcp : 1;
        unsigned int st_clk_ao_tcp_32k : 1;
        unsigned int reserved_1 : 1;
        unsigned int sw_ack_clk_spi3_sw : 2;
        unsigned int sw_ack_clk_spi5_sw : 2;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_spll_peri : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 2;
        unsigned int st_clk_sys_ini : 1;
        unsigned int st_clk_ao_tof : 1;
        unsigned int st_pclk_efusec2 : 1;
        unsigned int st_clkin_sys_logic_peri : 1;
        unsigned int st_pclk_ao_wd1 : 1;
        unsigned int st_pclk_hickm : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 4;
        unsigned int reserved_7 : 3;
    } reg;
} SOC_AO_CRG_SCPERSTAT5_UNION;
#endif
#define SOC_AO_CRG_SCPERSTAT5_ulppll_1_lock_START (2)
#define SOC_AO_CRG_SCPERSTAT5_ulppll_1_lock_END (2)
#define SOC_AO_CRG_SCPERSTAT5_ulppll_lock_START (3)
#define SOC_AO_CRG_SCPERSTAT5_ulppll_lock_END (3)
#define SOC_AO_CRG_SCPERSTAT5_swdone_clk_blpwm2_div_START (4)
#define SOC_AO_CRG_SCPERSTAT5_swdone_clk_blpwm2_div_END (4)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tcp_h2x_START (5)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tcp_h2x_END (5)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tcp_START (6)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tcp_END (6)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tcp_32k_START (7)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tcp_32k_END (7)
#define SOC_AO_CRG_SCPERSTAT5_sw_ack_clk_spi3_sw_START (9)
#define SOC_AO_CRG_SCPERSTAT5_sw_ack_clk_spi3_sw_END (10)
#define SOC_AO_CRG_SCPERSTAT5_sw_ack_clk_spi5_sw_START (11)
#define SOC_AO_CRG_SCPERSTAT5_sw_ack_clk_spi5_sw_END (12)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_spll_peri_START (14)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_spll_peri_END (14)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_sys_ini_START (18)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_sys_ini_END (18)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tof_START (19)
#define SOC_AO_CRG_SCPERSTAT5_st_clk_ao_tof_END (19)
#define SOC_AO_CRG_SCPERSTAT5_st_pclk_efusec2_START (20)
#define SOC_AO_CRG_SCPERSTAT5_st_pclk_efusec2_END (20)
#define SOC_AO_CRG_SCPERSTAT5_st_clkin_sys_logic_peri_START (21)
#define SOC_AO_CRG_SCPERSTAT5_st_clkin_sys_logic_peri_END (21)
#define SOC_AO_CRG_SCPERSTAT5_st_pclk_ao_wd1_START (22)
#define SOC_AO_CRG_SCPERSTAT5_st_pclk_ao_wd1_END (22)
#define SOC_AO_CRG_SCPERSTAT5_st_pclk_hickm_START (23)
#define SOC_AO_CRG_SCPERSTAT5_st_pclk_hickm_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_ufs_mphy_sys : 1;
        unsigned int gt_clk_ao_camera1 : 1;
        unsigned int gt_clk_qspi_sfc_x2 : 1;
        unsigned int gt_hclk_qspi : 1;
        unsigned int gt_pclk_autodiv_pcie : 1;
        unsigned int gt_clk_mudp_sys : 1;
        unsigned int gt_clk_out_ufs : 1;
        unsigned int gt_clk_out_io_die : 1;
        unsigned int gt_clk_swd2jtag_dap : 1;
        unsigned int gt_pclk_autodiv_aonoc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
    } reg;
} SOC_AO_CRG_SCPEREN6_UNION;
#endif
#define SOC_AO_CRG_SCPEREN6_gt_clk_ufs_mphy_sys_START (0)
#define SOC_AO_CRG_SCPEREN6_gt_clk_ufs_mphy_sys_END (0)
#define SOC_AO_CRG_SCPEREN6_gt_clk_ao_camera1_START (1)
#define SOC_AO_CRG_SCPEREN6_gt_clk_ao_camera1_END (1)
#define SOC_AO_CRG_SCPEREN6_gt_clk_qspi_sfc_x2_START (2)
#define SOC_AO_CRG_SCPEREN6_gt_clk_qspi_sfc_x2_END (2)
#define SOC_AO_CRG_SCPEREN6_gt_hclk_qspi_START (3)
#define SOC_AO_CRG_SCPEREN6_gt_hclk_qspi_END (3)
#define SOC_AO_CRG_SCPEREN6_gt_pclk_autodiv_pcie_START (4)
#define SOC_AO_CRG_SCPEREN6_gt_pclk_autodiv_pcie_END (4)
#define SOC_AO_CRG_SCPEREN6_gt_clk_mudp_sys_START (5)
#define SOC_AO_CRG_SCPEREN6_gt_clk_mudp_sys_END (5)
#define SOC_AO_CRG_SCPEREN6_gt_clk_out_ufs_START (6)
#define SOC_AO_CRG_SCPEREN6_gt_clk_out_ufs_END (6)
#define SOC_AO_CRG_SCPEREN6_gt_clk_out_io_die_START (7)
#define SOC_AO_CRG_SCPEREN6_gt_clk_out_io_die_END (7)
#define SOC_AO_CRG_SCPEREN6_gt_clk_swd2jtag_dap_START (8)
#define SOC_AO_CRG_SCPEREN6_gt_clk_swd2jtag_dap_END (8)
#define SOC_AO_CRG_SCPEREN6_gt_pclk_autodiv_aonoc_START (9)
#define SOC_AO_CRG_SCPEREN6_gt_pclk_autodiv_aonoc_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_ufs_mphy_sys : 1;
        unsigned int gt_clk_ao_camera1 : 1;
        unsigned int gt_clk_qspi_sfc_x2 : 1;
        unsigned int gt_hclk_qspi : 1;
        unsigned int gt_pclk_autodiv_pcie : 1;
        unsigned int gt_clk_mudp_sys : 1;
        unsigned int gt_clk_out_ufs : 1;
        unsigned int gt_clk_out_io_die : 1;
        unsigned int gt_clk_swd2jtag_dap : 1;
        unsigned int gt_pclk_autodiv_aonoc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS6_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS6_gt_clk_ufs_mphy_sys_START (0)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_ufs_mphy_sys_END (0)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_ao_camera1_START (1)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_ao_camera1_END (1)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_qspi_sfc_x2_START (2)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_qspi_sfc_x2_END (2)
#define SOC_AO_CRG_SCPERDIS6_gt_hclk_qspi_START (3)
#define SOC_AO_CRG_SCPERDIS6_gt_hclk_qspi_END (3)
#define SOC_AO_CRG_SCPERDIS6_gt_pclk_autodiv_pcie_START (4)
#define SOC_AO_CRG_SCPERDIS6_gt_pclk_autodiv_pcie_END (4)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_mudp_sys_START (5)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_mudp_sys_END (5)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_out_ufs_START (6)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_out_ufs_END (6)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_out_io_die_START (7)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_out_io_die_END (7)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_swd2jtag_dap_START (8)
#define SOC_AO_CRG_SCPERDIS6_gt_clk_swd2jtag_dap_END (8)
#define SOC_AO_CRG_SCPERDIS6_gt_pclk_autodiv_aonoc_START (9)
#define SOC_AO_CRG_SCPERDIS6_gt_pclk_autodiv_aonoc_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_ufs_mphy_sys : 1;
        unsigned int gt_clk_ao_camera1 : 1;
        unsigned int gt_clk_qspi_sfc_x2 : 1;
        unsigned int gt_hclk_qspi : 1;
        unsigned int gt_pclk_autodiv_pcie : 1;
        unsigned int gt_clk_mudp_sys : 1;
        unsigned int gt_clk_out_ufs : 1;
        unsigned int gt_clk_out_io_die : 1;
        unsigned int gt_clk_swd2jtag_dap : 1;
        unsigned int gt_pclk_autodiv_aonoc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN6_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_ufs_mphy_sys_START (0)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_ufs_mphy_sys_END (0)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_ao_camera1_START (1)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_ao_camera1_END (1)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_qspi_sfc_x2_START (2)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_qspi_sfc_x2_END (2)
#define SOC_AO_CRG_SCPERCLKEN6_gt_hclk_qspi_START (3)
#define SOC_AO_CRG_SCPERCLKEN6_gt_hclk_qspi_END (3)
#define SOC_AO_CRG_SCPERCLKEN6_gt_pclk_autodiv_pcie_START (4)
#define SOC_AO_CRG_SCPERCLKEN6_gt_pclk_autodiv_pcie_END (4)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_mudp_sys_START (5)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_mudp_sys_END (5)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_out_ufs_START (6)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_out_ufs_END (6)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_out_io_die_START (7)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_out_io_die_END (7)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_swd2jtag_dap_START (8)
#define SOC_AO_CRG_SCPERCLKEN6_gt_clk_swd2jtag_dap_END (8)
#define SOC_AO_CRG_SCPERCLKEN6_gt_pclk_autodiv_aonoc_START (9)
#define SOC_AO_CRG_SCPERCLKEN6_gt_pclk_autodiv_aonoc_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_ufs_mphy_sys : 1;
        unsigned int st_clk_ao_camera1 : 1;
        unsigned int st_clk_qspi_sfc_x2 : 1;
        unsigned int st_hclk_qspi : 1;
        unsigned int st_pclk_autodiv_pcie : 1;
        unsigned int st_clk_mudp_sys : 1;
        unsigned int st_clk_out_ufs : 1;
        unsigned int st_clk_out_io_die : 1;
        unsigned int st_clk_swd2jtag_dap : 1;
        unsigned int reset_ao_ctrl_n : 4;
        unsigned int st_pclk_autodiv_aonoc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 4;
        unsigned int reserved_11 : 3;
    } reg;
} SOC_AO_CRG_SCPERSTAT6_UNION;
#endif
#define SOC_AO_CRG_SCPERSTAT6_st_clk_ufs_mphy_sys_START (0)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_ufs_mphy_sys_END (0)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_ao_camera1_START (1)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_ao_camera1_END (1)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_qspi_sfc_x2_START (2)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_qspi_sfc_x2_END (2)
#define SOC_AO_CRG_SCPERSTAT6_st_hclk_qspi_START (3)
#define SOC_AO_CRG_SCPERSTAT6_st_hclk_qspi_END (3)
#define SOC_AO_CRG_SCPERSTAT6_st_pclk_autodiv_pcie_START (4)
#define SOC_AO_CRG_SCPERSTAT6_st_pclk_autodiv_pcie_END (4)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_mudp_sys_START (5)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_mudp_sys_END (5)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_out_ufs_START (6)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_out_ufs_END (6)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_out_io_die_START (7)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_out_io_die_END (7)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_swd2jtag_dap_START (8)
#define SOC_AO_CRG_SCPERSTAT6_st_clk_swd2jtag_dap_END (8)
#define SOC_AO_CRG_SCPERSTAT6_reset_ao_ctrl_n_START (9)
#define SOC_AO_CRG_SCPERSTAT6_reset_ao_ctrl_n_END (12)
#define SOC_AO_CRG_SCPERSTAT6_st_pclk_autodiv_aonoc_START (13)
#define SOC_AO_CRG_SCPERSTAT6_st_pclk_autodiv_aonoc_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_AO_CRG_FNPLL_STATE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_rtc : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_timer0 : 1;
        unsigned int ip_prst_blpwm2 : 1;
        unsigned int ip_prst_blpwm0 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_i2s_asp2dp_rs : 1;
        unsigned int ip_rst_asp_dw_axi : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_em_sync_top : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ip_prst_ao_ioc : 1;
        unsigned int ip_prst_syscnt : 1;
        unsigned int ip_rst_syscnt : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_noc_aobus2aspbus : 1;
        unsigned int ip_prst_bbpdrx : 1;
        unsigned int ip_prst_ao_ipc_ns : 1;
        unsigned int reserved_16 : 1;
        unsigned int sc_rst_src_clr : 1;
        unsigned int sc_pmurst_ctrl : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTEN0_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_rtc_START (1)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_rtc_END (1)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_timer0_START (3)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_timer0_END (3)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_blpwm2_START (4)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_blpwm2_END (4)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_blpwm0_START (5)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_blpwm0_END (5)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_i2s_asp2dp_rs_START (7)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_i2s_asp2dp_rs_END (7)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_asp_dw_axi_START (8)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_asp_dw_axi_END (8)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_em_sync_top_START (11)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_em_sync_top_END (11)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_ao_ioc_START (18)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_ao_ioc_END (18)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_syscnt_START (19)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_syscnt_END (19)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_syscnt_START (20)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_syscnt_END (20)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_noc_aobus2aspbus_START (26)
#define SOC_AO_CRG_SCPERRSTEN0_ip_rst_noc_aobus2aspbus_END (26)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_bbpdrx_START (27)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_bbpdrx_END (27)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_ao_ipc_ns_START (28)
#define SOC_AO_CRG_SCPERRSTEN0_ip_prst_ao_ipc_ns_END (28)
#define SOC_AO_CRG_SCPERRSTEN0_sc_rst_src_clr_START (30)
#define SOC_AO_CRG_SCPERRSTEN0_sc_rst_src_clr_END (30)
#define SOC_AO_CRG_SCPERRSTEN0_sc_pmurst_ctrl_START (31)
#define SOC_AO_CRG_SCPERRSTEN0_sc_pmurst_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_rtc : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_timer0 : 1;
        unsigned int ip_prst_blpwm2 : 1;
        unsigned int ip_prst_blpwm0 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_i2s_asp2dp_rs : 1;
        unsigned int ip_rst_asp_dw_axi : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_em_sync_top : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ip_prst_ao_ioc : 1;
        unsigned int ip_prst_syscnt : 1;
        unsigned int ip_rst_syscnt : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_noc_aobus2aspbus : 1;
        unsigned int ip_prst_bbpdrx : 1;
        unsigned int ip_prst_ao_ipc_ns : 1;
        unsigned int reserved_16 : 1;
        unsigned int sc_rst_src_clr : 1;
        unsigned int sc_pmurst_ctrl : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTDIS0_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_rtc_START (1)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_rtc_END (1)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_timer0_START (3)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_timer0_END (3)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_blpwm2_START (4)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_blpwm2_END (4)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_blpwm0_START (5)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_blpwm0_END (5)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_i2s_asp2dp_rs_START (7)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_i2s_asp2dp_rs_END (7)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_asp_dw_axi_START (8)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_asp_dw_axi_END (8)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_em_sync_top_START (11)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_em_sync_top_END (11)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_ao_ioc_START (18)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_ao_ioc_END (18)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_syscnt_START (19)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_syscnt_END (19)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_syscnt_START (20)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_syscnt_END (20)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_noc_aobus2aspbus_START (26)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_rst_noc_aobus2aspbus_END (26)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_bbpdrx_START (27)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_bbpdrx_END (27)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_ao_ipc_ns_START (28)
#define SOC_AO_CRG_SCPERRSTDIS0_ip_prst_ao_ipc_ns_END (28)
#define SOC_AO_CRG_SCPERRSTDIS0_sc_rst_src_clr_START (30)
#define SOC_AO_CRG_SCPERRSTDIS0_sc_rst_src_clr_END (30)
#define SOC_AO_CRG_SCPERRSTDIS0_sc_pmurst_ctrl_START (31)
#define SOC_AO_CRG_SCPERRSTDIS0_sc_pmurst_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_rtc : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_timer0 : 1;
        unsigned int ip_prst_blpwm2 : 1;
        unsigned int ip_prst_blpwm0 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_i2s_asp2dp_rs : 1;
        unsigned int ip_rst_asp_dw_axi : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_em_sync_top : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ip_prst_ao_ioc : 1;
        unsigned int ip_prst_syscnt : 1;
        unsigned int ip_rst_syscnt : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_noc_aobus2aspbus : 1;
        unsigned int ip_prst_bbpdrx : 1;
        unsigned int ip_prst_ao_ipc_ns : 1;
        unsigned int reserved_16 : 1;
        unsigned int sc_rst_src_clr : 1;
        unsigned int sc_pmurst_ctrl : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTSTAT0_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_rtc_START (1)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_rtc_END (1)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_timer0_START (3)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_timer0_END (3)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_blpwm2_START (4)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_blpwm2_END (4)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_blpwm0_START (5)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_blpwm0_END (5)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_i2s_asp2dp_rs_START (7)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_i2s_asp2dp_rs_END (7)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_asp_dw_axi_START (8)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_asp_dw_axi_END (8)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_em_sync_top_START (11)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_em_sync_top_END (11)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_ao_ioc_START (18)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_ao_ioc_END (18)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_syscnt_START (19)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_syscnt_END (19)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_syscnt_START (20)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_syscnt_END (20)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_noc_aobus2aspbus_START (26)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_rst_noc_aobus2aspbus_END (26)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_bbpdrx_START (27)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_bbpdrx_END (27)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_ao_ipc_ns_START (28)
#define SOC_AO_CRG_SCPERRSTSTAT0_ip_prst_ao_ipc_ns_END (28)
#define SOC_AO_CRG_SCPERRSTSTAT0_sc_rst_src_clr_START (30)
#define SOC_AO_CRG_SCPERRSTSTAT0_sc_rst_src_clr_END (30)
#define SOC_AO_CRG_SCPERRSTSTAT0_sc_pmurst_ctrl_START (31)
#define SOC_AO_CRG_SCPERRSTSTAT0_sc_pmurst_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_spmi : 1;
        unsigned int ip_rst_spmi1 : 1;
        unsigned int ip_prst_dbg_to_ao : 1;
        unsigned int ip_prst_timer4 : 1;
        unsigned int ip_prst_timer5 : 1;
        unsigned int ip_prst_timer6 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_timer8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ip_prst_ao_loadmonitor : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_dram_tmp_0 : 2;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_ufs_crg : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int ip_rst_mudp_sys : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTEN1_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_spmi_START (0)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_spmi_END (0)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_spmi1_START (1)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_spmi1_END (1)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_dbg_to_ao_START (2)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_dbg_to_ao_END (2)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer4_START (3)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer4_END (3)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer5_START (4)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer5_END (4)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer6_START (5)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer6_END (5)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer8_START (7)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_timer8_END (7)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_ao_loadmonitor_START (13)
#define SOC_AO_CRG_SCPERRSTEN1_ip_prst_ao_loadmonitor_END (13)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_dram_tmp_0_START (16)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_dram_tmp_0_END (17)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_ufs_crg_START (19)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_ufs_crg_END (19)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_mudp_sys_START (30)
#define SOC_AO_CRG_SCPERRSTEN1_ip_rst_mudp_sys_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_spmi : 1;
        unsigned int ip_rst_spmi1 : 1;
        unsigned int ip_prst_dbg_to_ao : 1;
        unsigned int ip_prst_timer4 : 1;
        unsigned int ip_prst_timer5 : 1;
        unsigned int ip_prst_timer6 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_timer8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ip_prst_ao_loadmonitor : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_dram_tmp_0 : 2;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_ufs_crg : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int ip_rst_mudp_sys : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTDIS1_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_spmi_START (0)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_spmi_END (0)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_spmi1_START (1)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_spmi1_END (1)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_dbg_to_ao_START (2)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_dbg_to_ao_END (2)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer4_START (3)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer4_END (3)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer5_START (4)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer5_END (4)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer6_START (5)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer6_END (5)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer8_START (7)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_timer8_END (7)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_ao_loadmonitor_START (13)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_prst_ao_loadmonitor_END (13)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_dram_tmp_0_START (16)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_dram_tmp_0_END (17)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_ufs_crg_START (19)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_ufs_crg_END (19)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_mudp_sys_START (30)
#define SOC_AO_CRG_SCPERRSTDIS1_ip_rst_mudp_sys_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_spmi : 1;
        unsigned int ip_rst_spmi1 : 1;
        unsigned int ip_prst_dbg_to_ao : 1;
        unsigned int ip_prst_timer4 : 1;
        unsigned int ip_prst_timer5 : 1;
        unsigned int ip_prst_timer6 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_timer8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ip_prst_ao_loadmonitor : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_dram_tmp_0 : 2;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_ufs_crg : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int ip_rst_mudp_sys : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTSTAT1_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_spmi_START (0)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_spmi_END (0)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_spmi1_START (1)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_spmi1_END (1)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_dbg_to_ao_START (2)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_dbg_to_ao_END (2)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer4_START (3)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer4_END (3)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer5_START (4)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer5_END (4)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer6_START (5)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer6_END (5)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer8_START (7)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_timer8_END (7)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_ao_loadmonitor_START (13)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_prst_ao_loadmonitor_END (13)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_dram_tmp_0_START (16)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_dram_tmp_0_END (17)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_ufs_crg_START (19)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_ufs_crg_END (19)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_mudp_sys_START (30)
#define SOC_AO_CRG_SCPERRSTSTAT1_ip_rst_mudp_sys_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_spi5 : 1;
        unsigned int soft_rst_dram_dis : 1;
        unsigned int ip_rst_dram_tmp_1 : 2;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_spi3 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ip_rst_spi11dma : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_qspi_sfc_x2 : 1;
        unsigned int ip_prst_timer17 : 1;
        unsigned int ip_prst_timer16 : 1;
        unsigned int ip_prst_timer15 : 1;
        unsigned int ip_prst_timer14 : 1;
        unsigned int ip_prst_timer13 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTEN2_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_spi5_START (3)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_spi5_END (3)
#define SOC_AO_CRG_SCPERRSTEN2_soft_rst_dram_dis_START (4)
#define SOC_AO_CRG_SCPERRSTEN2_soft_rst_dram_dis_END (4)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_dram_tmp_1_START (5)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_dram_tmp_1_END (6)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_spi3_START (9)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_spi3_END (9)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_spi11dma_START (11)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_spi11dma_END (11)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_qspi_sfc_x2_START (15)
#define SOC_AO_CRG_SCPERRSTEN2_ip_rst_qspi_sfc_x2_END (15)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer17_START (16)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer17_END (16)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer16_START (17)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer16_END (17)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer15_START (18)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer15_END (18)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer14_START (19)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer14_END (19)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer13_START (20)
#define SOC_AO_CRG_SCPERRSTEN2_ip_prst_timer13_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_spi5 : 1;
        unsigned int soft_rst_dram_dis : 1;
        unsigned int ip_rst_dram_tmp_1 : 2;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_spi3 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ip_rst_spi11dma : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_qspi_sfc_x2 : 1;
        unsigned int ip_prst_timer17 : 1;
        unsigned int ip_prst_timer16 : 1;
        unsigned int ip_prst_timer15 : 1;
        unsigned int ip_prst_timer14 : 1;
        unsigned int ip_prst_timer13 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTDIS2_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_spi5_START (3)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_spi5_END (3)
#define SOC_AO_CRG_SCPERRSTDIS2_soft_rst_dram_dis_START (4)
#define SOC_AO_CRG_SCPERRSTDIS2_soft_rst_dram_dis_END (4)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_dram_tmp_1_START (5)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_dram_tmp_1_END (6)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_spi3_START (9)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_spi3_END (9)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_spi11dma_START (11)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_spi11dma_END (11)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_qspi_sfc_x2_START (15)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_rst_qspi_sfc_x2_END (15)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer17_START (16)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer17_END (16)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer16_START (17)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer16_END (17)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer15_START (18)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer15_END (18)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer14_START (19)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer14_END (19)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer13_START (20)
#define SOC_AO_CRG_SCPERRSTDIS2_ip_prst_timer13_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_spi5 : 1;
        unsigned int soft_rst_dram_dis : 1;
        unsigned int ip_rst_dram_tmp_1 : 2;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_spi3 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ip_rst_spi11dma : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_qspi_sfc_x2 : 1;
        unsigned int ip_prst_timer17 : 1;
        unsigned int ip_prst_timer16 : 1;
        unsigned int ip_prst_timer15 : 1;
        unsigned int ip_prst_timer14 : 1;
        unsigned int ip_prst_timer13 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTSTAT2_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_spi5_START (3)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_spi5_END (3)
#define SOC_AO_CRG_SCPERRSTSTAT2_soft_rst_dram_dis_START (4)
#define SOC_AO_CRG_SCPERRSTSTAT2_soft_rst_dram_dis_END (4)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_dram_tmp_1_START (5)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_dram_tmp_1_END (6)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_spi3_START (9)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_spi3_END (9)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_spi11dma_START (11)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_spi11dma_END (11)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_qspi_sfc_x2_START (15)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_rst_qspi_sfc_x2_END (15)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer17_START (16)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer17_END (16)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer16_START (17)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer16_END (17)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer15_START (18)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer15_END (18)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer14_START (19)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer14_END (19)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer13_START (20)
#define SOC_AO_CRG_SCPERRSTSTAT2_ip_prst_timer13_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_asp_subsys : 3;
        unsigned int sc_div_hifidsp : 6;
        unsigned int div_clk_out2 : 4;
        unsigned int sel_ao_asp_32kpll : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV0_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV0_div_asp_subsys_START (0)
#define SOC_AO_CRG_SCCLKDIV0_div_asp_subsys_END (2)
#define SOC_AO_CRG_SCCLKDIV0_sc_div_hifidsp_START (3)
#define SOC_AO_CRG_SCCLKDIV0_sc_div_hifidsp_END (8)
#define SOC_AO_CRG_SCCLKDIV0_div_clk_out2_START (9)
#define SOC_AO_CRG_SCCLKDIV0_div_clk_out2_END (12)
#define SOC_AO_CRG_SCCLKDIV0_sel_ao_asp_32kpll_START (13)
#define SOC_AO_CRG_SCCLKDIV0_sel_ao_asp_32kpll_END (13)
#define SOC_AO_CRG_SCCLKDIV0_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_mudp_sys : 6;
        unsigned int sc_gt_clk_mad_spll : 1;
        unsigned int reserved : 5;
        unsigned int sel_clk_fll_test_src : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV1_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV1_div_mudp_sys_START (0)
#define SOC_AO_CRG_SCCLKDIV1_div_mudp_sys_END (5)
#define SOC_AO_CRG_SCCLKDIV1_sc_gt_clk_mad_spll_START (6)
#define SOC_AO_CRG_SCCLKDIV1_sc_gt_clk_mad_spll_END (6)
#define SOC_AO_CRG_SCCLKDIV1_sel_clk_fll_test_src_START (12)
#define SOC_AO_CRG_SCCLKDIV1_sel_clk_fll_test_src_END (15)
#define SOC_AO_CRG_SCCLKDIV1_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_asp_subsys : 1;
        unsigned int gt_hifidsp_clk_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_asp_hclk_div : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_spmi_mst_vote : 10;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV2_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV2_sc_gt_clk_asp_subsys_START (0)
#define SOC_AO_CRG_SCCLKDIV2_sc_gt_clk_asp_subsys_END (0)
#define SOC_AO_CRG_SCCLKDIV2_gt_hifidsp_clk_div_START (1)
#define SOC_AO_CRG_SCCLKDIV2_gt_hifidsp_clk_div_END (1)
#define SOC_AO_CRG_SCCLKDIV2_gt_asp_hclk_div_START (4)
#define SOC_AO_CRG_SCCLKDIV2_gt_asp_hclk_div_END (4)
#define SOC_AO_CRG_SCCLKDIV2_gt_clk_spmi_mst_vote_START (6)
#define SOC_AO_CRG_SCCLKDIV2_gt_clk_spmi_mst_vote_END (15)
#define SOC_AO_CRG_SCCLKDIV2_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hsdt_subsys : 6;
        unsigned int hsdt_subsys_clk_sw_req_cfg : 2;
        unsigned int sel_clk_ao_tof : 2;
        unsigned int div_ao_tof : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV3_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV3_div_hsdt_subsys_START (0)
#define SOC_AO_CRG_SCCLKDIV3_div_hsdt_subsys_END (5)
#define SOC_AO_CRG_SCCLKDIV3_hsdt_subsys_clk_sw_req_cfg_START (6)
#define SOC_AO_CRG_SCCLKDIV3_hsdt_subsys_clk_sw_req_cfg_END (7)
#define SOC_AO_CRG_SCCLKDIV3_sel_clk_ao_tof_START (8)
#define SOC_AO_CRG_SCCLKDIV3_sel_clk_ao_tof_END (9)
#define SOC_AO_CRG_SCCLKDIV3_div_ao_tof_START (10)
#define SOC_AO_CRG_SCCLKDIV3_div_ao_tof_END (15)
#define SOC_AO_CRG_SCCLKDIV3_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_ao_camera : 6;
        unsigned int sel_clk_ao_camera1 : 2;
        unsigned int sc_div_asp_hclk : 2;
        unsigned int div_ao_camera1 : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV4_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV4_div_ao_camera_START (0)
#define SOC_AO_CRG_SCCLKDIV4_div_ao_camera_END (5)
#define SOC_AO_CRG_SCCLKDIV4_sel_clk_ao_camera1_START (6)
#define SOC_AO_CRG_SCCLKDIV4_sel_clk_ao_camera1_END (7)
#define SOC_AO_CRG_SCCLKDIV4_sc_div_asp_hclk_START (8)
#define SOC_AO_CRG_SCCLKDIV4_sc_div_asp_hclk_END (9)
#define SOC_AO_CRG_SCCLKDIV4_div_ao_camera1_START (10)
#define SOC_AO_CRG_SCCLKDIV4_div_ao_camera1_END (15)
#define SOC_AO_CRG_SCCLKDIV4_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV4_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_ufs_mphy_sys : 1;
        unsigned int div_ufs_mphy_sys : 4;
        unsigned int div_hsdt_subsys_fll : 6;
        unsigned int reserved : 1;
        unsigned int sc_gt_clk_blpwm0 : 1;
        unsigned int sel_syscnt : 1;
        unsigned int sc_gt_clk_blpwm2 : 1;
        unsigned int sc_gt_clk_mad_fll : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV5_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_ufs_mphy_sys_START (0)
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_ufs_mphy_sys_END (0)
#define SOC_AO_CRG_SCCLKDIV5_div_ufs_mphy_sys_START (1)
#define SOC_AO_CRG_SCCLKDIV5_div_ufs_mphy_sys_END (4)
#define SOC_AO_CRG_SCCLKDIV5_div_hsdt_subsys_fll_START (5)
#define SOC_AO_CRG_SCCLKDIV5_div_hsdt_subsys_fll_END (10)
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_blpwm0_START (12)
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_blpwm0_END (12)
#define SOC_AO_CRG_SCCLKDIV5_sel_syscnt_START (13)
#define SOC_AO_CRG_SCCLKDIV5_sel_syscnt_END (13)
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_blpwm2_START (14)
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_blpwm2_END (14)
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_mad_fll_START (15)
#define SOC_AO_CRG_SCCLKDIV5_sc_gt_clk_mad_fll_END (15)
#define SOC_AO_CRG_SCCLKDIV5_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV5_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_mad_spll : 4;
        unsigned int div_syscnt : 4;
        unsigned int reserved_0 : 1;
        unsigned int sel_clk_out2 : 2;
        unsigned int reserved_1 : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV6_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV6_div_mad_spll_START (0)
#define SOC_AO_CRG_SCCLKDIV6_div_mad_spll_END (3)
#define SOC_AO_CRG_SCCLKDIV6_div_syscnt_START (4)
#define SOC_AO_CRG_SCCLKDIV6_div_syscnt_END (7)
#define SOC_AO_CRG_SCCLKDIV6_sel_clk_out2_START (9)
#define SOC_AO_CRG_SCCLKDIV6_sel_clk_out2_END (10)
#define SOC_AO_CRG_SCCLKDIV6_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV6_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_memrepair : 1;
        unsigned int reserved_0 : 1;
        unsigned int div_memrepair : 6;
        unsigned int sel_clk_out_ufs : 1;
        unsigned int sc_gt_clk_ao_loadmonitor : 1;
        unsigned int div_ao_loadmonitor : 4;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV7_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV7_sc_gt_clk_memrepair_START (0)
#define SOC_AO_CRG_SCCLKDIV7_sc_gt_clk_memrepair_END (0)
#define SOC_AO_CRG_SCCLKDIV7_div_memrepair_START (2)
#define SOC_AO_CRG_SCCLKDIV7_div_memrepair_END (7)
#define SOC_AO_CRG_SCCLKDIV7_sel_clk_out_ufs_START (8)
#define SOC_AO_CRG_SCCLKDIV7_sel_clk_out_ufs_END (8)
#define SOC_AO_CRG_SCCLKDIV7_sc_gt_clk_ao_loadmonitor_START (9)
#define SOC_AO_CRG_SCCLKDIV7_sc_gt_clk_ao_loadmonitor_END (9)
#define SOC_AO_CRG_SCCLKDIV7_div_ao_loadmonitor_START (10)
#define SOC_AO_CRG_SCCLKDIV7_div_ao_loadmonitor_END (13)
#define SOC_AO_CRG_SCCLKDIV7_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV7_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_em_sync_top : 6;
        unsigned int sc_gt_clk_em_sync_top : 1;
        unsigned int sel_mad_mux : 1;
        unsigned int sc_gt_clk_spmi_mst : 1;
        unsigned int div_spmi_mst : 6;
        unsigned int sel_spmi_mst : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV8_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV8_div_em_sync_top_START (0)
#define SOC_AO_CRG_SCCLKDIV8_div_em_sync_top_END (5)
#define SOC_AO_CRG_SCCLKDIV8_sc_gt_clk_em_sync_top_START (6)
#define SOC_AO_CRG_SCCLKDIV8_sc_gt_clk_em_sync_top_END (6)
#define SOC_AO_CRG_SCCLKDIV8_sel_mad_mux_START (7)
#define SOC_AO_CRG_SCCLKDIV8_sel_mad_mux_END (7)
#define SOC_AO_CRG_SCCLKDIV8_sc_gt_clk_spmi_mst_START (8)
#define SOC_AO_CRG_SCCLKDIV8_sc_gt_clk_spmi_mst_END (8)
#define SOC_AO_CRG_SCCLKDIV8_div_spmi_mst_START (9)
#define SOC_AO_CRG_SCCLKDIV8_div_spmi_mst_END (14)
#define SOC_AO_CRG_SCCLKDIV8_sel_spmi_mst_START (15)
#define SOC_AO_CRG_SCCLKDIV8_sel_spmi_mst_END (15)
#define SOC_AO_CRG_SCCLKDIV8_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV8_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int sc_gt_clk_hsdt_subsys_fll : 1;
        unsigned int sc_gt_clk_hsdt_subsys : 1;
        unsigned int sc_gt_clk_asp_codec_ulppll : 1;
        unsigned int sc_gt_clk_swd2jtag_dap : 1;
        unsigned int sc_gt_clk_mudp_sys : 1;
        unsigned int sc_gt_clk_ao_tof : 1;
        unsigned int sc_gt_clk_ao_camera1 : 1;
        unsigned int gt_clk_dp_audio_pll_tp : 1;
        unsigned int sc_gt_clk_asp_codec_pll : 1;
        unsigned int sc_gt_clk_asp_subsys_fll : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV9_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_hsdt_subsys_fll_START (6)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_hsdt_subsys_fll_END (6)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_hsdt_subsys_START (7)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_hsdt_subsys_END (7)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_asp_codec_ulppll_START (8)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_asp_codec_ulppll_END (8)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_swd2jtag_dap_START (9)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_swd2jtag_dap_END (9)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_mudp_sys_START (10)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_mudp_sys_END (10)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_ao_tof_START (11)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_ao_tof_END (11)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_ao_camera1_START (12)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_ao_camera1_END (12)
#define SOC_AO_CRG_SCCLKDIV9_gt_clk_dp_audio_pll_tp_START (13)
#define SOC_AO_CRG_SCCLKDIV9_gt_clk_dp_audio_pll_tp_END (13)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_asp_codec_pll_START (14)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_asp_codec_pll_END (14)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_asp_subsys_fll_START (15)
#define SOC_AO_CRG_SCCLKDIV9_sc_gt_clk_asp_subsys_fll_END (15)
#define SOC_AO_CRG_SCCLKDIV9_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV9_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_asp_nonidle_pend : 1;
        unsigned int intr_mask_iomcu_nonidle_pend : 1;
        unsigned int intr_mask_hisee_nonidle_pend : 1;
        unsigned int intr_mask_hieps_nonidle_pend : 1;
        unsigned int intr_mask_hieps_ree_nonidle_pend : 1;
        unsigned int reserved_0 : 3;
        unsigned int intr_clr_asp_nonidle_pend : 1;
        unsigned int intr_clr_iomcu_nonidle_pend : 1;
        unsigned int intr_clr_hisee_nonidle_pend : 1;
        unsigned int intr_clr_hieps_nonidle_pend : 1;
        unsigned int intr_clr_hieps_ree_nonidle_pend : 1;
        unsigned int reserved_1 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_UNION;
#endif
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_asp_nonidle_pend_START (0)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_asp_nonidle_pend_END (0)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_iomcu_nonidle_pend_START (1)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_iomcu_nonidle_pend_END (1)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_hisee_nonidle_pend_START (2)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_hisee_nonidle_pend_END (2)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_hieps_nonidle_pend_START (3)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_hieps_nonidle_pend_END (3)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_hieps_ree_nonidle_pend_START (4)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_mask_hieps_ree_nonidle_pend_END (4)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_asp_nonidle_pend_START (8)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_asp_nonidle_pend_END (8)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_iomcu_nonidle_pend_START (9)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_iomcu_nonidle_pend_END (9)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_hisee_nonidle_pend_START (10)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_hisee_nonidle_pend_END (10)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_hieps_nonidle_pend_START (11)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_hieps_nonidle_pend_END (11)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_hieps_ree_nonidle_pend_START (12)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_intr_clr_hieps_ree_nonidle_pend_END (12)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_bitmasken_START (16)
#define SOC_AO_CRG_SC_INTR_NOCBUS_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_asp_subsys : 4;
        unsigned int div_asp_subsys_fll : 2;
        unsigned int reserved : 5;
        unsigned int div_fll_src_tp : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV10_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV10_sel_asp_subsys_START (0)
#define SOC_AO_CRG_SCCLKDIV10_sel_asp_subsys_END (3)
#define SOC_AO_CRG_SCCLKDIV10_div_asp_subsys_fll_START (4)
#define SOC_AO_CRG_SCCLKDIV10_div_asp_subsys_fll_END (5)
#define SOC_AO_CRG_SCCLKDIV10_div_fll_src_tp_START (11)
#define SOC_AO_CRG_SCCLKDIV10_div_fll_src_tp_END (15)
#define SOC_AO_CRG_SCCLKDIV10_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV10_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_asp_codec : 6;
        unsigned int sel_clk_out0 : 2;
        unsigned int sc_gt_clk_out0 : 1;
        unsigned int sc_gt_clk_out2 : 1;
        unsigned int div_clk_out0 : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV11_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV11_div_asp_codec_START (0)
#define SOC_AO_CRG_SCCLKDIV11_div_asp_codec_END (5)
#define SOC_AO_CRG_SCCLKDIV11_sel_clk_out0_START (6)
#define SOC_AO_CRG_SCCLKDIV11_sel_clk_out0_END (7)
#define SOC_AO_CRG_SCCLKDIV11_sc_gt_clk_out0_START (8)
#define SOC_AO_CRG_SCCLKDIV11_sc_gt_clk_out0_END (8)
#define SOC_AO_CRG_SCCLKDIV11_sc_gt_clk_out2_START (9)
#define SOC_AO_CRG_SCCLKDIV11_sc_gt_clk_out2_END (9)
#define SOC_AO_CRG_SCCLKDIV11_div_clk_out0_START (10)
#define SOC_AO_CRG_SCCLKDIV11_div_clk_out0_END (13)
#define SOC_AO_CRG_SCCLKDIV11_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV11_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_noc_timeout_extref_peri_bypass : 1;
        unsigned int gt_timerclk_refh_peri_bypass : 1;
        unsigned int gt_clkin_sys_peri_bypass : 1;
        unsigned int gt_clkin_ref_peri_bypass : 1;
        unsigned int gt_clk_sys_ini_peri_bypass : 1;
        unsigned int gt_clk_hsdt_subsys_bypass : 1;
        unsigned int gt_clk_ref_peri_bypass : 1;
        unsigned int gt_clk_sys_peri_bypass : 1;
        unsigned int gt_clk_aobus_peri_bypass : 1;
        unsigned int gt_clk_fll_src_peri_bypass : 1;
        unsigned int gt_clk_aonoc_peri_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_spll_peri_bypass : 1;
        unsigned int gt_clkin_sys_logic_peri_bypass : 1;
        unsigned int sel_clk_pcie_aux : 1;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV12_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_noc_timeout_extref_peri_bypass_START (0)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_noc_timeout_extref_peri_bypass_END (0)
#define SOC_AO_CRG_SCCLKDIV12_gt_timerclk_refh_peri_bypass_START (1)
#define SOC_AO_CRG_SCCLKDIV12_gt_timerclk_refh_peri_bypass_END (1)
#define SOC_AO_CRG_SCCLKDIV12_gt_clkin_sys_peri_bypass_START (2)
#define SOC_AO_CRG_SCCLKDIV12_gt_clkin_sys_peri_bypass_END (2)
#define SOC_AO_CRG_SCCLKDIV12_gt_clkin_ref_peri_bypass_START (3)
#define SOC_AO_CRG_SCCLKDIV12_gt_clkin_ref_peri_bypass_END (3)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_sys_ini_peri_bypass_START (4)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_sys_ini_peri_bypass_END (4)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_hsdt_subsys_bypass_START (5)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_hsdt_subsys_bypass_END (5)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_ref_peri_bypass_START (6)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_ref_peri_bypass_END (6)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_sys_peri_bypass_START (7)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_sys_peri_bypass_END (7)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_aobus_peri_bypass_START (8)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_aobus_peri_bypass_END (8)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_fll_src_peri_bypass_START (9)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_fll_src_peri_bypass_END (9)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_aonoc_peri_bypass_START (10)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_aonoc_peri_bypass_END (10)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_spll_peri_bypass_START (12)
#define SOC_AO_CRG_SCCLKDIV12_gt_clk_spll_peri_bypass_END (12)
#define SOC_AO_CRG_SCCLKDIV12_gt_clkin_sys_logic_peri_bypass_START (13)
#define SOC_AO_CRG_SCCLKDIV12_gt_clkin_sys_logic_peri_bypass_END (13)
#define SOC_AO_CRG_SCCLKDIV12_sel_clk_pcie_aux_START (14)
#define SOC_AO_CRG_SCCLKDIV12_sel_clk_pcie_aux_END (14)
#define SOC_AO_CRG_SCCLKDIV12_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV12_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int sleep_mode_spi11dma_bypass : 1;
        unsigned int sleep_mode_spi5_bypass : 1;
        unsigned int sleep_mode_dp_audio_bypass : 1;
        unsigned int sleep_mode_spi3_bypass : 1;
        unsigned int sleep_mode_ufs_bypass : 1;
        unsigned int sleep_mode_cssys_bypass : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV13_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_spi11dma_bypass_START (10)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_spi11dma_bypass_END (10)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_spi5_bypass_START (11)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_spi5_bypass_END (11)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_dp_audio_bypass_START (12)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_dp_audio_bypass_END (12)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_spi3_bypass_START (13)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_spi3_bypass_END (13)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_ufs_bypass_START (14)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_ufs_bypass_END (14)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_cssys_bypass_START (15)
#define SOC_AO_CRG_SCCLKDIV13_sleep_mode_cssys_bypass_END (15)
#define SOC_AO_CRG_SCCLKDIV13_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV13_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_memrepair_fll : 4;
        unsigned int sel_clk_ao_camera : 2;
        unsigned int sel_memrepair_peri : 2;
        unsigned int div_swd2jtag_dap : 4;
        unsigned int sel_memrepair : 2;
        unsigned int sc_gt_clk_ao_camera : 1;
        unsigned int sc_gt_clk_memrepair_fll_div : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV14_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV14_div_memrepair_fll_START (0)
#define SOC_AO_CRG_SCCLKDIV14_div_memrepair_fll_END (3)
#define SOC_AO_CRG_SCCLKDIV14_sel_clk_ao_camera_START (4)
#define SOC_AO_CRG_SCCLKDIV14_sel_clk_ao_camera_END (5)
#define SOC_AO_CRG_SCCLKDIV14_sel_memrepair_peri_START (6)
#define SOC_AO_CRG_SCCLKDIV14_sel_memrepair_peri_END (7)
#define SOC_AO_CRG_SCCLKDIV14_div_swd2jtag_dap_START (8)
#define SOC_AO_CRG_SCCLKDIV14_div_swd2jtag_dap_END (11)
#define SOC_AO_CRG_SCCLKDIV14_sel_memrepair_START (12)
#define SOC_AO_CRG_SCCLKDIV14_sel_memrepair_END (13)
#define SOC_AO_CRG_SCCLKDIV14_sc_gt_clk_ao_camera_START (14)
#define SOC_AO_CRG_SCCLKDIV14_sc_gt_clk_ao_camera_END (14)
#define SOC_AO_CRG_SCCLKDIV14_sc_gt_clk_memrepair_fll_div_START (15)
#define SOC_AO_CRG_SCCLKDIV14_sc_gt_clk_memrepair_fll_div_END (15)
#define SOC_AO_CRG_SCCLKDIV14_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV14_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_mad_fll : 5;
        unsigned int sel_pll_ctrl_tp_ao : 3;
        unsigned int reserved_0 : 6;
        unsigned int sc_gt_clk_dp_audio_pll_ao : 1;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV15_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV15_div_mad_fll_START (0)
#define SOC_AO_CRG_SCCLKDIV15_div_mad_fll_END (4)
#define SOC_AO_CRG_SCCLKDIV15_sel_pll_ctrl_tp_ao_START (5)
#define SOC_AO_CRG_SCCLKDIV15_sel_pll_ctrl_tp_ao_END (7)
#define SOC_AO_CRG_SCCLKDIV15_sc_gt_clk_dp_audio_pll_ao_START (14)
#define SOC_AO_CRG_SCCLKDIV15_sc_gt_clk_dp_audio_pll_ao_END (14)
#define SOC_AO_CRG_SCCLKDIV15_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV15_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 4;
        unsigned int div_pcie_aux_32kpll : 6;
        unsigned int sc_gt_clk_pcie_aux_32kpll : 1;
        unsigned int div_memrepair_peri_fll : 4;
        unsigned int sc_gt_clk_memrepair_peri_fll_div : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV16_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV16_div_pcie_aux_32kpll_START (4)
#define SOC_AO_CRG_SCCLKDIV16_div_pcie_aux_32kpll_END (9)
#define SOC_AO_CRG_SCCLKDIV16_sc_gt_clk_pcie_aux_32kpll_START (10)
#define SOC_AO_CRG_SCCLKDIV16_sc_gt_clk_pcie_aux_32kpll_END (10)
#define SOC_AO_CRG_SCCLKDIV16_div_memrepair_peri_fll_START (11)
#define SOC_AO_CRG_SCCLKDIV16_div_memrepair_peri_fll_END (14)
#define SOC_AO_CRG_SCCLKDIV16_sc_gt_clk_memrepair_peri_fll_div_START (15)
#define SOC_AO_CRG_SCCLKDIV16_sc_gt_clk_memrepair_peri_fll_div_END (15)
#define SOC_AO_CRG_SCCLKDIV16_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV16_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
        unsigned int div_qspi_sfc_x2 : 4;
        unsigned int sc_gt_clk_qspi_sfc_x2 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV17_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV17_div_qspi_sfc_x2_START (8)
#define SOC_AO_CRG_SCCLKDIV17_div_qspi_sfc_x2_END (11)
#define SOC_AO_CRG_SCCLKDIV17_sc_gt_clk_qspi_sfc_x2_START (12)
#define SOC_AO_CRG_SCCLKDIV17_sc_gt_clk_qspi_sfc_x2_END (12)
#define SOC_AO_CRG_SCCLKDIV17_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV17_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int div_memrepair_peri : 6;
        unsigned int sc_gt_clk_memrepair_peri : 1;
        unsigned int reserved_1 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV18_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV18_div_memrepair_peri_START (5)
#define SOC_AO_CRG_SCCLKDIV18_div_memrepair_peri_END (10)
#define SOC_AO_CRG_SCCLKDIV18_sc_gt_clk_memrepair_peri_START (11)
#define SOC_AO_CRG_SCCLKDIV18_sc_gt_clk_memrepair_peri_END (11)
#define SOC_AO_CRG_SCCLKDIV18_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV18_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_spi5 : 1;
        unsigned int sc_gt_clk_spi5_ulppll : 1;
        unsigned int div_spi5 : 6;
        unsigned int div_spi5_ulppll : 4;
        unsigned int sel_spi5 : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV19_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV19_sc_gt_clk_spi5_START (0)
#define SOC_AO_CRG_SCCLKDIV19_sc_gt_clk_spi5_END (0)
#define SOC_AO_CRG_SCCLKDIV19_sc_gt_clk_spi5_ulppll_START (1)
#define SOC_AO_CRG_SCCLKDIV19_sc_gt_clk_spi5_ulppll_END (1)
#define SOC_AO_CRG_SCCLKDIV19_div_spi5_START (2)
#define SOC_AO_CRG_SCCLKDIV19_div_spi5_END (7)
#define SOC_AO_CRG_SCCLKDIV19_div_spi5_ulppll_START (8)
#define SOC_AO_CRG_SCCLKDIV19_div_spi5_ulppll_END (11)
#define SOC_AO_CRG_SCCLKDIV19_sel_spi5_START (12)
#define SOC_AO_CRG_SCCLKDIV19_sel_spi5_END (12)
#define SOC_AO_CRG_SCCLKDIV19_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV19_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_dp_audio_pll_ao : 4;
        unsigned int gt_clk_aupll_sscg : 1;
        unsigned int div_blpwm2 : 2;
        unsigned int div_spi3 : 6;
        unsigned int sc_gt_clk_spi3_ulppll : 1;
        unsigned int sc_gt_clk_spi3 : 1;
        unsigned int sel_spi3 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV20_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV20_div_dp_audio_pll_ao_START (0)
#define SOC_AO_CRG_SCCLKDIV20_div_dp_audio_pll_ao_END (3)
#define SOC_AO_CRG_SCCLKDIV20_gt_clk_aupll_sscg_START (4)
#define SOC_AO_CRG_SCCLKDIV20_gt_clk_aupll_sscg_END (4)
#define SOC_AO_CRG_SCCLKDIV20_div_blpwm2_START (5)
#define SOC_AO_CRG_SCCLKDIV20_div_blpwm2_END (6)
#define SOC_AO_CRG_SCCLKDIV20_div_spi3_START (7)
#define SOC_AO_CRG_SCCLKDIV20_div_spi3_END (12)
#define SOC_AO_CRG_SCCLKDIV20_sc_gt_clk_spi3_ulppll_START (13)
#define SOC_AO_CRG_SCCLKDIV20_sc_gt_clk_spi3_ulppll_END (13)
#define SOC_AO_CRG_SCCLKDIV20_sc_gt_clk_spi3_START (14)
#define SOC_AO_CRG_SCCLKDIV20_sc_gt_clk_spi3_END (14)
#define SOC_AO_CRG_SCCLKDIV20_sel_spi3_START (15)
#define SOC_AO_CRG_SCCLKDIV20_sel_spi3_END (15)
#define SOC_AO_CRG_SCCLKDIV20_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV20_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_spi3_ulppll : 4;
        unsigned int div_asp_codec_ulppll : 6;
        unsigned int div_blpwm0 : 2;
        unsigned int reserved : 2;
        unsigned int sel_asp_codec : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV21_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV21_div_spi3_ulppll_START (0)
#define SOC_AO_CRG_SCCLKDIV21_div_spi3_ulppll_END (3)
#define SOC_AO_CRG_SCCLKDIV21_div_asp_codec_ulppll_START (4)
#define SOC_AO_CRG_SCCLKDIV21_div_asp_codec_ulppll_END (9)
#define SOC_AO_CRG_SCCLKDIV21_div_blpwm0_START (10)
#define SOC_AO_CRG_SCCLKDIV21_div_blpwm0_END (11)
#define SOC_AO_CRG_SCCLKDIV21_sel_asp_codec_START (14)
#define SOC_AO_CRG_SCCLKDIV21_sel_asp_codec_END (15)
#define SOC_AO_CRG_SCCLKDIV21_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV21_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_loopback_en2 : 1;
        unsigned int ddr_reset_en2 : 1;
        unsigned int ddr_loopback_en : 1;
        unsigned int ddr_reset_en : 1;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV22_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV22_ddr_loopback_en2_START (0)
#define SOC_AO_CRG_SCCLKDIV22_ddr_loopback_en2_END (0)
#define SOC_AO_CRG_SCCLKDIV22_ddr_reset_en2_START (1)
#define SOC_AO_CRG_SCCLKDIV22_ddr_reset_en2_END (1)
#define SOC_AO_CRG_SCCLKDIV22_ddr_loopback_en_START (2)
#define SOC_AO_CRG_SCCLKDIV22_ddr_loopback_en_END (2)
#define SOC_AO_CRG_SCCLKDIV22_ddr_reset_en_START (3)
#define SOC_AO_CRG_SCCLKDIV22_ddr_reset_en_END (3)
#define SOC_AO_CRG_SCCLKDIV22_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV22_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_isp_snclk0 : 2;
        unsigned int sel_isp_snclk1 : 2;
        unsigned int sel_isp_snclk2 : 2;
        unsigned int sel_isp_snclk3 : 2;
        unsigned int div_isp_snclk_fix : 6;
        unsigned int sc_gt_clk_isp_snclk : 1;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV23_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk0_START (0)
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk0_END (1)
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk1_START (2)
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk1_END (3)
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk2_START (4)
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk2_END (5)
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk3_START (6)
#define SOC_AO_CRG_SCCLKDIV23_sel_isp_snclk3_END (7)
#define SOC_AO_CRG_SCCLKDIV23_div_isp_snclk_fix_START (8)
#define SOC_AO_CRG_SCCLKDIV23_div_isp_snclk_fix_END (13)
#define SOC_AO_CRG_SCCLKDIV23_sc_gt_clk_isp_snclk_START (14)
#define SOC_AO_CRG_SCCLKDIV23_sc_gt_clk_isp_snclk_END (14)
#define SOC_AO_CRG_SCCLKDIV23_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV23_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_isp_snclk0_div : 2;
        unsigned int div_isp_snclk1_div : 2;
        unsigned int div_isp_snclk2_div : 2;
        unsigned int div_isp_snclk3_div : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV24_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk0_div_START (0)
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk0_div_END (1)
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk1_div_START (2)
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk1_div_END (3)
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk2_div_START (4)
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk2_div_END (5)
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk3_div_START (6)
#define SOC_AO_CRG_SCCLKDIV24_div_isp_snclk3_div_END (7)
#define SOC_AO_CRG_SCCLKDIV24_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV24_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aupll_en_fsm_vote : 5;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SC_PLL_FSM_NS_VOTE0_UNION;
#endif
#define SOC_AO_CRG_SC_PLL_FSM_NS_VOTE0_aupll_en_fsm_vote_START (0)
#define SOC_AO_CRG_SC_PLL_FSM_NS_VOTE0_aupll_en_fsm_vote_END (4)
#define SOC_AO_CRG_SC_PLL_FSM_NS_VOTE0_bitmasken_START (16)
#define SOC_AO_CRG_SC_PLL_FSM_NS_VOTE0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_spmi1_vote : 10;
        unsigned int div_spmi1 : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV25_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV25_gt_clk_spmi1_vote_START (0)
#define SOC_AO_CRG_SCCLKDIV25_gt_clk_spmi1_vote_END (9)
#define SOC_AO_CRG_SCCLKDIV25_div_spmi1_START (10)
#define SOC_AO_CRG_SCCLKDIV25_div_spmi1_END (15)
#define SOC_AO_CRG_SCCLKDIV25_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV25_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_spmi1 : 1;
        unsigned int sel_spi11 : 1;
        unsigned int sc_gt_clk_spi11 : 1;
        unsigned int sc_gt_clk_spi11_ulppll : 1;
        unsigned int reserved_0 : 1;
        unsigned int div_spi11 : 6;
        unsigned int sel_spmi1_mst : 1;
        unsigned int reserved_1 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV26_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV26_sc_gt_clk_spmi1_START (0)
#define SOC_AO_CRG_SCCLKDIV26_sc_gt_clk_spmi1_END (0)
#define SOC_AO_CRG_SCCLKDIV26_sel_spi11_START (1)
#define SOC_AO_CRG_SCCLKDIV26_sel_spi11_END (1)
#define SOC_AO_CRG_SCCLKDIV26_sc_gt_clk_spi11_START (2)
#define SOC_AO_CRG_SCCLKDIV26_sc_gt_clk_spi11_END (2)
#define SOC_AO_CRG_SCCLKDIV26_sc_gt_clk_spi11_ulppll_START (3)
#define SOC_AO_CRG_SCCLKDIV26_sc_gt_clk_spi11_ulppll_END (3)
#define SOC_AO_CRG_SCCLKDIV26_div_spi11_START (5)
#define SOC_AO_CRG_SCCLKDIV26_div_spi11_END (10)
#define SOC_AO_CRG_SCCLKDIV26_sel_spmi1_mst_START (11)
#define SOC_AO_CRG_SCCLKDIV26_sel_spmi1_mst_END (11)
#define SOC_AO_CRG_SCCLKDIV26_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV26_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_spi11_ulppll : 6;
        unsigned int reserved : 10;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV27_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV27_div_spi11_ulppll_START (0)
#define SOC_AO_CRG_SCCLKDIV27_div_spi11_ulppll_END (5)
#define SOC_AO_CRG_SCCLKDIV27_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV27_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int x2_en_cfg : 1;
        unsigned int reserved : 1;
        unsigned int ki_s : 4;
        unsigned int ki_e : 3;
        unsigned int kp_s : 3;
        unsigned int kp_e : 3;
        unsigned int ki_s_x2 : 4;
        unsigned int ki_e_x2 : 3;
        unsigned int kp_s_x2 : 3;
        unsigned int kp_e_x2 : 3;
        unsigned int kdco_ctrl_cfg_en : 1;
        unsigned int kdco_ctrl_cfg : 3;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG0_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_x2_en_cfg_START (0)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_x2_en_cfg_END (0)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_s_START (2)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_s_END (5)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_e_START (6)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_e_END (8)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_s_START (9)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_s_END (11)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_e_START (12)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_e_END (14)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_s_x2_START (15)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_s_x2_END (18)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_e_x2_START (19)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_ki_e_x2_END (21)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_s_x2_START (22)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_s_x2_END (24)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_e_x2_START (25)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kp_e_x2_END (27)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kdco_ctrl_cfg_en_START (28)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kdco_ctrl_cfg_en_END (28)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kdco_ctrl_cfg_START (29)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG0_kdco_ctrl_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_vld : 1;
        unsigned int cfg_sel : 2;
        unsigned int rst_cfg_n : 1;
        unsigned int test_data_sel : 4;
        unsigned int read_en : 1;
        unsigned int test_ck_en : 1;
        unsigned int filter_rhm_sw_pll : 1;
        unsigned int swcap_en : 1;
        unsigned int delay_sel : 4;
        unsigned int sel_d2a_swcap : 2;
        unsigned int ulppll_ana_cfg : 5;
        unsigned int reserved : 9;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG1_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_cfg_vld_START (0)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_cfg_vld_END (0)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_cfg_sel_START (1)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_cfg_sel_END (2)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_rst_cfg_n_START (3)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_rst_cfg_n_END (3)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_test_data_sel_START (4)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_test_data_sel_END (7)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_read_en_START (8)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_read_en_END (8)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_test_ck_en_START (9)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_test_ck_en_END (9)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_filter_rhm_sw_pll_START (10)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_filter_rhm_sw_pll_END (10)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_swcap_en_START (11)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_swcap_en_END (11)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_delay_sel_START (12)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_delay_sel_END (15)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_sel_d2a_swcap_START (16)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_sel_d2a_swcap_END (17)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_ulppll_ana_cfg_START (18)
#define SOC_AO_CRG_SC_ULPPLL_1_CFG1_ulppll_ana_cfg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CFG8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_en : 1;
        unsigned int ulppll_bypass : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int ulppll_fbdiv : 15;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_CTRL0_UNION;
#endif
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ulppll_en_START (0)
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ulppll_en_END (0)
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ulppll_bypass_START (1)
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ulppll_bypass_END (1)
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ulppll_fbdiv_START (8)
#define SOC_AO_CRG_SC_ULPPLL_1_CTRL0_ulppll_fbdiv_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SC_ULPPLL_1_STATE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_asp_nonidle_pend : 1;
        unsigned int intr_stat_iomcu_nonidle_pend : 1;
        unsigned int intr_stat_hisee_nonidle_pend : 1;
        unsigned int intr_stat_hieps_nonidle_pend : 1;
        unsigned int intr_stat_hieps_ree_nonidle_pend : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 15;
    } reg;
} SOC_AO_CRG_SC_INTR_NOCBUS_STAT_UNION;
#endif
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_asp_nonidle_pend_START (0)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_asp_nonidle_pend_END (0)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_iomcu_nonidle_pend_START (1)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_iomcu_nonidle_pend_END (1)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_hisee_nonidle_pend_START (2)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_hisee_nonidle_pend_END (2)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_hieps_nonidle_pend_START (3)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_hieps_nonidle_pend_END (3)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_hieps_ree_nonidle_pend_START (4)
#define SOC_AO_CRG_SC_INTR_NOCBUS_STAT_intr_stat_hieps_ree_nonidle_pend_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int spll_fsm_wsat : 1;
        unsigned int aupll_fsm_wsat : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 15;
    } reg;
} SOC_AO_CRG_SCPERSTATUS17_UNION;
#endif
#define SOC_AO_CRG_SCPERSTATUS17_spll_fsm_wsat_START (9)
#define SOC_AO_CRG_SCPERSTATUS17_spll_fsm_wsat_END (9)
#define SOC_AO_CRG_SCPERSTATUS17_aupll_fsm_wsat_START (10)
#define SOC_AO_CRG_SCPERSTATUS17_aupll_fsm_wsat_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_ack_clk_memrepair_sw : 3;
        unsigned int sw_ack_clk_aobus_ini : 2;
        unsigned int swdone_clk_asp_codec_pll_div : 1;
        unsigned int swdone_clk_ufs_mphy_sys_div : 1;
        unsigned int swdone_clk_asp_codec_ulppll_div : 1;
        unsigned int swdone_clk_qspi_sfc_x2_div : 1;
        unsigned int reserved : 3;
        unsigned int swdone_clk_spmi_mst : 1;
        unsigned int sw_ack_clk_aonoc_sw : 2;
        unsigned int swdone_clk_ao_camera_div : 1;
        unsigned int swdone_clk_ao_camera1_div : 1;
        unsigned int st_pclk_spmi : 1;
        unsigned int sw_ack_clk_hsdt_subsys_sw : 3;
        unsigned int swdone_clk_hsdt_subsys_div : 1;
        unsigned int swdone_clk_ao_tof_div : 1;
        unsigned int sw_ack_clk_asp_codec_sw : 2;
        unsigned int sw_ack_clk_memrepair_peri_sw : 3;
        unsigned int swdone_clk_mudp_sys_div : 1;
        unsigned int swdone_clk_hsdt_subsys_fll_div : 1;
        unsigned int sw_ack_clk_hsdt_subsys_fll_sw : 2;
    } reg;
} SOC_AO_CRG_SCPERSTATUS16_UNION;
#endif
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_memrepair_sw_START (0)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_memrepair_sw_END (2)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_aobus_ini_START (3)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_aobus_ini_END (4)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_asp_codec_pll_div_START (5)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_asp_codec_pll_div_END (5)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ufs_mphy_sys_div_START (6)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ufs_mphy_sys_div_END (6)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_asp_codec_ulppll_div_START (7)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_asp_codec_ulppll_div_END (7)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_qspi_sfc_x2_div_START (8)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_qspi_sfc_x2_div_END (8)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_spmi_mst_START (12)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_spmi_mst_END (12)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_aonoc_sw_START (13)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_aonoc_sw_END (14)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ao_camera_div_START (15)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ao_camera_div_END (15)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ao_camera1_div_START (16)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ao_camera1_div_END (16)
#define SOC_AO_CRG_SCPERSTATUS16_st_pclk_spmi_START (17)
#define SOC_AO_CRG_SCPERSTATUS16_st_pclk_spmi_END (17)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_hsdt_subsys_sw_START (18)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_hsdt_subsys_sw_END (20)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_hsdt_subsys_div_START (21)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_hsdt_subsys_div_END (21)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ao_tof_div_START (22)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_ao_tof_div_END (22)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_asp_codec_sw_START (23)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_asp_codec_sw_END (24)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_memrepair_peri_sw_START (25)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_memrepair_peri_sw_END (27)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_mudp_sys_div_START (28)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_mudp_sys_div_END (28)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_hsdt_subsys_fll_div_START (29)
#define SOC_AO_CRG_SCPERSTATUS16_swdone_clk_hsdt_subsys_fll_div_END (29)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_hsdt_subsys_fll_sw_START (30)
#define SOC_AO_CRG_SCPERSTATUS16_sw_ack_clk_hsdt_subsys_fll_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swdone_clk_hio_ulp : 1;
        unsigned int swdone_clk_isp_snclk3_div : 1;
        unsigned int swdone_clk_isp_snclk2_div : 1;
        unsigned int swdone_clk_isp_snclk1_div : 1;
        unsigned int swdone_clk_isp_snclk0_div : 1;
        unsigned int swdone_clk_isp_snclk_fix_div : 1;
        unsigned int swdone_clk_sys_ulppll_div : 1;
        unsigned int st_pclk_spmi1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_pclk_sts : 1;
        unsigned int st_pclk_sts_gpio1 : 1;
        unsigned int st_pclk_sts_gpio2 : 1;
        unsigned int swdone_clk_spmi1_div : 1;
        unsigned int swdone_clk_blpwm0_div : 1;
        unsigned int st_clk_spmi1 : 1;
        unsigned int reserved_1 : 6;
        unsigned int sw_ack_clk_iomcu_fll_sw : 2;
        unsigned int reserved_2 : 1;
        unsigned int sw_ack_clk_asp_codec_sw_pre : 2;
        unsigned int sw_ack_clk_sys_ulppll_sw : 2;
        unsigned int sw_ack_clk_sys_pre : 2;
        unsigned int sw_ack_clk_ufs_mphy_sys_sw : 2;
    } reg;
} SOC_AO_CRG_SCPERSTATUS18_UNION;
#endif
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_hio_ulp_START (0)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_hio_ulp_END (0)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk3_div_START (1)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk3_div_END (1)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk2_div_START (2)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk2_div_END (2)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk1_div_START (3)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk1_div_END (3)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk0_div_START (4)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk0_div_END (4)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk_fix_div_START (5)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_isp_snclk_fix_div_END (5)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_sys_ulppll_div_START (6)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_sys_ulppll_div_END (6)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_spmi1_START (7)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_spmi1_END (7)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_sts_START (9)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_sts_END (9)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_sts_gpio1_START (10)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_sts_gpio1_END (10)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_sts_gpio2_START (11)
#define SOC_AO_CRG_SCPERSTATUS18_st_pclk_sts_gpio2_END (11)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_spmi1_div_START (12)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_spmi1_div_END (12)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_blpwm0_div_START (13)
#define SOC_AO_CRG_SCPERSTATUS18_swdone_clk_blpwm0_div_END (13)
#define SOC_AO_CRG_SCPERSTATUS18_st_clk_spmi1_START (14)
#define SOC_AO_CRG_SCPERSTATUS18_st_clk_spmi1_END (14)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_iomcu_fll_sw_START (21)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_iomcu_fll_sw_END (22)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_asp_codec_sw_pre_START (24)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_asp_codec_sw_pre_END (25)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_sys_ulppll_sw_START (26)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_sys_ulppll_sw_END (27)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_sys_pre_START (28)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_sys_pre_END (29)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_ufs_mphy_sys_sw_START (30)
#define SOC_AO_CRG_SCPERSTATUS18_sw_ack_clk_ufs_mphy_sys_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_hio_sys : 1;
        unsigned int st_clk_hio_ulp : 1;
        unsigned int st_clk_hio_spll : 1;
        unsigned int st_pclk_hio : 1;
        unsigned int st_aclk_hio : 1;
        unsigned int swdone_clk_aonoc_pll_div : 1;
        unsigned int sw_ack_clk_spi11_sw : 2;
        unsigned int swdone_clk_spi11_div : 1;
        unsigned int swdone_clk_spi11_ulppll_div : 1;
        unsigned int st_clk_qic_spi11dma : 1;
        unsigned int st_clk_spi11dma : 1;
        unsigned int st_clk_aonoc_peri : 1;
        unsigned int sw_ack_clk_hio_ulp_sw : 2;
        unsigned int sw_ack_clk_aonoc_fll_sw : 2;
        unsigned int reserved : 15;
    } reg;
} SOC_AO_CRG_SCPERSTATUS19_UNION;
#endif
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_hio_sys_START (0)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_hio_sys_END (0)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_hio_ulp_START (1)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_hio_ulp_END (1)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_hio_spll_START (2)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_hio_spll_END (2)
#define SOC_AO_CRG_SCPERSTATUS19_st_pclk_hio_START (3)
#define SOC_AO_CRG_SCPERSTATUS19_st_pclk_hio_END (3)
#define SOC_AO_CRG_SCPERSTATUS19_st_aclk_hio_START (4)
#define SOC_AO_CRG_SCPERSTATUS19_st_aclk_hio_END (4)
#define SOC_AO_CRG_SCPERSTATUS19_swdone_clk_aonoc_pll_div_START (5)
#define SOC_AO_CRG_SCPERSTATUS19_swdone_clk_aonoc_pll_div_END (5)
#define SOC_AO_CRG_SCPERSTATUS19_sw_ack_clk_spi11_sw_START (6)
#define SOC_AO_CRG_SCPERSTATUS19_sw_ack_clk_spi11_sw_END (7)
#define SOC_AO_CRG_SCPERSTATUS19_swdone_clk_spi11_div_START (8)
#define SOC_AO_CRG_SCPERSTATUS19_swdone_clk_spi11_div_END (8)
#define SOC_AO_CRG_SCPERSTATUS19_swdone_clk_spi11_ulppll_div_START (9)
#define SOC_AO_CRG_SCPERSTATUS19_swdone_clk_spi11_ulppll_div_END (9)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_qic_spi11dma_START (10)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_qic_spi11dma_END (10)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_spi11dma_START (11)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_spi11dma_END (11)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_aonoc_peri_START (12)
#define SOC_AO_CRG_SCPERSTATUS19_st_clk_aonoc_peri_END (12)
#define SOC_AO_CRG_SCPERSTATUS19_sw_ack_clk_hio_ulp_sw_START (13)
#define SOC_AO_CRG_SCPERSTATUS19_sw_ack_clk_hio_ulp_sw_END (14)
#define SOC_AO_CRG_SCPERSTATUS19_sw_ack_clk_aonoc_fll_sw_START (15)
#define SOC_AO_CRG_SCPERSTATUS19_sw_ack_clk_aonoc_fll_sw_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aupll_en : 1;
        unsigned int aupll_bp : 1;
        unsigned int aupll_refdiv : 6;
        unsigned int aupll_fbdiv : 12;
        unsigned int aupll_postdiv1 : 3;
        unsigned int aupll_postdiv2 : 3;
        unsigned int reserved : 6;
    } reg;
} SOC_AO_CRG_SCAUPLLCTRL0_UNION;
#endif
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_en_START (0)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_en_END (0)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_bp_START (1)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_bp_END (1)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_refdiv_START (2)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_refdiv_END (7)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_fbdiv_START (8)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_fbdiv_END (19)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_postdiv1_START (20)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_postdiv1_END (22)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_postdiv2_START (23)
#define SOC_AO_CRG_SCAUPLLCTRL0_aupll_postdiv2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aupll_fracdiv : 24;
        unsigned int aupll_int_mod : 1;
        unsigned int aupll_cfg_vld : 1;
        unsigned int gt_clk_aupll : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_AO_CRG_SCAUPLLCTRL1_UNION;
#endif
#define SOC_AO_CRG_SCAUPLLCTRL1_aupll_fracdiv_START (0)
#define SOC_AO_CRG_SCAUPLLCTRL1_aupll_fracdiv_END (23)
#define SOC_AO_CRG_SCAUPLLCTRL1_aupll_int_mod_START (24)
#define SOC_AO_CRG_SCAUPLLCTRL1_aupll_int_mod_END (24)
#define SOC_AO_CRG_SCAUPLLCTRL1_aupll_cfg_vld_START (25)
#define SOC_AO_CRG_SCAUPLLCTRL1_aupll_cfg_vld_END (25)
#define SOC_AO_CRG_SCAUPLLCTRL1_gt_clk_aupll_START (26)
#define SOC_AO_CRG_SCAUPLLCTRL1_gt_clk_aupll_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_rate : 4;
        unsigned int sscg_depth : 3;
        unsigned int sscg_fast_dis : 1;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCAUPLLSSCCTRL_UNION;
#endif
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_enable_START (0)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_enable_END (0)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_mode_START (1)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_mode_END (1)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_rate_START (2)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_rate_END (5)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_depth_START (6)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_depth_END (8)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_fast_dis_START (9)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_sscg_fast_dis_END (9)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_bitmasken_START (16)
#define SOC_AO_CRG_SCAUPLLSSCCTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_reg_sel : 1;
        unsigned int read_en : 1;
        unsigned int input_cfg_en : 1;
        unsigned int test_mode : 1;
        unsigned int unlock_clear : 1;
        unsigned int dll_en : 1;
        unsigned int pll_lock_ate_sel : 2;
        unsigned int test_data_sel : 4;
        unsigned int bias_ctrl : 2;
        unsigned int icp_ctrl : 2;
        unsigned int updn_sel : 1;
        unsigned int reserved : 2;
        unsigned int int_mask : 3;
        unsigned int pfd_div_ratio : 4;
        unsigned int freq_threshold : 6;
    } reg;
} SOC_AO_CRG_AUFNPLL_CFG0_UNION;
#endif
#define SOC_AO_CRG_AUFNPLL_CFG0_sta_reg_sel_START (0)
#define SOC_AO_CRG_AUFNPLL_CFG0_sta_reg_sel_END (0)
#define SOC_AO_CRG_AUFNPLL_CFG0_read_en_START (1)
#define SOC_AO_CRG_AUFNPLL_CFG0_read_en_END (1)
#define SOC_AO_CRG_AUFNPLL_CFG0_input_cfg_en_START (2)
#define SOC_AO_CRG_AUFNPLL_CFG0_input_cfg_en_END (2)
#define SOC_AO_CRG_AUFNPLL_CFG0_test_mode_START (3)
#define SOC_AO_CRG_AUFNPLL_CFG0_test_mode_END (3)
#define SOC_AO_CRG_AUFNPLL_CFG0_unlock_clear_START (4)
#define SOC_AO_CRG_AUFNPLL_CFG0_unlock_clear_END (4)
#define SOC_AO_CRG_AUFNPLL_CFG0_dll_en_START (5)
#define SOC_AO_CRG_AUFNPLL_CFG0_dll_en_END (5)
#define SOC_AO_CRG_AUFNPLL_CFG0_pll_lock_ate_sel_START (6)
#define SOC_AO_CRG_AUFNPLL_CFG0_pll_lock_ate_sel_END (7)
#define SOC_AO_CRG_AUFNPLL_CFG0_test_data_sel_START (8)
#define SOC_AO_CRG_AUFNPLL_CFG0_test_data_sel_END (11)
#define SOC_AO_CRG_AUFNPLL_CFG0_bias_ctrl_START (12)
#define SOC_AO_CRG_AUFNPLL_CFG0_bias_ctrl_END (13)
#define SOC_AO_CRG_AUFNPLL_CFG0_icp_ctrl_START (14)
#define SOC_AO_CRG_AUFNPLL_CFG0_icp_ctrl_END (15)
#define SOC_AO_CRG_AUFNPLL_CFG0_updn_sel_START (16)
#define SOC_AO_CRG_AUFNPLL_CFG0_updn_sel_END (16)
#define SOC_AO_CRG_AUFNPLL_CFG0_int_mask_START (19)
#define SOC_AO_CRG_AUFNPLL_CFG0_int_mask_END (21)
#define SOC_AO_CRG_AUFNPLL_CFG0_pfd_div_ratio_START (22)
#define SOC_AO_CRG_AUFNPLL_CFG0_pfd_div_ratio_END (25)
#define SOC_AO_CRG_AUFNPLL_CFG0_freq_threshold_START (26)
#define SOC_AO_CRG_AUFNPLL_CFG0_freq_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctinue_lock_num : 6;
        unsigned int lock_thr : 2;
        unsigned int dc_ac_clk_en : 1;
        unsigned int dtc_ctrl_inv : 1;
        unsigned int reserved : 6;
        unsigned int ana_cfg_fnpll : 16;
    } reg;
} SOC_AO_CRG_AUFNPLL_CFG1_UNION;
#endif
#define SOC_AO_CRG_AUFNPLL_CFG1_ctinue_lock_num_START (0)
#define SOC_AO_CRG_AUFNPLL_CFG1_ctinue_lock_num_END (5)
#define SOC_AO_CRG_AUFNPLL_CFG1_lock_thr_START (6)
#define SOC_AO_CRG_AUFNPLL_CFG1_lock_thr_END (7)
#define SOC_AO_CRG_AUFNPLL_CFG1_dc_ac_clk_en_START (8)
#define SOC_AO_CRG_AUFNPLL_CFG1_dc_ac_clk_en_END (8)
#define SOC_AO_CRG_AUFNPLL_CFG1_dtc_ctrl_inv_START (9)
#define SOC_AO_CRG_AUFNPLL_CFG1_dtc_ctrl_inv_END (9)
#define SOC_AO_CRG_AUFNPLL_CFG1_ana_cfg_fnpll_START (16)
#define SOC_AO_CRG_AUFNPLL_CFG1_ana_cfg_fnpll_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div2_pd : 1;
        unsigned int fbdiv_rst_n : 1;
        unsigned int refdiv_rst_n : 1;
        unsigned int dll_force_en : 1;
        unsigned int phe_code_a : 2;
        unsigned int phe_code_b : 2;
        unsigned int bbpd_calib_byp : 1;
        unsigned int k_gain_cfg_en : 1;
        unsigned int k_gain_cfg : 6;
        unsigned int k_gain_av_thr : 3;
        unsigned int dtc_test : 1;
        unsigned int dtc_m_cfg : 6;
        unsigned int dtc_o_cfg : 6;
    } reg;
} SOC_AO_CRG_AUFNPLL_CFG2_UNION;
#endif
#define SOC_AO_CRG_AUFNPLL_CFG2_div2_pd_START (0)
#define SOC_AO_CRG_AUFNPLL_CFG2_div2_pd_END (0)
#define SOC_AO_CRG_AUFNPLL_CFG2_fbdiv_rst_n_START (1)
#define SOC_AO_CRG_AUFNPLL_CFG2_fbdiv_rst_n_END (1)
#define SOC_AO_CRG_AUFNPLL_CFG2_refdiv_rst_n_START (2)
#define SOC_AO_CRG_AUFNPLL_CFG2_refdiv_rst_n_END (2)
#define SOC_AO_CRG_AUFNPLL_CFG2_dll_force_en_START (3)
#define SOC_AO_CRG_AUFNPLL_CFG2_dll_force_en_END (3)
#define SOC_AO_CRG_AUFNPLL_CFG2_phe_code_a_START (4)
#define SOC_AO_CRG_AUFNPLL_CFG2_phe_code_a_END (5)
#define SOC_AO_CRG_AUFNPLL_CFG2_phe_code_b_START (6)
#define SOC_AO_CRG_AUFNPLL_CFG2_phe_code_b_END (7)
#define SOC_AO_CRG_AUFNPLL_CFG2_bbpd_calib_byp_START (8)
#define SOC_AO_CRG_AUFNPLL_CFG2_bbpd_calib_byp_END (8)
#define SOC_AO_CRG_AUFNPLL_CFG2_k_gain_cfg_en_START (9)
#define SOC_AO_CRG_AUFNPLL_CFG2_k_gain_cfg_en_END (9)
#define SOC_AO_CRG_AUFNPLL_CFG2_k_gain_cfg_START (10)
#define SOC_AO_CRG_AUFNPLL_CFG2_k_gain_cfg_END (15)
#define SOC_AO_CRG_AUFNPLL_CFG2_k_gain_av_thr_START (16)
#define SOC_AO_CRG_AUFNPLL_CFG2_k_gain_av_thr_END (18)
#define SOC_AO_CRG_AUFNPLL_CFG2_dtc_test_START (19)
#define SOC_AO_CRG_AUFNPLL_CFG2_dtc_test_END (19)
#define SOC_AO_CRG_AUFNPLL_CFG2_dtc_m_cfg_START (20)
#define SOC_AO_CRG_AUFNPLL_CFG2_dtc_m_cfg_END (25)
#define SOC_AO_CRG_AUFNPLL_CFG2_dtc_o_cfg_START (26)
#define SOC_AO_CRG_AUFNPLL_CFG2_dtc_o_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scppll_cfg3 : 32;
    } reg;
} SOC_AO_CRG_AUFNPLL_CFG3_UNION;
#endif
#define SOC_AO_CRG_AUFNPLL_CFG3_scppll_cfg3_START (0)
#define SOC_AO_CRG_AUFNPLL_CFG3_scppll_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_AO_CRG_AUFNPLL_STATE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_div_auto_reduce_bypass : 1;
        unsigned int pcie_auto_waitcfg_in : 10;
        unsigned int pcie_auto_waitcfg_out : 10;
        unsigned int pcie_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_AO_CRG_AO_AUTODIV2_UNION;
#endif
#define SOC_AO_CRG_AO_AUTODIV2_pcie_div_auto_reduce_bypass_START (0)
#define SOC_AO_CRG_AO_AUTODIV2_pcie_div_auto_reduce_bypass_END (0)
#define SOC_AO_CRG_AO_AUTODIV2_pcie_auto_waitcfg_in_START (1)
#define SOC_AO_CRG_AO_AUTODIV2_pcie_auto_waitcfg_in_END (10)
#define SOC_AO_CRG_AO_AUTODIV2_pcie_auto_waitcfg_out_START (11)
#define SOC_AO_CRG_AO_AUTODIV2_pcie_auto_waitcfg_out_END (20)
#define SOC_AO_CRG_AO_AUTODIV2_pcie_div_auto_cfg_START (21)
#define SOC_AO_CRG_AO_AUTODIV2_pcie_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_timer1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_ao_tzpc : 1;
        unsigned int gt_pclk_efusec2 : 1;
        unsigned int gt_pclk_efusec : 1;
        unsigned int gt_clk_out0 : 1;
        unsigned int gt_clk_sts : 1;
        unsigned int gt_pclk_ao_gpio1_se : 1;
        unsigned int gt_clk_ao_tcp : 1;
        unsigned int gt_clk_ao_tcp_32k : 1;
        unsigned int gt_clk_sts_i2s : 1;
        unsigned int gt_clk_sts_rffe_ssc : 1;
        unsigned int gt_clk_sts_spi0 : 1;
        unsigned int gt_clk_sts_spi1 : 1;
        unsigned int gt_hclk_qspi_qic : 1;
        unsigned int gt_clk_aupll_media2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_ao_ipc : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_pclkdbg_to_iomcu : 1;
        unsigned int gt_clk_noc_aobus2iomcubus : 1;
        unsigned int gt_aclk_hio : 1;
        unsigned int gt_pclk_hio : 1;
        unsigned int gt_clk_hio_ulp : 1;
        unsigned int gt_clk_hio_sys : 1;
        unsigned int gt_clk_hio_spll : 1;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_AO_CRG_SCPEREN0_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_timer1_START (0)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_timer1_END (0)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_ao_tzpc_START (2)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_ao_tzpc_END (2)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_efusec2_START (3)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_efusec2_END (3)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_efusec_START (4)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_efusec_END (4)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_out0_START (5)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_out0_END (5)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_START (6)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_END (6)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_ao_gpio1_se_START (7)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_ao_gpio1_se_END (7)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_ao_tcp_START (8)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_ao_tcp_END (8)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_ao_tcp_32k_START (9)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_ao_tcp_32k_END (9)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_i2s_START (10)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_i2s_END (10)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_rffe_ssc_START (11)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_rffe_ssc_END (11)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_spi0_START (12)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_spi0_END (12)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_spi1_START (13)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_sts_spi1_END (13)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_hclk_qspi_qic_START (14)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_hclk_qspi_qic_END (14)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_aupll_media2_START (15)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_aupll_media2_END (15)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_ao_ipc_START (19)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_ao_ipc_END (19)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclkdbg_to_iomcu_START (24)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclkdbg_to_iomcu_END (24)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_noc_aobus2iomcubus_START (25)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_noc_aobus2iomcubus_END (25)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_aclk_hio_START (26)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_aclk_hio_END (26)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_hio_START (27)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_pclk_hio_END (27)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_hio_ulp_START (28)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_hio_ulp_END (28)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_hio_sys_START (29)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_hio_sys_END (29)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_hio_spll_START (30)
#define SOC_AO_CRG_SCPEREN0_SEC_gt_clk_hio_spll_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_timer1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_ao_tzpc : 1;
        unsigned int gt_pclk_efusec2 : 1;
        unsigned int gt_pclk_efusec : 1;
        unsigned int gt_clk_out0 : 1;
        unsigned int gt_clk_sts : 1;
        unsigned int gt_pclk_ao_gpio1_se : 1;
        unsigned int gt_clk_ao_tcp : 1;
        unsigned int gt_clk_ao_tcp_32k : 1;
        unsigned int gt_clk_sts_i2s : 1;
        unsigned int gt_clk_sts_rffe_ssc : 1;
        unsigned int gt_clk_sts_spi0 : 1;
        unsigned int gt_clk_sts_spi1 : 1;
        unsigned int gt_hclk_qspi_qic : 1;
        unsigned int gt_clk_aupll_media2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_ao_ipc : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_pclkdbg_to_iomcu : 1;
        unsigned int gt_clk_noc_aobus2iomcubus : 1;
        unsigned int gt_aclk_hio : 1;
        unsigned int gt_pclk_hio : 1;
        unsigned int gt_clk_hio_ulp : 1;
        unsigned int gt_clk_hio_sys : 1;
        unsigned int gt_clk_hio_spll : 1;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS0_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_timer1_START (0)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_timer1_END (0)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_ao_tzpc_START (2)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_ao_tzpc_END (2)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_efusec2_START (3)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_efusec2_END (3)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_efusec_START (4)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_efusec_END (4)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_out0_START (5)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_out0_END (5)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_START (6)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_END (6)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_ao_gpio1_se_START (7)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_ao_gpio1_se_END (7)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_ao_tcp_START (8)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_ao_tcp_END (8)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_ao_tcp_32k_START (9)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_ao_tcp_32k_END (9)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_i2s_START (10)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_i2s_END (10)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_rffe_ssc_START (11)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_rffe_ssc_END (11)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_spi0_START (12)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_spi0_END (12)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_spi1_START (13)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_sts_spi1_END (13)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_hclk_qspi_qic_START (14)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_hclk_qspi_qic_END (14)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_aupll_media2_START (15)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_aupll_media2_END (15)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_ao_ipc_START (19)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_ao_ipc_END (19)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclkdbg_to_iomcu_START (24)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclkdbg_to_iomcu_END (24)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_noc_aobus2iomcubus_START (25)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_noc_aobus2iomcubus_END (25)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_aclk_hio_START (26)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_aclk_hio_END (26)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_hio_START (27)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_pclk_hio_END (27)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_hio_ulp_START (28)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_hio_ulp_END (28)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_hio_sys_START (29)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_hio_sys_END (29)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_hio_spll_START (30)
#define SOC_AO_CRG_SCPERDIS0_SEC_gt_clk_hio_spll_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_timer1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_ao_tzpc : 1;
        unsigned int gt_pclk_efusec2 : 1;
        unsigned int gt_pclk_efusec : 1;
        unsigned int gt_clk_out0 : 1;
        unsigned int gt_clk_sts : 1;
        unsigned int gt_pclk_ao_gpio1_se : 1;
        unsigned int gt_clk_ao_tcp : 1;
        unsigned int gt_clk_ao_tcp_32k : 1;
        unsigned int gt_clk_sts_i2s : 1;
        unsigned int gt_clk_sts_rffe_ssc : 1;
        unsigned int gt_clk_sts_spi0 : 1;
        unsigned int gt_clk_sts_spi1 : 1;
        unsigned int gt_hclk_qspi_qic : 1;
        unsigned int gt_clk_aupll_media2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_ao_ipc : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_pclkdbg_to_iomcu : 1;
        unsigned int gt_clk_noc_aobus2iomcubus : 1;
        unsigned int gt_aclk_hio : 1;
        unsigned int gt_pclk_hio : 1;
        unsigned int gt_clk_hio_ulp : 1;
        unsigned int gt_clk_hio_sys : 1;
        unsigned int gt_clk_hio_spll : 1;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN0_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_timer1_START (0)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_timer1_END (0)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_ao_tzpc_START (2)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_ao_tzpc_END (2)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_efusec2_START (3)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_efusec2_END (3)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_efusec_START (4)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_efusec_END (4)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_out0_START (5)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_out0_END (5)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_START (6)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_END (6)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_ao_gpio1_se_START (7)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_ao_gpio1_se_END (7)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_ao_tcp_START (8)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_ao_tcp_END (8)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_ao_tcp_32k_START (9)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_ao_tcp_32k_END (9)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_i2s_START (10)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_i2s_END (10)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_rffe_ssc_START (11)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_rffe_ssc_END (11)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_spi0_START (12)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_spi0_END (12)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_spi1_START (13)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_sts_spi1_END (13)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_hclk_qspi_qic_START (14)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_hclk_qspi_qic_END (14)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_aupll_media2_START (15)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_aupll_media2_END (15)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_ao_ipc_START (19)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_ao_ipc_END (19)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclkdbg_to_iomcu_START (24)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclkdbg_to_iomcu_END (24)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_noc_aobus2iomcubus_START (25)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_noc_aobus2iomcubus_END (25)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_aclk_hio_START (26)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_aclk_hio_END (26)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_hio_START (27)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_pclk_hio_END (27)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_hio_ulp_START (28)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_hio_ulp_END (28)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_hio_sys_START (29)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_hio_sys_END (29)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_hio_spll_START (30)
#define SOC_AO_CRG_SCPERCLKEN0_SEC_gt_clk_hio_spll_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_timer1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_ao_ipc : 1;
        unsigned int ip_rst_aonoc_pds : 1;
        unsigned int ip_prst_ao_gpio1_se : 1;
        unsigned int ip_rst_aobus : 1;
        unsigned int ip_rst_aonoc : 1;
        unsigned int ip_prst_intr_hub : 1;
        unsigned int ip_rst_sts_spi1 : 1;
        unsigned int ip_rst_sts_spi0 : 1;
        unsigned int ip_rst_sts_rffe_ssc : 1;
        unsigned int ip_rst_sts_i2s : 1;
        unsigned int ip_rst_sts : 1;
        unsigned int ip_rst_hio : 1;
        unsigned int ip_rst_hio_crg : 1;
        unsigned int ip_prst_hio : 1;
        unsigned int ip_arst_hio : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTEN0_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_timer1_START (0)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_timer1_END (0)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_ao_ipc_START (2)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_ao_ipc_END (2)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_aonoc_pds_START (3)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_aonoc_pds_END (3)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_ao_gpio1_se_START (4)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_ao_gpio1_se_END (4)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_aobus_START (5)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_aobus_END (5)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_aonoc_START (6)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_aonoc_END (6)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_intr_hub_START (7)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_intr_hub_END (7)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_spi1_START (8)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_spi1_END (8)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_spi0_START (9)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_spi0_END (9)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_rffe_ssc_START (10)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_rffe_ssc_END (10)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_i2s_START (11)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_i2s_END (11)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_START (12)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_sts_END (12)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_hio_START (13)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_hio_END (13)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_hio_crg_START (14)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_rst_hio_crg_END (14)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_hio_START (15)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_prst_hio_END (15)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_arst_hio_START (16)
#define SOC_AO_CRG_SCPERRSTEN0_SEC_ip_arst_hio_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_timer1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_ao_ipc : 1;
        unsigned int ip_rst_aonoc_pds : 1;
        unsigned int ip_prst_ao_gpio1_se : 1;
        unsigned int ip_rst_aobus : 1;
        unsigned int ip_rst_aonoc : 1;
        unsigned int ip_prst_intr_hub : 1;
        unsigned int ip_rst_sts_spi1 : 1;
        unsigned int ip_rst_sts_spi0 : 1;
        unsigned int ip_rst_sts_rffe_ssc : 1;
        unsigned int ip_rst_sts_i2s : 1;
        unsigned int ip_rst_sts : 1;
        unsigned int ip_rst_hio : 1;
        unsigned int ip_rst_hio_crg : 1;
        unsigned int ip_prst_hio : 1;
        unsigned int ip_arst_hio : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTDIS0_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_timer1_START (0)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_timer1_END (0)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_ao_ipc_START (2)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_ao_ipc_END (2)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_aonoc_pds_START (3)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_aonoc_pds_END (3)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_ao_gpio1_se_START (4)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_ao_gpio1_se_END (4)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_aobus_START (5)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_aobus_END (5)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_aonoc_START (6)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_aonoc_END (6)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_intr_hub_START (7)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_intr_hub_END (7)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_spi1_START (8)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_spi1_END (8)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_spi0_START (9)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_spi0_END (9)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_rffe_ssc_START (10)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_rffe_ssc_END (10)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_i2s_START (11)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_i2s_END (11)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_START (12)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_sts_END (12)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_hio_START (13)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_hio_END (13)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_hio_crg_START (14)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_rst_hio_crg_END (14)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_hio_START (15)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_prst_hio_END (15)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_arst_hio_START (16)
#define SOC_AO_CRG_SCPERRSTDIS0_SEC_ip_arst_hio_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_timer1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_ao_ipc : 1;
        unsigned int ip_rst_aonoc_pds : 1;
        unsigned int ip_prst_ao_gpio1_se : 1;
        unsigned int ip_rst_aobus : 1;
        unsigned int ip_rst_aonoc : 1;
        unsigned int ip_prst_intr_hub : 1;
        unsigned int ip_rst_sts_spi1 : 1;
        unsigned int ip_rst_sts_spi0 : 1;
        unsigned int ip_rst_sts_rffe_ssc : 1;
        unsigned int ip_rst_sts_i2s : 1;
        unsigned int ip_rst_sts : 1;
        unsigned int ip_rst_hio : 1;
        unsigned int ip_rst_hio_crg : 1;
        unsigned int ip_prst_hio : 1;
        unsigned int ip_arst_hio : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTSTAT0_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_timer1_START (0)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_timer1_END (0)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_ao_ipc_START (2)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_ao_ipc_END (2)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_aonoc_pds_START (3)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_aonoc_pds_END (3)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_ao_gpio1_se_START (4)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_ao_gpio1_se_END (4)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_aobus_START (5)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_aobus_END (5)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_aonoc_START (6)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_aonoc_END (6)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_intr_hub_START (7)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_intr_hub_END (7)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_spi1_START (8)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_spi1_END (8)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_spi0_START (9)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_spi0_END (9)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_rffe_ssc_START (10)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_rffe_ssc_END (10)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_i2s_START (11)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_i2s_END (11)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_START (12)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_sts_END (12)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_hio_START (13)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_hio_END (13)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_hio_crg_START (14)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_rst_hio_crg_END (14)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_hio_START (15)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_prst_hio_END (15)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_arst_hio_START (16)
#define SOC_AO_CRG_SCPERRSTSTAT0_SEC_ip_arst_hio_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_asp_subsys : 1;
        unsigned int ip_rst_asp_subsys_crg : 1;
        unsigned int ip_prst_hickm : 1;
        unsigned int ip_rst_sci0 : 1;
        unsigned int ip_rst_sci1 : 1;
        unsigned int ip_prst_timer2 : 1;
        unsigned int ip_prst_timer3 : 1;
        unsigned int ip_prst_timer7 : 1;
        unsigned int ip_prst_rtc1 : 1;
        unsigned int ip_rst_asp_cfg : 1;
        unsigned int ip_rst_mad : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_hisee : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hieps_tee_crg : 1;
        unsigned int ip_rst_hieps_tee : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_qic_hieps_tee : 1;
        unsigned int ip_rst_ao_tcp : 1;
        unsigned int ip_prst_sts_gpio2 : 1;
        unsigned int ip_prst_sts_gpio1 : 1;
        unsigned int ip_prst_sts : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_qic_hieps_ree : 1;
        unsigned int ip_rst_hieps_ree_crg : 1;
        unsigned int ip_rst_hieps_ree : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTEN1_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_asp_subsys_START (0)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_asp_subsys_END (0)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_asp_subsys_crg_START (1)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_asp_subsys_crg_END (1)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_hickm_START (2)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_hickm_END (2)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_sci0_START (3)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_sci0_END (3)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_sci1_START (4)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_sci1_END (4)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_timer2_START (5)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_timer2_END (5)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_timer3_START (6)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_timer3_END (6)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_timer7_START (7)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_timer7_END (7)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_rtc1_START (8)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_rtc1_END (8)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_asp_cfg_START (9)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_asp_cfg_END (9)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_mad_START (10)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_mad_END (10)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hisee_START (12)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hisee_END (12)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_tee_crg_START (14)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_tee_crg_END (14)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_tee_START (15)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_tee_END (15)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_pll_fsm_START (16)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_pll_fsm_END (16)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_qic_hieps_tee_START (17)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_qic_hieps_tee_END (17)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_ao_tcp_START (18)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_ao_tcp_END (18)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_sts_gpio2_START (19)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_sts_gpio2_END (19)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_sts_gpio1_START (20)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_sts_gpio1_END (20)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_sts_START (21)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_prst_sts_END (21)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_qic_hieps_ree_START (29)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_qic_hieps_ree_END (29)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_ree_crg_START (30)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_ree_crg_END (30)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_ree_START (31)
#define SOC_AO_CRG_SCPERRSTEN1_SEC_ip_rst_hieps_ree_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_asp_subsys : 1;
        unsigned int ip_rst_asp_subsys_crg : 1;
        unsigned int ip_prst_hickm : 1;
        unsigned int ip_rst_sci0 : 1;
        unsigned int ip_rst_sci1 : 1;
        unsigned int ip_prst_timer2 : 1;
        unsigned int ip_prst_timer3 : 1;
        unsigned int ip_prst_timer7 : 1;
        unsigned int ip_prst_rtc1 : 1;
        unsigned int ip_rst_asp_cfg : 1;
        unsigned int ip_rst_mad : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_hisee : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hieps_tee_crg : 1;
        unsigned int ip_rst_hieps_tee : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_qic_hieps_tee : 1;
        unsigned int ip_rst_ao_tcp : 1;
        unsigned int ip_prst_sts_gpio2 : 1;
        unsigned int ip_prst_sts_gpio1 : 1;
        unsigned int ip_prst_sts : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_qic_hieps_ree : 1;
        unsigned int ip_rst_hieps_ree_crg : 1;
        unsigned int ip_rst_hieps_ree : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTDIS1_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_asp_subsys_START (0)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_asp_subsys_END (0)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_asp_subsys_crg_START (1)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_asp_subsys_crg_END (1)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_hickm_START (2)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_hickm_END (2)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_sci0_START (3)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_sci0_END (3)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_sci1_START (4)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_sci1_END (4)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_timer2_START (5)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_timer2_END (5)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_timer3_START (6)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_timer3_END (6)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_timer7_START (7)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_timer7_END (7)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_rtc1_START (8)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_rtc1_END (8)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_asp_cfg_START (9)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_asp_cfg_END (9)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_mad_START (10)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_mad_END (10)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hisee_START (12)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hisee_END (12)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_tee_crg_START (14)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_tee_crg_END (14)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_tee_START (15)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_tee_END (15)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_pll_fsm_START (16)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_pll_fsm_END (16)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_qic_hieps_tee_START (17)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_qic_hieps_tee_END (17)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_ao_tcp_START (18)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_ao_tcp_END (18)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_sts_gpio2_START (19)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_sts_gpio2_END (19)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_sts_gpio1_START (20)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_sts_gpio1_END (20)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_sts_START (21)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_prst_sts_END (21)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_qic_hieps_ree_START (29)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_qic_hieps_ree_END (29)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_ree_crg_START (30)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_ree_crg_END (30)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_ree_START (31)
#define SOC_AO_CRG_SCPERRSTDIS1_SEC_ip_rst_hieps_ree_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_asp_subsys : 1;
        unsigned int ip_rst_asp_subsys_crg : 1;
        unsigned int ip_prst_hickm : 1;
        unsigned int ip_rst_sci0 : 1;
        unsigned int ip_rst_sci1 : 1;
        unsigned int ip_prst_timer2 : 1;
        unsigned int ip_prst_timer3 : 1;
        unsigned int ip_prst_timer7 : 1;
        unsigned int ip_prst_rtc1 : 1;
        unsigned int ip_rst_asp_cfg : 1;
        unsigned int ip_rst_mad : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_hisee : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hieps_tee_crg : 1;
        unsigned int ip_rst_hieps_tee : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_qic_hieps_tee : 1;
        unsigned int ip_rst_ao_tcp : 1;
        unsigned int ip_prst_sts_gpio2 : 1;
        unsigned int ip_prst_sts_gpio1 : 1;
        unsigned int ip_prst_sts : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_qic_hieps_ree : 1;
        unsigned int ip_rst_hieps_ree_crg : 1;
        unsigned int ip_rst_hieps_ree : 1;
    } reg;
} SOC_AO_CRG_SCPERRSTSTAT1_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_asp_subsys_START (0)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_asp_subsys_END (0)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_asp_subsys_crg_START (1)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_asp_subsys_crg_END (1)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_hickm_START (2)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_hickm_END (2)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_sci0_START (3)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_sci0_END (3)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_sci1_START (4)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_sci1_END (4)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_timer2_START (5)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_timer2_END (5)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_timer3_START (6)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_timer3_END (6)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_timer7_START (7)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_timer7_END (7)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_rtc1_START (8)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_rtc1_END (8)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_asp_cfg_START (9)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_asp_cfg_END (9)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_mad_START (10)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_mad_END (10)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hisee_START (12)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hisee_END (12)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_tee_crg_START (14)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_tee_crg_END (14)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_tee_START (15)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_tee_END (15)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_pll_fsm_START (16)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_pll_fsm_END (16)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_qic_hieps_tee_START (17)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_qic_hieps_tee_END (17)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_ao_tcp_START (18)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_ao_tcp_END (18)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_sts_gpio2_START (19)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_sts_gpio2_END (19)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_sts_gpio1_START (20)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_sts_gpio1_END (20)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_sts_START (21)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_prst_sts_END (21)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_qic_hieps_ree_START (29)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_qic_hieps_ree_END (29)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_ree_crg_START (30)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_ree_crg_END (30)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_ree_START (31)
#define SOC_AO_CRG_SCPERRSTSTAT1_SEC_ip_rst_hieps_ree_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_iomcu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AO_CRG_SCPERRSTEN2_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTEN2_SEC_ip_rst_iomcu_START (0)
#define SOC_AO_CRG_SCPERRSTEN2_SEC_ip_rst_iomcu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_iomcu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AO_CRG_SCPERRSTDIS2_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTDIS2_SEC_ip_rst_iomcu_START (0)
#define SOC_AO_CRG_SCPERRSTDIS2_SEC_ip_rst_iomcu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_iomcu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AO_CRG_SCPERRSTSTAT2_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERRSTSTAT2_SEC_ip_rst_iomcu_START (0)
#define SOC_AO_CRG_SCPERRSTSTAT2_SEC_ip_rst_iomcu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hickm : 1;
        unsigned int gt_clk_sci0 : 1;
        unsigned int gt_clk_sci1 : 1;
        unsigned int gt_pclk_timer2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_timer3 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer7 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_ref_crc : 1;
        unsigned int gt_pclk_rtc1 : 1;
        unsigned int gt_pclk_ao_wd1 : 1;
        unsigned int gt_pclk_ao_wd : 1;
        unsigned int gt_clk_asp_subsys_lpmcu : 1;
        unsigned int gt_clk_asp_codec_lpm3 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_mad_lpm3 : 1;
        unsigned int gt_pclk_sts_gpio2 : 1;
        unsigned int gt_pclk_sts_gpio1 : 1;
        unsigned int gt_pclk_sts : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 6;
        unsigned int gt_atclk_to_iomcu : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_AO_CRG_SCPEREN3_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_hickm_START (0)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_hickm_END (0)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_sci0_START (1)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_sci0_END (1)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_sci1_START (2)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_sci1_END (2)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_timer2_START (3)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_timer2_END (3)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_timer3_START (5)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_timer3_END (5)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_timer7_START (7)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_timer7_END (7)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_ref_crc_START (9)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_ref_crc_END (9)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_rtc1_START (10)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_rtc1_END (10)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_ao_wd1_START (11)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_ao_wd1_END (11)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_ao_wd_START (12)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_ao_wd_END (12)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_asp_subsys_lpmcu_START (13)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_asp_subsys_lpmcu_END (13)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_asp_codec_lpm3_START (14)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_asp_codec_lpm3_END (14)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_mad_lpm3_START (16)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_clk_mad_lpm3_END (16)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_sts_gpio2_START (17)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_sts_gpio2_END (17)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_sts_gpio1_START (18)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_sts_gpio1_END (18)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_sts_START (19)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_pclk_sts_END (19)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_atclk_to_iomcu_START (27)
#define SOC_AO_CRG_SCPEREN3_SEC_gt_atclk_to_iomcu_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hickm : 1;
        unsigned int gt_clk_sci0 : 1;
        unsigned int gt_clk_sci1 : 1;
        unsigned int gt_pclk_timer2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_timer3 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer7 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_ref_crc : 1;
        unsigned int gt_pclk_rtc1 : 1;
        unsigned int gt_pclk_ao_wd1 : 1;
        unsigned int gt_pclk_ao_wd : 1;
        unsigned int gt_clk_asp_subsys_lpmcu : 1;
        unsigned int gt_clk_asp_codec_lpm3 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_mad_lpm3 : 1;
        unsigned int gt_pclk_sts_gpio2 : 1;
        unsigned int gt_pclk_sts_gpio1 : 1;
        unsigned int gt_pclk_sts : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 6;
        unsigned int gt_atclk_to_iomcu : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS3_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_hickm_START (0)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_hickm_END (0)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_sci0_START (1)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_sci0_END (1)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_sci1_START (2)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_sci1_END (2)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_timer2_START (3)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_timer2_END (3)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_timer3_START (5)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_timer3_END (5)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_timer7_START (7)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_timer7_END (7)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_ref_crc_START (9)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_ref_crc_END (9)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_rtc1_START (10)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_rtc1_END (10)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_ao_wd1_START (11)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_ao_wd1_END (11)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_ao_wd_START (12)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_ao_wd_END (12)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_asp_subsys_lpmcu_START (13)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_asp_subsys_lpmcu_END (13)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_asp_codec_lpm3_START (14)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_asp_codec_lpm3_END (14)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_mad_lpm3_START (16)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_clk_mad_lpm3_END (16)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_sts_gpio2_START (17)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_sts_gpio2_END (17)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_sts_gpio1_START (18)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_sts_gpio1_END (18)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_sts_START (19)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_pclk_sts_END (19)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_atclk_to_iomcu_START (27)
#define SOC_AO_CRG_SCPERDIS3_SEC_gt_atclk_to_iomcu_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hickm : 1;
        unsigned int gt_clk_sci0 : 1;
        unsigned int gt_clk_sci1 : 1;
        unsigned int gt_pclk_timer2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_timer3 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_timer7 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_ref_crc : 1;
        unsigned int gt_pclk_rtc1 : 1;
        unsigned int gt_pclk_ao_wd1 : 1;
        unsigned int gt_pclk_ao_wd : 1;
        unsigned int gt_clk_asp_subsys_lpmcu : 1;
        unsigned int gt_clk_asp_codec_lpm3 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_mad_lpm3 : 1;
        unsigned int gt_pclk_sts_gpio2 : 1;
        unsigned int gt_pclk_sts_gpio1 : 1;
        unsigned int gt_pclk_sts : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 6;
        unsigned int gt_atclk_to_iomcu : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN3_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_hickm_START (0)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_hickm_END (0)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_sci0_START (1)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_sci0_END (1)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_sci1_START (2)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_sci1_END (2)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_timer2_START (3)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_timer2_END (3)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_timer3_START (5)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_timer3_END (5)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_timer7_START (7)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_timer7_END (7)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_ref_crc_START (9)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_ref_crc_END (9)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_rtc1_START (10)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_rtc1_END (10)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_ao_wd1_START (11)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_ao_wd1_END (11)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_ao_wd_START (12)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_ao_wd_END (12)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_asp_subsys_lpmcu_START (13)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_asp_subsys_lpmcu_END (13)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_asp_codec_lpm3_START (14)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_asp_codec_lpm3_END (14)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_mad_lpm3_START (16)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_clk_mad_lpm3_END (16)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_sts_gpio2_START (17)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_sts_gpio2_END (17)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_sts_gpio1_START (18)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_sts_gpio1_END (18)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_sts_START (19)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_pclk_sts_END (19)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_atclk_to_iomcu_START (27)
#define SOC_AO_CRG_SCPERCLKEN3_SEC_gt_atclk_to_iomcu_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_atclk_to_ao : 1;
        unsigned int gt_clk_qic_spi11dma : 1;
        unsigned int gt_clk_spi11dma : 1;
        unsigned int gt_clk_hieps_tee : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_hieps_tcxo : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hisee_pll : 1;
        unsigned int gt_clk_hieps_ree : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_hisee_ref : 1;
        unsigned int gt_clk_qic_spidma : 1;
        unsigned int gt_clk_spll_sscg : 1;
        unsigned int gt_clk_aobus : 1;
        unsigned int gt_clk_aonoc2mspcbus : 1;
        unsigned int gt_clk_noc_aobus2sysbusddrc : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_timerclk_refh : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_clk_fll_src_peri : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_AO_CRG_SCPEREN4_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPEREN4_SEC_gt_atclk_to_ao_START (0)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_atclk_to_ao_END (0)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_qic_spi11dma_START (1)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_qic_spi11dma_END (1)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_spi11dma_START (2)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_spi11dma_END (2)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hieps_tee_START (3)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hieps_tee_END (3)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hieps_tcxo_START (5)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hieps_tcxo_END (5)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hisee_pll_START (7)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hisee_pll_END (7)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hieps_ree_START (8)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hieps_ree_END (8)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hisee_ref_START (10)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_hisee_ref_END (10)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_qic_spidma_START (11)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_qic_spidma_END (11)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_spll_sscg_START (12)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_spll_sscg_END (12)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_aobus_START (13)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_aobus_END (13)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_aonoc2mspcbus_START (14)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_aonoc2mspcbus_END (14)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_noc_aobus2sysbusddrc_START (15)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_noc_aobus2sysbusddrc_END (15)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_timerclk_refh_START (18)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_timerclk_refh_END (18)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_pll_fsm_START (19)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_pll_fsm_END (19)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_fll_src_peri_START (20)
#define SOC_AO_CRG_SCPEREN4_SEC_gt_clk_fll_src_peri_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_atclk_to_ao : 1;
        unsigned int gt_clk_qic_spi11dma : 1;
        unsigned int gt_clk_spi11dma : 1;
        unsigned int gt_clk_hieps_tee : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_hieps_tcxo : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hisee_pll : 1;
        unsigned int gt_clk_hieps_ree : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_hisee_ref : 1;
        unsigned int gt_clk_qic_spidma : 1;
        unsigned int gt_clk_spll_sscg : 1;
        unsigned int gt_clk_aobus : 1;
        unsigned int gt_clk_aonoc2mspcbus : 1;
        unsigned int gt_clk_noc_aobus2sysbusddrc : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_timerclk_refh : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_clk_fll_src_peri : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_AO_CRG_SCPERDIS4_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_atclk_to_ao_START (0)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_atclk_to_ao_END (0)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_qic_spi11dma_START (1)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_qic_spi11dma_END (1)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_spi11dma_START (2)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_spi11dma_END (2)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hieps_tee_START (3)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hieps_tee_END (3)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hieps_tcxo_START (5)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hieps_tcxo_END (5)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hisee_pll_START (7)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hisee_pll_END (7)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hieps_ree_START (8)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hieps_ree_END (8)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hisee_ref_START (10)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_hisee_ref_END (10)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_qic_spidma_START (11)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_qic_spidma_END (11)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_spll_sscg_START (12)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_spll_sscg_END (12)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_aobus_START (13)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_aobus_END (13)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_aonoc2mspcbus_START (14)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_aonoc2mspcbus_END (14)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_noc_aobus2sysbusddrc_START (15)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_noc_aobus2sysbusddrc_END (15)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_timerclk_refh_START (18)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_timerclk_refh_END (18)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_pll_fsm_START (19)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_pll_fsm_END (19)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_fll_src_peri_START (20)
#define SOC_AO_CRG_SCPERDIS4_SEC_gt_clk_fll_src_peri_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_atclk_to_ao : 1;
        unsigned int gt_clk_qic_spi11dma : 1;
        unsigned int gt_clk_spi11dma : 1;
        unsigned int gt_clk_hieps_tee : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_hieps_tcxo : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hisee_pll : 1;
        unsigned int gt_clk_hieps_ree : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_hisee_ref : 1;
        unsigned int gt_clk_qic_spidma : 1;
        unsigned int gt_clk_spll_sscg : 1;
        unsigned int gt_clk_aobus : 1;
        unsigned int gt_clk_aonoc2mspcbus : 1;
        unsigned int gt_clk_noc_aobus2sysbusddrc : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_timerclk_refh : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_clk_fll_src_peri : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_AO_CRG_SCPERCLKEN4_SEC_UNION;
#endif
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_atclk_to_ao_START (0)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_atclk_to_ao_END (0)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_qic_spi11dma_START (1)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_qic_spi11dma_END (1)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_spi11dma_START (2)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_spi11dma_END (2)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hieps_tee_START (3)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hieps_tee_END (3)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hieps_tcxo_START (5)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hieps_tcxo_END (5)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hisee_pll_START (7)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hisee_pll_END (7)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hieps_ree_START (8)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hieps_ree_END (8)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hisee_ref_START (10)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_hisee_ref_END (10)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_qic_spidma_START (11)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_qic_spidma_END (11)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_spll_sscg_START (12)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_spll_sscg_END (12)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_aobus_START (13)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_aobus_END (13)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_aonoc2mspcbus_START (14)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_aonoc2mspcbus_END (14)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_noc_aobus2sysbusddrc_START (15)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_noc_aobus2sysbusddrc_END (15)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_timerclk_refh_START (18)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_timerclk_refh_END (18)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_pll_fsm_START (19)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_pll_fsm_END (19)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_fll_src_peri_START (20)
#define SOC_AO_CRG_SCPERCLKEN4_SEC_gt_clk_fll_src_peri_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_aobus : 4;
        unsigned int div_iomcu_fll : 2;
        unsigned int sc_gt_clk_sci : 1;
        unsigned int timer_secu_en : 1;
        unsigned int sc_gt_clk_iomcu_fll : 1;
        unsigned int sc_gt_clk_iomcu_pll : 1;
        unsigned int iomcu_fll_gt_mode : 1;
        unsigned int ulppll_sleep_en_mode : 1;
        unsigned int ulppll_sleep_en_soft : 1;
        unsigned int div_sci : 2;
        unsigned int sel_sci : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV0_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV0_SEC_div_aobus_START (0)
#define SOC_AO_CRG_SCCLKDIV0_SEC_div_aobus_END (3)
#define SOC_AO_CRG_SCCLKDIV0_SEC_div_iomcu_fll_START (4)
#define SOC_AO_CRG_SCCLKDIV0_SEC_div_iomcu_fll_END (5)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sc_gt_clk_sci_START (6)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sc_gt_clk_sci_END (6)
#define SOC_AO_CRG_SCCLKDIV0_SEC_timer_secu_en_START (7)
#define SOC_AO_CRG_SCCLKDIV0_SEC_timer_secu_en_END (7)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sc_gt_clk_iomcu_fll_START (8)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sc_gt_clk_iomcu_fll_END (8)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sc_gt_clk_iomcu_pll_START (9)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sc_gt_clk_iomcu_pll_END (9)
#define SOC_AO_CRG_SCCLKDIV0_SEC_iomcu_fll_gt_mode_START (10)
#define SOC_AO_CRG_SCCLKDIV0_SEC_iomcu_fll_gt_mode_END (10)
#define SOC_AO_CRG_SCCLKDIV0_SEC_ulppll_sleep_en_mode_START (11)
#define SOC_AO_CRG_SCCLKDIV0_SEC_ulppll_sleep_en_mode_END (11)
#define SOC_AO_CRG_SCCLKDIV0_SEC_ulppll_sleep_en_soft_START (12)
#define SOC_AO_CRG_SCCLKDIV0_SEC_ulppll_sleep_en_soft_END (12)
#define SOC_AO_CRG_SCCLKDIV0_SEC_div_sci_START (13)
#define SOC_AO_CRG_SCCLKDIV0_SEC_div_sci_END (14)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sel_sci_START (15)
#define SOC_AO_CRG_SCCLKDIV0_SEC_sel_sci_END (15)
#define SOC_AO_CRG_SCCLKDIV0_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV0_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int sel_clk_iomcu_fll_src : 1;
        unsigned int div_hisee_pll : 6;
        unsigned int sc_gt_clk_hisee_pll : 1;
        unsigned int reserved_1 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV1_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV1_SEC_sel_clk_iomcu_fll_src_START (4)
#define SOC_AO_CRG_SCCLKDIV1_SEC_sel_clk_iomcu_fll_src_END (4)
#define SOC_AO_CRG_SCCLKDIV1_SEC_div_hisee_pll_START (5)
#define SOC_AO_CRG_SCCLKDIV1_SEC_div_hisee_pll_END (10)
#define SOC_AO_CRG_SCCLKDIV1_SEC_sc_gt_clk_hisee_pll_START (11)
#define SOC_AO_CRG_SCCLKDIV1_SEC_sc_gt_clk_hisee_pll_END (11)
#define SOC_AO_CRG_SCCLKDIV1_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV1_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_hieps_tee : 1;
        unsigned int div_hieps_tee : 6;
        unsigned int sc_gt_aonoc_pll : 1;
        unsigned int div_aonoc_div : 6;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV2_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV2_SEC_sc_gt_clk_hieps_tee_START (0)
#define SOC_AO_CRG_SCCLKDIV2_SEC_sc_gt_clk_hieps_tee_END (0)
#define SOC_AO_CRG_SCCLKDIV2_SEC_div_hieps_tee_START (1)
#define SOC_AO_CRG_SCCLKDIV2_SEC_div_hieps_tee_END (6)
#define SOC_AO_CRG_SCCLKDIV2_SEC_sc_gt_aonoc_pll_START (7)
#define SOC_AO_CRG_SCCLKDIV2_SEC_sc_gt_aonoc_pll_END (7)
#define SOC_AO_CRG_SCCLKDIV2_SEC_div_aonoc_div_START (8)
#define SOC_AO_CRG_SCCLKDIV2_SEC_div_aonoc_div_END (13)
#define SOC_AO_CRG_SCCLKDIV2_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV2_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aobusnoc_pll_div_auto_cfg : 6;
        unsigned int reserved_0 : 4;
        unsigned int sc_gt_clk_aobus : 1;
        unsigned int reserved_1 : 1;
        unsigned int sc_gt_aonoc_fll : 1;
        unsigned int aonoc_clk_sw_req_cfg : 2;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV3_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV3_SEC_aobusnoc_pll_div_auto_cfg_START (0)
#define SOC_AO_CRG_SCCLKDIV3_SEC_aobusnoc_pll_div_auto_cfg_END (5)
#define SOC_AO_CRG_SCCLKDIV3_SEC_sc_gt_clk_aobus_START (10)
#define SOC_AO_CRG_SCCLKDIV3_SEC_sc_gt_clk_aobus_END (10)
#define SOC_AO_CRG_SCCLKDIV3_SEC_sc_gt_aonoc_fll_START (12)
#define SOC_AO_CRG_SCCLKDIV3_SEC_sc_gt_aonoc_fll_END (12)
#define SOC_AO_CRG_SCCLKDIV3_SEC_aonoc_clk_sw_req_cfg_START (13)
#define SOC_AO_CRG_SCCLKDIV3_SEC_aonoc_clk_sw_req_cfg_END (14)
#define SOC_AO_CRG_SCCLKDIV3_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV3_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aobusnoc_auto_waitcfg_out : 10;
        unsigned int aobusnoc_fll_div_auto_cfg : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV4_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV4_SEC_aobusnoc_auto_waitcfg_out_START (0)
#define SOC_AO_CRG_SCCLKDIV4_SEC_aobusnoc_auto_waitcfg_out_END (9)
#define SOC_AO_CRG_SCCLKDIV4_SEC_aobusnoc_fll_div_auto_cfg_START (10)
#define SOC_AO_CRG_SCCLKDIV4_SEC_aobusnoc_fll_div_auto_cfg_END (15)
#define SOC_AO_CRG_SCCLKDIV4_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV4_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aobusnoc_div_auto_reduce_bypass : 1;
        unsigned int aobusnoc_auto_waitcfg_in : 10;
        unsigned int aobus_clk_sw_req_cfg : 2;
        unsigned int sc_gt_clk_aobus_fll_bypass : 1;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV5_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV5_SEC_aobusnoc_div_auto_reduce_bypass_START (0)
#define SOC_AO_CRG_SCCLKDIV5_SEC_aobusnoc_div_auto_reduce_bypass_END (0)
#define SOC_AO_CRG_SCCLKDIV5_SEC_aobusnoc_auto_waitcfg_in_START (1)
#define SOC_AO_CRG_SCCLKDIV5_SEC_aobusnoc_auto_waitcfg_in_END (10)
#define SOC_AO_CRG_SCCLKDIV5_SEC_aobus_clk_sw_req_cfg_START (11)
#define SOC_AO_CRG_SCCLKDIV5_SEC_aobus_clk_sw_req_cfg_END (12)
#define SOC_AO_CRG_SCCLKDIV5_SEC_sc_gt_clk_aobus_fll_bypass_START (13)
#define SOC_AO_CRG_SCCLKDIV5_SEC_sc_gt_clk_aobus_fll_bypass_END (13)
#define SOC_AO_CRG_SCCLKDIV5_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV5_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 4;
        unsigned int sel_noc_timeout_extref : 1;
        unsigned int div_noc_timeout_extref : 6;
        unsigned int div_aobus_fll : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV6_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV6_SEC_sel_noc_timeout_extref_START (4)
#define SOC_AO_CRG_SCCLKDIV6_SEC_sel_noc_timeout_extref_END (4)
#define SOC_AO_CRG_SCCLKDIV6_SEC_div_noc_timeout_extref_START (5)
#define SOC_AO_CRG_SCCLKDIV6_SEC_div_noc_timeout_extref_END (10)
#define SOC_AO_CRG_SCCLKDIV6_SEC_div_aobus_fll_START (11)
#define SOC_AO_CRG_SCCLKDIV6_SEC_div_aobus_fll_END (15)
#define SOC_AO_CRG_SCCLKDIV6_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV6_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aupll_en_vote : 5;
        unsigned int aupll_bypass_vote : 5;
        unsigned int aupll_gt_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV7_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV7_SEC_aupll_en_vote_START (0)
#define SOC_AO_CRG_SCCLKDIV7_SEC_aupll_en_vote_END (4)
#define SOC_AO_CRG_SCCLKDIV7_SEC_aupll_bypass_vote_START (5)
#define SOC_AO_CRG_SCCLKDIV7_SEC_aupll_bypass_vote_END (9)
#define SOC_AO_CRG_SCCLKDIV7_SEC_aupll_gt_vote_START (10)
#define SOC_AO_CRG_SCCLKDIV7_SEC_aupll_gt_vote_END (14)
#define SOC_AO_CRG_SCCLKDIV7_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV7_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_aonoc_fll : 6;
        unsigned int div_hio_ulp : 2;
        unsigned int sel_clk_hio_ulp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV8_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV8_SEC_div_aonoc_fll_START (0)
#define SOC_AO_CRG_SCCLKDIV8_SEC_div_aonoc_fll_END (5)
#define SOC_AO_CRG_SCCLKDIV8_SEC_div_hio_ulp_START (6)
#define SOC_AO_CRG_SCCLKDIV8_SEC_div_hio_ulp_END (7)
#define SOC_AO_CRG_SCCLKDIV8_SEC_sel_clk_hio_ulp_START (8)
#define SOC_AO_CRG_SCCLKDIV8_SEC_sel_clk_hio_ulp_END (8)
#define SOC_AO_CRG_SCCLKDIV8_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV8_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_clk_pll_fsm : 6;
        unsigned int sc_gt_clk_pll_fsm : 1;
        unsigned int div_clk_ao_332m : 3;
        unsigned int ulppll_lp_gt_en : 1;
        unsigned int ulppll1_gt_lp_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV9_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV9_SEC_div_clk_pll_fsm_START (0)
#define SOC_AO_CRG_SCCLKDIV9_SEC_div_clk_pll_fsm_END (5)
#define SOC_AO_CRG_SCCLKDIV9_SEC_sc_gt_clk_pll_fsm_START (6)
#define SOC_AO_CRG_SCCLKDIV9_SEC_sc_gt_clk_pll_fsm_END (6)
#define SOC_AO_CRG_SCCLKDIV9_SEC_div_clk_ao_332m_START (7)
#define SOC_AO_CRG_SCCLKDIV9_SEC_div_clk_ao_332m_END (9)
#define SOC_AO_CRG_SCCLKDIV9_SEC_ulppll_lp_gt_en_START (10)
#define SOC_AO_CRG_SCCLKDIV9_SEC_ulppll_lp_gt_en_END (10)
#define SOC_AO_CRG_SCCLKDIV9_SEC_ulppll1_gt_lp_en_START (11)
#define SOC_AO_CRG_SCCLKDIV9_SEC_ulppll1_gt_lp_en_END (11)
#define SOC_AO_CRG_SCCLKDIV9_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV9_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_timer : 6;
        unsigned int sc_gt_clk_timer : 1;
        unsigned int sc_sel_clk_timer : 1;
        unsigned int sc_gt_clk_sys_ulppll_gt : 1;
        unsigned int sel_sys_ulppll : 1;
        unsigned int div_sys_ulppll : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV10_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV10_SEC_div_timer_START (0)
#define SOC_AO_CRG_SCCLKDIV10_SEC_div_timer_END (5)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sc_gt_clk_timer_START (6)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sc_gt_clk_timer_END (6)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sc_sel_clk_timer_START (7)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sc_sel_clk_timer_END (7)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sc_gt_clk_sys_ulppll_gt_START (8)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sc_gt_clk_sys_ulppll_gt_END (8)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sel_sys_ulppll_START (9)
#define SOC_AO_CRG_SCCLKDIV10_SEC_sel_sys_ulppll_END (9)
#define SOC_AO_CRG_SCCLKDIV10_SEC_div_sys_ulppll_START (10)
#define SOC_AO_CRG_SCCLKDIV10_SEC_div_sys_ulppll_END (15)
#define SOC_AO_CRG_SCCLKDIV10_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV10_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hieps_ree : 6;
        unsigned int sc_gt_clk_hieps_ree : 1;
        unsigned int div_sts_spi_fll : 5;
        unsigned int div_sts_i2s : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV11_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV11_SEC_div_hieps_ree_START (0)
#define SOC_AO_CRG_SCCLKDIV11_SEC_div_hieps_ree_END (5)
#define SOC_AO_CRG_SCCLKDIV11_SEC_sc_gt_clk_hieps_ree_START (6)
#define SOC_AO_CRG_SCCLKDIV11_SEC_sc_gt_clk_hieps_ree_END (6)
#define SOC_AO_CRG_SCCLKDIV11_SEC_div_sts_spi_fll_START (7)
#define SOC_AO_CRG_SCCLKDIV11_SEC_div_sts_spi_fll_END (11)
#define SOC_AO_CRG_SCCLKDIV11_SEC_div_sts_i2s_START (12)
#define SOC_AO_CRG_SCCLKDIV11_SEC_div_sts_i2s_END (15)
#define SOC_AO_CRG_SCCLKDIV11_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV11_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_sts_spll : 5;
        unsigned int div_sts_spi : 4;
        unsigned int div_sts_fll : 5;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV12_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV12_SEC_div_sts_spll_START (0)
#define SOC_AO_CRG_SCCLKDIV12_SEC_div_sts_spll_END (4)
#define SOC_AO_CRG_SCCLKDIV12_SEC_div_sts_spi_START (5)
#define SOC_AO_CRG_SCCLKDIV12_SEC_div_sts_spi_END (8)
#define SOC_AO_CRG_SCCLKDIV12_SEC_div_sts_fll_START (9)
#define SOC_AO_CRG_SCCLKDIV12_SEC_div_sts_fll_END (13)
#define SOC_AO_CRG_SCCLKDIV12_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV12_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_sts_rffe_ssc : 4;
        unsigned int sc_gt_clk_sts_gt : 1;
        unsigned int sc_gt_clk_sts_rffe_ssc_gt : 1;
        unsigned int sc_gt_clk_sts_spi_gt : 1;
        unsigned int sc_gt_clk_sts_fll_gt : 1;
        unsigned int sc_gt_clk_sts_i2s_gt : 1;
        unsigned int sc_gt_clk_sts_spi_fll_gt : 1;
        unsigned int sel_clk_sts_spi : 1;
        unsigned int sel_clk_sts : 1;
        unsigned int sel_suspend_ao2syscache_aonoc_inuse : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV13_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV13_SEC_div_sts_rffe_ssc_START (0)
#define SOC_AO_CRG_SCCLKDIV13_SEC_div_sts_rffe_ssc_END (3)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_gt_START (4)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_gt_END (4)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_rffe_ssc_gt_START (5)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_rffe_ssc_gt_END (5)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_spi_gt_START (6)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_spi_gt_END (6)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_fll_gt_START (7)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_fll_gt_END (7)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_i2s_gt_START (8)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_i2s_gt_END (8)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_spi_fll_gt_START (9)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sc_gt_clk_sts_spi_fll_gt_END (9)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sel_clk_sts_spi_START (10)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sel_clk_sts_spi_END (10)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sel_clk_sts_START (11)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sel_clk_sts_END (11)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sel_suspend_ao2syscache_aonoc_inuse_START (12)
#define SOC_AO_CRG_SCCLKDIV13_SEC_sel_suspend_ao2syscache_aonoc_inuse_END (12)
#define SOC_AO_CRG_SCCLKDIV13_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV13_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll1_sleep_en_mode : 1;
        unsigned int ulppll1_sleep_en_soft : 1;
        unsigned int iomcu_fll_1_gt_mode : 1;
        unsigned int iomcu_fll_1_gt_enable : 1;
        unsigned int iomcu_fll_gt_enable : 1;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCCLKDIV14_SEC_UNION;
#endif
#define SOC_AO_CRG_SCCLKDIV14_SEC_ulppll1_sleep_en_mode_START (0)
#define SOC_AO_CRG_SCCLKDIV14_SEC_ulppll1_sleep_en_mode_END (0)
#define SOC_AO_CRG_SCCLKDIV14_SEC_ulppll1_sleep_en_soft_START (1)
#define SOC_AO_CRG_SCCLKDIV14_SEC_ulppll1_sleep_en_soft_END (1)
#define SOC_AO_CRG_SCCLKDIV14_SEC_iomcu_fll_1_gt_mode_START (2)
#define SOC_AO_CRG_SCCLKDIV14_SEC_iomcu_fll_1_gt_mode_END (2)
#define SOC_AO_CRG_SCCLKDIV14_SEC_iomcu_fll_1_gt_enable_START (3)
#define SOC_AO_CRG_SCCLKDIV14_SEC_iomcu_fll_1_gt_enable_END (3)
#define SOC_AO_CRG_SCCLKDIV14_SEC_iomcu_fll_gt_enable_START (4)
#define SOC_AO_CRG_SCCLKDIV14_SEC_iomcu_fll_gt_enable_END (4)
#define SOC_AO_CRG_SCCLKDIV14_SEC_bitmasken_START (16)
#define SOC_AO_CRG_SCCLKDIV14_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtc_clkrst_bypass : 1;
        unsigned int rtc1_clkrst_bypass : 1;
        unsigned int timer0_clkrst_bypass : 1;
        unsigned int timer1_clkrst_bypass : 1;
        unsigned int timer2_clkrst_bypass : 1;
        unsigned int timer3_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int sts_gpio2_clkrst_bypass : 1;
        unsigned int sts_gpio1_clkrst_bypass : 1;
        unsigned int sts_clkrst_bypass : 1;
        unsigned int blpwm0_clkrst_bypass : 1;
        unsigned int spmi1_clkrst_bypass : 1;
        unsigned int ioc_clkrst_bypass : 1;
        unsigned int syscnt_clkrst_bypass : 1;
        unsigned int sci0_clkrst_bypass : 1;
        unsigned int sci1_clkrst_bypass : 1;
        unsigned int bbpdrx_clkrst_bypass : 1;
        unsigned int qspi_clkrst_bypass : 1;
        unsigned int timer4_clkrst_bypass : 1;
        unsigned int timer5_clkrst_bypass : 1;
        unsigned int timer6_clkrst_bypass : 1;
        unsigned int timer7_clkrst_bypass : 1;
        unsigned int timer8_clkrst_bypass : 1;
        unsigned int hiphyio_clkrst_bypass : 1;
        unsigned int spi11dma_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int gpio1_se_clkrst_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int em_sync_top_clkrst_bypass : 1;
        unsigned int ao_loadmonitor_clkrst_bypass : 1;
        unsigned int spmi_clkrst_bypass : 1;
        unsigned int ao_tzpc_clkrst_bypass : 1;
    } reg;
} SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_UNION;
#endif
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_rtc_clkrst_bypass_START (0)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_rtc_clkrst_bypass_END (0)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_rtc1_clkrst_bypass_START (1)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_rtc1_clkrst_bypass_END (1)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer0_clkrst_bypass_START (2)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer0_clkrst_bypass_END (2)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer1_clkrst_bypass_START (3)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer1_clkrst_bypass_END (3)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer2_clkrst_bypass_START (4)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer2_clkrst_bypass_END (4)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer3_clkrst_bypass_START (5)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer3_clkrst_bypass_END (5)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sts_gpio2_clkrst_bypass_START (7)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sts_gpio2_clkrst_bypass_END (7)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sts_gpio1_clkrst_bypass_START (8)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sts_gpio1_clkrst_bypass_END (8)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sts_clkrst_bypass_START (9)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sts_clkrst_bypass_END (9)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_blpwm0_clkrst_bypass_START (10)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_blpwm0_clkrst_bypass_END (10)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_spmi1_clkrst_bypass_START (11)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_spmi1_clkrst_bypass_END (11)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ioc_clkrst_bypass_START (12)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ioc_clkrst_bypass_END (12)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_syscnt_clkrst_bypass_START (13)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_syscnt_clkrst_bypass_END (13)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sci0_clkrst_bypass_START (14)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sci0_clkrst_bypass_END (14)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sci1_clkrst_bypass_START (15)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_sci1_clkrst_bypass_END (15)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_bbpdrx_clkrst_bypass_START (16)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_bbpdrx_clkrst_bypass_END (16)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_qspi_clkrst_bypass_START (17)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_qspi_clkrst_bypass_END (17)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer4_clkrst_bypass_START (18)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer4_clkrst_bypass_END (18)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer5_clkrst_bypass_START (19)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer5_clkrst_bypass_END (19)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer6_clkrst_bypass_START (20)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer6_clkrst_bypass_END (20)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer7_clkrst_bypass_START (21)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer7_clkrst_bypass_END (21)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer8_clkrst_bypass_START (22)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_timer8_clkrst_bypass_END (22)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_hiphyio_clkrst_bypass_START (23)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_hiphyio_clkrst_bypass_END (23)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_spi11dma_clkrst_bypass_START (24)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_spi11dma_clkrst_bypass_END (24)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_gpio1_se_clkrst_bypass_START (26)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_gpio1_se_clkrst_bypass_END (26)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_em_sync_top_clkrst_bypass_START (28)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_em_sync_top_clkrst_bypass_END (28)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ao_loadmonitor_clkrst_bypass_START (29)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ao_loadmonitor_clkrst_bypass_END (29)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_spmi_clkrst_bypass_START (30)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_spmi_clkrst_bypass_END (30)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ao_tzpc_clkrst_bypass_START (31)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS0_SEC_ao_tzpc_clkrst_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_ipc_clkrst_bypass : 1;
        unsigned int ao_ipc_ns_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int spi3_clkrst_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ao_wd_clkrst_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ao_tcp_clkrst_bypass : 1;
        unsigned int timer17_clkrst_bypass : 1;
        unsigned int timer16_clkrst_bypass : 1;
        unsigned int timer15_clkrst_bypass : 1;
        unsigned int timer14_clkrst_bypass : 1;
        unsigned int timer13_clkrst_bypass : 1;
        unsigned int spi5_clkrst_bypass : 1;
        unsigned int ao_wd1_clkrst_bypass : 1;
        unsigned int reserved_7 : 1;
        unsigned int blpwm2_clkrst_bypass : 1;
        unsigned int intr_hub_clkrst_bypass : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int efusec_clkrst_bypass : 1;
        unsigned int efusec2_clkrst_bypass : 1;
        unsigned int hickm_clkrst_bypass : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_UNION;
#endif
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_ipc_clkrst_bypass_START (0)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_ipc_clkrst_bypass_END (0)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_ipc_ns_clkrst_bypass_START (1)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_ipc_ns_clkrst_bypass_END (1)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_spi3_clkrst_bypass_START (4)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_spi3_clkrst_bypass_END (4)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_wd_clkrst_bypass_START (7)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_wd_clkrst_bypass_END (7)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_tcp_clkrst_bypass_START (11)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_tcp_clkrst_bypass_END (11)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer17_clkrst_bypass_START (12)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer17_clkrst_bypass_END (12)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer16_clkrst_bypass_START (13)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer16_clkrst_bypass_END (13)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer15_clkrst_bypass_START (14)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer15_clkrst_bypass_END (14)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer14_clkrst_bypass_START (15)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer14_clkrst_bypass_END (15)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer13_clkrst_bypass_START (16)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_timer13_clkrst_bypass_END (16)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_spi5_clkrst_bypass_START (17)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_spi5_clkrst_bypass_END (17)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_wd1_clkrst_bypass_START (18)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_ao_wd1_clkrst_bypass_END (18)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_blpwm2_clkrst_bypass_START (20)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_blpwm2_clkrst_bypass_END (20)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_intr_hub_clkrst_bypass_START (21)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_intr_hub_clkrst_bypass_END (21)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_efusec_clkrst_bypass_START (25)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_efusec_clkrst_bypass_END (25)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_efusec2_clkrst_bypass_START (26)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_efusec2_clkrst_bypass_END (26)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_hickm_clkrst_bypass_START (27)
#define SOC_AO_CRG_SC_IPCLKRST_BYPASS1_SEC_hickm_clkrst_bypass_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_hieps_tee : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_hieps_tcxo : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_hieps_ree : 1;
        unsigned int st_hclk_qspi_qic : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_hisee_pll : 1;
        unsigned int st_clk_sts_rffe_ssc : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_clk_hisee_ref : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_clk_aonoc2mspcbus : 1;
        unsigned int reserved_6 : 18;
    } reg;
} SOC_AO_CRG_SC_CLK_STAT0_SEC_UNION;
#endif
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hieps_tee_START (0)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hieps_tee_END (0)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hieps_tcxo_START (2)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hieps_tcxo_END (2)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hieps_ree_START (4)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hieps_ree_END (4)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_hclk_qspi_qic_START (5)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_hclk_qspi_qic_END (5)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hisee_pll_START (8)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hisee_pll_END (8)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_sts_rffe_ssc_START (9)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_sts_rffe_ssc_END (9)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hisee_ref_START (11)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_hisee_ref_END (11)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_aonoc2mspcbus_START (13)
#define SOC_AO_CRG_SC_CLK_STAT0_SEC_st_clk_aonoc2mspcbus_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_ack_clk_hieps_tee_sw : 2;
        unsigned int swdone_clk_hieps_tee_div : 1;
        unsigned int sw_ack_clk_hisee_sw : 2;
        unsigned int sw_ack_clk_hieps_ree_sw : 2;
        unsigned int swdone_clk_hieps_ree_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_AO_CRG_SC_CLK_STAT1_SEC_UNION;
#endif
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_sw_ack_clk_hieps_tee_sw_START (0)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_sw_ack_clk_hieps_tee_sw_END (1)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_swdone_clk_hieps_tee_div_START (2)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_swdone_clk_hieps_tee_div_END (2)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_sw_ack_clk_hisee_sw_START (3)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_sw_ack_clk_hisee_sw_END (4)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_sw_ack_clk_hieps_ree_sw_START (5)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_sw_ack_clk_hieps_ree_sw_END (6)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_swdone_clk_hieps_ree_div_START (7)
#define SOC_AO_CRG_SC_CLK_STAT1_SEC_swdone_clk_hieps_ree_div_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aupll_fsm_en : 1;
        unsigned int aupll_vote_mode_sel : 1;
        unsigned int aupll_intr_clr : 1;
        unsigned int spll_fsm_en : 1;
        unsigned int spll_vote_mode_sel : 1;
        unsigned int spll_intr_clr : 1;
        unsigned int reserved : 10;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_PLL_FSM_CTRL0_SEC_UNION;
#endif
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_aupll_fsm_en_START (0)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_aupll_fsm_en_END (0)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_aupll_vote_mode_sel_START (1)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_aupll_vote_mode_sel_END (1)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_aupll_intr_clr_START (2)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_aupll_intr_clr_END (2)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_spll_fsm_en_START (3)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_spll_fsm_en_END (3)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_spll_vote_mode_sel_START (4)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_spll_vote_mode_sel_END (4)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_spll_intr_clr_START (5)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_spll_intr_clr_END (5)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_bitmasken_START (16)
#define SOC_AO_CRG_PLL_FSM_CTRL0_SEC_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_lock_dbc_en : 1;
        unsigned int pll_fsm_intr_en : 1;
        unsigned int pll_wait_en : 1;
        unsigned int pll_timeout_en : 1;
        unsigned int pll_intr_lmt : 3;
        unsigned int pll_wait_lmt : 8;
        unsigned int pll_timeout_lmt : 8;
        unsigned int reserved : 9;
    } reg;
} SOC_AO_CRG_PLL_FSM_CTRL1_SEC_UNION;
#endif
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_lock_dbc_en_START (0)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_lock_dbc_en_END (0)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_fsm_intr_en_START (1)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_fsm_intr_en_END (1)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_wait_en_START (2)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_wait_en_END (2)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_timeout_en_START (3)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_timeout_en_END (3)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_intr_lmt_START (4)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_intr_lmt_END (6)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_wait_lmt_START (7)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_wait_lmt_END (14)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_timeout_lmt_START (15)
#define SOC_AO_CRG_PLL_FSM_CTRL1_SEC_pll_timeout_lmt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aupll_fsm_intr : 1;
        unsigned int aupll_intr_cnt : 3;
        unsigned int aupll_curr_stat : 4;
        unsigned int spll_fsm_intr : 1;
        unsigned int spll_intr_cnt : 3;
        unsigned int spll_curr_stat : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_AO_CRG_PLL_FSM_STAT0_SEC_UNION;
#endif
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_aupll_fsm_intr_START (0)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_aupll_fsm_intr_END (0)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_aupll_intr_cnt_START (1)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_aupll_intr_cnt_END (3)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_aupll_curr_stat_START (4)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_aupll_curr_stat_END (7)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_spll_fsm_intr_START (8)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_spll_fsm_intr_END (8)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_spll_intr_cnt_START (9)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_spll_intr_cnt_END (11)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_spll_curr_stat_START (12)
#define SOC_AO_CRG_PLL_FSM_STAT0_SEC_spll_curr_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aoqic_aotcp_busy_bp : 1;
        unsigned int aoqic_qspi_idle_bp : 1;
        unsigned int aoqic_asp_perf_idle_bp : 1;
        unsigned int aoqic_asp_idle_bp : 1;
        unsigned int aoqic_iomcu_idle_bp : 1;
        unsigned int aoqic_top_idle_bp : 1;
        unsigned int aoqic_cc2ao_idle_bp : 1;
        unsigned int aoqic_mspc_idle_bp : 1;
        unsigned int ao2qic_top_bp : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_AO_CRG_AO_AUTODIV0_UNION;
#endif
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_aotcp_busy_bp_START (0)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_aotcp_busy_bp_END (0)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_qspi_idle_bp_START (1)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_qspi_idle_bp_END (1)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_asp_perf_idle_bp_START (2)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_asp_perf_idle_bp_END (2)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_asp_idle_bp_START (3)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_asp_idle_bp_END (3)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_iomcu_idle_bp_START (4)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_iomcu_idle_bp_END (4)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_top_idle_bp_START (5)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_top_idle_bp_END (5)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_cc2ao_idle_bp_START (6)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_cc2ao_idle_bp_END (6)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_mspc_idle_bp_START (7)
#define SOC_AO_CRG_AO_AUTODIV0_aoqic_mspc_idle_bp_END (7)
#define SOC_AO_CRG_AO_AUTODIV0_ao2qic_top_bp_START (8)
#define SOC_AO_CRG_AO_AUTODIV0_ao2qic_top_bp_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_AO_CRG_AO_AUTODIV1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrc_csysreq_cfg_sc2aocrg : 4;
        unsigned int ddrc_csysreq_sft_cfg_sc2aocrg : 1;
        unsigned int reserved_0 : 3;
        unsigned int ddrc_csysreq_stat_aocrg2sc : 4;
        unsigned int ddrc_csysack_stat : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_AO_CRG_SC_DDRC_CTRL_UNION;
#endif
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysreq_cfg_sc2aocrg_START (0)
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysreq_cfg_sc2aocrg_END (3)
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysreq_sft_cfg_sc2aocrg_START (4)
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysreq_sft_cfg_sc2aocrg_END (4)
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysreq_stat_aocrg2sc_START (8)
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysreq_stat_aocrg2sc_END (11)
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysack_stat_START (12)
#define SOC_AO_CRG_SC_DDRC_CTRL_ddrc_csysack_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_en : 1;
        unsigned int spll_bp : 1;
        unsigned int spll_refdiv : 6;
        unsigned int spll_fbdiv : 12;
        unsigned int spll_postdiv1 : 3;
        unsigned int spll_postdiv2 : 3;
        unsigned int reserved : 6;
    } reg;
} SOC_AO_CRG_SCSPLLCTRL0_UNION;
#endif
#define SOC_AO_CRG_SCSPLLCTRL0_spll_en_START (0)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_en_END (0)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_bp_START (1)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_bp_END (1)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_refdiv_START (2)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_refdiv_END (7)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_fbdiv_START (8)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_fbdiv_END (19)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_postdiv1_START (20)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_postdiv1_END (22)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_postdiv2_START (23)
#define SOC_AO_CRG_SCSPLLCTRL0_spll_postdiv2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_fracdiv : 24;
        unsigned int spll_int_mod : 1;
        unsigned int spll_cfg_vld : 1;
        unsigned int gt_clk_spll : 1;
        unsigned int sel_spll_mux : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_AO_CRG_SCSPLLCTRL1_UNION;
#endif
#define SOC_AO_CRG_SCSPLLCTRL1_spll_fracdiv_START (0)
#define SOC_AO_CRG_SCSPLLCTRL1_spll_fracdiv_END (23)
#define SOC_AO_CRG_SCSPLLCTRL1_spll_int_mod_START (24)
#define SOC_AO_CRG_SCSPLLCTRL1_spll_int_mod_END (24)
#define SOC_AO_CRG_SCSPLLCTRL1_spll_cfg_vld_START (25)
#define SOC_AO_CRG_SCSPLLCTRL1_spll_cfg_vld_END (25)
#define SOC_AO_CRG_SCSPLLCTRL1_gt_clk_spll_START (26)
#define SOC_AO_CRG_SCSPLLCTRL1_gt_clk_spll_END (26)
#define SOC_AO_CRG_SCSPLLCTRL1_sel_spll_mux_START (27)
#define SOC_AO_CRG_SCSPLLCTRL1_sel_spll_mux_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_rate : 4;
        unsigned int sscg_depth : 3;
        unsigned int sscg_fast_dis : 1;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AO_CRG_SCSPLLSSCCTRL_UNION;
#endif
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_enable_START (0)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_enable_END (0)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_mode_START (1)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_mode_END (1)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_rate_START (2)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_rate_END (5)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_depth_START (6)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_depth_END (8)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_fast_dis_START (9)
#define SOC_AO_CRG_SCSPLLSSCCTRL_sscg_fast_dis_END (9)
#define SOC_AO_CRG_SCSPLLSSCCTRL_bitmasken_START (16)
#define SOC_AO_CRG_SCSPLLSSCCTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SCSPLLCTRL0_LOCK_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AO_CRG_SCSPLLCTRL1_LOCK_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scspllsscctrl_lock_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_AO_CRG_SCSPLLSSCCTRL_LOCK_STAT_UNION;
#endif
#define SOC_AO_CRG_SCSPLLSSCCTRL_LOCK_STAT_scspllsscctrl_lock_stat_START (0)
#define SOC_AO_CRG_SCSPLLSSCCTRL_LOCK_STAT_scspllsscctrl_lock_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scclkdiv1_sec_lock_stat : 16;
        unsigned int spll_lock_bypass_stat : 1;
        unsigned int reserved_0 : 3;
        unsigned int spll_lock_bypass : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_UNION;
#endif
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_scclkdiv1_sec_lock_stat_START (0)
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_scclkdiv1_sec_lock_stat_END (15)
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_spll_lock_bypass_stat_START (16)
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_spll_lock_bypass_stat_END (16)
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_spll_lock_bypass_START (20)
#define SOC_AO_CRG_SCSPLL_OTHER_LOCK_STAT_spll_lock_bypass_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_reg_sel : 1;
        unsigned int read_en : 1;
        unsigned int input_cfg_en : 1;
        unsigned int test_mode : 1;
        unsigned int unlock_clear : 1;
        unsigned int dll_en : 1;
        unsigned int pll_lock_ate_sel : 2;
        unsigned int test_data_sel : 4;
        unsigned int bias_ctrl : 2;
        unsigned int icp_ctrl : 2;
        unsigned int updn_sel : 1;
        unsigned int reserved : 2;
        unsigned int int_mask : 3;
        unsigned int pfd_div_ratio : 4;
        unsigned int freq_threshold : 6;
    } reg;
} SOC_AO_CRG_FNPLL_CFG0_UNION;
#endif
#define SOC_AO_CRG_FNPLL_CFG0_sta_reg_sel_START (0)
#define SOC_AO_CRG_FNPLL_CFG0_sta_reg_sel_END (0)
#define SOC_AO_CRG_FNPLL_CFG0_read_en_START (1)
#define SOC_AO_CRG_FNPLL_CFG0_read_en_END (1)
#define SOC_AO_CRG_FNPLL_CFG0_input_cfg_en_START (2)
#define SOC_AO_CRG_FNPLL_CFG0_input_cfg_en_END (2)
#define SOC_AO_CRG_FNPLL_CFG0_test_mode_START (3)
#define SOC_AO_CRG_FNPLL_CFG0_test_mode_END (3)
#define SOC_AO_CRG_FNPLL_CFG0_unlock_clear_START (4)
#define SOC_AO_CRG_FNPLL_CFG0_unlock_clear_END (4)
#define SOC_AO_CRG_FNPLL_CFG0_dll_en_START (5)
#define SOC_AO_CRG_FNPLL_CFG0_dll_en_END (5)
#define SOC_AO_CRG_FNPLL_CFG0_pll_lock_ate_sel_START (6)
#define SOC_AO_CRG_FNPLL_CFG0_pll_lock_ate_sel_END (7)
#define SOC_AO_CRG_FNPLL_CFG0_test_data_sel_START (8)
#define SOC_AO_CRG_FNPLL_CFG0_test_data_sel_END (11)
#define SOC_AO_CRG_FNPLL_CFG0_bias_ctrl_START (12)
#define SOC_AO_CRG_FNPLL_CFG0_bias_ctrl_END (13)
#define SOC_AO_CRG_FNPLL_CFG0_icp_ctrl_START (14)
#define SOC_AO_CRG_FNPLL_CFG0_icp_ctrl_END (15)
#define SOC_AO_CRG_FNPLL_CFG0_updn_sel_START (16)
#define SOC_AO_CRG_FNPLL_CFG0_updn_sel_END (16)
#define SOC_AO_CRG_FNPLL_CFG0_int_mask_START (19)
#define SOC_AO_CRG_FNPLL_CFG0_int_mask_END (21)
#define SOC_AO_CRG_FNPLL_CFG0_pfd_div_ratio_START (22)
#define SOC_AO_CRG_FNPLL_CFG0_pfd_div_ratio_END (25)
#define SOC_AO_CRG_FNPLL_CFG0_freq_threshold_START (26)
#define SOC_AO_CRG_FNPLL_CFG0_freq_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctinue_lock_num : 6;
        unsigned int lock_thr : 2;
        unsigned int dc_ac_clk_en : 1;
        unsigned int dtc_ctrl_inv : 1;
        unsigned int reserved : 6;
        unsigned int ana_cfg_fnpll : 16;
    } reg;
} SOC_AO_CRG_FNPLL_CFG1_UNION;
#endif
#define SOC_AO_CRG_FNPLL_CFG1_ctinue_lock_num_START (0)
#define SOC_AO_CRG_FNPLL_CFG1_ctinue_lock_num_END (5)
#define SOC_AO_CRG_FNPLL_CFG1_lock_thr_START (6)
#define SOC_AO_CRG_FNPLL_CFG1_lock_thr_END (7)
#define SOC_AO_CRG_FNPLL_CFG1_dc_ac_clk_en_START (8)
#define SOC_AO_CRG_FNPLL_CFG1_dc_ac_clk_en_END (8)
#define SOC_AO_CRG_FNPLL_CFG1_dtc_ctrl_inv_START (9)
#define SOC_AO_CRG_FNPLL_CFG1_dtc_ctrl_inv_END (9)
#define SOC_AO_CRG_FNPLL_CFG1_ana_cfg_fnpll_START (16)
#define SOC_AO_CRG_FNPLL_CFG1_ana_cfg_fnpll_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div2_pd : 1;
        unsigned int fbdiv_rst_n : 1;
        unsigned int refdiv_rst_n : 1;
        unsigned int dll_force_en : 1;
        unsigned int phe_code_a : 2;
        unsigned int phe_code_b : 2;
        unsigned int bbpd_calib_byp : 1;
        unsigned int k_gain_cfg_en : 1;
        unsigned int k_gain_cfg : 6;
        unsigned int k_gain_av_thr : 3;
        unsigned int dtc_test : 1;
        unsigned int dtc_m_cfg : 6;
        unsigned int dtc_o_cfg : 6;
    } reg;
} SOC_AO_CRG_FNPLL_CFG2_UNION;
#endif
#define SOC_AO_CRG_FNPLL_CFG2_div2_pd_START (0)
#define SOC_AO_CRG_FNPLL_CFG2_div2_pd_END (0)
#define SOC_AO_CRG_FNPLL_CFG2_fbdiv_rst_n_START (1)
#define SOC_AO_CRG_FNPLL_CFG2_fbdiv_rst_n_END (1)
#define SOC_AO_CRG_FNPLL_CFG2_refdiv_rst_n_START (2)
#define SOC_AO_CRG_FNPLL_CFG2_refdiv_rst_n_END (2)
#define SOC_AO_CRG_FNPLL_CFG2_dll_force_en_START (3)
#define SOC_AO_CRG_FNPLL_CFG2_dll_force_en_END (3)
#define SOC_AO_CRG_FNPLL_CFG2_phe_code_a_START (4)
#define SOC_AO_CRG_FNPLL_CFG2_phe_code_a_END (5)
#define SOC_AO_CRG_FNPLL_CFG2_phe_code_b_START (6)
#define SOC_AO_CRG_FNPLL_CFG2_phe_code_b_END (7)
#define SOC_AO_CRG_FNPLL_CFG2_bbpd_calib_byp_START (8)
#define SOC_AO_CRG_FNPLL_CFG2_bbpd_calib_byp_END (8)
#define SOC_AO_CRG_FNPLL_CFG2_k_gain_cfg_en_START (9)
#define SOC_AO_CRG_FNPLL_CFG2_k_gain_cfg_en_END (9)
#define SOC_AO_CRG_FNPLL_CFG2_k_gain_cfg_START (10)
#define SOC_AO_CRG_FNPLL_CFG2_k_gain_cfg_END (15)
#define SOC_AO_CRG_FNPLL_CFG2_k_gain_av_thr_START (16)
#define SOC_AO_CRG_FNPLL_CFG2_k_gain_av_thr_END (18)
#define SOC_AO_CRG_FNPLL_CFG2_dtc_test_START (19)
#define SOC_AO_CRG_FNPLL_CFG2_dtc_test_END (19)
#define SOC_AO_CRG_FNPLL_CFG2_dtc_m_cfg_START (20)
#define SOC_AO_CRG_FNPLL_CFG2_dtc_m_cfg_END (25)
#define SOC_AO_CRG_FNPLL_CFG2_dtc_o_cfg_START (26)
#define SOC_AO_CRG_FNPLL_CFG2_dtc_o_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scppll_cfg3 : 32;
    } reg;
} SOC_AO_CRG_FNPLL_CFG3_UNION;
#endif
#define SOC_AO_CRG_FNPLL_CFG3_scppll_cfg3_START (0)
#define SOC_AO_CRG_FNPLL_CFG3_scppll_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_reg_sel : 1;
        unsigned int read_en : 1;
        unsigned int input_cfg_en : 1;
        unsigned int test_mode : 1;
        unsigned int unlock_clear : 1;
        unsigned int dll_en : 1;
        unsigned int pll_lock_ate_sel : 2;
        unsigned int test_data_sel : 4;
        unsigned int bias_ctrl : 2;
        unsigned int icp_ctrl : 2;
        unsigned int updn_sel : 1;
        unsigned int reserved : 2;
        unsigned int int_mask : 3;
        unsigned int pfd_div_ratio : 4;
        unsigned int freq_threshold : 6;
    } reg;
} SOC_AO_CRG_FNPLL_LP_CFG0_UNION;
#endif
#define SOC_AO_CRG_FNPLL_LP_CFG0_sta_reg_sel_START (0)
#define SOC_AO_CRG_FNPLL_LP_CFG0_sta_reg_sel_END (0)
#define SOC_AO_CRG_FNPLL_LP_CFG0_read_en_START (1)
#define SOC_AO_CRG_FNPLL_LP_CFG0_read_en_END (1)
#define SOC_AO_CRG_FNPLL_LP_CFG0_input_cfg_en_START (2)
#define SOC_AO_CRG_FNPLL_LP_CFG0_input_cfg_en_END (2)
#define SOC_AO_CRG_FNPLL_LP_CFG0_test_mode_START (3)
#define SOC_AO_CRG_FNPLL_LP_CFG0_test_mode_END (3)
#define SOC_AO_CRG_FNPLL_LP_CFG0_unlock_clear_START (4)
#define SOC_AO_CRG_FNPLL_LP_CFG0_unlock_clear_END (4)
#define SOC_AO_CRG_FNPLL_LP_CFG0_dll_en_START (5)
#define SOC_AO_CRG_FNPLL_LP_CFG0_dll_en_END (5)
#define SOC_AO_CRG_FNPLL_LP_CFG0_pll_lock_ate_sel_START (6)
#define SOC_AO_CRG_FNPLL_LP_CFG0_pll_lock_ate_sel_END (7)
#define SOC_AO_CRG_FNPLL_LP_CFG0_test_data_sel_START (8)
#define SOC_AO_CRG_FNPLL_LP_CFG0_test_data_sel_END (11)
#define SOC_AO_CRG_FNPLL_LP_CFG0_bias_ctrl_START (12)
#define SOC_AO_CRG_FNPLL_LP_CFG0_bias_ctrl_END (13)
#define SOC_AO_CRG_FNPLL_LP_CFG0_icp_ctrl_START (14)
#define SOC_AO_CRG_FNPLL_LP_CFG0_icp_ctrl_END (15)
#define SOC_AO_CRG_FNPLL_LP_CFG0_updn_sel_START (16)
#define SOC_AO_CRG_FNPLL_LP_CFG0_updn_sel_END (16)
#define SOC_AO_CRG_FNPLL_LP_CFG0_int_mask_START (19)
#define SOC_AO_CRG_FNPLL_LP_CFG0_int_mask_END (21)
#define SOC_AO_CRG_FNPLL_LP_CFG0_pfd_div_ratio_START (22)
#define SOC_AO_CRG_FNPLL_LP_CFG0_pfd_div_ratio_END (25)
#define SOC_AO_CRG_FNPLL_LP_CFG0_freq_threshold_START (26)
#define SOC_AO_CRG_FNPLL_LP_CFG0_freq_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctinue_lock_num : 6;
        unsigned int lock_thr : 2;
        unsigned int dc_ac_clk_en : 1;
        unsigned int dtc_ctrl_inv : 1;
        unsigned int reserved : 6;
        unsigned int ana_cfg_fnpll : 16;
    } reg;
} SOC_AO_CRG_FNPLL_LP_CFG1_UNION;
#endif
#define SOC_AO_CRG_FNPLL_LP_CFG1_ctinue_lock_num_START (0)
#define SOC_AO_CRG_FNPLL_LP_CFG1_ctinue_lock_num_END (5)
#define SOC_AO_CRG_FNPLL_LP_CFG1_lock_thr_START (6)
#define SOC_AO_CRG_FNPLL_LP_CFG1_lock_thr_END (7)
#define SOC_AO_CRG_FNPLL_LP_CFG1_dc_ac_clk_en_START (8)
#define SOC_AO_CRG_FNPLL_LP_CFG1_dc_ac_clk_en_END (8)
#define SOC_AO_CRG_FNPLL_LP_CFG1_dtc_ctrl_inv_START (9)
#define SOC_AO_CRG_FNPLL_LP_CFG1_dtc_ctrl_inv_END (9)
#define SOC_AO_CRG_FNPLL_LP_CFG1_ana_cfg_fnpll_START (16)
#define SOC_AO_CRG_FNPLL_LP_CFG1_ana_cfg_fnpll_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div2_pd : 1;
        unsigned int fbdiv_rst_n : 1;
        unsigned int refdiv_rst_n : 1;
        unsigned int dll_force_en : 1;
        unsigned int phe_code_a : 2;
        unsigned int phe_code_b : 2;
        unsigned int bbpd_calib_byp : 1;
        unsigned int k_gain_cfg_en : 1;
        unsigned int k_gain_cfg : 6;
        unsigned int k_gain_av_thr : 3;
        unsigned int dtc_test : 1;
        unsigned int dtc_m_cfg : 6;
        unsigned int dtc_o_cfg : 6;
    } reg;
} SOC_AO_CRG_FNPLL_LP_CFG2_UNION;
#endif
#define SOC_AO_CRG_FNPLL_LP_CFG2_div2_pd_START (0)
#define SOC_AO_CRG_FNPLL_LP_CFG2_div2_pd_END (0)
#define SOC_AO_CRG_FNPLL_LP_CFG2_fbdiv_rst_n_START (1)
#define SOC_AO_CRG_FNPLL_LP_CFG2_fbdiv_rst_n_END (1)
#define SOC_AO_CRG_FNPLL_LP_CFG2_refdiv_rst_n_START (2)
#define SOC_AO_CRG_FNPLL_LP_CFG2_refdiv_rst_n_END (2)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dll_force_en_START (3)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dll_force_en_END (3)
#define SOC_AO_CRG_FNPLL_LP_CFG2_phe_code_a_START (4)
#define SOC_AO_CRG_FNPLL_LP_CFG2_phe_code_a_END (5)
#define SOC_AO_CRG_FNPLL_LP_CFG2_phe_code_b_START (6)
#define SOC_AO_CRG_FNPLL_LP_CFG2_phe_code_b_END (7)
#define SOC_AO_CRG_FNPLL_LP_CFG2_bbpd_calib_byp_START (8)
#define SOC_AO_CRG_FNPLL_LP_CFG2_bbpd_calib_byp_END (8)
#define SOC_AO_CRG_FNPLL_LP_CFG2_k_gain_cfg_en_START (9)
#define SOC_AO_CRG_FNPLL_LP_CFG2_k_gain_cfg_en_END (9)
#define SOC_AO_CRG_FNPLL_LP_CFG2_k_gain_cfg_START (10)
#define SOC_AO_CRG_FNPLL_LP_CFG2_k_gain_cfg_END (15)
#define SOC_AO_CRG_FNPLL_LP_CFG2_k_gain_av_thr_START (16)
#define SOC_AO_CRG_FNPLL_LP_CFG2_k_gain_av_thr_END (18)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dtc_test_START (19)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dtc_test_END (19)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dtc_m_cfg_START (20)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dtc_m_cfg_END (25)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dtc_o_cfg_START (26)
#define SOC_AO_CRG_FNPLL_LP_CFG2_dtc_o_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scppll_cfg3 : 32;
    } reg;
} SOC_AO_CRG_FNPLL_LP_CFG3_UNION;
#endif
#define SOC_AO_CRG_FNPLL_LP_CFG3_scppll_cfg3_START (0)
#define SOC_AO_CRG_FNPLL_LP_CFG3_scppll_cfg3_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
