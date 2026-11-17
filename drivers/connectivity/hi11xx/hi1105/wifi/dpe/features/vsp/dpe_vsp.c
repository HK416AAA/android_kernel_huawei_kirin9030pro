/*
 * Copyright (c) @CompanyNameMagicTag 2021-2024. All rights reserved.
 * 功能说明 : dpe_vsp_source.c
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年06月27日
 */

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_VSP_C

#include "dpe_vsp_source.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_tid_ring_switch.h"

dpe_vsp_info_stru g_dpe_vsp_info;

dpe_vsp_info_stru *dpe_get_vsp_info(void)
{
    return &g_dpe_vsp_info;
}

uint32_t dpe_vsp_init_common_timer(hal_mac_common_timer *timer)
{
    timer->timer_en = OAL_TRUE;
    timer->timer_mask_en = OAL_TRUE;
    timer->timer_unit = HAL_COMMON_TIMER_UNIT_1US;
    timer->timer_mode = HAL_COMMON_TIMER_MODE_ONE_SHOT;
    timer->func = NULL;
    timer->timer_id = g_wlan_spec_cfg->vsp_timer_id;

    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
        return OAL_FAIL;
    }
    if (hal_host_init_common_timer(timer) != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_vsp_init_common_timer :: init common timer[%d] fail", timer->timer_id);
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
        return OAL_FAIL;
    }
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_VSP_INIT_COMMON_TIMER);
    return OAL_SUCC;
}

uint32_t dpe_vsp_init(uint16_t user_id, uint16_t vap_id, uint8_t device_id)
{
    hal_host_device_stru *hal_device = hal_get_host_device(device_id);

    if (!hal_device) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_vsp_init::hal_device NULL}");
        return OAL_FAIL;
    }

    g_dpe_vsp_info.tid_info[DPE_VSP_TYPE_VIDEO] = dpe_get_tx_tid_info(user_id, WLAN_TIDNO_VSP);
    if (g_dpe_vsp_info.tid_info[DPE_VSP_TYPE_VIDEO] == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_vsp_init::tid_info[VSP_TYPE_VIDEO] NULL}");
        return OAL_FAIL;
    }

    g_dpe_vsp_info.tid_info[DPE_VSP_TYPE_SX] = dpe_get_tx_tid_info(user_id, WLAN_TIDNO_VIDEO);
    if (g_dpe_vsp_info.tid_info[DPE_VSP_TYPE_SX] == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_vsp_init::tid_info[VSP_TYPE_SX] NULL}");
        return OAL_FAIL;
    }

    g_dpe_vsp_info.user = dpe_wlan_user_get(user_id);
    g_dpe_vsp_info.vap = dpe_wlan_vap_get(vap_id);
    g_dpe_vsp_info.host_hal_device = hal_device;

    /* remember to release */
    dpe_tid_tx_lock_init(&g_dpe_vsp_info.vsp_lock);
    
    return OAL_SUCC;
}

void dpe_vsp_init_proc(hmac_dpe_wifi_msg_stru *msg)
{
    msg->param0 = dpe_vsp_init((uint16_t)msg->param0, (uint16_t)msg->param1, (uint8_t)msg->param2);
}

void dpe_vsp_stop_timer(void)
{
    g_dpe_vsp_info.timer.timer_en = OAL_FALSE;
    hal_host_set_mac_common_timer(&g_dpe_vsp_info.timer);
}

void dpe_vsp_stop_timer_proc(hmac_dpe_wifi_msg_stru *msg)
{
    dpe_vsp_stop_timer();
}

void dpe_vsp_stop_timer_no_pm_wakeup(void)
{
    g_dpe_vsp_info.timer.timer_en = OAL_FALSE;
    hal_host_set_mac_common_timer_no_pm_wakeup(&g_dpe_vsp_info.timer);
}

void dpe_vsp_stop_timer_no_pm_wakeu_proc(hmac_dpe_wifi_msg_stru *msg)
{
    dpe_vsp_stop_timer_no_pm_wakeup();
}

