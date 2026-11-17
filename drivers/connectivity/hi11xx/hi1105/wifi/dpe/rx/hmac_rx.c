/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : rx方向公共处理流程
 * 作    者 : wifi
 * 创建日期 : 2024年12月13日
 */

/* 头文件包含 */
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
#include "hmac_stat.h"
#endif
#ifdef _PRE_WLAN_FEATURE_RX_PN_CHECK
#include "hmac_rx_pn_check.h"
#endif
#ifdef _PRE_WLAN_FEATURE_DEFRAG
#include "hmac_rx_defrag.h"
#endif
#ifdef _PRE_WLAN_FEATURE_MINTP
#include "hmac_mintp_log.h"
#endif
#include "hmac_rx_reorder.h"
#include "dpe_wlan_resource.h"
#include "dpe_wlan_stat.h"
#include "host_hal_ext_if.h"
#include "dpe_tx_data.h"
#ifdef _PRE_WLAN_PKT_TIME_STAT
#include <hwnet/ipv4/wifi_delayst.h>
#endif
#ifdef _PRE_WLAN_FEATURE_SNIFFER
#ifdef CONFIG_HW_SNIFFER
#include <hwnet/ipv4/sysctl_sniffer.h>
#endif
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hmac_pwl.h"
#endif
#include "dpe_sbuf.h"
#include "dpe_netdev.h"
#include "dpe_filter_reg.h"
#include "dpe_dpa_intf.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_C

/* 带锁接口 */
void hmac_rx_free_netbuf_list(oal_netbuf_head_stru *netbuf_hdr, uint16_t num_buf)
{
    oal_netbuf_stru *netbuf = NULL;
    uint16_t us_idx;

    if (oal_unlikely(netbuf_hdr == NULL)) {
        return;
    }

    for (us_idx = num_buf; us_idx > 0; us_idx--) {
        netbuf = oal_netbuf_delist(netbuf_hdr);
        if (netbuf != NULL) {
            dpe_netbuf_free(netbuf);
        }
    }
}

/* 无锁接口 */
uint32_t hmac_rx_netbuf_list_free(oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next = NULL;
    uint32_t cnt = 0;

    while (netbuf != NULL) {
        next = oal_netbuf_next(netbuf);
        dpe_netbuf_free(netbuf);
        netbuf = next;
        cnt++;
    }
    return cnt;
}

/*
 * 函 数 名  : hmac_rx_free_netbuf_list
 * 功能描述  : 释放指定个数的netbuf
 * 1.日    期  : 2012年12月6日
 *   修改内容  : 新生成函数
 */
void hmac_rx_free_netbuf(oal_netbuf_stru *netbuf, uint16_t nums)
{
    oal_netbuf_stru *netbuf_temp = NULL;
    uint16_t us_netbuf_num;

    if (oal_unlikely(netbuf == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "{hmac_rx_free_netbuf::netbuf null.}\r\n");
        return;
    }

    for (us_netbuf_num = nums; us_netbuf_num > 0; us_netbuf_num--) {
        netbuf_temp = oal_netbuf_next(netbuf);
        /* 减少netbuf对应的user引用计数 */
        dpe_netbuf_free(netbuf);
        netbuf = netbuf_temp;
        if (netbuf == NULL) {
            if (oal_unlikely(us_netbuf_num != 1)) {
                oam_error_log2(0, OAM_SF_DPA, "{hmac_rx_free_netbuf::netbuf list broken, us_netbuf_num[%d]nums[%d].}",
                    us_netbuf_num, nums);
                return;
            }
            break;
        }
    }
}

