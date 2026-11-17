/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for uart data parse
 * Author: bfgx drivers
 */

#define USE_LOG_TAG_FUNC
#define pr_fmt(fmt) "2[hisi_plat]" fmt

#include "plat_uart.h"
#include "bfgx_dev.h"
#include "plat_pm.h"
#include "plat_main.h"
#include "oal_net.h"
#include "plat_debug.h"
#include "bfgx_data_parse.h"

STATIC struct ps_tx_manage_info g_ps_tx_info[BFGX_BUTT] = {
    {PKG_NOT_SEPRETED, TX_HIGH_QUEUE, BT_MSG, BT_MSG, BT_MSG},
    {PKG_SEPRETED, TX_LOW_QUEUE, FM_FIRST_MSG, FM_COMMON_MSG, FM_LAST_MSG},
    {PKG_SEPRETED, TX_LOW_QUEUE, GNSS_FIRST_MSG, GNSS_COMMON_MSG, GNSS_LAST_MSG},
};

/*
 * Prototype    : ps_add_packet_head
 * Description  : add packet head to recv buf from hal or bt driver.
 * input        : buf  -> ptr of buf
 *                type -> packet type，example bt,fm,or gnss
 *                lenth-> packet length
 */
int32_t ps_add_packet_head(uint8_t *buf, uint8_t type, uint16_t lenth)
{
    uint8_t *ptr = buf;
    uint16_t len;

    if (oal_unlikely(ptr == NULL)) {
        PRINT_ERR("buf is NULL");
        return -EINVAL;
    }

    if (oal_unlikely(lenth < PS_PKG_SIZE)) {
        PRINT_ERR("buf is not enough");
        return -EINVAL;
    }

    *ptr = PACKET_START_SIGNAL;
    ptr++;
    *ptr = type;
    len = lenth;
    ptr++;
    *ptr = len_low_byte(len);
    ptr++;
    *ptr = len_high_byte(len);

    ptr = buf;
    ptr = ptr + lenth;
    ptr = ptr - PS_END_SIZE;
    *ptr = PACKET_END_SIGNAL;

    return 0;
}

/*
 * Prototype    : ps_set_sys_packet
 * Description  : set sys packet head to buf
 * input        : buf  -> ptr of buf
 *                type -> packet type，example bt,fm,or gnss
 *                lenth-> packet length
 */
STATIC void ps_set_sys_packet(uint8_t *buf, uint8_t type, uint8_t content)
{
    uint8_t *ptr = buf;

    if (oal_unlikely(ptr == NULL)) {
        PRINT_ERR("buf is NULL");
        return;
    }

    *ptr = PACKET_START_SIGNAL;
    ptr++;
    *ptr = type;
    ptr++;
    *ptr = SYS_TOTAL_PACKET_LENTH;
    ptr++;
    *ptr = 0;
    ptr++;
    *ptr = content;
    ptr++;
    *ptr = PACKET_END_SIGNAL;
}

/*
 * Prototype    : ps_tx_sys_cmd
 * Description  : tx sys commend to uart tty
 */
int32_t ps_tx_sys_cmd(struct ps_core_s *ps_core_d, uint8_t type, uint8_t content)
{
    uint8_t* data_buf = NULL;
    uint8_t  packet[SYS_TOTAL_PACKET_LENTH];

    data_buf = oal_large_malloc(SYS_TOTAL_PACKET_LENTH);
    if (data_buf == NULL) {
        PRINT_ERR("sys cmd malloc fail");
        return -ENOMEM;
    }

    PRINT_INFO("[%s]send cmd 0x%x", __FUNCTION__, content);

    ps_set_sys_packet(packet, type, content); // 构造sys_msg包

    if (memcpy_s(data_buf, SYS_TOTAL_PACKET_LENTH, packet, SYS_TOTAL_PACKET_LENTH) != 0) {
        oal_large_free(data_buf);
        return -EINVAL;
    }

    // 发送消息到对应uart发送线程队列, 成功由UART发送线程free动态申请的内存
    if (platform_task_send_msg(ps_core_d->tty.uart, MSG_TYPE_TX, data_buf, SYS_TOTAL_PACKET_LENTH) != BFGN_SUCC) {
        oal_large_free(data_buf);
    }

    return 0;
}

int32_t ps_core_kzalloc_check(struct ps_core_s **ps_core_d)
{
    uint8_t *ptr = NULL;
    *ps_core_d = oal_kzalloc(sizeof(struct ps_core_s), GFP_KERNEL);

    if (*ps_core_d == NULL) {
        PRINT_ERR("ps_core mem malloc failed!");
        return -ENOMEM;
    }

    (*ps_core_d)->chr_inf = oal_kzalloc(sizeof(chr_data_extend_t), GFP_KERNEL);
    if ((*ps_core_d)->chr_inf == NULL) {
        oal_kfree(*ps_core_d);
        PRINT_ERR("ps_core chr_inf mem malloc failed!");
        return -ENOMEM;
    }

    return 0;
}

void ps_core_kfree(struct ps_core_s *ps_core_d)
{
    oal_kfree(ps_core_d->chr_inf);
    oal_kfree(ps_core_d);
}

/*
 * Prototype    : ps_core_init
 * Description  : init ps_core_d struct and oal_kzalloc memery
 */
int32_t ps_core_init(struct ps_core_s **core_data, int index)
{
    struct ps_core_s *ps_core_d = NULL;
    const char *name = NULL;
    int32_t err, i;

    if (ps_core_kzalloc_check(&ps_core_d) < 0) {
        PRINT_ERR("error ps_core_kzalloc_check fail!");
        return -ENOMEM;
    }

    err = ps_pm_register(ps_core_d, index);
    if (err) {
        ps_core_kfree(ps_core_d);
        PRINT_ERR("error registering ps_pm err = %d", err);
        return -EFAULT;
    }

    err = plat_uart_init(ps_core_d, index);
    if (err) {
        ps_pm_unregister(ps_core_d, index);
        ps_core_kfree(ps_core_d);
        PRINT_ERR("error uart init fail! %d", err);
        return -EFAULT;
    }

    /* 初始化开关业务完成量 */
    for (i = 0; i < BFGX_BUTT; i++) {
        oal_init_completion(&ps_core_d->bfgx_info[i].wait_closed);
        oal_init_completion(&ps_core_d->bfgx_info[i].wait_opened);
        oal_atomic_set(&ps_core_d->bfgx_info[i].subsys_state, POWER_STATE_SHUTDOWN);
    }

    oal_atomic_set(&ps_core_d->node_visit_flag, 0);

    ps_core_d->rx_pkt_total_len = 0;
    ps_core_d->rx_have_recv_pkt_len = 0;
    ps_core_d->rx_have_del_public_len = 0;

    ps_core_d->dev_index = index;
    *core_data = ps_core_d;

    oal_mutex_init(&ps_core_d->tty_mutex);
    PRINT_INFO("ps_core_init %d ok!", index);
    return 0;
}

/*
 * Prototype    : ps_core_exit
 * Description  : release have init ps_core_d struct and oal_kfree memery:
 */
int32_t ps_core_exit(struct ps_core_s *ps_core_d, int index)
{
    int32_t err;

    if (ps_core_d != NULL) {
        /* TTY ldisc cleanup */
        err = plat_uart_exit(index);
        if (err) {
            PRINT_ERR("unable to un-register ldisc %d", err);
        }
        /* unregister pm */
        ps_pm_unregister(ps_core_d, index);
        /* free the global data pointer */
        ps_core_kfree(ps_core_d);
    }
    ps_core_d = NULL;
    return 0;
}
