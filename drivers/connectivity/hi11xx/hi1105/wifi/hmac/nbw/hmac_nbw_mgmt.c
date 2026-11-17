/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw island domain device mgmt
 * Author: wifi
 * Create: 2024-12-26
 */
#include "mac_nbw_common.h"
#include "hmac_config.h"
#include "hmac_chba_common_function.h"
#include "hmac_chba_function.h"
#include "hmac_nbw_frame.h"
#include "hmac_nbw_master_election.h"
#include "hmac_nbw_chan_switch.h"
#include "hmac_nbw_mgmt.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_MGMT_C

#ifdef _PRE_WLAN_FEATURE_NBW
/* NBW管理信息 */
hmac_nbw_mgmt_info_stru g_nbw_mgmt_info = {
    .nbw_module_state = MAC_CHBA_MODULE_STATE_UNINIT,
    .owner_info.alive_device_table = NULL,
};

hmac_nbw_vap_stru g_nbw_vap_info = {
    .timeslot_level = MAC_NBW_USLOT_NUM,
};

void hmac_nbw_init_device_info(hmac_chba_device_para_stru *device_info)
{
    if ((g_expand_feature_switch_bitmap & CUSTOM_NBW_CAP) != 0) {
        device_info->config_para.nbw_uslot_cnt_per_slot = MAC_NBW_USLOT_NUM;
        device_info->config_para.nbw_uslot_duaration = MAC_NBW_USLOT_DURATION;
        device_info->config_para.schedule_period = MAC_NBW_SCHED_PERIOD;
        device_info->config_para.slot_duration = MAC_NBW_SLOT_DURATION;
    }
}


uint32_t hmac_nbw_change_flag_timeout(void *arg)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_vap = (hmac_vap_stru *)arg;
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_reset_topo_change_flag_timer::clear change indicate");
    hmac_nbw_set_topo_change_flag(NBW_TOPO_NO_CHANGED_INDICATE);
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_NO_CHANGED_INDICATE);
    return OAL_SUCC;
}


void hmac_nbw_reset_topo_change_flag_timer(hmac_vap_stru *hmac_vap)
{
    hmac_nbw_mgmt_info_stru *nbw_mgmt_info = hmac_nbw_get_mgmt_info();
    hmac_nbw_set_topo_change_flag(NBW_TOPO_CHANGED_INDICATE);
    if (nbw_mgmt_info->topo_change_flag_timer.en_is_registerd == OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_reset_topo_change_flag_timer::RESTART");
        frw_timer_restart_timer_m(&(nbw_mgmt_info->topo_change_flag_timer), WAITTING_THREE_DURATION_MS, OAL_FALSE);
    } else {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_reset_topo_change_flag_timer::CREAT");
        frw_timer_create_timer_m(&(nbw_mgmt_info->topo_change_flag_timer), hmac_nbw_change_flag_timeout,
            WAITTING_THREE_DURATION_MS, hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC,
            hmac_vap->st_vap_base_info.core_id);
    }
}


uint32_t hmac_nbw_beacon_sync_timeout(void *arg)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_vap = (hmac_vap_stru *)arg;
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    return hmac_chba_update_beacon_pnf(&hmac_vap->st_vap_base_info, hmac_nbw_get_master_macaddr(),
        MAC_CHBA_SYNC_BEACON);
}


void hmac_nbw_start_beacon_sync_timer(hmac_vap_stru *hmac_vap)
{
    hmac_nbw_mgmt_info_stru *nbw_mgmt_info = hmac_nbw_get_mgmt_info();
    if (nbw_mgmt_info->beacon_sync_timer.en_is_registerd != OAL_TRUE) {
        frw_timer_create_timer_m(&(nbw_mgmt_info->beacon_sync_timer), hmac_nbw_beacon_sync_timeout,
            WAITTING_SYNC_TIME_MS, hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC,
            hmac_vap->st_vap_base_info.core_id);
    }
}


uint32_t hmac_nbw_pnf_sync_timeout(void *arg)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_vap = (hmac_vap_stru *)arg;
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    return hmac_chba_update_beacon_pnf(&hmac_vap->st_vap_base_info, hmac_nbw_get_master_macaddr(), MAC_CHBA_PNF);
}


void hmac_nbw_start_pnf_sync_timer(hmac_vap_stru *hmac_vap)
{
    hmac_nbw_mgmt_info_stru *nbw_mgmt_info = hmac_nbw_get_mgmt_info();
    if (nbw_mgmt_info->pnf_sync_timer.en_is_registerd != OAL_TRUE) {
        frw_timer_create_timer_m(&(nbw_mgmt_info->pnf_sync_timer), hmac_nbw_pnf_sync_timeout, WAITTING_SYNC_TIME_MS,
            hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
    }
}

uint8_t hmac_nbw_slaveap_exist_in_domain(uint8_t work_mode, uint8_t *slaveap_addr, uint8_t addr_len)
{
    struct hi_node *node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *nbw_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    uint8_t slaveap_device_id = hmac_nbw_get_dev_alive_dev_table(work_mode, slaveap_addr);
    /* 找不到该设备，无节点待删除，返回 */
    if ((slaveap_device_id >= MAC_CHBA_MAX_DEVICE_NUM)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_slaveap_exist_in_domain: device id check error");
        return OAL_FALSE;
    }
    hi_list_for_each_safe(node, tmp, &island_info->island_list) {
        nbw_node = hi_node_entry(node, hmac_chba_island_list_node_stru, node);
        curr_island = &nbw_node->data;
        if (curr_island->owner_device_id == slaveap_device_id) {
            return OAL_TRUE;
        }
    }
    oam_warning_log1(0, OAM_SF_CHBA, "hmac_nbw_slaveap_exist_in_domain::island id %d first alloc", slaveap_device_id);
    return OAL_FALSE;
}


void hmac_nbw_get_self_island_info(uint8_t work_mode, hmac_chba_per_island_info_stru *self_island)
{
    struct hi_node *node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *nbw_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    if (self_island == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_get_self_island_info::island null");
    }
 
    oam_warning_log1(0, OAM_SF_CHBA, "hmac_nbw_get_self_island_info::island total cnt %d",
        island_info->island_cnt);
    hi_list_for_each_safe(node, tmp, &island_info->island_list) {
        nbw_node = hi_node_entry(node, hmac_chba_island_list_node_stru, node);
        curr_island = &nbw_node->data;
        if (curr_island->owner_device_id == self_conn_info->self_device_id) {
            *self_island = *curr_island;
            return;
        }
        oam_warning_log1(0, OAM_SF_CHBA, "hmac_nbw_get_self_island_info::island id %d", curr_island->owner_device_id);
    }
}

#ifdef _PRE_WLAN_NBW_DEMO
/*
 * 功能描述  : 生成user 同步信息并同步
 *   日    期  : 2021年3月25日
 *   作    者  : wifi
 */
void hmac_nbw_sync_user_bitmap_info(mac_vap_stru *mac_vap,
    hmac_user_stru *hmac_user, uint32_t user_bitmap)
{
    uint32_t ret;
    nbw_user_timeslot_bitmap_cfg_stru user_ps_cfg = { 0 };

    /* 将user同步信息初始化后, 同步给dmac */
    user_ps_cfg.user_idx = hmac_user->st_user_base_info.us_assoc_id;
    user_ps_cfg.bitmap = user_bitmap;
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_NBW_SET_USER_BITMAP, sizeof(nbw_user_timeslot_bitmap_cfg_stru),
        (uint8_t *)&user_ps_cfg);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_sync_user_bitmap_info::send_event fail[%d]", ret);
    }
}

