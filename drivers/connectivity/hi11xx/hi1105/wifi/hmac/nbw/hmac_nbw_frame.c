/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: nbw frame encap and trx
 * Author: wifi
 * Create: 2024-12-26
 */
#include "hmac_nbw_frame.h"
#include "securec.h"
#include "securectype.h"
#include "oal_cfg80211.h"
#include "wlan_types.h"
#include "mac_device.h"
#include "hmac_mgmt_sta_up.h"
#include "mac_ie.h"
#include "hmac_encap_frame_sta.h"
#include "hmac_encap_frame_ap.h"
#include "hmac_mgmt_bss_comm.h"
#include "mac_frame_inl.h"
#include "mac_function.h"
#include "mac_mib_sta_config.h"
#include "hmac_chba_frame.h"
#include "hmac_chba_function.h"
#include "hmac_nbw_mgmt.h"
#include "hmac_nbw_connect.h"
#include "hmac_nbw_sync.h"
#include "hmac_chba_fsm.h"
#include "hmac_chba_sync.h"
#include "oam_event_wifi.h"
#include "hmac_nbw_master_election.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_FRAME_C

#ifdef _PRE_WLAN_FEATURE_NBW
oal_bool_enum_uint8 hmac_nbw_is_nbw_action(uint8_t *payload, uint32_t payload_len)
{
    /*
     *                       NBW Action
     * | category |  nbw oui   | oui type | NBW Attributes |
     * |     1    |     3      |     1    |     variable    |
     * |    127   |   00-E0-FC |   0x99   |                 |
     */
    uint8_t nbw_oui[MAC_OUI_LEN] = { 0x00, 0xE0, 0xFC };

    if (payload_len < MAC_NBW_ACTION_HDR_LEN) {
        return OAL_FALSE;
    }

    if (((payload[0] != MAC_ACTION_CATEGORY_VENDOR) &&
        (payload[0] != MAC_ACTION_CATEGORY_VENDOR_SPECIFIC_PROTECTED)) ||
        oal_memcmp(payload + 1, nbw_oui, MAC_OUI_LEN) != 0  ||
        payload[MAC_NBW_ACTION_OUI_TYPE_LEN] != MAC_OUI_TYPE_NBW) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}


void mac_set_nbw_action_hdr(uint8_t *action_buf, uint8_t action_type)
{
    if (oal_any_null_ptr1(action_buf)) {
        return;
    }
    /* 目前都是单播帧，所以都protected */
    action_buf[0] = MAC_ACTION_CATEGORY_VENDOR_SPECIFIC_PROTECTED; /* vendor-specific protected action */

    action_buf[BYTE_OFFSET_1] = 0x00; /* 1: oui[0] */
    action_buf[BYTE_OFFSET_2] = 0xE0; /* 2: oui[1] */
    action_buf[BYTE_OFFSET_3] = 0xFC; /* 3: oui[2] */
    action_buf[BYTE_OFFSET_4] = MAC_OUI_TYPE_NBW;
    action_buf[BYTE_OFFSET_5] = action_type;
}

static uint32_t hmac_nbw_set_nbw_timeslot_response_action_attr(uint8_t *attr_buf, uint8_t *offset, uint8_t *slave_addr,
    hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t idx = *offset;
    if (timeslot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        attr_buf[idx++] = MAC_NBW_REJECT;
        oam_warning_log0(0, OAM_SF_ANY,
            "{hmac_nbw_set_nbw_timeslot_response_action_attr:reject");
        /* 拒绝也带上slave mac地址，在解析时封装好处理 */
        if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN) != EOK) {
            return OAL_FAIL;
        }
        idx += WLAN_MAC_ADDR_LEN;
    } else {
        attr_buf[idx++] = MAC_NBW_ACCEPT;
        if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN) != EOK) {
            return OAL_FAIL;
        }
        idx += WLAN_MAC_ADDR_LEN;
        attr_buf[idx++] = 0;
        attr_buf[idx++] = 0;
#ifdef _PRE_WLAN_NBW_DEMO
        attr_buf[idx++] = NBW_SLOT_LEVEL_1;
#else
        attr_buf[idx++] = timeslot_info.slot_period_level;
#endif
        attr_buf[idx++] = timeslot_info.uslot_info.start_idx;
        attr_buf[idx++] = timeslot_info.uslot_info.end_idx;
        attr_buf[idx++] = timeslot_info.uslot_info.work_uslot_bitmap;
    }
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static uint32_t hmac_nbw_set_nbw_timeslot_request_action_attr(uint8_t *attr_buf, uint8_t *offset, uint8_t *slave_addr,
    hmac_nbw_slot_info_stru timeslot_info)
{
    hmac_chba_sync_info *nbw_sync_info = hmac_nbw_get_sync_info();
    uint8_t idx = *offset;
    if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN) != EOK) {
        return OAL_FAIL;
    }
    idx += WLAN_MAC_ADDR_LEN;
    /* 填写RP字段 */
    if (memcpy_s(attr_buf + idx, sizeof(nbw_ranking_priority),
        &nbw_sync_info->nbw_rp_info, sizeof(nbw_ranking_priority)) != EOK) {
        return OAL_FAIL;
    }
    idx += (uint8_t)sizeof(nbw_ranking_priority);
    attr_buf[idx++] = 0;
#ifdef _PRE_WLAN_NBW_DEMO
    attr_buf[idx++] = NBW_SLOT_LEVEL_1;
#else
    attr_buf[idx++] = timeslot_info.slot_period_level;
#endif
    attr_buf[idx++] = timeslot_info.uslot_info.timeslot_interval;
    attr_buf[idx++] = timeslot_info.uslot_info.start_idx;
    attr_buf[idx++] = timeslot_info.uslot_info.end_idx;
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static uint32_t hmac_nbw_set_nbw_timeslot_indicate_action_attr(uint8_t *attr_buf,
    uint8_t *offset, uint8_t *master_addr, hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t idx = *offset;
    if (timeslot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        attr_buf[idx++] = MAC_NBW_REJECT;
    } else {
        attr_buf[idx++] = MAC_NBW_ACCEPT;
        if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, master_addr, WLAN_MAC_ADDR_LEN) != EOK) {
            return OAL_FAIL;
        }
        idx += WLAN_MAC_ADDR_LEN;
        attr_buf[idx++] = 0;
#ifdef _PRE_WLAN_NBW_DEMO
        attr_buf[idx++] = NBW_SLOT_LEVEL_1;
#else
        attr_buf[idx++] = timeslot_info.slot_period_level;
#endif
        attr_buf[idx++] = timeslot_info.uslot_info.start_idx;
        attr_buf[idx++] = timeslot_info.uslot_info.end_idx;
        attr_buf[idx++] = timeslot_info.uslot_info.work_uslot_bitmap;
    }
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static uint32_t hmac_nbw_set_nbw_timeslot_sync_request_action_attr(uint8_t *attr_buf, uint8_t *offset)
{
    uint8_t idx = *offset;
    uint8_t cur_island_need_total_uslot = 0, cur_link_cnt = 0;
    uint8_t slot_idx, tmp_uslot_bitmap;
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *current_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(NBW_WORK_MODE);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(NBW_WORK_MODE);
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();
    /* 填slaveaprp值 */
    memcpy_s(attr_buf + idx, sizeof(nbw_ranking_priority), &sync_info->own_rp_info, sizeof(nbw_ranking_priority));
    idx += (uint8_t)sizeof(nbw_ranking_priority);
    /* 先跳过总的需要的时隙数的填写 */
    idx++;
    /* 先跳过总链路数 */
    idx++;
    /* 分别填写每个link的地址 */
    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        current_island = &island_node->data;
        if (current_island->owner_device_id != self_conn_info->self_device_id)
            continue;
        for (slot_idx = 0; slot_idx < MAX_ISLAND_SLOT_INFO_NUM; slot_idx++) {
            if (current_island->island_slot_info[slot_idx].use_flag != OAL_TRUE) {
                continue;
            }
            oal_set_mac_addr(attr_buf + idx, current_island->island_slot_info[slot_idx].peer_device_mac);
            tmp_uslot_bitmap = current_island->island_slot_info[slot_idx].uslot_info.uslot_bitmap;
            cur_island_need_total_uslot += hmac_nbw_uslotbitmap_transform_timeinterval(tmp_uslot_bitmap);
            cur_link_cnt++;
            idx += OAL_MAC_ADDR_LEN;
            attr_buf[idx++] = current_island->island_slot_info[slot_idx].uslot_info.shared_flag;
            attr_buf[idx++] = current_island->island_slot_info[slot_idx].slot_period_level;
            attr_buf[idx++] = current_island->island_slot_info[slot_idx].uslot_info.timeslot_interval;
        }
    }
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    attr_buf[TIMESLOT_REQ_AND_SYNC_TOTAL_USLOT_NUM_POS] = cur_island_need_total_uslot;
    attr_buf[TIMESLOT_REQ_AND_SYNC_TOTAL_LINK_CNT_POS] = cur_link_cnt;
    *offset = idx;
    return OAL_SUCC;
}

static void hmac_nbw_set_timeslot_neg_attr(uint8_t *attr_buf, uint16_t *attr_len, uint8_t *slave_addr,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t request_type)
{
    uint8_t offset;
    uint32_t ret = 0;
    attr_buf[0] = MAC_NBW_ATTR_TIMESLOT_INFO;
    offset = MAC_NBW_ATTR_HDR_LEN;
    switch (request_type) {
        case MAC_NBW_TIMESLOT_NEG_REQUEST_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_request_action_attr(attr_buf, &offset, slave_addr, timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_NEG_RESPONSE_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_response_action_attr(attr_buf, &offset, slave_addr, timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_NEG_INDICATE_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_indicate_action_attr(attr_buf, &offset,
                hmac_nbw_get_master_macaddr(), timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_NEG_AND_SYNC_REQUEST_ACTION:
            /* 时隙申请+sync帧需要遍历岛内时隙情况进行填写，所以不用在set的时候携带，调用send接口时timeslot_info填默认值即可，slave_addr填全F */
            ret = hmac_nbw_set_nbw_timeslot_sync_request_action_attr(attr_buf, &offset);
            break;
        default:
            break;
    }
    if (ret == OAL_FAIL) {
        oam_error_log0(0, OAM_SF_NBW, "hmac_nbw_set_timeslot_attr: set attr fail!");
        return;
    }
    *attr_len = offset;
    return;
}

static uint32_t hmac_nbw_set_nbw_timeslot_master_slaveap_adjust_req_action_attr(uint8_t *attr_buf,
    uint8_t *offset, uint8_t *slave_addr, hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t idx = *offset;
    oam_warning_log3(0, OAM_SF_ANY,
        "{hmac_nbw_set_nbw_timeslot_adjust_req_action_attr:slave mac[%02x:XX:XX:XX:%02x:%02x]}",
        slave_addr[MAC_ADDR_0], slave_addr[MAC_ADDR_4],
        slave_addr[MAC_ADDR_5]);

    if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN) != EOK) {
        return OAL_FAIL;
    }
    idx += WLAN_MAC_ADDR_LEN;
    if (hmac_nbw_get_role() == MAC_NBW_SLAVEAP_ROLE) {
        attr_buf[idx++] = 0; /* 如果是slaveap发送，标志位填0，否则填1，即slave发填1，方便demo实现 */
    } else {
        attr_buf[idx++] = 1;
    }
    attr_buf[idx++] = 0;
#ifdef _PRE_WLAN_NBW_DEMO
    attr_buf[idx++] = NBW_SLOT_LEVEL_1;
#else
    attr_buf[idx++] = timeslot_info.slot_period_level;
#endif

    /* 如果是通过时隙调整帧 做时隙资源释放使用，则uslot_info不要填写 */
    if (timeslot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        attr_buf[idx++] = INVALID_TIMESLOT_USLOT_IDX;
        attr_buf[idx++] = INVALID_TIMESLOT_USLOT_IDX;
    } else {
        attr_buf[idx++] = timeslot_info.uslot_info.start_idx;
        attr_buf[idx++] = timeslot_info.uslot_info.end_idx;
    }
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static uint32_t hmac_nbw_set_nbw_timeslot_master_slaveap_adjust_rsp_action_attr(uint8_t *attr_buf,
    uint8_t *offset, uint8_t *slave_addr, hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t idx = *offset;
    if (timeslot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        attr_buf[idx++] = MAC_NBW_REJECT;
        /* 拒绝也带上slave mac地址，在解析时封装好处理 */
        if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN) != EOK) {
            return OAL_FAIL;
        }
        idx += WLAN_MAC_ADDR_LEN;
    } else {
        attr_buf[idx++] = MAC_NBW_ACCEPT;
        if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN) != EOK) {
            return OAL_FAIL;
        }
        idx += WLAN_MAC_ADDR_LEN;
        attr_buf[idx++] = 0; /* delayed work beacon 暂时定成立即生效 */
#ifdef _PRE_WLAN_NBW_DEMO
        attr_buf[idx++] = NBW_SLOT_LEVEL_1;
#else
        attr_buf[idx++] = timeslot_info.slot_period_level;
