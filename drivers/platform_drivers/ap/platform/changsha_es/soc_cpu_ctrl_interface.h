#ifndef __SOC_CPU_CTRL_INTERFACE_H__
#define __SOC_CPU_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CPU_CTRL_P0_0_ADDR(base) (base)
#define SOC_CPU_CTRL_P0_1_ADDR(base) ((base) + 0x004UL)
#define SOC_CPU_CTRL_P0_2_ADDR(base) ((base) + 0x008UL)
#define SOC_CPU_CTRL_P0_3_ADDR(base) ((base) + 0x00CUL)
#define SOC_CPU_CTRL_P0_4_ADDR(base) ((base) + 0x010UL)
#define SOC_CPU_CTRL_P0_5_ADDR(base) ((base) + 0x014UL)
#define SOC_CPU_CTRL_P0_6_ADDR(base) ((base) + 0x018UL)
#define SOC_CPU_CTRL_P0_7_ADDR(base) ((base) + 0x01CUL)
#define SOC_CPU_CTRL_P0_8_ADDR(base) ((base) + 0x020UL)
#define SOC_CPU_CTRL_P0_9_ADDR(base) ((base) + 0x024UL)
#define SOC_CPU_CTRL_P0_10_ADDR(base) ((base) + 0x028UL)
#define SOC_CPU_CTRL_P0_11_ADDR(base) ((base) + 0x02CUL)
#define SOC_CPU_CTRL_P0_12_ADDR(base) ((base) + 0x030UL)
#define SOC_CPU_CTRL_P0_13_ADDR(base) ((base) + 0x034UL)
#define SOC_CPU_CTRL_P0_14_ADDR(base) ((base) + 0x038UL)
#define SOC_CPU_CTRL_P0_15_ADDR(base) ((base) + 0x03CUL)
#define SOC_CPU_CTRL_P0_16_ADDR(base) ((base) + 0x040UL)
#define SOC_CPU_CTRL_P1_MWC0_ADDR(base) ((base) + 0x400UL)
#define SOC_CPU_CTRL_P1_MSK2_ADDR(base) ((base) + 0x404UL)
#define SOC_CPU_CTRL_P1_MWC2_ADDR(base) ((base) + 0x408UL)
#define SOC_CPU_CTRL_P1_MSK0_ADDR(base) ((base) + 0x40CUL)
#define SOC_CPU_CTRL_P1_MSK1_ADDR(base) ((base) + 0x410UL)
#define SOC_CPU_CTRL_P1_MWC3_ADDR(base) ((base) + 0x414UL)
#define SOC_CPU_CTRL_P1_MWC4_ADDR(base) ((base) + 0x418UL)
#define SOC_CPU_CTRL_P1_MWC5_ADDR(base) ((base) + 0x41CUL)
#define SOC_CPU_CTRL_P1_MWC6_ADDR(base) ((base) + 0x420UL)
#define SOC_CPU_CTRL_P1_MWC7_ADDR(base) ((base) + 0x424UL)
#define SOC_CPU_CTRL_P1_MWC8_ADDR(base) ((base) + 0x428UL)
#define SOC_CPU_CTRL_P1_MWC9_ADDR(base) ((base) + 0x42CUL)
#define SOC_CPU_CTRL_P1_MWC10_ADDR(base) ((base) + 0x430UL)
#define SOC_CPU_CTRL_P1_MWC11_ADDR(base) ((base) + 0x434UL)
#define SOC_CPU_CTRL_P1_MWC12_ADDR(base) ((base) + 0x438UL)
#define SOC_CPU_CTRL_P1_MWC13_ADDR(base) ((base) + 0x43CUL)
#define SOC_CPU_CTRL_P1_MWC14_ADDR(base) ((base) + 0x440UL)
#define SOC_CPU_CTRL_P1_MWC15_ADDR(base) ((base) + 0x444UL)
#define SOC_CPU_CTRL_P1_MWC16_ADDR(base) ((base) + 0x448UL)
#define SOC_CPU_CTRL_P1_MWC17_ADDR(base) ((base) + 0x44CUL)
#define SOC_CPU_CTRL_P1_MWC18_ADDR(base) ((base) + 0x450UL)
#define SOC_CPU_CTRL_P1_MWC19_ADDR(base) ((base) + 0x454UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_0_ADDR(base) ((base) + 0x800UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_1_ADDR(base) ((base) + 0x804UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_2_ADDR(base) ((base) + 0x808UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_3_ADDR(base) ((base) + 0x80CUL)
#define SOC_CPU_CTRL_CPU_STAT_P2_4_ADDR(base) ((base) + 0x810UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_5_ADDR(base) ((base) + 0x814UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_6_ADDR(base) ((base) + 0x818UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_7_ADDR(base) ((base) + 0x81CUL)
#define SOC_CPU_CTRL_CPU_STAT_P2_8_ADDR(base) ((base) + 0x820UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_ADDR(base) ((base) + 0x824UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_10_ADDR(base) ((base) + 0x828UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_11_ADDR(base) ((base) + 0x82CUL)
#define SOC_CPU_CTRL_CPU_STAT_P2_12_ADDR(base) ((base) + 0x830UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_13_ADDR(base) ((base) + 0x834UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_14_ADDR(base) ((base) + 0x838UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_15_ADDR(base) ((base) + 0x83CUL)
#define SOC_CPU_CTRL_CPU_STAT_P2_16_ADDR(base) ((base) + 0x840UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_17_ADDR(base) ((base) + 0x844UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_18_ADDR(base) ((base) + 0x848UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_19_ADDR(base) ((base) + 0x84CUL)
#define SOC_CPU_CTRL_CPU_STAT_P2_20_ADDR(base) ((base) + 0x850UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_21_ADDR(base) ((base) + 0x854UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_22_ADDR(base) ((base) + 0x858UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_23_ADDR(base) ((base) + 0x85CUL)
#define SOC_CPU_CTRL_CPU_STAT_P2_24_ADDR(base) ((base) + 0x860UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_25_ADDR(base) ((base) + 0x864UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_26_ADDR(base) ((base) + 0x868UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_27_ADDR(base) ((base) + 0x86CUL)
#define SOC_CPU_CTRL_CPU_STAT_P2_28_ADDR(base) ((base) + 0x870UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_29_ADDR(base) ((base) + 0x874UL)
#define SOC_CPU_CTRL_CPU_STAT_P2_30_ADDR(base) ((base) + 0x878UL)
#define SOC_CPU_CTRL_P3_0_ADDR(base) ((base) + 0xC00UL)
#define SOC_CPU_CTRL_P3_1_ADDR(base) ((base) + 0xC04UL)
#define SOC_CPU_CTRL_P3_2_ADDR(base) ((base) + 0xC08UL)
#define SOC_CPU_CTRL_P3_3_ADDR(base) ((base) + 0xC0CUL)
#define SOC_CPU_CTRL_P3_4_ADDR(base) ((base) + 0xC10UL)
#define SOC_CPU_CTRL_P3_5_ADDR(base) ((base) + 0xC14UL)
#define SOC_CPU_CTRL_P3_6_ADDR(base) ((base) + 0xC18UL)
#define SOC_CPU_CTRL_P3_7_ADDR(base) ((base) + 0xC1CUL)
#define SOC_CPU_CTRL_CPU_STAT_P3_8_ADDR(base) ((base) + 0xC20UL)
#define SOC_CPU_CTRL_P4_0_SET_ADDR(base) ((base) + 0xFE0UL)
#define SOC_CPU_CTRL_P4_1_CLR_ADDR(base) ((base) + 0xFE4UL)
#define SOC_CPU_CTRL_P4_2_STA_ADDR(base) ((base) + 0xFE8UL)
#define SOC_CPU_CTRL_P4_3_ADDR(base) ((base) + 0xFECUL)
#define SOC_CPU_CTRL_P4_4_ADDR(base) ((base) + 0xFF0UL)
#define SOC_CPU_CTRL_P4_5_ADDR(base) ((base) + 0xFF4UL)
#define SOC_CPU_CTRL_P4_6_ADDR(base) ((base) + 0xFF8UL)
#define SOC_CPU_CTRL_LOCK_ADDR(base) ((base) + 0xFFCUL)
#else
#define SOC_CPU_CTRL_P0_0_ADDR(base) (base)
#define SOC_CPU_CTRL_P0_1_ADDR(base) ((base) + 0x004)
#define SOC_CPU_CTRL_P0_2_ADDR(base) ((base) + 0x008)
#define SOC_CPU_CTRL_P0_3_ADDR(base) ((base) + 0x00C)
#define SOC_CPU_CTRL_P0_4_ADDR(base) ((base) + 0x010)
#define SOC_CPU_CTRL_P0_5_ADDR(base) ((base) + 0x014)
#define SOC_CPU_CTRL_P0_6_ADDR(base) ((base) + 0x018)
#define SOC_CPU_CTRL_P0_7_ADDR(base) ((base) + 0x01C)
#define SOC_CPU_CTRL_P0_8_ADDR(base) ((base) + 0x020)
#define SOC_CPU_CTRL_P0_9_ADDR(base) ((base) + 0x024)
#define SOC_CPU_CTRL_P0_10_ADDR(base) ((base) + 0x028)
#define SOC_CPU_CTRL_P0_11_ADDR(base) ((base) + 0x02C)
#define SOC_CPU_CTRL_P0_12_ADDR(base) ((base) + 0x030)
#define SOC_CPU_CTRL_P0_13_ADDR(base) ((base) + 0x034)
#define SOC_CPU_CTRL_P0_14_ADDR(base) ((base) + 0x038)
#define SOC_CPU_CTRL_P0_15_ADDR(base) ((base) + 0x03C)
#define SOC_CPU_CTRL_P0_16_ADDR(base) ((base) + 0x040)
#define SOC_CPU_CTRL_P1_MWC0_ADDR(base) ((base) + 0x400)
#define SOC_CPU_CTRL_P1_MSK2_ADDR(base) ((base) + 0x404)
#define SOC_CPU_CTRL_P1_MWC2_ADDR(base) ((base) + 0x408)
#define SOC_CPU_CTRL_P1_MSK0_ADDR(base) ((base) + 0x40C)
#define SOC_CPU_CTRL_P1_MSK1_ADDR(base) ((base) + 0x410)
#define SOC_CPU_CTRL_P1_MWC3_ADDR(base) ((base) + 0x414)
#define SOC_CPU_CTRL_P1_MWC4_ADDR(base) ((base) + 0x418)
#define SOC_CPU_CTRL_P1_MWC5_ADDR(base) ((base) + 0x41C)
#define SOC_CPU_CTRL_P1_MWC6_ADDR(base) ((base) + 0x420)
#define SOC_CPU_CTRL_P1_MWC7_ADDR(base) ((base) + 0x424)
#define SOC_CPU_CTRL_P1_MWC8_ADDR(base) ((base) + 0x428)
#define SOC_CPU_CTRL_P1_MWC9_ADDR(base) ((base) + 0x42C)
#define SOC_CPU_CTRL_P1_MWC10_ADDR(base) ((base) + 0x430)
#define SOC_CPU_CTRL_P1_MWC11_ADDR(base) ((base) + 0x434)
#define SOC_CPU_CTRL_P1_MWC12_ADDR(base) ((base) + 0x438)
#define SOC_CPU_CTRL_P1_MWC13_ADDR(base) ((base) + 0x43C)
#define SOC_CPU_CTRL_P1_MWC14_ADDR(base) ((base) + 0x440)
#define SOC_CPU_CTRL_P1_MWC15_ADDR(base) ((base) + 0x444)
#define SOC_CPU_CTRL_P1_MWC16_ADDR(base) ((base) + 0x448)
#define SOC_CPU_CTRL_P1_MWC17_ADDR(base) ((base) + 0x44C)
#define SOC_CPU_CTRL_P1_MWC18_ADDR(base) ((base) + 0x450)
#define SOC_CPU_CTRL_P1_MWC19_ADDR(base) ((base) + 0x454)
#define SOC_CPU_CTRL_CPU_STAT_P2_0_ADDR(base) ((base) + 0x800)
#define SOC_CPU_CTRL_CPU_STAT_P2_1_ADDR(base) ((base) + 0x804)
#define SOC_CPU_CTRL_CPU_STAT_P2_2_ADDR(base) ((base) + 0x808)
#define SOC_CPU_CTRL_CPU_STAT_P2_3_ADDR(base) ((base) + 0x80C)
#define SOC_CPU_CTRL_CPU_STAT_P2_4_ADDR(base) ((base) + 0x810)
#define SOC_CPU_CTRL_CPU_STAT_P2_5_ADDR(base) ((base) + 0x814)
#define SOC_CPU_CTRL_CPU_STAT_P2_6_ADDR(base) ((base) + 0x818)
#define SOC_CPU_CTRL_CPU_STAT_P2_7_ADDR(base) ((base) + 0x81C)
#define SOC_CPU_CTRL_CPU_STAT_P2_8_ADDR(base) ((base) + 0x820)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_ADDR(base) ((base) + 0x824)
#define SOC_CPU_CTRL_CPU_STAT_P2_10_ADDR(base) ((base) + 0x828)
#define SOC_CPU_CTRL_CPU_STAT_P2_11_ADDR(base) ((base) + 0x82C)
#define SOC_CPU_CTRL_CPU_STAT_P2_12_ADDR(base) ((base) + 0x830)
#define SOC_CPU_CTRL_CPU_STAT_P2_13_ADDR(base) ((base) + 0x834)
#define SOC_CPU_CTRL_CPU_STAT_P2_14_ADDR(base) ((base) + 0x838)
#define SOC_CPU_CTRL_CPU_STAT_P2_15_ADDR(base) ((base) + 0x83C)
#define SOC_CPU_CTRL_CPU_STAT_P2_16_ADDR(base) ((base) + 0x840)
#define SOC_CPU_CTRL_CPU_STAT_P2_17_ADDR(base) ((base) + 0x844)
#define SOC_CPU_CTRL_CPU_STAT_P2_18_ADDR(base) ((base) + 0x848)
#define SOC_CPU_CTRL_CPU_STAT_P2_19_ADDR(base) ((base) + 0x84C)
#define SOC_CPU_CTRL_CPU_STAT_P2_20_ADDR(base) ((base) + 0x850)
#define SOC_CPU_CTRL_CPU_STAT_P2_21_ADDR(base) ((base) + 0x854)
#define SOC_CPU_CTRL_CPU_STAT_P2_22_ADDR(base) ((base) + 0x858)
#define SOC_CPU_CTRL_CPU_STAT_P2_23_ADDR(base) ((base) + 0x85C)
#define SOC_CPU_CTRL_CPU_STAT_P2_24_ADDR(base) ((base) + 0x860)
#define SOC_CPU_CTRL_CPU_STAT_P2_25_ADDR(base) ((base) + 0x864)
#define SOC_CPU_CTRL_CPU_STAT_P2_26_ADDR(base) ((base) + 0x868)
#define SOC_CPU_CTRL_CPU_STAT_P2_27_ADDR(base) ((base) + 0x86C)
#define SOC_CPU_CTRL_CPU_STAT_P2_28_ADDR(base) ((base) + 0x870)
#define SOC_CPU_CTRL_CPU_STAT_P2_29_ADDR(base) ((base) + 0x874)
#define SOC_CPU_CTRL_CPU_STAT_P2_30_ADDR(base) ((base) + 0x878)
#define SOC_CPU_CTRL_P3_0_ADDR(base) ((base) + 0xC00)
#define SOC_CPU_CTRL_P3_1_ADDR(base) ((base) + 0xC04)
#define SOC_CPU_CTRL_P3_2_ADDR(base) ((base) + 0xC08)
#define SOC_CPU_CTRL_P3_3_ADDR(base) ((base) + 0xC0C)
#define SOC_CPU_CTRL_P3_4_ADDR(base) ((base) + 0xC10)
#define SOC_CPU_CTRL_P3_5_ADDR(base) ((base) + 0xC14)
#define SOC_CPU_CTRL_P3_6_ADDR(base) ((base) + 0xC18)
#define SOC_CPU_CTRL_P3_7_ADDR(base) ((base) + 0xC1C)
#define SOC_CPU_CTRL_CPU_STAT_P3_8_ADDR(base) ((base) + 0xC20)
#define SOC_CPU_CTRL_P4_0_SET_ADDR(base) ((base) + 0xFE0)
#define SOC_CPU_CTRL_P4_1_CLR_ADDR(base) ((base) + 0xFE4)
#define SOC_CPU_CTRL_P4_2_STA_ADDR(base) ((base) + 0xFE8)
#define SOC_CPU_CTRL_P4_3_ADDR(base) ((base) + 0xFEC)
#define SOC_CPU_CTRL_P4_4_ADDR(base) ((base) + 0xFF0)
#define SOC_CPU_CTRL_P4_5_ADDR(base) ((base) + 0xFF4)
#define SOC_CPU_CTRL_P4_6_ADDR(base) ((base) + 0xFF8)
#define SOC_CPU_CTRL_LOCK_ADDR(base) ((base) + 0xFFC)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ctrl_rsv0 : 32;
    } reg;
} SOC_CPU_CTRL_P0_0_UNION;
#endif
#define SOC_CPU_CTRL_P0_0_cpu_ctrl_rsv0_START (0)
#define SOC_CPU_CTRL_P0_0_cpu_ctrl_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 20;
        unsigned int reserved_2: 4;
    } reg;
} SOC_CPU_CTRL_P0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 20;
        unsigned int reserved_2: 4;
    } reg;
} SOC_CPU_CTRL_P0_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 12;
        unsigned int reserved_1: 12;
        unsigned int reserved_2: 8;
    } reg;
} SOC_CPU_CTRL_P0_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_div_x2j_mux : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_CPU_CTRL_P0_4_UNION;
#endif
#define SOC_CPU_CTRL_P0_4_sc_div_x2j_mux_START (0)
#define SOC_CPU_CTRL_P0_4_sc_div_x2j_mux_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mux_sel0 : 5;
        unsigned int nopending_mux_sel1 : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_CTRL_P0_5_UNION;
