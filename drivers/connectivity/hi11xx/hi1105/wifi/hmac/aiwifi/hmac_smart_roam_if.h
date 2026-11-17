/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_smart_roam_if.h文件
 * 创建日期 : 2025年05月15日
 */
#ifndef HMAC_SMART_ROAM_IF_H
#define HMAC_SMART_ROAM_IF_H
#ifdef _PRE_WLAN_FEATURE_AI_WIFI_ROAM
#include "hmac_roam_connect.h"
#include "hmac_roam_main.h"
#include "hmac_roam_alg.h"
uint32_t hmac_smart_roam_init_params(hmac_roam_info_stru *roam_info, mac_scan_req_stru *scan_params,
    uint8_t neighbour_flag);
uint32_t hmac_proc_query_smart_roam_stats_event(frw_event_mem_stru *event_mem);
void hmac_smart_roam_add_dnn_input(mac_bss_dscr_stru *bss_dscr, hmac_vap_stru *hmac_vap);
mac_bss_dscr_stru *hmac_smart_roam_dnn_compare_inference(mac_vap_stru *mac_vap);
uint8_t hmac_smart_roam_is_satisfy_dnn_judgment(hmac_roam_alg_stru *roam_alg);
#endif
#endif