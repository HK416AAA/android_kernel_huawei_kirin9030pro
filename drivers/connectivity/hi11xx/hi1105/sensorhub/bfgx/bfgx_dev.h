/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: bfgx_dev.c header file
 * Author: bfgx drivers
 */

#ifndef __BFGX_DEV_H__
#define __BFGX_DEV_H__

/* 其他头文件包含 */
#include "hw_bfg_ps.h"
#include "ipc_iomcu_base.h"

/* 宏定义 */
#define BT_TYPE_DATA_LEN           1

/* timeout for dbg read */
#define DBG_READ_DEFAULT_TIME 5000

#define UART_LOOP_RESUME_DEVICE_DATA_HANDLER 0
#define UART_LOOP_SET_DEVICE_DATA_HANDLER    1

#define UART_LOOP_MAX_PKT_LEN 2048 /* device buf len is 2400 */

#define HW_SW_MODE      0
#define HW_STR_MODE     1

#define TASK_STACKSIZE_UART_LOOP     0x400
#define TASK_PRIORITY_UART_LOOP      (osPriorityAboveNormal)
#define UART_LOOP_RES_INIT          7
#define UART_LOOP_RUNNING           5

enum mcu_init_status {
    MCU_INIT_WAIT,
    MCU_INIT_SUCC,
    MCU_INIT_FAIL
};

extern bfgn_read_data_callback_t g_gnss_data_handle;
extern bfgn_read_data_callback_t g_data_handle_backup;

typedef struct ipc_dsp_data {
    pkt_header_sensorhub_t ipc_head;    /* ipc msg head */
    uint16_t dsp_buf_cnt;               /* dsp have two buff, 0 or 1 */
    uint16_t dsp_buf_len;               /* dsp data length */
} conn_dsp_data_t;

/* 结构体定义 */
struct bt_data_combination {
    uint8_t len;
    uint8_t type;
    uint16_t resverd;
};

typedef struct uart_loop_user_cfg {
    uint32_t loop_count;
    uint16_t pkt_len;
    uint16_t cpu_fre;
    uint32_t uart_loop_enable;
    uint32_t uart_loop_tx_random_enable;
} uart_loop_cfg;

typedef struct uart_loop_test {
    uart_loop_cfg *test_cfg;
    uint8_t *tx_buf;
    uint8_t *rx_buf;
    uint16_t rx_pkt_len;
} uart_loop_test_struct;

typedef struct uart_loop_ctx {
    uint8_t wait;
    uint8_t fail;
    uint8_t finish;
    uint8_t result;
    uint16_t set;
} uart_loop_test_ctx;

/* 全局变量声明 */
extern const char *g_bfgx_subsys_name[BFGX_BUTT];

extern uint32_t g_gnss_me_thread_status;
extern uint32_t g_gnss_lppe_thread_status;

extern uart_loop_cfg g_uart_loop_test_cfg;
extern uart_loop_test_struct *g_uart_loop_test_info;

/* 函数声明 */
int32_t uart_loop_test(uint8_t uart_type);
void uart_loop_test_recv_pkt(const char *buf_ptr, uint16_t pkt_len);
void uart_loop_ctx_complete_set(void);
void uart_loop_ctx_send_finish(void);

struct ps_core_s *ps_get_core_reference(uint32_t type);
oal_netbuf_stru *ps_alloc_skb(uint16_t len);
void ps_kfree_skb(struct ps_core_s *ps_core_d, uint8_t type);
int32_t alloc_seperted_rx_buf(struct ps_core_s *ps_core_d, uint8_t subsys, uint32_t len, uint8_t alloctype);
void free_seperted_rx_buf(struct ps_core_s *ps_core_d, uint8_t subsys, uint8_t alloctype);
bool ps_chk_tx_queue_empty(struct ps_core_s *ps_core_d);
int32_t plat_bfgx_dump_rotate_cmd_read(struct ps_core_s *ps_core_d, unsigned long arg);
bool ps_bfg_subsys_active(uint32_t subsys);
bool ps_set_subsys_state(uint32_t subsys, power_state_enum power_state);
void ps_set_device_log_status(bool status);
bool ps_is_device_log_enable(void);
void bfgx_set_device_init_status(uint8_t status);
void bfgx_send_device_init_status_to_ap(void);
int32_t bfgx_open_cmd_send(struct ps_core_s *ps_core_d, uint8_t subsys);
int32_t bfgx_close_cmd_send(struct ps_core_s *ps_core_d, uint8_t subsys);
int32_t uart_bfgx_close_cmd(void);
int32_t ps_restore_skbqueue(struct ps_core_s *ps_core_d, oal_netbuf_stru *pst_netbuf, uint8_t type);
int32_t hw_bfgx_open(uint32_t subsys);
int32_t hw_bfgx_close(uint32_t subsys);
int hw_ps_init(void);
void hw_ps_exit(void);
struct ps_core_s *ps_get_subsys_core_reference(uint32_t subsys);

/* 由于上层调用, 下面函数打桩保留, 删掉会导致编译报错 */
static inline int32_t hw_gnss_open(void)
{
    return 0;
}

static inline int32_t hw_gnss_close(void)
{
    return 0;
}

static inline int32_t hw_gnss_write(const char *buf, int32_t count)
{
    return 0;
}

static inline void hw_gnss_register_read_callback(bfgn_read_data_callback_t callback)
{
}

int conn_test_buart_loop(void);
int conn_test_uart_loop_result(void);
int conn_test_buart_panic(void);

#endif /* __BFGX_DEV_H__ */
