/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat_oam.c header file
 * Author: plat drivers
 */

#ifndef PLAT_OAM_H
#define PLAT_OAM_H

#include <stdint.h>
#include "mpxx_oam.h"

#define TIME_STR_LENGTH    16

typedef enum {
    OAM_SAVE_LOG_STOP = 0,
    OAM_SAVE_LOG_START = 1
} oam_save_log_type_t;

typedef struct {
    uint8_t frame_start;
    uint8_t func_type;
    uint8_t prime_id;
    uint8_t arr_reserver[1];
    uint16_t frame_len;
    uint16_t sn;
} __attribute__((packed)) oam_msg_header_t;

extern plat_oam_save_handle g_plat_oam_save_handle;
uint32_t plat_oam_msg_init(void);

#endif
