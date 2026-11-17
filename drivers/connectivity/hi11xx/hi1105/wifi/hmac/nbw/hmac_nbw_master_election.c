/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025. All rights reserved.
 * Description: nbw frame encap and trx
 * Author: wifi
 * Create: 2025-04-23
 */
#include "hmac_nbw_master_election.h"
#include "hmac_user.h"
#include "hmac_nbw_frame.h"
#include "hmac_chba_mgmt.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_MASTER_ELECTION_C

#ifdef _PRE_WLAN_FEATURE_NBW

/* NBW黑名单 */
hmac_nbw_master_blacklist_stru g_nbw_master_election_blacklist;

static oal_bool_enum_uint8 hmac_nbw_blacklist_is_aged(hmac_nbw_master_blacklist_stru *blacklist,
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info)
{
    oal_time_us_stru cur_time;
    if (oal_any_null_ptr1(blacklist)) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_blacklist_is_aged::blacklist null!\r\n");
        return OAL_FALSE;
    }

    /* 1.1 全零地址，属于非法地址 */
    if (mac_addr_is_zero(blacklist_info->master_addr) == OAL_TRUE) {
        return OAL_FALSE;
    }

    /* 2.1 老化时间为0表示不需要老化 */
    if (blacklist_info->aging_time == 0) {
        return OAL_FALSE;
    }

    /* 2.2 没有超过老化时间 */
    oal_time_get_stamp_us(&cur_time);
    if (cur_time.i_sec < (signed long)(blacklist_info->update_time + blacklist_info->aging_time)) {
        return OAL_FALSE;
    }

    oam_warning_log3(0, OAM_SF_NBW,
        "NBW: hmac_nbw_blacklist_is_aged::aging time reach delete MAC:=%02X:XX:XX:XX:%02X:%02X}",
        blacklist_info->master_addr[0], blacklist_info->master_addr[MAC_ADDR_4],
        blacklist_info->master_addr[MAC_ADDR_5]);

    /* 3.1 超过老化时间，直接从黑名单中删除 */
    memset_s(blacklist_info, sizeof(hmac_nbw_per_master_blacklist_info_stru),
        0, sizeof(hmac_nbw_per_master_blacklist_info_stru));
    if (blacklist->master_his_cnt > 0) {
        blacklist->master_his_cnt--;
        oam_warning_log1(0, OAM_SF_NBW, "NBW: del from blacklist & num=%d}", blacklist->master_his_cnt);
    }

    return OAL_TRUE;
}

static hmac_nbw_per_master_blacklist_info_stru *hmac_nbw_blacklist_search_item(
    hmac_nbw_master_blacklist_stru *blacklist, const uint8_t *mac_addr)
{
    uint8_t blacklist_index;
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info = NULL;

    for (blacklist_index = 0; blacklist_index < NBW_MASTER_BLACKLIST_MAX; blacklist_index++) {
        blacklist_info = &blacklist->master_blacklist[blacklist_index];
        if (!oal_memcmp(blacklist_info->master_addr, mac_addr, OAL_MAC_ADDR_LEN)) {
            break;
        }
        blacklist_info = NULL;
    }
    return blacklist_info;
}

static hmac_nbw_per_master_blacklist_info_stru *hmac_nbw_blacklist_search_zero_item(
    hmac_nbw_master_blacklist_stru *blacklist)
{
    uint8_t blacklist_index;
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info = NULL;

    for (blacklist_index = 0; blacklist_index < WLAN_BLACKLIST_MAX; blacklist_index++) {
        blacklist_info = &blacklist->master_blacklist[blacklist_index];
        if (mac_addr_is_zero(blacklist_info->master_addr) == OAL_TRUE) {
            break;
        }
        blacklist_info = NULL;
    }

    return blacklist_info;
}

static uint32_t hmac_nbw_blacklist_update_form(uint8_t *mac_addr, hmac_nbw_master_blacklist_stru *blacklist,
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info, uint32_t aging_time)
{
    oal_time_us_stru cur_time;
    oal_time_get_stamp_us(&cur_time);

    if (memcpy_s(blacklist_info->master_addr, sizeof(blacklist_info->master_addr), mac_addr, OAL_MAC_ADDR_LEN) != EOK) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_blacklist_update_form::memcpy fail!");
        return OAL_FAIL;
    }
    blacklist_info->update_time = (uint32_t)cur_time.i_sec;
    blacklist_info->aging_time = aging_time;
    blacklist->master_his_cnt++;

    oam_warning_log3(0, OAM_SF_NBW, "NBW: hmac_nbw_blacklist_update_form:: src mac=%02X:XX:XX:XX:%02X:%02X.}",
        mac_addr[MAC_ADDR_0], mac_addr[MAC_ADDR_4], mac_addr[MAC_ADDR_5]);
    oam_warning_log2(0, OAM_SF_NBW, "NBW: hmac_nbw_blacklist_update_form:: new count is %d, time=%d}",
        blacklist->master_his_cnt, blacklist_info->update_time);
    return OAL_SUCC;
}

static void hmac_nbw_blacklist_update_by_aging(hmac_nbw_master_blacklist_stru *blacklist)
{
    uint8_t blacklist_index;
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info = NULL;

    for (blacklist_index = 0; blacklist_index < WLAN_BLACKLIST_MAX; blacklist_index++) {
        blacklist_info = &blacklist->master_blacklist[blacklist_index];
        if (mac_addr_is_zero(blacklist_info->master_addr) == OAL_TRUE) {
            continue;
        }

        hmac_nbw_blacklist_is_aged(blacklist, blacklist_info);
    }
}

/*
 * 功能描述  : 初始化master选举黑名单
 * 日    期  : 2025年04月25日
 */
void hmac_nbw_blacklist_init(void)
{
    hmac_nbw_master_blacklist_stru *blacklist_info = hmac_nbw_get_blacklist_mgmt();
    /* 默认使能黑名单功能 */
    blacklist_info->is_blacklist_en = NBW_BLACKLIST_MODE_ENABLE;
    /* 历史记录清零 */
    blacklist_info->master_his_cnt = 0;
    memset_s(blacklist_info->master_blacklist, sizeof(hmac_nbw_per_master_blacklist_info_stru) *
        NBW_MASTER_BLACKLIST_MAX, 0, sizeof(hmac_nbw_per_master_blacklist_info_stru) * NBW_MASTER_BLACKLIST_MAX);
}

/*
 * 功能描述  : 根据历史域主黑名单，过滤待选举的域主列表，返回TRUE则表示该域主在黑名单内，需要被过滤
 * 日    期  : 2025年04月25日
 */
