/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: pm dpa wlan functional module
 * Author: dpa drivers
 */

#define MPXX_LOG_MODULE_NAME "[DPA_WLAN_PM]"
#define MPXX_LOG_MODULE_NAME_VAR dpa_wlan_pm_loglevel

/* 头文件包含 */
#include <string.h>
#include "oal_util.h"
#include "osl_thread.h"
#include "osl_cpu.h"
#include "oam_wdk.h"
#include "oam_logger.h"
#include "hcc_master.h"
#include "pcie_host.h"
#include "conn_dmi_msg.h"
#include "bsp_console.h"
#include "dpa_exception_rst.h"
#include "bsp_slice.h"
#include "pm_wlan.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_PM_WLAN_C

#define PM_MAX_TRACE 0x40

static uint8_t g_pm_trace_idx = 0;
static uint8_t g_last_node = TRACE_BUTT;
static uint8_t g_last_core;

static oal_spin_lock_stru g_pm_trace_spinlock;
static trace_per_node_t g_pm_trace_flg[PM_MAX_TRACE];
static pm_wlan_str_t g_pm_wlan_info = { 0 };
static uint8_t g_timer_last_core;

pm_wlan_str_t *get_pm_wlan_struct_info(void)
{
    return &g_pm_wlan_info;
}

uint8_t pm_wlan_idle_thread_should_stop(void)
{
    return g_pm_wlan_info.pm_idle_thread.running_flag;
}

uint8_t pm_wlan_handler_thread_should_stop(void)
{
    return g_pm_wlan_info.pm_handler_thread.running_flag;
}

