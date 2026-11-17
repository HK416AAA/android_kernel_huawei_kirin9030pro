/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : 帧过滤处理文件
 * 作    者 : wifi
 * 创建日期 : 2014年7月14日
 */

/* 1 头文件包含 */
#include "wlan_types.h"
#include "mac_device.h"
#include "mac_resource.h"

#include "hmac_rx_filter.h"
#include "hmac_device.h"
#include "hmac_resource.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_FILTER_C

/* 2 全局变量定义 */
/* 3 函数实现 */
/*
 * 函 数 名  : hmac_find_is_sta_up
 * 功能描述  : 查找是否有已经UP的STA
 * 1.日    期  : 2015年8月31日
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_find_is_sta_up(mac_device_stru *pst_mac_device)
{
    mac_vap_stru *pst_vap = NULL;
    uint8_t uc_vap_idx;

    for (uc_vap_idx = 0; uc_vap_idx < pst_mac_device->uc_vap_num; uc_vap_idx++) {
        pst_vap = (mac_vap_stru *)mac_res_get_mac_vap(pst_mac_device->auc_vap_id[uc_vap_idx]);
        if (pst_vap == NULL) {
            oam_error_log1(0, OAM_SF_SCAN, "{hmac_find_is_sta_up::pst_mac_vap null,vap_idx=%d.}",
                           pst_mac_device->auc_vap_id[uc_vap_idx]);
            continue;
        }

        if ((pst_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) && (pst_vap->en_vap_state == MAC_VAP_STATE_UP)) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE;
}

/*
 * 函 数 名  : hmac_calc_up_ap_num
 * 功能描述  : 计算不处于inti状态的VAP个数
 * 1.日    期  : 2014年7月14日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_calc_up_ap_num(mac_device_stru *pst_mac_device)
{
    mac_vap_stru *pst_vap = NULL;
    uint8_t uc_vap_idx;
    uint8_t up_ap_num = 0;

    for (uc_vap_idx = 0; uc_vap_idx < pst_mac_device->uc_vap_num; uc_vap_idx++) {
        pst_vap = (mac_vap_stru *)mac_res_get_mac_vap(pst_mac_device->auc_vap_id[uc_vap_idx]);
        if (pst_vap == NULL) {
            oam_error_log1(0, OAM_SF_SCAN, "{hmac_calc_up_ap_num::pst_mac_vap null,vap_idx=%d.}",
                           pst_mac_device->auc_vap_id[uc_vap_idx]);
            continue;
        }

        if ((pst_vap->en_vap_state != MAC_VAP_STATE_INIT) && (pst_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP)) {
            up_ap_num++;
        } else if ((pst_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) && (pst_vap->en_vap_state == MAC_VAP_STATE_UP)) {
            up_ap_num++;
        }
    }

    return up_ap_num;
}

/*
 * 函 数 名  : hmac_find_up_vap
 * 功能描述  : 找到up vap (优先级:AP > STA)
 * 1.日    期  : 2015年4月15日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_find_up_vap(mac_device_stru *pst_mac_device, mac_vap_stru **ppst_mac_vap)
{
    uint32_t ret;
    mac_vap_stru *pst_vap_up = NULL; /* 处在UP状态的VAP */

    /* find up VAP */
    ret = mac_device_find_up_vap(pst_mac_device, &pst_vap_up);
    if ((ret == OAL_SUCC) && (pst_vap_up != NULL)) {
        *ppst_mac_vap = pst_vap_up;
        /* find up AP */
        ret = mac_device_find_up_ap(pst_mac_device, &pst_vap_up);
        if ((ret == OAL_SUCC) && (pst_vap_up != NULL)) {
            *ppst_mac_vap = pst_vap_up;
        }

        return OAL_SUCC;
    } else {
        *ppst_mac_vap = NULL;
        return OAL_FAIL;
    }
}

OAL_STATIC uint8_t hmac_rx_netbuf_filter_need_no_encrypt_drop(hmac_vap_stru *vap, mac_rx_ctl_stru *rx_ctl)
{
    /* null帧、QOS null帧、eapol帧、WAI帧、支持高速组播vap收到组播帧 无需过滤 */
    uint8_t uc_data_type = rx_ctl->bit_data_type;
    if (uc_data_type == MAC_DATA_EAPOL || uc_data_type == MAC_DATA_WAPI) {
        return OAL_FALSE;
    }
    if (vap->st_vap_base_info.bit_support_mcast_ampdu == OAL_TRUE && rx_ctl->bit_mcast_bcast == OAL_TRUE) {
        return OAL_FALSE;
    }
    return OAL_TRUE;
}

/*
 * 功能描述  : 用户加密，接收到的数据帧不加密，则过滤
 * 1.日    期  : 2020.12.28
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
hmac_rx_frame_ctrl_enum hmac_host_rx_filter_encrypt(hmac_vap_stru *vap, uint16_t user_idx,
    mac_rx_ctl_stru *rx_ctl, oal_netbuf_stru *netbuf)
{
    wlan_ciper_protocol_type_enum_uint8 user_cipher_type;
    hmac_user_stru *hmac_user = mac_res_get_hmac_user(user_idx);
    if (hmac_user == NULL) {
        return HMAC_RX_FRAME_CTRL_GOON;
    }

    hmac_stat_user_rx_netbuf(hmac_user, netbuf);
    user_cipher_type = hmac_user->st_user_base_info.st_key_info.en_cipher_type;
    if (user_cipher_type == WLAN_80211_CIPHER_SUITE_WAPI && g_wlan_spec_cfg->feature_hw_wapi == OAL_FALSE) {
        /* 软件WAPI 加解密，rx_ctrl加密类型未填写，不过滤 */
        return HMAC_RX_FRAME_CTRL_GOON;
    }
    /* 加密场景接收到非加密的数据帧，则过滤； */
    if ((user_cipher_type != WLAN_80211_CIPHER_SUITE_NO_ENCRYP) &&
        (rx_ctl->bit_cipher_type == WLAN_80211_CIPHER_SUITE_NO_ENCRYP) &&
        (hmac_rx_netbuf_filter_need_no_encrypt_drop(vap, rx_ctl) == OAL_TRUE)) {
        oam_warning_log1(vap->hal_vap_id, OAM_SF_DPA, "{hmac_host_rx_filter_encrypt::plaintext drop! data type[%d]}",
            rx_ctl->bit_data_type);
        return HMAC_RX_FRAME_CTRL_DROP;
    }
    return HMAC_RX_FRAME_CTRL_GOON;
}
