/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: pm_wlan.c header file
 * Author: dpa drivers
 */

#ifndef PM_WLAN_H
#define PM_WLAN_H

#include <stdint.h>
#include "oal_net.h"
#include "oal_types.h"
#include "oal_mutex.h"
#include "mdrv_kevent.h"
#include "mdrv_sem.h"
#include "bsp_timer.h"
#include "oal_pm.h"

#define PM_WLAN_EVENT_MODE      (OS_EVENT_ANY)
#define PM_WLAN_THREAD_SIZE     0x800

#define DPA_DISALLOW_TO_SLEEP 0
#define DPA_ALLOW_TO_SLEEP    1

#define DPA_SLEEP_TIMER_PERIOD        20000    /* 20ms */
#define DPA_SLEEP_DEFAULT_CHECK_CNT   5    /* 默认100ms */

#define WLAN_WAKUP_MSG_WAIT_TIMEOUT    3    /* 唤醒超时时间3S */
#define WLAN_SLEEP_MSG_WAIT_TIMEOUT    3    /* 睡眠超时时间3S */

#define WLAN_SRV_FORBID_SLEEP_MAX_CNT           150
#define WLAN_SRV_PRINT_DEBUG_TIMEOUT_MAX_CNT    150

// 唤醒源
#define WAKEUP_SOURCE_DPA     0
#define WAKEUP_SOURCE_ACPU    1

typedef enum {
    A2D_SLEEP_REQ_MSG = 0,        // A核发送睡眠请求
    A2D_DISALLOW_SLEEP_MSG = 1,    // A核发送不允许睡消息
    A2D_SLEEP_SUCC_MSG = 2,    // A核发送睡眠完成消息
    A2D_WAKEUP_REQ_MSG = 3,    // A核发送唤醒请求消息
    A2D_WAKEUP_REQ_ACK = 4,     // A核回应唤醒请求ACK
    A2D_WAKEUP_FAIL_MSG = 5,    // A核发送唤醒失败消息
    A2D_WAKEUP_SUCC_MSG = 6,    // A核发送唤醒完成消息
    A2D_DISABLE_PM_MSG = 7,     // A核通知关闭低功耗
    A2D_ENABLE_PM_MSG = 8,      // A核通知打开低功耗
    A2D_RX_MSG_BUTT
} pm_wlan_rx_msg_t;

typedef enum {
    D2A_ALLOW_SLEEP_MSG = 0,    // dpa告诉A核可以睡消息
    D2A_ALLOW_SLEEP_ACK = 1,    // DPA允许睡ACK
    D2A_DISALLOW_SLEEP_ACK = 2,    // dpa不允许睡ACK
    D2A_SLEEP_SUCC_ACK = 3,    // DPA回复睡眠完成ACK
    D2A_WAKEUP_REQ_MSG = 4,    // DPA 唤醒请求
    D2A_WAKEUP_REQ_ACK = 5,    // DPA回复A核唤醒请求ACK
    D2A_WAKEUP_SUCC_ACK = 6,    // dpa 回复唤醒完成ACK
    D2A_TX_MSG_BUTT
} pm_wlan_tx_msg_t;

typedef enum {
    DPA_ALLOW_SLEEP_EVENT    = 0x0,
    SLEEP_REQ_EVENT          = 0x1,
    DISALLOW_SLEEP_EVENT     = 0x2,
    SLEEP_SUCC_EVENT         = 0x3,
    WAKEUP_REQ_EVENT         = 0x4,
    WAKEUP_FAIL_EVENT        = 0x5,
    WAKEUP_SUCC_EVENT        = 0x6,
    DPA_EXCEPTION_EVENT      = 0x7,
    DPA_WLAN_CLOSE_EVENT     = 0x8,
    PM_THREAD_EVENT_BUFF
} pm_waln_thread_event_t;

typedef enum {
    POWER_STATE_SHUTDOWN = 0,
    POWER_STATE_OPEN = 1,
    POWER_STATE_BUTT = 2,
} power_state_enum;

enum DPA_WLAN_PM_SLEEP_STAGE {
    SLEEP_STAGE_INIT = 0,    // 初始
    SLEEP_REQ_RCV = 1,       // 收到sleep request
    SLEEP_DISALLOW_ACK = 2,  // 回复A核不允许睡
    SLEEP_DISALLOW_RCV = 3,  // 收到A核disallow sleep消息
    SLEEP_ETE_CLOSE = 4,     // 收到A核下电ete的消息
    SLEEP_SUCC = 5,          // 收到A核睡眠完成消息
};

