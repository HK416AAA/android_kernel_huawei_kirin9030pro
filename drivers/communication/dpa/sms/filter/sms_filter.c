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
#include "bsp_dra.h"
#include "bsp_rproc.h"
#include "bsp_sms.h"
#include "bsp_print.h"
#include "bsp_rproc.h"
#include "sys/dpa/sys_rx_filter.h"
#include "sms_filter.h"

#define SMS_FILTER_MSG_POOL_SIZE            64                          /* must 2^n for mask */
#define SMS_FILTER_MSG_POOL_MASK            (SMS_FILTER_MSG_POOL_SIZE - 1)
#define SMS_FILTER_MSG_POS_ADD(prod, value)    ((prod) = ((prod) + (value)) & (SMS_FILTER_MSG_POOL_MASK))
#define SMS_FILTER_MSG_POOL_FULL(prod, cons)   ((((prod) + 1) & (SMS_FILTER_MSG_POOL_MASK)) == (cons))
#define SMS_FILTER_MSG_POOL_EMPTY(prod, cons)  ((prod) == (cons))

#define SMS_FILTER_DFT_DPA_PORT             6
#define SMS_FILTER_ALIGN(addr, boundary) (((uintptr_t)(addr) + (boundary) - 1) & ~((uintptr_t)(boundary) - 1))
#define SMS_FILTER_TRACE_MAX                64  /* must 2^n for mask */
#define SMS_FILTER_TRACE_MASK               (SMS_FILTER_TRACE_MAX - 1)
#define SMS_FILTER_TRACE_ADD(pos, value)    ((pos) = ((pos) + (value)) & (SMS_FILTER_TRACE_MASK))

struct sms_filter_opt_trace {
    unsigned int saddr[4];
    unsigned int daddr[4];
    unsigned int time_ms;
    unsigned short sport;
    unsigned short dport;
    unsigned short opt;     /* 0: add_flow / 1: del_flow */
    unsigned char is_tcp;
    unsigned char is_ipv6;
    void* handler;
};

struct sms_filter_ctx {
    struct dmi_client dmi_handler;
    struct dpa_sms_filter_callback_s filter_cb;
    unsigned short dpa_port;
    unsigned short nic_port[DPA_SMS_NIC_END];
    unsigned int cpu_port_offload_en;

    struct workqueue_struct *filter_wk;
    struct work_struct filter_work;

    struct sms_filter_msg* filter_msg_pool[SMS_FILTER_MSG_POOL_SIZE];
    unsigned int filter_prod;
    unsigned int filter_cons;
    
    /* debug info */
    struct sms_filter_opt_trace* opt_trace;
    spinlock_t lock;
    unsigned int trace_pos;
    unsigned int cp_msg_fail;
    unsigned int msg_pool_full;
    unsigned int msg_len_err;
    unsigned int add_flow_fail;
    unsigned int del_flow_fail;
    unsigned int add_flow_succ;
    unsigned int del_flow_succ;
    unsigned int msg_allc_fail;
    unsigned int msg_alloc_cnt;
    unsigned int msg_send_fail;
    unsigned int vote_en_cnt;
    unsigned int vote_en_fail;
    unsigned int vote_cancel_cnt;
    unsigned int vote_cancel_fail;
    unsigned int vote_en_more_cnt;
    unsigned int vote_cancel_more_cnt;
    unsigned int add_entry_cnt;
    unsigned int add_entry_fail;
    unsigned int add_entry_last_err;
    unsigned int param_err;
};

struct sms_filter_ctx g_sms_filter_ctx = {0};

static void sms_filter_proc_msg(struct sms_filter_ctx* ctx, struct dmi_msg_data *msg)
{
    struct sms_filter_msg* cur_msg;
    struct sms_filter_msg* filter_msg = (struct sms_filter_msg*)msg->buf;
    unsigned int prod = ctx->filter_prod;
    unsigned int cons = ctx->filter_cons;
    int msg_len = SMS_FILTER_ALIGN(sizeof(struct sms_filter_msg), 4);

    if (unlikely(msg_len != msg->len)) {
        ctx->msg_len_err++;
        return;
    }

    if (unlikely(SMS_FILTER_MSG_POOL_FULL(prod, cons))) {
        return;
    }

    cur_msg = ctx->filter_msg_pool[prod];
    if (memcpy_s(cur_msg, sizeof(*cur_msg), filter_msg, sizeof(*filter_msg))) {
        ctx->cp_msg_fail++;
        return;
    }
    mb();

    SMS_FILTER_MSG_POS_ADD(prod, 1);
    ctx->filter_prod = prod;
    return;
}

