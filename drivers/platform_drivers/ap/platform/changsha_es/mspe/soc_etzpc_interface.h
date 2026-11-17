#ifndef __SOC_ETZPC_INTERFACE_H__
#define __SOC_ETZPC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ETZPC_R0SIZE_ADDR(base) (base)
#define SOC_ETZPC_DECPROT0STAT_ADDR(base) ((base) + 0x800UL)
#define SOC_ETZPC_DECPROT0SET_ADDR(base) ((base) + 0x804UL)
#define SOC_ETZPC_DECPROT0CLR_ADDR(base) ((base) + 0x808UL)
#define SOC_ETZPC_DECPROT1STAT_ADDR(base) ((base) + 0x80CUL)
#define SOC_ETZPC_DECPROT1SET_ADDR(base) ((base) + 0x810UL)
#define SOC_ETZPC_DECPROT1CLR_ADDR(base) ((base) + 0x814UL)
#define SOC_ETZPC_DECPROT2STAT_ADDR(base) ((base) + 0x818UL)
#define SOC_ETZPC_DECPROT2SET_ADDR(base) ((base) + 0x81CUL)
#define SOC_ETZPC_DECPROT2CLR_ADDR(base) ((base) + 0x820UL)
#define SOC_ETZPC_DECPROT3STAT_ADDR(base) ((base) + 0x824UL)
#define SOC_ETZPC_DECPROT3SET_ADDR(base) ((base) + 0x828UL)
#define SOC_ETZPC_DECPROT3CLR_ADDR(base) ((base) + 0x82CUL)
#define SOC_ETZPC_DECPROT4STAT_ADDR(base) ((base) + 0x830UL)
#define SOC_ETZPC_DECPROT4SET_ADDR(base) ((base) + 0x834UL)
#define SOC_ETZPC_DECPROT4CLR_ADDR(base) ((base) + 0x838UL)
#define SOC_ETZPC_DECPROT5STAT_ADDR(base) ((base) + 0x83CUL)
#define SOC_ETZPC_DECPROT5SET_ADDR(base) ((base) + 0x840UL)
#define SOC_ETZPC_DECPROT5CLR_ADDR(base) ((base) + 0x844UL)
#define SOC_ETZPC_DECPROT6STAT_ADDR(base) ((base) + 0x848UL)
#define SOC_ETZPC_DECPROT6SET_ADDR(base) ((base) + 0x84CUL)
#define SOC_ETZPC_DECPROT6CLR_ADDR(base) ((base) + 0x850UL)
#define SOC_ETZPC_DECPROT7STAT_ADDR(base) ((base) + 0x854UL)
#define SOC_ETZPC_DECPROT7SET_ADDR(base) ((base) + 0x858UL)
#define SOC_ETZPC_DECPROT7CLR_ADDR(base) ((base) + 0x85CUL)
#define SOC_ETZPC_DECPROT8STAT_ADDR(base) ((base) + 0x860UL)
#define SOC_ETZPC_DECPROT8SET_ADDR(base) ((base) + 0x864UL)
#define SOC_ETZPC_DECPROT8CLR_ADDR(base) ((base) + 0x868UL)
#define SOC_ETZPC_REG0_STAT_ADDR(base) ((base) + 0x86CUL)
#define SOC_ETZPC_REG1_STAT_ADDR(base) ((base) + 0x870UL)
#define SOC_ETZPC_PERI_LOCK_ADDR(base) ((base) + 0xF00UL)
#else
#define SOC_ETZPC_R0SIZE_ADDR(base) (base)
#define SOC_ETZPC_DECPROT0STAT_ADDR(base) ((base) + 0x800)
#define SOC_ETZPC_DECPROT0SET_ADDR(base) ((base) + 0x804)
#define SOC_ETZPC_DECPROT0CLR_ADDR(base) ((base) + 0x808)
#define SOC_ETZPC_DECPROT1STAT_ADDR(base) ((base) + 0x80C)
#define SOC_ETZPC_DECPROT1SET_ADDR(base) ((base) + 0x810)
#define SOC_ETZPC_DECPROT1CLR_ADDR(base) ((base) + 0x814)
#define SOC_ETZPC_DECPROT2STAT_ADDR(base) ((base) + 0x818)
#define SOC_ETZPC_DECPROT2SET_ADDR(base) ((base) + 0x81C)
#define SOC_ETZPC_DECPROT2CLR_ADDR(base) ((base) + 0x820)
#define SOC_ETZPC_DECPROT3STAT_ADDR(base) ((base) + 0x824)
#define SOC_ETZPC_DECPROT3SET_ADDR(base) ((base) + 0x828)
#define SOC_ETZPC_DECPROT3CLR_ADDR(base) ((base) + 0x82C)
#define SOC_ETZPC_DECPROT4STAT_ADDR(base) ((base) + 0x830)
#define SOC_ETZPC_DECPROT4SET_ADDR(base) ((base) + 0x834)
#define SOC_ETZPC_DECPROT4CLR_ADDR(base) ((base) + 0x838)
#define SOC_ETZPC_DECPROT5STAT_ADDR(base) ((base) + 0x83C)
#define SOC_ETZPC_DECPROT5SET_ADDR(base) ((base) + 0x840)
#define SOC_ETZPC_DECPROT5CLR_ADDR(base) ((base) + 0x844)
#define SOC_ETZPC_DECPROT6STAT_ADDR(base) ((base) + 0x848)
#define SOC_ETZPC_DECPROT6SET_ADDR(base) ((base) + 0x84C)
#define SOC_ETZPC_DECPROT6CLR_ADDR(base) ((base) + 0x850)
#define SOC_ETZPC_DECPROT7STAT_ADDR(base) ((base) + 0x854)
#define SOC_ETZPC_DECPROT7SET_ADDR(base) ((base) + 0x858)
#define SOC_ETZPC_DECPROT7CLR_ADDR(base) ((base) + 0x85C)
#define SOC_ETZPC_DECPROT8STAT_ADDR(base) ((base) + 0x860)
#define SOC_ETZPC_DECPROT8SET_ADDR(base) ((base) + 0x864)
#define SOC_ETZPC_DECPROT8CLR_ADDR(base) ((base) + 0x868)
#define SOC_ETZPC_REG0_STAT_ADDR(base) ((base) + 0x86C)
#define SOC_ETZPC_REG1_STAT_ADDR(base) ((base) + 0x870)
#define SOC_ETZPC_PERI_LOCK_ADDR(base) ((base) + 0xF00)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_ETZPC_R0SIZE_UNION;
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
} SOC_ETZPC_DECPROT0STAT_UNION;
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
} SOC_ETZPC_DECPROT0SET_UNION;
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
} SOC_ETZPC_DECPROT0CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_config_ree : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT1STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT1STAT_tz_secure_config_ree_START (0)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_config_ree_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int config_ree_set_0 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT1SET_UNION;
#endif
#define SOC_ETZPC_DECPROT1SET_config_ree_set_0_START (0)
#define SOC_ETZPC_DECPROT1SET_config_ree_set_0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int config_ree_clr_0 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT1CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT1CLR_config_ree_clr_0_START (0)
#define SOC_ETZPC_DECPROT1CLR_config_ree_clr_0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_sce_ree : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT2STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT2STAT_tz_secure_sce_ree_START (0)
#define SOC_ETZPC_DECPROT2STAT_tz_secure_sce_ree_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ree_set_0 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT2SET_UNION;
#endif
#define SOC_ETZPC_DECPROT2SET_sce_ree_set_0_START (0)
#define SOC_ETZPC_DECPROT2SET_sce_ree_set_0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ree_clr_0 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT2CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT2CLR_sce_ree_clr_0_START (0)
#define SOC_ETZPC_DECPROT2CLR_sce_ree_clr_0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_pke_ree : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT3STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT3STAT_tz_secure_pke_ree_START (0)
#define SOC_ETZPC_DECPROT3STAT_tz_secure_pke_ree_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_ree_set_0 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT3SET_UNION;
#endif
#define SOC_ETZPC_DECPROT3SET_pke_ree_set_0_START (0)
#define SOC_ETZPC_DECPROT3SET_pke_ree_set_0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_ree_clr_0 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_ETZPC_DECPROT3CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT3CLR_pke_ree_clr_0_START (0)
#define SOC_ETZPC_DECPROT3CLR_pke_ree_clr_0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce_axi_mst_wr_stat_0 : 1;
        unsigned int tz_sce_axi_mst_wr_stat_1 : 1;
        unsigned int tz_sce_axi_mst_rd_stat_0 : 1;
        unsigned int tz_sce_axi_mst_rd_stat_1 : 1;
        unsigned int reserved_0 : 3;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
    } reg;
} SOC_ETZPC_DECPROT4STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_0_START (0)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_0_END (0)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_1_START (1)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_1_END (1)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_0_START (2)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_0_END (2)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_1_START (3)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce_axi_mst_wr_set_0 : 1;
        unsigned int tz_sce_axi_mst_wr_set_1 : 1;
        unsigned int tz_sce_axi_mst_rd_set_0 : 1;
        unsigned int tz_sce_axi_mst_rd_set_1 : 1;
        unsigned int reserved_0 : 3;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
    } reg;
} SOC_ETZPC_DECPROT4SET_UNION;
#endif
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_0_START (0)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_0_END (0)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_1_START (1)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_1_END (1)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_0_START (2)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_0_END (2)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_1_START (3)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce_axi_mst_wr_clr_0 : 1;
        unsigned int tz_sce_axi_mst_wr_clr_1 : 1;
        unsigned int tz_sce_axi_mst_rd_clr_0 : 1;
        unsigned int tz_sce_axi_mst_rd_clr_1 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_ETZPC_DECPROT4CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_0_START (0)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_0_END (0)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_1_START (1)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_1_END (1)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_0_START (2)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_0_END (2)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_1_START (3)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce2_axi_mst_wr_stat_0 : 1;
        unsigned int tz_sce2_axi_mst_wr_stat_1 : 1;
        unsigned int tz_sce2_axi_mst_rd_stat_0 : 1;
        unsigned int tz_sce2_axi_mst_rd_stat_1 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_ETZPC_DECPROT5STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_wr_stat_0_START (0)
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_wr_stat_0_END (0)
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_wr_stat_1_START (1)
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_wr_stat_1_END (1)
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_rd_stat_0_START (2)
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_rd_stat_0_END (2)
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_rd_stat_1_START (3)
#define SOC_ETZPC_DECPROT5STAT_tz_sce2_axi_mst_rd_stat_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce2_axi_mst_wr_set_0 : 1;
        unsigned int tz_sce2_axi_mst_wr_set_1 : 1;
        unsigned int tz_sce2_axi_mst_rd_set_0 : 1;
        unsigned int tz_sce2_axi_mst_rd_set_1 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_ETZPC_DECPROT5SET_UNION;
