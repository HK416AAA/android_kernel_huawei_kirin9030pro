#ifndef __SOC_PKE_INTERFACE_H__
#define __SOC_PKE_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PKE_BUSY_ADDR(base) (base)
#define SOC_PKE_START_ADDR(base) ((base) + 0x0004UL)
#define SOC_PKE_INT_MASK_ADDR(base) ((base) + 0x0008UL)
#define SOC_PKE_INT_MASK_STATUS_ADDR(base) ((base) + 0x000CUL)
#define SOC_PKE_INT_NOMASK_STATUS_ADDR(base) ((base) + 0x0010UL)
#define SOC_PKE_INT_CLR_ADDR(base) ((base) + 0x0014UL)
#define SOC_PKE_ALARM_MASK_ADDR(base) ((base) + 0x0018UL)
#define SOC_PKE_ALARM_MASK_STATUS_ADDR(base) ((base) + 0x001CUL)
#define SOC_PKE_ALARM_NOMASK_STATUS_ADDR(base) ((base) + 0x0020UL)
#define SOC_PKE_ALARM_CLR_ADDR(base) ((base) + 0x0024UL)
#define SOC_PKE_INV_ERR_TYPE_ADDR(base) ((base) + 0x0028UL)
#define SOC_PKE_PC_ADDR_ADDR(base) ((base) + 0x002cUL)
#define SOC_PKE_FLAG_STATUS_ADDR(base) ((base) + 0x0030UL)
#define SOC_PKE_LOCK_ADDR(base) ((base) + 0x0034UL)
#define SOC_PKE_MASK_ADDR(base) ((base) + 0x0038UL)
#define SOC_PKE_KEY_BACKUP_ADDR(base) ((base) + 0x003cUL)
#define SOC_PKE_REFRESH_ADDR(base) ((base) + 0x0040UL)
#define SOC_PKE_KEY_LOCK_ADDR(base) ((base) + 0x0044UL)
#define SOC_PKE_ALARM_STATUS0_ADDR(base) ((base) + 0x0048UL)
#define SOC_PKE_ALARM_STATUS1_ADDR(base) ((base) + 0x004cUL)
#define SOC_PKE_TRNG_REQUEST_ADDR(base) ((base) + 0x0050UL)
#define SOC_PKE_INT_TIME_OUT_VALUE_ADDR(base) ((base) + 0x0090UL)
#define SOC_PKE_INT_TIME_OUT_MASK_ADDR(base) ((base) + 0x0094UL)
#define SOC_PKE_INT_TIME_OUT_CLEAR_ADDR(base) ((base) + 0x0098UL)
#define SOC_PKE_INT_TIME_OUT_MASK_STATUS_ADDR(base) ((base) + 0x009cUL)
#define SOC_PKE_INT_TIME_OUT_NOMASK_STATUS_ADDR(base) ((base) + 0x00a0UL)
#define SOC_PKE_ENDIAN_CHANGE_ADDR(base) ((base) + 0x00a4UL)
#define SOC_PKE_IRAM_ADDR(base,i) ((base) + 0x0200UL + (i) * 4)
#define SOC_PKE_DRAM_ADDR(base,d) ((base) + 0x0600UL + (d) * 4)
#else
#define SOC_PKE_BUSY_ADDR(base) (base)
#define SOC_PKE_START_ADDR(base) ((base) + 0x0004)
#define SOC_PKE_INT_MASK_ADDR(base) ((base) + 0x0008)
#define SOC_PKE_INT_MASK_STATUS_ADDR(base) ((base) + 0x000C)
#define SOC_PKE_INT_NOMASK_STATUS_ADDR(base) ((base) + 0x0010)
#define SOC_PKE_INT_CLR_ADDR(base) ((base) + 0x0014)
#define SOC_PKE_ALARM_MASK_ADDR(base) ((base) + 0x0018)
#define SOC_PKE_ALARM_MASK_STATUS_ADDR(base) ((base) + 0x001C)
#define SOC_PKE_ALARM_NOMASK_STATUS_ADDR(base) ((base) + 0x0020)
#define SOC_PKE_ALARM_CLR_ADDR(base) ((base) + 0x0024)
#define SOC_PKE_INV_ERR_TYPE_ADDR(base) ((base) + 0x0028)
#define SOC_PKE_PC_ADDR_ADDR(base) ((base) + 0x002c)
#define SOC_PKE_FLAG_STATUS_ADDR(base) ((base) + 0x0030)
#define SOC_PKE_LOCK_ADDR(base) ((base) + 0x0034)
#define SOC_PKE_MASK_ADDR(base) ((base) + 0x0038)
#define SOC_PKE_KEY_BACKUP_ADDR(base) ((base) + 0x003c)
#define SOC_PKE_REFRESH_ADDR(base) ((base) + 0x0040)
#define SOC_PKE_KEY_LOCK_ADDR(base) ((base) + 0x0044)
#define SOC_PKE_ALARM_STATUS0_ADDR(base) ((base) + 0x0048)
#define SOC_PKE_ALARM_STATUS1_ADDR(base) ((base) + 0x004c)
#define SOC_PKE_TRNG_REQUEST_ADDR(base) ((base) + 0x0050)
#define SOC_PKE_INT_TIME_OUT_VALUE_ADDR(base) ((base) + 0x0090)
#define SOC_PKE_INT_TIME_OUT_MASK_ADDR(base) ((base) + 0x0094)
#define SOC_PKE_INT_TIME_OUT_CLEAR_ADDR(base) ((base) + 0x0098)
#define SOC_PKE_INT_TIME_OUT_MASK_STATUS_ADDR(base) ((base) + 0x009c)
#define SOC_PKE_INT_TIME_OUT_NOMASK_STATUS_ADDR(base) ((base) + 0x00a0)
#define SOC_PKE_ENDIAN_CHANGE_ADDR(base) ((base) + 0x00a4)
#define SOC_PKE_IRAM_ADDR(base,i) ((base) + 0x0200 + (i) * 4)
#define SOC_PKE_DRAM_ADDR(base,d) ((base) + 0x0600 + (d) * 4)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PKE_BUSY_UNION;
#endif
#define SOC_PKE_BUSY_pke_busy_START (0)
#define SOC_PKE_BUSY_pke_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_start : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_START_UNION;
#endif
#define SOC_PKE_START_pke_start_START (0)
#define SOC_PKE_START_pke_start_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_INT_MASK_UNION;
#endif
#define SOC_PKE_INT_MASK_pke_int_mask_START (0)
#define SOC_PKE_INT_MASK_pke_int_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_mask_status : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_INT_MASK_STATUS_UNION;
#endif
#define SOC_PKE_INT_MASK_STATUS_pke_int_mask_status_START (0)
#define SOC_PKE_INT_MASK_STATUS_pke_int_mask_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_nomsk_status : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_INT_NOMASK_STATUS_UNION;
#endif
#define SOC_PKE_INT_NOMASK_STATUS_pke_int_nomsk_status_START (0)
#define SOC_PKE_INT_NOMASK_STATUS_pke_int_nomsk_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_INT_CLR_UNION;
#endif
#define SOC_PKE_INT_CLR_int_clr_START (0)
#define SOC_PKE_INT_CLR_int_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_alarm_mask : 4;
        unsigned int pke_alarm_h2h_mask : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_PKE_ALARM_MASK_UNION;
