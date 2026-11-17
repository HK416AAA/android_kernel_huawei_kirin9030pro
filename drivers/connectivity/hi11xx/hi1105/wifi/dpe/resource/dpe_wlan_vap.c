/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_vap.c
 * 作    者 :
 * 创建日期 : 2024年11月15日
 */

/* 1 头文件包含 */
#include "dpe_wlan_vap.h"
#include "dpe_wlan_resource.h"
#include "dpe_wlan_stat.h"
#include "oam_ext_if.h"
#include "dpe_wlan_rx_reorder.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_config.h"
#endif
#include "dpe_sbuf.h"
#include "dpe_netdev_sync.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_VAP_C

dpe_wlan_vap_atomic_var g_wlan_vap_atomic_res[WLAN_VAP_MAX_NUM_LIMIT];
/*
 * 函 数 名  : dpe_wlan_vap_get
 * 功能描述  : 获取对应DPE VAP
 * 1.日    期  : 2024年11月21日
 *   修改内容  : 新生成函数
 */
dpe_wlan_vap_stru *dpe_wlan_vap_get(uint16_t us_idx)
{
    dpe_wlan_res_stru *wlan_res = dpe_wlan_res_addr_get();
    if (us_idx >= WLAN_VAP_MAX_NUM_LIMIT) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_vap_get::dpe_vap null,vap_idx=%d.}", us_idx);
        return NULL;
    }
    return (dpe_wlan_vap_stru *)(&wlan_res->dpe_wlan_vap_res[us_idx]);
}

OAL_STATIC void dpe_wlan_vap_init(dpe_wlan_vap_stru *dpe_vap, uint16_t vap_idx)
{
    uint32_t loop;
    memset_s(dpe_vap, sizeof(dpe_wlan_vap_stru), 0, sizeof(dpe_wlan_vap_stru));

    for (loop = 0; loop < DPE_VAP_USER_HASH_MAX_VALUE; loop++) {
        oal_dlist_init_head(&(dpe_vap->ast_user_hash[loop]));
    }
    /* cache user 锁初始化 */
    dpe_vap->cache_user_lock_idx = vap_idx;
    oal_spin_lock_init(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx));
    oal_dlist_init_head(&dpe_vap->st_mac_user_list_head);
    dpe_vap->us_cache_user_id = g_wlan_spec_cfg->invalid_user_id;
    dpe_vap->us_assoc_vap_id = g_wlan_spec_cfg->invalid_user_id;
    dpe_vap->net_map_id = HAL_MAX_HW_VAP_NUM;
    oal_netbuf_list_head_init_nolock(&dpe_vap->rx_rpt_wait_list);
    dpe_vap->wait_list_lock_idx = vap_idx;
    oal_spin_lock_init(dpe_get_vap_wait_list_lock(dpe_vap->wait_list_lock_idx));

    dpe_vap->atomic_val = &g_wlan_vap_atomic_res[vap_idx];
    oal_atomic_set(&dpe_vap->atomic_val->tx_suspend_user_cnt, 0);
}

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
/*
 * 函 数 名  : dpe_vap_get_host_net_device
 * 功能描述  : 通过vap id获取 net_device
 * 1.日    期  : 2013年9月6日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_net_device_stru *dpe_vap_get_host_net_device(uint8_t vap_id)
{
    dpe_wlan_vap_stru *dpe_vap;
    oal_net_device_stru *net_device = NULL;
#ifdef _PRE_WLAN_FEATURE_ML
    oal_netdev_priv_stru *net_dev_priv;
#endif

    dpe_vap = (dpe_wlan_vap_stru *)dpe_wlan_vap_get(vap_id);
    if (dpe_vap == NULL) {
        oam_error_log0(vap_id, OAM_SF_DPA, "{hmac_vap_get_net_device::dpe_vap null.}");
        return NULL;
    }

    net_device = dpe_vap->pst_net_device;
    if (net_device == NULL) {
        return NULL;
    }
#ifdef _PRE_WLAN_FEATURE_ML
    net_dev_priv = (oal_netdev_priv_stru *)oal_net_dev_wireless_priv(net_device);
    if (net_dev_priv == NULL) {
        return net_device;
    }
    /* 只有mld netdev才会挂接ml_netdev指针，为空说明是非mld vap，直接返回当前netdev即可 */
    if (net_dev_priv->mlo_cfg_info.ml_netdev == NULL) {
        return net_device;
    }
    /* mld netdev不管是wlan0还是link都会挂接ml_netdev指针，统一转化为ml_netdev返回 */
    return net_dev_priv->mlo_cfg_info.ml_netdev;
