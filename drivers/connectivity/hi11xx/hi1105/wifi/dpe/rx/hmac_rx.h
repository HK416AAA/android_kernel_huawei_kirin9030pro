/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : hmac_rx.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2024年12月13日
 */

#ifndef HMAC_RX_H
#define HMAC_RX_H

#include "mac_cb_rx.h"
#include "dpe_wlan_user.h"
#include "host_hal_device.h"
#include "dpe_sbuf.h"
#include "dpe_wlan_vap.h"
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_frw_if.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
#define HMAC_RX_DATA_ETHER_OFFSET_LENGTH 6      /* 代表发送lan的包，protocol type的以太头需要向前偏移6 */

#define RX_FILTER_USER_DATA_MAX_LEN 4
#define RX_FILTER_SOFT_USER_DATA_MAX_LEN 28

#define HMAC_RX_RPT_WAIT_LIST_MAX_NUM 10000

typedef enum {
    HMAC_RX_FRAME_CTRL_GOON,   /* 本数据帧需要继续处理 */
    HMAC_RX_FRAME_CTRL_DROP,   /* 本数据帧需要丢弃 */
    HMAC_RX_FRAME_CTRL_BUTT
} hmac_rx_frame_ctrl_enum;
/* 处理MPDU的MSDU的处理状态的结构体的定义 */
typedef struct {
    oal_netbuf_stru *pst_curr_netbuf;     /* 当前处理的netbuf指针 */
    uint8_t *puc_curr_netbuf_data;      /* 当前处理的netbuf的data指针 */
    uint16_t us_submsdu_offset;         /* 当前处理的submsdu的偏移量,   */
    uint8_t uc_msdu_nums_in_netbuf;     /* 当前netbuf包含的总的msdu数目 */
    uint8_t uc_procd_msdu_in_netbuf;    /* 当前netbuf中已处理的msdu数目 */
    uint8_t uc_netbuf_nums_in_mpdu;     /* 当前MPDU的中的总的netbuf的数目 */
    uint8_t uc_procd_netbuf_nums;       /* 当前MPDU中已处理的netbuf的数目 */
    uint8_t uc_procd_msdu_nums_in_mpdu; /* 当前MPDU中已处理的MSDU数目 */

    uint8_t uc_flag;
} dmac_msdu_proc_state_stru;

/* HMAC模块接收流程处理MSDU状态 */
typedef enum {
    MAC_PROC_ERROR = 0,
    MAC_PROC_LAST_MSDU,
    MAC_PROC_MORE_MSDU,
    MAC_PROC_LAST_MSDU_ODD,

    MAC_PROC_BUTT
} mac_msdu_proc_status_enum;
typedef uint8_t mac_msdu_proc_status_enum_uint8;

/* 每一个MSDU包含的内容的结构体的定义 */
typedef struct {
    uint8_t auc_sa[WLAN_MAC_ADDR_LEN]; /* MSDU发送的源地址 */
    uint8_t auc_da[WLAN_MAC_ADDR_LEN]; /* MSDU接收的目的地址 */
    uint8_t auc_ta[WLAN_MAC_ADDR_LEN]; /* MSDU接收的发送地址 */
    uint8_t uc_priority;
    uint8_t auc_resv[1];

    oal_netbuf_stru *pst_netbuf; /* MSDU对应的netbuf指针(可以使clone的netbuf) */
} dmac_msdu_stru;

typedef struct {
    hal_host_device_stru *hal_dev;
    dpe_wlan_vap_stru *dpe_vap;
    dpe_wlan_user_stru* dpe_user;
    oal_netbuf_stru *netbuf;
    mac_rx_ctl_stru *cb;
} hmac_host_rx_context_stru;

