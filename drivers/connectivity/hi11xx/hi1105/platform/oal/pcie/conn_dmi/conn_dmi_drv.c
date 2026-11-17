/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi适配, 用于隔离驱动与对外接口的中间层
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_DPA
#include <stddef.h>
#include <linux/mutex.h>
#include "oal_types.h"
#include "oal_util.h"
#include "dpa_interface.h"
#include "plat_exception_rst.h"
#include "conn_dmi_drv.h"

#define ALIGEN_BYTES      4

conn_dmi_rx_func g_conn_dmi_rx = NULL;
conn_dmi_rx_err_func g_conn_dmi_rx_err = NULL;

int32_t conn_dmi_drv_rx_register(conn_dmi_rx_func rx, conn_dmi_rx_err_func rx_err)
{
    g_conn_dmi_rx = rx;
    g_conn_dmi_rx_err = rx_err;
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_service_request
 * 功能描述  : dmi接收回调处理分发函数
 * 输入参数  : priv 私有数据, 注册填写
 *            sub_id dmi服务的子id, 参考sub_service_type
 *            msg dmi传输消息句柄, 用于交互信息获取以及dmi内存释放
 */
static int32_t conn_dmi_service_request(char *priv, unsigned int sub_id, struct dmi_msg_data *msg)
{
    int32_t ret;
    mutex_lock(&g_dmi_recv_mutex);
    if (oal_atomic_read(&g_dpa_dmi_rx_excp) == 1) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "dpa is exception, dmi msg drop\n");
        if (g_conn_dmi_rx_err != NULL) {
            g_conn_dmi_rx_err(msg->buf, msg->len);
        }
        external_dpa_dmi_msg_free_ops(msg);
        mutex_unlock(&g_dmi_recv_mutex);
        return OAL_SUCC;
    }

    if (g_conn_dmi_rx == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg need register");
        external_dpa_dmi_msg_free_ops(msg);
        mutex_unlock(&g_dmi_recv_mutex);
        return -OAL_FAIL;
    }

    ret = g_conn_dmi_rx(msg->buf, msg->len);
    external_dpa_dmi_msg_free_ops(msg);
    mutex_unlock(&g_dmi_recv_mutex);
    return ret;
}

/*
 * 函 数 名  : conn_dmi_service_err_process
 * 功能描述  : 从dmi接收申请内存失败时调用
 * 输入参数  : priv 私有数据, 注册填写
 *            sub_id dmi服务的子id, 参考sub_service_type
 *            msg_data dmi传输消息句柄, 用于交互信息获取以及dmi内存释放
 */
static void conn_dmi_service_err_process(void *priv, unsigned int sub_id, struct dmi_msg_data *msg)
{
    oal_print_mpxx_log(MPXX_LOG_ERR, "conn dmi message receiving exception, sub_id = %d", sub_id);
    if (g_conn_dmi_rx_err != NULL) {
        g_conn_dmi_rx_err(msg->buf, msg->len);
    }
}

static inline void dmi_msg_init(struct dmi_msg *msg, uint32_t len)
{
    msg->plane = DMI_SERVICE_TYPE_WLAN;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_WIFI;
    msg->sub_id = 0;
    msg->data.len = len - sizeof(struct dmi_msg);
}

/*
 * 函 数 名  : conn_dmi_drv_send
 * 功能描述  : dmi发送数据接口
 * 输入参数  : data 待发送数据地址
 *             data_len 待发送数据长度
 */
int32_t conn_dmi_drv_send(uint8_t *data, uint32_t data_len)
{
    struct dmi_msg *msg = NULL;
    uint32_t alloc_len;
    int32_t ret;

    // 分配dmi内存, 完成dmi消息组包
    alloc_len = ALIGN(sizeof(struct dmi_msg) + data_len, ALIGEN_BYTES);
    msg = external_dpa_dmi_msg_alloc_ops(DMI_SERVICE_WIFI, alloc_len);
    if (msg == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "external_dpa_dmi_msg_alloc_ops fail");
        return -OAL_FAIL;
    }

    dmi_msg_init(msg, alloc_len);
    if (memcpy_s(msg->data.buf, msg->data.len, data, data_len) != EOK) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_drv_send memcpy fail");
        external_dpa_dmi_msg_free_ops(&msg->data);
        return -OAL_FAIL;
    }

    ret = external_dpa_dmi_client_request_ops(msg, sizeof(struct dmi_msg) + msg->data.len);
    if (ret) {
        external_dpa_dmi_msg_free_ops(&msg->data);
        oal_print_mpxx_log(MPXX_LOG_ERR, "external_dpa_dmi_client_request_ops send fail, ret = %d", ret);
        return -OAL_FAIL;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_drv_init
 * 功能描述  : dmi驱动层初始化
 */
int32_t conn_dmi_drv_init(void)
{
    int32_t ret;
    struct dmi_client serv;

    ret = external_dpa_dmi_client_init_ops(&serv);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa service test init fail:%d", ret);
        return ret;
    }

    serv.dmi_id = DMI_SERVICE_WIFI;
    serv.service_cb = conn_dmi_service_request;
    serv.err_process = conn_dmi_service_err_process;

    ret = external_dpa_dmi_client_register_ops(&serv);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa service wifi register fail:%d", ret);
        return ret;
    }
    return OAL_SUCC;
}

#endif