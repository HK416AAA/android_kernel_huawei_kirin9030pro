/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef _GOODIX_TS_UTILS_H__
#define _GOODIX_TS_UTILS_H__

#include <linux/byteorder/generic.h>
#include "hm_os_sys.h"

static inline u8 checksum_u8(u8 *data, int len)
{
    u8 chksum = 0;
    int i = 0;

    for (i = 0; i < len; i++) {
        chksum += data[i];
    }

    return chksum;
}

static inline u16 checksum_be16(u8 *data, u32 size)
{
    u16 checksum = 0;
    u32 i;

    for (i = 0; i < size; i += sizeof(u16)) {
        checksum += be16_to_cpup((const __be16 *)(data + i));
    }
        
    return checksum;
}

#endif
