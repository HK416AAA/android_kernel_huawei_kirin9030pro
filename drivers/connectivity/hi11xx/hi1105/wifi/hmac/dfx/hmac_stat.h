/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : WIFI HOST统计接口文件
 * 作    者 :
 * 创建日期 : 2020年7月21日
 */

#ifndef HMAC_STAT_H
#define HMAC_STAT_H

#include "hmac_stat_stru.h"
#include "hmac_vap.h"
#include "hmac_user.h"
#include "dpe_wlan_stat.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_mgmt.h"
#include "hmac_chba_function.h"
#endif

#define HMAC_VAP_STATS_PKT_INCR(_member, _cnt) ((_member) += (_cnt))

struct hmac_device_tag;

void hmac_stat_init_device_screen_stat(struct hmac_device_tag *hmac_device);

extern hmac_lp_miracast_stat_stru g_hmac_lp_miracast_stats;

OAL_STATIC OAL_INLINE hmac_lp_miracast_stat_stru *hmac_stat_get_lp_miracast_stats(void)
{
    return &g_hmac_lp_miracast_stats;
}
hmac_device_trx_stat *hmac_get_device_trx_stat(void);
#endif /* HMAC_STAT_H */

