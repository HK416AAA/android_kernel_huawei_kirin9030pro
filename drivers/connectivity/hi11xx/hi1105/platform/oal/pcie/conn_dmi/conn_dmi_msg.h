/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 短距dmi消息层对外接口
 * Author: platform drivers
 */

#ifndef CONN_DMI_MSG_H
#define CONN_DMI_MSG_H

#include <stddef.h>
#include "oal_util.h"
#ifdef _PRE_PLAT_FEATURE_DPA
#include "dpa_interface.h"
#endif

#define CONN_DMI_MSG_DATA_LEN 32

enum conn_dmi_msg_type {
    CONN_DMI_MSG_POWERUP = 0,
    CONN_DMI_MSG_SHUTDOWN,
    CONN_DMI_MSG_OPEN,
    CONN_DMI_MSG_CLOSE,
    CONN_DMI_MSG_PM,
    CONN_DMI_MSG_WIFI_READY,
    CONN_DMI_MSG_WIFI_DFR_RECOVER,
    CONN_DMI_MSG_SBUF_FLOWCTRL_ON,
    CONN_DMI_MSG_SBUF_FLOWCTRL_OFF,
    CONN_DMI_MSG_ETE_RX_SUPPLY,
    CONN_DMI_MSG_ETE_THREAD_SCHED = 10,
    CONN_DMI_MSG_ETE_DEEPSLEEP_CLEAN,
    CONN_DMI_MSG_ETE_DEEPWKUP_RESTORE,
    CONN_DMI_MSG_WIFI_INIT,
    CONN_DMI_MSG_WIFI_ON,
    CONN_DMI_MSG_WIFI_OFF,
    CONN_DMI_MSG_DPA_EXCEP,
    CONN_DMI_MSG_WIFI_FORBID_ACCESS,
    CONN_DMI_MSG_WIFI_MSG,
    CONN_DMI_MSG_WIFI_DFX_UPDATE,
    CONN_DMI_MSG_WIFI_DFR_EXCP = 20,
    CONN_DMI_MSG_H2D_WIFI_MSG,
    CONN_DMI_MSG_SBUF_ALLOC_FAIL,
    CONN_DMI_MSG_H2D_EXCP_NOTIFY,
    CONN_DMI_MSG_SET_PM_TIMEOUT,
    CONN_DMI_MSG_BUF
};

typedef int32_t (*msg_resp_cb)(uint8_t type, void *priv_data);
typedef int32_t (*con_dmi_msg_proc)(uint8_t *buf, uint8_t buf_len);

#ifdef _PRE_PLAT_FEATURE_DPA
// dmi msg消息初始化
int32_t conn_dmi_msg_init(void);
// 消息注册接口
int32_t conn_dmi_msg_regiser(enum conn_dmi_msg_type msg_type, con_dmi_msg_proc cb);
// 通用消息发送接口
int32_t conn_dmi_msg_send(uint8_t msg_type, const uint8_t *buf, uint8_t buf_len, msg_resp_cb cb, void *priv);
// 异步发送一个消息
static inline int32_t conn_dmi_single_msg_send(uint8_t msg_type)
{
    return conn_dmi_msg_send(msg_type, NULL, 0, NULL, NULL);
}
// 发送消息后，支持回调
static inline int32_t conn_sync_dmi_single_ack_msg_send(uint8_t msg_type, msg_resp_cb cb, void *priv)
{
    return conn_dmi_msg_send(msg_type, NULL, 0, cb, priv);
}
// 发送消息后，携带数据
static inline int32_t conn_dmi_msg_data_send(uint8_t msg_type, const uint8_t *buf, uint8_t buf_len)
{
    return conn_dmi_msg_send(msg_type, buf, buf_len, NULL, NULL);
}
#else
static inline int32_t conn_dmi_msg_init(void)
{
    return -OAL_FAIL;
}

static inline int32_t conn_dmi_msg_regiser(enum conn_dmi_msg_type msg_type, con_dmi_msg_proc cb)
{
    return -OAL_FAIL;
}

static inline int32_t conn_dmi_msg_send(uint8_t msg_type, uint8_t *buf, uint8_t buf_len, msg_resp_cb cb, void *priv)
{
    return -OAL_FAIL;
}

static inline int32_t conn_dmi_single_msg_send(uint8_t msg_type)
{
    return -OAL_FAIL;
}

static inline int32_t conn_sync_dmi_single_ack_msg_send(uint8_t msg_type, msg_resp_cb cb, void *priv)
{
    return -OAL_FAIL;
}

static inline int32_t conn_dmi_msg_data_send(uint8_t msg_type, uint8_t *buf, uint8_t buf_len)
{
    return -OAL_FAIL;
}
#endif // _PRE_PLAT_FEATURE_DPA
#endif // CONN_DMI_MSG_H