/*
 * 功能描述  : 将netbuf链加入netbuf_head结构
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_rx_netbuf_join_to_list(oal_netbuf_stru *netbuf, oal_netbuf_head_stru *list)
{
    oal_netbuf_stru *next = NULL;
    uint32_t netbuf_cnt = 0;
    while (netbuf != NULL) {
        next = oal_netbuf_next(netbuf);
        oal_netbuf_list_tail_nolock(list, netbuf);
        netbuf = next;
        netbuf_cnt++;
    }
    return netbuf_cnt;
}

/*
 * 功能描述  : 将接收上下文中的netbuf链加入链表尾部
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_rx_context_netbuf_add_to_list(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *list, uint8_t buff_is_valid)
{
    oal_netbuf_stru *netbuf = rx_context->netbuf;

    if (buff_is_valid) {
        hmac_rx_netbuf_join_to_list(netbuf, list);
    }
    rx_context->netbuf = NULL;
}

uint32_t g_wifi_trx_log = 0;
void hmac_rx_route_print(hal_host_device_stru *hal_device, uint8_t step, mac_rx_ctl_stru *mac_rx_ctl)
{
    if ((mac_rx_ctl != NULL) && (hal_device != NULL) && (g_wifi_trx_log & HAL_LOG_RX_ROUTE_LOG)) {
        oam_warning_log4(hal_device->device_id, OAM_SF_DPA,
            "{rx_route_print::rx step[%d],tid[%d],process_flag[%d],seqnum[%d]}",
            step, mac_rx_ctl->bit_rx_tid, mac_rx_ctl->bit_process_flag, mac_rx_ctl->us_seq_num);
    }
}

OAL_STATIC void hmac_skb_info_dump(oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (cb == NULL) {
        return;
    }

    oam_warning_log3(0, OAM_SF_DPA, "{hmac_skb_info_dump::mac_vap_id[%d] hal_vap_id[%d] lut_user_id[%d]}",
        mac_get_rx_cb_mac_vap_id(cb), mac_get_rx_cb_hal_vap_id(cb), cb->bit_rx_user_id);
    oam_warning_log2(0, OAM_SF_DPA, "{hmac_skb_info_dump::amsdu[%d] first_msdu[%d]}",
        mac_rxcb_is_amsdu(cb), mac_get_rx_cb_is_first_sub_msdu(cb));

    oal_print_hex_dump((uint8_t *)cb, sizeof(mac_rx_ctl_stru), HEX_DUMP_GROUP_SIZE, "rx cb:");
}

OAL_STATIC void __hmac_hal_vap_info_dump(hal_host_device_stru *hal_device)
{
    uint8_t hal_vap_id;
    hal_vap_status_info *info = NULL;

    for (hal_vap_id = 0; hal_vap_id < dpe_mac_chip_get_hal_max_vap_num(); hal_vap_id++) {
        info = &hal_device->hal_vap_sts_info[hal_vap_id];
        oam_warning_log3(0, OAM_SF_DPA, "{__hmac_hal_vap_info_dump::hal_vap_id[%d], mac_vap_id[%d] hal_vap_valid[%d]}",
            hal_vap_id, info->mac_vap_id, info->hal_vap_valid);
    }
}

OAL_STATIC void hmac_hal_vap_info_dump(void)
{
    uint8_t hal_device_id;
    uint8_t hal_dev_num = mac_chip_get_hal_dev_num();

    for (hal_device_id = 0; hal_device_id < hal_dev_num; hal_device_id++) {
        __hmac_hal_vap_info_dump(hal_get_host_device(hal_device_id));
    }
}

OAL_STATIC void hmac_mac_vap_info_dump(dpe_wlan_vap_stru *dpe_vap)
{
    oam_warning_log2(0, OAM_SF_DPA, "{hmac_mac_vap_info_dump::mac_vap_id[%d] device_id[%d]}",
        dpe_vap->uc_vap_id, dpe_vap->uc_device_id);
}

OAL_STATIC void hmac_rx_enqueue_vap_abnormal_handle(oal_netbuf_stru *netbuf, uint8_t vap_id)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_id);
    if (dpe_vap != NULL) {
        hmac_mac_vap_info_dump(dpe_vap);
    }
    hmac_skb_info_dump(netbuf);
    hmac_hal_vap_info_dump();
}

void hmac_rx_vip_info_proc_rx_ctl_print(uint8_t vap_idx, mac_rx_ctl_stru *rx_ctrl, mac_ether_header_stru *ether_hdr)
{
    if (rx_ctrl == NULL || ether_hdr == NULL) {
        return;
    }
    oam_warning_log3(vap_idx, OAM_SF_DPA, "{rx_vip_info::dmac:%x:XX:XX:XX:%x:%x]",
        ether_hdr->auc_ether_dhost[MAC_ADDR_0],
        ether_hdr->auc_ether_dhost[MAC_ADDR_4], ether_hdr->auc_ether_dhost[MAC_ADDR_5]);
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oam_warning_log4(vap_idx, OAM_SF_DPA,
        "{rx_vip_info::user_id[%d] send to wlan smac: %x:XX:XX:XX:%x:%x]", rx_ctrl->bit_rx_user_id,
        ether_hdr->auc_ether_shost[MAC_ADDR_0],
        ether_hdr->auc_ether_shost[MAC_ADDR_4], ether_hdr->auc_ether_shost[MAC_ADDR_5]);
    oam_warning_log4(vap_idx, OAM_SF_DPA, "{rx_vip_info::VIP data process_flag[%d], tid[%d], seq[%d], start_seq[%d]",
        rx_ctrl->bit_process_flag, rx_ctrl->bit_rx_tid, rx_ctrl->us_seq_num, rx_ctrl->bit_start_seqnum);
    oam_warning_log2(vap_idx, OAM_SF_DPA, "{rx_vip_info:: VIP data release_start[%d], release_end[%d]",
        rx_ctrl->bit_release_start_sn, rx_ctrl->bit_release_end_sn);
#endif
}

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
OAL_STATIC OAL_INLINE oal_bool_enum hmac_rx_eth_frame_to_net(uint8_t vap_id, oal_netbuf_stru *netbuf)
{
    hmac_vap_stru *vap = mac_res_get_hmac_vap(vap_id);
    mac_ether_header_stru *eth_hdr = (mac_ether_header_stru *)oal_netbuf_data(netbuf);
    mac_rx_ctl_stru *cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    hmac_rx_frame_ctrl_enum ret = HMAC_RX_FRAME_CTRL_GOON;

    if ((vap == NULL) || (cb == NULL)) {
        return OAL_FALSE;
    }
    if (ether_is_multicast(eth_hdr->auc_ether_dhost) == OAL_FALSE) {
        oal_atomic_inc(&(vap->rx_unicast_pkt_to_lan));
        cb->bit_mcast_bcast = 0;
    } else {
        cb->bit_mcast_bcast = 1;
    }
    if (hmac_rx_ring_switch_enabled() == OAL_FALSE) {
        return OAL_TRUE;
    }
    ret = hmac_host_rx_filter_encrypt(vap, cb->bit_rx_user_id, cb, netbuf);
    if (ret == HMAC_RX_FRAME_CTRL_DROP) {
        return OAL_FALSE;
    }
    return OAL_TRUE;
}
#endif

void hmac_rx_skb_netif_rpt(uint8_t vap_id, oal_netbuf_head_stru *netbuf_list)
{
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_netbuf_stru  *netbuf = NULL;
    oal_netbuf_stru  *next_netbuf = NULL;
    oal_switch_enum_uint8 en_eth_switch = oam_ota_get_switch(OAM_OTA_SWITCH_RX_ETH_FRAME);
#endif
    oal_net_device_stru *net_dev = dpe_vap_get_net_device(vap_id);

    if (net_dev == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "{hmac_rx_enqueue_vap_abnormal_handle::vap invalid!}");
        hmac_rx_enqueue_vap_abnormal_handle(oal_netbuf_peek(netbuf_list), vap_id);
        dpe_netbuf_free_list_all(netbuf_list, oal_netbuf_list_len(netbuf_list));
        return;
    }

    /* dpe下netbuf是链表，非dpe netbuf为单个netbuf */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_wlan_to_filter(net_dev, vap_id, netbuf_list);
