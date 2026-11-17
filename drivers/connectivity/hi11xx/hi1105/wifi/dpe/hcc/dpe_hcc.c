/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HMAC模块HCC层适配
 * 作    者 :
 * 创建日期 : 2014年10月8日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD

#include "dpe_hcc.h"
#include "dpe_frw_if.h"
#include "dpe_wlan_config.h"
#include "oal_hcc_host_if.h"
#include "frw_event_main.h"
#include "host_hal_device.h"
#include "host_hal_ext_if.h"
#include "securec.h"
#include "securectype.h"
#include "dpe_sbuf.h"
#include "mac_data.h"
#include "dpe_wlan_stat.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_HCC_C

OAL_STATIC uint8_t g_hcc_sched_stat[FRW_EVENT_TYPE_BUTT];
OAL_STATIC uint8_t g_hcc_flowctrl_stat[FRW_EVENT_TYPE_BUTT];

OAL_STATIC void dpe_tx_sched_info_init(void)
{
    memset_s(g_hcc_sched_stat, sizeof(g_hcc_sched_stat), DATA_LO_QUEUE, sizeof(g_hcc_sched_stat));

    /* set the event sched PRI */
    g_hcc_sched_stat[FRW_EVENT_TYPE_HIGH_PRIO] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_CRX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_DRX] = DATA_LO_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_CTX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_SDT_REG] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_CRX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_DRX] = DATA_LO_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_CTX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_TX_COMP] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_TBTT] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_TIMEOUT] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_DMAC_MISC] = DATA_HI_QUEUE;

    memset_s(g_hcc_flowctrl_stat, sizeof(g_hcc_flowctrl_stat),
             HCC_FC_NONE, sizeof(g_hcc_flowctrl_stat));
    /* 来自HOST的事件，如果从Kernel Net过来选择网络层流控+丢包的方式，如果是Wlan To Wlan 的方式，直接丢包! */
    g_hcc_flowctrl_stat[FRW_EVENT_TYPE_HOST_DRX] = HCC_FC_DROP | HCC_FC_NET;
}

OAL_STATIC void hcc_event_hdr_init(dpe_frw_event_stru *frw_event)
{
    struct frw_hcc_extend_hdr *frw_hdr = &frw_event->hcc_hdr.frw_hdr;
    frw_event_hdr_stru  *event_hdr = &frw_event->st_event_hdr;

    frw_hdr->en_nest_type       = event_hdr->en_type;
    frw_hdr->uc_nest_sub_type   = event_hdr->uc_sub_type;
    frw_hdr->chip_id            = 0;
    frw_hdr->device_id          = event_hdr->uc_device_id;
    frw_hdr->vap_id             = event_hdr->uc_vap_id;
}

/* WIFI DPE透传事件流转接口，DPA核原封不动的将skb在hcc master和slave之间传递, 不访问cb 19 + wifi hdr 36 */
uint32_t frw_hcc_tx_netbuf(oal_netbuf_stru *netbuf)
{
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru *)oal_sbuf_cb(netbuf);
    struct hcc_transfer_param param;
    uint32_t payload_len = oal_netbuf_len(netbuf);
    dpe_wlan_event_dispatch_stat_stru *event_trx_stat = dpe_wlan_event_trx_stat_get();

    /* ACPU/WCPU事件分流流转至HCC */
    if (frw_event->st_event_hdr.transfer_event_to == FRW_EVENT_TO_WCORE) {
        /* WCPU */
        event_trx_stat->dpe_master_hcc_tx_event_cnt++;
        dpe_wifi_netbuf_out_inc(EN_HCC_TX_WCPU, 1);
        hcc_hdr_param_init(&param, HCC_ACTION_TYPE_WIFI, 0,
            HCC_HDR_RESERVED_MAX_LEN - frw_event->st_event_hdr.hcc_extend,
            g_hcc_flowctrl_stat[frw_event->st_event_hdr.en_type], g_hcc_sched_stat[frw_event->st_event_hdr.en_type]);
        hcc_master_tx(netbuf, payload_len, &param);
    } else {
        /* ACPU */
        event_trx_stat->dpe_slave_hcc_tx_event_cnt++;
        dpe_wifi_netbuf_out_inc(EN_HCC_TX_ACPU, 1);
        hcc_hdr_param_init(&param, HCC_ACTION_TYPE_WIFI, 0,
            HCC_HDR_RESERVED_MAX_LEN - frw_event->st_event_hdr.hcc_extend,
            HCC_FC_NONE, DATA_HI_QUEUE);
        hcc_slave_tx(netbuf, payload_len, &param);
    }
    return OAL_SUCC;
}

