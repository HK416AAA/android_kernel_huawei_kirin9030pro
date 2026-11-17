/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for msg handle
 * Author: bfgx drivers
 */
#define USE_LOG_TAG_FUNC
#define pr_fmt(fmt) "2[hisi_plat]" fmt

#include "bfgx_dev.h"
#include "plat_uart.h"
#include "plat_debug.h"
#include "oal_net.h"
#include "plat_pm.h"
#include "plat_sys_msg.h"
#include "errorcode.h"
#include "event.h"
#include "oal_schedule.h"
#include "bfgx_platform_msg_handle.h"

#define CHR_ERR_DATA_MAX_NUM 0x20
#define EXEC_BT_CONTROLLER 0x3
#define EXEC_BT_PLATFORM 0x4
#define EXCE_GLASSES_EVENT 0xFF
#define EXCE_BLUTTOOTH 0x7

#define BT_CHIP_CHR_BT_HARDWARE_ERROR      913900001
#define BT_CHIP_CHR_BLE_HARDWARE_ERROR     913900002
#define CHR_PMU_CMU_ERROR_EVENTID          909003037
#define CHR_PLATFORM_EXCEPTION_EVENTID     909003002

enum bt_exec_event {
    EXCEPT_BTC_ERROR_BT_INT_ISR = 0x1,
    EXCEPT_BTC_ERROR_BLE_INT_ISR = 0x2
};

enum plat_exec_event {
    EXCEPT_BT_PLAT_PMU_CMU_ERR = 0x1,
    EXCEPT_BT_PLAT_EXCEPTION = 0x2
};

typedef struct {
    uint32_t errnum;
    uint16_t errlen;
    uint16_t flag;
} chr_exception_info;

#pragma pack(1)
typedef struct {
    uint8_t            chr_type;
    chr_exception_info chr_info;
    uint8_t            errdata[CHR_ERR_DATA_MAX_NUM * 4];
} bfgx_chr_info;
#pragma pack()

typedef struct {
    uint32_t errnum;
    uint8_t chr_type;
    uint8_t info2;
    uint16_t info3;
} chr_convert;

chr_convert g_chr_event_id_convert[] = {
    {BT_CHIP_CHR_BT_HARDWARE_ERROR, CHR_TYPE_ERROR, EXEC_BT_CONTROLLER, EXCEPT_BTC_ERROR_BT_INT_ISR},
    {BT_CHIP_CHR_BLE_HARDWARE_ERROR, CHR_TYPE_ERROR, EXEC_BT_CONTROLLER, EXCEPT_BTC_ERROR_BLE_INT_ISR},
    {CHR_PMU_CMU_ERROR_EVENTID, CHR_TYPE_ERROR, EXEC_BT_PLATFORM, EXCEPT_BT_PLAT_PMU_CMU_ERR},
    {CHR_PLATFORM_EXCEPTION_EVENTID, CHR_TYPE_ERROR, EXEC_BT_PLATFORM, EXCEPT_BT_PLAT_EXCEPTION}
};

