/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 * 功能说明 : hmac_l5_tas.c 的头文件
 * 作    者 : y30077478
 * 创建日期 : 2025年12月10日
 */
 
#ifndef HMAC_L5_TAS_H
#define HMAC_L5_TAS_H
 
#include "frw_ext_if.h"
#include "oal_ext_if.h"
#include "mac_vap.h"
#include "hmac_vap.h"
 
oal_bool_enum_uint8 *hmac_get_l5_tas_switch_flag(void);
uint32_t hmac_l5_tas_ant_switch(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param);
uint32_t hmac_l5_tas_ant_switch_config(uint8_t l5_tas_ant_switch_status);
uint32_t hmac_l5_tas_ant_switch_notify(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param);
uint32_t hmac_l5_tas_wifi_open_protect(void);
void hmac_set_l5_tas_switch_status(uint8_t status);
uint32_t hmac_l5_tas_reset_default_cfg(oal_net_device_stru *net_dev);
uint32_t hmac_l5_tas_wifi_status_check(void);
uint8_t hmac_l5_tas_ant_switch_status_check(uint8_t status);
int32_t hmac_l5_tas_wait_dmac_notify(mac_vap_stru *mac_vap, hmac_vap_stru *hmac_vap);

#endif