/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe main.c 的头文件
 */

#ifndef DPE_MAIN_H
#define DPE_MAIN_H

#include "oal_ext_if.h"
uint8_t dpe_is_trx_busy(void);
int32_t dpe_wifi_on_init(uint8_t *buf, uint16_t buf_len);
int32_t dpe_wifi_off_deinit(uint8_t *buf, uint16_t buf_len);
void dpe_module_init(void);
void dpe_dmi_register(void);
#endif
