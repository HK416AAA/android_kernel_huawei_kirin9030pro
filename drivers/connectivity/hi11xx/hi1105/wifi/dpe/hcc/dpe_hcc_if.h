/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_hcc_adapt.c 的头文件
 * 作    者 :
 * 创建日期 : 2012年9月18日
 */

#ifndef DPE_HCC_IF_H
#define DPE_HCC_IF_H

/* 1 其他头文件包含 */
#include "oam_ext_if.h"
#include "hmac_ext_if.h"
#include "oal_mem.h"
#include "frw_ext_if.h"
#include "frw_event_main.h"

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
/* WIFI驱动使用的CB接口 */
#define oal_netbuf_cb(netbuf)    ((uint8_t*)((dpe_frw_event_stru*)oal_sbuf_cb(netbuf))->skb_cb)
#define oal_netbuf_dpe_cb(netbuf)    (dpe_cb_stru*)((uint8_t*)((dpe_frw_event_stru*)oal_sbuf_cb(netbuf))->dpe_cb)
#endif

uint32_t frw_hcc_tx_event_to_netbuf(oal_netbuf_stru *netbuf);
uint32_t frw_hcc_rx_convert_to_event(oal_netbuf_stru *netbuf);
void dpe_hcc_adapt_init(void);
uint32_t frw_hcc_tx_netbuf(oal_netbuf_stru *netbuf);
/* 申明事件转发表注册的适配接口 -- 提供给dpe_frw_main.c引用 */
uint32_t dpe_frw_wlan_user_add(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_wlan_user_del(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_wlan_tid_ba_sync(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_event_config_syn(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_get_host_ring_state(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_set_tx_ring_device_base_addr(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_tx_mode_switch_process(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_event_syn_dpa(oal_netbuf_stru *netbuf);
uint32_t dpe_frw_event_config_dmac_d2h_syn(oal_netbuf_stru *netbuf);
#endif /* end of hmac_main */
