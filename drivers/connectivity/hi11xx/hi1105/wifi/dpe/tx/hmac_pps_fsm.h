/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : pps驱动特性状态机
 * 作    者 : wifi
 * 创建日期 : 2021年3月31日
 */

#ifndef HMAC_PPS_FSM_H
#define HMAC_PPS_FSM_H

#include "oal_ext_if.h"
#include "hmac_tx_sche_switch_fsm.h"

typedef uint32_t (*hmac_pps_fsm_state_trans_action)(void);

typedef struct {
    uint8_t current_state;                  /* 状态机当前状态 */
    uint8_t next_state;                     /* 状态机下一状态 */
    uint8_t event;                          /* 触发状态转换的事件类型 */
    hmac_pps_fsm_state_trans_action action; /* 状态转换时执行的操作 */
} hmac_pps_fsm_state_trans_stru;

#define HMAC_PPS_FSM_MAX_SIZE 8

typedef struct {
    oal_atomic  current_state;
    oal_atomic  enable;
} dpe_pps_fsm_atomic_var;

typedef struct {
    hmac_pps_fsm_state_trans_stru fsm_table[HMAC_PPS_FSM_MAX_SIZE];
    uint16_t entry_num;
    uint16_t id;
    uint32_t host_keep_cnt;
} hmac_pps_fsm_stru;

extern dpe_pps_fsm_atomic_var g_pps_fsm_atomic_res[PPS_SWITCH_TYPE_BUTT];
void hmac_pps_fsm_handle_event(uint8_t event, hmac_pps_fsm_stru *fsm, uint8_t fsm_type);
#endif
