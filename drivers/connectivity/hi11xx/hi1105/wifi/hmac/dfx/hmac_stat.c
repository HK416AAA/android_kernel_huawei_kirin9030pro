/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : WIFI HMAC统计接口文件
 * 作    者 :
 * 创建日期 : 2020年7月21日
 */

#include "hmac_stat.h"
#include "hmac_device.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_STAT_C

hmac_lp_miracast_stat_stru g_hmac_lp_miracast_stats;
hmac_device_trx_stat g_hmac_device_trx_stat[WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC];

hmac_device_trx_stat *hmac_get_device_trx_stat(void)
{
    return &g_hmac_device_trx_stat[0];
}
void hmac_stat_init_device_screen_stat(hmac_device_stru *hmac_device)
{
    hmac_device->lp_miracast_stats = &g_hmac_lp_miracast_stats;
    memset_s(&g_hmac_lp_miracast_stats, sizeof(g_hmac_lp_miracast_stats), 0, sizeof(g_hmac_lp_miracast_stats));
}
