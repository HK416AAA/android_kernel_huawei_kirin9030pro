/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi消息驱动适配
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_DPA
#include "oal_util.h"
#include "oal_types.h"
#include "conn_dmi_hal.h"
#include "conn_dmi_msg.h"

#define CONN_DMI_MSG_PRIV_DATA_LEN 16

typedef union {
    struct {
        uint16_t local_req_ack : 1;    // 本端请求对端发送ack事件
        uint16_t remote_resp_ack : 1;  // 远端响应ack事件
    } bits;
    uint16_t as_word;
} conn_dmi_cap;

// 双端通信固定的结构体
struct conn_dmi_msg_inter_stru {
    uint8_t type;
    conn_dmi_cap cap;
    uint16_t data_len;
    uint8_t data[CONN_DMI_MSG_DATA_LEN];
};

// 双端内部私有结构体
struct conn_dmi_msg_priv_stru {
    msg_resp_cb resp;
    void *priv;
};

// 该结构体大小要与对端DPA核保持一致，需同步修改
struct conn_dmi_msg_stru {
    struct conn_dmi_msg_inter_stru inter;
    // 如下位内部数据
    uint8_t priv_data[CONN_DMI_MSG_PRIV_DATA_LEN];
};

static con_dmi_msg_proc g_dmi_msg_proc[CONN_DMI_MSG_BUF];

int32_t conn_dmi_msg_regiser(enum conn_dmi_msg_type msg_type, con_dmi_msg_proc cb)
{
    if (msg_type >= CONN_DMI_MSG_BUF) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_msg_regiser msg type %u invalid", msg_type);
        return -OAL_FAIL;
    }

    g_dmi_msg_proc[msg_type] = cb;
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_msg_send
 * 功能描述  : 通过dmi接口发送消息
 * 输入参数  : send_msg 待发消息
 */
int32_t conn_dmi_msg_send(uint8_t msg_type, const uint8_t *buf, uint8_t buf_len, msg_resp_cb cb, void *priv)
{
    int32_t ret;
    struct conn_dmi_msg_stru *dmi_msg = NULL;
    struct conn_dmi_msg_priv_stru *dmi_msg_priv = NULL;

    if (buf_len > CONN_DMI_MSG_DATA_LEN) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send param invalid, len = %u", buf_len);
        return -OAL_FAIL;
    }

    if (msg_type >= CONN_DMI_MSG_BUF) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send msg_type %u invalid", msg_type);
        return -OAL_FAIL;
    }

    dmi_msg = (struct conn_dmi_msg_stru *)conn_dmi_hal_alloc_buf(sizeof(struct conn_dmi_msg_stru));
    if (dmi_msg == NULL) {
        return -OAL_ENOMEM;
    }

    dmi_msg_priv = (struct conn_dmi_msg_priv_stru *)dmi_msg->priv_data;
    memset_s(dmi_msg, sizeof(struct conn_dmi_msg_stru), 0, sizeof(struct conn_dmi_msg_stru));
    dmi_msg->inter.type = msg_type;
    if (buf != NULL && buf_len != 0) {
        ret = memcpy_s(dmi_msg->inter.data, CONN_DMI_MSG_DATA_LEN, buf, buf_len);
        if (ret != EOK) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send buf len %u invalid", buf_len);
            conn_dmi_hal_free_buf((uint8_t *)dmi_msg);
            return -OAL_FAIL;
        }
    }

    dmi_msg->inter.data_len = buf_len;
    if (cb != NULL) {
        dmi_msg->inter.cap.bits.local_req_ack = OAL_TRUE;
        dmi_msg_priv->resp = cb;
        dmi_msg_priv->priv = priv;
    }

    ret = conn_dmi_hal_send(DMI_HAL_TYPE_MSG, (uint8_t *)dmi_msg, sizeof(struct conn_dmi_msg_stru));
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg send fail");
        conn_dmi_hal_free_buf((uint8_t *)dmi_msg);
        return ret;
    }

    conn_dmi_hal_free_buf((uint8_t *)dmi_msg);
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_msg_rx_ack_process
 * 功能描述  : 本核发过去的消息，对端已传回，调用发送时带的cb函数
 */
