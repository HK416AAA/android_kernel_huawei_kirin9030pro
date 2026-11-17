/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oam适配, 用于发送oam日志
 * Author: dpa drivers
 */

#include <stdint.h>
#include <stddef.h>
#include "oal_util.h"
#include "conn_dmi_hal.h"

int32_t conn_dmi_oam_send(uint8_t *param, uint16_t len)
{
    int32_t ret;
    uint8_t *dmi_hal_buf = NULL;

    // 检查输入参数是否有效
    if (param == NULL || len == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_oam_send param check fail");
        return -OAL_FAIL;
    }

    // 分配缓冲区
    dmi_hal_buf = conn_dmi_hal_alloc_buf(len);
    if (dmi_hal_buf == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi oam hal alloc buf fail");
        return -OAL_ENOMEM;
    }

    // 安全地复制内存
    if (memcpy_s(dmi_hal_buf, len, param, len) != EOK) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi oam memcpy_s fail");
        conn_dmi_hal_free_buf(dmi_hal_buf);
        return -OAL_FAIL;
    }

    // 发送数据
    ret = conn_dmi_hal_send(DMI_HAL_TYPE_OAM, dmi_hal_buf, len);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi oam send fail, ret = %d", ret);
        conn_dmi_hal_free_buf(dmi_hal_buf);
        return ret;
    }

    // 释放缓冲区
    conn_dmi_hal_free_buf(dmi_hal_buf);
    return OAL_SUCC;
}