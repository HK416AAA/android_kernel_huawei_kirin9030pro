/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : net
 * 作    者 : xianglei
 * 创建日期 : 2025年3月26日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_netdev_sync.h"
#include "dpe_netdev.h"
#include "dpe_wlan_vap.h"
#include "bsp_sms.h"
#include "dpe_wlan_resource.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_NETDEV_SYNC_C

dpe_wlan_net_map_stru g_wlan_net_vap_map[HAL_MAX_HW_VAP_NUM] = { 0 };
OAL_PL1_DATA uint32_t g_oal_dpe_netdev_res_bitmap = 0;

dpe_wlan_net_map_stru *dpe_get_wlan_net_vap_map(void)
{
    return g_wlan_net_vap_map;
}

OAL_STATIC void dpe_wlan_net_map_debug(void)
{
    uint8_t map_id;
    dpe_wlan_net_map_stru *net_vap_map = dpe_get_wlan_net_vap_map();

    for (map_id = 0; map_id < HAL_MAX_HW_VAP_NUM; map_id++) {
        oam_warning_log4(0, OAM_SF_DPA,
            "{dpe_wlan_net_map_debug:map_id[%d], vap_id[%d], dpe_vap is null[%d], netdev is NULL[%d]}",
            map_id, net_vap_map[map_id].vap_id, (net_vap_map[map_id].dpe_vap == NULL),
            (net_vap_map[map_id].dev == NULL));
    }
}

/* 查找netdev-vap映射表中的vap对应行index */
uint8_t dpe_net_map_find_same_vap_by_vapid(uint8_t vap_id)
{
    uint8_t id = 0;
    for (; id < HAL_MAX_HW_VAP_NUM; id++) {
        if (g_wlan_net_vap_map[id].vap_id == vap_id && g_wlan_net_vap_map[id].dev != NULL) {
            return id;
        }
    }
    return id;
}

/* 查找netdev-vap映射表中的netdev name对应行index */
oal_net_device_stru *dpe_net_map_find_same_vap_by_name(char *name)
{
    uint8_t id = 0;
    for (; id < HAL_MAX_HW_VAP_NUM; id++) {
        if ((strlen(g_wlan_net_vap_map[id].netdev_name) == strlen(name)) &&
            (strncmp(g_wlan_net_vap_map[id].netdev_name, name, strlen(name)) == 0)) {
            if (g_wlan_net_vap_map[id].dev == NULL) {
                oam_error_log2(0, OAM_SF_DPA,
                    "{dpe_net_map_find_same_vap_by_name:map[%d] dev is NULL, name_len[%d]!}",
                    id, strlen(name));
            }
            return g_wlan_net_vap_map[id].dev;
        }
    }
    return NULL;
}

/* 功能描述: link net_dev去初始化 */
void dpe_wlan_net_link_dev_deinit(uint8_t vap_id, uint8_t net_map_id, oal_net_device_stru *netdev)
{
    /* link vap没有实际网卡, 需在del vap的同时清空全部数据 */
    sync_wlan_priv_info_stru *priv_info = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(netdev);
    if (priv_info == NULL) {
        return;
    }
    /* 非link netdev不处理 */
    if ((g_wlan_net_vap_map[priv_info->net_map_id].vap_id == vap_id) ||
        (g_wlan_net_vap_map[priv_info->net_map_id].dpe_vap == NULL)) { /* 已被释放的ml_netdev */
        return;
    }
    /* 释放link管理信息 */
    g_oal_dpe_netdev_res_bitmap &= ~(BIT(net_map_id));
    memset_s(&g_wlan_net_vap_map[net_map_id], sizeof(dpe_wlan_net_map_stru), 0, sizeof(dpe_wlan_net_map_stru));
    oam_warning_log2(0, OAM_SF_DPA, "dpe_wlan_net_link_dev_deinit:vap_id[%d] map_id[%d] deinit!", net_map_id, vap_id);
}

