/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Linux cfg80211接口
 * 作    者 :
 * 创建日期 : 2012年11月8日
 */

#include "securec.h"
#include "securectype.h"
#include "oal_kernel_file.h"

#include "mac_ie.h"
#include "hmac_vap.h"
#include "hmac_config.h"
#include "hmac_chan_mgmt.h"
#include "hmac_tx_data.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_mgmt.h"
#endif
#ifdef _PRE_WLAN_FEATURE_NBW
#include "mac_nbw_common.h"
#endif
#include "wal_linux_cfg80211.h"
#include "wal_linux_netdev_ops.h"
#include "wal_cfg_ioctl.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID              OAM_FILE_ID_WAL_LINUX_CHBA_CFG80211_C

#ifdef _PRE_WLAN_CHBA_MGMT
/*
 * 功能描述  : 解析下发参数，抛事件到hmac进行配置
 * 1.日    期  : 2021年02月06日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
int32_t wal_cfg80211_cfg_chba(oal_wiphy_stru *wiphy, oal_net_device_stru *netdev,
    mac_vap_stru *mac_vap)
{
    mac_chba_param_stru chba_param;
    wal_msg_write_stru write_msg = {0};
    int32_t err;
    if ((g_optimized_feature_switch_bitmap & BIT(CUSTOM_OPTIMIZE_CHBA)) &&
        (oal_strcmp("chba0", netdev->name) == 0)) {
        memset_s(&chba_param, sizeof(mac_chba_param_stru), 0, sizeof(mac_chba_param_stru));
        /* 配置mac地址 */
        oal_set_mac_addr(chba_param.mac_addr, (uint8_t *)oal_netdevice_mac_addr(netdev));
        chba_param.init_channel = mac_vap->st_channel;
        oam_warning_log3(0, 0, "CHBA: start ap, init channel is chan no[%d], bandwidth[%d], band[%d].",
            chba_param.init_channel.uc_chan_number, chba_param.init_channel.en_bandwidth,
            chba_param.init_channel.en_band);
        /* 抛事件到wal层进行配置 */
        wal_write_msg_hdr_init(&write_msg, WLAN_CFGID_START_CHBA, sizeof(mac_chba_param_stru));
        if (memcpy_s(write_msg.auc_value, sizeof(mac_chba_param_stru),
            &chba_param, sizeof(mac_chba_param_stru)) != EOK) {
            return -OAL_EFAIL;
        }
        err = wal_send_cfg_event(netdev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_chba_param_stru),
            (uint8_t *)&write_msg, OAL_FALSE, NULL);
        if (err != OAL_SUCC) {
            oam_warning_log1(0, OAM_SF_ANY, "{wal_cfg80211_cfg_chba::Fail to config chba vap, error[%d]}", err);
            return -OAL_EFAIL;
        }
    }
    return OAL_SUCC;
}
#endif

void wal_cfg80211_start_ap_set_chba_mode(oal_net_device_stru *netdev, mac_vap_stru *mac_vap)
{
#ifdef _PRE_WLAN_CHBA_MGMT
    if ((g_optimized_feature_switch_bitmap & BIT(CUSTOM_OPTIMIZE_CHBA)) &&
        (oal_strcmp("chba0", netdev->name) == 0)) {
        mac_vap->chba_mode = CHBA_MODE;
        (hmac_get_chba_vap())->mac_vap_id = mac_vap->uc_vap_id;
    }
#endif
}
#ifdef _PRE_WLAN_CHBA_MGMT
void wal_chba_start_ap_set_beacon_info(oal_net_device_stru *netdev, mac_beacon_param_stru *beacon_param)
{
    if ((g_optimized_feature_switch_bitmap & BIT(CUSTOM_OPTIMIZE_CHBA)) &&
        (oal_strcmp("chba0", netdev->name) == 0)) {
        if ((g_expand_feature_switch_bitmap & CUSTOM_NBW_CAP) == 0) {
            beacon_param->l_interval = MAC_CHBA_DEFALUT_PERIODS_MS;
        }
#ifdef _PRE_WLAN_FEATURE_NBW
        if ((g_expand_feature_switch_bitmap & CUSTOM_NBW_CAP) != 0) {
            beacon_param->l_interval = MAC_NBW_DEFALUT_PERIODS_MS;
        }
#endif
        beacon_param->l_dtim_period = 2; // 2: chba dtim period
        beacon_param->uc_hidden_ssid = 1; // 1: chba hidden ssid
    }
}
void wal_chba_start_ap_set_protocol(oal_net_device_stru *netdev, uint8_t *protocol_he_flag)
{
    if ((g_optimized_feature_switch_bitmap & BIT(CUSTOM_OPTIMIZE_CHBA)) &&
        (oal_strcmp("chba0", netdev->name) == 0) &&
        (g_st_mac_device_custom_cfg.st_11ax_custom_cfg.bit_11ax_aput_switch == OAL_TRUE)) {
            *protocol_he_flag = OAL_TRUE;
    }
}

