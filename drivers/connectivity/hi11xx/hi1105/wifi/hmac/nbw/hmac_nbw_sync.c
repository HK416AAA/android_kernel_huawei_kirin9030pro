/*
 * Copyright (c) @CompanyNameMagicTag 2025-2025. All rights reserved.
 * Description: nbw powersave
 * Author: wifi
 * Create: 2025-05-20
 */

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_SYNC_C
#include "hmac_nbw_sync.h"
#include "hmac_config.h"
#include "hmac_nbw_frame.h"
#include "hmac_nbw_master_election.h"
#include "hmac_nbw_mgmt.h"
#include "hmac_nbw_channnel_measure.h"
#include "hmac_nbw_chan_switch.h"
#ifdef _PRE_WLAN_FEATURE_NBW
hmac_chba_sync_info g_nbw_sync_info;

void hmac_nbw_interfere_trigger_handler(hmac_vap_stru *hmac_vap)
{
    uint32_t ret;
    uint32_t slot_idx;
    hmac_nbw_slot_info_stru slot_info = { 0 };
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    if (hmac_vap == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_interfere_trigger_handler::input pointer is null.");
        return;
    }
    if (hmac_nbw_get_domain_merge_flag() == OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_interfere_trigger_handler::already in domain merge state.");
        return;
    }
    /* 检查自身角色, 如果是slave则给岛主发送信道测量请求，如果是slaveap或者master则直接开始信道测量 */
    if (hmac_nbw_get_role() == MAC_NBW_SLAVE_ROLE) {
        // 暂时不考虑群岛
        for (slot_idx = 0; slot_idx < MAX_ISLAND_SLOT_INFO_NUM; slot_idx++) {
            if (slave_slot_info[slot_idx].use_flag != OAL_TRUE) {
                continue;
            }
            hmac_nbw_send_timeslot_frame(slave_slot_info[slot_idx].peer_device_mac,
                mac_mib_get_StationID(&hmac_vap->st_vap_base_info), OAL_MAC_ADDR_LEN, slot_info,
                MAC_NBW_DOMAIN_MERGE_REQUEST_ACTION, 0);
            oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_interfere_trigger_handler::trigger domain merge action send.");
        }
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_interfere_trigger_handler::slave.");
    } else {
        /* 目前测量信道只测当前工作信道，测量时间200ms */
        ret = hmac_nbw_channel_measure_request(hmac_vap, 1, 1, MAC_NBW_POOR_QOS_TRIGGER_CHAN_MEASURE,
            NBW_CHANNEL_MEASURE_TIME);
        if (ret != MAC_NBW_CHANNEL_MEASURE_NORMAL) {
            /* 目前因为干扰或per升高，测量信道失败直接return，等下次触发 */
            oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_interfere_trigger_handler::measure fail wait next time.");
            return;
        }
    }
}


void hmac_sync_nbw_domain_merge_flag(mac_vap_stru *mac_vap)
{
    uint32_t ret;
    uint8_t  domain_merge_flag = hmac_nbw_get_domain_merge_flag();
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_NBW_SET_DOMAIN_MERGE_FLAG, sizeof(uint8_t), &domain_merge_flag);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_sync_nbw_domain_merge_flag:: send event fail");
    }
}


void hmac_nbw_sync_self_info(hmac_vap_stru *hmac_vap)
{
    chba_params_config_stru chba_params_sync;
    chba_params_sync.chba_role = hmac_nbw_get_role();
    oal_set_mac_addr(chba_params_sync.domain_bssid, hmac_nbw_get_master_macaddr());
    chba_params_sync.chba_state =  hmac_chba_get_sync_state();
    chba_params_sync.info_bitmap = CHBA_STATE | CHBA_ROLE | CHBA_BSSID;
    hmac_chba_params_sync(&hmac_vap->st_vap_base_info, &chba_params_sync);
    /* 同步域合并 */
    hmac_sync_nbw_domain_merge_flag(&hmac_vap->st_vap_base_info);
}

void hmac_nbw_sync_self_role(hmac_vap_stru *hmac_vap)
{
    chba_params_config_stru chba_params_sync;
    chba_params_sync.chba_role = hmac_nbw_get_role();

    chba_params_sync.info_bitmap = CHBA_ROLE;
    hmac_chba_params_sync(&hmac_vap->st_vap_base_info, &chba_params_sync);
}