void hmac_nbw_sync_user_bitmap(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, uint32_t user_bitmap)
{
    /* 暂时先继续沿用chba_vap，挂在下面，用nbw_mode区分 */
    hmac_chba_vap_stru *chba_vap_info = NULL;
    chba_vap_info = hmac_chba_get_chba_vap_info(hmac_vap);
    if (chba_vap_info == NULL || hmac_vap->st_vap_base_info.nbw_mode != NBW_MODE) {
        return;
    }
    oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_sync_user_bitmap::user_bitmap[%x]", user_bitmap);
    hmac_nbw_sync_user_bitmap_info(&(hmac_vap->st_vap_base_info), hmac_user, user_bitmap);
}

void hmac_nbw_sync_vap_bitmap_info(mac_vap_stru *mac_vap)
{
    uint32_t ret, bitmap;
    bitmap = hmac_nbw_get_slot_bitmap();
    oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_sync_vap_bitmap_info::vap_bitmap[%x]", bitmap);
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_NBW_SET_VAP_BITMAP, sizeof(uint32_t), (uint8_t *)&bitmap);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_sync_vap_bitmap_info:: send event fail");
    }
}
#else
void hmac_nbw_sync_user_bitmap_info(mac_vap_stru *mac_vap,
    hmac_user_stru *hmac_user, nbw_timeslot_bitmap_cfg_stru user_bitmap_info)
{
    uint32_t ret;
    nbw_user_timeslot_bitmap_cfg_stru user_ps_cfg = { 0 };

    /* 将user同步信息初始化后, 同步给dmac */
    user_ps_cfg.user_idx = hmac_user->st_user_base_info.us_assoc_id;
    user_ps_cfg.bitmap_info = user_bitmap_info;
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_NBW_SET_USER_BITMAP, sizeof(nbw_user_timeslot_bitmap_cfg_stru),
        (uint8_t *)&user_ps_cfg);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_sync_user_bitmap_info::send_event fail[%d]", ret);
    }
}

void hmac_nbw_sync_user_bitmap(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    nbw_timeslot_bitmap_cfg_stru user_bitmap_info)
{
    /* 暂时先继续沿用chba_vap，挂在下面，用nbw_mode区分 */
    hmac_chba_vap_stru *chba_vap_info = NULL;
    chba_vap_info = hmac_chba_get_chba_vap_info(hmac_vap);
    if (chba_vap_info == NULL || hmac_vap->st_vap_base_info.nbw_mode != NBW_MODE) {
        return;
    }

    hmac_nbw_sync_user_bitmap_info(&(hmac_vap->st_vap_base_info), hmac_user, user_bitmap_info);
}

void hmac_nbw_sync_vap_bitmap_info(mac_vap_stru *mac_vap, nbw_timeslot_bitmap_cfg_stru bitmap_info)
{
    uint32_t ret;
    if (mac_vap->nbw_mode != NBW_MODE) {
        return;
    }
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_NBW_SET_VAP_BITMAP, sizeof(nbw_timeslot_bitmap_cfg_stru),
        (uint8_t *)&bitmap_info);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_sync_vap_bitmap_info::send_event fail[%d]", ret);
    }
}
#endif

void hmac_nbw_sync_timeslot_info(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t work_uslot_flag, uint8_t work_slot_flag)
{
#ifdef _PRE_WLAN_NBW_DEMO
    hmac_nbw_sync_user_bitmap(hmac_vap, hmac_user,
        mac_nbw_uslot_bitmap_to_bitmap(timeslot_info.uslot_info.work_uslot_bitmap));
    hmac_nbw_update_uslot_bitmap_for_slot_alloced(hmac_vap, timeslot_info);
    hmac_nbw_sync_vap_bitmap_info(&(hmac_vap->st_vap_base_info));
#else
    nbw_timeslot_bitmap_cfg_stru user_bitmap_info = { 0 };
    nbw_timeslot_bitmap_cfg_stru vap_bitmap_info = { 0 };
    user_bitmap_info.uslot_bitmap = timeslot_info.uslot_info.uslot_bitmap;
    user_bitmap_info.work_uslot_bitmap = timeslot_info.uslot_info.work_uslot_bitmap;
    user_bitmap_info.slot_bitmap = mac_nbw_level_to_slot_bitmap(timeslot_info.slot_period_level);
    user_bitmap_info.work_slot_flag = work_slot_flag;
    user_bitmap_info.work_uslot_flag = work_uslot_flag;
    hmac_nbw_sync_user_bitmap(hmac_vap, hmac_user, user_bitmap_info);
    hmac_nbw_update_uslot_bitmap_for_slot_alloced(hmac_vap, timeslot_info);
    vap_bitmap_info.uslot_bitmap = hmac_nbw_get_used_uslot_bitmap();
    vap_bitmap_info.slot_bitmap = hmac_nbw_get_cur_slot_bitmap();
    vap_bitmap_info.work_slot_flag = work_slot_flag;
    vap_bitmap_info.work_uslot_flag = work_uslot_flag;
    hmac_nbw_sync_vap_bitmap_info(&(hmac_vap->st_vap_base_info), vap_bitmap_info);
#endif
}


void hmac_nbw_sync_timeslot_info_with_conn(hmac_vap_stru *hmac_vap, hmac_nbw_slot_info_stru slot_info,
    uint8_t work_uslot_flag, uint8_t work_slot_flag)
{
    hmac_user_stru *hmac_user = NULL;
    if (hmac_vap == NULL) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_sync_timeslot_info_with_conn::hmac_vap NULL.");
        return;
    }
    hmac_user = mac_vap_get_hmac_user_by_addr(&hmac_vap->st_vap_base_info,
        slot_info.peer_device_mac, WLAN_MAC_ADDR_LEN);
    if (hmac_user == NULL) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_sync_timeslot_info_with_conn::no connect.");
        return;
    }
    hmac_nbw_sync_timeslot_info(hmac_vap, hmac_user, slot_info, work_uslot_flag, work_slot_flag);
}
/*
 * 功能描述  : 检查此次时隙调整是接受还是拒绝
 * 日    期  : 2025年01月17日
 */
static uint32_t hmac_nbw_check_timeslot_adjust(hmac_nbw_uslot_info_stru before_uslot_bitmap_info,
    hmac_nbw_uslot_info_stru after_uslot_bitmap_info)
{
    uint8_t cur_uslot_bitmap = hmac_nbw_get_available_uslot_bitmap();
    /* 如果调整后的时隙被调整前的时隙完全覆盖，则可以调整，不用进行后面的检查 */
    if (after_uslot_bitmap_info.start_idx >= before_uslot_bitmap_info.start_idx &&
        after_uslot_bitmap_info.end_idx <= before_uslot_bitmap_info.end_idx) {
        return OAL_SUCC;
    }
    /* 不然的话要看去掉了before bitmap后的可用bitmap能否容纳after bitmap */
    if ((cur_uslot_bitmap & after_uslot_bitmap_info.uslot_bitmap) == 0) {
        return OAL_SUCC;
    } else {
        return OAL_FAIL;
    }
}

uint8_t hmac_nbw_find_slot_link_idx(hmac_nbw_slot_info_stru *slot_info, uint8_t *peer_addr)
{
    uint8_t idx;
    for (idx = 0; idx < MAX_ISLAND_SLOT_INFO_NUM; idx++) {
        if (slot_info[idx].use_flag == OAL_TRUE &&
            oal_memcmp(slot_info[idx].peer_device_mac, peer_addr, OAL_MAC_ADDR_LEN) == 0) {
            return idx;
        }
    }
    return NBW_INVALID_IDX;
}