#else
    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, netbuf_list) {
        if (hmac_rx_eth_frame_to_net(vap_id, netbuf) == OAL_FALSE) {
            oal_netbuf_delete_nolock(netbuf, netbuf_list);
            oal_netbuf_free(netbuf);
            continue;
        }
        if (en_eth_switch == OAL_SWITCH_ON) {
            hmac_rx_netbuf_force_ota_report(netbuf);
        }
        /* 对protocol模式赋值, pull ETH_HLEN至payload, 去掉ETH头 */
        oal_netbuf_protocol(netbuf) = oal_eth_type_trans(netbuf, net_dev);

        /* 接收线程使能则提交接收线程处理,线程决定直接传递orNAPI处理 */
        if (hmac_get_rxthread_enable() == OAL_TRUE) {
            continue;
        }

    #ifdef _PRE_DELAY_DEBUG
        hmac_wifi_delay_rx_notify(net_dev, netbuf);
    #endif
        /* 清空cb */
        memset_s(oal_netbuf_cb(netbuf), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());

    #ifdef _PRE_WLAN_FEATURE_ESPE
        hmac_espe_recv(netbuf);
    #else
        oal_netif_rx_ni(netbuf);
    #endif
    }

    if (hmac_get_rxthread_enable() == OAL_TRUE) {
        hmac_rxdata_netbuf_enqueue(netbuf_list, net_dev);
    }
#endif
}

/*
 * 功能描述  : 通用统计处理流程
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_host_rx_static_proc(hmac_host_rx_context_stru *rx_context)
{
    dpe_wlan_vap_stru *dpe_vap = rx_context->dpe_vap;
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    mac_rx_ctl_stru *rx_ctl = NULL;

    for (;netbuf != NULL; netbuf = oal_netbuf_next(netbuf)) {
        hmac_stat_vap_rx_netbuf(dpe_vap->uc_vap_id, netbuf);
        hmac_stat_device_rx_msdu(oal_netbuf_len(netbuf));
        rx_ctl = (mac_rx_ctl_stru*)oal_netbuf_cb(netbuf);
        dpe_wlan_stat_user_rx_netbuf(rx_ctl->bit_rx_user_id, netbuf);
    }
}
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_rx_set_delivery_sbuf_to_host(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    oal_netbuf_head_stru rpt_list;

    oal_netbuf_list_head_init_nolock(&rpt_list);
    oal_netbuf_list_tail_nolock(&rpt_list, netbuf);

    /* 标记数据帧来源,host有特殊处理,并且回传DPA */
    rx_ctl->bit_transfer_from_dpa = 1;
    rx_ctl->bit_transfer_from_task = 0; // single接口可以忽略
    hmac_rx_skb_netif_rpt(rx_ctl->uc_mac_vap_id, &rpt_list);
}

