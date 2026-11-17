/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : tx调度模式切换状态机
 * 作    者 : wifi
 * 创建日期 : 2021年3月31日
 */

#include "hmac_tx_sche_switch_fsm.h"
#include "hmac_pps_fsm.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_tx_data.h"
#include "hmac_config.h"
#endif
#include "dpe_wlan_config.h"
#include "dpe_tx_data.h"
#include "mac_common.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_TX_SCHE_SWITCH_FSM_C

typedef enum {
    TX_SCHE_H2D_SWITCH, /* 高流量事件, 尝试将Host调度切换至Device调度 */
    TX_SCHE_D2H_SWITCH, /* 低流量事件, 尝试将Device调度切换至Device调度 */

    TX_SCHE_SWITCH_EVENT_BUTT,
} hmac_tx_sche_switch_event_enum;

typedef enum {
    TX_SCHE_HOST_TRIGGER_MODE,   /* Host下发事件调度模式 */
    TX_SCHE_DEVICE_LOOP_MODE,    /* Device Main Loop调度模式 */
    TX_SCHE_H2D_SWITCHING_MODE,

    TX_SCHE_MODE_BUTT,
} hmac_tx_sche_switch_fsm_state_enum;

static uint32_t hmac_tx_sche_switch_send_event(uint8_t mode)
{
    uint32_t ret;
    tx_sche_switch_stru param = { .device_loop_sche_enabled = mode == TX_SCHE_DEVICE_LOOP_MODE };
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    ret = hmac_config_send_event((mac_vap_stru *)mac_res_get_mac_vap(0), WLAN_CFGID_TX_SCHE_SWITCH,
        sizeof(tx_sche_switch_stru), (uint8_t *)&param);
#else
    ret = dpe_config_sync_device_send_event(dpe_wlan_vap_get(0), WLAN_CFGID_TX_SCHE_SWITCH,
        (uint8_t *)&param, sizeof(tx_sche_switch_stru));
#endif
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_tx_sche_switch_send_event::switch to mode[%d] failed}", mode);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

static uint32_t hmac_tx_sche_d2h_switch(void)
{
    return hmac_tx_sche_switch_send_event(TX_SCHE_HOST_TRIGGER_MODE);
}

static uint32_t hmac_tx_sche_h2d_switch(void)
{
    return hmac_tx_sche_switch_send_event(TX_SCHE_DEVICE_LOOP_MODE);
}

dpe_pps_fsm_atomic_var g_pps_fsm_atomic_res[PPS_SWITCH_TYPE_BUTT];

#define HMAC_TX_SCHE_SWITCH_FSM_TABLE_SIZE 4
hmac_pps_fsm_stru g_tx_sche_switch_fsm = {
    .fsm_table = {
        /* device main loop调度模式吞吐量低, 立刻将调度方式切换至host trigger, 避免影响低功耗唤醒 */
        { TX_SCHE_DEVICE_LOOP_MODE, TX_SCHE_HOST_TRIGGER_MODE, TX_SCHE_D2H_SWITCH, hmac_tx_sche_d2h_switch },
        /* host trigger模式下吞吐量高, 继续等待一个统计周期 */
        { TX_SCHE_HOST_TRIGGER_MODE, TX_SCHE_H2D_SWITCHING_MODE, TX_SCHE_H2D_SWITCH, NULL },
        /* 第二个统计周期内吞吐量低, 取消切换 */
        { TX_SCHE_H2D_SWITCHING_MODE, TX_SCHE_HOST_TRIGGER_MODE, TX_SCHE_D2H_SWITCH, NULL },
        /* 第二个统计周期内吞吐量高, 将调度方式切换至device main loop, 以降低高吞吐下的host侧MIPS */
        { TX_SCHE_H2D_SWITCHING_MODE, TX_SCHE_DEVICE_LOOP_MODE, TX_SCHE_H2D_SWITCH, hmac_tx_sche_h2d_switch },
    },
    .entry_num = HMAC_TX_SCHE_SWITCH_FSM_TABLE_SIZE,
    .id = 1,
};

#define HMAC_TX_SCHE_SWITCH_LOW_THROUGHPUT 200
#define HMAC_TX_SCHE_SWITCH_HIGH_THROUGHPUT 300
static uint8_t hmac_tx_sche_switch_throughput_to_event(uint32_t tx_throughput)
{
    if (tx_throughput < HMAC_TX_SCHE_SWITCH_LOW_THROUGHPUT) {
        return TX_SCHE_D2H_SWITCH;
    } else if (tx_throughput > HMAC_TX_SCHE_SWITCH_HIGH_THROUGHPUT) {
        return TX_SCHE_H2D_SWITCH;
    } else {
        return TX_SCHE_SWITCH_EVENT_BUTT;
    }
}

void hmac_tx_sche_switch_process(uint32_t tx_throughput)
{
    if (!dpe_device_loop_sched_enabled() || !oal_atomic_read(&g_pps_fsm_atomic_res[TX_SCHE_SWITCH_FSM].enable)) {
        return;
    }

    hmac_pps_fsm_handle_event(hmac_tx_sche_switch_throughput_to_event(tx_throughput),
        &g_tx_sche_switch_fsm, TX_SCHE_SWITCH_FSM);
}
