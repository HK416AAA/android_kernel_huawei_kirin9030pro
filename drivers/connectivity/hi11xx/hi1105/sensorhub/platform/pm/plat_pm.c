/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for pm
 * Author: plat drivers
 */

#define USE_LOG_TAG_FUNC
#define pr_fmt(fmt) "2[hisi_plat]" fmt

#include <osal.h>
#include "oal_util.h"
#include "board.h"
#include "bfgx_dev.h"
#include "plat_uart.h"
#include "hw_bfg_ps.h"
#include "bfgx_data_parse.h"
#include "securec.h"
#include "oal_ext_if.h"
#include "plat_debug.h"
#include "plat_main.h"
#include "plat_ipc.h"
#include "hal_gpio.h"
#include "hal_pm.h"
#include "plat_exception_rst.h"
#include "plat_pm.h"

#define FEATURE_H2D_GPIO_WKUP  1

#define TASK_PRIORITY_PM     (osPriorityHigh)
#define TASK_STACKSIZE_PM     0x1000
#define QUEUE_PM_EVENT_LEN    16

#ifdef FEATURE_H2D_GPIO_WKUP
#define WAIT_CFG_GPIO_WKUP_MODE_TIME 50
#endif

#define DEV_WAKEUP_MCU_GPIO    (175)
#define MCU_WAKEUP_DEV_GPIO    (198)

#define LOW_POWER_UART_BAUD    115200

// 低功耗全局变量
struct pm_top g_pm_top;

#ifdef PLATFORM_DEBUG_ENABLE
#define PM_DEBUG_PARA_MAX  4   // 命令最多4个参数

typedef enum {
    PM_DEBUG_REPORT_SWITCH = 0,
    PM_DEBUG_WKUP_TEST = 1,
    PM_DEBUG_SLEEP_PERIOD_SET = 2,

    PM_DEBUG_ID_BUTT,
} pm_debug_id_t;

STATIC uint32_t pm_debug_wkup_test(struct pm_drv_data *pm_data)
{
    int32_t prepare_result;

    if (prepare_to_visit_node(pm_data->ps_core_data, &prepare_result) < 0) {
        PRINT_ERR("prepare work fail");
        return OAL_FAIL;
    }

    ps_tx_sys_cmd(pm_data->ps_core_data, SYS_MSG, PL_PM_DEBUG);

    post_to_visit_node(pm_data->ps_core_data, prepare_result);
    return OAL_SUCC;
}

STATIC void pm_set_report_switch(struct pm_drv_data *pm_data, uint32_t value)
{
    pm_data->pm_report_switch = value;
    PRINT_INFO("pm_set_report_switch %d", value);
}

/*
* 命令格式：pm_debug,xxx,yyy
* xxx: uart index
* yyy: debug cmd index
*/
uint32_t pm_debug_cmd(const uint8_t *data, uint16_t data_len)
{
    char *ptr = (char *)data;
    char *token = NULL;
    char *next_token = NULL;
    uint32_t uart = 0;
    uint32_t debug_id = 0;
    uint32_t tmp[PM_DEBUG_PARA_MAX] = {0};
    uint8_t idx = 0;

    token = strtok_s((char*)ptr, ",", &next_token); // 第1个分段是key
    token = strtok_s(NULL, ",", &next_token);       // 第2个分段开始是参数
    while (token != NULL) {
        tmp[idx++] = strtoul(token, NULL, 10); // 10: 十六进制
        token = strtok_s(NULL, ",", &next_token);
        if (idx >= PM_DEBUG_PARA_MAX) {
            break;
        }
    }
    PRINT_INFO("pm_debug %d %d %d", tmp[0], tmp[1], tmp[2]); // 0:uart;1:id;2:para

    uart =  tmp[0];      // 0: 第一个参数固定是uart index
    debug_id = tmp[1];   // 1: 第二个参数固定是id

    if (uart >= UART_BUTT || debug_id >= PM_DEBUG_ID_BUTT) {
        PRINT_ERR("pm_debug para error");
        return OAL_FAIL;
    }
    struct pm_drv_data *pm_data = pm_get_drvdata(uart);
    switch (debug_id) {
        case PM_DEBUG_REPORT_SWITCH:
            pm_set_report_switch(pm_data, tmp[2]); // 2: report开关命令的第3个参数是开关值
            break;
        case PM_DEBUG_WKUP_TEST:
            pm_debug_wkup_test(pm_data);
            break;
        case PM_DEBUG_SLEEP_PERIOD_SET:
            bfgx_set_sleep_period(pm_data, tmp[2]); // 2: 睡眠周期命令的第3个参数是睡眠定时器周期值
            break;
        default:
            break;
    }
    return OAL_SUCC;
}
#endif

int32_t pm_task_add_work(struct pm_drv_data *pm_data, uint8_t event);

// 外部获取低功耗结构体接口
struct pm_top* pm_get_top(void)
{
    return &g_pm_top;
}

struct pm_drv_data *pm_get_drvdata(uint32_t index)
{
    struct pm_top* pm_top_data = pm_get_top();
    struct pm_drv_data *pm_data;

