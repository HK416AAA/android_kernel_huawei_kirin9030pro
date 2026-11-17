/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw timeslot mgmt and schedule
 * Author: wifi
 * Create: 2024-12-26
 */
#include "oam_ext_if.h"
#include "mac_nbw_common.h"
#include "hmac_nbw_mgmt.h"
#include "hmac_nbw_timeslot_mgmt.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_TIMESLOT_MGMT_C
#ifdef _PRE_WLAN_FEATURE_NBW
hmac_nbw_timeslot_mgmt_stru g_nbw_timeslot_mgmt_info;
#ifdef _PRE_WLAN_NBW_DEMO
/* 07c上一个slot只有4个uslot，按照先分配第一个时隙，然后第三个时隙，之后第四个时隙，最后第二个时隙的顺序依次分配 */
uint8_t g_timeslot_compare_priority_level4[FOUR_LEVEL] = {0, 2, 3, 1};
#else
/* 08上一个slot有8个uslot，按照先配置第一个时隙，然后第五个，第七个，第三个，第四个，第八个，第六个，第二个的顺序完成分配 */
uint8_t g_timeslot_compare_priority_level8[EIGHT_LEVEL] = { 0, 4, 6, 2, 3, 7, 5, 1 };
#endif


void hmac_nbw_reset_timeslot_info(uint8_t work_mode)
{
    hmac_nbw_timeslot_mgmt_stru *timeslot_info = hmac_nbw_get_timeslot_mgmt_info();
    if (work_mode != NBW_WORK_MODE) {
        return;
    }

    memset_s(timeslot_info, sizeof(hmac_nbw_timeslot_mgmt_stru), 0, sizeof(hmac_nbw_timeslot_mgmt_stru));
}


void hmac_nbw_update_uslot_bitmap_for_link_disconnect(uint8_t val)
{
    uint8_t cur_timeslot_alloc = hmac_nbw_get_timeslot_alloced();
    if (cur_timeslot_alloc == OAL_FALSE) {
        return;
    }

    g_nbw_timeslot_mgmt_info.alloc_uslot_bitmap &= ~val;
#ifdef _PRE_WLAN_NBW_DEMO
    hmac_nbw_set_slot_bitmap(mac_nbw_uslot_bitmap_to_bitmap(g_nbw_timeslot_mgmt_info.alloc_uslot_bitmap));
#endif
}

/*
 * 功能描述  : 申请设置vap的bitmap，并且完成uint8->uint32的转化，方便配置固件
 * 日    期  : 2025年01月21日
 * 作    者 : y005000293
 */
void hmac_nbw_update_uslot_bitmap_for_slot_alloced(hmac_vap_stru *hmac_vap, hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t cur_timeslot_alloc, cur_slot_level;
    cur_timeslot_alloc = hmac_nbw_get_timeslot_alloced();
    /* 如果时隙没有分配过，则直接将本次bitmap进行配置 */
    /* 如果已经分配过，则与本次bitmap取或 */
    if (cur_timeslot_alloc == OAL_FALSE) {
        g_nbw_timeslot_mgmt_info.alloc_uslot_bitmap = timeslot_info.uslot_info.uslot_bitmap;
        hmac_nbw_set_timeslot_alloced(OAL_TRUE);
    } else {
        g_nbw_timeslot_mgmt_info.alloc_uslot_bitmap |= timeslot_info.uslot_info.uslot_bitmap;
    }
    cur_slot_level = hmac_nbw_get_new_slot_bitmap_level(&(hmac_vap->st_vap_base_info));
    hmac_nbw_set_work_uslot_bitmap(hmac_nbw_calc_all_links_work_uslot(
        g_nbw_timeslot_mgmt_info.alloc_uslot_bitmap, g_nbw_timeslot_mgmt_info.domain_alloc_bitmap));
#ifdef _PRE_WLAN_NBW_DEMO
    hmac_nbw_set_slot_bitmap(hmac_nbw_form_uslot_bitmap(cur_slot_level, hmac_nbw_get_work_uslot_bitmap()));
#else
    hmac_nbw_set_slot_level(cur_slot_level);
    hmac_nbw_set_cur_slot_bitmap(mac_nbw_level_to_slot_bitmap(hmac_nbw_get_slot_level()));
#endif
}

