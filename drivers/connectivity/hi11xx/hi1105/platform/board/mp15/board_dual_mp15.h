/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * Description: Resource acquisition.
 * Author: platform drivers
 */

#ifndef __BOARD_DUAL_MP15_H__
#define __BOARD_DUAL_MP15_H__

#ifdef _PRE_DUAL_CHIP
/* 其他头文件包含 */
#include "gpio_dual_mp15.h"

void hi_wlan_power_set_by_id(int32_t dev_id, int32_t on);
void board_callback_init_dual_mp15_power(void);
#endif
#endif
