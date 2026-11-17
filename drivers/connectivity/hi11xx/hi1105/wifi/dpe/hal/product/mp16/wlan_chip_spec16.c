/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * 功能说明 : WIFI 芯片差异接口文件
 * 作    者 : wifi
 * 创建日期 : 2025年4月22日
 */
#include "dpe_wlan_resource.h"
#include "wlan_mib_ht_vht_he.h"
#include "wlan_spec_host_if.h"

const oal_wlan_cfg_stru g_wlan_spec_cfg_mp16 = {
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
    .feature_ht_self_cure_is_open = OAL_FALSE,
    .feature_slave_ax_is_support = OAL_TRUE,
    .longer_than_16_he_sigb_support = OAL_TRUE,
    .feature_hw_wapi = OAL_FALSE,
    .full_bandwidth_ul_mu_mimo = OAL_TRUE,
    .feature_11be_is_open = OAL_FALSE,
    .feature_ml_is_supported = OAL_FALSE,
    .p2p_device_gc_use_one_vap = OAL_FALSE,
    .max_sta_num = 4,
    .max_p2p_group_num = 2,
    .p2p_go_max_user_num = WLAN_P2P_GO_ASSOC_USER_MAX_NUM_MP16,  /* mp16 P2P最大接入用户数为8 */
    .max_asoc_user = WLAN_ASSOC_USER_MAX_NUM,
    .max_active_user = WLAN_ASSOC_USER_MAX_NUM,
    .max_user_limit = WLAN_USER_MAX_USER_LIMIT,
    .invalid_user_id = WLAN_USER_MAX_USER_LIMIT,
    .max_tx_ba = WLAN_MAX_TX_BA_MP16,
    .max_rx_ba = WLAN_MAX_RX_BA_MP16,
    .other_bss_id = WLAN_HAL_OHTER_BSS_ID_MP16,
    .max_tx_ampdu_num = WLAN_AMPDU_TX_MAX_NUM_MP16,
    .max_rf_num = 4,
    .max_slave_rf_num = 2,          /* 辅路通道总数  */
    .max_slave_scan_rf_num = 2,     /* 并发扫描时用到的辅路通道数目 */
    .max_band_num = WLAN_CALI_BAND_6G,
    .max_5g_bw = WLAN_BANDWIDTH_160,
    .slave_scan_rf_start_idx = 2,   /* 并发扫描时用到的辅路起始通道号 */
    .feature_txq_ns_support = OAL_FALSE,
    .feature_txbf_mib_study = OAL_TRUE,
    .bfer_sounding_dimensions = 4, /* 发送最多支持4流 */
    .bfee_ntx_supports = 8,    /* mp16 最多支持 8*4 MU Sounding */
    .vht_max_mpdu_lenth = WLAN_MIB_VHT_MPDU_11454, /* VHT协议mp16最大mpdu_len */
    .pcie_speed = 2, /* 默认GEN3 */
    .trigger_su_beamforming_feedback = OAL_TRUE,
    .trigger_mu_partialbw_feedback = OAL_FALSE,
    .rx_stbc_160 = OAL_TRUE,
    .num_different_channels = 3,
    .max_work_vap_num = 3,
    .rx_checksum_hw_enable = OAL_FALSE,
    .wur_support_5g = OAL_FALSE,
    .wide_bw_support = OAL_FALSE,
    .multi_tid_aggr_tx_support = OAL_FALSE,
    .emlsr_str_link = OAL_FALSE,
    .tx_ba_info = OAL_TRUE,
    .vap_support_max_num_limit = WLAN_VAP_SUPPORT_MAX_NUM_LIMIT_MP16C,
    .hal_max_vap_num = HAL_MAX_VAP_NUM_MP16,
    .need_check_netbuf_pre_num = OAL_TRUE,
    .feature_same_chan_remain_on_chan_support = OAL_TRUE,
    .hal_dev_num = WLAN_DEVICE_MAX_NUM_PER_CHIP_MP16,
    .power_off_ready_support = OAL_FALSE,
    .rx_ring_reduce_load_is_open = OAL_FALSE,
    .vsp_timer_id = 16, // VSP特性使用common timer 16
    .vsp_version = 0, // 0:not support 1:vsp1.0 2:vsp2.0
    .rx_support_hw_reorder = OAL_TRUE,
    .high_pps_fastsleep_close = OAL_FALSE,
    .support_ring_burst_access = OAL_FALSE,
    .static_ring_alloc = OAL_FALSE,
    .rx_ring_8_bytes_align_check = OAL_FALSE,
    .rssi_report_within_frame_support = OAL_FALSE,
};
