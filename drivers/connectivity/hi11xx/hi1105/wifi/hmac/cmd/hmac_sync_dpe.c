/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac同步dpa接口源文件
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年4月21日
 */
#include "conn_dmi_msg.h"
#include "dpe_wlan_vap.h"
#include "dpe_tx_data.h"
#include "dpe_wlan_resource.h"
#include "dpe_main.h"
#include "dpe_dpa_intf.h"
#include "hmac_register_dpa.h"
#include "hmac_rx.h"
#include "hmac_tx_switch.h"
#include "hmac_tx_stat.h"
#include "hmac_tx_data.h"
#include "hmac_stat.h"
#include "hmac_config.h"
#include "hmac_invoke_dpe.h"
#include "dpe_wlan_stat.h"
#include "hmac_auto_adjust_freq.h"
#include "hmac_sync_dpe.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_SYNC_DPE_C

#define MAX_DPA_WLAN_STAT_RES_SIZE (1024 * 1024)

OAL_STATIC dpe_wlan_stat_res_stru *g_wlan_stat_shared_res_ptr = NULL;
dmi_msg_content_stru g_wifi_dmi_msg_info = { { 0 }, 0 }; // 初始化dmi消息携带的内容

/* DFR: IPC msg通知WIFI DPE，阻塞式返回 */
oal_completion  g_dfr_wifi_recover_msg;
oal_completion g_dfr_wifi_excp_msg;
int32_t hmac_dfr_wifi_recover_msg_ack(uint8_t type, void *priv)
{
    oal_complete(&g_dfr_wifi_recover_msg);
    oam_warning_log0(0, 0, "dfr_wifi_recover_msg done\n");
    return 0;
}
int32_t hmac_dfr_wifi_excp_msg_ack(uint8_t type, void *priv)
{
    oal_complete(&g_dfr_wifi_excp_msg);
    oam_warning_log0(0, 0, "dfr_wifi_excp_msg done\n");
    return 0;
}

oal_completion  g_wifi_update_trx_stat_recover_msg;
int32_t hmac_wifi_update_trx_stat_recover_msg_ack(uint8_t type, void *priv)
{
    oal_complete(&g_wifi_update_trx_stat_recover_msg);
    return 0;
}

void hmac_dfr_wifi_recover_msg(void)
{
    unsigned long dmi_msg_time = 0;
    /* 定制化关闭，不处理 */
    if (dpe_is_support_dpe_offload() != OAL_TRUE) {
        return;
    }
    dmi_msg_time = oal_read_once(OAL_TIME_JIFFY);
    // send wifi dfr recovery ipc msg
    oal_init_completion(&g_dfr_wifi_recover_msg);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_WIFI_DFR_RECOVER, hmac_dfr_wifi_recover_msg_ack, NULL);
    if (oal_wait_for_completion_timeout(&g_dfr_wifi_recover_msg, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC)) == 0) {
        oam_error_log0(0, 0, "hmac_dfr_wifi_recover_msg:: wait dfr completion timeout !\n");
        return;
    }
    oam_warning_log1(0, OAM_SF_CFG, "hmac_dfr_wifi_recover_msg:: Total time = %d",
        oal_jiffies_to_msecs(oal_read_once(OAL_TIME_JIFFY) - dmi_msg_time));
}
void hmac_dfr_wifi_excp_msg(void)
{
    unsigned long dmi_msg_time = 0;
    /* 定制化关闭，不处理 */
    if (dpe_is_support_dpe_offload() != OAL_TRUE) {
        return;
    }
    dmi_msg_time = oal_read_once(OAL_TIME_JIFFY);

    // send wifi dfr expc ipc msg
    oal_init_completion(&g_dfr_wifi_excp_msg);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_WIFI_DFR_EXCP, hmac_dfr_wifi_excp_msg_ack, NULL);
    if (oal_wait_for_completion_timeout(&g_dfr_wifi_excp_msg, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC)) == 0) {
        oam_error_log0(0, 0, "hmac_dfr_wifi_excp_msg:: wait dfr completion timeout !\n");
        return;
    }

    oam_warning_log1(0, OAM_SF_CFG, "hmac_dfr_wifi_excp_msg:: Total time = %d",
        oal_jiffies_to_msecs(oal_read_once(OAL_TIME_JIFFY) - dmi_msg_time));
}

oal_completion g_forbid_access_ready;
static int32_t hmac_dfr_forbid_access_cb(uint8_t type, void *priv)
{
    oal_complete(&g_forbid_access_ready);
    oam_warning_log0(0, 0, "hmac_dfr_forbid_access_cb done\n");
    return 0;
}

void hmac_dfr_forbid_access_notify_dpe(void)
{
    unsigned long dmi_msg_time = 0;
    if (hmac_is_support_dpe_offload() == OAL_FALSE) {
        return;
    }
    dmi_msg_time = oal_read_once(OAL_TIME_JIFFY);

    oal_init_completion(&g_forbid_access_ready);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_WIFI_FORBID_ACCESS, hmac_dfr_forbid_access_cb, NULL);
    if (oal_wait_for_completion_timeout(&g_forbid_access_ready, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC)) == 0) {
        oam_error_log0(0, 0, "hmac_dfr_forbid_access_notify_dpe:: wait forbid access completion timeout !\n");
        return;
    }

    oam_warning_log1(0, OAM_SF_CFG, "hmac_dfr_forbid_access_notify_dpe:: dmi msg Total time = %d",
        oal_jiffies_to_msecs(oal_read_once(OAL_TIME_JIFFY) - dmi_msg_time));
}

oal_completion g_dpa_init_ready;
static int32_t hmac_init_notify_dpe_cb(uint8_t type, void *priv)
{
    oal_complete(&g_dpa_init_ready);
    oam_warning_log0(0, 0, "dpe_main_init done\n");
    return 0;
}
void hmac_send_wifi_init_dmi_msg(void)
{
    if (hmac_is_support_dpe_offload() == OAL_FALSE) {
        return;
    }
    oal_init_completion(&g_dpa_init_ready);
    conn_dmi_msg_send(CONN_DMI_MSG_WIFI_INIT, (uint8_t *)&g_wifi_dmi_msg_info, sizeof(dmi_msg_content_stru),
        hmac_init_notify_dpe_cb, NULL);
    if (oal_wait_for_completion_timeout(&g_dpa_init_ready, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC)) == 0) {
        oam_error_log0(0, 0, "hmac_init_notify_dpe:: wait dpe init completion timeout !\n");
        return;
    }
    oam_warning_log0(0, OAM_SF_CFG, "hmac_send_wifi_init_dmi_msg:: send done");
}

