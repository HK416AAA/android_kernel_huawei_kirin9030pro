/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: nbw master election
 * Author: wifi
 * Create: 2025-04-23
 */
#ifndef HMAC_NBW_MASTER_ELECTION_H
#define HMAC_NBW_MASTER_ELECTION_H

#include "hmac_chba_sync.h"
#include "hmac_nbw_channnel_measure.h"
#include "hmac_nbw_sync.h"
#include "oam_ext_if.h"
#include "oal_util.h"
#include "hmac_chba_function.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_MASTER_ELECTION_H

#ifdef _PRE_WLAN_FEATURE_NBW

/* 1 宏定义 */
#define NBW_MASTER_BLACKLIST_MAX 16
#define NBW_MASTER_ELECTION_MAX 32
#define NBW_MAX_MASTER_ELECTION_DEVICE_NUM 32
#define NBW_DEFAULT_MASTER_AGING_TIME 60  /* master选举黑名单老化时间，单位s */
#define NBW_DEFAULT_RANKING_ID 1
#define NBW_MASTER_ELECTION_SELECT_RSSI_LEVEL 2 /* master选举 rssi切换阈值 */
#define NBW_NBW_USLOT_NUM_FIX 8
#define NBW_MASTER_ELECTION_MAX_MEASURE_TIME (MAC_NBW_DEFALUT_PERIODS_MS * 8) /* master丢失场景下，信道测量最大时长1s */
#define SIGNAL_LEVEL_NUM 4

/* 2 枚举定义 */
/* 域主选举触发场景枚举 */
typedef enum {
    TRIGGER_BY_SLAVEAP = 0,         /* slaveAP设备触发的域主选举 */
    TRIGGER_BY_MASTER = 1,          /* master设备触发的域主选举 */
    TRIGGER_BY_MASTER_LOSS = 2,     /* master丢失触发的域主选举 */
    TRIGGER_BY_INTERFERANCE = 3,    /* 干扰触发的域主选举 */

    TRIGGER_SCENE_BUTT,
} nbw_master_election_scene_enum;

/* 黑名单模式 */
typedef enum {
    NBW_BLACKLIST_MODE_NONE = 0,   /* 关闭黑名单         */
    NBW_BLACKLIST_MODE_ENABLE = 1, /* 黑名单使能       */

    NBW_BLACKLIST_MODE_BUTT
} nbw_blacklist_mode_enum;

/* 3 结构体定义 */
/* NBW黑名单域主信息的结构体 */
typedef struct {
    uint8_t master_addr[OAL_MAC_ADDR_LEN]; /* 域主bssid */
    uint8_t update_time;                   /* 域主更新时间, 单位s */
    uint8_t aging_time;                    /* 老化时间，单位s */
    bool is_local_master;                  /* 是否为本域master */
} hmac_nbw_per_master_blacklist_info_stru;

/* NBW本设备维护的所有历史域主的结构体 */
typedef struct {
    uint8_t is_blacklist_en;                                                            /* 黑名单机制是否生效 */
    uint8_t master_his_cnt;                                                             /* 历史域主个数   */
    hmac_nbw_per_master_blacklist_info_stru master_blacklist[NBW_MASTER_BLACKLIST_MAX]; /* 历史域主信息表 */
} hmac_nbw_master_blacklist_stru;

/* NBW选举的域主信息 */
typedef struct {
    uint8_t master_addr[OAL_MAC_ADDR_LEN]; /* 域主bssid */
    bool is_local_master;                  /* 是否为本域master */
    nbw_ranking_priority rp;               /* 域主设备RP值 */
    uint8_t rssi_level;                    /* 域主rssi档位 */
    uint8_t alloc_uslot_bitmap;            /* 域主使用时隙情况 */
    uint8_t island_flag;                   /* 单群岛指示 */
} election_master_info_stru;

