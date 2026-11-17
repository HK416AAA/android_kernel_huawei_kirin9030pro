/*
 * Copyright (c) @CompanyNameMagicTag 2025-2025. All rights reserved.
 * Description: nbw timeslot mgmt and schedule
 * Author: wifi
 * Create: 2025-05-20
 */
#ifndef HMAC_NBW_SYNC_H
#define HMAC_NBW_SYNC_H

#include "hmac_chba_sync.h"
#include "hmac_chba_mgmt.h"
#include "mac_chba_common.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_SYNC_H
#ifdef _PRE_WLAN_FEATURE_NBW
#define NBW_INTERFACE_TRIGGER_DOMAIN_MERGE_THRESHOLD -70
/* 域合并请求的最大连续发送次数 */
#define NBW_MAX_COUNT_DOMAIN_MERGE_REQ_CNT 3

/* 全局变量声明 */
extern hmac_chba_sync_info g_nbw_sync_info;

static inline hmac_chba_sync_info *hmac_nbw_get_sync_info(void)
{
    return &g_nbw_sync_info;
}

static inline hmac_nbw_domain_merge_info *hmac_nbw_get_domain_merge_info(void)
{
    return &g_nbw_sync_info.nbw_domain_merge_info;
}
static inline uint8_t *hmac_nbw_sync_get_domain_bssid(void)
{
    return g_nbw_sync_info.domain_bssid;
}
static inline uint8_t *hmac_nbw_get_master_mac_addr(void)
{
    return g_nbw_sync_info.cur_master_info.master_addr;
}
static inline nbw_ranking_priority *hmac_nbw_sync_get_rp_info(void)
{
    return &g_nbw_sync_info.nbw_rp_info;
}
static inline void hmac_nbw_sync_set_rp_id(uint8_t val)
{
    g_nbw_sync_info.nbw_rp_info.ranking_id = val;
}
static inline uint8_t hmac_nbw_sync_get_rp_ranking_id(void)
{
    return g_nbw_sync_info.nbw_rp_info.ranking_id;
}
static inline void hmac_nbw_sync_set_rp_dev_type(uint8_t val)
{
    g_nbw_sync_info.nbw_rp_info.device_level.dl.device_type = val;
}
static inline void hmac_nbw_sync_set_rp_capability(uint8_t val)
{
    g_nbw_sync_info.nbw_rp_info.device_level.dl.hardware_capability = val;
}
static inline void hmac_nbw_sync_set_rp_power(uint8_t val)
{
    g_nbw_sync_info.nbw_rp_info.device_level.dl.remain_power = val;
}
static inline void hmac_nbw_sync_set_rp_version(uint8_t val)
{
    g_nbw_sync_info.nbw_rp_info.chba_version = val;
}

static inline void hmac_nbw_set_all_awake_flag(uint8_t new_flag)
{
    g_nbw_sync_info.nbw_domain_merge_info.domain_merge_flag = new_flag;
}
static inline uint8_t hmac_nbw_get_all_awake_flag(void)
{
    return g_nbw_sync_info.nbw_domain_merge_info.domain_merge_flag;
}

static inline void hmac_nbw_set_domain_merge_flag(uint8_t new_flag)
{
    g_nbw_sync_info.nbw_domain_merge_info.domain_merge_flag = new_flag;
}

static inline uint8_t hmac_nbw_get_domain_merge_flag(void)
{
    return g_nbw_sync_info.nbw_domain_merge_info.domain_merge_flag;
}

static inline uint8_t *hmac_nbw_get_domain_merge_master_bssid(void)
{
    return g_nbw_sync_info.nbw_domain_merge_info.master_info.master_addr;
}

static inline hmac_nbw_timeslot_borrow_info_stru *hmac_nbw_get_timeslot_borrow_info(void)
{
    return &g_nbw_sync_info.timeslot_borrow_info;
}

void hmac_sync_nbw_domain_merge_flag(mac_vap_stru *mac_vap);
void hmac_nbw_sync_self_info(hmac_vap_stru *hmac_vap);
void hmac_nbw_sync_self_role(hmac_vap_stru *hmac_vap);
void hmac_nbw_domain_merge_recover_process(hmac_vap_stru *hmac_vap);
uint32_t hmac_nbw_waiting_domain_merge_timeslot_req_timeout(void *arg);
void hmac_nbw_interfere_trigger_handler(hmac_vap_stru *hmac_vap);
uint32_t hmac_nbw_interface_trigger_chan_meas_process(hmac_vap_stru *hmac_vap);
void hmac_nbw_domain_merge_succ_process(hmac_vap_stru *hmac_vap,
    hmac_chba_per_island_info_stru *self_island);
#endif
#endif