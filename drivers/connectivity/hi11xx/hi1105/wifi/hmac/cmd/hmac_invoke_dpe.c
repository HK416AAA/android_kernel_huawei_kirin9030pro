/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac调用dpa接口源文件
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年4月21日
 */
#include "dpe_wlan_vap.h"
#include "dpe_wlan_device.h"
#include "dpe_main.h"
#include "dpe_tx_data.h"
#include "hmac_rx.h"
#include "hmac_tx_switch.h"
#include "hmac_tx_stat.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_host_al_tx.h"
#include "hmac_config.h"
#include "hmac_invoke_dpe.h"
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hmac_pwl.h"
#endif
void hmac_forbid_access_bus(void)
{
    hal_host_forbid_access_device();
}

oal_bool_enum_uint8 hmac_is_ring_tx(mac_vap_stru *mac_vap, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl)
{
#ifdef _PRE_WLAN_FEATURE_PWL
    if (mac_vap->pwl_enable == OAL_TRUE) {
        /* 正式秘钥下来之前都在dmac做加解密 */
        if (hmac_pwl_is_ring_tx(mac_vap, netbuf) == OAL_FALSE) {
            return OAL_FALSE;
        }
    }
#endif
    return dpe_is_ring_tx(mac_vap->uc_vap_id, netbuf, tx_ctl);
}

uint8_t hmac_is_trx_busy(void)
{
    return dpe_is_trx_busy();
}

void hmac_wifi_on(void)
{
    uint8_t buf[NUM_32_BYTES] = { 0 }; // 复用接口，buf内容无实际使用。
    dpe_wifi_on_init(buf, sizeof(buf));
}

void hmac_wifi_off(void)
{
    uint8_t buf[NUM_32_BYTES] = { 0 }; // 复用接口，buf内容无实际使用。
    dpe_wifi_off_deinit(buf, sizeof(buf));
}

void hmac_device_init_info_sync(uint16_t device_id, uint16_t cfg_vap_id, uint8_t chip_id)
{
    dpe_wlan_device_init(device_id, cfg_vap_id, chip_id);
}

uint32_t hmac_config_always_tx_proc(mac_vap_stru *mac_vap, uint8_t dev_id, uint16_t len, uint8_t *param)
{
    if (mac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    return dpe_config_always_tx(dpe_wlan_vap_get(mac_vap->uc_vap_id), dev_id, len, param);
}

void hmac_altx_res_init(void)
{
    dpe_wlan_altx_res_init();
}

uint32_t hmac_always_tx_netbuf_enqueue(uint8_t hal_dev_id, oal_netbuf_stru *netbuf)
{
    return dpe_always_tx_netbuf_enqueue(hal_dev_id, netbuf);
}

dpe_wlan_device_stat_stru *hmac_wlan_device_stat_get(void)
{
    return dpe_wlan_device_stat_get();
}

dpe_wlan_vap_stat_stru *hmac_wlan_vap_stat_get(uint8_t vap_id)
{
    return dpe_wlan_vap_stat_get(vap_id);
}
dpe_wlan_user_stat_stru *hmac_wlan_user_stat_get(uint16_t user_idx)
{
    return dpe_wlan_user_stat_get(user_idx);
}

oal_net_device_stru *hmac_vap_get_net_device(uint8_t vap_id)
{
    return dpe_vap_get_net_device(vap_id);
}