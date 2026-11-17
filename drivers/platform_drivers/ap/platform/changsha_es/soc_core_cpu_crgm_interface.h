#ifndef __SOC_CORE_CPU_CRGM_INTERFACE_H__
#define __SOC_CORE_CPU_CRGM_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CORE_CPU_CRGM_PEREN0_ADDR(base) ((base) + (0x400UL))
#define SOC_CORE_CPU_CRGM_PERDIS0_ADDR(base) ((base) + (0x404UL))
#define SOC_CORE_CPU_CRGM_PERCLKEN0_ADDR(base) ((base) + (0x408UL))
#define SOC_CORE_CPU_CRGM_PERSTAT0_ADDR(base) ((base) + (0x40CUL))
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ADDR(base) ((base) + (0x410UL))
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ADDR(base) ((base) + (0x414UL))
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ADDR(base) ((base) + (0x418UL))
#define SOC_CORE_CPU_CRGM_CLKDIV0_ADDR(base) ((base) + (0x420UL))
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_ADDR(base) ((base) + (0x424UL))
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_ADDR(base) ((base) + (0x428UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG_RSV1_ADDR(base) ((base) + (0x42CUL))
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_ADDR(base) ((base) + (0x430UL))
#define SOC_CORE_CPU_CRGM_FCG_STAT0_ADDR(base) ((base) + (0x434UL))
#define SOC_CORE_CPU_CRGM_FCM_CLKEN_ADDR(base) ((base) + (0x438UL))
#define SOC_CORE_CPU_CRGM_RSV_CFG0_ADDR(base) ((base) + (0x43cUL))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_CFG_M_ADDR(base) ((base) + (0x440UL))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_TIME_CFG_M_ADDR(base) ((base) + (0x444UL))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_0_M_ADDR(base) ((base) + (0x448UL))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_ADDR(base) ((base) + (0x44cUL))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_ADDR(base) ((base) + (0x450UL))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + (0x454UL))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_ADDR(base) ((base) + (0x458UL))
#define SOC_CORE_CPU_CRGM_APB_ONSYS_ENABLE_ADDR(base) ((base) + (0x45cUL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_ADDR(base) ((base) + (0x460UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_ADDR(base) ((base) + (0x464UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_ADDR(base) ((base) + (0x468UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_ADDR(base) ((base) + (0x46cUL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_ADDR(base) ((base) + (0x470UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_ADDR(base) ((base) + (0x474UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_ADDR(base) ((base) + (0x478UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_ADDR(base) ((base) + (0x47cUL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_ADDR(base) ((base) + (0x480UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG9_M_ADDR(base) ((base) + (0x484UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG10_M_ADDR(base) ((base) + (0x488UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_ADDR(base) ((base) + (0x48cUL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG12_M_ADDR(base) ((base) + (0x490UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG13_M_ADDR(base) ((base) + (0x494UL))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_STAT_M_ADDR(base) ((base) + (0x498UL))
#define SOC_CORE_CPU_CRGM_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x49CUL))
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_ADDR(base) ((base) + (0x500UL))
#define SOC_CORE_CPU_CRGM_PIM_CFG0_MIDDLE_ADDR(base) ((base) + (0x504UL))
#define SOC_CORE_CPU_CRGM_PIM_CFG1_MIDDLE_ADDR(base) ((base) + (0x508UL))
#define SOC_CORE_CPU_CRGM_PIM_CFG2_MIDDLE_ADDR(base) ((base) + (0x50cUL))
#define SOC_CORE_CPU_CRGM_PIM_CFG3_MIDDLE_ADDR(base) ((base) + (0x510UL))
#define SOC_CORE_CPU_CRGM_PIM_STAT0_ADDR(base) ((base) + (0x514UL))
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_ADDR(base) ((base) + (0x518UL))
#define SOC_CORE_CPU_CRGM_MON_CFG1_MIDDLE_ADDR(base) ((base) + (0x51cUL))
#define SOC_CORE_CPU_CRGM_MON_CFG2_MIDDLE_ADDR(base) ((base) + (0x520UL))
#define SOC_CORE_CPU_CRGM_MON_CFG3_MIDDLE_ADDR(base) ((base) + (0x524UL))
#define SOC_CORE_CPU_CRGM_MON_CFG4_MIDDLE_ADDR(base) ((base) + (0x528UL))
#define SOC_CORE_CPU_CRGM_MON_CFG5_MIDDLE_ADDR(base) ((base) + (0x52cUL))
#define SOC_CORE_CPU_CRGM_MON_CFG6_MIDDLE_ADDR(base) ((base) + (0x530UL))
#define SOC_CORE_CPU_CRGM_MON_CFG7_MIDDLE_ADDR(base) ((base) + (0x534UL))
#define SOC_CORE_CPU_CRGM_MON_CFG8_MIDDLE_ADDR(base) ((base) + (0x538UL))
#define SOC_CORE_CPU_CRGM_MON_CFG9_MIDDLE_ADDR(base) ((base) + (0x53cUL))
#define SOC_CORE_CPU_CRGM_MON_CFG10_MIDDLE_ADDR(base) ((base) + (0x540UL))
#define SOC_CORE_CPU_CRGM_MON_CFG11_MIDDLE_ADDR(base) ((base) + (0x544UL))
#define SOC_CORE_CPU_CRGM_MON_CFG12_MIDDLE_ADDR(base) ((base) + (0x548UL))
#define SOC_CORE_CPU_CRGM_MON_CFG13_MIDDLE_ADDR(base) ((base) + (0x54cUL))
#define SOC_CORE_CPU_CRGM_MON_CFG14_MIDDLE_ADDR(base) ((base) + (0x550UL))
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_ADDR(base) ((base) + (0x554UL))
#define SOC_CORE_CPU_CRGM_MON_CFG16_MIDDLE_ADDR(base) ((base) + (0x558UL))
#define SOC_CORE_CPU_CRGM_MON_STAT0_MIDDLE_ADDR(base) ((base) + (0x55cUL))
#define SOC_CORE_CPU_CRGM_MON_STAT1_MIDDLE_ADDR(base) ((base) + (0x560UL))
#define SOC_CORE_CPU_CRGM_MON_STAT2_MIDDLE_ADDR(base) ((base) + (0x564UL))
#define SOC_CORE_CPU_CRGM_MON_STAT3_MIDDLE_ADDR(base) ((base) + (0x568UL))
#define SOC_CORE_CPU_CRGM_MON_STAT4_MIDDLE_ADDR(base) ((base) + (0x56cUL))
#define SOC_CORE_CPU_CRGM_MON_STAT5_MIDDLE_ADDR(base) ((base) + (0x570UL))
#define SOC_CORE_CPU_CRGM_MON_STAT6_MIDDLE_ADDR(base) ((base) + (0x574UL))
#define SOC_CORE_CPU_CRGM_MON_STAT7_MIDDLE_ADDR(base) ((base) + (0x578UL))
#define SOC_CORE_CPU_CRGM_MON_STAT8_MIDDLE_ADDR(base) ((base) + (0x57cUL))
#define SOC_CORE_CPU_CRGM_MON_STAT9_MIDDLE_ADDR(base) ((base) + (0x580UL))
#define SOC_CORE_CPU_CRGM_MON_STAT10_MIDDLE_ADDR(base) ((base) + (0x584UL))
#define SOC_CORE_CPU_CRGM_MON_STAT11_MIDDLE_ADDR(base) ((base) + (0x588UL))
#define SOC_CORE_CPU_CRGM_MON_STAT12_MIDDLE_ADDR(base) ((base) + (0x58cUL))
#define SOC_CORE_CPU_CRGM_MON_STAT13_MIDDLE_ADDR(base) ((base) + (0x590UL))
#define SOC_CORE_CPU_CRGM_MON_STAT14_MIDDLE_ADDR(base) ((base) + (0x594UL))
#define SOC_CORE_CPU_CRGM_MON_STAT15_MIDDLE_ADDR(base) ((base) + (0x598UL))
#define SOC_CORE_CPU_CRGM_MON_STAT16_MIDDLE_ADDR(base) ((base) + (0x59cUL))
#define SOC_CORE_CPU_CRGM_MON_STAT17_MIDDLE_ADDR(base) ((base) + (0x5A0UL))
#define SOC_CORE_CPU_CRGM_MON_STAT18_MIDDLE_ADDR(base) ((base) + (0x5A4UL))
#define SOC_CORE_CPU_CRGM_MON_STAT19_MIDDLE_ADDR(base) ((base) + (0x5A8UL))
#define SOC_CORE_CPU_CRGM_MON_STAT20_MIDDLE_ADDR(base) ((base) + (0x5ACUL))
#define SOC_CORE_CPU_CRGM_MON_STAT21_MIDDLE_ADDR(base) ((base) + (0x5B0UL))
#define SOC_CORE_CPU_CRGM_MON_STAT22_MIDDLE_ADDR(base) ((base) + (0x5B4UL))
#define SOC_CORE_CPU_CRGM_MON_STAT23_MIDDLE_ADDR(base) ((base) + (0x5B8UL))
#define SOC_CORE_CPU_CRGM_MON_STAT24_MIDDLE_ADDR(base) ((base) + (0x5BCUL))
#define SOC_CORE_CPU_CRGM_MON_STAT25_MIDDLE_ADDR(base) ((base) + (0x5C0UL))
#define SOC_CORE_CPU_CRGM_CLKDIV2_ADDR(base) ((base) + (0x604UL))
#define SOC_CORE_CPU_CRGM_CLKDIV3_ADDR(base) ((base) + (0x608UL))
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_ADDR(base) ((base) + (0x660UL))
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL1_ADDR(base) ((base) + (0x664UL))
#define SOC_CORE_CPU_CRGM_FCG_CNT_STATE0_ADDR(base) ((base) + (0x668UL))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG0_MIDDLE_ADDR(base) ((base) + (0x700UL))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG1_MIDDLE_ADDR(base) ((base) + (0x704UL))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG2_MIDDLE_ADDR(base) ((base) + (0x708UL))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG3_MIDDLE_ADDR(base) ((base) + (0x70CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG0_MIDDLE_ADDR(base) ((base) + (0x718UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG1_MIDDLE_ADDR(base) ((base) + (0x71CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG2_MIDDLE_ADDR(base) ((base) + (0x720UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG3_MIDDLE_ADDR(base) ((base) + (0x724UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG4_MIDDLE_ADDR(base) ((base) + (0x728UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG5_MIDDLE_ADDR(base) ((base) + (0x72CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG6_MIDDLE_ADDR(base) ((base) + (0x730UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG7_MIDDLE_ADDR(base) ((base) + (0x734UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG8_MIDDLE_ADDR(base) ((base) + (0x738UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG9_MIDDLE_ADDR(base) ((base) + (0x73CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG10_MIDDLE_ADDR(base) ((base) + (0x740UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG11_MIDDLE_ADDR(base) ((base) + (0x744UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG12_MIDDLE_ADDR(base) ((base) + (0x748UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG13_MIDDLE_ADDR(base) ((base) + (0x74CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG14_MIDDLE_ADDR(base) ((base) + (0x750UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG15_MIDDLE_ADDR(base) ((base) + (0x754UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG16_MIDDLE_ADDR(base) ((base) + (0x758UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG17_MIDDLE_ADDR(base) ((base) + (0x75CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG18_MIDDLE_ADDR(base) ((base) + (0x760UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG19_MIDDLE_ADDR(base) ((base) + (0x764UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG20_MIDDLE_ADDR(base) ((base) + (0x768UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG21_MIDDLE_ADDR(base) ((base) + (0x76CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG22_MIDDLE_ADDR(base) ((base) + (0x770UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG23_MIDDLE_ADDR(base) ((base) + (0x774UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG24_MIDDLE_ADDR(base) ((base) + (0x778UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG25_MIDDLE_ADDR(base) ((base) + (0x77CUL))
#define SOC_CORE_CPU_CRGM_FCG_CFG26_MIDDLE_ADDR(base) ((base) + (0x780UL))
#define SOC_CORE_CPU_CRGM_FCG_CFG27_MIDDLE_ADDR(base) ((base) + (0x784UL))
#define SOC_CORE_CPU_CRGM_FCG_STAT0_MIDDLE_ADDR(base) ((base) + (0x790UL))
#define SOC_CORE_CPU_CRGM_FCG_STAT1_MIDDLE_ADDR(base) ((base) + (0x794UL))
#define SOC_CORE_CPU_CRGM_FCG_STAT2_MIDDLE_ADDR(base) ((base) + (0x798UL))
#define SOC_CORE_CPU_CRGM_FCG_STAT3_MIDDLE_ADDR(base) ((base) + (0x79CUL))
#define SOC_CORE_CPU_CRGM_FCG_STAT4_MIDDLE_ADDR(base) ((base) + (0x7A0UL))
#define SOC_CORE_CPU_CRGM_FCG_STAT5_MIDDLE_ADDR(base) ((base) + (0x7A4UL))
#else
#define SOC_CORE_CPU_CRGM_PEREN0_ADDR(base) ((base) + (0x400))
#define SOC_CORE_CPU_CRGM_PERDIS0_ADDR(base) ((base) + (0x404))
#define SOC_CORE_CPU_CRGM_PERCLKEN0_ADDR(base) ((base) + (0x408))
#define SOC_CORE_CPU_CRGM_PERSTAT0_ADDR(base) ((base) + (0x40C))
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ADDR(base) ((base) + (0x410))
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ADDR(base) ((base) + (0x414))
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ADDR(base) ((base) + (0x418))
#define SOC_CORE_CPU_CRGM_CLKDIV0_ADDR(base) ((base) + (0x420))
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_ADDR(base) ((base) + (0x424))
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_ADDR(base) ((base) + (0x428))
#define SOC_CORE_CPU_CRGM_FCG_CFG_RSV1_ADDR(base) ((base) + (0x42C))
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_ADDR(base) ((base) + (0x430))
#define SOC_CORE_CPU_CRGM_FCG_STAT0_ADDR(base) ((base) + (0x434))
#define SOC_CORE_CPU_CRGM_FCM_CLKEN_ADDR(base) ((base) + (0x438))
#define SOC_CORE_CPU_CRGM_RSV_CFG0_ADDR(base) ((base) + (0x43c))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_CFG_M_ADDR(base) ((base) + (0x440))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_TIME_CFG_M_ADDR(base) ((base) + (0x444))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_0_M_ADDR(base) ((base) + (0x448))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_ADDR(base) ((base) + (0x44c))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_ADDR(base) ((base) + (0x450))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + (0x454))
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_ADDR(base) ((base) + (0x458))
#define SOC_CORE_CPU_CRGM_APB_ONSYS_ENABLE_ADDR(base) ((base) + (0x45c))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_ADDR(base) ((base) + (0x460))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_ADDR(base) ((base) + (0x464))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_ADDR(base) ((base) + (0x468))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_ADDR(base) ((base) + (0x46c))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_ADDR(base) ((base) + (0x470))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_ADDR(base) ((base) + (0x474))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_ADDR(base) ((base) + (0x478))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_ADDR(base) ((base) + (0x47c))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_ADDR(base) ((base) + (0x480))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG9_M_ADDR(base) ((base) + (0x484))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG10_M_ADDR(base) ((base) + (0x488))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_ADDR(base) ((base) + (0x48c))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG12_M_ADDR(base) ((base) + (0x490))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG13_M_ADDR(base) ((base) + (0x494))
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_STAT_M_ADDR(base) ((base) + (0x498))
#define SOC_CORE_CPU_CRGM_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x49C))
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_ADDR(base) ((base) + (0x500))
#define SOC_CORE_CPU_CRGM_PIM_CFG0_MIDDLE_ADDR(base) ((base) + (0x504))
#define SOC_CORE_CPU_CRGM_PIM_CFG1_MIDDLE_ADDR(base) ((base) + (0x508))
#define SOC_CORE_CPU_CRGM_PIM_CFG2_MIDDLE_ADDR(base) ((base) + (0x50c))
#define SOC_CORE_CPU_CRGM_PIM_CFG3_MIDDLE_ADDR(base) ((base) + (0x510))
#define SOC_CORE_CPU_CRGM_PIM_STAT0_ADDR(base) ((base) + (0x514))
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_ADDR(base) ((base) + (0x518))
#define SOC_CORE_CPU_CRGM_MON_CFG1_MIDDLE_ADDR(base) ((base) + (0x51c))
#define SOC_CORE_CPU_CRGM_MON_CFG2_MIDDLE_ADDR(base) ((base) + (0x520))
#define SOC_CORE_CPU_CRGM_MON_CFG3_MIDDLE_ADDR(base) ((base) + (0x524))
#define SOC_CORE_CPU_CRGM_MON_CFG4_MIDDLE_ADDR(base) ((base) + (0x528))
#define SOC_CORE_CPU_CRGM_MON_CFG5_MIDDLE_ADDR(base) ((base) + (0x52c))
#define SOC_CORE_CPU_CRGM_MON_CFG6_MIDDLE_ADDR(base) ((base) + (0x530))
#define SOC_CORE_CPU_CRGM_MON_CFG7_MIDDLE_ADDR(base) ((base) + (0x534))
#define SOC_CORE_CPU_CRGM_MON_CFG8_MIDDLE_ADDR(base) ((base) + (0x538))
#define SOC_CORE_CPU_CRGM_MON_CFG9_MIDDLE_ADDR(base) ((base) + (0x53c))
#define SOC_CORE_CPU_CRGM_MON_CFG10_MIDDLE_ADDR(base) ((base) + (0x540))
#define SOC_CORE_CPU_CRGM_MON_CFG11_MIDDLE_ADDR(base) ((base) + (0x544))
#define SOC_CORE_CPU_CRGM_MON_CFG12_MIDDLE_ADDR(base) ((base) + (0x548))
#define SOC_CORE_CPU_CRGM_MON_CFG13_MIDDLE_ADDR(base) ((base) + (0x54c))
#define SOC_CORE_CPU_CRGM_MON_CFG14_MIDDLE_ADDR(base) ((base) + (0x550))
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_ADDR(base) ((base) + (0x554))
#define SOC_CORE_CPU_CRGM_MON_CFG16_MIDDLE_ADDR(base) ((base) + (0x558))
#define SOC_CORE_CPU_CRGM_MON_STAT0_MIDDLE_ADDR(base) ((base) + (0x55c))
#define SOC_CORE_CPU_CRGM_MON_STAT1_MIDDLE_ADDR(base) ((base) + (0x560))
#define SOC_CORE_CPU_CRGM_MON_STAT2_MIDDLE_ADDR(base) ((base) + (0x564))
#define SOC_CORE_CPU_CRGM_MON_STAT3_MIDDLE_ADDR(base) ((base) + (0x568))
#define SOC_CORE_CPU_CRGM_MON_STAT4_MIDDLE_ADDR(base) ((base) + (0x56c))
#define SOC_CORE_CPU_CRGM_MON_STAT5_MIDDLE_ADDR(base) ((base) + (0x570))
#define SOC_CORE_CPU_CRGM_MON_STAT6_MIDDLE_ADDR(base) ((base) + (0x574))
#define SOC_CORE_CPU_CRGM_MON_STAT7_MIDDLE_ADDR(base) ((base) + (0x578))
#define SOC_CORE_CPU_CRGM_MON_STAT8_MIDDLE_ADDR(base) ((base) + (0x57c))
#define SOC_CORE_CPU_CRGM_MON_STAT9_MIDDLE_ADDR(base) ((base) + (0x580))
#define SOC_CORE_CPU_CRGM_MON_STAT10_MIDDLE_ADDR(base) ((base) + (0x584))
#define SOC_CORE_CPU_CRGM_MON_STAT11_MIDDLE_ADDR(base) ((base) + (0x588))
#define SOC_CORE_CPU_CRGM_MON_STAT12_MIDDLE_ADDR(base) ((base) + (0x58c))
#define SOC_CORE_CPU_CRGM_MON_STAT13_MIDDLE_ADDR(base) ((base) + (0x590))
#define SOC_CORE_CPU_CRGM_MON_STAT14_MIDDLE_ADDR(base) ((base) + (0x594))
#define SOC_CORE_CPU_CRGM_MON_STAT15_MIDDLE_ADDR(base) ((base) + (0x598))
#define SOC_CORE_CPU_CRGM_MON_STAT16_MIDDLE_ADDR(base) ((base) + (0x59c))
#define SOC_CORE_CPU_CRGM_MON_STAT17_MIDDLE_ADDR(base) ((base) + (0x5A0))
#define SOC_CORE_CPU_CRGM_MON_STAT18_MIDDLE_ADDR(base) ((base) + (0x5A4))
#define SOC_CORE_CPU_CRGM_MON_STAT19_MIDDLE_ADDR(base) ((base) + (0x5A8))
#define SOC_CORE_CPU_CRGM_MON_STAT20_MIDDLE_ADDR(base) ((base) + (0x5AC))
#define SOC_CORE_CPU_CRGM_MON_STAT21_MIDDLE_ADDR(base) ((base) + (0x5B0))
#define SOC_CORE_CPU_CRGM_MON_STAT22_MIDDLE_ADDR(base) ((base) + (0x5B4))
#define SOC_CORE_CPU_CRGM_MON_STAT23_MIDDLE_ADDR(base) ((base) + (0x5B8))
#define SOC_CORE_CPU_CRGM_MON_STAT24_MIDDLE_ADDR(base) ((base) + (0x5BC))
#define SOC_CORE_CPU_CRGM_MON_STAT25_MIDDLE_ADDR(base) ((base) + (0x5C0))
#define SOC_CORE_CPU_CRGM_CLKDIV2_ADDR(base) ((base) + (0x604))
#define SOC_CORE_CPU_CRGM_CLKDIV3_ADDR(base) ((base) + (0x608))
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_ADDR(base) ((base) + (0x660))
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL1_ADDR(base) ((base) + (0x664))
#define SOC_CORE_CPU_CRGM_FCG_CNT_STATE0_ADDR(base) ((base) + (0x668))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG0_MIDDLE_ADDR(base) ((base) + (0x700))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG1_MIDDLE_ADDR(base) ((base) + (0x704))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG2_MIDDLE_ADDR(base) ((base) + (0x708))
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG3_MIDDLE_ADDR(base) ((base) + (0x70C))
#define SOC_CORE_CPU_CRGM_FCG_CFG0_MIDDLE_ADDR(base) ((base) + (0x718))
#define SOC_CORE_CPU_CRGM_FCG_CFG1_MIDDLE_ADDR(base) ((base) + (0x71C))
#define SOC_CORE_CPU_CRGM_FCG_CFG2_MIDDLE_ADDR(base) ((base) + (0x720))
#define SOC_CORE_CPU_CRGM_FCG_CFG3_MIDDLE_ADDR(base) ((base) + (0x724))
#define SOC_CORE_CPU_CRGM_FCG_CFG4_MIDDLE_ADDR(base) ((base) + (0x728))
#define SOC_CORE_CPU_CRGM_FCG_CFG5_MIDDLE_ADDR(base) ((base) + (0x72C))
#define SOC_CORE_CPU_CRGM_FCG_CFG6_MIDDLE_ADDR(base) ((base) + (0x730))
#define SOC_CORE_CPU_CRGM_FCG_CFG7_MIDDLE_ADDR(base) ((base) + (0x734))
#define SOC_CORE_CPU_CRGM_FCG_CFG8_MIDDLE_ADDR(base) ((base) + (0x738))
#define SOC_CORE_CPU_CRGM_FCG_CFG9_MIDDLE_ADDR(base) ((base) + (0x73C))
#define SOC_CORE_CPU_CRGM_FCG_CFG10_MIDDLE_ADDR(base) ((base) + (0x740))
#define SOC_CORE_CPU_CRGM_FCG_CFG11_MIDDLE_ADDR(base) ((base) + (0x744))
#define SOC_CORE_CPU_CRGM_FCG_CFG12_MIDDLE_ADDR(base) ((base) + (0x748))
#define SOC_CORE_CPU_CRGM_FCG_CFG13_MIDDLE_ADDR(base) ((base) + (0x74C))
#define SOC_CORE_CPU_CRGM_FCG_CFG14_MIDDLE_ADDR(base) ((base) + (0x750))
#define SOC_CORE_CPU_CRGM_FCG_CFG15_MIDDLE_ADDR(base) ((base) + (0x754))
#define SOC_CORE_CPU_CRGM_FCG_CFG16_MIDDLE_ADDR(base) ((base) + (0x758))
#define SOC_CORE_CPU_CRGM_FCG_CFG17_MIDDLE_ADDR(base) ((base) + (0x75C))
#define SOC_CORE_CPU_CRGM_FCG_CFG18_MIDDLE_ADDR(base) ((base) + (0x760))
#define SOC_CORE_CPU_CRGM_FCG_CFG19_MIDDLE_ADDR(base) ((base) + (0x764))
#define SOC_CORE_CPU_CRGM_FCG_CFG20_MIDDLE_ADDR(base) ((base) + (0x768))
#define SOC_CORE_CPU_CRGM_FCG_CFG21_MIDDLE_ADDR(base) ((base) + (0x76C))
#define SOC_CORE_CPU_CRGM_FCG_CFG22_MIDDLE_ADDR(base) ((base) + (0x770))
#define SOC_CORE_CPU_CRGM_FCG_CFG23_MIDDLE_ADDR(base) ((base) + (0x774))
#define SOC_CORE_CPU_CRGM_FCG_CFG24_MIDDLE_ADDR(base) ((base) + (0x778))
#define SOC_CORE_CPU_CRGM_FCG_CFG25_MIDDLE_ADDR(base) ((base) + (0x77C))
#define SOC_CORE_CPU_CRGM_FCG_CFG26_MIDDLE_ADDR(base) ((base) + (0x780))
#define SOC_CORE_CPU_CRGM_FCG_CFG27_MIDDLE_ADDR(base) ((base) + (0x784))
#define SOC_CORE_CPU_CRGM_FCG_STAT0_MIDDLE_ADDR(base) ((base) + (0x790))
#define SOC_CORE_CPU_CRGM_FCG_STAT1_MIDDLE_ADDR(base) ((base) + (0x794))
#define SOC_CORE_CPU_CRGM_FCG_STAT2_MIDDLE_ADDR(base) ((base) + (0x798))
#define SOC_CORE_CPU_CRGM_FCG_STAT3_MIDDLE_ADDR(base) ((base) + (0x79C))
#define SOC_CORE_CPU_CRGM_FCG_STAT4_MIDDLE_ADDR(base) ((base) + (0x7A0))
#define SOC_CORE_CPU_CRGM_FCG_STAT5_MIDDLE_ADDR(base) ((base) + (0x7A4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_middle : 1;
        unsigned int gt_clk_pim_middle : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int gt_clk_fcg_freq_ctrl_middle : 1;
        unsigned int gt_pclk_fcg_middle : 1;
        unsigned int gt_clk_fdcs_mon_middle : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
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
        unsigned int reserved_16 : 7;
    } reg;
} SOC_CORE_CPU_CRGM_PEREN0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_sscg_middle_START (0)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_sscg_middle_END (0)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_pim_middle_START (1)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_pim_middle_END (1)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fdcs_xpu_ctrl_middle_START (2)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fdcs_xpu_ctrl_middle_END (2)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_freq_ctrl_middle_START (3)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_freq_ctrl_middle_END (3)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_pclk_fcg_middle_START (4)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_pclk_fcg_middle_END (4)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fdcs_mon_middle_START (5)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fdcs_mon_middle_END (5)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGM_PEREN0_gt_clk_fcg_ref_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_middle : 1;
        unsigned int gt_clk_pim_middle : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int gt_clk_fcg_freq_ctrl_middle : 1;
        unsigned int gt_pclk_fcg_middle : 1;
        unsigned int gt_clk_fdcs_mon_middle : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
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
        unsigned int reserved_16 : 7;
    } reg;
} SOC_CORE_CPU_CRGM_PERDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_sscg_middle_START (0)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_sscg_middle_END (0)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_pim_middle_START (1)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_pim_middle_END (1)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fdcs_xpu_ctrl_middle_START (2)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fdcs_xpu_ctrl_middle_END (2)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_freq_ctrl_middle_START (3)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_freq_ctrl_middle_END (3)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_pclk_fcg_middle_START (4)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_pclk_fcg_middle_END (4)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fdcs_mon_middle_START (5)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fdcs_mon_middle_END (5)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGM_PERDIS0_gt_clk_fcg_ref_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_middle : 1;
        unsigned int gt_clk_pim_middle : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int gt_clk_fcg_freq_ctrl_middle : 1;
        unsigned int gt_pclk_fcg_middle : 1;
        unsigned int gt_clk_fdcs_mon_middle : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
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
        unsigned int reserved_16 : 7;
    } reg;
} SOC_CORE_CPU_CRGM_PERCLKEN0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_sscg_middle_START (0)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_sscg_middle_END (0)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_pim_middle_START (1)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_pim_middle_END (1)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_middle_START (2)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_middle_END (2)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_freq_ctrl_middle_START (3)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_freq_ctrl_middle_END (3)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_pclk_fcg_middle_START (4)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_pclk_fcg_middle_END (4)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fdcs_mon_middle_START (5)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fdcs_mon_middle_END (5)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGM_PERCLKEN0_gt_clk_fcg_ref_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_fcg_sscg_middle : 1;
        unsigned int st_clk_pim_middle : 1;
        unsigned int st_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int st_clk_fcg_freq_ctrl_middle : 1;
        unsigned int st_pclk_fcg_middle : 1;
        unsigned int st_clk_fdcs_mon_middle : 1;
        unsigned int st_pclk_onsys_avs_cpu : 1;
        unsigned int st_clk_fcg_cnt : 1;
        unsigned int st_clk_fcg_ref : 1;
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
        unsigned int st_clk_fcg_pre : 1;
        unsigned int reserved_15 : 7;
    } reg;
} SOC_CORE_CPU_CRGM_PERSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_sscg_middle_START (0)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_sscg_middle_END (0)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_pim_middle_START (1)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_pim_middle_END (1)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fdcs_xpu_ctrl_middle_START (2)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fdcs_xpu_ctrl_middle_END (2)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_freq_ctrl_middle_START (3)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_freq_ctrl_middle_END (3)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_pclk_fcg_middle_START (4)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_pclk_fcg_middle_END (4)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fdcs_mon_middle_START (5)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fdcs_mon_middle_END (5)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_pre_START (24)
#define SOC_CORE_CPU_CRGM_PERSTAT0_st_clk_fcg_pre_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_mon_middle : 1;
        unsigned int ip_prst_fcg_middle : 1;
        unsigned int ip_rst_fcg_freq_ctrl_middle : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_middle : 1;
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
    } reg;
} SOC_CORE_CPU_CRGM_PERRSTEN0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_middle_START (0)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_middle_END (0)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fdcs_mon_middle_START (1)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fdcs_mon_middle_END (1)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_prst_fcg_middle_START (2)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_prst_fcg_middle_END (2)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fcg_freq_ctrl_middle_START (3)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fcg_freq_ctrl_middle_END (3)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fcg_freq_cnt_middle_START (5)
#define SOC_CORE_CPU_CRGM_PERRSTEN0_ip_rst_fcg_freq_cnt_middle_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_mon_middle : 1;
        unsigned int ip_prst_fcg_middle : 1;
        unsigned int ip_rst_fcg_freq_ctrl_middle : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_middle : 1;
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
    } reg;
} SOC_CORE_CPU_CRGM_PERRSTDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_middle_START (0)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_middle_END (0)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fdcs_mon_middle_START (1)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fdcs_mon_middle_END (1)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_prst_fcg_middle_START (2)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_prst_fcg_middle_END (2)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fcg_freq_ctrl_middle_START (3)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fcg_freq_ctrl_middle_END (3)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fcg_freq_cnt_middle_START (5)
#define SOC_CORE_CPU_CRGM_PERRSTDIS0_ip_rst_fcg_freq_cnt_middle_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_mon_middle : 1;
        unsigned int ip_prst_fcg_middle : 1;
        unsigned int ip_rst_fcg_freq_ctrl_middle : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_middle : 1;
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
    } reg;
} SOC_CORE_CPU_CRGM_PERRSTSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_middle_START (0)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_middle_END (0)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fdcs_mon_middle_START (1)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fdcs_mon_middle_END (1)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_prst_fcg_middle_START (2)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_prst_fcg_middle_END (2)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_middle_START (3)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_middle_END (3)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fcg_freq_cnt_middle_START (5)
#define SOC_CORE_CPU_CRGM_PERRSTSTAT0_ip_rst_fcg_freq_cnt_middle_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_fcg_middle_tp : 1;
        unsigned int div_clk_fcg_middle_tp : 6;
        unsigned int temp_code_bypass : 1;
        unsigned int temp_code_enable : 1;
        unsigned int reserved : 7;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_CLKDIV0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_CLKDIV0_sc_gt_clk_fcg_middle_tp_START (0)
