#ifndef __SOC_GPUCRG_INTERFACE_H__
#define __SOC_GPUCRG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_GPUCRG_PEREN0_ADDR(base) (base)
#define SOC_GPUCRG_PERDIS0_ADDR(base) ((base) + 0x004UL)
#define SOC_GPUCRG_PERCLKEN0_ADDR(base) ((base) + 0x008UL)
#define SOC_GPUCRG_PERSTAT0_ADDR(base) ((base) + 0x00CUL)
#define SOC_GPUCRG_PERRSTEN0_ADDR(base) ((base) + 0x010UL)
#define SOC_GPUCRG_PERRSTDIS0_ADDR(base) ((base) + 0x014UL)
#define SOC_GPUCRG_PERRSTSTAT0_ADDR(base) ((base) + 0x018UL)
#define SOC_GPUCRG_FCG_STAT_ADDR(base) ((base) + 0x020UL)
#define SOC_GPUCRG_GPU_CRG_STAT_ADDR(base) ((base) + 0x024UL)
#define SOC_GPUCRG_FCG_STAT_FCM_ADDR(base) ((base) + 0x028UL)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_ADDR(base) ((base) + 0x030UL)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_ADDR(base) ((base) + 0x034UL)
#define SOC_GPUCRG_FCG_CFG_RSV0_ADDR(base) ((base) + 0x040UL)
#define SOC_GPUCRG_FCG_CFG_RSV1_ADDR(base) ((base) + 0x044UL)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_ADDR(base) ((base) + 0x050UL)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_ADDR(base) ((base) + 0x054UL)
#define SOC_GPUCRG_GPU_CLKDIV0_ADDR(base) ((base) + 0x058UL)
#define SOC_GPUCRG_PIM_CTRL0_ADDR(base) ((base) + 0x400UL)
#define SOC_GPUCRG_PIM_CFG0_GPU_ADDR(base) ((base) + 0x404UL)
#define SOC_GPUCRG_PIM_CFG1_GPU_ADDR(base) ((base) + 0x408UL)
#define SOC_GPUCRG_PIM_STAT0_ADDR(base) ((base) + 0x40CUL)
#define SOC_GPUCRG_PIM_CFG2_GPU_ADDR(base) ((base) + 0x410UL)
#define SOC_GPUCRG_PIM_CFG3_GPU_ADDR(base) ((base) + 0x414UL)
#define SOC_GPUCRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x800UL)
#define SOC_GPUCRG_FCG_ANA_CFG0_GPU_ADDR(base) ((base) + 0xE00UL)
#define SOC_GPUCRG_FCG_ANA_CFG1_GPU_ADDR(base) ((base) + 0xE04UL)
#define SOC_GPUCRG_FCG_ANA_CFG2_GPU_ADDR(base) ((base) + 0xE08UL)
#define SOC_GPUCRG_FCG_ANA_CFG3_GPU_ADDR(base) ((base) + 0xE0CUL)
#define SOC_GPUCRG_FCG_CFG0_GPU_ADDR(base) ((base) + 0xE18UL)
#define SOC_GPUCRG_FCG_CFG1_GPU_ADDR(base) ((base) + 0xE1CUL)
#define SOC_GPUCRG_FCG_CFG2_GPU_ADDR(base) ((base) + 0xE20UL)
#define SOC_GPUCRG_FCG_CFG3_GPU_ADDR(base) ((base) + 0xE24UL)
#define SOC_GPUCRG_FCG_CFG4_GPU_ADDR(base) ((base) + 0xE28UL)
#define SOC_GPUCRG_FCG_CFG5_GPU_ADDR(base) ((base) + 0xE2CUL)
#define SOC_GPUCRG_FCG_CFG6_GPU_ADDR(base) ((base) + 0xE30UL)
#define SOC_GPUCRG_FCG_CFG7_GPU_ADDR(base) ((base) + 0xE34UL)
#define SOC_GPUCRG_FCG_CFG8_GPU_ADDR(base) ((base) + 0xE38UL)
#define SOC_GPUCRG_FCG_CFG9_GPU_ADDR(base) ((base) + 0xE3CUL)
#define SOC_GPUCRG_FCG_CFG10_GPU_ADDR(base) ((base) + 0xE40UL)
#define SOC_GPUCRG_FCG_CFG11_GPU_ADDR(base) ((base) + 0xE44UL)
#define SOC_GPUCRG_FCG_CFG12_GPU_ADDR(base) ((base) + 0xE48UL)
#define SOC_GPUCRG_FCG_CFG13_GPU_ADDR(base) ((base) + 0xE4CUL)
#define SOC_GPUCRG_FCG_CFG14_GPU_ADDR(base) ((base) + 0xE50UL)
#define SOC_GPUCRG_FCG_CFG15_GPU_ADDR(base) ((base) + 0xE54UL)
#define SOC_GPUCRG_FCG_CFG16_GPU_ADDR(base) ((base) + 0xE58UL)
#define SOC_GPUCRG_FCG_CFG17_GPU_ADDR(base) ((base) + 0xE5CUL)
#define SOC_GPUCRG_FCG_CFG18_GPU_ADDR(base) ((base) + 0xE60UL)
#define SOC_GPUCRG_FCG_CFG19_GPU_ADDR(base) ((base) + 0xE64UL)
#define SOC_GPUCRG_FCG_CFG20_GPU_ADDR(base) ((base) + 0xE68UL)
#define SOC_GPUCRG_FCG_CFG21_GPU_ADDR(base) ((base) + 0xE6CUL)
#define SOC_GPUCRG_FCG_CFG22_GPU_ADDR(base) ((base) + 0xE70UL)
#define SOC_GPUCRG_FCG_CFG23_GPU_ADDR(base) ((base) + 0xE74UL)
#define SOC_GPUCRG_FCG_CFG24_GPU_ADDR(base) ((base) + 0xE78UL)
#define SOC_GPUCRG_FCG_CFG25_GPU_ADDR(base) ((base) + 0xE7CUL)
#define SOC_GPUCRG_FCG_CFG26_GPU_ADDR(base) ((base) + 0xE80UL)
#define SOC_GPUCRG_FCG_CFG27_GPU_ADDR(base) ((base) + 0xE84UL)
#define SOC_GPUCRG_FCG_STAT0_GPU_ADDR(base) ((base) + 0xE90UL)
#define SOC_GPUCRG_FCG_STAT1_GPU_ADDR(base) ((base) + 0xE94UL)
#define SOC_GPUCRG_FCG_STAT2_GPU_ADDR(base) ((base) + 0xE98UL)
#define SOC_GPUCRG_FCG_STAT3_GPU_ADDR(base) ((base) + 0xE9CUL)
#define SOC_GPUCRG_FCG_STAT4_GPU_ADDR(base) ((base) + 0xEA0UL)
#define SOC_GPUCRG_FCG_STAT5_GPU_ADDR(base) ((base) + 0xEA4UL)
#define SOC_GPUCRG_ONSYS_AVS_CNT_US_GPU_ADDR(base) ((base) + 0x53cUL)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_ADDR(base) ((base) + 0x540UL)
#define SOC_GPUCRG_ONSYS_AVS_ENABLE_GPU_ADDR(base) ((base) + 0x544UL)
#define SOC_GPUCRG_ONSYS_AVS_TIME_CFG_GPU_ADDR(base) ((base) + 0x548UL)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_0_GPU_ADDR(base) ((base) + 0x54cUL)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_1_GPU_ADDR(base) ((base) + 0x550UL)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_2_GPU_ADDR(base) ((base) + 0x554UL)
#define SOC_GPUCRG_ONSYS_VOL_SUB_ADD_GPU_ADDR(base) ((base) + 0x558UL)
#define SOC_GPUCRG_ONSYS_AVS_CFG_GPU_ADDR(base) ((base) + 0x55cUL)
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_ADDR(base) ((base) + 0x560UL)
#define SOC_GPUCRG_FDCS_ONSYS_STAT_GPU_ADDR(base) ((base) + 0x564UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_ADDR(base) ((base) + 0x600UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_ADDR(base) ((base) + 0x604UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_ADDR(base) ((base) + 0x608UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_ADDR(base) ((base) + 0x60cUL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_ADDR(base) ((base) + 0x610UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_ADDR(base) ((base) + 0x614UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_ADDR(base) ((base) + 0x618UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_ADDR(base) ((base) + 0x61cUL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_ADDR(base) ((base) + 0x620UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG9_GPU_ADDR(base) ((base) + 0x624UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG10_GPU_ADDR(base) ((base) + 0x628UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_ADDR(base) ((base) + 0x62cUL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG12_GPU_ADDR(base) ((base) + 0x630UL)
#define SOC_GPUCRG_FDCS_ONSYS_CFG13_GPU_ADDR(base) ((base) + 0x634UL)
#define SOC_GPUCRG_MON_CFG0_GPU_ADDR(base) ((base) + 0x650UL)
#define SOC_GPUCRG_MON_CFG1_GPU_ADDR(base) ((base) + 0x654UL)
#define SOC_GPUCRG_MON_CFG2_GPU_ADDR(base) ((base) + 0x658UL)
#define SOC_GPUCRG_MON_CFG3_GPU_ADDR(base) ((base) + 0x65CUL)
#define SOC_GPUCRG_MON_CFG4_GPU_ADDR(base) ((base) + 0x660UL)
#define SOC_GPUCRG_MON_CFG5_GPU_ADDR(base) ((base) + 0x664UL)
#define SOC_GPUCRG_MON_CFG6_GPU_ADDR(base) ((base) + 0x668UL)
#define SOC_GPUCRG_MON_CFG7_GPU_ADDR(base) ((base) + 0x66CUL)
#define SOC_GPUCRG_MON_CFG8_GPU_ADDR(base) ((base) + 0x670UL)
#define SOC_GPUCRG_MON_CFG9_GPU_ADDR(base) ((base) + 0x674UL)
#define SOC_GPUCRG_MON_CFG10_GPU_ADDR(base) ((base) + 0x678UL)
#define SOC_GPUCRG_MON_CFG11_GPU_ADDR(base) ((base) + 0x67CUL)
#define SOC_GPUCRG_MON_CFG12_GPU_ADDR(base) ((base) + 0x680UL)
#define SOC_GPUCRG_MON_CFG13_GPU_ADDR(base) ((base) + 0x684UL)
#define SOC_GPUCRG_MON_CFG14_GPU_ADDR(base) ((base) + 0x688UL)
#define SOC_GPUCRG_MON_CFG15_GPU_ADDR(base) ((base) + 0x68CUL)
#define SOC_GPUCRG_MON_CFG16_GPU_ADDR(base) ((base) + 0x690UL)
#define SOC_GPUCRG_MON_STAT0_GPU_ADDR(base) ((base) + 0x694UL)
#define SOC_GPUCRG_MON_STAT1_GPU_ADDR(base) ((base) + 0x698UL)
#define SOC_GPUCRG_MON_STAT2_GPU_ADDR(base) ((base) + 0x69CUL)
#define SOC_GPUCRG_MON_STAT3_GPU_ADDR(base) ((base) + 0x6A0UL)
#define SOC_GPUCRG_MON_STAT4_GPU_ADDR(base) ((base) + 0x6A4UL)
#define SOC_GPUCRG_MON_STAT5_GPU_ADDR(base) ((base) + 0x6A8UL)
#define SOC_GPUCRG_MON_STAT6_GPU_ADDR(base) ((base) + 0x6ACUL)
#define SOC_GPUCRG_MON_STAT7_GPU_ADDR(base) ((base) + 0x6B0UL)
#define SOC_GPUCRG_MON_STAT8_GPU_ADDR(base) ((base) + 0x6B4UL)
#define SOC_GPUCRG_MON_STAT9_GPU_ADDR(base) ((base) + 0x6B8UL)
#define SOC_GPUCRG_MON_STAT10_GPU_ADDR(base) ((base) + 0x6BCUL)
#define SOC_GPUCRG_MON_STAT11_GPU_ADDR(base) ((base) + 0x6C0UL)
#define SOC_GPUCRG_MON_STAT12_GPU_ADDR(base) ((base) + 0x6C4UL)
#define SOC_GPUCRG_MON_STAT13_GPU_ADDR(base) ((base) + 0x6C8UL)
#define SOC_GPUCRG_MON_STAT14_GPU_ADDR(base) ((base) + 0x6CCUL)
#define SOC_GPUCRG_MON_STAT15_GPU_ADDR(base) ((base) + 0x6D0UL)
#define SOC_GPUCRG_MON_STAT16_GPU_ADDR(base) ((base) + 0x6D4UL)
#define SOC_GPUCRG_MON_STAT17_GPU_ADDR(base) ((base) + 0x6D8UL)
#define SOC_GPUCRG_MON_STAT18_GPU_ADDR(base) ((base) + 0x6DCUL)
#define SOC_GPUCRG_MON_STAT19_GPU_ADDR(base) ((base) + 0x6E0UL)
#define SOC_GPUCRG_MON_STAT20_GPU_ADDR(base) ((base) + 0x6E4UL)
#define SOC_GPUCRG_MON_STAT21_GPU_ADDR(base) ((base) + 0x6E8UL)
#define SOC_GPUCRG_MON_STAT22_GPU_ADDR(base) ((base) + 0x6ECUL)
#define SOC_GPUCRG_MON_STAT23_GPU_ADDR(base) ((base) + 0x6F0UL)
#define SOC_GPUCRG_MON_STAT24_GPU_ADDR(base) ((base) + 0x6F4UL)
#define SOC_GPUCRG_MON_STAT25_GPU_ADDR(base) ((base) + 0x6F8UL)
#define SOC_GPUCRG_FDCS_XPU_CFG_ADDR(base) ((base) + 0x700UL)
#define SOC_GPUCRG_FCG_ANA_CFG0_FCM_ADDR(base) ((base) + 0xF00UL)
#define SOC_GPUCRG_FCG_ANA_CFG1_FCM_ADDR(base) ((base) + 0xF04UL)
#define SOC_GPUCRG_FCG_ANA_CFG2_FCM_ADDR(base) ((base) + 0xF08UL)
#define SOC_GPUCRG_FCG_ANA_CFG3_FCM_ADDR(base) ((base) + 0xF0CUL)
#define SOC_GPUCRG_FCG_CFG0_FCM_ADDR(base) ((base) + 0xF18UL)
#define SOC_GPUCRG_FCG_CFG1_FCM_ADDR(base) ((base) + 0xF1CUL)
#define SOC_GPUCRG_FCG_CFG2_FCM_ADDR(base) ((base) + 0xF20UL)
#define SOC_GPUCRG_FCG_CFG3_FCM_ADDR(base) ((base) + 0xF24UL)
#define SOC_GPUCRG_FCG_CFG4_FCM_ADDR(base) ((base) + 0xF28UL)
#define SOC_GPUCRG_FCG_CFG5_FCM_ADDR(base) ((base) + 0xF2CUL)
#define SOC_GPUCRG_FCG_CFG6_FCM_ADDR(base) ((base) + 0xF30UL)
#define SOC_GPUCRG_FCG_CFG7_FCM_ADDR(base) ((base) + 0xF34UL)
#define SOC_GPUCRG_FCG_CFG8_FCM_ADDR(base) ((base) + 0xF38UL)
#define SOC_GPUCRG_FCG_CFG9_FCM_ADDR(base) ((base) + 0xF3CUL)
#define SOC_GPUCRG_FCG_CFG10_FCM_ADDR(base) ((base) + 0xF40UL)
#define SOC_GPUCRG_FCG_CFG11_FCM_ADDR(base) ((base) + 0xF44UL)
#define SOC_GPUCRG_FCG_CFG12_FCM_ADDR(base) ((base) + 0xF48UL)
#define SOC_GPUCRG_FCG_CFG13_FCM_ADDR(base) ((base) + 0xF4CUL)
#define SOC_GPUCRG_FCG_CFG14_FCM_ADDR(base) ((base) + 0xF50UL)
#define SOC_GPUCRG_FCG_CFG15_FCM_ADDR(base) ((base) + 0xF54UL)
#define SOC_GPUCRG_FCG_CFG16_FCM_ADDR(base) ((base) + 0xF58UL)
#define SOC_GPUCRG_FCG_CFG17_FCM_ADDR(base) ((base) + 0xF5CUL)
#define SOC_GPUCRG_FCG_CFG18_FCM_ADDR(base) ((base) + 0xF60UL)
#define SOC_GPUCRG_FCG_CFG19_FCM_ADDR(base) ((base) + 0xF64UL)
#define SOC_GPUCRG_FCG_CFG20_FCM_ADDR(base) ((base) + 0xF68UL)
#define SOC_GPUCRG_FCG_CFG21_FCM_ADDR(base) ((base) + 0xF6CUL)
#define SOC_GPUCRG_FCG_CFG22_FCM_ADDR(base) ((base) + 0xF70UL)
#define SOC_GPUCRG_FCG_CFG23_FCM_ADDR(base) ((base) + 0xF74UL)
#define SOC_GPUCRG_FCG_CFG24_FCM_ADDR(base) ((base) + 0xF78UL)
#define SOC_GPUCRG_FCG_CFG25_FCM_ADDR(base) ((base) + 0xF7CUL)
#define SOC_GPUCRG_FCG_CFG26_FCM_ADDR(base) ((base) + 0xF80UL)
#define SOC_GPUCRG_FCG_CFG27_FCM_ADDR(base) ((base) + 0xF84UL)
#define SOC_GPUCRG_FCG_STAT0_FCM_ADDR(base) ((base) + 0xF90UL)
#define SOC_GPUCRG_FCG_STAT1_FCM_ADDR(base) ((base) + 0xF94UL)
#define SOC_GPUCRG_FCG_STAT2_FCM_ADDR(base) ((base) + 0xF98UL)
#define SOC_GPUCRG_FCG_STAT3_FCM_ADDR(base) ((base) + 0xF9CUL)
#define SOC_GPUCRG_FCG_STAT4_FCM_ADDR(base) ((base) + 0xFA0UL)
#define SOC_GPUCRG_FCG_STAT5_FCM_ADDR(base) ((base) + 0xFA4UL)
#else
#define SOC_GPUCRG_PEREN0_ADDR(base) (base)
#define SOC_GPUCRG_PERDIS0_ADDR(base) ((base) + 0x004)
#define SOC_GPUCRG_PERCLKEN0_ADDR(base) ((base) + 0x008)
#define SOC_GPUCRG_PERSTAT0_ADDR(base) ((base) + 0x00C)
#define SOC_GPUCRG_PERRSTEN0_ADDR(base) ((base) + 0x010)
#define SOC_GPUCRG_PERRSTDIS0_ADDR(base) ((base) + 0x014)
#define SOC_GPUCRG_PERRSTSTAT0_ADDR(base) ((base) + 0x018)
#define SOC_GPUCRG_FCG_STAT_ADDR(base) ((base) + 0x020)
#define SOC_GPUCRG_GPU_CRG_STAT_ADDR(base) ((base) + 0x024)
#define SOC_GPUCRG_FCG_STAT_FCM_ADDR(base) ((base) + 0x028)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_ADDR(base) ((base) + 0x030)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_ADDR(base) ((base) + 0x034)
#define SOC_GPUCRG_FCG_CFG_RSV0_ADDR(base) ((base) + 0x040)
#define SOC_GPUCRG_FCG_CFG_RSV1_ADDR(base) ((base) + 0x044)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_ADDR(base) ((base) + 0x050)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_ADDR(base) ((base) + 0x054)
#define SOC_GPUCRG_GPU_CLKDIV0_ADDR(base) ((base) + 0x058)
#define SOC_GPUCRG_PIM_CTRL0_ADDR(base) ((base) + 0x400)
#define SOC_GPUCRG_PIM_CFG0_GPU_ADDR(base) ((base) + 0x404)
#define SOC_GPUCRG_PIM_CFG1_GPU_ADDR(base) ((base) + 0x408)
#define SOC_GPUCRG_PIM_STAT0_ADDR(base) ((base) + 0x40C)
#define SOC_GPUCRG_PIM_CFG2_GPU_ADDR(base) ((base) + 0x410)
#define SOC_GPUCRG_PIM_CFG3_GPU_ADDR(base) ((base) + 0x414)
#define SOC_GPUCRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x800)
#define SOC_GPUCRG_FCG_ANA_CFG0_GPU_ADDR(base) ((base) + 0xE00)
#define SOC_GPUCRG_FCG_ANA_CFG1_GPU_ADDR(base) ((base) + 0xE04)
#define SOC_GPUCRG_FCG_ANA_CFG2_GPU_ADDR(base) ((base) + 0xE08)
#define SOC_GPUCRG_FCG_ANA_CFG3_GPU_ADDR(base) ((base) + 0xE0C)
#define SOC_GPUCRG_FCG_CFG0_GPU_ADDR(base) ((base) + 0xE18)
#define SOC_GPUCRG_FCG_CFG1_GPU_ADDR(base) ((base) + 0xE1C)
#define SOC_GPUCRG_FCG_CFG2_GPU_ADDR(base) ((base) + 0xE20)
#define SOC_GPUCRG_FCG_CFG3_GPU_ADDR(base) ((base) + 0xE24)
#define SOC_GPUCRG_FCG_CFG4_GPU_ADDR(base) ((base) + 0xE28)
#define SOC_GPUCRG_FCG_CFG5_GPU_ADDR(base) ((base) + 0xE2C)
#define SOC_GPUCRG_FCG_CFG6_GPU_ADDR(base) ((base) + 0xE30)
#define SOC_GPUCRG_FCG_CFG7_GPU_ADDR(base) ((base) + 0xE34)
#define SOC_GPUCRG_FCG_CFG8_GPU_ADDR(base) ((base) + 0xE38)
#define SOC_GPUCRG_FCG_CFG9_GPU_ADDR(base) ((base) + 0xE3C)
#define SOC_GPUCRG_FCG_CFG10_GPU_ADDR(base) ((base) + 0xE40)
#define SOC_GPUCRG_FCG_CFG11_GPU_ADDR(base) ((base) + 0xE44)
#define SOC_GPUCRG_FCG_CFG12_GPU_ADDR(base) ((base) + 0xE48)
#define SOC_GPUCRG_FCG_CFG13_GPU_ADDR(base) ((base) + 0xE4C)
#define SOC_GPUCRG_FCG_CFG14_GPU_ADDR(base) ((base) + 0xE50)
#define SOC_GPUCRG_FCG_CFG15_GPU_ADDR(base) ((base) + 0xE54)
#define SOC_GPUCRG_FCG_CFG16_GPU_ADDR(base) ((base) + 0xE58)
#define SOC_GPUCRG_FCG_CFG17_GPU_ADDR(base) ((base) + 0xE5C)
#define SOC_GPUCRG_FCG_CFG18_GPU_ADDR(base) ((base) + 0xE60)
#define SOC_GPUCRG_FCG_CFG19_GPU_ADDR(base) ((base) + 0xE64)
#define SOC_GPUCRG_FCG_CFG20_GPU_ADDR(base) ((base) + 0xE68)
#define SOC_GPUCRG_FCG_CFG21_GPU_ADDR(base) ((base) + 0xE6C)
#define SOC_GPUCRG_FCG_CFG22_GPU_ADDR(base) ((base) + 0xE70)
#define SOC_GPUCRG_FCG_CFG23_GPU_ADDR(base) ((base) + 0xE74)
#define SOC_GPUCRG_FCG_CFG24_GPU_ADDR(base) ((base) + 0xE78)
#define SOC_GPUCRG_FCG_CFG25_GPU_ADDR(base) ((base) + 0xE7C)
#define SOC_GPUCRG_FCG_CFG26_GPU_ADDR(base) ((base) + 0xE80)
#define SOC_GPUCRG_FCG_CFG27_GPU_ADDR(base) ((base) + 0xE84)
#define SOC_GPUCRG_FCG_STAT0_GPU_ADDR(base) ((base) + 0xE90)
#define SOC_GPUCRG_FCG_STAT1_GPU_ADDR(base) ((base) + 0xE94)
#define SOC_GPUCRG_FCG_STAT2_GPU_ADDR(base) ((base) + 0xE98)
#define SOC_GPUCRG_FCG_STAT3_GPU_ADDR(base) ((base) + 0xE9C)
#define SOC_GPUCRG_FCG_STAT4_GPU_ADDR(base) ((base) + 0xEA0)
#define SOC_GPUCRG_FCG_STAT5_GPU_ADDR(base) ((base) + 0xEA4)
#define SOC_GPUCRG_ONSYS_AVS_CNT_US_GPU_ADDR(base) ((base) + 0x53c)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_ADDR(base) ((base) + 0x540)
#define SOC_GPUCRG_ONSYS_AVS_ENABLE_GPU_ADDR(base) ((base) + 0x544)
#define SOC_GPUCRG_ONSYS_AVS_TIME_CFG_GPU_ADDR(base) ((base) + 0x548)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_0_GPU_ADDR(base) ((base) + 0x54c)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_1_GPU_ADDR(base) ((base) + 0x550)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_2_GPU_ADDR(base) ((base) + 0x554)
#define SOC_GPUCRG_ONSYS_VOL_SUB_ADD_GPU_ADDR(base) ((base) + 0x558)
#define SOC_GPUCRG_ONSYS_AVS_CFG_GPU_ADDR(base) ((base) + 0x55c)
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_ADDR(base) ((base) + 0x560)
#define SOC_GPUCRG_FDCS_ONSYS_STAT_GPU_ADDR(base) ((base) + 0x564)
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_ADDR(base) ((base) + 0x600)
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_ADDR(base) ((base) + 0x604)
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_ADDR(base) ((base) + 0x608)
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_ADDR(base) ((base) + 0x60c)
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_ADDR(base) ((base) + 0x610)
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_ADDR(base) ((base) + 0x614)
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_ADDR(base) ((base) + 0x618)
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_ADDR(base) ((base) + 0x61c)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_ADDR(base) ((base) + 0x620)
#define SOC_GPUCRG_FDCS_ONSYS_CFG9_GPU_ADDR(base) ((base) + 0x624)
#define SOC_GPUCRG_FDCS_ONSYS_CFG10_GPU_ADDR(base) ((base) + 0x628)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_ADDR(base) ((base) + 0x62c)
#define SOC_GPUCRG_FDCS_ONSYS_CFG12_GPU_ADDR(base) ((base) + 0x630)
#define SOC_GPUCRG_FDCS_ONSYS_CFG13_GPU_ADDR(base) ((base) + 0x634)
#define SOC_GPUCRG_MON_CFG0_GPU_ADDR(base) ((base) + 0x650)
#define SOC_GPUCRG_MON_CFG1_GPU_ADDR(base) ((base) + 0x654)
#define SOC_GPUCRG_MON_CFG2_GPU_ADDR(base) ((base) + 0x658)
#define SOC_GPUCRG_MON_CFG3_GPU_ADDR(base) ((base) + 0x65C)
#define SOC_GPUCRG_MON_CFG4_GPU_ADDR(base) ((base) + 0x660)
#define SOC_GPUCRG_MON_CFG5_GPU_ADDR(base) ((base) + 0x664)
#define SOC_GPUCRG_MON_CFG6_GPU_ADDR(base) ((base) + 0x668)
#define SOC_GPUCRG_MON_CFG7_GPU_ADDR(base) ((base) + 0x66C)
#define SOC_GPUCRG_MON_CFG8_GPU_ADDR(base) ((base) + 0x670)
#define SOC_GPUCRG_MON_CFG9_GPU_ADDR(base) ((base) + 0x674)
#define SOC_GPUCRG_MON_CFG10_GPU_ADDR(base) ((base) + 0x678)
#define SOC_GPUCRG_MON_CFG11_GPU_ADDR(base) ((base) + 0x67C)
#define SOC_GPUCRG_MON_CFG12_GPU_ADDR(base) ((base) + 0x680)
#define SOC_GPUCRG_MON_CFG13_GPU_ADDR(base) ((base) + 0x684)
#define SOC_GPUCRG_MON_CFG14_GPU_ADDR(base) ((base) + 0x688)
#define SOC_GPUCRG_MON_CFG15_GPU_ADDR(base) ((base) + 0x68C)
#define SOC_GPUCRG_MON_CFG16_GPU_ADDR(base) ((base) + 0x690)
#define SOC_GPUCRG_MON_STAT0_GPU_ADDR(base) ((base) + 0x694)
#define SOC_GPUCRG_MON_STAT1_GPU_ADDR(base) ((base) + 0x698)
#define SOC_GPUCRG_MON_STAT2_GPU_ADDR(base) ((base) + 0x69C)
#define SOC_GPUCRG_MON_STAT3_GPU_ADDR(base) ((base) + 0x6A0)
#define SOC_GPUCRG_MON_STAT4_GPU_ADDR(base) ((base) + 0x6A4)
#define SOC_GPUCRG_MON_STAT5_GPU_ADDR(base) ((base) + 0x6A8)
#define SOC_GPUCRG_MON_STAT6_GPU_ADDR(base) ((base) + 0x6AC)
#define SOC_GPUCRG_MON_STAT7_GPU_ADDR(base) ((base) + 0x6B0)
#define SOC_GPUCRG_MON_STAT8_GPU_ADDR(base) ((base) + 0x6B4)
#define SOC_GPUCRG_MON_STAT9_GPU_ADDR(base) ((base) + 0x6B8)
#define SOC_GPUCRG_MON_STAT10_GPU_ADDR(base) ((base) + 0x6BC)
#define SOC_GPUCRG_MON_STAT11_GPU_ADDR(base) ((base) + 0x6C0)
#define SOC_GPUCRG_MON_STAT12_GPU_ADDR(base) ((base) + 0x6C4)
#define SOC_GPUCRG_MON_STAT13_GPU_ADDR(base) ((base) + 0x6C8)
#define SOC_GPUCRG_MON_STAT14_GPU_ADDR(base) ((base) + 0x6CC)
#define SOC_GPUCRG_MON_STAT15_GPU_ADDR(base) ((base) + 0x6D0)
#define SOC_GPUCRG_MON_STAT16_GPU_ADDR(base) ((base) + 0x6D4)
#define SOC_GPUCRG_MON_STAT17_GPU_ADDR(base) ((base) + 0x6D8)
#define SOC_GPUCRG_MON_STAT18_GPU_ADDR(base) ((base) + 0x6DC)
#define SOC_GPUCRG_MON_STAT19_GPU_ADDR(base) ((base) + 0x6E0)
#define SOC_GPUCRG_MON_STAT20_GPU_ADDR(base) ((base) + 0x6E4)
#define SOC_GPUCRG_MON_STAT21_GPU_ADDR(base) ((base) + 0x6E8)
#define SOC_GPUCRG_MON_STAT22_GPU_ADDR(base) ((base) + 0x6EC)
#define SOC_GPUCRG_MON_STAT23_GPU_ADDR(base) ((base) + 0x6F0)
#define SOC_GPUCRG_MON_STAT24_GPU_ADDR(base) ((base) + 0x6F4)
#define SOC_GPUCRG_MON_STAT25_GPU_ADDR(base) ((base) + 0x6F8)
#define SOC_GPUCRG_FDCS_XPU_CFG_ADDR(base) ((base) + 0x700)
#define SOC_GPUCRG_FCG_ANA_CFG0_FCM_ADDR(base) ((base) + 0xF00)
#define SOC_GPUCRG_FCG_ANA_CFG1_FCM_ADDR(base) ((base) + 0xF04)
#define SOC_GPUCRG_FCG_ANA_CFG2_FCM_ADDR(base) ((base) + 0xF08)
#define SOC_GPUCRG_FCG_ANA_CFG3_FCM_ADDR(base) ((base) + 0xF0C)
#define SOC_GPUCRG_FCG_CFG0_FCM_ADDR(base) ((base) + 0xF18)
#define SOC_GPUCRG_FCG_CFG1_FCM_ADDR(base) ((base) + 0xF1C)
#define SOC_GPUCRG_FCG_CFG2_FCM_ADDR(base) ((base) + 0xF20)
#define SOC_GPUCRG_FCG_CFG3_FCM_ADDR(base) ((base) + 0xF24)
#define SOC_GPUCRG_FCG_CFG4_FCM_ADDR(base) ((base) + 0xF28)
#define SOC_GPUCRG_FCG_CFG5_FCM_ADDR(base) ((base) + 0xF2C)
#define SOC_GPUCRG_FCG_CFG6_FCM_ADDR(base) ((base) + 0xF30)
#define SOC_GPUCRG_FCG_CFG7_FCM_ADDR(base) ((base) + 0xF34)
#define SOC_GPUCRG_FCG_CFG8_FCM_ADDR(base) ((base) + 0xF38)
#define SOC_GPUCRG_FCG_CFG9_FCM_ADDR(base) ((base) + 0xF3C)
#define SOC_GPUCRG_FCG_CFG10_FCM_ADDR(base) ((base) + 0xF40)
#define SOC_GPUCRG_FCG_CFG11_FCM_ADDR(base) ((base) + 0xF44)
#define SOC_GPUCRG_FCG_CFG12_FCM_ADDR(base) ((base) + 0xF48)
#define SOC_GPUCRG_FCG_CFG13_FCM_ADDR(base) ((base) + 0xF4C)
#define SOC_GPUCRG_FCG_CFG14_FCM_ADDR(base) ((base) + 0xF50)
#define SOC_GPUCRG_FCG_CFG15_FCM_ADDR(base) ((base) + 0xF54)
#define SOC_GPUCRG_FCG_CFG16_FCM_ADDR(base) ((base) + 0xF58)
#define SOC_GPUCRG_FCG_CFG17_FCM_ADDR(base) ((base) + 0xF5C)
#define SOC_GPUCRG_FCG_CFG18_FCM_ADDR(base) ((base) + 0xF60)
#define SOC_GPUCRG_FCG_CFG19_FCM_ADDR(base) ((base) + 0xF64)
#define SOC_GPUCRG_FCG_CFG20_FCM_ADDR(base) ((base) + 0xF68)
#define SOC_GPUCRG_FCG_CFG21_FCM_ADDR(base) ((base) + 0xF6C)
#define SOC_GPUCRG_FCG_CFG22_FCM_ADDR(base) ((base) + 0xF70)
#define SOC_GPUCRG_FCG_CFG23_FCM_ADDR(base) ((base) + 0xF74)
#define SOC_GPUCRG_FCG_CFG24_FCM_ADDR(base) ((base) + 0xF78)
#define SOC_GPUCRG_FCG_CFG25_FCM_ADDR(base) ((base) + 0xF7C)
#define SOC_GPUCRG_FCG_CFG26_FCM_ADDR(base) ((base) + 0xF80)
#define SOC_GPUCRG_FCG_CFG27_FCM_ADDR(base) ((base) + 0xF84)
#define SOC_GPUCRG_FCG_STAT0_FCM_ADDR(base) ((base) + 0xF90)
#define SOC_GPUCRG_FCG_STAT1_FCM_ADDR(base) ((base) + 0xF94)
#define SOC_GPUCRG_FCG_STAT2_FCM_ADDR(base) ((base) + 0xF98)
#define SOC_GPUCRG_FCG_STAT3_FCM_ADDR(base) ((base) + 0xF9C)
#define SOC_GPUCRG_FCG_STAT4_FCM_ADDR(base) ((base) + 0xFA0)
#define SOC_GPUCRG_FCG_STAT5_FCM_ADDR(base) ((base) + 0xFA4)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_fcg_gpu : 1;
        unsigned int gt_clk_fcg_sscg_gpu : 1;
        unsigned int gt_clk_fcg_freq_ctrl_gpu : 1;
        unsigned int gt_clk_fdcs_mon_gpu : 1;
        unsigned int gt_pclk_onsys_avs_gpu : 1;
        unsigned int gt_pclk_fdcs_xpu_stat_gpu : 1;
        unsigned int gt_clk_fcg_sscg_fcm : 1;
        unsigned int gt_pclk_fcg_fcm : 1;
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
        unsigned int reserved_17 : 7;
    } reg;
} SOC_GPUCRG_PEREN0_UNION;
#endif
#define SOC_GPUCRG_PEREN0_gt_pclk_fcg_gpu_START (0)
#define SOC_GPUCRG_PEREN0_gt_pclk_fcg_gpu_END (0)
#define SOC_GPUCRG_PEREN0_gt_clk_fcg_sscg_gpu_START (1)
#define SOC_GPUCRG_PEREN0_gt_clk_fcg_sscg_gpu_END (1)
#define SOC_GPUCRG_PEREN0_gt_clk_fcg_freq_ctrl_gpu_START (2)
#define SOC_GPUCRG_PEREN0_gt_clk_fcg_freq_ctrl_gpu_END (2)
#define SOC_GPUCRG_PEREN0_gt_clk_fdcs_mon_gpu_START (3)
#define SOC_GPUCRG_PEREN0_gt_clk_fdcs_mon_gpu_END (3)
#define SOC_GPUCRG_PEREN0_gt_pclk_onsys_avs_gpu_START (4)
#define SOC_GPUCRG_PEREN0_gt_pclk_onsys_avs_gpu_END (4)
#define SOC_GPUCRG_PEREN0_gt_pclk_fdcs_xpu_stat_gpu_START (5)
#define SOC_GPUCRG_PEREN0_gt_pclk_fdcs_xpu_stat_gpu_END (5)
#define SOC_GPUCRG_PEREN0_gt_clk_fcg_sscg_fcm_START (6)
#define SOC_GPUCRG_PEREN0_gt_clk_fcg_sscg_fcm_END (6)
#define SOC_GPUCRG_PEREN0_gt_pclk_fcg_fcm_START (7)
#define SOC_GPUCRG_PEREN0_gt_pclk_fcg_fcm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_fcg_gpu : 1;
        unsigned int gt_clk_fcg_sscg_gpu : 1;
        unsigned int gt_clk_fcg_freq_ctrl_gpu : 1;
        unsigned int gt_clk_fdcs_mon_gpu : 1;
        unsigned int gt_pclk_onsys_avs_gpu : 1;
        unsigned int gt_pclk_fdcs_xpu_stat_gpu : 1;
        unsigned int gt_clk_fcg_sscg_fcm : 1;
        unsigned int gt_pclk_fcg_fcm : 1;
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
        unsigned int reserved_17 : 7;
    } reg;
} SOC_GPUCRG_PERDIS0_UNION;
#endif
#define SOC_GPUCRG_PERDIS0_gt_pclk_fcg_gpu_START (0)
#define SOC_GPUCRG_PERDIS0_gt_pclk_fcg_gpu_END (0)
#define SOC_GPUCRG_PERDIS0_gt_clk_fcg_sscg_gpu_START (1)
#define SOC_GPUCRG_PERDIS0_gt_clk_fcg_sscg_gpu_END (1)
#define SOC_GPUCRG_PERDIS0_gt_clk_fcg_freq_ctrl_gpu_START (2)
#define SOC_GPUCRG_PERDIS0_gt_clk_fcg_freq_ctrl_gpu_END (2)
#define SOC_GPUCRG_PERDIS0_gt_clk_fdcs_mon_gpu_START (3)
#define SOC_GPUCRG_PERDIS0_gt_clk_fdcs_mon_gpu_END (3)
#define SOC_GPUCRG_PERDIS0_gt_pclk_onsys_avs_gpu_START (4)
#define SOC_GPUCRG_PERDIS0_gt_pclk_onsys_avs_gpu_END (4)
#define SOC_GPUCRG_PERDIS0_gt_pclk_fdcs_xpu_stat_gpu_START (5)
#define SOC_GPUCRG_PERDIS0_gt_pclk_fdcs_xpu_stat_gpu_END (5)
#define SOC_GPUCRG_PERDIS0_gt_clk_fcg_sscg_fcm_START (6)
#define SOC_GPUCRG_PERDIS0_gt_clk_fcg_sscg_fcm_END (6)
#define SOC_GPUCRG_PERDIS0_gt_pclk_fcg_fcm_START (7)
#define SOC_GPUCRG_PERDIS0_gt_pclk_fcg_fcm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_fcg_gpu : 1;
        unsigned int gt_clk_fcg_sscg_gpu : 1;
        unsigned int gt_clk_fcg_freq_ctrl_gpu : 1;
        unsigned int gt_clk_fdcs_mon_gpu : 1;
        unsigned int gt_pclk_onsys_avs_gpu : 1;
        unsigned int gt_pclk_fdcs_xpu_stat_gpu : 1;
        unsigned int gt_clk_fcg_sscg_fcm : 1;
        unsigned int gt_pclk_fcg_fcm : 1;
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
        unsigned int reserved_17 : 7;
    } reg;
} SOC_GPUCRG_PERCLKEN0_UNION;
#endif
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_fcg_gpu_START (0)
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_fcg_gpu_END (0)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fcg_sscg_gpu_START (1)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fcg_sscg_gpu_END (1)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fcg_freq_ctrl_gpu_START (2)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fcg_freq_ctrl_gpu_END (2)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fdcs_mon_gpu_START (3)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fdcs_mon_gpu_END (3)
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_onsys_avs_gpu_START (4)
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_onsys_avs_gpu_END (4)
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_fdcs_xpu_stat_gpu_START (5)
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_fdcs_xpu_stat_gpu_END (5)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fcg_sscg_fcm_START (6)
#define SOC_GPUCRG_PERCLKEN0_gt_clk_fcg_sscg_fcm_END (6)
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_fcg_fcm_START (7)
#define SOC_GPUCRG_PERCLKEN0_gt_pclk_fcg_fcm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_pclk_fcg_gpu : 1;
        unsigned int st_clk_fcg_sscg_gpu : 1;
        unsigned int st_clk_fcg_freq_ctrl_gpu : 1;
        unsigned int st_clk_fcg_fdcs_mon_gpu : 1;
        unsigned int st_pclk_onsys_avs : 1;
        unsigned int st_pclk_fdcs_xpu_stat_gpu : 1;
        unsigned int st_clk_fcg_sscg_fcm : 1;
        unsigned int st_pclk_fcg_fcm : 1;
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
        unsigned int st_clk_fcg_pre_fcm : 1;
        unsigned int st_clk_fcg_pre_g3d : 1;
        unsigned int st_clk_fcg_freq_ctrl_fcm : 1;
        unsigned int reserved_14 : 7;
    } reg;
} SOC_GPUCRG_PERSTAT0_UNION;
#endif
#define SOC_GPUCRG_PERSTAT0_st_pclk_fcg_gpu_START (0)
#define SOC_GPUCRG_PERSTAT0_st_pclk_fcg_gpu_END (0)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_sscg_gpu_START (1)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_sscg_gpu_END (1)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_freq_ctrl_gpu_START (2)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_freq_ctrl_gpu_END (2)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_fdcs_mon_gpu_START (3)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_fdcs_mon_gpu_END (3)
#define SOC_GPUCRG_PERSTAT0_st_pclk_onsys_avs_START (4)
#define SOC_GPUCRG_PERSTAT0_st_pclk_onsys_avs_END (4)
#define SOC_GPUCRG_PERSTAT0_st_pclk_fdcs_xpu_stat_gpu_START (5)
#define SOC_GPUCRG_PERSTAT0_st_pclk_fdcs_xpu_stat_gpu_END (5)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_sscg_fcm_START (6)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_sscg_fcm_END (6)
#define SOC_GPUCRG_PERSTAT0_st_pclk_fcg_fcm_START (7)
#define SOC_GPUCRG_PERSTAT0_st_pclk_fcg_fcm_END (7)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_pre_fcm_START (22)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_pre_fcm_END (22)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_pre_g3d_START (23)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_pre_g3d_END (23)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_freq_ctrl_fcm_START (24)
#define SOC_GPUCRG_PERSTAT0_st_clk_fcg_freq_ctrl_fcm_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_fcg_gpu : 1;
        unsigned int ip_rst_fcg_freq_ctrl_gpu : 1;
        unsigned int ip_rst_fdcs_mon_gpu : 1;
        unsigned int ip_prst_onsys_avs : 1;
        unsigned int ip_rst_g3d_gen : 1;
        unsigned int ip_rst_fdcs_xpu_stat : 1;
        unsigned int ip_prst_fcg_fcm : 1;
        unsigned int ip_rst_fcm_gen : 1;
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
    } reg;
} SOC_GPUCRG_PERRSTEN0_UNION;
#endif
#define SOC_GPUCRG_PERRSTEN0_ip_prst_fcg_gpu_START (0)
#define SOC_GPUCRG_PERRSTEN0_ip_prst_fcg_gpu_END (0)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_gpu_START (1)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_gpu_END (1)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fdcs_mon_gpu_START (2)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fdcs_mon_gpu_END (2)
#define SOC_GPUCRG_PERRSTEN0_ip_prst_onsys_avs_START (3)
#define SOC_GPUCRG_PERRSTEN0_ip_prst_onsys_avs_END (3)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_g3d_gen_START (4)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_g3d_gen_END (4)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fdcs_xpu_stat_START (5)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fdcs_xpu_stat_END (5)
#define SOC_GPUCRG_PERRSTEN0_ip_prst_fcg_fcm_START (6)
#define SOC_GPUCRG_PERRSTEN0_ip_prst_fcg_fcm_END (6)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fcm_gen_START (7)
#define SOC_GPUCRG_PERRSTEN0_ip_rst_fcm_gen_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_fcg_gpu : 1;
        unsigned int ip_rst_fcg_freq_ctrl_gpu : 1;
        unsigned int ip_rst_fdcs_mon_gpu : 1;
        unsigned int ip_prst_onsys_avs : 1;
        unsigned int ip_rst_g3d_gen : 1;
        unsigned int ip_rst_fdcs_xpu_stat : 1;
        unsigned int ip_prst_fcg_fcm : 1;
        unsigned int ip_rst_fcm_gen : 1;
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
    } reg;
} SOC_GPUCRG_PERRSTDIS0_UNION;
#endif
#define SOC_GPUCRG_PERRSTDIS0_ip_prst_fcg_gpu_START (0)
#define SOC_GPUCRG_PERRSTDIS0_ip_prst_fcg_gpu_END (0)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_gpu_START (1)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_gpu_END (1)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fdcs_mon_gpu_START (2)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fdcs_mon_gpu_END (2)
#define SOC_GPUCRG_PERRSTDIS0_ip_prst_onsys_avs_START (3)
#define SOC_GPUCRG_PERRSTDIS0_ip_prst_onsys_avs_END (3)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_g3d_gen_START (4)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_g3d_gen_END (4)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fdcs_xpu_stat_START (5)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fdcs_xpu_stat_END (5)
#define SOC_GPUCRG_PERRSTDIS0_ip_prst_fcg_fcm_START (6)
#define SOC_GPUCRG_PERRSTDIS0_ip_prst_fcg_fcm_END (6)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fcm_gen_START (7)
#define SOC_GPUCRG_PERRSTDIS0_ip_rst_fcm_gen_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_fcg_gpu : 1;
        unsigned int ip_rst_fcg_freq_ctrl_gpu : 1;
        unsigned int ip_rst_fdcs_mon_gpu : 1;
        unsigned int ip_prst_onsys_avs : 1;
        unsigned int ip_rst_g3d_gen : 1;
        unsigned int ip_rst_fdcs_xpu_stat : 1;
        unsigned int ip_prst_fcg_fcm : 1;
        unsigned int ip_rst_fcm_gen : 1;
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
    } reg;
} SOC_GPUCRG_PERRSTSTAT0_UNION;
#endif
#define SOC_GPUCRG_PERRSTSTAT0_ip_prst_fcg_gpu_START (0)
#define SOC_GPUCRG_PERRSTSTAT0_ip_prst_fcg_gpu_END (0)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_gpu_START (1)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_gpu_END (1)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fdcs_mon_gpu_START (2)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fdcs_mon_gpu_END (2)
#define SOC_GPUCRG_PERRSTSTAT0_ip_prst_onsys_avs_START (3)
#define SOC_GPUCRG_PERRSTSTAT0_ip_prst_onsys_avs_END (3)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_g3d_gen_START (4)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_g3d_gen_END (4)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fdcs_xpu_stat_START (5)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fdcs_xpu_stat_END (5)
#define SOC_GPUCRG_PERRSTSTAT0_ip_prst_fcg_fcm_START (6)
#define SOC_GPUCRG_PERRSTSTAT0_ip_prst_fcg_fcm_END (6)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fcm_gen_START (7)
#define SOC_GPUCRG_PERRSTSTAT0_ip_rst_fcm_gen_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat_gpu : 16;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_GPUCRG_FCG_STAT_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT_fcg_stat_gpu_START (0)
#define SOC_GPUCRG_FCG_STAT_fcg_stat_gpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_sscg_idle_gpu : 1;
        unsigned int sw_ack_clk_gpu_sw : 2;
        unsigned int freq_dn_flag_gpu : 1;
        unsigned int cpu_l2_idle_aft_gpu : 1;
        unsigned int div_g3d_vdm_aft : 4;
        unsigned int fcg_sscg_idle_fcm : 1;
        unsigned int sw_ack_clk_fcm_sw : 2;
        unsigned int freq_dn_flag_fcm : 1;
        unsigned int cpu_l2_idle_aft_fcm : 1;
        unsigned int div_fcm : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_GPUCRG_GPU_CRG_STAT_UNION;