void dpe_del_vap_net_map_proc(uint8_t net_map_id)
{
    uint8_t vap_id;
    oal_net_device_stru *netdev = NULL;
    if (net_map_id >= HAL_MAX_HW_VAP_NUM) {
        return;
    }
    oam_warning_log2(0, OAM_SF_DPA, "dpe_del_vap_net_map_proc:del netdev[%d] vap_id[%d]",
        net_map_id, g_wlan_net_vap_map[net_map_id].vap_id);
    vap_id = g_wlan_net_vap_map[net_map_id].vap_id;
    netdev = g_wlan_net_vap_map[net_map_id].dev;
    g_wlan_net_vap_map[net_map_id].vap_id = HAL_MAX_HW_VAP_NUM;
    g_wlan_net_vap_map[net_map_id].dpe_vap = NULL;
    if (netdev == NULL) {
        return;
    }
    /* link没有实际网卡, 需在del vap的同时清空全部link vap管理信息; 其他则在netdev去初始化时才清理 */
    dpe_wlan_net_link_dev_deinit(vap_id, net_map_id, netdev);
}

uint8_t dpe_add_vap_net_map_proc(dpe_wlan_vap_stru *dpe_vap, mac_cfg_add_vap_extend_stru *extend_param)
{
    uint8_t net_map_id;
    sync_wlan_priv_info_stru *priv_info = NULL;
    oal_net_device_stru *netdev = dpe_net_map_find_same_vap_by_name(extend_param->netdev_name);
    if (netdev == NULL) {
        oam_warning_log1(0, OAM_SF_DPA, "{dpe_add_vap_net_map_proc:find netdev fail, vap[%d]!}", dpe_vap->uc_vap_id);
        dpe_wlan_net_map_debug();
        return HAL_MAX_HW_VAP_NUM;
    }
    priv_info = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(netdev);
    if (priv_info == NULL) {
        oam_error_log1(0, OAM_SF_DPA,
            "{dpe_add_vap_net_map_proc::find priv_info fail, vap_id[%d]!}", dpe_vap->uc_vap_id);
        dpe_wlan_net_map_debug();
        return HAL_MAX_HW_VAP_NUM;
    }
    net_map_id = priv_info->net_map_id;
    if (net_map_id >= HAL_MAX_HW_VAP_NUM) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_add_vap_net_map_proc::find netdev fail!}");
        dpe_wlan_net_map_debug();
        return net_map_id;
    }
    g_wlan_net_vap_map[net_map_id].dpe_vap = dpe_vap;
    g_wlan_net_vap_map[net_map_id].vap_id = dpe_vap->uc_vap_id;
    oam_warning_log2(0, OAM_SF_DPA, "dpe_add_vap_net_map_proc:net_map_id[%d], vap[%d]", net_map_id, dpe_vap->uc_vap_id);
    return net_map_id;
}

dpe_wlan_vap_stru *dpe_netdev_get_vap(oal_net_device_stru *netdev)
{
    sync_wlan_priv_info_stru *priv_info = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(netdev);
    if (priv_info == NULL) {
        return NULL;
    }
    if (g_wlan_net_vap_map[priv_info->net_map_id].dpe_vap == NULL) {
        oam_error_log4(0, OAM_SF_DPA, "dpe_netdev_get_vap:netdev[%d] vap null, priv vap_id[%d], name_len[%d/%d]",
            priv_info->net_map_id, priv_info->vap_id,
            strlen(priv_info->netdev_name), strlen(oal_get_netdev_ifname(netdev)));
    }

    return g_wlan_net_vap_map[priv_info->net_map_id].dpe_vap;
}

