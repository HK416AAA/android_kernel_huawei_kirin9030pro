#ifndef __SOC_CORE_CPU_CRGL_INTERFACE_H__
#define __SOC_CORE_CPU_CRGL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CORE_CPU_CRGL_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_CORE_CPU_CRGL_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_CORE_CPU_CRGL_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_CORE_CPU_CRGL_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ADDR(base) ((base) + (0x010UL))
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ADDR(base) ((base) + (0x014UL))
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ADDR(base) ((base) + (0x018UL))
#define SOC_CORE_CPU_CRGL_CLKDIV0_ADDR(base) ((base) + (0x020UL))
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_ADDR(base) ((base) + (0x024UL))
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_ADDR(base) ((base) + (0x028UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG_RSV_LITTLE_ADDR(base) ((base) + (0x02CUL))
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_ADDR(base) ((base) + (0x030UL))
#define SOC_CORE_CPU_CRGL_FCG_STAT0_ADDR(base) ((base) + (0x034UL))
#define SOC_CORE_CPU_CRGL_FCM_CLKEN_ADDR(base) ((base) + (0x038UL))
#define SOC_CORE_CPU_CRGL_RSV_CFG0_ADDR(base) ((base) + (0x03cUL))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_CFG_A_ADDR(base) ((base) + (0x040UL))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_TIME_CFG_AB_ADDR(base) ((base) + (0x044UL))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_0_A_ADDR(base) ((base) + (0x048UL))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_ADDR(base) ((base) + (0x04cUL))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_ADDR(base) ((base) + (0x050UL))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + (0x054UL))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_ADDR(base) ((base) + (0x058UL))
#define SOC_CORE_CPU_CRGL_APB_ONSYS_ENABLE_ADDR(base) ((base) + (0x05cUL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_ADDR(base) ((base) + (0x060UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_ADDR(base) ((base) + (0x064UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_ADDR(base) ((base) + (0x068UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_ADDR(base) ((base) + (0x06cUL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_ADDR(base) ((base) + (0x070UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_ADDR(base) ((base) + (0x074UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_ADDR(base) ((base) + (0x078UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_ADDR(base) ((base) + (0x07cUL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_ADDR(base) ((base) + (0x080UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG9_A_ADDR(base) ((base) + (0x084UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG10_A_ADDR(base) ((base) + (0x088UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_ADDR(base) ((base) + (0x08cUL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG12_A_ADDR(base) ((base) + (0x090UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG13_A_ADDR(base) ((base) + (0x094UL))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_STAT_A_ADDR(base) ((base) + (0x098UL))
#define SOC_CORE_CPU_CRGL_CLKRST_BYPASS_ADDR(base) ((base) + (0x09cUL))
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_ADDR(base) ((base) + (0x100UL))
#define SOC_CORE_CPU_CRGL_PIM_CFG0_LITTLE_ADDR(base) ((base) + (0x104UL))
#define SOC_CORE_CPU_CRGL_PIM_CFG1_LITTLE_ADDR(base) ((base) + (0x108UL))
#define SOC_CORE_CPU_CRGL_PIM_CFG2_LITTLE_ADDR(base) ((base) + (0x10cUL))
#define SOC_CORE_CPU_CRGL_PIM_CFG3_LITTLE_ADDR(base) ((base) + (0x110UL))
#define SOC_CORE_CPU_CRGL_PIM_STAT0_ADDR(base) ((base) + (0x114UL))
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_ADDR(base) ((base) + (0x118UL))
#define SOC_CORE_CPU_CRGL_MON_CFG1_LITTLE_ADDR(base) ((base) + (0x11cUL))
#define SOC_CORE_CPU_CRGL_MON_CFG2_LITTLE_ADDR(base) ((base) + (0x120UL))
#define SOC_CORE_CPU_CRGL_MON_CFG3_LITTLE_ADDR(base) ((base) + (0x124UL))
#define SOC_CORE_CPU_CRGL_MON_CFG4_LITTLE_ADDR(base) ((base) + (0x128UL))
#define SOC_CORE_CPU_CRGL_MON_CFG5_LITTLE_ADDR(base) ((base) + (0x12cUL))
#define SOC_CORE_CPU_CRGL_MON_CFG6_LITTLE_ADDR(base) ((base) + (0x130UL))
#define SOC_CORE_CPU_CRGL_MON_CFG7_LITTLE_ADDR(base) ((base) + (0x134UL))
#define SOC_CORE_CPU_CRGL_MON_CFG8_LITTLE_ADDR(base) ((base) + (0x138UL))
#define SOC_CORE_CPU_CRGL_MON_CFG9_LITTLE_ADDR(base) ((base) + (0x13cUL))
#define SOC_CORE_CPU_CRGL_MON_CFG10_LITTLE_ADDR(base) ((base) + (0x140UL))
#define SOC_CORE_CPU_CRGL_MON_CFG11_LITTLE_ADDR(base) ((base) + (0x144UL))
#define SOC_CORE_CPU_CRGL_MON_CFG12_LITTLE_ADDR(base) ((base) + (0x148UL))
#define SOC_CORE_CPU_CRGL_MON_CFG13_LITTLE_ADDR(base) ((base) + (0x14cUL))
#define SOC_CORE_CPU_CRGL_MON_CFG14_LITTLE_ADDR(base) ((base) + (0x150UL))
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_ADDR(base) ((base) + (0x154UL))
#define SOC_CORE_CPU_CRGL_MON_CFG16_LITTLE_ADDR(base) ((base) + (0x158UL))
#define SOC_CORE_CPU_CRGL_MON_STAT0_LITTLE_ADDR(base) ((base) + (0x15cUL))
#define SOC_CORE_CPU_CRGL_MON_STAT1_LITTLE_ADDR(base) ((base) + (0x160UL))
#define SOC_CORE_CPU_CRGL_MON_STAT2_LITTLE_ADDR(base) ((base) + (0x164UL))
#define SOC_CORE_CPU_CRGL_MON_STAT3_LITTLE_ADDR(base) ((base) + (0x168UL))
#define SOC_CORE_CPU_CRGL_MON_STAT4_LITTLE_ADDR(base) ((base) + (0x16cUL))
#define SOC_CORE_CPU_CRGL_MON_STAT5_LITTLE_ADDR(base) ((base) + (0x170UL))
#define SOC_CORE_CPU_CRGL_MON_STAT6_LITTLE_ADDR(base) ((base) + (0x174UL))
#define SOC_CORE_CPU_CRGL_MON_STAT7_LITTLE_ADDR(base) ((base) + (0x178UL))
#define SOC_CORE_CPU_CRGL_MON_STAT8_LITTLE_ADDR(base) ((base) + (0x17cUL))
#define SOC_CORE_CPU_CRGL_MON_STAT9_LITTLE_ADDR(base) ((base) + (0x180UL))
#define SOC_CORE_CPU_CRGL_MON_STAT10_LITTLE_ADDR(base) ((base) + (0x184UL))
#define SOC_CORE_CPU_CRGL_MON_STAT11_LITTLE_ADDR(base) ((base) + (0x188UL))
#define SOC_CORE_CPU_CRGL_MON_STAT12_LITTLE_ADDR(base) ((base) + (0x18cUL))
#define SOC_CORE_CPU_CRGL_MON_STAT13_LITTLE_ADDR(base) ((base) + (0x190UL))
#define SOC_CORE_CPU_CRGL_MON_STAT14_LITTLE_ADDR(base) ((base) + (0x194UL))
#define SOC_CORE_CPU_CRGL_MON_STAT15_LITTLE_ADDR(base) ((base) + (0x198UL))
#define SOC_CORE_CPU_CRGL_MON_STAT16_LITTLE_ADDR(base) ((base) + (0x19cUL))
#define SOC_CORE_CPU_CRGL_MON_STAT17_LITTLE_ADDR(base) ((base) + (0x1A0UL))
#define SOC_CORE_CPU_CRGL_MON_STAT18_LITTLE_ADDR(base) ((base) + (0x1A4UL))
#define SOC_CORE_CPU_CRGL_MON_STAT19_LITTLE_ADDR(base) ((base) + (0x1A8UL))
#define SOC_CORE_CPU_CRGL_MON_STAT20_LITTLE_ADDR(base) ((base) + (0x1ACUL))
#define SOC_CORE_CPU_CRGL_MON_STAT21_LITTLE_ADDR(base) ((base) + (0x1B0UL))
#define SOC_CORE_CPU_CRGL_MON_STAT22_LITTLE_ADDR(base) ((base) + (0x1B4UL))
#define SOC_CORE_CPU_CRGL_MON_STAT23_LITTLE_ADDR(base) ((base) + (0x1B8UL))
#define SOC_CORE_CPU_CRGL_MON_STAT24_LITTLE_ADDR(base) ((base) + (0x1BCUL))
#define SOC_CORE_CPU_CRGL_MON_STAT25_LITTLE_ADDR(base) ((base) + (0x1C0UL))
#define SOC_CORE_CPU_CRGL_CLKDIV2_ADDR(base) ((base) + (0x204UL))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_ADDR(base) ((base) + (0x208UL))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_ADDR(base) ((base) + (0x20CUL))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_ADDR(base) ((base) + (0x210UL))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_ADDR(base) ((base) + (0x214UL))
#define SOC_CORE_CPU_CRGL_BHS_CFG_0_ADDR(base) ((base) + (0x218UL))
#define SOC_CORE_CPU_CRGL_BHS_CFG_1_ADDR(base) ((base) + (0x21CUL))
#define SOC_CORE_CPU_CRGL_BHS_CFG_2_ADDR(base) ((base) + (0x220UL))
#define SOC_CORE_CPU_CRGL_BHS_CFG_3_ADDR(base) ((base) + (0x224UL))
#define SOC_CORE_CPU_CRGL_BHS_STAT_0_ADDR(base) ((base) + (0x228UL))
#define SOC_CORE_CPU_CRGL_BHS_STAT_1_ADDR(base) ((base) + (0x22CUL))
#define SOC_CORE_CPU_CRGL_BHS_STAT_2_ADDR(base) ((base) + (0x230UL))
#define SOC_CORE_CPU_CRGL_BHS_STAT_3_ADDR(base) ((base) + (0x234UL))
#define SOC_CORE_CPU_CRGL_BHS_OUT_0_ADDR(base) ((base) + (0x238UL))
#define SOC_CORE_CPU_CRGL_BHS_OUT_1_ADDR(base) ((base) + (0x23cUL))
#define SOC_CORE_CPU_CRGL_BHS_OUT_2_ADDR(base) ((base) + (0x240UL))
#define SOC_CORE_CPU_CRGL_BHS_OUT_3_ADDR(base) ((base) + (0x244UL))
#define SOC_CORE_CPU_CRGL_BHS_CFG4_ADDR(base) ((base) + (0x248UL))
#define SOC_CORE_CPU_CRGL_BHS_CFG5_ADDR(base) ((base) + (0x24cUL))
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_ADDR(base) ((base) + (0x260UL))
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL1_ADDR(base) ((base) + (0x264UL))
#define SOC_CORE_CPU_CRGL_FCG_CNT_STATE0_ADDR(base) ((base) + (0x268UL))
#define SOC_CORE_CPU_CRGL_CLKDIV3_ADDR(base) ((base) + (0x26cUL))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG0_LITTLE_ADDR(base) ((base) + (0x300UL))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG1_LITTLE_ADDR(base) ((base) + (0x304UL))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG2_LITTLE_ADDR(base) ((base) + (0x308UL))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG3_LITTLE_ADDR(base) ((base) + (0x30CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG0_LITTLE_ADDR(base) ((base) + (0x318UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG1_LITTLE_ADDR(base) ((base) + (0x31CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG2_LITTLE_ADDR(base) ((base) + (0x320UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG3_LITTLE_ADDR(base) ((base) + (0x324UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG4_LITTLE_ADDR(base) ((base) + (0x328UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG5_LITTLE_ADDR(base) ((base) + (0x32CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG6_LITTLE_ADDR(base) ((base) + (0x330UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG7_LITTLE_ADDR(base) ((base) + (0x334UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG8_LITTLE_ADDR(base) ((base) + (0x338UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG9_LITTLE_ADDR(base) ((base) + (0x33CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG10_LITTLE_ADDR(base) ((base) + (0x340UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG11_LITTLE_ADDR(base) ((base) + (0x344UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG12_LITTLE_ADDR(base) ((base) + (0x348UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG13_LITTLE_ADDR(base) ((base) + (0x34CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG14_LITTLE_ADDR(base) ((base) + (0x350UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG15_LITTLE_ADDR(base) ((base) + (0x354UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG16_LITTLE_ADDR(base) ((base) + (0x358UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG17_LITTLE_ADDR(base) ((base) + (0x35CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG18_LITTLE_ADDR(base) ((base) + (0x360UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG19_LITTLE_ADDR(base) ((base) + (0x364UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG20_LITTLE_ADDR(base) ((base) + (0x368UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG21_LITTLE_ADDR(base) ((base) + (0x36CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG22_LITTLE_ADDR(base) ((base) + (0x370UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG23_LITTLE_ADDR(base) ((base) + (0x374UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG24_LITTLE_ADDR(base) ((base) + (0x378UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG25_LITTLE_ADDR(base) ((base) + (0x37CUL))
#define SOC_CORE_CPU_CRGL_FCG_CFG26_LITTLE_ADDR(base) ((base) + (0x380UL))
#define SOC_CORE_CPU_CRGL_FCG_CFG27_LITTLE_ADDR(base) ((base) + (0x384UL))
#define SOC_CORE_CPU_CRGL_FCG_STAT0_LITTLE_ADDR(base) ((base) + (0x390UL))
#define SOC_CORE_CPU_CRGL_FCG_STAT1_LITTLE_ADDR(base) ((base) + (0x394UL))
#define SOC_CORE_CPU_CRGL_FCG_STAT2_LITTLE_ADDR(base) ((base) + (0x398UL))
#define SOC_CORE_CPU_CRGL_FCG_STAT3_LITTLE_ADDR(base) ((base) + (0x39CUL))
#define SOC_CORE_CPU_CRGL_FCG_STAT4_LITTLE_ADDR(base) ((base) + (0x3A0UL))
#define SOC_CORE_CPU_CRGL_FCG_STAT5_LITTLE_ADDR(base) ((base) + (0x3A4UL))
#else
#define SOC_CORE_CPU_CRGL_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_CORE_CPU_CRGL_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_CORE_CPU_CRGL_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_CORE_CPU_CRGL_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ADDR(base) ((base) + (0x010))
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ADDR(base) ((base) + (0x014))
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ADDR(base) ((base) + (0x018))
#define SOC_CORE_CPU_CRGL_CLKDIV0_ADDR(base) ((base) + (0x020))
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_ADDR(base) ((base) + (0x024))
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_ADDR(base) ((base) + (0x028))
#define SOC_CORE_CPU_CRGL_FCG_CFG_RSV_LITTLE_ADDR(base) ((base) + (0x02C))
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_ADDR(base) ((base) + (0x030))
#define SOC_CORE_CPU_CRGL_FCG_STAT0_ADDR(base) ((base) + (0x034))
#define SOC_CORE_CPU_CRGL_FCM_CLKEN_ADDR(base) ((base) + (0x038))
#define SOC_CORE_CPU_CRGL_RSV_CFG0_ADDR(base) ((base) + (0x03c))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_CFG_A_ADDR(base) ((base) + (0x040))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_TIME_CFG_AB_ADDR(base) ((base) + (0x044))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_0_A_ADDR(base) ((base) + (0x048))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_ADDR(base) ((base) + (0x04c))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_ADDR(base) ((base) + (0x050))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_IDX_ADDR(base) ((base) + (0x054))
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_ADDR(base) ((base) + (0x058))
#define SOC_CORE_CPU_CRGL_APB_ONSYS_ENABLE_ADDR(base) ((base) + (0x05c))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_ADDR(base) ((base) + (0x060))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_ADDR(base) ((base) + (0x064))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_ADDR(base) ((base) + (0x068))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_ADDR(base) ((base) + (0x06c))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_ADDR(base) ((base) + (0x070))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_ADDR(base) ((base) + (0x074))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_ADDR(base) ((base) + (0x078))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_ADDR(base) ((base) + (0x07c))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_ADDR(base) ((base) + (0x080))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG9_A_ADDR(base) ((base) + (0x084))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG10_A_ADDR(base) ((base) + (0x088))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_ADDR(base) ((base) + (0x08c))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG12_A_ADDR(base) ((base) + (0x090))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG13_A_ADDR(base) ((base) + (0x094))
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_STAT_A_ADDR(base) ((base) + (0x098))
#define SOC_CORE_CPU_CRGL_CLKRST_BYPASS_ADDR(base) ((base) + (0x09c))
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_ADDR(base) ((base) + (0x100))
#define SOC_CORE_CPU_CRGL_PIM_CFG0_LITTLE_ADDR(base) ((base) + (0x104))
#define SOC_CORE_CPU_CRGL_PIM_CFG1_LITTLE_ADDR(base) ((base) + (0x108))
#define SOC_CORE_CPU_CRGL_PIM_CFG2_LITTLE_ADDR(base) ((base) + (0x10c))
#define SOC_CORE_CPU_CRGL_PIM_CFG3_LITTLE_ADDR(base) ((base) + (0x110))
#define SOC_CORE_CPU_CRGL_PIM_STAT0_ADDR(base) ((base) + (0x114))
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_ADDR(base) ((base) + (0x118))
#define SOC_CORE_CPU_CRGL_MON_CFG1_LITTLE_ADDR(base) ((base) + (0x11c))
#define SOC_CORE_CPU_CRGL_MON_CFG2_LITTLE_ADDR(base) ((base) + (0x120))
#define SOC_CORE_CPU_CRGL_MON_CFG3_LITTLE_ADDR(base) ((base) + (0x124))
#define SOC_CORE_CPU_CRGL_MON_CFG4_LITTLE_ADDR(base) ((base) + (0x128))
#define SOC_CORE_CPU_CRGL_MON_CFG5_LITTLE_ADDR(base) ((base) + (0x12c))
#define SOC_CORE_CPU_CRGL_MON_CFG6_LITTLE_ADDR(base) ((base) + (0x130))
#define SOC_CORE_CPU_CRGL_MON_CFG7_LITTLE_ADDR(base) ((base) + (0x134))
#define SOC_CORE_CPU_CRGL_MON_CFG8_LITTLE_ADDR(base) ((base) + (0x138))
#define SOC_CORE_CPU_CRGL_MON_CFG9_LITTLE_ADDR(base) ((base) + (0x13c))
#define SOC_CORE_CPU_CRGL_MON_CFG10_LITTLE_ADDR(base) ((base) + (0x140))
#define SOC_CORE_CPU_CRGL_MON_CFG11_LITTLE_ADDR(base) ((base) + (0x144))
#define SOC_CORE_CPU_CRGL_MON_CFG12_LITTLE_ADDR(base) ((base) + (0x148))
#define SOC_CORE_CPU_CRGL_MON_CFG13_LITTLE_ADDR(base) ((base) + (0x14c))
#define SOC_CORE_CPU_CRGL_MON_CFG14_LITTLE_ADDR(base) ((base) + (0x150))
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_ADDR(base) ((base) + (0x154))
#define SOC_CORE_CPU_CRGL_MON_CFG16_LITTLE_ADDR(base) ((base) + (0x158))
#define SOC_CORE_CPU_CRGL_MON_STAT0_LITTLE_ADDR(base) ((base) + (0x15c))
#define SOC_CORE_CPU_CRGL_MON_STAT1_LITTLE_ADDR(base) ((base) + (0x160))
#define SOC_CORE_CPU_CRGL_MON_STAT2_LITTLE_ADDR(base) ((base) + (0x164))
#define SOC_CORE_CPU_CRGL_MON_STAT3_LITTLE_ADDR(base) ((base) + (0x168))
#define SOC_CORE_CPU_CRGL_MON_STAT4_LITTLE_ADDR(base) ((base) + (0x16c))
#define SOC_CORE_CPU_CRGL_MON_STAT5_LITTLE_ADDR(base) ((base) + (0x170))
#define SOC_CORE_CPU_CRGL_MON_STAT6_LITTLE_ADDR(base) ((base) + (0x174))
#define SOC_CORE_CPU_CRGL_MON_STAT7_LITTLE_ADDR(base) ((base) + (0x178))
#define SOC_CORE_CPU_CRGL_MON_STAT8_LITTLE_ADDR(base) ((base) + (0x17c))
#define SOC_CORE_CPU_CRGL_MON_STAT9_LITTLE_ADDR(base) ((base) + (0x180))
#define SOC_CORE_CPU_CRGL_MON_STAT10_LITTLE_ADDR(base) ((base) + (0x184))
#define SOC_CORE_CPU_CRGL_MON_STAT11_LITTLE_ADDR(base) ((base) + (0x188))
#define SOC_CORE_CPU_CRGL_MON_STAT12_LITTLE_ADDR(base) ((base) + (0x18c))
#define SOC_CORE_CPU_CRGL_MON_STAT13_LITTLE_ADDR(base) ((base) + (0x190))
#define SOC_CORE_CPU_CRGL_MON_STAT14_LITTLE_ADDR(base) ((base) + (0x194))
#define SOC_CORE_CPU_CRGL_MON_STAT15_LITTLE_ADDR(base) ((base) + (0x198))
#define SOC_CORE_CPU_CRGL_MON_STAT16_LITTLE_ADDR(base) ((base) + (0x19c))
#define SOC_CORE_CPU_CRGL_MON_STAT17_LITTLE_ADDR(base) ((base) + (0x1A0))
#define SOC_CORE_CPU_CRGL_MON_STAT18_LITTLE_ADDR(base) ((base) + (0x1A4))
#define SOC_CORE_CPU_CRGL_MON_STAT19_LITTLE_ADDR(base) ((base) + (0x1A8))
#define SOC_CORE_CPU_CRGL_MON_STAT20_LITTLE_ADDR(base) ((base) + (0x1AC))
#define SOC_CORE_CPU_CRGL_MON_STAT21_LITTLE_ADDR(base) ((base) + (0x1B0))
#define SOC_CORE_CPU_CRGL_MON_STAT22_LITTLE_ADDR(base) ((base) + (0x1B4))
#define SOC_CORE_CPU_CRGL_MON_STAT23_LITTLE_ADDR(base) ((base) + (0x1B8))
#define SOC_CORE_CPU_CRGL_MON_STAT24_LITTLE_ADDR(base) ((base) + (0x1BC))
#define SOC_CORE_CPU_CRGL_MON_STAT25_LITTLE_ADDR(base) ((base) + (0x1C0))
#define SOC_CORE_CPU_CRGL_CLKDIV2_ADDR(base) ((base) + (0x204))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_ADDR(base) ((base) + (0x208))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_ADDR(base) ((base) + (0x20C))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_ADDR(base) ((base) + (0x210))
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_ADDR(base) ((base) + (0x214))
#define SOC_CORE_CPU_CRGL_BHS_CFG_0_ADDR(base) ((base) + (0x218))
#define SOC_CORE_CPU_CRGL_BHS_CFG_1_ADDR(base) ((base) + (0x21C))
#define SOC_CORE_CPU_CRGL_BHS_CFG_2_ADDR(base) ((base) + (0x220))
#define SOC_CORE_CPU_CRGL_BHS_CFG_3_ADDR(base) ((base) + (0x224))
#define SOC_CORE_CPU_CRGL_BHS_STAT_0_ADDR(base) ((base) + (0x228))
#define SOC_CORE_CPU_CRGL_BHS_STAT_1_ADDR(base) ((base) + (0x22C))
#define SOC_CORE_CPU_CRGL_BHS_STAT_2_ADDR(base) ((base) + (0x230))
#define SOC_CORE_CPU_CRGL_BHS_STAT_3_ADDR(base) ((base) + (0x234))
#define SOC_CORE_CPU_CRGL_BHS_OUT_0_ADDR(base) ((base) + (0x238))
#define SOC_CORE_CPU_CRGL_BHS_OUT_1_ADDR(base) ((base) + (0x23c))
#define SOC_CORE_CPU_CRGL_BHS_OUT_2_ADDR(base) ((base) + (0x240))
#define SOC_CORE_CPU_CRGL_BHS_OUT_3_ADDR(base) ((base) + (0x244))
#define SOC_CORE_CPU_CRGL_BHS_CFG4_ADDR(base) ((base) + (0x248))
#define SOC_CORE_CPU_CRGL_BHS_CFG5_ADDR(base) ((base) + (0x24c))
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_ADDR(base) ((base) + (0x260))
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL1_ADDR(base) ((base) + (0x264))
#define SOC_CORE_CPU_CRGL_FCG_CNT_STATE0_ADDR(base) ((base) + (0x268))
#define SOC_CORE_CPU_CRGL_CLKDIV3_ADDR(base) ((base) + (0x26c))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG0_LITTLE_ADDR(base) ((base) + (0x300))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG1_LITTLE_ADDR(base) ((base) + (0x304))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG2_LITTLE_ADDR(base) ((base) + (0x308))
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG3_LITTLE_ADDR(base) ((base) + (0x30C))
#define SOC_CORE_CPU_CRGL_FCG_CFG0_LITTLE_ADDR(base) ((base) + (0x318))
#define SOC_CORE_CPU_CRGL_FCG_CFG1_LITTLE_ADDR(base) ((base) + (0x31C))
#define SOC_CORE_CPU_CRGL_FCG_CFG2_LITTLE_ADDR(base) ((base) + (0x320))
#define SOC_CORE_CPU_CRGL_FCG_CFG3_LITTLE_ADDR(base) ((base) + (0x324))
#define SOC_CORE_CPU_CRGL_FCG_CFG4_LITTLE_ADDR(base) ((base) + (0x328))
#define SOC_CORE_CPU_CRGL_FCG_CFG5_LITTLE_ADDR(base) ((base) + (0x32C))
#define SOC_CORE_CPU_CRGL_FCG_CFG6_LITTLE_ADDR(base) ((base) + (0x330))
#define SOC_CORE_CPU_CRGL_FCG_CFG7_LITTLE_ADDR(base) ((base) + (0x334))
#define SOC_CORE_CPU_CRGL_FCG_CFG8_LITTLE_ADDR(base) ((base) + (0x338))
#define SOC_CORE_CPU_CRGL_FCG_CFG9_LITTLE_ADDR(base) ((base) + (0x33C))
#define SOC_CORE_CPU_CRGL_FCG_CFG10_LITTLE_ADDR(base) ((base) + (0x340))
#define SOC_CORE_CPU_CRGL_FCG_CFG11_LITTLE_ADDR(base) ((base) + (0x344))
#define SOC_CORE_CPU_CRGL_FCG_CFG12_LITTLE_ADDR(base) ((base) + (0x348))
#define SOC_CORE_CPU_CRGL_FCG_CFG13_LITTLE_ADDR(base) ((base) + (0x34C))
#define SOC_CORE_CPU_CRGL_FCG_CFG14_LITTLE_ADDR(base) ((base) + (0x350))
#define SOC_CORE_CPU_CRGL_FCG_CFG15_LITTLE_ADDR(base) ((base) + (0x354))
#define SOC_CORE_CPU_CRGL_FCG_CFG16_LITTLE_ADDR(base) ((base) + (0x358))
#define SOC_CORE_CPU_CRGL_FCG_CFG17_LITTLE_ADDR(base) ((base) + (0x35C))
#define SOC_CORE_CPU_CRGL_FCG_CFG18_LITTLE_ADDR(base) ((base) + (0x360))
#define SOC_CORE_CPU_CRGL_FCG_CFG19_LITTLE_ADDR(base) ((base) + (0x364))
#define SOC_CORE_CPU_CRGL_FCG_CFG20_LITTLE_ADDR(base) ((base) + (0x368))
#define SOC_CORE_CPU_CRGL_FCG_CFG21_LITTLE_ADDR(base) ((base) + (0x36C))
#define SOC_CORE_CPU_CRGL_FCG_CFG22_LITTLE_ADDR(base) ((base) + (0x370))
#define SOC_CORE_CPU_CRGL_FCG_CFG23_LITTLE_ADDR(base) ((base) + (0x374))
#define SOC_CORE_CPU_CRGL_FCG_CFG24_LITTLE_ADDR(base) ((base) + (0x378))
#define SOC_CORE_CPU_CRGL_FCG_CFG25_LITTLE_ADDR(base) ((base) + (0x37C))
#define SOC_CORE_CPU_CRGL_FCG_CFG26_LITTLE_ADDR(base) ((base) + (0x380))
#define SOC_CORE_CPU_CRGL_FCG_CFG27_LITTLE_ADDR(base) ((base) + (0x384))
#define SOC_CORE_CPU_CRGL_FCG_STAT0_LITTLE_ADDR(base) ((base) + (0x390))
#define SOC_CORE_CPU_CRGL_FCG_STAT1_LITTLE_ADDR(base) ((base) + (0x394))
#define SOC_CORE_CPU_CRGL_FCG_STAT2_LITTLE_ADDR(base) ((base) + (0x398))
#define SOC_CORE_CPU_CRGL_FCG_STAT3_LITTLE_ADDR(base) ((base) + (0x39C))
#define SOC_CORE_CPU_CRGL_FCG_STAT4_LITTLE_ADDR(base) ((base) + (0x3A0))
#define SOC_CORE_CPU_CRGL_FCG_STAT5_LITTLE_ADDR(base) ((base) + (0x3A4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_little : 1;
        unsigned int gt_clk_pim_little : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int gt_clk_fcg_freq_ctrl_little : 1;
        unsigned int gt_pclk_fcg_little : 1;
        unsigned int gt_clk_fdcs_mon_little : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
        unsigned int gt_clk_bhs3 : 1;
        unsigned int gt_clk_bhs2 : 1;
        unsigned int gt_clk_bhs1 : 1;
        unsigned int gt_clk_bhs0 : 1;
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
        unsigned int reserved_12 : 7;
    } reg;
} SOC_CORE_CPU_CRGL_PEREN0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_pim_little_START (1)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_pim_little_END (1)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fdcs_xpu_ctrl_little_START (2)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fdcs_xpu_ctrl_little_END (2)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_pclk_fcg_little_START (4)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_pclk_fcg_little_END (4)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fdcs_mon_little_START (5)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fdcs_mon_little_END (5)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs3_START (9)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs3_END (9)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs2_START (10)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs2_END (10)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs1_START (11)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs1_END (11)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs0_START (12)
#define SOC_CORE_CPU_CRGL_PEREN0_gt_clk_bhs0_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_little : 1;
        unsigned int gt_clk_pim_little : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int gt_clk_fcg_freq_ctrl_little : 1;
        unsigned int gt_pclk_fcg_little : 1;
        unsigned int gt_clk_fdcs_mon_little : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
        unsigned int gt_clk_bhs3 : 1;
        unsigned int gt_clk_bhs2 : 1;
        unsigned int gt_clk_bhs1 : 1;
        unsigned int gt_clk_bhs0 : 1;
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
        unsigned int reserved_12 : 7;
    } reg;
} SOC_CORE_CPU_CRGL_PERDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_pim_little_START (1)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_pim_little_END (1)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fdcs_xpu_ctrl_little_START (2)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fdcs_xpu_ctrl_little_END (2)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_pclk_fcg_little_START (4)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_pclk_fcg_little_END (4)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fdcs_mon_little_START (5)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fdcs_mon_little_END (5)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs3_START (9)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs3_END (9)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs2_START (10)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs2_END (10)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs1_START (11)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs1_END (11)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs0_START (12)
#define SOC_CORE_CPU_CRGL_PERDIS0_gt_clk_bhs0_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_fcg_sscg_little : 1;
        unsigned int gt_clk_pim_little : 1;
        unsigned int gt_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int gt_clk_fcg_freq_ctrl_little : 1;
        unsigned int gt_pclk_fcg_little : 1;
        unsigned int gt_clk_fdcs_mon_little : 1;
        unsigned int gt_pclk_onsys_avs_cpu : 1;
        unsigned int gt_clk_fcg_cnt : 1;
        unsigned int gt_clk_fcg_ref : 1;
        unsigned int gt_clk_bhs3 : 1;
        unsigned int gt_clk_bhs2 : 1;
        unsigned int gt_clk_bhs1 : 1;
        unsigned int gt_clk_bhs0 : 1;
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
        unsigned int reserved_12 : 7;
    } reg;
} SOC_CORE_CPU_CRGL_PERCLKEN0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_pim_little_START (1)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_pim_little_END (1)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_little_START (2)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fdcs_xpu_ctrl_little_END (2)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_pclk_fcg_little_START (4)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_pclk_fcg_little_END (4)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fdcs_mon_little_START (5)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fdcs_mon_little_END (5)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs3_START (9)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs3_END (9)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs2_START (10)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs2_END (10)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs1_START (11)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs1_END (11)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs0_START (12)
#define SOC_CORE_CPU_CRGL_PERCLKEN0_gt_clk_bhs0_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_fcg_sscg_little : 1;
        unsigned int st_clk_pim_little : 1;
        unsigned int st_clk_fdcs_xpu_ctrl_little : 1;
        unsigned int st_clk_fcg_freq_ctrl_little : 1;
        unsigned int st_pclk_fcg_little : 1;
        unsigned int st_clk_fdcs_mon_little : 1;
        unsigned int st_pclk_onsys_avs_cpu : 1;
        unsigned int st_clk_fcg_cnt : 1;
        unsigned int st_clk_fcg_ref : 1;
        unsigned int st_clk_bhs3 : 1;
        unsigned int st_clk_bhs2 : 1;
        unsigned int st_clk_bhs1 : 1;
        unsigned int st_clk_bhs0 : 1;
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
        unsigned int st_clk_fcg_pre : 1;
        unsigned int reserved_11 : 7;
    } reg;
} SOC_CORE_CPU_CRGL_PERSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_sscg_little_START (0)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_sscg_little_END (0)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_pim_little_START (1)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_pim_little_END (1)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fdcs_xpu_ctrl_little_START (2)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fdcs_xpu_ctrl_little_END (2)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_pclk_fcg_little_START (4)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_pclk_fcg_little_END (4)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fdcs_mon_little_START (5)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fdcs_mon_little_END (5)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_pclk_onsys_avs_cpu_START (6)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_pclk_onsys_avs_cpu_END (6)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_cnt_START (7)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_ref_END (8)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs3_START (9)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs3_END (9)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs2_START (10)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs2_END (10)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs1_START (11)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs1_END (11)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs0_START (12)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_bhs0_END (12)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_pre_START (24)
#define SOC_CORE_CPU_CRGL_PERSTAT0_st_clk_fcg_pre_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_little : 1;
        unsigned int ip_rst_fdcs_mon_little : 1;
        unsigned int ip_prst_fcg_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_little : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_little : 1;
        unsigned int ip_rst_bhs3 : 1;
        unsigned int ip_rst_bhs2 : 1;
        unsigned int ip_rst_bhs1 : 1;
        unsigned int ip_rst_bhs0 : 1;
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
} SOC_CORE_CPU_CRGL_PERRSTEN0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_little_START (0)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fdcs_xpu_ctrl_little_END (0)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fdcs_mon_little_START (1)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fdcs_mon_little_END (1)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_prst_fcg_little_START (2)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_prst_fcg_little_END (2)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fcg_freq_cnt_little_START (5)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_fcg_freq_cnt_little_END (5)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs3_START (6)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs3_END (6)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs2_START (7)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs2_END (7)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs1_START (8)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs1_END (8)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs0_START (9)
#define SOC_CORE_CPU_CRGL_PERRSTEN0_ip_rst_bhs0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_little : 1;
        unsigned int ip_rst_fdcs_mon_little : 1;
        unsigned int ip_prst_fcg_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_little : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_little : 1;
        unsigned int ip_rst_bhs3 : 1;
        unsigned int ip_rst_bhs2 : 1;
        unsigned int ip_rst_bhs1 : 1;
        unsigned int ip_rst_bhs0 : 1;
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
} SOC_CORE_CPU_CRGL_PERRSTDIS0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_little_START (0)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fdcs_xpu_ctrl_little_END (0)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fdcs_mon_little_START (1)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fdcs_mon_little_END (1)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_prst_fcg_little_START (2)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_prst_fcg_little_END (2)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fcg_freq_cnt_little_START (5)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_fcg_freq_cnt_little_END (5)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs3_START (6)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs3_END (6)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs2_START (7)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs2_END (7)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs1_START (8)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs1_END (8)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs0_START (9)
#define SOC_CORE_CPU_CRGL_PERRSTDIS0_ip_rst_bhs0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_fdcs_xpu_ctrl_little : 1;
        unsigned int ip_rst_fdcs_mon_little : 1;
        unsigned int ip_prst_fcg_little : 1;
        unsigned int ip_rst_fcg_freq_ctrl_little : 1;
        unsigned int ip_prst_onsys_avs_cpu : 1;
        unsigned int ip_rst_fcg_freq_cnt_little : 1;
        unsigned int ip_rst_bhs3 : 1;
        unsigned int ip_rst_bhs2 : 1;
        unsigned int ip_rst_bhs1 : 1;
        unsigned int ip_rst_bhs0 : 1;
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
} SOC_CORE_CPU_CRGL_PERRSTSTAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_little_START (0)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fdcs_xpu_ctrl_little_END (0)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fdcs_mon_little_START (1)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fdcs_mon_little_END (1)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_prst_fcg_little_START (2)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_prst_fcg_little_END (2)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_little_START (3)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fcg_freq_ctrl_little_END (3)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_prst_onsys_avs_cpu_START (4)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_prst_onsys_avs_cpu_END (4)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fcg_freq_cnt_little_START (5)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_fcg_freq_cnt_little_END (5)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs3_START (6)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs3_END (6)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs2_START (7)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs2_END (7)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs1_START (8)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs1_END (8)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs0_START (9)
#define SOC_CORE_CPU_CRGL_PERRSTSTAT0_ip_rst_bhs0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_test_mce_cpul : 1;
        unsigned int sel_clk_cpul_path : 1;
        unsigned int sc_gt_clk_fcg_little_tp : 1;
        unsigned int div_fcg_little_tp : 6;
        unsigned int temp_code_bypass : 1;
        unsigned int bhs3_bypass : 1;
        unsigned int bhs2_bypass : 1;
        unsigned int bhs1_bypass : 1;
        unsigned int bhs0_bypass : 1;
        unsigned int eisc_clk_gt_en_bypass : 1;
        unsigned int temp_update_enable : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGL_CLKDIV0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_CLKDIV0_sel_test_mce_cpul_START (0)