oal_bool_enum_uint8 hmac_nbw_master_blacklist_filter(uint8_t *mac_addr)
{
    hmac_nbw_master_blacklist_stru *blacklist = NULL;
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info = NULL;
    oal_bool_enum_uint8 is_aged;

    /* 入参检查, mac地址为空，不做检查 */
    if (oal_any_null_ptr1(mac_addr)) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_blacklist_filter::null mac addr");
        return OAL_FALSE;
    }
    
    blacklist = hmac_nbw_get_blacklist_mgmt();
    /* 黑名单功能没有开启，不需要过滤 */
    if (blacklist->is_blacklist_en == NBW_BLACKLIST_MODE_NONE) {
        return OAL_FALSE;
    }

    /* 根据mac地址在黑名单表单中检索，如果检索到数据，则需要过滤 */
    blacklist_info = hmac_nbw_blacklist_search_item(blacklist, mac_addr);
    if (blacklist_info == NULL) {
        oam_warning_log3(0, OAM_SF_NBW,
            "NBW: hmac_nbw_master_blacklist_filter::there is no MAC=%02X:XX:XX:XX:%02X:%02X in blacklist",
            mac_addr[MAC_ADDR_0], mac_addr[MAC_ADDR_4], mac_addr[MAC_ADDR_5]);
        return OAL_FALSE;
    }

    /* 老化时间到了，不需要过滤 */
    is_aged = hmac_nbw_blacklist_is_aged(blacklist, blacklist_info);
    if (is_aged == OAL_TRUE) {
        return OAL_FALSE;
    }

    oam_warning_log3(0, OAM_SF_NBW, "NBW: hmac_nbw_master_blacklist_filter::filter MAC:=%02X:XX:XX:XX:%02X:%02X",
        mac_addr[MAC_ADDR_0], mac_addr[MAC_ADDR_4], mac_addr[MAC_ADDR_5]);

    return OAL_TRUE;
}

uint32_t hmac_nbw_blacklist_add(uint8_t *mac_addr, uint32_t aging_time)
{
    hmac_nbw_master_blacklist_stru *blacklist = hmac_nbw_get_blacklist_mgmt();
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info = NULL;

    /* 根据老化时间，先刷新一遍表单 */
    hmac_nbw_blacklist_update_by_aging(blacklist);

    /* 根据mac地址在黑名单列表内检索数据 */
    blacklist_info = hmac_nbw_blacklist_search_item(blacklist, mac_addr);
    /* 黑名单已经存在，则只更新老化时间 */
    if (blacklist_info != NULL) {
        oam_warning_log1(0, OAM_SF_NBW, "NBW: hmac_nbw_blacklist_add::blacklist_add allready exist. update aging = %d",
            aging_time);
        blacklist_info->aging_time = aging_time;
        return OAL_SUCC;
    }

    /* 找一个地址为空的表单 */
    blacklist_info = hmac_nbw_blacklist_search_zero_item(blacklist);
    /* 无可用表单, 说明当前黑名单列表内数据已达最大值，理论上不会遇到 */
    if (blacklist_info == NULL) {
        oam_warning_log4(0, OAM_SF_NBW, "NBW: hmac_nbw_blacklist_add:: src mac=%02X:XX:XX:XX:%02X:%02X. count is %d;"
            "full count}", mac_addr[MAC_ADDR_0], mac_addr[MAC_ADDR_4], mac_addr[MAC_ADDR_5], blacklist->master_his_cnt);
        return OAL_ERR_CODE_SECURITY_LIST_FULL;
    }

    /* 向空表单更新数据 */
    return hmac_nbw_blacklist_update_form(mac_addr, blacklist, blacklist_info, aging_time);
}

uint32_t hmac_nbw_blacklist_del(uint8_t *mac_addr)
{
    hmac_nbw_per_master_blacklist_info_stru *blacklist_info = NULL;
    hmac_nbw_master_blacklist_stru *blacklist = NULL;

    blacklist = hmac_nbw_get_blacklist_mgmt();

    blacklist_info = hmac_nbw_blacklist_search_item(blacklist, mac_addr);
    /* 如果找不到表单，直接返回 */
    if (blacklist_info == NULL) {
        oam_warning_log3(0, OAM_SF_NBW,
            "NBW: hmac_nbw_blacklist_del:: didn't find this mac: %02X:XX:XX:XX:%02X:%02X}",
            mac_addr[MAC_ADDR_0], mac_addr[MAC_ADDR_4], mac_addr[MAC_ADDR_5]);
            return OAL_SUCC;
    }

    /* 如果找到表单，则删除 */
    memset_s(blacklist_info, sizeof(hmac_nbw_per_master_blacklist_info_stru),
        0, sizeof(hmac_nbw_per_master_blacklist_info_stru));
    if (blacklist->master_his_cnt > 0) blacklist->master_his_cnt--;
    oam_warning_log4(0, OAM_SF_NBW,
        "NBW: hmac_nbw_blacklist_del::mac=%02X:XX:XX:XX:%02X:%02X. list_num[%d]}",
        mac_addr[MAC_ADDR_0], mac_addr[MAC_ADDR_4], mac_addr[MAC_ADDR_5], blacklist->master_his_cnt);

    return OAL_SUCC;
}

static oal_bool_enum_uint8 hmac_nbw_is_belong_to_island_by_mac(uint8_t *mac_addr)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_lnfo = hmac_chba_get_island_list(NBW_WORK_MODE);
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(NBW_WORK_MODE);

    hi_list_for_each_safe(nbw_node, tmp, &island_lnfo->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (oal_memcmp(device_id_info[curr_island->owner_device_id].mac_addr, mac_addr, OAL_MAC_ADDR_LEN) == 0) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE;
}

static oal_bool_enum_uint8 hmac_nbw_master_lost_condition_check(hmac_nbw_chan_domain_info_stru *domain_info)
{
    // 判断收到的beacon设备是否是属于原域内的设备, rssi是否满足不在此处判断
    return hmac_nbw_is_belong_to_island_by_mac(domain_info->master_addr);
}

static uint8_t nbw_get_used_timeslot_count(uint8_t n)
{
    n = (n & 0x55) + ((n >> 1) & 0x55);  // 每2位统计1的个数
    n = (n & 0x33) + ((n >> 2) & 0x33);  // 每4位统计1的个数
    n = (n & 0x0F) + ((n >> 4) & 0x0F);  // 合并为8位结果
    return n;
}

static uint8_t nbw_get_available_timeslot_count(uint8_t n)
{
    return NBW_NBW_USLOT_NUM_FIX - nbw_get_used_timeslot_count(n);
}

static oal_bool_enum_uint8 hmac_nbw_check_master_timeslot(hmac_nbw_chan_domain_info_stru *domain_info)
{
    /* 目的域占用时隙 */
    uint8_t dst_used_timeslot_count = nbw_get_used_timeslot_count(domain_info->alloc_uslot_bitmap);
    /* 本岛（单岛或群岛）占用的时隙, TDO，当前仅获取本设备的使用时隙，只对单岛场景生效 */
    uint8_t src_used_timeslot_count = nbw_get_used_timeslot_count(hmac_nbw_get_used_uslot_bitmap());
    if (dst_used_timeslot_count + src_used_timeslot_count > NBW_NBW_USLOT_NUM_FIX) {
        return OAL_TRUE;
    }
    return OAL_FALSE;
}