static int32_t pm_wlan_event_send_to_pm_idle_thread(uint16_t event)
{
    uint32_t ret;

    if ((event != DPA_ALLOW_SLEEP_EVENT) && (event != SLEEP_REQ_EVENT) && (event != WAKEUP_REQ_EVENT)) {
        oam_error_log1(0, OAM_SF_DPA, "event is err, event=%u", event);
        return -OAL_FAIL;
    }

    oam_info_log1(0, OAM_SF_DPA, "dpa send event[%u] to pm thread", event);

    ret = mdrv_kevent_send(g_pm_wlan_info.pm_idle_thread.task_id, BIT(event));
    if (ret != OAL_SUCC) {
        oam_error_log2(0, OAM_SF_DPA, "dpa trigger EVENT[%u] fail, ret[%u]", event, ret);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

int32_t pm_wlan_event_send_to_pm_process_thread(uint16_t event)
{
    uint32_t ret;

    if (event >= PM_THREAD_EVENT_BUFF) {
        oam_error_log1(0, OAM_SF_DPA, "event is err, event=%u", event);
        return -OAL_FAIL;
    }

    oam_info_log1(0, OAM_SF_DPA, "dpa send event[%u]", event);

    ret = mdrv_kevent_send(g_pm_wlan_info.pm_handler_thread.task_id, BIT(event));
    if (ret != OAL_SUCC) {
        oam_error_log2(0, OAM_SF_DPA, "dpa trigger EVENT[%u] fail, ret[%u]", event, ret);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

/* DPA RX消息处理 */
static int32_t pm_wlan_a2d_sleep_req_msg_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_SLEEP_REQ_MSG");
    pm_trace_node(TRACE_A2D_SLEEP_REQ);
    if (pm_wlan_event_send_to_pm_idle_thread(SLEEP_REQ_EVENT) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_disallow_sleep_msg_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_DISALLOW_SLEEP_MSG");
    pm_trace_node(TRACE_A2D_DISALLOW_SLEEP);
    if (pm_wlan_event_send_to_pm_process_thread(DISALLOW_SLEEP_EVENT) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_sleep_succ_msg_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_SLEEP_SUCC_MSG");
    pm_trace_node(TRACE_A2D_SLEEP_SUCC);
    if (pm_wlan_event_send_to_pm_process_thread(SLEEP_SUCC_EVENT) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_wakeup_req_msg_handler(uint8_t msg)
{
    int32_t ret;
    pm_msg_t pm_msg;

    oal_wake_lock(WIFI_WAKE_PM);

    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_WAKEUP_REQ_MSG");
    pm_trace_node(TRACE_A2D_WAKEUP_REQ);
    if (pm_wlan_event_send_to_pm_idle_thread(WAKEUP_REQ_EVENT) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "dpa trigger WAKEUP_REQ_EVENT fail!");
        return -OAL_FAIL;
    }

    pm_msg.msg_id = D2A_WAKEUP_REQ_ACK;
    ret = conn_dmi_msg_data_send(CONN_DMI_MSG_PM, (uint8_t *)&pm_msg, sizeof(pm_msg_t));
    if (ret != OAL_SUCC) {
        pm_trace_node(TRACE_D2A_WAKEUP_REQ_ACK_SEND_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "dmi send msg[D2A_WAKEUP_REQ_ACK] fail! ret = %d", ret);
        return ret;
    }

    pm_trace_node(TRACE_D2A_WAKEUP_REQ_ACK);
    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_wakeup_req_ack_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_WAKEUP_REQ_ACK");
    pm_trace_node(TRACE_A2D_WAKEUP_REQ_ACK);

    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_wakeup_fail_msg_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_WAKEUP_FAIL_MSG");
    pm_trace_node(TRACE_A2D_WAKEUP_FAIL);
    if (pm_wlan_event_send_to_pm_process_thread(WAKEUP_FAIL_EVENT) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_wakeup_succ_msg_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_WAKEUP_SUCC_MSG");
    pm_trace_node(TRACE_A2D_WAKEUP_SUCC);
    if (pm_wlan_event_send_to_pm_process_thread(WAKEUP_SUCC_EVENT) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_disable_pm_msg_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_DISABLE_PM_MSG");
    if (wlan_pm_disable() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "disable pm fail!!!");
        return -OAL_FAIL;
    }

    pm_trace_node(TRACE_PM_DISABLE);
    return OAL_SUCC;
}

static int32_t pm_wlan_a2d_enable_pm_msg_handler(uint8_t msg)
{
    oam_info_log0(0, OAM_SF_DPA, "dpa receive A2D_ENABLE_PM_MSG");
    if (wlan_pm_enable() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "enable pm fail!!!");
        return -OAL_FAIL;
    }

    pm_trace_node(TRACE_PM_ENABLE);
    return OAL_SUCC;
}

static pm_wlan_rx_msg_handler g_pm_wlan_rx_msg_handler[A2D_RX_MSG_BUTT] = {
    [A2D_SLEEP_REQ_MSG] = pm_wlan_a2d_sleep_req_msg_handler,
    [A2D_DISALLOW_SLEEP_MSG] = pm_wlan_a2d_disallow_sleep_msg_handler,
    [A2D_SLEEP_SUCC_MSG] = pm_wlan_a2d_sleep_succ_msg_handler,
    [A2D_WAKEUP_REQ_MSG] = pm_wlan_a2d_wakeup_req_msg_handler,
    [A2D_WAKEUP_REQ_ACK] = pm_wlan_a2d_wakeup_req_ack_handler,
    [A2D_WAKEUP_FAIL_MSG] = pm_wlan_a2d_wakeup_fail_msg_handler,
    [A2D_WAKEUP_SUCC_MSG] = pm_wlan_a2d_wakeup_succ_msg_handler,
    [A2D_DISABLE_PM_MSG] = pm_wlan_a2d_disable_pm_msg_handler,
    [A2D_ENABLE_PM_MSG] = pm_wlan_a2d_enable_pm_msg_handler,
};

static void pm_wlan_trigger_dfr(void)
{
    oam_error_log2(0, OAM_SF_DPA, "pm_wlan_trigger_dfr is running, sleep = %u, wakeup = %u",
        g_pm_wlan_info.sleep_stage, g_pm_wlan_info.wakeup_stage);
    pm_trace_node_debug_print();
    dpa_exception_submit(EXCEPTION_TYPE_PLAT_PM, NULL, 0);
}

void pm_wlan_set_wkup_sleep_stage(uint8_t state, uint8_t pm_stage)
{
    if ((state == STATE_SLEEP) && (pm_stage <= SLEEP_SUCC)) {
        g_pm_wlan_info.sleep_stage = pm_stage;
    } else if ((state == STATE_WAKEUP) && (pm_stage <= WAKEUP_SUCC)) {
        g_pm_wlan_info.wakeup_stage = pm_stage;
    } else {
        oam_error_log2(0, OAM_SF_DPA, "set dpa pm stage fail, state[%u] or stage[%u] maybe error", state, pm_stage);
    }
}

/*
 * 函 数 名  : pm_wlan_get_pm_sema
 * 功能描述  : 低功耗模块睡眠唤醒过程获取信号量
 * 输入参数  : pm_sema：睡眠唤醒信号量指针
 */
static int32_t pm_wlan_get_pm_sema(pm_wlan_smea_info_t *pm_sema)
{
    uint32_t ret;
    if (pm_sema->state == 0) {
        oam_warning_log0(0, OAM_SF_DPA, "pm_sema get after release");
    }

    ret = mdrv_sem_down(pm_sema->sema_id, WLAN_SLEEP_MSG_WAIT_TIMEOUT * mdrv_tick_persecond_get());
    if (ret != 0) {
        oam_error_log1(0, OAM_SF_DPA, "get sema timeout[3s], ret[%u]", ret);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : pm_wlan_release_pm_sema
 * 功能描述  : 低功耗模块睡眠唤醒过程释放信号量
 * 输入参数  : pm_sema：睡眠唤醒信号量指针
 */
static int32_t pm_wlan_release_pm_sema(pm_wlan_smea_info_t *pm_sema)
{
    uint32_t ret;
    if (pm_sema->state == 0) {
        oam_warning_log0(0, OAM_SF_DPA, "pm_sema release before get");
    }

    if (g_pm_wlan_info.dpa_exception_state != 1) {
        ret = mdrv_sem_up(pm_sema->sema_id);
        if (ret != OAL_SUCC) {
            oam_error_log1(0, OAM_SF_DPA, "release sema fail!!!, ret[%u]", ret);
            return -OAL_FAIL;
        }
        pm_sema->state = 0;
    }
    return OAL_SUCC;
}

uint32_t wlan_pm_enable(void)
{
    hcc_master_tx_transfer_lock();
    if (g_pm_wlan_info.wlan_pm_enable == OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_DPA, "dpa pm already enabled");
        return OAL_SUCC;
    }

    g_pm_wlan_info.wlan_pm_enable = OAL_TRUE;
    pm_wlan_reset_sleep_timer();
    oam_warning_log0(0, OAM_SF_DPA, "dpa pm enable succ");
    hcc_master_tx_transfer_unlock();
    return OAL_SUCC;
}

uint32_t wlan_pm_disable(void)
{
    hcc_master_tx_transfer_lock();
    if (g_pm_wlan_info.wlan_pm_enable == OAL_FALSE) {
        oam_warning_log0(0, OAM_SF_DPA, "dpa pm already disabled");
        hcc_master_tx_transfer_unlock();
        return OAL_SUCC;
    }

    if (g_pm_wlan_info.dpa_allow_sleep == DPA_ALLOW_TO_SLEEP) {
        if (pm_wlan_wakeup_dpa_handler(WAKEUP_SOURCE_DPA) != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "dpa wakeup fail");
        }
    }

    g_pm_wlan_info.wlan_pm_enable = OAL_FALSE;
    g_pm_wlan_info.timeout_curr_cnt = 0;
    oam_warning_log0(0, OAM_SF_DPA, "dpa pm disable succ");
    hcc_master_tx_transfer_unlock();
    return OAL_SUCC;
}

static void wlan_pm_set_timeout(uint32_t count)
{
    g_pm_wlan_info.timeout_cnt = count;
    g_pm_wlan_info.timeout_curr_cnt = 0;
    g_pm_wlan_info.packet_cnt = 0;
}

void wlan_pm_wkup_src_debug_set(uint32_t en)
{
    g_pm_wlan_info.wkup_src_print_en = en;
}

uint32_t wlan_pm_wkup_src_debug_get(void)
{
    return g_pm_wlan_info.wkup_src_print_en;
}

uint8_t pm_wlan_dpa_get_acpu_state(void)
{
    return g_pm_wlan_info.acpu_state;
}

/* 睡眠流程 */
static int32_t pm_wlan_dpa_to_acpu_allow_sleep_event(void)
{
    pm_msg_t pm_msg;
    int32_t ret;

    if (g_pm_wlan_info.wlan_power_state == POWER_STATE_SHUTDOWN) {
        oam_error_log0(0, OAM_SF_DPA, "dpa wlan isn't powerup");
        return OAL_SUCC;
    }

    if (g_pm_wlan_info.wlan_pm_enable == OAL_FALSE) {
        g_pm_wlan_info.dpa_allow_sleep = DPA_DISALLOW_TO_SLEEP;
        return OAL_SUCC;
    }

    if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_pm_pause_func != NULL) {
        if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_pm_pause_func() == OAL_TRUE) {    // 业务不同意睡
            oam_info_log0(0, OAM_SF_DPA, "wlan srv pm pause!!!");
            g_pm_wlan_info.wifi_srv_sleep_forbid++;
            pm_wlan_reset_sleep_timer();
            return OAL_SUCC;
        }
    }

    pm_msg.msg_id = D2A_ALLOW_SLEEP_MSG;
    ret = conn_dmi_msg_data_send(CONN_DMI_MSG_PM, (uint8_t *)&pm_msg, sizeof(pm_msg_t));
    if (ret != OAL_SUCC) {
        pm_trace_node(TRACE_D2A_ALLOW_SLEEP_SEND_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "dmi send msg[D2A_ALLOW_SLEEP_MSG] fail! ret = %d", ret);
        pm_wlan_reset_sleep_timer();
        return ret;
    }

    g_pm_wlan_info.dpa_allow_sleep = DPA_ALLOW_TO_SLEEP;
    g_pm_wlan_info.dpa_allow_sleep_cnt++;

    pm_trace_node(TRACE_D2A_ALLOW_SLEEP);
    return OAL_SUCC;
}

static int32_t pm_wlan_sleep_check(dpa_pm_disallow_sleep_cont_t *sleep_cont)
{
    if (g_pm_wlan_info.wlan_power_state == POWER_STATE_SHUTDOWN) {
        *sleep_cont = DISALLOW_SLEEP_POWER_SHUTDOWN;
        oam_error_log0(0, OAM_SF_DPA, "dpa wlan isn't powerup");
        return -OAL_FAIL;
    }

    if (g_pm_wlan_info.dpa_exception_state == 1) {
        oam_error_log0(0, OAM_SF_DPA, "dpa is doing dfr, disallow sleep");
        return -OAL_FAIL;
    }

    if (g_pm_wlan_info.wlan_pm_enable == OAL_FALSE) {
        *sleep_cont = DISALLOW_SLEEP_PM_NOT_ENABLE;
        oam_info_log0(0, OAM_SF_DPA, "wlan dpa pm is disabled!");
        return -OAL_FAIL;
    }

    if ((g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_pm_pause_func != NULL) &&
        (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_pm_pause_func() == OAL_TRUE)) {    // 业务不同意睡
        g_pm_wlan_info.wifi_srv_sleep_forbid++;
        *sleep_cont = DISALLOW_SLEEP_WIFI_SRV_FORBID;
        oam_info_log0(0, OAM_SF_DPA, "wlan srv pm pause!!!");
        return -OAL_FAIL;
    } else {
        g_pm_wlan_info.wifi_srv_sleep_forbid = 0;
    }

    if (g_pm_wlan_info.dpa_allow_sleep != DPA_ALLOW_TO_SLEEP) {
        *sleep_cont = DISALLOW_SLEEP_DPA_DISALLOW;
        oam_info_log0(0, OAM_SF_DPA, "dpa wlan disallow sleep");
        return -OAL_FAIL;
    }

    /* 检查ete tx 队列是不是空 */
    if (hcc_bus_sleep_request_host(hcc_get_master_handler()) != OAL_SUCC) {
        *sleep_cont = DISALLOW_SLEEP_ETE_NOT_EMPTY;
        oam_info_log0(0, OAM_SF_DPA, "dpa ete tx have date");
        g_pm_wlan_info.sleep_request_dpa_forbid++;
        return -OAL_FAIL;
    } else {
        g_pm_wlan_info.sleep_request_dpa_forbid = 0;
    }

    return OAL_SUCC;
}

static void pm_wlan_disallow_sleep_event_process(void)
{
    g_pm_wlan_info.sleep_stage = SLEEP_DISALLOW_RCV;
    g_pm_wlan_info.sleep_request_host_forbid++;
    g_pm_wlan_info.dpa_allow_sleep = DPA_DISALLOW_TO_SLEEP;
    oam_warning_log0(0, OAM_SF_DPA, "receive acpu DISALLOW_SLEEP_EVENT");
    pm_wlan_reset_sleep_timer();
}

static void pm_wlan_dpa_sleep_succ_event_process(void)
{
    int32_t ret;
    pm_msg_t pm_msg;

    g_pm_wlan_info.acpu_state = POWER_STATE_SHUTDOWN;    // 此时device可能已经进深睡了

    if (g_pm_wlan_info.sleep_stage != SLEEP_ETE_CLOSE) {
        oam_error_log1(0, OAM_SF_DPA, "sleep fail, sleep stage[%u]", g_pm_wlan_info.sleep_stage);
        return;
    }

    g_pm_wlan_info.sleep_stage = SLEEP_SUCC;
    g_pm_wlan_info.wakeup_stage = WAKEUP_STAGE_INIT;    // 睡眠完成把wakeup_stage置成init状态
    if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_pm_state_notify != NULL) {
        g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_pm_state_notify(OAL_FALSE);    // 睡眠成功，通知业务
    }

    pm_msg.msg_id = D2A_SLEEP_SUCC_ACK;
    ret = conn_dmi_msg_data_send(CONN_DMI_MSG_PM, (uint8_t *)&pm_msg, sizeof(pm_msg_t));
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dmi send msg[D2A_SLEEP_SUCC_ACK] fail! ret = %d", ret);
    }

    g_pm_wlan_info.sleep_succ++;
    g_pm_wlan_info.sleep_request_host_forbid = 0;
    pm_trace_node(TRACE_D2A_SLEEP_SUCC_ACK);
    oam_warning_log1(0, OAM_SF_DPA, "dpa sleep succ, suspend_cnt[%u]", g_pm_wlan_info.suspend_resume_cnt);
}

static int32_t pm_wlan_acpu_to_dpa_sleep_request_event(void)
{
    pm_msg_t pm_msg;
    int32_t ret;
    dpa_pm_disallow_sleep_cont_t sleep_cont = DISALLOW_SLEEP_NONE;
    g_pm_wlan_info.sleep_stage = SLEEP_REQ_RCV;
    if (pm_wlan_sleep_check(&sleep_cont) != OAL_SUCC) {
        g_pm_wlan_info.sleep_stage = SLEEP_DISALLOW_ACK;
        pm_wlan_reset_sleep_timer();
        pm_msg.msg_id = D2A_DISALLOW_SLEEP_ACK;
        pm_msg.msg_cont = sleep_cont;
        ret = conn_dmi_msg_data_send(CONN_DMI_MSG_PM, (uint8_t *)&pm_msg, sizeof(pm_msg_t));
        if (ret != OAL_SUCC) {
            pm_trace_node(TRACE_D2A_DISALLOW_SLEEP_ACK_SEND_FAIL);
            oam_error_log1(0, OAM_SF_DPA, "dmi send msg[D2A_DISALLOW_SLEEP_ACK] fail! ret = %d", ret);
            return ret;
        }

        pm_trace_node(TRACE_D2A_DISALLOW_SLEEP_ACK);
        return OAL_SUCC;
    }

    pm_wlan_event_send_to_pm_process_thread(SLEEP_REQ_EVENT);    // 触发睡眠唤醒状态机线程处理
    g_pm_wlan_info.sleep_sema.state = 1; // 初始化睡眠信号量状态

    pm_msg.msg_id = D2A_ALLOW_SLEEP_ACK;
    ret = conn_dmi_msg_data_send(CONN_DMI_MSG_PM, (uint8_t *)&pm_msg, sizeof(pm_msg_t));
    if (ret != OAL_SUCC) {
        pm_trace_node(TRACE_D2A_ALLOW_SLEEP_ACK_SEND_FAIL);
        g_pm_wlan_info.sleep_sema.state = 0; // 初始化睡眠信号量状态
        oam_error_log1(0, OAM_SF_DPA, "dmi send msg[D2A_ALLOW_SLEEP_ACK] fail! ret = %d", ret);
        return ret;
    }

    pm_trace_node(TRACE_D2A_ALLOW_SLEEP_ACK);
    if (pm_wlan_get_pm_sema(&g_pm_wlan_info.sleep_sema) != OAL_SUCC) {
        pm_trace_node(TRACE_GET_SLEEP_SEMA_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "sleep state get sleep sema fail, state %d", g_pm_wlan_info.sleep_sema.state);
    }

    if ((g_pm_wlan_info.sleep_stage != SLEEP_SUCC) && (g_pm_wlan_info.sleep_stage != SLEEP_DISALLOW_RCV)) {
        pm_trace_node(TRACE_SLEEP_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "sleep fail! state[%u]", g_pm_wlan_info.sleep_stage);
        pm_wlan_trigger_dfr();
    }

    pm_trace_node(TRACE_SLEEP_END);
    oal_wake_unlock(WIFI_WAKE_PM);    // 在master tx lock内释放锁

    return OAL_SUCC;
}

static int32_t pm_wlan_submit_dpa_sleep_event_process(void)
{
    if (g_pm_wlan_info.timeout_curr_cnt >= g_pm_wlan_info.timeout_cnt) {
        if ((g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_pm_pause_func != NULL) &&
            (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_pm_pause_func() == OAL_TRUE)) {
            oam_info_log0(0, OAM_SF_DPA, "wlan srv pm pause!!!");    // 业务不同意睡
            return -OAL_FAIL;
        }
        if (pm_wlan_event_send_to_pm_idle_thread(DPA_ALLOW_SLEEP_EVENT) != 0) {
            oam_error_log0(0, OAM_SF_DPA, "send DPA_ALLOW_SLEEP_EVENT failed!");
            return -OAL_FAIL;
        }
        oam_info_log0(0, OAM_SF_DPA, "send DPA_ALLOW_SLEEP_EVENT");
        g_pm_wlan_info.have_packet = 0;
        g_pm_wlan_info.sleep_event_submit++;
        g_pm_wlan_info.timeout_curr_cnt = 0;
        return OAL_SUCC;
    }

    return -OAL_FAIL;
}

static int32_t pm_wlan_submit_dpa_sleep_event(void)
{
    if (g_pm_wlan_info.packet_cnt == 0) {
        g_pm_wlan_info.timeout_curr_cnt++;
        return pm_wlan_submit_dpa_sleep_event_process();
    } else {
        oam_info_log2(0, OAM_SF_DPA, "timeout cnt %d have packet %d....",
                      g_pm_wlan_info.timeout_curr_cnt, g_pm_wlan_info.packet_cnt);
        g_pm_wlan_info.have_packet++;
        g_pm_wlan_info.timeout_curr_cnt = 0;
        g_pm_wlan_info.packet_cnt = 0;
    }

    return -OAL_FAIL;
}

static void pm_wlan_debug_info(void)
{
    if (g_pm_wlan_info.wifi_srv_sleep_forbid >= WLAN_SRV_FORBID_SLEEP_MAX_CNT) {   // 业务超过3s以上未睡眠打印维测
        oam_error_log1(0, OAM_SF_DPA, "dpa wlan srv forbit sleep count[%u]!", g_pm_wlan_info.wifi_srv_sleep_forbid);
        g_pm_wlan_info.wifi_srv_sleep_forbid = 0;

        oam_error_log1(0, OAM_SF_DPA, "hcc trx cnt in work[%u]!", g_pm_wlan_info.packet_total_cnt);
    }

    if (g_pm_wlan_info.timeout_cnt_for_debug >= WLAN_SRV_PRINT_DEBUG_TIMEOUT_MAX_CNT) {
        if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_data_pm_print_func != NULL) {
            g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_data_pm_print_func();
        }
        g_pm_wlan_info.timeout_cnt_for_debug = 0;
    } else {
        g_pm_wlan_info.timeout_cnt_for_debug++;
    }
}

static void pm_wlan_hcc_master_trx_cnt_info(void)
{
    uint32_t tx_cnt = 0;
    uint32_t rx_cnt = 0;
    uint32_t wifi_srv_trx = 0;
    /* 只关注hcc master tx的数据流量，忽略hcc master rx(日志数据) */
    hcc_master_get_trx_cnt(&tx_cnt, &rx_cnt);
    /* 定时器超时时间内的业务数据收发量 */
    if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_trx_cnt_func != NULL) {
        wifi_srv_trx = g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_get_trx_cnt_func();
    }

    if (g_pm_wlan_info.master_tx_cnt > tx_cnt) {
        oam_error_log4(0, OAM_SF_DPA, "trx cnt maybe reset, pm tx_cnt[%u], pm rx_cnt[%u], tx_cnt[%u], rx_cnt[%u]",
                       g_pm_wlan_info.master_tx_cnt, g_pm_wlan_info.master_rx_cnt, tx_cnt, rx_cnt);
        g_pm_wlan_info.packet_cnt = tx_cnt + wifi_srv_trx;
    }

    if (g_pm_wlan_info.master_tx_cnt < tx_cnt) {
        g_pm_wlan_info.packet_cnt = tx_cnt - g_pm_wlan_info.master_tx_cnt + wifi_srv_trx;
    }
    g_pm_wlan_info.packet_total_cnt += g_pm_wlan_info.packet_cnt;
    g_pm_wlan_info.master_tx_cnt = tx_cnt;
    g_pm_wlan_info.master_rx_cnt = rx_cnt;
}