static inline oal_bool_enum_uint8 mac_tid_is_valid(uint8_t tid)
{
    return (oal_bool_enum_uint8)(((uint16_t)(tid)) < WLAN_TID_MAX_NUM);
}
void dpe_hmac_user_clear_ptk_rx_pn(uint16_t user_idx);
void dpe_hmac_user_clear_gtk_rx_pn(uint16_t user_idx);
uint32_t hmac_rx_netbuf_list_free(oal_netbuf_stru *netbuf);
void hmac_rx_free_netbuf(oal_netbuf_stru *netbuf, uint16_t nums);
void hmac_rx_free_netbuf_list(oal_netbuf_head_stru *netbuf_hdr, uint16_t num_buf);
void hmac_rx_route_print(hal_host_device_stru *hal_device, uint8_t step, mac_rx_ctl_stru *mac_rx_ctl);
void hmac_rx_mpdu_to_netbuf_list(oal_netbuf_head_stru *netbuf_head, oal_netbuf_stru *netbuf_mpdu);
void hmac_rx_rpt_netbuf(oal_netbuf_head_stru *list);
void hmac_host_rx_static_proc(hmac_host_rx_context_stru *rx_context);
uint32_t hmac_rx_proc_feature(hmac_host_rx_context_stru *rx_context, oal_netbuf_head_stru *rpt_list);
#ifdef _PRE_WLAN_DFT_DUMP_FRAME
void hmac_rx_netbuf_force_ota_report(oal_netbuf_stru *netbuf);
#endif
uint32_t hmac_rx_proc_80211_to_eth(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctrl, uint8_t uc_vap_id);
void hmac_rx_data_ap_proc(dpe_wlan_vap_stru *dpe_vap, oal_netbuf_head_stru *p_netbuf_head);
void hmac_parse_packet(uint8_t vap_idx, oal_netbuf_stru *netbuf_eth);
void hmac_rx_process_data_ap_tcp_ack_opt(uint8_t vap_idx, oal_netbuf_head_stru *netbuf_header);
void hmac_rx_lan_frame(oal_netbuf_head_stru *netbuf_header);
void hmac_rx_skb_netif_rpt(uint8_t vap_id, oal_netbuf_head_stru *netbuf_list);
uint32_t hmac_rx_frame_80211_to_eth(oal_netbuf_stru *netbuf, const unsigned char *puc_da, const unsigned char *puc_sa);
uint32_t hmac_rx_transmit_to_wlan(frw_event_hdr_stru *event_hdr, oal_netbuf_head_stru *netbuf_head);
void hmac_rx_ap_mcast_data_proc(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl, oal_netbuf_head_stru *w2w_list);
void hmac_rx_vip_info_proc(uint8_t vap_id, uint8_t data_type, uint8_t cipher_type, oal_netbuf_stru *netbuf);
void hmac_rx_vip_info_proc_rx_ctl_print(uint8_t vap_idx, mac_rx_ctl_stru *rx_ctrl, mac_ether_header_stru *ether_hdr);
uint32_t dpe_wlan_xmit_from_wlan(oal_netbuf_stru *netbuf);
void hmac_rx_wlan_to_wlan_proc(dpe_wlan_vap_stru *dpe_vap, oal_netbuf_head_stru *pw2w_netbuf_hdr);
void hmac_rx_ap_w2w_proc(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *release_list, oal_netbuf_head_stru *w2w_list);
uint32_t hmac_11i_ether_type_filter(uint8_t port_valid, uint16_t us_ether_type);
uint8_t hmac_rx_da_is_in_same_bss(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl, uint8_t vap_idx);
uint32_t hmac_rx_proc_netbuf(hmac_host_rx_context_stru *rx_context, oal_netbuf_head_stru *rpt_list);
void hmac_dev_build_rx_context(oal_netbuf_stru *netbuf, hmac_host_rx_context_stru *rx_context);
void hmac_rx_enqueue_list(oal_netbuf_head_stru *list, uint8_t is_same_vap);
uint32_t hmac_rx_netbuf_join_to_list(oal_netbuf_stru *netbuf, oal_netbuf_head_stru *list);
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_wlan_to_filter(oal_net_device_stru *net_dev, uint8_t vap_id, oal_netbuf_head_stru *netbuf_list);
void dpe_wlan_rx_filter_user_data_set(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctrl);
void hmac_rx_mcast_frame(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl);
#endif
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif