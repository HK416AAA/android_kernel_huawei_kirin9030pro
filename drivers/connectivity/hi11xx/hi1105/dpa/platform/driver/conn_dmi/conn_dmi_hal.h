/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi 抽象层对外接口
 * Author: dpa drivers
 */

#ifndef CONN_DMI_HAL_H
#define CONN_DMI_HAL_H

#include "conn_dmi_drv.h"

enum dmi_hal_tran_type {
    DMI_HAL_TYPE_MSG,
    DMI_HAL_TYPE_HCC,
    DMI_HAL_TYPE_OAM,
    DMI_HAL_TYPE_BUF
};

typedef int32_t(*conn_dmi_hal_rx_func)(uint8_t *buf, uint16_t buf_len);
typedef int32_t(*conn_dmi_hal_rx_err_func)(uint8_t *buf, uint16_t buf_len);

int32_t conn_dmi_hal_init(void);
int32_t conn_dmi_hal_send(enum dmi_hal_tran_type trans_type, uint8_t *buf, uint16_t buf_len);
uint8_t *conn_dmi_hal_alloc_buf(uint16_t len);
void conn_dmi_hal_free_buf(uint8_t *buf);
int32_t conn_dmi_hal_rx_register(enum dmi_hal_tran_type trans_type,
                                 conn_dmi_hal_rx_func rx, conn_dmi_hal_rx_err_func rx_err);

#endif // CONN_DMI_HAL_H