/* 全局变量定义 */
typedef void (*platform_msg_handler)(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void bfgx_hello_msg_handle(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void platform_unused_msg(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void bfgx_thread_msg_handle(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void bfgx_agree_host_sleep(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void bfgx_not_agree_host_sleep(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void bfgx_read_mem_complete(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void bfgx_set_uart_loop_done(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
STATIC void bfgx_recv_device_chr(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);

STATIC platform_msg_handler g_sys_msg_handle[SYS_INF_BUTT] = {
    bfgx_hello_msg_handle,       // SYS_INF_PF_HELLO = 0x00,               hello消息
    bfgx_thread_msg_handle,      // SYS_INF_BT_INIT = 0x01,                BT软件初始化完成
    bfgx_thread_msg_handle,      // SYS_INF_GNSS_INIT = 0x02,              GNSS软件初始化完成
    bfgx_thread_msg_handle,      // SYS_INF_FM_INIT = 0x03,                FM软件初始化完成
    platform_unused_msg,         // SYS_INF_BT_DISABLE = 0x04,             BT禁能
    platform_unused_msg,         // SYS_INF_GNSS_DISABLE = 0x05,           GNSS禁能
    platform_unused_msg,         // SYS_INF_FM_DISABLE = 0x06,             FM禁能
    bfgx_thread_msg_handle,      // SYS_INF_BT_EXIT = 0x07,                BT退出
    bfgx_thread_msg_handle,      // SYS_INF_GNSS_EXIT = 0x08,              GNSS退出
    bfgx_thread_msg_handle,      // SYS_INF_FM_EXIT = 0x09,                FM退出
    platform_unused_msg,         // SYS_INF_GNSS_WAIT_DOWNLOAD = 0x0A,     等待GNSS代码下载
    platform_unused_msg,         // SYS_INF_GNSS_DOWNLOAD_COMPLETE = 0x0B, GNSS代码下载完毕
    platform_unused_msg,         // SYS_INF_BFG_HEART_BEAT = 0x0C,         心跳信号
    bfgx_agree_host_sleep,       // SYS_INF_DEV_AGREE_HOST_SLP = 0x0D,     device回复host可睡
    bfgx_not_agree_host_sleep,   // SYS_INF_DEV_NOAGREE_HOST_SLP = 0x0E,   device回复host不可睡
    platform_unused_msg,         // SYS_INF_WIFI_OPEN = 0x0F,              WCPU上电完成
    bfgx_thread_msg_handle,      // SYS_INF_IR_INIT = 0x10,                IR软件初始化完成
    bfgx_thread_msg_handle,      // SYS_INF_IR_EXIT = 0x11,                IR退出
    bfgx_thread_msg_handle,      // SYS_INF_NFC_INIT = 0x12,               NFC软件初始化完成
    bfgx_thread_msg_handle,      // SYS_INF_NFC_EXIT = 0x13,               NFC退出
    platform_unused_msg,         // SYS_INF_WIFI_CLOSE = 0x14,             WCPU下电完成
    platform_unused_msg,         // SYS_INF_RF_TEMP_NORMAL = 0x15,         RF温度正常
    platform_unused_msg,         // SYS_INF_RF_TEMP_OVERHEAT = 0x16,       RF温度过热
    bfgx_read_mem_complete,      // SYS_INF_MEM_DUMP_COMPLETE = 0x17,      bfgx异常时，MEM DUMP已完成
    platform_unused_msg,         // SYS_INF_WIFI_MEM_DUMP_COMPLETE = 0X18, bfgx异常时，MEM DUMP已完成
    platform_unused_msg,         // SYS_INF_UART_HALT_WCPU = 0x19,         uart halt wcpu ok
    bfgx_set_uart_loop_done,     // SYS_INF_UART_LOOP_SET_DONE = 0x1a,     device 设置uart环回ok
    bfgx_recv_device_chr,        // SYS_INF_CHR_ERRNO_REPORT = 0x1b,       device向host上报CHR异常码
    platform_unused_msg,         // SYS_INF_RSV0 = 0x1c,                   rsv
    platform_unused_msg,         // SYS_INF_RSV1 = 0x1d,                   rsv
    platform_unused_msg,         // SYS_INF_RSV2 = 0x1e,                   rsv
};

STATIC void platform_unused_msg(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    PRINT_WARN("unused msg:%d, need to check", *buf_ptr);
}

STATIC void bfgx_hello_msg_handle(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    PRINT_INFO("SYS_INF_PF_HELLO msg received");
}

STATIC void thread_completion_handle(struct ps_core_s *ps_core_d, uint8_t flag, uint8_t thread)
{
    if (thread >= BFGX_BUTT) {
        PRINT_ERR("thread index error:%d", thread);
        return;
    }

    if (flag == THREAD_FLAG_INIT) {
        PRINT_INFO("thread init success");
        oal_complete(&ps_core_d->bfgx_info[thread].wait_opened);
    } else if (flag == THREAD_FLAG_EXIT) {
        PRINT_INFO("thread exit success");
        oal_complete(&ps_core_d->bfgx_info[thread].wait_closed);
    } else {
        PRINT_ERR("bfgx thread handle flag error:%d, thread:%d", flag, thread);
    }
}

STATIC void bfgx_thread_msg_handle(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    uint8_t msg = *buf_ptr;

    switch (msg) {
        case SYS_INF_BT_INIT:
            thread_completion_handle(ps_core_d, THREAD_FLAG_INIT, BFGX_BT);
            break;
#ifdef HAVE_HISI_NFC
        case SYS_INF_NFC_INIT:
            thread_completion_handle(ps_core_d, THREAD_FLAG_INIT, BFGX_NFC);
            break;
        case SYS_INF_NFC_EXIT:
            thread_completion_handle(ps_core_d, THREAD_FLAG_EXIT, BFGX_NFC);
            break;
#else
        case SYS_INF_FAKE_CLOSE_BT:
            PRINT_INFO("SYS_INF_FAKE_CLOSE_BT received");
            break;
#endif
        case SYS_INF_BT_EXIT:
            thread_completion_handle(ps_core_d, THREAD_FLAG_EXIT, BFGX_BT);
            break;
        default:
            break;
    };
}

STATIC void bfgx_not_agree_host_sleep(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    struct pm_drv_data *pm_data = NULL;

    pm_data = ps_core_d->pm_data;
    if (pm_data == NULL) {
        PRINT_ERR("pm_data is NULL!");
        return;
    }

    PRINT_INFO("bfgx dev not agree host sleep");

    bfgx_dev_state_set(pm_data, BFGX_ACTIVE);

    bfg_sleep_timer_restart(pm_data);

    // 有应答, 睡眠fail计数清零
    pm_data->bfg_sleep_fail_continue = 0;

    osSemaphoreRelease(pm_data->sleep_work_sem);
}

STATIC void bfgx_agree_host_sleep(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    uint32_t flags;
    struct pm_drv_data *pm_data;

    pm_data = ps_core_d->pm_data;
    if (pm_data == NULL) {
        PRINT_ERR("pm_data is NULL!");
        return;
    }

    // 有应答, 睡眠fail计数清零
    pm_data->bfg_sleep_fail_continue = 0;

    PRINT_INFO("bfgx dev agree host sleep, pre sem_count %d", osSemaphoreGetCount(pm_data->sleep_work_sem));
    osSemaphoreRelease(pm_data->sleep_work_sem);
}

STATIC void bfgx_read_mem_complete(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
}

STATIC void bfgx_set_uart_loop_complete(void)
{
    uart_loop_ctx_complete_set();
}

STATIC void bfgx_uart_loop_finish(void)
{
    uart_loop_ctx_send_finish();
}

STATIC void bfgx_set_uart_loop_done(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    if (conn_test_uart_loop_result() == UART_LOOP_RES_INIT) {
        bfgx_set_uart_loop_complete();
    } else {
        bfgx_uart_loop_finish();
        PRINT_INFO("******** UART LOOP TEST FINISH ******** ");
    }
    return;
}

STATIC int32_t bfgx_recv_device_chr_convert(chr_data_extend_t *chr_inf, bfgx_chr_info *buf_bfgx)
{
    int32_t ret;

    for (uint8_t i = 0; i < sizeof(g_chr_event_id_convert)/sizeof(chr_convert); i++) {
        if (g_chr_event_id_convert[i].errnum == buf_bfgx->chr_info.errnum) {
            chr_inf->chr_type = g_chr_event_id_convert[i].chr_type;
            chr_inf->info2 = g_chr_event_id_convert[i].info2;
            chr_inf->info3 = g_chr_event_id_convert[i].info3;
            break;
        }
    }
    chr_inf->event_id = EXCE_GLASSES_EVENT;
    chr_inf->info1 = EXCE_BLUTTOOTH;
    chr_inf->data_len = buf_bfgx->chr_info.errlen;

    if (chr_inf->data_len > 0) {
        ret = memcpy_s(chr_inf->data, CHR_EXTEND_PARAM_MAX_LEN, buf_bfgx->errdata, buf_bfgx->chr_info.errlen);
        if (ret != EOK) {
            PRINT_INFO("bfgx_recv_device_chr_convert memcpy fail");
            return ret;
        }
    }

    return OAL_SUCC;
}

STATIC void bfgx_chr_report(chr_data_extend_t *chr_inf)
{
    PRINT_INFO("## CHR ##: type:%u, evt_id:0x%X, inf1:0x%X, inf2:0x%X, inf3:0x%X",
               chr_inf->chr_type, chr_inf->event_id, chr_inf->info1, chr_inf->info2, chr_inf->info3);
    switch (chr_inf->chr_type) {
        case CHR_TYPE_EVENT:
            if (chr_inf->data_len == 0) {
                EVENT(EVENT_PUBLIC, chr_inf->event_id, chr_inf->info1, chr_inf->info2, chr_inf->info3);
            } else {
                EVENT(EVENT_PUBLIC, chr_inf->event_id, chr_inf->info1, chr_inf->info2, chr_inf->info3,
                      chr_inf->data, chr_inf->data_len);
            }
            break;

        case CHR_TYPE_ERROR:
            if (chr_inf->data_len == 0) {
                ERROR_CODE(EC_PUBLIC, chr_inf->event_id, chr_inf->info1, chr_inf->info2, chr_inf->info3);
            } else {
                ERROR_CODE(EC_PUBLIC, chr_inf->event_id, chr_inf->info1, chr_inf->info2, chr_inf->info3,
                           chr_inf->data, chr_inf->data_len);
            }
            break;
    }
}

STATIC void bfgx_recv_device_chr(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    chr_data_extend_t *chr_inf = (chr_data_extend_t *)ps_core_d->chr_inf;
    bfgx_chr_info *chr_bfgx = (bfgx_chr_info *)buf_ptr;

    if (bfgx_recv_device_chr_convert(chr_inf, chr_bfgx) == OAL_SUCC) {
        bfgx_chr_report(chr_inf);
    }
}

STATIC void heartbeat_debug_print(struct ps_core_s *ps_core_d, uint8_t syschar)
{
}

STATIC void bfgx_recv_heartbeat(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
}

/*
 * Prototype    : ps_exe_sys_func
 * Description  : called by core when recive sys data event from device
 *              : decode rx sys packet function
 */
int32_t ps_exe_sys_func(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    uint8_t syschar;

    if (buf_ptr == NULL) {
        PRINT_ERR("buf_ptr is NULL");
        return -EINVAL;
    }

    syschar = *buf_ptr;

    if (syschar < SYS_INF_BUTT) {
        if (g_sys_msg_handle[syschar] != NULL) {
            g_sys_msg_handle[syschar](ps_core_d, buf_ptr);
        }
    } else if (syschar >= SYS_INF_HEARTBEAT_CMD_BASE) {
        bfgx_recv_heartbeat(ps_core_d, buf_ptr);
    } else {
        PRINT_WARN("bfgx recv unsupport msg:0x%x", syschar);
    }

    return 0;
}
