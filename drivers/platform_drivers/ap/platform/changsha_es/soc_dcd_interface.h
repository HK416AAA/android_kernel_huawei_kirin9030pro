#ifndef __SOC_DCD_INTERFACE_H__
#define __SOC_DCD_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DCD_CONFIG_ADDR(base) (base)
#define SOC_DCD_SOFT_CTRL_ADDR(base) ((base) + 0x04UL)
#define SOC_DCD_HW_CTRL_ADDR(base) ((base) + 0x08UL)
#define SOC_DCD_SAMPLE_NUM_SW_ADDR(base) ((base) + 0x0CUL)
#define SOC_DCD_SAMPLE_NUM_HW_ADDR(base) ((base) + 0x10UL)
#define SOC_DCD_SINGLE_TH_ADDR(base) ((base) + 0x14UL)
#define SOC_DCD_MULTI_TH_ADDR(base) ((base) + 0x018UL)
#define SOC_DCD_DBG_INFO_ADDR(base) ((base) + 0x1CUL)
#define SOC_DCD_VALUE_ORIG_ADDR(base) ((base) + 0x20UL)
#define SOC_DCD_VALUE_JSUM_ADDR(base) ((base) + 0x24UL)
#define SOC_DCD_VALUE_KSUM_ADDR(base) ((base) + 0x28UL)
#define SOC_DCD_VALUE_MSUM_ADDR(base) ((base) + 0x2CUL)
#define SOC_DCD_VALUE_AVER_ADDR(base) ((base) + 0x30UL)
#define SOC_DCD_VALUE_MIN_ADDR(base) ((base) + 0x34UL)
#define SOC_DCD_VALUE_MAX_ADDR(base) ((base) + 0x38UL)
#else
#define SOC_DCD_CONFIG_ADDR(base) (base)
#define SOC_DCD_SOFT_CTRL_ADDR(base) ((base) + 0x04)
#define SOC_DCD_HW_CTRL_ADDR(base) ((base) + 0x08)
#define SOC_DCD_SAMPLE_NUM_SW_ADDR(base) ((base) + 0x0C)
#define SOC_DCD_SAMPLE_NUM_HW_ADDR(base) ((base) + 0x10)
#define SOC_DCD_SINGLE_TH_ADDR(base) ((base) + 0x14)
#define SOC_DCD_MULTI_TH_ADDR(base) ((base) + 0x018)
#define SOC_DCD_DBG_INFO_ADDR(base) ((base) + 0x1C)
#define SOC_DCD_VALUE_ORIG_ADDR(base) ((base) + 0x20)
#define SOC_DCD_VALUE_JSUM_ADDR(base) ((base) + 0x24)
#define SOC_DCD_VALUE_KSUM_ADDR(base) ((base) + 0x28)
#define SOC_DCD_VALUE_MSUM_ADDR(base) ((base) + 0x2C)
#define SOC_DCD_VALUE_AVER_ADDR(base) ((base) + 0x30)
#define SOC_DCD_VALUE_MIN_ADDR(base) ((base) + 0x34)
#define SOC_DCD_VALUE_MAX_ADDR(base) ((base) + 0x38)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int refclk_det_en : 1;
        unsigned int sample_gt_on : 1;
        unsigned int sw_hw_mode : 1;
        unsigned int multi_bit_en : 1;
        unsigned int single_bit_en : 1;
        unsigned int duty_flag_sel : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DCD_CONFIG_UNION;
#endif
#define SOC_DCD_CONFIG_refclk_det_en_START (0)
#define SOC_DCD_CONFIG_refclk_det_en_END (0)
#define SOC_DCD_CONFIG_sample_gt_on_START (1)
#define SOC_DCD_CONFIG_sample_gt_on_END (1)
#define SOC_DCD_CONFIG_sw_hw_mode_START (2)
#define SOC_DCD_CONFIG_sw_hw_mode_END (2)
#define SOC_DCD_CONFIG_multi_bit_en_START (3)
#define SOC_DCD_CONFIG_multi_bit_en_END (3)
#define SOC_DCD_CONFIG_single_bit_en_START (4)
#define SOC_DCD_CONFIG_single_bit_en_END (4)
#define SOC_DCD_CONFIG_duty_flag_sel_START (5)
#define SOC_DCD_CONFIG_duty_flag_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_en_soft : 1;
        unsigned int valid_hw2sw : 1;
        unsigned int ready_sw2hw : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DCD_SOFT_CTRL_UNION;
#endif
#define SOC_DCD_SOFT_CTRL_sample_en_soft_START (0)
#define SOC_DCD_SOFT_CTRL_sample_en_soft_END (0)
#define SOC_DCD_SOFT_CTRL_valid_hw2sw_START (1)
#define SOC_DCD_SOFT_CTRL_valid_hw2sw_END (1)
#define SOC_DCD_SOFT_CTRL_ready_sw2hw_START (2)
#define SOC_DCD_SOFT_CTRL_ready_sw2hw_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int disbale_num : 4;
        unsigned int refclk_gt_hw_bypass : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DCD_HW_CTRL_UNION;
