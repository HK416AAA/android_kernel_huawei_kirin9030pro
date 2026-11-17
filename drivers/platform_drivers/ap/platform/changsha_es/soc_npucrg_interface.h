#ifndef __SOC_NPUCRG_INTERFACE_H__
#define __SOC_NPUCRG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPUCRG_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x21CUL))
#define SOC_NPUCRG_PLL_FSM_NS_STAT_ADDR(base) ((base) + (0x220UL))
#define SOC_NPUCRG_PEREN0_ADDR(base) ((base) + (0x800UL))
#define SOC_NPUCRG_PERDIS0_ADDR(base) ((base) + (0x804UL))
#define SOC_NPUCRG_PERCLKEN0_ADDR(base) ((base) + (0x808UL))
#define SOC_NPUCRG_PERSTAT0_ADDR(base) ((base) + (0x80CUL))
#define SOC_NPUCRG_PEREN1_ADDR(base) ((base) + (0x810UL))
#define SOC_NPUCRG_PERDIS1_ADDR(base) ((base) + (0x814UL))
#define SOC_NPUCRG_PERCLKEN1_ADDR(base) ((base) + (0x818UL))
#define SOC_NPUCRG_PERSTAT1_ADDR(base) ((base) + (0x81CUL))
#define SOC_NPUCRG_PEREN2_ADDR(base) ((base) + (0x820UL))
#define SOC_NPUCRG_PERDIS2_ADDR(base) ((base) + (0x824UL))
#define SOC_NPUCRG_PERCLKEN2_ADDR(base) ((base) + (0x828UL))
#define SOC_NPUCRG_PERSTAT2_ADDR(base) ((base) + (0x82CUL))
#define SOC_NPUCRG_PEREN3_ADDR(base) ((base) + (0x830UL))
#define SOC_NPUCRG_PERDIS3_ADDR(base) ((base) + (0x834UL))
#define SOC_NPUCRG_PERCLKEN3_ADDR(base) ((base) + (0x838UL))
#define SOC_NPUCRG_PERSTAT3_ADDR(base) ((base) + (0x83CUL))
#define SOC_NPUCRG_PERRSTEN0_ADDR(base) ((base) + (0x840UL))
#define SOC_NPUCRG_PERRSTDIS0_ADDR(base) ((base) + (0x844UL))
#define SOC_NPUCRG_PERRSTSTAT0_ADDR(base) ((base) + (0x848UL))
#define SOC_NPUCRG_PERRSTEN1_ADDR(base) ((base) + (0x84cUL))
#define SOC_NPUCRG_PERRSTDIS1_ADDR(base) ((base) + (0x850UL))
#define SOC_NPUCRG_PERRSTSTAT1_ADDR(base) ((base) + (0x854UL))
#define SOC_NPUCRG_PERRSTEN2_ADDR(base) ((base) + (0x858UL))
#define SOC_NPUCRG_PERRSTDIS2_ADDR(base) ((base) + (0x85cUL))
#define SOC_NPUCRG_PERRSTSTAT2_ADDR(base) ((base) + (0x860UL))
#define SOC_NPUCRG_CLKDIV0_ADDR(base) ((base) + (0x870UL))
#define SOC_NPUCRG_CLKDIV3_ADDR(base) ((base) + (0x874UL))
#define SOC_NPUCRG_CLKDIV1_ADDR(base) ((base) + (0x878UL))
#define SOC_NPUCRG_CLKDIV2_ADDR(base) ((base) + (0x87CUL))
#define SOC_NPUCRG_PERI_STAT0_ADDR(base) ((base) + (0x880UL))
#define SOC_NPUCRG_PERI_CTRL0_ADDR(base) ((base) + (0x884UL))
#define SOC_NPUCRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x890UL))
#define SOC_NPUCRG_IPCLKRST_BYPASS1_ADDR(base) ((base) + (0x894UL))
#define SOC_NPUCRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x8A0UL))
#define SOC_NPUCRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x8A4UL))
#define SOC_NPUCRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x8A8UL))
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x8ACUL))
#define SOC_NPUCRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x8B0UL))
#define SOC_NPUCRG_PERI_AUTODIV5_ADDR(base) ((base) + (0x8B8UL))
#define SOC_NPUCRG_PERI_AUTODIV8_ADDR(base) ((base) + (0x8C4UL))
#define SOC_NPUCRG_PERI_AUTODIV9_ADDR(base) ((base) + (0x8C8UL))
#define SOC_NPUCRG_PERI_AUTODIV11_ADDR(base) ((base) + (0x8D0UL))
#define SOC_NPUCRG_PERI_AUTODIV12_ADDR(base) ((base) + (0x8D4UL))
#define SOC_NPUCRG_NPU_SUBSYS_STAT0_ADDR(base) ((base) + (0x8d8UL))
#define SOC_NPUCRG_NPU_SUBSYS_STAT1_ADDR(base) ((base) + (0x8dcUL))
#define SOC_NPUCRG_FCGCTRL0_ADDR(base) ((base) + (0x998UL))
#define SOC_NPUCRG_FCGCTRL1_ADDR(base) ((base) + (0x99CUL))
#define SOC_NPUCRG_PLL_VOTE_STAT_ADDR(base) ((base) + (0xA0CUL))
#define SOC_NPUCRG_PLL_EN_VOTE_CTRL_ADDR(base) ((base) + (0xA10UL))
#define SOC_NPUCRG_PLL_GT_VOTE_CTRL_ADDR(base) ((base) + (0xA14UL))
#define SOC_NPUCRG_PLL_BYPASS_VOTE_CTRL_ADDR(base) ((base) + (0xA18UL))
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_ADDR(base) ((base) + (0xB00UL))
#define SOC_NPUCRG_FCG_CFG_RSV0_ADDR(base) ((base) + (0xB10UL))
#define SOC_NPUCRG_FCG_STAT0_ADDR(base) ((base) + (0xB14UL))
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_ADDR(base) ((base) + (0xB20UL))
#define SOC_NPUCRG_PIM_CTRL0_ADDR(base) ((base) + (0xB50UL))
#define SOC_NPUCRG_PIM_CFG0_AICORE_ADDR(base) ((base) + (0xB54UL))
#define SOC_NPUCRG_PIM_CFG1_AICORE_ADDR(base) ((base) + (0xB58UL))
#define SOC_NPUCRG_PIM_CFG2_AICORE_ADDR(base) ((base) + (0xB5CUL))
#define SOC_NPUCRG_PIM_CFG3_AICORE_ADDR(base) ((base) + (0xB60UL))
#define SOC_NPUCRG_PIM_STAT0_ADDR(base) ((base) + (0xB6CUL))
#define SOC_NPUCRG_MON_CFG0_NPU_ADDR(base) ((base) + (0xC00UL))
#define SOC_NPUCRG_MON_CFG1_NPU_ADDR(base) ((base) + (0xC04UL))
#define SOC_NPUCRG_MON_CFG2_NPU_ADDR(base) ((base) + (0xC08UL))
#define SOC_NPUCRG_MON_CFG3_NPU_ADDR(base) ((base) + (0xC0CUL))
#define SOC_NPUCRG_MON_CFG4_NPU_ADDR(base) ((base) + (0xC10UL))
#define SOC_NPUCRG_MON_CFG5_NPU_ADDR(base) ((base) + (0xC14UL))
#define SOC_NPUCRG_MON_CFG6_NPU_ADDR(base) ((base) + (0xC18UL))
#define SOC_NPUCRG_MON_CFG7_NPU_ADDR(base) ((base) + (0xC1CUL))
#define SOC_NPUCRG_MON_CFG8_NPU_ADDR(base) ((base) + (0xC20UL))
#define SOC_NPUCRG_MON_CFG9_NPU_ADDR(base) ((base) + (0xC24UL))
#define SOC_NPUCRG_MON_CFG10_NPU_ADDR(base) ((base) + (0xC28UL))
#define SOC_NPUCRG_MON_CFG11_NPU_ADDR(base) ((base) + (0xC2CUL))
#define SOC_NPUCRG_MON_CFG12_NPU_ADDR(base) ((base) + (0xC30UL))
#define SOC_NPUCRG_MON_CFG13_NPU_ADDR(base) ((base) + (0xC34UL))
#define SOC_NPUCRG_MON_CFG14_NPU_ADDR(base) ((base) + (0xC38UL))
#define SOC_NPUCRG_MON_CFG15_NPU_ADDR(base) ((base) + (0xC3CUL))
#define SOC_NPUCRG_MON_CFG16_NPU_ADDR(base) ((base) + (0xC40UL))
#define SOC_NPUCRG_MON_STAT0_NPU_ADDR(base) ((base) + (0xC44UL))
#define SOC_NPUCRG_MON_STAT1_NPU_ADDR(base) ((base) + (0xC48UL))
#define SOC_NPUCRG_MON_STAT2_NPU_ADDR(base) ((base) + (0xC4CUL))
#define SOC_NPUCRG_MON_STAT3_NPU_ADDR(base) ((base) + (0xC50UL))
#define SOC_NPUCRG_MON_STAT4_NPU_ADDR(base) ((base) + (0xC54UL))
#define SOC_NPUCRG_MON_STAT5_NPU_ADDR(base) ((base) + (0xC58UL))
#define SOC_NPUCRG_MON_STAT6_NPU_ADDR(base) ((base) + (0xC5CUL))
#define SOC_NPUCRG_MON_STAT7_NPU_ADDR(base) ((base) + (0xC60UL))
#define SOC_NPUCRG_MON_STAT8_NPU_ADDR(base) ((base) + (0xC64UL))
#define SOC_NPUCRG_MON_STAT9_NPU_ADDR(base) ((base) + (0xC68UL))
#define SOC_NPUCRG_MON_STAT10_NPU_ADDR(base) ((base) + (0xC6CUL))
#define SOC_NPUCRG_MON_STAT11_NPU_ADDR(base) ((base) + (0xC70UL))
#define SOC_NPUCRG_MON_STAT12_NPU_ADDR(base) ((base) + (0xC74UL))
#define SOC_NPUCRG_MON_STAT13_NPU_ADDR(base) ((base) + (0xC78UL))
#define SOC_NPUCRG_MON_STAT14_NPU_ADDR(base) ((base) + (0xC7CUL))
#define SOC_NPUCRG_MON_STAT15_NPU_ADDR(base) ((base) + (0xC80UL))
#define SOC_NPUCRG_MON_STAT16_NPU_ADDR(base) ((base) + (0xC84UL))
#define SOC_NPUCRG_MON_STAT17_NPU_ADDR(base) ((base) + (0xC88UL))
#define SOC_NPUCRG_MON_STAT18_NPU_ADDR(base) ((base) + (0xC8CUL))
#define SOC_NPUCRG_MON_STAT19_NPU_ADDR(base) ((base) + (0xC90UL))
#define SOC_NPUCRG_MON_STAT20_NPU_ADDR(base) ((base) + (0xC94UL))
#define SOC_NPUCRG_MON_STAT21_NPU_ADDR(base) ((base) + (0xC98UL))
#define SOC_NPUCRG_MON_STAT22_NPU_ADDR(base) ((base) + (0xCA0UL))
#define SOC_NPUCRG_MON_STAT23_NPU_ADDR(base) ((base) + (0xCA4UL))
#define SOC_NPUCRG_MON_STAT24_NPU_ADDR(base) ((base) + (0xCA8UL))
#define SOC_NPUCRG_MON_STAT25_NPU_ADDR(base) ((base) + (0xCACUL))
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_ADDR(base) ((base) + (0xD00UL))
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_ADDR(base) ((base) + (0xD04UL))
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_ADDR(base) ((base) + (0xD08UL))
#define SOC_NPUCRG_PLL_FSM_CTRL0_ADDR(base) ((base) + (0xD10UL))
#define SOC_NPUCRG_PLL_FSM_CTRL1_ADDR(base) ((base) + (0xD14UL))
#define SOC_NPUCRG_PLL_FSM_STAT_ADDR(base) ((base) + (0xD18UL))
#define SOC_NPUCRG_FCG_ANA_CFG0_AICORE_ADDR(base) ((base) + (0xE00UL))
#define SOC_NPUCRG_FCG_ANA_CFG1_AICORE_ADDR(base) ((base) + (0xE04UL))
#define SOC_NPUCRG_FCG_ANA_CFG2_AICORE_ADDR(base) ((base) + (0xE08UL))
#define SOC_NPUCRG_FCG_ANA_CFG3_AICORE_ADDR(base) ((base) + (0xE0CUL))
#define SOC_NPUCRG_FCG_CFG0_AICORE_ADDR(base) ((base) + (0xE18UL))
#define SOC_NPUCRG_FCG_CFG1_AICORE_ADDR(base) ((base) + (0xE1CUL))
#define SOC_NPUCRG_FCG_CFG2_AICORE_ADDR(base) ((base) + (0xE20UL))
#define SOC_NPUCRG_FCG_CFG3_AICORE_ADDR(base) ((base) + (0xE24UL))
#define SOC_NPUCRG_FCG_CFG4_AICORE_ADDR(base) ((base) + (0xE28UL))
#define SOC_NPUCRG_FCG_CFG5_AICORE_ADDR(base) ((base) + (0xE2CUL))
#define SOC_NPUCRG_FCG_CFG6_AICORE_ADDR(base) ((base) + (0xE30UL))
#define SOC_NPUCRG_FCG_CFG7_AICORE_ADDR(base) ((base) + (0xE34UL))
#define SOC_NPUCRG_FCG_CFG8_AICORE_ADDR(base) ((base) + (0xE38UL))
#define SOC_NPUCRG_FCG_CFG9_AICORE_ADDR(base) ((base) + (0xE3CUL))
#define SOC_NPUCRG_FCG_CFG10_AICORE_ADDR(base) ((base) + (0xE40UL))
#define SOC_NPUCRG_FCG_CFG11_AICORE_ADDR(base) ((base) + (0xE44UL))
#define SOC_NPUCRG_FCG_CFG12_AICORE_ADDR(base) ((base) + (0xE48UL))
#define SOC_NPUCRG_FCG_CFG13_AICORE_ADDR(base) ((base) + (0xE4CUL))
#define SOC_NPUCRG_FCG_CFG14_AICORE_ADDR(base) ((base) + (0xE50UL))
#define SOC_NPUCRG_FCG_CFG15_AICORE_ADDR(base) ((base) + (0xE54UL))
#define SOC_NPUCRG_FCG_CFG16_AICORE_ADDR(base) ((base) + (0xE58UL))
#define SOC_NPUCRG_FCG_CFG17_AICORE_ADDR(base) ((base) + (0xE5CUL))
#define SOC_NPUCRG_FCG_CFG18_AICORE_ADDR(base) ((base) + (0xE60UL))
#define SOC_NPUCRG_FCG_CFG19_AICORE_ADDR(base) ((base) + (0xE64UL))
#define SOC_NPUCRG_FCG_CFG20_AICORE_ADDR(base) ((base) + (0xE68UL))
#define SOC_NPUCRG_FCG_CFG21_AICORE_ADDR(base) ((base) + (0xE6CUL))
#define SOC_NPUCRG_FCG_CFG22_AICORE_ADDR(base) ((base) + (0xE70UL))
#define SOC_NPUCRG_FCG_CFG23_AICORE_ADDR(base) ((base) + (0xE74UL))
#define SOC_NPUCRG_FCG_CFG24_AICORE_ADDR(base) ((base) + (0xE78UL))
#define SOC_NPUCRG_FCG_CFG25_AICORE_ADDR(base) ((base) + (0xE7CUL))
#define SOC_NPUCRG_FCG_CFG26_AICORE_ADDR(base) ((base) + (0xE80UL))
#define SOC_NPUCRG_FCG_CFG27_AICORE_ADDR(base) ((base) + (0xE84UL))
#define SOC_NPUCRG_FCG_STAT0_AICORE_ADDR(base) ((base) + (0xE90UL))
#define SOC_NPUCRG_FCG_STAT1_AICORE_ADDR(base) ((base) + (0xE94UL))
#define SOC_NPUCRG_FCG_STAT2_AICORE_ADDR(base) ((base) + (0xE98UL))
#define SOC_NPUCRG_FCG_STAT3_AICORE_ADDR(base) ((base) + (0xE9CUL))
#define SOC_NPUCRG_FCG_STAT4_AICORE_ADDR(base) ((base) + (0xEA0UL))
#define SOC_NPUCRG_FCG_STAT5_AICORE_ADDR(base) ((base) + (0xEA4UL))
#define SOC_NPUCRG_IPSIGMASK_ADDR(base) ((base) + (0x700UL))
#else
#define SOC_NPUCRG_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x21C))
#define SOC_NPUCRG_PLL_FSM_NS_STAT_ADDR(base) ((base) + (0x220))
#define SOC_NPUCRG_PEREN0_ADDR(base) ((base) + (0x800))
#define SOC_NPUCRG_PERDIS0_ADDR(base) ((base) + (0x804))
#define SOC_NPUCRG_PERCLKEN0_ADDR(base) ((base) + (0x808))
#define SOC_NPUCRG_PERSTAT0_ADDR(base) ((base) + (0x80C))
#define SOC_NPUCRG_PEREN1_ADDR(base) ((base) + (0x810))
#define SOC_NPUCRG_PERDIS1_ADDR(base) ((base) + (0x814))
#define SOC_NPUCRG_PERCLKEN1_ADDR(base) ((base) + (0x818))
#define SOC_NPUCRG_PERSTAT1_ADDR(base) ((base) + (0x81C))
#define SOC_NPUCRG_PEREN2_ADDR(base) ((base) + (0x820))
#define SOC_NPUCRG_PERDIS2_ADDR(base) ((base) + (0x824))
#define SOC_NPUCRG_PERCLKEN2_ADDR(base) ((base) + (0x828))
#define SOC_NPUCRG_PERSTAT2_ADDR(base) ((base) + (0x82C))
#define SOC_NPUCRG_PEREN3_ADDR(base) ((base) + (0x830))
#define SOC_NPUCRG_PERDIS3_ADDR(base) ((base) + (0x834))
#define SOC_NPUCRG_PERCLKEN3_ADDR(base) ((base) + (0x838))
#define SOC_NPUCRG_PERSTAT3_ADDR(base) ((base) + (0x83C))
#define SOC_NPUCRG_PERRSTEN0_ADDR(base) ((base) + (0x840))
#define SOC_NPUCRG_PERRSTDIS0_ADDR(base) ((base) + (0x844))
#define SOC_NPUCRG_PERRSTSTAT0_ADDR(base) ((base) + (0x848))
#define SOC_NPUCRG_PERRSTEN1_ADDR(base) ((base) + (0x84c))
#define SOC_NPUCRG_PERRSTDIS1_ADDR(base) ((base) + (0x850))
#define SOC_NPUCRG_PERRSTSTAT1_ADDR(base) ((base) + (0x854))
#define SOC_NPUCRG_PERRSTEN2_ADDR(base) ((base) + (0x858))
#define SOC_NPUCRG_PERRSTDIS2_ADDR(base) ((base) + (0x85c))
#define SOC_NPUCRG_PERRSTSTAT2_ADDR(base) ((base) + (0x860))
#define SOC_NPUCRG_CLKDIV0_ADDR(base) ((base) + (0x870))
#define SOC_NPUCRG_CLKDIV3_ADDR(base) ((base) + (0x874))
#define SOC_NPUCRG_CLKDIV1_ADDR(base) ((base) + (0x878))
#define SOC_NPUCRG_CLKDIV2_ADDR(base) ((base) + (0x87C))
#define SOC_NPUCRG_PERI_STAT0_ADDR(base) ((base) + (0x880))
#define SOC_NPUCRG_PERI_CTRL0_ADDR(base) ((base) + (0x884))
#define SOC_NPUCRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x890))
#define SOC_NPUCRG_IPCLKRST_BYPASS1_ADDR(base) ((base) + (0x894))
#define SOC_NPUCRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x8A0))
#define SOC_NPUCRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x8A4))
#define SOC_NPUCRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x8A8))
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x8AC))
#define SOC_NPUCRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x8B0))
#define SOC_NPUCRG_PERI_AUTODIV5_ADDR(base) ((base) + (0x8B8))
#define SOC_NPUCRG_PERI_AUTODIV8_ADDR(base) ((base) + (0x8C4))
#define SOC_NPUCRG_PERI_AUTODIV9_ADDR(base) ((base) + (0x8C8))
#define SOC_NPUCRG_PERI_AUTODIV11_ADDR(base) ((base) + (0x8D0))
#define SOC_NPUCRG_PERI_AUTODIV12_ADDR(base) ((base) + (0x8D4))
#define SOC_NPUCRG_NPU_SUBSYS_STAT0_ADDR(base) ((base) + (0x8d8))
#define SOC_NPUCRG_NPU_SUBSYS_STAT1_ADDR(base) ((base) + (0x8dc))
#define SOC_NPUCRG_FCGCTRL0_ADDR(base) ((base) + (0x998))
#define SOC_NPUCRG_FCGCTRL1_ADDR(base) ((base) + (0x99C))
#define SOC_NPUCRG_PLL_VOTE_STAT_ADDR(base) ((base) + (0xA0C))
#define SOC_NPUCRG_PLL_EN_VOTE_CTRL_ADDR(base) ((base) + (0xA10))
#define SOC_NPUCRG_PLL_GT_VOTE_CTRL_ADDR(base) ((base) + (0xA14))
#define SOC_NPUCRG_PLL_BYPASS_VOTE_CTRL_ADDR(base) ((base) + (0xA18))
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_ADDR(base) ((base) + (0xB00))
#define SOC_NPUCRG_FCG_CFG_RSV0_ADDR(base) ((base) + (0xB10))
#define SOC_NPUCRG_FCG_STAT0_ADDR(base) ((base) + (0xB14))
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_ADDR(base) ((base) + (0xB20))
#define SOC_NPUCRG_PIM_CTRL0_ADDR(base) ((base) + (0xB50))
#define SOC_NPUCRG_PIM_CFG0_AICORE_ADDR(base) ((base) + (0xB54))
#define SOC_NPUCRG_PIM_CFG1_AICORE_ADDR(base) ((base) + (0xB58))
#define SOC_NPUCRG_PIM_CFG2_AICORE_ADDR(base) ((base) + (0xB5C))
#define SOC_NPUCRG_PIM_CFG3_AICORE_ADDR(base) ((base) + (0xB60))
#define SOC_NPUCRG_PIM_STAT0_ADDR(base) ((base) + (0xB6C))
#define SOC_NPUCRG_MON_CFG0_NPU_ADDR(base) ((base) + (0xC00))
#define SOC_NPUCRG_MON_CFG1_NPU_ADDR(base) ((base) + (0xC04))
#define SOC_NPUCRG_MON_CFG2_NPU_ADDR(base) ((base) + (0xC08))
#define SOC_NPUCRG_MON_CFG3_NPU_ADDR(base) ((base) + (0xC0C))
#define SOC_NPUCRG_MON_CFG4_NPU_ADDR(base) ((base) + (0xC10))
#define SOC_NPUCRG_MON_CFG5_NPU_ADDR(base) ((base) + (0xC14))
#define SOC_NPUCRG_MON_CFG6_NPU_ADDR(base) ((base) + (0xC18))
#define SOC_NPUCRG_MON_CFG7_NPU_ADDR(base) ((base) + (0xC1C))
#define SOC_NPUCRG_MON_CFG8_NPU_ADDR(base) ((base) + (0xC20))
#define SOC_NPUCRG_MON_CFG9_NPU_ADDR(base) ((base) + (0xC24))
#define SOC_NPUCRG_MON_CFG10_NPU_ADDR(base) ((base) + (0xC28))
#define SOC_NPUCRG_MON_CFG11_NPU_ADDR(base) ((base) + (0xC2C))
#define SOC_NPUCRG_MON_CFG12_NPU_ADDR(base) ((base) + (0xC30))
#define SOC_NPUCRG_MON_CFG13_NPU_ADDR(base) ((base) + (0xC34))
#define SOC_NPUCRG_MON_CFG14_NPU_ADDR(base) ((base) + (0xC38))
#define SOC_NPUCRG_MON_CFG15_NPU_ADDR(base) ((base) + (0xC3C))
#define SOC_NPUCRG_MON_CFG16_NPU_ADDR(base) ((base) + (0xC40))
#define SOC_NPUCRG_MON_STAT0_NPU_ADDR(base) ((base) + (0xC44))
#define SOC_NPUCRG_MON_STAT1_NPU_ADDR(base) ((base) + (0xC48))
#define SOC_NPUCRG_MON_STAT2_NPU_ADDR(base) ((base) + (0xC4C))
#define SOC_NPUCRG_MON_STAT3_NPU_ADDR(base) ((base) + (0xC50))
#define SOC_NPUCRG_MON_STAT4_NPU_ADDR(base) ((base) + (0xC54))
#define SOC_NPUCRG_MON_STAT5_NPU_ADDR(base) ((base) + (0xC58))
#define SOC_NPUCRG_MON_STAT6_NPU_ADDR(base) ((base) + (0xC5C))
#define SOC_NPUCRG_MON_STAT7_NPU_ADDR(base) ((base) + (0xC60))
#define SOC_NPUCRG_MON_STAT8_NPU_ADDR(base) ((base) + (0xC64))
#define SOC_NPUCRG_MON_STAT9_NPU_ADDR(base) ((base) + (0xC68))
#define SOC_NPUCRG_MON_STAT10_NPU_ADDR(base) ((base) + (0xC6C))
#define SOC_NPUCRG_MON_STAT11_NPU_ADDR(base) ((base) + (0xC70))
#define SOC_NPUCRG_MON_STAT12_NPU_ADDR(base) ((base) + (0xC74))
#define SOC_NPUCRG_MON_STAT13_NPU_ADDR(base) ((base) + (0xC78))
#define SOC_NPUCRG_MON_STAT14_NPU_ADDR(base) ((base) + (0xC7C))
#define SOC_NPUCRG_MON_STAT15_NPU_ADDR(base) ((base) + (0xC80))
#define SOC_NPUCRG_MON_STAT16_NPU_ADDR(base) ((base) + (0xC84))
#define SOC_NPUCRG_MON_STAT17_NPU_ADDR(base) ((base) + (0xC88))
#define SOC_NPUCRG_MON_STAT18_NPU_ADDR(base) ((base) + (0xC8C))
#define SOC_NPUCRG_MON_STAT19_NPU_ADDR(base) ((base) + (0xC90))
#define SOC_NPUCRG_MON_STAT20_NPU_ADDR(base) ((base) + (0xC94))
#define SOC_NPUCRG_MON_STAT21_NPU_ADDR(base) ((base) + (0xC98))
#define SOC_NPUCRG_MON_STAT22_NPU_ADDR(base) ((base) + (0xCA0))
#define SOC_NPUCRG_MON_STAT23_NPU_ADDR(base) ((base) + (0xCA4))
#define SOC_NPUCRG_MON_STAT24_NPU_ADDR(base) ((base) + (0xCA8))
#define SOC_NPUCRG_MON_STAT25_NPU_ADDR(base) ((base) + (0xCAC))
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_ADDR(base) ((base) + (0xD00))
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_ADDR(base) ((base) + (0xD04))
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_ADDR(base) ((base) + (0xD08))
#define SOC_NPUCRG_PLL_FSM_CTRL0_ADDR(base) ((base) + (0xD10))
#define SOC_NPUCRG_PLL_FSM_CTRL1_ADDR(base) ((base) + (0xD14))
#define SOC_NPUCRG_PLL_FSM_STAT_ADDR(base) ((base) + (0xD18))
#define SOC_NPUCRG_FCG_ANA_CFG0_AICORE_ADDR(base) ((base) + (0xE00))
#define SOC_NPUCRG_FCG_ANA_CFG1_AICORE_ADDR(base) ((base) + (0xE04))
#define SOC_NPUCRG_FCG_ANA_CFG2_AICORE_ADDR(base) ((base) + (0xE08))
#define SOC_NPUCRG_FCG_ANA_CFG3_AICORE_ADDR(base) ((base) + (0xE0C))
#define SOC_NPUCRG_FCG_CFG0_AICORE_ADDR(base) ((base) + (0xE18))
#define SOC_NPUCRG_FCG_CFG1_AICORE_ADDR(base) ((base) + (0xE1C))
#define SOC_NPUCRG_FCG_CFG2_AICORE_ADDR(base) ((base) + (0xE20))
#define SOC_NPUCRG_FCG_CFG3_AICORE_ADDR(base) ((base) + (0xE24))
#define SOC_NPUCRG_FCG_CFG4_AICORE_ADDR(base) ((base) + (0xE28))
#define SOC_NPUCRG_FCG_CFG5_AICORE_ADDR(base) ((base) + (0xE2C))
#define SOC_NPUCRG_FCG_CFG6_AICORE_ADDR(base) ((base) + (0xE30))
#define SOC_NPUCRG_FCG_CFG7_AICORE_ADDR(base) ((base) + (0xE34))
#define SOC_NPUCRG_FCG_CFG8_AICORE_ADDR(base) ((base) + (0xE38))
#define SOC_NPUCRG_FCG_CFG9_AICORE_ADDR(base) ((base) + (0xE3C))
#define SOC_NPUCRG_FCG_CFG10_AICORE_ADDR(base) ((base) + (0xE40))
#define SOC_NPUCRG_FCG_CFG11_AICORE_ADDR(base) ((base) + (0xE44))
#define SOC_NPUCRG_FCG_CFG12_AICORE_ADDR(base) ((base) + (0xE48))
#define SOC_NPUCRG_FCG_CFG13_AICORE_ADDR(base) ((base) + (0xE4C))
#define SOC_NPUCRG_FCG_CFG14_AICORE_ADDR(base) ((base) + (0xE50))
#define SOC_NPUCRG_FCG_CFG15_AICORE_ADDR(base) ((base) + (0xE54))
#define SOC_NPUCRG_FCG_CFG16_AICORE_ADDR(base) ((base) + (0xE58))
#define SOC_NPUCRG_FCG_CFG17_AICORE_ADDR(base) ((base) + (0xE5C))
#define SOC_NPUCRG_FCG_CFG18_AICORE_ADDR(base) ((base) + (0xE60))
#define SOC_NPUCRG_FCG_CFG19_AICORE_ADDR(base) ((base) + (0xE64))
#define SOC_NPUCRG_FCG_CFG20_AICORE_ADDR(base) ((base) + (0xE68))
#define SOC_NPUCRG_FCG_CFG21_AICORE_ADDR(base) ((base) + (0xE6C))
#define SOC_NPUCRG_FCG_CFG22_AICORE_ADDR(base) ((base) + (0xE70))
#define SOC_NPUCRG_FCG_CFG23_AICORE_ADDR(base) ((base) + (0xE74))
#define SOC_NPUCRG_FCG_CFG24_AICORE_ADDR(base) ((base) + (0xE78))
#define SOC_NPUCRG_FCG_CFG25_AICORE_ADDR(base) ((base) + (0xE7C))
#define SOC_NPUCRG_FCG_CFG26_AICORE_ADDR(base) ((base) + (0xE80))
#define SOC_NPUCRG_FCG_CFG27_AICORE_ADDR(base) ((base) + (0xE84))
#define SOC_NPUCRG_FCG_STAT0_AICORE_ADDR(base) ((base) + (0xE90))
#define SOC_NPUCRG_FCG_STAT1_AICORE_ADDR(base) ((base) + (0xE94))
#define SOC_NPUCRG_FCG_STAT2_AICORE_ADDR(base) ((base) + (0xE98))
#define SOC_NPUCRG_FCG_STAT3_AICORE_ADDR(base) ((base) + (0xE9C))
#define SOC_NPUCRG_FCG_STAT4_AICORE_ADDR(base) ((base) + (0xEA0))
#define SOC_NPUCRG_FCG_STAT5_AICORE_ADDR(base) ((base) + (0xEA4))
#define SOC_NPUCRG_IPSIGMASK_ADDR(base) ((base) + (0x700))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_ns_en_vote_aicore : 5;
        unsigned int reserved : 11;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_PLL_FSM_NS_VOTE0_UNION;
