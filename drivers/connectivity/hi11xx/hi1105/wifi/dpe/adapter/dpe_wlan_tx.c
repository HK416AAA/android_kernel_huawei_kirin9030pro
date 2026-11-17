/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_tx.c
 * 作    者 :
 * 创建日期 : 2024年11月22日
 */

/* 1 头文件包含 */
#include "conn_dmi_msg.h"
#include "dpe_tx_data.h"
#include "dpe_wlan_stat.h"
#include "hmac_rx_dev.h"
#include "hmac_rx.h"
#include "hmac_host_al_tx.h"
#include "host_hal_dma.h"
#include "host_hal_dscr.h"
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "bsp_sms.h"
#include "mac_data.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_TX_C

void dpe_wlan_tx_update_tid_by_sbuf(oal_netbuf_stru *netbuf,
    mac_tx_ctl_stru *tx_ctl, mac_ether_header_stru *ether_hdr, uint8_t is_rx_w2w)
{
    uint8_t curr_tid = 0;
    uint8_t *uc_ether_hdr = NULL;
    if (is_rx_w2w == OAL_FALSE) {
        switch (ether_hdr->us_ether_type) {
            case oal_host2net_short(ETHER_TYPE_IP):
                hmac_tx_classify_tid_by_ipv4(ether_hdr, oal_netbuf_len(netbuf), &curr_tid);
                break;
            case oal_host2net_short(ETHER_TYPE_IPV6):
                curr_tid = hmac_tx_classify_tid_by_ipv6(ether_hdr);
                break;
            default:
                break;
        }
    } else if (is_rx_w2w == OAL_TRUE) {
        uc_ether_hdr = (uint8_t *)ether_hdr;
        curr_tid = *(uc_ether_hdr + (DPE_NETBUF_CB_WIFI_INFO_LEN - 1));
    }

    /* 设置ac和tid到cb字段 */
    mac_get_cb_wme_tid_type(tx_ctl) = curr_tid;
    mac_get_cb_wme_ac_type(tx_ctl) = WLAN_WME_TID_TO_AC(curr_tid);
    /* 非ring约束: 更新tid7 */
    hmac_ring_tx_update_tid(tx_ctl);
}

OAL_STATIC OAL_INLINE void dpe_tx_addba_check_and_proc(uint8_t vap_idx, uint16_t user_idx, uint8_t tidno)
{
    hmac_tx_addba_msg_stru msg;
    hmac_tid_ba_stru *tid_ba_info = dpe_get_tid_ba_info(user_idx, tidno);
    if (tid_ba_info == NULL) {
        oam_warning_log2(0, OAM_SF_DPA, "{dpe_tx_addba_check_and_proc:: err user id %d, tid = %d}", user_idx, tidno);
        return;
    }
    if (tid_ba_info->tx_ba_status != DMAC_BA_INIT) {
        return;
    }
    tid_ba_info->tx_ba_status = DMAC_BA_INPROGRESS;

    msg.msg_type = DMI_WIFI_MSG_TX_ADDBA;
    msg.tidno = tidno;
    msg.vap_idx = vap_idx;
    msg.user_id = user_idx;
    if (conn_dmi_msg_data_send(CONN_DMI_MSG_WIFI_MSG, (uint8_t *)&msg, sizeof(hmac_tx_addba_msg_stru)) != OAL_SUCC) {
        tid_ba_info->tx_ba_status = DMAC_BA_INIT;
        oam_error_log2(0, OAM_SF_DPA, "{dpe_tx_addba_check_and_proc:: user id %d, tid = %d msg fail}", user_idx, tidno);
        return;
    }
    oam_warning_log2(0, OAM_SF_DPA,
        "{dpe_tx_addba_check_and_proc:: user id %d, tid = %d start addba}", user_idx, tidno);
}