#endif
#define SOC_GPUCRG_GPU_CRG_STAT_fcg_sscg_idle_gpu_START (0)
#define SOC_GPUCRG_GPU_CRG_STAT_fcg_sscg_idle_gpu_END (0)
#define SOC_GPUCRG_GPU_CRG_STAT_sw_ack_clk_gpu_sw_START (1)
#define SOC_GPUCRG_GPU_CRG_STAT_sw_ack_clk_gpu_sw_END (2)
#define SOC_GPUCRG_GPU_CRG_STAT_freq_dn_flag_gpu_START (3)
#define SOC_GPUCRG_GPU_CRG_STAT_freq_dn_flag_gpu_END (3)
#define SOC_GPUCRG_GPU_CRG_STAT_cpu_l2_idle_aft_gpu_START (4)
#define SOC_GPUCRG_GPU_CRG_STAT_cpu_l2_idle_aft_gpu_END (4)
#define SOC_GPUCRG_GPU_CRG_STAT_div_g3d_vdm_aft_START (5)
#define SOC_GPUCRG_GPU_CRG_STAT_div_g3d_vdm_aft_END (8)
#define SOC_GPUCRG_GPU_CRG_STAT_fcg_sscg_idle_fcm_START (9)
#define SOC_GPUCRG_GPU_CRG_STAT_fcg_sscg_idle_fcm_END (9)
#define SOC_GPUCRG_GPU_CRG_STAT_sw_ack_clk_fcm_sw_START (10)
#define SOC_GPUCRG_GPU_CRG_STAT_sw_ack_clk_fcm_sw_END (11)
#define SOC_GPUCRG_GPU_CRG_STAT_freq_dn_flag_fcm_START (12)
#define SOC_GPUCRG_GPU_CRG_STAT_freq_dn_flag_fcm_END (12)
#define SOC_GPUCRG_GPU_CRG_STAT_cpu_l2_idle_aft_fcm_START (13)
#define SOC_GPUCRG_GPU_CRG_STAT_cpu_l2_idle_aft_fcm_END (13)
#define SOC_GPUCRG_GPU_CRG_STAT_div_fcm_START (14)
#define SOC_GPUCRG_GPU_CRG_STAT_div_fcm_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat_fcm : 16;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_GPUCRG_FCG_STAT_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT_FCM_fcg_stat_fcm_START (0)
#define SOC_GPUCRG_FCG_STAT_FCM_fcg_stat_fcm_END (15)
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
} SOC_GPUCRG_SSC_FCG_CFG_GPU_UNION;
#endif
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_enable_START (0)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_enable_END (0)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_mode_START (1)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_mode_END (1)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_rate_START (2)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_rate_END (5)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_depth_START (6)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_depth_END (8)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_fast_dis_START (9)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_sscg_fast_dis_END (9)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_bitmasken_START (16)
#define SOC_GPUCRG_SSC_FCG_CFG_GPU_bitmasken_END (31)
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
} SOC_GPUCRG_SSC_FCG_CFG_FCM_UNION;
#endif
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_enable_START (0)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_enable_END (0)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_mode_START (1)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_mode_END (1)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_rate_START (2)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_rate_END (5)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_depth_START (6)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_depth_END (8)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_fast_dis_START (9)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_sscg_fast_dis_END (9)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_bitmasken_START (16)
#define SOC_GPUCRG_SSC_FCG_CFG_FCM_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg_rsv_gpu : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_GPUCRG_FCG_CFG_RSV0_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG_RSV0_fcg_cfg_rsv_gpu_START (0)
#define SOC_GPUCRG_FCG_CFG_RSV0_fcg_cfg_rsv_gpu_END (15)
#define SOC_GPUCRG_FCG_CFG_RSV0_bitmasken_START (16)
#define SOC_GPUCRG_FCG_CFG_RSV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg_rsv_fcm : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_GPUCRG_FCG_CFG_RSV1_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG_RSV1_fcg_cfg_rsv_fcm_START (0)
#define SOC_GPUCRG_FCG_CFG_RSV1_fcg_cfg_rsv_fcm_END (15)
#define SOC_GPUCRG_FCG_CFG_RSV1_bitmasken_START (16)
#define SOC_GPUCRG_FCG_CFG_RSV1_bitmasken_END (31)
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
} SOC_GPUCRG_FCG_FREQ_CTRL_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_pcr_trig_vdm_en_START (0)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_pcr_trig_vdm_en_END (0)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_wfx_bypass_START (1)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_wfx_bypass_END (4)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_l2_idle_div_mod_START (5)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_l2_idle_div_mod_END (5)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_freq_dn_mst_sel_START (6)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_freq_dn_mst_sel_END (6)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_wake_up_mode_START (23)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_wake_up_mode_END (24)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_l2_idle_switch_bypass_START (25)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_l2_idle_switch_bypass_END (25)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_l2_idle_gt_en_START (26)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_cpu_l2_idle_gt_en_END (26)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_vbat_drop_icg_en_START (27)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_vbat_drop_icg_en_END (27)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_vbat_drop_fcg_en_START (28)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_vbat_drop_fcg_en_END (28)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_coreidle_bypass_START (29)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_coreidle_bypass_END (29)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_pcr_fs_icg_en_START (30)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_pcr_fs_icg_en_END (30)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_pcr_fs_fcg_en_START (31)
#define SOC_GPUCRG_FCG_FREQ_CTRL_GPU_pcr_fs_fcg_en_END (31)
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
} SOC_GPUCRG_FCG_FREQ_CTRL_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_pcr_trig_vdm_en_START (0)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_pcr_trig_vdm_en_END (0)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_wfx_bypass_START (1)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_wfx_bypass_END (4)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_l2_idle_div_mod_START (5)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_l2_idle_div_mod_END (5)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_freq_dn_mst_sel_START (6)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_freq_dn_mst_sel_END (6)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_wake_up_mode_START (23)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_wake_up_mode_END (24)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_l2_idle_switch_bypass_START (25)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_l2_idle_switch_bypass_END (25)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_l2_idle_gt_en_START (26)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_cpu_l2_idle_gt_en_END (26)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_vbat_drop_icg_en_START (27)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_vbat_drop_icg_en_END (27)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_vbat_drop_fcg_en_START (28)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_vbat_drop_fcg_en_END (28)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_coreidle_bypass_START (29)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_coreidle_bypass_END (29)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_pcr_fs_icg_en_START (30)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_pcr_fs_icg_en_END (30)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_pcr_fs_fcg_en_START (31)
#define SOC_GPUCRG_FCG_FREQ_CTRL_FCM_pcr_fs_fcg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_code_bypass : 1;
        unsigned int sc_fcg_cfg_gt_bypass_g3d : 1;
        unsigned int sc_fcg_cfg_gt_pre_bypass_g3d : 1;
        unsigned int sc_fcg_cfg_gt_bypass_fcm : 1;
        unsigned int sc_fcg_cfg_gt_pre_bypass_fcm : 1;
        unsigned int temp_code_enable : 1;
        unsigned int reserved : 10;
        unsigned int bitmasken : 16;
    } reg;
} SOC_GPUCRG_GPU_CLKDIV0_UNION;
#endif
#define SOC_GPUCRG_GPU_CLKDIV0_temp_code_bypass_START (0)
#define SOC_GPUCRG_GPU_CLKDIV0_temp_code_bypass_END (0)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_bypass_g3d_START (1)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_bypass_g3d_END (1)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_pre_bypass_g3d_START (2)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_pre_bypass_g3d_END (2)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_bypass_fcm_START (3)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_bypass_fcm_END (3)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_pre_bypass_fcm_START (4)
#define SOC_GPUCRG_GPU_CLKDIV0_sc_fcg_cfg_gt_pre_bypass_fcm_END (4)
#define SOC_GPUCRG_GPU_CLKDIV0_temp_code_enable_START (5)
#define SOC_GPUCRG_GPU_CLKDIV0_temp_code_enable_END (5)
#define SOC_GPUCRG_GPU_CLKDIV0_bitmasken_START (16)
#define SOC_GPUCRG_GPU_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_drop_en_gpu : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int pim_ost_en_gpu : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int pim_peaklow_en_gpu : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int pim_debug_gpu : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_GPUCRG_PIM_CTRL0_UNION;
#endif
#define SOC_GPUCRG_PIM_CTRL0_pim_drop_en_gpu_START (0)
#define SOC_GPUCRG_PIM_CTRL0_pim_drop_en_gpu_END (0)
#define SOC_GPUCRG_PIM_CTRL0_pim_ost_en_gpu_START (4)
#define SOC_GPUCRG_PIM_CTRL0_pim_ost_en_gpu_END (4)
#define SOC_GPUCRG_PIM_CTRL0_pim_peaklow_en_gpu_START (8)
#define SOC_GPUCRG_PIM_CTRL0_pim_peaklow_en_gpu_END (8)
#define SOC_GPUCRG_PIM_CTRL0_pim_debug_gpu_START (12)
#define SOC_GPUCRG_PIM_CTRL0_pim_debug_gpu_END (12)
#define SOC_GPUCRG_PIM_CTRL0_bitmasken_START (16)
#define SOC_GPUCRG_PIM_CTRL0_bitmasken_END (31)
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
} SOC_GPUCRG_PIM_CFG0_GPU_UNION;
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
} SOC_GPUCRG_PIM_CFG1_GPU_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_code : 16;
        unsigned int pim_peaklow_ready : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int pim_flag_l_gpu : 1;
        unsigned int pim_flag_h_gpu : 1;
        unsigned int pim_flag_ready_gpu : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
    } reg;
} SOC_GPUCRG_PIM_STAT0_UNION;
#endif
#define SOC_GPUCRG_PIM_STAT0_pim_peaklow_code_START (0)
#define SOC_GPUCRG_PIM_STAT0_pim_peaklow_code_END (15)
#define SOC_GPUCRG_PIM_STAT0_pim_peaklow_ready_START (16)
#define SOC_GPUCRG_PIM_STAT0_pim_peaklow_ready_END (16)
#define SOC_GPUCRG_PIM_STAT0_pim_flag_l_gpu_START (20)
#define SOC_GPUCRG_PIM_STAT0_pim_flag_l_gpu_END (20)
#define SOC_GPUCRG_PIM_STAT0_pim_flag_h_gpu_START (21)
#define SOC_GPUCRG_PIM_STAT0_pim_flag_h_gpu_END (21)
#define SOC_GPUCRG_PIM_STAT0_pim_flag_ready_gpu_START (22)
#define SOC_GPUCRG_PIM_STAT0_pim_flag_ready_gpu_END (22)
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
} SOC_GPUCRG_PIM_CFG2_GPU_UNION;
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
} SOC_GPUCRG_PIM_CFG3_GPU_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_gpu_clkrst_bypass : 1;
        unsigned int fcg_fcm_clkrst_bypass : 1;
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
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
    } reg;
} SOC_GPUCRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_GPUCRG_IPCLKRST_BYPASS0_fcg_gpu_clkrst_bypass_START (0)
#define SOC_GPUCRG_IPCLKRST_BYPASS0_fcg_gpu_clkrst_bypass_END (0)
#define SOC_GPUCRG_IPCLKRST_BYPASS0_fcg_fcm_clkrst_bypass_START (1)
#define SOC_GPUCRG_IPCLKRST_BYPASS0_fcg_fcm_clkrst_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG0_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG0_GPU_d2a_fcg_ana_cfg0_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG0_GPU_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG1_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG1_GPU_d2a_fcg_ana_cfg1_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG1_GPU_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG2_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG2_GPU_d2a_fcg_ana_cfg2_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG2_GPU_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG3_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG3_GPU_d2a_fcg_ana_cfg3_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG3_GPU_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG0_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG0_GPU_fcg_cfg0_START (0)
#define SOC_GPUCRG_FCG_CFG0_GPU_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG1_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG1_GPU_fcg_cfg1_START (0)
#define SOC_GPUCRG_FCG_CFG1_GPU_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG2_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG2_GPU_fcg_cfg2_START (0)
#define SOC_GPUCRG_FCG_CFG2_GPU_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG3_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG3_GPU_fcg_cfg3_START (0)
#define SOC_GPUCRG_FCG_CFG3_GPU_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG4_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG4_GPU_fcg_cfg4_START (0)
#define SOC_GPUCRG_FCG_CFG4_GPU_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG5_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG5_GPU_fcg_cfg5_START (0)
#define SOC_GPUCRG_FCG_CFG5_GPU_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG6_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG6_GPU_fcg_cfg6_START (0)
#define SOC_GPUCRG_FCG_CFG6_GPU_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG7_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG7_GPU_fcg_cfg7_START (0)
#define SOC_GPUCRG_FCG_CFG7_GPU_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG8_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG8_GPU_fcg_cfg8_START (0)
#define SOC_GPUCRG_FCG_CFG8_GPU_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG9_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG9_GPU_fcg_cfg9_START (0)
#define SOC_GPUCRG_FCG_CFG9_GPU_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG10_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG10_GPU_fcg_cfg10_START (0)
#define SOC_GPUCRG_FCG_CFG10_GPU_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG11_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG11_GPU_fcg_cfg11_START (0)
#define SOC_GPUCRG_FCG_CFG11_GPU_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG12_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG12_GPU_fcg_cfg12_START (0)
#define SOC_GPUCRG_FCG_CFG12_GPU_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG13_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG13_GPU_fcg_cfg13_START (0)
#define SOC_GPUCRG_FCG_CFG13_GPU_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG14_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG14_GPU_fcg_cfg14_START (0)
#define SOC_GPUCRG_FCG_CFG14_GPU_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG15_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG15_GPU_fcg_cfg15_START (0)
#define SOC_GPUCRG_FCG_CFG15_GPU_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG16_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG16_GPU_fcg_cfg16_START (0)
#define SOC_GPUCRG_FCG_CFG16_GPU_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG17_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG17_GPU_fcg_cfg17_START (0)
#define SOC_GPUCRG_FCG_CFG17_GPU_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG18_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG18_GPU_fcg_cfg18_START (0)
#define SOC_GPUCRG_FCG_CFG18_GPU_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG19_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG19_GPU_fcg_cfg19_START (0)
#define SOC_GPUCRG_FCG_CFG19_GPU_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG20_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG20_GPU_fcg_cfg20_START (0)
#define SOC_GPUCRG_FCG_CFG20_GPU_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG21_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG21_GPU_fcg_cfg21_START (0)
#define SOC_GPUCRG_FCG_CFG21_GPU_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG22_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG22_GPU_fcg_cfg22_START (0)
#define SOC_GPUCRG_FCG_CFG22_GPU_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG23_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG23_GPU_fcg_cfg23_START (0)
#define SOC_GPUCRG_FCG_CFG23_GPU_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG24_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG24_GPU_fcg_cfg24_START (0)
#define SOC_GPUCRG_FCG_CFG24_GPU_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG25_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG25_GPU_fcg_cfg25_START (0)
#define SOC_GPUCRG_FCG_CFG25_GPU_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG26_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG26_GPU_fcg_cfg26_START (0)
#define SOC_GPUCRG_FCG_CFG26_GPU_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG27_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG27_GPU_fcg_cfg27_START (0)
#define SOC_GPUCRG_FCG_CFG27_GPU_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT0_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT0_GPU_fcg_stat0_START (0)
#define SOC_GPUCRG_FCG_STAT0_GPU_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT1_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT1_GPU_fcg_stat1_START (0)
#define SOC_GPUCRG_FCG_STAT1_GPU_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT2_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT2_GPU_fcg_stat2_START (0)
#define SOC_GPUCRG_FCG_STAT2_GPU_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT3_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT3_GPU_fcg_stat3_START (0)
#define SOC_GPUCRG_FCG_STAT3_GPU_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT4_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT4_GPU_fcg_stat4_START (0)
#define SOC_GPUCRG_FCG_STAT4_GPU_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT5_GPU_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT5_GPU_fcg_stat5_START (0)
#define SOC_GPUCRG_FCG_STAT5_GPU_fcg_stat5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_cnt_us_gpu : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_CNT_US_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_CNT_US_GPU_apb_cnt_us_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_CNT_US_GPU_apb_cnt_us_gpu_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vol_cfg1_gpu : 8;
        unsigned int apb_vol_cfg2_gpu : 8;
        unsigned int apb_vol_cfg3_gpu : 8;
        unsigned int apb_vol_cfg4_gpu : 8;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg1_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg1_gpu_END (7)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg2_gpu_START (8)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg2_gpu_END (15)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg3_gpu_START (16)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg3_gpu_END (23)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg4_gpu_START (24)
