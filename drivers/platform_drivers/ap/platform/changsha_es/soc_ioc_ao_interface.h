#ifndef __SOC_IOC_AO_INTERFACE_H__
#define __SOC_IOC_AO_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_AO_IOCG_0_ADDR(base) ((base) + 0x800UL)
#define SOC_IOC_AO_IOCG_1_ADDR(base) ((base) + 0x804UL)
#define SOC_IOC_AO_IOCG_2_ADDR(base) ((base) + 0x808UL)
#define SOC_IOC_AO_IOCG_3_ADDR(base) ((base) + 0x80cUL)
#define SOC_IOC_AO_IOCG_4_ADDR(base) ((base) + 0x810UL)
#define SOC_IOC_AO_IOCG_5_ADDR(base) ((base) + 0x814UL)
#define SOC_IOC_AO_IOCG_6_ADDR(base) ((base) + 0x818UL)
#define SOC_IOC_AO_IOCG_7_ADDR(base) ((base) + 0x81cUL)
#define SOC_IOC_AO_IOCG_SE_0_ADDR(base) ((base) + 0xe00UL)
#define SOC_IOC_AO_IOCG_SE_1_ADDR(base) ((base) + 0xe04UL)
#define SOC_IOC_AO_IOCG_SE_2_ADDR(base) ((base) + 0xe08UL)
#define SOC_IOC_AO_IOCG_SE_3_ADDR(base) ((base) + 0xe0cUL)
#define SOC_IOC_AO_IOCG_SE_4_ADDR(base) ((base) + 0xe10UL)
#define SOC_IOC_AO_IOCG_SE_5_ADDR(base) ((base) + 0xe14UL)
#define SOC_IOC_AO_IOCG_SE_6_ADDR(base) ((base) + 0xe18UL)
#define SOC_IOC_AO_IOCG_SE_7_ADDR(base) ((base) + 0xe1cUL)
#define SOC_IOC_AO_IOCG_SE_8_ADDR(base) ((base) + 0xe20UL)
#define SOC_IOC_AO_IOCG_SE_9_ADDR(base) ((base) + 0xe24UL)
#define SOC_IOC_AO_IOCG_SE_10_ADDR(base) ((base) + 0xe28UL)
#define SOC_IOC_AO_IOCG_SE_11_ADDR(base) ((base) + 0xe2cUL)
#define SOC_IOC_AO_IOCG_8_ADDR(base) ((base) + 0x820UL)
#define SOC_IOC_AO_IOCG_SE_12_ADDR(base) ((base) + 0xe30UL)
#define SOC_IOC_AO_IOCG_SE_13_ADDR(base) ((base) + 0xe34UL)
#define SOC_IOC_AO_IOCG_SE_14_ADDR(base) ((base) + 0xe38UL)
#define SOC_IOC_AO_IOCG_SE_15_ADDR(base) ((base) + 0xe3cUL)
#define SOC_IOC_AO_IOCG_SE_16_ADDR(base) ((base) + 0xe40UL)
#define SOC_IOC_AO_IOCG_9_ADDR(base) ((base) + 0x824UL)
#define SOC_IOC_AO_IOCG_SE_17_ADDR(base) ((base) + 0xe44UL)
#define SOC_IOC_AO_IOCG_SE_18_ADDR(base) ((base) + 0xe48UL)
#define SOC_IOC_AO_IOCG_SE_19_ADDR(base) ((base) + 0xe4cUL)
#define SOC_IOC_AO_IOCG_SE_20_ADDR(base) ((base) + 0xe50UL)
#define SOC_IOC_AO_IOCG_SE_21_ADDR(base) ((base) + 0xe54UL)
#define SOC_IOC_AO_IOCG_SE_22_ADDR(base) ((base) + 0xe58UL)
#define SOC_IOC_AO_IOCG_SE_23_ADDR(base) ((base) + 0xe5cUL)
#define SOC_IOC_AO_IOCG_SE_24_ADDR(base) ((base) + 0xe60UL)
#define SOC_IOC_AO_IOCG_SE_25_ADDR(base) ((base) + 0xe64UL)
#define SOC_IOC_AO_IOCG_10_ADDR(base) ((base) + 0x828UL)
#define SOC_IOC_AO_IOCG_11_ADDR(base) ((base) + 0x82cUL)
#define SOC_IOC_AO_IOCG_12_ADDR(base) ((base) + 0x830UL)
#define SOC_IOC_AO_IOCG_13_ADDR(base) ((base) + 0x834UL)
#define SOC_IOC_AO_IOCG_SE_26_ADDR(base) ((base) + 0xe68UL)
#define SOC_IOC_AO_IOCG_SE_27_ADDR(base) ((base) + 0xe6cUL)
#define SOC_IOC_AO_IOCG_SE_28_ADDR(base) ((base) + 0xe70UL)
#define SOC_IOC_AO_IOCG_SE_29_ADDR(base) ((base) + 0xe74UL)
#define SOC_IOC_AO_IOCG_SE_30_ADDR(base) ((base) + 0xe78UL)
#define SOC_IOC_AO_IOCG_SE_31_ADDR(base) ((base) + 0xe7cUL)
#define SOC_IOC_AO_IOCG_SE_32_ADDR(base) ((base) + 0xe80UL)
#define SOC_IOC_AO_IOCG_SE_33_ADDR(base) ((base) + 0xe84UL)
#define SOC_IOC_AO_IOCG_SE_34_ADDR(base) ((base) + 0xe88UL)
#define SOC_IOC_AO_IOCG_SE_35_ADDR(base) ((base) + 0xe8cUL)
#define SOC_IOC_AO_IOCG_SE_36_ADDR(base) ((base) + 0xe90UL)
#define SOC_IOC_AO_IOCG_SE_37_ADDR(base) ((base) + 0xe94UL)
#define SOC_IOC_AO_IOCG_SE_38_ADDR(base) ((base) + 0xe98UL)
#define SOC_IOC_AO_IOCG_SE_39_ADDR(base) ((base) + 0xe9cUL)
#define SOC_IOC_AO_IOCG_14_ADDR(base) ((base) + 0x838UL)
#define SOC_IOC_AO_IOCG_15_ADDR(base) ((base) + 0x83cUL)
#define SOC_IOC_AO_IOCG_16_ADDR(base) ((base) + 0x840UL)
#define SOC_IOC_AO_IOCG_17_ADDR(base) ((base) + 0x844UL)
#define SOC_IOC_AO_IOCG_18_ADDR(base) ((base) + 0x848UL)
#define SOC_IOC_AO_IOCG_19_ADDR(base) ((base) + 0x84cUL)
#define SOC_IOC_AO_IOCG_20_ADDR(base) ((base) + 0x850UL)
#define SOC_IOC_AO_IOCG_21_ADDR(base) ((base) + 0x854UL)
#define SOC_IOC_AO_IOCG_SE_40_ADDR(base) ((base) + 0xea0UL)
#define SOC_IOC_AO_IOCG_22_ADDR(base) ((base) + 0x858UL)
#define SOC_IOC_AO_IOCG_23_ADDR(base) ((base) + 0x85cUL)
#define SOC_IOC_AO_IOCG_24_ADDR(base) ((base) + 0x860UL)
#define SOC_IOC_AO_IOCG_25_ADDR(base) ((base) + 0x864UL)
#define SOC_IOC_AO_IOCG_26_ADDR(base) ((base) + 0x868UL)
#define SOC_IOC_AO_IOCG_SE_41_ADDR(base) ((base) + 0xea4UL)
#define SOC_IOC_AO_IOCG_SE_42_ADDR(base) ((base) + 0xea8UL)
#define SOC_IOC_AO_IOCG_SE_43_ADDR(base) ((base) + 0xeacUL)
#define SOC_IOC_AO_IOCG_SE_44_ADDR(base) ((base) + 0xeb0UL)
#define SOC_IOC_AO_IOCG_SE_45_ADDR(base) ((base) + 0xeb4UL)
#define SOC_IOC_AO_IOCG_SE_46_ADDR(base) ((base) + 0xeb8UL)
#define SOC_IOC_AO_IOCG_SE_47_ADDR(base) ((base) + 0xebcUL)
#define SOC_IOC_AO_IOCG_SE_48_ADDR(base) ((base) + 0xec0UL)
#define SOC_IOC_AO_IOCG_SE_49_ADDR(base) ((base) + 0xec4UL)
#define SOC_IOC_AO_IOCG_SE_50_ADDR(base) ((base) + 0xec8UL)
#define SOC_IOC_AO_IOCG_SE_51_ADDR(base) ((base) + 0xeccUL)
#define SOC_IOC_AO_IOCG_SE_52_ADDR(base) ((base) + 0xed0UL)
#define SOC_IOC_AO_IOCG_SE_53_ADDR(base) ((base) + 0xed4UL)
#define SOC_IOC_AO_IOCG_SE_54_ADDR(base) ((base) + 0xed8UL)
#define SOC_IOC_AO_IOCG_27_ADDR(base) ((base) + 0x86cUL)
#define SOC_IOC_AO_IOCG_28_ADDR(base) ((base) + 0x870UL)
#define SOC_IOC_AO_IOCG_SE_55_ADDR(base) ((base) + 0xedcUL)
#define SOC_IOC_AO_IOCG_29_ADDR(base) ((base) + 0x874UL)
#define SOC_IOC_AO_IOCG_30_ADDR(base) ((base) + 0x878UL)
#define SOC_IOC_AO_IOCG_SE_56_ADDR(base) ((base) + 0xee0UL)
#define SOC_IOC_AO_IOCG_SE_57_ADDR(base) ((base) + 0xee4UL)
#define SOC_IOC_AO_IOCG_SE_58_ADDR(base) ((base) + 0xee8UL)
#define SOC_IOC_AO_IOCG_SE_59_ADDR(base) ((base) + 0xeecUL)
#define SOC_IOC_AO_IOCG_31_ADDR(base) ((base) + 0x87cUL)
#define SOC_IOC_AO_IOCG_32_ADDR(base) ((base) + 0x880UL)
#define SOC_IOC_AO_IOCG_33_ADDR(base) ((base) + 0x884UL)
#define SOC_IOC_AO_IOCG_34_ADDR(base) ((base) + 0x888UL)
#define SOC_IOC_AO_IOCG_SE_60_ADDR(base) ((base) + 0xef0UL)
#define SOC_IOC_AO_IOCG_SE_61_ADDR(base) ((base) + 0xef4UL)
#define SOC_IOC_AO_IOCG_SE_62_ADDR(base) ((base) + 0xef8UL)
#define SOC_IOC_AO_IOCG_SE_63_ADDR(base) ((base) + 0xefcUL)
#define SOC_IOC_AO_IOCG_SE_64_ADDR(base) ((base) + 0xf00UL)
#define SOC_IOC_AO_IOCG_35_ADDR(base) ((base) + 0x88cUL)
#define SOC_IOC_AO_IOCG_36_ADDR(base) ((base) + 0x890UL)
#define SOC_IOC_AO_IOCG_37_ADDR(base) ((base) + 0x894UL)
#define SOC_IOC_AO_IOCG_38_ADDR(base) ((base) + 0x898UL)
#define SOC_IOC_AO_IOCG_39_ADDR(base) ((base) + 0x89cUL)
#define SOC_IOC_AO_IOCG_40_ADDR(base) ((base) + 0x8a0UL)
#define SOC_IOC_AO_IOCG_41_ADDR(base) ((base) + 0x8a4UL)
#define SOC_IOC_AO_IOCG_SE_65_ADDR(base) ((base) + 0xf04UL)
#define SOC_IOC_AO_IOCG_SE_66_ADDR(base) ((base) + 0xf08UL)
#define SOC_IOC_AO_IOCG_SE_67_ADDR(base) ((base) + 0xf0cUL)
#define SOC_IOC_AO_IOCG_SE_68_ADDR(base) ((base) + 0xf10UL)
#define SOC_IOC_AO_IOCG_SE_69_ADDR(base) ((base) + 0xf14UL)
#define SOC_IOC_AO_IOCG_42_ADDR(base) ((base) + 0x8a8UL)
#define SOC_IOC_AO_IOCG_SE_70_ADDR(base) ((base) + 0xf18UL)
#else
#define SOC_IOC_AO_IOCG_0_ADDR(base) ((base) + 0x800)
#define SOC_IOC_AO_IOCG_1_ADDR(base) ((base) + 0x804)
#define SOC_IOC_AO_IOCG_2_ADDR(base) ((base) + 0x808)
#define SOC_IOC_AO_IOCG_3_ADDR(base) ((base) + 0x80c)
#define SOC_IOC_AO_IOCG_4_ADDR(base) ((base) + 0x810)
#define SOC_IOC_AO_IOCG_5_ADDR(base) ((base) + 0x814)
#define SOC_IOC_AO_IOCG_6_ADDR(base) ((base) + 0x818)
#define SOC_IOC_AO_IOCG_7_ADDR(base) ((base) + 0x81c)
#define SOC_IOC_AO_IOCG_SE_0_ADDR(base) ((base) + 0xe00)
#define SOC_IOC_AO_IOCG_SE_1_ADDR(base) ((base) + 0xe04)
#define SOC_IOC_AO_IOCG_SE_2_ADDR(base) ((base) + 0xe08)
#define SOC_IOC_AO_IOCG_SE_3_ADDR(base) ((base) + 0xe0c)
#define SOC_IOC_AO_IOCG_SE_4_ADDR(base) ((base) + 0xe10)
#define SOC_IOC_AO_IOCG_SE_5_ADDR(base) ((base) + 0xe14)
#define SOC_IOC_AO_IOCG_SE_6_ADDR(base) ((base) + 0xe18)
#define SOC_IOC_AO_IOCG_SE_7_ADDR(base) ((base) + 0xe1c)
#define SOC_IOC_AO_IOCG_SE_8_ADDR(base) ((base) + 0xe20)
#define SOC_IOC_AO_IOCG_SE_9_ADDR(base) ((base) + 0xe24)
#define SOC_IOC_AO_IOCG_SE_10_ADDR(base) ((base) + 0xe28)
#define SOC_IOC_AO_IOCG_SE_11_ADDR(base) ((base) + 0xe2c)
#define SOC_IOC_AO_IOCG_8_ADDR(base) ((base) + 0x820)
#define SOC_IOC_AO_IOCG_SE_12_ADDR(base) ((base) + 0xe30)
#define SOC_IOC_AO_IOCG_SE_13_ADDR(base) ((base) + 0xe34)
#define SOC_IOC_AO_IOCG_SE_14_ADDR(base) ((base) + 0xe38)
#define SOC_IOC_AO_IOCG_SE_15_ADDR(base) ((base) + 0xe3c)
#define SOC_IOC_AO_IOCG_SE_16_ADDR(base) ((base) + 0xe40)
#define SOC_IOC_AO_IOCG_9_ADDR(base) ((base) + 0x824)
#define SOC_IOC_AO_IOCG_SE_17_ADDR(base) ((base) + 0xe44)
#define SOC_IOC_AO_IOCG_SE_18_ADDR(base) ((base) + 0xe48)
#define SOC_IOC_AO_IOCG_SE_19_ADDR(base) ((base) + 0xe4c)
#define SOC_IOC_AO_IOCG_SE_20_ADDR(base) ((base) + 0xe50)
#define SOC_IOC_AO_IOCG_SE_21_ADDR(base) ((base) + 0xe54)
#define SOC_IOC_AO_IOCG_SE_22_ADDR(base) ((base) + 0xe58)
#define SOC_IOC_AO_IOCG_SE_23_ADDR(base) ((base) + 0xe5c)
#define SOC_IOC_AO_IOCG_SE_24_ADDR(base) ((base) + 0xe60)
#define SOC_IOC_AO_IOCG_SE_25_ADDR(base) ((base) + 0xe64)
#define SOC_IOC_AO_IOCG_10_ADDR(base) ((base) + 0x828)
#define SOC_IOC_AO_IOCG_11_ADDR(base) ((base) + 0x82c)
#define SOC_IOC_AO_IOCG_12_ADDR(base) ((base) + 0x830)
#define SOC_IOC_AO_IOCG_13_ADDR(base) ((base) + 0x834)
#define SOC_IOC_AO_IOCG_SE_26_ADDR(base) ((base) + 0xe68)
#define SOC_IOC_AO_IOCG_SE_27_ADDR(base) ((base) + 0xe6c)
#define SOC_IOC_AO_IOCG_SE_28_ADDR(base) ((base) + 0xe70)
#define SOC_IOC_AO_IOCG_SE_29_ADDR(base) ((base) + 0xe74)
#define SOC_IOC_AO_IOCG_SE_30_ADDR(base) ((base) + 0xe78)
#define SOC_IOC_AO_IOCG_SE_31_ADDR(base) ((base) + 0xe7c)
#define SOC_IOC_AO_IOCG_SE_32_ADDR(base) ((base) + 0xe80)
#define SOC_IOC_AO_IOCG_SE_33_ADDR(base) ((base) + 0xe84)
#define SOC_IOC_AO_IOCG_SE_34_ADDR(base) ((base) + 0xe88)
#define SOC_IOC_AO_IOCG_SE_35_ADDR(base) ((base) + 0xe8c)
#define SOC_IOC_AO_IOCG_SE_36_ADDR(base) ((base) + 0xe90)
#define SOC_IOC_AO_IOCG_SE_37_ADDR(base) ((base) + 0xe94)
#define SOC_IOC_AO_IOCG_SE_38_ADDR(base) ((base) + 0xe98)
#define SOC_IOC_AO_IOCG_SE_39_ADDR(base) ((base) + 0xe9c)
#define SOC_IOC_AO_IOCG_14_ADDR(base) ((base) + 0x838)
#define SOC_IOC_AO_IOCG_15_ADDR(base) ((base) + 0x83c)
#define SOC_IOC_AO_IOCG_16_ADDR(base) ((base) + 0x840)
#define SOC_IOC_AO_IOCG_17_ADDR(base) ((base) + 0x844)
#define SOC_IOC_AO_IOCG_18_ADDR(base) ((base) + 0x848)
#define SOC_IOC_AO_IOCG_19_ADDR(base) ((base) + 0x84c)
#define SOC_IOC_AO_IOCG_20_ADDR(base) ((base) + 0x850)
#define SOC_IOC_AO_IOCG_21_ADDR(base) ((base) + 0x854)
#define SOC_IOC_AO_IOCG_SE_40_ADDR(base) ((base) + 0xea0)
#define SOC_IOC_AO_IOCG_22_ADDR(base) ((base) + 0x858)
#define SOC_IOC_AO_IOCG_23_ADDR(base) ((base) + 0x85c)
#define SOC_IOC_AO_IOCG_24_ADDR(base) ((base) + 0x860)
#define SOC_IOC_AO_IOCG_25_ADDR(base) ((base) + 0x864)
#define SOC_IOC_AO_IOCG_26_ADDR(base) ((base) + 0x868)
#define SOC_IOC_AO_IOCG_SE_41_ADDR(base) ((base) + 0xea4)
#define SOC_IOC_AO_IOCG_SE_42_ADDR(base) ((base) + 0xea8)
#define SOC_IOC_AO_IOCG_SE_43_ADDR(base) ((base) + 0xeac)
#define SOC_IOC_AO_IOCG_SE_44_ADDR(base) ((base) + 0xeb0)
#define SOC_IOC_AO_IOCG_SE_45_ADDR(base) ((base) + 0xeb4)
#define SOC_IOC_AO_IOCG_SE_46_ADDR(base) ((base) + 0xeb8)
#define SOC_IOC_AO_IOCG_SE_47_ADDR(base) ((base) + 0xebc)
#define SOC_IOC_AO_IOCG_SE_48_ADDR(base) ((base) + 0xec0)
#define SOC_IOC_AO_IOCG_SE_49_ADDR(base) ((base) + 0xec4)
#define SOC_IOC_AO_IOCG_SE_50_ADDR(base) ((base) + 0xec8)
#define SOC_IOC_AO_IOCG_SE_51_ADDR(base) ((base) + 0xecc)
#define SOC_IOC_AO_IOCG_SE_52_ADDR(base) ((base) + 0xed0)
#define SOC_IOC_AO_IOCG_SE_53_ADDR(base) ((base) + 0xed4)
#define SOC_IOC_AO_IOCG_SE_54_ADDR(base) ((base) + 0xed8)
#define SOC_IOC_AO_IOCG_27_ADDR(base) ((base) + 0x86c)
#define SOC_IOC_AO_IOCG_28_ADDR(base) ((base) + 0x870)
#define SOC_IOC_AO_IOCG_SE_55_ADDR(base) ((base) + 0xedc)
#define SOC_IOC_AO_IOCG_29_ADDR(base) ((base) + 0x874)
#define SOC_IOC_AO_IOCG_30_ADDR(base) ((base) + 0x878)
#define SOC_IOC_AO_IOCG_SE_56_ADDR(base) ((base) + 0xee0)
#define SOC_IOC_AO_IOCG_SE_57_ADDR(base) ((base) + 0xee4)
#define SOC_IOC_AO_IOCG_SE_58_ADDR(base) ((base) + 0xee8)
#define SOC_IOC_AO_IOCG_SE_59_ADDR(base) ((base) + 0xeec)
#define SOC_IOC_AO_IOCG_31_ADDR(base) ((base) + 0x87c)
#define SOC_IOC_AO_IOCG_32_ADDR(base) ((base) + 0x880)
#define SOC_IOC_AO_IOCG_33_ADDR(base) ((base) + 0x884)
#define SOC_IOC_AO_IOCG_34_ADDR(base) ((base) + 0x888)
#define SOC_IOC_AO_IOCG_SE_60_ADDR(base) ((base) + 0xef0)
#define SOC_IOC_AO_IOCG_SE_61_ADDR(base) ((base) + 0xef4)
#define SOC_IOC_AO_IOCG_SE_62_ADDR(base) ((base) + 0xef8)
#define SOC_IOC_AO_IOCG_SE_63_ADDR(base) ((base) + 0xefc)
#define SOC_IOC_AO_IOCG_SE_64_ADDR(base) ((base) + 0xf00)
#define SOC_IOC_AO_IOCG_35_ADDR(base) ((base) + 0x88c)
#define SOC_IOC_AO_IOCG_36_ADDR(base) ((base) + 0x890)
#define SOC_IOC_AO_IOCG_37_ADDR(base) ((base) + 0x894)
#define SOC_IOC_AO_IOCG_38_ADDR(base) ((base) + 0x898)
#define SOC_IOC_AO_IOCG_39_ADDR(base) ((base) + 0x89c)
#define SOC_IOC_AO_IOCG_40_ADDR(base) ((base) + 0x8a0)
#define SOC_IOC_AO_IOCG_41_ADDR(base) ((base) + 0x8a4)
#define SOC_IOC_AO_IOCG_SE_65_ADDR(base) ((base) + 0xf04)
#define SOC_IOC_AO_IOCG_SE_66_ADDR(base) ((base) + 0xf08)
#define SOC_IOC_AO_IOCG_SE_67_ADDR(base) ((base) + 0xf0c)
#define SOC_IOC_AO_IOCG_SE_68_ADDR(base) ((base) + 0xf10)
#define SOC_IOC_AO_IOCG_SE_69_ADDR(base) ((base) + 0xf14)
#define SOC_IOC_AO_IOCG_42_ADDR(base) ((base) + 0x8a8)
#define SOC_IOC_AO_IOCG_SE_70_ADDR(base) ((base) + 0xf18)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_AO_IOMG_4_ADDR(base) ((base) + 0x10UL)
#define SOC_IOC_AO_IOMG_5_ADDR(base) ((base) + 0x14UL)
#define SOC_IOC_AO_IOMG_6_ADDR(base) ((base) + 0x18UL)
#define SOC_IOC_AO_IOMG_7_ADDR(base) ((base) + 0x1cUL)
#define SOC_IOC_AO_IOMG_SE_0_ADDR(base) ((base) + 0x600UL)
#define SOC_IOC_AO_IOMG_SE_1_ADDR(base) ((base) + 0x604UL)
#define SOC_IOC_AO_IOMG_SE_2_ADDR(base) ((base) + 0x608UL)
#define SOC_IOC_AO_IOMG_SE_3_ADDR(base) ((base) + 0x60cUL)
#define SOC_IOC_AO_IOMG_SE_4_ADDR(base) ((base) + 0x610UL)
#define SOC_IOC_AO_IOMG_SE_5_ADDR(base) ((base) + 0x614UL)
#define SOC_IOC_AO_IOMG_SE_6_ADDR(base) ((base) + 0x618UL)
#define SOC_IOC_AO_IOMG_SE_7_ADDR(base) ((base) + 0x61cUL)
#define SOC_IOC_AO_IOMG_SE_8_ADDR(base) ((base) + 0x620UL)
#define SOC_IOC_AO_IOMG_SE_9_ADDR(base) ((base) + 0x624UL)
#define SOC_IOC_AO_IOMG_SE_10_ADDR(base) ((base) + 0x628UL)
#define SOC_IOC_AO_IOMG_SE_11_ADDR(base) ((base) + 0x62cUL)
#define SOC_IOC_AO_IOMG_SE_12_ADDR(base) ((base) + 0x630UL)
#define SOC_IOC_AO_IOMG_SE_13_ADDR(base) ((base) + 0x634UL)
#define SOC_IOC_AO_IOMG_SE_14_ADDR(base) ((base) + 0x638UL)
#define SOC_IOC_AO_IOMG_SE_15_ADDR(base) ((base) + 0x63cUL)
#define SOC_IOC_AO_IOMG_9_ADDR(base) ((base) + 0x24UL)
#define SOC_IOC_AO_IOMG_SE_17_ADDR(base) ((base) + 0x644UL)
#define SOC_IOC_AO_IOMG_SE_18_ADDR(base) ((base) + 0x648UL)
#define SOC_IOC_AO_IOMG_SE_19_ADDR(base) ((base) + 0x64cUL)
#define SOC_IOC_AO_IOMG_SE_20_ADDR(base) ((base) + 0x650UL)
#define SOC_IOC_AO_IOMG_SE_21_ADDR(base) ((base) + 0x654UL)
#define SOC_IOC_AO_IOMG_SE_22_ADDR(base) ((base) + 0x658UL)
#define SOC_IOC_AO_IOMG_SE_23_ADDR(base) ((base) + 0x65cUL)
#define SOC_IOC_AO_IOMG_SE_24_ADDR(base) ((base) + 0x660UL)
#define SOC_IOC_AO_IOMG_SE_25_ADDR(base) ((base) + 0x664UL)
#define SOC_IOC_AO_IOMG_10_ADDR(base) ((base) + 0x28UL)
#define SOC_IOC_AO_IOMG_11_ADDR(base) ((base) + 0x2cUL)
#define SOC_IOC_AO_IOMG_12_ADDR(base) ((base) + 0x30UL)
#define SOC_IOC_AO_IOMG_13_ADDR(base) ((base) + 0x34UL)
#define SOC_IOC_AO_IOMG_SE_26_ADDR(base) ((base) + 0x668UL)
#define SOC_IOC_AO_IOMG_SE_27_ADDR(base) ((base) + 0x66cUL)
#define SOC_IOC_AO_IOMG_SE_28_ADDR(base) ((base) + 0x670UL)
#define SOC_IOC_AO_IOMG_SE_29_ADDR(base) ((base) + 0x674UL)
#define SOC_IOC_AO_IOMG_SE_30_ADDR(base) ((base) + 0x678UL)
#define SOC_IOC_AO_IOMG_SE_31_ADDR(base) ((base) + 0x67cUL)
#define SOC_IOC_AO_IOMG_SE_32_ADDR(base) ((base) + 0x680UL)
#define SOC_IOC_AO_IOMG_SE_33_ADDR(base) ((base) + 0x684UL)
#define SOC_IOC_AO_IOMG_SE_34_ADDR(base) ((base) + 0x688UL)
#define SOC_IOC_AO_IOMG_SE_35_ADDR(base) ((base) + 0x68cUL)
#define SOC_IOC_AO_IOMG_SE_36_ADDR(base) ((base) + 0x690UL)
#define SOC_IOC_AO_IOMG_SE_37_ADDR(base) ((base) + 0x694UL)
#define SOC_IOC_AO_IOMG_SE_38_ADDR(base) ((base) + 0x698UL)
#define SOC_IOC_AO_IOMG_SE_39_ADDR(base) ((base) + 0x69cUL)
#define SOC_IOC_AO_IOMG_17_ADDR(base) ((base) + 0x44UL)
#define SOC_IOC_AO_IOMG_18_ADDR(base) ((base) + 0x48UL)
#define SOC_IOC_AO_IOMG_19_ADDR(base) ((base) + 0x4cUL)
#define SOC_IOC_AO_IOMG_20_ADDR(base) ((base) + 0x50UL)
#define SOC_IOC_AO_IOMG_21_ADDR(base) ((base) + 0x54UL)
#define SOC_IOC_AO_IOMG_SE_40_ADDR(base) ((base) + 0x6a0UL)
#define SOC_IOC_AO_IOMG_22_ADDR(base) ((base) + 0x58UL)
#define SOC_IOC_AO_IOMG_23_ADDR(base) ((base) + 0x5cUL)
#define SOC_IOC_AO_IOMG_24_ADDR(base) ((base) + 0x60UL)
#define SOC_IOC_AO_IOMG_25_ADDR(base) ((base) + 0x64UL)
#define SOC_IOC_AO_IOMG_26_ADDR(base) ((base) + 0x68UL)
#define SOC_IOC_AO_IOMG_SE_41_ADDR(base) ((base) + 0x6a4UL)
#define SOC_IOC_AO_IOMG_SE_42_ADDR(base) ((base) + 0x6a8UL)
#define SOC_IOC_AO_IOMG_SE_43_ADDR(base) ((base) + 0x6acUL)
#define SOC_IOC_AO_IOMG_SE_44_ADDR(base) ((base) + 0x6b0UL)
#define SOC_IOC_AO_IOMG_SE_45_ADDR(base) ((base) + 0x6b4UL)
#define SOC_IOC_AO_IOMG_SE_46_ADDR(base) ((base) + 0x6b8UL)
#define SOC_IOC_AO_IOMG_SE_47_ADDR(base) ((base) + 0x6bcUL)
#define SOC_IOC_AO_IOMG_SE_48_ADDR(base) ((base) + 0x6c0UL)
#define SOC_IOC_AO_IOMG_SE_49_ADDR(base) ((base) + 0x6c4UL)
#define SOC_IOC_AO_IOMG_SE_50_ADDR(base) ((base) + 0x6c8UL)
#define SOC_IOC_AO_IOMG_SE_51_ADDR(base) ((base) + 0x6ccUL)
#define SOC_IOC_AO_IOMG_SE_52_ADDR(base) ((base) + 0x6d0UL)
#define SOC_IOC_AO_IOMG_SE_53_ADDR(base) ((base) + 0x6d4UL)
#define SOC_IOC_AO_IOMG_SE_54_ADDR(base) ((base) + 0x6d8UL)
#define SOC_IOC_AO_IOMG_28_ADDR(base) ((base) + 0x70UL)
#define SOC_IOC_AO_IOMG_SE_55_ADDR(base) ((base) + 0x6dcUL)
#define SOC_IOC_AO_IOMG_29_ADDR(base) ((base) + 0x74UL)
#define SOC_IOC_AO_IOMG_30_ADDR(base) ((base) + 0x78UL)
#define SOC_IOC_AO_IOMG_SE_56_ADDR(base) ((base) + 0x6e0UL)
#define SOC_IOC_AO_IOMG_SE_57_ADDR(base) ((base) + 0x6e4UL)
#define SOC_IOC_AO_IOMG_SE_58_ADDR(base) ((base) + 0x6e8UL)
#define SOC_IOC_AO_IOMG_SE_59_ADDR(base) ((base) + 0x6ecUL)
#define SOC_IOC_AO_IOMG_31_ADDR(base) ((base) + 0x7cUL)
#define SOC_IOC_AO_IOMG_32_ADDR(base) ((base) + 0x80UL)
#define SOC_IOC_AO_IOMG_33_ADDR(base) ((base) + 0x84UL)
#define SOC_IOC_AO_IOMG_34_ADDR(base) ((base) + 0x88UL)
#define SOC_IOC_AO_IOMG_SE_60_ADDR(base) ((base) + 0x6f0UL)
#define SOC_IOC_AO_IOMG_SE_61_ADDR(base) ((base) + 0x6f4UL)
#define SOC_IOC_AO_IOMG_SE_62_ADDR(base) ((base) + 0x6f8UL)
#define SOC_IOC_AO_IOMG_SE_63_ADDR(base) ((base) + 0x6fcUL)
#define SOC_IOC_AO_IOMG_SE_64_ADDR(base) ((base) + 0x700UL)
#define SOC_IOC_AO_IOMG_35_ADDR(base) ((base) + 0x8cUL)
#define SOC_IOC_AO_IOMG_36_ADDR(base) ((base) + 0x90UL)
#define SOC_IOC_AO_IOMG_37_ADDR(base) ((base) + 0x94UL)
#define SOC_IOC_AO_IOMG_38_ADDR(base) ((base) + 0x98UL)
#define SOC_IOC_AO_IOMG_39_ADDR(base) ((base) + 0x9cUL)
#define SOC_IOC_AO_IOMG_40_ADDR(base) ((base) + 0xa0UL)
#define SOC_IOC_AO_IOMG_41_ADDR(base) ((base) + 0xa4UL)
#define SOC_IOC_AO_IOMG_SE_65_ADDR(base) ((base) + 0x704UL)
#define SOC_IOC_AO_IOMG_SE_66_ADDR(base) ((base) + 0x708UL)
#define SOC_IOC_AO_IOMG_SE_67_ADDR(base) ((base) + 0x70cUL)
#define SOC_IOC_AO_IOMG_SE_68_ADDR(base) ((base) + 0x710UL)
#define SOC_IOC_AO_IOMG_SE_69_ADDR(base) ((base) + 0x714UL)
#define SOC_IOC_AO_IOMG_42_ADDR(base) ((base) + 0xa8UL)
#else
#define SOC_IOC_AO_IOMG_4_ADDR(base) ((base) + 0x10)
#define SOC_IOC_AO_IOMG_5_ADDR(base) ((base) + 0x14)
#define SOC_IOC_AO_IOMG_6_ADDR(base) ((base) + 0x18)
#define SOC_IOC_AO_IOMG_7_ADDR(base) ((base) + 0x1c)
#define SOC_IOC_AO_IOMG_SE_0_ADDR(base) ((base) + 0x600)
#define SOC_IOC_AO_IOMG_SE_1_ADDR(base) ((base) + 0x604)
#define SOC_IOC_AO_IOMG_SE_2_ADDR(base) ((base) + 0x608)
#define SOC_IOC_AO_IOMG_SE_3_ADDR(base) ((base) + 0x60c)
#define SOC_IOC_AO_IOMG_SE_4_ADDR(base) ((base) + 0x610)
#define SOC_IOC_AO_IOMG_SE_5_ADDR(base) ((base) + 0x614)
#define SOC_IOC_AO_IOMG_SE_6_ADDR(base) ((base) + 0x618)
#define SOC_IOC_AO_IOMG_SE_7_ADDR(base) ((base) + 0x61c)
#define SOC_IOC_AO_IOMG_SE_8_ADDR(base) ((base) + 0x620)
#define SOC_IOC_AO_IOMG_SE_9_ADDR(base) ((base) + 0x624)
#define SOC_IOC_AO_IOMG_SE_10_ADDR(base) ((base) + 0x628)
#define SOC_IOC_AO_IOMG_SE_11_ADDR(base) ((base) + 0x62c)
#define SOC_IOC_AO_IOMG_SE_12_ADDR(base) ((base) + 0x630)
#define SOC_IOC_AO_IOMG_SE_13_ADDR(base) ((base) + 0x634)
#define SOC_IOC_AO_IOMG_SE_14_ADDR(base) ((base) + 0x638)
#define SOC_IOC_AO_IOMG_SE_15_ADDR(base) ((base) + 0x63c)
#define SOC_IOC_AO_IOMG_9_ADDR(base) ((base) + 0x24)
#define SOC_IOC_AO_IOMG_SE_17_ADDR(base) ((base) + 0x644)
#define SOC_IOC_AO_IOMG_SE_18_ADDR(base) ((base) + 0x648)
#define SOC_IOC_AO_IOMG_SE_19_ADDR(base) ((base) + 0x64c)
#define SOC_IOC_AO_IOMG_SE_20_ADDR(base) ((base) + 0x650)
#define SOC_IOC_AO_IOMG_SE_21_ADDR(base) ((base) + 0x654)
#define SOC_IOC_AO_IOMG_SE_22_ADDR(base) ((base) + 0x658)
#define SOC_IOC_AO_IOMG_SE_23_ADDR(base) ((base) + 0x65c)
#define SOC_IOC_AO_IOMG_SE_24_ADDR(base) ((base) + 0x660)
#define SOC_IOC_AO_IOMG_SE_25_ADDR(base) ((base) + 0x664)
#define SOC_IOC_AO_IOMG_10_ADDR(base) ((base) + 0x28)
#define SOC_IOC_AO_IOMG_11_ADDR(base) ((base) + 0x2c)
#define SOC_IOC_AO_IOMG_12_ADDR(base) ((base) + 0x30)
#define SOC_IOC_AO_IOMG_13_ADDR(base) ((base) + 0x34)
#define SOC_IOC_AO_IOMG_SE_26_ADDR(base) ((base) + 0x668)
#define SOC_IOC_AO_IOMG_SE_27_ADDR(base) ((base) + 0x66c)
#define SOC_IOC_AO_IOMG_SE_28_ADDR(base) ((base) + 0x670)
#define SOC_IOC_AO_IOMG_SE_29_ADDR(base) ((base) + 0x674)
#define SOC_IOC_AO_IOMG_SE_30_ADDR(base) ((base) + 0x678)
#define SOC_IOC_AO_IOMG_SE_31_ADDR(base) ((base) + 0x67c)
#define SOC_IOC_AO_IOMG_SE_32_ADDR(base) ((base) + 0x680)
#define SOC_IOC_AO_IOMG_SE_33_ADDR(base) ((base) + 0x684)
#define SOC_IOC_AO_IOMG_SE_34_ADDR(base) ((base) + 0x688)
#define SOC_IOC_AO_IOMG_SE_35_ADDR(base) ((base) + 0x68c)
#define SOC_IOC_AO_IOMG_SE_36_ADDR(base) ((base) + 0x690)
#define SOC_IOC_AO_IOMG_SE_37_ADDR(base) ((base) + 0x694)
#define SOC_IOC_AO_IOMG_SE_38_ADDR(base) ((base) + 0x698)
#define SOC_IOC_AO_IOMG_SE_39_ADDR(base) ((base) + 0x69c)
#define SOC_IOC_AO_IOMG_17_ADDR(base) ((base) + 0x44)
#define SOC_IOC_AO_IOMG_18_ADDR(base) ((base) + 0x48)
#define SOC_IOC_AO_IOMG_19_ADDR(base) ((base) + 0x4c)
#define SOC_IOC_AO_IOMG_20_ADDR(base) ((base) + 0x50)
#define SOC_IOC_AO_IOMG_21_ADDR(base) ((base) + 0x54)
#define SOC_IOC_AO_IOMG_SE_40_ADDR(base) ((base) + 0x6a0)
#define SOC_IOC_AO_IOMG_22_ADDR(base) ((base) + 0x58)
#define SOC_IOC_AO_IOMG_23_ADDR(base) ((base) + 0x5c)
#define SOC_IOC_AO_IOMG_24_ADDR(base) ((base) + 0x60)
#define SOC_IOC_AO_IOMG_25_ADDR(base) ((base) + 0x64)
#define SOC_IOC_AO_IOMG_26_ADDR(base) ((base) + 0x68)
#define SOC_IOC_AO_IOMG_SE_41_ADDR(base) ((base) + 0x6a4)
#define SOC_IOC_AO_IOMG_SE_42_ADDR(base) ((base) + 0x6a8)
#define SOC_IOC_AO_IOMG_SE_43_ADDR(base) ((base) + 0x6ac)
#define SOC_IOC_AO_IOMG_SE_44_ADDR(base) ((base) + 0x6b0)
#define SOC_IOC_AO_IOMG_SE_45_ADDR(base) ((base) + 0x6b4)
#define SOC_IOC_AO_IOMG_SE_46_ADDR(base) ((base) + 0x6b8)
#define SOC_IOC_AO_IOMG_SE_47_ADDR(base) ((base) + 0x6bc)
#define SOC_IOC_AO_IOMG_SE_48_ADDR(base) ((base) + 0x6c0)
#define SOC_IOC_AO_IOMG_SE_49_ADDR(base) ((base) + 0x6c4)
#define SOC_IOC_AO_IOMG_SE_50_ADDR(base) ((base) + 0x6c8)
#define SOC_IOC_AO_IOMG_SE_51_ADDR(base) ((base) + 0x6cc)
#define SOC_IOC_AO_IOMG_SE_52_ADDR(base) ((base) + 0x6d0)
#define SOC_IOC_AO_IOMG_SE_53_ADDR(base) ((base) + 0x6d4)
#define SOC_IOC_AO_IOMG_SE_54_ADDR(base) ((base) + 0x6d8)
#define SOC_IOC_AO_IOMG_28_ADDR(base) ((base) + 0x70)
#define SOC_IOC_AO_IOMG_SE_55_ADDR(base) ((base) + 0x6dc)
#define SOC_IOC_AO_IOMG_29_ADDR(base) ((base) + 0x74)
#define SOC_IOC_AO_IOMG_30_ADDR(base) ((base) + 0x78)
#define SOC_IOC_AO_IOMG_SE_56_ADDR(base) ((base) + 0x6e0)
#define SOC_IOC_AO_IOMG_SE_57_ADDR(base) ((base) + 0x6e4)
#define SOC_IOC_AO_IOMG_SE_58_ADDR(base) ((base) + 0x6e8)
#define SOC_IOC_AO_IOMG_SE_59_ADDR(base) ((base) + 0x6ec)
#define SOC_IOC_AO_IOMG_31_ADDR(base) ((base) + 0x7c)
#define SOC_IOC_AO_IOMG_32_ADDR(base) ((base) + 0x80)
#define SOC_IOC_AO_IOMG_33_ADDR(base) ((base) + 0x84)
#define SOC_IOC_AO_IOMG_34_ADDR(base) ((base) + 0x88)
#define SOC_IOC_AO_IOMG_SE_60_ADDR(base) ((base) + 0x6f0)
#define SOC_IOC_AO_IOMG_SE_61_ADDR(base) ((base) + 0x6f4)
#define SOC_IOC_AO_IOMG_SE_62_ADDR(base) ((base) + 0x6f8)
#define SOC_IOC_AO_IOMG_SE_63_ADDR(base) ((base) + 0x6fc)
#define SOC_IOC_AO_IOMG_SE_64_ADDR(base) ((base) + 0x700)
#define SOC_IOC_AO_IOMG_35_ADDR(base) ((base) + 0x8c)
#define SOC_IOC_AO_IOMG_36_ADDR(base) ((base) + 0x90)
#define SOC_IOC_AO_IOMG_37_ADDR(base) ((base) + 0x94)
#define SOC_IOC_AO_IOMG_38_ADDR(base) ((base) + 0x98)
#define SOC_IOC_AO_IOMG_39_ADDR(base) ((base) + 0x9c)
#define SOC_IOC_AO_IOMG_40_ADDR(base) ((base) + 0xa0)
#define SOC_IOC_AO_IOMG_41_ADDR(base) ((base) + 0xa4)
#define SOC_IOC_AO_IOMG_SE_65_ADDR(base) ((base) + 0x704)
#define SOC_IOC_AO_IOMG_SE_66_ADDR(base) ((base) + 0x708)
#define SOC_IOC_AO_IOMG_SE_67_ADDR(base) ((base) + 0x70c)
#define SOC_IOC_AO_IOMG_SE_68_ADDR(base) ((base) + 0x710)
#define SOC_IOC_AO_IOMG_SE_69_ADDR(base) ((base) + 0x714)
#define SOC_IOC_AO_IOMG_42_ADDR(base) ((base) + 0xa8)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_0_pu : 1;
        unsigned int iocg_0_pd : 1;
        unsigned int reserved_0: 1;
        unsigned int iocg_0_st : 1;
        unsigned int reserved_1: 28;
    } reg;
} SOC_IOC_AO_IOCG_0_UNION;
#endif
#define SOC_IOC_AO_IOCG_0_iocg_0_pu_START (0)
#define SOC_IOC_AO_IOCG_0_iocg_0_pu_END (0)
#define SOC_IOC_AO_IOCG_0_iocg_0_pd_START (1)
#define SOC_IOC_AO_IOCG_0_iocg_0_pd_END (1)
#define SOC_IOC_AO_IOCG_0_iocg_0_st_START (3)
#define SOC_IOC_AO_IOCG_0_iocg_0_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 3;
        unsigned int iocg_1_st : 1;
        unsigned int reserved_1: 5;
        unsigned int iocg_1_pe : 1;
        unsigned int iocg_1_ps : 1;
        unsigned int reserved_2: 21;
    } reg;
} SOC_IOC_AO_IOCG_1_UNION;
#endif
#define SOC_IOC_AO_IOCG_1_iocg_1_st_START (3)
#define SOC_IOC_AO_IOCG_1_iocg_1_st_END (3)
#define SOC_IOC_AO_IOCG_1_iocg_1_pe_START (9)
#define SOC_IOC_AO_IOCG_1_iocg_1_pe_END (9)
#define SOC_IOC_AO_IOCG_1_iocg_1_ps_START (10)
#define SOC_IOC_AO_IOCG_1_iocg_1_ps_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_2_pu : 1;
        unsigned int iocg_2_pd : 1;
        unsigned int reserved_0: 1;
        unsigned int iocg_2_st : 1;
        unsigned int reserved_1: 28;
    } reg;
} SOC_IOC_AO_IOCG_2_UNION;
#endif
#define SOC_IOC_AO_IOCG_2_iocg_2_pu_START (0)
#define SOC_IOC_AO_IOCG_2_iocg_2_pu_END (0)
#define SOC_IOC_AO_IOCG_2_iocg_2_pd_START (1)
#define SOC_IOC_AO_IOCG_2_iocg_2_pd_END (1)
#define SOC_IOC_AO_IOCG_2_iocg_2_st_START (3)
#define SOC_IOC_AO_IOCG_2_iocg_2_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int iocg_3_ds0 : 1;
        unsigned int iocg_3_ds1 : 1;
        unsigned int iocg_3_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_3_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_3_UNION;
