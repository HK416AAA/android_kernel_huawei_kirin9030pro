/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _DPA_DMI_H_
#define _DPA_DMI_H_

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)
struct dmi_msg_data {
    unsigned int len;
    unsigned char buf[0];
};

struct dmi_callback {
    unsigned long long cb;
    unsigned long long cb_data;
};

struct dmi_msg {
    unsigned char plane;
    unsigned char type;
    unsigned char dmi_id;
    unsigned char last : 1;
    unsigned char sub_id : 7;
    struct dmi_callback dmi_cb;
    struct dmi_msg_data data;
};
#pragma pack()

enum dmi_event_type_e {
    DMI_EVENT_INVALID = 0,
    DMI_EVENT_CHN_NOT_FULL = 1,
    DMI_EVENT_MAX,
};

enum dmi_plane_type {
    DMI_SERVICE_TYPE_CTRL = 0,
    DMI_SERVICE_TYPE_DATA = 1,
    DMI_SERVICE_TYPE_RAW = 2,
    DMI_SERVICE_TYPE_WLAN = 3,
    DMI_SERVICE_TYPE_COMM = 4,
    DMI_SERVICE_TYPE_PLANE_MAX,
};

enum dmi_msg_id {
    DMI_SERVICE_STACK,
    DMI_SERVICE_PROTO_SOCK,
    DMI_SERVICE_PROTO_ENTRY,
    DMI_SERVICE_PROTO_NETDEV,
    DMI_SERVICE_PROTO_MDM_CFG,
    DMI_SERVICE_WIFI,
    DMI_SERVICE_DRA,
    DMI_SERVICE_PFA,
    DMI_SERVICE_WAN,
    DMI_SERVICE_MPERF,
    DMI_SERVICE_SYSLOG,
    DMI_SERVICE_DIAG,
    DMI_SERVICE_DSHELL,
    DMI_SERVICE_PROTO_OM,
    DMI_SERVICE_NETOM,
    DMI_SERVICE_NIC_SYNC,
    DMI_SERVICE_SMS_RX,
    DMI_SERVICE_SMS_FILTER,
    DMI_SERVICE_GSO,
    DMI_SERVICE_UDX_AGENT,
    DMI_SERVICE_SYSCTRL,
    DMI_SERVICE_SNMP,
    DMI_SERVICE_DPA_SAMPLER,
    DMI_SERVICE_TEST,
    DMI_SERVICE_DPA_DYNMEM,
    DMI_SERVICE_TC,
    DMI_SERVICE_BOOSTER,
    DMI_SERVICE_CHR,
    DMI_SERVICE_FILE_SERVICE,
    DMI_SERVICE_DSHARE_SERVICE,
    DMI_SERVICE_DFA,

    DMI_SERVICE_BTEST,
    DMI_SERVICE_MAX
};

enum dmi_msg_type {
    DMI_SERVICE_TYPE_RUN,
    DMI_SERVICE_TYPE_STOP,
    DMI_SERVICE_TYPE_REQUEST,
    DMI_SERVICE_TYPE_QUERY,
    DMI_SERVICE_TYPE_SUBSCRIBE,
    DMI_SERVICE_TYPE_REQUEST_CB,
    DMI_SERVICE_TYPE_REPLY,
    DMI_SERVICE_TYPE_ERR_PROC,
    DMI_SERVICE_TYPE_MAX
};

struct dmi_client {
    int dmi_id;
    char *priv;
    int (*service_cb)(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg);
    // 从eicc接收申请内存失败时调用
    void (*err_process)(void *priv, unsigned int service_sub_id, struct dmi_msg_data *msg);
    void (*send_done)(unsigned int free_size);
    void (*dmi_client_event_cbk)(unsigned int plane, enum dmi_event_type_e event);
};

struct dpa_dmi_ops {
    int (*dpa_dmi_client_init)(struct dmi_client *client);
    int (*dpa_dmi_client_register)(struct dmi_client *client);
    int (*dpa_dmi_client_request)(struct dmi_msg *msg, unsigned int len);
    struct dmi_msg *(*dpa_dmi_msg_alloc)(unsigned int dmi_id, unsigned int len);
    int (*dpa_dmi_msg_free)(struct dmi_msg_data *msg);
    int(*dpa_dmi_msg_maxsize)(void);
};


