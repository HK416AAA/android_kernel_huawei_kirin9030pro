/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: plat_cali.c header file
 * Author: platform drivers
 */

#ifndef CALI_DATA_OPS_MP12_H
#define CALI_DATA_OPS_MP12_H

/* 头文件包含 */
#include "plat_type.h"
#include "oal_types.h"
#include "oal_util.h"
#include "plat_cali.h"

#define BT_WL_2G_CALI_BAND_NUM 3
#define BT_WL_5G_CALI_BAND_NUM 3
#define BT_WLAN_2G_RF_BAND_NUM     3
#define BT_WLAN_5G_RF_BAND_NUM     8
#define FE_CALI_ALL_CHN_NUMS_MP12 1

typedef enum  {
    /* WL通路校准列表 */
    FE_CALI_WLAN_RF_RC, // BW
    FE_CALI_WLAN_RF_R,
    FE_CALI_WLAN_RF_C,
    FE_CALI_WLAN_RF_LOGEN,
    FE_CALI_WLAN_RF_RX_DC,
    FE_CALI_WLAN_RF_TX_DC,
    FE_CALI_WLAN_RF_TX_POW,
    FE_CALI_WLAN_RF_TX_IQ,
    FE_CALI_WLAN_RF_TX_IQ_QMC,
    FE_CALI_WLAN_RF_RX_IQ,
    FE_CALI_WLAN_RF_PEAK_DET,
    FE_CALI_WLAN_RF_POWER_DET,
    FE_CALI_WLAN_RF_LOBF,
    FE_CALI_WLAN_TYPE_BUTT,
} wl_cali_type;

typedef struct {
    int16_t cali_temper;
    uint16_t cali_done_flag;
} cali_rslt_mark_items_mp12;

typedef struct {
    uint16_t rc_cmp_code; // 2G&5G
    uint16_t rsv;
} rc_cali_data_mp12;

typedef struct {
    uint8_t wl_r_code;
    uint8_t rsv;
} wl_r_cali_data;

typedef struct {
    uint8_t wl_c_code;
    uint8_t rsv;
} wl_c_cali_data;

typedef struct {
    wl_r_cali_data r_code;
    wl_c_cali_data c_code;
} wl_r_c_cali_data;

typedef struct {
    int16_t  txdc_cmp_i;
    int16_t  txdc_cmp_q;
} wlan_cali_single_txdc_para_stru;

#define WL_TXDC_MAX_CALI_LVL 2 // 07c当前实际只用了一个档位
typedef struct {
    wlan_cali_single_txdc_para_stru txdc_cmp[WL_TXDC_MAX_CALI_LVL];
} wlan_cali_txdc_para_stru_mp12;

typedef struct  {
    wlan_cali_txdc_para_stru_mp12 txdc_cali_data_2g[BT_WL_2G_CALI_BAND_NUM][FE_CALI_ALL_CHN_NUMS_MP12];
    wlan_cali_txdc_para_stru_mp12 txdc_cali_data_5g[BT_WL_5G_CALI_BAND_NUM][FE_CALI_ALL_CHN_NUMS_MP12];
} cali_data_txdc_mp12;

typedef struct {
    int16_t iq_comp_e_val_wl;
    int16_t iq_comp_p_val_wl;
} wlan_cali_trx_iq_para_stru;

typedef struct {
    int64_t real;
    int64_t imag;
} fe_complex_stru_mp12;

#define FE_TXIQ_QMC_LSFIR_COEF_NUM 7 // 滤波器阶数
typedef struct {
    fe_complex_stru_mp12 coef[FE_TXIQ_QMC_LSFIR_COEF_NUM];
} wlan_cali_txiq_coef_stru;

typedef struct {
    wlan_cali_txiq_coef_stru qmc_fb_2g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_2G_CALI_BAND_NUM];
    wlan_cali_txiq_coef_stru qmc_fb_5g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_5G_CALI_BAND_NUM];
} wlan_cali_txiq_qmc_para_stru;

typedef struct {
    wlan_cali_trx_iq_para_stru txiq_cali_data_2g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_2G_CALI_BAND_NUM];
    wlan_cali_trx_iq_para_stru txiq_cali_data_5g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_5G_CALI_BAND_NUM];
} wlan_cali_txiq_para_stru;

typedef struct {
    wlan_cali_trx_iq_para_stru rxiq_cali_data_2g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_2G_CALI_BAND_NUM];
    wlan_cali_trx_iq_para_stru rxiq_cali_data_5g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_5G_CALI_BAND_NUM];
} wlan_cali_rxiq_para_stru;

#define WLAN_RX_DC_LNA_LVL 8
typedef struct {
    // RX DC
    uint8_t analog_rxdc_cmp_lna_i[WLAN_RX_DC_LNA_LVL];
    uint8_t analog_rxdc_cmp_lna_q[WLAN_RX_DC_LNA_LVL];
    uint16_t digital_rxdc_cmp_i;
    uint16_t digital_rxdc_cmp_q;
} wlan_cali_rxdc_para_stru_mp12;