#endif
#define SOC_NPUCRG_PLL_FSM_NS_VOTE0_fcg_ns_en_vote_aicore_START (0)
#define SOC_NPUCRG_PLL_FSM_NS_VOTE0_fcg_ns_en_vote_aicore_END (4)
#define SOC_NPUCRG_PLL_FSM_NS_VOTE0_bitmasken_START (16)
#define SOC_NPUCRG_PLL_FSM_NS_VOTE0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_fsm_wsat : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPUCRG_PLL_FSM_NS_STAT_UNION;
#endif
#define SOC_NPUCRG_PLL_FSM_NS_STAT_pll_fsm_wsat_START (0)
#define SOC_NPUCRG_PLL_FSM_NS_STAT_pll_fsm_wsat_END (0)
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
        unsigned int gt_clk_npu_pa : 1;
        unsigned int gt_clk_fdcs_monitor : 1;
        unsigned int gt_pclk_ts_apb : 1;
        unsigned int gt_pclk_ts_apb_83m : 1;
        unsigned int gt_pclk_easc1_cfg : 1;
        unsigned int gt_pclk_easc0_cfg : 1;
        unsigned int gt_pclk_npu_dmmu : 1;
        unsigned int gt_pclk_aicore_smmu : 1;
        unsigned int gt_pclk_npu_tcu : 1;
        unsigned int gt_pclk_fcg_aicore : 1;
        unsigned int gt_pclk_npu_dpm0 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_pclk_aicore_pdc : 1;
        unsigned int gt_pclk_npu_hw_exp_irq_ns : 1;
        unsigned int gt_pclk_npu_hw_exp_irq : 1;
        unsigned int gt_pclk_npu_uart : 1;
        unsigned int gt_pclk_npu_pcr : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_npu_hpm : 1;
        unsigned int gt_clk_aicore0_hpm : 1;
        unsigned int gt_pclk_atgm : 1;
    } reg;
} SOC_NPUCRG_PEREN0_UNION;
#endif
#define SOC_NPUCRG_PEREN0_gt_clk_npu_pa_START (10)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_pa_END (10)
#define SOC_NPUCRG_PEREN0_gt_clk_fdcs_monitor_START (11)
#define SOC_NPUCRG_PEREN0_gt_clk_fdcs_monitor_END (11)
#define SOC_NPUCRG_PEREN0_gt_pclk_ts_apb_START (12)
#define SOC_NPUCRG_PEREN0_gt_pclk_ts_apb_END (12)
#define SOC_NPUCRG_PEREN0_gt_pclk_ts_apb_83m_START (13)
#define SOC_NPUCRG_PEREN0_gt_pclk_ts_apb_83m_END (13)
#define SOC_NPUCRG_PEREN0_gt_pclk_easc1_cfg_START (14)
#define SOC_NPUCRG_PEREN0_gt_pclk_easc1_cfg_END (14)
#define SOC_NPUCRG_PEREN0_gt_pclk_easc0_cfg_START (15)
#define SOC_NPUCRG_PEREN0_gt_pclk_easc0_cfg_END (15)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_dmmu_START (16)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_dmmu_END (16)
#define SOC_NPUCRG_PEREN0_gt_pclk_aicore_smmu_START (17)
#define SOC_NPUCRG_PEREN0_gt_pclk_aicore_smmu_END (17)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_tcu_START (18)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_tcu_END (18)
#define SOC_NPUCRG_PEREN0_gt_pclk_fcg_aicore_START (19)
#define SOC_NPUCRG_PEREN0_gt_pclk_fcg_aicore_END (19)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_dpm0_START (20)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_dpm0_END (20)
#define SOC_NPUCRG_PEREN0_gt_pclk_aicore_pdc_START (23)
#define SOC_NPUCRG_PEREN0_gt_pclk_aicore_pdc_END (23)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_hw_exp_irq_ns_START (24)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_hw_exp_irq_ns_END (24)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_hw_exp_irq_START (25)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_hw_exp_irq_END (25)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_uart_START (26)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_uart_END (26)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_pcr_START (27)
#define SOC_NPUCRG_PEREN0_gt_pclk_npu_pcr_END (27)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_hpm_START (29)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_hpm_END (29)
#define SOC_NPUCRG_PEREN0_gt_clk_aicore0_hpm_START (30)
#define SOC_NPUCRG_PEREN0_gt_clk_aicore0_hpm_END (30)
#define SOC_NPUCRG_PEREN0_gt_pclk_atgm_START (31)
#define SOC_NPUCRG_PEREN0_gt_pclk_atgm_END (31)
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
        unsigned int gt_clk_npu_pa : 1;
        unsigned int gt_clk_fdcs_monitor : 1;
        unsigned int gt_pclk_ts_apb : 1;
        unsigned int gt_pclk_ts_apb_83m : 1;
        unsigned int gt_pclk_easc1_cfg : 1;
        unsigned int gt_pclk_easc0_cfg : 1;
        unsigned int gt_pclk_npu_dmmu : 1;
        unsigned int gt_pclk_aicore_smmu : 1;
        unsigned int gt_pclk_npu_tcu : 1;
        unsigned int gt_pclk_fcg_aicore : 1;
        unsigned int gt_pclk_npu_dpm0 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_pclk_aicore_pdc : 1;
        unsigned int gt_pclk_npu_hw_exp_irq_ns : 1;
        unsigned int gt_pclk_npu_hw_exp_irq : 1;
        unsigned int gt_pclk_npu_uart : 1;
        unsigned int gt_pclk_npu_pcr : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_npu_hpm : 1;
        unsigned int gt_clk_aicore0_hpm : 1;
        unsigned int gt_pclk_atgm : 1;
    } reg;
} SOC_NPUCRG_PERDIS0_UNION;
#endif
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_pa_START (10)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_pa_END (10)
#define SOC_NPUCRG_PERDIS0_gt_clk_fdcs_monitor_START (11)
#define SOC_NPUCRG_PERDIS0_gt_clk_fdcs_monitor_END (11)
#define SOC_NPUCRG_PERDIS0_gt_pclk_ts_apb_START (12)
#define SOC_NPUCRG_PERDIS0_gt_pclk_ts_apb_END (12)
#define SOC_NPUCRG_PERDIS0_gt_pclk_ts_apb_83m_START (13)
#define SOC_NPUCRG_PERDIS0_gt_pclk_ts_apb_83m_END (13)
#define SOC_NPUCRG_PERDIS0_gt_pclk_easc1_cfg_START (14)
#define SOC_NPUCRG_PERDIS0_gt_pclk_easc1_cfg_END (14)
#define SOC_NPUCRG_PERDIS0_gt_pclk_easc0_cfg_START (15)
#define SOC_NPUCRG_PERDIS0_gt_pclk_easc0_cfg_END (15)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_dmmu_START (16)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_dmmu_END (16)
#define SOC_NPUCRG_PERDIS0_gt_pclk_aicore_smmu_START (17)
#define SOC_NPUCRG_PERDIS0_gt_pclk_aicore_smmu_END (17)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_tcu_START (18)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_tcu_END (18)
#define SOC_NPUCRG_PERDIS0_gt_pclk_fcg_aicore_START (19)
#define SOC_NPUCRG_PERDIS0_gt_pclk_fcg_aicore_END (19)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_dpm0_START (20)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_dpm0_END (20)
#define SOC_NPUCRG_PERDIS0_gt_pclk_aicore_pdc_START (23)
#define SOC_NPUCRG_PERDIS0_gt_pclk_aicore_pdc_END (23)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_hw_exp_irq_ns_START (24)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_hw_exp_irq_ns_END (24)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_hw_exp_irq_START (25)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_hw_exp_irq_END (25)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_uart_START (26)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_uart_END (26)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_pcr_START (27)
#define SOC_NPUCRG_PERDIS0_gt_pclk_npu_pcr_END (27)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_hpm_START (29)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_hpm_END (29)
#define SOC_NPUCRG_PERDIS0_gt_clk_aicore0_hpm_START (30)
#define SOC_NPUCRG_PERDIS0_gt_clk_aicore0_hpm_END (30)
#define SOC_NPUCRG_PERDIS0_gt_pclk_atgm_START (31)
#define SOC_NPUCRG_PERDIS0_gt_pclk_atgm_END (31)
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
        unsigned int gt_clk_npu_pa : 1;
        unsigned int gt_clk_fdcs_monitor : 1;
        unsigned int gt_pclk_ts_apb : 1;
        unsigned int gt_pclk_ts_apb_83m : 1;
        unsigned int gt_pclk_easc1_cfg : 1;
        unsigned int gt_pclk_easc0_cfg : 1;
        unsigned int gt_pclk_npu_dmmu : 1;
        unsigned int gt_pclk_aicore_smmu : 1;
        unsigned int gt_pclk_npu_tcu : 1;
        unsigned int gt_pclk_fcg_aicore : 1;
        unsigned int gt_pclk_npu_dpm0 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_pclk_aicore_pdc : 1;
        unsigned int gt_pclk_npu_hw_exp_irq_ns : 1;
        unsigned int gt_pclk_npu_hw_exp_irq : 1;
        unsigned int gt_pclk_npu_uart : 1;
        unsigned int gt_pclk_npu_pcr : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_npu_hpm : 1;
        unsigned int gt_clk_aicore0_hpm : 1;
        unsigned int gt_pclk_atgm : 1;
    } reg;
} SOC_NPUCRG_PERCLKEN0_UNION;
#endif
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_pa_START (10)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_pa_END (10)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fdcs_monitor_START (11)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fdcs_monitor_END (11)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_ts_apb_START (12)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_ts_apb_END (12)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_ts_apb_83m_START (13)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_ts_apb_83m_END (13)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_easc1_cfg_START (14)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_easc1_cfg_END (14)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_easc0_cfg_START (15)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_easc0_cfg_END (15)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_dmmu_START (16)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_dmmu_END (16)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_aicore_smmu_START (17)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_aicore_smmu_END (17)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_tcu_START (18)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_tcu_END (18)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_fcg_aicore_START (19)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_fcg_aicore_END (19)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_dpm0_START (20)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_dpm0_END (20)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_aicore_pdc_START (23)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_aicore_pdc_END (23)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_hw_exp_irq_ns_START (24)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_hw_exp_irq_ns_END (24)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_hw_exp_irq_START (25)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_hw_exp_irq_END (25)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_uart_START (26)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_uart_END (26)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_pcr_START (27)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_npu_pcr_END (27)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_hpm_START (29)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_hpm_END (29)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_aicore0_hpm_START (30)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_aicore0_hpm_END (30)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_atgm_START (31)
#define SOC_NPUCRG_PERCLKEN0_gt_pclk_atgm_END (31)
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
        unsigned int st_clk_npu_pa : 1;
        unsigned int st_clk_fdcs_monitor : 1;
        unsigned int st_pclk_ts_apb : 1;
        unsigned int st_pclk_ts_apb_83m : 1;
        unsigned int st_pclk_easc1_cfg : 1;
        unsigned int st_pclk_easc0_cfg : 1;
        unsigned int st_pclk_npu_dmmu : 1;
        unsigned int st_pclk_aicore_smmu : 1;
        unsigned int st_pclk_npu_tcu : 1;
        unsigned int st_pclk_fcg_aicore : 1;
        unsigned int st_pclk_npu_dpm0 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int st_pclk_aicore_pdc : 1;
        unsigned int st_pclk_npu_hw_exp_irq_ns : 1;
        unsigned int st_pclk_npu_hw_exp_irq : 1;
        unsigned int st_pclk_npu_uart : 1;
        unsigned int st_pclk_npu_pcr : 1;
        unsigned int reserved_12 : 1;
        unsigned int st_clk_npu_hpm : 1;
        unsigned int st_clk_aicore0_hpm : 1;
        unsigned int st_pclk_atgm : 1;
    } reg;
} SOC_NPUCRG_PERSTAT0_UNION;
#endif
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_pa_START (10)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_pa_END (10)
#define SOC_NPUCRG_PERSTAT0_st_clk_fdcs_monitor_START (11)
#define SOC_NPUCRG_PERSTAT0_st_clk_fdcs_monitor_END (11)
#define SOC_NPUCRG_PERSTAT0_st_pclk_ts_apb_START (12)
#define SOC_NPUCRG_PERSTAT0_st_pclk_ts_apb_END (12)
#define SOC_NPUCRG_PERSTAT0_st_pclk_ts_apb_83m_START (13)
#define SOC_NPUCRG_PERSTAT0_st_pclk_ts_apb_83m_END (13)
#define SOC_NPUCRG_PERSTAT0_st_pclk_easc1_cfg_START (14)
#define SOC_NPUCRG_PERSTAT0_st_pclk_easc1_cfg_END (14)
#define SOC_NPUCRG_PERSTAT0_st_pclk_easc0_cfg_START (15)
#define SOC_NPUCRG_PERSTAT0_st_pclk_easc0_cfg_END (15)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_dmmu_START (16)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_dmmu_END (16)
#define SOC_NPUCRG_PERSTAT0_st_pclk_aicore_smmu_START (17)
#define SOC_NPUCRG_PERSTAT0_st_pclk_aicore_smmu_END (17)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_tcu_START (18)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_tcu_END (18)
#define SOC_NPUCRG_PERSTAT0_st_pclk_fcg_aicore_START (19)
#define SOC_NPUCRG_PERSTAT0_st_pclk_fcg_aicore_END (19)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_dpm0_START (20)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_dpm0_END (20)
#define SOC_NPUCRG_PERSTAT0_st_pclk_aicore_pdc_START (23)
#define SOC_NPUCRG_PERSTAT0_st_pclk_aicore_pdc_END (23)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_hw_exp_irq_ns_START (24)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_hw_exp_irq_ns_END (24)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_hw_exp_irq_START (25)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_hw_exp_irq_END (25)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_uart_START (26)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_uart_END (26)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_pcr_START (27)
#define SOC_NPUCRG_PERSTAT0_st_pclk_npu_pcr_END (27)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_hpm_START (29)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_hpm_END (29)
#define SOC_NPUCRG_PERSTAT0_st_clk_aicore0_hpm_START (30)
#define SOC_NPUCRG_PERSTAT0_st_clk_aicore0_hpm_END (30)
#define SOC_NPUCRG_PERSTAT0_st_pclk_atgm_START (31)
#define SOC_NPUCRG_PERSTAT0_st_pclk_atgm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_aicore_eff : 1;
        unsigned int gt_clk_aicore_gen : 1;
        unsigned int gt_clk_ts_hwts_lite : 1;
        unsigned int gt_clk_qice_npu_cfg : 1;
        unsigned int gt_clk_aicore_eff1 : 1;
        unsigned int gt_clk_ai_core0_root_gt : 1;
        unsigned int gt_clk_qice_npu_data : 1;
        unsigned int gt_clk_ppll5_npu_tp : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_qic_tcu : 1;
        unsigned int gt_clk_npu_tcu : 1;
        unsigned int gt_pclk_dmmu_ts_cfg : 1;
        unsigned int gt_clk_ts_doorbell : 1;
        unsigned int gt_clk_aicore_smmu : 1;
        unsigned int gt_clk_himinibus : 1;
        unsigned int gt_clk_npu_easc1 : 1;
        unsigned int gt_clk_npu_easc0 : 1;
        unsigned int gt_clk_ts_ffap1_tscpu : 1;
        unsigned int gt_clk_aicore_tbu2tcu : 1;
        unsigned int gt_pclkdbg_ts_cpu : 1;
        unsigned int gt_clk_ts_qic_riscv : 1;
        unsigned int gt_clk_tscpu_tbu2tcu : 1;
        unsigned int gt_clk_ts_hts_adpt : 1;
        unsigned int gt_clk_ts_ffap1 : 1;
        unsigned int gt_clk_ts_smmu : 1;
        unsigned int gt_clk_ts_hwts_tiny : 1;
        unsigned int gt_clk_ts_qic_bus : 1;
        unsigned int gt_clk_qic_ts : 1;
        unsigned int gt_clk_ts_cpu : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_clk_dw_dbg : 1;
        unsigned int gt_clk_npu_timer : 1;
    } reg;
} SOC_NPUCRG_PEREN1_UNION;
#endif
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_eff_START (0)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_eff_END (0)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_gen_START (1)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_gen_END (1)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_hwts_lite_START (2)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_hwts_lite_END (2)
#define SOC_NPUCRG_PEREN1_gt_clk_qice_npu_cfg_START (3)
#define SOC_NPUCRG_PEREN1_gt_clk_qice_npu_cfg_END (3)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_eff1_START (4)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_eff1_END (4)
#define SOC_NPUCRG_PEREN1_gt_clk_ai_core0_root_gt_START (5)
#define SOC_NPUCRG_PEREN1_gt_clk_ai_core0_root_gt_END (5)
#define SOC_NPUCRG_PEREN1_gt_clk_qice_npu_data_START (6)
#define SOC_NPUCRG_PEREN1_gt_clk_qice_npu_data_END (6)
#define SOC_NPUCRG_PEREN1_gt_clk_ppll5_npu_tp_START (7)
#define SOC_NPUCRG_PEREN1_gt_clk_ppll5_npu_tp_END (7)
#define SOC_NPUCRG_PEREN1_gt_clk_qic_tcu_START (9)
#define SOC_NPUCRG_PEREN1_gt_clk_qic_tcu_END (9)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_tcu_START (10)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_tcu_END (10)
#define SOC_NPUCRG_PEREN1_gt_pclk_dmmu_ts_cfg_START (11)
#define SOC_NPUCRG_PEREN1_gt_pclk_dmmu_ts_cfg_END (11)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_doorbell_START (12)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_doorbell_END (12)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_smmu_START (13)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_smmu_END (13)
#define SOC_NPUCRG_PEREN1_gt_clk_himinibus_START (14)
#define SOC_NPUCRG_PEREN1_gt_clk_himinibus_END (14)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_easc1_START (15)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_easc1_END (15)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_easc0_START (16)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_easc0_END (16)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_ffap1_tscpu_START (17)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_ffap1_tscpu_END (17)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_tbu2tcu_START (18)
#define SOC_NPUCRG_PEREN1_gt_clk_aicore_tbu2tcu_END (18)
#define SOC_NPUCRG_PEREN1_gt_pclkdbg_ts_cpu_START (19)
#define SOC_NPUCRG_PEREN1_gt_pclkdbg_ts_cpu_END (19)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_qic_riscv_START (20)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_qic_riscv_END (20)
#define SOC_NPUCRG_PEREN1_gt_clk_tscpu_tbu2tcu_START (21)
#define SOC_NPUCRG_PEREN1_gt_clk_tscpu_tbu2tcu_END (21)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_hts_adpt_START (22)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_hts_adpt_END (22)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_ffap1_START (23)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_ffap1_END (23)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_smmu_START (24)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_smmu_END (24)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_hwts_tiny_START (25)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_hwts_tiny_END (25)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_qic_bus_START (26)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_qic_bus_END (26)
#define SOC_NPUCRG_PEREN1_gt_clk_qic_ts_START (27)
#define SOC_NPUCRG_PEREN1_gt_clk_qic_ts_END (27)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_cpu_START (28)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_cpu_END (28)
#define SOC_NPUCRG_PEREN1_gt_clk_pll_fsm_START (29)
#define SOC_NPUCRG_PEREN1_gt_clk_pll_fsm_END (29)
#define SOC_NPUCRG_PEREN1_gt_clk_dw_dbg_START (30)
#define SOC_NPUCRG_PEREN1_gt_clk_dw_dbg_END (30)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_timer_START (31)
#define SOC_NPUCRG_PEREN1_gt_clk_npu_timer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_aicore_eff : 1;
        unsigned int gt_clk_aicore_gen : 1;
        unsigned int gt_clk_ts_hwts_lite : 1;
        unsigned int gt_clk_qice_npu_cfg : 1;
        unsigned int gt_clk_aicore_eff1 : 1;
        unsigned int gt_clk_ai_core0_root_gt : 1;
        unsigned int gt_clk_qice_npu_data : 1;
        unsigned int gt_clk_ppll5_npu_tp : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_qic_tcu : 1;
        unsigned int gt_clk_npu_tcu : 1;
        unsigned int gt_pclk_dmmu_ts_cfg : 1;
        unsigned int gt_clk_ts_doorbell : 1;
        unsigned int gt_clk_aicore_smmu : 1;
        unsigned int gt_clk_himinibus : 1;
        unsigned int gt_clk_npu_easc1 : 1;
        unsigned int gt_clk_npu_easc0 : 1;
        unsigned int gt_clk_ts_ffap1_tscpu : 1;
        unsigned int gt_clk_aicore_tbu2tcu : 1;
        unsigned int gt_pclkdbg_ts_cpu : 1;
        unsigned int gt_clk_ts_qic_riscv : 1;
        unsigned int gt_clk_tscpu_tbu2tcu : 1;
        unsigned int gt_clk_ts_hts_adpt : 1;
        unsigned int gt_clk_ts_ffap1 : 1;
        unsigned int gt_clk_ts_smmu : 1;
        unsigned int gt_clk_ts_hwts_tiny : 1;
        unsigned int gt_clk_ts_qic_bus : 1;
        unsigned int gt_clk_qic_ts : 1;
        unsigned int gt_clk_ts_cpu : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_clk_dw_dbg : 1;
        unsigned int gt_clk_npu_timer : 1;
    } reg;
} SOC_NPUCRG_PERDIS1_UNION;
#endif
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_eff_START (0)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_eff_END (0)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_gen_START (1)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_gen_END (1)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_hwts_lite_START (2)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_hwts_lite_END (2)
#define SOC_NPUCRG_PERDIS1_gt_clk_qice_npu_cfg_START (3)
#define SOC_NPUCRG_PERDIS1_gt_clk_qice_npu_cfg_END (3)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_eff1_START (4)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_eff1_END (4)
#define SOC_NPUCRG_PERDIS1_gt_clk_ai_core0_root_gt_START (5)
#define SOC_NPUCRG_PERDIS1_gt_clk_ai_core0_root_gt_END (5)
#define SOC_NPUCRG_PERDIS1_gt_clk_qice_npu_data_START (6)
#define SOC_NPUCRG_PERDIS1_gt_clk_qice_npu_data_END (6)
#define SOC_NPUCRG_PERDIS1_gt_clk_ppll5_npu_tp_START (7)
#define SOC_NPUCRG_PERDIS1_gt_clk_ppll5_npu_tp_END (7)
#define SOC_NPUCRG_PERDIS1_gt_clk_qic_tcu_START (9)
#define SOC_NPUCRG_PERDIS1_gt_clk_qic_tcu_END (9)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_tcu_START (10)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_tcu_END (10)
#define SOC_NPUCRG_PERDIS1_gt_pclk_dmmu_ts_cfg_START (11)
#define SOC_NPUCRG_PERDIS1_gt_pclk_dmmu_ts_cfg_END (11)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_doorbell_START (12)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_doorbell_END (12)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_smmu_START (13)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_smmu_END (13)
#define SOC_NPUCRG_PERDIS1_gt_clk_himinibus_START (14)
#define SOC_NPUCRG_PERDIS1_gt_clk_himinibus_END (14)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_easc1_START (15)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_easc1_END (15)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_easc0_START (16)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_easc0_END (16)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_ffap1_tscpu_START (17)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_ffap1_tscpu_END (17)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_tbu2tcu_START (18)
#define SOC_NPUCRG_PERDIS1_gt_clk_aicore_tbu2tcu_END (18)
#define SOC_NPUCRG_PERDIS1_gt_pclkdbg_ts_cpu_START (19)
#define SOC_NPUCRG_PERDIS1_gt_pclkdbg_ts_cpu_END (19)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_qic_riscv_START (20)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_qic_riscv_END (20)
#define SOC_NPUCRG_PERDIS1_gt_clk_tscpu_tbu2tcu_START (21)
#define SOC_NPUCRG_PERDIS1_gt_clk_tscpu_tbu2tcu_END (21)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_hts_adpt_START (22)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_hts_adpt_END (22)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_ffap1_START (23)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_ffap1_END (23)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_smmu_START (24)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_smmu_END (24)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_hwts_tiny_START (25)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_hwts_tiny_END (25)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_qic_bus_START (26)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_qic_bus_END (26)
#define SOC_NPUCRG_PERDIS1_gt_clk_qic_ts_START (27)
#define SOC_NPUCRG_PERDIS1_gt_clk_qic_ts_END (27)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_cpu_START (28)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_cpu_END (28)
#define SOC_NPUCRG_PERDIS1_gt_clk_pll_fsm_START (29)
#define SOC_NPUCRG_PERDIS1_gt_clk_pll_fsm_END (29)
#define SOC_NPUCRG_PERDIS1_gt_clk_dw_dbg_START (30)
#define SOC_NPUCRG_PERDIS1_gt_clk_dw_dbg_END (30)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_timer_START (31)
#define SOC_NPUCRG_PERDIS1_gt_clk_npu_timer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_aicore_eff : 1;
        unsigned int gt_clk_aicore_gen : 1;
        unsigned int gt_clk_ts_hwts_lite : 1;
        unsigned int gt_clk_qice_npu_cfg : 1;
        unsigned int gt_clk_aicore_eff1 : 1;
        unsigned int gt_clk_ai_core0_root_gt : 1;
        unsigned int gt_clk_qice_npu_data : 1;
        unsigned int gt_clk_ppll5_npu_tp : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_qic_tcu : 1;
        unsigned int gt_clk_npu_tcu : 1;
        unsigned int gt_pclk_dmmu_ts_cfg : 1;
        unsigned int gt_clk_ts_doorbell : 1;
        unsigned int gt_clk_aicore_smmu : 1;
        unsigned int gt_clk_himinibus : 1;
        unsigned int gt_clk_npu_easc1 : 1;
        unsigned int gt_clk_npu_easc0 : 1;
        unsigned int gt_clk_ts_ffap1_tscpu : 1;
        unsigned int gt_clk_aicore_tbu2tcu : 1;
        unsigned int gt_pclkdbg_ts_cpu : 1;
        unsigned int gt_clk_ts_qic_riscv : 1;
        unsigned int gt_clk_tscpu_tbu2tcu : 1;
        unsigned int gt_clk_ts_hts_adpt : 1;
        unsigned int gt_clk_ts_ffap1 : 1;
        unsigned int gt_clk_ts_smmu : 1;
        unsigned int gt_clk_ts_hwts_tiny : 1;
        unsigned int gt_clk_ts_qic_bus : 1;
        unsigned int gt_clk_qic_ts : 1;
        unsigned int gt_clk_ts_cpu : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_clk_dw_dbg : 1;
        unsigned int gt_clk_npu_timer : 1;
    } reg;
} SOC_NPUCRG_PERCLKEN1_UNION;
#endif
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_eff_START (0)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_eff_END (0)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_gen_START (1)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_gen_END (1)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_hwts_lite_START (2)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_hwts_lite_END (2)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qice_npu_cfg_START (3)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qice_npu_cfg_END (3)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_eff1_START (4)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_eff1_END (4)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ai_core0_root_gt_START (5)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ai_core0_root_gt_END (5)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qice_npu_data_START (6)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qice_npu_data_END (6)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ppll5_npu_tp_START (7)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ppll5_npu_tp_END (7)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qic_tcu_START (9)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qic_tcu_END (9)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_tcu_START (10)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_tcu_END (10)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_dmmu_ts_cfg_START (11)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_dmmu_ts_cfg_END (11)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_doorbell_START (12)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_doorbell_END (12)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_smmu_START (13)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_smmu_END (13)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_himinibus_START (14)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_himinibus_END (14)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_easc1_START (15)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_easc1_END (15)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_easc0_START (16)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_easc0_END (16)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_ffap1_tscpu_START (17)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_ffap1_tscpu_END (17)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_tbu2tcu_START (18)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_aicore_tbu2tcu_END (18)
#define SOC_NPUCRG_PERCLKEN1_gt_pclkdbg_ts_cpu_START (19)
#define SOC_NPUCRG_PERCLKEN1_gt_pclkdbg_ts_cpu_END (19)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_qic_riscv_START (20)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_qic_riscv_END (20)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_tscpu_tbu2tcu_START (21)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_tscpu_tbu2tcu_END (21)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_hts_adpt_START (22)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_hts_adpt_END (22)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_ffap1_START (23)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_ffap1_END (23)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_smmu_START (24)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_smmu_END (24)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_hwts_tiny_START (25)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_hwts_tiny_END (25)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_qic_bus_START (26)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_qic_bus_END (26)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qic_ts_START (27)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_qic_ts_END (27)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_cpu_START (28)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_cpu_END (28)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_pll_fsm_START (29)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_pll_fsm_END (29)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_dw_dbg_START (30)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_dw_dbg_END (30)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_timer_START (31)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npu_timer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_qice_npu_cfg : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_ai_core0_root_gt : 1;
        unsigned int st_clk_qice_npu_data : 1;
        unsigned int st_clk_ppll5_npu_tp : 1;
        unsigned int st_clk_ppll5_gt : 1;
        unsigned int st_clk_qic_tcu : 1;
        unsigned int st_clk_npu_tcu : 1;
        unsigned int st_pclk_dmmu_ts_cfg : 1;
        unsigned int st_clk_ts_doorbell : 1;
        unsigned int st_clk_aicore_smmu : 1;
        unsigned int st_clk_himinibus : 1;
        unsigned int st_clk_npu_easc1 : 1;
        unsigned int st_clk_npu_easc0 : 1;
        unsigned int st_clk_ts_ffap1_tscpu : 1;
        unsigned int st_clk_aicore_tbu2tcu : 1;
        unsigned int st_pclkdbg_ts_cpu : 1;
        unsigned int st_clk_ts_qic_riscv : 1;
        unsigned int st_clk_tscpu_tbu2tcu : 1;
        unsigned int st_clk_ts_hts_adpt : 1;
        unsigned int st_clk_ts_ffap1 : 1;
        unsigned int st_clk_ts_smmu : 1;
        unsigned int st_clk_ts_hwts : 1;
        unsigned int st_clk_ts_qic_bus : 1;
        unsigned int st_clk_qic_ts : 1;
        unsigned int st_clk_ts_cpu : 1;
        unsigned int st_clk_pll_fsm : 1;
        unsigned int st_clk_dw_dbg : 1;
        unsigned int st_clk_npu_timer : 1;
    } reg;
} SOC_NPUCRG_PERSTAT1_UNION;
#endif
#define SOC_NPUCRG_PERSTAT1_st_clk_qice_npu_cfg_START (3)
#define SOC_NPUCRG_PERSTAT1_st_clk_qice_npu_cfg_END (3)
#define SOC_NPUCRG_PERSTAT1_st_clk_ai_core0_root_gt_START (5)
#define SOC_NPUCRG_PERSTAT1_st_clk_ai_core0_root_gt_END (5)
#define SOC_NPUCRG_PERSTAT1_st_clk_qice_npu_data_START (6)
#define SOC_NPUCRG_PERSTAT1_st_clk_qice_npu_data_END (6)
#define SOC_NPUCRG_PERSTAT1_st_clk_ppll5_npu_tp_START (7)
#define SOC_NPUCRG_PERSTAT1_st_clk_ppll5_npu_tp_END (7)
#define SOC_NPUCRG_PERSTAT1_st_clk_ppll5_gt_START (8)
#define SOC_NPUCRG_PERSTAT1_st_clk_ppll5_gt_END (8)
#define SOC_NPUCRG_PERSTAT1_st_clk_qic_tcu_START (9)
#define SOC_NPUCRG_PERSTAT1_st_clk_qic_tcu_END (9)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_tcu_START (10)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_tcu_END (10)
#define SOC_NPUCRG_PERSTAT1_st_pclk_dmmu_ts_cfg_START (11)
#define SOC_NPUCRG_PERSTAT1_st_pclk_dmmu_ts_cfg_END (11)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_doorbell_START (12)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_doorbell_END (12)
#define SOC_NPUCRG_PERSTAT1_st_clk_aicore_smmu_START (13)
#define SOC_NPUCRG_PERSTAT1_st_clk_aicore_smmu_END (13)
#define SOC_NPUCRG_PERSTAT1_st_clk_himinibus_START (14)
#define SOC_NPUCRG_PERSTAT1_st_clk_himinibus_END (14)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_easc1_START (15)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_easc1_END (15)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_easc0_START (16)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_easc0_END (16)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_ffap1_tscpu_START (17)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_ffap1_tscpu_END (17)
#define SOC_NPUCRG_PERSTAT1_st_clk_aicore_tbu2tcu_START (18)
#define SOC_NPUCRG_PERSTAT1_st_clk_aicore_tbu2tcu_END (18)
#define SOC_NPUCRG_PERSTAT1_st_pclkdbg_ts_cpu_START (19)
#define SOC_NPUCRG_PERSTAT1_st_pclkdbg_ts_cpu_END (19)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_qic_riscv_START (20)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_qic_riscv_END (20)
#define SOC_NPUCRG_PERSTAT1_st_clk_tscpu_tbu2tcu_START (21)
#define SOC_NPUCRG_PERSTAT1_st_clk_tscpu_tbu2tcu_END (21)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_hts_adpt_START (22)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_hts_adpt_END (22)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_ffap1_START (23)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_ffap1_END (23)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_smmu_START (24)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_smmu_END (24)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_hwts_START (25)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_hwts_END (25)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_qic_bus_START (26)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_qic_bus_END (26)
#define SOC_NPUCRG_PERSTAT1_st_clk_qic_ts_START (27)
#define SOC_NPUCRG_PERSTAT1_st_clk_qic_ts_END (27)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_cpu_START (28)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_cpu_END (28)
#define SOC_NPUCRG_PERSTAT1_st_clk_pll_fsm_START (29)
#define SOC_NPUCRG_PERSTAT1_st_clk_pll_fsm_END (29)
#define SOC_NPUCRG_PERSTAT1_st_clk_dw_dbg_START (30)
#define SOC_NPUCRG_PERSTAT1_st_clk_dw_dbg_END (30)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_timer_START (31)
#define SOC_NPUCRG_PERSTAT1_st_clk_npu_timer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_qic_aicore_data : 1;
        unsigned int gt_clk_qic_aicore_cfg1 : 1;
        unsigned int gt_clk_qic_aicore_cfg0 : 1;
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
        unsigned int gt_pclk_autodiv_npu_tcu : 1;
        unsigned int gt_clk_fcg_sscg_aicore : 1;
        unsigned int gt_clk_fcg_freq_ctrl_aicore : 1;
        unsigned int gt_pclk_autodiv_npubus_ts_cpu : 1;
        unsigned int gt_pclk_autodiv_npubus : 1;
        unsigned int gt_pclk_autodiv_npubus_cfg : 1;
        unsigned int gt_pclk_autodiv_npubus_aicore0 : 1;
        unsigned int reserved_10 : 12;
    } reg;
} SOC_NPUCRG_PEREN2_UNION;
#endif
#define SOC_NPUCRG_PEREN2_gt_clk_qic_aicore_data_START (0)
#define SOC_NPUCRG_PEREN2_gt_clk_qic_aicore_data_END (0)
#define SOC_NPUCRG_PEREN2_gt_clk_qic_aicore_cfg1_START (1)
#define SOC_NPUCRG_PEREN2_gt_clk_qic_aicore_cfg1_END (1)
#define SOC_NPUCRG_PEREN2_gt_clk_qic_aicore_cfg0_START (2)
#define SOC_NPUCRG_PEREN2_gt_clk_qic_aicore_cfg0_END (2)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npu_tcu_START (13)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npu_tcu_END (13)
#define SOC_NPUCRG_PEREN2_gt_clk_fcg_sscg_aicore_START (14)
#define SOC_NPUCRG_PEREN2_gt_clk_fcg_sscg_aicore_END (14)
#define SOC_NPUCRG_PEREN2_gt_clk_fcg_freq_ctrl_aicore_START (15)
#define SOC_NPUCRG_PEREN2_gt_clk_fcg_freq_ctrl_aicore_END (15)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_ts_cpu_START (16)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_ts_cpu_END (16)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_START (17)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_END (17)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_cfg_START (18)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_cfg_END (18)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_aicore0_START (19)
#define SOC_NPUCRG_PEREN2_gt_pclk_autodiv_npubus_aicore0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_qic_aicore_data : 1;
        unsigned int gt_clk_qic_aicore_cfg1 : 1;
        unsigned int gt_clk_qic_aicore_cfg0 : 1;
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
        unsigned int gt_pclk_autodiv_npu_tcu : 1;
        unsigned int gt_clk_fcg_sscg_aicore : 1;
        unsigned int gt_clk_fcg_freq_ctrl_aicore : 1;
        unsigned int gt_pclk_autodiv_npubus_ts_cpu : 1;
        unsigned int gt_pclk_autodiv_npubus : 1;
        unsigned int gt_pclk_autodiv_npubus_cfg : 1;
        unsigned int gt_pclk_autodiv_npubus_aicore0 : 1;
        unsigned int reserved_10 : 12;
    } reg;
} SOC_NPUCRG_PERDIS2_UNION;
#endif
#define SOC_NPUCRG_PERDIS2_gt_clk_qic_aicore_data_START (0)
#define SOC_NPUCRG_PERDIS2_gt_clk_qic_aicore_data_END (0)
#define SOC_NPUCRG_PERDIS2_gt_clk_qic_aicore_cfg1_START (1)
#define SOC_NPUCRG_PERDIS2_gt_clk_qic_aicore_cfg1_END (1)
#define SOC_NPUCRG_PERDIS2_gt_clk_qic_aicore_cfg0_START (2)
#define SOC_NPUCRG_PERDIS2_gt_clk_qic_aicore_cfg0_END (2)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npu_tcu_START (13)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npu_tcu_END (13)
#define SOC_NPUCRG_PERDIS2_gt_clk_fcg_sscg_aicore_START (14)
#define SOC_NPUCRG_PERDIS2_gt_clk_fcg_sscg_aicore_END (14)
#define SOC_NPUCRG_PERDIS2_gt_clk_fcg_freq_ctrl_aicore_START (15)
#define SOC_NPUCRG_PERDIS2_gt_clk_fcg_freq_ctrl_aicore_END (15)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_ts_cpu_START (16)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_ts_cpu_END (16)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_START (17)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_END (17)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_cfg_START (18)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_cfg_END (18)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_aicore0_START (19)
#define SOC_NPUCRG_PERDIS2_gt_pclk_autodiv_npubus_aicore0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_qic_aicore_data : 1;
        unsigned int gt_clk_qic_aicore_cfg1 : 1;
        unsigned int gt_clk_qic_aicore_cfg0 : 1;
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
        unsigned int gt_pclk_autodiv_npu_tcu : 1;
        unsigned int gt_clk_fcg_sscg_aicore : 1;
        unsigned int gt_clk_fcg_freq_ctrl_aicore : 1;
        unsigned int gt_pclk_autodiv_npubus_ts_cpu : 1;
        unsigned int gt_pclk_autodiv_npubus : 1;
        unsigned int gt_pclk_autodiv_npubus_cfg : 1;
        unsigned int gt_pclk_autodiv_npubus_aicore0 : 1;
        unsigned int reserved_10 : 12;
    } reg;
} SOC_NPUCRG_PERCLKEN2_UNION;
#endif
#define SOC_NPUCRG_PERCLKEN2_gt_clk_qic_aicore_data_START (0)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_qic_aicore_data_END (0)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_qic_aicore_cfg1_START (1)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_qic_aicore_cfg1_END (1)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_qic_aicore_cfg0_START (2)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_qic_aicore_cfg0_END (2)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npu_tcu_START (13)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npu_tcu_END (13)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_fcg_sscg_aicore_START (14)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_fcg_sscg_aicore_END (14)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_fcg_freq_ctrl_aicore_START (15)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_fcg_freq_ctrl_aicore_END (15)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_ts_cpu_START (16)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_ts_cpu_END (16)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_START (17)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_END (17)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_cfg_START (18)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_cfg_END (18)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_aicore0_START (19)
#define SOC_NPUCRG_PERCLKEN2_gt_pclk_autodiv_npubus_aicore0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_qic_aicore_data : 1;
        unsigned int st_clk_qic_aicore_cfg1 : 1;
        unsigned int st_clk_qic_aicore_cfg0 : 1;
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
        unsigned int st_pclk_autodiv_npu_tcu : 1;
        unsigned int st_clk_fcg_sscg_aicore : 1;
        unsigned int st_clk_fcg_freq_ctrl_aicore : 1;
        unsigned int st_pclk_autodiv_npubus_ts_cpu : 1;
        unsigned int st_pclk_autodiv_npubus : 1;
        unsigned int st_pclk_autodiv_npubus_cfg : 1;
        unsigned int st_pclk_autodiv_npubus_aicore0 : 1;
        unsigned int reserved_10 : 12;
    } reg;
} SOC_NPUCRG_PERSTAT2_UNION;
#endif
#define SOC_NPUCRG_PERSTAT2_st_clk_qic_aicore_data_START (0)
#define SOC_NPUCRG_PERSTAT2_st_clk_qic_aicore_data_END (0)
#define SOC_NPUCRG_PERSTAT2_st_clk_qic_aicore_cfg1_START (1)
#define SOC_NPUCRG_PERSTAT2_st_clk_qic_aicore_cfg1_END (1)
#define SOC_NPUCRG_PERSTAT2_st_clk_qic_aicore_cfg0_START (2)
#define SOC_NPUCRG_PERSTAT2_st_clk_qic_aicore_cfg0_END (2)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npu_tcu_START (13)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npu_tcu_END (13)
#define SOC_NPUCRG_PERSTAT2_st_clk_fcg_sscg_aicore_START (14)
#define SOC_NPUCRG_PERSTAT2_st_clk_fcg_sscg_aicore_END (14)
#define SOC_NPUCRG_PERSTAT2_st_clk_fcg_freq_ctrl_aicore_START (15)
#define SOC_NPUCRG_PERSTAT2_st_clk_fcg_freq_ctrl_aicore_END (15)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_ts_cpu_START (16)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_ts_cpu_END (16)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_START (17)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_END (17)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_cfg_START (18)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_cfg_END (18)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_aicore0_START (19)
#define SOC_NPUCRG_PERSTAT2_st_pclk_autodiv_npubus_aicore0_END (19)
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
        unsigned int reserved_26: 6;
    } reg;
} SOC_NPUCRG_PEREN3_UNION;
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
        unsigned int reserved_26: 6;
    } reg;
} SOC_NPUCRG_PERDIS3_UNION;
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
        unsigned int reserved_26: 6;
    } reg;
} SOC_NPUCRG_PERCLKEN3_UNION;
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
        unsigned int reserved_26: 6;
    } reg;
} SOC_NPUCRG_PERSTAT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_npu_pa : 1;
        unsigned int ip_rst_fdcs_monitor : 1;
        unsigned int ip_rst_aicore_eff_crg : 1;
        unsigned int ip_rst_aicore_gen_crg : 1;
        unsigned int ip_rst_aicore_crg : 1;
        unsigned int ip_rst_aicore_gen : 1;
        unsigned int ip_rst_aicore_eff : 1;
        unsigned int ip_rst_npu_timer : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_aicore_pdc : 1;
        unsigned int ip_prst_dmmu_ts_cfg : 1;
        unsigned int ip_prst_ts_apb : 1;
        unsigned int ip_prst_ts_apb_83m : 1;
        unsigned int ip_prst_npu_easc1_cfg : 1;
        unsigned int ip_prst_npu_easc0_cfg : 1;
        unsigned int ip_prst_dmmu_cfg : 1;
        unsigned int ip_prst_aicore_smmu : 1;
        unsigned int ip_prst_fcg_aicore : 1;
        unsigned int ip_prst_npu_tcu : 1;
        unsigned int ip_prst_npu_dpm0 : 1;
        unsigned int ip_rst_ts_ffap1_tscpu : 1;
        unsigned int ip_rst_aicore_eff1 : 1;
        unsigned int ip_rst_aicore_eff1_crg : 1;
        unsigned int ip_prst_npu_hw_exp_irq_ns : 1;
        unsigned int ip_prst_npu_hw_exp_irq : 1;
        unsigned int ip_prst_npu_uart : 1;
        unsigned int ip_prst_npu_pcr : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_aicore0_hpm : 1;
        unsigned int ip_rst_npu_hpm : 1;
        unsigned int ip_prst_atgm : 1;
    } reg;
} SOC_NPUCRG_PERRSTEN0_UNION;
#endif
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_pa_START (1)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_pa_END (1)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fdcs_monitor_START (2)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fdcs_monitor_END (2)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff_crg_START (3)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff_crg_END (3)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_gen_crg_START (4)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_gen_crg_END (4)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_crg_START (5)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_crg_END (5)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_gen_START (6)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_gen_END (6)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff_START (7)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff_END (7)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_timer_START (8)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_timer_END (8)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_aicore_pdc_START (10)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_aicore_pdc_END (10)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_dmmu_ts_cfg_START (11)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_dmmu_ts_cfg_END (11)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_ts_apb_START (12)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_ts_apb_END (12)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_ts_apb_83m_START (13)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_ts_apb_83m_END (13)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_easc1_cfg_START (14)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_easc1_cfg_END (14)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_easc0_cfg_START (15)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_easc0_cfg_END (15)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_dmmu_cfg_START (16)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_dmmu_cfg_END (16)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_aicore_smmu_START (17)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_aicore_smmu_END (17)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_fcg_aicore_START (18)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_fcg_aicore_END (18)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_tcu_START (19)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_tcu_END (19)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_dpm0_START (20)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_dpm0_END (20)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_ts_ffap1_tscpu_START (21)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_ts_ffap1_tscpu_END (21)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff1_START (22)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff1_END (22)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff1_crg_START (23)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_eff1_crg_END (23)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_hw_exp_irq_ns_START (24)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_hw_exp_irq_ns_END (24)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_hw_exp_irq_START (25)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_hw_exp_irq_END (25)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_uart_START (26)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_uart_END (26)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_pcr_START (27)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_npu_pcr_END (27)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore0_hpm_START (29)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore0_hpm_END (29)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_hpm_START (30)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_hpm_END (30)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_atgm_START (31)
#define SOC_NPUCRG_PERRSTEN0_ip_prst_atgm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_npu_pa : 1;
        unsigned int ip_rst_fdcs_monitor : 1;
        unsigned int ip_rst_aicore_eff_crg : 1;
        unsigned int ip_rst_aicore_gen_crg : 1;
        unsigned int ip_rst_aicore_crg : 1;
        unsigned int ip_rst_aicore_gen : 1;
        unsigned int ip_rst_aicore_eff : 1;
        unsigned int ip_rst_npu_timer : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_aicore_pdc : 1;
        unsigned int ip_prst_dmmu_ts_cfg : 1;
        unsigned int ip_prst_ts_apb : 1;
        unsigned int ip_prst_ts_apb_83m : 1;
        unsigned int ip_prst_npu_easc1_cfg : 1;
        unsigned int ip_prst_npu_easc0_cfg : 1;
        unsigned int ip_prst_dmmu_cfg : 1;
        unsigned int ip_prst_aicore_smmu : 1;
        unsigned int ip_prst_fcg_aicore : 1;
        unsigned int ip_prst_npu_tcu : 1;
        unsigned int ip_prst_npu_dpm0 : 1;
        unsigned int ip_rst_ts_ffap1_tscpu : 1;
        unsigned int ip_rst_aicore_eff1 : 1;
        unsigned int ip_rst_aicore_eff1_crg : 1;
        unsigned int ip_prst_npu_hw_exp_irq_ns : 1;
        unsigned int ip_prst_npu_hw_exp_irq : 1;
        unsigned int ip_prst_npu_uart : 1;
        unsigned int ip_prst_npu_pcr : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_aicore0_hpm : 1;
        unsigned int ip_rst_npu_hpm : 1;
        unsigned int ip_prst_atgm : 1;
    } reg;
} SOC_NPUCRG_PERRSTDIS0_UNION;
#endif
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_pa_START (1)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_pa_END (1)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fdcs_monitor_START (2)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fdcs_monitor_END (2)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff_crg_START (3)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff_crg_END (3)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_gen_crg_START (4)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_gen_crg_END (4)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_crg_START (5)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_crg_END (5)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_gen_START (6)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_gen_END (6)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff_START (7)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff_END (7)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_timer_START (8)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_timer_END (8)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_aicore_pdc_START (10)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_aicore_pdc_END (10)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_dmmu_ts_cfg_START (11)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_dmmu_ts_cfg_END (11)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_ts_apb_START (12)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_ts_apb_END (12)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_ts_apb_83m_START (13)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_ts_apb_83m_END (13)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_easc1_cfg_START (14)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_easc1_cfg_END (14)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_easc0_cfg_START (15)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_easc0_cfg_END (15)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_dmmu_cfg_START (16)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_dmmu_cfg_END (16)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_aicore_smmu_START (17)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_aicore_smmu_END (17)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_fcg_aicore_START (18)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_fcg_aicore_END (18)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_tcu_START (19)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_tcu_END (19)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_dpm0_START (20)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_dpm0_END (20)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_ts_ffap1_tscpu_START (21)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_ts_ffap1_tscpu_END (21)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff1_START (22)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff1_END (22)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff1_crg_START (23)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_eff1_crg_END (23)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_hw_exp_irq_ns_START (24)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_hw_exp_irq_ns_END (24)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_hw_exp_irq_START (25)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_hw_exp_irq_END (25)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_uart_START (26)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_uart_END (26)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_pcr_START (27)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_npu_pcr_END (27)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore0_hpm_START (29)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore0_hpm_END (29)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_hpm_START (30)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_hpm_END (30)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_atgm_START (31)
#define SOC_NPUCRG_PERRSTDIS0_ip_prst_atgm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_npu_pa : 1;
        unsigned int ip_rst_fdcs_monitor : 1;
        unsigned int ip_rst_aicore_eff_crg : 1;
        unsigned int ip_rst_aicore_gen_crg : 1;
        unsigned int ip_rst_aicore_crg : 1;
        unsigned int ip_rst_aicore_gen : 1;
        unsigned int ip_rst_aicore_eff : 1;
        unsigned int ip_rst_npu_timer : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_aicore_pdc : 1;
        unsigned int ip_prst_dmmu_ts_cfg : 1;
        unsigned int ip_prst_ts_apb : 1;
        unsigned int ip_prst_ts_apb_83m : 1;
        unsigned int ip_prst_npu_easc1_cfg : 1;
        unsigned int ip_prst_npu_easc0_cfg : 1;
        unsigned int ip_prst_dmmu_cfg : 1;
        unsigned int ip_prst_aicore_smmu : 1;
        unsigned int ip_prst_fcg_aicore : 1;
        unsigned int ip_prst_npu_tcu : 1;
        unsigned int ip_prst_npu_dpm0 : 1;
        unsigned int ip_rst_ts_ffap1_tscpu : 1;
        unsigned int ip_rst_aicore_eff1 : 1;
        unsigned int ip_rst_aicore_eff1_crg : 1;
        unsigned int ip_prst_npu_hw_exp_irq_ns : 1;
        unsigned int ip_prst_npu_hw_exp_irq : 1;
        unsigned int ip_prst_npu_uart : 1;
        unsigned int ip_prst_npu_pcr : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_aicore0_hpm : 1;
        unsigned int ip_rst_npu_hpm : 1;
        unsigned int ip_prst_atgm : 1;
    } reg;
} SOC_NPUCRG_PERRSTSTAT0_UNION;
#endif
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_pa_START (1)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_pa_END (1)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fdcs_monitor_START (2)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fdcs_monitor_END (2)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff_crg_START (3)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff_crg_END (3)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_gen_crg_START (4)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_gen_crg_END (4)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_crg_START (5)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_crg_END (5)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_gen_START (6)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_gen_END (6)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff_START (7)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff_END (7)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_timer_START (8)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_timer_END (8)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_aicore_pdc_START (10)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_aicore_pdc_END (10)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_dmmu_ts_cfg_START (11)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_dmmu_ts_cfg_END (11)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_ts_apb_START (12)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_ts_apb_END (12)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_ts_apb_83m_START (13)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_ts_apb_83m_END (13)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_easc1_cfg_START (14)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_easc1_cfg_END (14)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_easc0_cfg_START (15)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_easc0_cfg_END (15)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_dmmu_cfg_START (16)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_dmmu_cfg_END (16)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_aicore_smmu_START (17)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_aicore_smmu_END (17)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_fcg_aicore_START (18)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_fcg_aicore_END (18)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_tcu_START (19)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_tcu_END (19)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_dpm0_START (20)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_dpm0_END (20)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_ts_ffap1_tscpu_START (21)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_ts_ffap1_tscpu_END (21)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff1_START (22)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff1_END (22)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff1_crg_START (23)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_eff1_crg_END (23)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_hw_exp_irq_ns_START (24)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_hw_exp_irq_ns_END (24)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_hw_exp_irq_START (25)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_hw_exp_irq_END (25)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_uart_START (26)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_uart_END (26)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_pcr_START (27)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_npu_pcr_END (27)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore0_hpm_START (29)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore0_hpm_END (29)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_hpm_START (30)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_hpm_END (30)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_atgm_START (31)
#define SOC_NPUCRG_PERRSTSTAT0_ip_prst_atgm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_qic_aicore_data : 1;
        unsigned int ip_rst_qic_aicore_cfg1 : 1;
        unsigned int ip_rst_qic_aicore_cfg0 : 1;
        unsigned int ip_rst_fcg_freq_ctrl_aicore : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_qice_npu : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_aicore_smmu : 1;
        unsigned int ip_rst_himinibus : 1;
        unsigned int ip_rst_npu_easc1 : 1;
        unsigned int ip_rst_npu_easc0 : 1;
        unsigned int ip_rst_ai_core : 1;
        unsigned int ip_rst_qice_cfg2npu : 1;
        unsigned int ip_rst_qic_tcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_ts_doorbell : 1;
        unsigned int ip_rst_pdbg_ts_cpu : 1;
        unsigned int ip_rst_npu_tcu : 1;
        unsigned int ip_rst_ts_hts_adpt : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_ts_smmu : 1;
        unsigned int ip_rst_ts_hwts : 1;
        unsigned int ip_rst_ts_qic_riscv : 1;
        unsigned int ip_rst_ts_qic_bus : 1;
        unsigned int ip_rst_qic_ts : 1;
        unsigned int ip_rst_ts_cpu : 1;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_NPUCRG_PERRSTEN1_UNION;
