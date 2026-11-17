/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : wifi定制化头文件声明
 * 作者       : wifi
 * 创建日期   : 2015年10月08日
 */

#ifndef HISI_CUSTOMIZE_WIFI_MP17C_H
#define HISI_CUSTOMIZE_WIFI_MP17C_H


/* 其他头文件包含 */
#include "oal_hcc_host_if.h"

void wal_send_cali_data_mp17c(oal_net_device_stru *cfg_net_dev);
#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
uint8_t wal_get_curr_band_tas_state(uint8_t wlan_band);
uint32_t wlan_chip_set_tas_ant_switch_mp17c(oal_net_device_stru *net_dev, oal_bool_enum_uint8 tas_ant_switch);
uint32_t hwifi_cust_tas_nv_fcc_ce_pow_data_send_mp17c(oal_net_device_stru *cfg_net_dev,
    uint8_t wlan_band, oal_bool_enum_uint8 tas_ant_switch);
int32_t wlan_chip_tas_switch_refresh_pow_cfg_mp17c(oal_net_device_stru *net_dev, oal_bool_enum_uint8 tas_ant_switch);
#endif
uint32_t hwifi_get_sar_ctrl_params_mp17c(uint8_t lvl_num, uint8_t *data_addr,
    uint16_t *data_len, uint16_t dest_len);
void wlan_chip_update_160m_4ltf_08gi_cap_mp17c(void);
#endif  // hisi_customize_wifi_mp17c.h
