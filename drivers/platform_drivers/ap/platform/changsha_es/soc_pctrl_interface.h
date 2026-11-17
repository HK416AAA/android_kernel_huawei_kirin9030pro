#ifndef __SOC_PCTRL_INTERFACE_H__
#define __SOC_PCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PCTRL_G3D_RASTER_ADDR(base) ((base) + (0x0000UL))
#define SOC_PCTRL_USB2_HOST_CTRL0_ADDR(base) ((base) + (0x0004UL))
#define SOC_PCTRL_USB2_HOST_CTRL1_ADDR(base) ((base) + (0x0008UL))
#define SOC_PCTRL_USB2_HOST_CTRL2_ADDR(base) ((base) + (0x000CUL))
#define SOC_PCTRL_PERI_CTRL4_ADDR(base) ((base) + (0x0010UL))
#define SOC_PCTRL_PERI_CTRL98_ADDR(base) ((base) + (0x0014UL))
#define SOC_PCTRL_PERI_CTRL99_ADDR(base) ((base) + (0x0018UL))
#define SOC_PCTRL_PERI_CTRL100_ADDR(base) ((base) + (0x001CUL))
#define SOC_PCTRL_PERI_CTRL101_ADDR(base) ((base) + (0x0020UL))
#define SOC_PCTRL_PERI_CTRL104_ADDR(base) ((base) + (0x0024UL))
#define SOC_PCTRL_PERI_CTRL12_ADDR(base) ((base) + (0x0028UL))
#define SOC_PCTRL_PERI_CTRL13_ADDR(base) ((base) + (0x002CUL))
#define SOC_PCTRL_PERI_CTRL14_ADDR(base) ((base) + (0x0030UL))
#define SOC_PCTRL_PERI_CTRL15_ADDR(base) ((base) + (0x0034UL))
#define SOC_PCTRL_PERI_CTRL16_ADDR(base) ((base) + (0x0038UL))
#define SOC_PCTRL_PERI_CTRL17_ADDR(base) ((base) + (0x003CUL))
#define SOC_PCTRL_PERI_CTRL18_ADDR(base) ((base) + (0x0040UL))
#define SOC_PCTRL_PERI_CTRL19_ADDR(base) ((base) + (0x0044UL))
#define SOC_PCTRL_PERI_CTRL20_ADDR(base) ((base) + (0x0048UL))
#define SOC_PCTRL_PERI_CTRL21_ADDR(base) ((base) + (0x004CUL))
#define SOC_PCTRL_PERI_CTRL22_ADDR(base) ((base) + (0x0050UL))
#define SOC_PCTRL_PERI_CTRL23_ADDR(base) ((base) + (0x0054UL))
#define SOC_PCTRL_PERI_CTRL24_ADDR(base) ((base) + (0x0058UL))
#define SOC_PCTRL_PERI_CTRL25_ADDR(base) ((base) + (0x005CUL))
#define SOC_PCTRL_PERI_CTRL26_ADDR(base) ((base) + (0x0060UL))
#define SOC_PCTRL_PERI_CTRL27_ADDR(base) ((base) + (0x0064UL))
#define SOC_PCTRL_PERI_CTRL28_ADDR(base) ((base) + (0x0068UL))
#define SOC_PCTRL_PERI_CTRL29_ADDR(base) ((base) + (0x006CUL))
#define SOC_PCTRL_PERI_CTRL30_ADDR(base) ((base) + (0x0070UL))
#define SOC_PCTRL_PERI_CTRL31_ADDR(base) ((base) + (0x0074UL))
#define SOC_PCTRL_PERI_CTRL32_ADDR(base) ((base) + (0x0078UL))
#define SOC_PCTRL_PERI_CTRL33_ADDR(base) ((base) + (0x007CUL))
#define SOC_PCTRL_PERI_CTRL67_ADDR(base) ((base) + (0x0080UL))
#define SOC_PCTRL_PERI_CTRL68_ADDR(base) ((base) + (0x0084UL))
#define SOC_PCTRL_PERI_CTRL69_ADDR(base) ((base) + (0x0088UL))
#define SOC_PCTRL_PERI_CTRL70_ADDR(base) ((base) + (0x008CUL))
#define SOC_PCTRL_PERI_CTRL71_ADDR(base) ((base) + (0x0090UL))
#define SOC_PCTRL_PERI_CTRL72_ADDR(base) ((base) + (0x0094UL))
#define SOC_PCTRL_PERI_CTRL73_ADDR(base) ((base) + (0x0098UL))
#define SOC_PCTRL_PERI_CTRL74_ADDR(base) ((base) + (0x009CUL))
#define SOC_PCTRL_PERI_CTRL88_ADDR(base) ((base) + (0x00A0UL))
#define SOC_PCTRL_PERI_CTRL89_ADDR(base) ((base) + (0x00A4UL))
#define SOC_PCTRL_PERI_CTRL90_ADDR(base) ((base) + (0x00A8UL))
#define SOC_PCTRL_PERI_CTRL91_ADDR(base) ((base) + (0x00ACUL))
#define SOC_PCTRL_PERI_CTRL92_ADDR(base) ((base) + (0x00B0UL))
#define SOC_PCTRL_PERI_CTRL93_ADDR(base) ((base) + (0x00B4UL))
#define SOC_PCTRL_PERI_CTRL95_ADDR(base) ((base) + (0x00B8UL))
#define SOC_PCTRL_PERI_CTRL96_ADDR(base) ((base) + (0x00BCUL))
#define SOC_PCTRL_PERI_CTRL97_ADDR(base) ((base) + (0x00C0UL))
#define SOC_PCTRL_PERI_CTRL108_ADDR(base) ((base) + (0x00C4UL))
#define SOC_PCTRL_PERI_CTRL109_ADDR(base) ((base) + (0x00C8UL))
#define SOC_PCTRL_PERI_CTRL110_ADDR(base) ((base) + (0x00CCUL))
#define SOC_PCTRL_PERI_CTRL111_ADDR(base) ((base) + (0x00D0UL))
#define SOC_PCTRL_PERI_CTRL112_ADDR(base) ((base) + (0x00D4UL))
#define SOC_PCTRL_PERI_CTRL113_ADDR(base) ((base) + (0x00D8UL))
#define SOC_PCTRL_PERI_CTRL114_ADDR(base) ((base) + (0x00DCUL))
#define SOC_PCTRL_PERI_CTRL115_ADDR(base) ((base) + (0x00E0UL))
#define SOC_PCTRL_PERI_CTRL116_ADDR(base) ((base) + (0x00E4UL))
#define SOC_PCTRL_PERI_CTRL117_ADDR(base) ((base) + (0x00E8UL))
#define SOC_PCTRL_PERI_CTRL118_ADDR(base) ((base) + (0x00ECUL))
#define SOC_PCTRL_PERI_CTRL119_ADDR(base) ((base) + (0x00F0UL))
#define SOC_PCTRL_PERI_CTRL120_ADDR(base) ((base) + (0x00F4UL))
#define SOC_PCTRL_PERI_CTRL121_ADDR(base) ((base) + (0x00F8UL))
#define SOC_PCTRL_PERI_CTRL122_ADDR(base) ((base) + (0x00FCUL))
#define SOC_PCTRL_PERI_CTRL123_ADDR(base) ((base) + (0x0100UL))
#define SOC_PCTRL_PERI_CTRL124_ADDR(base) ((base) + (0x0104UL))
#define SOC_PCTRL_PERI_CTRL125_ADDR(base) ((base) + (0x0108UL))
#define SOC_PCTRL_PERI_CTRL126_ADDR(base) ((base) + (0x010CUL))
#define SOC_PCTRL_PERI_CTRL127_ADDR(base) ((base) + (0x0110UL))
#define SOC_PCTRL_PERI_CTRL128_ADDR(base) ((base) + (0x0114UL))
#define SOC_PCTRL_PERI_CTRL129_ADDR(base) ((base) + (0x0118UL))
#define SOC_PCTRL_PERI_CTRL130_ADDR(base) ((base) + (0x011CUL))
#define SOC_PCTRL_PERI_CTRL131_ADDR(base) ((base) + (0x0120UL))
#define SOC_PCTRL_PERI_CTRL132_ADDR(base) ((base) + (0x0124UL))
#define SOC_PCTRL_PERI_CTRL133_ADDR(base) ((base) + (0x0128UL))
#define SOC_PCTRL_PERI_CTRL134_ADDR(base) ((base) + (0x012CUL))
#define SOC_PCTRL_PERI_CTRL135_ADDR(base) ((base) + (0x0130UL))
#define SOC_PCTRL_PERI_CTRL136_ADDR(base) ((base) + (0x0134UL))
#define SOC_PCTRL_MDM_TSP_NMI0_ADDR(base) ((base) + (0x0138UL))
#define SOC_PCTRL_PERI_CTRL138_ADDR(base) ((base) + (0x013CUL))
#define SOC_PCTRL_PERI_CTRL139_ADDR(base) ((base) + (0x0140UL))
#define SOC_PCTRL_PERI_CTRL140_ADDR(base) ((base) + (0x0144UL))
#define SOC_PCTRL_PERI_CTRL141_ADDR(base) ((base) + (0x0148UL))
#define SOC_PCTRL_PERI_CTRL142_ADDR(base) ((base) + (0x014CUL))
#define SOC_PCTRL_PERI_CTRL143_ADDR(base) ((base) + (0x0150UL))
#define SOC_PCTRL_PERI_CTRL144_ADDR(base) ((base) + (0x0154UL))
#define SOC_PCTRL_PERI_CTRL145_ADDR(base) ((base) + (0x0158UL))
#define SOC_PCTRL_PERI_CTRL146_ADDR(base) ((base) + (0x015CUL))
#define SOC_PCTRL_PERI_CTRL147_ADDR(base) ((base) + (0x0160UL))
#define SOC_PCTRL_PERI_CTRL148_ADDR(base) ((base) + (0x0164UL))
#define SOC_PCTRL_PERI_CTRL149_ADDR(base) ((base) + (0x0168UL))
#define SOC_PCTRL_PERI_CTRL150_ADDR(base) ((base) + (0x016CUL))
#define SOC_PCTRL_PERI_CTRL151_ADDR(base) ((base) + (0x0170UL))
#define SOC_PCTRL_PERI_CTRL152_ADDR(base) ((base) + (0x0174UL))
#define SOC_PCTRL_PERI_CTRL153_ADDR(base) ((base) + (0x0178UL))
#define SOC_PCTRL_PERI_CTRL154_ADDR(base) ((base) + (0x017CUL))
#define SOC_PCTRL_PERI_CTRL155_ADDR(base) ((base) + (0x0180UL))
#define SOC_PCTRL_PERI_CTRL156_ADDR(base) ((base) + (0x0184UL))
#define SOC_PCTRL_PERI_CTRL157_ADDR(base) ((base) + (0x0188UL))
#define SOC_PCTRL_PERI_CTRL158_ADDR(base) ((base) + (0x018CUL))
#define SOC_PCTRL_PERI_CTRL159_ADDR(base) ((base) + (0x0190UL))
#define SOC_PCTRL_PERI_CTRL160_ADDR(base) ((base) + (0x0194UL))
#define SOC_PCTRL_PERI_CTRL161_ADDR(base) ((base) + (0x0198UL))
#define SOC_PCTRL_PERI_CTRL162_ADDR(base) ((base) + (0x019CUL))
#define SOC_PCTRL_PERI_CTRL163_ADDR(base) ((base) + (0x01A0UL))
#define SOC_PCTRL_PERI_CTRL164_ADDR(base) ((base) + (0x01A4UL))
#define SOC_PCTRL_PERI_CTRL165_ADDR(base) ((base) + (0x01A8UL))
#define SOC_PCTRL_PERI_CTRL166_ADDR(base) ((base) + (0x01ACUL))
#define SOC_PCTRL_PERI_CTRL167_ADDR(base) ((base) + (0x01B0UL))
#define SOC_PCTRL_PERI_STAT0_ADDR(base) ((base) + (0x1000UL))
#define SOC_PCTRL_PERI_STAT1_ADDR(base) ((base) + (0x1004UL))
#define SOC_PCTRL_PERI_STAT2_ADDR(base) ((base) + (0x1008UL))
#define SOC_PCTRL_PERI_STAT3_ADDR(base) ((base) + (0x100CUL))
#define SOC_PCTRL_PERI_STAT4_ADDR(base) ((base) + (0x1010UL))
#define SOC_PCTRL_PERI_STAT5_ADDR(base) ((base) + (0x1014UL))
#define SOC_PCTRL_PERI_STAT6_ADDR(base) ((base) + (0x1018UL))
#define SOC_PCTRL_PERI_STAT7_ADDR(base) ((base) + (0x101CUL))
#define SOC_PCTRL_PERI_STAT8_ADDR(base) ((base) + (0x1020UL))
#define SOC_PCTRL_PERI_STAT9_ADDR(base) ((base) + (0x1024UL))
#define SOC_PCTRL_PERI_STAT10_ADDR(base) ((base) + (0x1028UL))
#define SOC_PCTRL_PERI_STAT11_ADDR(base) ((base) + (0x102CUL))
#define SOC_PCTRL_PERI_STAT12_ADDR(base) ((base) + (0x1030UL))
#define SOC_PCTRL_PERI_STAT13_ADDR(base) ((base) + (0x1034UL))
#define SOC_PCTRL_PERI_STAT14_ADDR(base) ((base) + (0x1038UL))
#define SOC_PCTRL_PERI_STAT15_ADDR(base) ((base) + (0x103CUL))
#define SOC_PCTRL_PERI_STAT16_ADDR(base) ((base) + (0x1040UL))
#define SOC_PCTRL_PERI_STAT17_ADDR(base) ((base) + (0x1044UL))
#define SOC_PCTRL_PERI_STAT18_ADDR(base) ((base) + (0x1048UL))
#define SOC_PCTRL_PERI_STAT19_ADDR(base) ((base) + (0x104CUL))
#define SOC_PCTRL_PERI_STAT29_ADDR(base) ((base) + (0x1050UL))
#define SOC_PCTRL_PERI_STAT30_ADDR(base) ((base) + (0x1054UL))
#define SOC_PCTRL_PERI_STAT31_ADDR(base) ((base) + (0x1058UL))
#define SOC_PCTRL_PERI_STAT32_ADDR(base) ((base) + (0x105CUL))
#define SOC_PCTRL_PERI_STAT33_ADDR(base) ((base) + (0x1060UL))
#define SOC_PCTRL_PERI_STAT34_ADDR(base) ((base) + (0x1064UL))
#define SOC_PCTRL_PERI_STAT35_ADDR(base) ((base) + (0x1068UL))
#define SOC_PCTRL_PERI_STAT36_ADDR(base) ((base) + (0x106CUL))
#define SOC_PCTRL_PERI_STAT37_ADDR(base) ((base) + (0x1070UL))
#define SOC_PCTRL_PERI_STAT38_ADDR(base) ((base) + (0x1074UL))
#define SOC_PCTRL_PERI_STAT39_ADDR(base) ((base) + (0x1078UL))
#define SOC_PCTRL_PERI_STAT40_ADDR(base) ((base) + (0x107CUL))
#define SOC_PCTRL_PERI_STAT41_ADDR(base) ((base) + (0x1080UL))
#define SOC_PCTRL_PERI_STAT42_ADDR(base) ((base) + (0x1084UL))
#define SOC_PCTRL_PERI_STAT43_ADDR(base) ((base) + (0x1088UL))
#define SOC_PCTRL_PERI_STAT44_ADDR(base) ((base) + (0x108CUL))
#define SOC_PCTRL_PERI_STAT45_ADDR(base) ((base) + (0x1090UL))
#define SOC_PCTRL_PERI_STAT46_ADDR(base) ((base) + (0x1094UL))
#define SOC_PCTRL_PERI_STAT47_ADDR(base) ((base) + (0x1098UL))
#define SOC_PCTRL_PERI_STAT48_ADDR(base) ((base) + (0x109CUL))
#define SOC_PCTRL_PERI_STAT49_ADDR(base) ((base) + (0x10A0UL))
#define SOC_PCTRL_PERI_STAT50_ADDR(base) ((base) + (0x10A4UL))
#define SOC_PCTRL_PERI_STAT51_ADDR(base) ((base) + (0x10A8UL))
#define SOC_PCTRL_PERI_STAT52_ADDR(base) ((base) + (0x10ACUL))
#define SOC_PCTRL_PERI_STAT53_ADDR(base) ((base) + (0x10B0UL))
#define SOC_PCTRL_PERI_STAT54_ADDR(base) ((base) + (0x10B4UL))
#define SOC_PCTRL_PERI_STAT55_ADDR(base) ((base) + (0x10B8UL))
#define SOC_PCTRL_PERI_STAT56_ADDR(base) ((base) + (0x10BCUL))
#define SOC_PCTRL_PERI_STAT57_ADDR(base) ((base) + (0x10C0UL))
#define SOC_PCTRL_PERI_STAT58_ADDR(base) ((base) + (0x10C4UL))
#define SOC_PCTRL_PERI_STAT59_ADDR(base) ((base) + (0x10C8UL))
#define SOC_PCTRL_PERI_STAT60_ADDR(base) ((base) + (0x10CCUL))
#define SOC_PCTRL_PERI_STAT61_ADDR(base) ((base) + (0x10D0UL))
#define SOC_PCTRL_PERI_STAT62_ADDR(base) ((base) + (0x10D4UL))
#define SOC_PCTRL_PERI_STAT63_ADDR(base) ((base) + (0x10D8UL))
#define SOC_PCTRL_PERI_STAT64_ADDR(base) ((base) + (0x10DCUL))
#define SOC_PCTRL_PERI_STAT66_ADDR(base) ((base) + (0x10E0UL))
#define SOC_PCTRL_PERI_STAT67_ADDR(base) ((base) + (0x10E4UL))
#define SOC_PCTRL_PERI_STAT68_ADDR(base) ((base) + (0x10E8UL))
#define SOC_PCTRL_PERI_STAT69_ADDR(base) ((base) + (0x10ECUL))
#define SOC_PCTRL_PERI_STAT70_ADDR(base) ((base) + (0x10F0UL))
#define SOC_PCTRL_PERI_STAT71_ADDR(base) ((base) + (0x10F4UL))
#define SOC_PCTRL_PERI_STAT72_ADDR(base) ((base) + (0x10F8UL))
#define SOC_PCTRL_PERI_STAT73_ADDR(base) ((base) + (0x10FCUL))
#define SOC_PCTRL_PERI_STAT74_ADDR(base) ((base) + (0x1100UL))
#define SOC_PCTRL_PERI_STAT75_ADDR(base) ((base) + (0x1104UL))
#define SOC_PCTRL_PERI_STAT76_ADDR(base) ((base) + (0x1108UL))
#define SOC_PCTRL_PERI_STAT77_ADDR(base) ((base) + (0x110CUL))
#define SOC_PCTRL_PERI_STAT78_ADDR(base) ((base) + (0x1110UL))
#define SOC_PCTRL_PERI_STAT79_ADDR(base) ((base) + (0x1114UL))
#define SOC_PCTRL_PERI_STAT80_ADDR(base) ((base) + (0x1118UL))
#define SOC_PCTRL_PERI_STAT81_ADDR(base) ((base) + (0x111CUL))
#define SOC_PCTRL_PERI_STAT82_ADDR(base) ((base) + (0x1120UL))
#define SOC_PCTRL_PERI_STAT83_ADDR(base) ((base) + (0x1124UL))
#define SOC_PCTRL_PERI_STAT84_ADDR(base) ((base) + (0x1128UL))
#define SOC_PCTRL_PERI_STAT85_ADDR(base) ((base) + (0x112CUL))
#define SOC_PCTRL_PERI_STAT86_ADDR(base) ((base) + (0x1130UL))
#define SOC_PCTRL_PERI_STAT87_ADDR(base) ((base) + (0x1134UL))
#define SOC_PCTRL_PERI_STAT88_ADDR(base) ((base) + (0x1138UL))
#define SOC_PCTRL_PERI_STAT89_ADDR(base) ((base) + (0x113CUL))
#define SOC_PCTRL_PERI_STAT90_ADDR(base) ((base) + (0x1140UL))
#define SOC_PCTRL_PERI_STAT91_ADDR(base) ((base) + (0x1144UL))
#define SOC_PCTRL_PERI_STAT92_ADDR(base) ((base) + (0x1148UL))
#define SOC_PCTRL_PERI_STAT93_ADDR(base) ((base) + (0x114CUL))
#define SOC_PCTRL_PERI_STAT94_ADDR(base) ((base) + (0x1150UL))
#define SOC_PCTRL_PERI_STAT95_ADDR(base) ((base) + (0x1154UL))
#define SOC_PCTRL_PERI_STAT96_ADDR(base) ((base) + (0x1158UL))
#define SOC_PCTRL_PERI_STAT97_ADDR(base) ((base) + (0x115CUL))
#define SOC_PCTRL_PERI_STAT98_ADDR(base) ((base) + (0x1160UL))
#define SOC_PCTRL_PERI_STAT99_ADDR(base) ((base) + (0x1164UL))
#define SOC_PCTRL_PERI_STAT100_ADDR(base) ((base) + (0x1168UL))
#define SOC_PCTRL_PERI_STAT101_ADDR(base) ((base) + (0x116CUL))
#define SOC_PCTRL_PERI_STAT102_ADDR(base) ((base) + (0x1170UL))
#define SOC_PCTRL_PERI_STAT103_ADDR(base) ((base) + (0x1174UL))
#define SOC_PCTRL_PERI_STAT104_ADDR(base) ((base) + (0x1178UL))
#define SOC_PCTRL_PERI_STAT105_ADDR(base) ((base) + (0x117CUL))
#define SOC_PCTRL_PERI_STAT106_ADDR(base) ((base) + (0x1180UL))
#define SOC_PCTRL_PERI_STAT107_ADDR(base) ((base) + (0x1184UL))
#define SOC_PCTRL_PERI_STAT108_ADDR(base) ((base) + (0x1188UL))
#define SOC_PCTRL_PERI_STAT109_ADDR(base) ((base) + (0x118CUL))
#define SOC_PCTRL_PERI_STAT110_ADDR(base) ((base) + (0x1190UL))
#define SOC_PCTRL_PERI_STAT111_ADDR(base) ((base) + (0x1194UL))
#define SOC_PCTRL_PERI_STAT112_ADDR(base) ((base) + (0x1198UL))
#define SOC_PCTRL_PERI_STAT113_ADDR(base) ((base) + (0x119CUL))
#define SOC_PCTRL_PERI_STAT114_ADDR(base) ((base) + (0x11A0UL))
#define SOC_PCTRL_PERI_STAT115_ADDR(base) ((base) + (0x11A4UL))
#define SOC_PCTRL_PERI_STAT116_ADDR(base) ((base) + (0x11A8UL))
#define SOC_PCTRL_PERI_STAT117_ADDR(base) ((base) + (0x11ACUL))
#define SOC_PCTRL_PERI_STAT118_ADDR(base) ((base) + (0x11B0UL))
#define SOC_PCTRL_PERI_STAT119_ADDR(base) ((base) + (0x11B4UL))
#define SOC_PCTRL_PERI_STAT120_ADDR(base) ((base) + (0x11B8UL))
#define SOC_PCTRL_PERI_STAT121_ADDR(base) ((base) + (0x11BCUL))
#define SOC_PCTRL_PERI_STAT122_ADDR(base) ((base) + (0x11C0UL))
#define SOC_PCTRL_PERI_STAT123_ADDR(base) ((base) + (0x11C4UL))
#define SOC_PCTRL_PERI_STAT124_ADDR(base) ((base) + (0x11C8UL))
#define SOC_PCTRL_PERI_STAT125_ADDR(base) ((base) + (0x11CCUL))
#define SOC_PCTRL_PERI_STAT126_ADDR(base) ((base) + (0x11D0UL))
#define SOC_PCTRL_PERI_STAT127_ADDR(base) ((base) + (0x11D4UL))
#define SOC_PCTRL_PERI_STAT128_ADDR(base) ((base) + (0x11D8UL))
#define SOC_PCTRL_PERI_STAT129_ADDR(base) ((base) + (0x11DCUL))
#define SOC_PCTRL_PERI_STAT130_ADDR(base) ((base) + (0x11E0UL))
#define SOC_PCTRL_PERI_STAT131_ADDR(base) ((base) + (0x11E4UL))
#define SOC_PCTRL_PERI_STAT132_ADDR(base) ((base) + (0x11E8UL))
#define SOC_PCTRL_PERI_STAT133_ADDR(base) ((base) + (0x11ECUL))
#define SOC_PCTRL_PERI_STAT134_ADDR(base) ((base) + (0x11F0UL))
#define SOC_PCTRL_PERI_STAT135_ADDR(base) ((base) + (0x11F4UL))
#define SOC_PCTRL_PERI_STAT136_ADDR(base) ((base) + (0x11F8UL))
#define SOC_PCTRL_PERI_STAT137_ADDR(base) ((base) + (0x11FCUL))
#define SOC_PCTRL_PERI_STAT138_ADDR(base) ((base) + (0x1200UL))
#define SOC_PCTRL_PERI_STAT139_ADDR(base) ((base) + (0x1204UL))
#define SOC_PCTRL_PERI_STAT140_ADDR(base) ((base) + (0x1208UL))
#define SOC_PCTRL_PERI_STAT141_ADDR(base) ((base) + (0x120CUL))
#define SOC_PCTRL_PERI_STAT142_ADDR(base) ((base) + (0x1210UL))
#define SOC_PCTRL_PERI_STAT143_ADDR(base) ((base) + (0x1214UL))
#define SOC_PCTRL_PERI_STAT144_ADDR(base) ((base) + (0x1218UL))
#define SOC_PCTRL_PERI_STAT145_ADDR(base) ((base) + (0x121CUL))
#define SOC_PCTRL_PERI_STAT146_ADDR(base) ((base) + (0x1220UL))
#define SOC_PCTRL_PERI_STAT147_ADDR(base) ((base) + (0x1224UL))
#define SOC_PCTRL_PERI_STAT148_ADDR(base) ((base) + (0x1228UL))
#define SOC_PCTRL_PERI_STAT149_ADDR(base) ((base) + (0x122CUL))
#define SOC_PCTRL_PERI_STAT150_ADDR(base) ((base) + (0x1230UL))
#define SOC_PCTRL_PERI_STAT151_ADDR(base) ((base) + (0x1234UL))
#define SOC_PCTRL_PERI_STAT152_ADDR(base) ((base) + (0x1238UL))
#define SOC_PCTRL_PERI_STAT153_ADDR(base) ((base) + (0x123CUL))
#define SOC_PCTRL_PERI_STAT154_ADDR(base) ((base) + (0x1240UL))
#define SOC_PCTRL_PERI_STAT155_ADDR(base) ((base) + (0x1244UL))
#define SOC_PCTRL_PERI_STAT156_ADDR(base) ((base) + (0x1248UL))
#define SOC_PCTRL_PERI_STAT157_ADDR(base) ((base) + (0x124CUL))
#define SOC_PCTRL_PERI_STAT158_ADDR(base) ((base) + (0x1250UL))
#define SOC_PCTRL_PERI_STAT159_ADDR(base) ((base) + (0x1254UL))
#define SOC_PCTRL_PERI_CTRL0_ADDR(base) ((base) + (0x1800UL))
#define SOC_PCTRL_PERI_CTRL1_ADDR(base) ((base) + (0x1804UL))
#define SOC_PCTRL_PERI_CTRL2_ADDR(base) ((base) + (0x1808UL))
#define SOC_PCTRL_PERI_CTRL3_ADDR(base) ((base) + (0x181CUL))
#define SOC_PCTRL_PERI_CTRL102_ADDR(base) ((base) + (0x1820UL))
#define SOC_PCTRL_PERI_CTRL103_ADDR(base) ((base) + (0x1824UL))
#define SOC_PCTRL_PERI_CTRL105_ADDR(base) ((base) + (0x1828UL))
#define SOC_PCTRL_PERI_CTRL106_ADDR(base) ((base) + (0x182CUL))
#define SOC_PCTRL_PERI_CTRL107_ADDR(base) ((base) + (0x1830UL))
#define SOC_PCTRL_PERI_CTRL176_WC_ADDR(base) ((base) + (0x1834UL))
#define SOC_PCTRL_PERI_CTRL177_WC_ADDR(base) ((base) + (0x1838UL))
#define SOC_PCTRL_PERI_CTRL178_WC_ADDR(base) ((base) + (0x183CUL))
#define SOC_PCTRL_PERI_CTRL179_WC_ADDR(base) ((base) + (0x1840UL))
#define SOC_PCTRL_PERI_CTRL180_WC_ADDR(base) ((base) + (0x1844UL))
#define SOC_PCTRL_PERI_CTRL181_WC_ADDR(base) ((base) + (0x1848UL))
#define SOC_PCTRL_PERI_CTRL182_WC_ADDR(base) ((base) + (0x184CUL))
#define SOC_PCTRL_PERI_CTRL183_WC_ADDR(base) ((base) + (0x1850UL))
#define SOC_PCTRL_PERI_CTRL184_WC_ADDR(base) ((base) + (0x1854UL))
#define SOC_PCTRL_PERI_CTRL185_WC_ADDR(base) ((base) + (0x1858UL))
#define SOC_PCTRL_PERI_CTRL186_WC_ADDR(base) ((base) + (0x185CUL))
#define SOC_PCTRL_PERI_CTRL187_WC_ADDR(base) ((base) + (0x1860UL))
#define SOC_PCTRL_PERI_CTRL188_WC_ADDR(base) ((base) + (0x1864UL))
#define SOC_PCTRL_PERI_CTRL189_WC_ADDR(base) ((base) + (0x1868UL))
#define SOC_PCTRL_PERI_CTRL190_CTRL_ADDR(base) ((base) + (0x186CUL))
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_ADDR(base) ((base) + (0x1870UL))
#define SOC_PCTRL_PERI_CTRL192_WC_ADDR(base) ((base) + (0x1874UL))
#define SOC_PCTRL_PERI_CTRL193_WC_ADDR(base) ((base) + (0x1878UL))
#define SOC_PCTRL_PERI_CTRL194_WC_ADDR(base) ((base) + (0x187CUL))
#define SOC_PCTRL_R2_PERI_CTRL0_WC_ADDR(base) ((base) + (0x1880UL))
#define SOC_PCTRL_R2_PERI_CTRL1_WC_ADDR(base) ((base) + (0x1884UL))
#define SOC_PCTRL_R2_PERI_CTRL2_WC_ADDR(base) ((base) + (0x1888UL))
#define SOC_PCTRL_R2_PERI_CTRL3_WC_ADDR(base) ((base) + (0x188CUL))
#define SOC_PCTRL_R2_PERI_CTRL4_WC_ADDR(base) ((base) + (0x1890UL))
#define SOC_PCTRL_R2_PERI_CTRL5_WC_ADDR(base) ((base) + (0x1894UL))
#define SOC_PCTRL_R2_PERI_CTRL6_WC_ADDR(base) ((base) + (0x1898UL))
#define SOC_PCTRL_R2_PERI_CTRL7_WC_ADDR(base) ((base) + (0x189CUL))
#define SOC_PCTRL_R2_PERI_CTRL8_WC_ADDR(base) ((base) + (0x18A0UL))
#define SOC_PCTRL_R2_PERI_CTRL9_WC_ADDR(base) ((base) + (0x18A4UL))
#define SOC_PCTRL_R2_PERI_CTRL10_WC_ADDR(base) ((base) + (0x18A8UL))
#define SOC_PCTRL_R2_PERI_CTRL11_WC_ADDR(base) ((base) + (0x18ACUL))
#define SOC_PCTRL_R2_PERI_CTRL12_WC_ADDR(base) ((base) + (0x18B0UL))
#define SOC_PCTRL_R2_PERI_CTRL13_WC_ADDR(base) ((base) + (0x18B4UL))
#define SOC_PCTRL_R2_PERI_CTRL14_WC_ADDR(base) ((base) + (0x18B8UL))
#define SOC_PCTRL_R2_PERI_CTRL15_WC_ADDR(base) ((base) + (0x18BCUL))
#define SOC_PCTRL_R2_PERI_CTRL16_WC_ADDR(base) ((base) + (0x18C0UL))
#define SOC_PCTRL_R2_PERI_CTRL17_WC_ADDR(base) ((base) + (0x18C4UL))
#define SOC_PCTRL_R2_PERI_CTRL18_WC_ADDR(base) ((base) + (0x18C8UL))
#define SOC_PCTRL_R2_PERI_CTRL19_WC_ADDR(base) ((base) + (0x18CCUL))
#define SOC_PCTRL_R2_PERI_CTRL20_WC_ADDR(base) ((base) + (0x18D0UL))
#define SOC_PCTRL_R2_PERI_CTRL21_WC_ADDR(base) ((base) + (0x18D4UL))
#define SOC_PCTRL_R2_PERI_CTRL22_WC_ADDR(base) ((base) + (0x18D8UL))
#define SOC_PCTRL_R2_PERI_CTRL23_WC_ADDR(base) ((base) + (0x18DCUL))
#define SOC_PCTRL_R2_PERI_CTRL24_WC_ADDR(base) ((base) + (0x18E0UL))
#define SOC_PCTRL_R2_PERI_CTRL25_WC_ADDR(base) ((base) + (0x18E4UL))
#define SOC_PCTRL_R2_PERI_CTRL26_WC_ADDR(base) ((base) + (0x18E8UL))
#define SOC_PCTRL_R2_PERI_CTRL27_WC_ADDR(base) ((base) + (0x18ECUL))
#define SOC_PCTRL_R2_PERI_CTRL28_WC_ADDR(base) ((base) + (0x18F0UL))
#define SOC_PCTRL_R2_PERI_CTRL29_WC_ADDR(base) ((base) + (0x18F4UL))
#define SOC_PCTRL_R2_PERI_CTRL30_WC_ADDR(base) ((base) + (0x18F8UL))
#define SOC_PCTRL_R2_PERI_CTRL31_WC_ADDR(base) ((base) + (0x18FCUL))
#define SOC_PCTRL_R2_PERI_CTRL32_WC_ADDR(base) ((base) + (0x1900UL))
#define SOC_PCTRL_R2_PERI_CTRL33_WC_ADDR(base) ((base) + (0x1904UL))
#define SOC_PCTRL_R2_PERI_CTRL34_WC_ADDR(base) ((base) + (0x1908UL))
#define SOC_PCTRL_R2_PERI_CTRL35_WC_ADDR(base) ((base) + (0x190CUL))
#define SOC_PCTRL_R2_PERI_CTRL36_WC_ADDR(base) ((base) + (0x1910UL))
#define SOC_PCTRL_R2_PERI_CTRL37_WC_ADDR(base) ((base) + (0x1914UL))
#define SOC_PCTRL_R2_PERI_CTRL38_WC_ADDR(base) ((base) + (0x1918UL))
#define SOC_PCTRL_R2_PERI_CTRL39_WC_ADDR(base) ((base) + (0x191CUL))
#define SOC_PCTRL_R2_PERI_CTRL40_WC_ADDR(base) ((base) + (0x1920UL))
#define SOC_PCTRL_R2_PERI_CTRL41_WC_ADDR(base) ((base) + (0x1924UL))
#define SOC_PCTRL_R2_PERI_CTRL42_WC_ADDR(base) ((base) + (0x1928UL))
#define SOC_PCTRL_R2_PERI_CTRL43_WC_ADDR(base) ((base) + (0x192CUL))
#define SOC_PCTRL_R2_PERI_CTRL44_WC_ADDR(base) ((base) + (0x1930UL))
#define SOC_PCTRL_R2_PERI_CTRL45_WC_ADDR(base) ((base) + (0x1934UL))
#define SOC_PCTRL_R2_PERI_CTRL46_WC_ADDR(base) ((base) + (0x1938UL))
#define SOC_PCTRL_R2_PERI_CTRL47_WC_ADDR(base) ((base) + (0x193CUL))
#define SOC_PCTRL_R2_PERI_CTRL48_WC_ADDR(base) ((base) + (0x1940UL))
#define SOC_PCTRL_R2_PERI_CTRL49_WC_ADDR(base) ((base) + (0x1944UL))
#define SOC_PCTRL_R2_PERI_CTRL50_WC_ADDR(base) ((base) + (0x1948UL))
#define SOC_PCTRL_R2_PERI_CTRL51_WC_ADDR(base) ((base) + (0x194CUL))
#define SOC_PCTRL_R2_PERI_CTRL52_WC_ADDR(base) ((base) + (0x1950UL))
#define SOC_PCTRL_R2_PERI_CTRL53_WC_ADDR(base) ((base) + (0x1954UL))
#define SOC_PCTRL_R2_PERI_CTRL54_WC_ADDR(base) ((base) + (0x1958UL))
#define SOC_PCTRL_R2_PERI_CTRL55_WC_ADDR(base) ((base) + (0x195CUL))
#define SOC_PCTRL_R2_PERI_CTRL56_WC_ADDR(base) ((base) + (0x1960UL))
#define SOC_PCTRL_R2_PERI_CTRL57_WC_ADDR(base) ((base) + (0x1964UL))
#define SOC_PCTRL_R2_PERI_CTRL58_WC_ADDR(base) ((base) + (0x1968UL))
#define SOC_PCTRL_R2_PERI_CTRL59_WC_ADDR(base) ((base) + (0x196CUL))
#define SOC_PCTRL_PERI_CTRL_195_NS_ADDR(base) ((base) + (0x1970UL))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_LOW_ADDR(base) ((base) + (0x1974UL))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_HIGH_ADDR(base) ((base) + (0x1978UL))
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_ADDR(base) ((base) + (0x197CUL))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_LOW_ADDR(base) ((base) + (0x1980UL))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_HIGH_ADDR(base) ((base) + (0x1984UL))
#define SOC_PCTRL_PERI_CTRL5_ADDR(base) ((base) + (0x1C00UL))
#define SOC_PCTRL_PERI_CTRL6_ADDR(base) ((base) + (0x1C04UL))
#define SOC_PCTRL_PERI_CTRL7_ADDR(base) ((base) + (0x1C08UL))
#define SOC_PCTRL_PERI_CTRL8_ADDR(base) ((base) + (0x1C0CUL))
#define SOC_PCTRL_PERI_CTRL9_ADDR(base) ((base) + (0x1C10UL))
#define SOC_PCTRL_PERI_CTRL10_ADDR(base) ((base) + (0x1C14UL))
#define SOC_PCTRL_PERI_CTRL11_ADDR(base) ((base) + (0x1C18UL))
#define SOC_PCTRL_PERI_CTRL34_ADDR(base) ((base) + (0x1C1CUL))
#define SOC_PCTRL_PERI_CTRL35_ADDR(base) ((base) + (0x1C20UL))
#define SOC_PCTRL_PERI_CTRL38_ADDR(base) ((base) + (0x1C2CUL))
#define SOC_PCTRL_PERI_CTRL39_ADDR(base) ((base) + (0x1C30UL))
#define SOC_PCTRL_PERI_CTRL40_ADDR(base) ((base) + (0x1C34UL))
#define SOC_PCTRL_PERI_CTRL41_ADDR(base) ((base) + (0x1C38UL))
#define SOC_PCTRL_PERI_CTRL42_ADDR(base) ((base) + (0x1C3CUL))
#define SOC_PCTRL_PERI_CTRL43_ADDR(base) ((base) + (0x1C40UL))
#define SOC_PCTRL_PERI_CTRL44_ADDR(base) ((base) + (0x1C44UL))
#define SOC_PCTRL_PERI_CTRL45_ADDR(base) ((base) + (0x1C48UL))
#define SOC_PCTRL_PERI_CTRL46_ADDR(base) ((base) + (0x1C4CUL))
#define SOC_PCTRL_PERI_CTRL47_ADDR(base) ((base) + (0x1C50UL))
#define SOC_PCTRL_PERI_CTRL48_ADDR(base) ((base) + (0x1C54UL))
#define SOC_PCTRL_PERI_CTRL49_ADDR(base) ((base) + (0x1C58UL))
#define SOC_PCTRL_PERI_CTRL50_ADDR(base) ((base) + (0x1C5CUL))
#define SOC_PCTRL_PERI_CTRL51_ADDR(base) ((base) + (0x1C60UL))
#define SOC_PCTRL_PERI_CTRL52_ADDR(base) ((base) + (0x1C64UL))
#define SOC_PCTRL_PERI_CTRL53_ADDR(base) ((base) + (0x1C68UL))
#define SOC_PCTRL_PERI_CTRL54_ADDR(base) ((base) + (0x1C6CUL))
#define SOC_PCTRL_PERI_CTRL55_ADDR(base) ((base) + (0x1C70UL))
#define SOC_PCTRL_PERI_CTRL56_ADDR(base) ((base) + (0x1C74UL))
#define SOC_PCTRL_PERI_CTRL57_ADDR(base) ((base) + (0x1C78UL))
#define SOC_PCTRL_PERI_CTRL58_ADDR(base) ((base) + (0x1C7CUL))
#define SOC_PCTRL_PERI_CTRL59_ADDR(base) ((base) + (0x1C80UL))
#define SOC_PCTRL_PERI_CTRL60_ADDR(base) ((base) + (0x1C84UL))
#define SOC_PCTRL_PERI_CTRL61_ADDR(base) ((base) + (0x1C88UL))
#define SOC_PCTRL_PERI_CTRL62_ADDR(base) ((base) + (0x1C8CUL))
#define SOC_PCTRL_PERI_CTRL63_ADDR(base) ((base) + (0x1C90UL))
#define SOC_PCTRL_PERI_CTRL64_ADDR(base) ((base) + (0x1C94UL))
#define SOC_PCTRL_PERI_CTRL65_ADDR(base) ((base) + (0x1C98UL))
#define SOC_PCTRL_PERI_CTRL66_ADDR(base) ((base) + (0x1C9CUL))
#define SOC_PCTRL_PERI_CTRL75_ADDR(base) ((base) + (0x1CA0UL))
#define SOC_PCTRL_PERI_CTRL76_ADDR(base) ((base) + (0x1CA4UL))
#define SOC_PCTRL_PERI_CTRL77_ADDR(base) ((base) + (0x1CA8UL))
#define SOC_PCTRL_PERI_CTRL78_ADDR(base) ((base) + (0x1CACUL))
#define SOC_PCTRL_PERI_CTRL79_ADDR(base) ((base) + (0x1CB0UL))
#define SOC_PCTRL_PERI_CTRL80_ADDR(base) ((base) + (0x1CB4UL))
#define SOC_PCTRL_PERI_CTRL81_ADDR(base) ((base) + (0x1CB8UL))
#define SOC_PCTRL_PERI_CTRL82_ADDR(base) ((base) + (0x1CBCUL))
#define SOC_PCTRL_PERI_CTRL83_ADDR(base) ((base) + (0x1CC0UL))
#define SOC_PCTRL_PERI_CTRL84_ADDR(base) ((base) + (0x1CC4UL))
#define SOC_PCTRL_PERI_CTRL85_ADDR(base) ((base) + (0x1CC8UL))
#define SOC_PCTRL_PERI_CTRL86_ADDR(base) ((base) + (0x1CCCUL))
#define SOC_PCTRL_PERI_CTRL87_ADDR(base) ((base) + (0x1CD0UL))
#define SOC_PCTRL_PERI_STAT160_ADDR(base) ((base) + (0x1CD4UL))
#define SOC_PCTRL_PERI_CTRL168_ADDR(base) ((base) + (0x1CD8UL))
#define SOC_PCTRL_PERI_CTRL169_ADDR(base) ((base) + (0x1CDCUL))
#define SOC_PCTRL_PERI_CTRL170_ADDR(base) ((base) + (0x1CE0UL))
#define SOC_PCTRL_PERI_CTRL171_ADDR(base) ((base) + (0x1CE4UL))
#define SOC_PCTRL_PERI_CTRL172_ADDR(base) ((base) + (0x1CE8UL))
#define SOC_PCTRL_PERI_CTRL173_ADDR(base) ((base) + (0x1CECUL))
#define SOC_PCTRL_PERI_CTRL174_ADDR(base) ((base) + (0x1CF0UL))
#define SOC_PCTRL_PERI_CTRL175_ADDR(base) ((base) + (0x1CF8UL))
#define SOC_PCTRL_PERI_CTRL176_ADDR(base) ((base) + (0x1CFCUL))
#define SOC_PCTRL_PERI_CTRL177_ADDR(base) ((base) + (0x1D00UL))
#define SOC_PCTRL_PERI_CTRL178_ADDR(base) ((base) + (0x1D04UL))
#define SOC_PCTRL_PERI_CTRL179_ADDR(base) ((base) + (0x1D08UL))
#define SOC_PCTRL_PERI_CTRL180_ADDR(base) ((base) + (0x1D0CUL))
#define SOC_PCTRL_PERI_CTRL181_ADDR(base) ((base) + (0x1D10UL))
#define SOC_PCTRL_PERI_CTRL182_ADDR(base) ((base) + (0x1D14UL))
#define SOC_PCTRL_PERI_CTRL183_ADDR(base) ((base) + (0x1D18UL))
#define SOC_PCTRL_PERI_CTRL184_ADDR(base) ((base) + (0x1D1CUL))
#define SOC_PCTRL_PERI_CTRL185_ADDR(base) ((base) + (0x1D20UL))
#define SOC_PCTRL_PERI_CTRL186_ADDR(base) ((base) + (0x1D24UL))
#define SOC_PCTRL_PERI_CTRL187_ADDR(base) ((base) + (0x1D28UL))
#define SOC_PCTRL_PERI_CTRL188_ADDR(base) ((base) + (0x1D2CUL))
#define SOC_PCTRL_PERI_CTRL189_ADDR(base) ((base) + (0x1D30UL))
#define SOC_PCTRL_PERI_CTRL190_ADDR(base) ((base) + (0x1D34UL))
#define SOC_PCTRL_PERI_CTRL191_ADDR(base) ((base) + (0x1D38UL))
#define SOC_PCTRL_PERI_CTRL192_ADDR(base) ((base) + (0x1D3CUL))
#define SOC_PCTRL_PERI_CTRL193_ADDR(base) ((base) + (0x1D40UL))
#define SOC_PCTRL_PERI_CTRL194_ADDR(base) ((base) + (0x1D44UL))
#define SOC_PCTRL_PERI_CTRL195_ADDR(base) ((base) + (0x1D48UL))
#define SOC_PCTRL_PERI_CTRL196_ADDR(base) ((base) + (0x1D4CUL))
#define SOC_PCTRL_PERI_CTRL197_ADDR(base) ((base) + (0x1D50UL))
#define SOC_PCTRL_PERI_CTRL198_ADDR(base) ((base) + (0x1D54UL))
#define SOC_PCTRL_PERI_CTRL199_ADDR(base) ((base) + (0x1D58UL))
#define SOC_PCTRL_PERI_CTRL200_ADDR(base) ((base) + (0x1D5CUL))
#define SOC_PCTRL_PERI_CTRL201_ADDR(base) ((base) + (0x1D60UL))
#define SOC_PCTRL_PERI_CTRL202_ADDR(base) ((base) + (0x1D64UL))
#define SOC_PCTRL_PERI_CTRL203_ADDR(base) ((base) + (0x1D68UL))
#define SOC_PCTRL_PERI_CTRL204_ADDR(base) ((base) + (0x1D6CUL))
#define SOC_PCTRL_PERI_CTRL205_ADDR(base) ((base) + (0x1D70UL))
#define SOC_PCTRL_PERI_CTRL206_ADDR(base) ((base) + (0x1D74UL))
#define SOC_PCTRL_PERI_CTRL207_ADDR(base) ((base) + (0x1D78UL))
#define SOC_PCTRL_PERI_CTRL208_ADDR(base) ((base) + (0x1D7CUL))
#define SOC_PCTRL_PERI_CTRL209_ADDR(base) ((base) + (0x1D80UL))
#define SOC_PCTRL_PERI_CTRL210_ADDR(base) ((base) + (0x1D84UL))
#define SOC_PCTRL_PERI_CTRL211_ADDR(base) ((base) + (0x1D88UL))
#define SOC_PCTRL_PERI_CTRL212_ADDR(base) ((base) + (0x1D8CUL))
#define SOC_PCTRL_PERI_CTRL213_ADDR(base) ((base) + (0x1D90UL))
#define SOC_PCTRL_PERI_CTRL214_ADDR(base) ((base) + (0x1D94UL))
#define SOC_PCTRL_PERI_CTRL215_ADDR(base) ((base) + (0x1D98UL))
#define SOC_PCTRL_PERI_CTRL216_ADDR(base) ((base) + (0x1D9CUL))
#define SOC_PCTRL_PERI_CTRL217_ADDR(base) ((base) + (0x1DA0UL))
#define SOC_PCTRL_PERI_CTRL218_ADDR(base) ((base) + (0x1DA4UL))
#define SOC_PCTRL_PERI_CTRL219_ADDR(base) ((base) + (0x1DA8UL))
#define SOC_PCTRL_PERI_CTRL220_ADDR(base) ((base) + (0x1DACUL))
#define SOC_PCTRL_PERI_CTRL221_ADDR(base) ((base) + (0x1DB0UL))
#define SOC_PCTRL_PERI_CTRL222_ADDR(base) ((base) + (0x1DB4UL))
#define SOC_PCTRL_PERI_CTRL223_ADDR(base) ((base) + (0x1DB8UL))
#define SOC_PCTRL_PERI_CTRL224_ADDR(base) ((base) + (0x1DBCUL))
#define SOC_PCTRL_PERI_CTRL225_ADDR(base) ((base) + (0x1DC0UL))
#define SOC_PCTRL_PERI_CTRL226_ADDR(base) ((base) + (0x1DC4UL))
#define SOC_PCTRL_PERI_CTRL227_ADDR(base) ((base) + (0x1DC8UL))
#define SOC_PCTRL_PERI_CTRL228_ADDR(base) ((base) + (0x1DCCUL))
#define SOC_PCTRL_PERI_CTRL229_ADDR(base) ((base) + (0x1DD0UL))
#define SOC_PCTRL_PERI_CTRL230_ADDR(base) ((base) + (0x1DD4UL))
#define SOC_PCTRL_PERI_CTRL231_ADDR(base) ((base) + (0x1DD8UL))
#define SOC_PCTRL_PERI_CTRL232_ADDR(base) ((base) + (0x1DDCUL))
#define SOC_PCTRL_PERI_CTRL233_ADDR(base) ((base) + (0x1DE0UL))
#define SOC_PCTRL_PERI_CTRL234_ADDR(base) ((base) + (0x1DE4UL))
#define SOC_PCTRL_PERI_CTRL235_ADDR(base) ((base) + (0x1DE8UL))
#define SOC_PCTRL_PERI_CTRL236_ADDR(base) ((base) + (0x1DECUL))
#define SOC_PCTRL_PERI_CTRL237_ADDR(base) ((base) + (0x1DF0UL))
#define SOC_PCTRL_PERI_CTRL238_ADDR(base) ((base) + (0x1DF4UL))
#define SOC_PCTRL_PERI_CTRL239_ADDR(base) ((base) + (0x1DF8UL))
#define SOC_PCTRL_PERI_CTRL240_ADDR(base) ((base) + (0x1DFCUL))
#define SOC_PCTRL_PERI_CTRL241_ADDR(base) ((base) + (0x1E00UL))
#define SOC_PCTRL_PERI_CTRL242_ADDR(base) ((base) + (0x1E04UL))
#define SOC_PCTRL_PERI_CTRL243_ADDR(base) ((base) + (0x1E08UL))
#define SOC_PCTRL_PERI_CTRL244_ADDR(base) ((base) + (0x1E0CUL))
#define SOC_PCTRL_PERI_CTRL245_ADDR(base) ((base) + (0x1E10UL))
#define SOC_PCTRL_PERI_CTRL246_ADDR(base) ((base) + (0x1E14UL))
#define SOC_PCTRL_PERI_CTRL247_ADDR(base) ((base) + (0x1E18UL))
#define SOC_PCTRL_PERI_CTRL248_ADDR(base) ((base) + (0x1E1CUL))
#define SOC_PCTRL_PERI_CTRL249_ADDR(base) ((base) + (0x1E20UL))
#define SOC_PCTRL_PERI_STAT_SEC0_ADDR(base) ((base) + (0x1E24UL))
#else
#define SOC_PCTRL_G3D_RASTER_ADDR(base) ((base) + (0x0000))
#define SOC_PCTRL_USB2_HOST_CTRL0_ADDR(base) ((base) + (0x0004))
#define SOC_PCTRL_USB2_HOST_CTRL1_ADDR(base) ((base) + (0x0008))
#define SOC_PCTRL_USB2_HOST_CTRL2_ADDR(base) ((base) + (0x000C))
#define SOC_PCTRL_PERI_CTRL4_ADDR(base) ((base) + (0x0010))
#define SOC_PCTRL_PERI_CTRL98_ADDR(base) ((base) + (0x0014))
#define SOC_PCTRL_PERI_CTRL99_ADDR(base) ((base) + (0x0018))
#define SOC_PCTRL_PERI_CTRL100_ADDR(base) ((base) + (0x001C))
#define SOC_PCTRL_PERI_CTRL101_ADDR(base) ((base) + (0x0020))
#define SOC_PCTRL_PERI_CTRL104_ADDR(base) ((base) + (0x0024))
#define SOC_PCTRL_PERI_CTRL12_ADDR(base) ((base) + (0x0028))
#define SOC_PCTRL_PERI_CTRL13_ADDR(base) ((base) + (0x002C))
#define SOC_PCTRL_PERI_CTRL14_ADDR(base) ((base) + (0x0030))
#define SOC_PCTRL_PERI_CTRL15_ADDR(base) ((base) + (0x0034))
#define SOC_PCTRL_PERI_CTRL16_ADDR(base) ((base) + (0x0038))
#define SOC_PCTRL_PERI_CTRL17_ADDR(base) ((base) + (0x003C))
#define SOC_PCTRL_PERI_CTRL18_ADDR(base) ((base) + (0x0040))
#define SOC_PCTRL_PERI_CTRL19_ADDR(base) ((base) + (0x0044))
#define SOC_PCTRL_PERI_CTRL20_ADDR(base) ((base) + (0x0048))
#define SOC_PCTRL_PERI_CTRL21_ADDR(base) ((base) + (0x004C))
#define SOC_PCTRL_PERI_CTRL22_ADDR(base) ((base) + (0x0050))
#define SOC_PCTRL_PERI_CTRL23_ADDR(base) ((base) + (0x0054))
#define SOC_PCTRL_PERI_CTRL24_ADDR(base) ((base) + (0x0058))
#define SOC_PCTRL_PERI_CTRL25_ADDR(base) ((base) + (0x005C))
#define SOC_PCTRL_PERI_CTRL26_ADDR(base) ((base) + (0x0060))
#define SOC_PCTRL_PERI_CTRL27_ADDR(base) ((base) + (0x0064))
#define SOC_PCTRL_PERI_CTRL28_ADDR(base) ((base) + (0x0068))
#define SOC_PCTRL_PERI_CTRL29_ADDR(base) ((base) + (0x006C))
#define SOC_PCTRL_PERI_CTRL30_ADDR(base) ((base) + (0x0070))
#define SOC_PCTRL_PERI_CTRL31_ADDR(base) ((base) + (0x0074))
#define SOC_PCTRL_PERI_CTRL32_ADDR(base) ((base) + (0x0078))
#define SOC_PCTRL_PERI_CTRL33_ADDR(base) ((base) + (0x007C))
#define SOC_PCTRL_PERI_CTRL67_ADDR(base) ((base) + (0x0080))
#define SOC_PCTRL_PERI_CTRL68_ADDR(base) ((base) + (0x0084))
#define SOC_PCTRL_PERI_CTRL69_ADDR(base) ((base) + (0x0088))
#define SOC_PCTRL_PERI_CTRL70_ADDR(base) ((base) + (0x008C))
#define SOC_PCTRL_PERI_CTRL71_ADDR(base) ((base) + (0x0090))
#define SOC_PCTRL_PERI_CTRL72_ADDR(base) ((base) + (0x0094))
#define SOC_PCTRL_PERI_CTRL73_ADDR(base) ((base) + (0x0098))
#define SOC_PCTRL_PERI_CTRL74_ADDR(base) ((base) + (0x009C))
#define SOC_PCTRL_PERI_CTRL88_ADDR(base) ((base) + (0x00A0))
#define SOC_PCTRL_PERI_CTRL89_ADDR(base) ((base) + (0x00A4))
#define SOC_PCTRL_PERI_CTRL90_ADDR(base) ((base) + (0x00A8))
#define SOC_PCTRL_PERI_CTRL91_ADDR(base) ((base) + (0x00AC))
#define SOC_PCTRL_PERI_CTRL92_ADDR(base) ((base) + (0x00B0))
#define SOC_PCTRL_PERI_CTRL93_ADDR(base) ((base) + (0x00B4))
#define SOC_PCTRL_PERI_CTRL95_ADDR(base) ((base) + (0x00B8))
#define SOC_PCTRL_PERI_CTRL96_ADDR(base) ((base) + (0x00BC))
#define SOC_PCTRL_PERI_CTRL97_ADDR(base) ((base) + (0x00C0))
#define SOC_PCTRL_PERI_CTRL108_ADDR(base) ((base) + (0x00C4))
#define SOC_PCTRL_PERI_CTRL109_ADDR(base) ((base) + (0x00C8))
#define SOC_PCTRL_PERI_CTRL110_ADDR(base) ((base) + (0x00CC))
#define SOC_PCTRL_PERI_CTRL111_ADDR(base) ((base) + (0x00D0))
#define SOC_PCTRL_PERI_CTRL112_ADDR(base) ((base) + (0x00D4))
#define SOC_PCTRL_PERI_CTRL113_ADDR(base) ((base) + (0x00D8))
#define SOC_PCTRL_PERI_CTRL114_ADDR(base) ((base) + (0x00DC))
#define SOC_PCTRL_PERI_CTRL115_ADDR(base) ((base) + (0x00E0))
#define SOC_PCTRL_PERI_CTRL116_ADDR(base) ((base) + (0x00E4))
#define SOC_PCTRL_PERI_CTRL117_ADDR(base) ((base) + (0x00E8))
#define SOC_PCTRL_PERI_CTRL118_ADDR(base) ((base) + (0x00EC))
#define SOC_PCTRL_PERI_CTRL119_ADDR(base) ((base) + (0x00F0))
#define SOC_PCTRL_PERI_CTRL120_ADDR(base) ((base) + (0x00F4))
#define SOC_PCTRL_PERI_CTRL121_ADDR(base) ((base) + (0x00F8))
#define SOC_PCTRL_PERI_CTRL122_ADDR(base) ((base) + (0x00FC))
#define SOC_PCTRL_PERI_CTRL123_ADDR(base) ((base) + (0x0100))
#define SOC_PCTRL_PERI_CTRL124_ADDR(base) ((base) + (0x0104))
#define SOC_PCTRL_PERI_CTRL125_ADDR(base) ((base) + (0x0108))
#define SOC_PCTRL_PERI_CTRL126_ADDR(base) ((base) + (0x010C))
#define SOC_PCTRL_PERI_CTRL127_ADDR(base) ((base) + (0x0110))
#define SOC_PCTRL_PERI_CTRL128_ADDR(base) ((base) + (0x0114))
#define SOC_PCTRL_PERI_CTRL129_ADDR(base) ((base) + (0x0118))
#define SOC_PCTRL_PERI_CTRL130_ADDR(base) ((base) + (0x011C))
#define SOC_PCTRL_PERI_CTRL131_ADDR(base) ((base) + (0x0120))
#define SOC_PCTRL_PERI_CTRL132_ADDR(base) ((base) + (0x0124))
#define SOC_PCTRL_PERI_CTRL133_ADDR(base) ((base) + (0x0128))
#define SOC_PCTRL_PERI_CTRL134_ADDR(base) ((base) + (0x012C))
#define SOC_PCTRL_PERI_CTRL135_ADDR(base) ((base) + (0x0130))
#define SOC_PCTRL_PERI_CTRL136_ADDR(base) ((base) + (0x0134))
#define SOC_PCTRL_MDM_TSP_NMI0_ADDR(base) ((base) + (0x0138))
#define SOC_PCTRL_PERI_CTRL138_ADDR(base) ((base) + (0x013C))
#define SOC_PCTRL_PERI_CTRL139_ADDR(base) ((base) + (0x0140))
#define SOC_PCTRL_PERI_CTRL140_ADDR(base) ((base) + (0x0144))
#define SOC_PCTRL_PERI_CTRL141_ADDR(base) ((base) + (0x0148))
#define SOC_PCTRL_PERI_CTRL142_ADDR(base) ((base) + (0x014C))
#define SOC_PCTRL_PERI_CTRL143_ADDR(base) ((base) + (0x0150))
#define SOC_PCTRL_PERI_CTRL144_ADDR(base) ((base) + (0x0154))
#define SOC_PCTRL_PERI_CTRL145_ADDR(base) ((base) + (0x0158))
#define SOC_PCTRL_PERI_CTRL146_ADDR(base) ((base) + (0x015C))
#define SOC_PCTRL_PERI_CTRL147_ADDR(base) ((base) + (0x0160))
#define SOC_PCTRL_PERI_CTRL148_ADDR(base) ((base) + (0x0164))
#define SOC_PCTRL_PERI_CTRL149_ADDR(base) ((base) + (0x0168))
#define SOC_PCTRL_PERI_CTRL150_ADDR(base) ((base) + (0x016C))
#define SOC_PCTRL_PERI_CTRL151_ADDR(base) ((base) + (0x0170))
#define SOC_PCTRL_PERI_CTRL152_ADDR(base) ((base) + (0x0174))
#define SOC_PCTRL_PERI_CTRL153_ADDR(base) ((base) + (0x0178))
#define SOC_PCTRL_PERI_CTRL154_ADDR(base) ((base) + (0x017C))
#define SOC_PCTRL_PERI_CTRL155_ADDR(base) ((base) + (0x0180))
#define SOC_PCTRL_PERI_CTRL156_ADDR(base) ((base) + (0x0184))
#define SOC_PCTRL_PERI_CTRL157_ADDR(base) ((base) + (0x0188))
#define SOC_PCTRL_PERI_CTRL158_ADDR(base) ((base) + (0x018C))
#define SOC_PCTRL_PERI_CTRL159_ADDR(base) ((base) + (0x0190))
#define SOC_PCTRL_PERI_CTRL160_ADDR(base) ((base) + (0x0194))
#define SOC_PCTRL_PERI_CTRL161_ADDR(base) ((base) + (0x0198))
#define SOC_PCTRL_PERI_CTRL162_ADDR(base) ((base) + (0x019C))
#define SOC_PCTRL_PERI_CTRL163_ADDR(base) ((base) + (0x01A0))
#define SOC_PCTRL_PERI_CTRL164_ADDR(base) ((base) + (0x01A4))
#define SOC_PCTRL_PERI_CTRL165_ADDR(base) ((base) + (0x01A8))
#define SOC_PCTRL_PERI_CTRL166_ADDR(base) ((base) + (0x01AC))
#define SOC_PCTRL_PERI_CTRL167_ADDR(base) ((base) + (0x01B0))
#define SOC_PCTRL_PERI_STAT0_ADDR(base) ((base) + (0x1000))
#define SOC_PCTRL_PERI_STAT1_ADDR(base) ((base) + (0x1004))
#define SOC_PCTRL_PERI_STAT2_ADDR(base) ((base) + (0x1008))
#define SOC_PCTRL_PERI_STAT3_ADDR(base) ((base) + (0x100C))
#define SOC_PCTRL_PERI_STAT4_ADDR(base) ((base) + (0x1010))
#define SOC_PCTRL_PERI_STAT5_ADDR(base) ((base) + (0x1014))
#define SOC_PCTRL_PERI_STAT6_ADDR(base) ((base) + (0x1018))
#define SOC_PCTRL_PERI_STAT7_ADDR(base) ((base) + (0x101C))
#define SOC_PCTRL_PERI_STAT8_ADDR(base) ((base) + (0x1020))
#define SOC_PCTRL_PERI_STAT9_ADDR(base) ((base) + (0x1024))
#define SOC_PCTRL_PERI_STAT10_ADDR(base) ((base) + (0x1028))
#define SOC_PCTRL_PERI_STAT11_ADDR(base) ((base) + (0x102C))
#define SOC_PCTRL_PERI_STAT12_ADDR(base) ((base) + (0x1030))
#define SOC_PCTRL_PERI_STAT13_ADDR(base) ((base) + (0x1034))
#define SOC_PCTRL_PERI_STAT14_ADDR(base) ((base) + (0x1038))
#define SOC_PCTRL_PERI_STAT15_ADDR(base) ((base) + (0x103C))
#define SOC_PCTRL_PERI_STAT16_ADDR(base) ((base) + (0x1040))
#define SOC_PCTRL_PERI_STAT17_ADDR(base) ((base) + (0x1044))
#define SOC_PCTRL_PERI_STAT18_ADDR(base) ((base) + (0x1048))
#define SOC_PCTRL_PERI_STAT19_ADDR(base) ((base) + (0x104C))
#define SOC_PCTRL_PERI_STAT29_ADDR(base) ((base) + (0x1050))
#define SOC_PCTRL_PERI_STAT30_ADDR(base) ((base) + (0x1054))
#define SOC_PCTRL_PERI_STAT31_ADDR(base) ((base) + (0x1058))
#define SOC_PCTRL_PERI_STAT32_ADDR(base) ((base) + (0x105C))
#define SOC_PCTRL_PERI_STAT33_ADDR(base) ((base) + (0x1060))
#define SOC_PCTRL_PERI_STAT34_ADDR(base) ((base) + (0x1064))
#define SOC_PCTRL_PERI_STAT35_ADDR(base) ((base) + (0x1068))
#define SOC_PCTRL_PERI_STAT36_ADDR(base) ((base) + (0x106C))
#define SOC_PCTRL_PERI_STAT37_ADDR(base) ((base) + (0x1070))
#define SOC_PCTRL_PERI_STAT38_ADDR(base) ((base) + (0x1074))
#define SOC_PCTRL_PERI_STAT39_ADDR(base) ((base) + (0x1078))
#define SOC_PCTRL_PERI_STAT40_ADDR(base) ((base) + (0x107C))
#define SOC_PCTRL_PERI_STAT41_ADDR(base) ((base) + (0x1080))
#define SOC_PCTRL_PERI_STAT42_ADDR(base) ((base) + (0x1084))
#define SOC_PCTRL_PERI_STAT43_ADDR(base) ((base) + (0x1088))
#define SOC_PCTRL_PERI_STAT44_ADDR(base) ((base) + (0x108C))
#define SOC_PCTRL_PERI_STAT45_ADDR(base) ((base) + (0x1090))
#define SOC_PCTRL_PERI_STAT46_ADDR(base) ((base) + (0x1094))
#define SOC_PCTRL_PERI_STAT47_ADDR(base) ((base) + (0x1098))
#define SOC_PCTRL_PERI_STAT48_ADDR(base) ((base) + (0x109C))
#define SOC_PCTRL_PERI_STAT49_ADDR(base) ((base) + (0x10A0))
#define SOC_PCTRL_PERI_STAT50_ADDR(base) ((base) + (0x10A4))
#define SOC_PCTRL_PERI_STAT51_ADDR(base) ((base) + (0x10A8))
#define SOC_PCTRL_PERI_STAT52_ADDR(base) ((base) + (0x10AC))
#define SOC_PCTRL_PERI_STAT53_ADDR(base) ((base) + (0x10B0))
#define SOC_PCTRL_PERI_STAT54_ADDR(base) ((base) + (0x10B4))
#define SOC_PCTRL_PERI_STAT55_ADDR(base) ((base) + (0x10B8))
#define SOC_PCTRL_PERI_STAT56_ADDR(base) ((base) + (0x10BC))
#define SOC_PCTRL_PERI_STAT57_ADDR(base) ((base) + (0x10C0))
#define SOC_PCTRL_PERI_STAT58_ADDR(base) ((base) + (0x10C4))
#define SOC_PCTRL_PERI_STAT59_ADDR(base) ((base) + (0x10C8))
#define SOC_PCTRL_PERI_STAT60_ADDR(base) ((base) + (0x10CC))
#define SOC_PCTRL_PERI_STAT61_ADDR(base) ((base) + (0x10D0))
#define SOC_PCTRL_PERI_STAT62_ADDR(base) ((base) + (0x10D4))
#define SOC_PCTRL_PERI_STAT63_ADDR(base) ((base) + (0x10D8))
#define SOC_PCTRL_PERI_STAT64_ADDR(base) ((base) + (0x10DC))
#define SOC_PCTRL_PERI_STAT66_ADDR(base) ((base) + (0x10E0))
#define SOC_PCTRL_PERI_STAT67_ADDR(base) ((base) + (0x10E4))
#define SOC_PCTRL_PERI_STAT68_ADDR(base) ((base) + (0x10E8))
#define SOC_PCTRL_PERI_STAT69_ADDR(base) ((base) + (0x10EC))
#define SOC_PCTRL_PERI_STAT70_ADDR(base) ((base) + (0x10F0))
#define SOC_PCTRL_PERI_STAT71_ADDR(base) ((base) + (0x10F4))
#define SOC_PCTRL_PERI_STAT72_ADDR(base) ((base) + (0x10F8))
#define SOC_PCTRL_PERI_STAT73_ADDR(base) ((base) + (0x10FC))
#define SOC_PCTRL_PERI_STAT74_ADDR(base) ((base) + (0x1100))
#define SOC_PCTRL_PERI_STAT75_ADDR(base) ((base) + (0x1104))
#define SOC_PCTRL_PERI_STAT76_ADDR(base) ((base) + (0x1108))
#define SOC_PCTRL_PERI_STAT77_ADDR(base) ((base) + (0x110C))
#define SOC_PCTRL_PERI_STAT78_ADDR(base) ((base) + (0x1110))
#define SOC_PCTRL_PERI_STAT79_ADDR(base) ((base) + (0x1114))
#define SOC_PCTRL_PERI_STAT80_ADDR(base) ((base) + (0x1118))
#define SOC_PCTRL_PERI_STAT81_ADDR(base) ((base) + (0x111C))
#define SOC_PCTRL_PERI_STAT82_ADDR(base) ((base) + (0x1120))
#define SOC_PCTRL_PERI_STAT83_ADDR(base) ((base) + (0x1124))
#define SOC_PCTRL_PERI_STAT84_ADDR(base) ((base) + (0x1128))
#define SOC_PCTRL_PERI_STAT85_ADDR(base) ((base) + (0x112C))
#define SOC_PCTRL_PERI_STAT86_ADDR(base) ((base) + (0x1130))
#define SOC_PCTRL_PERI_STAT87_ADDR(base) ((base) + (0x1134))
#define SOC_PCTRL_PERI_STAT88_ADDR(base) ((base) + (0x1138))
#define SOC_PCTRL_PERI_STAT89_ADDR(base) ((base) + (0x113C))
#define SOC_PCTRL_PERI_STAT90_ADDR(base) ((base) + (0x1140))
#define SOC_PCTRL_PERI_STAT91_ADDR(base) ((base) + (0x1144))
#define SOC_PCTRL_PERI_STAT92_ADDR(base) ((base) + (0x1148))
#define SOC_PCTRL_PERI_STAT93_ADDR(base) ((base) + (0x114C))
#define SOC_PCTRL_PERI_STAT94_ADDR(base) ((base) + (0x1150))
#define SOC_PCTRL_PERI_STAT95_ADDR(base) ((base) + (0x1154))
#define SOC_PCTRL_PERI_STAT96_ADDR(base) ((base) + (0x1158))
#define SOC_PCTRL_PERI_STAT97_ADDR(base) ((base) + (0x115C))
#define SOC_PCTRL_PERI_STAT98_ADDR(base) ((base) + (0x1160))
#define SOC_PCTRL_PERI_STAT99_ADDR(base) ((base) + (0x1164))
#define SOC_PCTRL_PERI_STAT100_ADDR(base) ((base) + (0x1168))
#define SOC_PCTRL_PERI_STAT101_ADDR(base) ((base) + (0x116C))
#define SOC_PCTRL_PERI_STAT102_ADDR(base) ((base) + (0x1170))
#define SOC_PCTRL_PERI_STAT103_ADDR(base) ((base) + (0x1174))
#define SOC_PCTRL_PERI_STAT104_ADDR(base) ((base) + (0x1178))
#define SOC_PCTRL_PERI_STAT105_ADDR(base) ((base) + (0x117C))
#define SOC_PCTRL_PERI_STAT106_ADDR(base) ((base) + (0x1180))
#define SOC_PCTRL_PERI_STAT107_ADDR(base) ((base) + (0x1184))
#define SOC_PCTRL_PERI_STAT108_ADDR(base) ((base) + (0x1188))
#define SOC_PCTRL_PERI_STAT109_ADDR(base) ((base) + (0x118C))
#define SOC_PCTRL_PERI_STAT110_ADDR(base) ((base) + (0x1190))
#define SOC_PCTRL_PERI_STAT111_ADDR(base) ((base) + (0x1194))
#define SOC_PCTRL_PERI_STAT112_ADDR(base) ((base) + (0x1198))
#define SOC_PCTRL_PERI_STAT113_ADDR(base) ((base) + (0x119C))
#define SOC_PCTRL_PERI_STAT114_ADDR(base) ((base) + (0x11A0))
#define SOC_PCTRL_PERI_STAT115_ADDR(base) ((base) + (0x11A4))
#define SOC_PCTRL_PERI_STAT116_ADDR(base) ((base) + (0x11A8))
#define SOC_PCTRL_PERI_STAT117_ADDR(base) ((base) + (0x11AC))
#define SOC_PCTRL_PERI_STAT118_ADDR(base) ((base) + (0x11B0))
#define SOC_PCTRL_PERI_STAT119_ADDR(base) ((base) + (0x11B4))
#define SOC_PCTRL_PERI_STAT120_ADDR(base) ((base) + (0x11B8))
#define SOC_PCTRL_PERI_STAT121_ADDR(base) ((base) + (0x11BC))
#define SOC_PCTRL_PERI_STAT122_ADDR(base) ((base) + (0x11C0))
#define SOC_PCTRL_PERI_STAT123_ADDR(base) ((base) + (0x11C4))
#define SOC_PCTRL_PERI_STAT124_ADDR(base) ((base) + (0x11C8))
#define SOC_PCTRL_PERI_STAT125_ADDR(base) ((base) + (0x11CC))
#define SOC_PCTRL_PERI_STAT126_ADDR(base) ((base) + (0x11D0))
#define SOC_PCTRL_PERI_STAT127_ADDR(base) ((base) + (0x11D4))
#define SOC_PCTRL_PERI_STAT128_ADDR(base) ((base) + (0x11D8))
#define SOC_PCTRL_PERI_STAT129_ADDR(base) ((base) + (0x11DC))
#define SOC_PCTRL_PERI_STAT130_ADDR(base) ((base) + (0x11E0))
#define SOC_PCTRL_PERI_STAT131_ADDR(base) ((base) + (0x11E4))
#define SOC_PCTRL_PERI_STAT132_ADDR(base) ((base) + (0x11E8))
#define SOC_PCTRL_PERI_STAT133_ADDR(base) ((base) + (0x11EC))
#define SOC_PCTRL_PERI_STAT134_ADDR(base) ((base) + (0x11F0))
#define SOC_PCTRL_PERI_STAT135_ADDR(base) ((base) + (0x11F4))
#define SOC_PCTRL_PERI_STAT136_ADDR(base) ((base) + (0x11F8))
#define SOC_PCTRL_PERI_STAT137_ADDR(base) ((base) + (0x11FC))
#define SOC_PCTRL_PERI_STAT138_ADDR(base) ((base) + (0x1200))
#define SOC_PCTRL_PERI_STAT139_ADDR(base) ((base) + (0x1204))
#define SOC_PCTRL_PERI_STAT140_ADDR(base) ((base) + (0x1208))
#define SOC_PCTRL_PERI_STAT141_ADDR(base) ((base) + (0x120C))
#define SOC_PCTRL_PERI_STAT142_ADDR(base) ((base) + (0x1210))
#define SOC_PCTRL_PERI_STAT143_ADDR(base) ((base) + (0x1214))
#define SOC_PCTRL_PERI_STAT144_ADDR(base) ((base) + (0x1218))
#define SOC_PCTRL_PERI_STAT145_ADDR(base) ((base) + (0x121C))
#define SOC_PCTRL_PERI_STAT146_ADDR(base) ((base) + (0x1220))
#define SOC_PCTRL_PERI_STAT147_ADDR(base) ((base) + (0x1224))
#define SOC_PCTRL_PERI_STAT148_ADDR(base) ((base) + (0x1228))
#define SOC_PCTRL_PERI_STAT149_ADDR(base) ((base) + (0x122C))
#define SOC_PCTRL_PERI_STAT150_ADDR(base) ((base) + (0x1230))
#define SOC_PCTRL_PERI_STAT151_ADDR(base) ((base) + (0x1234))
#define SOC_PCTRL_PERI_STAT152_ADDR(base) ((base) + (0x1238))
#define SOC_PCTRL_PERI_STAT153_ADDR(base) ((base) + (0x123C))
#define SOC_PCTRL_PERI_STAT154_ADDR(base) ((base) + (0x1240))
#define SOC_PCTRL_PERI_STAT155_ADDR(base) ((base) + (0x1244))
#define SOC_PCTRL_PERI_STAT156_ADDR(base) ((base) + (0x1248))
#define SOC_PCTRL_PERI_STAT157_ADDR(base) ((base) + (0x124C))
#define SOC_PCTRL_PERI_STAT158_ADDR(base) ((base) + (0x1250))
#define SOC_PCTRL_PERI_STAT159_ADDR(base) ((base) + (0x1254))
#define SOC_PCTRL_PERI_CTRL0_ADDR(base) ((base) + (0x1800))
#define SOC_PCTRL_PERI_CTRL1_ADDR(base) ((base) + (0x1804))
#define SOC_PCTRL_PERI_CTRL2_ADDR(base) ((base) + (0x1808))
#define SOC_PCTRL_PERI_CTRL3_ADDR(base) ((base) + (0x181C))
#define SOC_PCTRL_PERI_CTRL102_ADDR(base) ((base) + (0x1820))
#define SOC_PCTRL_PERI_CTRL103_ADDR(base) ((base) + (0x1824))
#define SOC_PCTRL_PERI_CTRL105_ADDR(base) ((base) + (0x1828))
#define SOC_PCTRL_PERI_CTRL106_ADDR(base) ((base) + (0x182C))
#define SOC_PCTRL_PERI_CTRL107_ADDR(base) ((base) + (0x1830))
#define SOC_PCTRL_PERI_CTRL176_WC_ADDR(base) ((base) + (0x1834))
#define SOC_PCTRL_PERI_CTRL177_WC_ADDR(base) ((base) + (0x1838))
#define SOC_PCTRL_PERI_CTRL178_WC_ADDR(base) ((base) + (0x183C))
#define SOC_PCTRL_PERI_CTRL179_WC_ADDR(base) ((base) + (0x1840))
#define SOC_PCTRL_PERI_CTRL180_WC_ADDR(base) ((base) + (0x1844))
#define SOC_PCTRL_PERI_CTRL181_WC_ADDR(base) ((base) + (0x1848))
#define SOC_PCTRL_PERI_CTRL182_WC_ADDR(base) ((base) + (0x184C))
#define SOC_PCTRL_PERI_CTRL183_WC_ADDR(base) ((base) + (0x1850))
#define SOC_PCTRL_PERI_CTRL184_WC_ADDR(base) ((base) + (0x1854))
#define SOC_PCTRL_PERI_CTRL185_WC_ADDR(base) ((base) + (0x1858))
#define SOC_PCTRL_PERI_CTRL186_WC_ADDR(base) ((base) + (0x185C))
#define SOC_PCTRL_PERI_CTRL187_WC_ADDR(base) ((base) + (0x1860))
#define SOC_PCTRL_PERI_CTRL188_WC_ADDR(base) ((base) + (0x1864))
#define SOC_PCTRL_PERI_CTRL189_WC_ADDR(base) ((base) + (0x1868))
#define SOC_PCTRL_PERI_CTRL190_CTRL_ADDR(base) ((base) + (0x186C))
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_ADDR(base) ((base) + (0x1870))
#define SOC_PCTRL_PERI_CTRL192_WC_ADDR(base) ((base) + (0x1874))
#define SOC_PCTRL_PERI_CTRL193_WC_ADDR(base) ((base) + (0x1878))
#define SOC_PCTRL_PERI_CTRL194_WC_ADDR(base) ((base) + (0x187C))
#define SOC_PCTRL_R2_PERI_CTRL0_WC_ADDR(base) ((base) + (0x1880))
#define SOC_PCTRL_R2_PERI_CTRL1_WC_ADDR(base) ((base) + (0x1884))
#define SOC_PCTRL_R2_PERI_CTRL2_WC_ADDR(base) ((base) + (0x1888))
#define SOC_PCTRL_R2_PERI_CTRL3_WC_ADDR(base) ((base) + (0x188C))
#define SOC_PCTRL_R2_PERI_CTRL4_WC_ADDR(base) ((base) + (0x1890))
#define SOC_PCTRL_R2_PERI_CTRL5_WC_ADDR(base) ((base) + (0x1894))
#define SOC_PCTRL_R2_PERI_CTRL6_WC_ADDR(base) ((base) + (0x1898))
#define SOC_PCTRL_R2_PERI_CTRL7_WC_ADDR(base) ((base) + (0x189C))
#define SOC_PCTRL_R2_PERI_CTRL8_WC_ADDR(base) ((base) + (0x18A0))
#define SOC_PCTRL_R2_PERI_CTRL9_WC_ADDR(base) ((base) + (0x18A4))
#define SOC_PCTRL_R2_PERI_CTRL10_WC_ADDR(base) ((base) + (0x18A8))
#define SOC_PCTRL_R2_PERI_CTRL11_WC_ADDR(base) ((base) + (0x18AC))
#define SOC_PCTRL_R2_PERI_CTRL12_WC_ADDR(base) ((base) + (0x18B0))
#define SOC_PCTRL_R2_PERI_CTRL13_WC_ADDR(base) ((base) + (0x18B4))
#define SOC_PCTRL_R2_PERI_CTRL14_WC_ADDR(base) ((base) + (0x18B8))
#define SOC_PCTRL_R2_PERI_CTRL15_WC_ADDR(base) ((base) + (0x18BC))
#define SOC_PCTRL_R2_PERI_CTRL16_WC_ADDR(base) ((base) + (0x18C0))
#define SOC_PCTRL_R2_PERI_CTRL17_WC_ADDR(base) ((base) + (0x18C4))
#define SOC_PCTRL_R2_PERI_CTRL18_WC_ADDR(base) ((base) + (0x18C8))
#define SOC_PCTRL_R2_PERI_CTRL19_WC_ADDR(base) ((base) + (0x18CC))
#define SOC_PCTRL_R2_PERI_CTRL20_WC_ADDR(base) ((base) + (0x18D0))
#define SOC_PCTRL_R2_PERI_CTRL21_WC_ADDR(base) ((base) + (0x18D4))
#define SOC_PCTRL_R2_PERI_CTRL22_WC_ADDR(base) ((base) + (0x18D8))
#define SOC_PCTRL_R2_PERI_CTRL23_WC_ADDR(base) ((base) + (0x18DC))
#define SOC_PCTRL_R2_PERI_CTRL24_WC_ADDR(base) ((base) + (0x18E0))
#define SOC_PCTRL_R2_PERI_CTRL25_WC_ADDR(base) ((base) + (0x18E4))
#define SOC_PCTRL_R2_PERI_CTRL26_WC_ADDR(base) ((base) + (0x18E8))
#define SOC_PCTRL_R2_PERI_CTRL27_WC_ADDR(base) ((base) + (0x18EC))
#define SOC_PCTRL_R2_PERI_CTRL28_WC_ADDR(base) ((base) + (0x18F0))
#define SOC_PCTRL_R2_PERI_CTRL29_WC_ADDR(base) ((base) + (0x18F4))
#define SOC_PCTRL_R2_PERI_CTRL30_WC_ADDR(base) ((base) + (0x18F8))
#define SOC_PCTRL_R2_PERI_CTRL31_WC_ADDR(base) ((base) + (0x18FC))
#define SOC_PCTRL_R2_PERI_CTRL32_WC_ADDR(base) ((base) + (0x1900))
#define SOC_PCTRL_R2_PERI_CTRL33_WC_ADDR(base) ((base) + (0x1904))
#define SOC_PCTRL_R2_PERI_CTRL34_WC_ADDR(base) ((base) + (0x1908))
#define SOC_PCTRL_R2_PERI_CTRL35_WC_ADDR(base) ((base) + (0x190C))
#define SOC_PCTRL_R2_PERI_CTRL36_WC_ADDR(base) ((base) + (0x1910))
#define SOC_PCTRL_R2_PERI_CTRL37_WC_ADDR(base) ((base) + (0x1914))
#define SOC_PCTRL_R2_PERI_CTRL38_WC_ADDR(base) ((base) + (0x1918))
#define SOC_PCTRL_R2_PERI_CTRL39_WC_ADDR(base) ((base) + (0x191C))
#define SOC_PCTRL_R2_PERI_CTRL40_WC_ADDR(base) ((base) + (0x1920))
#define SOC_PCTRL_R2_PERI_CTRL41_WC_ADDR(base) ((base) + (0x1924))
#define SOC_PCTRL_R2_PERI_CTRL42_WC_ADDR(base) ((base) + (0x1928))
#define SOC_PCTRL_R2_PERI_CTRL43_WC_ADDR(base) ((base) + (0x192C))
#define SOC_PCTRL_R2_PERI_CTRL44_WC_ADDR(base) ((base) + (0x1930))
#define SOC_PCTRL_R2_PERI_CTRL45_WC_ADDR(base) ((base) + (0x1934))
#define SOC_PCTRL_R2_PERI_CTRL46_WC_ADDR(base) ((base) + (0x1938))
#define SOC_PCTRL_R2_PERI_CTRL47_WC_ADDR(base) ((base) + (0x193C))
#define SOC_PCTRL_R2_PERI_CTRL48_WC_ADDR(base) ((base) + (0x1940))
#define SOC_PCTRL_R2_PERI_CTRL49_WC_ADDR(base) ((base) + (0x1944))
#define SOC_PCTRL_R2_PERI_CTRL50_WC_ADDR(base) ((base) + (0x1948))
#define SOC_PCTRL_R2_PERI_CTRL51_WC_ADDR(base) ((base) + (0x194C))
#define SOC_PCTRL_R2_PERI_CTRL52_WC_ADDR(base) ((base) + (0x1950))
#define SOC_PCTRL_R2_PERI_CTRL53_WC_ADDR(base) ((base) + (0x1954))
#define SOC_PCTRL_R2_PERI_CTRL54_WC_ADDR(base) ((base) + (0x1958))
#define SOC_PCTRL_R2_PERI_CTRL55_WC_ADDR(base) ((base) + (0x195C))
#define SOC_PCTRL_R2_PERI_CTRL56_WC_ADDR(base) ((base) + (0x1960))
#define SOC_PCTRL_R2_PERI_CTRL57_WC_ADDR(base) ((base) + (0x1964))
#define SOC_PCTRL_R2_PERI_CTRL58_WC_ADDR(base) ((base) + (0x1968))
#define SOC_PCTRL_R2_PERI_CTRL59_WC_ADDR(base) ((base) + (0x196C))
#define SOC_PCTRL_PERI_CTRL_195_NS_ADDR(base) ((base) + (0x1970))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_LOW_ADDR(base) ((base) + (0x1974))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_HIGH_ADDR(base) ((base) + (0x1978))
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_ADDR(base) ((base) + (0x197C))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_LOW_ADDR(base) ((base) + (0x1980))
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_HIGH_ADDR(base) ((base) + (0x1984))
#define SOC_PCTRL_PERI_CTRL5_ADDR(base) ((base) + (0x1C00))
#define SOC_PCTRL_PERI_CTRL6_ADDR(base) ((base) + (0x1C04))
#define SOC_PCTRL_PERI_CTRL7_ADDR(base) ((base) + (0x1C08))
#define SOC_PCTRL_PERI_CTRL8_ADDR(base) ((base) + (0x1C0C))
#define SOC_PCTRL_PERI_CTRL9_ADDR(base) ((base) + (0x1C10))
#define SOC_PCTRL_PERI_CTRL10_ADDR(base) ((base) + (0x1C14))
#define SOC_PCTRL_PERI_CTRL11_ADDR(base) ((base) + (0x1C18))
#define SOC_PCTRL_PERI_CTRL34_ADDR(base) ((base) + (0x1C1C))
#define SOC_PCTRL_PERI_CTRL35_ADDR(base) ((base) + (0x1C20))
#define SOC_PCTRL_PERI_CTRL38_ADDR(base) ((base) + (0x1C2C))
#define SOC_PCTRL_PERI_CTRL39_ADDR(base) ((base) + (0x1C30))
#define SOC_PCTRL_PERI_CTRL40_ADDR(base) ((base) + (0x1C34))
#define SOC_PCTRL_PERI_CTRL41_ADDR(base) ((base) + (0x1C38))
#define SOC_PCTRL_PERI_CTRL42_ADDR(base) ((base) + (0x1C3C))
#define SOC_PCTRL_PERI_CTRL43_ADDR(base) ((base) + (0x1C40))
#define SOC_PCTRL_PERI_CTRL44_ADDR(base) ((base) + (0x1C44))
#define SOC_PCTRL_PERI_CTRL45_ADDR(base) ((base) + (0x1C48))
#define SOC_PCTRL_PERI_CTRL46_ADDR(base) ((base) + (0x1C4C))
#define SOC_PCTRL_PERI_CTRL47_ADDR(base) ((base) + (0x1C50))
#define SOC_PCTRL_PERI_CTRL48_ADDR(base) ((base) + (0x1C54))
#define SOC_PCTRL_PERI_CTRL49_ADDR(base) ((base) + (0x1C58))
#define SOC_PCTRL_PERI_CTRL50_ADDR(base) ((base) + (0x1C5C))
#define SOC_PCTRL_PERI_CTRL51_ADDR(base) ((base) + (0x1C60))
#define SOC_PCTRL_PERI_CTRL52_ADDR(base) ((base) + (0x1C64))
#define SOC_PCTRL_PERI_CTRL53_ADDR(base) ((base) + (0x1C68))
#define SOC_PCTRL_PERI_CTRL54_ADDR(base) ((base) + (0x1C6C))
#define SOC_PCTRL_PERI_CTRL55_ADDR(base) ((base) + (0x1C70))
#define SOC_PCTRL_PERI_CTRL56_ADDR(base) ((base) + (0x1C74))
#define SOC_PCTRL_PERI_CTRL57_ADDR(base) ((base) + (0x1C78))
#define SOC_PCTRL_PERI_CTRL58_ADDR(base) ((base) + (0x1C7C))
#define SOC_PCTRL_PERI_CTRL59_ADDR(base) ((base) + (0x1C80))
#define SOC_PCTRL_PERI_CTRL60_ADDR(base) ((base) + (0x1C84))
#define SOC_PCTRL_PERI_CTRL61_ADDR(base) ((base) + (0x1C88))
#define SOC_PCTRL_PERI_CTRL62_ADDR(base) ((base) + (0x1C8C))
#define SOC_PCTRL_PERI_CTRL63_ADDR(base) ((base) + (0x1C90))
#define SOC_PCTRL_PERI_CTRL64_ADDR(base) ((base) + (0x1C94))
#define SOC_PCTRL_PERI_CTRL65_ADDR(base) ((base) + (0x1C98))
#define SOC_PCTRL_PERI_CTRL66_ADDR(base) ((base) + (0x1C9C))
#define SOC_PCTRL_PERI_CTRL75_ADDR(base) ((base) + (0x1CA0))
#define SOC_PCTRL_PERI_CTRL76_ADDR(base) ((base) + (0x1CA4))
#define SOC_PCTRL_PERI_CTRL77_ADDR(base) ((base) + (0x1CA8))
#define SOC_PCTRL_PERI_CTRL78_ADDR(base) ((base) + (0x1CAC))
#define SOC_PCTRL_PERI_CTRL79_ADDR(base) ((base) + (0x1CB0))
#define SOC_PCTRL_PERI_CTRL80_ADDR(base) ((base) + (0x1CB4))
#define SOC_PCTRL_PERI_CTRL81_ADDR(base) ((base) + (0x1CB8))
#define SOC_PCTRL_PERI_CTRL82_ADDR(base) ((base) + (0x1CBC))
#define SOC_PCTRL_PERI_CTRL83_ADDR(base) ((base) + (0x1CC0))
#define SOC_PCTRL_PERI_CTRL84_ADDR(base) ((base) + (0x1CC4))
#define SOC_PCTRL_PERI_CTRL85_ADDR(base) ((base) + (0x1CC8))
#define SOC_PCTRL_PERI_CTRL86_ADDR(base) ((base) + (0x1CCC))
#define SOC_PCTRL_PERI_CTRL87_ADDR(base) ((base) + (0x1CD0))
#define SOC_PCTRL_PERI_STAT160_ADDR(base) ((base) + (0x1CD4))
#define SOC_PCTRL_PERI_CTRL168_ADDR(base) ((base) + (0x1CD8))
#define SOC_PCTRL_PERI_CTRL169_ADDR(base) ((base) + (0x1CDC))
#define SOC_PCTRL_PERI_CTRL170_ADDR(base) ((base) + (0x1CE0))
#define SOC_PCTRL_PERI_CTRL171_ADDR(base) ((base) + (0x1CE4))
#define SOC_PCTRL_PERI_CTRL172_ADDR(base) ((base) + (0x1CE8))
#define SOC_PCTRL_PERI_CTRL173_ADDR(base) ((base) + (0x1CEC))
#define SOC_PCTRL_PERI_CTRL174_ADDR(base) ((base) + (0x1CF0))
#define SOC_PCTRL_PERI_CTRL175_ADDR(base) ((base) + (0x1CF8))
#define SOC_PCTRL_PERI_CTRL176_ADDR(base) ((base) + (0x1CFC))
#define SOC_PCTRL_PERI_CTRL177_ADDR(base) ((base) + (0x1D00))
#define SOC_PCTRL_PERI_CTRL178_ADDR(base) ((base) + (0x1D04))
#define SOC_PCTRL_PERI_CTRL179_ADDR(base) ((base) + (0x1D08))
#define SOC_PCTRL_PERI_CTRL180_ADDR(base) ((base) + (0x1D0C))
#define SOC_PCTRL_PERI_CTRL181_ADDR(base) ((base) + (0x1D10))
#define SOC_PCTRL_PERI_CTRL182_ADDR(base) ((base) + (0x1D14))
#define SOC_PCTRL_PERI_CTRL183_ADDR(base) ((base) + (0x1D18))
#define SOC_PCTRL_PERI_CTRL184_ADDR(base) ((base) + (0x1D1C))
#define SOC_PCTRL_PERI_CTRL185_ADDR(base) ((base) + (0x1D20))
#define SOC_PCTRL_PERI_CTRL186_ADDR(base) ((base) + (0x1D24))
#define SOC_PCTRL_PERI_CTRL187_ADDR(base) ((base) + (0x1D28))
#define SOC_PCTRL_PERI_CTRL188_ADDR(base) ((base) + (0x1D2C))
#define SOC_PCTRL_PERI_CTRL189_ADDR(base) ((base) + (0x1D30))
#define SOC_PCTRL_PERI_CTRL190_ADDR(base) ((base) + (0x1D34))
#define SOC_PCTRL_PERI_CTRL191_ADDR(base) ((base) + (0x1D38))
#define SOC_PCTRL_PERI_CTRL192_ADDR(base) ((base) + (0x1D3C))
#define SOC_PCTRL_PERI_CTRL193_ADDR(base) ((base) + (0x1D40))
#define SOC_PCTRL_PERI_CTRL194_ADDR(base) ((base) + (0x1D44))
#define SOC_PCTRL_PERI_CTRL195_ADDR(base) ((base) + (0x1D48))
#define SOC_PCTRL_PERI_CTRL196_ADDR(base) ((base) + (0x1D4C))
#define SOC_PCTRL_PERI_CTRL197_ADDR(base) ((base) + (0x1D50))
#define SOC_PCTRL_PERI_CTRL198_ADDR(base) ((base) + (0x1D54))
#define SOC_PCTRL_PERI_CTRL199_ADDR(base) ((base) + (0x1D58))
#define SOC_PCTRL_PERI_CTRL200_ADDR(base) ((base) + (0x1D5C))
#define SOC_PCTRL_PERI_CTRL201_ADDR(base) ((base) + (0x1D60))
#define SOC_PCTRL_PERI_CTRL202_ADDR(base) ((base) + (0x1D64))
#define SOC_PCTRL_PERI_CTRL203_ADDR(base) ((base) + (0x1D68))
#define SOC_PCTRL_PERI_CTRL204_ADDR(base) ((base) + (0x1D6C))
#define SOC_PCTRL_PERI_CTRL205_ADDR(base) ((base) + (0x1D70))
#define SOC_PCTRL_PERI_CTRL206_ADDR(base) ((base) + (0x1D74))
#define SOC_PCTRL_PERI_CTRL207_ADDR(base) ((base) + (0x1D78))
#define SOC_PCTRL_PERI_CTRL208_ADDR(base) ((base) + (0x1D7C))
#define SOC_PCTRL_PERI_CTRL209_ADDR(base) ((base) + (0x1D80))
#define SOC_PCTRL_PERI_CTRL210_ADDR(base) ((base) + (0x1D84))
#define SOC_PCTRL_PERI_CTRL211_ADDR(base) ((base) + (0x1D88))
#define SOC_PCTRL_PERI_CTRL212_ADDR(base) ((base) + (0x1D8C))
#define SOC_PCTRL_PERI_CTRL213_ADDR(base) ((base) + (0x1D90))
#define SOC_PCTRL_PERI_CTRL214_ADDR(base) ((base) + (0x1D94))
#define SOC_PCTRL_PERI_CTRL215_ADDR(base) ((base) + (0x1D98))
#define SOC_PCTRL_PERI_CTRL216_ADDR(base) ((base) + (0x1D9C))
#define SOC_PCTRL_PERI_CTRL217_ADDR(base) ((base) + (0x1DA0))
#define SOC_PCTRL_PERI_CTRL218_ADDR(base) ((base) + (0x1DA4))
#define SOC_PCTRL_PERI_CTRL219_ADDR(base) ((base) + (0x1DA8))
#define SOC_PCTRL_PERI_CTRL220_ADDR(base) ((base) + (0x1DAC))
#define SOC_PCTRL_PERI_CTRL221_ADDR(base) ((base) + (0x1DB0))
#define SOC_PCTRL_PERI_CTRL222_ADDR(base) ((base) + (0x1DB4))
#define SOC_PCTRL_PERI_CTRL223_ADDR(base) ((base) + (0x1DB8))
#define SOC_PCTRL_PERI_CTRL224_ADDR(base) ((base) + (0x1DBC))
#define SOC_PCTRL_PERI_CTRL225_ADDR(base) ((base) + (0x1DC0))
#define SOC_PCTRL_PERI_CTRL226_ADDR(base) ((base) + (0x1DC4))
#define SOC_PCTRL_PERI_CTRL227_ADDR(base) ((base) + (0x1DC8))
#define SOC_PCTRL_PERI_CTRL228_ADDR(base) ((base) + (0x1DCC))
#define SOC_PCTRL_PERI_CTRL229_ADDR(base) ((base) + (0x1DD0))
#define SOC_PCTRL_PERI_CTRL230_ADDR(base) ((base) + (0x1DD4))
#define SOC_PCTRL_PERI_CTRL231_ADDR(base) ((base) + (0x1DD8))
#define SOC_PCTRL_PERI_CTRL232_ADDR(base) ((base) + (0x1DDC))
#define SOC_PCTRL_PERI_CTRL233_ADDR(base) ((base) + (0x1DE0))
#define SOC_PCTRL_PERI_CTRL234_ADDR(base) ((base) + (0x1DE4))
#define SOC_PCTRL_PERI_CTRL235_ADDR(base) ((base) + (0x1DE8))
#define SOC_PCTRL_PERI_CTRL236_ADDR(base) ((base) + (0x1DEC))
#define SOC_PCTRL_PERI_CTRL237_ADDR(base) ((base) + (0x1DF0))
#define SOC_PCTRL_PERI_CTRL238_ADDR(base) ((base) + (0x1DF4))
#define SOC_PCTRL_PERI_CTRL239_ADDR(base) ((base) + (0x1DF8))
#define SOC_PCTRL_PERI_CTRL240_ADDR(base) ((base) + (0x1DFC))
#define SOC_PCTRL_PERI_CTRL241_ADDR(base) ((base) + (0x1E00))
#define SOC_PCTRL_PERI_CTRL242_ADDR(base) ((base) + (0x1E04))
#define SOC_PCTRL_PERI_CTRL243_ADDR(base) ((base) + (0x1E08))
#define SOC_PCTRL_PERI_CTRL244_ADDR(base) ((base) + (0x1E0C))
#define SOC_PCTRL_PERI_CTRL245_ADDR(base) ((base) + (0x1E10))
#define SOC_PCTRL_PERI_CTRL246_ADDR(base) ((base) + (0x1E14))
#define SOC_PCTRL_PERI_CTRL247_ADDR(base) ((base) + (0x1E18))
#define SOC_PCTRL_PERI_CTRL248_ADDR(base) ((base) + (0x1E1C))
#define SOC_PCTRL_PERI_CTRL249_ADDR(base) ((base) + (0x1E20))
#define SOC_PCTRL_PERI_STAT_SEC0_ADDR(base) ((base) + (0x1E24))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_G3D_RASTER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_USB2_HOST_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_USB2_HOST_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_USB2_HOST_CTRL2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en : 1;
        unsigned int qic_timeout_en_tb_cfgdma2sys : 1;
        unsigned int qic_timeout_en_tb_qice : 1;
        unsigned int reserved : 13;
        unsigned int peri_ctrl4_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL4_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL4_qic_timeout_en_START (0)