#endif
#define SOC_IOC_AO_IOCG_3_iocg_3_ds0_START (4)
#define SOC_IOC_AO_IOCG_3_iocg_3_ds0_END (4)
#define SOC_IOC_AO_IOCG_3_iocg_3_ds1_START (5)
#define SOC_IOC_AO_IOCG_3_iocg_3_ds1_END (5)
#define SOC_IOC_AO_IOCG_3_iocg_3_ds2_START (6)
#define SOC_IOC_AO_IOCG_3_iocg_3_ds2_END (6)
#define SOC_IOC_AO_IOCG_3_iocg_3_sl_START (8)
#define SOC_IOC_AO_IOCG_3_iocg_3_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_4_pu : 1;
        unsigned int iocg_4_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_4_st : 1;
        unsigned int iocg_4_ds0 : 1;
        unsigned int iocg_4_ds1 : 1;
        unsigned int iocg_4_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_4_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_4_UNION;
#endif
#define SOC_IOC_AO_IOCG_4_iocg_4_pu_START (0)
#define SOC_IOC_AO_IOCG_4_iocg_4_pu_END (0)
#define SOC_IOC_AO_IOCG_4_iocg_4_pd_START (1)
#define SOC_IOC_AO_IOCG_4_iocg_4_pd_END (1)
#define SOC_IOC_AO_IOCG_4_iocg_4_st_START (3)
#define SOC_IOC_AO_IOCG_4_iocg_4_st_END (3)
#define SOC_IOC_AO_IOCG_4_iocg_4_ds0_START (4)
#define SOC_IOC_AO_IOCG_4_iocg_4_ds0_END (4)
#define SOC_IOC_AO_IOCG_4_iocg_4_ds1_START (5)
#define SOC_IOC_AO_IOCG_4_iocg_4_ds1_END (5)
#define SOC_IOC_AO_IOCG_4_iocg_4_ds2_START (6)
#define SOC_IOC_AO_IOCG_4_iocg_4_ds2_END (6)
#define SOC_IOC_AO_IOCG_4_iocg_4_sl_START (8)
#define SOC_IOC_AO_IOCG_4_iocg_4_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_5_pu : 1;
        unsigned int iocg_5_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_5_st : 1;
        unsigned int iocg_5_ds0 : 1;
        unsigned int iocg_5_ds1 : 1;
        unsigned int iocg_5_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_5_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_5_UNION;
