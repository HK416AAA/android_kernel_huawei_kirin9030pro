/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_smart_roam.h文件
 * 创建日期 : 2025年05月15日
 */
#ifndef HMAC_SMART_ROAM_H
#define HMAC_SMART_ROAM_H
#ifdef _PRE_WLAN_FEATURE_AI_WIFI_ROAM
#include "hmac_roam_connect.h"
#include "hmac_roam_main.h"
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hd_pwl_common.h"
#endif
#define SMART_ROAM_DNN_MIN_BSS_DSCR_NUM 2
#define SMART_ROAM_DNN_MAX_BSS_DSCR_NUM 10
#define SMART_ROAM_DNN_COMPARE_BATCH_SIZE 48 // 与SMART_ROAM_DNN_MAX_BSS_DSCR_NUM需同时修改
#define SMART_ROAM_DNN_COMPARE_ONE_INPUT 6
#define SMART_ROAM_DNN_COMPARE_INPUT (SMART_ROAM_DNN_COMPARE_ONE_INPUT * 2)
#define SMART_ROAM_SCAN_COUNT 2
#define SMART_ROAM_SCAN_TIME 40
#define SMART_ROAM_DNN_MUL_SCALE 1024
#define SMART_ROAM_DNN_RSSI_SCALE 8
#define SMART_ROAM_DNN_INPUT_SCALE 10U
#define SMART_ROAM_DNN_CHLOAD_SCALE 255
typedef enum {
    SMART_ROAM_LEGACY_PROTOCOL = 0,
    SMART_ROAM_HT_PROTOCOL,
    SMART_ROAM_VHT_PROTOCOL,
    SMART_ROAM_HE_EHT_PROTOCOL,
    SMART_ROAM_PROTOCOL_BUTT,
} smart_roam_protocol_enum;
typedef enum {
    SMART_ROAM_BSS_EQUAL = 0,
    SMART_ROAM_BSS_LOSE,
    SMART_ROAM_BSS_WIN,
} smart_roam_bss_compare_result_enum;
typedef struct {
    int32_t beacon_rssi;
    int32_t ap_chan_utilization;
    int32_t sta_pri20M_freetime_ratio;
    int32_t sta_pri20M_noise_power;
    int32_t sta_rx_nondir_time_ratio;
    int32_t sta_adjch_time_ratio;
    int32_t protocol_one_hot_code[SMART_ROAM_PROTOCOL_BUTT];
    mac_bss_dscr_stru *bss_dscr;
} smart_roam_dnn_input_stru;
typedef struct {
    uint32_t bss_dscr_num;
    smart_roam_dnn_input_stru bss_dscr_input[SMART_ROAM_DNN_MAX_BSS_DSCR_NUM];
    int32_t smart_roam_dnn_compare_input[SMART_ROAM_DNN_COMPARE_BATCH_SIZE][SMART_ROAM_DNN_COMPARE_INPUT];
    uint32_t dnn_compare_bss_index[SMART_ROAM_DNN_COMPARE_BATCH_SIZE][2]; // 2个bss为一组作比较
} smart_roam_info_stru;
#endif
#endif