#define SOC_GPUCRG_ONSYS_AVS_VOL_CFG_GPU_apb_vol_cfg4_gpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_onsys_enable_gpu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_ENABLE_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_ENABLE_GPU_apb_onsys_enable_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_ENABLE_GPU_apb_onsys_enable_gpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_monitor_time_gpu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_TIME_CFG_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_TIME_CFG_GPU_apb_monitor_time_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_TIME_CFG_GPU_apb_monitor_time_gpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th1_gpu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_VS_TH_0_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_0_GPU_apb_vs_th1_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_0_GPU_apb_vs_th1_gpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th2_gpu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_VS_TH_1_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_1_GPU_apb_vs_th2_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_1_GPU_apb_vs_th2_gpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th3_gpu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_VS_TH_2_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_2_GPU_apb_vs_th3_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_VS_TH_2_GPU_apb_vs_th3_gpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vol_add_max_a : 16;
        unsigned int apb_vol_sub_min_a : 16;
    } reg;
} SOC_GPUCRG_ONSYS_VOL_SUB_ADD_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_VOL_SUB_ADD_GPU_apb_vol_add_max_a_START (0)
#define SOC_GPUCRG_ONSYS_VOL_SUB_ADD_GPU_apb_vol_add_max_a_END (15)
#define SOC_GPUCRG_ONSYS_VOL_SUB_ADD_GPU_apb_vol_sub_min_a_START (16)
#define SOC_GPUCRG_ONSYS_VOL_SUB_ADD_GPU_apb_vol_sub_min_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int onsys_avs_cfg_gpu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_ONSYS_AVS_CFG_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_AVS_CFG_GPU_onsys_avs_cfg_gpu_START (0)
#define SOC_GPUCRG_ONSYS_AVS_CFG_GPU_onsys_avs_cfg_gpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vol_sub_flag_a : 1;
        unsigned int apb_vol_idx_a : 8;
        unsigned int apb_cur_stat_a : 2;
        unsigned int reserved : 21;
    } reg;
} SOC_GPUCRG_ONSYS_CURR_STAT_GPU_UNION;
#endif
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_apb_vol_sub_flag_a_START (0)
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_apb_vol_sub_flag_a_END (0)
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_apb_vol_idx_a_START (1)
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_apb_vol_idx_a_END (8)
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_apb_cur_stat_a_START (9)
#define SOC_GPUCRG_ONSYS_CURR_STAT_GPU_apb_cur_stat_a_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_stat0 : 32;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_STAT_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_STAT_GPU_fdcs_onsys_stat0_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_STAT_GPU_fdcs_onsys_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg0 : 10;
        unsigned int coef_cfg1 : 10;
        unsigned int coef_cfg2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_coef_cfg0_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_coef_cfg0_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_coef_cfg1_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_coef_cfg1_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_coef_cfg2_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG0_GPU_coef_cfg2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg3 : 10;
        unsigned int coef_cfg4 : 10;
        unsigned int coef_cfg5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_coef_cfg3_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_coef_cfg3_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_coef_cfg4_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_coef_cfg4_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_coef_cfg5_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG1_GPU_coef_cfg5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg6 : 10;
        unsigned int coef_cfg7 : 10;
        unsigned int coef_cfg8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_coef_cfg6_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_coef_cfg6_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_coef_cfg7_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_coef_cfg7_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_coef_cfg8_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG2_GPU_coef_cfg8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg9 : 10;
        unsigned int coef_cfg10 : 10;
        unsigned int coef_cfg11 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_coef_cfg9_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_coef_cfg9_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_coef_cfg10_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_coef_cfg10_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_coef_cfg11_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG3_GPU_coef_cfg11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg12 : 10;
        unsigned int coef_cfg13 : 10;
        unsigned int coef_cfg14 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_coef_cfg12_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_coef_cfg12_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_coef_cfg13_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_coef_cfg13_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_coef_cfg14_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG4_GPU_coef_cfg14_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg15 : 10;
        unsigned int coef_cfg16 : 10;
        unsigned int coef_cfg17 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_coef_cfg15_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_coef_cfg15_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_coef_cfg16_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_coef_cfg16_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_coef_cfg17_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG5_GPU_coef_cfg17_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg18 : 10;
        unsigned int coef_cfg19 : 10;
        unsigned int coef_cfg20 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_coef_cfg18_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_coef_cfg18_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_coef_cfg19_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_coef_cfg19_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_coef_cfg20_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG6_GPU_coef_cfg20_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg21 : 10;
        unsigned int coef_cfg22 : 10;
        unsigned int coef_cfg23 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_coef_cfg21_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_coef_cfg21_END (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_coef_cfg22_START (10)
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_coef_cfg22_END (19)
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_coef_cfg23_START (20)
#define SOC_GPUCRG_FDCS_ONSYS_CFG7_GPU_coef_cfg23_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w0 : 8;
        unsigned int coef_w1 : 8;
        unsigned int coef_w2 : 8;
        unsigned int coef_w3 : 8;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w0_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w0_END (7)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w1_START (8)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w1_END (15)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w2_START (16)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w2_END (23)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w3_START (24)
#define SOC_GPUCRG_FDCS_ONSYS_CFG8_GPU_coef_w3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w4 : 8;
        unsigned int coef_m : 5;
        unsigned int reserved : 19;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG9_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG9_GPU_coef_w4_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG9_GPU_coef_w4_END (7)
#define SOC_GPUCRG_FDCS_ONSYS_CFG9_GPU_coef_m_START (8)
#define SOC_GPUCRG_FDCS_ONSYS_CFG9_GPU_coef_m_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd_thr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG10_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG10_GPU_accu_fd_thr_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG10_GPU_accu_fd_thr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vol_max_thr : 9;
        unsigned int vol_min_thr : 9;
        unsigned int vol_add : 4;
        unsigned int vol_add_bypass : 1;
        unsigned int fdcs_onsys_cfg11_a : 9;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_max_thr_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_max_thr_END (8)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_min_thr_START (9)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_min_thr_END (17)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_add_START (18)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_add_END (21)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_add_bypass_START (22)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_vol_add_bypass_END (22)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_fdcs_onsys_cfg11_a_START (23)
#define SOC_GPUCRG_FDCS_ONSYS_CFG11_GPU_fdcs_onsys_cfg11_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg12_a : 32;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG12_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG12_GPU_fdcs_onsys_cfg12_a_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG12_GPU_fdcs_onsys_cfg12_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg13_a : 32;
    } reg;
} SOC_GPUCRG_FDCS_ONSYS_CFG13_GPU_UNION;
#endif
#define SOC_GPUCRG_FDCS_ONSYS_CFG13_GPU_fdcs_onsys_cfg13_a_START (0)
#define SOC_GPUCRG_FDCS_ONSYS_CFG13_GPU_fdcs_onsys_cfg13_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_en : 1;
        unsigned int accu_fd_en : 1;
        unsigned int peaklow_en : 1;
        unsigned int clear_all_en : 1;
        unsigned int cnt_timer_hd_en : 1;
        unsigned int hs_fsm_mode : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_GPUCRG_MON_CFG0_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG0_GPU_cnt_timer_en_START (0)
