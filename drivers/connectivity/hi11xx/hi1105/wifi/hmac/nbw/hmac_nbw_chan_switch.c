/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw frame encap and trx
 * Author: wifi
 * Create: 2024-12-26
 */
#include "hmac_nbw_frame.h"
#include "mac_frame_inl.h"
#include "hmac_chba_frame.h"
#include "hmac_chba_fsm.h"
#include "hmac_chba_sync.h"
#include "hmac_nbw_chan_switch.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_CHAN_SWITCH_C

#ifdef _PRE_WLAN_FEATURE_NBW
#ifdef _PRE_WLAN_NBW_DEMO
hmac_nbw_mode_switch_notify_stru g_nbw_mode_switch_info = {};
hmac_nbw_mode_switch_notify_stru *hmac_get_nbw_mode_switch_info(void)
{
    return &g_nbw_mode_switch_info;
}

static void hmac_nbw_set_mode_switch_attr(hmac_nbw_mode_switch_notify_stru *mode_switch_ntf, uint8_t *attr_buf)
{
    uint8_t index;

    /* Attribute ID */
    attr_buf[0] = MAC_NBW_ATTR_MODE_SWITCH;
    index = MAC_NBW_ATTR_HDR_LEN;

    attr_buf[index++] = mode_switch_ntf->notify_type;
    attr_buf[index++] = mode_switch_ntf->channel_info.en_band;
    attr_buf[index++] = mode_switch_ntf->channel_info.uc_chan_number;
    attr_buf[index++] = mode_switch_ntf->channel_info.en_bandwidth;
    attr_buf[index++] = mode_switch_ntf->pwr_level;

    /* 设置Attr Length字段 */
    attr_buf[MAC_NBW_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
}

static uint32_t hmac_nbw_encap_mode_switch_action(hmac_vap_stru *hmac_vap, uint8_t *frame_buf,
    hmac_nbw_mode_switch_notify_stru *mode_switch_ntf, uint8_t *peer_addr)
{
    uint16_t total_len = 0;
    hmac_chba_vap_stru *chba_vap_info = hmac_get_chba_vap();
    mac_vap_stru *mac_vap = NULL;
    uint8_t *action_buf = NULL;

    if (oal_any_null_ptr2(hmac_vap, frame_buf)) {
        return total_len;
    }

    mac_vap = &(hmac_vap->st_vap_base_info);
    if (mac_vap == NULL) {
        return total_len;
    }
    mac_hdr_set_frame_control(frame_buf, WLAN_PROTOCOL_VERSION | WLAN_FC0_TYPE_MGT | WLAN_FC0_SUBTYPE_ACTION);
    oal_set_mac_addr(frame_buf + WLAN_HDR_ADDR1_OFFSET, peer_addr);
    oal_set_mac_addr(frame_buf + WLAN_HDR_ADDR2_OFFSET, mac_mib_get_StationID(mac_vap));
    mac_set_domain_bssid(frame_buf + WLAN_HDR_ADDR3_OFFSET, mac_vap, chba_vap_info);
    total_len += MAC_80211_FRAME_LEN;
    action_buf = frame_buf + total_len;
    mac_set_nbw_action_hdr(action_buf, MAC_CHBA_CHANNEL_SWITCH_NOTIFICATION);
    total_len += MAC_CHBA_ACTION_HDR_LEN;

    /* 封装Mode Switch属性 */
    hmac_nbw_set_mode_switch_attr(mode_switch_ntf, frame_buf + total_len);
    total_len += MAC_NBW_MODE_SWITCH_ATTR_LEN;
    return total_len;
}

uint32_t hmac_nbw_send_mode_switch_notify_action(uint8_t *peer_addr, hmac_nbw_mode_switch_notify_stru *mode_switch_ntf)
{
    uint32_t ret;
    hmac_chba_vap_stru *chba_vap_info = hmac_get_chba_vap();
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(chba_vap_info->mac_vap_id);
    oal_netbuf_stru *frame_buf = NULL;
    uint32_t frame_len;

    if (oal_any_null_ptr3(peer_addr, mode_switch_ntf, hmac_vap)) {
        return OAL_FAIL;
    }
    frame_buf = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (frame_buf == NULL) {
        oam_error_log0(0, OAM_SF_NBW, "hmac_nbw_send_mode_switch_notify_action::frame alloc failed.");
        return OAL_ERR_CODE_PTR_NULL;
    }
    oal_mem_netbuf_trace(frame_buf, OAL_TRUE);

    /* 将mac header清零 */
    memset_s(oal_netbuf_cb(frame_buf), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    memset_s((uint8_t *)oal_netbuf_header(frame_buf), MAC_80211_FRAME_LEN, 0, MAC_80211_FRAME_LEN);

    frame_len = hmac_nbw_encap_mode_switch_action(hmac_vap, (uint8_t *)(oal_netbuf_header(frame_buf)),
        mode_switch_ntf, peer_addr);
    if (frame_len == 0) {
        oal_netbuf_free(frame_buf);
        return OAL_FAIL;
    }

    hmac_chba_mgmt_cb_partial_init(&(hmac_vap->st_vap_base_info), peer_addr, frame_buf, frame_len, OAL_FALSE);
    oal_netbuf_put(frame_buf, frame_len);

    ret = hmac_tx_mgmt_send_event(&(hmac_vap->st_vap_base_info), frame_buf, frame_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(frame_buf);
        oam_warning_log1(0, 0, "hmac_nbw_send_mode_switch_notify_action::hmac_tx_mgmt_send_event failed[%d].", ret);
        return ret;
    }
    oam_warning_log4(0, OAM_SF_NBW,
        "hmac_nbw_send_mode_switch_notify_action::mode switch action tx, type %d, channel_num[%d], bw[%d], pwr_lvl[%d]",
        mode_switch_ntf->notify_type, mode_switch_ntf->channel_info.uc_chan_number,
        mode_switch_ntf->channel_info.en_bandwidth, mode_switch_ntf->pwr_level);

    return OAL_SUCC;
}

uint32_t hmac_nbw_waiting_mode_switch_rsp_timeout(void *arg)
{
    uint32_t ret;
    uint32_t curr_time;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_chba_vap_stru *chba_vap_info = NULL;
    uint8_t *peer_addr = (uint8_t *)arg;
    hmac_nbw_mode_switch_notify_stru *nbw_mode_switch_info = hmac_get_nbw_mode_switch_info();

    chba_vap_info = hmac_get_up_chba_vap_info();
    if (chba_vap_info == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(chba_vap_info->mac_vap_id);
    if (oal_any_null_ptr2(hmac_vap, nbw_mode_switch_info)) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    if (nbw_mode_switch_info->req_timer.en_is_registerd) {
        frw_timer_immediate_destroy_timer_m(&(nbw_mode_switch_info->req_timer));
    }
    nbw_mode_switch_info->req_timeout_cnt++;
    oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_waiting_mode_switch_rsp_timeout::req_timeout_cnt %d",
        nbw_mode_switch_info->req_timeout_cnt);
    /* 连续两次请求超时，退出切换失败 */
    if (nbw_mode_switch_info->req_timeout_cnt >= NBW_MAX_COUNT_SWITCH_REQ_CNT) {
        nbw_mode_switch_info->req_timeout_cnt = 0;
        return OAL_SUCC;
    }
    /* 信道切换请求帧重传 */
    ret = hmac_nbw_send_mode_switch_notify_action(peer_addr, nbw_mode_switch_info);
    if (ret != OAL_SUCC) {
        return ret;
    }
    /* 更新上次发送时间 */
    curr_time = (uint32_t)oal_time_get_stamp_ms();
    nbw_mode_switch_info->last_send_req_time = curr_time;
    /* 设置rsp等待超时定时器 */
    frw_timer_create_timer_m(&(nbw_mode_switch_info->req_timer),
        hmac_nbw_waiting_mode_switch_rsp_timeout, WAITTING_TWO_DURATION_MS,
        peer_addr, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
    return OAL_SUCC;
}

uint32_t hmac_nbw_start_mode_switch(uint8_t *peer_addr)
{
    uint32_t ret;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_chba_vap_stru *chba_vap_info = NULL;
    mac_vap_stru *mac_vap = NULL;
    nbw_demo_pwr_switch_stru nbw_pwr_switch = {};
    hmac_nbw_mode_switch_notify_stru *nbw_mode_switch_info = hmac_get_nbw_mode_switch_info();
    chba_vap_info = hmac_get_up_chba_vap_info();
    if (chba_vap_info == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(chba_vap_info->mac_vap_id);
    if (oal_any_null_ptr2(hmac_vap, nbw_mode_switch_info)) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    mac_vap = &(hmac_vap->st_vap_base_info);
    if (mac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    ret = hmac_nbw_send_mode_switch_notify_action(peer_addr, nbw_mode_switch_info);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, 0, "hmac_nbw_start_mode_switch::send_mode_switch_notify_action failed[%d].", ret);
        return ret;
    }
    if (nbw_mode_switch_info->req_timer.en_is_registerd != OAL_TRUE) {
        /* 设置时隙请求等待超时器 */
        frw_timer_create_timer_m(&(nbw_mode_switch_info->req_timer),
            hmac_nbw_waiting_mode_switch_rsp_timeout, WAITTING_TWO_DURATION_MS,
            peer_addr, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
    }
    /* 下发模式切换事件 */
    nbw_pwr_switch.band = nbw_mode_switch_info->channel_info.en_band;
    nbw_pwr_switch.bw_mode = nbw_mode_switch_info->channel_info.en_bandwidth;
    nbw_pwr_switch.channel_num = nbw_mode_switch_info->channel_info.uc_chan_number;
    nbw_pwr_switch.pwr_flag = nbw_mode_switch_info->pwr_level;
    ret = hmac_nbw_set_pwr_switch(mac_vap, sizeof(nbw_demo_pwr_switch_stru), (uint8_t *)(&nbw_pwr_switch));
    if (ret != OAL_SUCC) {
        oam_error_log1(0, 0, "hmac_nbw_start_mode_switch::set_pwr_switch failed[%d].", ret);
        return ret;
    }
    return OAL_SUCC;
}

void hmac_nbw_rx_chan_switch_notify_action(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint8_t sa_len, uint8_t *payload,
    uint16_t payload_len)
{
    mac_vap_stru *mac_vap = NULL;
    hmac_nbw_mode_switch_notify_stru *nbw_mode_switch_info = hmac_get_nbw_mode_switch_info();
    nbw_demo_pwr_switch_stru nbw_pwr_switch = {};
    uint32_t ret = OAL_SUCC;

    mac_vap = &(hmac_vap->st_vap_base_info);
    if (mac_vap == NULL) {
        return;
    }
    if (payload_len < BYTE_OFFSET_2 || (*payload) != MAC_NBW_ATTR_MODE_SWITCH) {
        oam_warning_log2(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
            "hmac_nbw_rx_chan_switch_notify_action::error payload_len[%d] attribute type[%d].", payload_len, *payload);
        return;
    }

    if (MAC_NBW_ATTR_HDR_LEN + payload[MAC_NBW_ATTR_ID_LEN] < MAC_NBW_MODE_SWITCH_ATTR_LEN) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
            "hmac_nbw_rx_chan_switch_notify_action::csa attr len[%d] invalid.", payload[MAC_NBW_ATTR_ID_LEN]);
        return;
    }
    payload = payload + MAC_NBW_ATTR_HDR_LEN;
    /* NBW只处理信道切换req，rsp帧device处理，不上报host */
    if ((*payload) != MAC_CHBA_CHAN_SWITCH_REQ) {
        return;
    }
    nbw_mode_switch_info->notify_type = MAC_CHBA_CHAN_SWITCH_RESP;
    payload++;
    nbw_mode_switch_info->channel_info.en_band = *payload;
    payload++;
    nbw_mode_switch_info->channel_info.uc_chan_number = *payload;
    payload++;
    nbw_mode_switch_info->channel_info.en_bandwidth = *payload;
    payload++;
    nbw_mode_switch_info->pwr_level = *payload;

    oam_warning_log4(0, OAM_SF_NBW, "hmac_nbw_rx_chan_switch_notify_action::type[%d], chn[%d], bw[%d], pwr_lvl[%d]",
        nbw_mode_switch_info->notify_type, nbw_mode_switch_info->channel_info.uc_chan_number,
        nbw_mode_switch_info->channel_info.en_bandwidth, nbw_mode_switch_info->pwr_level);
    /* 下发模式切换事件 */
    nbw_pwr_switch.band = nbw_mode_switch_info->channel_info.en_band;
    nbw_pwr_switch.bw_mode = nbw_mode_switch_info->channel_info.en_bandwidth;
    nbw_pwr_switch.channel_num = nbw_mode_switch_info->channel_info.uc_chan_number;
    nbw_pwr_switch.pwr_flag = nbw_mode_switch_info->pwr_level;
    ret += hmac_nbw_set_pwr_switch(mac_vap, sizeof(nbw_demo_pwr_switch_stru), (uint8_t *)(&nbw_pwr_switch));
    /* 组模式切换rsp帧下发 */
    ret += hmac_nbw_send_mode_switch_notify_action(sa_addr, nbw_mode_switch_info);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, 0, "hmac_nbw_rx_chan_switch_notify_action::set_pwr_switch failed[%d].", ret);
        return;
    }
}

uint32_t hmac_mode_switch_result_notify(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    hmac_nbw_mode_switch_notify_stru *nbw_mode_switch_info = hmac_get_nbw_mode_switch_info();

    if (nbw_mode_switch_info->req_timer.en_is_registerd) {
        frw_timer_immediate_destroy_timer_m(&(nbw_mode_switch_info->req_timer));
    }
    return OAL_SUCC;
}
#endif
#endif