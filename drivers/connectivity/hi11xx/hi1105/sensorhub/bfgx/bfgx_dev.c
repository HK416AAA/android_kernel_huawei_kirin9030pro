/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for bt node
 * Author: bfgx drivers
 */

#define USE_LOG_TAG_FUNC
#define pr_fmt(fmt) "2[hisi_plat]" fmt

/* Include Head file */
#include "board.h"
#include "plat_uart.h"
#include "hw_bfg_ps.h"
#include "plat_pm.h"
#include "plat_main.h"
#include "bfgx_data_parse.h"
#include "plat_debug.h"
#include "mpxx_dev.h"
#include "plat_ipc.h"
#include "bfgx_dev.h"

typedef struct subsys_status_stat {
    uint32_t open_succ;
    uint32_t open_fail;
    uint32_t close_succ;
    uint32_t close_fail;
    uint32_t exception_cnt;
} subsys_status_stat_t;

STATIC subsys_status_stat_t g_subsys_status_stat[UART_BUTT] = { 0 };

#define UART_TEST_DEV_ACK_TIMEOUT_MS 5000
#define UART_LOOP_TEST_LOOP_DATA_SIZE 4
uint8_t g_uart_loop_data[UART_LOOP_TEST_LOOP_DATA_SIZE] = {0x5A, 0xA5, 0x00, 0xFF};
uart_loop_test_ctx g_uart_loop_ctx = {
    .wait = 1,
    .fail = 0,
    .set = 0,
    .finish = 0,
    .result = UART_LOOP_RES_INIT
};

/*
 * This references is the per-PS platform device in the arch/arm/
 * board-xx.c file.
 */
STATIC struct platform_device *g_hw_ps_device = NULL;
STATIC oal_atomic_t g_debug_cnt = oal_atomic_init(0);
STATIC struct ps_core_s *g_sw_ps_core[UART_BUTT] = { NULL };

STATIC uint32_t g_bfgx_open_cmd[BFGX_BUTT] = {
    SYS_CFG_OPEN_BT,
    SYS_CFG_OPEN_FM,
    SYS_CFG_OPEN_GNSS,
};

STATIC uint32_t g_bfgx_close_cmd[BFGX_BUTT] = {
    SYS_CFG_CLOSE_BT,
    SYS_CFG_CLOSE_FM,
    SYS_CFG_CLOSE_GNSS,
};

STATIC uint32_t g_bfgx_open_cmd_timeout[BFGX_BUTT] = {
    WAIT_BT_OPEN_TIME,
    WAIT_FM_OPEN_TIME,
    WAIT_GNSS_OPEN_TIME,
};

STATIC uint32_t g_bfgx_close_cmd_timeout[BFGX_BUTT] = {
    WAIT_BT_CLOSE_TIME,
    WAIT_FM_CLOSE_TIME,
    WAIT_GNSS_CLOSE_TIME,
};

#define UART_LOOP_CMD_WAIT_CNT 6
#define UART_LOOP_CMD_WAIT_TIME 500
#define UART_LOOP_TEST_WAIT_TIME 100
#define UART_LOOP_TEST_TIMEOUT_CNT 50

const char *g_bfgx_subsys_name[BFGX_BUTT] = {
    "BT",
    "FM",
    "GNSS",
};

STATIC uint8_t g_device_init_status = MCU_INIT_WAIT;

uint32_t g_gnss_me_thread_status = DEV_THREAD_EXIT;
uint32_t g_gnss_lppe_thread_status = DEV_THREAD_EXIT;

STATIC bool g_device_log_status = false;
void ps_set_device_log_status(bool status)
{
    g_device_log_status = status;
}
bool ps_is_device_log_enable(void)
{
    return true;
}

void bfgx_set_device_init_status(uint8_t status)
{
    g_device_init_status = status;
}

void bfgx_send_device_init_status_to_ap(void)
{
    hw_plat_ipc_ctx_t *ctx = hw_plat_get_ipc_ctx();
    mcu_init_status_cmd_t  bt_status_ack;

    bt_status_ack.ipc_hdr.msg_code = BFGN_OP_CODE_BT_INIT_STATUS_ACK;
    bt_status_ack.ipc_hdr.msg_len = sizeof(mcu_init_status_cmd_t);
    bt_status_ack.ipc_hdr.seq = ctx->seq++;
    bt_status_ack.status = g_device_init_status;

    PRINT_INFO("send init status : 0x%x", g_device_init_status);

    plat_ipc_send_cmd(CMD_CONNECT_MCU_TO_AP, (const uint8_t *)&bt_status_ack, sizeof(mcu_init_status_cmd_t));
}