#define SOC_PCTRL_PERI_CTRL4_qic_timeout_en_END (0)
#define SOC_PCTRL_PERI_CTRL4_qic_timeout_en_tb_cfgdma2sys_START (1)
#define SOC_PCTRL_PERI_CTRL4_qic_timeout_en_tb_cfgdma2sys_END (1)
#define SOC_PCTRL_PERI_CTRL4_qic_timeout_en_tb_qice_START (2)
#define SOC_PCTRL_PERI_CTRL4_qic_timeout_en_tb_qice_END (2)
#define SOC_PCTRL_PERI_CTRL4_peri_ctrl4_msk_START (16)
#define SOC_PCTRL_PERI_CTRL4_peri_ctrl4_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 7;
        unsigned int ddr_xctrl_spua_ctrl_slp : 1;
        unsigned int bfmux_ddr_xctrl_spua_ctrl_dslp : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_PCTRL_PERI_CTRL98_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL98_ddr_xctrl_spua_ctrl_slp_START (7)
#define SOC_PCTRL_PERI_CTRL98_ddr_xctrl_spua_ctrl_slp_END (7)
#define SOC_PCTRL_PERI_CTRL98_bfmux_ddr_xctrl_spua_ctrl_dslp_START (8)
#define SOC_PCTRL_PERI_CTRL98_bfmux_ddr_xctrl_spua_ctrl_dslp_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdmperi_nonret_mem_ctrl_dslp : 1;
        unsigned int reserved_0 : 5;
        unsigned int peri_edmac_tpl_ctrl_slp : 1;
        unsigned int bfmux_peri_edmac_tpl_ctrl_dslp : 1;
        unsigned int reserved_1 : 1;
        unsigned int spi_tpram_ctrl_slp : 1;
        unsigned int bfmux_spi_tpram_ctrl_dslp : 1;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_PCTRL_PERI_CTRL99_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL99_mdmperi_nonret_mem_ctrl_dslp_START (0)
