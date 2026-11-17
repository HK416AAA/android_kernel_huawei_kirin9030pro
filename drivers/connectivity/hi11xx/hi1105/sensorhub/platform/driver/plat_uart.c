/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for uart
 * Author: plat drivers
 */

#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "board.h"
#include "oal_types.h"
#include "oal_net.h"
#include "plat_uart.h"
#include "bfgx_dev.h"
#include "plat_main.h"
#include "hw_bfg_ps.h"
#include "plat_debug.h"

#define UART_WRITE_TIMEOUT_CNT    10

#define BT_UART_BAUDRATE    UART_BAUD_RATE_10M
char g_bt_uart_rx[BT_MSG_MAX_LEN];

enum bfgn_msg_data_status {
    MSG_HEADER,
    MSG_PAYLOAD,
    MSG_TAIL,
    WRONG_STATUS,
    UART_STATUS_BUTT
};

bfgn_uart_data_handle_t g_pf_data_handle[MSG_BUTT];
bfgn_read_data_callback_t g_gnss_data_handle;
bfgn_read_data_callback_t g_bt_data_handle;
bfgn_read_data_callback_t g_sle_data_handle;
bfgn_read_data_callback_t g_data_handle_backup;

/* 全局变量定义 */
uart_rx_data_buf_t g_uart_rx_data_buf[UART_BUTT];
bfgn_uart_rx_ctx_t g_bfgn_uart_rx_ctx[UART_BUTT];

/* UART收发包维测统计 */
static uint32_t g_uart_rx_cnt[UART_BUTT] = { 0, 0 };
static uint32_t g_uart_tx_cnt[UART_BUTT] = { 0, 0 };
static uint32_t g_uart_rx_byte[UART_BUTT] = { 0, 0 };
static uint32_t g_uart_tx_byte[UART_BUTT] = { 0, 0 };
/* 数据收包维测统计 */
static uint32_t g_data_rx_byte[UART_BUTT] = { 0, 0 };
/* 日志接收维测统计 */
static uint32_t g_log_rx_cnt[UART_BUTT] = { 0, 0 };
static uint32_t g_log_rx_byte[UART_BUTT] = { 0, 0 };
/* 持锁后的uart收发包统计数据，用来判定本次持锁是否异常 */
static uint32_t g_lock_rx_cnt[UART_BUTT] = { 0, 0 };
static uint32_t g_lock_tx_cnt[UART_BUTT] = { 0, 0 };

/* UART上次收发包打印的时间 */
#define UART_DEBUG_INTERVAL     1       // 1s间隔
static time_t g_trx_print_time[UART_BUTT] = { 0, 0 };

bfgn_uart_rx_ctx_t *bfgn_uart_rx_ctx_init(uint8_t uart)
{
    if (uart >= UART_BUTT) {
        return NULL;
    }

    bfgn_uart_rx_ctx_t *ctx = &g_bfgn_uart_rx_ctx[uart];
    (void)memset_s(ctx, sizeof(bfgn_uart_rx_ctx_t), 0, sizeof(bfgn_uart_rx_ctx_t));
    ctx->uart = uart;
    ctx->rx_status = MSG_HEADER;
    ctx->data_local = ctx->head_buff;
    ctx->msg_recv_len = BFGN_MSG_HEADER_LEN;
    ctx->rx_buf = ctx->head_buff;
    ctx->rx_buf_len = BFGN_MSG_HEADER_LEN;
    ctx->rx_data_buf = &g_uart_rx_data_buf[uart];
    return ctx;
}

void bfgn_uart_obj_set(bfgn_uart_rx_ctx_t *ctx, char *rx_buf, uint16_t rx_len)
{
    ctx->rx_buf = rx_buf;
    ctx->rx_buf_len = rx_len;
}

static void bfgn_exec_bt_data_handle(uint8_t uart, const char *data, uint16_t data_len)
{
    if (ps_bfg_subsys_active(BFGX_BT) == false) {
        PRINT_WARN("uart[%u], BFGX_BT is close, no need to handle BT_MSG data", uart);
    }

    if (g_bt_data_handle != NULL) {
        g_bt_data_handle(data, data_len);
    }
}

static void bfgn_exec_sle_data_handle(uint8_t uart, const char *data, uint16_t data_len)
{
    if (ps_bfg_subsys_active(BFGX_SLE) == false) {
        PRINT_WARN("uart[%u], BFGX_SLE is close, no need to handle BFGX_SLE data", uart);
    }

    if (g_sle_data_handle != NULL) {
        g_sle_data_handle(data, data_len);
    }
}

void bfgn_register_bt_data_callback(bfgn_read_data_callback_t callback)
{
    g_bt_data_handle = callback;
    bfgn_register_uart_data_handle(BT_MSG, bfgn_exec_bt_data_handle);
}