#endif
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_aicore_data_START (0)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_aicore_data_END (0)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_aicore_cfg1_START (1)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_aicore_cfg1_END (1)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_aicore_cfg0_START (2)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_aicore_cfg0_END (2)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_fcg_freq_ctrl_aicore_START (3)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_fcg_freq_ctrl_aicore_END (3)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_pll_fsm_START (4)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_pll_fsm_END (4)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qice_npu_START (5)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qice_npu_END (5)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_aicore_smmu_START (7)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_aicore_smmu_END (7)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_himinibus_START (8)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_himinibus_END (8)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npu_easc1_START (9)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npu_easc1_END (9)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npu_easc0_START (10)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npu_easc0_END (10)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ai_core_START (11)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ai_core_END (11)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qice_cfg2npu_START (12)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qice_cfg2npu_END (12)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_tcu_START (13)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_tcu_END (13)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_doorbell_START (15)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_doorbell_END (15)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_pdbg_ts_cpu_START (16)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_pdbg_ts_cpu_END (16)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npu_tcu_START (17)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npu_tcu_END (17)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_hts_adpt_START (18)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_hts_adpt_END (18)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_smmu_START (20)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_smmu_END (20)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_hwts_START (21)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_hwts_END (21)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_qic_riscv_START (22)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_qic_riscv_END (22)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_qic_bus_START (23)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_qic_bus_END (23)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_ts_START (24)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_qic_ts_END (24)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_cpu_START (25)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_cpu_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_qic_aicore_data : 1;
        unsigned int ip_rst_qic_aicore_cfg1 : 1;
        unsigned int ip_rst_qic_aicore_cfg0 : 1;
        unsigned int ip_rst_fcg_freq_ctrl_aicore : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_qice_npu : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_aicore_smmu : 1;
        unsigned int ip_rst_himinibus : 1;
        unsigned int ip_rst_npu_easc1 : 1;
        unsigned int ip_rst_npu_easc0 : 1;
        unsigned int ip_rst_ai_core : 1;
        unsigned int ip_rst_qice_cfg2npu : 1;
        unsigned int ip_rst_qic_tcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_ts_doorbell : 1;
        unsigned int ip_rst_pdbg_ts_cpu : 1;
        unsigned int ip_rst_npu_tcu : 1;
        unsigned int ip_rst_ts_hts_adpt : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_ts_smmu : 1;
        unsigned int ip_rst_ts_hwts : 1;
        unsigned int ip_rst_ts_qic_riscv : 1;
        unsigned int ip_rst_ts_qic_bus : 1;
        unsigned int ip_rst_qic_ts : 1;
        unsigned int ip_rst_ts_cpu : 1;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_NPUCRG_PERRSTDIS1_UNION;