#define SOC_PCTRL_PERI_CTRL99_mdmperi_nonret_mem_ctrl_dslp_END (0)
#define SOC_PCTRL_PERI_CTRL99_peri_edmac_tpl_ctrl_slp_START (6)
#define SOC_PCTRL_PERI_CTRL99_peri_edmac_tpl_ctrl_slp_END (6)
#define SOC_PCTRL_PERI_CTRL99_bfmux_peri_edmac_tpl_ctrl_dslp_START (7)
#define SOC_PCTRL_PERI_CTRL99_bfmux_peri_edmac_tpl_ctrl_dslp_END (7)
#define SOC_PCTRL_PERI_CTRL99_spi_tpram_ctrl_slp_START (9)
#define SOC_PCTRL_PERI_CTRL99_spi_tpram_ctrl_slp_END (9)
#define SOC_PCTRL_PERI_CTRL99_bfmux_spi_tpram_ctrl_dslp_START (10)
#define SOC_PCTRL_PERI_CTRL99_bfmux_spi_tpram_ctrl_dslp_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootrom_rom_ctrl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_PCTRL_PERI_CTRL100_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL100_bootrom_rom_ctrl_START (0)
#define SOC_PCTRL_PERI_CTRL100_bootrom_rom_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int spua_tselr : 3;
        unsigned int spua_tselw : 2;
        unsigned int spua_test : 3;
        unsigned int rf_tselr : 3;
        unsigned int rf_tselw : 2;
        unsigned int spua_tra : 2;
        unsigned int spua_twa : 2;
        unsigned int spua_twac : 2;
        unsigned int spea_tra : 2;
        unsigned int spea_twac : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_PCTRL_PERI_CTRL101_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL101_spua_tselr_START (3)
