#ifndef __SOC_GPU_CTRL_INTERFACE_H__
#define __SOC_GPU_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_GPU_CTRL_P0_0_ADDR(base) (base)
#define SOC_GPU_CTRL_P0_1_ADDR(base) ((base) + 0x004UL)
#define SOC_GPU_CTRL_P0_2_ADDR(base) ((base) + 0x008UL)
#define SOC_GPU_CTRL_P0_3_ADDR(base) ((base) + 0x00CUL)
#define SOC_GPU_CTRL_P0_4_ADDR(base) ((base) + 0x010UL)
#define SOC_GPU_CTRL_P0_5_ADDR(base) ((base) + 0x014UL)
#define SOC_GPU_CTRL_P0_6_ADDR(base) ((base) + 0x018UL)
#define SOC_GPU_CTRL_P0_7_ADDR(base) ((base) + 0x01CUL)
#define SOC_GPU_CTRL_P0_8_ADDR(base) ((base) + 0x020UL)
#define SOC_GPU_CTRL_P0_lpcfg_mem_ADDR(base) ((base) + 0x024UL)
#define SOC_GPU_CTRL_P0_9_ADDR(base) ((base) + 0x028UL)
#define SOC_GPU_CTRL_P0_10_ADDR(base) ((base) + 0x02CUL)
#define SOC_GPU_CTRL_P0_11_ADDR(base) ((base) + 0x030UL)
#define SOC_GPU_CTRL_P0_12_ADDR(base) ((base) + 0x034UL)
#define SOC_GPU_CTRL_P0_13_ADDR(base) ((base) + 0x038UL)
#define SOC_GPU_CTRL_P0_14_ADDR(base) ((base) + 0x03CUL)
#define SOC_GPU_CTRL_P0_15_ADDR(base) ((base) + 0x040UL)
#define SOC_GPU_CTRL_P0__ADDR(base) ((base) + 0x044UL)
#define SOC_GPU_CTRL_P0_16_ADDR(base) ((base) + 0x048UL)
#define SOC_GPU_CTRL_P0_17_ADDR(base) ((base) + 0x04CUL)
#define SOC_GPU_CTRL_P0_18_ADDR(base) ((base) + 0x050UL)
#define SOC_GPU_CTRL_P0_19_ADDR(base) ((base) + 0x054UL)
#define SOC_GPU_CTRL_P0_20_ADDR(base) ((base) + 0x058UL)
#define SOC_GPU_CTRL_P0_21_ADDR(base) ((base) + 0x05CUL)
#define SOC_GPU_CTRL_P0_22_ADDR(base) ((base) + 0x060UL)
#define SOC_GPU_CTRL_P0_23_ADDR(base) ((base) + 0x064UL)
#define SOC_GPU_CTRL_P0_24_ADDR(base) ((base) + 0x068UL)
#define SOC_GPU_CTRL_P0_25_ADDR(base) ((base) + 0x06CUL)
#define SOC_GPU_CTRL_P0_26_ADDR(base) ((base) + 0x070UL)
#define SOC_GPU_CTRL_P0_27_ADDR(base) ((base) + 0x074UL)
#define SOC_GPU_CTRL_P0_28_ADDR(base) ((base) + 0x078UL)
#define SOC_GPU_CTRL_P0_29_ADDR(base) ((base) + 0x07CUL)
#define SOC_GPU_CTRL_P0_30_ADDR(base) ((base) + 0x080UL)
#define SOC_GPU_CTRL_P0_31_ADDR(base) ((base) + 0x084UL)
#define SOC_GPU_CTRL_P0_32_ADDR(base) ((base) + 0x088UL)
#define SOC_GPU_CTRL_P0_33_ADDR(base) ((base) + 0x08CUL)
#define SOC_GPU_CTRL_P0_34_ADDR(base) ((base) + 0x090UL)
#define SOC_GPU_CTRL_P0_35_ADDR(base) ((base) + 0x094UL)
#define SOC_GPU_CTRL_P0_36_ADDR(base) ((base) + 0x098UL)
#define SOC_GPU_CTRL_P0_37_ADDR(base) ((base) + 0x09CUL)
#define SOC_GPU_CTRL_P0_38_ADDR(base) ((base) + 0x0A0UL)
#define SOC_GPU_CTRL_P0_39_ADDR(base) ((base) + 0x0A4UL)
#define SOC_GPU_CTRL_P0_40_ADDR(base) ((base) + 0x0A8UL)
#define SOC_GPU_CTRL_P0_41_ADDR(base) ((base) + 0x0ACUL)
#define SOC_GPU_CTRL_P0_42_ADDR(base) ((base) + 0x0B0UL)
#define SOC_GPU_CTRL_P0_43_ADDR(base) ((base) + 0x0B4UL)
#define SOC_GPU_CTRL_P0_44_ADDR(base) ((base) + 0x0B8UL)
#define SOC_GPU_CTRL_P0_45_ADDR(base) ((base) + 0x0BCUL)
#define SOC_GPU_CTRL_P0_46_ADDR(base) ((base) + 0x0C0UL)
#define SOC_GPU_CTRL_P0_47_ADDR(base) ((base) + 0x0C4UL)
#define SOC_GPU_CTRL_P0_48_ADDR(base) ((base) + 0x0C8UL)
#define SOC_GPU_CTRL_P0_49_ADDR(base) ((base) + 0x0CCUL)
#define SOC_GPU_CTRL_MSK0_ADDR(base) ((base) + 0x400UL)
#define SOC_GPU_CTRL_MSK1_ADDR(base) ((base) + 0x404UL)
#define SOC_GPU_CTRL_MSK2_ADDR(base) ((base) + 0x408UL)
#define SOC_GPU_CTRL_P1_MWC0_ADDR(base) ((base) + 0x40CUL)
#define SOC_GPU_CTRL_P1_MWC1_ADDR(base) ((base) + 0x410UL)
#define SOC_GPU_CTRL_P1_MWC2_ADDR(base) ((base) + 0x414UL)
#define SOC_GPU_CTRL_MSK3_ADDR(base) ((base) + 0x418UL)
#define SOC_GPU_CTRL_MSK4_ADDR(base) ((base) + 0x41CUL)
#define SOC_GPU_CTRL_MSK5_ADDR(base) ((base) + 0x420UL)
#define SOC_GPU_CTRL_MSK6_ADDR(base) ((base) + 0x424UL)
#define SOC_GPU_CTRL_P1_MWC3_ADDR(base) ((base) + 0x428UL)
#define SOC_GPU_CTRL_P1_MWC4_ADDR(base) ((base) + 0x42CUL)
#define SOC_GPU_CTRL_P1_MWC5_ADDR(base) ((base) + 0x430UL)
#define SOC_GPU_CTRL_P1_MWC6_ADDR(base) ((base) + 0x434UL)
#define SOC_GPU_CTRL_P1_MWC7_ADDR(base) ((base) + 0x438UL)
#define SOC_GPU_CTRL_P1_MWC8_ADDR(base) ((base) + 0x43CUL)
#define SOC_GPU_CTRL_P1_MWC9_ADDR(base) ((base) + 0x440UL)
#define SOC_GPU_CTRL_P1_MWC10_ADDR(base) ((base) + 0x444UL)
#define SOC_GPU_CTRL_P1_MWC12_ADDR(base) ((base) + 0x448UL)
#define SOC_GPU_CTRL_P1_MWC13_ADDR(base) ((base) + 0x44CUL)
#define SOC_GPU_CTRL_P1_MWC14_ADDR(base) ((base) + 0x450UL)
#define SOC_GPU_CTRL_P1_MWC15_ADDR(base) ((base) + 0x454UL)
#define SOC_GPU_CTRL_P1_MWC16_ADDR(base) ((base) + 0x458UL)
#define SOC_GPU_CTRL_P1_MWC17_ADDR(base) ((base) + 0x45CUL)
#define SOC_GPU_CTRL_P1_MWC18_ADDR(base) ((base) + 0x460UL)
#define SOC_GPU_CTRL_P1_MWC19_ADDR(base) ((base) + 0x464UL)
#define SOC_GPU_CTRL_P1_MWC20_ADDR(base) ((base) + 0x468UL)
#define SOC_GPU_CTRL_P1_MWC21_ADDR(base) ((base) + 0x46CUL)
#define SOC_GPU_CTRL_P1_MWC22_ADDR(base) ((base) + 0x470UL)
#define SOC_GPU_CTRL_MSK7_ADDR(base) ((base) + 0x474UL)
#define SOC_GPU_CTRL_P1_MWC23_ADDR(base) ((base) + 0x478UL)
#define SOC_GPU_CTRL_P1_MWC24_ADDR(base) ((base) + 0x47CUL)
#define SOC_GPU_CTRL_P1_MWC25_ADDR(base) ((base) + 0x480UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_0_ADDR(base) ((base) + 0x800UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_1_ADDR(base) ((base) + 0x804UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_2_ADDR(base) ((base) + 0x808UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_3_ADDR(base) ((base) + 0x80CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_4_ADDR(base) ((base) + 0x810UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_5_ADDR(base) ((base) + 0x814UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_6_ADDR(base) ((base) + 0x818UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_7_ADDR(base) ((base) + 0x81CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_8_ADDR(base) ((base) + 0x820UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_9_ADDR(base) ((base) + 0x824UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_10_ADDR(base) ((base) + 0x828UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_11_ADDR(base) ((base) + 0x82CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_12_ADDR(base) ((base) + 0x830UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_13_ADDR(base) ((base) + 0x834UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_14_ADDR(base) ((base) + 0x838UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_15_ADDR(base) ((base) + 0x83CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_16_ADDR(base) ((base) + 0x840UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_17_ADDR(base) ((base) + 0x844UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_18_ADDR(base) ((base) + 0x848UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_ADDR(base) ((base) + 0x84CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_ADDR(base) ((base) + 0x850UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_21_ADDR(base) ((base) + 0x854UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_22_ADDR(base) ((base) + 0x858UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_ADDR(base) ((base) + 0x85CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_24_ADDR(base) ((base) + 0x860UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_25_ADDR(base) ((base) + 0x864UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_26_ADDR(base) ((base) + 0x868UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_27_ADDR(base) ((base) + 0x86CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_28_ADDR(base) ((base) + 0x870UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_29_ADDR(base) ((base) + 0x874UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_30_ADDR(base) ((base) + 0x878UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_31_ADDR(base) ((base) + 0x87CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_32_ADDR(base) ((base) + 0x880UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_33_ADDR(base) ((base) + 0x884UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_34_ADDR(base) ((base) + 0x888UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_35_ADDR(base) ((base) + 0x88CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_36_ADDR(base) ((base) + 0x890UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_37_ADDR(base) ((base) + 0x894UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_38_ADDR(base) ((base) + 0x898UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_39_ADDR(base) ((base) + 0x89CUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_40_ADDR(base) ((base) + 0x9A0UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_ADDR(base) ((base) + 0x9A4UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_42_ADDR(base) ((base) + 0x9A8UL)
#define SOC_GPU_CTRL_GPU_STAT_P2_43_ADDR(base) ((base) + 0x9ACUL)
#define SOC_GPU_CTRL_GPU_STAT_P2_44_ADDR(base) ((base) + 0x9B0UL)
#define SOC_GPU_CTRL_P3_0_ADDR(base) ((base) + 0xC00UL)
#define SOC_GPU_CTRL_GPU_STAT_P3_0_ADDR(base) ((base) + 0xC04UL)
#define SOC_GPU_CTRL_P4_0_SET_ADDR(base) ((base) + 0xFE0UL)
#define SOC_GPU_CTRL_P4_0_CLR_ADDR(base) ((base) + 0xFE4UL)
#define SOC_GPU_CTRL_P4_0_STA_ADDR(base) ((base) + 0xFE8UL)
#define SOC_GPU_CTRL_P4_1_SET_ADDR(base) ((base) + 0xFECUL)
#define SOC_GPU_CTRL_P4_1_CLR_ADDR(base) ((base) + 0xFF0UL)
#define SOC_GPU_CTRL_P4_1_STA_ADDR(base) ((base) + 0xFF4UL)
#define SOC_GPU_CTRL_P4_6_ADDR(base) ((base) + 0xFF8UL)
#define SOC_GPU_CTRL_LOCK_ADDR(base) ((base) + 0xFFCUL)
#else
#define SOC_GPU_CTRL_P0_0_ADDR(base) (base)
#define SOC_GPU_CTRL_P0_1_ADDR(base) ((base) + 0x004)
#define SOC_GPU_CTRL_P0_2_ADDR(base) ((base) + 0x008)
#define SOC_GPU_CTRL_P0_3_ADDR(base) ((base) + 0x00C)
#define SOC_GPU_CTRL_P0_4_ADDR(base) ((base) + 0x010)
#define SOC_GPU_CTRL_P0_5_ADDR(base) ((base) + 0x014)
#define SOC_GPU_CTRL_P0_6_ADDR(base) ((base) + 0x018)
#define SOC_GPU_CTRL_P0_7_ADDR(base) ((base) + 0x01C)
#define SOC_GPU_CTRL_P0_8_ADDR(base) ((base) + 0x020)
#define SOC_GPU_CTRL_P0_lpcfg_mem_ADDR(base) ((base) + 0x024)
#define SOC_GPU_CTRL_P0_9_ADDR(base) ((base) + 0x028)
#define SOC_GPU_CTRL_P0_10_ADDR(base) ((base) + 0x02C)
#define SOC_GPU_CTRL_P0_11_ADDR(base) ((base) + 0x030)
#define SOC_GPU_CTRL_P0_12_ADDR(base) ((base) + 0x034)
#define SOC_GPU_CTRL_P0_13_ADDR(base) ((base) + 0x038)
#define SOC_GPU_CTRL_P0_14_ADDR(base) ((base) + 0x03C)
#define SOC_GPU_CTRL_P0_15_ADDR(base) ((base) + 0x040)
#define SOC_GPU_CTRL_P0__ADDR(base) ((base) + 0x044)
#define SOC_GPU_CTRL_P0_16_ADDR(base) ((base) + 0x048)
#define SOC_GPU_CTRL_P0_17_ADDR(base) ((base) + 0x04C)
#define SOC_GPU_CTRL_P0_18_ADDR(base) ((base) + 0x050)
#define SOC_GPU_CTRL_P0_19_ADDR(base) ((base) + 0x054)
#define SOC_GPU_CTRL_P0_20_ADDR(base) ((base) + 0x058)
#define SOC_GPU_CTRL_P0_21_ADDR(base) ((base) + 0x05C)
#define SOC_GPU_CTRL_P0_22_ADDR(base) ((base) + 0x060)
#define SOC_GPU_CTRL_P0_23_ADDR(base) ((base) + 0x064)
#define SOC_GPU_CTRL_P0_24_ADDR(base) ((base) + 0x068)
#define SOC_GPU_CTRL_P0_25_ADDR(base) ((base) + 0x06C)
#define SOC_GPU_CTRL_P0_26_ADDR(base) ((base) + 0x070)
#define SOC_GPU_CTRL_P0_27_ADDR(base) ((base) + 0x074)
#define SOC_GPU_CTRL_P0_28_ADDR(base) ((base) + 0x078)
#define SOC_GPU_CTRL_P0_29_ADDR(base) ((base) + 0x07C)
#define SOC_GPU_CTRL_P0_30_ADDR(base) ((base) + 0x080)
#define SOC_GPU_CTRL_P0_31_ADDR(base) ((base) + 0x084)
#define SOC_GPU_CTRL_P0_32_ADDR(base) ((base) + 0x088)
#define SOC_GPU_CTRL_P0_33_ADDR(base) ((base) + 0x08C)
#define SOC_GPU_CTRL_P0_34_ADDR(base) ((base) + 0x090)
#define SOC_GPU_CTRL_P0_35_ADDR(base) ((base) + 0x094)
#define SOC_GPU_CTRL_P0_36_ADDR(base) ((base) + 0x098)
#define SOC_GPU_CTRL_P0_37_ADDR(base) ((base) + 0x09C)
#define SOC_GPU_CTRL_P0_38_ADDR(base) ((base) + 0x0A0)
#define SOC_GPU_CTRL_P0_39_ADDR(base) ((base) + 0x0A4)
#define SOC_GPU_CTRL_P0_40_ADDR(base) ((base) + 0x0A8)
#define SOC_GPU_CTRL_P0_41_ADDR(base) ((base) + 0x0AC)
#define SOC_GPU_CTRL_P0_42_ADDR(base) ((base) + 0x0B0)
#define SOC_GPU_CTRL_P0_43_ADDR(base) ((base) + 0x0B4)
#define SOC_GPU_CTRL_P0_44_ADDR(base) ((base) + 0x0B8)
#define SOC_GPU_CTRL_P0_45_ADDR(base) ((base) + 0x0BC)
#define SOC_GPU_CTRL_P0_46_ADDR(base) ((base) + 0x0C0)
#define SOC_GPU_CTRL_P0_47_ADDR(base) ((base) + 0x0C4)
#define SOC_GPU_CTRL_P0_48_ADDR(base) ((base) + 0x0C8)
#define SOC_GPU_CTRL_P0_49_ADDR(base) ((base) + 0x0CC)
#define SOC_GPU_CTRL_MSK0_ADDR(base) ((base) + 0x400)
#define SOC_GPU_CTRL_MSK1_ADDR(base) ((base) + 0x404)
#define SOC_GPU_CTRL_MSK2_ADDR(base) ((base) + 0x408)
#define SOC_GPU_CTRL_P1_MWC0_ADDR(base) ((base) + 0x40C)
#define SOC_GPU_CTRL_P1_MWC1_ADDR(base) ((base) + 0x410)
#define SOC_GPU_CTRL_P1_MWC2_ADDR(base) ((base) + 0x414)
#define SOC_GPU_CTRL_MSK3_ADDR(base) ((base) + 0x418)
#define SOC_GPU_CTRL_MSK4_ADDR(base) ((base) + 0x41C)
#define SOC_GPU_CTRL_MSK5_ADDR(base) ((base) + 0x420)
#define SOC_GPU_CTRL_MSK6_ADDR(base) ((base) + 0x424)
#define SOC_GPU_CTRL_P1_MWC3_ADDR(base) ((base) + 0x428)
#define SOC_GPU_CTRL_P1_MWC4_ADDR(base) ((base) + 0x42C)
#define SOC_GPU_CTRL_P1_MWC5_ADDR(base) ((base) + 0x430)
#define SOC_GPU_CTRL_P1_MWC6_ADDR(base) ((base) + 0x434)
#define SOC_GPU_CTRL_P1_MWC7_ADDR(base) ((base) + 0x438)
#define SOC_GPU_CTRL_P1_MWC8_ADDR(base) ((base) + 0x43C)
#define SOC_GPU_CTRL_P1_MWC9_ADDR(base) ((base) + 0x440)
#define SOC_GPU_CTRL_P1_MWC10_ADDR(base) ((base) + 0x444)
#define SOC_GPU_CTRL_P1_MWC12_ADDR(base) ((base) + 0x448)
#define SOC_GPU_CTRL_P1_MWC13_ADDR(base) ((base) + 0x44C)
#define SOC_GPU_CTRL_P1_MWC14_ADDR(base) ((base) + 0x450)
#define SOC_GPU_CTRL_P1_MWC15_ADDR(base) ((base) + 0x454)
#define SOC_GPU_CTRL_P1_MWC16_ADDR(base) ((base) + 0x458)
#define SOC_GPU_CTRL_P1_MWC17_ADDR(base) ((base) + 0x45C)
#define SOC_GPU_CTRL_P1_MWC18_ADDR(base) ((base) + 0x460)
#define SOC_GPU_CTRL_P1_MWC19_ADDR(base) ((base) + 0x464)
#define SOC_GPU_CTRL_P1_MWC20_ADDR(base) ((base) + 0x468)
#define SOC_GPU_CTRL_P1_MWC21_ADDR(base) ((base) + 0x46C)
#define SOC_GPU_CTRL_P1_MWC22_ADDR(base) ((base) + 0x470)
#define SOC_GPU_CTRL_MSK7_ADDR(base) ((base) + 0x474)
#define SOC_GPU_CTRL_P1_MWC23_ADDR(base) ((base) + 0x478)
#define SOC_GPU_CTRL_P1_MWC24_ADDR(base) ((base) + 0x47C)
#define SOC_GPU_CTRL_P1_MWC25_ADDR(base) ((base) + 0x480)
#define SOC_GPU_CTRL_GPU_STAT_P2_0_ADDR(base) ((base) + 0x800)
#define SOC_GPU_CTRL_GPU_STAT_P2_1_ADDR(base) ((base) + 0x804)
#define SOC_GPU_CTRL_GPU_STAT_P2_2_ADDR(base) ((base) + 0x808)
#define SOC_GPU_CTRL_GPU_STAT_P2_3_ADDR(base) ((base) + 0x80C)
#define SOC_GPU_CTRL_GPU_STAT_P2_4_ADDR(base) ((base) + 0x810)
#define SOC_GPU_CTRL_GPU_STAT_P2_5_ADDR(base) ((base) + 0x814)
#define SOC_GPU_CTRL_GPU_STAT_P2_6_ADDR(base) ((base) + 0x818)
#define SOC_GPU_CTRL_GPU_STAT_P2_7_ADDR(base) ((base) + 0x81C)
#define SOC_GPU_CTRL_GPU_STAT_P2_8_ADDR(base) ((base) + 0x820)
#define SOC_GPU_CTRL_GPU_STAT_P2_9_ADDR(base) ((base) + 0x824)
#define SOC_GPU_CTRL_GPU_STAT_P2_10_ADDR(base) ((base) + 0x828)
#define SOC_GPU_CTRL_GPU_STAT_P2_11_ADDR(base) ((base) + 0x82C)
#define SOC_GPU_CTRL_GPU_STAT_P2_12_ADDR(base) ((base) + 0x830)
#define SOC_GPU_CTRL_GPU_STAT_P2_13_ADDR(base) ((base) + 0x834)
#define SOC_GPU_CTRL_GPU_STAT_P2_14_ADDR(base) ((base) + 0x838)
#define SOC_GPU_CTRL_GPU_STAT_P2_15_ADDR(base) ((base) + 0x83C)
#define SOC_GPU_CTRL_GPU_STAT_P2_16_ADDR(base) ((base) + 0x840)
#define SOC_GPU_CTRL_GPU_STAT_P2_17_ADDR(base) ((base) + 0x844)
#define SOC_GPU_CTRL_GPU_STAT_P2_18_ADDR(base) ((base) + 0x848)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_ADDR(base) ((base) + 0x84C)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_ADDR(base) ((base) + 0x850)
#define SOC_GPU_CTRL_GPU_STAT_P2_21_ADDR(base) ((base) + 0x854)
#define SOC_GPU_CTRL_GPU_STAT_P2_22_ADDR(base) ((base) + 0x858)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_ADDR(base) ((base) + 0x85C)
#define SOC_GPU_CTRL_GPU_STAT_P2_24_ADDR(base) ((base) + 0x860)
#define SOC_GPU_CTRL_GPU_STAT_P2_25_ADDR(base) ((base) + 0x864)
#define SOC_GPU_CTRL_GPU_STAT_P2_26_ADDR(base) ((base) + 0x868)
#define SOC_GPU_CTRL_GPU_STAT_P2_27_ADDR(base) ((base) + 0x86C)
#define SOC_GPU_CTRL_GPU_STAT_P2_28_ADDR(base) ((base) + 0x870)
#define SOC_GPU_CTRL_GPU_STAT_P2_29_ADDR(base) ((base) + 0x874)
#define SOC_GPU_CTRL_GPU_STAT_P2_30_ADDR(base) ((base) + 0x878)
#define SOC_GPU_CTRL_GPU_STAT_P2_31_ADDR(base) ((base) + 0x87C)
#define SOC_GPU_CTRL_GPU_STAT_P2_32_ADDR(base) ((base) + 0x880)
#define SOC_GPU_CTRL_GPU_STAT_P2_33_ADDR(base) ((base) + 0x884)
#define SOC_GPU_CTRL_GPU_STAT_P2_34_ADDR(base) ((base) + 0x888)
#define SOC_GPU_CTRL_GPU_STAT_P2_35_ADDR(base) ((base) + 0x88C)
#define SOC_GPU_CTRL_GPU_STAT_P2_36_ADDR(base) ((base) + 0x890)
#define SOC_GPU_CTRL_GPU_STAT_P2_37_ADDR(base) ((base) + 0x894)
#define SOC_GPU_CTRL_GPU_STAT_P2_38_ADDR(base) ((base) + 0x898)
#define SOC_GPU_CTRL_GPU_STAT_P2_39_ADDR(base) ((base) + 0x89C)
#define SOC_GPU_CTRL_GPU_STAT_P2_40_ADDR(base) ((base) + 0x9A0)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_ADDR(base) ((base) + 0x9A4)
#define SOC_GPU_CTRL_GPU_STAT_P2_42_ADDR(base) ((base) + 0x9A8)
#define SOC_GPU_CTRL_GPU_STAT_P2_43_ADDR(base) ((base) + 0x9AC)
#define SOC_GPU_CTRL_GPU_STAT_P2_44_ADDR(base) ((base) + 0x9B0)
#define SOC_GPU_CTRL_P3_0_ADDR(base) ((base) + 0xC00)
#define SOC_GPU_CTRL_GPU_STAT_P3_0_ADDR(base) ((base) + 0xC04)
#define SOC_GPU_CTRL_P4_0_SET_ADDR(base) ((base) + 0xFE0)
#define SOC_GPU_CTRL_P4_0_CLR_ADDR(base) ((base) + 0xFE4)
#define SOC_GPU_CTRL_P4_0_STA_ADDR(base) ((base) + 0xFE8)
#define SOC_GPU_CTRL_P4_1_SET_ADDR(base) ((base) + 0xFEC)
#define SOC_GPU_CTRL_P4_1_CLR_ADDR(base) ((base) + 0xFF0)
#define SOC_GPU_CTRL_P4_1_STA_ADDR(base) ((base) + 0xFF4)
#define SOC_GPU_CTRL_P4_6_ADDR(base) ((base) + 0xFF8)
#define SOC_GPU_CTRL_LOCK_ADDR(base) ((base) + 0xFFC)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_ctrl_rsv0 : 32;
    } reg;
} SOC_GPU_CTRL_P0_0_UNION;
#endif
#define SOC_GPU_CTRL_P0_0_gpu_ctrl_rsv0_START (0)
#define SOC_GPU_CTRL_P0_0_gpu_ctrl_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 19;
    } reg;
} SOC_GPU_CTRL_P0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 27;
    } reg;
} SOC_GPU_CTRL_P0_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_GPU_CTRL_P0_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg2gpu_qactive_cfgcnt : 7;
        unsigned int cfg2gpu_gt_clk_bypass : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_CTRL_P0_4_UNION;