#endif
#define SOC_DCD_HW_CTRL_disbale_num_START (0)
#define SOC_DCD_HW_CTRL_disbale_num_END (3)
#define SOC_DCD_HW_CTRL_refclk_gt_hw_bypass_START (4)
#define SOC_DCD_HW_CTRL_refclk_gt_hw_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_num_soft : 7;
        unsigned int sample_gap_soft : 9;
        unsigned int reserved : 16;
    } reg;
} SOC_DCD_SAMPLE_NUM_SW_UNION;
#endif
#define SOC_DCD_SAMPLE_NUM_SW_sample_num_soft_START (0)
#define SOC_DCD_SAMPLE_NUM_SW_sample_num_soft_END (6)
#define SOC_DCD_SAMPLE_NUM_SW_sample_gap_soft_START (7)
#define SOC_DCD_SAMPLE_NUM_SW_sample_gap_soft_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_num : 7;
        unsigned int sample_gap : 9;
        unsigned int reserved : 16;
    } reg;
} SOC_DCD_SAMPLE_NUM_HW_UNION;
#endif
#define SOC_DCD_SAMPLE_NUM_HW_sample_num_START (0)
#define SOC_DCD_SAMPLE_NUM_HW_sample_num_END (6)
#define SOC_DCD_SAMPLE_NUM_HW_sample_gap_START (7)
#define SOC_DCD_SAMPLE_NUM_HW_sample_gap_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int single_mode_th : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DCD_SINGLE_TH_UNION;
#endif
#define SOC_DCD_SINGLE_TH_single_mode_th_START (0)
#define SOC_DCD_SINGLE_TH_single_mode_th_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int multi_mode_th : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DCD_MULTI_TH_UNION;
#endif
#define SOC_DCD_MULTI_TH_multi_mode_th_START (0)
#define SOC_DCD_MULTI_TH_multi_mode_th_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delay_line_long : 1;
        unsigned int delay_line_short : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DCD_DBG_INFO_UNION;
#endif
#define SOC_DCD_DBG_INFO_delay_line_long_START (0)
#define SOC_DCD_DBG_INFO_delay_line_long_END (0)
#define SOC_DCD_DBG_INFO_delay_line_short_START (1)
#define SOC_DCD_DBG_INFO_delay_line_short_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m_orig : 8;
        unsigned int k_orig : 8;
        unsigned int j_orig : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DCD_VALUE_ORIG_UNION;
#endif
#define SOC_DCD_VALUE_ORIG_m_orig_START (0)
#define SOC_DCD_VALUE_ORIG_m_orig_END (7)
#define SOC_DCD_VALUE_ORIG_k_orig_START (8)
#define SOC_DCD_VALUE_ORIG_k_orig_END (15)
#define SOC_DCD_VALUE_ORIG_j_orig_START (16)
#define SOC_DCD_VALUE_ORIG_j_orig_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int j_sum : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_DCD_VALUE_JSUM_UNION;
#endif
#define SOC_DCD_VALUE_JSUM_j_sum_START (0)
#define SOC_DCD_VALUE_JSUM_j_sum_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int k_sum : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_DCD_VALUE_KSUM_UNION;
#endif
#define SOC_DCD_VALUE_KSUM_k_sum_START (0)
#define SOC_DCD_VALUE_KSUM_k_sum_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m_sum : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_DCD_VALUE_MSUM_UNION;
#endif
#define SOC_DCD_VALUE_MSUM_m_sum_START (0)
#define SOC_DCD_VALUE_MSUM_m_sum_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m_aver : 8;
        unsigned int k_aver : 8;
        unsigned int j_aver : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DCD_VALUE_AVER_UNION;
#endif
#define SOC_DCD_VALUE_AVER_m_aver_START (0)
#define SOC_DCD_VALUE_AVER_m_aver_END (7)
#define SOC_DCD_VALUE_AVER_k_aver_START (8)
#define SOC_DCD_VALUE_AVER_k_aver_END (15)
#define SOC_DCD_VALUE_AVER_j_aver_START (16)
#define SOC_DCD_VALUE_AVER_j_aver_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m_min : 8;
        unsigned int k_min : 8;
        unsigned int j_min : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DCD_VALUE_MIN_UNION;
#endif
#define SOC_DCD_VALUE_MIN_m_min_START (0)
#define SOC_DCD_VALUE_MIN_m_min_END (7)
#define SOC_DCD_VALUE_MIN_k_min_START (8)
#define SOC_DCD_VALUE_MIN_k_min_END (15)
#define SOC_DCD_VALUE_MIN_j_min_START (16)
#define SOC_DCD_VALUE_MIN_j_min_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m_max : 8;
        unsigned int k_max : 8;
        unsigned int j_max : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DCD_VALUE_MAX_UNION;
#endif
#define SOC_DCD_VALUE_MAX_m_max_START (0)
#define SOC_DCD_VALUE_MAX_m_max_END (7)
#define SOC_DCD_VALUE_MAX_k_max_START (8)
#define SOC_DCD_VALUE_MAX_k_max_END (15)
#define SOC_DCD_VALUE_MAX_j_max_START (16)
#define SOC_DCD_VALUE_MAX_j_max_END (23)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
