/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * 功能说明 : chba长休眠相关文件
 * 作    者 : y30038709
 * 创建日期 : 2025年5月21日
 */
#include "hmac_chba_longsleep.h"
#include "hmac_config.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_CHBA_LONGSLEEP_C

#ifdef _PRE_WLAN_CHBA_MGMT
OAL_STATIC uint8_t hmac_chba_get_longsleep_period_cnt(uint8_t longsleep_type)
{
    uint8_t period_cnt = 0;
    switch (longsleep_type) {
        case CHBA_DEEP_SLEEP_DEFAULT:
            period_cnt = 1;
            break;
        case CHBA_DEEP_SLEEP_LEVEL1:
            period_cnt = 2; /* 1个chba调度周期时长, 即2 * 256ms */
            break;
        case CHBA_DEEP_SLEEP_LEVEL2:
            period_cnt = 4; /* 2个chba调度周期时长, 即4 * 256ms */
            break;
        case CHBA_DEEP_SLEEP_LEVEL3:
            period_cnt = 8; /* 4个chba调度周期时长, 即8 * 256ms */
            break;
        default:
            oam_error_log1(0, OAM_SF_CFG, "{hmac_chba_get_longsleep_period_cnt:invalid type[%d]}", longsleep_type);
            break;
    }
    return period_cnt;
}

uint32_t hmac_chba_set_longsleep_cfg(mac_vap_stru *mac_vap, uint16_t len, uint8_t *params)
{
    uint32_t ret;
    uint8_t period_cnt;
    hmac_user_stru *hmac_user = NULL;
    wlan_chba_set_virtual_connect_cfg_stru *virtual_connect_cfg = NULL;
    mac_chba_longsleep_cfg_stru longsleep_cfg = { 0 };

    if (mac_is_chba_mode(mac_vap) == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_chba_set_longsleep_cfg:not chba vap}");
        return OAL_FAIL;
    }
    virtual_connect_cfg = (wlan_chba_set_virtual_connect_cfg_stru *)params;
    if (virtual_connect_cfg->connect_type > CHBA_VIRTUAL_CONNECT_TYPE) {
        return OAL_FAIL;
    }
    period_cnt = hmac_chba_get_longsleep_period_cnt(virtual_connect_cfg->longsleep_type);
    if (period_cnt == 0) {
        return OAL_FAIL;
    }
    hmac_user = mac_vap_get_hmac_user_by_addr(mac_vap, virtual_connect_cfg->user_mac_addr, WLAN_MAC_ADDR_LEN);
    if (hmac_user == NULL) {
        oam_warning_log3(mac_vap->uc_vap_id, OAM_SF_ANY,
            "{hmac_chba_set_longsleep_cfg:%02x:xx:xx:xx:%02x:%02x is not my user!}",
            virtual_connect_cfg->user_mac_addr[MAC_ADDR_0], virtual_connect_cfg->user_mac_addr[MAC_ADDR_4],
            virtual_connect_cfg->user_mac_addr[MAC_ADDR_5]);
        return OAL_FAIL;
    }
    longsleep_cfg.is_longsleep = (virtual_connect_cfg->connect_type == CHBA_VIRTUAL_CONNECT_TYPE);
    longsleep_cfg.is_negotiated_flag = virtual_connect_cfg->is_negotiated_flag;
    longsleep_cfg.user_idx = hmac_user->st_user_base_info.us_assoc_id;
    longsleep_cfg.period_cnt = period_cnt;
    oam_warning_log4(mac_vap->uc_vap_id, OAM_SF_CFG,
        "{hmac_chba_set_longsleep_cfg:update use[%d], is_longsleep[%d], cnt[%d], is_negotiated_flag[%d]}",
        hmac_user->st_user_base_info.us_assoc_id, longsleep_cfg.is_longsleep,
        longsleep_cfg.period_cnt, longsleep_cfg.is_negotiated_flag);
    /***************************************************************************
        抛事件到DMAC层处理
    ***************************************************************************/
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_CHBA_SET_LONGSLEEP_CFG, sizeof(longsleep_cfg),
        (uint8_t *)&longsleep_cfg);
    if (ret != OAL_SUCC) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_chba_set_longsleep_cfg:send fail[%d]}", ret);
    }
    return OAL_SUCC;
}

uint32_t hmac_chba_longsleep_update_report(mac_vap_stru *mac_vap, uint8_t len, uint8_t *params)
{
    oal_bool_enum_uint8 is_fix;
    uint8_t expect_bitmap_level;
    hmac_chba_user_stru *chba_user_info = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    mac_chba_longsleep_cfg_stru *longsleep_cfg = (mac_chba_longsleep_cfg_stru *)params;
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    mac_longsleep_finish_report_stru longsleep_finish_info = { 0 };
#endif
    hmac_user_stru *hmac_user = mac_res_get_hmac_user(longsleep_cfg->user_idx);
    if (hmac_user == NULL) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CFG,
            "{hmac_chba_longsleep_update_report:find user[%d] fail!}", longsleep_cfg->user_idx);
        return OAL_SUCC;
    }

    /* 进入长休眠状态下, 固定user bitmap为保活; 退出长休眠, 先将user bitmap配置为全醒, 再根据流量模型自动调整 */
    chba_user_info = &(hmac_user->chba_user);
    is_fix = (longsleep_cfg->is_longsleep == OAL_TRUE);
    expect_bitmap_level = ((is_fix == OAL_TRUE) ? CHBA_BITMAP_KEEP_ALIVE_LEVEL : CHBA_BITMAP_ALL_AWAKE_LEVEL);
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    hmac_chba_update_fix_user_bitmap_cfg(hmac_vap, hmac_user,
        CHBA_LONGSLEEP_FIX_USER_BITMAP_TYPE, expect_bitmap_level, is_fix);

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    /* 最新长休眠状态通知上层 */
    longsleep_finish_info.report_type = HMAC_CHBA_VIRTUAL_CONNECT_FINISH_REPORT;
    longsleep_finish_info.connect_type =
        ((longsleep_cfg->is_longsleep == OAL_TRUE) ? CHBA_VIRTUAL_CONNECT_TYPE : CHBA_REAL_CONNECT_TYPE);
    oal_set_mac_addr(longsleep_finish_info.user_mac_addr, hmac_user->st_user_base_info.auc_user_mac_addr);
    oal_cfg80211_chba_report((uint8_t *)(&longsleep_finish_info), sizeof(mac_longsleep_finish_report_stru));
#endif
    oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_chba_longsleep_update_report:user[%d] is_longsleep[%d]!}",
        longsleep_cfg->user_idx, longsleep_cfg->is_longsleep);
    return OAL_SUCC;
}
#endif