OAL_STATIC uint32_t dpe_rx_data_frame_to_acpu(oal_netbuf_stru *netbuf, uint8_t uc_vap_id)
{
    /* 分片帧acpu处理 */
    frw_event_param_stru param = {
        .type = FRW_EVENT_TYPE_WLAN_DRX,
        .subtype = DMAC_WLAN_DRX_EVENT_SUB_TYPE_RX_DATA_DPA,
        .vap_id = uc_vap_id,
        .hal_device_id = 0,
        .pipeline = FRW_EVENT_PIPELINE_STAGE_1,
        .transfer_event_to = FRW_EVENT_TO_ACORE,  /* 去往ACPU方向 */
        .hcc_extend = 1, /* 固定1 */
        .payload_size = oal_netbuf_len(netbuf),
        .payload = NULL,
        .netbuf = netbuf,
    };
    if (frw_post_event(&param) != OAL_SUCC) {
        oal_print_hex_dump((uint8_t *)oal_sbuf_cb(netbuf),
            (int32_t)sizeof(dpe_frw_event_stru), 32, "invaild frw extend hdr: "); // 32代表长度
        dpe_netbuf_free(netbuf);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

void hmac_rx_mcast_frame(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    if (dpe_is_support_80211_dmi_transfer() == OAL_TRUE) {
        /* 标记组播帧在filter透传 */
        rx_ctl->bit_amsdu_enable = 0;
        rx_ctl->uc_msdu_in_buffer = 0;
        rx_ctl->bit_is_first_buffer = 1;
        rx_ctl->bit_mcast_bcast = 1;

        dpe_rx_set_delivery_sbuf_to_host(netbuf, rx_ctl);
    } else {
        oam_error_log1(0, OAM_SF_DPA, "{hmac_rx_mcast_frame::dpe_is_support_80211_dmi_transfer is [%d]!}",
                       dpe_is_support_80211_dmi_transfer());
    }
}
#endif

/*
 * 功能描述  : host rx接收方向去分片流程封装
 * 1.日    期  : 2020.5.21
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC oal_netbuf_stru *hmac_rx_defrag(dpe_wlan_user_stru *dpe_user, oal_netbuf_stru *netbuf,
    mac_rx_ctl_stru *rx_ctl)
{
    mac_ieee80211_frame_stru *pst_mac_hdr = NULL;
    uint8_t uc_frag_num;
    uint8_t en_more_frag;

    /* 不支持分片 */
    if ((rx_ctl->bit_amsdu_enable == OAL_TRUE) || (rx_ctl->bit_frame_format != MAC_FRAME_TYPE_80211)) {
        return netbuf;
    }

    /* 没有分片,直接返回 */
    pst_mac_hdr = (mac_ieee80211_frame_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf);
    if (pst_mac_hdr == NULL) {
        return netbuf;
    }
    uc_frag_num = (uint8_t)pst_mac_hdr->bit_frag_num;
    en_more_frag = (uint8_t)pst_mac_hdr->st_frame_control.bit_more_frag;
    if (en_more_frag == 0 && uc_frag_num == 0) {
        return netbuf;
    }
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    if (dpe_is_support_80211_dmi_transfer() == OAL_TRUE) {
        /* 标记分片帧在filter透传 */
        dpe_rx_set_delivery_sbuf_to_host(netbuf, rx_ctl);
    } else {
        dpe_rx_data_frame_to_acpu(netbuf, mac_get_rx_cb_mac_vap_id(rx_ctl));
    }
    return NULL; /* 已释放, 固定返回NULL, 后续流程不处理 */
#else
    return hmac_defrag_process(dpe_user->us_assoc_id, netbuf);
#endif
}

OAL_STATIC uint32_t hmac_rx_80211_frame(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl, uint8_t uc_vap_id)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    if (dpe_is_support_80211_dmi_transfer() == OAL_TRUE) {
        /* 标记分片帧在filter透传 */
        dpe_rx_set_delivery_sbuf_to_host(netbuf, rx_ctl);
    } else {
        dpe_rx_data_frame_to_acpu(netbuf, uc_vap_id);
    }
    return OAL_FAIL; /* 已释放, 固定返回FAIL, 后续流程不处理 */
#else
    /* 80211转换成8023 */
    if (hmac_rx_proc_80211_to_eth(netbuf, rx_ctl, uc_vap_id) != OAL_SUCC) {
        dpe_netbuf_free(netbuf);
        return OAL_FAIL;
    }
    return OAL_SUCC;
#endif
}

/*
 * 功能描述  : rx_context上下文中msdu转化成8023
 * 1.日    期  : 2021年1月4日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_rx_context_prepare_msdu_list_to_eth(hmac_host_rx_context_stru *rx_context)
{
    mac_rx_ctl_stru *rx_ctrl = NULL;
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    oal_netbuf_stru *next_netbuf = NULL;
    oal_netbuf_head_stru netbuf_head;

    oal_netbuf_list_head_init_nolock(&netbuf_head);
    while (netbuf != NULL) {
        next_netbuf = oal_netbuf_next(netbuf);
        rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        if (rx_ctrl->bit_frame_format == MAC_FRAME_TYPE_80211) {
            if (hmac_rx_80211_frame(netbuf, rx_ctrl, rx_context->dpe_vap->uc_vap_id) != OAL_SUCC) {
                netbuf = next_netbuf;
                continue;
            }
        }
        if (oal_unlikely(rx_ctrl->bit_data_type == MAC_DATA_RTSP)) {
            oam_warning_log0(rx_ctrl->uc_mac_vap_id, OAM_SF_DPA, "{dpe rx::rtsp}");
        } else if (oal_unlikely(rx_ctrl->bit_data_type <= MAC_DATA_ARP_REQ)) {
            oam_warning_log3(rx_ctrl->uc_mac_vap_id, OAM_SF_DPA,
                "{wifi_dpe_rx::user[%d] rx vip type%d [0:dhcp 1:eapol 2:arp_rsp 3:arp_req] mcast %d}",
                rx_ctrl->bit_rx_user_id, rx_ctrl->bit_data_type, ether_is_multicast(dpe_rx_get_eth_da(netbuf)));
            hmac_rx_vip_info_proc_rx_ctl_print(rx_context->dpe_vap->uc_vap_id, rx_ctrl,
                (mac_ether_header_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf));
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
            /* 不支持DPA时才需要做VIP帧处理, DPA下由GRO流程处理 */
            if (dpe_is_support_dpe_offload() != OAL_TRUE) {
                hmac_rx_vip_info_proc(rx_context->dpe_vap->uc_vap_id, rx_ctrl->bit_data_type,
                    rx_ctrl->bit_cipher_type, netbuf);
            }
