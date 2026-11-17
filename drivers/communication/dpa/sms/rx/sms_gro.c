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
 *
 */

#include <linux/workqueue.h>
#include <linux/slab.h>
#include <asm/page.h>
#include <asm/barrier.h>
#include <linux/skbuff.h>
#include <linux/printk.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <net/ip6_checksum.h>
#include <net/net_namespace.h>
#include <net/netfilter/nf_conntrack_tuple.h>
#include <net/ipv6.h>
#include <net/udp.h>
#include <net/checksum.h>
#include <securec.h>
#include "bsp_dump.h"
#include "bsp_dpa_net_om.h"
#include "bsp_print.h"
#include "bsp_sms.h"
#include "bsp_dra.h"
#include "sms_gro.h"

#define SMS_GRO_MSG_POOL_SIZE             1024                        /* must 2^n for mask */
#define SMS_GRO_MSG_POOL_MASK             (SMS_GRO_MSG_POOL_SIZE - 1)
#define SMS_GRO_MSG_POS_ADD(prod, value)    ((prod) = ((prod) + (value)) & (SMS_GRO_MSG_POOL_MASK))
#define SMS_GRO_MSG_POOL_FULL(prod, cons)   ((((prod) + 1) & (SMS_GRO_MSG_POOL_MASK)) == (cons))
#define SMS_GRO_MSG_POOL_EMPTY(prod, cons)  ((prod) == (cons))

#define SMS_GRO_DRA_DATA_TRUE_SZ        (PAGE_SIZE >> 1)
#define SMS_GRO_PAGE_OFFSET(addr)       ((addr) & (PAGE_SIZE - 1))

#define SMS_GRO_MSG_ALIGN(addr, boundary) (((uintptr_t)(addr) + (boundary) - 1) & ~((uintptr_t)(boundary) - 1))
#define SMS_GRO_WLAN_MAX_PKT_DELIV      128
#define SMS_GRO_IS_OVER_LEN(len) ((len) > DRA_OPIPE_LEVEL_1_SIZE)


struct sms_host_rx_debug_info {
    unsigned int dra_unmap_fail;
    unsigned int nic_type_err;
    unsigned int rx_pkt_cnt;
    unsigned int rx_blk_cnt;
    unsigned int rx_msg_cnt;
    unsigned int rx_msg_sync_cnt;
    unsigned int proc_msg_cnt;
    unsigned long long rx_pkt_sz;
    unsigned int msg_pool_full;
    unsigned int msg_len_err;
    unsigned int first_cnt;
    unsigned int flist_cnt;
    unsigned int frags_cnt;
    unsigned int last_usr_len;
    unsigned int drop_pkt;
    unsigned int msg_free;
    unsigned int over_len_pkt;
    unsigned int over_len_no_gro;
};

struct sms_gro_deliv_ctx {
    struct sk_buff* deliv_skb_head;
    struct sk_buff* cur_skb;
    unsigned int cur_pkt_cnt;
    void* usr_data;
    unsigned int usr_offset;
    unsigned int usr_len;
};

struct sms_gro_ctx {
    struct dmi_client dmi_handler;

    struct dmi_msg_data* deliv_msg_pool[SMS_GRO_MSG_POOL_SIZE];
    unsigned int deliv_prod;
    unsigned int deliv_cons;

    struct sms_gro_deliv_ctx deliv_ctx[DPA_SMS_NIC_END];
    struct dpa_sms_rx_callback_s rx_cb[DPA_SMS_NIC_END];
    struct net_om_info net_om_info;
    
    /* debug info */
    struct sms_host_rx_debug_info debug_info;
};

struct sms_gro_ctx g_sms_gro_ctx = {0};

static void sms_gro_deliv_work(struct sms_gro_ctx* ctx, bool free_msg);
static void sms_gro_deliver_all(struct sms_gro_ctx* ctx, struct gro_deliv_msg* msg);
void sms_gro_dump_skb(char* tag, struct sk_buff *skb);


static void sms_gro_free_all_data(struct sms_gro_ctx* ctx, struct gro_deliv_msg* msg)
{
    unsigned int i;
    
    for (i = 0; i < msg->deliv_hdr.blk_num; i++) {
        struct gro_deliv_blk* one_blk = &msg->blks[i];
        if (unlikely(one_blk->fake_addr)) {
            continue;
        }
        ctx->debug_info.drop_pkt++;
        bsp_dra_free(one_blk->data);
    }
}

static inline void sms_gro_free_skb_list(struct sms_gro_ctx* ctx, struct sk_buff *skb)
{
    struct sk_buff *cur_skb = skb;
    struct sk_buff *free_skb;

    while(cur_skb != NULL) {
        free_skb = cur_skb;
        cur_skb = cur_skb->next;
        free_skb->next = NULL;
        free_skb->prev = NULL;
        ctx->debug_info.drop_pkt++;
        dev_kfree_skb_any(free_skb);
    }
}