#endif
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_aicore_data_START (0)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_aicore_data_END (0)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_aicore_cfg1_START (1)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_aicore_cfg1_END (1)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_aicore_cfg0_START (2)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_aicore_cfg0_END (2)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_fcg_freq_ctrl_aicore_START (3)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_fcg_freq_ctrl_aicore_END (3)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_pll_fsm_START (4)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_pll_fsm_END (4)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qice_npu_START (5)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qice_npu_END (5)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_aicore_smmu_START (7)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_aicore_smmu_END (7)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_himinibus_START (8)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_himinibus_END (8)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npu_easc1_START (9)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npu_easc1_END (9)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npu_easc0_START (10)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npu_easc0_END (10)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ai_core_START (11)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ai_core_END (11)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qice_cfg2npu_START (12)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qice_cfg2npu_END (12)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_tcu_START (13)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_tcu_END (13)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_doorbell_START (15)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_doorbell_END (15)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_pdbg_ts_cpu_START (16)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_pdbg_ts_cpu_END (16)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npu_tcu_START (17)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npu_tcu_END (17)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_hts_adpt_START (18)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_hts_adpt_END (18)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_smmu_START (20)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_smmu_END (20)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_hwts_START (21)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_hwts_END (21)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_qic_riscv_START (22)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_qic_riscv_END (22)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_qic_bus_START (23)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_qic_bus_END (23)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_ts_START (24)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_qic_ts_END (24)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_cpu_START (25)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_cpu_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_qic_aicore_data : 1;
        unsigned int ip_rst_qic_aicore_cfg1 : 1;
        unsigned int ip_rst_qic_aicore_cfg0 : 1;
        unsigned int ip_rst_fcg_freq_ctrl_aicore : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_qice_npu : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_aicore_smmu : 1;
        unsigned int ip_rst_himinibus : 1;
        unsigned int ip_rst_npu_easc1 : 1;
        unsigned int ip_rst_npu_easc0 : 1;
        unsigned int ip_rst_ai_core : 1;
        unsigned int ip_rst_qice_cfg2npu : 1;
        unsigned int ip_rst_qic_tcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_ts_doorbell : 1;
        unsigned int ip_rst_pdbg_ts_cpu : 1;
        unsigned int ip_rst_npu_tcu : 1;
        unsigned int ip_rst_ts_hts_adpt : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_ts_smmu : 1;
        unsigned int ip_rst_ts_hwts : 1;
        unsigned int ip_rst_ts_qic_riscv : 1;
        unsigned int ip_rst_ts_qic_bus : 1;
        unsigned int ip_rst_qic_ts : 1;
        unsigned int ip_rst_ts_cpu : 1;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_NPUCRG_PERRSTSTAT1_UNION;
