#ifndef __SOC_HI_RTC_V500_INTERFACE_H__
#define __SOC_HI_RTC_V500_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HI_RTC_V500_RTC_EN_ADDR(base) ((base) + (0x000UL))
#define SOC_HI_RTC_V500_INITIAL_VAL_ADDR(base) ((base) + (0x004UL))
#define SOC_HI_RTC_V500_COMP_VAL_ADDR(base) ((base) + (0x008UL))
#define SOC_HI_RTC_V500_INTR_RTC_CLR_ADDR(base) ((base) + (0x010UL))
#define SOC_HI_RTC_V500_INTR_RTC_MASK_ADDR(base) ((base) + (0x014UL))
#define SOC_HI_RTC_V500_INTR_RTC_RAW_ADDR(base) ((base) + (0x018UL))
#define SOC_HI_RTC_V500_INTR_RTC_ADDR(base) ((base) + (0x01CUL))
#define SOC_HI_RTC_V500_CNT_RTC_ADDR(base) ((base) + (0x020UL))
#define SOC_HI_RTC_V500_RTC_ID_ADDR(base) ((base) + (0xFFCUL))
#else
#define SOC_HI_RTC_V500_RTC_EN_ADDR(base) ((base) + (0x000))
#define SOC_HI_RTC_V500_INITIAL_VAL_ADDR(base) ((base) + (0x004))
#define SOC_HI_RTC_V500_COMP_VAL_ADDR(base) ((base) + (0x008))
#define SOC_HI_RTC_V500_INTR_RTC_CLR_ADDR(base) ((base) + (0x010))
#define SOC_HI_RTC_V500_INTR_RTC_MASK_ADDR(base) ((base) + (0x014))
#define SOC_HI_RTC_V500_INTR_RTC_RAW_ADDR(base) ((base) + (0x018))
#define SOC_HI_RTC_V500_INTR_RTC_ADDR(base) ((base) + (0x01C))
#define SOC_HI_RTC_V500_CNT_RTC_ADDR(base) ((base) + (0x020))
#define SOC_HI_RTC_V500_RTC_ID_ADDR(base) ((base) + (0xFFC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_RTC_V500_RTC_EN_UNION;
#endif
#define SOC_HI_RTC_V500_RTC_EN_rtc_en_START (0)
#define SOC_HI_RTC_V500_RTC_EN_rtc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int initial_val : 32;
    } reg;
} SOC_HI_RTC_V500_INITIAL_VAL_UNION;
#endif
#define SOC_HI_RTC_V500_INITIAL_VAL_initial_val_START (0)
#define SOC_HI_RTC_V500_INITIAL_VAL_initial_val_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int comp_val : 32;
    } reg;
} SOC_HI_RTC_V500_COMP_VAL_UNION;
#endif
#define SOC_HI_RTC_V500_COMP_VAL_comp_val_START (0)
#define SOC_HI_RTC_V500_COMP_VAL_comp_val_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rtc_clr_pulse : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_RTC_V500_INTR_RTC_CLR_UNION;
#endif
#define SOC_HI_RTC_V500_INTR_RTC_CLR_intr_rtc_clr_pulse_START (0)
#define SOC_HI_RTC_V500_INTR_RTC_CLR_intr_rtc_clr_pulse_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rtc_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_RTC_V500_INTR_RTC_MASK_UNION;
#endif
#define SOC_HI_RTC_V500_INTR_RTC_MASK_intr_rtc_mask_START (0)
#define SOC_HI_RTC_V500_INTR_RTC_MASK_intr_rtc_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rtc_raw : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_RTC_V500_INTR_RTC_RAW_UNION;
#endif
#define SOC_HI_RTC_V500_INTR_RTC_RAW_intr_rtc_raw_START (0)
#define SOC_HI_RTC_V500_INTR_RTC_RAW_intr_rtc_raw_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_rtc : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_RTC_V500_INTR_RTC_UNION;
#endif
#define SOC_HI_RTC_V500_INTR_RTC_intr_rtc_START (0)
#define SOC_HI_RTC_V500_INTR_RTC_intr_rtc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_rtc : 32;
    } reg;
} SOC_HI_RTC_V500_CNT_RTC_UNION;
#endif
#define SOC_HI_RTC_V500_CNT_RTC_cnt_rtc_START (0)
#define SOC_HI_RTC_V500_CNT_RTC_cnt_rtc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtc_id : 32;
    } reg;
} SOC_HI_RTC_V500_RTC_ID_UNION;
#endif
#define SOC_HI_RTC_V500_RTC_ID_rtc_id_START (0)
#define SOC_HI_RTC_V500_RTC_ID_rtc_id_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
