/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for plat init
 * Author: plat drivers
 */
#define USE_LOG_TAG_FUNC
#define pr_fmt(fmt) "2[hisi_plat]" fmt

/* 头文件包含 */
#include "plat_main.h"
#include "securec.h"
#include "oal_net.h"
#include "ohos_init.h"
#include "board.h"
#include "plat_pm.h"
#include "plat_uart.h"
#include "bfgx_dev.h"
#include "bfgx_platform_msg_handle.h"
#include "plat_oam.h"
#include "plat_sys_msg.h"
#include "plat_exception_rst.h"
#include "plat_debug.h"

#define TASK_PRIORITY_PLAT_RX   (osPriorityAboveNormal2)
#define TASK_PRIORITY_PLAT_TX   (osPriorityHigh)
#define TASK_PRIORITY_PLAT_INIT (osPriorityHigh)
#define TASK_STACKSIZE_PLAT     0x400
#define TASK_STACKSIZE_INIT     0x1000
#define QUEUE_BUART_TX_LEN      32
#define QUEUE_GUART_TX_LEN      16
#define BFGN_EVT_UART_RX        0x4

plat_uart_task_info_t g_uart_task_inf[UART_BUTT];

osMessageQueueId_t bfgn_uart_tx_queue_create(uint8_t uart, const char *name)
{
    osMessageQueueAttr_t attr = { 0 };
    uint32_t queue_len;

    if (uart == BUART) {
        queue_len = QUEUE_BUART_TX_LEN;
    } else if (uart == GUART) {
        queue_len = QUEUE_GUART_TX_LEN;
    } else {
        return NULL;
    }
    attr.name = name;
    osMessageQueueId_t id = osMessageQueueNew(queue_len, sizeof(plat_msg_t), &attr);
    if (id == NULL) {
        PRINT_ERR("plat_init: bfgn_uart_tx_queue_create error!");
        return NULL;
    }

    PRINT_INFO("plat_init: bfgn_uart_tx_queue_create success!");
    return id;
}

void bfgn_uart_tx_queue_clear(uint8_t uart)
{
    plat_msg_t work;
    plat_uart_task_info_t *task_inf = bfgn_get_uart_task_info(uart);

    while (osMessageQueueGetSpace(task_inf->tx_queue) < QUEUE_BUART_TX_LEN) {
        osMessageQueueGet(task_inf->tx_queue, &work, NULL, osWaitForever);
        oal_large_free(work.buf);
    }
}

plat_uart_task_info_t *bfgn_get_uart_task_info(uint8_t uart)
{
    return (uart == BUART) ? &g_uart_task_inf[BUART] : &g_uart_task_inf[GUART];
}

static inline const char *bfgn_get_queue_name(uint8_t uart)
{
    return (uart == BUART) ? "bt queue" : "gnss queue";
}

static inline const char *bfgn_get_rx_task_name(uint8_t uart)
{
    return (uart == BUART) ? "bt urx" : "gnss urx";
}

static inline const char *bfgn_get_tx_task_name(uint8_t uart)
{
    return (uart == BUART) ? "bt utx" : "gnss utx";
}

static void bfgn_uart_irq_handler(void *param)
{
    plat_uart_task_info_t *task_inf = (plat_uart_task_info_t *)param;
    if (task_inf == NULL) {
        return;
    }

    struct uart_adapter *adapter = task_inf->adapter;
    if (adapter == NULL) {
        return;
    }

    uint32_t int_val = readl(adapter->base + UARTMIS);
    if (int_val & (OVERFLOW_ERR | BREAK_ERR | FRAME_ERR)) {
        writel((OVERFLOW_ERR | BREAK_ERR | FRAME_ERR), adapter->base + UARTICR);
    }

    if (int_val & (RX | RX_TIMEOUT)) {
        osa_irq_disable(adapter->p_reso->irq_num);
        writel(RX | RX_TIMEOUT, adapter->base + UARTICR);
        osa_irq_clear(adapter->p_reso->irq_num);
        osSignalSet(task_inf->rx_thread, BFGN_EVT_UART_RX);
        return;
    }
}

int32_t bfgn_uart_irq_init(uint8_t uart)
{
    plat_uart_task_info_t *task_inf = bfgn_get_uart_task_info(uart);
    if (task_inf == NULL) {
        return BFGN_FAIL;
    }

    struct ps_core_s *ps_core_d = ps_get_core_reference(uart);
    if (ps_core_d == NULL) {
        return BFGN_FAIL;
    }

    task_inf->adapter = ps_core_d->tty.adapter;

    if (readl(task_inf->adapter->base + UARTMIS) & (RX | RX_TIMEOUT)) {
        writel((RX | RX_TIMEOUT), task_inf->adapter->base + UARTICR);
    }

    int32_t ret = osa_irq_create(task_inf->adapter->p_reso->irq_num, OS_HWI_PRIO_14, bfgn_uart_irq_handler, task_inf);
    if (ret != 0) {
        PRINT_ERR("plat_init: bfgn_uart_irq_init[%d] Error ret = %d", uart, ret);
        return BFGN_FAIL;
    }

    if (uart == GUART) {
        /* gnss uart, disable irq. */
        osa_irq_disable(task_inf->adapter->p_reso->irq_num);
    }

    PRINT_INFO("plat_init: bfgn_uart_irq_init[%d] success", uart);
    return BFGN_SUCC;
}

