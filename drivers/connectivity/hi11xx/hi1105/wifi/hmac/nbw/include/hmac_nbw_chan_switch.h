/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw frame encap and trx
 * Author: wifi
 * Create: 2024-12-26
 */
#ifndef HMAC_NBW_CHAN_SWITCH_H
#define HMAC_NBW_CHAN_SWITCH_H

#include "hmac_device.h"
#include "hmac_vap.h"
#include "hmac_user.h"
#include "hmac_vap.h"
#include "hmac_nbw_common.h"
#include "mac_nbw_common.h"
#include "mac_frame_common.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_CHAN_SWITCH_H
#ifdef _PRE_WLAN_FEATURE_NBW
#ifdef _PRE_WLAN_NBW_DEMO
/* 信道切换请求的最大连续发送次数 */
#define NBW_MAX_COUNT_SWITCH_REQ_CNT 2
/* 信道切换最小时间间隔，单位ms */
#define NBW_CHAN_SWITCH_MIN_INTERVAL 5000

/* 信道/模式切换信息结构体 */
typedef struct {
    uint8_t notify_type;                    /* 信道切换通知类型，req还是rsp */
    mac_channel_stru channel_info;          /* 目标信道信息 */
    uint8_t pwr_level;                      /* 目标信道功率模式 */
    uint8_t req_timeout_cnt;                /* req重传次数 */
    uint32_t last_send_req_time;            /* 上次发送req时间，防止pingpang使用 */
    frw_timeout_stru req_timer;             /* NBW 模式切换req帧定时器 */
} hmac_nbw_mode_switch_notify_stru;
uint32_t hmac_nbw_send_mode_switch_notify_action(uint8_t *peer_addr, hmac_nbw_mode_switch_notify_stru *mode_switch_ntf);
void hmac_nbw_rx_chan_switch_notify_action(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint8_t sa_len, uint8_t *payload,
    uint16_t payload_len);
uint32_t hmac_mode_switch_result_notify(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param);
hmac_nbw_mode_switch_notify_stru *hmac_get_nbw_mode_switch_info(void);
uint32_t hmac_nbw_start_mode_switch(uint8_t *peer_addr);
#endif
#endif
#endif