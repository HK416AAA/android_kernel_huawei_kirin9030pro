/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_resource.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2024年11月18日
 */

#ifndef DPE_WLAN_RESOURCE_H
#define DPE_WLAN_RESOURCE_H
#include "wlan_spec_host.h"
#include "wlan_spec_cfg.h"
#include "dpe_wlan_device.h"
#include "dpe_wlan_vap.h"
#include "dpe_wlan_user.h"
#include "mac_frame_if.h"
#include "dpe_wlan_stat.h"

#define DPE_MIN_CACHE_UPDATE_LEN 256

typedef struct {
    dpe_wlan_device_stru dpe_wlan_device_res[WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC];
    dpe_wlan_vap_stru dpe_wlan_vap_res[WLAN_VAP_MAX_NUM_LIMIT];
    dpe_wlan_user_stru dpe_wlan_user_res[WLAN_USER_MAX_USER_LIMIT];
} dpe_wlan_res_stru;

typedef struct {
    dpe_wlan_device_stat_stru device_stat[WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC];
    dpe_wlan_vap_stat_stru vap_stat[WLAN_VAP_MAX_NUM_LIMIT];
    dpe_wlan_user_stat_stru user_stat[WLAN_USER_MAX_USER_LIMIT];
    dpe_wlan_event_dispatch_stat_stru event_trx_stat;
    uint8_t resv[DPE_MIN_CACHE_UPDATE_LEN]; /* 增加一定余量, 避免共享内存刷cache时出现问题 */
} dpe_wlan_stat_res_stru; /* 统计相关资源定义 */
#define DPE_WLAN_DEV_RX_ALLOC_LIST_LIMIT   (HAL_RX_DSCR_QUEUE_ID_BUTT * WLAN_DEVICE_MAX_NUM_PER_CHIP)
typedef struct {
    oal_spin_lock_stru cache_user_lock[WLAN_VAP_MAX_NUM_LIMIT];
    oal_spin_lock_stru wait_list_lock[WLAN_VAP_MAX_NUM_LIMIT];
    oal_spin_lock_stru device_rx_list_lock[WLAN_USER_MAX_USER_LIMIT];
    oal_spin_lock_stru dev_rx_alloc_list_lock[DPE_WLAN_DEV_RX_ALLOC_LIST_LIMIT];
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_spin_lock_stru tid_list_lock[HOST_TX_LIST_BUTT];
#else
    oal_mutex_stru     tid_list_lock[HOST_TX_LIST_BUTT];
#endif
    oal_spin_lock_stru dpe_frw_thread_lock;
} dpe_wlan_lock_res_stru; /* 锁相关资源定义 */

extern dpe_wlan_stat_res_stru g_dpe_wlan_stat_res;
extern dpe_wlan_stat_res_stru *g_dpe_wlan_stat_res_ptr;

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
// 低功耗统计类
typedef struct {
    uint32_t tid_not_empty_cnt;
    uint32_t tid_ring_host_cnt;
    uint32_t master_ddr_rx_cnt;
    uint32_t slave_ddr_rx_cnt;
    uint32_t host_forbid_sleep_cnt;
    uint32_t ring_has_mpdu_cnt;
} wlan_pm_ring_stat;

/* 低功耗wlan侧收发包统计:统计数据不准确(未加锁,调度数量不确定),仅用于判断是否可以进低功耗 */
typedef struct {
    uint32_t ring_tx_pkt; /* ring发包统计 */
    uint32_t d2h_rx_pkt;  /* 非host ring rx，hcc接收报文上报 */
    uint32_t host_rx_pkt; /* host ring接收报文统计 */
} pm_wlan_pkt_statis_stru;
extern pm_wlan_pkt_statis_stru g_pm_wlan_pkt_statis;

wlan_pm_ring_stat *wlan_pm_get_ring_stat(void);
void dpe_clean_wlan_pm_ring_stat(void);
uint32_t dpe_pm_get_trx_cnt(void);
void dpe_wlan_pm_print_debug_info(void);
#endif
uint8_t dpe_wlan_chip_get_max_5g_bw(void);
void dpe_wlan_res_init(void);
dpe_wlan_res_stru *dpe_wlan_res_addr_get(void);

/* 对接ACPU的spec cfg差异化配置同步接口 */
int32_t dpe_chip_feature_init(void);
uint8_t dpe_mac_chip_get_hal_max_vap_num(void);
void dpe_pm_reset_trx_stat(void);
oal_spin_lock_stru *dpe_get_user_dev_rx_list_lock(uint16_t lock_idx);
oal_spin_lock_stru *dpe_get_vap_cache_user_lock(uint16_t lock_idx);
oal_spin_lock_stru *dpe_get_vap_wait_list_lock(uint16_t lock_idx);
oal_spin_lock_stru *dpe_get_dev_rx_alloc_list_lock(uint16_t lock_idx);
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
oal_spin_lock_stru *dpe_get_tid_list_lock(uint8_t lock_idx);
#else
oal_mutex_stru *dpe_get_tid_list_lock(uint8_t lock_idx);
#endif
oal_spin_lock_stru *dpe_get_frw_thread_lock(void);
#endif
