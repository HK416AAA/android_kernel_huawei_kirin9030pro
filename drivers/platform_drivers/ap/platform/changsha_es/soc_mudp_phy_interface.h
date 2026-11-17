#ifndef __SOC_MUDP_PHY_INTERFACE_H__
#define __SOC_MUDP_PHY_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_PHY_CP_CSR0_ADDR(base) (base)
#define SOC_MUDP_PHY_CP_CSR1_ADDR(base) ((base) + 0x0004UL)
#define SOC_MUDP_PHY_CP_CSR2_ADDR(base) ((base) + 0x0008UL)
#define SOC_MUDP_PHY_CP_CSR3_ADDR(base) ((base) + 0x000CUL)
#define SOC_MUDP_PHY_CP_CSR4_ADDR(base) ((base) + 0x0010UL)
#define SOC_MUDP_PHY_CP_CSR5_ADDR(base) ((base) + 0x0014UL)
#define SOC_MUDP_PHY_CP_CSR6_ADDR(base) ((base) + 0x0018UL)
#define SOC_MUDP_PHY_CP_CSR7_ADDR(base) ((base) + 0x001CUL)
#define SOC_MUDP_PHY_CP_CSR8_ADDR(base) ((base) + 0x0020UL)
#define SOC_MUDP_PHY_CP_CSR9_ADDR(base) ((base) + 0x0024UL)
#define SOC_MUDP_PHY_CP_CSR10_ADDR(base) ((base) + 0x0028UL)
#define SOC_MUDP_PHY_CP_CSR11_ADDR(base) ((base) + 0x002CUL)
#define SOC_MUDP_PHY_CP_CSR12_ADDR(base) ((base) + 0x0030UL)
#define SOC_MUDP_PHY_CP_CSR13_ADDR(base) ((base) + 0x0034UL)
#define SOC_MUDP_PHY_CP_CSR14_ADDR(base) ((base) + 0x0038UL)
#define SOC_MUDP_PHY_CP_CSR15_ADDR(base) ((base) + 0x003CUL)
#define SOC_MUDP_PHY_CP_CSR16_ADDR(base) ((base) + 0x0040UL)
#define SOC_MUDP_PHY_CP_CSR17_ADDR(base) ((base) + 0x0044UL)
#define SOC_MUDP_PHY_CP_CSR18_ADDR(base) ((base) + 0x0048UL)
#define SOC_MUDP_PHY_CP_CSR19_ADDR(base) ((base) + 0x004CUL)
#define SOC_MUDP_PHY_CP_CSR20_ADDR(base) ((base) + 0x0050UL)
#define SOC_MUDP_PHY_CP_CSR21_ADDR(base) ((base) + 0x0054UL)
#define SOC_MUDP_PHY_CP_CSR22_ADDR(base) ((base) + 0x0058UL)
#define SOC_MUDP_PHY_CP_CSR23_ADDR(base) ((base) + 0x005CUL)
#define SOC_MUDP_PHY_CP_CSR24_ADDR(base) ((base) + 0x0060UL)
#define SOC_MUDP_PHY_CP_CSR25_ADDR(base) ((base) + 0x0064UL)
#define SOC_MUDP_PHY_CP_CSR26_ADDR(base) ((base) + 0x0068UL)
#define SOC_MUDP_PHY_CP_CSR27_ADDR(base) ((base) + 0x006CUL)
#define SOC_MUDP_PHY_CP_CSR28_ADDR(base) ((base) + 0x0070UL)
#define SOC_MUDP_PHY_CP_CSR29_ADDR(base) ((base) + 0x0074UL)
#define SOC_MUDP_PHY_CP_CSR30_ADDR(base) ((base) + 0x0078UL)
#define SOC_MUDP_PHY_CP_CSR31_ADDR(base) ((base) + 0x007CUL)
#define SOC_MUDP_PHY_CP_CSR32_ADDR(base) ((base) + 0x0080UL)
#define SOC_MUDP_PHY_CP_CSR33_ADDR(base) ((base) + 0x0084UL)
#define SOC_MUDP_PHY_CP_CSR34_ADDR(base) ((base) + 0x0088UL)
#define SOC_MUDP_PHY_CP_CSR35_ADDR(base) ((base) + 0x008CUL)
#define SOC_MUDP_PHY_CP_CSR36_ADDR(base) ((base) + 0x0090UL)
#define SOC_MUDP_PHY_CP_CSR37_ADDR(base) ((base) + 0x0094UL)
#define SOC_MUDP_PHY_CP_CSR38_ADDR(base) ((base) + 0x0098UL)
#define SOC_MUDP_PHY_CP_CSR39_ADDR(base) ((base) + 0x009CUL)
#define SOC_MUDP_PHY_CP_CSR40_ADDR(base) ((base) + 0x00A0UL)
#define SOC_MUDP_PHY_CP_CSR41_ADDR(base) ((base) + 0x00A4UL)
#define SOC_MUDP_PHY_CP_CSR42_ADDR(base) ((base) + 0x00A8UL)
#define SOC_MUDP_PHY_CP_CSR43_ADDR(base) ((base) + 0x00ACUL)
#define SOC_MUDP_PHY_CP_CSR44_ADDR(base) ((base) + 0x00B0UL)
#define SOC_MUDP_PHY_CP_CSR45_ADDR(base) ((base) + 0x00B4UL)
#define SOC_MUDP_PHY_CP_CSR46_ADDR(base) ((base) + 0x00B8UL)
#define SOC_MUDP_PHY_CP_CSR47_ADDR(base) ((base) + 0x00BCUL)
#define SOC_MUDP_PHY_CP_CSR48_ADDR(base) ((base) + 0x00C0UL)
#else
#define SOC_MUDP_PHY_CP_CSR0_ADDR(base) (base)
#define SOC_MUDP_PHY_CP_CSR1_ADDR(base) ((base) + 0x0004)
#define SOC_MUDP_PHY_CP_CSR2_ADDR(base) ((base) + 0x0008)
#define SOC_MUDP_PHY_CP_CSR3_ADDR(base) ((base) + 0x000C)
#define SOC_MUDP_PHY_CP_CSR4_ADDR(base) ((base) + 0x0010)
#define SOC_MUDP_PHY_CP_CSR5_ADDR(base) ((base) + 0x0014)
#define SOC_MUDP_PHY_CP_CSR6_ADDR(base) ((base) + 0x0018)
#define SOC_MUDP_PHY_CP_CSR7_ADDR(base) ((base) + 0x001C)
#define SOC_MUDP_PHY_CP_CSR8_ADDR(base) ((base) + 0x0020)
#define SOC_MUDP_PHY_CP_CSR9_ADDR(base) ((base) + 0x0024)
#define SOC_MUDP_PHY_CP_CSR10_ADDR(base) ((base) + 0x0028)
#define SOC_MUDP_PHY_CP_CSR11_ADDR(base) ((base) + 0x002C)
#define SOC_MUDP_PHY_CP_CSR12_ADDR(base) ((base) + 0x0030)
#define SOC_MUDP_PHY_CP_CSR13_ADDR(base) ((base) + 0x0034)
#define SOC_MUDP_PHY_CP_CSR14_ADDR(base) ((base) + 0x0038)
#define SOC_MUDP_PHY_CP_CSR15_ADDR(base) ((base) + 0x003C)
#define SOC_MUDP_PHY_CP_CSR16_ADDR(base) ((base) + 0x0040)
#define SOC_MUDP_PHY_CP_CSR17_ADDR(base) ((base) + 0x0044)
#define SOC_MUDP_PHY_CP_CSR18_ADDR(base) ((base) + 0x0048)
#define SOC_MUDP_PHY_CP_CSR19_ADDR(base) ((base) + 0x004C)
#define SOC_MUDP_PHY_CP_CSR20_ADDR(base) ((base) + 0x0050)
#define SOC_MUDP_PHY_CP_CSR21_ADDR(base) ((base) + 0x0054)
#define SOC_MUDP_PHY_CP_CSR22_ADDR(base) ((base) + 0x0058)
#define SOC_MUDP_PHY_CP_CSR23_ADDR(base) ((base) + 0x005C)
#define SOC_MUDP_PHY_CP_CSR24_ADDR(base) ((base) + 0x0060)
#define SOC_MUDP_PHY_CP_CSR25_ADDR(base) ((base) + 0x0064)
#define SOC_MUDP_PHY_CP_CSR26_ADDR(base) ((base) + 0x0068)
#define SOC_MUDP_PHY_CP_CSR27_ADDR(base) ((base) + 0x006C)
#define SOC_MUDP_PHY_CP_CSR28_ADDR(base) ((base) + 0x0070)
#define SOC_MUDP_PHY_CP_CSR29_ADDR(base) ((base) + 0x0074)
#define SOC_MUDP_PHY_CP_CSR30_ADDR(base) ((base) + 0x0078)
#define SOC_MUDP_PHY_CP_CSR31_ADDR(base) ((base) + 0x007C)
#define SOC_MUDP_PHY_CP_CSR32_ADDR(base) ((base) + 0x0080)
#define SOC_MUDP_PHY_CP_CSR33_ADDR(base) ((base) + 0x0084)
#define SOC_MUDP_PHY_CP_CSR34_ADDR(base) ((base) + 0x0088)
#define SOC_MUDP_PHY_CP_CSR35_ADDR(base) ((base) + 0x008C)
#define SOC_MUDP_PHY_CP_CSR36_ADDR(base) ((base) + 0x0090)
#define SOC_MUDP_PHY_CP_CSR37_ADDR(base) ((base) + 0x0094)
#define SOC_MUDP_PHY_CP_CSR38_ADDR(base) ((base) + 0x0098)
#define SOC_MUDP_PHY_CP_CSR39_ADDR(base) ((base) + 0x009C)
#define SOC_MUDP_PHY_CP_CSR40_ADDR(base) ((base) + 0x00A0)
#define SOC_MUDP_PHY_CP_CSR41_ADDR(base) ((base) + 0x00A4)
#define SOC_MUDP_PHY_CP_CSR42_ADDR(base) ((base) + 0x00A8)
#define SOC_MUDP_PHY_CP_CSR43_ADDR(base) ((base) + 0x00AC)
#define SOC_MUDP_PHY_CP_CSR44_ADDR(base) ((base) + 0x00B0)
#define SOC_MUDP_PHY_CP_CSR45_ADDR(base) ((base) + 0x00B4)
#define SOC_MUDP_PHY_CP_CSR46_ADDR(base) ((base) + 0x00B8)
#define SOC_MUDP_PHY_CP_CSR47_ADDR(base) ((base) + 0x00BC)
#define SOC_MUDP_PHY_CP_CSR48_ADDR(base) ((base) + 0x00C0)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_PHY_CS_CSR0_ADDR(base) (base)
#define SOC_MUDP_PHY_CS_CSR1_ADDR(base) ((base) + 0x0004UL)
#define SOC_MUDP_PHY_CS_CSR2_ADDR(base) ((base) + 0x0008UL)
#define SOC_MUDP_PHY_CS_CSR3_ADDR(base) ((base) + 0x000CUL)
#define SOC_MUDP_PHY_CS_CSR4_ADDR(base) ((base) + 0x0010UL)
#define SOC_MUDP_PHY_CS_CSR5_ADDR(base) ((base) + 0x0014UL)
#define SOC_MUDP_PHY_CS_CSR6_ADDR(base) ((base) + 0x0018UL)
#define SOC_MUDP_PHY_CS_CSR7_ADDR(base) ((base) + 0x001CUL)
#define SOC_MUDP_PHY_CS_CSR8_ADDR(base) ((base) + 0x0020UL)
#define SOC_MUDP_PHY_CS_CSR9_ADDR(base) ((base) + 0x0024UL)
#define SOC_MUDP_PHY_CS_CSR10_ADDR(base) ((base) + 0x0028UL)
#define SOC_MUDP_PHY_CS_CSR11_ADDR(base) ((base) + 0x002CUL)
#define SOC_MUDP_PHY_CS_CSR12_ADDR(base) ((base) + 0x0030UL)
#define SOC_MUDP_PHY_CS_CSR13_ADDR(base) ((base) + 0x0034UL)
#define SOC_MUDP_PHY_CS_CSR14_ADDR(base) ((base) + 0x0038UL)
#define SOC_MUDP_PHY_CS_CSR15_ADDR(base) ((base) + 0x003CUL)
#define SOC_MUDP_PHY_CS_CSR16_ADDR(base) ((base) + 0x0040UL)
#define SOC_MUDP_PHY_CS_CSR17_ADDR(base) ((base) + 0x0044UL)
#define SOC_MUDP_PHY_CS_CSR18_ADDR(base) ((base) + 0x0048UL)
#define SOC_MUDP_PHY_CS_CSR19_ADDR(base) ((base) + 0x004CUL)
#define SOC_MUDP_PHY_CS_CSR20_ADDR(base) ((base) + 0x0050UL)
#define SOC_MUDP_PHY_CS_CSR21_ADDR(base) ((base) + 0x0054UL)
#define SOC_MUDP_PHY_CS_CSR22_ADDR(base) ((base) + 0x0058UL)
#define SOC_MUDP_PHY_CS_CSR23_ADDR(base) ((base) + 0x005CUL)
#define SOC_MUDP_PHY_CS_CSR24_ADDR(base) ((base) + 0x0060UL)
#define SOC_MUDP_PHY_CS_CSR25_ADDR(base) ((base) + 0x0064UL)
#define SOC_MUDP_PHY_CS_CSR26_ADDR(base) ((base) + 0x0068UL)
#define SOC_MUDP_PHY_CS_CSR27_ADDR(base) ((base) + 0x006CUL)
#define SOC_MUDP_PHY_CS_CSR28_ADDR(base) ((base) + 0x0070UL)
#define SOC_MUDP_PHY_CS_CSR29_ADDR(base) ((base) + 0x0074UL)
#define SOC_MUDP_PHY_CS_CSR30_ADDR(base) ((base) + 0x0078UL)
#define SOC_MUDP_PHY_CS_CSR31_ADDR(base) ((base) + 0x007CUL)
#define SOC_MUDP_PHY_CS_CSR32_ADDR(base) ((base) + 0x0080UL)
#define SOC_MUDP_PHY_CS_CSR33_ADDR(base) ((base) + 0x0084UL)
#define SOC_MUDP_PHY_CS_CSR34_ADDR(base) ((base) + 0x0088UL)
#define SOC_MUDP_PHY_CS_CSR35_ADDR(base) ((base) + 0x008CUL)
#define SOC_MUDP_PHY_CS_CSR36_ADDR(base) ((base) + 0x0090UL)
#define SOC_MUDP_PHY_CS_CSR37_ADDR(base) ((base) + 0x0094UL)
#define SOC_MUDP_PHY_CS_CSR38_ADDR(base) ((base) + 0x0098UL)
#define SOC_MUDP_PHY_CS_CSR39_ADDR(base) ((base) + 0x009CUL)
#define SOC_MUDP_PHY_CS_CSR40_ADDR(base) ((base) + 0x00A0UL)
#define SOC_MUDP_PHY_CS_CSR41_ADDR(base) ((base) + 0x00A4UL)
#define SOC_MUDP_PHY_CS_CSR42_ADDR(base) ((base) + 0x00A8UL)
#define SOC_MUDP_PHY_CS_CSR43_ADDR(base) ((base) + 0x00ACUL)
#define SOC_MUDP_PHY_CS_CSR44_ADDR(base) ((base) + 0x00B0UL)
#define SOC_MUDP_PHY_CS_CSR45_ADDR(base) ((base) + 0x00B4UL)
#define SOC_MUDP_PHY_CS_CSR46_ADDR(base) ((base) + 0x00B8UL)
#define SOC_MUDP_PHY_CS_CSR47_ADDR(base) ((base) + 0x00BCUL)
#define SOC_MUDP_PHY_CS_CSR48_ADDR(base) ((base) + 0x00C0UL)
#define SOC_MUDP_PHY_CS_CSR49_ADDR(base) ((base) + 0x00C4UL)
#define SOC_MUDP_PHY_CS_CSR50_ADDR(base) ((base) + 0x00C8UL)
#define SOC_MUDP_PHY_CS_CSR51_ADDR(base) ((base) + 0x00CCUL)
#define SOC_MUDP_PHY_CS_CSR52_ADDR(base) ((base) + 0x00D0UL)
#define SOC_MUDP_PHY_CS_CSR53_ADDR(base) ((base) + 0x00D4UL)
#define SOC_MUDP_PHY_CS_CSR54_ADDR(base) ((base) + 0x00D8UL)
#define SOC_MUDP_PHY_CS_CSR55_ADDR(base) ((base) + 0x00DCUL)
#define SOC_MUDP_PHY_CS_CSR56_ADDR(base) ((base) + 0x00E0UL)
#define SOC_MUDP_PHY_CS_CSR57_ADDR(base) ((base) + 0x00E4UL)
#define SOC_MUDP_PHY_CS_CSR58_ADDR(base) ((base) + 0x00E8UL)
#define SOC_MUDP_PHY_CS_CSR59_ADDR(base) ((base) + 0x00ECUL)
#define SOC_MUDP_PHY_CS_CSR60_ADDR(base) ((base) + 0x00F0UL)
#define SOC_MUDP_PHY_CS_CSR61_ADDR(base) ((base) + 0x00F4UL)
#define SOC_MUDP_PHY_CS_CSR62_ADDR(base) ((base) + 0x00F8UL)
#define SOC_MUDP_PHY_CS_CSR63_ADDR(base) ((base) + 0x00FCUL)
#define SOC_MUDP_PHY_CS_CSR64_ADDR(base) ((base) + 0x0100UL)
#else
#define SOC_MUDP_PHY_CS_CSR0_ADDR(base) (base)
#define SOC_MUDP_PHY_CS_CSR1_ADDR(base) ((base) + 0x0004)
#define SOC_MUDP_PHY_CS_CSR2_ADDR(base) ((base) + 0x0008)
#define SOC_MUDP_PHY_CS_CSR3_ADDR(base) ((base) + 0x000C)
#define SOC_MUDP_PHY_CS_CSR4_ADDR(base) ((base) + 0x0010)
#define SOC_MUDP_PHY_CS_CSR5_ADDR(base) ((base) + 0x0014)
#define SOC_MUDP_PHY_CS_CSR6_ADDR(base) ((base) + 0x0018)
#define SOC_MUDP_PHY_CS_CSR7_ADDR(base) ((base) + 0x001C)
#define SOC_MUDP_PHY_CS_CSR8_ADDR(base) ((base) + 0x0020)
#define SOC_MUDP_PHY_CS_CSR9_ADDR(base) ((base) + 0x0024)
#define SOC_MUDP_PHY_CS_CSR10_ADDR(base) ((base) + 0x0028)
#define SOC_MUDP_PHY_CS_CSR11_ADDR(base) ((base) + 0x002C)
#define SOC_MUDP_PHY_CS_CSR12_ADDR(base) ((base) + 0x0030)
#define SOC_MUDP_PHY_CS_CSR13_ADDR(base) ((base) + 0x0034)
#define SOC_MUDP_PHY_CS_CSR14_ADDR(base) ((base) + 0x0038)
#define SOC_MUDP_PHY_CS_CSR15_ADDR(base) ((base) + 0x003C)
#define SOC_MUDP_PHY_CS_CSR16_ADDR(base) ((base) + 0x0040)
#define SOC_MUDP_PHY_CS_CSR17_ADDR(base) ((base) + 0x0044)
#define SOC_MUDP_PHY_CS_CSR18_ADDR(base) ((base) + 0x0048)
#define SOC_MUDP_PHY_CS_CSR19_ADDR(base) ((base) + 0x004C)
#define SOC_MUDP_PHY_CS_CSR20_ADDR(base) ((base) + 0x0050)
#define SOC_MUDP_PHY_CS_CSR21_ADDR(base) ((base) + 0x0054)
#define SOC_MUDP_PHY_CS_CSR22_ADDR(base) ((base) + 0x0058)
#define SOC_MUDP_PHY_CS_CSR23_ADDR(base) ((base) + 0x005C)
#define SOC_MUDP_PHY_CS_CSR24_ADDR(base) ((base) + 0x0060)
#define SOC_MUDP_PHY_CS_CSR25_ADDR(base) ((base) + 0x0064)
#define SOC_MUDP_PHY_CS_CSR26_ADDR(base) ((base) + 0x0068)
#define SOC_MUDP_PHY_CS_CSR27_ADDR(base) ((base) + 0x006C)
#define SOC_MUDP_PHY_CS_CSR28_ADDR(base) ((base) + 0x0070)
#define SOC_MUDP_PHY_CS_CSR29_ADDR(base) ((base) + 0x0074)
#define SOC_MUDP_PHY_CS_CSR30_ADDR(base) ((base) + 0x0078)
#define SOC_MUDP_PHY_CS_CSR31_ADDR(base) ((base) + 0x007C)
#define SOC_MUDP_PHY_CS_CSR32_ADDR(base) ((base) + 0x0080)
#define SOC_MUDP_PHY_CS_CSR33_ADDR(base) ((base) + 0x0084)
#define SOC_MUDP_PHY_CS_CSR34_ADDR(base) ((base) + 0x0088)
#define SOC_MUDP_PHY_CS_CSR35_ADDR(base) ((base) + 0x008C)
#define SOC_MUDP_PHY_CS_CSR36_ADDR(base) ((base) + 0x0090)
#define SOC_MUDP_PHY_CS_CSR37_ADDR(base) ((base) + 0x0094)
#define SOC_MUDP_PHY_CS_CSR38_ADDR(base) ((base) + 0x0098)
#define SOC_MUDP_PHY_CS_CSR39_ADDR(base) ((base) + 0x009C)
#define SOC_MUDP_PHY_CS_CSR40_ADDR(base) ((base) + 0x00A0)
#define SOC_MUDP_PHY_CS_CSR41_ADDR(base) ((base) + 0x00A4)
#define SOC_MUDP_PHY_CS_CSR42_ADDR(base) ((base) + 0x00A8)
#define SOC_MUDP_PHY_CS_CSR43_ADDR(base) ((base) + 0x00AC)
#define SOC_MUDP_PHY_CS_CSR44_ADDR(base) ((base) + 0x00B0)
#define SOC_MUDP_PHY_CS_CSR45_ADDR(base) ((base) + 0x00B4)
#define SOC_MUDP_PHY_CS_CSR46_ADDR(base) ((base) + 0x00B8)
#define SOC_MUDP_PHY_CS_CSR47_ADDR(base) ((base) + 0x00BC)
#define SOC_MUDP_PHY_CS_CSR48_ADDR(base) ((base) + 0x00C0)
#define SOC_MUDP_PHY_CS_CSR49_ADDR(base) ((base) + 0x00C4)
#define SOC_MUDP_PHY_CS_CSR50_ADDR(base) ((base) + 0x00C8)
#define SOC_MUDP_PHY_CS_CSR51_ADDR(base) ((base) + 0x00CC)
#define SOC_MUDP_PHY_CS_CSR52_ADDR(base) ((base) + 0x00D0)
#define SOC_MUDP_PHY_CS_CSR53_ADDR(base) ((base) + 0x00D4)
#define SOC_MUDP_PHY_CS_CSR54_ADDR(base) ((base) + 0x00D8)
#define SOC_MUDP_PHY_CS_CSR55_ADDR(base) ((base) + 0x00DC)
#define SOC_MUDP_PHY_CS_CSR56_ADDR(base) ((base) + 0x00E0)
#define SOC_MUDP_PHY_CS_CSR57_ADDR(base) ((base) + 0x00E4)
#define SOC_MUDP_PHY_CS_CSR58_ADDR(base) ((base) + 0x00E8)
#define SOC_MUDP_PHY_CS_CSR59_ADDR(base) ((base) + 0x00EC)
#define SOC_MUDP_PHY_CS_CSR60_ADDR(base) ((base) + 0x00F0)
#define SOC_MUDP_PHY_CS_CSR61_ADDR(base) ((base) + 0x00F4)
#define SOC_MUDP_PHY_CS_CSR62_ADDR(base) ((base) + 0x00F8)
#define SOC_MUDP_PHY_CS_CSR63_ADDR(base) ((base) + 0x00FC)
#define SOC_MUDP_PHY_CS_CSR64_ADDR(base) ((base) + 0x0100)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_PHY_TX_CSR0_ADDR(base,RX_ID) (base)
#define SOC_MUDP_PHY_TX_CSR1_ADDR(base,RX_ID) ((base) + 0x0004UL)
#define SOC_MUDP_PHY_TX_CSR2_ADDR(base,RX_ID) ((base) + 0x0008UL)
#define SOC_MUDP_PHY_TX_CSR3_ADDR(base,RX_ID) ((base) + 0x000CUL)
#define SOC_MUDP_PHY_TX_CSR4_ADDR(base,RX_ID) ((base) + 0x0010UL)
#define SOC_MUDP_PHY_TX_CSR5_ADDR(base,RX_ID) ((base) + 0x0014UL)
#define SOC_MUDP_PHY_TX_CSR6_ADDR(base,RX_ID) ((base) + 0x0018UL)
#define SOC_MUDP_PHY_TX_CSR7_ADDR(base,RX_ID) ((base) + 0x001CUL)
#define SOC_MUDP_PHY_TX_CSR8_ADDR(base,RX_ID) ((base) + 0x0020UL)
#define SOC_MUDP_PHY_TX_CSR9_ADDR(base,RX_ID) ((base) + 0x0024UL)
#define SOC_MUDP_PHY_TX_CSR10_ADDR(base,RX_ID) ((base) + 0x0028UL)
#define SOC_MUDP_PHY_TX_CSR11_ADDR(base,RX_ID) ((base) + 0x002CUL)
#define SOC_MUDP_PHY_TX_CSR12_ADDR(base,RX_ID) ((base) + 0x0030UL)
#define SOC_MUDP_PHY_TX_CSR13_ADDR(base,RX_ID) ((base) + 0x0034UL)
#define SOC_MUDP_PHY_TX_CSR14_ADDR(base,RX_ID) ((base) + 0x0038UL)
#define SOC_MUDP_PHY_TX_CSR15_ADDR(base,RX_ID) ((base) + 0x003CUL)
#define SOC_MUDP_PHY_TX_CSR16_ADDR(base,RX_ID) ((base) + 0x0040UL)
#define SOC_MUDP_PHY_TX_CSR17_ADDR(base,RX_ID) ((base) + 0x0044UL)
#define SOC_MUDP_PHY_TX_CSR18_ADDR(base,RX_ID) ((base) + 0x0048UL)
#define SOC_MUDP_PHY_TX_CSR19_ADDR(base,RX_ID) ((base) + 0x004CUL)
#define SOC_MUDP_PHY_TX_CSR24_ADDR(base,RX_ID) ((base) + 0x0050UL)
#define SOC_MUDP_PHY_TX_CSR25_ADDR(base,RX_ID) ((base) + 0x0054UL)
#define SOC_MUDP_PHY_TX_CSR26_ADDR(base,RX_ID) ((base) + 0x0058UL)
#define SOC_MUDP_PHY_TX_CSR27_ADDR(base,RX_ID) ((base) + 0x005CUL)
#define SOC_MUDP_PHY_TX_CSR28_ADDR(base,RX_ID) ((base) + 0x0060UL)
#define SOC_MUDP_PHY_TX_CSR29_ADDR(base,RX_ID) ((base) + 0x0064UL)
#define SOC_MUDP_PHY_TX_CSR30_ADDR(base,RX_ID) ((base) + 0x0068UL)
#define SOC_MUDP_PHY_TX_CSR31_ADDR(base,RX_ID) ((base) + 0x006CUL)
#define SOC_MUDP_PHY_TX_CSR32_ADDR(base,RX_ID) ((base) + 0x0070UL)
#define SOC_MUDP_PHY_TX_CSR33_ADDR(base,RX_ID) ((base) + 0x0074UL)
#define SOC_MUDP_PHY_TX_CSR34_ADDR(base,RX_ID) ((base) + 0x0078UL)
#define SOC_MUDP_PHY_TX_CSR35_ADDR(base,RX_ID) ((base) + 0x007CUL)
#define SOC_MUDP_PHY_TX_CSR36_ADDR(base,RX_ID) ((base) + 0x0080UL)
#define SOC_MUDP_PHY_TX_CSR37_ADDR(base,RX_ID) ((base) + 0x0084UL)
#define SOC_MUDP_PHY_TX_CSR38_ADDR(base,RX_ID) ((base) + 0x0088UL)
#define SOC_MUDP_PHY_TX_CSR39_ADDR(base,RX_ID) ((base) + 0x008CUL)
#define SOC_MUDP_PHY_TX_CSR40_ADDR(base,RX_ID) ((base) + 0x0090UL)
#define SOC_MUDP_PHY_TX_CSR41_ADDR(base,RX_ID) ((base) + 0x0094UL)
#define SOC_MUDP_PHY_TX_CSR42_ADDR(base,RX_ID) ((base) + 0x0098UL)
#define SOC_MUDP_PHY_TX_CSR43_ADDR(base,RX_ID) ((base) + 0x009CUL)
#define SOC_MUDP_PHY_TX_CSR44_ADDR(base,RX_ID) ((base) + 0x00A0UL)
#define SOC_MUDP_PHY_TX_CSR45_ADDR(base,RX_ID) ((base) + 0x00A4UL)
#define SOC_MUDP_PHY_TX_CSR46_ADDR(base,RX_ID) ((base) + 0x00A8UL)
#define SOC_MUDP_PHY_TX_CSR47_ADDR(base,RX_ID) ((base) + 0x00ACUL)
#define SOC_MUDP_PHY_TX_CSR48_ADDR(base,RX_ID) ((base) + 0x00B0UL)
#define SOC_MUDP_PHY_TX_CSR49_ADDR(base,RX_ID) ((base) + 0x00B4UL)
#define SOC_MUDP_PHY_TX_CSR50_ADDR(base,RX_ID) ((base) + 0x00B8UL)
#define SOC_MUDP_PHY_TX_CSR51_ADDR(base,RX_ID) ((base) + 0x00BCUL)
#define SOC_MUDP_PHY_TX_CSR52_ADDR(base,RX_ID) ((base) + 0x00C0UL)
#define SOC_MUDP_PHY_TX_CSR53_ADDR(base,RX_ID) ((base) + 0x00C4UL)
#define SOC_MUDP_PHY_TX_CSR54_ADDR(base,RX_ID) ((base) + 0x00C8UL)
#define SOC_MUDP_PHY_TX_CSR55_ADDR(base,RX_ID) ((base) + 0x00CCUL)
#define SOC_MUDP_PHY_TX_CSR56_ADDR(base,RX_ID) ((base) + 0x00D0UL)
#define SOC_MUDP_PHY_TX_CSR57_ADDR(base,RX_ID) ((base) + 0x00D4UL)
#define SOC_MUDP_PHY_TX_CSR58_ADDR(base,RX_ID) ((base) + 0x00D8UL)
#define SOC_MUDP_PHY_TX_CSR59_ADDR(base,RX_ID) ((base) + 0x00DCUL)
#else
#define SOC_MUDP_PHY_TX_CSR0_ADDR(base,RX_ID) (base)
#define SOC_MUDP_PHY_TX_CSR1_ADDR(base,RX_ID) ((base) + 0x0004)
#define SOC_MUDP_PHY_TX_CSR2_ADDR(base,RX_ID) ((base) + 0x0008)
#define SOC_MUDP_PHY_TX_CSR3_ADDR(base,RX_ID) ((base) + 0x000C)
#define SOC_MUDP_PHY_TX_CSR4_ADDR(base,RX_ID) ((base) + 0x0010)
#define SOC_MUDP_PHY_TX_CSR5_ADDR(base,RX_ID) ((base) + 0x0014)
#define SOC_MUDP_PHY_TX_CSR6_ADDR(base,RX_ID) ((base) + 0x0018)
#define SOC_MUDP_PHY_TX_CSR7_ADDR(base,RX_ID) ((base) + 0x001C)
#define SOC_MUDP_PHY_TX_CSR8_ADDR(base,RX_ID) ((base) + 0x0020)
#define SOC_MUDP_PHY_TX_CSR9_ADDR(base,RX_ID) ((base) + 0x0024)
#define SOC_MUDP_PHY_TX_CSR10_ADDR(base,RX_ID) ((base) + 0x0028)
#define SOC_MUDP_PHY_TX_CSR11_ADDR(base,RX_ID) ((base) + 0x002C)
#define SOC_MUDP_PHY_TX_CSR12_ADDR(base,RX_ID) ((base) + 0x0030)
#define SOC_MUDP_PHY_TX_CSR13_ADDR(base,RX_ID) ((base) + 0x0034)
#define SOC_MUDP_PHY_TX_CSR14_ADDR(base,RX_ID) ((base) + 0x0038)
#define SOC_MUDP_PHY_TX_CSR15_ADDR(base,RX_ID) ((base) + 0x003C)
#define SOC_MUDP_PHY_TX_CSR16_ADDR(base,RX_ID) ((base) + 0x0040)
#define SOC_MUDP_PHY_TX_CSR17_ADDR(base,RX_ID) ((base) + 0x0044)
#define SOC_MUDP_PHY_TX_CSR18_ADDR(base,RX_ID) ((base) + 0x0048)
#define SOC_MUDP_PHY_TX_CSR19_ADDR(base,RX_ID) ((base) + 0x004C)
#define SOC_MUDP_PHY_TX_CSR24_ADDR(base,RX_ID) ((base) + 0x0050)
#define SOC_MUDP_PHY_TX_CSR25_ADDR(base,RX_ID) ((base) + 0x0054)
#define SOC_MUDP_PHY_TX_CSR26_ADDR(base,RX_ID) ((base) + 0x0058)
#define SOC_MUDP_PHY_TX_CSR27_ADDR(base,RX_ID) ((base) + 0x005C)
#define SOC_MUDP_PHY_TX_CSR28_ADDR(base,RX_ID) ((base) + 0x0060)
#define SOC_MUDP_PHY_TX_CSR29_ADDR(base,RX_ID) ((base) + 0x0064)
#define SOC_MUDP_PHY_TX_CSR30_ADDR(base,RX_ID) ((base) + 0x0068)
#define SOC_MUDP_PHY_TX_CSR31_ADDR(base,RX_ID) ((base) + 0x006C)
#define SOC_MUDP_PHY_TX_CSR32_ADDR(base,RX_ID) ((base) + 0x0070)
#define SOC_MUDP_PHY_TX_CSR33_ADDR(base,RX_ID) ((base) + 0x0074)
#define SOC_MUDP_PHY_TX_CSR34_ADDR(base,RX_ID) ((base) + 0x0078)
#define SOC_MUDP_PHY_TX_CSR35_ADDR(base,RX_ID) ((base) + 0x007C)
#define SOC_MUDP_PHY_TX_CSR36_ADDR(base,RX_ID) ((base) + 0x0080)
#define SOC_MUDP_PHY_TX_CSR37_ADDR(base,RX_ID) ((base) + 0x0084)
#define SOC_MUDP_PHY_TX_CSR38_ADDR(base,RX_ID) ((base) + 0x0088)
#define SOC_MUDP_PHY_TX_CSR39_ADDR(base,RX_ID) ((base) + 0x008C)
#define SOC_MUDP_PHY_TX_CSR40_ADDR(base,RX_ID) ((base) + 0x0090)
#define SOC_MUDP_PHY_TX_CSR41_ADDR(base,RX_ID) ((base) + 0x0094)
#define SOC_MUDP_PHY_TX_CSR42_ADDR(base,RX_ID) ((base) + 0x0098)
#define SOC_MUDP_PHY_TX_CSR43_ADDR(base,RX_ID) ((base) + 0x009C)
#define SOC_MUDP_PHY_TX_CSR44_ADDR(base,RX_ID) ((base) + 0x00A0)
#define SOC_MUDP_PHY_TX_CSR45_ADDR(base,RX_ID) ((base) + 0x00A4)
#define SOC_MUDP_PHY_TX_CSR46_ADDR(base,RX_ID) ((base) + 0x00A8)
#define SOC_MUDP_PHY_TX_CSR47_ADDR(base,RX_ID) ((base) + 0x00AC)
#define SOC_MUDP_PHY_TX_CSR48_ADDR(base,RX_ID) ((base) + 0x00B0)
#define SOC_MUDP_PHY_TX_CSR49_ADDR(base,RX_ID) ((base) + 0x00B4)
#define SOC_MUDP_PHY_TX_CSR50_ADDR(base,RX_ID) ((base) + 0x00B8)
#define SOC_MUDP_PHY_TX_CSR51_ADDR(base,RX_ID) ((base) + 0x00BC)
#define SOC_MUDP_PHY_TX_CSR52_ADDR(base,RX_ID) ((base) + 0x00C0)
#define SOC_MUDP_PHY_TX_CSR53_ADDR(base,RX_ID) ((base) + 0x00C4)
#define SOC_MUDP_PHY_TX_CSR54_ADDR(base,RX_ID) ((base) + 0x00C8)
#define SOC_MUDP_PHY_TX_CSR55_ADDR(base,RX_ID) ((base) + 0x00CC)
#define SOC_MUDP_PHY_TX_CSR56_ADDR(base,RX_ID) ((base) + 0x00D0)
#define SOC_MUDP_PHY_TX_CSR57_ADDR(base,RX_ID) ((base) + 0x00D4)
#define SOC_MUDP_PHY_TX_CSR58_ADDR(base,RX_ID) ((base) + 0x00D8)
#define SOC_MUDP_PHY_TX_CSR59_ADDR(base,RX_ID) ((base) + 0x00DC)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_PHY_RX_CSR0_ADDR(base,RX_ID) (base)
#define SOC_MUDP_PHY_RX_CSR1_ADDR(base,RX_ID) ((base) + 0x0004UL)
#define SOC_MUDP_PHY_RX_CSR2_ADDR(base,RX_ID) ((base) + 0x0008UL)
#define SOC_MUDP_PHY_RX_CSR3_ADDR(base,RX_ID) ((base) + 0x000CUL)
#define SOC_MUDP_PHY_RX_CSR4_ADDR(base,RX_ID) ((base) + 0x0010UL)
#define SOC_MUDP_PHY_RX_CSR5_ADDR(base,RX_ID) ((base) + 0x0014UL)
#define SOC_MUDP_PHY_RX_CSR6_ADDR(base,RX_ID) ((base) + 0x0018UL)
#define SOC_MUDP_PHY_RX_CSR7_ADDR(base,RX_ID) ((base) + 0x001CUL)
#define SOC_MUDP_PHY_RX_CSR8_ADDR(base,RX_ID) ((base) + 0x0020UL)
#define SOC_MUDP_PHY_RX_CSR9_ADDR(base,RX_ID) ((base) + 0x0024UL)
#define SOC_MUDP_PHY_RX_CSR10_ADDR(base,RX_ID) ((base) + 0x0028UL)
#define SOC_MUDP_PHY_RX_CSR11_ADDR(base,RX_ID) ((base) + 0x002CUL)
#define SOC_MUDP_PHY_RX_CSR12_ADDR(base,RX_ID) ((base) + 0x0030UL)
#define SOC_MUDP_PHY_RX_CSR13_ADDR(base,RX_ID) ((base) + 0x0034UL)
#define SOC_MUDP_PHY_RX_CSR14_ADDR(base,RX_ID) ((base) + 0x0038UL)
#define SOC_MUDP_PHY_RX_CSR15_ADDR(base,RX_ID) ((base) + 0x003CUL)
#define SOC_MUDP_PHY_RX_CSR16_ADDR(base,RX_ID) ((base) + 0x0040UL)
#define SOC_MUDP_PHY_RX_CSR17_ADDR(base,RX_ID) ((base) + 0x0044UL)
#define SOC_MUDP_PHY_RX_CSR18_ADDR(base,RX_ID) ((base) + 0x0048UL)
#define SOC_MUDP_PHY_RX_CSR19_ADDR(base,RX_ID) ((base) + 0x004CUL)
#define SOC_MUDP_PHY_RX_CSR20_ADDR(base,RX_ID) ((base) + 0x0050UL)
#define SOC_MUDP_PHY_RX_CSR21_ADDR(base,RX_ID) ((base) + 0x0054UL)
#define SOC_MUDP_PHY_RX_CSR22_ADDR(base,RX_ID) ((base) + 0x0058UL)
#define SOC_MUDP_PHY_RX_CSR23_ADDR(base,RX_ID) ((base) + 0x005CUL)
#define SOC_MUDP_PHY_RX_CSR24_ADDR(base,RX_ID) ((base) + 0x0060UL)
#define SOC_MUDP_PHY_RX_CSR25_ADDR(base,RX_ID) ((base) + 0x0064UL)
#define SOC_MUDP_PHY_RX_CSR26_ADDR(base,RX_ID) ((base) + 0x0068UL)
#define SOC_MUDP_PHY_RX_CSR27_ADDR(base,RX_ID) ((base) + 0x006CUL)
#define SOC_MUDP_PHY_RX_CSR28_ADDR(base,RX_ID) ((base) + 0x0070UL)
#define SOC_MUDP_PHY_RX_CSR29_ADDR(base,RX_ID) ((base) + 0x0074UL)
#define SOC_MUDP_PHY_RX_CSR30_ADDR(base,RX_ID) ((base) + 0x0078UL)
#define SOC_MUDP_PHY_RX_CSR31_ADDR(base,RX_ID) ((base) + 0x007CUL)
#define SOC_MUDP_PHY_RX_CSR32_ADDR(base,RX_ID) ((base) + 0x0080UL)
#define SOC_MUDP_PHY_RX_CSR33_ADDR(base,RX_ID) ((base) + 0x0084UL)
#define SOC_MUDP_PHY_RX_CSR34_ADDR(base,RX_ID) ((base) + 0x0088UL)
#define SOC_MUDP_PHY_RX_CSR35_ADDR(base,RX_ID) ((base) + 0x008CUL)
#define SOC_MUDP_PHY_RX_CSR36_ADDR(base,RX_ID) ((base) + 0x0090UL)
#define SOC_MUDP_PHY_RX_CSR37_ADDR(base,RX_ID) ((base) + 0x0094UL)
#define SOC_MUDP_PHY_RX_CSR38_ADDR(base,RX_ID) ((base) + 0x0098UL)
#define SOC_MUDP_PHY_RX_CSR39_ADDR(base,RX_ID) ((base) + 0x009CUL)
#define SOC_MUDP_PHY_RX_CSR40_ADDR(base,RX_ID) ((base) + 0x00A0UL)
#define SOC_MUDP_PHY_RX_CSR41_ADDR(base,RX_ID) ((base) + 0x00A4UL)
#define SOC_MUDP_PHY_RX_CSR42_ADDR(base,RX_ID) ((base) + 0x00A8UL)
#define SOC_MUDP_PHY_RX_CSR43_ADDR(base,RX_ID) ((base) + 0x00ACUL)
#define SOC_MUDP_PHY_RX_CSR44_ADDR(base,RX_ID) ((base) + 0x00B0UL)
#define SOC_MUDP_PHY_RX_CSR45_ADDR(base,RX_ID) ((base) + 0x00B4UL)
#define SOC_MUDP_PHY_RX_CSR46_ADDR(base,RX_ID) ((base) + 0x00B8UL)
#define SOC_MUDP_PHY_RX_CSR47_ADDR(base,RX_ID) ((base) + 0x00BCUL)
#define SOC_MUDP_PHY_RX_CSR48_ADDR(base,RX_ID) ((base) + 0x00C0UL)
#define SOC_MUDP_PHY_RX_CSR49_ADDR(base,RX_ID) ((base) + 0x00C4UL)
#define SOC_MUDP_PHY_RX_CSR50_ADDR(base,RX_ID) ((base) + 0x00C8UL)
#define SOC_MUDP_PHY_RX_CSR51_ADDR(base,RX_ID) ((base) + 0x00CCUL)
#define SOC_MUDP_PHY_RX_CSR52_ADDR(base,RX_ID) ((base) + 0x00D0UL)
#define SOC_MUDP_PHY_RX_CSR53_ADDR(base,RX_ID) ((base) + 0x00D4UL)
#define SOC_MUDP_PHY_RX_CSR54_ADDR(base,RX_ID) ((base) + 0x00D8UL)
#define SOC_MUDP_PHY_RX_CSR55_ADDR(base,RX_ID) ((base) + 0x00DCUL)
#define SOC_MUDP_PHY_RX_CSR56_ADDR(base,RX_ID) ((base) + 0x00E0UL)
#define SOC_MUDP_PHY_RX_CSR57_ADDR(base,RX_ID) ((base) + 0x00E4UL)
#define SOC_MUDP_PHY_RX_CSR58_ADDR(base,RX_ID) ((base) + 0x00E8UL)
#define SOC_MUDP_PHY_RX_CSR59_ADDR(base,RX_ID) ((base) + 0x00ECUL)
#define SOC_MUDP_PHY_RX_CSR60_ADDR(base,RX_ID) ((base) + 0x00F0UL)
#define SOC_MUDP_PHY_RX_CSR61_ADDR(base,RX_ID) ((base) + 0x00F4UL)
#define SOC_MUDP_PHY_RX_CSR62_ADDR(base,RX_ID) ((base) + 0x00F8UL)
#define SOC_MUDP_PHY_RX_CSR63_ADDR(base,RX_ID) ((base) + 0x00FCUL)
#define SOC_MUDP_PHY_RX_CSR64_ADDR(base,RX_ID) ((base) + 0x0100UL)
#define SOC_MUDP_PHY_RX_CSR65_ADDR(base,RX_ID) ((base) + 0x0104UL)
#define SOC_MUDP_PHY_RX_CSR66_ADDR(base,RX_ID) ((base) + 0x0108UL)
#define SOC_MUDP_PHY_RX_CSR67_ADDR(base,RX_ID) ((base) + 0x010CUL)
#define SOC_MUDP_PHY_RX_CSR68_ADDR(base,RX_ID) ((base) + 0x0110UL)
#define SOC_MUDP_PHY_RX_CSR69_ADDR(base,RX_ID) ((base) + 0x0114UL)
#define SOC_MUDP_PHY_RX_CSR70_ADDR(base,RX_ID) ((base) + 0x0118UL)
#define SOC_MUDP_PHY_RX_CSR71_ADDR(base,RX_ID) ((base) + 0x011CUL)
#define SOC_MUDP_PHY_RX_CSR72_ADDR(base,RX_ID) ((base) + 0x0120UL)
#define SOC_MUDP_PHY_RX_CSR73_ADDR(base,RX_ID) ((base) + 0x0124UL)
#define SOC_MUDP_PHY_RX_CSR74_ADDR(base,RX_ID) ((base) + 0x0128UL)
#define SOC_MUDP_PHY_RX_CSR75_ADDR(base,RX_ID) ((base) + 0x012CUL)
#define SOC_MUDP_PHY_RX_CSR76_ADDR(base,RX_ID) ((base) + 0x0130UL)
#define SOC_MUDP_PHY_RX_CSR77_ADDR(base,RX_ID) ((base) + 0x0134UL)
#define SOC_MUDP_PHY_RX_CSR78_ADDR(base,RX_ID) ((base) + 0x0138UL)
#define SOC_MUDP_PHY_RX_CSR79_ADDR(base,RX_ID) ((base) + 0x013CUL)
#define SOC_MUDP_PHY_RX_CSR80_ADDR(base,RX_ID) ((base) + 0x0140UL)
#define SOC_MUDP_PHY_RX_CSR81_ADDR(base,RX_ID) ((base) + 0x0144UL)
#define SOC_MUDP_PHY_RX_CSR82_ADDR(base,RX_ID) ((base) + 0x0148UL)
#define SOC_MUDP_PHY_RX_CSR83_ADDR(base,RX_ID) ((base) + 0x014CUL)
#define SOC_MUDP_PHY_RX_CSR84_ADDR(base,RX_ID) ((base) + 0x0150UL)
#define SOC_MUDP_PHY_RX_CSR85_ADDR(base,RX_ID) ((base) + 0x0154UL)
#define SOC_MUDP_PHY_RX_CSR86_ADDR(base,RX_ID) ((base) + 0x0158UL)
#define SOC_MUDP_PHY_RX_CSR87_ADDR(base,RX_ID) ((base) + 0x015CUL)
#define SOC_MUDP_PHY_RX_CSR88_ADDR(base,RX_ID) ((base) + 0x0160UL)
#define SOC_MUDP_PHY_RX_CSR89_ADDR(base,RX_ID) ((base) + 0x0164UL)
#define SOC_MUDP_PHY_RX_CSR90_ADDR(base,RX_ID) ((base) + 0x0168UL)
#define SOC_MUDP_PHY_RX_CSR91_ADDR(base,RX_ID) ((base) + 0x016CUL)
#define SOC_MUDP_PHY_RX_CSR92_ADDR(base,RX_ID) ((base) + 0x0170UL)
#define SOC_MUDP_PHY_RX_CSR93_ADDR(base,RX_ID) ((base) + 0x0174UL)
#define SOC_MUDP_PHY_RX_CSR94_ADDR(base,RX_ID) ((base) + 0x0178UL)
#else
#define SOC_MUDP_PHY_RX_CSR0_ADDR(base,RX_ID) (base)
#define SOC_MUDP_PHY_RX_CSR1_ADDR(base,RX_ID) ((base) + 0x0004)
#define SOC_MUDP_PHY_RX_CSR2_ADDR(base,RX_ID) ((base) + 0x0008)
#define SOC_MUDP_PHY_RX_CSR3_ADDR(base,RX_ID) ((base) + 0x000C)
#define SOC_MUDP_PHY_RX_CSR4_ADDR(base,RX_ID) ((base) + 0x0010)
#define SOC_MUDP_PHY_RX_CSR5_ADDR(base,RX_ID) ((base) + 0x0014)
#define SOC_MUDP_PHY_RX_CSR6_ADDR(base,RX_ID) ((base) + 0x0018)
#define SOC_MUDP_PHY_RX_CSR7_ADDR(base,RX_ID) ((base) + 0x001C)
#define SOC_MUDP_PHY_RX_CSR8_ADDR(base,RX_ID) ((base) + 0x0020)
#define SOC_MUDP_PHY_RX_CSR9_ADDR(base,RX_ID) ((base) + 0x0024)
#define SOC_MUDP_PHY_RX_CSR10_ADDR(base,RX_ID) ((base) + 0x0028)
#define SOC_MUDP_PHY_RX_CSR11_ADDR(base,RX_ID) ((base) + 0x002C)
#define SOC_MUDP_PHY_RX_CSR12_ADDR(base,RX_ID) ((base) + 0x0030)
#define SOC_MUDP_PHY_RX_CSR13_ADDR(base,RX_ID) ((base) + 0x0034)
#define SOC_MUDP_PHY_RX_CSR14_ADDR(base,RX_ID) ((base) + 0x0038)
#define SOC_MUDP_PHY_RX_CSR15_ADDR(base,RX_ID) ((base) + 0x003C)
#define SOC_MUDP_PHY_RX_CSR16_ADDR(base,RX_ID) ((base) + 0x0040)
#define SOC_MUDP_PHY_RX_CSR17_ADDR(base,RX_ID) ((base) + 0x0044)
#define SOC_MUDP_PHY_RX_CSR18_ADDR(base,RX_ID) ((base) + 0x0048)
#define SOC_MUDP_PHY_RX_CSR19_ADDR(base,RX_ID) ((base) + 0x004C)
#define SOC_MUDP_PHY_RX_CSR20_ADDR(base,RX_ID) ((base) + 0x0050)
#define SOC_MUDP_PHY_RX_CSR21_ADDR(base,RX_ID) ((base) + 0x0054)
#define SOC_MUDP_PHY_RX_CSR22_ADDR(base,RX_ID) ((base) + 0x0058)
#define SOC_MUDP_PHY_RX_CSR23_ADDR(base,RX_ID) ((base) + 0x005C)
#define SOC_MUDP_PHY_RX_CSR24_ADDR(base,RX_ID) ((base) + 0x0060)
#define SOC_MUDP_PHY_RX_CSR25_ADDR(base,RX_ID) ((base) + 0x0064)
#define SOC_MUDP_PHY_RX_CSR26_ADDR(base,RX_ID) ((base) + 0x0068)
#define SOC_MUDP_PHY_RX_CSR27_ADDR(base,RX_ID) ((base) + 0x006C)
#define SOC_MUDP_PHY_RX_CSR28_ADDR(base,RX_ID) ((base) + 0x0070)
#define SOC_MUDP_PHY_RX_CSR29_ADDR(base,RX_ID) ((base) + 0x0074)
#define SOC_MUDP_PHY_RX_CSR30_ADDR(base,RX_ID) ((base) + 0x0078)
#define SOC_MUDP_PHY_RX_CSR31_ADDR(base,RX_ID) ((base) + 0x007C)
#define SOC_MUDP_PHY_RX_CSR32_ADDR(base,RX_ID) ((base) + 0x0080)
#define SOC_MUDP_PHY_RX_CSR33_ADDR(base,RX_ID) ((base) + 0x0084)
#define SOC_MUDP_PHY_RX_CSR34_ADDR(base,RX_ID) ((base) + 0x0088)
#define SOC_MUDP_PHY_RX_CSR35_ADDR(base,RX_ID) ((base) + 0x008C)
#define SOC_MUDP_PHY_RX_CSR36_ADDR(base,RX_ID) ((base) + 0x0090)
#define SOC_MUDP_PHY_RX_CSR37_ADDR(base,RX_ID) ((base) + 0x0094)
#define SOC_MUDP_PHY_RX_CSR38_ADDR(base,RX_ID) ((base) + 0x0098)
#define SOC_MUDP_PHY_RX_CSR39_ADDR(base,RX_ID) ((base) + 0x009C)
#define SOC_MUDP_PHY_RX_CSR40_ADDR(base,RX_ID) ((base) + 0x00A0)
#define SOC_MUDP_PHY_RX_CSR41_ADDR(base,RX_ID) ((base) + 0x00A4)
#define SOC_MUDP_PHY_RX_CSR42_ADDR(base,RX_ID) ((base) + 0x00A8)
#define SOC_MUDP_PHY_RX_CSR43_ADDR(base,RX_ID) ((base) + 0x00AC)
#define SOC_MUDP_PHY_RX_CSR44_ADDR(base,RX_ID) ((base) + 0x00B0)
#define SOC_MUDP_PHY_RX_CSR45_ADDR(base,RX_ID) ((base) + 0x00B4)
#define SOC_MUDP_PHY_RX_CSR46_ADDR(base,RX_ID) ((base) + 0x00B8)
#define SOC_MUDP_PHY_RX_CSR47_ADDR(base,RX_ID) ((base) + 0x00BC)
#define SOC_MUDP_PHY_RX_CSR48_ADDR(base,RX_ID) ((base) + 0x00C0)
#define SOC_MUDP_PHY_RX_CSR49_ADDR(base,RX_ID) ((base) + 0x00C4)
#define SOC_MUDP_PHY_RX_CSR50_ADDR(base,RX_ID) ((base) + 0x00C8)
#define SOC_MUDP_PHY_RX_CSR51_ADDR(base,RX_ID) ((base) + 0x00CC)
#define SOC_MUDP_PHY_RX_CSR52_ADDR(base,RX_ID) ((base) + 0x00D0)
#define SOC_MUDP_PHY_RX_CSR53_ADDR(base,RX_ID) ((base) + 0x00D4)
#define SOC_MUDP_PHY_RX_CSR54_ADDR(base,RX_ID) ((base) + 0x00D8)
#define SOC_MUDP_PHY_RX_CSR55_ADDR(base,RX_ID) ((base) + 0x00DC)
#define SOC_MUDP_PHY_RX_CSR56_ADDR(base,RX_ID) ((base) + 0x00E0)
#define SOC_MUDP_PHY_RX_CSR57_ADDR(base,RX_ID) ((base) + 0x00E4)
#define SOC_MUDP_PHY_RX_CSR58_ADDR(base,RX_ID) ((base) + 0x00E8)
#define SOC_MUDP_PHY_RX_CSR59_ADDR(base,RX_ID) ((base) + 0x00EC)
#define SOC_MUDP_PHY_RX_CSR60_ADDR(base,RX_ID) ((base) + 0x00F0)
#define SOC_MUDP_PHY_RX_CSR61_ADDR(base,RX_ID) ((base) + 0x00F4)
#define SOC_MUDP_PHY_RX_CSR62_ADDR(base,RX_ID) ((base) + 0x00F8)
#define SOC_MUDP_PHY_RX_CSR63_ADDR(base,RX_ID) ((base) + 0x00FC)
#define SOC_MUDP_PHY_RX_CSR64_ADDR(base,RX_ID) ((base) + 0x0100)
#define SOC_MUDP_PHY_RX_CSR65_ADDR(base,RX_ID) ((base) + 0x0104)
#define SOC_MUDP_PHY_RX_CSR66_ADDR(base,RX_ID) ((base) + 0x0108)
#define SOC_MUDP_PHY_RX_CSR67_ADDR(base,RX_ID) ((base) + 0x010C)
#define SOC_MUDP_PHY_RX_CSR68_ADDR(base,RX_ID) ((base) + 0x0110)
#define SOC_MUDP_PHY_RX_CSR69_ADDR(base,RX_ID) ((base) + 0x0114)
#define SOC_MUDP_PHY_RX_CSR70_ADDR(base,RX_ID) ((base) + 0x0118)
#define SOC_MUDP_PHY_RX_CSR71_ADDR(base,RX_ID) ((base) + 0x011C)
#define SOC_MUDP_PHY_RX_CSR72_ADDR(base,RX_ID) ((base) + 0x0120)
#define SOC_MUDP_PHY_RX_CSR73_ADDR(base,RX_ID) ((base) + 0x0124)
#define SOC_MUDP_PHY_RX_CSR74_ADDR(base,RX_ID) ((base) + 0x0128)
#define SOC_MUDP_PHY_RX_CSR75_ADDR(base,RX_ID) ((base) + 0x012C)
#define SOC_MUDP_PHY_RX_CSR76_ADDR(base,RX_ID) ((base) + 0x0130)
#define SOC_MUDP_PHY_RX_CSR77_ADDR(base,RX_ID) ((base) + 0x0134)
#define SOC_MUDP_PHY_RX_CSR78_ADDR(base,RX_ID) ((base) + 0x0138)
#define SOC_MUDP_PHY_RX_CSR79_ADDR(base,RX_ID) ((base) + 0x013C)
#define SOC_MUDP_PHY_RX_CSR80_ADDR(base,RX_ID) ((base) + 0x0140)
#define SOC_MUDP_PHY_RX_CSR81_ADDR(base,RX_ID) ((base) + 0x0144)
#define SOC_MUDP_PHY_RX_CSR82_ADDR(base,RX_ID) ((base) + 0x0148)
#define SOC_MUDP_PHY_RX_CSR83_ADDR(base,RX_ID) ((base) + 0x014C)
#define SOC_MUDP_PHY_RX_CSR84_ADDR(base,RX_ID) ((base) + 0x0150)
#define SOC_MUDP_PHY_RX_CSR85_ADDR(base,RX_ID) ((base) + 0x0154)
#define SOC_MUDP_PHY_RX_CSR86_ADDR(base,RX_ID) ((base) + 0x0158)
#define SOC_MUDP_PHY_RX_CSR87_ADDR(base,RX_ID) ((base) + 0x015C)
#define SOC_MUDP_PHY_RX_CSR88_ADDR(base,RX_ID) ((base) + 0x0160)
#define SOC_MUDP_PHY_RX_CSR89_ADDR(base,RX_ID) ((base) + 0x0164)
#define SOC_MUDP_PHY_RX_CSR90_ADDR(base,RX_ID) ((base) + 0x0168)
#define SOC_MUDP_PHY_RX_CSR91_ADDR(base,RX_ID) ((base) + 0x016C)
#define SOC_MUDP_PHY_RX_CSR92_ADDR(base,RX_ID) ((base) + 0x0170)
#define SOC_MUDP_PHY_RX_CSR93_ADDR(base,RX_ID) ((base) + 0x0174)
#define SOC_MUDP_PHY_RX_CSR94_ADDR(base,RX_ID) ((base) + 0x0178)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int macro_cpdigrev : 5;
        unsigned int macro_technode : 3;
        unsigned int macro_foundry : 2;
        unsigned int macro_type : 6;
        unsigned int macro_rate : 3;
        unsigned int serdes_type : 3;
        unsigned int dds_num : 4;
        unsigned int ss_num : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_CP_CSR0_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR0_macro_cpdigrev_START (0)
#define SOC_MUDP_PHY_CP_CSR0_macro_cpdigrev_END (4)
#define SOC_MUDP_PHY_CP_CSR0_macro_technode_START (5)
#define SOC_MUDP_PHY_CP_CSR0_macro_technode_END (7)
#define SOC_MUDP_PHY_CP_CSR0_macro_foundry_START (8)
#define SOC_MUDP_PHY_CP_CSR0_macro_foundry_END (9)
#define SOC_MUDP_PHY_CP_CSR0_macro_type_START (10)
#define SOC_MUDP_PHY_CP_CSR0_macro_type_END (15)
#define SOC_MUDP_PHY_CP_CSR0_macro_rate_START (16)
#define SOC_MUDP_PHY_CP_CSR0_macro_rate_END (18)
#define SOC_MUDP_PHY_CP_CSR0_serdes_type_START (19)
#define SOC_MUDP_PHY_CP_CSR0_serdes_type_END (21)
#define SOC_MUDP_PHY_CP_CSR0_dds_num_START (22)
#define SOC_MUDP_PHY_CP_CSR0_dds_num_END (25)
#define SOC_MUDP_PHY_CP_CSR0_ss_num_START (26)
#define SOC_MUDP_PHY_CP_CSR0_ss_num_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr1_ra : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_CP_CSR1_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR1_top_fsm_sfr1_ra_START (0)
#define SOC_MUDP_PHY_CP_CSR1_top_fsm_sfr1_ra_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr2_sp : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_CP_CSR2_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR2_top_fsm_sfr2_sp_START (0)
#define SOC_MUDP_PHY_CP_CSR2_top_fsm_sfr2_sp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr3_gp : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_CP_CSR3_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR3_top_fsm_sfr3_gp_START (0)
#define SOC_MUDP_PHY_CP_CSR3_top_fsm_sfr3_gp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr4_ap : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_CP_CSR4_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR4_top_fsm_sfr4_ap_START (0)
#define SOC_MUDP_PHY_CP_CSR4_top_fsm_sfr4_ap_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr5_vp : 22;
        unsigned int top_fsm_sram_mask : 10;
    } reg;
} SOC_MUDP_PHY_CP_CSR5_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR5_top_fsm_sfr5_vp_START (0)
#define SOC_MUDP_PHY_CP_CSR5_top_fsm_sfr5_vp_END (21)
#define SOC_MUDP_PHY_CP_CSR5_top_fsm_sram_mask_START (22)
#define SOC_MUDP_PHY_CP_CSR5_top_fsm_sram_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr6_rp0 : 22;
        unsigned int top_fsm_reg_mask : 10;
    } reg;
} SOC_MUDP_PHY_CP_CSR6_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR6_top_fsm_sfr6_rp0_START (0)
#define SOC_MUDP_PHY_CP_CSR6_top_fsm_sfr6_rp0_END (21)
#define SOC_MUDP_PHY_CP_CSR6_top_fsm_reg_mask_START (22)
#define SOC_MUDP_PHY_CP_CSR6_top_fsm_reg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr7_rp1 : 22;
        unsigned int top_fsm_status : 3;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PHY_CP_CSR7_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR7_top_fsm_sfr7_rp1_START (0)
#define SOC_MUDP_PHY_CP_CSR7_top_fsm_sfr7_rp1_END (21)
#define SOC_MUDP_PHY_CP_CSR7_top_fsm_status_START (22)
#define SOC_MUDP_PHY_CP_CSR7_top_fsm_status_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr8_pc : 22;
        unsigned int top_fsm_done : 1;
        unsigned int top_fsm_cmd : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_MUDP_PHY_CP_CSR8_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR8_top_fsm_sfr8_pc_START (0)
#define SOC_MUDP_PHY_CP_CSR8_top_fsm_sfr8_pc_END (21)
#define SOC_MUDP_PHY_CP_CSR8_top_fsm_done_START (22)
#define SOC_MUDP_PHY_CP_CSR8_top_fsm_done_END (22)
#define SOC_MUDP_PHY_CP_CSR8_top_fsm_cmd_START (23)
#define SOC_MUDP_PHY_CP_CSR8_top_fsm_cmd_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr9_opl : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR9_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR9_top_fsm_sfr9_opl_START (0)
#define SOC_MUDP_PHY_CP_CSR9_top_fsm_sfr9_opl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr10_opr : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR10_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR10_top_fsm_sfr10_opr_START (0)
#define SOC_MUDP_PHY_CP_CSR10_top_fsm_sfr10_opr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr11_opd : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR11_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR11_top_fsm_sfr11_opd_START (0)
#define SOC_MUDP_PHY_CP_CSR11_top_fsm_sfr11_opd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr12_a0 : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR12_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR12_top_fsm_sfr12_a0_START (0)
#define SOC_MUDP_PHY_CP_CSR12_top_fsm_sfr12_a0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr13_a1 : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR13_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR13_top_fsm_sfr13_a1_START (0)
#define SOC_MUDP_PHY_CP_CSR13_top_fsm_sfr13_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr14_a2 : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR14_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR14_top_fsm_sfr14_a2_START (0)
#define SOC_MUDP_PHY_CP_CSR14_top_fsm_sfr14_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_sfr15_a3 : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR15_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR15_top_fsm_sfr15_a3_START (0)
#define SOC_MUDP_PHY_CP_CSR15_top_fsm_sfr15_a3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_reg_addr : 16;
        unsigned int top_fsm_sram_addr : 16;
    } reg;
} SOC_MUDP_PHY_CP_CSR16_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR16_top_fsm_reg_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR16_top_fsm_reg_addr_END (15)
#define SOC_MUDP_PHY_CP_CSR16_top_fsm_sram_addr_START (16)
#define SOC_MUDP_PHY_CP_CSR16_top_fsm_sram_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_start : 1;
        unsigned int top_fsm_start_addr : 16;
        unsigned int top_fsm_hold_en : 1;
        unsigned int top_fsm_freeze : 1;
        unsigned int top_fsm_clr : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR17_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_start_START (0)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_start_END (0)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_start_addr_START (1)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_start_addr_END (16)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_hold_en_START (17)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_hold_en_END (17)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_freeze_START (18)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_freeze_END (18)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_clr_START (19)
#define SOC_MUDP_PHY_CP_CSR17_top_fsm_clr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_timer_base : 14;
        unsigned int top_fsm_timer_exp : 4;
        unsigned int top_fsm_apb_slverr_bypass : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_PHY_CP_CSR18_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR18_top_fsm_timer_base_START (0)
#define SOC_MUDP_PHY_CP_CSR18_top_fsm_timer_base_END (13)
#define SOC_MUDP_PHY_CP_CSR18_top_fsm_timer_exp_START (14)
#define SOC_MUDP_PHY_CP_CSR18_top_fsm_timer_exp_END (17)
#define SOC_MUDP_PHY_CP_CSR18_top_fsm_apb_slverr_bypass_START (18)
#define SOC_MUDP_PHY_CP_CSR18_top_fsm_apb_slverr_bypass_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_req_start_addr : 16;
        unsigned int pll0_req_en : 2;
        unsigned int pll1_req_en : 2;
        unsigned int init_req_en : 2;
        unsigned int top_fsm_wait_flag_ctrl : 3;
        unsigned int top_fsm_clr_en : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_PHY_CP_CSR19_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR19_top_fsm_req_start_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR19_top_fsm_req_start_addr_END (15)
#define SOC_MUDP_PHY_CP_CSR19_pll0_req_en_START (16)
#define SOC_MUDP_PHY_CP_CSR19_pll0_req_en_END (17)
#define SOC_MUDP_PHY_CP_CSR19_pll1_req_en_START (18)
#define SOC_MUDP_PHY_CP_CSR19_pll1_req_en_END (19)
#define SOC_MUDP_PHY_CP_CSR19_init_req_en_START (20)
#define SOC_MUDP_PHY_CP_CSR19_init_req_en_END (21)
#define SOC_MUDP_PHY_CP_CSR19_top_fsm_wait_flag_ctrl_START (22)
#define SOC_MUDP_PHY_CP_CSR19_top_fsm_wait_flag_ctrl_END (24)
#define SOC_MUDP_PHY_CP_CSR19_top_fsm_clr_en_START (25)
#define SOC_MUDP_PHY_CP_CSR19_top_fsm_clr_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_fsm_curr_fw : 6;
        unsigned int top_curr_txx_fsm_int0 : 4;
        unsigned int top_curr_rxx_fsm_int0 : 4;
        unsigned int all_slice_pll0_req : 1;
        unsigned int all_slice_pll1_req : 1;
        unsigned int all_slice_init_req : 1;
        unsigned int rv_pll0_req_int : 1;
        unsigned int rv_pll1_req_int : 1;
        unsigned int rv_init_req_int : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR20_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR20_top_fsm_curr_fw_START (0)
#define SOC_MUDP_PHY_CP_CSR20_top_fsm_curr_fw_END (5)
#define SOC_MUDP_PHY_CP_CSR20_top_curr_txx_fsm_int0_START (6)
#define SOC_MUDP_PHY_CP_CSR20_top_curr_txx_fsm_int0_END (9)
#define SOC_MUDP_PHY_CP_CSR20_top_curr_rxx_fsm_int0_START (10)
#define SOC_MUDP_PHY_CP_CSR20_top_curr_rxx_fsm_int0_END (13)
#define SOC_MUDP_PHY_CP_CSR20_all_slice_pll0_req_START (14)
#define SOC_MUDP_PHY_CP_CSR20_all_slice_pll0_req_END (14)
#define SOC_MUDP_PHY_CP_CSR20_all_slice_pll1_req_START (15)
#define SOC_MUDP_PHY_CP_CSR20_all_slice_pll1_req_END (15)
#define SOC_MUDP_PHY_CP_CSR20_all_slice_init_req_START (16)
#define SOC_MUDP_PHY_CP_CSR20_all_slice_init_req_END (16)
#define SOC_MUDP_PHY_CP_CSR20_rv_pll0_req_int_START (17)
#define SOC_MUDP_PHY_CP_CSR20_rv_pll0_req_int_END (17)
#define SOC_MUDP_PHY_CP_CSR20_rv_pll1_req_int_START (18)
#define SOC_MUDP_PHY_CP_CSR20_rv_pll1_req_int_END (18)
#define SOC_MUDP_PHY_CP_CSR20_rv_init_req_int_START (19)
#define SOC_MUDP_PHY_CP_CSR20_rv_init_req_int_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_freq : 5;
        unsigned int fsm_sram_max_addr : 16;
        unsigned int reserved : 11;
    } reg;
} SOC_MUDP_PHY_CP_CSR21_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR21_core_freq_START (0)
#define SOC_MUDP_PHY_CP_CSR21_core_freq_END (4)
#define SOC_MUDP_PHY_CP_CSR21_fsm_sram_max_addr_START (5)
#define SOC_MUDP_PHY_CP_CSR21_fsm_sram_max_addr_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fsm_spreg_start_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PHY_CP_CSR22_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR22_fsm_spreg_start_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR22_fsm_spreg_start_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cp_sram_return_cnt : 1;
        unsigned int reserved_0 : 5;
        unsigned int cp_apb_slverr_mask : 1;
        unsigned int cp_adap_apb_timeout_th : 3;
        unsigned int cpdfx_low_length : 4;
        unsigned int cpdfx_high_length : 4;
        unsigned int cpdfx_lfdata_test_en : 1;
        unsigned int cpdfx_clk_en : 1;
        unsigned int cpdfx_clk_soft_rstn : 1;
        unsigned int cp_cs_calib_sel : 1;
        unsigned int cp_dtb_sel : 4;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MUDP_PHY_CP_CSR23_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR23_cp_sram_return_cnt_START (0)
#define SOC_MUDP_PHY_CP_CSR23_cp_sram_return_cnt_END (0)
#define SOC_MUDP_PHY_CP_CSR23_cp_apb_slverr_mask_START (6)
#define SOC_MUDP_PHY_CP_CSR23_cp_apb_slverr_mask_END (6)
#define SOC_MUDP_PHY_CP_CSR23_cp_adap_apb_timeout_th_START (7)
#define SOC_MUDP_PHY_CP_CSR23_cp_adap_apb_timeout_th_END (9)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_low_length_START (10)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_low_length_END (13)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_high_length_START (14)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_high_length_END (17)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_lfdata_test_en_START (18)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_lfdata_test_en_END (18)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_clk_en_START (19)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_clk_en_END (19)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_clk_soft_rstn_START (20)
#define SOC_MUDP_PHY_CP_CSR23_cpdfx_clk_soft_rstn_END (20)
#define SOC_MUDP_PHY_CP_CSR23_cp_cs_calib_sel_START (21)
#define SOC_MUDP_PHY_CP_CSR23_cp_cs_calib_sel_END (21)
#define SOC_MUDP_PHY_CP_CSR23_cp_dtb_sel_START (22)
#define SOC_MUDP_PHY_CP_CSR23_cp_dtb_sel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR24_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cp_spare0 : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR25_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR25_cp_spare0_START (0)
#define SOC_MUDP_PHY_CP_CSR25_cp_spare0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cp_spare1 : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR26_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR26_cp_spare1_START (0)
#define SOC_MUDP_PHY_CP_CSR26_cp_spare1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cp_spare2 : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR27_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR27_cp_spare2_START (0)
#define SOC_MUDP_PHY_CP_CSR27_cp_spare2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 18;
        unsigned int rv_timer_clk_div : 4;
        unsigned int cp_rwreg_online_en : 1;
        unsigned int core_clk_div : 1;
        unsigned int top_fsm_clk_en : 1;
        unsigned int top_fsm_soft_rstn : 1;
        unsigned int rv_wdog_clk_soft_rstn : 1;
        unsigned int rv_timer_clk_soft_rstn : 1;
        unsigned int rv_clk_soft_rstn : 1;
        unsigned int rv_wdog_clk_en : 1;
        unsigned int rv_timer_clk_en : 1;
        unsigned int rv_clk_en : 1;
    } reg;
} SOC_MUDP_PHY_CP_CSR28_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR28_rv_timer_clk_div_START (18)
#define SOC_MUDP_PHY_CP_CSR28_rv_timer_clk_div_END (21)
#define SOC_MUDP_PHY_CP_CSR28_cp_rwreg_online_en_START (22)
#define SOC_MUDP_PHY_CP_CSR28_cp_rwreg_online_en_END (22)
#define SOC_MUDP_PHY_CP_CSR28_core_clk_div_START (23)
#define SOC_MUDP_PHY_CP_CSR28_core_clk_div_END (23)
#define SOC_MUDP_PHY_CP_CSR28_top_fsm_clk_en_START (24)
#define SOC_MUDP_PHY_CP_CSR28_top_fsm_clk_en_END (24)
#define SOC_MUDP_PHY_CP_CSR28_top_fsm_soft_rstn_START (25)
#define SOC_MUDP_PHY_CP_CSR28_top_fsm_soft_rstn_END (25)
#define SOC_MUDP_PHY_CP_CSR28_rv_wdog_clk_soft_rstn_START (26)
#define SOC_MUDP_PHY_CP_CSR28_rv_wdog_clk_soft_rstn_END (26)
#define SOC_MUDP_PHY_CP_CSR28_rv_timer_clk_soft_rstn_START (27)
#define SOC_MUDP_PHY_CP_CSR28_rv_timer_clk_soft_rstn_END (27)
#define SOC_MUDP_PHY_CP_CSR28_rv_clk_soft_rstn_START (28)
#define SOC_MUDP_PHY_CP_CSR28_rv_clk_soft_rstn_END (28)
#define SOC_MUDP_PHY_CP_CSR28_rv_wdog_clk_en_START (29)
#define SOC_MUDP_PHY_CP_CSR28_rv_wdog_clk_en_END (29)
#define SOC_MUDP_PHY_CP_CSR28_rv_timer_clk_en_START (30)
#define SOC_MUDP_PHY_CP_CSR28_rv_timer_clk_en_END (30)
#define SOC_MUDP_PHY_CP_CSR28_rv_clk_en_START (31)
#define SOC_MUDP_PHY_CP_CSR28_rv_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_start_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR29_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR29_itcm_rgn_start_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR29_itcm_rgn_start_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_end_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR30_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR30_itcm_rgn_end_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR30_itcm_rgn_end_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtcm_rgn_start_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR31_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR31_dtcm_rgn_start_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR31_dtcm_rgn_start_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtcm_rgn_end_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR32_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR32_dtcm_rgn_end_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR32_dtcm_rgn_end_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_rgn_start_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR33_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR33_ahb_rgn_start_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR33_ahb_rgn_start_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_rgn_end_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_CP_CSR34_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR34_ahb_rgn_end_addr_START (0)
#define SOC_MUDP_PHY_CP_CSR34_ahb_rgn_end_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int por_rst_pc : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR35_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR35_por_rst_pc_START (0)
#define SOC_MUDP_PHY_CP_CSR35_por_rst_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer_thr : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR36_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR36_timer_thr_START (0)
#define SOC_MUDP_PHY_CP_CSR36_timer_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer_cnt : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR37_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR37_timer_cnt_START (0)
#define SOC_MUDP_PHY_CP_CSR37_timer_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_stack_pointer : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR38_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR38_core_irf_stack_pointer_START (0)
#define SOC_MUDP_PHY_CP_CSR38_core_irf_stack_pointer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR39_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR39_core_pc_START (0)
#define SOC_MUDP_PHY_CP_CSR39_core_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdog_load_data : 23;
        unsigned int code_hard_fault_mode : 1;
        unsigned int core_debug_mode : 1;
        unsigned int core_sleep_mode : 1;
        unsigned int wdog_load : 1;
        unsigned int wdog_ena : 1;
        unsigned int timer_stop : 1;
        unsigned int timer_start : 1;
        unsigned int core_wait : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_MUDP_PHY_CP_CSR40_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR40_wdog_load_data_START (0)
#define SOC_MUDP_PHY_CP_CSR40_wdog_load_data_END (22)
#define SOC_MUDP_PHY_CP_CSR40_code_hard_fault_mode_START (23)
#define SOC_MUDP_PHY_CP_CSR40_code_hard_fault_mode_END (23)
#define SOC_MUDP_PHY_CP_CSR40_core_debug_mode_START (24)
#define SOC_MUDP_PHY_CP_CSR40_core_debug_mode_END (24)
#define SOC_MUDP_PHY_CP_CSR40_core_sleep_mode_START (25)
#define SOC_MUDP_PHY_CP_CSR40_core_sleep_mode_END (25)
#define SOC_MUDP_PHY_CP_CSR40_wdog_load_START (26)
#define SOC_MUDP_PHY_CP_CSR40_wdog_load_END (26)
#define SOC_MUDP_PHY_CP_CSR40_wdog_ena_START (27)
#define SOC_MUDP_PHY_CP_CSR40_wdog_ena_END (27)
#define SOC_MUDP_PHY_CP_CSR40_timer_stop_START (28)
#define SOC_MUDP_PHY_CP_CSR40_timer_stop_END (28)
#define SOC_MUDP_PHY_CP_CSR40_timer_start_START (29)
#define SOC_MUDP_PHY_CP_CSR40_timer_start_END (29)
#define SOC_MUDP_PHY_CP_CSR40_core_wait_START (30)
#define SOC_MUDP_PHY_CP_CSR40_core_wait_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rv_int_mode : 1;
        unsigned int rv_wdog_rst_bypass : 1;
        unsigned int rv_reg_error_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PHY_CP_CSR41_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR41_rv_int_mode_START (0)
#define SOC_MUDP_PHY_CP_CSR41_rv_int_mode_END (0)
#define SOC_MUDP_PHY_CP_CSR41_rv_wdog_rst_bypass_START (1)
#define SOC_MUDP_PHY_CP_CSR41_rv_wdog_rst_bypass_END (1)
#define SOC_MUDP_PHY_CP_CSR41_rv_reg_error_bypass_START (2)
#define SOC_MUDP_PHY_CP_CSR41_rv_reg_error_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_CP_CSR42_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ss_spare_in_fromcp : 2;
        unsigned int cs_spare_in_fromcp : 2;
        unsigned int tx0_spare_in_fromcp : 2;
        unsigned int tx1_spare_in_fromcp : 2;
        unsigned int tx2_spare_in_fromcp : 2;
        unsigned int tx3_spare_in_fromcp : 2;
        unsigned int tx4_spare_in_fromcp : 2;
        unsigned int tx5_spare_in_fromcp : 2;
        unsigned int tx6_spare_in_fromcp : 2;
        unsigned int tx7_spare_in_fromcp : 2;
        unsigned int rx0_spare_in_fromcp : 2;
        unsigned int rx1_spare_in_fromcp : 2;
        unsigned int rx2_spare_in_fromcp : 2;
        unsigned int rx3_spare_in_fromcp : 2;
        unsigned int rx4_spare_in_fromcp : 2;
        unsigned int rx5_spare_in_fromcp : 2;
    } reg;
} SOC_MUDP_PHY_CP_CSR43_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR43_ss_spare_in_fromcp_START (0)
#define SOC_MUDP_PHY_CP_CSR43_ss_spare_in_fromcp_END (1)
#define SOC_MUDP_PHY_CP_CSR43_cs_spare_in_fromcp_START (2)
#define SOC_MUDP_PHY_CP_CSR43_cs_spare_in_fromcp_END (3)
#define SOC_MUDP_PHY_CP_CSR43_tx0_spare_in_fromcp_START (4)
#define SOC_MUDP_PHY_CP_CSR43_tx0_spare_in_fromcp_END (5)
#define SOC_MUDP_PHY_CP_CSR43_tx1_spare_in_fromcp_START (6)
#define SOC_MUDP_PHY_CP_CSR43_tx1_spare_in_fromcp_END (7)
#define SOC_MUDP_PHY_CP_CSR43_tx2_spare_in_fromcp_START (8)
#define SOC_MUDP_PHY_CP_CSR43_tx2_spare_in_fromcp_END (9)
#define SOC_MUDP_PHY_CP_CSR43_tx3_spare_in_fromcp_START (10)
#define SOC_MUDP_PHY_CP_CSR43_tx3_spare_in_fromcp_END (11)
#define SOC_MUDP_PHY_CP_CSR43_tx4_spare_in_fromcp_START (12)
#define SOC_MUDP_PHY_CP_CSR43_tx4_spare_in_fromcp_END (13)
#define SOC_MUDP_PHY_CP_CSR43_tx5_spare_in_fromcp_START (14)
#define SOC_MUDP_PHY_CP_CSR43_tx5_spare_in_fromcp_END (15)
#define SOC_MUDP_PHY_CP_CSR43_tx6_spare_in_fromcp_START (16)
#define SOC_MUDP_PHY_CP_CSR43_tx6_spare_in_fromcp_END (17)
#define SOC_MUDP_PHY_CP_CSR43_tx7_spare_in_fromcp_START (18)
#define SOC_MUDP_PHY_CP_CSR43_tx7_spare_in_fromcp_END (19)
#define SOC_MUDP_PHY_CP_CSR43_rx0_spare_in_fromcp_START (20)
#define SOC_MUDP_PHY_CP_CSR43_rx0_spare_in_fromcp_END (21)
#define SOC_MUDP_PHY_CP_CSR43_rx1_spare_in_fromcp_START (22)
#define SOC_MUDP_PHY_CP_CSR43_rx1_spare_in_fromcp_END (23)
#define SOC_MUDP_PHY_CP_CSR43_rx2_spare_in_fromcp_START (24)
#define SOC_MUDP_PHY_CP_CSR43_rx2_spare_in_fromcp_END (25)
#define SOC_MUDP_PHY_CP_CSR43_rx3_spare_in_fromcp_START (26)
#define SOC_MUDP_PHY_CP_CSR43_rx3_spare_in_fromcp_END (27)
#define SOC_MUDP_PHY_CP_CSR43_rx4_spare_in_fromcp_START (28)
#define SOC_MUDP_PHY_CP_CSR43_rx4_spare_in_fromcp_END (29)
#define SOC_MUDP_PHY_CP_CSR43_rx5_spare_in_fromcp_START (30)
#define SOC_MUDP_PHY_CP_CSR43_rx5_spare_in_fromcp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx6_spare_in_fromcp : 2;
        unsigned int rx7_spare_in_fromcp : 2;
        unsigned int cs_spare_out_fromcp : 2;
        unsigned int ss_spare_out_fromcp : 2;
        unsigned int tx0_spare_out_fromcp : 2;
        unsigned int tx1_spare_out_fromcp : 2;
        unsigned int tx2_spare_out_fromcp : 2;
        unsigned int tx3_spare_out_fromcp : 2;
        unsigned int tx4_spare_out_fromcp : 2;
        unsigned int tx5_spare_out_fromcp : 2;
        unsigned int tx6_spare_out_fromcp : 2;
        unsigned int tx7_spare_out_fromcp : 2;
        unsigned int rx0_spare_out_fromcp : 2;
        unsigned int rx1_spare_out_fromcp : 2;
        unsigned int rx2_spare_out_fromcp : 2;
        unsigned int rx3_spare_out_fromcp : 2;
    } reg;
} SOC_MUDP_PHY_CP_CSR44_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR44_rx6_spare_in_fromcp_START (0)
#define SOC_MUDP_PHY_CP_CSR44_rx6_spare_in_fromcp_END (1)
#define SOC_MUDP_PHY_CP_CSR44_rx7_spare_in_fromcp_START (2)
#define SOC_MUDP_PHY_CP_CSR44_rx7_spare_in_fromcp_END (3)
#define SOC_MUDP_PHY_CP_CSR44_cs_spare_out_fromcp_START (4)
#define SOC_MUDP_PHY_CP_CSR44_cs_spare_out_fromcp_END (5)
#define SOC_MUDP_PHY_CP_CSR44_ss_spare_out_fromcp_START (6)
#define SOC_MUDP_PHY_CP_CSR44_ss_spare_out_fromcp_END (7)
#define SOC_MUDP_PHY_CP_CSR44_tx0_spare_out_fromcp_START (8)
#define SOC_MUDP_PHY_CP_CSR44_tx0_spare_out_fromcp_END (9)
#define SOC_MUDP_PHY_CP_CSR44_tx1_spare_out_fromcp_START (10)
#define SOC_MUDP_PHY_CP_CSR44_tx1_spare_out_fromcp_END (11)
#define SOC_MUDP_PHY_CP_CSR44_tx2_spare_out_fromcp_START (12)
#define SOC_MUDP_PHY_CP_CSR44_tx2_spare_out_fromcp_END (13)
#define SOC_MUDP_PHY_CP_CSR44_tx3_spare_out_fromcp_START (14)
#define SOC_MUDP_PHY_CP_CSR44_tx3_spare_out_fromcp_END (15)
#define SOC_MUDP_PHY_CP_CSR44_tx4_spare_out_fromcp_START (16)
#define SOC_MUDP_PHY_CP_CSR44_tx4_spare_out_fromcp_END (17)
#define SOC_MUDP_PHY_CP_CSR44_tx5_spare_out_fromcp_START (18)
#define SOC_MUDP_PHY_CP_CSR44_tx5_spare_out_fromcp_END (19)
#define SOC_MUDP_PHY_CP_CSR44_tx6_spare_out_fromcp_START (20)
#define SOC_MUDP_PHY_CP_CSR44_tx6_spare_out_fromcp_END (21)
#define SOC_MUDP_PHY_CP_CSR44_tx7_spare_out_fromcp_START (22)
#define SOC_MUDP_PHY_CP_CSR44_tx7_spare_out_fromcp_END (23)
#define SOC_MUDP_PHY_CP_CSR44_rx0_spare_out_fromcp_START (24)
#define SOC_MUDP_PHY_CP_CSR44_rx0_spare_out_fromcp_END (25)
#define SOC_MUDP_PHY_CP_CSR44_rx1_spare_out_fromcp_START (26)
#define SOC_MUDP_PHY_CP_CSR44_rx1_spare_out_fromcp_END (27)
#define SOC_MUDP_PHY_CP_CSR44_rx2_spare_out_fromcp_START (28)
#define SOC_MUDP_PHY_CP_CSR44_rx2_spare_out_fromcp_END (29)
#define SOC_MUDP_PHY_CP_CSR44_rx3_spare_out_fromcp_START (30)
#define SOC_MUDP_PHY_CP_CSR44_rx3_spare_out_fromcp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx4_spare_out_fromcp : 2;
        unsigned int rx5_spare_out_fromcp : 2;
        unsigned int rx6_spare_out_fromcp : 2;
        unsigned int rx7_spare_out_fromcp : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_PHY_CP_CSR45_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR45_rx4_spare_out_fromcp_START (0)
#define SOC_MUDP_PHY_CP_CSR45_rx4_spare_out_fromcp_END (1)
#define SOC_MUDP_PHY_CP_CSR45_rx5_spare_out_fromcp_START (2)
#define SOC_MUDP_PHY_CP_CSR45_rx5_spare_out_fromcp_END (3)
#define SOC_MUDP_PHY_CP_CSR45_rx6_spare_out_fromcp_START (4)
#define SOC_MUDP_PHY_CP_CSR45_rx6_spare_out_fromcp_END (5)
#define SOC_MUDP_PHY_CP_CSR45_rx7_spare_out_fromcp_START (6)
#define SOC_MUDP_PHY_CP_CSR45_rx7_spare_out_fromcp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rv_wdog_int_source : 1;
        unsigned int rv_apb_slverr_int_source : 1;
        unsigned int top_fsm_apb_slverr_int_source : 1;
        unsigned int top_fsm_wait_out_flag_int_source : 1;
        unsigned int top_fsm_cmd_error_int_source : 1;
        unsigned int top_fsm_sram_error_int_source : 1;
        unsigned int cp_soft_int_source : 1;
        unsigned int cp_reg_req_error_int_source : 1;
        unsigned int cp_adap_apb_error_int_source : 1;
        unsigned int cp_cs_int_source : 1;
        unsigned int cp_ss_int_source : 1;
        unsigned int cp_ds_int_source : 8;
        unsigned int rv_timer_int_source : 1;
        unsigned int rv_sleep_int_source : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_MUDP_PHY_CP_CSR46_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR46_rv_wdog_int_source_START (0)
#define SOC_MUDP_PHY_CP_CSR46_rv_wdog_int_source_END (0)
#define SOC_MUDP_PHY_CP_CSR46_rv_apb_slverr_int_source_START (1)
#define SOC_MUDP_PHY_CP_CSR46_rv_apb_slverr_int_source_END (1)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_apb_slverr_int_source_START (2)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_apb_slverr_int_source_END (2)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_wait_out_flag_int_source_START (3)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_wait_out_flag_int_source_END (3)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_cmd_error_int_source_START (4)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_cmd_error_int_source_END (4)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_sram_error_int_source_START (5)
#define SOC_MUDP_PHY_CP_CSR46_top_fsm_sram_error_int_source_END (5)
#define SOC_MUDP_PHY_CP_CSR46_cp_soft_int_source_START (6)
#define SOC_MUDP_PHY_CP_CSR46_cp_soft_int_source_END (6)
#define SOC_MUDP_PHY_CP_CSR46_cp_reg_req_error_int_source_START (7)
#define SOC_MUDP_PHY_CP_CSR46_cp_reg_req_error_int_source_END (7)
#define SOC_MUDP_PHY_CP_CSR46_cp_adap_apb_error_int_source_START (8)
#define SOC_MUDP_PHY_CP_CSR46_cp_adap_apb_error_int_source_END (8)
#define SOC_MUDP_PHY_CP_CSR46_cp_cs_int_source_START (9)
#define SOC_MUDP_PHY_CP_CSR46_cp_cs_int_source_END (9)
#define SOC_MUDP_PHY_CP_CSR46_cp_ss_int_source_START (10)
#define SOC_MUDP_PHY_CP_CSR46_cp_ss_int_source_END (10)
#define SOC_MUDP_PHY_CP_CSR46_cp_ds_int_source_START (11)
#define SOC_MUDP_PHY_CP_CSR46_cp_ds_int_source_END (18)
#define SOC_MUDP_PHY_CP_CSR46_rv_timer_int_source_START (19)
#define SOC_MUDP_PHY_CP_CSR46_rv_timer_int_source_END (19)
#define SOC_MUDP_PHY_CP_CSR46_rv_sleep_int_source_START (20)
#define SOC_MUDP_PHY_CP_CSR46_rv_sleep_int_source_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rv_wdog_int_mask : 1;
        unsigned int rv_apb_slverr_int_mask : 1;
        unsigned int top_fsm_apb_slverr_int_mask : 1;
        unsigned int top_fsm_wait_out_flag_int_mask : 1;
        unsigned int top_fsm_cmd_error_int_mask : 1;
        unsigned int top_fsm_sram_error_int_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int cp_reg_req_error_int_mask : 1;
        unsigned int cp_adap_apb_error_int_mask : 1;
        unsigned int cp_cs_int_mask : 1;
        unsigned int cp_ss_int_mask : 1;
        unsigned int cp_ds_int_mask : 8;
        unsigned int cp_soft_int_mask : 1;
        unsigned int rv_timer_int_mask : 1;
        unsigned int rv_sleep_int_mask : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MUDP_PHY_CP_CSR47_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR47_rv_wdog_int_mask_START (0)
#define SOC_MUDP_PHY_CP_CSR47_rv_wdog_int_mask_END (0)
#define SOC_MUDP_PHY_CP_CSR47_rv_apb_slverr_int_mask_START (1)
#define SOC_MUDP_PHY_CP_CSR47_rv_apb_slverr_int_mask_END (1)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_apb_slverr_int_mask_START (2)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_apb_slverr_int_mask_END (2)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_wait_out_flag_int_mask_START (3)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_wait_out_flag_int_mask_END (3)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_cmd_error_int_mask_START (4)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_cmd_error_int_mask_END (4)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_sram_error_int_mask_START (5)
#define SOC_MUDP_PHY_CP_CSR47_top_fsm_sram_error_int_mask_END (5)
#define SOC_MUDP_PHY_CP_CSR47_cp_reg_req_error_int_mask_START (7)
#define SOC_MUDP_PHY_CP_CSR47_cp_reg_req_error_int_mask_END (7)
#define SOC_MUDP_PHY_CP_CSR47_cp_adap_apb_error_int_mask_START (8)
#define SOC_MUDP_PHY_CP_CSR47_cp_adap_apb_error_int_mask_END (8)
#define SOC_MUDP_PHY_CP_CSR47_cp_cs_int_mask_START (9)
#define SOC_MUDP_PHY_CP_CSR47_cp_cs_int_mask_END (9)
#define SOC_MUDP_PHY_CP_CSR47_cp_ss_int_mask_START (10)
#define SOC_MUDP_PHY_CP_CSR47_cp_ss_int_mask_END (10)
#define SOC_MUDP_PHY_CP_CSR47_cp_ds_int_mask_START (11)
#define SOC_MUDP_PHY_CP_CSR47_cp_ds_int_mask_END (18)
#define SOC_MUDP_PHY_CP_CSR47_cp_soft_int_mask_START (19)
#define SOC_MUDP_PHY_CP_CSR47_cp_soft_int_mask_END (19)
#define SOC_MUDP_PHY_CP_CSR47_rv_timer_int_mask_START (20)
#define SOC_MUDP_PHY_CP_CSR47_rv_timer_int_mask_END (20)
#define SOC_MUDP_PHY_CP_CSR47_rv_sleep_int_mask_START (21)
#define SOC_MUDP_PHY_CP_CSR47_rv_sleep_int_mask_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rv_wdog_int : 1;
        unsigned int rv_apb_slverr_int : 1;
        unsigned int top_fsm_apb_slverr_int : 1;
        unsigned int top_fsm_wait_out_flag_int : 1;
        unsigned int top_fsm_cmd_error_int : 1;
        unsigned int top_fsm_sram_error_int : 1;
        unsigned int reserved_0 : 1;
        unsigned int cp_reg_req_error_int : 1;
        unsigned int cp_adap_apb_error_int : 1;
        unsigned int cp_cs_int : 1;
        unsigned int cp_ss_int : 1;
        unsigned int cp_ds_int : 8;
        unsigned int sds_int : 1;
        unsigned int cp_soft_int : 1;
        unsigned int rv_timer_int : 1;
        unsigned int rv_sleep_int : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_MUDP_PHY_CP_CSR48_UNION;
#endif
#define SOC_MUDP_PHY_CP_CSR48_rv_wdog_int_START (0)
#define SOC_MUDP_PHY_CP_CSR48_rv_wdog_int_END (0)
#define SOC_MUDP_PHY_CP_CSR48_rv_apb_slverr_int_START (1)
#define SOC_MUDP_PHY_CP_CSR48_rv_apb_slverr_int_END (1)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_apb_slverr_int_START (2)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_apb_slverr_int_END (2)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_wait_out_flag_int_START (3)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_wait_out_flag_int_END (3)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_cmd_error_int_START (4)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_cmd_error_int_END (4)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_sram_error_int_START (5)
#define SOC_MUDP_PHY_CP_CSR48_top_fsm_sram_error_int_END (5)
#define SOC_MUDP_PHY_CP_CSR48_cp_reg_req_error_int_START (7)
#define SOC_MUDP_PHY_CP_CSR48_cp_reg_req_error_int_END (7)
#define SOC_MUDP_PHY_CP_CSR48_cp_adap_apb_error_int_START (8)
#define SOC_MUDP_PHY_CP_CSR48_cp_adap_apb_error_int_END (8)
#define SOC_MUDP_PHY_CP_CSR48_cp_cs_int_START (9)
#define SOC_MUDP_PHY_CP_CSR48_cp_cs_int_END (9)
#define SOC_MUDP_PHY_CP_CSR48_cp_ss_int_START (10)
#define SOC_MUDP_PHY_CP_CSR48_cp_ss_int_END (10)
#define SOC_MUDP_PHY_CP_CSR48_cp_ds_int_START (11)
#define SOC_MUDP_PHY_CP_CSR48_cp_ds_int_END (18)
#define SOC_MUDP_PHY_CP_CSR48_sds_int_START (19)
#define SOC_MUDP_PHY_CP_CSR48_sds_int_END (19)
#define SOC_MUDP_PHY_CP_CSR48_cp_soft_int_START (20)
#define SOC_MUDP_PHY_CP_CSR48_cp_soft_int_END (20)
#define SOC_MUDP_PHY_CP_CSR48_rv_timer_int_START (21)
#define SOC_MUDP_PHY_CP_CSR48_rv_timer_int_END (21)
#define SOC_MUDP_PHY_CP_CSR48_rv_sleep_int_START (22)
#define SOC_MUDP_PHY_CP_CSR48_rv_sleep_int_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_ana_id : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_MUDP_PHY_CS_CSR0_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR0_cs_ana_id_START (0)
#define SOC_MUDP_PHY_CS_CSR0_cs_ana_id_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_calib_soft_rstn : 1;
        unsigned int cs_lld_soft_rstn : 1;
        unsigned int cs_pll_soft_rstn : 1;
        unsigned int cs_soft_rstn : 1;
        unsigned int cs_kckref_div : 2;
        unsigned int reserved_0 : 1;
        unsigned int cs_kckd_hs_pre_div : 1;
        unsigned int cs_ckv_gate : 1;
        unsigned int cs_ckv_en : 1;
        unsigned int cs_afc_clk_en : 1;
        unsigned int cs_olt_clk_en : 1;
        unsigned int cs_ssc_clk_en : 1;
        unsigned int cs_tcal_clk_en : 1;
        unsigned int cs_pll_dtc_clk_en : 1;
        unsigned int cs_mclk_gate : 1;
        unsigned int cs_mclk_en : 1;
        unsigned int cs_refclkd_gate : 1;
        unsigned int cs_refclkd_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int cs_sds_cs_mclk_soft_rstn : 1;
        unsigned int cs_sds_cs_mclk_div_cfg : 3;
        unsigned int cs_sds_cs_mclk_ready : 1;
        unsigned int cs_sds_cs_sys_to_pcs_div : 1;
        unsigned int cs_sds_cs_sys_to_pcs_en : 1;
        unsigned int cs_sds_cs_sys_to_pcs_sel : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_MUDP_PHY_CS_CSR1_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR1_cs_calib_soft_rstn_START (0)
#define SOC_MUDP_PHY_CS_CSR1_cs_calib_soft_rstn_END (0)
#define SOC_MUDP_PHY_CS_CSR1_cs_lld_soft_rstn_START (1)
#define SOC_MUDP_PHY_CS_CSR1_cs_lld_soft_rstn_END (1)
#define SOC_MUDP_PHY_CS_CSR1_cs_pll_soft_rstn_START (2)
#define SOC_MUDP_PHY_CS_CSR1_cs_pll_soft_rstn_END (2)
#define SOC_MUDP_PHY_CS_CSR1_cs_soft_rstn_START (3)
#define SOC_MUDP_PHY_CS_CSR1_cs_soft_rstn_END (3)
#define SOC_MUDP_PHY_CS_CSR1_cs_kckref_div_START (4)
#define SOC_MUDP_PHY_CS_CSR1_cs_kckref_div_END (5)
#define SOC_MUDP_PHY_CS_CSR1_cs_kckd_hs_pre_div_START (7)
#define SOC_MUDP_PHY_CS_CSR1_cs_kckd_hs_pre_div_END (7)
#define SOC_MUDP_PHY_CS_CSR1_cs_ckv_gate_START (8)
#define SOC_MUDP_PHY_CS_CSR1_cs_ckv_gate_END (8)
#define SOC_MUDP_PHY_CS_CSR1_cs_ckv_en_START (9)
#define SOC_MUDP_PHY_CS_CSR1_cs_ckv_en_END (9)
#define SOC_MUDP_PHY_CS_CSR1_cs_afc_clk_en_START (10)
#define SOC_MUDP_PHY_CS_CSR1_cs_afc_clk_en_END (10)
#define SOC_MUDP_PHY_CS_CSR1_cs_olt_clk_en_START (11)
#define SOC_MUDP_PHY_CS_CSR1_cs_olt_clk_en_END (11)
#define SOC_MUDP_PHY_CS_CSR1_cs_ssc_clk_en_START (12)
#define SOC_MUDP_PHY_CS_CSR1_cs_ssc_clk_en_END (12)
#define SOC_MUDP_PHY_CS_CSR1_cs_tcal_clk_en_START (13)
#define SOC_MUDP_PHY_CS_CSR1_cs_tcal_clk_en_END (13)
#define SOC_MUDP_PHY_CS_CSR1_cs_pll_dtc_clk_en_START (14)
#define SOC_MUDP_PHY_CS_CSR1_cs_pll_dtc_clk_en_END (14)
#define SOC_MUDP_PHY_CS_CSR1_cs_mclk_gate_START (15)
#define SOC_MUDP_PHY_CS_CSR1_cs_mclk_gate_END (15)
#define SOC_MUDP_PHY_CS_CSR1_cs_mclk_en_START (16)
#define SOC_MUDP_PHY_CS_CSR1_cs_mclk_en_END (16)
#define SOC_MUDP_PHY_CS_CSR1_cs_refclkd_gate_START (17)
#define SOC_MUDP_PHY_CS_CSR1_cs_refclkd_gate_END (17)
#define SOC_MUDP_PHY_CS_CSR1_cs_refclkd_en_START (18)
#define SOC_MUDP_PHY_CS_CSR1_cs_refclkd_en_END (18)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_mclk_soft_rstn_START (20)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_mclk_soft_rstn_END (20)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_mclk_div_cfg_START (21)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_mclk_div_cfg_END (23)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_mclk_ready_START (24)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_mclk_ready_END (24)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_sys_to_pcs_div_START (25)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_sys_to_pcs_div_END (25)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_sys_to_pcs_en_START (26)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_sys_to_pcs_en_END (26)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_sys_to_pcs_sel_START (27)
#define SOC_MUDP_PHY_CS_CSR1_cs_sds_cs_sys_to_pcs_sel_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_calib_clk_en : 1;
        unsigned int cs_adc_clk_div_ratio : 7;
        unsigned int reserved_0 : 6;
        unsigned int cs_lld_clk_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int cs_adc_clk_en : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_MUDP_PHY_CS_CSR2_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR2_cs_calib_clk_en_START (0)
#define SOC_MUDP_PHY_CS_CSR2_cs_calib_clk_en_END (0)
#define SOC_MUDP_PHY_CS_CSR2_cs_adc_clk_div_ratio_START (1)
#define SOC_MUDP_PHY_CS_CSR2_cs_adc_clk_div_ratio_END (7)
#define SOC_MUDP_PHY_CS_CSR2_cs_lld_clk_en_START (14)
#define SOC_MUDP_PHY_CS_CSR2_cs_lld_clk_en_END (14)
#define SOC_MUDP_PHY_CS_CSR2_cs_adc_clk_en_START (16)
#define SOC_MUDP_PHY_CS_CSR2_cs_adc_clk_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_adpll_ro_refresh : 1;
        unsigned int reserved_0 : 1;
        unsigned int cs_adpll_lock_source_sel : 1;
        unsigned int cs_acq2init_cnt_clr : 1;
        unsigned int cs_unlock2acq_cnt_clr : 1;
        unsigned int cs_unlock2init_cnt_clr : 1;
        unsigned int cs_lock2unlock_cnt_clr : 1;
        unsigned int cs_acq2init_cnt_en : 1;
        unsigned int cs_unlock2acq_cnt_en : 1;
        unsigned int cs_unlock2init_cnt_en : 1;
        unsigned int cs_lock2unlock_cnt_en : 1;
        unsigned int cs_unlock2init_en : 1;
        unsigned int cs_unlock2acq_en : 1;
        unsigned int cs_acq2init_en : 1;
        unsigned int cs_ssc4kcal_en : 1;
        unsigned int cs_pacq_en : 1;
        unsigned int cs_unlock2init_flag_gen_src : 1;
        unsigned int cs_phs_err_flag_gen_mode : 1;
        unsigned int cs_fast_lock_mode : 1;
        unsigned int cs_adpll_en : 1;
        unsigned int cs_adpll_lock_flag : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_MUDP_PHY_CS_CSR3_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_ro_refresh_START (0)
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_ro_refresh_END (0)
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_lock_source_sel_START (2)
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_lock_source_sel_END (2)
#define SOC_MUDP_PHY_CS_CSR3_cs_acq2init_cnt_clr_START (3)
#define SOC_MUDP_PHY_CS_CSR3_cs_acq2init_cnt_clr_END (3)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2acq_cnt_clr_START (4)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2acq_cnt_clr_END (4)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_cnt_clr_START (5)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_cnt_clr_END (5)
#define SOC_MUDP_PHY_CS_CSR3_cs_lock2unlock_cnt_clr_START (6)
#define SOC_MUDP_PHY_CS_CSR3_cs_lock2unlock_cnt_clr_END (6)
#define SOC_MUDP_PHY_CS_CSR3_cs_acq2init_cnt_en_START (7)
#define SOC_MUDP_PHY_CS_CSR3_cs_acq2init_cnt_en_END (7)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2acq_cnt_en_START (8)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2acq_cnt_en_END (8)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_cnt_en_START (9)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_cnt_en_END (9)
#define SOC_MUDP_PHY_CS_CSR3_cs_lock2unlock_cnt_en_START (10)
#define SOC_MUDP_PHY_CS_CSR3_cs_lock2unlock_cnt_en_END (10)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_en_START (11)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_en_END (11)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2acq_en_START (12)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2acq_en_END (12)
#define SOC_MUDP_PHY_CS_CSR3_cs_acq2init_en_START (13)
#define SOC_MUDP_PHY_CS_CSR3_cs_acq2init_en_END (13)
#define SOC_MUDP_PHY_CS_CSR3_cs_ssc4kcal_en_START (14)
#define SOC_MUDP_PHY_CS_CSR3_cs_ssc4kcal_en_END (14)
#define SOC_MUDP_PHY_CS_CSR3_cs_pacq_en_START (15)
#define SOC_MUDP_PHY_CS_CSR3_cs_pacq_en_END (15)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_flag_gen_src_START (16)
#define SOC_MUDP_PHY_CS_CSR3_cs_unlock2init_flag_gen_src_END (16)
#define SOC_MUDP_PHY_CS_CSR3_cs_phs_err_flag_gen_mode_START (17)
#define SOC_MUDP_PHY_CS_CSR3_cs_phs_err_flag_gen_mode_END (17)
#define SOC_MUDP_PHY_CS_CSR3_cs_fast_lock_mode_START (18)
#define SOC_MUDP_PHY_CS_CSR3_cs_fast_lock_mode_END (18)
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_en_START (19)
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_en_END (19)
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_lock_flag_START (20)
#define SOC_MUDP_PHY_CS_CSR3_cs_adpll_lock_flag_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 20;
        unsigned int cs_lock_phe_th : 8;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MUDP_PHY_CS_CSR4_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR4_cs_lock_phe_th_START (20)
#define SOC_MUDP_PHY_CS_CSR4_cs_lock_phe_th_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_adpll_fsm_lock_flag : 1;
        unsigned int cs_afc_done : 1;
        unsigned int cs_afc_fail : 1;
        unsigned int cs_ssc_gen_state : 1;
        unsigned int cs_acq_lock : 1;
        unsigned int cs_start_lock : 1;
        unsigned int cs_unlock2init_flag : 1;
        unsigned int cs_unlock_flag : 1;
        unsigned int cs_curr_state : 4;
        unsigned int cs_acq2init_cnt : 5;
        unsigned int cs_unlock2acq_cnt : 5;
        unsigned int cs_unlock2init_cnt : 5;
        unsigned int cs_lock2unlock_cnt : 5;
    } reg;
} SOC_MUDP_PHY_CS_CSR5_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR5_cs_adpll_fsm_lock_flag_START (0)
#define SOC_MUDP_PHY_CS_CSR5_cs_adpll_fsm_lock_flag_END (0)
#define SOC_MUDP_PHY_CS_CSR5_cs_afc_done_START (1)
#define SOC_MUDP_PHY_CS_CSR5_cs_afc_done_END (1)
#define SOC_MUDP_PHY_CS_CSR5_cs_afc_fail_START (2)
#define SOC_MUDP_PHY_CS_CSR5_cs_afc_fail_END (2)
#define SOC_MUDP_PHY_CS_CSR5_cs_ssc_gen_state_START (3)
#define SOC_MUDP_PHY_CS_CSR5_cs_ssc_gen_state_END (3)
#define SOC_MUDP_PHY_CS_CSR5_cs_acq_lock_START (4)
#define SOC_MUDP_PHY_CS_CSR5_cs_acq_lock_END (4)
#define SOC_MUDP_PHY_CS_CSR5_cs_start_lock_START (5)
#define SOC_MUDP_PHY_CS_CSR5_cs_start_lock_END (5)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock2init_flag_START (6)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock2init_flag_END (6)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock_flag_START (7)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock_flag_END (7)
#define SOC_MUDP_PHY_CS_CSR5_cs_curr_state_START (8)
#define SOC_MUDP_PHY_CS_CSR5_cs_curr_state_END (11)
#define SOC_MUDP_PHY_CS_CSR5_cs_acq2init_cnt_START (12)
#define SOC_MUDP_PHY_CS_CSR5_cs_acq2init_cnt_END (16)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock2acq_cnt_START (17)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock2acq_cnt_END (21)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock2init_cnt_START (22)
#define SOC_MUDP_PHY_CS_CSR5_cs_unlock2init_cnt_END (26)
#define SOC_MUDP_PHY_CS_CSR5_cs_lock2unlock_cnt_START (27)
#define SOC_MUDP_PHY_CS_CSR5_cs_lock2unlock_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_kdtc_update_mu_fine : 8;
        unsigned int cs_kdtc_update_mu_kcal : 8;
        unsigned int cs_kdtc_update_src_kcal : 1;
        unsigned int cs_kdtc_update_src_fine : 1;
        unsigned int cs_dtc_test_code : 8;
        unsigned int cs_dtc_test_mode : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_CS_CSR6_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_mu_fine_START (0)
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_mu_fine_END (7)
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_mu_kcal_START (8)
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_mu_kcal_END (15)
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_src_kcal_START (16)
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_src_kcal_END (16)
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_src_fine_START (17)
#define SOC_MUDP_PHY_CS_CSR6_cs_kdtc_update_src_fine_END (17)
#define SOC_MUDP_PHY_CS_CSR6_cs_dtc_test_code_START (18)
#define SOC_MUDP_PHY_CS_CSR6_cs_dtc_test_code_END (25)
#define SOC_MUDP_PHY_CS_CSR6_cs_dtc_test_mode_START (26)
#define SOC_MUDP_PHY_CS_CSR6_cs_dtc_test_mode_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 15;
        unsigned int cs_tdev_compensate_k_update_mu_fine : 8;
        unsigned int cs_tdev_compensate_k_update_src : 1;
        unsigned int cs_tdev_compensate_en : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_MUDP_PHY_CS_CSR7_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR7_cs_tdev_compensate_k_update_mu_fine_START (15)
#define SOC_MUDP_PHY_CS_CSR7_cs_tdev_compensate_k_update_mu_fine_END (22)
#define SOC_MUDP_PHY_CS_CSR7_cs_tdev_compensate_k_update_src_START (23)
#define SOC_MUDP_PHY_CS_CSR7_cs_tdev_compensate_k_update_src_END (23)
#define SOC_MUDP_PHY_CS_CSR7_cs_tdev_compensate_en_START (24)
#define SOC_MUDP_PHY_CS_CSR7_cs_tdev_compensate_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_vco_k_update_mu_fine : 8;
        unsigned int reserved_0 : 15;
        unsigned int cs_vcok_lms_en : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MUDP_PHY_CS_CSR8_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR8_cs_vco_k_update_mu_fine_START (0)
#define SOC_MUDP_PHY_CS_CSR8_cs_vco_k_update_mu_fine_END (7)
#define SOC_MUDP_PHY_CS_CSR8_cs_vcok_lms_en_START (23)
#define SOC_MUDP_PHY_CS_CSR8_cs_vcok_lms_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tdev_compensate : 15;
        unsigned int reserved_0 : 1;
        unsigned int cs_vco_k_update_en : 1;
        unsigned int cs_tdev_compensate_k_update_en : 1;
        unsigned int cs_dtc_decoder_en : 1;
        unsigned int cs_dtc_k_update_en : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_MUDP_PHY_CS_CSR9_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR9_cs_tdev_compensate_START (0)
#define SOC_MUDP_PHY_CS_CSR9_cs_tdev_compensate_END (14)
#define SOC_MUDP_PHY_CS_CSR9_cs_vco_k_update_en_START (16)
#define SOC_MUDP_PHY_CS_CSR9_cs_vco_k_update_en_END (16)
#define SOC_MUDP_PHY_CS_CSR9_cs_tdev_compensate_k_update_en_START (17)
#define SOC_MUDP_PHY_CS_CSR9_cs_tdev_compensate_k_update_en_END (17)
#define SOC_MUDP_PHY_CS_CSR9_cs_dtc_decoder_en_START (18)
#define SOC_MUDP_PHY_CS_CSR9_cs_dtc_decoder_en_END (18)
#define SOC_MUDP_PHY_CS_CSR9_cs_dtc_k_update_en_START (19)
#define SOC_MUDP_PHY_CS_CSR9_cs_dtc_k_update_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_dtc_k_2decoder : 16;
        unsigned int cs_tdev_compensate_k_2pfd : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_MUDP_PHY_CS_CSR10_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR10_cs_dtc_k_2decoder_START (0)
#define SOC_MUDP_PHY_CS_CSR10_cs_dtc_k_2decoder_END (15)
#define SOC_MUDP_PHY_CS_CSR10_cs_tdev_compensate_k_2pfd_START (16)
#define SOC_MUDP_PHY_CS_CSR10_cs_tdev_compensate_k_2pfd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_dtc_code_f : 10;
        unsigned int cs_dtc_code_int : 8;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PHY_CS_CSR11_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR11_cs_dtc_code_f_START (0)
#define SOC_MUDP_PHY_CS_CSR11_cs_dtc_code_f_END (9)
#define SOC_MUDP_PHY_CS_CSR11_cs_dtc_code_int_START (10)
#define SOC_MUDP_PHY_CS_CSR11_cs_dtc_code_int_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_vco_k : 10;
        unsigned int cs_tdc_k : 16;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_PHY_CS_CSR12_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR12_cs_vco_k_START (0)
#define SOC_MUDP_PHY_CS_CSR12_cs_vco_k_END (9)
#define SOC_MUDP_PHY_CS_CSR12_cs_tdc_k_START (10)
#define SOC_MUDP_PHY_CS_CSR12_cs_tdc_k_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_ktdc_ssc : 11;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MUDP_PHY_CS_CSR13_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR13_cs_ktdc_ssc_START (0)
#define SOC_MUDP_PHY_CS_CSR13_cs_ktdc_ssc_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 10;
        unsigned int cs_phe_underbound_cnt_clr : 1;
        unsigned int cs_phe_overbound_cnt_clr : 1;
        unsigned int cs_phe_underbound_cnt_en : 1;
        unsigned int cs_phe_overbound_cnt_en : 1;
        unsigned int cs_large_ferr_th : 6;
        unsigned int cs_large_tdev_th : 8;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MUDP_PHY_CS_CSR14_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_underbound_cnt_clr_START (10)
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_underbound_cnt_clr_END (10)
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_overbound_cnt_clr_START (11)
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_overbound_cnt_clr_END (11)
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_underbound_cnt_en_START (12)
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_underbound_cnt_en_END (12)
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_overbound_cnt_en_START (13)
#define SOC_MUDP_PHY_CS_CSR14_cs_phe_overbound_cnt_en_END (13)
#define SOC_MUDP_PHY_CS_CSR14_cs_large_ferr_th_START (14)
#define SOC_MUDP_PHY_CS_CSR14_cs_large_ferr_th_END (19)
#define SOC_MUDP_PHY_CS_CSR14_cs_large_tdev_th_START (20)
#define SOC_MUDP_PHY_CS_CSR14_cs_large_tdev_th_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tdev_f : 16;
        unsigned int cs_tdev_i : 8;
        unsigned int cs_pfd_tdev_out_disable : 1;
        unsigned int cs_large_ferr : 1;
        unsigned int cs_large_tdev : 1;
        unsigned int cs_phe_underbound : 1;
        unsigned int cs_phe_overbound : 1;
        unsigned int cs_keep_loop_init : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_MUDP_PHY_CS_CSR15_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR15_cs_tdev_f_START (0)
#define SOC_MUDP_PHY_CS_CSR15_cs_tdev_f_END (15)
#define SOC_MUDP_PHY_CS_CSR15_cs_tdev_i_START (16)
#define SOC_MUDP_PHY_CS_CSR15_cs_tdev_i_END (23)
#define SOC_MUDP_PHY_CS_CSR15_cs_pfd_tdev_out_disable_START (24)
#define SOC_MUDP_PHY_CS_CSR15_cs_pfd_tdev_out_disable_END (24)
#define SOC_MUDP_PHY_CS_CSR15_cs_large_ferr_START (25)
#define SOC_MUDP_PHY_CS_CSR15_cs_large_ferr_END (25)
#define SOC_MUDP_PHY_CS_CSR15_cs_large_tdev_START (26)
#define SOC_MUDP_PHY_CS_CSR15_cs_large_tdev_END (26)
#define SOC_MUDP_PHY_CS_CSR15_cs_phe_underbound_START (27)
#define SOC_MUDP_PHY_CS_CSR15_cs_phe_underbound_END (27)
#define SOC_MUDP_PHY_CS_CSR15_cs_phe_overbound_START (28)
#define SOC_MUDP_PHY_CS_CSR15_cs_phe_overbound_END (28)
#define SOC_MUDP_PHY_CS_CSR15_cs_keep_loop_init_START (29)
#define SOC_MUDP_PHY_CS_CSR15_cs_keep_loop_init_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_phe_underbound_cnt : 5;
        unsigned int cs_phe_overbound_cnt : 5;
        unsigned int cs_reg_phe : 6;
        unsigned int cs_reg_fdw : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_PHY_CS_CSR16_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR16_cs_phe_underbound_cnt_START (0)
#define SOC_MUDP_PHY_CS_CSR16_cs_phe_underbound_cnt_END (4)
#define SOC_MUDP_PHY_CS_CSR16_cs_phe_overbound_cnt_START (5)
#define SOC_MUDP_PHY_CS_CSR16_cs_phe_overbound_cnt_END (9)
#define SOC_MUDP_PHY_CS_CSR16_cs_reg_phe_START (10)
#define SOC_MUDP_PHY_CS_CSR16_cs_reg_phe_END (15)
#define SOC_MUDP_PHY_CS_CSR16_cs_reg_fdw_START (16)
#define SOC_MUDP_PHY_CS_CSR16_cs_reg_fdw_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 12;
        unsigned int cs_ki_fine_ssc : 4;
        unsigned int cs_kp_fine_ssc : 8;
        unsigned int cs_abank_step_size : 2;
        unsigned int cs_tmode : 3;
        unsigned int cs_mash_dither_bypass : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_MUDP_PHY_CS_CSR17_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR17_cs_ki_fine_ssc_START (12)
#define SOC_MUDP_PHY_CS_CSR17_cs_ki_fine_ssc_END (15)
#define SOC_MUDP_PHY_CS_CSR17_cs_kp_fine_ssc_START (16)
#define SOC_MUDP_PHY_CS_CSR17_cs_kp_fine_ssc_END (23)
#define SOC_MUDP_PHY_CS_CSR17_cs_abank_step_size_START (24)
#define SOC_MUDP_PHY_CS_CSR17_cs_abank_step_size_END (25)
#define SOC_MUDP_PHY_CS_CSR17_cs_tmode_START (26)
#define SOC_MUDP_PHY_CS_CSR17_cs_tmode_END (28)
#define SOC_MUDP_PHY_CS_CSR17_cs_mash_dither_bypass_START (29)
#define SOC_MUDP_PHY_CS_CSR17_cs_mash_dither_bypass_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 8;
        unsigned int reserved_2: 20;
    } reg;
} SOC_MUDP_PHY_CS_CSR18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tcal_abank_code : 9;
        unsigned int cs_abank_code : 9;
        unsigned int cs_pbank_code : 7;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PHY_CS_CSR19_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR19_cs_tcal_abank_code_START (0)
#define SOC_MUDP_PHY_CS_CSR19_cs_tcal_abank_code_END (8)
#define SOC_MUDP_PHY_CS_CSR19_cs_abank_code_START (9)
#define SOC_MUDP_PHY_CS_CSR19_cs_abank_code_END (17)
#define SOC_MUDP_PHY_CS_CSR19_cs_pbank_code_START (18)
#define SOC_MUDP_PHY_CS_CSR19_cs_pbank_code_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tmode_rc_code_0 : 9;
        unsigned int cs_tmode_lpf_frac_code_0 : 9;
        unsigned int cs_tmode_lpf_int_code_0 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_CS_CSR20_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR20_cs_tmode_rc_code_0_START (0)
#define SOC_MUDP_PHY_CS_CSR20_cs_tmode_rc_code_0_END (8)
#define SOC_MUDP_PHY_CS_CSR20_cs_tmode_lpf_frac_code_0_START (9)
#define SOC_MUDP_PHY_CS_CSR20_cs_tmode_lpf_frac_code_0_END (17)
#define SOC_MUDP_PHY_CS_CSR20_cs_tmode_lpf_int_code_0_START (18)
#define SOC_MUDP_PHY_CS_CSR20_cs_tmode_lpf_int_code_0_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tmode_rc_code_1 : 9;
        unsigned int cs_tmode_lpf_frac_code_1 : 9;
        unsigned int cs_tmode_lpf_int_code_1 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_CS_CSR21_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR21_cs_tmode_rc_code_1_START (0)
#define SOC_MUDP_PHY_CS_CSR21_cs_tmode_rc_code_1_END (8)
#define SOC_MUDP_PHY_CS_CSR21_cs_tmode_lpf_frac_code_1_START (9)
#define SOC_MUDP_PHY_CS_CSR21_cs_tmode_lpf_frac_code_1_END (17)
#define SOC_MUDP_PHY_CS_CSR21_cs_tmode_lpf_int_code_1_START (18)
#define SOC_MUDP_PHY_CS_CSR21_cs_tmode_lpf_int_code_1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tsen_para_b : 10;
        unsigned int cs_tsen_para_k : 7;
        unsigned int cs_tsen_bypass : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PHY_CS_CSR22_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR22_cs_tsen_para_b_START (0)
#define SOC_MUDP_PHY_CS_CSR22_cs_tsen_para_b_END (9)
#define SOC_MUDP_PHY_CS_CSR22_cs_tsen_para_k_START (10)
#define SOC_MUDP_PHY_CS_CSR22_cs_tsen_para_k_END (16)
#define SOC_MUDP_PHY_CS_CSR22_cs_tsen_bypass_START (17)
#define SOC_MUDP_PHY_CS_CSR22_cs_tsen_bypass_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tsen_temp_in : 10;
        unsigned int cs_tsen_para_offset : 9;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_PHY_CS_CSR23_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR23_cs_tsen_temp_in_START (0)
#define SOC_MUDP_PHY_CS_CSR23_cs_tsen_temp_in_END (9)
#define SOC_MUDP_PHY_CS_CSR23_cs_tsen_para_offset_START (10)
#define SOC_MUDP_PHY_CS_CSR23_cs_tsen_para_offset_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_obsv_pbank_sel : 3;
        unsigned int cs_max_pbank_code : 7;
        unsigned int cs_afc_wait_time : 7;
        unsigned int cs_afc_diff_th : 3;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MUDP_PHY_CS_CSR24_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR24_cs_obsv_pbank_sel_START (0)
#define SOC_MUDP_PHY_CS_CSR24_cs_obsv_pbank_sel_END (2)
#define SOC_MUDP_PHY_CS_CSR24_cs_max_pbank_code_START (3)
#define SOC_MUDP_PHY_CS_CSR24_cs_max_pbank_code_END (9)
#define SOC_MUDP_PHY_CS_CSR24_cs_afc_wait_time_START (10)
#define SOC_MUDP_PHY_CS_CSR24_cs_afc_wait_time_END (16)
#define SOC_MUDP_PHY_CS_CSR24_cs_afc_diff_th_START (17)
#define SOC_MUDP_PHY_CS_CSR24_cs_afc_diff_th_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_obsv_diff_abs_first_s2 : 4;
        unsigned int cs_obsv_diff_abs_first_s1 : 4;
        unsigned int cs_obsv_pbank_transition_cnt : 4;
        unsigned int cs_obsv_pbank : 7;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_PHY_CS_CSR25_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_diff_abs_first_s2_START (0)
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_diff_abs_first_s2_END (3)
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_diff_abs_first_s1_START (4)
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_diff_abs_first_s1_END (7)
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_pbank_transition_cnt_START (8)
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_pbank_transition_cnt_END (11)
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_pbank_START (12)
#define SOC_MUDP_PHY_CS_CSR25_cs_obsv_pbank_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_ssc_qrt_perd_ncycle_cfg : 12;
        unsigned int cs_ssc_ppm_ofst_cfg : 10;
        unsigned int cs_ssc_ppm_ofst_gen_stepsize_cfg : 2;
        unsigned int cs_ssc_dynamic_shutoff_mode : 2;
        unsigned int cs_ssc_mode : 2;
        unsigned int cs_ssc_start_source_sel : 1;
        unsigned int cs_ssc_start : 1;
        unsigned int cs_ssc_en : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_MUDP_PHY_CS_CSR26_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_qrt_perd_ncycle_cfg_START (0)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_qrt_perd_ncycle_cfg_END (11)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_ppm_ofst_cfg_START (12)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_ppm_ofst_cfg_END (21)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_ppm_ofst_gen_stepsize_cfg_START (22)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_ppm_ofst_gen_stepsize_cfg_END (23)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_dynamic_shutoff_mode_START (24)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_dynamic_shutoff_mode_END (25)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_mode_START (26)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_mode_END (27)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_start_source_sel_START (28)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_start_source_sel_END (28)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_start_START (29)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_start_END (29)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_en_START (30)
#define SOC_MUDP_PHY_CS_CSR26_cs_ssc_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_ssc_step_size_cfg : 24;
        unsigned int cs_ssc_en_pin_st : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PHY_CS_CSR27_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR27_cs_ssc_step_size_cfg_START (0)
#define SOC_MUDP_PHY_CS_CSR27_cs_ssc_step_size_cfg_END (23)
#define SOC_MUDP_PHY_CS_CSR27_cs_ssc_en_pin_st_START (24)
#define SOC_MUDP_PHY_CS_CSR27_cs_ssc_en_pin_st_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_fcw_cfg : 32;
    } reg;
} SOC_MUDP_PHY_CS_CSR28_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR28_cs_fcw_cfg_START (0)
#define SOC_MUDP_PHY_CS_CSR28_cs_fcw_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int cs_fcw_reciprocal_cfg : 14;
        unsigned int reserved_4 : 7;
    } reg;
} SOC_MUDP_PHY_CS_CSR29_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR29_cs_fcw_reciprocal_cfg_START (11)
#define SOC_MUDP_PHY_CS_CSR29_cs_fcw_reciprocal_cfg_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_pbank_code_cfg : 7;
        unsigned int cs_abank_code_cfg : 9;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PHY_CS_CSR30_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR30_cs_pbank_code_cfg_START (0)
#define SOC_MUDP_PHY_CS_CSR30_cs_pbank_code_cfg_END (6)
#define SOC_MUDP_PHY_CS_CSR30_cs_abank_code_cfg_START (7)
#define SOC_MUDP_PHY_CS_CSR30_cs_abank_code_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tdev_compensate_k_cfg : 12;
        unsigned int cs_dtc_k2decoder_cfg : 16;
        unsigned int reserved : 4;
    } reg;
} SOC_MUDP_PHY_CS_CSR31_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR31_cs_tdev_compensate_k_cfg_START (0)
#define SOC_MUDP_PHY_CS_CSR31_cs_tdev_compensate_k_cfg_END (11)
#define SOC_MUDP_PHY_CS_CSR31_cs_dtc_k2decoder_cfg_START (12)
#define SOC_MUDP_PHY_CS_CSR31_cs_dtc_k2decoder_cfg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_lld_clr : 1;
        unsigned int cs_lld_once : 1;
        unsigned int cs_lld_start : 1;
        unsigned int cs_lld_wait_threshold : 10;
        unsigned int cs_lld_lck_threshold : 6;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_PHY_CS_CSR32_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_clr_START (0)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_clr_END (0)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_once_START (1)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_once_END (1)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_start_START (2)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_start_END (2)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_wait_threshold_START (3)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_wait_threshold_END (12)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_lck_threshold_START (13)
#define SOC_MUDP_PHY_CS_CSR32_cs_lld_lck_threshold_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_lld_fb_cnt_lv : 16;
        unsigned int cs_lld_ref_cnt_lv : 16;
    } reg;
} SOC_MUDP_PHY_CS_CSR33_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR33_cs_lld_fb_cnt_lv_START (0)
#define SOC_MUDP_PHY_CS_CSR33_cs_lld_fb_cnt_lv_END (15)
#define SOC_MUDP_PHY_CS_CSR33_cs_lld_ref_cnt_lv_START (16)
#define SOC_MUDP_PHY_CS_CSR33_cs_lld_ref_cnt_lv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_lld_done : 1;
        unsigned int cs_lld_lck_status : 1;
        unsigned int cs_lld_cmp_status : 1;
        unsigned int cs_lld_fd_state : 2;
        unsigned int cs_lld_fb_freq : 16;
        unsigned int cs_lld_history_status : 1;
        unsigned int cs_lld_history_clr : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_MUDP_PHY_CS_CSR34_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_done_START (0)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_done_END (0)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_lck_status_START (1)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_lck_status_END (1)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_cmp_status_START (2)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_cmp_status_END (2)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_fd_state_START (3)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_fd_state_END (4)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_fb_freq_START (5)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_fb_freq_END (20)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_history_status_START (21)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_history_status_END (21)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_history_clr_START (22)
#define SOC_MUDP_PHY_CS_CSR34_cs_lld_history_clr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_lld_ref_freq : 16;
        unsigned int cs_lld_diff_freq : 16;
    } reg;
} SOC_MUDP_PHY_CS_CSR35_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR35_cs_lld_ref_freq_START (0)
#define SOC_MUDP_PHY_CS_CSR35_cs_lld_ref_freq_END (15)
#define SOC_MUDP_PHY_CS_CSR35_cs_lld_diff_freq_START (16)
#define SOC_MUDP_PHY_CS_CSR35_cs_lld_diff_freq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_CS_CSR36_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_CS_CSR37_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_soft_int : 1;
        unsigned int reserved_0 : 1;
        unsigned int cs_calib_gcal_int : 1;
        unsigned int cs_lcpll_afc_fail_int : 1;
        unsigned int cs_lcpll_lock2unlock_int : 1;
        unsigned int rom_ecc_multi_err_int : 1;
        unsigned int cs_rom_ecc_err_int : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_MUDP_PHY_CS_CSR38_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR38_cs_soft_int_START (0)
#define SOC_MUDP_PHY_CS_CSR38_cs_soft_int_END (0)
#define SOC_MUDP_PHY_CS_CSR38_cs_calib_gcal_int_START (2)
#define SOC_MUDP_PHY_CS_CSR38_cs_calib_gcal_int_END (2)
#define SOC_MUDP_PHY_CS_CSR38_cs_lcpll_afc_fail_int_START (3)
#define SOC_MUDP_PHY_CS_CSR38_cs_lcpll_afc_fail_int_END (3)
#define SOC_MUDP_PHY_CS_CSR38_cs_lcpll_lock2unlock_int_START (4)
#define SOC_MUDP_PHY_CS_CSR38_cs_lcpll_lock2unlock_int_END (4)
#define SOC_MUDP_PHY_CS_CSR38_rom_ecc_multi_err_int_START (5)
#define SOC_MUDP_PHY_CS_CSR38_rom_ecc_multi_err_int_END (5)
#define SOC_MUDP_PHY_CS_CSR38_cs_rom_ecc_err_int_START (6)
#define SOC_MUDP_PHY_CS_CSR38_cs_rom_ecc_err_int_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_soft_int_source : 1;
        unsigned int reserved_0 : 1;
        unsigned int cs_calib_gcal_int_source : 1;
        unsigned int lcpll_afc_fail_int_source : 1;
        unsigned int lcpll_lock2unlock_int_source : 1;
        unsigned int rom_ecc_multi_err_int_source : 1;
        unsigned int rom_ecc_err_int_source : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_MUDP_PHY_CS_CSR39_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR39_cs_soft_int_source_START (0)
#define SOC_MUDP_PHY_CS_CSR39_cs_soft_int_source_END (0)
#define SOC_MUDP_PHY_CS_CSR39_cs_calib_gcal_int_source_START (2)
#define SOC_MUDP_PHY_CS_CSR39_cs_calib_gcal_int_source_END (2)
#define SOC_MUDP_PHY_CS_CSR39_lcpll_afc_fail_int_source_START (3)
#define SOC_MUDP_PHY_CS_CSR39_lcpll_afc_fail_int_source_END (3)
#define SOC_MUDP_PHY_CS_CSR39_lcpll_lock2unlock_int_source_START (4)
#define SOC_MUDP_PHY_CS_CSR39_lcpll_lock2unlock_int_source_END (4)
#define SOC_MUDP_PHY_CS_CSR39_rom_ecc_multi_err_int_source_START (5)
#define SOC_MUDP_PHY_CS_CSR39_rom_ecc_multi_err_int_source_END (5)
#define SOC_MUDP_PHY_CS_CSR39_rom_ecc_err_int_source_START (6)
#define SOC_MUDP_PHY_CS_CSR39_rom_ecc_err_int_source_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_soft_int_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int cs_calib_gcal_int_mask : 1;
        unsigned int cs_lcpll_afc_fail_int_mask : 1;
        unsigned int lcpll_lock2unlock_int_mask : 1;
        unsigned int rom_ecc_multi_err_int_mask : 1;
        unsigned int rom_ecc_err_int_mask : 1;
        unsigned int cs_dtb_out_sel : 4;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_MUDP_PHY_CS_CSR40_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR40_cs_soft_int_mask_START (0)
#define SOC_MUDP_PHY_CS_CSR40_cs_soft_int_mask_END (0)
#define SOC_MUDP_PHY_CS_CSR40_cs_calib_gcal_int_mask_START (2)
#define SOC_MUDP_PHY_CS_CSR40_cs_calib_gcal_int_mask_END (2)
#define SOC_MUDP_PHY_CS_CSR40_cs_lcpll_afc_fail_int_mask_START (3)
#define SOC_MUDP_PHY_CS_CSR40_cs_lcpll_afc_fail_int_mask_END (3)
#define SOC_MUDP_PHY_CS_CSR40_lcpll_lock2unlock_int_mask_START (4)
#define SOC_MUDP_PHY_CS_CSR40_lcpll_lock2unlock_int_mask_END (4)
#define SOC_MUDP_PHY_CS_CSR40_rom_ecc_multi_err_int_mask_START (5)
#define SOC_MUDP_PHY_CS_CSR40_rom_ecc_multi_err_int_mask_END (5)
#define SOC_MUDP_PHY_CS_CSR40_rom_ecc_err_int_mask_START (6)
#define SOC_MUDP_PHY_CS_CSR40_rom_ecc_err_int_mask_END (6)
#define SOC_MUDP_PHY_CS_CSR40_cs_dtb_out_sel_START (7)
#define SOC_MUDP_PHY_CS_CSR40_cs_dtb_out_sel_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_spare_in : 2;
        unsigned int cs_spare_out : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_MUDP_PHY_CS_CSR41_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR41_cs_spare_in_START (0)
#define SOC_MUDP_PHY_CS_CSR41_cs_spare_in_END (1)
#define SOC_MUDP_PHY_CS_CSR41_cs_spare_out_START (2)
#define SOC_MUDP_PHY_CS_CSR41_cs_spare_out_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_dig_spare0 : 32;
    } reg;
} SOC_MUDP_PHY_CS_CSR42_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR42_cs_dig_spare0_START (0)
#define SOC_MUDP_PHY_CS_CSR42_cs_dig_spare0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_dig_spare1 : 32;
    } reg;
} SOC_MUDP_PHY_CS_CSR43_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR43_cs_dig_spare1_START (0)
#define SOC_MUDP_PHY_CS_CSR43_cs_dig_spare1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_rom_ecc_err_cnt : 4;
        unsigned int cs_rom_ecc_multi_err_addr : 13;
        unsigned int reserved : 15;
    } reg;
} SOC_MUDP_PHY_CS_CSR44_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR44_cs_rom_ecc_err_cnt_START (0)
#define SOC_MUDP_PHY_CS_CSR44_cs_rom_ecc_err_cnt_END (3)
#define SOC_MUDP_PHY_CS_CSR44_cs_rom_ecc_multi_err_addr_START (4)
#define SOC_MUDP_PHY_CS_CSR44_cs_rom_ecc_multi_err_addr_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_s12_rom_tmode : 8;
        unsigned int cs_c2x_rom_tmode : 8;
        unsigned int cs_ruby_rom_tmode : 8;
        unsigned int cs_rom_shut_down : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PHY_CS_CSR45_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR45_cs_s12_rom_tmode_START (0)
#define SOC_MUDP_PHY_CS_CSR45_cs_s12_rom_tmode_END (7)
#define SOC_MUDP_PHY_CS_CSR45_cs_c2x_rom_tmode_START (8)
#define SOC_MUDP_PHY_CS_CSR45_cs_c2x_rom_tmode_END (15)
#define SOC_MUDP_PHY_CS_CSR45_cs_ruby_rom_tmode_START (16)
#define SOC_MUDP_PHY_CS_CSR45_cs_ruby_rom_tmode_END (23)
#define SOC_MUDP_PHY_CS_CSR45_cs_rom_shut_down_START (24)
#define SOC_MUDP_PHY_CS_CSR45_cs_rom_shut_down_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_CS_CSR46_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_tdev_compensate_k_update_coarse_cnt_th : 7;
        unsigned int cs_tdev_compensate_k_update_mu_coarse : 8;
        unsigned int cs_vco_k_update_coarse_cnt_th : 7;
        unsigned int cs_vco_k_update_mu_coarse : 8;
        unsigned int reserved : 2;
    } reg;
} SOC_MUDP_PHY_CS_CSR47_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR47_cs_tdev_compensate_k_update_coarse_cnt_th_START (0)
#define SOC_MUDP_PHY_CS_CSR47_cs_tdev_compensate_k_update_coarse_cnt_th_END (6)
#define SOC_MUDP_PHY_CS_CSR47_cs_tdev_compensate_k_update_mu_coarse_START (7)
#define SOC_MUDP_PHY_CS_CSR47_cs_tdev_compensate_k_update_mu_coarse_END (14)
#define SOC_MUDP_PHY_CS_CSR47_cs_vco_k_update_coarse_cnt_th_START (15)
#define SOC_MUDP_PHY_CS_CSR47_cs_vco_k_update_coarse_cnt_th_END (21)
#define SOC_MUDP_PHY_CS_CSR47_cs_vco_k_update_mu_coarse_START (22)
#define SOC_MUDP_PHY_CS_CSR47_cs_vco_k_update_mu_coarse_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_adpll_loop_gain_dynamic_ctrl_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int cs_loop_gain_steptime : 6;
        unsigned int reserved_1 : 2;
        unsigned int cs_kp_step : 4;
        unsigned int cs_ki_step : 2;
        unsigned int reserved_2 : 2;
        unsigned int ktdc_step : 5;
        unsigned int reserved_3 : 7;
    } reg;
} SOC_MUDP_PHY_CS_CSR48_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR48_cs_adpll_loop_gain_dynamic_ctrl_en_START (0)
#define SOC_MUDP_PHY_CS_CSR48_cs_adpll_loop_gain_dynamic_ctrl_en_END (0)
#define SOC_MUDP_PHY_CS_CSR48_cs_loop_gain_steptime_START (4)
#define SOC_MUDP_PHY_CS_CSR48_cs_loop_gain_steptime_END (9)
#define SOC_MUDP_PHY_CS_CSR48_cs_kp_step_START (12)
#define SOC_MUDP_PHY_CS_CSR48_cs_kp_step_END (15)
#define SOC_MUDP_PHY_CS_CSR48_cs_ki_step_START (16)
#define SOC_MUDP_PHY_CS_CSR48_cs_ki_step_END (17)
#define SOC_MUDP_PHY_CS_CSR48_ktdc_step_START (20)
#define SOC_MUDP_PHY_CS_CSR48_ktdc_step_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csbiasmst_bgbuffer_pwrdnb : 1;
        unsigned int csbiasmst_icc_voutbps : 2;
        unsigned int reserved_0 : 1;
        unsigned int csbiasmst_bgbuf_srcfollow_sel : 1;
        unsigned int csbiasmst_bufcal_enb : 1;
        unsigned int csbiasmst_bufoft_gray : 5;
        unsigned int csbiasmst_vbg_chopclk_source_selb : 1;
        unsigned int reserved_1 : 2;
        unsigned int csbiasmst_vbg_tcadj_dec : 3;
        unsigned int csbiasmst_vbg_chopclk_mode : 1;
        unsigned int csbiasmst_vbg_demclk_mode : 1;
        unsigned int csbiasmst_vbg_level_dec : 3;
        unsigned int csbiasmst_vbg_rstb : 1;
        unsigned int csbiasmst_vbg_enb_dem : 1;
        unsigned int csbiasmst_vbg_enb_chop : 1;
        unsigned int reserved_2 : 1;
        unsigned int csbiasmst_vbg_force_stup : 1;
        unsigned int csbiasmst_vbg_bypassb : 1;
        unsigned int csbiasmst_vbg_pwrdnb : 1;
        unsigned int csbiasmst_vbg_fast_stup : 1;
        unsigned int csbiasmst_icv_pwrdnb : 1;
        unsigned int csbiasmst_icc_pwrdnb : 1;
    } reg;
} SOC_MUDP_PHY_CS_CSR49_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bgbuffer_pwrdnb_START (0)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bgbuffer_pwrdnb_END (0)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_icc_voutbps_START (1)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_icc_voutbps_END (2)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bgbuf_srcfollow_sel_START (4)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bgbuf_srcfollow_sel_END (4)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bufcal_enb_START (5)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bufcal_enb_END (5)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bufoft_gray_START (6)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_bufoft_gray_END (10)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_chopclk_source_selb_START (11)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_chopclk_source_selb_END (11)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_tcadj_dec_START (14)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_tcadj_dec_END (16)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_chopclk_mode_START (17)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_chopclk_mode_END (17)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_demclk_mode_START (18)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_demclk_mode_END (18)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_level_dec_START (19)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_level_dec_END (21)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_rstb_START (22)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_rstb_END (22)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_enb_dem_START (23)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_enb_dem_END (23)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_enb_chop_START (24)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_enb_chop_END (24)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_force_stup_START (26)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_force_stup_END (26)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_bypassb_START (27)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_bypassb_END (27)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_pwrdnb_START (28)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_pwrdnb_END (28)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_fast_stup_START (29)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_vbg_fast_stup_END (29)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_icv_pwrdnb_START (30)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_icv_pwrdnb_END (30)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_icc_pwrdnb_START (31)
#define SOC_MUDP_PHY_CS_CSR49_csbiasmst_icc_pwrdnb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cspll_div7_pwrdnb : 1;
        unsigned int cspll_div6_pwrdnb : 1;
        unsigned int cspll_div5_pwrdnb : 1;
        unsigned int cs_refclk_term_mode : 2;
        unsigned int cs_refclk_bump_hys_sel : 2;
        unsigned int cs_refclk_bump_hys_en : 1;
        unsigned int cs_refclk2lcpll_sel : 1;
        unsigned int cs_refclk_glitch_cancel_en : 1;
        unsigned int cs_refclk_sel_frompin : 1;
        unsigned int cs_refclk_rep_pwrdnb_frompin : 1;
        unsigned int csbiasmst_atb_sel : 6;
        unsigned int csbiasmst_vgs_sensor_atb_sel : 5;
        unsigned int csbiasmst_icv_dcogm_sel : 5;
        unsigned int csbiasmst_icv_vrefbps : 2;
        unsigned int csbiasmst_icv_igenbps : 2;
    } reg;
} SOC_MUDP_PHY_CS_CSR50_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR50_cspll_div7_pwrdnb_START (0)
#define SOC_MUDP_PHY_CS_CSR50_cspll_div7_pwrdnb_END (0)
#define SOC_MUDP_PHY_CS_CSR50_cspll_div6_pwrdnb_START (1)
#define SOC_MUDP_PHY_CS_CSR50_cspll_div6_pwrdnb_END (1)
#define SOC_MUDP_PHY_CS_CSR50_cspll_div5_pwrdnb_START (2)
#define SOC_MUDP_PHY_CS_CSR50_cspll_div5_pwrdnb_END (2)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_term_mode_START (3)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_term_mode_END (4)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_bump_hys_sel_START (5)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_bump_hys_sel_END (6)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_bump_hys_en_START (7)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_bump_hys_en_END (7)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk2lcpll_sel_START (8)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk2lcpll_sel_END (8)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_glitch_cancel_en_START (9)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_glitch_cancel_en_END (9)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_sel_frompin_START (10)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_sel_frompin_END (10)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_rep_pwrdnb_frompin_START (11)
#define SOC_MUDP_PHY_CS_CSR50_cs_refclk_rep_pwrdnb_frompin_END (11)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_atb_sel_START (12)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_atb_sel_END (17)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_vgs_sensor_atb_sel_START (18)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_vgs_sensor_atb_sel_END (22)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_icv_dcogm_sel_START (23)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_icv_dcogm_sel_END (27)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_icv_vrefbps_START (28)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_icv_vrefbps_END (29)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_icv_igenbps_START (30)
#define SOC_MUDP_PHY_CS_CSR50_csbiasmst_icv_igenbps_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csreg_pfd_overshoot_ctrl : 2;
        unsigned int csreg_pfd_eospro_dio_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int cspll_tdc_test_mode : 1;
        unsigned int cspll_tdc_allhi : 1;
        unsigned int cspll_dco_bias_sel : 1;
        unsigned int reserved_1 : 1;
        unsigned int cspll_tdc_ref_dly_sel : 2;
        unsigned int cspll_refdiv_sel : 2;
        unsigned int cspll_dtc_bypass : 1;
        unsigned int reserved_2 : 5;
        unsigned int cspll_div_ka_sel : 2;
        unsigned int csreg_htol_en : 1;
        unsigned int reserved_3 : 5;
        unsigned int cspll_divw_pwrdnb : 1;
        unsigned int cspll_div15_pwrdnb : 1;
        unsigned int cspll_div11_pwrdnb : 1;
        unsigned int cspll_div9_pwrdnb : 1;
    } reg;
} SOC_MUDP_PHY_CS_CSR51_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR51_csreg_pfd_overshoot_ctrl_START (0)
#define SOC_MUDP_PHY_CS_CSR51_csreg_pfd_overshoot_ctrl_END (1)
#define SOC_MUDP_PHY_CS_CSR51_csreg_pfd_eospro_dio_en_START (2)
#define SOC_MUDP_PHY_CS_CSR51_csreg_pfd_eospro_dio_en_END (2)
#define SOC_MUDP_PHY_CS_CSR51_cspll_tdc_test_mode_START (6)
#define SOC_MUDP_PHY_CS_CSR51_cspll_tdc_test_mode_END (6)
#define SOC_MUDP_PHY_CS_CSR51_cspll_tdc_allhi_START (7)
#define SOC_MUDP_PHY_CS_CSR51_cspll_tdc_allhi_END (7)
#define SOC_MUDP_PHY_CS_CSR51_cspll_dco_bias_sel_START (8)
#define SOC_MUDP_PHY_CS_CSR51_cspll_dco_bias_sel_END (8)
#define SOC_MUDP_PHY_CS_CSR51_cspll_tdc_ref_dly_sel_START (10)
#define SOC_MUDP_PHY_CS_CSR51_cspll_tdc_ref_dly_sel_END (11)
#define SOC_MUDP_PHY_CS_CSR51_cspll_refdiv_sel_START (12)
#define SOC_MUDP_PHY_CS_CSR51_cspll_refdiv_sel_END (13)
#define SOC_MUDP_PHY_CS_CSR51_cspll_dtc_bypass_START (14)
#define SOC_MUDP_PHY_CS_CSR51_cspll_dtc_bypass_END (14)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div_ka_sel_START (20)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div_ka_sel_END (21)
#define SOC_MUDP_PHY_CS_CSR51_csreg_htol_en_START (22)
#define SOC_MUDP_PHY_CS_CSR51_csreg_htol_en_END (22)
#define SOC_MUDP_PHY_CS_CSR51_cspll_divw_pwrdnb_START (28)
#define SOC_MUDP_PHY_CS_CSR51_cspll_divw_pwrdnb_END (28)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div15_pwrdnb_START (29)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div15_pwrdnb_END (29)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div11_pwrdnb_START (30)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div11_pwrdnb_END (30)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div9_pwrdnb_START (31)
#define SOC_MUDP_PHY_CS_CSR51_cspll_div9_pwrdnb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_adc_tst_enb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cs_adc_input_sel : 3;
        unsigned int cs_adc_tsensor_tst_enb : 1;
        unsigned int cs_adc_pwrdnb : 1;
        unsigned int csreg_dco_atb_ctrl : 3;
        unsigned int csreg_dco_bypassb : 1;
        unsigned int csreg_dco_overshoot_ctrl : 2;
        unsigned int csreg_dco_vref_sel : 5;
        unsigned int csreg_dco_eospro_dio_en : 1;
        unsigned int csreg_dco_fast_startup : 1;
        unsigned int csreg_clk_fast_startup : 1;
        unsigned int csreg_pfd_fast_startup : 1;
        unsigned int cspll_dcobuff_supply_sel : 1;
        unsigned int csreg_pfd_atb_ctrl : 3;
        unsigned int csreg_pfd_bypassb : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_MUDP_PHY_CS_CSR52_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_tst_enb_START (0)
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_tst_enb_END (0)
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_input_sel_START (3)
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_input_sel_END (5)
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_tsensor_tst_enb_START (6)
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_tsensor_tst_enb_END (6)
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_pwrdnb_START (7)
#define SOC_MUDP_PHY_CS_CSR52_cs_adc_pwrdnb_END (7)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_atb_ctrl_START (8)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_atb_ctrl_END (10)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_bypassb_START (11)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_bypassb_END (11)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_overshoot_ctrl_START (12)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_overshoot_ctrl_END (13)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_vref_sel_START (14)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_vref_sel_END (18)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_eospro_dio_en_START (19)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_eospro_dio_en_END (19)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_fast_startup_START (20)
#define SOC_MUDP_PHY_CS_CSR52_csreg_dco_fast_startup_END (20)
#define SOC_MUDP_PHY_CS_CSR52_csreg_clk_fast_startup_START (21)
#define SOC_MUDP_PHY_CS_CSR52_csreg_clk_fast_startup_END (21)
#define SOC_MUDP_PHY_CS_CSR52_csreg_pfd_fast_startup_START (22)
#define SOC_MUDP_PHY_CS_CSR52_csreg_pfd_fast_startup_END (22)
#define SOC_MUDP_PHY_CS_CSR52_cspll_dcobuff_supply_sel_START (23)
#define SOC_MUDP_PHY_CS_CSR52_cspll_dcobuff_supply_sel_END (23)
#define SOC_MUDP_PHY_CS_CSR52_csreg_pfd_atb_ctrl_START (24)
#define SOC_MUDP_PHY_CS_CSR52_csreg_pfd_atb_ctrl_END (26)
#define SOC_MUDP_PHY_CS_CSR52_csreg_pfd_bypassb_START (27)
#define SOC_MUDP_PHY_CS_CSR52_csreg_pfd_bypassb_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_hsclk_supply_sel : 1;
        unsigned int cspwr_supply_half_sense : 2;
        unsigned int csatb_top : 3;
        unsigned int csatb_tsensor_vbesel : 2;
        unsigned int csatb_ss : 3;
        unsigned int csatb_pin_top : 3;
        unsigned int csatb_adc_sigsel : 2;
        unsigned int reserved_0 : 1;
        unsigned int cs_comp_otb_sel : 2;
        unsigned int cs_comp_atb_sel : 3;
        unsigned int reserved_1 : 1;
        unsigned int cs_comp_mode_sel : 1;
        unsigned int cs_comp_pwrdnb : 1;
        unsigned int cs_adc_output : 1;
        unsigned int cs_adc_iref_sel : 2;
        unsigned int cs_adc_abs_meas_enb : 1;
        unsigned int cs_adc_out_gating : 1;
        unsigned int adc_vcm_ctrl : 2;
    } reg;
} SOC_MUDP_PHY_CS_CSR53_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR53_cs_hsclk_supply_sel_START (0)
#define SOC_MUDP_PHY_CS_CSR53_cs_hsclk_supply_sel_END (0)
#define SOC_MUDP_PHY_CS_CSR53_cspwr_supply_half_sense_START (1)
#define SOC_MUDP_PHY_CS_CSR53_cspwr_supply_half_sense_END (2)
#define SOC_MUDP_PHY_CS_CSR53_csatb_top_START (3)
#define SOC_MUDP_PHY_CS_CSR53_csatb_top_END (5)
#define SOC_MUDP_PHY_CS_CSR53_csatb_tsensor_vbesel_START (6)
#define SOC_MUDP_PHY_CS_CSR53_csatb_tsensor_vbesel_END (7)
#define SOC_MUDP_PHY_CS_CSR53_csatb_ss_START (8)
#define SOC_MUDP_PHY_CS_CSR53_csatb_ss_END (10)
#define SOC_MUDP_PHY_CS_CSR53_csatb_pin_top_START (11)
#define SOC_MUDP_PHY_CS_CSR53_csatb_pin_top_END (13)
#define SOC_MUDP_PHY_CS_CSR53_csatb_adc_sigsel_START (14)
#define SOC_MUDP_PHY_CS_CSR53_csatb_adc_sigsel_END (15)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_otb_sel_START (17)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_otb_sel_END (18)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_atb_sel_START (19)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_atb_sel_END (21)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_mode_sel_START (23)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_mode_sel_END (23)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_pwrdnb_START (24)
#define SOC_MUDP_PHY_CS_CSR53_cs_comp_pwrdnb_END (24)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_output_START (25)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_output_END (25)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_iref_sel_START (26)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_iref_sel_END (27)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_abs_meas_enb_START (28)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_abs_meas_enb_END (28)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_out_gating_START (29)
#define SOC_MUDP_PHY_CS_CSR53_cs_adc_out_gating_END (29)
#define SOC_MUDP_PHY_CS_CSR53_adc_vcm_ctrl_START (30)
#define SOC_MUDP_PHY_CS_CSR53_adc_vcm_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cspll_ctb_en : 1;
        unsigned int cscp_ctb_pwrdnb : 1;
        unsigned int cs_spare : 8;
        unsigned int cs_txdrv_up_cal : 4;
        unsigned int cs_txdrv_dn_cal : 4;
        unsigned int cs_txdrv_slice_short : 1;
        unsigned int cs_txdrv_slice_open : 1;
        unsigned int cs_txdrv_slice_en : 1;
        unsigned int cs_rxterm_cal_enb : 1;
        unsigned int cs_txterm_cal_iccp_pwrdnb : 1;
        unsigned int cs_txterm_cal_iccn_pwrdnb : 1;
        unsigned int reserved_0 : 1;
        unsigned int csreg_pfd_vref_sel : 5;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_MUDP_PHY_CS_CSR54_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR54_cspll_ctb_en_START (0)
#define SOC_MUDP_PHY_CS_CSR54_cspll_ctb_en_END (0)
#define SOC_MUDP_PHY_CS_CSR54_cscp_ctb_pwrdnb_START (1)
#define SOC_MUDP_PHY_CS_CSR54_cscp_ctb_pwrdnb_END (1)
#define SOC_MUDP_PHY_CS_CSR54_cs_spare_START (2)
#define SOC_MUDP_PHY_CS_CSR54_cs_spare_END (9)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_up_cal_START (10)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_up_cal_END (13)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_dn_cal_START (14)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_dn_cal_END (17)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_slice_short_START (18)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_slice_short_END (18)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_slice_open_START (19)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_slice_open_END (19)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_slice_en_START (20)
#define SOC_MUDP_PHY_CS_CSR54_cs_txdrv_slice_en_END (20)
#define SOC_MUDP_PHY_CS_CSR54_cs_rxterm_cal_enb_START (21)
#define SOC_MUDP_PHY_CS_CSR54_cs_rxterm_cal_enb_END (21)
#define SOC_MUDP_PHY_CS_CSR54_cs_txterm_cal_iccp_pwrdnb_START (22)
#define SOC_MUDP_PHY_CS_CSR54_cs_txterm_cal_iccp_pwrdnb_END (22)
#define SOC_MUDP_PHY_CS_CSR54_cs_txterm_cal_iccn_pwrdnb_START (23)
#define SOC_MUDP_PHY_CS_CSR54_cs_txterm_cal_iccn_pwrdnb_END (23)
#define SOC_MUDP_PHY_CS_CSR54_csreg_pfd_vref_sel_START (25)
#define SOC_MUDP_PHY_CS_CSR54_csreg_pfd_vref_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int csreg_clk_atb_ctrl : 3;
        unsigned int csreg_clk_bypassb : 1;
        unsigned int csreg_clk_overshoot_ctrl : 2;
        unsigned int csreg_clk_vref_sel : 5;
        unsigned int csreg_eospro_dio_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int cscp_hsclkind_drv2n_ctrl : 2;
        unsigned int cscp_hsclkind_drv2s_ctrl : 2;
        unsigned int reserved_2 : 4;
        unsigned int cscp_hsclkind_drv2n_pwrdnb : 1;
        unsigned int cscp_hsclkind_drv2s_pwrdnb : 1;
        unsigned int cscp_ctb_local_sel : 4;
    } reg;
} SOC_MUDP_PHY_CS_CSR55_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_atb_ctrl_START (4)
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_atb_ctrl_END (6)
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_bypassb_START (7)
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_bypassb_END (7)
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_overshoot_ctrl_START (8)
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_overshoot_ctrl_END (9)
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_vref_sel_START (10)
#define SOC_MUDP_PHY_CS_CSR55_csreg_clk_vref_sel_END (14)
#define SOC_MUDP_PHY_CS_CSR55_csreg_eospro_dio_en_START (15)
#define SOC_MUDP_PHY_CS_CSR55_csreg_eospro_dio_en_END (15)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2n_ctrl_START (18)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2n_ctrl_END (19)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2s_ctrl_START (20)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2s_ctrl_END (21)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2n_pwrdnb_START (26)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2n_pwrdnb_END (26)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2s_pwrdnb_START (27)
#define SOC_MUDP_PHY_CS_CSR55_cscp_hsclkind_drv2s_pwrdnb_END (27)
#define SOC_MUDP_PHY_CS_CSR55_cscp_ctb_local_sel_START (28)
#define SOC_MUDP_PHY_CS_CSR55_cscp_ctb_local_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_hsclk_vreg_pgate_pwrdnb : 1;
        unsigned int csreg_clk_bleed_en : 1;
        unsigned int csreg_clk_ref_pwrdnb : 1;
        unsigned int csreg_dco_ref_pwrdnb : 1;
        unsigned int csreg_pfd_ref_pwrdnb : 1;
        unsigned int csreg_pfd_bleed_en : 1;
        unsigned int csreg_dco_bleed_en : 1;
        unsigned int csreg_pfd_pgate_pwrdnb : 1;
        unsigned int csreg_dco_pgate_pwrdnb : 1;
        unsigned int csreg_dco_pwrdnb : 1;
        unsigned int csreg_pfd_pwrdnb : 1;
        unsigned int csreg_clk_pgate_pwrdnb : 1;
        unsigned int csreg_clk_pwrdnb : 1;
        unsigned int cspll_km_pwrdnb : 1;
        unsigned int cs_refclk_pwrdnb_frompin : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_MUDP_PHY_CS_CSR56_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR56_cs_hsclk_vreg_pgate_pwrdnb_START (0)
#define SOC_MUDP_PHY_CS_CSR56_cs_hsclk_vreg_pgate_pwrdnb_END (0)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_bleed_en_START (1)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_bleed_en_END (1)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_ref_pwrdnb_START (2)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_ref_pwrdnb_END (2)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_ref_pwrdnb_START (3)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_ref_pwrdnb_END (3)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_ref_pwrdnb_START (4)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_ref_pwrdnb_END (4)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_bleed_en_START (5)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_bleed_en_END (5)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_bleed_en_START (6)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_bleed_en_END (6)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_pgate_pwrdnb_START (7)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_pgate_pwrdnb_END (7)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_pgate_pwrdnb_START (8)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_pgate_pwrdnb_END (8)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_pwrdnb_START (9)
#define SOC_MUDP_PHY_CS_CSR56_csreg_dco_pwrdnb_END (9)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_pwrdnb_START (10)
#define SOC_MUDP_PHY_CS_CSR56_csreg_pfd_pwrdnb_END (10)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_pgate_pwrdnb_START (11)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_pgate_pwrdnb_END (11)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_pwrdnb_START (12)
#define SOC_MUDP_PHY_CS_CSR56_csreg_clk_pwrdnb_END (12)
#define SOC_MUDP_PHY_CS_CSR56_cspll_km_pwrdnb_START (13)
#define SOC_MUDP_PHY_CS_CSR56_cspll_km_pwrdnb_END (13)
#define SOC_MUDP_PHY_CS_CSR56_cs_refclk_pwrdnb_frompin_START (14)
#define SOC_MUDP_PHY_CS_CSR56_cs_refclk_pwrdnb_frompin_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cspll_div_km_sel : 3;
        unsigned int cspll_div_kf_sel : 2;
        unsigned int cs_ktdc : 11;
        unsigned int cs_dtc_bypass : 1;
        unsigned int cs_afc_cnt_mode : 2;
        unsigned int cs_ki_coarse : 4;
        unsigned int cs_kp_coarse : 8;
        unsigned int cs_kckd_hs_div : 1;
    } reg;
} SOC_MUDP_PHY_CS_CSR57_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR57_cspll_div_km_sel_START (0)
#define SOC_MUDP_PHY_CS_CSR57_cspll_div_km_sel_END (2)
#define SOC_MUDP_PHY_CS_CSR57_cspll_div_kf_sel_START (3)
#define SOC_MUDP_PHY_CS_CSR57_cspll_div_kf_sel_END (4)
#define SOC_MUDP_PHY_CS_CSR57_cs_ktdc_START (5)
#define SOC_MUDP_PHY_CS_CSR57_cs_ktdc_END (15)
#define SOC_MUDP_PHY_CS_CSR57_cs_dtc_bypass_START (16)
#define SOC_MUDP_PHY_CS_CSR57_cs_dtc_bypass_END (16)
#define SOC_MUDP_PHY_CS_CSR57_cs_afc_cnt_mode_START (17)
#define SOC_MUDP_PHY_CS_CSR57_cs_afc_cnt_mode_END (18)
#define SOC_MUDP_PHY_CS_CSR57_cs_ki_coarse_START (19)
#define SOC_MUDP_PHY_CS_CSR57_cs_ki_coarse_END (22)
#define SOC_MUDP_PHY_CS_CSR57_cs_kp_coarse_START (23)
#define SOC_MUDP_PHY_CS_CSR57_cs_kp_coarse_END (30)
#define SOC_MUDP_PHY_CS_CSR57_cs_kckd_hs_div_START (31)
#define SOC_MUDP_PHY_CS_CSR57_cs_kckd_hs_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_phe_underbound_th : 5;
        unsigned int cs_phe_overbound_th : 5;
        unsigned int cs_phe_ofst : 7;
        unsigned int csbiasmst_vbg_clkfreq_sel : 2;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_PHY_CS_CSR58_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR58_cs_phe_underbound_th_START (0)
#define SOC_MUDP_PHY_CS_CSR58_cs_phe_underbound_th_END (4)
#define SOC_MUDP_PHY_CS_CSR58_cs_phe_overbound_th_START (5)
#define SOC_MUDP_PHY_CS_CSR58_cs_phe_overbound_th_END (9)
#define SOC_MUDP_PHY_CS_CSR58_cs_phe_ofst_START (10)
#define SOC_MUDP_PHY_CS_CSR58_cs_phe_ofst_END (16)
#define SOC_MUDP_PHY_CS_CSR58_csbiasmst_vbg_clkfreq_sel_START (17)
#define SOC_MUDP_PHY_CS_CSR58_csbiasmst_vbg_clkfreq_sel_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_acq_lock_cnt_th : 6;
        unsigned int cs_kcal_cnt_th : 7;
        unsigned int cs_pacq_cnt_th : 7;
        unsigned int cs_ki_fine : 4;
        unsigned int cs_kp_fine : 8;
    } reg;
} SOC_MUDP_PHY_CS_CSR59_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR59_cs_acq_lock_cnt_th_START (0)
#define SOC_MUDP_PHY_CS_CSR59_cs_acq_lock_cnt_th_END (5)
#define SOC_MUDP_PHY_CS_CSR59_cs_kcal_cnt_th_START (6)
#define SOC_MUDP_PHY_CS_CSR59_cs_kcal_cnt_th_END (12)
#define SOC_MUDP_PHY_CS_CSR59_cs_pacq_cnt_th_START (13)
#define SOC_MUDP_PHY_CS_CSR59_cs_pacq_cnt_th_END (19)
#define SOC_MUDP_PHY_CS_CSR59_cs_ki_fine_START (20)
#define SOC_MUDP_PHY_CS_CSR59_cs_ki_fine_END (23)
#define SOC_MUDP_PHY_CS_CSR59_cs_kp_fine_START (24)
#define SOC_MUDP_PHY_CS_CSR59_cs_kp_fine_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_gcalib_ctrl_code_min : 8;
        unsigned int cs_gcalib_ctrl_code_max : 8;
        unsigned int cs_gcalib_init_ctrl_code : 8;
        unsigned int cs_gcalib_trans_max : 4;
        unsigned int cs_gcalib_direction : 1;
        unsigned int cs_gcalib_code_format : 1;
        unsigned int cs_calib_trigger_sel : 2;
    } reg;
} SOC_MUDP_PHY_CS_CSR60_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_ctrl_code_min_START (0)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_ctrl_code_min_END (7)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_ctrl_code_max_START (8)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_ctrl_code_max_END (15)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_init_ctrl_code_START (16)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_init_ctrl_code_END (23)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_trans_max_START (24)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_trans_max_END (27)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_direction_START (28)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_direction_END (28)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_code_format_START (29)
#define SOC_MUDP_PHY_CS_CSR60_cs_gcalib_code_format_END (29)
#define SOC_MUDP_PHY_CS_CSR60_cs_calib_trigger_sel_START (30)
#define SOC_MUDP_PHY_CS_CSR60_cs_calib_trigger_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_decimation_data : 12;
        unsigned int cs_decimation_ready : 1;
        unsigned int cs_ctrl_code_get_type : 3;
        unsigned int reserved_0 : 1;
        unsigned int cs_calib_start : 1;
        unsigned int cs_gcalib_done : 1;
        unsigned int cs_gcalib_trans_cnt : 4;
        unsigned int cs_gcalib_clr : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MUDP_PHY_CS_CSR61_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR61_cs_decimation_data_START (0)
#define SOC_MUDP_PHY_CS_CSR61_cs_decimation_data_END (11)
#define SOC_MUDP_PHY_CS_CSR61_cs_decimation_ready_START (12)
#define SOC_MUDP_PHY_CS_CSR61_cs_decimation_ready_END (12)
#define SOC_MUDP_PHY_CS_CSR61_cs_ctrl_code_get_type_START (13)
#define SOC_MUDP_PHY_CS_CSR61_cs_ctrl_code_get_type_END (15)
#define SOC_MUDP_PHY_CS_CSR61_cs_calib_start_START (17)
#define SOC_MUDP_PHY_CS_CSR61_cs_calib_start_END (17)
#define SOC_MUDP_PHY_CS_CSR61_cs_gcalib_done_START (18)
#define SOC_MUDP_PHY_CS_CSR61_cs_gcalib_done_END (18)
#define SOC_MUDP_PHY_CS_CSR61_cs_gcalib_trans_cnt_START (19)
#define SOC_MUDP_PHY_CS_CSR61_cs_gcalib_trans_cnt_END (22)
#define SOC_MUDP_PHY_CS_CSR61_cs_gcalib_clr_START (23)
#define SOC_MUDP_PHY_CS_CSR61_cs_gcalib_clr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_adc_start_measurement : 1;
        unsigned int cs_adc_reference_value : 12;
        unsigned int cs_decimation_factor_sel : 2;
        unsigned int cs_adc_filter_order : 1;
        unsigned int cs_adc_deadband_sel : 2;
        unsigned int cs_adc_conversion_mode : 1;
        unsigned int cs_adc_compstatus_deadband_m : 1;
        unsigned int cs_adc_compstatus_deadband_p : 1;
        unsigned int cs_adc_compare_status : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_CS_CSR62_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_start_measurement_START (0)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_start_measurement_END (0)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_reference_value_START (1)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_reference_value_END (12)
#define SOC_MUDP_PHY_CS_CSR62_cs_decimation_factor_sel_START (13)
#define SOC_MUDP_PHY_CS_CSR62_cs_decimation_factor_sel_END (14)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_filter_order_START (15)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_filter_order_END (15)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_deadband_sel_START (16)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_deadband_sel_END (17)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_conversion_mode_START (18)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_conversion_mode_END (18)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_compstatus_deadband_m_START (19)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_compstatus_deadband_m_END (19)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_compstatus_deadband_p_START (20)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_compstatus_deadband_p_END (20)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_compare_status_START (21)
#define SOC_MUDP_PHY_CS_CSR62_cs_adc_compare_status_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_timer_clr : 1;
        unsigned int cs_timer_start : 1;
        unsigned int reserved_0 : 14;
        unsigned int cs_timer_base : 14;
        unsigned int cs_timer_exp : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_MUDP_PHY_CS_CSR63_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_clr_START (0)
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_clr_END (0)
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_start_START (1)
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_start_END (1)
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_base_START (16)
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_base_END (29)
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_exp_START (30)
#define SOC_MUDP_PHY_CS_CSR63_cs_timer_exp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cs_vbgbuf_compare_status : 1;
        unsigned int cs_comp_compare_status : 1;
        unsigned int cs_rd_refresh : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PHY_CS_CSR64_UNION;
#endif
#define SOC_MUDP_PHY_CS_CSR64_cs_vbgbuf_compare_status_START (0)
#define SOC_MUDP_PHY_CS_CSR64_cs_vbgbuf_compare_status_END (0)
#define SOC_MUDP_PHY_CS_CSR64_cs_comp_compare_status_START (1)
#define SOC_MUDP_PHY_CS_CSR64_cs_comp_compare_status_END (1)
#define SOC_MUDP_PHY_CS_CSR64_cs_rd_refresh_START (2)
#define SOC_MUDP_PHY_CS_CSR64_cs_rd_refresh_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 1;
        unsigned int tx_slice_id : 3;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_MUDP_PHY_TX_CSR0_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR0_tx_slice_id_START (7)
#define SOC_MUDP_PHY_TX_CSR0_tx_slice_id_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr1_ra : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR1_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR1_tx_fsm_sfr1_ra_START (0)
#define SOC_MUDP_PHY_TX_CSR1_tx_fsm_sfr1_ra_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr2_sp : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR2_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR2_tx_fsm_sfr2_sp_START (0)
#define SOC_MUDP_PHY_TX_CSR2_tx_fsm_sfr2_sp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr3_gp : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR3_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR3_tx_fsm_sfr3_gp_START (0)
#define SOC_MUDP_PHY_TX_CSR3_tx_fsm_sfr3_gp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr4_ap : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR4_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR4_tx_fsm_sfr4_ap_START (0)
#define SOC_MUDP_PHY_TX_CSR4_tx_fsm_sfr4_ap_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr5_vp : 22;
        unsigned int tx_fsm_sram_mask : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR5_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR5_tx_fsm_sfr5_vp_START (0)
#define SOC_MUDP_PHY_TX_CSR5_tx_fsm_sfr5_vp_END (21)
#define SOC_MUDP_PHY_TX_CSR5_tx_fsm_sram_mask_START (22)
#define SOC_MUDP_PHY_TX_CSR5_tx_fsm_sram_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr6_rp0 : 22;
        unsigned int tx_fsm_reg_mask : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR6_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR6_tx_fsm_sfr6_rp0_START (0)
#define SOC_MUDP_PHY_TX_CSR6_tx_fsm_sfr6_rp0_END (21)
#define SOC_MUDP_PHY_TX_CSR6_tx_fsm_reg_mask_START (22)
#define SOC_MUDP_PHY_TX_CSR6_tx_fsm_reg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr7_rp1 : 22;
        unsigned int tx_fsm_status : 3;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PHY_TX_CSR7_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR7_tx_fsm_sfr7_rp1_START (0)
#define SOC_MUDP_PHY_TX_CSR7_tx_fsm_sfr7_rp1_END (21)
#define SOC_MUDP_PHY_TX_CSR7_tx_fsm_status_START (22)
#define SOC_MUDP_PHY_TX_CSR7_tx_fsm_status_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr8_pc : 22;
        unsigned int tx_fsm_done : 1;
        unsigned int tx_fsm_cmd : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_MUDP_PHY_TX_CSR8_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR8_tx_fsm_sfr8_pc_START (0)
#define SOC_MUDP_PHY_TX_CSR8_tx_fsm_sfr8_pc_END (21)
#define SOC_MUDP_PHY_TX_CSR8_tx_fsm_done_START (22)
#define SOC_MUDP_PHY_TX_CSR8_tx_fsm_done_END (22)
#define SOC_MUDP_PHY_TX_CSR8_tx_fsm_cmd_START (23)
#define SOC_MUDP_PHY_TX_CSR8_tx_fsm_cmd_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr9_opl : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR9_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR9_tx_fsm_sfr9_opl_START (0)
#define SOC_MUDP_PHY_TX_CSR9_tx_fsm_sfr9_opl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr10_opr : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR10_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR10_tx_fsm_sfr10_opr_START (0)
#define SOC_MUDP_PHY_TX_CSR10_tx_fsm_sfr10_opr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr11_opd : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR11_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR11_tx_fsm_sfr11_opd_START (0)
#define SOC_MUDP_PHY_TX_CSR11_tx_fsm_sfr11_opd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr12_a0 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR12_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR12_tx_fsm_sfr12_a0_START (0)
#define SOC_MUDP_PHY_TX_CSR12_tx_fsm_sfr12_a0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr13_a1 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR13_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR13_tx_fsm_sfr13_a1_START (0)
#define SOC_MUDP_PHY_TX_CSR13_tx_fsm_sfr13_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr14_a2 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR14_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR14_tx_fsm_sfr14_a2_START (0)
#define SOC_MUDP_PHY_TX_CSR14_tx_fsm_sfr14_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sfr15_a3 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR15_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR15_tx_fsm_sfr15_a3_START (0)
#define SOC_MUDP_PHY_TX_CSR15_tx_fsm_sfr15_a3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_reg_addr : 16;
        unsigned int tx_fsm_sram_addr : 16;
    } reg;
} SOC_MUDP_PHY_TX_CSR16_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR16_tx_fsm_reg_addr_START (0)
#define SOC_MUDP_PHY_TX_CSR16_tx_fsm_reg_addr_END (15)
#define SOC_MUDP_PHY_TX_CSR16_tx_fsm_sram_addr_START (16)
#define SOC_MUDP_PHY_TX_CSR16_tx_fsm_sram_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_start : 1;
        unsigned int tx_fsm_start_addr : 16;
        unsigned int tx_fsm_hold_en : 1;
        unsigned int tx_fsm_freeze : 1;
        unsigned int tx_fsm_clr : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_TX_CSR17_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_start_START (0)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_start_END (0)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_start_addr_START (1)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_start_addr_END (16)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_hold_en_START (17)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_hold_en_END (17)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_freeze_START (18)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_freeze_END (18)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_clr_START (19)
#define SOC_MUDP_PHY_TX_CSR17_tx_fsm_clr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_timer_base : 14;
        unsigned int tx_fsm_timer_exp : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PHY_TX_CSR18_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR18_tx_fsm_timer_base_START (0)
#define SOC_MUDP_PHY_TX_CSR18_tx_fsm_timer_base_END (13)
#define SOC_MUDP_PHY_TX_CSR18_tx_fsm_timer_exp_START (14)
#define SOC_MUDP_PHY_TX_CSR18_tx_fsm_timer_exp_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_int0 : 4;
        unsigned int tx_fsm_int1 : 4;
        unsigned int tx_fsm_int3 : 4;
        unsigned int tx_pll0_req : 1;
        unsigned int tx_pll1_req : 1;
        unsigned int tx_init_req : 1;
        unsigned int tx_all_slice_pll0_req : 1;
        unsigned int tx_all_slice_pll1_req : 1;
        unsigned int tx_all_slice_init_req : 1;
        unsigned int tx_pll0_status : 1;
        unsigned int tx_pll1_status : 1;
        unsigned int tx_init_status : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_MUDP_PHY_TX_CSR19_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR19_tx_fsm_int0_START (0)
#define SOC_MUDP_PHY_TX_CSR19_tx_fsm_int0_END (3)
#define SOC_MUDP_PHY_TX_CSR19_tx_fsm_int1_START (4)
#define SOC_MUDP_PHY_TX_CSR19_tx_fsm_int1_END (7)
#define SOC_MUDP_PHY_TX_CSR19_tx_fsm_int3_START (8)
#define SOC_MUDP_PHY_TX_CSR19_tx_fsm_int3_END (11)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll0_req_START (12)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll0_req_END (12)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll1_req_START (13)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll1_req_END (13)
#define SOC_MUDP_PHY_TX_CSR19_tx_init_req_START (14)
#define SOC_MUDP_PHY_TX_CSR19_tx_init_req_END (14)
#define SOC_MUDP_PHY_TX_CSR19_tx_all_slice_pll0_req_START (15)
#define SOC_MUDP_PHY_TX_CSR19_tx_all_slice_pll0_req_END (15)
#define SOC_MUDP_PHY_TX_CSR19_tx_all_slice_pll1_req_START (16)
#define SOC_MUDP_PHY_TX_CSR19_tx_all_slice_pll1_req_END (16)
#define SOC_MUDP_PHY_TX_CSR19_tx_all_slice_init_req_START (17)
#define SOC_MUDP_PHY_TX_CSR19_tx_all_slice_init_req_END (17)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll0_status_START (18)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll0_status_END (18)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll1_status_START (19)
#define SOC_MUDP_PHY_TX_CSR19_tx_pll1_status_END (19)
#define SOC_MUDP_PHY_TX_CSR19_tx_init_status_START (20)
#define SOC_MUDP_PHY_TX_CSR19_tx_init_status_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 28;
        unsigned int tx_fsm_clr_en : 1;
        unsigned int tx_fsm_wait_flag_ctrl : 2;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_MUDP_PHY_TX_CSR24_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR24_tx_fsm_clr_en_START (28)
#define SOC_MUDP_PHY_TX_CSR24_tx_fsm_clr_en_END (28)
#define SOC_MUDP_PHY_TX_CSR24_tx_fsm_wait_flag_ctrl_START (29)
#define SOC_MUDP_PHY_TX_CSR24_tx_fsm_wait_flag_ctrl_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_sdpi_event_status : 16;
        unsigned int tx_sdpi_ready : 1;
        unsigned int tx_sdpi_event_ack : 1;
        unsigned int tx_fsm_curr_fw : 4;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR25_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR25_tx_sdpi_event_status_START (0)
#define SOC_MUDP_PHY_TX_CSR25_tx_sdpi_event_status_END (15)
#define SOC_MUDP_PHY_TX_CSR25_tx_sdpi_ready_START (16)
#define SOC_MUDP_PHY_TX_CSR25_tx_sdpi_ready_END (16)
#define SOC_MUDP_PHY_TX_CSR25_tx_sdpi_event_ack_START (17)
#define SOC_MUDP_PHY_TX_CSR25_tx_sdpi_event_ack_END (17)
#define SOC_MUDP_PHY_TX_CSR25_tx_fsm_curr_fw_START (18)
#define SOC_MUDP_PHY_TX_CSR25_tx_fsm_curr_fw_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_sdpi_event_cmd_pin : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR26_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR26_tx_sdpi_event_cmd_pin_START (0)
#define SOC_MUDP_PHY_TX_CSR26_tx_sdpi_event_cmd_pin_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_sdpi_event_cmd : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR27_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR27_tx_sdpi_event_cmd_START (0)
#define SOC_MUDP_PHY_TX_CSR27_tx_sdpi_event_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_sdpi_event_enable_pin : 1;
        unsigned int tx_sdpi_reset_pin : 1;
        unsigned int tx_sdpi_mode_pin : 1;
        unsigned int reserved_0 : 3;
        unsigned int tx_sdpi_event_enable_status : 1;
        unsigned int tx_sdpi_reset_status : 1;
        unsigned int tx_sdpi_mode_status : 1;
        unsigned int reserved_1 : 3;
        unsigned int tx_sdpi_event_req : 1;
        unsigned int tx_sdpi_reset : 1;
        unsigned int tx_sdpi_mode : 1;
        unsigned int reserved_2 : 3;
        unsigned int tx_sdpi_event_pin_en : 1;
        unsigned int tx_sdpi_reset_pin_en : 1;
        unsigned int tx_sdpi_phy_mode_pin_en : 1;
        unsigned int tx_sdpi_reset_fsm_en : 1;
        unsigned int tx_sdpi_event_fsm_en : 8;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_MUDP_PHY_TX_CSR28_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_enable_pin_START (0)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_enable_pin_END (0)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_pin_START (1)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_pin_END (1)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_mode_pin_START (2)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_mode_pin_END (2)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_enable_status_START (6)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_enable_status_END (6)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_status_START (7)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_status_END (7)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_mode_status_START (8)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_mode_status_END (8)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_req_START (12)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_req_END (12)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_START (13)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_END (13)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_mode_START (14)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_mode_END (14)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_pin_en_START (18)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_pin_en_END (18)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_pin_en_START (19)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_pin_en_END (19)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_phy_mode_pin_en_START (20)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_phy_mode_pin_en_END (20)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_fsm_en_START (21)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_reset_fsm_en_END (21)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_fsm_en_START (22)
#define SOC_MUDP_PHY_TX_CSR28_tx_sdpi_event_fsm_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_waiting_for_lpctrl_rsp : 1;
        unsigned int tx_lpctrl_hw_call_enable : 1;
        unsigned int tx_curr_pwr_status : 4;
        unsigned int tx_curr_rate_status : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_MUDP_PHY_TX_CSR29_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR29_tx_waiting_for_lpctrl_rsp_START (0)
#define SOC_MUDP_PHY_TX_CSR29_tx_waiting_for_lpctrl_rsp_END (0)
#define SOC_MUDP_PHY_TX_CSR29_tx_lpctrl_hw_call_enable_START (1)
#define SOC_MUDP_PHY_TX_CSR29_tx_lpctrl_hw_call_enable_END (1)
#define SOC_MUDP_PHY_TX_CSR29_tx_curr_pwr_status_START (2)
#define SOC_MUDP_PHY_TX_CSR29_tx_curr_pwr_status_END (5)
#define SOC_MUDP_PHY_TX_CSR29_tx_curr_rate_status_START (6)
#define SOC_MUDP_PHY_TX_CSR29_tx_curr_rate_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_sdpi_start_addr : 16;
        unsigned int tx_fsm_trx_int_addr : 16;
    } reg;
} SOC_MUDP_PHY_TX_CSR30_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR30_tx_fsm_sdpi_start_addr_START (0)
#define SOC_MUDP_PHY_TX_CSR30_tx_fsm_sdpi_start_addr_END (15)
#define SOC_MUDP_PHY_TX_CSR30_tx_fsm_trx_int_addr_START (16)
#define SOC_MUDP_PHY_TX_CSR30_tx_fsm_trx_int_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_soft_int : 1;
        unsigned int tx_pwr_event_int : 1;
        unsigned int tx_sdpi_error_int : 1;
        unsigned int tx_fsm_wait_out_flag_int : 1;
        unsigned int tx_fsm_apb_slverr_int : 1;
        unsigned int tx_fsm_cmd_error_int : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int tx_fsm_sram_error_int : 1;
        unsigned int reserved_5 : 20;
    } reg;
} SOC_MUDP_PHY_TX_CSR31_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR31_tx_soft_int_START (0)
#define SOC_MUDP_PHY_TX_CSR31_tx_soft_int_END (0)
#define SOC_MUDP_PHY_TX_CSR31_tx_pwr_event_int_START (1)
#define SOC_MUDP_PHY_TX_CSR31_tx_pwr_event_int_END (1)
#define SOC_MUDP_PHY_TX_CSR31_tx_sdpi_error_int_START (2)
#define SOC_MUDP_PHY_TX_CSR31_tx_sdpi_error_int_END (2)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_wait_out_flag_int_START (3)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_wait_out_flag_int_END (3)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_apb_slverr_int_START (4)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_apb_slverr_int_END (4)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_cmd_error_int_START (5)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_cmd_error_int_END (5)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_sram_error_int_START (11)
#define SOC_MUDP_PHY_TX_CSR31_tx_fsm_sram_error_int_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_soft_int_source : 1;
        unsigned int tx_pwr_event_int_source : 1;
        unsigned int tx_sdpi_error_int_source : 1;
        unsigned int tx_fsm_wait_out_flag_int_source : 1;
        unsigned int tx_fsm_apb_slverr_int_source : 1;
        unsigned int tx_fsm_cmd_error_int_source : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int tx_fsm_sram_error_int_source : 1;
        unsigned int reserved_5 : 20;
    } reg;
} SOC_MUDP_PHY_TX_CSR32_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR32_tx_soft_int_source_START (0)
#define SOC_MUDP_PHY_TX_CSR32_tx_soft_int_source_END (0)
#define SOC_MUDP_PHY_TX_CSR32_tx_pwr_event_int_source_START (1)
#define SOC_MUDP_PHY_TX_CSR32_tx_pwr_event_int_source_END (1)
#define SOC_MUDP_PHY_TX_CSR32_tx_sdpi_error_int_source_START (2)
#define SOC_MUDP_PHY_TX_CSR32_tx_sdpi_error_int_source_END (2)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_wait_out_flag_int_source_START (3)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_wait_out_flag_int_source_END (3)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_apb_slverr_int_source_START (4)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_apb_slverr_int_source_END (4)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_cmd_error_int_source_START (5)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_cmd_error_int_source_END (5)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_sram_error_int_source_START (11)
#define SOC_MUDP_PHY_TX_CSR32_tx_fsm_sram_error_int_source_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_soft_int_mask : 1;
        unsigned int tx_pwr_event_int_mask : 1;
        unsigned int tx_sdpi_error_int_mask : 1;
        unsigned int tx_fsm_wait_out_flag_int_mask : 1;
        unsigned int tx_fsm_apb_slverr_int_mask : 1;
        unsigned int tx_fsm_cmd_error_int_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int tx_fsm_sram_error_int_mask : 1;
        unsigned int tx_dtb_out_sel : 4;
        unsigned int reserved_5 : 16;
    } reg;
} SOC_MUDP_PHY_TX_CSR33_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR33_tx_soft_int_mask_START (0)
#define SOC_MUDP_PHY_TX_CSR33_tx_soft_int_mask_END (0)
#define SOC_MUDP_PHY_TX_CSR33_tx_pwr_event_int_mask_START (1)
#define SOC_MUDP_PHY_TX_CSR33_tx_pwr_event_int_mask_END (1)
#define SOC_MUDP_PHY_TX_CSR33_tx_sdpi_error_int_mask_START (2)
#define SOC_MUDP_PHY_TX_CSR33_tx_sdpi_error_int_mask_END (2)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_wait_out_flag_int_mask_START (3)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_wait_out_flag_int_mask_END (3)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_apb_slverr_int_mask_START (4)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_apb_slverr_int_mask_END (4)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_cmd_error_int_mask_START (5)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_cmd_error_int_mask_END (5)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_sram_error_int_mask_START (11)
#define SOC_MUDP_PHY_TX_CSR33_tx_fsm_sram_error_int_mask_END (11)
#define SOC_MUDP_PHY_TX_CSR33_tx_dtb_out_sel_START (12)
#define SOC_MUDP_PHY_TX_CSR33_tx_dtb_out_sel_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int tx_spare_in : 2;
        unsigned int tx_spare_out : 2;
        unsigned int tx_bse : 1;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_MUDP_PHY_TX_CSR34_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR34_tx_spare_in_START (8)
#define SOC_MUDP_PHY_TX_CSR34_tx_spare_in_END (9)
#define SOC_MUDP_PHY_TX_CSR34_tx_spare_out_START (10)
#define SOC_MUDP_PHY_TX_CSR34_tx_spare_out_END (11)
#define SOC_MUDP_PHY_TX_CSR34_tx_bse_START (12)
#define SOC_MUDP_PHY_TX_CSR34_tx_bse_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_dig_spare0 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR35_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR35_tx_dig_spare0_START (0)
#define SOC_MUDP_PHY_TX_CSR35_tx_dig_spare0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_dig_spare1 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR36_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR36_tx_dig_spare1_START (0)
#define SOC_MUDP_PHY_TX_CSR36_tx_dig_spare1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_lfdata_polarity_en : 1;
        unsigned int tx_lfdata_pin_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_PHY_TX_CSR37_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR37_tx_lfdata_polarity_en_START (0)
#define SOC_MUDP_PHY_TX_CSR37_tx_lfdata_polarity_en_END (0)
#define SOC_MUDP_PHY_TX_CSR37_tx_lfdata_pin_en_START (1)
#define SOC_MUDP_PHY_TX_CSR37_tx_lfdata_pin_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int tx_bitorder_inv_en : 1;
        unsigned int tx_polarity_en : 1;
        unsigned int tx_pa_test_en : 1;
        unsigned int reserved_1 : 4;
        unsigned int tx_pa_lock_success : 1;
        unsigned int tx2rx_parlpbk_en : 1;
        unsigned int rx2tx_parlpbk_en : 1;
        unsigned int tx_grbx_gate_en : 1;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_MUDP_PHY_TX_CSR38_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR38_tx_bitorder_inv_en_START (2)
#define SOC_MUDP_PHY_TX_CSR38_tx_bitorder_inv_en_END (2)
#define SOC_MUDP_PHY_TX_CSR38_tx_polarity_en_START (3)
#define SOC_MUDP_PHY_TX_CSR38_tx_polarity_en_END (3)
#define SOC_MUDP_PHY_TX_CSR38_tx_pa_test_en_START (4)
#define SOC_MUDP_PHY_TX_CSR38_tx_pa_test_en_END (4)
#define SOC_MUDP_PHY_TX_CSR38_tx_pa_lock_success_START (9)
#define SOC_MUDP_PHY_TX_CSR38_tx_pa_lock_success_END (9)
#define SOC_MUDP_PHY_TX_CSR38_tx2rx_parlpbk_en_START (10)
#define SOC_MUDP_PHY_TX_CSR38_tx2rx_parlpbk_en_END (10)
#define SOC_MUDP_PHY_TX_CSR38_rx2tx_parlpbk_en_START (11)
#define SOC_MUDP_PHY_TX_CSR38_rx2tx_parlpbk_en_END (11)
#define SOC_MUDP_PHY_TX_CSR38_tx_grbx_gate_en_START (12)
#define SOC_MUDP_PHY_TX_CSR38_tx_grbx_gate_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_prbs_cust_patt_0 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR39_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR39_tx_prbs_cust_patt_0_START (0)
#define SOC_MUDP_PHY_TX_CSR39_tx_prbs_cust_patt_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_prbs_cust_patt_1 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR40_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR40_tx_prbs_cust_patt_1_START (0)
#define SOC_MUDP_PHY_TX_CSR40_tx_prbs_cust_patt_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_prbs_cust_patt_2 : 32;
    } reg;
} SOC_MUDP_PHY_TX_CSR41_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR41_tx_prbs_cust_patt_2_START (0)
#define SOC_MUDP_PHY_TX_CSR41_tx_prbs_cust_patt_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_prbs_err_inj_position : 6;
        unsigned int tx_prbs_err_inj_once : 1;
        unsigned int tx_prbs_err_inj_en : 1;
        unsigned int tx_prbs_patt_sel : 5;
        unsigned int tx_prbs_en : 1;
        unsigned int tx_prbs_width_sel : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_MUDP_PHY_TX_CSR42_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_err_inj_position_START (0)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_err_inj_position_END (5)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_err_inj_once_START (6)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_err_inj_once_END (6)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_err_inj_en_START (7)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_err_inj_en_END (7)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_patt_sel_START (8)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_patt_sel_END (12)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_en_START (13)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_en_END (13)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_width_sel_START (14)
#define SOC_MUDP_PHY_TX_CSR42_tx_prbs_width_sel_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_pa_target_phase : 4;
        unsigned int tx_pa_wait_time : 2;
        unsigned int tx_pa_start : 1;
        unsigned int tx_pa_compare_count_th : 4;
        unsigned int txcp_clkslip_sel : 1;
        unsigned int txcp_clkslip : 1;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_MUDP_PHY_TX_CSR43_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_target_phase_START (0)
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_target_phase_END (3)
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_wait_time_START (4)
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_wait_time_END (5)
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_start_START (6)
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_start_END (6)
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_compare_count_th_START (7)
#define SOC_MUDP_PHY_TX_CSR43_tx_pa_compare_count_th_END (10)
#define SOC_MUDP_PHY_TX_CSR43_txcp_clkslip_sel_START (11)
#define SOC_MUDP_PHY_TX_CSR43_txcp_clkslip_sel_END (11)
#define SOC_MUDP_PHY_TX_CSR43_txcp_clkslip_START (12)
#define SOC_MUDP_PHY_TX_CSR43_txcp_clkslip_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_ffe_enable : 1;
        unsigned int tx_ffe_enable_pin_en : 1;
        unsigned int tx_drv_sel : 4;
        unsigned int tx_ffe_enable_pin_st : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MUDP_PHY_TX_CSR44_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR44_tx_ffe_enable_START (0)
#define SOC_MUDP_PHY_TX_CSR44_tx_ffe_enable_END (0)
#define SOC_MUDP_PHY_TX_CSR44_tx_ffe_enable_pin_en_START (1)
#define SOC_MUDP_PHY_TX_CSR44_tx_ffe_enable_pin_en_END (1)
#define SOC_MUDP_PHY_TX_CSR44_tx_drv_sel_START (2)
#define SOC_MUDP_PHY_TX_CSR44_tx_drv_sel_END (5)
#define SOC_MUDP_PHY_TX_CSR44_tx_ffe_enable_pin_st_START (6)
#define SOC_MUDP_PHY_TX_CSR44_tx_ffe_enable_pin_st_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_lpctrl_bypass : 1;
        unsigned int rx_lpctrl_bypass : 1;
        unsigned int tx_tsn : 3;
        unsigned int tx_lpctrl_wait_time : 6;
        unsigned int reserved_0 : 2;
        unsigned int tx_curr_seq : 3;
        unsigned int tx_seq_done : 1;
        unsigned int dscomm_curr_seq : 3;
        unsigned int dscomm_seq_done : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_MUDP_PHY_TX_CSR45_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR45_tx_lpctrl_bypass_START (0)
#define SOC_MUDP_PHY_TX_CSR45_tx_lpctrl_bypass_END (0)
#define SOC_MUDP_PHY_TX_CSR45_rx_lpctrl_bypass_START (1)
#define SOC_MUDP_PHY_TX_CSR45_rx_lpctrl_bypass_END (1)
#define SOC_MUDP_PHY_TX_CSR45_tx_tsn_START (2)
#define SOC_MUDP_PHY_TX_CSR45_tx_tsn_END (4)
#define SOC_MUDP_PHY_TX_CSR45_tx_lpctrl_wait_time_START (5)
#define SOC_MUDP_PHY_TX_CSR45_tx_lpctrl_wait_time_END (10)
#define SOC_MUDP_PHY_TX_CSR45_tx_curr_seq_START (13)
#define SOC_MUDP_PHY_TX_CSR45_tx_curr_seq_END (15)
#define SOC_MUDP_PHY_TX_CSR45_tx_seq_done_START (16)
#define SOC_MUDP_PHY_TX_CSR45_tx_seq_done_END (16)
#define SOC_MUDP_PHY_TX_CSR45_dscomm_curr_seq_START (17)
#define SOC_MUDP_PHY_TX_CSR45_dscomm_curr_seq_END (19)
#define SOC_MUDP_PHY_TX_CSR45_dscomm_seq_done_START (20)
#define SOC_MUDP_PHY_TX_CSR45_dscomm_seq_done_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_wclk_gate_soft_val : 1;
        unsigned int tx_wclk_gate_sel_soft : 1;
        unsigned int tx_wclk_en_soft_val : 1;
        unsigned int tx_wclk_en_sel_soft : 1;
        unsigned int tx_div_rstb_soft_val : 1;
        unsigned int tx_div_rstb_sel_soft : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 24;
    } reg;
} SOC_MUDP_PHY_TX_CSR46_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_gate_soft_val_START (0)
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_gate_soft_val_END (0)
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_gate_sel_soft_START (1)
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_gate_sel_soft_END (1)
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_en_soft_val_START (2)
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_en_soft_val_END (2)
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_en_sel_soft_START (3)
#define SOC_MUDP_PHY_TX_CSR46_tx_wclk_en_sel_soft_END (3)
#define SOC_MUDP_PHY_TX_CSR46_tx_div_rstb_soft_val_START (4)
#define SOC_MUDP_PHY_TX_CSR46_tx_div_rstb_soft_val_END (4)
#define SOC_MUDP_PHY_TX_CSR46_tx_div_rstb_sel_soft_START (5)
#define SOC_MUDP_PHY_TX_CSR46_tx_div_rstb_sel_soft_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txcp_prediv_pwrdnb_up : 1;
        unsigned int txcp_prediv_pwrdnb_dn : 1;
        unsigned int txcp_clktree_pwrdnb_up : 1;
        unsigned int txcp_clktree_pwrdnb_dn : 1;
        unsigned int txcp_qdiv_pwrdnb_up : 1;
        unsigned int txcp_qdiv_pwrdnb_dn : 1;
        unsigned int txdp_p2s_pwrdnb_up : 1;
        unsigned int txdp_p2s_pwrdnb_dn : 1;
        unsigned int txdrv_pwrdnb_up : 1;
        unsigned int txdrv_pwrdnb_dn : 1;
        unsigned int txdrv_post1tap_pwrdnb_up : 1;
        unsigned int txdrv_post1tap_pwrdnb_dn : 1;
        unsigned int txreg_data_pwrdnb : 1;
        unsigned int txds_lvcc_pwrdnb : 1;
        unsigned int txreg_data_bleed_en : 1;
        unsigned int txreg_data_fast_startup_up : 1;
        unsigned int txreg_data_fast_startup_dn : 1;
        unsigned int txreg_data_pgate_pwrdnb : 1;
        unsigned int txreg_drv_bleed_en : 1;
        unsigned int txreg_drv_pwrdnb : 1;
        unsigned int txreg_drv_pgate_pwrdnb : 1;
        unsigned int txreg_drv_fast_startup_up : 1;
        unsigned int txreg_drv_fast_startup_dn : 1;
        unsigned int txreg_data_bleed_en_up : 1;
        unsigned int txreg_data_bleed_en_dn : 1;
        unsigned int txreg_data_pgate_pwrdnb_up : 1;
        unsigned int txreg_data_pgate_pwrdnb_dn : 1;
        unsigned int txreg_drv_bleed_en_up : 1;
        unsigned int txreg_drv_bleed_en_dn : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_MUDP_PHY_TX_CSR47_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR47_txcp_prediv_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_TX_CSR47_txcp_prediv_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_TX_CSR47_txcp_prediv_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_TX_CSR47_txcp_prediv_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_TX_CSR47_txcp_clktree_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_TX_CSR47_txcp_clktree_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_TX_CSR47_txcp_clktree_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_TX_CSR47_txcp_clktree_pwrdnb_dn_END (3)
#define SOC_MUDP_PHY_TX_CSR47_txcp_qdiv_pwrdnb_up_START (4)
#define SOC_MUDP_PHY_TX_CSR47_txcp_qdiv_pwrdnb_up_END (4)
#define SOC_MUDP_PHY_TX_CSR47_txcp_qdiv_pwrdnb_dn_START (5)
#define SOC_MUDP_PHY_TX_CSR47_txcp_qdiv_pwrdnb_dn_END (5)
#define SOC_MUDP_PHY_TX_CSR47_txdp_p2s_pwrdnb_up_START (6)
#define SOC_MUDP_PHY_TX_CSR47_txdp_p2s_pwrdnb_up_END (6)
#define SOC_MUDP_PHY_TX_CSR47_txdp_p2s_pwrdnb_dn_START (7)
#define SOC_MUDP_PHY_TX_CSR47_txdp_p2s_pwrdnb_dn_END (7)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_pwrdnb_up_START (8)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_pwrdnb_up_END (8)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_pwrdnb_dn_START (9)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_pwrdnb_dn_END (9)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_post1tap_pwrdnb_up_START (10)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_post1tap_pwrdnb_up_END (10)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_post1tap_pwrdnb_dn_START (11)
#define SOC_MUDP_PHY_TX_CSR47_txdrv_post1tap_pwrdnb_dn_END (11)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pwrdnb_START (12)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pwrdnb_END (12)
#define SOC_MUDP_PHY_TX_CSR47_txds_lvcc_pwrdnb_START (13)
#define SOC_MUDP_PHY_TX_CSR47_txds_lvcc_pwrdnb_END (13)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_bleed_en_START (14)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_bleed_en_END (14)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_fast_startup_up_START (15)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_fast_startup_up_END (15)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_fast_startup_dn_START (16)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_fast_startup_dn_END (16)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pgate_pwrdnb_START (17)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pgate_pwrdnb_END (17)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_bleed_en_START (18)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_bleed_en_END (18)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_pwrdnb_START (19)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_pwrdnb_END (19)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_pgate_pwrdnb_START (20)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_pgate_pwrdnb_END (20)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_fast_startup_up_START (21)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_fast_startup_up_END (21)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_fast_startup_dn_START (22)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_fast_startup_dn_END (22)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_bleed_en_up_START (23)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_bleed_en_up_END (23)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_bleed_en_dn_START (24)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_bleed_en_dn_END (24)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pgate_pwrdnb_up_START (25)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pgate_pwrdnb_up_END (25)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pgate_pwrdnb_dn_START (26)
#define SOC_MUDP_PHY_TX_CSR47_txreg_data_pgate_pwrdnb_dn_END (26)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_bleed_en_up_START (27)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_bleed_en_up_END (27)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_bleed_en_dn_START (28)
#define SOC_MUDP_PHY_TX_CSR47_txreg_drv_bleed_en_dn_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscp_hsclkrcv_1ststage_pwrdnb_up : 1;
        unsigned int dscp_hsclkrcv_1ststage_pwrdnb_dn : 1;
        unsigned int dscp_txhsclkrcv_2ndstage_pwrdnb_up : 1;
        unsigned int dscp_txhsclkrcv_2ndstage_pwrdnb_dn : 1;
        unsigned int dscp_rxhsclkrcv_2ndstage_pwrdnb_up : 1;
        unsigned int dscp_rxhsclkrcv_2ndstage_pwrdnb_dn : 1;
        unsigned int ds_ldobst_bypass_cp : 1;
        unsigned int ds_ldobst_vref_pwrdnb : 1;
        unsigned int ds_ldobst_preopamp_pwrdnb : 1;
        unsigned int ds_ldobst_bleed_en : 1;
        unsigned int ds_cpump_pwrdnb : 1;
        unsigned int txrxreg_clk_pwrdnb : 1;
        unsigned int txrxreg_clk_ref_pwrdnb : 1;
        unsigned int txrxreg_clk_fast_startup : 1;
        unsigned int txrxreg_clk_bleed_en : 1;
        unsigned int txrxreg_clk_pgate_pwrdnb : 1;
        unsigned int txrxreg_clk_pgate_pwrdnb_up : 1;
        unsigned int txrxreg_clk_pgate_pwrdnb_dn : 1;
        unsigned int txrxreg_clk_bleed_en_up : 1;
        unsigned int txrxreg_clk_bleed_en_dn : 1;
        unsigned int txrxreg_clk_fast_startup_up : 1;
        unsigned int txrxreg_clk_fast_startup_dn : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_TX_CSR48_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR48_dscp_hsclkrcv_1ststage_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_TX_CSR48_dscp_hsclkrcv_1ststage_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_TX_CSR48_dscp_hsclkrcv_1ststage_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_TX_CSR48_dscp_hsclkrcv_1ststage_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_TX_CSR48_dscp_txhsclkrcv_2ndstage_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_TX_CSR48_dscp_txhsclkrcv_2ndstage_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_TX_CSR48_dscp_txhsclkrcv_2ndstage_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_TX_CSR48_dscp_txhsclkrcv_2ndstage_pwrdnb_dn_END (3)
#define SOC_MUDP_PHY_TX_CSR48_dscp_rxhsclkrcv_2ndstage_pwrdnb_up_START (4)
#define SOC_MUDP_PHY_TX_CSR48_dscp_rxhsclkrcv_2ndstage_pwrdnb_up_END (4)
#define SOC_MUDP_PHY_TX_CSR48_dscp_rxhsclkrcv_2ndstage_pwrdnb_dn_START (5)
#define SOC_MUDP_PHY_TX_CSR48_dscp_rxhsclkrcv_2ndstage_pwrdnb_dn_END (5)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_bypass_cp_START (6)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_bypass_cp_END (6)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_vref_pwrdnb_START (7)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_vref_pwrdnb_END (7)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_preopamp_pwrdnb_START (8)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_preopamp_pwrdnb_END (8)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_bleed_en_START (9)
#define SOC_MUDP_PHY_TX_CSR48_ds_ldobst_bleed_en_END (9)
#define SOC_MUDP_PHY_TX_CSR48_ds_cpump_pwrdnb_START (10)
#define SOC_MUDP_PHY_TX_CSR48_ds_cpump_pwrdnb_END (10)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pwrdnb_START (11)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pwrdnb_END (11)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_ref_pwrdnb_START (12)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_ref_pwrdnb_END (12)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_fast_startup_START (13)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_fast_startup_END (13)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_bleed_en_START (14)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_bleed_en_END (14)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pgate_pwrdnb_START (15)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pgate_pwrdnb_END (15)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pgate_pwrdnb_up_START (16)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pgate_pwrdnb_up_END (16)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pgate_pwrdnb_dn_START (17)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_pgate_pwrdnb_dn_END (17)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_bleed_en_up_START (18)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_bleed_en_up_END (18)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_bleed_en_dn_START (19)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_bleed_en_dn_END (19)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_fast_startup_up_START (20)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_fast_startup_up_END (20)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_fast_startup_dn_START (21)
#define SOC_MUDP_PHY_TX_CSR48_txrxreg_clk_fast_startup_dn_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_MUDP_PHY_TX_CSR49_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_fsm_clk_en_gt : 1;
        unsigned int tx_fsm_soft_rstn : 1;
        unsigned int tx_fsm_start_dg : 1;
        unsigned int tx_lp_ctrl_clk_en_gt : 1;
        unsigned int tx_lp_ctrl_soft_rstn : 1;
        unsigned int tx_lp_ctrl_start_dg : 1;
        unsigned int tx_pa_clk_en_gt : 1;
        unsigned int tx_pa_grbx_soft_rstn : 1;
        unsigned int tx_prbs_clk_en : 1;
        unsigned int tx_prbs_soft_rstn : 1;
        unsigned int tx_soft_rstn : 1;
        unsigned int tx_txi_clk_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_MUDP_PHY_TX_CSR50_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR50_tx_fsm_clk_en_gt_START (0)
#define SOC_MUDP_PHY_TX_CSR50_tx_fsm_clk_en_gt_END (0)
#define SOC_MUDP_PHY_TX_CSR50_tx_fsm_soft_rstn_START (1)
#define SOC_MUDP_PHY_TX_CSR50_tx_fsm_soft_rstn_END (1)
#define SOC_MUDP_PHY_TX_CSR50_tx_fsm_start_dg_START (2)
#define SOC_MUDP_PHY_TX_CSR50_tx_fsm_start_dg_END (2)
#define SOC_MUDP_PHY_TX_CSR50_tx_lp_ctrl_clk_en_gt_START (3)
#define SOC_MUDP_PHY_TX_CSR50_tx_lp_ctrl_clk_en_gt_END (3)
#define SOC_MUDP_PHY_TX_CSR50_tx_lp_ctrl_soft_rstn_START (4)
#define SOC_MUDP_PHY_TX_CSR50_tx_lp_ctrl_soft_rstn_END (4)
#define SOC_MUDP_PHY_TX_CSR50_tx_lp_ctrl_start_dg_START (5)
#define SOC_MUDP_PHY_TX_CSR50_tx_lp_ctrl_start_dg_END (5)
#define SOC_MUDP_PHY_TX_CSR50_tx_pa_clk_en_gt_START (6)
#define SOC_MUDP_PHY_TX_CSR50_tx_pa_clk_en_gt_END (6)
#define SOC_MUDP_PHY_TX_CSR50_tx_pa_grbx_soft_rstn_START (7)
#define SOC_MUDP_PHY_TX_CSR50_tx_pa_grbx_soft_rstn_END (7)
#define SOC_MUDP_PHY_TX_CSR50_tx_prbs_clk_en_START (8)
#define SOC_MUDP_PHY_TX_CSR50_tx_prbs_clk_en_END (8)
#define SOC_MUDP_PHY_TX_CSR50_tx_prbs_soft_rstn_START (9)
#define SOC_MUDP_PHY_TX_CSR50_tx_prbs_soft_rstn_END (9)
#define SOC_MUDP_PHY_TX_CSR50_tx_soft_rstn_START (10)
#define SOC_MUDP_PHY_TX_CSR50_tx_soft_rstn_END (10)
#define SOC_MUDP_PHY_TX_CSR50_tx_txi_clk_en_START (11)
#define SOC_MUDP_PHY_TX_CSR50_tx_txi_clk_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txdrv_up_cal : 4;
        unsigned int txdrv_cboost_en : 4;
        unsigned int reserved_0 : 18;
        unsigned int txcp_clktree_ac_bypass : 1;
        unsigned int txcp_source_sel : 2;
        unsigned int dscp_rcv_hsclk_ac_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_MUDP_PHY_TX_CSR51_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR51_txdrv_up_cal_START (0)
#define SOC_MUDP_PHY_TX_CSR51_txdrv_up_cal_END (3)
#define SOC_MUDP_PHY_TX_CSR51_txdrv_cboost_en_START (4)
#define SOC_MUDP_PHY_TX_CSR51_txdrv_cboost_en_END (7)
#define SOC_MUDP_PHY_TX_CSR51_txcp_clktree_ac_bypass_START (26)
#define SOC_MUDP_PHY_TX_CSR51_txcp_clktree_ac_bypass_END (26)
#define SOC_MUDP_PHY_TX_CSR51_txcp_source_sel_START (27)
#define SOC_MUDP_PHY_TX_CSR51_txcp_source_sel_END (28)
#define SOC_MUDP_PHY_TX_CSR51_dscp_rcv_hsclk_ac_bypass_START (29)
#define SOC_MUDP_PHY_TX_CSR51_dscp_rcv_hsclk_ac_bypass_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txcp_ctb_pwrdnb : 1;
        unsigned int txcp_ctb_local_pwrdnb : 1;
        unsigned int txatb_top : 3;
        unsigned int txdp_lpbk_sel : 1;
        unsigned int txdp_lpbk_local_pwrdnb : 1;
        unsigned int txdp_lpbk_pwrdnb : 1;
        unsigned int txdrv_idle_pulldn_en : 1;
        unsigned int txdrv_idle_pwrdnb : 1;
        unsigned int txdrv_tap_inv_enb : 1;
        unsigned int reserved : 1;
        unsigned int txdrv_dn_cal : 4;
        unsigned int txdrv_oc : 16;
    } reg;
} SOC_MUDP_PHY_TX_CSR52_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR52_txcp_ctb_pwrdnb_START (0)
#define SOC_MUDP_PHY_TX_CSR52_txcp_ctb_pwrdnb_END (0)
#define SOC_MUDP_PHY_TX_CSR52_txcp_ctb_local_pwrdnb_START (1)
#define SOC_MUDP_PHY_TX_CSR52_txcp_ctb_local_pwrdnb_END (1)
#define SOC_MUDP_PHY_TX_CSR52_txatb_top_START (2)
#define SOC_MUDP_PHY_TX_CSR52_txatb_top_END (4)
#define SOC_MUDP_PHY_TX_CSR52_txdp_lpbk_sel_START (5)
#define SOC_MUDP_PHY_TX_CSR52_txdp_lpbk_sel_END (5)
#define SOC_MUDP_PHY_TX_CSR52_txdp_lpbk_local_pwrdnb_START (6)
#define SOC_MUDP_PHY_TX_CSR52_txdp_lpbk_local_pwrdnb_END (6)
#define SOC_MUDP_PHY_TX_CSR52_txdp_lpbk_pwrdnb_START (7)
#define SOC_MUDP_PHY_TX_CSR52_txdp_lpbk_pwrdnb_END (7)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_idle_pulldn_en_START (8)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_idle_pulldn_en_END (8)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_idle_pwrdnb_START (9)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_idle_pwrdnb_END (9)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_tap_inv_enb_START (10)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_tap_inv_enb_END (10)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_dn_cal_START (12)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_dn_cal_END (15)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_oc_START (16)
#define SOC_MUDP_PHY_TX_CSR52_txdrv_oc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 22;
        unsigned int tx_spare : 8;
        unsigned int txcp_ctb_ac_bypass : 1;
        unsigned int txcp_ctb_localsel : 1;
    } reg;
} SOC_MUDP_PHY_TX_CSR53_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR53_tx_spare_START (22)
#define SOC_MUDP_PHY_TX_CSR53_tx_spare_END (29)
#define SOC_MUDP_PHY_TX_CSR53_txcp_ctb_ac_bypass_START (30)
#define SOC_MUDP_PHY_TX_CSR53_txcp_ctb_ac_bypass_END (30)
#define SOC_MUDP_PHY_TX_CSR53_txcp_ctb_localsel_START (31)
#define SOC_MUDP_PHY_TX_CSR53_txcp_ctb_localsel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txreg_data_vref_sel : 5;
        unsigned int vref_source_icv_selb : 1;
        unsigned int txreg_drv_ref_pwrdnb : 1;
        unsigned int reserved_0 : 1;
        unsigned int txreg_data_ref_pwrdnb : 1;
        unsigned int reserved_1 : 1;
        unsigned int ds_atb_sel : 3;
        unsigned int ds_ldo_top_atb_sel : 3;
        unsigned int ds_supplyhalf_atb_sel : 2;
        unsigned int ds_ldobst_atb_sel : 3;
        unsigned int ds_biasrcv_icv_atb_sel : 3;
        unsigned int ds_biasrcv_icc_atb_sel : 3;
        unsigned int ds_biasrcv_diffmode_sel : 1;
        unsigned int ds_biasrcv_icv_testmode : 1;
        unsigned int ds_biasrcv_icc_testmode : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MUDP_PHY_TX_CSR54_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR54_txreg_data_vref_sel_START (0)
#define SOC_MUDP_PHY_TX_CSR54_txreg_data_vref_sel_END (4)
#define SOC_MUDP_PHY_TX_CSR54_vref_source_icv_selb_START (5)
#define SOC_MUDP_PHY_TX_CSR54_vref_source_icv_selb_END (5)
#define SOC_MUDP_PHY_TX_CSR54_txreg_drv_ref_pwrdnb_START (6)
#define SOC_MUDP_PHY_TX_CSR54_txreg_drv_ref_pwrdnb_END (6)
#define SOC_MUDP_PHY_TX_CSR54_txreg_data_ref_pwrdnb_START (8)
#define SOC_MUDP_PHY_TX_CSR54_txreg_data_ref_pwrdnb_END (8)
#define SOC_MUDP_PHY_TX_CSR54_ds_atb_sel_START (10)
#define SOC_MUDP_PHY_TX_CSR54_ds_atb_sel_END (12)
#define SOC_MUDP_PHY_TX_CSR54_ds_ldo_top_atb_sel_START (13)
#define SOC_MUDP_PHY_TX_CSR54_ds_ldo_top_atb_sel_END (15)
#define SOC_MUDP_PHY_TX_CSR54_ds_supplyhalf_atb_sel_START (16)
#define SOC_MUDP_PHY_TX_CSR54_ds_supplyhalf_atb_sel_END (17)
#define SOC_MUDP_PHY_TX_CSR54_ds_ldobst_atb_sel_START (18)
#define SOC_MUDP_PHY_TX_CSR54_ds_ldobst_atb_sel_END (20)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icv_atb_sel_START (21)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icv_atb_sel_END (23)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icc_atb_sel_START (24)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icc_atb_sel_END (26)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_diffmode_sel_START (27)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_diffmode_sel_END (27)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icv_testmode_START (28)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icv_testmode_END (28)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icc_testmode_START (29)
#define SOC_MUDP_PHY_TX_CSR54_ds_biasrcv_icc_testmode_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int ds_ana_id : 6;
        unsigned int reserved_1 : 1;
        unsigned int ds_ldobst_bias_source_sel : 1;
        unsigned int ds_ldobst_bypass_preldo : 1;
        unsigned int reserved_2 : 2;
        unsigned int ds_cpump_half_en : 1;
        unsigned int ds_cpump_clkdiv2_sel : 1;
        unsigned int reserved_3 : 2;
        unsigned int ds_ldobst_vref_sel : 5;
        unsigned int reserved_4 : 5;
        unsigned int txrxreg_clk_vref_sel : 5;
    } reg;
} SOC_MUDP_PHY_TX_CSR55_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR55_ds_ana_id_START (2)
#define SOC_MUDP_PHY_TX_CSR55_ds_ana_id_END (7)
#define SOC_MUDP_PHY_TX_CSR55_ds_ldobst_bias_source_sel_START (9)
#define SOC_MUDP_PHY_TX_CSR55_ds_ldobst_bias_source_sel_END (9)
#define SOC_MUDP_PHY_TX_CSR55_ds_ldobst_bypass_preldo_START (10)
#define SOC_MUDP_PHY_TX_CSR55_ds_ldobst_bypass_preldo_END (10)
#define SOC_MUDP_PHY_TX_CSR55_ds_cpump_half_en_START (13)
#define SOC_MUDP_PHY_TX_CSR55_ds_cpump_half_en_END (13)
#define SOC_MUDP_PHY_TX_CSR55_ds_cpump_clkdiv2_sel_START (14)
#define SOC_MUDP_PHY_TX_CSR55_ds_cpump_clkdiv2_sel_END (14)
#define SOC_MUDP_PHY_TX_CSR55_ds_ldobst_vref_sel_START (17)
#define SOC_MUDP_PHY_TX_CSR55_ds_ldobst_vref_sel_END (21)
#define SOC_MUDP_PHY_TX_CSR55_txrxreg_clk_vref_sel_START (27)
#define SOC_MUDP_PHY_TX_CSR55_txrxreg_clk_vref_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txreg_data_bias_source_sel : 1;
        unsigned int txreg_drv_bias_source_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int txrxreg_clk_bypassb : 1;
        unsigned int txrxreg_clk_eospro_dio_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int txrxreg_clk_overshoot_ctrl : 2;
        unsigned int reserved_2 : 2;
        unsigned int txreg_data_atb_sel : 3;
        unsigned int reserved_3 : 1;
        unsigned int txreg_data_bypassb : 1;
        unsigned int txreg_data_eospro_dio_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int txreg_data_overshoot_ctrl : 2;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int txreg_drv_atb_sel : 3;
        unsigned int reserved_7 : 1;
        unsigned int txreg_drv_bypassb : 1;
        unsigned int txreg_drv_eospro_dio_en : 1;
        unsigned int reserved_8 : 1;
        unsigned int txreg_drv_lo_selb : 1;
        unsigned int txreg_drv_hibw_selb : 1;
        unsigned int txreg_drv_overshoot_ctrl : 2;
    } reg;
} SOC_MUDP_PHY_TX_CSR56_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_bias_source_sel_START (0)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_bias_source_sel_END (0)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_bias_source_sel_START (1)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_bias_source_sel_END (1)
#define SOC_MUDP_PHY_TX_CSR56_txrxreg_clk_bypassb_START (3)
#define SOC_MUDP_PHY_TX_CSR56_txrxreg_clk_bypassb_END (3)
#define SOC_MUDP_PHY_TX_CSR56_txrxreg_clk_eospro_dio_en_START (4)
#define SOC_MUDP_PHY_TX_CSR56_txrxreg_clk_eospro_dio_en_END (4)
#define SOC_MUDP_PHY_TX_CSR56_txrxreg_clk_overshoot_ctrl_START (6)
#define SOC_MUDP_PHY_TX_CSR56_txrxreg_clk_overshoot_ctrl_END (7)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_atb_sel_START (10)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_atb_sel_END (12)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_bypassb_START (14)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_bypassb_END (14)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_eospro_dio_en_START (15)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_eospro_dio_en_END (15)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_overshoot_ctrl_START (17)
#define SOC_MUDP_PHY_TX_CSR56_txreg_data_overshoot_ctrl_END (18)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_atb_sel_START (21)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_atb_sel_END (23)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_bypassb_START (25)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_bypassb_END (25)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_eospro_dio_en_START (26)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_eospro_dio_en_END (26)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_lo_selb_START (28)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_lo_selb_END (28)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_hibw_selb_START (29)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_hibw_selb_END (29)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_overshoot_ctrl_START (30)
#define SOC_MUDP_PHY_TX_CSR56_txreg_drv_overshoot_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int rxds_lvcc_pwrdnb : 1;
        unsigned int lvccldo_rx_atb_sel : 3;
        unsigned int lvccldo_tx_atb_sel : 3;
        unsigned int lvccldo_rx_bleed_en : 1;
        unsigned int lvccldo_tx_bleed_en : 1;
        unsigned int lvccldo_fast_startup : 1;
        unsigned int lvccldo_rx_vref_sel : 3;
        unsigned int lvccldo_tx_vref_sel : 3;
        unsigned int ds_ldo_htol_en : 1;
        unsigned int ds_lvccldo_bias_source_sel : 1;
        unsigned int txrxreg_clk_bias_source_sel : 1;
        unsigned int txrxreg_clk_atb_sel : 3;
    } reg;
} SOC_MUDP_PHY_TX_CSR57_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR57_rxds_lvcc_pwrdnb_START (10)
#define SOC_MUDP_PHY_TX_CSR57_rxds_lvcc_pwrdnb_END (10)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_rx_atb_sel_START (11)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_rx_atb_sel_END (13)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_tx_atb_sel_START (14)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_tx_atb_sel_END (16)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_rx_bleed_en_START (17)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_rx_bleed_en_END (17)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_tx_bleed_en_START (18)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_tx_bleed_en_END (18)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_fast_startup_START (19)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_fast_startup_END (19)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_rx_vref_sel_START (20)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_rx_vref_sel_END (22)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_tx_vref_sel_START (23)
#define SOC_MUDP_PHY_TX_CSR57_lvccldo_tx_vref_sel_END (25)
#define SOC_MUDP_PHY_TX_CSR57_ds_ldo_htol_en_START (26)
#define SOC_MUDP_PHY_TX_CSR57_ds_ldo_htol_en_END (26)
#define SOC_MUDP_PHY_TX_CSR57_ds_lvccldo_bias_source_sel_START (27)
#define SOC_MUDP_PHY_TX_CSR57_ds_lvccldo_bias_source_sel_END (27)
#define SOC_MUDP_PHY_TX_CSR57_txrxreg_clk_bias_source_sel_START (28)
#define SOC_MUDP_PHY_TX_CSR57_txrxreg_clk_bias_source_sel_END (28)
#define SOC_MUDP_PHY_TX_CSR57_txrxreg_clk_atb_sel_START (29)
#define SOC_MUDP_PHY_TX_CSR57_txrxreg_clk_atb_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_width : 2;
        unsigned int reserved_0 : 17;
        unsigned int txcp_clktree_supply_sel : 1;
        unsigned int txdp_predrv_supply_sel : 1;
        unsigned int txdata_supply_sel : 1;
        unsigned int txcp_hsclk_supply_sel : 1;
        unsigned int rxabe_supply_sel : 1;
        unsigned int rxafe_supply_sel : 1;
        unsigned int rxcp_hsclk_supply_sel : 1;
        unsigned int ds_biasrcv_icv_pwrdnb : 1;
        unsigned int ds_biasrcv_icc_pwrdnb : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MUDP_PHY_TX_CSR58_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR58_tx_width_START (0)
#define SOC_MUDP_PHY_TX_CSR58_tx_width_END (1)
#define SOC_MUDP_PHY_TX_CSR58_txcp_clktree_supply_sel_START (19)
#define SOC_MUDP_PHY_TX_CSR58_txcp_clktree_supply_sel_END (19)
#define SOC_MUDP_PHY_TX_CSR58_txdp_predrv_supply_sel_START (20)
#define SOC_MUDP_PHY_TX_CSR58_txdp_predrv_supply_sel_END (20)
#define SOC_MUDP_PHY_TX_CSR58_txdata_supply_sel_START (21)
#define SOC_MUDP_PHY_TX_CSR58_txdata_supply_sel_END (21)
#define SOC_MUDP_PHY_TX_CSR58_txcp_hsclk_supply_sel_START (22)
#define SOC_MUDP_PHY_TX_CSR58_txcp_hsclk_supply_sel_END (22)
#define SOC_MUDP_PHY_TX_CSR58_rxabe_supply_sel_START (23)
#define SOC_MUDP_PHY_TX_CSR58_rxabe_supply_sel_END (23)
#define SOC_MUDP_PHY_TX_CSR58_rxafe_supply_sel_START (24)
#define SOC_MUDP_PHY_TX_CSR58_rxafe_supply_sel_END (24)
#define SOC_MUDP_PHY_TX_CSR58_rxcp_hsclk_supply_sel_START (25)
#define SOC_MUDP_PHY_TX_CSR58_rxcp_hsclk_supply_sel_END (25)
#define SOC_MUDP_PHY_TX_CSR58_ds_biasrcv_icv_pwrdnb_START (26)
#define SOC_MUDP_PHY_TX_CSR58_ds_biasrcv_icv_pwrdnb_END (26)
#define SOC_MUDP_PHY_TX_CSR58_ds_biasrcv_icc_pwrdnb_START (27)
#define SOC_MUDP_PHY_TX_CSR58_ds_biasrcv_icc_pwrdnb_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int txdp_wdiv_sel : 2;
        unsigned int txreg_drv_vref_sel : 5;
        unsigned int txcp_wclk_timingwindow_sel : 2;
        unsigned int txcp_dcd_adj_sign : 1;
        unsigned int txcp_dcd_adj_en : 4;
        unsigned int txcp_prediv_sel : 3;
        unsigned int tx_lpctrl_final_step_wait_time : 6;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_MUDP_PHY_TX_CSR59_UNION;
#endif
#define SOC_MUDP_PHY_TX_CSR59_txdp_wdiv_sel_START (2)
#define SOC_MUDP_PHY_TX_CSR59_txdp_wdiv_sel_END (3)
#define SOC_MUDP_PHY_TX_CSR59_txreg_drv_vref_sel_START (4)
#define SOC_MUDP_PHY_TX_CSR59_txreg_drv_vref_sel_END (8)
#define SOC_MUDP_PHY_TX_CSR59_txcp_wclk_timingwindow_sel_START (9)
#define SOC_MUDP_PHY_TX_CSR59_txcp_wclk_timingwindow_sel_END (10)
#define SOC_MUDP_PHY_TX_CSR59_txcp_dcd_adj_sign_START (11)
#define SOC_MUDP_PHY_TX_CSR59_txcp_dcd_adj_sign_END (11)
#define SOC_MUDP_PHY_TX_CSR59_txcp_dcd_adj_en_START (12)
#define SOC_MUDP_PHY_TX_CSR59_txcp_dcd_adj_en_END (15)
#define SOC_MUDP_PHY_TX_CSR59_txcp_prediv_sel_START (16)
#define SOC_MUDP_PHY_TX_CSR59_txcp_prediv_sel_END (18)
#define SOC_MUDP_PHY_TX_CSR59_tx_lpctrl_final_step_wait_time_START (19)
#define SOC_MUDP_PHY_TX_CSR59_tx_lpctrl_final_step_wait_time_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_dig_slice_id : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PHY_RX_CSR0_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR0_rx_dig_slice_id_START (0)
#define SOC_MUDP_PHY_RX_CSR0_rx_dig_slice_id_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr1_ra : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR1_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR1_rx_fsm_sfr1_ra_START (0)
#define SOC_MUDP_PHY_RX_CSR1_rx_fsm_sfr1_ra_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr2_sp : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR2_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR2_rx_fsm_sfr2_sp_START (0)
#define SOC_MUDP_PHY_RX_CSR2_rx_fsm_sfr2_sp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr3_gp : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR3_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR3_rx_fsm_sfr3_gp_START (0)
#define SOC_MUDP_PHY_RX_CSR3_rx_fsm_sfr3_gp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr4_ap : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR4_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR4_rx_fsm_sfr4_ap_START (0)
#define SOC_MUDP_PHY_RX_CSR4_rx_fsm_sfr4_ap_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr5_vp : 22;
        unsigned int rx_fsm_sram_mask : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR5_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR5_rx_fsm_sfr5_vp_START (0)
#define SOC_MUDP_PHY_RX_CSR5_rx_fsm_sfr5_vp_END (21)
#define SOC_MUDP_PHY_RX_CSR5_rx_fsm_sram_mask_START (22)
#define SOC_MUDP_PHY_RX_CSR5_rx_fsm_sram_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr6_rp0 : 22;
        unsigned int rx_fsm_reg_mask : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR6_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR6_rx_fsm_sfr6_rp0_START (0)
#define SOC_MUDP_PHY_RX_CSR6_rx_fsm_sfr6_rp0_END (21)
#define SOC_MUDP_PHY_RX_CSR6_rx_fsm_reg_mask_START (22)
#define SOC_MUDP_PHY_RX_CSR6_rx_fsm_reg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr7_rp1 : 22;
        unsigned int rx_fsm_status : 3;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PHY_RX_CSR7_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR7_rx_fsm_sfr7_rp1_START (0)
#define SOC_MUDP_PHY_RX_CSR7_rx_fsm_sfr7_rp1_END (21)
#define SOC_MUDP_PHY_RX_CSR7_rx_fsm_status_START (22)
#define SOC_MUDP_PHY_RX_CSR7_rx_fsm_status_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr8_pc : 22;
        unsigned int rx_fsm_done : 1;
        unsigned int rx_fsm_cmd : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_MUDP_PHY_RX_CSR8_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR8_rx_fsm_sfr8_pc_START (0)
#define SOC_MUDP_PHY_RX_CSR8_rx_fsm_sfr8_pc_END (21)
#define SOC_MUDP_PHY_RX_CSR8_rx_fsm_done_START (22)
#define SOC_MUDP_PHY_RX_CSR8_rx_fsm_done_END (22)
#define SOC_MUDP_PHY_RX_CSR8_rx_fsm_cmd_START (23)
#define SOC_MUDP_PHY_RX_CSR8_rx_fsm_cmd_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr9_opl : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR9_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR9_rx_fsm_sfr9_opl_START (0)
#define SOC_MUDP_PHY_RX_CSR9_rx_fsm_sfr9_opl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr10_opr : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR10_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR10_rx_fsm_sfr10_opr_START (0)
#define SOC_MUDP_PHY_RX_CSR10_rx_fsm_sfr10_opr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr11_opd : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR11_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR11_rx_fsm_sfr11_opd_START (0)
#define SOC_MUDP_PHY_RX_CSR11_rx_fsm_sfr11_opd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr12_a0 : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR12_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR12_rx_fsm_sfr12_a0_START (0)
#define SOC_MUDP_PHY_RX_CSR12_rx_fsm_sfr12_a0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr13_a1 : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR13_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR13_rx_fsm_sfr13_a1_START (0)
#define SOC_MUDP_PHY_RX_CSR13_rx_fsm_sfr13_a1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr14_a2 : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR14_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR14_rx_fsm_sfr14_a2_START (0)
#define SOC_MUDP_PHY_RX_CSR14_rx_fsm_sfr14_a2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sfr15_a3 : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR15_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR15_rx_fsm_sfr15_a3_START (0)
#define SOC_MUDP_PHY_RX_CSR15_rx_fsm_sfr15_a3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_reg_addr : 16;
        unsigned int rx_fsm_sram_addr : 16;
    } reg;
} SOC_MUDP_PHY_RX_CSR16_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR16_rx_fsm_reg_addr_START (0)
#define SOC_MUDP_PHY_RX_CSR16_rx_fsm_reg_addr_END (15)
#define SOC_MUDP_PHY_RX_CSR16_rx_fsm_sram_addr_START (16)
#define SOC_MUDP_PHY_RX_CSR16_rx_fsm_sram_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_start : 1;
        unsigned int rx_fsm_start_addr : 16;
        unsigned int rx_fsm_hold_en : 1;
        unsigned int rx_fsm_freeze : 1;
        unsigned int rx_fsm_clr : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_RX_CSR17_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_start_START (0)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_start_END (0)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_start_addr_START (1)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_start_addr_END (16)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_hold_en_START (17)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_hold_en_END (17)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_freeze_START (18)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_freeze_END (18)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_clr_START (19)
#define SOC_MUDP_PHY_RX_CSR17_rx_fsm_clr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_timer_base : 14;
        unsigned int rx_fsm_timer_exp : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PHY_RX_CSR18_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR18_rx_fsm_timer_base_START (0)
#define SOC_MUDP_PHY_RX_CSR18_rx_fsm_timer_base_END (13)
#define SOC_MUDP_PHY_RX_CSR18_rx_fsm_timer_exp_START (14)
#define SOC_MUDP_PHY_RX_CSR18_rx_fsm_timer_exp_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_int0 : 4;
        unsigned int rx_fsm_int1 : 4;
        unsigned int rx_fsm_int2 : 4;
        unsigned int rx_pll0_req : 1;
        unsigned int rx_pll1_req : 1;
        unsigned int rx_init_req : 1;
        unsigned int rx_all_slice_pll0_req : 1;
        unsigned int rx_all_slice_pll1_req : 1;
        unsigned int rx_all_slice_init_req : 1;
        unsigned int rx_pll0_status : 1;
        unsigned int rx_pll1_status : 1;
        unsigned int rx_init_status : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_MUDP_PHY_RX_CSR19_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR19_rx_fsm_int0_START (0)
#define SOC_MUDP_PHY_RX_CSR19_rx_fsm_int0_END (3)
#define SOC_MUDP_PHY_RX_CSR19_rx_fsm_int1_START (4)
#define SOC_MUDP_PHY_RX_CSR19_rx_fsm_int1_END (7)
#define SOC_MUDP_PHY_RX_CSR19_rx_fsm_int2_START (8)
#define SOC_MUDP_PHY_RX_CSR19_rx_fsm_int2_END (11)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll0_req_START (12)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll0_req_END (12)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll1_req_START (13)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll1_req_END (13)
#define SOC_MUDP_PHY_RX_CSR19_rx_init_req_START (14)
#define SOC_MUDP_PHY_RX_CSR19_rx_init_req_END (14)
#define SOC_MUDP_PHY_RX_CSR19_rx_all_slice_pll0_req_START (15)
#define SOC_MUDP_PHY_RX_CSR19_rx_all_slice_pll0_req_END (15)
#define SOC_MUDP_PHY_RX_CSR19_rx_all_slice_pll1_req_START (16)
#define SOC_MUDP_PHY_RX_CSR19_rx_all_slice_pll1_req_END (16)
#define SOC_MUDP_PHY_RX_CSR19_rx_all_slice_init_req_START (17)
#define SOC_MUDP_PHY_RX_CSR19_rx_all_slice_init_req_END (17)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll0_status_START (18)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll0_status_END (18)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll1_status_START (19)
#define SOC_MUDP_PHY_RX_CSR19_rx_pll1_status_END (19)
#define SOC_MUDP_PHY_RX_CSR19_rx_init_status_START (20)
#define SOC_MUDP_PHY_RX_CSR19_rx_init_status_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 28;
        unsigned int rx_fsm_clr_en : 1;
        unsigned int rx_fsm_wait_flag_ctrl : 2;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_MUDP_PHY_RX_CSR24_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR24_rx_fsm_clr_en_START (28)
#define SOC_MUDP_PHY_RX_CSR24_rx_fsm_clr_en_END (28)
#define SOC_MUDP_PHY_RX_CSR24_rx_fsm_wait_flag_ctrl_START (29)
#define SOC_MUDP_PHY_RX_CSR24_rx_fsm_wait_flag_ctrl_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_sdpi_event_status : 16;
        unsigned int rx_sdpi_ready : 1;
        unsigned int rx_sdpi_event_ack : 1;
        unsigned int rx_fsm_curr_fw : 5;
        unsigned int reserved : 9;
    } reg;
} SOC_MUDP_PHY_RX_CSR25_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR25_rx_sdpi_event_status_START (0)
#define SOC_MUDP_PHY_RX_CSR25_rx_sdpi_event_status_END (15)
#define SOC_MUDP_PHY_RX_CSR25_rx_sdpi_ready_START (16)
#define SOC_MUDP_PHY_RX_CSR25_rx_sdpi_ready_END (16)
#define SOC_MUDP_PHY_RX_CSR25_rx_sdpi_event_ack_START (17)
#define SOC_MUDP_PHY_RX_CSR25_rx_sdpi_event_ack_END (17)
#define SOC_MUDP_PHY_RX_CSR25_rx_fsm_curr_fw_START (18)
#define SOC_MUDP_PHY_RX_CSR25_rx_fsm_curr_fw_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_sdpi_event_cmd_pin : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR26_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR26_rx_sdpi_event_cmd_pin_START (0)
#define SOC_MUDP_PHY_RX_CSR26_rx_sdpi_event_cmd_pin_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_sdpi_event_cmd : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR27_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR27_rx_sdpi_event_cmd_START (0)
#define SOC_MUDP_PHY_RX_CSR27_rx_sdpi_event_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_sdpi_event_enable_pin : 1;
        unsigned int rx_sdpi_reset_pin : 1;
        unsigned int rx_sdpi_mode_pin : 1;
        unsigned int reserved_0 : 3;
        unsigned int rx_sdpi_event_enable_status : 1;
        unsigned int rx_sdpi_reset_status : 1;
        unsigned int rx_sdpi_mode_status : 1;
        unsigned int reserved_1 : 3;
        unsigned int rx_sdpi_event_req : 1;
        unsigned int rx_sdpi_reset : 1;
        unsigned int rx_sdpi_mode : 1;
        unsigned int rx_sdpi_event_pin_en : 1;
        unsigned int rx_sdpi_reset_pin_en : 1;
        unsigned int rx_sdpi_phy_mode_pin_en : 1;
        unsigned int rx_sdpi_reset_fsm_en : 1;
        unsigned int rx_sdpi_event_fsm_en : 9;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_MUDP_PHY_RX_CSR28_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_enable_pin_START (0)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_enable_pin_END (0)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_pin_START (1)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_pin_END (1)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_mode_pin_START (2)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_mode_pin_END (2)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_enable_status_START (6)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_enable_status_END (6)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_status_START (7)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_status_END (7)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_mode_status_START (8)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_mode_status_END (8)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_req_START (12)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_req_END (12)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_START (13)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_END (13)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_mode_START (14)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_mode_END (14)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_pin_en_START (15)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_pin_en_END (15)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_pin_en_START (16)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_pin_en_END (16)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_phy_mode_pin_en_START (17)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_phy_mode_pin_en_END (17)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_fsm_en_START (18)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_reset_fsm_en_END (18)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_fsm_en_START (19)
#define SOC_MUDP_PHY_RX_CSR28_rx_sdpi_event_fsm_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_waiting_for_lpctrl_rsp : 1;
        unsigned int rx_lpctrl_hw_call_enable : 1;
        unsigned int rx_curr_pwr_status : 4;
        unsigned int rx_curr_rate_status : 6;
        unsigned int rx_spare_out : 2;
        unsigned int rx_spare_in : 2;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PHY_RX_CSR29_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR29_rx_waiting_for_lpctrl_rsp_START (0)
#define SOC_MUDP_PHY_RX_CSR29_rx_waiting_for_lpctrl_rsp_END (0)
#define SOC_MUDP_PHY_RX_CSR29_rx_lpctrl_hw_call_enable_START (1)
#define SOC_MUDP_PHY_RX_CSR29_rx_lpctrl_hw_call_enable_END (1)
#define SOC_MUDP_PHY_RX_CSR29_rx_curr_pwr_status_START (2)
#define SOC_MUDP_PHY_RX_CSR29_rx_curr_pwr_status_END (5)
#define SOC_MUDP_PHY_RX_CSR29_rx_curr_rate_status_START (6)
#define SOC_MUDP_PHY_RX_CSR29_rx_curr_rate_status_END (11)
#define SOC_MUDP_PHY_RX_CSR29_rx_spare_out_START (12)
#define SOC_MUDP_PHY_RX_CSR29_rx_spare_out_END (13)
#define SOC_MUDP_PHY_RX_CSR29_rx_spare_in_START (14)
#define SOC_MUDP_PHY_RX_CSR29_rx_spare_in_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_sdpi_start_addr : 16;
        unsigned int rx_fsm_pin_start_addr : 16;
    } reg;
} SOC_MUDP_PHY_RX_CSR30_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR30_rx_fsm_sdpi_start_addr_START (0)
#define SOC_MUDP_PHY_RX_CSR30_rx_fsm_sdpi_start_addr_END (15)
#define SOC_MUDP_PHY_RX_CSR30_rx_fsm_pin_start_addr_START (16)
#define SOC_MUDP_PHY_RX_CSR30_rx_fsm_pin_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR31_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR32_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_calib_wclk_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int rx_eyemon_wclk_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int rx_owclk_en : 1;
        unsigned int rx_prbs_wclk_en : 1;
        unsigned int rx_rx2tx_paralpbk_wclk_en : 1;
        unsigned int rx_edge_isi_wclk_en : 1;
        unsigned int rx_wclk_gate : 1;
        unsigned int rx_wclk_en : 1;
        unsigned int rx_lp_ctrl_clk_en : 1;
        unsigned int rx_fsm_clk_en : 1;
        unsigned int rx_latch_start_en : 1;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_MUDP_PHY_RX_CSR33_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR33_rx_calib_wclk_en_START (0)
#define SOC_MUDP_PHY_RX_CSR33_rx_calib_wclk_en_END (0)
#define SOC_MUDP_PHY_RX_CSR33_rx_eyemon_wclk_en_START (2)
#define SOC_MUDP_PHY_RX_CSR33_rx_eyemon_wclk_en_END (2)
#define SOC_MUDP_PHY_RX_CSR33_rx_owclk_en_START (4)
#define SOC_MUDP_PHY_RX_CSR33_rx_owclk_en_END (4)
#define SOC_MUDP_PHY_RX_CSR33_rx_prbs_wclk_en_START (5)
#define SOC_MUDP_PHY_RX_CSR33_rx_prbs_wclk_en_END (5)
#define SOC_MUDP_PHY_RX_CSR33_rx_rx2tx_paralpbk_wclk_en_START (6)
#define SOC_MUDP_PHY_RX_CSR33_rx_rx2tx_paralpbk_wclk_en_END (6)
#define SOC_MUDP_PHY_RX_CSR33_rx_edge_isi_wclk_en_START (7)
#define SOC_MUDP_PHY_RX_CSR33_rx_edge_isi_wclk_en_END (7)
#define SOC_MUDP_PHY_RX_CSR33_rx_wclk_gate_START (8)
#define SOC_MUDP_PHY_RX_CSR33_rx_wclk_gate_END (8)
#define SOC_MUDP_PHY_RX_CSR33_rx_wclk_en_START (9)
#define SOC_MUDP_PHY_RX_CSR33_rx_wclk_en_END (9)
#define SOC_MUDP_PHY_RX_CSR33_rx_lp_ctrl_clk_en_START (10)
#define SOC_MUDP_PHY_RX_CSR33_rx_lp_ctrl_clk_en_END (10)
#define SOC_MUDP_PHY_RX_CSR33_rx_fsm_clk_en_START (11)
#define SOC_MUDP_PHY_RX_CSR33_rx_fsm_clk_en_END (11)
#define SOC_MUDP_PHY_RX_CSR33_rx_latch_start_en_START (12)
#define SOC_MUDP_PHY_RX_CSR33_rx_latch_start_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_soft_rstn : 1;
        unsigned int rx_calib_soft_rstn : 1;
        unsigned int rx_cdr_soft_rstn : 1;
        unsigned int rx_eyemon_soft_rstn : 1;
        unsigned int rx_prbs_soft_rstn : 1;
        unsigned int rx_ospd_soft_rstn : 1;
        unsigned int rx_o_soft_rstn : 1;
        unsigned int rx_gearbox_soft_rstn : 1;
        unsigned int rx_soft_rstn : 1;
        unsigned int rx_edge_isi_soft_rstn : 1;
        unsigned int rx_lp_ctrl_soft_rstn : 1;
        unsigned int rx_cdr_en : 1;
        unsigned int rx_prbs_chk_en : 1;
        unsigned int rx_ospd_en : 1;
        unsigned int rx_width : 2;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PHY_RX_CSR34_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR34_rx_fsm_soft_rstn_START (0)
#define SOC_MUDP_PHY_RX_CSR34_rx_fsm_soft_rstn_END (0)
#define SOC_MUDP_PHY_RX_CSR34_rx_calib_soft_rstn_START (1)
#define SOC_MUDP_PHY_RX_CSR34_rx_calib_soft_rstn_END (1)
#define SOC_MUDP_PHY_RX_CSR34_rx_cdr_soft_rstn_START (2)
#define SOC_MUDP_PHY_RX_CSR34_rx_cdr_soft_rstn_END (2)
#define SOC_MUDP_PHY_RX_CSR34_rx_eyemon_soft_rstn_START (3)
#define SOC_MUDP_PHY_RX_CSR34_rx_eyemon_soft_rstn_END (3)
#define SOC_MUDP_PHY_RX_CSR34_rx_prbs_soft_rstn_START (4)
#define SOC_MUDP_PHY_RX_CSR34_rx_prbs_soft_rstn_END (4)
#define SOC_MUDP_PHY_RX_CSR34_rx_ospd_soft_rstn_START (5)
#define SOC_MUDP_PHY_RX_CSR34_rx_ospd_soft_rstn_END (5)
#define SOC_MUDP_PHY_RX_CSR34_rx_o_soft_rstn_START (6)
#define SOC_MUDP_PHY_RX_CSR34_rx_o_soft_rstn_END (6)
#define SOC_MUDP_PHY_RX_CSR34_rx_gearbox_soft_rstn_START (7)
#define SOC_MUDP_PHY_RX_CSR34_rx_gearbox_soft_rstn_END (7)
#define SOC_MUDP_PHY_RX_CSR34_rx_soft_rstn_START (8)
#define SOC_MUDP_PHY_RX_CSR34_rx_soft_rstn_END (8)
#define SOC_MUDP_PHY_RX_CSR34_rx_edge_isi_soft_rstn_START (9)
#define SOC_MUDP_PHY_RX_CSR34_rx_edge_isi_soft_rstn_END (9)
#define SOC_MUDP_PHY_RX_CSR34_rx_lp_ctrl_soft_rstn_START (10)
#define SOC_MUDP_PHY_RX_CSR34_rx_lp_ctrl_soft_rstn_END (10)
#define SOC_MUDP_PHY_RX_CSR34_rx_cdr_en_START (11)
#define SOC_MUDP_PHY_RX_CSR34_rx_cdr_en_END (11)
#define SOC_MUDP_PHY_RX_CSR34_rx_prbs_chk_en_START (12)
#define SOC_MUDP_PHY_RX_CSR34_rx_prbs_chk_en_END (12)
#define SOC_MUDP_PHY_RX_CSR34_rx_ospd_en_START (13)
#define SOC_MUDP_PHY_RX_CSR34_rx_ospd_en_END (13)
#define SOC_MUDP_PHY_RX_CSR34_rx_width_START (14)
#define SOC_MUDP_PHY_RX_CSR34_rx_width_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_tx2rx_paralpbk_en : 1;
        unsigned int rx_bitorder_inv : 1;
        unsigned int rx_polarity_inv_status : 1;
        unsigned int rx_polarity_inv : 1;
        unsigned int rx_polarity_pin_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MUDP_PHY_RX_CSR35_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR35_rx_tx2rx_paralpbk_en_START (0)
#define SOC_MUDP_PHY_RX_CSR35_rx_tx2rx_paralpbk_en_END (0)
#define SOC_MUDP_PHY_RX_CSR35_rx_bitorder_inv_START (1)
#define SOC_MUDP_PHY_RX_CSR35_rx_bitorder_inv_END (1)
#define SOC_MUDP_PHY_RX_CSR35_rx_polarity_inv_status_START (2)
#define SOC_MUDP_PHY_RX_CSR35_rx_polarity_inv_status_END (2)
#define SOC_MUDP_PHY_RX_CSR35_rx_polarity_inv_START (3)
#define SOC_MUDP_PHY_RX_CSR35_rx_polarity_inv_END (3)
#define SOC_MUDP_PHY_RX_CSR35_rx_polarity_pin_en_START (4)
#define SOC_MUDP_PHY_RX_CSR35_rx_polarity_pin_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_ospd_cdata_loca : 4;
        unsigned int rx_ospd_cdata_loca_delta : 4;
        unsigned int rx_ospd_lock_los : 1;
        unsigned int rx_ospd_channel_sel : 2;
        unsigned int rx_ospd_channel_force : 2;
        unsigned int rx_ospd_channel_shift : 1;
        unsigned int rx_ospd_mode : 1;
        unsigned int rx_ospd_clear : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PHY_RX_CSR36_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_cdata_loca_START (0)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_cdata_loca_END (3)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_cdata_loca_delta_START (4)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_cdata_loca_delta_END (7)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_lock_los_START (8)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_lock_los_END (8)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_channel_sel_START (9)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_channel_sel_END (10)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_channel_force_START (11)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_channel_force_END (12)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_channel_shift_START (13)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_channel_shift_END (13)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_mode_START (14)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_mode_END (14)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_clear_START (15)
#define SOC_MUDP_PHY_RX_CSR36_rx_ospd_clear_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_prediv_sel : 2;
        unsigned int rxdp_demux_word_width_sel : 1;
        unsigned int rxcp_spineclk_sel : 1;
        unsigned int rx_rate_mode : 2;
        unsigned int rxpi_predrv : 5;
        unsigned int rxpi_predrv_cap_sel : 2;
        unsigned int rxpi_inl_adjust_en : 5;
        unsigned int rxpi_buf_res_ctrl : 2;
        unsigned int rxpi_core_sr_ctrl : 4;
        unsigned int rx_cdr_wclk_en : 1;
        unsigned int rx_ospd_wclk_en : 1;
        unsigned int rx_cdr_coarse_window : 3;
        unsigned int reserved : 3;
    } reg;
} SOC_MUDP_PHY_RX_CSR37_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR37_rxcp_prediv_sel_START (0)
#define SOC_MUDP_PHY_RX_CSR37_rxcp_prediv_sel_END (1)
#define SOC_MUDP_PHY_RX_CSR37_rxdp_demux_word_width_sel_START (2)
#define SOC_MUDP_PHY_RX_CSR37_rxdp_demux_word_width_sel_END (2)
#define SOC_MUDP_PHY_RX_CSR37_rxcp_spineclk_sel_START (3)
#define SOC_MUDP_PHY_RX_CSR37_rxcp_spineclk_sel_END (3)
#define SOC_MUDP_PHY_RX_CSR37_rx_rate_mode_START (4)
#define SOC_MUDP_PHY_RX_CSR37_rx_rate_mode_END (5)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_predrv_START (6)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_predrv_END (10)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_predrv_cap_sel_START (11)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_predrv_cap_sel_END (12)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_inl_adjust_en_START (13)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_inl_adjust_en_END (17)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_buf_res_ctrl_START (18)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_buf_res_ctrl_END (19)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_core_sr_ctrl_START (20)
#define SOC_MUDP_PHY_RX_CSR37_rxpi_core_sr_ctrl_END (23)
#define SOC_MUDP_PHY_RX_CSR37_rx_cdr_wclk_en_START (24)
#define SOC_MUDP_PHY_RX_CSR37_rx_cdr_wclk_en_END (24)
#define SOC_MUDP_PHY_RX_CSR37_rx_ospd_wclk_en_START (25)
#define SOC_MUDP_PHY_RX_CSR37_rx_ospd_wclk_en_END (25)
#define SOC_MUDP_PHY_RX_CSR37_rx_cdr_coarse_window_START (26)
#define SOC_MUDP_PHY_RX_CSR37_rx_cdr_coarse_window_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_cdr_freq_gain_coarse : 4;
        unsigned int rx_cdr_freq_gain_fine : 4;
        unsigned int rx_cdr_phs_gain_coarse : 4;
        unsigned int rx_cdr_phs_gain_fine : 4;
        unsigned int rx_cdr_freq_intatt_coarse : 2;
        unsigned int rx_cdr_freq_intatt_fine : 2;
        unsigned int rx_cdr_ce_phs_ofst : 7;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_RX_CSR38_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_gain_coarse_START (0)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_gain_coarse_END (3)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_gain_fine_START (4)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_gain_fine_END (7)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_phs_gain_coarse_START (8)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_phs_gain_coarse_END (11)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_phs_gain_fine_START (12)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_phs_gain_fine_END (15)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_intatt_coarse_START (16)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_intatt_coarse_END (17)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_intatt_fine_START (18)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_freq_intatt_fine_END (19)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_ce_phs_ofst_START (20)
#define SOC_MUDP_PHY_RX_CSR38_rx_cdr_ce_phs_ofst_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_cdr_edge_iq_phs_ofst : 7;
        unsigned int rx_cdr_fintg_rst_value : 3;
        unsigned int rx_cdr_edge_mode : 1;
        unsigned int rx_cdr_secloop_en : 1;
        unsigned int rx_cdr_gain_step_time : 2;
        unsigned int rx_cdr_bind_push_window : 3;
        unsigned int rx_cdr_bind_push_en : 1;
        unsigned int rx_cdr_hard_acc_rst_value : 2;
        unsigned int rx_cdr_hard_acc_window : 3;
        unsigned int rx_cdr_hard_acc_en : 1;
        unsigned int rx_cdr_freeze_en : 1;
        unsigned int rx_cdr_phs_adjust_en : 1;
        unsigned int rx_cdr_bitslip : 1;
        unsigned int rx_cdr_jitter_inj_en : 1;
        unsigned int rx_cdr_ppm_inj_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_MUDP_PHY_RX_CSR39_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_edge_iq_phs_ofst_START (0)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_edge_iq_phs_ofst_END (6)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_fintg_rst_value_START (7)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_fintg_rst_value_END (9)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_edge_mode_START (10)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_edge_mode_END (10)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_secloop_en_START (11)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_secloop_en_END (11)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_gain_step_time_START (12)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_gain_step_time_END (13)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_bind_push_window_START (14)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_bind_push_window_END (16)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_bind_push_en_START (17)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_bind_push_en_END (17)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_hard_acc_rst_value_START (18)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_hard_acc_rst_value_END (19)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_hard_acc_window_START (20)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_hard_acc_window_END (22)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_hard_acc_en_START (23)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_hard_acc_en_END (23)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_freeze_en_START (24)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_freeze_en_END (24)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_phs_adjust_en_START (25)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_phs_adjust_en_END (25)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_bitslip_START (26)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_bitslip_END (26)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_jitter_inj_en_START (27)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_jitter_inj_en_END (27)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_ppm_inj_en_START (28)
#define SOC_MUDP_PHY_RX_CSR39_rx_cdr_ppm_inj_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_cdr_phs_adjust : 8;
        unsigned int rx_cdr_jitter_amp : 5;
        unsigned int rx_cdr_jitter_freq : 10;
        unsigned int rx_cdr_ppm_amp : 6;
        unsigned int reserved : 3;
    } reg;
} SOC_MUDP_PHY_RX_CSR40_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_phs_adjust_START (0)
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_phs_adjust_END (7)
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_jitter_amp_START (8)
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_jitter_amp_END (12)
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_jitter_freq_START (13)
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_jitter_freq_END (22)
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_ppm_amp_START (23)
#define SOC_MUDP_PHY_RX_CSR40_rx_cdr_ppm_amp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_cdr_cphs_ofst_done : 1;
        unsigned int rx_cdr_ephs_ofst_done : 1;
        unsigned int rx_cdr_phs_adjust_done : 1;
        unsigned int rx_cdr_bitslip_done : 1;
        unsigned int rx_cdr_fintg_value : 14;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PHY_RX_CSR41_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_cphs_ofst_done_START (0)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_cphs_ofst_done_END (0)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_ephs_ofst_done_START (1)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_ephs_ofst_done_END (1)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_phs_adjust_done_START (2)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_phs_adjust_done_END (2)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_bitslip_done_START (3)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_bitslip_done_END (3)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_fintg_value_START (4)
#define SOC_MUDP_PHY_RX_CSR41_rx_cdr_fintg_value_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_cdr_edge_q_phs_code : 7;
        unsigned int rx_cdr_edge_i_phs_code : 7;
        unsigned int rx_cdr_center_phs_code : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_MUDP_PHY_RX_CSR42_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR42_rx_cdr_edge_q_phs_code_START (0)
#define SOC_MUDP_PHY_RX_CSR42_rx_cdr_edge_q_phs_code_END (6)
#define SOC_MUDP_PHY_RX_CSR42_rx_cdr_edge_i_phs_code_START (7)
#define SOC_MUDP_PHY_RX_CSR42_rx_cdr_edge_i_phs_code_END (13)
#define SOC_MUDP_PHY_RX_CSR42_rx_cdr_center_phs_code_START (14)
#define SOC_MUDP_PHY_RX_CSR42_rx_cdr_center_phs_code_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR43_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR44_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_prbs_chk_err : 1;
        unsigned int rx_prbs_err_cnt_base : 11;
        unsigned int rx_prbs_err_cnt_exp : 4;
        unsigned int rx_prbs_patt_sel : 5;
        unsigned int rx_prbs_chk_mode : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR45_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_chk_err_START (0)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_chk_err_END (0)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_err_cnt_base_START (1)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_err_cnt_base_END (11)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_err_cnt_exp_START (12)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_err_cnt_exp_END (15)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_patt_sel_START (16)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_patt_sel_END (20)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_chk_mode_START (21)
#define SOC_MUDP_PHY_RX_CSR45_rx_prbs_chk_mode_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_term_ctrl_50ohm_pin_en : 1;
        unsigned int rx_term_ctrl_status : 1;
        unsigned int real_rxterm_cal_is_zero : 1;
        unsigned int reserved_0 : 2;
        unsigned int rxterm_floating_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 23;
    } reg;
} SOC_MUDP_PHY_RX_CSR46_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR46_rx_term_ctrl_50ohm_pin_en_START (0)
#define SOC_MUDP_PHY_RX_CSR46_rx_term_ctrl_50ohm_pin_en_END (0)
#define SOC_MUDP_PHY_RX_CSR46_rx_term_ctrl_status_START (1)
#define SOC_MUDP_PHY_RX_CSR46_rx_term_ctrl_status_END (1)
#define SOC_MUDP_PHY_RX_CSR46_real_rxterm_cal_is_zero_START (2)
#define SOC_MUDP_PHY_RX_CSR46_real_rxterm_cal_is_zero_END (2)
#define SOC_MUDP_PHY_RX_CSR46_rxterm_floating_en_START (5)
#define SOC_MUDP_PHY_RX_CSR46_rxterm_floating_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_prbs_csr_read_clear : 1;
        unsigned int rx_cdr_csr_read_en : 1;
        unsigned int rx_ospd_csr_read_en : 1;
        unsigned int rx_eyemon_csr_read_en : 1;
        unsigned int rx_csr_wr_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MUDP_PHY_RX_CSR47_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR47_rx_prbs_csr_read_clear_START (0)
#define SOC_MUDP_PHY_RX_CSR47_rx_prbs_csr_read_clear_END (0)
#define SOC_MUDP_PHY_RX_CSR47_rx_cdr_csr_read_en_START (1)
#define SOC_MUDP_PHY_RX_CSR47_rx_cdr_csr_read_en_END (1)
#define SOC_MUDP_PHY_RX_CSR47_rx_ospd_csr_read_en_START (2)
#define SOC_MUDP_PHY_RX_CSR47_rx_ospd_csr_read_en_END (2)
#define SOC_MUDP_PHY_RX_CSR47_rx_eyemon_csr_read_en_START (3)
#define SOC_MUDP_PHY_RX_CSR47_rx_eyemon_csr_read_en_END (3)
#define SOC_MUDP_PHY_RX_CSR47_rx_csr_wr_en_START (4)
#define SOC_MUDP_PHY_RX_CSR47_rx_csr_wr_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR48_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR49_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fsm_cmd_error_int_source : 1;
        unsigned int rx_fsm_apb_slverr_int_source : 1;
        unsigned int rx_fsm_wait_out_flag_int_source : 1;
        unsigned int rx_sdpi_error_int_source : 1;
        unsigned int rx_fsm_sram_error_int_source : 1;
        unsigned int rx_soft_int_source : 1;
        unsigned int rx_sdpi_pwr_event_int_source : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MUDP_PHY_RX_CSR50_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_cmd_error_int_source_START (0)
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_cmd_error_int_source_END (0)
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_apb_slverr_int_source_START (1)
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_apb_slverr_int_source_END (1)
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_wait_out_flag_int_source_START (2)
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_wait_out_flag_int_source_END (2)
#define SOC_MUDP_PHY_RX_CSR50_rx_sdpi_error_int_source_START (3)
#define SOC_MUDP_PHY_RX_CSR50_rx_sdpi_error_int_source_END (3)
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_sram_error_int_source_START (4)
#define SOC_MUDP_PHY_RX_CSR50_rx_fsm_sram_error_int_source_END (4)
#define SOC_MUDP_PHY_RX_CSR50_rx_soft_int_source_START (5)
#define SOC_MUDP_PHY_RX_CSR50_rx_soft_int_source_END (5)
#define SOC_MUDP_PHY_RX_CSR50_rx_sdpi_pwr_event_int_source_START (6)
#define SOC_MUDP_PHY_RX_CSR50_rx_sdpi_pwr_event_int_source_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_eyescan_done_int_mask : 1;
        unsigned int rx_ospd_lock_los_int_mask : 1;
        unsigned int rx_fsm_cmd_error_int_mask : 1;
        unsigned int rx_fsm_apb_slverr_int_mask : 1;
        unsigned int rx_fsm_wait_out_flag_int_mask : 1;
        unsigned int rx_sdpi_error_int_mask : 1;
        unsigned int rx_fsm_sram_error_int_mask : 1;
        unsigned int rx_soft_int_mask : 1;
        unsigned int rx_sdpi_pwr_event_int_mask : 1;
        unsigned int gcalib_code_warning_int_mask : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_MUDP_PHY_RX_CSR51_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR51_rx_eyescan_done_int_mask_START (0)
#define SOC_MUDP_PHY_RX_CSR51_rx_eyescan_done_int_mask_END (0)
#define SOC_MUDP_PHY_RX_CSR51_rx_ospd_lock_los_int_mask_START (1)
#define SOC_MUDP_PHY_RX_CSR51_rx_ospd_lock_los_int_mask_END (1)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_cmd_error_int_mask_START (2)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_cmd_error_int_mask_END (2)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_apb_slverr_int_mask_START (3)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_apb_slverr_int_mask_END (3)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_wait_out_flag_int_mask_START (4)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_wait_out_flag_int_mask_END (4)
#define SOC_MUDP_PHY_RX_CSR51_rx_sdpi_error_int_mask_START (5)
#define SOC_MUDP_PHY_RX_CSR51_rx_sdpi_error_int_mask_END (5)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_sram_error_int_mask_START (6)
#define SOC_MUDP_PHY_RX_CSR51_rx_fsm_sram_error_int_mask_END (6)
#define SOC_MUDP_PHY_RX_CSR51_rx_soft_int_mask_START (7)
#define SOC_MUDP_PHY_RX_CSR51_rx_soft_int_mask_END (7)
#define SOC_MUDP_PHY_RX_CSR51_rx_sdpi_pwr_event_int_mask_START (8)
#define SOC_MUDP_PHY_RX_CSR51_rx_sdpi_pwr_event_int_mask_END (8)
#define SOC_MUDP_PHY_RX_CSR51_gcalib_code_warning_int_mask_START (9)
#define SOC_MUDP_PHY_RX_CSR51_gcalib_code_warning_int_mask_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_eyescan_done_int : 1;
        unsigned int rx_ospd_lock_los_int : 1;
        unsigned int rx_fsm_cmd_error_int : 1;
        unsigned int rx_fsm_apb_slverr_int : 1;
        unsigned int rx_fsm_wait_out_flag_int : 1;
        unsigned int rx_sdpi_error_int : 1;
        unsigned int rx_fsm_sram_error_int : 1;
        unsigned int rx_soft_int : 1;
        unsigned int rx_sdpi_pwr_event_int : 1;
        unsigned int gcalib_code_warning_int : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_MUDP_PHY_RX_CSR52_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR52_rx_eyescan_done_int_START (0)
#define SOC_MUDP_PHY_RX_CSR52_rx_eyescan_done_int_END (0)
#define SOC_MUDP_PHY_RX_CSR52_rx_ospd_lock_los_int_START (1)
#define SOC_MUDP_PHY_RX_CSR52_rx_ospd_lock_los_int_END (1)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_cmd_error_int_START (2)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_cmd_error_int_END (2)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_apb_slverr_int_START (3)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_apb_slverr_int_END (3)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_wait_out_flag_int_START (4)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_wait_out_flag_int_END (4)
#define SOC_MUDP_PHY_RX_CSR52_rx_sdpi_error_int_START (5)
#define SOC_MUDP_PHY_RX_CSR52_rx_sdpi_error_int_END (5)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_sram_error_int_START (6)
#define SOC_MUDP_PHY_RX_CSR52_rx_fsm_sram_error_int_END (6)
#define SOC_MUDP_PHY_RX_CSR52_rx_soft_int_START (7)
#define SOC_MUDP_PHY_RX_CSR52_rx_soft_int_END (7)
#define SOC_MUDP_PHY_RX_CSR52_rx_sdpi_pwr_event_int_START (8)
#define SOC_MUDP_PHY_RX_CSR52_rx_sdpi_pwr_event_int_END (8)
#define SOC_MUDP_PHY_RX_CSR52_gcalib_code_warning_int_START (9)
#define SOC_MUDP_PHY_RX_CSR52_gcalib_code_warning_int_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_eyemon_start : 1;
        unsigned int rx_eyemon_mode : 1;
        unsigned int rx_eyemon_chan_sel : 1;
        unsigned int rx_eyemon_offset : 7;
        unsigned int rx_eyemon_window : 4;
        unsigned int rx_eyemon_fsm_clr_en : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_MUDP_PHY_RX_CSR53_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_start_START (0)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_start_END (0)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_mode_START (1)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_mode_END (1)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_chan_sel_START (2)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_chan_sel_END (2)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_offset_START (3)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_offset_END (9)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_window_START (10)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_window_END (13)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_fsm_clr_en_START (14)
#define SOC_MUDP_PHY_RX_CSR53_rx_eyemon_fsm_clr_en_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_eyecorner1 : 7;
        unsigned int reserved_0 : 1;
        unsigned int rx_eyecorner0 : 7;
        unsigned int rx_eyescan_done : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MUDP_PHY_RX_CSR54_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR54_rx_eyecorner1_START (0)
#define SOC_MUDP_PHY_RX_CSR54_rx_eyecorner1_END (6)
#define SOC_MUDP_PHY_RX_CSR54_rx_eyecorner0_START (8)
#define SOC_MUDP_PHY_RX_CSR54_rx_eyecorner0_END (14)
#define SOC_MUDP_PHY_RX_CSR54_rx_eyescan_done_START (15)
#define SOC_MUDP_PHY_RX_CSR54_rx_eyescan_done_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_edge_isi_en : 1;
        unsigned int rx_edge_isi_clr : 1;
        unsigned int rx_edge_isi_pat_det_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int rx_edge_isi_det_width : 3;
        unsigned int reserved_1 : 1;
        unsigned int rx_edge_isi_boost : 5;
        unsigned int rx_edge_isi_boost_sdm : 4;
        unsigned int rx_edge_isi_boost_max : 5;
        unsigned int rx_edge_isi_boost_min : 5;
        unsigned int rx_edge_isi_boost_sat : 5;
    } reg;
} SOC_MUDP_PHY_RX_CSR55_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_en_START (0)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_en_END (0)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_clr_START (1)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_clr_END (1)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_pat_det_bypass_START (2)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_pat_det_bypass_END (2)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_det_width_START (4)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_det_width_END (6)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_START (8)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_END (12)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_sdm_START (13)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_sdm_END (16)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_max_START (17)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_max_END (21)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_min_START (22)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_min_END (26)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_sat_START (27)
#define SOC_MUDP_PHY_RX_CSR55_rx_edge_isi_boost_sat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_edge_isi_offset_update_flag : 1;
        unsigned int rx_edge_isi_boost_update_flag : 1;
        unsigned int rx_edge_isi_offset_sat_flag : 1;
        unsigned int rx_edge_isi_boost_sat_flag : 1;
        unsigned int rx_edge_isi_offset : 4;
        unsigned int reserved_0 : 1;
        unsigned int rx_edge_isi_offset_sdm : 4;
        unsigned int rx_edge_isi_offset_max : 9;
        unsigned int rx_edge_isi_offset_min : 9;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_MUDP_PHY_RX_CSR56_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_update_flag_START (0)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_update_flag_END (0)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_boost_update_flag_START (1)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_boost_update_flag_END (1)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_sat_flag_START (2)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_sat_flag_END (2)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_boost_sat_flag_START (3)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_boost_sat_flag_END (3)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_START (4)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_END (7)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_sdm_START (9)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_sdm_END (12)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_max_START (13)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_max_END (21)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_min_START (22)
#define SOC_MUDP_PHY_RX_CSR56_rx_edge_isi_offset_min_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_edge_isi_offset_sat : 9;
        unsigned int rxctle_eq_lfboost_update_bypass : 1;
        unsigned int rxdfe_edg_latch_ofst_update_bypass : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_MUDP_PHY_RX_CSR57_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR57_rx_edge_isi_offset_sat_START (0)
#define SOC_MUDP_PHY_RX_CSR57_rx_edge_isi_offset_sat_END (8)
#define SOC_MUDP_PHY_RX_CSR57_rxctle_eq_lfboost_update_bypass_START (9)
#define SOC_MUDP_PHY_RX_CSR57_rxctle_eq_lfboost_update_bypass_END (9)
#define SOC_MUDP_PHY_RX_CSR57_rxdfe_edg_latch_ofst_update_bypass_START (10)
#define SOC_MUDP_PHY_RX_CSR57_rxdfe_edg_latch_ofst_update_bypass_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_edge_isi_offset_conv_rpt : 1;
        unsigned int rx_edge_isi_boost_conv_rpt : 1;
        unsigned int rx_edge_isi_conv_timeout_rpt : 1;
        unsigned int rx_edge_isi_conv_equal0_time : 10;
        unsigned int rx_edge_isi_conv_time_win : 8;
        unsigned int rx_edge_isi_offset_conv_th : 4;
        unsigned int rx_edge_isi_boost_conv_th : 4;
        unsigned int reserved : 3;
    } reg;
} SOC_MUDP_PHY_RX_CSR58_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_offset_conv_rpt_START (0)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_offset_conv_rpt_END (0)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_boost_conv_rpt_START (1)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_boost_conv_rpt_END (1)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_conv_timeout_rpt_START (2)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_conv_timeout_rpt_END (2)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_conv_equal0_time_START (3)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_conv_equal0_time_END (12)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_conv_time_win_START (13)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_conv_time_win_END (20)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_offset_conv_th_START (21)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_offset_conv_th_END (24)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_boost_conv_th_START (25)
#define SOC_MUDP_PHY_RX_CSR58_rx_edge_isi_boost_conv_th_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int rxctle_eq1_lfboost_gray : 4;
        unsigned int rxdfe_edg_i_lat_ofst : 9;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_MUDP_PHY_RX_CSR59_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR59_rxctle_eq1_lfboost_gray_START (8)
#define SOC_MUDP_PHY_RX_CSR59_rxctle_eq1_lfboost_gray_END (11)
#define SOC_MUDP_PHY_RX_CSR59_rxdfe_edg_i_lat_ofst_START (12)
#define SOC_MUDP_PHY_RX_CSR59_rxdfe_edg_i_lat_ofst_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdfe_edg_qb_lat_ofst : 9;
        unsigned int rxdfe_edg_q_lat_ofst : 9;
        unsigned int rxdfe_edg_ib_lat_ofst : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_RX_CSR60_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR60_rxdfe_edg_qb_lat_ofst_START (0)
#define SOC_MUDP_PHY_RX_CSR60_rxdfe_edg_qb_lat_ofst_END (8)
#define SOC_MUDP_PHY_RX_CSR60_rxdfe_edg_q_lat_ofst_START (9)
#define SOC_MUDP_PHY_RX_CSR60_rxdfe_edg_q_lat_ofst_END (17)
#define SOC_MUDP_PHY_RX_CSR60_rxdfe_edg_ib_lat_ofst_START (18)
#define SOC_MUDP_PHY_RX_CSR60_rxdfe_edg_ib_lat_ofst_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxjtag_initclk_status : 1;
        unsigned int rxjtag_initclk : 1;
        unsigned int rxjtag_initm_status : 1;
        unsigned int rxjtag_initm : 1;
        unsigned int rxjtag_initp_status : 1;
        unsigned int rxjtag_initp : 1;
        unsigned int rxjtag_acmode_en_status : 1;
        unsigned int rxjtag_acmode_en : 1;
        unsigned int rxjtag_th_adj_status : 2;
        unsigned int rxjtag_th_adj : 2;
        unsigned int rxjtag_hyst_adj_status : 2;
        unsigned int rxjtag_hyst_adj : 2;
        unsigned int rx_bse : 1;
        unsigned int rx_pcs_rcv_eob_status : 1;
        unsigned int rx_pcs_rcv_eob : 1;
        unsigned int rx_pcs_rcv_eob_pin_en : 1;
        unsigned int rx_ad_difp_det_rst_status : 1;
        unsigned int rx_ad_difp_det_rst : 1;
        unsigned int rx_ad_difp_det_rst_pin_en : 1;
        unsigned int rx_sqdet_pwrdnb_status : 1;
        unsigned int rx_sqdet_pwrdnb : 1;
        unsigned int rx_sqdet_pwrdnb_pin_en : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_PHY_RX_CSR61_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initclk_status_START (0)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initclk_status_END (0)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initclk_START (1)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initclk_END (1)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initm_status_START (2)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initm_status_END (2)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initm_START (3)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initm_END (3)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initp_status_START (4)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initp_status_END (4)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initp_START (5)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_initp_END (5)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_acmode_en_status_START (6)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_acmode_en_status_END (6)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_acmode_en_START (7)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_acmode_en_END (7)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_th_adj_status_START (8)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_th_adj_status_END (9)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_th_adj_START (10)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_th_adj_END (11)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_hyst_adj_status_START (12)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_hyst_adj_status_END (13)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_hyst_adj_START (14)
#define SOC_MUDP_PHY_RX_CSR61_rxjtag_hyst_adj_END (15)
#define SOC_MUDP_PHY_RX_CSR61_rx_bse_START (16)
#define SOC_MUDP_PHY_RX_CSR61_rx_bse_END (16)
#define SOC_MUDP_PHY_RX_CSR61_rx_pcs_rcv_eob_status_START (17)
#define SOC_MUDP_PHY_RX_CSR61_rx_pcs_rcv_eob_status_END (17)
#define SOC_MUDP_PHY_RX_CSR61_rx_pcs_rcv_eob_START (18)
#define SOC_MUDP_PHY_RX_CSR61_rx_pcs_rcv_eob_END (18)
#define SOC_MUDP_PHY_RX_CSR61_rx_pcs_rcv_eob_pin_en_START (19)
#define SOC_MUDP_PHY_RX_CSR61_rx_pcs_rcv_eob_pin_en_END (19)
#define SOC_MUDP_PHY_RX_CSR61_rx_ad_difp_det_rst_status_START (20)
#define SOC_MUDP_PHY_RX_CSR61_rx_ad_difp_det_rst_status_END (20)
#define SOC_MUDP_PHY_RX_CSR61_rx_ad_difp_det_rst_START (21)
#define SOC_MUDP_PHY_RX_CSR61_rx_ad_difp_det_rst_END (21)
#define SOC_MUDP_PHY_RX_CSR61_rx_ad_difp_det_rst_pin_en_START (22)
#define SOC_MUDP_PHY_RX_CSR61_rx_ad_difp_det_rst_pin_en_END (22)
#define SOC_MUDP_PHY_RX_CSR61_rx_sqdet_pwrdnb_status_START (23)
#define SOC_MUDP_PHY_RX_CSR61_rx_sqdet_pwrdnb_status_END (23)
#define SOC_MUDP_PHY_RX_CSR61_rx_sqdet_pwrdnb_START (24)
#define SOC_MUDP_PHY_RX_CSR61_rx_sqdet_pwrdnb_END (24)
#define SOC_MUDP_PHY_RX_CSR61_rx_sqdet_pwrdnb_pin_en_START (25)
#define SOC_MUDP_PHY_RX_CSR61_rx_sqdet_pwrdnb_pin_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR62_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_target_seq_num : 7;
        unsigned int reserved_0 : 5;
        unsigned int rx_seq_time_b : 4;
        unsigned int rx_seq_time_a : 4;
        unsigned int rx_target_seq_run_done : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_MUDP_PHY_RX_CSR63_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR63_rx_target_seq_num_START (0)
#define SOC_MUDP_PHY_RX_CSR63_rx_target_seq_num_END (6)
#define SOC_MUDP_PHY_RX_CSR63_rx_seq_time_b_START (12)
#define SOC_MUDP_PHY_RX_CSR63_rx_seq_time_b_END (15)
#define SOC_MUDP_PHY_RX_CSR63_rx_seq_time_a_START (16)
#define SOC_MUDP_PHY_RX_CSR63_rx_seq_time_a_END (19)
#define SOC_MUDP_PHY_RX_CSR63_rx_target_seq_run_done_START (20)
#define SOC_MUDP_PHY_RX_CSR63_rx_target_seq_run_done_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxctle_buffer_q_pwrdnb_up : 1;
        unsigned int rxctle_buffer_q_pwrdnb_dn : 1;
        unsigned int rxctle_buffer_i_pwrdnb_up : 1;
        unsigned int rxctle_buffer_i_pwrdnb_dn : 1;
        unsigned int rxctle_eq_pwrdnb_up : 1;
        unsigned int rxctle_eq_pwrdnb_dn : 1;
        unsigned int rxctle_pwrdnb_up : 1;
        unsigned int rxctle_pwrdnb_dn : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_PHY_RX_CSR64_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_q_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_q_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_q_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_q_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_i_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_i_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_i_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_buffer_i_pwrdnb_dn_END (3)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_eq_pwrdnb_up_START (4)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_eq_pwrdnb_up_END (4)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_eq_pwrdnb_dn_START (5)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_eq_pwrdnb_dn_END (5)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_pwrdnb_up_START (6)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_pwrdnb_up_END (6)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_pwrdnb_dn_START (7)
#define SOC_MUDP_PHY_RX_CSR64_rxctle_pwrdnb_dn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxpi_qdiv_pwrdnb_up : 1;
        unsigned int rxpi_qdiv_pwrdnb_dn : 1;
        unsigned int rxcp_prediv_pwrdnb_up : 1;
        unsigned int rxcp_prediv_pwrdnb_dn : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MUDP_PHY_RX_CSR65_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR65_rxpi_qdiv_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_RX_CSR65_rxpi_qdiv_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_RX_CSR65_rxpi_qdiv_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_RX_CSR65_rxpi_qdiv_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_RX_CSR65_rxcp_prediv_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_RX_CSR65_rxcp_prediv_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_RX_CSR65_rxcp_prediv_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_RX_CSR65_rxcp_prediv_pwrdnb_dn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_div8_pwrdnb_up : 1;
        unsigned int rxcp_div8_pwrdnb_dn : 1;
        unsigned int rxdp_center_demuxi_pwrdnb_up : 1;
        unsigned int rxdp_center_demuxi_pwrdnb_dn : 1;
        unsigned int rxdp_center_slicerib_pwrdnb_up : 1;
        unsigned int rxdp_center_slicerib_pwrdnb_dn : 1;
        unsigned int rxdp_center_sliceri_pwrdnb_up : 1;
        unsigned int rxdp_center_sliceri_pwrdnb_dn : 1;
        unsigned int rxpi_center_cml2cmos_i_pwrdnb_up : 1;
        unsigned int rxpi_center_cml2cmos_i_pwrdnb_dn : 1;
        unsigned int rxpi_center_picore_i_pwrdnb_up : 1;
        unsigned int rxpi_center_picore_i_pwrdnb_dn : 1;
        unsigned int rxpi_center_predrv_i_pwrdnb_up : 1;
        unsigned int rxpi_center_predrv_i_pwrdnb_dn : 1;
        unsigned int rxpi_center_pi_i_pwrdnb_up : 1;
        unsigned int rxpi_center_pi_i_pwrdnb_dn : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PHY_RX_CSR66_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR66_rxcp_div8_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_RX_CSR66_rxcp_div8_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_RX_CSR66_rxcp_div8_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_RX_CSR66_rxcp_div8_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_demuxi_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_demuxi_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_demuxi_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_demuxi_pwrdnb_dn_END (3)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_slicerib_pwrdnb_up_START (4)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_slicerib_pwrdnb_up_END (4)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_slicerib_pwrdnb_dn_START (5)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_slicerib_pwrdnb_dn_END (5)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_sliceri_pwrdnb_up_START (6)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_sliceri_pwrdnb_up_END (6)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_sliceri_pwrdnb_dn_START (7)
#define SOC_MUDP_PHY_RX_CSR66_rxdp_center_sliceri_pwrdnb_dn_END (7)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_cml2cmos_i_pwrdnb_up_START (8)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_cml2cmos_i_pwrdnb_up_END (8)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_cml2cmos_i_pwrdnb_dn_START (9)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_cml2cmos_i_pwrdnb_dn_END (9)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_picore_i_pwrdnb_up_START (10)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_picore_i_pwrdnb_up_END (10)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_picore_i_pwrdnb_dn_START (11)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_picore_i_pwrdnb_dn_END (11)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_predrv_i_pwrdnb_up_START (12)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_predrv_i_pwrdnb_up_END (12)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_predrv_i_pwrdnb_dn_START (13)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_predrv_i_pwrdnb_dn_END (13)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_pi_i_pwrdnb_up_START (14)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_pi_i_pwrdnb_up_END (14)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_pi_i_pwrdnb_dn_START (15)
#define SOC_MUDP_PHY_RX_CSR66_rxpi_center_pi_i_pwrdnb_dn_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_demuxq_pwrdnb_up : 1;
        unsigned int rxdp_center_demuxq_pwrdnb_dn : 1;
        unsigned int rxdp_center_slicerqb_pwrdnb_up : 1;
        unsigned int rxdp_center_slicerqb_pwrdnb_dn : 1;
        unsigned int rxdp_center_slicerq_pwrdnb_up : 1;
        unsigned int rxdp_center_slicerq_pwrdnb_dn : 1;
        unsigned int rxpi_center_cml2cmos_q_pwrdnb_up : 1;
        unsigned int rxpi_center_cml2cmos_q_pwrdnb_dn : 1;
        unsigned int rxpi_center_picore_q_pwrdnb_up : 1;
        unsigned int rxpi_center_picore_q_pwrdnb_dn : 1;
        unsigned int rxpi_center_predrv_q_pwrdnb_up : 1;
        unsigned int rxpi_center_predrv_q_pwrdnb_dn : 1;
        unsigned int rxpi_center_pi_q_pwrdnb_up : 1;
        unsigned int rxpi_center_pi_q_pwrdnb_dn : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_PHY_RX_CSR67_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_demuxq_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_demuxq_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_demuxq_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_demuxq_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerqb_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerqb_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerqb_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerqb_pwrdnb_dn_END (3)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerq_pwrdnb_up_START (4)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerq_pwrdnb_up_END (4)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerq_pwrdnb_dn_START (5)
#define SOC_MUDP_PHY_RX_CSR67_rxdp_center_slicerq_pwrdnb_dn_END (5)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_cml2cmos_q_pwrdnb_up_START (6)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_cml2cmos_q_pwrdnb_up_END (6)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_cml2cmos_q_pwrdnb_dn_START (7)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_cml2cmos_q_pwrdnb_dn_END (7)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_picore_q_pwrdnb_up_START (8)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_picore_q_pwrdnb_up_END (8)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_picore_q_pwrdnb_dn_START (9)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_picore_q_pwrdnb_dn_END (9)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_predrv_q_pwrdnb_up_START (10)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_predrv_q_pwrdnb_up_END (10)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_predrv_q_pwrdnb_dn_START (11)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_predrv_q_pwrdnb_dn_END (11)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_pi_q_pwrdnb_up_START (12)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_pi_q_pwrdnb_up_END (12)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_pi_q_pwrdnb_dn_START (13)
#define SOC_MUDP_PHY_RX_CSR67_rxpi_center_pi_q_pwrdnb_dn_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_edge_demuxi_pwrdnb_up : 1;
        unsigned int rxdp_edge_demuxi_pwrdnb_dn : 1;
        unsigned int rxdp_edge_slicerib_pwrdnb_up : 1;
        unsigned int rxdp_edge_slicerib_pwrdnb_dn : 1;
        unsigned int rxdp_edge_sliceri_pwrdnb_up : 1;
        unsigned int rxdp_edge_sliceri_pwrdnb_dn : 1;
        unsigned int rxpi_edge_cml2cmos_i_pwrdnb_up : 1;
        unsigned int rxpi_edge_cml2cmos_i_pwrdnb_dn : 1;
        unsigned int rxpi_edge_picore_i_pwrdnb_up : 1;
        unsigned int rxpi_edge_picore_i_pwrdnb_dn : 1;
        unsigned int rxpi_edge_picore_i_half_pwrdnb_up : 1;
        unsigned int rxpi_edge_picore_i_half_pwrdnb_dn : 1;
        unsigned int rxpi_edge_predrv_i_pwrdnb_up : 1;
        unsigned int rxpi_edge_predrv_i_pwrdnb_dn : 1;
        unsigned int rxpi_edge_predrv_i_twothird_pwrdnb_up : 1;
        unsigned int rxpi_edge_predrv_i_twothird_pwrdnb_dn : 1;
        unsigned int rxpi_edge_predrv_i_onethird_pwrdnb_up : 1;
        unsigned int rxpi_edge_predrv_i_onethird_pwrdnb_dn : 1;
        unsigned int rxpi_edge_pi_i_pwrdnb_up : 1;
        unsigned int rxpi_edge_pi_i_pwrdnb_dn : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_RX_CSR68_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_demuxi_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_demuxi_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_demuxi_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_demuxi_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_slicerib_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_slicerib_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_slicerib_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_slicerib_pwrdnb_dn_END (3)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_sliceri_pwrdnb_up_START (4)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_sliceri_pwrdnb_up_END (4)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_sliceri_pwrdnb_dn_START (5)
#define SOC_MUDP_PHY_RX_CSR68_rxdp_edge_sliceri_pwrdnb_dn_END (5)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_cml2cmos_i_pwrdnb_up_START (6)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_cml2cmos_i_pwrdnb_up_END (6)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_cml2cmos_i_pwrdnb_dn_START (7)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_cml2cmos_i_pwrdnb_dn_END (7)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_pwrdnb_up_START (8)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_pwrdnb_up_END (8)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_pwrdnb_dn_START (9)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_pwrdnb_dn_END (9)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_half_pwrdnb_up_START (10)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_half_pwrdnb_up_END (10)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_half_pwrdnb_dn_START (11)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_picore_i_half_pwrdnb_dn_END (11)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_pwrdnb_up_START (12)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_pwrdnb_up_END (12)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_pwrdnb_dn_START (13)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_pwrdnb_dn_END (13)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_twothird_pwrdnb_up_START (14)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_twothird_pwrdnb_up_END (14)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_twothird_pwrdnb_dn_START (15)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_twothird_pwrdnb_dn_END (15)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_onethird_pwrdnb_up_START (16)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_onethird_pwrdnb_up_END (16)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_onethird_pwrdnb_dn_START (17)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_predrv_i_onethird_pwrdnb_dn_END (17)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_pi_i_pwrdnb_up_START (18)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_pi_i_pwrdnb_up_END (18)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_pi_i_pwrdnb_dn_START (19)
#define SOC_MUDP_PHY_RX_CSR68_rxpi_edge_pi_i_pwrdnb_dn_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_edge_demuxq_pwrdnb_up : 1;
        unsigned int rxdp_edge_demuxq_pwrdnb_dn : 1;
        unsigned int rxdp_edge_slicerqb_pwrdnb_up : 1;
        unsigned int rxdp_edge_slicerqb_pwrdnb_dn : 1;
        unsigned int rxdp_edge_slicerq_pwrdnb_up : 1;
        unsigned int rxdp_edge_slicerq_pwrdnb_dn : 1;
        unsigned int rxpi_edge_2ndbuf_q_pwrdnb_up : 1;
        unsigned int rxpi_edge_2ndbuf_q_pwrdnb_dn : 1;
        unsigned int rxpi_edge_cml2cmos_q_pwrdnb_up : 1;
        unsigned int rxpi_edge_cml2cmos_q_pwrdnb_dn : 1;
        unsigned int rxpi_edge_picore_q_pwrdnb_up : 1;
        unsigned int rxpi_edge_picore_q_pwrdnb_dn : 1;
        unsigned int rxpi_edge_predrv_q_pwrdnb_up : 1;
        unsigned int rxpi_edge_predrv_q_pwrdnb_dn : 1;
        unsigned int rxpi_edge_predrv_q_twothird_pwrdnb_up : 1;
        unsigned int rxpi_edge_predrv_q_twothird_pwrdnb_dn : 1;
        unsigned int rxpi_edge_predrv_q_onethird_pwrdnb_up : 1;
        unsigned int rxpi_edge_predrv_q_onethird_pwrdnb_dn : 1;
        unsigned int rxpi_edge_pi_q_pwrdnb_up : 1;
        unsigned int rxpi_edge_pi_q_pwrdnb_dn : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PHY_RX_CSR69_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_demuxq_pwrdnb_up_START (0)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_demuxq_pwrdnb_up_END (0)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_demuxq_pwrdnb_dn_START (1)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_demuxq_pwrdnb_dn_END (1)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerqb_pwrdnb_up_START (2)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerqb_pwrdnb_up_END (2)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerqb_pwrdnb_dn_START (3)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerqb_pwrdnb_dn_END (3)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerq_pwrdnb_up_START (4)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerq_pwrdnb_up_END (4)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerq_pwrdnb_dn_START (5)
#define SOC_MUDP_PHY_RX_CSR69_rxdp_edge_slicerq_pwrdnb_dn_END (5)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_2ndbuf_q_pwrdnb_up_START (6)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_2ndbuf_q_pwrdnb_up_END (6)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_2ndbuf_q_pwrdnb_dn_START (7)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_2ndbuf_q_pwrdnb_dn_END (7)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_cml2cmos_q_pwrdnb_up_START (8)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_cml2cmos_q_pwrdnb_up_END (8)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_cml2cmos_q_pwrdnb_dn_START (9)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_cml2cmos_q_pwrdnb_dn_END (9)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_picore_q_pwrdnb_up_START (10)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_picore_q_pwrdnb_up_END (10)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_picore_q_pwrdnb_dn_START (11)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_picore_q_pwrdnb_dn_END (11)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_pwrdnb_up_START (12)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_pwrdnb_up_END (12)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_pwrdnb_dn_START (13)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_pwrdnb_dn_END (13)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_twothird_pwrdnb_up_START (14)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_twothird_pwrdnb_up_END (14)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_twothird_pwrdnb_dn_START (15)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_twothird_pwrdnb_dn_END (15)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_onethird_pwrdnb_up_START (16)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_onethird_pwrdnb_up_END (16)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_onethird_pwrdnb_dn_START (17)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_predrv_q_onethird_pwrdnb_dn_END (17)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_pi_q_pwrdnb_up_START (18)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_pi_q_pwrdnb_up_END (18)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_pi_q_pwrdnb_dn_START (19)
#define SOC_MUDP_PHY_RX_CSR69_rxpi_edge_pi_q_pwrdnb_dn_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_dig_spare0 : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR70_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR70_rx_dig_spare0_START (0)
#define SOC_MUDP_PHY_RX_CSR70_rx_dig_spare0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_dig_spare1 : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR71_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR71_rx_dig_spare1_START (0)
#define SOC_MUDP_PHY_RX_CSR71_rx_dig_spare1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_MUDP_PHY_RX_CSR72_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxterm_vcmgen_vrefsel : 4;
        unsigned int rxterm_vcmgen_pwrdnb : 1;
        unsigned int rx_1k_hiz_sel_reg : 1;
        unsigned int rxterm_sel : 2;
        unsigned int rxterm_cal : 4;
        unsigned int rxpi_edge_2ndbuf_q_pwrdn_ctrl : 1;
        unsigned int rxpi_edge_picore_q_half_pwrdnb : 1;
        unsigned int rxpi_predrv_lowpwr_enb : 1;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 5;
    } reg;
} SOC_MUDP_PHY_RX_CSR73_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR73_rxterm_vcmgen_vrefsel_START (0)
#define SOC_MUDP_PHY_RX_CSR73_rxterm_vcmgen_vrefsel_END (3)
#define SOC_MUDP_PHY_RX_CSR73_rxterm_vcmgen_pwrdnb_START (4)
#define SOC_MUDP_PHY_RX_CSR73_rxterm_vcmgen_pwrdnb_END (4)
#define SOC_MUDP_PHY_RX_CSR73_rx_1k_hiz_sel_reg_START (5)
#define SOC_MUDP_PHY_RX_CSR73_rx_1k_hiz_sel_reg_END (5)
#define SOC_MUDP_PHY_RX_CSR73_rxterm_sel_START (6)
#define SOC_MUDP_PHY_RX_CSR73_rxterm_sel_END (7)
#define SOC_MUDP_PHY_RX_CSR73_rxterm_cal_START (8)
#define SOC_MUDP_PHY_RX_CSR73_rxterm_cal_END (11)
#define SOC_MUDP_PHY_RX_CSR73_rxpi_edge_2ndbuf_q_pwrdn_ctrl_START (12)
#define SOC_MUDP_PHY_RX_CSR73_rxpi_edge_2ndbuf_q_pwrdn_ctrl_END (12)
#define SOC_MUDP_PHY_RX_CSR73_rxpi_edge_picore_q_half_pwrdnb_START (13)
#define SOC_MUDP_PHY_RX_CSR73_rxpi_edge_picore_q_half_pwrdnb_END (13)
#define SOC_MUDP_PHY_RX_CSR73_rxpi_predrv_lowpwr_enb_START (14)
#define SOC_MUDP_PHY_RX_CSR73_rxpi_predrv_lowpwr_enb_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxctle_buffer_res_sel : 3;
        unsigned int rxctle_buffer_q_offset_gray : 6;
        unsigned int rxctle_buffer_i_offset_gray : 6;
        unsigned int rxctle_buffer_cap_sel_gray : 3;
        unsigned int rxctle_buffer_negc_bias_sel : 1;
        unsigned int rxctle_buffer_negc_en : 1;
        unsigned int rxctle_lpbk_predrv_pullup_en : 1;
        unsigned int rxctle_buffer_q_mute_en : 1;
        unsigned int rxctle_buffer_i_mute_en : 1;
        unsigned int rxctle_ls_mode_en : 1;
        unsigned int rxctle_bypass_en : 1;
        unsigned int rxctle_lpbk_predrv_pwrdnb : 1;
        unsigned int rxctle_lpbk_pwrdnb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int rxctle_vcmref_pwrdnb : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_MUDP_PHY_RX_CSR74_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_res_sel_START (0)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_res_sel_END (2)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_q_offset_gray_START (3)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_q_offset_gray_END (8)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_i_offset_gray_START (9)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_i_offset_gray_END (14)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_cap_sel_gray_START (15)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_cap_sel_gray_END (17)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_negc_bias_sel_START (18)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_negc_bias_sel_END (18)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_negc_en_START (19)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_negc_en_END (19)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_lpbk_predrv_pullup_en_START (20)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_lpbk_predrv_pullup_en_END (20)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_q_mute_en_START (21)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_q_mute_en_END (21)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_i_mute_en_START (22)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_buffer_i_mute_en_END (22)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_ls_mode_en_START (23)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_ls_mode_en_END (23)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_bypass_en_START (24)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_bypass_en_END (24)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_lpbk_predrv_pwrdnb_START (25)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_lpbk_predrv_pwrdnb_END (25)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_lpbk_pwrdnb_START (26)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_lpbk_pwrdnb_END (26)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_vcmref_pwrdnb_START (30)
#define SOC_MUDP_PHY_RX_CSR74_rxctle_vcmref_pwrdnb_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int rxctle_eq_rmband_gray : 3;
        unsigned int rxctle_eq_offset_gray : 5;
        unsigned int rxctle_eq_lfboost_gray : 4;
        unsigned int rxctle_eq_ind_bypass_en : 1;
        unsigned int rxctle_eq_hfboost_gray : 4;
        unsigned int rxctle_eq_fwd_en : 1;
        unsigned int rxctle_eq_cmband_gray : 3;
        unsigned int rxctle_ctle_bias_sel : 2;
        unsigned int rxctle_vcm_vrefsel : 4;
        unsigned int rxctle_buffer_rtrim : 4;
    } reg;
} SOC_MUDP_PHY_RX_CSR75_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_rmband_gray_START (1)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_rmband_gray_END (3)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_offset_gray_START (4)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_offset_gray_END (8)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_lfboost_gray_START (9)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_lfboost_gray_END (12)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_ind_bypass_en_START (13)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_ind_bypass_en_END (13)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_hfboost_gray_START (14)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_hfboost_gray_END (17)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_fwd_en_START (18)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_fwd_en_END (18)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_cmband_gray_START (19)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_eq_cmband_gray_END (21)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_ctle_bias_sel_START (22)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_ctle_bias_sel_END (23)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_vcm_vrefsel_START (24)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_vcm_vrefsel_END (27)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_buffer_rtrim_START (28)
#define SOC_MUDP_PHY_RX_CSR75_rxctle_buffer_rtrim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchi_offsetp_d0 : 8;
        unsigned int rxdp_dfetap1_enb : 1;
        unsigned int rxdp_dfetap1_d1_sel : 1;
        unsigned int rxdp_edge_q_eyeplot_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 4;
        unsigned int rxctle_fwd_sel_gray : 3;
        unsigned int rxctle_eq_squelch_gray : 3;
        unsigned int rxctle_eq_rtrim : 4;
    } reg;
} SOC_MUDP_PHY_RX_CSR76_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR76_rxdp_center_latchi_offsetp_d0_START (0)
#define SOC_MUDP_PHY_RX_CSR76_rxdp_center_latchi_offsetp_d0_END (7)
#define SOC_MUDP_PHY_RX_CSR76_rxdp_dfetap1_enb_START (8)
#define SOC_MUDP_PHY_RX_CSR76_rxdp_dfetap1_enb_END (8)
#define SOC_MUDP_PHY_RX_CSR76_rxdp_dfetap1_d1_sel_START (9)
#define SOC_MUDP_PHY_RX_CSR76_rxdp_dfetap1_d1_sel_END (9)
#define SOC_MUDP_PHY_RX_CSR76_rxdp_edge_q_eyeplot_sel_START (10)
#define SOC_MUDP_PHY_RX_CSR76_rxdp_edge_q_eyeplot_sel_END (10)
#define SOC_MUDP_PHY_RX_CSR76_rxctle_fwd_sel_gray_START (22)
#define SOC_MUDP_PHY_RX_CSR76_rxctle_fwd_sel_gray_END (24)
#define SOC_MUDP_PHY_RX_CSR76_rxctle_eq_squelch_gray_START (25)
#define SOC_MUDP_PHY_RX_CSR76_rxctle_eq_squelch_gray_END (27)
#define SOC_MUDP_PHY_RX_CSR76_rxctle_eq_rtrim_START (28)
#define SOC_MUDP_PHY_RX_CSR76_rxctle_eq_rtrim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchib_offsetp_d0 : 8;
        unsigned int rxdp_center_latchq_offsetm_d0 : 8;
        unsigned int rxdp_center_latchq_offsetp_d0 : 8;
        unsigned int rxdp_center_latchi_offsetm_d0 : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR77_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchib_offsetp_d0_START (0)
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchib_offsetp_d0_END (7)
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchq_offsetm_d0_START (8)
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchq_offsetm_d0_END (15)
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchq_offsetp_d0_START (16)
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchq_offsetp_d0_END (23)
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchi_offsetm_d0_START (24)
#define SOC_MUDP_PHY_RX_CSR77_rxdp_center_latchi_offsetm_d0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchi_offsetp_d1 : 8;
        unsigned int rxdp_center_latchqb_offsetm_d0 : 8;
        unsigned int rxdp_center_latchqb_offsetp_d0 : 8;
        unsigned int rxdp_center_latchib_offsetm_d0 : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR78_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchi_offsetp_d1_START (0)
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchi_offsetp_d1_END (7)
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchqb_offsetm_d0_START (8)
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchqb_offsetm_d0_END (15)
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchqb_offsetp_d0_START (16)
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchqb_offsetp_d0_END (23)
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchib_offsetm_d0_START (24)
#define SOC_MUDP_PHY_RX_CSR78_rxdp_center_latchib_offsetm_d0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchib_offsetp_d1 : 8;
        unsigned int rxdp_center_latchq_offsetm_d1 : 8;
        unsigned int rxdp_center_latchq_offsetp_d1 : 8;
        unsigned int rxdp_center_latchi_offsetm_d1 : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR79_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchib_offsetp_d1_START (0)
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchib_offsetp_d1_END (7)
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchq_offsetm_d1_START (8)
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchq_offsetm_d1_END (15)
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchq_offsetp_d1_START (16)
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchq_offsetp_d1_END (23)
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchi_offsetm_d1_START (24)
#define SOC_MUDP_PHY_RX_CSR79_rxdp_center_latchi_offsetm_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_edge_latchi_offsetp : 8;
        unsigned int rxdp_center_latchqb_offsetm_d1 : 8;
        unsigned int rxdp_center_latchqb_offsetp_d1 : 8;
        unsigned int rxdp_center_latchib_offsetm_d1 : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR80_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR80_rxdp_edge_latchi_offsetp_START (0)
#define SOC_MUDP_PHY_RX_CSR80_rxdp_edge_latchi_offsetp_END (7)
#define SOC_MUDP_PHY_RX_CSR80_rxdp_center_latchqb_offsetm_d1_START (8)
#define SOC_MUDP_PHY_RX_CSR80_rxdp_center_latchqb_offsetm_d1_END (15)
#define SOC_MUDP_PHY_RX_CSR80_rxdp_center_latchqb_offsetp_d1_START (16)
#define SOC_MUDP_PHY_RX_CSR80_rxdp_center_latchqb_offsetp_d1_END (23)
#define SOC_MUDP_PHY_RX_CSR80_rxdp_center_latchib_offsetm_d1_START (24)
#define SOC_MUDP_PHY_RX_CSR80_rxdp_center_latchib_offsetm_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_edge_latchib_offsetp : 8;
        unsigned int rxdp_edge_latchq_offsetm : 8;
        unsigned int rxdp_edge_latchq_offsetp : 8;
        unsigned int rxdp_edge_latchi_offsetm : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR81_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchib_offsetp_START (0)
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchib_offsetp_END (7)
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchq_offsetm_START (8)
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchq_offsetm_END (15)
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchq_offsetp_START (16)
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchq_offsetp_END (23)
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchi_offsetm_START (24)
#define SOC_MUDP_PHY_RX_CSR81_rxdp_edge_latchi_offsetm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxcp_clkq_skew : 4;
        unsigned int rxcp_clki_skew : 4;
        unsigned int rxdp_edge_latchqb_offsetm : 8;
        unsigned int rxdp_edge_latchqb_offsetp : 8;
        unsigned int rxdp_edge_latchib_offsetm : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR82_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR82_rxcp_clkq_skew_START (0)
#define SOC_MUDP_PHY_RX_CSR82_rxcp_clkq_skew_END (3)
#define SOC_MUDP_PHY_RX_CSR82_rxcp_clki_skew_START (4)
#define SOC_MUDP_PHY_RX_CSR82_rxcp_clki_skew_END (7)
#define SOC_MUDP_PHY_RX_CSR82_rxdp_edge_latchqb_offsetm_START (8)
#define SOC_MUDP_PHY_RX_CSR82_rxdp_edge_latchqb_offsetm_END (15)
#define SOC_MUDP_PHY_RX_CSR82_rxdp_edge_latchqb_offsetp_START (16)
#define SOC_MUDP_PHY_RX_CSR82_rxdp_edge_latchqb_offsetp_END (23)
#define SOC_MUDP_PHY_RX_CSR82_rxdp_edge_latchib_offsetm_START (24)
#define SOC_MUDP_PHY_RX_CSR82_rxdp_edge_latchib_offsetm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxatb_top : 3;
        unsigned int rxbe_atb_sel : 4;
        unsigned int reserved_0 : 2;
        unsigned int rxctle_atbsel : 3;
        unsigned int rx_diffp_det : 1;
        unsigned int reserved_1 : 1;
        unsigned int rx_jtag_bypass_en : 1;
        unsigned int rx_jtagdp : 1;
        unsigned int rx_jtagdm : 1;
        unsigned int rx_jtag_pwrdnb : 1;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 3;
        unsigned int reserved_5 : 1;
        unsigned int rx_pwmd_en : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
    } reg;
} SOC_MUDP_PHY_RX_CSR83_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR83_rxatb_top_START (0)
#define SOC_MUDP_PHY_RX_CSR83_rxatb_top_END (2)
#define SOC_MUDP_PHY_RX_CSR83_rxbe_atb_sel_START (3)
#define SOC_MUDP_PHY_RX_CSR83_rxbe_atb_sel_END (6)
#define SOC_MUDP_PHY_RX_CSR83_rxctle_atbsel_START (9)
#define SOC_MUDP_PHY_RX_CSR83_rxctle_atbsel_END (11)
#define SOC_MUDP_PHY_RX_CSR83_rx_diffp_det_START (12)
#define SOC_MUDP_PHY_RX_CSR83_rx_diffp_det_END (12)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtag_bypass_en_START (14)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtag_bypass_en_END (14)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtagdp_START (15)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtagdp_END (15)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtagdm_START (16)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtagdm_END (16)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtag_pwrdnb_START (17)
#define SOC_MUDP_PHY_RX_CSR83_rx_jtag_pwrdnb_END (17)
#define SOC_MUDP_PHY_RX_CSR83_rx_pwmd_en_START (26)
#define SOC_MUDP_PHY_RX_CSR83_rx_pwmd_en_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 7;
        unsigned int rxdp_vsd_atb_sel : 3;
        unsigned int rx_spare : 8;
        unsigned int rxpi_ctb_pm_sel : 1;
        unsigned int rxcp_ctbsrc_sel : 2;
        unsigned int rxdp_ctb_sel : 3;
        unsigned int rxdp_ctb_mux_pwrdnb : 1;
        unsigned int rxpi_ctb_sel : 2;
        unsigned int rx_otb_sel : 2;
        unsigned int rxcp_iqdet_atb_sel : 1;
        unsigned int rxatb_smp_lvccint : 2;
    } reg;
} SOC_MUDP_PHY_RX_CSR84_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR84_rxdp_vsd_atb_sel_START (7)
#define SOC_MUDP_PHY_RX_CSR84_rxdp_vsd_atb_sel_END (9)
#define SOC_MUDP_PHY_RX_CSR84_rx_spare_START (10)
#define SOC_MUDP_PHY_RX_CSR84_rx_spare_END (17)
#define SOC_MUDP_PHY_RX_CSR84_rxpi_ctb_pm_sel_START (18)
#define SOC_MUDP_PHY_RX_CSR84_rxpi_ctb_pm_sel_END (18)
#define SOC_MUDP_PHY_RX_CSR84_rxcp_ctbsrc_sel_START (19)
#define SOC_MUDP_PHY_RX_CSR84_rxcp_ctbsrc_sel_END (20)
#define SOC_MUDP_PHY_RX_CSR84_rxdp_ctb_sel_START (21)
#define SOC_MUDP_PHY_RX_CSR84_rxdp_ctb_sel_END (23)
#define SOC_MUDP_PHY_RX_CSR84_rxdp_ctb_mux_pwrdnb_START (24)
#define SOC_MUDP_PHY_RX_CSR84_rxdp_ctb_mux_pwrdnb_END (24)
#define SOC_MUDP_PHY_RX_CSR84_rxpi_ctb_sel_START (25)
#define SOC_MUDP_PHY_RX_CSR84_rxpi_ctb_sel_END (26)
#define SOC_MUDP_PHY_RX_CSR84_rx_otb_sel_START (27)
#define SOC_MUDP_PHY_RX_CSR84_rx_otb_sel_END (28)
#define SOC_MUDP_PHY_RX_CSR84_rxcp_iqdet_atb_sel_START (29)
#define SOC_MUDP_PHY_RX_CSR84_rxcp_iqdet_atb_sel_END (29)
#define SOC_MUDP_PHY_RX_CSR84_rxatb_smp_lvccint_START (30)
#define SOC_MUDP_PHY_RX_CSR84_rxatb_smp_lvccint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchib_offset_d1 : 9;
        unsigned int rxdp_center_latchi_offset_d0 : 9;
        unsigned int rxdp_center_latchi_offset_d1 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_RX_CSR85_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR85_rxdp_center_latchib_offset_d1_START (0)
#define SOC_MUDP_PHY_RX_CSR85_rxdp_center_latchib_offset_d1_END (8)
#define SOC_MUDP_PHY_RX_CSR85_rxdp_center_latchi_offset_d0_START (9)
#define SOC_MUDP_PHY_RX_CSR85_rxdp_center_latchi_offset_d0_END (17)
#define SOC_MUDP_PHY_RX_CSR85_rxdp_center_latchi_offset_d1_START (18)
#define SOC_MUDP_PHY_RX_CSR85_rxdp_center_latchi_offset_d1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchq_offset_d0 : 9;
        unsigned int rxdp_center_latchq_offset_d1 : 9;
        unsigned int rxdp_center_latchib_offset_d0 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PHY_RX_CSR86_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR86_rxdp_center_latchq_offset_d0_START (0)
#define SOC_MUDP_PHY_RX_CSR86_rxdp_center_latchq_offset_d0_END (8)
#define SOC_MUDP_PHY_RX_CSR86_rxdp_center_latchq_offset_d1_START (9)
#define SOC_MUDP_PHY_RX_CSR86_rxdp_center_latchq_offset_d1_END (17)
#define SOC_MUDP_PHY_RX_CSR86_rxdp_center_latchib_offset_d0_START (18)
#define SOC_MUDP_PHY_RX_CSR86_rxdp_center_latchib_offset_d0_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchqb_offset_d0 : 9;
        unsigned int rxdp_center_latchqb_offset_d1 : 9;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PHY_RX_CSR87_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR87_rxdp_center_latchqb_offset_d0_START (0)
#define SOC_MUDP_PHY_RX_CSR87_rxdp_center_latchqb_offset_d0_END (8)
#define SOC_MUDP_PHY_RX_CSR87_rxdp_center_latchqb_offset_d1_START (9)
#define SOC_MUDP_PHY_RX_CSR87_rxdp_center_latchqb_offset_d1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchib_offset_d0_cm_code : 8;
        unsigned int rxdp_center_latchib_offset_d1_cm_code : 8;
        unsigned int rxdp_center_latchi_offset_d0_cm_code : 8;
        unsigned int rxdp_center_latchi_offset_d1_cm_code : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR88_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchib_offset_d0_cm_code_START (0)
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchib_offset_d0_cm_code_END (7)
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchib_offset_d1_cm_code_START (8)
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchib_offset_d1_cm_code_END (15)
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchi_offset_d0_cm_code_START (16)
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchi_offset_d0_cm_code_END (23)
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchi_offset_d1_cm_code_START (24)
#define SOC_MUDP_PHY_RX_CSR88_rxdp_center_latchi_offset_d1_cm_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_center_latchqb_offset_d0_cm_code : 8;
        unsigned int rxdp_center_latchqb_offset_d1_cm_code : 8;
        unsigned int rxdp_center_latchq_offset_d0_cm_code : 8;
        unsigned int rxdp_center_latchq_offset_d1_cm_code : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR89_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchqb_offset_d0_cm_code_START (0)
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchqb_offset_d0_cm_code_END (7)
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchqb_offset_d1_cm_code_START (8)
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchqb_offset_d1_cm_code_END (15)
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchq_offset_d0_cm_code_START (16)
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchq_offset_d0_cm_code_END (23)
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchq_offset_d1_cm_code_START (24)
#define SOC_MUDP_PHY_RX_CSR89_rxdp_center_latchq_offset_d1_cm_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rxdp_edge_latchqb_offset_cm_code : 8;
        unsigned int rxdp_edge_latchq_offset_cm_code : 8;
        unsigned int rxdp_edge_latchib_offset_cm_code : 8;
        unsigned int rxdp_edge_latchi_offset_cm_code : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR90_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchqb_offset_cm_code_START (0)
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchqb_offset_cm_code_END (7)
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchq_offset_cm_code_START (8)
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchq_offset_cm_code_END (15)
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchib_offset_cm_code_START (16)
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchib_offset_cm_code_END (23)
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchi_offset_cm_code_START (24)
#define SOC_MUDP_PHY_RX_CSR90_rxdp_edge_latchi_offset_cm_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_gcalib_ctrl_code_min : 9;
        unsigned int rx_gcalib_ctrl_code_max : 9;
        unsigned int rx_gcalib_init_ctrl_code : 9;
        unsigned int rx_gcalib_trans_max : 4;
        unsigned int rx_gcalib_direction : 1;
    } reg;
} SOC_MUDP_PHY_RX_CSR91_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_ctrl_code_min_START (0)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_ctrl_code_min_END (8)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_ctrl_code_max_START (9)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_ctrl_code_max_END (17)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_init_ctrl_code_START (18)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_init_ctrl_code_END (26)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_trans_max_START (27)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_trans_max_END (30)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_direction_START (31)
#define SOC_MUDP_PHY_RX_CSR91_rx_gcalib_direction_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_ctrl_code_get_type : 3;
        unsigned int reserved_0 : 1;
        unsigned int rx_calib_start : 1;
        unsigned int rx_gcalib_done : 1;
        unsigned int rx_gcalib_trans_cnt : 4;
        unsigned int rx_gcalib_clr : 1;
        unsigned int rx_gcalib_code_format : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_MUDP_PHY_RX_CSR92_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR92_rx_ctrl_code_get_type_START (0)
#define SOC_MUDP_PHY_RX_CSR92_rx_ctrl_code_get_type_END (2)
#define SOC_MUDP_PHY_RX_CSR92_rx_calib_start_START (4)
#define SOC_MUDP_PHY_RX_CSR92_rx_calib_start_END (4)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_done_START (5)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_done_END (5)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_trans_cnt_START (6)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_trans_cnt_END (9)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_clr_START (10)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_clr_END (10)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_code_format_START (11)
#define SOC_MUDP_PHY_RX_CSR92_rx_gcalib_code_format_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_timer_clr : 1;
        unsigned int rx_timer_start : 1;
        unsigned int reserved_0 : 14;
        unsigned int rx_timer_base : 5;
        unsigned int rx_timer_exp : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MUDP_PHY_RX_CSR93_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_clr_START (0)
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_clr_END (0)
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_start_START (1)
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_start_END (1)
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_base_START (16)
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_base_END (20)
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_exp_START (21)
#define SOC_MUDP_PHY_RX_CSR93_rx_timer_exp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_calib_latch_ready : 1;
        unsigned int rx_calib_latch_status : 1;
        unsigned int rx_calib_latch_bit1_num : 16;
        unsigned int rx_calib_window : 2;
        unsigned int rx_calib_latch_sel : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_PHY_RX_CSR94_UNION;
#endif
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_ready_START (0)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_ready_END (0)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_status_START (1)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_status_END (1)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_bit1_num_START (2)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_bit1_num_END (17)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_window_START (18)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_window_END (19)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_sel_START (20)
#define SOC_MUDP_PHY_RX_CSR94_rx_calib_latch_sel_END (23)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