#define SOC_CORE_CPU_CRGL_CLKDIV0_sel_test_mce_cpul_END (0)
#define SOC_CORE_CPU_CRGL_CLKDIV0_sel_clk_cpul_path_START (1)
#define SOC_CORE_CPU_CRGL_CLKDIV0_sel_clk_cpul_path_END (1)
#define SOC_CORE_CPU_CRGL_CLKDIV0_sc_gt_clk_fcg_little_tp_START (2)
#define SOC_CORE_CPU_CRGL_CLKDIV0_sc_gt_clk_fcg_little_tp_END (2)
#define SOC_CORE_CPU_CRGL_CLKDIV0_div_fcg_little_tp_START (3)
#define SOC_CORE_CPU_CRGL_CLKDIV0_div_fcg_little_tp_END (8)
#define SOC_CORE_CPU_CRGL_CLKDIV0_temp_code_bypass_START (9)
#define SOC_CORE_CPU_CRGL_CLKDIV0_temp_code_bypass_END (9)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs3_bypass_START (10)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs3_bypass_END (10)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs2_bypass_START (11)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs2_bypass_END (11)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs1_bypass_START (12)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs1_bypass_END (12)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs0_bypass_START (13)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bhs0_bypass_END (13)
#define SOC_CORE_CPU_CRGL_CLKDIV0_eisc_clk_gt_en_bypass_START (14)
#define SOC_CORE_CPU_CRGL_CLKDIV0_eisc_clk_gt_en_bypass_END (14)
#define SOC_CORE_CPU_CRGL_CLKDIV0_temp_update_enable_START (15)
#define SOC_CORE_CPU_CRGL_CLKDIV0_temp_update_enable_END (15)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_CLKDIV0_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_pim_drop_en_bypass_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_pim_drop_en_bypass_END (0)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_pim_peaklow_en_bypass_START (1)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_pim_peaklow_en_bypass_END (1)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_pim_drop_update_bypass_START (2)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_pim_drop_update_bypass_END (2)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_cnt_thr_START (3)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_cnt_thr_END (6)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_ffc_en_bypass_START (7)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_ffc_en_bypass_END (7)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_ffc_cnt_thr_START (8)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_ffc_cnt_thr_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_FDCS_XPU_CFG_LITTLE_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_pcr_trig_vdm_en_START (0)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_pcr_trig_vdm_en_END (0)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_wfx_bypass_START (1)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_wfx_bypass_END (4)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_l2_idle_div_mod_START (5)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_l2_idle_div_mod_END (5)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_freq_dn_mst_sel_START (6)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_freq_dn_mst_sel_END (6)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_wake_up_mode_START (23)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_wake_up_mode_END (24)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_gt_en_START (26)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_cpu_l2_idle_gt_en_END (26)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_vbat_drop_icg_en_START (27)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_vbat_drop_icg_en_END (27)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_vbat_drop_fcg_en_START (28)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_vbat_drop_fcg_en_END (28)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_coreidle_bypass_START (29)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_coreidle_bypass_END (29)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_pcr_fs_icg_en_START (30)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_pcr_fs_icg_en_END (30)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_pcr_fs_fcg_en_START (31)
#define SOC_CORE_CPU_CRGL_FCG_FREQ_CTRL_LITTLE_pcr_fs_fcg_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg_rsv_little : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG_RSV_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG_RSV_LITTLE_fcg_cfg_rsv_little_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG_RSV_LITTLE_fcg_cfg_rsv_little_END (15)
#define SOC_CORE_CPU_CRGL_FCG_CFG_RSV_LITTLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_FCG_CFG_RSV_LITTLE_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_enable_START (0)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_enable_END (0)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_mode_START (1)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_mode_END (1)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_rate_START (2)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_rate_END (5)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_depth_START (6)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_depth_END (8)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_fast_dis_START (9)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_sscg_fast_dis_END (9)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_SSC_FCG_CFG_LITTLE_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat_little : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_STAT0_fcg_stat_little_START (0)
#define SOC_CORE_CPU_CRGL_FCG_STAT0_fcg_stat_little_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_cpu_little : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGL_FCM_CLKEN_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCM_CLKEN_gt_clk_cpu_little_START (0)
#define SOC_CORE_CPU_CRGL_FCM_CLKEN_gt_clk_cpu_little_END (0)
#define SOC_CORE_CPU_CRGL_FCM_CLKEN_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_FCM_CLKEN_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsv_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_RSV_CFG0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_RSV_CFG0_rsv_cfg0_START (0)
#define SOC_CORE_CPU_CRGL_RSV_CFG0_rsv_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int onsys_avs_cfg_a : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGL_ONSYS_AVS_CFG_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_CFG_A_onsys_avs_cfg_a_START (0)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_CFG_A_onsys_avs_cfg_a_END (15)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_CFG_A_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_CFG_A_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_monitor_time_a : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGL_ONSYS_AVS_TIME_CFG_AB_UNION;
#endif
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_TIME_CFG_AB_apb_monitor_time_a_START (0)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_TIME_CFG_AB_apb_monitor_time_a_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vs_th1_a : 16;
        unsigned int apb_vs_th2_a : 16;
    } reg;
} SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_0_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_0_A_apb_vs_th1_a_START (0)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_0_A_apb_vs_th1_a_END (15)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_0_A_apb_vs_th2_a_START (16)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_0_A_apb_vs_th2_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vs_th3_a : 16;
        unsigned int apb_vol_sub_min_a : 8;
        unsigned int apb_vol_add_max_a : 8;
    } reg;
} SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_apb_vs_th3_a_START (0)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_apb_vs_th3_a_END (15)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_apb_vol_sub_min_a_START (16)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_apb_vol_sub_min_a_END (23)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_apb_vol_add_max_a_START (24)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VS_TH_1_A_apb_vol_add_max_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vol_cfg1_a : 8;
        unsigned int apb_vol_cfg2_a : 8;
        unsigned int apb_vol_cfg3_a : 8;
        unsigned int apb_vol_cfg4_a : 8;
    } reg;
} SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg1_a_START (0)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg1_a_END (7)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg2_a_START (8)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg2_a_END (15)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg3_a_START (16)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg3_a_END (23)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg4_a_START (24)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_CFG_A_apb_vol_cfg4_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_vol_idx_a : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_IDX_UNION;
#endif
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_IDX_apb_vol_idx_a_START (0)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_VOL_IDX_apb_vol_idx_a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_cur_stat_a : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int apb_vol_sub_flag_a : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int apb_cnt_us : 8;
        unsigned int reserved_6 : 12;
    } reg;
} SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_UNION;
#endif
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_apb_cur_stat_a_START (0)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_apb_cur_stat_a_END (1)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_apb_vol_sub_flag_a_START (8)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_apb_vol_sub_flag_a_END (8)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_apb_cnt_us_START (12)
#define SOC_CORE_CPU_CRGL_ONSYS_AVS_APB_READ_apb_cnt_us_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_onsys_enable_a : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CORE_CPU_CRGL_APB_ONSYS_ENABLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_APB_ONSYS_ENABLE_apb_onsys_enable_a_START (0)
#define SOC_CORE_CPU_CRGL_APB_ONSYS_ENABLE_apb_onsys_enable_a_END (0)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_coef_cfg0_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_coef_cfg0_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_coef_cfg1_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_coef_cfg1_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_coef_cfg2_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG0_A_coef_cfg2_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_coef_cfg3_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_coef_cfg3_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_coef_cfg4_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_coef_cfg4_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_coef_cfg5_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG1_A_coef_cfg5_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_coef_cfg6_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_coef_cfg6_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_coef_cfg7_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_coef_cfg7_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_coef_cfg8_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG2_A_coef_cfg8_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_coef_cfg9_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_coef_cfg9_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_coef_cfg10_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_coef_cfg10_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_coef_cfg11_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG3_A_coef_cfg11_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_coef_cfg12_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_coef_cfg12_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_coef_cfg13_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_coef_cfg13_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_coef_cfg14_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG4_A_coef_cfg14_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_coef_cfg15_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_coef_cfg15_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_coef_cfg16_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_coef_cfg16_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_coef_cfg17_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG5_A_coef_cfg17_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_coef_cfg18_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_coef_cfg18_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_coef_cfg19_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_coef_cfg19_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_coef_cfg20_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG6_A_coef_cfg20_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_coef_cfg21_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_coef_cfg21_END (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_coef_cfg22_START (10)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_coef_cfg22_END (19)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_coef_cfg23_START (20)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG7_A_coef_cfg23_END (29)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w0_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w0_END (7)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w1_START (8)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w1_END (15)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w2_START (16)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w2_END (23)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w3_START (24)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG8_A_coef_w3_END (31)
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
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG9_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG9_A_coef_w4_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG9_A_coef_w4_END (7)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG9_A_coef_m_START (8)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG9_A_coef_m_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int accu_fd_thr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG10_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG10_A_accu_fd_thr_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG10_A_accu_fd_thr_END (24)
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
        unsigned int fdcs_onsys_cfg11_a : 9;
    } reg;
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_max_thr_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_max_thr_END (8)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_min_thr_START (9)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_min_thr_END (17)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_add_START (18)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_add_END (21)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_add_bypass_START (22)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_vol_add_bypass_END (22)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_fdcs_onsys_cfg11_a_START (23)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG11_A_fdcs_onsys_cfg11_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_cfg12_a : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG12_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG12_A_fdcs_onsys_cfg12_a_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG12_A_fdcs_onsys_cfg12_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_cfg13_a : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG13_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG13_A_fdcs_onsys_cfg13_a_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_CFG13_A_fdcs_onsys_cfg13_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdcs_onsys_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FDCS_ONSYS_STAT_A_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_STAT_A_fdcs_onsys_stat0_START (0)
#define SOC_CORE_CPU_CRGL_FDCS_ONSYS_STAT_A_fdcs_onsys_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_little_clkrst_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORE_CPU_CRGL_CLKRST_BYPASS_UNION;
#endif
#define SOC_CORE_CPU_CRGL_CLKRST_BYPASS_fcg_little_clkrst_bypass_START (0)
#define SOC_CORE_CPU_CRGL_CLKRST_BYPASS_fcg_little_clkrst_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_drop_en_little : 1;
        unsigned int pim_ost_en_little : 1;
        unsigned int pim_peaklow_en_little : 1;
        unsigned int pim_debug_little : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGL_PIM_CTRL0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_drop_en_little_START (0)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_drop_en_little_END (0)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_ost_en_little_START (1)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_ost_en_little_END (1)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_peaklow_en_little_START (2)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_peaklow_en_little_END (2)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_debug_little_START (3)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_pim_debug_little_END (3)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_PIM_CTRL0_bitmasken_END (31)
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
} SOC_CORE_CPU_CRGL_PIM_CFG0_LITTLE_UNION;
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
} SOC_CORE_CPU_CRGL_PIM_CFG1_LITTLE_UNION;
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
} SOC_CORE_CPU_CRGL_PIM_CFG2_LITTLE_UNION;
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
} SOC_CORE_CPU_CRGL_PIM_CFG3_LITTLE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_peaklow_code_little : 16;
        unsigned int pim_peaklow_ready_little : 1;
        unsigned int pim_flag_ready_little : 1;
        unsigned int pim_flag_l_little : 1;
        unsigned int pim_flag_h_little : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_PIM_STAT0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_peaklow_code_little_START (0)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_peaklow_code_little_END (15)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_peaklow_ready_little_START (16)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_peaklow_ready_little_END (16)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_flag_ready_little_START (17)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_flag_ready_little_END (17)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_flag_l_little_START (18)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_flag_l_little_END (18)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_flag_h_little_START (19)
