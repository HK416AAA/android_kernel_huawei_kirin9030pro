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

#include <linux/types.h>
#include <linux/filter.h>
#include <linux/bpf-cgroup.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv6.h>
#include <net/sock.h>
#include <net/inet_sock.h>

#include "bsp_dpa_tc.h"
#include "dpa_tc_util.h"
#include "dpa_tc_interface.h"

// 将报文偏移至IP开始位置，保存原有头部指针和长度
#define SKB_BACKUP(skb, skb_data, skb_len)                          \
    do {                                                    \
        int offset;                                          \
        (skb_data) = (skb)->data;                               \
        (skb_len) = (skb)->len;                                 \
        offset = (skb)->data - skb_network_header(skb); \
        if (unlikely(offset < 0)) {                         \
            __skb_pull(skb, -offset);                       \
        } else {                                            \
            __skb_push(skb, offset);                        \
        }                                                   \
    } while (0)


// 将报文指针和长度恢复至原有头部指针和长度
#define SKB_RESTORE(skb, skb_data, skb_len) \
    do {                            \
        (skb)->data = (skb_data);         \
        (skb)->len = (skb_len);           \
    } while (0)

static int tc_ingress_skb_nf_hook(int proto, struct sk_buff *skb, struct net_device *dev)
{
    int ret;
    ret = tc_nf_hook(proto, NF_INET_PRE_ROUTING, dev_net(dev), NULL, skb, dev, NULL);
    if (ret == NF_DROP) {
        TC_STATS_INC(SKB_INGRESS_PACKETS_FAIL_NF_PREROUTEING, 1);
        TC_STATS_INC(SKB_INGRESS_BYTES_FAIL_NF_PREROUTEING, skb->len);
        return TC_NF_PRE_ROUTING_DROP;
    }

    ret = tc_nf_hook(proto, NF_INET_LOCAL_IN, dev_net(dev), NULL, skb, dev, NULL);
    if (ret == NF_DROP) {
        TC_STATS_INC(SKB_INGRESS_PACKETS_FAIL_NF_LOCAL_IN, 1);
        TC_STATS_INC(SKB_INGRESS_BYTES_FAIL_NF_LOCAL_IN, skb->len);
        return TC_NF_LOCAL_IN_DROP;
    }
    return TC_CONTINUE;
}

int tc_ingress_skb_hook(struct sk_buff *skb)
{
    int ret = TC_CONTINUE, cgrp_ret;
    unsigned char *skb_head;
    int skb_len;

    if (unlikely(IS_SKB_INGRESS_DISABLE))
        return TC_CONTINUE;

    TC_STATS_INC(SKB_INGRESS_CALLED, 1);

    if (unlikely(!skb)) {
        TC_PRINT_ERR("error, skb is null!\n");
        return TC_CONTINUE;
    }
    if (unlikely(!skb->sk || !skb->dev)) {
        TC_PRINT_ERR("error, skb sk %s, skb dev %s\n", PTR_IS_NULL(skb->sk), PTR_IS_NULL(skb->dev));
        return TC_CONTINUE;
    }

    TC_PRINT_SKB("tc_ingress_skb_hook begin", skb);

    // 数据报文可能data位置已经偏移过IP头部，需要修正到IP头部
    SKB_BACKUP(skb, skb_head, skb_len);

    TC_STATS_INC(SKB_INGRESS_PACKETS, 1);
    TC_STATS_INC(SKB_INGRESS_BYTES, skb->len);
    TC_STATS_INC(SKB_INGRESS_SEGS, skb_shinfo(skb)->gso_segs);

    // 进行网卡流量统计
    tc_traverse_ptype(skb);

    // 进行netfilter处理
    if (skb->sk->sk_family == AF_INET) {  // ipv4
        ret = tc_ingress_skb_nf_hook(NFPROTO_IPV4, skb, skb->dev);
    } else if (skb->sk->sk_family == AF_INET6) {  // ipv6
        ret = tc_ingress_skb_nf_hook(NFPROTO_IPV6, skb, skb->dev);
    }
    if (ret != TC_CONTINUE) {
        TC_PRINT_WARN("tc_ingress_skb_nf_hook drop: familiy %d prot %u uid %u dev %s %u len %u ret %d\n",
            skb->sk->sk_family, skb->protocol, SKB_UID(skb), skb->dev->name, skb->dev->ifindex, skb->len, ret);
        goto tc_ingress_skb_hook_end;  // 注意不能return，要恢复偏移
    }

    // 进行CGROUPO流量统计和防火墙处理
    TC_PRINT_CGROUP(skb);
    cgrp_ret = BPF_CGROUP_RUN_PROG_INET_INGRESS(skb->sk, skb);
    TC_PRINT_CGROUP(skb);
    if (cgrp_ret) {
        TC_PRINT_WARN("bpf cgroup ingress drop: uid %d len %d ret %d,\n", SKB_UID(skb), skb->len, cgrp_ret);
        ret = TC_BPF_CGROUP_DROP;
        TC_STATS_INC(SKB_INGRESS_PACKETS_FAIL_CGROUP, 1);
        TC_STATS_INC(SKB_INGRESS_BYTES_FAIL_CGROUP, skb->len);
        goto tc_ingress_skb_hook_end;//注意不能return，要恢复偏移
    }
    ret = TC_CONTINUE;

tc_ingress_skb_hook_end:
    // 恢复偏移
    SKB_RESTORE(skb, skb_head, skb_len);

    TC_PRINT_SKB("tc_ingress_skb_hook end", skb);

    return ret;
}