static int32_t pm_wlan_sleep_timer_timeout_callback(int para)
{
    g_pm_wlan_info.timer_handle = -1;    // timer超时后会自动删除，手动删除后有bug
    if (g_pm_wlan_info.wlan_power_state == POWER_STATE_SHUTDOWN) {
        oam_info_log0(0, OAM_SF_DPA, "don't reset sleep timer, power state is SHUTDOWN");
        return OAL_SUCC;
    }

    if (g_pm_wlan_info.dpa_allow_sleep == DPA_ALLOW_TO_SLEEP) {
        oam_info_log0(0, OAM_SF_DPA, "dpa wlan allow deepsleep!");
        return OAL_SUCC;
    }

    pm_wlan_debug_info();
    oam_info_log1(0, OAM_SF_DPA, "timeout_curr_cnt[%d]", g_pm_wlan_info.timeout_curr_cnt);
    pm_wlan_hcc_master_trx_cnt_info();

    if (g_pm_wlan_info.wlan_pm_enable == OAL_TRUE) {
        if (pm_wlan_submit_dpa_sleep_event() == OAL_SUCC) {
            return OAL_SUCC;
        }
    } else {
        g_pm_wlan_info.packet_cnt = 0;
    }

    pm_wlan_reset_sleep_timer();

    return OAL_SUCC;
}