void bfgn_register_sle_data_callback(bfgn_read_data_callback_t callback)
{
    g_sle_data_handle = callback;
    bfgn_register_uart_data_handle(GLE_MSG, bfgn_exec_sle_data_handle);
}

void bfgn_uart_callback_switch_backup(bfgn_read_data_callback_t callback)
{
    bfgn_read_data_callback_t temp = callback;
    callback = g_data_handle_backup;
    g_data_handle_backup = callback;
}

void bfgn_uart_callback_backup(bfgn_read_data_callback_t callback)
{
    g_data_handle_backup = callback;
}

/* 消息处理接口注册接口 */
void bfgn_register_uart_data_handle(uint16_t msg_type, bfgn_uart_data_handle_t handle)
{
    g_pf_data_handle[msg_type] = handle;
}

uint32_t bfgn_data_store_handle(bfgn_uart_rx_ctx_t *ctx, char **data_addr, uint16_t *data_len)
{
    if (oal_unlikely((data_addr == NULL) || (data_len == NULL))) {
        return BFGN_FAIL;
    }

    uart_rx_data_buf_t *rx_data_buf = ctx->rx_data_buf;
    if (oal_unlikely((*data_len > (rx_data_buf->data_maxlen - rx_data_buf->data_len)) ||
        (*data_len < PAYLOAD_MIN_LEN))) {
        return BFGN_FAIL;
    }

    *data_addr = rx_data_buf->data + rx_data_buf->data_len;
    return BFGN_SUCC;
}

uint32_t get_uart_tx_cnt(int index)
{
    if (index >= UART_BUTT) {
        return 0;
    }
    return g_lock_tx_cnt[index];
}

uint32_t get_uart_rx_cnt(int index)
{
    if (index >= UART_BUTT) {
        return 0;
    }
    return g_lock_rx_cnt[index];
}

void clear_uart_tx_cnt(int index)
{
    if (index >= UART_BUTT) {
        return;
    }
    g_lock_tx_cnt[index] = 0;
}

void clear_uart_rx_cnt(int index)
{
    if (index >= UART_BUTT) {
        return;
    }
    g_lock_rx_cnt[index] = 0;
}

static void bfgn_uart_rx_stat(uint8_t uart, uint8_t msg_type, char sys_type, uint16_t data_len)
{
    time_t curr_time = time(NULL);
    uint32_t elapsed =  (uint32_t)difftime(curr_time, g_trx_print_time[uart]);

    // 低功耗定时周期内数据接收cnt计数, 会用于睡眠条件检查，睡眠前会清空; 数据接收长度仅用作维测，不清空
    if (msg_type != OML_MSG) {
        g_lock_rx_cnt[uart]++;
        g_data_rx_byte[uart] += data_len;
    } else {
        g_log_rx_cnt[uart]++;
        g_log_rx_byte[uart] += data_len;
    }

    // 总的UART接收统计
    g_uart_rx_cnt[uart]++;
    g_uart_rx_byte[uart] += data_len;

    /* 打印间隔设置为1s钟 */
    if (elapsed >= UART_DEBUG_INTERVAL) {
        g_trx_print_time[uart] = curr_time;
        PRINT_INFO("[com%u tx]: tx_cnt=%u, tx_byte=%u, elapsed=%u", uart,
                   g_uart_tx_cnt[uart], g_uart_tx_byte[uart], elapsed);

        PRINT_INFO("[com%u rx]: rx_cnt=%u(log=%u), rx_byte=%u(data=%u, log=%u)", uart,
                   g_uart_rx_cnt[uart], g_log_rx_cnt[uart], g_uart_rx_byte[uart],
                   g_data_rx_byte[uart], g_log_rx_byte[uart]);
    }
}

void bfgn_uart_tx_stat(uint8_t uart, uint8_t* data, uint16_t data_len)
{
    // 低功耗定时周期内数据发送cnt计数, 会用于睡眠条件检查，睡眠前会清空;
    g_lock_tx_cnt[uart]++;

    g_uart_tx_cnt[uart]++;
    g_uart_tx_byte[uart] += data_len;
}

void bfgn_msg_data_handle(bfgn_uart_rx_ctx_t *ctx, uint16_t data_len)
{
    uart_rx_data_buf_t *rx_data_buf = ctx->rx_data_buf;
    rx_data_buf->data_len += data_len;

    switch (ctx->msg_type) {
        case GNSS_FIRST_MSG:
        case GNSS_COMMON_MSG:
            /* 需要等待报文拼接完成再上报 */
            return;

        default:
            /* 上报收到的报文 */
            break;
    }

    /* UART RX维测信息 */
    bfgn_uart_rx_stat(ctx->uart, ctx->msg_type, ((const char *)rx_data_buf->data)[0], rx_data_buf->data_len);

    if (g_pf_data_handle[ctx->msg_type] != NULL) {
        g_pf_data_handle[ctx->msg_type](ctx->uart, (const char *)rx_data_buf->data, (uint16_t)rx_data_buf->data_len);
    }

    rx_data_buf->data_len = 0;
}