#endif
#define SOC_IOC_AO_IOCG_5_iocg_5_pu_START (0)
#define SOC_IOC_AO_IOCG_5_iocg_5_pu_END (0)
#define SOC_IOC_AO_IOCG_5_iocg_5_pd_START (1)
#define SOC_IOC_AO_IOCG_5_iocg_5_pd_END (1)
#define SOC_IOC_AO_IOCG_5_iocg_5_st_START (3)
#define SOC_IOC_AO_IOCG_5_iocg_5_st_END (3)
#define SOC_IOC_AO_IOCG_5_iocg_5_ds0_START (4)
#define SOC_IOC_AO_IOCG_5_iocg_5_ds0_END (4)
#define SOC_IOC_AO_IOCG_5_iocg_5_ds1_START (5)
#define SOC_IOC_AO_IOCG_5_iocg_5_ds1_END (5)
#define SOC_IOC_AO_IOCG_5_iocg_5_ds2_START (6)
#define SOC_IOC_AO_IOCG_5_iocg_5_ds2_END (6)
#define SOC_IOC_AO_IOCG_5_iocg_5_sl_START (8)
#define SOC_IOC_AO_IOCG_5_iocg_5_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_6_pu : 1;
        unsigned int iocg_6_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_6_st : 1;
        unsigned int iocg_6_ds0 : 1;
        unsigned int iocg_6_ds1 : 1;
        unsigned int iocg_6_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_6_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_6_UNION;
#endif
#define SOC_IOC_AO_IOCG_6_iocg_6_pu_START (0)
#define SOC_IOC_AO_IOCG_6_iocg_6_pu_END (0)
#define SOC_IOC_AO_IOCG_6_iocg_6_pd_START (1)
#define SOC_IOC_AO_IOCG_6_iocg_6_pd_END (1)
#define SOC_IOC_AO_IOCG_6_iocg_6_st_START (3)
#define SOC_IOC_AO_IOCG_6_iocg_6_st_END (3)
#define SOC_IOC_AO_IOCG_6_iocg_6_ds0_START (4)
#define SOC_IOC_AO_IOCG_6_iocg_6_ds0_END (4)
#define SOC_IOC_AO_IOCG_6_iocg_6_ds1_START (5)
#define SOC_IOC_AO_IOCG_6_iocg_6_ds1_END (5)
#define SOC_IOC_AO_IOCG_6_iocg_6_ds2_START (6)
#define SOC_IOC_AO_IOCG_6_iocg_6_ds2_END (6)
#define SOC_IOC_AO_IOCG_6_iocg_6_sl_START (8)
#define SOC_IOC_AO_IOCG_6_iocg_6_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_7_pu : 1;
        unsigned int iocg_7_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_7_st : 1;
        unsigned int iocg_7_ds0 : 1;
        unsigned int iocg_7_ds1 : 1;
        unsigned int iocg_7_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_7_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_7_UNION;