static void sms_gro_proc_deliv_msg(struct sms_gro_ctx* ctx, struct dmi_msg_data *msg, bool free_msg)
{
    struct gro_deliv_msg* deliv_msg = (struct gro_deliv_msg*)msg->buf;
    unsigned int prod = ctx->deliv_prod;
    unsigned int cons = ctx->deliv_cons;
    int msg_len = SMS_GRO_MSG_ALIGN(sizeof(struct gro_deliv_hdr) + 
                  deliv_msg->deliv_hdr.blk_num * sizeof(struct gro_deliv_blk), 4);

    if (unlikely(msg_len != msg->len)) {
        ctx->debug_info.msg_len_err++;
        goto deliv_fail;
    }

    if (unlikely(SMS_GRO_MSG_POOL_FULL(prod, cons))) {
        ctx->debug_info.msg_pool_full++;
        goto deliv_fail;
    }

    ctx->deliv_msg_pool[prod] = msg;
    mb();

    SMS_GRO_MSG_POS_ADD(prod, 1);
    ctx->deliv_prod = prod;
    return;

deliv_fail:
    sms_gro_free_all_data(ctx, deliv_msg);
    if (free_msg) {
        ctx->debug_info.msg_free++;
        bsp_dmi_msg_free(msg);
    }
    return;
}

static inline void sms_gro_restore_skb_base(struct sk_buff* skb, void* data, unsigned short len)
{
    skb->data = data;
    skb->len = 0;
    skb_reset_tail_pointer(skb);
    skb_put(skb, len);
}

static int sms_gro_proc_rx_cb(char *priv, unsigned int sub_id, struct dmi_msg_data *msg)
{
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;

    ctx->debug_info.rx_msg_cnt++;
    if (unlikely(msg == NULL || msg->len <= sizeof(struct gro_deliv_hdr))) {
        ctx->debug_info.msg_len_err++;
        return -1;
    }
    sms_gro_proc_deliv_msg(ctx, msg, true);
    sms_gro_deliv_work(ctx, true);
    return 0;
}

static void sms_gro_proc_rx_sync_cb(void *priv, unsigned int sub_id, struct dmi_msg_data *msg)
{
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;
    struct gro_deliv_msg* deliv_msg;

    ctx->debug_info.rx_msg_sync_cnt++;
    if (unlikely(msg == NULL || msg->len <= sizeof(struct gro_deliv_hdr))) {
        ctx->debug_info.msg_len_err++;
        return;
    }
    deliv_msg = (struct gro_deliv_msg*)msg->buf;
    sms_gro_deliver_all(ctx, deliv_msg);
    return;
}

static inline struct sk_buff* sms_gro_build_new_skb(struct sk_buff* dra_skb)
{
    struct sk_buff *skb_new;

    skb_new = build_skb((void *)dra_skb->head, dra_skb->end + SKB_DATA_ALIGN(sizeof(struct skb_shared_info)));
    if (unlikely(skb_new == NULL)) {
        return NULL;
    }
    sms_gro_restore_skb_base(skb_new, dra_skb->data, dra_skb->len);
    return skb_new;
}

static struct sk_buff* sms_gro_build_skb(struct sk_buff* dra_skb, unsigned int offset, 
                       struct gro_deliv_msg* msg, int is_frag, int is_csum)
{
    struct sk_buff *skb_new;
    unsigned int pull_len = is_frag ? offset : 0;

    skb_new = sms_gro_build_new_skb(dra_skb);
    if (unlikely(skb_new == NULL)) {
        return NULL;
    }
    skb_new->skb_iif = msg->deliv_hdr.ifindex;
    if (likely(is_csum)) {
        skb_new->ip_summed = CHECKSUM_UNNECESSARY;
        skb_new->csum_level = 0;
    }

    skb_set_mac_header(skb_new, 0);
    skb_set_network_header(skb_new, ETH_HLEN);

    if (msg->deliv_hdr.deliv_info.is_valid) {
        skb_new->protocol = msg->deliv_hdr.deliv_info.is_ipv4 ? htons(ETH_P_IP) : htons(ETH_P_IPV6);
        __skb_pull(skb_new, pull_len);
    } else {
        struct iphdr* iph; /* ipv4/v6 hdr has the same ver offset*/
        iph = (struct iphdr*)(skb_new->data + ETH_HLEN);
        skb_new->protocol = (iph->version == 0x4) ? htons(ETH_P_IP) : htons(ETH_P_IPV6);
    }

    return skb_new;
}

static inline void sms_gro_merge_skb_end(struct sk_buff* first, struct sk_buff* end_frag)
{
    if (end_frag != NULL) {
        first->len += end_frag->len;
        first->data_len += end_frag->len;
        first->truesize += end_frag->truesize;
    }
}

static inline void sms_gro_merge_skb_list(struct sk_buff* first, struct sk_buff** frag_list, 
       struct sk_buff* dra_skb, struct sk_buff* frag_skb, unsigned int offset, struct gro_deliv_msg* msg)
{
    struct sk_buff* skb_new;
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;

    skb_new = sms_gro_build_skb(dra_skb, offset, msg, 1, 1);
    if (unlikely(!skb_new)) {
        ctx->debug_info.drop_pkt++;
        put_page(virt_to_page(dra_skb->head));
        return;
    }

    if (*frag_list == NULL) {
        skb_shinfo(first)->frag_list = skb_new;
        *frag_list = skb_new;
    } else {
        (*frag_list)->next = skb_new;
        *frag_list = skb_new;
    }

    if (frag_skb != NULL) {
        if (first != frag_skb) {
            first->len += frag_skb->len;
            first->data_len += frag_skb->len;
            first->truesize += frag_skb->truesize;
        }
    } else {
        first->len += skb_new->len;
        first->data_len += skb_new->len;
        first->truesize += skb_new->truesize;
    }
}

