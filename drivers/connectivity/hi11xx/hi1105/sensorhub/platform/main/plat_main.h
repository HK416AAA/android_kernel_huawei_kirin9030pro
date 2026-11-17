/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat_main.c header file
 * Author: plat drivers
 */

#ifndef PLAT_MAIN_H
#define PLAT_MAIN_H

#include <stdint.h>
#include "cmsis_os2.h"

typedef void (*uart_tx_prepare_t)(void);

typedef struct plat_uart_task_info {
    osThreadId_t rx_thread;
    osThreadId_t tx_thread;
    osMessageQueueId_t tx_queue;
    osSemaphoreId_t tx_sem;
    struct uart_adapter *adapter;
    uart_tx_prepare_t prepare;
} plat_uart_task_info_t;

extern int32_t hal_work_begin(uint64_t a);
extern int32_t hal_work_end(uint64_t a);

#ifdef _PRE_LINUX_TEST
#define MCU_TASK_BEGIN()
#define MCU_TASK_END()
#else
#define MCU_TASK_BEGIN()    hal_work_begin(0)
#define MCU_TASK_END()      hal_work_end(0)
#endif

enum {
    MSG_TYPE_RX,
    MSG_TYPE_TX,
};

typedef struct {
    uint8_t uart;
    uint8_t type;
    uint16_t buf_len;
    uint8_t* buf;
} plat_msg_t;

/* 函数声明 */
extern int32_t plat_init(void);
extern void plat_exit(void);
int32_t platform_task_send_msg(uint8_t uart, uint8_t type, uint8_t* data, uint16_t data_len);
int32_t platform_rx_task_send_msg(uint8_t msg_type);
plat_uart_task_info_t *bfgn_get_uart_task_info(uint8_t uart);
void bfgn_uart_tx_queue_clear(uint8_t uart);

#endif