/* 参与选举的所有master域主列表 */
typedef struct {
    nbw_master_election_scene_enum election_type;
    uint8_t master_election_cnt;                        /* 选举域主信息个数 */
    election_master_info_stru *master_election_list;    /* 选举域主信息列表 */
} hmac_nbw_master_election_mgmt_stru;

/* NBW 选举结果信息列表结构体 */
typedef struct {
    uint8_t role;                                     /* 本设备的角色，master、岛主、其它设备 */
    uint8_t is_island_owner_master;                   /* 本设备是否优先选择为域主 */
    uint8_t island_owner_addr[WLAN_MAC_ADDR_LEN];     /* 本设备的mac地址 */
    uint8_t master_election_result_cnt;               /* 选举后的master结果信息个数 */
    election_master_info_stru *master_election_result_list; /* 选举后的域主信息列表，按优先级排序 */
} hmac_nbw_master_election_result_info_stru;

// 辅助结构：存储岛节点和对应的rp信息，用于rp排序
typedef struct {
    uint8_t mac_addr[OAL_MAC_ADDR_LEN];
    hmac_chba_per_island_info_stru *node;
    nbw_ranking_priority rp;
} island_rank_entry;

/* 4 全局变量声明 */
extern hmac_nbw_master_blacklist_stru g_nbw_master_election_blacklist;

static inline hmac_nbw_master_blacklist_stru *hmac_nbw_get_blacklist_mgmt(void)
{
    return &g_nbw_master_election_blacklist;
}

/* 5 函数声明 */
void hmac_nbw_update_rp_ranking_id(uint8_t work_mode);
void hmac_nbw_blacklist_init(void);
oal_bool_enum_uint8 hmac_nbw_master_blacklist_filter(uint8_t *mac_addr);
uint32_t hmac_nbw_blacklist_add(uint8_t *mac_addr, uint32_t aging_time);
uint32_t hmac_nbw_blacklist_del(uint8_t *mac_addr);
uint32_t hmac_nbw_master_election_trigger_by_measure(hmac_nbw_chan_measure_res_stru *measure_res,
    nbw_master_election_scene_enum election_type, hmac_nbw_master_election_result_info_stru *result_list_by_priority);
void hmac_nbw_master_election_trigger_by_master(hmac_nbw_master_election_mgmt_stru *election_list,
    hmac_nbw_master_election_result_info_stru *result);
void hmac_nbw_master_election_trigger_by_slaveap(hmac_nbw_master_election_mgmt_stru *election_list,
    hmac_nbw_master_election_result_info_stru *result);
uint32_t hmac_nbw_master_election_by_loss(hmac_vap_stru *hmac_vap);
void hmac_nbw_master_loss_select_self_as_master(hmac_vap_stru *hmac_vap);
void hmac_nbw_master_loss_trigger_chan_meas_process(hmac_vap_stru *hmac_vap);
void hmac_qsort(void *base, int nmemb, int size, int (*cmp)(const void*, const void*));
election_master_info_stru hmac_nbw_get_best_master_election_info(
    hmac_nbw_master_election_result_info_stru *result_list_by_priority);
uint8_t hmac_nbw_get_rp_ranking_by_slaveap_id(uint8_t work_mode, uint8_t slaveAp_id);
int compare_by_rp(const void *a, const void *b);
uint32_t hmac_nbw_get_master_election_list(hmac_nbw_chan_measure_res_stru *measure_res,
    hmac_nbw_master_election_mgmt_stru *election_list);
void hmac_nbw_update_sync_ranking_id(uint8_t work_mode);
oal_bool_enum_uint8 hmac_nbw_self_device_update_rp(uint8_t work_mode, hmac_chba_per_island_info_stru *curr_island);
void hmac_nbw_sync_module_init(hmac_chba_device_para_stru *device_info);
uint32_t hmac_nbw_rssi_to_signal_level(int8_t rssi, wlan_channel_band_enum_uint8 band);
#endif
#endif