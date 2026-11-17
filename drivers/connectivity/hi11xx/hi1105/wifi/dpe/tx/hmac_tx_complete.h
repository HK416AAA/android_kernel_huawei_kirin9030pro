/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Host发送完成模块
 * 作    者 : wifi
 * 创建日期 : 2020年4月23日
 */

#ifndef HMAC_TX_COMPLETE_H
#define HMAC_TX_COMPLETE_H

#include "dpe_wlan_user.h"
#include "hmac_tid_list.h"
#include "dpe_thread.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct {
    dpe_wlan_user_stru *dpe_user;
    uint8_t tid_no;
} hmac_tx_comp_info_stru;

extern hmac_tid_list_stru g_tx_comp_tid_tx_list;

static inline hmac_tx_comp_stru *hmac_get_tx_comp_mgmt(void)
{
    return &g_tx_comp_mgmt;
}

static inline void hmac_set_tx_comp_triggered(uint8_t hal_dev_id)
{
    oal_atomic_set(&g_hal_dev_tx_comp_triggered[hal_dev_id], OAL_TRUE);
}

static inline void hmac_clear_tx_comp_triggered(uint8_t hal_dev_id)
{
    oal_atomic_set(&g_hal_dev_tx_comp_triggered[hal_dev_id], OAL_FALSE);
}

static inline uint8_t hmac_get_tx_comp_triggered(uint8_t hal_dev_id)
{
    return oal_atomic_read(&g_hal_dev_tx_comp_triggered[hal_dev_id]) == OAL_TRUE;
}

static inline uint32_t hmac_get_tx_comp_scheduled_cnt(void)
{
    return g_tx_comp_mgmt.schedule_cnt;
}

void hmac_tx_complete_tid_ring_process(dpe_wlan_user_stru *dpe_user, hmac_tid_info_stru *tid_info);
void hmac_tx_comp_init(void);
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
int32_t hmac_tx_comp_thread(int para, mdrv_order_msg *msg);
#else
int32_t hmac_tx_comp_thread(void *p_data);
#endif
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
