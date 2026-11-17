/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : Host发送完成模块
 */

#ifndef DPE_TX_DATA_H
#define DPE_TX_DATA_H

#include "dpe_wlan_user.h"
#include "dpe_wlan_vap.h"
#include "hmac_tid_sche.h"
#include "hd_trx_data.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

void dpe_trx_switch_sync(wlan_trx_switch_stru *trx_switch);
static inline uint8_t dpe_host_ring_tx_enabled(void)
{
    return g_dpe_trx_switch.host_ring_tx_switch;
}

static inline uint8_t dpe_device_ring_tx_enabled(void)
{
    return g_dpe_trx_switch.device_ring_tx_switch;
}

static inline uint8_t dpe_device_loop_sched_enabled(void)
{
    return g_dpe_trx_switch.device_loop_sched;
}

static inline uint8_t dpe_tx_ring_switch_enabled(void)
{
    return g_dpe_trx_switch.tx_ring_switch;
}
static inline uint8_t dpe_rx_ring_switch_enabled(void)
{
    return g_dpe_trx_switch.rx_switch;
}
static inline uint8_t dpe_tx_ring_soft_irq_sched_enabled(void)
{
    return g_dpe_trx_switch.soft_irq_sched;
}

static inline uint8_t dpe_host_update_wptr_enabled(void)
{
    return g_dpe_trx_switch.host_update_wptr;
}

static inline uint8_t dpe_tx_ring_switch_sync_mode(void)
{
    return g_dpe_trx_switch.ring_switch_independent;
}
static inline uint8_t dpe_is_support_dpe_offload(void)
{
    return g_dpe_trx_switch.is_support_dpe_offload;
}
static inline uint8_t dpe_is_support_80211_dmi_transfer(void)
{
    return g_dpe_trx_switch.is_support_80211_rx_filter;
}
static inline uint8_t dpe_is_support_device_tx_gso(void)
{
    return g_dpe_trx_switch.is_support_device_tx_gso;
}
static inline uint8_t dpe_is_support_rx_dma_async(void)
{
    return g_dpe_trx_switch.is_support_host_rx_dma_async;
}
static inline uint8_t dpe_is_support_tx_no_dma(void)
{
    return g_dpe_trx_switch.is_support_tx_no_dma;
}
static inline uint8_t dpe_is_support_dev_rx_no_dma(void)
{
    return g_dpe_trx_switch.is_support_dev_rx_no_dma;
}
static inline uint8_t dpe_is_support_tx_gso_list(void)
{
    return g_dpe_trx_switch.is_support_tx_gso_list;
}
static inline uint8_t dpe_is_support_rx_filter_list(void)
{
    return g_dpe_trx_switch.is_support_rx_filter_list;
}

static inline uint8_t dpe_is_tx_ring_set_single(void)
{
    return g_dpe_trx_switch.is_support_tx_ring_set_single;
}

static inline uint8_t dpe_is_support_rx_ring_read_single(void)
{
    return g_dpe_trx_switch.is_support_rx_ring_read_single;
}

static inline oal_bool_enum_uint8 dpe_ring_tx_enabled(void)
{
    return (dpe_host_ring_tx_enabled() || dpe_device_ring_tx_enabled()) ? OAL_TRUE : OAL_FALSE;
}

static inline oal_bool_enum_uint8 dpe_device_ring_tx_only(void)
{
    return (!dpe_host_ring_tx_enabled() && dpe_device_ring_tx_enabled()) ? OAL_TRUE : OAL_FALSE;
}

static inline void hmac_ring_tx_update_tid(mac_tx_ctl_stru *tx_ctl)
{
    if (mac_get_cb_wme_tid_type(tx_ctl) == WLAN_TIDNO_BCAST) {
        mac_get_cb_wme_tid_type(tx_ctl) = WLAN_TIDNO_VOICE;
        mac_get_cb_wme_ac_type(tx_ctl) = WLAN_WME_TID_TO_AC(WLAN_TIDNO_VOICE);
    }
}

typedef union {
    uint32_t word;
    struct {
        uint16_t user_id;
        uint8_t vap_id;
        uint8_t tid;
    } user_info;
} dpe_wlan_xmit_cb_info;

uint32_t hmac_host_tx_tid_enqueue(hmac_tid_info_stru *tid_info, oal_netbuf_stru *netbuf);
uint32_t hmac_host_ring_tx(dpe_wlan_vap_stru *dpe_vap, dpe_wlan_user_stru *dpe_user, oal_netbuf_stru *netbuf);
void hmac_host_ring_tx_resume(dpe_wlan_vap_stru *dpe_vap, dpe_wlan_user_stru *dpe_user, hmac_tid_info_stru *tid_info);
uint32_t hmac_host_tx_data(uint8_t vap_idx, uint16_t user_idx, oal_netbuf_stru *netbuf);
uint16_t dpe_tx_get_user_id(dpe_wlan_vap_stru *dpe_vap, mac_ether_header_stru *ether_hdr);
void hmac_tx_cb_field_init(mac_tx_ctl_stru *tx_ctl, uint8_t uc_vap_id, uint8_t en_vap_mode,
    uint16_t user_idx, mac_ether_header_stru *ether_hdr);
oal_bool_enum_uint8 dpe_is_ring_tx(uint8_t vapid, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl);
void hmac_mcast_ampdu_netbuf_process(dpe_wlan_vap_stru *mac_vap, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl,
    mac_ether_header_stru *eth_hdr, oal_bool_enum_uint8 *multicast_need_host_tx);
void hmac_ether_set_data_type(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf);
void hmac_free_netbuf_list(oal_netbuf_stru *netbuf);
void hmac_cb_size_protect(void);

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t dpe_device_ring_tx_send_netbuf(dpe_wlan_vap_stru *dpe_vap, oal_netbuf_stru *netbuf);
void dpe_wlan_xmit(dpe_wlan_vap_stru *vap, oal_netbuf_stru *netbuf, uint8_t is_rx_w2w);
#endif
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
