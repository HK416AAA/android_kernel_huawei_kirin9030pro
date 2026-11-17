/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 短距dmi日志对外接口
 * Author: dpa drivers
 */

#ifndef CONN_DMI_OAM_H
#define CONN_DMI_OAM_H

#include <stdint.h>

int32_t conn_dmi_oam_send(uint8_t *param, uint16_t len);

#endif // CONN_DMI_OAM_H