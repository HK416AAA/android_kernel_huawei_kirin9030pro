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
#include <linux/skbuff.h>
#include <linux/bpf.h>
#include <net/inet_sock.h>
#include <net/sock.h>
#include <securec.h>

#include "dpa_tc_util.h"

// TC打印信息控制
int g_dpa_tc_print = 0;
int dpa_tc_print_enable(int mask)
{
    g_dpa_tc_print = mask;

    return g_dpa_tc_print;
}
EXPORT_SYMBOL(dpa_tc_print_enable);

int dpa_tc_print_show(void)
{
    TC_PRINT_ERR("dpa tc trace mask %d",g_dpa_tc_print);
    TC_PRINT_ERR("WARN_MASK:0x%x , DEBUG_MASK:0x%x, SKB_MASK:0x%x, CGROUP_MASK:0x%x, IFSTAT_MASK:0x%x", \
        WARN_MASK, DEBUG_MASK, SKB_MASK, CGROUP_MASK, IFSTAT_MASK);
    return g_dpa_tc_print;
}
EXPORT_SYMBOL(dpa_tc_print_show);

// TC功能控制
int g_dpa_tc_func = 0;
int dpa_tc_func_disable(int mask)
{
    g_dpa_tc_func = mask;

    return g_dpa_tc_func;
}
EXPORT_SYMBOL(dpa_tc_func_disable);

int dpa_tc_func_show(void)
{
    TC_PRINT_ERR("dpa tc func mask %d",g_dpa_tc_func);
    TC_PRINT_ERR("SKB_INGRESS_MASK:0x%x , SKB_EGRESS_MASK:0x%x, SK_UDP_BPF_MASK:0x%x, \
        SK_STATS_MASK:0x%x, WIFI_STATS_MASK:0x%x", \
        SKB_INGRESS_MASK, SKB_EGRESS_MASK, SK_UDP_BPF_MASK, SK_STATS_MASK, WIFI_STATS_MASK);
    return g_dpa_tc_func;
}
EXPORT_SYMBOL(dpa_tc_func_show);

// TC统计数据
atomic_t g_dpa_tc_statistics[MAX_STATS_NUM];
int dpa_tc_statistics_reset(void)
{
    int index;
    for (index = 0; index < MAX_STATS_NUM; index++){
        atomic_set(&g_dpa_tc_statistics[index], 0);
    }
    return 0;
}
EXPORT_SYMBOL(dpa_tc_statistics_reset);

#define __TC_STR(e)  #e