#define SOC_PCTRL_PERI_CTRL101_spua_tselr_END (5)
#define SOC_PCTRL_PERI_CTRL101_spua_tselw_START (6)
#define SOC_PCTRL_PERI_CTRL101_spua_tselw_END (7)
#define SOC_PCTRL_PERI_CTRL101_spua_test_START (8)
#define SOC_PCTRL_PERI_CTRL101_spua_test_END (10)
#define SOC_PCTRL_PERI_CTRL101_rf_tselr_START (11)
#define SOC_PCTRL_PERI_CTRL101_rf_tselr_END (13)
#define SOC_PCTRL_PERI_CTRL101_rf_tselw_START (14)
#define SOC_PCTRL_PERI_CTRL101_rf_tselw_END (15)
#define SOC_PCTRL_PERI_CTRL101_spua_tra_START (16)
#define SOC_PCTRL_PERI_CTRL101_spua_tra_END (17)
#define SOC_PCTRL_PERI_CTRL101_spua_twa_START (18)
#define SOC_PCTRL_PERI_CTRL101_spua_twa_END (19)
#define SOC_PCTRL_PERI_CTRL101_spua_twac_START (20)
#define SOC_PCTRL_PERI_CTRL101_spua_twac_END (21)
#define SOC_PCTRL_PERI_CTRL101_spea_tra_START (22)
#define SOC_PCTRL_PERI_CTRL101_spea_tra_END (23)
#define SOC_PCTRL_PERI_CTRL101_spea_twac_START (24)
#define SOC_PCTRL_PERI_CTRL101_spea_twac_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdcu_qsp_bus_cg_en : 1;
        unsigned int sdcu_qslv_err_clr : 1;
        unsigned int sdcu_pdlock_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_PCTRL_PERI_CTRL104_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL104_sdcu_qsp_bus_cg_en_START (0)
