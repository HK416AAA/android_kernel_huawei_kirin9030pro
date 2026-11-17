#ifndef __SOC_CORE_CPU_CRGB_INTERFACE_H__
#define __SOC_CORE_CPU_CRGB_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CORE_CPU_CRGB_PEREN0_ADDR(base) ((base) + (0x900UL))
#define SOC_CORE_CPU_CRGB_PERDIS0_ADDR(base) ((base) + (0x904UL))
#define SOC_CORE_CPU_CRGB_PERCLKEN0_ADDR(base) ((base) + (0x908UL))
#define SOC_CORE_CPU_CRGB_PERSTAT0_ADDR(base) ((base) + (0x90CUL))
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ADDR(base) ((base) + (0x910UL))
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ADDR(base) ((base) + (0x914UL))
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ADDR(base) ((base) + (0x918UL))
#define SOC_CORE_CPU_CRGB_CLKDIV0_ADDR(base) ((base) + (0x920UL))
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_ADDR(base) ((base) + (0x924UL))
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_ADDR(base) ((base) + (0x928UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG_RSV1_ADDR(base) ((base) + (0x92cUL))
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_ADDR(base) ((base) + (0x930UL))
#define SOC_CORE_CPU_CRGB_FCG_STAT0_ADDR(base) ((base) + (0x934UL))
#define SOC_CORE_CPU_CRGB_FCM_CLKEN_ADDR(base) ((base) + (0x938UL))
#define SOC_CORE_CPU_CRGB_RSV_CFG0_ADDR(base) ((base) + (0x93cUL))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_CFG_C_ADDR(base) ((base) + (0x940UL))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_TIME_CFG_C_ADDR(base) ((base) + (0x944UL))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_0_C_ADDR(base) ((base) + (0x948UL))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_ADDR(base) ((base) + (0x94cUL))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_ADDR(base) ((base) + (0x950UL))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + (0x954UL))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_ADDR(base) ((base) + (0x958UL))
#define SOC_CORE_CPU_CRGB_APB_ONSYS_ENABLE_ADDR(base) ((base) + (0x95cUL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_ADDR(base) ((base) + (0x960UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_ADDR(base) ((base) + (0x964UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_ADDR(base) ((base) + (0x968UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_ADDR(base) ((base) + (0x96cUL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_ADDR(base) ((base) + (0x970UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_ADDR(base) ((base) + (0x974UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_ADDR(base) ((base) + (0x978UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_ADDR(base) ((base) + (0x97cUL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_ADDR(base) ((base) + (0x980UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG9_C_ADDR(base) ((base) + (0x984UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG10_C_ADDR(base) ((base) + (0x988UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_ADDR(base) ((base) + (0x98cUL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG12_C_ADDR(base) ((base) + (0x990UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG13_C_ADDR(base) ((base) + (0x994UL))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_STAT_C_ADDR(base) ((base) + (0x998UL))
#define SOC_CORE_CPU_CRGB_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x99CUL))
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_ADDR(base) ((base) + (0xA00UL))
#define SOC_CORE_CPU_CRGB_PIM_CFG0_BIG_ADDR(base) ((base) + (0xA04UL))
#define SOC_CORE_CPU_CRGB_PIM_CFG1_BIG_ADDR(base) ((base) + (0xA08UL))
#define SOC_CORE_CPU_CRGB_PIM_CFG2_BIG_ADDR(base) ((base) + (0xA0cUL))
#define SOC_CORE_CPU_CRGB_PIM_CFG3_BIG_ADDR(base) ((base) + (0xA10UL))
#define SOC_CORE_CPU_CRGB_PIM_STAT0_ADDR(base) ((base) + (0xA14UL))
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_ADDR(base) ((base) + (0xA18UL))
#define SOC_CORE_CPU_CRGB_MON_CFG1_BIG_ADDR(base) ((base) + (0xA1cUL))
#define SOC_CORE_CPU_CRGB_MON_CFG2_BIG_ADDR(base) ((base) + (0xA20UL))
#define SOC_CORE_CPU_CRGB_MON_CFG3_BIG_ADDR(base) ((base) + (0xA24UL))
#define SOC_CORE_CPU_CRGB_MON_CFG4_BIG_ADDR(base) ((base) + (0xA28UL))
#define SOC_CORE_CPU_CRGB_MON_CFG5_BIG_ADDR(base) ((base) + (0xA2cUL))
#define SOC_CORE_CPU_CRGB_MON_CFG6_BIG_ADDR(base) ((base) + (0xA30UL))
#define SOC_CORE_CPU_CRGB_MON_CFG7_BIG_ADDR(base) ((base) + (0xA34UL))
#define SOC_CORE_CPU_CRGB_MON_CFG8_BIG_ADDR(base) ((base) + (0xA38UL))
#define SOC_CORE_CPU_CRGB_MON_CFG9_BIG_ADDR(base) ((base) + (0xA3cUL))
#define SOC_CORE_CPU_CRGB_MON_CFG10_BIG_ADDR(base) ((base) + (0xA40UL))
#define SOC_CORE_CPU_CRGB_MON_CFG11_BIG_ADDR(base) ((base) + (0xA44UL))
#define SOC_CORE_CPU_CRGB_MON_CFG12_BIG_ADDR(base) ((base) + (0xA48UL))
#define SOC_CORE_CPU_CRGB_MON_CFG13_BIG_ADDR(base) ((base) + (0xA4cUL))
#define SOC_CORE_CPU_CRGB_MON_CFG14_BIG_ADDR(base) ((base) + (0xA50UL))
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_ADDR(base) ((base) + (0xA54UL))
#define SOC_CORE_CPU_CRGB_MON_CFG16_BIG_ADDR(base) ((base) + (0xA58UL))
#define SOC_CORE_CPU_CRGB_MON_STAT0_BIG_ADDR(base) ((base) + (0xA5cUL))
#define SOC_CORE_CPU_CRGB_MON_STAT1_BIG_ADDR(base) ((base) + (0xA60UL))
#define SOC_CORE_CPU_CRGB_MON_STAT2_BIG_ADDR(base) ((base) + (0xA64UL))
#define SOC_CORE_CPU_CRGB_MON_STAT3_BIG_ADDR(base) ((base) + (0xA68UL))
#define SOC_CORE_CPU_CRGB_MON_STAT4_BIG_ADDR(base) ((base) + (0xA6cUL))
#define SOC_CORE_CPU_CRGB_MON_STAT5_BIG_ADDR(base) ((base) + (0xA70UL))
#define SOC_CORE_CPU_CRGB_MON_STAT6_BIG_ADDR(base) ((base) + (0xA74UL))
#define SOC_CORE_CPU_CRGB_MON_STAT7_BIG_ADDR(base) ((base) + (0xA78UL))
#define SOC_CORE_CPU_CRGB_MON_STAT8_BIG_ADDR(base) ((base) + (0xA7cUL))
#define SOC_CORE_CPU_CRGB_MON_STAT9_BIG_ADDR(base) ((base) + (0xA80UL))
#define SOC_CORE_CPU_CRGB_MON_STAT10_BIG_ADDR(base) ((base) + (0xA84UL))
#define SOC_CORE_CPU_CRGB_MON_STAT11_BIG_ADDR(base) ((base) + (0xA88UL))
#define SOC_CORE_CPU_CRGB_MON_STAT12_BIG_ADDR(base) ((base) + (0xA8cUL))
#define SOC_CORE_CPU_CRGB_MON_STAT13_BIG_ADDR(base) ((base) + (0xA90UL))
#define SOC_CORE_CPU_CRGB_MON_STAT14_BIG_ADDR(base) ((base) + (0xA94UL))
#define SOC_CORE_CPU_CRGB_MON_STAT15_BIG_ADDR(base) ((base) + (0xA98UL))
#define SOC_CORE_CPU_CRGB_MON_STAT16_BIG_ADDR(base) ((base) + (0xA9cUL))
#define SOC_CORE_CPU_CRGB_MON_STAT17_BIG_ADDR(base) ((base) + (0xAA0UL))
#define SOC_CORE_CPU_CRGB_MON_STAT18_BIG_ADDR(base) ((base) + (0xAA4UL))
#define SOC_CORE_CPU_CRGB_MON_STAT19_BIG_ADDR(base) ((base) + (0xAA8UL))
#define SOC_CORE_CPU_CRGB_MON_STAT20_BIG_ADDR(base) ((base) + (0xAACUL))
#define SOC_CORE_CPU_CRGB_MON_STAT21_BIG_ADDR(base) ((base) + (0xAB0UL))
#define SOC_CORE_CPU_CRGB_MON_STAT22_BIG_ADDR(base) ((base) + (0xAB4UL))
#define SOC_CORE_CPU_CRGB_MON_STAT23_BIG_ADDR(base) ((base) + (0xAB8UL))
#define SOC_CORE_CPU_CRGB_MON_STAT24_BIG_ADDR(base) ((base) + (0xABCUL))
#define SOC_CORE_CPU_CRGB_MON_STAT25_BIG_ADDR(base) ((base) + (0xAC0UL))
#define SOC_CORE_CPU_CRGB_CLKDIV2_ADDR(base) ((base) + (0xB04UL))
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_ADDR(base) ((base) + (0xB60UL))
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL1_ADDR(base) ((base) + (0xB64UL))
#define SOC_CORE_CPU_CRGB_FCG_CNT_STATE0_ADDR(base) ((base) + (0xB68UL))
#define SOC_CORE_CPU_CRGB_STATE1_ADDR(base) ((base) + (0xB6cUL))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG0_BIG_ADDR(base) ((base) + (0xC00UL))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG1_BIG_ADDR(base) ((base) + (0xC04UL))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG2_BIG_ADDR(base) ((base) + (0xC08UL))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG3_BIG_ADDR(base) ((base) + (0xC0CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG0_BIG_ADDR(base) ((base) + (0xC18UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG1_BIG_ADDR(base) ((base) + (0xC1CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG2_BIG_ADDR(base) ((base) + (0xC20UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG3_BIG_ADDR(base) ((base) + (0xC24UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG4_BIG_ADDR(base) ((base) + (0xC28UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG5_BIG_ADDR(base) ((base) + (0xC2CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG6_BIG_ADDR(base) ((base) + (0xC30UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG7_BIG_ADDR(base) ((base) + (0xC34UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG8_BIG_ADDR(base) ((base) + (0xC38UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG9_BIG_ADDR(base) ((base) + (0xC3CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG10_BIG_ADDR(base) ((base) + (0xC40UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG11_BIG_ADDR(base) ((base) + (0xC44UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG12_BIG_ADDR(base) ((base) + (0xC48UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG13_BIG_ADDR(base) ((base) + (0xC4CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG14_BIG_ADDR(base) ((base) + (0xC50UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG15_BIG_ADDR(base) ((base) + (0xC54UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG16_BIG_ADDR(base) ((base) + (0xC58UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG17_BIG_ADDR(base) ((base) + (0xC5CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG18_BIG_ADDR(base) ((base) + (0xC60UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG19_BIG_ADDR(base) ((base) + (0xC64UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG20_BIG_ADDR(base) ((base) + (0xC68UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG21_BIG_ADDR(base) ((base) + (0xC6CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG22_BIG_ADDR(base) ((base) + (0xC70UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG23_BIG_ADDR(base) ((base) + (0xC74UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG24_BIG_ADDR(base) ((base) + (0xC78UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG25_BIG_ADDR(base) ((base) + (0xC7CUL))
#define SOC_CORE_CPU_CRGB_FCG_CFG26_BIG_ADDR(base) ((base) + (0xC80UL))
#define SOC_CORE_CPU_CRGB_FCG_CFG27_BIG_ADDR(base) ((base) + (0xC84UL))
#define SOC_CORE_CPU_CRGB_FCG_STAT0_BIG_ADDR(base) ((base) + (0xC90UL))
#define SOC_CORE_CPU_CRGB_FCG_STAT1_BIG_ADDR(base) ((base) + (0xC94UL))
#define SOC_CORE_CPU_CRGB_FCG_STAT2_BIG_ADDR(base) ((base) + (0xC98UL))
#define SOC_CORE_CPU_CRGB_FCG_STAT3_BIG_ADDR(base) ((base) + (0xC9CUL))
#define SOC_CORE_CPU_CRGB_FCG_STAT4_BIG_ADDR(base) ((base) + (0xCA0UL))
#define SOC_CORE_CPU_CRGB_FCG_STAT5_BIG_ADDR(base) ((base) + (0xCA4UL))
#else
#define SOC_CORE_CPU_CRGB_PEREN0_ADDR(base) ((base) + (0x900))
#define SOC_CORE_CPU_CRGB_PERDIS0_ADDR(base) ((base) + (0x904))
#define SOC_CORE_CPU_CRGB_PERCLKEN0_ADDR(base) ((base) + (0x908))
#define SOC_CORE_CPU_CRGB_PERSTAT0_ADDR(base) ((base) + (0x90C))
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ADDR(base) ((base) + (0x910))
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ADDR(base) ((base) + (0x914))
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ADDR(base) ((base) + (0x918))
#define SOC_CORE_CPU_CRGB_CLKDIV0_ADDR(base) ((base) + (0x920))
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_ADDR(base) ((base) + (0x924))
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_ADDR(base) ((base) + (0x928))
#define SOC_CORE_CPU_CRGB_FCG_CFG_RSV1_ADDR(base) ((base) + (0x92c))
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_ADDR(base) ((base) + (0x930))
#define SOC_CORE_CPU_CRGB_FCG_STAT0_ADDR(base) ((base) + (0x934))
#define SOC_CORE_CPU_CRGB_FCM_CLKEN_ADDR(base) ((base) + (0x938))
#define SOC_CORE_CPU_CRGB_RSV_CFG0_ADDR(base) ((base) + (0x93c))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_CFG_C_ADDR(base) ((base) + (0x940))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_TIME_CFG_C_ADDR(base) ((base) + (0x944))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_0_C_ADDR(base) ((base) + (0x948))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_ADDR(base) ((base) + (0x94c))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_ADDR(base) ((base) + (0x950))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + (0x954))
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_ADDR(base) ((base) + (0x958))
#define SOC_CORE_CPU_CRGB_APB_ONSYS_ENABLE_ADDR(base) ((base) + (0x95c))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_ADDR(base) ((base) + (0x960))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_ADDR(base) ((base) + (0x964))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_ADDR(base) ((base) + (0x968))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_ADDR(base) ((base) + (0x96c))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_ADDR(base) ((base) + (0x970))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_ADDR(base) ((base) + (0x974))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_ADDR(base) ((base) + (0x978))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_ADDR(base) ((base) + (0x97c))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_ADDR(base) ((base) + (0x980))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG9_C_ADDR(base) ((base) + (0x984))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG10_C_ADDR(base) ((base) + (0x988))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_ADDR(base) ((base) + (0x98c))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG12_C_ADDR(base) ((base) + (0x990))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG13_C_ADDR(base) ((base) + (0x994))
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_STAT_C_ADDR(base) ((base) + (0x998))
#define SOC_CORE_CPU_CRGB_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x99C))
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_ADDR(base) ((base) + (0xA00))
#define SOC_CORE_CPU_CRGB_PIM_CFG0_BIG_ADDR(base) ((base) + (0xA04))
#define SOC_CORE_CPU_CRGB_PIM_CFG1_BIG_ADDR(base) ((base) + (0xA08))
#define SOC_CORE_CPU_CRGB_PIM_CFG2_BIG_ADDR(base) ((base) + (0xA0c))
#define SOC_CORE_CPU_CRGB_PIM_CFG3_BIG_ADDR(base) ((base) + (0xA10))
#define SOC_CORE_CPU_CRGB_PIM_STAT0_ADDR(base) ((base) + (0xA14))
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_ADDR(base) ((base) + (0xA18))
#define SOC_CORE_CPU_CRGB_MON_CFG1_BIG_ADDR(base) ((base) + (0xA1c))
#define SOC_CORE_CPU_CRGB_MON_CFG2_BIG_ADDR(base) ((base) + (0xA20))
#define SOC_CORE_CPU_CRGB_MON_CFG3_BIG_ADDR(base) ((base) + (0xA24))
#define SOC_CORE_CPU_CRGB_MON_CFG4_BIG_ADDR(base) ((base) + (0xA28))
#define SOC_CORE_CPU_CRGB_MON_CFG5_BIG_ADDR(base) ((base) + (0xA2c))
#define SOC_CORE_CPU_CRGB_MON_CFG6_BIG_ADDR(base) ((base) + (0xA30))
#define SOC_CORE_CPU_CRGB_MON_CFG7_BIG_ADDR(base) ((base) + (0xA34))
#define SOC_CORE_CPU_CRGB_MON_CFG8_BIG_ADDR(base) ((base) + (0xA38))
#define SOC_CORE_CPU_CRGB_MON_CFG9_BIG_ADDR(base) ((base) + (0xA3c))
#define SOC_CORE_CPU_CRGB_MON_CFG10_BIG_ADDR(base) ((base) + (0xA40))
#define SOC_CORE_CPU_CRGB_MON_CFG11_BIG_ADDR(base) ((base) + (0xA44))
#define SOC_CORE_CPU_CRGB_MON_CFG12_BIG_ADDR(base) ((base) + (0xA48))
#define SOC_CORE_CPU_CRGB_MON_CFG13_BIG_ADDR(base) ((base) + (0xA4c))
#define SOC_CORE_CPU_CRGB_MON_CFG14_BIG_ADDR(base) ((base) + (0xA50))
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_ADDR(base) ((base) + (0xA54))
#define SOC_CORE_CPU_CRGB_MON_CFG16_BIG_ADDR(base) ((base) + (0xA58))
#define SOC_CORE_CPU_CRGB_MON_STAT0_BIG_ADDR(base) ((base) + (0xA5c))
#define SOC_CORE_CPU_CRGB_MON_STAT1_BIG_ADDR(base) ((base) + (0xA60))
#define SOC_CORE_CPU_CRGB_MON_STAT2_BIG_ADDR(base) ((base) + (0xA64))
#define SOC_CORE_CPU_CRGB_MON_STAT3_BIG_ADDR(base) ((base) + (0xA68))
#define SOC_CORE_CPU_CRGB_MON_STAT4_BIG_ADDR(base) ((base) + (0xA6c))
#define SOC_CORE_CPU_CRGB_MON_STAT5_BIG_ADDR(base) ((base) + (0xA70))
#define SOC_CORE_CPU_CRGB_MON_STAT6_BIG_ADDR(base) ((base) + (0xA74))
#define SOC_CORE_CPU_CRGB_MON_STAT7_BIG_ADDR(base) ((base) + (0xA78))
#define SOC_CORE_CPU_CRGB_MON_STAT8_BIG_ADDR(base) ((base) + (0xA7c))
#define SOC_CORE_CPU_CRGB_MON_STAT9_BIG_ADDR(base) ((base) + (0xA80))
#define SOC_CORE_CPU_CRGB_MON_STAT10_BIG_ADDR(base) ((base) + (0xA84))
#define SOC_CORE_CPU_CRGB_MON_STAT11_BIG_ADDR(base) ((base) + (0xA88))
#define SOC_CORE_CPU_CRGB_MON_STAT12_BIG_ADDR(base) ((base) + (0xA8c))
#define SOC_CORE_CPU_CRGB_MON_STAT13_BIG_ADDR(base) ((base) + (0xA90))
#define SOC_CORE_CPU_CRGB_MON_STAT14_BIG_ADDR(base) ((base) + (0xA94))
#define SOC_CORE_CPU_CRGB_MON_STAT15_BIG_ADDR(base) ((base) + (0xA98))
#define SOC_CORE_CPU_CRGB_MON_STAT16_BIG_ADDR(base) ((base) + (0xA9c))
#define SOC_CORE_CPU_CRGB_MON_STAT17_BIG_ADDR(base) ((base) + (0xAA0))
#define SOC_CORE_CPU_CRGB_MON_STAT18_BIG_ADDR(base) ((base) + (0xAA4))
#define SOC_CORE_CPU_CRGB_MON_STAT19_BIG_ADDR(base) ((base) + (0xAA8))
#define SOC_CORE_CPU_CRGB_MON_STAT20_BIG_ADDR(base) ((base) + (0xAAC))
#define SOC_CORE_CPU_CRGB_MON_STAT21_BIG_ADDR(base) ((base) + (0xAB0))
#define SOC_CORE_CPU_CRGB_MON_STAT22_BIG_ADDR(base) ((base) + (0xAB4))
#define SOC_CORE_CPU_CRGB_MON_STAT23_BIG_ADDR(base) ((base) + (0xAB8))
#define SOC_CORE_CPU_CRGB_MON_STAT24_BIG_ADDR(base) ((base) + (0xABC))
#define SOC_CORE_CPU_CRGB_MON_STAT25_BIG_ADDR(base) ((base) + (0xAC0))
#define SOC_CORE_CPU_CRGB_CLKDIV2_ADDR(base) ((base) + (0xB04))
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_ADDR(base) ((base) + (0xB60))
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL1_ADDR(base) ((base) + (0xB64))
#define SOC_CORE_CPU_CRGB_FCG_CNT_STATE0_ADDR(base) ((base) + (0xB68))
#define SOC_CORE_CPU_CRGB_STATE1_ADDR(base) ((base) + (0xB6c))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG0_BIG_ADDR(base) ((base) + (0xC00))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG1_BIG_ADDR(base) ((base) + (0xC04))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG2_BIG_ADDR(base) ((base) + (0xC08))
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG3_BIG_ADDR(base) ((base) + (0xC0C))
#define SOC_CORE_CPU_CRGB_FCG_CFG0_BIG_ADDR(base) ((base) + (0xC18))
#define SOC_CORE_CPU_CRGB_FCG_CFG1_BIG_ADDR(base) ((base) + (0xC1C))
#define SOC_CORE_CPU_CRGB_FCG_CFG2_BIG_ADDR(base) ((base) + (0xC20))
#define SOC_CORE_CPU_CRGB_FCG_CFG3_BIG_ADDR(base) ((base) + (0xC24))
#define SOC_CORE_CPU_CRGB_FCG_CFG4_BIG_ADDR(base) ((base) + (0xC28))
#define SOC_CORE_CPU_CRGB_FCG_CFG5_BIG_ADDR(base) ((base) + (0xC2C))
#define SOC_CORE_CPU_CRGB_FCG_CFG6_BIG_ADDR(base) ((base) + (0xC30))
#define SOC_CORE_CPU_CRGB_FCG_CFG7_BIG_ADDR(base) ((base) + (0xC34))
#define SOC_CORE_CPU_CRGB_FCG_CFG8_BIG_ADDR(base) ((base) + (0xC38))
#define SOC_CORE_CPU_CRGB_FCG_CFG9_BIG_ADDR(base) ((base) + (0xC3C))
#define SOC_CORE_CPU_CRGB_FCG_CFG10_BIG_ADDR(base) ((base) + (0xC40))
#define SOC_CORE_CPU_CRGB_FCG_CFG11_BIG_ADDR(base) ((base) + (0xC44))
#define SOC_CORE_CPU_CRGB_FCG_CFG12_BIG_ADDR(base) ((base) + (0xC48))
#define SOC_CORE_CPU_CRGB_FCG_CFG13_BIG_ADDR(base) ((base) + (0xC4C))
#define SOC_CORE_CPU_CRGB_FCG_CFG14_BIG_ADDR(base) ((base) + (0xC50))
#define SOC_CORE_CPU_CRGB_FCG_CFG15_BIG_ADDR(base) ((base) + (0xC54))
#define SOC_CORE_CPU_CRGB_FCG_CFG16_BIG_ADDR(base) ((base) + (0xC58))
#define SOC_CORE_CPU_CRGB_FCG_CFG17_BIG_ADDR(base) ((base) + (0xC5C))
#define SOC_CORE_CPU_CRGB_FCG_CFG18_BIG_ADDR(base) ((base) + (0xC60))
#define SOC_CORE_CPU_CRGB_FCG_CFG19_BIG_ADDR(base) ((base) + (0xC64))
#define SOC_CORE_CPU_CRGB_FCG_CFG20_BIG_ADDR(base) ((base) + (0xC68))
#define SOC_CORE_CPU_CRGB_FCG_CFG21_BIG_ADDR(base) ((base) + (0xC6C))
#define SOC_CORE_CPU_CRGB_FCG_CFG22_BIG_ADDR(base) ((base) + (0xC70))
#define SOC_CORE_CPU_CRGB_FCG_CFG23_BIG_ADDR(base) ((base) + (0xC74))
#define SOC_CORE_CPU_CRGB_FCG_CFG24_BIG_ADDR(base) ((base) + (0xC78))
#define SOC_CORE_CPU_CRGB_FCG_CFG25_BIG_ADDR(base) ((base) + (0xC7C))
#define SOC_CORE_CPU_CRGB_FCG_CFG26_BIG_ADDR(base) ((base) + (0xC80))
#define SOC_CORE_CPU_CRGB_FCG_CFG27_BIG_ADDR(base) ((base) + (0xC84))
#define SOC_CORE_CPU_CRGB_FCG_STAT0_BIG_ADDR(base) ((base) + (0xC90))
#define SOC_CORE_CPU_CRGB_FCG_STAT1_BIG_ADDR(base) ((base) + (0xC94))
#define SOC_CORE_CPU_CRGB_FCG_STAT2_BIG_ADDR(base) ((base) + (0xC98))
#define SOC_CORE_CPU_CRGB_FCG_STAT3_BIG_ADDR(base) ((base) + (0xC9C))
#define SOC_CORE_CPU_CRGB_FCG_STAT4_BIG_ADDR(base) ((base) + (0xCA0))
#define SOC_CORE_CPU_CRGB_FCG_STAT5_BIG_ADDR(base) ((base) + (0xCA4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_big : 1;
        unsigned int gt_clk_pim_big : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int gt_clk_fcg_freq_ctrl_big : 1;
        unsigned int gt_pclk_fcg_big : 1;
        unsigned int gt_clk_fdcs_mon_big : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
        unsigned int gt_clk_dcc_ref : 1;
        unsigned int gt_clk_dcd_ref : 1;
        unsigned int gt_pclk_dcc : 1;
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
        unsigned int reserved_13 : 7;
    } reg;
} SOC_CORE_CPU_CRGB_PEREN0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_sscg_big_START (0)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_sscg_big_END (0)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_pim_big_START (1)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_pim_big_END (1)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fdcs_xpu_ctrl_big_START (2)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fdcs_xpu_ctrl_big_END (2)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_freq_ctrl_big_START (3)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_freq_ctrl_big_END (3)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_pclk_fcg_big_START (4)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_pclk_fcg_big_END (4)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fdcs_mon_big_START (5)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fdcs_mon_big_END (5)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_dcc_ref_START (9)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_dcc_ref_END (9)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_dcd_ref_START (10)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_clk_dcd_ref_END (10)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_pclk_dcc_START (11)
#define SOC_CORE_CPU_CRGB_PEREN0_gt_pclk_dcc_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_big : 1;
        unsigned int gt_clk_pim_big : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int gt_clk_fcg_freq_ctrl_big : 1;
        unsigned int gt_pclk_fcg_big : 1;
        unsigned int gt_clk_fdcs_mon_big : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
        unsigned int gt_clk_dcc_ref : 1;
        unsigned int gt_clk_dcd_ref : 1;
        unsigned int gt_pclk_dcc : 1;
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
        unsigned int reserved_13 : 7;
    } reg;
} SOC_CORE_CPU_CRGB_PERDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_sscg_big_START (0)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_sscg_big_END (0)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_pim_big_START (1)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_pim_big_END (1)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fdcs_xpu_ctrl_big_START (2)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fdcs_xpu_ctrl_big_END (2)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_freq_ctrl_big_START (3)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_freq_ctrl_big_END (3)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_pclk_fcg_big_START (4)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_pclk_fcg_big_END (4)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fdcs_mon_big_START (5)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fdcs_mon_big_END (5)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_dcc_ref_START (9)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_dcc_ref_END (9)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_dcd_ref_START (10)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_clk_dcd_ref_END (10)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_pclk_dcc_START (11)
#define SOC_CORE_CPU_CRGB_PERDIS0_gt_pclk_dcc_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_big : 1;
        unsigned int gt_clk_pim_big : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int gt_clk_fcg_freq_ctrl_big : 1;
        unsigned int gt_pclk_fcg_big : 1;
        unsigned int gt_clk_fdcs_mon_big : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
        unsigned int gt_clk_dcc_ref : 1;
        unsigned int gt_clk_dcd_ref : 1;
        unsigned int gt_pclk_dcc : 1;
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
        unsigned int reserved_13 : 7;
    } reg;
} SOC_CORE_CPU_CRGB_PERCLKEN0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_sscg_big_START (0)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_sscg_big_END (0)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_pim_big_START (1)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_pim_big_END (1)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_big_START (2)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_big_END (2)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_freq_ctrl_big_START (3)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_freq_ctrl_big_END (3)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_pclk_fcg_big_START (4)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_pclk_fcg_big_END (4)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fdcs_mon_big_START (5)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fdcs_mon_big_END (5)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_dcc_ref_START (9)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_dcc_ref_END (9)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_dcd_ref_START (10)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_clk_dcd_ref_END (10)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_pclk_dcc_START (11)
#define SOC_CORE_CPU_CRGB_PERCLKEN0_gt_pclk_dcc_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_fcg_sscg_big : 1;
        unsigned int st_clk_pim_big : 1;
        unsigned int st_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int st_clk_fcg_freq_ctrl_big : 1;
        unsigned int st_pclk_fcg_big : 1;
        unsigned int st_clk_fdcs_mon_big : 1;
        unsigned int st_pclk_onsys_avs_cpu : 1;
        unsigned int st_clk_fcg_cnt : 1;
        unsigned int st_clk_fcg_ref : 1;
        unsigned int st_clk_dcc_ref : 1;
        unsigned int st_clk_dcd_ref : 1;
        unsigned int st_pclk_dcc : 1;
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
        unsigned int reserved_13 : 7;
    } reg;
} SOC_CORE_CPU_CRGB_PERSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_sscg_big_START (0)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_sscg_big_END (0)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_pim_big_START (1)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_pim_big_END (1)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fdcs_xpu_ctrl_big_START (2)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fdcs_xpu_ctrl_big_END (2)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_freq_ctrl_big_START (3)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_freq_ctrl_big_END (3)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_pclk_fcg_big_START (4)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_pclk_fcg_big_END (4)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fdcs_mon_big_START (5)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fdcs_mon_big_END (5)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_dcc_ref_START (9)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_dcc_ref_END (9)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_dcd_ref_START (10)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_clk_dcd_ref_END (10)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_pclk_dcc_START (11)
#define SOC_CORE_CPU_CRGB_PERSTAT0_st_pclk_dcc_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_big : 1;
        unsigned int ip_rst_fdcs_mon_big : 1;
        unsigned int ip_prst_fcg_big : 1;
        unsigned int ip_rst_fcg_freq_ctrl_big : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_big : 1;
        unsigned int ip_prst_dcc : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
    } reg;
} SOC_CORE_CPU_CRGB_PERRSTEN0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_big_START (0)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_big_END (0)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fdcs_mon_big_START (1)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fdcs_mon_big_END (1)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_prst_fcg_big_START (2)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_prst_fcg_big_END (2)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fcg_freq_ctrl_big_START (3)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fcg_freq_ctrl_big_END (3)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fcg_freq_cnt_big_START (5)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_rst_fcg_freq_cnt_big_END (5)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_prst_dcc_START (6)
#define SOC_CORE_CPU_CRGB_PERRSTEN0_ip_prst_dcc_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_big : 1;
        unsigned int ip_rst_fdcs_mon_big : 1;
        unsigned int ip_prst_fcg_big : 1;
        unsigned int ip_rst_fcg_freq_ctrl_big : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_big : 1;
        unsigned int ip_prst_dcc : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
    } reg;
} SOC_CORE_CPU_CRGB_PERRSTDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_big_START (0)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_big_END (0)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fdcs_mon_big_START (1)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fdcs_mon_big_END (1)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_prst_fcg_big_START (2)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_prst_fcg_big_END (2)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fcg_freq_ctrl_big_START (3)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fcg_freq_ctrl_big_END (3)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fcg_freq_cnt_big_START (5)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_rst_fcg_freq_cnt_big_END (5)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_prst_dcc_START (6)
#define SOC_CORE_CPU_CRGB_PERRSTDIS0_ip_prst_dcc_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_big : 1;
        unsigned int ip_rst_fdcs_mon_big : 1;
        unsigned int ip_prst_fcg_big : 1;
        unsigned int ip_rst_fcg_freq_ctrl_big : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_big : 1;
        unsigned int ip_prst_dcc : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
    } reg;
} SOC_CORE_CPU_CRGB_PERRSTSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_big_START (0)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_big_END (0)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fdcs_mon_big_START (1)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fdcs_mon_big_END (1)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_prst_fcg_big_START (2)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_prst_fcg_big_END (2)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_big_START (3)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_big_END (3)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fcg_freq_cnt_big_START (5)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_rst_fcg_freq_cnt_big_END (5)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_prst_dcc_START (6)
#define SOC_CORE_CPU_CRGB_PERRSTSTAT0_ip_prst_dcc_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_fcg_big_tp : 1;
        unsigned int div_fcg_big_tp : 6;
        unsigned int temp_code_bypass : 1;
        unsigned int sel_clk_fcg_tp_out : 1;
        unsigned int dcc_bypass : 1;
        unsigned int temp_update_enable : 1;
        unsigned int sc_fcg_cfg_gt_bypass : 1;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_CLKDIV0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_CLKDIV0_sc_gt_clk_fcg_big_tp_START (0)