static void sms_gro_merge_skb_frags(struct sk_buff* first, 
    struct sk_buff** frag_list, struct sk_buff* dra_skb, unsigned int offset, struct gro_deliv_msg* msg)
{
    struct sk_buff* skb_frag;

    if (*frag_list == NULL) {
        skb_frag = first;
    } else {
        skb_frag = *frag_list;
    }

    if (unlikely(skb_shinfo(skb_frag)->nr_frags >= MAX_SKB_FRAGS)) {
        sms_gro_merge_skb_list(first, frag_list, dra_skb, skb_frag, offset, msg);
        return;
    }

    __skb_pull(dra_skb, offset);
    skb_add_rx_frag(skb_frag, skb_shinfo(skb_frag)->nr_frags,
        virt_to_page(dra_skb->head),
        SMS_GRO_PAGE_OFFSET((uintptr_t)(dra_skb->data)),
        dra_skb->len, SMS_GRO_DRA_DATA_TRUE_SZ);
}

static void sms_gro_rebuild_iphdr(struct sk_buff *skb, struct gro_deliv_msg* msg)
{
    struct iphdr *ip4h = (struct iphdr *)(skb->data + ETH_HLEN);
    struct tcphdr *th;
    struct udphdr *uh;
    unsigned int iphdr_len = sizeof(struct iphdr);
    unsigned int data_len = skb->len - ETH_HLEN;
    __be16 newlen;

    newlen = htons(skb->len - ETH_HLEN);
    csum_replace2(&ip4h->check, ip4h->tot_len, newlen);
    ip4h->tot_len = newlen;

    switch (ip4h->protocol) {
    case IPPROTO_TCP:
        th = (struct tcphdr *)(ip4h + 1);
        th->check = ~csum_tcpudp_magic(ip4h->saddr, ip4h->daddr,
            data_len - iphdr_len, IPPROTO_TCP, 0);
        skb->csum_start = (__u16)((unsigned char *)th - skb->head);
        skb->csum_offset = offsetof(struct tcphdr, check);
        skb->ip_summed = CHECKSUM_PARTIAL;
        tcp_flag_word(th) |= msg->deliv_hdr.deliv_info.tcp_flags;
        break;

    case IPPROTO_UDP:
        uh = (struct udphdr *)(ip4h + 1);
        uh->len = htons(data_len - iphdr_len);
        if (uh->check) {
            uh->check = ~csum_tcpudp_magic(ip4h->saddr, ip4h->daddr,
                data_len - iphdr_len, IPPROTO_UDP, 0);
        }
        skb->csum_start = (unsigned char *)uh - skb->head;
        skb->csum_offset = offsetof(struct udphdr, check);
        skb->ip_summed = CHECKSUM_PARTIAL;
        break;

    default:
        return;
    }
}

static void sms_gro_rebuild_ipv6hdr(struct sk_buff *skb, struct gro_deliv_msg* msg)
{
    struct ipv6hdr *ip6h = (struct ipv6hdr *)(skb->data + ETH_HLEN);
    struct tcphdr *th;
    struct udphdr *uh;
    unsigned int iphdr_len = sizeof(struct ipv6hdr);
    unsigned int data_len = skb->len - ETH_HLEN;

    ip6h->payload_len = htons(data_len - iphdr_len);

    switch (ip6h->nexthdr) {
    case IPPROTO_TCP:
        th = (struct tcphdr *)(ip6h + 1);
        th->check = ~tcp_v6_check((int)(data_len - iphdr_len),
            &ip6h->saddr, &ip6h->daddr, 0);
        skb->csum_start = (__u16)((unsigned char *)th - skb->head);
        skb->csum_offset = offsetof(struct tcphdr, check);
        skb->ip_summed = CHECKSUM_PARTIAL;
        tcp_flag_word(th) |= msg->deliv_hdr.deliv_info.tcp_flags;
        break;

    case IPPROTO_UDP:
        uh = (struct udphdr *)(ip6h + 1);
        uh->len = htons(data_len - iphdr_len);
        if (uh->check) {
            uh->check = ~csum_ipv6_magic(&ip6h->saddr, &ip6h->daddr,
                data_len - iphdr_len, IPPROTO_UDP, 0);
        }
        skb->csum_start = (unsigned char *)uh - skb->head;
        skb->csum_offset = offsetof(struct udphdr, check);
        skb->ip_summed = CHECKSUM_PARTIAL;
        break;

    default:
        return;
    }
}

static void sms_gro_rebuild_skb_hdr(struct sk_buff *skb, struct gro_deliv_msg* msg)
{
    if (msg->deliv_hdr.deliv_info.is_ipv4) {
        sms_gro_rebuild_iphdr(skb, msg);
    } else {
        sms_gro_rebuild_ipv6hdr(skb, msg);
    }
}

static void sms_gro_rebuild_shareinfo(struct sk_buff *skb, 
    struct gro_deliv_msg* msg, unsigned int frag_num, bool flist)
{
    skb_shinfo(skb)->gso_size = msg->deliv_hdr.deliv_info.seg_size;
    skb_shinfo(skb)->gso_segs = frag_num;