#endif
#define SOC_IOC_AO_IOCG_7_iocg_7_pu_START (0)
#define SOC_IOC_AO_IOCG_7_iocg_7_pu_END (0)
#define SOC_IOC_AO_IOCG_7_iocg_7_pd_START (1)
#define SOC_IOC_AO_IOCG_7_iocg_7_pd_END (1)
#define SOC_IOC_AO_IOCG_7_iocg_7_st_START (3)
#define SOC_IOC_AO_IOCG_7_iocg_7_st_END (3)
#define SOC_IOC_AO_IOCG_7_iocg_7_ds0_START (4)
#define SOC_IOC_AO_IOCG_7_iocg_7_ds0_END (4)
#define SOC_IOC_AO_IOCG_7_iocg_7_ds1_START (5)
#define SOC_IOC_AO_IOCG_7_iocg_7_ds1_END (5)
#define SOC_IOC_AO_IOCG_7_iocg_7_ds2_START (6)
#define SOC_IOC_AO_IOCG_7_iocg_7_ds2_END (6)
#define SOC_IOC_AO_IOCG_7_iocg_7_sl_START (8)
#define SOC_IOC_AO_IOCG_7_iocg_7_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_0_pu : 1;
        unsigned int iocg_se_0_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_0_st : 1;
        unsigned int iocg_se_0_ds0 : 1;
        unsigned int iocg_se_0_ds1 : 1;
        unsigned int iocg_se_0_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_0_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_0_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_st_START (3)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_st_END (3)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_0_iocg_se_0_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_1_pu : 1;
        unsigned int iocg_se_1_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_1_st : 1;
        unsigned int iocg_se_1_ds0 : 1;
        unsigned int iocg_se_1_ds1 : 1;
        unsigned int iocg_se_1_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_1_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_1_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_st_START (3)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_st_END (3)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_1_iocg_se_1_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_2_pu : 1;
        unsigned int iocg_se_2_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_2_st : 1;
        unsigned int iocg_se_2_ds0 : 1;
        unsigned int iocg_se_2_ds1 : 1;
        unsigned int iocg_se_2_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_2_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_2_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_st_START (3)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_st_END (3)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_2_iocg_se_2_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_3_pu : 1;
        unsigned int iocg_se_3_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_3_st : 1;
        unsigned int iocg_se_3_ds0 : 1;
        unsigned int iocg_se_3_ds1 : 1;
        unsigned int iocg_se_3_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_3_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_3_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_st_START (3)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_st_END (3)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_3_iocg_se_3_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_4_pu : 1;
        unsigned int iocg_se_4_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_4_st : 1;
        unsigned int iocg_se_4_ds0 : 1;
        unsigned int iocg_se_4_ds1 : 1;
        unsigned int iocg_se_4_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_4_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_4_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_st_START (3)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_st_END (3)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_4_iocg_se_4_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_5_pu : 1;
        unsigned int iocg_se_5_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_5_st : 1;
        unsigned int iocg_se_5_ds0 : 1;
        unsigned int iocg_se_5_ds1 : 1;
        unsigned int iocg_se_5_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_5_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_5_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_st_START (3)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_st_END (3)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_5_iocg_se_5_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_6_pu : 1;
        unsigned int iocg_se_6_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_6_st : 1;
        unsigned int iocg_se_6_ds0 : 1;
        unsigned int iocg_se_6_ds1 : 1;
        unsigned int iocg_se_6_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_6_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_6_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_st_START (3)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_st_END (3)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_6_iocg_se_6_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_7_pu : 1;
        unsigned int iocg_se_7_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_7_st : 1;
        unsigned int iocg_se_7_ds0 : 1;
        unsigned int iocg_se_7_ds1 : 1;
        unsigned int iocg_se_7_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_7_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_7_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_st_START (3)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_st_END (3)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_7_iocg_se_7_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_8_pu : 1;
        unsigned int iocg_se_8_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_8_st : 1;
        unsigned int iocg_se_8_ds0 : 1;
        unsigned int iocg_se_8_ds1 : 1;
        unsigned int iocg_se_8_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_8_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_8_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_st_START (3)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_st_END (3)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_8_iocg_se_8_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_9_pu : 1;
        unsigned int iocg_se_9_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_9_st : 1;
        unsigned int iocg_se_9_ds0 : 1;
        unsigned int iocg_se_9_ds1 : 1;
        unsigned int iocg_se_9_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_9_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_9_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_st_START (3)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_st_END (3)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_9_iocg_se_9_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_10_pu : 1;
        unsigned int iocg_se_10_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_10_st : 1;
        unsigned int iocg_se_10_ds0 : 1;
        unsigned int iocg_se_10_ds1 : 1;
        unsigned int iocg_se_10_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_10_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_10_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_st_START (3)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_st_END (3)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_11_pu : 1;
        unsigned int iocg_se_11_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_11_st : 1;
        unsigned int iocg_se_11_ds0 : 1;
        unsigned int iocg_se_11_ds1 : 1;
        unsigned int iocg_se_11_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_11_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_11_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_st_START (3)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_st_END (3)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_8_pu : 1;
        unsigned int iocg_8_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_8_st : 1;
        unsigned int iocg_8_ds0 : 1;
        unsigned int iocg_8_ds1 : 1;
        unsigned int iocg_8_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_8_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_8_UNION;
#endif
#define SOC_IOC_AO_IOCG_8_iocg_8_pu_START (0)
#define SOC_IOC_AO_IOCG_8_iocg_8_pu_END (0)
#define SOC_IOC_AO_IOCG_8_iocg_8_pd_START (1)
#define SOC_IOC_AO_IOCG_8_iocg_8_pd_END (1)
#define SOC_IOC_AO_IOCG_8_iocg_8_st_START (3)
#define SOC_IOC_AO_IOCG_8_iocg_8_st_END (3)
#define SOC_IOC_AO_IOCG_8_iocg_8_ds0_START (4)
#define SOC_IOC_AO_IOCG_8_iocg_8_ds0_END (4)
#define SOC_IOC_AO_IOCG_8_iocg_8_ds1_START (5)
#define SOC_IOC_AO_IOCG_8_iocg_8_ds1_END (5)
#define SOC_IOC_AO_IOCG_8_iocg_8_ds2_START (6)
#define SOC_IOC_AO_IOCG_8_iocg_8_ds2_END (6)
#define SOC_IOC_AO_IOCG_8_iocg_8_sl_START (8)
#define SOC_IOC_AO_IOCG_8_iocg_8_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_12_pu : 1;
        unsigned int iocg_se_12_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_12_st : 1;
        unsigned int iocg_se_12_ds0 : 1;
        unsigned int iocg_se_12_ds1 : 1;
        unsigned int iocg_se_12_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_12_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_12_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_st_START (3)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_st_END (3)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_13_pu : 1;
        unsigned int iocg_se_13_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_13_st : 1;
        unsigned int iocg_se_13_ds0 : 1;
        unsigned int iocg_se_13_ds1 : 1;
        unsigned int iocg_se_13_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_13_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_13_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_st_START (3)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_st_END (3)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_14_pu : 1;
        unsigned int iocg_se_14_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_14_st : 1;
        unsigned int iocg_se_14_ds0 : 1;
        unsigned int iocg_se_14_ds1 : 1;
        unsigned int iocg_se_14_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_14_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_14_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_st_START (3)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_st_END (3)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_15_pu : 1;
        unsigned int iocg_se_15_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_15_st : 1;
        unsigned int iocg_se_15_ds0 : 1;
        unsigned int iocg_se_15_ds1 : 1;
        unsigned int iocg_se_15_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_15_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_15_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_st_START (3)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_st_END (3)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int iocg_se_16_ds0 : 1;
        unsigned int iocg_se_16_ds1 : 1;
        unsigned int iocg_se_16_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_16_sl : 1;
        unsigned int iocg_se_16_pe : 1;
        unsigned int iocg_se_16_ps : 1;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_IOC_AO_IOCG_SE_16_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_sl_END (8)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_pe_START (9)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_pe_END (9)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ps_START (10)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ps_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_9_pu : 1;
        unsigned int iocg_9_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_9_st : 1;
        unsigned int iocg_9_ds0 : 1;
        unsigned int iocg_9_ds1 : 1;
        unsigned int iocg_9_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_9_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_9_UNION;
#endif
#define SOC_IOC_AO_IOCG_9_iocg_9_pu_START (0)
#define SOC_IOC_AO_IOCG_9_iocg_9_pu_END (0)
#define SOC_IOC_AO_IOCG_9_iocg_9_pd_START (1)
#define SOC_IOC_AO_IOCG_9_iocg_9_pd_END (1)
#define SOC_IOC_AO_IOCG_9_iocg_9_st_START (3)
#define SOC_IOC_AO_IOCG_9_iocg_9_st_END (3)
#define SOC_IOC_AO_IOCG_9_iocg_9_ds0_START (4)
#define SOC_IOC_AO_IOCG_9_iocg_9_ds0_END (4)
#define SOC_IOC_AO_IOCG_9_iocg_9_ds1_START (5)
#define SOC_IOC_AO_IOCG_9_iocg_9_ds1_END (5)
#define SOC_IOC_AO_IOCG_9_iocg_9_ds2_START (6)
#define SOC_IOC_AO_IOCG_9_iocg_9_ds2_END (6)
#define SOC_IOC_AO_IOCG_9_iocg_9_sl_START (8)
#define SOC_IOC_AO_IOCG_9_iocg_9_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_17_pu : 1;
        unsigned int iocg_se_17_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_17_st : 1;
        unsigned int iocg_se_17_ds0 : 1;
        unsigned int iocg_se_17_ds1 : 1;
        unsigned int iocg_se_17_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_17_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_17_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_st_START (3)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_st_END (3)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_18_pu : 1;
        unsigned int iocg_se_18_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_18_st : 1;
        unsigned int iocg_se_18_ds0 : 1;
        unsigned int iocg_se_18_ds1 : 1;
        unsigned int iocg_se_18_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_18_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_18_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_st_START (3)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_st_END (3)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_19_pu : 1;
        unsigned int iocg_se_19_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_19_st : 1;
        unsigned int iocg_se_19_ds0 : 1;
        unsigned int iocg_se_19_ds1 : 1;
        unsigned int iocg_se_19_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_19_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_19_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_st_START (3)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_st_END (3)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_20_pu : 1;
        unsigned int iocg_se_20_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_20_st : 1;
        unsigned int iocg_se_20_ds0 : 1;
        unsigned int iocg_se_20_ds1 : 1;
        unsigned int iocg_se_20_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_20_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_20_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_st_START (3)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_st_END (3)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_21_pu : 1;
        unsigned int iocg_se_21_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_21_st : 1;
        unsigned int iocg_se_21_ds0 : 1;
        unsigned int iocg_se_21_ds1 : 1;
        unsigned int iocg_se_21_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_21_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_21_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_st_START (3)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_st_END (3)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_22_pu : 1;
        unsigned int iocg_se_22_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_22_st : 1;
        unsigned int iocg_se_22_ds0 : 1;
        unsigned int iocg_se_22_ds1 : 1;
        unsigned int iocg_se_22_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_22_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_22_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_st_START (3)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_st_END (3)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_23_pu : 1;
        unsigned int iocg_se_23_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_23_st : 1;
        unsigned int iocg_se_23_ds0 : 1;
        unsigned int iocg_se_23_ds1 : 1;
        unsigned int iocg_se_23_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_23_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_23_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_st_START (3)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_st_END (3)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_24_pu : 1;
        unsigned int iocg_se_24_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_24_st : 1;
        unsigned int iocg_se_24_ds0 : 1;
        unsigned int iocg_se_24_ds1 : 1;
        unsigned int iocg_se_24_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_24_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_24_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_st_START (3)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_st_END (3)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_25_pu : 1;
        unsigned int iocg_se_25_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_25_st : 1;
        unsigned int iocg_se_25_ds0 : 1;
        unsigned int iocg_se_25_ds1 : 1;
        unsigned int iocg_se_25_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_25_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_25_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_st_START (3)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_st_END (3)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_10_pu : 1;
        unsigned int iocg_10_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_10_st : 1;
        unsigned int iocg_10_ds0 : 1;
        unsigned int iocg_10_ds1 : 1;
        unsigned int iocg_10_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_10_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_10_UNION;
#endif
#define SOC_IOC_AO_IOCG_10_iocg_10_pu_START (0)
#define SOC_IOC_AO_IOCG_10_iocg_10_pu_END (0)
#define SOC_IOC_AO_IOCG_10_iocg_10_pd_START (1)
#define SOC_IOC_AO_IOCG_10_iocg_10_pd_END (1)
#define SOC_IOC_AO_IOCG_10_iocg_10_st_START (3)
#define SOC_IOC_AO_IOCG_10_iocg_10_st_END (3)
#define SOC_IOC_AO_IOCG_10_iocg_10_ds0_START (4)
#define SOC_IOC_AO_IOCG_10_iocg_10_ds0_END (4)
#define SOC_IOC_AO_IOCG_10_iocg_10_ds1_START (5)
#define SOC_IOC_AO_IOCG_10_iocg_10_ds1_END (5)
#define SOC_IOC_AO_IOCG_10_iocg_10_ds2_START (6)
#define SOC_IOC_AO_IOCG_10_iocg_10_ds2_END (6)
#define SOC_IOC_AO_IOCG_10_iocg_10_sl_START (8)
#define SOC_IOC_AO_IOCG_10_iocg_10_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_11_pu : 1;
        unsigned int iocg_11_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_11_st : 1;
        unsigned int iocg_11_ds0 : 1;
        unsigned int iocg_11_ds1 : 1;
        unsigned int iocg_11_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_11_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_11_UNION;
#endif
#define SOC_IOC_AO_IOCG_11_iocg_11_pu_START (0)
#define SOC_IOC_AO_IOCG_11_iocg_11_pu_END (0)
#define SOC_IOC_AO_IOCG_11_iocg_11_pd_START (1)
#define SOC_IOC_AO_IOCG_11_iocg_11_pd_END (1)
#define SOC_IOC_AO_IOCG_11_iocg_11_st_START (3)
#define SOC_IOC_AO_IOCG_11_iocg_11_st_END (3)
#define SOC_IOC_AO_IOCG_11_iocg_11_ds0_START (4)
#define SOC_IOC_AO_IOCG_11_iocg_11_ds0_END (4)
#define SOC_IOC_AO_IOCG_11_iocg_11_ds1_START (5)
#define SOC_IOC_AO_IOCG_11_iocg_11_ds1_END (5)
#define SOC_IOC_AO_IOCG_11_iocg_11_ds2_START (6)
#define SOC_IOC_AO_IOCG_11_iocg_11_ds2_END (6)
#define SOC_IOC_AO_IOCG_11_iocg_11_sl_START (8)
#define SOC_IOC_AO_IOCG_11_iocg_11_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_12_pu : 1;
        unsigned int iocg_12_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_12_st : 1;
        unsigned int iocg_12_ds0 : 1;
        unsigned int iocg_12_ds1 : 1;
        unsigned int iocg_12_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_12_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_12_UNION;
#endif
#define SOC_IOC_AO_IOCG_12_iocg_12_pu_START (0)
#define SOC_IOC_AO_IOCG_12_iocg_12_pu_END (0)
#define SOC_IOC_AO_IOCG_12_iocg_12_pd_START (1)
#define SOC_IOC_AO_IOCG_12_iocg_12_pd_END (1)
#define SOC_IOC_AO_IOCG_12_iocg_12_st_START (3)
#define SOC_IOC_AO_IOCG_12_iocg_12_st_END (3)
#define SOC_IOC_AO_IOCG_12_iocg_12_ds0_START (4)
#define SOC_IOC_AO_IOCG_12_iocg_12_ds0_END (4)
#define SOC_IOC_AO_IOCG_12_iocg_12_ds1_START (5)
#define SOC_IOC_AO_IOCG_12_iocg_12_ds1_END (5)
#define SOC_IOC_AO_IOCG_12_iocg_12_ds2_START (6)
#define SOC_IOC_AO_IOCG_12_iocg_12_ds2_END (6)
#define SOC_IOC_AO_IOCG_12_iocg_12_sl_START (8)
#define SOC_IOC_AO_IOCG_12_iocg_12_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_13_pu : 1;
        unsigned int iocg_13_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_13_st : 1;
        unsigned int iocg_13_ds0 : 1;
        unsigned int iocg_13_ds1 : 1;
        unsigned int iocg_13_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_13_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_13_UNION;
