/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : WIFI 芯片差异接口文件
 * 作    者 :
 * 创建日期 : 2023年9月4日
 */

#include "wlan_chip.h"
#ifdef _PRE_WLAN_FEATURE_HIEX
#include "mac_hiex.h"
#endif
#ifdef _PRE_WLAN_FEATURE_FTM
#include "mac_ftm.h"
#endif
#include "hmac_ext_if.h"
#include "hmac_auto_adjust_freq.h"
#include "hmac_rx_reorder.h"
#include "hmac_cali_mgmt.h"
#include "hmac_tx_data.h"
#include "hmac_host_tx_data.h"
#include "hmac_tx_amsdu.h"
#include "hmac_hcc_adapt.h"
#include "hmac_scan.h"
#include "hmac_rx_host.h"
#include "hisi_customize_wifi.h"
#include "hisi_customize_wifi_mp16.h"
#include "hisi_customize_wifi_mp17c.h"
#include "hisi_customize_wifi_mp12.h"

#include "hmac_config.h"
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
#include "hmac_tcp_ack_buf.h"
#endif
#ifdef _PRE_WLAN_FEATURE_CSI
#include "hmac_csi.h"
#endif
#ifdef _PRE_WLAN_FEATURE_FTM
#include "hmac_ftm.h"
#endif
#ifdef _PRE_WLAN_FEATURE_WMMAC
#include "hmac_wmmac.h"
#endif

#ifdef _PRE_PLAT_FEATURE_CUSTOMIZE
#include "plat_pm_wlan.h"
#endif
#ifdef _PRE_WLAN_FEATURE_DFS
#include "hmac_dfs.h"
#endif
#include "mac_mib.h"
#ifdef _PRE_WLAN_FEATURE_LP_MIRACAST
#include "hmac_lp_miracast.h"
#endif
#ifdef _PRE_WLAN_FEATURE_11AX
#include "hmac_11ax.h"
#endif
#include "hmac_chan_mgmt.h"
#include "hmac_rx_action_filter.h"
#include "hmac_btcoex_cfg.h"
#include "hmac_l5_tas.h"

oal_bool_enum_uint8 wlan_chip_is_support_hw_wapi_mp12(void)
{
    return g_wlan_spec_cfg->feature_hw_wapi;
}
#ifdef _PRE_WLAN_FEATURE_EMLSR
uint8_t wlan_chip_get_emlsr_transation_delay_mp12(void)
{
    return g_cust_cap.emlsr_transation_delay;
}
uint8_t wlan_chip_get_emlsr_padding_delay_mp12(void)
{
    return g_cust_cap.emlsr_padding_delay;
}
#endif
static inline uint8_t wlan_chip_soft_irq_sch_support_mp12(void)
{
    return OAL_TRUE;
}

static uint8_t wlan_chip_get_pcie_probe_state_mp12(mac_user_stru *mac_user)
{
    wlan_nss_enum_uint8 avil_nss = mac_user->en_avail_num_spatial_stream;
    wlan_protocol_enum_uint8 cur_protocol = mac_user->en_cur_protocol_mode;
    wlan_bw_cap_enum_uint8 bw = mac_user->en_avail_bandwidth;

    /* 低于HE协议所有速率，GEN1可支持 */
    if (cur_protocol < WLAN_HE_MODE || bw < WLAN_BW_CAP_160M) {
        return WLAN_PCIE_PROBE_LOW;
    } else if (avil_nss < WLAN_DOUBLE_NSS) {
        /* HE协议仅有160M 2nss需要GEN2，其余GEN1 */
        return WLAN_PCIE_PROBE_LOW;
    }

    return WLAN_PCIE_PROBE_DEFAULT;
}

static void wlan_chip_custom_default_init_mp12(void)
{
    g_cust_cap.phy_cap_mask = 0xBF;
    g_cust_cap.lp_cap_mask = 0x0;
}

static oal_bool_enum_uint8 wlan_chip_is_support_dual_5g_dbdc_by_radio_cap_mp12(void)
{
    return OAL_TRUE;
}

#ifdef _PRE_WLAN_CHBA_MGMT
/* mp12不支持chba dbdc+dbac共存 */
static oal_bool_enum_uint8 wlan_chip_is_support_chba_dbdc_dbac_mp12(void)
{
    return OAL_FALSE;
}
#endif

#ifdef _PRE_WLAN_FEATURE_LP_MIRACAST
void wlan_chip_lp_miracast_stat_mbps_mp12(uint32_t tx_throughput_mbps, uint32_t rx_throughput_mbps)
{
    hmac_config_lp_miracast_stat_mbps(tx_throughput_mbps, rx_throughput_mbps);
}