    if (!msg->deliv_hdr.deliv_info.is_tcp) {
        skb_shinfo(skb)->gso_type = SKB_GSO_UDP_L4;
    } else {
        if (msg->deliv_hdr.deliv_info.is_ipv4) {
            skb_shinfo(skb)->gso_type = SKB_GSO_TCPV4;
        } else {
            skb_shinfo(skb)->gso_type = SKB_GSO_TCPV6;
        }
    }

    if (flist) {
        skb_shinfo(skb)->gso_type |= SKB_GSO_FRAGLIST;
    }
}

static inline void sms_gro_prepare_deliver_skb(struct sms_gro_ctx* ctx, struct dpa_sms_rx_callback_s* rx_cb,
    struct sk_buff** cur, struct sk_buff* skb, struct gro_deliv_msg* msg, unsigned int frag_num, bool flist)
{
    if (unlikely(skb->len < skb->data_len)) {
        sms_gro_dump_skb("skb_bug", skb);
        dpa_system_error(DRV_ERRNO_SMS_GRO, skb->len, skb->data_len, (char*)skb, sizeof(struct sk_buff));
        return;
    }
    
    /* rebuild skb hdr */
    if (frag_num > 1) {
        sms_gro_rebuild_skb_hdr(skb, msg);
        sms_gro_rebuild_shareinfo(skb, msg, frag_num, flist);
    }

    ctx->debug_info.rx_blk_cnt++;
    ctx->debug_info.rx_pkt_sz += skb->len;

    /* add to deliver list */
    if (*cur != NULL) {
        (*cur)->next = skb;
    }
    *cur = skb;
    skb->next = NULL;
}

static void sms_gro_deliver_skb_list(struct sms_gro_ctx* ctx, struct dpa_sms_rx_callback_s* rx_cb, 
    struct sk_buff* skb_header, struct gro_deliv_msg* msg)
{
    if (unlikely(skb_header == NULL)) {
        return;
    }
    ctx->debug_info.last_usr_len = msg->deliv_hdr.deliv_info.usr_msg_len;
    if (rx_cb->rx) {
        rx_cb->rx(skb_header, (void*)msg->deliv_hdr.deliv_info.usr_msg);
    } else {
        sms_gro_free_skb_list(ctx, skb_header);
    }
}

static struct sock *sms_gro_udp_lookup_sock(struct sk_buff *skb, struct gro_deliv_msg* msg)
{
	struct udphdr *uh;
    struct sock* ret;
    struct net_device *dev = dev_get_by_index(&init_net, skb->skb_iif);

    if (unlikely(dev == NULL)) {
        return NULL;
    }
    skb->dev = dev;
    if (msg->deliv_hdr.deliv_info.is_ipv4) {
        struct iphdr* iph = (struct iphdr*)(skb->data + ETH_HLEN);
        uh = (struct udphdr*)(iph + 1); /* just support no ext iph in gro */
        ret = udp4_lib_lookup_skb(skb, uh->source, uh->dest);
    } else {
        struct ipv6hdr* ip6h = (struct ipv6hdr*)(skb->data + ETH_HLEN);
        uh = (struct udphdr*)(ip6h + 1); /* just support no ext iph in gro */
        ret = udp6_lib_lookup_skb(skb, uh->source, uh->dest);
    }
    skb->dev = NULL;
    dev_put(dev);
    return ret;
}

static bool sms_gro_can_merge(struct sk_buff *skb, struct gro_deliv_msg* msg, bool* flist)
{
	struct sock *sk;

    /* don't merge over len pkt to the blk */
    if (unlikely(SMS_GRO_IS_OVER_LEN(skb->len))) {
        return false;
    }
    
    if (msg->deliv_hdr.deliv_info.is_tcp) {
        return true;
    }

    /* default use flist for udp */
    *flist = true;

    if (static_branch_unlikely(&udp_encap_needed_key)) {
    	rcu_read_lock();
    	sk = sms_gro_udp_lookup_sock(skb, msg);
    	if (sk) {
    		if (udp_sk(sk)->gro_receive) {
    			rcu_read_unlock();
    			return false;
    		}

    		if (udp_sk(sk)->gro_enabled) {
    			*flist = false;
    		}
    	}
    	rcu_read_unlock();
    }

    /* default use flist for udp gro, ref to udp_gro_receive in udp_offload.c */
	return true;
}

static int dpa_sms_gro_unmap_free_dra(struct sms_gro_ctx* ctx, unsigned long long dra_addr)
{
    unsigned long long org_dra;
    struct sk_buff *dra_skb = NULL;

    /* unmap for dra_clear_tab_info */
    dra_skb = bsp_dra_unmap_reuse(dra_addr, &org_dra);
    if (unlikely(dra_skb == NULL)) {
        dpa_pr_fatal("gro bsp_dra_to_skb failed\n");
        ctx->debug_info.dra_unmap_fail++;
        return -1;
    }
    /* free org page of dra */
    put_page(virt_to_page(dra_skb->head));
    return 0;
}

static struct sk_buff* dpa_sms_build_over_len_pkt(struct sms_gro_ctx* ctx, 
    unsigned long long dra_addr, unsigned int len)
{
    struct sk_buff *skb = NULL;

    skb = dev_alloc_skb(len);
    if (skb == NULL) {
        ctx->debug_info.drop_pkt++;
        goto build_ret;
    }
    skb_put(skb, len);
    bsp_dra_dma_unmap_single((dma_addr_t)bsp_dra_to_phy(dra_addr), len, DMA_FROM_DEVICE);
    if (memcpy_s(skb->data, skb->len, phys_to_virt(bsp_dra_to_phy(dra_addr)), len)) {
        dpa_pr_fatal("gro skb copy failed\n");
        goto build_ret;
    }
    ctx->debug_info.over_len_pkt++;
    
build_ret:
    if (dpa_sms_gro_unmap_free_dra(ctx, dra_addr)) {
        if (skb) {
            ctx->debug_info.drop_pkt++;
            dev_kfree_skb_any(skb);
        }
        return NULL;
    }
    return skb;
}

