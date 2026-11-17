/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:pm wlan dpa functional module
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_DPA
#define MPXX_LOG_MODULE_NAME     "[WLAN_DPA_PM]"
#include "plat_pm_dpa.h"
#include "conn_dmi_msg.h"
#include "pcie_linux.h"
#include "plat_pm.h"

static char *g_disallow_sleep_cont_str[DISALLOW_SLEEP_BUTT] = {
    [DISALLOW_SLEEP_POWER_SHUTDOWN] = "power shutdown",
    [DISALLOW_SLEEP_PM_NOT_ENABLE] = "pm not enable",
    [DISALLOW_SLEEP_WIFI_SRV_FORBID] = "wifi srv forbid",
    [DISALLOW_SLEEP_DPA_DISALLOW] = "dpa disallow",
    [DISALLOW_SLEEP_ETE_NOT_EMPTY] = "ete not empty",
};

static int32_t wlan_pm_d2a_allow_sleep_msg_handler(pm_msg_t *pm_msg)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa_allow_sleep");
    oal_atomic_set(&dpa_pm->dpa_allow_sleep, 1);
    return OAL_SUCC;
}

static int32_t wlan_pm_d2a_allow_sleep_ack_handler(pm_msg_t *pm_msg)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    dpa_pm->dpa_sleep_stage = SLEEP_ALLOW_RCV;

    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa allow sleep ack");
    oal_complete(&dpa_pm->dpa_sleep_request_ack);
    return OAL_SUCC;
}

static int32_t wlan_pm_d2a_disallow_sleep_ack_handler(pm_msg_t *pm_msg)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    dpa_pm->dpa_sleep_stage = SLEEP_DISALLOW_RCV;
    if (pm_msg->msg_cont >= DISALLOW_SLEEP_BUTT) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "dpa disallow sleep err msg_cont[%d]", pm_msg->msg_cont);
    } else {
        oal_print_mpxx_log(MPXX_LOG_INFO, "dpa disallow sleep cont[%s]", g_disallow_sleep_cont_str[pm_msg->msg_cont]);
    }

    oal_complete(&dpa_pm->dpa_sleep_request_ack);
    return OAL_SUCC;
}

static int32_t wlan_pm_d2a_sleep_succ_done_handler(pm_msg_t *pm_msg)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa_sleep_succ_done");
    oal_complete(&dpa_pm->dpa_sleep_succ_done);
    return OAL_SUCC;
}

static int32_t wlan_pm_d2a_wakeup_request_msg_handler(pm_msg_t *pm_msg)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    int32_t ret;
    uint8_t msg_buff;
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_atomic_set(&dpa_pm->dpa_allow_sleep, 0);

    /* 告知DPA，收到DPA的唤醒请求 */
    msg_buff = A2D_WAKEUP_REQ_ACK;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg_buff, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_WAKEUP_REQ_ACK] fail! ret = %d", ret);
        return ret;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "dmi send msg[A2D_WAKEUP_REQ_ACK]");

    if (wlan_pm_wakeup_host() != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa wakeup host fail");
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t wlan_pm_d2a_wakeup_request_ack_handler(pm_msg_t *pm_msg)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa_wakeup_request_ack");
    oal_complete(&dpa_pm->dpa_wakeup_request_ack);
    return OAL_SUCC;
}

static int32_t wlan_pm_d2a_wakeup_succ_ack_handler(pm_msg_t *pm_msg)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa_wakeup_succ_done");
    oal_complete(&dpa_pm->dpa_wakeup_succ_done);
    return OAL_SUCC;
}

static dpa_pm_rx_msg_handler g_dpa_pm_rx_msg_handler[D2A_RX_MSG_BUTT] = {
    [D2A_ALLOW_SLEEP_MSG] = wlan_pm_d2a_allow_sleep_msg_handler,
    [D2A_ALLOW_SLEEP_ACK] = wlan_pm_d2a_allow_sleep_ack_handler,
    [D2A_DISALLOW_SLEEP_ACK] = wlan_pm_d2a_disallow_sleep_ack_handler,
    [D2A_SLEEP_SUCC_ACK] = wlan_pm_d2a_sleep_succ_done_handler,
    [D2A_WAKEUP_REQ_MSG] = wlan_pm_d2a_wakeup_request_msg_handler,
    [D2A_WAKEUP_REQ_ACK] = wlan_pm_d2a_wakeup_request_ack_handler,
    [D2A_WAKEUP_SUCC_ACK] = wlan_pm_d2a_wakeup_succ_ack_handler,
};

void wlan_pm_send_wakeup_fail_to_dpa(void)
{
    int32_t ret;
    uint8_t msg;

    msg = A2D_WAKEUP_FAIL_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_WAKEUP_FAIL_MSG] fail! ret = %d", ret);
        // TODO 消息发送失败的DFR处理
        return;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "dmi send msg[A2D_WAKEUP_FAIL_MSG]");
}

