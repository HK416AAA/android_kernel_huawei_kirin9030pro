/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: Update and load independent calibration data
 * Author: platform drivers
 */

/* 头文件包含 */
#include "plat_debug.h"
#include "bfgx_dev.h"
#include "plat_pm.h"
#include "bfgx_data_parse.h"
#include "pcie_linux.h"
#include "cali_data_ops_mp12.h"
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 35))
#ifndef _PRE_NO_HISI_NVRAM
#define HISI_NVRAM_SUPPORT
#endif
#endif
#include "oam_dsm.h"
#include "chr_user.h"

/* 定义不能超过BFGX_BT_CUST_INI_SIZE/4 (128) */
STATIC int32_t g_bfgx_cust_ini_data_mp12c[MP12_BFGX_BT_CUST_INI_SIZE / 4] = {0};
/*
 * 函 数 名  : mp12_bfgx_get_nv_data_buf
 * 功能描述  : 返回保存bfgx nv数据的内存地址
 * 输出参数  : nv buf的长度
 * 返 回 值  : bfgx nv数据buf的地址，也可能是NULL
 */
STATIC void *mp12_bfgx_get_nv_data_buf(uint32_t *pul_len)
{
    mp12_bfgx_cali_data_stru *pst_bfgx_cali_data_buf = NULL;

    if (g_bfgx_cali_data_buf == NULL) {
        return NULL;
    }

    pst_bfgx_cali_data_buf = (mp12_bfgx_cali_data_stru *)g_bfgx_cali_data_buf;

    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_data_buf->auc_nv_data);

    ps_print_info("bfgx nv buf size is %d\n", *pul_len);

    return pst_bfgx_cali_data_buf->auc_nv_data;
}

/*
 * 函 数 名  : mp12_bfgx_get_ext_nv_data_buf
 * 功能描述  : 返回保存bfgx extended nv数据的内存地址
 * 输出参数  : nv extended buf的长度
 * 返 回 值  : bfgx extended nv数据buf的地址，也可能是NULL
 */
STATIC void *mp12_bfgx_get_ext_nv_data_buf(uint32_t *pul_len)
{
    mp12_bfgx_cali_data_stru *pst_bfgx_cali_data_buf = NULL;

    if (g_bfgx_cali_data_buf == NULL) {
        return NULL;
    }

    pst_bfgx_cali_data_buf = (mp12_bfgx_cali_data_stru *)g_bfgx_cali_data_buf;

    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_data_buf->auc_ext_nv_data);

    ps_print_info("bfgx ext nv buf size is %d\n", *pul_len);

    return pst_bfgx_cali_data_buf->auc_ext_nv_data;
}

STATIC void mp12_plat_bfgx_cali_data_test(void)
{
    mp12_bfgx_cali_data_stru *pst_cali_data = NULL;
    uint32_t *p_test = NULL;
    uint32_t count, i;

    pst_cali_data = (mp12_bfgx_cali_data_stru *)g_bfgx_cali_data_buf;
    p_test = (uint32_t *)(pst_cali_data->auc_bfgx_data);
    count = (uint32_t)(sizeof(pst_cali_data->auc_bfgx_data) / sizeof(uint32_t));

    for (i = 0; i < count; i++) {
        p_test[i] = i;
    }
}

/*
 * 函 数 名  : mp12_get_bfgx_cali_data
 * 功能描述  : 返回保存bfgx校准数据的内存首地址以及长度
 * 输入参数  : uint8  *buf:调用函数保存bfgx校准数据的首地址
 *            uint32_t buf_len:buf的长度
 *            uint32_t fw_addr 固件加载的地址
 * 返 回 值  : 0表示成功，-1表示失败
 */
STATIC int32_t mp12_get_bfgx_cali_data(uint8_t *buf, uint32_t buf_len, uint8_t uart_index)
{
    int32_t ret;
    struct ps_core_s *ps_core_d = NULL;
    struct st_bfgx_data *bfgx_data = NULL;
    mp12_bfgx_cali_data_stru *bfgx_cali_data_buf = NULL;

    ps_core_d = ps_get_core_reference(uart_index);
    if (ps_core_d == NULL) {
        ps_print_err("ps_core is null\n");
        return -EFAIL;
    }

    bfgx_data = &ps_core_d->bfgx_info[BFGX_BT];
    if (bfgx_data->cali_buf == NULL) {
        ps_print_err("cali buf is NULL\n");
        return -ENOMEM;
    }

    if (g_cali_buffer_debug != 0) {
        mp12_plat_bfgx_cali_data_test();
    } else {
        bfgx_cali_data_buf = (mp12_bfgx_cali_data_stru *)g_bfgx_cali_data_buf;
        if (memcpy_s(bfgx_cali_data_buf->auc_bfgx_data, MP12_BFGX_BT_CALI_DATA_SIZE,
                     bfgx_data->cali_buf, MP12_BFGX_BT_CALI_DATA_SIZE) != EOK) {
            ps_print_err("mp12 copy buffer fail\n");
            return -EFAIL;
        }
    }

    ret = save_get_bfgx_cali_data(buf, buf_len);
    if (ret < 0) {
        ps_print_err("save cali fail\n");
        return ret;
    }
    return SUCC;
}

