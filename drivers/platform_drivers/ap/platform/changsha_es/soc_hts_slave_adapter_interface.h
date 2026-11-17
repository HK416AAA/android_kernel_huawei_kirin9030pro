#ifndef __SOC_HTS_SLAVE_ADAPTER_INTERFACE_H__
#define __SOC_HTS_SLAVE_ADAPTER_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_0_ADDR(base) (base)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_1_ADDR(base) ((base) + 0x004UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_2_ADDR(base) ((base) + 0x008UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_3_ADDR(base) ((base) + 0x00CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_4_ADDR(base) ((base) + 0x010UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_5_ADDR(base) ((base) + 0x014UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_6_ADDR(base) ((base) + 0x018UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_7_ADDR(base) ((base) + 0x01CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_8_ADDR(base) ((base) + 0x020UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_9_ADDR(base) ((base) + 0x024UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_10_ADDR(base) ((base) + 0x028UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_11_ADDR(base) ((base) + 0x02CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_12_ADDR(base) ((base) + 0x030UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_13_ADDR(base) ((base) + 0x034UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_14_ADDR(base) ((base) + 0x038UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_15_ADDR(base) ((base) + 0x03CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_16_ADDR(base) ((base) + 0x040UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_17_ADDR(base) ((base) + 0x044UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_18_ADDR(base) ((base) + 0x048UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_19_ADDR(base) ((base) + 0x04CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_20_ADDR(base) ((base) + 0x050UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_21_ADDR(base) ((base) + 0x054UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_22_ADDR(base) ((base) + 0x058UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_23_ADDR(base) ((base) + 0x05CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_24_ADDR(base) ((base) + 0x060UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_25_ADDR(base) ((base) + 0x064UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_26_ADDR(base) ((base) + 0x068UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_27_ADDR(base) ((base) + 0x06CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_28_ADDR(base) ((base) + 0x070UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_29_ADDR(base) ((base) + 0x074UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_30_ADDR(base) ((base) + 0x078UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_31_ADDR(base) ((base) + 0x07CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_ADDR(base) ((base) + 0x080UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_ADDR(base) ((base) + 0x084UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_EVENT_ADDR(base) ((base) + 0x088UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_STAT_ADDR(base) ((base) + 0x08CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_MSK_ADDR(base) ((base) + 0x90UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_ADDR(base) ((base) + 0x100UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_ADDR(base) ((base) + 0x104UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_ADDR(base) ((base) + 0x108UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT0_ADDR(base) ((base) + 0x10CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT1_ADDR(base) ((base) + 0x110UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT2_ADDR(base) ((base) + 0x114UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT3_ADDR(base) ((base) + 0x118UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT4_ADDR(base) ((base) + 0x11CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT5_ADDR(base) ((base) + 0x120UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT6_ADDR(base) ((base) + 0x124UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT7_ADDR(base) ((base) + 0x128UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT8_ADDR(base) ((base) + 0x12CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT9_ADDR(base) ((base) + 0x130UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT10_ADDR(base) ((base) + 0x134UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT11_ADDR(base) ((base) + 0x138UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT12_ADDR(base) ((base) + 0x13CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT13_ADDR(base) ((base) + 0x140UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT14_ADDR(base) ((base) + 0x144UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT15_ADDR(base) ((base) + 0x148UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT16_ADDR(base) ((base) + 0x14CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT17_ADDR(base) ((base) + 0x150UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT18_ADDR(base) ((base) + 0x154UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT19_ADDR(base) ((base) + 0x158UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT20_ADDR(base) ((base) + 0x15CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT21_ADDR(base) ((base) + 0x160UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT22_ADDR(base) ((base) + 0x164UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT23_ADDR(base) ((base) + 0x168UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT24_ADDR(base) ((base) + 0x16CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT25_ADDR(base) ((base) + 0x170UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT26_ADDR(base) ((base) + 0x174UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT27_ADDR(base) ((base) + 0x178UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT28_ADDR(base) ((base) + 0x17CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT29_ADDR(base) ((base) + 0x180UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT30_ADDR(base) ((base) + 0x184UL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT31_ADDR(base) ((base) + 0x188UL)
#define SOC_HTS_SLAVE_ADAPTER_HTS_SLV_ADAPTER_RCV_EVENT_CNT_ADDR(base) ((base) + 0x18CUL)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_LAST_EVENT_ADDR(base) ((base) + 0x190UL)
#else
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_0_ADDR(base) (base)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_1_ADDR(base) ((base) + 0x004)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_2_ADDR(base) ((base) + 0x008)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_3_ADDR(base) ((base) + 0x00C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_4_ADDR(base) ((base) + 0x010)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_5_ADDR(base) ((base) + 0x014)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_6_ADDR(base) ((base) + 0x018)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_7_ADDR(base) ((base) + 0x01C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_8_ADDR(base) ((base) + 0x020)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_9_ADDR(base) ((base) + 0x024)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_10_ADDR(base) ((base) + 0x028)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_11_ADDR(base) ((base) + 0x02C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_12_ADDR(base) ((base) + 0x030)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_13_ADDR(base) ((base) + 0x034)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_14_ADDR(base) ((base) + 0x038)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_15_ADDR(base) ((base) + 0x03C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_16_ADDR(base) ((base) + 0x040)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_17_ADDR(base) ((base) + 0x044)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_18_ADDR(base) ((base) + 0x048)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_19_ADDR(base) ((base) + 0x04C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_20_ADDR(base) ((base) + 0x050)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_21_ADDR(base) ((base) + 0x054)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_22_ADDR(base) ((base) + 0x058)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_23_ADDR(base) ((base) + 0x05C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_24_ADDR(base) ((base) + 0x060)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_25_ADDR(base) ((base) + 0x064)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_26_ADDR(base) ((base) + 0x068)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_27_ADDR(base) ((base) + 0x06C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_28_ADDR(base) ((base) + 0x070)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_29_ADDR(base) ((base) + 0x074)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_30_ADDR(base) ((base) + 0x078)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_31_ADDR(base) ((base) + 0x07C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_ADDR(base) ((base) + 0x080)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_ADDR(base) ((base) + 0x084)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_EVENT_ADDR(base) ((base) + 0x088)
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_STAT_ADDR(base) ((base) + 0x08C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_MSK_ADDR(base) ((base) + 0x90)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_ADDR(base) ((base) + 0x100)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_ADDR(base) ((base) + 0x104)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_ADDR(base) ((base) + 0x108)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT0_ADDR(base) ((base) + 0x10C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT1_ADDR(base) ((base) + 0x110)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT2_ADDR(base) ((base) + 0x114)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT3_ADDR(base) ((base) + 0x118)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT4_ADDR(base) ((base) + 0x11C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT5_ADDR(base) ((base) + 0x120)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT6_ADDR(base) ((base) + 0x124)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT7_ADDR(base) ((base) + 0x128)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT8_ADDR(base) ((base) + 0x12C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT9_ADDR(base) ((base) + 0x130)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT10_ADDR(base) ((base) + 0x134)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT11_ADDR(base) ((base) + 0x138)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT12_ADDR(base) ((base) + 0x13C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT13_ADDR(base) ((base) + 0x140)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT14_ADDR(base) ((base) + 0x144)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT15_ADDR(base) ((base) + 0x148)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT16_ADDR(base) ((base) + 0x14C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT17_ADDR(base) ((base) + 0x150)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT18_ADDR(base) ((base) + 0x154)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT19_ADDR(base) ((base) + 0x158)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT20_ADDR(base) ((base) + 0x15C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT21_ADDR(base) ((base) + 0x160)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT22_ADDR(base) ((base) + 0x164)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT23_ADDR(base) ((base) + 0x168)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT24_ADDR(base) ((base) + 0x16C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT25_ADDR(base) ((base) + 0x170)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT26_ADDR(base) ((base) + 0x174)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT27_ADDR(base) ((base) + 0x178)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT28_ADDR(base) ((base) + 0x17C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT29_ADDR(base) ((base) + 0x180)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT30_ADDR(base) ((base) + 0x184)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT31_ADDR(base) ((base) + 0x188)
#define SOC_HTS_SLAVE_ADAPTER_HTS_SLV_ADAPTER_RCV_EVENT_CNT_ADDR(base) ((base) + 0x18C)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_LAST_EVENT_ADDR(base) ((base) + 0x190)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_0_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_0_e2i_cfg_event_0_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_0_e2i_cfg_event_0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_1 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_1_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_1_e2i_cfg_event_1_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_1_e2i_cfg_event_1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_2_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_2_e2i_cfg_event_2_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_2_e2i_cfg_event_2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_3 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_3_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_3_e2i_cfg_event_3_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_3_e2i_cfg_event_3_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_4 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_4_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_4_e2i_cfg_event_4_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_4_e2i_cfg_event_4_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_5 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_5_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_5_e2i_cfg_event_5_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_5_e2i_cfg_event_5_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_6 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_6_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_6_e2i_cfg_event_6_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_6_e2i_cfg_event_6_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_7 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_7_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_7_e2i_cfg_event_7_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_7_e2i_cfg_event_7_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_8 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_8_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_8_e2i_cfg_event_8_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_8_e2i_cfg_event_8_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_9 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_9_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_9_e2i_cfg_event_9_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_9_e2i_cfg_event_9_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_10 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_10_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_10_e2i_cfg_event_10_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_10_e2i_cfg_event_10_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_11 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_11_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_11_e2i_cfg_event_11_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_11_e2i_cfg_event_11_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_12 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_12_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_12_e2i_cfg_event_12_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_12_e2i_cfg_event_12_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_13 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_13_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_13_e2i_cfg_event_13_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_13_e2i_cfg_event_13_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_14 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_14_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_14_e2i_cfg_event_14_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_14_e2i_cfg_event_14_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_15 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_15_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_15_e2i_cfg_event_15_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_15_e2i_cfg_event_15_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_16 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_16_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_16_e2i_cfg_event_16_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_16_e2i_cfg_event_16_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_17 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_17_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_17_e2i_cfg_event_17_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_17_e2i_cfg_event_17_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_18 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_18_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_18_e2i_cfg_event_18_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_18_e2i_cfg_event_18_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_19 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_19_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_19_e2i_cfg_event_19_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_19_e2i_cfg_event_19_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_20 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_20_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_20_e2i_cfg_event_20_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_20_e2i_cfg_event_20_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_21 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_21_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_21_e2i_cfg_event_21_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_21_e2i_cfg_event_21_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_22 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_22_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_22_e2i_cfg_event_22_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_22_e2i_cfg_event_22_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_23 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_23_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_23_e2i_cfg_event_23_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_23_e2i_cfg_event_23_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_24 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_24_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_24_e2i_cfg_event_24_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_24_e2i_cfg_event_24_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_25 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_25_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_25_e2i_cfg_event_25_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_25_e2i_cfg_event_25_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_26 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_26_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_26_e2i_cfg_event_26_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_26_e2i_cfg_event_26_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_27 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_27_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_27_e2i_cfg_event_27_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_27_e2i_cfg_event_27_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_28 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_28_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_28_e2i_cfg_event_28_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_28_e2i_cfg_event_28_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_29 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_29_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_29_e2i_cfg_event_29_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_29_e2i_cfg_event_29_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_30 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_30_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_30_e2i_cfg_event_30_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_30_e2i_cfg_event_30_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cfg_event_31 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_31_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_31_e2i_cfg_event_31_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CFG_EVENT_31_e2i_cfg_event_31_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cnt_err_irpt_stat0 : 1;
        unsigned int e2i_cnt_err_irpt_stat1 : 1;
        unsigned int e2i_cnt_err_irpt_stat2 : 1;
        unsigned int e2i_cnt_err_irpt_stat3 : 1;
        unsigned int e2i_cnt_err_irpt_stat4 : 1;
        unsigned int e2i_cnt_err_irpt_stat5 : 1;
        unsigned int e2i_cnt_err_irpt_stat6 : 1;
        unsigned int e2i_cnt_err_irpt_stat7 : 1;
        unsigned int e2i_cnt_err_irpt_stat8 : 1;
        unsigned int e2i_cnt_err_irpt_stat9 : 1;
        unsigned int e2i_cnt_err_irpt_stat10 : 1;
        unsigned int e2i_cnt_err_irpt_stat11 : 1;
        unsigned int e2i_cnt_err_irpt_stat12 : 1;
        unsigned int e2i_cnt_err_irpt_stat13 : 1;
        unsigned int e2i_cnt_err_irpt_stat14 : 1;
        unsigned int e2i_cnt_err_irpt_stat15 : 1;
        unsigned int e2i_cnt_err_irpt_stat16 : 1;
        unsigned int e2i_cnt_err_irpt_stat17 : 1;
        unsigned int e2i_cnt_err_irpt_stat18 : 1;
        unsigned int e2i_cnt_err_irpt_stat19 : 1;
        unsigned int e2i_cnt_err_irpt_stat20 : 1;
        unsigned int e2i_cnt_err_irpt_stat21 : 1;
        unsigned int e2i_cnt_err_irpt_stat22 : 1;
        unsigned int e2i_cnt_err_irpt_stat23 : 1;
        unsigned int e2i_cnt_err_irpt_stat24 : 1;
        unsigned int e2i_cnt_err_irpt_stat25 : 1;
        unsigned int e2i_cnt_err_irpt_stat26 : 1;
        unsigned int e2i_cnt_err_irpt_stat27 : 1;
        unsigned int e2i_cnt_err_irpt_stat28 : 1;
        unsigned int e2i_cnt_err_irpt_stat29 : 1;
        unsigned int e2i_cnt_err_irpt_stat30 : 1;
        unsigned int e2i_cnt_err_irpt_stat31 : 1;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat0_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat0_END (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat1_START (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat1_END (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat2_START (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat2_END (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat3_START (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat3_END (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat4_START (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat4_END (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat5_START (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat5_END (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat6_START (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat6_END (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat7_START (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat7_END (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat8_START (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat8_END (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat9_START (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat9_END (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat10_START (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat10_END (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat11_START (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat11_END (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat12_START (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat12_END (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat13_START (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat13_END (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat14_START (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat14_END (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat15_START (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat15_END (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat16_START (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat16_END (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat17_START (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat17_END (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat18_START (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat18_END (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat19_START (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat19_END (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat20_START (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat20_END (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat21_START (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat21_END (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat22_START (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat22_END (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat23_START (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat23_END (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat24_START (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat24_END (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat25_START (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat25_END (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat26_START (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat26_END (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat27_START (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat27_END (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat28_START (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat28_END (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat29_START (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat29_END (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat30_START (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat30_END (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat31_START (31)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_STAT_e2i_cnt_err_irpt_stat31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cnt_err_irpt_msk0 : 1;
        unsigned int e2i_cnt_err_irpt_msk1 : 1;
        unsigned int e2i_cnt_err_irpt_msk2 : 1;
        unsigned int e2i_cnt_err_irpt_msk3 : 1;
        unsigned int e2i_cnt_err_irpt_msk4 : 1;
        unsigned int e2i_cnt_err_irpt_msk5 : 1;
        unsigned int e2i_cnt_err_irpt_msk6 : 1;
        unsigned int e2i_cnt_err_irpt_msk7 : 1;
        unsigned int e2i_cnt_err_irpt_msk8 : 1;
        unsigned int e2i_cnt_err_irpt_msk9 : 1;
        unsigned int e2i_cnt_err_irpt_msk10 : 1;
        unsigned int e2i_cnt_err_irpt_msk11 : 1;
        unsigned int e2i_cnt_err_irpt_msk12 : 1;
        unsigned int e2i_cnt_err_irpt_msk13 : 1;
        unsigned int e2i_cnt_err_irpt_msk14 : 1;
        unsigned int e2i_cnt_err_irpt_msk15 : 1;
        unsigned int e2i_cnt_err_irpt_msk16 : 1;
        unsigned int e2i_cnt_err_irpt_msk17 : 1;
        unsigned int e2i_cnt_err_irpt_msk18 : 1;
        unsigned int e2i_cnt_err_irpt_msk19 : 1;
        unsigned int e2i_cnt_err_irpt_msk20 : 1;
        unsigned int e2i_cnt_err_irpt_msk21 : 1;
        unsigned int e2i_cnt_err_irpt_msk22 : 1;
        unsigned int e2i_cnt_err_irpt_msk23 : 1;
        unsigned int e2i_cnt_err_irpt_msk24 : 1;
        unsigned int e2i_cnt_err_irpt_msk25 : 1;
        unsigned int e2i_cnt_err_irpt_msk26 : 1;
        unsigned int e2i_cnt_err_irpt_msk27 : 1;
        unsigned int e2i_cnt_err_irpt_msk28 : 1;
        unsigned int e2i_cnt_err_irpt_msk29 : 1;
        unsigned int e2i_cnt_err_irpt_msk30 : 1;
        unsigned int e2i_cnt_err_irpt_msk31 : 1;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk0_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk0_END (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk1_START (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk1_END (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk2_START (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk2_END (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk3_START (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk3_END (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk4_START (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk4_END (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk5_START (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk5_END (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk6_START (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk6_END (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk7_START (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk7_END (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk8_START (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk8_END (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk9_START (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk9_END (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk10_START (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk10_END (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk11_START (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk11_END (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk12_START (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk12_END (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk13_START (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk13_END (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk14_START (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk14_END (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk15_START (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk15_END (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk16_START (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk16_END (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk17_START (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk17_END (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk18_START (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk18_END (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk19_START (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk19_END (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk20_START (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk20_END (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk21_START (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk21_END (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk22_START (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk22_END (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk23_START (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk23_END (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk24_START (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk24_END (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk25_START (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk25_END (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk26_START (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk26_END (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk27_START (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk27_END (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk28_START (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk28_END (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk29_START (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk29_END (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk30_START (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk30_END (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk31_START (31)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_IRPT_MSK_e2i_cnt_err_irpt_msk31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_cnt_err_event : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_EVENT_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_EVENT_e2i_cnt_err_event_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_CNT_ERR_EVENT_e2i_cnt_err_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_wrong_event_irpt_stat : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_STAT_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_STAT_e2i_wrong_event_irpt_stat_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_STAT_e2i_wrong_event_irpt_stat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_wrong_event_irpt_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_MSK_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_MSK_e2i_wrong_event_irpt_msk_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_WRONG_EVENT_IRPT_MSK_e2i_wrong_event_irpt_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_irpt_stat0 : 1;
        unsigned int e2i_event_irpt_stat1 : 1;
        unsigned int e2i_event_irpt_stat2 : 1;
        unsigned int e2i_event_irpt_stat3 : 1;
        unsigned int e2i_event_irpt_stat4 : 1;
        unsigned int e2i_event_irpt_stat5 : 1;
        unsigned int e2i_event_irpt_stat6 : 1;
        unsigned int e2i_event_irpt_stat7 : 1;
        unsigned int e2i_event_irpt_stat8 : 1;
        unsigned int e2i_event_irpt_stat9 : 1;
        unsigned int e2i_event_irpt_stat10 : 1;
        unsigned int e2i_event_irpt_stat11 : 1;
        unsigned int e2i_event_irpt_stat12 : 1;
        unsigned int e2i_event_irpt_stat13 : 1;
        unsigned int e2i_event_irpt_stat14 : 1;
        unsigned int e2i_event_irpt_stat15 : 1;
        unsigned int e2i_event_irpt_stat16 : 1;
        unsigned int e2i_event_irpt_stat17 : 1;
        unsigned int e2i_event_irpt_stat18 : 1;
        unsigned int e2i_event_irpt_stat19 : 1;
        unsigned int e2i_event_irpt_stat20 : 1;
        unsigned int e2i_event_irpt_stat21 : 1;
        unsigned int e2i_event_irpt_stat22 : 1;
        unsigned int e2i_event_irpt_stat23 : 1;
        unsigned int e2i_event_irpt_stat24 : 1;
        unsigned int e2i_event_irpt_stat25 : 1;
        unsigned int e2i_event_irpt_stat26 : 1;
        unsigned int e2i_event_irpt_stat27 : 1;
        unsigned int e2i_event_irpt_stat28 : 1;
        unsigned int e2i_event_irpt_stat29 : 1;
        unsigned int e2i_event_irpt_stat30 : 1;
        unsigned int e2i_event_irpt_stat31 : 1;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat0_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat0_END (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat1_START (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat1_END (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat2_START (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat2_END (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat3_START (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat3_END (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat4_START (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat4_END (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat5_START (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat5_END (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat6_START (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat6_END (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat7_START (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat7_END (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat8_START (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat8_END (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat9_START (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat9_END (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat10_START (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat10_END (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat11_START (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat11_END (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat12_START (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat12_END (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat13_START (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat13_END (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat14_START (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat14_END (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat15_START (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat15_END (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat16_START (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat16_END (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat17_START (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat17_END (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat18_START (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat18_END (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat19_START (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat19_END (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat20_START (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat20_END (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat21_START (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat21_END (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat22_START (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat22_END (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat23_START (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat23_END (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat24_START (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat24_END (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat25_START (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat25_END (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat26_START (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat26_END (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat27_START (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat27_END (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat28_START (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat28_END (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat29_START (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat29_END (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat30_START (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat30_END (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat31_START (31)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_STAT_e2i_event_irpt_stat31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_irpt_msk0 : 1;
        unsigned int e2i_event_irpt_msk1 : 1;
        unsigned int e2i_event_irpt_msk2 : 1;
        unsigned int e2i_event_irpt_msk3 : 1;
        unsigned int e2i_event_irpt_msk4 : 1;
        unsigned int e2i_event_irpt_msk5 : 1;
        unsigned int e2i_event_irpt_msk6 : 1;
        unsigned int e2i_event_irpt_msk7 : 1;
        unsigned int e2i_event_irpt_msk8 : 1;
        unsigned int e2i_event_irpt_msk9 : 1;
        unsigned int e2i_event_irpt_msk10 : 1;
        unsigned int e2i_event_irpt_msk11 : 1;
        unsigned int e2i_event_irpt_msk12 : 1;
        unsigned int e2i_event_irpt_msk13 : 1;
        unsigned int e2i_event_irpt_msk14 : 1;
        unsigned int e2i_event_irpt_msk15 : 1;
        unsigned int e2i_event_irpt_msk16 : 1;
        unsigned int e2i_event_irpt_msk17 : 1;
        unsigned int e2i_event_irpt_msk18 : 1;
        unsigned int e2i_event_irpt_msk19 : 1;
        unsigned int e2i_event_irpt_msk20 : 1;
        unsigned int e2i_event_irpt_msk21 : 1;
        unsigned int e2i_event_irpt_msk22 : 1;
        unsigned int e2i_event_irpt_msk23 : 1;
        unsigned int e2i_event_irpt_msk24 : 1;
        unsigned int e2i_event_irpt_msk25 : 1;
        unsigned int e2i_event_irpt_msk26 : 1;
        unsigned int e2i_event_irpt_msk27 : 1;
        unsigned int e2i_event_irpt_msk28 : 1;
        unsigned int e2i_event_irpt_msk29 : 1;
        unsigned int e2i_event_irpt_msk30 : 1;
        unsigned int e2i_event_irpt_msk31 : 1;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk0_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk0_END (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk1_START (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk1_END (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk2_START (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk2_END (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk3_START (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk3_END (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk4_START (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk4_END (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk5_START (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk5_END (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk6_START (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk6_END (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk7_START (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk7_END (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk8_START (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk8_END (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk9_START (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk9_END (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk10_START (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk10_END (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk11_START (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk11_END (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk12_START (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk12_END (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk13_START (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk13_END (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk14_START (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk14_END (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk15_START (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk15_END (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk16_START (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk16_END (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk17_START (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk17_END (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk18_START (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk18_END (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk19_START (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk19_END (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk20_START (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk20_END (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk21_START (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk21_END (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk22_START (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk22_END (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk23_START (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk23_END (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk24_START (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk24_END (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk25_START (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk25_END (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk26_START (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk26_END (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk27_START (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk27_END (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk28_START (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk28_END (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk29_START (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk29_END (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk30_START (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk30_END (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk31_START (31)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_MSK_e2i_event_irpt_msk31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_irpt_lock0 : 1;
        unsigned int e2i_event_irpt_lock1 : 1;
        unsigned int e2i_event_irpt_lock2 : 1;
        unsigned int e2i_event_irpt_lock3 : 1;
        unsigned int e2i_event_irpt_lock4 : 1;
        unsigned int e2i_event_irpt_lock5 : 1;
        unsigned int e2i_event_irpt_lock6 : 1;
        unsigned int e2i_event_irpt_lock7 : 1;
        unsigned int e2i_event_irpt_lock8 : 1;
        unsigned int e2i_event_irpt_lock9 : 1;
        unsigned int e2i_event_irpt_lock10 : 1;
        unsigned int e2i_event_irpt_lock11 : 1;
        unsigned int e2i_event_irpt_lock12 : 1;
        unsigned int e2i_event_irpt_lock13 : 1;
        unsigned int e2i_event_irpt_lock14 : 1;
        unsigned int e2i_event_irpt_lock15 : 1;
        unsigned int e2i_event_irpt_lock16 : 1;
        unsigned int e2i_event_irpt_lock17 : 1;
        unsigned int e2i_event_irpt_lock18 : 1;
        unsigned int e2i_event_irpt_lock19 : 1;
        unsigned int e2i_event_irpt_lock20 : 1;
        unsigned int e2i_event_irpt_lock21 : 1;
        unsigned int e2i_event_irpt_lock22 : 1;
        unsigned int e2i_event_irpt_lock23 : 1;
        unsigned int e2i_event_irpt_lock24 : 1;
        unsigned int e2i_event_irpt_lock25 : 1;
        unsigned int e2i_event_irpt_lock26 : 1;
        unsigned int e2i_event_irpt_lock27 : 1;
        unsigned int e2i_event_irpt_lock28 : 1;
        unsigned int e2i_event_irpt_lock29 : 1;
        unsigned int e2i_event_irpt_lock30 : 1;
        unsigned int e2i_event_irpt_lock31 : 1;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock0_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock0_END (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock1_START (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock1_END (1)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock2_START (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock2_END (2)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock3_START (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock3_END (3)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock4_START (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock4_END (4)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock5_START (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock5_END (5)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock6_START (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock6_END (6)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock7_START (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock7_END (7)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock8_START (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock8_END (8)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock9_START (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock9_END (9)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock10_START (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock10_END (10)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock11_START (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock11_END (11)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock12_START (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock12_END (12)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock13_START (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock13_END (13)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock14_START (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock14_END (14)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock15_START (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock15_END (15)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock16_START (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock16_END (16)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock17_START (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock17_END (17)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock18_START (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock18_END (18)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock19_START (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock19_END (19)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock20_START (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock20_END (20)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock21_START (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock21_END (21)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock22_START (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock22_END (22)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock23_START (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock23_END (23)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock24_START (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock24_END (24)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock25_START (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock25_END (25)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock26_START (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock26_END (26)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock27_START (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock27_END (27)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock28_START (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock28_END (28)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock29_START (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock29_END (29)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock30_START (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock30_END (30)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock31_START (31)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_IRPT_LOCK_e2i_event_irpt_lock31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt0 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT0_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT0_e2i_event_cnt0_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT0_e2i_event_cnt0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT1_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT1_e2i_event_cnt1_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT1_e2i_event_cnt1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt2 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT2_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT2_e2i_event_cnt2_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT2_e2i_event_cnt2_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt3 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT3_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT3_e2i_event_cnt3_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT3_e2i_event_cnt3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt4 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT4_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT4_e2i_event_cnt4_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT4_e2i_event_cnt4_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt5 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT5_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT5_e2i_event_cnt5_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT5_e2i_event_cnt5_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt6 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT6_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT6_e2i_event_cnt6_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT6_e2i_event_cnt6_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt7 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT7_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT7_e2i_event_cnt7_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT7_e2i_event_cnt7_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt8 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT8_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT8_e2i_event_cnt8_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT8_e2i_event_cnt8_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt9 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT9_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT9_e2i_event_cnt9_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT9_e2i_event_cnt9_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt10 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT10_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT10_e2i_event_cnt10_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT10_e2i_event_cnt10_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt11 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT11_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT11_e2i_event_cnt11_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT11_e2i_event_cnt11_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt12 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT12_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT12_e2i_event_cnt12_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT12_e2i_event_cnt12_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt13 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT13_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT13_e2i_event_cnt13_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT13_e2i_event_cnt13_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt14 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT14_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT14_e2i_event_cnt14_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT14_e2i_event_cnt14_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt15 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT15_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT15_e2i_event_cnt15_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT15_e2i_event_cnt15_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt16 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT16_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT16_e2i_event_cnt16_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT16_e2i_event_cnt16_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt17 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT17_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT17_e2i_event_cnt17_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT17_e2i_event_cnt17_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt18 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT18_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT18_e2i_event_cnt18_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT18_e2i_event_cnt18_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt19 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT19_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT19_e2i_event_cnt19_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT19_e2i_event_cnt19_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt20 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT20_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT20_e2i_event_cnt20_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT20_e2i_event_cnt20_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt21 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT21_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT21_e2i_event_cnt21_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT21_e2i_event_cnt21_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt22 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT22_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT22_e2i_event_cnt22_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT22_e2i_event_cnt22_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt23 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT23_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT23_e2i_event_cnt23_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT23_e2i_event_cnt23_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt24 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT24_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT24_e2i_event_cnt24_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT24_e2i_event_cnt24_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt25 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT25_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT25_e2i_event_cnt25_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT25_e2i_event_cnt25_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt26 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT26_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT26_e2i_event_cnt26_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT26_e2i_event_cnt26_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt27 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT27_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT27_e2i_event_cnt27_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT27_e2i_event_cnt27_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt28 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT28_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT28_e2i_event_cnt28_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT28_e2i_event_cnt28_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt29 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT29_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT29_e2i_event_cnt29_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT29_e2i_event_cnt29_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt30 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT30_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT30_e2i_event_cnt30_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT30_e2i_event_cnt30_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_cnt31 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT31_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT31_e2i_event_cnt31_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_CNT31_e2i_event_cnt31_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_slv_adapter_rcv_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_HTS_SLV_ADAPTER_RCV_EVENT_CNT_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_HTS_SLV_ADAPTER_RCV_EVENT_CNT_hts_slv_adapter_rcv_event_cnt_START (0)
#define SOC_HTS_SLAVE_ADAPTER_HTS_SLV_ADAPTER_RCV_EVENT_CNT_hts_slv_adapter_rcv_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int e2i_event_last_event : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_LAST_EVENT_UNION;
#endif
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_LAST_EVENT_e2i_event_last_event_START (0)
#define SOC_HTS_SLAVE_ADAPTER_E2I_EVENT_LAST_EVENT_e2i_event_last_event_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
