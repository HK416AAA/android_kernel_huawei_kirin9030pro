/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac同步dpa接口头文件
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年4月21日
 */
#ifndef HMAC_INVOKE_DPE_H
#define HMAC_INVOKE_DPE_H

#include "hmac_vap.h"
#ifdef _PRE_WLAN_FEATURE_ML
#include "hd_event_mld_vap.h"
#endif
#include "dpe_tx_data.h"
#include "hd_trx_data.h"
#include "dpe_wlan_stat.h"

uint8_t hmac_is_trx_busy(void);
oal_bool_enum_uint8 hmac_is_ring_tx(mac_vap_stru *mac_vap, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl);
void hmac_wifi_on(void);
void hmac_wifi_off(void);
void hmac_forbid_access_bus(void);
void hmac_device_init_info_sync(uint16_t device_id, uint16_t cfg_vap_id, uint8_t chip_id);
void hmac_altx_res_init(void);
dpe_wlan_device_stat_stru *hmac_wlan_device_stat_get(void);
dpe_wlan_vap_stat_stru *hmac_wlan_vap_stat_get(uint8_t vap_id);
dpe_wlan_user_stat_stru *hmac_wlan_user_stat_get(uint16_t user_idx);
oal_net_device_stru *hmac_vap_get_net_device(uint8_t vap_id);
void wal_dfr_dpa_init_notify(void);
oal_bool_enum_uint8 wal_dfr_is_dpa_reset(void);
#endif