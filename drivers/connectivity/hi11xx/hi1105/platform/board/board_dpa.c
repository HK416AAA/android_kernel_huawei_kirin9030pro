/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dpa board层适配
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_DPA
#include "conn_dmi_msg.h"
#include "oal_schedule.h"
#include "oal_util.h"
#include "board_dpa.h"

oal_completion g_dpa_open_ready;
oal_completion g_dpa_close_ready;
oal_completion g_dpa_ready;


int32_t dpa_open_ack(uint8_t type, void *priv)
{
    oal_io_print("dpa_open_ack\n");
    complete_all(&g_dpa_open_ready);
    return 0;
}

int32_t dpa_close_ack(uint8_t type, void *priv)
{
    oal_io_print("dpa_close_ack\n");
    complete_all(&g_dpa_close_ready);
    return 0;
}

int32_t dpa_ready_ack(uint8_t type, void *priv)
{
    oal_io_print("dpa_ready_ack\n");
    complete_all(&g_dpa_ready);
    return 0;
}


int32_t dpa_wlan_close(void)
{
    int32_t ret;
    oal_init_completion(&g_dpa_close_ready);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_CLOSE, dpa_close_ack, NULL);
    ret = oal_wait_for_completion_timeout(&g_dpa_close_ready, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC));
    if (ret == 0) {
        oal_io_print("dpa_wlan_close wait completion fail !\n");
        return -OAL_EFAIL;
    }
    oal_io_print("dpa_wlan_close %d\n", ret);
    return OAL_SUCC;
}

int32_t dpa_wlan_open(void)
{
    int32_t ret;
    oal_init_completion(&g_dpa_open_ready);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_OPEN, dpa_open_ack, NULL);
    ret = oal_wait_for_completion_timeout(&g_dpa_open_ready, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC));
    if (ret == 0) {
        oal_io_print("dpa_wlan_open wait completion fail !\n");
        return -OAL_EFAIL;
    }
    oal_io_print("dpa_wlan_open %d\n", ret);
    return OAL_SUCC;
}

int32_t wait_for_dap_ready(void)
{
    int32_t ret;
    oal_init_completion(&g_dpa_ready);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_WIFI_READY, dpa_ready_ack, NULL);
    ret = oal_wait_for_completion_timeout(&g_dpa_ready, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC));
    if (ret == 0) {
        oal_io_print("wait_for_dap_ready wait completion fail !\n");
        return -OAL_EFAIL;
    }
    oal_io_print("g_dpa_ready %d\n", ret);
    return OAL_SUCC;
}

void borad_dpa_init(void)
{
    oal_init_completion(&g_dpa_open_ready);
    oal_init_completion(&g_dpa_close_ready);
    oal_init_completion(&g_dpa_ready);
}

#endif