static struct sk_buff* sms_gro_get_dra_skb(struct sms_gro_ctx* ctx, unsigned long long dra_addr, unsigned int len)
{
    unsigned long long org;
    unsigned long long data_phy;
    struct sk_buff* dra_skb;

    if (unlikely(SMS_GRO_IS_OVER_LEN(len))) {
        dra_skb = dpa_sms_build_over_len_pkt(ctx, dra_addr, len);
        return dra_skb;
    }
    
    dra_skb = bsp_dra_unmap_reuse(dra_addr, &org);
    if (dra_skb == NULL) {
        dpa_pr_fatal("gro msg dra_unmap fail data: 0x%llx\n", dra_addr);
        ctx->debug_info.dra_unmap_fail++;
        return NULL;
    }

    data_phy = bsp_dra_to_phy(dra_addr);
    bsp_dra_dma_unmap_single((dma_addr_t)data_phy, len, DMA_FROM_DEVICE);
    sms_gro_restore_skb_base(dra_skb, phys_to_virt(data_phy), len);
    return dra_skb;
}


static inline int sms_gro_add_one_skb(struct sms_gro_ctx* ctx, struct gro_deliv_msg* msg, bool can_gro, bool flist,
    unsigned int* frag_num, struct dpa_sms_rx_callback_s* rx_cb, struct gro_deliv_blk* one_blk,
    struct sk_buff** first_blk, struct sk_buff** frag_list, struct sk_buff** cur_pkt)
{
    int use_next = 0;
    
    /* deliver the skb, if pkt is marked end */
    if (one_blk->pkt_end || !can_gro) {
        if (!flist) {
            sms_gro_merge_skb_end(*first_blk, *frag_list);
        }
        /* restore the tcp flags */
        if (one_blk->tcp_flags) {
            struct gro_deliv_blk* next_blk = one_blk + 1;
            unsigned int *tcp_flags = (unsigned int*)&next_blk->data;
            msg->deliv_hdr.deliv_info.tcp_flags = *tcp_flags;
            use_next = 1;
        }

        sms_gro_prepare_deliver_skb(ctx, rx_cb, cur_pkt, *first_blk, msg, *frag_num, flist);
        *first_blk = NULL;
        *frag_list = NULL;
        *frag_num = 0;
    }
    return use_next;
}

static inline int sms_gro_proc_one_skb(struct sms_gro_ctx* ctx, struct gro_deliv_msg* msg, 
    struct gro_deliv_blk* one_blk, bool* can_gro, bool* flist, unsigned int* frag_num, 
    struct sk_buff** first_blk, struct sk_buff** frag_list)
{
    struct sk_buff* dra_skb;

    if (unlikely(one_blk->len > DRA_SKB_MAX_PKT_SIZE)) {
        dpa_pr_fatal("sms_gro invalid pkt len: %d\n", one_blk->len);
        ctx->debug_info.drop_pkt++;
        bsp_dra_free(one_blk->data);
        return -1;
    }
    
    dra_skb = sms_gro_get_dra_skb(ctx, one_blk->data, one_blk->len);
    if (dra_skb == NULL) {
        return -1;
    }

    /* build skb for first pkt */
    if (*first_blk == NULL) {
        (*frag_num)++;
        if (unlikely(SMS_GRO_IS_OVER_LEN(dra_skb->len))) {
            /* over len pkt is the kernel skb */
            *first_blk = dra_skb;
        } else {
            *first_blk = sms_gro_build_skb(dra_skb, one_blk->offset, msg, 0, one_blk->is_csum);
            if ((*first_blk) == NULL) {
                ctx->debug_info.drop_pkt++;
                put_page(virt_to_page(dra_skb->head));
                return -1;
            }
            /* update seg_size for the blk */
            msg->deliv_hdr.deliv_info.seg_size = (unsigned short)(one_blk->len - one_blk->offset);
        }

        ctx->debug_info.first_cnt++;
        *can_gro = sms_gro_can_merge(*first_blk, msg, flist);
    } else {
        /* merge skb to first skb */
        (*frag_num)++;
        if (*flist) {
            ctx->debug_info.flist_cnt++;
            sms_gro_merge_skb_list(*first_blk, frag_list, dra_skb, NULL, one_blk->offset, msg);
        } else {
            ctx->debug_info.frags_cnt++;
            sms_gro_merge_skb_frags(*first_blk, frag_list, dra_skb, one_blk->offset, msg);
        }
    }
    ctx->debug_info.rx_pkt_cnt++;
    return 0;
}

static void sms_gro_proc_each_pkt(struct sms_gro_ctx* ctx, 
    struct gro_deliv_msg* msg, struct dpa_sms_rx_callback_s* rx_cb)
{
    unsigned int frag_num = 0;
    unsigned int i;
    struct sk_buff* first_blk = NULL;
    struct sk_buff* frag_list = NULL;
    struct sk_buff* pkt_header = NULL;
    struct sk_buff* cur_pkt = NULL;
    bool flist = false;
    bool can_gro = false;