#endif
#define SOC_PKE_ALARM_MASK_pke_alarm_mask_START (0)
#define SOC_PKE_ALARM_MASK_pke_alarm_mask_END (3)
#define SOC_PKE_ALARM_MASK_pke_alarm_h2h_mask_START (4)
#define SOC_PKE_ALARM_MASK_pke_alarm_h2h_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_alarm_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PKE_ALARM_MASK_STATUS_UNION;
#endif
#define SOC_PKE_ALARM_MASK_STATUS_pke_alarm_status_START (0)
#define SOC_PKE_ALARM_MASK_STATUS_pke_alarm_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_alarm_nomask_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PKE_ALARM_NOMASK_STATUS_UNION;
#endif
#define SOC_PKE_ALARM_NOMASK_STATUS_pke_alarm_nomask_status_START (0)
#define SOC_PKE_ALARM_NOMASK_STATUS_pke_alarm_nomask_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_alarm_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_ALARM_CLR_UNION;
#endif
#define SOC_PKE_ALARM_CLR_pke_alarm_clr_START (0)
#define SOC_PKE_ALARM_CLR_pke_alarm_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_inv_err_type : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_PKE_INV_ERR_TYPE_UNION;
#endif
#define SOC_PKE_INV_ERR_TYPE_pke_inv_err_type_START (0)
#define SOC_PKE_INV_ERR_TYPE_pke_inv_err_type_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_pc_addr : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_PKE_PC_ADDR_UNION;
#endif
#define SOC_PKE_PC_ADDR_pke_pc_addr_START (0)
#define SOC_PKE_PC_ADDR_pke_pc_addr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_flag_status : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_FLAG_STATUS_UNION;
#endif
#define SOC_PKE_FLAG_STATUS_pke_flag_status_START (0)
#define SOC_PKE_FLAG_STATUS_pke_flag_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_LOCK_UNION;
#endif
#define SOC_PKE_LOCK_pke_lock_START (0)
#define SOC_PKE_LOCK_pke_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_mask : 32;
    } reg;
} SOC_PKE_MASK_UNION;
#endif
#define SOC_PKE_MASK_pke_mask_START (0)
#define SOC_PKE_MASK_pke_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_key_backup : 32;
    } reg;
} SOC_PKE_KEY_BACKUP_UNION;
#endif
#define SOC_PKE_KEY_BACKUP_pke_key_backup_START (0)
#define SOC_PKE_KEY_BACKUP_pke_key_backup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_refresh : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_REFRESH_UNION;
#endif
#define SOC_PKE_REFRESH_pke_refresh_START (0)
#define SOC_PKE_REFRESH_pke_refresh_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_key_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_KEY_LOCK_UNION;
#endif
#define SOC_PKE_KEY_LOCK_pke_key_lock_START (0)
#define SOC_PKE_KEY_LOCK_pke_key_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_alarm_status0 : 32;
    } reg;
} SOC_PKE_ALARM_STATUS0_UNION;
#endif
#define SOC_PKE_ALARM_STATUS0_pke_alarm_status0_START (0)
#define SOC_PKE_ALARM_STATUS0_pke_alarm_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_alarm_status1 : 32;
    } reg;
} SOC_PKE_ALARM_STATUS1_UNION;
#endif
#define SOC_PKE_ALARM_STATUS1_pke_alarm_status1_START (0)
#define SOC_PKE_ALARM_STATUS1_pke_alarm_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_trng_request_ack : 1;
        unsigned int pke_trng_length : 8;
        unsigned int pke_trng_write_addr : 12;
        unsigned int pke_trng_data_type : 2;
        unsigned int pke_trng_ready : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_PKE_TRNG_REQUEST_UNION;
