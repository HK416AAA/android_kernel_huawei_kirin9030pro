/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : AMPDU聚合、BA处理接口定义源文件
 * 作    者 :
 * 创建日期 : 2014年11月25日
 */

/* 1 头文件包含 */
#include "hmac_rx.h"
#include "mac_data.h"
#include "mac_frame_if.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_11i.h"
#include "hmac_wapi.h"
#include "hmac_ht_self_cure.h"
#include "hmac_tx_amsdu.h"
#include "hmac_ota_report.h"
#include "hmac_mgmt_sta_up.h"
#include "hmac_wifi_delay.h"
#include "oam_event_wifi.h"
#endif
#include "hmac_rx_reorder.h"
#include "dpe_wlan_resource.h"
#include "dpe_wlan_stat.h"
#include "dpe_tx_data.h"
#include "host_hal_ext_if.h"
#include "dpe_sbuf.h"
#ifdef _PRE_WLAN_PKT_TIME_STAT
#include <hwnet/ipv4/wifi_delayst.h>
#endif
#ifdef _PRE_WLAN_FEATURE_SNIFFER
#ifdef CONFIG_HW_SNIFFER
#include <hwnet/ipv4/sysctl_sniffer.h>
#endif
#endif
#ifdef CONFIG_HUAWEI_DUBAI
#include <chipset_common/dubai/dubai.h>
#include <huawei_platform/log/hwlog_kernel.h>
#endif
#ifdef _PRE_WLAN_FEATURE_ISOLATION
#include "hmac_isolation.h"
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hmac_pwl.h"
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_W2W_C

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
static void dpe_rx_to_tx_eth_hdr_cpy(oal_netbuf_stru *netbuf)
{
    int32_t ret;
    mac_rx_ctl_stru *pst_rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    uint8_t *rx_eth_hdr = (uint8_t *)dpe_get_rx_netbuf_hdr_addr(netbuf);
    uint8_t *tx_eth_hdr = (uint8_t *)dpe_tx_get_eth_hdr_info(netbuf);
    uint32_t move_len = DPE_NETBUF_CB_WIFI_INFO_LEN - hal_host_get_rx_msdu_dscr_len();
    /* 拷贝ETH */
    ret = memmove_s(tx_eth_hdr, DPE_NETBUF_CB_WIFI_INFO_LEN, rx_eth_hdr, move_len);
    if (ret != EOK) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_rx_to_tx_eth_hdr_cpy::tx_eth_hdr copy process failed.}");
    }
    *(tx_eth_hdr + (DPE_NETBUF_CB_WIFI_INFO_LEN - 1)) = pst_rx_ctrl->bit_rx_tid;
    /* 清零cb前128字节 */
    memset_s(oal_sbuf_cb(netbuf), DPE_NETBUF_CB_WIFI_INFO_LEN, 0, DPE_NETBUF_CB_WIFI_INFO_LEN);
}
#endif
/*
 * 函 数 名  : hmac_rx_transmit_to_wlan
 * 功能描述  : 将数据帧发送到WLAN侧的接口函数，将一个netbuf链抛给发送流程，每个
 * 1.日    期  : 2012年11月19日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_rx_transmit_to_wlan(frw_event_hdr_stru *event_hdr, oal_netbuf_head_stru *netbuf_head)
{
    oal_netbuf_stru *netbuf = NULL; /* 从netbuf链上取下来的指向netbuf的指针 */
    oal_netbuf_stru *pst_buf_tmp = NULL; /* 暂存netbuf指针，用于while循环 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(event_hdr->uc_vap_id);
#else
    mac_tx_ctl_stru *pst_tx_ctl = NULL;
    mac_vap_stru *pst_mac_vap = NULL;
    uint32_t ret;
#endif

    /* 获取链头的net buffer */
    netbuf = oal_netbuf_peek(netbuf_head);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* 获取mac vap 结构 */
    ret = hmac_tx_get_mac_vap(event_hdr->uc_vap_id, &pst_mac_vap);
    if (oal_unlikely(ret != OAL_SUCC)) {
        uint32_t netbuf_num = oal_netbuf_list_len(netbuf_head);
        hmac_rx_free_netbuf(netbuf, (uint16_t)netbuf_num);
        oam_warning_log3(event_hdr->uc_vap_id, OAM_SF_DPA, "{hmac_rx_transmit_to_wlan::find vap [%d] failed[%d], \
            free [%d] netbuffer.}", event_hdr->uc_vap_id, ret, netbuf_num);
        return ret;
    }
#endif
    /* 循环处理每一个netbuf，按照以太网帧的方式处理 */
    while (netbuf != NULL) {
        pst_buf_tmp = oal_netbuf_next(netbuf);
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        /* DPE在DPA上WLAN TO WLAN转发 */
        dpe_rx_to_tx_eth_hdr_cpy(netbuf);
        dpe_wlan_xmit(dpe_vap, netbuf, OAL_TRUE);
#else
        oal_set_netbuf_next(netbuf, NULL);
        oal_set_netbuf_prev(netbuf, NULL);
#ifdef _PRE_WLAN_FEATURE_ISOLATION
        if (hmac_isolation_filter(pst_mac_vap, netbuf) == OAL_TRUE) {
            hmac_free_netbuf_list(netbuf);
            netbuf = pst_buf_tmp;
            continue;
        }
#endif
        pst_tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        memset_s(pst_tx_ctl, sizeof(mac_tx_ctl_stru), 0, sizeof(mac_tx_ctl_stru));

        mac_get_cb_event_type(pst_tx_ctl) = FRW_EVENT_TYPE_WLAN_DTX;
        mac_get_cb_event_subtype(pst_tx_ctl) = DMAC_TX_WLAN_DTX;

        /* set the queue map id when wlan to wlan */
        oal_skb_set_queue_mapping(netbuf, WLAN_NORMAL_QUEUE);

        ret = hmac_tx_lan_to_wlan(pst_mac_vap, &netbuf);
        if (ret != OAL_SUCC) {
            hmac_free_netbuf_list(netbuf);
        }
#endif
        netbuf = pst_buf_tmp;
    }
    return OAL_SUCC;
}