static int32_t conn_dmi_msg_rx_ack_process(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    struct conn_dmi_msg_stru *msg = NULL;
    struct conn_dmi_msg_priv_stru *msg_priv = NULL;

    // 发送回来的数据应该与发过去的长度一致
    if (buf_len != (uint16_t)sizeof(struct conn_dmi_msg_stru)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi ack msg len %u invaid", buf_len);
        return -OAL_FAIL;
    }

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_priv = (struct conn_dmi_msg_priv_stru *)msg->priv_data;
    if (msg_priv->resp == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi ack callback is NULL");
        return -OAL_FAIL;
    }

    return ((msg_resp_cb)msg_priv->resp)(msg_type, (void *)msg_priv->priv);
}

/*
 * 函 数 名  : conn_dmi_msg_rx_ack_send_back
 * 功能描述  : 接收到对端核消息, 直接调用返回
 */
static int32_t conn_dmi_msg_rx_ack_send_back(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    int32_t ret;
    uint8_t *send_buf = NULL;

    send_buf = conn_dmi_hal_alloc_buf(buf_len);
    if (send_buf == NULL) {
        return -OAL_ENOMEM;
    }

    ret = memcpy_s(send_buf, buf_len, buf, buf_len);
    if (ret != EOK) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg rx ack memcpy_s fail");
        conn_dmi_hal_free_buf(send_buf);
        return ret;
    }

    ret = conn_dmi_hal_send(DMI_HAL_TYPE_MSG, send_buf, buf_len);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg rx ack send fail");
        conn_dmi_hal_free_buf(send_buf);
        return ret;
    }

    conn_dmi_hal_free_buf(send_buf);
    return OAL_SUCC;
}

/*
 * 函 数 名  : conn_dmi_msg_rx_process
 * 功能描述  : 消息处理函数
 */
static int32_t conn_dmi_msg_rx_process(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    int32_t ret;

    if (g_dmi_msg_proc[msg_type] == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg process is NULL\n");
        return -OAL_FAIL;
    }

    ret = g_dmi_msg_proc[msg_type](buf, buf_len);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg %u process fail", msg_type);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t conn_dmi_msg_rx_cap_process(uint8_t msg_type, uint8_t *buf, uint16_t buf_len)
{
    struct conn_dmi_msg_inter_stru *msg_inter = NULL;
    struct conn_dmi_msg_stru *msg = NULL;
    conn_dmi_cap cap;
    int32_t ret;

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_inter = &msg->inter;
    cap.as_word = msg_inter->cap.as_word;

    // 接收到本核消息的答应ack, 仅执行内容回调
    if (cap.bits.local_req_ack == OAL_TRUE && cap.bits.remote_resp_ack == OAL_TRUE) {
        return conn_dmi_msg_rx_ack_process(msg_type, buf, buf_len);
    }

    ret = conn_dmi_msg_rx_process(msg_type, (uint8_t *)&msg_inter->data, msg_inter->data_len);
    if (ret != OAL_SUCC) {
        return ret;
    }

    // 不需要将消息回传，直接返回
    if (cap.bits.local_req_ack == OAL_FALSE) {
        return OAL_SUCC;
    }

    // 这里需要把标记位改掉，对端才知道时回传消息
    cap.bits.remote_resp_ack = OAL_TRUE;
    msg_inter->cap.as_word = cap.as_word;
    ret = conn_dmi_msg_rx_ack_send_back(msg_type, buf, buf_len);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg ack send back fail");
        return ret;
    }

    return OAL_SUCC;
}

static int32_t conn_dmi_msg_rx_func(uint8_t *buf, uint16_t buf_len)
{
    struct conn_dmi_msg_stru *msg = NULL;
    struct conn_dmi_msg_inter_stru *msg_inter = NULL;

    if (buf_len < (uint16_t)sizeof(struct conn_dmi_msg_stru)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg rx len %u invalid", buf_len);
        return -OAL_FAIL;
    }

    msg = (struct conn_dmi_msg_stru *)buf;
    msg_inter = &msg->inter;
    if (msg_inter->type >= CONN_DMI_MSG_BUF) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi msg type %u invalid", msg_inter->type);
        return -OAL_FAIL;
    }

    return conn_dmi_msg_rx_cap_process(msg_inter->type, buf, buf_len);
}

static int32_t conn_dmi_msg_rx_err_func(uint8_t *buf, uint16_t buf_len)
{
    return OAL_SUCC;
}

int32_t conn_dmi_msg_init(void)
{
    oal_build_bug_on((sizeof(struct conn_dmi_msg_priv_stru) > CONN_DMI_MSG_PRIV_DATA_LEN));
    conn_dmi_hal_init();
    return conn_dmi_hal_rx_register(DMI_HAL_TYPE_MSG, conn_dmi_msg_rx_func, conn_dmi_msg_rx_err_func);
}
#endif