#endif
#define SOC_GPU_CTRL_P0_4_cfg2gpu_qactive_cfgcnt_START (0)
#define SOC_GPU_CTRL_P0_4_cfg2gpu_qactive_cfgcnt_END (6)
#define SOC_GPU_CTRL_P0_4_cfg2gpu_gt_clk_bypass_START (7)
#define SOC_GPU_CTRL_P0_4_cfg2gpu_gt_clk_bypass_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gid_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_CTRL_P0_5_UNION;
#endif
#define SOC_GPU_CTRL_P0_5_gid_mode_START (0)
#define SOC_GPU_CTRL_P0_5_gid_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csysreq_adb_g3d_0 : 1;
        unsigned int csysreq_adb_g3d_1 : 1;
        unsigned int cfg2gpu_pwrqreqns_i : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_GPU_CTRL_P0_6_UNION;
#endif
#define SOC_GPU_CTRL_P0_6_csysreq_adb_g3d_0_START (0)
#define SOC_GPU_CTRL_P0_6_csysreq_adb_g3d_0_END (0)
#define SOC_GPU_CTRL_P0_6_csysreq_adb_g3d_1_START (1)
#define SOC_GPU_CTRL_P0_6_csysreq_adb_g3d_1_END (1)
#define SOC_GPU_CTRL_P0_6_cfg2gpu_pwrqreqns_i_START (2)
#define SOC_GPU_CTRL_P0_6_cfg2gpu_pwrqreqns_i_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qactive_cfgcnt_gpu : 7;
        unsigned int gt_clk_bypass_gpu : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_CTRL_P0_7_UNION;