#define SOC_CORE_CPU_CRGB_CLKDIV0_sc_gt_clk_fcg_big_tp_END (0)
#define SOC_CORE_CPU_CRGB_CLKDIV0_div_fcg_big_tp_START (1)
#define SOC_CORE_CPU_CRGB_CLKDIV0_div_fcg_big_tp_END (6)
#define SOC_CORE_CPU_CRGB_CLKDIV0_temp_code_bypass_START (7)
#define SOC_CORE_CPU_CRGB_CLKDIV0_temp_code_bypass_END (7)
#define SOC_CORE_CPU_CRGB_CLKDIV0_sel_clk_fcg_tp_out_START (8)
#define SOC_CORE_CPU_CRGB_CLKDIV0_sel_clk_fcg_tp_out_END (8)
#define SOC_CORE_CPU_CRGB_CLKDIV0_dcc_bypass_START (9)
#define SOC_CORE_CPU_CRGB_CLKDIV0_dcc_bypass_END (9)
#define SOC_CORE_CPU_CRGB_CLKDIV0_temp_update_enable_START (10)
#define SOC_CORE_CPU_CRGB_CLKDIV0_temp_update_enable_END (10)
#define SOC_CORE_CPU_CRGB_CLKDIV0_sc_fcg_cfg_gt_bypass_START (11)
#define SOC_CORE_CPU_CRGB_CLKDIV0_sc_fcg_cfg_gt_bypass_END (11)
#define SOC_CORE_CPU_CRGB_CLKDIV0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_drop_en_bypass : 1;
        unsigned int pim_peaklow_en_bypass : 1;
        unsigned int pim_drop_update_bypass : 1;
        unsigned int cnt_thr : 4;
        unsigned int ffc_en_bypass : 1;
        unsigned int ffc_cnt_thr : 2;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_pim_drop_en_bypass_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_pim_drop_en_bypass_END (0)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_pim_peaklow_en_bypass_START (1)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_pim_peaklow_en_bypass_END (1)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_pim_drop_update_bypass_START (2)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_pim_drop_update_bypass_END (2)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_cnt_thr_START (3)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_cnt_thr_END (6)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_ffc_en_bypass_START (7)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_ffc_en_bypass_END (7)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_ffc_cnt_thr_START (8)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_ffc_cnt_thr_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_FDCS_XPU_CFG_BIG_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
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
} SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_pcr_trig_vdm_en_START (0)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_pcr_trig_vdm_en_END (0)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_wfx_bypass_START (1)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_wfx_bypass_END (4)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_l2_idle_div_mod_START (5)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_l2_idle_div_mod_END (5)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_freq_dn_mst_sel_START (6)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_freq_dn_mst_sel_END (6)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_wake_up_mode_START (23)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_wake_up_mode_END (24)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_l2_idle_gt_en_START (26)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_cpu_l2_idle_gt_en_END (26)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_vbat_drop_icg_en_START (27)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_vbat_drop_icg_en_END (27)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_vbat_drop_fcg_en_START (28)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_vbat_drop_fcg_en_END (28)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_coreidle_bypass_START (29)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_coreidle_bypass_END (29)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_pcr_fs_icg_en_START (30)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_pcr_fs_icg_en_END (30)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_pcr_fs_fcg_en_START (31)
#define SOC_CORE_CPU_CRGB_FCG_FREQ_CTRL_BIG_pcr_fs_fcg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg_rsv_big : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG_RSV1_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG_RSV1_fcg_cfg_rsv_big_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG_RSV1_fcg_cfg_rsv_big_END (15)
#define SOC_CORE_CPU_CRGB_FCG_CFG_RSV1_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_FCG_CFG_RSV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_rate : 4;
        unsigned int sscg_depth : 3;
        unsigned int sscg_fast_dis : 1;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_enable_START (0)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_enable_END (0)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_mode_START (1)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_mode_END (1)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_rate_START (2)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_rate_END (5)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_depth_START (6)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_depth_END (8)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_fast_dis_START (9)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_sscg_fast_dis_END (9)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_SSC_FCG_CFG_BIG_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat_big : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_STAT0_fcg_stat_big_START (0)