static inline oal_bool_enum_uint8 hmac_dpe_shared_res_ptr_is_aligned(uint64_t share_base)
{
    const uint64_t mask = 0xff; /* 共享内存应256字节对齐 */
    return ((share_base & mask) == 0);
}

void hmac_init_notify_dpe(void)
{
    unsigned long dmi_msg_time = 0;
    size_t cma_size = sizeof(dpe_wlan_stat_res_stru); // 确认申请的大小
    void *virt_base = NULL;
    oal_build_bug_on(sizeof(dmi_msg_content_stru) > CONN_DMI_MSG_DATA_LEN); // 编译守护dmi消息携带的数据最大长度

    if (cma_size > MAX_DPA_WLAN_STAT_RES_SIZE) {
        oam_error_log1(0, OAM_SF_CFG, "hmac_init_notify_dpe::cma size is %d", cma_size);
    }

    /* 记录注册网络设备资源初始化 */
    hmac_init_regist_netdev();
    /* WIFI DPE资源初始化 */
    dpe_module_init();

    if (hmac_is_support_dpe_offload() == OAL_FALSE) {
        return;
    }
    register_wifi_dpa_init_after_reset(wal_dfr_dpa_init_notify);
    hmac_wlan_dpe_cb_register();

    dmi_msg_time = oal_read_once(OAL_TIME_JIFFY);

    memcpy_s(&g_wifi_dmi_msg_info.trx_switch, sizeof(wlan_trx_switch_stru),
        &g_dpe_trx_switch, sizeof(wlan_trx_switch_stru));
    /*
        ACPU/DPA共享访问区CMA，dpa uncache，acpu cache虚拟地址, 申请的内存给dpe_wlan_stat_res_stru使用，以及后续备用
        返回值为虚拟地址，acpu使用
        入参cma_base为物理地址，dpa使用
    */
    virt_base = dpe_dpa_cma_alloc(cma_size, &g_wifi_dmi_msg_info.cma_base);
    if (virt_base != NULL) {
        memset_s(virt_base, cma_size, 0, cma_size);
        g_wlan_stat_shared_res_ptr = (dpe_wlan_stat_res_stru *)virt_base;
        oam_warning_log2(0, OAM_SF_CFG, "{hmac_init_notify_dpe:alloc mem size[%d], is_aligned[%d]}",
            cma_size, hmac_dpe_shared_res_ptr_is_aligned(g_wifi_dmi_msg_info.cma_base));
    } else {
        oam_error_log1(0, OAM_SF_CFG, "hmac_init_notify_dpe:: cma alloc fail,size[%u]", cma_size);
    }

    hmac_send_wifi_init_dmi_msg();

    oam_warning_log1(0, OAM_SF_CFG, "hmac_init_notify_dpe:: dmi msg Total time = %d",
        oal_jiffies_to_msecs(oal_read_once(OAL_TIME_JIFFY) - dmi_msg_time));
}

oal_completion g_dpe_wifi_on_ready;
static int32_t hmac_wifi_on_notify_dpe_cb(uint8_t type, void *priv)
{
    oal_complete(&g_dpe_wifi_on_ready);
    oam_warning_log0(0, 0, "dpe_wifi_on done\n");
    return 0;
}

void hmac_wifi_on_notify_dpe(void)
{
    unsigned long dmi_msg_time = 0;
    if (hmac_is_support_dpe_offload() == OAL_FALSE) {
        return;
    }
    dmi_msg_time = oal_read_once(OAL_TIME_JIFFY);

    oal_init_completion(&g_dpe_wifi_on_ready);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_WIFI_ON, hmac_wifi_on_notify_dpe_cb, NULL);
    if (oal_wait_for_completion_timeout(&g_dpe_wifi_on_ready, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC)) == 0) {
        oam_error_log0(0, 0, "hmac_wifi_on_notify_dpe:: wait dpe wifi on completion timeout !\n");
        return;
    }

    oam_warning_log1(0, OAM_SF_CFG, "hmac_wifi_on_notify_dpe:: dmi msg Total time = %d",
        oal_jiffies_to_msecs(oal_read_once(OAL_TIME_JIFFY) - dmi_msg_time));
}

oal_completion g_dpe_wifi_off_ready;
static int32_t hmac_wifi_off_notify_dpe_cb(uint8_t type, void *priv)
{
    oal_complete(&g_dpe_wifi_off_ready);
    oam_warning_log0(0, 0, "dpa_wifi_off done\n");
    return 0;
}

void hmac_wifi_off_notify_dpe(void)
{
    unsigned long dmi_msg_time = 0;
    if (hmac_is_support_dpe_offload() == OAL_FALSE) {
        return;
    }
    dmi_msg_time = oal_read_once(OAL_TIME_JIFFY);

    oal_init_completion(&g_dpe_wifi_off_ready);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_WIFI_OFF, hmac_wifi_off_notify_dpe_cb, NULL);
    if (oal_wait_for_completion_timeout(&g_dpe_wifi_off_ready, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC)) == 0) {
        oam_error_log0(0, 0, "hmac_wifi_off_notify_dpe:: wait dpe wifi off completion timeout !\n");
        return;
    }

    oam_warning_log1(0, OAM_SF_CFG, "hmac_wifi_off_notify_dpe:: dmi msg Total time = %d",
        oal_jiffies_to_msecs(oal_read_once(OAL_TIME_JIFFY) - dmi_msg_time));
}

void hmac_wifi_state_sync_dpe(wifi_state_enum wifi_state)
{
    switch (wifi_state) {
        case WIFI_STATE_ON:
            hmac_wifi_on_notify_dpe();
            break;
        case WIFI_STATE_OFF:
            hmac_wifi_off_notify_dpe();
            break;
        case WIFI_STATE_DFR_RECOVER:
            hmac_dfr_wifi_recover_msg();
            break;
        case WIFI_STATE_FORBID_ACCESS:
            hmac_dfr_forbid_access_notify_dpe();
            break;
        case WIFI_STATE_DFR_EXCP:
            hmac_dfr_wifi_excp_msg();
            break;
        default:
            break;
    }
}
void hmac_chip_feature_init(void)
{
    dpe_chip_feature_init();
}