#define SOC_CORE_CPU_CRGL_PIM_STAT0_pim_flag_h_little_END (19)
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
} SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_cnt_timer_en_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_cnt_timer_en_END (0)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_accu_fd_en_START (1)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_accu_fd_en_END (1)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_peaklow_en_START (2)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_peaklow_en_END (2)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_clear_all_en_START (3)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_clear_all_en_END (3)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_cnt_timer_hd_en_START (4)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_cnt_timer_hd_en_END (4)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_hw_fsm_mode_START (5)
#define SOC_CORE_CPU_CRGL_MON_CFG0_LITTLE_hw_fsm_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int read_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG1_LITTLE_read_lock_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG1_LITTLE_read_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin_peaklow_en : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG2_LITTLE_bin_peaklow_en_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG2_LITTLE_bin_peaklow_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth0_peaklow : 16;
        unsigned int vth1_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG3_LITTLE_vth0_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG3_LITTLE_vth0_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG3_LITTLE_vth1_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG3_LITTLE_vth1_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth2_peaklow : 16;
        unsigned int vth3_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG4_LITTLE_vth2_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG4_LITTLE_vth2_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG4_LITTLE_vth3_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG4_LITTLE_vth3_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth4_peaklow : 16;
        unsigned int vth5_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG5_LITTLE_vth4_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG5_LITTLE_vth4_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG5_LITTLE_vth5_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG5_LITTLE_vth5_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth6_peaklow : 16;
        unsigned int vth7_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG6_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG6_LITTLE_vth6_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG6_LITTLE_vth6_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG6_LITTLE_vth7_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG6_LITTLE_vth7_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth8_peaklow : 16;
        unsigned int vth9_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG7_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG7_LITTLE_vth8_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG7_LITTLE_vth8_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG7_LITTLE_vth9_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG7_LITTLE_vth9_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth10_peaklow : 16;
        unsigned int vth11_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG8_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG8_LITTLE_vth10_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG8_LITTLE_vth10_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG8_LITTLE_vth11_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG8_LITTLE_vth11_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth12_peaklow : 16;
        unsigned int vth13_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG9_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG9_LITTLE_vth12_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG9_LITTLE_vth12_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG9_LITTLE_vth13_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG9_LITTLE_vth13_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth14_peaklow : 16;
        unsigned int vth15_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG10_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG10_LITTLE_vth14_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG10_LITTLE_vth14_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG10_LITTLE_vth15_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG10_LITTLE_vth15_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth16_peaklow : 16;
        unsigned int vth17_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG11_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG11_LITTLE_vth16_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG11_LITTLE_vth16_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG11_LITTLE_vth17_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG11_LITTLE_vth17_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth18_peaklow : 16;
        unsigned int vth19_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG12_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG12_LITTLE_vth18_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG12_LITTLE_vth18_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG12_LITTLE_vth19_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG12_LITTLE_vth19_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth20_peaklow : 16;
        unsigned int vth21_peaklow : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG13_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG13_LITTLE_vth20_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG13_LITTLE_vth20_peaklow_END (15)
