/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 短距dmi驱动层对外接口
 * Author: platform drivers
 */

#ifndef CONN_DMI_DRV_H
#define CONN_DMI_DRV_H
#ifdef _PRE_PLAT_FEATURE_DPA

#include "dpa_interface.h"

typedef int32_t (*conn_dmi_rx_func)(uint8_t *buf, uint16_t buf_len);
typedef int32_t (*conn_dmi_rx_err_func)(uint8_t *buf, uint16_t buf_len);

int32_t conn_dmi_drv_rx_register(conn_dmi_rx_func rx, conn_dmi_rx_err_func rx_err);
int32_t conn_dmi_drv_send(uint8_t *data, uint32_t data_len);
int32_t conn_dmi_drv_init(void);

#endif // CONN_DMI_DRV_H
#endif