static oal_bool_enum_uint8 hmac_nbw_check_is_match_election_condition(hmac_nbw_chan_domain_info_stru *domain_info,
    hmac_nbw_master_election_mgmt_stru *election_list)
{
    if (oal_any_null_ptr1(domain_info)) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: mac_nbw_check_is_match_election_condition::input param err.");
        return OAL_FALSE;
    }

    oam_warning_log3(0, OAM_SF_NBW, "NBW: mac_nbw_check_is_match_election_condition::check candidate:"
        "addr %02X:XX:XX:XX:%02X:%02X", domain_info->master_addr[MAC_ADDR_0], domain_info->master_addr[MAC_ADDR_4],
        domain_info->master_addr[MAC_ADDR_5]);

    // 如果是master loss丢失场景触发的选举，需要过滤掉非本域的master
    if (election_list->election_type == TRIGGER_BY_MASTER_LOSS) {
        if (hmac_nbw_master_lost_condition_check(domain_info) == OAL_FALSE) {
            oam_warning_log0(0, OAM_SF_NBW, "NBW: mac_nbw_check_is_match_election_condition::not local island");
            return OAL_FALSE;
        }
    }

    // 过滤Rssi强度小于特定阈值的master
    if (hmac_nbw_rssi_to_signal_level(domain_info->master_rssi, WLAN_BAND_5G) < NBW_MASTER_ELECTION_SELECT_RSSI_LEVEL) {
        oam_warning_log1(0, OAM_SF_NBW, "NBW: mac_nbw_check_is_match_election_condition::"
            "rssi lower than threshold, rssi:%d", domain_info->master_rssi);
        return OAL_FALSE;
    }

    // 过滤在黑名单内的master
    if (hmac_nbw_master_blacklist_filter(domain_info->master_addr) == OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: mac_nbw_check_is_match_election_condition::in history blacklist");
        return OAL_FALSE;
    }

    // 过滤目的域已分配时隙 + 本岛时隙 > 8
    if (hmac_nbw_check_master_timeslot(domain_info) == OAL_TRUE) {
        oam_warning_log1(0, OAM_SF_NBW, "NBW: mac_nbw_check_is_match_election_condition::dst timeslot[%d]",
            domain_info->alloc_uslot_bitmap);
        return OAL_FALSE;
    }

    oam_warning_log0(0, OAM_SF_NBW, "NBW: mac_nbw_check_is_match_election_condition::check pass");
    return OAL_TRUE;
}

static uint8_t hmac_nbw_count_valid_candidate(hmac_nbw_chan_measure_res_stru *measure_res,
    hmac_nbw_master_election_mgmt_stru *election_list)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_nbw_chan_domain_info_stru *domain_info = NULL;
    hmac_nbw_domain_list_node_stru *domain_list_node = NULL;
    uint8_t count = 0;

    hi_list_for_each_safe(nbw_node, tmp, &measure_res->domain_list) {
        domain_list_node = hi_node_entry(nbw_node, hmac_nbw_domain_list_node_stru, node);
        domain_info = &domain_list_node->data;
        if (hmac_nbw_check_is_match_election_condition(domain_info, election_list) == OAL_TRUE) {
            count++;
        }
    }

    return count;
}

static void hmac_nbw_create_filterd_election_array(uint8_t count, hmac_nbw_master_election_mgmt_stru *election_list)
{
    election_list->master_election_list =
        (election_master_info_stru *)oal_memalloc(count * sizeof(election_master_info_stru));
    if (election_list->master_election_list == NULL) {
        return;
    }
    memset_s(election_list->master_election_list, count * sizeof(election_master_info_stru),
        0, count * sizeof(election_master_info_stru));
    election_list->master_election_cnt = count;
}

static void hmac_nbw_fill_candidate_content(election_master_info_stru *election_list,
    hmac_nbw_chan_domain_info_stru *domain_info, int index)
{
    int32_t ret;
    election_list[index].rssi_level = hmac_nbw_rssi_to_signal_level(domain_info->master_rssi, WLAN_BAND_5G);
    election_list[index].alloc_uslot_bitmap = domain_info->alloc_uslot_bitmap;
    ret = memcpy_s(election_list[index].master_addr, sizeof(uint8_t) * OAL_MAC_ADDR_LEN,
        domain_info->master_addr, sizeof(uint8_t) * OAL_MAC_ADDR_LEN);
    if (ret != 0) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_fill_candidate_content::memcpy_s fail");
        return;
    }
    if (oal_compare_mac_addr(domain_info->master_addr, hmac_nbw_get_master_macaddr()) == 0) {
        election_list[index].is_local_master = TRUE;
    }
}

static void hmac_nbw_fill_filterd_candidate(hmac_nbw_chan_measure_res_stru *measure_res,
    hmac_nbw_master_election_mgmt_stru *election_list)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_nbw_chan_domain_info_stru *domain_info = NULL;
    hmac_nbw_domain_list_node_stru *domain_list_node = NULL;
    uint8_t index = 0;

    hi_list_for_each_safe(nbw_node, tmp, &measure_res->domain_list) {
        domain_list_node = hi_node_entry(nbw_node, hmac_nbw_domain_list_node_stru, node);
        domain_info = &domain_list_node->data;
        if (hmac_nbw_check_is_match_election_condition(domain_info, election_list) &&
            index < election_list->master_election_cnt) {
            hmac_nbw_fill_candidate_content(election_list->master_election_list, domain_info, index);
            index++;
        }
    }
}

static void hmac_nbw_get_election_list_by_measure_result(hmac_nbw_chan_measure_res_stru *measure_res,
    hmac_nbw_master_election_mgmt_stru *election_list)
{
    uint8_t candidate_count = 0;
    uint8_t domain_cnt = measure_res->domain_cnt;
    if (domain_cnt <= 0) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_get_election_list_by_measure_result::no measure result");
        return;
    }

    /* 计算有效的候选者个数 */
    candidate_count = hmac_nbw_count_valid_candidate(measure_res, election_list);
    if (candidate_count <= 0) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_get_election_list_by_measure_result::no suitable candidate");
        return;
    }

    /* 分配候选域数组内存 */
    hmac_nbw_create_filterd_election_array(candidate_count, election_list);
    if (election_list->master_election_list == NULL) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_get_election_list_by_measure_result::memcpy err");
        return;
    }

    /* 将筛选的候选域master加入到数组内 */
    hmac_nbw_fill_filterd_candidate(measure_res, election_list);
}

/*
 * 功能描述  : 从测量结果中获取待选举的域主信息列表
 * 日    期  : 2025年04月25日
 */
uint32_t hmac_nbw_get_master_election_list(hmac_nbw_chan_measure_res_stru *measure_res,
    hmac_nbw_master_election_mgmt_stru *election_list)
{
    /* 检查信道测量结果内是否存在当前信道信息 */

    /* 检测信道测量结果是否在有效期内 */

    /* 将测量结果转换为选举列表 */
    hmac_nbw_get_election_list_by_measure_result(measure_res, election_list);

    return OAL_SUCC;
}

/*
 * 功能描述  : RP值比较，如果第一个设备rp值较大或者相同返回TRUE，否则返回FALSE
 * 日    期  : 2021年03月01日
 * 作    者  : wifi
 */
int hmac_nbw_dev_rp_compare(const nbw_ranking_priority rp1, const nbw_ranking_priority rp2,
    const uint8_t *addr1, const uint8_t *addr2)
{
    uint8_t device_level1, device_level2;
    int32_t value;

    /* 比较device level */
    device_level1 = (uint8_t)rp1.device_level.value;
    device_level2 = (uint8_t)rp2.device_level.value;
    if (device_level1 != device_level2) {
        int result = (device_level1 > device_level2) ? 1 : -1;
        oam_warning_log2(0, OAM_SF_NBW,
            "hmac_nbw_dev_rp_compare::device level1[%d], device level2[%d].", device_level1, device_level2);
        return result;
    }

    /* 比较NBW 版本号，复用CHBA版本号 */
    if (rp1.chba_version != rp2.chba_version) {
        int result = (rp1.chba_version > rp2.chba_version) ? 1 : -1;
        oam_warning_log2(0, OAM_SF_CHBA, "hmac_chba_sync_dev_rp_compare::rp1 chba_version[%d], rp2 chba_version[%d].",
            rp1.chba_version, rp2.chba_version);
        return result;
    }

    /* 比较mac地址 */
    value = oal_memcmp(addr1, addr2, OAL_MAC_ADDR_LEN);
    oam_warning_log3(0, OAM_SF_CHBA, "hmac_chba_sync_dev_rp_compare::mac address [%x] vs [%x] value[%d].",
        addr1[MAC_ADDR_5], addr2[MAC_ADDR_5], value);
    if (value > 0) {
        return 1;
    } else if (value < 0) {
        return -1;
    } else {
        return 0;
    }
}