#endif
#define SOC_IOC_AO_IOCG_13_iocg_13_pu_START (0)
#define SOC_IOC_AO_IOCG_13_iocg_13_pu_END (0)
#define SOC_IOC_AO_IOCG_13_iocg_13_pd_START (1)
#define SOC_IOC_AO_IOCG_13_iocg_13_pd_END (1)
#define SOC_IOC_AO_IOCG_13_iocg_13_st_START (3)
#define SOC_IOC_AO_IOCG_13_iocg_13_st_END (3)
#define SOC_IOC_AO_IOCG_13_iocg_13_ds0_START (4)
#define SOC_IOC_AO_IOCG_13_iocg_13_ds0_END (4)
#define SOC_IOC_AO_IOCG_13_iocg_13_ds1_START (5)
#define SOC_IOC_AO_IOCG_13_iocg_13_ds1_END (5)
#define SOC_IOC_AO_IOCG_13_iocg_13_ds2_START (6)
#define SOC_IOC_AO_IOCG_13_iocg_13_ds2_END (6)
#define SOC_IOC_AO_IOCG_13_iocg_13_sl_START (8)
#define SOC_IOC_AO_IOCG_13_iocg_13_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_26_pu : 1;
        unsigned int iocg_se_26_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_26_st : 1;
        unsigned int iocg_se_26_ds0 : 1;
        unsigned int iocg_se_26_ds1 : 1;
        unsigned int iocg_se_26_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_26_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_26_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_st_START (3)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_st_END (3)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_27_pu : 1;
        unsigned int iocg_se_27_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_27_st : 1;
        unsigned int iocg_se_27_ds0 : 1;
        unsigned int iocg_se_27_ds1 : 1;
        unsigned int iocg_se_27_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_27_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_27_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_st_START (3)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_st_END (3)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_28_pu : 1;
        unsigned int iocg_se_28_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_28_st : 1;
        unsigned int iocg_se_28_ds0 : 1;
        unsigned int iocg_se_28_ds1 : 1;
        unsigned int iocg_se_28_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_28_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_28_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_st_START (3)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_st_END (3)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_29_pu : 1;
        unsigned int iocg_se_29_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_29_st : 1;
        unsigned int iocg_se_29_ds0 : 1;
        unsigned int iocg_se_29_ds1 : 1;
        unsigned int iocg_se_29_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_29_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_29_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_st_START (3)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_st_END (3)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_30_pu : 1;
        unsigned int iocg_se_30_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_30_st : 1;
        unsigned int iocg_se_30_ds0 : 1;
        unsigned int iocg_se_30_ds1 : 1;
        unsigned int iocg_se_30_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_30_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_30_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_st_START (3)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_st_END (3)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_31_pu : 1;
        unsigned int iocg_se_31_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_31_st : 1;
        unsigned int iocg_se_31_ds0 : 1;
        unsigned int iocg_se_31_ds1 : 1;
        unsigned int iocg_se_31_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_31_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_31_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_st_START (3)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_st_END (3)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_32_pu : 1;
        unsigned int iocg_se_32_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_32_st : 1;
        unsigned int iocg_se_32_ds0 : 1;
        unsigned int iocg_se_32_ds1 : 1;
        unsigned int iocg_se_32_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_32_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_32_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_st_START (3)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_st_END (3)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_33_pu : 1;
        unsigned int iocg_se_33_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_33_st : 1;
        unsigned int iocg_se_33_ds0 : 1;
        unsigned int iocg_se_33_ds1 : 1;
        unsigned int iocg_se_33_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_33_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_33_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_st_START (3)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_st_END (3)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_34_pu : 1;
        unsigned int iocg_se_34_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_34_st : 1;
        unsigned int iocg_se_34_ds0 : 1;
        unsigned int iocg_se_34_ds1 : 1;
        unsigned int iocg_se_34_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_34_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_34_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_st_START (3)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_st_END (3)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_35_pu : 1;
        unsigned int iocg_se_35_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_35_st : 1;
        unsigned int iocg_se_35_ds0 : 1;
        unsigned int iocg_se_35_ds1 : 1;
        unsigned int iocg_se_35_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_35_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_35_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_st_START (3)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_st_END (3)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_36_pu : 1;
        unsigned int iocg_se_36_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_36_st : 1;
        unsigned int iocg_se_36_ds0 : 1;
        unsigned int iocg_se_36_ds1 : 1;
        unsigned int iocg_se_36_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_36_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_36_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_st_START (3)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_st_END (3)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_37_pu : 1;
        unsigned int iocg_se_37_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_37_st : 1;
        unsigned int iocg_se_37_ds0 : 1;
        unsigned int iocg_se_37_ds1 : 1;
        unsigned int iocg_se_37_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_37_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_37_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_st_START (3)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_st_END (3)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_38_pu : 1;
        unsigned int iocg_se_38_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_38_st : 1;
        unsigned int iocg_se_38_ds0 : 1;
        unsigned int iocg_se_38_ds1 : 1;
        unsigned int iocg_se_38_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_38_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_38_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_st_START (3)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_st_END (3)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_39_pu : 1;
        unsigned int iocg_se_39_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_39_st : 1;
        unsigned int iocg_se_39_ds0 : 1;
        unsigned int iocg_se_39_ds1 : 1;
        unsigned int iocg_se_39_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_39_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_39_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_st_START (3)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_st_END (3)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int iocg_14_ds0 : 1;
        unsigned int iocg_14_ds1 : 1;
        unsigned int iocg_14_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_14_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_14_UNION;
#endif
#define SOC_IOC_AO_IOCG_14_iocg_14_ds0_START (4)
#define SOC_IOC_AO_IOCG_14_iocg_14_ds0_END (4)
#define SOC_IOC_AO_IOCG_14_iocg_14_ds1_START (5)
#define SOC_IOC_AO_IOCG_14_iocg_14_ds1_END (5)
#define SOC_IOC_AO_IOCG_14_iocg_14_ds2_START (6)
#define SOC_IOC_AO_IOCG_14_iocg_14_ds2_END (6)
#define SOC_IOC_AO_IOCG_14_iocg_14_sl_START (8)
#define SOC_IOC_AO_IOCG_14_iocg_14_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_15_pu : 1;
        unsigned int iocg_15_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_15_st : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOC_AO_IOCG_15_UNION;
#endif
#define SOC_IOC_AO_IOCG_15_iocg_15_pu_START (0)
#define SOC_IOC_AO_IOCG_15_iocg_15_pu_END (0)
#define SOC_IOC_AO_IOCG_15_iocg_15_pd_START (1)
#define SOC_IOC_AO_IOCG_15_iocg_15_pd_END (1)
#define SOC_IOC_AO_IOCG_15_iocg_15_st_START (3)
#define SOC_IOC_AO_IOCG_15_iocg_15_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_16_pu : 1;
        unsigned int iocg_16_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_16_st : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOC_AO_IOCG_16_UNION;
#endif
#define SOC_IOC_AO_IOCG_16_iocg_16_pu_START (0)
#define SOC_IOC_AO_IOCG_16_iocg_16_pu_END (0)
#define SOC_IOC_AO_IOCG_16_iocg_16_pd_START (1)
#define SOC_IOC_AO_IOCG_16_iocg_16_pd_END (1)
#define SOC_IOC_AO_IOCG_16_iocg_16_st_START (3)
#define SOC_IOC_AO_IOCG_16_iocg_16_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_17_pu : 1;
        unsigned int iocg_17_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_17_st : 1;
        unsigned int iocg_17_ds0 : 1;
        unsigned int iocg_17_ds1 : 1;
        unsigned int iocg_17_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_17_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_17_UNION;
#endif
#define SOC_IOC_AO_IOCG_17_iocg_17_pu_START (0)
#define SOC_IOC_AO_IOCG_17_iocg_17_pu_END (0)
#define SOC_IOC_AO_IOCG_17_iocg_17_pd_START (1)
#define SOC_IOC_AO_IOCG_17_iocg_17_pd_END (1)
#define SOC_IOC_AO_IOCG_17_iocg_17_st_START (3)
#define SOC_IOC_AO_IOCG_17_iocg_17_st_END (3)
#define SOC_IOC_AO_IOCG_17_iocg_17_ds0_START (4)
#define SOC_IOC_AO_IOCG_17_iocg_17_ds0_END (4)
#define SOC_IOC_AO_IOCG_17_iocg_17_ds1_START (5)
#define SOC_IOC_AO_IOCG_17_iocg_17_ds1_END (5)
#define SOC_IOC_AO_IOCG_17_iocg_17_ds2_START (6)
#define SOC_IOC_AO_IOCG_17_iocg_17_ds2_END (6)
#define SOC_IOC_AO_IOCG_17_iocg_17_sl_START (8)
#define SOC_IOC_AO_IOCG_17_iocg_17_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_18_pu : 1;
        unsigned int iocg_18_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_18_st : 1;
        unsigned int iocg_18_ds0 : 1;
        unsigned int iocg_18_ds1 : 1;
        unsigned int iocg_18_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_18_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_18_UNION;
#endif
#define SOC_IOC_AO_IOCG_18_iocg_18_pu_START (0)
#define SOC_IOC_AO_IOCG_18_iocg_18_pu_END (0)
#define SOC_IOC_AO_IOCG_18_iocg_18_pd_START (1)
#define SOC_IOC_AO_IOCG_18_iocg_18_pd_END (1)
#define SOC_IOC_AO_IOCG_18_iocg_18_st_START (3)
#define SOC_IOC_AO_IOCG_18_iocg_18_st_END (3)
#define SOC_IOC_AO_IOCG_18_iocg_18_ds0_START (4)
#define SOC_IOC_AO_IOCG_18_iocg_18_ds0_END (4)
#define SOC_IOC_AO_IOCG_18_iocg_18_ds1_START (5)
#define SOC_IOC_AO_IOCG_18_iocg_18_ds1_END (5)
#define SOC_IOC_AO_IOCG_18_iocg_18_ds2_START (6)
#define SOC_IOC_AO_IOCG_18_iocg_18_ds2_END (6)
#define SOC_IOC_AO_IOCG_18_iocg_18_sl_START (8)
#define SOC_IOC_AO_IOCG_18_iocg_18_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_19_pu : 1;
        unsigned int iocg_19_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_19_st : 1;
        unsigned int iocg_19_ds0 : 1;
        unsigned int iocg_19_ds1 : 1;
        unsigned int iocg_19_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_19_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_19_UNION;
#endif
#define SOC_IOC_AO_IOCG_19_iocg_19_pu_START (0)
#define SOC_IOC_AO_IOCG_19_iocg_19_pu_END (0)
#define SOC_IOC_AO_IOCG_19_iocg_19_pd_START (1)
#define SOC_IOC_AO_IOCG_19_iocg_19_pd_END (1)
#define SOC_IOC_AO_IOCG_19_iocg_19_st_START (3)
#define SOC_IOC_AO_IOCG_19_iocg_19_st_END (3)
#define SOC_IOC_AO_IOCG_19_iocg_19_ds0_START (4)
#define SOC_IOC_AO_IOCG_19_iocg_19_ds0_END (4)
#define SOC_IOC_AO_IOCG_19_iocg_19_ds1_START (5)
#define SOC_IOC_AO_IOCG_19_iocg_19_ds1_END (5)
#define SOC_IOC_AO_IOCG_19_iocg_19_ds2_START (6)
#define SOC_IOC_AO_IOCG_19_iocg_19_ds2_END (6)
#define SOC_IOC_AO_IOCG_19_iocg_19_sl_START (8)
#define SOC_IOC_AO_IOCG_19_iocg_19_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_20_pu : 1;
        unsigned int iocg_20_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_20_st : 1;
        unsigned int iocg_20_ds0 : 1;
        unsigned int iocg_20_ds1 : 1;
        unsigned int iocg_20_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_20_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_20_UNION;
#endif
#define SOC_IOC_AO_IOCG_20_iocg_20_pu_START (0)
#define SOC_IOC_AO_IOCG_20_iocg_20_pu_END (0)
#define SOC_IOC_AO_IOCG_20_iocg_20_pd_START (1)
#define SOC_IOC_AO_IOCG_20_iocg_20_pd_END (1)
#define SOC_IOC_AO_IOCG_20_iocg_20_st_START (3)
#define SOC_IOC_AO_IOCG_20_iocg_20_st_END (3)
#define SOC_IOC_AO_IOCG_20_iocg_20_ds0_START (4)
#define SOC_IOC_AO_IOCG_20_iocg_20_ds0_END (4)
#define SOC_IOC_AO_IOCG_20_iocg_20_ds1_START (5)
#define SOC_IOC_AO_IOCG_20_iocg_20_ds1_END (5)
#define SOC_IOC_AO_IOCG_20_iocg_20_ds2_START (6)
#define SOC_IOC_AO_IOCG_20_iocg_20_ds2_END (6)
#define SOC_IOC_AO_IOCG_20_iocg_20_sl_START (8)
#define SOC_IOC_AO_IOCG_20_iocg_20_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_21_pu : 1;
        unsigned int iocg_21_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_21_st : 1;
        unsigned int iocg_21_ds0 : 1;
        unsigned int iocg_21_ds1 : 1;
        unsigned int iocg_21_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_21_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_21_UNION;
#endif
#define SOC_IOC_AO_IOCG_21_iocg_21_pu_START (0)
#define SOC_IOC_AO_IOCG_21_iocg_21_pu_END (0)
#define SOC_IOC_AO_IOCG_21_iocg_21_pd_START (1)
#define SOC_IOC_AO_IOCG_21_iocg_21_pd_END (1)
#define SOC_IOC_AO_IOCG_21_iocg_21_st_START (3)
#define SOC_IOC_AO_IOCG_21_iocg_21_st_END (3)
#define SOC_IOC_AO_IOCG_21_iocg_21_ds0_START (4)
#define SOC_IOC_AO_IOCG_21_iocg_21_ds0_END (4)
#define SOC_IOC_AO_IOCG_21_iocg_21_ds1_START (5)
#define SOC_IOC_AO_IOCG_21_iocg_21_ds1_END (5)
#define SOC_IOC_AO_IOCG_21_iocg_21_ds2_START (6)
#define SOC_IOC_AO_IOCG_21_iocg_21_ds2_END (6)
#define SOC_IOC_AO_IOCG_21_iocg_21_sl_START (8)
#define SOC_IOC_AO_IOCG_21_iocg_21_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_40_pu : 1;
        unsigned int iocg_se_40_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_40_st : 1;
        unsigned int iocg_se_40_ds0 : 1;
        unsigned int iocg_se_40_ds1 : 1;
        unsigned int iocg_se_40_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_40_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_40_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_st_START (3)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_st_END (3)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_22_pu : 1;
        unsigned int iocg_22_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_22_st : 1;
        unsigned int iocg_22_ds0 : 1;
        unsigned int iocg_22_ds1 : 1;
        unsigned int iocg_22_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_22_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_22_UNION;
#endif
#define SOC_IOC_AO_IOCG_22_iocg_22_pu_START (0)
#define SOC_IOC_AO_IOCG_22_iocg_22_pu_END (0)
#define SOC_IOC_AO_IOCG_22_iocg_22_pd_START (1)
#define SOC_IOC_AO_IOCG_22_iocg_22_pd_END (1)
#define SOC_IOC_AO_IOCG_22_iocg_22_st_START (3)
#define SOC_IOC_AO_IOCG_22_iocg_22_st_END (3)
#define SOC_IOC_AO_IOCG_22_iocg_22_ds0_START (4)
#define SOC_IOC_AO_IOCG_22_iocg_22_ds0_END (4)
#define SOC_IOC_AO_IOCG_22_iocg_22_ds1_START (5)
#define SOC_IOC_AO_IOCG_22_iocg_22_ds1_END (5)
#define SOC_IOC_AO_IOCG_22_iocg_22_ds2_START (6)
#define SOC_IOC_AO_IOCG_22_iocg_22_ds2_END (6)
#define SOC_IOC_AO_IOCG_22_iocg_22_sl_START (8)
#define SOC_IOC_AO_IOCG_22_iocg_22_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_23_pu : 1;
        unsigned int iocg_23_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_23_st : 1;
        unsigned int iocg_23_ds0 : 1;
        unsigned int iocg_23_ds1 : 1;
        unsigned int iocg_23_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_23_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_23_UNION;
#endif
#define SOC_IOC_AO_IOCG_23_iocg_23_pu_START (0)
#define SOC_IOC_AO_IOCG_23_iocg_23_pu_END (0)
#define SOC_IOC_AO_IOCG_23_iocg_23_pd_START (1)
#define SOC_IOC_AO_IOCG_23_iocg_23_pd_END (1)
#define SOC_IOC_AO_IOCG_23_iocg_23_st_START (3)
#define SOC_IOC_AO_IOCG_23_iocg_23_st_END (3)
#define SOC_IOC_AO_IOCG_23_iocg_23_ds0_START (4)
#define SOC_IOC_AO_IOCG_23_iocg_23_ds0_END (4)
#define SOC_IOC_AO_IOCG_23_iocg_23_ds1_START (5)
#define SOC_IOC_AO_IOCG_23_iocg_23_ds1_END (5)
#define SOC_IOC_AO_IOCG_23_iocg_23_ds2_START (6)
#define SOC_IOC_AO_IOCG_23_iocg_23_ds2_END (6)
#define SOC_IOC_AO_IOCG_23_iocg_23_sl_START (8)
#define SOC_IOC_AO_IOCG_23_iocg_23_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_24_pu : 1;
        unsigned int iocg_24_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_24_st : 1;
        unsigned int iocg_24_ds0 : 1;
        unsigned int iocg_24_ds1 : 1;
        unsigned int iocg_24_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_24_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_24_UNION;
