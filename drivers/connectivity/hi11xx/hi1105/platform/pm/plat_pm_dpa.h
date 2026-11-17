/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:plat_pm_dpa.c header file
 * Author: platform drivers
 */

#ifndef PLAT_DPA_PM_H
#define PLAT_DPA_PM_H

#ifdef _PRE_PLAT_FEATURE_DPA

#include "plat_pm_wlan.h"

#define W2D_WAKUP_MSG_WAIT_TIMEOUT    500
#define W2D_SLEEP_MSG_WAIT_TIMEOUT    500

typedef enum {
    A2D_SLEEP_REQ_MSG = 0,         // A核发送睡眠请求
    A2D_DISALOOW_SLEEP_MSG = 1,    // A核发送不允许睡消息
    A2D_SLEEP_SUCC_MSG = 2,        // A核发送睡眠完成消息
    A2D_WAKEUP_REQ_MSG = 3,        // A核发送唤醒请求消息
    A2D_WAKEUP_REQ_ACK = 4,        // A核回应唤醒请求ACK
    A2D_WAKEUP_FAIL_MSG = 5,       // A核发送唤醒失败消息
    A2D_WAKEUP_SUCC_MSG = 6,       // A核发送唤醒完成消息
    A2D_DISABLE_PM_MSG = 7,        // A核通知关闭低功耗
    A2D_ENABLE_PM_MSG = 8,         // A核通知打开低功耗
    A2D_TX_MSG_BUTT
} dpa_pm_tx_msg_t;

typedef enum {
    D2A_ALLOW_SLEEP_MSG = 0,    // dpa告诉A核可以睡消息
    D2A_ALLOW_SLEEP_ACK = 1,    // DPA允许睡ACK
    D2A_DISALLOW_SLEEP_ACK = 2,    // dpa不允许睡ACK
    D2A_SLEEP_SUCC_ACK = 3,    // DPA回复睡眠完成ACK
    D2A_WAKEUP_REQ_MSG = 4,    // DPA 唤醒请求
    D2A_WAKEUP_REQ_ACK = 5,    // DPA回复A核唤醒请求ACK
    D2A_WAKEUP_SUCC_ACK = 6,    // dpa 回复唤醒完成ACK
    D2A_RX_MSG_BUTT
} dpa_pm_rx_msg_t;

typedef enum {
    DISALLOW_SLEEP_NONE = 0,             // 初始
    DISALLOW_SLEEP_POWER_SHUTDOWN = 1,   // wifi已下电
    DISALLOW_SLEEP_PM_NOT_ENABLE = 2,    // 低功耗未使能
    DISALLOW_SLEEP_WIFI_SRV_FORBID = 3,  // 业务不允许睡
    DISALLOW_SLEEP_DPA_DISALLOW = 4,     // DPA不允许睡
    DISALLOW_SLEEP_ETE_NOT_EMPTY = 5,    // ETE队列不为空
    DISALLOW_SLEEP_BUTT
} dpa_pm_disallow_sleep_cont_t;

/* pm_msg_t 结构体与dpa上要保持一致, 两边需同时修改 */
typedef struct pm_msg_t {
    uint8_t msg_id;
    uint8_t msg_cont;
} pm_msg_t;

typedef int32_t (*dpa_pm_rx_msg_handler)(pm_msg_t *pm_msg);

void wlan_pm_send_wakeup_fail_to_dpa(void);
void wlan_pm_set_dpa_timeout(uint32_t timeout);
void wlan_pm_send_disallow_sleep_to_dpa(struct wlan_pm_s *pst_wlan_pm);
int32_t wlan_pm_wakeup_check_dpa(struct wlan_pm_s *pst_wlan_pm);
int32_t wlan_pm_wakeup_request_to_dpa(struct wlan_pm_s *pst_wlan_pm);
int32_t wlan_pm_wakeup_succ_to_dpa(struct wlan_pm_s *pst_wlan_pm);
int32_t wlan_pm_sleep_check_dpa(struct wlan_pm_s *pst_wlan_pm);
int32_t wlan_pm_sleep_request_to_dpa(struct wlan_pm_s *pst_wlan_pm);
int32_t wlan_pm_sleep_succ_to_dpa(struct wlan_pm_s *pst_wlan_pm);
int32_t wlan_pm_enable_dpa_pm(void);
int32_t wlan_pm_disable_dpa_pm(void);
void dpa_pm_para_init(void);
int32_t dpa_pm_init(struct wlan_pm_s *pst_wlan_pm);
int32_t dpa_pm_deinit(struct wlan_pm_s *pst_wlan_pm);

#endif    // _PRE_PLAT_FEATURE_DPA
#endif    // PLAT_DPA_PM_H