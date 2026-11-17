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
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <net/ip6_route.h>
#include <securec.h>

#include "bsp_dmi.h"
#include "bsp_dpa_tc.h"
#include "dpa_tc_util.h"
#include "dpa_tc_interface.h"
#include "dpa_tc_statistics.h"

#define MIN_PACKET_PER_MSG (200)
#define MIN_PACKET_LEN (512)
#define MAX_PACKET_LEN (64000)


/* 流量统计临时SKB分配 */
static struct sk_buff *tc_alloc_skb(int sock_family, unsigned int sk_protocol)
{
    int hdr_len = 0;
    struct sk_buff *skb = alloc_skb(MIN_PACKET_LEN, GFP_KERNEL);
    if (unlikely(skb == NULL)) {
        TC_PRINT_ERR("alloc skb failed\n");
        TC_STATS_INC(ALLOC_SKB_FAIL_KMALLOC, 1);
        return NULL;
    }
    skb_set_mac_header(skb, 0);
    skb_reserve(skb, sizeof(struct ethhdr));
    skb_set_network_header(skb, 0);
    skb_put(skb, MIN_PACKET_LEN - sizeof(struct ethhdr));
    
    if (memset_s(skb->data, skb->len, 0, skb->len) != EOK) {
        TC_PRINT_ERR("skb data clear failed\n");
    }

    if (sock_family == AF_INET) {
        hdr_len += sizeof(struct iphdr);
        struct iphdr *iph = ip_hdr(skb);
        iph->version = 4;
        iph->ihl = 5;
        iph->frag_off = 0;
        iph->ttl = 255;
        /* 不能设置iph->protocol = sk_protocol;，否则需要5元组;如果没有5元组，会当作异常报文 */
        skb_set_transport_header(skb, hdr_len);
        skb->protocol = htons(ETH_P_IP);
    } else if (sock_family == AF_INET6) {
        hdr_len += sizeof(struct ipv6hdr);
        struct ipv6hdr *ip6h = ipv6_hdr(skb);
        ip6h->version = 6;
        ip6h->hop_limit = 128;
        ip6h->nexthdr = NEXTHDR_NONE;
        /* 不能设置ip6h->nexthdr = sk_protocol;，否则需要5元组;如果没有5元组，会当作异常报文 */
        skb_set_transport_header(skb, hdr_len);
        skb->protocol = htons(ETH_P_IPV6);

    } else {
        TC_PRINT_ERR("bad sock family %d protocol %d\n", sock_family, sk_protocol);
        kfree_skb(skb);
        TC_STATS_INC(ALLOC_SKB_FAIL_PARA, 1);
        return NULL;
    }
    return skb;
}

/* ipv4: 创建指向特定dev的临时rt */
static int tc_fwd_output(struct net *net, struct sock *sk, struct sk_buff *skb)
{
    return 1;
}

static struct rtable *tc_ipv4_rtable_create(struct net_device *dev)
{
    struct rtable *rth;

    rth = rt_dst_alloc(dev, 0, RTN_UNICAST, 1, 1);
    if (!rth) {
        return NULL;
    }

    rth->dst.output = tc_fwd_output;
    return rth;
}

/* ipv6: 创建指向特定dev的临时rt */
static struct rt6_info *tc_ipv6_rtable_create(struct net_device *dev)
{
    struct rt6_info *rth;
	int flags = DST_NOPOLICY |DST_NOXFRM;
    rth = ip6_dst_alloc(dev_net(dev), dev, flags);
    if (!rth) {
        return NULL;
    }

    return rth;
}

static struct dst_entry *tc_dst_create(int family, struct net_device *dev){

    if (family == AF_INET) {
        struct rtable *rt = tc_ipv4_rtable_create(dev);
        if (rt) {
            return &rt->dst;
        }
        TC_STATS_INC(IPV4_DST_CREATE_FAIL, 1);
    } else if (family == AF_INET6) {
        struct rt6_info *rt = tc_ipv6_rtable_create(dev);
        if (rt) {
            return &rt->dst;
        }
        TC_STATS_INC(IPV6_DST_CREATE_FAIL, 1);
    }
    return NULL;
}

