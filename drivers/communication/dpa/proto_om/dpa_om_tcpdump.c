/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <securec.h>
#include <linux/spinlock.h>
#include <bsp_print.h>
#include <net/checksum.h>
#include <net/ip6_checksum.h>
#include "socket/sbr_prot_com.h"
#include "sys/dpa/stack_mem.h"
#include "dpa_om.h"
#include "dpa_om_msg.h"
#include "dpa_om_tcpdump.h"

#define DPA_GET_IP_VERSION(ptr)   ((*(unsigned char *)(ptr)) >> 4)
#define DPA_OM_TCPDUMP_ENABLE           1
#define DPA_OM_TCPDUMP_DISABLE          0

#define DPA_MAC_ADDR_LEN                6

struct dpa_tcpdump_ctx *g_tcpdump_ctx = NULL;
unsigned char g_tcpdump_tag[2 * DPA_MAC_ADDR_LEN] = "dpa...dpa...";
static spinlock_t g_tcpdump_lock;

void dpa_tcpdump_proc_debug(void)
{
    struct dpa_tcpdump_ctx *tcpdump_ctx = g_tcpdump_ctx;
    if (tcpdump_ctx == NULL) {
        dpa_pr_err("dpa_tcpdump service not init\n");
        return;
    }
    dpa_pr_err("dpa_tcpdump debug:\n");
    dpa_pr_err("dpa_tcpdump service refcnt=%u\n", tcpdump_ctx->refcnt);
    dpa_pr_err("dpa_tcpdump service state: %u(idle=0,start=1,running=2,stop=3)\n", tcpdump_ctx->state);
    dpa_pr_err("dpa_tcpdump ctrl msg send fail num=%u\n", tcpdump_ctx->ctrl_msg_send_fail_num);
    dpa_pr_err("dpa_tcpdump receive %u pkts in idle stats\n", tcpdump_ctx->no_service_enqueue_fail_num);
    dpa_pr_err("dpa_tcpdump skb build fail num=%u\n", tcpdump_ctx->skb_build_fail_num);
    dpa_pr_err("dpa_tcpdump enqueue skb num=%u\n", tcpdump_ctx->enqueue_skb_num);
    dpa_pr_err("dpa_tcpdump uplink=%u, downlink=%u\n",
        tcpdump_ctx->enqueue_uplink_skb_num, tcpdump_ctx->enqueue_downlink_skb_num);
    dpa_pr_err("dpa_tcpdump uplink pkts=%u, downlink pkts=%u\n",
        tcpdump_ctx->enqueue_uplink_pkts, tcpdump_ctx->enqueue_downlink_pkts);
    dpa_pr_err("dpa_tcpdump deliver, patch deliver times=%u\n", tcpdump_ctx->deliver_times);
    dpa_pr_err("dpa_tcpdump deliver_uplink skb num=%u, deliver_downlink skb num=%u\n",
        tcpdump_ctx->deliver_uplink_skb_num, tcpdump_ctx->deliver_downlink_skb_num);
    dpa_pr_err("dpa_tcpdump no_dev_free skb num=%u, normal_free skb num=%u\n",
        tcpdump_ctx->no_dev_free_skb_num, tcpdump_ctx->normal_free_skb_num);
    dpa_pr_err("dpa_tcpdump no_dev_skb_iif=%u\n", tcpdump_ctx->no_dev_skb_iif);
}

static int dpa_om_tcpdump_ctrl(int en)
{
    dpa_om_msg dpa_msg = {0};
    dpa_msg.param.buffer_len = (unsigned int)OM_MSG_SIZE(sizeof(ctrl_pkt));
    ctrl_pkt *msg = (ctrl_pkt *)dpa_msg.buffer;
    msg->report_enable = en;

    return dpa_om_msg_send(&dpa_msg, DPA_STACK_TCPDUMP_PKT);
}

static int tcpdump_proc_skb(struct sk_buff *skb, struct packet_type *ptype)
{
    if (unlikely(skb_orphan_frags_rx(skb, GFP_ATOMIC) != 0)) {
        return -ENOMEM;
    }
    struct dpa_tcpdump_ctx *tcpdump_ctx = g_tcpdump_ctx;
    if (skb->pkt_type == PACKET_OUTGOING) {
        tcpdump_ctx->deliver_uplink_skb_num++;
    } else {
        tcpdump_ctx->deliver_downlink_skb_num++;
    }

    refcount_inc(&skb->users);
    return ptype->func(skb, skb->dev, ptype, skb->dev);
}

static int dpa_do_tcpdump(struct sk_buff *skb)
{
    struct packet_type *ptype;
    struct dpa_tcpdump_ctx *tcpdump_ctx = g_tcpdump_ctx;

    /* tcpdump处理 */
    local_bh_disable();
    rcu_read_lock();
    /* 格式1 */
    list_for_each_entry_rcu(ptype, &ptype_all, list) {
        if (ptype && is_packet_rcv(ptype->func)) {
            tcpdump_proc_skb(skb, ptype);
        }
    }
    /* 格式2 */
    list_for_each_entry_rcu(ptype, &skb->dev->ptype_all, list) {
        if (ptype && is_packet_rcv(ptype->func)) {
            tcpdump_proc_skb(skb, ptype);
        }
    }
    rcu_read_unlock();
    local_bh_enable();
    dev_kfree_skb_any(skb);
    tcpdump_ctx->normal_free_skb_num++;
    return 0;
}