static inline uint32_t bfgx_subsys_to_type(uint32_t subsys)
{
    switch (subsys) {
        case BFGX_BT:
            return BUART;
        case BFGX_GNSS:
            return GUART;
        default:
            break;
    }

    return UART_BUTT;
}

void bfgx_subsys_status_stat_open_succ(uint32_t subsys)
{
    uint32_t type = bfgx_subsys_to_type(subsys);
    if (type >= UART_BUTT) {
        return;
    }

    g_subsys_status_stat[type].open_succ++;
    PRINT_ERR("subsys %d open succ, succ = %u, fail = %u", subsys,
        g_subsys_status_stat[type].open_succ, g_subsys_status_stat[type].open_fail);
}

void bfgx_subsys_status_stat_open_fail(uint32_t subsys)
{
    uint32_t type = bfgx_subsys_to_type(subsys);
    if (type >= UART_BUTT) {
        return;
    }

    g_subsys_status_stat[type].open_fail++;
    PRINT_ERR("subsys %d open fail, succ = %u, fail = %u", subsys,
        g_subsys_status_stat[type].open_succ, g_subsys_status_stat[type].open_fail);
}

void bfgx_subsys_status_stat_close_succ(uint32_t subsys)
{
    uint32_t type = bfgx_subsys_to_type(subsys);
    if (type >= UART_BUTT) {
        return;
    }

    g_subsys_status_stat[type].close_succ++;
    PRINT_ERR("subsys %d close succ, succ = %u, fail = %u", subsys,
        g_subsys_status_stat[type].close_succ, g_subsys_status_stat[type].close_fail);
}

void bfgx_subsys_status_stat_close_fail(uint32_t subsys)
{
    uint32_t type = bfgx_subsys_to_type(subsys);
    if (type >= UART_BUTT) {
        return;
    }

    g_subsys_status_stat[type].close_fail++;
    PRINT_ERR("subsys %d close fail, succ = %u, fail = %u", subsys,
        g_subsys_status_stat[type].close_succ, g_subsys_status_stat[type].close_fail);
}

void bfgx_subsys_status_stat_exception(uint32_t subsys)
{
    uint32_t type = bfgx_subsys_to_type(subsys);
    if (type >= UART_BUTT) {
        return;
    }

    g_subsys_status_stat[type].exception_cnt++;
    PRINT_ERR("subsys %d exception, cnt = %u", subsys, g_subsys_status_stat[type].exception_cnt);
}

/*
 * Prototype    : ps_get_core_reference
 * Description  : reference the core's data,This references the per-PS
 *                platform device in the arch/xx/board-xx.c file..
 */
struct ps_core_s *ps_get_core_reference(uint32_t type)
{
    return g_sw_ps_core[type];
}

struct ps_core_s *ps_get_subsys_core_reference(uint32_t subsys)
{
    switch (subsys) {
        case BFGX_BT:
            return ps_get_core_reference(BUART);
        case BFGX_SLE:
            return ps_get_core_reference(BUART);
        case BFGX_GNSS:
            return ps_get_core_reference(BUART);
        default:
            break;
    }

    return NULL;
}

/*
 * Prototype    : ps_bfg_subsys_active
 * Description  : check bfgx subsys active or no
 */
bool ps_bfg_subsys_active(uint32_t subsys)
{
    struct ps_core_s *ps_core_d = ps_get_subsys_core_reference(subsys);
    if (ps_core_d == NULL) {
        return false;
    }

    if (oal_atomic_read(&ps_core_d->bfgx_info[subsys].subsys_state) == POWER_STATE_SHUTDOWN) {
        return false;
    }

    return true;
}

/*
 * Prototype    : ps_set_subsys_state
 * Description  : set subsys state
 */
bool ps_set_subsys_state(uint32_t subsys, power_state_enum power_state)
{
    struct ps_core_s *ps_core_d = ps_get_subsys_core_reference(subsys);
    if (ps_core_d == NULL) {
        return false;
    }

    oal_atomic_set(&ps_core_d->bfgx_info[subsys].subsys_state, power_state);

    return true;
}

/*
 * Prototype    : uart_bfgx_close_cmd
 * Description  : functions called by bfgn pm to close bcpu throuhg bfgx system
 */