OAL_STATIC void dpe_wlan_net_dev_update_event_proc(sync_wlan_priv_info_stru *priv_info,
    sync_wlan_priv_info_stru *own_priv_info, oal_net_device_stru *dev)
{
    unsigned int net_map_id = own_priv_info->net_map_id;
    switch (priv_info->update_type) {
        case DPE_NETDEV_SYNC_VAP_UPDATE:
            g_wlan_net_vap_map[net_map_id].vap_id = own_priv_info->vap_id; /* vap id从hmac传的priv中取 */
            g_wlan_net_vap_map[net_map_id].dpe_vap = dpe_wlan_vap_get(own_priv_info->vap_id);
            break;
        case DPE_NETDEV_SYNC_UPDATE_MAC:
            oal_set_netdev_hwaddr(dev, priv_info->netdev_mac);
            break;
        default :
            oam_warning_log1(0, OAM_SF_DPA, "{dpe_wlan_net_dev_update_event_proc:update_event[%d] invalid}",
                priv_info->update_type);
            break;
    }
}

void dpe_wlan_net_dev_update_priv_cb(oal_net_device_stru *dev, char net_priv[DPE_SYNC_NET_PRIV_INFO_SIZE])
{
    sync_wlan_priv_info_stru *priv_info = (sync_wlan_priv_info_stru *)net_priv;
    sync_wlan_priv_info_stru *own_priv_info = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(dev);
    unsigned int net_map_id;

    if (net_priv == NULL || own_priv_info == NULL) {
        return;
    }
    net_map_id = own_priv_info->net_map_id;
    if (net_map_id >= HAL_MAX_HW_VAP_NUM) {
        return;
    }

    if (priv_info->sync_event == DPE_NETDEV_SYNC_ADD_VAP) {
        g_wlan_net_vap_map[net_map_id].vap_id = priv_info->vap_id;
    } else if (priv_info->sync_event == DPE_NETDEV_SYNC_CHANGE_FLAGS) {
        oal_set_netdev_flags(g_wlan_net_vap_map[net_map_id].dev, priv_info->net_dev_flags);
    } else if (priv_info->sync_event == DPE_NETDEV_SYNC_DEL_VAP) {
        dpe_del_vap_net_map_proc(priv_info->net_map_id);
    } else if (priv_info->sync_event == DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV) {
        dpe_wlan_net_dev_update_event_proc(priv_info, own_priv_info, dev);
    }
    oam_warning_log3(0, OAM_SF_DPA, "{dpe_wlan_net_dev_update_priv_cb:map_id[%d], sync_event[%d], update_type[%d]}",
        net_map_id, priv_info->sync_event, priv_info->update_type);
}
#define ARPHRD_IEEE80211 801
void wlan_dev_init(oal_net_device_stru *dev, void *para)
{
    struct nic_sync_netdev_para *dev_para;
    uint16_t type = ARPHRD_IEEE80211;
    uint64_t features = SPL_NETIF_F_HW_CSUM;
    uint8_t hwaddr_len = SPL_HWADDR_LEN;

    if (para == NULL || dev == NULL) {
        return;
    }

    dev_para = (struct nic_sync_netdev_para *)para;

    oal_set_netdev_type(dev, type);
    oal_set_netdev_features(dev, features);
    oal_set_netdev_tx_handler(dev, dpe_wlan_xmit_from_tcpip);
    oal_set_netdev_hwaddr(dev, dev_para->mac.addr);
    oal_set_netdev_hwaddr_len(dev, hwaddr_len);
}

uint8_t dpe_alloc_net_dev_map_id(void)
{
    uint8_t map_id = oal_bit_find_first_zero_four_byte(g_oal_dpe_netdev_res_bitmap);
    if (map_id >= HAL_MAX_HW_VAP_NUM) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_alloc_net_dev_map_id::err id[%d]", map_id);
        return map_id;
    }

    g_oal_dpe_netdev_res_bitmap |= BIT(map_id);
    return map_id;
}

/* 配置vap 网卡初始化 */
void dpe_wlan_cfg_vap_net_dev_map(uint8_t net_map_id)
{
    uint8_t cfg_vap_id = 0;
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(cfg_vap_id);
    if (dpe_vap == NULL) {
        return;
    }

    if (strncmp("Hisilicon0", oal_get_netdev_ifname(g_wlan_net_vap_map[net_map_id].dev), strlen("Hisilicon0")) != 0) {
        return;
    }

    g_wlan_net_vap_map[net_map_id].vap_id = cfg_vap_id;
    g_wlan_net_vap_map[net_map_id].dpe_vap = dpe_vap;
    dpe_vap->net_map_id = net_map_id;
}