void dpe_wlan_xmit(dpe_wlan_vap_stru *vap, oal_netbuf_stru *netbuf, uint8_t is_rx_w2w)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    dpe_wlan_user_stru *user = NULL;
    mac_ether_header_stru *ether_hdr = NULL;
    uint16_t us_user_idx;

    oal_set_netbuf_next(netbuf, NULL);
    oal_set_netbuf_prev(netbuf, NULL);

    /* VAP模式判断 */
    if (oal_unlikely(vap->en_vap_mode != WLAN_VAP_MODE_BSS_AP && vap->en_vap_mode != WLAN_VAP_MODE_BSS_STA)) {
        dpe_netbuf_free(netbuf);
        return;
    }
    /* 如果关联用户数量为0，则丢弃报文 */
    if (oal_unlikely(vap->us_user_nums == 0)) {
        dpe_netbuf_free(netbuf);
        return;
    }
    ether_hdr = (mac_ether_header_stru *)dpe_tx_get_eth_hdr_info(netbuf);
    us_user_idx = dpe_tx_get_user_id(vap, ether_hdr);
    user = (dpe_wlan_user_stru *)dpe_wlan_user_get(us_user_idx);
    if (oal_unlikely(user == NULL)) {
        dpe_netbuf_free(netbuf);
        return;
    }

    /* 来自acpu的数据包已提前清空msdu info，来自dpa stack和modem的数据包需要在此处清空msdu info */
    hal_host_tx_netbuf_init_msdu_dscr(netbuf, OAL_FALSE);

    dpe_tx_msdu_info_clear_check(netbuf);
    /* 申请并清空cb */
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    /* dpa栈/modem/aput二层转发不需要重复csum */
    tx_ctl->st_expand_cb.csum_type = 0;
    hmac_tx_cb_field_init(tx_ctl, vap->uc_vap_id, vap->en_vap_mode, us_user_idx, ether_hdr);
    dpe_wlan_tx_update_tid_by_sbuf(netbuf, tx_ctl, ether_hdr, is_rx_w2w);

    dpe_tx_addba_check_and_proc(vap->uc_vap_id, us_user_idx, mac_get_cb_wme_tid_type(tx_ctl));

    if (dpe_is_ring_tx(vap->uc_vap_id, netbuf, tx_ctl)) {
        /* csum上层填写在skb cb里, 后续流程根据该字段填写 */
        hmac_ether_set_data_type(tx_ctl, netbuf);
        /* 入队 */
        hmac_host_tx_data(vap->uc_vap_id, us_user_idx, netbuf);
        return;
    }
    /* Device Tx帧统一流转到ACPU进行封装处理,不走当前接口 */
    oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_xmit:: user id %d,  tx error path}", us_user_idx);
}
void dpe_wlan_netdev_xmit(oal_net_device_stru *net_device, oal_netbuf_stru *netbuf, uint32_t xmit_type)
{
    dpe_wlan_vap_stru *vap = dpe_netdev_get_vap(net_device);
    if (oal_unlikely(vap == NULL)) {
        oam_warning_log0(0, OAM_SF_DPA, "{dpe_wlan_netdev_xmit:: vap null}");
        dpe_netbuf_free(netbuf);
        return;
    }
    dpe_wifi_netbuf_in_inc(EN_XMIT_TPCIP);
    /* EHT HDR信息可直接访问 */
    /* payload read */
    dpe_wlan_xmit_hdr_info_move(netbuf);
    dpe_wlan_xmit(vap, netbuf, OAL_FALSE);
}
/*
 * 注册给Modem的回调：: 挂接到DPA modem转发表的发送源的入口函数, 注册给对应的ops
 */