#define SOC_GPUCRG_MON_CFG0_GPU_cnt_timer_en_END (0)
#define SOC_GPUCRG_MON_CFG0_GPU_accu_fd_en_START (1)
#define SOC_GPUCRG_MON_CFG0_GPU_accu_fd_en_END (1)
#define SOC_GPUCRG_MON_CFG0_GPU_peaklow_en_START (2)
#define SOC_GPUCRG_MON_CFG0_GPU_peaklow_en_END (2)
#define SOC_GPUCRG_MON_CFG0_GPU_clear_all_en_START (3)
#define SOC_GPUCRG_MON_CFG0_GPU_clear_all_en_END (3)
#define SOC_GPUCRG_MON_CFG0_GPU_cnt_timer_hd_en_START (4)
#define SOC_GPUCRG_MON_CFG0_GPU_cnt_timer_hd_en_END (4)
#define SOC_GPUCRG_MON_CFG0_GPU_hs_fsm_mode_START (5)
#define SOC_GPUCRG_MON_CFG0_GPU_hs_fsm_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPUCRG_MON_CFG1_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG1_GPU_read_lock_START (0)
#define SOC_GPUCRG_MON_CFG1_GPU_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_GPUCRG_MON_CFG2_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG2_GPU_bin_peaklow_en_START (0)
#define SOC_GPUCRG_MON_CFG2_GPU_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG3_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG3_GPU_vth0_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG3_GPU_vth0_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG3_GPU_vth1_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG3_GPU_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG4_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG4_GPU_vth2_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG4_GPU_vth2_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG4_GPU_vth3_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG4_GPU_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG5_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG5_GPU_vth4_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG5_GPU_vth4_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG5_GPU_vth5_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG5_GPU_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG6_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG6_GPU_vth6_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG6_GPU_vth6_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG6_GPU_vth7_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG6_GPU_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG7_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG7_GPU_vth8_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG7_GPU_vth8_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG7_GPU_vth9_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG7_GPU_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG8_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG8_GPU_vth10_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG8_GPU_vth10_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG8_GPU_vth11_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG8_GPU_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG9_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG9_GPU_vth12_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG9_GPU_vth12_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG9_GPU_vth13_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG9_GPU_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG10_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG10_GPU_vth14_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG10_GPU_vth14_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG10_GPU_vth15_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG10_GPU_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG11_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG11_GPU_vth16_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG11_GPU_vth16_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG11_GPU_vth17_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG11_GPU_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG12_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG12_GPU_vth18_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG12_GPU_vth18_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG12_GPU_vth19_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG12_GPU_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_GPUCRG_MON_CFG13_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG13_GPU_vth20_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG13_GPU_vth20_peaklow_END (15)
#define SOC_GPUCRG_MON_CFG13_GPU_vth21_peaklow_START (16)
#define SOC_GPUCRG_MON_CFG13_GPU_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_MON_CFG14_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG14_GPU_vth22_peaklow_START (0)
#define SOC_GPUCRG_MON_CFG14_GPU_vth22_peaklow_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_hd_th : 22;
        unsigned int reserved : 8;
        unsigned int read_lock_mode : 1;
        unsigned int sel_peaklow_vth : 1;
    } reg;
} SOC_GPUCRG_MON_CFG15_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG15_GPU_cnt_timer_hd_th_START (0)
#define SOC_GPUCRG_MON_CFG15_GPU_cnt_timer_hd_th_END (21)
#define SOC_GPUCRG_MON_CFG15_GPU_read_lock_mode_START (30)
#define SOC_GPUCRG_MON_CFG15_GPU_read_lock_mode_END (30)
#define SOC_GPUCRG_MON_CFG15_GPU_sel_peaklow_vth_START (31)
#define SOC_GPUCRG_MON_CFG15_GPU_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPUCRG_MON_CFG16_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_CFG16_GPU_pim_peaklow_vth_START (0)
#define SOC_GPUCRG_MON_CFG16_GPU_pim_peaklow_vth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer : 22;
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 4;
    } reg;
} SOC_GPUCRG_MON_STAT0_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT0_GPU_cnt_timer_START (0)
#define SOC_GPUCRG_MON_STAT0_GPU_cnt_timer_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd : 25;
        unsigned int reserved_0: 3;
        unsigned int reserved_1: 4;
    } reg;
} SOC_GPUCRG_MON_STAT1_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT1_GPU_accu_fd_START (0)
#define SOC_GPUCRG_MON_STAT1_GPU_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT2_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT2_GPU_bin0_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT2_GPU_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT3_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT3_GPU_bin1_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT3_GPU_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT4_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT4_GPU_bin2_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT4_GPU_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT5_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT5_GPU_bin3_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT5_GPU_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT6_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT6_GPU_bin4_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT6_GPU_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT7_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT7_GPU_bin5_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT7_GPU_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT8_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT8_GPU_bin6_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT8_GPU_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT9_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT9_GPU_bin7_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT9_GPU_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT10_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT10_GPU_bin8_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT10_GPU_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT11_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT11_GPU_bin9_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT11_GPU_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT12_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT12_GPU_bin10_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT12_GPU_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT13_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT13_GPU_bin11_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT13_GPU_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT14_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT14_GPU_bin12_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT14_GPU_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT15_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT15_GPU_bin13_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT15_GPU_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT16_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT16_GPU_bin14_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT16_GPU_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT17_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT17_GPU_bin15_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT17_GPU_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT18_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT18_GPU_bin16_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT18_GPU_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT19_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT19_GPU_bin17_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT19_GPU_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT20_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT20_GPU_bin18_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT20_GPU_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT21_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT21_GPU_bin19_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT21_GPU_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT22_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT22_GPU_bin20_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT22_GPU_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT23_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT23_GPU_bin21_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT23_GPU_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT24_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT24_GPU_bin22_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT24_GPU_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_GPUCRG_MON_STAT25_GPU_UNION;
#endif
#define SOC_GPUCRG_MON_STAT25_GPU_bin23_peaklow_START (0)
#define SOC_GPUCRG_MON_STAT25_GPU_bin23_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_drop_en_bypass : 1;
        unsigned int pim_peaklow_en_bypass : 1;
        unsigned int pim_drop_update_bypass : 1;
        unsigned int cnt_thr : 4;
        unsigned int ffc_en_bypass : 1;
        unsigned int ffc_cnt_thr : 2;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_GPUCRG_FDCS_XPU_CFG_UNION;