#endif
        attr_buf[idx++] = timeslot_info.uslot_info.start_idx;
        attr_buf[idx++] = timeslot_info.uslot_info.end_idx;
    }
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static uint32_t hmac_nbw_set_nbw_timeslot_slaveap_slave_adjust_req_action_attr(uint8_t *attr_buf,
    uint8_t *offset, hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t idx = *offset;
    attr_buf[idx++] = 0; /* delayed work beacon 暂时定成立即生效 */
#ifdef _PRE_WLAN_NBW_DEMO
    attr_buf[idx++] = NBW_SLOT_LEVEL_1;
#else
    attr_buf[idx++] = timeslot_info.slot_period_level;
#endif
    attr_buf[idx++] = timeslot_info.uslot_info.start_idx;
    attr_buf[idx++] = timeslot_info.uslot_info.end_idx;
    attr_buf[idx++] = timeslot_info.uslot_info.work_uslot_bitmap;
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static uint32_t hmac_nbw_set_nbw_timeslot_slaveap_slave_adjust_rsp_action_attr(uint8_t *attr_buf,
    uint8_t *offset, hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t idx = *offset;
    if (timeslot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        attr_buf[idx++] = MAC_NBW_REJECT;
    } else {
        attr_buf[idx++] = MAC_NBW_ACCEPT;
        attr_buf[idx++] = 0; /* delayed work beacon 暂时定成立即生效 */
#ifdef _PRE_WLAN_NBW_DEMO
        attr_buf[idx++] = NBW_SLOT_LEVEL_1;
#else
        attr_buf[idx++] = timeslot_info.slot_period_level;
#endif
        attr_buf[idx++] = timeslot_info.uslot_info.start_idx;
        attr_buf[idx++] = timeslot_info.uslot_info.end_idx;
    }
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static uint32_t hmac_nbw_set_nbw_timeslot_inform_borrow_req_action_attr(uint8_t *attr_buf,
    uint8_t *offset, uint8_t *slave_addr, hmac_nbw_slot_info_stru timeslot_info)
{
    hmac_nbw_timeslot_borrow_info_stru *timeslot_borrow_info = hmac_nbw_get_timeslot_borrow_info();
    uint8_t idx = *offset;
    if (memcpy_s(attr_buf + idx, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN) != EOK) {
        return OAL_FAIL;
    }
    idx += WLAN_MAC_ADDR_LEN;
    attr_buf[idx++] = timeslot_info.uslot_info.work_uslot_bitmap; /* 更新后的工作时隙信息 */
    attr_buf[idx++] = timeslot_borrow_info->old_work_timeslot; /* 保存历史工作时隙信息 */
    attr_buf[idx++] = hmac_nbw_get_available_uslot_bitmap();
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}
 
static uint32_t hmac_nbw_set_nbw_timeslot_inform_borrow_rsp_action_attr(uint8_t *attr_buf,
    uint8_t *offset, hmac_nbw_slot_info_stru timeslot_info)
{
    uint8_t idx = *offset;
    attr_buf[idx++] = MAC_NBW_ACCEPT; /* 时隙借用响应当前默认成功 */
    attr_buf[MAC_NBW_ATTR_ID_LEN] = idx - MAC_NBW_ATTR_HDR_LEN;
    *offset = idx;
    return OAL_SUCC;
}

static void hmac_nbw_set_timeslot_adjust_attr(uint8_t *attr_buf, uint16_t *attr_len, uint8_t *slave_addr,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t request_type)
{
    uint8_t offset;
    uint32_t ret = 0;
    attr_buf[0] = MAC_NBW_ATTR_TIMESLOT_INFO;
    offset = MAC_NBW_ATTR_HDR_LEN;
    switch (request_type) {
        case MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_master_slaveap_adjust_req_action_attr(attr_buf, &offset,
                slave_addr, timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_master_slaveap_adjust_rsp_action_attr(attr_buf, &offset,
                slave_addr, timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_slaveap_slave_adjust_req_action_attr(attr_buf, &offset,
                timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_slaveap_slave_adjust_rsp_action_attr(attr_buf, &offset,
                timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_MASTER_INDICATE_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_slaveap_slave_adjust_req_action_attr(attr_buf, &offset,
                timeslot_info); // master时隙调整指示帧当前内容同slave和slaveap时隙调整请求帧
            break;
        case MAC_NBW_TIMESLOT_INFORM_BORROW_REQ_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_inform_borrow_req_action_attr(attr_buf, &offset,
                slave_addr, timeslot_info);
            break;
        case MAC_NBW_TIMESLOT_INFORM_BORROW_RESP_ACTION:
            ret = hmac_nbw_set_nbw_timeslot_inform_borrow_rsp_action_attr(attr_buf, &offset,
                timeslot_info);
            break;
        default:
            break;
    }
    if (ret == OAL_FAIL) {
        oam_error_log0(0, OAM_SF_NBW, "hmac_nbw_set_timeslot_adjust_attr: set attr fail!");
        return;
    }
    *attr_len = offset;
    return;
}

void hmac_nbw_set_timeslot_attr(uint8_t *attr_buf, uint16_t *attr_len, uint8_t *slave_addr,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t action_type, uint8_t request_type)
{
    if (oal_any_null_ptr3(attr_buf, attr_len, slave_addr)) {
        oam_error_log0(0, OAM_SF_NBW, "hmac_nbw_set_timeslot_attr: ptr is NULL!");
        return;
    }
    if (action_type == MAC_NBW_TIMESLOT_NEG_ACTION) {
        hmac_nbw_set_timeslot_neg_attr(attr_buf, attr_len, slave_addr, timeslot_info, request_type);
    } else if (action_type == MAC_NBW_TIMESLOT_ADJUST_ACTION) {
        hmac_nbw_set_timeslot_adjust_attr(attr_buf, attr_len, slave_addr, timeslot_info, request_type);
    } else if (action_type == MAC_NBW_DOMAIN_MERGE_REQUEST_ACTION) {
        return;
    } else {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_set_timeslot_attr: action type error!");
        return;
    }
}

void hmac_nbw_send_timeslot_frame(uint8_t *peer_addr, uint8_t *slave_addr, uint8_t addr_len,
    hmac_nbw_slot_info_stru timeslot_info, uint8_t action_type, uint8_t request_type)
{
    oal_netbuf_stru *timeslot_action_frame = NULL;
    uint8_t *frame_hdr = NULL, *payload = NULL;
    uint16_t mgmt_len = 0, payload_len = 0, attr_len = 0;
    uint32_t ret;
    hmac_chba_vap_stru *chba_vap_info = hmac_get_chba_vap();
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(chba_vap_info->mac_vap_id);
    mac_vap_stru *mac_vap = NULL;
    /* 先用chba vap来实现， 后续可能改成nbw vap */
    if (oal_any_null_ptr3(hmac_vap, peer_addr, slave_addr)) {
        return;
    }
    mac_vap = &hmac_vap->st_vap_base_info;
    timeslot_action_frame = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (timeslot_action_frame == NULL) {
        return;
    }
    oam_warning_log2(0, OAM_SF_NBW, "hmac_nbw_send_timeslot_frame: action type:%d, request type:%d!",
        action_type, request_type);

    oal_mem_netbuf_trace(timeslot_action_frame, OAL_TRUE);
    memset_s(oal_netbuf_cb(timeslot_action_frame), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    /* 封装TIMESLOT Action */
    frame_hdr = (uint8_t *)oal_netbuf_header(timeslot_action_frame);
    /* 将mac header清零 */
    memset_s(frame_hdr, MAC_80211_FRAME_LEN, 0, MAC_80211_FRAME_LEN);
    /* 填写mac头信息 */
    mac_hdr_set_frame_control(frame_hdr, WLAN_PROTOCOL_VERSION | WLAN_FC0_TYPE_MGT | WLAN_FC0_SUBTYPE_ACTION);
    oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR1_OFFSET, peer_addr);
    oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR2_OFFSET, mac_mib_get_StationID(mac_vap));
    if (request_type == MAC_NBW_TIMESLOT_NEG_AND_SYNC_REQUEST_ACTION) {
        oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR3_OFFSET, peer_addr);
    } else {
        oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR3_OFFSET, hmac_nbw_get_master_macaddr());
    }

    mgmt_len += MAC_80211_FRAME_LEN;
    payload = frame_hdr + mgmt_len;
    /* 填写Action 头 */
    mac_set_nbw_action_hdr(payload, action_type);
    payload_len += MAC_CHBA_ACTION_HDR_LEN;
    /* 填写type */
    payload[payload_len] = request_type;
    payload_len++;
    /* 当前没有rp值，时隙复用这些 */
    hmac_nbw_set_timeslot_attr(payload + payload_len, &attr_len, slave_addr, timeslot_info, action_type, request_type);

    payload_len += attr_len;
    mgmt_len += payload_len;
    oal_netbuf_put(timeslot_action_frame, mgmt_len);
    /* 先复用chba的管理帧cb字段初始化 */
    hmac_chba_mgmt_cb_partial_init(mac_vap, peer_addr, timeslot_action_frame, mgmt_len, OAL_FALSE);
    /* 发送TIMESLOT Action帧 */
    ret = hmac_tx_mgmt_send_event(mac_vap, timeslot_action_frame, mgmt_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(timeslot_action_frame);
        return;
    }
}

static hmac_nbw_slot_info_stru hmac_nbw_timeslot_frame_resolve_timeslot_attr(uint8_t *payload,
    uint8_t slot_level_pos, uint8_t start_uslot_idx_pos, uint8_t end_uslot_idx_pos, uint8_t work_uslot_idx_pos)
{
    hmac_nbw_slot_info_stru timeslot_info = { 0 };
    timeslot_info.slot_period_level = *(payload + slot_level_pos);
    timeslot_info.uslot_info.start_idx = *(payload + start_uslot_idx_pos);
    timeslot_info.uslot_info.end_idx = *(payload + end_uslot_idx_pos);
    /* 先不限制start idx和end idx具体的数值, 只强要求end idx要大于等于start idx */
    if (timeslot_info.uslot_info.end_idx < timeslot_info.uslot_info.start_idx) {
        timeslot_info.uslot_info.uslot_bitmap = INVALID_USLOT_BITMAP;
        return timeslot_info;
    }
    timeslot_info.uslot_info.timeslot_interval = timeslot_info.uslot_info.end_idx -
        timeslot_info.uslot_info.start_idx + 1;
    timeslot_info.uslot_info.uslot_bitmap =
        hmac_nbw_convert_idx_to_uslotbitmap_level1(timeslot_info.uslot_info.start_idx,
        timeslot_info.uslot_info.end_idx);
    timeslot_info.uslot_info.work_uslot_bitmap = *(payload + work_uslot_idx_pos);
    return timeslot_info;
}


static void hmac_nbw_timeslot_neg_request_handle(hmac_vap_stru *hmac_vap, uint8_t *payload,
    uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t time_interval;
    uint8_t slave_addr[WLAN_MAC_ADDR_LEN];
    hmac_nbw_island_conn_info_rpt island_conn_info = { 0 };
    hmac_nbw_slot_info_stru *slot_info = &island_conn_info.slot_info;
    if (slot_info == NULL) {
        return;
    }
    if (payload_len < TIMESLOT_REQ_BODY_LEN || hmac_nbw_get_role() != MAC_NBW_MASTER_ROLE) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_neg_request_handle::receive timeslot REQ len invalid or is not master no handle.");
        return;
    }

    if (memcpy_s(slave_addr, WLAN_MAC_ADDR_LEN, payload + TIMESLOT_REQ_SLAVEMAC_POS, WLAN_MAC_ADDR_LEN) != EOK) {
        return;
    }
    /* 获取对端device RP */
    if (memcpy_s((uint8_t *)&island_conn_info.slaveap_rp, sizeof(nbw_ranking_priority),
        payload + TIMESLOT_REQ_SLAVEAP_RP_POS, sizeof(nbw_ranking_priority)) != EOK) {
        return;
    }
    slot_info->slot_period_level = *(payload + TIMESLOT_REQ_SLOT_LEVEL);
    time_interval = *(payload + TIMESLOT_REQ_TIMEINTERVAL_POS);
    /* 先做简化方案，不考虑时隙复用的情况，只要申请时隙的连续长度让当前的uslot-bitmap不满足，则拒绝 */
    slot_info->uslot_info = hmac_nbw_calculate_uslotbitmap(time_interval);
    /* 如果申请不到时隙，则直接发送拒绝帧，结束流程 */
    if (slot_info->uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        hmac_nbw_send_timeslot_frame(peer_addr, slave_addr, OAL_MAC_ADDR_LEN, *slot_info,
            MAC_NBW_TIMESLOT_NEG_ACTION, MAC_NBW_TIMESLOT_NEG_RESPONSE_ACTION);
        return;
    }
    oal_set_mac_addr(slot_info->peer_device_mac, slave_addr);
    hmac_nbw_update_conn_info(hmac_vap, island_conn_info, slave_addr, peer_addr, WLAN_MAC_ADDR_LEN);
    /* 更新最新的Beacon和PNF到Driver */
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_timeslot_neg_request_handle::slaveap mac[%02X:XX:XX:XX:%02X:%02X]}",
        peer_addr[0], peer_addr[BYTE_OFFSET_4],
        peer_addr[BYTE_OFFSET_5]);
    oam_warning_log3(0, OAM_SF_CHBA,
        "{hmac_nbw_timeslot_neg_request_handle::slave mac[%02X:XX:XX:XX:%02X:%02X]}",
        slave_addr[0], slave_addr[BYTE_OFFSET_4],
        slave_addr[BYTE_OFFSET_5]);

    hmac_nbw_send_timeslot_frame(peer_addr, slave_addr, OAL_MAC_ADDR_LEN, *slot_info,
        MAC_NBW_TIMESLOT_NEG_ACTION, MAC_NBW_TIMESLOT_NEG_RESPONSE_ACTION);
}

static uint32_t hmac_nbw_timeslot_neg_response_resolving(hmac_vap_stru *hmac_vap, uint8_t *payload,
    uint16_t payload_len)
{
    uint8_t slave_addr[WLAN_MAC_ADDR_LEN] = { 0 };
    uint8_t status;
    hmac_nbw_island_conn_info_rpt island_conn_info = { 0 };
    hmac_nbw_slot_info_stru *slot_info = &island_conn_info.slot_info;
    if (slot_info == NULL) {
        return OAL_FAIL;
    }
    if (memcpy_s(slave_addr, WLAN_MAC_ADDR_LEN, payload + TIMESLOT_RSP_SLAVEMAC_POS, WLAN_MAC_ADDR_LEN) != EOK) {
        return OAL_FAIL;
    }
    status = *(payload + TIMESLOT_RSP_STATUS_POS);
    /* 如果收到的response不是ACCEPT或者长度不符，则不做处理，直接通知slave拒绝 */
    if (status != MAC_NBW_ACCEPT || payload_len < TIMESLOT_RSP_BODY_LEN) {
        oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
            "hmac_nbw_timeslot_neg_response_resolving reject error");
        hmac_nbw_send_timeslot_frame(slave_addr, slave_addr, OAL_MAC_ADDR_LEN, *slot_info,
            MAC_NBW_TIMESLOT_NEG_ACTION, MAC_NBW_TIMESLOT_NEG_INDICATE_ACTION);
        return OAL_FAIL;
    }
    /* 如果收到的response是接受，则取出对应的时隙，填入岛的时隙管理部分，再通知给slave */
    /* slaverp，单群岛指示等的处理先不考虑 */
    *slot_info = hmac_nbw_timeslot_frame_resolve_timeslot_attr(payload, TIMESLOT_RSP_SLOT_LEVEL_POS,
        TIMESLOT_RSP_START_IDX_POS, TIMESLOT_RSP_END_IDX_POS, TIMESLOT_RSP_WORK_USLOT_IDX_POS);
    if (slot_info->uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_neg_response_resolving uslot bitmap error");
        return OAL_FAIL;
    }
    oal_set_mac_addr(slot_info->peer_device_mac, slave_addr);
    oam_warning_log3(0, OAM_SF_NBW,"hmac_nbw_timeslot_neg_response_resolving uslotbitmap start_idx: %d, end_idx: %d "
        " bitmap: 0x%x", slot_info->uslot_info.start_idx, slot_info->uslot_info.end_idx,
        slot_info->uslot_info.uslot_bitmap);
    /* 更新岛主的时隙管理信息 */
    hmac_nbw_update_conn_info(hmac_vap, island_conn_info, slave_addr,
        mac_mib_get_StationID(&hmac_vap->st_vap_base_info), WLAN_MAC_ADDR_LEN);
    /* 更新最新的Beacon和PNF到Driver */
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
    hmac_nbw_send_timeslot_frame(slave_addr, slave_addr, OAL_MAC_ADDR_LEN, *slot_info, MAC_NBW_TIMESLOT_NEG_ACTION,
        MAC_NBW_TIMESLOT_NEG_INDICATE_ACTION);

    return OAL_SUCC;
}


