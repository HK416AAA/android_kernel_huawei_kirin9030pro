/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: board_gpio.c header file
 * Author: platform drivers
 */

#ifndef BOARD_GPIO_H
#define BOARD_GPIO_H
#include <linux/platform_device.h>
#include "oal_types.h"

int32_t conn_board_gpio_init(struct platform_device *pdev);
void conn_board_gpio_remove(struct platform_device *pdev);
#endif
