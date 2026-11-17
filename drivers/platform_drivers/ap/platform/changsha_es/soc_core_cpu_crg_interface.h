#ifndef __SOC_CORE_CPU_CRG_INTERFACE_H__
#define __SOC_CORE_CPU_CRG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CORE_CPU_CRG_PEREN0_ADDR(base) (base)
#define SOC_CORE_CPU_CRG_PERDIS0_ADDR(base) ((base) + 0x004UL)
#define SOC_CORE_CPU_CRG_PERCLKEN0_ADDR(base) ((base) + 0x008UL)
#define SOC_CORE_CPU_CRG_PERSTAT0_ADDR(base) ((base) + 0x00CUL)
#define SOC_CORE_CPU_CRG_PEREN1_ADDR(base) ((base) + 0x010UL)
#define SOC_CORE_CPU_CRG_PERDIS1_ADDR(base) ((base) + 0x014UL)
#define SOC_CORE_CPU_CRG_PERCLKEN1_ADDR(base) ((base) + 0x018UL)
#define SOC_CORE_CPU_CRG_PERSTAT1_ADDR(base) ((base) + 0x01CUL)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ADDR(base) ((base) + 0x040UL)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ADDR(base) ((base) + 0x044UL)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ADDR(base) ((base) + 0x048UL)
#define SOC_CORE_CPU_CRG_PERI_STAT0_ADDR(base) ((base) + 0x060UL)
#define SOC_CORE_CPU_CRG_PERI_STAT1_ADDR(base) ((base) + 0x064UL)
#define SOC_CORE_CPU_CRG_CLKDIV0_ADDR(base) ((base) + 0x080UL)
#define SOC_CORE_CPU_CRG_CLKDIV1_ADDR(base) ((base) + 0x084UL)
#define SOC_CORE_CPU_CRG_CLKDIV2_ADDR(base) ((base) + 0x088UL)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_ADDR(base) ((base) + 0x1B0UL)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_ADDR(base) ((base) + 0x1B4UL)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_ADDR(base) ((base) + 0x1B8UL)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_ADDR(base) ((base) + 0x1C0UL)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_ADDR(base) ((base) + 0x1C4UL)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_ADDR(base) ((base) + 0x1C8UL)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV0_ADDR(base) ((base) + 0x1D0UL)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV1_ADDR(base) ((base) + 0x1D4UL)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV2_ADDR(base) ((base) + 0x1D8UL)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_ADDR(base) ((base) + 0x1ECUL)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_ADDR(base) ((base) + 0x1F0UL)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_ADDR(base) ((base) + 0x1F4UL)
#define SOC_CORE_CPU_CRG_FCG_STAT0_ADDR(base) ((base) + 0x1F8UL)
#define SOC_CORE_CPU_CRG_FCG_STAT1_ADDR(base) ((base) + 0x1FCUL)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_ADDR(base) ((base) + 0x200UL)
#define SOC_CORE_CPU_CRG_RSV_CFG0_ADDR(base) ((base) + 0x300UL)
#define SOC_CORE_CPU_CRG_RSV_CFG1_ADDR(base) ((base) + 0x304UL)
#define SOC_CORE_CPU_CRG_RSV_CFG2_ADDR(base) ((base) + 0x308UL)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_ADDR(base) ((base) + 0x400UL)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_ADDR(base) ((base) + 0x404UL)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_ADDR(base) ((base) + 0x408UL)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_ADDR(base) ((base) + 0x40cUL)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_ADDR(base) ((base) + 0x410UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_A_ADDR(base) ((base) + 0x4F4UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_B_ADDR(base) ((base) + 0x4F8UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_C_ADDR(base) ((base) + 0x4FCUL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_AB_ADDR(base) ((base) + 0x500UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_A_ADDR(base) ((base) + 0x504UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_ADDR(base) ((base) + 0x508UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_ADDR(base) ((base) + 0x50CUL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_ADDR(base) ((base) + 0x510UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_ADDR(base) ((base) + 0x514UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + 0x51CUL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_ADDR(base) ((base) + 0x520UL)
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_ADDR(base) ((base) + 0x524UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_B_ADDR(base) ((base) + 0x528UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_ADDR(base) ((base) + 0x52CUL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_C_ADDR(base) ((base) + 0x530UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_ADDR(base) ((base) + 0x534UL)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_CD_ADDR(base) ((base) + 0x540UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_ADDR(base) ((base) + 0x548UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_ADDR(base) ((base) + 0x54CUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_ADDR(base) ((base) + 0x550UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_ADDR(base) ((base) + 0x554UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_ADDR(base) ((base) + 0x558UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_ADDR(base) ((base) + 0x55CUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_ADDR(base) ((base) + 0x560UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_ADDR(base) ((base) + 0x564UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_ADDR(base) ((base) + 0x568UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_A_ADDR(base) ((base) + 0x56CUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_A_ADDR(base) ((base) + 0x570UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_ADDR(base) ((base) + 0x574UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_A_ADDR(base) ((base) + 0x578UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_A_ADDR(base) ((base) + 0x57CUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_ADDR(base) ((base) + 0x580UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_ADDR(base) ((base) + 0x584UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_ADDR(base) ((base) + 0x588UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_ADDR(base) ((base) + 0x58CUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_ADDR(base) ((base) + 0x590UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_ADDR(base) ((base) + 0x594UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_ADDR(base) ((base) + 0x598UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_ADDR(base) ((base) + 0x59CUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_ADDR(base) ((base) + 0x5A0UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_B_ADDR(base) ((base) + 0x5A4UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_B_ADDR(base) ((base) + 0x5A8UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_ADDR(base) ((base) + 0x5ACUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_B_ADDR(base) ((base) + 0x5B0UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_B_ADDR(base) ((base) + 0x5B4UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_ADDR(base) ((base) + 0x5B8UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_ADDR(base) ((base) + 0x5BCUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_ADDR(base) ((base) + 0x5C0UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_ADDR(base) ((base) + 0x5C4UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_ADDR(base) ((base) + 0x5C8UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_ADDR(base) ((base) + 0x5CCUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_ADDR(base) ((base) + 0x5D0UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_ADDR(base) ((base) + 0x5D4UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_ADDR(base) ((base) + 0x5D8UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_C_ADDR(base) ((base) + 0x5DCUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_C_ADDR(base) ((base) + 0x5E0UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_ADDR(base) ((base) + 0x5E4UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_C_ADDR(base) ((base) + 0x5E8UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_C_ADDR(base) ((base) + 0x5ECUL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_A_ADDR(base) ((base) + 0x5F0UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_B_ADDR(base) ((base) + 0x5F4UL)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_C_ADDR(base) ((base) + 0x5F8UL)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_ADDR(base) ((base) + 0x600UL)
#define SOC_CORE_CPU_CRG_PIM_CFG0_MIDDLE_ADDR(base) ((base) + 0x604UL)
#define SOC_CORE_CPU_CRG_PIM_CFG1_MIDDLE_ADDR(base) ((base) + 0x608UL)
#define SOC_CORE_CPU_CRG_PIM_CFG2_MIDDLE_ADDR(base) ((base) + 0x60CUL)
#define SOC_CORE_CPU_CRG_PIM_CFG3_MIDDLE_ADDR(base) ((base) + 0x610UL)
#define SOC_CORE_CPU_CRG_PIM_CFG0_BIG_ADDR(base) ((base) + 0x614UL)
#define SOC_CORE_CPU_CRG_PIM_CFG1_BIG_ADDR(base) ((base) + 0x618UL)
#define SOC_CORE_CPU_CRG_PIM_CFG2_BIG_ADDR(base) ((base) + 0x61CUL)
#define SOC_CORE_CPU_CRG_PIM_CFG3_BIG_ADDR(base) ((base) + 0x620UL)
#define SOC_CORE_CPU_CRG_PIM_CFG0_LITTLE_ADDR(base) ((base) + 0x624UL)
#define SOC_CORE_CPU_CRG_PIM_CFG1_LITTLE_ADDR(base) ((base) + 0x628UL)
#define SOC_CORE_CPU_CRG_PIM_CFG2_LITTLE_ADDR(base) ((base) + 0x62CUL)
#define SOC_CORE_CPU_CRG_PIM_CFG3_LITTLE_ADDR(base) ((base) + 0x630UL)
#define SOC_CORE_CPU_CRG_PIM_STAT0_ADDR(base) ((base) + 0x634UL)
#define SOC_CORE_CPU_CRG_PIM_STAT1_ADDR(base) ((base) + 0x638UL)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_ADDR(base) ((base) + 0x650UL)
#define SOC_CORE_CPU_CRG_MON_CFG1_MIDDLE_ADDR(base) ((base) + 0x654UL)
#define SOC_CORE_CPU_CRG_MON_CFG2_MIDDLE_ADDR(base) ((base) + 0x658UL)
#define SOC_CORE_CPU_CRG_MON_CFG3_MIDDLE_ADDR(base) ((base) + 0x65CUL)
#define SOC_CORE_CPU_CRG_MON_CFG4_MIDDLE_ADDR(base) ((base) + 0x660UL)
#define SOC_CORE_CPU_CRG_MON_CFG5_MIDDLE_ADDR(base) ((base) + 0x664UL)
#define SOC_CORE_CPU_CRG_MON_CFG6_MIDDLE_ADDR(base) ((base) + 0x668UL)
#define SOC_CORE_CPU_CRG_MON_CFG7_MIDDLE_ADDR(base) ((base) + 0x66CUL)
#define SOC_CORE_CPU_CRG_MON_CFG8_MIDDLE_ADDR(base) ((base) + 0x670UL)
#define SOC_CORE_CPU_CRG_MON_CFG9_MIDDLE_ADDR(base) ((base) + 0x674UL)
#define SOC_CORE_CPU_CRG_MON_CFG10_MIDDLE_ADDR(base) ((base) + 0x678UL)
#define SOC_CORE_CPU_CRG_MON_CFG11_MIDDLE_ADDR(base) ((base) + 0x67CUL)
#define SOC_CORE_CPU_CRG_MON_CFG12_MIDDLE_ADDR(base) ((base) + 0x680UL)
#define SOC_CORE_CPU_CRG_MON_CFG13_MIDDLE_ADDR(base) ((base) + 0x684UL)
#define SOC_CORE_CPU_CRG_MON_CFG14_MIDDLE_ADDR(base) ((base) + 0x688UL)
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_ADDR(base) ((base) + 0x68CUL)
#define SOC_CORE_CPU_CRG_MON_CFG16_MIDDLE_ADDR(base) ((base) + 0x690UL)
#define SOC_CORE_CPU_CRG_MON_STAT0_MIDDLE_ADDR(base) ((base) + 0x694UL)
#define SOC_CORE_CPU_CRG_MON_STAT1_MIDDLE_ADDR(base) ((base) + 0x698UL)
#define SOC_CORE_CPU_CRG_MON_STAT2_MIDDLE_ADDR(base) ((base) + 0x69CUL)
#define SOC_CORE_CPU_CRG_MON_STAT3_MIDDLE_ADDR(base) ((base) + 0x6A0UL)
#define SOC_CORE_CPU_CRG_MON_STAT4_MIDDLE_ADDR(base) ((base) + 0x6A4UL)
#define SOC_CORE_CPU_CRG_MON_STAT5_MIDDLE_ADDR(base) ((base) + 0x6A8UL)
#define SOC_CORE_CPU_CRG_MON_STAT6_MIDDLE_ADDR(base) ((base) + 0x6ACUL)
#define SOC_CORE_CPU_CRG_MON_STAT7_MIDDLE_ADDR(base) ((base) + 0x6B0UL)
#define SOC_CORE_CPU_CRG_MON_STAT8_MIDDLE_ADDR(base) ((base) + 0x6B4UL)
#define SOC_CORE_CPU_CRG_MON_STAT9_MIDDLE_ADDR(base) ((base) + 0x6B8UL)
#define SOC_CORE_CPU_CRG_MON_STAT10_MIDDLE_ADDR(base) ((base) + 0x6BCUL)
#define SOC_CORE_CPU_CRG_MON_STAT11_MIDDLE_ADDR(base) ((base) + 0x6C0UL)
#define SOC_CORE_CPU_CRG_MON_STAT12_MIDDLE_ADDR(base) ((base) + 0x6C4UL)
#define SOC_CORE_CPU_CRG_MON_STAT13_MIDDLE_ADDR(base) ((base) + 0x6C8UL)
#define SOC_CORE_CPU_CRG_MON_STAT14_MIDDLE_ADDR(base) ((base) + 0x6CCUL)
#define SOC_CORE_CPU_CRG_MON_STAT15_MIDDLE_ADDR(base) ((base) + 0x6D0UL)
#define SOC_CORE_CPU_CRG_MON_STAT16_MIDDLE_ADDR(base) ((base) + 0x6D4UL)
#define SOC_CORE_CPU_CRG_MON_STAT17_MIDDLE_ADDR(base) ((base) + 0x6D8UL)
#define SOC_CORE_CPU_CRG_MON_STAT18_MIDDLE_ADDR(base) ((base) + 0x6DCUL)
#define SOC_CORE_CPU_CRG_MON_STAT19_MIDDLE_ADDR(base) ((base) + 0x6E0UL)
#define SOC_CORE_CPU_CRG_MON_STAT20_MIDDLE_ADDR(base) ((base) + 0x6E4UL)
#define SOC_CORE_CPU_CRG_MON_STAT21_MIDDLE_ADDR(base) ((base) + 0x6E8UL)
#define SOC_CORE_CPU_CRG_MON_STAT22_MIDDLE_ADDR(base) ((base) + 0x6ECUL)
#define SOC_CORE_CPU_CRG_MON_STAT23_MIDDLE_ADDR(base) ((base) + 0x6F0UL)
#define SOC_CORE_CPU_CRG_MON_STAT24_MIDDLE_ADDR(base) ((base) + 0x6F4UL)
#define SOC_CORE_CPU_CRG_MON_STAT25_MIDDLE_ADDR(base) ((base) + 0x6F8UL)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_ADDR(base) ((base) + 0x6FCUL)
#define SOC_CORE_CPU_CRG_MON_CFG1_BIG_ADDR(base) ((base) + 0x700UL)
#define SOC_CORE_CPU_CRG_MON_CFG2_BIG_ADDR(base) ((base) + 0x704UL)
#define SOC_CORE_CPU_CRG_MON_CFG3_BIG_ADDR(base) ((base) + 0x708UL)
#define SOC_CORE_CPU_CRG_MON_CFG4_BIG_ADDR(base) ((base) + 0x70CUL)
#define SOC_CORE_CPU_CRG_MON_CFG5_BIG_ADDR(base) ((base) + 0x710UL)
#define SOC_CORE_CPU_CRG_MON_CFG6_BIG_ADDR(base) ((base) + 0x714UL)
#define SOC_CORE_CPU_CRG_MON_CFG7_BIG_ADDR(base) ((base) + 0x718UL)
#define SOC_CORE_CPU_CRG_MON_CFG8_BIG_ADDR(base) ((base) + 0x71CUL)
#define SOC_CORE_CPU_CRG_MON_CFG9_BIG_ADDR(base) ((base) + 0x720UL)
#define SOC_CORE_CPU_CRG_MON_CFG10_BIG_ADDR(base) ((base) + 0x724UL)
#define SOC_CORE_CPU_CRG_MON_CFG11_BIG_ADDR(base) ((base) + 0x728UL)
#define SOC_CORE_CPU_CRG_MON_CFG12_BIG_ADDR(base) ((base) + 0x72CUL)
#define SOC_CORE_CPU_CRG_MON_CFG13_BIG_ADDR(base) ((base) + 0x730UL)
#define SOC_CORE_CPU_CRG_MON_CFG14_BIG_ADDR(base) ((base) + 0x734UL)
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_ADDR(base) ((base) + 0x738UL)
#define SOC_CORE_CPU_CRG_MON_CFG16_BIG_ADDR(base) ((base) + 0x73CUL)
#define SOC_CORE_CPU_CRG_MON_STAT0_BIG_ADDR(base) ((base) + 0x740UL)
#define SOC_CORE_CPU_CRG_MON_STAT1_BIG_ADDR(base) ((base) + 0x744UL)
#define SOC_CORE_CPU_CRG_MON_STAT2_BIG_ADDR(base) ((base) + 0x748UL)
#define SOC_CORE_CPU_CRG_MON_STAT3_BIG_ADDR(base) ((base) + 0x74CUL)
#define SOC_CORE_CPU_CRG_MON_STAT4_BIG_ADDR(base) ((base) + 0x750UL)
#define SOC_CORE_CPU_CRG_MON_STAT5_BIG_ADDR(base) ((base) + 0x754UL)
#define SOC_CORE_CPU_CRG_MON_STAT6_BIG_ADDR(base) ((base) + 0x758UL)
#define SOC_CORE_CPU_CRG_MON_STAT7_BIG_ADDR(base) ((base) + 0x75CUL)
#define SOC_CORE_CPU_CRG_MON_STAT8_BIG_ADDR(base) ((base) + 0x760UL)
#define SOC_CORE_CPU_CRG_MON_STAT9_BIG_ADDR(base) ((base) + 0x764UL)
#define SOC_CORE_CPU_CRG_MON_STAT10_BIG_ADDR(base) ((base) + 0x768UL)
#define SOC_CORE_CPU_CRG_MON_STAT11_BIG_ADDR(base) ((base) + 0x76CUL)
#define SOC_CORE_CPU_CRG_MON_STAT12_BIG_ADDR(base) ((base) + 0x770UL)
#define SOC_CORE_CPU_CRG_MON_STAT13_BIG_ADDR(base) ((base) + 0x774UL)
#define SOC_CORE_CPU_CRG_MON_STAT14_BIG_ADDR(base) ((base) + 0x778UL)
#define SOC_CORE_CPU_CRG_MON_STAT15_BIG_ADDR(base) ((base) + 0x77CUL)
#define SOC_CORE_CPU_CRG_MON_STAT16_BIG_ADDR(base) ((base) + 0x780UL)
#define SOC_CORE_CPU_CRG_MON_STAT17_BIG_ADDR(base) ((base) + 0x784UL)
#define SOC_CORE_CPU_CRG_MON_STAT18_BIG_ADDR(base) ((base) + 0x788UL)
#define SOC_CORE_CPU_CRG_MON_STAT19_BIG_ADDR(base) ((base) + 0x78CUL)
#define SOC_CORE_CPU_CRG_MON_STAT20_BIG_ADDR(base) ((base) + 0x790UL)
#define SOC_CORE_CPU_CRG_MON_STAT21_BIG_ADDR(base) ((base) + 0x794UL)
#define SOC_CORE_CPU_CRG_MON_STAT22_BIG_ADDR(base) ((base) + 0x798UL)
#define SOC_CORE_CPU_CRG_MON_STAT23_BIG_ADDR(base) ((base) + 0x79CUL)
#define SOC_CORE_CPU_CRG_MON_STAT24_BIG_ADDR(base) ((base) + 0x7A0UL)
#define SOC_CORE_CPU_CRG_MON_STAT25_BIG_ADDR(base) ((base) + 0x7A4UL)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_ADDR(base) ((base) + 0x7A8UL)
#define SOC_CORE_CPU_CRG_MON_CFG1_LITTLE_ADDR(base) ((base) + 0x7ACUL)
#define SOC_CORE_CPU_CRG_MON_CFG2_LITTLE_ADDR(base) ((base) + 0x7B0UL)
#define SOC_CORE_CPU_CRG_MON_CFG3_LITTLE_ADDR(base) ((base) + 0x7B4UL)
#define SOC_CORE_CPU_CRG_MON_CFG4_LITTLE_ADDR(base) ((base) + 0x7B8UL)
#define SOC_CORE_CPU_CRG_MON_CFG5_LITTLE_ADDR(base) ((base) + 0x7BCUL)
#define SOC_CORE_CPU_CRG_MON_CFG6_LITTLE_ADDR(base) ((base) + 0x7C0UL)
#define SOC_CORE_CPU_CRG_MON_CFG7_LITTLE_ADDR(base) ((base) + 0x7C4UL)
#define SOC_CORE_CPU_CRG_MON_CFG8_LITTLE_ADDR(base) ((base) + 0x7C8UL)
#define SOC_CORE_CPU_CRG_MON_CFG9_LITTLE_ADDR(base) ((base) + 0x7CCUL)
#define SOC_CORE_CPU_CRG_MON_CFG10_LITTLE_ADDR(base) ((base) + 0x7D0UL)
#define SOC_CORE_CPU_CRG_MON_CFG11_LITTLE_ADDR(base) ((base) + 0x7D4UL)
#define SOC_CORE_CPU_CRG_MON_CFG12_LITTLE_ADDR(base) ((base) + 0x7D8UL)
#define SOC_CORE_CPU_CRG_MON_CFG13_LITTLE_ADDR(base) ((base) + 0x7DCUL)
#define SOC_CORE_CPU_CRG_MON_CFG14_LITTLE_ADDR(base) ((base) + 0x7E0UL)
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_ADDR(base) ((base) + 0x7E4UL)
#define SOC_CORE_CPU_CRG_MON_CFG16_LITTLE_ADDR(base) ((base) + 0x7E8UL)
#define SOC_CORE_CPU_CRG_MON_STAT0_LITTLE_ADDR(base) ((base) + 0x7ECUL)
#define SOC_CORE_CPU_CRG_MON_STAT1_LITTLE_ADDR(base) ((base) + 0x7F0UL)
#define SOC_CORE_CPU_CRG_MON_STAT2_LITTLE_ADDR(base) ((base) + 0x7F4UL)
#define SOC_CORE_CPU_CRG_MON_STAT3_LITTLE_ADDR(base) ((base) + 0x7F8UL)
#define SOC_CORE_CPU_CRG_MON_STAT4_LITTLE_ADDR(base) ((base) + 0x7FCUL)
#define SOC_CORE_CPU_CRG_MON_STAT5_LITTLE_ADDR(base) ((base) + 0x800UL)
#define SOC_CORE_CPU_CRG_MON_STAT6_LITTLE_ADDR(base) ((base) + 0x804UL)
#define SOC_CORE_CPU_CRG_MON_STAT7_LITTLE_ADDR(base) ((base) + 0x808UL)
#define SOC_CORE_CPU_CRG_MON_STAT8_LITTLE_ADDR(base) ((base) + 0x80CUL)
#define SOC_CORE_CPU_CRG_MON_STAT9_LITTLE_ADDR(base) ((base) + 0x810UL)
#define SOC_CORE_CPU_CRG_MON_STAT10_LITTLE_ADDR(base) ((base) + 0x814UL)
#define SOC_CORE_CPU_CRG_MON_STAT11_LITTLE_ADDR(base) ((base) + 0x818UL)
#define SOC_CORE_CPU_CRG_MON_STAT12_LITTLE_ADDR(base) ((base) + 0x81CUL)
#define SOC_CORE_CPU_CRG_MON_STAT13_LITTLE_ADDR(base) ((base) + 0x820UL)
#define SOC_CORE_CPU_CRG_MON_STAT14_LITTLE_ADDR(base) ((base) + 0x824UL)
#define SOC_CORE_CPU_CRG_MON_STAT15_LITTLE_ADDR(base) ((base) + 0x828UL)
#define SOC_CORE_CPU_CRG_MON_STAT16_LITTLE_ADDR(base) ((base) + 0x82CUL)
#define SOC_CORE_CPU_CRG_MON_STAT17_LITTLE_ADDR(base) ((base) + 0x830UL)
#define SOC_CORE_CPU_CRG_MON_STAT18_LITTLE_ADDR(base) ((base) + 0x834UL)
#define SOC_CORE_CPU_CRG_MON_STAT19_LITTLE_ADDR(base) ((base) + 0x838UL)
#define SOC_CORE_CPU_CRG_MON_STAT20_LITTLE_ADDR(base) ((base) + 0x83CUL)
#define SOC_CORE_CPU_CRG_MON_STAT21_LITTLE_ADDR(base) ((base) + 0x840UL)
#define SOC_CORE_CPU_CRG_MON_STAT22_LITTLE_ADDR(base) ((base) + 0x844UL)
#define SOC_CORE_CPU_CRG_MON_STAT23_LITTLE_ADDR(base) ((base) + 0x848UL)
#define SOC_CORE_CPU_CRG_MON_STAT24_LITTLE_ADDR(base) ((base) + 0x84CUL)
#define SOC_CORE_CPU_CRG_MON_STAT25_LITTLE_ADDR(base) ((base) + 0x850UL)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x8A0UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_MIDDLE_ADDR(base) ((base) + 0x900UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_MIDDLE_ADDR(base) ((base) + 0x904UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_MIDDLE_ADDR(base) ((base) + 0x908UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_MIDDLE_ADDR(base) ((base) + 0x90CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG0_MIDDLE_ADDR(base) ((base) + 0x918UL)
#define SOC_CORE_CPU_CRG_FCG_CFG1_MIDDLE_ADDR(base) ((base) + 0x91CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG2_MIDDLE_ADDR(base) ((base) + 0x920UL)
#define SOC_CORE_CPU_CRG_FCG_CFG3_MIDDLE_ADDR(base) ((base) + 0x924UL)
#define SOC_CORE_CPU_CRG_FCG_CFG4_MIDDLE_ADDR(base) ((base) + 0x928UL)
#define SOC_CORE_CPU_CRG_FCG_CFG5_MIDDLE_ADDR(base) ((base) + 0x92CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG6_MIDDLE_ADDR(base) ((base) + 0x930UL)
#define SOC_CORE_CPU_CRG_FCG_CFG7_MIDDLE_ADDR(base) ((base) + 0x934UL)
#define SOC_CORE_CPU_CRG_FCG_CFG8_MIDDLE_ADDR(base) ((base) + 0x938UL)
#define SOC_CORE_CPU_CRG_FCG_CFG9_MIDDLE_ADDR(base) ((base) + 0x93CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG10_MIDDLE_ADDR(base) ((base) + 0x940UL)
#define SOC_CORE_CPU_CRG_FCG_CFG11_MIDDLE_ADDR(base) ((base) + 0x944UL)
#define SOC_CORE_CPU_CRG_FCG_CFG12_MIDDLE_ADDR(base) ((base) + 0x948UL)
#define SOC_CORE_CPU_CRG_FCG_CFG13_MIDDLE_ADDR(base) ((base) + 0x94CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG14_MIDDLE_ADDR(base) ((base) + 0x950UL)
#define SOC_CORE_CPU_CRG_FCG_CFG15_MIDDLE_ADDR(base) ((base) + 0x954UL)
#define SOC_CORE_CPU_CRG_FCG_CFG16_MIDDLE_ADDR(base) ((base) + 0x958UL)
#define SOC_CORE_CPU_CRG_FCG_CFG17_MIDDLE_ADDR(base) ((base) + 0x95CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG18_MIDDLE_ADDR(base) ((base) + 0x960UL)
#define SOC_CORE_CPU_CRG_FCG_CFG19_MIDDLE_ADDR(base) ((base) + 0x964UL)
#define SOC_CORE_CPU_CRG_FCG_CFG20_MIDDLE_ADDR(base) ((base) + 0x968UL)
#define SOC_CORE_CPU_CRG_FCG_CFG21_MIDDLE_ADDR(base) ((base) + 0x96CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG22_MIDDLE_ADDR(base) ((base) + 0x970UL)
#define SOC_CORE_CPU_CRG_FCG_CFG23_MIDDLE_ADDR(base) ((base) + 0x974UL)
#define SOC_CORE_CPU_CRG_FCG_CFG24_MIDDLE_ADDR(base) ((base) + 0x978UL)
#define SOC_CORE_CPU_CRG_FCG_CFG25_MIDDLE_ADDR(base) ((base) + 0x97CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG26_MIDDLE_ADDR(base) ((base) + 0x980UL)
#define SOC_CORE_CPU_CRG_FCG_CFG27_MIDDLE_ADDR(base) ((base) + 0x984UL)
#define SOC_CORE_CPU_CRG_FCG_STAT0_MIDDLE_ADDR(base) ((base) + 0x990UL)
#define SOC_CORE_CPU_CRG_FCG_STAT1_MIDDLE_ADDR(base) ((base) + 0x994UL)
#define SOC_CORE_CPU_CRG_FCG_STAT2_MIDDLE_ADDR(base) ((base) + 0x998UL)
#define SOC_CORE_CPU_CRG_FCG_STAT3_MIDDLE_ADDR(base) ((base) + 0x99CUL)
#define SOC_CORE_CPU_CRG_FCG_STAT4_MIDDLE_ADDR(base) ((base) + 0x9A0UL)
#define SOC_CORE_CPU_CRG_FCG_STAT5_MIDDLE_ADDR(base) ((base) + 0x9A4UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_BIG_ADDR(base) ((base) + 0xA00UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_BIG_ADDR(base) ((base) + 0xA04UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_BIG_ADDR(base) ((base) + 0xA08UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_BIG_ADDR(base) ((base) + 0xA0CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG0_BIG_ADDR(base) ((base) + 0xA18UL)
#define SOC_CORE_CPU_CRG_FCG_CFG1_BIG_ADDR(base) ((base) + 0xA1CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG2_BIG_ADDR(base) ((base) + 0xA20UL)
#define SOC_CORE_CPU_CRG_FCG_CFG3_BIG_ADDR(base) ((base) + 0xA24UL)
#define SOC_CORE_CPU_CRG_FCG_CFG4_BIG_ADDR(base) ((base) + 0xA28UL)
#define SOC_CORE_CPU_CRG_FCG_CFG5_BIG_ADDR(base) ((base) + 0xA2CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG6_BIG_ADDR(base) ((base) + 0xA30UL)
#define SOC_CORE_CPU_CRG_FCG_CFG7_BIG_ADDR(base) ((base) + 0xA34UL)
#define SOC_CORE_CPU_CRG_FCG_CFG8_BIG_ADDR(base) ((base) + 0xA38UL)
#define SOC_CORE_CPU_CRG_FCG_CFG9_BIG_ADDR(base) ((base) + 0xA3CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG10_BIG_ADDR(base) ((base) + 0xA40UL)
#define SOC_CORE_CPU_CRG_FCG_CFG11_BIG_ADDR(base) ((base) + 0xA44UL)
#define SOC_CORE_CPU_CRG_FCG_CFG12_BIG_ADDR(base) ((base) + 0xA48UL)
#define SOC_CORE_CPU_CRG_FCG_CFG13_BIG_ADDR(base) ((base) + 0xA4CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG14_BIG_ADDR(base) ((base) + 0xA50UL)
#define SOC_CORE_CPU_CRG_FCG_CFG15_BIG_ADDR(base) ((base) + 0xA54UL)
#define SOC_CORE_CPU_CRG_FCG_CFG16_BIG_ADDR(base) ((base) + 0xA58UL)
#define SOC_CORE_CPU_CRG_FCG_CFG17_BIG_ADDR(base) ((base) + 0xA5CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG18_BIG_ADDR(base) ((base) + 0xA60UL)
#define SOC_CORE_CPU_CRG_FCG_CFG19_BIG_ADDR(base) ((base) + 0xA64UL)
#define SOC_CORE_CPU_CRG_FCG_CFG20_BIG_ADDR(base) ((base) + 0xA68UL)
#define SOC_CORE_CPU_CRG_FCG_CFG21_BIG_ADDR(base) ((base) + 0xA6CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG22_BIG_ADDR(base) ((base) + 0xA70UL)
#define SOC_CORE_CPU_CRG_FCG_CFG23_BIG_ADDR(base) ((base) + 0xA74UL)
#define SOC_CORE_CPU_CRG_FCG_CFG24_BIG_ADDR(base) ((base) + 0xA78UL)
#define SOC_CORE_CPU_CRG_FCG_CFG25_BIG_ADDR(base) ((base) + 0xA7CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG26_BIG_ADDR(base) ((base) + 0xA80UL)
#define SOC_CORE_CPU_CRG_FCG_CFG27_BIG_ADDR(base) ((base) + 0xA84UL)
#define SOC_CORE_CPU_CRG_FCG_STAT0_BIG_ADDR(base) ((base) + 0xA90UL)
#define SOC_CORE_CPU_CRG_FCG_STAT1_BIG_ADDR(base) ((base) + 0xA94UL)
#define SOC_CORE_CPU_CRG_FCG_STAT2_BIG_ADDR(base) ((base) + 0xA98UL)
#define SOC_CORE_CPU_CRG_FCG_STAT3_BIG_ADDR(base) ((base) + 0xA9CUL)
#define SOC_CORE_CPU_CRG_FCG_STAT4_BIG_ADDR(base) ((base) + 0xAA0UL)
#define SOC_CORE_CPU_CRG_FCG_STAT5_BIG_ADDR(base) ((base) + 0xAA4UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_LITTLE_ADDR(base) ((base) + 0xB00UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_LITTLE_ADDR(base) ((base) + 0xB04UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_LITTLE_ADDR(base) ((base) + 0xB08UL)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_LITTLE_ADDR(base) ((base) + 0xB0CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG0_LITTLE_ADDR(base) ((base) + 0xB18UL)
#define SOC_CORE_CPU_CRG_FCG_CFG1_LITTLE_ADDR(base) ((base) + 0xB1CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG2_LITTLE_ADDR(base) ((base) + 0xB20UL)
#define SOC_CORE_CPU_CRG_FCG_CFG3_LITTLE_ADDR(base) ((base) + 0xB24UL)
#define SOC_CORE_CPU_CRG_FCG_CFG4_LITTLE_ADDR(base) ((base) + 0xB28UL)
#define SOC_CORE_CPU_CRG_FCG_CFG5_LITTLE_ADDR(base) ((base) + 0xB2CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG6_LITTLE_ADDR(base) ((base) + 0xB30UL)
#define SOC_CORE_CPU_CRG_FCG_CFG7_LITTLE_ADDR(base) ((base) + 0xB34UL)
#define SOC_CORE_CPU_CRG_FCG_CFG8_LITTLE_ADDR(base) ((base) + 0xB38UL)
#define SOC_CORE_CPU_CRG_FCG_CFG9_LITTLE_ADDR(base) ((base) + 0xB3CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG10_LITTLE_ADDR(base) ((base) + 0xB40UL)
#define SOC_CORE_CPU_CRG_FCG_CFG11_LITTLE_ADDR(base) ((base) + 0xB44UL)
#define SOC_CORE_CPU_CRG_FCG_CFG12_LITTLE_ADDR(base) ((base) + 0xB48UL)
#define SOC_CORE_CPU_CRG_FCG_CFG13_LITTLE_ADDR(base) ((base) + 0xB4CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG14_LITTLE_ADDR(base) ((base) + 0xB50UL)
#define SOC_CORE_CPU_CRG_FCG_CFG15_LITTLE_ADDR(base) ((base) + 0xB54UL)
#define SOC_CORE_CPU_CRG_FCG_CFG16_LITTLE_ADDR(base) ((base) + 0xB58UL)
#define SOC_CORE_CPU_CRG_FCG_CFG17_LITTLE_ADDR(base) ((base) + 0xB5CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG18_LITTLE_ADDR(base) ((base) + 0xB60UL)
#define SOC_CORE_CPU_CRG_FCG_CFG19_LITTLE_ADDR(base) ((base) + 0xB64UL)
#define SOC_CORE_CPU_CRG_FCG_CFG20_LITTLE_ADDR(base) ((base) + 0xB68UL)
#define SOC_CORE_CPU_CRG_FCG_CFG21_LITTLE_ADDR(base) ((base) + 0xB6CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG22_LITTLE_ADDR(base) ((base) + 0xB70UL)
#define SOC_CORE_CPU_CRG_FCG_CFG23_LITTLE_ADDR(base) ((base) + 0xB74UL)
#define SOC_CORE_CPU_CRG_FCG_CFG24_LITTLE_ADDR(base) ((base) + 0xB78UL)
#define SOC_CORE_CPU_CRG_FCG_CFG25_LITTLE_ADDR(base) ((base) + 0xB7CUL)
#define SOC_CORE_CPU_CRG_FCG_CFG26_LITTLE_ADDR(base) ((base) + 0xB80UL)
#define SOC_CORE_CPU_CRG_FCG_CFG27_LITTLE_ADDR(base) ((base) + 0xB84UL)
#define SOC_CORE_CPU_CRG_FCG_STAT0_LITTLE_ADDR(base) ((base) + 0xB90UL)
#define SOC_CORE_CPU_CRG_FCG_STAT1_LITTLE_ADDR(base) ((base) + 0xB94UL)
#define SOC_CORE_CPU_CRG_FCG_STAT2_LITTLE_ADDR(base) ((base) + 0xB98UL)
#define SOC_CORE_CPU_CRG_FCG_STAT3_LITTLE_ADDR(base) ((base) + 0xB9CUL)
#define SOC_CORE_CPU_CRG_FCG_STAT4_LITTLE_ADDR(base) ((base) + 0xBA0UL)
#define SOC_CORE_CPU_CRG_FCG_STAT5_LITTLE_ADDR(base) ((base) + 0xBA4UL)
#define SOC_CORE_CPU_CRG_CALIBRATION1_ADDR(base) ((base) + 0xF00UL)
#define SOC_CORE_CPU_CRG_CALIBRATION2_ADDR(base) ((base) + 0xF04UL)
#define SOC_CORE_CPU_CRG_TS_CFG_ADDR(base) ((base) + 0xF08UL)
#define SOC_CORE_CPU_CRG_DATA_ADDR(base) ((base) + 0xF0CUL)
#define SOC_CORE_CPU_CRG_DATA_MIN_ADDR(base) ((base) + 0xF10UL)
#define SOC_CORE_CPU_CRG_DATA_MAX_ADDR(base) ((base) + 0xF14UL)
#define SOC_CORE_CPU_CRG_TS_RSV_CTRL_ADDR(base) ((base) + 0xF18UL)
#else
#define SOC_CORE_CPU_CRG_PEREN0_ADDR(base) (base)
#define SOC_CORE_CPU_CRG_PERDIS0_ADDR(base) ((base) + 0x004)
#define SOC_CORE_CPU_CRG_PERCLKEN0_ADDR(base) ((base) + 0x008)
#define SOC_CORE_CPU_CRG_PERSTAT0_ADDR(base) ((base) + 0x00C)
#define SOC_CORE_CPU_CRG_PEREN1_ADDR(base) ((base) + 0x010)
#define SOC_CORE_CPU_CRG_PERDIS1_ADDR(base) ((base) + 0x014)
#define SOC_CORE_CPU_CRG_PERCLKEN1_ADDR(base) ((base) + 0x018)
#define SOC_CORE_CPU_CRG_PERSTAT1_ADDR(base) ((base) + 0x01C)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ADDR(base) ((base) + 0x040)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ADDR(base) ((base) + 0x044)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ADDR(base) ((base) + 0x048)
#define SOC_CORE_CPU_CRG_PERI_STAT0_ADDR(base) ((base) + 0x060)
#define SOC_CORE_CPU_CRG_PERI_STAT1_ADDR(base) ((base) + 0x064)
#define SOC_CORE_CPU_CRG_CLKDIV0_ADDR(base) ((base) + 0x080)
#define SOC_CORE_CPU_CRG_CLKDIV1_ADDR(base) ((base) + 0x084)
#define SOC_CORE_CPU_CRG_CLKDIV2_ADDR(base) ((base) + 0x088)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_ADDR(base) ((base) + 0x1B0)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_ADDR(base) ((base) + 0x1B4)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_ADDR(base) ((base) + 0x1B8)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_ADDR(base) ((base) + 0x1C0)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_ADDR(base) ((base) + 0x1C4)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_ADDR(base) ((base) + 0x1C8)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV0_ADDR(base) ((base) + 0x1D0)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV1_ADDR(base) ((base) + 0x1D4)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV2_ADDR(base) ((base) + 0x1D8)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_ADDR(base) ((base) + 0x1EC)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_ADDR(base) ((base) + 0x1F0)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_ADDR(base) ((base) + 0x1F4)
#define SOC_CORE_CPU_CRG_FCG_STAT0_ADDR(base) ((base) + 0x1F8)
#define SOC_CORE_CPU_CRG_FCG_STAT1_ADDR(base) ((base) + 0x1FC)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_ADDR(base) ((base) + 0x200)
#define SOC_CORE_CPU_CRG_RSV_CFG0_ADDR(base) ((base) + 0x300)
#define SOC_CORE_CPU_CRG_RSV_CFG1_ADDR(base) ((base) + 0x304)
#define SOC_CORE_CPU_CRG_RSV_CFG2_ADDR(base) ((base) + 0x308)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_ADDR(base) ((base) + 0x400)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_ADDR(base) ((base) + 0x404)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_ADDR(base) ((base) + 0x408)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_ADDR(base) ((base) + 0x40c)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_ADDR(base) ((base) + 0x410)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_A_ADDR(base) ((base) + 0x4F4)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_B_ADDR(base) ((base) + 0x4F8)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_C_ADDR(base) ((base) + 0x4FC)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_AB_ADDR(base) ((base) + 0x500)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_A_ADDR(base) ((base) + 0x504)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_ADDR(base) ((base) + 0x508)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_ADDR(base) ((base) + 0x50C)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_ADDR(base) ((base) + 0x510)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_ADDR(base) ((base) + 0x514)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + 0x51C)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_ADDR(base) ((base) + 0x520)
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_ADDR(base) ((base) + 0x524)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_B_ADDR(base) ((base) + 0x528)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_ADDR(base) ((base) + 0x52C)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_C_ADDR(base) ((base) + 0x530)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_ADDR(base) ((base) + 0x534)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_CD_ADDR(base) ((base) + 0x540)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_ADDR(base) ((base) + 0x548)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_ADDR(base) ((base) + 0x54C)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_ADDR(base) ((base) + 0x550)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_ADDR(base) ((base) + 0x554)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_ADDR(base) ((base) + 0x558)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_ADDR(base) ((base) + 0x55C)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_ADDR(base) ((base) + 0x560)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_ADDR(base) ((base) + 0x564)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_ADDR(base) ((base) + 0x568)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_A_ADDR(base) ((base) + 0x56C)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_A_ADDR(base) ((base) + 0x570)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_ADDR(base) ((base) + 0x574)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_A_ADDR(base) ((base) + 0x578)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_A_ADDR(base) ((base) + 0x57C)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_ADDR(base) ((base) + 0x580)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_ADDR(base) ((base) + 0x584)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_ADDR(base) ((base) + 0x588)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_ADDR(base) ((base) + 0x58C)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_ADDR(base) ((base) + 0x590)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_ADDR(base) ((base) + 0x594)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_ADDR(base) ((base) + 0x598)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_ADDR(base) ((base) + 0x59C)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_ADDR(base) ((base) + 0x5A0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_B_ADDR(base) ((base) + 0x5A4)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_B_ADDR(base) ((base) + 0x5A8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_ADDR(base) ((base) + 0x5AC)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_B_ADDR(base) ((base) + 0x5B0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_B_ADDR(base) ((base) + 0x5B4)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_ADDR(base) ((base) + 0x5B8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_ADDR(base) ((base) + 0x5BC)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_ADDR(base) ((base) + 0x5C0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_ADDR(base) ((base) + 0x5C4)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_ADDR(base) ((base) + 0x5C8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_ADDR(base) ((base) + 0x5CC)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_ADDR(base) ((base) + 0x5D0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_ADDR(base) ((base) + 0x5D4)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_ADDR(base) ((base) + 0x5D8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_C_ADDR(base) ((base) + 0x5DC)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_C_ADDR(base) ((base) + 0x5E0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_ADDR(base) ((base) + 0x5E4)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_C_ADDR(base) ((base) + 0x5E8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_C_ADDR(base) ((base) + 0x5EC)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_A_ADDR(base) ((base) + 0x5F0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_B_ADDR(base) ((base) + 0x5F4)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_C_ADDR(base) ((base) + 0x5F8)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_ADDR(base) ((base) + 0x600)
#define SOC_CORE_CPU_CRG_PIM_CFG0_MIDDLE_ADDR(base) ((base) + 0x604)
#define SOC_CORE_CPU_CRG_PIM_CFG1_MIDDLE_ADDR(base) ((base) + 0x608)
#define SOC_CORE_CPU_CRG_PIM_CFG2_MIDDLE_ADDR(base) ((base) + 0x60C)
#define SOC_CORE_CPU_CRG_PIM_CFG3_MIDDLE_ADDR(base) ((base) + 0x610)
#define SOC_CORE_CPU_CRG_PIM_CFG0_BIG_ADDR(base) ((base) + 0x614)
#define SOC_CORE_CPU_CRG_PIM_CFG1_BIG_ADDR(base) ((base) + 0x618)
#define SOC_CORE_CPU_CRG_PIM_CFG2_BIG_ADDR(base) ((base) + 0x61C)
#define SOC_CORE_CPU_CRG_PIM_CFG3_BIG_ADDR(base) ((base) + 0x620)
#define SOC_CORE_CPU_CRG_PIM_CFG0_LITTLE_ADDR(base) ((base) + 0x624)
#define SOC_CORE_CPU_CRG_PIM_CFG1_LITTLE_ADDR(base) ((base) + 0x628)
#define SOC_CORE_CPU_CRG_PIM_CFG2_LITTLE_ADDR(base) ((base) + 0x62C)
#define SOC_CORE_CPU_CRG_PIM_CFG3_LITTLE_ADDR(base) ((base) + 0x630)
#define SOC_CORE_CPU_CRG_PIM_STAT0_ADDR(base) ((base) + 0x634)
#define SOC_CORE_CPU_CRG_PIM_STAT1_ADDR(base) ((base) + 0x638)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_ADDR(base) ((base) + 0x650)
#define SOC_CORE_CPU_CRG_MON_CFG1_MIDDLE_ADDR(base) ((base) + 0x654)
#define SOC_CORE_CPU_CRG_MON_CFG2_MIDDLE_ADDR(base) ((base) + 0x658)
#define SOC_CORE_CPU_CRG_MON_CFG3_MIDDLE_ADDR(base) ((base) + 0x65C)
#define SOC_CORE_CPU_CRG_MON_CFG4_MIDDLE_ADDR(base) ((base) + 0x660)
#define SOC_CORE_CPU_CRG_MON_CFG5_MIDDLE_ADDR(base) ((base) + 0x664)
#define SOC_CORE_CPU_CRG_MON_CFG6_MIDDLE_ADDR(base) ((base) + 0x668)
#define SOC_CORE_CPU_CRG_MON_CFG7_MIDDLE_ADDR(base) ((base) + 0x66C)
#define SOC_CORE_CPU_CRG_MON_CFG8_MIDDLE_ADDR(base) ((base) + 0x670)
#define SOC_CORE_CPU_CRG_MON_CFG9_MIDDLE_ADDR(base) ((base) + 0x674)
#define SOC_CORE_CPU_CRG_MON_CFG10_MIDDLE_ADDR(base) ((base) + 0x678)
#define SOC_CORE_CPU_CRG_MON_CFG11_MIDDLE_ADDR(base) ((base) + 0x67C)
#define SOC_CORE_CPU_CRG_MON_CFG12_MIDDLE_ADDR(base) ((base) + 0x680)
#define SOC_CORE_CPU_CRG_MON_CFG13_MIDDLE_ADDR(base) ((base) + 0x684)
#define SOC_CORE_CPU_CRG_MON_CFG14_MIDDLE_ADDR(base) ((base) + 0x688)
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_ADDR(base) ((base) + 0x68C)
#define SOC_CORE_CPU_CRG_MON_CFG16_MIDDLE_ADDR(base) ((base) + 0x690)
#define SOC_CORE_CPU_CRG_MON_STAT0_MIDDLE_ADDR(base) ((base) + 0x694)
#define SOC_CORE_CPU_CRG_MON_STAT1_MIDDLE_ADDR(base) ((base) + 0x698)
#define SOC_CORE_CPU_CRG_MON_STAT2_MIDDLE_ADDR(base) ((base) + 0x69C)
#define SOC_CORE_CPU_CRG_MON_STAT3_MIDDLE_ADDR(base) ((base) + 0x6A0)
#define SOC_CORE_CPU_CRG_MON_STAT4_MIDDLE_ADDR(base) ((base) + 0x6A4)
#define SOC_CORE_CPU_CRG_MON_STAT5_MIDDLE_ADDR(base) ((base) + 0x6A8)
#define SOC_CORE_CPU_CRG_MON_STAT6_MIDDLE_ADDR(base) ((base) + 0x6AC)
#define SOC_CORE_CPU_CRG_MON_STAT7_MIDDLE_ADDR(base) ((base) + 0x6B0)
#define SOC_CORE_CPU_CRG_MON_STAT8_MIDDLE_ADDR(base) ((base) + 0x6B4)
#define SOC_CORE_CPU_CRG_MON_STAT9_MIDDLE_ADDR(base) ((base) + 0x6B8)
#define SOC_CORE_CPU_CRG_MON_STAT10_MIDDLE_ADDR(base) ((base) + 0x6BC)
#define SOC_CORE_CPU_CRG_MON_STAT11_MIDDLE_ADDR(base) ((base) + 0x6C0)
#define SOC_CORE_CPU_CRG_MON_STAT12_MIDDLE_ADDR(base) ((base) + 0x6C4)
#define SOC_CORE_CPU_CRG_MON_STAT13_MIDDLE_ADDR(base) ((base) + 0x6C8)
#define SOC_CORE_CPU_CRG_MON_STAT14_MIDDLE_ADDR(base) ((base) + 0x6CC)
#define SOC_CORE_CPU_CRG_MON_STAT15_MIDDLE_ADDR(base) ((base) + 0x6D0)
#define SOC_CORE_CPU_CRG_MON_STAT16_MIDDLE_ADDR(base) ((base) + 0x6D4)
#define SOC_CORE_CPU_CRG_MON_STAT17_MIDDLE_ADDR(base) ((base) + 0x6D8)
#define SOC_CORE_CPU_CRG_MON_STAT18_MIDDLE_ADDR(base) ((base) + 0x6DC)
#define SOC_CORE_CPU_CRG_MON_STAT19_MIDDLE_ADDR(base) ((base) + 0x6E0)
#define SOC_CORE_CPU_CRG_MON_STAT20_MIDDLE_ADDR(base) ((base) + 0x6E4)
#define SOC_CORE_CPU_CRG_MON_STAT21_MIDDLE_ADDR(base) ((base) + 0x6E8)
#define SOC_CORE_CPU_CRG_MON_STAT22_MIDDLE_ADDR(base) ((base) + 0x6EC)
#define SOC_CORE_CPU_CRG_MON_STAT23_MIDDLE_ADDR(base) ((base) + 0x6F0)
#define SOC_CORE_CPU_CRG_MON_STAT24_MIDDLE_ADDR(base) ((base) + 0x6F4)
#define SOC_CORE_CPU_CRG_MON_STAT25_MIDDLE_ADDR(base) ((base) + 0x6F8)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_ADDR(base) ((base) + 0x6FC)
#define SOC_CORE_CPU_CRG_MON_CFG1_BIG_ADDR(base) ((base) + 0x700)
#define SOC_CORE_CPU_CRG_MON_CFG2_BIG_ADDR(base) ((base) + 0x704)
#define SOC_CORE_CPU_CRG_MON_CFG3_BIG_ADDR(base) ((base) + 0x708)
#define SOC_CORE_CPU_CRG_MON_CFG4_BIG_ADDR(base) ((base) + 0x70C)
#define SOC_CORE_CPU_CRG_MON_CFG5_BIG_ADDR(base) ((base) + 0x710)
#define SOC_CORE_CPU_CRG_MON_CFG6_BIG_ADDR(base) ((base) + 0x714)
#define SOC_CORE_CPU_CRG_MON_CFG7_BIG_ADDR(base) ((base) + 0x718)
#define SOC_CORE_CPU_CRG_MON_CFG8_BIG_ADDR(base) ((base) + 0x71C)
#define SOC_CORE_CPU_CRG_MON_CFG9_BIG_ADDR(base) ((base) + 0x720)
#define SOC_CORE_CPU_CRG_MON_CFG10_BIG_ADDR(base) ((base) + 0x724)
#define SOC_CORE_CPU_CRG_MON_CFG11_BIG_ADDR(base) ((base) + 0x728)
#define SOC_CORE_CPU_CRG_MON_CFG12_BIG_ADDR(base) ((base) + 0x72C)
#define SOC_CORE_CPU_CRG_MON_CFG13_BIG_ADDR(base) ((base) + 0x730)
#define SOC_CORE_CPU_CRG_MON_CFG14_BIG_ADDR(base) ((base) + 0x734)
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_ADDR(base) ((base) + 0x738)
#define SOC_CORE_CPU_CRG_MON_CFG16_BIG_ADDR(base) ((base) + 0x73C)
#define SOC_CORE_CPU_CRG_MON_STAT0_BIG_ADDR(base) ((base) + 0x740)
#define SOC_CORE_CPU_CRG_MON_STAT1_BIG_ADDR(base) ((base) + 0x744)
#define SOC_CORE_CPU_CRG_MON_STAT2_BIG_ADDR(base) ((base) + 0x748)
#define SOC_CORE_CPU_CRG_MON_STAT3_BIG_ADDR(base) ((base) + 0x74C)
#define SOC_CORE_CPU_CRG_MON_STAT4_BIG_ADDR(base) ((base) + 0x750)
#define SOC_CORE_CPU_CRG_MON_STAT5_BIG_ADDR(base) ((base) + 0x754)
#define SOC_CORE_CPU_CRG_MON_STAT6_BIG_ADDR(base) ((base) + 0x758)
#define SOC_CORE_CPU_CRG_MON_STAT7_BIG_ADDR(base) ((base) + 0x75C)
#define SOC_CORE_CPU_CRG_MON_STAT8_BIG_ADDR(base) ((base) + 0x760)
#define SOC_CORE_CPU_CRG_MON_STAT9_BIG_ADDR(base) ((base) + 0x764)
#define SOC_CORE_CPU_CRG_MON_STAT10_BIG_ADDR(base) ((base) + 0x768)
#define SOC_CORE_CPU_CRG_MON_STAT11_BIG_ADDR(base) ((base) + 0x76C)
#define SOC_CORE_CPU_CRG_MON_STAT12_BIG_ADDR(base) ((base) + 0x770)
#define SOC_CORE_CPU_CRG_MON_STAT13_BIG_ADDR(base) ((base) + 0x774)
#define SOC_CORE_CPU_CRG_MON_STAT14_BIG_ADDR(base) ((base) + 0x778)
#define SOC_CORE_CPU_CRG_MON_STAT15_BIG_ADDR(base) ((base) + 0x77C)
#define SOC_CORE_CPU_CRG_MON_STAT16_BIG_ADDR(base) ((base) + 0x780)
#define SOC_CORE_CPU_CRG_MON_STAT17_BIG_ADDR(base) ((base) + 0x784)
#define SOC_CORE_CPU_CRG_MON_STAT18_BIG_ADDR(base) ((base) + 0x788)
#define SOC_CORE_CPU_CRG_MON_STAT19_BIG_ADDR(base) ((base) + 0x78C)
#define SOC_CORE_CPU_CRG_MON_STAT20_BIG_ADDR(base) ((base) + 0x790)
#define SOC_CORE_CPU_CRG_MON_STAT21_BIG_ADDR(base) ((base) + 0x794)
#define SOC_CORE_CPU_CRG_MON_STAT22_BIG_ADDR(base) ((base) + 0x798)
#define SOC_CORE_CPU_CRG_MON_STAT23_BIG_ADDR(base) ((base) + 0x79C)
#define SOC_CORE_CPU_CRG_MON_STAT24_BIG_ADDR(base) ((base) + 0x7A0)
#define SOC_CORE_CPU_CRG_MON_STAT25_BIG_ADDR(base) ((base) + 0x7A4)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_ADDR(base) ((base) + 0x7A8)
#define SOC_CORE_CPU_CRG_MON_CFG1_LITTLE_ADDR(base) ((base) + 0x7AC)
#define SOC_CORE_CPU_CRG_MON_CFG2_LITTLE_ADDR(base) ((base) + 0x7B0)
#define SOC_CORE_CPU_CRG_MON_CFG3_LITTLE_ADDR(base) ((base) + 0x7B4)
#define SOC_CORE_CPU_CRG_MON_CFG4_LITTLE_ADDR(base) ((base) + 0x7B8)
#define SOC_CORE_CPU_CRG_MON_CFG5_LITTLE_ADDR(base) ((base) + 0x7BC)
#define SOC_CORE_CPU_CRG_MON_CFG6_LITTLE_ADDR(base) ((base) + 0x7C0)
#define SOC_CORE_CPU_CRG_MON_CFG7_LITTLE_ADDR(base) ((base) + 0x7C4)
#define SOC_CORE_CPU_CRG_MON_CFG8_LITTLE_ADDR(base) ((base) + 0x7C8)
#define SOC_CORE_CPU_CRG_MON_CFG9_LITTLE_ADDR(base) ((base) + 0x7CC)
#define SOC_CORE_CPU_CRG_MON_CFG10_LITTLE_ADDR(base) ((base) + 0x7D0)
#define SOC_CORE_CPU_CRG_MON_CFG11_LITTLE_ADDR(base) ((base) + 0x7D4)
#define SOC_CORE_CPU_CRG_MON_CFG12_LITTLE_ADDR(base) ((base) + 0x7D8)
#define SOC_CORE_CPU_CRG_MON_CFG13_LITTLE_ADDR(base) ((base) + 0x7DC)
#define SOC_CORE_CPU_CRG_MON_CFG14_LITTLE_ADDR(base) ((base) + 0x7E0)
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_ADDR(base) ((base) + 0x7E4)
#define SOC_CORE_CPU_CRG_MON_CFG16_LITTLE_ADDR(base) ((base) + 0x7E8)
#define SOC_CORE_CPU_CRG_MON_STAT0_LITTLE_ADDR(base) ((base) + 0x7EC)
#define SOC_CORE_CPU_CRG_MON_STAT1_LITTLE_ADDR(base) ((base) + 0x7F0)
#define SOC_CORE_CPU_CRG_MON_STAT2_LITTLE_ADDR(base) ((base) + 0x7F4)
#define SOC_CORE_CPU_CRG_MON_STAT3_LITTLE_ADDR(base) ((base) + 0x7F8)
#define SOC_CORE_CPU_CRG_MON_STAT4_LITTLE_ADDR(base) ((base) + 0x7FC)
#define SOC_CORE_CPU_CRG_MON_STAT5_LITTLE_ADDR(base) ((base) + 0x800)
#define SOC_CORE_CPU_CRG_MON_STAT6_LITTLE_ADDR(base) ((base) + 0x804)
#define SOC_CORE_CPU_CRG_MON_STAT7_LITTLE_ADDR(base) ((base) + 0x808)
#define SOC_CORE_CPU_CRG_MON_STAT8_LITTLE_ADDR(base) ((base) + 0x80C)
#define SOC_CORE_CPU_CRG_MON_STAT9_LITTLE_ADDR(base) ((base) + 0x810)
#define SOC_CORE_CPU_CRG_MON_STAT10_LITTLE_ADDR(base) ((base) + 0x814)
#define SOC_CORE_CPU_CRG_MON_STAT11_LITTLE_ADDR(base) ((base) + 0x818)
#define SOC_CORE_CPU_CRG_MON_STAT12_LITTLE_ADDR(base) ((base) + 0x81C)
#define SOC_CORE_CPU_CRG_MON_STAT13_LITTLE_ADDR(base) ((base) + 0x820)
#define SOC_CORE_CPU_CRG_MON_STAT14_LITTLE_ADDR(base) ((base) + 0x824)
#define SOC_CORE_CPU_CRG_MON_STAT15_LITTLE_ADDR(base) ((base) + 0x828)
#define SOC_CORE_CPU_CRG_MON_STAT16_LITTLE_ADDR(base) ((base) + 0x82C)
#define SOC_CORE_CPU_CRG_MON_STAT17_LITTLE_ADDR(base) ((base) + 0x830)
#define SOC_CORE_CPU_CRG_MON_STAT18_LITTLE_ADDR(base) ((base) + 0x834)
#define SOC_CORE_CPU_CRG_MON_STAT19_LITTLE_ADDR(base) ((base) + 0x838)
#define SOC_CORE_CPU_CRG_MON_STAT20_LITTLE_ADDR(base) ((base) + 0x83C)
#define SOC_CORE_CPU_CRG_MON_STAT21_LITTLE_ADDR(base) ((base) + 0x840)
#define SOC_CORE_CPU_CRG_MON_STAT22_LITTLE_ADDR(base) ((base) + 0x844)
#define SOC_CORE_CPU_CRG_MON_STAT23_LITTLE_ADDR(base) ((base) + 0x848)
#define SOC_CORE_CPU_CRG_MON_STAT24_LITTLE_ADDR(base) ((base) + 0x84C)
#define SOC_CORE_CPU_CRG_MON_STAT25_LITTLE_ADDR(base) ((base) + 0x850)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x8A0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_MIDDLE_ADDR(base) ((base) + 0x900)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_MIDDLE_ADDR(base) ((base) + 0x904)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_MIDDLE_ADDR(base) ((base) + 0x908)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_MIDDLE_ADDR(base) ((base) + 0x90C)
#define SOC_CORE_CPU_CRG_FCG_CFG0_MIDDLE_ADDR(base) ((base) + 0x918)
#define SOC_CORE_CPU_CRG_FCG_CFG1_MIDDLE_ADDR(base) ((base) + 0x91C)
#define SOC_CORE_CPU_CRG_FCG_CFG2_MIDDLE_ADDR(base) ((base) + 0x920)
#define SOC_CORE_CPU_CRG_FCG_CFG3_MIDDLE_ADDR(base) ((base) + 0x924)
#define SOC_CORE_CPU_CRG_FCG_CFG4_MIDDLE_ADDR(base) ((base) + 0x928)
#define SOC_CORE_CPU_CRG_FCG_CFG5_MIDDLE_ADDR(base) ((base) + 0x92C)
#define SOC_CORE_CPU_CRG_FCG_CFG6_MIDDLE_ADDR(base) ((base) + 0x930)
#define SOC_CORE_CPU_CRG_FCG_CFG7_MIDDLE_ADDR(base) ((base) + 0x934)
#define SOC_CORE_CPU_CRG_FCG_CFG8_MIDDLE_ADDR(base) ((base) + 0x938)
#define SOC_CORE_CPU_CRG_FCG_CFG9_MIDDLE_ADDR(base) ((base) + 0x93C)
#define SOC_CORE_CPU_CRG_FCG_CFG10_MIDDLE_ADDR(base) ((base) + 0x940)
#define SOC_CORE_CPU_CRG_FCG_CFG11_MIDDLE_ADDR(base) ((base) + 0x944)
#define SOC_CORE_CPU_CRG_FCG_CFG12_MIDDLE_ADDR(base) ((base) + 0x948)
#define SOC_CORE_CPU_CRG_FCG_CFG13_MIDDLE_ADDR(base) ((base) + 0x94C)
#define SOC_CORE_CPU_CRG_FCG_CFG14_MIDDLE_ADDR(base) ((base) + 0x950)
#define SOC_CORE_CPU_CRG_FCG_CFG15_MIDDLE_ADDR(base) ((base) + 0x954)
#define SOC_CORE_CPU_CRG_FCG_CFG16_MIDDLE_ADDR(base) ((base) + 0x958)
#define SOC_CORE_CPU_CRG_FCG_CFG17_MIDDLE_ADDR(base) ((base) + 0x95C)
#define SOC_CORE_CPU_CRG_FCG_CFG18_MIDDLE_ADDR(base) ((base) + 0x960)
#define SOC_CORE_CPU_CRG_FCG_CFG19_MIDDLE_ADDR(base) ((base) + 0x964)
#define SOC_CORE_CPU_CRG_FCG_CFG20_MIDDLE_ADDR(base) ((base) + 0x968)
#define SOC_CORE_CPU_CRG_FCG_CFG21_MIDDLE_ADDR(base) ((base) + 0x96C)
#define SOC_CORE_CPU_CRG_FCG_CFG22_MIDDLE_ADDR(base) ((base) + 0x970)
#define SOC_CORE_CPU_CRG_FCG_CFG23_MIDDLE_ADDR(base) ((base) + 0x974)
#define SOC_CORE_CPU_CRG_FCG_CFG24_MIDDLE_ADDR(base) ((base) + 0x978)
#define SOC_CORE_CPU_CRG_FCG_CFG25_MIDDLE_ADDR(base) ((base) + 0x97C)
#define SOC_CORE_CPU_CRG_FCG_CFG26_MIDDLE_ADDR(base) ((base) + 0x980)
#define SOC_CORE_CPU_CRG_FCG_CFG27_MIDDLE_ADDR(base) ((base) + 0x984)
#define SOC_CORE_CPU_CRG_FCG_STAT0_MIDDLE_ADDR(base) ((base) + 0x990)
#define SOC_CORE_CPU_CRG_FCG_STAT1_MIDDLE_ADDR(base) ((base) + 0x994)
#define SOC_CORE_CPU_CRG_FCG_STAT2_MIDDLE_ADDR(base) ((base) + 0x998)
#define SOC_CORE_CPU_CRG_FCG_STAT3_MIDDLE_ADDR(base) ((base) + 0x99C)
#define SOC_CORE_CPU_CRG_FCG_STAT4_MIDDLE_ADDR(base) ((base) + 0x9A0)
#define SOC_CORE_CPU_CRG_FCG_STAT5_MIDDLE_ADDR(base) ((base) + 0x9A4)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_BIG_ADDR(base) ((base) + 0xA00)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_BIG_ADDR(base) ((base) + 0xA04)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_BIG_ADDR(base) ((base) + 0xA08)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_BIG_ADDR(base) ((base) + 0xA0C)
#define SOC_CORE_CPU_CRG_FCG_CFG0_BIG_ADDR(base) ((base) + 0xA18)
#define SOC_CORE_CPU_CRG_FCG_CFG1_BIG_ADDR(base) ((base) + 0xA1C)
#define SOC_CORE_CPU_CRG_FCG_CFG2_BIG_ADDR(base) ((base) + 0xA20)
#define SOC_CORE_CPU_CRG_FCG_CFG3_BIG_ADDR(base) ((base) + 0xA24)
#define SOC_CORE_CPU_CRG_FCG_CFG4_BIG_ADDR(base) ((base) + 0xA28)
#define SOC_CORE_CPU_CRG_FCG_CFG5_BIG_ADDR(base) ((base) + 0xA2C)
#define SOC_CORE_CPU_CRG_FCG_CFG6_BIG_ADDR(base) ((base) + 0xA30)
#define SOC_CORE_CPU_CRG_FCG_CFG7_BIG_ADDR(base) ((base) + 0xA34)
#define SOC_CORE_CPU_CRG_FCG_CFG8_BIG_ADDR(base) ((base) + 0xA38)
#define SOC_CORE_CPU_CRG_FCG_CFG9_BIG_ADDR(base) ((base) + 0xA3C)
#define SOC_CORE_CPU_CRG_FCG_CFG10_BIG_ADDR(base) ((base) + 0xA40)
#define SOC_CORE_CPU_CRG_FCG_CFG11_BIG_ADDR(base) ((base) + 0xA44)
#define SOC_CORE_CPU_CRG_FCG_CFG12_BIG_ADDR(base) ((base) + 0xA48)
#define SOC_CORE_CPU_CRG_FCG_CFG13_BIG_ADDR(base) ((base) + 0xA4C)
#define SOC_CORE_CPU_CRG_FCG_CFG14_BIG_ADDR(base) ((base) + 0xA50)
#define SOC_CORE_CPU_CRG_FCG_CFG15_BIG_ADDR(base) ((base) + 0xA54)
#define SOC_CORE_CPU_CRG_FCG_CFG16_BIG_ADDR(base) ((base) + 0xA58)
#define SOC_CORE_CPU_CRG_FCG_CFG17_BIG_ADDR(base) ((base) + 0xA5C)
#define SOC_CORE_CPU_CRG_FCG_CFG18_BIG_ADDR(base) ((base) + 0xA60)
#define SOC_CORE_CPU_CRG_FCG_CFG19_BIG_ADDR(base) ((base) + 0xA64)
#define SOC_CORE_CPU_CRG_FCG_CFG20_BIG_ADDR(base) ((base) + 0xA68)
#define SOC_CORE_CPU_CRG_FCG_CFG21_BIG_ADDR(base) ((base) + 0xA6C)
#define SOC_CORE_CPU_CRG_FCG_CFG22_BIG_ADDR(base) ((base) + 0xA70)
#define SOC_CORE_CPU_CRG_FCG_CFG23_BIG_ADDR(base) ((base) + 0xA74)
#define SOC_CORE_CPU_CRG_FCG_CFG24_BIG_ADDR(base) ((base) + 0xA78)
#define SOC_CORE_CPU_CRG_FCG_CFG25_BIG_ADDR(base) ((base) + 0xA7C)
#define SOC_CORE_CPU_CRG_FCG_CFG26_BIG_ADDR(base) ((base) + 0xA80)
#define SOC_CORE_CPU_CRG_FCG_CFG27_BIG_ADDR(base) ((base) + 0xA84)
#define SOC_CORE_CPU_CRG_FCG_STAT0_BIG_ADDR(base) ((base) + 0xA90)
#define SOC_CORE_CPU_CRG_FCG_STAT1_BIG_ADDR(base) ((base) + 0xA94)
#define SOC_CORE_CPU_CRG_FCG_STAT2_BIG_ADDR(base) ((base) + 0xA98)
#define SOC_CORE_CPU_CRG_FCG_STAT3_BIG_ADDR(base) ((base) + 0xA9C)
#define SOC_CORE_CPU_CRG_FCG_STAT4_BIG_ADDR(base) ((base) + 0xAA0)
#define SOC_CORE_CPU_CRG_FCG_STAT5_BIG_ADDR(base) ((base) + 0xAA4)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_LITTLE_ADDR(base) ((base) + 0xB00)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_LITTLE_ADDR(base) ((base) + 0xB04)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_LITTLE_ADDR(base) ((base) + 0xB08)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_LITTLE_ADDR(base) ((base) + 0xB0C)
#define SOC_CORE_CPU_CRG_FCG_CFG0_LITTLE_ADDR(base) ((base) + 0xB18)
#define SOC_CORE_CPU_CRG_FCG_CFG1_LITTLE_ADDR(base) ((base) + 0xB1C)
#define SOC_CORE_CPU_CRG_FCG_CFG2_LITTLE_ADDR(base) ((base) + 0xB20)
#define SOC_CORE_CPU_CRG_FCG_CFG3_LITTLE_ADDR(base) ((base) + 0xB24)
#define SOC_CORE_CPU_CRG_FCG_CFG4_LITTLE_ADDR(base) ((base) + 0xB28)
#define SOC_CORE_CPU_CRG_FCG_CFG5_LITTLE_ADDR(base) ((base) + 0xB2C)
#define SOC_CORE_CPU_CRG_FCG_CFG6_LITTLE_ADDR(base) ((base) + 0xB30)
#define SOC_CORE_CPU_CRG_FCG_CFG7_LITTLE_ADDR(base) ((base) + 0xB34)
#define SOC_CORE_CPU_CRG_FCG_CFG8_LITTLE_ADDR(base) ((base) + 0xB38)
#define SOC_CORE_CPU_CRG_FCG_CFG9_LITTLE_ADDR(base) ((base) + 0xB3C)
#define SOC_CORE_CPU_CRG_FCG_CFG10_LITTLE_ADDR(base) ((base) + 0xB40)
#define SOC_CORE_CPU_CRG_FCG_CFG11_LITTLE_ADDR(base) ((base) + 0xB44)
#define SOC_CORE_CPU_CRG_FCG_CFG12_LITTLE_ADDR(base) ((base) + 0xB48)
#define SOC_CORE_CPU_CRG_FCG_CFG13_LITTLE_ADDR(base) ((base) + 0xB4C)
#define SOC_CORE_CPU_CRG_FCG_CFG14_LITTLE_ADDR(base) ((base) + 0xB50)
#define SOC_CORE_CPU_CRG_FCG_CFG15_LITTLE_ADDR(base) ((base) + 0xB54)
#define SOC_CORE_CPU_CRG_FCG_CFG16_LITTLE_ADDR(base) ((base) + 0xB58)
#define SOC_CORE_CPU_CRG_FCG_CFG17_LITTLE_ADDR(base) ((base) + 0xB5C)
#define SOC_CORE_CPU_CRG_FCG_CFG18_LITTLE_ADDR(base) ((base) + 0xB60)
#define SOC_CORE_CPU_CRG_FCG_CFG19_LITTLE_ADDR(base) ((base) + 0xB64)
#define SOC_CORE_CPU_CRG_FCG_CFG20_LITTLE_ADDR(base) ((base) + 0xB68)
#define SOC_CORE_CPU_CRG_FCG_CFG21_LITTLE_ADDR(base) ((base) + 0xB6C)
#define SOC_CORE_CPU_CRG_FCG_CFG22_LITTLE_ADDR(base) ((base) + 0xB70)
#define SOC_CORE_CPU_CRG_FCG_CFG23_LITTLE_ADDR(base) ((base) + 0xB74)
#define SOC_CORE_CPU_CRG_FCG_CFG24_LITTLE_ADDR(base) ((base) + 0xB78)
#define SOC_CORE_CPU_CRG_FCG_CFG25_LITTLE_ADDR(base) ((base) + 0xB7C)
#define SOC_CORE_CPU_CRG_FCG_CFG26_LITTLE_ADDR(base) ((base) + 0xB80)
#define SOC_CORE_CPU_CRG_FCG_CFG27_LITTLE_ADDR(base) ((base) + 0xB84)
#define SOC_CORE_CPU_CRG_FCG_STAT0_LITTLE_ADDR(base) ((base) + 0xB90)
#define SOC_CORE_CPU_CRG_FCG_STAT1_LITTLE_ADDR(base) ((base) + 0xB94)
#define SOC_CORE_CPU_CRG_FCG_STAT2_LITTLE_ADDR(base) ((base) + 0xB98)
#define SOC_CORE_CPU_CRG_FCG_STAT3_LITTLE_ADDR(base) ((base) + 0xB9C)
#define SOC_CORE_CPU_CRG_FCG_STAT4_LITTLE_ADDR(base) ((base) + 0xBA0)
#define SOC_CORE_CPU_CRG_FCG_STAT5_LITTLE_ADDR(base) ((base) + 0xBA4)
#define SOC_CORE_CPU_CRG_CALIBRATION1_ADDR(base) ((base) + 0xF00)
#define SOC_CORE_CPU_CRG_CALIBRATION2_ADDR(base) ((base) + 0xF04)
#define SOC_CORE_CPU_CRG_TS_CFG_ADDR(base) ((base) + 0xF08)
#define SOC_CORE_CPU_CRG_DATA_ADDR(base) ((base) + 0xF0C)
#define SOC_CORE_CPU_CRG_DATA_MIN_ADDR(base) ((base) + 0xF10)
#define SOC_CORE_CPU_CRG_DATA_MAX_ADDR(base) ((base) + 0xF14)
#define SOC_CORE_CPU_CRG_TS_RSV_CTRL_ADDR(base) ((base) + 0xF18)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_fcg_sscg_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_little_dpm : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_dcc_ref : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int gt_clk_pim_little : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int gt_clk_fcg_freq_ctrl_little : 1;
        unsigned int gt_pclk_fcg_little : 1;
        unsigned int gt_clk_fdcs_mon_little : 1;
        unsigned int reserved_16 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PEREN0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_little_dpm_START (7)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_little_dpm_END (7)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_dcc_ref_START (15)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_dcc_ref_END (15)
#define SOC_CORE_CPU_CRG_PEREN0_gt_pclk_onsys_avs_cpu_START (16)
#define SOC_CORE_CPU_CRG_PEREN0_gt_pclk_onsys_avs_cpu_END (16)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_pim_little_START (20)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_pim_little_END (20)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fdcs_xpu_ctrl_little_START (21)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fdcs_xpu_ctrl_little_END (21)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fcg_freq_ctrl_little_START (22)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fcg_freq_ctrl_little_END (22)
#define SOC_CORE_CPU_CRG_PEREN0_gt_pclk_fcg_little_START (23)
#define SOC_CORE_CPU_CRG_PEREN0_gt_pclk_fcg_little_END (23)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fdcs_mon_little_START (24)
#define SOC_CORE_CPU_CRG_PEREN0_gt_clk_fdcs_mon_little_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_fcg_sscg_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_little_dpm : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_dcc_ref : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int gt_clk_pim_little : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int gt_clk_fcg_freq_ctrl_little : 1;
        unsigned int gt_pclk_fcg_little : 1;
        unsigned int gt_clk_fdcs_mon_little : 1;
        unsigned int reserved_16 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PERDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_little_dpm_START (7)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_little_dpm_END (7)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_dcc_ref_START (15)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_dcc_ref_END (15)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_pclk_onsys_avs_cpu_START (16)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_pclk_onsys_avs_cpu_END (16)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_pim_little_START (20)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_pim_little_END (20)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fdcs_xpu_ctrl_little_START (21)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fdcs_xpu_ctrl_little_END (21)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fcg_freq_ctrl_little_START (22)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fcg_freq_ctrl_little_END (22)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_pclk_fcg_little_START (23)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_pclk_fcg_little_END (23)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fdcs_mon_little_START (24)
#define SOC_CORE_CPU_CRG_PERDIS0_gt_clk_fdcs_mon_little_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_fcg_sscg_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_little_dpm : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int gt_clk_dcc_ref : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int gt_clk_pim_little : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int gt_clk_fcg_freq_ctrl_little : 1;
        unsigned int gt_pclk_fcg_little : 1;
        unsigned int gt_clk_fdcs_mon_little : 1;
        unsigned int reserved_16 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PERCLKEN0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_little_dpm_START (7)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_little_dpm_END (7)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_dcc_ref_START (15)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_dcc_ref_END (15)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_pclk_onsys_avs_cpu_START (16)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_pclk_onsys_avs_cpu_END (16)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_pim_little_START (20)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_pim_little_END (20)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_little_START (21)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_little_END (21)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fcg_freq_ctrl_little_START (22)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fcg_freq_ctrl_little_END (22)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_pclk_fcg_little_START (23)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_pclk_fcg_little_END (23)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fdcs_mon_little_START (24)
#define SOC_CORE_CPU_CRG_PERCLKEN0_gt_clk_fdcs_mon_little_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_fcg_sscg_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_clk_little_dpm : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int st_clk_dcc_ref : 1;
        unsigned int st_pclk_onsys_avs_cpu : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int st_clk_pim_little : 1;
        unsigned int st_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int st_clk_fcg_freq_ctrl_little : 1;
        unsigned int st_pclk_fcg_little : 1;
        unsigned int st_clk_fdcs_mon_little : 1;
        unsigned int reserved_16 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PERSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_little_dpm_START (7)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_little_dpm_END (7)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_dcc_ref_START (15)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_dcc_ref_END (15)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_pclk_onsys_avs_cpu_START (16)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_pclk_onsys_avs_cpu_END (16)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_pim_little_START (20)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_pim_little_END (20)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fdcs_xpu_ctrl_little_START (21)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fdcs_xpu_ctrl_little_END (21)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fcg_freq_ctrl_little_START (22)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fcg_freq_ctrl_little_END (22)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_pclk_fcg_little_START (23)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_pclk_fcg_little_END (23)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fdcs_mon_little_START (24)
#define SOC_CORE_CPU_CRG_PERSTAT0_st_clk_fdcs_mon_little_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_dcd : 1;
        unsigned int gt_pclk_dcc_cpum : 1;
        unsigned int gt_pclk_dcc_cpub : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_big_dpm : 1;
        unsigned int gt_clk_middle_dpm : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_pim_big : 1;
        unsigned int gt_clk_pim_middle : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int gt_clk_fdcs_mon_big : 1;
        unsigned int gt_clk_fdcs_mon_middle : 1;
        unsigned int gt_clk_fcg_freq_ctrl_big : 1;
        unsigned int gt_clk_fcg_freq_ctrl_middle : 1;
        unsigned int gt_clk_fcg_sscg_big : 1;
        unsigned int gt_clk_fcg_sscg_middle : 1;
        unsigned int gt_pclk_fcg_big : 1;
        unsigned int gt_pclk_fcg_middle : 1;
        unsigned int reserved_8 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PEREN1_UNION;
#endif
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_dcd_START (0)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_dcd_END (0)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_dcc_cpum_START (1)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_dcc_cpum_END (1)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_dcc_cpub_START (2)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_dcc_cpub_END (2)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_big_dpm_START (6)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_big_dpm_END (6)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_middle_dpm_START (7)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_middle_dpm_END (7)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_pim_big_START (13)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_pim_big_END (13)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_pim_middle_START (14)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_pim_middle_END (14)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_xpu_ctrl_big_START (15)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_xpu_ctrl_big_END (15)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_xpu_ctrl_middle_START (16)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_xpu_ctrl_middle_END (16)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_mon_big_START (17)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_mon_big_END (17)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_mon_middle_START (18)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fdcs_mon_middle_END (18)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_freq_ctrl_big_START (19)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_freq_ctrl_big_END (19)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_freq_ctrl_middle_START (20)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_freq_ctrl_middle_END (20)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_sscg_big_START (21)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_sscg_big_END (21)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_sscg_middle_START (22)
#define SOC_CORE_CPU_CRG_PEREN1_gt_clk_fcg_sscg_middle_END (22)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_fcg_big_START (23)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_fcg_big_END (23)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_fcg_middle_START (24)
#define SOC_CORE_CPU_CRG_PEREN1_gt_pclk_fcg_middle_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_dcd : 1;
        unsigned int gt_pclk_dcc_cpum : 1;
        unsigned int gt_pclk_dcc_cpub : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_big_dpm : 1;
        unsigned int gt_clk_middle_dpm : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_pim_big : 1;
        unsigned int gt_clk_pim_middle : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int gt_clk_fdcs_mon_big : 1;
        unsigned int gt_clk_fdcs_mon_middle : 1;
        unsigned int gt_clk_fcg_freq_ctrl_big : 1;
        unsigned int gt_clk_fcg_freq_ctrl_middle : 1;
        unsigned int gt_clk_fcg_sscg_big : 1;
        unsigned int gt_clk_fcg_sscg_middle : 1;
        unsigned int gt_pclk_fcg_big : 1;
        unsigned int gt_pclk_fcg_middle : 1;
        unsigned int reserved_8 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PERDIS1_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_dcd_START (0)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_dcd_END (0)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_dcc_cpum_START (1)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_dcc_cpum_END (1)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_dcc_cpub_START (2)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_dcc_cpub_END (2)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_big_dpm_START (6)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_big_dpm_END (6)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_middle_dpm_START (7)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_middle_dpm_END (7)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_pim_big_START (13)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_pim_big_END (13)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_pim_middle_START (14)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_pim_middle_END (14)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_xpu_ctrl_big_START (15)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_xpu_ctrl_big_END (15)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_xpu_ctrl_middle_START (16)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_xpu_ctrl_middle_END (16)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_mon_big_START (17)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_mon_big_END (17)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_mon_middle_START (18)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fdcs_mon_middle_END (18)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_freq_ctrl_big_START (19)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_freq_ctrl_big_END (19)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_freq_ctrl_middle_START (20)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_freq_ctrl_middle_END (20)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_sscg_big_START (21)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_sscg_big_END (21)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_sscg_middle_START (22)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_clk_fcg_sscg_middle_END (22)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_fcg_big_START (23)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_fcg_big_END (23)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_fcg_middle_START (24)
#define SOC_CORE_CPU_CRG_PERDIS1_gt_pclk_fcg_middle_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_dcd : 1;
        unsigned int gt_pclk_dcc_cpum : 1;
        unsigned int gt_pclk_dcc_cpub : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_big_dpm : 1;
        unsigned int gt_clk_middle_dpm : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_pim_big : 1;
        unsigned int gt_clk_pim_middle : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int gt_clk_fdcs_mon_big : 1;
        unsigned int gt_clk_fdcs_mon_middle : 1;
        unsigned int gt_clk_fcg_freq_ctrl_big : 1;
        unsigned int gt_clk_fcg_freq_ctrl_middle : 1;
        unsigned int gt_clk_fcg_sscg_big : 1;
        unsigned int gt_clk_fcg_sscg_middle : 1;
        unsigned int gt_pclk_fcg_big : 1;
        unsigned int gt_pclk_fcg_middle : 1;
        unsigned int reserved_8 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PERCLKEN1_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_dcd_START (0)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_dcd_END (0)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_dcc_cpum_START (1)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_dcc_cpum_END (1)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_dcc_cpub_START (2)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_dcc_cpub_END (2)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_big_dpm_START (6)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_big_dpm_END (6)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_middle_dpm_START (7)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_middle_dpm_END (7)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_pim_big_START (13)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_pim_big_END (13)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_pim_middle_START (14)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_pim_middle_END (14)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_xpu_ctrl_big_START (15)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_xpu_ctrl_big_END (15)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_xpu_ctrl_middle_START (16)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_xpu_ctrl_middle_END (16)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_mon_big_START (17)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_mon_big_END (17)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_mon_middle_START (18)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fdcs_mon_middle_END (18)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_freq_ctrl_big_START (19)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_freq_ctrl_big_END (19)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_freq_ctrl_middle_START (20)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_freq_ctrl_middle_END (20)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_sscg_big_START (21)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_sscg_big_END (21)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_sscg_middle_START (22)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_clk_fcg_sscg_middle_END (22)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_fcg_big_START (23)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_fcg_big_END (23)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_fcg_middle_START (24)
#define SOC_CORE_CPU_CRG_PERCLKEN1_gt_pclk_fcg_middle_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_pclk_dcd : 1;
        unsigned int st_pclk_dcc_cpum : 1;
        unsigned int st_pclk_dcc_cpub : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_big_dpm : 1;
        unsigned int st_clk_middle_dpm : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int st_clk_pim_big : 1;
        unsigned int st_clk_pim_middle : 1;
        unsigned int st_clk_fdcs_xpu_ctrl_big : 1;
        unsigned int st_clk_fdcs_xpu_ctrl_middle : 1;
        unsigned int st_clk_fdcs_mon_big : 1;
        unsigned int st_clk_fdcs_mon_middle : 1;
        unsigned int st_clk_fcg_freq_ctrl_big : 1;
        unsigned int st_clk_fcg_freq_ctrl_middle : 1;
        unsigned int st_clk_fcg_sscg_big : 1;
        unsigned int st_clk_fcg_sscg_middle : 1;
        unsigned int st_pclk_fcg_big : 1;
        unsigned int st_pclk_fcg_middle : 1;
        unsigned int reserved_8 : 7;
    } reg;
} SOC_CORE_CPU_CRG_PERSTAT1_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_dcd_START (0)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_dcd_END (0)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_dcc_cpum_START (1)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_dcc_cpum_END (1)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_dcc_cpub_START (2)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_dcc_cpub_END (2)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_big_dpm_START (6)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_big_dpm_END (6)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_middle_dpm_START (7)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_middle_dpm_END (7)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_pim_big_START (13)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_pim_big_END (13)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_pim_middle_START (14)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_pim_middle_END (14)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_xpu_ctrl_big_START (15)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_xpu_ctrl_big_END (15)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_xpu_ctrl_middle_START (16)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_xpu_ctrl_middle_END (16)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_mon_big_START (17)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_mon_big_END (17)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_mon_middle_START (18)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fdcs_mon_middle_END (18)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_freq_ctrl_big_START (19)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_freq_ctrl_big_END (19)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_freq_ctrl_middle_START (20)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_freq_ctrl_middle_END (20)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_sscg_big_START (21)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_sscg_big_END (21)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_sscg_middle_START (22)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_clk_fcg_sscg_middle_END (22)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_fcg_big_START (23)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_fcg_big_END (23)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_fcg_middle_START (24)
#define SOC_CORE_CPU_CRG_PERSTAT1_st_pclk_fcg_middle_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_fcg_big : 1;
        unsigned int ip_prst_fcg_middle : 1;
        unsigned int ip_prst_fcg_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_big : 1;
        unsigned int ip_rst_fcg_freq_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_mon_big : 1;
        unsigned int ip_rst_fdcs_mon_middle : 1;
        unsigned int ip_rst_fdcs_mon_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_little : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_big : 1;
        unsigned int ip_rst_dcc_cpub : 1;
        unsigned int ip_rst_dcc_cpum : 1;
        unsigned int ip_rst_dcd : 1;
    } reg;
} SOC_CORE_CPU_CRG_PERRSTEN0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_fcg_big_START (0)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_fcg_big_END (0)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_fcg_middle_START (1)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_fcg_middle_END (1)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_fcg_little_START (2)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_fcg_little_END (2)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_big_START (4)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_big_END (4)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_middle_START (5)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fcg_freq_ctrl_middle_END (5)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_mon_big_START (6)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_mon_big_END (6)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_mon_middle_START (7)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_mon_middle_END (7)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_mon_little_START (8)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_mon_little_END (8)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_onsys_avs_cpu_START (16)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_prst_onsys_avs_cpu_END (16)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_little_START (26)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_little_END (26)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_middle_START (27)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_middle_END (27)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_big_START (28)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_big_END (28)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_dcc_cpub_START (29)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_dcc_cpub_END (29)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_dcc_cpum_START (30)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_dcc_cpum_END (30)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_dcd_START (31)
#define SOC_CORE_CPU_CRG_PERRSTEN0_ip_rst_dcd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_fcg_big : 1;
        unsigned int ip_prst_fcg_middle : 1;
        unsigned int ip_prst_fcg_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_big : 1;
        unsigned int ip_rst_fcg_freq_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_mon_big : 1;
        unsigned int ip_rst_fdcs_mon_middle : 1;
        unsigned int ip_rst_fdcs_mon_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_little : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_big : 1;
        unsigned int ip_rst_dcc_cpub : 1;
        unsigned int ip_rst_dcc_cpum : 1;
        unsigned int ip_rst_dcd : 1;
    } reg;
} SOC_CORE_CPU_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_fcg_big_START (0)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_fcg_big_END (0)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_fcg_middle_START (1)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_fcg_middle_END (1)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_fcg_little_START (2)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_fcg_little_END (2)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_big_START (4)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_big_END (4)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_middle_START (5)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fcg_freq_ctrl_middle_END (5)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_mon_big_START (6)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_mon_big_END (6)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_mon_middle_START (7)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_mon_middle_END (7)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_mon_little_START (8)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_mon_little_END (8)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_onsys_avs_cpu_START (16)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_prst_onsys_avs_cpu_END (16)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_little_START (26)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_little_END (26)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_middle_START (27)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_middle_END (27)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_big_START (28)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_big_END (28)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_dcc_cpub_START (29)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_dcc_cpub_END (29)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_dcc_cpum_START (30)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_dcc_cpum_END (30)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_dcd_START (31)
#define SOC_CORE_CPU_CRG_PERRSTDIS0_ip_rst_dcd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_fcg_big : 1;
        unsigned int ip_prst_fcg_middle : 1;
        unsigned int ip_prst_fcg_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_big : 1;
        unsigned int ip_rst_fcg_freq_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_mon_big : 1;
        unsigned int ip_rst_fdcs_mon_middle : 1;
        unsigned int ip_rst_fdcs_mon_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_little : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_middle : 1;
        unsigned int ip_rst_fdcs_xpu_ctrl_big : 1;
        unsigned int ip_rst_dcc_cpub : 1;
        unsigned int ip_rst_dcc_cpum : 1;
        unsigned int ip_rst_dcd : 1;
    } reg;
} SOC_CORE_CPU_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_fcg_big_START (0)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_fcg_big_END (0)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_fcg_middle_START (1)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_fcg_middle_END (1)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_fcg_little_START (2)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_fcg_little_END (2)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_big_START (4)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_big_END (4)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_middle_START (5)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_middle_END (5)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_mon_big_START (6)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_mon_big_END (6)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_mon_middle_START (7)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_mon_middle_END (7)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_mon_little_START (8)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_mon_little_END (8)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_onsys_avs_cpu_START (16)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_prst_onsys_avs_cpu_END (16)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_little_START (26)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_little_END (26)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_middle_START (27)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_middle_END (27)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_big_START (28)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_big_END (28)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_dcc_cpub_START (29)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_dcc_cpub_END (29)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_dcc_cpum_START (30)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_dcc_cpum_END (30)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_dcd_START (31)
#define SOC_CORE_CPU_CRG_PERRSTSTAT0_ip_rst_dcd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_cpu_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int sw_ack_clk_cpul_pll_final_sw : 2;
        unsigned int reserved_1 : 2;
        unsigned int fcg_sscg_idle_little : 1;
        unsigned int reserved_2 : 1;
        unsigned int sw_ack_clk_cpum_pll_sw : 2;
        unsigned int freq_dn_flag_little : 1;
        unsigned int cpu_l2_idle_aft_cpul : 1;
        unsigned int reserved_3 : 20;
    } reg;
} SOC_CORE_CPU_CRG_PERI_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERI_STAT0_st_clk_cpu_little_START (0)
#define SOC_CORE_CPU_CRG_PERI_STAT0_st_clk_cpu_little_END (0)
#define SOC_CORE_CPU_CRG_PERI_STAT0_sw_ack_clk_cpul_pll_final_sw_START (2)
#define SOC_CORE_CPU_CRG_PERI_STAT0_sw_ack_clk_cpul_pll_final_sw_END (3)
#define SOC_CORE_CPU_CRG_PERI_STAT0_fcg_sscg_idle_little_START (6)
#define SOC_CORE_CPU_CRG_PERI_STAT0_fcg_sscg_idle_little_END (6)
#define SOC_CORE_CPU_CRG_PERI_STAT0_sw_ack_clk_cpum_pll_sw_START (8)
#define SOC_CORE_CPU_CRG_PERI_STAT0_sw_ack_clk_cpum_pll_sw_END (9)
#define SOC_CORE_CPU_CRG_PERI_STAT0_freq_dn_flag_little_START (10)
#define SOC_CORE_CPU_CRG_PERI_STAT0_freq_dn_flag_little_END (10)
#define SOC_CORE_CPU_CRG_PERI_STAT0_cpu_l2_idle_aft_cpul_START (11)
#define SOC_CORE_CPU_CRG_PERI_STAT0_cpu_l2_idle_aft_cpul_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_cpu_big0 : 1;
        unsigned int st_clk_cpu_middle0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int fcg_sscg_idle_big : 1;
        unsigned int fcg_sscg_idle_middle : 1;
        unsigned int freq_dn_flag_big : 1;
        unsigned int freq_dn_flag_middle : 1;
        unsigned int cpu_l2_idle_aft_cpum : 1;
        unsigned int cpu_l2_idle_aft_cpub : 1;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_CORE_CPU_CRG_PERI_STAT1_UNION;
#endif
#define SOC_CORE_CPU_CRG_PERI_STAT1_st_clk_cpu_big0_START (0)
#define SOC_CORE_CPU_CRG_PERI_STAT1_st_clk_cpu_big0_END (0)
#define SOC_CORE_CPU_CRG_PERI_STAT1_st_clk_cpu_middle0_START (1)
#define SOC_CORE_CPU_CRG_PERI_STAT1_st_clk_cpu_middle0_END (1)
#define SOC_CORE_CPU_CRG_PERI_STAT1_fcg_sscg_idle_big_START (4)
#define SOC_CORE_CPU_CRG_PERI_STAT1_fcg_sscg_idle_big_END (4)
#define SOC_CORE_CPU_CRG_PERI_STAT1_fcg_sscg_idle_middle_START (5)
#define SOC_CORE_CPU_CRG_PERI_STAT1_fcg_sscg_idle_middle_END (5)
#define SOC_CORE_CPU_CRG_PERI_STAT1_freq_dn_flag_big_START (6)
#define SOC_CORE_CPU_CRG_PERI_STAT1_freq_dn_flag_big_END (6)
#define SOC_CORE_CPU_CRG_PERI_STAT1_freq_dn_flag_middle_START (7)
#define SOC_CORE_CPU_CRG_PERI_STAT1_freq_dn_flag_middle_END (7)
#define SOC_CORE_CPU_CRG_PERI_STAT1_cpu_l2_idle_aft_cpum_START (8)
#define SOC_CORE_CPU_CRG_PERI_STAT1_cpu_l2_idle_aft_cpum_END (8)
#define SOC_CORE_CPU_CRG_PERI_STAT1_cpu_l2_idle_aft_cpub_START (9)
#define SOC_CORE_CPU_CRG_PERI_STAT1_cpu_l2_idle_aft_cpub_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_clk_out1_cpu : 2;
        unsigned int sc_gt_clk_big_dpm : 1;
        unsigned int sc_gt_clk_middle_dpm : 1;
        unsigned int sc_gt_clk_little_dpm : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int div_little_dpm : 6;
        unsigned int sc_gt_clk_out1_fcg_tp : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_CLKDIV0_UNION;
#endif
#define SOC_CORE_CPU_CRG_CLKDIV0_sel_clk_out1_cpu_START (0)
#define SOC_CORE_CPU_CRG_CLKDIV0_sel_clk_out1_cpu_END (1)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_big_dpm_START (2)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_big_dpm_END (2)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_middle_dpm_START (3)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_middle_dpm_END (3)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_little_dpm_START (4)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_little_dpm_END (4)
#define SOC_CORE_CPU_CRG_CLKDIV0_div_little_dpm_START (9)
#define SOC_CORE_CPU_CRG_CLKDIV0_div_little_dpm_END (14)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_out1_fcg_tp_START (15)
#define SOC_CORE_CPU_CRG_CLKDIV0_sc_gt_clk_out1_fcg_tp_END (15)
#define SOC_CORE_CPU_CRG_CLKDIV0_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_middle_dpm : 6;
        unsigned int div_big_dpm : 6;
        unsigned int reserved : 1;
        unsigned int sel_test_mce_cpul : 1;
        unsigned int sel_clk_cpul_path : 1;
        unsigned int sel_clk_dcd : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_CLKDIV1_UNION;
#endif
#define SOC_CORE_CPU_CRG_CLKDIV1_div_middle_dpm_START (0)
#define SOC_CORE_CPU_CRG_CLKDIV1_div_middle_dpm_END (5)
#define SOC_CORE_CPU_CRG_CLKDIV1_div_big_dpm_START (6)
#define SOC_CORE_CPU_CRG_CLKDIV1_div_big_dpm_END (11)
#define SOC_CORE_CPU_CRG_CLKDIV1_sel_test_mce_cpul_START (13)
#define SOC_CORE_CPU_CRG_CLKDIV1_sel_test_mce_cpul_END (13)
#define SOC_CORE_CPU_CRG_CLKDIV1_sel_clk_cpul_path_START (14)
#define SOC_CORE_CPU_CRG_CLKDIV1_sel_clk_cpul_path_END (14)
#define SOC_CORE_CPU_CRG_CLKDIV1_sel_clk_dcd_START (15)
#define SOC_CORE_CPU_CRG_CLKDIV1_sel_clk_dcd_END (15)
#define SOC_CORE_CPU_CRG_CLKDIV1_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_test_ram_src : 2;
        unsigned int div_out1_fcg_tp : 6;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_CLKDIV2_UNION;
#endif
#define SOC_CORE_CPU_CRG_CLKDIV2_sel_test_ram_src_START (0)
#define SOC_CORE_CPU_CRG_CLKDIV2_sel_test_ram_src_END (1)
#define SOC_CORE_CPU_CRG_CLKDIV2_div_out1_fcg_tp_START (2)
#define SOC_CORE_CPU_CRG_CLKDIV2_div_out1_fcg_tp_END (7)
#define SOC_CORE_CPU_CRG_CLKDIV2_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_CLKDIV2_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_pim_drop_en_bypass_START (0)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_pim_drop_en_bypass_END (0)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_pim_peaklow_en_bypass_START (1)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_pim_peaklow_en_bypass_END (1)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_pim_drop_update_bypass_START (2)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_pim_drop_update_bypass_END (2)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_cnt_thr_START (3)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_cnt_thr_END (6)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_ffc_en_bypass_START (7)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_ffc_en_bypass_END (7)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_ffc_cnt_thr_START (8)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_ffc_cnt_thr_END (9)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_BIG_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_pim_drop_en_bypass_START (0)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_pim_drop_en_bypass_END (0)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_pim_peaklow_en_bypass_START (1)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_pim_peaklow_en_bypass_END (1)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_pim_drop_update_bypass_START (2)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_pim_drop_update_bypass_END (2)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_cnt_thr_START (3)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_cnt_thr_END (6)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_ffc_en_bypass_START (7)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_ffc_en_bypass_END (7)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_ffc_cnt_thr_START (8)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_ffc_cnt_thr_END (9)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_MIDDLE_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_pim_drop_en_bypass_START (0)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_pim_drop_en_bypass_END (0)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_pim_peaklow_en_bypass_START (1)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_pim_peaklow_en_bypass_END (1)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_pim_drop_update_bypass_START (2)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_pim_drop_update_bypass_END (2)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_cnt_thr_START (3)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_cnt_thr_END (6)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_ffc_en_bypass_START (7)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_ffc_en_bypass_END (7)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_ffc_cnt_thr_START (8)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_ffc_cnt_thr_END (9)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_FDCS_XPU_CFG_LITTLE_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_pcr_trig_vdm_en_START (0)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_pcr_trig_vdm_en_END (0)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_wfx_bypass_START (1)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_wfx_bypass_END (4)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_l2_idle_div_mod_START (5)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_l2_idle_div_mod_END (5)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_freq_dn_mst_sel_START (6)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_freq_dn_mst_sel_END (6)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_wake_up_mode_START (23)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_wake_up_mode_END (24)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_l2_idle_gt_en_START (26)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_cpu_l2_idle_gt_en_END (26)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_vbat_drop_icg_en_START (27)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_vbat_drop_icg_en_END (27)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_vbat_drop_fcg_en_START (28)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_vbat_drop_fcg_en_END (28)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_coreidle_bypass_START (29)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_coreidle_bypass_END (29)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_pcr_fs_icg_en_START (30)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_pcr_fs_icg_en_END (30)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_pcr_fs_fcg_en_START (31)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_BIG_pcr_fs_fcg_en_END (31)
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
} SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_pcr_trig_vdm_en_START (0)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_pcr_trig_vdm_en_END (0)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_wfx_bypass_START (1)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_wfx_bypass_END (4)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_l2_idle_div_mod_START (5)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_l2_idle_div_mod_END (5)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_freq_dn_mst_sel_START (6)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_freq_dn_mst_sel_END (6)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_wake_up_mode_START (23)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_wake_up_mode_END (24)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_gt_en_START (26)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_cpu_l2_idle_gt_en_END (26)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_vbat_drop_icg_en_START (27)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_vbat_drop_icg_en_END (27)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_vbat_drop_fcg_en_START (28)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_vbat_drop_fcg_en_END (28)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_coreidle_bypass_START (29)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_coreidle_bypass_END (29)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_pcr_fs_icg_en_START (30)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_pcr_fs_icg_en_END (30)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_pcr_fs_fcg_en_START (31)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_MIDDLE_pcr_fs_fcg_en_END (31)
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
} SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_pcr_trig_vdm_en_START (0)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_pcr_trig_vdm_en_END (0)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_wfx_bypass_START (1)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_wfx_bypass_END (4)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_l2_idle_div_mod_START (5)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_l2_idle_div_mod_END (5)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_freq_dn_mst_sel_START (6)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_freq_dn_mst_sel_END (6)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_wake_up_mode_START (23)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_wake_up_mode_END (24)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_gt_en_START (26)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_gt_en_END (26)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_vbat_drop_icg_en_START (27)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_vbat_drop_icg_en_END (27)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_vbat_drop_fcg_en_START (28)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_vbat_drop_fcg_en_END (28)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_coreidle_bypass_START (29)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_coreidle_bypass_END (29)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_pcr_fs_icg_en_START (30)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_pcr_fs_icg_en_END (30)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_pcr_fs_fcg_en_START (31)
#define SOC_CORE_CPU_CRG_FCG_FREQ_CTRL_LITTLE_pcr_fs_fcg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg_rsv_big : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG_RSV0_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV0_fcg_cfg_rsv_big_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV0_fcg_cfg_rsv_big_END (15)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV0_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg_rsv_middle : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG_RSV1_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV1_fcg_cfg_rsv_middle_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV1_fcg_cfg_rsv_middle_END (15)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV1_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg_rsv_little : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG_RSV2_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV2_fcg_cfg_rsv_little_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV2_fcg_cfg_rsv_little_END (15)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV2_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_FCG_CFG_RSV2_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_enable_START (0)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_enable_END (0)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_mode_START (1)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_mode_END (1)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_rate_START (2)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_rate_END (5)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_depth_START (6)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_depth_END (8)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_fast_dis_START (9)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_sscg_fast_dis_END (9)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_LITTLE_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_enable_START (0)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_enable_END (0)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_mode_START (1)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_mode_END (1)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_rate_START (2)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_rate_END (5)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_depth_START (6)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_depth_END (8)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_fast_dis_START (9)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_sscg_fast_dis_END (9)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_BIG_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_enable_START (0)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_enable_END (0)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_mode_START (1)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_mode_END (1)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_rate_START (2)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_rate_END (5)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_depth_START (6)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_depth_END (8)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_fast_dis_START (9)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_sscg_fast_dis_END (9)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_SSC_FCG_CFG_MIDDLE_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat_little : 16;
        unsigned int fcg_stat_middle : 16;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT0_fcg_stat_little_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT0_fcg_stat_little_END (15)
#define SOC_CORE_CPU_CRG_FCG_STAT0_fcg_stat_middle_START (16)
#define SOC_CORE_CPU_CRG_FCG_STAT0_fcg_stat_middle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat_big : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT1_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT1_fcg_stat_big_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT1_fcg_stat_big_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_cpu_little : 1;
        unsigned int gt_clk_cpu_big0 : 1;
        unsigned int gt_clk_cpu_middle0 : 1;
        unsigned int reserved_1 : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_FCM_CLKEN_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCM_CLKEN_gt_clk_cpu_little_START (1)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_gt_clk_cpu_little_END (1)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_gt_clk_cpu_big0_START (2)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_gt_clk_cpu_big0_END (2)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_gt_clk_cpu_middle0_START (3)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_gt_clk_cpu_middle0_END (3)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_FCM_CLKEN_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_RSV_CFG0_UNION;
#endif
#define SOC_CORE_CPU_CRG_RSV_CFG0_rsv_cfg0_START (0)
#define SOC_CORE_CPU_CRG_RSV_CFG0_rsv_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_RSV_CFG1_UNION;
#endif
#define SOC_CORE_CPU_CRG_RSV_CFG1_rsv_cfg1_START (0)
#define SOC_CORE_CPU_CRG_RSV_CFG1_rsv_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_RSV_CFG2_UNION;
#endif
#define SOC_CORE_CPU_CRG_RSV_CFG2_rsv_cfg2_START (0)
#define SOC_CORE_CPU_CRG_RSV_CFG2_rsv_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_jm_clk_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int sc_jm_rst_n : 1;
        unsigned int sc_one2two_cyc : 1;
        unsigned int sc_timing_ctrl_en : 1;
        unsigned int sc_dtc_start : 1;
        unsigned int sc_fdtc_rev : 1;
        unsigned int sc_cdtc_rev : 1;
        unsigned int sc_max2min_cyc : 5;
        unsigned int reserved_1 : 3;
        unsigned int sc_dtc_margin : 10;
        unsigned int reserved_2 : 1;
        unsigned int sc_cdtc_gap : 5;
    } reg;
} SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_UNION;
#endif
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_jm_clk_en_START (0)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_jm_clk_en_END (0)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_jm_rst_n_START (2)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_jm_rst_n_END (2)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_one2two_cyc_START (3)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_one2two_cyc_END (3)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_timing_ctrl_en_START (4)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_timing_ctrl_en_END (4)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_dtc_start_START (5)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_dtc_start_END (5)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_fdtc_rev_START (6)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_fdtc_rev_END (6)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_cdtc_rev_START (7)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_cdtc_rev_END (7)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_max2min_cyc_START (8)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_max2min_cyc_END (12)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_dtc_margin_START (16)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_dtc_margin_END (25)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_cdtc_gap_START (27)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG0_sc_cdtc_gap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_fdtc_code_init : 8;
        unsigned int sc_cdtc_code_init : 8;
        unsigned int sc_fdtc_cyc : 5;
        unsigned int reserved_0 : 3;
        unsigned int sc_cdtc_cyc : 5;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_UNION;
#endif
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_fdtc_code_init_START (0)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_fdtc_code_init_END (7)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_cdtc_code_init_START (8)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_cdtc_code_init_END (15)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_fdtc_cyc_START (16)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_fdtc_cyc_END (20)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_cdtc_cyc_START (24)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG1_sc_cdtc_cyc_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_fdtc_step : 7;
        unsigned int reserved_0 : 1;
        unsigned int sc_cdtc_step : 6;
        unsigned int reserved_1 : 2;
        unsigned int sc_fdtc_length : 8;
        unsigned int sc_cdtc_length : 8;
    } reg;
} SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_UNION;
#endif
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_fdtc_step_START (0)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_fdtc_step_END (6)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_cdtc_step_START (8)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_cdtc_step_END (13)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_fdtc_length_START (16)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_fdtc_length_END (23)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_cdtc_length_START (24)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_CFG2_sc_cdtc_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int jm_code_b : 8;
        unsigned int jm_code_a : 8;
        unsigned int jm_code_d : 8;
        unsigned int jm_code_c : 8;
    } reg;
} SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_UNION;
#endif
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_b_START (0)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_b_END (7)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_a_START (8)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_a_END (15)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_d_START (16)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_d_END (23)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_c_START (24)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST0_jm_code_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int jm_dtc_mea_done : 1;
        unsigned int test_comp : 1;
        unsigned int jm_underflow : 1;
        unsigned int jm_overflow : 1;
        unsigned int test_dtc_curr_st : 3;
        unsigned int jm_code_valid : 1;
        unsigned int jm_code_e : 8;
        unsigned int jm_code_min : 8;
        unsigned int jm_code_max : 8;
    } reg;
} SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_UNION;
#endif
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_dtc_mea_done_START (0)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_dtc_mea_done_END (0)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_test_comp_START (1)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_test_comp_END (1)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_underflow_START (2)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_underflow_END (2)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_overflow_START (3)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_overflow_END (3)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_test_dtc_curr_st_START (4)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_test_dtc_curr_st_END (6)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_valid_START (7)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_valid_END (7)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_e_START (8)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_e_END (15)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_min_START (16)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_min_END (23)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_max_START (24)
#define SOC_CORE_CPU_CRG_JITTER_MONITOR_ST1_jm_code_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int onsys_avs_cfg_a : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_A_onsys_avs_cfg_a_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_A_onsys_avs_cfg_a_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_A_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_A_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int onsys_avs_cfg_b : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_B_onsys_avs_cfg_b_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_B_onsys_avs_cfg_b_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_B_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_B_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int onsys_avs_cfg_c : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_C_onsys_avs_cfg_c_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_C_onsys_avs_cfg_c_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_C_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_CFG_C_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_monitor_time_a : 16;
        unsigned int apb_monitor_time_b : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_AB_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_AB_apb_monitor_time_a_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_AB_apb_monitor_time_a_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_AB_apb_monitor_time_b_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_AB_apb_monitor_time_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th1_a : 16;
        unsigned int apb_vs_th2_a : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_A_apb_vs_th1_a_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_A_apb_vs_th1_a_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_A_apb_vs_th2_a_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_A_apb_vs_th2_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th3_a : 16;
        unsigned int apb_vol_sub_min_a : 8;
        unsigned int apb_vol_add_max_a : 8;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_apb_vs_th3_a_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_apb_vs_th3_a_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_apb_vol_sub_min_a_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_apb_vol_sub_min_a_END (23)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_apb_vol_add_max_a_START (24)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_A_apb_vol_add_max_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vol_cfg1_a : 8;
        unsigned int apb_vol_cfg2_a : 8;
        unsigned int apb_vol_cfg3_a : 8;
        unsigned int apb_vol_cfg4_a : 8;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg1_a_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg1_a_END (7)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg2_a_START (8)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg2_a_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg3_a_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg3_a_END (23)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg4_a_START (24)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg4_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vol_cfg1_b : 8;
        unsigned int apb_vol_cfg2_b : 8;
        unsigned int apb_vol_cfg3_b : 8;
        unsigned int apb_vol_cfg4_b : 8;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg1_b_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg1_b_END (7)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg2_b_START (8)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg2_b_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg3_b_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg3_b_END (23)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg4_b_START (24)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_B_apb_vol_cfg4_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vol_cfg1_c : 8;
        unsigned int apb_vol_cfg2_c : 8;
        unsigned int apb_vol_cfg3_c : 8;
        unsigned int apb_vol_cfg4_c : 8;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg1_c_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg1_c_END (7)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg2_c_START (8)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg2_c_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg3_c_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg3_c_END (23)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg4_c_START (24)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_CFG_C_apb_vol_cfg4_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vol_idx_a : 8;
        unsigned int apb_vol_idx_b : 8;
        unsigned int apb_vol_idx_c : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_apb_vol_idx_a_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_apb_vol_idx_a_END (7)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_apb_vol_idx_b_START (8)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_apb_vol_idx_b_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_apb_vol_idx_c_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VOL_IDX_apb_vol_idx_c_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_cur_stat_a : 2;
        unsigned int apb_cur_stat_b : 2;
        unsigned int apb_cur_stat_c : 2;
        unsigned int reserved_0 : 2;
        unsigned int apb_vol_sub_flag_a : 1;
        unsigned int apb_vol_sub_flag_b : 1;
        unsigned int apb_vol_sub_flag_c : 1;
        unsigned int reserved_1 : 1;
        unsigned int apb_cnt_us : 8;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cur_stat_a_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cur_stat_a_END (1)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cur_stat_b_START (2)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cur_stat_b_END (3)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cur_stat_c_START (4)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cur_stat_c_END (5)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_vol_sub_flag_a_START (8)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_vol_sub_flag_a_END (8)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_vol_sub_flag_b_START (9)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_vol_sub_flag_b_END (9)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_vol_sub_flag_c_START (10)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_vol_sub_flag_c_END (10)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cnt_us_START (12)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_APB_READ_apb_cnt_us_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_onsys_enable_a : 1;
        unsigned int apb_onsys_enable_b : 1;
        unsigned int apb_onsys_enable_c : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 12;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_apb_onsys_enable_a_START (0)
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_apb_onsys_enable_a_END (0)
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_apb_onsys_enable_b_START (1)
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_apb_onsys_enable_b_END (1)
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_apb_onsys_enable_c_START (2)
#define SOC_CORE_CPU_CRG_APB_ONSYS_ENABLE_apb_onsys_enable_c_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th1_b : 16;
        unsigned int apb_vs_th2_b : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_B_apb_vs_th1_b_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_B_apb_vs_th1_b_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_B_apb_vs_th2_b_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_B_apb_vs_th2_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th3_b : 16;
        unsigned int apb_vol_sub_min_b : 8;
        unsigned int apb_vol_add_max_b : 8;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_apb_vs_th3_b_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_apb_vs_th3_b_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_apb_vol_sub_min_b_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_apb_vol_sub_min_b_END (23)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_apb_vol_add_max_b_START (24)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_B_apb_vol_add_max_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th1_c : 16;
        unsigned int apb_vs_th2_c : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_C_apb_vs_th1_c_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_C_apb_vs_th1_c_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_C_apb_vs_th2_c_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_0_C_apb_vs_th2_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_vs_th3_c : 16;
        unsigned int apb_vol_sub_min_c : 8;
        unsigned int apb_vol_add_max_c : 8;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_apb_vs_th3_c_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_apb_vs_th3_c_END (15)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_apb_vol_sub_min_c_START (16)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_apb_vol_sub_min_c_END (23)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_apb_vol_add_max_c_START (24)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_VS_TH_1_C_apb_vol_add_max_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_monitor_time_c : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_CD_UNION;
#endif
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_CD_apb_monitor_time_c_START (0)
#define SOC_CORE_CPU_CRG_ONSYS_AVS_TIME_CFG_CD_apb_monitor_time_c_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg0 : 10;
        unsigned int coef_cfg1 : 10;
        unsigned int coef_cfg2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_coef_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_coef_cfg0_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_coef_cfg1_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_coef_cfg1_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_coef_cfg2_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_A_coef_cfg2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg3 : 10;
        unsigned int coef_cfg4 : 10;
        unsigned int coef_cfg5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_coef_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_coef_cfg3_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_coef_cfg4_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_coef_cfg4_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_coef_cfg5_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_A_coef_cfg5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg6 : 10;
        unsigned int coef_cfg7 : 10;
        unsigned int coef_cfg8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_coef_cfg6_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_coef_cfg6_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_coef_cfg7_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_coef_cfg7_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_coef_cfg8_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_A_coef_cfg8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg9 : 10;
        unsigned int coef_cfg10 : 10;
        unsigned int coef_cfg11 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_coef_cfg9_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_coef_cfg9_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_coef_cfg10_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_coef_cfg10_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_coef_cfg11_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_A_coef_cfg11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg12 : 10;
        unsigned int coef_cfg13 : 10;
        unsigned int coef_cfg14 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_coef_cfg12_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_coef_cfg12_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_coef_cfg13_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_coef_cfg13_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_coef_cfg14_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_A_coef_cfg14_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg15 : 10;
        unsigned int coef_cfg16 : 10;
        unsigned int coef_cfg17 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_coef_cfg15_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_coef_cfg15_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_coef_cfg16_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_coef_cfg16_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_coef_cfg17_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_A_coef_cfg17_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg18 : 10;
        unsigned int coef_cfg19 : 10;
        unsigned int coef_cfg20 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_coef_cfg18_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_coef_cfg18_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_coef_cfg19_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_coef_cfg19_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_coef_cfg20_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_A_coef_cfg20_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg21 : 10;
        unsigned int coef_cfg22 : 10;
        unsigned int coef_cfg23 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_coef_cfg21_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_coef_cfg21_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_coef_cfg22_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_coef_cfg22_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_coef_cfg23_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_A_coef_cfg23_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w0 : 8;
        unsigned int coef_w1 : 8;
        unsigned int coef_w2 : 8;
        unsigned int coef_w3 : 8;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w0_END (7)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w1_START (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w1_END (15)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w2_START (16)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w2_END (23)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w3_START (24)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_A_coef_w3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w4 : 8;
        unsigned int coef_m : 5;
        unsigned int reserved : 19;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_A_coef_w4_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_A_coef_w4_END (7)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_A_coef_m_START (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_A_coef_m_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd_thr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_A_accu_fd_thr_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_A_accu_fd_thr_END (24)
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
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_max_thr_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_max_thr_END (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_min_thr_START (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_min_thr_END (17)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_add_START (18)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_add_END (21)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_add_bypass_START (22)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_vol_add_bypass_END (22)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_fdcs_onsys_cfg11_a_START (23)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_A_fdcs_onsys_cfg11_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg12_a : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_A_fdcs_onsys_cfg12_a_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_A_fdcs_onsys_cfg12_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg13_a : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_A_fdcs_onsys_cfg13_a_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_A_fdcs_onsys_cfg13_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg0 : 10;
        unsigned int coef_cfg1 : 10;
        unsigned int coef_cfg2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_coef_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_coef_cfg0_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_coef_cfg1_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_coef_cfg1_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_coef_cfg2_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_B_coef_cfg2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg3 : 10;
        unsigned int coef_cfg4 : 10;
        unsigned int coef_cfg5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_coef_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_coef_cfg3_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_coef_cfg4_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_coef_cfg4_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_coef_cfg5_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_B_coef_cfg5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg6 : 10;
        unsigned int coef_cfg7 : 10;
        unsigned int coef_cfg8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_coef_cfg6_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_coef_cfg6_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_coef_cfg7_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_coef_cfg7_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_coef_cfg8_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_B_coef_cfg8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg9 : 10;
        unsigned int coef_cfg10 : 10;
        unsigned int coef_cfg11 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_coef_cfg9_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_coef_cfg9_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_coef_cfg10_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_coef_cfg10_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_coef_cfg11_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_B_coef_cfg11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg12 : 10;
        unsigned int coef_cfg13 : 10;
        unsigned int coef_cfg14 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_coef_cfg12_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_coef_cfg12_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_coef_cfg13_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_coef_cfg13_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_coef_cfg14_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_B_coef_cfg14_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg15 : 10;
        unsigned int coef_cfg16 : 10;
        unsigned int coef_cfg17 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_coef_cfg15_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_coef_cfg15_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_coef_cfg16_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_coef_cfg16_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_coef_cfg17_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_B_coef_cfg17_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg18 : 10;
        unsigned int coef_cfg19 : 10;
        unsigned int coef_cfg20 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_coef_cfg18_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_coef_cfg18_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_coef_cfg19_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_coef_cfg19_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_coef_cfg20_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_B_coef_cfg20_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg21 : 10;
        unsigned int coef_cfg22 : 10;
        unsigned int coef_cfg23 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_coef_cfg21_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_coef_cfg21_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_coef_cfg22_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_coef_cfg22_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_coef_cfg23_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_B_coef_cfg23_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w0 : 8;
        unsigned int coef_w1 : 8;
        unsigned int coef_w2 : 8;
        unsigned int coef_w3 : 8;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w0_END (7)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w1_START (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w1_END (15)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w2_START (16)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w2_END (23)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w3_START (24)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_B_coef_w3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w4 : 8;
        unsigned int coef_m : 5;
        unsigned int reserved : 19;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_B_coef_w4_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_B_coef_w4_END (7)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_B_coef_m_START (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_B_coef_m_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd_thr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_B_accu_fd_thr_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_B_accu_fd_thr_END (24)
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
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_max_thr_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_max_thr_END (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_min_thr_START (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_min_thr_END (17)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_add_START (18)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_add_END (21)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_add_bypass_START (22)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_vol_add_bypass_END (22)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_fdcs_onsys_cfg11_a_START (23)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_B_fdcs_onsys_cfg11_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg12_a : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_B_fdcs_onsys_cfg12_a_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_B_fdcs_onsys_cfg12_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg13_a : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_B_fdcs_onsys_cfg13_a_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_B_fdcs_onsys_cfg13_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg0 : 10;
        unsigned int coef_cfg1 : 10;
        unsigned int coef_cfg2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_coef_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_coef_cfg0_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_coef_cfg1_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_coef_cfg1_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_coef_cfg2_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG0_C_coef_cfg2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg3 : 10;
        unsigned int coef_cfg4 : 10;
        unsigned int coef_cfg5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_coef_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_coef_cfg3_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_coef_cfg4_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_coef_cfg4_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_coef_cfg5_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG1_C_coef_cfg5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg6 : 10;
        unsigned int coef_cfg7 : 10;
        unsigned int coef_cfg8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_coef_cfg6_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_coef_cfg6_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_coef_cfg7_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_coef_cfg7_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_coef_cfg8_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG2_C_coef_cfg8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg9 : 10;
        unsigned int coef_cfg10 : 10;
        unsigned int coef_cfg11 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_coef_cfg9_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_coef_cfg9_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_coef_cfg10_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_coef_cfg10_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_coef_cfg11_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG3_C_coef_cfg11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg12 : 10;
        unsigned int coef_cfg13 : 10;
        unsigned int coef_cfg14 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_coef_cfg12_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_coef_cfg12_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_coef_cfg13_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_coef_cfg13_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_coef_cfg14_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG4_C_coef_cfg14_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg15 : 10;
        unsigned int coef_cfg16 : 10;
        unsigned int coef_cfg17 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_coef_cfg15_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_coef_cfg15_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_coef_cfg16_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_coef_cfg16_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_coef_cfg17_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG5_C_coef_cfg17_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg18 : 10;
        unsigned int coef_cfg19 : 10;
        unsigned int coef_cfg20 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_coef_cfg18_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_coef_cfg18_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_coef_cfg19_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_coef_cfg19_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_coef_cfg20_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG6_C_coef_cfg20_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_cfg21 : 10;
        unsigned int coef_cfg22 : 10;
        unsigned int coef_cfg23 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_coef_cfg21_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_coef_cfg21_END (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_coef_cfg22_START (10)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_coef_cfg22_END (19)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_coef_cfg23_START (20)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG7_C_coef_cfg23_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w0 : 8;
        unsigned int coef_w1 : 8;
        unsigned int coef_w2 : 8;
        unsigned int coef_w3 : 8;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w0_END (7)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w1_START (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w1_END (15)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w2_START (16)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w2_END (23)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w3_START (24)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG8_C_coef_w3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coef_w4 : 8;
        unsigned int coef_m : 5;
        unsigned int reserved : 19;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_C_coef_w4_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_C_coef_w4_END (7)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_C_coef_m_START (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG9_C_coef_m_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd_thr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_C_accu_fd_thr_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG10_C_accu_fd_thr_END (24)
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
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_max_thr_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_max_thr_END (8)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_min_thr_START (9)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_min_thr_END (17)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_add_START (18)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_add_END (21)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_add_bypass_START (22)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_vol_add_bypass_END (22)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_fdcs_onsys_cfg11_a_START (23)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG11_C_fdcs_onsys_cfg11_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg12_a : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_C_fdcs_onsys_cfg12_a_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG12_C_fdcs_onsys_cfg12_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_cfg13_a : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_C_fdcs_onsys_cfg13_a_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_CFG13_C_fdcs_onsys_cfg13_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_A_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_A_fdcs_onsys_stat0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_A_fdcs_onsys_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_B_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_B_fdcs_onsys_stat0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_B_fdcs_onsys_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fdcs_onsys_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_C_UNION;
#endif
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_C_fdcs_onsys_stat0_START (0)
#define SOC_CORE_CPU_CRG_FDCS_ONSYS_STAT_C_fdcs_onsys_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_drop_en_big : 1;
        unsigned int pim_drop_en_middle : 1;
        unsigned int pim_drop_en_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int pim_ost_en_big : 1;
        unsigned int pim_ost_en_middle : 1;
        unsigned int pim_ost_en_little : 1;
        unsigned int reserved_1 : 1;
        unsigned int pim_peaklow_en_big : 1;
        unsigned int pim_peaklow_en_middle : 1;
        unsigned int pim_peaklow_en_little : 1;
        unsigned int reserved_2 : 1;
        unsigned int pim_debug_big : 1;
        unsigned int pim_debug_middle : 1;
        unsigned int pim_debug_little : 1;
        unsigned int reserved_3 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_PIM_CTRL0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_drop_en_big_START (0)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_drop_en_big_END (0)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_drop_en_middle_START (1)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_drop_en_middle_END (1)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_drop_en_little_START (2)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_drop_en_little_END (2)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_ost_en_big_START (4)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_ost_en_big_END (4)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_ost_en_middle_START (5)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_ost_en_middle_END (5)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_ost_en_little_START (6)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_ost_en_little_END (6)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_peaklow_en_big_START (8)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_peaklow_en_big_END (8)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_peaklow_en_middle_START (9)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_peaklow_en_middle_END (9)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_peaklow_en_little_START (10)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_peaklow_en_little_END (10)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_debug_big_START (12)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_debug_big_END (12)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_debug_middle_START (13)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_debug_middle_END (13)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_debug_little_START (14)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_pim_debug_little_END (14)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_PIM_CTRL0_bitmasken_END (31)
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
} SOC_CORE_CPU_CRG_PIM_CFG0_MIDDLE_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG1_MIDDLE_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG2_MIDDLE_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG3_MIDDLE_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG0_BIG_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG1_BIG_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG2_BIG_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG3_BIG_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG0_LITTLE_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG1_LITTLE_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG2_LITTLE_UNION;
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
} SOC_CORE_CPU_CRG_PIM_CFG3_LITTLE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_code_big : 16;
        unsigned int pim_peaklow_ready_big : 1;
        unsigned int pim_peaklow_ready_middle : 1;
        unsigned int pim_flag_l_big : 1;
        unsigned int pim_flag_h_big : 1;
        unsigned int pim_flag_l_middle : 1;
        unsigned int pim_flag_h_middle : 1;
        unsigned int pim_flag_ready_big : 1;
        unsigned int pim_flag_ready_middle : 1;
        unsigned int pim_peaklow_ready_little : 1;
        unsigned int pim_flag_ready_little : 1;
        unsigned int pim_flag_l_little : 1;
        unsigned int pim_flag_h_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_CORE_CPU_CRG_PIM_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_code_big_START (0)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_code_big_END (15)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_ready_big_START (16)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_ready_big_END (16)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_ready_middle_START (17)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_ready_middle_END (17)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_l_big_START (18)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_l_big_END (18)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_h_big_START (19)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_h_big_END (19)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_l_middle_START (20)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_l_middle_END (20)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_h_middle_START (21)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_h_middle_END (21)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_ready_big_START (22)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_ready_big_END (22)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_ready_middle_START (23)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_ready_middle_END (23)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_ready_little_START (24)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_peaklow_ready_little_END (24)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_ready_little_START (25)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_ready_little_END (25)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_l_little_START (26)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_l_little_END (26)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_h_little_START (27)
#define SOC_CORE_CPU_CRG_PIM_STAT0_pim_flag_h_little_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_code_middle : 16;
        unsigned int pim_peaklow_code_little : 16;
    } reg;
} SOC_CORE_CPU_CRG_PIM_STAT1_UNION;
#endif
#define SOC_CORE_CPU_CRG_PIM_STAT1_pim_peaklow_code_middle_START (0)
#define SOC_CORE_CPU_CRG_PIM_STAT1_pim_peaklow_code_middle_END (15)
#define SOC_CORE_CPU_CRG_PIM_STAT1_pim_peaklow_code_little_START (16)
#define SOC_CORE_CPU_CRG_PIM_STAT1_pim_peaklow_code_little_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_en : 1;
        unsigned int accu_fd_en : 1;
        unsigned int peaklow_en : 1;
        unsigned int clear_all_en : 1;
        unsigned int cnt_timer_hd_en : 1;
        unsigned int hw_fsm_mode : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_cnt_timer_en_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_cnt_timer_en_END (0)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_accu_fd_en_START (1)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_accu_fd_en_END (1)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_peaklow_en_START (2)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_peaklow_en_END (2)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_clear_all_en_START (3)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_clear_all_en_END (3)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_cnt_timer_hd_en_START (4)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_cnt_timer_hd_en_END (4)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_hw_fsm_mode_START (5)
#define SOC_CORE_CPU_CRG_MON_CFG0_MIDDLE_hw_fsm_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG1_MIDDLE_read_lock_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG1_MIDDLE_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG2_MIDDLE_bin_peaklow_en_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG2_MIDDLE_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG3_MIDDLE_vth0_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG3_MIDDLE_vth0_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG3_MIDDLE_vth1_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG3_MIDDLE_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG4_MIDDLE_vth2_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG4_MIDDLE_vth2_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG4_MIDDLE_vth3_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG4_MIDDLE_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG5_MIDDLE_vth4_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG5_MIDDLE_vth4_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG5_MIDDLE_vth5_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG5_MIDDLE_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG6_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG6_MIDDLE_vth6_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG6_MIDDLE_vth6_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG6_MIDDLE_vth7_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG6_MIDDLE_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG7_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG7_MIDDLE_vth8_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG7_MIDDLE_vth8_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG7_MIDDLE_vth9_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG7_MIDDLE_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG8_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG8_MIDDLE_vth10_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG8_MIDDLE_vth10_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG8_MIDDLE_vth11_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG8_MIDDLE_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG9_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG9_MIDDLE_vth12_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG9_MIDDLE_vth12_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG9_MIDDLE_vth13_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG9_MIDDLE_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG10_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG10_MIDDLE_vth14_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG10_MIDDLE_vth14_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG10_MIDDLE_vth15_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG10_MIDDLE_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG11_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG11_MIDDLE_vth16_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG11_MIDDLE_vth16_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG11_MIDDLE_vth17_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG11_MIDDLE_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG12_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG12_MIDDLE_vth18_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG12_MIDDLE_vth18_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG12_MIDDLE_vth19_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG12_MIDDLE_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG13_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG13_MIDDLE_vth20_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG13_MIDDLE_vth20_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG13_MIDDLE_vth21_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG13_MIDDLE_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG14_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG14_MIDDLE_vth22_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG14_MIDDLE_vth22_peaklow_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_hd_th : 22;
        unsigned int reserved : 8;
        unsigned int read_lock_mode : 1;
        unsigned int sel_peaklow_vth : 1;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_cnt_timer_hd_th_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_cnt_timer_hd_th_END (21)
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_read_lock_mode_START (30)
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_read_lock_mode_END (30)
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_sel_peaklow_vth_START (31)
#define SOC_CORE_CPU_CRG_MON_CFG15_MIDDLE_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG16_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG16_MIDDLE_pim_peaklow_vth_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG16_MIDDLE_pim_peaklow_vth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer : 22;
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT0_MIDDLE_cnt_timer_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT0_MIDDLE_cnt_timer_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd : 25;
        unsigned int reserved_0: 3;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT1_MIDDLE_accu_fd_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT1_MIDDLE_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT2_MIDDLE_bin0_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT2_MIDDLE_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT3_MIDDLE_bin1_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT3_MIDDLE_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT4_MIDDLE_bin2_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT4_MIDDLE_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT5_MIDDLE_bin3_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT5_MIDDLE_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT6_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT6_MIDDLE_bin4_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT6_MIDDLE_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT7_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT7_MIDDLE_bin5_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT7_MIDDLE_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT8_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT8_MIDDLE_bin6_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT8_MIDDLE_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT9_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT9_MIDDLE_bin7_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT9_MIDDLE_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT10_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT10_MIDDLE_bin8_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT10_MIDDLE_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT11_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT11_MIDDLE_bin9_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT11_MIDDLE_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT12_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT12_MIDDLE_bin10_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT12_MIDDLE_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT13_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT13_MIDDLE_bin11_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT13_MIDDLE_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT14_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT14_MIDDLE_bin12_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT14_MIDDLE_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT15_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT15_MIDDLE_bin13_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT15_MIDDLE_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT16_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT16_MIDDLE_bin14_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT16_MIDDLE_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT17_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT17_MIDDLE_bin15_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT17_MIDDLE_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT18_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT18_MIDDLE_bin16_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT18_MIDDLE_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT19_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT19_MIDDLE_bin17_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT19_MIDDLE_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT20_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT20_MIDDLE_bin18_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT20_MIDDLE_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT21_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT21_MIDDLE_bin19_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT21_MIDDLE_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT22_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT22_MIDDLE_bin20_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT22_MIDDLE_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT23_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT23_MIDDLE_bin21_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT23_MIDDLE_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT24_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT24_MIDDLE_bin22_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT24_MIDDLE_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT25_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT25_MIDDLE_bin23_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT25_MIDDLE_bin23_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_en : 1;
        unsigned int accu_fd_en : 1;
        unsigned int peaklow_en : 1;
        unsigned int clear_all_en : 1;
        unsigned int cnt_timer_hd_en : 1;
        unsigned int hw_fsm_mode : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_cnt_timer_en_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_cnt_timer_en_END (0)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_accu_fd_en_START (1)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_accu_fd_en_END (1)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_peaklow_en_START (2)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_peaklow_en_END (2)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_clear_all_en_START (3)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_clear_all_en_END (3)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_cnt_timer_hd_en_START (4)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_cnt_timer_hd_en_END (4)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_hw_fsm_mode_START (5)
#define SOC_CORE_CPU_CRG_MON_CFG0_BIG_hw_fsm_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG1_BIG_read_lock_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG1_BIG_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG2_BIG_bin_peaklow_en_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG2_BIG_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG3_BIG_vth0_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG3_BIG_vth0_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG3_BIG_vth1_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG3_BIG_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG4_BIG_vth2_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG4_BIG_vth2_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG4_BIG_vth3_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG4_BIG_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG5_BIG_vth4_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG5_BIG_vth4_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG5_BIG_vth5_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG5_BIG_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG6_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG6_BIG_vth6_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG6_BIG_vth6_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG6_BIG_vth7_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG6_BIG_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG7_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG7_BIG_vth8_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG7_BIG_vth8_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG7_BIG_vth9_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG7_BIG_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG8_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG8_BIG_vth10_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG8_BIG_vth10_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG8_BIG_vth11_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG8_BIG_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG9_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG9_BIG_vth12_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG9_BIG_vth12_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG9_BIG_vth13_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG9_BIG_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG10_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG10_BIG_vth14_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG10_BIG_vth14_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG10_BIG_vth15_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG10_BIG_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG11_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG11_BIG_vth16_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG11_BIG_vth16_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG11_BIG_vth17_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG11_BIG_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG12_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG12_BIG_vth18_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG12_BIG_vth18_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG12_BIG_vth19_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG12_BIG_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG13_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG13_BIG_vth20_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG13_BIG_vth20_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG13_BIG_vth21_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG13_BIG_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG14_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG14_BIG_vth22_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG14_BIG_vth22_peaklow_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_hd_th : 22;
        unsigned int reserved : 8;
        unsigned int read_lock_mode : 1;
        unsigned int sel_peaklow_vth : 1;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG15_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_cnt_timer_hd_th_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_cnt_timer_hd_th_END (21)
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_read_lock_mode_START (30)
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_read_lock_mode_END (30)
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_sel_peaklow_vth_START (31)
#define SOC_CORE_CPU_CRG_MON_CFG15_BIG_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG16_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG16_BIG_pim_peaklow_vth_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG16_BIG_pim_peaklow_vth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer : 22;
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT0_BIG_cnt_timer_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT0_BIG_cnt_timer_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd : 25;
        unsigned int reserved_0: 3;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT1_BIG_accu_fd_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT1_BIG_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT2_BIG_bin0_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT2_BIG_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT3_BIG_bin1_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT3_BIG_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT4_BIG_bin2_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT4_BIG_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT5_BIG_bin3_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT5_BIG_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT6_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT6_BIG_bin4_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT6_BIG_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT7_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT7_BIG_bin5_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT7_BIG_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT8_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT8_BIG_bin6_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT8_BIG_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT9_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT9_BIG_bin7_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT9_BIG_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT10_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT10_BIG_bin8_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT10_BIG_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT11_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT11_BIG_bin9_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT11_BIG_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT12_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT12_BIG_bin10_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT12_BIG_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT13_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT13_BIG_bin11_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT13_BIG_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT14_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT14_BIG_bin12_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT14_BIG_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT15_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT15_BIG_bin13_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT15_BIG_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT16_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT16_BIG_bin14_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT16_BIG_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT17_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT17_BIG_bin15_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT17_BIG_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT18_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT18_BIG_bin16_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT18_BIG_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT19_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT19_BIG_bin17_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT19_BIG_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT20_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT20_BIG_bin18_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT20_BIG_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT21_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT21_BIG_bin19_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT21_BIG_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT22_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT22_BIG_bin20_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT22_BIG_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT23_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT23_BIG_bin21_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT23_BIG_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT24_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT24_BIG_bin22_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT24_BIG_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT25_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT25_BIG_bin23_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT25_BIG_bin23_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_en : 1;
        unsigned int accu_fd_en : 1;
        unsigned int peaklow_en : 1;
        unsigned int clear_all_en : 1;
        unsigned int cnt_timer_hd_en : 1;
        unsigned int hw_fsm_mode : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_cnt_timer_en_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_cnt_timer_en_END (0)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_accu_fd_en_START (1)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_accu_fd_en_END (1)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_peaklow_en_START (2)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_peaklow_en_END (2)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_clear_all_en_START (3)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_clear_all_en_END (3)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_cnt_timer_hd_en_START (4)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_cnt_timer_hd_en_END (4)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_hw_fsm_mode_START (5)
#define SOC_CORE_CPU_CRG_MON_CFG0_LITTLE_hw_fsm_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG1_LITTLE_read_lock_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG1_LITTLE_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG2_LITTLE_bin_peaklow_en_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG2_LITTLE_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG3_LITTLE_vth0_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG3_LITTLE_vth0_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG3_LITTLE_vth1_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG3_LITTLE_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG4_LITTLE_vth2_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG4_LITTLE_vth2_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG4_LITTLE_vth3_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG4_LITTLE_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG5_LITTLE_vth4_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG5_LITTLE_vth4_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG5_LITTLE_vth5_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG5_LITTLE_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG6_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG6_LITTLE_vth6_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG6_LITTLE_vth6_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG6_LITTLE_vth7_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG6_LITTLE_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG7_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG7_LITTLE_vth8_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG7_LITTLE_vth8_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG7_LITTLE_vth9_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG7_LITTLE_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG8_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG8_LITTLE_vth10_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG8_LITTLE_vth10_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG8_LITTLE_vth11_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG8_LITTLE_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG9_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG9_LITTLE_vth12_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG9_LITTLE_vth12_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG9_LITTLE_vth13_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG9_LITTLE_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG10_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG10_LITTLE_vth14_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG10_LITTLE_vth14_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG10_LITTLE_vth15_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG10_LITTLE_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG11_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG11_LITTLE_vth16_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG11_LITTLE_vth16_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG11_LITTLE_vth17_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG11_LITTLE_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG12_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG12_LITTLE_vth18_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG12_LITTLE_vth18_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG12_LITTLE_vth19_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG12_LITTLE_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG13_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG13_LITTLE_vth20_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG13_LITTLE_vth20_peaklow_END (15)
#define SOC_CORE_CPU_CRG_MON_CFG13_LITTLE_vth21_peaklow_START (16)
#define SOC_CORE_CPU_CRG_MON_CFG13_LITTLE_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG14_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG14_LITTLE_vth22_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG14_LITTLE_vth22_peaklow_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_hd_th : 22;
        unsigned int reserved : 8;
        unsigned int read_lock_mode : 1;
        unsigned int sel_peaklow_vth : 1;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_cnt_timer_hd_th_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_cnt_timer_hd_th_END (21)
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_read_lock_mode_START (30)
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_read_lock_mode_END (30)
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_sel_peaklow_vth_START (31)
#define SOC_CORE_CPU_CRG_MON_CFG15_LITTLE_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRG_MON_CFG16_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_CFG16_LITTLE_pim_peaklow_vth_START (0)
#define SOC_CORE_CPU_CRG_MON_CFG16_LITTLE_pim_peaklow_vth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer : 22;
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT0_LITTLE_cnt_timer_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT0_LITTLE_cnt_timer_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int accu_fd : 25;
        unsigned int reserved_0: 3;
        unsigned int reserved_1: 4;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT1_LITTLE_accu_fd_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT1_LITTLE_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT2_LITTLE_bin0_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT2_LITTLE_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT3_LITTLE_bin1_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT3_LITTLE_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT4_LITTLE_bin2_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT4_LITTLE_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT5_LITTLE_bin3_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT5_LITTLE_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT6_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT6_LITTLE_bin4_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT6_LITTLE_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT7_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT7_LITTLE_bin5_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT7_LITTLE_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT8_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT8_LITTLE_bin6_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT8_LITTLE_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT9_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT9_LITTLE_bin7_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT9_LITTLE_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT10_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT10_LITTLE_bin8_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT10_LITTLE_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT11_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT11_LITTLE_bin9_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT11_LITTLE_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT12_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT12_LITTLE_bin10_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT12_LITTLE_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT13_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT13_LITTLE_bin11_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT13_LITTLE_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT14_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT14_LITTLE_bin12_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT14_LITTLE_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT15_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT15_LITTLE_bin13_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT15_LITTLE_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT16_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT16_LITTLE_bin14_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT16_LITTLE_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT17_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT17_LITTLE_bin15_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT17_LITTLE_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT18_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT18_LITTLE_bin16_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT18_LITTLE_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT19_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT19_LITTLE_bin17_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT19_LITTLE_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT20_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT20_LITTLE_bin18_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT20_LITTLE_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT21_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT21_LITTLE_bin19_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT21_LITTLE_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT22_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT22_LITTLE_bin20_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT22_LITTLE_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT23_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT23_LITTLE_bin21_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT23_LITTLE_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT24_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT24_LITTLE_bin22_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT24_LITTLE_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRG_MON_STAT25_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_MON_STAT25_LITTLE_bin23_peaklow_START (0)
#define SOC_CORE_CPU_CRG_MON_STAT25_LITTLE_bin23_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_big_clkrst_bypass : 1;
        unsigned int fcg_middle_clkrst_bypass : 1;
        unsigned int fcg_little_clkrst_bypass : 1;
        unsigned int dcd_clkrst_bypass : 1;
        unsigned int dcc_cpum_clkrst_bypass : 1;
        unsigned int dcc_cpub_clkrst_bypass : 1;
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
} SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_fcg_big_clkrst_bypass_START (0)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_fcg_big_clkrst_bypass_END (0)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_fcg_middle_clkrst_bypass_START (1)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_fcg_middle_clkrst_bypass_END (1)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_fcg_little_clkrst_bypass_START (2)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_fcg_little_clkrst_bypass_END (2)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_dcd_clkrst_bypass_START (3)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_dcd_clkrst_bypass_END (3)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_dcc_cpum_clkrst_bypass_START (4)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_dcc_cpum_clkrst_bypass_END (4)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_dcc_cpub_clkrst_bypass_START (5)
#define SOC_CORE_CPU_CRG_IPCLKRST_BYPASS0_dcc_cpub_clkrst_bypass_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_MIDDLE_d2a_fcg_ana_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_MIDDLE_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_MIDDLE_d2a_fcg_ana_cfg1_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_MIDDLE_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_MIDDLE_d2a_fcg_ana_cfg2_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_MIDDLE_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_MIDDLE_d2a_fcg_ana_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_MIDDLE_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG0_MIDDLE_fcg_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG0_MIDDLE_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG1_MIDDLE_fcg_cfg1_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG1_MIDDLE_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG2_MIDDLE_fcg_cfg2_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG2_MIDDLE_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG3_MIDDLE_fcg_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG3_MIDDLE_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG4_MIDDLE_fcg_cfg4_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG4_MIDDLE_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG5_MIDDLE_fcg_cfg5_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG5_MIDDLE_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG6_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG6_MIDDLE_fcg_cfg6_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG6_MIDDLE_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG7_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG7_MIDDLE_fcg_cfg7_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG7_MIDDLE_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG8_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG8_MIDDLE_fcg_cfg8_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG8_MIDDLE_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG9_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG9_MIDDLE_fcg_cfg9_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG9_MIDDLE_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG10_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG10_MIDDLE_fcg_cfg10_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG10_MIDDLE_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG11_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG11_MIDDLE_fcg_cfg11_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG11_MIDDLE_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG12_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG12_MIDDLE_fcg_cfg12_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG12_MIDDLE_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG13_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG13_MIDDLE_fcg_cfg13_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG13_MIDDLE_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG14_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG14_MIDDLE_fcg_cfg14_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG14_MIDDLE_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG15_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG15_MIDDLE_fcg_cfg15_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG15_MIDDLE_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG16_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG16_MIDDLE_fcg_cfg16_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG16_MIDDLE_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG17_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG17_MIDDLE_fcg_cfg17_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG17_MIDDLE_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG18_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG18_MIDDLE_fcg_cfg18_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG18_MIDDLE_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG19_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG19_MIDDLE_fcg_cfg19_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG19_MIDDLE_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG20_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG20_MIDDLE_fcg_cfg20_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG20_MIDDLE_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG21_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG21_MIDDLE_fcg_cfg21_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG21_MIDDLE_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG22_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG22_MIDDLE_fcg_cfg22_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG22_MIDDLE_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG23_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG23_MIDDLE_fcg_cfg23_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG23_MIDDLE_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG24_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG24_MIDDLE_fcg_cfg24_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG24_MIDDLE_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG25_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG25_MIDDLE_fcg_cfg25_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG25_MIDDLE_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG26_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG26_MIDDLE_fcg_cfg26_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG26_MIDDLE_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG27_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG27_MIDDLE_fcg_cfg27_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG27_MIDDLE_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT0_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT0_MIDDLE_fcg_stat0_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT0_MIDDLE_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT1_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT1_MIDDLE_fcg_stat1_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT1_MIDDLE_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT2_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT2_MIDDLE_fcg_stat2_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT2_MIDDLE_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT3_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT3_MIDDLE_fcg_stat3_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT3_MIDDLE_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT4_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT4_MIDDLE_fcg_stat4_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT4_MIDDLE_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT5_MIDDLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT5_MIDDLE_fcg_stat5_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT5_MIDDLE_fcg_stat5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_BIG_d2a_fcg_ana_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_BIG_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_BIG_d2a_fcg_ana_cfg1_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_BIG_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_BIG_d2a_fcg_ana_cfg2_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_BIG_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_BIG_d2a_fcg_ana_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_BIG_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG0_BIG_fcg_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG0_BIG_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG1_BIG_fcg_cfg1_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG1_BIG_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG2_BIG_fcg_cfg2_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG2_BIG_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG3_BIG_fcg_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG3_BIG_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG4_BIG_fcg_cfg4_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG4_BIG_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG5_BIG_fcg_cfg5_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG5_BIG_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG6_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG6_BIG_fcg_cfg6_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG6_BIG_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG7_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG7_BIG_fcg_cfg7_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG7_BIG_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG8_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG8_BIG_fcg_cfg8_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG8_BIG_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG9_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG9_BIG_fcg_cfg9_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG9_BIG_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG10_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG10_BIG_fcg_cfg10_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG10_BIG_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG11_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG11_BIG_fcg_cfg11_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG11_BIG_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG12_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG12_BIG_fcg_cfg12_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG12_BIG_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG13_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG13_BIG_fcg_cfg13_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG13_BIG_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG14_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG14_BIG_fcg_cfg14_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG14_BIG_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG15_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG15_BIG_fcg_cfg15_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG15_BIG_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG16_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG16_BIG_fcg_cfg16_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG16_BIG_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG17_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG17_BIG_fcg_cfg17_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG17_BIG_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG18_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG18_BIG_fcg_cfg18_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG18_BIG_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG19_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG19_BIG_fcg_cfg19_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG19_BIG_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG20_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG20_BIG_fcg_cfg20_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG20_BIG_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG21_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG21_BIG_fcg_cfg21_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG21_BIG_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG22_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG22_BIG_fcg_cfg22_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG22_BIG_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG23_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG23_BIG_fcg_cfg23_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG23_BIG_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG24_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG24_BIG_fcg_cfg24_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG24_BIG_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG25_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG25_BIG_fcg_cfg25_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG25_BIG_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG26_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG26_BIG_fcg_cfg26_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG26_BIG_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG27_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG27_BIG_fcg_cfg27_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG27_BIG_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT0_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT0_BIG_fcg_stat0_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT0_BIG_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT1_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT1_BIG_fcg_stat1_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT1_BIG_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT2_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT2_BIG_fcg_stat2_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT2_BIG_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT3_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT3_BIG_fcg_stat3_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT3_BIG_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT4_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT4_BIG_fcg_stat4_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT4_BIG_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT5_BIG_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT5_BIG_fcg_stat5_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT5_BIG_fcg_stat5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_LITTLE_d2a_fcg_ana_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG0_LITTLE_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_LITTLE_d2a_fcg_ana_cfg1_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG1_LITTLE_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_LITTLE_d2a_fcg_ana_cfg2_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG2_LITTLE_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_ANA_CFG3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_LITTLE_d2a_fcg_ana_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FCG_ANA_CFG3_LITTLE_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG0_LITTLE_fcg_cfg0_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG0_LITTLE_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG1_LITTLE_fcg_cfg1_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG1_LITTLE_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG2_LITTLE_fcg_cfg2_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG2_LITTLE_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG3_LITTLE_fcg_cfg3_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG3_LITTLE_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG4_LITTLE_fcg_cfg4_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG4_LITTLE_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG5_LITTLE_fcg_cfg5_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG5_LITTLE_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG6_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG6_LITTLE_fcg_cfg6_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG6_LITTLE_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG7_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG7_LITTLE_fcg_cfg7_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG7_LITTLE_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG8_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG8_LITTLE_fcg_cfg8_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG8_LITTLE_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG9_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG9_LITTLE_fcg_cfg9_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG9_LITTLE_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG10_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG10_LITTLE_fcg_cfg10_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG10_LITTLE_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG11_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG11_LITTLE_fcg_cfg11_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG11_LITTLE_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG12_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG12_LITTLE_fcg_cfg12_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG12_LITTLE_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG13_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG13_LITTLE_fcg_cfg13_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG13_LITTLE_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG14_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG14_LITTLE_fcg_cfg14_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG14_LITTLE_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG15_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG15_LITTLE_fcg_cfg15_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG15_LITTLE_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG16_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG16_LITTLE_fcg_cfg16_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG16_LITTLE_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG17_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG17_LITTLE_fcg_cfg17_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG17_LITTLE_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG18_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG18_LITTLE_fcg_cfg18_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG18_LITTLE_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG19_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG19_LITTLE_fcg_cfg19_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG19_LITTLE_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG20_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG20_LITTLE_fcg_cfg20_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG20_LITTLE_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG21_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG21_LITTLE_fcg_cfg21_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG21_LITTLE_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG22_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG22_LITTLE_fcg_cfg22_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG22_LITTLE_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG23_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG23_LITTLE_fcg_cfg23_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG23_LITTLE_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG24_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG24_LITTLE_fcg_cfg24_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG24_LITTLE_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG25_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG25_LITTLE_fcg_cfg25_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG25_LITTLE_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG26_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG26_LITTLE_fcg_cfg26_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG26_LITTLE_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_CFG27_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_CFG27_LITTLE_fcg_cfg27_START (0)
#define SOC_CORE_CPU_CRG_FCG_CFG27_LITTLE_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT0_LITTLE_fcg_stat0_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT0_LITTLE_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT1_LITTLE_fcg_stat1_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT1_LITTLE_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT2_LITTLE_fcg_stat2_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT2_LITTLE_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT3_LITTLE_fcg_stat3_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT3_LITTLE_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT4_LITTLE_fcg_stat4_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT4_LITTLE_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_CORE_CPU_CRG_FCG_STAT5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRG_FCG_STAT5_LITTLE_fcg_stat5_START (0)
#define SOC_CORE_CPU_CRG_FCG_STAT5_LITTLE_fcg_stat5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Tref1 : 16;
        unsigned int delt_T1 : 16;
    } reg;
} SOC_CORE_CPU_CRG_CALIBRATION1_UNION;
#endif
#define SOC_CORE_CPU_CRG_CALIBRATION1_Tref1_START (0)
#define SOC_CORE_CPU_CRG_CALIBRATION1_Tref1_END (15)
#define SOC_CORE_CPU_CRG_CALIBRATION1_delt_T1_START (16)
#define SOC_CORE_CPU_CRG_CALIBRATION1_delt_T1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int Tref2 : 16;
        unsigned int delt_T2 : 16;
    } reg;
} SOC_CORE_CPU_CRG_CALIBRATION2_UNION;
#endif
#define SOC_CORE_CPU_CRG_CALIBRATION2_Tref2_START (0)
#define SOC_CORE_CPU_CRG_CALIBRATION2_Tref2_END (15)
#define SOC_CORE_CPU_CRG_CALIBRATION2_delt_T2_START (16)
#define SOC_CORE_CPU_CRG_CALIBRATION2_delt_T2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_num : 6;
        unsigned int reserved_0 : 2;
        unsigned int ts_en : 1;
        unsigned int ts_dbgclk_en : 1;
        unsigned int reserved_1 : 6;
        unsigned int ts_cfg : 16;
    } reg;
} SOC_CORE_CPU_CRG_TS_CFG_UNION;
#endif
#define SOC_CORE_CPU_CRG_TS_CFG_sample_num_START (0)
#define SOC_CORE_CPU_CRG_TS_CFG_sample_num_END (5)
#define SOC_CORE_CPU_CRG_TS_CFG_ts_en_START (8)
#define SOC_CORE_CPU_CRG_TS_CFG_ts_en_END (8)
#define SOC_CORE_CPU_CRG_TS_CFG_ts_dbgclk_en_START (9)
#define SOC_CORE_CPU_CRG_TS_CFG_ts_dbgclk_en_END (9)
#define SOC_CORE_CPU_CRG_TS_CFG_ts_cfg_START (16)
#define SOC_CORE_CPU_CRG_TS_CFG_ts_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_B : 16;
        unsigned int data_A : 16;
    } reg;
} SOC_CORE_CPU_CRG_DATA_UNION;
#endif
#define SOC_CORE_CPU_CRG_DATA_data_B_START (0)
#define SOC_CORE_CPU_CRG_DATA_data_B_END (15)
#define SOC_CORE_CPU_CRG_DATA_data_A_START (16)
#define SOC_CORE_CPU_CRG_DATA_data_A_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_B_min : 16;
        unsigned int data_A_min : 16;
    } reg;
} SOC_CORE_CPU_CRG_DATA_MIN_UNION;
#endif
#define SOC_CORE_CPU_CRG_DATA_MIN_data_B_min_START (0)
#define SOC_CORE_CPU_CRG_DATA_MIN_data_B_min_END (15)
#define SOC_CORE_CPU_CRG_DATA_MIN_data_A_min_START (16)
#define SOC_CORE_CPU_CRG_DATA_MIN_data_A_min_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_B_max : 16;
        unsigned int data_A_max : 16;
    } reg;
} SOC_CORE_CPU_CRG_DATA_MAX_UNION;
#endif
#define SOC_CORE_CPU_CRG_DATA_MAX_data_B_max_START (0)
#define SOC_CORE_CPU_CRG_DATA_MAX_data_B_max_END (15)
#define SOC_CORE_CPU_CRG_DATA_MAX_data_A_max_START (16)
#define SOC_CORE_CPU_CRG_DATA_MAX_data_A_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_rsv_ctrl : 32;
    } reg;
} SOC_CORE_CPU_CRG_TS_RSV_CTRL_UNION;
#endif
#define SOC_CORE_CPU_CRG_TS_RSV_CTRL_ts_rsv_ctrl_START (0)
#define SOC_CORE_CPU_CRG_TS_RSV_CTRL_ts_rsv_ctrl_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
