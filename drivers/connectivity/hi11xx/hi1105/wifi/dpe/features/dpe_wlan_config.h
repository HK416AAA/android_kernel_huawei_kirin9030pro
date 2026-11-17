/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_config.c 的头文件
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年03月28日
 */

#ifndef DPE_WLAN_CONFIG_H
#define DPE_WLAN_CONFIG_H

#include "dpe_wlan_debug.h"
#include "dpe_wlan_vap.h"
#include "dpe_wlan_tid.h"
#include "hd_trx_data.h"

typedef struct {
    uint8_t event_type;
    uint8_t event_subtype;
} dpe_config_event_type_stru;

/* HMAC到DPE配置同步操作 */
typedef struct {
    wlan_cfgid_enum_uint16 en_cfgid;
    uint8_t auc_resv[2];  /*  2 对齐 */
    uint32_t (*p_set_func)(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
} dpe_config_syn_stru;

uint32_t dpe_event_config_syn(uint8_t *hmac2dmac_msg_data, uint8_t vap_id,
    dpe_config_event_type_stru *event_type_info);

/* config事件适配层函数 */
uint32_t dpe_config_start_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_config_del_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_config_down_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_config_user_info_sync(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#ifdef _PRE_WLAN_FEATURE_ML
uint32_t dpe_config_set_mld_vap_param(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_config_h2d_user_change_to_mld_mode(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#endif
uint32_t dpe_config_set_always_rx(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_config_set_always_tx(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);

/* 声明config事件业务层函数 */
void dpe_wlan_user_info_sync(uint8_t *param);
#ifdef _PRE_WLAN_FEATURE_ML
void dpe_wlan_config_h2d_user_change_to_mld_mode(uint8_t *event_mem);
#endif
void dpe_wlan_device_al_trx_flag_sync(uint8_t in_al_trx);

/* hmac同步dpa事件适配层函数 */
uint32_t dpe_sync_elmsr_state(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#ifdef _PRE_WLAN_FEATURE_ML
uint32_t dpe_sync_mld_assoc_mode(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_emlsr_tx_ring_bitmap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_vap_mld_mode(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_change_tid_ba_info(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#endif
uint32_t dpe_sync_user_mac_addr(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_user_assoc_state(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_user_port(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_assoc_vap_id(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_vap_state(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_config_add_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_rx_ba_init(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_trx_switch(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_unicast_pkt_reset(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#ifdef _PRE_WLAN_FEATURE_RX_PN_CHECK
uint32_t dpe_sync_clear_ptk_rx_pn(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_clear_gtk_rx_pn(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#endif
uint32_t dpe_sync_del_cfg_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
uint32_t dpe_sync_tx_mode_switch(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#ifdef _PRE_WLAN_FEATURE_TX_STAT
uint32_t dpe_sync_tx_stats_set_log_on(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param);
#endif

/* 声明hmac同步dpa事件业务层函数 */
void dpe_wlan_vap_emlsr_state_sync(uint8_t vap_idx, uint8_t emlsr_state);
#ifdef _PRE_WLAN_FEATURE_ML
void dpe_wlan_vap_mld_assoc_mode_set(uint8_t vap_idx, uint8_t mld_assoc_mode);
void dpe_wlan_vap_mld_mode_set(uint8_t vap_idx, uint8_t mld_mode);
void dpe_change_tid_ba_info(uint16_t cur_work_user_idx, uint16_t next_work_user_idx);
#endif
void dpe_wlan_user_addr_sync(uint16_t user_idx, uint8_t *addr);
void dpe_wlan_user_assoc_state_sync(uint16_t user_idx, mac_user_asoc_state_enum_uint8 user_asoc_state);
void dpe_user_set_port_sync(uint16_t user_idx, oal_bool_enum_uint8 en_port_valid);
void dpe_trx_switch_sync(wlan_trx_switch_stru *trx_switch);
void dpe_hmac_user_clear_ptk_rx_pn(uint16_t user_idx);
void dpe_hmac_user_clear_gtk_rx_pn(uint16_t user_idx);
uint32_t dpe_wlan_tx_mode_switch(uint32_t *params);
#ifdef _PRE_WLAN_FEATURE_TX_STAT
uint32_t dpe_wlan_tx_stats_set_log_on(uint32_t *params);
#endif
uint32_t dpe_config_get_dbdc_info(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param);
uint32_t dpe_config_d2h_hal_vap_syn(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param);
uint32_t dpe_config_d2h_usr_lut_syn(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param);
uint32_t dpe_config_d2h_rx_mode_syn(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param);
uint32_t dpe_config_sync_device_send_event(dpe_wlan_vap_stru *dpe_vap, wlan_cfgid_enum_uint16 cfg_id,
    uint8_t *param, uint16_t param_len);
uint32_t dpe_always_tx_host_ring_check(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param);
uint32_t dpe_config_update_user_key_info(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param);
uint32_t dpe_config_change_netdev_vap_relation(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *param);
uint32_t dpe_sync_clear_tid_queue(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *param);
#endif
