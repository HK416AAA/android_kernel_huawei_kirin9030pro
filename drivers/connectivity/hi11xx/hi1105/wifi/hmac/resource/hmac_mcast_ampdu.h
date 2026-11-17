/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : hmac_tx_msdu_dscr.c 的头文件
 * 作者       : wifi
 * 创建日期   : 2020年02月12日
 */

#ifndef HMAC_MCAST_AMPDU_H
#define HMAC_MCAST_AMPDU_H

#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
/* 1 其他头文件包含 */
#include "hmac_user.h"
#include "hmac_vap.h"
#include "hmac_rx_data.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

void hmac_mcast_ampdu_user_init(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    uint8_t *lut_idx, uint8_t *ml_lut_idx);
void hmac_add_multi_user_mcast_ampdu_user_init(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    mac_cfg_add_vap_param_stru *pst_param);
void hmac_del_multi_user_mcast_ampdu_user_deinit(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user);
hmac_rx_frame_ctrl_enum hmac_mcast_ampdu_rx_proc(uint8_t vap_idx, oal_netbuf_stru *netbuf);
void hmac_mcast_ampdu_stats_stru_init(hmac_vap_stru *hmac_vap);
void hmac_tx_classify_mcast_ampdu_tidno(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    uint8_t *tidno, mac_tx_ctl_stru *tx_ctl);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
#endif