static int compare_by_timeslot_and_rp(const void *a, const void *b)
{
    const election_master_info_stru *masterA = (const election_master_info_stru *)a;
    const election_master_info_stru *masterB = (const election_master_info_stru *)b;
    uint8_t master_a_avail_timeslot = nbw_get_available_timeslot_count(masterA->alloc_uslot_bitmap);
    uint8_t master_b_avail_timeslot = nbw_get_available_timeslot_count(masterB->alloc_uslot_bitmap);
    // 首先按 空闲时隙个数 降序排序
    if (master_a_avail_timeslot > master_b_avail_timeslot) {
        return -1;
    } else if (master_a_avail_timeslot < master_b_avail_timeslot) {
        return 1;
    } else {
        // 当 空闲时隙 相同时，按 rp 降序排序
        int cmp = hmac_nbw_dev_rp_compare(masterA->rp, masterB->rp, masterA->master_addr, masterB->master_addr);
        return -cmp;
    }
}

static int compare_by_rssi_and_rp(const void *a, const void *b)
{
    const election_master_info_stru *masterA = (const election_master_info_stru *)a;
    const election_master_info_stru *masterB = (const election_master_info_stru *)b;

    // 首先按 rssi 降序排序
    if (masterA->rssi_level > masterB->rssi_level) {
        return -1;
    } else if (masterA->rssi_level < masterB->rssi_level) {
        return 1;
    } else {
        // 当 rssi 相同时，按 rp 降序排序
        int cmp = hmac_nbw_dev_rp_compare(masterA->rp, masterB->rp, masterA->master_addr, masterB->master_addr);
        return -cmp;
    }
}

static void hmac_nbw_get_local_master_info_by_election_list(hmac_nbw_master_election_mgmt_stru *election_list,
    election_master_info_stru *local_master_info)
{
    uint8_t index = 0;
    if (oal_any_null_ptr1(election_list->master_election_list)) {
        return;
    }

    for (index = 0; index < election_list->master_election_cnt; index++) {
        if (election_list->master_election_list[index].is_local_master == TRUE) {
            *local_master_info = election_list->master_election_list[index];
            return;
        }
    }
}

static oal_bool_enum_uint8 nbw_match_timeslot_condiation(election_master_info_stru *c,
    election_master_info_stru *local_master)
{
    /* 目的域的空闲时隙 */
    uint8_t dst_avail_timeslot_count = nbw_get_available_timeslot_count(c->alloc_uslot_bitmap);
    /* 本岛（单岛或群岛）占用的时隙, TDO，当前仅获取本设备的使用时隙，只对单岛场景生效 */
    uint8_t src_used_timeslot_count = nbw_get_used_timeslot_count(hmac_nbw_get_used_uslot_bitmap());
    /* 本岛所在域的空闲时隙 */
    uint8_t src_avail_timeslot_count = nbw_get_available_timeslot_count(local_master->alloc_uslot_bitmap);
    /* 目的域空闲时隙 - 本岛已占用时隙 >= 本岛所在域空闲时隙 + 本岛已占用时隙 */
    if (dst_avail_timeslot_count - src_used_timeslot_count >= src_avail_timeslot_count + src_used_timeslot_count) {
        return OAL_TRUE;
    } else {
        /* 目的域空闲时隙 - 本岛已占用时隙 < 本岛空闲时隙 + 本岛已占用时隙 &&
            原域空闲时隙 < 目的域空闲时隙 && 原域RP < 目的域RP */
        /* TDO::暂时不切,根据仿真结果后再确认 */
    }
    return OAL_FALSE;
}

static void hmac_nbw_master_election_temp_list_count(hmac_nbw_master_election_mgmt_stru *election_list,
    election_master_info_stru *local_master, int *count_by_rssi, int *count_by_timeslot)
{
    uint8_t i = 0;
    for (i = 0; i < election_list->master_election_cnt; i++) {
        election_master_info_stru *c = &election_list->master_election_list[i];
        if (c->is_local_master) continue;

        if (c->rssi_level > local_master->rssi_level) {
            oam_warning_log4(0, OAM_SF_NBW, "{hmac_nbw_master_election_temp_list_count:"
                "rssi candidate mac[%02x:XX:XX:XX:XX:%02x], dst rssi[%d], src rssi[%d]}",
                c->master_addr[MAC_ADDR_0], c->master_addr[MAC_ADDR_5], c->rssi_level, local_master->rssi_level);
            (*count_by_rssi)++;
        } else if (c->rssi_level == local_master->rssi_level && nbw_match_timeslot_condiation(c, local_master) &&
            election_list->election_type != TRIGGER_BY_MASTER_LOSS) {
            /* master loss丢失场景，一定存在rssin > rssi0的情况，不需要再判断时隙情况 */
            oam_warning_log4(0, OAM_SF_NBW, "{hmac_nbw_master_election_temp_list_count:timeslot candidate"
                "mac[%02x:XX:XX:XX:XX:%02x], dst timeslot[%02x], src timeslot[%02x]}", c->master_addr[MAC_ADDR_0],
                c->master_addr[MAC_ADDR_5], c->alloc_uslot_bitmap, local_master->alloc_uslot_bitmap);
            (*count_by_timeslot)++;
        }
    }
}

static uint32_t hmac_nbw_master_election_temp_list_alloc(election_master_info_stru **list_by_rssi,
    election_master_info_stru **list_by_timeslot, int countA, int countB)
{
    if (countA > 0) {
        *list_by_rssi = oal_memalloc(countA * sizeof(**list_by_rssi));
        if (*list_by_rssi == NULL) {
            oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_temp_list_alloc::alloc fail.");
            return OAL_FAIL;
        }
    }
    if (countB > 0) {
        *list_by_timeslot = oal_memalloc(countB * sizeof(**list_by_timeslot));
        if (*list_by_timeslot == NULL) {
            if (*list_by_rssi != NULL) {
                oal_free(list_by_rssi);
            }
            oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_temp_list_alloc::alloc fail.");
            return OAL_FAIL;
        }
    }
    return OAL_SUCC;
}

static void hmac_nbw_master_election_temp_list_fill(hmac_nbw_master_election_mgmt_stru *election_list,
    election_master_info_stru *local_master, election_master_info_stru *list_by_rssi,
    election_master_info_stru *list_by_timeslot)
{
    int i = 0, idxA = 0, idxB = 0;
    for (i = 0; i < election_list->master_election_cnt; i++) {
        election_master_info_stru *c = &election_list->master_election_list[i];
        if (c->is_local_master) continue;

        if (c->rssi_level > local_master->rssi_level) {
            list_by_rssi[idxA++] = *c;
        } else if (c->rssi_level == local_master->rssi_level && nbw_match_timeslot_condiation(c, local_master)) {
            list_by_timeslot[idxB++] = *c;
        }
    }
}

// 交换两个元素（按字节操作）
static void my_swap(void *a, void *b, int size)
{
    char *tmp = oal_memalloc(size);
    memcpy_s(tmp, size, a, size);
    memcpy_s(a, size, b, size);
    memcpy_s(b, size, tmp, size);
    oal_free(tmp);
}

