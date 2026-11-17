/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
 *
 */
#ifndef __MDRV_FIPC_H__
#define __MDRV_FIPC_H__

typedef unsigned fipc_chn_t;

/**
 * @brief fipc发送通道类型，用于打开通道时fipc_chn_attr_t.type
 */
#define FIPC_CHN_TYPE_SEND 0x0
/**
 * @brief fipc接收通道类型，用于打开通道时fipc_chn_attr_t.type
 */
#define FIPC_CHN_TYPE_RECV 0x1
/**
 * @brief fipc无效通道类型，用于打开通道时fipc_chn_attr_t.type
 */
#define FIPC_CHN_TYPE_INVAILD 0xFFFFFFFFUL

/** @brief 默认情况下, 数据到达，接收方总是有通知的，该标志可以关闭该通知 */
#define FIPC_ATTR_FLAGS_NOARRVEVENT (1U << 0)
/** @brief 设置该标记的通道，DPM低功耗时不管理(这种通道必须是DMA通道) */
#define FIPC_ATTR_FLAGS_DPMSRIGNORE (1U << 4)
/** @brief 设置该标记，表示DMA搬移完成需要上报中断 */
#define FIPC_ATTR_FLAGS_SENDDONEEN (1U << 5)
/** @brief 设置该标记，表示支持DMA外设搬移 */
#define FIPC_ATTR_FLAGS_PERITRANS (1U << 6)
#define FIPC_ATTR_FLAGS_TIMEOUTINTEN (1U << 8)
/** @brief 设置该标记的通道，低功耗管理在特定级别(需要硬件资源支持，使用该标记请与开发者确认) */
#define FIPC_ATTR_FLAGS_DSSCTRLSR (1U << 31)

#define FIPC_SEND_FLAGS_NOARRVNOTIFY (1UL << 0)
#define FIPC_SEND_FLAGS_NODONENOTIFY (1UL << 1)

#define MDRV_FIPC_CHN_SEND_AP2TSP_V2X (0x160)
#define MDRV_FIPC_CHN_RECV_AP2TSP_V2X (0x161)
#define MDRV_FIPC_CHN_SEND_TSP2AP_V2X (0x162)
#define MDRV_FIPC_CHN_RECV_TSP2AP_V2X (0x163)
#define MDRV_FIPC_CHN_SEND_DMA_V2X (0x164)

/**
 * @brief fipc回调事件类型
 */
typedef enum {
    FIPC_EVENT_DATA_ARRV,
    FIPC_EVENT_SEND_DONE,
    FIPC_EVENT_SEND_FLOWUP,
    FIPC_EVENT_SEND_FLOWDN,
    FIPC_EVENT_INVAILD,
} fipc_event;

/**
 * @brief fipc回调事件额外参数
 */
typedef union {
    struct {
        unsigned chnid;
        fipc_chn_t chn_hdl;
    } data_arrv; /* used for give information for event FIPC_EVENT_DATA_ARRV */
} fipc_eventinfo;

/**
 * @brief fipc回调
 * @attention
 * <ul><li>此回调直接执行在中断上下文</li></ul>
 * @param[in]  event, 此次回调的事件类型
 * @param[in]  cbk_arg, 用户私有参数，此参数来自于open通道时用户传入
 * @param[in]  info, 此次回调所带的额外信息
 *
 * @retval 0,回调正确处理。
 * @retval 非0,回调未正确处理。
 *
 * @see mdrv_fipc_chn_open
 */
typedef int (*fipc_cbk)(fipc_event event, void *cbk_arg, const fipc_eventinfo *info);
typedef int (*fipc_irq_wakeup_cbk)(void *cbk_arg);

/**
 * @brief 用户打开通道时的输入参数
 * @attention
 * <ul><li>该结构体在使用前,必须使用fipc_chn_attr_init初始化</li></ul>
 * @see mdrv_fipc_chn_attr_init mdrv_fipc_chn_open
 */
typedef struct {
    unsigned chnid;        /**< 通道的id定义, 在attr_init后用户填写 */
    unsigned type;         /**< 通道收发属性，例如FIPC_CHN_TYPE_SEND ,在attr_init后用户填写 */
    unsigned long long pa; /**< ringbuf物理地址，硬件有对齐要求 8Bytes, 在attr_init后用户填写 */
    void *va;              /**< ringbuf虚拟地址,在attr_init后用户填写 */
    unsigned size;         /**< ringbuf大小，硬件有对齐要求 128Bytes,在attr_init后用户填写 */
    fipc_cbk cbk;          /**< fipc事件发生时的回调函数, 在attr_init后用户填写*/
    void *cbk_arg;         /**< 回调时，透传的用户私有数据，用户需要保证cbk_arg的生命周期,在attr_init后用户填写 */
    unsigned req_sel;      /**< 外设请求选择编号 */
    unsigned flags;        /**< 一些标志，比如唤醒，报中断等, 不清楚用处的在attr_init后不要操作 */
    fipc_irq_wakeup_cbk irq_wakeup_cbk; /**< fipc识别acore唤醒源后执行的回调, 在attr_init后用户填写*/
    void *irq_cbk_arg;  /**< 识别acore唤醒源后执行回调时，透传的用户私有数据，用户需要保证irq_cbk_arg的生命周期,在attr_init后用户填写 */
    unsigned flup;
    unsigned fldn;
    unsigned timeout;
} fipc_chn_attr_t;