    struct gro_deliv_blk* one_blk = &msg->blks[0];
    for (i = 0; i < msg->deliv_hdr.blk_num; i++) {
        if (sms_gro_proc_one_skb(ctx, msg, one_blk, &can_gro, &flist, &frag_num, &first_blk, &frag_list)) {
            continue;
        }
        if (pkt_header == NULL) {
            pkt_header = first_blk;
        }
        if (i <= msg->deliv_hdr.blk_num && SMS_GRO_IS_OVER_LEN((one_blk + 1)->len)) {
            /* if next is over len pkt, stop merge pkts */
            can_gro = 0;
            ctx->debug_info.over_len_no_gro++;
        }

        /* prepare deliver skb, if pkt is marked end */
        if (sms_gro_add_one_skb(ctx, msg, can_gro, flist, &frag_num, rx_cb, one_blk, 
            &first_blk, &frag_list, &cur_pkt)) {
            one_blk++;
            i++;
        }
        one_blk++;
    }
    sms_gro_deliver_skb_list(ctx, rx_cb, pkt_header, msg);
}

static void sms_gro_deliver_all(struct sms_gro_ctx* ctx, struct gro_deliv_msg* msg)
{
    struct dpa_sms_rx_callback_s* rx_cb;

    if (unlikely(msg->deliv_hdr.nic_type >= DPA_SMS_NIC_END || msg->deliv_hdr.blk_num > GRO_MSG_MAX_FRAGS)) {
        ctx->debug_info.nic_type_err++;
        sms_gro_free_all_data(ctx, msg);
        return;
    }
    rx_cb = &ctx->rx_cb[msg->deliv_hdr.nic_type];
    sms_gro_proc_each_pkt(ctx, msg, rx_cb);
    
    if (rx_cb->rx_complete) {
        rx_cb->rx_complete();
    }
}

static void sms_gro_deliv_work(struct sms_gro_ctx* ctx, bool free_msg)
{
    unsigned int prod = ctx->deliv_prod;
    unsigned int cons = ctx->deliv_cons;
    struct gro_deliv_msg* cur_msg;

    while (!SMS_GRO_MSG_POOL_EMPTY(prod, cons)) {
        /* get new msg */
        cur_msg = (struct gro_deliv_msg*)ctx->deliv_msg_pool[cons]->buf;

        /* build and deliver skbs */
        ctx->debug_info.proc_msg_cnt++;
        sms_gro_deliver_all(ctx, cur_msg);
        if (free_msg) {
            ctx->debug_info.msg_free++;
            bsp_dmi_msg_free(ctx->deliv_msg_pool[cons]);
        }

        /* update pord and cons */
        SMS_GRO_MSG_POS_ADD(cons, 1);
        ctx->deliv_cons = cons;
        prod = ctx->deliv_prod;
    }
}

int dpa_sms_rx_callback_register(enum dpa_sms_nic nic, struct dpa_sms_rx_callback_s* cb)
{
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;
    struct dpa_sms_rx_callback_s* rx_cb;
    
    if (nic >= DPA_SMS_NIC_END) {
        dpa_pr_fatal("dpa_sms err nic type:%d\n", nic);
        return -1;
    }
    if (cb->rx == NULL) {
        dpa_pr_fatal("dpa_sms rx_cb is NULL\n");
        return -1;
    }
    rx_cb = &ctx->rx_cb[nic];
    rx_cb->rx = cb->rx;
    rx_cb->rx_complete = cb->rx_complete;
    return 0;
}
EXPORT_SYMBOL(dpa_sms_rx_callback_register);


static inline int sms_gro_cmp_usr_data(struct sms_gro_deliv_ctx* deliv_ctx, void* usr_data)
{
    if (likely(deliv_ctx->usr_len == sizeof(unsigned int))) {
        return (*(unsigned int*)deliv_ctx->usr_data == *(unsigned int*)usr_data) ? (0) : (-1);
    } 
    return memcmp(deliv_ctx->usr_data, usr_data, deliv_ctx->usr_len);
}

static void sms_gro_wlan_pfa_deliv_list(struct sms_gro_ctx* ctx, struct sms_gro_deliv_ctx* deliv_ctx)
{
    struct dpa_sms_rx_callback_s* rx_cb = &ctx->rx_cb[DPA_SMS_NIC_WLAN];
    struct sk_buff *deliv_skb = deliv_ctx->deliv_skb_head;
    void* usr_data = deliv_ctx->usr_data;

    deliv_ctx->deliv_skb_head = NULL;
    deliv_ctx->cur_skb = NULL;
    deliv_ctx->usr_data = NULL;
    deliv_ctx->cur_pkt_cnt = 0;
    
    if (unlikely(deliv_skb == NULL)) {
        ctx->debug_info.msg_len_err++;
        return;
    }

    if (unlikely(rx_cb->rx == NULL)) {
        sms_gro_free_skb_list(ctx, deliv_skb);
        return;
    }
    ctx->debug_info.rx_blk_cnt++;
    rx_cb->rx(deliv_skb, usr_data);
}

