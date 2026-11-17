#ifndef __SOC_BOOTROM_CPU_INTERFACE_H__
#define __SOC_BOOTROM_CPU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA0_ADDR(base) ((base) + 0x40000UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA1_ADDR(base) ((base) + 0x40004UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA2_ADDR(base) ((base) + 0x40008UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA3_ADDR(base) ((base) + 0x4000CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA4_ADDR(base) ((base) + 0x40010UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA5_ADDR(base) ((base) + 0x40014UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA6_ADDR(base) ((base) + 0x40018UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA7_ADDR(base) ((base) + 0x4001CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA8_ADDR(base) ((base) + 0x40020UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA9_ADDR(base) ((base) + 0x40024UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA10_ADDR(base) ((base) + 0x40028UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA11_ADDR(base) ((base) + 0x4002CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA12_ADDR(base) ((base) + 0x40030UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA13_ADDR(base) ((base) + 0x40034UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA14_ADDR(base) ((base) + 0x40038UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA15_ADDR(base) ((base) + 0x4003CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA16_ADDR(base) ((base) + 0x40040UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA17_ADDR(base) ((base) + 0x40044UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA18_ADDR(base) ((base) + 0x40048UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA19_ADDR(base) ((base) + 0x4004CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA20_ADDR(base) ((base) + 0x40050UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA21_ADDR(base) ((base) + 0x40054UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA22_ADDR(base) ((base) + 0x40058UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA23_ADDR(base) ((base) + 0x4005CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA24_ADDR(base) ((base) + 0x40060UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA25_ADDR(base) ((base) + 0x40064UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA26_ADDR(base) ((base) + 0x40068UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA27_ADDR(base) ((base) + 0x4006CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA28_ADDR(base) ((base) + 0x40070UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA29_ADDR(base) ((base) + 0x40074UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA30_ADDR(base) ((base) + 0x40078UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA31_ADDR(base) ((base) + 0x4007CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA32_ADDR(base) ((base) + 0x40080UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA33_ADDR(base) ((base) + 0x40084UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA34_ADDR(base) ((base) + 0x40088UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA35_ADDR(base) ((base) + 0x4008CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA36_ADDR(base) ((base) + 0x40090UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA37_ADDR(base) ((base) + 0x40094UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA38_ADDR(base) ((base) + 0x40098UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA39_ADDR(base) ((base) + 0x4009CUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA40_ADDR(base) ((base) + 0x400A0UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA41_ADDR(base) ((base) + 0x400A4UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA42_ADDR(base) ((base) + 0x400A8UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA43_ADDR(base) ((base) + 0x400ACUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA44_ADDR(base) ((base) + 0x400B0UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA45_ADDR(base) ((base) + 0x400B4UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA46_ADDR(base) ((base) + 0x400B8UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA47_ADDR(base) ((base) + 0x400BCUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA48_ADDR(base) ((base) + 0x400C0UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA49_ADDR(base) ((base) + 0x400C4UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA50_ADDR(base) ((base) + 0x400C8UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA51_ADDR(base) ((base) + 0x400CCUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA52_ADDR(base) ((base) + 0x400D0UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA53_ADDR(base) ((base) + 0x400D4UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA54_ADDR(base) ((base) + 0x400D8UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA55_ADDR(base) ((base) + 0x400DCUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA56_ADDR(base) ((base) + 0x400E0UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA57_ADDR(base) ((base) + 0x400E4UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA58_ADDR(base) ((base) + 0x400E8UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA59_ADDR(base) ((base) + 0x400ECUL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA60_ADDR(base) ((base) + 0x400F0UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA61_ADDR(base) ((base) + 0x400F4UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA62_ADDR(base) ((base) + 0x400F8UL)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA63_ADDR(base) ((base) + 0x400FCUL)
#define SOC_BOOTROM_CPU_PATCHADDR0_ADDR(base) ((base) + 0x40100UL)
#define SOC_BOOTROM_CPU_PATCHADDR1_ADDR(base) ((base) + 0x40104UL)
#define SOC_BOOTROM_CPU_PATCHADDR2_ADDR(base) ((base) + 0x40108UL)
#define SOC_BOOTROM_CPU_PATCHADDR3_ADDR(base) ((base) + 0x4010CUL)
#define SOC_BOOTROM_CPU_PATCHADDR4_ADDR(base) ((base) + 0x40110UL)
#define SOC_BOOTROM_CPU_PATCHADDR5_ADDR(base) ((base) + 0x40114UL)
#define SOC_BOOTROM_CPU_PATCHADDR6_ADDR(base) ((base) + 0x40118UL)
#define SOC_BOOTROM_CPU_PATCHADDR7_ADDR(base) ((base) + 0x4011CUL)
#define SOC_BOOTROM_CPU_PATCHADDR8_ADDR(base) ((base) + 0x40120UL)
#define SOC_BOOTROM_CPU_PATCHADDR9_ADDR(base) ((base) + 0x40124UL)
#define SOC_BOOTROM_CPU_PATCHADDR10_ADDR(base) ((base) + 0x40128UL)
#define SOC_BOOTROM_CPU_PATCHADDR11_ADDR(base) ((base) + 0x4012CUL)
#define SOC_BOOTROM_CPU_PATCHADDR12_ADDR(base) ((base) + 0x40130UL)
#define SOC_BOOTROM_CPU_PATCHADDR13_ADDR(base) ((base) + 0x40134UL)
#define SOC_BOOTROM_CPU_PATCHADDR14_ADDR(base) ((base) + 0x40138UL)
#define SOC_BOOTROM_CPU_PATCHADDR15_ADDR(base) ((base) + 0x4013CUL)
#define SOC_BOOTROM_CPU_PATCHDATA0_ADDR(base) ((base) + 0x40140UL)
#define SOC_BOOTROM_CPU_PATCHDATA1_ADDR(base) ((base) + 0x40144UL)
#define SOC_BOOTROM_CPU_PATCHDATA2_ADDR(base) ((base) + 0x40148UL)
#define SOC_BOOTROM_CPU_PATCHDATA3_ADDR(base) ((base) + 0x4014CUL)
#define SOC_BOOTROM_CPU_PATCHDATA4_ADDR(base) ((base) + 0x40150UL)
#define SOC_BOOTROM_CPU_PATCHDATA5_ADDR(base) ((base) + 0x40154UL)
#define SOC_BOOTROM_CPU_PATCHDATA6_ADDR(base) ((base) + 0x40158UL)
#define SOC_BOOTROM_CPU_PATCHDATA7_ADDR(base) ((base) + 0x4015CUL)
#define SOC_BOOTROM_CPU_PATCHDATA8_ADDR(base) ((base) + 0x40160UL)
#define SOC_BOOTROM_CPU_PATCHDATA9_ADDR(base) ((base) + 0x40164UL)
#define SOC_BOOTROM_CPU_PATCHDATA10_ADDR(base) ((base) + 0x40168UL)
#define SOC_BOOTROM_CPU_PATCHDATA11_ADDR(base) ((base) + 0x4016CUL)
#define SOC_BOOTROM_CPU_PATCHDATA12_ADDR(base) ((base) + 0x40170UL)
#define SOC_BOOTROM_CPU_PATCHDATA13_ADDR(base) ((base) + 0x40174UL)
#define SOC_BOOTROM_CPU_PATCHDATA14_ADDR(base) ((base) + 0x40178UL)
#define SOC_BOOTROM_CPU_PATCHDATA15_ADDR(base) ((base) + 0x4017CUL)
#define SOC_BOOTROM_CPU_REMAPCTRL_ADDR(base) ((base) + 0x40180UL)
#define SOC_BOOTROM_CPU_UNLOCKADDR_ADDR(base) ((base) + 0x40184UL)
#define SOC_BOOTROM_CPU_PATCHCTRL_ADDR(base) ((base) + 0x40188UL)
#define SOC_BOOTROM_CPU_ROMMEMCTRL_ADDR(base) ((base) + 0x4018CUL)
#else
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA0_ADDR(base) ((base) + 0x40000)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA1_ADDR(base) ((base) + 0x40004)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA2_ADDR(base) ((base) + 0x40008)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA3_ADDR(base) ((base) + 0x4000C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA4_ADDR(base) ((base) + 0x40010)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA5_ADDR(base) ((base) + 0x40014)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA6_ADDR(base) ((base) + 0x40018)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA7_ADDR(base) ((base) + 0x4001C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA8_ADDR(base) ((base) + 0x40020)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA9_ADDR(base) ((base) + 0x40024)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA10_ADDR(base) ((base) + 0x40028)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA11_ADDR(base) ((base) + 0x4002C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA12_ADDR(base) ((base) + 0x40030)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA13_ADDR(base) ((base) + 0x40034)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA14_ADDR(base) ((base) + 0x40038)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA15_ADDR(base) ((base) + 0x4003C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA16_ADDR(base) ((base) + 0x40040)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA17_ADDR(base) ((base) + 0x40044)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA18_ADDR(base) ((base) + 0x40048)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA19_ADDR(base) ((base) + 0x4004C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA20_ADDR(base) ((base) + 0x40050)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA21_ADDR(base) ((base) + 0x40054)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA22_ADDR(base) ((base) + 0x40058)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA23_ADDR(base) ((base) + 0x4005C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA24_ADDR(base) ((base) + 0x40060)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA25_ADDR(base) ((base) + 0x40064)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA26_ADDR(base) ((base) + 0x40068)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA27_ADDR(base) ((base) + 0x4006C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA28_ADDR(base) ((base) + 0x40070)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA29_ADDR(base) ((base) + 0x40074)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA30_ADDR(base) ((base) + 0x40078)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA31_ADDR(base) ((base) + 0x4007C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA32_ADDR(base) ((base) + 0x40080)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA33_ADDR(base) ((base) + 0x40084)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA34_ADDR(base) ((base) + 0x40088)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA35_ADDR(base) ((base) + 0x4008C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA36_ADDR(base) ((base) + 0x40090)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA37_ADDR(base) ((base) + 0x40094)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA38_ADDR(base) ((base) + 0x40098)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA39_ADDR(base) ((base) + 0x4009C)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA40_ADDR(base) ((base) + 0x400A0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA41_ADDR(base) ((base) + 0x400A4)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA42_ADDR(base) ((base) + 0x400A8)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA43_ADDR(base) ((base) + 0x400AC)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA44_ADDR(base) ((base) + 0x400B0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA45_ADDR(base) ((base) + 0x400B4)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA46_ADDR(base) ((base) + 0x400B8)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA47_ADDR(base) ((base) + 0x400BC)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA48_ADDR(base) ((base) + 0x400C0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA49_ADDR(base) ((base) + 0x400C4)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA50_ADDR(base) ((base) + 0x400C8)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA51_ADDR(base) ((base) + 0x400CC)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA52_ADDR(base) ((base) + 0x400D0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA53_ADDR(base) ((base) + 0x400D4)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA54_ADDR(base) ((base) + 0x400D8)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA55_ADDR(base) ((base) + 0x400DC)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA56_ADDR(base) ((base) + 0x400E0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA57_ADDR(base) ((base) + 0x400E4)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA58_ADDR(base) ((base) + 0x400E8)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA59_ADDR(base) ((base) + 0x400EC)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA60_ADDR(base) ((base) + 0x400F0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA61_ADDR(base) ((base) + 0x400F4)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA62_ADDR(base) ((base) + 0x400F8)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA63_ADDR(base) ((base) + 0x400FC)
#define SOC_BOOTROM_CPU_PATCHADDR0_ADDR(base) ((base) + 0x40100)
#define SOC_BOOTROM_CPU_PATCHADDR1_ADDR(base) ((base) + 0x40104)
#define SOC_BOOTROM_CPU_PATCHADDR2_ADDR(base) ((base) + 0x40108)
#define SOC_BOOTROM_CPU_PATCHADDR3_ADDR(base) ((base) + 0x4010C)
#define SOC_BOOTROM_CPU_PATCHADDR4_ADDR(base) ((base) + 0x40110)
#define SOC_BOOTROM_CPU_PATCHADDR5_ADDR(base) ((base) + 0x40114)
#define SOC_BOOTROM_CPU_PATCHADDR6_ADDR(base) ((base) + 0x40118)
#define SOC_BOOTROM_CPU_PATCHADDR7_ADDR(base) ((base) + 0x4011C)
#define SOC_BOOTROM_CPU_PATCHADDR8_ADDR(base) ((base) + 0x40120)
#define SOC_BOOTROM_CPU_PATCHADDR9_ADDR(base) ((base) + 0x40124)
#define SOC_BOOTROM_CPU_PATCHADDR10_ADDR(base) ((base) + 0x40128)
#define SOC_BOOTROM_CPU_PATCHADDR11_ADDR(base) ((base) + 0x4012C)
#define SOC_BOOTROM_CPU_PATCHADDR12_ADDR(base) ((base) + 0x40130)
#define SOC_BOOTROM_CPU_PATCHADDR13_ADDR(base) ((base) + 0x40134)
#define SOC_BOOTROM_CPU_PATCHADDR14_ADDR(base) ((base) + 0x40138)
#define SOC_BOOTROM_CPU_PATCHADDR15_ADDR(base) ((base) + 0x4013C)
#define SOC_BOOTROM_CPU_PATCHDATA0_ADDR(base) ((base) + 0x40140)
#define SOC_BOOTROM_CPU_PATCHDATA1_ADDR(base) ((base) + 0x40144)
#define SOC_BOOTROM_CPU_PATCHDATA2_ADDR(base) ((base) + 0x40148)
#define SOC_BOOTROM_CPU_PATCHDATA3_ADDR(base) ((base) + 0x4014C)
#define SOC_BOOTROM_CPU_PATCHDATA4_ADDR(base) ((base) + 0x40150)
#define SOC_BOOTROM_CPU_PATCHDATA5_ADDR(base) ((base) + 0x40154)
#define SOC_BOOTROM_CPU_PATCHDATA6_ADDR(base) ((base) + 0x40158)
#define SOC_BOOTROM_CPU_PATCHDATA7_ADDR(base) ((base) + 0x4015C)
#define SOC_BOOTROM_CPU_PATCHDATA8_ADDR(base) ((base) + 0x40160)
#define SOC_BOOTROM_CPU_PATCHDATA9_ADDR(base) ((base) + 0x40164)
#define SOC_BOOTROM_CPU_PATCHDATA10_ADDR(base) ((base) + 0x40168)
#define SOC_BOOTROM_CPU_PATCHDATA11_ADDR(base) ((base) + 0x4016C)
#define SOC_BOOTROM_CPU_PATCHDATA12_ADDR(base) ((base) + 0x40170)
#define SOC_BOOTROM_CPU_PATCHDATA13_ADDR(base) ((base) + 0x40174)
#define SOC_BOOTROM_CPU_PATCHDATA14_ADDR(base) ((base) + 0x40178)
#define SOC_BOOTROM_CPU_PATCHDATA15_ADDR(base) ((base) + 0x4017C)
#define SOC_BOOTROM_CPU_REMAPCTRL_ADDR(base) ((base) + 0x40180)
#define SOC_BOOTROM_CPU_UNLOCKADDR_ADDR(base) ((base) + 0x40184)
#define SOC_BOOTROM_CPU_PATCHCTRL_ADDR(base) ((base) + 0x40188)
#define SOC_BOOTROM_CPU_ROMMEMCTRL_ADDR(base) ((base) + 0x4018C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data0 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA0_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA0_patchextend_data0_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA0_patchextend_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data1 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA1_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA1_patchextend_data1_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA1_patchextend_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data2 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA2_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA2_patchextend_data2_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA2_patchextend_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data3 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA3_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA3_patchextend_data3_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA3_patchextend_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data4 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA4_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA4_patchextend_data4_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA4_patchextend_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data5 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA5_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA5_patchextend_data5_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA5_patchextend_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data6 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA6_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA6_patchextend_data6_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA6_patchextend_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data7 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA7_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA7_patchextend_data7_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA7_patchextend_data7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data8 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA8_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA8_patchextend_data8_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA8_patchextend_data8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data9 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA9_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA9_patchextend_data9_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA9_patchextend_data9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data10 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA10_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA10_patchextend_data10_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA10_patchextend_data10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data11 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA11_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA11_patchextend_data11_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA11_patchextend_data11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data12 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA12_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA12_patchextend_data12_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA12_patchextend_data12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data13 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA13_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA13_patchextend_data13_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA13_patchextend_data13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data14 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA14_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA14_patchextend_data14_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA14_patchextend_data14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data15 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA15_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA15_patchextend_data15_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA15_patchextend_data15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data16 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA16_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA16_patchextend_data16_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA16_patchextend_data16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data17 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA17_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA17_patchextend_data17_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA17_patchextend_data17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data18 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA18_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA18_patchextend_data18_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA18_patchextend_data18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data19 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA19_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA19_patchextend_data19_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA19_patchextend_data19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data20 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA20_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA20_patchextend_data20_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA20_patchextend_data20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data21 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA21_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA21_patchextend_data21_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA21_patchextend_data21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data22 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA22_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA22_patchextend_data22_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA22_patchextend_data22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data23 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA23_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA23_patchextend_data23_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA23_patchextend_data23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data24 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA24_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA24_patchextend_data24_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA24_patchextend_data24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data25 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA25_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA25_patchextend_data25_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA25_patchextend_data25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data26 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA26_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA26_patchextend_data26_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA26_patchextend_data26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data27 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA27_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA27_patchextend_data27_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA27_patchextend_data27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data28 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA28_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA28_patchextend_data28_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA28_patchextend_data28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data29 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA29_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA29_patchextend_data29_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA29_patchextend_data29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data30 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA30_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA30_patchextend_data30_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA30_patchextend_data30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data31 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA31_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA31_patchextend_data31_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA31_patchextend_data31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data32 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA32_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA32_patchextend_data32_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA32_patchextend_data32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data33 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA33_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA33_patchextend_data33_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA33_patchextend_data33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data34 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA34_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA34_patchextend_data34_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA34_patchextend_data34_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data35 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA35_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA35_patchextend_data35_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA35_patchextend_data35_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data36 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA36_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA36_patchextend_data36_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA36_patchextend_data36_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data37 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA37_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA37_patchextend_data37_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA37_patchextend_data37_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data38 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA38_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA38_patchextend_data38_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA38_patchextend_data38_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data39 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA39_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA39_patchextend_data39_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA39_patchextend_data39_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data40 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA40_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA40_patchextend_data40_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA40_patchextend_data40_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data41 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA41_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA41_patchextend_data41_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA41_patchextend_data41_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data42 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA42_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA42_patchextend_data42_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA42_patchextend_data42_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data43 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA43_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA43_patchextend_data43_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA43_patchextend_data43_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data44 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA44_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA44_patchextend_data44_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA44_patchextend_data44_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data45 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA45_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA45_patchextend_data45_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA45_patchextend_data45_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data46 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA46_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA46_patchextend_data46_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA46_patchextend_data46_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data47 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA47_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA47_patchextend_data47_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA47_patchextend_data47_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data48 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA48_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA48_patchextend_data48_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA48_patchextend_data48_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data49 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA49_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA49_patchextend_data49_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA49_patchextend_data49_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data50 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA50_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA50_patchextend_data50_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA50_patchextend_data50_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data51 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA51_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA51_patchextend_data51_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA51_patchextend_data51_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data52 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA52_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA52_patchextend_data52_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA52_patchextend_data52_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data53 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA53_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA53_patchextend_data53_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA53_patchextend_data53_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data54 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA54_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA54_patchextend_data54_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA54_patchextend_data54_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data55 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA55_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA55_patchextend_data55_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA55_patchextend_data55_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data56 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA56_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA56_patchextend_data56_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA56_patchextend_data56_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data57 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA57_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA57_patchextend_data57_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA57_patchextend_data57_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data58 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA58_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA58_patchextend_data58_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA58_patchextend_data58_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data59 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA59_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA59_patchextend_data59_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA59_patchextend_data59_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data60 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA60_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA60_patchextend_data60_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA60_patchextend_data60_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data61 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA61_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA61_patchextend_data61_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA61_patchextend_data61_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data62 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA62_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA62_patchextend_data62_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA62_patchextend_data62_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchextend_data63 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHEXTENDDATA63_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA63_patchextend_data63_START (0)
#define SOC_BOOTROM_CPU_PATCHEXTENDDATA63_patchextend_data63_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr0 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR0_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR0_patchaddr0_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR0_patchaddr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr1 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR1_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR1_patchaddr1_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR1_patchaddr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr2 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR2_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR2_patchaddr2_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR2_patchaddr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr3 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR3_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR3_patchaddr3_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR3_patchaddr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr4 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR4_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR4_patchaddr4_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR4_patchaddr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr5 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR5_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR5_patchaddr5_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR5_patchaddr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr6 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR6_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR6_patchaddr6_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR6_patchaddr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr7 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR7_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR7_patchaddr7_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR7_patchaddr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr8 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR8_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR8_patchaddr8_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR8_patchaddr8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr9 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR9_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR9_patchaddr9_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR9_patchaddr9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr10 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR10_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR10_patchaddr10_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR10_patchaddr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr11 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR11_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR11_patchaddr11_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR11_patchaddr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr12 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR12_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR12_patchaddr12_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR12_patchaddr12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr13 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR13_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR13_patchaddr13_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR13_patchaddr13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr14 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR14_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR14_patchaddr14_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR14_patchaddr14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchaddr15 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHADDR15_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHADDR15_patchaddr15_START (0)
#define SOC_BOOTROM_CPU_PATCHADDR15_patchaddr15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata0 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA0_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA0_patchdata0_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA0_patchdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata1 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA1_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA1_patchdata1_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA1_patchdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata2 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA2_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA2_patchdata2_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA2_patchdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata3 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA3_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA3_patchdata3_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA3_patchdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata4 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA4_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA4_patchdata4_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA4_patchdata4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata5 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA5_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA5_patchdata5_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA5_patchdata5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata6 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA6_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA6_patchdata6_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA6_patchdata6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata7 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA7_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA7_patchdata7_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA7_patchdata7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata8 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA8_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA8_patchdata8_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA8_patchdata8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata9 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA9_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA9_patchdata9_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA9_patchdata9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata10 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA10_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA10_patchdata10_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA10_patchdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata11 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA11_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA11_patchdata11_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA11_patchdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata12 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA12_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA12_patchdata12_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA12_patchdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata13 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA13_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA13_patchdata13_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA13_patchdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata14 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA14_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA14_patchdata14_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA14_patchdata14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchdata15 : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHDATA15_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHDATA15_patchdata15_START (0)
#define SOC_BOOTROM_CPU_PATCHDATA15_patchdata15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remap_ctrl : 32;
    } reg;
} SOC_BOOTROM_CPU_REMAPCTRL_UNION;
#endif
#define SOC_BOOTROM_CPU_REMAPCTRL_remap_ctrl_START (0)
#define SOC_BOOTROM_CPU_REMAPCTRL_remap_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int unlock_addr : 32;
    } reg;
} SOC_BOOTROM_CPU_UNLOCKADDR_UNION;
#endif
#define SOC_BOOTROM_CPU_UNLOCKADDR_unlock_addr_START (0)
#define SOC_BOOTROM_CPU_UNLOCKADDR_unlock_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int patchctrl : 32;
    } reg;
} SOC_BOOTROM_CPU_PATCHCTRL_UNION;
#endif
#define SOC_BOOTROM_CPU_PATCHCTRL_patchctrl_START (0)
#define SOC_BOOTROM_CPU_PATCHCTRL_patchctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootrom_rom_mem_ctrl : 32;
    } reg;
} SOC_BOOTROM_CPU_ROMMEMCTRL_UNION;
#endif
#define SOC_BOOTROM_CPU_ROMMEMCTRL_bootrom_rom_mem_ctrl_START (0)
#define SOC_BOOTROM_CPU_ROMMEMCTRL_bootrom_rom_mem_ctrl_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
