/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 短距dmi 抽象层
 * Author: dpa drivers
 */

#include "circ_queue.h"
#include "oal_util.h"
#include "board_pm.h"
#include "oal_mm.h"
#include "hcc_slave.h"
#include "bsp_dra.h"
#include "bsp_dump.h"
#include "conn_dmi_hal.h"

#define DMI_TRANS_MAGIC_ID 0xdeadbeaf
#define DMI_TRANS_BUF_LEN 464

// 核间通信结构体: 用于AP<->DPA之间HCC数据交互
typedef struct {
    uint32_t magic_id;
    uint16_t trans_type;
    uint16_t data_len;
    uint8_t trans_buf[DMI_TRANS_BUF_LEN];
} dmi_trans_stru;

conn_dmi_hal_rx_func g_dmi_hal_rx[DMI_HAL_TYPE_BUF];
conn_dmi_hal_rx_err_func g_dmi_hal_rx_err[DMI_HAL_TYPE_BUF];

int32_t conn_dmi_hal_rx_register(enum dmi_hal_tran_type trans_type,
                                 conn_dmi_hal_rx_func rx, conn_dmi_hal_rx_err_func rx_err)
{
    if (trans_type >= DMI_HAL_TYPE_BUF ||  rx == NULL || rx_err == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hal_rx_register type %u param invalid ", trans_type);
        return -OAL_FAIL;
    }

    g_dmi_hal_rx[trans_type] = rx;
    g_dmi_hal_rx_err[trans_type] = rx_err;
    return OAL_SUCC;
}

uint8_t *conn_dmi_hal_alloc_buf(uint16_t len)
{
    dmi_trans_stru *trans = NULL;

    if (len > DMI_TRANS_BUF_LEN) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi hal len %u invalid ", len);
        return NULL;
    }

    trans = (dmi_trans_stru *)mdrv_mem_alloc(sizeof(dmi_trans_stru), MEM_CACHE | MDRV_MEM_ALIGN_004);
    if (trans == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi hal alloc fail ");
        return NULL;
    }

    trans->magic_id = DMI_TRANS_MAGIC_ID;

    return trans->trans_buf;
}

void conn_dmi_hal_free_buf(uint8_t *buf)
{
    dmi_trans_stru *trans = NULL;
    if (buf == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi hal free buf is NULL");
        return;
    }

    trans = container_of(buf, dmi_trans_stru, trans_buf[0]);
    if (trans->magic_id != DMI_TRANS_MAGIC_ID) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi hal free magic id 0x%x invalid ", trans->magic_id);
        return;
    }

    mdrv_free(trans);
}

static void dmi_error_process(enum dmi_hal_tran_type trans_type)
{
    if (trans_type == DMI_HAL_TYPE_MSG) {
        system_error(WLAN_ERRNO_DMI_EXCEP, 0, 0, NULL, 0);
    }
}

/*
 * 函 数 名  : conn_dmi_hal_send
 * 功能描述  : dmi 发送hcc消息接口
 * 输入参数  : sbuf 待发送sbuf
 *            qtype 发送优先级
 */
int32_t conn_dmi_hal_send(enum dmi_hal_tran_type trans_type, uint8_t *buf, uint16_t buf_len)
{
    int32_t ret;
    if (buf == NULL || buf_len == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hal_send param check fail, buf_len = %d", buf_len);
        return -OAL_FAIL;
    }

    dmi_trans_stru *trans = container_of(buf, dmi_trans_stru, trans_buf[0]);

    if (trans->magic_id != DMI_TRANS_MAGIC_ID) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi hal free magic id 0x%x invalid ", trans->magic_id);
        return -OAL_FAIL;
    }

    trans->trans_type = trans_type;
    trans->data_len = buf_len;

    ret = conn_dmi_drv_send((uint8_t *)trans, sizeof(dmi_trans_stru));
    if (ret != OAL_SUCC) {
        dmi_error_process(trans_type);
    }
    return ret;
}

static int32_t conn_dmi_hal_rx_check(uint8_t *buf, uint16_t buf_len)
{
    uint16_t trans_type;
    uint32_t magic_id;
    dmi_trans_stru *trans = NULL;

    if (buf == NULL || buf_len != sizeof(dmi_trans_stru)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hal_rx param check fail, buf_len = %d", buf_len);
        return -OAL_FAIL;
    }

    trans = (dmi_trans_stru *)buf;
    trans_type = trans->trans_type;
    magic_id = trans->magic_id;
    if (magic_id != DMI_TRANS_MAGIC_ID) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hal_rx magic_id %u invalid ", magic_id);
        return -OAL_FAIL;
    }

    if (trans_type >= DMI_HAL_TYPE_BUF) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hal_rx param trans type %u invalid ", trans_type);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_hal_rx
 * 功能描述  : 核间传输hal层接收
 */
static int32_t conn_dmi_hal_rx(uint8_t *buf, uint16_t buf_len)
{
    uint16_t trans_type;
    dmi_trans_stru *trans = NULL;

    if (conn_dmi_hal_rx_check(buf, buf_len) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    trans = (dmi_trans_stru *)buf;
    trans_type = trans->trans_type;
    if (g_dmi_hal_rx[trans_type] == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hal_rx param trans type %u rx func is null", trans_type);
        return -OAL_FAIL;
    }

    return g_dmi_hal_rx[trans_type](trans->trans_buf, trans->data_len);
}

/*
 * 函 数 名  : conn_dmi_hal_rx_err
 * 功能描述  : 核间传输hal层接收
 */
static int32_t conn_dmi_hal_rx_err(uint8_t *buf, uint16_t buf_len)
{
    uint16_t trans_type;
    dmi_trans_stru *trans = NULL;

    if (conn_dmi_hal_rx_check(buf, buf_len) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    trans = (dmi_trans_stru *)buf;
    trans_type = trans->trans_type;
    if (g_dmi_hal_rx_err[trans_type] == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hal_rx param trans type %u rx err func is null", trans_type);
        return -OAL_FAIL;
    }

    return g_dmi_hal_rx_err[trans_type](trans->trans_buf, trans->data_len);
}

int32_t conn_dmi_hal_init(void)
{
    oal_build_bug_on((sizeof(dmi_trans_stru) > DRA_LEVEL_9_SIZE));
    conn_dmi_drv_rx_register(conn_dmi_hal_rx, conn_dmi_hal_rx_err);
    return OAL_SUCC;
}