#endif
#define SOC_PKE_TRNG_REQUEST_pke_trng_request_ack_START (0)
#define SOC_PKE_TRNG_REQUEST_pke_trng_request_ack_END (0)
#define SOC_PKE_TRNG_REQUEST_pke_trng_length_START (1)
#define SOC_PKE_TRNG_REQUEST_pke_trng_length_END (8)
#define SOC_PKE_TRNG_REQUEST_pke_trng_write_addr_START (9)
#define SOC_PKE_TRNG_REQUEST_pke_trng_write_addr_END (20)
#define SOC_PKE_TRNG_REQUEST_pke_trng_data_type_START (21)
#define SOC_PKE_TRNG_REQUEST_pke_trng_data_type_END (22)
#define SOC_PKE_TRNG_REQUEST_pke_trng_ready_START (23)
#define SOC_PKE_TRNG_REQUEST_pke_trng_ready_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_time_out_value : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PKE_INT_TIME_OUT_VALUE_UNION;
#endif
#define SOC_PKE_INT_TIME_OUT_VALUE_pke_int_time_out_value_START (0)
#define SOC_PKE_INT_TIME_OUT_VALUE_pke_int_time_out_value_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_time_out_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PKE_INT_TIME_OUT_MASK_UNION;
#endif
#define SOC_PKE_INT_TIME_OUT_MASK_pke_int_time_out_mask_START (0)
#define SOC_PKE_INT_TIME_OUT_MASK_pke_int_time_out_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_time_out_clear : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PKE_INT_TIME_OUT_CLEAR_UNION;
#endif
#define SOC_PKE_INT_TIME_OUT_CLEAR_pke_int_time_out_clear_START (0)
#define SOC_PKE_INT_TIME_OUT_CLEAR_pke_int_time_out_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_time_out_mask_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PKE_INT_TIME_OUT_MASK_STATUS_UNION;
#endif
#define SOC_PKE_INT_TIME_OUT_MASK_STATUS_pke_int_time_out_mask_status_START (0)
#define SOC_PKE_INT_TIME_OUT_MASK_STATUS_pke_int_time_out_mask_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_int_time_out_nomask_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PKE_INT_TIME_OUT_NOMASK_STATUS_UNION;
#endif
#define SOC_PKE_INT_TIME_OUT_NOMASK_STATUS_pke_int_time_out_nomask_status_START (0)
#define SOC_PKE_INT_TIME_OUT_NOMASK_STATUS_pke_int_time_out_nomask_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_endian_change : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_PKE_ENDIAN_CHANGE_UNION;
#endif
#define SOC_PKE_ENDIAN_CHANGE_pke_endian_change_START (0)
#define SOC_PKE_ENDIAN_CHANGE_pke_endian_change_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_iram : 32;
    } reg;
} SOC_PKE_IRAM_UNION;
#endif
#define SOC_PKE_IRAM_pke_iram_START (0)
#define SOC_PKE_IRAM_pke_iram_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_dram : 32;
    } reg;
} SOC_PKE_DRAM_UNION;
#endif
#define SOC_PKE_DRAM_pke_dram_START (0)
#define SOC_PKE_DRAM_pke_dram_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