static int sms_filter_msg_cb(char *priv, unsigned int sub_id, struct dmi_msg_data *msg)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;

    sms_filter_proc_msg(ctx, msg);
    bsp_dmi_msg_free(msg);
    queue_work(ctx->filter_wk, &ctx->filter_work);
    return 0;
}

static void sms_filter_msg_sync_cb(void *priv, unsigned int sub_id, struct dmi_msg_data *msg)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;

    sms_filter_proc_msg(ctx, msg);
    queue_work(ctx->filter_wk, &ctx->filter_work);
    return;
}

int sms_filter_send_msg(enum sms_filter_opt opt)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;
    unsigned int msg_len = ALIGN(sizeof(struct dmi_msg) + sizeof(struct sms_filter_msg), 4);
    struct sms_filter_msg* filter_msg;
    struct dmi_msg* msg;
    int ret;
    
    msg = bsp_dmi_msg_alloc(DMI_SERVICE_SMS_FILTER, msg_len);
    if (msg == NULL) {
        ctx->msg_allc_fail++;
        return -1;
    }
    ctx->msg_alloc_cnt++;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_SMS_FILTER;
    msg->data.len = msg_len - sizeof(struct dmi_msg);

    filter_msg = (struct sms_filter_msg*)(msg + 1);
    filter_msg->opt = opt;

    ret = bsp_dmi_client_request_comm_wake(msg, msg_len);
    if (ret) {
        ctx->msg_send_fail++;
    }
    bsp_dmi_msg_free(&msg->data);
    return ret;
}

static void sms_vote_dpa_awake(struct sms_filter_ctx* ctx)
{
    if (ctx->vote_en_cnt == ctx->vote_cancel_cnt + 1) {
        ctx->vote_en_more_cnt++;
        dpa_pr_fatal("no vote en, vote_en_cnt:%d, vote_cancel_cnt:%d\n", ctx->vote_en_cnt, ctx->vote_cancel_cnt);
        return;
    }
    ctx->vote_en_cnt++;
}

static void sms_vote_dpa_cancel(struct sms_filter_ctx* ctx)
{
    if (ctx->vote_cancel_cnt == ctx->vote_en_cnt) {
        ctx->vote_cancel_more_cnt++;
        dpa_pr_fatal("no vote cancel, vote_en_cnt:%d, vote_cancel_cnt:%d\n", ctx->vote_en_cnt, ctx->vote_cancel_cnt);
        return;
    }
    ctx->vote_cancel_cnt++;
}

static void sms_filter_msg_process(struct sms_filter_ctx* ctx, struct sms_filter_msg* msg)
{
    switch (msg->opt)
    {
    case FILTER_OPT_ADD_ENTRY:
    case FILTER_OPT_DEL_ENTRY:
        break;
    case FILTER_RETURN_DPA_PORT:
        ctx->dpa_port = (unsigned short)msg->usr_para;
        break;
    case FILTER_RETURN_WLAN_PORT:
        ctx->nic_port[DPA_SMS_NIC_WLAN] = (unsigned short)msg->usr_para;
        break;
    case FILTER_RETURN_WAN_PORT:
        ctx->nic_port[DPA_SMS_NIC_WAN] = (unsigned short)msg->usr_para;
        break;
    case FILTER_PM_VOTE_EN:
        sms_vote_dpa_awake(ctx);
        break;
    case FILTER_PM_VOTE_DIS:
        sms_vote_dpa_cancel(ctx);
        break;
    default:
        return;
    }

    return;
}

static void sms_filter_msg_proc(struct sms_filter_ctx* ctx)
{
    unsigned int prod = ctx->filter_prod;
    unsigned int cons = ctx->filter_cons;
    struct sms_filter_msg* cur_msg;

    while (!SMS_FILTER_MSG_POOL_EMPTY(prod, cons)) {
        /* get new msg */
        cur_msg = ctx->filter_msg_pool[cons];

        /* process filter opt */
        sms_filter_msg_process(ctx, cur_msg);

        /* update pord and cons */
        SMS_FILTER_MSG_POS_ADD(cons, 1);
        ctx->filter_cons = cons;
        prod = ctx->filter_prod;
    }
}

