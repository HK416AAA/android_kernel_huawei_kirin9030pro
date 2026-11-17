/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_config.c
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年03月28日
 */

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
/* 1 头文件包含 */
#include "hd_event.h"
#include "hd_command.h"
#include "oam_ext_if.h"
#include "host_hal_device.h"
#include "dpe_wlan_config.h"
#include "dpe_wlan_resource.h"
#include "dpe_netdev.h"
#include "hmac_tx_switch.h"
#include "hmac_tx_ring_alloc.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_CONFIG_C

/*****************************************************************************
    HMAC到DPE配置同步事件操作函数表
*****************************************************************************/
OAL_PL1_DATA dpe_config_syn_stru g_dpe_config_syn[] = {
    /* 同步ID                    保留2个字节            函数操作 */
    { WLAN_CFGID_START_VAP,        { 0, 0 }, dpe_config_start_vap },
#ifdef _PRE_WLAN_FEATURE_ML
    { WLAN_CFGID_SET_MLD_VAP_PARAM, { 0, 0 }, dpe_config_set_mld_vap_param },
    { WLAN_CFGID_CHANGE_USER_MLD_MODE, { 0, 0 }, dpe_config_h2d_user_change_to_mld_mode },
#endif
    { WLAN_CFGID_ADD_VAP,          { 0, 0 }, dpe_config_add_vap },
    { WLAN_CFGID_DEL_VAP,          { 0, 0 }, dpe_config_del_vap   },
    { WLAN_CFGID_DOWN_VAP,         { 0, 0 }, dpe_config_down_vap  },
    { WLAN_CFGID_USR_INFO_SYN,     { 0, 0 }, dpe_config_user_info_sync },
    { WLAN_CFGID_SET_ALWAYS_RX,    { 0, 0 }, dpe_config_set_always_rx },
};

dpe_config_syn_stru g_dpe_config_syn_debug[] = {
};

/*****************************************************************************
    HMAC同步DPA事件操作函数表
*****************************************************************************/
dpe_config_syn_stru g_hmac_syn_dpa[] = {
    /* 同步ID                    保留2个字节            函数操作 */
    { WLAN_SYN_DPA_EMLSR_STATE,        { 0, 0 }, dpe_sync_elmsr_state },
#ifdef _PRE_WLAN_FEATURE_ML
    { WLAN_SYN_DPA_MLD_ASSOC_MODE,     { 0, 0 }, dpe_sync_mld_assoc_mode },
    { WLAN_SYN_DPA_EMLSR_TX_RING_BITMAP, { 0, 0 }, dpe_sync_emlsr_tx_ring_bitmap },
    { WLAN_SYN_DPA_VAP_MLD_MODE,       { 0, 0 }, dpe_sync_vap_mld_mode },
    { WLAN_SYN_DPA_CHANGE_TID_BA_INFO, { 0, 0 }, dpe_sync_change_tid_ba_info },
#endif
    { WLAN_SYN_DPA_USER_MAC_ADDR,      { 0, 0 }, dpe_sync_user_mac_addr },
    { WLAN_SYN_DPA_USER_ASSOC_STATE,   { 0, 0 }, dpe_sync_user_assoc_state },
    { WLAN_SYN_DPA_USER_PORT,          { 0, 0 }, dpe_sync_user_port },
    { WLAN_SYN_DPA_ASSOC_VAP_ID,       { 0, 0 }, dpe_sync_assoc_vap_id },
    { WLAN_SYN_DPA_VAP_STATE,          { 0, 0 }, dpe_sync_vap_state },
    { WLAN_SYN_DPA_RX_BA_INIT,         { 0, 0 }, dpe_sync_rx_ba_init },
    { WLAN_SYN_DPA_TRX_SWITCH,         { 0, 0 }, dpe_sync_trx_switch },
#ifdef _PRE_WLAN_FEATURE_RX_PN_CHECK
    { WLAN_SYN_DPA_CLEAR_PTK_RX_PN,    { 0, 0 }, dpe_sync_clear_ptk_rx_pn },
    { WLAN_SYN_DPA_CLEAR_GTK_RX_PN,    { 0, 0 }, dpe_sync_clear_gtk_rx_pn },
#endif
    { WLAN_SYN_DPA_DEL_CFG_VAP,        { 0, 0 }, dpe_sync_del_cfg_vap },
    { WLAN_SYN_DPA_TX_MODE_SWITCH,     { 0, 0 }, dpe_sync_tx_mode_switch },
#ifdef _PRE_WLAN_FEATURE_TX_STAT
    { WLAN_SYN_DPA_TX_STATS_LOG_ON,    { 0, 0 }, dpe_sync_tx_stats_set_log_on },
#endif
    { WLAN_SYN_DPA_UPDATE_USER_KEY_INFO, { 0, 0 }, dpe_config_update_user_key_info },
    { WLAN_SYN_DPA_VAP_CHBA_FLAG,      { 0, 0 }, dpe_sync_vap_chba_start_flag },
    { WLAN_CFGID_SET_ALWAYS_TX,        { 0, 0 }, dpe_config_set_always_tx },
    { WLAN_SYN_DPA_CHANGE_NETDEV_VAP_RELATION, { 0, 0 }, dpe_config_change_netdev_vap_relation },
    { WLAN_SYN_DPA_TID_CLEAR, { 0, 0 }, dpe_sync_clear_tid_queue },
};