/* 只WIFI SME初始化, WIFI DPE初始化由netdev sync流程完成 */
void hmac_cfg_vap_net_dev_info_sync(uint8_t cfg_vap_idx)
{
    hmac_vap_stru *hmac_cfg_vap = mac_res_get_hmac_vap(cfg_vap_idx);
    if (hmac_cfg_vap == NULL) {
        return;
    }
    dpe_wlan_cfg_vap_net_dev_set(cfg_vap_idx, hmac_cfg_vap->pst_net_device);
}
/* 只WIFI SME初始化, WIFI DPE初始化由altx event流程完成 */
void hmac_wlan_device_al_trx_flag_sync(uint8_t in_al_trx)
{
    dpe_wlan_device_al_trx_flag_sync(in_al_trx);
}
#ifdef _PRE_WLAN_FEATURE_ML
void hmac_mld_params_update_config_event(mac_vap_stru *mac_vap, hmac_mld_manage_stru *mld_vap_manage,
    h2d_mld_vap_param_stru *h2d_mld_vap_param)
{
    if (mac_vap == NULL || mld_vap_manage == NULL) {
        oam_error_log0(0, 0, "{hmac_config_mld_params_update_event::mac_vap or mld_vap_manage is null!}");
        return;
    }
    /* 抛事件到dmac，设置dmac_mld_vap_manage下的mld_addr */
    hmac_config_send_event(mac_vap, WLAN_CFGID_SET_MLD_VAP_PARAM,
        sizeof(h2d_mld_vap_param_stru), (uint8_t *)h2d_mld_vap_param);
    dpe_wlan_vap_mld_assoc_mode_set(mac_vap->uc_vap_id, mld_vap_manage->mld_assoc_mode);
    dpe_wlan_vap_mld_addr_set(mac_vap->uc_vap_id, mld_vap_manage->mld_addr);
}

void hmac_mld_assoc_mode_sync_event(uint8_t vap_id, uint8_t mld_assoc_mode)
{
    dpe_wlan_vap_mld_assoc_mode_set(vap_id, mld_assoc_mode);

    /* HMAC上同步mld_assoc_mode到DPA */
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_id), WLAN_SYN_DPA_MLD_ASSOC_MODE,
        sizeof(uint8_t), &mld_assoc_mode);
}

void hmac_vap_mld_mode_sync(uint8_t vap_idx, uint8_t mld_mode)
{
    dpe_wlan_vap_mld_mode_set(vap_idx, mld_mode);
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_idx), WLAN_SYN_DPA_VAP_MLD_MODE,
        sizeof(uint8_t), (&mld_mode));
}

void hmac_change_tid_ba_info_sync_dpe(uint8_t vap_idx, uint16_t cur_work_user_idx, uint16_t next_work_user_idx)
{
    mac_change_tid_ba_param_stru change_tid_ba_param = { 0 };

    dpe_change_tid_ba_info(cur_work_user_idx, next_work_user_idx);

    change_tid_ba_param.cur_work_user_idx = cur_work_user_idx;
    change_tid_ba_param.next_work_user_idx = next_work_user_idx;
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_idx), WLAN_SYN_DPA_CHANGE_TID_BA_INFO,
        sizeof(mac_change_tid_ba_param_stru), (uint8_t *)(&change_tid_ba_param));
}

void hmac_change_netdev_vap_relation_sync(uint8_t cur_vap_idx, uint8_t next_vap_idx,
    oal_net_device_stru *cur_net_dev, oal_net_device_stru *next_net_dev)
{
    dpe_wlan_mlsr_change_netdev_vap_relation(cur_vap_idx, next_vap_idx, cur_net_dev, next_net_dev);
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(cur_vap_idx),
        WLAN_SYN_DPA_CHANGE_NETDEV_VAP_RELATION, sizeof(uint8_t), &next_vap_idx);
}

void hmac_config_h2d_user_change_to_mld_mode_sync_dpe(uint8_t *event_param)
{
    dpe_wlan_config_h2d_user_change_to_mld_mode(event_param);
}
#endif

void hmac_user_mac_addr_sync(uint16_t user_idx, uint8_t *addr)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);

    dpe_wlan_user_addr_sync(user_idx, addr);

    if (dpe_user == NULL) {
        return;
    }
    /* HMAC上同步user_mac_addr到DPA */
    hmac_sync_user_mac_addr_send_event(dpe_user->uc_vap_id, user_idx, addr);
}

void hmac_user_assoc_state_sync(uint16_t user_idx, mac_user_asoc_state_enum_uint8 user_asoc_state)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);

    dpe_wlan_user_assoc_state_sync(user_idx, user_asoc_state);

    if (dpe_user == NULL) {
        return;
    }
    /* HMAC上同步user_assoc_state到DPA */
    hmac_sync_user_assoc_state_send_event(dpe_user->uc_vap_id, user_idx, user_asoc_state);
}

void hmac_user_port_sync(uint16_t user_idx, oal_bool_enum_uint8 en_port_valid)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);

    dpe_user_set_port_sync(user_idx, en_port_valid);

    if (dpe_user == NULL) {
        return;
    }
    /* HMAC上同步port_valid到DPA */
    hmac_sync_user_port_send_event(dpe_user->uc_vap_id, user_idx, en_port_valid);
}

void hmac_vap_assoc_id_sync(uint8_t vap_id, uint16_t assoc_vap_id)
{
    dpe_vap_set_assoc_id(vap_id, assoc_vap_id);

    /* HMAC上同步assoc_vap_id到DPA */
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_id), WLAN_SYN_DPA_ASSOC_VAP_ID,
        sizeof(uint16_t), (uint8_t *)(&assoc_vap_id));
}

void hmac_vap_state_sync(uint16_t vap_idx, uint8_t *param)
{
    dpe_wlan_vap_state_sync(vap_idx, param);

    /* HMAC上同步vap_state到DPA */
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_idx), WLAN_SYN_DPA_VAP_STATE,
        sizeof(mac_vap_state_enum_uint8), param);
}

