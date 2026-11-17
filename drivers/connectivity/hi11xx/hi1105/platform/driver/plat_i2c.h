/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: plat_i2c.c header file
 * Author: platform drivers
 */
 
#ifndef __PLAT_I2C_H__
#define __PLAT_I2C_H__

#include "plat_type.h"

int32_t mpxx_i2c_init(void);
void mpxx_i2c_exit(void);

#endif