#define SOC_PCTRL_PERI_CTRL104_sdcu_qsp_bus_cg_en_END (0)
#define SOC_PCTRL_PERI_CTRL104_sdcu_qslv_err_clr_START (1)
#define SOC_PCTRL_PERI_CTRL104_sdcu_qslv_err_clr_END (1)
#define SOC_PCTRL_PERI_CTRL104_sdcu_pdlock_en_START (2)
#define SOC_PCTRL_PERI_CTRL104_sdcu_pdlock_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int sphcsram_rtsel : 3;
        unsigned int sphcsram_wtsel : 2;
        unsigned int spsram_test : 3;
        unsigned int sphdsram_rtsel : 3;
        unsigned int sphdsram_wtsel : 2;
        unsigned int spsram_tra_peri : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_PCTRL_PERI_CTRL12_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL12_sphcsram_rtsel_START (3)
#define SOC_PCTRL_PERI_CTRL12_sphcsram_rtsel_END (5)
#define SOC_PCTRL_PERI_CTRL12_sphcsram_wtsel_START (6)
#define SOC_PCTRL_PERI_CTRL12_sphcsram_wtsel_END (7)
#define SOC_PCTRL_PERI_CTRL12_spsram_test_START (8)
#define SOC_PCTRL_PERI_CTRL12_spsram_test_END (10)
#define SOC_PCTRL_PERI_CTRL12_sphdsram_rtsel_START (11)
#define SOC_PCTRL_PERI_CTRL12_sphdsram_rtsel_END (13)
#define SOC_PCTRL_PERI_CTRL12_sphdsram_wtsel_START (14)
#define SOC_PCTRL_PERI_CTRL12_sphdsram_wtsel_END (15)
#define SOC_PCTRL_PERI_CTRL12_spsram_tra_peri_START (16)
#define SOC_PCTRL_PERI_CTRL12_spsram_tra_peri_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int tprf_tselr : 2;
        unsigned int tprf_tselw : 2;
        unsigned int tprf_test : 3;
        unsigned int tprf_tra_peri : 2;
        unsigned int reserved_1 : 9;
        unsigned int tpl_tselr : 2;
        unsigned int tpl_tselw : 2;
        unsigned int tpl_test : 3;
        unsigned int tpl_tra_peri : 2;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_PCTRL_PERI_CTRL13_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL13_tprf_tselr_START (4)
#define SOC_PCTRL_PERI_CTRL13_tprf_tselr_END (5)
#define SOC_PCTRL_PERI_CTRL13_tprf_tselw_START (6)
#define SOC_PCTRL_PERI_CTRL13_tprf_tselw_END (7)
#define SOC_PCTRL_PERI_CTRL13_tprf_test_START (8)
#define SOC_PCTRL_PERI_CTRL13_tprf_test_END (10)
#define SOC_PCTRL_PERI_CTRL13_tprf_tra_peri_START (11)
#define SOC_PCTRL_PERI_CTRL13_tprf_tra_peri_END (12)
#define SOC_PCTRL_PERI_CTRL13_tpl_tselr_START (22)
#define SOC_PCTRL_PERI_CTRL13_tpl_tselr_END (23)
#define SOC_PCTRL_PERI_CTRL13_tpl_tselw_START (24)
#define SOC_PCTRL_PERI_CTRL13_tpl_tselw_END (25)
#define SOC_PCTRL_PERI_CTRL13_tpl_test_START (26)
#define SOC_PCTRL_PERI_CTRL13_tpl_test_END (28)
#define SOC_PCTRL_PERI_CTRL13_tpl_tra_peri_START (29)
#define SOC_PCTRL_PERI_CTRL13_tpl_tra_peri_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rom_dt : 2;
        unsigned int rom_skp : 2;
        unsigned int rom_ckle : 1;
        unsigned int rom_ckhe : 1;
        unsigned int reserved_0: 11;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 14;
    } reg;
} SOC_PCTRL_PERI_CTRL14_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL14_rom_dt_START (0)
#define SOC_PCTRL_PERI_CTRL14_rom_dt_END (1)
#define SOC_PCTRL_PERI_CTRL14_rom_skp_START (2)
#define SOC_PCTRL_PERI_CTRL14_rom_skp_END (3)
#define SOC_PCTRL_PERI_CTRL14_rom_ckle_START (4)
#define SOC_PCTRL_PERI_CTRL14_rom_ckle_END (4)
#define SOC_PCTRL_PERI_CTRL14_rom_ckhe_START (5)
#define SOC_PCTRL_PERI_CTRL14_rom_ckhe_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int bpram_tselr : 3;
        unsigned int bpram_tselw : 2;
        unsigned int bpram_test : 3;
        unsigned int bpram_tra_peri : 2;
        unsigned int reserved_1 : 1;
        unsigned int bpram_tselm : 2;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL15_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL15_bpram_tselr_START (3)
#define SOC_PCTRL_PERI_CTRL15_bpram_tselr_END (5)
#define SOC_PCTRL_PERI_CTRL15_bpram_tselw_START (6)
#define SOC_PCTRL_PERI_CTRL15_bpram_tselw_END (7)
#define SOC_PCTRL_PERI_CTRL15_bpram_test_START (8)
#define SOC_PCTRL_PERI_CTRL15_bpram_test_END (10)
#define SOC_PCTRL_PERI_CTRL15_bpram_tra_peri_START (11)
#define SOC_PCTRL_PERI_CTRL15_bpram_tra_peri_END (12)
#define SOC_PCTRL_PERI_CTRL15_bpram_tselm_START (14)
#define SOC_PCTRL_PERI_CTRL15_bpram_tselm_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi4_cs_sel : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_PCTRL_PERI_CTRL16_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL16_spi4_cs_sel_START (0)
#define SOC_PCTRL_PERI_CTRL16_spi4_cs_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_rs_dmca : 1;
        unsigned int ckg_byp_rs_dmcb : 1;
        unsigned int ckg_byp_rs_dmcc : 1;
        unsigned int ckg_byp_rs_dmcd : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PCTRL_PERI_CTRL17_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmca_START (0)
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmca_END (0)
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmcb_START (1)
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmcb_END (1)
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmcc_START (2)
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmcc_END (2)
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmcd_START (3)
#define SOC_PCTRL_PERI_CTRL17_ckg_byp_rs_dmcd_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwr_dwn_req_cdphy0 : 1;
        unsigned int pwr_dwn_req_cdphy1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_PERI_CTRL18_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL18_pwr_dwn_req_cdphy0_START (0)
#define SOC_PCTRL_PERI_CTRL18_pwr_dwn_req_cdphy0_END (0)
#define SOC_PCTRL_PERI_CTRL18_pwr_dwn_req_cdphy1_START (1)
#define SOC_PCTRL_PERI_CTRL18_pwr_dwn_req_cdphy1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_xpu_ua_sig_a : 8;
        unsigned int ddr_xpu_ua_sig_b : 8;
        unsigned int ddr_xpu_ua_sig_c : 8;
        unsigned int ddr_xpu_ua_sig_d : 8;
    } reg;
} SOC_PCTRL_PERI_CTRL19_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_a_START (0)
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_a_END (7)
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_b_START (8)
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_b_END (15)
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_c_START (16)
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_c_END (23)
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_d_START (24)
#define SOC_PCTRL_PERI_CTRL19_ddr_xpu_ua_sig_d_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uart0_1wire_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_PCTRL_PERI_CTRL20_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL20_uart0_1wire_en_START (0)
#define SOC_PCTRL_PERI_CTRL20_uart0_1wire_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ipc_ns_gt_clk_bypass : 1;
        unsigned int ipc_rtos_ns_gt_clk_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_PERI_CTRL21_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL21_ipc_ns_gt_clk_bypass_START (0)
#define SOC_PCTRL_PERI_CTRL21_ipc_ns_gt_clk_bypass_END (0)
#define SOC_PCTRL_PERI_CTRL21_ipc_rtos_ns_gt_clk_bypass_START (1)
#define SOC_PCTRL_PERI_CTRL21_ipc_rtos_ns_gt_clk_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmss_bus_buff_en : 1;
        unsigned int dmc_bus_buff_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_PERI_CTRL22_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL22_dmss_bus_buff_en_START (0)
#define SOC_PCTRL_PERI_CTRL22_dmss_bus_buff_en_END (0)
#define SOC_PCTRL_PERI_CTRL22_dmc_bus_buff_en_START (1)
#define SOC_PCTRL_PERI_CTRL22_dmc_bus_buff_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int sc_noc_djtag_mst_pstrb : 4;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int sc_dmac_ckgt_dis : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 3;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 3;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 4;
        unsigned int reserved_13 : 3;
    } reg;
} SOC_PCTRL_PERI_CTRL23_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL23_sc_noc_djtag_mst_pstrb_START (3)
#define SOC_PCTRL_PERI_CTRL23_sc_noc_djtag_mst_pstrb_END (6)
#define SOC_PCTRL_PERI_CTRL23_sc_dmac_ckgt_dis_START (11)
#define SOC_PCTRL_PERI_CTRL23_sc_dmac_ckgt_dis_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cc_nopending_pdms_mux_sel : 3;
        unsigned int qic_cc_nopending_mux_sel1 : 5;
        unsigned int qic_cc_nopending_mux_sel0 : 5;
        unsigned int qic_cc_idlereq_mux_sel1 : 1;
        unsigned int qic_cc_idleack_mux_sel1 : 1;
        unsigned int reserved_0 : 5;
        unsigned int qic_cc_intr_qic_mux_sel : 5;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_PCTRL_PERI_CTRL24_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL24_qic_cc_nopending_pdms_mux_sel_START (0)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_nopending_pdms_mux_sel_END (2)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_nopending_mux_sel1_START (3)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_nopending_mux_sel1_END (7)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_nopending_mux_sel0_START (8)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_nopending_mux_sel0_END (12)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_idlereq_mux_sel1_START (13)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_idlereq_mux_sel1_END (13)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_idleack_mux_sel1_START (14)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_idleack_mux_sel1_END (14)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_intr_qic_mux_sel_START (20)
#define SOC_PCTRL_PERI_CTRL24_qic_cc_intr_qic_mux_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cfg_dma_nopending_pdms_mux_sel : 3;
        unsigned int qic_cfg_dma_nopending_mux_sel1 : 5;
        unsigned int qic_cfg_dma_nopending_mux_sel0 : 5;
        unsigned int qic_cfg_dma_idlereq_mux_sel1 : 1;
        unsigned int qic_cfg_dma_idleack_mux_sel1 : 1;
        unsigned int reserved_0 : 5;
        unsigned int qic_cfg_dma_intr_qic_mux_sel : 5;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_PCTRL_PERI_CTRL25_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_nopending_pdms_mux_sel_START (0)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_nopending_pdms_mux_sel_END (2)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_nopending_mux_sel1_START (3)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_nopending_mux_sel1_END (7)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_nopending_mux_sel0_START (8)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_nopending_mux_sel0_END (12)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_idlereq_mux_sel1_START (13)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_idlereq_mux_sel1_END (13)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_idleack_mux_sel1_START (14)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_idleack_mux_sel1_END (14)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_intr_qic_mux_sel_START (20)
#define SOC_PCTRL_PERI_CTRL25_qic_cfg_dma_intr_qic_mux_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cfg_dma_idlereq_mask : 16;
        unsigned int qic_cfg_dma_idleack_mask : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL26_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL26_qic_cfg_dma_idlereq_mask_START (0)
#define SOC_PCTRL_PERI_CTRL26_qic_cfg_dma_idlereq_mask_END (15)
#define SOC_PCTRL_PERI_CTRL26_qic_cfg_dma_idleack_mask_START (16)
#define SOC_PCTRL_PERI_CTRL26_qic_cfg_dma_idleack_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cfg_dma_nopending_pdms_mask : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL28_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL28_qic_cfg_dma_nopending_pdms_mask_START (0)
#define SOC_PCTRL_PERI_CTRL28_qic_cfg_dma_nopending_pdms_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cfg_dma_intr_qic_mask : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL29_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL29_qic_cfg_dma_intr_qic_mask_START (0)
#define SOC_PCTRL_PERI_CTRL29_qic_cfg_dma_intr_qic_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dma_autofs_byp2 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL30_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL30_cfg_dma_autofs_byp2_START (0)
#define SOC_PCTRL_PERI_CTRL30_cfg_dma_autofs_byp2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cfg_dma_nopending_mask0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL31_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL31_qic_cfg_dma_nopending_mask0_START (0)
#define SOC_PCTRL_PERI_CTRL31_qic_cfg_dma_nopending_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cfg_dma_nopending_mask1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL32_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL32_qic_cfg_dma_nopending_mask1_START (0)
#define SOC_PCTRL_PERI_CTRL32_qic_cfg_dma_nopending_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cc_idlereq_mask : 16;
        unsigned int qic_cc_idleack_mask : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL33_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL33_qic_cc_idlereq_mask_START (0)
#define SOC_PCTRL_PERI_CTRL33_qic_cc_idlereq_mask_END (15)
#define SOC_PCTRL_PERI_CTRL33_qic_cc_idleack_mask_START (16)
#define SOC_PCTRL_PERI_CTRL33_qic_cc_idleack_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL67_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cc_nopending_pdms_mask : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL68_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL68_qic_cc_nopending_pdms_mask_START (0)
#define SOC_PCTRL_PERI_CTRL68_qic_cc_nopending_pdms_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cc_intr_qic_mask : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL69_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL69_qic_cc_intr_qic_mask_START (0)
#define SOC_PCTRL_PERI_CTRL69_qic_cc_intr_qic_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cc_nopending_mask0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL70_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL70_qic_cc_nopending_mask0_START (0)
#define SOC_PCTRL_PERI_CTRL70_qic_cc_nopending_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_cc_nopending_mask1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL71_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL71_qic_cc_nopending_mask1_START (0)
#define SOC_PCTRL_PERI_CTRL71_qic_cc_nopending_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL72_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_reserved_ctrl_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL73_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL73_pctrl_reserved_ctrl_0_START (0)
#define SOC_PCTRL_PERI_CTRL73_pctrl_reserved_ctrl_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_reserved_ctrl_1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL74_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL74_pctrl_reserved_ctrl_1_START (0)
#define SOC_PCTRL_PERI_CTRL74_pctrl_reserved_ctrl_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_reserved_ctrl_2 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL88_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL88_pctrl_reserved_ctrl_2_START (0)
#define SOC_PCTRL_PERI_CTRL88_pctrl_reserved_ctrl_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_comb_qice_mask : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL89_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL89_intr_comb_qice_mask_START (0)
#define SOC_PCTRL_PERI_CTRL89_intr_comb_qice_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ap2mdm_ctrl : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL90_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL90_ap2mdm_ctrl_START (0)
#define SOC_PCTRL_PERI_CTRL90_ap2mdm_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL91_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL91_center_crossbar_autofs_byp0_START (0)
#define SOC_PCTRL_PERI_CTRL91_center_crossbar_autofs_byp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp0_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL92_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL92_center_crossbar_autofs_byp0_d1_START (0)
#define SOC_PCTRL_PERI_CTRL92_center_crossbar_autofs_byp0_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL93_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL93_center_crossbar_autofs_byp1_START (0)
#define SOC_PCTRL_PERI_CTRL93_center_crossbar_autofs_byp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp1_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL95_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL95_center_crossbar_autofs_byp1_d1_START (0)
#define SOC_PCTRL_PERI_CTRL95_center_crossbar_autofs_byp1_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp2 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL96_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL96_center_crossbar_autofs_byp2_START (0)
#define SOC_PCTRL_PERI_CTRL96_center_crossbar_autofs_byp2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp2_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL97_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL97_center_crossbar_autofs_byp2_d1_START (0)
#define SOC_PCTRL_PERI_CTRL97_center_crossbar_autofs_byp2_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp3 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL108_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL108_center_crossbar_autofs_byp3_START (0)
#define SOC_PCTRL_PERI_CTRL108_center_crossbar_autofs_byp3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp3_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL109_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL109_center_crossbar_autofs_byp3_d1_START (0)
#define SOC_PCTRL_PERI_CTRL109_center_crossbar_autofs_byp3_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp5 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL110_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL110_center_crossbar_autofs_byp5_START (0)
#define SOC_PCTRL_PERI_CTRL110_center_crossbar_autofs_byp5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_zq_ch_sel_ca : 2;
        unsigned int cfg_zq_ch_sel_db : 2;
        unsigned int cfg_zq_ch_sel_rsv0 : 2;
        unsigned int cfg_zq_ch_sel_rsv1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int icfg_cha_seq : 2;
        unsigned int icfg_chb_seq : 2;
        unsigned int icfg_chc_seq : 2;
        unsigned int icfg_chd_seq : 2;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_PCTRL_PERI_CTRL111_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_ca_START (0)
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_ca_END (1)
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_db_START (2)
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_db_END (3)
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_rsv0_START (4)
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_rsv0_END (5)
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_rsv1_START (6)
#define SOC_PCTRL_PERI_CTRL111_cfg_zq_ch_sel_rsv1_END (6)
#define SOC_PCTRL_PERI_CTRL111_icfg_cha_seq_START (10)
#define SOC_PCTRL_PERI_CTRL111_icfg_cha_seq_END (11)
#define SOC_PCTRL_PERI_CTRL111_icfg_chb_seq_START (12)
#define SOC_PCTRL_PERI_CTRL111_icfg_chb_seq_END (13)
#define SOC_PCTRL_PERI_CTRL111_icfg_chc_seq_START (14)
#define SOC_PCTRL_PERI_CTRL111_icfg_chc_seq_END (15)
#define SOC_PCTRL_PERI_CTRL111_icfg_chd_seq_START (16)
#define SOC_PCTRL_PERI_CTRL111_icfg_chd_seq_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1_ufs_mphy_parallel_test_en : 1;
        unsigned int mudp_mphy_parallel_test_en : 1;
        unsigned int reserved_0 : 29;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_PCTRL_PERI_CTRL112_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL112_hsdt1_ufs_mphy_parallel_test_en_START (0)
#define SOC_PCTRL_PERI_CTRL112_hsdt1_ufs_mphy_parallel_test_en_END (0)
#define SOC_PCTRL_PERI_CTRL112_mudp_mphy_parallel_test_en_START (1)
#define SOC_PCTRL_PERI_CTRL112_mudp_mphy_parallel_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perfstat_mon_clkgt : 1;
        unsigned int pctrl_perf_sdcu_npu_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 25;
    } reg;
} SOC_PCTRL_PERI_CTRL113_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL113_perfstat_mon_clkgt_START (0)
#define SOC_PCTRL_PERI_CTRL113_perfstat_mon_clkgt_END (0)
#define SOC_PCTRL_PERI_CTRL113_pctrl_perf_sdcu_npu_sel_START (1)
#define SOC_PCTRL_PERI_CTRL113_pctrl_perf_sdcu_npu_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp4 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL114_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL114_center_crossbar_autofs_byp4_START (0)
#define SOC_PCTRL_PERI_CTRL114_center_crossbar_autofs_byp4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp4_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL115_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL115_center_crossbar_autofs_byp4_d1_START (0)
#define SOC_PCTRL_PERI_CTRL115_center_crossbar_autofs_byp4_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp5_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL116_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL116_center_crossbar_autofs_byp5_d1_START (0)
#define SOC_PCTRL_PERI_CTRL116_center_crossbar_autofs_byp5_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmac_aw_lmtr_saturation : 14;
        unsigned int dmac_aw_lmtr_bandwidth : 13;
        unsigned int dmac_aw_lmtr_en : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_PCTRL_PERI_CTRL117_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL117_dmac_aw_lmtr_saturation_START (0)
#define SOC_PCTRL_PERI_CTRL117_dmac_aw_lmtr_saturation_END (13)
#define SOC_PCTRL_PERI_CTRL117_dmac_aw_lmtr_bandwidth_START (14)
#define SOC_PCTRL_PERI_CTRL117_dmac_aw_lmtr_bandwidth_END (26)
#define SOC_PCTRL_PERI_CTRL117_dmac_aw_lmtr_en_START (27)
#define SOC_PCTRL_PERI_CTRL117_dmac_aw_lmtr_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmac_ar_lmtr_saturation : 14;
        unsigned int dmac_ar_lmtr_bandwidth : 13;
        unsigned int dmac_ar_lmtr_en : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_PCTRL_PERI_CTRL118_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL118_dmac_ar_lmtr_saturation_START (0)
#define SOC_PCTRL_PERI_CTRL118_dmac_ar_lmtr_saturation_END (13)
#define SOC_PCTRL_PERI_CTRL118_dmac_ar_lmtr_bandwidth_START (14)
#define SOC_PCTRL_PERI_CTRL118_dmac_ar_lmtr_bandwidth_END (26)
#define SOC_PCTRL_PERI_CTRL118_dmac_ar_lmtr_en_START (27)
#define SOC_PCTRL_PERI_CTRL118_dmac_ar_lmtr_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dma_autofs_byp0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL119_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL119_cfg_dma_autofs_byp0_START (0)
#define SOC_PCTRL_PERI_CTRL119_cfg_dma_autofs_byp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dma_autofs_byp1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL120_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL120_cfg_dma_autofs_byp1_START (0)
#define SOC_PCTRL_PERI_CTRL120_cfg_dma_autofs_byp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_req_timeout : 10;
        unsigned int cfg_timeout_bypass : 1;
        unsigned int cfg_sync_mask : 4;
        unsigned int cfg_timeout_clear : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL121_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL121_cfg_req_timeout_START (0)