int32_t uart_bfgx_close_cmd(void)
{
#define WAIT_CLOSE_TIMES 100
    struct ps_core_s *ps_core_d = NULL;
    int bwkup_gpio_val = 1;
    int32_t ret;
    int i;
    int32_t prepare_result;

    ps_core_d = ps_get_core_reference(BUART);
    if (oal_unlikely(ps_core_d == NULL)) {
        PRINT_ERR("ps_core_d is err");
        return -EINVAL;
    }

    /* 如果BFGIN睡眠，则唤醒之 */
    ret = prepare_to_visit_node(ps_core_d, &prepare_result);
    if (ret < 0) {
        PRINT_ERR("prepare work FAIL");
        return ret;
    }

    /* 下发BFGIN shutdown命令 */
    PRINT_INFO("uart shutdown CPU");

    ps_tx_sys_cmd(ps_core_d, SYS_MSG, SYS_CFG_SHUTDOWN_SLP);

    post_to_visit_node(ps_core_d, prepare_result);

    return ret;
}

int32_t bfgx_open_cmd_send(struct ps_core_s *ps_core_d, uint8_t subsys)
{
    if (ps_core_d == NULL || subsys >= BFGX_BUTT) {
        PRINT_ERR("open cmd para err! subsys=%d", subsys);
        return -EINVAL;
    }

    if (subsys == BFGX_GNSS) {
        return 0;
    }

    return ps_tx_sys_cmd(ps_core_d, SYS_MSG, g_bfgx_open_cmd[subsys]);
}

int32_t bfgx_close_cmd_send(struct ps_core_s *ps_core_d, uint8_t subsys)
{
    if (ps_core_d == NULL || subsys >= BFGX_BUTT) {
        PRINT_ERR("close cmd para err! subsys=%d", subsys);
        return -EINVAL;
    }

    ps_tx_sys_cmd(ps_core_d, SYS_MSG, g_bfgx_close_cmd[subsys]);

    return 0;
}

STATIC int32_t hw_bfgx_start(struct ps_core_s *ps_core_d, uint32_t subsys)
{
    struct st_bfgx_data *pst_bfgx_data = NULL;
    struct pm_drv_data *pm_data = NULL;
    int32_t error;

    pm_data = ps_core_d->pm_data;
    pst_bfgx_data = &ps_core_d->bfgx_info[subsys];

    if (bfgx_open_cmd_send(ps_core_d, subsys) != BFGX_POWER_SUCCESS) {
        PRINT_ERR("bfgx open cmd fail");
        error = BFGX_POWER_OPEN_CMD_FAIL;
        goto bfgx_open_cmd_fail;
    }

    oal_atomic_set(&pst_bfgx_data->subsys_state, POWER_STATE_OPEN);

    return BFGX_POWER_SUCCESS;

bfgx_open_cmd_fail:
    bfgx_subsys_status_stat_open_fail(subsys);
    return BFGX_POWER_FAILED;
}

int32_t hw_bfgx_open(uint32_t subsys)
{
    int32_t ret;
    struct ps_core_s *ps_core_d = ps_get_subsys_core_reference(subsys);
    struct st_bfgx_data *pst_bfgx_data = NULL;
    struct pm_drv_data *pm_data = NULL;

    PRINT_ERR("enter hw_bfgx_open(%d)", subsys);

    if (oal_unlikely((ps_core_d == NULL) || (ps_core_d->pm_data == NULL))) {
        PRINT_ERR("leave hw_bfgx_open() error 0.");
        bfgx_subsys_status_stat_open_fail(subsys);
        return -EINVAL;
    }

    pm_data = ps_core_d->pm_data;
    pst_bfgx_data = &ps_core_d->bfgx_info[subsys];

    if (oal_atomic_read(&pst_bfgx_data->subsys_state) == POWER_STATE_OPEN) {
        PRINT_ERR("has opened! It's Not necessary to send msg to device");
        bfgx_subsys_status_stat_open_succ(subsys);
        return BFGX_POWER_SUCCESS;
    }

    hal_uart_config(ps_core_d->tty.bus, UART_RESET, NULL, 0);
    ret = hw_bfgx_start(ps_core_d, subsys);
    if (ret == 0) {
        bfgx_subsys_status_stat_open_succ(subsys);
    } else {
        bfgx_subsys_status_stat_open_fail(subsys);
    }

    PRINT_ERR("leave hw_bfgx_open() ret = %d", ret);
    return ret;
}

