#ifndef __SOC_HICKM_INTERFACE_H__
#define __SOC_HICKM_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HICKM_EH_SENSOR_ENABLE_ADDR(base,n) ((base) + (0x0000+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_CFG_MIN_ADDR(base,n) ((base) + (0x0004+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_CFG_MAX_ADDR(base,n) ((base) + (0x0008+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_CLEAR_ADDR(base,n) ((base) + (0x000C+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_STATE_ADDR(base,n) ((base) + (0x00010+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_INT_MSK_ADDR(base) ((base) + (0x0200UL))
#define SOC_HICKM_EH_SENSOR_INT_STATE_ADDR(base) ((base) + (0x0204UL))
#define SOC_HICKM_F_SENSOR_ENABLE_ADDR(base,m) ((base) + (0x0000+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_CFG_MIN_ADDR(base,m) ((base) + (0x0004+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_CFG_MAX_ADDR(base,m) ((base) + (0x0008+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_CLEAR_ADDR(base,m) ((base) + (0x000C+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_STATE_ADDR(base,m) ((base) + (0x0010+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_INT_MSK_ADDR(base) ((base) + (0x800UL))
#define SOC_HICKM_F_SENSOR_INT_STATE_ADDR(base) ((base) + (0x804UL))
#define SOC_HICKM_CKM_OSC_EN_ADDR(base) ((base) + (0x0A00UL))
#define SOC_HICKM_CKM_OSC_EH_CFG_ADDR(base) ((base) + (0x0A04UL))
#define SOC_HICKM_CKM_OSC_CFG_ADDR(base) ((base) + (0x0A08UL))
#define SOC_HICKM_CKM_OSC_READY_ADDR(base) ((base) + (0x0A0CUL))
#define SOC_HICKM_CKM_EH_LOCK_ADDR(base) ((base) + (0x0A10UL))
#else
#define SOC_HICKM_EH_SENSOR_ENABLE_ADDR(base,n) ((base) + (0x0000+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_CFG_MIN_ADDR(base,n) ((base) + (0x0004+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_CFG_MAX_ADDR(base,n) ((base) + (0x0008+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_CLEAR_ADDR(base,n) ((base) + (0x000C+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_STATE_ADDR(base,n) ((base) + (0x00010+0x100*(n)))
#define SOC_HICKM_EH_SENSOR_INT_MSK_ADDR(base) ((base) + (0x0200))
#define SOC_HICKM_EH_SENSOR_INT_STATE_ADDR(base) ((base) + (0x0204))
#define SOC_HICKM_F_SENSOR_ENABLE_ADDR(base,m) ((base) + (0x0000+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_CFG_MIN_ADDR(base,m) ((base) + (0x0004+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_CFG_MAX_ADDR(base,m) ((base) + (0x0008+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_CLEAR_ADDR(base,m) ((base) + (0x000C+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_STATE_ADDR(base,m) ((base) + (0x0010+0x400+0x100*(m)))
#define SOC_HICKM_F_SENSOR_INT_MSK_ADDR(base) ((base) + (0x800))
#define SOC_HICKM_F_SENSOR_INT_STATE_ADDR(base) ((base) + (0x804))
#define SOC_HICKM_CKM_OSC_EN_ADDR(base) ((base) + (0x0A00))
#define SOC_HICKM_CKM_OSC_EH_CFG_ADDR(base) ((base) + (0x0A04))
#define SOC_HICKM_CKM_OSC_CFG_ADDR(base) ((base) + (0x0A08))
#define SOC_HICKM_CKM_OSC_READY_ADDR(base) ((base) + (0x0A0C))
#define SOC_HICKM_CKM_EH_LOCK_ADDR(base) ((base) + (0x0A10))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eh_fs_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HICKM_EH_SENSOR_ENABLE_UNION;
#endif
#define SOC_HICKM_EH_SENSOR_ENABLE_eh_fs_en_START (0)
#define SOC_HICKM_EH_SENSOR_ENABLE_eh_fs_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eh_fs_limit_value_min : 16;
        unsigned int eh_fs_div_min : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HICKM_EH_SENSOR_CFG_MIN_UNION;
#endif
#define SOC_HICKM_EH_SENSOR_CFG_MIN_eh_fs_limit_value_min_START (0)
#define SOC_HICKM_EH_SENSOR_CFG_MIN_eh_fs_limit_value_min_END (15)
#define SOC_HICKM_EH_SENSOR_CFG_MIN_eh_fs_div_min_START (16)
#define SOC_HICKM_EH_SENSOR_CFG_MIN_eh_fs_div_min_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eh_fs_limit_value_max : 16;
        unsigned int eh_fs_div_max : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HICKM_EH_SENSOR_CFG_MAX_UNION;
