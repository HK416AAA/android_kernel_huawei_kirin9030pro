/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: nbw connect mgnt
 * Author: wifi
 * Create: 2025-01-14
 */

#ifndef HMAC_NBW_COMMON_H
#define HMAC_NBW_COMMON_H

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_NBW_COMMON_H

#define MAX_ISLAND_SLOT_INFO_NUM 8
#define MAX_ISLAND_CNT 8
#define NBW_CHANNEL_NUM 3
#define MAX_CONNECTION_SLOT_INFO_NUM 4
#define NBW_MAX_TIMESLOT_BORROW_STOP_INFORM_CNT 2 /* 通知时隙借用重试最大次数 */

typedef struct {
    uint8_t channel_num;
    uint32_t last_timestamp; /* 上次切到该信道的时间戳 */
} chan_switch_timestamp_stru;

typedef struct {
    uint8_t freeze_detected_flag; /* 检测到卡顿标记 */
    uint8_t domain_merge_flag; /* 域切换标记，域合并开始时置true，结束后为false */
    uint8_t domain_merge_sync_flag; /* 域切换后是否与新域master同步上的标记 */
    uint8_t domain_merge_moving_status; /* 域切换运动状态， 域切换时向上层查询 */
    uint8_t max_domain_num; /* 选择进行域切换的域个数阈值 */
    uint8_t max_link_num; /* 选择进行域切换的连接数阈值 */
    uint8_t min_chan_switch_delta_time; /* 距上次切到某信道的最小等待时间差 */
    uint8_t domain_merge_sync_beacon_flag; /* 域切换后是否要立即同步，或者等下一个tbtt中断再同步 */
    uint8_t his_role; /* 域切换前历史角色信息 */
    uint8_t ask_for_sync_mgmt_type; /* 请求同步管理帧帧类型 */
    uint8_t ask_for_sync_cnt; /* 域合并流程请求同步发送的次数 */
    uint8_t domain_merge_notify_mgmt_type; /* 通知自身岛内其他设备域合并管理帧类型 */
    uint8_t domain_merge_notify_cnt; /* 通知自身岛内其他设备域合并管理帧帧发送次数 */
    uint8_t his_bssid[OAL_MAC_ADDR_LEN]; /* 历史域bssid */
    master_info master_info; /* 域合并的目标master信息 */
} hmac_nbw_domain_merge_info;

/* 描述单次申请的uslot bitmap情况, 当前默认repeat cnt为12，后续可以增加该元素 */
typedef struct {
    uint8_t start_idx;
    uint8_t end_idx;
    uint8_t uslot_bitmap;
    uint8_t timeslot_interval;
    uint8_t shared_flag; /* 是否允许共享，cpe业务申请的时隙该flag要置位 */
    uint8_t is_timeslot_borrowed; /* 是否存在时隙借用 */
    uint8_t work_uslot_bitmap; /* 当前设备实际工作（借用）的uslot_bitmap */
} hmac_nbw_uslot_info_stru;


typedef struct {
    uint8_t use_flag;
    uint8_t peer_device_mac[OAL_MAC_ADDR_LEN];
    uint8_t slot_period_level;
    hmac_nbw_uslot_info_stru uslot_info;  // 目前先实现一个链路只能申请一次时隙，后续再扩展
} hmac_nbw_slot_info_stru;

typedef struct {
    uint8_t link_cnt;
    hmac_nbw_slot_info_stru device_slot_info[MAX_ISLAND_SLOT_INFO_NUM]; /* 该设备的时隙信息，可能有多个岛主的情况 */
} hmac_nbw_slave_info_stru;

typedef struct {
    uint8_t connect_status; /* 当前连接的阶段, 状态包括0: 建链协商中；1：建链关联中 */
    uint8_t connect_role; /* 设备在当前连接中的角色 */
    uint8_t peer_addr[OAL_MAC_ADDR_LEN]; /* 当前连接的对端设备地址 */
    uint8_t op_id; /* 命令ID */
    uint8_t conn_flag;
    mac_status_code_enum_uint16 status_code; /* 反馈给上层的建链结果码 */
    uint32_t connect_timeout; /* 上层下发的连接超时时间 */
    frw_timeout_stru assoc_waiting_timer;
} hmac_nbw_current_connect_info_stru;

typedef enum {
    NBW_TIMESLOT_STOP_INVALID = 0,
    NBW_MASTER_SLAVE_TIMESLOT_BORROW = 1,
    NBW_SLAVEAP_SLAVE_TIMESLOT_BORROW = 2,
    NBW_MASTER_SLAVEAP_TIMESLOT_BORROW = 3,
} timeslot_borrow_request_enum;

/* 时隙借用通知结构体 */
typedef struct {
    timeslot_borrow_request_enum request_flag; /* 发起通知的类型，当前为master通知关联的slave、master通知域内slaveap、slaveap通知关联slave */
    uint8_t confirm_flag; /* 通知端收到对端的rsp确认帧 */
    uint8_t retry_cnt; /* 通知重试次数 */
    uint8_t old_work_timeslot; /* 保存原工作时隙 */
    hmac_nbw_slot_info_stru send_slot_info; /* 更新后的全域时隙信息 */
    uint8_t peer_addr[OAL_MAC_ADDR_LEN]; /* 通知的slaveap或slave的地址 */
    uint8_t slave_addr[OAL_MAC_ADDR_LEN];
} hmac_nbw_timeslot_borrow_info_stru;
#endif