#endif
#define SOC_GPU_CTRL_P0_7_qactive_cfgcnt_gpu_START (0)
#define SOC_GPU_CTRL_P0_7_qactive_cfgcnt_gpu_END (6)
#define SOC_GPU_CTRL_P0_7_gt_clk_bypass_gpu_START (7)
#define SOC_GPU_CTRL_P0_7_gt_clk_bypass_gpu_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aw_mpam_override : 1;
        unsigned int ar_mpam_override : 1;
        unsigned int ar_mask_override : 1;
        unsigned int qos_override : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_GPU_CTRL_P0_8_UNION;
#endif
#define SOC_GPU_CTRL_P0_8_aw_mpam_override_START (0)
#define SOC_GPU_CTRL_P0_8_aw_mpam_override_END (0)
#define SOC_GPU_CTRL_P0_8_ar_mpam_override_START (1)
#define SOC_GPU_CTRL_P0_8_ar_mpam_override_END (1)
#define SOC_GPU_CTRL_P0_8_ar_mask_override_START (2)
#define SOC_GPU_CTRL_P0_8_ar_mask_override_END (2)
#define SOC_GPU_CTRL_P0_8_qos_override_START (3)
#define SOC_GPU_CTRL_P0_8_qos_override_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P0_lpcfg_mem_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remap_aw_mpam : 4;
        unsigned int remap_ar_mpam : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_CTRL_P0_9_UNION;