uint32_t hmac_nbw_encap_sync_domain_info_frame(chba_params_config_stru *chba_params_sync)
{
    master_info master_info = { 0 };
    if (chba_params_sync == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_encap_sync_domain_info_frame::input pointer is null.");
        return OAL_FAIL;
    }

    chba_params_sync->chba_state = hmac_chba_get_sync_state();
    chba_params_sync->chba_role = hmac_nbw_get_role();
    oal_set_mac_addr(chba_params_sync->domain_bssid, hmac_nbw_get_master_macaddr());
    oal_set_mac_addr(master_info.master_addr, hmac_nbw_get_master_macaddr());
    chba_params_sync->master_info = master_info;

    chba_params_sync->info_bitmap |= CHBA_MASTER_INFO | CHBA_STATE | CHBA_ROLE | CHBA_BSSID;
    return OAL_SUCC;
}
/*
 * 功能描述  : 填写NBW SlaveAp下属的Slave Link Info
 * 日    期  : 2025年08月08日
 * 作    者  : wifi
 */
static void hmac_nbw_set_slave_link_info_attr(uint8_t *attr_buf, uint16_t *attr_len)
{
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *current_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(NBW_WORK_MODE);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(NBW_WORK_MODE);
    uint16_t index = 0;
    uint8_t slot_idx;
    attr_buf[index++] = 0; /* 清空slave link cnt字段 */

    /* 分别填写每个link的地址 */
    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        current_island = &island_node->data;
        if (current_island->owner_device_id != self_conn_info->self_device_id)
            continue;
        for (slot_idx = 0; slot_idx < MAX_ISLAND_SLOT_INFO_NUM; slot_idx++) {
            if (current_island->island_slot_info[slot_idx].use_flag == OAL_FALSE)
                continue;
            oal_set_mac_addr(attr_buf + index, current_island->island_slot_info[slot_idx].peer_device_mac);
            attr_buf[0]++; /* link cnt + 1 */
            index += OAL_MAC_ADDR_LEN;
        }
    }
    *attr_len += index;
}

/*
 * 功能描述  : 填写NBW Slaveap Link Info
 * 日    期  : 2025年08月08日
 * 作    者  : wifi
 */
static void hmac_nbw_set_slaveap_link_info_attr(uint8_t *attr_buf, uint16_t *attr_len)
{
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    uint16_t index = 0;
    uint8_t slot_idx;
    attr_buf[index++] = 0; /* 清空slave link cnt字段 */

    /* 分别填写每个link的地址 */
    for (slot_idx = 0; slot_idx < MAX_ISLAND_SLOT_INFO_NUM; slot_idx++) {
        if (slave_slot_info[slot_idx].use_flag == OAL_FALSE)
            continue;
        oal_set_mac_addr(attr_buf + index, slave_slot_info[slot_idx].peer_device_mac);
        attr_buf[0]++; /* link cnt + 1 */
        index += OAL_MAC_ADDR_LEN;
    }
    *attr_len += index;
}
/*
 * 功能描述  : 封装NBW Link Info Attribute
 * 日    期  : 2025年05月08日
 * 作    者  : wifi
 */
static void hmac_nbw_set_link_info_attr(uint8_t *attr_buf, uint16_t *attr_len)
{
    uint16_t index;
    uint8_t nbw_role = hmac_nbw_get_role();

    if (oal_any_null_ptr2(attr_buf, attr_len)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_set_link_info_attr: input pointer is null.");
        return;
    }

    if (nbw_role != MAC_NBW_SLAVEAP_ROLE && nbw_role != MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE
        && nbw_role != MAC_NBW_SLAVE_ROLE) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_set_link_info_attr: not slaveap or slave.");
        return;
    }
    /* Attribute ID */
    attr_buf[0] = MAC_NBW_ATTR_LINK_INFO;
    index = MAC_CHBA_ATTR_HDR_LEN;

    index++; /* 空一格字段，用于填写Recv RSSI */
    attr_buf[index++] = nbw_role == MAC_NBW_SLAVE_ROLE ? NBW_TOPO_NO_CHANGED_INDICATE : hmac_nbw_get_topo_change_flag();

    hmac_nbw_set_slave_link_info_attr(attr_buf + index, &index);
    hmac_nbw_set_slaveap_link_info_attr(attr_buf + index, &index);

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    *attr_len = index;
}


uint32_t hmac_nbw_beacon_frame_sync(hmac_vap_stru *hmac_vap, uint8_t beacon_type)
{
    hmac_chba_vap_stru *chba_vap_info = hmac_get_chba_vap();
    if (oal_any_null_ptr2(hmac_vap, chba_vap_info)) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_beacon_frame_sync::nullptr.");
        return OAL_FAIL;
    }
    /* 封装beacon vendor信息 */
    hmac_nbw_encap_master_slaveap_beacon(chba_vap_info, chba_vap_info->beacon_buf, &chba_vap_info->beacon_buf_len,
        beacon_type);
    hmac_nbw_start_beacon_sync_timer(hmac_vap);
    return OAL_SUCC;
}


uint32_t hmac_nbw_slaveap_slave_pnf_sync(hmac_vap_stru *hmac_vap)
{
    uint16_t total_len = 0;
    uint16_t attr_len = 0;
    hmac_chba_vap_stru *chba_vap_info = hmac_get_chba_vap();
    if (chba_vap_info == NULL) {
        return OAL_FAIL;
    }

    /* 填写Action 头 */
    mac_set_chba_action_hdr(chba_vap_info->pnf_buf, MAC_CHBA_PNF);
    total_len += MAC_CHBA_ACTION_HDR_LEN;

    /* 封装pnf link info信息 */
    hmac_nbw_set_link_info_attr(chba_vap_info->pnf_buf + total_len, &attr_len);
    total_len += attr_len;
    chba_vap_info->pnf_buf_len = total_len;

    hmac_nbw_start_pnf_sync_timer(hmac_vap);
    return OAL_SUCC;
}


uint32_t hmac_nbw_beacon_pnf_sync(hmac_vap_stru *hmac_vap, uint8_t topo_changed)
{
    uint8_t nbw_role;
    /* 更新本设备角色 */
    hmac_nbw_update_self_role(hmac_vap);
    nbw_role = hmac_nbw_get_role();
    if (topo_changed == NBW_TOPO_CHANGED_INDICATE) {
        hmac_nbw_reset_topo_change_flag_timer(hmac_vap);
    }
    if (nbw_role == MAC_NBW_MASTER_ROLE) {
        return hmac_nbw_beacon_frame_sync(hmac_vap, MAC_NBW_BEACON_TYPE_DOMAIN_TOPO);
    } else if (nbw_role == MAC_NBW_SLAVEAP_ROLE || nbw_role == MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE) {
        hmac_nbw_beacon_frame_sync(hmac_vap, MAC_NBW_BEACON_TYPE_ISLAND_TOPO);
        return hmac_nbw_slaveap_slave_pnf_sync(hmac_vap);
    } else if (nbw_role == MAC_NBW_SLAVE_ROLE) {
        return hmac_nbw_slaveap_slave_pnf_sync(hmac_vap);
    }
    return OAL_FAIL;
}


static void hmac_nbw_timeslot_neg_response_handle(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint16_t payload_len)
{
    uint32_t ret;
    uint8_t nbw_role = hmac_nbw_get_role();
    hmac_nbw_current_connect_info_stru *connect_info = hmac_nbw_get_curr_conn_info();
    if (payload_len < TIMESLOT_RSP_MIN_BODY_LEN || (nbw_role != MAC_NBW_SLAVEAP_ROLE &&
        nbw_role != MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE)) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_neg_response_handle::receive timeslot RSP len invalid or no slaveap handle it.");
        return;
    }
    oam_warning_log0(0, OAM_SF_CHBA, "NBW: hmac_nbw_timeslot_neg_response_handle:: slaveap process slot neg response.");

    ret = hmac_nbw_timeslot_neg_response_resolving(hmac_vap, payload, payload_len);
    /* 未申请到时隙时的本端设备处理 */
    if (ret == OAL_FAIL) {
        /* 建链失败处理 */
        hmac_nbw_connect_fail_handler(hmac_vap);
        return;
    }

    /* 停hmac_nbw_waiting_master_slot_time_response_proc 定时器 */
    if (connect_info->assoc_waiting_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(connect_info->assoc_waiting_timer));
    }

    /* 时隙申请完成后，清除当前建链信息 */
    hmac_nbw_clear_curr_conn_info();
}

static uint32_t hmac_nbw_timeslot_neg_indicate_resolving(hmac_vap_stru *hmac_vap, uint8_t *payload,
    uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t master_addr[WLAN_MAC_ADDR_LEN];
    uint8_t status, slot_idx;
    hmac_nbw_slot_info_stru slot_info = { 0 };
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    status = *(payload + TIMESLOT_INDICATE_STATUS_POS);
    /* 如果收到的response报文不是ACCEPT的，则不做处理 */
    if (status != MAC_NBW_ACCEPT || payload_len < TIMESLOT_INDICATE_BODY_LEN) {
        return OAL_FAIL;
    }

    if (memcpy_s(master_addr, WLAN_MAC_ADDR_LEN, payload + TIMESLOT_INDICATE_MASTERMAC_POS,
        WLAN_MAC_ADDR_LEN) != EOK) {
        return OAL_FAIL;
    }
    oal_set_mac_addr(hmac_nbw_get_master_macaddr(), master_addr);
    oam_warning_log3(0, OAM_SF_ANY, "{hmac_nbw_timeslot_neg_indicate_resolving:master mac[%02x:XX:XX:XX:%02x:%02x]}",
        master_addr[MAC_ADDR_0], master_addr[MAC_ADDR_4], master_addr[MAC_ADDR_5]);
    /* 单群岛指示先不处理 */
    slot_info = hmac_nbw_timeslot_frame_resolve_timeslot_attr(payload, TIMESLOT_INDICATE_SLOT_LEVEL_POS,
        TIMESLOT_INDICATE_START_IDX_POS, TIMESLOT_INDICATE_END_IDX_POS, TIMESLOT_INDICATE_WORK_USLOT_POS);
    if (slot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_neg_indicate_resolving uslot bitmap error");
        return OAL_FAIL;
    }
    oam_warning_log4(0, OAM_SF_NBW, "hmac_nbw_timeslot_neg_indicate_resolving uslotbitmap start_idx: %d, end_idx; %d, "
        "bitmap: %x, work: %x", slot_info.uslot_info.start_idx, slot_info.uslot_info.end_idx,
        slot_info.uslot_info.uslot_bitmap, slot_info.uslot_info.work_uslot_bitmap);
    /* 填入时隙管理并配置给固件 */
    /* 因为是时隙申请指示，所以肯定是新增 */
    slot_idx = hmac_nbw_find_unused_link_idx(slave_slot_info);
    if (slot_idx == NBW_INVALID_IDX) {
        return OAL_FAIL;
    }
    if (memcpy_s(slave_slot_info[slot_idx].peer_device_mac, WLAN_MAC_ADDR_LEN,
        peer_addr, WLAN_MAC_ADDR_LEN) != EOK) {
        return OAL_FAIL;
    }
    slave_slot_info[slot_idx].uslot_info = slot_info.uslot_info;
    slave_slot_info[slot_idx].uslot_info.shared_flag = 0;
    slave_slot_info[slot_idx].use_flag = OAL_TRUE;
    hmac_nbw_slave_link_cnt_add();
    hmac_nbw_slave_config_sync_slaveap(hmac_vap);
    /* 向device同步时隙和帧 */
    hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, slave_slot_info[slot_idx], 1, 1);
    return hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
}


static void hmac_nbw_timeslot_neg_indicate_handle(hmac_vap_stru *hmac_vap, uint8_t *payload,
    uint16_t payload_len, uint8_t *peer_addr)
{
    uint32_t ret;
    hmac_user_stru *hmac_user = NULL;
    hmac_nbw_current_connect_info_stru *nbw_curr_info = hmac_nbw_get_curr_conn_info();
    oam_warning_log0(0, OAM_SF_CHBA, "NBW: hmac_nbw_timeslot_neg_indicate_handle start.");
    /* 如果不是建链中、或者不是SLAVE角色、或者对端设备地址不是目标SlaveAp, 则不处理 */
    if (nbw_curr_info->connect_status != MAC_NBW_CONNECT_ASSOC ||
        nbw_curr_info->connect_role != MAC_NBW_SLAVE_ROLE ||
        oal_compare_mac_addr(peer_addr, nbw_curr_info->peer_addr) != 0) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_timeslot_neg_indicate_handle:: not need handle slot indicate.");
        return;
    }

    /* 校验帧长的合法性 */
    if (payload_len < TIMESLOT_INDICATE_BODY_LEN_MIN) {
        oam_error_log0(0, OAM_SF_NBW,
            "NBW: hmac_nbw_timeslot_neg_indicate_handle::receive timeslot IND len invalid.");
        return;
    }

    /* 查找hmac user */
    hmac_user = mac_vap_get_hmac_user_by_addr(&hmac_vap->st_vap_base_info, peer_addr, WLAN_MAC_ADDR_LEN);
    if (hmac_user == NULL) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_timeslot_neg_indicate_handle:: hmac user is null.");
        return;
    }

    /* slave建链初始化完成后，启动定时器等待时隙指示，此处删除定时器 */
    if (hmac_user->chba_user.connect_info.assoc_waiting_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(hmac_user->chba_user.connect_info.assoc_waiting_timer));
    }

    ret = hmac_nbw_timeslot_neg_indicate_resolving(hmac_vap, payload, payload_len, peer_addr);
    if (ret == OAL_FAIL) {
        oam_error_log0(0, OAM_SF_NBW,
            "NBW: hmac_nbw_timeslot_neg_indicate_handle::slot apply failed, report connect failed.");
        /* 时隙申请不成功，上报建链失败 */
        hmac_nbw_connect_fail_handler(hmac_vap);
        return;
    }

    /* 如果已同步并时隙申请完成，清除当前建链信息 */
    if (hmac_chba_get_sync_state() == CHBA_WORK) {
        hmac_nbw_clear_curr_conn_info();
    }
}

static uint32_t hmac_nbw_timeslot_resource_handle(uint8_t *payload, uint16_t payload_len, uint8_t total_link_cnt,
    hmac_nbw_slot_info_stru *slot_info)
{
    uint8_t link_cnt;
    if (payload_len < TIMESLOT_REQ_AND_SYNC_BASIC_TIMESLOT_LEN * total_link_cnt) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_timeslot_resource_handle:: frame length err");
        return OAL_FAIL;
    }
    for (link_cnt = 0; link_cnt < total_link_cnt; link_cnt++) {
        (slot_info + link_cnt)->uslot_info =
 
            hmac_nbw_calculate_uslotbitmap(*(payload + TIMESLOT_REQ_AND_SYNC_TIME_IBNTERVAL_POS));
        /* 如果申请不到时隙, 失败 */
        if ((slot_info + link_cnt)->uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
            oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_resource_handle: apply slot failed");
            return OAL_FAIL;
        }
        oal_set_mac_addr((slot_info + link_cnt)->peer_device_mac, payload);
        (slot_info + link_cnt)->uslot_info.shared_flag = *(payload + TIMESLOT_REQ_AND_SYNC_USLOT_SHARED_POS);
        (slot_info + link_cnt)->slot_period_level = *(payload + TIMESLOT_REQ_AND_SYNC_SLOT_PERIOD_POS);
        payload += TIMESLOT_REQ_AND_SYNC_BASIC_TIMESLOT_LEN;
    }
    return OAL_SUCC;
}