#endif
#define SOC_HICKM_EH_SENSOR_CFG_MAX_eh_fs_limit_value_max_START (0)
#define SOC_HICKM_EH_SENSOR_CFG_MAX_eh_fs_limit_value_max_END (15)
#define SOC_HICKM_EH_SENSOR_CFG_MAX_eh_fs_div_max_START (16)
#define SOC_HICKM_EH_SENSOR_CFG_MAX_eh_fs_div_max_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eh_fs_alarm_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HICKM_EH_SENSOR_CLEAR_UNION;
#endif
#define SOC_HICKM_EH_SENSOR_CLEAR_eh_fs_alarm_clr_START (0)
#define SOC_HICKM_EH_SENSOR_CLEAR_eh_fs_alarm_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eh_fs_alarm_state : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HICKM_EH_SENSOR_STATE_UNION;
#endif
#define SOC_HICKM_EH_SENSOR_STATE_eh_fs_alarm_state_START (0)
#define SOC_HICKM_EH_SENSOR_STATE_eh_fs_alarm_state_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eh_fs_int_msk : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HICKM_EH_SENSOR_INT_MSK_UNION;
#endif
#define SOC_HICKM_EH_SENSOR_INT_MSK_eh_fs_int_msk_START (0)
#define SOC_HICKM_EH_SENSOR_INT_MSK_eh_fs_int_msk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eh_fs_int_state : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HICKM_EH_SENSOR_INT_STATE_UNION;
#endif
#define SOC_HICKM_EH_SENSOR_INT_STATE_eh_fs_int_state_START (0)
#define SOC_HICKM_EH_SENSOR_INT_STATE_eh_fs_int_state_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HICKM_F_SENSOR_ENABLE_UNION;
#endif
#define SOC_HICKM_F_SENSOR_ENABLE_fs_en_START (0)
#define SOC_HICKM_F_SENSOR_ENABLE_fs_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_limit_value_min : 16;
        unsigned int fs_div_min : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HICKM_F_SENSOR_CFG_MIN_UNION;
#endif
#define SOC_HICKM_F_SENSOR_CFG_MIN_fs_limit_value_min_START (0)
#define SOC_HICKM_F_SENSOR_CFG_MIN_fs_limit_value_min_END (15)
#define SOC_HICKM_F_SENSOR_CFG_MIN_fs_div_min_START (16)
#define SOC_HICKM_F_SENSOR_CFG_MIN_fs_div_min_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_limit_value_max : 16;
        unsigned int fs_div_max : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HICKM_F_SENSOR_CFG_MAX_UNION;
#endif
#define SOC_HICKM_F_SENSOR_CFG_MAX_fs_limit_value_max_START (0)
#define SOC_HICKM_F_SENSOR_CFG_MAX_fs_limit_value_max_END (15)
#define SOC_HICKM_F_SENSOR_CFG_MAX_fs_div_max_START (16)
#define SOC_HICKM_F_SENSOR_CFG_MAX_fs_div_max_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_alarm_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HICKM_F_SENSOR_CLEAR_UNION;
#endif
#define SOC_HICKM_F_SENSOR_CLEAR_fs_alarm_clr_START (0)
#define SOC_HICKM_F_SENSOR_CLEAR_fs_alarm_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_alarm_state : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HICKM_F_SENSOR_STATE_UNION;
#endif
#define SOC_HICKM_F_SENSOR_STATE_fs_alarm_state_START (0)
#define SOC_HICKM_F_SENSOR_STATE_fs_alarm_state_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_int_msk : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HICKM_F_SENSOR_INT_MSK_UNION;
#endif
#define SOC_HICKM_F_SENSOR_INT_MSK_fs_int_msk_START (0)
#define SOC_HICKM_F_SENSOR_INT_MSK_fs_int_msk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_int_state : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HICKM_F_SENSOR_INT_STATE_UNION;
#endif
#define SOC_HICKM_F_SENSOR_INT_STATE_fs_int_state_START (0)
#define SOC_HICKM_F_SENSOR_INT_STATE_fs_int_state_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HICKM_CKM_OSC_EN_UNION;
#endif
#define SOC_HICKM_CKM_OSC_EN_osc_en_START (0)
#define SOC_HICKM_CKM_OSC_EN_osc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_eh_cfg : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HICKM_CKM_OSC_EH_CFG_UNION;
#endif
#define SOC_HICKM_CKM_OSC_EH_CFG_osc_eh_cfg_START (0)
#define SOC_HICKM_CKM_OSC_EH_CFG_osc_eh_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_cfg : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HICKM_CKM_OSC_CFG_UNION;
#endif
#define SOC_HICKM_CKM_OSC_CFG_osc_cfg_START (0)
#define SOC_HICKM_CKM_OSC_CFG_osc_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_ready : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HICKM_CKM_OSC_READY_UNION;
#endif
#define SOC_HICKM_CKM_OSC_READY_osc_ready_START (0)
#define SOC_HICKM_CKM_OSC_READY_osc_ready_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prt_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HICKM_CKM_EH_LOCK_UNION;
#endif
#define SOC_HICKM_CKM_EH_LOCK_prt_lock_START (0)
#define SOC_HICKM_CKM_EH_LOCK_prt_lock_END (3)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