/*****************************************************************************
    DMAC到DPE配置同步事件操作函数表
*****************************************************************************/
dpe_config_syn_stru g_dmac_to_dpe_syn[] = {
    /* 同步ID                    保留2个字节            函数操作 */
    { WLAN_CFGID_GET_DBDC_INFO,         { 0, 0 }, dpe_config_get_dbdc_info },
    { WLAN_CFGID_RX_MODE_SWITCH,        { 0, 0 }, dpe_config_d2h_rx_mode_syn },
    { WLAN_CFGID_HAL_VAP_UPDATE,        { 0, 0 }, dpe_config_d2h_hal_vap_syn },
    { WLAN_CFGID_LUT_USR_UPDATE,        { 0, 0 }, dpe_config_d2h_usr_lut_syn },
};

/* Get the cfgid entry */
OAL_STATIC dpe_config_syn_stru *dpe_config_get_cfgid_map(dpe_config_syn_stru *cfgid_map,
    uint16_t en_cfgid, uint32_t cfgid_nums)
{
    uint16_t us_cfgid;
    dpe_config_syn_stru *current_cfgid = NULL;

    for (us_cfgid = 0; us_cfgid < cfgid_nums; us_cfgid++) {
        current_cfgid = cfgid_map + us_cfgid;
        if (current_cfgid->en_cfgid == en_cfgid) {
            return current_cfgid;
        }
    }

    return NULL;
}

/*
 * 函 数 名  : dpe_event_config_syn_get_config_tbl
 * 功能描述  : dpe配置同步事件 获取函数表
 * 日    期  : 2025年4月19日
 * 作    者  : Wi-Fi
 * 修改内容  : 新生成函数
 */