static void hmac_nbw_timeslot_neg_and_sync_request_handle(hmac_vap_stru *hmac_vap, uint8_t *payload,
    uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t total_link_cnt, total_need_uslot_cnt, cur_free_uslot_cnt, link_cnt;
    hmac_nbw_slot_info_stru slot_info[MAX_ISLAND_SLOT_INFO_NUM] = { 0 };
    hmac_nbw_island_conn_info_rpt island_conn_info = { 0 };
    hmac_chba_vap_stru *chba_vap_info = hmac_vap->hmac_chba_vap_info;
    if (hmac_nbw_get_domain_merge_flag() == OAL_TRUE) {
        hmac_nbw_domain_merge_recover_process(hmac_vap);
        return;
    }
    if (chba_vap_info == NULL) {
        return;
    }
    if (payload_len < TIMESLOT_REQ_AND_SYNC_LEN_MIN || (hmac_nbw_get_role() != MAC_NBW_MASTER_ROLE)) {
        oam_warning_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_neg_and_sync_request_handle::receive timeslot sync len valid or no slaveap handle it.");
        return;
    }
    total_need_uslot_cnt = *(payload + TIMESLOT_REQ_AND_SYNC_TOTAL_USLOT_NUM_POS);
    total_link_cnt = *(payload + TIMESLOT_REQ_AND_SYNC_TOTAL_LINK_CNT_POS);
    cur_free_uslot_cnt = EIGHT_LEVEL -
        hmac_nbw_uslotbitmap_transform_timeinterval(hmac_nbw_get_available_uslot_bitmap());
    if (cur_free_uslot_cnt < total_need_uslot_cnt || total_need_uslot_cnt > MAX_ISLAND_SLOT_INFO_NUM) {
        oam_warning_log0(0, OAM_SF_CHBA, "NBW: hmac_nbw_timeslot_neg_and_sync_request_handle:: uslot not enough");
        return;
    }
    /* 如果已经收到过对端设备的时隙申请，不重新申请时隙，直接重新发送beacon */
    if (hmac_nbw_slaveap_exist_in_domain(hmac_vap->st_vap_base_info.work_mode, peer_addr,
        OAL_MAC_ADDR_LEN) == OAL_TRUE) {
        /* 更新最新的Beacon和PNF到Driver */
        hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
        hmac_chba_send_sync_beacon(hmac_vap, hmac_nbw_get_master_macaddr(), OAL_MAC_ADDR_LEN);
        return;
    }
    /* 因为total uslot cnt 最基本条件，还要看是否满足连续时隙情况，依次取出要申请的每条链路的时隙资源信息，看是否能分配再更新 */
    if (hmac_nbw_timeslot_resource_handle(payload + TIMESLOT_REQ_AND_SYNC_LEN_MIN,
        payload_len - TIMESLOT_REQ_AND_SYNC_LEN_MIN, total_link_cnt, slot_info) == OAL_FAIL) {
        oam_warning_log0(0, OAM_SF_CHBA, "NBW: hmac_nbw_timeslot_neg_and_sync_request_handle:: time slot not satisfy");
        return;
    }
    /* NBW拓扑更新流程 */
    for (link_cnt = 0; link_cnt < total_link_cnt; link_cnt++) {
        island_conn_info.slot_info = *(slot_info + link_cnt);
        hmac_nbw_update_conn_info(hmac_vap, island_conn_info, island_conn_info.slot_info.peer_device_mac, peer_addr,
            WLAN_MAC_ADDR_LEN);
    }
    /* 更新最新的Beacon和PNF到Driver */
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
    /* 完成更新后，就通过encap 组一个beacon帧 立即发送 */
    hmac_chba_send_sync_beacon(hmac_vap, hmac_nbw_get_master_macaddr(), OAL_MAC_ADDR_LEN);
}

void hmac_nbw_rx_timeslot_neg_handle(hmac_vap_stru *hmac_vap, uint8_t *peer_addr,
    uint8_t *payload, uint16_t payload_len)
{
    uint8_t request_type;
    if (payload_len < MIN_TIMESLOT_BODY_LEN) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
            "hmac_nbw_rx_timeslot_neg_handle::receive timeslot neg action frame len[%d] invalid.", payload_len);
        return;
    }
    request_type = *payload;
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
        "hmac_nbw_rx_timeslot_neg_handle::receive timeslot neg action frame, subtype is %d.", request_type);
    switch (request_type) {
        case MAC_NBW_TIMESLOT_NEG_REQUEST_ACTION:
            hmac_nbw_timeslot_neg_request_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_NEG_RESPONSE_ACTION:
            hmac_nbw_timeslot_neg_response_handle(hmac_vap, peer_addr, payload + 1, payload_len - 1);
            break;
        case MAC_NBW_TIMESLOT_NEG_INDICATE_ACTION:
            hmac_nbw_timeslot_neg_indicate_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_NEG_AND_SYNC_REQUEST_ACTION:
            hmac_nbw_timeslot_neg_and_sync_request_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        default:
            break;
    }
}


static void hmac_nbw_timeslot_adjust_master_slaveap_req_handler(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t ret, flag;
    uint8_t slave_addr[WLAN_MAC_ADDR_LEN];
	hmac_nbw_island_conn_info_rpt island_conn_info = { 0 };
    hmac_nbw_slot_info_stru *slot_info = &island_conn_info.slot_info;
    hmac_nbw_slot_info_stru send_slot_info = { 0 };
    if (payload_len < TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_BODY_LEN || hmac_nbw_get_role() != MAC_NBW_MASTER_ROLE) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_adjust_master_slaveap_req_handler::len invalid or no master handle it.");
        return;
    }

    if (memcpy_s(slave_addr, WLAN_MAC_ADDR_LEN, payload + TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_SLAVEMAC_POS,
        WLAN_MAC_ADDR_LEN) != EOK) {
        return;
    }
    flag = *(payload + TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_FLAG_POS);
    /* 先做简化方案，不考虑before after，时隙调整直接覆盖，如果start和end都为127，则认为是主动释放资源 */
    slot_info->uslot_info.start_idx = *(payload + TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_START_IDX_POS);
    slot_info->uslot_info.end_idx = *(payload + TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_END_IDX_POS);
    if (slot_info->uslot_info.start_idx == INVALID_TIMESLOT_USLOT_IDX &&
        slot_info->uslot_info.end_idx == INVALID_TIMESLOT_USLOT_IDX) {
        /* 释放该链路的时隙资源 */
        if (flag == 0) {
            hmac_nbw_release_timeslot(hmac_vap, slave_addr, WLAN_MAC_ADDR_LEN, peer_addr, WLAN_MAC_ADDR_LEN);
        } else if (flag == 1) {
            hmac_nbw_release_timeslot(hmac_vap, peer_addr, WLAN_MAC_ADDR_LEN, slave_addr, WLAN_MAC_ADDR_LEN);
        } else {
            oam_error_log0(0, OAM_SF_NBW,
                "hmac_nbw_timeslot_adjust_master_slaveap_req_handler::flag error.");
        }
        return;
    }
    /* 如果是非127，则需要先检查申请调整的interval是否可以被调整，无论能否调整，均要回复 */
    slot_info->slot_period_level = *(payload + TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_SLOT_LEVEL);
    slot_info->uslot_info.timeslot_interval = slot_info->uslot_info.end_idx - slot_info->uslot_info.start_idx + 1;
    slot_info->uslot_info.uslot_bitmap = hmac_nbw_timeslot_interval_transfrom(slot_info->uslot_info.timeslot_interval);
    oal_set_mac_addr(slot_info->peer_device_mac, slave_addr);
    ret = hmac_nbw_master_adjust_timeslot(hmac_vap->st_vap_base_info.work_mode, peer_addr, WLAN_MAC_ADDR_LEN,
        slave_addr, WLAN_MAC_ADDR_LEN, slot_info->uslot_info);
    /* 如果不符合调整条件，则发拒绝帧 */
    if (ret == OAL_FAIL) {
        /* 拒绝帧和接受帧的区别在于uslot_info，拒绝的话，在组帧时会检查bitmap，如果是0，则知道是拒绝 */
        hmac_nbw_send_timeslot_frame(peer_addr, slave_addr, OAL_MAC_ADDR_LEN, send_slot_info,
            MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_ACTION);
    } else {
        /* 目前调整帧不包括master帮助调整，如果接受就直接将申请的ulsot_info带回去 */
        hmac_nbw_update_conn_info(hmac_vap, island_conn_info, slave_addr,
            mac_mib_get_StationID(&hmac_vap->st_vap_base_info), WLAN_MAC_ADDR_LEN);
        /* 更新最新的Beacon和PNF到Driver */
        hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
        hmac_nbw_send_timeslot_frame(peer_addr, slave_addr, OAL_MAC_ADDR_LEN, *slot_info,
            MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_ACTION);
    }
}


static void hmac_nbw_timeslot_adjust_master_slaveap_rsp_handler(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t status;
    uint8_t slave_addr[WLAN_MAC_ADDR_LEN];
    hmac_nbw_island_conn_info_rpt island_conn_info = { 0 };
    hmac_nbw_slot_info_stru *slot_info = &island_conn_info.slot_info;

    if (payload_len < TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_MIN_BODY_LEN ||
        (hmac_nbw_get_role() != MAC_NBW_SLAVEAP_ROLE && hmac_nbw_get_role() != MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE)) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_adjust_master_slaveap_rsp_handler::len invalid or no master handle it.");
        return;
    }
    status = *(payload + TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_STATUS_POS);
    /* 如果status不为accept时，则直接结束，说明：后面要加一个标志来指示是slave发起的还是slaveap发起的 */
    /* 如果是slave发起的，即使是拒绝，也要通知给slave */
    if (status != MAC_NBW_ACCEPT || payload_len < TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_BODY_LEN) {
        return;
    }
    if (memcpy_s(slave_addr, WLAN_MAC_ADDR_LEN, payload + TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_SLAVEMAC_POS,
        WLAN_MAC_ADDR_LEN) != EOK) {
        return;
    }
    /* 如果status是成功，则要通知给slave */
    *slot_info = hmac_nbw_timeslot_frame_resolve_timeslot_attr(payload,
        TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_SLOT_LEVEL_POS, TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_START_IDX_POS,
        TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_END_IDX_POS, TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_WORK_USLOT_POS);
    if (slot_info->uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_adjust_master_slaveap_rsp_handler uslot bitmap error");
        return;
    }
    /* 更新岛主的时隙管理信息, 因为是时隙调整，找到之前的时隙资源，直接覆盖 */
    oal_set_mac_addr(slot_info->peer_device_mac, slave_addr);
    hmac_nbw_update_conn_info(hmac_vap, island_conn_info, slave_addr,
        mac_mib_get_StationID(&hmac_vap->st_vap_base_info), WLAN_MAC_ADDR_LEN);
    /* 更新最新的Beacon和PNF到Driver */
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
    hmac_nbw_send_timeslot_frame(slave_addr, slave_addr, OAL_MAC_ADDR_LEN, *slot_info,
        MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_ACTION);
}


static void hmac_nbw_timeslot_adjust_slave_slaveap_req_handle(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    hmac_nbw_slot_info_stru slot_info = { 0 };

    if (payload_len < TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_BODY_LEN || hmac_nbw_get_role() != MAC_NBW_SLAVEAP_ROLE) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_adjust_slave_slaveap_req_handle::len invalid or no master handle it.");
        return;
    }
    slot_info.slot_period_level = *(payload + TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_SLOT_LEVEL_POS);
    slot_info.uslot_info.start_idx = *(payload + TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_START_IDX_POS);
    slot_info.uslot_info.end_idx = *(payload + TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_END_IDX_POS);
    /* 需要补充组帧内容，目前没实现 */
    hmac_nbw_send_timeslot_frame(hmac_nbw_get_master_macaddr(), peer_addr, OAL_MAC_ADDR_LEN, slot_info,
        MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_ACTION);
}


static void hmac_nbw_timeslot_adjust_slave_slaveap_rsp_handler(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t status, slot_idx;
    hmac_nbw_slot_info_stru slot_info = { 0 };
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();

    if (payload_len < TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_MIN_BODY_LEN || hmac_nbw_get_role() != MAC_NBW_SLAVE_ROLE) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_adjust_slave_slaveap_rsp_handler::len invalid or no master handle it.");
        return;
    }
    status = *(payload + TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_STATUS_POS);
    /* 此次slave发起的时隙调整失败 */
    if (status != MAC_NBW_ACCEPT || payload_len < TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_BODY_LEN) {
        return;
    }
    /* 如果status是成功，则取出新的bitmap info, 填入时隙资源并配给固件 */
    slot_info = hmac_nbw_timeslot_frame_resolve_timeslot_attr(payload,
        TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_SLOT_LEVEL_POS, TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_START_IDX_POS,
        TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_END_IDX_POS, TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_WORL_USLOT_POS);
    if (slot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_adjust_slave_slaveap_rsp_handler uslot bitmap error");
        return;
    }
    slot_idx = hmac_nbw_find_slot_link_idx(slave_slot_info, peer_addr);
    if (slot_idx == NBW_INVALID_IDX) {
        return;
    }
    hmac_nbw_update_uslot_bitmap_for_link_disconnect(slave_slot_info[slot_idx].uslot_info.uslot_bitmap);
    slave_slot_info[slot_idx].uslot_info = slot_info.uslot_info;
    hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, slave_slot_info[slot_idx], 1, 1);
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
}


static void hmac_nbw_timeslot_adjust_master_indicate_handle(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t slot_idx;
    hmac_nbw_slot_info_stru slot_info = { 0 };
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();

    if (payload_len < TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_BODY_LEN || hmac_nbw_get_role() != MAC_NBW_SLAVE_ROLE) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_adjust_master_indicate_handle::len invalid or no master handle it.");
        return;
    }
    slot_info = hmac_nbw_timeslot_frame_resolve_timeslot_attr(payload, TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_SLOT_LEVEL_POS,
        TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_START_IDX_POS, TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_END_IDX_POS,
        TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_WORK_USLOT_IDX_POS);
    if (slot_info.uslot_info.uslot_bitmap == INVALID_USLOT_BITMAP) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_adjust_master_indicate_handle uslot bitmap error");
        return;
    }
    slot_idx = hmac_nbw_find_slot_link_idx(slave_slot_info, peer_addr);
    if (slot_idx == NBW_INVALID_IDX) {
        return;
    }
    hmac_nbw_update_uslot_bitmap_for_link_disconnect(slave_slot_info[slot_idx].uslot_info.uslot_bitmap);
    slave_slot_info[slot_idx].uslot_info = slot_info.uslot_info;
    hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, slave_slot_info[slot_idx], 1, 1);
    hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
}