static int tc_sock_statistics_send(struct sk_buff *skb, long long bytes, int need_netfilter)
{
    int ret = TC_CONTINUE;

    if (unlikely(bytes > MIN_PACKET_PER_MSG *MAX_PACKET_LEN )) {
        TC_PRINT_WARN("report send bytes may too big, bytes %lld \n", bytes);
    }

    long long left_len = bytes;
    struct sock *sk = skb->sk;
    int proto = sk->sk_family == AF_INET6? NFPROTO_IPV6: NFPROTO_IPV4;
    
    skb->pkt_type = PACKET_OUTGOING;
    skb->priority = sk->sk_priority;
    skb->mark = sk->sk_mark;

    for (; left_len > 0; left_len -= MAX_PACKET_LEN) {
        skb->len = left_len >= MAX_PACKET_LEN ? MAX_PACKET_LEN : left_len;
        TC_PRINT_DEBUG("send bytes %lld, left len %lld \n", bytes, left_len);

        // 进行netfilter处理
        if (need_netfilter){
            ret |= tc_nf_hook(proto, NF_INET_LOCAL_OUT, dev_net(skb->dev), sk, skb, NULL, skb->dev);
            ret |= tc_nf_hook(proto, NF_INET_POST_ROUTING, dev_net(skb->dev), sk, skb, NULL, skb->dev);
        }

        // 进行CGROUP流量统计
        TC_PRINT_CGROUP(skb);
        ret |= BPF_CGROUP_RUN_PROG_INET_EGRESS(sk, skb);
        TC_PRINT_CGROUP(skb);
        // 进行网卡流量统计
        tc_traverse_ptype(skb);
    }
    return ret;
}

static int tc_sock_statistics_recv(struct sk_buff *skb, long long bytes, int need_netfilter)
{
    int ret = TC_CONTINUE;
    if (unlikely(bytes > MIN_PACKET_PER_MSG *MAX_PACKET_LEN )) {
        TC_PRINT_WARN("report recv bytes may too big, bytes %lld \n", bytes);
    }

    long long left_len = bytes;
    struct sock *sk = skb->sk;
    int proto = sk->sk_family == AF_INET6? NFPROTO_IPV6: NFPROTO_IPV4;

    skb->priority = 0;
    skb->mark = 0;
    skb->pkt_type = PACKET_HOST;
    skb->skb_iif = skb->dev->ifindex;

    for (; left_len > 0; left_len -= MAX_PACKET_LEN) {
        skb->len = left_len >= MAX_PACKET_LEN ? MAX_PACKET_LEN : left_len;
        TC_PRINT_DEBUG("recv bytes %lld, left len %lld\n", bytes, left_len);
        // 进行网卡流量统计
        tc_traverse_ptype(skb);

        // 进行netfilter处理
        if (need_netfilter){
            ret |= tc_nf_hook(proto, NF_INET_PRE_ROUTING, dev_net(skb->dev), NULL, skb, skb->dev, NULL);
            ret |= tc_nf_hook(proto, NF_INET_LOCAL_IN, dev_net(skb->dev), NULL, skb, skb->dev, NULL);
        }

        // 进行CGROUP流量统计
        TC_PRINT_CGROUP(skb);
        ret |= BPF_CGROUP_RUN_PROG_INET_INGRESS(sk, skb);
        TC_PRINT_CGROUP(skb);
    }
    return ret;
}


