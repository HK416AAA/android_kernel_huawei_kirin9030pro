/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dpa board适配
 * Author: platform drivers
 */

#ifndef BOARD_DPA_H
#define BOARD_DPA_H
#ifdef _PRE_PLAT_FEATURE_DPA

#include "oal_util.h"

int32_t dpa_wlan_open(void);
int32_t dpa_wlan_close(void);
int32_t wait_for_dap_ready(void);
void borad_dpa_init(void);

#endif // BOARD_DPA_H
#endif