#define SOC_CORE_CPU_CRGL_MON_CFG13_LITTLE_vth21_peaklow_START (16)
#define SOC_CORE_CPU_CRGL_MON_CFG13_LITTLE_vth21_peaklow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vth22_peaklow : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG14_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG14_LITTLE_vth22_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG14_LITTLE_vth22_peaklow_END (15)
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
} SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_cnt_timer_hd_th_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_cnt_timer_hd_th_END (21)
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_read_lock_mode_START (30)
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_read_lock_mode_END (30)
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_sel_peaklow_vth_START (31)
#define SOC_CORE_CPU_CRGL_MON_CFG15_LITTLE_sel_peaklow_vth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pim_peaklow_vth : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_CPU_CRGL_MON_CFG16_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_CFG16_LITTLE_pim_peaklow_vth_START (0)
#define SOC_CORE_CPU_CRGL_MON_CFG16_LITTLE_pim_peaklow_vth_END (15)
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
} SOC_CORE_CPU_CRGL_MON_STAT0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT0_LITTLE_cnt_timer_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT0_LITTLE_cnt_timer_END (21)
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
} SOC_CORE_CPU_CRGL_MON_STAT1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT1_LITTLE_accu_fd_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT1_LITTLE_accu_fd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin0_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT2_LITTLE_bin0_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT2_LITTLE_bin0_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin1_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT3_LITTLE_bin1_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT3_LITTLE_bin1_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin2_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT4_LITTLE_bin2_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT4_LITTLE_bin2_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin3_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT5_LITTLE_bin3_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT5_LITTLE_bin3_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin4_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT6_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT6_LITTLE_bin4_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT6_LITTLE_bin4_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin5_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT7_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT7_LITTLE_bin5_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT7_LITTLE_bin5_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin6_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT8_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT8_LITTLE_bin6_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT8_LITTLE_bin6_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin7_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT9_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT9_LITTLE_bin7_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT9_LITTLE_bin7_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin8_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT10_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT10_LITTLE_bin8_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT10_LITTLE_bin8_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin9_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT11_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT11_LITTLE_bin9_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT11_LITTLE_bin9_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin10_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT12_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT12_LITTLE_bin10_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT12_LITTLE_bin10_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin11_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT13_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT13_LITTLE_bin11_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT13_LITTLE_bin11_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin12_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT14_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT14_LITTLE_bin12_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT14_LITTLE_bin12_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin13_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT15_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT15_LITTLE_bin13_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT15_LITTLE_bin13_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin14_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT16_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT16_LITTLE_bin14_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT16_LITTLE_bin14_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin15_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT17_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT17_LITTLE_bin15_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT17_LITTLE_bin15_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin16_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT18_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT18_LITTLE_bin16_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT18_LITTLE_bin16_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin17_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT19_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT19_LITTLE_bin17_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT19_LITTLE_bin17_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin18_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT20_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT20_LITTLE_bin18_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT20_LITTLE_bin18_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin19_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT21_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT21_LITTLE_bin19_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT21_LITTLE_bin19_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin20_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT22_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT22_LITTLE_bin20_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT22_LITTLE_bin20_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin21_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT23_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT23_LITTLE_bin21_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT23_LITTLE_bin21_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin22_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT24_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT24_LITTLE_bin22_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT24_LITTLE_bin22_peaklow_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin23_peaklow : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_MON_STAT25_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_MON_STAT25_LITTLE_bin23_peaklow_START (0)
#define SOC_CORE_CPU_CRGL_MON_STAT25_LITTLE_bin23_peaklow_END (19)
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
} SOC_CORE_CPU_CRGL_CLKDIV2_UNION;
#endif
#define SOC_CORE_CPU_CRGL_CLKDIV2_sc_gt_clk_fcg_ref_START (0)
#define SOC_CORE_CPU_CRGL_CLKDIV2_sc_gt_clk_fcg_ref_END (0)
#define SOC_CORE_CPU_CRGL_CLKDIV2_sc_gt_clk_fcg_cnt_START (1)
#define SOC_CORE_CPU_CRGL_CLKDIV2_sc_gt_clk_fcg_cnt_END (1)
#define SOC_CORE_CPU_CRGL_CLKDIV2_div_clk_fcg_cnt_START (2)
#define SOC_CORE_CPU_CRGL_CLKDIV2_div_clk_fcg_cnt_END (7)
#define SOC_CORE_CPU_CRGL_CLKDIV2_div_clk_fcg_ref_START (8)
#define SOC_CORE_CPU_CRGL_CLKDIV2_div_clk_fcg_ref_END (13)
#define SOC_CORE_CPU_CRGL_CLKDIV2_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_mode_0 : 4;
        unsigned int bhs_trim_0 : 8;
        unsigned int bhs_vset_0 : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CTRL_0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_bhs_mode_0_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_bhs_mode_0_END (3)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_bhs_trim_0_START (4)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_bhs_trim_0_END (11)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_bhs_vset_0_START (12)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_0_bhs_vset_0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_mode_1 : 4;
        unsigned int bhs_trim_1 : 8;
        unsigned int bhs_vset_1 : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CTRL_1_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_bhs_mode_1_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_bhs_mode_1_END (3)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_bhs_trim_1_START (4)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_bhs_trim_1_END (11)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_bhs_vset_1_START (12)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_1_bhs_vset_1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_mode_2 : 4;
        unsigned int bhs_trim_2 : 8;
        unsigned int bhs_vset_2 : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CTRL_2_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_bhs_mode_2_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_bhs_mode_2_END (3)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_bhs_trim_2_START (4)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_bhs_trim_2_END (11)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_bhs_vset_2_START (12)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_2_bhs_vset_2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_mode_3 : 4;
        unsigned int bhs_trim_3 : 8;
        unsigned int bhs_vset_3 : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CTRL_3_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_bhs_mode_3_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_bhs_mode_3_END (3)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_bhs_trim_3_START (4)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_bhs_trim_3_END (11)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_bhs_vset_3_START (12)