#endif
#define SOC_CPU_CTRL_P0_5_nopending_mux_sel0_START (0)
#define SOC_CPU_CTRL_P0_5_nopending_mux_sel0_END (4)
#define SOC_CPU_CTRL_P0_5_nopending_mux_sel1_START (5)
#define SOC_CPU_CTRL_P0_5_nopending_mux_sel1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int testpoint_subchip_sel : 3;
        unsigned int intr_qic_mux_sel : 5;
        unsigned int idlereq_mux_sel1 : 1;
        unsigned int idleack_mux_sel1 : 1;
        unsigned int idlereq_mux_sel0 : 3;
        unsigned int idleack_mux_sel0 : 3;
        unsigned int reserved_0 : 2;
        unsigned int busy_mux_sel : 4;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 3;
    } reg;
} SOC_CPU_CTRL_P0_6_UNION;
#endif
#define SOC_CPU_CTRL_P0_6_testpoint_subchip_sel_START (0)
#define SOC_CPU_CTRL_P0_6_testpoint_subchip_sel_END (2)
#define SOC_CPU_CTRL_P0_6_intr_qic_mux_sel_START (3)
#define SOC_CPU_CTRL_P0_6_intr_qic_mux_sel_END (7)
#define SOC_CPU_CTRL_P0_6_idlereq_mux_sel1_START (8)
#define SOC_CPU_CTRL_P0_6_idlereq_mux_sel1_END (8)
#define SOC_CPU_CTRL_P0_6_idleack_mux_sel1_START (9)
#define SOC_CPU_CTRL_P0_6_idleack_mux_sel1_END (9)
#define SOC_CPU_CTRL_P0_6_idlereq_mux_sel0_START (10)
#define SOC_CPU_CTRL_P0_6_idlereq_mux_sel0_END (12)
#define SOC_CPU_CTRL_P0_6_idleack_mux_sel0_START (13)
#define SOC_CPU_CTRL_P0_6_idleack_mux_sel0_END (15)
#define SOC_CPU_CTRL_P0_6_busy_mux_sel_START (18)
#define SOC_CPU_CTRL_P0_6_busy_mux_sel_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idlereq_mask : 16;
        unsigned int idleack_mask : 16;
    } reg;
} SOC_CPU_CTRL_P0_7_UNION;
#endif
#define SOC_CPU_CTRL_P0_7_idlereq_mask_START (0)
#define SOC_CPU_CTRL_P0_7_idlereq_mask_END (15)
#define SOC_CPU_CTRL_P0_7_idleack_mask_START (16)
#define SOC_CPU_CTRL_P0_7_idleack_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int busy_mask : 32;
    } reg;
} SOC_CPU_CTRL_P0_8_UNION;
#endif
#define SOC_CPU_CTRL_P0_8_busy_mask_START (0)
#define SOC_CPU_CTRL_P0_8_busy_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mask0 : 32;
    } reg;
} SOC_CPU_CTRL_P0_9_UNION;
#endif
#define SOC_CPU_CTRL_P0_9_nopending_mask0_START (0)
#define SOC_CPU_CTRL_P0_9_nopending_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_mask1 : 32;
    } reg;
} SOC_CPU_CTRL_P0_10_UNION;
#endif
#define SOC_CPU_CTRL_P0_10_nopending_mask1_START (0)
#define SOC_CPU_CTRL_P0_10_nopending_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_mask : 32;
    } reg;
} SOC_CPU_CTRL_P0_11_UNION;
#endif
#define SOC_CPU_CTRL_P0_11_intr_qic_mask_START (0)
#define SOC_CPU_CTRL_P0_11_intr_qic_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcmxctrl_nopending_bypass : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_CPU_CTRL_P0_12_UNION;
#endif
#define SOC_CPU_CTRL_P0_12_fcmxctrl_nopending_bypass_START (0)
#define SOC_CPU_CTRL_P0_12_fcmxctrl_nopending_bypass_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P0_13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P0_14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P0_15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P0_16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_nopending_bypass0 : 1;
        unsigned int qice_nopending_bypass1 : 1;
        unsigned int reserved : 14;
        unsigned int CPU_CTRL_P1_MSK2 : 16;
    } reg;
} SOC_CPU_CTRL_P1_MSK2_UNION;
#endif
#define SOC_CPU_CTRL_P1_MSK2_qice_nopending_bypass0_START (0)
#define SOC_CPU_CTRL_P1_MSK2_qice_nopending_bypass0_END (0)
#define SOC_CPU_CTRL_P1_MSK2_qice_nopending_bypass1_START (1)
#define SOC_CPU_CTRL_P1_MSK2_qice_nopending_bypass1_END (1)
#define SOC_CPU_CTRL_P1_MSK2_CPU_CTRL_P1_MSK2_START (16)
#define SOC_CPU_CTRL_P1_MSK2_CPU_CTRL_P1_MSK2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_cpu2sys : 1;
        unsigned int qic_timeout_en : 1;
        unsigned int cpu_pp_timeout_en : 1;
        unsigned int qic_timeout_en_cfg2fcm : 1;
        unsigned int reserved : 12;
        unsigned int CPU_CTRL_P1_MSK0 : 16;
    } reg;
} SOC_CPU_CTRL_P1_MSK0_UNION;
#endif
#define SOC_CPU_CTRL_P1_MSK0_qic_timeout_en_cpu2sys_START (0)
#define SOC_CPU_CTRL_P1_MSK0_qic_timeout_en_cpu2sys_END (0)
#define SOC_CPU_CTRL_P1_MSK0_qic_timeout_en_START (1)
#define SOC_CPU_CTRL_P1_MSK0_qic_timeout_en_END (1)
#define SOC_CPU_CTRL_P1_MSK0_cpu_pp_timeout_en_START (2)
#define SOC_CPU_CTRL_P1_MSK0_cpu_pp_timeout_en_END (2)
#define SOC_CPU_CTRL_P1_MSK0_qic_timeout_en_cfg2fcm_START (3)
#define SOC_CPU_CTRL_P1_MSK0_qic_timeout_en_cfg2fcm_END (3)
#define SOC_CPU_CTRL_P1_MSK0_CPU_CTRL_P1_MSK0_START (16)
#define SOC_CPU_CTRL_P1_MSK0_CPU_CTRL_P1_MSK0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysbus_t_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int cpu_pmc_clkgt_bypass : 1;
        unsigned int reserved_1 : 13;
        unsigned int CPU_CTRL_P1_MSK1 : 16;
    } reg;
} SOC_CPU_CTRL_P1_MSK1_UNION;
#endif
#define SOC_CPU_CTRL_P1_MSK1_sysbus_t_bypass_START (0)
#define SOC_CPU_CTRL_P1_MSK1_sysbus_t_bypass_END (0)
#define SOC_CPU_CTRL_P1_MSK1_cpu_pmc_clkgt_bypass_START (2)
#define SOC_CPU_CTRL_P1_MSK1_cpu_pmc_clkgt_bypass_END (2)
#define SOC_CPU_CTRL_P1_MSK1_CPU_CTRL_P1_MSK1_START (16)
#define SOC_CPU_CTRL_P1_MSK1_CPU_CTRL_P1_MSK1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_nopending_rt_fcm_qic_rsp : 1;
        unsigned int wc_qic_nopending_rt_fcm_qic_req : 1;
        unsigned int wc_qic_nopending_tb_cpu_bus_qcp : 1;
        unsigned int wc_qic_nopending_tb_gic_cfg : 1;
        unsigned int wc_qic_nopending_tb_fcm_lpctrlslv : 1;
        unsigned int wc_qic_nopending_tb_fcm_cfg : 1;
        unsigned int wc_qic_nopending_tb_fcm2sys : 1;
        unsigned int wc_qic_nopending_ib_wr_peri_port : 1;
        unsigned int wc_qic_nopending_ib_rd_peri_port : 1;
        unsigned int wc_qic_nopending_ib_wr_gic_mst : 1;
        unsigned int wc_qic_nopending_ib_rd_gic_mst : 1;
        unsigned int wc_qic_nopending_ib_wr_fcm_lpctrlmst : 1;
        unsigned int wc_qic_nopending_ib_rd_fcm_lpctrlmst : 1;
        unsigned int wc_qic_nopending_ib_wr_cfg2fcm : 1;
        unsigned int wc_qic_nopending_ib_rd_cfg2fcm : 1;
        unsigned int wc_qic_nopending_wr_ib_cpu_rtm_mst : 1;
        unsigned int wc_qic_nopending_rd_ib_cpu_rtm_mst : 1;
        unsigned int wc_qic_nopending_rt_qcp_req : 1;
        unsigned int wc_qic_nopending_rt_qcp_rsp : 1;
        unsigned int wc_qic_nopending_rt_fw_tb_qcp_rsp : 1;
        unsigned int wc_qic_nopending_rt_fw_tb_qcp_req : 1;
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
    } reg;
} SOC_CPU_CTRL_P1_MWC3_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fcm_qic_rsp_START (0)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fcm_qic_rsp_END (0)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fcm_qic_req_START (1)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fcm_qic_req_END (1)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_cpu_bus_qcp_START (2)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_cpu_bus_qcp_END (2)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_gic_cfg_START (3)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_gic_cfg_END (3)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_fcm_lpctrlslv_START (4)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_fcm_lpctrlslv_END (4)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_fcm_cfg_START (5)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_fcm_cfg_END (5)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_fcm2sys_START (6)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_tb_fcm2sys_END (6)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_peri_port_START (7)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_peri_port_END (7)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_peri_port_START (8)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_peri_port_END (8)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_gic_mst_START (9)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_gic_mst_END (9)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_gic_mst_START (10)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_gic_mst_END (10)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_fcm_lpctrlmst_START (11)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_fcm_lpctrlmst_END (11)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_fcm_lpctrlmst_START (12)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_fcm_lpctrlmst_END (12)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_cfg2fcm_START (13)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_wr_cfg2fcm_END (13)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_cfg2fcm_START (14)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_ib_rd_cfg2fcm_END (14)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_wr_ib_cpu_rtm_mst_START (15)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_wr_ib_cpu_rtm_mst_END (15)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rd_ib_cpu_rtm_mst_START (16)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rd_ib_cpu_rtm_mst_END (16)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_qcp_req_START (17)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_qcp_req_END (17)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_qcp_rsp_START (18)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_qcp_rsp_END (18)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fw_tb_qcp_rsp_START (19)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fw_tb_qcp_rsp_END (19)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fw_tb_qcp_req_START (20)
#define SOC_CPU_CTRL_P1_MWC3_wc_qic_nopending_rt_fw_tb_qcp_req_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_trans_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC4_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC4_wc_intr_trans_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC4_wc_intr_trans_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_err_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC5_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC5_wc_intr_err_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC5_wc_intr_err_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_safety_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC6_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC6_wc_intr_safety_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC6_wc_intr_safety_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_safety_err_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC7_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC7_wc_intr_safety_err_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC7_wc_intr_safety_err_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_qic_timeout_st_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC8_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC8_wc_qic_timeout_st_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC8_wc_qic_timeout_st_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_ca_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC9_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC9_wc_intr_ca_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC9_wc_intr_ca_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_em_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC10_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC10_wc_intr_em_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC10_wc_intr_em_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_intr_qic_probe_fcm_bus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_CTRL_P1_MWC11_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC11_wc_intr_qic_probe_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC11_wc_intr_qic_probe_fcm_bus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wc_dfx_busy_ca_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC12_UNION;
#endif
#define SOC_CPU_CTRL_P1_MWC12_wc_dfx_busy_ca_fcm_bus_START (0)
#define SOC_CPU_CTRL_P1_MWC12_wc_dfx_busy_ca_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P1_MWC19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ccf_nopending_0 : 1;
        unsigned int ccf_nopending_1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_7_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_7_ccf_nopending_0_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_7_ccf_nopending_0_END (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_7_ccf_nopending_1_START (1)
#define SOC_CPU_CTRL_CPU_STAT_P2_7_ccf_nopending_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_stat_rsv0 : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_8_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_8_cpu_stat_rsv0_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_8_cpu_stat_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_nopending_rt_fcm_qic_rsp : 1;
        unsigned int qic_nopending_rt_fcm_qic_req : 1;
        unsigned int qic_nopending_tb_cpu_bus_qcp : 1;
        unsigned int qic_nopending_tb_gic_cfg : 1;
        unsigned int qic_nopending_tb_fcm_lpctrlslv : 1;
        unsigned int qic_nopending_tb_fcm_cfg : 1;
        unsigned int qic_nopending_tb_fcm2sys : 1;
        unsigned int qic_nopending_ib_wr_peri_port : 1;
        unsigned int qic_nopending_ib_rd_peri_port : 1;
        unsigned int qic_nopending_ib_wr_gic_mst : 1;
        unsigned int qic_nopending_ib_rd_gic_mst : 1;
        unsigned int qic_nopending_ib_wr_lpctrlmst : 1;
        unsigned int qic_nopending_ib_rd_lpctrlmst : 1;
        unsigned int qic_nopending_ib_wr_cfg2fcm : 1;
        unsigned int qic_nopending_ib_rd_cfg2fcm : 1;
        unsigned int qic_nopending_wr_ib_cpu_rtm_mst : 1;
        unsigned int qic_nopending_rd_ib_cpu_rtm_mst : 1;
        unsigned int qic_nopending_rt_qcp_req : 1;
        unsigned int qic_nopending_rt_qcp_rsp : 1;
        unsigned int qic_nopending_rt_fw_tb_qcp_rsp : 1;
        unsigned int qic_nopending_rt_fw_tb_qcp_req : 1;
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
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_9_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fcm_qic_rsp_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fcm_qic_rsp_END (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fcm_qic_req_START (1)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fcm_qic_req_END (1)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_cpu_bus_qcp_START (2)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_cpu_bus_qcp_END (2)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_gic_cfg_START (3)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_gic_cfg_END (3)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_fcm_lpctrlslv_START (4)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_fcm_lpctrlslv_END (4)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_fcm_cfg_START (5)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_fcm_cfg_END (5)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_fcm2sys_START (6)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_tb_fcm2sys_END (6)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_peri_port_START (7)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_peri_port_END (7)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_peri_port_START (8)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_peri_port_END (8)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_gic_mst_START (9)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_gic_mst_END (9)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_gic_mst_START (10)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_gic_mst_END (10)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_lpctrlmst_START (11)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_lpctrlmst_END (11)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_lpctrlmst_START (12)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_lpctrlmst_END (12)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_cfg2fcm_START (13)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_wr_cfg2fcm_END (13)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_cfg2fcm_START (14)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_ib_rd_cfg2fcm_END (14)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_wr_ib_cpu_rtm_mst_START (15)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_wr_ib_cpu_rtm_mst_END (15)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rd_ib_cpu_rtm_mst_START (16)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rd_ib_cpu_rtm_mst_END (16)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_qcp_req_START (17)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_qcp_req_END (17)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_qcp_rsp_START (18)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_qcp_rsp_END (18)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fw_tb_qcp_rsp_START (19)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fw_tb_qcp_rsp_END (19)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fw_tb_qcp_req_START (20)
#define SOC_CPU_CTRL_CPU_STAT_P2_9_qic_nopending_rt_fw_tb_qcp_req_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_trans_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_10_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_10_intr_trans_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_10_intr_trans_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_err_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_11_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_11_intr_err_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_11_intr_err_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_safety_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_12_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_12_intr_safety_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_12_intr_safety_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_safety_err_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_13_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_13_intr_safety_err_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_13_intr_safety_err_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_14_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_14_qic_timeout_st_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_14_qic_timeout_st_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qic_probe_fcm_bus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_17_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_17_intr_qic_probe_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_17_intr_qic_probe_fcm_bus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_ca_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_18_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_18_intr_ca_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_18_intr_ca_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_busy_ca_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_19_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_19_dfx_busy_ca_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_19_dfx_busy_ca_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_em_fcm_bus : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_21_UNION;
#endif
#define SOC_CPU_CTRL_CPU_STAT_P2_21_intr_em_fcm_bus_START (0)
#define SOC_CPU_CTRL_CPU_STAT_P2_21_intr_em_fcm_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_24_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_25_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_29_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P2_30_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_subchip_mem_sdo : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_CTRL_P3_0_UNION;
#endif
#define SOC_CPU_CTRL_P3_0_cpu_subchip_mem_sdo_START (0)
#define SOC_CPU_CTRL_P3_0_cpu_subchip_mem_sdo_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_rtm_xsecure_n : 1;
        unsigned int cpu_subchip_mem_sd : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_CTRL_P3_1_UNION;
#endif
#define SOC_CPU_CTRL_P3_1_cpu_rtm_xsecure_n_START (0)
#define SOC_CPU_CTRL_P3_1_cpu_rtm_xsecure_n_END (0)
#define SOC_CPU_CTRL_P3_1_cpu_subchip_mem_sd_START (1)
#define SOC_CPU_CTRL_P3_1_cpu_subchip_mem_sd_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_gic_mst_icfg_awvcidx_ddr : 8;
        unsigned int ib_gic_mst_icfg_awvcidx_device : 8;
        unsigned int ib_gic_mst_icfg_arvcidx_ddr : 8;
        unsigned int ib_gic_mst_icfg_arvcidx_device : 8;
    } reg;
} SOC_CPU_CTRL_P3_2_UNION;
#endif
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_awvcidx_ddr_START (0)
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_awvcidx_ddr_END (7)
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_awvcidx_device_START (8)
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_awvcidx_device_END (15)
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_arvcidx_ddr_START (16)
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_arvcidx_ddr_END (23)
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_arvcidx_device_START (24)
#define SOC_CPU_CTRL_P3_2_ib_gic_mst_icfg_arvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_cpu_rtm_mst_icfg_awvcidx_ddr : 8;
        unsigned int ib_cpu_rtm_mst_icfg_awvcidx_device : 8;
        unsigned int ib_cpu_rtm_mst_icfg_arvcidx_ddr : 8;
        unsigned int ib_cpu_rtm_mst_icfg_arvcidx_device : 8;
    } reg;
} SOC_CPU_CTRL_P3_3_UNION;
#endif
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_awvcidx_ddr_START (0)
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_awvcidx_ddr_END (7)
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_awvcidx_device_START (8)
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_awvcidx_device_END (15)
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_arvcidx_ddr_START (16)
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_arvcidx_ddr_END (23)
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_arvcidx_device_START (24)
#define SOC_CPU_CTRL_P3_3_ib_cpu_rtm_mst_icfg_arvcidx_device_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fc_secure_user0 : 8;
        unsigned int fc_secure_user1 : 8;
        unsigned int fc_secure_user2 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CPU_CTRL_P3_4_UNION;
