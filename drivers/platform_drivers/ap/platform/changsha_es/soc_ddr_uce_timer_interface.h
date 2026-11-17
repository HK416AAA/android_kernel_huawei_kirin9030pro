#ifndef __SOC_DDR_UCE_TIMER_INTERFACE_H__
#define __SOC_DDR_UCE_TIMER_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_DDR_UCE_TIMER_TIMER_INIT_ADDR(base) ((base) + (0x0004UL))
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_ADDR(base) ((base) + (0x0008UL))
#define SOC_DDR_UCE_TIMER_INTR_TIMER_ADDR(base) ((base) + (0x000CUL))
#define SOC_DDR_UCE_TIMER_INTR_TIMER_CLR_ADDR(base) ((base) + (0x0010UL))
#define SOC_DDR_UCE_TIMER_COUNT_VALUE_ADDR(base) ((base) + (0x0014UL))
#define SOC_DDR_UCE_TIMER_TIMER_PERIOD_INIT_ADDR(base) ((base) + (0x0018UL))
#define SOC_DDR_UCE_TIMER_TIMER_VERSION_ADDR(base) ((base) + (0x00F0UL))
#else
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_DDR_UCE_TIMER_TIMER_INIT_ADDR(base) ((base) + (0x0004))
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_ADDR(base) ((base) + (0x0008))
#define SOC_DDR_UCE_TIMER_INTR_TIMER_ADDR(base) ((base) + (0x000C))
#define SOC_DDR_UCE_TIMER_INTR_TIMER_CLR_ADDR(base) ((base) + (0x0010))
#define SOC_DDR_UCE_TIMER_COUNT_VALUE_ADDR(base) ((base) + (0x0014))
#define SOC_DDR_UCE_TIMER_TIMER_PERIOD_INIT_ADDR(base) ((base) + (0x0018))
#define SOC_DDR_UCE_TIMER_TIMER_VERSION_ADDR(base) ((base) + (0x00F0))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_timer_en_bypass : 1;
        unsigned int cnt_timer_en_sel : 1;
        unsigned int dbg_timer_en_bypass : 1;
        unsigned int reserved : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_UNION;
#endif
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_cnt_timer_en_bypass_START (0)
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_cnt_timer_en_bypass_END (0)
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_cnt_timer_en_sel_START (1)
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_cnt_timer_en_sel_END (1)
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_dbg_timer_en_bypass_START (2)
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_dbg_timer_en_bypass_END (2)
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_bitmasken_START (16)
#define SOC_DDR_UCE_TIMER_TIMER_CLK_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer_init : 32;
    } reg;
} SOC_DDR_UCE_TIMER_TIMER_INIT_UNION;
#endif
#define SOC_DDR_UCE_TIMER_TIMER_INIT_timer_init_START (0)
#define SOC_DDR_UCE_TIMER_TIMER_INIT_timer_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer_en : 1;
        unsigned int timer_size : 1;
        unsigned int timer_stop : 1;
        unsigned int timer_reload_sel : 1;
        unsigned int timer_int_mask : 1;
        unsigned int reserved : 11;
        unsigned int bitmasken : 16;
    } reg;
} SOC_DDR_UCE_TIMER_TIMER_CTRL_UNION;
#endif
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_en_START (0)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_en_END (0)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_size_START (1)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_size_END (1)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_stop_START (2)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_stop_END (2)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_reload_sel_START (3)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_reload_sel_END (3)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_int_mask_START (4)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_timer_int_mask_END (4)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_bitmasken_START (16)
#define SOC_DDR_UCE_TIMER_TIMER_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_timer : 1;
        unsigned int intr_timer_raw : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_UCE_TIMER_INTR_TIMER_UNION;
#endif
#define SOC_DDR_UCE_TIMER_INTR_TIMER_intr_timer_START (0)
#define SOC_DDR_UCE_TIMER_INTR_TIMER_intr_timer_END (0)
#define SOC_DDR_UCE_TIMER_INTR_TIMER_intr_timer_raw_START (1)
#define SOC_DDR_UCE_TIMER_INTR_TIMER_intr_timer_raw_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_timer_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_UCE_TIMER_INTR_TIMER_CLR_UNION;
#endif
#define SOC_DDR_UCE_TIMER_INTR_TIMER_CLR_intr_timer_clr_START (0)
#define SOC_DDR_UCE_TIMER_INTR_TIMER_CLR_intr_timer_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int count_value : 32;
    } reg;
} SOC_DDR_UCE_TIMER_COUNT_VALUE_UNION;
#endif
#define SOC_DDR_UCE_TIMER_COUNT_VALUE_count_value_START (0)
#define SOC_DDR_UCE_TIMER_COUNT_VALUE_count_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer_period_init : 32;
    } reg;
} SOC_DDR_UCE_TIMER_TIMER_PERIOD_INIT_UNION;
#endif
#define SOC_DDR_UCE_TIMER_TIMER_PERIOD_INIT_timer_period_init_START (0)
#define SOC_DDR_UCE_TIMER_TIMER_PERIOD_INIT_timer_period_init_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer_version : 32;
    } reg;
} SOC_DDR_UCE_TIMER_TIMER_VERSION_UNION;
#endif
#define SOC_DDR_UCE_TIMER_TIMER_VERSION_timer_version_START (0)
#define SOC_DDR_UCE_TIMER_TIMER_VERSION_timer_version_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
