/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#ifndef VI5302_FIRMWARE_H
#define VI5302_FIRMWARE_H

#include "vi5302.h"
#define FIRMWARE_NUM 8192
extern uint8_t vi5302_firmware[FIRMWARE_NUM];
uint32_t vi5302_loadfirmware(vi5302_dev dev);

#endif

