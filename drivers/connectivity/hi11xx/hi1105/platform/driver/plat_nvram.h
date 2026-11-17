/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat_nvram.c header file
 * Author: platform drivers
 */

#ifndef PLAT_NVRAM_H
#define PLAT_NVRAM_H

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include <linux/types.h>
#include <linux/version.h>
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 35))
#ifndef _PRE_NO_HISI_NVRAM
#define HISI_NVRAM_SUPPORT
#endif
#endif

#define PLAT_NVRAM_NAME          "plat"
#define PLAT_NVRAM_ID            384
#define PLAT_NVRAM_SIZE          104

/* nv中存储的字段，每个字段含义在各自芯片的mpxx_nvram.h定义，规定每个字段占4字节，一共26个字段 */
typedef enum {
    NVRAM_FIELD_0,
    NVRAM_FIELD_1,
    NVRAM_FIELD_2,
    NVRAM_FIELD_3,
    NVRAM_FIELD_4,
    NVRAM_FIELD_5,
    NVRAM_FIELD_6,
    NVRAM_FIELD_7,
    NVRAM_FIELD_8,
    NVRAM_FIELD_9,
    NVRAM_FIELD_10,
    NVRAM_FIELD_11,
    NVRAM_FIELD_12,
    NVRAM_FIELD_13,
    NVRAM_FIELD_14,
    NVRAM_FIELD_15,
    NVRAM_FIELD_16,
    NVRAM_FIELD_17,
    NVRAM_FIELD_18,
    NVRAM_FIELD_19,
    NVRAM_FIELD_20,
    NVRAM_FIELD_21,
    NVRAM_FIELD_22,
    NVRAM_FIELD_23,
    NVRAM_FIELD_24,
    NVRAM_FIELD_25,
    NVRAM_FIELD_BUTT,
} nvram_field_enum;

typedef struct {
    int32_t (*read_nvram)(uint32_t *nv_buff, uint16_t read_byte_len);
    int32_t (*write_nvram)(uint8_t *data, nvram_field_enum field);
    int32_t (*write_efuse_to_nvram)(uint16_t *efuse_buff, nvram_field_enum *efuse_item, uint8_t item_num);
    int32_t (*read_dieid_from_nvram)(uint16_t *dieid_buff, uint16_t buff_byte_len);
    int32_t (*write_dieid_to_nvram)(uint16_t *efuse_buff);
} plat_nvram_ops_stru;

plat_nvram_ops_stru *get_plat_nvram_ops(void);

#endif