enum DPA_WLAN_PM_WAKEUP_STAGE {
    WAKEUP_STAGE_INIT = 0,       // 初始
    WAKEUP_REQ_SND = 1,          // DPA发送wakeup request
    WAKEUP_REQ_RCV = 2,          // 收到A核wakeup request
    WAKEUP_ETE_OPEN = 3,         // 收到A核上电ete的消息
    WAKEUP_FAIL = 4,             // 收到A核唤醒失败的消息
    WAKEUP_SUCC = 5              // 收到A核唤醒完成的消息
};

typedef enum {
    DISALLOW_SLEEP_NONE = 0,             // 初始
    DISALLOW_SLEEP_POWER_SHUTDOWN = 1,   // wifi已下电
    DISALLOW_SLEEP_PM_NOT_ENABLE = 2,    // 低功耗未使能
    DISALLOW_SLEEP_WIFI_SRV_FORBID = 3,  // 业务不允许睡
    DISALLOW_SLEEP_DPA_DISALLOW = 4,     // DPA不允许睡
    DISALLOW_SLEEP_ETE_NOT_EMPTY = 5,    // ETE队列不为空
    DISALLOW_SLEEP_BUTT
} dpa_pm_disallow_sleep_cont_t;

typedef enum {
    STATE_SLEEP,
    STATE_WAKEUP,
    STATE_IDLE
} pm_state_t;

typedef int32_t (*pm_wlan_rx_msg_handler)(uint8_t);

typedef uint8_t (*wifi_srv_get_pm_pause_func)(void);
typedef void (*wifi_srv_open_notify)(uint8_t);
typedef void (*wifi_srv_pm_state_notify)(uint8_t);
typedef uint32_t (*wifi_srv_get_trx_cnt_func)(void);
typedef void (*wifi_srv_data_wkup_print_en_func)(int32_t);
typedef void (*wifi_srv_data_pm_print_func)(void);
struct wifi_srv_callback_handler {
    wifi_srv_get_pm_pause_func p_wifi_srv_get_pm_pause_func;    // 协议栈回调获取是否pause低功耗
    wifi_srv_open_notify p_wifi_srv_open_notify;                // WIFI开机成功后,通知业务侧
    wifi_srv_pm_state_notify p_wifi_srv_pm_state_notify;        // WIFI退出低功耗,通知业务侧开启定时器
    wifi_srv_get_trx_cnt_func p_wifi_srv_get_trx_cnt_func;      // 获取WIFI当个timer周期内的收发包统计
    wifi_srv_data_pm_print_func p_wifi_srv_data_pm_print_func;  // WIFI维测打印
};

typedef struct pm_wlan_thread_info {
    mdrv_task_id task_id;
    uint32_t event_type;
    void* stack_addr;
    uint8_t running_flag;
} pm_wlan_thread_info_t;

/* 二值信号量 */
typedef struct pm_wlan_smea_info {
    mdrv_sem_id sema_id;
    uint8_t state;              // 用于标识当前信号量状态
} pm_wlan_smea_info_t;

typedef struct pm_wlan_str {
    uint8_t wlan_pm_enable;                         // pm使能开关
    pm_wlan_smea_info_t wakeup_sema;                // 唤醒信号量
    pm_wlan_smea_info_t sleep_sema;                 // 睡眠信号量
    pm_wlan_thread_info_t pm_handler_thread;       // 低功耗线程包含线程事件
    pm_wlan_thread_info_t pm_idle_thread;           // 低功耗线程用于DPA唤醒A核事件处理
    timer_handle timer_handle;                      // 睡眠定时器
    struct dpm_ops dpm_operation;                   // dmp的suspend和resume

    volatile uint8_t wlan_power_state;              // dpa power on state
    volatile uint8_t dpa_allow_sleep;               // dpa 自身维护的允许睡状态
    volatile uint8_t wakeup_source;
    volatile uint8_t sleep_stage;                   // 睡眠过程阶段标识
    volatile uint8_t wakeup_stage;                  // 唤醒过程阶段标识
    volatile uint8_t acpu_state;                    // 用于标识device睡眠或者下电状态，不可用pcie访问
    volatile uint8_t dpa_exception_state;           // DPA异常状态

    uint8_t wakeup_err_count;                       // 允许连续唤醒失败次数
    uint8_t fail_sleep_count;                       // 允许连续睡眠失败次数

    uint32_t timeout_cnt;                           // timeout check cnt
    uint32_t timeout_curr_cnt;                      // timeout check current cnt
    uint32_t have_packet;
    uint32_t master_tx_cnt;                // 记录前一个睡眠周期超时时刻的tx packet个数
    uint32_t master_rx_cnt;                // 记录前一个睡眠周期超时时刻的rx packet个数
    uint32_t packet_cnt;                   // 单个睡眠周期内统计的packet个数
    uint32_t packet_total_cnt;             // 从上次唤醒至今的packet个数，定期输出for debug
    uint32_t timeout_cnt_for_debug;        // 用于定时打印维测的计数，依赖睡眠定时器
    uint32_t wkup_src_print_en;            // 用于唤醒源维测打印

    struct wifi_srv_callback_handler wifi_srv_handler;    // 业务回调

    uint8_t excep_id;

// 统计维测
    uint32_t open_cnt;
    uint32_t close_cnt;
    uint32_t suspend_resume_cnt;
    uint32_t wakeup_succ;
    uint32_t wakeup_fail;
    uint32_t wakeup_event_submit;
    uint32_t dpa_allow_sleep_cnt;
    uint32_t sleep_succ;
    uint32_t sleep_fail;
    uint32_t wifi_srv_sleep_forbid;
    uint32_t sleep_request_dpa_forbid;
    uint32_t sleep_request_host_forbid;
    uint32_t sleep_event_submit;
} pm_wlan_str_t;

