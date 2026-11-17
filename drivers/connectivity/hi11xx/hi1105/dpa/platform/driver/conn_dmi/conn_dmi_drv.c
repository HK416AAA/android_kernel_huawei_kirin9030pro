/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi适配, 用于隔离驱动与对外接口的中间层
 * Author: dpa drivers
 */

#include <stddef.h>
#include "oal_types.h"
#include "oal_util.h"
#include "bsp_dmi.h"
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
static int32_t conn_dmi_service_request(void *priv, unsigned int sub_id, struct dmi_msg_data *msg)
{
    int32_t ret;

    if (g_conn_dmi_rx == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg need register");
        bsp_dmi_msg_free(msg);
        return -OAL_FAIL;
    }

    ret = g_conn_dmi_rx(msg->buf, (uint16_t)msg->len);
    bsp_dmi_msg_free(msg);

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
        g_conn_dmi_rx_err(msg->buf, (uint16_t)msg->len);
    }
}

static inline void dmi_msg_init(struct dmi_msg *msg, uint32_t len)
{
    msg->plane = DMI_SERVICE_TYPE_WLAN;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_WIFI;
    msg->sub_id = 0;
    msg->data.len = len - (uint32_t)sizeof(struct dmi_msg);
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
    msg = bsp_dmi_msg_alloc(DMI_SERVICE_WIFI, alloc_len);
    if (msg == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bsp_dmi_msg_alloc fail");
        return -OAL_FAIL;
    }

    dmi_msg_init(msg, alloc_len);
    if (memcpy_s(msg->data.buf, msg->data.len, data, data_len) != EOK) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_drv_send memcpy fail");
        bsp_dmi_msg_free(&msg->data);
        return -OAL_FAIL;
    }

    ret = bsp_dmi_send_msg(msg, sizeof(struct dmi_msg) + msg->data.len);
    if (ret) {
        bsp_dmi_msg_free(&msg->data);
        return ret;
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
    struct dmi_service serv;

    ret = bsp_dmi_service_init(&serv);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa service test init fail:%d", ret);
        return ret;
    }

    serv.dmi_id = DMI_SERVICE_WIFI;
    serv.request = conn_dmi_service_request;
    serv.err_process = conn_dmi_service_err_process;

    ret = bsp_dmi_service_register(&serv);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa service wifi register fail:%d", ret);
        return ret;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_trans_init
 * 功能描述  : dmi驱动层去初始化
 */
void conn_dmi_trans_deinit(void)
{
    int32_t ret;
    struct dmi_service serv;

    serv.dmi_id = DMI_SERVICE_WIFI;
    ret = bsp_dmi_service_unregister(&serv);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dpa service wifi unregister fail:%d", ret);
    }
}

