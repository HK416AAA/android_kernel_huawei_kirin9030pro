#ifndef __SOC_ULL_MON_INTERFACE_H__
#define __SOC_ULL_MON_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ULL_MON_CKG_ADDR(base) (base)
#define SOC_ULL_MON_CFG0_ADDR(base,mon_num) (base) + 0x100 + 0x10 * (mon_num)
#define SOC_ULL_MON_CFG1_ADDR(base,mon_num) (base) + 0x104 + 0x10 * (mon_num)
#define SOC_ULL_MON_LAT_ADDR(base,mon_num) (base) + 0x108 + 0x10 * (mon_num)
#else
#define SOC_ULL_MON_CKG_ADDR(base) (base)
#define SOC_ULL_MON_CFG0_ADDR(base,mon_num) (base) + 0x100 + 0x10 * (mon_num)
#define SOC_ULL_MON_CFG1_ADDR(base,mon_num) (base) + 0x104 + 0x10 * (mon_num)
#define SOC_ULL_MON_LAT_ADDR(base,mon_num) (base) + 0x108 + 0x10 * (mon_num)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ull_mon_ckg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ULL_MON_CKG_UNION;
#endif
#define SOC_ULL_MON_CKG_ull_mon_ckg_en_START (0)
#define SOC_ULL_MON_CKG_ull_mon_ckg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ref : 32;
    } reg;
} SOC_ULL_MON_CFG0_UNION;
#endif
#define SOC_ULL_MON_CFG0_mid_ref_START (0)
#define SOC_ULL_MON_CFG0_mid_ref_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_ref : 8;
        unsigned int cfg_interval_sel : 1;
        unsigned int cfg_average_num : 1;
        unsigned int cfg_timer_def_val : 5;
        unsigned int reserved_0 : 1;
        unsigned int mon_start : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_ULL_MON_CFG1_UNION;
#endif
#define SOC_ULL_MON_CFG1_qos_ref_START (0)
#define SOC_ULL_MON_CFG1_qos_ref_END (7)
#define SOC_ULL_MON_CFG1_cfg_interval_sel_START (8)
#define SOC_ULL_MON_CFG1_cfg_interval_sel_END (8)
#define SOC_ULL_MON_CFG1_cfg_average_num_START (9)
#define SOC_ULL_MON_CFG1_cfg_average_num_END (9)
#define SOC_ULL_MON_CFG1_cfg_timer_def_val_START (10)
#define SOC_ULL_MON_CFG1_cfg_timer_def_val_END (14)
#define SOC_ULL_MON_CFG1_mon_start_START (16)
#define SOC_ULL_MON_CFG1_mon_start_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int max_latency : 5;
        unsigned int reserved_0 : 3;
        unsigned int min_latency : 5;
        unsigned int reserved_1 : 3;
        unsigned int average_latency : 5;
        unsigned int reserved_2 : 3;
        unsigned int trans_count : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_ULL_MON_LAT_UNION;
#endif
#define SOC_ULL_MON_LAT_max_latency_START (0)
#define SOC_ULL_MON_LAT_max_latency_END (4)
#define SOC_ULL_MON_LAT_min_latency_START (8)
#define SOC_ULL_MON_LAT_min_latency_END (12)
#define SOC_ULL_MON_LAT_average_latency_START (16)
#define SOC_ULL_MON_LAT_average_latency_END (20)
#define SOC_ULL_MON_LAT_trans_count_START (24)
#define SOC_ULL_MON_LAT_trans_count_END (27)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