// 三数取中法选择基准值
static void* median_of_three(void *a, void *b, void *c, int (*cmp)(const void*, const void*))
{
    return cmp(a, b) < 0 ? (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a)) :
           (cmp(a, c) < 0 ? a : (cmp(b, c) < 0 ? c : b));
}

// 分区函数（Hoare分区方案）
static int partition(void *base, int low, int high, int size, int (*cmp)(const void*, const void*))
{
    char *arr = (char*)base;
    void *pivot = median_of_three(arr+low*size, arr+high*size, arr+(low+high)/2*size, cmp);
    
    int i = low - 1, j = high + 1;
    while (1) {
        do { i++; } while (cmp(arr+i*size, pivot) < 0);
        do { j--; } while (cmp(arr+j*size, pivot) > 0);
        if (i >= j) return j;
        my_swap(arr+i*size, arr+j*size, size);
    }
}

// 递归快速排序主体
static void qsort_impl(void *base, int low, int high, int size, int (*cmp)(const void*, const void*))
{
    if (low < high) {
        int pi = partition(base, low, high, size, cmp);
        qsort_impl(base, low, pi, size, cmp);
        qsort_impl(base, pi+1, high, size, cmp);
    }
}

/*
 * 功能描述  : hmac qsort对外接口（标准stdlib库qsort形式）
 * 日    期  : 2025年04月25日
 */
void hmac_qsort(void *base, int nmemb, int size, int (*cmp)(const void*, const void*))
{
    if (oal_any_null_ptr1(base)) {
        return;
    }
    qsort_impl(base, 0, nmemb-1, size, cmp);
}

static void hmac_nbw_master_election_temp_list_order(election_master_info_stru *list_by_rssi,
    election_master_info_stru *list_by_timeslot, int countA, int countB)
{
    if (countA > 0) hmac_qsort(list_by_rssi, countA, sizeof(*list_by_rssi), compare_by_rssi_and_rp);
    if (countB > 0) hmac_qsort(list_by_timeslot, countB, sizeof(*list_by_timeslot), compare_by_timeslot_and_rp);
}

static void hmac_nbw_master_election_temp_list_merge(hmac_nbw_master_election_result_info_stru *result,
    election_master_info_stru *list_by_rssi, election_master_info_stru *list_by_timeslot,
    int countA, int countB)
{
    int total = countA + countB;
    if (total > 0) {
        result->master_election_result_list = oal_memalloc(total * sizeof(*result->master_election_result_list));
        if (result->master_election_result_list == NULL) {
            oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_temp_list_merge::alloc mem fail.");
            return;
        }
        result->master_election_result_cnt = total;

        if (countA > 0) memcpy_s(result->master_election_result_list,
            total * sizeof(*result->master_election_result_list), list_by_rssi, countA * sizeof(*list_by_rssi));
        if (countB > 0) memcpy_s(result->master_election_result_list + countA,
            total * sizeof(*result->master_election_result_list) - countA * sizeof(*list_by_rssi),
            list_by_timeslot, countB * sizeof(*list_by_timeslot));
    }
}

static void hmac_nbw_filter_master_election_result(hmac_nbw_master_election_mgmt_stru *election_list,
    hmac_nbw_master_election_result_info_stru *result, election_master_info_stru *local_master)
{
    election_master_info_stru *list_by_rssi = NULL;
    election_master_info_stru *list_by_timeslot = NULL;
    int countA = 0, countB = 0;
    if (oal_any_null_ptr1(election_list->master_election_list)) {
        return;
    }

    /* 1、遍历列表，筛选出rssi大于本域master rssi以及rssi等于本域master rssi的两个临时数组 */
    hmac_nbw_master_election_temp_list_count(election_list, local_master, &countA, &countB);
    if (countA == 0 && countB == 0) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_filter_master_election_result::no suitable master found.");
        return;
    }

    /* 2、根据筛选结果给临时数组分配内存 */
    if (hmac_nbw_master_election_temp_list_alloc(&list_by_rssi, &list_by_timeslot, countA, countB) != OAL_SUCC) {
        return;
    }

    /* 3、根据rssi和timeslot对比规则向临时数组内填充数据 */
    hmac_nbw_master_election_temp_list_fill(election_list, local_master, list_by_rssi, list_by_timeslot);

    /* 4、将list_by_rssi按rssi和rp值排序，将list_by_timeslot按时隙情况和rp值排序 */
    hmac_nbw_master_election_temp_list_order(list_by_rssi, list_by_timeslot, countA, countB);

    /* 5、将临时数据合并且到返回结果内 */
    hmac_nbw_master_election_temp_list_merge(result, list_by_rssi, list_by_timeslot, countA, countB);

    /* 6、清理临时内存 */
    oal_free(list_by_rssi);
    oal_free(list_by_timeslot);
}

/*
 * 功能描述  : slaveAP触发的master选举, election_list候选者列表内的master候选者均已满足前置切换条件
 * 日    期  : 2025年04月25日
 */
void hmac_nbw_master_election_trigger_by_slaveap(hmac_nbw_master_election_mgmt_stru *election_list,
    hmac_nbw_master_election_result_info_stru *result)
{
    election_master_info_stru local_master = { 0 };
    /* 1、查找本域master信息 */
    hmac_nbw_get_local_master_info_by_election_list(election_list, &local_master);

    /* 2、筛选出符合条件的候选 */
    hmac_nbw_filter_master_election_result(election_list, result, &local_master);
}

static int compare_by_timeslot_and_rssi(const void *a, const void *b)
{
    const election_master_info_stru *masterA = (const election_master_info_stru *)a;
    const election_master_info_stru *masterB = (const election_master_info_stru *)b;
    uint8_t master_a_avail_timeslot = nbw_get_available_timeslot_count(masterA->alloc_uslot_bitmap);
    uint8_t master_b_avail_timeslot = nbw_get_available_timeslot_count(masterB->alloc_uslot_bitmap);
    // 按 空闲时隙个数 降序排序
    if (master_a_avail_timeslot > master_b_avail_timeslot) {
        return -1;
    } else if (master_a_avail_timeslot < master_b_avail_timeslot) {
        return 1;
    } else {
        if (masterA->rssi_level > masterB->rssi_level) {
            return -1;
        } else if (masterA->rssi_level < masterB->rssi_level) {
            return 1;
        } else {
            // 当 rssi 相同时，按 rp 降序排序
            int cmp = hmac_nbw_dev_rp_compare(masterA->rp, masterB->rp, masterA->master_addr, masterB->master_addr);
            return -cmp;
        }
    }
}

static void election_list_order_by_timeslot_and_rssi(hmac_nbw_master_election_mgmt_stru *election_list)
{
    hmac_qsort(election_list->master_election_list, election_list->master_election_cnt,
        sizeof(*election_list->master_election_list), compare_by_timeslot_and_rssi);
}

static void election_list_count_by_master(hmac_nbw_master_election_mgmt_stru *election_list,
    election_master_info_stru *local_master, int *count)
{
    uint8_t i;
    for (i = 0; i < election_list->master_election_cnt; i++) {
        election_master_info_stru *c = &election_list->master_election_list[i];

        if (nbw_match_timeslot_condiation(c, local_master)) {
            (*count)++;
        }
    }
}