#endif
#define SOC_CPU_CTRL_P3_4_fc_secure_user0_START (0)
#define SOC_CPU_CTRL_P3_4_fc_secure_user0_END (7)
#define SOC_CPU_CTRL_P3_4_fc_secure_user1_START (8)
#define SOC_CPU_CTRL_P3_4_fc_secure_user1_END (15)
#define SOC_CPU_CTRL_P3_4_fc_secure_user2_START (16)
#define SOC_CPU_CTRL_P3_4_fc_secure_user2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P3_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P3_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_CTRL_P3_7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 30;
    } reg;
} SOC_CPU_CTRL_CPU_STAT_P3_8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_sec_flag_rt_fw_tb_qcp_set : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_CPU_CTRL_P4_0_SET_UNION;
#endif
#define SOC_CPU_CTRL_P4_0_SET_qic_sec_flag_rt_fw_tb_qcp_set_START (0)
#define SOC_CPU_CTRL_P4_0_SET_qic_sec_flag_rt_fw_tb_qcp_set_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_sec_flag_rt_fw_tb_qcp_clr : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_CPU_CTRL_P4_1_CLR_UNION;
#endif
#define SOC_CPU_CTRL_P4_1_CLR_qic_sec_flag_rt_fw_tb_qcp_clr_START (0)
#define SOC_CPU_CTRL_P4_1_CLR_qic_sec_flag_rt_fw_tb_qcp_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_sec_flag_rt_fw_tb_qcp : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_CPU_CTRL_P4_2_STA_UNION;
#endif
#define SOC_CPU_CTRL_P4_2_STA_qic_sec_flag_rt_fw_tb_qcp_START (0)
#define SOC_CPU_CTRL_P4_2_STA_qic_sec_flag_rt_fw_tb_qcp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 30;
    } reg;
} SOC_CPU_CTRL_P4_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 30;
    } reg;
} SOC_CPU_CTRL_P4_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_CPU_CTRL_P4_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 28;
    } reg;
} SOC_CPU_CTRL_P4_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 32;
    } reg;
} SOC_CPU_CTRL_LOCK_UNION;
#endif
#define SOC_CPU_CTRL_LOCK_lock_START (0)
#define SOC_CPU_CTRL_LOCK_lock_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
