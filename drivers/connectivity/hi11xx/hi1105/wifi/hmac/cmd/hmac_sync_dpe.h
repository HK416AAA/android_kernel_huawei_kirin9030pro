/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac同步dpa接口头文件
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年4月21日
 */
#ifndef HMAC_SYNC_DPE_H
#define HMAC_SYNC_DPE_H

#include "hmac_vap.h"
#ifdef _PRE_WLAN_FEATURE_ML
#include "hd_event_mld_vap.h"
#endif
#include "dpe_tx_data.h"
#include "hd_trx_data.h"
#include "dpe_netdev.h"

#ifndef MSEC_PER_SEC
#define MSEC_PER_SEC            1000L
#endif

uint32_t hmac_sync_dpa_event(hmac_dpe_wifi_msg_stru *msg);
uint32_t hmac_sync_dpa_event_wait_response(hmac_dpe_wifi_msg_stru *msg, hmac_dpe_wifi_msg_stru *resp);
void hmac_sync_dpa_event_cb(uint8_t *buf, uint8_t buf_len);
void hmac_dfr_wifi_recover_msg(void);
void hmac_dfr_wifi_excp_msg(void);
uint32_t hmac_config_always_tx_proc(mac_vap_stru *mac_vap, uint8_t dev_id, uint16_t len, uint8_t *param);
uint32_t hmac_always_tx_netbuf_enqueue(uint8_t hal_dev_id, oal_netbuf_stru *netbuf);
void hmac_init_notify_dpe(void);
void hmac_chip_feature_init(void);
void hmac_wlan_device_al_trx_flag_sync(uint8_t in_al_trx);
void hmac_cfg_vap_net_dev_info_sync(uint8_t cfg_vap_idx);
#ifdef _PRE_WLAN_FEATURE_ML
void hmac_mld_params_update_config_event(mac_vap_stru *mac_vap, hmac_mld_manage_stru *mld_vap_manage,
    h2d_mld_vap_param_stru *h2d_mld_vap_param);
void hmac_mld_assoc_mode_sync_event(uint8_t vap_id, uint8_t mld_assoc_mode);
void hmac_vap_mld_mode_sync(uint8_t vap_idx, uint8_t mld_mode);
void hmac_change_tid_ba_info_sync_dpe(uint8_t vap_idx, uint16_t cur_work_user_idx, uint16_t next_work_user_idx);
void hmac_change_netdev_vap_relation_sync(uint8_t cur_vap_idx, uint8_t next_vap_idx,
    oal_net_device_stru *cur_net_dev, oal_net_device_stru *next_net_dev);
void hmac_config_h2d_user_change_to_mld_mode_sync_dpe(uint8_t *event_param);
#endif
void hmac_user_mac_addr_sync(uint16_t user_idx, uint8_t *addr);
void hmac_user_assoc_state_sync(uint16_t user_idx, mac_user_asoc_state_enum_uint8 user_asoc_state);
void hmac_user_port_sync(uint16_t user_idx, oal_bool_enum_uint8 en_port_valid);
void hmac_vap_assoc_id_sync(uint8_t vap_id, uint16_t assoc_vap_id);
void hmac_vap_state_sync(uint16_t vap_idx, uint8_t *param);
void hmac_add_vap_sync(uint8_t *param, uint8_t *param_extend, mac_vap_stru *mac_vap);
void hmac_rx_ba_init_sync(hmac_ba_rx_para_stru *ba_rx, uint8_t vap_id, uint16_t assoc_id, uint8_t tid);
void hmac_trx_switch_sync(wlan_trx_switch_stru *trx_switch);
void hmac_clear_ptk_rx_pn_sync(hmac_user_stru *hmac_user);
void hmac_clear_gtk_rx_pn_sync(hmac_user_stru *hmac_user);
void hmac_del_cfg_vap_sync(uint8_t vap_idx);
uint32_t hmac_tx_mode_switch_sync(uint8_t vap_idx, uint32_t *params);
void hmac_sync_dpe_pps_tx_switch(uint32_t pps);
#ifdef _PRE_WLAN_FEATURE_TX_STAT
uint32_t hmac_tx_stats_set_log_on_sync(uint8_t vap_idx, uint32_t *params);
#endif
#ifdef _PRE_WLAN_FEATURE_EMLSR
void hmac_vap_emlsr_state_sync_dpe(uint8_t vap_idx, uint8_t emlsr_state);
#endif
#ifdef _PRE_WLAN_CHBA_MGMT
void hmac_dbac_vap_set_rx_reorder_timeout_sync(uint8_t vap_idx, uint8_t is_dbac_running);
void hmac_sync_dpe_chba_start_flag(hmac_vap_stru *hmac_vap, uint8_t is_chba_start);
#endif
void hmac_config_del_vap_sync_dpe(uint8_t vap_idx, uint8_t *param, oal_net_device_stru *net_dev);
void hmac_user_info_sync_dpe(uint8_t *param);
void hmac_config_down_vap_sync_dpe(uint8_t vap_idx, mac_cfg_down_vap_param_stru *down_vap_param);
void hmac_config_start_vap_sync_dpe(uint16_t us_idx, mac_cfg_start_vap_param_stru *start_vap_param);
void hmac_user_del_sync_dpe(frw_event_mem_stru *event_mem);
void hmac_user_add_sync_dpe(frw_event_mem_stru *event_mem);
int32_t hmac_netdev_sync_dpa(oal_net_device_stru *net_device, sync_wlan_priv_info_stru *netdev_priv_info);
void hmac_netdev_sync_dpa_del_p2p_cl_vap(hmac_vap_stru *hmac_vap);
void hmac_wifi_state_sync_dpe(wifi_state_enum wifi_state);
void mac_sync_dpe_user_key_info(mac_user_stru *mac_user);
void hmac_tid_clear_sync(hmac_user_stru *hmac_user, uint8_t sync_to_dpa);
void hmac_netdev_update_mac_addr(oal_net_device_stru *netdev,
    uint8_t *mac_addr, uint8_t is_sync_dpa, uint8_t array_len);
void hmac_send_wifi_init_dmi_msg(void);
void hmac_sync_dpe_update_trx_stat_info(void);
void mac_add_vap_sync_dpe_user_key_info(hmac_vap_stru *hmac_vap);
void hmac_sync_dpe_dump_event_pps_info(uint32_t dur_ms);
#endif