#define SOC_CORE_CPU_CRGB_FCG_STAT0_fcg_stat_big_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_cpu_big0 : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_FCM_CLKEN_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCM_CLKEN_gt_clk_cpu_big0_START (0)
#define SOC_CORE_CPU_CRGB_FCM_CLKEN_gt_clk_cpu_big0_END (0)
#define SOC_CORE_CPU_CRGB_FCM_CLKEN_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_FCM_CLKEN_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsv_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_RSV_CFG0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_RSV_CFG0_rsv_cfg0_START (0)
#define SOC_CORE_CPU_CRGB_RSV_CFG0_rsv_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int onsys_avs_cfg_c : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_ONSYS_AVS_CFG_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_CFG_C_onsys_avs_cfg_c_START (0)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_CFG_C_onsys_avs_cfg_c_END (15)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_CFG_C_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_CFG_C_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_monitor_time_c : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGB_ONSYS_AVS_TIME_CFG_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_TIME_CFG_C_apb_monitor_time_c_START (0)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_TIME_CFG_C_apb_monitor_time_c_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vs_th1_c : 16;
        unsigned int apb_vs_th2_c : 16;
    } reg;
} SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_0_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_0_C_apb_vs_th1_c_START (0)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_0_C_apb_vs_th1_c_END (15)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_0_C_apb_vs_th2_c_START (16)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_0_C_apb_vs_th2_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vs_th3_c : 16;
        unsigned int apb_vol_sub_min_c : 8;
        unsigned int apb_vol_add_max_c : 8;
    } reg;
} SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_apb_vs_th3_c_START (0)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_apb_vs_th3_c_END (15)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_apb_vol_sub_min_c_START (16)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_apb_vol_sub_min_c_END (23)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_apb_vol_add_max_c_START (24)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VS_TH_1_C_apb_vol_add_max_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vol_cfg1_c : 8;
        unsigned int apb_vol_cfg2_c : 8;
        unsigned int apb_vol_cfg3_c : 8;
        unsigned int apb_vol_cfg4_c : 8;
    } reg;
} SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg1_c_START (0)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg1_c_END (7)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg2_c_START (8)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg2_c_END (15)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg3_c_START (16)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg3_c_END (23)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg4_c_START (24)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg4_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vol_idx_c : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_IDX_UNION;
#endif
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_IDX_apb_vol_idx_c_START (0)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_VOL_IDX_apb_vol_idx_c_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_cur_stat_c : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int apb_vol_sub_flag_c : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int apb_cnt_us : 8;
        unsigned int reserved_6 : 12;
    } reg;
} SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_UNION;
#endif
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_apb_cur_stat_c_START (0)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_apb_cur_stat_c_END (1)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_apb_vol_sub_flag_c_START (8)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_apb_vol_sub_flag_c_END (8)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_apb_cnt_us_START (12)
#define SOC_CORE_CPU_CRGB_ONSYS_AVS_APB_READ_apb_cnt_us_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int apb_onsys_enable_c : 1;
        unsigned int reserved_1 : 13;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_CORE_CPU_CRGB_APB_ONSYS_ENABLE_UNION;
