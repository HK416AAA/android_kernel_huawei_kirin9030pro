/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: efuse_mp17c.c header file
 * Author: platform drivers
 */

#ifndef NVRAM_MP17C_H
#define NVRAM_MP17C_H

/* nv中存储的efuse字段，从起始地址开始与以下枚举一一对应，规定每个字段占4字节 */
typedef enum {
    MP17C_NVRAM_EFUSE_VER,            // NVRAM_FIELD_0
    MP17C_NVRAM_EFUSE_VBG_TIME,       // NVRAM_FIELD_1
    MP17C_NVRAM_EFUSE_CRC,            // NVRAM_FIELD_2 特殊字段：由此往上字段的crc值
    MP17C_NVRAM_EFUSE_DIEID1,         // NVRAM_FIELD_3
    MP17C_NVRAM_EFUSE_DIEID2,         // NVRAM_FIELD_4
    MP17C_NVRAM_EFUSE_DIEID3,         // NVRAM_FIELD_5
    MP17C_NVRAM_EFUSE_DIEID4,         // NVRAM_FIELD_6
    MP17C_NVRAM_EFUSE_DIEID5,         // NVRAM_FIELD_7
    MP17C_NVRAM_EFUSE_BUTT,           // NVRAM_FIELD_8
    /* 最后4字节存放前面100字节的crc校验值 */
    MP17C_NVRAM_EFUSE_TOTAL_CRC = 25, // NVRAM_FIELD_25
} mp17c_nv_efuse_enum;

void nvram_ops_init_mp17c(void);

#endif