OAL_STATIC uint8_t hmac_add_vap_sync_dpe_get_ml_vap_idx(uint8_t vap_id)
{
    mac_vap_stru *ml_mac_vap = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    oal_netdev_priv_stru *net_dev_priv = NULL;

    if (g_wlan_spec_cfg->feature_ml_is_supported == OAL_FALSE) {
        return vap_id;
    }
    hmac_vap = mac_res_get_hmac_vap(vap_id);
    if ((hmac_vap == NULL) || (hmac_vap->pst_net_device == NULL)) {
        oam_error_log0(vap_id, OAM_SF_ANY, "hmac_add_vap_sync_dpe_get_ml_vap_idx:fail to get vap");
        return vap_id;
    }
    if (is_legacy_sta(&hmac_vap->st_vap_base_info) == OAL_FALSE) {
        return vap_id;
    }

    net_dev_priv = (oal_netdev_priv_stru *)oal_net_dev_wireless_priv(hmac_vap->pst_net_device);
    if (net_dev_priv == NULL) {
        return vap_id;
    }
    /* 只有mld netdev才会挂接ml_netdev指针，为空说明是非mld vap，直接返回当前vap_id即可 */
    if (net_dev_priv->mlo_cfg_info.ml_netdev == NULL) {
        return vap_id;
    }
    /* mld netdev不管是wlan0还是link都会挂接ml_netdev指针，通过ml_netdev获取对应ml_mac_vap */
    ml_mac_vap = oal_net_dev_priv(net_dev_priv->mlo_cfg_info.ml_netdev);
    if (ml_mac_vap == NULL) {
        return vap_id;
    }
    oam_warning_log1(vap_id, OAM_SF_ANY, "hmac_add_vap_sync_dpe_get_ml_vap_idx:get ml_vap_id[%d]",
        ml_mac_vap->uc_vap_id);
    return ml_mac_vap->uc_vap_id;
}

/* 功能描述: 同步user秘钥管理信息至dpe的总接口 */
void mac_sync_dpe_user_key_info(mac_user_stru *mac_user)
{
    mac_vap_stru *mac_vap = NULL;
    mac_user_key_sync_dpe_info sync_key_info = { 0 };
    if (mac_user == NULL) {
        oam_error_log0(0, OAM_SF_CFG, "{mac_sync_dpe_user_key_info::user[%d] null.}");
        return;
    }
    mac_vap = (mac_vap_stru *)mac_res_get_mac_vap(mac_user->uc_vap_id);
    if (mac_vap == NULL) {
        oam_error_log1(0, OAM_SF_CFG, "{mac_sync_dpe_user_key_info:fail to get mac_vap[%d]}", mac_user->uc_vap_id);
        return;
    }

    sync_key_info.user_idx = mac_user->us_assoc_id;
    memcpy_s(&(sync_key_info.key_info), sizeof(mac_key_mgmt_stru), &mac_user->st_key_info, sizeof(mac_key_mgmt_stru));
    dpe_wlan_update_user_key_info((uint8_t *)&sync_key_info);
    /* HMAC上同步密钥信息更新事件到DPA */
    hmac_sync_dpa_send_event(mac_vap, WLAN_SYN_DPA_UPDATE_USER_KEY_INFO,
        sizeof(mac_user_key_sync_dpe_info), (uint8_t *)(&sync_key_info));
}
/* 功能描述: 同步user秘钥管理信息至dpe的总接口 */
void mac_add_vap_sync_dpe_user_key_info(hmac_vap_stru *hmac_vap)
{
    mac_vap_stru *mac_vap = &(hmac_vap->st_vap_base_info);
    mac_user_stru *mac_user = (mac_user_stru *)mac_res_get_mac_user(mac_vap->us_multi_user_idx);
    if (mac_user == NULL) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_UM,
                         "{mac_add_vap_sync_dpe_user_key_info::mac_user[%d] null.}", mac_vap->us_multi_user_idx);
        return;
    }
    mac_sync_dpe_user_key_info(mac_user);
}

void hmac_add_vap_sync(uint8_t *param, uint8_t *param_extend, mac_vap_stru *mac_vap)
{
    errno_t ret;
    hmac_vap_stru *hmac_vap = NULL;
    mac_cfg_add_vap_param_extend_stru *vap_param_extend = (mac_cfg_add_vap_param_extend_stru *)param_extend;

    if (param == NULL || param_extend == NULL || mac_vap == NULL) {
        return;
    }
    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if ((hmac_vap == NULL) || (hmac_vap->pst_net_device == NULL)) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "hmac_add_vap_sync:fail to get vap");
        return;
    }
    memset_s(vap_param_extend, sizeof(mac_cfg_add_vap_param_extend_stru), 0,
        sizeof(mac_cfg_add_vap_param_extend_stru));
    if (memcpy_s(&vap_param_extend->add_vap_param, sizeof(mac_cfg_add_vap_param_stru),
        param, sizeof(mac_cfg_add_vap_param_stru)) != EOK) {
        oam_error_log0(0, 0, "{hmac_add_vap_sync::memcpy fail!}");
        return;
    }
    vap_param_extend->add_vap_extend.core_id = mac_vap->core_id;
    vap_param_extend->add_vap_extend.chip_id = mac_vap->uc_chip_id;
    vap_param_extend->add_vap_extend.device_id = mac_vap->uc_device_id;
    vap_param_extend->add_vap_extend.bit_support_mcast_ampdu = mac_vap->bit_support_mcast_ampdu;
    vap_param_extend->add_vap_extend.ml_vap_idx = hmac_add_vap_sync_dpe_get_ml_vap_idx(mac_vap->uc_vap_id);
    ret = strncpy_s(vap_param_extend->add_vap_extend.netdev_name, sizeof(vap_param_extend->add_vap_extend.netdev_name),
        hmac_vap->pst_net_device->name, strlen(hmac_vap->pst_net_device->name));
    if (ret != EOK) {
        oam_error_log1(0, OAM_SF_ANY, "{hmac_add_vap_sync:fail to cpy name! ret[%d]}", ret);
        return;
    }
    dpe_wlan_config_add_vap((uint8_t *)(vap_param_extend));
    dpe_wlan_add_vap_net_init(dpe_wlan_vap_get(mac_vap->uc_vap_id),
        (oal_net_device_stru *)(uintptr_t)(vap_param_extend->add_vap_param.pst_net_dev),
        (mac_cfg_add_vap_extend_stru *)(&vap_param_extend->add_vap_extend));
    oam_warning_log4(mac_vap->uc_vap_id, OAM_SF_ANY,
        "{hmac_add_vap_sync:ml_vap_idx[%d], support_mcast_ampdu[%d], name_len[%d/%d]}",
        vap_param_extend->add_vap_extend.ml_vap_idx, vap_param_extend->add_vap_extend.bit_support_mcast_ampdu,
        strlen(vap_param_extend->add_vap_extend.netdev_name), strlen(hmac_vap->pst_net_device->name));
}

