/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat pm header file
 * Author: plat drivers
 */

#ifndef __PLAT_PM_H__
#define __PLAT_PM_H__

/* 其他头文件包含 */
#include "hw_bfg_ps.h"
#include "board.h"
#include "oal_list.h"
#include "cmsis_os2.h"

/* 宏定义 */
#define BFG_LOCK_NAME               "bfg_wake_lock"
#define BT_LOCK_NAME                "bt_wake_lock"
#define GNSS_LOCK_NAME              "gnss_wake_lock"

#define DEFAULT_WAKELOCK_TIMEOUT 2000 /* msec */

#define FIRMWARE_CFG_INIT_OK 0x01

#define SUCCESS 0
#define FAILURE 1

#define GNSS_AGREE_SLEEP     1
#define GNSS_NOT_AGREE_SLEEP 0

#define BFGX_SLEEP  0
#define BFGX_ACTIVE 1

#define HOST_DISALLOW_TO_SLEEP 0
#define HOST_ALLOW_TO_SLEEP    1

#define BFGX_PM_ENABLE  1
#define BFGX_PM_DISABLE 0

#define SLEEP_ACK_TIMEOUT_MSEC          500
#define WAIT_WKUP_DEVACK_TIMEOUT_MSEC   20

// 唤醒最长等待gpio irq时长, 参考AP侧的值，MCU侧GPIO中断可能由于系统调度原因响应慢
#define WAIT_WKUP_ACK_TOTAL             1500

#define SLEEP_10_MSEC              10
#define SLEEP_100_MSEC             100

#define WAIT_WKUPDEV_MSEC 10000

/* 睡眠超时时间设置成200ms, 避免蓝牙HCI命令间隙频繁唤醒 */
#define PLATFORM_SLEEP_TIME 200

/* 检查是否bfg timer工作正常,5s内无有mod timer, 异常处理,防止始终不睡眠 */
#define PL_CHECK_TIMER_WORK 5000

/* 检查是否gnss异常不投票睡眠的次数:5s */
#define PL_CHECK_GNSS_VOTE_CNT (5000 / PLATFORM_SLEEP_TIME)

enum UART_STATE_ENUM {
    UART_NOT_READY = 0,
    UART_READY = 1,
};

/* BFGX系统上电加载异常类型 */
enum BFGX_POWER_ON_EXCEPTION_ENUM {
    BFGX_POWER_FAILED = -1,
    BFGX_POWER_SUCCESS = 0,

    BFGX_POWER_PULL_POWER_GPIO_FAIL = 1,
    BFGX_POWER_TTY_OPEN_FAIL = 2,
    BFGX_POWER_TTY_FLOW_ENABLE_FAIL = 3,

    BFGX_POWER_WIFI_DERESET_BCPU_FAIL = 4,
    BFGX_POWER_WIFI_ON_BOOT_UP_FAIL = 5,

    BFGX_POWER_WIFI_OFF_BOOT_UP_FAIL = 6,
    BFGX_POWER_DOWNLOAD_FIRMWARE_FAIL = 7,

    BFGX_POWER_WAKEUP_FAIL = 8,
    BFGX_POWER_OPEN_CMD_FAIL = 9,

    BFGX_POWER_DOWNLOAD_FIRMWARE_INTERRUPT = 10,
    BFGX_POWER_ALREADY_DOWNLOAD = 11,   /* bfgx已加载 */

    BFGX_POWER_ENUM_BUTT,
};
typedef struct pm_task_info {
    osThreadId_t thread_id;
    osMessageQueueId_t event_queue;
    osMutexId_t work_mutex;
    osMutexId_t service_mutex;
} pm_task_info_t;

typedef struct {
    uint8_t pm_event;
} pm_work_t;

enum {
    PM_EVENT_SLEEP = 0,
    PM_EVENT_WAKEUP_ISR = 1,
    PM_EVENT_WAKEUP_DEV = 2,

    PM_EVENT_BUTT
};

typedef enum PM_NOTIFY_LEVEL {
    PM_NOTIFY_LEVEL_ERR = 0,
    PM_NOTIFY_LEVEL_INFO = 1,

    PM_NOTIFY_LEVEL_BUTT
} pm_notify_level_t;

typedef enum PM_STATUS_NOTIFY {
    PM_NOTIFY_SLEEP_SUCC = 0,
    PM_NOTIFY_SLEEP_FAIL = 1,
    PM_NOTIFY_WAKEUP_DEV_SUCC = 2,
    PM_NOTIFY_WAKEUP_DEV_FAIL = 3,
    PM_NOTIFY_SLEEP_CONTINUE_FAIL = 4,

    PM_NOTIFY_EVENT_BUTT
} pm_notify_event_t;