#endif

    return net_device;
}
#endif

#ifdef _PRE_WLAN_FEATURE_ML
OAL_STATIC void dpe_wlan_mld_vap_init(dpe_wlan_vap_stru *dpe_vap, mac_cfg_add_vap_param_stru *vap_param)
{
    if (vap_param->mld_vap_param.mld_mode == WLAN_ML_MODE || vap_param->mld_vap_param.mld_mode == WLAN_ML_LINK_MODE) {
        dpe_vap->mld_assoc_mode = MLD_ASSOC_MODE_MLSR;
        dpe_vap->emlsr_state = EMLSR_CLOSED;
    }
}
#endif

uint32_t dpe_wlan_config_add_vap(uint8_t *param)
{
    mac_cfg_add_vap_param_extend_stru *vap_param_extend = NULL;
    mac_cfg_add_vap_param_stru *vap_param = NULL;
    dpe_wlan_vap_stru *dpe_vap = NULL;

    if (param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_config_add_vap::param is NULL!}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    vap_param_extend = (mac_cfg_add_vap_param_extend_stru *)param;
    vap_param = (mac_cfg_add_vap_param_stru *)(&vap_param_extend->add_vap_param);
    dpe_vap = dpe_wlan_vap_get(vap_param->uc_vap_id);
    if (dpe_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    dpe_wlan_vap_init(dpe_vap, vap_param->uc_vap_id);
    /* 初始化重排序超时时间 */
    dpe_vap_init_set_rx_reorder_timeout(dpe_vap);
    dpe_vap->uc_vap_id = vap_param->uc_vap_id;
    dpe_vap->uc_chip_id = vap_param_extend->add_vap_extend.chip_id;
    dpe_vap->hal_dev_id = vap_param->uc_dst_hal_dev_id;
    dpe_vap->us_multi_user_idx = vap_param->us_muti_user_id;
    dpe_vap->en_vap_mode = vap_param->en_vap_mode;
    dpe_vap->en_p2p_mode = vap_param->en_p2p_mode;
    dpe_vap->core_id = vap_param_extend->add_vap_extend.core_id;
    dpe_vap->uc_device_id = vap_param_extend->add_vap_extend.device_id;
    dpe_vap->bit_support_mcast_ampdu = vap_param_extend->add_vap_extend.bit_support_mcast_ampdu;
    dpe_wlan_multi_user_add(vap_param->us_muti_user_id, vap_param->uc_vap_id, vap_param->multi_user_lut_idx,
        vap_param->multi_user_ml_lut_idx, vap_param_extend->add_vap_extend.bit_support_mcast_ampdu);
#ifdef _PRE_WLAN_FEATURE_ML
    dpe_wlan_mld_vap_init(dpe_vap, vap_param);
#endif
    oam_warning_log3(dpe_vap->uc_vap_id, OAM_SF_DPA,
        "{dpe_wlan_config_add_vap:vap_mode[%d], p2p_mode[%d], ml_vap_id[%d]}",
        dpe_vap->en_vap_mode, dpe_vap->en_p2p_mode, vap_param_extend->add_vap_extend.ml_vap_idx);
    return OAL_SUCC;
}

void dpe_wlan_config_start_vap(uint16_t us_idx, mac_cfg_start_vap_param_stru *start_vap_param)
{
    dpe_wlan_vap_stru *dpe_vap;

    if (start_vap_param == NULL) {
        return;
    }
    dpe_vap = dpe_wlan_vap_get(us_idx);
    if (dpe_vap == NULL) {
        return;
    }

    dpe_vap->en_p2p_mode = start_vap_param->en_p2p_mode;
}

void dpe_wlan_config_down_vap(uint8_t vap_idx, mac_cfg_down_vap_param_stru *down_vap_param)
{
}

void dpe_wlan_config_del_vap(uint8_t vap_idx, uint8_t *param, oal_net_device_stru *net_dev)
{
    dpe_wlan_vap_stru *dpe_vap;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    if (param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_config_del_vap::param is NULL!}");
        return;
    }
    dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }
    dpe_wlan_del_multi_user(dpe_vap->us_multi_user_idx, dpe_vap->bit_support_mcast_ampdu);
    dpe_wlan_del_vap_netdev_sync(dpe_vap, net_dev);
    OAL_SPIN_LOCK_EXIT(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx));
    rx_stats->rx_rpt_wait_list_cnt -= oal_netbuf_list_len(&dpe_vap->rx_rpt_wait_list);
    dpe_netbuf_free_list_all(&dpe_vap->rx_rpt_wait_list, oal_netbuf_list_len(&dpe_vap->rx_rpt_wait_list));
    OAL_SPIN_LOCK_EXIT(dpe_get_vap_wait_list_lock(dpe_vap->wait_list_lock_idx));
    dpe_vap->hal_vap_id = 0xff;
}