#endif
#define SOC_CORE_CPU_CRGB_APB_ONSYS_ENABLE_apb_onsys_enable_c_START (2)
#define SOC_CORE_CPU_CRGB_APB_ONSYS_ENABLE_apb_onsys_enable_c_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg0 : 10;
        unsigned int coef_cfg1 : 10;
        unsigned int coef_cfg2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_coef_cfg0_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_coef_cfg0_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_coef_cfg1_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_coef_cfg1_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_coef_cfg2_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG0_C_coef_cfg2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg3 : 10;
        unsigned int coef_cfg4 : 10;
        unsigned int coef_cfg5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_coef_cfg3_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_coef_cfg3_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_coef_cfg4_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_coef_cfg4_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_coef_cfg5_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG1_C_coef_cfg5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg6 : 10;
        unsigned int coef_cfg7 : 10;
        unsigned int coef_cfg8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_coef_cfg6_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_coef_cfg6_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_coef_cfg7_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_coef_cfg7_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_coef_cfg8_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG2_C_coef_cfg8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg9 : 10;
        unsigned int coef_cfg10 : 10;
        unsigned int coef_cfg11 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_coef_cfg9_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_coef_cfg9_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_coef_cfg10_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_coef_cfg10_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_coef_cfg11_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG3_C_coef_cfg11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg12 : 10;
        unsigned int coef_cfg13 : 10;
        unsigned int coef_cfg14 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_coef_cfg12_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_coef_cfg12_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_coef_cfg13_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_coef_cfg13_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_coef_cfg14_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG4_C_coef_cfg14_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg15 : 10;
        unsigned int coef_cfg16 : 10;
        unsigned int coef_cfg17 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_coef_cfg15_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_coef_cfg15_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_coef_cfg16_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_coef_cfg16_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_coef_cfg17_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG5_C_coef_cfg17_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg18 : 10;
        unsigned int coef_cfg19 : 10;
        unsigned int coef_cfg20 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_coef_cfg18_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_coef_cfg18_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_coef_cfg19_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_coef_cfg19_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_coef_cfg20_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG6_C_coef_cfg20_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_cfg21 : 10;
        unsigned int coef_cfg22 : 10;
        unsigned int coef_cfg23 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_coef_cfg21_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_coef_cfg21_END (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_coef_cfg22_START (10)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_coef_cfg22_END (19)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_coef_cfg23_START (20)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG7_C_coef_cfg23_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_w0 : 8;
        unsigned int coef_w1 : 8;
        unsigned int coef_w2 : 8;
        unsigned int coef_w3 : 8;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w0_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w0_END (7)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w1_START (8)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w1_END (15)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w2_START (16)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w2_END (23)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w3_START (24)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG8_C_coef_w3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coef_w4 : 8;
        unsigned int coef_m : 5;
        unsigned int reserved : 19;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG9_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG9_C_coef_w4_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG9_C_coef_w4_END (7)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG9_C_coef_m_START (8)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG9_C_coef_m_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int accu_fd_thr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG10_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG10_C_accu_fd_thr_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG10_C_accu_fd_thr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vol_max_thr : 9;
        unsigned int vol_min_thr : 9;
        unsigned int vol_add : 4;
        unsigned int vol_add_bypass : 1;
        unsigned int fdcs_onsys_cfg11_c : 9;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_max_thr_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_max_thr_END (8)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_min_thr_START (9)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_min_thr_END (17)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_add_START (18)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_add_END (21)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_add_bypass_START (22)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_vol_add_bypass_END (22)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_fdcs_onsys_cfg11_c_START (23)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG11_C_fdcs_onsys_cfg11_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_cfg12_c : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG12_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG12_C_fdcs_onsys_cfg12_c_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG12_C_fdcs_onsys_cfg12_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_cfg13_c : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG13_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG13_C_fdcs_onsys_cfg13_c_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_CFG13_C_fdcs_onsys_cfg13_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FDCS_ONSYS_STAT_C_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_STAT_C_fdcs_onsys_stat0_START (0)
#define SOC_CORE_CPU_CRGB_FDCS_ONSYS_STAT_C_fdcs_onsys_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_big_clkrst_bypass : 1;
        unsigned int dcc_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 27;
    } reg;
} SOC_CORE_CPU_CRGB_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_IPCLKRST_BYPASS0_fcg_big_clkrst_bypass_START (0)
#define SOC_CORE_CPU_CRGB_IPCLKRST_BYPASS0_fcg_big_clkrst_bypass_END (0)
#define SOC_CORE_CPU_CRGB_IPCLKRST_BYPASS0_dcc_clkrst_bypass_START (1)
#define SOC_CORE_CPU_CRGB_IPCLKRST_BYPASS0_dcc_clkrst_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_drop_en_big : 1;
        unsigned int pim_ost_en_big : 1;
        unsigned int pim_peaklow_en_big : 1;
        unsigned int pim_debug_big : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_PIM_CTRL0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_drop_en_big_START (0)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_drop_en_big_END (0)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_ost_en_big_START (1)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_ost_en_big_END (1)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_peaklow_en_big_START (2)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_peaklow_en_big_END (2)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_debug_big_START (3)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_pim_debug_big_END (3)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_PIM_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
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
} SOC_CORE_CPU_CRGB_PIM_CFG0_BIG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
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
} SOC_CORE_CPU_CRGB_PIM_CFG1_BIG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
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
} SOC_CORE_CPU_CRGB_PIM_CFG2_BIG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
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
} SOC_CORE_CPU_CRGB_PIM_CFG3_BIG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_peaklow_code_big : 16;
        unsigned int pim_peaklow_ready_big : 1;
        unsigned int pim_flag_ready_big : 1;
        unsigned int pim_flag_l_big : 1;
        unsigned int pim_flag_h_big : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_PIM_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_peaklow_code_big_START (0)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_peaklow_code_big_END (15)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_peaklow_ready_big_START (16)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_peaklow_ready_big_END (16)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_flag_ready_big_START (17)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_flag_ready_big_END (17)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_flag_l_big_START (18)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_flag_l_big_END (18)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_flag_h_big_START (19)