#endif
        }
        oal_netbuf_list_tail_nolock(&netbuf_head, netbuf);
        netbuf = next_netbuf;
    }

    if (oal_netbuf_list_empty(&netbuf_head)) {
        rx_context->netbuf = NULL;
        return OAL_FAIL;
    }

    /* 将最后一个NETBUF置空 */
    oal_set_netbuf_next((oal_netbuf_tail(&netbuf_head)), NULL);
    rx_context->netbuf = oal_netbuf_peek(&netbuf_head);

    return OAL_SUCC;
}

uint32_t hmac_rx_proc_netbuf(hmac_host_rx_context_stru *rx_context, oal_netbuf_head_stru *rpt_list)
{
    uint8_t buff_is_valid = OAL_TRUE;
    oal_netbuf_head_stru release_list;
    oal_netbuf_head_stru w2w_list;
    dpe_wlan_vap_stru *dpe_vap = rx_context->dpe_vap;

    hal_host_rx_tcp_udp_checksum(rx_context->netbuf);
#ifdef _PRE_WLAN_FEATURE_MINTP
    hmac_mintp_log((uint8_t *)rx_context->netbuf, MINTP_LOG_LVL_2, MINTP_LOG_DATATYPE_SKB_NEXT_LIST, MINTP_LOG_TYPE_RX);
#endif
    /* release list包括需要转发和上报的netbuf */
    oal_netbuf_list_head_init_nolock(&release_list);
    if (hmac_rx_proc_reorder(rx_context, &release_list, &buff_is_valid) != OAL_SUCC) {
        return OAL_FAIL;
    }

    /* 此函数执行后rx context中不包含netbuf,全部挂在release list中 */
    hmac_rx_context_netbuf_add_to_list(rx_context, &release_list, buff_is_valid);

    /* APUT转发链更新 */
    oal_netbuf_list_head_init_nolock(&w2w_list);
    if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        hmac_rx_ap_w2w_proc(rx_context, &release_list, &w2w_list);
    }

    /* 剩下的报文全部上报协议栈 */
    oal_netbuf_queue_splice_tail_init(&release_list, rpt_list);

    g_pm_wlan_pkt_statis.host_rx_pkt += oal_netbuf_list_len(rpt_list) + oal_netbuf_list_len(&w2w_list);

    if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        hmac_rx_wlan_to_wlan_proc(dpe_vap, &w2w_list);
    }
    return OAL_SUCC;
}
/*
 * 函 数 名  : hmac_rx_is_qos_data_frame
 * 功能描述  : 判断是否是qos帧
 * 1.日    期  : 2020年5月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC oal_bool_enum_uint8 hmac_rx_is_qos_data_frame(mac_rx_ctl_stru *rx_ctl)
{
    uint8_t frame_type = mac_get_frame_type_and_subtype((uint8_t *)&rx_ctl->us_frame_control);

    return (frame_type != (WLAN_FC0_SUBTYPE_QOS | WLAN_FC0_TYPE_DATA)) ? OAL_FALSE : OAL_TRUE;
}

/*
 * 函 数 名   : hmac_rx_qos_data_need_drop
 * 功能描述   : 在未建ba场景下，软件检查qos data是否重复帧，此时硬件无法识别，sn 重复过滤，不重复更新sn
 * 1.日    期   : 2020-05-11
 *   作    者   : wifi
 */
OAL_STATIC oal_bool_enum_uint8 hmac_rx_qos_data_need_drop(hmac_host_rx_context_stru *rx_context)
{
    mac_rx_ctl_stru     *rx_ctl = rx_context->cb;
    dpe_wlan_user_stru *dpe_user = rx_context->dpe_user;
    hmac_tid_ba_stru       *hmac_tid = NULL;
    hmac_ba_rx_stru     *ba_rx_hdl = NULL;
    uint16_t             seq_frag_num;
    uint8_t              rx_tid;

    if (!hmac_rx_is_qos_data_frame(rx_ctl)) {
        return OAL_FALSE;
    }
    rx_tid = mac_get_rx_cb_tid(rx_ctl);
    if (!mac_tid_is_valid(rx_tid)) {
        oam_warning_log1(0, OAM_SF_DPA, "{hmac_rx_qos_data_need_drop:: tid invalid[%d]}", rx_tid);
        return OAL_TRUE;
    }

    /* qos 已建ba返回 */
    hmac_tid = dpe_get_tid_ba_info(dpe_user->us_assoc_id, rx_tid);
    if (hmac_tid == NULL) {
        return OAL_TRUE;
    }
    ba_rx_hdl = hmac_tid->pst_ba_rx_info;
    if (ba_rx_hdl != NULL && (ba_rx_hdl->en_ba_status == DMAC_BA_COMPLETE)) {
        return OAL_FALSE;
    }

    if (rx_ctl->bit_is_fragmented) {
        seq_frag_num = ((uint16_t)(rx_ctl->us_seq_num) << 4) | rx_ctl->bit_fragment_num; /* 合并sn放高4位 */
    } else {
        seq_frag_num = rx_ctl->us_seq_num;
    }

    /* no ba qos data，retry 且seq num相同则过滤，否则更新 */
    if (((mac_header_frame_control_stru *)&rx_ctl->us_frame_control)->bit_retry == OAL_TRUE &&
        (seq_frag_num == hmac_tid->qos_last_seq_frag_num)) {
        oam_warning_log2(dpe_user->uc_vap_id, OAM_SF_DPA,
            "{hmac_rx_qos_data_need_drop::tid is[%d],qos duplicate frame[%d].}", rx_tid, seq_frag_num);
        return OAL_TRUE;
    }

    hmac_tid->qos_last_seq_frag_num = seq_frag_num;
    return OAL_FALSE;
}

