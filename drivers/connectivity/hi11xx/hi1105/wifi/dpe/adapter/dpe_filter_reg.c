/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe - gso - filter 数据流转接口
 * 作    者 : xianglei
 * 创建日期 : 2025年4月27日
 */

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_filter_reg.h"
#include "dpe_netdev_sync.h"
#include "dpe_netdev.h"
#include "dpe_wlan_stat.h"
#include "hmac_rx.h"
#include "mac_data.h"
#include "dpe_tx_data.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_FILTER_REG_C

void dpe_sms_filter_output_register(void)
{
    struct dpa_sms_filter_cb_s cb = { 0 };
    int32_t ret = 0;

    cb.filter_output = dpe_wlan_xmit_from_modem;
    ret = dpa_sms_filter_register(DPA_SMS_NIC_WLAN, &cb);
    if (unlikely(ret != OAL_SUCC)) {
        oam_error_log1(0, OAM_SF_DPA, "{dpa_sms_filter_register returns fail %x}", ret);
    }
}

void dpe_wlan_tx_gso_register(void)
{
    int32_t ret = 0;
    if (dpe_is_support_tx_gso_list() == OAL_TRUE) {
        ret = bsp_sms_register_tx_list_cb(DPA_SMS_NIC_WLAN, dpe_wlan_xmit_list_from_acpu);
        if (unlikely(ret != OAL_SUCC)) {
            oam_error_log1(0, OAM_SF_DPA, "{bsp_sms_register_tx_list_cb returns fail %x}", ret);
        }
    } else {
        ret = bsp_sms_register_tx_cb(DPA_SMS_NIC_WLAN, dpe_wlan_xmit_from_acpu);
        if (unlikely(ret != OAL_SUCC)) {
            oam_error_log1(0, OAM_SF_DPA, "{bsp_sms_register_tx_cb returns fail %x}", ret);
        }
    }
}
void dpe_wlan_tx_data_src_register(void)
{
    /* tx 数据包来源注册：1.WIFI SME->GSO->dpe 2.Modem->filter->dpe */
    dpe_wlan_tx_gso_register();
    dpe_sms_filter_output_register();
}
#endif