uint8_t hmac_nbw_timeslot_interval_transfrom(uint8_t timeslot_interval)
{
    uint8_t idx = 0, ans = 0;
    if (timeslot_interval >= MAC_NBW_USLOT_NUM)
        return INVALID_USLOT_BITMAP;
    for (; idx < timeslot_interval; idx++) {
        ans |= (1 << idx);
    }
    return ans;
}

uint8_t hmac_nbw_uslotbitmap_transform_timeinterval(uint8_t uslot_bitmap)
{
    uint8_t timeinterval_cnt = 0, idx = 0;
    for (; idx < EIGHT_LEVEL; idx++) {
        if (uslot_bitmap & (1 << idx))
            timeinterval_cnt++;
    }
    return timeinterval_cnt;
}
/*
 * 功能描述  : start_end_idx转化成uslot_bitmap, 8uslot一个repeat的转换公式
 * 日    期  : 2025年01月06日
 */
uint8_t hmac_nbw_convert_idx_to_uslotbitmap_level1(uint8_t start_idx, uint8_t end_idx)
{
    uint8_t uslotbitmap = 0;
    int idx;
#ifdef _PRE_WLAN_NBW_DEMO
    hmac_nbw_vap_stru *nbw_info = hmac_nbw_get_nbw_vap();
#endif
    if (end_idx < start_idx) {
        return INVALID_USLOT_BITMAP;
    }
    for (idx = start_idx; idx <= end_idx; idx++) {
        uslotbitmap |= (1 << idx);
    }
#ifdef _PRE_WLAN_NBW_DEMO
    if (nbw_info->timeslot_level == FOUR_LEVEL)
        uslotbitmap |= (uslotbitmap << BIT_OFFSET_4);
#endif
    return uslotbitmap;
}

/* 查找最高连续有效位（LSB）位置 */
static uint8_t find_consecutive_lsb_position(uint8_t num)
{
    uint8_t pos = 0;
    uint8_t last_lsb = 0;
    oal_bool_enum_uint8 flag = OAL_FALSE;
    while (num) {
        if (num & 0x1) {
            last_lsb = pos;
            flag = OAL_TRUE;
        } else if (flag == OAL_TRUE) {
            break;
        }
        num = num >> 1;
        pos++;
    }
    return last_lsb;
}

/*
 * 功能描述  : 根据全域已分配时隙，以及当前链路分配时隙，计算当前链路可借用时隙，无可借用时隙则直接返回uslot_bitmap
 * 日    期  : 2025年07月29日
 */
uint8_t hmac_nbw_calc_work_uslot(uint8_t link_alloc_uslot, uint8_t domain_alloc_uslot)
{
    uint8_t borrowed_mask = 0;
    uint8_t current_bit = 0;
#ifdef _PRE_WLAN_NBW_DEMO
    uint8_t max_pos = BIT_OFFSET_3;
#else
    uint8_t max_pos = BIT_OFFSET_7;
#endif
    /* 计算链路时隙的最高位位置 */
    uint8_t lsb = find_consecutive_lsb_position(link_alloc_uslot);
    if (lsb >= max_pos) { // 如果原始时隙的最高位已经是bit7（最高位），则不能借用
        return link_alloc_uslot;
    }
    /* 计算可借用时隙掩码：从lsb+1开始到bit7的连续空闲位 */
    current_bit = lsb + 1;
    /* 从lsb+1开始检查连续的空闲位，计算该链路可借用时隙 */
    while (current_bit <= max_pos) {
        uint8_t bit_mask = 1 << current_bit;
        if (domain_alloc_uslot & bit_mask) {
            break; // 遇到已占用位，停止检查
        }
        borrowed_mask |= bit_mask; // 将该位加入可借用掩码
        current_bit++;
    }
#ifdef _PRE_WLAN_NBW_DEMO
    borrowed_mask |= (borrowed_mask << BIT_OFFSET_4);
#endif
    return borrowed_mask | link_alloc_uslot;
}

/*
 * 功能描述  : 根据本设备所有链路的分配时隙合集和全域分配时隙，计算本设备所有链路的可借用时隙合集
 * 输入参数  :
 *      local_alloc_uslot  : 本设备所有链路的分配时隙合集
 *      domain_alloc_uslot : 全域的分配时隙
 * 返回值    : 本设备所有链路的可借用时隙合集
 * 日    期  : 2025年08月01日
 */