    if (index == BUART) {
        pm_data = &(pm_top_data->bfg_pm_info);
    } else {
        pm_data = &(pm_top_data->gnss_pm_info);
    }
    return (index < UART_BUTT) ? pm_data : NULL;
}

STATIC struct ps_core_s *pm_get_core(struct pm_drv_data *pm_data)
{
    return pm_data->ps_core_data;
}

void bfgx_dev_state_set(struct pm_drv_data *pm_data, uint8_t state)
{
    oal_uint flags;
    if (pm_data == NULL) {
        PRINT_ERR("pm_data is NULL!");
        return;
    }

    oal_spin_lock_irq_save(&pm_data->state_spinlock, &flags);
    pm_data->bfgx_dev_state = state;
    oal_spin_unlock_irq_restore(&pm_data->state_spinlock, &flags);
}

int32_t bfgx_dev_state_get(struct pm_drv_data *pm_data)
{
    oal_uint flags;
    int32_t ret;
    oal_spin_lock_irq_save(&pm_data->state_spinlock, &flags);
    ret = pm_data->bfgx_dev_state;
    oal_spin_unlock_irq_restore(&pm_data->state_spinlock, &flags);
    return ret;
}

void bfgx_set_pm_switch(struct pm_drv_data *pm_data, uint8_t pm_switch)
{
    if (pm_data == NULL) {
        return;
    }
    PRINT_INFO("[%s]bfgx_set_pm_switch[%d]", index2name(pm_data->index), pm_switch);
    pm_data->bfgx_lowpower_enable = pm_switch;
}

void bfgx_set_sleep_period(struct pm_drv_data *pm_data, uint32_t value)
{
    if (value == 0) {
        return;
    }
    pm_data->sleep_period = value;
    PRINT_INFO("pm_set_sleep_period %d ms", value);
}

/*
 * Prototype    : bfgx_pm_status_notify
 * Description  : 低功耗关键事件通知AP侧
 * Input        : level: 事件的等级，ERR | INFO
 *                event：报告的事件
 */
void bfgx_pm_status_notify(struct pm_drv_data *pm_data, pm_notify_level_t level, pm_notify_event_t event)
{
    hw_plat_ipc_ctx_t *ctx = hw_plat_get_ipc_ctx();
    mcu_pm_status_notify_t  cmd;
    uint32_t mask = 1 << level;

    /* 根据level和设置的report开关做过滤，默认ERROR等级的通知AP, debug时可以通过命令：
       hdc shell echo "pm_debug,0,0,3 > /sys/hi110x_debug/mcu_dbg" 使能INFO级别的notify */
    if ((mask & pm_data->pm_report_switch) == 0) {
        return;
    }

    cmd.ipc_hdr.msg_code = BFGN_OP_CODE_PM_STATUS_NOTIFY;
    cmd.ipc_hdr.msg_len = sizeof(mcu_pm_status_notify_t);
    cmd.ipc_hdr.seq = ctx->seq++;
    cmd.level = level;
    cmd.event = event;

    plat_ipc_send_cmd(CMD_CONNECT_MCU_TO_AP, (const uint8_t *)&cmd, sizeof(mcu_pm_status_notify_t));
}

void bfg_wake_lock(struct pm_drv_data *pm_data)
{
    if (pm_data == NULL) {
        return;
    }
    enum cpuidle_usr usr = (pm_data->index == BUART) ? PM_USR_BT : PM_USR_GNSS;

    hal_cpuidle_request(usr, PM_WFI);
}

void bfg_wake_unlock(struct pm_drv_data *pm_data)
{
    if (pm_data == NULL) {
        return;
    }
    enum cpuidle_usr usr = (pm_data->index == BUART) ? PM_USR_BT : PM_USR_GNSS;
    hal_cpuidle_release(usr, PM_WFI);
}

STATIC bool bfgx_subsys_all_shutdown(struct pm_drv_data *pm_data)
{
    int32_t i = 0;
    struct ps_core_s *ps_core_d = pm_get_core(pm_data);

    if (ps_core_d == NULL) {
        PRINT_ERR("ps_core_d is NULL");
        return true;
    }

    for (i = 0; i < BFGX_BUTT; i++) {
        if (oal_atomic_read(&ps_core_d->bfgx_info[i].subsys_state) == POWER_STATE_OPEN) {
            return false;
        }
    }

    return true;
}

int32_t bfgx_power_on(struct pm_drv_data *pm_data, uint32_t subsys)
{
    uint32_t int_flag;
    if (subsys >= BFGX_BUTT) {
        return BFGX_POWER_FAILED;
    }

    int_flag = osa_int_lock();
    if (ps_bfg_subsys_active(subsys) == true) {
        osa_int_restore(int_flag);
        PRINT_ERR("bfgx_power sys[%d] already open", subsys);
        return BFGX_POWER_SUCCESS;
    }

    bfg_wake_lock(pm_data);
    if (bfgx_subsys_all_shutdown(pm_data)) {
        // 打开GPIO中断
        hal_gpio_irq_enable_conn(pm_data->wakeup_host_gpio, IRQ_ENABLE);

        // 首次上电清理异常标记位
        plat_exception_reset_clear();
    }

    ps_set_subsys_state(subsys, POWER_STATE_OPEN);
    osa_int_restore(int_flag);
    return BFGX_POWER_SUCCESS;
}