int32_t hw_bfgx_close(uint32_t subsys)
{
    struct ps_core_s *ps_core_d = ps_get_subsys_core_reference(subsys);
    struct st_bfgx_data *pst_bfgx_data = NULL;
    int32_t ret;
    struct pm_drv_data *pm_data = NULL;

    PRINT_ERR("enter hw_bfgx_close(%d)", subsys);

    if (subsys >= BFGX_BUTT) {
        PRINT_ERR("subsys is err, subsys is [%d]", subsys);
        return -EINVAL;
    }

    if (oal_unlikely((ps_core_d == NULL) || (ps_core_d->pm_data == NULL))) {
        PRINT_ERR("ps_core_d is NULL");
        bfgx_subsys_status_stat_close_fail(subsys);
        return -EINVAL;
    }
    pm_data = ps_core_d->pm_data;
    pst_bfgx_data = &ps_core_d->bfgx_info[subsys];

    if (oal_atomic_read(&pst_bfgx_data->subsys_state) == POWER_STATE_SHUTDOWN) {
        PRINT_WARN("has closed! It's Not necessary to send msg to device");
        bfgx_subsys_status_stat_close_succ(subsys);
        return BFGX_POWER_SUCCESS;
    }

    ret = bfgx_close_cmd_send(ps_core_d, subsys);
    if (ret < 0) {
        /* 发送close命令失败，不进行DFR，继续进行下电流程，DFR恢复延迟到下次open时或者其他业务运行时进行 */
        PRINT_ERR("bfgx close cmd fail");
    }

    oal_atomic_set(&pst_bfgx_data->subsys_state, POWER_STATE_SHUTDOWN);
    if (ret == 0) {
        bfgx_subsys_status_stat_close_succ(subsys);
    } else {
        bfgx_subsys_status_stat_close_fail(subsys);
    }

    PRINT_ERR("leave hw_bfgx_close() ret = %d", ret);
    return ret;
}

static int32_t hw_bfgx_open_subsys(uint32_t subsys)
{
    int32_t ret;
    struct pm_top* pm_top_data = pm_get_top();

    oal_mutex_lock(&(pm_top_data->host_mutex));
    ret = hw_bfgx_open(subsys);
    oal_mutex_unlock(&(pm_top_data->host_mutex));

    return ret;
}

static int32_t hw_bfgx_close_subsys(uint32_t subsys)
{
    int32_t ret;
    struct pm_top* pm_top_data = pm_get_top();

    oal_mutex_lock(&(pm_top_data->host_mutex));
    ret = hw_bfgx_close(subsys);
    oal_mutex_unlock(&(pm_top_data->host_mutex));

    return ret;
}

/* device bfgx pm debug switch on/off */
void plat_pm_debug_switch(void)
{
    struct ps_core_s *ps_core_d = NULL;
    int32_t ret;
    int32_t prepare_result;

    ps_core_d = ps_get_core_reference(BUART);
    if (oal_unlikely(ps_core_d == NULL)) {
        PRINT_ERR("ps_core_d is NULL");
        return;
    }

    ret = prepare_to_visit_node(ps_core_d, &prepare_result);
    if (ret < 0) {
        PRINT_ERR("prepare work FAIL");
        return;
    }

    ps_tx_sys_cmd(ps_core_d, SYS_MSG, PL_PM_DEBUG);

    post_to_visit_node(ps_core_d, prepare_result);

    return;
}

int32_t plat_bfgx_dump_rotate_cmd_read(struct ps_core_s *ps_core_d, unsigned long arg)
{
    return 0;
}

uart_loop_cfg g_uart_loop_test_cfg = { 256, 2048, 0, 0, 0 };
uart_loop_test_struct *g_uart_loop_test_info = NULL;