#define SOC_CORE_CPU_CRGM_CLKDIV0_sc_gt_clk_fcg_middle_tp_END (0)
#define SOC_CORE_CPU_CRGM_CLKDIV0_div_clk_fcg_middle_tp_START (1)
#define SOC_CORE_CPU_CRGM_CLKDIV0_div_clk_fcg_middle_tp_END (6)
#define SOC_CORE_CPU_CRGM_CLKDIV0_temp_code_bypass_START (7)
#define SOC_CORE_CPU_CRGM_CLKDIV0_temp_code_bypass_END (7)
#define SOC_CORE_CPU_CRGM_CLKDIV0_temp_code_enable_START (8)
#define SOC_CORE_CPU_CRGM_CLKDIV0_temp_code_enable_END (8)
#define SOC_CORE_CPU_CRGM_CLKDIV0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_CLKDIV0_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_pim_drop_en_bypass_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_pim_drop_en_bypass_END (0)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_pim_peaklow_en_bypass_START (1)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_pim_peaklow_en_bypass_END (1)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_pim_drop_update_bypass_START (2)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_pim_drop_update_bypass_END (2)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_cnt_thr_START (3)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_cnt_thr_END (6)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_ffc_en_bypass_START (7)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_ffc_en_bypass_END (7)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_ffc_cnt_thr_START (8)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_ffc_cnt_thr_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_FDCS_XPU_CFG_MIDDLE_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_pcr_trig_vdm_en_START (0)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_pcr_trig_vdm_en_END (0)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_wfx_bypass_START (1)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_wfx_bypass_END (4)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_l2_idle_div_mod_START (5)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_l2_idle_div_mod_END (5)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_freq_dn_mst_sel_START (6)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_freq_dn_mst_sel_END (6)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_wake_up_mode_START (23)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_wake_up_mode_END (24)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_gt_en_START (26)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_gt_en_END (26)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_vbat_drop_icg_en_START (27)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_vbat_drop_icg_en_END (27)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_vbat_drop_fcg_en_START (28)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_vbat_drop_fcg_en_END (28)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_coreidle_bypass_START (29)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_coreidle_bypass_END (29)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_pcr_fs_icg_en_START (30)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_pcr_fs_icg_en_END (30)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_pcr_fs_fcg_en_START (31)
#define SOC_CORE_CPU_CRGM_FCG_FREQ_CTRL_MIDDLE_pcr_fs_fcg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg_rsv_middle : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG_RSV1_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG_RSV1_fcg_cfg_rsv_middle_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG_RSV1_fcg_cfg_rsv_middle_END (15)
#define SOC_CORE_CPU_CRGM_FCG_CFG_RSV1_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_FCG_CFG_RSV1_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_enable_START (0)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_enable_END (0)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_mode_START (1)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_mode_END (1)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_rate_START (2)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_rate_END (5)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_depth_START (6)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_depth_END (8)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_fast_dis_START (9)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_sscg_fast_dis_END (9)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_SSC_FCG_CFG_MIDDLE_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat_middle : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_STAT0_fcg_stat_middle_START (0)
#define SOC_CORE_CPU_CRGM_FCG_STAT0_fcg_stat_middle_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_cpu_middle0 : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_FCM_CLKEN_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCM_CLKEN_gt_clk_cpu_middle0_START (0)
#define SOC_CORE_CPU_CRGM_FCM_CLKEN_gt_clk_cpu_middle0_END (0)
#define SOC_CORE_CPU_CRGM_FCM_CLKEN_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_FCM_CLKEN_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsv_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_RSV_CFG0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_RSV_CFG0_rsv_cfg0_START (0)
#define SOC_CORE_CPU_CRGM_RSV_CFG0_rsv_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int onsys_avs_cfg_m : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_ONSYS_AVS_CFG_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_CFG_M_onsys_avs_cfg_m_START (0)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_CFG_M_onsys_avs_cfg_m_END (15)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_CFG_M_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_CFG_M_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_monitor_time_m : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGM_ONSYS_AVS_TIME_CFG_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_TIME_CFG_M_apb_monitor_time_m_START (0)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_TIME_CFG_M_apb_monitor_time_m_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vs_th1_m : 16;
        unsigned int apb_vs_th2_m : 16;
    } reg;
} SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_0_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_0_M_apb_vs_th1_m_START (0)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_0_M_apb_vs_th1_m_END (15)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_0_M_apb_vs_th2_m_START (16)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_0_M_apb_vs_th2_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vs_th3_m : 16;
        unsigned int apb_vol_sub_min_m : 8;
        unsigned int apb_vol_add_max_m : 8;
    } reg;
} SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_apb_vs_th3_m_START (0)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_apb_vs_th3_m_END (15)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_apb_vol_sub_min_m_START (16)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_apb_vol_sub_min_m_END (23)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_apb_vol_add_max_m_START (24)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VS_TH_1_M_apb_vol_add_max_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vol_cfg1_m : 8;
        unsigned int apb_vol_cfg2_m : 8;
        unsigned int apb_vol_cfg3_m : 8;
        unsigned int apb_vol_cfg4_m : 8;
    } reg;
} SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg1_m_START (0)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg1_m_END (7)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg2_m_START (8)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg2_m_END (15)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg3_m_START (16)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg3_m_END (23)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg4_m_START (24)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_CFG_M_apb_vol_cfg4_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vol_idx_m : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_IDX_UNION;
#endif
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_IDX_apb_vol_idx_m_START (0)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_VOL_IDX_apb_vol_idx_m_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_cur_stat_m : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int apb_vol_sub_flag_m : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int apb_cnt_us : 8;
        unsigned int reserved_6 : 12;
    } reg;
} SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_UNION;
#endif
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_apb_cur_stat_m_START (0)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_apb_cur_stat_m_END (1)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_apb_vol_sub_flag_m_START (8)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_apb_vol_sub_flag_m_END (8)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_apb_cnt_us_START (12)
#define SOC_CORE_CPU_CRGM_ONSYS_AVS_APB_READ_apb_cnt_us_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int apb_onsys_enable_m : 1;
        unsigned int reserved_1 : 14;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_CORE_CPU_CRGM_APB_ONSYS_ENABLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_APB_ONSYS_ENABLE_apb_onsys_enable_m_START (1)