oal_net_device_stru *dpe_wlan_net_dev_init_add_cb(struct nic_sync_netdev_para *para, char net_priv[64])
{
    sync_wlan_priv_info_stru *priv_info = (sync_wlan_priv_info_stru *)net_priv;
    sync_wlan_priv_info_stru *dev_priv = NULL;
    unsigned int net_map_id;

    net_map_id = dpe_alloc_net_dev_map_id();
    if (unlikely(net_map_id >= HAL_MAX_HW_VAP_NUM)) {
        return NULL;
    }

    priv_info->net_map_id = net_map_id;
    g_wlan_net_vap_map[net_map_id].dev = create_dev(para->name, NULL, wlan_dev_init,
        DPE_SYNC_NET_PRIV_INFO_SIZE, para);
    if (g_wlan_net_vap_map[net_map_id].dev == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_net_dev_init_add_cb:map_id[%d] create dev fail!}", net_map_id);
        return NULL;
    }
    if ((strlen(priv_info->netdev_name) != strlen(para->name)) ||
        (strncmp(para->name, priv_info->netdev_name, strlen(para->name)) != 0)) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_net_dev_init_add_cb:not same netdev!}");
    }
    memcpy_s(g_wlan_net_vap_map[net_map_id].netdev_name, sizeof(g_wlan_net_vap_map[net_map_id].netdev_name),
        priv_info->netdev_name, sizeof(priv_info->netdev_name));
    dev_priv = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(g_wlan_net_vap_map[net_map_id].dev);
    if (dev_priv == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{oal_comm_dev_priv returns NULL}");
        return NULL;
    }
    memcpy_s(dev_priv, sizeof(sync_wlan_priv_info_stru),
        priv_info, sizeof(sync_wlan_priv_info_stru));
    dpe_wlan_cfg_vap_net_dev_map(net_map_id);
    oam_warning_log2(0, OAM_SF_DPA, "dpe:add netdev[%d], 0~4:wlan0,p2p0,wlan1,chba0,nan0, name_len[%d]",
        net_map_id, strlen(g_wlan_net_vap_map[net_map_id].netdev_name));
    return g_wlan_net_vap_map[net_map_id].dev;
}

void dpe_wlan_net_dev_del_cb(oal_net_device_stru* dev)
{
    sync_wlan_priv_info_stru *priv_info = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(dev);
    if (priv_info == NULL) {
        return;
    }
    uint8_t net_map_id = priv_info->net_map_id;
    g_oal_dpe_netdev_res_bitmap &= ~(BIT(net_map_id));
    memset_s(&g_wlan_net_vap_map[net_map_id], sizeof(dpe_wlan_net_map_stru), 0, sizeof(dpe_wlan_net_map_stru));
    oam_warning_log1(0, OAM_SF_DPA, "{dpe_wlan_net_dev_del_cb:map_id[%d]}", net_map_id);
    if (unlikely(oal_get_netdev_ifname(dev) == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "{oal_get_netdev_ifname returns NULL}");
        return;
    }
    delete_dev(oal_get_netdev_ifname(dev));
}

void dpe_wlan_net_dev_init(void)
{
    struct nic_sync_cb cb;
    int ret;

    memset_s(g_wlan_net_vap_map, sizeof(dpe_wlan_net_map_stru) * HAL_MAX_HW_VAP_NUM, 0,
        sizeof(dpe_wlan_net_map_stru) * HAL_MAX_HW_VAP_NUM);

    cb.nic_sync_add_cb = dpe_wlan_net_dev_init_add_cb;
    cb.nic_sync_del_cb = dpe_wlan_net_dev_del_cb;
    cb.nic_sync_update_net_priv_cb = dpe_wlan_net_dev_update_priv_cb;

    ret = bsp_sms_nic_sync_register_cb(DPA_SMS_NIC_WLAN, &cb);
    if (ret) {
        oam_error_log1(0, OAM_SF_DPA, "wlan bsp_nic_sync_register_cb fail %d", ret);
    }
}