#define SLEEP_CONTINUE_FAIL_REPORT  20  // 连续20次sleep request失败
/* private data for pm driver */
struct pm_drv_data {
    struct ps_core_s *ps_core_data;
    int index;
    /* wake lock for bfg,be used to prevent host form suspend */
    oal_wakelock_stru bus_wake_lock;
    oal_wakelock_stru bt_wake_lock;
    oal_wakelock_stru gnss_wake_lock;

    /* dev state spinlock while wkup isr VS allow sleep ack */
    oal_spin_lock_stru state_spinlock;
    /* bfgx sleep state */
    uint8_t bfgx_dev_state;

    /* hal layer ioctl set flag not really close bt */
    uint32_t bt_fake_close_flag;

    /* bfg irq num */
    uint32_t bfg_irq;

    /* host2dev wakeup gpio */
    int32_t wakeup_dev_gpio;

    /* dev2host wakeup gpio */
    int32_t wakeup_host_gpio;

    /* debug count */
    uint32_t bfg_wakeup_host_cnt;
    uint32_t bfg_wakeup_dev_cnt;
    uint32_t bfg_sleep_cnt;
    uint32_t bfg_wakeup_fail_cnt;
    uint32_t bfg_sleep_fail_cnt;
    uint32_t bfg_sleep_fail_continue;

    uint32_t wakeup_src_debug;

    /* gnss lowpower state */
    oal_atomic_t gnss_sleep_flag;

    /* flag to mark whether enable lowpower or not */
    uint8_t bfgx_lowpower_enable;
    uint8_t bfgx_bt_lowpower_enable;
    uint8_t bfgx_gnss_lowpower_enable;

    pm_task_info_t pm_task;

    uint32_t uart_baud_switch_to;

    osTimerId_t sleep_timer;
    uint32_t sleep_period;

    osSemaphoreId_t sleep_work_sem;
    osSemaphoreId_t wakeup_work_sem;

    uint32_t pm_report_switch;  // 状态通知AP开关
};

struct pm_top {
    /* mutex for sync */
    oal_mutex_t host_mutex;
        /* flag for firmware cfg file init */
    unsigned long firmware_cfg_init_flag;
    struct pm_drv_data bfg_pm_info;
    struct pm_drv_data gnss_pm_info;
};

#define  index2name(index) (((index) == 0) ? "BUART" : "GUART")

/*
 * Prototype    : bfgx_set_pm_switch
 * Description  : set low power switch
 */
void bfgx_set_pm_switch(struct pm_drv_data *pm_data, uint8_t pm_switch);

/*
 * Prototype    : bfgx_set_sleep_period
 * Description  : set low power sleep timer timout
 */
void bfgx_set_sleep_period(struct pm_drv_data *pm_data, uint32_t value);

/*
 * Prototype    : bfg_wake_lock
 * Description  : get bfg wakelock
 */
void bfg_wake_lock(struct pm_drv_data *pm_data);
/*
 * Prototype    : bfg_wake_unlock
 * Description  : release bfg wakelock
 */
void bfg_wake_unlock(struct pm_drv_data *pm_data);
/*
 * Prototype    : bfgx_dev_state_set
 * Description  : set bfg lowpower state
 */
void bfgx_dev_state_set(struct pm_drv_data *pm_data, uint8_t state);
/*
 * Prototype    : bfgx_dev_state_get
 * Description  : get bfg lowpower state
 */
int32_t bfgx_dev_state_get(struct pm_drv_data *pm_data);
/* EXTERN FUNCTION */
struct pm_top* pm_get_top(void);
struct pm_drv_data *pm_get_drvdata(uint32_t index);
/*
 * Prototype    : bfgx_power_on
 * Description  : subsys power on
 */
int32_t bfgx_power_on(struct pm_drv_data *pm_data, uint32_t subsys);
/*
 * Prototype    : bfgx_power_off
 * Description  : subsys power off
 */
int32_t bfgx_power_off(struct pm_drv_data *pm_data, uint32_t subsys);

/*
 * Prototype    : prepare_to_visit_node
 * Description  : 应用线程访问设备前处理, 带唤醒设备功能，唤醒期间线程阻塞
 */
int32_t prepare_to_visit_node(struct ps_core_s *ps_core_d, int32_t *prepare_result);

/*
 * Prototype    : post_to_visit_node
 * Description  : 应用线程访问设备后处理
 */
void post_to_visit_node(struct ps_core_s *ps_core_d, int32_t prepare_result);
/*
 * Prototype    : bfg_sleep_timer_restart
 * Description  : sleep timer restart
 */
void bfg_sleep_timer_restart(struct pm_drv_data *pm_data);
int32_t ps_pm_register(struct ps_core_s *ps_core_d, int index);
int32_t ps_pm_unregister(struct ps_core_s *ps_core_d, int index);
int low_power_init(void);
void low_power_exit(void);
uint32_t pm_debug_cmd(const uint8_t *data, uint16_t data_len);

#endif