/* pm_msg_t 结构体与a核上要保持一致, 两边需同时修改 */
typedef struct pm_msg_t {
    uint8_t msg_id;
    uint8_t msg_cont;
} pm_msg_t;

typedef enum {
    TRACE_PM_ENABLE = 0,
    TRACE_PM_DISABLE,
    TRACE_SLEEP_FAIL,
    TRACE_SLEEP_END,
    TRACE_WIFI_WAKEUP_START,
    TRACE_WIFI_WAKEUP_SUCC,
    TRACE_WIFI_WAKEUP_FAIL,
    TRACE_WAKEUP_SOURCE_ACPU,
    TRACE_WAKEUP_FAIL,
    TRACE_WAKEUP_END,
    TRACE_GET_WAKEUP_SEMA_FAIL,
    TRACE_GET_SLEEP_SEMA_FAIL,
    TRACE_RELEASE_WAKEUP_SEMA_FAIL,
    TRACE_RELEASE_SLEEP_SEMA_FAIL,
    TRACE_A2D_SLEEP_REQ,
    TRACE_A2D_DISALLOW_SLEEP,
    TRACE_A2D_SLEEP_SUCC,
    TRACE_A2D_WAKEUP_REQ,
    TRACE_A2D_WAKEUP_REQ_ACK,
    TRACE_A2D_WAKEUP_FAIL,
    TRACE_A2D_WAKEUP_SUCC,
    TRACE_D2A_ALLOW_SLEEP,
    TRACE_D2A_ALLOW_SLEEP_SEND_FAIL,
    TRACE_D2A_ALLOW_SLEEP_ACK,
    TRACE_D2A_ALLOW_SLEEP_ACK_SEND_FAIL,
    TRACE_D2A_DISALLOW_SLEEP_ACK,
    TRACE_D2A_DISALLOW_SLEEP_ACK_SEND_FAIL,
    TRACE_D2A_SLEEP_SUCC_ACK,
    TRACE_D2A_WAKEUP_SUCC_ACK,
    TRACE_D2A_WAKEUP_REQ,
    TRACE_D2A_WAKEUP_REQ_SEND_FAIL,
    TRACE_D2A_WAKEUP_REQ_ACK,
    TRACE_D2A_WAKEUP_REQ_ACK_SEND_FAIL,
    TRACE_BUTT,
} pm_trace_types_t;

typedef struct trace_per_node {
    uint8_t type;
    uint8_t core;
    uint16_t repeat_cnt;
    uint32_t slice;
} trace_per_node_t;

void pm_trace_node(uint8_t type);
void pm_trace_node_debug_print(void);
pm_wlan_str_t *get_pm_wlan_struct_info(void);
uint8_t pm_wlan_idle_thread_should_stop(void);
uint8_t pm_wlan_handler_thread_should_stop(void);
int32_t pm_wlan_event_send_to_pm_process_thread(uint16_t event);
void pm_wlan_set_wkup_sleep_stage(uint8_t state, uint8_t pm_stage);
uint32_t wlan_pm_enable(void);
uint32_t wlan_pm_disable(void);
uint8_t pm_wlan_dpa_get_acpu_state(void);
uint32_t wlan_pm_try_wakeup_dev_lock(void);
void wlan_pm_wkup_src_debug_set(uint32_t en);
uint32_t wlan_pm_wkup_src_debug_get(void);
int32_t pm_wlan_reset_sleep_timer(void);
int32_t pm_wlan_close_sleep_timer(void);
int32_t pm_wlan_wakeup_dpa_handler(uint8_t wake_source);
int32_t pm_wlan_dpa_wakeup_acpu_handler_lock(void);
struct wifi_srv_callback_handler *wlan_pm_get_wifi_srv_handler(void);
int32_t pm_wlan_init(void);
int32_t pm_wlan_deinit(void);
int32_t pm_wlan_module_init(void);
int32_t pm_wlan_module_deinit(void);

#endif // PM_WLAN_H