static int tc_egress_skb_nf_hook(int proto, struct sk_buff *skb, struct sock *sk, struct net_device *dev)
{
    int ret;
    ret = tc_nf_hook(proto, NF_INET_LOCAL_OUT, dev_net(dev), sk, skb, NULL, dev);
    if (ret == NF_DROP) {
        TC_STATS_INC(SKB_EGRESS_PACKETS_FAIL_NF_LOCAL_OUT, 1);
        TC_STATS_INC(SKB_EGRESS_BYTES_FAIL_NF_LOCAL_OUT, skb->len);
        return TC_NF_LOCAL_OUT_DROP;
    }

    ret = tc_nf_hook(proto, NF_INET_POST_ROUTING, dev_net(dev), sk, skb, NULL, dev);
    if (ret == NF_DROP) {
        TC_STATS_INC(SKB_EGRESS_PACKETS_FAIL_NF_POSTOUTEING, 1);
        TC_STATS_INC(SKB_EGRESS_BYTES_FAIL_NF_POSTOUTEING, skb->len);
        return TC_NF_POST_ROUTING_DROP;
    }
    return TC_CONTINUE;
}

static int tc_egress_skb_cgroup_hook(struct sock *sk, struct sk_buff *skb)
{
    int ret;
    TC_PRINT_CGROUP(skb);
    ret = BPF_CGROUP_RUN_PROG_INET_EGRESS(sk, skb);
    TC_PRINT_CGROUP(skb);
    switch (ret) {
        case NET_XMIT_SUCCESS:
        case NET_XMIT_CN:
            return TC_CONTINUE;
        default:
            TC_PRINT_WARN("bpf cgroup egress drop: uid %u len %u ret %d,\n", SKB_UID(skb), skb->len, ret);
            TC_STATS_INC(SKB_EGRESS_PACKETS_FAIL_CGROUP, 1);
            TC_STATS_INC(SKB_EGRESS_BYTES_FAIL_CGROUP, skb->len);
            return TC_BPF_CGROUP_DROP;
    }
    return TC_CONTINUE;
}