static void hmac_nbw_timeslot_borrow_req_handle_by_slaveap(hmac_vap_stru *hmac_vap, uint8_t *slave_addr,
    hmac_nbw_slot_info_stru slot_info, uint8_t old_work_uslot)
{
    hmac_nbw_timeslot_borrow_info_stru *timeslot_borrow_info = hmac_nbw_get_timeslot_borrow_info();
    hmac_chba_sync_info *sync_info = hmac_nbw_get_sync_info();

    /* 若已有时隙借用通知，停止之前的通知定时器，重新按最新的时隙发送 */
    if (sync_info->timeslot_borrow_timer.en_is_registerd) {
        oam_warning_log0(0, OAM_SF_CHBA,
            "{hmac_nbw_timeslot_borrow_req_handle_by_slaveap::timeslot borrow notify is ongoing}");
        frw_timer_immediate_destroy_timer_m(&(sync_info->timeslot_borrow_timer));
    }

    /* 初始化时隙借用信息，并向存在借用的设备发送借用通知 */
    memset_s(timeslot_borrow_info, sizeof(hmac_nbw_timeslot_borrow_info_stru),
        0, sizeof(hmac_nbw_timeslot_borrow_info_stru));
    oal_set_mac_addr(timeslot_borrow_info->peer_addr, slave_addr);
    oal_set_mac_addr(timeslot_borrow_info->slave_addr, slave_addr);
    timeslot_borrow_info->send_slot_info.uslot_info = slot_info.uslot_info;
    timeslot_borrow_info->old_work_timeslot = old_work_uslot;
    timeslot_borrow_info->request_flag = NBW_SLAVEAP_SLAVE_TIMESLOT_BORROW;
    hmac_nbw_send_timeslot_frame(slave_addr, slave_addr, OAL_MAC_ADDR_LEN, timeslot_borrow_info->send_slot_info,
        MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_INFORM_BORROW_REQ_ACTION);

    frw_timer_create_timer_m(&sync_info->timeslot_borrow_timer, hmac_nbw_timeslot_borrow_wait_timeout,
        MAC_NBW_DEFALUT_PERIODS_MS, hmac_vap, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);
}


static void hmac_nbw_timeslot_borrow_req_handle(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    hmac_nbw_slot_info_stru slot_info = { 0 };
    uint8_t slave_addr[WLAN_MAC_ADDR_LEN];
    uint8_t local_role = hmac_nbw_get_role();
    uint8_t old_work_uslot, domain_alloc_bitmap;

    /* master设备不处理该消息 */
    if (payload_len < TIMESLOT_ADJUST_INFORM_BORROW_REQ_BODY_LEN || local_role == MAC_NBW_MASTER_ROLE) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_borrow_req_handle::len invalid or master do not handle this action.");
        return;
    }

    /* 获取新的工作时隙信息 */
    slot_info.uslot_info.work_uslot_bitmap = *(payload + TIMESLOT_ADJUST_INFORM_BORROW_REQ_WORK_USLOT_POS);
    old_work_uslot = *(payload + TIMESLOT_ADJUST_INFORM_BORROW_REQ_OLD_WORK_USLOT_POS);
    domain_alloc_bitmap = *(payload + TIMESLOT_ADJUST_INFORM_BORROW_REQ_DOMAIN_USLOT_POS);
    oam_warning_log4(0, OAM_SF_NBW, "hmac_nbw_timeslot_borrow_req_handle::local role:[%d], work slot:[%x], "
        "old work slot:[%x], domain alloc:[%x]", local_role, slot_info.uslot_info.work_uslot_bitmap,
        old_work_uslot, domain_alloc_bitmap);

    /* 根据master发的全域时隙，更新本设备上保存的全域时隙 */
    hmac_nbw_set_alloc_uslot_bitmap(domain_alloc_bitmap);

    /* slave收到通知时隙借用帧后，回复resp, 并直接下发新的工作时隙给device */
    if (local_role == MAC_NBW_SLAVE_ROLE) {
        oal_set_mac_addr(slot_info.peer_device_mac, peer_addr);
        hmac_nbw_send_timeslot_frame(peer_addr, peer_addr, OAL_MAC_ADDR_LEN, slot_info,
            MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_INFORM_BORROW_RESP_ACTION);
        /* 岛域的时隙信息在后续收到beacon后更新，不在此处更新 */
        hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, slot_info, 1, 1);
        return;
    }

    /* slaveAp收到master发送的停止时隙借用帧后回复resp，并向关联的slave设备发送时隙借用通知，master已经算好了工作时隙 */
    if (local_role == MAC_NBW_SLAVEAP_ROLE) {
        if (memcpy_s(slave_addr, WLAN_MAC_ADDR_LEN, payload + TIMESLOT_ADJUST_INFORM_BORROW_REQ_SLAVEMAC_POS,
            WLAN_MAC_ADDR_LEN) != EOK) {
            return;
        }
        hmac_nbw_send_timeslot_frame(peer_addr, peer_addr, OAL_MAC_ADDR_LEN, slot_info,
            MAC_NBW_TIMESLOT_ADJUST_ACTION, MAC_NBW_TIMESLOT_INFORM_BORROW_RESP_ACTION);
        oal_set_mac_addr(slot_info.peer_device_mac, slave_addr);
        hmac_nbw_timeslot_borrow_req_handle_by_slaveap(hmac_vap, slave_addr, slot_info, old_work_uslot);
        return;
    }
}


static void hmac_nbw_timeslot_borrow_rsp_handle(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    uint8_t status;
    uint8_t local_role = hmac_nbw_get_role();
    hmac_nbw_timeslot_borrow_info_stru *timeslot_borrow_info = hmac_nbw_get_timeslot_borrow_info();
    if (payload_len < TIMESLOT_ADJUST_INFORM_BORROW_RESP_BODY_LEN || local_role == MAC_NBW_SLAVE_ROLE) {
        oam_error_log0(0, OAM_SF_NBW,
            "hmac_nbw_timeslot_borrow_rsp_handle::len invalid or no master/slaveap handle it.");
        return;
    }

    status = *(payload + TIMESLOT_ADJUST_INFORM_BORROW_RESP_STATUS_POS);
    /* 此次master/slaveap发起的时隙借用通知失败 */
    if (status != MAC_NBW_ACCEPT) {
        oam_error_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_borrow_rsp_handle::status is err.");
        return;
    }

    /* master/slaveap收到对端rsp，停止定时器 */
    timeslot_borrow_info->confirm_flag = OAL_TRUE;

    if (local_role == MAC_NBW_MASTER_ROLE) {
        /* 若收到的是关联的slave设备回复的rsp，master向device下发停止时隙借用 */
        if (timeslot_borrow_info->request_flag == NBW_MASTER_SLAVE_TIMESLOT_BORROW) {
            hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, timeslot_borrow_info->send_slot_info, 1, 1);
        } else if (timeslot_borrow_info->request_flag == NBW_MASTER_SLAVEAP_TIMESLOT_BORROW) {
            /* master收到slaveap的rsp，不做处理 */
            oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_timeslot_borrow_rsp_handle::recv slaveap resp.");
            return;
        }
    }

    if (local_role == MAC_NBW_SLAVEAP_ROLE) {
        /* slaveAp收到关联slave回复的rsp，向device下发停止时隙借用，slaveap无需向master回复resp */
        if (timeslot_borrow_info->request_flag == NBW_SLAVEAP_SLAVE_TIMESLOT_BORROW) {
            hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, timeslot_borrow_info->send_slot_info, 1, 1);
        }
    }

    oam_warning_log2(0, OAM_SF_NBW, "hmac_nbw_timeslot_borrow_rsp_handle::recv rsp end, request_flag:[%d], "
        "new work timeslot:[%x].", timeslot_borrow_info->request_flag,
        timeslot_borrow_info->send_slot_info.uslot_info.work_uslot_bitmap);
}


void hmac_nbw_rx_timeslot_adjust_handle(hmac_vap_stru *hmac_vap, uint8_t *peer_addr,
    uint8_t *payload, uint16_t payload_len)
{
    uint8_t request_type;
    if (payload_len < MIN_TIMESLOT_BODY_LEN) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
            "hmac_nbw_rx_timeslot_adjust_handle::receive timeslot action frame len[%d] invalid.", payload_len);
        return;
    }
    request_type = *payload;
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
        "hmac_nbw_rx_timeslot_req_handle::receive timeslot action frame, subtype is %d.", request_type);
    /* 先不考虑before after，一条链对应一个连续时隙段 */
    switch (request_type) {
        case MAC_NBW_TIMESLOT_ADJUST_SLAVE_SLAVEAP_REQ_ACTION:
            hmac_nbw_timeslot_adjust_slave_slaveap_req_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_SLAVE_SLAVEAP_RSP_ACTION:
            hmac_nbw_timeslot_adjust_slave_slaveap_rsp_handler(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_REQ_ACTION:
            hmac_nbw_timeslot_adjust_master_slaveap_req_handler(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_MASTER_SLAVEAP_RSP_ACTION:
            hmac_nbw_timeslot_adjust_master_slaveap_rsp_handler(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_ADJUST_MASTER_INDICATE_ACTION:
            hmac_nbw_timeslot_adjust_master_indicate_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_INFORM_BORROW_REQ_ACTION:
            hmac_nbw_timeslot_borrow_req_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_TIMESLOT_INFORM_BORROW_RESP_ACTION:
            hmac_nbw_timeslot_borrow_rsp_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        default:
            break;
    }
}


static void hmac_nbw_domain_merge_req_handle(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    /* 收到域合并的请求，在07c上也是作为测量的一个触发源,  建议直接发起nbw干扰测量 */
    hmac_nbw_interfere_trigger_handler(hmac_vap);
}

static void hmac_nbw_domain_merge_status_allawake_req_handler(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    /* 目前收到全醒帧后，设置进入域合并的flag，然后通知给device */
    hmac_nbw_set_all_awake_flag(OAL_TRUE);
    hmac_sync_nbw_domain_merge_flag(&hmac_vap->st_vap_base_info);
}

static void hmac_nbw_domain_merge_status_allawake_rsp_handler(hmac_vap_stru *hmac_vap,
    uint8_t *payload, uint16_t payload_len, uint8_t *peer_addr)
{
    /* SLAVEAP收到rsp确认后，在07c上不做特殊处理，主要是用来进行重传保护，确保所有slave都awake */
}


void hmac_nbw_rx_domain_merge_action_handle(hmac_vap_stru *hmac_vap, uint8_t *peer_addr,
    uint8_t *payload, uint16_t payload_len, uint8_t array_len)
{
    uint8_t request_type;
    if (payload_len < DOMAIN_MERGE_ACTION_MIN_LEN) {
        oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
            "hmac_nbw_rx_domain_merge_action_handle::receive domain merge frame len[%d] invalid.", payload_len);
        return;
    }
    request_type = *payload;
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
        "hmac_nbw_rx_domain_merge_action_handle::receive domain merge frame, subtype is %d.", request_type);
    /* 先不考虑before after，一条链对应一个连续时隙段 */
    switch (request_type) {
        case MAC_NBW_DOMAIN_MERGE_REQ_ACTION:
            hmac_nbw_domain_merge_req_handle(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_DOMAIN_MERGE_RSP_ACTION:
            /* 目前domain merge req为指示，不需要rsp，保留rsp的扩展性，暂时不实现 */
            break;
        case MAC_NBW_DOMAIN_MERGE_STATUS_ALLAWAKE_REQ_ACTION:
            hmac_nbw_domain_merge_status_allawake_req_handler(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        case MAC_NBW_DOMAIN_MERGE_STATUS_ALLAWAKE_RSP_ACTION:
            hmac_nbw_domain_merge_status_allawake_rsp_handler(hmac_vap, payload + 1, payload_len - 1, peer_addr);
            break;
        default:
            break;
    }
}


static void hmac_nbw_beacon_per_slot_info_parsing(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    uint8_t link_cnt, link_idx;
    uint8_t index = 0;
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    hmac_nbw_slot_info_stru new_slot_info = { 0 };
    if (payload == NULL || payload_len < MAC_NBW_ISLAND_HDR_LEN) {
        oam_warning_log1(0, OAM_SF_CHBA, "hmac_nbw_beacon_per_slot_info_parsing::paylen[%d].", payload_len);
        return;
    }
    link_cnt = payload[1];
    link_idx = hmac_nbw_find_slot_link_idx(slave_slot_info, peer_addr);
    if (link_idx == NBW_INVALID_IDX || payload_len < (MAC_NBW_ISLAND_HDR_LEN + link_cnt * MAC_NBW_SLOT_INFO_LEN)) {
        oam_warning_log0(0, 0, "hmac_nbw_beacon_per_slot_info_parsing::link no exist or error payload_len");
        return;
    }
    index = MAC_NBW_ISLAND_HDR_LEN;
    while (index < payload_len) {
        if (oal_compare_mac_addr(payload + index, mac_mib_get_StationID(&hmac_vap->st_vap_base_info)) == 0) {
            oal_set_mac_addr(new_slot_info.peer_device_mac, peer_addr);
            index += OAL_MAC_ADDR_LEN;
            new_slot_info.slot_period_level = *(payload + (index++));
            new_slot_info.uslot_info.start_idx = *(payload + (index++));
            new_slot_info.uslot_info.timeslot_interval = *(payload + (index++));
            new_slot_info.uslot_info.shared_flag = *(payload + (index++));
            new_slot_info.uslot_info.work_uslot_bitmap = *(payload + (index++));
            new_slot_info.uslot_info.uslot_bitmap =
                hmac_nbw_convert_idx_to_uslotbitmap_level1(new_slot_info.uslot_info.start_idx,
                new_slot_info.uslot_info.start_idx + new_slot_info.uslot_info.timeslot_interval - 1);
            if (new_slot_info.uslot_info.start_idx + new_slot_info.uslot_info.timeslot_interval > NBW_TOTAL_SLOT_NUM) {
                oam_warning_log0(0, 0, "hmac_nbw_beacon_per_slot_info_parsing::info error");
                return;
            }
            new_slot_info.uslot_info.end_idx = new_slot_info.uslot_info.start_idx
                + new_slot_info.uslot_info.timeslot_interval - 1;
            new_slot_info.use_flag = OAL_TRUE;
            hmac_nbw_update_uslot_bitmap_for_link_disconnect(slave_slot_info[link_idx].uslot_info.uslot_bitmap);
            slave_slot_info[link_idx] = new_slot_info;
            /* 时隙同步到device */
            hmac_nbw_sync_timeslot_info_with_conn(hmac_vap, new_slot_info, 1, 1);
            hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
            return;
        } else {
            index += MAC_NBW_SLOT_INFO_LEN;
        }
    }
}


static void hmac_nbw_beacon_island_info_parsing(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    uint8_t index, island_idx, island_cnt;
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    if (hmac_nbw_find_slot_link_idx(slave_slot_info, hmac_nbw_get_master_macaddr()) == NBW_INVALID_IDX) {
        return;
    }

    if (payload == NULL || payload_len < NBW_MASTER_BEACON_BASIC_INFO_LEN) {
        oam_warning_log1(0, 0, "hmac_nbw_beacon_island_info_parsing::payload_len[%d]", payload_len);
        return;
    }

    if (payload[MAC_NBW_TOPO_CHANGE_POS] == NBW_TOPO_NO_CHANGED_INDICATE) {
        return;
    }
    /* 全域已分配时隙信息更新 */
    hmac_nbw_set_alloc_uslot_bitmap(payload[MAC_NBW_SLOT_BITMAP_ALLOC_POS]);
    island_cnt = payload[NBW_MASTER_BEACON_ISLAND_NUM_POS];
    index = NBW_MASTER_BEACON_BASIC_INFO_LEN;
    for (island_idx = 0; island_idx < island_cnt; island_idx++) {
        if (payload_len < (index + MAC_NBW_ISLAND_INFO_LEN)) {
            oam_warning_log1(0, 0, "hmac_nbw_beacon_island_info_parsing::payload_len[%d]", payload_len);
            return;
        }

        if (oal_compare_mac_addr(payload + index, peer_addr) == 0) { // 当前岛主地址是否是对端设备的MAC地址
            index += MAC_NBW_ISLAND_INFO_HEAD_LEN;
            hmac_nbw_beacon_per_slot_info_parsing(hmac_vap, peer_addr,
                payload + index, payload_len - index);
            index += MAC_NBW_SLOT_INFO_LEN;
            return;
        } else {
            index += (MAC_NBW_ISLAND_INFO_LEN + *(payload + NBW_MASTER_BEACON_SLOT_NUM_POS) * MAC_NBW_SLOT_INFO_LEN);
            oam_warning_log1(0, 0, "hmac_nbw_beacon_island_info_parsing:index[%d]", index);
        }
    }
}

static void hmac_nbw_slave_rx_beacon_proc(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    hmac_nbw_current_connect_info_stru *curr_conn_info =
        (hmac_nbw_current_connect_info_stru *)hmac_nbw_get_curr_conn_info();

    if (payload == NULL || payload_len < NBW_SLAVEAP_BEACON_HDR_SLOTINFO_POS) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_slave_rx_beacon_proc: input pointer is null.");
        return;
    }

    /* 如果当前已同步，则返回 */
    if (hmac_chba_get_sync_state() == CHBA_WORK) {
        return;
    }
    if (oal_compare_mac_addr(curr_conn_info->peer_addr, peer_addr) != 0) {
        return;
    }
    /* 配置同步状态 */
    hmac_chba_set_sync_state(CHBA_WORK);
    hmac_nbw_slave_sync_set(hmac_vap);

    /* 如果slave已获取到时隙指示，清除当前建链信息 */
    if (hmac_nbw_find_slot_link_idx(slave_slot_info, peer_addr) != NBW_INVALID_IDX) {
        hmac_nbw_clear_curr_conn_info();
    } else {
        hmac_nbw_find_slot_link_idx(slave_slot_info, peer_addr);
    }
}

uint32_t hmac_nbw_waiting_master_slot_time_response_proc(void *arg)
{
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)arg;
    hmac_nbw_current_connect_info_stru *nbw_curr_conn_info = hmac_nbw_get_curr_conn_info();
    hmac_user_stru *hmac_user = mac_vap_get_hmac_user_by_addr(&hmac_vap->st_vap_base_info,
        nbw_curr_conn_info->peer_addr, WLAN_MAC_ADDR_LEN);
    if (hmac_user == NULL) {
        oam_error_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_waiting_master_slot_time_response_proc::hmac user is null.");
        return 0;
    }
    hmac_nbw_connect_fail_handler(hmac_vap);
    oam_warning_log0(0, OAM_SF_NBW,
        "NBW: hmac_nbw_waiting_master_slot_time_response_proc::receive timeslot action frame timeout.");
    return 0;
}