void hmac_rx_ba_init_sync(hmac_ba_rx_para_stru *ba_rx, uint8_t vap_id, uint16_t assoc_id, uint8_t tid)
{
    if (ba_rx == NULL) {
        return;
    }
    ba_rx->uc_vap_id = vap_id;
    ba_rx->us_assoc_id = assoc_id;
    ba_rx->uc_tid_no = tid;
    dpe_wlan_rx_ba_init(ba_rx);

    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_id), WLAN_SYN_DPA_RX_BA_INIT,
        sizeof(hmac_ba_rx_para_stru), (uint8_t *)ba_rx);
}

void hmac_trx_switch_sync(wlan_trx_switch_stru *trx_switch)
{
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(0), WLAN_SYN_DPA_TRX_SWITCH,
        sizeof(wlan_trx_switch_stru), (uint8_t *)trx_switch);
}

void hmac_clear_ptk_rx_pn_sync(hmac_user_stru *hmac_user)
{
    if (hmac_user == NULL) {
        oam_error_log0(0, 0, "{hmac_clear_ptk_rx_pn_sync::hmac_user is null!}");
        return;
    }
    dpe_hmac_user_clear_ptk_rx_pn(hmac_user->st_user_base_info.us_assoc_id);

    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(hmac_user->st_user_base_info.uc_vap_id),
        WLAN_SYN_DPA_CLEAR_PTK_RX_PN, sizeof(uint16_t), (uint8_t *)(&(hmac_user->st_user_base_info.us_assoc_id)));
}

void hmac_clear_gtk_rx_pn_sync(hmac_user_stru *hmac_user)
{
    if (hmac_user == NULL) {
        oam_error_log0(0, 0, "{hmac_clear_gtk_rx_pn_sync::hmac_user is null!}");
        return;
    }
    dpe_hmac_user_clear_gtk_rx_pn(hmac_user->st_user_base_info.us_assoc_id);

    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(hmac_user->st_user_base_info.uc_vap_id),
        WLAN_SYN_DPA_CLEAR_GTK_RX_PN, sizeof(uint16_t), (uint8_t *)(&(hmac_user->st_user_base_info.us_assoc_id)));
}

void hmac_del_cfg_vap_sync(uint8_t vap_idx)
{
    dpe_wlan_config_del_cfg_vap(vap_idx);
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_idx), WLAN_SYN_DPA_DEL_CFG_VAP,
        sizeof(uint8_t), (uint8_t *)(&vap_idx));
}
void hmac_tid_clear_sync(hmac_user_stru *hmac_user, uint8_t sync_to_dpa)
{
    if (hmac_user == NULL) {
        oam_error_log0(0, 0, "{hmac_tid_clear_sync::hmac_user is null!}");
        return;
    }

    hmac_clear_tid_queue(hmac_user->st_user_base_info.us_assoc_id);

    if (sync_to_dpa != OAL_TRUE) {
        return;
    }
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(hmac_user->st_user_base_info.uc_vap_id),
        WLAN_SYN_DPA_TID_CLEAR, sizeof(uint16_t), (uint8_t *)(&(hmac_user->st_user_base_info.us_assoc_id)));
}

uint32_t hmac_tx_mode_switch_sync(uint8_t vap_idx, uint32_t *params)
{
    uint32_t ret = OAL_SUCC;

    ret = dpe_wlan_tx_mode_switch(params);
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_idx), WLAN_SYN_DPA_TX_MODE_SWITCH,
        sizeof(uint8_t), (uint8_t *)params);
    return ret;
}

#ifdef _PRE_WLAN_FEATURE_TX_STAT
uint32_t hmac_tx_stats_set_log_on_sync(uint8_t vap_idx, uint32_t *params)
{
    uint32_t ret = OAL_SUCC;

    ret = dpe_wlan_tx_stats_set_log_on(params);
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_idx), WLAN_SYN_DPA_TX_STATS_LOG_ON,
        sizeof(uint8_t), (uint8_t *)params);
    return ret;
}
#endif

#ifdef _PRE_WLAN_FEATURE_EMLSR
void hmac_vap_emlsr_state_sync_dpe(uint8_t vap_idx, uint8_t emlsr_state)
{
    dpe_wlan_vap_emlsr_state_sync(vap_idx, emlsr_state);
    /* HMAC上同步emlsr state到DPA */
    hmac_sync_dpa_send_event((mac_vap_stru *)mac_res_get_mac_vap(vap_idx), WLAN_SYN_DPA_EMLSR_STATE,
        sizeof(uint8_t), &emlsr_state);
}
#endif

#ifdef _PRE_WLAN_CHBA_MGMT
void hmac_dbac_vap_set_rx_reorder_timeout_sync(uint8_t vap_idx, uint8_t is_dbac_running)
{
    dpe_wlan_dbac_vap_set_rx_reorder_timeout(vap_idx, is_dbac_running);
}
void hmac_sync_dpe_chba_start_flag(hmac_vap_stru *hmac_vap, uint8_t is_chba_start)
{
    dpe_wlan_set_chba_start_flag(hmac_vap->st_vap_base_info.uc_vap_id, is_chba_start);
    hmac_sync_dpa_send_event(&(hmac_vap->st_vap_base_info), WLAN_SYN_DPA_VAP_CHBA_FLAG,
        sizeof(uint8_t), &is_chba_start);
}
#endif

void hmac_config_del_vap_sync_dpe(uint8_t vap_idx, uint8_t *param, oal_net_device_stru *net_dev)
{
    dpe_wlan_config_del_vap(vap_idx, param, net_dev);
}

void hmac_user_info_sync_dpe(uint8_t *param)
{
    dpe_wlan_user_info_sync(param);
}

void hmac_config_down_vap_sync_dpe(uint8_t vap_idx, mac_cfg_down_vap_param_stru *down_vap_param)
{
    dpe_wlan_config_down_vap(vap_idx, down_vap_param);
}

void hmac_config_start_vap_sync_dpe(uint16_t us_idx, mac_cfg_start_vap_param_stru *start_vap_param)
{
    dpe_wlan_config_start_vap(us_idx, start_vap_param);
}

