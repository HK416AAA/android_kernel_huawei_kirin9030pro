#ifndef __SOC_PQU_INTERFACE_H__
#define __SOC_PQU_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PQU_BUSY_ADDR(base) (base)
#define SOC_PQU_START_ADDR(base) ((base) + 0x0004UL)
#define SOC_PQU_INT_MASK_ADDR(base) ((base) + 0x0008UL)
#define SOC_PQU_INT_MASK_STATUS_ADDR(base) ((base) + 0x000CUL)
#define SOC_PQU_INT_NOMASK_STATUS_ADDR(base) ((base) + 0x0010UL)
#define SOC_PQU_INT_CLEAR_ADDR(base) ((base) + 0x0014UL)
#define SOC_PQU_ALARM_MASK_ADDR(base) ((base) + 0x0018UL)
#define SOC_PQU_ALARM_MASK_STATUS_ADDR(base) ((base) + 0x001CUL)
#define SOC_PQU_ALARM_NOMASK_STATUS_ADDR(base) ((base) + 0x0020UL)
#define SOC_PQU_ALARM_CLEAR_ADDR(base) ((base) + 0x0024UL)
#define SOC_PQU_LOCK_ADDR(base) ((base) + 0x0028UL)
#define SOC_PQU_FLAG_ADDR(base) ((base) + 0x002cUL)
#define SOC_PQU_ALARM_STATUS_ADDR(base) ((base) + 0x0030UL)
#define SOC_PQU_IRAM_ADDR(base,i) ((base) + 0x0200UL + (i) * 4)
#define SOC_PQU_DRAM_ADDR(base,d) ((base) + 0x0600UL + (d) * 4)
#define SOC_PQU_CRAM0_ADDR(base,c_0) ((base) + 0x2600UL + (c_0) * 4)
#define SOC_PQU_CRAM1_ADDR(base,c_1) ((base) + 0x9E00UL + (c_1) * 4)
#define SOC_PQU_CRAM2_ADDR(base,c_2) ((base) + 0xBE00UL + (c_2) * 4)
#define SOC_PQU_CRAM3_ADDR(base,c_3) ((base) + 0xDE00UL + (c_3) * 4)
#else
#define SOC_PQU_BUSY_ADDR(base) (base)
#define SOC_PQU_START_ADDR(base) ((base) + 0x0004)
#define SOC_PQU_INT_MASK_ADDR(base) ((base) + 0x0008)
#define SOC_PQU_INT_MASK_STATUS_ADDR(base) ((base) + 0x000C)
#define SOC_PQU_INT_NOMASK_STATUS_ADDR(base) ((base) + 0x0010)
#define SOC_PQU_INT_CLEAR_ADDR(base) ((base) + 0x0014)
#define SOC_PQU_ALARM_MASK_ADDR(base) ((base) + 0x0018)
#define SOC_PQU_ALARM_MASK_STATUS_ADDR(base) ((base) + 0x001C)
#define SOC_PQU_ALARM_NOMASK_STATUS_ADDR(base) ((base) + 0x0020)
#define SOC_PQU_ALARM_CLEAR_ADDR(base) ((base) + 0x0024)
#define SOC_PQU_LOCK_ADDR(base) ((base) + 0x0028)
#define SOC_PQU_FLAG_ADDR(base) ((base) + 0x002c)
#define SOC_PQU_ALARM_STATUS_ADDR(base) ((base) + 0x0030)
#define SOC_PQU_IRAM_ADDR(base,i) ((base) + 0x0200 + (i) * 4)
#define SOC_PQU_DRAM_ADDR(base,d) ((base) + 0x0600 + (d) * 4)
#define SOC_PQU_CRAM0_ADDR(base,c_0) ((base) + 0x2600 + (c_0) * 4)
#define SOC_PQU_CRAM1_ADDR(base,c_1) ((base) + 0x9E00 + (c_1) * 4)
#define SOC_PQU_CRAM2_ADDR(base,c_2) ((base) + 0xBE00 + (c_2) * 4)
#define SOC_PQU_CRAM3_ADDR(base,c_3) ((base) + 0xDE00 + (c_3) * 4)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PQU_BUSY_UNION;
#endif
#define SOC_PQU_BUSY_pqu_busy_START (0)
#define SOC_PQU_BUSY_pqu_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_start : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_START_UNION;
#endif
#define SOC_PQU_START_pqu_start_START (0)
#define SOC_PQU_START_pqu_start_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_int_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_INT_MASK_UNION;
#endif
#define SOC_PQU_INT_MASK_pqu_int_mask_START (0)
#define SOC_PQU_INT_MASK_pqu_int_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_int_mask_status : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_INT_MASK_STATUS_UNION;
#endif
#define SOC_PQU_INT_MASK_STATUS_pqu_int_mask_status_START (0)
#define SOC_PQU_INT_MASK_STATUS_pqu_int_mask_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_int_nomsk_status : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_INT_NOMASK_STATUS_UNION;
#endif
#define SOC_PQU_INT_NOMASK_STATUS_pqu_int_nomsk_status_START (0)
#define SOC_PQU_INT_NOMASK_STATUS_pqu_int_nomsk_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_int_clear : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_INT_CLEAR_UNION;
#endif
#define SOC_PQU_INT_CLEAR_pqu_int_clear_START (0)
#define SOC_PQU_INT_CLEAR_pqu_int_clear_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_alarm_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_ALARM_MASK_UNION;
#endif
#define SOC_PQU_ALARM_MASK_pqu_alarm_mask_START (0)
#define SOC_PQU_ALARM_MASK_pqu_alarm_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_alarm_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PQU_ALARM_MASK_STATUS_UNION;
#endif
#define SOC_PQU_ALARM_MASK_STATUS_pqu_alarm_status_START (0)
#define SOC_PQU_ALARM_MASK_STATUS_pqu_alarm_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_alarm_nomask_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PQU_ALARM_NOMASK_STATUS_UNION;
#endif
#define SOC_PQU_ALARM_NOMASK_STATUS_pqu_alarm_nomask_status_START (0)
#define SOC_PQU_ALARM_NOMASK_STATUS_pqu_alarm_nomask_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_alarm_clear : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_ALARM_CLEAR_UNION;
#endif
#define SOC_PQU_ALARM_CLEAR_pqu_alarm_clear_START (0)
#define SOC_PQU_ALARM_CLEAR_pqu_alarm_clear_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_LOCK_UNION;
#endif
#define SOC_PQU_LOCK_pqu_lock_START (0)
#define SOC_PQU_LOCK_pqu_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_flag : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PQU_FLAG_UNION;
#endif
#define SOC_PQU_FLAG_pqu_flag_START (0)
#define SOC_PQU_FLAG_pqu_flag_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_alarm_status : 32;
    } reg;
} SOC_PQU_ALARM_STATUS_UNION;
#endif
#define SOC_PQU_ALARM_STATUS_pqu_alarm_status_START (0)
#define SOC_PQU_ALARM_STATUS_pqu_alarm_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_iram : 32;
    } reg;
} SOC_PQU_IRAM_UNION;
#endif
#define SOC_PQU_IRAM_pqu_iram_START (0)
#define SOC_PQU_IRAM_pqu_iram_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_dram : 32;
    } reg;
} SOC_PQU_DRAM_UNION;
#endif
#define SOC_PQU_DRAM_pqu_dram_START (0)
#define SOC_PQU_DRAM_pqu_dram_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_cram0 : 32;
    } reg;
} SOC_PQU_CRAM0_UNION;
#endif
#define SOC_PQU_CRAM0_pqu_cram0_START (0)
#define SOC_PQU_CRAM0_pqu_cram0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_cram1 : 32;
    } reg;
} SOC_PQU_CRAM1_UNION;
#endif
#define SOC_PQU_CRAM1_pqu_cram1_START (0)
#define SOC_PQU_CRAM1_pqu_cram1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_cram2 : 32;
    } reg;
} SOC_PQU_CRAM2_UNION;
#endif
#define SOC_PQU_CRAM2_pqu_cram2_START (0)
#define SOC_PQU_CRAM2_pqu_cram2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pqu_cram3 : 32;
    } reg;
} SOC_PQU_CRAM3_UNION;
#endif
#define SOC_PQU_CRAM3_pqu_cram3_START (0)
#define SOC_PQU_CRAM3_pqu_cram3_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
