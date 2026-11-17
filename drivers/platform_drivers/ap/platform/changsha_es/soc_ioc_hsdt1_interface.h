#ifndef __SOC_IOC_HSDT1_INTERFACE_H__
#define __SOC_IOC_HSDT1_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_HSDT1_IOCG_0_ADDR(base) ((base) + 0x800UL)
#define SOC_IOC_HSDT1_IOCG_1_ADDR(base) ((base) + 0x804UL)
#define SOC_IOC_HSDT1_IOCG_2_ADDR(base) ((base) + 0x808UL)
#define SOC_IOC_HSDT1_IOCG_SE_0_ADDR(base) ((base) + 0xe00UL)
#define SOC_IOC_HSDT1_IOCG_SE_1_ADDR(base) ((base) + 0xe04UL)
#define SOC_IOC_HSDT1_IOCG_3_ADDR(base) ((base) + 0x80cUL)
#define SOC_IOC_HSDT1_IOCG_4_ADDR(base) ((base) + 0x810UL)
#define SOC_IOC_HSDT1_IOCG_5_ADDR(base) ((base) + 0x814UL)
#define SOC_IOC_HSDT1_IOCG_6_ADDR(base) ((base) + 0x818UL)
#define SOC_IOC_HSDT1_IOCG_7_ADDR(base) ((base) + 0x81cUL)
#define SOC_IOC_HSDT1_IOCG_8_ADDR(base) ((base) + 0x820UL)
#define SOC_IOC_HSDT1_IOCG_9_ADDR(base) ((base) + 0x824UL)
#define SOC_IOC_HSDT1_IOCG_SE_2_ADDR(base) ((base) + 0xe08UL)
#define SOC_IOC_HSDT1_IOCG_10_ADDR(base) ((base) + 0x828UL)
#define SOC_IOC_HSDT1_IOCG_11_ADDR(base) ((base) + 0x82cUL)
#define SOC_IOC_HSDT1_IOCG_12_ADDR(base) ((base) + 0x830UL)
#define SOC_IOC_HSDT1_IOCG_13_ADDR(base) ((base) + 0x834UL)
#define SOC_IOC_HSDT1_IOCG_14_ADDR(base) ((base) + 0x838UL)
#define SOC_IOC_HSDT1_IOCG_15_ADDR(base) ((base) + 0x83cUL)
#define SOC_IOC_HSDT1_IOCG_16_ADDR(base) ((base) + 0x840UL)
#define SOC_IOC_HSDT1_IOCG_17_ADDR(base) ((base) + 0x844UL)
#define SOC_IOC_HSDT1_IOCG_SE_3_ADDR(base) ((base) + 0xe0cUL)
#define SOC_IOC_HSDT1_IOCG_SE_4_ADDR(base) ((base) + 0xe10UL)
#define SOC_IOC_HSDT1_IOCG_SE_5_ADDR(base) ((base) + 0xe14UL)
#define SOC_IOC_HSDT1_IOCG_SE_6_ADDR(base) ((base) + 0xe18UL)
#define SOC_IOC_HSDT1_IOCG_18_ADDR(base) ((base) + 0x848UL)
#define SOC_IOC_HSDT1_IOCG_19_ADDR(base) ((base) + 0x84cUL)
#define SOC_IOC_HSDT1_IOCG_20_ADDR(base) ((base) + 0x850UL)
#define SOC_IOC_HSDT1_IOCG_21_ADDR(base) ((base) + 0x854UL)
#define SOC_IOC_HSDT1_IOCG_22_ADDR(base) ((base) + 0x858UL)
#define SOC_IOC_HSDT1_IOCG_23_ADDR(base) ((base) + 0x85cUL)
#define SOC_IOC_HSDT1_IOCG_24_ADDR(base) ((base) + 0x860UL)
#define SOC_IOC_HSDT1_IOCG_25_ADDR(base) ((base) + 0x864UL)
#define SOC_IOC_HSDT1_IOCG_26_ADDR(base) ((base) + 0x868UL)
#define SOC_IOC_HSDT1_IOCG_27_ADDR(base) ((base) + 0x86cUL)
#define SOC_IOC_HSDT1_IOCG_28_ADDR(base) ((base) + 0x870UL)
#define SOC_IOC_HSDT1_IOCG_29_ADDR(base) ((base) + 0x874UL)
#define SOC_IOC_HSDT1_IOCG_30_ADDR(base) ((base) + 0x878UL)
#define SOC_IOC_HSDT1_IOCG_31_ADDR(base) ((base) + 0x87cUL)
#define SOC_IOC_HSDT1_IOCG_SE_7_ADDR(base) ((base) + 0xe1cUL)
#define SOC_IOC_HSDT1_IOCG_SE_8_ADDR(base) ((base) + 0xe20UL)
#define SOC_IOC_HSDT1_IOCG_SE_9_ADDR(base) ((base) + 0xe24UL)
#define SOC_IOC_HSDT1_IOCG_SE_10_ADDR(base) ((base) + 0xe28UL)
#define SOC_IOC_HSDT1_IOCG_SE_11_ADDR(base) ((base) + 0xe2cUL)
#define SOC_IOC_HSDT1_IOCG_SE_12_ADDR(base) ((base) + 0xe30UL)
#define SOC_IOC_HSDT1_IOCG_SE_13_ADDR(base) ((base) + 0xe34UL)
#define SOC_IOC_HSDT1_IOCG_32_ADDR(base) ((base) + 0x880UL)
#define SOC_IOC_HSDT1_IOCG_33_ADDR(base) ((base) + 0x884UL)
#define SOC_IOC_HSDT1_IOCG_34_ADDR(base) ((base) + 0x888UL)
#else
#define SOC_IOC_HSDT1_IOCG_0_ADDR(base) ((base) + 0x800)
#define SOC_IOC_HSDT1_IOCG_1_ADDR(base) ((base) + 0x804)
#define SOC_IOC_HSDT1_IOCG_2_ADDR(base) ((base) + 0x808)
#define SOC_IOC_HSDT1_IOCG_SE_0_ADDR(base) ((base) + 0xe00)
#define SOC_IOC_HSDT1_IOCG_SE_1_ADDR(base) ((base) + 0xe04)
#define SOC_IOC_HSDT1_IOCG_3_ADDR(base) ((base) + 0x80c)
#define SOC_IOC_HSDT1_IOCG_4_ADDR(base) ((base) + 0x810)
#define SOC_IOC_HSDT1_IOCG_5_ADDR(base) ((base) + 0x814)
#define SOC_IOC_HSDT1_IOCG_6_ADDR(base) ((base) + 0x818)
#define SOC_IOC_HSDT1_IOCG_7_ADDR(base) ((base) + 0x81c)
#define SOC_IOC_HSDT1_IOCG_8_ADDR(base) ((base) + 0x820)
#define SOC_IOC_HSDT1_IOCG_9_ADDR(base) ((base) + 0x824)
#define SOC_IOC_HSDT1_IOCG_SE_2_ADDR(base) ((base) + 0xe08)
#define SOC_IOC_HSDT1_IOCG_10_ADDR(base) ((base) + 0x828)
#define SOC_IOC_HSDT1_IOCG_11_ADDR(base) ((base) + 0x82c)
#define SOC_IOC_HSDT1_IOCG_12_ADDR(base) ((base) + 0x830)
#define SOC_IOC_HSDT1_IOCG_13_ADDR(base) ((base) + 0x834)
#define SOC_IOC_HSDT1_IOCG_14_ADDR(base) ((base) + 0x838)
#define SOC_IOC_HSDT1_IOCG_15_ADDR(base) ((base) + 0x83c)
#define SOC_IOC_HSDT1_IOCG_16_ADDR(base) ((base) + 0x840)
#define SOC_IOC_HSDT1_IOCG_17_ADDR(base) ((base) + 0x844)
#define SOC_IOC_HSDT1_IOCG_SE_3_ADDR(base) ((base) + 0xe0c)
#define SOC_IOC_HSDT1_IOCG_SE_4_ADDR(base) ((base) + 0xe10)
#define SOC_IOC_HSDT1_IOCG_SE_5_ADDR(base) ((base) + 0xe14)
#define SOC_IOC_HSDT1_IOCG_SE_6_ADDR(base) ((base) + 0xe18)
#define SOC_IOC_HSDT1_IOCG_18_ADDR(base) ((base) + 0x848)
#define SOC_IOC_HSDT1_IOCG_19_ADDR(base) ((base) + 0x84c)
#define SOC_IOC_HSDT1_IOCG_20_ADDR(base) ((base) + 0x850)
#define SOC_IOC_HSDT1_IOCG_21_ADDR(base) ((base) + 0x854)
#define SOC_IOC_HSDT1_IOCG_22_ADDR(base) ((base) + 0x858)
#define SOC_IOC_HSDT1_IOCG_23_ADDR(base) ((base) + 0x85c)
#define SOC_IOC_HSDT1_IOCG_24_ADDR(base) ((base) + 0x860)
#define SOC_IOC_HSDT1_IOCG_25_ADDR(base) ((base) + 0x864)
#define SOC_IOC_HSDT1_IOCG_26_ADDR(base) ((base) + 0x868)
#define SOC_IOC_HSDT1_IOCG_27_ADDR(base) ((base) + 0x86c)
#define SOC_IOC_HSDT1_IOCG_28_ADDR(base) ((base) + 0x870)
#define SOC_IOC_HSDT1_IOCG_29_ADDR(base) ((base) + 0x874)
#define SOC_IOC_HSDT1_IOCG_30_ADDR(base) ((base) + 0x878)
#define SOC_IOC_HSDT1_IOCG_31_ADDR(base) ((base) + 0x87c)
#define SOC_IOC_HSDT1_IOCG_SE_7_ADDR(base) ((base) + 0xe1c)
#define SOC_IOC_HSDT1_IOCG_SE_8_ADDR(base) ((base) + 0xe20)
#define SOC_IOC_HSDT1_IOCG_SE_9_ADDR(base) ((base) + 0xe24)
#define SOC_IOC_HSDT1_IOCG_SE_10_ADDR(base) ((base) + 0xe28)
#define SOC_IOC_HSDT1_IOCG_SE_11_ADDR(base) ((base) + 0xe2c)
#define SOC_IOC_HSDT1_IOCG_SE_12_ADDR(base) ((base) + 0xe30)
#define SOC_IOC_HSDT1_IOCG_SE_13_ADDR(base) ((base) + 0xe34)
#define SOC_IOC_HSDT1_IOCG_32_ADDR(base) ((base) + 0x880)
#define SOC_IOC_HSDT1_IOCG_33_ADDR(base) ((base) + 0x884)
#define SOC_IOC_HSDT1_IOCG_34_ADDR(base) ((base) + 0x888)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_HSDT1_IOMG_0_ADDR(base) (base)
#define SOC_IOC_HSDT1_IOMG_1_ADDR(base) ((base) + 0x4UL)
#define SOC_IOC_HSDT1_IOMG_2_ADDR(base) ((base) + 0x8UL)
#define SOC_IOC_HSDT1_IOMG_SE_0_ADDR(base) ((base) + 0x600UL)
#define SOC_IOC_HSDT1_IOMG_SE_1_ADDR(base) ((base) + 0x604UL)
#define SOC_IOC_HSDT1_IOMG_4_ADDR(base) ((base) + 0x10UL)
#define SOC_IOC_HSDT1_IOMG_5_ADDR(base) ((base) + 0x14UL)
#define SOC_IOC_HSDT1_IOMG_6_ADDR(base) ((base) + 0x18UL)
#define SOC_IOC_HSDT1_IOMG_7_ADDR(base) ((base) + 0x1cUL)
#define SOC_IOC_HSDT1_IOMG_8_ADDR(base) ((base) + 0x20UL)
#define SOC_IOC_HSDT1_IOMG_9_ADDR(base) ((base) + 0x24UL)
#define SOC_IOC_HSDT1_IOMG_SE_2_ADDR(base) ((base) + 0x608UL)
#define SOC_IOC_HSDT1_IOMG_10_ADDR(base) ((base) + 0x28UL)
#define SOC_IOC_HSDT1_IOMG_11_ADDR(base) ((base) + 0x2cUL)
#define SOC_IOC_HSDT1_IOMG_12_ADDR(base) ((base) + 0x30UL)
#define SOC_IOC_HSDT1_IOMG_13_ADDR(base) ((base) + 0x34UL)
#define SOC_IOC_HSDT1_IOMG_14_ADDR(base) ((base) + 0x38UL)
#define SOC_IOC_HSDT1_IOMG_15_ADDR(base) ((base) + 0x3cUL)
#define SOC_IOC_HSDT1_IOMG_16_ADDR(base) ((base) + 0x40UL)
#define SOC_IOC_HSDT1_IOMG_17_ADDR(base) ((base) + 0x44UL)
#define SOC_IOC_HSDT1_IOMG_SE_3_ADDR(base) ((base) + 0x60cUL)
#define SOC_IOC_HSDT1_IOMG_SE_4_ADDR(base) ((base) + 0x610UL)
#define SOC_IOC_HSDT1_IOMG_SE_5_ADDR(base) ((base) + 0x614UL)
#define SOC_IOC_HSDT1_IOMG_SE_6_ADDR(base) ((base) + 0x618UL)
#define SOC_IOC_HSDT1_IOMG_18_ADDR(base) ((base) + 0x48UL)
#define SOC_IOC_HSDT1_IOMG_19_ADDR(base) ((base) + 0x4cUL)
#define SOC_IOC_HSDT1_IOMG_20_ADDR(base) ((base) + 0x50UL)
#define SOC_IOC_HSDT1_IOMG_21_ADDR(base) ((base) + 0x54UL)
#define SOC_IOC_HSDT1_IOMG_24_ADDR(base) ((base) + 0x60UL)
#define SOC_IOC_HSDT1_IOMG_25_ADDR(base) ((base) + 0x64UL)
#define SOC_IOC_HSDT1_IOMG_26_ADDR(base) ((base) + 0x68UL)
#define SOC_IOC_HSDT1_IOMG_27_ADDR(base) ((base) + 0x6cUL)
#define SOC_IOC_HSDT1_IOMG_28_ADDR(base) ((base) + 0x70UL)
#define SOC_IOC_HSDT1_IOMG_29_ADDR(base) ((base) + 0x74UL)
#define SOC_IOC_HSDT1_IOMG_30_ADDR(base) ((base) + 0x78UL)
#define SOC_IOC_HSDT1_IOMG_31_ADDR(base) ((base) + 0x7cUL)
#define SOC_IOC_HSDT1_IOMG_SE_7_ADDR(base) ((base) + 0x61cUL)
#define SOC_IOC_HSDT1_IOMG_SE_8_ADDR(base) ((base) + 0x620UL)
#define SOC_IOC_HSDT1_IOMG_SE_9_ADDR(base) ((base) + 0x624UL)
#define SOC_IOC_HSDT1_IOMG_SE_10_ADDR(base) ((base) + 0x628UL)
#define SOC_IOC_HSDT1_IOMG_SE_11_ADDR(base) ((base) + 0x62cUL)
#define SOC_IOC_HSDT1_IOMG_SE_12_ADDR(base) ((base) + 0x630UL)
#define SOC_IOC_HSDT1_IOMG_SE_13_ADDR(base) ((base) + 0x634UL)
#define SOC_IOC_HSDT1_IOMG_32_ADDR(base) ((base) + 0x80UL)
#define SOC_IOC_HSDT1_IOMG_33_ADDR(base) ((base) + 0x84UL)
#define SOC_IOC_HSDT1_IOMG_34_ADDR(base) ((base) + 0x88UL)
#else
#define SOC_IOC_HSDT1_IOMG_0_ADDR(base) (base)
#define SOC_IOC_HSDT1_IOMG_1_ADDR(base) ((base) + 0x4)
#define SOC_IOC_HSDT1_IOMG_2_ADDR(base) ((base) + 0x8)
#define SOC_IOC_HSDT1_IOMG_SE_0_ADDR(base) ((base) + 0x600)
#define SOC_IOC_HSDT1_IOMG_SE_1_ADDR(base) ((base) + 0x604)
#define SOC_IOC_HSDT1_IOMG_4_ADDR(base) ((base) + 0x10)
#define SOC_IOC_HSDT1_IOMG_5_ADDR(base) ((base) + 0x14)
#define SOC_IOC_HSDT1_IOMG_6_ADDR(base) ((base) + 0x18)
#define SOC_IOC_HSDT1_IOMG_7_ADDR(base) ((base) + 0x1c)
#define SOC_IOC_HSDT1_IOMG_8_ADDR(base) ((base) + 0x20)
#define SOC_IOC_HSDT1_IOMG_9_ADDR(base) ((base) + 0x24)
#define SOC_IOC_HSDT1_IOMG_SE_2_ADDR(base) ((base) + 0x608)
#define SOC_IOC_HSDT1_IOMG_10_ADDR(base) ((base) + 0x28)
#define SOC_IOC_HSDT1_IOMG_11_ADDR(base) ((base) + 0x2c)
#define SOC_IOC_HSDT1_IOMG_12_ADDR(base) ((base) + 0x30)
#define SOC_IOC_HSDT1_IOMG_13_ADDR(base) ((base) + 0x34)
#define SOC_IOC_HSDT1_IOMG_14_ADDR(base) ((base) + 0x38)
#define SOC_IOC_HSDT1_IOMG_15_ADDR(base) ((base) + 0x3c)
#define SOC_IOC_HSDT1_IOMG_16_ADDR(base) ((base) + 0x40)
#define SOC_IOC_HSDT1_IOMG_17_ADDR(base) ((base) + 0x44)
#define SOC_IOC_HSDT1_IOMG_SE_3_ADDR(base) ((base) + 0x60c)
#define SOC_IOC_HSDT1_IOMG_SE_4_ADDR(base) ((base) + 0x610)
#define SOC_IOC_HSDT1_IOMG_SE_5_ADDR(base) ((base) + 0x614)
#define SOC_IOC_HSDT1_IOMG_SE_6_ADDR(base) ((base) + 0x618)
#define SOC_IOC_HSDT1_IOMG_18_ADDR(base) ((base) + 0x48)
#define SOC_IOC_HSDT1_IOMG_19_ADDR(base) ((base) + 0x4c)
#define SOC_IOC_HSDT1_IOMG_20_ADDR(base) ((base) + 0x50)
#define SOC_IOC_HSDT1_IOMG_21_ADDR(base) ((base) + 0x54)
#define SOC_IOC_HSDT1_IOMG_24_ADDR(base) ((base) + 0x60)
#define SOC_IOC_HSDT1_IOMG_25_ADDR(base) ((base) + 0x64)
#define SOC_IOC_HSDT1_IOMG_26_ADDR(base) ((base) + 0x68)
#define SOC_IOC_HSDT1_IOMG_27_ADDR(base) ((base) + 0x6c)
#define SOC_IOC_HSDT1_IOMG_28_ADDR(base) ((base) + 0x70)
#define SOC_IOC_HSDT1_IOMG_29_ADDR(base) ((base) + 0x74)
#define SOC_IOC_HSDT1_IOMG_30_ADDR(base) ((base) + 0x78)
#define SOC_IOC_HSDT1_IOMG_31_ADDR(base) ((base) + 0x7c)
#define SOC_IOC_HSDT1_IOMG_SE_7_ADDR(base) ((base) + 0x61c)
#define SOC_IOC_HSDT1_IOMG_SE_8_ADDR(base) ((base) + 0x620)
#define SOC_IOC_HSDT1_IOMG_SE_9_ADDR(base) ((base) + 0x624)
#define SOC_IOC_HSDT1_IOMG_SE_10_ADDR(base) ((base) + 0x628)
#define SOC_IOC_HSDT1_IOMG_SE_11_ADDR(base) ((base) + 0x62c)
#define SOC_IOC_HSDT1_IOMG_SE_12_ADDR(base) ((base) + 0x630)
#define SOC_IOC_HSDT1_IOMG_SE_13_ADDR(base) ((base) + 0x634)
#define SOC_IOC_HSDT1_IOMG_32_ADDR(base) ((base) + 0x80)
#define SOC_IOC_HSDT1_IOMG_33_ADDR(base) ((base) + 0x84)
#define SOC_IOC_HSDT1_IOMG_34_ADDR(base) ((base) + 0x88)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_0_pu : 1;
        unsigned int iocg_0_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_0_st : 1;
        unsigned int iocg_0_ds0 : 1;
        unsigned int iocg_0_ds1 : 1;
        unsigned int iocg_0_ds2 : 1;
        unsigned int iocg_0_ds3 : 1;
        unsigned int iocg_0_sl : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_0_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_st_START (3)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_st_END (3)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds3_START (7)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_ds3_END (7)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_0_iocg_0_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_1_pu : 1;
        unsigned int iocg_1_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_1_st : 1;
        unsigned int iocg_1_ds0 : 1;
        unsigned int iocg_1_ds1 : 1;
        unsigned int iocg_1_ds2 : 1;
        unsigned int iocg_1_ds3 : 1;
        unsigned int iocg_1_sl : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_1_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_st_START (3)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_st_END (3)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds3_START (7)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_ds3_END (7)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_1_iocg_1_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_2_pu : 1;
        unsigned int iocg_2_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_2_st : 1;
        unsigned int iocg_2_ds0 : 1;
        unsigned int iocg_2_ds1 : 1;
        unsigned int iocg_2_ds2 : 1;
        unsigned int iocg_2_ds3 : 1;
        unsigned int iocg_2_sl : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_2_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_st_START (3)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_st_END (3)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds3_START (7)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_ds3_END (7)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_2_iocg_2_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_0_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_0_iocg_se_0_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_1_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_1_iocg_se_1_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_3_pu : 1;
        unsigned int iocg_3_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_3_st : 1;
        unsigned int iocg_3_ds0 : 1;
        unsigned int iocg_3_ds1 : 1;
        unsigned int iocg_3_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_3_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_3_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_st_START (3)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_st_END (3)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_3_iocg_3_sl_END (8)
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
        unsigned int iocg_4_ds3 : 1;
        unsigned int iocg_4_sl : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_4_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_st_START (3)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_st_END (3)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds3_START (7)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_ds3_END (7)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_4_iocg_4_sl_END (8)
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
        unsigned int iocg_5_ds3 : 1;
        unsigned int iocg_5_sl : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_5_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_st_START (3)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_st_END (3)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds3_START (7)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_ds3_END (7)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_5_iocg_5_sl_END (8)
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
        unsigned int iocg_6_ds3 : 1;
        unsigned int iocg_6_sl : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_6_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_st_START (3)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_st_END (3)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds3_START (7)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_ds3_END (7)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_6_iocg_6_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_7_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_st_START (3)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_st_END (3)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_7_iocg_7_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_8_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_st_START (3)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_st_END (3)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_8_iocg_8_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_9_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_st_START (3)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_st_END (3)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_9_iocg_9_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_2_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_2_iocg_se_2_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_10_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_st_START (3)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_st_END (3)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_10_iocg_10_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_11_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_st_START (3)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_st_END (3)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_11_iocg_11_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_12_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_st_START (3)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_st_END (3)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_12_iocg_12_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_13_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_st_START (3)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_st_END (3)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_13_iocg_13_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_14_pu : 1;
        unsigned int iocg_14_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_14_st : 1;
        unsigned int iocg_14_ds0 : 1;
        unsigned int iocg_14_ds1 : 1;
        unsigned int iocg_14_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_14_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_14_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_st_START (3)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_st_END (3)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_14_iocg_14_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_15_pu : 1;
        unsigned int iocg_15_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_15_st : 1;
        unsigned int iocg_15_ds0 : 1;
        unsigned int iocg_15_ds1 : 1;
        unsigned int iocg_15_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_15_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_15_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_st_START (3)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_st_END (3)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_15_iocg_15_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_16_pu : 1;
        unsigned int iocg_16_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_16_st : 1;
        unsigned int iocg_16_ds0 : 1;
        unsigned int iocg_16_ds1 : 1;
        unsigned int iocg_16_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_16_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT1_IOCG_16_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_st_START (3)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_st_END (3)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_16_iocg_16_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_17_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_st_START (3)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_st_END (3)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_17_iocg_17_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_3_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_3_iocg_se_3_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_4_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_4_iocg_se_4_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_5_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_5_iocg_se_5_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_6_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_6_iocg_se_6_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_18_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_st_START (3)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_st_END (3)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_18_iocg_18_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_19_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_st_START (3)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_st_END (3)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_19_iocg_19_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_20_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_st_START (3)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_st_END (3)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_20_iocg_20_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_21_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_st_START (3)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_st_END (3)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_21_iocg_21_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int iocg_22_st : 1;
        unsigned int reserved_1 : 5;
        unsigned int iocg_22_pe : 1;
        unsigned int iocg_22_ps : 1;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_IOC_HSDT1_IOCG_22_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_22_iocg_22_st_START (3)