uint8_t hmac_nbw_find_unused_link_idx(hmac_nbw_slot_info_stru *slot_info)
{
    uint8_t idx;
    for (idx = 0; idx < MAX_ISLAND_SLOT_INFO_NUM; idx++) {
        if (slot_info[idx].use_flag == OAL_TRUE) {
            continue;
        }
        return idx;
    }
    return NBW_INVALID_IDX;
}

uint8_t hmac_nbw_count_device_num(uint32_t device_bitmap)
{
    uint8_t count = 0;
    while (device_bitmap) {
        device_bitmap &= device_bitmap - 1;
        count++;
    }
    return count;
}


void hmac_nbw_update_self_role(hmac_vap_stru *hmac_vap)
{
    uint8_t work_mode = hmac_vap->st_vap_base_info.work_mode;
    uint8_t nbw_role = hmac_nbw_get_role();
    uint8_t slave_link_cnt = hmac_nbw_get_slave_link_cnt();
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    uint8_t self_island_exist = (device_id_info[self_conn_info->self_device_id].slaveap_id_bitmap
        & BIT(self_conn_info->self_device_id)) == BIT(self_conn_info->self_device_id);
    uint8_t new_nbw_role;
    if (nbw_role == MAC_NBW_MASTER_ROLE) {
        return;
    }
    /* 本设备在岛域拓扑中作为岛主存在 */
    if (self_island_exist && slave_link_cnt) {
        new_nbw_role = MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE;
    } else if (self_island_exist && slave_link_cnt == 0) {
        new_nbw_role = MAC_NBW_SLAVEAP_ROLE;
    } else if (!self_island_exist && slave_link_cnt) {
        new_nbw_role = MAC_NBW_SLAVE_ROLE;
    } else {
        new_nbw_role = MAC_NBW_OTHER_DEVICE;
    }

    if (new_nbw_role != nbw_role) {
        hmac_nbw_set_role(new_nbw_role);
        hmac_nbw_sync_self_role(hmac_vap);
    }
}


void hmac_nbw_update_island_slot_info(hmac_nbw_slot_info_stru *island_slot_info, uint8_t link_idx,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t *peer_mac_addr)
{
    oam_warning_log1(0, OAM_SF_CHBA, "{hmac_nbw_update_island_slot_info::link idx:%d", link_idx);
    if (link_idx == NBW_INVALID_IDX || island_slot_info == NULL) {
        return;
    }
    if (memcpy_s(island_slot_info[link_idx].peer_device_mac, WLAN_MAC_ADDR_LEN,
        peer_mac_addr, WLAN_MAC_ADDR_LEN) != EOK) {
        return;
    }
    island_slot_info[link_idx].uslot_info = timeslot_info.uslot_info;
    island_slot_info[link_idx].use_flag = OAL_TRUE;
    island_slot_info[link_idx].slot_period_level = timeslot_info.slot_period_level;
    oam_warning_log4(0, OAM_SF_NBW, "hmac_nbw_update_island_slot_info:: start:%d, end:%d, bitmap:%x, work bitmap:%x",
        timeslot_info.uslot_info.start_idx, timeslot_info.uslot_info.end_idx, timeslot_info.uslot_info.uslot_bitmap,
        timeslot_info.uslot_info.work_uslot_bitmap);
}


static void hmac_nbw_update_island_device_list(uint8_t work_mode, uint8_t slaveap_id,
    hmac_nbw_slot_info_stru *island_slot_info, uint8_t *device_list)
{
    uint8_t device_cnt = 1;
    uint8_t i, device_id;
    memset_s(device_list, MAC_CHBA_MAX_DEVICE_NUM * sizeof(uint8_t), 0, MAC_CHBA_MAX_DEVICE_NUM * sizeof(uint8_t));
    device_list[0] = slaveap_id;
    for (i = 0; i < MAX_ISLAND_SLOT_INFO_NUM; i++) {
        if (island_slot_info[i].use_flag != OAL_TRUE) {
            continue;
        }
        device_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, island_slot_info[i].peer_device_mac);
        if (device_id >= MAC_CHBA_MAX_DEVICE_NUM) {
            return;
        }
        *(device_list + device_cnt) = device_id;
        device_cnt ++;
    }
    oam_warning_log1(0, OAM_SF_CHBA, "{hmac_nbw_update_island_device_list::device_cnt:%d", device_cnt);
}


void hmac_nbw_update_group_island_flag(uint8_t work_mode, hmac_chba_per_island_info_stru *curr_island,
    uint32_t slaveap_bitmap)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *other_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    if (hmac_nbw_count_device_num(slaveap_bitmap) == 1) {
        return;
    }
    curr_island->island_flag = MAC_NBW_GROUP_ISLAND;
    
    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        other_island = &island_node->data;
        if (other_island->owner_device_id == curr_island->owner_device_id)
            continue;
        if ((slaveap_bitmap & BIT(other_island->owner_device_id)) != 0)
            other_island->island_flag = MAC_NBW_GROUP_ISLAND;
    }
}


uint8_t hmac_nbw_check_island_type(uint8_t work_mode, hmac_nbw_slot_info_stru *slot_info)
{
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    uint32_t slaveap_bitmap = 0;
    int i, device_id;
    for (i = 0; i < MAX_ISLAND_SLOT_INFO_NUM; i++) {
        if (slot_info[i].use_flag != OAL_TRUE)
            continue;
        device_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, slot_info[i].peer_device_mac);
        slaveap_bitmap |= device_id_info[device_id].slaveap_id_bitmap;
    }
    if (hmac_nbw_count_device_num(slaveap_bitmap) == 1)
        return MAC_NBW_SINGLE_ISLAND;
    return MAC_NBW_GROUP_ISLAND;
}


uint32_t hmac_nbw_get_island_slave_info(uint8_t work_mode, uint8_t slaveap_id)
{
    uint32_t slave_bitmap = 0;
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
     /* 域内岛域数目 */
    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (slaveap_id == curr_island->owner_device_id) {
            slave_bitmap = hmac_nbw_island_slave_bitmap(curr_island);
            return slave_bitmap;
        }
    }
    return slave_bitmap;
}


uint8_t hmac_nbw_island_slave_bitmap(hmac_chba_per_island_info_stru *island_info)
{
    uint8_t idx;
    uint8_t slave_bitmap = 0;

    for (idx = 0; idx < island_info->device_cnt; idx++) {
        if (island_info->device_list[idx] == island_info->owner_device_id) {
            continue;
        }
        slave_bitmap |= BIT(island_info->device_list[idx]);
    }
    return slave_bitmap;
}


void hmac_nbw_update_single_island_flag(uint8_t work_mode, uint32_t slaveap_bitmap)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *other_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    if (hmac_nbw_count_device_num(slaveap_bitmap) != 1) {
        return;
    }

    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        other_island = &island_node->data;
        if ((slaveap_bitmap & BIT(other_island->owner_device_id)) == 0) {
            continue;
        }
        other_island->island_flag = hmac_nbw_check_island_type(work_mode, other_island->island_slot_info);
    }
}


