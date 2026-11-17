/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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

#ifndef _BSP_DPA_TC_H
#define _BSP_DPA_TC_H

#include <net/sock.h>
#include <linux/skbuff.h>

/**
 * @brief DPA TC BPF/Netfilter检查返回值
 */
enum {
    TC_CONTINUE = 0,
    TC_NF_PRE_ROUTING_DROP,
    TC_NF_POST_ROUTING_DROP,
    TC_NF_FOWARD_DROP,
    TC_NF_LOCAL_IN_DROP,
    TC_NF_LOCAL_OUT_DROP,
    TC_BPF_CGROUP_DROP,
    TC_PRAR_ERR,
    TC_INTERNAL_ERR
};

/**
 * @brief 卸载应用收包处理
 * @par 描述:
 * 用于处理卸载应用收到的数据报文
 *
 * @attention
 * <ul><li> 用于卸载应用从DPA接收报文后调用</li></ul>
 * @param[in]  skb , 报文
 *
 * @retval TC_CONTINUE,继续进行后续协议栈处理
 * @retval != TC_CONTINUE,BPF/Netfilter检查失败
 */
#ifdef CONFIG_DPA_TC
int tc_ingress_skb_hook(struct sk_buff *skb);
#else
static inline int tc_ingress_skb_hook(struct sk_buff *skb)
{
    return TC_CONTINUE;
}
#endif

/**
 * @brief 卸载应用发包处理
 * @par 描述:
 * 用于处理卸载应用发送的数据报文
 *
 * @attention
 * <ul><li> 用于卸载应用向DPA发送报文前调用</li></ul>
 * @param[in]  skb , 报文
 *
 * @retval TC_CONTINUE,继续进行后续协议栈处理
 * @retval != TC_CONTINUE,BPF/Netfilter检查失败
 */
#ifdef CONFIG_DPA_TC
int tc_egress_skb_hook(struct sk_buff *skb);
#else
static inline int tc_egress_skb_hook(struct sk_buff *skb)
{
    return TC_CONTINUE;
}
#endif

/**
 * @brief 卸载应用Socket Sendmsg检查
 * @par 描述:
 * 用于处理卸载应用中UDP Socket进行msgsend操作时进行BPF检查
 *
 * @attention
 * <ul><li> 用于卸载应用UDP Socket向DPA发送报文前调用(第一次connect时)</li></ul>
 * @param[in]  lsk , socket
  * @param[in]  msg , 报文
 *
 * @retval TC_CONTINUE,继续进行后续协议栈处理
 * @retval != TC_CONTINUE,BPF/Netfilter检查失败
 */
#ifdef CONFIG_DPA_TC
int tc_udpsk_sendmsg_hook(struct sock *lsk, struct msghdr *msg);
#else
static inline int tc_udpsk_sendmsg_hook(struct sock *lsk, struct msghdr *msg)
{
    return TC_CONTINUE;
}
#endif


/**
 * @brief socket应用流量统计消息
 */
#define MAX_INTERFACE (4)   // 一段统计周期内最多四个网卡:wlan0\wlan1\rmnet0\rmnet1
#pragma pack (4)
typedef struct {
    unsigned int  if_index;         // linux内核网卡idx
    unsigned int  send_pks;         // 报文发送数量
    unsigned int  recv_pks;         // 报文接收数量
    unsigned int send_bytes;  // 报文发送字节数
    unsigned int recv_bytes;  // 报文接收字节数
}sock_statistics_msg_item;

typedef struct {
    unsigned int  num;              // 有流量的网卡的数量
    unsigned int  sk_index;         // socket id
    sock_statistics_msg_item item[MAX_INTERFACE];
}sock_statistics_msg;
#pragma pack ()


/**
 * @brief 直通或卸载应用Socket统计信息处理
 * @par 描述:
 * 用于处理直通或卸载应用中上报的Socket流量统计信息
 *
 * @attention
 * <ul><li> 用于直通或卸载应用中上报消息到TCP/IP协议栈后调用</li></ul>
 * @param[in]  sk , socket
  * @param[in]  msg , 报文
 *
 * @retval TC_CONTINUE,处理成功
 * @retval != TC_CONTINUE,处理失败
 */
#ifdef CONFIG_DPA_TC
int tc_sock_statistics_hook(struct sock *sk, sock_statistics_msg *msg);
#else
static inline int tc_sock_statistics_hook(struct sock *sk, sock_statistics_msg *msg)
{
    return 0;
}
#endif

#endif