uint8_t hmac_nbw_calc_all_links_work_uslot(uint8_t local_alloc_uslot, uint8_t domain_alloc_uslot)
{
    uint8_t borrowed_uslot = 0;
    uint8_t link_alloc_uslot, bit_pos, link_borrowed;

    for (bit_pos = 0; bit_pos <= BIT_OFFSET_7; bit_pos++) {
        if ((local_alloc_uslot >> bit_pos) & 0x1) {
            // 提取单个链路的分配时隙
            link_alloc_uslot = (1 << bit_pos);
            // 计算该链路的可借用时隙
            link_borrowed = hmac_nbw_calc_work_uslot(link_alloc_uslot, domain_alloc_uslot);
            // 将该链路的借用时隙加入结果
            borrowed_uslot |= link_borrowed;
        }
    }

    return borrowed_uslot;
}

/*
 * 功能描述  : master根据实际情况计算出满足申请条件的bitmap, 第一版简化处理，先不考虑时隙借用和二分分配，只要有连续空闲时隙满足要求，就分配出去，后续可以优化算法
 * 日    期  : 2025年01月06日
 */
hmac_nbw_uslot_info_stru hmac_nbw_calculate_uslotbitmap(uint8_t timeslot_interval)
{
    uint8_t idx;
    uint8_t valid_flag = 0;
    hmac_nbw_uslot_info_stru uslot_info = { 0 };
    uint8_t cur_uslot_bitmap = hmac_nbw_get_available_uslot_bitmap();
    uint8_t timeslotneed_bitmap = hmac_nbw_timeslot_interval_transfrom(timeslot_interval);
    oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_calculate_uslotbitmap:: cur_uslot_bitmap:0x%x",
        cur_uslot_bitmap);
    if (cur_uslot_bitmap == FULL_USLOT_BITMAP || timeslotneed_bitmap == INVALID_USLOT_BITMAP) {
        oam_error_log0(0, OAM_SF_NBW,
                "hmac_nbw_calculate_uslotbitmap:: uslot bitmap unvalid");
        return uslot_info;
    }
    for (idx = 0; idx < MAC_NBW_USLOT_NUM - timeslot_interval + 1; idx++) {
        if ((cur_uslot_bitmap & (timeslotneed_bitmap << idx)) == 0) {
            valid_flag |= 1 << idx;
        }
    }
#ifdef _PRE_WLAN_NBW_DEMO
    for (idx = 0; idx < MAC_NBW_USLOT_NUM - timeslot_interval + 1; idx++) {
        if (valid_flag & (1 << g_timeslot_compare_priority_level4[idx])) {
            uslot_info.start_idx = g_timeslot_compare_priority_level4[idx];
            uslot_info.end_idx = g_timeslot_compare_priority_level4[idx] + timeslot_interval - 1;
            uslot_info.uslot_bitmap =
                hmac_nbw_convert_idx_to_uslotbitmap_level1(uslot_info.start_idx, uslot_info.end_idx);
            uslot_info.timeslot_interval = timeslot_interval;
            break;
        }
    }
#else
    for (idx = 0; idx < MAC_NBW_USLOT_NUM - timeslot_interval + 1; idx++) {
        if (valid_flag & (1 << g_timeslot_compare_priority_level8[idx])) {
            uslot_info.start_idx = g_timeslot_compare_priority_level8[idx];
            uslot_info.end_idx = g_timeslot_compare_priority_level8[idx] + timeslot_interval - 1;
            uslot_info.uslot_bitmap =
                hmac_nbw_convert_idx_to_uslotbitmap_level1(uslot_info.start_idx, uslot_info.end_idx);
            uslot_info.timeslot_interval = timeslot_interval;
            break;
        }
    }
#endif
    /* 根据全域分配时隙，计算该链路可借用时隙 */
    uslot_info.work_uslot_bitmap = hmac_nbw_calc_work_uslot(uslot_info.uslot_bitmap, cur_uslot_bitmap);
    oam_warning_log4(0, OAM_SF_NBW, "hmac_nbw_calculate_uslotbitmap:: start:%d, end:%d, bitmap:0x%x, work bitmap:0x%x",
        uslot_info.start_idx, uslot_info.end_idx, uslot_info.uslot_bitmap, uslot_info.work_uslot_bitmap);
    return uslot_info;
}