int tc_egress_skb_hook(struct sk_buff *skb)
{
    int ret = TC_CONTINUE;
    unsigned char *skb_head;
    int skb_len;

    if (unlikely(IS_SKB_EGRESS_DISABLE))
        return TC_CONTINUE;

    TC_STATS_INC(SKB_EGRESS_CALLED, 1);

    if (unlikely(!skb)) {
        TC_PRINT_ERR("error, skb is null\n");
        return TC_CONTINUE;
    }
    if (unlikely(!skb->sk || !skb->dev)) {
        TC_PRINT_ERR("error, skb sk %s ,skb dev %s\n", PTR_IS_NULL(skb->sk), PTR_IS_NULL(skb->dev));
        return TC_CONTINUE;
    }

    if (unlikely(skb->_skb_refdst == 0)) {
        TC_PRINT_ERR("error, skb dst is zero\n");
        return TC_CONTINUE;
    }

    TC_PRINT_SKB("tc_egress_skb_hook begin", skb);

    // 数据报文可能data位置已经偏移过IP头部，需要修正到IP头部
    SKB_BACKUP(skb, skb_head, skb_len);

    TC_STATS_INC(SKB_EGRESS_PACKETS, 1);
    TC_STATS_INC(SKB_EGRESS_BYTES, skb->len);
    TC_STATS_INC(SKB_EGRESS_SEGS, skb_shinfo(skb)->gso_segs);
    
    // 进行netfilter处理
    if (skb->sk->sk_family == AF_INET) {  // ipv4
        ret = tc_egress_skb_nf_hook(NFPROTO_IPV4, skb, skb->sk, skb->dev);
    } else if (skb->sk->sk_family == AF_INET6) {  // ipv6
        ret = tc_egress_skb_nf_hook(NFPROTO_IPV6, skb, skb->sk, skb->dev);
    }

    if (ret != TC_CONTINUE) {
        TC_PRINT_WARN("tc_egress_skb_nf_hook drop: familiy %d prot %u uid %u dev %s %u len %u ret %d\n",
            skb->sk->sk_family, skb->protocol, SKB_UID(skb), skb->dev->name, skb->dev->ifindex, skb->len, ret); 
        goto tc_egress_skb_hook_end;  // 注意不能return，要恢复偏移
    }

    ret = tc_egress_skb_cgroup_hook(skb->sk, skb);
    if (ret != TC_CONTINUE) {
        goto tc_egress_skb_hook_end;  // 注意不能return，要恢复偏移
    }
    
    // 进行网卡流量统计
    tc_traverse_ptype(skb);
    ret = TC_CONTINUE;

tc_egress_skb_hook_end:
    // 恢复偏移
    SKB_RESTORE(skb, skb_head, skb_len);

    TC_PRINT_SKB("tc_egress_skb_hook end", skb);
    return ret;
}


int tc_udpsk_sendmsg_hook(struct sock *sk, struct msghdr *msg)
{
    int ret = 0;

    if (unlikely(IS_SK_UDP_BPF_DISABLE))
        return ret;

    TC_STATS_INC(SK_UDP_SEND_BPF_CALLED, 1);

    if (sk->sk_family == AF_INET6) {
        DECLARE_SOCKADDR(struct sockaddr_in6 *, sin6, msg->msg_name);
        struct ipv6_pinfo *np = inet6_sk(sk);
        if (np){
            struct in6_addr saddr = np->saddr;
            ret = __cgroup_bpf_run_filter_sock_addr(sk, (struct sockaddr *)sin6, BPF_CGROUP_UDP6_SENDMSG,&saddr);
        }
    } else if (sk->sk_family == AF_INET){
        DECLARE_SOCKADDR(struct sockaddr_in *, usin, msg->msg_name);
        struct ipcm_cookie ipc;
        ipc.addr = inet_sk(sk)->inet_saddr;
        ret = __cgroup_bpf_run_filter_sock_addr(sk, (struct sockaddr *)usin, BPF_CGROUP_UDP4_SENDMSG,&ipc.addr);
    }
    TC_PRINT_DEBUG("ip version %s return %d\n", sk->sk_family == AF_INET?"V4":"V6", ret);

    if (ret)
        TC_STATS_INC(SK_UDP_SEND_BPF_FAIL, 1);

    return ret;

}