void dpe_wlan_xmit_from_modem(oal_netbuf_stru *netbuf)
{
    oal_net_device_stru *net_device = NULL;

    if (netbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_xmit_from_modem:: netbuf null}");
        return;
    }

    net_device = oal_get_netif_comm_dev(oal_get_netbuf_ifindex(netbuf));
    if (net_device == NULL) {
        oam_warning_log1(0, OAM_SF_DPA, "{dpe_wlan_xmit_from_modem:: net_device %d null}",
            oal_get_netbuf_ifindex(netbuf));
        dpe_netbuf_free(netbuf);
        return;
    }

    dpe_wlan_netdev_xmit(net_device, netbuf, EN_XMIT_MODEM);
}
/*
 * 注册给DPA栈(网卡xmit)的回调：: 挂接到DPA TCP/IP协议栈的发送源的入口函数, 注册给对应的ops
 */
int32_t dpe_wlan_xmit_from_tcpip(oal_net_device_stru *net_device, oal_netbuf_stru *netbuf)
{
    if (netbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_xmit_from_tcpip:: netbuf null}");
        return 0;
    }
    if (net_device == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_xmit_from_tcpip:: net_device null}");
        dpe_netbuf_free(netbuf);
        return 0;
    }
    dpe_wlan_netdev_xmit(net_device, netbuf, EN_XMIT_TPCIP);
    return 0;
}

void dpe_wlan_xmit_from_acpu_ring_tx(oal_netbuf_head_stru *netbuf_list)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    oal_netbuf_stru *netbuf = oal_netbuf_peek(netbuf_list);
    dpe_wlan_tx_stat_stru *dpe_tx_stat = dpe_wlan_tx_stat_get();
    if (netbuf == NULL) {
        return;
    }

    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    oal_set_netbuf_next((oal_netbuf_tail(netbuf_list)), NULL);
    dpe_tx_stat->tx_gso_output_data++;
    /* ACPU来帧直接入队或转发 */
    if (dpe_is_ring_tx(mac_get_cb_tx_vap_index(tx_ctl), netbuf, tx_ctl)) {
        /* 入队 */
        hmac_host_tx_data(mac_get_cb_tx_vap_index(tx_ctl), mac_get_cb_tx_user_idx(tx_ctl), netbuf);
    } else {
        /* 已封装80211 HDR, FRW事件透传流转至DEVICE */
        /* 此处不存在非Ring帧 */
        oam_error_log3(0, OAM_SF_DPA, "{dpe_wlan_xmit_from_acpu:: vap id = %d user id %d, tid = %d}",
            mac_get_cb_tx_vap_index(tx_ctl), mac_get_cb_tx_user_idx(tx_ctl), mac_get_cb_wme_tid_type(tx_ctl));
    }
}

void dpe_wlan_xmit_cb_info_set(mac_tx_ctl_stru *tx_ctl, dpe_wlan_xmit_cb_info *cb_info)
{
    cb_info->user_info.vap_id = mac_get_cb_tx_vap_index(tx_ctl);
    cb_info->user_info.user_id = mac_get_cb_tx_user_idx(tx_ctl);
    cb_info->user_info.tid = mac_get_cb_wme_tid_type(tx_ctl);
}

