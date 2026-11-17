/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_smart_roam.c文件
 * 创建日期 : 2025年05月15日
 */
#ifdef _PRE_WLAN_FEATURE_AI_WIFI_ROAM
#include "oal_util.h"
#include "oam_ext_if.h"
#include "mac_ie.h"
#include "mac_device.h"
#include "mac_resource.h"
#include "hmac_resource.h"
#include "hmac_device.h"
#include "hmac_scan.h"
#include "hmac_roam_main.h"
#include "hmac_roam_connect.h"
#include "hmac_roam_alg.h"
#include "hmac_smart_roam_if.h"
#include "hmac_smart_roam_dnn_model.h"
#include "hmac_smart_roam.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_SMART_ROAM_C
OAL_STATIC smart_roam_info_stru g_smart_roam_info = {0};
OAL_STATIC smart_roam_info_stru *hmac_smart_roam_get_smart_roam_info(void)
{
    return &g_smart_roam_info;
}
uint32_t hmac_smart_roam_init_params(hmac_roam_info_stru *roam_info, mac_scan_req_stru *scan_params,
    uint8_t neighbour_flag)
{
    smart_roam_info_stru *smart_roam_info = hmac_smart_roam_get_smart_roam_info();
    hmac_vap_stru *hmac_vap = NULL;
    wlan_scan_chan_stats_ext_stru *record = NULL;
    hmac_device_stru *hmac_dev = NULL;
    if (roam_info == NULL) {
        return OAL_FAIL;
    }
    hmac_vap = roam_info->pst_hmac_vap;
    if (hmac_vap == NULL) {
        return OAL_FAIL;
    }

    hmac_dev = hmac_res_get_mac_dev(hmac_vap->st_vap_base_info.uc_device_id);
    if (hmac_dev == NULL) {
        return OAL_FAIL;
    }
    record = hmac_dev->st_scan_mgmt.st_scan_record_mgmt.ext_chan_results;
    scan_params->uc_scan_func |= (MAC_SCAN_FUNC_MEAS | MAC_SCAN_FUNC_STATS | MAC_SCAN_FUNC_SMART_ROAM);
    if (neighbour_flag == OAL_TRUE) {
        hmac_roam_neighbor_report_add_chan(scan_params, hmac_vap->st_vap_base_info.st_channel.uc_chan_number,
            hmac_vap->st_vap_base_info.st_channel.en_band);

        scan_params->uc_max_scan_count_per_channel = SMART_ROAM_SCAN_COUNT;
        scan_params->us_scan_time = SMART_ROAM_SCAN_TIME;
    }

    memset_s(record, WLAN_MAX_CHANNEL_NUM * sizeof(wlan_scan_chan_stats_ext_stru), 0,
        WLAN_MAX_CHANNEL_NUM * sizeof(wlan_scan_chan_stats_ext_stru));
    memset_s(smart_roam_info->bss_dscr_input, SMART_ROAM_DNN_MAX_BSS_DSCR_NUM * sizeof(smart_roam_dnn_input_stru), 0,
        SMART_ROAM_DNN_MAX_BSS_DSCR_NUM * sizeof(smart_roam_dnn_input_stru));
    smart_roam_info->bss_dscr_num = 0;
    roam_info->st_alg.smart_roam_enable = OAL_TRUE;
    return OAL_SUCC;
}
OAL_STATIC int32_t hmac_smart_roam_rssi_normalization(int8_t rssi)
{
    /* DNN模型输入一般归一为[0,1];但host不支持浮点数，所以将输入归一化到[0,1024]，下同
    rssi归一化处理，-128对应0 0及以上对应1024 */
    if (rssi >= 0) {
        return SMART_ROAM_DNN_MUL_SCALE;
    } else {
        return (SMART_ROAM_DNN_MUL_SCALE + rssi * SMART_ROAM_DNN_RSSI_SCALE);
    }
}
OAL_STATIC void hmac_smart_roam_fill_protocol_info(mac_bss_dscr_stru *bss_dscr, smart_roam_dnn_input_stru *input)
{
    /* 协议类型归一化处理转成onehot编码 */
    uint8_t protocol_index = SMART_ROAM_LEGACY_PROTOCOL;
    if (bss_dscr->eht_capable == OAL_TRUE || bss_dscr->en_he_capable == OAL_TRUE) {
        protocol_index = SMART_ROAM_HE_EHT_PROTOCOL;
    } else if (bss_dscr->en_vht_capable == OAL_TRUE) {
        protocol_index = SMART_ROAM_VHT_PROTOCOL;
    } else if (bss_dscr->en_ht_capable == OAL_TRUE) {
        protocol_index = SMART_ROAM_HT_PROTOCOL;
    }
    memset_s(input->protocol_one_hot_code, sizeof(input->protocol_one_hot_code), 0,
        sizeof(input->protocol_one_hot_code));
    input->protocol_one_hot_code[protocol_index] = SMART_ROAM_DNN_MUL_SCALE;
}
OAL_STATIC void hmac_smart_roam_fill_ap_info(mac_bss_dscr_stru *bss_dscr, smart_roam_dnn_input_stru *input)
{
    input->beacon_rssi = hmac_smart_roam_rssi_normalization(bss_dscr->c_rssi);
    if (bss_dscr->ap_chan_utilization == 0 && bss_dscr->sta_count == 0) { // beacon中未携带bssload ie使用信道测量利用率
        input->ap_chan_utilization = SMART_ROAM_DNN_MUL_SCALE - input->sta_pri20M_freetime_ratio;
    } else {
        input->ap_chan_utilization = (bss_dscr->ap_chan_utilization << SMART_ROAM_DNN_INPUT_SCALE) /
            SMART_ROAM_DNN_CHLOAD_SCALE;
    }
}
OAL_STATIC uint32_t hmac_smart_roam_fill_intf_info(mac_bss_dscr_stru *bss_dscr, smart_roam_dnn_input_stru *input,
    hmac_vap_stru *hmac_vap)
{
    uint8_t channel_number = bss_dscr->st_channel.uc_chan_number;
    wlan_scan_chan_stats_ext_stru *record = NULL;
    wlan_scan_chan_stats_stru *chan_results = NULL;
    uint8_t i, total_chan_numbers;
    uint32_t adjch_time, free_time;
    hmac_device_stru *hmac_dev = hmac_res_get_mac_dev(hmac_vap->st_vap_base_info.uc_device_id);
    if (hmac_dev == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_smart_roam_fill_intf_info::hmac_dev = NULL}");
        return OAL_FAIL;
    }
    record = hmac_dev->st_scan_mgmt.st_scan_record_mgmt.ext_chan_results;
    chan_results = hmac_dev->st_scan_mgmt.st_scan_record_mgmt.ast_chan_results;
    total_chan_numbers = hmac_dev->st_scan_mgmt.st_scan_record_mgmt.uc_chan_numbers;
    for (i = 0; i < total_chan_numbers; i++) {
        if (chan_results[i].uc_channel_number == channel_number) {
            // 信道测量数据异常切回传统漫游
            if (record[i].total_scan_time == 0 || record[i].free_pri20M_time > record[i].total_scan_time) {
                return OAL_FAIL;
            }
            input->sta_rx_nondir_time_ratio = (int32_t)((record[i].total_recv_nondir_time_us <<
                SMART_ROAM_DNN_INPUT_SCALE) / record[i].total_scan_time);
            input->sta_pri20M_noise_power = hmac_smart_roam_rssi_normalization(record[i].free_pri20M_noise);
            free_time = record[i].free_pri20M_time + record[i].total_tx_time +
                record[i].total_rx_direct_time + record[i].total_recv_nondir_time_us;
            adjch_time = (record[i].total_scan_time > free_time) ? (record[i].total_scan_time - free_time) : 0;
            input->sta_adjch_time_ratio = (int32_t)((adjch_time << SMART_ROAM_DNN_INPUT_SCALE) /
                record[i].total_scan_time);
            input->sta_pri20M_freetime_ratio = (int32_t)((record[i].free_pri20M_time << SMART_ROAM_DNN_INPUT_SCALE) /
                record[i].total_scan_time);
            bss_dscr->channel_index = i;
            return OAL_SUCC;
        }
        continue;
    }

    return OAL_FAIL;
}
void hmac_smart_roam_add_dnn_input(mac_bss_dscr_stru *bss_dscr, hmac_vap_stru *hmac_vap)
{
    uint32_t ret;
    smart_roam_info_stru *smart_roam_info = hmac_smart_roam_get_smart_roam_info();
    smart_roam_dnn_input_stru *input = &(smart_roam_info->bss_dscr_input[smart_roam_info->bss_dscr_num]);
    if (hmac_vap == NULL || bss_dscr == NULL) {
        return;
    }
    if (smart_roam_info->bss_dscr_num >= SMART_ROAM_DNN_MAX_BSS_DSCR_NUM) {
        (smart_roam_info->bss_dscr_num)++;
        return;
    }
    ret = hmac_smart_roam_fill_intf_info(bss_dscr, input, hmac_vap);
    if (ret != OAL_SUCC) {
        smart_roam_info->bss_dscr_num = (SMART_ROAM_DNN_MAX_BSS_DSCR_NUM + 1); // 信道测量有误，不进行AI决策
        return;
    }

    hmac_smart_roam_fill_protocol_info(bss_dscr, input);

    hmac_smart_roam_fill_ap_info(bss_dscr, input);

    input->bss_dscr = bss_dscr;

    (smart_roam_info->bss_dscr_num)++;
}
OAL_STATIC void hmac_smart_roam_print_result(mac_vap_stru *mac_vap, int8_t *score, uint32_t best_index)
{
    uint8_t i;
    smart_roam_dnn_input_stru *tmp_input = NULL;
    mac_bss_dscr_stru *bss_dscr = NULL;
    smart_roam_info_stru *smart_roam_info = hmac_smart_roam_get_smart_roam_info();
    wlan_scan_chan_stats_ext_stru *record = NULL;
    hmac_device_stru *hmac_dev = hmac_res_get_mac_dev(mac_vap->uc_device_id);
    if (hmac_dev == NULL) {
        return;
    }
    for (i = 0; i < smart_roam_info->bss_dscr_num; i++) {
        tmp_input = (smart_roam_dnn_input_stru *)&(smart_roam_info->bss_dscr_input[i]);
        bss_dscr = tmp_input->bss_dscr;
        if (bss_dscr == NULL) {
            return;
        }

        record = &(hmac_dev->st_scan_mgmt.st_scan_record_mgmt.ext_chan_results[bss_dscr->channel_index]);
        oam_warning_log4(0, OAM_SF_ROAM, "{hmac_smart_roam_print_result[%02X:XX:XX:XX:%02X:%02X]rssi[%d]}",
            bss_dscr->auc_bssid[BYTE_OFFSET_0], bss_dscr->auc_bssid[BYTE_OFFSET_4], bss_dscr->auc_bssid[BYTE_OFFSET_5],
            bss_dscr->c_rssi);
        oal_io_print("hmac_smart_roam_print_result:i[%u]ap_chan_utilization[%u]total_scan_time[%u]rx_direct_time[%u]"
            "free_time[%u]nondir_time[%u]tx_time[%u]noise_power[%d]\n", i, bss_dscr->ap_chan_utilization,
            record->total_scan_time, record->total_rx_direct_time, record->free_pri20M_time,
            record->total_recv_nondir_time_us, record->total_tx_time, record->free_pri20M_noise);
    }
    return;
}
OAL_STATIC mac_bss_dscr_stru *hmac_smart_roam_dnn_compare_inference_proc(mac_vap_stru *mac_vap, uint8_t batch_size,
    int32_t input[][SMART_ROAM_DNN_COMPARE_INPUT])
{
    uint32_t ret, i, front, back;
    int8_t score[SMART_ROAM_DNN_MAX_BSS_DSCR_NUM] = {0};
    int32_t output[SMART_ROAM_DNN_COMPARE_BATCH_SIZE] = {0};
    uint32_t best_index = 0;
    int32_t best_score = 0;

    smart_roam_info_stru *smart_roam_info = hmac_smart_roam_get_smart_roam_info();
    ret = hmac_smart_roam_dnn_process(&(input[0][0]), SMART_ROAM_DNN_COMPARE_INPUT, batch_size, output);
    if (ret != OAL_SUCC) {
        return NULL;
    }
    /* 计算每个bss的得分 */
    for (i = 0; i < batch_size; i++) {
        front = smart_roam_info->dnn_compare_bss_index[i][0];
        back = smart_roam_info->dnn_compare_bss_index[i][1];
        if (output[i] == SMART_ROAM_BSS_LOSE) {
            score[front] += -1;
            score[back] += 1;
        } else if (output[i] == SMART_ROAM_BSS_WIN) {
            score[front] += 1;
            score[back] += -1;
        }
    }
    /* 获取得分最高的bss */
    best_score = score[0];
    for (i = 1; i < smart_roam_info->bss_dscr_num; i++) {
        if (best_score < score[i]) {
            best_index = i;
            best_score = score[i];
        }
    }
    hmac_smart_roam_print_result(mac_vap, score, best_index);

    return smart_roam_info->bss_dscr_input[best_index].bss_dscr;
}
OAL_STATIC void hmac_smart_roam_adjust_5g_rssi_weight(smart_roam_dnn_input_stru *input1,
    smart_roam_dnn_input_stru *input2, uint8_t batch_index)
{
    smart_roam_info_stru *smart_roam_info = hmac_smart_roam_get_smart_roam_info();
    mac_bss_dscr_stru *bss_dscr1 = input1->bss_dscr;
    mac_bss_dscr_stru *bss_dscr2 = input2->bss_dscr;
    int8_t temp_rssi;
    smart_roam_dnn_input_stru *dnn_input = NULL;
    if (bss_dscr1 == NULL || bss_dscr2 == NULL) {
        return;
    }
    if (bss_dscr1->st_channel.en_band == bss_dscr2->st_channel.en_band) {
        return;
    }
    if (bss_dscr1->st_channel.en_band == WLAN_BAND_5G) {
        dnn_input = (smart_roam_dnn_input_stru*)&(smart_roam_info->smart_roam_dnn_compare_input[batch_index][0]);
        temp_rssi = hmac_roam_alg_adjust_5g_rssi_weight(bss_dscr1->c_rssi);
        dnn_input->beacon_rssi = hmac_smart_roam_rssi_normalization(temp_rssi);
    }
    if (bss_dscr2->st_channel.en_band == WLAN_BAND_5G) {
        dnn_input = (smart_roam_dnn_input_stru*)(&(smart_roam_info->smart_roam_dnn_compare_input[batch_index][0]) +
            SMART_ROAM_DNN_COMPARE_ONE_INPUT);
        temp_rssi = hmac_roam_alg_adjust_5g_rssi_weight(bss_dscr2->c_rssi);
        dnn_input->beacon_rssi = hmac_smart_roam_rssi_normalization(temp_rssi);
    }
    return;
}
mac_bss_dscr_stru *hmac_smart_roam_dnn_compare_inference(mac_vap_stru *mac_vap)
{
    mac_bss_dscr_stru *best_dscr = NULL;
    smart_roam_dnn_input_stru *input1 = NULL;
    smart_roam_dnn_input_stru *input2 = NULL;
    smart_roam_info_stru *smart_roam_info = hmac_smart_roam_get_smart_roam_info();
    uint8_t batch_index = 0;
    uint8_t i, j;
    if (mac_vap == NULL) {
        return NULL;
    }
    /* dnn模型输入为ap1[rssi,ap_chan_utilization...]ap2[rssi,ap_chan_utilization...]需将两个input的相关信息拼接做输入 */
    for (i = 0; i < smart_roam_info->bss_dscr_num - 1; i++) {
        input1 = &(smart_roam_info->bss_dscr_input[i]);
        for (j = i + 1; j < smart_roam_info->bss_dscr_num; j++) {
            input2 = &(smart_roam_info->bss_dscr_input[j]);
            (void)memcpy_s(&(smart_roam_info->smart_roam_dnn_compare_input[batch_index][0]),
                SMART_ROAM_DNN_COMPARE_ONE_INPUT * sizeof(int32_t),
                input1, SMART_ROAM_DNN_COMPARE_ONE_INPUT * sizeof(int32_t));
            (void)memcpy_s(&(smart_roam_info->smart_roam_dnn_compare_input[batch_index][0]) +
                SMART_ROAM_DNN_COMPARE_ONE_INPUT, SMART_ROAM_DNN_COMPARE_ONE_INPUT * sizeof(int32_t),
                input2, SMART_ROAM_DNN_COMPARE_ONE_INPUT * sizeof(int32_t));
            smart_roam_info->dnn_compare_bss_index[batch_index][0] = i;
            smart_roam_info->dnn_compare_bss_index[batch_index][1] = j;
            hmac_smart_roam_adjust_5g_rssi_weight(input1, input2, batch_index);
            batch_index++;
        }
    }
    best_dscr = hmac_smart_roam_dnn_compare_inference_proc(mac_vap,
        batch_index, smart_roam_info->smart_roam_dnn_compare_input);
    if (best_dscr != NULL && (oal_memcmp(mac_vap->auc_bssid, best_dscr->auc_bssid, OAL_MAC_ADDR_LEN) == 0)) {
        return NULL;
    } else {
        return best_dscr;
    }
}
uint8_t hmac_smart_roam_is_satisfy_dnn_judgment(hmac_roam_alg_stru *roam_alg)
{
    smart_roam_info_stru *smart_roam_info = hmac_smart_roam_get_smart_roam_info();
    if (roam_alg->smart_roam_enable != OAL_TRUE) {
        return OAL_FALSE;
    }
    if (smart_roam_info->bss_dscr_num < SMART_ROAM_DNN_MIN_BSS_DSCR_NUM ||
        smart_roam_info->bss_dscr_num > SMART_ROAM_DNN_MAX_BSS_DSCR_NUM) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}
#endif