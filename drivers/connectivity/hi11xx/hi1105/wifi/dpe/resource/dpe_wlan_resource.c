/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : DPE资源池主文件
 * 作    者 : wifi
 * 创建日期 : 2024年11月18日
 */
#include "dpe_wlan_config.h"
#include "hmac_host_al_tx.h"
#include "wlan_spec_cfg.h"
#include "oam_ext_if.h"
#include "oal_ext_if.h"
#include "dpe_wlan_resource.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_RESOURCE_C

OAL_PL1_BSS dpe_wlan_res_stru g_dpe_ast_wlan_res;
OAL_PL1_BSS dpe_wlan_stat_res_stru g_dpe_wlan_stat_res;
dpe_wlan_lock_res_stru g_dpe_wlan_lock_res;
/* dpe模式下，g_dpe_wlan_stat_res_ptr指针会在dpa初始化时赋值成cma共享内存; acpu只读, dpa可进行读写,
 * 即hmac的g_dpe_wlan_stat_res_ptr指针指向其自身全局变量g_dpe_wlan_stat_res,
 * dpa的g_dpe_wlan_stat_res_ptr指针会在后续流程重新指向hmac/dpa的cma共享内存, 而不再使用全局变量g_dpe_wlan_stat_res */
OAL_PL1_DATA dpe_wlan_stat_res_stru *g_dpe_wlan_stat_res_ptr = &g_dpe_wlan_stat_res;
OAL_PL1_DATA wlan_trx_switch_stru g_dpe_trx_switch = { 0 };
oal_wlan_cfg_stru g_wlan_spec_cfg_dpe = {
    .hal_dev_num = WLAN_DEVICE_MAX_NUM_PER_CHIP,
};
const oal_wlan_cfg_stru *g_wlan_spec_cfg = &g_wlan_spec_cfg_dpe;
/*  查询当前芯片支持的最大带宽 */
uint8_t dpe_wlan_chip_get_max_5g_bw(void)
{
    return g_wlan_spec_cfg->max_5g_bw;
}
dpe_wlan_res_stru *dpe_wlan_res_addr_get(void)
{
    return (dpe_wlan_res_stru *)(&g_dpe_ast_wlan_res);
}

OAL_STATIC void dpe_wlan_stat_res_init(void)
{
    memset_s(&g_dpe_wlan_stat_res, sizeof(g_dpe_wlan_stat_res), 0, sizeof(g_dpe_wlan_stat_res));
}

void dpe_wlan_res_init(void)
{
    /* 收发资源初始化 */
    memset_s(&g_dpe_ast_wlan_res, sizeof(dpe_wlan_res_stru), 0, sizeof(dpe_wlan_res_stru));
    /* 收发统计资源初始化 */
    dpe_wlan_stat_res_init();
    /* dpe device初始化 */
    dpe_wlan_device_init(0, 0, 0);  // device_id: 0, cfg_vap_id: 0, chip_id: 0
    /* 常发资源初始化 */
    dpe_wlan_altx_res_init();
}

void dpe_pm_reset_trx_stat(void)
{
    if (g_dpe_wlan_stat_res_ptr == NULL) {
        return;
    }
    memset_s(&(g_dpe_wlan_stat_res_ptr->device_stat[0]),
        sizeof(dpe_wlan_device_stat_stru) * WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC, 0,
        sizeof(dpe_wlan_device_stat_stru) * WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC);
    memset_s(&(g_dpe_wlan_stat_res_ptr->vap_stat[0]), sizeof(dpe_wlan_vap_stat_stru) * WLAN_VAP_MAX_NUM_LIMIT,
        0, sizeof(dpe_wlan_vap_stat_stru) * WLAN_VAP_MAX_NUM_LIMIT);
    memset_s(&(g_dpe_wlan_stat_res_ptr->user_stat[0]), sizeof(dpe_wlan_user_stat_stru) * WLAN_USER_MAX_USER_LIMIT,
        0, sizeof(dpe_wlan_user_stat_stru) * WLAN_USER_MAX_USER_LIMIT);
}

static void dpe_wlan_private_spec_cfg(const oal_wlan_cfg_stru *spec_cfg)
{
#ifdef _PRE_DUAL_CHIP
    /* 兼容单芯片的场景，增加判断总线上是否是双芯片 */
    if (oal_bus_get_chip_num() < WLAN_CHIP_MAX_NUM_PER_BOARD) {
        memcpy_s(&g_wlan_spec_cfg_dpe, sizeof(oal_wlan_cfg_stru), spec_cfg, sizeof(oal_wlan_cfg_stru));

        g_wlan_spec_cfg_dpe.vap_support_max_num_limit = HAL_MAX_VAP_NUM_DUAL_MP15;
        g_wlan_spec_cfg_dpe.hal_max_vap_num = HAL_MAX_VAP_NUM_MP13;

        g_wlan_spec_cfg = &g_wlan_spec_cfg_dpe;
    }
#endif
}

