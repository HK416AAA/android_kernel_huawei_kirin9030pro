#ifndef __SOC_QICE_TBED_MON_INTERFACE_H__
#define __SOC_QICE_TBED_MON_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_TBED_MON_CFG_ADDR(base) (base)
#define SOC_QICE_TBED_MON_ITEM_CFG_ADDR(base,mon_num) (base) + 0x080 + 0x10 * (mon_num)
#define SOC_QICE_TBED_MON_ITEM_STAT_ADDR(base,mon_num) (base) + 0x084 + 0x10 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH0_ADDR(base,mon_num) (base) + 0x100 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH1_ADDR(base,mon_num) (base) + 0x104 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH2_ADDR(base,mon_num) (base) + 0x108 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH3_ADDR(base,mon_num) (base) + 0x10c + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH4_ADDR(base,mon_num) (base) + 0x110 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH5_ADDR(base,mon_num) (base) + 0x114 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH6_ADDR(base,mon_num) (base) + 0x118 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH7_ADDR(base,mon_num) (base) + 0x11c + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA0_ADDR(base,mon_num) (base) + 0x400 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA1_ADDR(base,mon_num) (base) + 0x404 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA2_ADDR(base,mon_num) (base) + 0x408 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA3_ADDR(base,mon_num) (base) + 0x40c + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA4_ADDR(base,mon_num) (base) + 0x410 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA5_ADDR(base,mon_num) (base) + 0x414 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA6_ADDR(base,mon_num) (base) + 0x418 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA7_ADDR(base,mon_num) (base) + 0x41c + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA0_ADDR(base,mon_num) (base) + 0x420 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA1_ADDR(base,mon_num) (base) + 0x424 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA2_ADDR(base,mon_num) (base) + 0x428 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA3_ADDR(base,mon_num) (base) + 0x42c + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA4_ADDR(base,mon_num) (base) + 0x430 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA5_ADDR(base,mon_num) (base) + 0x434 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA6_ADDR(base,mon_num) (base) + 0x438 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA7_ADDR(base,mon_num) (base) + 0x43c + 0x40 * (mon_num)
#else
#define SOC_QICE_TBED_MON_CFG_ADDR(base) (base)
#define SOC_QICE_TBED_MON_ITEM_CFG_ADDR(base,mon_num) (base) + 0x080 + 0x10 * (mon_num)
#define SOC_QICE_TBED_MON_ITEM_STAT_ADDR(base,mon_num) (base) + 0x084 + 0x10 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH0_ADDR(base,mon_num) (base) + 0x100 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH1_ADDR(base,mon_num) (base) + 0x104 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH2_ADDR(base,mon_num) (base) + 0x108 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH3_ADDR(base,mon_num) (base) + 0x10c + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH4_ADDR(base,mon_num) (base) + 0x110 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH5_ADDR(base,mon_num) (base) + 0x114 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH6_ADDR(base,mon_num) (base) + 0x118 + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_MID_MATCH7_ADDR(base,mon_num) (base) + 0x11c + 0x20 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA0_ADDR(base,mon_num) (base) + 0x400 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA1_ADDR(base,mon_num) (base) + 0x404 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA2_ADDR(base,mon_num) (base) + 0x408 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA3_ADDR(base,mon_num) (base) + 0x40c + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA4_ADDR(base,mon_num) (base) + 0x410 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA5_ADDR(base,mon_num) (base) + 0x414 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA6_ADDR(base,mon_num) (base) + 0x418 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN0_DATA7_ADDR(base,mon_num) (base) + 0x41c + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA0_ADDR(base,mon_num) (base) + 0x420 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA1_ADDR(base,mon_num) (base) + 0x424 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA2_ADDR(base,mon_num) (base) + 0x428 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA3_ADDR(base,mon_num) (base) + 0x42c + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA4_ADDR(base,mon_num) (base) + 0x430 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA5_ADDR(base,mon_num) (base) + 0x434 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA6_ADDR(base,mon_num) (base) + 0x438 + 0x40 * (mon_num)
#define SOC_QICE_TBED_MON_CHN1_DATA7_ADDR(base,mon_num) (base) + 0x43c + 0x40 * (mon_num)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_ckg : 1;
        unsigned int icfg_ckg_ext_ena : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBED_MON_CFG_UNION;