static void bfgn_uart_tx_handle(void *param)
{
    plat_uart_task_info_t *task_inf = (plat_uart_task_info_t *)param;
    if (task_inf == NULL) {
        return;
    }

    struct uart_adapter *adapter = task_inf->adapter;
    if (adapter == NULL) {
        return;
    }

    osStatus_t status;
    plat_msg_t msg;
    osMessageQueueId_t queue_id = task_inf->tx_queue;
    int32_t ret;

    while (true) {
        status = osMessageQueueGet(queue_id, &msg, NULL, osWaitForever);
        MCU_TASK_BEGIN();
        if (status == osOK) {
            osSemaphoreAcquire(task_inf->tx_sem, osWaitForever);
            bfgn_uart_tx_stat(msg.uart, msg.buf, msg.buf_len);
            ret = bfgn_uart_dev_write(&adapter->bus_controller, (char *)msg.buf, msg.buf_len, HAL_UART_TRANS_DMA);
            oal_large_free(msg.buf);
            osSemaphoreRelease(task_inf->tx_sem);
        }
        MCU_TASK_END();
    }
}

static inline bool plat_get_uart_status(uint8_t uart)
{
    return true;
}

static void bfgn_uart_rx_handle(void *param)
{
    plat_uart_task_info_t *task_inf = (plat_uart_task_info_t *)param;
    if (task_inf == NULL) {
        return;
    }

    struct uart_adapter *adapter = task_inf->adapter;
    if (adapter == NULL) {
        return;
    }

    uint16_t uart = adapter->p_reso->bus_num;
    while (true) {
        osSignalWait(BFGN_EVT_UART_RX, osWaitForever);

        if (!plat_get_uart_status(uart)) {
            /* 业务未使能，串口默认不接收数据 */
            PRINT_ERR("com%u uart not work", uart);
            continue;
        }

        MCU_TASK_BEGIN();

        uint32_t uart_sts_mask = (uart == GNSS_UART_BUS) ? 0x80000000 : 0x01000000;
        uint32_t uart_clksts_val = readl(IOMCU_CLKSTAT0);
        uint32_t uart_rststs_val = readl(IOMCU_RSTSTAT0);
        if (((uart_clksts_val & uart_sts_mask) == 0) || ((uart_rststs_val & uart_sts_mask) != 0)) {
            PRINT_ERR("com%u task: clk: %08x, rst: %08x", uart, uart_clksts_val, uart_rststs_val);

            writel(BIT(SOC_IOMCU_CLKEN1_iomcu_clken1_0peri0_START), IOMCU_CLKEN1);
            if (adapter->p_reso->clk_reg != 0) {
                writel(BIT(adapter->p_reso->clk_bit), adapter->p_reso->clk_reg);
            }

            if (adapter->p_reso->rst_reg != 0) {
                writel(BIT(adapter->p_reso->rst_bit), adapter->p_reso->rst_reg);
                writel(BIT(adapter->p_reso->rst_bit), en_reg_to_dis(adapter->p_reso->rst_reg));
            }

            osa_irq_enable(adapter->p_reso->irq_num);
            MCU_TASK_END();
            continue;
        }

        while ((readl(task_inf->adapter->base + UARTFR) & RXFE) == 0) {
            bfgn_uart_recv_loop(adapter);
        }

        /* 接收完数据清除uart err中断 */
        if (readl(task_inf->adapter->base + UARTMIS) & (OVERFLOW_ERR | BREAK_ERR | FRAME_ERR)) {
            writel((OVERFLOW_ERR | BREAK_ERR | FRAME_ERR), task_inf->adapter->base + UARTICR);
        }

        osa_irq_enable(adapter->p_reso->irq_num);
        MCU_TASK_END();
    }
}

