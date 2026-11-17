/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat_sys_msg.c header file
 * Author: plat drivers
 */

#ifndef PLAT_SYS_MSG_H
#define PLAT_SYS_MSG_H

#include <stdint.h>

#define CHR_EXTEND_PARAM_MAX_LEN 128

enum {
    CHR_TYPE_EVENT = 0,
    CHR_TYPE_ERROR,
};

typedef struct chr_data_extend {
    uint8_t chr_type;
    uint8_t rsv;
    uint8_t event_id;
    uint8_t info1;
    uint8_t info2;
    uint16_t info3;
    uint8_t data_len;
    uint8_t data[CHR_EXTEND_PARAM_MAX_LEN];
} chr_data_extend_t;

uint32_t plat_sys_msg_init(void);

#endif