typedef struct  {
    wlan_cali_rxdc_para_stru_mp12 cali_data_2g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_2G_CALI_BAND_NUM];
    wlan_cali_rxdc_para_stru_mp12 cali_data_5g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WL_5G_CALI_BAND_NUM];
} cali_data_rxdc_mp12;

typedef struct  {
    uint16_t ppa_cap_cmp;
    uint16_t upc_cap_cmp;
    uint16_t tx_pow_gc;
    uint16_t tx_pow_np_gc;
} wlan_cali_data_txpwr_mp12;

typedef struct  {
    wlan_cali_data_txpwr_mp12 txpwr_cali_2g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WLAN_2G_RF_BAND_NUM];
    wlan_cali_data_txpwr_mp12 txpwr_cali_5g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WLAN_5G_RF_BAND_NUM];
    uint32_t status; // bit0~7:2G bit8~15:5G
} cali_data_txpwr_mp12;

typedef struct {
    uint8_t mixer_cap_tune;
    uint8_t lcbuf0_cap_tune;
    uint16_t rsv;
} wl_logen_cali_data_para_stru_mp12;

typedef struct {
    wl_logen_cali_data_para_stru_mp12 logen_cali_data_2g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WLAN_2G_RF_BAND_NUM];
    wl_logen_cali_data_para_stru_mp12 logen_cali_data_5g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WLAN_5G_RF_BAND_NUM];
} logen_cali_data_para_stru_mp12;

typedef struct {
    uint16_t aux_adc_code;
    uint16_t power_det_eos_code;
} wlan_cali_power_det_para_stru;

typedef struct {
    wlan_cali_power_det_para_stru power_det_data[FE_BAND_BUTT][FE_CALI_ALL_CHN_NUMS_MP12];
} cali_data_power_det;

typedef struct {
    uint16_t aux_adc_code;
    uint16_t peak_det_aci_code;
    uint16_t peak_det_eos_code;
    uint8_t resv[2];  /* 对齐 2 */
} wlan_cali_peak_det_para_stru;

typedef struct {
    wlan_cali_peak_det_para_stru peak_det_data[FE_BAND_BUTT][FE_CALI_ALL_CHN_NUMS_MP12];
} cali_data_peak_det;

typedef struct {
    uint16_t lodiv_cali_data_2g[FE_CALI_ALL_CHN_NUMS_MP12];
    uint16_t lodiv_cali_data_5g[FE_CALI_ALL_CHN_NUMS_MP12][BT_WLAN_5G_RF_BAND_NUM];
} cali_data_lodiv_data_mp12;

typedef struct {
    rc_cali_data_mp12 rc_cali_data;
    wl_r_c_cali_data r_c_code_cali_data;

    cali_data_txdc_mp12 txdc_cali_data;
    wlan_cali_txiq_para_stru wl_txiq_cali_data;
    wlan_cali_txiq_qmc_para_stru wl_txiq_qmc_cali_data;
    wlan_cali_rxiq_para_stru wl_rxiq_cali_data;

    cali_data_rxdc_mp12 rxdc_cali_data;
    cali_data_txpwr_mp12 txpwr_cali_data;

    logen_cali_data_para_stru_mp12 logen_cali_data;
    cali_data_power_det power_det_cali_data;
    cali_data_peak_det peak_det_cali_data;
    cali_data_lodiv_data_mp12 lodiv_cali_data;
    cali_rslt_mark_items_mp12 cali_flags;
} hal_wl_cali_data_stru_mp12;

/* 以下宏定义，如果要修改结构体成员，需要同步修改device */
#define MP12_BFGX_BT_CALI_DATA_SIZE             1260 // (sizeof(m12_bfgx_data_stru))
#define MP12_BFGX_WL_CALI_DATA_SIZE             20
#define MP12_BFGX_NV_DATA_SIZE                  128
#define MP12_BFGX_EXT_NV_DATA_SIZE              128
#define MP12_BFGX_BT_CUST_INI_SIZE              512

/* 考虑结构体总体长度考虑SDIO下载长度512对齐特性，这里长度为2048 */
typedef struct {
    uint8_t auc_bfgx_data[MP12_BFGX_BT_CALI_DATA_SIZE]; // bt校准数据
    uint8_t auc_wifi_cali_for_bt_data[MP12_BFGX_WL_CALI_DATA_SIZE]; // wifi校准数据
    uint8_t auc_nv_data[MP12_BFGX_NV_DATA_SIZE];
    uint8_t auc_ext_nv_data[MP12_BFGX_EXT_NV_DATA_SIZE];
    uint8_t auc_bt_cust_ini_data[MP12_BFGX_BT_CUST_INI_SIZE];
} mp12_bfgx_cali_data_stru;

#define MP12_BFGX_CALI_DATA_BUF_LEN  sizeof(mp12_bfgx_cali_data_stru)

extern bfgx_cali_data_ops_stru g_cali_data_ops_mp12;

#endif /* end of cali_data_ops_mp12.h */
