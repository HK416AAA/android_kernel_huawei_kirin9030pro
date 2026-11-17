/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : wifi定制化函数实现
 * 作者       : wifi
 * 创建日期   : 2020年5月20日
 */

/* 头文件包含 */
#include "hisi_customize_wifi_mp16.h"
#include "hmac_cali_mgmt.h"
#include "hisi_customize_wifi_mp17c.h"


#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HISI_CUSTOMIZE_WIFI_MP17_C

/*
 * 函 数 名  : hmac_set_scan_dbdc_cali_data
 * 功能描述  : 获取20m(扫描)下发DBDC校准数据
 */
void hmac_set_scan_dbdc_cali_data_mp17c(void)
{
    uint8_t *mem_addr = get_cali_data_buf_addr();
    mp1x_wlan_cali_data_para_stru *cali_data = (mp1x_wlan_cali_data_para_stru *)mem_addr;
    uint8_t rf_idx;
    uint8_t chn_idx;
    wlan_cali_band_enum_uint8 wlan_cali_band;
    uint8_t rf_slave_idx = hmac_get_slave_scan_rf_start_idx();
    uint8_t rf_slave_scan_num = hmac_get_slave_scan_rf_num();
    wlan_cali_20m_basic_para_stru *scan_cali_data = NULL;
    wlan_cali_dbdc_basic_para_stru *dbdc_cali_data = NULL;
    uint8_t chn_num[] = {WLAN_2G_CALI_BAND_NUM, WLAN_5G_20M_CALI_BAND_NUM, WLAN_6G_20M_CALI_BAND_NUM};

    for (rf_idx = rf_slave_idx; rf_idx < rf_slave_idx + rf_slave_scan_num; rf_idx++) {
        for (wlan_cali_band = WLAN_CALI_BAND_2G; wlan_cali_band < HAL_MAX_BAND_NUM; wlan_cali_band++) {
            for (chn_idx = 0; chn_idx < chn_num[wlan_cali_band]; chn_idx++) {
                scan_cali_data = hmac_get_scan_basic_cali_data_addr(rf_idx, wlan_cali_band, chn_idx);
                dbdc_cali_data = hmac_get_dbdc_basic_cali_data_addr(cali_data, rf_idx, wlan_cali_band, chn_idx);
                hmac_set_scan_dbdc_basic_cali_data(scan_cali_data, dbdc_cali_data);
            }
        }
    }
}

void wal_send_cali_data_mp17c(oal_net_device_stru *cfg_net_dev)
{
    h2d_cali_trans_stru h2d_scan_cali_trans = {0};
    h2d_cali_trans_stru h2d_scan_cali_trans_slave = {0};
    h2d_cali_trans_stru h2d_comm_cali_trans = {0};

    hmac_set_scan_cali_data(oal_net_dev_priv(cfg_net_dev));
    h2d_scan_cali_trans.cali_data_type = WLAN_SCAN_ALL_CHN;
    hmac_send_cali_data_mp16(oal_net_dev_priv(cfg_net_dev), &h2d_scan_cali_trans);
    /* 下发辅路扫描校准数据 */
    hmac_set_scan_dbdc_cali_data_mp17c();
    h2d_scan_cali_trans_slave.cali_data_type = WLAN_SCAN_ALL_CHN_SLAVE;
    hmac_send_cali_data_mp16(oal_net_dev_priv(cfg_net_dev), &h2d_scan_cali_trans_slave);
    h2d_comm_cali_trans.cali_data_type = WLAN_CALI_CTL;
    hmac_send_cali_data_mp16(oal_net_dev_priv(cfg_net_dev), &h2d_comm_cali_trans);
    h2d_comm_cali_trans.cali_data_type = WLAN_CALI_CTL_EXT;
    hmac_send_cali_data_mp16(oal_net_dev_priv(cfg_net_dev), &h2d_comm_cali_trans);
}