static void election_result_list_alloc(hmac_nbw_master_election_result_info_stru *result, int count)
{
    result->master_election_result_list = oal_memalloc(count * sizeof(*result->master_election_result_list));
    if (result->master_election_result_list == NULL) {
        return;
    }
    result->master_election_result_cnt = count;
}

static void election_list_fill_result(hmac_nbw_master_election_mgmt_stru *election_list,
    election_master_info_stru *local_master, hmac_nbw_master_election_result_info_stru *result)
{
    uint8_t i;
    for (i = 0; i < election_list->master_election_cnt; i++) {
        election_master_info_stru *c = &election_list->master_election_list[i];

        if (nbw_match_timeslot_condiation(c, local_master)) {
            memcpy_s(&(result->master_election_result_list[i]), sizeof(result->master_election_result_list[i]),
                c, sizeof(election_master_info_stru));
        }
    }
}

static void election_result_fill_master_self(hmac_nbw_master_election_result_info_stru *result)
{
    result->is_island_owner_master = TRUE;
    result->master_election_result_cnt = 0;
}

static void fill_local_master_info(election_master_info_stru *local_master)
{
    memcpy_s(&local_master->rp, sizeof(nbw_ranking_priority), hmac_nbw_sync_get_rp_info(),
        sizeof(nbw_ranking_priority));
    oal_set_mac_addr(local_master->master_addr, hmac_nbw_get_master_macaddr());
    local_master->alloc_uslot_bitmap = hmac_nbw_get_available_uslot_bitmap(); // 本域已分配的工作时隙
    local_master->is_local_master = TRUE;
}

/*
 * 功能描述  : master触发的master选举, election_list候选者列表内的master候选者均已满足前置切换条件
 * 日    期  : 2025年04月25日
 */
void hmac_nbw_master_election_trigger_by_master(hmac_nbw_master_election_mgmt_stru *election_list,
    hmac_nbw_master_election_result_info_stru *result)
{
    int count = 0;
    election_master_info_stru local_master = { 0 };

    /* 获取本域时隙信息以及rp信息 */
    fill_local_master_info(&local_master);

    /* election_list 按时隙空闲从多到少排序, 当时隙相等时按RSSI排序, 当RSSI相等时，按RP排序 */
    election_list_order_by_timeslot_and_rssi(election_list);

    /* 遍历election_list，筛选符合规则的候选master个数 */
    election_list_count_by_master(election_list, &local_master, &count);
    if (count == 0) {
        election_result_fill_master_self(result);
        return;
    }

    /* 分配内存 */
    election_result_list_alloc(result, count);
    if (result->master_election_result_cnt == 0) {
        election_result_fill_master_self(result);
        return;
    }

    /* 遍历列表，将数据放入result内 */
    election_list_fill_result(election_list, &local_master, result);
}

/*
 * 功能描述  : 干扰触发的域主选举，从传入的候选master列表中，选择出最优的master
 * 日    期  : 2025年04月25日
 */
uint32_t hmac_nbw_master_election_trigger_by_measure(hmac_nbw_chan_measure_res_stru *measure_res,
    nbw_master_election_scene_enum election_type, hmac_nbw_master_election_result_info_stru *result_list_by_priority)
{
    uint32_t ret;
    hmac_nbw_master_election_mgmt_stru election_list = { 0 };
    election_list.election_type = election_type;

    if (oal_any_null_ptr1(measure_res)) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_trigger_by_measure::measure_res is null");
        return OAL_FAIL;
    }

    /* 从测量结果内过滤满足rssi、黑名单、时隙等要求的候选域主列表 */
    ret = hmac_nbw_get_master_election_list(measure_res, &election_list);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_trigger_by_measure::convert measure list err.");
        return OAL_FAIL;
    }

    /* 若过滤后的候选列表为空，则直接返回失败 */
    if (election_list.master_election_cnt == 0) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_trigger_by_measure::no matching candidate.");
        return OAL_FAIL;
    }

    if (election_type == TRIGGER_BY_MASTER) {
        hmac_nbw_master_election_trigger_by_master(&election_list, result_list_by_priority);
    } else if (election_type == TRIGGER_BY_MASTER_LOSS || election_type == TRIGGER_BY_SLAVEAP) {
        /* slaveAP触发的域主选举和master loss触发的选举规则基本一致 */
        hmac_nbw_master_election_trigger_by_slaveap(&election_list, result_list_by_priority);
    } else {
        oam_error_log1(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_trigger_by_measure::unknown type:[%d].",
            election_type);
        return OAL_FAIL;
    }

    /* free election_list */
    if (election_list.master_election_cnt > 0) {
        oal_free(election_list.master_election_list);
    }
    return OAL_SUCC;
}

static void hmac_nbw_slaveap_to_master_by_master_loss(hmac_vap_stru *hmac_vap,
    hmac_nbw_island_conn_info_rpt island_conn_info)
{
    hmac_nbw_slot_info_stru *timeslot_info = &island_conn_info.slot_info;
    hmac_nbw_uslot_info_stru tmp_uslot_bitmap = timeslot_info->uslot_info;

    /* 角色变更为master */
    hmac_nbw_set_role(MAC_NBW_MASTER_ROLE);

    /* 设置本设备bssid为master bssid */
    oal_set_mac_addr(hmac_nbw_get_master_macaddr(), hmac_vap->st_vap_base_info.auc_bssid);
    /* 调整当前链路时隙到uslot0，并重置链路原时隙信息 */
    hmac_nbw_resume_timeslot_bitmap(tmp_uslot_bitmap);
    timeslot_info->uslot_info = hmac_nbw_calculate_uslotbitmap(1);
    /* 如果申请不到时隙，结束流程 */
    if (timeslot_info->uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_loss_select_self_as_master::apply timeslot "
            "fail.");
        return;
    }

    /* NBW拓扑更新流程 */
    hmac_nbw_update_conn_info(hmac_vap, island_conn_info, timeslot_info->peer_device_mac,
        hmac_nbw_get_master_macaddr(), WLAN_MAC_ADDR_LEN);
    /* 同步设备角色和域主bssid */
    hmac_nbw_sync_self_info(hmac_vap);
    /* 更新Beacon和PNF到Driver */
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
}

static void hmac_nbw_master_loss_get_linked_used_timeslot(hmac_nbw_slot_info_stru *timeslot_info, uint8_t work_mode)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    uint8_t slot_idx;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);

    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (self_conn_info->self_device_id != curr_island->owner_device_id) {
            continue;
        }
        for (slot_idx = 0; slot_idx < MAX_ISLAND_SLOT_INFO_NUM; slot_idx++) {
            // 从本岛中选取一条链路做时隙调整
            if (curr_island->island_slot_info[slot_idx].use_flag == OAL_TRUE) {
                memcpy_s(timeslot_info, sizeof(hmac_nbw_slot_info_stru), &curr_island->island_slot_info[slot_idx],
                    sizeof(hmac_nbw_slot_info_stru));
                break;
            }
        }
        return;
    }
}

/*
 * 功能描述  : 选择本设备作为master
 * 日    期  : 2025年04月25日
 */