static void dpa_sms_pfa_netif_rx(struct sms_gro_ctx* ctx, struct sms_gro_deliv_ctx* deliv_ctx, 
    struct sk_buff *skb, void *priv)
{
    void* usr_data = (void*)((char*)(skb->cb) + deliv_ctx->usr_offset);

    ctx->debug_info.rx_pkt_cnt++;
    ctx->debug_info.rx_pkt_sz += skb->len;
    ctx->debug_info.last_usr_len = deliv_ctx->usr_len;

    /* same usr data deliv in one skb list */
    if (deliv_ctx->cur_pkt_cnt >= SMS_GRO_WLAN_MAX_PKT_DELIV ||
        (deliv_ctx->usr_data != NULL && sms_gro_cmp_usr_data(deliv_ctx, usr_data) != 0)) {
        sms_gro_wlan_pfa_deliv_list(ctx, deliv_ctx);
    }

    if (deliv_ctx->deliv_skb_head == NULL) {
        deliv_ctx->deliv_skb_head = skb;
    }
    /* save the last pkt usr_data for safe */
    deliv_ctx->usr_data = usr_data;
    deliv_ctx->cur_pkt_cnt++;
    
    if (deliv_ctx->cur_skb != NULL) {
        deliv_ctx->cur_skb->next = skb;
    }
    deliv_ctx->cur_skb = skb;
    skb->next = NULL;
    return;
}

void dpa_sms_wlan_pfa_netif_rx(struct sk_buff *skb, void *priv)
{
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;
    struct sms_gro_deliv_ctx* deliv_ctx = &ctx->deliv_ctx[DPA_SMS_NIC_WLAN];
    
    dpa_sms_pfa_netif_rx(ctx, deliv_ctx, skb, priv);
    return;
}
EXPORT_SYMBOL(dpa_sms_wlan_pfa_netif_rx);

void dpa_sms_wlan_pfa_rx(void *pkt_info, void *priv)
{
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;
    struct sms_gro_deliv_ctx* deliv_ctx = &ctx->deliv_ctx[DPA_SMS_NIC_WLAN];
    struct dpa_sms_filter_pkt_info* info = (struct dpa_sms_filter_pkt_info*)pkt_info;
    struct sk_buff *deliv_skb;
    struct sk_buff *dra_skb;
    void* usr_data;

    if (unlikely(info->pkt_len > DRA_SKB_MAX_PKT_SIZE)) {
        dpa_sms_gro_unmap_free_dra(ctx, info->dra_addr);
        dpa_pr_fatal("pfa_rx invalid pkt len: %d\n", info->pkt_len);
        ctx->debug_info.drop_pkt++;
        return;
    }

    dra_skb = sms_gro_get_dra_skb(ctx, info->dra_addr, info->pkt_len);
    if (unlikely(dra_skb == NULL)) {
        return;
    }
    if (unlikely(SMS_GRO_IS_OVER_LEN(dra_skb->len))) {
        deliv_skb = dra_skb;
    } else {
        deliv_skb = sms_gro_build_new_skb(dra_skb);
    }
    usr_data = (void*)((char*)(deliv_skb->cb) + deliv_ctx->usr_offset);
#ifdef CONFIG_DPA_PROTO
    deliv_skb->update_only = info->update_only_flag;
#endif
    *(unsigned int*)usr_data = (unsigned int)info->userfield1;
    dpa_sms_pfa_netif_rx(ctx, deliv_ctx, deliv_skb, priv);
}
EXPORT_SYMBOL(dpa_sms_wlan_pfa_rx);

void dpa_sms_wlan_pfa_complete_rd(void *priv)
{
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;
    struct dpa_sms_rx_callback_s* rx_cb = &ctx->rx_cb[DPA_SMS_NIC_WLAN];
    struct sms_gro_deliv_ctx* deliv_ctx = &g_sms_gro_ctx.deliv_ctx[DPA_SMS_NIC_WLAN];

    if (deliv_ctx->deliv_skb_head == NULL) {
        return;
    }

    sms_gro_wlan_pfa_deliv_list(ctx, deliv_ctx);
    if (rx_cb->rx_complete) {
        rx_cb->rx_complete();
    }
    return;
}
EXPORT_SYMBOL(dpa_sms_wlan_pfa_complete_rd);

void dpa_sms_wlan_set_usr_info(unsigned int offset, unsigned int len)
{
    return;
}
EXPORT_SYMBOL(dpa_sms_wlan_set_usr_info);

static void sms_gro_report_cb(void)
{
    return;
}

static void sms_gro_init_deliv_ctx(struct sms_gro_ctx* ctx)
{
    struct sms_gro_deliv_ctx* deliv_ctx;

    deliv_ctx = &g_sms_gro_ctx.deliv_ctx[DPA_SMS_NIC_WLAN];
    deliv_ctx->usr_offset = 0;
    deliv_ctx->usr_len = sizeof(unsigned int);
}

void sms_gro_report_init(void)
{
    struct net_om_info *info = &g_sms_gro_ctx.net_om_info;
    int ret;
 
    info->ul_msg_id = (int)DPA_HOST_NET_OM_SMS_RX;
    info->func_cb = sms_gro_report_cb;
    info->data = (void*)(&g_sms_gro_ctx.debug_info);
    info->size = sizeof(g_sms_gro_ctx.debug_info);
    INIT_LIST_HEAD(&info->list);
 
    ret = bsp_dpa_net_report_register(info);
    if (ret != 0) {
        dpa_pr_err("sms_gro report register fail\n");
    }
}