/*
 * 函 数 名  : mp12_bfgx_get_cust_ini_data_buf
 * 功能描述  : 返回保存bfgx ini定制化数据的内存地址
 * 输出参数  : bfgx ini定制化数据buf的长度
 * 返 回 值  : bfgx ini数据buf的地址，也可能是NULL
 */
STATIC void *mp12_bfgx_get_cust_ini_data_buf(uint32_t *pul_len)
{
    mp12_bfgx_cali_data_stru *pst_bfgx_cali_data_buf = NULL;

    if (g_bfgx_cali_data_buf == NULL) {
        return NULL;
    }

    pst_bfgx_cali_data_buf = (mp12_bfgx_cali_data_stru *)g_bfgx_cali_data_buf;

    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_data_buf->auc_bt_cust_ini_data);

    ps_print_info("bfgx cust ini buf size is %d\n", *pul_len);

    return pst_bfgx_cali_data_buf->auc_bt_cust_ini_data;
}
/*
 * 函 数 名  : wifi_get_bt_cali_data_buf
 * 功能描述  : 返回保存wifi cali data for bt数据的内存地址
 * 输出参数  : wifi cali data for bt数据buf的长度
 * 返 回 值  : wifi cali data for bt数据buf的地址，也可能是NULL
 */
STATIC void *mp12_wifi_get_bt_cali_data_buf(uint32_t *pul_len)
{
    mp12_bfgx_cali_data_stru *pst_bfgx_cali_data_buf = NULL;

    if (oal_any_null_ptr2(g_bfgx_cali_data_buf, pul_len)) {
        return NULL;
    }

    pst_bfgx_cali_data_buf = (mp12_bfgx_cali_data_stru *)g_bfgx_cali_data_buf;

    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_data_buf->auc_wifi_cali_for_bt_data);

    ps_print_info("bfgx wifi cali data for bt buf size is %d\n", *pul_len);

    return pst_bfgx_cali_data_buf->auc_wifi_cali_for_bt_data;
}

/*
 * 函 数 名  : mp12_check_bfgx_cali_data
 * 功能描述  : 检测上电校准芯片异常状态
 * 输出参数  : 无
 * 返 回 值  : DMD&CHR状态上报
 */
STATIC void mp12_check_bfgx_cali_data(uint8_t *cali_buf)
{
    hal_wl_cali_data_stru_mp12 *bt_cali_data = (hal_wl_cali_data_stru_mp12 *)cali_buf;
    if (bt_cali_data == NULL) {
        ps_print_err("mp12_check_bfgx_cali_data buffer null\n");
        return;
    }

    if ((bt_cali_data->cali_flags.cali_done_flag == FE_CALI_WLAN_TYPE_BUTT) &&
        bt_cali_data->txpwr_cali_data.status != 0) {
        ps_print_err("mp12_check_bfgx_cali_data:abnormal status=0x%x\n",
            bt_cali_data->txpwr_cali_data.status);

        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_BT, DSM_BT_FEMERROR, "%s: vdet error C0-0x%xx",
            __FUNCTION__, bt_cali_data->txpwr_cali_data.status);

        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_BT, CHR_LAYER_DEV,
            CHR_BFGX_DEV_EVENT_CALI, bt_cali_data->txpwr_cali_data.status);
    }
}

bfgx_cali_data_ops_stru g_cali_data_ops_mp12 = {
    .bfgx_cali_data_len = MP12_BFGX_CALI_DATA_BUF_LEN,
    .bt_cali_data_len = MP12_BFGX_BT_CALI_DATA_SIZE,
    .nv_data_len = MP12_BFGX_NV_DATA_SIZE,
    .cust_ini_data_len = MP12_BFGX_BT_CUST_INI_SIZE,
    .get_bfgx_cali_data_ops = mp12_get_bfgx_cali_data,
    .bfgx_get_nv_data_buf_ops = mp12_bfgx_get_nv_data_buf,
    .bfgx_get_ext_nv_data_buf_ops = mp12_bfgx_get_ext_nv_data_buf,
    .plat_bfgx_cali_data_test_ops = mp12_plat_bfgx_cali_data_test,
    .wifi_get_bfgx_rc_data_buf_addr_ops = NULL,
    .wifi_get_bt_cali_data_buf_ops = mp12_wifi_get_bt_cali_data_buf,
    .bfgx_get_cust_ini_data_buf_ops = mp12_bfgx_get_cust_ini_data_buf,
    .bfgx_cust_ini_data_ptr = g_bfgx_cust_ini_data_mp12c,
    .check_bfgx_cali_data_ops = mp12_check_bfgx_cali_data,
};