void dpe_wlan_xmit_from_acpu_proc(oal_netbuf_head_stru *netbuf_list)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    oal_netbuf_stru *netbuf = NULL;
    oal_netbuf_stru *next_netbuf = NULL;
    dpe_wlan_vap_stru *dpe_vap = NULL;
    oal_netbuf_head_stru ring_list;
    dpe_wlan_xmit_cb_info cb_info = { 0 };
    dpe_wlan_xmit_cb_info ring_list_cb_info = { 0 };
    dpe_wlan_tx_stat_stru *dpe_tx_stat = dpe_wlan_tx_stat_get();

    oal_netbuf_list_head_init_nolock(&ring_list);
    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, netbuf_list) {
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);

        oal_netbuf_delete_nolock(netbuf, netbuf_list);
        /* 1.优先处理dpa转发帧，dpa 转发数据帧入接收队列重排序 */
        if (tx_ctl->st_expand_cb.is_dpa_transfer == OAL_TRUE) {
            dpe_tx_stat->tx_gso_output_dpa_trans++;
            dpe_wlan_xmit_from_wlan(netbuf);
            continue;
        }
        /* 2. 常发数据帧入常发缓存队列 */
        if (tx_ctl->st_expand_cb.is_altx_frame == OAL_TRUE) {
            dpe_always_tx_netbuf_enqueue(tx_ctl->hal_device_id, netbuf);
            continue;
        }
        if (mac_get_cb_frame_subtype(tx_ctl) <= MAC_DATA_ARP_REQ) {
            oam_warning_log3(0, OAM_SF_DPA, "{dpe_tx_vip_info:: vap %d user %d datatype=%d}",
                mac_get_cb_tx_vap_index(tx_ctl), mac_get_cb_tx_user_idx(tx_ctl), mac_get_cb_frame_subtype(tx_ctl));
        }
        /* 3. device tx数据帧转HCC下发DMAC */
        if (tx_ctl->st_expand_cb.is_device_tx == OAL_TRUE) {
            dpe_tx_stat->tx_gso_output_devtx++;
            dpe_vap = dpe_wlan_vap_get(mac_get_cb_tx_vap_index(tx_ctl));
            if (dpe_vap == NULL) {
                dpe_netbuf_free(netbuf);
                continue;
            }
            dpe_wlan_stat_all_tx_netbuf(tx_ctl, netbuf); /* device tx数据统计 */
            dpe_device_ring_tx_send_netbuf(dpe_vap, netbuf);
            continue;
        }
        /* 1.先获取首帧的信息 */
        if (oal_netbuf_list_empty(&ring_list)) {
            oal_netbuf_addlist_tail_nolock(&ring_list, netbuf);
            dpe_wlan_xmit_cb_info_set(tx_ctl, &ring_list_cb_info);
            continue;
        }
        dpe_wlan_xmit_cb_info_set(tx_ctl, &cb_info);
        /* 2.同一user/tid帧入队 */
        if (cb_info.word != ring_list_cb_info.word) {
            /* 3.user/tid等信息不一致，攒的包直接入tid缓存队列 */
            dpe_wlan_xmit_from_acpu_ring_tx(&ring_list);
            /* 4.入完缓存队列，初始化重新开始攒包 */
            ring_list_cb_info.word = cb_info.word;
            oal_netbuf_list_head_init_nolock(&ring_list);
        }
        oal_netbuf_addlist_tail_nolock(&ring_list, netbuf);
    }
    /* 5.netbuf list取空，ring list还有包，剩余包入tid缓存队列 */
    if (!oal_netbuf_list_empty(&ring_list)) {
        dpe_wlan_xmit_from_acpu_ring_tx(&ring_list);
    }
}

void dpe_wlan_xmit_list_from_acpu(struct sms_tx_bd_desc *gso_desc, uint32_t cnt)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    oal_netbuf_stru *netbuf = NULL;
    oal_netbuf_head_stru netbuf_list;
    uint8_t idx;

    if (oal_unlikely(gso_desc == NULL || cnt == 0)) {
        return;
    }
    oal_netbuf_list_head_init_nolock(&netbuf_list);
    for (idx = 0; idx < cnt; idx++) {
        netbuf = oal_netbuf_build(gso_desc[idx].dra_addr, gso_desc[idx].len);
        if (oal_unlikely(netbuf == NULL)) {
            continue;
        }
        dpe_wifi_netbuf_in_inc(EN_XMIT_GSO);
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        memcpy_s(tx_ctl, sizeof(mac_tx_ctl_stru), gso_desc[idx].cb, sizeof(mac_tx_ctl_stru));

        hal_host_tx_netbuf_init_msdu_dscr(netbuf, OAL_FALSE);
        dpe_tx_msdu_info_clear_check(netbuf);
        oal_netbuf_addlist_tail_nolock(&netbuf_list, netbuf);
    }
    dpe_wlan_xmit_from_acpu_proc(&netbuf_list);
}