void check_dpa_tcpdump_service(void)
{
    struct dpa_tcpdump_ctx *tcpdump_ctx = g_tcpdump_ctx;
    int ret;
    spin_lock_bh(&g_tcpdump_lock);
    switch (tcpdump_ctx->state) {
        case DPA_TCPDUMP_STATE_START:
            ret = dpa_om_tcpdump_ctrl(DPA_OM_TCPDUMP_ENABLE);
            if (ret) {
                tcpdump_ctx->ctrl_msg_send_fail_num++;
                tcpdump_ctx->refcnt--;
                tcpdump_ctx->state = DPA_TCPDUMP_STATE_IDLE;
                dpa_pr_err("dpa_tcpdump service start fail\n");
                break;
            }
            tcpdump_ctx->state = DPA_TCPDUMP_STATE_RUNNING;
            dpa_pr_err("dpa_tcpdump service start\n");
            break;
        case DPA_TCPDUMP_STATE_STOP:
            ret = dpa_om_tcpdump_ctrl(DPA_OM_TCPDUMP_DISABLE);
            if (ret) {
                tcpdump_ctx->ctrl_msg_send_fail_num++;
                tcpdump_ctx->refcnt++;
                tcpdump_ctx->state = DPA_TCPDUMP_STATE_RUNNING;
                dpa_pr_err("dpa_tcpdump service stop fail\n");
                break;
            }
            tcpdump_ctx->state = DPA_TCPDUMP_STATE_IDLE;
            dpa_pr_err("dpa_tcpdump service stop\n");
            dpa_tcpdump_proc_debug();
            break;
        case DPA_TCPDUMP_STATE_IDLE:
        case DPA_TCPDUMP_STATE_RUNNING:
            break;
        default:
            dpa_pr_err("dpa_chr tcpdump_state err, state:%u", tcpdump_ctx->state);
            break;
    }
    spin_unlock_bh(&g_tcpdump_lock);
    return;
}

static int do_tcpdump(void *data)
{
    struct sk_buff *skb;
    struct sk_buff_head *list;
    struct dpa_tcpdump_ctx *tcpdump_ctx = g_tcpdump_ctx;
    list = &(tcpdump_ctx->list);

    while (!kthread_should_stop()) {
        down(&tcpdump_ctx->sem_tcpdump_task);
        while ((skb = skb_dequeue(list)) != NULL) {
            dpa_do_tcpdump(skb);
        }
        check_dpa_tcpdump_service();
    }
    return 0;
}

static void dpa_tcpdump_recv_cb(struct sk_buff *skb)
{
    struct sk_buff_head *list;
    list = &(g_tcpdump_ctx->list);
    skb_queue_tail(list, skb);  /* 将skb入队, 内部有锁保护 */
    up(&g_tcpdump_ctx->sem_tcpdump_task);
    g_tcpdump_ctx->deliver_times++;

    return;
}

static void tcpdump_rebuild_iphdr(struct sk_buff *skb)
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
            break;
    }
    return;
}

static void tcpdump_rebuild_ipv6hdr(struct sk_buff *skb)
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
            break;
    }
    return;
}

static void tcpdump_rebuild_skb_hdr(struct sk_buff *skb)
{
    if (skb->protocol == htons(ETH_P_IPV6)) {
        tcpdump_rebuild_ipv6hdr(skb);
    } else {
        tcpdump_rebuild_iphdr(skb);
    }
}

static void dpa_tcpdump_proc(struct sk_buff *skb, dpa_om_msg *msg)
{
    struct net_device *dev;
    om_msg_pkt *p = (om_msg_pkt *)msg->buffer;
    skb_set_mac_header(skb, p->eth_hdr_offset);
    (void)memcpy_s(skb->head + skb->mac_header, sizeof(g_tcpdump_tag), &g_tcpdump_tag[0], sizeof(g_tcpdump_tag));
    if (p->iov_segs > 1) {
        tcpdump_rebuild_skb_hdr(skb);
    }

    dev = dev_get_by_index(&init_net, p->ifindex);
    if (unlikely(dev == NULL)) {
        g_tcpdump_ctx->no_dev_free_skb_num++;
        dev_kfree_skb_any(skb);
        return;
    }

    skb->data = skb->head + skb->mac_header + ETH_HLEN;
    skb->len -= ETH_HLEN;
    skb->skb_iif = dev->ifindex;
    skb->dev = dev;
    skb->destructor = sbr_destruct_skb;
    dev_put(dev);

    switch (msg->param.type) {
        case PKT_UPLINK:
            skb->pkt_type = PACKET_OUTGOING;
            g_tcpdump_ctx->enqueue_uplink_skb_num++;
            g_tcpdump_ctx->enqueue_uplink_pkts += p->iov_segs;
            break;
        case PKT_DOWNLINK:
            skb->pkt_type = PACKET_HOST;
            g_tcpdump_ctx->enqueue_downlink_skb_num++;
            g_tcpdump_ctx->enqueue_downlink_pkts += p->iov_segs;
            break;
        default:
            g_tcpdump_ctx->skb_link_type_err_num++;
            dev_kfree_skb_any(skb);
            return;
    }
    /* 调用tcpdump处理 */
    g_tcpdump_ctx->enqueue_skb_num++;
    dpa_tcpdump_recv_cb(skb);

    return;
}

