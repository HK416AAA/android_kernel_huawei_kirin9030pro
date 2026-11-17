/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#ifndef VI5302_PLATFORM_H
#define VI5302_PLATFORM_H

#include "vi5302.h"

int32_t vi5302_write_byte(vi5302_dev dev, uint16_t reg, uint8_t data);
int32_t vi5302_read_byte(vi5302_dev dev, uint16_t reg, uint8_t *data);
int32_t vi5302_write_multibytes(vi5302_dev dev, uint16_t reg, uint8_t *data, int32_t count);
int32_t vi5302_read_multibytes(vi5302_dev dev, uint16_t reg, uint8_t *data, int32_t count);
int32_t vi5302_write_reg_offset(vi5302_dev dev, uint16_t reg, uint8_t offset, uint8_t data);
int32_t vi5302_read_reg_offset(vi5302_dev dev, uint16_t reg, uint8_t offset, uint8_t *data);

 #endif