void hmac_nbw_domain_merge_trigger_process(hmac_vap_stru *hmac_vap, election_master_info_stru sel_master)
{
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();
    hmac_nbw_slot_info_stru timeslot_info = { 0 };
    uint8_t slave_addr[OAL_MAC_ADDR_LEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    oal_set_mac_addr(hmac_nbw_get_domain_merge_master_bssid(), sel_master.master_addr);
    hmac_nbw_set_role(MAC_NBW_SLAVEAP_ROLE);
   
    /* 向新域主申请时隙 */
    hmac_nbw_send_timeslot_frame(sel_master.master_addr, slave_addr, OAL_MAC_ADDR_LEN, timeslot_info,
        MAC_NBW_TIMESLOT_NEG_ACTION, MAC_NBW_TIMESLOT_NEG_AND_SYNC_REQUEST_ACTION);
    /* 设置状态标志位 */
    hmac_chba_set_sync_state(CHBA_NON_SYNC);
    hmac_nbw_set_domain_merge_flag(OAL_TRUE);
    hmac_nbw_sync_self_info(hmac_vap);
    /* 起定时器 */
    if (sync_info->domain_merge_sync_waiting_timer.en_is_registerd != OAL_TRUE) {
        /* 设置域合并时隙申请超时器 */
        frw_timer_create_timer_m(&(sync_info->domain_merge_sync_waiting_timer),
            hmac_nbw_waiting_domain_merge_timeslot_req_timeout, MAC_NBW_DEFALUT_PERIODS_MS,
            hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
    }
}

void hmac_nbw_domain_merge_recover_process(hmac_vap_stru *hmac_vap)
{
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();
    sync_info->nbw_domain_merge_info.ask_for_sync_cnt = 0;
    /* 设置状态标志位 */
    hmac_chba_set_sync_state(CHBA_WORK);
    hmac_nbw_set_domain_merge_flag(OAL_FALSE);
    /* 本设备成为Master */
    oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_domain_merge_recover_process::no timeslot response,"
            "self device become master.");
    if (oal_compare_mac_addr(mac_mib_get_StationID(&hmac_vap->st_vap_base_info), hmac_nbw_get_master_macaddr()) == 0) {
        /* 本设备已经是Master，后续不处理，直接返回 */
        hmac_nbw_set_role(MAC_NBW_MASTER_ROLE);
        hmac_nbw_sync_self_info(hmac_vap);
        /* 同步状态和设备角色变化，需要重新下发beacon和pnf */
        hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_NO_CHANGED_INDICATE);
        return;
    }
    hmac_nbw_master_loss_select_self_as_master(hmac_vap);
}


void hmac_nbw_domain_merge_succ_process(hmac_vap_stru *hmac_vap, hmac_chba_per_island_info_stru *self_island)
{
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();
    hmac_chba_per_island_info_stru zero_island = { 0 };
    if (self_island == NULL || oal_memcmp(self_island, &zero_island, sizeof(hmac_chba_per_island_info_stru)) == 0) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_domain_merge_succ_process::null island.");
        hmac_nbw_domain_merge_recover_process(hmac_vap);
        return;
    }
    /* 当前处于域合并流程中 */
    if (hmac_chba_get_sync_state() != CHBA_NON_SYNC || hmac_nbw_get_domain_merge_flag() != OAL_TRUE) {
        return;
    }

    sync_info->nbw_domain_merge_info.ask_for_sync_cnt = 0;
    /* 与新域同步完成, 注销等待定时器 */
    if (sync_info->domain_merge_sync_waiting_timer.en_is_registerd) {
        frw_timer_immediate_destroy_timer_m(&sync_info->domain_merge_sync_waiting_timer);
    }
    /* 设置状态标志位 */
    hmac_chba_set_sync_state(CHBA_WORK);
    hmac_nbw_set_domain_merge_flag(OAL_FALSE);
    oal_set_mac_addr(hmac_nbw_get_master_macaddr(), hmac_nbw_get_domain_merge_master_bssid());
    /* 同步标志位至dmac */
    hmac_nbw_sync_self_info(hmac_vap);
}


