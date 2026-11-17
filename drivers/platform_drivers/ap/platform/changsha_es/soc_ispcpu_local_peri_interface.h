#ifndef __SOC_ISPCPU_LOCAL_PERI_INTERFACE_H__
#define __SOC_ISPCPU_LOCAL_PERI_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_ADDR(base) (base)
#define SOC_ISPCPU_LOCAL_PERI_CTRL1_ADDR(base) ((base) + 0x004UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL2_ADDR(base) ((base) + 0x008UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL3_ADDR(base) ((base) + 0x00CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_ADDR(base) ((base) + 0x010UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_ADDR(base) ((base) + 0x014UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_ADDR(base) ((base) + 0x018UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ADDR(base) ((base) + 0x01CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_ADDR(base) ((base) + 0x020UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL9_ADDR(base) ((base) + 0x024UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL10_ADDR(base) ((base) + 0x028UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_ADDR(base) ((base) + 0x02CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_ADDR(base) ((base) + 0x030UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL13_ADDR(base) ((base) + 0x034UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL14_ADDR(base) ((base) + 0x038UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + 0x03CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + 0x040UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + 0x044UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + 0x048UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + 0x04CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + 0x050UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + 0x054UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + 0x058UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL23_ADDR(base) ((base) + 0x05CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL24_ADDR(base) ((base) + 0x060UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL25_ADDR(base) ((base) + 0x064UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL26_ADDR(base) ((base) + 0x068UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_ADDR(base) ((base) + 0x06CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_ADDR(base) ((base) + 0x070UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_ADDR(base) ((base) + 0x074UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_ADDR(base) ((base) + 0x078UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_ADDR(base) ((base) + 0x07CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_ADDR(base) ((base) + 0x080UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_ADDR(base) ((base) + 0x084UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_ADDR(base) ((base) + 0x088UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_ADDR(base) ((base) + 0x08CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_ADDR(base) ((base) + 0x090UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_ADDR(base) ((base) + 0x094UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_ADDR(base) ((base) + 0x098UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_ADDR(base) ((base) + 0x09CUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_ADDR(base) ((base) + 0x0A0UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_ADDR(base) ((base) + 0x0A4UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_ADDR(base) ((base) + 0x0A8UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_ADDR(base) ((base) + 0x0ACUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_ADDR(base) ((base) + 0x0B0UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_ADDR(base) ((base) + 0x0B4UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_ADDR(base) ((base) + 0x0B8UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL47_ADDR(base) ((base) + 0x0BCUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL48_ADDR(base) ((base) + 0x0C0UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL49_ADDR(base) ((base) + 0x0C4UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL50_ADDR(base) ((base) + 0x0C8UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL51_ADDR(base) ((base) + 0x0CCUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_ADDR(base) ((base) + 0x0D0UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_ADDR(base) ((base) + 0x0D4UL)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_SET_ADDR(base) ((base) + 0x0D8UL)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_CLR_ADDR(base) ((base) + 0x0DCUL)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_STAT_ADDR(base) ((base) + 0x0E0UL)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_SET_ADDR(base) ((base) + 0x0E4UL)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_CLR_ADDR(base) ((base) + 0x0E8UL)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_STAT_ADDR(base) ((base) + 0x0ECUL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL60_ADDR(base) ((base) + 0x0F0UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL61_ADDR(base) ((base) + 0x0F4UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL62_ADDR(base) ((base) + 0x0F8UL)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_ADDR(base) ((base) + 0x0FCUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_ADDR(base) ((base) + 0x100UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_HIGH_ADDR(base) ((base) + 0x104UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_ADDR(base) ((base) + 0x108UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_HIGH_ADDR(base) ((base) + 0x10CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_ADDR(base) ((base) + 0x110UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_HIGH_ADDR(base) ((base) + 0x114UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_ADDR(base) ((base) + 0x118UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_HIGH_ADDR(base) ((base) + 0x11CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_ADDR(base) ((base) + 0x120UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_HIGH_ADDR(base) ((base) + 0x124UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_ADDR(base) ((base) + 0x128UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_HIGH_ADDR(base) ((base) + 0x12CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_ADDR(base) ((base) + 0x130UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_HIGH_ADDR(base) ((base) + 0x134UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_ADDR(base) ((base) + 0x138UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_HIGH_ADDR(base) ((base) + 0x13CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_ADDR(base) ((base) + 0x140UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_HIGH_ADDR(base) ((base) + 0x144UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_ADDR(base) ((base) + 0x148UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_HIGH_ADDR(base) ((base) + 0x14CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_ADDR(base) ((base) + 0x150UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_HIGH_ADDR(base) ((base) + 0x154UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_ADDR(base) ((base) + 0x158UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_HIGH_ADDR(base) ((base) + 0x15CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_LOCK_ADDR(base) ((base) + 0x1F0UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL400_ADDR(base) ((base) + 0x400UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL404_ADDR(base) ((base) + 0x404UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL408_ADDR(base) ((base) + 0x408UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL40C_ADDR(base) ((base) + 0x40CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL410_ADDR(base) ((base) + 0x410UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_ADDR(base) ((base) + 0x414UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_ADDR(base) ((base) + 0x418UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_ADDR(base) ((base) + 0x41CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_ADDR(base) ((base) + 0x420UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_ADDR(base) ((base) + 0x424UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL428_ADDR(base) ((base) + 0x428UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL42C_ADDR(base) ((base) + 0x42CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL430_ADDR(base) ((base) + 0x430UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL434_ADDR(base) ((base) + 0x434UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL438_ADDR(base) ((base) + 0x438UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL43C_ADDR(base) ((base) + 0x43CUL)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_ADDR(base) ((base) + 0x200UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_ADDR(base) ((base) + 0x204UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_ADDR(base) ((base) + 0x208UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_ADDR(base) ((base) + 0x20CUL)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_ADDR(base) ((base) + 0x210UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_ADDR(base) ((base) + 0x214UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_ADDR(base) ((base) + 0x218UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_ADDR(base) ((base) + 0x21CUL)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_ADDR(base) ((base) + 0x220UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT9_ADDR(base) ((base) + 0x224UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_ADDR(base) ((base) + 0x228UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_ADDR(base) ((base) + 0x22CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + 0x230UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + 0x234UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + 0x238UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + 0x23CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + 0x240UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + 0x244UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + 0x248UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + 0x24CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x250UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x254UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x258UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x25CUL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_0_ADDR(base) ((base) + 0x260UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_ADDR(base) ((base) + 0x264UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_ADDR(base) ((base) + 0x268UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_ADDR(base) ((base) + 0x26CUL)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_ADDR(base) ((base) + 0x270UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_ADDR(base) ((base) + 0x274UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT30_ADDR(base) ((base) + 0x278UL)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_1_ADDR(base) ((base) + 0x27CUL)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_ADDR(base) ((base) + 0x280UL)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_DEBUG_INFO_ADDR(base) ((base) + 0x284UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT34_ADDR(base) ((base) + 0x288UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT35_ADDR(base) ((base) + 0x28CUL)
#define SOC_ISPCPU_LOCAL_PERI_STAT36_ADDR(base) ((base) + 0x290UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT37_ADDR(base) ((base) + 0x294UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT38_ADDR(base) ((base) + 0x298UL)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_ADDR(base) ((base) + 0x29CUL)
#else
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_ADDR(base) (base)
#define SOC_ISPCPU_LOCAL_PERI_CTRL1_ADDR(base) ((base) + 0x004)
#define SOC_ISPCPU_LOCAL_PERI_CTRL2_ADDR(base) ((base) + 0x008)
#define SOC_ISPCPU_LOCAL_PERI_CTRL3_ADDR(base) ((base) + 0x00C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_ADDR(base) ((base) + 0x010)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_ADDR(base) ((base) + 0x014)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_ADDR(base) ((base) + 0x018)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ADDR(base) ((base) + 0x01C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_ADDR(base) ((base) + 0x020)
#define SOC_ISPCPU_LOCAL_PERI_CTRL9_ADDR(base) ((base) + 0x024)
#define SOC_ISPCPU_LOCAL_PERI_CTRL10_ADDR(base) ((base) + 0x028)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_ADDR(base) ((base) + 0x02C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_ADDR(base) ((base) + 0x030)
#define SOC_ISPCPU_LOCAL_PERI_CTRL13_ADDR(base) ((base) + 0x034)
#define SOC_ISPCPU_LOCAL_PERI_CTRL14_ADDR(base) ((base) + 0x038)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + 0x03C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + 0x040)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + 0x044)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + 0x048)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + 0x04C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + 0x050)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + 0x054)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + 0x058)
#define SOC_ISPCPU_LOCAL_PERI_CTRL23_ADDR(base) ((base) + 0x05C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL24_ADDR(base) ((base) + 0x060)
#define SOC_ISPCPU_LOCAL_PERI_CTRL25_ADDR(base) ((base) + 0x064)
#define SOC_ISPCPU_LOCAL_PERI_CTRL26_ADDR(base) ((base) + 0x068)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_ADDR(base) ((base) + 0x06C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_ADDR(base) ((base) + 0x070)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_ADDR(base) ((base) + 0x074)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_ADDR(base) ((base) + 0x078)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_ADDR(base) ((base) + 0x07C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_ADDR(base) ((base) + 0x080)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_ADDR(base) ((base) + 0x084)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_ADDR(base) ((base) + 0x088)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_ADDR(base) ((base) + 0x08C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_ADDR(base) ((base) + 0x090)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_ADDR(base) ((base) + 0x094)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_ADDR(base) ((base) + 0x098)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_ADDR(base) ((base) + 0x09C)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_ADDR(base) ((base) + 0x0A0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_ADDR(base) ((base) + 0x0A4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_ADDR(base) ((base) + 0x0A8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_ADDR(base) ((base) + 0x0AC)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_ADDR(base) ((base) + 0x0B0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_ADDR(base) ((base) + 0x0B4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_ADDR(base) ((base) + 0x0B8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL47_ADDR(base) ((base) + 0x0BC)
#define SOC_ISPCPU_LOCAL_PERI_CTRL48_ADDR(base) ((base) + 0x0C0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL49_ADDR(base) ((base) + 0x0C4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL50_ADDR(base) ((base) + 0x0C8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL51_ADDR(base) ((base) + 0x0CC)
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_ADDR(base) ((base) + 0x0D0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_ADDR(base) ((base) + 0x0D4)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_SET_ADDR(base) ((base) + 0x0D8)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_CLR_ADDR(base) ((base) + 0x0DC)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_STAT_ADDR(base) ((base) + 0x0E0)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_SET_ADDR(base) ((base) + 0x0E4)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_CLR_ADDR(base) ((base) + 0x0E8)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_STAT_ADDR(base) ((base) + 0x0EC)
#define SOC_ISPCPU_LOCAL_PERI_CTRL60_ADDR(base) ((base) + 0x0F0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL61_ADDR(base) ((base) + 0x0F4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL62_ADDR(base) ((base) + 0x0F8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_ADDR(base) ((base) + 0x0FC)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_ADDR(base) ((base) + 0x100)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_HIGH_ADDR(base) ((base) + 0x104)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_ADDR(base) ((base) + 0x108)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_HIGH_ADDR(base) ((base) + 0x10C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_ADDR(base) ((base) + 0x110)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_HIGH_ADDR(base) ((base) + 0x114)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_ADDR(base) ((base) + 0x118)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_HIGH_ADDR(base) ((base) + 0x11C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_ADDR(base) ((base) + 0x120)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_HIGH_ADDR(base) ((base) + 0x124)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_ADDR(base) ((base) + 0x128)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_HIGH_ADDR(base) ((base) + 0x12C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_ADDR(base) ((base) + 0x130)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_HIGH_ADDR(base) ((base) + 0x134)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_ADDR(base) ((base) + 0x138)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_HIGH_ADDR(base) ((base) + 0x13C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_ADDR(base) ((base) + 0x140)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_HIGH_ADDR(base) ((base) + 0x144)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_ADDR(base) ((base) + 0x148)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_HIGH_ADDR(base) ((base) + 0x14C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_ADDR(base) ((base) + 0x150)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_HIGH_ADDR(base) ((base) + 0x154)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_ADDR(base) ((base) + 0x158)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_HIGH_ADDR(base) ((base) + 0x15C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_LOCK_ADDR(base) ((base) + 0x1F0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL400_ADDR(base) ((base) + 0x400)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL404_ADDR(base) ((base) + 0x404)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL408_ADDR(base) ((base) + 0x408)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL40C_ADDR(base) ((base) + 0x40C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL410_ADDR(base) ((base) + 0x410)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_ADDR(base) ((base) + 0x414)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_ADDR(base) ((base) + 0x418)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_ADDR(base) ((base) + 0x41C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_ADDR(base) ((base) + 0x420)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_ADDR(base) ((base) + 0x424)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL428_ADDR(base) ((base) + 0x428)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL42C_ADDR(base) ((base) + 0x42C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL430_ADDR(base) ((base) + 0x430)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL434_ADDR(base) ((base) + 0x434)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL438_ADDR(base) ((base) + 0x438)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL43C_ADDR(base) ((base) + 0x43C)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_ADDR(base) ((base) + 0x200)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_ADDR(base) ((base) + 0x204)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_ADDR(base) ((base) + 0x208)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_ADDR(base) ((base) + 0x20C)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_ADDR(base) ((base) + 0x210)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_ADDR(base) ((base) + 0x214)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_ADDR(base) ((base) + 0x218)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_ADDR(base) ((base) + 0x21C)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_ADDR(base) ((base) + 0x220)
#define SOC_ISPCPU_LOCAL_PERI_STAT9_ADDR(base) ((base) + 0x224)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_ADDR(base) ((base) + 0x228)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_ADDR(base) ((base) + 0x22C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + 0x230)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + 0x234)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + 0x238)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + 0x23C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + 0x240)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + 0x244)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + 0x248)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + 0x24C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x250)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x254)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x258)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + 0x25C)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_0_ADDR(base) ((base) + 0x260)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_ADDR(base) ((base) + 0x264)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_ADDR(base) ((base) + 0x268)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_ADDR(base) ((base) + 0x26C)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_ADDR(base) ((base) + 0x270)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_ADDR(base) ((base) + 0x274)
#define SOC_ISPCPU_LOCAL_PERI_STAT30_ADDR(base) ((base) + 0x278)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_1_ADDR(base) ((base) + 0x27C)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_ADDR(base) ((base) + 0x280)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_DEBUG_INFO_ADDR(base) ((base) + 0x284)
#define SOC_ISPCPU_LOCAL_PERI_STAT34_ADDR(base) ((base) + 0x288)
#define SOC_ISPCPU_LOCAL_PERI_STAT35_ADDR(base) ((base) + 0x28C)
#define SOC_ISPCPU_LOCAL_PERI_STAT36_ADDR(base) ((base) + 0x290)
#define SOC_ISPCPU_LOCAL_PERI_STAT37_ADDR(base) ((base) + 0x294)
#define SOC_ISPCPU_LOCAL_PERI_STAT38_ADDR(base) ((base) + 0x298)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_ADDR(base) ((base) + 0x29C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 12;
        unsigned int iso_sd_bypass : 1;
        unsigned int iso_idle_bypass : 1;
        unsigned int bisr_sd_bypass : 1;
        unsigned int pdc_sd_bypass : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_iso_sd_bypass_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_iso_sd_bypass_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_iso_idle_bypass_START (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_iso_idle_bypass_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_bisr_sd_bypass_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_bisr_sd_bypass_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_pdc_sd_bypass_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL0_pdc_sd_bypass_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int astartmp : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL1_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL1_astartmp_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL1_astartmp_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aendmp : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL2_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL2_aendmp_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL2_aendmp_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_coreclk_little_soft : 1;
        unsigned int gt_clk_coreclk_middle_soft : 6;
        unsigned int gt_clk_coreclk_big_soft : 1;
        unsigned int gt_clk_coreclk_sl2_soft : 1;
        unsigned int reserved : 3;
        unsigned int sl2_core_clkgate_sel : 1;
        unsigned int little_core_clkgate_sel : 1;
        unsigned int middle_core_clkgate_sel : 1;
        unsigned int big_core_clkgate_sel : 1;
        unsigned int clken_masken_4 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL4_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_little_soft_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_little_soft_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_middle_soft_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_middle_soft_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_big_soft_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_big_soft_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_sl2_soft_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_gt_clk_coreclk_sl2_soft_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_sl2_core_clkgate_sel_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_sl2_core_clkgate_sel_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_little_core_clkgate_sel_START (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_little_core_clkgate_sel_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_middle_core_clkgate_sel_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_middle_core_clkgate_sel_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_big_core_clkgate_sel_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_big_core_clkgate_sel_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_clken_masken_4_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL4_clken_masken_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_cnt_en_dly : 6;
        unsigned int reserved_0 : 2;
        unsigned int freq_sel : 2;
        unsigned int tick_sel_bypass : 1;
        unsigned int retetion_tick_sel : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL5_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_sys_cnt_en_dly_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_sys_cnt_en_dly_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_freq_sel_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_freq_sel_END (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_tick_sel_bypass_START (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_tick_sel_bypass_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_retetion_tick_sel_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL5_retetion_tick_sel_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_chi_rs_gate_en : 1;
        unsigned int lit_l3sys_ckb_devorder_en : 1;
        unsigned int lit_sys_sha_ckb_cfg_en : 1;
        unsigned int lit_hisi_sve2_crypto_disable : 1;
        unsigned int lit_l3sys_ckb_force_clk_en_i : 1;
        unsigned int lit_core7_ckb_force_clk_en_i : 1;
        unsigned int lit_syscoack_from_qice_bypass : 1;
        unsigned int lit_syscoreq_to_qice : 1;
        unsigned int lit_l3sys_ckb_sce_stash_en : 1;
        unsigned int lit_l3sys_ckb_sce_we_en : 1;
        unsigned int lit_l3sys_ckb_sce_cmo_en : 1;
        unsigned int lit_namtso_djtag_clken : 1;
        unsigned int lit_core456_ckb_force_clk_en_i : 1;
        unsigned int lit_enable_active_for_bdq_clk : 1;
        unsigned int lit_chi_pwrctl_mux_sel : 1;
        unsigned int lit_chi_clkctl_mux_sel : 1;
        unsigned int masken_6 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL6_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_chi_rs_gate_en_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_chi_rs_gate_en_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_devorder_en_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_devorder_en_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_sys_sha_ckb_cfg_en_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_sys_sha_ckb_cfg_en_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_hisi_sve2_crypto_disable_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_hisi_sve2_crypto_disable_END (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_force_clk_en_i_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_force_clk_en_i_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_core7_ckb_force_clk_en_i_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_core7_ckb_force_clk_en_i_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_syscoack_from_qice_bypass_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_syscoack_from_qice_bypass_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_syscoreq_to_qice_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_syscoreq_to_qice_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_sce_stash_en_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_sce_stash_en_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_sce_we_en_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_sce_we_en_END (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_sce_cmo_en_START (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_l3sys_ckb_sce_cmo_en_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_namtso_djtag_clken_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_namtso_djtag_clken_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_core456_ckb_force_clk_en_i_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_core456_ckb_force_clk_en_i_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_enable_active_for_bdq_clk_START (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_enable_active_for_bdq_clk_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_chi_pwrctl_mux_sel_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_chi_pwrctl_mux_sel_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_chi_clkctl_mux_sel_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_lit_chi_clkctl_mux_sel_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_masken_6_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL6_masken_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ananke_core_mem_ctl_normal : 3;
        unsigned int reserved_0 : 1;
        unsigned int ananke_core_mem_ctl_sd : 3;
        unsigned int reserved_1 : 1;
        unsigned int ananke_core_mem_ctl_dslp : 3;
        unsigned int reserved_2 : 1;
        unsigned int ananke_core_mem_ctl_slp : 3;
        unsigned int reserved_3 : 1;
        unsigned int enyo_big_core_mem_ctl_normal : 3;
        unsigned int reserved_4 : 1;
        unsigned int enyo_big_core_mem_ctl_sd : 3;
        unsigned int reserved_5 : 1;
        unsigned int enyo_big_core_mem_ctl_dslp : 3;
        unsigned int reserved_6 : 1;
        unsigned int enyo_big_core_mem_ctl_slp : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL7_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_normal_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_normal_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_sd_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_sd_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_dslp_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_dslp_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_slp_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_slp_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_normal_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_normal_END (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_sd_START (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_sd_END (22)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_dslp_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_dslp_END (26)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_slp_START (28)
#define SOC_ISPCPU_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_slp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qactive_cfgcnt : 7;
        unsigned int gt_clk_bypass : 1;
        unsigned int reserved_0 : 3;
        unsigned int pwrqreqns_adb_m0 : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL8_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_qactive_cfgcnt_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_qactive_cfgcnt_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_gt_clk_bypass_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_gt_clk_bypass_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_pwrqreqns_adb_m0_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL8_pwrqreqns_adb_m0_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_pchannel_wait_cycle_sd : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL10_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_dslp_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_dslp_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_sd_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_sd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_p_channel_init_pstate : 8;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
        unsigned int cluster_preq_from_sys : 1;
        unsigned int cluster_pstate_from_sys : 8;
        unsigned int reserved_4 : 7;
        unsigned int fcm_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL11_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_fcm_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_fcm_p_channel_init_pstate_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_cluster_preq_from_sys_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_cluster_preq_from_sys_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_cluster_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_cluster_pstate_from_sys_END (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_fcm_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_CTRL11_fcm_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int paccept_pdeny_delay_sample_win : 16;
        unsigned int ckb_bypass_paccept_delay : 1;
        unsigned int ckb_bypass_txrx_pchannel : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL12_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_paccept_pdeny_delay_sample_win_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_paccept_pdeny_delay_sample_win_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_ckb_bypass_paccept_delay_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_ckb_bypass_paccept_delay_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_ckb_bypass_txrx_pchannel_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL12_ckb_bypass_txrx_pchannel_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_off_to_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL13_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL13_force_off_to_on_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL13_force_off_to_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_disable_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL14_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL14_force_disable_off_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL14_force_disable_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core0_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core0_deny_delay_threshold : 8;
        unsigned int core0_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core0_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core0_mem_ctrl_from_sys : 3;
        unsigned int core0_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_CFG_core0_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core1_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core1_deny_delay_threshold : 8;
        unsigned int core1_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core1_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core1_mem_ctrl_from_sys : 3;
        unsigned int core1_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_CFG_core1_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core2_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core2_deny_delay_threshold : 8;
        unsigned int core2_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core2_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core2_mem_ctrl_from_sys : 3;
        unsigned int core2_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_CFG_core2_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core3_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core3_deny_delay_threshold : 8;
        unsigned int core3_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core3_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core3_mem_ctrl_from_sys : 3;
        unsigned int core3_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_CFG_core3_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core4_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core4_deny_delay_threshold : 8;
        unsigned int core4_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core4_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core4_mem_ctrl_from_sys : 3;
        unsigned int core4_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_CFG_core4_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core5_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core5_deny_delay_threshold : 8;
        unsigned int core5_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core5_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core5_mem_ctrl_from_sys : 3;
        unsigned int core5_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_CFG_core5_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core6_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core6_deny_delay_threshold : 8;
        unsigned int core6_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core6_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core6_mem_ctrl_from_sys : 3;
        unsigned int core6_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_CFG_core6_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int core7_deny_delay_threshold : 8;
        unsigned int core7_pstate_from_sys : 7;
        unsigned int reserved_1 : 1;
        unsigned int core7_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core7_mem_ctrl_from_sys : 3;
        unsigned int core7_p_channel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_deny_delay_threshold_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_deny_delay_threshold_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_preq_from_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_preq_from_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_END (30)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_p_channel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_CFG_core7_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_core0_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core1_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL23_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL23_fcm_core0_pchannel_wait_cycle_dslp_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL23_fcm_core0_pchannel_wait_cycle_dslp_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL23_fcm_core1_pchannel_wait_cycle_dslp_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL23_fcm_core1_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_core2_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core3_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL24_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL24_fcm_core2_pchannel_wait_cycle_dslp_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL24_fcm_core2_pchannel_wait_cycle_dslp_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL24_fcm_core3_pchannel_wait_cycle_dslp_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL24_fcm_core3_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_core4_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core5_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL25_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL25_fcm_core4_pchannel_wait_cycle_dslp_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL25_fcm_core4_pchannel_wait_cycle_dslp_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL25_fcm_core5_pchannel_wait_cycle_dslp_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL25_fcm_core5_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_core6_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core7_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL26_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL26_fcm_core6_pchannel_wait_cycle_dslp_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL26_fcm_core6_pchannel_wait_cycle_dslp_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL26_fcm_core7_pchannel_wait_cycle_dslp_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL26_fcm_core7_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int little_hc_test : 3;
        unsigned int little_hc_tselr_tp : 2;
        unsigned int little_hc_tselw : 2;
        unsigned int little_hc_tra : 2;
        unsigned int little_hc_tselr_hchd : 3;
        unsigned int little_hd_test : 3;
        unsigned int little_hd_tselr_tp : 2;
        unsigned int little_hd_tselw : 2;
        unsigned int little_hd_tra : 2;
        unsigned int little_hd_tselr_hchd : 3;
        unsigned int little_hd_twac_twa : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL27_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_test_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_test_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tselr_tp_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tselr_tp_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tselw_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tselw_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tra_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tra_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tselr_hchd_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hc_tselr_hchd_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_test_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_test_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tselr_tp_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tselr_tp_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tselw_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tselw_END (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tra_START (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tra_END (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tselr_hchd_START (21)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_tselr_hchd_END (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_twac_twa_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL27_little_hd_twac_twa_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int little_tp_test : 3;
        unsigned int little_tp_tselr_tp : 2;
        unsigned int little_tp_tselw : 2;
        unsigned int little_tp_tra : 2;
        unsigned int little_tp_tselr_hchd : 3;
        unsigned int little_spus_test : 3;
        unsigned int little_spus_tselr_tp : 2;
        unsigned int little_spus_tselw : 2;
        unsigned int little_spus_tra : 2;
        unsigned int little_spus_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL28_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_test_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_test_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tselr_tp_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tselr_tp_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tselw_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tselw_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tra_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tra_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tselr_hchd_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_tp_tselr_hchd_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_test_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_test_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tselr_tp_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tselr_tp_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tselw_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tselw_END (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tra_START (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tra_END (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tselr_hchd_START (21)
#define SOC_ISPCPU_LOCAL_PERI_CTRL28_little_spus_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int middle_sps_test : 3;
        unsigned int middle_sps_tselr_tp : 2;
        unsigned int middle_sps_tselw : 2;
        unsigned int middle_sps_tra : 2;
        unsigned int middle_sps_tselr_spsspa : 3;
        unsigned int middle_tp_test : 3;
        unsigned int middle_tp_tselr_tp : 2;
        unsigned int middle_tp_tselw : 2;
        unsigned int middle_tp_tra : 2;
        unsigned int middle_tp_tselr_spsspa : 3;
        unsigned int middle_tp_tselr_lsu_data : 3;
        unsigned int reserved : 5;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL29_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_test_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_test_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tselr_tp_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tselr_tp_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tselw_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tselw_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tra_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tra_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tselr_spsspa_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_sps_tselr_spsspa_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_test_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_test_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselr_tp_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselr_tp_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselw_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselw_END (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tra_START (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tra_END (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselr_spsspa_START (21)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselr_spsspa_END (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselr_lsu_data_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL29_middle_tp_tselr_lsu_data_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int middle_spa_test : 3;
        unsigned int middle_spa_tselr_spa : 2;
        unsigned int middle_spa_tselw : 2;
        unsigned int middle_spa_tra : 2;
        unsigned int middle_spa_tselr_spsspa : 3;
        unsigned int middle_tsps_test : 3;
        unsigned int middle_tsps_tselr_spa : 2;
        unsigned int middle_tsps_tselw : 2;
        unsigned int middle_tsps_tra : 2;
        unsigned int middle_tsps_tselr_spsspa : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL30_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_test_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_test_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tselr_spa_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tselr_spa_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tselw_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tselw_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tra_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tra_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tselr_spsspa_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_spa_tselr_spsspa_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_test_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_test_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tselr_spa_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tselr_spa_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tselw_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tselw_END (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tra_START (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tra_END (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tselr_spsspa_START (21)
#define SOC_ISPCPU_LOCAL_PERI_CTRL30_middle_tsps_tselr_spsspa_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int big_sps_test : 3;
        unsigned int big_sps_tselr_tp : 2;
        unsigned int big_sps_tselw : 2;
        unsigned int big_sps_tra : 2;
        unsigned int big_sps_tselr_spsspa : 3;
        unsigned int big_tp_test : 3;
        unsigned int big_tp_tselr_tp : 2;
        unsigned int big_tp_tselw : 2;
        unsigned int big_tp_tra : 2;
        unsigned int big_tp_tselr_spsspa : 3;
        unsigned int big_tp_tselr_lsu_data : 3;
        unsigned int reserved : 5;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL31_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_test_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_test_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tselr_tp_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tselr_tp_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tselw_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tselw_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tra_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tra_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tselr_spsspa_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_sps_tselr_spsspa_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_test_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_test_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselr_tp_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselr_tp_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselw_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselw_END (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tra_START (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tra_END (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselr_spsspa_START (21)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselr_spsspa_END (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselr_lsu_data_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL31_big_tp_tselr_lsu_data_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int big_spa_test : 3;
        unsigned int big_spa_tselr_tp : 2;
        unsigned int big_spa_tselw : 2;
        unsigned int big_spa_tra : 2;
        unsigned int big_spa_tselr_spsspa : 3;
        unsigned int big_ttp_test : 3;
        unsigned int big_ttp_tselr_ttp : 2;
        unsigned int big_ttp_tselw : 2;
        unsigned int big_ttp_tra : 2;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL32_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_test_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_test_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tselr_tp_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tselr_tp_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tselw_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tselw_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tra_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tra_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tselr_spsspa_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_spa_tselr_spsspa_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_test_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_test_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_tselr_ttp_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_tselr_ttp_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_tselw_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_tselw_END (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_tra_START (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL32_big_ttp_tra_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l3_mem_spua_test : 3;
        unsigned int l3_mem_spua_tp_tselr : 2;
        unsigned int l3_mem_spua_tselw : 2;
        unsigned int l3_mem_spua_tra : 2;
        unsigned int l3_mem_spua_notp_tselr : 3;
        unsigned int l3_mem_lp_ctl : 3;
        unsigned int reserved : 1;
        unsigned int l3_mem_spua_twa : 2;
        unsigned int l3_mem_spua_spua_twac : 2;
        unsigned int l3_mem_sps_test : 3;
        unsigned int l3_mem_sps_tp_tselr : 2;
        unsigned int l3_mem_sps_tselw : 2;
        unsigned int l3_mem_sps_tra : 2;
        unsigned int l3_mem_sps_notp_tselr : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL33_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_test_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_test_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_tp_tselr_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_tp_tselr_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_tselw_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_tselw_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_tra_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_tra_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_notp_tselr_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_notp_tselr_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_lp_ctl_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_lp_ctl_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_twa_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_twa_END (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_spua_twac_START (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_spua_spua_twac_END (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_test_START (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_test_END (22)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_tp_tselr_START (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_tp_tselr_END (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_tselw_START (25)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_tselw_END (26)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_tra_START (27)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_tra_END (28)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_notp_tselr_START (29)
#define SOC_ISPCPU_LOCAL_PERI_CTRL33_l3_mem_sps_notp_tselr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_memory_ls : 1;
        unsigned int sp_memory_ds : 1;
        unsigned int sp_memory_sd : 1;
        unsigned int sp_mem_hc_tselr : 3;
        unsigned int sp_mem_hc_tselw : 2;
        unsigned int sp_mem_test : 3;
        unsigned int sp_mem_hd_tselr : 3;
        unsigned int sp_mem_hd_tselw : 2;
        unsigned int sp_mem_tra : 2;
        unsigned int reserved : 6;
        unsigned int l3_mem_rf_test : 3;
        unsigned int l3_mem_rf_tp_tselr : 2;
        unsigned int l3_mem_rf_tselw : 2;
        unsigned int l3_mem_rf_tra_0 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL34_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_memory_ls_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_memory_ls_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_memory_ds_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_memory_ds_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_memory_sd_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_memory_sd_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hc_tselr_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hc_tselr_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hc_tselw_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hc_tselw_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_test_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_test_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hd_tselr_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hd_tselr_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hd_tselw_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_hd_tselw_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_tra_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_sp_mem_tra_END (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_test_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_test_END (26)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_tp_tselr_START (27)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_tp_tselr_END (28)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_tselw_START (29)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_tselw_END (30)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_tra_0_START (31)
#define SOC_ISPCPU_LOCAL_PERI_CTRL34_l3_mem_rf_tra_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_mem_ctrl_ls : 1;
        unsigned int tp_mem_ctrl_ds : 1;
        unsigned int tp_mem_ctrl_sd : 1;
        unsigned int reserved_0 : 1;
        unsigned int tp_mem_ctrl_tselr : 2;
        unsigned int tp_mem_ctrl_tselw : 2;
        unsigned int tp_mem_ctrl_test : 3;
        unsigned int tp_mem_ctrl_tra : 2;
        unsigned int reserved_1 : 3;
        unsigned int l3_mem_rf_tra_1 : 1;
        unsigned int l3_mem_rf_notp_tselr : 3;
        unsigned int l3_mem_tp_test : 3;
        unsigned int l3_mem_tp_tp_tselr : 2;
        unsigned int l3_mem_tp_tselw : 2;
        unsigned int l3_mem_tp_tra : 2;
        unsigned int l3_mem_tp_notp_tselr : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL35_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_ls_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_ls_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_ds_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_ds_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_sd_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_sd_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselr_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselr_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselw_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselw_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_test_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_test_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_tra_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_tp_mem_ctrl_tra_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_rf_tra_1_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_rf_tra_1_END (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_rf_notp_tselr_START (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_rf_notp_tselr_END (19)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_test_START (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_test_END (22)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_tp_tselr_START (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_tp_tselr_END (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_tselw_START (25)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_tselw_END (26)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_tra_START (27)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_tra_END (28)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_notp_tselr_START (29)
#define SOC_ISPCPU_LOCAL_PERI_CTRL35_l3_mem_tp_notp_tselr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_pipe0_mem_ctrl : 3;
        unsigned int sys_pipe0_mem_ctrl_1_2 : 3;
        unsigned int sys_pipe0_mem_ctrl_sf : 3;
        unsigned int sys_pipe0_mem_ctrl_age : 3;
        unsigned int sys_pipe0_mem_ctrl_other : 3;
        unsigned int sys_pipe1_mem_ctrl : 3;
        unsigned int sys_pipe1_mem_ctrl_1_2 : 3;
        unsigned int sys_pipe1_mem_ctrl_sf : 3;
        unsigned int sys_pipe1_mem_ctrl_age : 3;
        unsigned int sys_pipe1_mem_ctrl_other : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL36_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_1_2_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_1_2_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_sf_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_sf_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_age_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_age_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_other_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe0_mem_ctrl_other_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_END (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_1_2_START (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_1_2_END (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_sf_START (21)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_sf_END (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_age_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_age_END (26)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_other_START (27)
#define SOC_ISPCPU_LOCAL_PERI_CTRL36_sys_pipe1_mem_ctrl_other_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_pipe2_mem_ctrl : 3;
        unsigned int sys_pipe2_mem_ctrl_1_2 : 3;
        unsigned int sys_pipe2_mem_ctrl_sf : 3;
        unsigned int sys_pipe2_mem_ctrl_age : 3;
        unsigned int sys_pipe2_mem_ctrl_other : 3;
        unsigned int sys_pipe3_mem_ctrl : 3;
        unsigned int sys_pipe3_mem_ctrl_1_2 : 3;
        unsigned int sys_pipe3_mem_ctrl_sf : 3;
        unsigned int sys_pipe3_mem_ctrl_age : 3;
        unsigned int sys_pipe3_mem_ctrl_other : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL37_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_1_2_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_1_2_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_sf_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_sf_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_age_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_age_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_other_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe2_mem_ctrl_other_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_END (17)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_1_2_START (18)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_1_2_END (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_sf_START (21)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_sf_END (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_age_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_age_END (26)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_other_START (27)
#define SOC_ISPCPU_LOCAL_PERI_CTRL37_sys_pipe3_mem_ctrl_other_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chk_all_sd_ds_chain : 1;
        unsigned int reserved_0 : 1;
        unsigned int sdo_check_enable : 1;
        unsigned int sd_quit_delay_enable : 1;
        unsigned int reserved_1 : 1;
        unsigned int sw_sel_pipe_enable : 1;
        unsigned int pactive_delay_enable : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 4;
        unsigned int sw_sel_pipe : 4;
        unsigned int pactive_sample_threshold : 4;
        unsigned int reserved_6 : 4;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL38_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_chk_all_sd_ds_chain_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_chk_all_sd_ds_chain_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sdo_check_enable_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sdo_check_enable_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sd_quit_delay_enable_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sd_quit_delay_enable_END (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sw_sel_pipe_enable_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sw_sel_pipe_enable_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_pactive_delay_enable_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_pactive_delay_enable_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sw_sel_pipe_START (20)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_sw_sel_pipe_END (23)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_pactive_sample_threshold_START (24)
#define SOC_ISPCPU_LOCAL_PERI_CTRL38_pactive_sample_threshold_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_config_mode_thread0 : 1;
        unsigned int core7_config_mode_thread1 : 1;
        unsigned int core7_config_mode_smt_en : 1;
        unsigned int core7_bypass_force_mt_mode : 1;
        unsigned int core6_config_mode_thread0 : 1;
        unsigned int core6_config_mode_thread1 : 1;
        unsigned int core6_config_mode_smt_en : 1;
        unsigned int core6_bypass_force_mt_mode : 1;
        unsigned int core5_config_mode_thread0 : 1;
        unsigned int core5_config_mode_thread1 : 1;
        unsigned int core5_config_mode_smt_en : 1;
        unsigned int core5_bypass_force_mt_mode : 1;
        unsigned int core4_config_mode_thread0 : 1;
        unsigned int core4_config_mode_thread1 : 1;
        unsigned int core4_config_mode_smt_en : 1;
        unsigned int core4_bypass_force_mt_mode : 1;
        unsigned int masken : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL39_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_config_mode_thread0_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_config_mode_thread0_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_config_mode_thread1_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_config_mode_thread1_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_config_mode_smt_en_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_config_mode_smt_en_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_bypass_force_mt_mode_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core7_bypass_force_mt_mode_END (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_config_mode_thread0_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_config_mode_thread0_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_config_mode_thread1_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_config_mode_thread1_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_config_mode_smt_en_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_config_mode_smt_en_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_bypass_force_mt_mode_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core6_bypass_force_mt_mode_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_config_mode_thread0_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_config_mode_thread0_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_config_mode_thread1_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_config_mode_thread1_END (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_config_mode_smt_en_START (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_config_mode_smt_en_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_bypass_force_mt_mode_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core5_bypass_force_mt_mode_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_config_mode_thread0_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_config_mode_thread0_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_config_mode_thread1_START (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_config_mode_thread1_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_config_mode_smt_en_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_config_mode_smt_en_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_bypass_force_mt_mode_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_core4_bypass_force_mt_mode_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_masken_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL39_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu7_thread0_idle_wakeup_mask : 1;
        unsigned int cpu7_thread1_idle_wakeup_mask : 1;
        unsigned int cpu7_thread0_hotplug_wakeup_mask : 1;
        unsigned int cpu7_thread1_hotplug_wakeup_mask : 1;
        unsigned int cpu6_thread0_idle_wakeup_mask : 1;
        unsigned int cpu6_thread1_idle_wakeup_mask : 1;
        unsigned int cpu6_thread0_hotplug_wakeup_mask : 1;
        unsigned int cpu6_thread1_hotplug_wakeup_mask : 1;
        unsigned int cpu5_thread0_idle_wakeup_mask : 1;
        unsigned int cpu5_thread1_idle_wakeup_mask : 1;
        unsigned int cpu5_thread0_hotplug_wakeup_mask : 1;
        unsigned int cpu5_thread1_hotplug_wakeup_mask : 1;
        unsigned int cpu4_thread0_idle_wakeup_mask : 1;
        unsigned int cpu4_thread1_idle_wakeup_mask : 1;
        unsigned int cpu4_thread0_hotplug_wakeup_mask : 1;
        unsigned int cpu4_thread1_hotplug_wakeup_mask : 1;
        unsigned int core_wakeup_masken : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL40_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread0_idle_wakeup_mask_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread0_idle_wakeup_mask_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread1_idle_wakeup_mask_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread1_idle_wakeup_mask_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread0_hotplug_wakeup_mask_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread0_hotplug_wakeup_mask_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread1_hotplug_wakeup_mask_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu7_thread1_hotplug_wakeup_mask_END (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread0_idle_wakeup_mask_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread0_idle_wakeup_mask_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread1_idle_wakeup_mask_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread1_idle_wakeup_mask_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread0_hotplug_wakeup_mask_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread0_hotplug_wakeup_mask_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread1_hotplug_wakeup_mask_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu6_thread1_hotplug_wakeup_mask_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread0_idle_wakeup_mask_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread0_idle_wakeup_mask_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread1_idle_wakeup_mask_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread1_idle_wakeup_mask_END (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread0_hotplug_wakeup_mask_START (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread0_hotplug_wakeup_mask_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread1_hotplug_wakeup_mask_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu5_thread1_hotplug_wakeup_mask_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread0_idle_wakeup_mask_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread0_idle_wakeup_mask_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread1_idle_wakeup_mask_START (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread1_idle_wakeup_mask_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread0_hotplug_wakeup_mask_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread0_hotplug_wakeup_mask_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread1_hotplug_wakeup_mask_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_cpu4_thread1_hotplug_wakeup_mask_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_core_wakeup_masken_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL40_core_wakeup_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread0_pwron_arbit : 1;
        unsigned int core6_thread0_pwron_arbit : 1;
        unsigned int core5_thread0_pwron_arbit : 1;
        unsigned int core4_thread0_pwron_arbit : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL41_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core7_thread0_pwron_arbit_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core7_thread0_pwron_arbit_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core6_thread0_pwron_arbit_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core6_thread0_pwron_arbit_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core5_thread0_pwron_arbit_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core5_thread0_pwron_arbit_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core4_thread0_pwron_arbit_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL41_core4_thread0_pwron_arbit_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread1_pwron_arbit : 1;
        unsigned int core6_thread1_pwron_arbit : 1;
        unsigned int core5_thread1_pwron_arbit : 1;
        unsigned int core4_thread1_pwron_arbit : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL42_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core7_thread1_pwron_arbit_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core7_thread1_pwron_arbit_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core6_thread1_pwron_arbit_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core6_thread1_pwron_arbit_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core5_thread1_pwron_arbit_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core5_thread1_pwron_arbit_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core4_thread1_pwron_arbit_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL42_core4_thread1_pwron_arbit_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread0_pwrdn_arbit : 1;
        unsigned int core6_thread0_pwrdn_arbit : 1;
        unsigned int core5_thread0_pwrdn_arbit : 1;
        unsigned int core4_thread0_pwrdn_arbit : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL43_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core7_thread0_pwrdn_arbit_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core7_thread0_pwrdn_arbit_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core6_thread0_pwrdn_arbit_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core6_thread0_pwrdn_arbit_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core5_thread0_pwrdn_arbit_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core5_thread0_pwrdn_arbit_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core4_thread0_pwrdn_arbit_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL43_core4_thread0_pwrdn_arbit_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread1_pwrdn_arbit : 1;
        unsigned int core6_thread1_pwrdn_arbit : 1;
        unsigned int core5_thread1_pwrdn_arbit : 1;
        unsigned int core4_thread1_pwrdn_arbit : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL44_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core7_thread1_pwrdn_arbit_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core7_thread1_pwrdn_arbit_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core6_thread1_pwrdn_arbit_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core6_thread1_pwrdn_arbit_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core5_thread1_pwrdn_arbit_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core5_thread1_pwrdn_arbit_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core4_thread1_pwrdn_arbit_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL44_core4_thread1_pwrdn_arbit_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_rs_gate_en : 1;
        unsigned int l3sys_ckb_devorder_en : 1;
        unsigned int sys_sha_ckb_cfg_en : 1;
        unsigned int hisi_sve2_crypto_disable : 1;
        unsigned int l3sys_ckb_force_clk_en_i : 1;
        unsigned int core7_ckb_force_clk_en_i : 1;
        unsigned int syscoack_from_qice_bypass : 1;
        unsigned int syscoreq_to_qice : 1;
        unsigned int l3sys_ckb_sce_stash_en : 1;
        unsigned int l3sys_ckb_sce_we_en : 1;
        unsigned int l3sys_ckb_sce_cmo_en : 1;
        unsigned int namtso_djtag_clken : 1;
        unsigned int core456_ckb_force_clk_en_i : 1;
        unsigned int enable_active_for_bdq_clk : 1;
        unsigned int chi_pwrctl_mux_sel : 1;
        unsigned int reserved : 1;
        unsigned int masken_45 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL45_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_chi_rs_gate_en_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_chi_rs_gate_en_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_devorder_en_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_devorder_en_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_sys_sha_ckb_cfg_en_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_sys_sha_ckb_cfg_en_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_hisi_sve2_crypto_disable_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_hisi_sve2_crypto_disable_END (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_force_clk_en_i_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_force_clk_en_i_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_core7_ckb_force_clk_en_i_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_core7_ckb_force_clk_en_i_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_syscoack_from_qice_bypass_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_syscoack_from_qice_bypass_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_syscoreq_to_qice_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_syscoreq_to_qice_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_sce_stash_en_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_sce_stash_en_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_sce_we_en_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_sce_we_en_END (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_sce_cmo_en_START (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_l3sys_ckb_sce_cmo_en_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_namtso_djtag_clken_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_namtso_djtag_clken_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_core456_ckb_force_clk_en_i_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_core456_ckb_force_clk_en_i_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_enable_active_for_bdq_clk_START (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_enable_active_for_bdq_clk_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_chi_pwrctl_mux_sel_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_chi_pwrctl_mux_sel_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_masken_45_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL45_masken_45_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_sw_wakeup_auto_mask_bypass : 1;
        unsigned int core7_sw_pwron_to_wakeup_bypass : 1;
        unsigned int core7_gic_wakeup_thread0_auto_mask_bypass : 1;
        unsigned int core7_gic_wakeup_thread1_auto_mask_bypass : 1;
        unsigned int core6_sw_wakeup_auto_mask_bypass : 1;
        unsigned int core6_sw_pwron_to_wakeup_bypass : 1;
        unsigned int core6_gic_wakeup_thread0_auto_mask_bypass : 1;
        unsigned int core6_gic_wakeup_thread1_auto_mask_bypass : 1;
        unsigned int core5_sw_wakeup_auto_mask_bypass : 1;
        unsigned int core5_sw_pwron_to_wakeup_bypass : 1;
        unsigned int core5_gic_wakeup_thread0_auto_mask_bypass : 1;
        unsigned int core5_gic_wakeup_thread1_auto_mask_bypass : 1;
        unsigned int core4_sw_wakeup_auto_mask_bypass : 1;
        unsigned int core4_sw_pwron_to_wakeup_bypass : 1;
        unsigned int core4_gic_wakeup_thread0_auto_mask_bypass : 1;
        unsigned int core4_gic_wakeup_thread1_auto_mask_bypass : 1;
        unsigned int masken_46 : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL46_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_sw_wakeup_auto_mask_bypass_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_sw_wakeup_auto_mask_bypass_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_sw_pwron_to_wakeup_bypass_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_sw_pwron_to_wakeup_bypass_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_gic_wakeup_thread0_auto_mask_bypass_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_gic_wakeup_thread0_auto_mask_bypass_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_gic_wakeup_thread1_auto_mask_bypass_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core7_gic_wakeup_thread1_auto_mask_bypass_END (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_sw_wakeup_auto_mask_bypass_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_sw_wakeup_auto_mask_bypass_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_sw_pwron_to_wakeup_bypass_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_sw_pwron_to_wakeup_bypass_END (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_gic_wakeup_thread0_auto_mask_bypass_START (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_gic_wakeup_thread0_auto_mask_bypass_END (6)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_gic_wakeup_thread1_auto_mask_bypass_START (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core6_gic_wakeup_thread1_auto_mask_bypass_END (7)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_sw_wakeup_auto_mask_bypass_START (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_sw_wakeup_auto_mask_bypass_END (8)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_sw_pwron_to_wakeup_bypass_START (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_sw_pwron_to_wakeup_bypass_END (9)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_gic_wakeup_thread0_auto_mask_bypass_START (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_gic_wakeup_thread0_auto_mask_bypass_END (10)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_gic_wakeup_thread1_auto_mask_bypass_START (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core5_gic_wakeup_thread1_auto_mask_bypass_END (11)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_sw_wakeup_auto_mask_bypass_START (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_sw_wakeup_auto_mask_bypass_END (12)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_sw_pwron_to_wakeup_bypass_START (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_sw_pwron_to_wakeup_bypass_END (13)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_gic_wakeup_thread0_auto_mask_bypass_START (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_gic_wakeup_thread0_auto_mask_bypass_END (14)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_gic_wakeup_thread1_auto_mask_bypass_START (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_core4_gic_wakeup_thread1_auto_mask_bypass_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_masken_46_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL46_masken_46_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL47_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sd_quit_threshold : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL48_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL48_sd_quit_threshold_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL48_sd_quit_threshold_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL49_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL50_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL51_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_adb_latch_bypass : 1;
        unsigned int chi_adb_linkactive_bypass : 1;
        unsigned int lit_chi_adb_latch_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL52_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_chi_adb_latch_bypass_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_chi_adb_latch_bypass_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_chi_adb_linkactive_bypass_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_chi_adb_linkactive_bypass_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_lit_chi_adb_latch_bypass_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL52_lit_chi_adb_latch_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int portion0_1_2_on : 1;
        unsigned int pipe_is_first : 2;
        unsigned int reserved : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL53_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_portion0_1_2_on_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_portion0_1_2_on_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_pipe_is_first_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_pipe_is_first_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_bitmasken_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL53_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_core_pwstat_set : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_SET_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_SET_cpu_core_pwstat_set_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_SET_cpu_core_pwstat_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_core_pwstat_clr : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_CLR_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_CLR_cpu_core_pwstat_clr_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_CLR_cpu_core_pwstat_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_core_pwstat_stat : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_STAT_cpu_core_pwstat_stat_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_PWSTAT_STAT_cpu_core_pwstat_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_core_idlestat_set : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_SET_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_SET_cpu_core_idlestat_set_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_SET_cpu_core_idlestat_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_core_idlestat_clr : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_CLR_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_CLR_cpu_core_idlestat_clr_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_CLR_cpu_core_idlestat_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_core_idlestat_stat : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_STAT_cpu_core_idlestat_stat_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CPU_CORE_IDLESTAT_STAT_cpu_core_idlestat_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ds_wait_cycle_sd : 16;
        unsigned int sdo_threshold : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL60_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL60_ds_wait_cycle_sd_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL60_ds_wait_cycle_sd_END (15)
#define SOC_ISPCPU_LOCAL_PERI_CTRL60_sdo_threshold_START (16)
#define SOC_ISPCPU_LOCAL_PERI_CTRL60_sdo_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL61_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL62_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hc_clk_idle_freqdown_bypass : 1;
        unsigned int lit_clk_idle_freqdown_bypass : 1;
        unsigned int hcclk_idle_gate_bypass : 1;
        unsigned int litclk_idle_gate_bypass : 1;
        unsigned int pwakeup_bypass : 1;
        unsigned int bypass_pprot_addr31_klein : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_CTRL63_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_hc_clk_idle_freqdown_bypass_START (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_hc_clk_idle_freqdown_bypass_END (0)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_lit_clk_idle_freqdown_bypass_START (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_lit_clk_idle_freqdown_bypass_END (1)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_hcclk_idle_gate_bypass_START (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_hcclk_idle_gate_bypass_END (2)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_litclk_idle_gate_bypass_START (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_litclk_idle_gate_bypass_END (3)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_pwakeup_bypass_START (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_pwakeup_bypass_END (4)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_bypass_pprot_addr31_klein_START (5)
#define SOC_ISPCPU_LOCAL_PERI_CTRL63_bypass_pprot_addr31_klein_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr0 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_rvbaraddr0_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_rvbaraddr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr0_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_HIGH_rvbaraddr0_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL0_HIGH_rvbaraddr0_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr1 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_rvbaraddr1_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_rvbaraddr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr1_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_HIGH_rvbaraddr1_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL1_HIGH_rvbaraddr1_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr2 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_rvbaraddr2_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_rvbaraddr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr2_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_HIGH_rvbaraddr2_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL2_HIGH_rvbaraddr2_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr3 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_rvbaraddr3_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_rvbaraddr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr3_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_HIGH_rvbaraddr3_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL3_HIGH_rvbaraddr3_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr4_t0 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_rvbaraddr4_t0_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_rvbaraddr4_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr4_t0_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_HIGH_rvbaraddr4_t0_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL4_HIGH_rvbaraddr4_t0_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr4_t1 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_rvbaraddr4_t1_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_rvbaraddr4_t1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr4_t1_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_HIGH_rvbaraddr4_t1_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL5_HIGH_rvbaraddr4_t1_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr5_t0 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_rvbaraddr5_t0_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_rvbaraddr5_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr5_t0_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_HIGH_rvbaraddr5_t0_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL6_HIGH_rvbaraddr5_t0_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr5_t1 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_rvbaraddr5_t1_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_rvbaraddr5_t1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr5_t1_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_HIGH_rvbaraddr5_t1_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL7_HIGH_rvbaraddr5_t1_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr6_t0 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_rvbaraddr6_t0_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_rvbaraddr6_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr6_t0_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_HIGH_rvbaraddr6_t0_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL8_HIGH_rvbaraddr6_t0_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr6_t1 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_rvbaraddr6_t1_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_rvbaraddr6_t1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr6_t1_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_HIGH_rvbaraddr6_t1_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL9_HIGH_rvbaraddr6_t1_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr7_t0 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_rvbaraddr7_t0_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_rvbaraddr7_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr7_t0_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_HIGH_rvbaraddr7_t0_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL10_HIGH_rvbaraddr7_t0_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int rvbaraddr7_t1 : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_rvbaraddr7_t1_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_rvbaraddr7_t1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvbaraddr7_t1_high : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_HIGH_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_HIGH_rvbaraddr7_t1_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_CTRL11_HIGH_rvbaraddr7_t1_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_rvbar_lock : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_LOCK_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_LOCK_fcm_rvbar_lock_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_RVBAR_LOCK_fcm_rvbar_lock_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int namtso_chkbit : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL400_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL400_namtso_chkbit_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL400_namtso_chkbit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int namtso_chkbit2 : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL404_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL404_namtso_chkbit2_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL404_namtso_chkbit2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_sys_cnt_en_dly : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL408_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL408_fcm_sys_cnt_en_dly_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL408_fcm_sys_cnt_en_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL40C_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_onchip_rom_end : 16;
        unsigned int lit_onchip_rom_start : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL410_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL410_lit_onchip_rom_end_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL410_lit_onchip_rom_end_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL410_lit_onchip_rom_start_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL410_lit_onchip_rom_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_sys_chl_pu_wait_bypass : 1;
        unsigned int lit_gic_pu_bypass : 1;
        unsigned int lit_dbg_pu_bypass : 1;
        unsigned int lit_sys_chl_pd_wait : 1;
        unsigned int lit_gic_pd_bypass : 1;
        unsigned int lit_atb_pd_bypass : 1;
        unsigned int lit_dbg_pd_bypass : 1;
        unsigned int lit_event_pd_bypass : 1;
        unsigned int lit_axistream_pd_bypass : 1;
        unsigned int lit_ckb_disaccheinvalid : 1;
        unsigned int lit_clister_onreq_ckb : 1;
        unsigned int lit_cluster_cg_disable_ckb : 1;
        unsigned int lit_syscnt_sample_alon_ckb : 1;
        unsigned int lit_cluster_pwrdn_dly_en : 1;
        unsigned int lit_event_cpu_wakeup_mask_bp_ckb : 1;
        unsigned int lc600_core_in_cg_bp_ckb : 1;
        unsigned int lit_flush_packet_req : 1;
        unsigned int lit_core_pwrdn_block_apb : 4;
        unsigned int lc600_core_cg_disable_chkbit_o : 1;
        unsigned int lit_chkbit : 10;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_sys_chl_pu_wait_bypass_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_sys_chl_pu_wait_bypass_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_gic_pu_bypass_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_gic_pu_bypass_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_dbg_pu_bypass_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_dbg_pu_bypass_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_sys_chl_pd_wait_START (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_sys_chl_pd_wait_END (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_gic_pd_bypass_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_gic_pd_bypass_END (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_atb_pd_bypass_START (5)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_atb_pd_bypass_END (5)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_dbg_pd_bypass_START (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_dbg_pd_bypass_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_event_pd_bypass_START (7)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_event_pd_bypass_END (7)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_axistream_pd_bypass_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_axistream_pd_bypass_END (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_ckb_disaccheinvalid_START (9)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_ckb_disaccheinvalid_END (9)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_clister_onreq_ckb_START (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_clister_onreq_ckb_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_cluster_cg_disable_ckb_START (11)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_cluster_cg_disable_ckb_END (11)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_syscnt_sample_alon_ckb_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_syscnt_sample_alon_ckb_END (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_cluster_pwrdn_dly_en_START (13)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_cluster_pwrdn_dly_en_END (13)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_event_cpu_wakeup_mask_bp_ckb_START (14)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_event_cpu_wakeup_mask_bp_ckb_END (14)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lc600_core_in_cg_bp_ckb_START (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lc600_core_in_cg_bp_ckb_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_flush_packet_req_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_flush_packet_req_END (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_core_pwrdn_block_apb_START (17)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_core_pwrdn_block_apb_END (20)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lc600_core_cg_disable_chkbit_o_START (21)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lc600_core_cg_disable_chkbit_o_END (21)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_chkbit_START (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL414_lit_chkbit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_way_index_sel : 1;
        unsigned int lit_ckb_tq_wait_data : 1;
        unsigned int lit_ckb_tag_hash_en : 1;
        unsigned int lit_ckb_mst_ads_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int lit_cpu_slv_clk_always_en : 1;
        unsigned int lit_adbbrg_clk_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int lit_ckb_ext_intf_ctl : 4;
        unsigned int lit_ckb_ncdev_wu_ely_deq_en : 1;
        unsigned int lit_force_timer_tcg_enable : 1;
        unsigned int lit_chk_adb_unmask_rxsnp_credit_qactive : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int lit_clkoff_gicclk_harden : 1;
        unsigned int lit_clkoff_periphclk_harden : 1;
        unsigned int lit_clkoff_pclk_harden : 1;
        unsigned int lit_freq_sel : 2;
        unsigned int lit_sys_cnt_en_dly : 6;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_way_index_sel_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_way_index_sel_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_tq_wait_data_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_tq_wait_data_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_tag_hash_en_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_tag_hash_en_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_mst_ads_en_START (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_mst_ads_en_END (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_cpu_slv_clk_always_en_START (9)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_cpu_slv_clk_always_en_END (9)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_adbbrg_clk_en_START (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_adbbrg_clk_en_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_ext_intf_ctl_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_ext_intf_ctl_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_ncdev_wu_ely_deq_en_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_ckb_ncdev_wu_ely_deq_en_END (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_force_timer_tcg_enable_START (17)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_force_timer_tcg_enable_END (17)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_chk_adb_unmask_rxsnp_credit_qactive_START (18)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_chk_adb_unmask_rxsnp_credit_qactive_END (18)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_clkoff_gicclk_harden_START (21)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_clkoff_gicclk_harden_END (21)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_clkoff_periphclk_harden_START (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_clkoff_periphclk_harden_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_clkoff_pclk_harden_START (23)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_clkoff_pclk_harden_END (23)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_freq_sel_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_freq_sel_END (25)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_sys_cnt_en_dly_START (26)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL418_lit_sys_cnt_en_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_broadcastatomic : 1;
        unsigned int lit_broadcastatomicmp : 1;
        unsigned int lit_broadcastcachemaint : 1;
        unsigned int lit_broadcastcachemaintmp : 1;
        unsigned int lit_broadcastinnner : 1;
        unsigned int lit_broadcastatouter : 1;
        unsigned int lit_broadcastoutermp : 1;
        unsigned int lit_broadcastperist : 1;
        unsigned int lit_broadcastperistmp : 1;
        unsigned int lit_broadcasttlbinner : 1;
        unsigned int lit_broadcasttlbouter : 1;
        unsigned int lit_broadcastmte : 1;
        unsigned int lit_broadcastcinval : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastatomic_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastatomic_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastatomicmp_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastatomicmp_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastcachemaint_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastcachemaint_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastcachemaintmp_START (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastcachemaintmp_END (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastinnner_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastinnner_END (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastatouter_START (5)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastatouter_END (5)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastoutermp_START (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastoutermp_END (6)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastperist_START (7)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastperist_END (7)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastperistmp_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastperistmp_END (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcasttlbinner_START (9)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcasttlbinner_END (9)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcasttlbouter_START (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcasttlbouter_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastmte_START (11)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastmte_END (11)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastcinval_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL41C_lit_broadcastcinval_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int sl2_cluster_pactive_delay_enable : 1;
        unsigned int reserved_1 : 1;
        unsigned int sl2_cluster_pactive_sample_threshold : 4;
        unsigned int reserved_2 : 8;
        unsigned int sl2_cluster_pstate_sys : 8;
        unsigned int sl2_cluster_memctl_sys : 3;
        unsigned int sl2_cluster_preq_sys : 1;
        unsigned int reserved_3 : 3;
        unsigned int sl2_cluster_pchannel_enable : 1;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pactive_delay_enable_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pactive_delay_enable_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pactive_sample_threshold_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pactive_sample_threshold_END (7)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pstate_sys_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pstate_sys_END (23)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_memctl_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_memctl_sys_END (26)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_preq_sys_START (27)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_preq_sys_END (27)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pchannel_enable_START (31)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL420_sl2_cluster_pchannel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sl2_cluster_phannel_wait_cycle : 16;
        unsigned int sl2_cluster_memctl_normal : 3;
        unsigned int reserved_0 : 1;
        unsigned int sl2_cluster_memctl_sd : 3;
        unsigned int reserved_1 : 1;
        unsigned int sl2_cluster_memctl_ds : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_phannel_wait_cycle_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_phannel_wait_cycle_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_memctl_normal_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_memctl_normal_END (18)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_memctl_sd_START (20)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_memctl_sd_END (22)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_memctl_ds_START (24)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL424_sl2_cluster_memctl_ds_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocldo_bypass : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL428_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL428_ocldo_bypass_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL428_ocldo_bypass_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sl2_cluster_force_disable_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL42C_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL42C_sl2_cluster_force_disable_off_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL42C_sl2_cluster_force_disable_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sl2_cluster_force_off_to_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL430_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL430_sl2_cluster_force_off_to_on_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL430_sl2_cluster_force_off_to_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_adb_crg_rst_en : 1;
        unsigned int hc_adb_crg_rst_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL434_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL434_lit_adb_crg_rst_en_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL434_lit_adb_crg_rst_en_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL434_hc_adb_crg_rst_en_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL434_hc_adb_crg_rst_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_adb_crg_rst_dis : 1;
        unsigned int hc_adb_crg_rst_dis : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL438_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL438_lit_adb_crg_rst_dis_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL438_lit_adb_crg_rst_dis_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL438_hc_adb_crg_rst_dis_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL438_hc_adb_crg_rst_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_adb_crg_rst_stat : 1;
        unsigned int hc_adb_crg_rst_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL43C_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL43C_lit_adb_crg_rst_stat_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL43C_lit_adb_crg_rst_stat_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL43C_hc_adb_crg_rst_stat_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PERI_CTRL43C_hc_adb_crg_rst_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core0_pactive_to_sys : 20;
        unsigned int core0_paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int core0_pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int core0_can_pd : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT0_core0_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core1_pactive_to_sys : 20;
        unsigned int core1_paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int core1_pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int core1_can_pd : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT1_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT1_core1_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core2_pactive_to_sys : 20;
        unsigned int core2_paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int core2_pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int core2_can_pd : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT2_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT2_core2_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core3_pactive_to_sys : 20;
        unsigned int core3_paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int core3_pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int core3_can_pd : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT3_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT3_core3_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core4_pactive_to_sys : 20;
        unsigned int core4_paccept_to_sys : 1;
        unsigned int core4_force_smt_en_is_mt : 1;
        unsigned int reserved_0 : 2;
        unsigned int core4_pdeny_to_sys : 1;
        unsigned int core4_p_channel_handshake_done : 1;
        unsigned int reserved_1 : 2;
        unsigned int core4_can_pd : 1;
        unsigned int core4_config_mode_final : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT4_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_force_smt_en_is_mt_START (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_force_smt_en_is_mt_END (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_p_channel_handshake_done_START (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_p_channel_handshake_done_END (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_can_pd_END (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_config_mode_final_START (29)
#define SOC_ISPCPU_LOCAL_PERI_STAT4_core4_config_mode_final_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core5_pactive_to_sys : 20;
        unsigned int core5_paccept_to_sys : 1;
        unsigned int core5_force_smt_en_is_mt : 1;
        unsigned int reserved_0 : 2;
        unsigned int core5_pdeny_to_sys : 1;
        unsigned int core5_p_channel_handshake_done : 1;
        unsigned int reserved_1 : 2;
        unsigned int core5_can_pd : 1;
        unsigned int core5_config_mode_final : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT5_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_force_smt_en_is_mt_START (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_force_smt_en_is_mt_END (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_p_channel_handshake_done_START (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_p_channel_handshake_done_END (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_can_pd_END (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_config_mode_final_START (29)
#define SOC_ISPCPU_LOCAL_PERI_STAT5_core5_config_mode_final_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core6_pactive_to_sys : 20;
        unsigned int core6_paccept_to_sys : 1;
        unsigned int core6_force_smt_en_is_mt : 1;
        unsigned int reserved_0 : 2;
        unsigned int core6_pdeny_to_sys : 1;
        unsigned int core6_p_channel_handshake_done : 1;
        unsigned int reserved_1 : 2;
        unsigned int core6_can_pd : 1;
        unsigned int core6_config_mode_final : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT6_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_force_smt_en_is_mt_START (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_force_smt_en_is_mt_END (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_p_channel_handshake_done_START (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_p_channel_handshake_done_END (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_can_pd_END (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_config_mode_final_START (29)
#define SOC_ISPCPU_LOCAL_PERI_STAT6_core6_config_mode_final_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_pactive_to_sys : 20;
        unsigned int core7_paccept_to_sys : 1;
        unsigned int core7_force_smt_en_is_mt : 1;
        unsigned int reserved_0 : 2;
        unsigned int core7_pdeny_to_sys : 1;
        unsigned int core7_p_channel_handshake_done : 1;
        unsigned int reserved_1 : 2;
        unsigned int core7_can_pd : 1;
        unsigned int core7_config_mode_final : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT7_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_force_smt_en_is_mt_START (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_force_smt_en_is_mt_END (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_p_channel_handshake_done_START (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_p_channel_handshake_done_END (25)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_can_pd_END (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_config_mode_final_START (29)
#define SOC_ISPCPU_LOCAL_PERI_STAT7_core7_config_mode_final_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cluster_pactive_to_sys : 20;
        unsigned int cluster_paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int cluster_pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int cluster_can_pd : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT8_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_pdeny_to_sys_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_pdeny_to_sys_END (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_can_pd_START (28)
#define SOC_ISPCPU_LOCAL_PERI_STAT8_cluster_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int custom_wfi : 1;
        unsigned int custom_wfe : 1;
        unsigned int standbywfi_pdc : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT9_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT9_custom_wfi_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT9_custom_wfi_END (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT9_custom_wfe_START (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT9_custom_wfe_END (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT9_standbywfi_pdc_START (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT9_standbywfi_pdc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_bisr_req : 7;
        unsigned int reserved_0 : 4;
        unsigned int core_pdc_sdo_ack : 8;
        unsigned int complex_pdc_sdo_ack : 2;
        unsigned int reserved_1 : 2;
        unsigned int standbywfi_pdc_l3 : 1;
        unsigned int standbywfi_pdc_sl2 : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT10_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT10_core_bisr_req_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_core_bisr_req_END (6)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_core_pdc_sdo_ack_START (11)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_core_pdc_sdo_ack_END (18)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_complex_pdc_sdo_ack_START (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_complex_pdc_sdo_ack_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_standbywfi_pdc_l3_START (23)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_standbywfi_pdc_l3_END (23)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_standbywfi_pdc_sl2_START (24)
#define SOC_ISPCPU_LOCAL_PERI_STAT10_standbywfi_pdc_sl2_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cluster_paccept : 1;
        unsigned int cluster_pdeny : 1;
        unsigned int cluster_preq : 1;
        unsigned int cluster_pstate : 9;
        unsigned int cluster_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_pstate_START (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_pstate_END (11)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CLUSTER_PCHANNEL_STAT_cluster_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core0_paccept : 1;
        unsigned int core0_pdeny : 1;
        unsigned int core0_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core0_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core0_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE0_PCHANNEL_STAT_core0_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core1_paccept : 1;
        unsigned int core1_pdeny : 1;
        unsigned int core1_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core1_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core1_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE1_PCHANNEL_STAT_core1_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core2_paccept : 1;
        unsigned int core2_pdeny : 1;
        unsigned int core2_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core2_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core2_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE2_PCHANNEL_STAT_core2_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core3_paccept : 1;
        unsigned int core3_pdeny : 1;
        unsigned int core3_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core3_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core3_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE3_PCHANNEL_STAT_core3_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core4_paccept : 1;
        unsigned int core4_pdeny : 1;
        unsigned int core4_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core4_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core4_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE4_PCHANNEL_STAT_core4_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core5_paccept : 1;
        unsigned int core5_pdeny : 1;
        unsigned int core5_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core5_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core5_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE5_PCHANNEL_STAT_core5_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core6_paccept : 1;
        unsigned int core6_pdeny : 1;
        unsigned int core6_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core6_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core6_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE6_PCHANNEL_STAT_core6_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_paccept : 1;
        unsigned int core7_pdeny : 1;
        unsigned int core7_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core7_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core7_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_pstate_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_pstate_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE7_PCHANNEL_STAT_core7_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int current_state0 : 4;
        unsigned int core_pstate0 : 7;
        unsigned int reserved_0 : 5;
        unsigned int current_state1 : 4;
        unsigned int core_pstate1 : 7;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_current_state0_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_current_state0_END (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_current_state1_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_current_state1_END (19)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_START (20)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int current_state2 : 4;
        unsigned int core_pstate2 : 7;
        unsigned int reserved_0 : 5;
        unsigned int current_state3 : 4;
        unsigned int core_pstate3 : 7;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_current_state2_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_current_state2_END (3)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_START (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_END (10)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_current_state3_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_current_state3_END (19)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_START (20)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int current_state4 : 5;
        unsigned int core_pstate4 : 7;
        unsigned int illegal_fsm_state4 : 1;
        unsigned int real_corepactive4 : 3;
        unsigned int current_state5 : 5;
        unsigned int core_pstate5 : 7;
        unsigned int illegal_fsm_state5 : 1;
        unsigned int real_corepactive5 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_current_state4_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_current_state4_END (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_START (5)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_END (11)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_illegal_fsm_state4_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_illegal_fsm_state4_END (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_real_corepactive4_START (13)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_real_corepactive4_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_current_state5_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_current_state5_END (20)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_START (21)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_END (27)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_illegal_fsm_state5_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_illegal_fsm_state5_END (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_real_corepactive5_START (29)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE45_PCHANNEL_DEBUG_STAT_real_corepactive5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int current_state6 : 5;
        unsigned int core_pstate6 : 7;
        unsigned int illegal_fsm_state6 : 1;
        unsigned int real_corepactive6 : 3;
        unsigned int current_state7 : 5;
        unsigned int core_pstate7 : 7;
        unsigned int illegal_fsm_state7 : 1;
        unsigned int real_corepactive7 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_current_state6_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_current_state6_END (4)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_START (5)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_END (11)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_illegal_fsm_state6_START (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_illegal_fsm_state6_END (12)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_real_corepactive6_START (13)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_real_corepactive6_END (15)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_current_state7_START (16)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_current_state7_END (20)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_START (21)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_END (27)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_illegal_fsm_state7_START (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_illegal_fsm_state7_END (28)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_real_corepactive7_START (29)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_CORE67_PCHANNEL_DEBUG_STAT_real_corepactive7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cluster_current_state : 8;
        unsigned int sel_pipe_is_on : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_0_cluster_current_state_START (0)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_0_cluster_current_state_END (7)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_0_sel_pipe_is_on_START (8)
#define SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_0_sel_pipe_is_on_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread0_pwron_arb_result : 2;
        unsigned int core6_thread0_pwron_arb_result : 2;
        unsigned int core5_thread0_pwron_arb_result : 2;
        unsigned int core4_thread0_pwron_arb_result : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT25_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core7_thread0_pwron_arb_result_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core7_thread0_pwron_arb_result_END (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core6_thread0_pwron_arb_result_START (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core6_thread0_pwron_arb_result_END (3)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core5_thread0_pwron_arb_result_START (4)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core5_thread0_pwron_arb_result_END (5)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core4_thread0_pwron_arb_result_START (6)
#define SOC_ISPCPU_LOCAL_PERI_STAT25_core4_thread0_pwron_arb_result_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread1_pwron_arb_result : 2;
        unsigned int core6_thread1_pwron_arb_result : 2;
        unsigned int core5_thread1_pwron_arb_result : 2;
        unsigned int core4_thread1_pwron_arb_result : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT26_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core7_thread1_pwron_arb_result_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core7_thread1_pwron_arb_result_END (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core6_thread1_pwron_arb_result_START (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core6_thread1_pwron_arb_result_END (3)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core5_thread1_pwron_arb_result_START (4)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core5_thread1_pwron_arb_result_END (5)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core4_thread1_pwron_arb_result_START (6)
#define SOC_ISPCPU_LOCAL_PERI_STAT26_core4_thread1_pwron_arb_result_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread0_pwrdn_arb_result : 2;
        unsigned int core6_thread0_pwrdn_arb_result : 2;
        unsigned int core5_thread0_pwrdn_arb_result : 2;
        unsigned int core4_thread0_pwrdn_arb_result : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT27_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core7_thread0_pwrdn_arb_result_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core7_thread0_pwrdn_arb_result_END (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core6_thread0_pwrdn_arb_result_START (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core6_thread0_pwrdn_arb_result_END (3)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core5_thread0_pwrdn_arb_result_START (4)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core5_thread0_pwrdn_arb_result_END (5)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core4_thread0_pwrdn_arb_result_START (6)
#define SOC_ISPCPU_LOCAL_PERI_STAT27_core4_thread0_pwrdn_arb_result_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core7_thread1_pwrdn_arb_result : 2;
        unsigned int core6_thread1_pwrdn_arb_result : 2;
        unsigned int core5_thread1_pwrdn_arb_result : 2;
        unsigned int core4_thread1_pwrdn_arb_result : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT28_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core7_thread1_pwrdn_arb_result_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core7_thread1_pwrdn_arb_result_END (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core6_thread1_pwrdn_arb_result_START (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core6_thread1_pwrdn_arb_result_END (3)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core5_thread1_pwrdn_arb_result_START (4)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core5_thread1_pwrdn_arb_result_END (5)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core4_thread1_pwrdn_arb_result_START (6)
#define SOC_ISPCPU_LOCAL_PERI_STAT28_core4_thread1_pwrdn_arb_result_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_cpu_syscoack_m1 : 1;
        unsigned int qice_cpu_syscoreq_m1 : 1;
        unsigned int cpu_qice_syscoack_m1 : 1;
        unsigned int cpu_qice_syscoreq_m1 : 1;
        unsigned int rxlinkactiveack_m1 : 1;
        unsigned int rxlinkactivereq_m1 : 1;
        unsigned int txlinkactiveack_m1 : 1;
        unsigned int txlinkactivereq_m1 : 1;
        unsigned int qice_cpu_syscoack_m0 : 1;
        unsigned int qice_cpu_syscoreq_m0 : 1;
        unsigned int cpu_qice_syscoack_m0 : 1;
        unsigned int cpu_qice_syscoreq_m0 : 1;
        unsigned int rxlinkactiveack_m0 : 1;
        unsigned int rxlinkactivereq_m0 : 1;
        unsigned int txlinkactiveack_m0 : 1;
        unsigned int txlinkactivereq_m0 : 1;
        unsigned int qice_cpu_syscoack_lit : 1;
        unsigned int qice_cpu_syscoreq_lit : 1;
        unsigned int cpu_qice_syscoack_lit : 1;
        unsigned int cpu_qice_syscoreq_lit : 1;
        unsigned int rxlinkactiveack_lit : 1;
        unsigned int rxlinkactivereq_lit : 1;
        unsigned int txlinkactiveack_lit : 1;
        unsigned int txlinkactivereq_lit : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT29_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoack_m1_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoack_m1_END (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoreq_m1_START (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoreq_m1_END (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoack_m1_START (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoack_m1_END (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoreq_m1_START (3)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoreq_m1_END (3)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactiveack_m1_START (4)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactiveack_m1_END (4)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactivereq_m1_START (5)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactivereq_m1_END (5)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactiveack_m1_START (6)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactiveack_m1_END (6)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactivereq_m1_START (7)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactivereq_m1_END (7)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoack_m0_START (8)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoack_m0_END (8)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoreq_m0_START (9)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoreq_m0_END (9)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoack_m0_START (10)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoack_m0_END (10)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoreq_m0_START (11)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoreq_m0_END (11)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactiveack_m0_START (12)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactiveack_m0_END (12)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactivereq_m0_START (13)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactivereq_m0_END (13)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactiveack_m0_START (14)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactiveack_m0_END (14)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactivereq_m0_START (15)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactivereq_m0_END (15)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoack_lit_START (16)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoack_lit_END (16)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoreq_lit_START (17)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_qice_cpu_syscoreq_lit_END (17)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoack_lit_START (18)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoack_lit_END (18)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoreq_lit_START (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_cpu_qice_syscoreq_lit_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactiveack_lit_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactiveack_lit_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactivereq_lit_START (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_rxlinkactivereq_lit_END (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactiveack_lit_START (22)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactiveack_lit_END (22)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactivereq_lit_START (23)
#define SOC_ISPCPU_LOCAL_PERI_STAT29_txlinkactivereq_lit_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_idle : 1;
        unsigned int sl2_idle : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT30_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT30_core_idle_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT30_core_idle_END (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT30_sl2_idle_START (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT30_sl2_idle_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_ISPCPU_PCHANNEL_DEBUG_STAT_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sl2cluster_paccept : 1;
        unsigned int sl2cluster_pdeny : 1;
        unsigned int sl2cluster_preq : 1;
        unsigned int sl2cluster_pstate : 9;
        unsigned int sl2cluster_pactive : 20;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_paccept_START (0)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_paccept_END (0)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_pdeny_START (1)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_pdeny_END (1)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_preq_START (2)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_preq_END (2)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_pstate_START (3)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_pstate_END (11)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_pactive_START (12)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_STAT_sl2cluster_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sl2_pchannel_debug_info : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_DEBUG_INFO_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_DEBUG_INFO_sl2_pchannel_debug_info_START (0)
#define SOC_ISPCPU_LOCAL_PERI_SL2_CLUSTER_PCHANNEL_DEBUG_INFO_sl2_pchannel_debug_info_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_mst_dfx_status_hc0_low : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT34_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT34_adb_mst_dfx_status_hc0_low_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT34_adb_mst_dfx_status_hc0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_mst_dfx_status_hc0_high : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT35_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT35_adb_mst_dfx_status_hc0_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT35_adb_mst_dfx_status_hc0_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_mst_dfx_status_hc1_low : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT36_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT36_adb_mst_dfx_status_hc1_low_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT36_adb_mst_dfx_status_hc1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_mst_dfx_status_hc1_high : 32;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT37_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT37_adb_mst_dfx_status_hc1_high_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT37_adb_mst_dfx_status_hc1_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int psel_local_peri_active_sync : 1;
        unsigned int sl2_cluster_pchannel_tx_active : 1;
        unsigned int pchannle_tx_active : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT38_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT38_psel_local_peri_active_sync_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT38_psel_local_peri_active_sync_END (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT38_sl2_cluster_pchannel_tx_active_START (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT38_sl2_cluster_pchannel_tx_active_END (1)
#define SOC_ISPCPU_LOCAL_PERI_STAT38_pchannle_tx_active_START (2)
#define SOC_ISPCPU_LOCAL_PERI_STAT38_pchannle_tx_active_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sl2_cluster_pactive_to_sys : 20;
        unsigned int sl2_cluster_paccept_to_sys : 1;
        unsigned int sl2_cluster_pdeny_to_sys : 1;
        unsigned int sl2_cluster_can_power_down : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_ISPCPU_LOCAL_PERI_STAT39_UNION;
#endif
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_pactive_to_sys_START (0)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_pactive_to_sys_END (19)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_paccept_to_sys_START (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_paccept_to_sys_END (20)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_pdeny_to_sys_START (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_pdeny_to_sys_END (21)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_can_power_down_START (22)
#define SOC_ISPCPU_LOCAL_PERI_STAT39_sl2_cluster_can_power_down_END (22)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