static void hmac_nbw_beacon_slaveap_rp_parsing(nbw_ranking_priority slaveap_rp, uint8_t *payload, uint8_t payload_len)
{
    int32_t err;
    if (payload == NULL || payload_len < MAC_NBW_ATTR_RP_LEN) {
        return;
    }
    err = memcpy_s(&slaveap_rp, sizeof(nbw_ranking_priority), payload, sizeof(nbw_ranking_priority));
    if (err != EOK) {
        oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_beacon_slaveap_rp_parsing::memcpy failed, err[%d].", err);
    }
}


static uint8_t hmac_nbw_beacon_island_flag_parsing(uint8_t *payload, uint8_t payload_len)
{
    uint8_t island_flag = MAC_NBW_ISLAND_TYPE_BUTT;
    if (payload == NULL || payload_len < MAC_NBW_ISLAND_FLAG_LEN) {
        return island_flag;
    }

    if (payload[0] >= MAC_NBW_ISLAND_TYPE_BUTT) {
        return island_flag;
    }
    island_flag = payload[0];
    return island_flag;
}


static uint8_t hmac_nbw_beacon_link_cnt_parsing(uint8_t *payload, uint8_t payload_len)
{
    uint8_t link_cnt = 0;
    if (payload == NULL || payload_len < MAC_NBW_ISLAND_FLAG_LEN) {
        return link_cnt;
    }

    if (payload[0] > MAX_ISLAND_SLOT_INFO_NUM) {
        return link_cnt;
    }
    link_cnt = payload[0];
    return link_cnt;
}


static void hmac_nbw_beacon_slot_info_parsing(hmac_nbw_slot_info_stru *slot_info, uint8_t *payload, uint8_t payload_len)
{
    uint8_t index = NBW_BEACON_LINK_SLOT_INFO_POS;
    if (oal_any_null_ptr2(slot_info, payload) || payload_len < MAC_NBW_SLOT_INFO_LEN) {
        return;
    }
    oal_set_mac_addr(slot_info->peer_device_mac, payload);
    slot_info->slot_period_level = payload[index++];
    slot_info->uslot_info.start_idx = payload[index++];
    slot_info->uslot_info.timeslot_interval = payload[index++];
    slot_info->uslot_info.shared_flag = payload[index++];
    slot_info->uslot_info.work_uslot_bitmap = payload[index++];
    slot_info->uslot_info.end_idx = slot_info->uslot_info.start_idx + slot_info->uslot_info.timeslot_interval - 1;
    if (slot_info->uslot_info.start_idx >= NBW_TOTAL_SLOT_NUM || slot_info->uslot_info.timeslot_interval < 1 ||
        slot_info->uslot_info.end_idx >= NBW_TOTAL_SLOT_NUM) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_slot_info_parsing::slot info err.");
        return;
    }
    
    slot_info->uslot_info.uslot_bitmap =
        hmac_nbw_convert_idx_to_uslotbitmap_level1(slot_info->uslot_info.start_idx, slot_info->uslot_info.end_idx);
    payload += MAC_NBW_SLOT_INFO_LEN;
    payload_len -= MAC_NBW_SLOT_INFO_LEN;
}

/*
 * 功能描述  : 清空NBW拓扑管理信息
 * 日    期  : 2021年02月24日
 */
static void hmac_nbw_clear_device_topo_info(uint8_t work_mode)
{
    hmac_chba_alive_device_table_stru *alive_dev_table = hmac_chba_get_alive_device_table(work_mode);
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(work_mode);

    uint32_t *network_topo_addr = hmac_chba_get_network_topo_addr(work_mode);

    /* 哈希表创建失败，直接返回 */
    if (alive_dev_table == NULL) {
        oam_warning_log0(0, OAM_SF_NBW, "NBW: hmac_nbw_clear_device_topo_info::topo no changed, skip.");
        return;
    }

    /* 清空岛信息 */
    hmac_chba_clear_island_info(work_mode, island_info, hmac_chba_island_list_node_free);

    /* 清空设备管理信息 */
    memset_s(network_topo_addr, sizeof(uint32_t) * (MAC_CHBA_MAX_DEVICE_NUM * MAC_CHBA_MAX_BITMAP_WORD_NUM),
        0, sizeof(uint32_t) * (MAC_CHBA_MAX_DEVICE_NUM * MAC_CHBA_MAX_BITMAP_WORD_NUM));

    /* 清空时隙信息 */
    hmac_nbw_reset_timeslot_info(work_mode);
}


uint8_t hmac_nbw_beacon_slaveap_exist_domain_info(uint8_t *payload, uint8_t payload_len, uint8_t *mac_addr,
    uint8_t addr_len)
{
    uint8_t index, island_cnt, island_idx, link_cnt;
    if (oal_any_null_ptr2(payload, mac_addr) || payload_len < MAC_NBW_DOAMIN_HDR_LEN) {
        return OAL_FALSE;
    }
    island_cnt = payload[NBW_MASTER_BEACON_ISLAND_NUM_POS];
    index = MAC_NBW_DOAMIN_HDR_LEN;
    /* 全量更新拓扑信息 */
    for (island_idx = 0; island_idx < island_cnt; island_idx++) {
        if (payload_len < (index + MAC_NBW_ISLAND_INFO_LEN)) {
            oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_beacon_slaveap_exist_domain_info::payload_len[%d].", payload_len);
            return OAL_FALSE;
        }
        if (oal_compare_mac_addr(mac_addr, payload + index) == 0) {
            oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_slaveap_exist_domain_info::find device island.");
            return OAL_TRUE;
        }
        index += (OAL_MAC_ADDR_LEN + MAC_NBW_ATTR_RP_LEN + MAC_NBW_ISLAND_FLAG_LEN);
        link_cnt = hmac_nbw_beacon_link_cnt_parsing(payload + index, payload_len - index);
        index += (MAC_NBW_LINK_CNT_LEN + MAC_NBW_ISLAND_RSV_LEN);

        if (payload_len < (index + link_cnt * MAC_NBW_SLOT_INFO_LEN)) {
            oam_warning_log1(0, OAM_SF_NBW, "hmac_nbw_beacon_slaveap_exist_domain_info::payload_len[%d].", payload_len);
            return OAL_FALSE;
        }
        index += link_cnt * MAC_NBW_SLOT_INFO_LEN;
    }
    return OAL_FALSE;
}
/*
 * 功能描述  : slaveap处理master beacon信息，本岛拓扑是否改变flag置位
 * 日    期  : 2025年05月24日
 */
static void hmac_nbw_beacon_domain_info_parsing(hmac_vap_stru *hmac_vap, uint8_t *payload, uint8_t payload_len)
{
    uint8_t index, island_cnt, island_idx, link_cnt, link_idx;
    uint8_t slaveap_addr[OAL_MAC_ADDR_LEN] = { 0 };
    hmac_chba_per_island_info_stru old_self_island = { 0 };
    hmac_chba_per_island_info_stru new_self_island = { 0 };
    hmac_nbw_island_conn_info_rpt island_conn_info;
    hmac_chba_vap_stru *chba_vap_info = hmac_vap->hmac_chba_vap_info;
    if (oal_any_null_ptr2(chba_vap_info, payload) || payload_len < MAC_NBW_DOAMIN_HDR_LEN) {
        return;
    }

    if (payload[MAC_NBW_TOPO_CHANGE_POS] == NBW_TOPO_NO_CHANGED_INDICATE) {
        return;
    }
    /* 本岛主是否在此master beacon中 */
    if (hmac_nbw_beacon_slaveap_exist_domain_info(payload, payload_len,
        mac_mib_get_StationID(&hmac_vap->st_vap_base_info), OAL_MAC_ADDR_LEN) != OAL_TRUE) {
        return;
    }
    hmac_nbw_get_self_island_info(hmac_vap->st_vap_base_info.work_mode, &old_self_island);
    /* 清空全域拓扑信息 */
    hmac_nbw_clear_device_topo_info(hmac_vap->st_vap_base_info.work_mode);

    /* 全域已分配时隙信息更新 */
    hmac_nbw_set_alloc_uslot_bitmap(payload[MAC_NBW_SLOT_BITMAP_ALLOC_POS]);
    island_cnt = payload[NBW_MASTER_BEACON_ISLAND_NUM_POS];
    index = MAC_NBW_DOAMIN_HDR_LEN;
    /* 全量更新拓扑信息 */
    for (island_idx = 0; island_idx < island_cnt; island_idx++) {
        if (payload_len < (index + MAC_NBW_ISLAND_INFO_LEN)) {
            return;
        }
        oal_set_mac_addr(slaveap_addr, payload + index);
        index += OAL_MAC_ADDR_LEN;
        hmac_nbw_beacon_slaveap_rp_parsing(island_conn_info.slaveap_rp, payload + index, payload_len - index);
        index += MAC_NBW_ATTR_RP_LEN;
        island_conn_info.island_flag = hmac_nbw_beacon_island_flag_parsing(payload + index, payload_len - index);
        index += MAC_NBW_ISLAND_FLAG_LEN;
        link_cnt = hmac_nbw_beacon_link_cnt_parsing(payload + index, payload_len - index);
        index += (MAC_NBW_LINK_CNT_LEN + MAC_NBW_ISLAND_RSV_LEN);

        if (payload_len < (index + link_cnt * MAC_NBW_SLOT_INFO_LEN)) {
            return;
        }
        for (link_idx = 0; link_idx < link_cnt; link_idx ++) {
            hmac_nbw_beacon_slot_info_parsing(&island_conn_info.slot_info, payload + index, payload_len - index);
            hmac_nbw_update_conn_info(hmac_vap, island_conn_info, (payload + index), slaveap_addr, WLAN_MAC_ADDR_LEN);
            index += MAC_NBW_SLOT_INFO_LEN;
        }
    }
    hmac_nbw_get_self_island_info(hmac_vap->st_vap_base_info.work_mode, &new_self_island);
    hmac_nbw_domain_merge_succ_process(hmac_vap, &new_self_island);
    if (oal_memcmp(&new_self_island, &old_self_island, sizeof(hmac_chba_per_island_info_stru)) != 0) {
        hmac_nbw_update_sync_ranking_id(hmac_vap->st_vap_base_info.work_mode);
        /* 更新最新的Beacon和PNF到Driver，且设置拓扑更改flag */
        hmac_nbw_beacon_pnf_sync(hmac_vap, NBW_TOPO_CHANGED_INDICATE);
    }
}

static void hmac_nbw_slaveap_rx_beacon_proc(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    int8_t master_rssi = 0;
    hmac_user_stru *hmac_user = NULL;
    hmac_nbw_current_connect_info_stru *conn_info = hmac_nbw_get_curr_conn_info();
    chba_params_config_stru chba_params_sync = { 0 };
    if (payload == NULL || payload_len < NBW_MASTER_BEACON_ATTR_MIN_LEN) {
        return;
    }

    /* 如果当前已同步，则返回 */
    if (hmac_chba_get_sync_state() == CHBA_WORK) {
        return;
    }

    /* 若收到的master beacon rssi小于阈值，则不选择该master作为域主 */
    master_rssi = (int8_t)(*(payload + NBW_MATSER_BEACON_RSSI_OFFSET));
    if (master_rssi < MASTER_BEACON_MIN_RSSI) {
        oam_warning_log4(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
            "{hmac_nbw_slaveap_rx_beacon_proc:Master %02x:XX:XX:XX:%02x:%02x is too far, beacon rssi:%d}",
            peer_addr[MAC_ADDR_0], peer_addr[MAC_ADDR_4], peer_addr[MAC_ADDR_5], master_rssi);
        return;
    }

    /* 1. slaveap接收master beacon后，停止监听定时器 */
    if (conn_info->assoc_waiting_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(conn_info->assoc_waiting_timer));
    }

    /* 2. 同步master */
    hmac_nbw_set_role(MAC_NBW_SLAVEAP_ROLE);
    oal_set_mac_addr(hmac_nbw_get_master_macaddr(), peer_addr);
    hmac_chba_set_sync_state(CHBA_WORK);
    oam_warning_log3(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_NBW,
        "{hmac_nbw_basic_beacon_handler:become slaveap! Master is %02x:XX:XX:XX:%02x:%02x}",
        peer_addr[MAC_ADDR_0], peer_addr[MAC_ADDR_4], peer_addr[MAC_ADDR_5]);

    chba_params_sync.chba_role = MAC_NBW_SLAVEAP_ROLE;
    oal_set_mac_addr(chba_params_sync.domain_bssid, hmac_nbw_get_master_macaddr());
    chba_params_sync.chba_state = CHBA_WORK;
    chba_params_sync.info_bitmap = CHBA_STATE | CHBA_ROLE | CHBA_BSSID;
    hmac_chba_params_sync(&hmac_vap->st_vap_base_info, &chba_params_sync);

    /* 3. 如果已经关联，则向master申请时隙 */
    hmac_user = mac_vap_get_hmac_user_by_addr(&hmac_vap->st_vap_base_info, conn_info->peer_addr, WLAN_MAC_ADDR_LEN);
    if (hmac_user == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "NBW: hmac_nbw_slaveap_rx_beacon_proc:: hmac user is null.");
        return;
    }
    if (hmac_user->st_user_base_info.en_user_asoc_state == MAC_USER_STATE_ASSOC) {
        hmac_nbw_apply_slot(hmac_vap);
        return;
    }
}