static void sms_filter_msg_work(struct work_struct *work)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;

    sms_filter_msg_proc(ctx);
    return;
}

static void sms_filter_print_ipaddr(char* tag, void* addr, int is_ipv4)
{
    char* cur = (char*)addr;

    if (is_ipv4) {
        dpa_pr_fatal("%s ipv4: %d.%d.%d.%d\n", tag, *(cur), *(cur+1), *(cur+2), *(cur+3));
    } else {
        dpa_pr_fatal("%s ipv6: %x%02x:%x%02x:%x%02x:%x%02x:%x%02x:%x%02x:%x%02x:%x%02x\n", tag,
            *(cur), *(cur+1), *(cur+2), *(cur+3), *(cur+4), *(cur+5), *(cur+6), *(cur+7), 
            *(cur+8), *(cur+9), *(cur+10), *(cur+11), *(cur+12), *(cur+13), *(cur+14), *(cur+15));
    }
}

static void sms_filter_trace_opt(struct sms_filter_ctx* ctx, void* handler, struct nf_conntrack_tuple* tuple)
{
    unsigned long flags;
    unsigned int trace_pos;
    struct sms_filter_opt_trace* opt_trace;

    spin_lock_irqsave(&ctx->lock, flags);
    trace_pos = ctx->trace_pos;
    SMS_FILTER_TRACE_ADD(ctx->trace_pos, 1);
    spin_unlock_irqrestore(&ctx->lock, flags);

    opt_trace = &ctx->opt_trace[trace_pos];
    if (tuple != NULL) {
        (void)memcpy_s(opt_trace->daddr, sizeof(opt_trace->daddr), tuple->dst.u3.all, sizeof(tuple->dst.u3.all));
        (void)memcpy_s(opt_trace->saddr, sizeof(opt_trace->saddr), tuple->src.u3.all, sizeof(tuple->src.u3.all));
        opt_trace->dport = htons(tuple->dst.u.udp.port);
        opt_trace->sport = htons(tuple->src.u.udp.port);
        opt_trace->is_ipv6 = (tuple->src.l3num == AF_INET6) ? 1 : 0;
        opt_trace->is_tcp = (tuple->dst.protonum == IPPROTO_TCP) ? 1 : 0;
        opt_trace->opt = 0;
    } else {
        opt_trace->opt = 1;
    }
    opt_trace->time_ms = jiffies_to_msecs(get_jiffies_64());
    opt_trace->handler = handler;

    return;
}

static void sms_filter_dump_trace_opt(struct sms_filter_ctx* ctx)
{
    unsigned int trace_pos = ctx->trace_pos;
    struct sms_filter_opt_trace* opt_trace;
    int i;

    opt_trace = &ctx->opt_trace[trace_pos];
    if (opt_trace->time_ms == 0) {
        trace_pos = 0;
    }

    for (i = 0; i < SMS_FILTER_TRACE_MAX; i++) {
        opt_trace = &ctx->opt_trace[trace_pos];
        if (opt_trace->time_ms == 0) {
            break;
        }
        dpa_pr_fatal("=====\n");
        dpa_pr_fatal("dump tuple[%d]:\n", trace_pos);
        dpa_pr_fatal("  opt: %s\n", (opt_trace->opt == 0) ? ("add_flow") : ("del_flow"));
        dpa_pr_fatal("  handler: 0x%x\n", (unsigned int)(uintptr_t)opt_trace->handler);
        dpa_pr_fatal("  time_ms: 0x%x\n", opt_trace->time_ms);
        if (opt_trace->opt == 0) {
            sms_filter_print_ipaddr("  daddr:", (void*)opt_trace->daddr, !opt_trace->is_ipv6);
            sms_filter_print_ipaddr("  saddr:", (void*)opt_trace->saddr, !opt_trace->is_ipv6);
            dpa_pr_fatal("  %s dport: %d, sport: %d\n", (opt_trace->is_tcp) ? ("tcp") : ("udp"), 
                opt_trace->dport, opt_trace->sport);
        }
        SMS_FILTER_TRACE_ADD(trace_pos, 1);
    }
}