#endif
#define SOC_GPU_CTRL_P0_9_remap_aw_mpam_START (0)
#define SOC_GPU_CTRL_P0_9_remap_aw_mpam_END (3)
#define SOC_GPU_CTRL_P0_9_remap_ar_mpam_START (4)
#define SOC_GPU_CTRL_P0_9_remap_ar_mpam_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 25;
        unsigned int reserved_1: 7;
    } reg;
} SOC_GPU_CTRL_P0_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_spram_mem_ctrl_hisi_h : 32;
    } reg;
} SOC_GPU_CTRL_P0_11_UNION;
#endif
#define SOC_GPU_CTRL_P0_11_gpu_spram_mem_ctrl_hisi_h_START (0)
#define SOC_GPU_CTRL_P0_11_gpu_spram_mem_ctrl_hisi_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_spram_mem_ctrl_hisi_l : 32;
    } reg;
} SOC_GPU_CTRL_P0_12_UNION;
#endif
#define SOC_GPU_CTRL_P0_12_gpu_spram_mem_ctrl_hisi_l_START (0)
#define SOC_GPU_CTRL_P0_12_gpu_spram_mem_ctrl_hisi_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g3d_tpram_mem_ctrl_hisi_h : 32;
    } reg;
} SOC_GPU_CTRL_P0_13_UNION;
#endif
#define SOC_GPU_CTRL_P0_13_g3d_tpram_mem_ctrl_hisi_h_START (0)
#define SOC_GPU_CTRL_P0_13_g3d_tpram_mem_ctrl_hisi_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g3d_tpram_mem_ctrl_hisi_l : 32;
    } reg;
} SOC_GPU_CTRL_P0_14_UNION;
#endif
#define SOC_GPU_CTRL_P0_14_g3d_tpram_mem_ctrl_hisi_l_START (0)
#define SOC_GPU_CTRL_P0_14_g3d_tpram_mem_ctrl_hisi_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P0_15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P0__UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P0_16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arqos_remap_sid7 : 4;
        unsigned int arqos_remap_sid6 : 4;
        unsigned int arqos_remap_sid5 : 4;
        unsigned int arqos_remap_sid4 : 4;
        unsigned int arqos_remap_sid3 : 4;
        unsigned int arqos_remap_sid2 : 4;
        unsigned int arqos_remap_sid1 : 4;
        unsigned int arqos_remap_sid0 : 4;
    } reg;
} SOC_GPU_CTRL_P0_17_UNION;
#endif
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid7_START (0)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid7_END (3)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid6_START (4)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid6_END (7)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid5_START (8)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid5_END (11)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid4_START (12)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid4_END (15)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid3_START (16)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid3_END (19)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid2_START (20)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid2_END (23)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid1_START (24)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid1_END (27)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid0_START (28)
#define SOC_GPU_CTRL_P0_17_arqos_remap_sid0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arqos_remap_sid15 : 4;
        unsigned int arqos_remap_sid14 : 4;
        unsigned int arqos_remap_sid13 : 4;
        unsigned int arqos_remap_sid12 : 4;
        unsigned int arqos_remap_sid11 : 4;
        unsigned int arqos_remap_sid10 : 4;
        unsigned int arqos_remap_sid9 : 4;
        unsigned int arqos_remap_sid8 : 4;
    } reg;
} SOC_GPU_CTRL_P0_18_UNION;
#endif
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid15_START (0)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid15_END (3)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid14_START (4)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid14_END (7)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid13_START (8)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid13_END (11)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid12_START (12)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid12_END (15)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid11_START (16)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid11_END (19)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid10_START (20)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid10_END (23)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid9_START (24)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid9_END (27)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid8_START (28)
#define SOC_GPU_CTRL_P0_18_arqos_remap_sid8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arqos_remap_sid23 : 4;
        unsigned int arqos_remap_sid22 : 4;
        unsigned int arqos_remap_sid21 : 4;
        unsigned int arqos_remap_sid20 : 4;
        unsigned int arqos_remap_sid19 : 4;
        unsigned int arqos_remap_sid18 : 4;
        unsigned int arqos_remap_sid17 : 4;
        unsigned int arqos_remap_sid16 : 4;
    } reg;
} SOC_GPU_CTRL_P0_19_UNION;
#endif
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid23_START (0)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid23_END (3)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid22_START (4)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid22_END (7)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid21_START (8)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid21_END (11)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid20_START (12)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid20_END (15)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid19_START (16)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid19_END (19)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid18_START (20)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid18_END (23)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid17_START (24)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid17_END (27)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid16_START (28)
#define SOC_GPU_CTRL_P0_19_arqos_remap_sid16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arqos_remap_sid31 : 4;
        unsigned int arqos_remap_sid30 : 4;
        unsigned int arqos_remap_sid29 : 4;
        unsigned int arqos_remap_sid28 : 4;
        unsigned int arqos_remap_sid27 : 4;
        unsigned int arqos_remap_sid26 : 4;
        unsigned int arqos_remap_sid25 : 4;
        unsigned int arqos_remap_sid24 : 4;
    } reg;
} SOC_GPU_CTRL_P0_20_UNION;
#endif
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid31_START (0)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid31_END (3)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid30_START (4)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid30_END (7)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid29_START (8)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid29_END (11)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid28_START (12)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid28_END (15)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid27_START (16)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid27_END (19)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid26_START (20)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid26_END (23)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid25_START (24)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid25_END (27)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid24_START (28)
#define SOC_GPU_CTRL_P0_20_arqos_remap_sid24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awqos_remap_sid7 : 4;
        unsigned int awqos_remap_sid6 : 4;
        unsigned int awqos_remap_sid5 : 4;
        unsigned int awqos_remap_sid4 : 4;
        unsigned int awqos_remap_sid3 : 4;
        unsigned int awqos_remap_sid2 : 4;
        unsigned int awqos_remap_sid1 : 4;
        unsigned int awqos_remap_sid0 : 4;
    } reg;
} SOC_GPU_CTRL_P0_21_UNION;
#endif
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid7_START (0)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid7_END (3)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid6_START (4)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid6_END (7)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid5_START (8)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid5_END (11)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid4_START (12)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid4_END (15)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid3_START (16)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid3_END (19)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid2_START (20)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid2_END (23)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid1_START (24)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid1_END (27)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid0_START (28)
#define SOC_GPU_CTRL_P0_21_awqos_remap_sid0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awqos_remap_sid15 : 4;
        unsigned int awqos_remap_sid14 : 4;
        unsigned int awqos_remap_sid13 : 4;
        unsigned int awqos_remap_sid12 : 4;
        unsigned int awqos_remap_sid11 : 4;
        unsigned int awqos_remap_sid10 : 4;
        unsigned int awqos_remap_sid9 : 4;
        unsigned int awqos_remap_sid8 : 4;
    } reg;
} SOC_GPU_CTRL_P0_22_UNION;
#endif
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid15_START (0)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid15_END (3)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid14_START (4)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid14_END (7)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid13_START (8)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid13_END (11)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid12_START (12)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid12_END (15)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid11_START (16)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid11_END (19)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid10_START (20)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid10_END (23)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid9_START (24)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid9_END (27)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid8_START (28)
#define SOC_GPU_CTRL_P0_22_awqos_remap_sid8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awqos_remap_sid23 : 4;
        unsigned int awqos_remap_sid22 : 4;
        unsigned int awqos_remap_sid21 : 4;
        unsigned int awqos_remap_sid20 : 4;
        unsigned int awqos_remap_sid19 : 4;
        unsigned int awqos_remap_sid18 : 4;
        unsigned int awqos_remap_sid17 : 4;
        unsigned int awqos_remap_sid16 : 4;
    } reg;
} SOC_GPU_CTRL_P0_23_UNION;
#endif
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid23_START (0)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid23_END (3)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid22_START (4)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid22_END (7)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid21_START (8)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid21_END (11)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid20_START (12)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid20_END (15)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid19_START (16)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid19_END (19)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid18_START (20)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid18_END (23)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid17_START (24)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid17_END (27)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid16_START (28)
#define SOC_GPU_CTRL_P0_23_awqos_remap_sid16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awqos_remap_sid31 : 4;
        unsigned int awqos_remap_sid30 : 4;
        unsigned int awqos_remap_sid29 : 4;
        unsigned int awqos_remap_sid28 : 4;
        unsigned int awqos_remap_sid27 : 4;
        unsigned int awqos_remap_sid26 : 4;
        unsigned int awqos_remap_sid25 : 4;
        unsigned int awqos_remap_sid24 : 4;
    } reg;
} SOC_GPU_CTRL_P0_24_UNION;
#endif
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid31_START (0)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid31_END (3)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid30_START (4)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid30_END (7)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid29_START (8)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid29_END (11)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid28_START (12)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid28_END (15)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid27_START (16)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid27_END (19)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid26_START (20)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid26_END (23)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid25_START (24)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid25_END (27)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid24_START (28)
#define SOC_GPU_CTRL_P0_24_awqos_remap_sid24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_25_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_29_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_30_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_31_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_32_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_33_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_34_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_35_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_36_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_37_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_GPU_CTRL_P0_38_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int testpoint_subchip_sel : 3;
        unsigned int intr_qic_mux_sel : 4;
        unsigned int idlereq_mux_sel1 : 1;
        unsigned int idleack_mux_sel1 : 1;
        unsigned int idlereq_mux_sel0 : 3;
        unsigned int idleack_mux_sel0 : 3;
        unsigned int reserved_0 : 3;
        unsigned int busy_mux_sel : 4;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 3;
    } reg;
} SOC_GPU_CTRL_P0_39_UNION;
#endif
#define SOC_GPU_CTRL_P0_39_testpoint_subchip_sel_START (0)
#define SOC_GPU_CTRL_P0_39_testpoint_subchip_sel_END (2)
#define SOC_GPU_CTRL_P0_39_intr_qic_mux_sel_START (3)
#define SOC_GPU_CTRL_P0_39_intr_qic_mux_sel_END (6)
#define SOC_GPU_CTRL_P0_39_idlereq_mux_sel1_START (7)
#define SOC_GPU_CTRL_P0_39_idlereq_mux_sel1_END (7)
#define SOC_GPU_CTRL_P0_39_idleack_mux_sel1_START (8)
#define SOC_GPU_CTRL_P0_39_idleack_mux_sel1_END (8)
#define SOC_GPU_CTRL_P0_39_idlereq_mux_sel0_START (9)
#define SOC_GPU_CTRL_P0_39_idlereq_mux_sel0_END (11)
#define SOC_GPU_CTRL_P0_39_idleack_mux_sel0_START (12)
#define SOC_GPU_CTRL_P0_39_idleack_mux_sel0_END (14)
#define SOC_GPU_CTRL_P0_39_busy_mux_sel_START (18)
#define SOC_GPU_CTRL_P0_39_busy_mux_sel_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mux_sel0 : 5;
        unsigned int nopending_mux_sel1 : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_GPU_CTRL_P0_40_UNION;
#endif
#define SOC_GPU_CTRL_P0_40_nopending_mux_sel0_START (0)
#define SOC_GPU_CTRL_P0_40_nopending_mux_sel0_END (4)
#define SOC_GPU_CTRL_P0_40_nopending_mux_sel1_START (5)
#define SOC_GPU_CTRL_P0_40_nopending_mux_sel1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idlereq_mask : 16;
        unsigned int idleack_mask : 16;
    } reg;
} SOC_GPU_CTRL_P0_41_UNION;
#endif
#define SOC_GPU_CTRL_P0_41_idlereq_mask_START (0)
#define SOC_GPU_CTRL_P0_41_idlereq_mask_END (15)
#define SOC_GPU_CTRL_P0_41_idleack_mask_START (16)
#define SOC_GPU_CTRL_P0_41_idleack_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int busy_mask : 32;
    } reg;
} SOC_GPU_CTRL_P0_42_UNION;
#endif
#define SOC_GPU_CTRL_P0_42_busy_mask_START (0)
#define SOC_GPU_CTRL_P0_42_busy_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mask0 : 32;
    } reg;
} SOC_GPU_CTRL_P0_43_UNION;
#endif
#define SOC_GPU_CTRL_P0_43_nopending_mask0_START (0)
#define SOC_GPU_CTRL_P0_43_nopending_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mask1 : 32;
    } reg;
} SOC_GPU_CTRL_P0_44_UNION;
#endif
#define SOC_GPU_CTRL_P0_44_nopending_mask1_START (0)
#define SOC_GPU_CTRL_P0_44_nopending_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_mask : 32;
    } reg;
} SOC_GPU_CTRL_P0_45_UNION;
#endif
#define SOC_GPU_CTRL_P0_45_intr_qic_mask_START (0)
#define SOC_GPU_CTRL_P0_45_intr_qic_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ostd1_lvl : 8;
        unsigned int icfg_ostd0_lvl : 8;
        unsigned int icfg_ostd0_update : 1;
        unsigned int icfg_ostd0_type : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_GPU_CTRL_P0_46_UNION;
#endif
#define SOC_GPU_CTRL_P0_46_icfg_ostd1_lvl_START (0)
#define SOC_GPU_CTRL_P0_46_icfg_ostd1_lvl_END (7)
#define SOC_GPU_CTRL_P0_46_icfg_ostd0_lvl_START (8)
#define SOC_GPU_CTRL_P0_46_icfg_ostd0_lvl_END (15)
#define SOC_GPU_CTRL_P0_46_icfg_ostd0_update_START (16)
#define SOC_GPU_CTRL_P0_46_icfg_ostd0_update_END (16)
#define SOC_GPU_CTRL_P0_46_icfg_ostd0_type_START (17)
#define SOC_GPU_CTRL_P0_46_icfg_ostd0_type_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P0_47_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P0_48_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_GPU_CTRL_P0_49_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysbus_gpu_xpu_bypass : 1;
        unsigned int sysbus_gpu_lpctrl_bypass : 1;
        unsigned int sysbus_t_bypass : 1;
        unsigned int sysbus_cfg2gpu_bypass : 1;
        unsigned int qice_gpu_perf_bypass : 1;
        unsigned int qice_gpu_perf_b_bypass : 1;
        unsigned int qice_gpu_dataqic_inner_bypass : 1;
        unsigned int sysbus_gpu_sub_bypass : 1;
        unsigned int gpu_pmc_clkgt_bypass : 1;
        unsigned int sysbus_gpu_dataqic_bypass : 1;
        unsigned int sysbus_g3d_cfg_idle_bypass : 1;
        unsigned int qice_gpu_dataqic_outer_bypass : 1;
        unsigned int qice_gpu_dataqic_qcp_bypass : 1;
        unsigned int reserved : 3;
        unsigned int GPU_CTRL_MSK0_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK0_UNION;