void hmac_user_del_sync_dpe(frw_event_mem_stru *event_mem)
{
    frw_event_stru *event = frw_get_event_stru(event_mem);
    uint8_t *del_user_data = (uint8_t *)event->auc_event_data;
    dpe_wlan_user_del(del_user_data);
}

void hmac_user_add_sync_dpe(frw_event_mem_stru *event_mem)
{
    frw_event_stru *event = frw_get_event_stru(event_mem);
    uint8_t *add_user_data = (uint8_t *)event->auc_event_data;
    dpe_wlan_user_add(add_user_data, event->st_event_hdr.uc_vap_id);
}

int32_t hmac_netdev_sync_dpa(oal_net_device_stru *net_device,
    sync_wlan_priv_info_stru *netdev_priv_info)
{
    errno_t str_ret;
    int32_t ret = OAL_SUCC;
    sync_wlan_priv_info_stru *dpe_netdev_priv_info = NULL;

    if (dpe_is_support_dpe_offload() == OAL_FALSE) {
        return OAL_SUCC;
    }
    if (oal_strncmp("Hisilicon0", net_device->name, OAL_STRLEN("Hisilicon0")) == 0) {
        return OAL_SUCC;
    }

    dpe_netdev_priv_info = (sync_wlan_priv_info_stru *)oal_mem_alloc_m(OAL_MEM_POOL_ID_LOCAL,
        DPE_SYNC_NET_PRIV_INFO_SIZE, OAL_TRUE);
    if (dpe_netdev_priv_info == NULL) {
        return OAL_FAIL;
    }

    str_ret = strncpy_s(netdev_priv_info->netdev_name, sizeof(netdev_priv_info->netdev_name),
        net_device->name, strlen(net_device->name));
    if (str_ret != EOK) {
        oam_error_log2(0, OAM_SF_ANY, "{hmac_netdev_sync_dpa:fail to cpy name! event[%d], ret[%d]}",
            netdev_priv_info->sync_event, str_ret);
    }
    memcpy_s(dpe_netdev_priv_info, sizeof(sync_wlan_priv_info_stru),
        netdev_priv_info, sizeof(sync_wlan_priv_info_stru));
    oam_warning_log3(0, OAM_SF_ANY, "{hmac_netdev_sync_dpa:event[%d], update_type[%d], vap_id[%d]}",
        netdev_priv_info->sync_event, netdev_priv_info->update_type, netdev_priv_info->vap_id);
    ret = dpe_dpa_sms_sync_netdev_ops(net_device, dpe_netdev_priv_info);
    oal_mem_free_m(dpe_netdev_priv_info, OAL_TRUE);

    return ret;
}

void hmac_netdev_sync_dpa_del_p2p_cl_vap(hmac_vap_stru *hmac_vap)
{
    sync_wlan_priv_info_stru dpe_netdev_priv_info = { 0 };

    dpe_netdev_priv_info.sync_event = DPE_NETDEV_SYNC_DEL_VAP;
    hmac_netdev_sync_dpa(hmac_vap->pst_p2p0_net_device, &dpe_netdev_priv_info);
    dpe_netdev_priv_info.sync_event = DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV;
    dpe_netdev_priv_info.update_type = DPE_NETDEV_SYNC_VAP_UPDATE;
    dpe_netdev_priv_info.vap_id = hmac_vap->st_vap_base_info.uc_vap_id;
    hmac_netdev_sync_dpa(hmac_vap->pst_net_device, &dpe_netdev_priv_info);
}

/*
 * 功能描述  : 设置网络设备mac地址接口归一，更新mac地址时需要同步更新到balong
 * 1.参数   : is_sync_dpa为控制同步开关，在netdev未注册到balong时需置OAL_FALSE，已注册时置OAL_TRUE
 */
void hmac_netdev_update_mac_addr(oal_net_device_stru *netdev,
    uint8_t *mac_addr, uint8_t is_sync_dpa, uint8_t array_len)
{
    sync_wlan_priv_info_stru dpe_netdev_priv_info = { 0 };

    oal_set_mac_addr((uint8_t *)oal_netdevice_mac_addr(netdev), mac_addr);

    if (is_sync_dpa != OAL_TRUE) {
        return;
    }
    // link网络设备信息不需要同步给balong
    if (oal_strcmp(oal_netdevice_name(netdev), "link") == 0) {
        return;
    }

    dpe_netdev_priv_info.sync_event = DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV;
    dpe_netdev_priv_info.update_type = DPE_NETDEV_SYNC_UPDATE_MAC;
    // 复用DPE_NETDEV_SYNC_VAP_UPDATE_NETDEV事件，在dpa update回调中更新balong网络设备的mac地址
    memcpy_s(dpe_netdev_priv_info.netdev_mac, OAL_MAC_ADDR_LEN, mac_addr, OAL_MAC_ADDR_LEN);
    hmac_netdev_sync_dpa(netdev, &dpe_netdev_priv_info);
}

