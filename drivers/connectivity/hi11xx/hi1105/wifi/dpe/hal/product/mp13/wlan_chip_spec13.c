/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * 功能说明 : WIFI 芯片差异接口文件
 * 作    者 : wifi
 * 创建日期 : 2025年4月22日
 */
#include "dpe_wlan_resource.h"
#include "wlan_mib_ht_vht_he.h"
#include "wlan_spec_host_if.h"

#define WLAN_ASSOC_USER_MAX_NUM_MP15 10 /* mp15关联用户的最大个数 10 */
#define WLAN_ASSOC_USER_MAX_NUM_MP13 10 /* mp13关联用户的最大个数 10 */
const oal_wlan_cfg_stru g_wlan_spec_cfg_mp13 = {
    .feature_m2s_modem_is_open = OAL_FALSE,
    .feature_priv_closed_is_open = OAL_TRUE,
    .feature_hiex_is_open = OAL_FALSE,
    .rx_listen_ps_is_open = OAL_FALSE,
    .feature_11ax_is_open = OAL_FALSE,
    .feature_twt_is_open = OAL_FALSE,
    .feature_11ax_er_su_dcm_is_open = OAL_FALSE,
    .feature_11ax_uora_is_supported = OAL_FALSE,
    .feature_ftm_is_open = OAL_FALSE,
    .feature_psm_dfx_ext_is_open = OAL_TRUE,
    .feature_wow_opt_is_open  = OAL_FALSE,
    .feature_dual_wlan_is_supported = OAL_FALSE,
    .feature_ht_self_cure_is_open = OAL_TRUE,
    .feature_slave_ax_is_support = OAL_FALSE,
    .longer_than_16_he_sigb_support = OAL_FALSE,
    .feature_hw_wapi = OAL_FALSE,
    .full_bandwidth_ul_mu_mimo = OAL_FALSE,
    .feature_11be_is_open = OAL_FALSE,
    .feature_ml_is_supported = OAL_FALSE,
    .p2p_device_gc_use_one_vap = OAL_TRUE,
    .max_sta_num = 3,
    .max_p2p_group_num = 1,
    .p2p_go_max_user_num = WLAN_P2P_GO_ASSOC_USER_MAX_NUM_MP13,
    .max_asoc_user = WLAN_ASSOC_USER_MAX_NUM_MP13,
    .max_active_user = WLAN_ASSOC_USER_MAX_NUM_MP13,
    .max_user_limit = WLAN_ASSOC_USER_MAX_NUM_MP13 + WLAN_MULTI_USER_MAX_NUM_LIMIT_MP13,
    .invalid_user_id = WLAN_ASSOC_USER_MAX_NUM_MP13 + WLAN_MULTI_USER_MAX_NUM_LIMIT_MP13,
    .max_tx_ba = WLAN_MAX_TX_BA_MP13,
    .max_rx_ba = WLAN_MAX_RX_BA_MP13,
    .other_bss_id = WLAN_HAL_OHTER_BSS_ID_MP13,
    .max_tx_ampdu_num = WLAN_AMPDU_TX_MAX_NUM_MP13,
    .max_rf_num = 2,
    .max_slave_rf_num = 1,          /* 辅路通道总数  */
    .max_slave_scan_rf_num = 1,     /* 并发扫描时用到的辅路通道数目 */
    .slave_scan_rf_start_idx = 1,   /* 并发扫描时用到的辅路起始通道号 */
    .max_5g_bw = WLAN_BANDWIDTH_160,
    .feature_txq_ns_support = OAL_FALSE,
    .feature_txbf_mib_study = OAL_TRUE,
    .bfer_sounding_dimensions = 1, /* 发送最多支持单流 */
    .bfee_ntx_supports = 4,    /* mp13最多支持 4*2 MU Sounding */
    .vht_max_mpdu_lenth = WLAN_MIB_VHT_MPDU_7991, /* VHT协议mp15最大mpdu_len */
    .pcie_speed = 0, /* 不使用 */
    .trigger_su_beamforming_feedback = OAL_FALSE,
    .trigger_mu_partialbw_feedback = OAL_FALSE,
    .rx_stbc_160 = OAL_FALSE,
    .num_different_channels = 2,
    .max_work_vap_num = 2,
    .rx_checksum_hw_enable = OAL_FALSE,
    .wur_support_5g = OAL_FALSE,
    .wide_bw_support = OAL_FALSE,
    .emlsr_str_link = OAL_FALSE,
    .tx_ba_info = OAL_FALSE,
    .multi_tid_aggr_tx_support = OAL_FALSE,
    .vap_support_max_num_limit = WLAN_VAP_SUPPORT_MAX_NUM_LIMIT_MP13,
    .hal_max_vap_num = HAL_MAX_VAP_NUM_MP13,
    .need_check_netbuf_pre_num = OAL_TRUE,
    .feature_same_chan_remain_on_chan_support = OAL_FALSE,
    .hal_dev_num = WLAN_DEVICE_MAX_NUM_PER_CHIP_MP13,
    .power_off_ready_support = OAL_FALSE,
    .rx_ring_reduce_load_is_open = OAL_FALSE,
    .rx_support_hw_reorder = OAL_FALSE,
    .high_pps_fastsleep_close = OAL_FALSE,
    .rx_ring_8_bytes_align_check = OAL_FALSE,
    .rssi_report_within_frame_support = OAL_FALSE,
};