#endif
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_aicore_data_START (0)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_aicore_data_END (0)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_aicore_cfg1_START (1)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_aicore_cfg1_END (1)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_aicore_cfg0_START (2)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_aicore_cfg0_END (2)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_fcg_freq_ctrl_aicore_START (3)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_fcg_freq_ctrl_aicore_END (3)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_pll_fsm_START (4)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_pll_fsm_END (4)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qice_npu_START (5)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qice_npu_END (5)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_aicore_smmu_START (7)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_aicore_smmu_END (7)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_himinibus_START (8)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_himinibus_END (8)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npu_easc1_START (9)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npu_easc1_END (9)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npu_easc0_START (10)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npu_easc0_END (10)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ai_core_START (11)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ai_core_END (11)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qice_cfg2npu_START (12)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qice_cfg2npu_END (12)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_tcu_START (13)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_tcu_END (13)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_doorbell_START (15)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_doorbell_END (15)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_pdbg_ts_cpu_START (16)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_pdbg_ts_cpu_END (16)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npu_tcu_START (17)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npu_tcu_END (17)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_hts_adpt_START (18)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_hts_adpt_END (18)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_smmu_START (20)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_smmu_END (20)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_hwts_START (21)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_hwts_END (21)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_qic_riscv_START (22)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_qic_riscv_END (22)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_qic_bus_START (23)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_qic_bus_END (23)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_ts_START (24)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_qic_ts_END (24)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_cpu_START (25)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_cpu_END (25)
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
        unsigned int reserved_30: 2;
    } reg;
} SOC_NPUCRG_PERRSTEN2_UNION;
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
        unsigned int reserved_30: 2;
    } reg;
} SOC_NPUCRG_PERRSTDIS2_UNION;
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
        unsigned int reserved_30: 2;
    } reg;
} SOC_NPUCRG_PERRSTSTAT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int div_clk_npu_tcu : 4;
        unsigned int div_clk_ai_core0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_CLKDIV0_UNION;