OAL_STATIC uint32_t hmac_sync_dpe_to_update_stat_info(void)
{
    oal_init_completion(&g_wifi_update_trx_stat_recover_msg);
    // 如果是dpa复位，在dpa未完成初始化时，不可以向dpa下发dmi消息。
    if (wal_dfr_is_dpa_reset() == OAL_TRUE) {
        return OAL_FAIL;
    }
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_WIFI_DFX_UPDATE,
        hmac_wifi_update_trx_stat_recover_msg_ack, NULL);
    if (oal_wait_for_completion_timeout(&g_wifi_update_trx_stat_recover_msg,
        (uint32_t)oal_msecs_to_jiffies(60)) == 0) { // 等待60ms，小于hmac_wlan_auto_freq_timeout周期（100ms）
        oam_error_log0(0, OAM_SF_ANY, "hmac_sync_dpe_to_update_stat_info:fail to update trx stat !\n");
        return OAL_FAIL;
    }

    return OAL_SUCC;
}
#define HMAC_DPE_EVENT_UNEQUAL_DUMP_LOG_MAX_COUNT 30
void hmac_sync_dpe_check_event_trx_sync_is_valid(void)
{
    dpe_wlan_event_dispatch_stat_stru *event_trx_stat = dpe_wlan_event_trx_stat_get();
    hmac_device_trx_stat *hmac_dev_stat = hmac_get_device_trx_stat();
    if ((hmac_dev_stat->event_trx_stat.master_hcc_rx_event_cnt != event_trx_stat->dpe_slave_hcc_tx_event_cnt) ||
        (hmac_dev_stat->event_trx_stat.master_hcc_tx_event_cnt != event_trx_stat->dpe_slave_hcc_rx_event_cnt)) {
        hmac_dev_stat->event_trx_stat.master_slave_event_trx_unequal_cnt++;
    } else {
        hmac_dev_stat->event_trx_stat.master_slave_event_trx_unequal_cnt = 0;
    }

    if (hmac_dev_stat->event_trx_stat.master_slave_event_trx_unequal_cnt == 1) {
        oam_warning_log2(0, 0, "hmac_sync_dpe_check_event_trx_sync d2h invalid 1 master[%d] slave[%d](dpa)",
            hmac_dev_stat->event_trx_stat.master_hcc_rx_event_cnt, event_trx_stat->dpe_slave_hcc_tx_event_cnt);
        oam_warning_log2(0, 0, "hmac_sync_dpe_check_event_trx_sync h2d invalid 1 master[%d] slave[%d](dpa)",
            hmac_dev_stat->event_trx_stat.master_hcc_tx_event_cnt, event_trx_stat->dpe_slave_hcc_rx_event_cnt);
    }
    if (hmac_dev_stat->event_trx_stat.master_slave_event_trx_unequal_cnt >= HMAC_DPE_EVENT_UNEQUAL_DUMP_LOG_MAX_COUNT) {
        oam_warning_log2(0, 0, "hmac_sync_dpe_check_event_trx_sync d2h invalid 30 master[%d] slave[%d](dpa)",
            hmac_dev_stat->event_trx_stat.master_hcc_rx_event_cnt, event_trx_stat->dpe_slave_hcc_tx_event_cnt);
        oam_warning_log2(0, 0, "hmac_sync_dpe_check_event_trx_sync h2d invalid 30 master[%d] slave[%d](dpa)",
            hmac_dev_stat->event_trx_stat.master_hcc_tx_event_cnt, event_trx_stat->dpe_slave_hcc_rx_event_cnt);
        /* 累计异常超门限后, 重置统计结果 */
        hmac_dev_stat->event_trx_stat.master_hcc_rx_event_cnt = event_trx_stat->dpe_slave_hcc_tx_event_cnt;
        hmac_dev_stat->event_trx_stat.master_hcc_tx_event_cnt = event_trx_stat->dpe_slave_hcc_rx_event_cnt;
        hmac_dev_stat->event_trx_stat.master_slave_event_trx_unequal_cnt = 0;
    }
    if (hmac_dev_stat->event_trx_stat.tx_dmi_msg_ring_switch != event_trx_stat->dpe_rx_dmi_msg_ring_switch) {
        hmac_dev_stat->event_trx_stat.tx_dmi_msg_diff_th++;
    } else {
        hmac_dev_stat->event_trx_stat.tx_dmi_msg_diff_th = 0;
    }
    if (hmac_dev_stat->event_trx_stat.tx_dmi_msg_diff_th >= HMAC_DPE_EVENT_UNEQUAL_DUMP_LOG_MAX_COUNT) {
        oam_warning_log2(0, 0, "hmac_sync_dpe_check_event_trx_sync dmi msg diff host[%d] dpa[%d]",
            hmac_dev_stat->event_trx_stat.tx_dmi_msg_ring_switch, event_trx_stat->dpe_rx_dmi_msg_ring_switch);
        hmac_dev_stat->event_trx_stat.tx_dmi_msg_ring_switch = event_trx_stat->dpe_rx_dmi_msg_ring_switch;
        hmac_dev_stat->event_trx_stat.tx_dmi_msg_diff_th = 0;
    }
}

void hmac_sync_dpe_dump_event_pps_info(uint32_t dur_ms)
{
    dpe_wlan_event_dispatch_stat_stru *event_trx_stat = dpe_wlan_event_trx_stat_get();
    hmac_device_trx_stat *hmac_dev_stat = hmac_get_device_trx_stat();
    if (dur_ms != 0) {
        g_freq_lock_control.dpe_master_rx_pps =
            (event_trx_stat->dpe_master_hcc_rx_event_cnt - hmac_dev_stat->last_stat.dpe_master_rx_event) / dur_ms;
        g_freq_lock_control.dpe_master_tx_pps =
            (event_trx_stat->dpe_master_hcc_tx_event_cnt - hmac_dev_stat->last_stat.dpe_master_tx_event) / dur_ms;
        g_freq_lock_control.dpe_slave_rx_pps =
            (event_trx_stat->dpe_slave_hcc_rx_event_cnt - hmac_dev_stat->last_stat.dpe_slave_rx_event) / dur_ms;
        g_freq_lock_control.dpe_slave_tx_pps =
            (event_trx_stat->dpe_slave_hcc_tx_event_cnt - hmac_dev_stat->last_stat.dpe_slave_tx_event) / dur_ms;
    }

    hmac_dev_stat->last_stat.dpe_master_rx_event = event_trx_stat->dpe_master_hcc_rx_event_cnt;
    hmac_dev_stat->last_stat.dpe_master_tx_event = event_trx_stat->dpe_master_hcc_tx_event_cnt;
    hmac_dev_stat->last_stat.dpe_slave_rx_event = event_trx_stat->dpe_slave_hcc_rx_event_cnt;
    hmac_dev_stat->last_stat.dpe_slave_tx_event = event_trx_stat->dpe_slave_hcc_tx_event_cnt;
}

/* 功能描述: 更新device统计信息 */
void hmac_sync_dpe_update_trx_stat_info(void)
{
    int32_t ret;
    if (dpe_is_support_dpe_offload() == OAL_FALSE) {
        return;
    }

    if ((g_dpe_wlan_stat_res_ptr == NULL) || (g_wlan_stat_shared_res_ptr == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_sync_dpe_update_user_stat_info:ptr is NULL!}");
        return;
    }
    if (hmac_sync_dpe_to_update_stat_info() != OAL_SUCC) {
        return;
    }
    ret = memcpy_s(g_dpe_wlan_stat_res_ptr, sizeof(dpe_wlan_stat_res_stru),
        g_wlan_stat_shared_res_ptr, sizeof(dpe_wlan_stat_res_stru));
    if (ret != EOK) {
        oam_error_log1(0, OAM_SF_ANY, "{hmac_sync_dpe_update_trx_stat_info:ret[%d]}", ret);
    }
    hmac_sync_dpe_check_event_trx_sync_is_valid();
}

