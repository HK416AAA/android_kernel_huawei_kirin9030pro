/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw island domain device mgmt
 * Author: wifi
 * Create: 2024-12-26
 */
#ifndef HMAC_NBW_MGMT_H
#define HMAC_NBW_MGMT_H

#include "hmac_chba_common_function.h"
#include "hmac_chba_mgmt.h"
#include "hmac_nbw_timeslot_mgmt.h"
#include "hmac_nbw_common.h"
#include "hihash.h"
#include "hilist.h"
#include "hmac_vap.h"
#include "frw_ext_if.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_MGMT_H

#ifdef _PRE_WLAN_FEATURE_NBW
#define MAC_NBW_MAX_DEVICE_NUM 32
#define MAC_NBW_MAX_BITMAP_WORD_NUM 4

#define SLOT_NUM 12
#define NBW_INVALID_IDX 0xff
#define NBW_ISLAND_MIN_DEVICE_NUM 2

#define NBW_TOPO_NO_CHANGED_INDICATE 0
#define NBW_TOPO_CHANGED_INDICATE 1

/* 用户统计信息上报时刻位置枚举 */
typedef enum {
    MAC_NBW_MASTER_ROLE = 1, /* 后续的值，与chba角色取值保持一致 */
    MAC_NBW_SLAVEAP_ROLE = 2,
    MAC_NBW_SLAVE_ROLE = 3,
    MAC_NBW_OTHER_DEVICE = 4,
    MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE = 5,
    MAC_NBW_ROLE_BUTT,
} hmac_nbw_role_enum;

/* 建链阶段状态枚举 */
typedef enum {
    MAC_NBW_CONNECT_ASSOC = 1, /* 建链关联过程中，包括时隙申请、同步、关联、加密 */
    MAC_NBW_CONNECT_NEGOTIATE = 2, /* 建链协商 */
} hmac_nbw_curr_conn_status_enum;

typedef enum {
    MAC_NBW_SINGLE_ISLAND = 0, /* 单岛 */
    MAC_NBW_GROUP_ISLAND = 1,  /* 群岛 */
    MAC_NBW_ISLAND_TYPE_BUTT,
} hmac_nbw_island_type_enum;

typedef struct {
    uint8_t timeslot_level;
    uint32_t vap_bitmap;
} hmac_nbw_vap_stru;

extern hmac_nbw_vap_stru g_nbw_vap_info;

/* 岛域信息更新结构体 */
typedef struct {
    uint8_t island_flag;    /* 单岛0，群岛1 */
    nbw_ranking_priority slaveap_rp;     /* SlaveAp的ranking priority */
    hmac_nbw_slot_info_stru slot_info;
} hmac_nbw_island_conn_info_rpt;


static inline hmac_nbw_mgmt_info_stru *hmac_nbw_get_mgmt_info(void)
{
    return &g_nbw_mgmt_info;
}

static inline void hmac_nbw_set_topo_change_flag(uint8_t flag)
{
    g_nbw_mgmt_info.topo_change_flag = flag;
}

static inline uint8_t hmac_nbw_get_topo_change_flag(void)
{
    return g_nbw_mgmt_info.topo_change_flag;
}

static inline uint8_t hmac_nbw_get_role(void)
{
    return g_nbw_mgmt_info.self_conn_info.role;
}

static inline void hmac_nbw_set_role(uint8_t val)
{
    g_nbw_mgmt_info.self_conn_info.role = val;
}

static inline uint8_t *hmac_nbw_get_master_macaddr(void)
{
    return g_nbw_mgmt_info.master_addr;
}

static inline hmac_nbw_current_connect_info_stru *hmac_nbw_get_curr_conn_info(void)
{
    return &g_nbw_mgmt_info.curr_conn_info;
}

static inline hmac_nbw_slot_info_stru *hmac_nbw_get_slave_slot_info(void)
{
    return &g_nbw_mgmt_info.slave_info.device_slot_info[0];
}

static inline void hmac_nbw_slave_link_cnt_add(void)
{
    g_nbw_mgmt_info.slave_info.link_cnt++;
}

static inline void hmac_nbw_slave_link_cnt_dec(void)
{
    g_nbw_mgmt_info.slave_info.link_cnt--;
}

static inline uint8_t hmac_nbw_get_slave_link_cnt(void)
{
    return g_nbw_mgmt_info.slave_info.link_cnt;
}

static inline hmac_nbw_vap_stru *hmac_nbw_get_nbw_vap(void)
{
    return &g_nbw_vap_info;
}

static inline uint8_t hmac_nbw_get_island_uslot_bitmap(hmac_nbw_slot_info_stru *slot_info)
{
    uint8_t idx;
    uint8_t uslot_bitmap = 0;
    for (idx = 0; idx < MAX_ISLAND_SLOT_INFO_NUM; idx++) {
        if (slot_info[idx].use_flag == OAL_FALSE) {
            continue;
        }
        uslot_bitmap |= slot_info[idx].uslot_info.uslot_bitmap;
    }
    return uslot_bitmap;
}

