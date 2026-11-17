/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe netdev
 * 作    者 : xianglei
 * 创建日期 : 2025年3月26日
 */
#ifndef DPE_NETDEV_H
#define DPE_NETDEV_H

#include "oal_util.h"
#include "dpe_wlan_vap.h"
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "oal_net_wifi.h"
#include "dpe_netdev_sync.h"
#endif

#define DPE_SYNC_NET_PRIV_INFO_SIZE 64

enum dpe_netdev_sync_event {
    DPE_NETDEV_SYNC_ADD_NETDEV = 0,
    DPE_NETDEV_SYNC_DEL_NETDEV,
    DPE_NETDEV_SYNC_ADD_VAP,
    DPE_NETDEV_SYNC_DEL_VAP,
    DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV,
    DPE_NETDEV_SYNC_CHANGE_FLAGS,
    DPE_NETDEV_SYNC_BUTT,
};
// DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV事件的子类型
enum dpe_netdev_sync_vap_update_type {
    DPE_NETDEV_SYNC_VAP_UPDATE = 0,
    DPE_NETDEV_SYNC_UPDATE_MAC = 1, // 更新mac同步balong，dpa wifi回调中无需处理

    DPE_NETDEV_SYNC_UPDATE_BUTT,
};
typedef struct {
    uint8_t sync_event;
    uint8_t net_map_id;
    uint8_t vap_id;
    uint8_t update_type; // DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV事件的子类型，
    uint32_t net_dev_flags;
    char netdev_name[DPE_SYNC_NETDEV_NAME_LEN];
    uint8_t netdev_mac[OAL_MAC_ADDR_LEN]; // 更新网络设备mac addr
} sync_wlan_priv_info_stru;

typedef struct {
    oal_net_device_stru *dev;
    uint8_t vap_id;
    dpe_wlan_vap_stru *dpe_vap;
    char netdev_name[DPE_SYNC_NETDEV_NAME_LEN];
} dpe_wlan_net_map_stru;

dpe_wlan_net_map_stru *dpe_get_wlan_net_vap_map(void);

OAL_STATIC OAL_INLINE void dpe_wlan_del_vap_netdev_sync(dpe_wlan_vap_stru *dpe_vap, oal_net_device_stru *net_dev)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_del_vap_net_map_proc(dpe_vap->net_map_id);
#else
    dpe_vap->pst_net_device = net_dev;
#endif
}
OAL_STATIC OAL_INLINE void dpe_wlan_add_vap_net_init(dpe_wlan_vap_stru *dpe_vap, oal_net_device_stru *net_dev,
    mac_cfg_add_vap_extend_stru *extend_param)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_vap->net_map_id = dpe_add_vap_net_map_proc(dpe_vap, extend_param);
#else
    dpe_vap->pst_net_device = net_dev;
#endif
}

OAL_STATIC OAL_INLINE oal_net_device_stru *dpe_vap_get_net_device(uint8_t vap_id)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_wlan_net_map_stru *net_vap_map = dpe_get_wlan_net_vap_map();
    dpe_wlan_vap_stru *dpe_vap = (dpe_wlan_vap_stru *)dpe_wlan_vap_get(vap_id);
    if (net_vap_map == NULL || dpe_vap == NULL) {
        return NULL;
    }
    if (dpe_vap->net_map_id >= HAL_MAX_HW_VAP_NUM) {
        return NULL;
    }
    return net_vap_map[dpe_vap->net_map_id].dev;
#else
    return dpe_vap_get_host_net_device(vap_id);
#endif
}

OAL_STATIC OAL_INLINE void dpe_del_cfg_vap_netdev_proc(dpe_wlan_vap_stru *dpe_vap)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_del_vap_net_map_proc(dpe_vap->net_map_id);
#else
    dpe_vap->pst_net_device = NULL;
#endif
}
#endif