static inline void sms_filter_conv_tuple(struct nf_conntrack_tuple* tuple, struct dpa_filter_tuple *dpa_tuple)
{
    int ret;
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;
    unsigned short sport = dpa_tuple->rport;
    unsigned short dport = dpa_tuple->lport;
    void* saddr = (void*)&dpa_tuple->raddr;
    void* daddr = (void*)&dpa_tuple->laddr;

    (void)memset_s(tuple, sizeof(struct nf_conntrack_tuple), 0, sizeof(struct nf_conntrack_tuple));

    tuple->dst.dir = IP_CT_DIR_ORIGINAL;
    
    if (!dpa_tuple->is_v6) {
        tuple->dst.u3.ip = *(unsigned int*)daddr;
        tuple->src.u3.ip = *(unsigned int*)saddr;
        tuple->src.l3num = AF_INET;
    } else {
        ret = memcpy_s(tuple->src.u3.ip6, sizeof(tuple->src.u3.ip6), saddr, sizeof(tuple->src.u3.ip6));
        if (ret) {
            ctx->cp_msg_fail++;
        }
        ret = memcpy_s(tuple->dst.u3.ip6, sizeof(tuple->dst.u3.ip6), daddr, sizeof(tuple->dst.u3.ip6));
        if (ret) {
            ctx->cp_msg_fail++;
        }
        tuple->src.l3num = AF_INET6;
    }

    if (dpa_tuple->is_tcp) {
        tuple->dst.protonum = IPPROTO_TCP;
        tuple->src.u.tcp.port = sport;
        tuple->dst.u.tcp.port = dport;
    } else {
        tuple->dst.protonum = IPPROTO_UDP;
        tuple->src.u.udp.port = sport;
        tuple->dst.u.udp.port = dport;
    }
}

int dpa_sms_filter_callback_register(struct dpa_sms_filter_callback_s* cb)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;
    
    if (cb == NULL || cb->add_flow == NULL || cb->del_flow == NULL) {
        return -1;
    }

    ctx->filter_cb.add_flow = cb->add_flow;
    ctx->filter_cb.del_flow = cb->del_flow;
    ctx->filter_cb.add_entry = cb->add_entry;
    return 0;
}
EXPORT_SYMBOL(dpa_sms_filter_callback_register);

int dpa_sms_get_wlan_port(void)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;

    if (ctx->nic_port[DPA_SMS_NIC_WLAN] == 0) {
        return -1;
    }
    return ctx->nic_port[DPA_SMS_NIC_WLAN];
}
EXPORT_SYMBOL(dpa_sms_get_wlan_port);

int dpa_sms_filter_add_entry(enum dpa_sms_nic nic, struct sk_buff *skb)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;
    int ret;
 
    if (ctx->filter_cb.add_entry == NULL || nic >= DPA_SMS_NIC_END) {
        ctx->param_err++;
        return -1;
    }
    if (ctx->nic_port[nic] == 0) {
        ctx->param_err++;
        return -1;
    }
    ctx->add_entry_cnt++;
    ret = ctx->filter_cb.add_entry(skb, ctx->nic_port[nic]);
    if (ret) {
        ctx->add_entry_fail++;
        ctx->add_entry_last_err = ret;
    }
    return 0;
}
EXPORT_SYMBOL(dpa_sms_filter_add_entry);

int dpa_sms_filter_config_port(void)
{
    int ret;

    ret = sms_filter_send_msg(FILTER_GET_DPA_PORT);
    if (ret) {
        dpa_pr_fatal("sms_filter get dpa port fail\n");
        return ret;
    }
    ret = sms_filter_send_msg(FILTER_GET_WLAN_PORT);
    if (ret) {
        dpa_pr_fatal("sms_filter get wlan port fail\n");
        return ret;
    }
    ret = sms_filter_send_msg(FILTER_GET_WAN_PORT);
    if (ret) {
        dpa_pr_fatal("sms_filter get wan port fail\n");
        return ret;
    }

    if (g_sms_filter_ctx.cpu_port_offload_en) {
        ret = sms_filter_send_msg(FILTER_ENABLE_CPU_PORT);
        if (ret) {
            dpa_pr_fatal("sms_filter enable cpu port fail\n");
            return ret;
        }
    }
    ret = sms_filter_send_msg(FILTER_CFG_PORT_DONE);
    if (ret) {
        dpa_pr_fatal("sms_filter get dpa port fail\n");
        return ret;
    }
    return 0;
}
EXPORT_SYMBOL(dpa_sms_filter_config_port);