#endif
#define SOC_QICE_TBED_MON_CFG_icfg_ckg_byp_ckg_START (0)
#define SOC_QICE_TBED_MON_CFG_icfg_ckg_byp_ckg_END (0)
#define SOC_QICE_TBED_MON_CFG_icfg_ckg_ext_ena_START (1)
#define SOC_QICE_TBED_MON_CFG_icfg_ckg_ext_ena_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_tbed_mon : 1;
        unsigned int icfg_ckg_ext_tbed_mon : 1;
        unsigned int icfg_tbed_mon_disable : 1;
        unsigned int icfg_monitor_en : 1;
        unsigned int icfg_sam_rise : 1;
        unsigned int reserved : 11;
        unsigned int icfg_mpam_filter : 16;
    } reg;
} SOC_QICE_TBED_MON_ITEM_CFG_UNION;
#endif
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_ckg_byp_tbed_mon_START (0)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_ckg_byp_tbed_mon_END (0)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_ckg_ext_tbed_mon_START (1)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_ckg_ext_tbed_mon_END (1)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_tbed_mon_disable_START (2)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_tbed_mon_disable_END (2)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_monitor_en_START (3)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_monitor_en_END (3)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_sam_rise_START (4)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_sam_rise_END (4)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_mpam_filter_START (16)
#define SOC_QICE_TBED_MON_ITEM_CFG_icfg_mpam_filter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ckg_busy_tbed_mon0 : 1;
        unsigned int dfx_ckg_busy_tbed_mon1 : 1;
        unsigned int dfx_ckg_busy_tbed_mon2 : 1;
        unsigned int dfx_ckg_busy_tbed_mon3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_TBED_MON_ITEM_STAT_UNION;
#endif
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon0_START (0)
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon0_END (0)
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon1_START (1)
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon1_END (1)
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon2_START (2)
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon2_END (2)
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon3_START (3)
#define SOC_QICE_TBED_MON_ITEM_STAT_dfx_ckg_busy_tbed_mon3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter0 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH0_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH0_icfg_mid_filter0_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH0_icfg_mid_filter0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter1 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH1_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH1_icfg_mid_filter1_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH1_icfg_mid_filter1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter2 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH2_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH2_icfg_mid_filter2_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH2_icfg_mid_filter2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter3 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH3_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH3_icfg_mid_filter3_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH3_icfg_mid_filter3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter4 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH4_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH4_icfg_mid_filter4_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH4_icfg_mid_filter4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter5 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH5_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH5_icfg_mid_filter5_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH5_icfg_mid_filter5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter6 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH6_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH6_icfg_mid_filter6_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH6_icfg_mid_filter6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mid_filter7 : 32;
    } reg;
} SOC_QICE_TBED_MON_MID_MATCH7_UNION;
#endif
#define SOC_QICE_TBED_MON_MID_MATCH7_icfg_mid_filter7_START (0)
#define SOC_QICE_TBED_MON_MID_MATCH7_icfg_mid_filter7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data0 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA0_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA0_monitor_chn0_data0_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA0_monitor_chn0_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data1 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA1_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA1_monitor_chn0_data1_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA1_monitor_chn0_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data2 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA2_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA2_monitor_chn0_data2_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA2_monitor_chn0_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data3 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA3_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA3_monitor_chn0_data3_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA3_monitor_chn0_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data4 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA4_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA4_monitor_chn0_data4_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA4_monitor_chn0_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data5 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA5_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA5_monitor_chn0_data5_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA5_monitor_chn0_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data6 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA6_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA6_monitor_chn0_data6_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA6_monitor_chn0_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn0_data7 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN0_DATA7_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN0_DATA7_monitor_chn0_data7_START (0)
#define SOC_QICE_TBED_MON_CHN0_DATA7_monitor_chn0_data7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data0 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA0_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA0_monitor_chn1_data0_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA0_monitor_chn1_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data1 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA1_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA1_monitor_chn1_data1_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA1_monitor_chn1_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data2 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA2_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA2_monitor_chn1_data2_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA2_monitor_chn1_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data3 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA3_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA3_monitor_chn1_data3_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA3_monitor_chn1_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data4 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA4_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA4_monitor_chn1_data4_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA4_monitor_chn1_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data5 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA5_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA5_monitor_chn1_data5_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA5_monitor_chn1_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data6 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA6_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA6_monitor_chn1_data6_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA6_monitor_chn1_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_chn1_data7 : 32;
    } reg;
} SOC_QICE_TBED_MON_CHN1_DATA7_UNION;
#endif
#define SOC_QICE_TBED_MON_CHN1_DATA7_monitor_chn1_data7_START (0)
#define SOC_QICE_TBED_MON_CHN1_DATA7_monitor_chn1_data7_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