/**
 * @brief 初始化通道属性参数
 *
 * @par 描述:
 * 初始化通道属性参数
 *
 * @attention
 * <ul><li>申请高速内存时，若无内存可用，会依次尝试往低速方向分配内存</li></ul>
 *
 * @param[in]  attr, 申请消息内存的模块id
 *
 * @retval 0,表示初始化成功。
 * @retval !=0,表示初始化失败。

 * @par 依赖:
 * <ul><li>mdrv_fipc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see mdrv_fipc_chn_attr_init
 */
int mdrv_fipc_chn_attr_init(fipc_chn_attr_t *attr); 

/**
 * @brief 打开通道
 *
 * @par 描述:
 * 根据属性参数打开通道
 *
 * @attention
 * <ul><li>申请高速内存时，若无内存可用，会依次尝试往低速方向分配内存</li></ul>
 *
 * @param[in]  pchn_hdl, 申请消息内存的模块id
 * @param[in]  attr, 申请消息内存的长度
 *
 * @retval 0,表示打开通道成功。
 * @retval !=0,表示打开通道失败。

 * @par 依赖:
 * <ul><li>mdrv_fipc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see mdrv_fipc_chn_open
 */
int mdrv_fipc_chn_open(fipc_chn_t *pchn_hdl, fipc_chn_attr_t *attr);

/**
 * @brief 获取通道ringbuf的rptr
 *
 * @par 描述:
 * 获取通道ringbuf的rptr
 *
 * @attention
 * <ul><li>申请高速内存时，若无内存可用，会依次尝试往低速方向分配内存</li></ul>
 *
 * @param[in]  chn_hdl, 通道handler，open通道时获得
 * @param[in]  rptr, 通道rptr
 *
 * @retval 0,表示获取rptr成功。
 * @retval !=0,表示获取rptr失败。

 * @par 依赖:
 * <ul><li>mdrv_fipc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see mdrv_fipc_chn_rptr_get
 */
int mdrv_fipc_chn_rptr_get(fipc_chn_t chn_hdl, unsigned int *rptr);

/**
 * @brief 获取通道ringbuf的wptr
 *
 * @par 描述:
 * 获取通道ringbuf的wptr
 *
 * @attention
 * <ul><li>申请高速内存时，若无内存可用，会依次尝试往低速方向分配内存</li></ul>
 *
 * @param[in]  chn_hdl, 通道handler，open通道时获得
 * @param[in]  wptr, 通道wptr
 *
 * @retval 0,表示获取wptr成功。
 * @retval !=0,表示获取wptr失败。

 * @par 依赖:
 * <ul><li>mdrv_fipc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see mdrv_fipc_chn_wptr_get
 */
int mdrv_fipc_chn_wptr_get(fipc_chn_t chn_hdl, unsigned int *wptr);

/**
 * @brief 更新接收通道ringbuf的rptr
 *
 * @par 描述:
 * 更新接收通道ringbuf的rptr
 *
 * @attention
 * <ul><li>申请高速内存时，若无内存可用，会依次尝试往低速方向分配内存</li></ul>
 *
 * @param[in]  chn_hdl, 通道handler，open通道时获得
 * @param[in]  rptr, 带更新的rptr值
 *
 * @retval 0,表示更新rptr成功。
 * @retval !=0,表示更新rptr失败。

 * @par 依赖:
 * <ul><li>mdrv_fipc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see mdrv_fipc_chn_ringbuf_rptr_set
 */
int mdrv_fipc_chn_ringbuf_rptr_set(fipc_chn_t chn_hdl, unsigned int rptr);

/**
 * @brief 发送消息接口
 *
 * @par 描述:
 * 发送核间消息
 *
 * @attention
 * <ul><li>申请高速内存时，若无内存可用，会依次尝试往低速方向分配内存</li></ul>
 *
 * @param[in]  chn_hdl, 通道handler，open通道时获得
 * @param[in]  buf, 带发送消息的地址
 * @param[in]  len, 待发送消息负载长度
 * @param[in]  flags: MDRV_FIPC_SEND_FLAGS，按照bit位控制
 *                   MDRV_FIPC_SEND_FLAGS_NOARRVNOTIFY，不产生数据到达中断
 *                   MDRV_FIPC_SEND_FLAGS_NODONENOTIFY，不产生搬移完成中断
 *
 * @retval 0,表示发送消息成功。
 * @retval !=0,表示发送消息失败。

 * @par 依赖:
 * <ul><li>mdrv_fipc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see mdrv_fipc_chn_blk2ring_send
 */
int mdrv_fipc_chn_blk2ring_send(fipc_chn_t chn_hdl, void *buf, unsigned len, u32 flags);

#endif