#define SOC_CORE_CPU_CRGM_APB_ONSYS_ENABLE_apb_onsys_enable_m_END (1)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_coef_cfg0_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_coef_cfg0_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_coef_cfg1_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_coef_cfg1_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_coef_cfg2_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG0_M_coef_cfg2_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_coef_cfg3_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_coef_cfg3_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_coef_cfg4_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_coef_cfg4_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_coef_cfg5_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG1_M_coef_cfg5_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_coef_cfg6_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_coef_cfg6_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_coef_cfg7_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_coef_cfg7_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_coef_cfg8_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG2_M_coef_cfg8_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_coef_cfg9_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_coef_cfg9_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_coef_cfg10_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_coef_cfg10_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_coef_cfg11_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG3_M_coef_cfg11_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_coef_cfg12_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_coef_cfg12_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_coef_cfg13_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_coef_cfg13_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_coef_cfg14_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG4_M_coef_cfg14_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_coef_cfg15_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_coef_cfg15_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_coef_cfg16_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_coef_cfg16_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_coef_cfg17_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG5_M_coef_cfg17_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_coef_cfg18_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_coef_cfg18_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_coef_cfg19_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_coef_cfg19_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_coef_cfg20_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG6_M_coef_cfg20_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_coef_cfg21_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_coef_cfg21_END (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_coef_cfg22_START (10)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_coef_cfg22_END (19)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_coef_cfg23_START (20)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG7_M_coef_cfg23_END (29)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w0_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w0_END (7)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w1_START (8)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w1_END (15)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w2_START (16)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w2_END (23)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w3_START (24)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG8_M_coef_w3_END (31)
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
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG9_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG9_M_coef_w4_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG9_M_coef_w4_END (7)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG9_M_coef_m_START (8)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG9_M_coef_m_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int accu_fd_thr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG10_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG10_M_accu_fd_thr_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG10_M_accu_fd_thr_END (24)
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
        unsigned int fdcs_onsys_cfg11_m : 9;
    } reg;
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_max_thr_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_max_thr_END (8)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_min_thr_START (9)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_min_thr_END (17)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_add_START (18)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_add_END (21)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_add_bypass_START (22)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_vol_add_bypass_END (22)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_fdcs_onsys_cfg11_m_START (23)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG11_M_fdcs_onsys_cfg11_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_cfg12_m : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG12_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG12_M_fdcs_onsys_cfg12_m_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG12_M_fdcs_onsys_cfg12_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_cfg13_m : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG13_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG13_M_fdcs_onsys_cfg13_m_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_CFG13_M_fdcs_onsys_cfg13_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FDCS_ONSYS_STAT_M_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_STAT_M_fdcs_onsys_stat0_START (0)
#define SOC_CORE_CPU_CRGM_FDCS_ONSYS_STAT_M_fdcs_onsys_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_middle_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 27;
    } reg;
} SOC_CORE_CPU_CRGM_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_IPCLKRST_BYPASS0_fcg_middle_clkrst_bypass_START (0)
#define SOC_CORE_CPU_CRGM_IPCLKRST_BYPASS0_fcg_middle_clkrst_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_drop_en_middle : 1;
        unsigned int pim_ost_en_middle : 1;
        unsigned int pim_peaklow_en_middle : 1;
        unsigned int pim_debug_middle : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_PIM_CTRL0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_drop_en_middle_START (0)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_drop_en_middle_END (0)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_ost_en_middle_START (1)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_ost_en_middle_END (1)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_peaklow_en_middle_START (2)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_peaklow_en_middle_END (2)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_debug_middle_START (3)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_pim_debug_middle_END (3)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_PIM_CTRL0_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGM_PIM_CFG0_MIDDLE_UNION;
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
} SOC_CORE_CPU_CRGM_PIM_CFG1_MIDDLE_UNION;
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
} SOC_CORE_CPU_CRGM_PIM_CFG2_MIDDLE_UNION;
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
} SOC_CORE_CPU_CRGM_PIM_CFG3_MIDDLE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_peaklow_code_middle : 16;
        unsigned int pim_peaklow_ready_middle : 1;
        unsigned int pim_flag_ready_middle : 1;
        unsigned int pim_flag_l_middle : 1;
        unsigned int pim_flag_h_middle : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_PIM_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_peaklow_code_middle_START (0)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_peaklow_code_middle_END (15)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_peaklow_ready_middle_START (16)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_peaklow_ready_middle_END (16)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_flag_ready_middle_START (17)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_flag_ready_middle_END (17)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_flag_l_middle_START (18)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_flag_l_middle_END (18)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_flag_h_middle_START (19)