void dpe_wlan_config_del_cfg_vap(uint8_t vap_idx)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }

    dpe_del_cfg_vap_netdev_proc(dpe_vap);
}

/*
 * 函 数 名  : hmac_vap_init_set_rx_reorder_timeout
 * 功能描述  : 初始化重排序超时时间
 * 1.日    期  : 2012年10月24日
 *   修改内容  : 新生成函数
 */
void dpe_vap_init_set_rx_reorder_timeout(dpe_wlan_vap_stru *dpe_vap)
{
    dpe_vap->us_rx_timeout[WLAN_WME_AC_BK] = HMAC_BA_RX_BK_TIMEOUT;
    dpe_vap->us_rx_timeout[WLAN_WME_AC_BE] = HMAC_BA_RX_BE_TIMEOUT;
    dpe_vap->us_rx_timeout[WLAN_WME_AC_VI] = HMAC_BA_RX_VI_TIMEOUT;
    dpe_vap->us_rx_timeout[WLAN_WME_AC_VO] = HMAC_BA_RX_VO_TIMEOUT;

    dpe_vap->us_rx_timeout_min[WLAN_WME_AC_BE] = HMAC_BA_RX_BE_TIMEOUT_MIN;
    dpe_vap->us_rx_timeout_min[WLAN_WME_AC_BK] = HMAC_BA_RX_BK_TIMEOUT_MIN;
    dpe_vap->us_rx_timeout_min[WLAN_WME_AC_VI] = HMAC_BA_RX_VI_TIMEOUT_MIN;
    dpe_vap->us_rx_timeout_min[WLAN_WME_AC_VO] = HMAC_BA_RX_VO_TIMEOUT_MIN;
}

/*
 * 函 数 名  : dpe_wlan_cfg_vap_init
 * 功能描述  : DPE侧配置VAP初始化
 *   日    期  : 2024年12月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void dpe_wlan_cfg_vap_init(uint8_t dev_idx, uint16_t vap_idx, uint8_t chip_id)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }

    dpe_wlan_vap_init(dpe_vap, vap_idx);
    /* 初始化重排序超时时间 */
    dpe_vap_init_set_rx_reorder_timeout(dpe_vap);
    dpe_vap->uc_vap_id = vap_idx;
    dpe_vap->uc_chip_id = chip_id;
    dpe_vap->hal_dev_id = 0;    /* 配置vap挂在主路 */
    dpe_vap->en_vap_mode = WLAN_VAP_MODE_CONFIG;
    dpe_vap->en_vap_state = MAC_VAP_STATE_INIT;
    dpe_vap->uc_device_id = dev_idx;
}

void dpe_wlan_vap_state_sync(uint16_t vap_idx, uint8_t *param)
{
    dpe_wlan_vap_stru *dpe_vap;
    mac_vap_state_enum_uint8 vap_state;

    if (param == NULL) {
        return;
    }
    vap_state = (mac_vap_state_enum_uint8)(*param);

    dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }

    dpe_vap->en_vap_state = vap_state;
}

void dpe_wlan_cfg_vap_net_dev_set(uint8_t cfg_vap_idx, oal_net_device_stru *net_dev)
{
    dpe_wlan_vap_stru *dpe_cfg_vap;

    if (net_dev == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_cfg_vap_net_dev_set::net_device is NULL!}");
        return;
    }

    dpe_cfg_vap = dpe_wlan_vap_get(cfg_vap_idx);
    if (dpe_cfg_vap == NULL) {
        return;
    }
    dpe_cfg_vap->pst_net_device = net_dev;
}

void dpe_vap_set_assoc_id(uint8_t vap_id, uint16_t assoc_vap_id)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_id);
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_vap_set_assoc_id::dpe vap is NULL}");
        return;
    }
    dpe_vap->us_assoc_vap_id = assoc_vap_id;
}