int32_t bfgx_power_off(struct pm_drv_data *pm_data, uint32_t subsys)
{
    uint32_t int_flag;
    if (subsys >= BFGX_BUTT) {
        return BFGX_POWER_FAILED;
    }

    int_flag = osa_int_lock();
    if (ps_bfg_subsys_active(subsys) == false) {
        osa_int_restore(int_flag);
        PRINT_ERR("bfgx_power sys[%d] already close", subsys);
        return BFGX_POWER_SUCCESS;
    }

    ps_set_subsys_state(subsys, POWER_STATE_SHUTDOWN);

    if (bfgx_subsys_all_shutdown(pm_data)) {
        // 停止timer, 低功耗线程事件清0
        osTimerStop(pm_data->sleep_timer);
        while (osMessageQueueGetSpace(pm_data->pm_task.event_queue) < QUEUE_PM_EVENT_LEN) {
            pm_work_t work;
            osMessageQueueGet(pm_data->pm_task.event_queue, &work, NULL, osWaitForever);
        }
        // 清理uart发送队列
        bfgn_uart_tx_queue_clear(pm_data->ps_core_data->tty.uart);

        // 关闭GPIO中断
        hal_gpio_irq_enable_conn(pm_data->wakeup_host_gpio, IRQ_DISABLE);
        bfg_wake_unlock(pm_data);
    }
    osa_int_restore(int_flag);
    return BFGX_POWER_SUCCESS;
}

#ifndef FEATURE_H2D_GPIO_WKUP
STATIC int32_t ps_change_baud_rate_retry(struct ps_core_s *ps_core_d, long baud_rate, uint8_t flowctl_status)
{
    return OAL_TRUE;
}

STATIC int32_t process_host_wkup_dev_fail(struct ps_core_s *ps_core_d, struct pm_drv_data *pm_data)
{
    return OAL_FALSE;
}
#endif

STATIC int32_t wait_wakeup_dev_ack(struct pm_drv_data *pm_data)
{
    // 等待gpio irq最大时长, 参考AP侧的值设置为1500ms，MCU侧GPIO中断可能由于系统调度原因响应慢, 间隔20ms检查一次状态
    int32_t wait_cnt = WAIT_WKUP_ACK_TOTAL / WAIT_WKUP_DEVACK_TIMEOUT_MSEC;
    while (wait_cnt--) {
        oal_msleep(WAIT_WKUP_DEVACK_TIMEOUT_MSEC);
        if ((gpio_get_value(pm_data->wakeup_host_gpio) == GPIO_HIGHLEVEL) &&
            (bfgx_dev_state_get(pm_data) == BFGX_ACTIVE)) {
            return OAL_SUCC;
        }
    }
    PRINT_ERR("wait_wakeup_dev_ack fail, gpio_level=%d,state=%d",
              gpio_get_value(pm_data->wakeup_host_gpio), bfgx_dev_state_get(pm_data));

    return -OAL_FAIL;
}

STATIC int32_t host_wkup_dev_via_gpio(struct ps_core_s *ps_core_d, struct pm_drv_data *pm_data)
{
    const uint32_t wkup_retry = 2;
    int32_t ret;
    int bwkup_gpio_val = 0;
    uint32_t i;

    for (i = 0; i < wkup_retry; i++) {
        bwkup_gpio_val = gpio_get_value(pm_data->wakeup_host_gpio);
        PRINT_INFO("bfg wakeup dev,try %u, cur dev2mcu gpio:%u", i + 1, bwkup_gpio_val);

        gpio_set_value(pm_data->wakeup_dev_gpio, GPIO_LOWLEVEL);
        oal_udelay(200); // 200us采样
        gpio_set_value(pm_data->wakeup_dev_gpio, GPIO_HIGHLEVEL);

        // DE2MCU GPIO拉高 + GPIO中断响应才算完成
        if (wait_wakeup_dev_ack(pm_data) == OAL_SUCC) {
            bfgx_pm_status_notify(pm_data, PM_NOTIFY_LEVEL_INFO, PM_NOTIFY_WAKEUP_DEV_SUCC);
            return OAL_TRUE;
        }
    }
    pm_data->bfg_wakeup_fail_cnt++;
    bfgx_pm_status_notify(pm_data, PM_NOTIFY_LEVEL_ERR, PM_NOTIFY_WAKEUP_DEV_FAIL);
    return OAL_FALSE;
}

STATIC int32_t host_do_wakeup(struct pm_drv_data *pm_data)
{
    int32_t ret = OAL_TRUE;

    ret = host_wkup_dev_via_gpio(pm_data->ps_core_data, pm_data);
    if (ret != OAL_TRUE) {
        PRINT_ERR("host gpio wkup bfg fail");
    }

    return ret;
}