#endif
#define SOC_NPUCRG_CLKDIV0_div_clk_npu_tcu_START (4)
#define SOC_NPUCRG_CLKDIV0_div_clk_npu_tcu_END (7)
#define SOC_NPUCRG_CLKDIV0_div_clk_ai_core0_START (8)
#define SOC_NPUCRG_CLKDIV0_div_clk_ai_core0_END (11)
#define SOC_NPUCRG_CLKDIV0_bitmasken_START (16)
#define SOC_NPUCRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int div_clk_ts_cpu : 4;
        unsigned int reserved_1 : 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_CLKDIV3_UNION;
#endif
#define SOC_NPUCRG_CLKDIV3_div_clk_ts_cpu_START (4)
#define SOC_NPUCRG_CLKDIV3_div_clk_ts_cpu_END (7)
#define SOC_NPUCRG_CLKDIV3_bitmasken_START (16)
#define SOC_NPUCRG_CLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_code_bypass : 1;
        unsigned int temp_code_enable : 1;
        unsigned int reserved_0 : 1;
        unsigned int sc_gt_clk_npu_tcu_div : 1;
        unsigned int sc_gt_clk_ts_cpu_div : 1;
        unsigned int sc_gt_clk_ppll5_npu_tp : 1;
        unsigned int reserved_1 : 6;
        unsigned int sc_gt_clk_pll_fsm : 1;
        unsigned int sc_gt_clk_npu_monitor : 1;
        unsigned int sc_gt_clk_dw_dbg : 1;
        unsigned int sc_gt_clk_ai_core0_div : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_CLKDIV1_UNION;
#endif
#define SOC_NPUCRG_CLKDIV1_temp_code_bypass_START (0)
#define SOC_NPUCRG_CLKDIV1_temp_code_bypass_END (0)
#define SOC_NPUCRG_CLKDIV1_temp_code_enable_START (1)
#define SOC_NPUCRG_CLKDIV1_temp_code_enable_END (1)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_npu_tcu_div_START (3)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_npu_tcu_div_END (3)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_ts_cpu_div_START (4)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_ts_cpu_div_END (4)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_ppll5_npu_tp_START (5)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_ppll5_npu_tp_END (5)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_pll_fsm_START (12)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_pll_fsm_END (12)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_npu_monitor_START (13)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_npu_monitor_END (13)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_dw_dbg_START (14)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_dw_dbg_END (14)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_ai_core0_div_START (15)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_ai_core0_div_END (15)
#define SOC_NPUCRG_CLKDIV1_bitmasken_START (16)
#define SOC_NPUCRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_clk_ppll5_npu_tp : 6;
        unsigned int div_clk_pll_fsm : 6;
        unsigned int div_clk_npu_monitor : 2;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_CLKDIV2_UNION;
#endif
#define SOC_NPUCRG_CLKDIV2_div_clk_ppll5_npu_tp_START (0)
#define SOC_NPUCRG_CLKDIV2_div_clk_ppll5_npu_tp_END (5)
#define SOC_NPUCRG_CLKDIV2_div_clk_pll_fsm_START (6)
#define SOC_NPUCRG_CLKDIV2_div_clk_pll_fsm_END (11)
#define SOC_NPUCRG_CLKDIV2_div_clk_npu_monitor_START (12)
#define SOC_NPUCRG_CLKDIV2_div_clk_npu_monitor_END (13)
#define SOC_NPUCRG_CLKDIV2_bitmasken_START (16)
#define SOC_NPUCRG_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swdone_clk_ts_cpu_div : 1;
        unsigned int swdone_clk_npu_monitor_div : 1;
        unsigned int cpu_l2_idle_aft_aicore : 1;
        unsigned int freq_dn_flag_aicore : 1;
        unsigned int swdone_clk_npu_tcu_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int swdone_clk_ai_core0_div : 1;
        unsigned int st_clk_npu_pcr : 1;
        unsigned int st_clk_ai_core_pcr : 1;
        unsigned int dfs_ack_aicore : 1;
        unsigned int st_clk_npu_dpm0 : 1;
        unsigned int st_clk_ppll5_gt : 1;
        unsigned int fcg_sscg_idle_aicore : 1;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_NPUCRG_PERI_STAT0_UNION;
#endif
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_ts_cpu_div_START (0)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_ts_cpu_div_END (0)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_npu_monitor_div_START (1)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_npu_monitor_div_END (1)
#define SOC_NPUCRG_PERI_STAT0_cpu_l2_idle_aft_aicore_START (2)
#define SOC_NPUCRG_PERI_STAT0_cpu_l2_idle_aft_aicore_END (2)
#define SOC_NPUCRG_PERI_STAT0_freq_dn_flag_aicore_START (3)
#define SOC_NPUCRG_PERI_STAT0_freq_dn_flag_aicore_END (3)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_npu_tcu_div_START (4)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_npu_tcu_div_END (4)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_ai_core0_div_START (6)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_ai_core0_div_END (6)
#define SOC_NPUCRG_PERI_STAT0_st_clk_npu_pcr_START (7)
#define SOC_NPUCRG_PERI_STAT0_st_clk_npu_pcr_END (7)
#define SOC_NPUCRG_PERI_STAT0_st_clk_ai_core_pcr_START (8)
#define SOC_NPUCRG_PERI_STAT0_st_clk_ai_core_pcr_END (8)
#define SOC_NPUCRG_PERI_STAT0_dfs_ack_aicore_START (9)
#define SOC_NPUCRG_PERI_STAT0_dfs_ack_aicore_END (9)
#define SOC_NPUCRG_PERI_STAT0_st_clk_npu_dpm0_START (10)
#define SOC_NPUCRG_PERI_STAT0_st_clk_npu_dpm0_END (10)
#define SOC_NPUCRG_PERI_STAT0_st_clk_ppll5_gt_START (11)
#define SOC_NPUCRG_PERI_STAT0_st_clk_ppll5_gt_END (11)
#define SOC_NPUCRG_PERI_STAT0_fcg_sscg_idle_aicore_START (12)
#define SOC_NPUCRG_PERI_STAT0_fcg_sscg_idle_aicore_END (12)
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
        unsigned int reserved_6: 10;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_PERI_CTRL0_UNION;
#endif
#define SOC_NPUCRG_PERI_CTRL0_bitmasken_START (16)
#define SOC_NPUCRG_PERI_CTRL0_bitmasken_END (31)
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
        unsigned int aicore_pdc_clkrst_bypass : 1;
        unsigned int ts_ffap1_tscpu_clkrst_bypass : 1;
        unsigned int ts_hts_adpt_clkrst_bypass : 1;
        unsigned int ts_ffap1_clkrst_bypass : 1;
        unsigned int ts_qic_bus_clkrst_bypass : 1;
        unsigned int ts_timer_clkrst_bypass : 1;
        unsigned int ts_dmmu_clkrst_bypass : 1;
        unsigned int ts_tbu_clkrst_bypass : 1;
        unsigned int ts_doorbell_clkrst_bypass : 1;
        unsigned int ts_hwts_clkrst_bypass : 1;
        unsigned int ts_apb_clkrst_bypass : 1;
        unsigned int ts_uart_clkrst_bypass : 1;
        unsigned int ts_irq_ns_clkrst_bypass : 1;
        unsigned int ts_irq_clkrst_bypass : 1;
        unsigned int ts_apb_83m_clkrst_bypass : 1;
        unsigned int aicore_easc1_cfg_clkrst_bypass : 1;
        unsigned int aicore_easc0_cfg_clkrst_bypass : 1;
        unsigned int aicore_dmmu_clkrst_bypass : 1;
        unsigned int aicore_smmu_clkrst_bypass : 1;
        unsigned int npu_tcu_cfg_clkrst_bypass : 1;
        unsigned int npu_pcr_clkrst_bypass : 1;
        unsigned int npu_dpm0_clkrst_bypass : 1;
        unsigned int fcg_aicore_clkrst_bypass : 1;
        unsigned int reserved_7 : 2;
    } reg;
} SOC_NPUCRG_IPCLKRST_BYPASS_UNION;
#endif
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_pdc_clkrst_bypass_START (7)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_pdc_clkrst_bypass_END (7)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_ffap1_tscpu_clkrst_bypass_START (8)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_ffap1_tscpu_clkrst_bypass_END (8)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_hts_adpt_clkrst_bypass_START (9)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_hts_adpt_clkrst_bypass_END (9)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_ffap1_clkrst_bypass_START (10)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_ffap1_clkrst_bypass_END (10)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_qic_bus_clkrst_bypass_START (11)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_qic_bus_clkrst_bypass_END (11)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_timer_clkrst_bypass_START (12)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_timer_clkrst_bypass_END (12)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_dmmu_clkrst_bypass_START (13)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_dmmu_clkrst_bypass_END (13)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_tbu_clkrst_bypass_START (14)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_tbu_clkrst_bypass_END (14)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_doorbell_clkrst_bypass_START (15)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_doorbell_clkrst_bypass_END (15)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_hwts_clkrst_bypass_START (16)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_hwts_clkrst_bypass_END (16)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_apb_clkrst_bypass_START (17)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_apb_clkrst_bypass_END (17)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_uart_clkrst_bypass_START (18)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_uart_clkrst_bypass_END (18)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_irq_ns_clkrst_bypass_START (19)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_irq_ns_clkrst_bypass_END (19)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_irq_clkrst_bypass_START (20)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_irq_clkrst_bypass_END (20)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_apb_83m_clkrst_bypass_START (21)
#define SOC_NPUCRG_IPCLKRST_BYPASS_ts_apb_83m_clkrst_bypass_END (21)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_easc1_cfg_clkrst_bypass_START (22)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_easc1_cfg_clkrst_bypass_END (22)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_easc0_cfg_clkrst_bypass_START (23)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_easc0_cfg_clkrst_bypass_END (23)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_dmmu_clkrst_bypass_START (24)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_dmmu_clkrst_bypass_END (24)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_smmu_clkrst_bypass_START (25)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_smmu_clkrst_bypass_END (25)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_tcu_cfg_clkrst_bypass_START (26)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_tcu_cfg_clkrst_bypass_END (26)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_pcr_clkrst_bypass_START (27)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_pcr_clkrst_bypass_END (27)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_dpm0_clkrst_bypass_START (28)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_dpm0_clkrst_bypass_END (28)
#define SOC_NPUCRG_IPCLKRST_BYPASS_fcg_aicore_clkrst_bypass_START (29)
#define SOC_NPUCRG_IPCLKRST_BYPASS_fcg_aicore_clkrst_bypass_END (29)
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
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPUCRG_IPCLKRST_BYPASS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int npubus_ts_cpu_hts_slv_idle_bypass : 1;
        unsigned int npubus_ts_cpu_hts_mst_idle_bypass : 1;
        unsigned int tscpu_perf_idle_bypass : 1;
        unsigned int npubus_ts_cpu_autodiv_rv_idle_bypass : 1;
        unsigned int npubus_ts_cpu_ts_himinibus_idle_bypass : 1;
        unsigned int tscpu_tbu_idle_bypass : 1;
        unsigned int npubus_tcu_ts_hwts_idle_bypass : 1;
        unsigned int npubus_ts_cpu_cc_bypass : 1;
        unsigned int npubus_ts_cpu_tsqic_bypass : 1;
        unsigned int npubus_ts_cpu_qic_bypass : 1;
        unsigned int aicore1_perf_idle_bypass : 1;
        unsigned int aicore0_perf_idle_bypass : 1;
        unsigned int npubus_aicore0_autodiv_aic0_bypass : 1;
        unsigned int npubus_aicore0_smmu_bypass : 1;
        unsigned int npubus_aicore0_himinibus_bypass : 1;
        unsigned int npubus_aicore0_cc_bypass : 1;
        unsigned int npubus_aicore0_qic_bypass : 1;
        unsigned int npubus_cfg_cc_bypass : 1;
        unsigned int npubus_cfg_tsqic_bypass : 1;
        unsigned int npubus_cfg_qic_bypass : 1;
        unsigned int npubus_perf_idle_tscpu_bypass : 1;
        unsigned int npubus_perf_idle_tcu_bypass : 1;
        unsigned int npubus_perf_idle_aicore_m1_bypass : 1;
        unsigned int npubus_perf_idle_aicore_m0_bypass : 1;
        unsigned int qice_ibqe_perf_idle_bypass : 1;
        unsigned int qice_ibqe_bypass : 1;
        unsigned int npubus_qic_tcu_idle_bypass : 1;
        unsigned int npubus_himinibus_ts_2to1_idle_bypass : 1;
        unsigned int npubus_himinibus_aicore_2to1_idle_bypass : 1;
        unsigned int npubus_tsqic_idle_bypass : 1;
        unsigned int npubus_qic_idle_bypass : 1;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_hts_slv_idle_bypass_START (1)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_hts_slv_idle_bypass_END (1)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_hts_mst_idle_bypass_START (2)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_hts_mst_idle_bypass_END (2)