#ifdef _PRE_WLAN_FEATURE_ML
void dpe_wlan_mlsr_change_netdev_vap_relation(uint8_t cur_vap_idx, uint8_t next_vap_idx,
    oal_net_device_stru *cur_net_dev, oal_net_device_stru *next_net_dev)
{
    dpe_wlan_vap_stru *cur_dpe_vap;
    dpe_wlan_vap_stru *next_dpe_vap;

    if (cur_net_dev == NULL || next_net_dev == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_mlsr_change_netdev_vap_relation::net_device is NULL!}");
        return;
    }

    cur_dpe_vap = dpe_wlan_vap_get(cur_vap_idx);
    next_dpe_vap = dpe_wlan_vap_get(next_vap_idx);
    if (cur_dpe_vap == NULL || next_dpe_vap == NULL) {
        return;
    }

    cur_dpe_vap->pst_net_device = cur_net_dev;
    next_dpe_vap->pst_net_device = next_net_dev;
}

void dpe_wlan_vap_mld_assoc_mode_set(uint8_t vap_idx, uint8_t mld_assoc_mode)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }
    dpe_vap->mld_assoc_mode = mld_assoc_mode;
}

void dpe_wlan_vap_mld_mode_set(uint8_t vap_idx, uint8_t mld_mode)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }
    dpe_vap->mld_mode = mld_mode;
}

void dpe_wlan_vap_mld_addr_set(uint8_t vap_idx, uint8_t *mld_addr)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }
    memcpy_s(&dpe_vap->mld_addr, WLAN_MAC_ADDR_LEN, mld_addr, WLAN_MAC_ADDR_LEN);
}
#endif  /* _PRE_WLAN_FEATURE_ML */

void dpe_wlan_vap_emlsr_state_sync(uint8_t vap_idx, uint8_t emlsr_state)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        return;
    }
    dpe_vap->emlsr_state = emlsr_state;
}

OAL_STATIC void dpe_wlan_chba_dbac_vap_init_set_rx_reorder_timeout(dpe_wlan_vap_stru *dpe_vap)
{
    uint8_t ac_type;

    for (ac_type = WLAN_WME_AC_BE; ac_type < WLAN_WME_AC_BUTT; ac_type++) {
        dpe_vap->us_rx_timeout[ac_type] = DPE_WLAN_CHBA_DBAC_BA_RX_DEFAULT_TIMEOUT;
        dpe_vap->us_rx_timeout_min[ac_type] = DPE_WLAN_CHBA_DBAC_BA_RX_DEFAULT_TIMEOUT;
    }
    oam_warning_log1(0, OAM_SF_DPA, "{dpe_wlan_chba_dbac_vap_init_set_rx_reorder_timeout:set chba rx_timeout[%d]}",
        DPE_WLAN_CHBA_DBAC_BA_RX_DEFAULT_TIMEOUT);
}

void dpe_wlan_dbac_vap_set_rx_reorder_timeout(uint8_t vap_idx, uint8_t is_dbac_running)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_idx);
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_dbac_vap_set_rx_reorder_timeout::vap is NULL!}");
        return;
    }

    /* 退出dbac模式, 恢复CHBA vap rx重排序定时器超时配置 */
    if (is_dbac_running == OAL_FALSE) {
        dpe_vap_init_set_rx_reorder_timeout(dpe_vap);
        oam_warning_log0(dpe_vap->uc_vap_id, OAM_SF_DPA,
            "{dpe_wlan_dbac_vap_set_rx_reorder_timeout:reset chba vap rx_reorder_timeout}");
        return;
    }
    /* chba进入dbac模式, 初始化chba独有的强制移窗超时定时器定时时间门限配置 */
    dpe_wlan_chba_dbac_vap_init_set_rx_reorder_timeout(dpe_vap);
}

void dpe_wlan_set_chba_start_flag(uint8_t vap_id, uint8_t is_chba_start)
{
    dpe_wlan_vap_stru *dpe_vap = dpe_wlan_vap_get(vap_id);
    if (dpe_vap == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_set_chba_start_flag::vap[%d] is NULL!}", vap_id);
        return;
    }
    dpe_vap->bit_is_start_chba_vap = (is_chba_start == OAL_TRUE);
}
uint32_t dpe_sync_vap_chba_start_flag(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *param)
{
    dpe_wlan_set_chba_start_flag(dpe_vap->uc_vap_id, *param);
    return OAL_SUCC;
}

oal_bool_enum_uint8 dpe_is_chba_mode(dpe_wlan_vap_stru *dpe_vap)
{
    return (dpe_vap->bit_is_start_chba_vap);
}
