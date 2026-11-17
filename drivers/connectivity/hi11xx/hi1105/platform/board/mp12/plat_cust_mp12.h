/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Customization Structure
 * Author: platform drivers
 */

#ifndef PLAT_CUST_MP12_H
#define PLAT_CUST_MP12_H

/* 其他头文件包含 */
#include "plat_type.h"

/* 必须和mp12/pilot/chip/port/common/inc/adapter_plat_cust.h中DTCM_PLAT_CUST_LEN长度相同 */
#define DTCM_PLAT_CUST_LEN 0x40

typedef union {
    struct {
        uint8_t release_version; // true:relese; false: other
        uint8_t enter_rsmc;
        uint8_t gugong_fac_status;
        uint8_t vmin_mode;
        uint32_t buart_rate;
        uint32_t gnss_dpe_switch;
        uint32_t slave_monitor;
        uint8_t sensorhub_enable;
        uint8_t gnss_xw_mode;
        uint8_t pm_linkdown;
        uint8_t auto_cg;
        uint8_t uart_parity_en;
        uint8_t lp_eng_switch;
        uint8_t low_temp_protect_switch;
        uint8_t reserve2;
        uint32_t clk_32k_freq;
        uint8_t resered[36]; /* 预留36个字节扩展用 */
    } cfg;
    uint8_t data[DTCM_PLAT_CUST_LEN];
} plat_cust_data_mp12;
_Static_assert(sizeof(plat_cust_data_mp12) == DTCM_PLAT_CUST_LEN, "Union size does not match DTCM_PLAT_CUST_LEN");
#endif