#define SOC_PCTRL_PERI_CTRL121_cfg_req_timeout_END (9)
#define SOC_PCTRL_PERI_CTRL121_cfg_timeout_bypass_START (10)
#define SOC_PCTRL_PERI_CTRL121_cfg_timeout_bypass_END (10)
#define SOC_PCTRL_PERI_CTRL121_cfg_sync_mask_START (11)
#define SOC_PCTRL_PERI_CTRL121_cfg_sync_mask_END (14)
#define SOC_PCTRL_PERI_CTRL121_cfg_timeout_clear_START (15)
#define SOC_PCTRL_PERI_CTRL121_cfg_timeout_clear_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL122_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL122_pctrl_modem_reserved0_START (0)
#define SOC_PCTRL_PERI_CTRL122_pctrl_modem_reserved0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL123_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL123_pctrl_modem_reserved1_START (0)
#define SOC_PCTRL_PERI_CTRL123_pctrl_modem_reserved1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved2 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL124_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL124_pctrl_modem_reserved2_START (0)
#define SOC_PCTRL_PERI_CTRL124_pctrl_modem_reserved2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved3 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL125_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL125_pctrl_modem_reserved3_START (0)
#define SOC_PCTRL_PERI_CTRL125_pctrl_modem_reserved3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved4 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL126_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL126_pctrl_modem_reserved4_START (0)
#define SOC_PCTRL_PERI_CTRL126_pctrl_modem_reserved4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved5 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL127_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL127_pctrl_modem_reserved5_START (0)
#define SOC_PCTRL_PERI_CTRL127_pctrl_modem_reserved5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved6 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL128_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL128_pctrl_modem_reserved6_START (0)
#define SOC_PCTRL_PERI_CTRL128_pctrl_modem_reserved6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved7 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL129_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL129_pctrl_modem_reserved7_START (0)
#define SOC_PCTRL_PERI_CTRL129_pctrl_modem_reserved7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_perf_stat_icfg_arvcidx_device : 8;
        unsigned int ib_perf_stat_icfg_awvcidx_device : 8;
        unsigned int ib_pwr_mon_icfg_arvcidx_device : 8;
        unsigned int ib_pwr_mon_icfg_awvcidx_device : 8;
    } reg;
} SOC_PCTRL_PERI_CTRL130_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL130_ib_perf_stat_icfg_arvcidx_device_START (0)
#define SOC_PCTRL_PERI_CTRL130_ib_perf_stat_icfg_arvcidx_device_END (7)
#define SOC_PCTRL_PERI_CTRL130_ib_perf_stat_icfg_awvcidx_device_START (8)
#define SOC_PCTRL_PERI_CTRL130_ib_perf_stat_icfg_awvcidx_device_END (15)
#define SOC_PCTRL_PERI_CTRL130_ib_pwr_mon_icfg_arvcidx_device_START (16)
#define SOC_PCTRL_PERI_CTRL130_ib_pwr_mon_icfg_arvcidx_device_END (23)
#define SOC_PCTRL_PERI_CTRL130_ib_pwr_mon_icfg_awvcidx_device_START (24)
#define SOC_PCTRL_PERI_CTRL130_ib_pwr_mon_icfg_awvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_lpmcu_icfg_arvcidx_device : 8;
        unsigned int ib_djtag_icfg_arvcidx_device : 8;
        unsigned int ib_dmac_mst_icfg_arvcidx_device : 8;
        unsigned int ib_dmac_mst_icfg_awvcidx_device : 8;
    } reg;
} SOC_PCTRL_PERI_CTRL131_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL131_ib_lpmcu_icfg_arvcidx_device_START (0)
#define SOC_PCTRL_PERI_CTRL131_ib_lpmcu_icfg_arvcidx_device_END (7)
#define SOC_PCTRL_PERI_CTRL131_ib_djtag_icfg_arvcidx_device_START (8)
#define SOC_PCTRL_PERI_CTRL131_ib_djtag_icfg_arvcidx_device_END (15)
#define SOC_PCTRL_PERI_CTRL131_ib_dmac_mst_icfg_arvcidx_device_START (16)
#define SOC_PCTRL_PERI_CTRL131_ib_dmac_mst_icfg_arvcidx_device_END (23)
#define SOC_PCTRL_PERI_CTRL131_ib_dmac_mst_icfg_awvcidx_device_START (24)
#define SOC_PCTRL_PERI_CTRL131_ib_dmac_mst_icfg_awvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_perf_stat_icfg_arvcidx_ddr : 8;
        unsigned int ib_perf_stat_icfg_awvcidx_ddr : 8;
        unsigned int ib_pwr_mon_icfg_arvcidx_ddr : 8;
        unsigned int ib_pwr_mon_icfg_awvcidx_ddr : 8;
    } reg;
} SOC_PCTRL_PERI_CTRL132_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL132_ib_perf_stat_icfg_arvcidx_ddr_START (0)
#define SOC_PCTRL_PERI_CTRL132_ib_perf_stat_icfg_arvcidx_ddr_END (7)
#define SOC_PCTRL_PERI_CTRL132_ib_perf_stat_icfg_awvcidx_ddr_START (8)
#define SOC_PCTRL_PERI_CTRL132_ib_perf_stat_icfg_awvcidx_ddr_END (15)
#define SOC_PCTRL_PERI_CTRL132_ib_pwr_mon_icfg_arvcidx_ddr_START (16)
#define SOC_PCTRL_PERI_CTRL132_ib_pwr_mon_icfg_arvcidx_ddr_END (23)
#define SOC_PCTRL_PERI_CTRL132_ib_pwr_mon_icfg_awvcidx_ddr_START (24)
#define SOC_PCTRL_PERI_CTRL132_ib_pwr_mon_icfg_awvcidx_ddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_lpmcu_icfg_arvcidx_ddr : 8;
        unsigned int ib_djtag_icfg_arvcidx_ddr : 8;
        unsigned int ib_dmac_mst_icfg_arvcidx_ddr : 8;
        unsigned int ib_dmac_mst_icfg_awvcidx_ddr : 8;
    } reg;
} SOC_PCTRL_PERI_CTRL133_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL133_ib_lpmcu_icfg_arvcidx_ddr_START (0)
#define SOC_PCTRL_PERI_CTRL133_ib_lpmcu_icfg_arvcidx_ddr_END (7)
#define SOC_PCTRL_PERI_CTRL133_ib_djtag_icfg_arvcidx_ddr_START (8)
#define SOC_PCTRL_PERI_CTRL133_ib_djtag_icfg_arvcidx_ddr_END (15)
#define SOC_PCTRL_PERI_CTRL133_ib_dmac_mst_icfg_arvcidx_ddr_START (16)
#define SOC_PCTRL_PERI_CTRL133_ib_dmac_mst_icfg_arvcidx_ddr_END (23)
#define SOC_PCTRL_PERI_CTRL133_ib_dmac_mst_icfg_awvcidx_ddr_START (24)
#define SOC_PCTRL_PERI_CTRL133_ib_dmac_mst_icfg_awvcidx_ddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_topcs_icfg_arvcidx_ddr : 8;
        unsigned int ib_topcs_icfg_awvcidx_ddr : 8;
        unsigned int ib_topcs_icfg_arvcidx_device : 8;
        unsigned int ib_topcs_icfg_awvcidx_device : 8;
    } reg;
} SOC_PCTRL_PERI_CTRL134_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_arvcidx_ddr_START (0)
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_arvcidx_ddr_END (7)
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_awvcidx_ddr_START (8)
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_awvcidx_ddr_END (15)
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_arvcidx_device_START (16)
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_arvcidx_device_END (23)
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_awvcidx_device_START (24)
#define SOC_PCTRL_PERI_CTRL134_ib_topcs_icfg_awvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp6 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL135_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL135_center_crossbar_autofs_byp6_START (0)
#define SOC_PCTRL_PERI_CTRL135_center_crossbar_autofs_byp6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp6_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL136_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL136_center_crossbar_autofs_byp6_d1_START (0)
#define SOC_PCTRL_PERI_CTRL136_center_crossbar_autofs_byp6_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpa_wakeup_irqs_en : 32;
    } reg;
} SOC_PCTRL_MDM_TSP_NMI0_UNION;
#endif
#define SOC_PCTRL_MDM_TSP_NMI0_dpa_wakeup_irqs_en_START (0)
#define SOC_PCTRL_MDM_TSP_NMI0_dpa_wakeup_irqs_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ispcpu2qice_gate_en : 1;
        unsigned int cpulc2qice_gate_en : 1;
        unsigned int cpuhc2qice_gate_en : 1;
        unsigned int dcdr2dmc3_ckg_en : 1;
        unsigned int dcdr2dmc2_ckg_en : 1;
        unsigned int dcdr2dmc1_ckg_en : 1;
        unsigned int dcdr2dmc0_ckg_en : 1;
        unsigned int icfg_ckg_rs_byp_npu2qice : 1;
        unsigned int icfg_ckg_rs_byp_m22qice : 1;
        unsigned int icfg_ckg_rs_byp_m12qice : 1;
        unsigned int icfg_ckg_rs_byp_qice2dmca_drsp : 1;
        unsigned int icfg_ckg_rs_byp_qice2dmca_crsp : 1;
        unsigned int icfg_ckg_rs_byp_qice2dmca_rdata : 1;
        unsigned int icfg_ckg_rs_byp_qice2dmcd_wdata : 1;
        unsigned int icfg_ckg_rs_byp_qice2dmcc_wdata : 1;
        unsigned int icfg_ckg_rs_byp_qice2dmcb_wdata : 1;
        unsigned int icfg_ckg_rs_byp_qice2dmca_wdata : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_PCTRL_PERI_CTRL138_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL138_ispcpu2qice_gate_en_START (0)
#define SOC_PCTRL_PERI_CTRL138_ispcpu2qice_gate_en_END (0)
#define SOC_PCTRL_PERI_CTRL138_cpulc2qice_gate_en_START (1)
#define SOC_PCTRL_PERI_CTRL138_cpulc2qice_gate_en_END (1)
#define SOC_PCTRL_PERI_CTRL138_cpuhc2qice_gate_en_START (2)
#define SOC_PCTRL_PERI_CTRL138_cpuhc2qice_gate_en_END (2)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc3_ckg_en_START (3)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc3_ckg_en_END (3)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc2_ckg_en_START (4)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc2_ckg_en_END (4)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc1_ckg_en_START (5)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc1_ckg_en_END (5)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc0_ckg_en_START (6)
#define SOC_PCTRL_PERI_CTRL138_dcdr2dmc0_ckg_en_END (6)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_npu2qice_START (7)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_npu2qice_END (7)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_m22qice_START (8)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_m22qice_END (8)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_m12qice_START (9)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_m12qice_END (9)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_drsp_START (10)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_drsp_END (10)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_crsp_START (11)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_crsp_END (11)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_rdata_START (12)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_rdata_END (12)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmcd_wdata_START (13)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmcd_wdata_END (13)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmcc_wdata_START (14)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmcc_wdata_END (14)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmcb_wdata_START (15)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmcb_wdata_END (15)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_wdata_START (16)
#define SOC_PCTRL_PERI_CTRL138_icfg_ckg_rs_byp_qice2dmca_wdata_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdm_nopending_sys2mdm_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PCTRL_PERI_CTRL139_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL139_pdm_nopending_sys2mdm_bypass_START (0)
#define SOC_PCTRL_PERI_CTRL139_pdm_nopending_sys2mdm_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp7 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL140_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL140_center_crossbar_autofs_byp7_START (0)
#define SOC_PCTRL_PERI_CTRL140_center_crossbar_autofs_byp7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int center_crossbar_autofs_byp7_d1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL141_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL141_center_crossbar_autofs_byp7_d1_START (0)
#define SOC_PCTRL_PERI_CTRL141_center_crossbar_autofs_byp7_d1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL142_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL143_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL144_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL145_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL146_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL147_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL148_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL149_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL150_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL151_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL152_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL153_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL154_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL155_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL156_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL157_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL158_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL159_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL160_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL161_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL162_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL163_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL164_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL165_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL166_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL167_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT1_UNION;
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
        unsigned int reserved_13: 19;
    } reg;
} SOC_PCTRL_PERI_STAT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idle_ddrxctrl_h2p : 1;
        unsigned int idle_ddrxctrl_minibus : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_PERI_STAT3_UNION;
#endif
#define SOC_PCTRL_PERI_STAT3_idle_ddrxctrl_h2p_START (0)
#define SOC_PCTRL_PERI_STAT3_idle_ddrxctrl_h2p_END (0)
#define SOC_PCTRL_PERI_STAT3_idle_ddrxctrl_minibus_START (1)
#define SOC_PCTRL_PERI_STAT3_idle_ddrxctrl_minibus_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int cssys_etr_x2x_ckg_idle : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 2;
        unsigned int reserved_8 : 8;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int sc_mdm_reset_stat : 1;
        unsigned int pwr_dwn_ack_cdphy0 : 1;
        unsigned int pwr_dwn_ack_cdphy1 : 1;
        unsigned int reserved_11 : 3;
        unsigned int reserved_12 : 3;
        unsigned int reserved_13 : 3;
    } reg;
} SOC_PCTRL_PERI_STAT4_UNION;
#endif
#define SOC_PCTRL_PERI_STAT4_cssys_etr_x2x_ckg_idle_START (3)
#define SOC_PCTRL_PERI_STAT4_cssys_etr_x2x_ckg_idle_END (3)
#define SOC_PCTRL_PERI_STAT4_sc_mdm_reset_stat_START (20)
#define SOC_PCTRL_PERI_STAT4_sc_mdm_reset_stat_END (20)
#define SOC_PCTRL_PERI_STAT4_pwr_dwn_ack_cdphy0_START (21)
#define SOC_PCTRL_PERI_STAT4_pwr_dwn_ack_cdphy0_END (21)
#define SOC_PCTRL_PERI_STAT4_pwr_dwn_ack_cdphy1_START (22)
#define SOC_PCTRL_PERI_STAT4_pwr_dwn_ack_cdphy1_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_mdm2ap_status : 32;
    } reg;
} SOC_PCTRL_PERI_STAT5_UNION;
#endif
#define SOC_PCTRL_PERI_STAT5_sc_mdm2ap_status_START (0)
#define SOC_PCTRL_PERI_STAT5_sc_mdm2ap_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_point_core : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_PCTRL_PERI_STAT6_UNION;
#endif
#define SOC_PCTRL_PERI_STAT6_test_point_core_START (0)
#define SOC_PCTRL_PERI_STAT6_test_point_core_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ipc_ns_gt_clk_status : 1;
        unsigned int ipc_gt_clk_status : 1;
        unsigned int ipc_rtos_ns_gt_clk_status : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_PCTRL_PERI_STAT29_UNION;
#endif
#define SOC_PCTRL_PERI_STAT29_ipc_ns_gt_clk_status_START (0)
#define SOC_PCTRL_PERI_STAT29_ipc_ns_gt_clk_status_END (0)
#define SOC_PCTRL_PERI_STAT29_ipc_gt_clk_status_START (1)
#define SOC_PCTRL_PERI_STAT29_ipc_gt_clk_status_END (1)
#define SOC_PCTRL_PERI_STAT29_ipc_rtos_ns_gt_clk_status_START (2)
#define SOC_PCTRL_PERI_STAT29_ipc_rtos_ns_gt_clk_status_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_pwrds_ack_sys2mdm : 1;
        unsigned int pdc_pwrds_ack_mdm2sys : 1;
        unsigned int pdc_pwrdm_ack_sys2mdm : 1;
        unsigned int pdc_pwrdm_ack_mdm2sys : 1;
        unsigned int pdc_pwrds_ack_mdm2ddr : 1;
        unsigned int pdc_pwrds_ack_pdea2ddr : 1;
        unsigned int pdc_pwrdm_ack_mdm2ddr : 1;
        unsigned int pdc_pwrdm_ack_pdea2ddr : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PCTRL_PERI_STAT30_UNION;
#endif
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_sys2mdm_START (0)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_sys2mdm_END (0)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_mdm2sys_START (1)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_mdm2sys_END (1)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_sys2mdm_START (2)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_sys2mdm_END (2)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_mdm2sys_START (3)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_mdm2sys_END (3)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_mdm2ddr_START (4)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_mdm2ddr_END (4)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_pdea2ddr_START (5)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrds_ack_pdea2ddr_END (5)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_mdm2ddr_START (6)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_mdm2ddr_END (6)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_pdea2ddr_START (7)
#define SOC_PCTRL_PERI_STAT30_pdc_pwrdm_ack_pdea2ddr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pds_pw_stat_sys2mdm : 3;
        unsigned int pds_pw_stat_mdm2sys : 3;
        unsigned int pdm_pw_stat_sys2mdm : 5;
        unsigned int pdm_pw_stat_mdm2sys : 5;
        unsigned int pds_pw_stat_mdm2ddr : 3;
        unsigned int pds_pw_stat_pdea2ddr : 3;
        unsigned int pdm_pw_stat_mdm2ddr : 5;
        unsigned int pdm_pw_stat_pdea2ddr : 5;
    } reg;
} SOC_PCTRL_PERI_STAT31_UNION;
#endif
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_sys2mdm_START (0)
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_sys2mdm_END (2)
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_mdm2sys_START (3)
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_mdm2sys_END (5)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_sys2mdm_START (6)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_sys2mdm_END (10)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_mdm2sys_START (11)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_mdm2sys_END (15)
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_mdm2ddr_START (16)
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_mdm2ddr_END (18)
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_pdea2ddr_START (19)
#define SOC_PCTRL_PERI_STAT31_pds_pw_stat_pdea2ddr_END (21)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_mdm2ddr_START (22)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_mdm2ddr_END (26)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_pdea2ddr_START (27)
#define SOC_PCTRL_PERI_STAT31_pdm_pw_stat_pdea2ddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out : 9;
        unsigned int reserved_0 : 7;
        unsigned int pasensor_nbti_o_out : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_PCTRL_PERI_STAT32_UNION;
#endif
#define SOC_PCTRL_PERI_STAT32_pasensor_nbti_a_out_START (0)
#define SOC_PCTRL_PERI_STAT32_pasensor_nbti_a_out_END (8)
#define SOC_PCTRL_PERI_STAT32_pasensor_nbti_o_out_START (16)
#define SOC_PCTRL_PERI_STAT32_pasensor_nbti_o_out_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out : 9;
        unsigned int reserved_0 : 7;
        unsigned int pasensor_hci_o_out : 9;
        unsigned int pasensor_cfg_ready : 1;
        unsigned int pasensor_valid : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_PCTRL_PERI_STAT33_UNION;
#endif
#define SOC_PCTRL_PERI_STAT33_pasensor_hci_a_out_START (0)
#define SOC_PCTRL_PERI_STAT33_pasensor_hci_a_out_END (8)
#define SOC_PCTRL_PERI_STAT33_pasensor_hci_o_out_START (16)
#define SOC_PCTRL_PERI_STAT33_pasensor_hci_o_out_END (24)
#define SOC_PCTRL_PERI_STAT33_pasensor_cfg_ready_START (25)
#define SOC_PCTRL_PERI_STAT33_pasensor_cfg_ready_END (25)
#define SOC_PCTRL_PERI_STAT33_pasensor_valid_START (26)
#define SOC_PCTRL_PERI_STAT33_pasensor_valid_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int req_timeout_flag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PCTRL_PERI_STAT34_UNION;
#endif
#define SOC_PCTRL_PERI_STAT34_req_timeout_flag_START (0)
#define SOC_PCTRL_PERI_STAT34_req_timeout_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdm_nopending_sys2mdm : 1;
        unsigned int pdm_nopending_mdm2sys : 1;
        unsigned int pdm_nopending_mdm2ddr : 1;
        unsigned int pdm_nopending_pdea2ddr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PCTRL_PERI_STAT35_UNION;
#endif
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_sys2mdm_START (0)
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_sys2mdm_END (0)
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_mdm2sys_START (1)
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_mdm2sys_END (1)
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_mdm2ddr_START (2)
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_mdm2ddr_END (2)
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_pdea2ddr_START (3)
#define SOC_PCTRL_PERI_STAT35_pdm_nopending_pdea2ddr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT36_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT37_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT38_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT39_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT40_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_mem_sta_mdm_bbp_nonret_poff_ctrl_stat : 16;
        unsigned int afmux_mem_sta_mdm_soc_nonret_poff_ctrl_stat : 16;
    } reg;
} SOC_PCTRL_PERI_STAT41_UNION;
#endif
#define SOC_PCTRL_PERI_STAT41_afmux_mem_sta_mdm_bbp_nonret_poff_ctrl_stat_START (0)
#define SOC_PCTRL_PERI_STAT41_afmux_mem_sta_mdm_bbp_nonret_poff_ctrl_stat_END (15)
#define SOC_PCTRL_PERI_STAT41_afmux_mem_sta_mdm_soc_nonret_poff_ctrl_stat_START (16)
#define SOC_PCTRL_PERI_STAT41_afmux_mem_sta_mdm_soc_nonret_poff_ctrl_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_mem_sta_modem_ret_poff_ctrl_stat : 32;
    } reg;
} SOC_PCTRL_PERI_STAT42_UNION;
#endif
#define SOC_PCTRL_PERI_STAT42_afmux_mem_sta_modem_ret_poff_ctrl_stat_START (0)
#define SOC_PCTRL_PERI_STAT42_afmux_mem_sta_modem_ret_poff_ctrl_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_wdt_intr_merge_stat : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_PERI_STAT43_UNION;
#endif
#define SOC_PCTRL_PERI_STAT43_mdm_wdt_intr_merge_stat_START (0)
#define SOC_PCTRL_PERI_STAT43_mdm_wdt_intr_merge_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdmqdbs_pwrd_qdbs_ack : 1;
        unsigned int mdmqdbs_qdbs_qtp_err_int : 1;
        unsigned int mdmqdbs_qic_qdbs_busy : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_PCTRL_PERI_STAT44_UNION;
#endif
#define SOC_PCTRL_PERI_STAT44_mdmqdbs_pwrd_qdbs_ack_START (0)
#define SOC_PCTRL_PERI_STAT44_mdmqdbs_pwrd_qdbs_ack_END (0)
#define SOC_PCTRL_PERI_STAT44_mdmqdbs_qdbs_qtp_err_int_START (1)
#define SOC_PCTRL_PERI_STAT44_mdmqdbs_qdbs_qtp_err_int_END (1)
#define SOC_PCTRL_PERI_STAT44_mdmqdbs_qic_qdbs_busy_START (2)
#define SOC_PCTRL_PERI_STAT44_mdmqdbs_qic_qdbs_busy_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_reserved_stat_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT45_UNION;
#endif
#define SOC_PCTRL_PERI_STAT45_pctrl_reserved_stat_0_START (0)
#define SOC_PCTRL_PERI_STAT45_pctrl_reserved_stat_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_reserved_stat_1 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT46_UNION;
#endif
#define SOC_PCTRL_PERI_STAT46_pctrl_reserved_stat_1_START (0)
#define SOC_PCTRL_PERI_STAT46_pctrl_reserved_stat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_reserved_stat_2 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT47_UNION;
#endif
#define SOC_PCTRL_PERI_STAT47_pctrl_reserved_stat_2_START (0)
#define SOC_PCTRL_PERI_STAT47_pctrl_reserved_stat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_mem_ctrl_sdo_hts : 1;
        unsigned int afmux_ddr_xctrl_mem_sdo : 1;
        unsigned int afmux_ddr_xctrl_mem_dso : 1;
        unsigned int reserved_0 : 1;
        unsigned int afmux_mem_sta_qic_peri_ram_sdo : 1;
        unsigned int afmux_mem_sta_sd_peri : 1;
        unsigned int afmux_media_xctrl_mem_sdo : 1;
        unsigned int afmux_media_xctrl_mem_dso : 1;
        unsigned int reserved_1 : 1;
        unsigned int afmux_retmem_sta_sd_dmc_pack : 4;
        unsigned int afmux_retmem_sta_ds_dmc_pack : 4;
        unsigned int afmux_mem_sdo_sdcu : 6;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
    } reg;
} SOC_PCTRL_PERI_STAT48_UNION;
#endif
#define SOC_PCTRL_PERI_STAT48_afmux_mem_ctrl_sdo_hts_START (0)
#define SOC_PCTRL_PERI_STAT48_afmux_mem_ctrl_sdo_hts_END (0)
#define SOC_PCTRL_PERI_STAT48_afmux_ddr_xctrl_mem_sdo_START (1)
#define SOC_PCTRL_PERI_STAT48_afmux_ddr_xctrl_mem_sdo_END (1)
#define SOC_PCTRL_PERI_STAT48_afmux_ddr_xctrl_mem_dso_START (2)
#define SOC_PCTRL_PERI_STAT48_afmux_ddr_xctrl_mem_dso_END (2)
#define SOC_PCTRL_PERI_STAT48_afmux_mem_sta_qic_peri_ram_sdo_START (4)
#define SOC_PCTRL_PERI_STAT48_afmux_mem_sta_qic_peri_ram_sdo_END (4)
#define SOC_PCTRL_PERI_STAT48_afmux_mem_sta_sd_peri_START (5)
#define SOC_PCTRL_PERI_STAT48_afmux_mem_sta_sd_peri_END (5)
#define SOC_PCTRL_PERI_STAT48_afmux_media_xctrl_mem_sdo_START (6)
#define SOC_PCTRL_PERI_STAT48_afmux_media_xctrl_mem_sdo_END (6)
#define SOC_PCTRL_PERI_STAT48_afmux_media_xctrl_mem_dso_START (7)
#define SOC_PCTRL_PERI_STAT48_afmux_media_xctrl_mem_dso_END (7)
#define SOC_PCTRL_PERI_STAT48_afmux_retmem_sta_sd_dmc_pack_START (9)
#define SOC_PCTRL_PERI_STAT48_afmux_retmem_sta_sd_dmc_pack_END (12)
#define SOC_PCTRL_PERI_STAT48_afmux_retmem_sta_ds_dmc_pack_START (13)
#define SOC_PCTRL_PERI_STAT48_afmux_retmem_sta_ds_dmc_pack_END (16)
#define SOC_PCTRL_PERI_STAT48_afmux_mem_sdo_sdcu_START (17)
#define SOC_PCTRL_PERI_STAT48_afmux_mem_sdo_sdcu_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpa_nonret_poff_ctrl_stat : 2;
        unsigned int mdmperi_nonret_poff_ctrl_stat : 2;
        unsigned int dpa_ret_poff_ctrl_stat : 2;
        unsigned int mdmperi_ret_poff_ctrl_stat : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_PCTRL_PERI_STAT49_UNION;
#endif
#define SOC_PCTRL_PERI_STAT49_dpa_nonret_poff_ctrl_stat_START (0)
#define SOC_PCTRL_PERI_STAT49_dpa_nonret_poff_ctrl_stat_END (1)
#define SOC_PCTRL_PERI_STAT49_mdmperi_nonret_poff_ctrl_stat_START (2)
#define SOC_PCTRL_PERI_STAT49_mdmperi_nonret_poff_ctrl_stat_END (3)
#define SOC_PCTRL_PERI_STAT49_dpa_ret_poff_ctrl_stat_START (4)
#define SOC_PCTRL_PERI_STAT49_dpa_ret_poff_ctrl_stat_END (5)
#define SOC_PCTRL_PERI_STAT49_mdmperi_ret_poff_ctrl_stat_START (6)
#define SOC_PCTRL_PERI_STAT49_mdmperi_ret_poff_ctrl_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_mem_stat_sd_dmc : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 20;
    } reg;
} SOC_PCTRL_PERI_STAT50_UNION;
#endif
#define SOC_PCTRL_PERI_STAT50_afmux_mem_stat_sd_dmc_START (0)
#define SOC_PCTRL_PERI_STAT50_afmux_mem_stat_sd_dmc_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_retmem_stat_sdo_qice : 8;
        unsigned int afmux_retmem_stat_dso_qice : 8;
        unsigned int afmux_mem_stat_sdo_qice : 1;
        unsigned int afmux_mem_stat_sdo_ffts : 1;
        unsigned int afmux_mem_stat_sdo_exmbist0 : 1;
        unsigned int afmux_mem_stat_sdo_exmbist1 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_PCTRL_PERI_STAT51_UNION;
