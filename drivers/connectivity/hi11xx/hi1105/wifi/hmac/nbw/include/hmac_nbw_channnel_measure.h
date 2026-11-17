/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: nbw 8GHz channel measurement
 * Author: wifi
 * Create: 2025-03-29
 */
#ifndef HMAC_NBW_CHANNEL_MEASURE_H
#define HMAC_NBW_CHANNEL_MEASURE_H

#include "oam_ext_if.h"
#include "frw_ext_if.h"
#include "oal_util.h"
#include "hilist.h"
#include "hmac_vap.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_CHANNEL_MEASURE_H
#ifdef _PRE_WLAN_FEATURE_NBW

/* 1. 宏定义 */
/* NBW 8GHz频段信道宏定义 */
#define NBW_MAX_CHANNLE_NUM 3
#define NBW_CHANNEL_8 8
#define NBW_CHANNEL_9 9
#define NBW_CHANNEL_10 10
#define NBW_CHANNEL_RES_0 0
#define NBW_CHANNEL_RES_1 1
#define NBW_CHANNEL_RES_2 2
#define NBW_CHANNEL_BITMAP_MAX_VALUE 7
#define NBW_USED_BITMAP_POS 4
#define NBW_MASTER_BEACON_ATTR_MIN_LEN 6
#define NBW_MATSER_BEACON_RSSI_OFFSET 2
#define NBW_CHANNEL_RES_EXPIREE_TIME 500 /* 500 milliseconds */
#define NBW_CHANNEL_MEASURE_TIME 200 /* 200 milliseconds */

/* 2. 枚举值定义 */
/* 信道测量状态 */
typedef enum {
    MAC_NBW_CHANNEL_MEASURE_END = 0, /* 信道测量已结束 */
    MAC_NBW_CHANNEL_MEASURE_START = 1, /* 信道测量已启动 */
    MAC_NBW_CHANNEL_MEASURE_STATUS_BUTT,
} hmac_nbw_chan_measure_status_enum;

/* 信道测量触发事件类型, 以下枚举值对应事件的bit位置 */
typedef enum {
    MAC_NBW_CONN_TRIGGER_CHAN_MEASURE = 0, /* 连接触发信道测量 */
    MAC_NBW_POOR_QOS_TRIGGER_CHAN_MEASURE = 1, /* 底层检测到传输质量差 */
    MAC_NBW_MASTER_LOST_TRIGGER_CHAN_MEASURE = 2, /* MASTER丢失触发信道测量 */
    MAC_NBW_SLAVE_TRIGGER_CHAN_MEASURE = 3, /* 从设备触发信道测量 */
    MAC_NBW_APP_TRIGGER_CHAN_MEASURE = 4, /* 上层应用触发信道测量 */
    MAC_NBW_TRIGGER_CHAN_MEASURE_EVENT_BUTT,
} hmac_nbw_chan_measure_type_enum;

/* 信道测量接口返回值 */
typedef enum {
    MAC_NBW_CHANNEL_MEASURE_NORMAL = 0,
    MAC_NBW_CHANNEL_MEASURE_PARA_ERROR = 1,
    MAC_NBW_CHANNEL_MEASURE_BUSY = 2,
    MAC_NBW_CHAN_MEASURE_BUTT
} hmac_nbw_chan_measure_error_type_enum;

/* 3. 数据结构体定义 */
/* 单个域的信息 */
typedef struct {
    int8_t master_rssi; /* 域主设备rssi */
    uint8_t alloc_uslot_bitmap; /* 域已分配时隙资源信息 */
    uint8_t link_cnt; /* 当前域的链路数 */
    uint8_t master_addr[OAL_MAC_ADDR_LEN]; /* 域主bssid */
} hmac_nbw_chan_domain_info_stru;

/* 单个域信息链表节点结构体 */
typedef struct {
    struct hi_node node;
    hmac_nbw_chan_domain_info_stru data;
} hmac_nbw_domain_list_node_stru;

/* 单个信道测量结果 */
typedef struct {
    uint32_t measure_end_time; /* 信道测量结束时间，用于判断信道测量结果有效期 */
    uint8_t channel_num; /* 信道号 */
    uint8_t channel_load; /* 信道负载 */
    uint8_t domain_cnt; /* 信道上域的数量 */
    struct hi_list domain_list; /* 信道上域的信息 */
} hmac_nbw_chan_measure_res_stru;

/* 信道测量管理 */
typedef struct {
    uint8_t measure_status; /* 信道测量状态，取值为hmac_nbw_chan_measure_status_enum */
    uint8_t measure_channel_cnt; /* 需要测量的信道数 */
    uint8_t measure_channel_list; /* 测量的信道号列表，bit0:信道8；bit1:信道9；bit2:信道10 */
    uint8_t measure_channel_num; /* 当前正在进行测量的信道 */
    uint16_t measure_event; /* 信道测量触发事件类型 ，取值为hmac_nbw_chan_measure_event_enum */
    uint32_t measure_time; /* 调用方指示的单个信道的测量时间 */
    frw_timeout_stru measure_timer; /* 信道测量定时器 */
    hmac_nbw_chan_measure_res_stru measure_res[NBW_MAX_CHANNLE_NUM]; /* 信道测量结果 */
} hmac_nbw_chan_measure_mgmt_stru;

/* 内联函数定义 */

/* 函数声明 */
hmac_nbw_chan_measure_res_stru *hmac_nbw_get_measure_res_pos(uint8_t channel_num);
hmac_nbw_chan_measure_mgmt_stru* hmac_nbw_get_channel_measure_info(void);
hmac_nbw_chan_measure_res_stru *hmac_nbw_get_channel_measure_res(void);
uint32_t hmac_nbw_channel_measure_end_process(void *arg);
uint32_t hmac_nbw_channel_measure_beacon_process(uint8_t *payload, uint32_t payload_len, uint8_t *domain_addr);
uint32_t hmac_nbw_channel_measure_request(hmac_vap_stru *hmac_vap, uint8_t channel_cnt, uint8_t channel_list,
    uint16_t event, uint32_t measure_time);
void hmac_nbw_clean_expire_res(uint8_t channel_list);
uint8_t hmac_nbw_get_measure_param_by_current_work_channel(hmac_vap_stru *hmac_vap);
hmac_nbw_chan_measure_res_stru *hmac_nbw_get_measure_res_pos(uint8_t channel_num);
void hmac_nbw_channel_measure_process_init(void);
#endif
#endif