#endif
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_xpu_bypass_START (0)
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_xpu_bypass_END (0)
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_lpctrl_bypass_START (1)
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_lpctrl_bypass_END (1)
#define SOC_GPU_CTRL_MSK0_sysbus_t_bypass_START (2)
#define SOC_GPU_CTRL_MSK0_sysbus_t_bypass_END (2)
#define SOC_GPU_CTRL_MSK0_sysbus_cfg2gpu_bypass_START (3)
#define SOC_GPU_CTRL_MSK0_sysbus_cfg2gpu_bypass_END (3)
#define SOC_GPU_CTRL_MSK0_qice_gpu_perf_bypass_START (4)
#define SOC_GPU_CTRL_MSK0_qice_gpu_perf_bypass_END (4)
#define SOC_GPU_CTRL_MSK0_qice_gpu_perf_b_bypass_START (5)
#define SOC_GPU_CTRL_MSK0_qice_gpu_perf_b_bypass_END (5)
#define SOC_GPU_CTRL_MSK0_qice_gpu_dataqic_inner_bypass_START (6)
#define SOC_GPU_CTRL_MSK0_qice_gpu_dataqic_inner_bypass_END (6)
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_sub_bypass_START (7)
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_sub_bypass_END (7)
#define SOC_GPU_CTRL_MSK0_gpu_pmc_clkgt_bypass_START (8)
#define SOC_GPU_CTRL_MSK0_gpu_pmc_clkgt_bypass_END (8)
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_dataqic_bypass_START (9)
#define SOC_GPU_CTRL_MSK0_sysbus_gpu_dataqic_bypass_END (9)
#define SOC_GPU_CTRL_MSK0_sysbus_g3d_cfg_idle_bypass_START (10)
#define SOC_GPU_CTRL_MSK0_sysbus_g3d_cfg_idle_bypass_END (10)
#define SOC_GPU_CTRL_MSK0_qice_gpu_dataqic_outer_bypass_START (11)
#define SOC_GPU_CTRL_MSK0_qice_gpu_dataqic_outer_bypass_END (11)
#define SOC_GPU_CTRL_MSK0_qice_gpu_dataqic_qcp_bypass_START (12)
#define SOC_GPU_CTRL_MSK0_qice_gpu_dataqic_qcp_bypass_END (12)
#define SOC_GPU_CTRL_MSK0_GPU_CTRL_MSK0_msk_START (16)
#define SOC_GPU_CTRL_MSK0_GPU_CTRL_MSK0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_timeout_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int gpu_ib_timeout_en : 1;
        unsigned int gpu_databus_timeout_en : 1;
        unsigned int gpu_databus_qcp_timeout_en : 1;
        unsigned int gpu_cfgbus_tb_gpuxpu_timeout_en : 1;
        unsigned int reserved_1 : 10;
        unsigned int gpu_ctrl_msk1_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK1_UNION;
#endif
#define SOC_GPU_CTRL_MSK1_gpu_timeout_en_START (0)
#define SOC_GPU_CTRL_MSK1_gpu_timeout_en_END (0)
#define SOC_GPU_CTRL_MSK1_gpu_ib_timeout_en_START (2)
#define SOC_GPU_CTRL_MSK1_gpu_ib_timeout_en_END (2)
#define SOC_GPU_CTRL_MSK1_gpu_databus_timeout_en_START (3)
#define SOC_GPU_CTRL_MSK1_gpu_databus_timeout_en_END (3)
#define SOC_GPU_CTRL_MSK1_gpu_databus_qcp_timeout_en_START (4)
#define SOC_GPU_CTRL_MSK1_gpu_databus_qcp_timeout_en_END (4)
#define SOC_GPU_CTRL_MSK1_gpu_cfgbus_tb_gpuxpu_timeout_en_START (5)
#define SOC_GPU_CTRL_MSK1_gpu_cfgbus_tb_gpuxpu_timeout_en_END (5)
#define SOC_GPU_CTRL_MSK1_gpu_ctrl_msk1_msk_START (16)
#define SOC_GPU_CTRL_MSK1_gpu_ctrl_msk1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 15;
        unsigned int gpu_ctrl_msk2_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK2_UNION;
#endif
#define SOC_GPU_CTRL_MSK2_gpu_ctrl_msk2_msk_START (16)
#define SOC_GPU_CTRL_MSK2_gpu_ctrl_msk2_msk_END (31)
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
        unsigned int reserved_7: 16;
    } reg;
} SOC_GPU_CTRL_P1_MWC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 3;
        unsigned int reserved_3: 8;
        unsigned int reserved_4: 16;
    } reg;
} SOC_GPU_CTRL_P1_MWC1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_g3d_mem_sd_lowbit : 16;
        unsigned int GPU_CTRL_MSK3_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK3_UNION;
#endif
#define SOC_GPU_CTRL_MSK3_bfmux_g3d_mem_sd_lowbit_START (0)
#define SOC_GPU_CTRL_MSK3_bfmux_g3d_mem_sd_lowbit_END (15)
#define SOC_GPU_CTRL_MSK3_GPU_CTRL_MSK3_msk_START (16)
#define SOC_GPU_CTRL_MSK3_GPU_CTRL_MSK3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int GPU_CTRL_MSK4_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK4_UNION;
#endif
#define SOC_GPU_CTRL_MSK4_GPU_CTRL_MSK4_msk_START (16)
#define SOC_GPU_CTRL_MSK4_GPU_CTRL_MSK4_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bfmux_g3d_mem_sd_highbit : 16;
        unsigned int GPU_CTRL_MSK5_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK5_UNION;
#endif
#define SOC_GPU_CTRL_MSK5_bfmux_g3d_mem_sd_highbit_START (0)
#define SOC_GPU_CTRL_MSK5_bfmux_g3d_mem_sd_highbit_END (15)
#define SOC_GPU_CTRL_MSK5_GPU_CTRL_MSK5_msk_START (16)
#define SOC_GPU_CTRL_MSK5_GPU_CTRL_MSK5_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 9;
        unsigned int reserved_1 : 7;
        unsigned int GPU_CTRL_MSK6_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK6_UNION;
#endif
#define SOC_GPU_CTRL_MSK6_GPU_CTRL_MSK6_msk_START (16)
#define SOC_GPU_CTRL_MSK6_GPU_CTRL_MSK6_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_gpucfgbus_qic_nopending_rd_ib0_xpu : 1;
        unsigned int wc_gpucfgbus_qic_nopending_wr_ib0_xpu : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rd_ib1_sys2gpu : 1;
        unsigned int wc_gpucfgbus_qic_nopending_wr_ib1_sys2gpu : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rd_ib2_gpuscs : 1;
        unsigned int wc_gpucfgbus_qic_nopending_wr_ib2_gpuscs : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rd_ib3_gpu_ffap1_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_wr_ib3_gpu_ffap1_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rd_ib4_gpu_hts_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_wr_ib4_gpu_hts_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_tb0_gpuapb : 1;
        unsigned int wc_gpucfgbus_qic_nopending_tb1_gpucore : 1;
        unsigned int wc_gpucfgbus_qic_nopending_tb2_xpuahb : 1;
        unsigned int wc_gpucfgbus_qic_nopending_tb3_gpu2sys : 1;
        unsigned int wc_gpucfgbus_qic_nopending_tb4_qcp : 1;
        unsigned int wc_gpucfgbus_qic_nopending_tb5_gpu_ffap1_slv : 1;
        unsigned int wc_gpucfgbus_qic_nopending_tb6_gpu_hts_msg : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt0_gpucfg_rsp : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt0_gpucfg_req : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt1_fw_qcp_rsp : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt1_fw_qcp_req : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt2_fw_core_rsp : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt2_fw_core_req : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt_maintenance_rsp : 1;
        unsigned int wc_gpucfgbus_qic_nopending_rt_maintenance_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_GPU_CTRL_P1_MWC3_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib0_xpu_START (0)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib0_xpu_END (0)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib0_xpu_START (1)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib0_xpu_END (1)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib1_sys2gpu_START (2)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib1_sys2gpu_END (2)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib1_sys2gpu_START (3)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib1_sys2gpu_END (3)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib2_gpuscs_START (4)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib2_gpuscs_END (4)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib2_gpuscs_START (5)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib2_gpuscs_END (5)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib3_gpu_ffap1_mst_START (6)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib3_gpu_ffap1_mst_END (6)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib3_gpu_ffap1_mst_START (7)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib3_gpu_ffap1_mst_END (7)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib4_gpu_hts_mst_START (8)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rd_ib4_gpu_hts_mst_END (8)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib4_gpu_hts_mst_START (9)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_wr_ib4_gpu_hts_mst_END (9)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb0_gpuapb_START (10)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb0_gpuapb_END (10)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb1_gpucore_START (11)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb1_gpucore_END (11)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb2_xpuahb_START (12)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb2_xpuahb_END (12)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb3_gpu2sys_START (13)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb3_gpu2sys_END (13)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb4_qcp_START (14)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb4_qcp_END (14)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb5_gpu_ffap1_slv_START (15)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb5_gpu_ffap1_slv_END (15)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb6_gpu_hts_msg_START (16)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_tb6_gpu_hts_msg_END (16)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt0_gpucfg_rsp_START (17)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt0_gpucfg_rsp_END (17)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt0_gpucfg_req_START (18)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt0_gpucfg_req_END (18)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt1_fw_qcp_rsp_START (19)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt1_fw_qcp_rsp_END (19)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt1_fw_qcp_req_START (20)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt1_fw_qcp_req_END (20)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt2_fw_core_rsp_START (21)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt2_fw_core_rsp_END (21)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt2_fw_core_req_START (22)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt2_fw_core_req_END (22)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt_maintenance_rsp_START (23)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt_maintenance_rsp_END (23)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt_maintenance_req_START (24)
#define SOC_GPU_CTRL_P1_MWC3_wc_gpucfgbus_qic_nopending_rt_maintenance_req_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_em_gpu_cfg_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC4_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC4_wc_intr_em_gpu_cfg_bus_0_START (0)
#define SOC_GPU_CTRL_P1_MWC4_wc_intr_em_gpu_cfg_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_gpucfgbus_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC5_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC5_wc_qic_pdm_state_pdm_gpucfgbus_0_START (0)
#define SOC_GPU_CTRL_P1_MWC5_wc_qic_pdm_state_pdm_gpucfgbus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_gpucfgbus_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC6_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC6_wc_qic_pds_state_pds_gpucfgbus_0_START (0)
#define SOC_GPU_CTRL_P1_MWC6_wc_qic_pds_state_pds_gpucfgbus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_gpu_cfg_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC7_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC7_wc_qic_timeout_st_gpu_cfg_bus_0_START (0)
#define SOC_GPU_CTRL_P1_MWC7_wc_qic_timeout_st_gpu_cfg_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_gpucfgbus_qic_nopending_pdm0_gpuscs : 1;
        unsigned int wc_gpucfgbus_qic_nopending_pdm1_gpu_ffap1_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_pdm2_gpu_hts_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_pds0_gpuscs : 1;
        unsigned int wc_gpucfgbus_qic_nopending_pds1_gpu_ffap1_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_pds2_gpu_hts_mst : 1;
        unsigned int wc_gpucfgbus_qic_nopending_pdm0_qcp_gpusub : 1;
        unsigned int wc_gpucfgbus_qic_nopending_pds0_qcp_gpusub : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_CTRL_P1_MWC8_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm0_gpuscs_START (0)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm0_gpuscs_END (0)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm1_gpu_ffap1_mst_START (1)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm1_gpu_ffap1_mst_END (1)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm2_gpu_hts_mst_START (2)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm2_gpu_hts_mst_END (2)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds0_gpuscs_START (3)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds0_gpuscs_END (3)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds1_gpu_ffap1_mst_START (4)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds1_gpu_ffap1_mst_END (4)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds2_gpu_hts_mst_START (5)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds2_gpu_hts_mst_END (5)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm0_qcp_gpusub_START (6)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pdm0_qcp_gpusub_END (6)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds0_qcp_gpusub_START (7)