#define SOC_CORE_CPU_CRGL_BHS_CTRL_3_bhs_vset_3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_cfg : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CFG_0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CFG_0_bhs_cfg_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CFG_0_bhs_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_cfg : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CFG_1_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CFG_1_bhs_cfg_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CFG_1_bhs_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_cfg : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CFG_2_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CFG_2_bhs_cfg_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CFG_2_bhs_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_cfg : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CFG_3_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CFG_3_bhs_cfg_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CFG_3_bhs_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_state0 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_STAT_0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_STAT_0_bhs_state0_START (0)
#define SOC_CORE_CPU_CRGL_BHS_STAT_0_bhs_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_state1 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_STAT_1_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_STAT_1_bhs_state1_START (0)
#define SOC_CORE_CPU_CRGL_BHS_STAT_1_bhs_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_state2 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_STAT_2_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_STAT_2_bhs_state2_START (0)
#define SOC_CORE_CPU_CRGL_BHS_STAT_2_bhs_state2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_state3 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_STAT_3_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_STAT_3_bhs_state3_START (0)
#define SOC_CORE_CPU_CRGL_BHS_STAT_3_bhs_state3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_out_core0 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_OUT_0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_OUT_0_bhs_out_core0_START (0)
#define SOC_CORE_CPU_CRGL_BHS_OUT_0_bhs_out_core0_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_out_core1 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_OUT_1_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_OUT_1_bhs_out_core1_START (0)
#define SOC_CORE_CPU_CRGL_BHS_OUT_1_bhs_out_core1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_out_core2 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_OUT_2_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_OUT_2_bhs_out_core2_START (0)
#define SOC_CORE_CPU_CRGL_BHS_OUT_2_bhs_out_core2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs_out_core3 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_OUT_3_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_OUT_3_bhs_out_core3_START (0)
#define SOC_CORE_CPU_CRGL_BHS_OUT_3_bhs_out_core3_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs0_bypass_cfg : 10;
        unsigned int bhs1_bypass_cfg : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CFG4_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CFG4_bhs0_bypass_cfg_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CFG4_bhs0_bypass_cfg_END (9)