static void hmac_nbw_update_exist_island_info(uint8_t work_mode, hmac_chba_per_island_info_stru *curr_island,
    hmac_nbw_island_conn_info_rpt *island_conn_info, uint32_t slaveap_bitmap, uint8_t slave_id)
{
    hmac_nbw_slot_info_stru *slot_info = NULL;
    uint8_t link_idx;
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    if (oal_any_null_ptr2(curr_island, island_conn_info)) {
        return;
    }
    slot_info = curr_island->island_slot_info;
    curr_island->slaveap_rp = island_conn_info->slaveap_rp;
    link_idx = hmac_nbw_find_slot_link_idx(curr_island->island_slot_info,
        device_id_info[slave_id].mac_addr);
    if (link_idx == NBW_INVALID_IDX) {
        hmac_nbw_update_island_slot_info(slot_info, hmac_nbw_find_unused_link_idx(slot_info),
            island_conn_info->slot_info, device_id_info[slave_id].mac_addr);
        curr_island->device_cnt++;
    } else {
        hmac_nbw_resume_uslot_bitmap(curr_island->island_slot_info[link_idx].uslot_info.uslot_bitmap);
        hmac_nbw_update_island_slot_info(curr_island->island_slot_info,
            link_idx, island_conn_info->slot_info, device_id_info[slave_id].mac_addr);
    }
    if (island_conn_info->island_flag == MAC_NBW_ISLAND_TYPE_BUTT) {
        hmac_nbw_update_group_island_flag(work_mode, curr_island, slaveap_bitmap);
    } else {
        curr_island->island_flag = island_conn_info->island_flag;
    }
}


void hmac_nbw_update_island_info(uint8_t work_mode, hmac_nbw_island_conn_info_rpt island_conn_info,
    uint8_t slaveap_id, uint8_t slave_id)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_island_list_node_stru *new_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    uint8_t find_flag = FALSE;
    uint32_t slaveap_bitmap = device_id_info[slaveap_id].slaveap_id_bitmap & device_id_info[slave_id].slaveap_id_bitmap;

    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (slaveap_id == curr_island->owner_device_id) {
            oam_warning_log1(0, 0, "NBW: hmac_nbw_update_island_info: find island, owner id %d",
                curr_island->owner_device_id);
            hmac_nbw_update_exist_island_info(work_mode, curr_island, &island_conn_info, slaveap_bitmap, slave_id);
            find_flag = TRUE;
            hmac_nbw_update_island_device_list(work_mode, slaveap_id, curr_island->island_slot_info,
                curr_island->device_list);
            break;
        }
    }

    if (find_flag == FALSE) { /* 该岛不存在 */
        curr_island = NULL;
        new_node = (hmac_chba_island_list_node_stru *)oal_memalloc(sizeof(hmac_chba_island_list_node_stru));
        if (new_node == NULL) {
            return;
        }
        curr_island = &new_node->data;
        curr_island->owner_device_id = slaveap_id;
        if (hmac_nbw_self_device_update_rp(work_mode, curr_island) != OAL_TRUE) {
            curr_island->slaveap_rp = island_conn_info.slaveap_rp;
        }
        hmac_nbw_update_island_slot_info(curr_island->island_slot_info,
            0, island_conn_info.slot_info, device_id_info[slave_id].mac_addr);
        curr_island->device_cnt = NBW_ISLAND_MIN_DEVICE_NUM;
        if (island_conn_info.island_flag == MAC_NBW_ISLAND_TYPE_BUTT) {
            hmac_nbw_update_group_island_flag(work_mode, curr_island, slaveap_bitmap);
        } else {
            curr_island->island_flag = island_conn_info.island_flag;
        }
        curr_island->device_list[0] = slaveap_id;
        curr_island->device_list[1] = slave_id;
        oam_warning_log1(0, 0, "NBW: hmac_nbw_update_island_info: new island, owner id %d",
            curr_island->owner_device_id);
        hi_list_add_tail(&island_info->island_list, &new_node->node);
        island_info->island_cnt++;
    }
}


void hmac_nbw_clear_device_info(uint8_t work_mode, uint8_t slaveap_id, uint8_t slave_id)
{
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    if (device_id_info[slaveap_id].slaveap_id_bitmap == 0) {
        hmac_chba_del_one_device_info(work_mode, slaveap_id);
    }
    if (device_id_info[slave_id].slaveap_id_bitmap == 0) {
        hmac_chba_del_one_device_info(work_mode, slave_id);
    }
}

void hmac_nbw_clear_island_info(uint8_t work_mode, uint8_t slaveap_id, uint8_t slave_id)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    /* slave设备信息清除对应slaveAp */
    device_id_info[slave_id].slaveap_id_bitmap &= ~BIT(slaveap_id);

    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (slaveap_id == curr_island->owner_device_id) {
            uint8_t link_idx = hmac_nbw_find_slot_link_idx(curr_island->island_slot_info,
                device_id_info[slave_id].mac_addr);
            if (link_idx == NBW_INVALID_IDX) {
                oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_clear_island_info: link not find");
                return;
            }
            hmac_nbw_resume_uslot_bitmap(curr_island->island_slot_info[link_idx].uslot_info.uslot_bitmap);
            memset_s(&curr_island->island_slot_info[link_idx], sizeof(hmac_nbw_slot_info_stru),
                0, sizeof(hmac_nbw_slot_info_stru));
            curr_island->device_cnt--;
            /* 链路所属岛域没有其他链路存在 */
            if (curr_island->device_cnt == 1) {
                /* slaveAp设备信息清除本slaveAp */
                device_id_info[slaveap_id].slaveap_id_bitmap &= ~BIT(slaveap_id);
            }
            if (curr_island->island_flag == MAC_NBW_SINGLE_ISLAND) {
                /* 删链前当前岛域是单岛, 不涉及群岛到单岛的标志变化 */
                break;
            }
            hmac_nbw_update_island_device_list(work_mode, slaveap_id, curr_island->island_slot_info,
                curr_island->device_list);
            hmac_nbw_update_single_island_flag(work_mode, device_id_info[slaveap_id].slaveap_id_bitmap);
            hmac_nbw_update_single_island_flag(work_mode, device_id_info[slave_id].slaveap_id_bitmap);
            break;
        }
    }
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_clear_island_info::slaveap mac[%02X:XX:XX:XX:%02X:%02X]}",
        device_id_info[slaveap_id].mac_addr[0], device_id_info[slaveap_id].mac_addr[BYTE_OFFSET_4],
        device_id_info[slaveap_id].mac_addr[BYTE_OFFSET_5]);
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_clear_island_info::slave mac[%02X:XX:XX:XX:%02X:%02X]}",
        device_id_info[slave_id].mac_addr[0], device_id_info[slave_id].mac_addr[BYTE_OFFSET_4],
        device_id_info[slave_id].mac_addr[BYTE_OFFSET_5]);
    /* 链路删除后， 当前岛域无其他链路存在，则删除岛域节点 */
    if (curr_island != NULL && curr_island->device_cnt == 1) {
        hmac_nbw_island_list_node_release(nbw_node);
        island_info->island_cnt--;
    }
    /* 清除device id信息 */
    hmac_nbw_clear_device_info(work_mode, slaveap_id, slave_id);
}

uint32_t hmac_nbw_timeslot_borrow_wait_timeout(void *arg)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();
    hmac_nbw_timeslot_borrow_info_stru *timeslot_borrow_info = hmac_nbw_get_timeslot_borrow_info();
    hmac_vap = (hmac_vap_stru *)arg;
    if (hmac_vap == NULL) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_timeslot_borrow_wait_timeout: arg is null}");
        return OAL_ERR_CODE_PTR_NULL;
    }
 
    /* 如果已经收到resp，则直接返回 */
    if (timeslot_borrow_info->confirm_flag == OAL_TRUE) {
        oam_warning_log0(0, 0, "NBW: {hmac_nbw_timeslot_borrow_wait_timeout: already recv resp, stop timer}");
        return OAL_SUCC;
    }
 
    timeslot_borrow_info->retry_cnt++;
    if (timeslot_borrow_info->retry_cnt > NBW_MAX_TIMESLOT_BORROW_STOP_INFORM_CNT) {
        oam_error_log0(0, 0, "NBW: {hmac_nbw_timeslot_borrow_wait_timeout: exceed max retry cnt}");
        /* 时隙借用通知超时，待完善 */
        return OAL_SUCC;
    }
 
    hmac_nbw_send_timeslot_frame(timeslot_borrow_info->peer_addr, timeslot_borrow_info->slave_addr,
        OAL_MAC_ADDR_LEN, timeslot_borrow_info->send_slot_info, MAC_NBW_TIMESLOT_ADJUST_ACTION,
        MAC_NBW_TIMESLOT_INFORM_BORROW_REQ_ACTION);
    frw_timer_create_timer_m(&sync_info->timeslot_borrow_timer, hmac_nbw_timeslot_borrow_wait_timeout,
        MAC_NBW_DEFALUT_PERIODS_MS, hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
 
    oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_timeslot_borrow_wait_timeout:: retry send, cnt:%d",
        timeslot_borrow_info->retry_cnt);
    return OAL_SUCC;
}