#endif
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_wr_set_0_START (0)
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_wr_set_0_END (0)
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_wr_set_1_START (1)
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_wr_set_1_END (1)
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_rd_set_0_START (2)
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_rd_set_0_END (2)
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_rd_set_1_START (3)
#define SOC_ETZPC_DECPROT5SET_tz_sce2_axi_mst_rd_set_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce2_axi_mst_wr_clr_0 : 1;
        unsigned int tz_sce2_axi_mst_wr_clr_1 : 1;
        unsigned int tz_sce2_axi_mst_rd_clr_0 : 1;
        unsigned int tz_sce2_axi_mst_rd_clr_1 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_ETZPC_DECPROT5CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_wr_clr_0_START (0)
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_wr_clr_0_END (0)
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_wr_clr_1_START (1)
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_wr_clr_1_END (1)
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_rd_clr_0_START (2)
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_rd_clr_0_END (2)
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_rd_clr_1_START (3)
#define SOC_ETZPC_DECPROT5CLR_tz_sce2_axi_mst_rd_clr_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce_ree_axi_mst_wr_stat_0 : 1;
        unsigned int tz_sce_ree_axi_mst_wr_stat_1 : 1;
        unsigned int tz_sce_ree_axi_mst_rd_stat_0 : 1;
        unsigned int tz_sce_ree_axi_mst_rd_stat_1 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_ETZPC_DECPROT6STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_wr_stat_0_START (0)
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_wr_stat_0_END (0)
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_wr_stat_1_START (1)
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_wr_stat_1_END (1)
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_rd_stat_0_START (2)
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_rd_stat_0_END (2)
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_rd_stat_1_START (3)
#define SOC_ETZPC_DECPROT6STAT_tz_sce_ree_axi_mst_rd_stat_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce_ree_axi_mst_wr_set_0 : 1;
        unsigned int tz_sce_ree_axi_mst_wr_set_1 : 1;
        unsigned int tz_sce_ree_axi_mst_rd_set_0 : 1;
        unsigned int tz_sce_ree_axi_mst_rd_set_1 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_ETZPC_DECPROT6SET_UNION;