static uint32_t wlan_chip_set_lp_miracast_mp12(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    return hmac_config_set_lp_miracast(mac_vap, len, param);
}
#endif

const uint32_t g_cmd_need_filter_mp12[] = {
    WLAN_CFGID_ETH_SWITCH,
    WLAN_CFGID_80211_UCAST_SWITCH,
    WLAN_CFGID_80211_MCAST_SWITCH,
    WLAN_CFGID_PROBE_SWITCH,
    WLAN_CFGID_OTA_BEACON_SWITCH,
    WLAN_CFGID_OTA_RX_DSCR_SWITCH,
    WLAN_CFGID_VAP_STAT,
    WLAN_CFGID_REPORT_VAP_INFO,
    WLAN_CFGID_USER_INFO,
    WLAN_CFGID_ALL_STAT,
    WLAN_CFGID_BSS_TYPE,
    WLAN_CFGID_GET_HIPKT_STAT,
    WLAN_CFGID_PROT_MODE,
    WLAN_CFGID_BEACON_INTERVAL,
    WLAN_CFGID_NO_BEACON,
    WLAN_CFGID_DTIM_PERIOD,
    WLAN_CFGID_SET_POWER_TEST,
    WLAN_CFGID_GET_ANT,
    WLAN_CFGID_QUERY_RSSI,
    WLAN_CFGID_QUERY_PSST,
    WLAN_CFGID_QUERY_RATE,
    WLAN_CFGID_QUERY_ANI,
    WLAN_CFGID_SET_P2P_MIRACAST_STATUS,
    WLAN_CFGID_SET_CUS_DYN_CALI_PARAM,
    WLAN_CFGID_SET_ALL_LOG_LEVEL,
    WLAN_CFGID_SET_CUS_RF,
    WLAN_CFGID_SET_CUS_DTS_CALI,
    WLAN_CFGID_SET_CUS_NVRAM_PARAM,
    WLAN_CFGID_SHOW_DEV_CUSTOMIZE_INFOS,
    WLAN_CFGID_SEND_BAR,
    WLAN_CFGID_RESET_HW,
    WLAN_CFGID_GET_USER_RSSBW,
    WLAN_CFGID_ENABLE_ARP_OFFLOAD,
    WLAN_CFGID_SHOW_ARPOFFLOAD_INFO,
    WLAN_CFGID_SET_AUTO_PROTECTION,
    WLAN_CFGID_SET_BW_FIXED,
    WLAN_CFGID_SET_FEATURE_LOG,
    WLAN_CFGID_WMM_SWITCH,
};