unsigned int dpa_sms_filter_cpu_port_offload_en(void)
{
    return g_sms_filter_ctx.cpu_port_offload_en;
}
EXPORT_SYMBOL(dpa_sms_filter_cpu_port_offload_en);

static void sms_filter_init_cpu_port_offload(void)
{
    g_sms_filter_ctx.cpu_port_offload_en = 0;
}

void* sms_filter_add_flow(struct dpa_filter_tuple *dpa_tuple, struct filter_cb_param *param)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;
    struct nf_conntrack_tuple nf_tuple;
    struct dpa_sms_filter_usr_info usr_info;
    void* ret = NULL;
    unsigned int vir_id;

    if (ctx->dpa_port == 0) {
        dpa_pr_fatal("sms_filter_add_flow, dpa_port err\n");
        return NULL;
    }

    sms_filter_conv_tuple(&nf_tuple, dpa_tuple);
    usr_info.out_port = ctx->dpa_port;
    usr_info.dev = dev_get_by_index(&init_net, param->ifindex);
    if (!usr_info.dev) {
        dpa_pr_fatal("sms_filter_add_flow, dev null, ifindex:%d may err\n", param->ifindex);
        ctx->add_flow_fail++;
        return NULL;
    }
    vir_id = bsp_dpa_sms_netdev_get_vir_id(usr_info.dev);
    if (vir_id  < 0) {
        dpa_pr_fatal("sms_filter_add_flow, vir_idx:%d may err\n", vir_id);
        ctx->add_flow_fail++;
        dev_put(usr_info.dev);
        return NULL;
    }
    usr_info.usr_para = (unsigned int)((vir_id << 16) | (param->hash & 0xFF));
    if (ctx->filter_cb.add_flow != NULL) {
        ret = ctx->filter_cb.add_flow(&nf_tuple, &usr_info);
    }
    dev_put(usr_info.dev);

    if (ret == NULL) {
        ctx->add_flow_fail++;
    }

    ctx->add_flow_succ++;
    sms_filter_trace_opt(ctx, ret, &nf_tuple);
    return ret;
}

void sms_filter_del_flow(void *handle)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;

    sms_filter_trace_opt(ctx, handle, NULL);

    if (handle == NULL) {
        ctx->del_flow_fail++;
        return;
    }
    
    if (ctx->filter_cb.del_flow != NULL) {
        ctx->filter_cb.del_flow(handle);
    }
    ctx->del_flow_succ++;
    return;
}

static void sms_filter_deinit(struct sms_filter_ctx* ctx)
{
    int i;
    
    for (i = 0; i < SMS_FILTER_MSG_POOL_SIZE; i++) {
        if (ctx->filter_msg_pool[i]) {
            kfree((void*)ctx->filter_msg_pool[i]);
            ctx->filter_msg_pool[i] = NULL;
        }
    }

    if (ctx->opt_trace) {
        kfree((void*)ctx->opt_trace);
        ctx->opt_trace = NULL;
    }

    if (ctx->filter_wk != NULL) {
        destroy_workqueue(ctx->filter_wk);
        ctx->filter_wk = NULL;
    }
}

void sms_filter_vote_init(void)
{
}

