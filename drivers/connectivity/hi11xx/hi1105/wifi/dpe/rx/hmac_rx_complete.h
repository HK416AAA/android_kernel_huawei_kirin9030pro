/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Host发送完成模块
 * 作    者 : wifi
 * 创建日期 : 2020年4月23日
 */

#ifndef HMAC_RX_COMPLETE_H
#define HMAC_RX_COMPLETE_H

#include "host_hal_irq.h"
#include "host_hal_device.h"
#include "dpe_task.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

static inline hmac_rx_comp_stru *hmac_get_rx_comp_mgmt(void)
{
    return &g_rx_comp_mgmt;
}

static inline void hmac_clear_rx_comp_triggered(uint8_t hal_dev_id)
{
    oal_atomic_set(&g_hal_dev_rx_comp_triggered[hal_dev_id], OAL_FALSE);
}

static inline uint8_t hmac_get_rx_comp_triggered(uint8_t hal_dev_id)
{
    return oal_atomic_read(&g_hal_dev_rx_comp_triggered[hal_dev_id]) == OAL_TRUE;
}

void hmac_rx_comp_init(void);
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
int32_t dpe_rx_data_thread(int para, mdrv_order_msg *msg);
int32_t hmac_rx_comp_thread(int para, mdrv_order_msg *msg);
#else
int32_t dpe_rx_data_thread(void *p_data);
int32_t hmac_rx_comp_thread(void *p_data);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