#endif
#define SOC_GPUCRG_FDCS_XPU_CFG_pim_drop_en_bypass_START (0)
#define SOC_GPUCRG_FDCS_XPU_CFG_pim_drop_en_bypass_END (0)
#define SOC_GPUCRG_FDCS_XPU_CFG_pim_peaklow_en_bypass_START (1)
#define SOC_GPUCRG_FDCS_XPU_CFG_pim_peaklow_en_bypass_END (1)
#define SOC_GPUCRG_FDCS_XPU_CFG_pim_drop_update_bypass_START (2)
#define SOC_GPUCRG_FDCS_XPU_CFG_pim_drop_update_bypass_END (2)
#define SOC_GPUCRG_FDCS_XPU_CFG_cnt_thr_START (3)
#define SOC_GPUCRG_FDCS_XPU_CFG_cnt_thr_END (6)
#define SOC_GPUCRG_FDCS_XPU_CFG_ffc_en_bypass_START (7)
#define SOC_GPUCRG_FDCS_XPU_CFG_ffc_en_bypass_END (7)
#define SOC_GPUCRG_FDCS_XPU_CFG_ffc_cnt_thr_START (8)
#define SOC_GPUCRG_FDCS_XPU_CFG_ffc_cnt_thr_END (9)
#define SOC_GPUCRG_FDCS_XPU_CFG_bitmasken_START (16)
#define SOC_GPUCRG_FDCS_XPU_CFG_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG0_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG0_FCM_d2a_fcg_ana_cfg0_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG0_FCM_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG1_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG1_FCM_d2a_fcg_ana_cfg1_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG1_FCM_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG2_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG2_FCM_d2a_fcg_ana_cfg2_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG2_FCM_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_GPUCRG_FCG_ANA_CFG3_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_ANA_CFG3_FCM_d2a_fcg_ana_cfg3_START (0)
#define SOC_GPUCRG_FCG_ANA_CFG3_FCM_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG0_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG0_FCM_fcg_cfg0_START (0)
#define SOC_GPUCRG_FCG_CFG0_FCM_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG1_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG1_FCM_fcg_cfg1_START (0)
#define SOC_GPUCRG_FCG_CFG1_FCM_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG2_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG2_FCM_fcg_cfg2_START (0)
#define SOC_GPUCRG_FCG_CFG2_FCM_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG3_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG3_FCM_fcg_cfg3_START (0)
#define SOC_GPUCRG_FCG_CFG3_FCM_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG4_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG4_FCM_fcg_cfg4_START (0)
#define SOC_GPUCRG_FCG_CFG4_FCM_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG5_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG5_FCM_fcg_cfg5_START (0)
#define SOC_GPUCRG_FCG_CFG5_FCM_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG6_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG6_FCM_fcg_cfg6_START (0)
#define SOC_GPUCRG_FCG_CFG6_FCM_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG7_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG7_FCM_fcg_cfg7_START (0)
#define SOC_GPUCRG_FCG_CFG7_FCM_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG8_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG8_FCM_fcg_cfg8_START (0)
#define SOC_GPUCRG_FCG_CFG8_FCM_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG9_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG9_FCM_fcg_cfg9_START (0)
#define SOC_GPUCRG_FCG_CFG9_FCM_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG10_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG10_FCM_fcg_cfg10_START (0)
#define SOC_GPUCRG_FCG_CFG10_FCM_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG11_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG11_FCM_fcg_cfg11_START (0)
#define SOC_GPUCRG_FCG_CFG11_FCM_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG12_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG12_FCM_fcg_cfg12_START (0)
#define SOC_GPUCRG_FCG_CFG12_FCM_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG13_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG13_FCM_fcg_cfg13_START (0)
#define SOC_GPUCRG_FCG_CFG13_FCM_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG14_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG14_FCM_fcg_cfg14_START (0)
#define SOC_GPUCRG_FCG_CFG14_FCM_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG15_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG15_FCM_fcg_cfg15_START (0)
#define SOC_GPUCRG_FCG_CFG15_FCM_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG16_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG16_FCM_fcg_cfg16_START (0)
#define SOC_GPUCRG_FCG_CFG16_FCM_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG17_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG17_FCM_fcg_cfg17_START (0)
#define SOC_GPUCRG_FCG_CFG17_FCM_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG18_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG18_FCM_fcg_cfg18_START (0)
#define SOC_GPUCRG_FCG_CFG18_FCM_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG19_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG19_FCM_fcg_cfg19_START (0)
#define SOC_GPUCRG_FCG_CFG19_FCM_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG20_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG20_FCM_fcg_cfg20_START (0)
#define SOC_GPUCRG_FCG_CFG20_FCM_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG21_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG21_FCM_fcg_cfg21_START (0)
#define SOC_GPUCRG_FCG_CFG21_FCM_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG22_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG22_FCM_fcg_cfg22_START (0)
#define SOC_GPUCRG_FCG_CFG22_FCM_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG23_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG23_FCM_fcg_cfg23_START (0)
#define SOC_GPUCRG_FCG_CFG23_FCM_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG24_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG24_FCM_fcg_cfg24_START (0)
#define SOC_GPUCRG_FCG_CFG24_FCM_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG25_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG25_FCM_fcg_cfg25_START (0)
#define SOC_GPUCRG_FCG_CFG25_FCM_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG26_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG26_FCM_fcg_cfg26_START (0)
#define SOC_GPUCRG_FCG_CFG26_FCM_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_GPUCRG_FCG_CFG27_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_CFG27_FCM_fcg_cfg27_START (0)
#define SOC_GPUCRG_FCG_CFG27_FCM_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT0_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT0_FCM_fcg_stat0_START (0)
#define SOC_GPUCRG_FCG_STAT0_FCM_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT1_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT1_FCM_fcg_stat1_START (0)
#define SOC_GPUCRG_FCG_STAT1_FCM_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT2_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT2_FCM_fcg_stat2_START (0)
#define SOC_GPUCRG_FCG_STAT2_FCM_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT3_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT3_FCM_fcg_stat3_START (0)
#define SOC_GPUCRG_FCG_STAT3_FCM_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT4_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT4_FCM_fcg_stat4_START (0)
#define SOC_GPUCRG_FCG_STAT4_FCM_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_GPUCRG_FCG_STAT5_FCM_UNION;
#endif
#define SOC_GPUCRG_FCG_STAT5_FCM_fcg_stat5_START (0)
#define SOC_GPUCRG_FCG_STAT5_FCM_fcg_stat5_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
