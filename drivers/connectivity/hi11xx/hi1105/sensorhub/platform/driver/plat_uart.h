/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat_uart.c header file
 * Author: plat drivers
 */

#ifndef __PLAT_UART_H__
#define __PLAT_UART_H__

/* 其他头文件包含 */
#include "hw_bfg_ps.h"

/* uart配置参数，待适配 */
#define BT_UART_BUS         4
#define GNSS_UART_BUS       5

/* 宏定义 */
#define OPEN_TTY_RETRY_COUNT 5
#define RELEASE_DELAT_TIMES 50

/* BFGX正常通信使用3M波特率，host唤醒device时使用115200波特率，单红外时使用921600波特率 */
#define DEFAULT_BAUD_RATE 2000000

#define LOW_FREQ_BAUD_RATE  4000000
#define HIGH_FREQ_BAUD_RATE 6000000

#define UART_BAUD_RATE_921600   921600
#define UART_BAUD_RATE_1M       1000000
#define UART_BAUD_RATE_2M       2000000
#define UART_BAUD_RATE_4M       4000000
#define UART_BAUD_RATE_6M       6000000
#define UART_BAUD_RATE_8M       8000000
#define UART_BAUD_RATE_10M      10000000

#define WKUP_DEV_BAUD_RATE 115200
#define IR_ONLY_BAUD_RATE  921600

#define FLOW_CTRL_ENABLE  1
#define FLOW_CTRL_DISABLE 0

#define UART_PCLK_FROM_SENSORHUB 0
#define UART_PCLK_NORMAL         1

#define BFGN_MSG_START          0x7E
#define BFGN_MSG_TAIL           0x7E
#define BFGN_MSG_HEADER_LEN     4
#define BFGN_MSG_TAIL_LEN       1
#define PAYLOAD_MIN_LEN         1
#define BFGN_MSG_MIN_LEN        (BFGN_MSG_HEADER_LEN + BFGN_MSG_TAIL_LEN + PAYLOAD_MIN_LEN)
#define BFGN_MSG_MAX_LEN        4100    /* 需要根据类型适配 */
#define BT_MSG_MAX_LEN          (2716 + 5 + 5)

typedef enum {
    STATE_TTY_TX = 0,
    STATE_TTY_RX = 1,
    STATE_UART_TX = 2,
    STATE_UART_RX = 3,
} uart_state_index;

typedef struct {
    uint8_t msg_start;
    uint8_t msg_type;
    uint16_t msg_len;
} bfgn_msg_header_t;

typedef struct uart_rx_data_buf {
    uint16_t data_maxlen;
    uint16_t data_len;
    char* data;
} uart_rx_status_t, uart_rx_data_buf_t;


typedef struct bfgn_uart_rx_ctx {
    char     head_buff[BFGN_MSG_HEADER_LEN];
    char     tail_buff[BFGN_MSG_TAIL_LEN];
    uint8_t  uart;
    bool     rx_done;
    uint8_t  rx_status;
    uint8_t  msg_type;
    uint8_t  reserved;
    uint16_t msg_len;
    uint16_t msg_recv_len;
    uint16_t rx_buf_len;
    char    *data_local;
    char    *rx_buf;
    uart_rx_data_buf_t *rx_data_buf;
} bfgn_uart_rx_ctx_t;

/* EXTERN VARIABLE */
extern uint32_t g_uart_default_baud_rate;

typedef void (*bfgn_uart_data_handle_t)(uint8_t uart, const char *data, uint16_t data_len);

/* 函数声明 */
int32_t plat_uart_init(struct ps_core_s *core_data, int uart);
int32_t plat_uart_exit(int);
int32_t plat_uart_enable(struct ps_core_s *core_data);
int32_t plat_uart_disable(struct ps_core_s *core_data);
int32_t open_tty_drv(struct ps_core_s *ps_core_d);
int32_t release_tty_drv(struct ps_core_s *ps_core_d);
int32_t ps_change_uart_baud_rate(struct ps_core_s *ps_core_d, long baud_rate, uint8_t enable_flowctl);
void ps_uart_state_dump(struct ps_core_s *ps_core_d);
void bfgn_register_uart_data_handle(uint16_t msg_type, bfgn_uart_data_handle_t handle);
void bfgn_register_bt_data_callback(bfgn_read_data_callback_t callback);
void bfgn_register_sle_data_callback(bfgn_read_data_callback_t callback);
void bfgn_uart_recv_loop(struct uart_adapter *adapter);
void bfgn_uart_callback_switch_backup(bfgn_read_data_callback_t callback);
void bfgn_uart_callback_backup(bfgn_read_data_callback_t callback);
int32_t bfgn_uart_dev_write(struct bus* bus_controller, char* buf, INT32 len, INT32 type);
void bfgn_uart_tx_stat(uint8_t uart, uint8_t* data, uint16_t data_len);
uint32_t get_uart_tx_cnt(int index);
uint32_t get_uart_rx_cnt(int index);
void clear_uart_tx_cnt(int index);
void clear_uart_rx_cnt(int index);
#endif