/* 功能描述: 获取最大hal_vap个数 */
uint8_t dpe_mac_chip_get_hal_max_vap_num(void)
{
    return g_wlan_spec_cfg->hal_max_vap_num;
}
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_chip_feature_init_export(int32_t chip)
{
    if (chip == BOARD_VERSION_MP13) {
        g_wlan_spec_cfg = &g_wlan_spec_cfg_mp13;
    } else if (chip == BOARD_VERSION_MP15) {
        g_wlan_spec_cfg = &g_wlan_spec_cfg_mp15;
    }
}
#endif
void dpe_chip_feature_init_dpe_support(int32_t chip)
{
    if (chip == BOARD_VERSION_MP17C || chip == BOARD_VERSION_MP17A) {
        g_wlan_spec_cfg = &g_wlan_spec_cfg_mp17c;
    } else if (chip == BOARD_VERSION_MP12) {
        g_wlan_spec_cfg = &g_wlan_spec_cfg_mp12;
    }
}
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_chip_feature_init_dpe_not_support(int32_t chip)
{
    if (chip == BOARD_VERSION_MP16) {
        g_wlan_spec_cfg = &g_wlan_spec_cfg_mp16;
    } else if (chip == BOARD_VERSION_MP16C) {
        if (get_mpxx_subchip_version() == CHIP_VERSION_PILOT) {
            g_wlan_spec_cfg = &g_wlan_spec_cfg_mp16c;
        } else {
            g_wlan_spec_cfg = &g_wlan_spec_cfg_mp17c_mpw;
        }
    } else if (chip == BOARD_VERSION_GF61) {
        g_wlan_spec_cfg = &g_wlan_spec_cfg_gf61;
    }
}
#endif
int32_t dpe_chip_feature_init(void)
{
    int32_t chip = get_mpxx_subchip_type();
    if (chip >= BOARD_VERSION_MPXX_BUTT) {
        oal_io_print("wifi unsupport chiptype[%d]\n", chip);
        return -OAL_EFAIL;
    }
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_chip_feature_init_export(chip);
#endif
#ifndef _PRE_WLAN_EXPORT
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_chip_feature_init_dpe_not_support(chip);
#endif
    dpe_chip_feature_init_dpe_support(chip);
#endif
    /* 私有定制化配置项 */
    dpe_wlan_private_spec_cfg(g_wlan_spec_cfg);
    return OAL_SUCC;
}

oal_spin_lock_stru *dpe_get_user_dev_rx_list_lock(uint16_t lock_idx)
{
    if (lock_idx >= WLAN_USER_MAX_USER_LIMIT) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_get_user_dev_rx_list_lock::lock_idx [%d] too max", lock_idx);
        return &(g_dpe_wlan_lock_res.device_rx_list_lock[0]);
    }
    return &(g_dpe_wlan_lock_res.device_rx_list_lock[lock_idx]);
}
oal_spin_lock_stru *dpe_get_vap_cache_user_lock(uint16_t lock_idx)
{
    if (lock_idx >= WLAN_VAP_MAX_NUM_LIMIT) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_get_vap_cache_user_lock::lock_idx [%d] too max", lock_idx);
        return &(g_dpe_wlan_lock_res.cache_user_lock[0]);
    }
    return &(g_dpe_wlan_lock_res.cache_user_lock[lock_idx]);
}
oal_spin_lock_stru *dpe_get_vap_wait_list_lock(uint16_t lock_idx)
{
    if (lock_idx >= WLAN_VAP_MAX_NUM_LIMIT) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_get_vap_wait_list_lock::lock_idx [%d] too max", lock_idx);
        return &(g_dpe_wlan_lock_res.wait_list_lock[0]);
    }
    return &(g_dpe_wlan_lock_res.wait_list_lock[lock_idx]);
}
oal_spin_lock_stru *dpe_get_dev_rx_alloc_list_lock(uint16_t lock_idx)
{
    if (lock_idx >= DPE_WLAN_DEV_RX_ALLOC_LIST_LIMIT) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_get_dev_rx_alloc_list_lock::lock_idx [%d] too max", lock_idx);
        return &(g_dpe_wlan_lock_res.dev_rx_alloc_list_lock[0]);
    }
    return &(g_dpe_wlan_lock_res.dev_rx_alloc_list_lock[lock_idx]);
}
oal_spin_lock_stru *dpe_get_frw_thread_lock(void)
{
    return &(g_dpe_wlan_lock_res.dpe_frw_thread_lock);
}
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
oal_spin_lock_stru *dpe_get_tid_list_lock(uint8_t lock_idx)
{
    if (lock_idx >= HOST_TX_LIST_BUTT) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_get_tid_list_lock::lock_idx [%d] too max", lock_idx);
        return &(g_dpe_wlan_lock_res.tid_list_lock[0]);
    }
    return &(g_dpe_wlan_lock_res.tid_list_lock[lock_idx]);
}
#else
oal_mutex_stru *dpe_get_tid_list_lock(uint8_t lock_idx)
{
    if (lock_idx >= HOST_TX_LIST_BUTT) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_get_tid_list_lock::lock_idx [%d] too max", lock_idx);
        return &(g_dpe_wlan_lock_res.tid_list_lock[0]);
    }
    return &(g_dpe_wlan_lock_res.tid_list_lock[lock_idx]);
}
#endif
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
OAL_PL1_DATA wlan_pm_ring_stat g_wlan_pm_ring_stat = { 0 };
pm_wlan_pkt_statis_stru g_pm_wlan_pkt_statis = { 0 };