void hmac_nbw_reset_topo_change_flag_timer(hmac_vap_stru *hmac_vap);
uint32_t hmac_nbw_change_flag_timeout(void *arg);
uint32_t hmac_nbw_beacon_sync_timeout(void *arg);
uint32_t hmac_nbw_pnf_sync_timeout(void *arg);
uint8_t hmac_nbw_slaveap_exist_in_domain(uint8_t work_mode, uint8_t *slaveap_addr, uint8_t addr_len);
void hmac_nbw_get_self_island_info(uint8_t work_mode, hmac_chba_per_island_info_stru *self_island);
uint8_t hmac_nbw_find_unused_link_idx(hmac_nbw_slot_info_stru *slot_info);
uint8_t hmac_nbw_find_slot_link_idx(hmac_nbw_slot_info_stru *slot_info, uint8_t *peer_addr);
uint8_t hmac_nbw_count_device_num(uint32_t device_bitmap);
uint8_t hmac_nbw_check_island_type(uint8_t work_mode, hmac_nbw_slot_info_stru *slot_info);
uint32_t hmac_nbw_get_island_slave_info(uint8_t work_mode, uint8_t slaveap_id);
uint8_t hmac_nbw_island_slave_bitmap(hmac_chba_per_island_info_stru *island_info);
void hmac_nbw_update_self_role(hmac_vap_stru *hmac_vap);
void hmac_nbw_clear_island_info(uint8_t work_mode, uint8_t slaveap_id, uint8_t slave_id);
void hmac_nbw_update_group_island_flag(uint8_t work_mode, hmac_chba_per_island_info_stru *curr_island,
    uint32_t slaveap_bitmap);
void hmac_nbw_update_single_island_flag(uint8_t work_mode, uint32_t slaveap_bitmap);
void hmac_nbw_update_island_slot_info(hmac_nbw_slot_info_stru *island_slot_info, uint8_t link_idx,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t *peer_mac_addr);
void hmac_nbw_clear_conn_info(hmac_vap_stru *hmac_vap, uint8_t *slave_addr, uint8_t *peer_addr);
uint32_t hmac_nbw_master_adjust_timeslot(uint8_t work_mode, uint8_t *peer_addr, uint8_t peer_len,
    uint8_t *slave_addr, uint8_t slave_len, hmac_nbw_uslot_info_stru uslot_bitmap_info);
#ifdef _PRE_WLAN_NBW_DEMO
void hmac_nbw_sync_user_bitmap_info(mac_vap_stru *mac_vap,
    hmac_user_stru *hmac_user, uint32_t user_bitmap);
void hmac_nbw_sync_user_bitmap(hmac_vap_stru *hmac_vap,
    hmac_user_stru *hmac_user, uint32_t user_bitmap);
void hmac_nbw_sync_vap_bitmap_info(mac_vap_stru *mac_vap);
uint32_t hmac_nbw_set_pwr_switch(mac_vap_stru *mac_vap, uint16_t len, uint8_t *params);
uint32_t hmac_nbw_set_mode_switch(mac_vap_stru *mac_vap, uint16_t len, uint8_t *params);
#else
void hmac_nbw_sync_user_bitmap_info(mac_vap_stru *mac_vap,
    hmac_user_stru *hmac_user, nbw_timeslot_bitmap_cfg_stru user_bitmap_info);
void hmac_nbw_sync_user_bitmap(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    nbw_timeslot_bitmap_cfg_stru user_bitmap_info);
void hmac_nbw_sync_vap_bitmap_info(mac_vap_stru *mac_vap, nbw_timeslot_bitmap_cfg_stru bitmap_info);
#endif
void hmac_nbw_sync_timeslot_info(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t work_uslot_flag, uint8_t work_slot_flag);
void hmac_nbw_sync_timeslot_info_with_conn(hmac_vap_stru *hmac_vap, hmac_nbw_slot_info_stru slot_info,
    uint8_t work_uslot_flag, uint8_t work_slot_flag);
void hmac_nbw_update_island_info(uint8_t work_mode, hmac_nbw_island_conn_info_rpt island_conn_info,
    uint8_t slaveap_id, uint8_t slave_id);
void hmac_nbw_init_device_info(hmac_chba_device_para_stru *device_info);
void hmac_nbw_release_timeslot(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t peer_len,
    uint8_t *other_addr, uint8_t other_len);
void hmac_nbw_update_conn_info(hmac_vap_stru *hmac_vap, hmac_nbw_island_conn_info_rpt island_conn_info,
    uint8_t *slave_addr, uint8_t *slaveap_addr, uint8_t addr_len);
void hmac_nbw_island_list_node_release(struct hi_node *node);
void hmac_nbw_del_non_alive_device(mac_vap_stru *mac_vap, chba_device_id_stru *device_rpt);
void hmac_nbw_start_beacon_sync_timer(hmac_vap_stru *hmac_vap);
void hmac_nbw_start_pnf_sync_timer(hmac_vap_stru *hmac_vap);
uint8_t hmac_nbw_del_one_device_island_info(hmac_vap_stru *hmac_vap, uint8_t device_id);
void hmac_nbw_del_device_by_mac_addr(mac_vap_stru *mac_vap, uint8_t *mac_addr, uint8_t addr_len);
void hmac_nbw_clear_device_info(uint8_t work_mode, uint8_t slaveap_id, uint8_t slave_id);
uint8_t hmac_nbw_get_dev_alive_dev_table(uint8_t work_mode, const uint8_t* mac_addr);
void hmac_nbw_handle_timeslot_borrow(hmac_vap_stru *hmac_vap);
uint32_t hmac_nbw_timeslot_borrow_wait_timeout(void *arg);
#endif
#endif