STATIC int32_t alloc_uart_loop_test(void)
{
    uint8_t *uart_loop_tx_buf = NULL;
    uint8_t *uart_loop_rx_buf = NULL;
    uint16_t pkt_len = 0;

    if (g_uart_loop_test_info == NULL) {
        g_uart_loop_test_info = (uart_loop_test_struct *)oal_large_malloc(sizeof(uart_loop_test_struct));
        if (g_uart_loop_test_info == NULL) {
            PRINT_ERR("malloc uart_loop_test_info fail");
            goto malloc_test_info_fail;
        }
        memset_s(g_uart_loop_test_info, sizeof(uart_loop_test_struct), 0, sizeof(uart_loop_test_struct));

        pkt_len = g_uart_loop_test_cfg.pkt_len;
        if (pkt_len == 0 || pkt_len > UART_LOOP_MAX_PKT_LEN) {
            pkt_len = UART_LOOP_MAX_PKT_LEN;
            g_uart_loop_test_cfg.pkt_len = UART_LOOP_MAX_PKT_LEN;
        }

        uart_loop_tx_buf = (uint8_t *)oal_large_malloc(pkt_len);
        if (uart_loop_tx_buf == NULL) {
            PRINT_ERR("malloc uart_loop_tx_buf fail");
            goto malloc_tx_buf_fail;
        }

        memset_s(uart_loop_tx_buf, pkt_len, 0xa5, pkt_len);
        uart_loop_rx_buf = (uint8_t *)oal_large_malloc(pkt_len);
        if (uart_loop_rx_buf == NULL) {
            PRINT_ERR("malloc uart_loop_rx_buf fail");
            goto malloc_rx_buf_fail;
        }

        g_uart_loop_test_cfg.uart_loop_enable = 1;
        g_uart_loop_test_cfg.uart_loop_tx_random_enable = 1;

        g_uart_loop_test_info->test_cfg = &g_uart_loop_test_cfg;
        g_uart_loop_test_info->tx_buf = uart_loop_tx_buf;
        g_uart_loop_test_info->rx_buf = uart_loop_rx_buf;
        g_uart_loop_test_info->rx_pkt_len = 0;

        PRINT_INFO("uart loop test, loop count is [%d]", g_uart_loop_test_cfg.loop_count);
    }

    return 0;

malloc_rx_buf_fail:
    oal_large_free(uart_loop_tx_buf);
malloc_tx_buf_fail:
    oal_large_free(g_uart_loop_test_info);
    g_uart_loop_test_info = NULL;
malloc_test_info_fail:
    return -ENOMEM;
}

STATIC void free_uart_loop_test(void)
{
    if (g_uart_loop_test_info == NULL) {
        return;
    }
    PRINT_INFO("free uart loop test buf");
    g_uart_loop_test_cfg.uart_loop_enable = 0;
    oal_large_free(g_uart_loop_test_info->rx_buf);
    oal_large_free(g_uart_loop_test_info->tx_buf);
    oal_large_free(g_uart_loop_test_info);
    g_uart_loop_test_info = NULL;

    return;
}

STATIC void uart_loop_pwr_on(uint8_t uart_type)
{
    PRINT_INFO("the core %u is not open in mcu", uart_type);
}

STATIC void uart_loop_pwr_off(uint8_t uart_type)
{
    PRINT_INFO("the core %u is not close in mcu", uart_type);
}

STATIC int32_t uart_loop_test_open(uint8_t uart_type)
{
    uart_loop_pwr_on(uart_type);
    bfgn_uart_callback_backup(g_gnss_data_handle);
    hw_bt_register_read_callback(uart_loop_test_recv_pkt);
    if (alloc_uart_loop_test() != BFGX_POWER_SUCCESS) {
        PRINT_ERR("alloc mem for uart loop test fail!");
        return -ENOMEM;
    }

    return BFGX_POWER_SUCCESS;
}

STATIC void uart_loop_test_close(uint8_t uart_type)
{
    g_uart_loop_ctx.set = 0;
    g_uart_loop_ctx.wait = 1;
    free_uart_loop_test();
    bfgn_uart_callback_switch_backup(g_gnss_data_handle);
    uart_loop_pwr_off(uart_type);
}

