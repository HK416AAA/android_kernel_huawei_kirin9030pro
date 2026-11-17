
/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : net
 * 作    者 : xianglei
 * 创建日期 : 2025年3月26日
 */
#ifndef DPE_NETDEV_SYNC_H
#define DPE_NETDEV_SYNC_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD

#include "oal_ext_if.h"
#include "oam_ext_if.h"
#include "wlan_spec_host.h"
#include "dpe_wlan_vap.h"

void dpe_del_vap_net_map_proc(uint8_t net_map_id);
uint8_t dpe_add_vap_net_map_proc(dpe_wlan_vap_stru *dpe_vap, mac_cfg_add_vap_extend_stru *extend_param);
void dpe_wlan_net_dev_init(void);
int32_t dpe_wlan_xmit_from_tcpip(oal_net_device_stru *net_device, oal_netbuf_stru *netbuf);
dpe_wlan_vap_stru *dpe_netdev_get_vap(oal_net_device_stru *netdev);
uint32_t dpe_wlan_add_link_net_init(dpe_wlan_vap_stru *dpe_vap, uint8_t ml_vap_idx);
uint32_t dpe_wlan_change_netdev_vap_relation(dpe_wlan_vap_stru *cur_dpe_vap, dpe_wlan_vap_stru *next_dpe_vap);
void dpe_wifi_clear_wlan_res(void);
uint8_t dpe_net_map_find_same_vap_by_vapid(uint8_t vap_id);
#endif
#endif