#define SOC_CORE_CPU_CRGM_PIM_STAT0_pim_flag_h_middle_END (19)
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
} SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_cnt_timer_en_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_cnt_timer_en_END (0)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_accu_fd_en_START (1)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_accu_fd_en_END (1)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_peaklow_en_START (2)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_peaklow_en_END (2)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_clear_all_en_START (3)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_clear_all_en_END (3)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_cnt_timer_hd_en_START (4)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_cnt_timer_hd_en_END (4)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_hw_fsm_mode_START (5)
#define SOC_CORE_CPU_CRGM_MON_CFG0_MIDDLE_hw_fsm_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG1_MIDDLE_read_lock_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG1_MIDDLE_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG2_MIDDLE_bin_peaklow_en_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG2_MIDDLE_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG3_MIDDLE_vth0_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG3_MIDDLE_vth0_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG3_MIDDLE_vth1_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG3_MIDDLE_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG4_MIDDLE_vth2_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG4_MIDDLE_vth2_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG4_MIDDLE_vth3_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG4_MIDDLE_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG5_MIDDLE_vth4_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG5_MIDDLE_vth4_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG5_MIDDLE_vth5_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG5_MIDDLE_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG6_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG6_MIDDLE_vth6_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG6_MIDDLE_vth6_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG6_MIDDLE_vth7_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG6_MIDDLE_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG7_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG7_MIDDLE_vth8_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG7_MIDDLE_vth8_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG7_MIDDLE_vth9_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG7_MIDDLE_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG8_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG8_MIDDLE_vth10_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG8_MIDDLE_vth10_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG8_MIDDLE_vth11_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG8_MIDDLE_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG9_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG9_MIDDLE_vth12_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG9_MIDDLE_vth12_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG9_MIDDLE_vth13_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG9_MIDDLE_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG10_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG10_MIDDLE_vth14_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG10_MIDDLE_vth14_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG10_MIDDLE_vth15_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG10_MIDDLE_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG11_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG11_MIDDLE_vth16_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG11_MIDDLE_vth16_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG11_MIDDLE_vth17_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG11_MIDDLE_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG12_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG12_MIDDLE_vth18_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG12_MIDDLE_vth18_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG12_MIDDLE_vth19_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG12_MIDDLE_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG13_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG13_MIDDLE_vth20_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG13_MIDDLE_vth20_peaklow_END (15)
#define SOC_CORE_CPU_CRGM_MON_CFG13_MIDDLE_vth21_peaklow_START (16)
#define SOC_CORE_CPU_CRGM_MON_CFG13_MIDDLE_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG14_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG14_MIDDLE_vth22_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG14_MIDDLE_vth22_peaklow_END (15)
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
} SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_cnt_timer_hd_th_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_cnt_timer_hd_th_END (21)
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_read_lock_mode_START (30)
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_read_lock_mode_END (30)
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_sel_peaklow_vth_START (31)
#define SOC_CORE_CPU_CRGM_MON_CFG15_MIDDLE_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGM_MON_CFG16_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_CFG16_MIDDLE_pim_peaklow_vth_START (0)
#define SOC_CORE_CPU_CRGM_MON_CFG16_MIDDLE_pim_peaklow_vth_END (15)
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
} SOC_CORE_CPU_CRGM_MON_STAT0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT0_MIDDLE_cnt_timer_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT0_MIDDLE_cnt_timer_END (21)
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
} SOC_CORE_CPU_CRGM_MON_STAT1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT1_MIDDLE_accu_fd_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT1_MIDDLE_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT2_MIDDLE_bin0_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT2_MIDDLE_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT3_MIDDLE_bin1_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT3_MIDDLE_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT4_MIDDLE_bin2_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT4_MIDDLE_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT5_MIDDLE_bin3_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT5_MIDDLE_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT6_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT6_MIDDLE_bin4_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT6_MIDDLE_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT7_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT7_MIDDLE_bin5_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT7_MIDDLE_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT8_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT8_MIDDLE_bin6_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT8_MIDDLE_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT9_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT9_MIDDLE_bin7_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT9_MIDDLE_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT10_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT10_MIDDLE_bin8_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT10_MIDDLE_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT11_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT11_MIDDLE_bin9_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT11_MIDDLE_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT12_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT12_MIDDLE_bin10_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT12_MIDDLE_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT13_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT13_MIDDLE_bin11_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT13_MIDDLE_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT14_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT14_MIDDLE_bin12_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT14_MIDDLE_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT15_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT15_MIDDLE_bin13_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT15_MIDDLE_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT16_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT16_MIDDLE_bin14_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT16_MIDDLE_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT17_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT17_MIDDLE_bin15_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT17_MIDDLE_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT18_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT18_MIDDLE_bin16_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT18_MIDDLE_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT19_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT19_MIDDLE_bin17_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT19_MIDDLE_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT20_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT20_MIDDLE_bin18_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT20_MIDDLE_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT21_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT21_MIDDLE_bin19_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT21_MIDDLE_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT22_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT22_MIDDLE_bin20_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT22_MIDDLE_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT23_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT23_MIDDLE_bin21_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT23_MIDDLE_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT24_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT24_MIDDLE_bin22_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT24_MIDDLE_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGM_MON_STAT25_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_MON_STAT25_MIDDLE_bin23_peaklow_START (0)
#define SOC_CORE_CPU_CRGM_MON_STAT25_MIDDLE_bin23_peaklow_END (19)
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
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_CLKDIV2_UNION;
#endif
#define SOC_CORE_CPU_CRGM_CLKDIV2_sc_gt_clk_fcg_ref_START (0)
#define SOC_CORE_CPU_CRGM_CLKDIV2_sc_gt_clk_fcg_ref_END (0)
#define SOC_CORE_CPU_CRGM_CLKDIV2_sc_gt_clk_fcg_cnt_START (1)
#define SOC_CORE_CPU_CRGM_CLKDIV2_sc_gt_clk_fcg_cnt_END (1)
#define SOC_CORE_CPU_CRGM_CLKDIV2_div_clk_fcg_cnt_START (2)
#define SOC_CORE_CPU_CRGM_CLKDIV2_div_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGM_CLKDIV2_div_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGM_CLKDIV2_div_clk_fcg_ref_END (13)
#define SOC_CORE_CPU_CRGM_CLKDIV2_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_fcg_cfg_gt_bypass : 1;
        unsigned int sc_fcg_cfg_gt_pre_bypass : 1;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_CLKDIV3_UNION;