STATIC int32_t uart_loop_test_set(uint8_t uart_type, uint8_t flag)
{
    uint8_t cmd;
    uint16_t count = 0;
    int32_t prepare_result;

    struct ps_core_s *ps_core_d = ps_get_core_reference(uart_type);
    if (oal_unlikely(ps_core_d == NULL)) {
        PRINT_ERR("ps_core_d is null");
        return -EINVAL;
    }

    if (prepare_to_visit_node(ps_core_d, &prepare_result) < 0) {
        PRINT_ERR("prepare work fail");
        return -EFAULT;
    }

    if (flag == UART_LOOP_SET_DEVICE_DATA_HANDLER) {
        cmd = PL_SET_UART_LOOP_HANDLER;
    } else {
        cmd = PL_SET_UART_LOOP_FINISH;
    }

    while (g_uart_loop_ctx.set == 0 && cmd == PL_SET_UART_LOOP_HANDLER) {
        if (count > UART_LOOP_CMD_WAIT_CNT) {
            post_to_visit_node(ps_core_d, prepare_result);
            PRINT_ERR("UART LOOP WAIT SET TIMEOUT ");
            return -EFAULT;
        }
        PRINT_INFO("UART LOOP SETTING ... ");
        ps_tx_sys_cmd(ps_core_d, SYS_MSG, cmd);
        osDelay(UART_LOOP_CMD_WAIT_TIME);
        count ++;
    }

    count = 0;
    if (cmd == PL_SET_UART_LOOP_FINISH) {
        ps_tx_sys_cmd(ps_core_d, SYS_MSG, cmd);
        while (g_uart_loop_ctx.finish == 0) {
            if (count > UART_LOOP_CMD_WAIT_CNT) {
                post_to_visit_node(ps_core_d, prepare_result);
                PRINT_ERR("UART LOOP WAIT FINISH TIMEOUT ");
                return -EFAULT;
            }
            PRINT_INFO("UART LOOP FINISHING ... ");
            osDelay(UART_LOOP_CMD_WAIT_TIME);
            count ++;
        }
    }

    post_to_visit_node(ps_core_d, prepare_result);
    return 0;
}

STATIC int32_t uart_loop_test_send_data(struct ps_core_s *ps_core_d, uint8_t *buf, uint32_t count)
{
    char *tx_buf = NULL;
    uint16_t total_len;
    int ret;

    if (oal_unlikely(ps_core_d == NULL)) {
        PRINT_ERR("uart test ps_core_d is NULL");
        return -EINVAL;
    }

    total_len = count + sizeof(struct ps_packet_head) + sizeof(struct ps_packet_end);
    tx_buf = (char*)oal_large_malloc(total_len);
    if (tx_buf == NULL) {
        PRINT_ERR("uart test send data malloc fail!");
        return -EINVAL;
    }

    ps_add_packet_head((uint8_t *)tx_buf, BT_MSG, total_len);

    if (memcpy_s(&tx_buf[sizeof(struct ps_packet_head)], total_len - sizeof(struct ps_packet_head),
        buf, count) != EOK) {
        PRINT_ERR("buf is not enough");
        oal_large_free(tx_buf);
        return -EINVAL;
    }

    ret = platform_task_send_msg(ps_core_d->tty.uart, MSG_TYPE_TX, (uint8_t *)tx_buf, total_len);
    if (ret != OAL_SUCC) {
        PRINT_ERR("uart test send msg err");
        oal_large_free(tx_buf);
        return -EFAULT;
    }

    return 0;
}

STATIC int32_t uart_loop_test_send_pkt(uint8_t uart_type)
{
    struct ps_core_s *ps_core_d = ps_get_core_reference(uart_type);
    uint16_t count = 0;
    int32_t prepare_result;

    while (g_uart_loop_ctx.set == 0) {
        osDelay(UART_LOOP_TEST_WAIT_TIME);
        if (++count > UART_LOOP_TEST_TIMEOUT_CNT) {
            PRINT_ERR("UART LOOP SET TIMEOUT ");
            return -EFAULT;
        }
    }
    count = 0;

    if (oal_unlikely((ps_core_d == NULL) || (g_uart_loop_test_info == NULL) ||
        (g_uart_loop_test_info->tx_buf == NULL))) {
        PRINT_ERR("para is invalided");
        return -EFAULT;
    }

    if (prepare_to_visit_node(ps_core_d, &prepare_result) < 0) {
        PRINT_ERR("prepare work fail");
        return -EFAULT;
    }

    while (g_uart_loop_ctx.wait == 0) {
        osDelay(UART_LOOP_TEST_WAIT_TIME);
        if (++count > UART_LOOP_TEST_TIMEOUT_CNT) {
            g_uart_loop_ctx.set = 0;
            PRINT_ERR("UART LOOP WAIT CHECK TIMEOUT ");
            post_to_visit_node(ps_core_d, prepare_result);
            return -EFAULT;
        }
    }

    /* to divide up packet function and tx to tty work */
    if (uart_loop_test_send_data(ps_core_d, g_uart_loop_test_info->tx_buf, g_uart_loop_test_cfg.pkt_len) < 0) {
        PRINT_ERR("uart loop test pkt send is err");
        post_to_visit_node(ps_core_d, prepare_result);
        return -EFAULT;
    }

    g_uart_loop_ctx.wait = 0;

    post_to_visit_node(ps_core_d, prepare_result);

    return 0;
}