int dpa_tcpdump_proc_cb(unsigned char *info, unsigned int size)
{
    if (info == NULL || size < OM_MSG_SIZE(sizeof(om_msg_pkt))) {
        g_tcpdump_ctx->skb_build_fail_num++;
        return -1;
    }

    if (g_tcpdump_ctx->state == DPA_TCPDUMP_STATE_IDLE) {
        g_tcpdump_ctx->no_service_enqueue_fail_num++;
        dpa_om_tcpdump_ctrl(DPA_OM_TCPDUMP_DISABLE);
        return -1;
    }

    struct sk_buff *skb;
    dpa_om_msg *msg = (dpa_om_msg *)info;
    om_msg_pkt *p = (om_msg_pkt *)msg->buffer;

    iov_desc_t desc = {
        .is_ipv6          = p->is_ipv6,
        .net_hdr_offset   = p->net_hdr_offset,
        .trans_hdr_offset = p->trans_hdr_offset
    };
    skb = stack_iovs_build_skb(p->iov, &p->iov_segs, &desc, false);
    if (skb == NULL) {
        g_tcpdump_ctx->skb_build_fail_num++;
        return -1;
    }

    dpa_tcpdump_proc(skb, msg);
    return 0;
}

int dpa_tcpdump_service_init(void)
{
    struct dpa_tcpdump_ctx *tcpdump_ctx = NULL;
    tcpdump_ctx = (struct dpa_tcpdump_ctx *)kzalloc(sizeof(struct dpa_tcpdump_ctx), GFP_KERNEL);
    if (tcpdump_ctx == NULL) {
        dpa_pr_err("init_dpa_tcpdump_service kmalloc fail\n");
        return -1;
    }
    memset_s(tcpdump_ctx, sizeof(struct dpa_tcpdump_ctx), 0, sizeof(struct dpa_tcpdump_ctx));
    g_tcpdump_ctx = tcpdump_ctx;

    spin_lock_init(&g_tcpdump_lock);

    skb_queue_head_init(&tcpdump_ctx->list);

    sema_init(&tcpdump_ctx->sem_tcpdump_task, 0);
    tcpdump_ctx->task = kthread_run(do_tcpdump, NULL, "dpa_tcpdump");
    if (IS_ERR_OR_NULL(tcpdump_ctx->task)) {
        kfree(tcpdump_ctx);
        g_tcpdump_ctx = NULL;
        dpa_pr_err("dpa_tcpdump_service_init kthread_run fail\n");
        return -1;
    }

    return 0;
}

void start_dpa_tcpdump_service(void)
{
    struct dpa_tcpdump_ctx *tcpdump_ctx = g_tcpdump_ctx;
    if (tcpdump_ctx == NULL) {
        dpa_pr_err("dpa_tcpdump service not init\n");
        return;
    }
    spin_lock_bh(&g_tcpdump_lock);
    tcpdump_ctx->refcnt++;
    if (tcpdump_ctx->state == DPA_TCPDUMP_STATE_START || tcpdump_ctx->state == DPA_TCPDUMP_STATE_RUNNING) {
        dpa_pr_err("dpa_tcpdump service is already start, refcnt=%u\n", tcpdump_ctx->refcnt);
        spin_unlock_bh(&g_tcpdump_lock);
        return;
    }
    tcpdump_ctx->state = DPA_TCPDUMP_STATE_START;
    up(&tcpdump_ctx->sem_tcpdump_task);
    spin_unlock_bh(&g_tcpdump_lock);
    return;
}

void exit_dpa_tcpdump_service(void)
{
    struct dpa_tcpdump_ctx *tcpdump_ctx = g_tcpdump_ctx;
    if (tcpdump_ctx == NULL) {
        dpa_pr_err("dpa_tcpdump service not init\n");
        return;
    }

    if (tcpdump_ctx->state == DPA_TCPDUMP_STATE_IDLE || tcpdump_ctx->state == DPA_TCPDUMP_STATE_STOP) {
        dpa_pr_err("dpa_tcpdump service in idle state\n");
        return;
    }

    spin_lock_bh(&g_tcpdump_lock);
    tcpdump_ctx->refcnt--;
    dpa_pr_err("dpa_tcpdump service call exit, refcnt=%u\n", tcpdump_ctx->refcnt);
    if (tcpdump_ctx->refcnt == 0) {
        tcpdump_ctx->state = DPA_TCPDUMP_STATE_STOP;
        up(&tcpdump_ctx->sem_tcpdump_task);
    }
    spin_unlock_bh(&g_tcpdump_lock);

    return;
}