#define SOC_GPU_CTRL_P1_MWC8_wc_gpucfgbus_qic_nopending_pds0_qcp_gpusub_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_qic_probe_gpu_cfg_bus : 1;
        unsigned int wc_intr_qic_probe_gpu_data_bus : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_GPU_CTRL_P1_MWC12_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC12_wc_intr_qic_probe_gpu_cfg_bus_START (0)
#define SOC_GPU_CTRL_P1_MWC12_wc_intr_qic_probe_gpu_cfg_bus_END (0)
#define SOC_GPU_CTRL_P1_MWC12_wc_intr_qic_probe_gpu_data_bus_START (1)
#define SOC_GPU_CTRL_P1_MWC12_wc_intr_qic_probe_gpu_data_bus_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_gpucfgbus_pdc0_gpucfg_pwrd_req : 1;
        unsigned int wc_gpucfgbus_pdc1_gpusub_pwrd_req : 1;
        unsigned int wc_gpudatabus_pdc0_inner_pwrd_req : 1;
        unsigned int wc_gpudatabus_pdc1_outer_pwrd_req : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_GPU_CTRL_P1_MWC13_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC13_wc_gpucfgbus_pdc0_gpucfg_pwrd_req_START (0)
#define SOC_GPU_CTRL_P1_MWC13_wc_gpucfgbus_pdc0_gpucfg_pwrd_req_END (0)
#define SOC_GPU_CTRL_P1_MWC13_wc_gpucfgbus_pdc1_gpusub_pwrd_req_START (1)
#define SOC_GPU_CTRL_P1_MWC13_wc_gpucfgbus_pdc1_gpusub_pwrd_req_END (1)
#define SOC_GPU_CTRL_P1_MWC13_wc_gpudatabus_pdc0_inner_pwrd_req_START (2)
#define SOC_GPU_CTRL_P1_MWC13_wc_gpudatabus_pdc0_inner_pwrd_req_END (2)
#define SOC_GPU_CTRL_P1_MWC13_wc_gpudatabus_pdc1_outer_pwrd_req_START (3)
#define SOC_GPU_CTRL_P1_MWC13_wc_gpudatabus_pdc1_outer_pwrd_req_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_gpucfgbus_pdc0_gpucfg_pwrd_ack : 1;
        unsigned int wc_gpucfgbus_pdc1_gpusub_pwrd_ack : 1;
        unsigned int wc_gpudatabus_pdc0_inner_pwrd_ack : 1;
        unsigned int wc_gpudatabus_pdc1_outer_pwrd_ack : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_GPU_CTRL_P1_MWC14_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC14_wc_gpucfgbus_pdc0_gpucfg_pwrd_ack_START (0)
#define SOC_GPU_CTRL_P1_MWC14_wc_gpucfgbus_pdc0_gpucfg_pwrd_ack_END (0)
#define SOC_GPU_CTRL_P1_MWC14_wc_gpucfgbus_pdc1_gpusub_pwrd_ack_START (1)
#define SOC_GPU_CTRL_P1_MWC14_wc_gpucfgbus_pdc1_gpusub_pwrd_ack_END (1)
#define SOC_GPU_CTRL_P1_MWC14_wc_gpudatabus_pdc0_inner_pwrd_ack_START (2)
#define SOC_GPU_CTRL_P1_MWC14_wc_gpudatabus_pdc0_inner_pwrd_ack_END (2)
#define SOC_GPU_CTRL_P1_MWC14_wc_gpudatabus_pdc1_outer_pwrd_ack_START (3)
#define SOC_GPU_CTRL_P1_MWC14_wc_gpudatabus_pdc1_outer_pwrd_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_dfx_busy_ca_gpucfgbus : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC15_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC15_wc_dfx_busy_ca_gpucfgbus_START (0)
#define SOC_GPU_CTRL_P1_MWC15_wc_dfx_busy_ca_gpucfgbus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_dfx_busy_ca_gpudatabus : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC16_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC16_wc_dfx_busy_ca_gpudatabus_START (0)
#define SOC_GPU_CTRL_P1_MWC16_wc_dfx_busy_ca_gpudatabus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_gpudatabus_qic_nopending_rd_ib0r_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_wr_ib0w_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_rd_ib1r_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_wr_ib1w_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_wr_ib2_qcp0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_rd_ib2_qcp0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_tb0r_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_tb0w_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_tb1r_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_tb1w_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_tb2_qcp0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_rt1w_gpu0_rsp : 1;
        unsigned int wc_gpudatabus_qic_nopending_rt1w_gpu0_req : 1;
        unsigned int wc_gpudatabus_qic_nopending_rt1r_gpu0_rsp : 1;
        unsigned int wc_gpudatabus_qic_nopending_rt1r_gpu0_req : 1;
        unsigned int wc_gpudatabus_qic_nopending_rt_maintenance_rsp : 1;
        unsigned int wc_gpudatabus_qic_nopending_rt_maintenance_req : 1;
        unsigned int wc_gpudatabus_qic_nopending_pdm0r_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pdm0w_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pdm1r_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pdm1w_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pds0r_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pds0w_gpu_d0 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pds1r_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pds1w_gpu_d1 : 1;
        unsigned int wc_gpudatabus_qic_nopending_pdm0_qcp_gpu : 1;
        unsigned int wc_gpudatabus_qic_nopending_pds0_qcp_gpu : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_GPU_CTRL_P1_MWC17_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rd_ib0r_gpu_d0_START (0)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rd_ib0r_gpu_d0_END (0)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_wr_ib0w_gpu_d0_START (1)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_wr_ib0w_gpu_d0_END (1)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rd_ib1r_gpu_d1_START (2)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rd_ib1r_gpu_d1_END (2)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_wr_ib1w_gpu_d1_START (3)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_wr_ib1w_gpu_d1_END (3)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_wr_ib2_qcp0_START (4)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_wr_ib2_qcp0_END (4)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rd_ib2_qcp0_START (5)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rd_ib2_qcp0_END (5)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb0r_gpu_d0_START (6)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb0r_gpu_d0_END (6)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb0w_gpu_d0_START (7)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb0w_gpu_d0_END (7)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb1r_gpu_d1_START (8)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb1r_gpu_d1_END (8)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb1w_gpu_d1_START (9)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb1w_gpu_d1_END (9)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb2_qcp0_START (10)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_tb2_qcp0_END (10)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1w_gpu0_rsp_START (11)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1w_gpu0_rsp_END (11)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1w_gpu0_req_START (12)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1w_gpu0_req_END (12)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1r_gpu0_rsp_START (13)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1r_gpu0_rsp_END (13)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1r_gpu0_req_START (14)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt1r_gpu0_req_END (14)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt_maintenance_rsp_START (15)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt_maintenance_rsp_END (15)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt_maintenance_req_START (16)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_rt_maintenance_req_END (16)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm0r_gpu_d0_START (17)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm0r_gpu_d0_END (17)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm0w_gpu_d0_START (18)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm0w_gpu_d0_END (18)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm1r_gpu_d1_START (19)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm1r_gpu_d1_END (19)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm1w_gpu_d1_START (20)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm1w_gpu_d1_END (20)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds0r_gpu_d0_START (21)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds0r_gpu_d0_END (21)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds0w_gpu_d0_START (22)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds0w_gpu_d0_END (22)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds1r_gpu_d1_START (23)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds1r_gpu_d1_END (23)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds1w_gpu_d1_START (24)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds1w_gpu_d1_END (24)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm0_qcp_gpu_START (25)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pdm0_qcp_gpu_END (25)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds0_qcp_gpu_START (26)