int sms_gro_init(void)
{
    int ret;
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;

    ctx->dmi_handler.dmi_id = DMI_SERVICE_SMS_RX;
    ctx->dmi_handler.priv = (char*)ctx;
    ctx->dmi_handler.service_cb = sms_gro_proc_rx_cb;
    ctx->dmi_handler.err_process = sms_gro_proc_rx_sync_cb;

    ret = bsp_dmi_client_register(&ctx->dmi_handler);
    if (ret) {
        dpa_pr_fatal("sms msg reg dmi fail\n");
        return ret;
    }

    sms_gro_report_init();
    sms_gro_init_deliv_ctx(ctx);
    dpa_pr_fatal("sms gro init succ\n");
    return 0;
}
EXPORT_SYMBOL(sms_gro_init);

/* debug func can use in rnic: rnic_srs_napi_deliver_skb, bef deliv to linux stack */
void sms_gro_dump_skb(char* tag, struct sk_buff *skb)
{
    struct sk_buff *skb_next = skb;
    struct sk_buff *first = skb;
    int i = 0, j = 0;
    
    dpa_pr_fatal("%s dump skb, skb_iif:%d, protocol:%d, len:%d, data_len:%d\n", 
        tag, skb->skb_iif, skb->protocol, skb->len, skb->data_len);

    while(skb_next) {
        int nfrags = skb_shinfo(skb_next)->nr_frags;
        int gso_size = skb_shinfo(skb)->gso_size;
        int gso_segs = skb_shinfo(skb)->gso_segs;
        
        dpa_pr_fatal(" skb[%d], len:%d, data_len:%d, nfrags:%d, gso_size:%d, gso_segs:%d\n", 
            i, skb_next->len, skb_next->data_len, nfrags, gso_size, gso_segs);

        dpa_pr_fatal(" skb[%d], mac_header:%d, network_header:%d, transport_header:%d\n", 
            i, skb_next->mac_header, skb_next->network_header, skb_next->transport_header);

        j = 0;
        while(j < nfrags) {
            skb_frag_t *frag = &skb_shinfo(skb_next)->frags[j];
            
            dpa_pr_fatal("  frag[%d], data:0x%llx, bv_offset:%d, bv_len:%d\n", 
                j, (unsigned long long)page_to_virt(frag->bv_page), frag->bv_offset, frag->bv_len);

            j++;
        }

        if (skb_next == first) {
            skb_next = skb_shinfo(first)->frag_list;
        } else {
            skb_next = skb_next->next;
        }
        i++;
    }
}
EXPORT_SYMBOL(sms_gro_dump_skb);

void sms_gro_show_usr_info(void)
{
    struct sms_gro_deliv_ctx* deliv_ctx;
    int nic;

    for (nic = DPA_SMS_NIC_WAN; nic < DPA_SMS_NIC_END; nic++) {
        deliv_ctx = &g_sms_gro_ctx.deliv_ctx[nic];
        dpa_pr_fatal("nic[%d] usr_offset: %d\n", nic, deliv_ctx->usr_offset);
        dpa_pr_fatal("nic[%d] usr_len: %d\n", nic, deliv_ctx->usr_len);
    }
}

void sms_gro_debug_show(void)
{
    struct sms_gro_ctx* ctx = &g_sms_gro_ctx;

    dpa_pr_fatal("msg_len_err: %d\n", ctx->debug_info.msg_len_err);
    dpa_pr_fatal("dra_unmap_fail: %d\n", ctx->debug_info.dra_unmap_fail);
    dpa_pr_fatal("nic_type_err: %d\n", ctx->debug_info.nic_type_err);
    dpa_pr_fatal("rx_msg_cnt: %d\n", ctx->debug_info.rx_msg_cnt);
    dpa_pr_fatal("rx_msg_sync_cnt: %d\n", ctx->debug_info.rx_msg_sync_cnt);
    dpa_pr_fatal("proc_msg_cnt: %d\n", ctx->debug_info.proc_msg_cnt);
    dpa_pr_fatal("rx_pkt_cnt: %d\n", ctx->debug_info.rx_pkt_cnt);
    dpa_pr_fatal("rx_blk_cnt: %d\n", ctx->debug_info.rx_blk_cnt);
    dpa_pr_fatal("first_cnt: %d\n", ctx->debug_info.first_cnt);
    dpa_pr_fatal("flist_cnt: %d\n", ctx->debug_info.flist_cnt);
    dpa_pr_fatal("frags_cnt: %d\n", ctx->debug_info.frags_cnt);
    dpa_pr_fatal("rx_pkt_sz: %lld\n", ctx->debug_info.rx_pkt_sz);
    dpa_pr_fatal("last_usr_len: %d\n", ctx->debug_info.last_usr_len);
    dpa_pr_fatal("msg_pool_full: %d\n", ctx->debug_info.msg_pool_full);
    dpa_pr_fatal("drop_pkt: %d\n", ctx->debug_info.drop_pkt);
    dpa_pr_fatal("msg_free: %d\n", ctx->debug_info.msg_free);
    dpa_pr_fatal("over_len_pkt: %d\n", ctx->debug_info.over_len_pkt);
    dpa_pr_fatal("over_len_no_gro: %d\n", ctx->debug_info.over_len_no_gro);
    sms_gro_show_usr_info();

    return;
}