int sms_filter_init(void)
{
    int ret;
    int i;
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;

    for (i = 0; i < SMS_FILTER_MSG_POOL_SIZE; i++) {
        ctx->filter_msg_pool[i] = kmalloc(sizeof(struct sms_filter_msg), GFP_KERNEL);
        if (!ctx->filter_msg_pool[i]) {
            dpa_pr_fatal("sms_filter alloc msg pool fail\n");
            goto fail;
        }
    }

    ctx->opt_trace = kzalloc(sizeof(struct sms_filter_opt_trace) * SMS_FILTER_TRACE_MAX, GFP_KERNEL);
    if (!ctx->opt_trace) {
        dpa_pr_fatal("sms_filter alloc trace fail\n");
        goto fail;
    }

    INIT_WORK(&ctx->filter_work, sms_filter_msg_work);
    ctx->filter_wk = alloc_ordered_workqueue("sms_filter_work", 0);
    if (ctx->filter_wk == NULL) {
        dpa_pr_fatal("sms_filter alloc wk fail\n");
        goto fail;
    }
    
    ctx->dmi_handler.dmi_id = DMI_SERVICE_SMS_FILTER;
    ctx->dmi_handler.priv = (char*)ctx;
    ctx->dmi_handler.service_cb = sms_filter_msg_cb;
    ctx->dmi_handler.err_process = sms_filter_msg_sync_cb;

    ret = bsp_dmi_client_register(&ctx->dmi_handler);
    if (ret) {
        dpa_pr_fatal("sms_filter reg dmi fail\n");
        goto fail;
    }

    ret = rx_filter_func_regeister(sms_filter_add_flow, sms_filter_del_flow);
    if (ret) {
        dpa_pr_fatal("sms_filter reg cb fail\n");
        goto fail;
    }

    spin_lock_init(&ctx->lock);
    sms_filter_init_cpu_port_offload();
    ctx->nic_port[DPA_SMS_NIC_WLAN] = SMS_FILTER_WLAN_PORT;
    ctx->nic_port[DPA_SMS_NIC_WAN] = SMS_FILTER_WAN_PORT;
    dpa_pr_fatal("sms_filter init succ\n");
    return ret;

fail:
    sms_filter_deinit(ctx);
    return -1;
}
EXPORT_SYMBOL(sms_filter_init);

void sms_filter_debug_show(void)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;

    dpa_pr_fatal("cp_msg_fail: %d\n", ctx->cp_msg_fail);
    dpa_pr_fatal("msg_pool_full: %d\n", ctx->msg_pool_full);
    dpa_pr_fatal("msg_len_err: %d\n", ctx->msg_len_err);
    dpa_pr_fatal("dpa_port: %d\n", ctx->dpa_port);
    dpa_pr_fatal("wlan_port: %d\n", ctx->nic_port[DPA_SMS_NIC_WLAN]);
    dpa_pr_fatal("wan_port: %d\n", ctx->nic_port[DPA_SMS_NIC_WAN]);
    dpa_pr_fatal("add_flow_fail: %d\n", ctx->add_flow_fail);
    dpa_pr_fatal("del_flow_fail: %d\n", ctx->del_flow_fail);
    dpa_pr_fatal("add_flow_succ: %d\n", ctx->add_flow_succ);
    dpa_pr_fatal("del_flow_succ: %d\n", ctx->del_flow_succ);
    dpa_pr_fatal("msg_allc_fail: %d\n", ctx->msg_allc_fail);
    dpa_pr_fatal("msg_alloc_cnt: %d\n", ctx->msg_alloc_cnt);
    dpa_pr_fatal("msg_send_fail: %d\n", ctx->msg_send_fail);

    dpa_pr_fatal("vote_en_cnt: %d\n", ctx->vote_en_cnt);
    dpa_pr_fatal("vote_en_fail: %d\n", ctx->vote_en_fail);
    dpa_pr_fatal("vote_cancel_cnt: %d\n", ctx->vote_cancel_cnt);
    dpa_pr_fatal("vote_cancel_fail: %d\n", ctx->vote_cancel_fail);
    dpa_pr_fatal("vote_en_more_cnt: %d\n", ctx->vote_en_more_cnt);
    dpa_pr_fatal("vote_cancel_more_cnt: %d\n", ctx->vote_cancel_more_cnt);
    
    dpa_pr_fatal("add_entry_cnt: %d\n", ctx->add_entry_cnt);
    dpa_pr_fatal("add_entry_fail: %d\n", ctx->add_entry_fail);
    dpa_pr_fatal("add_entry_last_err: %d\n", ctx->add_entry_last_err);
    dpa_pr_fatal("param_err: %d\n", ctx->param_err);

    return;
}

void sms_filter_dump_trace(void)
{
    struct sms_filter_ctx* ctx = &g_sms_filter_ctx;
    sms_filter_dump_trace_opt(ctx);
    return;
}


