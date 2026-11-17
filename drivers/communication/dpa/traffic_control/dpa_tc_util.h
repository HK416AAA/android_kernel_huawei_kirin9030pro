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

#ifndef DPA_TC_UTIL_H_
#define DPA_TC_UTIL_H_

#include <linux/skbuff.h>
#include <linux/bpf.h>
#include <net/sock.h>
#include <linux/atomic.h>

#include "bsp_print.h"

#define MAX_MAP_NAME_LEN (512)

// TC打印信息控制
extern int g_dpa_tc_print;

void tc_save_map(struct bpf_map *uid_map, const char *pathname, int len);
void tc_print_skb(char *prefix, struct sk_buff *skb);
void tc_print_ifstats(struct sk_buff *skb);
void tc_print_cgroupstats(struct sk_buff *skb);
int dpa_tc_print_enable(int mask);
int dpa_tc_print_show(void);

#define PTR_IS_NULL(p) ((p)?"is not null":"is null")
#define SKB_UID(skb) ((sock_net_uid(sock_net((skb)->sk), (skb)->sk)).val)
#define SK_UID(sk) ((sock_net_uid(sock_net(sk), (sk))).val)

#define WARN_MASK 0x1
#define DEBUG_MASK 0x2
#define SKB_MASK 0x4
#define CGROUP_MASK 0x8
#define IFSTAT_MASK 0x10

#define TC_PRINT_FATAL(FMT, ...)  dpa_pr_fatal("[DPA_TC][%s %d]"FMT, __func__, __LINE__, ##__VA_ARGS__)
#define TC_PRINT_ERR(FMT, ...)  dpa_pr_err("[DPA_TC][%s %d]"FMT, __func__, __LINE__, ##__VA_ARGS__)
#define TC_PRINT_INFO(FMT, ...)  dpa_pr_info("[DPA_TC][%s %d]"FMT, __func__, __LINE__, ##__VA_ARGS__)