static int tc_sock_statistics_item(struct sk_buff *skb, int index, sock_statistics_msg_item *item)
{
    struct dst_entry *dst;
    int need_netfilter = 0;
    struct net_device *dev = dev_get_by_index(sock_net(skb->sk), item->if_index);
    if (!dev){
        TC_PRINT_ERR("get dev error, item index %d, ifindex %d \n", index, item->if_index);
        TC_STATS_INC(SK_STATS_MSG_ITEM_FAIL_IFINDEX, 1);
        return -1;
    }
    skb->dev = dev;
    if (item->recv_bytes){
        tc_sock_statistics_recv(skb, item->recv_bytes, need_netfilter);
        TC_STATS_INC(SK_STATS_RECV_PACKETS, item->recv_pks);
        TC_STATS_INC(SK_STATS_RECV_BYTES, item->recv_bytes);
    }

    if (item->send_bytes) {
        dst = tc_dst_create(skb->sk->sk_family, dev);
        if (dst) {
            skb_dst_set(skb, dst);
            tc_sock_statistics_send(skb, item->send_bytes, need_netfilter);
            skb_dst_set(skb, (void *)NULL);
            dst_release(dst);
            TC_STATS_INC(SK_STATS_SEND_PACKETS, item->send_pks);
            TC_STATS_INC(SK_STATS_SEND_BYTES, item->send_bytes);
        }else {
            TC_PRINT_ERR("dst entyr create error, uid %u, dev %s ifindex %d \n", 
                SK_UID(skb->sk), dev->name, dev->ifindex);
            TC_STATS_INC(SK_STATS_MSG_ITEM_FAIL_CREATE_DST, 1);
        }
    } 
    dev_put(dev);
    skb->dev = NULL;
    return 0;
}

/* 直通或卸载应用Socket统计信息处理 */
int tc_sock_statistics_hook(struct sock *sk, sock_statistics_msg *msg)
{
    int index;
    unsigned int len;
    unsigned char *data;

    if (unlikely(IS_SK_STATS_DISABLE))
        return TC_CONTINUE;

    TC_STATS_INC(SK_STATS_CALLED, 1);

    if (unlikely(!sk || !msg || msg->num == 0)) {
        TC_PRINT_ERR("para error, sk %s, msg %s, item num %u \n", \
            PTR_IS_NULL(sk), PTR_IS_NULL(msg), msg == NULL? -1: msg->num);
        return TC_PRAR_ERR;
    }

    TC_STATS_INC(SK_STATS_MSG, 1);

    TC_PRINT_DEBUG("begin uid %u, item num %u \n", SK_UID(sk), msg->num);

    struct sk_buff *skb = tc_alloc_skb(sk->sk_family, sk->sk_protocol);
    if (skb == NULL) {
        TC_PRINT_ERR("alloc skb failed\n");
        return TC_INTERNAL_ERR;
    }
    /* 备份skb长度和指针*/
    len = skb->len;
    data = skb->data;

    skb->sk = sk;
    for (index = 0; index < msg->num; index++) {
        TC_PRINT_DEBUG("item index %d ifindex %d send_bytes %u recv_bytes %u\n", 
            index, msg->item[index].if_index, msg->item[index].send_bytes, msg->item[index].recv_bytes);

        TC_STATS_INC(SK_STATS_MSG_ITEM, 1);
        tc_sock_statistics_item(skb, index, &msg->item[index]);
    }

    skb->sk = NULL;

    /* 恢复skb长度和指针*/
    skb->data = data;
    skb->len = len;
    kfree_skb(skb);
    return TC_CONTINUE;
}


/* WIFI热点统计量处理netfilter处理函数 */
static int tc_forward_skb_nf_hook(
    int proto, struct sk_buff *skb, struct net_device *in_dev, struct net_device *out_dev, struct dst_entry *dst)
{
    int ret = TC_CONTINUE;

    ret = tc_nf_hook(proto, NF_INET_PRE_ROUTING, dev_net(in_dev), NULL, skb, in_dev, NULL);
    if (ret == NF_DROP) {
        TC_STATS_INC(WIFI_STATS_PACKETS_FAIL_NF_RREROUTEING, 1);
        TC_STATS_INC(WIFI_STATS_BYTES_FAIL_NF_RREROUTEING, skb->len);
        TC_PRINT_WARN("drop TC NF_PRE_ROUTING DROP");
    }

    ret = tc_nf_hook(proto, NF_INET_FORWARD, dev_net(in_dev), NULL, skb, in_dev, out_dev);
    if (ret == NF_DROP) {
        TC_STATS_INC(WIFI_STATS_PACKETS_FAIL_NF_FWD, 1);
        TC_STATS_INC(WIFI_STATS_BYTES_FAIL_NF_FWD, skb->len);
        TC_PRINT_WARN("drop TC NF_FOWARD DROP");
    }

    skb->dev = out_dev;
    skb->pkt_type = PACKET_OUTGOING;

    /* 不能删除，在POSTROUTE链上如果有类似-A bw_raw_PREROUTING -m policy规则时会访问，否则会Coredump */
    skb_dst_set(skb, dst);

    ret = tc_nf_hook(proto, NF_INET_POST_ROUTING, dev_net(out_dev), NULL, skb, NULL, out_dev);
    if (ret == NF_DROP) {
        TC_STATS_INC(WIFI_STATS_PACKETS_FAIL_NF_POSTOUTEING, 1);
        TC_STATS_INC(WIFI_STATS_BYTES_FAIL_NF_POSTOUTEING, skb->len);
        TC_PRINT_WARN("drop TC NF_POST_ROUTING DROP");
    }

    skb_dst_set(skb, (void *)NULL);
    return TC_CONTINUE;
}