#define SOC_CORE_CPU_CRGB_PIM_STAT0_pim_flag_h_big_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_timer_en : 1;
        unsigned int accu_fd_en : 1;
        unsigned int peaklow_en : 1;
        unsigned int clear_all_en : 1;
        unsigned int cnt_timer_hd_en : 1;
        unsigned int hw_fsm_mode : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_cnt_timer_en_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_cnt_timer_en_END (0)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_accu_fd_en_START (1)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_accu_fd_en_END (1)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_peaklow_en_START (2)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_peaklow_en_END (2)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_clear_all_en_START (3)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_clear_all_en_END (3)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_cnt_timer_hd_en_START (4)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_cnt_timer_hd_en_END (4)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_hw_fsm_mode_START (5)
#define SOC_CORE_CPU_CRGB_MON_CFG0_BIG_hw_fsm_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG1_BIG_read_lock_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG1_BIG_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG2_BIG_bin_peaklow_en_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG2_BIG_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG3_BIG_vth0_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG3_BIG_vth0_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG3_BIG_vth1_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG3_BIG_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG4_BIG_vth2_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG4_BIG_vth2_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG4_BIG_vth3_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG4_BIG_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG5_BIG_vth4_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG5_BIG_vth4_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG5_BIG_vth5_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG5_BIG_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG6_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG6_BIG_vth6_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG6_BIG_vth6_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG6_BIG_vth7_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG6_BIG_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG7_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG7_BIG_vth8_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG7_BIG_vth8_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG7_BIG_vth9_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG7_BIG_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG8_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG8_BIG_vth10_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG8_BIG_vth10_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG8_BIG_vth11_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG8_BIG_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG9_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG9_BIG_vth12_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG9_BIG_vth12_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG9_BIG_vth13_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG9_BIG_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG10_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG10_BIG_vth14_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG10_BIG_vth14_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG10_BIG_vth15_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG10_BIG_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG11_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG11_BIG_vth16_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG11_BIG_vth16_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG11_BIG_vth17_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG11_BIG_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG12_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG12_BIG_vth18_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG12_BIG_vth18_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG12_BIG_vth19_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG12_BIG_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG13_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG13_BIG_vth20_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG13_BIG_vth20_peaklow_END (15)
#define SOC_CORE_CPU_CRGB_MON_CFG13_BIG_vth21_peaklow_START (16)
#define SOC_CORE_CPU_CRGB_MON_CFG13_BIG_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG14_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG14_BIG_vth22_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG14_BIG_vth22_peaklow_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_timer_hd_th : 22;
        unsigned int reserved : 8;
        unsigned int read_lock_mode : 1;
        unsigned int sel_peaklow_vth : 1;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG15_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_cnt_timer_hd_th_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_cnt_timer_hd_th_END (21)
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_read_lock_mode_START (30)
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_read_lock_mode_END (30)
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_sel_peaklow_vth_START (31)
#define SOC_CORE_CPU_CRGB_MON_CFG15_BIG_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGB_MON_CFG16_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_CFG16_BIG_pim_peaklow_vth_START (0)
#define SOC_CORE_CPU_CRGB_MON_CFG16_BIG_pim_peaklow_vth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_timer : 22;
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT0_BIG_cnt_timer_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT0_BIG_cnt_timer_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int accu_fd : 25;
        unsigned int reserved_0: 3;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT1_BIG_accu_fd_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT1_BIG_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT2_BIG_bin0_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT2_BIG_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT3_BIG_bin1_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT3_BIG_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT4_BIG_bin2_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT4_BIG_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT5_BIG_bin3_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT5_BIG_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT6_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT6_BIG_bin4_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT6_BIG_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT7_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT7_BIG_bin5_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT7_BIG_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT8_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT8_BIG_bin6_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT8_BIG_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT9_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT9_BIG_bin7_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT9_BIG_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT10_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT10_BIG_bin8_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT10_BIG_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT11_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT11_BIG_bin9_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT11_BIG_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT12_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT12_BIG_bin10_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT12_BIG_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT13_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT13_BIG_bin11_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT13_BIG_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT14_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT14_BIG_bin12_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT14_BIG_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT15_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT15_BIG_bin13_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT15_BIG_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT16_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT16_BIG_bin14_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT16_BIG_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT17_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT17_BIG_bin15_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT17_BIG_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT18_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT18_BIG_bin16_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT18_BIG_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT19_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT19_BIG_bin17_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT19_BIG_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT20_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT20_BIG_bin18_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT20_BIG_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT21_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT21_BIG_bin19_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT21_BIG_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT22_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT22_BIG_bin20_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT22_BIG_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT23_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT23_BIG_bin21_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT23_BIG_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT24_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT24_BIG_bin22_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT24_BIG_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGB_MON_STAT25_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_MON_STAT25_BIG_bin23_peaklow_START (0)