#define SOC_CORE_CPU_CRGL_BHS_CFG4_bhs1_bypass_cfg_START (10)
#define SOC_CORE_CPU_CRGL_BHS_CFG4_bhs1_bypass_cfg_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bhs2_bypass_cfg : 10;
        unsigned int bhs3_bypass_cfg : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_CORE_CPU_CRGL_BHS_CFG5_UNION;
#endif
#define SOC_CORE_CPU_CRGL_BHS_CFG5_bhs2_bypass_cfg_START (0)
#define SOC_CORE_CPU_CRGL_BHS_CFG5_bhs2_bypass_cfg_END (9)
#define SOC_CORE_CPU_CRGL_BHS_CFG5_bhs3_bypass_cfg_START (10)
#define SOC_CORE_CPU_CRGL_BHS_CFG5_bhs3_bypass_cfg_END (19)
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
} SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_fcg_freq_en_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_fcg_freq_en_END (0)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_fcg_freq_clr_START (1)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_fcg_freq_clr_END (1)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_fcg_freq_lock_START (2)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_fcg_freq_lock_END (2)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cnt_set : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CNT_CTRL1_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL1_fcg_cnt_set_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL1_fcg_cnt_set_END (15)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL1_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_FCG_CNT_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_freq_cnt_lock : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CNT_STATE0_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CNT_STATE0_fcg_freq_cnt_lock_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CNT_STATE0_fcg_freq_cnt_lock_END (31)
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
} SOC_CORE_CPU_CRGL_CLKDIV3_UNION;
#endif
#define SOC_CORE_CPU_CRGL_CLKDIV3_sc_fcg_cfg_gt_bypass_START (0)
#define SOC_CORE_CPU_CRGL_CLKDIV3_sc_fcg_cfg_gt_bypass_END (0)
#define SOC_CORE_CPU_CRGL_CLKDIV3_sc_fcg_cfg_gt_pre_bypass_START (1)
#define SOC_CORE_CPU_CRGL_CLKDIV3_sc_fcg_cfg_gt_pre_bypass_END (1)
#define SOC_CORE_CPU_CRGL_CLKDIV3_bitmasken_START (16)
#define SOC_CORE_CPU_CRGL_CLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_ANA_CFG0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG0_LITTLE_d2a_fcg_ana_cfg0_START (0)
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG0_LITTLE_d2a_fcg_ana_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_ANA_CFG1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG1_LITTLE_d2a_fcg_ana_cfg1_START (0)
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG1_LITTLE_d2a_fcg_ana_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_ANA_CFG2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG2_LITTLE_d2a_fcg_ana_cfg2_START (0)
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG2_LITTLE_d2a_fcg_ana_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d2a_fcg_ana_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_ANA_CFG3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG3_LITTLE_d2a_fcg_ana_cfg3_START (0)
#define SOC_CORE_CPU_CRGL_FCG_ANA_CFG3_LITTLE_d2a_fcg_ana_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg0 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG0_LITTLE_fcg_cfg0_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG0_LITTLE_fcg_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg1 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG1_LITTLE_fcg_cfg1_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG1_LITTLE_fcg_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg2 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG2_LITTLE_fcg_cfg2_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG2_LITTLE_fcg_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg3 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG3_LITTLE_fcg_cfg3_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG3_LITTLE_fcg_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg4 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG4_LITTLE_fcg_cfg4_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG4_LITTLE_fcg_cfg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg5 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG5_LITTLE_fcg_cfg5_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG5_LITTLE_fcg_cfg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg6 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG6_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG6_LITTLE_fcg_cfg6_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG6_LITTLE_fcg_cfg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg7 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG7_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG7_LITTLE_fcg_cfg7_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG7_LITTLE_fcg_cfg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg8 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG8_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG8_LITTLE_fcg_cfg8_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG8_LITTLE_fcg_cfg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg9 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG9_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG9_LITTLE_fcg_cfg9_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG9_LITTLE_fcg_cfg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg10 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG10_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG10_LITTLE_fcg_cfg10_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG10_LITTLE_fcg_cfg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg11 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG11_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG11_LITTLE_fcg_cfg11_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG11_LITTLE_fcg_cfg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg12 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG12_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG12_LITTLE_fcg_cfg12_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG12_LITTLE_fcg_cfg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg13 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG13_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG13_LITTLE_fcg_cfg13_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG13_LITTLE_fcg_cfg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg14 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG14_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG14_LITTLE_fcg_cfg14_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG14_LITTLE_fcg_cfg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg15 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG15_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG15_LITTLE_fcg_cfg15_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG15_LITTLE_fcg_cfg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg16 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG16_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG16_LITTLE_fcg_cfg16_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG16_LITTLE_fcg_cfg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg17 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG17_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG17_LITTLE_fcg_cfg17_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG17_LITTLE_fcg_cfg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg18 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG18_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG18_LITTLE_fcg_cfg18_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG18_LITTLE_fcg_cfg18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg19 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG19_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG19_LITTLE_fcg_cfg19_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG19_LITTLE_fcg_cfg19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg20 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG20_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG20_LITTLE_fcg_cfg20_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG20_LITTLE_fcg_cfg20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg21 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG21_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG21_LITTLE_fcg_cfg21_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG21_LITTLE_fcg_cfg21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg22 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG22_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG22_LITTLE_fcg_cfg22_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG22_LITTLE_fcg_cfg22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg23 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG23_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG23_LITTLE_fcg_cfg23_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG23_LITTLE_fcg_cfg23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg24 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG24_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG24_LITTLE_fcg_cfg24_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG24_LITTLE_fcg_cfg24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg25 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG25_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG25_LITTLE_fcg_cfg25_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG25_LITTLE_fcg_cfg25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg26 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG26_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG26_LITTLE_fcg_cfg26_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG26_LITTLE_fcg_cfg26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_cfg27 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_CFG27_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_CFG27_LITTLE_fcg_cfg27_START (0)
#define SOC_CORE_CPU_CRGL_FCG_CFG27_LITTLE_fcg_cfg27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat0 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_STAT0_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_STAT0_LITTLE_fcg_stat0_START (0)
#define SOC_CORE_CPU_CRGL_FCG_STAT0_LITTLE_fcg_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat1 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_STAT1_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_STAT1_LITTLE_fcg_stat1_START (0)
#define SOC_CORE_CPU_CRGL_FCG_STAT1_LITTLE_fcg_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat2 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_STAT2_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_STAT2_LITTLE_fcg_stat2_START (0)
#define SOC_CORE_CPU_CRGL_FCG_STAT2_LITTLE_fcg_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat3 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_STAT3_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_STAT3_LITTLE_fcg_stat3_START (0)
#define SOC_CORE_CPU_CRGL_FCG_STAT3_LITTLE_fcg_stat3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat4 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_STAT4_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_STAT4_LITTLE_fcg_stat4_START (0)
#define SOC_CORE_CPU_CRGL_FCG_STAT4_LITTLE_fcg_stat4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcg_stat5 : 32;
    } reg;
} SOC_CORE_CPU_CRGL_FCG_STAT5_LITTLE_UNION;
#endif
#define SOC_CORE_CPU_CRGL_FCG_STAT5_LITTLE_fcg_stat5_START (0)
#define SOC_CORE_CPU_CRGL_FCG_STAT5_LITTLE_fcg_stat5_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