static int32_t platform_uart_task_init(uint8_t uart)
{
    plat_uart_task_info_t *task_inf = bfgn_get_uart_task_info(uart);
    if (task_inf == NULL) {
        return BFGN_FAIL;
    }

    task_inf->tx_queue = bfgn_uart_tx_queue_create(uart, bfgn_get_queue_name(uart));
    if (task_inf->tx_queue == NULL) {
        PRINT_ERR("plat_init: task_inf->tx_queue[%d] Error", uart);
        return BFGN_FAIL;
    }

    osThreadAttr_t attr = { "", 0, NULL, 0, NULL, TASK_STACKSIZE_PLAT, TASK_PRIORITY_PLAT_TX, 0, 0 };
    attr.name = bfgn_get_tx_task_name(uart);
    task_inf->tx_thread = osThreadNew(bfgn_uart_tx_handle, task_inf, &attr);
    if (task_inf->tx_thread == NULL) {
        PRINT_ERR("plat_init: task_inf->tx_thread[%d] Error", uart);
        return BFGN_FAIL;
    }

    attr.name = bfgn_get_rx_task_name(uart);
    attr.priority = TASK_PRIORITY_PLAT_RX;
    attr.stack_size = TASK_STACKSIZE_INIT;
    task_inf->rx_thread = osThreadNew(bfgn_uart_rx_handle, task_inf, &attr);
    if (task_inf->rx_thread == NULL) {
        PRINT_ERR("plat_init: task_inf->rx_thread[%d] Error", uart);
        return BFGN_FAIL;
    }

    task_inf->prepare = NULL;
    task_inf->tx_sem = osSemaphoreNew(1, 1, NULL);
    if (task_inf->tx_sem == NULL) {
        PRINT_ERR("plat_init: task_inf->tx_sem[%d] Error", uart);
        return BFGN_FAIL;
    }

    if (bfgn_uart_irq_init(uart) != BFGN_SUCC) {
        PRINT_ERR("plat_init: bfgn_uart_irq_init[%d] Error", uart);
        return BFGN_FAIL;
    }

    PRINT_INFO("plat_init: task_inf[%d] init success", uart);
    return BFGN_SUCC;
}

/* 平台发送消息到对应uart task接口 */
int32_t platform_task_send_msg(uint8_t uart, uint8_t type, uint8_t *data, uint16_t data_len)
{
    plat_uart_task_info_t *task_inf = bfgn_get_uart_task_info(uart);
    if (task_inf == NULL) {
        PRINT_ERR("platform_task_send_msg not init!");
        return BFGN_FAIL;
    }

    if (osMessageQueueGetSpace(task_inf->tx_queue) == 0) {
        PRINT_ERR("platform_task_send_msg queue is full!");
        return BFGN_FAIL;
    }

    plat_msg_t msg;
    msg.uart = uart;
    msg.type = type;
    msg.buf = data;
    msg.buf_len = data_len;
    osStatus_t status = osMessageQueuePut(task_inf->tx_queue, &msg, 0, 0);
    if (status != osOK) {
        PRINT_ERR("platform_task_send_msg send queue error, err=%d!", status);
        return BFGN_FAIL;
    }

    PRINT_DEBUG("platform_task_send_msg send queue success!");

    return BFGN_SUCC;
}

static void platfrom_task_init_handle(void *param)
{
    if (plat_oam_msg_init() != BFGN_SUCC) {
        PRINT_ERR("plat_init: plat_oam_msg_init error\r");
        return;
    }

    PRINT_INFO("plat_init: platform_task_init success!");
}

int32_t platform_task_init(void)
{
    osThreadAttr_t attr = { "hisi plat task", 0, NULL, 0, NULL, TASK_STACKSIZE_INIT, TASK_PRIORITY_PLAT_INIT, 0, 0 };
    osThreadId_t id;

    if (platform_uart_task_init(BUART) != BFGN_SUCC) {
        PRINT_ERR("plat_init: platform_task_init uart[%d] Error", BUART);
        return BFGN_FAIL;
    }

    plat_sys_msg_init();

    id = osThreadNew(platfrom_task_init_handle, NULL, &attr);
    if (id == NULL) {
        PRINT_ERR("plat_init: plat task init Error!");
        return BFGN_FAIL;
    }

    return BFGN_SUCC;
}

/*
 * 函 数 名  : plat_init
 * 功能描述  : 平台初始化函数总入口
 */
int32_t plat_init(void)
{
    int32_t l_return;

    // board初始化，相关钩子接口挂载，以及涉及设备进行初始化
    l_return = hi110x_board_init();
    if (l_return != OAL_SUCC) {
        PRINT_ERR("plat_init: hi110x_board_init fail\r");
        goto board_init_fail;
    }

    // 主模块初始化
    l_return = low_power_init();
    if (l_return != OAL_SUCC) {
        PRINT_ERR("plat_init: low_power_init return error code: %d\r", l_return);
        goto board_init_fail;
    }

    // dfr功能初始化
    l_return = plat_exception_reset_init();
    if (l_return != OAL_SUCC) {
        PRINT_ERR("plat_init: plat_exception_reset_init fail\r");
        goto board_init_fail;
    }

    // 平台初入口task初始化
    l_return = platform_task_init();
    if (l_return != OAL_SUCC) {
        PRINT_ERR("plat_init: platform_task_init return error code: %d\r", l_return);
        goto board_init_fail;
    }

    /* 启动完成后，输出打印 */
    PRINT_ERR("plat_init::platform_main_init finish!\r");

    /* 启动完成后置位，用于ap侧获取状态 */
    bfgx_set_device_init_status(MCU_INIT_SUCC);
    return OAL_SUCC;

board_init_fail:
    bfgx_set_device_init_status(MCU_INIT_FAIL);
    return l_return;
}
SYS_SERVICE_INIT(plat_init);