static void hmac_nbw_update_work_bitmap_and_notify(hmac_vap_stru *hmac_vap, hmac_nbw_slot_info_stru *island_slot_info,
    uint8_t old_work_uslot_bitmap, uint8_t new_work_uslot_bitmap, uint8_t owner_device_id)
{
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();
    hmac_nbw_timeslot_borrow_info_stru *timeslot_borrow_info = hmac_nbw_get_timeslot_borrow_info();
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(hmac_vap->st_vap_base_info.work_mode);
    hmac_chba_per_device_id_info_stru *device_id_info =
        hmac_chba_get_device_id_info(hmac_vap->st_vap_base_info.work_mode);

    /* 初始化时隙借用结构体 */
    memset_s(timeslot_borrow_info, sizeof(hmac_nbw_timeslot_borrow_info_stru),
        0, sizeof(hmac_nbw_timeslot_borrow_info_stru));
    memcpy_s(&timeslot_borrow_info->send_slot_info, sizeof(hmac_nbw_slot_info_stru),
        island_slot_info, sizeof(hmac_nbw_slot_info_stru));
    timeslot_borrow_info->old_work_timeslot = old_work_uslot_bitmap;

    /* 如果是和本设备关联的链路，在收到resp后，同步将时隙配置到device。非本设备关联链路，则直接通知对应slaveap即可 */
    if (self_conn_info->self_device_id == owner_device_id) {
        oal_set_mac_addr(timeslot_borrow_info->peer_addr, island_slot_info->peer_device_mac);
        oal_set_mac_addr(timeslot_borrow_info->slave_addr, island_slot_info->peer_device_mac);
        timeslot_borrow_info->request_flag = NBW_MASTER_SLAVE_TIMESLOT_BORROW;
    } else {
        oal_set_mac_addr(timeslot_borrow_info->peer_addr, device_id_info[owner_device_id].mac_addr);
        oal_set_mac_addr(timeslot_borrow_info->slave_addr, island_slot_info->peer_device_mac);
        timeslot_borrow_info->request_flag = NBW_MASTER_SLAVEAP_TIMESLOT_BORROW;
    }

    hmac_nbw_send_timeslot_frame(timeslot_borrow_info->peer_addr, timeslot_borrow_info->slave_addr,
        OAL_MAC_ADDR_LEN, timeslot_borrow_info->send_slot_info, MAC_NBW_TIMESLOT_ADJUST_ACTION,
        MAC_NBW_TIMESLOT_INFORM_BORROW_REQ_ACTION);

    frw_timer_create_timer_m(&sync_info->timeslot_borrow_timer, hmac_nbw_timeslot_borrow_wait_timeout,
        MAC_NBW_DEFALUT_PERIODS_MS, hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC,
        hmac_vap->st_vap_base_info.core_id);

    oam_warning_log3(0, OAM_SF_NBW,
        "hmac_nbw_update_work_bitmap_and_notify::notify peer=%02X:XX:XX:XX:XX:%02X, request_flag:%d",
        timeslot_borrow_info->peer_addr[MAC_ADDR_0], timeslot_borrow_info->peer_addr[MAC_ADDR_5],
        timeslot_borrow_info->request_flag);
    oam_warning_log3(0, OAM_SF_NBW,
        "hmac_nbw_update_work_bitmap_and_notify::link_slot:%x, new_work_slot:%x, old_work_slot:%x",
        island_slot_info->uslot_info.uslot_bitmap, new_work_uslot_bitmap, old_work_uslot_bitmap);

    return;
}


void hmac_nbw_handle_timeslot_borrow(hmac_vap_stru *hmac_vap)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_info = NULL;
    uint8_t slot_idx, old_work_uslot_bitmap, new_work_uslot_bitmap;
    uint8_t work_mode = hmac_vap->st_vap_base_info.work_mode;
    uint8_t domain_alloc_uslot = hmac_nbw_get_available_uslot_bitmap();
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();

    if (hmac_nbw_get_role() != MAC_NBW_MASTER_ROLE) {
        return;
    }

    if (sync_info->timeslot_borrow_timer.en_is_registerd) {
        oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_handle_timeslot_borrow::timeslot borrow notify is ongoing}");
        frw_timer_immediate_destroy_timer_m(&(sync_info->timeslot_borrow_timer));
    }

    /* 遍历岛屿拓扑，通知可能存在时隙借用的设备对 */
    island_info = hmac_chba_get_island_list(work_mode);
    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        for (slot_idx = 0; slot_idx < MAX_ISLAND_SLOT_INFO_NUM; slot_idx++) {
            hmac_nbw_slot_info_stru *island_slot_info = &curr_island->island_slot_info[slot_idx];
            if (island_slot_info->use_flag == OAL_FALSE)
                continue;
            old_work_uslot_bitmap = island_slot_info->uslot_info.work_uslot_bitmap;
            new_work_uslot_bitmap = hmac_nbw_calc_work_uslot(island_slot_info->uslot_info.uslot_bitmap,
                domain_alloc_uslot);
            /* 若工作时隙有变更，则需要通知到对应的链路刷新工作时隙，按当前时隙分配规则，只会存在一对设备变更 */
            if (old_work_uslot_bitmap != new_work_uslot_bitmap) {
                /* 更新岛域拓扑内的工作时隙 */
                island_slot_info->uslot_info.work_uslot_bitmap = new_work_uslot_bitmap;
                /* 处理时隙借用发送请求 */
                hmac_nbw_update_work_bitmap_and_notify(hmac_vap, island_slot_info, old_work_uslot_bitmap,
                    new_work_uslot_bitmap, curr_island->owner_device_id);
                break;
            }
        }
    }
}