/* WIFI热点统计量处理处理函数 */
int tc_forward_skb_statistics(unsigned long len, struct net_device *in_dev, struct net_device *out_dev)
{
    int sock_family = AF_INET;
    int proto = NFPROTO_IPV4;
    struct dst_entry *dst;
    long long left_len = len;

    if (unlikely(IS_WIFI_STATS_DISABLE))
        return TC_CONTINUE;

    TC_STATS_INC(WIFI_STATS_CALLED, 1);

    if (unlikely(!in_dev || !out_dev || (len == 0))) {
        TC_PRINT_ERR("error, in_dev %s, dst_dev %s, len %lu\n", PTR_IS_NULL(in_dev), PTR_IS_NULL(out_dev), len);
        TC_STATS_INC(WIFI_STATS_FAIL, 1);
        return TC_PRAR_ERR;
    }

    TC_PRINT_DEBUG("begin family %d len %lu in_dev %s dst_dev %s",\
        sock_family, len, in_dev->name, out_dev->name);

    struct sk_buff *skb = tc_alloc_skb(sock_family, IPPROTO_UDP);
    if (skb == NULL) {
        TC_PRINT_ERR("alloc skb failed\n");
        return TC_INTERNAL_ERR;
    }
    dst = tc_dst_create(sock_family, out_dev);
    if (dst == NULL) {
        TC_PRINT_ERR("dst entry failed,dev %s ifindex %d \n", out_dev->name, out_dev->ifindex);
        return TC_INTERNAL_ERR;
    }
    /* 进行netfilter处理需要该参数 */
    proto = (skb->protocol == htons(ETH_P_IP)) ? NFPROTO_IPV4 : NFPROTO_IPV6;

    TC_STATS_INC(WIFI_STATS_BYTES, left_len);

    for (; left_len > 0; left_len -= MAX_PACKET_LEN) {
        TC_PRINT_DEBUG("recv bytes %lu, left len %lld\n", len, left_len);
        skb->len = left_len >= MAX_PACKET_LEN ? MAX_PACKET_LEN : left_len;
        skb->pkt_type = PACKET_HOST;
        skb->dev = in_dev;

        /* 单框架进行入网卡流量统计 */
        tc_traverse_ptype(skb);
        /* netfilter规则 */
        tc_forward_skb_nf_hook(proto, skb, in_dev, out_dev, dst);
        /* 单框架进行入网卡流量统计 */
        tc_traverse_ptype(skb);
    }

    skb_dst_set(skb, (void *)NULL);
    dst_release(dst);
    kfree_skb(skb);
    
    TC_PRINT_DEBUG("end family %d len %lu in_dev %s dst_dev %s",\
        sock_family, len, in_dev->name, out_dev->name);

    return TC_CONTINUE;
}

/* 用于C核消息回调处理函数 */
EXPORT_SYMBOL(tc_forward_skb_statistics);