unsigned char g_dpa_tc_statistics_str[MAX_STATS_NUM][MAX_STR_SIZE] = {
// 卸载白名单应用收包统计
__TC_STR(SKB_INGRESS_CALLED),
__TC_STR(SKB_INGRESS_PACKETS),
__TC_STR(SKB_INGRESS_BYTES),
__TC_STR(SKB_INGRESS_PACKETS_FAIL_CGROUP),
__TC_STR(SKB_INGRESS_BYTES_FAIL_CGROUP),
__TC_STR(SKB_INGRESS_PACKETS_FAIL_NF_LOCAL_IN),
__TC_STR(SKB_INGRESS_BYTES_FAIL_NF_LOCAL_IN),
__TC_STR(SKB_INGRESS_PACKETS_FAIL_NF_PREROUTEING),
__TC_STR(SKB_INGRESS_BYTES_FAIL_NF_PREROUTEING),
__TC_STR(SKB_INGRESS_SEGS),

// 卸载白名单应用发包统计
__TC_STR(SKB_EGRESS_CALLED),
__TC_STR(SKB_EGRESS_PACKETS),
__TC_STR(SKB_EGRESS_BYTES),
__TC_STR(SKB_EGRESS_PACKETS_FAIL_CGROUP),
__TC_STR(SKB_EGRESS_BYTES_FAIL_CGROUP),
__TC_STR(SKB_EGRESS_PACKETS_FAIL_NF_LOCAL_OUT),
__TC_STR(SKB_EGRESS_BYTES_FAIL_NF_LOCAL_OUT),
__TC_STR(SKB_EGRESS_PACKETS_FAIL_NF_POSTOUTEING),
__TC_STR(SKB_EGRESS_BYTES_FAIL_NF_POSTOUTEING),
__TC_STR(SKB_EGRESS_SEGS),

// 卸载白名单应用UDP发包统计
__TC_STR(SK_UDP_SEND_BPF_CALLED),
__TC_STR(SK_UDP_SEND_BPF_FAIL),

// 直通应用Socket流量统计
__TC_STR(SK_STATS_CALLED),
__TC_STR(SK_STATS_MSG),
__TC_STR(SK_STATS_MSG_ITEM),
__TC_STR(SK_STATS_MSG_ITEM_FAIL_IFINDEX),
__TC_STR(SK_STATS_MSG_ITEM_FAIL_CREATE_DST),
__TC_STR(SK_STATS_SEND_PACKETS),
__TC_STR(SK_STATS_SEND_BYTES),
__TC_STR(SK_STATS_RECV_PACKETS),
__TC_STR(SK_STATS_RECV_BYTES),

// WIFI热点流量统计
__TC_STR(WIFI_STATS_CALLED),
__TC_STR(WIFI_STATS_FAIL),
__TC_STR(WIFI_STATS_BYTES),
__TC_STR(WIFI_STATS_PACKETS_FAIL_NF_RREROUTEING),
__TC_STR(WIFI_STATS_BYTES_FAIL_NF_RREROUTEING),
__TC_STR(WIFI_STATS_PACKETS_FAIL_NF_FWD),
__TC_STR(WIFI_STATS_BYTES_FAIL_NF_FWD),
__TC_STR(WIFI_STATS_PACKETS_FAIL_NF_POSTOUTEING),
__TC_STR(WIFI_STATS_BYTES_FAIL_NF_POSTOUTEING),


// WIFI热点CCORE流量统计
__TC_STR(WIFI_CCORE_STATS_CALLED),
__TC_STR(WIFI_CCORE_STATS_MSG),
__TC_STR(WIFI_CCORE_STATS_FAIL),
__TC_STR(WIFI_CCORE_STATS_ITEM),
__TC_STR(WIFI_CCORE_STATS_ITEM_FAIL),
__TC_STR(WIFI_CCORE_STATS_PACKETS),
__TC_STR(WIFI_CCORE_STATS_BYTES),

// WIFI热点DCORE流量统计
__TC_STR(WIFI_DCORE_STATS_CALLED),
__TC_STR(WIFI_DCORE_STATS_MSG),
__TC_STR(WIFI_DCORE_STATS_ITEM),
__TC_STR(WIFI_DCORE_STATS_ITEM_FAIL),
__TC_STR(WIFI_DCORE_STATS_PACKETS),
__TC_STR(WIFI_DCORE_STATS_BYTES),

// other
__TC_STR(PTYPE_IF_STATS_CALLED),
__TC_STR(PTYPE_IF_STATS_PACKETS),
__TC_STR(PTYPE_IF_STATS_BYTES),

__TC_STR(ALLOC_SKB_FAIL_KMALLOC),
__TC_STR(ALLOC_SKB_FAIL_PARA),

__TC_STR(IPV4_DST_CREATE_FAIL),
__TC_STR(IPV6_DST_CREATE_FAIL)
};

int dpa_tc_statistics_show(void)
{
    int index;
    for (index = 0; index < MAX_STATS_NUM; index++){
        TC_PRINT_ERR("%s:%u\n", g_dpa_tc_statistics_str[index], atomic_read(&g_dpa_tc_statistics[index]));
    }

    return 0;
}
EXPORT_SYMBOL(dpa_tc_statistics_show);

// MAP打印处理

typedef void (*bpf_map_print)(char *name, char *key, char *value);
typedef struct {
    struct bpf_map *pmap;
    int enum_value;
    char name[MAX_MAP_NAME_LEN];
    bpf_map_print print_cb;
} bpf_map_test;

typedef struct {
    unsigned int uId;
    unsigned int ifIndex;
    unsigned int ifType;
} stats_key;
 

typedef struct {
    unsigned long long rxPackets;
    unsigned long long rxBytes;
    unsigned long long txPackets;
    unsigned long long txBytes;
} stats_value;

// network stats
typedef unsigned long long iface_stats_key;
typedef stats_value iface_stats_value;

typedef unsigned long long app_uid_stats_key;
typedef stats_value app_uid_stats_value;

/*For bpf map print*/
static void bpf_map_print_stats(char *name, char *key, char *value)
{
    iface_stats_key *k = (iface_stats_key *)key;
    stats_value *s = (stats_value *)value;
    if (!key)
        return;

    if (!value) {
        TC_PRINT_ERR("%s \t:KEY:%llu VALUE notfind!\n", name? name:"<NULL>", *k);
        return;
    }
    TC_PRINT_INFO("%s \t:KEY:%llu VALUE: rxp %llu rxb %llu txp %llu txb %llu \n",
        name? name:"<NULL>",
        *k,
        s->rxPackets,
        s->rxBytes,
        s->txPackets,
        s->txBytes);
    return;
}
static void bpf_map_print_uid_ifstats(char *name, char *key, char *value)
{
    stats_key *k = (stats_key *)key;
    stats_value *s = (stats_value *)value;
    if (!key)
        return;

    if (!value) {
        TC_PRINT_ERR("%s \t:KEY:%u %u VALUE notfind!\n", name? name:"<NULL>", k->uId, k->ifIndex);
        return;
    }
    TC_PRINT_INFO("%s \t:KEY:%u %u VALUE: rxp %llu rxb %llu txp %llu txb %llu \n",
        name? name:"<NULL>",
        k->uId,
        k->ifIndex,
        s->rxPackets,
        s->rxBytes,
        s->txPackets,
        s->txBytes);
    return;
}
enum { 
    BPF_PRINT_IFSTATS = 0, 
    BPF_PRINT_UIDSTATS, 
    BPF_PRINT_UID_IFSTATS, 
    BPF_PRINT_MAX 
    };