wlan_pm_ring_stat *wlan_pm_get_ring_stat(void)
{
    return &g_wlan_pm_ring_stat;
}
pm_wlan_pkt_statis_stru *wlan_pm_get_pkt_stat(void)
{
    return &g_pm_wlan_pkt_statis;
}
uint32_t dpe_pm_get_trx_cnt(void)
{
    uint32_t total_pkt = 0;
    pm_wlan_pkt_statis_stru *wlan_pm_pkt = wlan_pm_get_pkt_stat();
    if (wlan_pm_pkt == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_pm_get_trx_cnt: wlan_pm_pkt is null \n");
        return 0;
    }
    total_pkt = wlan_pm_pkt->ring_tx_pkt + wlan_pm_pkt->d2h_rx_pkt + wlan_pm_pkt->host_rx_pkt;

    memset_s(wlan_pm_pkt, sizeof(pm_wlan_pkt_statis_stru), 0, sizeof(pm_wlan_pkt_statis_stru));
    return total_pkt;
}
void dpe_clean_wlan_pm_ring_stat(void)
{
    wlan_pm_ring_stat *wlan_pm_info = wlan_pm_get_ring_stat();
    if (wlan_pm_info == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_clean_wlan_pm_ring_stat: wlan_pm is null \n");
        return;
    }
    wlan_pm_info->tid_not_empty_cnt = 0;
    wlan_pm_info->tid_ring_host_cnt = 0;
    wlan_pm_info->master_ddr_rx_cnt = 0;
    wlan_pm_info->slave_ddr_rx_cnt = 0;
    wlan_pm_info->host_forbid_sleep_cnt = 0;
    wlan_pm_info->ring_has_mpdu_cnt = 0;
}

void dpe_wlan_pm_print_debug_info(void)
{
    wlan_pm_ring_stat *wlan_pm_info = wlan_pm_get_ring_stat();
    pm_wlan_pkt_statis_stru *wlan_pm_pkt = wlan_pm_get_pkt_stat();
    if (wlan_pm_info == NULL || wlan_pm_pkt == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_wlan_pm_print_debug_info: wlan_pm or wlan_pm_pkt is null \n");
        return;
    }
    oam_warning_log3(0, OAM_SF_DPA, "dpe::tid not empty[%d],ring host[%d]+mpdu num[%d]",
        wlan_pm_info->tid_not_empty_cnt, wlan_pm_info->tid_ring_host_cnt, wlan_pm_info->ring_has_mpdu_cnt);
    oam_warning_log3(0, OAM_SF_DPA, "dpe::m ddr[%d], s ddr[%d], forbid[%d]",
        wlan_pm_info->master_ddr_rx_cnt, wlan_pm_info->slave_ddr_rx_cnt, wlan_pm_info->host_forbid_sleep_cnt);
    oam_warning_log3(0, OAM_SF_DPA, "dpe pm trx cnt::ring_tx_pkt[%d], d2h_rx_pkt[%d], host_rx_pkt[%d]",
        wlan_pm_pkt->ring_tx_pkt, wlan_pm_pkt->d2h_rx_pkt, wlan_pm_pkt->host_rx_pkt);
}
#endif