int32_t pm_wlan_reset_sleep_timer(void)
{
    int32_t ret;
    int8_t current_core = (uint8_t)osl_get_core_id(); // 当前所在核
    timer_attr_s timerattr = {
        .name = "slp_t",
        .time = DPA_SLEEP_TIMER_PERIOD,
        .flag = TIMER_FLAG_DEFAULT,
        .callback = pm_wlan_sleep_timer_timeout_callback,
        .para = 0,
    };

    if ((g_pm_wlan_info.wlan_power_state == POWER_STATE_SHUTDOWN) || (g_pm_wlan_info.wlan_pm_enable == OAL_FALSE)) {
        oam_warning_log0(0, OAM_SF_DPA, "not need reset timer");
        return OAL_SUCC;
    }

    if (g_pm_wlan_info.timer_handle >= 0) {
        ret = bsp_timer_delete(g_pm_wlan_info.timer_handle);
        if (ret != 0) {
            oam_error_log4(0, OAM_SF_DPA, "reset sleep_timer ret[%d], timer[%d], core[%d], create_core[%d]",
                           ret, g_pm_wlan_info.timer_handle, current_core, g_timer_last_core);
        }
    }

    g_pm_wlan_info.timer_handle = bsp_timer_add(&timerattr);
    if (g_pm_wlan_info.timer_handle < 0) {
        oam_error_log1(0, OAM_SF_DPA, "sleep timer add err %d", g_pm_wlan_info.timer_handle);
        return -OAL_FAIL;
    }

    g_timer_last_core = current_core; // 记录低功耗timer当前所在核
    return OAL_SUCC;
}

int32_t pm_wlan_close_sleep_timer(void)
{
    int32_t ret;
    int8_t current_core = (uint8_t)osl_get_core_id(); // 当前所在核
    if (g_pm_wlan_info.timer_handle >= 0) {
        ret = bsp_timer_delete(g_pm_wlan_info.timer_handle);
        if (ret != 0) {
            oam_error_log4(0, OAM_SF_DPA, "close sleep_timer err ret[%d], timer[%d], core[%d], create_core[%d]",
                           ret, g_pm_wlan_info.timer_handle, current_core, g_timer_last_core);
            g_pm_wlan_info.timer_handle = -1;
            return -OAL_FAIL;
        }
        oam_info_log0(0, OAM_SF_DPA, "sleep timer delete");
    }
    g_pm_wlan_info.timer_handle = -1;
    return OAL_SUCC;
}

/* 唤醒流程 */
static int32_t pm_wlan_wakeup_check(pm_wlan_str_t *pm_wlan)
{
    if (pm_wlan->wlan_power_state == POWER_STATE_SHUTDOWN) {
        oam_error_log0(0, OAM_SF_DPA, "pm_wlan is shutdown!");
        return -OAL_FAIL;
    }

    if (g_pm_wlan_info.dpa_exception_state == 1) {
        oam_error_log0(0, OAM_SF_DPA, "dpa is doing dfr, not allow wake");
        return -OAL_FAIL;
    }

    if (pm_wlan->wlan_pm_enable == OAL_FALSE) {
        if (pm_wlan->sleep_stage == SLEEP_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "wlan pm disabled but sleep state == SLEEP_SUCC!");
            return OAL_ERR_CODE_WAKEUP_PROCESSING;
        } else {
            oam_info_log0(0, OAM_SF_DPA, "wlan pm is disabled!");
            return OAL_SUCC;
        }
    }

    if (pm_wlan->dpa_allow_sleep == DPA_DISALLOW_TO_SLEEP) {
        oam_info_log0(0, OAM_SF_DPA, "dpa_allow_sleep == DPA_DISALLOW_TO_SLEEP!");
        return OAL_SUCC;
    }

    if (g_pm_wlan_info.acpu_state == POWER_STATE_OPEN) {
        oam_info_log0(0, OAM_SF_DPA, "wlan pm acpu_state == POWER_STATE_OPEN!");
        return OAL_SUCC;
    }

    return OAL_SUCC_GO_ON;
}