#endif
#define SOC_IOC_AO_IOCG_24_iocg_24_pu_START (0)
#define SOC_IOC_AO_IOCG_24_iocg_24_pu_END (0)
#define SOC_IOC_AO_IOCG_24_iocg_24_pd_START (1)
#define SOC_IOC_AO_IOCG_24_iocg_24_pd_END (1)
#define SOC_IOC_AO_IOCG_24_iocg_24_st_START (3)
#define SOC_IOC_AO_IOCG_24_iocg_24_st_END (3)
#define SOC_IOC_AO_IOCG_24_iocg_24_ds0_START (4)
#define SOC_IOC_AO_IOCG_24_iocg_24_ds0_END (4)
#define SOC_IOC_AO_IOCG_24_iocg_24_ds1_START (5)
#define SOC_IOC_AO_IOCG_24_iocg_24_ds1_END (5)
#define SOC_IOC_AO_IOCG_24_iocg_24_ds2_START (6)
#define SOC_IOC_AO_IOCG_24_iocg_24_ds2_END (6)
#define SOC_IOC_AO_IOCG_24_iocg_24_sl_START (8)
#define SOC_IOC_AO_IOCG_24_iocg_24_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_25_pu : 1;
        unsigned int iocg_25_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_25_st : 1;
        unsigned int iocg_25_ds0 : 1;
        unsigned int iocg_25_ds1 : 1;
        unsigned int iocg_25_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_25_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_25_UNION;
#endif
#define SOC_IOC_AO_IOCG_25_iocg_25_pu_START (0)
#define SOC_IOC_AO_IOCG_25_iocg_25_pu_END (0)
#define SOC_IOC_AO_IOCG_25_iocg_25_pd_START (1)
#define SOC_IOC_AO_IOCG_25_iocg_25_pd_END (1)
#define SOC_IOC_AO_IOCG_25_iocg_25_st_START (3)
#define SOC_IOC_AO_IOCG_25_iocg_25_st_END (3)
#define SOC_IOC_AO_IOCG_25_iocg_25_ds0_START (4)
#define SOC_IOC_AO_IOCG_25_iocg_25_ds0_END (4)
#define SOC_IOC_AO_IOCG_25_iocg_25_ds1_START (5)
#define SOC_IOC_AO_IOCG_25_iocg_25_ds1_END (5)
#define SOC_IOC_AO_IOCG_25_iocg_25_ds2_START (6)
#define SOC_IOC_AO_IOCG_25_iocg_25_ds2_END (6)
#define SOC_IOC_AO_IOCG_25_iocg_25_sl_START (8)
#define SOC_IOC_AO_IOCG_25_iocg_25_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_26_pu : 1;
        unsigned int iocg_26_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_26_st : 1;
        unsigned int iocg_26_ds0 : 1;
        unsigned int iocg_26_ds1 : 1;
        unsigned int iocg_26_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_26_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_26_UNION;
#endif
#define SOC_IOC_AO_IOCG_26_iocg_26_pu_START (0)
#define SOC_IOC_AO_IOCG_26_iocg_26_pu_END (0)
#define SOC_IOC_AO_IOCG_26_iocg_26_pd_START (1)
#define SOC_IOC_AO_IOCG_26_iocg_26_pd_END (1)
#define SOC_IOC_AO_IOCG_26_iocg_26_st_START (3)
#define SOC_IOC_AO_IOCG_26_iocg_26_st_END (3)
#define SOC_IOC_AO_IOCG_26_iocg_26_ds0_START (4)
#define SOC_IOC_AO_IOCG_26_iocg_26_ds0_END (4)
#define SOC_IOC_AO_IOCG_26_iocg_26_ds1_START (5)
#define SOC_IOC_AO_IOCG_26_iocg_26_ds1_END (5)
#define SOC_IOC_AO_IOCG_26_iocg_26_ds2_START (6)
#define SOC_IOC_AO_IOCG_26_iocg_26_ds2_END (6)
#define SOC_IOC_AO_IOCG_26_iocg_26_sl_START (8)
#define SOC_IOC_AO_IOCG_26_iocg_26_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_41_pu : 1;
        unsigned int iocg_se_41_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_41_st : 1;
        unsigned int iocg_se_41_ds0 : 1;
        unsigned int iocg_se_41_ds1 : 1;
        unsigned int iocg_se_41_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_41_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_41_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_st_START (3)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_st_END (3)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_42_pu : 1;
        unsigned int iocg_se_42_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_42_st : 1;
        unsigned int iocg_se_42_ds0 : 1;
        unsigned int iocg_se_42_ds1 : 1;
        unsigned int iocg_se_42_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_42_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_42_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_st_START (3)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_st_END (3)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_43_pu : 1;
        unsigned int iocg_se_43_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_43_st : 1;
        unsigned int iocg_se_43_ds0 : 1;
        unsigned int iocg_se_43_ds1 : 1;
        unsigned int iocg_se_43_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_43_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_43_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_st_START (3)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_st_END (3)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_44_pu : 1;
        unsigned int iocg_se_44_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_44_st : 1;
        unsigned int iocg_se_44_ds0 : 1;
        unsigned int iocg_se_44_ds1 : 1;
        unsigned int iocg_se_44_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_44_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_44_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_st_START (3)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_st_END (3)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_45_pu : 1;
        unsigned int iocg_se_45_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_45_st : 1;
        unsigned int iocg_se_45_ds0 : 1;
        unsigned int iocg_se_45_ds1 : 1;
        unsigned int iocg_se_45_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_45_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_45_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_st_START (3)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_st_END (3)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_46_pu : 1;
        unsigned int iocg_se_46_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_46_st : 1;
        unsigned int iocg_se_46_ds0 : 1;
        unsigned int iocg_se_46_ds1 : 1;
        unsigned int iocg_se_46_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_46_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_46_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_st_START (3)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_st_END (3)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_47_pu : 1;
        unsigned int iocg_se_47_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_47_st : 1;
        unsigned int iocg_se_47_ds0 : 1;
        unsigned int iocg_se_47_ds1 : 1;
        unsigned int iocg_se_47_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_47_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_47_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_st_START (3)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_st_END (3)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_48_pu : 1;
        unsigned int iocg_se_48_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_48_st : 1;
        unsigned int iocg_se_48_ds0 : 1;
        unsigned int iocg_se_48_ds1 : 1;
        unsigned int iocg_se_48_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_48_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_48_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_st_START (3)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_st_END (3)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_49_pu : 1;
        unsigned int iocg_se_49_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_49_st : 1;
        unsigned int iocg_se_49_ds0 : 1;
        unsigned int iocg_se_49_ds1 : 1;
        unsigned int iocg_se_49_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_49_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_49_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_st_START (3)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_st_END (3)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_50_pu : 1;
        unsigned int iocg_se_50_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_50_st : 1;
        unsigned int iocg_se_50_ds0 : 1;
        unsigned int iocg_se_50_ds1 : 1;
        unsigned int iocg_se_50_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_50_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_50_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_st_START (3)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_st_END (3)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_51_pu : 1;
        unsigned int iocg_se_51_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_51_st : 1;
        unsigned int iocg_se_51_ds0 : 1;
        unsigned int iocg_se_51_ds1 : 1;
        unsigned int iocg_se_51_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_51_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_51_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_st_START (3)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_st_END (3)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_52_pu : 1;
        unsigned int iocg_se_52_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_52_st : 1;
        unsigned int iocg_se_52_ds0 : 1;
        unsigned int iocg_se_52_ds1 : 1;
        unsigned int iocg_se_52_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_52_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_52_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_st_START (3)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_st_END (3)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_53_pu : 1;
        unsigned int iocg_se_53_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_53_st : 1;
        unsigned int iocg_se_53_ds0 : 1;
        unsigned int iocg_se_53_ds1 : 1;
        unsigned int iocg_se_53_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_53_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_53_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_st_START (3)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_st_END (3)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_54_pu : 1;
        unsigned int iocg_se_54_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_54_st : 1;
        unsigned int iocg_se_54_ds0 : 1;
        unsigned int iocg_se_54_ds1 : 1;
        unsigned int iocg_se_54_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_54_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_54_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_st_START (3)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_st_END (3)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_27_pu : 1;
        unsigned int iocg_27_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_27_st : 1;
        unsigned int iocg_27_ds0 : 1;
        unsigned int iocg_27_ds1 : 1;
        unsigned int iocg_27_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_27_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_27_UNION;
#endif
#define SOC_IOC_AO_IOCG_27_iocg_27_pu_START (0)
#define SOC_IOC_AO_IOCG_27_iocg_27_pu_END (0)
#define SOC_IOC_AO_IOCG_27_iocg_27_pd_START (1)
#define SOC_IOC_AO_IOCG_27_iocg_27_pd_END (1)
#define SOC_IOC_AO_IOCG_27_iocg_27_st_START (3)
#define SOC_IOC_AO_IOCG_27_iocg_27_st_END (3)
#define SOC_IOC_AO_IOCG_27_iocg_27_ds0_START (4)
#define SOC_IOC_AO_IOCG_27_iocg_27_ds0_END (4)
#define SOC_IOC_AO_IOCG_27_iocg_27_ds1_START (5)
#define SOC_IOC_AO_IOCG_27_iocg_27_ds1_END (5)
#define SOC_IOC_AO_IOCG_27_iocg_27_ds2_START (6)
#define SOC_IOC_AO_IOCG_27_iocg_27_ds2_END (6)
#define SOC_IOC_AO_IOCG_27_iocg_27_sl_START (8)
#define SOC_IOC_AO_IOCG_27_iocg_27_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_28_pu : 1;
        unsigned int iocg_28_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_28_st : 1;
        unsigned int iocg_28_ds0 : 1;
        unsigned int iocg_28_ds1 : 1;
        unsigned int iocg_28_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_28_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_28_UNION;
#endif
#define SOC_IOC_AO_IOCG_28_iocg_28_pu_START (0)
#define SOC_IOC_AO_IOCG_28_iocg_28_pu_END (0)
#define SOC_IOC_AO_IOCG_28_iocg_28_pd_START (1)
#define SOC_IOC_AO_IOCG_28_iocg_28_pd_END (1)
#define SOC_IOC_AO_IOCG_28_iocg_28_st_START (3)
#define SOC_IOC_AO_IOCG_28_iocg_28_st_END (3)
#define SOC_IOC_AO_IOCG_28_iocg_28_ds0_START (4)
#define SOC_IOC_AO_IOCG_28_iocg_28_ds0_END (4)
#define SOC_IOC_AO_IOCG_28_iocg_28_ds1_START (5)
#define SOC_IOC_AO_IOCG_28_iocg_28_ds1_END (5)
#define SOC_IOC_AO_IOCG_28_iocg_28_ds2_START (6)
#define SOC_IOC_AO_IOCG_28_iocg_28_ds2_END (6)
#define SOC_IOC_AO_IOCG_28_iocg_28_sl_START (8)
#define SOC_IOC_AO_IOCG_28_iocg_28_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_55_pu : 1;
        unsigned int iocg_se_55_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_55_st : 1;
        unsigned int iocg_se_55_ds0 : 1;
        unsigned int iocg_se_55_ds1 : 1;
        unsigned int iocg_se_55_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_55_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_55_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_st_START (3)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_st_END (3)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_29_pu : 1;
        unsigned int iocg_29_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_29_st : 1;
        unsigned int iocg_29_ds0 : 1;
        unsigned int iocg_29_ds1 : 1;
        unsigned int iocg_29_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_29_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_29_UNION;
#endif
#define SOC_IOC_AO_IOCG_29_iocg_29_pu_START (0)
#define SOC_IOC_AO_IOCG_29_iocg_29_pu_END (0)
#define SOC_IOC_AO_IOCG_29_iocg_29_pd_START (1)
#define SOC_IOC_AO_IOCG_29_iocg_29_pd_END (1)
#define SOC_IOC_AO_IOCG_29_iocg_29_st_START (3)
#define SOC_IOC_AO_IOCG_29_iocg_29_st_END (3)
#define SOC_IOC_AO_IOCG_29_iocg_29_ds0_START (4)
#define SOC_IOC_AO_IOCG_29_iocg_29_ds0_END (4)
#define SOC_IOC_AO_IOCG_29_iocg_29_ds1_START (5)
#define SOC_IOC_AO_IOCG_29_iocg_29_ds1_END (5)
#define SOC_IOC_AO_IOCG_29_iocg_29_ds2_START (6)
#define SOC_IOC_AO_IOCG_29_iocg_29_ds2_END (6)
#define SOC_IOC_AO_IOCG_29_iocg_29_sl_START (8)
#define SOC_IOC_AO_IOCG_29_iocg_29_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_30_pu : 1;
        unsigned int iocg_30_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_30_st : 1;
        unsigned int iocg_30_ds0 : 1;
        unsigned int iocg_30_ds1 : 1;
        unsigned int iocg_30_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_30_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_30_UNION;
#endif
#define SOC_IOC_AO_IOCG_30_iocg_30_pu_START (0)
#define SOC_IOC_AO_IOCG_30_iocg_30_pu_END (0)
#define SOC_IOC_AO_IOCG_30_iocg_30_pd_START (1)
#define SOC_IOC_AO_IOCG_30_iocg_30_pd_END (1)
#define SOC_IOC_AO_IOCG_30_iocg_30_st_START (3)
#define SOC_IOC_AO_IOCG_30_iocg_30_st_END (3)
#define SOC_IOC_AO_IOCG_30_iocg_30_ds0_START (4)
#define SOC_IOC_AO_IOCG_30_iocg_30_ds0_END (4)
#define SOC_IOC_AO_IOCG_30_iocg_30_ds1_START (5)
#define SOC_IOC_AO_IOCG_30_iocg_30_ds1_END (5)
#define SOC_IOC_AO_IOCG_30_iocg_30_ds2_START (6)
#define SOC_IOC_AO_IOCG_30_iocg_30_ds2_END (6)
#define SOC_IOC_AO_IOCG_30_iocg_30_sl_START (8)
#define SOC_IOC_AO_IOCG_30_iocg_30_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_56_pu : 1;
        unsigned int iocg_se_56_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_56_st : 1;
        unsigned int iocg_se_56_ds0 : 1;
        unsigned int iocg_se_56_ds1 : 1;
        unsigned int iocg_se_56_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_56_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_56_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_st_START (3)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_st_END (3)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_56_iocg_se_56_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_57_pu : 1;
        unsigned int iocg_se_57_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_57_st : 1;
        unsigned int iocg_se_57_ds0 : 1;
        unsigned int iocg_se_57_ds1 : 1;
        unsigned int iocg_se_57_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_57_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_57_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_st_START (3)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_st_END (3)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_57_iocg_se_57_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_58_pu : 1;
        unsigned int iocg_se_58_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_58_st : 1;
        unsigned int iocg_se_58_ds0 : 1;
        unsigned int iocg_se_58_ds1 : 1;
        unsigned int iocg_se_58_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_58_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_58_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_st_START (3)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_st_END (3)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_58_iocg_se_58_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_59_pu : 1;
        unsigned int iocg_se_59_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_59_st : 1;
        unsigned int iocg_se_59_ds0 : 1;
        unsigned int iocg_se_59_ds1 : 1;
        unsigned int iocg_se_59_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_59_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_59_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_st_START (3)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_st_END (3)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_59_iocg_se_59_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_31_pu : 1;
        unsigned int iocg_31_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_31_st : 1;
        unsigned int iocg_31_ds0 : 1;
        unsigned int iocg_31_ds1 : 1;
        unsigned int iocg_31_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_31_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_31_UNION;
#endif
#define SOC_IOC_AO_IOCG_31_iocg_31_pu_START (0)
#define SOC_IOC_AO_IOCG_31_iocg_31_pu_END (0)
#define SOC_IOC_AO_IOCG_31_iocg_31_pd_START (1)
#define SOC_IOC_AO_IOCG_31_iocg_31_pd_END (1)
#define SOC_IOC_AO_IOCG_31_iocg_31_st_START (3)
#define SOC_IOC_AO_IOCG_31_iocg_31_st_END (3)
#define SOC_IOC_AO_IOCG_31_iocg_31_ds0_START (4)
#define SOC_IOC_AO_IOCG_31_iocg_31_ds0_END (4)
#define SOC_IOC_AO_IOCG_31_iocg_31_ds1_START (5)
#define SOC_IOC_AO_IOCG_31_iocg_31_ds1_END (5)
#define SOC_IOC_AO_IOCG_31_iocg_31_ds2_START (6)
#define SOC_IOC_AO_IOCG_31_iocg_31_ds2_END (6)
#define SOC_IOC_AO_IOCG_31_iocg_31_sl_START (8)
#define SOC_IOC_AO_IOCG_31_iocg_31_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_32_pu : 1;
        unsigned int iocg_32_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_32_st : 1;
        unsigned int iocg_32_ds0 : 1;
        unsigned int iocg_32_ds1 : 1;
        unsigned int iocg_32_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_32_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_32_UNION;
