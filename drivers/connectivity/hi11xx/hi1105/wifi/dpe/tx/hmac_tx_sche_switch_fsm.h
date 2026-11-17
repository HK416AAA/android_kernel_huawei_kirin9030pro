/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : tx调度模式切换状态机
 * 作    者 : wifi
 * 创建日期 : 2021年3月31日
 */

#ifndef HMAC_TX_SCHE_SWITCH_FSM_H
#define HMAC_TX_SCHE_SWITCH_FSM_H

#include "oal_ext_if.h"

typedef enum {
    TX_SCHE_SWITCH_FSM,
    TX_MODE_SWITCH_FSM,
    PPS_SWITCH_TYPE_BUTT,
} hmac_pps_switch_fsm_enum;

void hmac_tx_sche_switch_process(uint32_t tx_throughput);
#endif
