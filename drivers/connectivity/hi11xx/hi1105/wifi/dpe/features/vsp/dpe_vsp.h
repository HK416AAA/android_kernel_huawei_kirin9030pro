/*
 * Copyright (c) @CompanyNameMagicTag 2021-2024. All rights reserved.
 * 功能说明 : dpe_vsp.h 的头文件
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年06月28日
 */

#ifndef DPE_VSP_H
#define DPE_VSP_H

#include "hmac_tx_msdu_dscr.h"
#include "dpe_wlan_user.h"
#include "dpe_wlan_vap.h"

enum dpe_vsp_type {
    DPE_VSP_TYPE_VIDEO = 0,
    DPE_VSP_TYPE_SX = 1,
    DPE_VSP_TYPE_BUTT,
};

typedef struct {
    hmac_tid_info_stru *tid_info[DPE_VSP_TYPE_BUTT]; // 0:视频-tid4 1:键鼠-tid5
    dpe_wlan_user_stru *user;
    dpe_wlan_vap_stru *vap;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_spin_lock_stru vsp_lock;
#else
    oal_mutex_stru vsp_lock;
#endif
    hal_host_device_stru *host_hal_device;
    hal_mac_common_timer timer;
} dpe_vsp_info_stru;

dpe_vsp_info_stru *dpe_get_vsp_info(void);
uint32_t dpe_vsp_init(uint16_t user_id, uint16_t vap_id, uint8_t device_id);
void dpe_vsp_stop_timer(void);
void dpe_vsp_stop_timer_no_pm_wakeup(void);
void dpe_vsp_start_timer(uint32_t start_time, uint32_t timeout_us);
uint32_t dpe_vsp_get_timestamp(void);
void dpe_vsp_deinit_common_timer(void);

void dpe_vsp_init_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_stop_timer_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_stop_timer_no_pm_wakeu_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_start_timer_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_get_timestamp_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_deinit_common_timer_proc(hmac_dpe_wifi_msg_stru *msg);

#endif