#endif
#define SOC_IOC_AO_IOCG_32_iocg_32_pu_START (0)
#define SOC_IOC_AO_IOCG_32_iocg_32_pu_END (0)
#define SOC_IOC_AO_IOCG_32_iocg_32_pd_START (1)
#define SOC_IOC_AO_IOCG_32_iocg_32_pd_END (1)
#define SOC_IOC_AO_IOCG_32_iocg_32_st_START (3)
#define SOC_IOC_AO_IOCG_32_iocg_32_st_END (3)
#define SOC_IOC_AO_IOCG_32_iocg_32_ds0_START (4)
#define SOC_IOC_AO_IOCG_32_iocg_32_ds0_END (4)
#define SOC_IOC_AO_IOCG_32_iocg_32_ds1_START (5)
#define SOC_IOC_AO_IOCG_32_iocg_32_ds1_END (5)
#define SOC_IOC_AO_IOCG_32_iocg_32_ds2_START (6)
#define SOC_IOC_AO_IOCG_32_iocg_32_ds2_END (6)
#define SOC_IOC_AO_IOCG_32_iocg_32_sl_START (8)
#define SOC_IOC_AO_IOCG_32_iocg_32_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_33_pu : 1;
        unsigned int iocg_33_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_33_st : 1;
        unsigned int iocg_33_ds0 : 1;
        unsigned int iocg_33_ds1 : 1;
        unsigned int iocg_33_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_33_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_33_UNION;
#endif
#define SOC_IOC_AO_IOCG_33_iocg_33_pu_START (0)
#define SOC_IOC_AO_IOCG_33_iocg_33_pu_END (0)
#define SOC_IOC_AO_IOCG_33_iocg_33_pd_START (1)
#define SOC_IOC_AO_IOCG_33_iocg_33_pd_END (1)
#define SOC_IOC_AO_IOCG_33_iocg_33_st_START (3)
#define SOC_IOC_AO_IOCG_33_iocg_33_st_END (3)
#define SOC_IOC_AO_IOCG_33_iocg_33_ds0_START (4)
#define SOC_IOC_AO_IOCG_33_iocg_33_ds0_END (4)
#define SOC_IOC_AO_IOCG_33_iocg_33_ds1_START (5)
#define SOC_IOC_AO_IOCG_33_iocg_33_ds1_END (5)
#define SOC_IOC_AO_IOCG_33_iocg_33_ds2_START (6)
#define SOC_IOC_AO_IOCG_33_iocg_33_ds2_END (6)
#define SOC_IOC_AO_IOCG_33_iocg_33_sl_START (8)
#define SOC_IOC_AO_IOCG_33_iocg_33_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_34_pu : 1;
        unsigned int iocg_34_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_34_st : 1;
        unsigned int iocg_34_ds0 : 1;
        unsigned int iocg_34_ds1 : 1;
        unsigned int iocg_34_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_34_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_34_UNION;
#endif
#define SOC_IOC_AO_IOCG_34_iocg_34_pu_START (0)
#define SOC_IOC_AO_IOCG_34_iocg_34_pu_END (0)
#define SOC_IOC_AO_IOCG_34_iocg_34_pd_START (1)
#define SOC_IOC_AO_IOCG_34_iocg_34_pd_END (1)
#define SOC_IOC_AO_IOCG_34_iocg_34_st_START (3)
#define SOC_IOC_AO_IOCG_34_iocg_34_st_END (3)
#define SOC_IOC_AO_IOCG_34_iocg_34_ds0_START (4)
#define SOC_IOC_AO_IOCG_34_iocg_34_ds0_END (4)
#define SOC_IOC_AO_IOCG_34_iocg_34_ds1_START (5)
#define SOC_IOC_AO_IOCG_34_iocg_34_ds1_END (5)
#define SOC_IOC_AO_IOCG_34_iocg_34_ds2_START (6)
#define SOC_IOC_AO_IOCG_34_iocg_34_ds2_END (6)
#define SOC_IOC_AO_IOCG_34_iocg_34_sl_START (8)
#define SOC_IOC_AO_IOCG_34_iocg_34_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_60_pu : 1;
        unsigned int iocg_se_60_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_60_st : 1;
        unsigned int iocg_se_60_ds0 : 1;
        unsigned int iocg_se_60_ds1 : 1;
        unsigned int iocg_se_60_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_60_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_60_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_st_START (3)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_st_END (3)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_60_iocg_se_60_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_61_pu : 1;
        unsigned int iocg_se_61_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_61_st : 1;
        unsigned int iocg_se_61_ds0 : 1;
        unsigned int iocg_se_61_ds1 : 1;
        unsigned int iocg_se_61_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_61_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_61_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_st_START (3)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_st_END (3)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_61_iocg_se_61_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_62_pu : 1;
        unsigned int iocg_se_62_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_62_st : 1;
        unsigned int iocg_se_62_ds0 : 1;
        unsigned int iocg_se_62_ds1 : 1;
        unsigned int iocg_se_62_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_62_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_62_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_st_START (3)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_st_END (3)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_62_iocg_se_62_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_63_pu : 1;
        unsigned int iocg_se_63_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_63_st : 1;
        unsigned int iocg_se_63_ds0 : 1;
        unsigned int iocg_se_63_ds1 : 1;
        unsigned int iocg_se_63_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_63_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_63_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_st_START (3)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_st_END (3)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_63_iocg_se_63_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_64_pu : 1;
        unsigned int iocg_se_64_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_64_st : 1;
        unsigned int iocg_se_64_ds0 : 1;
        unsigned int iocg_se_64_ds1 : 1;
        unsigned int iocg_se_64_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_64_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_64_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_st_START (3)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_st_END (3)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_64_iocg_se_64_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_35_pu : 1;
        unsigned int iocg_35_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_35_st : 1;
        unsigned int iocg_35_ds0 : 1;
        unsigned int iocg_35_ds1 : 1;
        unsigned int iocg_35_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_35_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_35_UNION;
#endif
#define SOC_IOC_AO_IOCG_35_iocg_35_pu_START (0)
#define SOC_IOC_AO_IOCG_35_iocg_35_pu_END (0)
#define SOC_IOC_AO_IOCG_35_iocg_35_pd_START (1)
#define SOC_IOC_AO_IOCG_35_iocg_35_pd_END (1)
#define SOC_IOC_AO_IOCG_35_iocg_35_st_START (3)
#define SOC_IOC_AO_IOCG_35_iocg_35_st_END (3)
#define SOC_IOC_AO_IOCG_35_iocg_35_ds0_START (4)
#define SOC_IOC_AO_IOCG_35_iocg_35_ds0_END (4)
#define SOC_IOC_AO_IOCG_35_iocg_35_ds1_START (5)
#define SOC_IOC_AO_IOCG_35_iocg_35_ds1_END (5)
#define SOC_IOC_AO_IOCG_35_iocg_35_ds2_START (6)
#define SOC_IOC_AO_IOCG_35_iocg_35_ds2_END (6)
#define SOC_IOC_AO_IOCG_35_iocg_35_sl_START (8)
#define SOC_IOC_AO_IOCG_35_iocg_35_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_36_pu : 1;
        unsigned int iocg_36_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_36_st : 1;
        unsigned int iocg_36_ds0 : 1;
        unsigned int iocg_36_ds1 : 1;
        unsigned int iocg_36_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_36_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_36_UNION;
#endif
#define SOC_IOC_AO_IOCG_36_iocg_36_pu_START (0)
#define SOC_IOC_AO_IOCG_36_iocg_36_pu_END (0)
#define SOC_IOC_AO_IOCG_36_iocg_36_pd_START (1)
#define SOC_IOC_AO_IOCG_36_iocg_36_pd_END (1)
#define SOC_IOC_AO_IOCG_36_iocg_36_st_START (3)
#define SOC_IOC_AO_IOCG_36_iocg_36_st_END (3)
#define SOC_IOC_AO_IOCG_36_iocg_36_ds0_START (4)
#define SOC_IOC_AO_IOCG_36_iocg_36_ds0_END (4)
#define SOC_IOC_AO_IOCG_36_iocg_36_ds1_START (5)
#define SOC_IOC_AO_IOCG_36_iocg_36_ds1_END (5)
#define SOC_IOC_AO_IOCG_36_iocg_36_ds2_START (6)
#define SOC_IOC_AO_IOCG_36_iocg_36_ds2_END (6)
#define SOC_IOC_AO_IOCG_36_iocg_36_sl_START (8)
#define SOC_IOC_AO_IOCG_36_iocg_36_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_37_pu : 1;
        unsigned int iocg_37_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_37_st : 1;
        unsigned int iocg_37_ds0 : 1;
        unsigned int iocg_37_ds1 : 1;
        unsigned int iocg_37_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_37_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_37_UNION;
#endif
#define SOC_IOC_AO_IOCG_37_iocg_37_pu_START (0)
#define SOC_IOC_AO_IOCG_37_iocg_37_pu_END (0)
#define SOC_IOC_AO_IOCG_37_iocg_37_pd_START (1)
#define SOC_IOC_AO_IOCG_37_iocg_37_pd_END (1)
#define SOC_IOC_AO_IOCG_37_iocg_37_st_START (3)
#define SOC_IOC_AO_IOCG_37_iocg_37_st_END (3)
#define SOC_IOC_AO_IOCG_37_iocg_37_ds0_START (4)
#define SOC_IOC_AO_IOCG_37_iocg_37_ds0_END (4)
#define SOC_IOC_AO_IOCG_37_iocg_37_ds1_START (5)
#define SOC_IOC_AO_IOCG_37_iocg_37_ds1_END (5)
#define SOC_IOC_AO_IOCG_37_iocg_37_ds2_START (6)
#define SOC_IOC_AO_IOCG_37_iocg_37_ds2_END (6)
#define SOC_IOC_AO_IOCG_37_iocg_37_sl_START (8)
#define SOC_IOC_AO_IOCG_37_iocg_37_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_38_pu : 1;
        unsigned int iocg_38_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_38_st : 1;
        unsigned int iocg_38_ds0 : 1;
        unsigned int iocg_38_ds1 : 1;
        unsigned int iocg_38_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_38_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_38_UNION;
#endif
#define SOC_IOC_AO_IOCG_38_iocg_38_pu_START (0)
#define SOC_IOC_AO_IOCG_38_iocg_38_pu_END (0)
#define SOC_IOC_AO_IOCG_38_iocg_38_pd_START (1)
#define SOC_IOC_AO_IOCG_38_iocg_38_pd_END (1)
#define SOC_IOC_AO_IOCG_38_iocg_38_st_START (3)
#define SOC_IOC_AO_IOCG_38_iocg_38_st_END (3)
#define SOC_IOC_AO_IOCG_38_iocg_38_ds0_START (4)
#define SOC_IOC_AO_IOCG_38_iocg_38_ds0_END (4)
#define SOC_IOC_AO_IOCG_38_iocg_38_ds1_START (5)
#define SOC_IOC_AO_IOCG_38_iocg_38_ds1_END (5)
#define SOC_IOC_AO_IOCG_38_iocg_38_ds2_START (6)
#define SOC_IOC_AO_IOCG_38_iocg_38_ds2_END (6)
#define SOC_IOC_AO_IOCG_38_iocg_38_sl_START (8)
#define SOC_IOC_AO_IOCG_38_iocg_38_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_39_pu : 1;
        unsigned int iocg_39_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_39_st : 1;
        unsigned int iocg_39_ds0 : 1;
        unsigned int iocg_39_ds1 : 1;
        unsigned int iocg_39_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_39_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_39_UNION;
#endif
#define SOC_IOC_AO_IOCG_39_iocg_39_pu_START (0)
#define SOC_IOC_AO_IOCG_39_iocg_39_pu_END (0)
#define SOC_IOC_AO_IOCG_39_iocg_39_pd_START (1)
#define SOC_IOC_AO_IOCG_39_iocg_39_pd_END (1)
#define SOC_IOC_AO_IOCG_39_iocg_39_st_START (3)
#define SOC_IOC_AO_IOCG_39_iocg_39_st_END (3)
#define SOC_IOC_AO_IOCG_39_iocg_39_ds0_START (4)
#define SOC_IOC_AO_IOCG_39_iocg_39_ds0_END (4)
#define SOC_IOC_AO_IOCG_39_iocg_39_ds1_START (5)
#define SOC_IOC_AO_IOCG_39_iocg_39_ds1_END (5)
#define SOC_IOC_AO_IOCG_39_iocg_39_ds2_START (6)
#define SOC_IOC_AO_IOCG_39_iocg_39_ds2_END (6)
#define SOC_IOC_AO_IOCG_39_iocg_39_sl_START (8)
#define SOC_IOC_AO_IOCG_39_iocg_39_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_40_pu : 1;
        unsigned int iocg_40_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_40_st : 1;
        unsigned int iocg_40_ds0 : 1;
        unsigned int iocg_40_ds1 : 1;
        unsigned int iocg_40_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_40_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_40_UNION;
#endif
#define SOC_IOC_AO_IOCG_40_iocg_40_pu_START (0)
#define SOC_IOC_AO_IOCG_40_iocg_40_pu_END (0)
#define SOC_IOC_AO_IOCG_40_iocg_40_pd_START (1)
#define SOC_IOC_AO_IOCG_40_iocg_40_pd_END (1)
#define SOC_IOC_AO_IOCG_40_iocg_40_st_START (3)
#define SOC_IOC_AO_IOCG_40_iocg_40_st_END (3)
#define SOC_IOC_AO_IOCG_40_iocg_40_ds0_START (4)
#define SOC_IOC_AO_IOCG_40_iocg_40_ds0_END (4)
#define SOC_IOC_AO_IOCG_40_iocg_40_ds1_START (5)
#define SOC_IOC_AO_IOCG_40_iocg_40_ds1_END (5)
#define SOC_IOC_AO_IOCG_40_iocg_40_ds2_START (6)
#define SOC_IOC_AO_IOCG_40_iocg_40_ds2_END (6)
#define SOC_IOC_AO_IOCG_40_iocg_40_sl_START (8)
#define SOC_IOC_AO_IOCG_40_iocg_40_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_41_pu : 1;
        unsigned int iocg_41_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_41_st : 1;
        unsigned int iocg_41_ds0 : 1;
        unsigned int iocg_41_ds1 : 1;
        unsigned int iocg_41_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_41_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_41_UNION;
#endif
#define SOC_IOC_AO_IOCG_41_iocg_41_pu_START (0)
#define SOC_IOC_AO_IOCG_41_iocg_41_pu_END (0)
#define SOC_IOC_AO_IOCG_41_iocg_41_pd_START (1)
#define SOC_IOC_AO_IOCG_41_iocg_41_pd_END (1)
#define SOC_IOC_AO_IOCG_41_iocg_41_st_START (3)
#define SOC_IOC_AO_IOCG_41_iocg_41_st_END (3)
#define SOC_IOC_AO_IOCG_41_iocg_41_ds0_START (4)
#define SOC_IOC_AO_IOCG_41_iocg_41_ds0_END (4)
#define SOC_IOC_AO_IOCG_41_iocg_41_ds1_START (5)
#define SOC_IOC_AO_IOCG_41_iocg_41_ds1_END (5)
#define SOC_IOC_AO_IOCG_41_iocg_41_ds2_START (6)
#define SOC_IOC_AO_IOCG_41_iocg_41_ds2_END (6)
#define SOC_IOC_AO_IOCG_41_iocg_41_sl_START (8)
#define SOC_IOC_AO_IOCG_41_iocg_41_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_65_pu : 1;
        unsigned int iocg_se_65_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_65_st : 1;
        unsigned int iocg_se_65_ds0 : 1;
        unsigned int iocg_se_65_ds1 : 1;
        unsigned int iocg_se_65_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_65_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_65_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_st_START (3)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_st_END (3)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_65_iocg_se_65_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_66_pu : 1;
        unsigned int iocg_se_66_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_66_st : 1;
        unsigned int iocg_se_66_ds0 : 1;
        unsigned int iocg_se_66_ds1 : 1;
        unsigned int iocg_se_66_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_66_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_66_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_st_START (3)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_st_END (3)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_66_iocg_se_66_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_67_pu : 1;
        unsigned int iocg_se_67_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_67_st : 1;
        unsigned int iocg_se_67_ds0 : 1;
        unsigned int iocg_se_67_ds1 : 1;
        unsigned int iocg_se_67_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_67_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_67_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_st_START (3)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_st_END (3)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_67_iocg_se_67_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_68_pu : 1;
        unsigned int iocg_se_68_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_68_st : 1;
        unsigned int iocg_se_68_ds0 : 1;
        unsigned int iocg_se_68_ds1 : 1;
        unsigned int iocg_se_68_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_68_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_68_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_st_START (3)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_st_END (3)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_68_iocg_se_68_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_69_pu : 1;
        unsigned int iocg_se_69_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_69_st : 1;
        unsigned int iocg_se_69_ds0 : 1;
        unsigned int iocg_se_69_ds1 : 1;
        unsigned int iocg_se_69_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_69_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_SE_69_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_st_START (3)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_st_END (3)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_69_iocg_se_69_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_42_pu : 1;
        unsigned int iocg_42_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_42_st : 1;
        unsigned int iocg_42_ds0 : 1;
        unsigned int iocg_42_ds1 : 1;
        unsigned int iocg_42_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_42_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_AO_IOCG_42_UNION;