#define TC_PRINT_WARN(FMT, ...)           \
    do {                              \
        if (unlikely(g_dpa_tc_print&WARN_MASK)) \
            dpa_pr_wrn("[DPA_TC][%s %d]"FMT, __func__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define TC_PRINT_DEBUG(FMT, ...)           \
    do {                              \
        if (unlikely(g_dpa_tc_print&DEBUG_MASK)) \
            dpa_pr_info("[DPA_TC][%s %d]"FMT, __func__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define TC_PRINT_SKB(prefix, skb)          \
    do {                                   \
        if (unlikely(g_dpa_tc_print&SKB_MASK))      \
            tc_print_skb((prefix), (skb)); \
    } while (0)

#define TC_PRINT_IFSTAT(skb)          \
    do {                              \
        if (unlikely(g_dpa_tc_print&IFSTAT_MASK)) \
            tc_print_ifstats(skb);    \
    } while (0)

#define TC_PRINT_CGROUP(skb)           \
    do {                               \
        if (unlikely(g_dpa_tc_print&CGROUP_MASK))  \
            tc_print_cgroupstats(skb); \
    } while (0)

// TC功能控制
extern int g_dpa_tc_func;
#define SKB_INGRESS_MASK 0x1
#define SKB_EGRESS_MASK 0x2
#define SK_UDP_BPF_MASK 0x4
#define SK_STATS_MASK 0x8
#define WIFI_STATS_MASK 0x10

#define IS_SKB_INGRESS_DISABLE (g_dpa_tc_func&SKB_INGRESS_MASK)
#define IS_SKB_EGRESS_DISABLE (g_dpa_tc_func&SKB_EGRESS_MASK)
#define IS_SK_UDP_BPF_DISABLE (g_dpa_tc_func&SK_UDP_BPF_MASK)
#define IS_SK_STATS_DISABLE (g_dpa_tc_func&SK_STATS_MASK)
#define IS_WIFI_STATS_DISABLE (g_dpa_tc_func&WIFI_STATS_MASK)

int dpa_tc_func_disable(int mask);
int dpa_tc_func_show(void);

/* TC统计数据
   注意：1) 此处的增删修改后，需要更新TC_STATS_VER，HIDIS上报会携带该值，用于指示上报的数据版本;
        2) 当MAX_STATS_NUM超过100后，需要更新HIDIS的数组长度
 */
#define TC_STATS_VER "v1.0.0"
enum {
    // 卸载白名单应用收包统计
    SKB_INGRESS_CALLED = 0,
    SKB_INGRESS_PACKETS,
    SKB_INGRESS_BYTES,
    SKB_INGRESS_PACKETS_FAIL_CGROUP,
    SKB_INGRESS_BYTES_FAIL_CGROUP,
    SKB_INGRESS_PACKETS_FAIL_NF_LOCAL_IN,
    SKB_INGRESS_BYTES_FAIL_NF_LOCAL_IN,
    SKB_INGRESS_PACKETS_FAIL_NF_PREROUTEING,
    SKB_INGRESS_BYTES_FAIL_NF_PREROUTEING,
    SKB_INGRESS_SEGS,

    // 卸载白名单应用发包统计
    SKB_EGRESS_CALLED,
    SKB_EGRESS_PACKETS,
    SKB_EGRESS_BYTES,
    SKB_EGRESS_PACKETS_FAIL_CGROUP,
    SKB_EGRESS_BYTES_FAIL_CGROUP,
    SKB_EGRESS_PACKETS_FAIL_NF_LOCAL_OUT,
    SKB_EGRESS_BYTES_FAIL_NF_LOCAL_OUT,
    SKB_EGRESS_PACKETS_FAIL_NF_POSTOUTEING,
    SKB_EGRESS_BYTES_FAIL_NF_POSTOUTEING,
    SKB_EGRESS_SEGS,
    
    // 卸载白名单应用UDP发包统计
    SK_UDP_SEND_BPF_CALLED,
    SK_UDP_SEND_BPF_FAIL,

    // 直通应用Socket流量统计
    SK_STATS_CALLED,
    SK_STATS_MSG,
    SK_STATS_MSG_ITEM,
    SK_STATS_MSG_ITEM_FAIL_IFINDEX,
    SK_STATS_MSG_ITEM_FAIL_CREATE_DST,
    SK_STATS_SEND_PACKETS,
    SK_STATS_SEND_BYTES,
    SK_STATS_RECV_PACKETS,
    SK_STATS_RECV_BYTES,

    // WIFI热点流量统计
    WIFI_STATS_CALLED,
    WIFI_STATS_FAIL,
    WIFI_STATS_BYTES,
    WIFI_STATS_PACKETS_FAIL_NF_RREROUTEING,
    WIFI_STATS_BYTES_FAIL_NF_RREROUTEING,
    WIFI_STATS_PACKETS_FAIL_NF_FWD,
    WIFI_STATS_BYTES_FAIL_NF_FWD,
    WIFI_STATS_PACKETS_FAIL_NF_POSTOUTEING,
    WIFI_STATS_BYTES_FAIL_NF_POSTOUTEING,

    // WIFI热点CCORE流量统计
    WIFI_CCORE_STATS_CALLED,
    WIFI_CCORE_STATS_MSG,
    WIFI_CCORE_STATS_FAIL,
    WIFI_CCORE_STATS_ITEM,
    WIFI_CCORE_STATS_ITEM_FAIL,
    WIFI_CCORE_STATS_PACKETS,
    WIFI_CCORE_STATS_BYTES,

    // WIFI热点DCORE流量统计
    WIFI_DCORE_STATS_CALLED,
    WIFI_DCORE_STATS_MSG,
    WIFI_DCORE_STATS_ITEM,
    WIFI_DCORE_STATS_ITEM_FAIL,
    WIFI_DCORE_STATS_PACKETS,
    WIFI_DCORE_STATS_BYTES,

    // other
    PTYPE_IF_STATS_CALLED,
    PTYPE_IF_STATS_PACKETS,
    PTYPE_IF_STATS_BYTES,

    ALLOC_SKB_FAIL_KMALLOC,
    ALLOC_SKB_FAIL_PARA,

    IPV4_DST_CREATE_FAIL,
    IPV6_DST_CREATE_FAIL,

    MAX_STATS_NUM
};

#define MAX_STR_SIZE (256)

extern atomic_t g_dpa_tc_statistics[MAX_STATS_NUM];
extern unsigned char g_dpa_tc_statistics_str[MAX_STATS_NUM][MAX_STR_SIZE];

#define TC_STATS_INC(type, num) atomic_add((num), &g_dpa_tc_statistics[(type)])
int dpa_tc_statistics_reset(void);
int dpa_tc_statistics_show(void);

#endif /* DPA_TC_UTIL_H_ */