STATIC int32_t uart_loop_test_data_check(uint8_t *puc_src, uint8_t *puc_dest, uint16_t us_data_len)
{
    uint16_t us_index;

    for (us_index = 0; us_index < us_data_len; us_index++) {
        if (puc_src[us_index] != puc_dest[us_index]) {
            PRINT_INFO("CHECK FAIL index[%d]  src 0x%x    dest 0x%x ",
                       us_index, puc_src[us_index], puc_dest[us_index]);
            g_uart_loop_ctx.fail = 1;
            return false;
        }
    }

    return true;
}

void uart_loop_test_recv_pkt(const char *buf_ptr, uint16_t pkt_len)
{
    uint16_t expect_pkt_len;
    uint8_t *rx_buf = NULL;
    uint16_t recvd_len;

    if ((g_uart_loop_test_info == NULL)) {
        PRINT_ERR("uart_loop_test_recv_pkt null info ");
        return ;
    }

    expect_pkt_len = g_uart_loop_test_info->test_cfg->pkt_len;
    rx_buf = g_uart_loop_test_info->rx_buf;
    recvd_len = g_uart_loop_test_info->rx_pkt_len;

    if (memcpy_s(&rx_buf[0], expect_pkt_len, buf_ptr, expect_pkt_len) != EOK) {
        PRINT_ERR("memcpy_s error, destlen=%d, srclen=%d ", expect_pkt_len - recvd_len, pkt_len);
    }

    if (uart_loop_test_data_check(rx_buf, g_uart_loop_test_info->tx_buf, expect_pkt_len)) {
        PRINT_INFO("uart loop recv pkt SUCC ");
    }
    osDelay(UART_LOOP_TEST_WAIT_TIME);
    memset_s(g_uart_loop_test_info->tx_buf, pkt_len,
             g_uart_loop_data[g_uart_loop_ctx.set % UART_LOOP_TEST_LOOP_DATA_SIZE], pkt_len);
    g_uart_loop_test_info->rx_pkt_len = 0;
    g_uart_loop_ctx.wait = 1;
    g_uart_loop_ctx.set ++;
}

void uart_loop_ctx_complete_set(void)
{
    g_uart_loop_ctx.set = 1;
    g_uart_loop_ctx.fail = 0;
    PRINT_INFO("bfgx uart loop test set ok");
}

void uart_loop_ctx_send_finish(void)
{
    g_uart_loop_ctx.finish = 1;
}

int32_t uart_loop_test(uint8_t uart_type)
{
    uint32_t i, count;
    uint16_t pkt_len;
    unsigned long long tx_total_len;
    unsigned long long total_time = 0;
    unsigned long long cost_time = 0;
    uint64_t start_time, end_time;
    uint8_t *puc_buf = NULL;
    g_uart_loop_ctx.result = UART_LOOP_RES_INIT;

    PRINT_INFO(" ***********  UART LOOP TEST START  ***********  ");
    if (uart_loop_test_open(uart_type) < 0) {
        goto open_fail;
    }

    if (uart_loop_test_set(uart_type, UART_LOOP_SET_DEVICE_DATA_HANDLER) < 0) {
        PRINT_INFO("UART LOOP SET FAIL ");
        goto test_set_fail;
    }

    count = g_uart_loop_test_info->test_cfg->loop_count;
    pkt_len = g_uart_loop_test_info->test_cfg->pkt_len;
    tx_total_len = ((unsigned long long)count) * ((unsigned long long)pkt_len);
    puc_buf = g_uart_loop_test_info->tx_buf;
    PRINT_INFO("UART LOOP MSG: TOTAL CNT: %d; PKT LEN: %d; TX TOTAL LEN: %d", count, pkt_len, tx_total_len);
    memset_s(puc_buf, pkt_len, g_uart_loop_data[0], pkt_len);
    g_uart_loop_ctx.result = UART_LOOP_RUNNING;

    for (i = 0; i < count; i++) {
        start_time = osKernelGetTick2ms();

        if (g_uart_loop_ctx.fail != 0) {
            PRINT_ERR("  UART LOOP TEST FAILURE ");
            uart_loop_test_close(uart_type);
            return -FAILURE;
        }

        if (uart_loop_test_send_pkt(uart_type) != SUCCESS) {
            PRINT_ERR("uart loop test fail, i=[%d]", i);
            goto send_pkt_fail;
        }

        end_time = osKernelGetTick2ms();
        cost_time = ((end_time - start_time) * NS_PER_US);
        total_time += cost_time;
        PRINT_INFO("uart loop test tx ok, i=[%d], time cost=[%d]", i, cost_time);
    }

    if (uart_loop_test_set(uart_type, UART_LOOP_RESUME_DEVICE_DATA_HANDLER) < 0) {
        PRINT_ERR("uart loop test, resume device data handler fail ");
        return -FAILURE;
    }

    uart_loop_test_close(uart_type);
    if (total_time == 0) {
        PRINT_ERR("divisor can not be zero!");
        return -FAILURE;
    }

    if (g_uart_loop_ctx.fail != 0) {
        PRINT_ERR("  UART LOOP TEST FAILURE ");
        return -FAILURE;
    }
    PRINT_INFO("  UART LOOP TEST SUCCESS ");
    return SUCCESS;

send_pkt_fail:
test_set_fail:
    uart_loop_test_close(uart_type);
open_fail:
    return -FAILURE;
}