static void hmac_nbw_rx_beacon_proc_domain_merge(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    uint8_t nbw_role = hmac_nbw_get_role();
    uint8_t *domain_topo_info = NULL;

    /* 当前处于域合并流程中 */
    if (hmac_chba_get_sync_state() != CHBA_NON_SYNC || hmac_nbw_get_domain_merge_flag() != OAL_TRUE) {
        return;
    }
    /* 接收到域合并目标master的beacon帧 */
    if (oal_compare_mac_addr(peer_addr, hmac_nbw_get_domain_merge_master_bssid()) != 0) {
        oam_warning_log0(0, OAM_SF_CHBA, "NBW: {hmac_nbw_rx_beacon_proc_domain_merge::not object domain.}");
        return;
    }
    /* 确定下这个状态的设备角色是否已刷新 */
    if (nbw_role != MAC_NBW_SLAVEAP_ROLE) {
        return;
    }

    domain_topo_info = hmac_find_chba_attr(MAC_NBW_ATTR_DOMAIN_TOPO, payload, payload_len);
    if (domain_topo_info == NULL) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_rx_beacon_proc_domain_merge::no attribute.");
        return;
    }
    oam_warning_log0(0, OAM_SF_CHBA, "NBW: {hmac_nbw_rx_beacon_proc_domain_merge::doamin_merge finish.}");

    /* 解析帧内容 */
    hmac_nbw_beacon_domain_info_parsing(hmac_vap, domain_topo_info + MAC_CHBA_ATTR_HDR_LEN,
        *(domain_topo_info + MAC_CHBA_ATTR_ID_LEN));
}

/*
 * 功能描述  : slave处理master/slaveap beacon，更新master信息
 * 日    期  : 2025年08月13日
 * 作    者  : wifi
 */
static void hmac_nbw_beacon_update_master_info(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    uint8_t *master_info = NULL;
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    master_info = hmac_find_chba_attr(MAC_NBW_ATTR_MASTER_INFO, payload, payload_len);
    if (master_info == NULL) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_update_master_info::no master info attr find.");
        return;
    }
    
    if (hmac_nbw_get_role() != MAC_NBW_SLAVE_ROLE) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_update_master_info::no slave no handle.");
        return;
    }

    if (hmac_nbw_find_slot_link_idx(slave_slot_info, peer_addr) == NBW_INVALID_IDX) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_update_master_info::not connect link update.");
        return;
    }

    if (MAC_CHBA_ATTR_HDR_LEN + master_info[MAC_CHBA_ATTR_ID_LEN] < NBW_BEACON_MASTER_INFO_LEN) {
        oam_error_log1(0, OAM_SF_NBW, "hmac_nbw_beacon_update_master_info::master info attr len[%d] invalid.",
            master_info[MAC_CHBA_ATTR_ID_LEN]);
        return;
    }

    if (oal_compare_mac_addr(master_info + NBW_BEACON_MASTER_INFO_ADDR_POS, hmac_nbw_get_master_macaddr()) != 0) {
        oam_warning_log3(0, OAM_SF_NBW, "hmac_nbw_beacon_update_master_info::new master addr %02X:XX:XX:XX:%02X:%02X.",
            master_info[NBW_BEACON_MASTER_INFO_ADDR_POS], master_info[NBW_BEACON_MASTER_INFO_ADDR_POS + MAC_ADDR_4],
            master_info[NBW_BEACON_MASTER_INFO_ADDR_POS + MAC_ADDR_5]);
        /* 刷新slave的master bssid */
        oal_set_mac_addr(hmac_nbw_get_master_macaddr(), master_info + NBW_BEACON_MASTER_INFO_ADDR_POS);
        hmac_nbw_sync_self_info(hmac_vap);
    }
}

static oal_bool_enum_uint8 hmac_nbw_beacon_slaveap_slave_match(uint8_t *peer_addr)
{
    hmac_nbw_slot_info_stru *slave_slot_info = hmac_nbw_get_slave_slot_info();
    if (hmac_nbw_find_slot_link_idx(slave_slot_info, peer_addr) == NBW_INVALID_IDX) {
        return OAL_FALSE;
    }
    return OAL_TRUE;
}


static void hmac_nbw_beacon_domain_topo_handle(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    uint8_t nbw_role = hmac_nbw_get_role();
    uint8_t *domain_topo_info = NULL;
    domain_topo_info = hmac_find_chba_attr(MAC_NBW_ATTR_DOMAIN_TOPO, payload, payload_len);
    if (domain_topo_info == NULL) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_domain_topo_handle::no attribute.");
        return;
    }
    if (oal_compare_mac_addr(peer_addr, hmac_nbw_get_master_macaddr()) != 0 &&
        hmac_nbw_beacon_slaveap_slave_match(peer_addr) != OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_beacon_domain_topo_handle::not self domain beacon.");
        return;
    }
    switch (nbw_role) {
        case MAC_NBW_SLAVE_ROLE:
            /* Master直连slave处理Master发送的beacon */
            hmac_nbw_beacon_island_info_parsing(hmac_vap, peer_addr,
                domain_topo_info + MAC_CHBA_ATTR_HDR_LEN, *(domain_topo_info + MAC_CHBA_ATTR_ID_LEN));
            break;
        case MAC_NBW_SLAVEAP_ROLE:
            /* 处理master发送的beacon */
            hmac_nbw_beacon_domain_info_parsing(hmac_vap, domain_topo_info + MAC_CHBA_ATTR_HDR_LEN,
                *(domain_topo_info + MAC_CHBA_ATTR_ID_LEN));
            break;
        case MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE:
            hmac_nbw_beacon_island_info_parsing(hmac_vap, peer_addr,
                domain_topo_info + MAC_CHBA_ATTR_HDR_LEN, *(domain_topo_info + MAC_CHBA_ATTR_ID_LEN));
            hmac_nbw_beacon_domain_info_parsing(hmac_vap, domain_topo_info + MAC_CHBA_ATTR_HDR_LEN,
                *(domain_topo_info + MAC_CHBA_ATTR_ID_LEN));
            break;
        default:
            oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_beacon_domain_topo_handle: nbw role err.");
            break;
    }
}


static void hmac_nbw_beacon_island_topo_handle(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    uint8_t nbw_role = hmac_nbw_get_role();
    hmac_user_stru *hmac_user = NULL;
    uint8_t *island_topo_info = NULL;
    island_topo_info = hmac_find_chba_attr(MAC_NBW_ATTR_ISLAND_TOPO, payload, payload_len);
    if (island_topo_info == NULL) {
        return;
    }
    if (nbw_role != MAC_NBW_SLAVE_ROLE && nbw_role != MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE) {
        return;
    }
    if (island_topo_info[MAC_CHBA_ATTR_ID_LEN] < NBW_SLAVEAP_BEACON_BASIC_INFO_LEN) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_island_topo_handle::ISLAND_TOPO len err.");
        return;
    }

    if (island_topo_info[MAC_NBW_TOPO_CHANGE_POS + MAC_CHBA_ATTR_HDR_LEN] != NBW_TOPO_CHANGED_INDICATE) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_beacon_island_topo_handle::NBW_TOPO_CHANGED_INDICATE.");
        return;
    }
    /* 全域已分配时隙信息更新 */
    hmac_nbw_set_alloc_uslot_bitmap(island_topo_info[MAC_NBW_SLOT_BITMAP_ALLOC_POS + MAC_CHBA_ATTR_HDR_LEN]);
    /* slave处理slaveAp beacon帧 */
    hmac_nbw_beacon_per_slot_info_parsing(hmac_vap, peer_addr,
        island_topo_info + NBW_SLAVEAP_BEACON_BASIC_INFO_LEN + MAC_CHBA_ATTR_HDR_LEN,
        island_topo_info[MAC_CHBA_ATTR_ID_LEN] - NBW_SLAVEAP_BEACON_BASIC_INFO_LEN);
}


static void hmac_nbw_rx_beacon_proc_after_sync(hmac_vap_stru *hmac_vap, uint8_t *peer_addr, uint8_t *payload,
    uint8_t payload_len)
{
    if (oal_any_null_ptr3(hmac_vap, peer_addr, payload) ||
        payload_len < (MAC_CHBA_ATTR_HDR_LEN + MAC_NBW_SLOT_BITMAP_ALLOC_POS)) {
        oam_warning_log0(0, OAM_SF_NBW, "hmac_nbw_rx_beacon_proc_after_sync::nullptr.");
        return;
    }
    if (hmac_chba_get_sync_state() != CHBA_WORK) {
        return;
    }
    /* 识别beacon帧attribute类型 */
    hmac_nbw_beacon_domain_topo_handle(hmac_vap, peer_addr, payload, payload_len);
    hmac_nbw_beacon_island_topo_handle(hmac_vap, peer_addr, payload, payload_len);
    hmac_nbw_beacon_update_master_info(hmac_vap, peer_addr, payload, payload_len);
}


uint32_t hmac_nbw_rx_beacon(hmac_vap_stru *hmac_vap, mac_ieee80211_frame_stru *mac_hdr,
    uint8_t *payload, uint16_t payload_len)
{
    uint8_t sa_addr[WLAN_MAC_ADDR_LEN], domain_bssid[WLAN_MAC_ADDR_LEN];
    uint8_t *nbw_ie = NULL;
    uint16_t nbw_ie_len;
    mac_ies_info ies_info = { 0 };
    hmac_nbw_current_connect_info_stru *curr_conn_info = NULL;
    /* 固定长度检查 */
    if (payload_len < MAC_NBW_BEACON_ELEMENT_OFFSET) {
        oam_warning_log1(0, OAM_SF_CHBA, "NBW: {hmac_nbw_rx_beacon::len is too short[%d].}", payload_len);
        return OAL_FAIL;
    }
    /* 解析hdr头地址 */
    mac_get_address2((uint8_t *)mac_hdr, sa_addr, WLAN_MAC_ADDR_LEN);
    mac_get_address3((uint8_t *)mac_hdr, domain_bssid, WLAN_MAC_ADDR_LEN);
    /* 解析nbw 私有IE, 并完成合法性检查 */
    ies_info.frame_ies = payload + MAC_NBW_BEACON_ELEMENT_OFFSET;
    ies_info.frame_len = payload_len - MAC_NBW_BEACON_ELEMENT_OFFSET;
    nbw_ie = mac_find_vendor_ie(MAC_CHBA_VENDOR_IE, MAC_OUI_TYPE_NBW, &ies_info);
    if (nbw_ie == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "NBW: hmac_nbw_rx_beacon::can't find nbw ie in beacon frame.");
        return OAL_FAIL;
    }
    /* 收到来自目标域的beacon, 看sa，且当前处于域合并状态，需要进行处理，把时隙指示部分本岛的时隙抽出来 作为新的时隙 */
    if (((uint16_t)(nbw_ie[1]) + MAC_IE_HDR_LEN) < sizeof(mac_ieee80211_vendor_ie_stru)) {
        oam_warning_log1(0, OAM_SF_CHBA, "NBW: hmac_nbw_rx_beacon::find nbw_ie len[%d]", nbw_ie[1]);
        return OAL_FAIL;
    }

    nbw_ie_len = ((uint16_t)(nbw_ie[1]) + MAC_IE_HDR_LEN) - (uint8_t)sizeof(mac_ieee80211_vendor_ie_stru);
    if (nbw_ie_len < MAC_NBW_BEACON_BASIC_ATTR_LEN) {
        oam_error_log0(0, OAM_SF_CHBA, "NBW: hmac_nbw_rx_beacon::nbw ie len is wrong.");
        return OAL_FAIL;
    }
    nbw_ie = nbw_ie + (uint8_t)sizeof(mac_ieee80211_vendor_ie_stru);

    curr_conn_info = (hmac_nbw_current_connect_info_stru *)hmac_nbw_get_curr_conn_info();
    if (curr_conn_info->connect_status == MAC_NBW_CONNECT_NEGOTIATE) {
        /* 建链协商过程中处理beacon帧 */
    } else if (curr_conn_info->connect_status == MAC_NBW_CONNECT_ASSOC) { /* 建链关联过程中处理beacon帧 */
        if (curr_conn_info->connect_role == MAC_NBW_SLAVE_ROLE) {
            hmac_nbw_slave_rx_beacon_proc(hmac_vap, sa_addr, nbw_ie, nbw_ie_len);
        } else if (curr_conn_info->connect_role == MAC_NBW_SLAVEAP_ROLE) {
            hmac_nbw_slaveap_rx_beacon_proc(hmac_vap, sa_addr, nbw_ie, nbw_ie_len);
        }
    } else {
        /* 建链协商完成后处理beacon帧 */
        hmac_nbw_rx_beacon_proc_after_sync(hmac_vap, sa_addr, nbw_ie, nbw_ie_len);
    }
    /* 信道测量过程中的beacon处理 */
    hmac_nbw_channel_measure_beacon_process(nbw_ie, nbw_ie_len, domain_bssid);
    /* 域合并过程中的beacon处理 */
    hmac_nbw_rx_beacon_proc_domain_merge(hmac_vap, sa_addr, nbw_ie, nbw_ie_len);
    return OAL_SUCC;
}

/*
 * 功能描述  : 根据PNF的payload更新岛域内链路信息，返回岛域内slave bitmap
 * 日    期  : 2025年05月20日
 */