/**
 * @brief 注册dpa dmi内核API
 *
 * @par 描述:
 * 注册dpa dmi内核API，注册后dmi系列ops接口才能使用
 *
 * @attention
 * <ul><li>dpa host注册成功，内核才能使用dmi api</li></ul>
 *
 * @param[in] size, 报文长度
 *
 * @retval == 0,注册API成功。
 * @retval < 0,注册API不成功。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_api_register(struct dpa_dmi_ops *dra_ops);

/**
 * @brief 初始化dmi_client结构体
 *
 * @par 描述:
 * 初始化结构体，使用者只对使用字段初始化赋值
 *
 * @attention
 * <ul><li>dmi驱动拷贝结构体信息到全局变量维护，建议用户使用临时缓存，减少内存占用。</li></ul>
 *
 * @param[in] client, dmi_client结构体指针
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,-ENOSYS函数不支持；其他表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_client_init_ops(struct dmi_client *client);

/**
 * @brief 注册client端处理回调
 *
 * @par 描述:
 * 注册dmi_id用户的回调处理
 *
 * @attention
 * <ul><li>同一个dmi_id用户只能注册一次，否则可能导致异常。</li></ul>
 *
 * @param[in] client, dmi_client结构体指针
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,-ENOSYS表示函数不支持；-EAGAIN表示发送队列满；其他表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_client_register_ops(struct dmi_client *client);

/**
 * @brief dmi消息发送，专用通道使用
 *
 * @par 描述:
 * host->fw侧发送dmi消息
 *
 * @attention
 * <ul><li>len包括dmi头，不超过1K字节。不带唤醒DPA FW功能。用户调用接口前保证DPA处于唤醒态。</li></ul>
 *
 * @param[in] msg, dmi消息指针，使用dpa_dmi_msg_alloc申请的内存，发送完成内存由dmi驱动释放
 * @param[in] len, dmi消息长度
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,-ENOSYS函数不支持；其他表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_client_request_ops(struct dmi_msg *msg, unsigned int len);

/**
 * @brief 申请dmi消息内存
 *
 * @par 描述:
 * 申请dmi消息内存
 *
 * @attention
 * <ul><li>专用通道使用，分配长度时需要计算dmi消息结构体的长度，即sizeof(struct dmi_msg)
 * +sizeof(struct dmi_msg_data) + 用户数据长度。</li></ul>
 *
 * @param[in] dmi_id, 用户ID
 * @param[in] len, dmi消息长度，包括dmi头，不超过512字节
 *
 * @retval != NULL,返回dmi_msg内存指针，表示函数执行成功。
 * @retval == NULL,表示函数不支持，或者分配内存失败。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
struct dmi_msg *dpa_dmi_msg_alloc_ops(unsigned int dmi_id, unsigned int len);

/**
 * @brief 释放dmi消息内存
 *
 * @par 描述:
 * 释放dmi消息内存
 *
 * @attention
 * <ul><li>专用通道使用。</li></ul>
 *
 * @param[in] msg, dmi消息的data指针
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,-ENOSYS函数不支持；表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_msg_free_ops(struct dmi_msg_data *msg);

/**
 * @brief msg支持的最大内存，包括msg结构体长度
 *
 * @par 描述:
 * 释放dmi消息内存
 *
 * @attention
 * <ul><li>长度包括了msg结构长度</li></ul>
 *
 * @param[in] NA
 *
 * @retval > 0,返回支持的最大msg内存。
 * @retval < 0,-ENOSYS函数不支持。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_msg_maxsize_ops(void);

#ifdef CONFIG_DPA_DMI
/**
 * @brief 初始化dmi_client结构体
 *
 * @par 描述:
 * 初始化结构体，使用者只对使用字段初始化赋值
 *
 * @attention
 * <ul><li>dmi驱动拷贝结构体信息到全局变量维护，建议用户使用临时缓存，减少内存占用。</li></ul>
 *
 * @param[in] client, dmi_client结构体指针
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_client_init(struct dmi_client *client);

/**
 * @brief 注册client端处理回调
 *
 * @par 描述:
 * 注册dmi_id用户的回调处理
 *
 * @attention
 * <ul><li>同一个dmi_id用户只能注册一次，否则可能导致异常。</li></ul>
 *
 * @param[in] client, dmi_client结构体指针
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_client_register(struct dmi_client *client);

/**
 * @brief dmi消息发送，专用通道使用
 *
 * @par 描述:
 * host->fw侧发送dmi消息
 *
 * @attention
 * <ul><li>len包括dmi头，不超过512字节。不带唤醒DPA FW功能。用户调用接口前保证DPA处于唤醒态。</li></ul>
 *
 * @param[in] msg, dmi消息指针，使用dpa_dmi_msg_alloc申请的内存，发送完成内存由dmi驱动释放
 * @param[in] len, dmi消息长度
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_client_request(struct dmi_msg *msg, unsigned int len);

/**
 * @brief 申请dmi消息内存
 *
 * @par 描述:
 * 申请dmi消息内存
 *
 * @attention
 * <ul><li>专用通道使用。</li></ul>
 *
 * @param[in] dmi_id, 用户ID
 * @param[in] len, dmi消息长度，包括dmi头，不超过512字节
 *
 * @retval != NULL,返回dmi_msg内存指针，表示函数执行成功。
 * @retval == NULL,表示函数执行失败。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
struct dmi_msg *dpa_dmi_msg_alloc(unsigned int dmi_id, unsigned int len);

/**
 * @brief 释放dmi消息内存
 *
 * @par 描述:
 * 释放dmi消息内存
 *
 * @attention
 * <ul><li>专用通道使用。</li></ul>
 *
 * @param[in] msg, dmi消息的data指针
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_msg_free(struct dmi_msg_data *msg);

/**
 * @brief dmi消息发送，通用通道使用
 *
 * @par 描述:
 * host->fw侧发送dmi消息
 *
 * @attention
 * <ul><li>带唤醒DPA FW功能。,不能在中断上下文中使用/li></ul>
 *
 * @param[in] msg, dmi消息指针，内存用户自行申请，接口返回后内存可回收
 * @param[in] len, dmi消息长度
 *
 * @retval == 0,表示函数执行成功。
 * @retval < 0,表示函数执行失败，返回对应的错误码。
 *
 * @par 依赖:
 * <ul><li>dpa_dmi.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dmi_client_request_comm_wake(struct dmi_msg *msg, unsigned int len);
#else
static inline int dpa_dmi_client_init(struct dmi_client *client)
{
    return 0;
}

static inline int dpa_dmi_client_register(struct dmi_client *client)
{
    return 0;
}

static inline int dpa_dmi_client_request(struct dmi_msg *msg, unsigned int len)
{
    return -1;
}

static inline struct dmi_msg *dpa_dmi_msg_alloc(unsigned int dmi_id, unsigned int len)
{
    return NULL;
}

static inline int dpa_dmi_msg_free(struct dmi_msg_data *msg)
{
    return 0;
}

static inline int dpa_dmi_client_request_comm_wake(struct dmi_msg *msg, unsigned int len)
{
    return -1;
}
#endif
#ifdef __cplusplus
}
#endif
#endif