/* DPA主动唤醒A核加锁 */
int32_t pm_wlan_dpa_wakeup_acpu_handler_lock(void)
{
    int32_t ret;
    oal_wake_lock(WIFI_WAKE_PM);

    hcc_master_tx_transfer_lock();
    ret = pm_wlan_wakeup_dpa_handler(WAKEUP_SOURCE_DPA);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "wakeup fail!");
    }
    hcc_master_tx_transfer_unlock();
    return ret;
}

uint32_t wlan_pm_try_wakeup_dev_lock(void)
{
#define WLAN_PM_TRY_WAKEUP_DEV_MAX_CNT 2
    uint32_t try_cnt = 1;

    pm_trace_node(TRACE_WIFI_WAKEUP_START);
    while ((pm_wlan_dpa_wakeup_acpu_handler_lock() != OAL_SUCC) && (try_cnt < WLAN_PM_TRY_WAKEUP_DEV_MAX_CNT)) {
        ++try_cnt;
        continue;
    }

    if (oal_unlikely(try_cnt >= WLAN_PM_TRY_WAKEUP_DEV_MAX_CNT)) {
        pm_trace_node(TRACE_WIFI_WAKEUP_FAIL);
        oam_error_log0(0, OAM_SF_DPA, "{wlan_pm_try_wakeup_dev_lock::wakeup dev failed!}");
        return OAL_FAIL;
    }

    pm_trace_node(TRACE_WIFI_WAKEUP_SUCC);
    return OAL_SUCC;
}

/* 唤醒DPA */
int32_t pm_wlan_wakeup_dpa_handler(uint8_t wake_source)
{
    int32_t ret;
    pm_msg_t pm_msg;

    oal_wake_lock(WIFI_WAKE_PM);    // 在master tx lock内持锁

    ret = pm_wlan_wakeup_check(&g_pm_wlan_info);
    if (ret != OAL_SUCC_GO_ON) {
        return ret;
    }

    pm_wlan_event_send_to_pm_process_thread(WAKEUP_REQ_EVENT);    // 触发睡眠唤醒状态机线程处理
    g_pm_wlan_info.wakeup_sema.state = 1; // 初始化唤醒信号量状态

    if (wake_source == WAKEUP_SOURCE_DPA) {
        pm_msg.msg_id = D2A_WAKEUP_REQ_MSG;
        ret = conn_dmi_msg_data_send(CONN_DMI_MSG_PM, (uint8_t *)&pm_msg, sizeof(pm_msg_t));
        if (ret != OAL_SUCC) {
            pm_trace_node(TRACE_D2A_WAKEUP_REQ_SEND_FAIL);
            g_pm_wlan_info.wakeup_sema.state = 0;
            oam_error_log1(0, OAM_SF_DPA, "dmi send msg[D2A_WAKEUP_REQ_MSG] fail! ret = %d", ret);
            return ret;
        }

        g_pm_wlan_info.wakeup_source = WAKEUP_SOURCE_DPA;
        g_pm_wlan_info.wakeup_stage = WAKEUP_REQ_SND;
        pm_trace_node(TRACE_D2A_WAKEUP_REQ);
    } else {
        g_pm_wlan_info.wakeup_source = WAKEUP_SOURCE_ACPU;
        pm_trace_node(TRACE_WAKEUP_SOURCE_ACPU);
    }

    /* 等待唤醒完成释放信号量，超时表示后续事件未处理完或唤醒失败 初始化信号量的值是0 */
    if (pm_wlan_get_pm_sema(&g_pm_wlan_info.wakeup_sema) != OAL_SUCC) {
        pm_trace_node(TRACE_GET_WAKEUP_SEMA_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "STATE_WAKEUP get pm smea fail, state %d", g_pm_wlan_info.wakeup_sema.state);
    }

    /* 根据g_pm_wlan_info.wakeup_stage判断唤醒是否成功 */
    if (g_pm_wlan_info.wakeup_stage != WAKEUP_SUCC) {
        pm_trace_node(TRACE_WAKEUP_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "wakeup fail, wakeup_state[%u]", g_pm_wlan_info.wakeup_stage);
        pm_wlan_trigger_dfr();
        return -OAL_FAIL;
    }

    pm_trace_node(TRACE_WAKEUP_END);
    oam_warning_log0(0, OAM_SF_DPA, "get sema succ, wakeup succ");
    pm_wlan_reset_sleep_timer();
    return OAL_SUCC;
}

static void pm_wlan_dpa_wakeup_fail_event_process(void)
{
    // 唤醒失败的处理
    oam_error_log0(0, OAM_SF_DPA, "handler acpu WAKEUP_FAIL_EVENT");
    g_pm_wlan_info.wakeup_stage = WAKEUP_FAIL;
    g_pm_wlan_info.dpa_allow_sleep = DPA_ALLOW_TO_SLEEP;    // 唤醒失败默认DPA允许睡
    g_pm_wlan_info.wakeup_fail++;
}

static void pm_wlan_dpa_wakeup_succ_event_process(void)
{
    pm_msg_t pm_msg;
    int32_t ret;

    if (g_pm_wlan_info.wakeup_stage != WAKEUP_ETE_OPEN) {
        oam_error_log1(0, OAM_SF_DPA, "wakeup fail, wakeup stage[%u]", g_pm_wlan_info.wakeup_stage);
        return;
    }

    g_pm_wlan_info.wakeup_stage = WAKEUP_SUCC;
    g_pm_wlan_info.sleep_stage = SLEEP_STAGE_INIT;    // 唤醒完成把睡眠置成init状态
    g_pm_wlan_info.dpa_allow_sleep = DPA_DISALLOW_TO_SLEEP;
    g_pm_wlan_info.wakeup_succ++;
    if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_pm_state_notify != NULL) {
        g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_pm_state_notify(OAL_TRUE);    // 唤醒成功，通知业务
    }
    pm_msg.msg_id = D2A_WAKEUP_SUCC_ACK;
    ret = conn_dmi_msg_data_send(CONN_DMI_MSG_PM, (uint8_t *)&pm_msg, sizeof(pm_msg_t));
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dmi send msg[D2A_WAKEUP_SUCC_ACK] fail! ret = %d", ret);  // 发送失败继续往后走
    }
    g_pm_wlan_info.acpu_state = POWER_STATE_OPEN;
    g_pm_wlan_info.packet_total_cnt = 0;    // 唤醒成功重置work状态的收包统计
    g_pm_wlan_info.packet_cnt = 0;

    pm_trace_node(TRACE_D2A_WAKEUP_SUCC_ACK);
    oam_info_log0(0, OAM_SF_DPA, "wakeup dpa succ");
}

/* A核唤醒DPA */
static int32_t pm_wlan_acpu_to_dpa_wakeup_request_event(void)
{
    oal_wake_lock(WIFI_WAKE_PM);    // 在master tx lock内持锁
    g_pm_wlan_info.wakeup_stage = WAKEUP_REQ_RCV;
    g_pm_wlan_info.wakeup_event_submit++;

    return pm_wlan_wakeup_dpa_handler(WAKEUP_SOURCE_ACPU);
}

static void pm_wlan_dpa_exception_event_process(void)
{
    g_pm_wlan_info.dpa_exception_state = 1;
    dpa_exception_handler(g_pm_wlan_info.excep_id);
}