#define SOC_NPUCRG_PERI_AUTODIV0_tscpu_perf_idle_bypass_START (3)
#define SOC_NPUCRG_PERI_AUTODIV0_tscpu_perf_idle_bypass_END (3)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_autodiv_rv_idle_bypass_START (4)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_autodiv_rv_idle_bypass_END (4)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_ts_himinibus_idle_bypass_START (5)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_ts_himinibus_idle_bypass_END (5)
#define SOC_NPUCRG_PERI_AUTODIV0_tscpu_tbu_idle_bypass_START (6)
#define SOC_NPUCRG_PERI_AUTODIV0_tscpu_tbu_idle_bypass_END (6)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_tcu_ts_hwts_idle_bypass_START (7)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_tcu_ts_hwts_idle_bypass_END (7)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_cc_bypass_START (8)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_cc_bypass_END (8)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_tsqic_bypass_START (9)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_tsqic_bypass_END (9)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_qic_bypass_START (10)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_ts_cpu_qic_bypass_END (10)
#define SOC_NPUCRG_PERI_AUTODIV0_aicore1_perf_idle_bypass_START (11)
#define SOC_NPUCRG_PERI_AUTODIV0_aicore1_perf_idle_bypass_END (11)
#define SOC_NPUCRG_PERI_AUTODIV0_aicore0_perf_idle_bypass_START (12)
#define SOC_NPUCRG_PERI_AUTODIV0_aicore0_perf_idle_bypass_END (12)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_autodiv_aic0_bypass_START (13)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_autodiv_aic0_bypass_END (13)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_smmu_bypass_START (14)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_smmu_bypass_END (14)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_himinibus_bypass_START (15)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_himinibus_bypass_END (15)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_cc_bypass_START (16)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_cc_bypass_END (16)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_qic_bypass_START (17)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_aicore0_qic_bypass_END (17)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_cfg_cc_bypass_START (18)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_cfg_cc_bypass_END (18)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_cfg_tsqic_bypass_START (19)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_cfg_tsqic_bypass_END (19)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_cfg_qic_bypass_START (20)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_cfg_qic_bypass_END (20)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_tscpu_bypass_START (21)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_tscpu_bypass_END (21)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_tcu_bypass_START (22)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_tcu_bypass_END (22)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_aicore_m1_bypass_START (23)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_aicore_m1_bypass_END (23)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_aicore_m0_bypass_START (24)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_perf_idle_aicore_m0_bypass_END (24)
#define SOC_NPUCRG_PERI_AUTODIV0_qice_ibqe_perf_idle_bypass_START (25)
#define SOC_NPUCRG_PERI_AUTODIV0_qice_ibqe_perf_idle_bypass_END (25)
#define SOC_NPUCRG_PERI_AUTODIV0_qice_ibqe_bypass_START (26)
#define SOC_NPUCRG_PERI_AUTODIV0_qice_ibqe_bypass_END (26)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_qic_tcu_idle_bypass_START (27)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_qic_tcu_idle_bypass_END (27)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_himinibus_ts_2to1_idle_bypass_START (28)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_himinibus_ts_2to1_idle_bypass_END (28)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_himinibus_aicore_2to1_idle_bypass_START (29)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_himinibus_aicore_2to1_idle_bypass_END (29)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_tsqic_idle_bypass_START (30)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_tsqic_idle_bypass_END (30)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_qic_idle_bypass_START (31)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_qic_idle_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npubus_cfg_div_auto_reduce_bypass : 1;
        unsigned int npubus_cfg_auto_waitcfg_in : 14;
        unsigned int npubus_cfg_auto_waitcfg_out : 6;
        unsigned int npubus_cfg_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_reduce_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_reduce_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_in_START (1)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_in_END (14)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_out_START (15)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_out_END (20)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_cfg_START (21)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npubus_div_auto_reduce_bypass : 1;
        unsigned int npubus_auto_waitcfg_in : 14;
        unsigned int npubus_auto_waitcfg_out : 6;
        unsigned int npubus_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV2_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_reduce_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_reduce_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_in_START (1)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_in_END (14)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_out_START (15)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_out_END (20)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_cfg_START (21)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int autodiv_npubus_stat : 1;
        unsigned int autodiv_npubus_cfg_stat : 1;
        unsigned int autodiv_npubus_aicore0_stat : 1;
        unsigned int autodiv_npubus_tcu_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int autodiv_npubus_ts_cpu_stat : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_stat_START (0)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_stat_END (0)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_cfg_stat_START (1)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_cfg_stat_END (1)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_aicore0_stat_START (2)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_aicore0_stat_END (2)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_tcu_stat_START (3)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_tcu_stat_END (3)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_ts_cpu_stat_START (5)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_ts_cpu_stat_END (5)
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
        unsigned int reserved_16: 16;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npubus_aicore0_div_auto_reduce_bypass_lpm3 : 1;
        unsigned int npubus_aicore0_auto_waitcfg_in : 14;
        unsigned int npubus_aicore0_auto_waitcfg_out : 6;
        unsigned int npubus_aicore0_div_auto_cfg : 6;
        unsigned int npubus_aicore0_div_auto_reduce_bypass_acpu : 1;
        unsigned int npubus_aicore0_div_auto_reduce_bypass_mcpu : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV5_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_reduce_bypass_lpm3_START (0)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_reduce_bypass_lpm3_END (0)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_auto_waitcfg_in_START (1)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_auto_waitcfg_in_END (14)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_auto_waitcfg_out_START (15)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_auto_waitcfg_out_END (20)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_cfg_START (21)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_cfg_END (26)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_reduce_bypass_acpu_START (27)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_reduce_bypass_acpu_END (27)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_reduce_bypass_mcpu_START (28)
#define SOC_NPUCRG_PERI_AUTODIV5_npubus_aicore0_div_auto_reduce_bypass_mcpu_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npubus_ts_cpu_div_auto_reduce_bypass : 1;
        unsigned int npubus_ts_cpu_auto_waitcfg_in : 14;
        unsigned int npubus_ts_cpu_auto_waitcfg_out : 6;
        unsigned int npubus_ts_cpu_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV8_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_div_auto_reduce_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_div_auto_reduce_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_auto_waitcfg_in_START (1)
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_auto_waitcfg_in_END (14)
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_auto_waitcfg_out_START (15)
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_auto_waitcfg_out_END (20)
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_div_auto_cfg_START (21)
#define SOC_NPUCRG_PERI_AUTODIV8_npubus_ts_cpu_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_perf_idle_bypass : 1;
        unsigned int npubus_tcu_qic_idle_bypass : 1;
        unsigned int npubus_tcu_aicore_tbu_idle_bypass : 1;
        unsigned int npubus_tcu_ts_tbu_idle_bypass : 1;
        unsigned int npu_tcu_idle_bypass : 1;
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
        unsigned int reserved_11 : 16;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV9_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV9_tcu_perf_idle_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV9_tcu_perf_idle_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV9_npubus_tcu_qic_idle_bypass_START (1)
#define SOC_NPUCRG_PERI_AUTODIV9_npubus_tcu_qic_idle_bypass_END (1)
#define SOC_NPUCRG_PERI_AUTODIV9_npubus_tcu_aicore_tbu_idle_bypass_START (2)
#define SOC_NPUCRG_PERI_AUTODIV9_npubus_tcu_aicore_tbu_idle_bypass_END (2)
#define SOC_NPUCRG_PERI_AUTODIV9_npubus_tcu_ts_tbu_idle_bypass_START (3)
#define SOC_NPUCRG_PERI_AUTODIV9_npubus_tcu_ts_tbu_idle_bypass_END (3)
#define SOC_NPUCRG_PERI_AUTODIV9_npu_tcu_idle_bypass_START (4)
#define SOC_NPUCRG_PERI_AUTODIV9_npu_tcu_idle_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npubus_npu_tcu_div_auto_reduce_bypass : 1;
        unsigned int npubus_npu_tcu_auto_waitcfg_in : 14;
        unsigned int npubus_npu_tcu_auto_waitcfg_out : 6;
        unsigned int npubus_npu_tcu_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV11_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_div_auto_reduce_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_div_auto_reduce_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_auto_waitcfg_in_START (1)
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_auto_waitcfg_in_END (14)
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_auto_waitcfg_out_START (15)
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_auto_waitcfg_out_END (20)
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_div_auto_cfg_START (21)
#define SOC_NPUCRG_PERI_AUTODIV11_npubus_npu_tcu_div_auto_cfg_END (26)
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
} SOC_NPUCRG_PERI_AUTODIV12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPUCRG_NPU_SUBSYS_STAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPUCRG_NPU_SUBSYS_STAT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_en_aicore : 1;
        unsigned int fcg_bp_aicore : 1;
        unsigned int fdcs_fast_mode_aicore : 1;
        unsigned int reserved_0 : 5;
        unsigned int fcg_fbdiv_aicore : 12;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int fcg_lock_aicore : 1;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_NPUCRG_FCGCTRL0_UNION;
#endif
#define SOC_NPUCRG_FCGCTRL0_fcg_en_aicore_START (0)
#define SOC_NPUCRG_FCGCTRL0_fcg_en_aicore_END (0)
#define SOC_NPUCRG_FCGCTRL0_fcg_bp_aicore_START (1)
#define SOC_NPUCRG_FCGCTRL0_fcg_bp_aicore_END (1)
#define SOC_NPUCRG_FCGCTRL0_fdcs_fast_mode_aicore_START (2)
#define SOC_NPUCRG_FCGCTRL0_fdcs_fast_mode_aicore_END (2)
#define SOC_NPUCRG_FCGCTRL0_fcg_fbdiv_aicore_START (8)
#define SOC_NPUCRG_FCGCTRL0_fcg_fbdiv_aicore_END (19)
#define SOC_NPUCRG_FCGCTRL0_fcg_lock_aicore_START (26)
#define SOC_NPUCRG_FCGCTRL0_fcg_lock_aicore_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_frac_aicore : 24;
        unsigned int reserved_0 : 1;
        unsigned int fcg_cfg_vld_aicore : 1;
        unsigned int gt_clk_fcg_aicore : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_NPUCRG_FCGCTRL1_UNION;
#endif
#define SOC_NPUCRG_FCGCTRL1_fcg_frac_aicore_START (0)
#define SOC_NPUCRG_FCGCTRL1_fcg_frac_aicore_END (23)
#define SOC_NPUCRG_FCGCTRL1_fcg_cfg_vld_aicore_START (25)
#define SOC_NPUCRG_FCGCTRL1_fcg_cfg_vld_aicore_END (25)
#define SOC_NPUCRG_FCGCTRL1_gt_clk_fcg_aicore_START (26)
#define SOC_NPUCRG_FCGCTRL1_gt_clk_fcg_aicore_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_gt_stat_aicore : 1;
        unsigned int fcg_bypass_aicore : 1;
        unsigned int fcg_en_stat_aicore : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 26;
    } reg;
} SOC_NPUCRG_PLL_VOTE_STAT_UNION;
#endif
#define SOC_NPUCRG_PLL_VOTE_STAT_fcg_gt_stat_aicore_START (0)
#define SOC_NPUCRG_PLL_VOTE_STAT_fcg_gt_stat_aicore_END (0)
#define SOC_NPUCRG_PLL_VOTE_STAT_fcg_bypass_aicore_START (1)
#define SOC_NPUCRG_PLL_VOTE_STAT_fcg_bypass_aicore_END (1)
#define SOC_NPUCRG_PLL_VOTE_STAT_fcg_en_stat_aicore_START (2)
#define SOC_NPUCRG_PLL_VOTE_STAT_fcg_en_stat_aicore_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_en_vote_aicore : 5;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_PLL_EN_VOTE_CTRL_UNION;
#endif
#define SOC_NPUCRG_PLL_EN_VOTE_CTRL_fcg_en_vote_aicore_START (0)
#define SOC_NPUCRG_PLL_EN_VOTE_CTRL_fcg_en_vote_aicore_END (4)
#define SOC_NPUCRG_PLL_EN_VOTE_CTRL_bitmasken_START (16)
#define SOC_NPUCRG_PLL_EN_VOTE_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_gt_vote_aicore : 5;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_PLL_GT_VOTE_CTRL_UNION;
#endif
#define SOC_NPUCRG_PLL_GT_VOTE_CTRL_fcg_gt_vote_aicore_START (0)
#define SOC_NPUCRG_PLL_GT_VOTE_CTRL_fcg_gt_vote_aicore_END (4)
#define SOC_NPUCRG_PLL_GT_VOTE_CTRL_bitmasken_START (16)
#define SOC_NPUCRG_PLL_GT_VOTE_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_bypass_vote_aicore : 5;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_PLL_BYPASS_VOTE_CTRL_UNION;
#endif
#define SOC_NPUCRG_PLL_BYPASS_VOTE_CTRL_fcg_bypass_vote_aicore_START (0)
#define SOC_NPUCRG_PLL_BYPASS_VOTE_CTRL_fcg_bypass_vote_aicore_END (4)
#define SOC_NPUCRG_PLL_BYPASS_VOTE_CTRL_bitmasken_START (16)
#define SOC_NPUCRG_PLL_BYPASS_VOTE_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcr_trig_vdm_en : 1;
        unsigned int cpu_wfx_bypass : 4;
        unsigned int l2_idle_div_mod : 1;
        unsigned int freq_dn_mst_sel : 1;
        unsigned int cfg_cnt_cpu_wake_quit : 16;
        unsigned int cpu_wake_up_mode : 2;
        unsigned int cpu_l2_idle_switch_bypass : 1;
        unsigned int cpu_l2_idle_gt_en : 1;
        unsigned int vbat_drop_icg_en : 1;
        unsigned int vbat_drop_fcg_en : 1;
        unsigned int coreidle_bypass : 1;
        unsigned int pcr_fs_icg_en : 1;
        unsigned int pcr_fs_fcg_en : 1;
    } reg;
} SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_pcr_trig_vdm_en_START (0)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_pcr_trig_vdm_en_END (0)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_wfx_bypass_START (1)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_wfx_bypass_END (4)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_l2_idle_div_mod_START (5)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_l2_idle_div_mod_END (5)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_freq_dn_mst_sel_START (6)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_freq_dn_mst_sel_END (6)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_wake_up_mode_START (23)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_wake_up_mode_END (24)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_l2_idle_switch_bypass_START (25)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_l2_idle_switch_bypass_END (25)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_l2_idle_gt_en_START (26)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_cpu_l2_idle_gt_en_END (26)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_vbat_drop_icg_en_START (27)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_vbat_drop_icg_en_END (27)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_vbat_drop_fcg_en_START (28)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_vbat_drop_fcg_en_END (28)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_coreidle_bypass_START (29)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_coreidle_bypass_END (29)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_pcr_fs_icg_en_START (30)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_pcr_fs_icg_en_END (30)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_pcr_fs_fcg_en_START (31)
#define SOC_NPUCRG_FCG_FREQ_CTRL_AICORE_pcr_fs_fcg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg_rsv_aicore : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_FCG_CFG_RSV0_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG_RSV0_fcg_cfg_rsv_aicore_START (0)
#define SOC_NPUCRG_FCG_CFG_RSV0_fcg_cfg_rsv_aicore_END (15)
#define SOC_NPUCRG_FCG_CFG_RSV0_bitmasken_START (16)
#define SOC_NPUCRG_FCG_CFG_RSV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat_aicore : 16;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_NPUCRG_FCG_STAT0_UNION;
#endif
#define SOC_NPUCRG_FCG_STAT0_fcg_stat_aicore_START (0)
#define SOC_NPUCRG_FCG_STAT0_fcg_stat_aicore_END (15)
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
} SOC_NPUCRG_SSC_FCG_CFG_AICORE_UNION;
#endif
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_enable_START (0)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_enable_END (0)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_mode_START (1)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_mode_END (1)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_rate_START (2)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_rate_END (5)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_depth_START (6)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_depth_END (8)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_fast_dis_START (9)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_sscg_fast_dis_END (9)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_bitmasken_START (16)
#define SOC_NPUCRG_SSC_FCG_CFG_AICORE_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_drop_en_aicore : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int pim_ost_en_aicore : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int pim_peaklow_en_aicore : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int pim_debug_aicore : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_PIM_CTRL0_UNION;
#endif
#define SOC_NPUCRG_PIM_CTRL0_pim_drop_en_aicore_START (0)
#define SOC_NPUCRG_PIM_CTRL0_pim_drop_en_aicore_END (0)
#define SOC_NPUCRG_PIM_CTRL0_pim_ost_en_aicore_START (4)
#define SOC_NPUCRG_PIM_CTRL0_pim_ost_en_aicore_END (4)
#define SOC_NPUCRG_PIM_CTRL0_pim_peaklow_en_aicore_START (8)
#define SOC_NPUCRG_PIM_CTRL0_pim_peaklow_en_aicore_END (8)
#define SOC_NPUCRG_PIM_CTRL0_pim_debug_aicore_START (12)
#define SOC_NPUCRG_PIM_CTRL0_pim_debug_aicore_END (12)
#define SOC_NPUCRG_PIM_CTRL0_bitmasken_START (16)
#define SOC_NPUCRG_PIM_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
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
        unsigned int reserved_15: 16;
    } reg;
} SOC_NPUCRG_PIM_CFG0_AICORE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
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
        unsigned int reserved_15: 16;
    } reg;
} SOC_NPUCRG_PIM_CFG1_AICORE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
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
        unsigned int reserved_15: 16;
    } reg;
} SOC_NPUCRG_PIM_CFG2_AICORE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
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
        unsigned int reserved_15: 16;
    } reg;
} SOC_NPUCRG_PIM_CFG3_AICORE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_code : 16;
        unsigned int pim_peaklow_ready : 1;
        unsigned int reserved : 12;
        unsigned int pim_flag_ready_aicore : 1;
        unsigned int pim_flag_l_aicore : 1;
        unsigned int pim_flag_h_aicore : 1;
    } reg;
} SOC_NPUCRG_PIM_STAT0_UNION;
#endif
#define SOC_NPUCRG_PIM_STAT0_pim_peaklow_code_START (0)
#define SOC_NPUCRG_PIM_STAT0_pim_peaklow_code_END (15)
#define SOC_NPUCRG_PIM_STAT0_pim_peaklow_ready_START (16)
#define SOC_NPUCRG_PIM_STAT0_pim_peaklow_ready_END (16)
#define SOC_NPUCRG_PIM_STAT0_pim_flag_ready_aicore_START (29)
#define SOC_NPUCRG_PIM_STAT0_pim_flag_ready_aicore_END (29)
#define SOC_NPUCRG_PIM_STAT0_pim_flag_l_aicore_START (30)
#define SOC_NPUCRG_PIM_STAT0_pim_flag_l_aicore_END (30)
#define SOC_NPUCRG_PIM_STAT0_pim_flag_h_aicore_START (31)
#define SOC_NPUCRG_PIM_STAT0_pim_flag_h_aicore_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_en : 1;
        unsigned int accu_fd_en : 1;
        unsigned int peaklow_en : 1;
        unsigned int clear_all_en : 1;
        unsigned int cnt_timer_hd_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_NPUCRG_MON_CFG0_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG0_NPU_cnt_timer_en_START (0)