/*
 * 功能描述  : 获取netbuf对应以太帧类型,兼容80211及8023
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint16_t hmac_rx_netbuf_get_ether_type(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    uint16_t ether_type = 0;
    uint16_t netbuf_len = oal_netbuf_len(netbuf);
    uint16_t frame_formate = rx_ctl->bit_frame_format;
    uint8_t *header = dpe_get_rx_netbuf_hdr_addr(netbuf);

    if (header == NULL) {
        return ether_type;
    }

    return mac_rx_data_get_ether_type(header, netbuf_len, rx_ctl->uc_mac_header_len, frame_formate);
}
/*
 * 函 数 名  : hmac_11i_port_filter
 * 功能描述  : 接收数据，安全相关过滤
 * 1.日    期  : 2014年1月6日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_11i_ether_type_filter(uint8_t port_valid, uint16_t us_ether_type)
{
    if (port_valid == OAL_FALSE) { /* 判断端口是否打开 */
        /* 接收数据时，针对非EAPOL 的数据帧做过滤 */
#ifdef _PRE_WLAN_FEATURE_PWL
        if ((oal_byteorder_host_to_net_uint16(ETHER_TYPE_PAE) != us_ether_type) &&
            (oal_byteorder_host_to_net_uint16(ETHER_TYPE_WAI) != us_ether_type)) {
#else
        if (oal_byteorder_host_to_net_uint16(ETHER_TYPE_PAE) != us_ether_type) {
#endif
            oam_warning_log1(0, OAM_SF_DPA,
                "{hmac_11i_ether_type_filter::TYPE 0x%04x not permission， drop.}", us_ether_type);
            return OAL_ERR_CODE_SECURITY_PORT_INVALID;
        }
    }
    return OAL_SUCC;
}

/*
 * 功能描述  : 通用业务过滤流程
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC hmac_rx_frame_ctrl_enum hmac_host_rx_feature_filter(hmac_host_rx_context_stru *rx_context)
{
    dpe_wlan_vap_stru *dpe_vap = rx_context->dpe_vap;
    dpe_wlan_user_stru *dpe_user = rx_context->dpe_user;
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    mac_rx_ctl_stru *mac_rx_ctl = NULL;
    uint16_t ether_type;

    mac_rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (mac_rx_ctl == NULL) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }
    if (dpe_vap == NULL || dpe_user == NULL) {
        oam_warning_log1(0, OAM_SF_DPA, "{hmac_host_rx_feature_filter::user[%d] null!}",
            mac_rx_ctl->bit_rx_user_id);
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    if (hmac_rx_qos_data_need_drop(rx_context) == OAL_TRUE) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    ether_type = hmac_rx_netbuf_get_ether_type(netbuf, mac_rx_ctl);
    if (hmac_11i_ether_type_filter(dpe_user->en_port_valid, ether_type) != OAL_SUCC) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    return HMAC_RX_FRAME_CTRL_GOON;
}
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
OAL_STATIC void hmac_dmi_transfer_to_dpa(hmac_host_rx_context_stru *rx_context, oal_netbuf_stru *netbuf)
{
    uint8_t vap_id = rx_context->dpe_vap->uc_vap_id;
    oal_net_device_stru *dev = dpe_vap_get_net_device(vap_id);
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (tx_ctl == NULL) {
        return;
    }
    tx_ctl->st_expand_cb.is_dpa_transfer = OAL_TRUE;
    if (dev != NULL) {
        netbuf->dev = dev;
        hmac_dpa_sms_tx_ops(netbuf, tx_ctl, OAL_FALSE, rx_context->cb->bit_maa_from_dpa);
    } else {
        oam_warning_log0(vap_id, OAM_SF_DPA, "{hmac_dmi_transfer_to_dpa:: netdev is NULL, vap may del}");
    }
}
uint32_t hmac_rx_specific_frame_to_dpa(hmac_host_rx_context_stru *rx_context)
{
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    oal_netbuf_stru *next_netbuf = NULL;
    frw_event_stru *frw_event = NULL;
    frw_event_mem_stru *frw_event_mem = NULL;
    oal_netbuf_head_stru netbuf_head;
    oal_netbuf_list_head_init_nolock(&netbuf_head);

    while (netbuf != NULL) {
        next_netbuf = netbuf->next;
        /* 非DPA流转帧、或组播帧继续入队后续处理 */
        /* 分片长度超限，则提交协议栈 */
        if (oal_netbuf_len(netbuf) > 1536) { /* 1536指示dmi最大payload */
            oam_warning_log1(0, OAM_SF_DPA,
                "{hmac_rx_specific_frame_to_dpa:: frag frame larger than MTU %d}", oal_netbuf_len(netbuf));
            oal_netbuf_list_tail_nolock(&netbuf_head, netbuf);

            netbuf = next_netbuf;
            continue;
        }
        /* 支持GSO则透传软转 */
        if (hmac_is_support_80211_dmi_transfer() == OAL_TRUE) {
            hmac_dmi_transfer_to_dpa(rx_context, netbuf);
            netbuf = next_netbuf;
            continue;
        }
        /* 不支持GSO则HCC流转 */
        if (frw_event_mem == NULL) {
            frw_event_mem = frw_event_alloc_m(sizeof(dmac_tx_event_stru));
            if (oal_unlikely(frw_event_mem == NULL)) {
                oam_warning_log0(0, OAM_SF_DPA, "{hmac_rx_specific_frame_to_dpa::event mem alloc failed}");
                dpe_netbuf_free(netbuf);
                netbuf = next_netbuf;
                continue;
            }
        }
        frw_event = frw_get_event_stru(frw_event_mem);
        frw_event_hdr_init(&frw_event->st_event_hdr, FRW_EVENT_TYPE_HOST_DRX, DMAC_TX_HOST_TO_DPA,
            sizeof(dmac_tx_event_stru), FRW_EVENT_PIPELINE_STAGE_1,
            rx_context->dpe_vap->uc_chip_id, rx_context->dpe_vap->uc_device_id, rx_context->dpe_vap->uc_vap_id);

        ((dmac_tx_event_stru *)frw_event->auc_event_data)->pst_netbuf = netbuf;

        /* h2d传输netbuf时, 传输失败的netbuf由hcc统一释放, hmac无需释放 */
        if (oal_unlikely(frw_event_dispatch_event(frw_event_mem) != OAL_SUCC)) {
            oam_warning_log0(0, OAM_SF_DPA, "{hmac_rx_specific_frame_to_dpa::frw_event_dispatch_event failed}");
            dpe_netbuf_free(netbuf);
        }

        netbuf = next_netbuf;
    }
    /* 释放事件内存 */
    if (frw_event_mem != NULL) {
        frw_event_free_m(frw_event_mem);
    }
    /* 全部流转至DPA */
    if (oal_netbuf_list_empty(&netbuf_head)) {
        rx_context->netbuf = NULL;
        rx_context->cb = NULL;
        return OAL_SUCC;
    }

    /* 继续提交协议栈 */
    oal_set_netbuf_next((oal_netbuf_tail(&netbuf_head)), NULL);
    rx_context->netbuf = oal_netbuf_peek(&netbuf_head);
    rx_context->cb = (mac_rx_ctl_stru *)oal_netbuf_cb(rx_context->netbuf);
    return OAL_FAIL;
}
#endif