static pm_state_t pm_wlan_idle_state_handler(uint32_t event)
{
    if ((event & (BIT(SLEEP_REQ_EVENT) | BIT(WAKEUP_REQ_EVENT) |
        BIT(DPA_EXCEPTION_EVENT) | BIT(DPA_WLAN_CLOSE_EVENT))) == 0) {
        oam_error_log1(0, OAM_SF_DPA, "STATE_IDLE handler fail!!! EVENT[%u]", event);
        return STATE_IDLE;
    }

    if ((event & BIT(WAKEUP_REQ_EVENT)) == BIT(WAKEUP_REQ_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_IDLE --> STATE_WAKEUP");
        return STATE_WAKEUP;
    }

    if ((event & BIT(SLEEP_REQ_EVENT)) == BIT(SLEEP_REQ_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_IDLE --> STATE_SLEEP");
        return STATE_SLEEP;
    }

    if ((event & BIT(DPA_EXCEPTION_EVENT)) == BIT(DPA_EXCEPTION_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_IDLE handler DPA_EXCEPTION_EVENT");
        pm_wlan_dpa_exception_event_process();
        return STATE_IDLE;
    }

    if ((event & BIT(DPA_WLAN_CLOSE_EVENT)) == BIT(DPA_WLAN_CLOSE_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_IDLE handler DPA_WLAN_CLOSE_EVENT");
        return STATE_IDLE;
    }

    return STATE_IDLE;
}

static pm_state_t pm_wlan_sleep_state_handler(uint32_t event)
{
    if ((event & (BIT(DISALLOW_SLEEP_EVENT) | BIT(SLEEP_SUCC_EVENT) | BIT(DPA_WLAN_CLOSE_EVENT) |
        BIT(DPA_EXCEPTION_EVENT))) == 0) {
        oam_error_log1(0, OAM_SF_DPA, "STATE_SLEEP handler fail!!! EVENT[%u]", event);
        return STATE_SLEEP;
    }

    if ((event & BIT(DISALLOW_SLEEP_EVENT)) == BIT(DISALLOW_SLEEP_EVENT)) {
        pm_wlan_disallow_sleep_event_process();
    }

    if ((event & BIT(SLEEP_SUCC_EVENT)) == BIT(SLEEP_SUCC_EVENT)) {
        pm_wlan_dpa_sleep_succ_event_process();
    }

    if ((event & BIT(DPA_EXCEPTION_EVENT)) == BIT(DPA_EXCEPTION_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_SLEEP handler DPA_EXCEPTION_EVENT");
        pm_wlan_dpa_exception_event_process();
    }

    if ((event & BIT(DPA_WLAN_CLOSE_EVENT)) == BIT(DPA_WLAN_CLOSE_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_SLEEP handler DPA_WLAN_CLOSE_EVENT");
    }

    /* 不管睡眠成功与否都释放信号量 */
    if (pm_wlan_release_pm_sema(&g_pm_wlan_info.sleep_sema) != OAL_SUCC) {
        pm_trace_node(TRACE_RELEASE_SLEEP_SEMA_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "STATE_SLEEP release sema fail, state %d", g_pm_wlan_info.sleep_sema.state);
        return STATE_IDLE;
    }

    oam_info_log0(0, OAM_SF_DPA, "STATE_SLEEP dpa release sema");

    return STATE_IDLE;
}

static pm_state_t pm_wlan_wakeup_state_handler(uint32_t event)
{
    if ((event & (BIT(WAKEUP_FAIL_EVENT) | BIT(WAKEUP_SUCC_EVENT) | BIT(DPA_WLAN_CLOSE_EVENT) |
        BIT(DPA_EXCEPTION_EVENT))) == 0) {
        oam_error_log1(0, OAM_SF_DPA, "STATE_WAKEUP handler fail!!! EVENT[%u]", event);
        return STATE_WAKEUP;
    }

    if ((event & BIT(WAKEUP_FAIL_EVENT)) == BIT(WAKEUP_FAIL_EVENT)) {
        pm_wlan_dpa_wakeup_fail_event_process();
    }

    if ((event & BIT(WAKEUP_SUCC_EVENT)) == BIT(WAKEUP_SUCC_EVENT)) {
        pm_wlan_dpa_wakeup_succ_event_process();
    }

    if ((event & BIT(DPA_EXCEPTION_EVENT)) == BIT(DPA_EXCEPTION_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_WAKEUP handler DPA_EXCEPTION_EVENT");
        pm_wlan_dpa_exception_event_process();
    }

    if ((event & BIT(DPA_WLAN_CLOSE_EVENT)) == BIT(DPA_WLAN_CLOSE_EVENT)) {
        oam_warning_log0(0, OAM_SF_DPA, "STATE_WAKEUP handler DPA_WLAN_CLOSE_EVENT");
    }

    /* 不管唤醒成功与否都释放信号量 */
    if (pm_wlan_release_pm_sema(&g_pm_wlan_info.wakeup_sema) != OAL_SUCC) {
        pm_trace_node(TRACE_RELEASE_WAKEUP_SEMA_FAIL);
        oam_error_log1(0, OAM_SF_DPA, "STATE_WAKEUP release sema fail, state", g_pm_wlan_info.wakeup_sema.state);
        return STATE_IDLE;
    }

    oam_info_log0(0, OAM_SF_DPA, "STATE_WAKEUP dpa release sema");

    return STATE_IDLE;
}

static int32_t pm_wlan_handler_thread_process(void *param)
{
    uint32_t recv_event;
    pm_state_t current_state = STATE_IDLE;
    oam_warning_log0(0, OAM_SF_DPA, "pm_wlan_handler_thread_process enter ");
    while (pm_wlan_handler_thread_should_stop() == 0) {
        recv_event = 0;
        /* IDLE-->SLEEP-->IDLE  IDLE-->WORK-->IDLE */
        mdrv_kevent_recv((BIT(SLEEP_REQ_EVENT) | BIT(DISALLOW_SLEEP_EVENT) | BIT(SLEEP_SUCC_EVENT) |
            BIT(WAKEUP_REQ_EVENT) | BIT(WAKEUP_FAIL_EVENT) | BIT(WAKEUP_SUCC_EVENT) | BIT(DPA_EXCEPTION_EVENT) |
            BIT(DPA_WLAN_CLOSE_EVENT)), PM_WLAN_EVENT_MODE, OS_EVENT_WAIT_FOREVER, &recv_event);
        switch (current_state) {
            case STATE_IDLE:
                current_state = pm_wlan_idle_state_handler(recv_event);
                break;
            case STATE_SLEEP:
                current_state = pm_wlan_sleep_state_handler(recv_event);
                break;
            case STATE_WAKEUP:
                current_state = pm_wlan_wakeup_state_handler(recv_event);
                break;
            default:
                oam_error_log0(0, OAM_SF_DPA, "No way are going to get here");
                break;
        }
    }

    return OAL_SUCC;
}

static int32_t pm_wlan_handler_thread_create(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t ret;
    g_pm_wlan_info.pm_handler_thread.stack_addr = mdrv_mem_alloc(PM_WLAN_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (g_pm_wlan_info.pm_handler_thread.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "pm_wlan stack mem alloc fail");
        return -OAL_FAIL;
    }

    task_attr.type = THRD_TASK;
    task_attr.prio = OS_TSK_PRIORITY_01;
    task_attr.stackSize = PM_WLAN_THREAD_SIZE;
    task_attr.stackAddr = (uintptr_t)g_pm_wlan_info.pm_handler_thread.stack_addr;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.entryFunc = pm_wlan_handler_thread_process,
    ret = osl_task_create("pm_wlan", &task_attr, 1, &g_pm_wlan_info.pm_handler_thread.task_id);
    if (ret) {
        mdrv_free(g_pm_wlan_info.pm_handler_thread.stack_addr);
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create pm_wlan fail, ret[%u]", ret);
        return -OAL_FAIL;
    }
    g_pm_wlan_info.pm_handler_thread.event_type = 0xFFFFFFFF;
    return OAL_SUCC;
}

static int32_t pm_wlan_idle_thread_process(void *param)
{
    uint32_t recv_event;
    oam_info_log0(0, OAM_SF_DPA, "pm_wlan_idle_thread_process enter ");
    while (pm_wlan_idle_thread_should_stop() == 0) {
        recv_event = 0;
        mdrv_kevent_recv((BIT(WAKEUP_REQ_EVENT) | BIT(DPA_ALLOW_SLEEP_EVENT) | BIT(SLEEP_REQ_EVENT)),
                         PM_WLAN_EVENT_MODE, OS_EVENT_WAIT_FOREVER, &recv_event);
        if ((recv_event & BIT(WAKEUP_REQ_EVENT)) == BIT(WAKEUP_REQ_EVENT)) {
            hcc_master_tx_transfer_lock();
            pm_wlan_acpu_to_dpa_wakeup_request_event();
            hcc_master_tx_transfer_unlock();
        }

        if ((recv_event & BIT(DPA_ALLOW_SLEEP_EVENT)) == BIT(DPA_ALLOW_SLEEP_EVENT)) {
            hcc_master_tx_transfer_lock();
            pm_wlan_dpa_to_acpu_allow_sleep_event();
            hcc_master_tx_transfer_unlock();
        }

        if ((recv_event & BIT(SLEEP_REQ_EVENT)) == BIT(SLEEP_REQ_EVENT)) {
            hcc_master_tx_transfer_lock();
            pm_wlan_acpu_to_dpa_sleep_request_event();
            hcc_master_tx_transfer_unlock();
        }
    }
    return OAL_SUCC;
}

static int32_t pm_wlan_idle_thread_create(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t ret;
    g_pm_wlan_info.pm_idle_thread.stack_addr = mdrv_mem_alloc(PM_WLAN_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (g_pm_wlan_info.pm_idle_thread.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "pm_idle_thread stack mem alloc fail");
        return -OAL_FAIL;
    }

    task_attr.type = THRD_TASK;
    task_attr.prio = OS_TSK_PRIORITY_02;    // 优先级低于pm_handler_thread线程
    task_attr.stackSize = PM_WLAN_THREAD_SIZE;
    task_attr.stackAddr = (uintptr_t)g_pm_wlan_info.pm_idle_thread.stack_addr;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.entryFunc = pm_wlan_idle_thread_process,
    ret = osl_task_create("pm_idle_thread", &task_attr, 1, &g_pm_wlan_info.pm_idle_thread.task_id);
    if (ret) {
        mdrv_free(g_pm_wlan_info.pm_idle_thread.stack_addr);
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create pm_idle_thread fail, ret[%u]", ret);
        return -OAL_FAIL;
    }
    g_pm_wlan_info.pm_idle_thread.event_type = 0xFFFFFFFF;
    return OAL_SUCC;
}

int32_t pm_wlan_suspend(void)
{
    if (g_pm_wlan_info.wlan_power_state == POWER_STATE_SHUTDOWN) {
        oam_info_log0(0, OAM_SF_DPA, "wlan_power_state POWER_STATE_SHUTDOWN");
        return 0;
    }

    g_pm_wlan_info.suspend_resume_cnt++;
    wlan_pm_wkup_src_debug_set(OAL_TRUE);
    oam_warning_log3(0, OAM_SF_DPA, "suspend dpa_allow_sleep[%u], sleep_stage[%u], wakeup_stage[%u]",
        g_pm_wlan_info.dpa_allow_sleep, g_pm_wlan_info.sleep_stage, g_pm_wlan_info.wakeup_stage);
    oam_info_log1(0, OAM_SF_DPA, "suspend_resume_cnt[%u]", g_pm_wlan_info.suspend_resume_cnt);
    return 0;
}

int32_t pm_wlan_resume(void)
{
    return 0;
}

struct wifi_srv_callback_handler *wlan_pm_get_wifi_srv_handler(void)
{
    return &g_pm_wlan_info.wifi_srv_handler;
}

static int32_t pm_wlan_dpa_pm_msg_proc(uint8_t *buf, uint16_t buf_len)
{
    int32_t i;
    if ((buf_len != 1) || (buf[0] >= A2D_RX_MSG_BUTT)) {
        oam_error_log1(0, OAM_SF_DPA, "pm_wlan_dpa_pm_msg_proc is err, buff_len[%u]", buf_len);
        for (i = 0; i < buf_len; i++) {
            oam_error_log2(0, OAM_SF_DPA, "buff[%d]=%u", i, buf[i]);
        }
        return -OAL_FAIL;
    }

    return g_pm_wlan_rx_msg_handler[buf[0]](buf[0]);
}

static int32_t pm_wlan_a2d_set_timeout(uint8_t *buf, uint16_t buf_len)
{
    uint32_t timeout_cnt;
    if (buf_len != sizeof(uint32_t)) {
        return -OAL_FAIL;
    }

    timeout_cnt = *(uint32_t *)buf;
    oam_warning_log1(0, OAM_SF_DPA, "pm_wlan_a2d_set_timeout[%d]", timeout_cnt);
    wlan_pm_set_timeout(timeout_cnt);
    return OAL_SUCC;
}

static void pm_wlan_debug_info_clean(void)
{
    g_pm_wlan_info.open_cnt = 0;
    g_pm_wlan_info.close_cnt = 0;
    g_pm_wlan_info.wakeup_succ = 0;
    g_pm_wlan_info.wakeup_fail = 0;
    g_pm_wlan_info.wakeup_event_submit = 0;
    g_pm_wlan_info.dpa_allow_sleep_cnt = 0;
    g_pm_wlan_info.sleep_succ = 0;
    g_pm_wlan_info.sleep_request_dpa_forbid = 0;
    g_pm_wlan_info.sleep_request_host_forbid = 0;
    g_pm_wlan_info.sleep_event_submit = 0;
}

int32_t pm_wlan_init(void)
{
    int32_t ret;
    g_pm_wlan_info.wlan_power_state = POWER_STATE_OPEN;
    g_pm_wlan_info.dpa_allow_sleep = DPA_DISALLOW_TO_SLEEP;
    g_pm_wlan_info.sleep_stage = SLEEP_STAGE_INIT;
    g_pm_wlan_info.wakeup_stage = WAKEUP_STAGE_INIT;
    g_pm_wlan_info.dpa_exception_state = 0;
    g_pm_wlan_info.wakeup_source = 0;
    g_pm_wlan_info.wakeup_err_count = 0;
    g_pm_wlan_info.fail_sleep_count = 0;
    g_pm_wlan_info.acpu_state = POWER_STATE_OPEN;
    g_pm_wlan_info.timer_handle = -1;         // 定时器未启用时定时器句柄置成-1，使用时从使用接口返回值
    g_pm_wlan_info.dpm_operation.dpm_suspend = pm_wlan_suspend;
    g_pm_wlan_info.dpm_operation.dpm_resume  = pm_wlan_resume;
    g_pm_wlan_info.have_packet = 0;
    g_pm_wlan_info.packet_cnt = 0;
    g_pm_wlan_info.packet_total_cnt = 0;
    g_pm_wlan_info.timeout_cnt = DPA_SLEEP_DEFAULT_CHECK_CNT;
    g_pm_wlan_info.timeout_curr_cnt = 0;
    g_pm_wlan_info.timeout_cnt_for_debug = 0;
    g_pm_wlan_info.wkup_src_print_en = OAL_FALSE;
    g_pm_wlan_info.suspend_resume_cnt = 0;

    g_pm_wlan_info.open_cnt++;
    g_pm_wlan_info.wakeup_sema.state = 0;
    ret = mdrv_bsem_init(OS_SEM_EMPTY, SEM_MODE_PRIOR, &g_pm_wlan_info.wakeup_sema.sema_id);
    if (ret != 0) {
        oam_error_log1(0, OAM_SF_DPA, "dpa init wakeup_sema fail! ret = %d", ret);
        return -OAL_FAIL;
    }
    g_pm_wlan_info.sleep_sema.state = 0;
    ret = mdrv_bsem_init(OS_SEM_EMPTY, SEM_MODE_PRIOR, &g_pm_wlan_info.sleep_sema.sema_id);
    if (ret != 0) {
        oam_error_log1(0, OAM_SF_DPA, "dpa init sleep_sema fail! ret = %d", ret);
        mdrv_sem_delete(g_pm_wlan_info.wakeup_sema.sema_id);
        return -OAL_FAIL;
    }

    if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_open_notify != NULL) {
        g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_open_notify(POWER_STATE_OPEN);
    }
    pm_wlan_reset_sleep_timer();

    oam_warning_log0(0, OAM_SF_DPA, "pm_wlan_init succ");
    return OAL_SUCC;
}

int32_t pm_wlan_deinit(void)
{
    if (g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_open_notify != NULL) {
        g_pm_wlan_info.wifi_srv_handler.p_wifi_srv_open_notify(POWER_STATE_SHUTDOWN);
    }
    g_pm_wlan_info.wlan_pm_enable = OAL_FALSE;
    g_pm_wlan_info.wlan_power_state = POWER_STATE_SHUTDOWN;
    g_pm_wlan_info.dpa_allow_sleep = DPA_DISALLOW_TO_SLEEP;
    g_pm_wlan_info.acpu_state = POWER_STATE_SHUTDOWN;
    g_pm_wlan_info.dpm_operation.dpm_suspend = NULL;
    g_pm_wlan_info.dpm_operation.dpm_resume  = NULL;
    g_pm_wlan_info.timer_handle = -1;
    g_pm_wlan_info.wkup_src_print_en = OAL_FALSE;

    g_pm_wlan_info.close_cnt++;

    pm_wlan_event_send_to_pm_process_thread(DPA_WLAN_CLOSE_EVENT);

    mdrv_sem_delete(g_pm_wlan_info.sleep_sema.sema_id);
    mdrv_sem_delete(g_pm_wlan_info.wakeup_sema.sema_id);
    oam_warning_log0(0, OAM_SF_DPA, "pm_wlan_deinit succ");
    return OAL_SUCC;
}

/* 记录pm_trace 所在核和当前32k tick数 */
void pm_trace_node(uint8_t type)
{
    unsigned long irq_sts;
    uint8_t current_core;
    if (type >= TRACE_BUTT) {
        oam_error_log1(0, OAM_SF_DPA, "pm_trace_node type[%d] invalid", type);
        return;
    }

    current_core = (uint8_t)osl_get_core_id(); // 当前所在核
    oal_spin_lock_irq_save(&g_pm_trace_spinlock, &irq_sts);
    /* 若连续相同trace且在同CPU上, 仅累加记录最后一次时间 */
    if ((type == g_last_node) && (current_core == g_last_core)) {
        g_pm_trace_flg[g_pm_trace_idx].repeat_cnt++;
        g_pm_trace_flg[g_pm_trace_idx].slice = bsp_get_slice_value(); // 32k计数
        oal_spin_unlock_irq_restore(&g_pm_trace_spinlock, &irq_sts);
        return;
    } else {
        g_pm_trace_idx++;
        if (g_pm_trace_idx >= PM_MAX_TRACE) {
            g_pm_trace_idx = 0;
        }
        g_pm_trace_flg[g_pm_trace_idx].type = type;
        g_pm_trace_flg[g_pm_trace_idx].core = current_core; // 当前所在核
        g_pm_trace_flg[g_pm_trace_idx].repeat_cnt = 1;
        g_pm_trace_flg[g_pm_trace_idx].slice = bsp_get_slice_value(); // 32k计数
        g_last_node = type;
        g_last_core = current_core;
    }
    oal_spin_unlock_irq_restore(&g_pm_trace_spinlock, &irq_sts);
}

/* 打印缓存中的pm_trace, 仅在异常时调用 */
void pm_trace_node_debug_print(void)
{
    int32_t i;
    oam_warning_log1(0, OAM_SF_DPA, "pm_trace_type curr idx:%d", g_pm_trace_idx);
    for (i = 0; i < PM_MAX_TRACE; i++) {
        oam_warning_log4(0, OAM_SF_DPA, "[%d]pm_trace_type[%d] slice[0x%x] repeat_cnt_core[0x%x]",
                         i, g_pm_trace_flg[i].type, g_pm_trace_flg[i].slice,
                         ((g_pm_trace_flg[i].repeat_cnt << NUM_16_BITS) | g_pm_trace_flg[i].core));
    }
}

void pm_trace_init(void)
{
    g_pm_trace_idx = 0;
    memset_s((void *)g_pm_trace_flg, sizeof(g_pm_trace_flg), 0, sizeof(g_pm_trace_flg));
    oal_spin_lock_init(&g_pm_trace_spinlock);
}

void pm_trace_deinit(void)
{
    g_pm_trace_idx = 0;
    memset_s((void *)g_pm_trace_flg, sizeof(g_pm_trace_flg), 0, sizeof(g_pm_trace_flg));
    oal_spin_lock_exit(&g_pm_trace_spinlock);
}

/*
 * 函 数 名  : pm_wlan_module_init
 * 功能描述  : 低功耗模块初始化
 * 输入参数  : NULL
 */
int32_t pm_wlan_module_init(void)
{
    int32_t ret;
    oam_info_log0(0, OAM_SF_DPA, "pm_wlan_module_init start");
    pm_wlan_debug_info_clean();
    ret = bsp_dpm_register(DPA_WLAN, &g_pm_wlan_info.dpm_operation);
    if (ret != 0) {
        oam_error_log1(0, OAM_SF_DPA, "wlan add dpm fail, ret = %d.", ret);
        return ret;
    }

    ret = pm_wlan_handler_thread_create();
    if (ret < 0) {
        oam_error_log0(0, OAM_SF_DPA, "pm wlan thread create fail");
        return ret;
    }

    ret = pm_wlan_idle_thread_create();
    if (ret < 0) {
        oam_error_log0(0, OAM_SF_DPA, "pm_wlan_idle_thread_create fail");
        return ret;
    }

    /* 使能去使能低功耗需要持锁，fiber线程无法持锁，所以放在消息处理下半部 */
    conn_dmi_msg_regiser(CONN_DMI_MSG_PM, NULL, pm_wlan_dpa_pm_msg_proc);
    /* 同步a核sleep timer超时次数配置 */
    conn_dmi_msg_regiser(CONN_DMI_MSG_SET_PM_TIMEOUT, pm_wlan_a2d_set_timeout, NULL);
    dpa_exception_register(&g_pm_wlan_info.excep_id,
        g_pm_wlan_info.pm_handler_thread.task_id, BIT(DPA_EXCEPTION_EVENT));
    pm_trace_init();
    oam_warning_log0(0, OAM_SF_DPA, "pm_wlan_module_init succ");
    return OAL_SUCC;
}

/*
 * 函 数 名  : pm_wlan_module_deinit
 * 功能描述  : 低功耗模块去初始化
 * 输入参数  : NULL
 */
int32_t pm_wlan_module_deinit(void)
{
    uint32_t ret;
    pm_trace_deinit();
    conn_dmi_msg_regiser(CONN_DMI_MSG_PM, NULL, NULL);
    ret = mdrv_task_delete(g_pm_wlan_info.pm_handler_thread.task_id);
    if (ret != 0) {
        oam_error_log1(0, OAM_SF_DPA, "mdrv_task_delete g_pm_wlan_info.pm_handler_thread fail, ret = %u", ret);
    }
    mdrv_free(g_pm_wlan_info.pm_handler_thread.stack_addr);

    ret = mdrv_task_delete(g_pm_wlan_info.pm_idle_thread.task_id);
    if (ret != 0) {
        oam_error_log1(0, OAM_SF_DPA, "mdrv_task_delete g_pm_wlan_info.pm_idle_thread fail, ret = %u", ret);
    }
    mdrv_free(g_pm_wlan_info.pm_idle_thread.stack_addr);
    oam_warning_log0(0, OAM_SF_DPA, "pm_wlan_module_deinit succ");
    return OAL_SUCC;
}