#endif
#define SOC_IOC_AO_IOCG_42_iocg_42_pu_START (0)
#define SOC_IOC_AO_IOCG_42_iocg_42_pu_END (0)
#define SOC_IOC_AO_IOCG_42_iocg_42_pd_START (1)
#define SOC_IOC_AO_IOCG_42_iocg_42_pd_END (1)
#define SOC_IOC_AO_IOCG_42_iocg_42_st_START (3)
#define SOC_IOC_AO_IOCG_42_iocg_42_st_END (3)
#define SOC_IOC_AO_IOCG_42_iocg_42_ds0_START (4)
#define SOC_IOC_AO_IOCG_42_iocg_42_ds0_END (4)
#define SOC_IOC_AO_IOCG_42_iocg_42_ds1_START (5)
#define SOC_IOC_AO_IOCG_42_iocg_42_ds1_END (5)
#define SOC_IOC_AO_IOCG_42_iocg_42_ds2_START (6)
#define SOC_IOC_AO_IOCG_42_iocg_42_ds2_END (6)
#define SOC_IOC_AO_IOCG_42_iocg_42_sl_START (8)
#define SOC_IOC_AO_IOCG_42_iocg_42_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int iocg_se_70_ds0 : 1;
        unsigned int iocg_se_70_ds1 : 1;
        unsigned int iocg_se_70_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_70_sl : 1;
        unsigned int iocg_se_70_pe : 1;
        unsigned int iocg_se_70_ps : 1;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_IOC_AO_IOCG_SE_70_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_sl_START (8)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_sl_END (8)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_pe_START (9)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_pe_END (9)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ps_START (10)
#define SOC_IOC_AO_IOCG_SE_70_iocg_se_70_ps_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_4 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_4_UNION;
#endif
#define SOC_IOC_AO_IOMG_4_iomg_4_START (0)
#define SOC_IOC_AO_IOMG_4_iomg_4_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_5 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_5_UNION;
#endif
#define SOC_IOC_AO_IOMG_5_iomg_5_START (0)
#define SOC_IOC_AO_IOMG_5_iomg_5_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_6 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_6_UNION;
#endif
#define SOC_IOC_AO_IOMG_6_iomg_6_START (0)
#define SOC_IOC_AO_IOMG_6_iomg_6_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_7 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_7_UNION;
#endif
#define SOC_IOC_AO_IOMG_7_iomg_7_START (0)
#define SOC_IOC_AO_IOMG_7_iomg_7_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_0 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_0_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_0_iomg_se_0_START (0)
#define SOC_IOC_AO_IOMG_SE_0_iomg_se_0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_1 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_1_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_1_iomg_se_1_START (0)
#define SOC_IOC_AO_IOMG_SE_1_iomg_se_1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_2 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_2_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_2_iomg_se_2_START (0)
#define SOC_IOC_AO_IOMG_SE_2_iomg_se_2_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_3 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_3_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_3_iomg_se_3_START (0)
#define SOC_IOC_AO_IOMG_SE_3_iomg_se_3_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_4 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_4_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_4_iomg_se_4_START (0)
#define SOC_IOC_AO_IOMG_SE_4_iomg_se_4_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_5 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_5_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_5_iomg_se_5_START (0)
#define SOC_IOC_AO_IOMG_SE_5_iomg_se_5_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_6 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_6_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_6_iomg_se_6_START (0)
#define SOC_IOC_AO_IOMG_SE_6_iomg_se_6_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_7 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_7_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_7_iomg_se_7_START (0)
#define SOC_IOC_AO_IOMG_SE_7_iomg_se_7_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_8 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_8_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_8_iomg_se_8_START (0)
#define SOC_IOC_AO_IOMG_SE_8_iomg_se_8_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_9 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_9_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_9_iomg_se_9_START (0)
#define SOC_IOC_AO_IOMG_SE_9_iomg_se_9_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_10 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_10_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_10_iomg_se_10_START (0)
#define SOC_IOC_AO_IOMG_SE_10_iomg_se_10_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_11 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_11_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_11_iomg_se_11_START (0)
#define SOC_IOC_AO_IOMG_SE_11_iomg_se_11_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_12 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_12_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_12_iomg_se_12_START (0)
#define SOC_IOC_AO_IOMG_SE_12_iomg_se_12_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_13 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_13_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_13_iomg_se_13_START (0)
#define SOC_IOC_AO_IOMG_SE_13_iomg_se_13_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_14 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_14_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_14_iomg_se_14_START (0)
#define SOC_IOC_AO_IOMG_SE_14_iomg_se_14_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_15 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_15_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_15_iomg_se_15_START (0)
#define SOC_IOC_AO_IOMG_SE_15_iomg_se_15_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_9 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_9_UNION;
#endif
#define SOC_IOC_AO_IOMG_9_iomg_9_START (0)
#define SOC_IOC_AO_IOMG_9_iomg_9_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_17 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_17_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_17_iomg_se_17_START (0)
#define SOC_IOC_AO_IOMG_SE_17_iomg_se_17_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_18 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_18_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_18_iomg_se_18_START (0)
#define SOC_IOC_AO_IOMG_SE_18_iomg_se_18_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_19 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_19_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_19_iomg_se_19_START (0)
#define SOC_IOC_AO_IOMG_SE_19_iomg_se_19_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_20 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_20_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_20_iomg_se_20_START (0)
#define SOC_IOC_AO_IOMG_SE_20_iomg_se_20_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_21 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_21_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_21_iomg_se_21_START (0)
#define SOC_IOC_AO_IOMG_SE_21_iomg_se_21_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_22 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_22_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_22_iomg_se_22_START (0)
#define SOC_IOC_AO_IOMG_SE_22_iomg_se_22_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_23 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_23_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_23_iomg_se_23_START (0)
#define SOC_IOC_AO_IOMG_SE_23_iomg_se_23_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_24 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_24_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_24_iomg_se_24_START (0)
#define SOC_IOC_AO_IOMG_SE_24_iomg_se_24_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_25 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_25_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_25_iomg_se_25_START (0)
#define SOC_IOC_AO_IOMG_SE_25_iomg_se_25_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_10 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_10_UNION;
#endif
#define SOC_IOC_AO_IOMG_10_iomg_10_START (0)
#define SOC_IOC_AO_IOMG_10_iomg_10_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_11 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_11_UNION;
#endif
#define SOC_IOC_AO_IOMG_11_iomg_11_START (0)
#define SOC_IOC_AO_IOMG_11_iomg_11_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_12 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_12_UNION;
#endif
#define SOC_IOC_AO_IOMG_12_iomg_12_START (0)
#define SOC_IOC_AO_IOMG_12_iomg_12_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_13 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_13_UNION;
#endif
#define SOC_IOC_AO_IOMG_13_iomg_13_START (0)
#define SOC_IOC_AO_IOMG_13_iomg_13_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_26 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_26_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_26_iomg_se_26_START (0)
#define SOC_IOC_AO_IOMG_SE_26_iomg_se_26_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_27 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_27_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_27_iomg_se_27_START (0)
#define SOC_IOC_AO_IOMG_SE_27_iomg_se_27_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_28 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_28_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_28_iomg_se_28_START (0)
#define SOC_IOC_AO_IOMG_SE_28_iomg_se_28_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_29 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_29_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_29_iomg_se_29_START (0)
#define SOC_IOC_AO_IOMG_SE_29_iomg_se_29_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_30 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_30_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_30_iomg_se_30_START (0)
#define SOC_IOC_AO_IOMG_SE_30_iomg_se_30_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_31 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_31_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_31_iomg_se_31_START (0)
#define SOC_IOC_AO_IOMG_SE_31_iomg_se_31_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_32 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_32_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_32_iomg_se_32_START (0)
#define SOC_IOC_AO_IOMG_SE_32_iomg_se_32_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_33 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_33_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_33_iomg_se_33_START (0)
#define SOC_IOC_AO_IOMG_SE_33_iomg_se_33_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_34 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_34_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_34_iomg_se_34_START (0)
#define SOC_IOC_AO_IOMG_SE_34_iomg_se_34_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_35 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_35_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_35_iomg_se_35_START (0)
#define SOC_IOC_AO_IOMG_SE_35_iomg_se_35_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_36 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_36_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_36_iomg_se_36_START (0)
#define SOC_IOC_AO_IOMG_SE_36_iomg_se_36_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_37 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_37_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_37_iomg_se_37_START (0)
#define SOC_IOC_AO_IOMG_SE_37_iomg_se_37_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_38 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_38_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_38_iomg_se_38_START (0)
#define SOC_IOC_AO_IOMG_SE_38_iomg_se_38_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_39 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_39_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_39_iomg_se_39_START (0)
#define SOC_IOC_AO_IOMG_SE_39_iomg_se_39_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_17 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_17_UNION;
#endif
#define SOC_IOC_AO_IOMG_17_iomg_17_START (0)
#define SOC_IOC_AO_IOMG_17_iomg_17_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_18 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_18_UNION;
#endif
#define SOC_IOC_AO_IOMG_18_iomg_18_START (0)
#define SOC_IOC_AO_IOMG_18_iomg_18_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_19 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_19_UNION;
#endif
#define SOC_IOC_AO_IOMG_19_iomg_19_START (0)
#define SOC_IOC_AO_IOMG_19_iomg_19_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_20 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_20_UNION;
#endif
#define SOC_IOC_AO_IOMG_20_iomg_20_START (0)
#define SOC_IOC_AO_IOMG_20_iomg_20_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_21 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_21_UNION;
#endif
#define SOC_IOC_AO_IOMG_21_iomg_21_START (0)
#define SOC_IOC_AO_IOMG_21_iomg_21_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_40 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_40_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_40_iomg_se_40_START (0)
#define SOC_IOC_AO_IOMG_SE_40_iomg_se_40_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_22 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_22_UNION;
#endif
#define SOC_IOC_AO_IOMG_22_iomg_22_START (0)
#define SOC_IOC_AO_IOMG_22_iomg_22_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_23 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_23_UNION;
#endif
#define SOC_IOC_AO_IOMG_23_iomg_23_START (0)
#define SOC_IOC_AO_IOMG_23_iomg_23_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_24 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_24_UNION;
#endif
#define SOC_IOC_AO_IOMG_24_iomg_24_START (0)
#define SOC_IOC_AO_IOMG_24_iomg_24_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_25 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_25_UNION;
#endif
#define SOC_IOC_AO_IOMG_25_iomg_25_START (0)
#define SOC_IOC_AO_IOMG_25_iomg_25_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_26 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_26_UNION;
#endif
#define SOC_IOC_AO_IOMG_26_iomg_26_START (0)
#define SOC_IOC_AO_IOMG_26_iomg_26_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_41 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_41_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_41_iomg_se_41_START (0)
#define SOC_IOC_AO_IOMG_SE_41_iomg_se_41_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_42 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_42_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_42_iomg_se_42_START (0)
#define SOC_IOC_AO_IOMG_SE_42_iomg_se_42_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_43 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_43_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_43_iomg_se_43_START (0)
#define SOC_IOC_AO_IOMG_SE_43_iomg_se_43_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_44 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_44_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_44_iomg_se_44_START (0)
#define SOC_IOC_AO_IOMG_SE_44_iomg_se_44_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_45 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_45_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_45_iomg_se_45_START (0)
#define SOC_IOC_AO_IOMG_SE_45_iomg_se_45_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_46 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_46_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_46_iomg_se_46_START (0)
#define SOC_IOC_AO_IOMG_SE_46_iomg_se_46_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_47 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_47_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_47_iomg_se_47_START (0)
#define SOC_IOC_AO_IOMG_SE_47_iomg_se_47_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_48 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_48_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_48_iomg_se_48_START (0)
#define SOC_IOC_AO_IOMG_SE_48_iomg_se_48_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_49 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_49_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_49_iomg_se_49_START (0)
#define SOC_IOC_AO_IOMG_SE_49_iomg_se_49_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_50 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_50_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_50_iomg_se_50_START (0)
#define SOC_IOC_AO_IOMG_SE_50_iomg_se_50_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_51 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_51_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_51_iomg_se_51_START (0)
#define SOC_IOC_AO_IOMG_SE_51_iomg_se_51_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_52 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_52_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_52_iomg_se_52_START (0)
#define SOC_IOC_AO_IOMG_SE_52_iomg_se_52_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_53 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_53_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_53_iomg_se_53_START (0)
#define SOC_IOC_AO_IOMG_SE_53_iomg_se_53_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_54 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_54_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_54_iomg_se_54_START (0)
#define SOC_IOC_AO_IOMG_SE_54_iomg_se_54_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_28 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_28_UNION;
#endif
#define SOC_IOC_AO_IOMG_28_iomg_28_START (0)
#define SOC_IOC_AO_IOMG_28_iomg_28_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_55 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_55_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_55_iomg_se_55_START (0)
#define SOC_IOC_AO_IOMG_SE_55_iomg_se_55_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_29 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_29_UNION;
#endif
#define SOC_IOC_AO_IOMG_29_iomg_29_START (0)
#define SOC_IOC_AO_IOMG_29_iomg_29_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_30 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_30_UNION;
#endif
#define SOC_IOC_AO_IOMG_30_iomg_30_START (0)
#define SOC_IOC_AO_IOMG_30_iomg_30_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_56 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_56_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_56_iomg_se_56_START (0)
#define SOC_IOC_AO_IOMG_SE_56_iomg_se_56_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_57 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_57_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_57_iomg_se_57_START (0)
#define SOC_IOC_AO_IOMG_SE_57_iomg_se_57_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_58 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_58_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_58_iomg_se_58_START (0)
#define SOC_IOC_AO_IOMG_SE_58_iomg_se_58_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_59 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_59_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_59_iomg_se_59_START (0)
#define SOC_IOC_AO_IOMG_SE_59_iomg_se_59_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_31 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_31_UNION;
#endif
#define SOC_IOC_AO_IOMG_31_iomg_31_START (0)
#define SOC_IOC_AO_IOMG_31_iomg_31_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_32 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_32_UNION;
#endif
#define SOC_IOC_AO_IOMG_32_iomg_32_START (0)
#define SOC_IOC_AO_IOMG_32_iomg_32_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_33 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_33_UNION;
#endif
#define SOC_IOC_AO_IOMG_33_iomg_33_START (0)
#define SOC_IOC_AO_IOMG_33_iomg_33_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_34 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_34_UNION;
#endif
#define SOC_IOC_AO_IOMG_34_iomg_34_START (0)
#define SOC_IOC_AO_IOMG_34_iomg_34_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_60 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_60_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_60_iomg_se_60_START (0)
#define SOC_IOC_AO_IOMG_SE_60_iomg_se_60_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_61 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_61_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_61_iomg_se_61_START (0)
#define SOC_IOC_AO_IOMG_SE_61_iomg_se_61_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_62 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_62_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_62_iomg_se_62_START (0)
#define SOC_IOC_AO_IOMG_SE_62_iomg_se_62_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_63 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_63_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_63_iomg_se_63_START (0)
#define SOC_IOC_AO_IOMG_SE_63_iomg_se_63_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_64 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_64_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_64_iomg_se_64_START (0)
#define SOC_IOC_AO_IOMG_SE_64_iomg_se_64_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_35 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_35_UNION;
#endif
#define SOC_IOC_AO_IOMG_35_iomg_35_START (0)
#define SOC_IOC_AO_IOMG_35_iomg_35_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_36 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_36_UNION;
#endif
#define SOC_IOC_AO_IOMG_36_iomg_36_START (0)
#define SOC_IOC_AO_IOMG_36_iomg_36_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_37 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_37_UNION;
#endif
#define SOC_IOC_AO_IOMG_37_iomg_37_START (0)
#define SOC_IOC_AO_IOMG_37_iomg_37_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_38 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_38_UNION;
#endif
#define SOC_IOC_AO_IOMG_38_iomg_38_START (0)
#define SOC_IOC_AO_IOMG_38_iomg_38_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_39 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_39_UNION;
#endif
#define SOC_IOC_AO_IOMG_39_iomg_39_START (0)
#define SOC_IOC_AO_IOMG_39_iomg_39_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_40 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_40_UNION;
#endif
#define SOC_IOC_AO_IOMG_40_iomg_40_START (0)
#define SOC_IOC_AO_IOMG_40_iomg_40_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_41 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_41_UNION;
#endif
#define SOC_IOC_AO_IOMG_41_iomg_41_START (0)
#define SOC_IOC_AO_IOMG_41_iomg_41_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_65 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_65_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_65_iomg_se_65_START (0)
#define SOC_IOC_AO_IOMG_SE_65_iomg_se_65_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_66 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_66_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_66_iomg_se_66_START (0)
#define SOC_IOC_AO_IOMG_SE_66_iomg_se_66_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_67 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_67_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_67_iomg_se_67_START (0)
#define SOC_IOC_AO_IOMG_SE_67_iomg_se_67_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_68 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_68_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_68_iomg_se_68_START (0)
#define SOC_IOC_AO_IOMG_SE_68_iomg_se_68_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_69 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_69_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_69_iomg_se_69_START (0)
#define SOC_IOC_AO_IOMG_SE_69_iomg_se_69_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_42 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_42_UNION;
#endif
#define SOC_IOC_AO_IOMG_42_iomg_42_START (0)
#define SOC_IOC_AO_IOMG_42_iomg_42_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