void hmac_nbw_update_conn_info(hmac_vap_stru *hmac_vap, hmac_nbw_island_conn_info_rpt island_conn_info,
    uint8_t *slave_addr, uint8_t *slaveap_addr, uint8_t addr_len)
{
    mac_chba_conn_info_rpt conn_info_context;
    uint8_t slaveap_id, slave_id, work_mode;
    if (oal_any_null_ptr4(hmac_vap, hmac_vap->hmac_chba_vap_info, slaveap_addr, slave_addr)) {
        oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_update_conn_info::input null ptr}");
        return;
    }
    work_mode = hmac_vap->st_vap_base_info.work_mode;

    /* 未初始化不处理 */
    if (hmac_chba_get_module_state(work_mode) == MAC_CHBA_MODULE_STATE_UNINIT) {
        oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_update_conn_info::module state uinit}");
        return;
    }

    /* 封装下文所需关键变量 */
    oal_set_mac_addr(conn_info_context.self_mac_addr, slaveap_addr);
    oal_set_mac_addr(conn_info_context.peer_mac_addr, slave_addr);
    conn_info_context.work_channel = hmac_vap->hmac_chba_vap_info->work_channel;

    slaveap_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, slaveap_addr);
    slave_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, slave_addr);
    if ((slaveap_id >= MAC_CHBA_MAX_DEVICE_NUM) || (slave_id >= MAC_CHBA_MAX_DEVICE_NUM)) {
        oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_update_conn_info::device id error}");
        return;
    }
    /* 根据上报的建链信息，更新连接拓扑图和设备ID信息 */
    hmac_chba_conn_add_update_network_topo(work_mode, conn_info_context, slaveap_id, slave_id);
    hmac_nbw_update_island_info(work_mode, island_conn_info, slaveap_id, slave_id);
    /* 申请到的时隙配置到map表中 */
    hmac_nbw_set_available_uslot_bitmap(island_conn_info.slot_info.uslot_info.uslot_bitmap);
    /* 更新岛域拓扑后，重新计算岛域内的工作时隙，并通知时隙变化的设备 */
    hmac_nbw_handle_timeslot_borrow(hmac_vap);
    /* 更新rp值排序信息 */
    hmac_nbw_update_rp_ranking_id(work_mode);

    /* 将时隙信息同步到DMAC */
    hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, island_conn_info.slot_info, 1, 1);

    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_update_conn_info::slaveap mac[%02X:XX:XX:XX:%02X:%02X]}",
        slaveap_addr[0], slaveap_addr[BYTE_OFFSET_4],
        slaveap_addr[BYTE_OFFSET_5]);
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_update_conn_info::slave mac[%02X:XX:XX:XX:%02X:%02X]}",
        slave_addr[0], slave_addr[BYTE_OFFSET_4],
        slave_addr[BYTE_OFFSET_5]);
}


void hmac_nbw_clear_conn_info(hmac_vap_stru *hmac_vap, uint8_t *slave_addr, uint8_t *peer_addr)
{
    uint8_t slaveap_id, slave_id;
    uint8_t nbw_role = hmac_nbw_get_role();
    uint8_t work_mode = hmac_vap->st_vap_base_info.work_mode;
    hmac_nbw_slot_info_stru timeslot_info = { 0 };
    uint8_t invalid_addr[OAL_MAC_ADDR_LEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

    /* 未初始化不处理 */
    if (hmac_chba_get_module_state(work_mode) == MAC_CHBA_MODULE_STATE_UNINIT) {
        return;
    }
    if (oal_any_null_ptr2(peer_addr, slave_addr)) {
        return;
    }
    slaveap_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, peer_addr);
    slave_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, slave_addr);
    if ((slaveap_id >= MAC_CHBA_MAX_DEVICE_NUM) || (slave_id >= MAC_CHBA_MAX_DEVICE_NUM)) {
        oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_clear_conn_info::device id error}");
        return;
    }
    /* 根据上报的建链信息，清除连接拓扑图 */
    hmac_chba_set_network_topo_ele_false(work_mode, slaveap_id, slave_id);
    hmac_chba_set_network_topo_ele_false(work_mode, slave_id, slaveap_id);

    /* 岛域信息中删除对应链路 */
    hmac_nbw_clear_island_info(work_mode, slaveap_id, slave_id);

    hmac_nbw_update_rp_ranking_id(work_mode);
    /* 断链场景，在master清空某个岛主信息后，或者master/slaveap删除相关user时，需要重新计算工作时隙 */
    hmac_nbw_handle_timeslot_borrow(hmac_vap);

    /* 岛主告知域主时隙释放 */
    if (nbw_role == MAC_NBW_SLAVEAP_ROLE || nbw_role == MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE) {
        timeslot_info.uslot_info.start_idx = INVALID_TIMESLOT_USLOT_IDX; // 255为无效值
        timeslot_info.uslot_info.end_idx = INVALID_TIMESLOT_USLOT_IDX; // 255为无效值
        hmac_nbw_send_timeslot_frame(hmac_nbw_get_master_macaddr(), invalid_addr, OAL_MAC_ADDR_LEN,
            timeslot_info, MAC_NBW_TIMESLOT_ADJUST_ACTION,
            MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_ACTION);
    }
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_clear_conn_info::slaveap mac[%02X:XX:XX:XX:%02X:%02X]}",
        peer_addr[0], peer_addr[BYTE_OFFSET_4],
        peer_addr[BYTE_OFFSET_5]);
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_clear_conn_info::slave mac[%02X:XX:XX:XX:%02X:%02X]}",
        slave_addr[0], slave_addr[BYTE_OFFSET_4],
        slave_addr[BYTE_OFFSET_5]);
}

static void hmac_nbw_island_list_node_clear_device_info(hmac_chba_per_island_info_stru *island)
{
    uint8_t idx;
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(NBW_WORK_MODE);
    for (idx = 0; idx < island->device_cnt; idx++) {
        if (island->device_list[idx] == island->owner_device_id) {
            continue;
        }

        /* 删除岛域节点内的slave有且仅有当前岛主的链路时，清除设备信息 */
        if ((device_id_info[island->device_list[idx]].slaveap_id_bitmap & 0xFF) == BIT(island->owner_device_id)) {
            hmac_chba_del_one_device_info(NBW_WORK_MODE, island->device_list[idx]);
        }
    }
}
/*
 * 功能描述  : 释放一个岛信息链表节点的内存
 * 日    期  : 2025年02月24日
 */
void hmac_nbw_island_list_node_release(struct hi_node *node)
{
    hmac_chba_island_list_node_stru *n = NULL;
    if (node == NULL) {
        return;
    }
    n = hi_node_entry(node, hmac_chba_island_list_node_stru, node);
    hmac_nbw_island_list_node_clear_device_info(&n->data);
    hi_list_remove(node);
    oal_free(n);
}


static void hmac_nbw_slave_release_timeslot(hmac_vap_stru *hmac_vap, uint8_t *slaveap_addr)
{
    uint8_t slot_idx;
    hmac_nbw_slot_info_stru timeslot_info = { 0 };
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();

    slot_idx = hmac_nbw_find_slot_link_idx(slave_slot_info, slaveap_addr);
    if (slot_idx == NBW_INVALID_IDX) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_slave_release_timeslot: not find link slot.");
        return;
    }
    oal_set_mac_addr(timeslot_info.peer_device_mac, slaveap_addr);
    /* 更新vap bitmap */
    hmac_nbw_update_uslot_bitmap_for_link_disconnect(slave_slot_info[slot_idx].uslot_info.uslot_bitmap);
    hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, timeslot_info, 1, 1);

    /* 清除uslot */
    memset_s(&slave_slot_info[slot_idx], sizeof(hmac_nbw_slot_info_stru), 0, sizeof(hmac_nbw_slot_info_stru));

    hmac_nbw_slave_link_cnt_dec();
    /* 发送时隙调整帧释放帧给slaveap */
    timeslot_info.uslot_info.start_idx = INVALID_TIMESLOT_USLOT_IDX; // 255为无效值
    timeslot_info.uslot_info.end_idx = INVALID_TIMESLOT_USLOT_IDX; // 255为无效值
    hmac_nbw_send_timeslot_frame(hmac_nbw_get_master_macaddr(), slaveap_addr, OAL_MAC_ADDR_LEN, timeslot_info,
        MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_ACTION);
}