/*
 * 功能描述  : 通用业务处理流程
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_rx_proc_feature(hmac_host_rx_context_stru *rx_context, oal_netbuf_head_stru *rpt_list)
{
    oal_netbuf_stru *netbuf = rx_context->netbuf;

    if (hmac_host_rx_feature_filter(rx_context) == HMAC_RX_FRAME_CTRL_DROP) {
        return OAL_FAIL;
    }

    if (g_wlan_spec_cfg->feature_hw_wapi == OAL_FALSE) {
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        oam_error_log0(0, OAM_SF_DPA, "{hmac_rx_proc_feature::feature_hw_wapi must be enabled!}");
#else
#ifdef _PRE_WLAN_FEATURE_WAPI
        netbuf = hmac_wapi_netbuf_rx_decrypt_sw(rx_context->dpe_vap->uc_vap_id,
            rx_context->dpe_user->us_assoc_id, netbuf);
        if (netbuf == NULL) {
            /* 解密失败，已经释放netbuf，此处返回成功，不需要释放netbuf */
            return OAL_SUCC;
        }
#endif
#endif
    }

    /* 分片处理 */
    netbuf = hmac_rx_defrag(rx_context->dpe_user, netbuf, rx_context->cb);
    if (netbuf == NULL) {
        return OAL_SUCC;
    }

    /* WAPI解密/defrag转换后更新参数 */
    rx_context->netbuf = netbuf;
    rx_context->cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);

    /* 80211转换成8023, 失败已释放 */
    if (hmac_rx_context_prepare_msdu_list_to_eth(rx_context) != OAL_SUCC) {
        return OAL_SUCC;
    }
    netbuf = rx_context->netbuf;
    rx_context->cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (rx_context->cb == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* HOST接收流程处理DPA转发过来并且处理完毕后，组播帧去往内核,单播帧则去DPA进重排序 */
    if ((rx_context->cb->bit_transfer_from_dpa == 1) && (ether_is_multicast(dpe_rx_get_eth_da(netbuf)) == OAL_FALSE)) {
        if (hmac_rx_specific_frame_to_dpa(rx_context) == OAL_SUCC) {
            return OAL_SUCC;
        }
    }
#endif

    if (hmac_rx_proc_netbuf(rx_context, rpt_list) != OAL_SUCC) {
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

/*
 * 功能描述  : rx data aput数据流处理
 * 1.日    期  : 2020年03月6日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_data_ap_proc(dpe_wlan_vap_stru *dpe_vap, oal_netbuf_head_stru *p_netbuf_head)
{
    oal_netbuf_stru          *netbuf = NULL;
    oal_netbuf_stru          *temp_netbuf = oal_netbuf_peek(p_netbuf_head);
    mac_rx_ctl_stru          *rx_ctl = NULL;
    uint16_t                  netbuf_num = (uint16_t)oal_netbuf_list_len(p_netbuf_head);
    oal_netbuf_head_stru      w2w_netbuf_hdr;
    oal_netbuf_head_stru      w2l_netbuf_hdr;
    dpe_wlan_vap_stru        *dpe_vap_temp = NULL;

    oal_netbuf_list_head_init_nolock(&w2w_netbuf_hdr);
    oal_netbuf_list_head_init_nolock(&w2l_netbuf_hdr);
    while (netbuf_num != 0) {
        netbuf = temp_netbuf;
        if (netbuf == NULL) {
            break;
        }

        temp_netbuf = oal_netbuf_next(netbuf);
        oal_set_netbuf_next(netbuf, NULL);
        oal_set_netbuf_prev(netbuf, NULL);

        netbuf_num = oal_sub(netbuf_num, 1);
        rx_ctl     = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        dpe_vap_temp = dpe_wlan_vap_get(rx_ctl->uc_mac_vap_id);
        if (dpe_vap_temp == NULL) {
            hmac_rx_free_netbuf(netbuf, (uint16_t)1);
            continue;
        }
        /* rx reoder队列出来的包应该都是同vap的 */
        if (dpe_vap_temp->uc_vap_id != dpe_vap->uc_vap_id) {
            oam_error_log2(0, OAM_SF_DPA, "hmac_rx_data_ap_proc::vap id error[%d][%d]",
                dpe_vap_temp->uc_vap_id, dpe_vap->uc_vap_id);
        }

        if ((dpe_rx_get_eth_da(netbuf) != NULL) && (ether_is_multicast(dpe_rx_get_eth_da(netbuf)) == OAL_TRUE)) {
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
            hmac_rx_ap_mcast_data_proc(netbuf, rx_ctl, &w2w_netbuf_hdr);
            oal_netbuf_list_tail_nolock(&w2l_netbuf_hdr, netbuf);
#else
            hmac_rx_mcast_frame(netbuf, rx_ctl);
#endif
            continue;
        }

        /* check if da belong to the same bss */
        if (hmac_rx_da_is_in_same_bss(netbuf, rx_ctl, dpe_vap_temp->uc_vap_id) == OAL_TRUE) {
            /* 目的用户已在AP的用户表中，进行WLAN_TO_WLAN转发 */
            oal_netbuf_list_tail_nolock(&w2w_netbuf_hdr, netbuf);
        } else {
            oal_netbuf_list_tail_nolock(&w2l_netbuf_hdr, netbuf);
        }
    }

    hmac_rx_enqueue_list(&w2l_netbuf_hdr, OAL_TRUE);
    /*  将MSDU链表交给发送流程处理 */
    hmac_rx_wlan_to_wlan_proc(dpe_vap, &w2w_netbuf_hdr);
}