/* DPE事件去往ACPU、WCPU统一接口，实现FRW与HCC之间的适配 */
uint32_t frw_hcc_tx_event_to_netbuf(oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *rx_ctl = (mac_rx_ctl_stru*)oal_netbuf_cb(netbuf);
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru *)oal_sbuf_cb(netbuf);

    /* hcc extend == 1, 代表64字节HCC HDR以hcc 5 + pad 1 + frw 3 + cb 19 + wifi hdr 36的格式传输 */
    if (frw_event->st_event_hdr.hcc_extend == 1) {
        /* 垮核传递时，需要将skb cb 48字节空间保存到hcc hdr核间通信传输 */
        memcpy_s(frw_event->hcc_hdr.wifi_cb, sizeof(mac_rx_ctl_stru), rx_ctl, sizeof(mac_rx_ctl_stru));
    }

    /* 初始化hcc frw 3区间 */
    hcc_event_hdr_init(frw_event);

    return frw_hcc_tx_netbuf(netbuf);
}

uint32_t frw_hcc_rx_convert_to_event(oal_netbuf_stru *netbuf)
{
    /* HCC接收到的skb, 平台已经将64字节hcc+frw+cb+80211 hdr放入sbuf->cb区域;
       通过dpe_frw_event_stru强转oal_netbuf_cb(sbuf)获取hcc hdr；
       通过oal_netbuf_data(sbuf)获取事件体或帧体(802.11或802.3格式, 802.11帧头与帧体连续)
    */
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(netbuf); /* 事件信息维护在sbuf->cb(128 bytes) */
    /* 核间通信的cb只有19字节 */
    mac_rx_ctl_stru *rx_ctl = (mac_rx_ctl_stru*)oal_netbuf_cb(netbuf);
    dpe_cb_stru *dpe_cb = oal_netbuf_dpe_cb(netbuf);
    mac_ieee80211_frame_stru *ieee80211_hdr = NULL;
    mac_ether_header_stru *eth_hdr = NULL;
    d2h_drx_data_info_stru *transfer_info = NULL;
    /* 核间通信cb放入host cb 48字节区间, 后续所有WIFI驱动都使用该处cb区间访问 */
    memcpy_s(rx_ctl, sizeof(mac_rx_ctl_stru), frw_event->hcc_hdr.wifi_cb, sizeof(mac_rx_ctl_stru));

    /* DPA device ring接收流程使用的字段, 保存到标准ETH头部中 */
    if ((frw_event->hcc_hdr.frw_hdr.en_nest_type == FRW_EVENT_TYPE_WLAN_DRX) &&
        (frw_event->hcc_hdr.frw_hdr.uc_nest_sub_type == DMAC_WLAN_DRX_EVENT_SUB_TYPE_WOW_RX_DATA)) {
        transfer_info = (d2h_drx_data_info_stru *)(frw_event->hcc_hdr.wifi_cb + 31); // cb起始往后偏移31
        if (rx_ctl->bit_frame_format == MAC_FRAME_TYPE_RTH || rx_ctl->bit_frame_format == MAC_FRAME_TYPE_8023) {
            eth_hdr = (mac_ether_header_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf);
            memcpy_s(eth_hdr->auc_ether_dhost, ETHER_ADDR_LEN, transfer_info->auc_ether_dhost, ETHER_ADDR_LEN);
        } else if (rx_ctl->bit_frame_format == MAC_FRAME_TYPE_80211) {
            ieee80211_hdr = (mac_ieee80211_frame_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf);
            ieee80211_hdr->bit_frag_num = transfer_info->bit_frag_num;
            ieee80211_hdr->st_frame_control.bit_more_frag = transfer_info->bit_more_frag;
        }
        /* EAPOL加密过滤用 */
        mac_rx_data_set_ether_type(dpe_get_rx_netbuf_hdr_addr(netbuf), oal_netbuf_len(netbuf),
            mac_get_rx_cb_mac_header_len(rx_ctl), rx_ctl->bit_frame_format, transfer_info->ether_type);
    }

    rx_ctl->bit_transfer_from_dpa = 0; // 清除该bit，防止随机值导致的流程异常
    rx_ctl->bit_transfer_from_task = 1; // hcc为task
    /* 统一标记为MAA内存 */
    dpe_cb->not_maa_sbuf = 0;
    return OAL_SUCC;
}