OAL_STATIC uint32_t dpe_event_config_syn_get_config_tbl(dpe_config_event_type_stru *event_type_info,
    dpe_config_syn_stru **config_syn_tbl, uint32_t *config_syn_tbl_size,
    dpe_config_syn_stru **config_syn_debug_tbl, uint32_t *config_syn_debug_tbl_size)
{
    uint8_t event_type = event_type_info->event_type;
    uint8_t event_sub_type = event_type_info->event_subtype;

    if ((event_type == FRW_EVENT_TYPE_HOST_CRX) && (event_sub_type == HMAC_TO_DMAC_SYN_CFG)) {
        (*config_syn_tbl) = g_dpe_config_syn;
        (*config_syn_debug_tbl) = g_dpe_config_syn_debug;
        (*config_syn_tbl_size) = oal_array_size(g_dpe_config_syn);
        (*config_syn_debug_tbl_size) = oal_array_size(g_dpe_config_syn_debug);
    } else if ((event_type == FRW_EVENT_TYPE_HOST_CRX) && (event_sub_type == HMAC_SYN_DPA)) {
        (*config_syn_tbl) = g_hmac_syn_dpa;
        (*config_syn_debug_tbl) = NULL;
        (*config_syn_tbl_size) = oal_array_size(g_hmac_syn_dpa);
        (*config_syn_debug_tbl_size) = 0;   // hmac同步dpa事件只有一张处理函数表
    } else if ((event_type == FRW_EVENT_TYPE_HOST_SDT_REG) && (event_sub_type == DMAC_TO_HMAC_SYN_CFG)) {
        (*config_syn_tbl) = g_dmac_to_dpe_syn;
        (*config_syn_debug_tbl) = NULL;
        (*config_syn_tbl_size) = oal_array_size(g_dmac_to_dpe_syn);
        (*config_syn_debug_tbl_size) = 0;   // hmac同步dpa事件只有一张处理函数表
    } else {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_event_config_syn_get_config_tbl::error event_sub_type!}");
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : dpe_event_config_syn
 * 功能描述  : dpe配置同步事件处理入口
 * 日    期  : 2025年3月27日
 * 作    者  : Wi-Fi
 * 修改内容  : 新生成函数
 */
uint32_t dpe_event_config_syn(uint8_t *hmac2dmac_msg_data, uint8_t vap_id,
    dpe_config_event_type_stru *event_type_info)
{
    uint32_t ret;
    uint32_t config_syn_tbl_size = 0;
    uint32_t config_syn_debug_tbl_size = 0;
    dpe_config_syn_stru *config_syn_tbl = NULL;
    dpe_config_syn_stru *config_syn_debug_tbl = NULL;
    dpe_wlan_vap_stru *dpe_vap = NULL;
    dpe_config_syn_stru *cfgid_entry = NULL;
    hmac_to_dmac_cfg_msg_stru *hmac2dmac_msg = (hmac_to_dmac_cfg_msg_stru *)hmac2dmac_msg_data;

    if (hmac2dmac_msg == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_event_config_syn::hmac2dmac_msg is NULL!}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 获取dpe vap */
    dpe_vap = (dpe_wlan_vap_stru *)dpe_wlan_vap_get(vap_id);
    if (dpe_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (dpe_event_config_syn_get_config_tbl(event_type_info, &config_syn_tbl, &config_syn_tbl_size,
        &config_syn_debug_tbl, &config_syn_debug_tbl_size) != OAL_SUCC) {
        return OAL_FAIL;
    }

    /* 获得cfg id对应的操作函数 */
    if (config_syn_tbl != NULL) {
        cfgid_entry = dpe_config_get_cfgid_map(config_syn_tbl, hmac2dmac_msg->en_syn_id, config_syn_tbl_size);
    }
    if (cfgid_entry == NULL && config_syn_debug_tbl != NULL) {
        cfgid_entry = dpe_config_get_cfgid_map(config_syn_debug_tbl, hmac2dmac_msg->en_syn_id,
            config_syn_debug_tbl_size);
    }
    if (cfgid_entry == NULL) {
        /* 未注册说明是DPA上不关心的事件，直接流转到DMAC */
        return OAL_SUCC;
    }

    /* 异常情况，p_set_func 为空 */
    if (cfgid_entry->p_set_func == NULL) {
        oam_error_log1(vap_id, OAM_SF_DPA,
            "{dpe_event_config_syn::invalid p_set_func cfgid[%d].", hmac2dmac_msg->en_syn_id);
        return OAL_ERR_CODE_INVALID_CONFIG;
    }

    /* 执行操作函数 */
    ret = cfgid_entry->p_set_func(dpe_vap, (uint8_t)(hmac2dmac_msg->us_len), (uint8_t *)hmac2dmac_msg->auc_msg_body);
    if (ret != OAL_SUCC) {
        oam_error_log2(vap_id, OAM_SF_DPA,
            "{dpe_event_config_syn::p_set_func failed, ret=%d en_syn_id=%d.", ret, hmac2dmac_msg->en_syn_id);
        return ret;
    }

    return OAL_SUCC;
}

uint32_t dpe_config_sync_device_send_event(dpe_wlan_vap_stru *dpe_vap, wlan_cfgid_enum_uint16 cfg_id,
    uint8_t *param, uint16_t param_len)
{
    hmac_to_dmac_cfg_msg_stru *syn_msg = NULL;
    frw_event_param_stru frw_param = { 0 };
    uint32_t msg_body_len = param_len + sizeof(hmac_to_dmac_cfg_msg_stru) - 4; // body起始占用的4字节

    if ((dpe_vap == NULL) || (param == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_config_sync_send_event:invalid input!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    syn_msg = oal_memalloc_cache_align(oal_get_cacheline_aligned_len(msg_body_len));
    if (syn_msg == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_config_sync_send_event:invalid input!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    syn_msg->en_syn_id = cfg_id;
    syn_msg->us_len = param_len;
    /* 填写配置同步消息内容 */
    if (memcpy_s(syn_msg->auc_msg_body, syn_msg->us_len, param, param_len) != EOK) {
        oam_error_log0(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_config_sync_send_event:fail to alloc!");
        oal_free(syn_msg);
        return OAL_FAIL;
    }
    frw_param.type = FRW_EVENT_TYPE_HOST_CRX;
    frw_param.subtype = DPA_TO_DMAC_SYN_CFG;
    frw_param.hal_device_id = dpe_vap->uc_device_id;
    frw_param.vap_id = dpe_vap->uc_vap_id;
    frw_param.pipeline = FRW_EVENT_PIPELINE_STAGE_1;
    frw_param.transfer_event_to = FRW_EVENT_TO_WCORE;   /* DPA去往WCPU方向 */
    frw_param.hcc_extend = 1; /* 固定1 */
    frw_param.payload_size = msg_body_len;
    frw_param.payload = (uint8_t *)syn_msg;
    frw_param.netbuf = NULL;

    if (frw_post_event(&frw_param) != OAL_SUCC) {
        oam_error_log1(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_config_sync_device_send_event:cfg[%d] fail", cfg_id);
        oal_free(syn_msg);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

/* dpe上配置同步子事件的适配层函数，接口统一为(dpe_vap, uc_len, puc_param) */
uint32_t dpe_config_start_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_config_start_vap::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    /* 调用具体业务函数 */
    dpe_wlan_config_start_vap(dpe_vap->uc_vap_id, (mac_cfg_start_vap_param_stru *)puc_param);
    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_ML
uint32_t dpe_config_set_mld_vap_param(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    h2d_mld_vap_param_stru *mld_vap_param = (h2d_mld_vap_param_stru *)puc_param;
    if (dpe_vap == NULL || mld_vap_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_config_set_mld_vap_param::dpe_vap or param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_vap_mld_assoc_mode_set(dpe_vap->uc_vap_id, mld_vap_param->mld_assoc_mode);
    dpe_wlan_vap_mld_addr_set(dpe_vap->uc_vap_id, mld_vap_param->mld_addr);
    return OAL_SUCC;
}

uint32_t dpe_config_h2d_user_change_to_mld_mode(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    dpe_wlan_config_h2d_user_change_to_mld_mode(puc_param);
    return OAL_SUCC;
}
#endif

uint32_t dpe_config_user_info_sync(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    dpe_wlan_user_info_sync(puc_param);
    return OAL_SUCC;
}

uint32_t dpe_config_del_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    uint8_t map_id;
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_config_del_vap::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    /* dpe_vap已被释放, 不再重复释放 */
    map_id = dpe_net_map_find_same_vap_by_vapid(dpe_vap->uc_vap_id);
    if (map_id >= HAL_MAX_HW_VAP_NUM) {
        oam_warning_log0(dpe_vap->uc_vap_id, OAM_SF_DPA, "{dpe_config_del_vap::dep_vap has been del!");
        return OAL_SUCC;
    }
    dpe_wlan_config_del_vap(dpe_vap->uc_vap_id, puc_param, dpe_vap_get_net_device(dpe_vap->uc_vap_id));
    return OAL_SUCC;
}

uint32_t dpe_config_down_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_config_down_vap::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_config_down_vap(dpe_vap->uc_vap_id, (mac_cfg_down_vap_param_stru *)puc_param);
    return OAL_SUCC;
}

uint32_t dpe_config_set_always_rx(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL || puc_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_config_set_always_rx::dpe_vap or puc_param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    hal_set_alrx_status(dpe_vap->hal_dev_id, (uint8_t)(*puc_param));
    dpe_wlan_device_al_trx_flag_sync((uint8_t)(*puc_param));
    return OAL_SUCC;
}

uint32_t dpe_config_set_always_tx(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    return dpe_always_tx_host_ring_check(dpe_vap, uc_len, puc_param);
}

/* hmac同步到dpa的子事件的适配层函数 */
uint32_t dpe_sync_elmsr_state(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_elmsr_state::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    /* 调用具体业务函数 */
    dpe_wlan_vap_emlsr_state_sync(dpe_vap->uc_vap_id, (uint8_t)(*puc_param));
    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_ML
uint32_t dpe_sync_mld_assoc_mode(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_mld_assoc_mode::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_vap_mld_assoc_mode_set(dpe_vap->uc_vap_id, (uint8_t)(*puc_param));
    return OAL_SUCC;
}

uint32_t dpe_sync_emlsr_tx_ring_bitmap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_emlsr_tx_ring_bitmap::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_tx_ring_set_mld_bitmap_next(dpe_vap->us_assoc_vap_id, (uint8_t)(*puc_param));
    return OAL_SUCC;
}

uint32_t dpe_sync_vap_mld_mode(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL || puc_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_mld_mode::dpe_vap or param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_vap_mld_mode_set(dpe_vap->uc_vap_id, (*puc_param));
    return OAL_SUCC;
}

uint32_t dpe_sync_change_tid_ba_info(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    mac_change_tid_ba_param_stru *change_tid_ba_param = (mac_change_tid_ba_param_stru *)puc_param;

    if (puc_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_change_tid_ba_info::param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_change_tid_ba_info(change_tid_ba_param->cur_work_user_idx, change_tid_ba_param->next_work_user_idx);
    return OAL_SUCC;
}
#endif

uint32_t dpe_sync_user_mac_addr(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    mac_sync_user_param_stru *user_param = (mac_sync_user_param_stru *)puc_param;
    if (user_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_user_mac_addr::param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_user_addr_sync(user_param->us_assoc_id, user_param->auc_user_mac_addr);
    return OAL_SUCC;
}

uint32_t dpe_sync_user_assoc_state(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    mac_sync_user_param_stru *user_param = (mac_sync_user_param_stru *)puc_param;
    if (user_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_user_assoc_state::param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_user_assoc_state_sync(user_param->us_assoc_id, user_param->en_user_asoc_state);
    return OAL_SUCC;
}

uint32_t dpe_sync_user_port(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    mac_sync_user_param_stru *user_param = (mac_sync_user_param_stru *)puc_param;
    if (user_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_user_port::param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_user_set_port_sync(user_param->us_assoc_id, user_param->en_port_valid);
    return OAL_SUCC;
}

uint32_t dpe_sync_assoc_vap_id(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_assoc_vap_id::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_vap_set_assoc_id(dpe_vap->uc_vap_id, (uint16_t)(*puc_param));
    return OAL_SUCC;
}

uint32_t dpe_sync_vap_state(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_vap_state::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_vap_state_sync(dpe_vap->uc_vap_id, puc_param);
    return OAL_SUCC;
}

uint32_t dpe_config_add_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    uint32_t ret;
    dpe_wlan_vap_stru *dpe_add_vap = NULL;
    mac_cfg_add_vap_param_extend_stru *vap_param_extend = (mac_cfg_add_vap_param_extend_stru *)puc_param;
    ret = dpe_wlan_config_add_vap(puc_param);
    if (ret != OAL_SUCC) {
        return ret;
    }

    dpe_add_vap = dpe_wlan_vap_get(vap_param_extend->add_vap_param.uc_vap_id);
    /* link net初始化 */
    if (dpe_add_vap->uc_vap_id != vap_param_extend->add_vap_extend.ml_vap_idx) {
        return dpe_wlan_add_link_net_init(dpe_add_vap, vap_param_extend->add_vap_extend.ml_vap_idx);
    }
    dpe_wlan_add_vap_net_init(dpe_add_vap,
        (oal_net_device_stru *)(uintptr_t)(vap_param_extend->add_vap_param.pst_net_dev),
        (mac_cfg_add_vap_extend_stru *)(&vap_param_extend->add_vap_extend));
    return OAL_SUCC;
}

uint32_t dpe_sync_rx_ba_init(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    dpe_wlan_rx_ba_init((hmac_ba_rx_para_stru *)puc_param);
    return OAL_SUCC;
}

uint32_t dpe_sync_trx_switch(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    dpe_trx_switch_sync((wlan_trx_switch_stru *)puc_param);
    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_RX_PN_CHECK
uint32_t dpe_sync_clear_ptk_rx_pn(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    uint16_t user_idx;

    if (puc_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_clear_ptk_rx_pn::param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    user_idx = (uint16_t)(*puc_param);
    dpe_hmac_user_clear_ptk_rx_pn(user_idx);
    return OAL_SUCC;
}

uint32_t dpe_sync_clear_gtk_rx_pn(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    uint16_t user_idx;

    if (puc_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_clear_gtk_rx_pn::param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    user_idx = (uint16_t)(*puc_param);
    dpe_hmac_user_clear_gtk_rx_pn(user_idx);
    return OAL_SUCC;
}
#endif
uint32_t dpe_sync_del_cfg_vap(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (dpe_vap == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_del_cfg_vap::dpe_vap is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_config_del_cfg_vap(dpe_vap->uc_vap_id);
    return OAL_SUCC;
}

uint32_t dpe_sync_tx_mode_switch(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (puc_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_tx_mode_switch::puc_param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_tx_mode_switch((uint32_t *)puc_param);
    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_TX_STAT
uint32_t dpe_sync_tx_stats_set_log_on(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *puc_param)
{
    if (puc_param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_tx_stats_set_log_on::puc_param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }
    dpe_wlan_tx_stats_set_log_on((uint32_t *)puc_param);
    return OAL_SUCC;
}
#endif

/* 功能描述 : rx ddr 接收数据帧 dpe侧hal vap与mac vap， hal device 之间的映射关系同步 */
uint32_t dpe_config_d2h_usr_lut_syn(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param)
{
    d2h_usr_lut_info_syn_event *usr_ldx_info = NULL;
    hal_host_chip_stru *hal_chip = hal_get_host_chip();

    usr_ldx_info = (d2h_usr_lut_info_syn_event *)param;
    if (usr_ldx_info->lut_idx >= HAL_MAX_LUT) {
        return OAL_FAIL;
    }

    if (!usr_ldx_info->valid) {
        hal_chip->user_sts_info[usr_ldx_info->lut_idx].user_valid = 0;
    } else {
        hal_chip->user_sts_info[usr_ldx_info->lut_idx].user_valid = 1;
        hal_chip->user_sts_info[usr_ldx_info->lut_idx].user_id = usr_ldx_info->usr_idx;
    }

    oam_warning_log3(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_config_d2h_usr_lut_syn:lut_idx[%d],usr_idx[%d],valid[%d]",
        usr_ldx_info->lut_idx, usr_ldx_info->usr_idx, usr_ldx_info->valid);

    return OAL_SUCC;
}

/* 功能描述 : rx ddr 接收数据帧 host侧hal vap与mac vap， hal device 之间的映射关系同步 */
uint32_t dpe_config_d2h_hal_vap_syn(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param)
{
    d2h_hal_vap_info_syn_event *d2h_hal_vap_info = NULL;
    hal_host_device_stru *hal_dev = NULL;

    d2h_hal_vap_info = (d2h_hal_vap_info_syn_event *)param;
    if ((d2h_hal_vap_info->hal_dev_id >= mac_chip_get_hal_dev_num()) ||
        (d2h_hal_vap_info->hal_vap_id >= mac_chip_get_hal_max_vap_num())) {
        return OAL_FAIL;
    }

    hal_dev = hal_get_host_device(d2h_hal_vap_info->hal_dev_id);
    if (hal_dev == NULL) {
        oam_error_log0(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_config_d2h_hal_vap_syn: hal_dev null");
        return OAL_FAIL;
    }

    if (!d2h_hal_vap_info->valid) {
        hal_dev->hal_vap_sts_info[d2h_hal_vap_info->hal_vap_id].hal_vap_valid = 0;
        dpe_vap->hal_dev_id = 0xff;
        dpe_vap->hal_vap_id = 0xff;
    } else {
        hal_dev->hal_vap_sts_info[d2h_hal_vap_info->hal_vap_id].hal_vap_valid = 1;
        hal_dev->hal_vap_sts_info[d2h_hal_vap_info->hal_vap_id].mac_vap_id = d2h_hal_vap_info->mac_vap_id;
        dpe_vap->hal_dev_id = d2h_hal_vap_info->hal_dev_id;
        dpe_vap->hal_vap_id = d2h_hal_vap_info->hal_vap_id;
    }
    oam_warning_log3(dpe_vap->uc_vap_id, OAM_SF_DPA, "dpe_config_d2h_hal_vap_syn:haldev[%d],mac vap[%d],valid[%d]",
        d2h_hal_vap_info->hal_dev_id, d2h_hal_vap_info->mac_vap_id, d2h_hal_vap_info->valid);

    return OAL_SUCC;
}

uint32_t dpe_config_get_dbdc_info(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param)
{
    hal_host_device_stru *hal_device = (hal_host_device_stru *)hal_get_host_device(HAL_DEVICE_ID_SLAVE);
    if (hal_device == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    hal_device->mac_intr_error_cnt = 0;
    oam_warning_log1(0, OAM_SF_DPA, "dpe_config_d2h_hal_vap_syn::dbdc state[%d]", *param);
    return OAL_SUCC;
}

uint32_t dpe_config_d2h_rx_mode_syn(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param)
{
    mac_rx_switch_stru *rx_switch = (mac_rx_switch_stru *)param;
    hal_host_device_stru *hal_device  = hal_get_host_device(rx_switch->hal_device_id);

    if (hal_device == NULL) {
        return OAL_FAIL;
    }

    if (hal_device->rx_alloc_list_inited == OAL_FALSE && rx_switch->new_rx_mode == HAL_RAM_RX) {
        return OAL_SUCC;  /* 未初始化时默认值为HAL_RAM_RX，无需切换 */
    }

    if (rx_switch->new_rx_mode >= HAL_SWTICH_ING ||
        oal_atomic_read(&hal_device->atomic_val->rx_mode) == rx_switch->new_rx_mode) {
        oam_error_log2(rx_switch->hal_device_id, OAM_SF_DPA,
            "dpe_config_d2h_rx_mode_syn::new[%d]==old[%d][0:ddr, 1:ram]",
            rx_switch->new_rx_mode, oal_atomic_read(&hal_device->atomic_val->rx_mode));
    }

    oam_warning_log3(rx_switch->hal_device_id, OAM_SF_DPA, "hmac_config_d2h_rx_mode_syn:: \
        switch rx from %d to %d [0:ddr, 1:ram]once reset smac%d",
        oal_atomic_read(&hal_device->atomic_val->rx_mode), rx_switch->new_rx_mode, rx_switch->once_ddr_reset_smac);
    hal_pm_try_wakeup_forbid_sleep(HAL_PM_FORBIDE_SLEEP_D2H_RX_MODE_SYN);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_D2H_RX_MODE_SYN);
        return OAL_FAIL;
    }
    if (rx_switch->new_rx_mode == HAL_DDR_RX) {
        /* DEVICE reset过host rx ring */
        if (rx_switch->once_ddr_reset_smac == OAL_TRUE) {
            hal_host_rx_reset_smac_handler(hal_device);
        }
        /* host完成接收的准备工作,抛事件到device使能DDR接收 */
        if (hal_rx_d2h_init_dscr_queue(rx_switch->hal_device_id) != OAL_SUCC) {
            hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_D2H_RX_MODE_SYN);
            return OAL_FAIL;
        }
        dpe_config_sync_device_send_event(dpe_vap, WLAN_CFGID_RX_MODE_SWITCH, param, sizeof(mac_rx_switch_stru));
    }

    /* 统一host切换接收模式，防止d2h没内存抛事件失败导致上下状态不一致 */
    oal_atomic_set(&(hal_device->atomic_val->rx_mode), rx_switch->new_rx_mode);
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_D2H_RX_MODE_SYN);
    /* 触发TX 切换 */
    hmac_tx_switch(rx_switch->new_rx_mode);
    return OAL_SUCC;
}

uint32_t dpe_config_update_user_key_info(dpe_wlan_vap_stru *dpe_vap, uint8_t len, uint8_t *param)
{
    dpe_wlan_update_user_key_info(param);
    return OAL_SUCC;
}

/* 功能描述: hmac->dpe link切换事件同步处理接口 */
uint32_t dpe_config_change_netdev_vap_relation(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *param)
{
    dpe_wlan_vap_stru *dpe_next_work_vap = dpe_wlan_vap_get(*param);
    return dpe_wlan_change_netdev_vap_relation(dpe_vap, dpe_next_work_vap);
}
uint32_t dpe_sync_clear_tid_queue(dpe_wlan_vap_stru *dpe_vap, uint8_t uc_len, uint8_t *param)
{
    uint16_t user_idx;
    if (param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_sync_clear_tid_queue::param is null!");
        return OAL_ERR_CODE_PTR_NULL;
    }

    user_idx = (uint16_t)(*param);
    hmac_clear_tid_queue(user_idx);
    return OAL_SUCC;
}
#endif
