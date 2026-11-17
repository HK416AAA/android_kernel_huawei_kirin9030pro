/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * 功能说明 : l5 tas天线切换host侧功能
 * 作    者 : y30077478
 * 创建日期 : 2025年12月10日
 */
#include "hmac_l5_tas.h"
#include "wal_linux_ioctl.h"
#include "host_hal_tas.h"
#include "wlan_cfg_id_1.h"
#include "hmac_config.h"
#include "wal_linux_atcmdsrv.h"
uint8_t g_l5_tas_switch_flag = OAL_FALSE; // 等待device消息上报的标志位
uint8_t g_l5_tas_switch_status = OAL_FALSE; // L5 TAS开关状态位
 
oal_bool_enum_uint8 *hmac_get_l5_tas_switch_flag(void)
{
    /* 每次获取等待上报标志位时，需清空其状态 */
    g_l5_tas_switch_flag = OAL_FALSE;
    return &g_l5_tas_switch_flag;
}

void hmac_set_l5_tas_switch_status(uint8_t status)
{
    g_l5_tas_switch_status = status;
}

uint32_t hmac_l5_tas_ant_switch_notify(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    hmac_vap_stru *hmac_vap;
    g_l5_tas_switch_flag = OAL_TRUE;
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_l5_tas_ant_switch_notify::get_hmac_vap failed!}");
        return OAL_FAIL;
    }
    oal_wait_queue_wake_up(&(hmac_vap->query_wait_q));
    return OAL_SUCC;
}
 
uint32_t hmac_l5_tas_ant_switch_config(uint8_t l5_tas_ant_switch_status)
{
    hal_wifi_l5_tas_set(l5_tas_ant_switch_status);
    hmac_set_l5_tas_switch_status(l5_tas_ant_switch_status);
    return OAL_SUCC;
}
 
uint32_t hmac_l5_tas_ant_switch(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    uint32_t ret;
 
    if (oal_any_null_ptr2(mac_vap, param)) {
        return OAL_ERR_CODE_PTR_NULL;
    }
 
    /***************************************************************************
        抛事件到DMAC层, 同步DMAC数据
    ***************************************************************************/
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_L5_TAS_ANT_SWITCH_CFG, len, param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CFG,
                         "hmac_config_l5_tas_ant_switch::hmac_config_send_event failed, error no[%d]!", ret);
        return ret;
    }
    return OAL_SUCC;
}

uint32_t hmac_l5_tas_wifi_open_protect(void)
{
    if (g_l5_tas_switch_status == OAL_TRUE) {
        hmac_l5_tas_ant_switch_config(OAL_FALSE);
        g_l5_tas_switch_status = OAL_FALSE;
    }
    return OAL_SUCC;
}

uint32_t hmac_l5_tas_reset_default_cfg(oal_net_device_stru *net_dev)
{
    if (g_l5_tas_switch_status == OAL_TRUE) {
        wal_ioctl_l5_tas_ant_switch_process(net_dev, OAL_FALSE);
    }
    return OAL_SUCC;
}

uint32_t hmac_l5_tas_wifi_status_check(void)
{
    mac_chip_stru *mac_chip = NULL;
    mac_vap_stru *mac_vap = NULL;
    mac_device_stru *mac_device = NULL;
    uint8_t dev_idx;
    mac_chip = hmac_res_get_mac_chip(0);
    if (mac_chip->uc_assoc_user_cnt > 0) {
        return OAL_FAIL;
    }
    for (dev_idx = 0; dev_idx < mac_chip->uc_device_nums; dev_idx++) {
        mac_device = mac_res_get_dev(mac_chip->auc_device_id[dev_idx]);
        if (mac_device == NULL) {
            continue;
        }
        if (mac_device_find_up_ap(mac_device, &mac_vap) == OAL_SUCC) {
            return OAL_FAIL;
        }
    }
    return OAL_SUCC;
}

uint8_t hmac_l5_tas_ant_switch_status_check(uint8_t status)
{
    if (status == g_l5_tas_switch_status) {
        return OAL_TRUE;
    }
    return OAL_FALSE;
}
 
int32_t hmac_l5_tas_wait_dmac_notify(mac_vap_stru *mac_vap, hmac_vap_stru *hmac_vap)
{
    int32_t left_time;
    oal_bool_enum_uint8 *l5_tas_switch_flag = NULL;
    l5_tas_switch_flag = hmac_get_l5_tas_switch_flag();
    /* 阻塞等待dmac上报 */
    left_time = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
        (uint32_t)((*l5_tas_switch_flag) == OAL_TRUE), WAL_ATCMDSRB_NORM_TIME);
    if (left_time <= 0) {
        /* 超时还没有上报扫描结束 */
        oam_error_log2(mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
            "hmac_l5_tas_wait_dmac_notify:wait for %ld ms timeout/error, leftime %ld ms!",
            ((WAL_ATCMDSRB_NORM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ), left_time);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}