/* 功能描述: link vap/net管理结构体初始化 */
uint32_t dpe_wlan_add_link_net_init(dpe_wlan_vap_stru *dpe_vap, uint8_t ml_vap_idx)
{
    uint8_t link_net_map_id;
    uint8_t ml_net_map_id;
    if (ml_vap_idx >= WLAN_VAP_MAX_NUM_LIMIT) {
        oam_error_log1(dpe_vap->uc_vap_id, OAM_SF_DPA, "{dpe_wlan_add_link_net_init:invalid ml_vap[%d]}", ml_vap_idx);
        return OAL_ERR_CODE_CONFIG_EXCEED_SPEC;
    }
    ml_net_map_id = dpe_net_map_find_same_vap_by_vapid(ml_vap_idx);
    if (ml_net_map_id >= HAL_MAX_HW_VAP_NUM) {
        oam_error_log0(dpe_vap->uc_vap_id, OAM_SF_DPA, "{dpe_wlan_add_link_net_init:find to find ml_netdev!}");
        return OAL_ERR_CODE_CONFIG_EXCEED_SPEC;
    }

    /* 为link vap申请一份新资源 */
    link_net_map_id = dpe_alloc_net_dev_map_id();
    if (link_net_map_id >= HAL_MAX_HW_VAP_NUM) {
        oam_error_log0(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_wlan_add_link_net_init:fail to get map_id");
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }
    g_wlan_net_vap_map[link_net_map_id].dev = g_wlan_net_vap_map[ml_net_map_id].dev; /* link绑定ml_netdev */
    g_wlan_net_vap_map[link_net_map_id].vap_id = dpe_vap->uc_vap_id;
    g_wlan_net_vap_map[link_net_map_id].dpe_vap = dpe_vap;
    memcpy_s(g_wlan_net_vap_map[link_net_map_id].netdev_name, sizeof(g_wlan_net_vap_map[link_net_map_id].netdev_name),
        g_wlan_net_vap_map[ml_net_map_id].netdev_name, sizeof(g_wlan_net_vap_map[ml_net_map_id].netdev_name));
    dpe_vap->net_map_id = link_net_map_id;
    oam_warning_log3(dpe_vap->uc_vap_id, OAM_SF_DPA,
        "dpe_wlan_add_link_net_init:link_net_map_id[%d], vap_idx[%d], name_len[%d]",
        link_net_map_id, dpe_vap->uc_vap_id, strlen(g_wlan_net_vap_map[link_net_map_id].netdev_name));
    oam_warning_log3(dpe_vap->uc_vap_id, OAM_SF_DPA,
        "dpe_wlan_add_link_net_init:ml_net_map_id[%d], vap_idx[%d], name_len[%d]",
        ml_net_map_id, ml_vap_idx, strlen(g_wlan_net_vap_map[ml_net_map_id].netdev_name));
    return OAL_SUCC;
}

/* 功能描述: link切换更新映射关系 */
uint32_t dpe_wlan_change_netdev_vap_relation(dpe_wlan_vap_stru *cur_dpe_vap, dpe_wlan_vap_stru *next_dpe_vap)
{
    sync_wlan_priv_info_stru *priv_info = NULL;

    if ((cur_dpe_vap == NULL) || (next_dpe_vap == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_change_netdev_vap_relation:ptr is NULL!}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    if (g_wlan_net_vap_map[cur_dpe_vap->net_map_id].dev != g_wlan_net_vap_map[next_dpe_vap->net_map_id].dev) {
        oam_error_log4(0, OAM_SF_DPA,
            "{dpe_wlan_change_netdev_vap_relation:cur_vap[%d] map_id[%d]/next_vap[%d] map_id[%d] is not same netdev!}",
            cur_dpe_vap->uc_vap_id, cur_dpe_vap->net_map_id, next_dpe_vap->uc_vap_id, next_dpe_vap->net_map_id);
        dpe_wlan_net_map_debug();
        return OAL_FAIL;
    }

    priv_info = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(g_wlan_net_vap_map[cur_dpe_vap->net_map_id].dev);
    if (priv_info == NULL) {
        return OAL_FAIL;
    }
    /* next_dpe_vap已绑定netdev */
    if (g_wlan_net_vap_map[priv_info->net_map_id].vap_id == next_dpe_vap->uc_vap_id) {
        oam_error_log2(0, OAM_SF_DPA, "{dpe_wlan_change_netdev_vap_relation:map_id[%d] has vap[%d]}",
            priv_info->net_map_id, next_dpe_vap->uc_vap_id);
        dpe_wlan_net_map_debug();
        return OAL_FAIL;
    }
    /* 更新绑定关系 */
    priv_info->net_map_id = next_dpe_vap->net_map_id;
    priv_info->vap_id = next_dpe_vap->uc_vap_id;
    oam_warning_log4(0, OAM_SF_DPA,
        "{dpe_wlan_change_netdev_vap_relation:update vap[%d] map_id[%d] / vap[%d] map_id[%d]!}",
        cur_dpe_vap->uc_vap_id, cur_dpe_vap->net_map_id, next_dpe_vap->uc_vap_id, next_dpe_vap->net_map_id);
    return OAL_SUCC;
}
void dpe_wifi_clear_wlan_res(void)
{
    uint8_t map_id;
    uint16_t us_idx;
    dpe_wlan_res_stru *wlan_res = dpe_wlan_res_addr_get();
    dmac_ctx_del_user_stru del_user_data = { 0 };
    dpe_wlan_user_stru *dpe_wlan_user = NULL;
    sync_wlan_priv_info_stru *priv_info = NULL;
    dpe_wlan_net_map_stru *wlan_net_map = dpe_get_wlan_net_vap_map();

    oam_warning_log0(0, OAM_SF_DPA, "{dpe_wifi_clear_wlan_res!}");
    /* 释放全部user资源 */
    for (us_idx = 0; us_idx < WLAN_USER_MAX_USER_LIMIT; us_idx++) {
        dpe_wlan_user = (dpe_wlan_user_stru *)(&wlan_res->dpe_wlan_user_res[us_idx]);
        if (dpe_wlan_user->uc_is_user_alloced != MAC_USER_ALLOCED) {
            continue;
        }
        /* multi user在del vap时统一处理 */
        if (dpe_wlan_user->en_is_multi_user == OAL_TRUE) {
            continue;
        }
        del_user_data.us_user_idx = us_idx;
        dpe_wlan_user_del((uint8_t *)&del_user_data);
    }

    /* link依赖ml netdev, 需优先查找并释放 */
    for (map_id = 0; map_id < HAL_MAX_HW_VAP_NUM; map_id++) {
        if (wlan_net_map[map_id].dpe_vap == NULL) {
            continue;
        }
        priv_info = (sync_wlan_priv_info_stru *)oal_comm_dev_priv(wlan_net_map[map_id].dev);
        if (priv_info == NULL) {
            continue;
        }
        /* 非link netdev不处理 */
        if ((wlan_net_map[priv_info->net_map_id].vap_id == wlan_net_map[map_id].vap_id) ||
            (wlan_net_map[priv_info->net_map_id].dpe_vap == NULL)) {
            continue;
        }
        dpe_wlan_config_del_vap(wlan_net_map[map_id].vap_id, &map_id, wlan_net_map[map_id].dev);
    }

    /* 释放其他全部vap资源 */
    for (map_id = 0; map_id < HAL_MAX_HW_VAP_NUM; map_id++) {
        if (wlan_net_map[map_id].dpe_vap != NULL) {
            dpe_wlan_config_del_vap(wlan_net_map[map_id].vap_id, &map_id, wlan_net_map[map_id].dev);
        }
    }
}
#endif