void dpe_vsp_start_timer(uint32_t start_time, uint32_t timeout_us)
{
    g_dpe_vsp_info.timer.start_time = start_time;
    g_dpe_vsp_info.timer.common_timer_val = timeout_us;
    g_dpe_vsp_info.timer.timer_en = OAL_TRUE;
    hal_host_set_mac_common_timer(&g_dpe_vsp_info.timer);
}

void dpe_vsp_start_timer_proc(hmac_dpe_wifi_msg_stru *msg)
{
    dpe_vsp_start_timer(msg->param0, msg->param1);
}

uint32_t dpe_vsp_get_timestamp(void)
{
    uint32_t tsf = 0;

    if (oal_any_null_ptr2(g_dpe_vsp_info.host_hal_device, g_dpe_vsp_info.vap)) {
        return 0;
    }

    return hal_host_get_tsf_lo(g_dpe_vsp_info.host_hal_device, g_dpe_vsp_info.vap->hal_vap_id, &tsf) ? tsf : 0;
}

void dpe_vsp_get_timestamp_proc(hmac_dpe_wifi_msg_stru *msg)
{
    msg->param0 = dpe_vsp_get_timestamp();
}

void dpe_vsp_deinit_common_timer(void)
{
    hal_mac_common_timer *timer = &g_dpe_vsp_info.timer;

    timer->timer_en = OAL_FALSE;
    hal_host_set_mac_common_timer(timer);
}

void dpe_vsp_deinit_common_timer_proc(hmac_dpe_wifi_msg_stru *msg)
{
    dpe_vsp_deinit_common_timer();
}

void dpe_vsp_clear_tx_ring(hmac_tid_info_stru *tid_info)
{
    hmac_msdu_info_ring_stru *tx_ring = &tid_info->tx_ring;

    hmac_wait_tx_ring_empty(tid_info);
    hmac_tx_ring_release_all_netbuf(tx_ring);
}

static uint32_t dpe_vsp_tid_ring_switch(hmac_tid_info_stru *tid_info)
{
    uint8_t cnt = 5; // 最多重试5次

    if (tid_info == NULL || g_dpe_vsp_info.user == NULL) {
        return OAL_FAIL;
    }

    while (oal_atomic_read(&tid_info->ring_tx_mode) != HOST_RING_TX_MODE &&
        oal_atomic_read(&tid_info->ring_tx_mode) != D2H_SWITCHING_MODE && cnt != 0) {
        hmac_tid_ring_switch(g_dpe_vsp_info.user->us_assoc_id, tid_info, HOST_RING_TX_MODE);
        oal_msleep(2); // 间隔2ms
        cnt--;
    }

    if (oal_atomic_read(&tid_info->ring_tx_mode) == HOST_RING_TX_MODE ||
        oal_atomic_read(&tid_info->ring_tx_mode) == D2H_SWITCHING_MODE) {
        return OAL_SUCC;
    } else {
        oam_error_log2(0, OAM_SF_DPA, "dpe_vsp_tid_ring_switch:FAIL! ring_tx_mode[%d]cnt[%d]",
            oal_atomic_read(&tid_info->ring_tx_mode), cnt);
        return OAL_FAIL;
    }
}

uint32_t dpe_vsp_context_init_ring(uint8_t vsp_type)
{
    hmac_tid_info_stru *tid_info = g_dpe_vsp_info.tid_info[vsp_type];

    if (tid_info == NULL) {
        return OAL_FAIL;
    }

    hmac_tid_info_queue_release(tid_info);
    dpe_vsp_clear_tx_ring(tid_info);

    return dpe_vsp_tid_ring_switch(tid_info);
}

void dpe_vsp_context_init_ring_proc(hmac_dpe_wifi_msg_stru *msg)
{
    msg->param0 = dpe_vsp_context_init_ring((uint8_t)msg->param0);
}