#define SOC_CORE_CPU_CRGB_MON_STAT25_BIG_bin23_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_fcg_ref : 1;
        unsigned int sc_gt_clk_fcg_cnt : 1;
        unsigned int div_clk_fcg_cnt : 6;
        unsigned int div_clk_fcg_ref : 6;
        unsigned int sel_fcg_lock : 1;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_CLKDIV2_UNION;
#endif
#define SOC_CORE_CPU_CRGB_CLKDIV2_sc_gt_clk_fcg_ref_START (0)
#define SOC_CORE_CPU_CRGB_CLKDIV2_sc_gt_clk_fcg_ref_END (0)
#define SOC_CORE_CPU_CRGB_CLKDIV2_sc_gt_clk_fcg_cnt_START (1)
#define SOC_CORE_CPU_CRGB_CLKDIV2_sc_gt_clk_fcg_cnt_END (1)
#define SOC_CORE_CPU_CRGB_CLKDIV2_div_clk_fcg_cnt_START (2)
#define SOC_CORE_CPU_CRGB_CLKDIV2_div_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGB_CLKDIV2_div_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGB_CLKDIV2_div_clk_fcg_ref_END (13)
#define SOC_CORE_CPU_CRGB_CLKDIV2_sel_fcg_lock_START (14)
#define SOC_CORE_CPU_CRGB_CLKDIV2_sel_fcg_lock_END (14)
#define SOC_CORE_CPU_CRGB_CLKDIV2_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_freq_en : 1;
        unsigned int fcg_freq_clr : 1;
        unsigned int fcg_freq_lock : 1;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_fcg_freq_en_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_fcg_freq_en_END (0)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_fcg_freq_clr_START (1)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_fcg_freq_clr_END (1)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_fcg_freq_lock_START (2)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_fcg_freq_lock_END (2)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cnt_set : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CNT_CTRL1_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL1_fcg_cnt_set_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL1_fcg_cnt_set_END (15)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL1_bitmasken_START (16)