void hmac_nbw_master_loss_select_self_as_master(hmac_vap_stru *hmac_vap)
{
    uint8_t work_mode = hmac_vap->st_vap_base_info.work_mode;
    hmac_nbw_island_conn_info_rpt island_conn_info = { 0 };
    hmac_nbw_slot_info_stru *timeslot_info = &island_conn_info.slot_info;
    uint8_t master_device_id;

    oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_loss_select_self_as_master::enter.");

    /* 1、删除当前岛屿topo里的原master信息，该流程中会处理master allocated slot */
    master_device_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, hmac_nbw_get_master_macaddr());
    hmac_nbw_del_one_device_island_info(hmac_vap, master_device_id);

    /* 2、获取本岛内其中一条链路时隙信息，用于时隙调整 */
    hmac_nbw_master_loss_get_linked_used_timeslot(timeslot_info, work_mode);

    /* 3、slaveap调整当前链路时隙到管理时隙，更新角色为master，并通知slave时隙调整，以及配置beacon和时隙信息到dmac */
    if (timeslot_info->use_flag == OAL_TRUE) {
        hmac_nbw_slaveap_to_master_by_master_loss(hmac_vap, island_conn_info);
    } else {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_loss_select_self_as_master::no used timeslot find,"
            "invalid slaveap.");
    }
    hmac_chba_del_one_device_info(work_mode, master_device_id);
    hmac_nbw_set_domain_merge_flag(OAL_FALSE);
    return;
}

/*
 * 功能描述  : 本岛主向新域主合并流程
 * 日    期  : 2025年06月13日
 */
static void hmac_nbw_master_loss_slaveap_merge_to_new_master(hmac_vap_stru *hmac_vap, election_master_info_stru res)
{
    oam_warning_log3(0, OAM_SF_NBW, "NBW: hmac_nbw_master_loss_slaveap_merge_to_new_master::merge to new master:"
        "mac=%02X:XX:XX:XX:%02X:%02X", res.master_addr[0], res.master_addr[MAC_ADDR_4], res.master_addr[MAC_ADDR_5]);

    /* 1、更新全域已分配时隙，本岛分配时隙不变 */
    hmac_nbw_set_alloc_uslot_bitmap(res.alloc_uslot_bitmap);

    /* 2、更新域主mac地址 */
    oal_set_mac_addr(hmac_nbw_get_master_macaddr(), res.master_addr);

    /* 3、向device配置beacon和pnf信息 */
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
}

static void hmac_nbw_master_loss_select_best_candidate(hmac_nbw_chan_measure_res_stru *measure_res,
    hmac_vap_stru *hmac_vap)
{
    hmac_nbw_master_election_result_info_stru result_list_by_priority = { 0 };

    hmac_nbw_master_election_trigger_by_measure(measure_res, TRIGGER_BY_MASTER_LOSS, &result_list_by_priority);

    /* 5.1、若选举结果为空，则本设备成为新域主 */
    if (result_list_by_priority.master_election_result_cnt == 0) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_loss_select_best_candidate::no measure res found,"
            "self device become master.");
        hmac_nbw_master_loss_select_self_as_master(hmac_vap);
    } else {
        /* 5.2、根据slaveAP干扰触发的选举规则，选择最优的master合并 */
        election_master_info_stru res = hmac_nbw_get_best_master_election_info(&result_list_by_priority);
        if (res.is_local_master == OAL_TRUE) {
            oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_loss_select_best_candidate::no avail candidate found,"
                "self device become master.");
            hmac_nbw_master_loss_select_self_as_master(hmac_vap);
        } else {
            hmac_nbw_master_loss_slaveap_merge_to_new_master(hmac_vap, res);
        }
        return;
    }
}

/*
 * 功能描述  : master丢失后，slaveap触发测量结果到期时的处理函数
 * 日    期  : 2025年04月25日
 */
void hmac_nbw_master_loss_trigger_chan_meas_process(hmac_vap_stru *hmac_vap)
{
    hmac_nbw_chan_measure_res_stru *measure_res = NULL;

    /* 4、在定时器超时后, 获取测量结果 */
#ifdef _PRE_WLAN_NBW_DEMO
    hmac_nbw_chan_measure_res_stru *measure_res_list = NULL;
    measure_res_list = hmac_nbw_get_channel_measure_res();
    measure_res = &measure_res_list[0];
    if (measure_res_list != NULL) {
        measure_res = &measure_res_list[0];
    }
#else
    measure_res = hmac_nbw_get_measure_res_pos(hmac_vap->hmac_chba_vap_info->work_channel.uc_chan_number);
#endif
    oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_loss_trigger_chan_meas_process::enter");

    /* 5、根据测量结果，筛选合适的master beacon */
    hmac_nbw_master_loss_select_best_candidate(measure_res, hmac_vap);
}

/*
 * 功能描述  : 在m*2个beacon周期内未收到master beacon，则触发岛主的master选举
 * 日    期  : 2025年04月25日
 */
uint32_t hmac_nbw_master_election_by_loss(hmac_vap_stru *hmac_vap)
{
    uint8_t channel_cnt = 0;
    uint8_t channel_list = 0;
    uint32_t measure_time = 0;
    uint8_t ranking_id = hmac_nbw_sync_get_rp_ranking_id();
    /* 当前处于域合并/域拆分流程中，不再触发新的域拆分，直到上次结束 */
    if (hmac_nbw_get_domain_merge_flag() == OAL_TRUE) {
        return OAL_FAIL;
    }

    /* 1. 获取当前NBW工作信道，作为待测量信道 */
#ifdef _PRE_WLAN_NBW_DEMO
    /* demo阶段，device默认仅扫描当前工作信道，上层无需指定信道 */
    channel_cnt = 1;
    channel_list = 1;
#else
    channel_list = hmac_nbw_get_measure_param_by_current_work_channel(hmac_vap);
    if (channel_list <= 0) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_by_loss::no work channel found.");
        return OAL_FAIL;
    }
    channel_cnt = 1;
#endif
    hmac_nbw_set_domain_merge_flag(OAL_TRUE);
    /* 2. 根据维护的RP id, 设置信道测量时长为 (m - 1) * 2(m为ranking id的值)个beacon周期，且最大测量时长不超过1s */
    measure_time = MAC_NBW_DEFALUT_PERIODS_MS * (ranking_id - 1) * 2;
    if (measure_time > NBW_MASTER_ELECTION_MAX_MEASURE_TIME) {
        measure_time = NBW_MASTER_ELECTION_MAX_MEASURE_TIME;
    }

    if (measure_time == 0) {
        /* 3.1 ranking_id为0的设备，直接当选master */
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_by_loss::ranking id: 1, to be master.");
        hmac_nbw_master_loss_select_self_as_master(hmac_vap);
        return OAL_SUCC;
    } else {
        /* 3.2 下发信道测量,测量周期为n*m*2个beacon周期 */
        oam_warning_log2(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_by_loss::ranking id:[%d], measure_time:[%d]",
            ranking_id, measure_time);
        if (hmac_nbw_channel_measure_request(hmac_vap, channel_cnt, channel_list,
            MAC_NBW_MASTER_LOST_TRIGGER_CHAN_MEASURE, measure_time) != MAC_NBW_CHANNEL_MEASURE_NORMAL) {
            oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_master_election_by_loss::channel measure err");
            hmac_nbw_master_loss_select_self_as_master(hmac_vap);
            return OAL_FAIL;
        }
    }
    hmac_nbw_set_domain_merge_flag(OAL_FALSE);
    return OAL_SUCC;
}

int compare_by_rp(const void *a, const void *b)
{
    const island_rank_entry *entry_a = (const island_rank_entry *)a;
    const island_rank_entry *entry_b = (const island_rank_entry *)b;

    int cmp = hmac_nbw_dev_rp_compare(entry_a->rp, entry_b->rp, entry_a->mac_addr, entry_b->mac_addr);
    return -cmp;
}