#endif
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_wr_set_0_START (0)
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_wr_set_0_END (0)
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_wr_set_1_START (1)
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_wr_set_1_END (1)
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_rd_set_0_START (2)
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_rd_set_0_END (2)
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_rd_set_1_START (3)
#define SOC_ETZPC_DECPROT6SET_tz_sce_ree_axi_mst_rd_set_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_sce_ree_axi_mst_wr_clr_0 : 1;
        unsigned int tz_sce_ree_axi_mst_wr_clr_1 : 1;
        unsigned int tz_sce_ree_axi_mst_rd_clr_0 : 1;
        unsigned int tz_sce_ree_axi_mst_rd_clr_1 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_ETZPC_DECPROT6CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_wr_clr_0_START (0)
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_wr_clr_0_END (0)
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_wr_clr_1_START (1)
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_wr_clr_1_END (1)
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_rd_clr_0_START (2)
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_rd_clr_0_END (2)
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_rd_clr_1_START (3)
#define SOC_ETZPC_DECPROT6CLR_tz_sce_ree_axi_mst_rd_clr_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 28;
    } reg;
} SOC_ETZPC_DECPROT7STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 28;
    } reg;
} SOC_ETZPC_DECPROT7SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 28;
    } reg;
} SOC_ETZPC_DECPROT7CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 23;
        unsigned int reserved_2: 1;
    } reg;
} SOC_ETZPC_DECPROT8STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 23;
        unsigned int reserved_2: 1;
    } reg;
} SOC_ETZPC_DECPROT8SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 23;
        unsigned int reserved_2: 1;
    } reg;
} SOC_ETZPC_DECPROT8CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ETZPC_REG0_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ETZPC_REG1_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ETZPC_PERI_LOCK_UNION;
#endif
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