#define SOC_CORE_CPU_CRGB_FCG_CNT_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_freq_cnt_lock : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CNT_STATE0_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CNT_STATE0_fcg_freq_cnt_lock_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CNT_STATE0_fcg_freq_cnt_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcc_lock : 1;
        unsigned int dcc_err : 1;
        unsigned int fcg_lock_big : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CORE_CPU_CRGB_STATE1_UNION;
#endif
#define SOC_CORE_CPU_CRGB_STATE1_dcc_lock_START (0)
#define SOC_CORE_CPU_CRGB_STATE1_dcc_lock_END (0)
#define SOC_CORE_CPU_CRGB_STATE1_dcc_err_START (1)
#define SOC_CORE_CPU_CRGB_STATE1_dcc_err_END (1)
#define SOC_CORE_CPU_CRGB_STATE1_fcg_lock_big_START (2)
#define SOC_CORE_CPU_CRGB_STATE1_fcg_lock_big_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_ANA_CFG0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG0_BIG_d2a_fcg_ana_cfg0_START (0)
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG0_BIG_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_ANA_CFG1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG1_BIG_d2a_fcg_ana_cfg1_START (0)
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG1_BIG_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_ANA_CFG2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG2_BIG_d2a_fcg_ana_cfg2_START (0)
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG2_BIG_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_ANA_CFG3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG3_BIG_d2a_fcg_ana_cfg3_START (0)
#define SOC_CORE_CPU_CRGB_FCG_ANA_CFG3_BIG_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG0_BIG_fcg_cfg0_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG0_BIG_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG1_BIG_fcg_cfg1_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG1_BIG_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG2_BIG_fcg_cfg2_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG2_BIG_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG3_BIG_fcg_cfg3_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG3_BIG_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG4_BIG_fcg_cfg4_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG4_BIG_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG5_BIG_fcg_cfg5_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG5_BIG_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG6_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG6_BIG_fcg_cfg6_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG6_BIG_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG7_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG7_BIG_fcg_cfg7_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG7_BIG_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG8_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG8_BIG_fcg_cfg8_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG8_BIG_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG9_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG9_BIG_fcg_cfg9_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG9_BIG_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG10_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG10_BIG_fcg_cfg10_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG10_BIG_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG11_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG11_BIG_fcg_cfg11_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG11_BIG_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG12_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG12_BIG_fcg_cfg12_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG12_BIG_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG13_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG13_BIG_fcg_cfg13_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG13_BIG_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG14_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG14_BIG_fcg_cfg14_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG14_BIG_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG15_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG15_BIG_fcg_cfg15_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG15_BIG_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG16_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG16_BIG_fcg_cfg16_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG16_BIG_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG17_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG17_BIG_fcg_cfg17_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG17_BIG_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG18_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG18_BIG_fcg_cfg18_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG18_BIG_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG19_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG19_BIG_fcg_cfg19_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG19_BIG_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG20_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG20_BIG_fcg_cfg20_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG20_BIG_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG21_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG21_BIG_fcg_cfg21_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG21_BIG_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG22_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG22_BIG_fcg_cfg22_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG22_BIG_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG23_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG23_BIG_fcg_cfg23_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG23_BIG_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG24_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG24_BIG_fcg_cfg24_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG24_BIG_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG25_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG25_BIG_fcg_cfg25_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG25_BIG_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG26_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG26_BIG_fcg_cfg26_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG26_BIG_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_CFG27_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_CFG27_BIG_fcg_cfg27_START (0)
#define SOC_CORE_CPU_CRGB_FCG_CFG27_BIG_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_STAT0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_STAT0_BIG_fcg_stat0_START (0)
#define SOC_CORE_CPU_CRGB_FCG_STAT0_BIG_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_STAT1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_STAT1_BIG_fcg_stat1_START (0)
#define SOC_CORE_CPU_CRGB_FCG_STAT1_BIG_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_STAT2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_STAT2_BIG_fcg_stat2_START (0)
#define SOC_CORE_CPU_CRGB_FCG_STAT2_BIG_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_STAT3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_STAT3_BIG_fcg_stat3_START (0)
#define SOC_CORE_CPU_CRGB_FCG_STAT3_BIG_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_STAT4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_STAT4_BIG_fcg_stat4_START (0)
#define SOC_CORE_CPU_CRGB_FCG_STAT4_BIG_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_CORE_CPU_CRGB_FCG_STAT5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRGB_FCG_STAT5_BIG_fcg_stat5_START (0)
#define SOC_CORE_CPU_CRGB_FCG_STAT5_BIG_fcg_stat5_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