uint32_t hmac_nbw_waiting_domain_merge_timeslot_req_timeout(void *arg)
{
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)arg;
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();
    hmac_nbw_slot_info_stru timeslot_info = { 0 };
    uint8_t slave_addr[OAL_MAC_ADDR_LEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    if (hmac_vap == NULL) {
        oam_error_log0(0, 0, "hmac_nbw_waiting_domain_merge_timeslot_req_timeout: arg is null");
        return OAL_ERR_CODE_PTR_NULL;
    }
    /* 起定时器 */
    if (sync_info->domain_merge_sync_waiting_timer.en_is_registerd) {
        frw_timer_immediate_destroy_timer_m(&(sync_info->domain_merge_sync_waiting_timer));
    }
    if (sync_info->nbw_domain_merge_info.ask_for_sync_cnt < NBW_MAX_COUNT_DOMAIN_MERGE_REQ_CNT) {
        sync_info->nbw_domain_merge_info.ask_for_sync_cnt ++;
        hmac_nbw_send_timeslot_frame(hmac_nbw_get_domain_merge_master_bssid(), slave_addr, OAL_MAC_ADDR_LEN,
            timeslot_info, MAC_NBW_TIMESLOT_NEG_ACTION, MAC_NBW_TIMESLOT_NEG_AND_SYNC_REQUEST_ACTION);
        frw_timer_create_timer_m(&(sync_info->domain_merge_sync_waiting_timer),
            hmac_nbw_waiting_domain_merge_timeslot_req_timeout, MAC_NBW_DEFALUT_PERIODS_MS,
            hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
        oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_waiting_domain_merge_timeslot_req_timeout::continue retrans[%d].",
            sync_info->nbw_domain_merge_info.ask_for_sync_cnt);
        return OAL_SUCC;
    }
    hmac_nbw_domain_merge_recover_process(hmac_vap);
    return OAL_SUCC;
}


uint32_t hmac_nbw_interface_trigger_chan_meas_process(hmac_vap_stru *hmac_vap)
{
    /* 根据测量结果选择切信道或者域合并, 现在只要测到了有热点且rssi合理，就发起合并 */
    /* 默认07c单信道测量存在测量结果数组的第一个索引 */
    uint8_t nbw_role = hmac_nbw_get_role();
    hmac_nbw_chan_measure_res_stru *measure_res = hmac_nbw_get_measure_res_pos(NBW_CHANNEL_8);
    nbw_master_election_scene_enum election_type;
    election_master_info_stru res = { 0 };
    hmac_nbw_master_election_result_info_stru result_list = { 0 };
    hmac_nbw_slot_info_stru timeslot_info = { 0 };
    uint8_t slave_addr[OAL_MAC_ADDR_LEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    if (nbw_role == MAC_NBW_MASTER_ROLE) {
        election_type = TRIGGER_BY_MASTER;
    } else if (nbw_role == MAC_NBW_SLAVEAP_ROLE || nbw_role == MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE) {
        election_type = TRIGGER_BY_SLAVEAP;
    } else {
        return OAL_SUCC;
    }

    if (hmac_nbw_master_election_trigger_by_measure(measure_res, election_type, &result_list) != OAL_SUCC) {
        return OAL_FAIL;
    }
    res = hmac_nbw_get_best_master_election_info(&result_list);
    if (res.is_local_master == OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_interface_trigger_chan_meas_process::no avail candidate found,"
            "self device become master.");
        return OAL_SUCC;
    }
    /* 跟随新域主 */
    oam_warning_log3(0, OAM_SF_NBW, "hmac_nbw_interface_trigger_chan_meas_process::master bssid[%02X]...[%02X][%02X],",
        res.master_addr[0], res.master_addr[BYTE_OFFSET_4], res.master_addr[BYTE_OFFSET_5]);
    if (nbw_role == MAC_NBW_SLAVEAP_ROLE || nbw_role == MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE) {
        /* 告知旧域主释放时隙 */
        timeslot_info.uslot_info.start_idx = INVALID_TIMESLOT_USLOT_IDX; // 255为无效值
        timeslot_info.uslot_info.end_idx = INVALID_TIMESLOT_USLOT_IDX; // 255为无效值
        hmac_nbw_send_timeslot_frame(hmac_nbw_get_master_macaddr(), slave_addr, OAL_MAC_ADDR_LEN, timeslot_info,
            MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_ACTION);
    }
    /* 新域主存在于当前域拓扑内，删除对应时隙分配后再发送时隙申请 */
    if (hmac_nbw_slaveap_exist_in_domain(hmac_vap->st_vap_base_info.work_mode, res.master_addr,
        OAL_MAC_ADDR_LEN) == OAL_TRUE) {
        hmac_nbw_del_device_by_mac_addr(&hmac_vap->st_vap_base_info, res.master_addr, OAL_MAC_ADDR_LEN);
    }
    hmac_nbw_domain_merge_trigger_process(hmac_vap, res);
    return OAL_SUCC;
}
#endif