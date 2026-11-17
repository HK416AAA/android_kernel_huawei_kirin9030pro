/*
 * Copyright (c) @CompanyNameMagicTag 2021-2024. All rights reserved.
 * 功能说明 : dpe_sync_hmac.c
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年07月5日
 */

#include "conn_dmi_msg.h"
#include "dpe_vsp.h"
#include "dpe_vsp_source.h"
#include "dpe_sync_hmac.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_SYNC_HMAC_C

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD

typedef void (*dpa_hmac_dmi_msg_handle)(hmac_dpe_wifi_msg_stru *);
dpa_hmac_dmi_msg_handle g_hmac_dmi_msg_handle[DMI_WIFI_MSG_BUTT] = {
    NULL,                                   /* DMI_WIFI_MSG_START */
    NULL,                                   /* DMI_WIFI_MSG_TX_ADDBA */
    dpe_vsp_init_proc,                      /* HMAC2DPE_VSP_INIT_MSG */
    dpe_vsp_context_init_ring_proc,         /* HMAC2DPE_VSP_RING_INIT_MSG */
    dpe_vsp_source_init_timer_proc,         /* HMAC2DPE_VSP_SOURCE_TIMER_INIT_MSG */
    dpe_vsp_deinit_common_timer_proc,       /* HMAC2DPE_VSP_COMMON_TIMER_DEINIT_MSG */
    dpe_vsp_start_timer_proc,               /* HMAC2DPE_VSP_START_TIMER_MSG */
    dpe_vsp_stop_timer_proc,                /* HMAC2DPE_VSP_STOP_TIMER_MSG */
    dpe_vsp_stop_timer_no_pm_wakeu_proc,    /* HMAC2DPE_VSP_STOP_TIMER_NO_PM_MSG */
    dpe_vsp_source_timeout_proc,            /* HMAC2DPE_VSP_SOURCE_TIMEOUT_MSG */
    dpe_vsp_tx_packet_proc,                 /* HMAC2DPE_VSP_TX_PKT_MSG */
    dpe_vsp_tx_complete_proc,               /* HMAC2DPE_VSP_TX_COMP_MSG */
    dpe_vsp_get_timestamp_proc,             /* HMAC2DPE_VSP_GET_TIMESTAMP_MSG */
};

int32_t dpe_sync_event_proc(uint8_t *buf, uint16_t buf_len)
{
    hmac_dpe_wifi_msg_stru *msg = (hmac_dpe_wifi_msg_stru *)buf;

    if (!msg || msg->msg_type >= DMI_WIFI_MSG_BUTT || !g_hmac_dmi_msg_handle[msg->msg_type]) {
        return OAL_FAIL;
    }

    g_hmac_dmi_msg_handle[msg->msg_type](msg);

    if (conn_dmi_msg_data_send(CONN_DMI_MSG_WIFI_MSG, (uint8_t *)msg, sizeof(hmac_dpe_wifi_msg_stru)) != OAL_SUCC) {
        oam_error_log1(0, 0, "{dpe_sync_event_proc::msg type[%d] send fail}", msg->msg_type);
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

#endif