#endif
#define SOC_PCTRL_PERI_STAT51_afmux_retmem_stat_sdo_qice_START (0)
#define SOC_PCTRL_PERI_STAT51_afmux_retmem_stat_sdo_qice_END (7)
#define SOC_PCTRL_PERI_STAT51_afmux_retmem_stat_dso_qice_START (8)
#define SOC_PCTRL_PERI_STAT51_afmux_retmem_stat_dso_qice_END (15)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_qice_START (16)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_qice_END (16)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_ffts_START (17)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_ffts_END (17)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_exmbist0_START (18)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_exmbist0_END (18)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_exmbist1_START (19)
#define SOC_PCTRL_PERI_STAT51_afmux_mem_stat_sdo_exmbist1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_mem_stat_sd_sca : 8;
        unsigned int afmux_mem_stat_sd_scb : 8;
        unsigned int afmux_mem_stat_sd_scc : 8;
        unsigned int afmux_mem_stat_sd_scd : 8;
    } reg;
} SOC_PCTRL_PERI_STAT52_UNION;
#endif
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_sca_START (0)
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_sca_END (7)
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_scb_START (8)
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_scb_END (15)
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_scc_START (16)
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_scc_END (23)
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_scd_START (24)
#define SOC_PCTRL_PERI_STAT52_afmux_mem_stat_sd_scd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rd_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT53_UNION;
#endif
#define SOC_PCTRL_PERI_STAT53_qic_rd_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT53_qic_rd_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_wr_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT54_UNION;
#endif
#define SOC_PCTRL_PERI_STAT54_qic_wr_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT54_qic_wr_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_tb_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT55_UNION;
#endif
#define SOC_PCTRL_PERI_STAT55_qic_tb_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT55_qic_tb_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdms_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT56_UNION;
#endif
#define SOC_PCTRL_PERI_STAT56_qic_pdms_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT56_qic_pdms_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_safety_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT57_UNION;
#endif
#define SOC_PCTRL_PERI_STAT57_intr_safety_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT57_intr_safety_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_safety_err_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT58_UNION;
#endif
#define SOC_PCTRL_PERI_STAT58_intr_safety_err_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT58_intr_safety_err_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_safety_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT59_UNION;
#endif
#define SOC_PCTRL_PERI_STAT59_intr_safety_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT59_intr_safety_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rd_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT60_UNION;
#endif
#define SOC_PCTRL_PERI_STAT60_qic_rd_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT60_qic_rd_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_wr_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT61_UNION;
#endif
#define SOC_PCTRL_PERI_STAT61_qic_wr_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT61_qic_wr_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_tb_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT62_UNION;
#endif
#define SOC_PCTRL_PERI_STAT62_qic_tb_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT62_qic_tb_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdms_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT63_UNION;
#endif
#define SOC_PCTRL_PERI_STAT63_qic_pdms_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT63_qic_pdms_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdms_nopending_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT64_UNION;
#endif
#define SOC_PCTRL_PERI_STAT64_qic_pdms_nopending_center_crossbar_1_START (0)
#define SOC_PCTRL_PERI_STAT64_qic_pdms_nopending_center_crossbar_1_END (31)
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
} SOC_PCTRL_PERI_STAT66_UNION;
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
        unsigned int reserved_8: 24;
    } reg;
} SOC_PCTRL_PERI_STAT67_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_retmem_stat_sdo_sca : 6;
        unsigned int afmux_retmem_stat_sdo_scb : 6;
        unsigned int afmux_retmem_stat_sdo_scc : 6;
        unsigned int afmux_retmem_stat_sdo_scd : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_PCTRL_PERI_STAT68_UNION;
#endif
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_sca_START (0)
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_sca_END (5)
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_scb_START (6)
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_scb_END (11)
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_scc_START (12)
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_scc_END (17)
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_scd_START (18)
#define SOC_PCTRL_PERI_STAT68_afmux_retmem_stat_sdo_scd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int qic_m1_comb_intr_lpmcu_acpu : 1;
        unsigned int qic_m2_comb_intr_lpmcu_acpu : 1;
        unsigned int qic_npu_comb_intr_lpmcu_acpu : 1;
        unsigned int reserved_1 : 1;
        unsigned int intr_qic_probe_hsdt0_qic : 1;
        unsigned int intr_qic_probe_hsdt1_qic : 1;
        unsigned int intr_qic_probe_gpu_qic : 1;
        unsigned int intr_qic_probe_cpu_qic : 1;
        unsigned int intr_qic_probe_cfg_dma : 1;
        unsigned int intr_qic_probe_crossbar : 1;
        unsigned int reserved_2 : 1;
        unsigned int qic_ao_comb_intr_lpmcu_acpu : 1;
        unsigned int intr_qic_probe_gpu_data_qic : 1;
        unsigned int qic_nputs_comb_intr_lpmcu_acpu : 1;
        unsigned int reserved_3 : 17;
    } reg;
} SOC_PCTRL_PERI_STAT69_UNION;
#endif
#define SOC_PCTRL_PERI_STAT69_qic_m1_comb_intr_lpmcu_acpu_START (1)
#define SOC_PCTRL_PERI_STAT69_qic_m1_comb_intr_lpmcu_acpu_END (1)
#define SOC_PCTRL_PERI_STAT69_qic_m2_comb_intr_lpmcu_acpu_START (2)
#define SOC_PCTRL_PERI_STAT69_qic_m2_comb_intr_lpmcu_acpu_END (2)
#define SOC_PCTRL_PERI_STAT69_qic_npu_comb_intr_lpmcu_acpu_START (3)
#define SOC_PCTRL_PERI_STAT69_qic_npu_comb_intr_lpmcu_acpu_END (3)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_hsdt0_qic_START (5)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_hsdt0_qic_END (5)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_hsdt1_qic_START (6)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_hsdt1_qic_END (6)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_gpu_qic_START (7)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_gpu_qic_END (7)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_cpu_qic_START (8)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_cpu_qic_END (8)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_cfg_dma_START (9)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_cfg_dma_END (9)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_crossbar_START (10)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_crossbar_END (10)
#define SOC_PCTRL_PERI_STAT69_qic_ao_comb_intr_lpmcu_acpu_START (12)
#define SOC_PCTRL_PERI_STAT69_qic_ao_comb_intr_lpmcu_acpu_END (12)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_gpu_data_qic_START (13)
#define SOC_PCTRL_PERI_STAT69_intr_qic_probe_gpu_data_qic_END (13)
#define SOC_PCTRL_PERI_STAT69_qic_nputs_comb_intr_lpmcu_acpu_START (14)
#define SOC_PCTRL_PERI_STAT69_qic_nputs_comb_intr_lpmcu_acpu_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_ddrc0_err : 1;
        unsigned int intr_ddrc1_err : 1;
        unsigned int intr_ddrc2_err : 1;
        unsigned int intr_ddrc3_err : 1;
        unsigned int intr_ddrphy : 4;
        unsigned int intr_uce0_wdog : 1;
        unsigned int intr_uce1_wdog : 1;
        unsigned int intr_uce2_wdog : 1;
        unsigned int intr_uce3_wdog : 1;
        unsigned int intr_ddrc_fatal : 4;
        unsigned int intr_ddrca0_reset : 1;
        unsigned int intr_ddrca1_reset : 1;
        unsigned int intr_ddrca2_reset : 1;
        unsigned int intr_ddrca3_reset : 1;
        unsigned int intr_ddrc0_normal : 1;
        unsigned int intr_ddrc1_normal : 1;
        unsigned int intr_ddrc2_normal : 1;
        unsigned int intr_ddrc3_normal : 1;
        unsigned int intr_uce0_rtactive : 1;
        unsigned int intr_uce1_rtactive : 1;
        unsigned int intr_uce2_rtactive : 1;
        unsigned int intr_uce3_rtactive : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_PCTRL_PERI_STAT70_UNION;
#endif
#define SOC_PCTRL_PERI_STAT70_intr_ddrc0_err_START (0)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc0_err_END (0)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc1_err_START (1)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc1_err_END (1)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc2_err_START (2)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc2_err_END (2)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc3_err_START (3)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc3_err_END (3)
#define SOC_PCTRL_PERI_STAT70_intr_ddrphy_START (4)
#define SOC_PCTRL_PERI_STAT70_intr_ddrphy_END (7)
#define SOC_PCTRL_PERI_STAT70_intr_uce0_wdog_START (8)
#define SOC_PCTRL_PERI_STAT70_intr_uce0_wdog_END (8)
#define SOC_PCTRL_PERI_STAT70_intr_uce1_wdog_START (9)
#define SOC_PCTRL_PERI_STAT70_intr_uce1_wdog_END (9)
#define SOC_PCTRL_PERI_STAT70_intr_uce2_wdog_START (10)
#define SOC_PCTRL_PERI_STAT70_intr_uce2_wdog_END (10)
#define SOC_PCTRL_PERI_STAT70_intr_uce3_wdog_START (11)
#define SOC_PCTRL_PERI_STAT70_intr_uce3_wdog_END (11)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc_fatal_START (12)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc_fatal_END (15)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca0_reset_START (16)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca0_reset_END (16)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca1_reset_START (17)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca1_reset_END (17)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca2_reset_START (18)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca2_reset_END (18)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca3_reset_START (19)
#define SOC_PCTRL_PERI_STAT70_intr_ddrca3_reset_END (19)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc0_normal_START (20)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc0_normal_END (20)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc1_normal_START (21)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc1_normal_END (21)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc2_normal_START (22)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc2_normal_END (22)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc3_normal_START (23)
#define SOC_PCTRL_PERI_STAT70_intr_ddrc3_normal_END (23)
#define SOC_PCTRL_PERI_STAT70_intr_uce0_rtactive_START (24)
#define SOC_PCTRL_PERI_STAT70_intr_uce0_rtactive_END (24)
#define SOC_PCTRL_PERI_STAT70_intr_uce1_rtactive_START (25)
#define SOC_PCTRL_PERI_STAT70_intr_uce1_rtactive_END (25)
#define SOC_PCTRL_PERI_STAT70_intr_uce2_rtactive_START (26)
#define SOC_PCTRL_PERI_STAT70_intr_uce2_rtactive_END (26)
#define SOC_PCTRL_PERI_STAT70_intr_uce3_rtactive_START (27)
#define SOC_PCTRL_PERI_STAT70_intr_uce3_rtactive_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_clkrst_status_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT71_UNION;
#endif
#define SOC_PCTRL_PERI_STAT71_qic_clkrst_status_0_START (0)
#define SOC_PCTRL_PERI_STAT71_qic_clkrst_status_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_clkrst_status_1 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT72_UNION;
#endif
#define SOC_PCTRL_PERI_STAT72_qic_clkrst_status_1_START (0)
#define SOC_PCTRL_PERI_STAT72_qic_clkrst_status_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT73_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_gpu_mtcmos_ack : 1;
        unsigned int dpa_mtcmos_ack : 1;
        unsigned int sdcu_mtcmos_ack : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_PCTRL_PERI_STAT74_UNION;
#endif
#define SOC_PCTRL_PERI_STAT74_qice_gpu_mtcmos_ack_START (0)
#define SOC_PCTRL_PERI_STAT74_qice_gpu_mtcmos_ack_END (0)
#define SOC_PCTRL_PERI_STAT74_dpa_mtcmos_ack_START (1)
#define SOC_PCTRL_PERI_STAT74_dpa_mtcmos_ack_END (1)
#define SOC_PCTRL_PERI_STAT74_sdcu_mtcmos_ack_START (2)
#define SOC_PCTRL_PERI_STAT74_sdcu_mtcmos_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT75_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT76_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT77_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rt_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT78_UNION;
#endif
#define SOC_PCTRL_PERI_STAT78_qic_rt_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT78_qic_rt_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rt_nopending_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT79_UNION;
#endif
#define SOC_PCTRL_PERI_STAT79_qic_rt_nopending_center_crossbar_1_START (0)
#define SOC_PCTRL_PERI_STAT79_qic_rt_nopending_center_crossbar_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_rt_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT80_UNION;
#endif
#define SOC_PCTRL_PERI_STAT80_qic_rt_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT80_qic_rt_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_safety_err_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT81_UNION;
#endif
#define SOC_PCTRL_PERI_STAT81_intr_safety_err_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT81_intr_safety_err_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT82_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT83_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT84_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT85_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT86_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT87_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT88_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT89_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT90_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT91_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT92_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpa_wakeup_irqs_stat : 32;
    } reg;
} SOC_PCTRL_PERI_STAT93_UNION;
#endif
#define SOC_PCTRL_PERI_STAT93_dpa_wakeup_irqs_stat_START (0)
#define SOC_PCTRL_PERI_STAT93_dpa_wakeup_irqs_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp0_wakeup_irps_grp_stat : 32;
    } reg;
} SOC_PCTRL_PERI_STAT94_UNION;
#endif
#define SOC_PCTRL_PERI_STAT94_tsp0_wakeup_irps_grp_stat_START (0)
#define SOC_PCTRL_PERI_STAT94_tsp0_wakeup_irps_grp_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp0_wakeup_irps_stat_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT95_UNION;
#endif
#define SOC_PCTRL_PERI_STAT95_tsp0_wakeup_irps_stat_0_START (0)
#define SOC_PCTRL_PERI_STAT95_tsp0_wakeup_irps_stat_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp0_wakeup_irps_stat_1 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT96_UNION;
#endif
#define SOC_PCTRL_PERI_STAT96_tsp0_wakeup_irps_stat_1_START (0)
#define SOC_PCTRL_PERI_STAT96_tsp0_wakeup_irps_stat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT97_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT98_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT99_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT100_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT101_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT102_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT103_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT104_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT105_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT106_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT107_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT108_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT109_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT110_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT111_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT112_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT113_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT114_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT115_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT116_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT117_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT118_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT119_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT120_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT121_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT122_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT123_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT124_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT125_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT126_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp0_wakeup_intr_comb_stat : 1;
        unsigned int dpa_wakeup_intr_comb_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_PERI_STAT127_UNION;
#endif
#define SOC_PCTRL_PERI_STAT127_tsp0_wakeup_intr_comb_stat_START (0)
#define SOC_PCTRL_PERI_STAT127_tsp0_wakeup_intr_comb_stat_END (0)
#define SOC_PCTRL_PERI_STAT127_dpa_wakeup_intr_comb_stat_START (1)
#define SOC_PCTRL_PERI_STAT127_dpa_wakeup_intr_comb_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT128_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_pktc_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT129_UNION;
#endif
#define SOC_PCTRL_PERI_STAT129_intr_pktc_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT129_intr_pktc_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_em_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT130_UNION;
#endif
#define SOC_PCTRL_PERI_STAT130_intr_em_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT130_intr_em_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT131_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_pktc_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT132_UNION;
#endif
#define SOC_PCTRL_PERI_STAT132_intr_pktc_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT132_intr_pktc_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_em_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT133_UNION;
#endif
#define SOC_PCTRL_PERI_STAT133_intr_em_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT133_intr_em_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT134_UNION;
#endif
#define SOC_PCTRL_PERI_STAT134_qic_timeout_st_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT134_qic_timeout_st_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_7 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT135_UNION;
#endif
#define SOC_PCTRL_PERI_STAT135_qic_pdm_state_pdm_center_crossbar_7_START (0)
#define SOC_PCTRL_PERI_STAT135_qic_pdm_state_pdm_center_crossbar_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT136_UNION;
#endif
#define SOC_PCTRL_PERI_STAT136_qic_timeout_st_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT136_qic_timeout_st_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT137_UNION;
#endif
#define SOC_PCTRL_PERI_STAT137_qic_pdm_state_pdm_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT137_qic_pdm_state_pdm_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT138_UNION;
#endif
#define SOC_PCTRL_PERI_STAT138_qic_pdm_state_pdm_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT138_qic_pdm_state_pdm_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT139_UNION;
#endif
#define SOC_PCTRL_PERI_STAT139_qic_pdm_state_pdm_center_crossbar_1_START (0)
#define SOC_PCTRL_PERI_STAT139_qic_pdm_state_pdm_center_crossbar_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_2 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT140_UNION;
#endif
#define SOC_PCTRL_PERI_STAT140_qic_pdm_state_pdm_center_crossbar_2_START (0)
#define SOC_PCTRL_PERI_STAT140_qic_pdm_state_pdm_center_crossbar_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_3 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT141_UNION;
#endif
#define SOC_PCTRL_PERI_STAT141_qic_pdm_state_pdm_center_crossbar_3_START (0)
#define SOC_PCTRL_PERI_STAT141_qic_pdm_state_pdm_center_crossbar_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_4 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT142_UNION;
#endif
#define SOC_PCTRL_PERI_STAT142_qic_pdm_state_pdm_center_crossbar_4_START (0)
#define SOC_PCTRL_PERI_STAT142_qic_pdm_state_pdm_center_crossbar_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_5 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT143_UNION;
#endif
#define SOC_PCTRL_PERI_STAT143_qic_pdm_state_pdm_center_crossbar_5_START (0)
#define SOC_PCTRL_PERI_STAT143_qic_pdm_state_pdm_center_crossbar_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_center_crossbar_6 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT144_UNION;
#endif
#define SOC_PCTRL_PERI_STAT144_qic_pdm_state_pdm_center_crossbar_6_START (0)
#define SOC_PCTRL_PERI_STAT144_qic_pdm_state_pdm_center_crossbar_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT145_UNION;
#endif
#define SOC_PCTRL_PERI_STAT145_qic_pds_state_pds_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_STAT145_qic_pds_state_pds_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT146_UNION;
#endif
#define SOC_PCTRL_PERI_STAT146_qic_pds_state_pds_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_STAT146_qic_pds_state_pds_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT147_UNION;
#endif
#define SOC_PCTRL_PERI_STAT147_qic_pds_state_pds_center_crossbar_1_START (0)
#define SOC_PCTRL_PERI_STAT147_qic_pds_state_pds_center_crossbar_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_center_crossbar_2 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT148_UNION;
#endif
#define SOC_PCTRL_PERI_STAT148_qic_pds_state_pds_center_crossbar_2_START (0)
#define SOC_PCTRL_PERI_STAT148_qic_pds_state_pds_center_crossbar_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_center_crossbar_3 : 32;
    } reg;
} SOC_PCTRL_PERI_STAT149_UNION;
#endif
#define SOC_PCTRL_PERI_STAT149_qic_pds_state_pds_center_crossbar_3_START (0)
#define SOC_PCTRL_PERI_STAT149_qic_pds_state_pds_center_crossbar_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_cfg_dma_0_aftmsk : 32;
    } reg;
} SOC_PCTRL_PERI_STAT150_UNION;
#endif
#define SOC_PCTRL_PERI_STAT150_qic_timeout_st_cfg_dma_0_aftmsk_START (0)
#define SOC_PCTRL_PERI_STAT150_qic_timeout_st_cfg_dma_0_aftmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_center_crossbar_0_aftmsk : 32;
    } reg;
} SOC_PCTRL_PERI_STAT151_UNION;
#endif
#define SOC_PCTRL_PERI_STAT151_qic_timeout_st_center_crossbar_0_aftmsk_START (0)
#define SOC_PCTRL_PERI_STAT151_qic_timeout_st_center_crossbar_0_aftmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT152_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT153_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT154_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT155_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_PCTRL_PERI_STAT156_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prog_stat_a : 8;
        unsigned int uce_prog_stat_b : 8;
        unsigned int uce_prog_stat_c : 8;
        unsigned int uce_prog_stat_d : 8;
    } reg;
} SOC_PCTRL_PERI_STAT157_UNION;
#endif
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_a_START (0)
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_a_END (7)
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_b_START (8)
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_b_END (15)
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_c_START (16)
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_c_END (23)
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_d_START (24)
#define SOC_PCTRL_PERI_STAT157_uce_prog_stat_d_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT158_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_STAT159_UNION;
#endif
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
        unsigned int qtpe_icfg_ckg_rs_byp : 1;
        unsigned int cssys_etr_x2x_ckg_en : 1;
        unsigned int reserved_6 : 1;
        unsigned int h2p_ckg_en_qicecfg : 1;
        unsigned int h2h_ckg_en_dmc : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 4;
        unsigned int PERI_CTRL0_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL0_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL0_qtpe_icfg_ckg_rs_byp_START (6)
#define SOC_PCTRL_PERI_CTRL0_qtpe_icfg_ckg_rs_byp_END (6)
#define SOC_PCTRL_PERI_CTRL0_cssys_etr_x2x_ckg_en_START (7)
#define SOC_PCTRL_PERI_CTRL0_cssys_etr_x2x_ckg_en_END (7)
#define SOC_PCTRL_PERI_CTRL0_h2p_ckg_en_qicecfg_START (9)
#define SOC_PCTRL_PERI_CTRL0_h2p_ckg_en_qicecfg_END (9)
#define SOC_PCTRL_PERI_CTRL0_h2h_ckg_en_dmc_START (10)
#define SOC_PCTRL_PERI_CTRL0_h2h_ckg_en_dmc_END (10)
#define SOC_PCTRL_PERI_CTRL0_PERI_CTRL0_msk_START (16)
#define SOC_PCTRL_PERI_CTRL0_PERI_CTRL0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_point_sel_for_core : 6;
        unsigned int test_point_sel_for_peri : 4;
        unsigned int reserved : 6;
        unsigned int peri_ctrl1_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL1_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL1_test_point_sel_for_core_START (0)
#define SOC_PCTRL_PERI_CTRL1_test_point_sel_for_core_END (5)
#define SOC_PCTRL_PERI_CTRL1_test_point_sel_for_peri_START (6)
#define SOC_PCTRL_PERI_CTRL1_test_point_sel_for_peri_END (9)
#define SOC_PCTRL_PERI_CTRL1_peri_ctrl1_msk_START (16)
#define SOC_PCTRL_PERI_CTRL1_peri_ctrl1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_mem_ctrl_sd_dmc_pack : 4;
        unsigned int bfmux_dmc_d_ret_mem_ds_in : 1;
        unsigned int bfmux_dmc_c_ret_mem_ds_in : 1;
        unsigned int bfmux_dmc_b_ret_mem_ds_in : 1;
        unsigned int bfmux_dmc_a_ret_mem_ds_in : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 2;
        unsigned int peri_ctrl2_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL2_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL2_bfmux_mem_ctrl_sd_dmc_pack_START (0)
#define SOC_PCTRL_PERI_CTRL2_bfmux_mem_ctrl_sd_dmc_pack_END (3)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_d_ret_mem_ds_in_START (4)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_d_ret_mem_ds_in_END (4)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_c_ret_mem_ds_in_START (5)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_c_ret_mem_ds_in_END (5)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_b_ret_mem_ds_in_START (6)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_b_ret_mem_ds_in_END (6)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_a_ret_mem_ds_in_START (7)
#define SOC_PCTRL_PERI_CTRL2_bfmux_dmc_a_ret_mem_ds_in_END (7)
#define SOC_PCTRL_PERI_CTRL2_peri_ctrl2_msk_START (16)
#define SOC_PCTRL_PERI_CTRL2_peri_ctrl2_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_pctrl_mem_ctrl_sd_qice : 1;
        unsigned int bfmux_pctrl_mem_ctrl_sd_ffts : 1;
        unsigned int bfmux_mem_ctrl_sd_exmb0 : 1;
        unsigned int bfmux_mem_ctrl_sd_exmb1 : 1;
        unsigned int bfmux_mem_ctrl_sd_hts : 1;
        unsigned int bfmux_mem_ctrl_sd_bootroom : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int bfmux_pctrl_retmem_ctrl_ds_qice : 8;
        unsigned int peri_ctrl3_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL3_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL3_bfmux_pctrl_mem_ctrl_sd_qice_START (0)
#define SOC_PCTRL_PERI_CTRL3_bfmux_pctrl_mem_ctrl_sd_qice_END (0)
#define SOC_PCTRL_PERI_CTRL3_bfmux_pctrl_mem_ctrl_sd_ffts_START (1)
#define SOC_PCTRL_PERI_CTRL3_bfmux_pctrl_mem_ctrl_sd_ffts_END (1)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_exmb0_START (2)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_exmb0_END (2)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_exmb1_START (3)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_exmb1_END (3)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_hts_START (4)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_hts_END (4)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_bootroom_START (5)
#define SOC_PCTRL_PERI_CTRL3_bfmux_mem_ctrl_sd_bootroom_END (5)
#define SOC_PCTRL_PERI_CTRL3_bfmux_pctrl_retmem_ctrl_ds_qice_START (8)
#define SOC_PCTRL_PERI_CTRL3_bfmux_pctrl_retmem_ctrl_ds_qice_END (15)
#define SOC_PCTRL_PERI_CTRL3_peri_ctrl3_msk_START (16)
#define SOC_PCTRL_PERI_CTRL3_peri_ctrl3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_mem_ctrl_sd_peri : 1;
        unsigned int bfmux_mem_ctrl_sd_dsi2 : 1;
        unsigned int bfmux_mem_ctrl_sd_dsi1 : 1;
        unsigned int bfmux_mem_ctrl_sd_dsi0 : 1;
        unsigned int bfmux_mem_ctrl_sd_mdmperi : 1;
        unsigned int bfmux_mem_ctrl_sd_sdcu : 6;
        unsigned int reserved : 5;
        unsigned int peri_ctrl102_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL102_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_peri_START (0)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_peri_END (0)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_dsi2_START (1)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_dsi2_END (1)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_dsi1_START (2)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_dsi1_END (2)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_dsi0_START (3)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_dsi0_END (3)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_mdmperi_START (4)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_mdmperi_END (4)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_sdcu_START (5)
#define SOC_PCTRL_PERI_CTRL102_bfmux_mem_ctrl_sd_sdcu_END (10)
#define SOC_PCTRL_PERI_CTRL102_peri_ctrl102_msk_START (16)
#define SOC_PCTRL_PERI_CTRL102_peri_ctrl102_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_rom_ctrl_sd_dmc_pack_a : 1;
        unsigned int bfmux_rom_ctrl_sd_dmc_pack_b : 1;
        unsigned int bfmux_rom_ctrl_sd_dmc_pack_c : 1;
        unsigned int bfmux_rom_ctrl_sd_dmc_pack_d : 1;
        unsigned int reserved : 12;
        unsigned int peri_ctrl103_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL103_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_a_START (0)
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_a_END (0)
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_b_START (1)
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_b_END (1)
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_c_START (2)
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_c_END (2)
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_d_START (3)
#define SOC_PCTRL_PERI_CTRL103_bfmux_rom_ctrl_sd_dmc_pack_d_END (3)
#define SOC_PCTRL_PERI_CTRL103_peri_ctrl103_msk_START (16)
#define SOC_PCTRL_PERI_CTRL103_peri_ctrl103_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_cfg_valid : 1;
        unsigned int pasensor_cmd : 2;
        unsigned int pasensor_en : 1;
        unsigned int pasensor_ctrl : 6;
        unsigned int reserved : 6;
        unsigned int peri_ctrl105_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL105_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL105_pasensor_cfg_valid_START (0)