void wlan_pm_send_disallow_sleep_to_dpa(struct wlan_pm_s *pst_wlan_pm)
{
    int32_t ret;
    uint8_t msg;
    dpa_pm_t *dpa_pm = NULL;
    dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return;
    }

    if (dpa_pm->dpa_sleep_stage != SLEEP_ALLOW_RCV) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "dpa don't send D2A_ALLOW_SLEEP_ACK, don't need send disallow msg");
        return;
    }

    msg = A2D_DISALOOW_SLEEP_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_DISALOOW_SLEEP_MSG] fail! ret = %d", ret);
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "dmi send msg[A2D_DISALOOW_SLEEP_MSG]");

    /* DPA侧重走睡眠流程，A核也重走睡眠流程 */
    oal_atomic_set(&dpa_pm->dpa_allow_sleep, 0);
    dpa_pm->dpa_sleep_stage = SLEEP_STAGE_INIT;
}

int32_t wlan_pm_wakeup_check_dpa(struct wlan_pm_s *pst_wlan_pm)
{
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    if (dpa_pm->dpa_cur_state == HOST_DISALLOW_TO_SLEEP) {
        return OAL_SUCC;
    }

    return OAL_SUCC_GO_ON;
}

int32_t wlan_pm_wakeup_request_to_dpa(struct wlan_pm_s *pst_wlan_pm)
{
    uint32_t time_left;
    uint8_t msg;
    int32_t ret;
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    if ((oal_atomic_read(&dpa_pm->dpa_allow_sleep) == 0)) {
        return OAL_SUCC;
    }

    oal_init_completion(&dpa_pm->dpa_wakeup_request_ack);

    /* A核主动唤醒DPA，发送唤醒请求 */
    msg = A2D_WAKEUP_REQ_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_WAKEUP_REQ_MSG] fail! ret = %d", ret);
        return ret;
    }

    time_left = oal_wait_for_completion_timeout(&dpa_pm->dpa_wakeup_request_ack,
                                                (uint32_t)oal_msecs_to_jiffies(W2D_WAKUP_MSG_WAIT_TIMEOUT));
    if (time_left == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_wakeup_request_to_dpa wait completion fail !\n");
        return -OAL_FAIL;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "wait D2A_WAKEUP_REQ_ACK succ");

    return OAL_SUCC;
}

int32_t wlan_pm_wakeup_succ_to_dpa(struct wlan_pm_s *pst_wlan_pm)
{
    uint32_t time_left;
    uint8_t msg;
    int32_t ret;
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_init_completion(&dpa_pm->dpa_wakeup_succ_done);

    msg = A2D_WAKEUP_SUCC_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_WAKEUP_SUCC_MSG] fail! ret = %d", ret);
        return ret;
    }

    time_left = oal_wait_for_completion_timeout(&dpa_pm->dpa_wakeup_succ_done,
                                                (uint32_t)oal_msecs_to_jiffies(W2D_WAKUP_MSG_WAIT_TIMEOUT));
    if (time_left == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_wakeup_succ_to_dpa wait completion fail !\n");
        return -OAL_FAIL;
    }

    oal_atomic_set(&dpa_pm->dpa_allow_sleep, 0);

    dpa_pm->dpa_cur_state = HOST_DISALLOW_TO_SLEEP;
    oal_print_mpxx_log(MPXX_LOG_INFO, "wlan pm dpa wakeup succ");
    return OAL_SUCC;
}

int32_t wlan_pm_sleep_check_dpa(struct wlan_pm_s *pst_wlan_pm)
{
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    if (oal_atomic_read(&dpa_pm->dpa_allow_sleep) == 0) {
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

int32_t wlan_pm_sleep_request_to_dpa(struct wlan_pm_s *pst_wlan_pm)
{
    uint32_t time_left;
    uint8_t msg;
    int32_t ret;
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    if (dpa_pm->dpa_sleep_stage == SLEEP_ALLOW_RCV) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "ACPU has received D2A_ALLOW_SLEEP_ACK, don't send A2D_SLEEP_REQ_MSG");
    }

    oal_init_completion(&dpa_pm->dpa_sleep_request_ack);

    dpa_pm->dpa_sleep_stage = SLEEP_REQ_SND;

    msg = A2D_SLEEP_REQ_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_SLEEP_REQ_MSG] fail! ret = %d", ret);
        return ret;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "dmi send msg[A2D_SLEEP_REQ_MSG]");

    time_left = oal_wait_for_completion_timeout(&dpa_pm->dpa_sleep_request_ack,
                                                (uint32_t)oal_msecs_to_jiffies(W2D_SLEEP_MSG_WAIT_TIMEOUT));
    if (time_left == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_sleep_request_to_dpa wait completion fail !\n");
        return -OAL_FAIL;
    }

    if (dpa_pm->dpa_sleep_stage != SLEEP_ALLOW_RCV) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "dpa disallow sleep");
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