void hmac_sync_dpe_pps_tx_switch(uint32_t pps)
{
    hmac_pps_tx_switch_stru msg = { 0 };
    hmac_device_trx_stat *hmac_dev_stat = hmac_get_device_trx_stat();
    if (hmac_is_support_dpe_offload() == OAL_FALSE) {
        /* DPA不使能时host切换,DPA使能时offload切换 */
        hmac_tx_pps_switch(pps);
        return;
    }
    // 如果是dpa复位，在dpa未完成初始化时，不可以向dpa下发dmi消息。
    if (wal_dfr_is_dpa_reset() == OAL_TRUE) {
        oam_warning_log1(0, OAM_SF_ANY, "{hmac_sync_dpe_pps_tx_switch: pps [%d] dfr ing}", pps);
        return;
    }
    msg.msg_type = DMI_WIFI_MSG_PPS_TX_SWITCH;
    msg.pps = pps;
    if (conn_dmi_msg_data_send(CONN_DMI_MSG_WIFI_MSG, (uint8_t *)&msg, sizeof(hmac_pps_tx_switch_stru)) != OAL_SUCC) {
        oam_error_log3(0, OAM_SF_TX, "{hmac_sync_dpe_pps_tx_switch:: msg[%d][%d] pps:%d}",
            CONN_DMI_MSG_WIFI_MSG, msg.msg_type, pps);
        return;
    }
    hmac_dev_stat->event_trx_stat.tx_dmi_msg_ring_switch++;
}

void hmac_netdev_flags_open(oal_net_device_stru *net_device)
{
    sync_wlan_priv_info_stru dpe_netdev_priv_info = { 0 };
    if (net_device == NULL) {
        return;
    }

    oal_netdevice_flags(net_device) |= OAL_IFF_RUNNING;
    dpe_netdev_priv_info.sync_event = DPE_NETDEV_SYNC_CHANGE_FLAGS;
    dpe_netdev_priv_info.net_dev_flags = oal_netdevice_flags(net_device);
    hmac_netdev_sync_dpa(net_device, &dpe_netdev_priv_info);
}

void hmac_netdev_flags_stop(oal_net_device_stru *net_device)
{
    sync_wlan_priv_info_stru dpe_netdev_priv_info = { 0 };
    if (net_device == NULL) {
        return;
    }

    oal_netdevice_flags(net_device) &= ~OAL_IFF_RUNNING;
    dpe_netdev_priv_info.sync_event = DPE_NETDEV_SYNC_CHANGE_FLAGS;
    dpe_netdev_priv_info.net_dev_flags = oal_netdevice_flags(net_device);
    hmac_netdev_sync_dpa(net_device, &dpe_netdev_priv_info);
}

hmac_dpe_wifi_msg_buffer_stru g_dpe_wifi_msg_buffer[DMI_WIFI_MSG_BUTT];
static uint32_t hmac_sync_dpa_event_get_response(uint8_t msg_type, hmac_dpe_wifi_msg_stru *resp)
{
    if (!g_dpe_wifi_msg_buffer[msg_type].valid) {
        return OAL_FAIL;
    }

    resp->param0 = g_dpe_wifi_msg_buffer[msg_type].msg.param0;
    resp->param1 = g_dpe_wifi_msg_buffer[msg_type].msg.param1;
    resp->param2 = g_dpe_wifi_msg_buffer[msg_type].msg.param2;
    resp->param3 = g_dpe_wifi_msg_buffer[msg_type].msg.param3;
    g_dpe_wifi_msg_buffer[msg_type].valid = OAL_FALSE;

    return OAL_SUCC;
}

/* 考虑同一类型的事件处理完之前又再次触发 */
static oal_completion g_event_resp_ready[DMI_WIFI_MSG_BUTT];
void hmac_sync_dpa_event_cb(uint8_t *buf, uint8_t buf_len)
{
    hmac_dpe_wifi_msg_stru *resp = (hmac_dpe_wifi_msg_stru *)buf;

    if (!resp || resp->msg_type >= DMI_WIFI_MSG_BUTT) {
        return;
    }

    g_dpe_wifi_msg_buffer[resp->msg_type].msg.param0 = resp->param0;
    g_dpe_wifi_msg_buffer[resp->msg_type].msg.param1 = resp->param1;
    g_dpe_wifi_msg_buffer[resp->msg_type].msg.param2 = resp->param2;
    g_dpe_wifi_msg_buffer[resp->msg_type].msg.param3 = resp->param3;
    g_dpe_wifi_msg_buffer[resp->msg_type].valid = OAL_TRUE;

    oal_complete(&g_event_resp_ready[resp->msg_type]);
}

uint32_t hmac_sync_dpa_event(hmac_dpe_wifi_msg_stru *msg)
{
    int32_t ret;
    uint32_t timeout;

    if (!msg || msg->msg_type >= DMI_WIFI_MSG_BUTT) {
        return OAL_FAIL;
    }
    // 如果是dpa复位，在dpa未完成初始化时，不可以向dpa下发dmi消息。
    if (wal_dfr_is_dpa_reset() == OAL_TRUE) {
        return OAL_FAIL;
    }
    oal_init_completion(&g_event_resp_ready[msg->msg_type]);
    ret = conn_dmi_msg_send(CONN_DMI_MSG_H2D_WIFI_MSG, (uint8_t *)msg, sizeof(hmac_dpe_wifi_msg_stru), NULL, NULL);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, 0, "dmi send msg[HMAC2DPE_WIFI_MSG] fail! ret = %d", ret);
        return OAL_FAIL;
    }

    timeout = (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC);
    if (oal_wait_for_completion_timeout(&g_event_resp_ready[msg->msg_type], timeout) == 0) {
        oam_error_log1(0, 0, "hmac_sync_dpa_event:: wait dpe wifi off completion timeout, msg_type[%d]", msg->msg_type);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

uint32_t hmac_sync_dpa_event_wait_response(hmac_dpe_wifi_msg_stru *msg, hmac_dpe_wifi_msg_stru *resp)
{
    return hmac_sync_dpa_event(msg) && hmac_sync_dpa_event_get_response(msg->msg_type, resp);
}