/* chba0接口处理 */
int32_t wal_cfg80211_change_intf_chba0_proc(oal_net_device_stru *net_dev, enum nl80211_iftype if_type)
{
    if (oal_unlikely(net_dev == NULL || net_dev->ieee80211_ptr == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_cfg80211_change_intf_chba0_proc::net_dev or ieee80211_ptr null!}");
        return -OAL_EFAUL;
    }

    if (!(g_optimized_feature_switch_bitmap & BIT(CUSTOM_OPTIMIZE_CHBA)) || if_type != NL80211_IFTYPE_P2P_GO) {
        oam_warning_log1(0, 0, "CHBA: driver not support chba0 change type[%d].", if_type);
        return -OAL_EINVAL;
    }
    oam_warning_log0(0, 0, "CHBA: set mode to GO.");
    if (wal_setup_ap(net_dev) != OAL_SUCC) {
        return -OAL_EINVAL;
    }
    net_dev->ieee80211_ptr->iftype = if_type;
    return OAL_SUCC;
}

#define CHBA_WAIT_M2S_INFO_TIMEOUT 80 /* 等待返回结果超时时间ms */
OAL_STATIC void wal_chba_query_m2s_info_check_left_time(hmac_vap_stru *hmac_vap)
{
    signed long leftime;
    uint32_t start_time;
    uint32_t cur_time;

    start_time = (uint32_t)oal_time_get_stamp_ms();
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
        (hmac_vap->m2s_info_query_completed_flag == OAL_TRUE),
        (uint32_t)oal_msecs_to_jiffies(CHBA_WAIT_M2S_INFO_TIMEOUT));
    cur_time = (uint32_t)oal_time_get_stamp_ms();
    if (leftime <= 0) {
        /* leftime为0超时还没有结果上来, 继续走connect流程 */
        oam_error_log3(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY,
            "{wal_cfg80211_connect_chba_query_m2s_info::query m2s_info left_time[%d], start_tsf[%u], cur_tsf[%u]}",
            leftime, start_time, cur_time);
    } else {
        oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY,
            "{wal_cfg80211_connect_chba_query_m2s_info::query m2s_info cost[%u]ms}",
            oal_time_get_runtime(start_time, cur_time));
    }
}

void wal_cfg80211_connect_chba_query_m2s_info(oal_net_device_stru *net_device, hmac_conn_param_stru *mac_conn_param)
{
    int32_t ret;
    mac_vap_stru *mac_vap = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    uint8_t conn_flag;
    mac_device_stru *mac_dev = NULL;
    mac_vap_stru *another_up_vap = NULL;

    wal_msg_write_stru write_msg;

    mac_vap = oal_net_dev_priv(net_device);
    if (mac_vap == NULL) {
        oam_warning_log0(0, OAM_SF_ANY,
            "{wal_cfg80211_connect_chba_query_m2s_info:: mac_vap of net_device is NULL!}");
        return;
    }

    /* 获取hmac vap */
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_SCAN,
            "{wal_cfg80211_connect_chba_query_m2s_info::hmac_vap is null, vap_id[%d]!}", mac_vap->uc_vap_id);
        return;
    }

    mac_dev = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_dev == NULL) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{wal_cfg80211_connect_chba_query_m2s_info::dev is null.}");
        return;
    }

    /* chba极速连接才需要等待更新m2s info */
    if (mac_vap->chba_mode != CHBA_MODE) {
        return;
    }
    conn_flag = hmac_chba_get_connect_initiator_conn_flag(mac_conn_param->flags);
    if (hmac_chba_check_fast_connect_flag(conn_flag) == OAL_FALSE) {
        return;
    }

    /* 没有其他up vap，不用查询m2s info */
    another_up_vap = mac_device_find_another_up_vap(mac_dev, mac_vap->uc_vap_id);
    if (another_up_vap == NULL) {
        return;
    }

    /* 先清标记 */
    hmac_vap->m2s_info_query_completed_flag = OAL_FALSE;

    /* 抛事件到wal层处理 */
    wal_write_msg_hdr_init(&write_msg, WLAN_CFGID_GET_VAP_M2S_INFO, sizeof(uint8_t));
    ret = wal_send_cfg_event(net_device, WAL_MSG_TYPE_WRITE,
        WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(uint8_t), (uint8_t *)&write_msg, OAL_FALSE, NULL);
    if (ret != OAL_SUCC) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CFG, "{wal_cfg80211_connect_chba_query_m2s_info::fail[%d]}", ret);
        return;
    }

    /* 等待device 返回结果 */
    wal_chba_query_m2s_info_check_left_time(hmac_vap);
}
#endif