int32_t wlan_pm_sleep_succ_to_dpa(struct wlan_pm_s *pst_wlan_pm)
{
    uint32_t time_left;
    uint8_t msg;
    int32_t ret;
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_init_completion(&dpa_pm->dpa_sleep_succ_done);

    dpa_pm->dpa_sleep_stage = SLEEP_CMD_SND;

    msg = A2D_SLEEP_SUCC_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_SLEEP_SUCC_MSG] fail! ret = %d", ret);
        return ret;
    }

    time_left = oal_wait_for_completion_timeout(&dpa_pm->dpa_sleep_succ_done,
                                                (uint32_t)oal_msecs_to_jiffies(W2D_SLEEP_MSG_WAIT_TIMEOUT));
    if (time_left == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_sleep_succ_to_dpa wait completion fail !\n");
        return -OAL_FAIL;
    }

    dpa_pm->dpa_cur_state = HOST_ALLOW_TO_SLEEP;
    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa sleep succ");
    return OAL_SUCC;
}

void wlan_pm_set_dpa_timeout(uint32_t timeout)
{
    int32_t ret;
    uint32_t pm_timeout = timeout;

    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return;
    }

    ret = conn_dmi_msg_data_send(CONN_DMI_MSG_SET_PM_TIMEOUT, (uint8_t *)&pm_timeout, sizeof(uint32_t));
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_set_dpa_timeout fail! ret = %d", ret);
    }
}

int32_t wlan_pm_enable_dpa_pm(void)
{
    uint8_t msg;
    int32_t ret;

    msg = A2D_ENABLE_PM_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_ENABLE_PM_MSG] fail! ret = %d", ret);
        return ret;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "dmi send msg[A2D_ENABLE_PM_MSG]");

    return OAL_SUCC;
}

int32_t wlan_pm_disable_dpa_pm(void)
{
    uint8_t msg;
    int32_t ret;

    msg = A2D_DISABLE_PM_MSG;
    ret = conn_dmi_msg_send(CONN_DMI_MSG_PM, &msg, sizeof(uint8_t), NULL, NULL);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi send msg[A2D_DISABLE_PM_MSG] fail! ret = %d", ret);
        return ret;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "dmi send msg[A2D_DISABLE_PM_MSG]");

    return OAL_SUCC;
}

static int32_t wlan_pm_dpa_pm_msg_proc(uint8_t *buf, uint8_t buf_len)
{
    int i;
    pm_msg_t *pm_msg = (pm_msg_t *)buf;
    if ((buf_len != (uint8_t)sizeof(pm_msg_t)) || (pm_msg->msg_id >= D2A_RX_MSG_BUTT)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_dpa_pm_msg_proc is err, buff_len[%u]", buf_len);
        for (i = 0; i < buf_len; i++) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "buff[%d]=%u", i, buf[i]);
        }
        return -OAL_FAIL;
    }

    return g_dpa_pm_rx_msg_handler[pm_msg->msg_id](pm_msg);
}

void dpa_pm_para_init(void)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    dpa_pm_t *dpa_pm = &wlan_pm_info->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return;
    }

    oal_atomic_set(&dpa_pm->dpa_allow_sleep, 0);
    dpa_pm->dpa_cur_state = HOST_DISALLOW_TO_SLEEP;
    dpa_pm->dpa_sleep_stage = SLEEP_STAGE_INIT;
}

int32_t dpa_pm_init(struct wlan_pm_s *pst_wlan_pm)
{
    int32_t ret;
    oal_pcie_linux_res *pst_pci_lres = NULL;
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    oal_atomic_set(&dpa_pm->dpa_allow_sleep, 0);
    dpa_pm->dpa_cur_state = HOST_ALLOW_TO_SLEEP;
    dpa_pm->dpa_sleep_stage = SLEEP_STAGE_INIT;
    oal_init_completion(&dpa_pm->dpa_sleep_request_ack);
    oal_init_completion(&dpa_pm->dpa_sleep_succ_done);
    oal_init_completion(&dpa_pm->dpa_wakeup_request_ack);
    oal_init_completion(&dpa_pm->dpa_wakeup_succ_done);

    conn_dmi_msg_regiser(CONN_DMI_MSG_PM, wlan_pm_dpa_pm_msg_proc);

    pst_pci_lres = (oal_pcie_linux_res *)pst_wlan_pm->pst_bus->data;
    if (pst_pci_lres != NULL) {
        ret = oal_pci_resource_sync(pst_pci_lres, OAL_FALSE);    // 发送CONN_DMI_MSG_POWERUP给DPA
        if (ret != OAL_SUCC) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "pci resource sync fail!\n");
            return -OAL_FAIL;
        }
    } else {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pst_pci_lres is NULL");
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa wlan init succ");

    return OAL_SUCC;
}

int32_t dpa_pm_deinit(struct wlan_pm_s *pst_wlan_pm)
{
    dpa_pm_t *dpa_pm = &pst_wlan_pm->dpm_pm_info;
    if (dpa_pm == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa_pm is NULL");
        return -OAL_FAIL;
    }

    conn_dmi_msg_regiser(CONN_DMI_MSG_PM, NULL);

    oal_print_mpxx_log(MPXX_LOG_INFO, "dpa wlan deinit succ");
    return OAL_SUCC;
}

#endif    // _PRE_PLAT_FEATURE_DPA