void dpe_hcc_adapt_init(void)
{
    /* ACPU下送HCC(SLAVE)接口注册 */
    acpu_rx_register_hcc_action();

    /* WCPU上送HCC(MASTER)接口注册 */
    wcpu_rx_register_hcc_action();
    dpe_tx_sched_info_init();
}

uint32_t dpe_frw_wlan_user_add(oal_netbuf_stru *netbuf)
{
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(netbuf);

    if (frw_event == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_wlan_user_add::get frw_event fail!}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_user_add((uint8_t *)oal_netbuf_data(netbuf), frw_event->st_event_hdr.uc_vap_id);
    return OAL_SUCC;
}

uint32_t dpe_frw_wlan_user_del(oal_netbuf_stru *netbuf)
{
    dpe_wlan_user_del((uint8_t *)oal_netbuf_data(netbuf));
    return OAL_SUCC;
}

uint32_t dpe_frw_wlan_tid_ba_sync(oal_netbuf_stru *netbuf)
{
    dpe_wlan_tid_ba_sync((uint8_t *)oal_netbuf_data(netbuf));
    return OAL_SUCC;
}

uint32_t dpe_frw_event_config_syn(oal_netbuf_stru *netbuf)
{
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(netbuf);
    dpe_config_event_type_stru event_type_info = { 0 };

    if (frw_event == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_event_config_syn::get frw_event fail!}");
        return OAL_FAIL;
    }
    event_type_info.event_type = FRW_EVENT_TYPE_HOST_CRX;
    event_type_info.event_subtype = HMAC_TO_DMAC_SYN_CFG;
    return dpe_event_config_syn((uint8_t *)oal_netbuf_data(netbuf), frw_event->st_event_hdr.uc_vap_id,
        &event_type_info);
}

uint32_t dpe_frw_event_syn_dpa(oal_netbuf_stru *netbuf)
{
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(netbuf);
    dpe_config_event_type_stru event_type_info = { 0 };

    if (frw_event == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_event_syn_dpa::get frw_event fail!}");
        return OAL_FAIL;
    }
    event_type_info.event_type = FRW_EVENT_TYPE_HOST_CRX;
    event_type_info.event_subtype = HMAC_SYN_DPA;
    return dpe_event_config_syn((uint8_t *)oal_netbuf_data(netbuf), frw_event->st_event_hdr.uc_vap_id,
        &event_type_info);
}

uint32_t dpe_frw_event_config_dmac_d2h_syn(oal_netbuf_stru *netbuf)
{
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(netbuf);
    dpe_config_event_type_stru event_type_info = { 0 };

    if (frw_event == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_event_syn_dpa::get frw_event fail!}");
        return OAL_FAIL;
    }
    event_type_info.event_type = FRW_EVENT_TYPE_HOST_SDT_REG;
    event_type_info.event_subtype = DMAC_TO_HMAC_SYN_CFG;
    return dpe_event_config_syn((uint8_t *)oal_netbuf_data(netbuf), frw_event->st_event_hdr.uc_vap_id,
        &event_type_info);
}

uint32_t dpe_frw_get_host_ring_state(oal_netbuf_stru *netbuf)
{
    return dpe_get_host_ring_state();
}

uint32_t dpe_frw_set_tx_ring_device_base_addr(oal_netbuf_stru *netbuf)
{
    return dpe_set_tx_ring_device_base_addr((uint8_t *)oal_netbuf_data(netbuf));
}

uint32_t dpe_frw_tx_mode_switch_process(oal_netbuf_stru *netbuf)
{
    return dpe_tx_mode_switch_process((uint8_t *)oal_netbuf_data(netbuf));
}

uint32_t dpe_frw_dbac_status_notify(oal_netbuf_stru *netbuf)
{
    dpe_frw_event_stru *frw_event = (dpe_frw_event_stru*)oal_sbuf_cb(netbuf);
    dmac_dbac_notify_to_hmac_stru *dbac_notify = (dmac_dbac_notify_to_hmac_stru *)oal_netbuf_data(netbuf);

    if (frw_event == NULL || dbac_notify == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_frw_dbac_status_notify::get frw_event or dbac_notify_param fail!}");
        return OAL_FAIL;
    }
    dpe_wlan_dbac_vap_set_rx_reorder_timeout(frw_event->st_event_hdr.uc_vap_id, dbac_notify->dbac_enabled);
    return OAL_SUCC;
}
#endif