uint8_t hmac_nbw_get_rp_ranking_by_slaveap_id(uint8_t work_mode, uint8_t slaveap_id)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_lnfo = hmac_chba_get_island_list(work_mode);

    hi_list_for_each_safe(nbw_node, tmp, &island_lnfo->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (curr_island->owner_device_id == slaveap_id) {
            return curr_island->slaveap_rp.ranking_id;
        }
    }

    return 0;
}

/*
 * 功能描述  : 当有新的岛主接入或者岛主宣告rp值变更时，域主需要更新岛主在域内的rp排名
 * 日    期  : 2025年04月25日
 */
void hmac_nbw_update_rp_ranking_id(uint8_t work_mode)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    island_rank_entry *entries = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_lnfo = hmac_chba_get_island_list(work_mode);
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    int idx = 0, i;
    if (hmac_nbw_get_role() != MAC_NBW_MASTER_ROLE) {
        return; // 只在master设备上更新ranking id
    }

    // 分配临时存储空间
    entries = oal_memalloc(island_lnfo->island_cnt * sizeof(island_rank_entry));
    if (entries == NULL) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_update_rp_ranking_id::alloc fail.");
        return;
    }

    hi_list_for_each_safe(nbw_node, tmp, &island_lnfo->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        entries[idx].node = curr_island;
        if (memcpy_s(entries[idx].mac_addr, OAL_MAC_ADDR_LEN,
            device_id_info[curr_island->owner_device_id].mac_addr, OAL_MAC_ADDR_LEN) != EOK) {
            oal_free(entries);
            return;
        }
        if (memcpy_s(&entries[idx].rp, sizeof(nbw_ranking_priority),
            &curr_island->slaveap_rp, sizeof(nbw_ranking_priority)) != EOK) {
            oal_free(entries);
            return;
        }
        idx++;
    }

    // 按 device_level.value 降序排序
    hmac_qsort(entries, island_lnfo->island_cnt, sizeof(island_rank_entry), compare_by_rp);

    // 分配 ranking_id（值越大、排序越前则 ranking_id 越小）
    for (i = 0; i < island_lnfo->island_cnt; i++) {
        entries[i].node->slaveap_rp.ranking_id = i + 1; // 排名从 1 开始
        if (entries[i].node->owner_device_id == self_conn_info->self_device_id) {
            hmac_nbw_sync_set_rp_id(entries[i].node->slaveap_rp.ranking_id);
        }
        oam_warning_log2(0, OAM_SF_NBW, "NBW: hmac_nbw_update_rp_ranking_id::slaveap_id:[%d], ranking_id:[%d].",
            entries[i].node->owner_device_id, entries[i].node->slaveap_rp.ranking_id);
    }
    oal_free(entries);
}

/*
 * 功能描述  : slaveap收到master beacon，更新rp id
 * 日    期  : 2025年06月05日
 */
void hmac_nbw_update_sync_ranking_id(uint8_t work_mode)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_lnfo = hmac_chba_get_island_list(work_mode);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();

    hi_list_for_each_safe(nbw_node, tmp, &island_lnfo->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (curr_island->owner_device_id == self_conn_info->self_device_id) {
            if (oal_memcmp(&sync_info->nbw_rp_info, &curr_island->slaveap_rp, sizeof(nbw_ranking_priority)) != 0) {
                oam_warning_log2(0, OAM_SF_NBW, "NBW: hmac_nbw_update_sync_ranking_id::update old ranking_id:[%d],"
                    "new ranking_id:[%d]", sync_info->nbw_rp_info.ranking_id, curr_island->slaveap_rp.ranking_id);
                sync_info->nbw_rp_info = curr_island->slaveap_rp;
                break;
            }
        }
    }
}

/*
 * 功能描述  : hmac_nbw_update_island_info流程更新岛域拓扑时，在首次初始化本设备岛信息时，从sync中更新rp到岛信息内
 * 日    期  : 2025年06月05日
 */
oal_bool_enum_uint8 hmac_nbw_self_device_update_rp(uint8_t work_mode, hmac_chba_per_island_info_stru *curr_island)
{
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_self_device_update_rp::enter");

    if (oal_any_null_ptr2(curr_island, self_conn_info)) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_self_device_update_rp::input param err");
        return OAL_FALSE;
    }

    if (curr_island->owner_device_id == self_conn_info->self_device_id) {
        curr_island->slaveap_rp = *hmac_nbw_sync_get_rp_info();
        oam_warning_log1(0, OAM_SF_NBW, "NBW: hmac_nbw_self_device_update_rp::update owner island rp:[%d]",
            curr_island->slaveap_rp.ranking_id);
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

/*
 * 功能描述  : 根据result_list_by_priority内的选举结果，返回最优的域主信息，若选举结果为空，则返回本域域主信息
 * 日    期  : 2025年06月05日
 */
election_master_info_stru hmac_nbw_get_best_master_election_info(
    hmac_nbw_master_election_result_info_stru *result_list_by_priority)
{
    election_master_info_stru res = { 0 };

    /* 1、若master_election_result_list不为空，则返回列表中的第一个元素 */
    if (result_list_by_priority->master_election_result_cnt > 0 &&
        result_list_by_priority->master_election_result_list != NULL) {
        return result_list_by_priority->master_election_result_list[0];
    }

    /* 2、干扰检测触发的选举，若结果列表为空，则返回本域master作为选举结果 */
    fill_local_master_info(&res);
    return res;
}

/*
 * 功能描述  : 初始化nbw sync info信息和选举黑名单
 * 日    期  : 2025年06月05日
 */
void hmac_nbw_sync_module_init(hmac_chba_device_para_stru *device_info)
{
    hmac_nbw_sync_set_rp_dev_type(device_info->device_type);
    hmac_nbw_sync_set_rp_capability(device_info->hardwire_cap);
    hmac_nbw_sync_set_rp_power(device_info->remain_power);
    hmac_nbw_sync_set_rp_version(device_info->config_para.chba_version);
    hmac_nbw_sync_set_rp_id(NBW_DEFAULT_RANKING_ID); /* nbw设备默认初始ranking id为1 */
    hmac_nbw_blacklist_init(); /* 初始化master选举黑名单 */
}

struct rssi_to_signal_level {
    uint32_t level;
    int8_t rssi[WLAN_BAND_BUTT];
};

/* 微功率需要再单独适配修改 */
struct rssi_to_signal_level g_nbw_rssi_to_signal_level[SIGNAL_LEVEL_NUM] = {
    { 4,  {-65, -65}, }, // 四格
    { 3,  {-75, -72}, }, // 三格
    { 2,  {-82, -79}, }, // 两格
    { 1,  {-88, -85}, }, // 一格
    // 零格
};

uint32_t hmac_nbw_rssi_to_signal_level(int8_t rssi, wlan_channel_band_enum_uint8 band)
{
    uint32_t i = 0;
    if (band >= WLAN_BAND_BUTT) {
        /* 非法频段，返回最小信号格数 */
        oam_error_log1(0, OAM_SF_NBW, "{hmac_nbw_rssi_to_signal_level::invalid band [%d]}", band);
        return 0;
    }

    for (i = 0; i < SIGNAL_LEVEL_NUM; i++) {
        if (rssi >= g_nbw_rssi_to_signal_level[i].rssi[band]) {
            return g_nbw_rssi_to_signal_level[i].level;
        }
    }
    return 0;
}
#endif