static void uart_loop_task_bt_handle(void *param)
{
    bfgx_power_on(pm_get_drvdata(BUART), BFGX_GNSS);
    if (uart_loop_test(BUART) == 0) {
        g_uart_loop_ctx.result = SUCCESS;
    } else {
        g_uart_loop_ctx.result = -FAILURE;
    }
    mcu_uart_loop_done_notify_ap_bt();
    bfgx_power_off(pm_get_drvdata(BUART), BFGX_GNSS);
}

static int32_t uart_loop_bt_task(void)
{
    osThreadAttr_t attr = { "BT uart loop task", 0, NULL, 0,
                            NULL, TASK_STACKSIZE_UART_LOOP, TASK_PRIORITY_UART_LOOP, 0, 0 };
    osThreadId_t id;

    id = osThreadNew(uart_loop_task_bt_handle, NULL, &attr);
    if (id == NULL) {
        PRINT_ERR("uart_loop: BT uart loop task Error!");
        return BFGN_FAIL;
    }

    return BFGN_SUCC;
}

int conn_test_buart_loop(void)
{
    if (g_uart_loop_ctx.set > 0) {
        PRINT_ERR("BT uart loop is running ");
        return g_uart_loop_ctx.set;
    } else {
        return uart_loop_bt_task();
    }
}

int conn_test_uart_loop_result(void)
{
    if (g_uart_loop_ctx.set > 0) {
        return UART_LOOP_RUNNING;
    } else {
        return g_uart_loop_ctx.result;
    }
}

STATIC int32_t device_panic(uint8_t uart_type)
{
    int32_t ret;
    int32_t prepare_result;

    struct ps_core_s *ps_core_d = ps_get_core_reference(uart_type);
    if (oal_unlikely(ps_core_d == NULL)) {
        PRINT_ERR("ps_core_d is null");
        return -EINVAL;
    }

    ret = prepare_to_visit_node(ps_core_d, &prepare_result);
    if (ret < 0) {
        PRINT_ERR("prepare work FAIL");
        return ret;
    }

    ps_tx_sys_cmd(ps_core_d, SYS_MSG, SYS_CFG_DEV_PANIC);

    post_to_visit_node(ps_core_d, prepare_result);

    return 0;
}

int conn_test_buart_panic(void)
{
    return device_panic(BUART);
}

int conn_test_guart_panic(void)
{
    return device_panic(GUART);
}

// 全局结构体初始化，以及bt校准
int32_t ps_probe(void)
{
    int32_t err;

    // BUART ps core初始化
    err = ps_core_init(&g_sw_ps_core[BUART], BUART);
    if (err != 0) {
        PRINT_ERR(" bt ps core init failed");
        goto err_core_init;
    }

    PRINT_INFO("ps_probe ok!");
    return 0;

err_core_init:
    PRINT_ERR("ps_probe fail!");
    return -EFAULT;
}

/*
 * Prototype    : ps_remove
 * Description  : called when user applation rmmod driver
 */
int32_t ps_remove(void)
{
    ps_core_exit(g_sw_ps_core[BUART], BUART);
    return 0;
}

int32_t hw_ps_init(void)
{
    int32_t ret = 0;

    // ps相关组件初始化
    ret = ps_probe();
    if (ret) {
        PRINT_ERR("Unable to register platform bfgx driver.");
    }

    return ret;
}

void hw_ps_exit(void)
{
    ps_remove();
}