void hmac_rx_enqueue_list(oal_netbuf_head_stru *list, uint8_t is_same_vap)
{
    uint8_t last_vap_id;
    mac_rx_ctl_stru *cb = NULL;
    oal_netbuf_stru *next_netbuf = NULL;
    oal_netbuf_stru *netbuf = NULL;
    oal_netbuf_head_stru netbuf_list; /* 同一vap的包串链 */
    oal_netbuf_list_head_init_nolock(&netbuf_list);

    /* 1.vap串链  2. pn check 3. mcast计数 */
    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, list) {
        oal_netbuf_delete_nolock(netbuf, list);
        cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
#ifdef _USE_CACHE_PRELOAD
        prefetch_cached_ddr(next_netbuf);
#endif

#ifdef _PRE_WLAN_FEATURE_RX_PN_CHECK
        if (hmac_rx_pn_check(netbuf) != OAL_SUCC) {
            dpe_netbuf_free(netbuf);
            continue;
        }
#endif
        /* 硬转802.3帧转发, 4字节空间 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        dpe_wlan_rx_filter_user_data_set(netbuf, cb);
#endif
        dpe_wlan_rx_delay_notify(netbuf, -1, RX_REORDER);
        if (is_same_vap == OAL_TRUE) {
            oal_netbuf_list_tail_nolock(&netbuf_list, netbuf);
            continue;
        }

        /* 1.获取首帧，保存vap id */
        if (oal_netbuf_list_len(&netbuf_list) == 0) {
            oal_netbuf_list_tail_nolock(&netbuf_list, netbuf);
            last_vap_id = cb->uc_mac_vap_id;
            continue;
        }
        /* 2.vap id不一致，netbuf list存的包统一传递给filter */
        if (last_vap_id != cb->uc_mac_vap_id) {
            hmac_rx_skb_netif_rpt(last_vap_id, &netbuf_list);
            /* 3.初始化，重新开始攒包 */
            oal_netbuf_list_head_init_nolock(&netbuf_list);
            last_vap_id = cb->uc_mac_vap_id;
        }
        oal_netbuf_list_tail_nolock(&netbuf_list, netbuf);
    }
    /* 4.遍历结束，剩余的包一定是同一vap的，统一传递给filter */
    if (oal_netbuf_list_len(&netbuf_list) != 0) {
        cb = (mac_rx_ctl_stru *)oal_netbuf_cb(oal_netbuf_peek(&netbuf_list));
        hmac_rx_skb_netif_rpt(cb->uc_mac_vap_id, &netbuf_list);
    }
}

/*
 * 功能描述  : 报文上报协议栈
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_rpt_netbuf(oal_netbuf_head_stru *list)
{
    hmac_rx_enqueue_list(list, OAL_FALSE);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    if (hmac_get_rxthread_enable() == OAL_TRUE) {
        g_hisi_softwdt_check.rxshed_rpt++;
        hmac_rxdata_sched();
    }
#endif
}
void hmac_cb_size_protect(void)
{
    oal_build_bug_on(sizeof(mac_tx_ctl_stru) != 48); // tx cb 固定48字节
    oal_build_bug_on(sizeof(mac_rx_ctl_stru) != 48); // rx cb 固定48字节
}