static oal_bool_enum_uint8 wlan_chip_h2d_cmd_need_filter_mp12(uint32_t cmd_id)
{
    uint32_t idx;

    for (idx = 0; idx < oal_array_size(g_cmd_need_filter_mp12); idx++) {
        if (cmd_id == g_cmd_need_filter_mp12[idx]) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE; /* 不用过滤 */
}

const struct wlan_chip_ops g_wlan_chip_ops_mp12 = {
#ifdef _PRE_PLAT_FEATURE_CUSTOMIZE
    .host_global_init_param = hwifi_cfg_host_global_init_param_mp16,
    .first_power_on_mark = wlan_first_powon_mark_mp16,
    .first_powon_cali_completed = hmac_first_powon_cali_completed,
    .is_aput_support_160M = wlan_chip_is_aput_support_160m_mp16,
    .get_flow_ctrl_used_mem = wlan_chip_get_flow_ctrl_used_mem_mp16,
    .force_update_custom_params = hwifi_force_update_rf_params_mp16,
    .init_nvram_main = hwifi_config_init_fcc_ce_params_mp16,
    .cpu_freq_ini_param_init = hwifi_config_cpu_freq_ini_param_mp16,
    .host_global_ini_param_init = hwifi_config_host_global_ini_param_mp16,
    .get_selfstudy_country_flag = wlan_chip_get_selfstudy_country_flag_mp16,
    .custom_cali = wal_custom_cali_mp16,
    .custom_cali_data_host_addr_init = hwifi_rf_cali_data_host_addr_init_mp16,
    .send_cali_data = wal_send_cali_data_mp12,
    .send_20m_all_chn_cali_data = wal_send_cali_data_mp12,
    .custom_host_read_cfg_init = hwifi_custom_host_read_cfg_init_mp16,
#ifdef HISI_CONN_NVE_SUPPORT
     .get_nv_dpd_data = wal_get_nv_dpd_data_mp12,
#endif
    .hcc_customize_h2d_data_cfg = hwifi_hcc_customize_h2d_data_cfg_mp16,
    .show_customize_info = hwifi_show_customize_info_mp16,
    .show_cali_data_info = hmac_dump_cali_result_mp12,
    .get_sar_ctrl_params = hwifi_get_sar_ctrl_params_mp17c,
    .get_11ax_switch_mask = wlan_chip_get_11ax_switch_mask_mp16,
    .get_11be_switch_mask = wlan_chip_get_11be_switch_mask_mp16,
    .get_wur_switch = wlan_chip_get_wur_switch_mp16,
    .get_11ac2g_enable = wlan_chip_get_11ac2g_enable_mp16,
    .get_probe_resp_mode = wlan_chip_get_probe_resp_mode_mp16,
    .get_trx_switch = wlan_chip_get_trx_switch_mp16,
    .get_d2h_access_ddr = wlan_chip_get_d2h_access_ddr_mp16,
#endif
    .h2d_cmd_need_filter = wlan_chip_h2d_cmd_need_filter_mp12,
    .update_cfg80211_mgmt_tx_wait_time = wlan_chip_update_cfg80211_mgmt_tx_wait_time_mp16,
    // 收发和聚合相关
    .check_need_setup_ba_session = wlan_chip_check_need_setup_ba_session_mp16,
    .tx_update_amsdu_num = hmac_update_amsdu_num_mp16,
    .check_need_process_bar = wlan_chip_check_need_process_bar_mp16,
    .ba_need_check_lut_idx = wlan_chip_ba_need_check_lut_idx_mp16,
    .trx_aspm_switch_on = NULL,
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
    .tcp_ack_buff_config = hmac_tcp_ack_buff_config_mp16,
#endif
#ifdef _PRE_WLAN_FEATURE_WMMAC
    .wmmac_need_degrade_for_ts = hmac_need_degrade_for_ts_mp16,
#endif
    .update_arp_tid = hmac_update_arp_tid_mp16,
    .get_6g_flag = mac_get_rx_6g_flag_mp16,
    // 校准相关
    .send_cali_matrix_data = hmac_send_cali_matrix_data_mp16c,
    .save_cali_event = hmac_save_cali_event_mp16,
    .update_cur_chn_cali_data = hmac_update_cur_chn_cali_data_mp12,
    .get_chn_radio_cap = wlan_chip_get_chn_radio_cap_mp16,
    .set_chn_cali_data = hmac_set_chn_cali_data_mp12,
    .get_cali_data_send_addr = hmac_get_cali_data_send_addr_mp12,
    .get_cali_data_send_len = hmac_get_cali_data_send_len_mp12,
    .get_cali_data_size = hmac_get_cali_data_size_mp12,
    .save_cali_event_get_cali_times = hmac_save_cali_event_get_cali_times_mp12,
    // 特殊dbdc相关
    .get_special_dbdc_cap = wlan_chip_get_special_dbdc_cap_mp16,
    .get_rf_band_from_center_freq = wlan_chip_get_rf_band_from_center_freq_mp16,
    .get_center_freq_from_chn = wlan_chip_get_center_freq_from_chn_mp16,
    .is_support_dual_5g_dbdc_by_radio_cap = wlan_chip_is_support_dual_5g_dbdc_by_radio_cap_mp12,

#ifdef _PRE_WLAN_FEATURE_11AX
    .mac_vap_init_mib_11ax = mac_vap_init_mib_11ax_mp16,
    .tx_set_frame_htc = hmac_tx_set_qos_frame_htc,
#endif
    .mac_mib_set_auth_rsp_time_out = wlan_chip_mac_mib_set_auth_rsp_time_out_mp16,
    .mac_vap_need_set_user_htc_cap = mac_vap_need_set_user_htc_cap_mp16,
#ifdef _PRE_WLAN_FEATURE_MULTI_NETBUF_AMSDU
    .tx_encap_large_skb_amsdu = hmac_tx_encap_large_skb_amsdu_mp16, /* 大包AMDPU+大包AMSDU入口 mp16 不生效 */
#endif
    .check_headroom_len = check_headroom_length,
    .adjust_netbuf_data = hmac_format_netbuf_header,
    .proc_query_station_packets = wlan_chip_proc_query_station_packets_mp16,
    .scan_req_alloc_and_fill_netbuf = wlan_chip_scan_req_alloc_and_fill_netbuf_mp16,
#ifdef _PRE_WLAN_FEATURE_SNIFFER
    .set_sniffer_config = hmac_config_set_sniffer_mp16,
#endif
#ifdef _PRE_WLAN_FEATURE_CSI
    .dcsi_config = hmac_device_csi_config,
    .hcsi_config = hmac_host_csi_config,
#endif
#ifdef _PRE_WLAN_FEATURE_FTM
    .dftm_config = hmac_device_ftm_config,
    .hftm_config = hmac_host_ftm_config,
    .rrm_proc_rm_request = hmac_rrm_proc_rm_request_mp16,
    .dconfig_wifi_rtt_config = hmac_device_wifi_rtt_config,
    .hconfig_wifi_rtt_config = hmac_host_wifi_rtt_config,
    .ftm_vap_init = hmac_ftm_vap_init_mp16,
#endif
#ifdef _PRE_WLAN_FEATURE_DFS
    .start_zero_wait_dfs = hmac_config_start_zero_wait_dfs_handle,
#endif
    .is_dbdc_ini_en = wlan_chip_is_dbdc_ini_en_mp16,
    .is_single_dbdc_ini_en = NULL,
#if defined(CONFIG_ARCH_HISI) &&  defined(CONFIG_NR_CPUS)
#if CONFIG_NR_CPUS > OAL_BUS_HPCPU_NUM
    .frw_task_bind_cpu = hmac_rx_frw_task_bind_cpu,
#endif
#endif
    .send_connect_security_params = wlan_chip_send_connect_security_params_mp16,
    .defrag_is_pn_abnormal = wlan_chip_defrag_is_pn_abnormal_mp16,
    .is_support_hw_wapi = wlan_chip_is_support_hw_wapi_mp12,
    .get_scaned_result_extend_info = wlan_chip_get_scaned_result_extend_info_mp16,
    .get_scaned_payload_extend_len = wlan_chip_get_scaned_payload_extend_len_mp16,

    .tx_pt_mcast_set_cb = NULL,
    .soft_irq_sch_support = wlan_chip_soft_irq_sch_support_mp12,
    .get_pcie_probe_state = wlan_chip_get_pcie_probe_state_mp12,
    .custom_default_init = wlan_chip_custom_default_init_mp12,
#ifdef _PRE_WLAN_CHBA_MGMT
    .is_support_chba_dbdc_dbac = wlan_chip_is_support_chba_dbdc_dbac_mp12,
#endif
#ifdef _PRE_WLAN_FEATURE_LP_MIRACAST
    .lp_miracast_stat_func = wlan_chip_lp_miracast_stat_mbps_mp12,
    .set_lp_miracast_func = wlan_chip_set_lp_miracast_mp12,
#endif
#ifdef _PRE_WLAN_FEATURE_11AX
    .need_decrease_sts = NULL,
#endif
    .ap_p2p_device_coex_check_valid = NULL,
    .hcc_rx_update_rx_ctrl = NULL,
#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    .set_tas_ant_switch = wlan_chip_set_tas_ant_switch_mp17c,
    .get_tas_ant_status = wlan_chip_get_tas_ant_status_mp16c,
#ifdef _PRE_PLAT_FEATURE_CUSTOMIZE
    .init_nvram_main_tas = hwifi_cust_tas_nv_fcc_ce_pow_data_send_mp17c,
    .tas_refresh_pow_cfg = wlan_chip_tas_switch_refresh_pow_cfg_mp17c,
#endif
#endif
    .get_reduce_pwr_channel_2g_bitmap = wlan_chip_get_reduce_pwr_channel_2g_bitmap_mp16,
#ifdef _PRE_WLAN_FEATURE_EMLSR
    .get_emlsr_transation_delay = wlan_chip_get_emlsr_transation_delay_mp12,
    .get_emlsr_padding_delay = wlan_chip_get_emlsr_padding_delay_mp12,
#endif
#ifdef WIFI_DEBUG_ENABLE
    .always_tx_write_msg = wal_hipriv_always_tx_write_msg_mp17c,
#ifdef _PRE_WLAN_EXPORT
    .set_single_tone_tx = NULL,
#endif
#endif
    .mvap_send_trans_tbl = hmac_mvap_send_trans_tbl,
    .update_action_filter = hmac_update_action_filter,
    .get_lowpower_stat_enable = NULL,
    .set_btcoex_ant_cfg = hmac_set_btcoex_ant_cfg_mp12,
    .get_cali_data_save_addr = hmac_get_cali_data_save_addr_mp12,
    .update_160m_4ltf_08gi_cap = NULL,
    .l5_tas_wifi_open_protect = hmac_l5_tas_wifi_open_protect,
};
