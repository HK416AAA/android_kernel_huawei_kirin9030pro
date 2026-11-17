
/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpa host 回调注册
 * 作    者 : xianglei
 * 创建日期 : 2025年5月23日
 */
#include "conn_dmi_msg.h"
#include "hmac_tx_data.h"
#include "dpe_dpa_intf.h"
#include "hmac_invoke_dpe.h"
#include "hmac_sync_dpe.h"
#include "hmac_register_dpa.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_REGISTER_DPA_C

typedef void (*hmac_dpa_dmi_msg_handle)(uint8_t *, uint8_t);
hmac_dpa_dmi_msg_handle g_dpa_dmi_msg_handle[DMI_WIFI_MSG_BUTT] = {
    NULL,                         /* DMI_WIFI_MSG_START */
    hmac_tx_addba_proc,           /* DMI_WIFI_MSG_TX_ADDBA */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_INIT_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_RING_INIT_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_SOURCE_TIMER_INIT_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_COMMON_TIMER_DEINIT_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_START_TIMER_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_STOP_TIMER_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_STOP_TIMER_NO_PM_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_SOURCE_TIMEOUT_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_TX_PKT_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_TX_COMP_MSG */
    hmac_sync_dpa_event_cb,       /* HMAC2DPE_VSP_GET_TIMESTAMP_MSG */
};

int32_t hmac_recv_dpa_dmi_msg(uint8_t *buf, uint8_t buf_len)
{
    uint32_t msg_type = *(uint32_t*)buf;

    if (msg_type == DMI_WIFI_MSG_TX_ADDBA) {
        hmac_tx_addba_proc(buf, buf_len);
        // 如果是dpa复位，在dpa未完成初始化时，不可以向dpa下发dmi消息。
        if (wal_dfr_is_dpa_reset() == OAL_TRUE) {
            return OAL_FAIL;
        }
        conn_dmi_msg_data_send(CONN_DMI_MSG_WIFI_MSG, buf, buf_len); // 回送DPE
    } else {
        oam_error_log2(0, OAM_SF_TX, "{hmac_recv_dpa_dmi_msg:: msg_type %d, len %d}", msg_type, buf_len);
    }
    return 0;
}

void hmac_wlan_dpe_cb_register(void)
{
    /* WIFI DPE rx filter->GRO->host回调函数注册 */
    if (dpe_dpa_sms_rx_callback_register_ops(hmac_rx_skb_from_gro) != OAL_SUCC) {
        oal_io_print("hmac_wlan_dpe_cb_register::register fail!\r\n");
    }
    /* DPA 往 ACPU msg通用接口 */
    if (conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_MSG, hmac_recv_dpa_dmi_msg) != OAL_SUCC) {
        oal_io_print("hmac_wlan_dpe_cb_register::register fail!\r\n");
    }
    if (dpe_dpa_sms_tx_unblock_cb_register(hmac_dpa_sms_tx_unblock_state_notify) != OAL_SUCC) {
        oal_io_print("dpe_dpa_sms_tx_unblock_cb_register::register fail!\r\n");
    }
    oal_io_print("hmac_wlan_dpe_cb_register::register wifi dmi msg\r\n");
}