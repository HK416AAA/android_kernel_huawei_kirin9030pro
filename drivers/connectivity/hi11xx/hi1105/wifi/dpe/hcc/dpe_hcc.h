/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_hcc_adapt.c 的头文件
 * 作    者 :
 * 创建日期 : 2012年9月18日
 */

#ifndef DPE_HCC_H
#define DPE_HCC_H

/* 1 其他头文件包含 */
#include "oam_ext_if.h"
#include "hmac_ext_if.h"
#include "oal_mem.h"
#include "frw_ext_if.h"
#include "frw_event_main.h"
#include "dpe_hcc_if.h"

OAL_STATIC OAL_INLINE uint8_t *hcc_get_frw_hdr(oal_netbuf_stru *netbuf)
{
    uint8_t *frw_hdr = oal_sbuf_cb(netbuf);
    struct hcc_header *hcc_hdr = (struct hcc_header *)frw_hdr;
    return (frw_hdr + sizeof(struct hcc_header) + hcc_hdr->pad_hdr);
}

void acpu_rx_register_hcc_action(void);
void wcpu_rx_register_hcc_action(void);

/* 声明业务层函数 -- 提供给dpe_hcc.c引用 */
void dpe_wlan_user_add(uint8_t *add_user_data, uint8_t vap_id);
void dpe_wlan_user_del(uint8_t *del_user_data);
void dpe_wlan_tid_ba_sync(uint8_t *tid_data);
uint32_t dpe_get_host_ring_state(void);
uint32_t dpe_set_tx_ring_device_base_addr(uint8_t *d2h_tx_ring_base_addr_data);
uint32_t dpe_tx_mode_switch_process(uint8_t *tx_switch_param_data);
uint32_t dpe_frw_dbac_status_notify(oal_netbuf_stru *netbuf);
#endif /* end of hmac_main */
