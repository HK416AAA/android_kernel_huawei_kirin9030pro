#ifndef __SOC_DIGTSENSORC_INTERFACE_H__
#define __SOC_DIGTSENSORC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DIGTSENSORC_TS_MODE_ADDR(base,m) ((base) + (0x000+0x100*(m)))
#define SOC_DIGTSENSORC_TS_CFG_ADDR(base,m) ((base) + (0x004+0x100*(m)))
#define SOC_DIGTSENSORC_DATA_ADDR(base,m) ((base) + (0x008+0x100*(m)))
#define SOC_DIGTSENSORC_DATA_MIN_ADDR(base,m) ((base) + (0x00C+0x100*(m)))
#define SOC_DIGTSENSORC_DATA_MAX_ADDR(base,m) ((base) + (0x010+0x100*(m)))
#define SOC_DIGTSENSORC_TS_RSV_CTRL_ADDR(base,m) ((base) + (0x014+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_0_ADDR(base,m) ((base) + (0x018+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_1_ADDR(base,m) ((base) + (0x01C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_2_ADDR(base,m) ((base) + (0x020+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_3_ADDR(base,m) ((base) + (0x024+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_4_ADDR(base,m) ((base) + (0x028+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_5_ADDR(base,m) ((base) + (0x02C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_6_ADDR(base,m) ((base) + (0x030+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_7_ADDR(base,m) ((base) + (0x034+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_8_ADDR(base,m) ((base) + (0x038+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_9_ADDR(base,m) ((base) + (0x03C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_10_ADDR(base,m) ((base) + (0x040+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_11_ADDR(base,m) ((base) + (0x044+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_12_ADDR(base,m) ((base) + (0x048+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_13_ADDR(base,m) ((base) + (0x04C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_14_ADDR(base,m) ((base) + (0x050+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_15_ADDR(base,m) ((base) + (0x054+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_LAG_ADDR(base,m) ((base) + (0x058+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_INT_TH_ADDR(base,m) ((base) + (0x05C+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_MSK_ADDR(base,m) ((base) + (0x060+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_RST_TH_ADDR(base,m) ((base) + (0x064+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_INT_CLR_ADDR(base,m) ((base) + (0x068+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_INT_RST_ADDR(base,m) ((base) + (0x06C+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_SUM_ADDR(base,m) ((base) + (0x070+0x100*(m)))
#else
#define SOC_DIGTSENSORC_TS_MODE_ADDR(base,m) ((base) + (0x000+0x100*(m)))
#define SOC_DIGTSENSORC_TS_CFG_ADDR(base,m) ((base) + (0x004+0x100*(m)))
#define SOC_DIGTSENSORC_DATA_ADDR(base,m) ((base) + (0x008+0x100*(m)))
#define SOC_DIGTSENSORC_DATA_MIN_ADDR(base,m) ((base) + (0x00C+0x100*(m)))
#define SOC_DIGTSENSORC_DATA_MAX_ADDR(base,m) ((base) + (0x010+0x100*(m)))
#define SOC_DIGTSENSORC_TS_RSV_CTRL_ADDR(base,m) ((base) + (0x014+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_0_ADDR(base,m) ((base) + (0x018+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_1_ADDR(base,m) ((base) + (0x01C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_2_ADDR(base,m) ((base) + (0x020+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_3_ADDR(base,m) ((base) + (0x024+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_4_ADDR(base,m) ((base) + (0x028+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_5_ADDR(base,m) ((base) + (0x02C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_6_ADDR(base,m) ((base) + (0x030+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_7_ADDR(base,m) ((base) + (0x034+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_8_ADDR(base,m) ((base) + (0x038+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_9_ADDR(base,m) ((base) + (0x03C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_10_ADDR(base,m) ((base) + (0x040+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_11_ADDR(base,m) ((base) + (0x044+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_12_ADDR(base,m) ((base) + (0x048+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_13_ADDR(base,m) ((base) + (0x04C+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_14_ADDR(base,m) ((base) + (0x050+0x100*(m)))
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_15_ADDR(base,m) ((base) + (0x054+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_LAG_ADDR(base,m) ((base) + (0x058+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_INT_TH_ADDR(base,m) ((base) + (0x05C+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_MSK_ADDR(base,m) ((base) + (0x060+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_RST_TH_ADDR(base,m) ((base) + (0x064+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_INT_CLR_ADDR(base,m) ((base) + (0x068+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_INT_RST_ADDR(base,m) ((base) + (0x06C+0x100*(m)))
#define SOC_DIGTSENSORC_TEMP_SUM_ADDR(base,m) ((base) + (0x070+0x100*(m)))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_en_inner : 1;
        unsigned int ts_dbgclk_en : 1;
        unsigned int hw_tsen_disable_msk : 1;
        unsigned int remote_fail_flag : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DIGTSENSORC_TS_MODE_UNION;
#endif
#define SOC_DIGTSENSORC_TS_MODE_ts_en_inner_START (0)
#define SOC_DIGTSENSORC_TS_MODE_ts_en_inner_END (0)
#define SOC_DIGTSENSORC_TS_MODE_ts_dbgclk_en_START (1)
#define SOC_DIGTSENSORC_TS_MODE_ts_dbgclk_en_END (1)
#define SOC_DIGTSENSORC_TS_MODE_hw_tsen_disable_msk_START (2)
#define SOC_DIGTSENSORC_TS_MODE_hw_tsen_disable_msk_END (2)
#define SOC_DIGTSENSORC_TS_MODE_remote_fail_flag_START (3)
#define SOC_DIGTSENSORC_TS_MODE_remote_fail_flag_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_num : 8;
        unsigned int reserved : 8;
        unsigned int ts_cfg : 16;
    } reg;
} SOC_DIGTSENSORC_TS_CFG_UNION;
#endif
#define SOC_DIGTSENSORC_TS_CFG_sample_num_START (0)
#define SOC_DIGTSENSORC_TS_CFG_sample_num_END (7)
#define SOC_DIGTSENSORC_TS_CFG_ts_cfg_START (16)
#define SOC_DIGTSENSORC_TS_CFG_ts_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_aver : 16;
        unsigned int temp_flash_flag : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_DIGTSENSORC_DATA_UNION;
#endif
#define SOC_DIGTSENSORC_DATA_temp_aver_START (0)
#define SOC_DIGTSENSORC_DATA_temp_aver_END (15)
#define SOC_DIGTSENSORC_DATA_temp_flash_flag_START (16)
#define SOC_DIGTSENSORC_DATA_temp_flash_flag_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_min : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DIGTSENSORC_DATA_MIN_UNION;
#endif
#define SOC_DIGTSENSORC_DATA_MIN_temp_min_START (0)
#define SOC_DIGTSENSORC_DATA_MIN_temp_min_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_max : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DIGTSENSORC_DATA_MAX_UNION;
#endif
#define SOC_DIGTSENSORC_DATA_MAX_temp_max_START (0)
#define SOC_DIGTSENSORC_DATA_MAX_temp_max_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_rsv_ctrl : 32;
    } reg;
} SOC_DIGTSENSORC_TS_RSV_CTRL_UNION;
#endif
#define SOC_DIGTSENSORC_TS_RSV_CTRL_ts_rsv_ctrl_START (0)
#define SOC_DIGTSENSORC_TS_RSV_CTRL_ts_rsv_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_0 : 16;
        unsigned int sample_temp_1 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_0_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_0_sample_temp_0_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_0_sample_temp_0_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_0_sample_temp_1_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_0_sample_temp_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_2 : 16;
        unsigned int sample_temp_3 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_1_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_1_sample_temp_2_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_1_sample_temp_2_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_1_sample_temp_3_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_1_sample_temp_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_4 : 16;
        unsigned int sample_temp_5 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_2_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_2_sample_temp_4_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_2_sample_temp_4_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_2_sample_temp_5_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_2_sample_temp_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_6 : 16;
        unsigned int sample_temp_7 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_3_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_3_sample_temp_6_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_3_sample_temp_6_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_3_sample_temp_7_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_3_sample_temp_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_8 : 16;
        unsigned int sample_temp_9 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_4_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_4_sample_temp_8_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_4_sample_temp_8_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_4_sample_temp_9_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_4_sample_temp_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_10 : 16;
        unsigned int sample_temp_11 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_5_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_5_sample_temp_10_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_5_sample_temp_10_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_5_sample_temp_11_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_5_sample_temp_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_12 : 16;
        unsigned int sample_temp_13 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_6_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_6_sample_temp_12_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_6_sample_temp_12_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_6_sample_temp_13_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_6_sample_temp_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_14 : 16;
        unsigned int sample_temp_15 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_7_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_7_sample_temp_14_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_7_sample_temp_14_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_7_sample_temp_15_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_7_sample_temp_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_16 : 16;
        unsigned int sample_temp_17 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_8_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_8_sample_temp_16_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_8_sample_temp_16_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_8_sample_temp_17_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_8_sample_temp_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_18 : 16;
        unsigned int sample_temp_19 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_9_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_9_sample_temp_18_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_9_sample_temp_18_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_9_sample_temp_19_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_9_sample_temp_19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_20 : 16;
        unsigned int sample_temp_21 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_10_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_10_sample_temp_20_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_10_sample_temp_20_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_10_sample_temp_21_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_10_sample_temp_21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_22 : 16;
        unsigned int sample_temp_23 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_11_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_11_sample_temp_22_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_11_sample_temp_22_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_11_sample_temp_23_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_11_sample_temp_23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_24 : 16;
        unsigned int sample_temp_25 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_12_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_12_sample_temp_24_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_12_sample_temp_24_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_12_sample_temp_25_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_12_sample_temp_25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_26 : 16;
        unsigned int sample_temp_27 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_13_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_13_sample_temp_26_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_13_sample_temp_26_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_13_sample_temp_27_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_13_sample_temp_27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_28 : 16;
        unsigned int sample_temp_29 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_14_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_14_sample_temp_28_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_14_sample_temp_28_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_14_sample_temp_29_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_14_sample_temp_29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_temp_30 : 16;
        unsigned int sample_temp_31 : 16;
    } reg;
} SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_15_UNION;
#endif
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_15_sample_temp_30_START (0)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_15_sample_temp_30_END (15)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_15_sample_temp_31_START (16)
#define SOC_DIGTSENSORC_SAMPLE_TEMP_INFO_15_sample_temp_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_lag : 7;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 24;
    } reg;
} SOC_DIGTSENSORC_TEMP_LAG_UNION;
#endif
#define SOC_DIGTSENSORC_TEMP_LAG_temp_lag_START (0)
#define SOC_DIGTSENSORC_TEMP_LAG_temp_lag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_h_th : 16;
        unsigned int temp_l_th : 16;
    } reg;
} SOC_DIGTSENSORC_TEMP_INT_TH_UNION;
#endif
#define SOC_DIGTSENSORC_TEMP_INT_TH_temp_h_th_START (0)
#define SOC_DIGTSENSORC_TEMP_INT_TH_temp_h_th_END (15)
#define SOC_DIGTSENSORC_TEMP_INT_TH_temp_l_th_START (16)
#define SOC_DIGTSENSORC_TEMP_INT_TH_temp_l_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_h_int_msk : 1;
        unsigned int temp_l_int_msk : 1;
        unsigned int temp_rst_msk : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DIGTSENSORC_TEMP_MSK_UNION;
#endif
#define SOC_DIGTSENSORC_TEMP_MSK_temp_h_int_msk_START (0)
#define SOC_DIGTSENSORC_TEMP_MSK_temp_h_int_msk_END (0)
#define SOC_DIGTSENSORC_TEMP_MSK_temp_l_int_msk_START (1)
#define SOC_DIGTSENSORC_TEMP_MSK_temp_l_int_msk_END (1)
#define SOC_DIGTSENSORC_TEMP_MSK_temp_rst_msk_START (2)
#define SOC_DIGTSENSORC_TEMP_MSK_temp_rst_msk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_rst_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DIGTSENSORC_TEMP_RST_TH_UNION;
#endif
#define SOC_DIGTSENSORC_TEMP_RST_TH_temp_rst_th_START (0)
#define SOC_DIGTSENSORC_TEMP_RST_TH_temp_rst_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_h_int_clr : 1;
        unsigned int temp_l_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DIGTSENSORC_TEMP_INT_CLR_UNION;
#endif
#define SOC_DIGTSENSORC_TEMP_INT_CLR_temp_h_int_clr_START (0)
#define SOC_DIGTSENSORC_TEMP_INT_CLR_temp_h_int_clr_END (0)
#define SOC_DIGTSENSORC_TEMP_INT_CLR_temp_l_int_clr_START (1)
#define SOC_DIGTSENSORC_TEMP_INT_CLR_temp_l_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_rawint_h : 1;
        unsigned int temp_rawint_l : 1;
        unsigned int temp_mskint_h : 1;
        unsigned int temp_mskint_l : 1;
        unsigned int temp_rst_inner : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DIGTSENSORC_TEMP_INT_RST_UNION;
#endif
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_rawint_h_START (0)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_rawint_h_END (0)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_rawint_l_START (1)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_rawint_l_END (1)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_mskint_h_START (2)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_mskint_h_END (2)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_mskint_l_START (3)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_mskint_l_END (3)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_rst_inner_START (4)
#define SOC_DIGTSENSORC_TEMP_INT_RST_temp_rst_inner_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_sum : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_DIGTSENSORC_TEMP_SUM_UNION;
#endif
#define SOC_DIGTSENSORC_TEMP_SUM_temp_sum_START (0)
#define SOC_DIGTSENSORC_TEMP_SUM_temp_sum_END (20)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
