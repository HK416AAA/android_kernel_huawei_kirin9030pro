/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for bt node
 * Author: bfgx drivers
 */

#include "plat_debug.h"
#include "plat_main.h"
#include "plat_pm.h"
#include "plat_uart.h"
#include "bfgx_dev.h"
#include "oal_atomic.h"
#include "oal_net.h"
#include "bfgx_data_parse.h"
#include "plat_exception_rst.h"
#include "mpxx_dev.h"

// 子系统关闭则不再写数据
static int32_t hw_bfgx_write_check(struct ps_core_s *ps_core_d, uint32_t subsys)
{
    struct st_bfgx_data *pst_bfgx_data = NULL;
    if (oal_unlikely(ps_core_d == NULL)) {
        PRINT_ERR("ps_core_d is NULL");
        return -EINVAL;
    }
    return 0;
}

/*
 * Prototype    : hisi_bt_uart_send
 * Description  : functions called from above bt hal,read count data to buf
 * input        : file handle, buf, count
 * output       : return size --> actual read byte size
 */
static int32_t hisi_bt_uart_send(uint8_t msg_type, const char *data, int32_t len)
{
    struct ps_core_s *ps_core_d = NULL;
    uint8_t* data_buf = NULL;
    uint16_t total_len;
    int32_t ret = 0;
    int32_t prepare_result;

    ps_core_d = ps_get_core_reference(BUART);

    ret = hw_bfgx_write_check(ps_core_d, BFGX_BT);
    if (ret < 0) {
        return ret;
    }

    if (len > BT_TX_MAX_FRAME) {
        PRINT_ERR("len is too large!");
        return -EINVAL;
    }

    ret = prepare_to_visit_node(ps_core_d, &prepare_result);
    if (ret < 0) {
        return ret;
    }

    total_len = len + sizeof(struct ps_packet_head) + sizeof(struct ps_packet_end);

    data_buf = oal_large_malloc(total_len);
    if (data_buf == NULL) {
        PRINT_ERR("hisi_uart_send malloc fail");
        post_to_visit_node(ps_core_d, prepare_result);
        return -EFAULT;
    }

    ret = memcpy_s(&data_buf[sizeof(struct ps_packet_head)], total_len - sizeof(struct ps_packet_head), data, len);
    if (ret != 0) {
        PRINT_ERR("hisi_uart_send memcpy err");
        oal_large_free(data_buf);
        post_to_visit_node(ps_core_d, prepare_result);
        return -EFAULT;
    }

    ps_add_packet_head(data_buf, msg_type, total_len);

    ret = platform_task_send_msg(BUART, MSG_TYPE_TX, data_buf, total_len);
    if (ret != OAL_SUCC) {
        PRINT_ERR("hisi_uart_send send msg err");
        oal_large_free(data_buf);
        post_to_visit_node(ps_core_d, prepare_result);
        return -EFAULT;
    }

    post_to_visit_node(ps_core_d, prepare_result);

    return len;
}

/*
 * Prototype    : hw_bt_write
 * Description  : functions called from bt service,send data to dev core
 * input        : data, data_len
 * output       : return size --> actual write byte size
 */
int32_t hw_bt_write(const char *data, int32_t data_len)
{
    if (ps_bfg_subsys_active(BFGX_BT) == false) {
        PRINT_ERR("hw_bt_write send msg err, bt is not open");
        return -EFAULT;
    }
    return hisi_bt_uart_send(BT_MSG, data, data_len);
}

/*
 * Prototype    : hw_sle_write
 * Description  : functions called from bt service,send data to dev core
 * input        : data, data_len
 * output       : return size --> actual write byte size
 */
int32_t hw_sle_write(const char *data, int32_t data_len)
{
    if (ps_bfg_subsys_active(BFGX_SLE) == false) {
        PRINT_ERR("hw_sle_write send msg err, sle is not open");
        return -EFAULT;
    }
    return hisi_bt_uart_send(GLE_MSG, data, data_len);
}

/*
 * Prototype    : hw_bt_register_read_callback
 * Description  : functions called from bt service to register uart recv
 * input        : callback
 */
void hw_bt_register_read_callback(bfgn_read_data_callback_t callback)
{
    bfgn_register_bt_data_callback(callback);
}

/*
 * Prototype    : hw_sle_register_read_callback
 * Description  : functions called from sle service to register uart recv
 * input        : callback
 */
void hw_sle_register_read_callback(bfgn_read_data_callback_t callback)
{
    bfgn_register_sle_data_callback(callback);
}

int32_t hw_get_bt_state(void)
{
    struct ps_core_s *ps_core_d = ps_get_subsys_core_reference(BFGX_BT);
    if (ps_core_d == NULL) {
        PRINT_ERR("hw_get_bt_state bt not init");
        return -EINVAL;
    }
    return (int32_t)oal_atomic_read(&(ps_core_d->bfgx_info[BFGX_BT].subsys_state));
}

int32_t hw_get_sle_state(void)
{
    struct ps_core_s *ps_core_d = ps_get_subsys_core_reference(BFGX_SLE);
    if (ps_core_d == NULL) {
        PRINT_ERR("hw_get_sle_state sle not init");
        return -EINVAL;
    }
    return (int32_t)oal_atomic_read(&(ps_core_d->bfgx_info[BFGX_SLE].subsys_state));
}