/* WIFI热点DPA<->A核消息回调处理函数 */
static int tc_wifishare_statistics_cb(char *buf, unsigned int len)
{
    wifishare_statistics_msg *msg = (wifishare_statistics_msg *)buf;
    int index = 0;

    TC_STATS_INC(WIFI_DCORE_STATS_CALLED, 1);

    if (msg->num > MAX_WIFI_STATS_ITEM_NUM){
        TC_PRINT_ERR("msg num %u overflow\n", msg->num);
        return TC_PRAR_ERR;
    }

    if (len != sizeof(wifishare_statistics_msg)){
        TC_PRINT_ERR("msg len %u is not match, msg len should be %lu\n",  len, sizeof(wifishare_statistics_msg));
        return TC_PRAR_ERR;
    }

    TC_STATS_INC(WIFI_DCORE_STATS_MSG, 1);

    for (index = 0; index < msg->num; index++){
        TC_PRINT_DEBUG("itemindex %d, bytes %u, in dev ifindex %d, out dev ifindex %d\n", \
            index, msg->item[index].bytes, msg->item[index].in_ifindex, msg->item[index].out_ifindex);

        TC_STATS_INC(WIFI_DCORE_STATS_ITEM, 1);

        if (msg->item[index].bytes){
            struct net_device *in_dev = dev_get_by_index(&init_net, msg->item[index].in_ifindex);
            if (!in_dev){
                TC_PRINT_ERR("get in_dev error,ifindex %u\n",  msg->item[index].in_ifindex);
                TC_STATS_INC(WIFI_DCORE_STATS_ITEM_FAIL, 1);
                continue;
            }
            struct net_device *out_dev = dev_get_by_index(&init_net, msg->item[index].out_ifindex);
            if (!out_dev){
                TC_PRINT_ERR("get out_dev error,ifindex %u\n",  msg->item[index].out_ifindex);
                dev_put(in_dev);
                TC_STATS_INC(WIFI_DCORE_STATS_ITEM_FAIL, 1);
                continue;
            }
            tc_forward_skb_statistics(msg->item[index].bytes, in_dev, out_dev);
            dev_put(in_dev);
            dev_put(out_dev);
            TC_STATS_INC(WIFI_DCORE_STATS_PACKETS, msg->item[index].pkts);
            TC_STATS_INC(WIFI_DCORE_STATS_BYTES, msg->item[index].bytes);
        }else {
            TC_STATS_INC(WIFI_DCORE_STATS_ITEM_FAIL, 1);
        }
    }
    return 0;
}

/* WIFI热点DPA<->A核消息通道初始化以及回调注册 */
static int dpa_tc_cb(char *priv, unsigned int id, struct dmi_msg_data *msg)
{
    int ret;
    if (msg == NULL) {
        TC_PRINT_ERR("dpa tc cb msg is null\n");
        return -1;
    }
    switch (id) {
        case DPA_TC_DCORE_WIFI_REPORT:
            ret = tc_wifishare_statistics_cb(msg->buf, msg->len);
            break;
        default:
            ret = -1;
            TC_PRINT_ERR("dpa tc cb msg dispatch fail\n");
            break;
    }
    bsp_dmi_msg_free(msg);
    return ret;
}

static int tc_wifishare_statistics_subscribe(void)
{
    int ret;
    struct dmi_client tc_dmi_client;
    ret = bsp_dmi_client_init(&tc_dmi_client);
    if (ret != 0) {
        TC_PRINT_ERR("dpa tc client_dmi init fail\n");
        return ret;
    }
    tc_dmi_client.dmi_id = DMI_SERVICE_TC;
    tc_dmi_client.service_cb = dpa_tc_cb;

    ret = bsp_dmi_client_register(&tc_dmi_client);
    if (ret != 0) {
        TC_PRINT_ERR("dpa tc client_dmi fail\n");
        return ret;
    }
    return ret;
}

int tc_wifishare_statistics_init(void)
{
    int ret;
    ret = tc_wifishare_statistics_subscribe();
    if (ret) {
        TC_PRINT_ERR("dpa tc subscribe init fail\n");
        return ret;
    }

    TC_PRINT_INFO("dpa tc init success.\n");
    return 0;
}

EXPORT_SYMBOL(tc_wifishare_statistics_init);