#define SOC_IOC_HSDT1_IOCG_22_iocg_22_st_END (3)
#define SOC_IOC_HSDT1_IOCG_22_iocg_22_pe_START (9)
#define SOC_IOC_HSDT1_IOCG_22_iocg_22_pe_END (9)
#define SOC_IOC_HSDT1_IOCG_22_iocg_22_ps_START (10)
#define SOC_IOC_HSDT1_IOCG_22_iocg_22_ps_END (10)
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
} SOC_IOC_HSDT1_IOCG_23_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_st_START (3)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_st_END (3)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_23_iocg_23_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_24_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_st_START (3)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_st_END (3)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_24_iocg_24_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_25_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_st_START (3)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_st_END (3)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_25_iocg_25_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_26_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_st_START (3)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_st_END (3)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_26_iocg_26_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_27_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_st_START (3)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_st_END (3)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_27_iocg_27_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_28_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_st_START (3)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_st_END (3)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_28_iocg_28_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_29_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_st_START (3)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_st_END (3)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_29_iocg_29_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_30_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_st_START (3)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_st_END (3)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_30_iocg_30_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_31_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_st_START (3)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_st_END (3)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_31_iocg_31_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_7_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_7_iocg_se_7_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_8_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_8_iocg_se_8_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_9_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_9_iocg_se_9_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_10_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_10_iocg_se_10_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_11_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_11_iocg_se_11_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_12_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_12_iocg_se_12_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_SE_13_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_st_START (3)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_st_END (3)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_SE_13_iocg_se_13_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_32_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_st_START (3)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_st_END (3)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_32_iocg_32_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_33_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_st_START (3)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_st_END (3)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_33_iocg_33_sl_END (8)
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
} SOC_IOC_HSDT1_IOCG_34_UNION;
#endif
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_pu_START (0)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_pu_END (0)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_pd_START (1)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_pd_END (1)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_st_START (3)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_st_END (3)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_ds0_START (4)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_ds0_END (4)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_ds1_START (5)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_ds1_END (5)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_ds2_START (6)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_ds2_END (6)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_sl_START (8)
#define SOC_IOC_HSDT1_IOCG_34_iocg_34_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_0 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_0_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_0_iomg_0_START (0)
#define SOC_IOC_HSDT1_IOMG_0_iomg_0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_1 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_1_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_1_iomg_1_START (0)
#define SOC_IOC_HSDT1_IOMG_1_iomg_1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_2 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_2_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_2_iomg_2_START (0)
#define SOC_IOC_HSDT1_IOMG_2_iomg_2_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_0_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_0_iomg_se_0_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_0_iomg_se_0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_1_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_1_iomg_se_1_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_1_iomg_se_1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_4 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_4_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_4_iomg_4_START (0)
#define SOC_IOC_HSDT1_IOMG_4_iomg_4_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_5 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_5_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_5_iomg_5_START (0)
#define SOC_IOC_HSDT1_IOMG_5_iomg_5_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_6 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_6_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_6_iomg_6_START (0)
#define SOC_IOC_HSDT1_IOMG_6_iomg_6_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_7 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_7_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_7_iomg_7_START (0)
#define SOC_IOC_HSDT1_IOMG_7_iomg_7_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_8 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_8_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_8_iomg_8_START (0)
#define SOC_IOC_HSDT1_IOMG_8_iomg_8_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_9 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_9_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_9_iomg_9_START (0)
#define SOC_IOC_HSDT1_IOMG_9_iomg_9_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_2 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_2_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_2_iomg_se_2_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_2_iomg_se_2_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_10 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_10_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_10_iomg_10_START (0)
#define SOC_IOC_HSDT1_IOMG_10_iomg_10_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_11 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_11_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_11_iomg_11_START (0)
#define SOC_IOC_HSDT1_IOMG_11_iomg_11_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_12 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_12_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_12_iomg_12_START (0)
#define SOC_IOC_HSDT1_IOMG_12_iomg_12_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_13 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_13_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_13_iomg_13_START (0)
#define SOC_IOC_HSDT1_IOMG_13_iomg_13_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_14 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_14_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_14_iomg_14_START (0)
#define SOC_IOC_HSDT1_IOMG_14_iomg_14_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_15 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_15_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_15_iomg_15_START (0)
#define SOC_IOC_HSDT1_IOMG_15_iomg_15_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_16 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_16_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_16_iomg_16_START (0)
#define SOC_IOC_HSDT1_IOMG_16_iomg_16_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_17 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_17_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_17_iomg_17_START (0)
#define SOC_IOC_HSDT1_IOMG_17_iomg_17_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_3 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_3_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_3_iomg_se_3_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_3_iomg_se_3_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_4 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_4_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_4_iomg_se_4_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_4_iomg_se_4_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_5 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_5_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_5_iomg_se_5_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_5_iomg_se_5_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_6 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_6_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_6_iomg_se_6_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_6_iomg_se_6_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_18 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_18_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_18_iomg_18_START (0)
#define SOC_IOC_HSDT1_IOMG_18_iomg_18_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_19 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_19_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_19_iomg_19_START (0)
#define SOC_IOC_HSDT1_IOMG_19_iomg_19_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_20 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_20_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_20_iomg_20_START (0)
#define SOC_IOC_HSDT1_IOMG_20_iomg_20_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_21 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_21_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_21_iomg_21_START (0)
#define SOC_IOC_HSDT1_IOMG_21_iomg_21_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_24 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_24_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_24_iomg_24_START (0)
#define SOC_IOC_HSDT1_IOMG_24_iomg_24_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_25 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_25_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_25_iomg_25_START (0)
#define SOC_IOC_HSDT1_IOMG_25_iomg_25_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_26 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_26_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_26_iomg_26_START (0)
#define SOC_IOC_HSDT1_IOMG_26_iomg_26_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_27 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_27_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_27_iomg_27_START (0)
#define SOC_IOC_HSDT1_IOMG_27_iomg_27_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_28 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_28_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_28_iomg_28_START (0)
#define SOC_IOC_HSDT1_IOMG_28_iomg_28_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_29 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT1_IOMG_29_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_29_iomg_29_START (0)
#define SOC_IOC_HSDT1_IOMG_29_iomg_29_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_30 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT1_IOMG_30_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_30_iomg_30_START (0)
#define SOC_IOC_HSDT1_IOMG_30_iomg_30_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_31 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT1_IOMG_31_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_31_iomg_31_START (0)
#define SOC_IOC_HSDT1_IOMG_31_iomg_31_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_7 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_7_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_7_iomg_se_7_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_7_iomg_se_7_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_8 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_8_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_8_iomg_se_8_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_8_iomg_se_8_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_9 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_9_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_9_iomg_se_9_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_9_iomg_se_9_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_10 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_10_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_10_iomg_se_10_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_10_iomg_se_10_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_11 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_11_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_11_iomg_se_11_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_11_iomg_se_11_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_12 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_12_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_12_iomg_se_12_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_12_iomg_se_12_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_13 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT1_IOMG_SE_13_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_SE_13_iomg_se_13_START (0)
#define SOC_IOC_HSDT1_IOMG_SE_13_iomg_se_13_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_32 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_32_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_32_iomg_32_START (0)
#define SOC_IOC_HSDT1_IOMG_32_iomg_32_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_33 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_33_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_33_iomg_33_START (0)
#define SOC_IOC_HSDT1_IOMG_33_iomg_33_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_34 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT1_IOMG_34_UNION;
#endif
#define SOC_IOC_HSDT1_IOMG_34_iomg_34_START (0)
#define SOC_IOC_HSDT1_IOMG_34_iomg_34_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
