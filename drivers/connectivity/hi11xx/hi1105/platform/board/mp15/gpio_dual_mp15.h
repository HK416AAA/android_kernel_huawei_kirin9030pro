/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * Description: Dual MP15 gpio board-level implementation header file.
 * Author: platform drivers
 */

#ifndef _GPIO_DUAL_MP15_H_
#define _GPIO_DUAL_MP15_H_

#ifdef _PRE_DUAL_CHIP
#include <linux/platform_device.h>
#include "plat_gpio.h"

/* note: CHIP2 GPIO TYPE reuse existing GPIO definitions  */
enum chip2_gpio_type {
    CHIP_POWR_CHIP2     = GT_POWER,       // reuse GT_POWER
    W_POWER_CHIP2       = G_POWER,        // reuse G_POWER
    W_WKUP_HOST_CHIP2   = GT_WKUP_HOST,   // reuse GT_WKUP_HOST
    HOST_WKUP_W_CHIP2   = HOST_WKUP_GT,   // reuse HOST_WKUP_GT
    CHIP2_GPIO_TYPE_BUFF
};

int32_t dual_mp15_gpio_init(struct platform_device *pdev);
void dual_mp15_gpio_remove(struct platform_device *pdev);
enum gpio_type conn_get_gpio_type_by_id(int32_t dev_id, enum gpio_type type);
#endif
#endif
