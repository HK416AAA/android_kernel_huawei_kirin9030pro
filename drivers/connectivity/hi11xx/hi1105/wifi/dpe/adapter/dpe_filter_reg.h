/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe - gso - filter 数据流转接口
 * 作    者 : xianglei
 * 创建日期 : 2025年4月27日
 */
#ifndef DPE_SMS_FILTER_H
#define DPE_SMS_FILTER_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "oal_net.h"
#include "oal_util.h"
#include "oal_util_wifi.h"
#include "oal_net_wifi.h"
#include "bsp_sms.h"
#include "mac_cb_rx.h"
#include "dpe_dpa_intf.h"
#include "dpe_sbuf.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_SMS_FILTER_H

oal_netbuf_stru *dpe_wlan_rx_sms_filter_input(oal_net_device_stru *netdev, oal_netbuf_head_stru *netbuf_list);
void dpe_wlan_tx_data_src_register(void);
void dpe_wlan_xmit_from_modem(oal_netbuf_stru *netbuf);
void dpe_wlan_xmit_from_acpu(struct sms_tx_bd_desc *desc);
void dpe_wlan_xmit_list_from_acpu(struct sms_tx_bd_desc *gso_desc, uint32_t cnt);
void dpe_wlan_rx_filter_input_is_from_dpa(oal_net_device_stru *netdev,
    oal_netbuf_head_stru *netbuf_list, mac_rx_ctl_stru *rx_ctrl);
#endif
#endif