uint8_t hmac_get_user_uslot_bitmap(hmac_user_stru *hmac_user)
{
    uint8_t role = hmac_nbw_get_role();
    uint8_t link_idx;
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *current_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(NBW_WORK_MODE);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(NBW_WORK_MODE);
    hmac_nbw_slot_info_stru *slot_info = NULL;
    if (hmac_user == NULL) {
        oam_error_log0(0, 0, "{hmac_get_user_uslot_bitmap: ptr is NULL!}");
        return INVALID_USLOT_BITMAP;
    }
    if (role == MAC_NBW_SLAVE_ROLE) {
        slot_info = hmac_nbw_get_slave_slot_info();
    } else {
        hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
            island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
            current_island = &island_node->data;
            if (current_island->owner_device_id != self_conn_info->self_device_id)
                continue;
            slot_info = current_island->island_slot_info;
            break;
        }
    }
    if (slot_info == NULL) {
        return INVALID_USLOT_BITMAP;
    }
    link_idx = hmac_nbw_find_slot_link_idx(slot_info, hmac_user->st_user_base_info.auc_user_mac_addr);
    if (link_idx == NBW_INVALID_IDX) {
        oam_warning_log0(0, 0, "hmac_get_user_uslot_bitmap::link no exist");
        return INVALID_USLOT_BITMAP;
    }
    return slot_info[link_idx].uslot_info.uslot_bitmap;
}
#ifdef _PRE_WLAN_NBW_DEMO
uint32_t hmac_nbw_form_uslot_bitmap(uint8_t slot_level, uint8_t uslot_bitmap)
{
    uint8_t index = 0;
    uint32_t total_uslot_bitmap = 0;
    uint32_t slot_bitmap = mac_nbw_level_to_slot_bitmap(slot_level);
    for (; index < MAC_NBW_USLOT_NUM; index++) {
        if (slot_bitmap & (1 << index)) {
            total_uslot_bitmap |= (uslot_bitmap << (EIGHT_LEVEL * index));
        }
    }
    return total_uslot_bitmap;
}
#endif

uint8_t hmac_nbw_get_new_slot_bitmap_level(mac_vap_stru *mac_vap)
{
    mac_user_stru *mac_user = NULL;
    hmac_user_stru *hmac_user = NULL;
    hmac_chba_user_stru *nbw_user_info = NULL;
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *dlist_tmp = NULL;
    uint8_t cur_slot_bitmap_level = NBW_SLOT_BITMAP_LEVEL_BUTT;
    if (mac_vap == NULL) {
        return NBW_SLOT_BITMAP_LEVEL_BUTT;
    }
    if (oal_dlist_is_empty(&(mac_vap->st_mac_user_list_head)) == OAL_TRUE) {
        return NBW_SLOT_BITMAP_LEVEL_BUTT;
    }
    oal_dlist_search_for_each_safe(entry, dlist_tmp, &(mac_vap->st_mac_user_list_head)) {
        mac_user = oal_dlist_get_entry(entry, mac_user_stru, st_user_dlist);
        hmac_user = mac_res_get_hmac_user(mac_user->us_assoc_id);
        if ((hmac_user == NULL) || (mac_user_get_port(&hmac_user->st_user_base_info) == OAL_FALSE)) {
            continue;
        }
        nbw_user_info = &(hmac_user->chba_user);
        /* 取所有链路中最大的bitmap level作为本vap的level */
        if (nbw_user_info->nbw_user_slot_bitmap_level < cur_slot_bitmap_level)
            cur_slot_bitmap_level = nbw_user_info->nbw_user_slot_bitmap_level;
    }
    return cur_slot_bitmap_level;
}

/*
 * 功能描述  : 本设备清除当前设备分配的uslot_bitmap和全域已分配的工作时隙
 * 日    期  : 2025年01月06日
 */
void hmac_nbw_resume_timeslot_bitmap(hmac_nbw_uslot_info_stru uslot_info)
{
    hmac_nbw_resume_used_uslot_bitmap(uslot_info.uslot_bitmap);
    hmac_nbw_resume_uslot_bitmap(uslot_info.uslot_bitmap);
}

void hmac_nbw_set_available_uslot_bitmap(uint8_t val)
{
    g_nbw_timeslot_mgmt_info.domain_alloc_bitmap |= val;
}
#endif