/* 注册给GSO的回调：处理所有来源于ACPU的数据帧, 包含ACPU协议栈、DPA协议栈/Modem的Ring Tx数据; 非Ring tx数据透传至WCPU */
void dpe_wlan_xmit_from_acpu(struct sms_tx_bd_desc *gso_desc)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    oal_netbuf_stru *netbuf = NULL;
    oal_netbuf_head_stru netbuf_list;

    if (oal_unlikely(gso_desc == NULL)) {
        return;
    }

    netbuf = oal_netbuf_build(gso_desc->dra_addr, gso_desc->len);
    if (oal_unlikely(netbuf == NULL)) {
        bsp_dra_free(gso_desc->dra_addr);
        return;
    }
    dpe_wifi_netbuf_in_inc(EN_XMIT_GSO);
    oal_netbuf_list_head_init_nolock(&netbuf_list);

    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    memcpy_s(tx_ctl, sizeof(mac_tx_ctl_stru), gso_desc->cb, sizeof(mac_tx_ctl_stru));

    hal_host_tx_netbuf_init_msdu_dscr(netbuf, OAL_FALSE);
    dpe_tx_msdu_info_clear_check(netbuf);
    oal_netbuf_addlist_tail_nolock(&netbuf_list, netbuf);
    dpe_wlan_xmit_from_acpu_proc(&netbuf_list);
}

/* 注册给HMAC事件的回调：处理所有来源于DPE的数据帧, 转发ACPU再流转DPA转收的帧，处理802.11/fragment特性 */
uint32_t dpe_wlan_xmit_from_wlan(oal_netbuf_stru *netbuf)
{
    dpe_wlan_vap_stru *vap = NULL;
    dpe_wlan_user_stru *user = NULL;
    mac_rx_ctl_stru *rx_ctl = NULL;
    mac_ether_header_stru *eth_hdr = NULL;
    oal_netbuf_head_stru rpt_list;
    hmac_host_rx_context_stru rx_context = { 0 };

    if (oal_unlikely(netbuf == NULL)) {
        return OAL_SUCC;
    }
    rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    rx_ctl->bit_transfer_from_dpa = 0;
    rx_ctl->bit_transfer_from_task = 0;
    /* 当前接口只有802.3帧, 拷贝ACPU保存的DA，接收流程误解析EHT/IP/TCP头信息 */
    eth_hdr = (mac_ether_header_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf);
    memcpy_s(eth_hdr->auc_ether_dhost, ETHER_ADDR_LEN, rx_ctl->auc_ether_dhost, ETHER_ADDR_LEN);

    /* RX CB在ACPU透传未改变 */
    vap = (dpe_wlan_vap_stru *)dpe_wlan_vap_get(mac_get_rx_cb_mac_vap_id(rx_ctl));
    user = (dpe_wlan_user_stru *)dpe_wlan_user_get(rx_ctl->bit_rx_user_id);
    if (vap == NULL || user == NULL) {
        oam_error_log2(0, OAM_SF_DPA, "{dpe_wlan_xmit_from_wlan::vap or user NULL, vap id %d, user id %d}",
            mac_get_rx_cb_mac_vap_id(rx_ctl), rx_ctl->bit_rx_user_id);
        dpe_netbuf_free(netbuf);
        return OAL_SUCC;
    }
    hmac_dev_build_rx_context(netbuf, &rx_context);

    oal_netbuf_list_head_init_nolock(&rpt_list);
    if (hmac_rx_proc_netbuf(&rx_context, &rpt_list) != OAL_SUCC) {
        dpe_netbuf_free(netbuf);
        return OAL_SUCC;
    }
    if (oal_netbuf_list_len(&rpt_list)) {
        hmac_rx_rpt_netbuf(&rpt_list);
    }
    return OAL_SUCC;
}
#endif