#define SOC_GPU_CTRL_P1_MWC17_wc_gpudatabus_qic_nopending_pds0_qcp_gpu_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_gpudata_1 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC18_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC18_wc_qic_pdm_state_pdm_gpudata_1_START (0)
#define SOC_GPU_CTRL_P1_MWC18_wc_qic_pdm_state_pdm_gpudata_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_em_gpu_data_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC19_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC19_wc_intr_em_gpu_data_bus_0_START (0)
#define SOC_GPU_CTRL_P1_MWC19_wc_intr_em_gpu_data_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_gpu_data_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC22_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC22_wc_qic_timeout_st_gpu_data_bus_0_START (0)
#define SOC_GPU_CTRL_P1_MWC22_wc_qic_timeout_st_gpu_data_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpucfgbus_pdc0_gpucfg_pwrd_req : 1;
        unsigned int gpucfgbus_pdc1_gpusub_pwrd_req : 1;
        unsigned int gpudatabus_pdc0_inner_pwrd_req : 1;
        unsigned int gpudatabus_pdc1_outer_pwrd_req : 1;
        unsigned int reserved : 12;
        unsigned int GPU_CTRL_MSK7_msk : 16;
    } reg;
} SOC_GPU_CTRL_MSK7_UNION;
#endif
#define SOC_GPU_CTRL_MSK7_gpucfgbus_pdc0_gpucfg_pwrd_req_START (0)
#define SOC_GPU_CTRL_MSK7_gpucfgbus_pdc0_gpucfg_pwrd_req_END (0)
#define SOC_GPU_CTRL_MSK7_gpucfgbus_pdc1_gpusub_pwrd_req_START (1)
#define SOC_GPU_CTRL_MSK7_gpucfgbus_pdc1_gpusub_pwrd_req_END (1)
#define SOC_GPU_CTRL_MSK7_gpudatabus_pdc0_inner_pwrd_req_START (2)
#define SOC_GPU_CTRL_MSK7_gpudatabus_pdc0_inner_pwrd_req_END (2)
#define SOC_GPU_CTRL_MSK7_gpudatabus_pdc1_outer_pwrd_req_START (3)
#define SOC_GPU_CTRL_MSK7_gpudatabus_pdc1_outer_pwrd_req_END (3)
#define SOC_GPU_CTRL_MSK7_GPU_CTRL_MSK7_msk_START (16)
#define SOC_GPU_CTRL_MSK7_GPU_CTRL_MSK7_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pdm_state_pdm_gpudata_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC23_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC23_wc_qic_pdm_state_pdm_gpudata_0_START (0)
#define SOC_GPU_CTRL_P1_MWC23_wc_qic_pdm_state_pdm_gpudata_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_pds_state_pds_gpudata_0 : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC24_UNION;
#endif
#define SOC_GPU_CTRL_P1_MWC24_wc_qic_pds_state_pds_gpudata_0_START (0)
#define SOC_GPU_CTRL_P1_MWC24_wc_qic_pds_state_pds_gpudata_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_P1_MWC25_UNION;
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
        unsigned int reserved_6: 26;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 24;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_scs_mst_valid : 1;
        unsigned int gpu_ffap1_mst_valid : 1;
        unsigned int gpu_hts_mst_valid : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_2_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_2_gpu_scs_mst_valid_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_2_gpu_scs_mst_valid_END (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_2_gpu_ffap1_mst_valid_START (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_2_gpu_ffap1_mst_valid_END (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_2_gpu_hts_mst_valid_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_2_gpu_hts_mst_valid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_stat_rsv0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_3_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_3_gpu_stat_rsv0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_3_gpu_stat_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 20;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 2;
        unsigned int reserved_5: 3;
        unsigned int reserved_6: 8;
        unsigned int reserved_7: 10;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 2;
        unsigned int reserved_5: 3;
        unsigned int reserved_6: 8;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 2;
        unsigned int reserved_9: 4;
        unsigned int reserved_10: 3;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 12;
        unsigned int reserved_1: 8;
        unsigned int reserved_2: 12;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 12;
        unsigned int reserved_1: 8;
        unsigned int reserved_2: 12;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g3d_cfc0_busy : 1;
        unsigned int g3d_cfc1_busy : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_13_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_13_g3d_cfc0_busy_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_13_g3d_cfc0_busy_END (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_13_g3d_cfc1_busy_START (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_13_g3d_cfc1_busy_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 12;
        unsigned int reserved_1: 7;
        unsigned int reserved_2: 13;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cfg2gpu_pwrqactives_o : 1;
        unsigned int cfg2gpu_pwrqacceptns_o : 1;
        unsigned int cfg2gpu_pwrqdenys_o : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_16_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_16_cfg2gpu_pwrqactives_o_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_16_cfg2gpu_pwrqactives_o_END (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_16_cfg2gpu_pwrqacceptns_o_START (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_16_cfg2gpu_pwrqacceptns_o_END (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_16_cfg2gpu_pwrqdenys_o_START (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_16_cfg2gpu_pwrqdenys_o_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cactive_adb_g3d_0 : 1;
        unsigned int csysaccept_adb_g3d_0 : 1;
        unsigned int csysdeney_adb_g3d_0 : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_17_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_17_cactive_adb_g3d_0_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_17_cactive_adb_g3d_0_END (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_17_csysaccept_adb_g3d_0_START (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_17_csysaccept_adb_g3d_0_END (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_17_csysdeney_adb_g3d_0_START (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_17_csysdeney_adb_g3d_0_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cactive_adb_g3d_1 : 1;
        unsigned int csysaccept_adb_g3d_1 : 1;
        unsigned int csysdeney_adb_g3d_1 : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_18_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_18_cactive_adb_g3d_1_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_18_cactive_adb_g3d_1_END (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_18_csysaccept_adb_g3d_1_START (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_18_csysaccept_adb_g3d_1_END (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_18_csysdeney_adb_g3d_1_START (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_18_csysdeney_adb_g3d_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpudatabus_qic_nopending_rd_ib0r_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_wr_ib0w_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_rd_ib1r_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_wr_ib1w_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_wr_ib2_qcp0 : 1;
        unsigned int gpudatabus_qic_nopending_rd_ib2_qcp0 : 1;
        unsigned int gpudatabus_qic_nopending_tb0r_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_tb0w_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_tb1r_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_tb1w_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_tb2_qcp0 : 1;
        unsigned int gpudatabus_qic_nopending_rt1w_gpu0_rsp : 1;
        unsigned int gpudatabus_qic_nopending_rt1w_gpu0_req : 1;
        unsigned int gpudatabus_qic_nopending_rt1r_gpu0_rsp : 1;
        unsigned int gpudatabus_qic_nopending_rt1r_gpu0_req : 1;
        unsigned int gpudatabus_qic_nopending_rt_maintenance_rsp : 1;
        unsigned int gpudatabus_qic_nopending_rt_maintenance_req : 1;
        unsigned int gpudatabus_qic_nopending_pdm0r_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_pdm0w_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_pdm1r_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_pdm1w_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_pds0r_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_pds0w_gpu_d0 : 1;
        unsigned int gpudatabus_qic_nopending_pds1r_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_pds1w_gpu_d1 : 1;
        unsigned int gpudatabus_qic_nopending_pdm0_qcp_gpu : 1;
        unsigned int gpudatabus_qic_nopending_pds0_qcp_gpu : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_19_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rd_ib0r_gpu_d0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rd_ib0r_gpu_d0_END (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_wr_ib0w_gpu_d0_START (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_wr_ib0w_gpu_d0_END (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rd_ib1r_gpu_d1_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rd_ib1r_gpu_d1_END (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_wr_ib1w_gpu_d1_START (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_wr_ib1w_gpu_d1_END (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_wr_ib2_qcp0_START (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_wr_ib2_qcp0_END (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rd_ib2_qcp0_START (5)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rd_ib2_qcp0_END (5)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb0r_gpu_d0_START (6)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb0r_gpu_d0_END (6)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb0w_gpu_d0_START (7)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb0w_gpu_d0_END (7)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb1r_gpu_d1_START (8)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb1r_gpu_d1_END (8)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb1w_gpu_d1_START (9)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb1w_gpu_d1_END (9)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb2_qcp0_START (10)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_tb2_qcp0_END (10)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1w_gpu0_rsp_START (11)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1w_gpu0_rsp_END (11)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1w_gpu0_req_START (12)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1w_gpu0_req_END (12)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1r_gpu0_rsp_START (13)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1r_gpu0_rsp_END (13)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1r_gpu0_req_START (14)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt1r_gpu0_req_END (14)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt_maintenance_rsp_START (15)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt_maintenance_rsp_END (15)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt_maintenance_req_START (16)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_rt_maintenance_req_END (16)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm0r_gpu_d0_START (17)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm0r_gpu_d0_END (17)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm0w_gpu_d0_START (18)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm0w_gpu_d0_END (18)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm1r_gpu_d1_START (19)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm1r_gpu_d1_END (19)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm1w_gpu_d1_START (20)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm1w_gpu_d1_END (20)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds0r_gpu_d0_START (21)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds0r_gpu_d0_END (21)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds0w_gpu_d0_START (22)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds0w_gpu_d0_END (22)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds1r_gpu_d1_START (23)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds1r_gpu_d1_END (23)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds1w_gpu_d1_START (24)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds1w_gpu_d1_END (24)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm0_qcp_gpu_START (25)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pdm0_qcp_gpu_END (25)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds0_qcp_gpu_START (26)
#define SOC_GPU_CTRL_GPU_STAT_P2_19_gpudatabus_qic_nopending_pds0_qcp_gpu_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpucfgbus_qic_nopending_pdm0_gpuscs : 1;
        unsigned int gpucfgbus_qic_nopending_pdm1_gpu_ffap1_mst : 1;
        unsigned int gpucfgbus_qic_nopending_pdm2_gpu_hts_mst : 1;
        unsigned int gpucfgbus_qic_nopending_pds0_gpuscs : 1;
        unsigned int gpucfgbus_qic_nopending_pds1_gpu_ffap1_mst : 1;
        unsigned int gpucfgbus_qic_nopending_pds2_gpu_hts_mst : 1;
        unsigned int gpucfgbus_qic_nopending_pdm0_qcp_gpusub : 1;
        unsigned int gpucfgbus_qic_nopending_pds0_qcp_gpusub : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_20_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm0_gpuscs_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm0_gpuscs_END (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm1_gpu_ffap1_mst_START (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm1_gpu_ffap1_mst_END (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm2_gpu_hts_mst_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm2_gpu_hts_mst_END (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds0_gpuscs_START (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds0_gpuscs_END (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds1_gpu_ffap1_mst_START (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds1_gpu_ffap1_mst_END (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds2_gpu_hts_mst_START (5)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds2_gpu_hts_mst_END (5)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm0_qcp_gpusub_START (6)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pdm0_qcp_gpusub_END (6)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds0_qcp_gpusub_START (7)
#define SOC_GPU_CTRL_GPU_STAT_P2_20_gpucfgbus_qic_nopending_pds0_qcp_gpusub_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int afmux_mem_sta_sd_gpu : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_21_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_21_afmux_mem_sta_sd_gpu_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_21_afmux_mem_sta_sd_gpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpucfgbus_qic_nopending_rd_ib0_xpu : 1;
        unsigned int gpucfgbus_qic_nopending_wr_ib0_xpu : 1;
        unsigned int gpucfgbus_qic_nopending_rd_ib1_sys2gpu : 1;
        unsigned int gpucfgbus_qic_nopending_wr_ib1_sys2gpu : 1;
        unsigned int gpucfgbus_qic_nopending_rd_ib2_gpuscs : 1;
        unsigned int gpucfgbus_qic_nopending_wr_ib2_gpuscs : 1;
        unsigned int gpucfgbus_qic_nopending_rd_ib3_gpu_ffap1_mst : 1;
        unsigned int gpucfgbus_qic_nopending_wr_ib3_gpu_ffap1_mst : 1;
        unsigned int gpucfgbus_qic_nopending_rd_ib4_gpu_hts_mst : 1;
        unsigned int gpucfgbus_qic_nopending_wr_ib4_gpu_hts_mst : 1;
        unsigned int gpucfgbus_qic_nopending_tb0_gpuapb : 1;
        unsigned int gpucfgbus_qic_nopending_tb1_gpucore : 1;
        unsigned int gpucfgbus_qic_nopending_tb2_xpuahb : 1;
        unsigned int gpucfgbus_qic_nopending_tb3_gpu2sys : 1;
        unsigned int gpucfgbus_qic_nopending_tb4_qcp : 1;
        unsigned int gpucfgbus_qic_nopending_tb5_gpu_ffap1_slv : 1;
        unsigned int gpucfgbus_qic_nopending_tb6_gpu_hts_msg : 1;
        unsigned int gpucfgbus_qic_nopending_rt0_gpucfg_rsp : 1;
        unsigned int gpucfgbus_qic_nopending_rt0_gpucfg_req : 1;
        unsigned int gpucfgbus_qic_nopending_rt1_fw_qcp_rsp : 1;
        unsigned int gpucfgbus_qic_nopending_rt1_fw_qcp_req : 1;
        unsigned int gpucfgbus_qic_nopending_rt2_fw_core_rsp : 1;
        unsigned int gpucfgbus_qic_nopending_rt2_fw_core_req : 1;
        unsigned int gpucfgbus_qic_nopending_rt_maintenance_rsp : 1;
        unsigned int gpucfgbus_qic_nopending_rt_maintenance_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_23_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib0_xpu_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib0_xpu_END (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib0_xpu_START (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib0_xpu_END (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib1_sys2gpu_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib1_sys2gpu_END (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib1_sys2gpu_START (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib1_sys2gpu_END (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib2_gpuscs_START (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib2_gpuscs_END (4)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib2_gpuscs_START (5)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib2_gpuscs_END (5)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib3_gpu_ffap1_mst_START (6)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib3_gpu_ffap1_mst_END (6)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib3_gpu_ffap1_mst_START (7)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib3_gpu_ffap1_mst_END (7)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib4_gpu_hts_mst_START (8)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rd_ib4_gpu_hts_mst_END (8)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib4_gpu_hts_mst_START (9)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_wr_ib4_gpu_hts_mst_END (9)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb0_gpuapb_START (10)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb0_gpuapb_END (10)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb1_gpucore_START (11)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb1_gpucore_END (11)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb2_xpuahb_START (12)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb2_xpuahb_END (12)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb3_gpu2sys_START (13)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb3_gpu2sys_END (13)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb4_qcp_START (14)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb4_qcp_END (14)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb5_gpu_ffap1_slv_START (15)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb5_gpu_ffap1_slv_END (15)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb6_gpu_hts_msg_START (16)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_tb6_gpu_hts_msg_END (16)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt0_gpucfg_rsp_START (17)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt0_gpucfg_rsp_END (17)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt0_gpucfg_req_START (18)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt0_gpucfg_req_END (18)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt1_fw_qcp_rsp_START (19)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt1_fw_qcp_rsp_END (19)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt1_fw_qcp_req_START (20)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt1_fw_qcp_req_END (20)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt2_fw_core_rsp_START (21)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt2_fw_core_rsp_END (21)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt2_fw_core_req_START (22)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt2_fw_core_req_END (22)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt_maintenance_rsp_START (23)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt_maintenance_rsp_END (23)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt_maintenance_req_START (24)
#define SOC_GPU_CTRL_GPU_STAT_P2_23_gpucfgbus_qic_nopending_rt_maintenance_req_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_em_gpu_cfg_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_24_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_24_intr_em_gpu_cfg_bus_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_24_intr_em_gpu_cfg_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_gpucfgbus_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_25_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_25_qic_pdm_state_pdm_gpucfgbus_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_25_qic_pdm_state_pdm_gpucfgbus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_gpucfgbus_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_26_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_26_qic_pds_state_pds_gpucfgbus_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_26_qic_pds_state_pds_gpucfgbus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_gpu_cfg_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_27_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_27_qic_timeout_st_gpu_cfg_bus_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_27_qic_timeout_st_gpu_cfg_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mtcmos_gpu_ack : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_28_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_28_mtcmos_gpu_ack_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_28_mtcmos_gpu_ack_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_29_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_30_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_probe_gpu_cfg_bus : 1;
        unsigned int intr_qic_probe_gpu_data_bus : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_31_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_31_intr_qic_probe_gpu_cfg_bus_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_31_intr_qic_probe_gpu_cfg_bus_END (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_31_intr_qic_probe_gpu_data_bus_START (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_31_intr_qic_probe_gpu_data_bus_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_32_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_33_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_busy_ca_gpucfgbus : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_34_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_34_dfx_busy_ca_gpucfgbus_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_34_dfx_busy_ca_gpucfgbus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_busy_ca_gpudatabus : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_35_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_35_dfx_busy_ca_gpudatabus_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_35_dfx_busy_ca_gpudatabus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_gpudata_1 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_36_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_36_qic_pdm_state_pdm_gpudata_1_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_36_qic_pdm_state_pdm_gpudata_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_em_gpu_data_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_37_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_37_intr_em_gpu_data_bus_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_37_intr_em_gpu_data_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_38_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_39_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_gpu_data_bus_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_40_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_40_qic_timeout_st_gpu_data_bus_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_40_qic_timeout_st_gpu_data_bus_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpucfgbus_pdc0_gpucfg_pwrd_ack : 1;
        unsigned int gpucfgbus_pdc1_gpusub_pwrd_ack : 1;
        unsigned int gpudatabus_pdc0_inner_pwrd_ack : 1;
        unsigned int gpudatabus_pdc1_outer_pwrd_ack : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_41_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpucfgbus_pdc0_gpucfg_pwrd_ack_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpucfgbus_pdc0_gpucfg_pwrd_ack_END (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpucfgbus_pdc1_gpusub_pwrd_ack_START (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpucfgbus_pdc1_gpusub_pwrd_ack_END (1)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpudatabus_pdc0_inner_pwrd_ack_START (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpudatabus_pdc0_inner_pwrd_ack_END (2)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpudatabus_pdc1_outer_pwrd_ack_START (3)
#define SOC_GPU_CTRL_GPU_STAT_P2_41_gpudatabus_pdc1_outer_pwrd_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pdm_state_pdm_gpudata_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_42_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_42_qic_pdm_state_pdm_gpudata_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_42_qic_pdm_state_pdm_gpudata_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_pds_state_pds_gpudata_0 : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_43_UNION;
#endif
#define SOC_GPU_CTRL_GPU_STAT_P2_43_qic_pds_state_pds_gpudata_0_START (0)
#define SOC_GPU_CTRL_GPU_STAT_P2_43_qic_pds_state_pds_gpudata_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P2_44_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g3d_icfg_cfc_en : 1;
        unsigned int g3d_icfg_cfc_bw : 8;
        unsigned int g3d_icfg_cfc_stat : 8;
        unsigned int g3d_icfg_cfc_lp : 2;
        unsigned int reserved : 13;
    } reg;
} SOC_GPU_CTRL_P3_0_UNION;
#endif
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_en_START (0)
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_en_END (0)
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_bw_START (1)
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_bw_END (8)
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_stat_START (9)
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_stat_END (16)
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_lp_START (17)
#define SOC_GPU_CTRL_P3_0_g3d_icfg_cfc_lp_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 30;
    } reg;
} SOC_GPU_CTRL_GPU_STAT_P3_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g3d_xsecure_n_set : 1;
        unsigned int reserved_0 : 7;
        unsigned int tz_secure_n_gpu_ctrl_set : 4;
        unsigned int tz_secure_n_gpu_crg_set : 1;
        unsigned int reserved_1 : 1;
        unsigned int tz_secure_n_gpu_databus_set : 1;
        unsigned int reserved_2 : 1;
        unsigned int tz_secure_n_gpu_lp_ctrl_set : 16;
    } reg;
} SOC_GPU_CTRL_P4_0_SET_UNION;
#endif
#define SOC_GPU_CTRL_P4_0_SET_g3d_xsecure_n_set_START (0)
#define SOC_GPU_CTRL_P4_0_SET_g3d_xsecure_n_set_END (0)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_ctrl_set_START (8)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_ctrl_set_END (11)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_crg_set_START (12)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_crg_set_END (12)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_databus_set_START (14)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_databus_set_END (14)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_lp_ctrl_set_START (16)
#define SOC_GPU_CTRL_P4_0_SET_tz_secure_n_gpu_lp_ctrl_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g3d_xsecure_n_clr : 1;
        unsigned int reserved_0 : 7;
        unsigned int tz_secure_n_gpu_ctrl_clr : 4;
        unsigned int tz_secure_n_gpu_crg_clr : 1;
        unsigned int reserved_1 : 1;
        unsigned int tz_secure_n_gpu_databus_clr : 1;
        unsigned int reserved_2 : 1;
        unsigned int tz_secure_n_gpu_lp_ctrl_clr : 16;
    } reg;
} SOC_GPU_CTRL_P4_0_CLR_UNION;
#endif
#define SOC_GPU_CTRL_P4_0_CLR_g3d_xsecure_n_clr_START (0)
#define SOC_GPU_CTRL_P4_0_CLR_g3d_xsecure_n_clr_END (0)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_ctrl_clr_START (8)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_ctrl_clr_END (11)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_crg_clr_START (12)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_crg_clr_END (12)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_databus_clr_START (14)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_databus_clr_END (14)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_lp_ctrl_clr_START (16)
#define SOC_GPU_CTRL_P4_0_CLR_tz_secure_n_gpu_lp_ctrl_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g3d_xsecure_n : 1;
        unsigned int reserved_0 : 7;
        unsigned int tz_secure_n_gpu_ctrl : 4;
        unsigned int tz_secure_n_gpu_crg : 1;
        unsigned int reserved_1 : 1;
        unsigned int tz_secure_n_gpu_databus : 1;
        unsigned int reserved_2 : 1;
        unsigned int tz_secure_n_gpu_lp_ctrl : 16;
    } reg;
} SOC_GPU_CTRL_P4_0_STA_UNION;
#endif
#define SOC_GPU_CTRL_P4_0_STA_g3d_xsecure_n_START (0)
#define SOC_GPU_CTRL_P4_0_STA_g3d_xsecure_n_END (0)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_ctrl_START (8)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_ctrl_END (11)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_crg_START (12)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_crg_END (12)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_databus_START (14)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_databus_END (14)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_lp_ctrl_START (16)
#define SOC_GPU_CTRL_P4_0_STA_tz_secure_n_gpu_lp_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_slv_sec_flag_tb_gpu_qcp_slv_set : 8;
        unsigned int qic_slv_sec_flag_tb_gpu_core_slv_set : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_CTRL_P4_1_SET_UNION;
#endif
#define SOC_GPU_CTRL_P4_1_SET_qic_slv_sec_flag_tb_gpu_qcp_slv_set_START (0)
#define SOC_GPU_CTRL_P4_1_SET_qic_slv_sec_flag_tb_gpu_qcp_slv_set_END (7)
#define SOC_GPU_CTRL_P4_1_SET_qic_slv_sec_flag_tb_gpu_core_slv_set_START (8)
#define SOC_GPU_CTRL_P4_1_SET_qic_slv_sec_flag_tb_gpu_core_slv_set_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_slv_sec_flag_tb_gpu_qcp_slv_clr : 8;
        unsigned int qic_slv_sec_flag_tb_gpu_core_slv_clr : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_CTRL_P4_1_CLR_UNION;
#endif
#define SOC_GPU_CTRL_P4_1_CLR_qic_slv_sec_flag_tb_gpu_qcp_slv_clr_START (0)
#define SOC_GPU_CTRL_P4_1_CLR_qic_slv_sec_flag_tb_gpu_qcp_slv_clr_END (7)
#define SOC_GPU_CTRL_P4_1_CLR_qic_slv_sec_flag_tb_gpu_core_slv_clr_START (8)
#define SOC_GPU_CTRL_P4_1_CLR_qic_slv_sec_flag_tb_gpu_core_slv_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_slv_sec_flag_tb_gpu_qcp_slv : 8;
        unsigned int qic_slv_sec_flag_tb_gpu_core_slv : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_CTRL_P4_1_STA_UNION;
#endif
#define SOC_GPU_CTRL_P4_1_STA_qic_slv_sec_flag_tb_gpu_qcp_slv_START (0)
#define SOC_GPU_CTRL_P4_1_STA_qic_slv_sec_flag_tb_gpu_qcp_slv_END (7)
#define SOC_GPU_CTRL_P4_1_STA_qic_slv_sec_flag_tb_gpu_core_slv_START (8)
#define SOC_GPU_CTRL_P4_1_STA_qic_slv_sec_flag_tb_gpu_core_slv_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 30;
    } reg;
} SOC_GPU_CTRL_P4_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 32;
    } reg;
} SOC_GPU_CTRL_LOCK_UNION;
#endif
#define SOC_GPU_CTRL_LOCK_lock_START (0)
#define SOC_GPU_CTRL_LOCK_lock_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