/*
 * 功能描述  : 转交w2w处理
 * 1.日    期  : 2020年03月6日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_wlan_to_wlan_proc(dpe_wlan_vap_stru *dpe_vap, oal_netbuf_head_stru *pw2w_netbuf_hdr)
{
    frw_event_hdr_stru event_hdr;
    memset_s(&event_hdr, sizeof(frw_event_hdr_stru), 0, sizeof(frw_event_hdr_stru));
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    event_hdr.uc_chip_id = dpe_vap->uc_chip_id;
#endif
    event_hdr.uc_device_id = dpe_vap->uc_device_id;
    event_hdr.uc_vap_id = dpe_vap->uc_vap_id;

    if (oal_netbuf_list_empty(pw2w_netbuf_hdr) == OAL_FALSE && oal_netbuf_tail(pw2w_netbuf_hdr) != NULL &&
        oal_netbuf_peek(pw2w_netbuf_hdr) != NULL) {
        oal_set_netbuf_next((oal_netbuf_tail(pw2w_netbuf_hdr)), NULL);
        oal_set_netbuf_prev((oal_netbuf_peek(pw2w_netbuf_hdr)), NULL);
        if (hmac_rx_transmit_to_wlan(&event_hdr, pw2w_netbuf_hdr) != OAL_SUCC) {
            oam_warning_log0(0, OAM_SF_DPA, "{hmac_rx_wlan_to_wlan_proc:: rx transmit to wlan fail}");
        }
    }
    return;
}

uint8_t hmac_rx_da_is_in_same_bss(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl, uint8_t vap_idx)
{
    dpe_wlan_user_stru *dpe_user = NULL;
    uint16_t user_idx = 0;
    uint8_t *puc_da = dpe_rx_get_eth_da(netbuf);

    if (dpe_vap_find_user_by_macaddr(vap_idx, puc_da, &user_idx) != OAL_SUCC) {
        return OAL_FALSE;
    }

    dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_rx_da_is_in_same_bss::find da fail usr idx:%d}", user_idx);
        return OAL_FALSE;
    }
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    if (dpe_user->en_user_asoc_state != MAC_USER_STATE_ASSOC) {
        hmac_mgmt_send_deauth_frame(vap_idx, dpe_user->auc_user_mac_addr, MAC_NOT_AUTHED, OAL_FALSE);
        return OAL_FALSE;
    }
#endif
    return OAL_TRUE;
}

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
OAL_STATIC void hmac_rx_ap_mcast_w2w_proc(dpe_wlan_vap_stru *dpe_vap, oal_netbuf_stru *netbuf,
    mac_rx_ctl_stru *rx_ctl, oal_netbuf_head_stru *w2w_list)
{
    /* chba高速组播场景组播不需要w2w处理 */
    if ((dpe_is_chba_mode(dpe_vap) == OAL_TRUE) && dpe_vap->bit_support_mcast_ampdu == OAL_TRUE) {
        return;
    }
    hmac_rx_ap_mcast_data_proc(netbuf, rx_ctl, w2w_list);
}
#endif

/*
 * 功能描述  : AP转发逻辑，仅处理单个netbuf
 * 1.日    期  : 2020年03月6日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_ap_w2w_proc(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *release_list, oal_netbuf_head_stru *w2w_list)
{
    oal_netbuf_stru          *netbuf = NULL;
    mac_rx_ctl_stru          *rx_ctl = NULL;
    dpe_wlan_vap_stru        *dpe_vap = rx_context->dpe_vap;
    oal_netbuf_stru          *next_netbuf = NULL;
    uint8_t                  *frame_ctl = NULL;

    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, release_list) {
        rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        if (rx_ctl == NULL) {
            continue;
        }
        frame_ctl = (uint8_t *)&rx_ctl->us_frame_control;
        /* 四地址amsdu不进行转发，上报协议栈解析后再转发 */
        if ((mac_is_4addr((mac_ieee80211_frame_stru *)frame_ctl) == OAL_TRUE) && rx_ctl->bit_amsdu_enable) {
            continue;
        }

        if ((dpe_rx_get_eth_da(netbuf) != NULL) && (ether_is_multicast(dpe_rx_get_eth_da(netbuf)) == OAL_TRUE)) {
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
            hmac_rx_ap_mcast_w2w_proc(dpe_vap, netbuf, rx_ctl, w2w_list);
#else
            oal_netbuf_delete_nolock(netbuf, release_list);
            hmac_rx_mcast_frame(netbuf, rx_ctl);
#endif
            continue;
        }
        if (hmac_rx_da_is_in_same_bss(netbuf, rx_ctl, dpe_vap->uc_vap_id) == OAL_TRUE) {
            /* 目的用户已在AP的用户表中，进行WLAN_TO_WLAN转发 */
            oal_netbuf_delete_nolock(netbuf, release_list);
            oal_netbuf_list_tail_nolock(w2w_list, netbuf);
        }
        /* 该帧呆在链表里面 等待to lan */
    }
}
