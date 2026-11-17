/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_rx_filter.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2014年7月14日
 */

#ifndef HMAC_RX_FILTER_H
#define HMAC_RX_FILTER_H

/* 1 其他头文件包含 */
#include "oal_types.h"
#include "mac_vap.h"
#include "mac_device.h"
#include "mac_data.h"
#include "hmac_rx.h"
#include "hmac_vap.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_FILTER_H
/* 2 宏定义 */
/* 3 枚举定义 */
/* 4 全局变量声明 */
/* 5 消息头定义 */
/* 6 消息定义 */
/* 7 STRUCT定义 */
/* 8 UNION定义 */
/* 9 OTHERS定义 */
/* 10 函数声明 */
oal_bool_enum_uint8 hmac_find_is_sta_up(mac_device_stru *pst_mac_device);

uint32_t hmac_calc_up_ap_num(mac_device_stru *pst_mac_device);
uint32_t hmac_find_up_vap(mac_device_stru *pst_mac_device, mac_vap_stru **ppst_mac_vap);
hmac_rx_frame_ctrl_enum hmac_host_rx_filter_encrypt(hmac_vap_stru *vap, uint16_t user_idx,
    mac_rx_ctl_stru *rx_ctl, oal_netbuf_stru *netbuf);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hmac_rx_filter.h */