const oal_wlan_cfg_stru g_wlan_spec_cfg_mp15 = {
    .feature_m2s_modem_is_open = OAL_TRUE,
    .feature_priv_closed_is_open = OAL_FALSE,
    .feature_hiex_is_open = OAL_TRUE,
    .rx_listen_ps_is_open = OAL_TRUE,
    .feature_11ax_is_open = OAL_TRUE,
    .feature_twt_is_open = OAL_TRUE,
    .feature_11ax_er_su_dcm_is_open = OAL_TRUE,
    .feature_11ax_uora_is_supported = OAL_FALSE,
    .feature_ftm_is_open = OAL_TRUE,
    .feature_psm_dfx_ext_is_open = OAL_TRUE,
    .feature_wow_opt_is_open  = OAL_FALSE,
    .feature_dual_wlan_is_supported = OAL_TRUE,
    .feature_ht_self_cure_is_open = OAL_TRUE,
    .feature_slave_ax_is_support = OAL_FALSE,
    .longer_than_16_he_sigb_support = OAL_FALSE,
    .feature_hw_wapi = OAL_FALSE,
    .full_bandwidth_ul_mu_mimo = OAL_FALSE,
    .feature_11be_is_open = OAL_FALSE,
    .feature_ml_is_supported = OAL_FALSE,
    .p2p_device_gc_use_one_vap = OAL_TRUE,
    .max_sta_num = 3,
    .max_p2p_group_num = 1,
    .p2p_go_max_user_num = WLAN_P2P_GO_ASSOC_USER_MAX_NUM_MP15,
    .max_asoc_user = WLAN_ASSOC_USER_MAX_NUM_MP15,
    .max_active_user = WLAN_ASSOC_USER_MAX_NUM_MP15,
    .max_user_limit = WLAN_ASSOC_USER_MAX_NUM_MP15 + WLAN_MULTI_USER_MAX_NUM_LIMIT_MP15,
    .invalid_user_id = WLAN_ASSOC_USER_MAX_NUM_MP15 + WLAN_MULTI_USER_MAX_NUM_LIMIT_MP15,
    .max_tx_ba = WLAN_MAX_TX_BA_MP15,
    .max_rx_ba = WLAN_MAX_RX_BA_MP15,
    .other_bss_id = WLAN_HAL_OHTER_BSS_ID_MP15,
    .max_tx_ampdu_num = WLAN_AMPDU_TX_MAX_NUM_MP15,
    .max_rf_num = 2,
    .max_slave_rf_num = 1,          /* 辅路通道总数  */
    .max_slave_scan_rf_num = 1,     /* 并发扫描时用到的辅路通道数目 */
    .slave_scan_rf_start_idx = 1,   /* 并发扫描时用到的辅路起始通道号 */
    .max_5g_bw = WLAN_BANDWIDTH_160,
    .feature_txq_ns_support = OAL_FALSE,
    .feature_txbf_mib_study = OAL_TRUE,
    .bfer_sounding_dimensions = 1, /* 发送最多支持双流 */
    .bfee_ntx_supports = 8,    /* mp13最多支持 4*2 MU Sounding */
    .vht_max_mpdu_lenth = WLAN_MIB_VHT_MPDU_7991, /* VHT协议mp15最大mpdu_len */
    .pcie_speed = 0, /* 不使用 */
    .trigger_su_beamforming_feedback = OAL_FALSE,
    .trigger_mu_partialbw_feedback = OAL_FALSE,
    .rx_stbc_160 = OAL_FALSE,
    .num_different_channels = 2,
    .max_work_vap_num = 3,
    .rx_checksum_hw_enable = OAL_FALSE,
    .wur_support_5g = OAL_FALSE,
    .wide_bw_support = OAL_FALSE,
    .multi_tid_aggr_tx_support = OAL_FALSE,
    .emlsr_str_link = OAL_FALSE,
    .tx_ba_info = OAL_FALSE,
    .vap_support_max_num_limit = WLAN_VAP_SUPPORT_MAX_NUM_LIMIT_MP15,
#ifdef _PRE_DUAL_CHIP
    .hal_max_vap_num = HAL_MAX_VAP_NUM_DUAL_MP15,
#else
    .hal_max_vap_num = HAL_MAX_VAP_NUM_MP13,
#endif
    .need_check_netbuf_pre_num = OAL_TRUE,
    .feature_same_chan_remain_on_chan_support = OAL_TRUE,
    .hal_dev_num = WLAN_DEVICE_MAX_NUM_PER_CHIP_MP15,
    .power_off_ready_support = OAL_FALSE,
    .rx_ring_reduce_load_is_open = OAL_FALSE,
    .rx_support_hw_reorder = OAL_FALSE,
    .high_pps_fastsleep_close = OAL_FALSE,
    .rx_ring_8_bytes_align_check = OAL_FALSE,
    .rssi_report_within_frame_support = OAL_FALSE,
};