static bpf_map_test g_map_test[] = {
    {NULL, BPF_PRINT_IFSTATS, "/sys/fs/bpf/netsys/maps/iface_stats_map", bpf_map_print_stats},
    {NULL, BPF_PRINT_UIDSTATS, "/sys/fs/bpf/netsys/maps/app_uid_stats_map", bpf_map_print_stats},
    {NULL, BPF_PRINT_UID_IFSTATS, "/sys/fs/bpf/netsys/maps/app_uid_if_stats_map", bpf_map_print_uid_ifstats}
    };

static unsigned long long test_bpf_get_socket_uid(struct sk_buff *skb)
{
    struct sock *sk;
    kuid_t kuid;

    if (!skb)
        return overflowuid;

    sk = sk_to_full_sk(skb->sk);
    if (!sk || !sk_fullsock(sk))
        return overflowuid;
    kuid = sock_net_uid(sock_net(sk), sk);
    return from_kuid_munged(sock_net(sk)->user_ns, kuid);
}

static void bpf_map_print_one(int index, char *k)
{
    char *value = NULL;
    if (index < 0 || index >= BPF_PRINT_MAX) {
        TC_PRINT_ERR("index overflow %d\n", index);
        return;
    }

    if (k == NULL) {
        TC_PRINT_ERR("inpu key is null\n");
        return;
    }

    if (g_map_test[index].print_cb == NULL ) {
        TC_PRINT_ERR("g_map_test error, print cb is null\n");
        return;
    }
    if (g_map_test[index].pmap == NULL) {
        TC_PRINT_ERR("g_map_test error, map is null\n");
        return;
    }

    // assert linux kernel pmap->ops is not null
    value = g_map_test[index].pmap->ops->map_lookup_elem(g_map_test[index].pmap, k);
    g_map_test[index].print_cb(g_map_test[index].name, k, value);
    return;
}

void tc_save_map(struct bpf_map *uid_map, const char *pathname, int len)
{
    int i;
    if (uid_map && pathname) {

        for (i = 0; i < sizeof(g_map_test) / sizeof(bpf_map_test); i++) {
            if (strnstr(pathname, g_map_test[i].name, len) != NULL) {
                TC_PRINT_DEBUG("BPF MAP match %s ok \n", pathname);
                g_map_test[i].pmap = uid_map;
                break;
            }
        }
    }
}


void tc_print_cgroupstats(struct sk_buff *skb)
{
    if (skb && skb->dev) {
        unsigned long long key = test_bpf_get_socket_uid(skb);
        bpf_map_print_one(BPF_PRINT_UIDSTATS, (char *)&key);
    }
    if (skb && skb->dev) {
        stats_key key = {0};
        key.uId = test_bpf_get_socket_uid(skb);
        key.ifIndex = skb->dev->ifindex;
        bpf_map_print_one(BPF_PRINT_UID_IFSTATS, (char *)&key);
    }
}
void tc_print_ifstats(struct sk_buff *skb)
{
    if (skb && skb->dev) {
        unsigned long long key = skb->dev->ifindex;
        bpf_map_print_one(BPF_PRINT_IFSTATS, (char *)&key);
    }
}

// SKB打印处理
void tc_print_skb(char *prefix, struct sk_buff *skb)
{
    if (skb) {
        TC_PRINT_INFO("[DPA_TC]DUMP_SKB:%s, len:%d, offset %lu, tail:%lu, end:%lu, dev:%s, mac hd %d, net hd %d, trans hd %d,rtdst %lu,"\
               "IP Vesion %u, len %u, gso_segs %d\n",
            prefix ? prefix : "<NULL>",
            skb->len,
            skb->data - skb->head,
            (unsigned long)skb->tail,
            (unsigned long)skb->end,
            skb->dev ? skb->dev->name : "<NULL>",
            skb->mac_header,
            skb->network_header,
            skb->transport_header,
            skb->_skb_refdst,
            ip_hdr(skb)->version,
            ip_hdr(skb)->version==4 ? ntohs(ip_hdr(skb)->tot_len):ntohs(ipv6_hdr(skb)->payload_len),
            skb_shinfo(skb)->gso_segs
            );
    }
}