void ps_uart_state_print(void)
{
}

void ps_uart_state_dump(struct ps_core_s *ps_core_d)
{
}

int change_tty_baud_rate(struct bus* bus_controller, uint32_t baud_rate, uint8_t enable_flowctl)
{
    return hal_uart_config(bus_controller, UART_SET_BAUDRATE, (void*)&baud_rate, sizeof(uint32_t));
}

/* 配置业务使用波特率，然后起uart接收中断 */
int32_t open_tty_drv(struct ps_core_s *ps_core_d)
{
    struct tty_struct* tty = &ps_core_d->tty;
    hal_uart_config(tty->bus, UART_SET_BAUDRATE, &tty->baud_rate, sizeof(uint32_t));
    // TODO: 待低功耗引脚适配 hal_gpio_irq_enable(ps_core_d->tty.irq_gpio, IRQ_ENABLE);
    return 0;
}

int32_t release_tty_drv(struct ps_core_s *ps_core_d)
{
    // TODO: 待低功耗引脚适配 hal_gpio_irq_enable(ps_core_d->tty.irq_gpio, IRQ_DISABLE);
    return 0;
}

static void bfgn_wrong_status_handle(bfgn_uart_rx_ctx_t *ctx)
{
    PRINT_ERR("bfgn_wrong_status_handle: rx_status=%d", ctx->rx_status);
    if (ctx->rx_status == MSG_HEADER) {
        /* 从第2个字节开始查找0x7E */
        for (uint16_t idx = 1; idx < BFGN_MSG_HEADER_LEN; idx++) {
            if (ctx->head_buff[idx] != BFGN_MSG_START) {
                continue;
            }

            if (memmove_s((void *)ctx->head_buff, BFGN_MSG_HEADER_LEN, (const void *)&ctx->head_buff[idx],
                          BFGN_MSG_HEADER_LEN - idx)  != EOK) {
                    return;
                }
            bfgn_uart_obj_set(ctx, ctx->head_buff + BFGN_MSG_HEADER_LEN - idx, idx);
            return;
        }
    }

    ctx->rx_status = MSG_HEADER;
    ctx->data_local = ctx->head_buff;
    ctx->msg_recv_len = BFGN_MSG_HEADER_LEN;
    bfgn_uart_obj_set(ctx, ctx->data_local, BFGN_MSG_HEADER_LEN);
}

static void bfgn_msg_header_handle(bfgn_uart_rx_ctx_t *ctx)
{
    int32_t ret;
    uint32_t msg_max_len = BFGN_MSG_MAX_LEN;
    bfgn_msg_header_t *msg_header = (bfgn_msg_header_t *)ctx->head_buff;

    /* 判断包头首字节是否为0x7E */
    if (oal_unlikely(msg_header->msg_start != BFGN_MSG_START)) {
        bfgn_wrong_status_handle(ctx);
        return;
    }

    /* 获取包的类型及长度 */
    ctx->msg_type = msg_header->msg_type;
    ctx->msg_len = msg_header->msg_len;

    /* 判断包类型和包长度是否错误 */
    if (oal_unlikely(ctx->msg_type >= MSG_BUTT)) {
        bfgn_wrong_status_handle(ctx);
        return;
    }

    msg_max_len = BT_MSG_MAX_LEN;
    /* BFGN_MSG_MAX_LEN需要根据报文类型适配 */
    if (oal_unlikely((ctx->msg_len < BFGN_MSG_MIN_LEN) || (ctx->msg_len > msg_max_len))) {
        PRINT_ERR("ctx->msg_len is failed! %d", ctx->msg_len);
        bfgn_wrong_status_handle(ctx);
        return;
    }

    ctx->msg_recv_len = ctx->msg_len - (BFGN_MSG_HEADER_LEN + BFGN_MSG_TAIL_LEN);

    /* 接收长度和接收首地址可能已经改变 */
    ret = bfgn_data_store_handle(ctx, &ctx->data_local, &ctx->msg_recv_len);
    if (ret == BFGN_SUCC) {
        /* 更新接收参数 */
        bfgn_uart_obj_set(ctx, ctx->data_local, ctx->msg_recv_len);
        /* 改变接收数据状态 */
        ctx->rx_status = MSG_PAYLOAD;
    } else {
        bfgn_wrong_status_handle(ctx);
        return;
    }
}