#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
uint32_t hwifi_cust_tas_nv_fcc_ce_pow_data_send_mp17c(oal_net_device_stru *cfg_net_dev,
    uint8_t wlan_band, oal_bool_enum_uint8 tas_ant_switch)
{
    uint32_t ret = OAL_SUCC;
    uint8_t rf_idx;
    for (rf_idx = 0; rf_idx < HD_EVENT_RF_NUM; rf_idx++) {
        if (hwifi_get_rf_chn_tas_en(wlan_band, rf_idx) == OAL_TRUE) {
            if (tas_ant_switch) {
                g_cust_pow.tas_fcc_ce_param[rf_idx].tas_band = wlan_band;
                g_cust_pow.tas_fcc_ce_param[rf_idx].rf_chn = rf_idx;
                ret += hwifi_custom_data_send(cfg_net_dev, (uint8_t *)&(g_cust_pow.tas_fcc_ce_param[rf_idx]),
                    sizeof(hal_cfg_custom_tas_fcc_txpwr_limit_stru), WLAN_CFGID_SET_TAS_CUS_FCC_CE_POW);
            } else {
                g_cust_pow.fcc_ce_param[rf_idx].rf_id = rf_idx;
                g_cust_pow.fcc_ce_param[rf_idx].is_tas_recovery = OAL_TRUE;
                g_cust_pow.fcc_ce_param[rf_idx].tas_band = wlan_band;
                ret += hwifi_custom_data_send(cfg_net_dev, (uint8_t *)&(g_cust_pow.fcc_ce_param[rf_idx]),
                    sizeof(hal_cfg_custom_fcc_txpwr_limit_stru), WLAN_CFGID_SET_CUS_FCC_CE_POW);
            }
        }
    }
    if (ret != OAL_SUCC) {
        oam_error_log2(0, 0, "hwifi_cust_tas_nv_fcc_ce_pow_data_send_mp17c::fail[%d] tas_switch[%d]",
            ret, tas_ant_switch);
    }
    return ret;
}
#endif

static uint32_t hwifi_memcpy_sar_ctrl_pow_mp17c(wlan_sar_trigger_cfg_stru *sar_trigger_param,
    uint8_t lvl_num, uint16_t dest_len)
{
#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    uint8_t rf_idx;
#endif
    if (memcpy_s(&sar_trigger_param->sar_avg_pow, dest_len,
        &g_cust_pow.sar_ctrl_params[lvl_num], sizeof(wlan_cust_sar_cfg_stru)) != EOK) {
        return OAL_FAIL;
    }
#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    for (rf_idx = 0; rf_idx < HD_EVENT_RF_NUM; rf_idx++) {
        if ((wal_get_curr_band_tas_state(WLAN_BAND_2G) == OAL_TRUE) &&
            (hwifi_get_rf_chn_tas_en(WLAN_BAND_2G, rf_idx) == OAL_TRUE)) {
            if (memcpy_s(&sar_trigger_param->sar_avg_pow.sar_ctrl_params[rf_idx][MAC_NUM_5G_BAND],
                sizeof(uint8_t),
                &g_cust_pow.tas_sar_ctrl_params[lvl_num].sar_ctrl_params[rf_idx][MAC_NUM_5G_BAND],
                sizeof(uint8_t)) != EOK) {
                return OAL_FAIL;
            }
        }
        if ((wal_get_curr_band_tas_state(WLAN_BAND_5G) == OAL_TRUE) &&
            (hwifi_get_rf_chn_tas_en(WLAN_BAND_5G, rf_idx) == OAL_TRUE)) {
            if (memcpy_s(&sar_trigger_param->sar_avg_pow.sar_ctrl_params[rf_idx][0],
                sizeof(uint8_t) * MAC_NUM_5G_BAND,
                &g_cust_pow.tas_sar_ctrl_params[lvl_num].sar_ctrl_params[rf_idx][0],
                sizeof(uint8_t) * MAC_NUM_5G_BAND) != EOK) {
                return OAL_FAIL;
            }
        }
    }
#endif
    return OAL_SUCC;
}

uint32_t hwifi_get_sar_ctrl_params_mp17c(uint8_t lvl_num, uint8_t *data_addr,
    uint16_t *data_len, uint16_t dest_len)
{
    uint8_t temp_lvl_num = lvl_num;
    wlan_sar_trigger_cfg_stru *sar_trigger_param = (wlan_sar_trigger_cfg_stru *)data_addr;
    *data_len = (uint16_t)(sizeof(wlan_sar_trigger_cfg_stru));
#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    g_cur_sar_txpwr_lvl = (uint16_t)lvl_num + 1000; // 更新当前SAR档位，格式10xx，1000为默认值
#endif
    if ((temp_lvl_num <= CUS_NUM_OF_SAR_LVL) && (temp_lvl_num > 0)) {
        temp_lvl_num--;
        if ((hwifi_memcpy_sar_ctrl_pow_mp17c(sar_trigger_param, temp_lvl_num, dest_len) == OAL_FAIL) ||
            (memcpy_s(sar_trigger_param->sar_cust_slide.sar_total_time, dest_len,
                g_cust_cap.sar_total_time[temp_lvl_num],
                sizeof(sar_trigger_param->sar_cust_slide.sar_total_time)) != EOK)) {
            oam_error_log0(0, OAM_SF_CFG, "hwifi_get_sar_ctrl_params::memcpy fail!");
            return OAL_FAIL;
        }
    } else {
        memset_s(data_addr, dest_len, 0xFF, dest_len);
    }
    return OAL_SUCC;
}