void hmac_nbw_release_timeslot(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t peer_len,
    uint8_t *other_addr, uint8_t other_len)
{
    uint8_t device_role;
    if (oal_any_null_ptr2(peer_addr, other_addr) || peer_len > WLAN_MAC_ADDR_LEN || other_len > WLAN_MAC_ADDR_LEN) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_release_timeslot: addr is null.");
        return;
    }

    device_role = hmac_nbw_get_role();
    switch (device_role) {
        case MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE:
            hmac_nbw_clear_conn_info(hmac_vap, peer_addr, other_addr);
            hmac_nbw_slave_release_timeslot(hmac_vap, peer_addr);
            break;
        case MAC_NBW_MASTER_ROLE:
            /* slave slaveAP */
            hmac_nbw_clear_conn_info(hmac_vap, peer_addr, other_addr);
            break;
        case MAC_NBW_SLAVEAP_ROLE:
            /* peer_addr为slave地址，other addr为slaveap地址或者master地址（与master自有连接断开） */
            hmac_nbw_clear_conn_info(hmac_vap, peer_addr, other_addr);
            break;
        case MAC_NBW_SLAVE_ROLE:
            /* peer_addr为slaveap地址，other_addr不使用 */
            hmac_nbw_slave_release_timeslot(hmac_vap, peer_addr);
            break;
        default:
            oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_release_timeslot: device_role is wrong.");
            break;
    }
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
}


uint32_t hmac_nbw_master_adjust_timeslot(uint8_t work_mode, uint8_t *peer_addr, uint8_t peer_len,
    uint8_t *slave_addr, uint8_t slave_len, hmac_nbw_uslot_info_stru uslot_bitmap_info)
{
    uint8_t slaveap_id;
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    if (oal_any_null_ptr2(peer_addr, slave_addr) || peer_len > WLAN_MAC_ADDR_LEN || slave_len > WLAN_MAC_ADDR_LEN) {
        return OAL_FAIL;
    }
    slaveap_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, peer_addr);
    
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_master_adjust_timeslot::slaveap mac[%02X:XX:XX:XX:%02X:%02X]}",
        peer_addr[0], peer_addr[BYTE_OFFSET_4],
        peer_addr[BYTE_OFFSET_5]);
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_master_adjust_timeslot::slave mac[%02X:XX:XX:XX:%02X:%02X]}",
        slave_addr[0], slave_addr[BYTE_OFFSET_4],
        slave_addr[BYTE_OFFSET_5]);

    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (slaveap_id == curr_island->owner_device_id) {
            uint8_t link_idx = hmac_nbw_find_slot_link_idx(curr_island->island_slot_info, slave_addr);
            if (link_idx == NBW_INVALID_IDX) {
                return OAL_FAIL;
            }
            oam_warning_log1(0, OAM_SF_CHBA, "{hmac_nbw_master_adjust_timeslot::link idx:%d", link_idx);
            if (hmac_nbw_check_timeslot_adjust(curr_island->island_slot_info[link_idx].uslot_info,
                uslot_bitmap_info) == OAL_FAIL) {
                return OAL_FAIL;
            }
            hmac_nbw_resume_uslot_bitmap(curr_island->island_slot_info[link_idx].uslot_info.uslot_bitmap);
            curr_island->island_slot_info[link_idx].uslot_info = uslot_bitmap_info;
            hmac_nbw_set_available_uslot_bitmap(uslot_bitmap_info.uslot_bitmap);
            return OAL_SUCC;
        }
    }
    return OAL_FAIL;
}

static void hmac_nbw_slave_del_one_device(uint8_t *mac_addr, uint8_t *self_mac_addr)
{
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    uint8_t link_idx = hmac_nbw_find_slot_link_idx(slave_slot_info, mac_addr);
    if (link_idx == NBW_INVALID_IDX || oal_memcmp(mac_addr, self_mac_addr, OAL_MAC_ADDR_LEN) == 0) {
        return;
    }
    memset_s(&slave_slot_info[link_idx], sizeof(hmac_nbw_slot_info_stru), 0, sizeof(hmac_nbw_slot_info_stru));
    return;
}


uint8_t hmac_nbw_del_one_device_island_info(hmac_vap_stru *hmac_vap, uint8_t device_id)
{
    uint8_t ret = OAL_FALSE;
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    struct hi_node *delete_node = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    uint8_t island_bitmap;
    uint8_t slaveap_id_bitmap = 0;
    uint8_t work_mode = hmac_vap->st_vap_base_info.work_mode;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    oam_warning_log1(0, OAM_SF_CHBA, "{hmac_nbw_del_one_device_island_info::island_cnt[%d]", island_info->island_cnt);
    /* 获取本设备相关的所有岛主 */
    slaveap_id_bitmap = device_id_info[device_id].slaveap_id_bitmap;
    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if ((BIT(curr_island->owner_device_id) & slaveap_id_bitmap) != BIT(curr_island->owner_device_id)) {
            continue;
        }

        if (device_id == curr_island->owner_device_id) {
            /* 本设备相关是岛主， 清空时隙分配信息，删除岛域节点 */
            island_bitmap = hmac_nbw_get_island_uslot_bitmap(curr_island->island_slot_info);
            hmac_nbw_resume_uslot_bitmap(island_bitmap);
            delete_node = nbw_node;
            oam_warning_log1(0, OAM_SF_CHBA, "{hmac_nbw_del_one_device_island_info::del slaveap[%d]", device_id);
            ret = OAL_TRUE;
        } else {
            /* 失活机制仅管理与本身有直接连接的slave设备 */
            if (curr_island->owner_device_id != self_conn_info->self_device_id) {
                oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_del_one_device_island_info::slave has not connect");
                continue;
            }
            /* 本设备相关是普通设备， 删除链路 */
            hmac_nbw_clear_island_info(work_mode, curr_island->owner_device_id, device_id);
            ret = OAL_TRUE;
            oam_warning_log1(0, OAM_SF_CHBA, "{hmac_nbw_del_one_device_island_info::del slave[%d]", device_id);
        }
    }

    if (delete_node != NULL) {
        hmac_nbw_island_list_node_release(delete_node);
        island_info->island_cnt--;
    }
    /* 失活场景，在master清空某个岛主信息后，或者master/slaveap删除相关user时，需要重新计算工作时隙 */
    hmac_nbw_handle_timeslot_borrow(hmac_vap);
    return ret;
}
#ifdef _PRE_WLAN_NBW_DEMO
uint32_t hmac_nbw_set_mode_switch(mac_vap_stru *mac_vap, uint16_t len, uint8_t *params)
{
    mac_user_stru *mac_user = NULL;
    hmac_user_stru *hmac_user = NULL;
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *dlist_tmp = NULL;
    nbw_demo_pwr_switch_stru *nbw_pwr_switch = (nbw_demo_pwr_switch_stru *)params;
    hmac_nbw_mode_switch_notify_stru *nbw_mode_switch_info = hmac_get_nbw_mode_switch_info();
    if (mac_is_nbw_mode(mac_vap) == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_nbw_set_mode_switch:not nbw vap}");
        return OAL_FAIL;
    }
    /* 输入参数合法性校验 */
    if (nbw_pwr_switch == NULL || nbw_pwr_switch->pwr_flag > 1 || nbw_pwr_switch->band >= WLAN_BAND_BUTT ||
        nbw_pwr_switch->bw_mode > WLAN_BAND_WIDTH_160MINUSMINUSMINUS ||
        mac_is_channel_num_valid(WLAN_BAND_5G, nbw_pwr_switch->channel_num, OAL_FALSE) != OAL_SUCC) {
        return OAL_FAIL;
    }
    /* 切换请求定时器已经启动直接返回 */
    if (nbw_mode_switch_info->req_timer.en_is_registerd == OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_set_mode_switch::last mode switch not fiinish!");
        return OAL_SUCC;
    }
    nbw_mode_switch_info->channel_info.en_band = nbw_pwr_switch->band;
    nbw_mode_switch_info->channel_info.uc_chan_number = nbw_pwr_switch->channel_num;
    nbw_mode_switch_info->channel_info.en_bandwidth = nbw_pwr_switch->bw_mode;
    nbw_mode_switch_info->pwr_level = nbw_pwr_switch->pwr_flag;
    oal_dlist_search_for_each_safe(entry, dlist_tmp, &(mac_vap->st_mac_user_list_head)) {
        mac_user = oal_dlist_get_entry(entry, mac_user_stru, st_user_dlist);
        hmac_user = mac_res_get_hmac_user(mac_user->us_assoc_id);
        if ((hmac_user == NULL) || (mac_user_get_port(&hmac_user->st_user_base_info) == OAL_FALSE)) {
            continue;
        }
        hmac_nbw_start_mode_switch(hmac_user->st_user_base_info.auc_user_mac_addr);
        break;
    }
    return OAL_SUCC;
}