static void bfgn_msg_payload_handle(bfgn_uart_rx_ctx_t *ctx)
{
    ctx->rx_status = MSG_TAIL;
    ctx->data_local = ctx->tail_buff;
    ctx->msg_recv_len = BFGN_MSG_TAIL_LEN;
    bfgn_uart_obj_set(ctx, ctx->data_local, ctx->msg_recv_len);
}

static void bfgn_msg_tail_handle(bfgn_uart_rx_ctx_t *ctx)
{
    ctx->rx_done = true;

    if (oal_unlikely(ctx->tail_buff[0] != BFGN_MSG_TAIL)) {
        /* 异常：接收结束 */
        return;
    }

    bfgn_msg_data_handle(ctx, ctx->msg_len - (BFGN_MSG_HEADER_LEN + BFGN_MSG_TAIL_LEN));
}

static void bfgn_data_rx(bfgn_uart_rx_ctx_t *ctx)
{
    switch (ctx->rx_status) {
        case MSG_HEADER:
            bfgn_msg_header_handle(ctx);
            break;

        case MSG_PAYLOAD:
            bfgn_msg_payload_handle(ctx);
            break;

        case MSG_TAIL:
            bfgn_msg_tail_handle(ctx);
            break;

        default:
            bfgn_wrong_status_handle(ctx);
            break;
    }
}

#define UART_RETRY_TIMES 5
int32_t bfgn_uart_read(struct uart_adapter *adapter, bfgn_uart_rx_ctx_t *ctx)
{
    /* 读fifo状态 */
    for (uint8_t i = 0; i < UART_RETRY_TIMES; i++) {
        if ((readl(adapter->base + UARTFR) & RXFE) != 0) {
            osDelay(1);
            continue;
        }

        return hal_uart_dev_read(&adapter->bus_controller, (char *)ctx->rx_buf, ctx->rx_buf_len, HAL_UART_TRANS_DMA);
    }

    return -1;
}

void bfgn_uart_recv_loop(struct uart_adapter *adapter)
{
    uint8_t uart = (adapter->p_reso->bus_num == BT_UART_BUS) ? 0 : 1;
    bfgn_uart_rx_ctx_t *ctx = bfgn_uart_rx_ctx_init(uart);
    if (ctx == NULL) {
        return;
    }

    int ret;
    while (!ctx->rx_done) {
        ret = bfgn_uart_read(adapter, ctx);
        if (ret != 0) {
            return;
        }

        bfgn_data_rx(ctx);
    }
}

int32_t bfgn_uart_dev_write(struct bus* bus_controller, char* buf, int32_t len, int32_t type)
{
    int32_t ret;
    int32_t data_len = 0;
    uint16_t count = 0;
    while ((len - data_len) != 0) {
        ret = hal_uart_dev_write(bus_controller, (char *)buf + data_len, len - data_len, type);
        data_len += ret;
        if (count > UART_WRITE_TIMEOUT_CNT) {
            PRINT_ERR("bfgn uart dev write error!");
            break;
        }
        count++;
    }
    return data_len;
}

int32_t plat_uart_enable(struct ps_core_s *core_data)
{
    return hal_uart_config(core_data->tty.bus, UART_ENABLE, NULL, 0);
}

int32_t plat_uart_disable(struct ps_core_s *core_data)
{
    return hal_uart_config(core_data->tty.bus, UART_DISABLE, NULL, 0);
}

int32_t plat_uart_init(struct ps_core_s *core_data, int uart)
{
    /* 获取uart的设备信息，并且保存到全局变量，并且注册中断信息，处理流程 */
    struct tty_struct *tty = &core_data->tty;
    uint32_t bus_num = BT_UART_BUS;
    uint32_t baud_rate = BT_UART_BAUDRATE;
    uint32_t rx_buf_size = BT_MSG_MAX_LEN;

    if (uart >= UART_BUTT) {
        return -1;
    }

    tty->bus = hal_bsp_register(TAG_UART, bus_num, NULL);
    tty->adapter = oal_container_of(tty->bus, struct uart_adapter, bus_controller);
    tty->baud_rate = baud_rate;
    tty->uart = uart;
    tty->flow_cntrl = 1;

    g_uart_rx_data_buf[uart].data = g_bt_uart_rx;
    g_uart_rx_data_buf[uart].data_len = 0;
    g_uart_rx_data_buf[uart].data_maxlen = rx_buf_size;

    osDelay(1);
    hal_uart_config(tty->bus, UART_SET_BAUDRATE, &tty->baud_rate, sizeof(uint32_t));

    PRINT_INFO("plat_uart_init[%d] tty->adapter[%x] tty->baud_rate[%d] over!", uart, tty->adapter, tty->baud_rate);

    return 0;
}

int32_t plat_uart_exit(int index)
{
    return 0;
}