#define SOC_PCTRL_PERI_CTRL105_pasensor_cfg_valid_END (0)
#define SOC_PCTRL_PERI_CTRL105_pasensor_cmd_START (1)
#define SOC_PCTRL_PERI_CTRL105_pasensor_cmd_END (2)
#define SOC_PCTRL_PERI_CTRL105_pasensor_en_START (3)
#define SOC_PCTRL_PERI_CTRL105_pasensor_en_END (3)
#define SOC_PCTRL_PERI_CTRL105_pasensor_ctrl_START (4)
#define SOC_PCTRL_PERI_CTRL105_pasensor_ctrl_END (9)
#define SOC_PCTRL_PERI_CTRL105_peri_ctrl105_msk_START (16)
#define SOC_PCTRL_PERI_CTRL105_peri_ctrl105_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_msg : 16;
        unsigned int peri_ctrl106_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL106_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL106_pasensor_msg_START (0)
#define SOC_PCTRL_PERI_CTRL106_pasensor_msg_END (15)
#define SOC_PCTRL_PERI_CTRL106_peri_ctrl106_msk_START (16)
#define SOC_PCTRL_PERI_CTRL106_peri_ctrl106_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL107_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rd_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL176_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL176_WC_wc_qic_rd_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_CTRL176_WC_wc_qic_rd_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_wr_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL177_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL177_WC_wc_qic_wr_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_CTRL177_WC_wc_qic_wr_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_tb_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL178_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL178_WC_wc_qic_tb_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_CTRL178_WC_wc_qic_tb_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdms_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL179_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL179_WC_wc_qic_pdms_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_CTRL179_WC_wc_qic_pdms_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_safety_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL180_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL180_WC_wc_intr_safety_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_CTRL180_WC_wc_intr_safety_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_safety_err_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL181_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL181_WC_wc_intr_safety_err_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_CTRL181_WC_wc_intr_safety_err_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_safety_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL182_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL182_WC_wc_intr_safety_cfg_dma_0_START (0)
#define SOC_PCTRL_PERI_CTRL182_WC_wc_intr_safety_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rd_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL183_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL183_WC_wc_qic_rd_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_CTRL183_WC_wc_qic_rd_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_wr_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL184_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL184_WC_wc_qic_wr_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_CTRL184_WC_wc_qic_wr_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_tb_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL185_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL185_WC_wc_qic_tb_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_CTRL185_WC_wc_qic_tb_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdms_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL186_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL186_WC_wc_qic_pdms_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_PERI_CTRL186_WC_wc_qic_pdms_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdms_nopending_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL187_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL187_WC_wc_qic_pdms_nopending_center_crossbar_1_START (0)
#define SOC_PCTRL_PERI_CTRL187_WC_wc_qic_pdms_nopending_center_crossbar_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_sc_pmc_qic_power_idle_ack0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL188_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL188_WC_wc_sc_pmc_qic_power_idle_ack0_START (0)
#define SOC_PCTRL_PERI_CTRL188_WC_wc_sc_pmc_qic_power_idle_ack0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_sc_pmc_qic_power_idle_req0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL189_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL189_WC_wc_sc_pmc_qic_power_idle_req0_START (0)
#define SOC_PCTRL_PERI_CTRL189_WC_wc_sc_pmc_qic_power_idle_req0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL190_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_gpu_mtcmos_en : 1;
        unsigned int sdcu_mtcmos_en : 1;
        unsigned int dpa_mtcmos_en : 1;
        unsigned int dpa_iso_en : 1;
        unsigned int sdcu_iso_en : 1;
        unsigned int sdcu_top_iso_en : 1;
        unsigned int reserved : 10;
        unsigned int peri_ctrl191_mask : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL191_MTCMOS_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_qice_gpu_mtcmos_en_START (0)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_qice_gpu_mtcmos_en_END (0)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_sdcu_mtcmos_en_START (1)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_sdcu_mtcmos_en_END (1)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_dpa_mtcmos_en_START (2)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_dpa_mtcmos_en_END (2)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_dpa_iso_en_START (3)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_dpa_iso_en_END (3)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_sdcu_iso_en_START (4)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_sdcu_iso_en_END (4)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_sdcu_top_iso_en_START (5)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_sdcu_top_iso_en_END (5)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_peri_ctrl191_mask_START (16)
#define SOC_PCTRL_PERI_CTRL191_MTCMOS_peri_ctrl191_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_noc_stat0_topctrl : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL192_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL192_WC_wc_noc_stat0_topctrl_START (0)
#define SOC_PCTRL_PERI_CTRL192_WC_wc_noc_stat0_topctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_noc_stat1_topctrl : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL193_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL193_WC_wc_noc_stat1_topctrl_START (0)
#define SOC_PCTRL_PERI_CTRL193_WC_wc_noc_stat1_topctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_noc_stat2_topctrl : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL194_WC_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL194_WC_wc_noc_stat2_topctrl_START (0)
#define SOC_PCTRL_PERI_CTRL194_WC_wc_noc_stat2_topctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_pktc_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL0_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL0_WC_wc_intr_pktc_cfg_dma_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL0_WC_wc_intr_pktc_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_em_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL1_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL1_WC_wc_intr_em_cfg_dma_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL1_WC_wc_intr_em_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_safety_err_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL2_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL2_WC_wc_intr_safety_err_cfg_dma_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL2_WC_wc_intr_safety_err_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_pktc_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL3_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL3_WC_wc_intr_pktc_center_crossbar_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL3_WC_wc_intr_pktc_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_em_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL4_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL4_WC_wc_intr_em_center_crossbar_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL4_WC_wc_intr_em_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL5_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL5_WC_wc_qic_timeout_st_cfg_dma_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL5_WC_wc_qic_timeout_st_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_7 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL6_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL6_WC_wc_qic_pdm_state_pdm_center_crossbar_7_START (0)
#define SOC_PCTRL_R2_PERI_CTRL6_WC_wc_qic_pdm_state_pdm_center_crossbar_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL7_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL7_WC_wc_qic_timeout_st_center_crossbar_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL7_WC_wc_qic_timeout_st_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL8_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL8_WC_wc_qic_pdm_state_pdm_cfg_dma_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL8_WC_wc_qic_pdm_state_pdm_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL9_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL9_WC_wc_qic_pdm_state_pdm_center_crossbar_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL9_WC_wc_qic_pdm_state_pdm_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL10_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL10_WC_wc_qic_pdm_state_pdm_center_crossbar_1_START (0)
#define SOC_PCTRL_R2_PERI_CTRL10_WC_wc_qic_pdm_state_pdm_center_crossbar_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_2 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL11_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL11_WC_wc_qic_pdm_state_pdm_center_crossbar_2_START (0)
#define SOC_PCTRL_R2_PERI_CTRL11_WC_wc_qic_pdm_state_pdm_center_crossbar_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_3 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL12_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL12_WC_wc_qic_pdm_state_pdm_center_crossbar_3_START (0)
#define SOC_PCTRL_R2_PERI_CTRL12_WC_wc_qic_pdm_state_pdm_center_crossbar_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_4 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL13_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL13_WC_wc_qic_pdm_state_pdm_center_crossbar_4_START (0)
#define SOC_PCTRL_R2_PERI_CTRL13_WC_wc_qic_pdm_state_pdm_center_crossbar_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_5 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL14_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL14_WC_wc_qic_pdm_state_pdm_center_crossbar_5_START (0)
#define SOC_PCTRL_R2_PERI_CTRL14_WC_wc_qic_pdm_state_pdm_center_crossbar_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_center_crossbar_6 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL15_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL15_WC_wc_qic_pdm_state_pdm_center_crossbar_6_START (0)
#define SOC_PCTRL_R2_PERI_CTRL15_WC_wc_qic_pdm_state_pdm_center_crossbar_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL16_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL16_WC_wc_qic_pds_state_pds_cfg_dma_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL16_WC_wc_qic_pds_state_pds_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL17_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL17_WC_wc_qic_pds_state_pds_center_crossbar_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL17_WC_wc_qic_pds_state_pds_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL18_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL18_WC_wc_qic_pds_state_pds_center_crossbar_1_START (0)
#define SOC_PCTRL_R2_PERI_CTRL18_WC_wc_qic_pds_state_pds_center_crossbar_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_center_crossbar_2 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL19_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL19_WC_wc_qic_pds_state_pds_center_crossbar_2_START (0)
#define SOC_PCTRL_R2_PERI_CTRL19_WC_wc_qic_pds_state_pds_center_crossbar_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_center_crossbar_3 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL20_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL20_WC_wc_qic_pds_state_pds_center_crossbar_3_START (0)
#define SOC_PCTRL_R2_PERI_CTRL20_WC_wc_qic_pds_state_pds_center_crossbar_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_qic_probe_cfg_dma : 1;
        unsigned int wc_intr_qic_probe_crossbar : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL21_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL21_WC_wc_intr_qic_probe_cfg_dma_START (0)
#define SOC_PCTRL_R2_PERI_CTRL21_WC_wc_intr_qic_probe_cfg_dma_END (0)
#define SOC_PCTRL_R2_PERI_CTRL21_WC_wc_intr_qic_probe_crossbar_START (1)
#define SOC_PCTRL_R2_PERI_CTRL21_WC_wc_intr_qic_probe_crossbar_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL22_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL23_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rt_nopending_center_crossbar_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL24_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL24_WC_wc_qic_rt_nopending_center_crossbar_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL24_WC_wc_qic_rt_nopending_center_crossbar_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rt_nopending_center_crossbar_1 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL25_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL25_WC_wc_qic_rt_nopending_center_crossbar_1_START (0)
#define SOC_PCTRL_R2_PERI_CTRL25_WC_wc_qic_rt_nopending_center_crossbar_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_rt_nopending_cfg_dma_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL26_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL26_WC_wc_qic_rt_nopending_cfg_dma_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL26_WC_wc_qic_rt_nopending_cfg_dma_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_clkrst_status_0 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL27_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL27_WC_wc_qic_clkrst_status_0_START (0)
#define SOC_PCTRL_R2_PERI_CTRL27_WC_wc_qic_clkrst_status_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_clkrst_status_1 : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL28_WC_UNION;
#endif
#define SOC_PCTRL_R2_PERI_CTRL28_WC_wc_qic_clkrst_status_1_START (0)
#define SOC_PCTRL_R2_PERI_CTRL28_WC_wc_qic_clkrst_status_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL29_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL30_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL31_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL32_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL33_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL34_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL35_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL36_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL37_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL38_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL39_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL40_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL41_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL42_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL43_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL44_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL45_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL46_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL47_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL48_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL49_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL50_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL51_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL52_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL53_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL54_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL55_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL56_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL57_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL58_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_R2_PERI_CTRL59_WC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpa_nonret_mem_ds_pctrl : 1;
        unsigned int dpa_nonret_mem_sd_pctrl : 1;
        unsigned int reserved : 14;
        unsigned int peri_ctrl195_mask : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL_195_NS_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL_195_NS_dpa_nonret_mem_ds_pctrl_START (0)
#define SOC_PCTRL_PERI_CTRL_195_NS_dpa_nonret_mem_ds_pctrl_END (0)
#define SOC_PCTRL_PERI_CTRL_195_NS_dpa_nonret_mem_sd_pctrl_START (1)
#define SOC_PCTRL_PERI_CTRL_195_NS_dpa_nonret_mem_sd_pctrl_END (1)
#define SOC_PCTRL_PERI_CTRL_195_NS_peri_ctrl195_mask_START (16)
#define SOC_PCTRL_PERI_CTRL_195_NS_peri_ctrl195_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_cfg_dma_msk_low : 16;
        unsigned int qic_timeout_st_cfg_dma_msk_low_msk : 16;
    } reg;
} SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_LOW_UNION;
#endif
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_LOW_qic_timeout_st_cfg_dma_msk_low_START (0)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_LOW_qic_timeout_st_cfg_dma_msk_low_END (15)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_LOW_qic_timeout_st_cfg_dma_msk_low_msk_START (16)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_LOW_qic_timeout_st_cfg_dma_msk_low_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_cfg_dma_msk_high : 16;
        unsigned int qic_timeout_st_cfg_dma_msk_high_msk : 16;
    } reg;
} SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_HIGH_UNION;
#endif
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_HIGH_qic_timeout_st_cfg_dma_msk_high_START (0)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_HIGH_qic_timeout_st_cfg_dma_msk_high_END (15)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_HIGH_qic_timeout_st_cfg_dma_msk_high_msk_START (16)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CFG_DMA_MSK_HIGH_qic_timeout_st_cfg_dma_msk_high_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_ack_dbg_en_cfg_dma : 1;
        unsigned int pwrd_ack_dbg_en_cc : 1;
        unsigned int reserved : 14;
        unsigned int qic_dbg_en_ns_msk : 16;
    } reg;
} SOC_PCTRL_QIC_DBG_EN_NS_MSK_UNION;
#endif
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_pwrd_ack_dbg_en_cfg_dma_START (0)
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_pwrd_ack_dbg_en_cfg_dma_END (0)
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_pwrd_ack_dbg_en_cc_START (1)
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_pwrd_ack_dbg_en_cc_END (1)
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_qic_dbg_en_ns_msk_START (16)
#define SOC_PCTRL_QIC_DBG_EN_NS_MSK_qic_dbg_en_ns_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_cc_msk_low : 16;
        unsigned int qic_timeout_st_cc_msk_low_msk : 16;
    } reg;
} SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_LOW_UNION;
#endif
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_LOW_qic_timeout_st_cc_msk_low_START (0)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_LOW_qic_timeout_st_cc_msk_low_END (15)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_LOW_qic_timeout_st_cc_msk_low_msk_START (16)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_LOW_qic_timeout_st_cc_msk_low_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_cc_msk_high : 16;
        unsigned int qic_timeout_st_cc_msk_high_msk : 16;
    } reg;
} SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_HIGH_UNION;
#endif
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_HIGH_qic_timeout_st_cc_msk_high_START (0)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_HIGH_qic_timeout_st_cc_msk_high_END (15)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_HIGH_qic_timeout_st_cc_msk_high_msk_START (16)
#define SOC_PCTRL_QIC_TIMEOUT_ST_CC_MSK_HIGH_qic_timeout_st_cc_msk_high_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_lock_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PCTRL_PERI_CTRL5_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL5_soft_lock_dis_START (0)
#define SOC_PCTRL_PERI_CTRL5_soft_lock_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_en_ddrxctrl_h2p : 1;
        unsigned int ckg_en_ddrxctrl_minibus : 1;
        unsigned int reserved : 14;
        unsigned int peri_ctrl6_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL6_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL6_ckg_en_ddrxctrl_h2p_START (0)
#define SOC_PCTRL_PERI_CTRL6_ckg_en_ddrxctrl_h2p_END (0)
#define SOC_PCTRL_PERI_CTRL6_ckg_en_ddrxctrl_minibus_START (1)
#define SOC_PCTRL_PERI_CTRL6_ckg_en_ddrxctrl_minibus_END (1)
#define SOC_PCTRL_PERI_CTRL6_peri_ctrl6_msk_START (16)
#define SOC_PCTRL_PERI_CTRL6_peri_ctrl6_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ipc_gt_clk_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PCTRL_PERI_CTRL7_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL7_ipc_gt_clk_bypass_START (0)
#define SOC_PCTRL_PERI_CTRL7_ipc_gt_clk_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int counter_unify_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PCTRL_PERI_CTRL8_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL8_counter_unify_en_START (0)
#define SOC_PCTRL_PERI_CTRL8_counter_unify_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chnl_radio_rd_sel : 2;
        unsigned int chnl_radio_wr_en : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_PCTRL_PERI_CTRL9_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL9_chnl_radio_rd_sel_START (0)
#define SOC_PCTRL_PERI_CTRL9_chnl_radio_rd_sel_END (1)
#define SOC_PCTRL_PERI_CTRL9_chnl_radio_wr_en_START (2)
#define SOC_PCTRL_PERI_CTRL9_chnl_radio_wr_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_PCTRL_PERI_CTRL10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_pwrds_req_sys2mdm : 1;
        unsigned int pdc_pwrds_req_mdm2sys : 1;
        unsigned int pdc_pwrdm_req_sys2mdm : 1;
        unsigned int pdc_pwrdm_req_mdm2sys : 1;
        unsigned int pdc_pwrds_req_mdm2ddr : 1;
        unsigned int pdc_pwrds_req_pdea2ddr : 1;
        unsigned int pdc_pwrdm_req_mdm2ddr : 1;
        unsigned int pdc_pwrdm_req_pdea2ddr : 1;
        unsigned int reserved : 8;
        unsigned int peri_ctrl11_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL11_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_sys2mdm_START (0)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_sys2mdm_END (0)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_mdm2sys_START (1)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_mdm2sys_END (1)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_sys2mdm_START (2)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_sys2mdm_END (2)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_mdm2sys_START (3)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_mdm2sys_END (3)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_mdm2ddr_START (4)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_mdm2ddr_END (4)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_pdea2ddr_START (5)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrds_req_pdea2ddr_END (5)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_mdm2ddr_START (6)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_mdm2ddr_END (6)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_pdea2ddr_START (7)
#define SOC_PCTRL_PERI_CTRL11_pdc_pwrdm_req_pdea2ddr_END (7)
#define SOC_PCTRL_PERI_CTRL11_peri_ctrl11_msk_START (16)
#define SOC_PCTRL_PERI_CTRL11_peri_ctrl11_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hard_volt_low : 1;
        unsigned int hard_volt_high : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PCTRL_PERI_CTRL34_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL34_hard_volt_low_START (0)
#define SOC_PCTRL_PERI_CTRL34_hard_volt_low_END (0)
#define SOC_PCTRL_PERI_CTRL34_hard_volt_high_START (1)
#define SOC_PCTRL_PERI_CTRL34_hard_volt_high_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomux_sel_peri : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL35_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL35_iomux_sel_peri_START (0)
#define SOC_PCTRL_PERI_CTRL35_iomux_sel_peri_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_reset_io_pctrl : 15;
        unsigned int ddr_reset_io_to : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL38_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL38_ddr_reset_io_pctrl_START (0)
#define SOC_PCTRL_PERI_CTRL38_ddr_reset_io_pctrl_END (14)
#define SOC_PCTRL_PERI_CTRL38_ddr_reset_io_to_START (15)
#define SOC_PCTRL_PERI_CTRL38_ddr_reset_io_to_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uid_check_bypass : 1;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 6;
        unsigned int reserved_3 : 6;
        unsigned int reserved_4 : 6;
        unsigned int reserved_5 : 2;
    } reg;
} SOC_PCTRL_PERI_CTRL39_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL39_uid_check_bypass_START (0)
#define SOC_PCTRL_PERI_CTRL39_uid_check_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 24;
    } reg;
} SOC_PCTRL_PERI_CTRL40_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int psw_test_mux : 4;
        unsigned int ocldo_test_mux : 3;
        unsigned int reserved : 25;
    } reg;
} SOC_PCTRL_PERI_CTRL41_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL41_psw_test_mux_START (0)
#define SOC_PCTRL_PERI_CTRL41_psw_test_mux_END (3)
#define SOC_PCTRL_PERI_CTRL41_ocldo_test_mux_START (4)
#define SOC_PCTRL_PERI_CTRL41_ocldo_test_mux_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_PCTRL_PERI_CTRL42_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_PCTRL_PERI_CTRL43_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_PCTRL_PERI_CTRL44_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL45_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_slp_req_external_a : 1;
        unsigned int ddr_slp_req_external_b : 1;
        unsigned int ddr_slp_req_external_c : 1;
        unsigned int ddr_slp_req_external_d : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PCTRL_PERI_CTRL46_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_a_START (0)
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_a_END (0)
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_b_START (1)
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_b_END (1)
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_c_START (2)
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_c_END (2)
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_d_START (3)
#define SOC_PCTRL_PERI_CTRL46_ddr_slp_req_external_d_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_mem_ctrl_sd_sca : 8;
        unsigned int bfmux_mem_ctrl_sd_scb : 8;
        unsigned int peri_ctrl47_mask : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL47_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL47_bfmux_mem_ctrl_sd_sca_START (0)
#define SOC_PCTRL_PERI_CTRL47_bfmux_mem_ctrl_sd_sca_END (7)
#define SOC_PCTRL_PERI_CTRL47_bfmux_mem_ctrl_sd_scb_START (8)
#define SOC_PCTRL_PERI_CTRL47_bfmux_mem_ctrl_sd_scb_END (15)
#define SOC_PCTRL_PERI_CTRL47_peri_ctrl47_mask_START (16)
#define SOC_PCTRL_PERI_CTRL47_peri_ctrl47_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_mem_ctrl_sd_scc : 8;
        unsigned int bfmux_mem_ctrl_sd_scd : 8;
        unsigned int peri_ctrl107_msk : 16;
    } reg;
} SOC_PCTRL_PERI_CTRL48_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL48_bfmux_mem_ctrl_sd_scc_START (0)
#define SOC_PCTRL_PERI_CTRL48_bfmux_mem_ctrl_sd_scc_END (7)
#define SOC_PCTRL_PERI_CTRL48_bfmux_mem_ctrl_sd_scd_START (8)
#define SOC_PCTRL_PERI_CTRL48_bfmux_mem_ctrl_sd_scd_END (15)
#define SOC_PCTRL_PERI_CTRL48_peri_ctrl107_msk_START (16)
#define SOC_PCTRL_PERI_CTRL48_peri_ctrl107_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL49_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL50_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL51_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL52_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL53_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL54_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL55_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL56_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL57_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL58_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL59_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 24;
        unsigned int reserved_1: 8;
    } reg;
} SOC_PCTRL_PERI_CTRL60_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL61_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL61_lock_START (0)
#define SOC_PCTRL_PERI_CTRL61_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp0_wakeup_irps_en_0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL62_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL62_tsp0_wakeup_irps_en_0_START (0)
#define SOC_PCTRL_PERI_CTRL62_tsp0_wakeup_irps_en_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsp0_wakeup_irps_en_1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL63_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL63_tsp0_wakeup_irps_en_1_START (0)
#define SOC_PCTRL_PERI_CTRL63_tsp0_wakeup_irps_en_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL64_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL65_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL66_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL75_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL76_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved8 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL77_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL77_pctrl_modem_reserved8_START (0)
#define SOC_PCTRL_PERI_CTRL77_pctrl_modem_reserved8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved9 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL78_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL78_pctrl_modem_reserved9_START (0)
#define SOC_PCTRL_PERI_CTRL78_pctrl_modem_reserved9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved10 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL79_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL79_pctrl_modem_reserved10_START (0)
#define SOC_PCTRL_PERI_CTRL79_pctrl_modem_reserved10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved11 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL80_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL80_pctrl_modem_reserved11_START (0)
#define SOC_PCTRL_PERI_CTRL80_pctrl_modem_reserved11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved12 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL81_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL81_pctrl_modem_reserved12_START (0)
#define SOC_PCTRL_PERI_CTRL81_pctrl_modem_reserved12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved13 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL82_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL82_pctrl_modem_reserved13_START (0)
#define SOC_PCTRL_PERI_CTRL82_pctrl_modem_reserved13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved14 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL83_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL83_pctrl_modem_reserved14_START (0)
#define SOC_PCTRL_PERI_CTRL83_pctrl_modem_reserved14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pctrl_modem_reserved15 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL84_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL84_pctrl_modem_reserved15_START (0)
#define SOC_PCTRL_PERI_CTRL84_pctrl_modem_reserved15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL85_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL86_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_PCTRL_PERI_CTRL87_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_PCTRL_PERI_STAT160_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL168_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL169_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL170_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL171_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL172_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL173_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL174_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL175_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL176_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL177_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL178_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL179_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL180_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL181_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL182_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL183_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL184_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL185_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL186_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL187_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL188_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL189_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL190_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL191_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL192_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL193_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL194_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL195_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL196_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL197_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL198_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL199_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL200_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL201_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL202_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL203_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int bootram_auth : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_PCTRL_PERI_CTRL204_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL204_bootram_auth_START (1)
#define SOC_PCTRL_PERI_CTRL204_bootram_auth_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read0 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL205_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL205_software_secure_write_read0_START (0)
#define SOC_PCTRL_PERI_CTRL205_software_secure_write_read0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read1 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL206_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL206_software_secure_write_read1_START (0)
#define SOC_PCTRL_PERI_CTRL206_software_secure_write_read1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read2 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL207_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL207_software_secure_write_read2_START (0)
#define SOC_PCTRL_PERI_CTRL207_software_secure_write_read2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read3 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL208_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL208_software_secure_write_read3_START (0)
#define SOC_PCTRL_PERI_CTRL208_software_secure_write_read3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read4 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL209_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL209_software_secure_write_read4_START (0)
#define SOC_PCTRL_PERI_CTRL209_software_secure_write_read4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read5 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL210_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL210_software_secure_write_read5_START (0)
#define SOC_PCTRL_PERI_CTRL210_software_secure_write_read5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read6 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL211_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL211_software_secure_write_read6_START (0)
#define SOC_PCTRL_PERI_CTRL211_software_secure_write_read6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int software_secure_write_read7 : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL212_UNION;
#endif
#define SOC_PCTRL_PERI_CTRL212_software_secure_write_read7_START (0)
#define SOC_PCTRL_PERI_CTRL212_software_secure_write_read7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL213_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL214_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL215_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL216_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL217_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL218_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL219_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL220_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL221_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL222_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL223_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL224_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL225_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL226_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL227_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL228_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL229_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL230_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL231_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL232_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL233_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL234_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL235_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL236_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL237_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL238_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL239_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL240_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL241_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL242_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL243_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL244_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL245_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL246_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL247_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL248_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PCTRL_PERI_CTRL249_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_slp_ack_external_a : 1;
        unsigned int ddr_slp_ack_external_b : 1;
        unsigned int ddr_slp_ack_external_c : 1;
        unsigned int ddr_slp_ack_external_d : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PCTRL_PERI_STAT_SEC0_UNION;
#endif
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_a_START (0)
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_a_END (0)
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_b_START (1)
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_b_END (1)
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_c_START (2)
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_c_END (2)
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_d_START (3)
#define SOC_PCTRL_PERI_STAT_SEC0_ddr_slp_ack_external_d_END (3)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