uint32_t hmac_nbw_set_pwr_switch(mac_vap_stru *mac_vap, uint16_t len, uint8_t *params)
{
    uint32_t ret;
    nbw_demo_pwr_switch_stru *nbw_pwr_switch = NULL;

    if (mac_is_nbw_mode(mac_vap) == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_nbw_set_pwr_switch:not nbw vap}");
        return OAL_FAIL;
    }
    nbw_pwr_switch = (nbw_demo_pwr_switch_stru *)params;
    /* 输入参数合法性校验 */
    if (nbw_pwr_switch == NULL || nbw_pwr_switch->pwr_flag > 1 || nbw_pwr_switch->band >= WLAN_BAND_BUTT ||
        nbw_pwr_switch->bw_mode > WLAN_BAND_WIDTH_160MINUSMINUSMINUS ||
        mac_is_channel_num_valid(WLAN_BAND_5G, nbw_pwr_switch->channel_num, OAL_FALSE) != OAL_SUCC) {
        return OAL_FAIL;
    }
    oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_CFG,
        "{hmac_nbw_set_pwr_switch: target_channel_num[%d], target_pwr_level[%d]}",
        nbw_pwr_switch->channel_num, nbw_pwr_switch->pwr_flag);
    /***************************************************************************
        抛事件到DMAC层处理
    ***************************************************************************/
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_NBW_SET_PWR_SWITCH, sizeof(nbw_demo_pwr_switch_stru),
        (uint8_t *)nbw_pwr_switch);
    if (ret != OAL_SUCC) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_nbw_set_pwr_switch:send fail[%d]}", ret);
    }
    return OAL_SUCC;
}
#endif


uint8_t hmac_nbw_get_dev_alive_dev_table(uint8_t work_mode, const uint8_t* mac_addr)
{
    uint8_t device_id;
    hmac_chba_hash_node_stru cmp;
    hmac_chba_hash_node_stru *nbw_node = NULL;
    struct hi_node *node = NULL;
    hmac_chba_alive_device_table_stru *ht = hmac_chba_get_alive_device_table(work_mode);

    /* 哈希表创建失败，直接返回 */
    if (oal_any_null_ptr2(mac_addr, ht)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_get_dev_alive_dev_table: null");
        return UINT8_INVALID_VALUE;
    }

    /* 输入地址全0，直接返回 */
    if (mac_addr_is_zero(mac_addr)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_get_dev_alive_dev_table: mac addr all zero");
        return UINT8_INVALID_VALUE;
    }

    /* 根据mac地址在活跃设备表中查找 */
    oal_set_mac_addr(cmp.mac_addr, mac_addr);
    node = hi_hash_find(&ht->raw, &cmp.node);
    /* 找到该设备，更新lastAliveTime */
    if (node == NULL) {
        return UINT8_INVALID_VALUE;
    }

    nbw_node = hi_node_entry(node, hmac_chba_hash_node_stru, node);
    nbw_node->last_alive_time = (uint32_t)oal_time_get_stamp_ms();
    device_id = nbw_node->device_id;
    return device_id;
}


static void hmac_nbw_master_slaveap_del_one_device(mac_vap_stru *mac_vap, chba_device_id_stru *device_rpt)
{
    hmac_vap_stru *hmac_vap = NULL;
    uint8_t device_id;
    uint8_t work_mode = mac_vap->work_mode;
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_nbw_master_slaveap_del_one_device::hmac_vap null.}");
        return;
    }
    if (oal_memcmp(device_rpt->mac_addr, mac_mib_get_StationID(mac_vap), OAL_MAC_ADDR_LEN) == 0) {
        return;
    }
    device_id = hmac_nbw_get_dev_alive_dev_table(work_mode, device_rpt->mac_addr);
    /* 找不到该设备，无节点待删除，返回 */
    if ((device_id >= MAC_CHBA_MAX_DEVICE_NUM) || device_id != device_rpt->device_id ||
        (device_id == self_conn_info->self_device_id)) {
        oam_warning_log3(0, OAM_SF_CHBA,
            "hmac_nbw_master_slaveap_del_one_device: device id check error, device_id[%d], rpt_id[%d], self_id[%d]",
            device_id, device_rpt->device_id, self_conn_info->self_device_id);
        return;
    }
    /* Master失活 */
    if (oal_memcmp(device_rpt->mac_addr, hmac_nbw_get_master_macaddr(), OAL_MAC_ADDR_LEN) == 0) {
        /* 目前测量信道只测当前工作信道，测量时间200ms */
        hmac_nbw_master_election_by_loss(hmac_vap);
        return;
    }
    if (hmac_nbw_del_one_device_island_info(hmac_vap, device_id) != OAL_TRUE) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_nbw_master_slaveap_del_one_device::no del.}");
        return;
    }
    hmac_chba_del_one_device_info(work_mode, device_id);
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
}


void hmac_nbw_del_non_alive_device(mac_vap_stru *mac_vap, chba_device_id_stru *device_rpt)
{
    uint8_t nbw_role = hmac_nbw_get_role();
    if (mac_vap == NULL || device_rpt == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_del_one_device_island_info::NULL");
        return;
    }
    oam_warning_log1(0, OAM_SF_CHBA, "{hmac_nbw_del_non_alive_device::del[%d]", device_rpt->device_id);
    if (mac_vap->work_mode != NBW_WORK_MODE) {
        oam_warning_log0(0, OAM_SF_CHBA, "{hmac_nbw_del_one_device_island_info::not nbw");
        return;
    }
    if (nbw_role == MAC_NBW_SLAVE_ROLE) {
        hmac_nbw_slave_del_one_device(device_rpt->mac_addr, mac_mib_get_StationID(mac_vap));
    } else if (nbw_role == MAC_NBW_SLAVEAP_ROLE || nbw_role == MAC_NBW_MASTER_ROLE) {
        hmac_nbw_master_slaveap_del_one_device(mac_vap, device_rpt);
    } else if (nbw_role == MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE) {
        hmac_nbw_master_slaveap_del_one_device(mac_vap, device_rpt);
        hmac_nbw_slave_del_one_device(device_rpt->mac_addr, mac_mib_get_StationID(mac_vap));
    }
}

void hmac_nbw_del_device_by_mac_addr(mac_vap_stru *mac_vap, uint8_t *mac_addr, uint8_t addr_len)
{
    chba_device_id_stru device_rpt;
    device_rpt.device_id = hmac_chba_one_dev_update_alive_dev_table(NBW_WORK_MODE, mac_addr);
    oal_set_mac_addr(device_rpt.mac_addr, mac_addr);
    hmac_nbw_del_non_alive_device(mac_vap, &device_rpt);
}
#endif