static uint32_t hmac_nbw_update_island_slave_info_by_frame(uint8_t work_mode, uint8_t *payload,
    int32_t len, uint8_t *peer_addr)
{
    uint8_t *data = NULL;
    uint16_t offset;
    uint8_t device_id, conn_device_id, topo_changed;
    uint8_t i, linkcnt;
    int8_t rssi;
    uint32_t slave_bitmap = 0;

    /* 解析NBW Link Info Attribute */
    /* ******************************************* Link Info Attribute ************************************ */
    /* ---------------------------------------------------------------------------------------------------  */
    /* | NBW ATTR ID | LEN | rssi | changed bit | slave LinkCnt | MacAddr   | SlaveAp LinkCnt | MacAddr   | */
    /* ---------------------------------------------------------------------------------------------------  */
    /* |       1     |  1  |   1  |     1       |   1           | LinkCnt*6 |   1             | LinkCnt*6 | */
    /* ---------------------------------------------------------------------------------------------------  */
    data = hmac_find_chba_attr(MAC_NBW_ATTR_LINK_INFO, payload, len);
    if (data == NULL) {
        return slave_bitmap;
    }

    if (MAC_CHBA_ATTR_HDR_LEN + data[MAC_CHBA_ATTR_ID_LEN] < MAC_NBW_LINK_INFO_LINK_CNT_POS + 1 ||
        MAC_CHBA_ATTR_HDR_LEN + data[MAC_CHBA_ATTR_ID_LEN] <
        MAC_NBW_LINK_INFO_LINK_CNT_POS + 1 + data[MAC_NBW_LINK_INFO_LINK_CNT_POS] * WLAN_MAC_ADDR_LEN) {
        oam_error_log1(0, OAM_SF_CHBA, "hmac_nbw_update_island_slave_info_by_frame::link info attr len[%d] invalid.",
            data[MAC_CHBA_ATTR_ID_LEN]);
        return slave_bitmap;
    }
    offset = MAC_CHBA_ATTR_HDR_LEN;
    rssi = data[offset];
    offset += HMAC_CHBA_BYTE_LEN_1;
    topo_changed = data[offset];
    offset += HMAC_CHBA_BYTE_LEN_1;
    linkcnt = data[offset];
    offset += HMAC_CHBA_BYTE_LEN_1;

    /* 将帧发送方加入到活跃设备表 */
    device_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, peer_addr);
    /* 无效的device id直接返回 */
    if (device_id >= MAC_CHBA_MAX_DEVICE_NUM) {
        return slave_bitmap;
    }

    /* 将与帧发送方连接的每个设备加入到活跃设备表 */
    for (i = 0; i < linkcnt; i++) {
        conn_device_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, &data[offset]);
        /* 无效的device id不处理 */
        if (conn_device_id >= MAC_CHBA_MAX_DEVICE_NUM) {
            continue;
        }
        slave_bitmap |= BIT(conn_device_id);

        offset += OAL_MAC_ADDR_LEN;
    }
    return slave_bitmap;
}


void hmac_nbw_rx_pnf_proc(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint8_t sa_len, uint8_t *payload,
    uint16_t payload_len)
{
    uint32_t pnf_bitmap = 0;
    uint32_t slave_bitmap = 0;
    uint16_t index = 0;
    uint8_t work_mode = hmac_vap->st_vap_base_info.work_mode;
    chba_device_id_stru device_rpt = { 0 };
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(work_mode);
    uint8_t slaveap_device_id = hmac_chba_one_dev_update_alive_dev_table(work_mode, sa_addr);
    uint8_t nbw_role = hmac_nbw_get_role();
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(work_mode);
    /* SlaveAp设备仅处理对应slave的信息 */
    if (nbw_role == MAC_NBW_SLAVEAP_ROLE || nbw_role == MAC_NBW_SLAVEAP_SLAVE_MIX_ROLE) {
        hmac_nbw_update_island_slave_info_by_frame(work_mode, payload, payload_len, sa_addr);
        return;
    }
    /* 非Master或者无效的device id直接返回 */
    if (nbw_role != MAC_NBW_MASTER_ROLE || slaveap_device_id >= MAC_CHBA_MAX_DEVICE_NUM) {
        return;
    }
    /* 处理slaveAp岛内的slave链路 */
    pnf_bitmap = hmac_nbw_update_island_slave_info_by_frame(work_mode, payload, payload_len, sa_addr);
    slave_bitmap = hmac_nbw_get_island_slave_info(work_mode, slaveap_device_id);
    for (index = 0; index < MAC_CHBA_MAX_DEVICE_NUM; index++) {
        if ((pnf_bitmap & BIT(index)) == BIT(index)) {
            device_id_info[index].pnf_link_loss_cnt[slaveap_device_id] = 0;
        }
    }

    if (slave_bitmap == pnf_bitmap) {
        return;
    }
    for (index = 0; index < MAC_CHBA_MAX_DEVICE_NUM; index++) {
        if ((slave_bitmap & BIT(index)) == BIT(index) && (pnf_bitmap & BIT(index)) != BIT(index)) {
            if (index == self_conn_info->self_device_id ||
                device_id_info[index].pnf_link_loss_cnt[slaveap_device_id] < NBW_PNF_LINK_LOSS_CNT) {
                device_id_info[index].pnf_link_loss_cnt[slaveap_device_id]++;
                continue;
            }
            device_rpt.device_id = index;
            oal_set_mac_addr(device_rpt.mac_addr, device_id_info[index].mac_addr);
            hmac_chba_del_non_alive_device(&hmac_vap->st_vap_base_info, sizeof(chba_device_id_stru),
                (uint8_t*)&device_rpt);
            device_id_info[index].pnf_link_loss_cnt[slaveap_device_id] = 0;
        } else if ((pnf_bitmap & BIT(index)) == BIT(index)) {
            device_id_info[index].pnf_link_loss_cnt[slaveap_device_id] = 0;
        }
    }
}

/*
 * 功能描述  : NBW Vendor IE Header填写
 * 日    期  : 2021年02月04日
 * 作    者  : wifi
 */
static uint32_t hmac_nbw_set_vendor_ie_hdr(uint8_t *buf)
{
    if (buf == NULL) {
        return 0;
    }

    buf[BYTE_OFFSET_0] = MAC_NBW_VENDOR_EID; /* vendor ie: 221 */
    buf[BYTE_OFFSET_2] = 0x00; /* 2: oui[0] */
    buf[BYTE_OFFSET_3] = 0xE0; /* 3: oui[1] */
    buf[BYTE_OFFSET_4] = 0xFC; /* 4: oui[2] */
    buf[BYTE_OFFSET_5] = MAC_OUI_TYPE_NBW;
    return sizeof(mac_ieee80211_vendor_ie_stru);
}

/*
 * 功能描述  : 封装Master Election Attribute
 * 日    期  : 2021年02月04日
 * 作    者  : wifi
 */
static void hmac_nbw_set_basic_beacon_attr(uint8_t *attr_buf)
{
    uint8_t index;

    if (attr_buf == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_set_master_election_attr: input pointer is null.");
        return;
    }

    /* Attribute ID */
    attr_buf[0] = MAC_NBW_ATTR_BASIC;
    index = MAC_CHBA_ATTR_HDR_LEN;

    /* Attribute Content */
    /* 根据role信息填写is_master字段 */
    if (hmac_nbw_get_role() == MAC_NBW_MASTER_ROLE) {
        attr_buf[index++] = MASTER_BEACON_INDICATE;
    } else {
        attr_buf[index++] = 0;
    }

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
}


static void hmac_nbw_set_island_rp_attr(uint8_t *buf, uint16_t *buf_len, nbw_ranking_priority *rp)
{
    int status = 0;
    status = memcpy_s(buf, sizeof(nbw_ranking_priority), rp, sizeof(nbw_ranking_priority));
    if (status != EOK) {
        oam_warning_log1(0, OAM_SF_CHBA, "hmac_nbw_set_island_rp_attr::memcpy failed, err[%d].", status);
    }
    *buf_len += MAC_NBW_ATTR_RP_LEN;
}


static void hmac_nbw_set_per_island_info_attr(uint8_t *buf, uint16_t *buf_len,
    hmac_chba_per_island_info_stru *per_island)
{
    uint8_t link_cnt = 0;
    uint8_t index, idx;
    hmac_nbw_slot_info_stru *island_slot_info = &per_island->island_slot_info[0];
    buf[0] = per_island->island_flag;
    index = MAC_NBW_ISLAND_HDR_LEN;
    for (idx = 0; idx < MAX_ISLAND_SLOT_INFO_NUM; idx++) {
        if (island_slot_info[idx].use_flag == OAL_TRUE) {
            link_cnt++;
            oal_set_mac_addr(buf + index, island_slot_info[idx].peer_device_mac);
            index += OAL_MAC_ADDRESS_LEN;
            buf[index++] = island_slot_info[idx].slot_period_level;
            buf[index++] = island_slot_info[idx].uslot_info.start_idx;
            buf[index++] = island_slot_info[idx].uslot_info.timeslot_interval;
            buf[index++] = island_slot_info[idx].uslot_info.shared_flag;
            buf[index++] = island_slot_info[idx].uslot_info.work_uslot_bitmap;
        }
    }

    buf[1] = link_cnt;
    *buf_len += index;
}


static void hmac_nbw_set_island_info_attr(uint8_t *buf, uint16_t *buf_len)
{
    uint16_t index = 0;
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(NBW_WORK_MODE);
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info(NBW_WORK_MODE);
    /* 域内岛域数目 */
    buf[index++] = island_info->island_cnt;
    if (island_info->island_cnt == 0) {
        return;
    }

    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        /* SlaveAp地址 */
        oal_set_mac_addr(buf + index, device_id_info[curr_island->owner_device_id].mac_addr); /* SlaveAp地址 */
        index += OAL_MAC_ADDRESS_LEN;

        /* SlaveAp Rp值 */
        hmac_nbw_set_island_rp_attr(&buf[index], &index, &curr_island->slaveap_rp);

        /* 岛域链路和时隙信息 */
        hmac_nbw_set_per_island_info_attr(&buf[index], &index, curr_island);
    }
    *buf_len += index;
}

static void hmac_nbw_set_domain_topo_beacon_attr(uint8_t *attr_buf, uint16_t *buf_len)
{
    uint16_t index;

    if (attr_buf == NULL || buf_len == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_set_master_election_attr: input pointer is null.");
        return;
    }

    /* Attribute ID */
    attr_buf[0] = MAC_NBW_ATTR_DOMAIN_TOPO;
    index = MAC_CHBA_ATTR_HDR_LEN;

    /* Attribute Content */
    /* Rsv for rssi */
    attr_buf[index++] = 0;
    /* 填写拓扑信息改变标记 */
    attr_buf[index++] = hmac_nbw_get_topo_change_flag();
    /* 填写全域已分配bitmap */
    attr_buf[index++] = hmac_nbw_get_available_uslot_bitmap();
    /* 填写全域拓扑信息 */
    hmac_nbw_set_island_info_attr(&attr_buf[index], &index);

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    *buf_len = index;
}


static void hmac_nbw_set_island_topo_beacon_attr(uint8_t *attr_buf, uint16_t *buf_len)
{
    uint16_t index;
    struct hi_node *nbw_node = NULL;
    struct hi_node *tmp = NULL;
    hmac_chba_island_list_node_stru *island_node = NULL;
    hmac_chba_per_island_info_stru *curr_island = NULL;
    hmac_chba_island_list_stru *island_info = hmac_chba_get_island_list(NBW_WORK_MODE);
    mac_chba_self_conn_info_stru *self_conn_info = hmac_chba_get_self_conn_info(NBW_WORK_MODE);

    if (attr_buf == NULL || buf_len == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_set_island_topo_beacon_attr: input pointer is null.");
        return;
    }

    /* Attribute ID */
    attr_buf[0] = MAC_NBW_ATTR_ISLAND_TOPO;
    index = MAC_CHBA_ATTR_HDR_LEN;

    /* Attribute Content */
    /* Rsv for rssi */
    attr_buf[index++] = 0;
    /* 填写拓扑信息改变标记 */
    attr_buf[index++] = hmac_nbw_get_topo_change_flag();
    /* 填写全域已分配bitmap */
    attr_buf[index++] = hmac_nbw_get_available_uslot_bitmap();

    /* 填写Master地址 */
    oal_set_mac_addr(attr_buf + index, hmac_nbw_get_master_macaddr());
    index += OAL_MAC_ADDRESS_LEN;
    
    /* 填写岛域拓扑信息 */
    hi_list_for_each_safe(nbw_node, tmp, &island_info->island_list) {
        island_node = hi_node_entry(nbw_node, hmac_chba_island_list_node_stru, node);
        curr_island = &island_node->data;
        if (curr_island->owner_device_id != self_conn_info->self_device_id) {
            continue;
        }
        /* 岛域链路和时隙信息 */
        hmac_nbw_set_per_island_info_attr(&attr_buf[index], &index, curr_island);
    }

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    *buf_len = index;
}


static void hmac_nbw_set_master_info_attr(uint8_t *attr_buf, uint16_t *buf_len)
{
    uint16_t index;
    if (attr_buf == NULL || buf_len == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_set_master_info_attr: input pointer is null.");
        return;
    }

    /* Attribute ID */
    attr_buf[0] = MAC_NBW_ATTR_MASTER_INFO;
    index = MAC_CHBA_ATTR_HDR_LEN;

    /* Attribute Content */
    /* 填写Master地址 */
    oal_set_mac_addr(attr_buf + index, hmac_nbw_get_master_macaddr());
    index += OAL_MAC_ADDRESS_LEN;

    /* 填写nbw 同步状态, rsv */
    attr_buf[index++] = 0;

    /* 填写beacon loss cnt, rsv */
    attr_buf[index++] = 0;

    /* 填写sync slot, rsv */
    attr_buf[index++] = 0;
    attr_buf[index++] = 0;

    /* 预留slot bitmap长度 */
    index += NBW_BEACON_MASTER_INFO_SLOT_BITMAP_LEN;

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    *buf_len = index;
}


void hmac_nbw_encap_master_slaveap_beacon(hmac_chba_vap_stru *chba_vap_info, uint8_t *beacon_buf, uint16_t *beacon_len,
    uint8_t beacon_type)
{
    uint16_t total_len = 0;
    uint16_t info_len = 0;
    uint16_t vendor_ie_len;
    uint8_t *vendor_ie_len_pos = NULL;

    if (oal_any_null_ptr3(chba_vap_info, beacon_buf, beacon_len)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_encap_sync_beacon: input pointer is null.");
        return;
    }

    /* 填写NBW Vendor IE Header */
    hmac_nbw_set_vendor_ie_hdr(beacon_buf);
    vendor_ie_len_pos = beacon_buf + 1;
    vendor_ie_len = MAC_CHBA_ACTION_HDR_LEN - MAC_CHBA_ATTR_HDR_LEN;
    total_len += MAC_CHBA_ACTION_HDR_LEN;

    switch (beacon_type) {
        case MAC_NBW_BEACON_TYPE_BASIC:
            hmac_nbw_set_basic_beacon_attr(beacon_buf + total_len);
            total_len += MAC_NBW_BEACON_BASIC_ATTR_LEN;
            vendor_ie_len += MAC_NBW_BEACON_BASIC_ATTR_LEN;
            break;
        case MAC_NBW_BEACON_TYPE_DOMAIN_TOPO:
            hmac_nbw_set_domain_topo_beacon_attr(beacon_buf + total_len, &info_len);
            total_len += info_len;
            vendor_ie_len += info_len;
            /* 封装Master info属性(必选) */
            hmac_nbw_set_master_info_attr(beacon_buf + total_len, &info_len);
            total_len += info_len;
            vendor_ie_len += info_len;
            break;
        case MAC_NBW_BEACON_TYPE_ISLAND_TOPO:
            hmac_nbw_set_island_topo_beacon_attr(beacon_buf + total_len, &info_len);
            total_len += info_len;
            vendor_ie_len += info_len;
            /* 封装Master info属性(必选) */
            hmac_nbw_set_master_info_attr(beacon_buf + total_len, &info_len);
            total_len += info_len;
            vendor_ie_len += info_len;
            break;
        default:
            oam_warning_log0(0, OAM_SF_CHBA, "hmac_nbw_encap_master_slaveap_beacon: beacon type is unknown.");
            break;
    }

    *vendor_ie_len_pos = vendor_ie_len;
    *beacon_len = total_len;
}
#endif