#endif
#define SOC_CORE_CPU_CRGM_CLKDIV3_sc_fcg_cfg_gt_bypass_START (0)
#define SOC_CORE_CPU_CRGM_CLKDIV3_sc_fcg_cfg_gt_bypass_END (0)
#define SOC_CORE_CPU_CRGM_CLKDIV3_sc_fcg_cfg_gt_pre_bypass_START (1)
#define SOC_CORE_CPU_CRGM_CLKDIV3_sc_fcg_cfg_gt_pre_bypass_END (1)
#define SOC_CORE_CPU_CRGM_CLKDIV3_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_CLKDIV3_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_fcg_freq_en_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_fcg_freq_en_END (0)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_fcg_freq_clr_START (1)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_fcg_freq_clr_END (1)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_fcg_freq_lock_START (2)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_fcg_freq_lock_END (2)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cnt_set : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CNT_CTRL1_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL1_fcg_cnt_set_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL1_fcg_cnt_set_END (15)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL1_bitmasken_START (16)
#define SOC_CORE_CPU_CRGM_FCG_CNT_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_freq_cnt_lock : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CNT_STATE0_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CNT_STATE0_fcg_freq_cnt_lock_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CNT_STATE0_fcg_freq_cnt_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_ANA_CFG0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG0_MIDDLE_d2a_fcg_ana_cfg0_START (0)
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG0_MIDDLE_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_ANA_CFG1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG1_MIDDLE_d2a_fcg_ana_cfg1_START (0)
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG1_MIDDLE_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_ANA_CFG2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG2_MIDDLE_d2a_fcg_ana_cfg2_START (0)
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG2_MIDDLE_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_ANA_CFG3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG3_MIDDLE_d2a_fcg_ana_cfg3_START (0)
#define SOC_CORE_CPU_CRGM_FCG_ANA_CFG3_MIDDLE_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG0_MIDDLE_fcg_cfg0_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG0_MIDDLE_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG1_MIDDLE_fcg_cfg1_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG1_MIDDLE_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG2_MIDDLE_fcg_cfg2_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG2_MIDDLE_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG3_MIDDLE_fcg_cfg3_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG3_MIDDLE_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG4_MIDDLE_fcg_cfg4_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG4_MIDDLE_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG5_MIDDLE_fcg_cfg5_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG5_MIDDLE_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG6_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG6_MIDDLE_fcg_cfg6_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG6_MIDDLE_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG7_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG7_MIDDLE_fcg_cfg7_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG7_MIDDLE_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG8_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG8_MIDDLE_fcg_cfg8_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG8_MIDDLE_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG9_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG9_MIDDLE_fcg_cfg9_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG9_MIDDLE_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG10_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG10_MIDDLE_fcg_cfg10_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG10_MIDDLE_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG11_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG11_MIDDLE_fcg_cfg11_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG11_MIDDLE_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG12_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG12_MIDDLE_fcg_cfg12_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG12_MIDDLE_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG13_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG13_MIDDLE_fcg_cfg13_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG13_MIDDLE_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG14_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG14_MIDDLE_fcg_cfg14_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG14_MIDDLE_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG15_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG15_MIDDLE_fcg_cfg15_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG15_MIDDLE_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG16_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG16_MIDDLE_fcg_cfg16_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG16_MIDDLE_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG17_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG17_MIDDLE_fcg_cfg17_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG17_MIDDLE_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG18_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG18_MIDDLE_fcg_cfg18_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG18_MIDDLE_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG19_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG19_MIDDLE_fcg_cfg19_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG19_MIDDLE_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG20_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG20_MIDDLE_fcg_cfg20_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG20_MIDDLE_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG21_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG21_MIDDLE_fcg_cfg21_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG21_MIDDLE_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG22_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG22_MIDDLE_fcg_cfg22_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG22_MIDDLE_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG23_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG23_MIDDLE_fcg_cfg23_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG23_MIDDLE_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG24_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG24_MIDDLE_fcg_cfg24_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG24_MIDDLE_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG25_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG25_MIDDLE_fcg_cfg25_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG25_MIDDLE_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG26_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG26_MIDDLE_fcg_cfg26_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG26_MIDDLE_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_CFG27_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_CFG27_MIDDLE_fcg_cfg27_START (0)
#define SOC_CORE_CPU_CRGM_FCG_CFG27_MIDDLE_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_STAT0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_STAT0_MIDDLE_fcg_stat0_START (0)
#define SOC_CORE_CPU_CRGM_FCG_STAT0_MIDDLE_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_STAT1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_STAT1_MIDDLE_fcg_stat1_START (0)
#define SOC_CORE_CPU_CRGM_FCG_STAT1_MIDDLE_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_STAT2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_STAT2_MIDDLE_fcg_stat2_START (0)
#define SOC_CORE_CPU_CRGM_FCG_STAT2_MIDDLE_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_STAT3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_STAT3_MIDDLE_fcg_stat3_START (0)
#define SOC_CORE_CPU_CRGM_FCG_STAT3_MIDDLE_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_STAT4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_STAT4_MIDDLE_fcg_stat4_START (0)
#define SOC_CORE_CPU_CRGM_FCG_STAT4_MIDDLE_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_CORE_CPU_CRGM_FCG_STAT5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRGM_FCG_STAT5_MIDDLE_fcg_stat5_START (0)
#define SOC_CORE_CPU_CRGM_FCG_STAT5_MIDDLE_fcg_stat5_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