STATIC int32_t sleep_timer_expire_param_check(struct pm_drv_data *pm_data)
{
    if (oal_unlikely(pm_data == NULL)) {
        PRINT_ERR("pm_data is null");
        return OAL_FALSE;
    }

    if (pm_data->bfgx_lowpower_enable == BFGX_PM_DISABLE) {
        PRINT_INFO("lowpower function disabled");
        return OAL_FALSE;
    }
    if (bfgx_dev_state_get(pm_data) == BFGX_SLEEP) {
        PRINT_INFO("dev has been sleep");
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

/*
 * Prototype    : sleep_timer_expire
 * Description  : bfg timer expired function
 */
STATIC void bfg_sleep_timer_expire(void* arg)
{
    struct pm_drv_data *pm_data = (struct pm_drv_data *)arg;

    if (sleep_timer_expire_param_check(pm_data) == OAL_FALSE) {
        return;
    }

    /* 睡眠周期内没有收发数据, 提交睡眠事件 */
    if ((get_uart_tx_cnt(pm_data->index) == 0) && (get_uart_rx_cnt(pm_data->index) == 0)) {
        if (pm_task_add_work(pm_data, PM_EVENT_SLEEP) != OAL_SUCC) {
            bfg_sleep_timer_restart(pm_data);
        }
    } else {
        /* 清零相关计数重新开始下次检测触发 */
        clear_uart_tx_cnt(pm_data->index);
        clear_uart_rx_cnt(pm_data->index);
        bfg_sleep_timer_restart(pm_data);
    }
}

STATIC int32_t wait_wakeup_dev_complete(struct pm_drv_data *pm_data)
{
    osStatus_t status = osSemaphoreAcquire(pm_data->wakeup_work_sem, WAIT_WKUPDEV_MSEC);
    if (((bfgx_dev_state_get(pm_data) != BFGX_ACTIVE))) {
        PRINT_ERR("[%s]wait wake up dev timeout", index2name(pm_data->index));
        return -ETIMEDOUT;
    }

    return SUCCESS;
}

STATIC int32_t host_wakeup_dev(struct pm_drv_data *pm_data)
{
    if (bfgx_dev_state_get(pm_data) == BFGX_ACTIVE) {
        return SUCCESS;
    }
    bfg_wake_lock(pm_data);

    pm_data->bfg_wakeup_dev_cnt++;
    PRINT_INFO("wkup start, wkup_dev %d, wkup_host %d, wkup_fail %d, sleep_cnt %d, sleep_fail %d",
               pm_data->bfg_wakeup_dev_cnt, pm_data->bfg_wakeup_host_cnt, pm_data->bfg_wakeup_fail_cnt,
               pm_data->bfg_sleep_cnt, pm_data->bfg_sleep_fail_cnt);

    if (pm_task_add_work(pm_data, PM_EVENT_WAKEUP_DEV) != OAL_SUCC) {
        return -FAILURE;
    }
    /* 有信号量获取操作，不支持重入 */
    return wait_wakeup_dev_complete(pm_data);
}

/*
 * Prototype    : prepare_to_visit_node
 * Description  : 应用线程访问设备前处理, 带唤醒设备功能，唤醒期间线程阻塞
 */
int32_t prepare_to_visit_node(struct ps_core_s *ps_core_d, int32_t *prepare_result)
{
    struct pm_drv_data *pm_data = NULL;

    *prepare_result = -EFAULT;
    pm_data = ps_core_d->pm_data;
    if (oal_unlikely(pm_data == NULL)) {
        PRINT_ERR("pm_data is NULL!");
        return -EFAULT;
    }
    if (pm_data->bfgx_lowpower_enable == BFGX_PM_DISABLE) {
        return SUCCESS;
    }

    oal_atomic_inc(&ps_core_d->node_visit_flag); /* mark someone is visiting dev node */
    /* 多业务线程并发时，只能有个1线程触发唤醒，其它线程阻塞等待 */
    osMutexAcquire(pm_data->pm_task.service_mutex, osWaitForever);
    if (host_wakeup_dev(pm_data) != 0) {
        osMutexRelease(pm_data->pm_task.service_mutex);
        oal_atomic_dec(&ps_core_d->node_visit_flag);
        PRINT_ERR("[%s]wkup device FAILED, bring to reset work!", index2name(pm_data->index));
        plat_exception_handler(SUBSYS_BFGX, BFGX_WAKEUP_FAIL, NULL, 0);
        return -EIO;
    }
    osMutexRelease(pm_data->pm_task.service_mutex);
    *prepare_result = SUCCESS;
    return SUCCESS;
}

/* we should do something before exit from visiting dev_node */
void post_to_visit_node(struct ps_core_s *ps_core_d, int32_t prepare_result)
{
    struct pm_drv_data *pm_data = NULL;

    pm_data = ps_core_d->pm_data;
    if (oal_unlikely(pm_data == NULL)) {
        PRINT_ERR("pm_data is NULL!");
        return;
    }

    if (oal_unlikely(prepare_result != SUCCESS)) {
        PRINT_WARN("[%s]node_visit_flag[%d] is not need decrease", index2name(pm_data->index),
                   oal_atomic_read(&ps_core_d->node_visit_flag));
        return;
    }

    oal_atomic_dec(&ps_core_d->node_visit_flag);

    return;
}

/*
 * Prototype    : bfg_wake_host_isr
 * Description  : functions called when bt wake host via GPIO
 */
STATIC void bfg_wake_host_isr(void *arg)
{
    oal_uint flags;

    struct pm_drv_data *pm_data = (struct pm_drv_data*)arg;
    if (pm_data == NULL) {
        PRINT_ERR("pm_data is NULL!");
        return;
    }

    pm_data->bfg_wakeup_host_cnt++;
    pm_data->wakeup_src_debug = 1;

    PRINT_INFO("bfg_wake_host_isr wkup_dev %d, wkup_host %d, sleep_cnt %d",
               pm_data->bfg_wakeup_dev_cnt, pm_data->bfg_wakeup_host_cnt, pm_data->bfg_sleep_cnt);

    bfg_wake_lock(pm_data);
    bfgx_dev_state_set(pm_data, BFGX_ACTIVE);

    pm_task_add_work(pm_data, PM_EVENT_WAKEUP_ISR);
    return;
}

int32_t low_power_probe_timer_init(struct pm_drv_data *pm_data)
{
    pm_data->sleep_timer = osTimerNew(bfg_sleep_timer_expire, osTimerOnce, pm_data, NULL);
    if (pm_data->sleep_timer == NULL) {
        PRINT_ERR("Failed to create sleep timer!");
        return -OAL_FAIL;
    }
    pm_data->sleep_period = PLATFORM_SLEEP_TIME;
    return OAL_SUCC;
}

void low_power_timer_deinit(struct pm_drv_data *pm_data)
{
    if (pm_data->sleep_timer != NULL) {
        osTimerStop(pm_data->sleep_timer);
        osTimerDelete(pm_data->sleep_timer);
        pm_data->sleep_timer = NULL;
    }
}

void bfg_sleep_timer_restart(struct pm_drv_data *pm_data)
{
    osStatus_t status;

    osTimerStop(pm_data->sleep_timer);
    status = osTimerStart(pm_data->sleep_timer, pm_data->sleep_period);
    if (status != osOK) {
        PRINT_ERR("[0x%x] Failed to start sleep timer!", status);
    }
}

int low_power_gpio_init(struct pm_drv_data *pm_data)
{
    int32_t ret;

    PRINT_INFO("low_power_gpio_init:enter");
    pm_data->wakeup_host_gpio = DEV_WAKEUP_MCU_GPIO;
    hal_gpiomux_set_iocg(pm_data->wakeup_host_gpio, PINMUX_PULL_DOWN, PINMUX_SLEW_NONSET, PINMUX_2MA);
    hal_gpiomux_set_iomg(pm_data->wakeup_host_gpio, PINMUX_M0);
    hal_gpio_direction_input(pm_data->wakeup_host_gpio);
    ret = hal_gpio_irq_request(pm_data->wakeup_host_gpio, bfg_wake_host_isr, pm_data, IRQ_TYPE_EDGE_RISING);
    if (ret != SUCCESS) {
        PRINT_ERR("low_power_gpio_init: request irq for wakeup_host_gpio err, ret[%d]", ret);
        return ret;
    }
    hal_gpio_irq_enable_conn(pm_data->wakeup_host_gpio, IRQ_DISABLE);
#ifdef FEATURE_H2D_GPIO_WKUP
    pm_data->wakeup_dev_gpio = MCU_WAKEUP_DEV_GPIO;
    hal_gpiomux_set_iocg(pm_data->wakeup_dev_gpio, PINMUX_PULL_DOWN, PINMUX_SLEW_NONSET, PINMUX_2MA);
    hal_gpiomux_set_iomg(pm_data->wakeup_dev_gpio, PINMUX_M0);
    hal_gpio_direction_output(pm_data->wakeup_dev_gpio);
    hal_gpio_set_value(pm_data->wakeup_dev_gpio, GPIO_LOWLEVEL);
#endif
    return OAL_SUCC;
}

void low_power_gpio_deinit(struct pm_drv_data *pm_data)
{
    hal_gpio_free_irq(pm_data->wakeup_host_gpio);
}

int32_t bfg_enter_sleep_check(struct pm_drv_data *pm_data)
{
    struct ps_core_s *ps_core_d = pm_data->ps_core_data;
    /* if someone is visiting the dev_node */
    if (oal_atomic_read(&ps_core_d->node_visit_flag) > 0) {
        PRINT_INFO("[%s]someone visit node, not send allow sleep msg", index2name(pm_data->index));
        return -FAILURE;
    }

    if (bfgx_dev_state_get(pm_data) == BFGX_SLEEP) {
        PRINT_INFO("[%s]bfgx already sleep!", index2name(pm_data->index));
        return -FAILURE;
    }
    return SUCCESS;
}

STATIC int32_t wait_sleep_cmd_ack(struct pm_drv_data *pm_data)
{
    int32_t allow_sleep =  OAL_FALSE;
    uint32_t sem_count = osSemaphoreGetCount(pm_data->sleep_work_sem);
    osStatus_t status = osSemaphoreAcquire(pm_data->sleep_work_sem, SLEEP_ACK_TIMEOUT_MSEC);

    /* 当UART Tx或rx调度慢时, 可能上一次睡眠命令处理中，芯片应答的消息在timeout后才得到处理，osSemaphoreRelease导致sem count当前值非0,
    本次睡眠命令中osSemaphoreAcquire马上能获取到，达不到阻塞等待芯片应答的目的, 需oal_msleep等待芯片应答 */
    if (sem_count > 0) {
        PRINT_INFO("uart tx or rx schedule maybe slow, sem pre_count %d", sem_count);
        oal_msleep(SLEEP_ACK_TIMEOUT_MSEC);
    }

    if ((gpio_get_value(pm_data->wakeup_host_gpio) == GPIO_LOWLEVEL) &&
        (bfgx_dev_state_get(pm_data) == BFGX_SLEEP)) {
        // case1: 芯片收到sleep cmd，拉低GPIO做为应答
        allow_sleep = OAL_TRUE;
        bfg_wake_unlock(pm_data);
        pm_data->bfg_sleep_cnt++;
        pm_data->bfg_sleep_fail_continue = 0;  // 连续sleep fail计数清零
    } else {
        // case2: rcv not agress sleep msg or device wakeup MCU, is normal
        allow_sleep = OAL_FALSE;

        // case3: no response timeout, is not normal
        if ((bfgx_dev_state_get(pm_data) == BFGX_SLEEP) && status != osOK) {
            pm_data->bfg_sleep_fail_continue++;
        }
    }

    PRINT_INFO("wait device sleep ack complete, allow_sleep=%d, sem pre_count %d, acq status %d, ddr_vote %d",
               allow_sleep, sem_count, status, oal_get_ddr_vote_cnt());

    return allow_sleep;
}

STATIC int32_t host_allow_bfg_sleep_cmd(struct pm_drv_data *pm_data)
{
    /* 设置device状态为睡眠态，在host唤醒dev完成之前(或dev唤醒host前)uart不可用 */
    bfgx_dev_state_set(pm_data, BFGX_SLEEP);

    if (ps_tx_sys_cmd(pm_get_core(pm_data), SYS_MSG, SYS_CFG_ALLOWDEV_SLP) != 0) {
        PRINT_ERR("SYS_CFG_ALLOWDEV_SLP MSG send fail");
        pm_data->bfg_sleep_fail_continue++;
        bfgx_dev_state_set(pm_data, BFGX_ACTIVE);
        bfg_sleep_timer_restart(pm_data);
        return -OAL_FAIL;
    }
    // 等待ack
    if (wait_sleep_cmd_ack(pm_data) == OAL_TRUE) {
        return OAL_SUCC;
    } else {
        PRINT_INFO("wait device sleep ack fail, dev state[%d], ddr_vote %d",
                   bfgx_dev_state_get(pm_data), oal_get_ddr_vote_cnt());
        bfgx_dev_state_set(pm_data, BFGX_ACTIVE);
        bfg_sleep_timer_restart(pm_data);
        return -OAL_FAIL;
    }
}

STATIC void pm_bfg_sleep_work(struct pm_drv_data *pm_data)
{
    struct ps_core_s *ps_core_d = NULL;

    PRINT_INFO("[%s]timer_period=%d ms,dev2mcu gpio_level=%d",  __func__,
               pm_data->sleep_period, gpio_get_value(pm_data->wakeup_host_gpio));

    if (bfg_enter_sleep_check(pm_data) != SUCCESS) {
        bfg_sleep_timer_restart(pm_data);
        return;
    }

    if (host_allow_bfg_sleep_cmd(pm_data) == OAL_SUCC) {
        // sleep cmd成功, 才拉低GPIO
#ifdef FEATURE_H2D_GPIO_WKUP
        gpio_set_value(pm_data->wakeup_dev_gpio, GPIO_LOWLEVEL);
#endif
        bfgx_pm_status_notify(pm_data, PM_NOTIFY_LEVEL_INFO, PM_NOTIFY_SLEEP_SUCC);
    } else {
        // 连续N次sleep request失败, 大概率是异常, ERR级别通知AP
        if ((pm_data->bfg_sleep_fail_continue != 0) &&
            (pm_data->bfg_sleep_fail_continue % SLEEP_CONTINUE_FAIL_REPORT == 0)) {
            plat_exception_handler(SUBSYS_BFGX, BFGX_SLEEP_FAIL, NULL, 0);
        } else {
            bfgx_pm_status_notify(pm_data, PM_NOTIFY_LEVEL_INFO, PM_NOTIFY_SLEEP_FAIL);
        }
    }

    return;
}

STATIC void pm_bfg_wakeup_isr_work(struct pm_drv_data *pm_data)
{
    if (pm_data == NULL) {
        return;
    }

    /* unlikely case: 在提交disallow sleep work前, 队列中残留了一个allow sleep work未处理，
    导致disallow消息发送的时候，由于allow sleep消息先发下去了，芯片已经睡眠，disallow消息未发送成功 */
    if (bfgx_dev_state_get(pm_data) != BFGX_ACTIVE) {
        PRINT_ERR("[%s]device not in active, no msg could send,commit wkup work.", index2name(pm_data->index));
        pm_task_add_work(pm_data, PM_EVENT_WAKEUP_DEV);
        return;
    }

    if (ps_tx_sys_cmd(pm_get_core(pm_data), SYS_MSG, SYS_CFG_DISALLOW_SLP) != 0) {
        PRINT_INFO("[%s]SYS_CFG_DISALLOW_SLP MSG send fail", index2name(pm_data->index));
        return;
    }

    /* 启动sleep timer */
    bfg_sleep_timer_restart(pm_data);
    return;
}

STATIC void pm_bfg_wakeup_dev_work(struct pm_drv_data *pm_data)
{
    int32_t ret;

    if (bfgx_dev_state_get(pm_data) != BFGX_SLEEP) {
        // 如果已经是唤醒状态, 仅拉高GPIO作为ACK
        PRINT_INFO("pm_bfg_wakeup_dev_work already work: dev state %d, dev2mcu gpio %d",
                   bfgx_dev_state_get(pm_data), gpio_get_value(pm_data->wakeup_host_gpio));
#ifdef FEATURE_H2D_GPIO_WKUP
        gpio_set_value(pm_data->wakeup_dev_gpio, GPIO_HIGHLEVEL);
#endif
        osSemaphoreRelease(pm_data->wakeup_work_sem);
        return;
    }

    ret = host_do_wakeup(pm_data);

    // 唤醒等待的应用线程
    osSemaphoreRelease(pm_data->wakeup_work_sem);
}

int32_t pm_task_add_work(struct pm_drv_data *pm_data, uint8_t event)
{
    pm_task_info_t* task_info = &pm_data->pm_task;

    if (osMessageQueueGetSpace(task_info->event_queue) == 0) {
        PRINT_ERR("pm_task_add_work queue is full!");
        return -OAL_FAIL;
    }
    pm_work_t work;
    work.pm_event = event;

    osStatus_t status = osMessageQueuePut(task_info->event_queue, &work, 0, 0);
    if (status != osOK) {
        PRINT_ERR("pm_task_add_work queue put error, err=%d!", status);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

STATIC void plat_pm_work_process(struct pm_drv_data *pm_data, pm_work_t* work)
{
    osMutexAcquire(pm_data->pm_task.work_mutex, osWaitForever);  // 锁定互斥锁
    switch (work->pm_event) {
        case PM_EVENT_SLEEP:
            pm_bfg_sleep_work(pm_data);
            break;
        case PM_EVENT_WAKEUP_ISR:
            pm_bfg_wakeup_isr_work(pm_data);
            break;
        case PM_EVENT_WAKEUP_DEV:
            pm_bfg_wakeup_dev_work(pm_data);
            break;
        default:
            break;
    }
    osMutexRelease(pm_data->pm_task.work_mutex);  // 释放互斥锁
}

STATIC void plat_pm_thread_main(void *param)
{
    struct pm_drv_data *pm_data = (struct pm_drv_data*)param;
    if (pm_data == NULL) {
        return;
    }

    pm_task_info_t* task_info = &pm_data->pm_task;
    osMessageQueueId_t queue_id = task_info->event_queue;
    osStatus_t status;
    pm_work_t work;
    while (true) {
        status = osMessageQueueGet(queue_id, &work, NULL, osWaitForever);
        MCU_TASK_BEGIN();
        if (status == osOK) {
            plat_pm_work_process(pm_data, &work);
        }
        MCU_TASK_END();
    }
    return;
}

int low_power_task_init(struct pm_drv_data *pm_data)
{
    osThreadAttr_t thread_attr = { "hisi_conn_pm_task", 0, NULL, 0, NULL, TASK_STACKSIZE_PM, TASK_PRIORITY_PM, 0, 0 };
    pm_data->pm_task.thread_id = osThreadNew(plat_pm_thread_main, pm_data, &thread_attr);
    if (pm_data->pm_task.thread_id == NULL) {
        PRINT_ERR("low_power_task_init thread Error");
        goto CREATE_THREAD_FAIL;
    }

    osMessageQueueAttr_t queue_attr = { 0 };
    queue_attr.name = "pm_event_queue";
    pm_data->pm_task.event_queue = osMessageQueueNew(QUEUE_PM_EVENT_LEN, sizeof(pm_work_t), &queue_attr);
    if (pm_data->pm_task.event_queue == NULL) {
        PRINT_ERR("low_power_task_init queue Error");
        goto CREATE_QUEUE_FAIL;
    }
    pm_data->pm_task.work_mutex = osMutexNew(NULL);
    if (pm_data->pm_task.work_mutex == NULL) {
        PRINT_ERR("low_power_task_init work mutex Error");
        goto WORK_MUTEX_FAIL;
    }
    pm_data->pm_task.service_mutex = osMutexNew(NULL);
    if (pm_data->pm_task.service_mutex == NULL) {
        PRINT_ERR("low_power_task_init service mutex Error");
        goto SERVICE_MUTEX_FAIL;
    }
    return OAL_SUCC;

SERVICE_MUTEX_FAIL:
    osMutexDelete(pm_data->pm_task.work_mutex);
WORK_MUTEX_FAIL:
    osMessageQueueDelete(pm_data->pm_task.event_queue);
CREATE_QUEUE_FAIL:
CREATE_THREAD_FAIL:
    return -OAL_FAIL;
}

void low_power_task_deinit(struct pm_drv_data *pm_data)
{
    if (pm_data->pm_task.work_mutex != NULL) {
        osMutexDelete(pm_data->pm_task.work_mutex);
    }

    if (pm_data->pm_task.service_mutex != NULL) {
        osMutexDelete(pm_data->pm_task.service_mutex);
    }

    if (pm_data->pm_task.event_queue != NULL) {
        osMessageQueueDelete(pm_data->pm_task.event_queue);
    }

    if (pm_data->pm_task.thread_id != NULL) {
        osThreadTerminate(pm_data->pm_task.thread_id);
    }
}

int low_power_probe(struct pm_drv_data *pm_data, int idx)
{
    bfgx_set_pm_switch(pm_data, BFGX_PM_ENABLE);
    pm_data->bfgx_bt_lowpower_enable = BFGX_PM_DISABLE;
    pm_data->bfgx_gnss_lowpower_enable = BFGX_PM_DISABLE;

    oal_atomic_set(&pm_data->gnss_sleep_flag, GNSS_AGREE_SLEEP);
    pm_data->uart_baud_switch_to = LOW_POWER_UART_BAUD;

    oal_spin_lock_init(&pm_data->state_spinlock);
    pm_data->bfgx_dev_state = BFGX_SLEEP;
    pm_data->bt_fake_close_flag = OAL_FALSE;

    pm_data->sleep_work_sem = osSemaphoreNew(1, 0, NULL);
    pm_data->wakeup_work_sem = osSemaphoreNew(1, 0, NULL);
    pm_data->pm_report_switch = (1 << PM_NOTIFY_LEVEL_ERR);  // 低功耗异常事件通报AP
    pm_data->bfg_wakeup_dev_cnt = 0;
    pm_data->bfg_wakeup_host_cnt = 0;
    pm_data->bfg_sleep_cnt = 0;
    pm_data->bfg_sleep_fail_cnt = 0;
    pm_data->bfg_wakeup_fail_cnt = 0;

    if (low_power_gpio_init(pm_data) != OAL_SUCC) {
        goto REQ_IRQ_FAIL;
    }

    if (low_power_task_init(pm_data) != OAL_SUCC) {
        goto CREATE_TASK_FAIL;
    }

    low_power_probe_timer_init(pm_data);

    /* set driver data */
    PRINT_INFO("low_power_probe ok!");

    return OAL_SUCC;

CREATE_TASK_FAIL:
    low_power_gpio_deinit(pm_data);
REQ_IRQ_FAIL:
    return -ENOMEM;
}

int low_power_remove(struct pm_drv_data *pm_data, int index)
{
    low_power_timer_deinit(pm_data);
    low_power_gpio_deinit(pm_data);
    low_power_task_deinit(pm_data);
    return 0;
}

int low_power_init(void)
{
    int ret;
    struct pm_top *pm_top_data = pm_get_top();

    /* init mutex */
    oal_mutex_init((oal_mutex_t *)&(pm_top_data->host_mutex));
    pm_top_data->firmware_cfg_init_flag = 0;

    ret = hw_ps_init();
    if (ret != SUCCESS) {
        PRINT_ERR("low_power_init: hw_ps_init fail");
        return -ENOMEM;
    }

    PRINT_INFO("low_power_init ok!");
    return ret;
}

void low_power_exit(void)
{
    hw_ps_exit();
}

/*
 * Prototype    : ps_pm_register
 * Description  : register interface for 3 in 1
 * Input        : struct ps_pm_s *new_pm: interface want to register
 * Return       : 0 means succeed,-1 means failed
 */
int32_t ps_pm_register(struct ps_core_s *ps_core_d, int index)
{
    int ret;
    struct pm_top *pm_top_data = pm_get_top();
    struct pm_drv_data *pm_data = &(pm_top_data->bfg_pm_info);

    ret = low_power_probe(pm_data, index);
    if (ret != OAL_SUCC) {
        return -FAILURE;
    }

    ps_core_d->pm_data = pm_data;
    pm_data->ps_core_data = ps_core_d;

    PRINT_INFO("pm registered over:%d!", index);
    return SUCCESS;
}

/*
 * Prototype    : ps_pm_unregister
 * Description  : unregister interface for 3 in 1
 * Input        : struct ps_pm_s *new_pm: interface want to unregister
 * Return       : 0 means succeed,-1 means failed
 */
int32_t ps_pm_unregister(struct ps_core_s *ps_core_d, int index)
{
    struct pm_drv_data *pm_data = ps_core_d->pm_data;

    pm_data->ps_core_data = NULL;
    ps_core_d->pm_data = NULL;

    (void)low_power_remove(pm_data, index);

    PRINT_INFO("pm unregistered over:%d!", index);

    return SUCCESS;
}