#define SOC_NPUCRG_MON_CFG0_NPU_cnt_timer_en_END (0)
#define SOC_NPUCRG_MON_CFG0_NPU_accu_fd_en_START (1)
#define SOC_NPUCRG_MON_CFG0_NPU_accu_fd_en_END (1)
#define SOC_NPUCRG_MON_CFG0_NPU_peaklow_en_START (2)
#define SOC_NPUCRG_MON_CFG0_NPU_peaklow_en_END (2)
#define SOC_NPUCRG_MON_CFG0_NPU_clear_all_en_START (3)
#define SOC_NPUCRG_MON_CFG0_NPU_clear_all_en_END (3)
#define SOC_NPUCRG_MON_CFG0_NPU_cnt_timer_hd_en_START (4)
#define SOC_NPUCRG_MON_CFG0_NPU_cnt_timer_hd_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPUCRG_MON_CFG1_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG1_NPU_read_lock_START (0)
#define SOC_NPUCRG_MON_CFG1_NPU_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_NPUCRG_MON_CFG2_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG2_NPU_bin_peaklow_en_START (0)
#define SOC_NPUCRG_MON_CFG2_NPU_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG3_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG3_NPU_vth0_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG3_NPU_vth0_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG3_NPU_vth1_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG3_NPU_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG4_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG4_NPU_vth2_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG4_NPU_vth2_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG4_NPU_vth3_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG4_NPU_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG5_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG5_NPU_vth4_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG5_NPU_vth4_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG5_NPU_vth5_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG5_NPU_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG6_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG6_NPU_vth6_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG6_NPU_vth6_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG6_NPU_vth7_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG6_NPU_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG7_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG7_NPU_vth8_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG7_NPU_vth8_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG7_NPU_vth9_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG7_NPU_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG8_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG8_NPU_vth10_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG8_NPU_vth10_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG8_NPU_vth11_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG8_NPU_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG9_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG9_NPU_vth12_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG9_NPU_vth12_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG9_NPU_vth13_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG9_NPU_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG10_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG10_NPU_vth14_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG10_NPU_vth14_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG10_NPU_vth15_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG10_NPU_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG11_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG11_NPU_vth16_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG11_NPU_vth16_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG11_NPU_vth17_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG11_NPU_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG12_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG12_NPU_vth18_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG12_NPU_vth18_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG12_NPU_vth19_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG12_NPU_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_NPUCRG_MON_CFG13_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG13_NPU_vth20_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG13_NPU_vth20_peaklow_END (15)
#define SOC_NPUCRG_MON_CFG13_NPU_vth21_peaklow_START (16)
#define SOC_NPUCRG_MON_CFG13_NPU_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPUCRG_MON_CFG14_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG14_NPU_vth22_peaklow_START (0)
#define SOC_NPUCRG_MON_CFG14_NPU_vth22_peaklow_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_hd_th : 22;
        unsigned int reserved : 8;
        unsigned int read_lock_mode : 1;
        unsigned int sel_peaklow_vth : 1;
    } reg;
} SOC_NPUCRG_MON_CFG15_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG15_NPU_cnt_timer_hd_th_START (0)
#define SOC_NPUCRG_MON_CFG15_NPU_cnt_timer_hd_th_END (21)
#define SOC_NPUCRG_MON_CFG15_NPU_read_lock_mode_START (30)
#define SOC_NPUCRG_MON_CFG15_NPU_read_lock_mode_END (30)
#define SOC_NPUCRG_MON_CFG15_NPU_sel_peaklow_vth_START (31)
#define SOC_NPUCRG_MON_CFG15_NPU_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPUCRG_MON_CFG16_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_CFG16_NPU_pim_peaklow_vth_START (0)
#define SOC_NPUCRG_MON_CFG16_NPU_pim_peaklow_vth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer : 22;
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 4;
    } reg;
} SOC_NPUCRG_MON_STAT0_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT0_NPU_cnt_timer_START (0)
#define SOC_NPUCRG_MON_STAT0_NPU_cnt_timer_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd : 25;
        unsigned int reserved_0: 3;
        unsigned int reserved_1: 4;
    } reg;
} SOC_NPUCRG_MON_STAT1_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT1_NPU_accu_fd_START (0)
#define SOC_NPUCRG_MON_STAT1_NPU_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT2_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT2_NPU_bin0_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT2_NPU_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT3_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT3_NPU_bin1_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT3_NPU_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT4_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT4_NPU_bin2_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT4_NPU_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT5_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT5_NPU_bin3_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT5_NPU_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT6_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT6_NPU_bin4_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT6_NPU_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT7_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT7_NPU_bin5_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT7_NPU_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT8_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT8_NPU_bin6_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT8_NPU_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT9_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT9_NPU_bin7_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT9_NPU_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT10_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT10_NPU_bin8_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT10_NPU_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT11_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT11_NPU_bin9_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT11_NPU_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT12_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT12_NPU_bin10_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT12_NPU_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT13_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT13_NPU_bin11_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT13_NPU_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT14_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT14_NPU_bin12_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT14_NPU_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT15_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT15_NPU_bin13_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT15_NPU_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT16_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT16_NPU_bin14_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT16_NPU_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT17_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT17_NPU_bin15_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT17_NPU_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT18_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT18_NPU_bin16_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT18_NPU_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT19_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT19_NPU_bin17_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT19_NPU_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT20_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT20_NPU_bin18_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT20_NPU_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT21_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT21_NPU_bin19_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT21_NPU_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT22_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT22_NPU_bin20_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT22_NPU_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT23_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT23_NPU_bin21_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT23_NPU_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT24_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT24_NPU_bin22_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT24_NPU_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPUCRG_MON_STAT25_NPU_UNION;
#endif
#define SOC_NPUCRG_MON_STAT25_NPU_bin23_peaklow_START (0)
#define SOC_NPUCRG_MON_STAT25_NPU_bin23_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_aicore_cfg0_nonidle_pend : 1;
        unsigned int intr_mask_aicore_cfg1_nonidle_pend : 1;
        unsigned int intr_mask_aicore_data_nonidle_pend : 1;
        unsigned int intr_mask_tcu_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_mask_ts_nonidle_pend : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_aicore_cfg0_nonidle_pend_START (0)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_aicore_cfg0_nonidle_pend_END (0)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_aicore_cfg1_nonidle_pend_START (1)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_aicore_cfg1_nonidle_pend_END (1)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_aicore_data_nonidle_pend_START (2)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_aicore_data_nonidle_pend_END (2)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_tcu_nonidle_pend_START (3)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_tcu_nonidle_pend_END (3)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_ts_nonidle_pend_START (5)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_intr_mask_ts_nonidle_pend_END (5)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_NPUCRG_INTR_MASK_QICBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_aicore_cfg0_nonidle_pend : 1;
        unsigned int intr_clr_aicore_cfg1_nonidle_pend : 1;
        unsigned int intr_clr_aicore_data_nonidle_pend : 1;
        unsigned int intr_clr_tcu_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_clr_ts_nonidle_pend : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_aicore_cfg0_nonidle_pend_START (0)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_aicore_cfg0_nonidle_pend_END (0)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_aicore_cfg1_nonidle_pend_START (1)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_aicore_cfg1_nonidle_pend_END (1)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_aicore_data_nonidle_pend_START (2)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_aicore_data_nonidle_pend_END (2)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_tcu_nonidle_pend_START (3)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_tcu_nonidle_pend_END (3)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_ts_nonidle_pend_START (5)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_intr_clr_ts_nonidle_pend_END (5)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_NPUCRG_INTR_CLR_QICBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_aicore_cfg0_nonidle_pend : 1;
        unsigned int intr_stat_aicore_cfg1_nonidle_pend : 1;
        unsigned int intr_stat_aicore_data_nonidle_pend : 1;
        unsigned int intr_stat_tcu_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_stat_ts_nonidle_pend : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 24;
    } reg;
} SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_aicore_cfg0_nonidle_pend_START (0)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_aicore_cfg0_nonidle_pend_END (0)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_aicore_cfg1_nonidle_pend_START (1)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_aicore_cfg1_nonidle_pend_END (1)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_aicore_data_nonidle_pend_START (2)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_aicore_data_nonidle_pend_END (2)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_tcu_nonidle_pend_START (3)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_tcu_nonidle_pend_END (3)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_ts_nonidle_pend_START (5)
#define SOC_NPUCRG_INTR_STAT_QICBUS_NONIDLE_PEND_intr_stat_ts_nonidle_pend_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_fsm_en : 1;
        unsigned int pll_vote_mode_sel : 1;
        unsigned int pll_intr_clr : 1;
        unsigned int reserved : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_PLL_FSM_CTRL0_UNION;
#endif
#define SOC_NPUCRG_PLL_FSM_CTRL0_pll_fsm_en_START (0)
#define SOC_NPUCRG_PLL_FSM_CTRL0_pll_fsm_en_END (0)
#define SOC_NPUCRG_PLL_FSM_CTRL0_pll_vote_mode_sel_START (1)
#define SOC_NPUCRG_PLL_FSM_CTRL0_pll_vote_mode_sel_END (1)
#define SOC_NPUCRG_PLL_FSM_CTRL0_pll_intr_clr_START (2)
#define SOC_NPUCRG_PLL_FSM_CTRL0_pll_intr_clr_END (2)
#define SOC_NPUCRG_PLL_FSM_CTRL0_bitmasken_START (16)
#define SOC_NPUCRG_PLL_FSM_CTRL0_bitmasken_END (31)
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
} SOC_NPUCRG_PLL_FSM_CTRL1_UNION;
#endif
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_lock_dbc_en_START (0)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_lock_dbc_en_END (0)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_fsm_intr_en_START (1)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_fsm_intr_en_END (1)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_wait_en_START (2)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_wait_en_END (2)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_timeout_en_START (3)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_timeout_en_END (3)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_intr_lmt_START (4)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_intr_lmt_END (6)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_wait_lmt_START (7)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_wait_lmt_END (14)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_timeout_lmt_START (15)
#define SOC_NPUCRG_PLL_FSM_CTRL1_pll_timeout_lmt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_fsm_intr : 1;
        unsigned int pll_intr_cnt : 3;
        unsigned int pll_curr_stat : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_NPUCRG_PLL_FSM_STAT_UNION;
#endif
#define SOC_NPUCRG_PLL_FSM_STAT_pll_fsm_intr_START (0)
#define SOC_NPUCRG_PLL_FSM_STAT_pll_fsm_intr_END (0)
#define SOC_NPUCRG_PLL_FSM_STAT_pll_intr_cnt_START (1)
#define SOC_NPUCRG_PLL_FSM_STAT_pll_intr_cnt_END (3)
#define SOC_NPUCRG_PLL_FSM_STAT_pll_curr_stat_START (4)
#define SOC_NPUCRG_PLL_FSM_STAT_pll_curr_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_NPUCRG_FCG_ANA_CFG0_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_ANA_CFG0_AICORE_d2a_fcg_ana_cfg0_START (0)
#define SOC_NPUCRG_FCG_ANA_CFG0_AICORE_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_NPUCRG_FCG_ANA_CFG1_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_ANA_CFG1_AICORE_d2a_fcg_ana_cfg1_START (0)
#define SOC_NPUCRG_FCG_ANA_CFG1_AICORE_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_NPUCRG_FCG_ANA_CFG2_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_ANA_CFG2_AICORE_d2a_fcg_ana_cfg2_START (0)
#define SOC_NPUCRG_FCG_ANA_CFG2_AICORE_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_NPUCRG_FCG_ANA_CFG3_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_ANA_CFG3_AICORE_d2a_fcg_ana_cfg3_START (0)
#define SOC_NPUCRG_FCG_ANA_CFG3_AICORE_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG0_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG0_AICORE_fcg_cfg0_START (0)
#define SOC_NPUCRG_FCG_CFG0_AICORE_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG1_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG1_AICORE_fcg_cfg1_START (0)
#define SOC_NPUCRG_FCG_CFG1_AICORE_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG2_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG2_AICORE_fcg_cfg2_START (0)
#define SOC_NPUCRG_FCG_CFG2_AICORE_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG3_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG3_AICORE_fcg_cfg3_START (0)
#define SOC_NPUCRG_FCG_CFG3_AICORE_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG4_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG4_AICORE_fcg_cfg4_START (0)
#define SOC_NPUCRG_FCG_CFG4_AICORE_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG5_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG5_AICORE_fcg_cfg5_START (0)
#define SOC_NPUCRG_FCG_CFG5_AICORE_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG6_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG6_AICORE_fcg_cfg6_START (0)
#define SOC_NPUCRG_FCG_CFG6_AICORE_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG7_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG7_AICORE_fcg_cfg7_START (0)
#define SOC_NPUCRG_FCG_CFG7_AICORE_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG8_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG8_AICORE_fcg_cfg8_START (0)
#define SOC_NPUCRG_FCG_CFG8_AICORE_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG9_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG9_AICORE_fcg_cfg9_START (0)
#define SOC_NPUCRG_FCG_CFG9_AICORE_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG10_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG10_AICORE_fcg_cfg10_START (0)
#define SOC_NPUCRG_FCG_CFG10_AICORE_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG11_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG11_AICORE_fcg_cfg11_START (0)
#define SOC_NPUCRG_FCG_CFG11_AICORE_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG12_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG12_AICORE_fcg_cfg12_START (0)
#define SOC_NPUCRG_FCG_CFG12_AICORE_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG13_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG13_AICORE_fcg_cfg13_START (0)
#define SOC_NPUCRG_FCG_CFG13_AICORE_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG14_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG14_AICORE_fcg_cfg14_START (0)
#define SOC_NPUCRG_FCG_CFG14_AICORE_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG15_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG15_AICORE_fcg_cfg15_START (0)
#define SOC_NPUCRG_FCG_CFG15_AICORE_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG16_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG16_AICORE_fcg_cfg16_START (0)
#define SOC_NPUCRG_FCG_CFG16_AICORE_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG17_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG17_AICORE_fcg_cfg17_START (0)
#define SOC_NPUCRG_FCG_CFG17_AICORE_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG18_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG18_AICORE_fcg_cfg18_START (0)
#define SOC_NPUCRG_FCG_CFG18_AICORE_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG19_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG19_AICORE_fcg_cfg19_START (0)
#define SOC_NPUCRG_FCG_CFG19_AICORE_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG20_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG20_AICORE_fcg_cfg20_START (0)
#define SOC_NPUCRG_FCG_CFG20_AICORE_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG21_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG21_AICORE_fcg_cfg21_START (0)
#define SOC_NPUCRG_FCG_CFG21_AICORE_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG22_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG22_AICORE_fcg_cfg22_START (0)
#define SOC_NPUCRG_FCG_CFG22_AICORE_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG23_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG23_AICORE_fcg_cfg23_START (0)
#define SOC_NPUCRG_FCG_CFG23_AICORE_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG24_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG24_AICORE_fcg_cfg24_START (0)
#define SOC_NPUCRG_FCG_CFG24_AICORE_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG25_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG25_AICORE_fcg_cfg25_START (0)
#define SOC_NPUCRG_FCG_CFG25_AICORE_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG26_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG26_AICORE_fcg_cfg26_START (0)
#define SOC_NPUCRG_FCG_CFG26_AICORE_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_NPUCRG_FCG_CFG27_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_CFG27_AICORE_fcg_cfg27_START (0)
#define SOC_NPUCRG_FCG_CFG27_AICORE_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_NPUCRG_FCG_STAT0_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_STAT0_AICORE_fcg_stat0_START (0)
#define SOC_NPUCRG_FCG_STAT0_AICORE_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_NPUCRG_FCG_STAT1_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_STAT1_AICORE_fcg_stat1_START (0)
#define SOC_NPUCRG_FCG_STAT1_AICORE_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_NPUCRG_FCG_STAT2_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_STAT2_AICORE_fcg_stat2_START (0)
#define SOC_NPUCRG_FCG_STAT2_AICORE_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_NPUCRG_FCG_STAT3_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_STAT3_AICORE_fcg_stat3_START (0)
#define SOC_NPUCRG_FCG_STAT3_AICORE_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_NPUCRG_FCG_STAT4_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_STAT4_AICORE_fcg_stat4_START (0)
#define SOC_NPUCRG_FCG_STAT4_AICORE_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_NPUCRG_FCG_STAT5_AICORE_UNION;
#endif
#define SOC_NPUCRG_FCG_STAT5_AICORE_fcg_stat5_START (0)
#define SOC_NPUCRG_FCG_STAT5_AICORE_fcg_stat5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
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
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_IPSIGMASK_UNION;
#endif
#define SOC_NPUCRG_IPSIGMASK_bitmasken_START (16)
#define SOC_NPUCRG_IPSIGMASK_bitmasken_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
