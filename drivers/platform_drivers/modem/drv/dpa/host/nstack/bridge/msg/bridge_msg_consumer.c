/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#include <net/arp.h>
#include "net/udp.h"
#include <net/ip6_checksum.h>
#include "linux/udp.h"
#include "net/tcp.h"
#include "socket/sbr_prot_com.h"
#include "socket/sbr_protocol_api.h"
#include "cooperation/cooperation.h"
#include "stack_thread.h"
#include "stack_mem.h"
#include "sbr_res_mgr.h"
#include "ring.h"
#include "opt.h"
#include "msg/bridge_msg_producer.h"
#include "msg/bridge_msg_api.h"
#include "socket/sbr_prot_com.h"
#include "ip_addr.h"
#include "stack_time.h"
#include "dfx/chr_stats.h"
#include "tc_interface.h"
#include "dfx/global_res_stats.h"
#include "dfx/conn_stats.h"
#ifdef CONFIG_DPA_CHR_WEB
#include "bsp_dpa_chr.h"
#endif
#include "sys_ifidx_convert.h"
#include "msg/bridge_msg_consumer.h"
#ifdef CONFIG_HUAWEI_SMARTCOM
#include <smartcom/smartcom_interface.h>
#endif

struct ssk_map {
    sbr_socket_t *ssk[SOCKET_NUM];
    int num;
};

static struct ssk_map g_ssk_rcv_ready = {0};

static void ssk_map_insert(sbr_socket_t *ssk)
{
    int i;
    for (i = 0; i < g_ssk_rcv_ready.num && i < SOCKET_NUM; i++) {
        if (g_ssk_rcv_ready.ssk[i] == ssk) {
            return;
        }
    }
    if (i == SOCKET_NUM) {
        return;
    }
    sock_hold(ssk->sk);
    g_ssk_rcv_ready.ssk[i] = ssk;
    g_ssk_rcv_ready.num++;
}

static void ssk_map_schedule(void)
{
    int i;
    for (i = 0; i < g_ssk_rcv_ready.num; i++) {
        struct sock *sk = g_ssk_rcv_ready.ssk[i]->sk;
        lock_sock(sk);
        if (!sock_flag(sk, SOCK_DONE)) {
            sk->sk_data_ready(sk);
        }
        release_sock(sk);
        sock_put(sk);
    }
    g_ssk_rcv_ready.num = 0;
}

static void dpa_skb_set_owner_r(struct sk_buff *skb, struct sock *sk)
{
    skb_orphan(skb);
    skb->sk = sk;
    skb->destructor = sbr_tcp_rx_destruct_skb;
    atomic_add((int)skb->truesize, &sk->sk_rmem_alloc);
    sk_mem_charge(sk, (int)skb->truesize);
}

static void dpa_tcp_fix_iphdr(struct sk_buff *skb)
{
    if (skb->protocol == htons(ETH_P_IPV6)) {
        struct ipv6hdr *iph = ipv6_hdr(skb);
        iph->payload_len = htons(ntohs(iph->payload_len) + skb->data_len);
    } else {
        struct iphdr *iph = ip_hdr(skb);
        iph->tot_len = htons(ntohs(iph->tot_len) + skb->data_len);
    }
}

static s32 _dpa_pkt_arrived(sbr_socket_t *sk, msg_pkt_arrived *p)
{
    s32 bpf_ret = 0;
    struct sk_buff *skb;
    u8 iov_segs = p->iov_segs;
    p->ifidx = sk->ifidx;
    bool is_unmap_all;
#if COST_TIME_STAT
    if (p->stats.enabled) {
        u32 cur_time = stack_get_stat_time();
        u32 diff_time = stack_get_diff_time_u32(p->stats.if_timestamp, cur_time);
        p->stats.msg_cost_time = diff_time - p->stats.netif_cost_time - p->stats.ip_cost_time -
                                p->stats.trans_cost_time;
    }
#endif
    struct sock *lsk = sk->sk;
    bool is_tcp = (lsk->sk_protocol == IPPROTO_TCP);
    bool is_skb_next_list = (!is_tcp) && (!udp_sk(lsk)->gro_enabled);
    if (is_skb_next_list) {
        lock_sock(lsk);
        u8 iov_seg_in = stack_iovs_to_skb_recv_queue(sk, p);
        sbr_global_stat_update(GLOBAL_RX_MSG_SKB_NEXT_LIST, iov_seg_in, 0);
        goto RECV_END;
    }
    iov_desc_t desc = {
        .is_ipv6 = p->is_ipv6,
        .net_hdr_offset = p->net_hdr_offset,
        .trans_hdr_offset = p->trans_hdr_offset
    };
    is_unmap_all = (get_global_rx_dra_alloc_num() > RX_DRA_CACHE_LIMIT);
    skb = stack_iovs_build_skb(p->iov, &p->iov_segs, &desc, is_unmap_all);
    if (skb == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, build_skb fail", sk->sk_id, sk->fd);
        sbr_global_stat_update(GLOBAL_RX_MSG_SKB_NULL_ERR, p->iov_segs, 0);
        sbr_conn_stat_update(sk->stats, SBR_RX_MSG_SKB_NULL_ERR, p->iov_segs, 0);
        return -ENOMEM;
    }
    sbr_global_stat_update(GLOBAL_RX_MSG_SEGS_ERR, iov_segs - p->iov_segs, 0);
    skb->protocol = p->is_ipv6 ? htons(ETH_P_IPV6) : htons(ETH_P_IP);
    if (is_tcp && (skb->data_len > 0)) {
        dpa_tcp_fix_iphdr(skb);
    }
    struct skb_shared_info *shinfo = skb_shinfo(skb);
    if (p->iov_segs > 1) {
        if (is_tcp) {
            if (p->is_ipv6) {
                shinfo->gso_type |= SKB_GSO_TCPV6;
            } else {
                shinfo->gso_type |= SKB_GSO_TCPV4;
            }
            shinfo->gso_size = p->iov[1].data_len;
            shinfo->gso_segs = p->iov_segs;
        } else if (udp_sk(lsk)->gro_enabled) {
            shinfo->gso_type |= SKB_GSO_UDP_L4;
            shinfo->gso_size = p->iov[1].data_len;
            shinfo->gso_segs = p->iov_segs;
        }
    }
#if COST_TIME_STAT
    if (p->stats.enabled) {
        p->stats.sock_timestamp = stack_get_stat_time();
        sbr_get_cost_time_stat((void *)skb, &p->stats, COST_TIME_STAT_DOWNLOAD);
    }
#endif

#if CONFIG_DPA_TC
    unsigned long dev_scratch = skb->dev_scratch;
    struct net_device *dev = dev_get_by_index(sock_net(sk->sk), p->ifidx);
    skb->dev = dev;
    skb->sk = lsk;
    bpf_ret = tc_recv_skb(skb);
    skb->sk = NULL;
    skb->dev = NULL;
    skb->dev_scratch = dev_scratch;
    if (dev != NULL) {
        dev_put(dev);
    }
    if (bpf_ret != 0 && !is_tcp) {
        NS_ERR("sk_id=%lu, fd=%d, tc_recv_skb bpf&netfilter fail", sk->sk_id, sk->fd);
        sbr_global_stat_update(GLOBAL_RX_MSG_UDP_BPF_ERR, p->iov_segs, (u32)skb->len);
        if (!is_unmap_all) {
            skb->destructor = sbr_destruct_skb;
        }
        kfree_skb(skb);
        return 0;
    }
#endif

#ifdef CONFIG_DPA_CHR
    u64 rcv_time_ns = (u64)(stack_get_stat_time() - p->arrived_timestamp) * SPL_NS_PER_TICK;
    skb->tstamp = ktime_get_real() - rcv_time_ns;
    bst_rx_check_http_cb(sk, skb);
#endif
    struct sk_buff_head *sk_queue = &lsk->sk_receive_queue;
    lock_sock(lsk);
    if (sk->status == SK_CLOSE) {
        sbr_global_stat_update(GLOBAL_RX_MSG_SK_CLOSED_ERR, p->iov_segs, (u32)skb->len);
        if (!is_unmap_all) {
            skb->destructor = sbr_destruct_skb;
        }
        kfree_skb(skb);
        release_sock(lsk);
        return -EPIPE;
    }
    if (is_tcp) {
        struct tcp_sock *tp = tcp_sk(lsk);
        struct tcp_skb_cb *tcb = TCP_SKB_CB(skb);

        tcb->seq = tp->rcv_nxt;
        tcb->end_seq = tp->rcv_nxt + skb->len;
        tcb->ack_seq = tp->snd_nxt;
        tcb->tcp_flags = TCPHDR_ACK;
        tcb->has_rxtstamp = 1;
        tcb->tcp_gso_segs = p->iov_segs;
        tp->bytes_received += skb->len;
        WRITE_ONCE(tp->rcv_nxt, tcb->end_seq);
        if (is_unmap_all) {
            skb_set_owner_r(skb, lsk);
        } else {
            dpa_skb_set_owner_r(skb, lsk);
        }
        __skb_queue_tail(sk_queue, skb);
        sbr_global_stat_update(GLOBAL_RX_MSG_TCP_OUT, p->iov_segs, (u32)skb->len);
#ifdef CONFIG_CHR_NETLINK_MODULE
        struct net_device *dev = dev_get_by_index(sock_net(sk->sk), p->ifidx);
        skb->dev = dev;
        dpa_hook_local_in(skb);
        if (dev != NULL) {
            dev_put(dev);
            skb->dev = NULL;
        }
#endif
    } else {
        struct udp_dev_scratch *scratch = udp_skb_scratch(skb);
        scratch->_tsize_state = skb->truesize;
#if BITS_PER_LONG == 64
        scratch->len = (u16)skb->len;
        scratch->csum_unnecessary = !!skb_csum_unnecessary(skb);
        scratch->is_linear = !skb_is_nonlinear(skb);
#endif
        int size = (int)skb->truesize;
        int delta, amt;

        spin_lock_bh(&sk_queue->lock);
        (void)atomic_add_return(size, &lsk->sk_rmem_alloc);
        if (!is_unmap_all) {
            skb->destructor = sbr_destruct_skb;
        }
        if (size >= lsk->sk_forward_alloc) {
            amt = sk_mem_pages(size);
            delta = amt << SK_MEM_QUANTUM_SHIFT;
            if (!__sk_mem_raise_allocated(lsk, delta, amt, SK_MEM_RECV)) {
                spin_unlock_bh(&sk_queue->lock);
                atomic_sub(skb->truesize, &lsk->sk_rmem_alloc);
                sbr_global_stat_update(GLOBAL_RX_MSG_SK_RMEM_ERR, p->iov_segs, (u32)skb->len);
                kfree_skb(skb);
                UDP_INC_STATS(sock_net(lsk), UDP_MIB_INERRORS, false);
                goto OUT;
            }
            lsk->sk_forward_alloc += delta;
        }
        lsk->sk_forward_alloc -= size;
        __skb_queue_tail(sk_queue, skb);
        spin_unlock_bh(&sk_queue->lock);
        sbr_global_stat_update(GLOBAL_RX_MSG_UDP_OUT, p->iov_segs, (u32)skb->len);
    }

    NS_DBG("recv skb len %u %s packet, fd=%d", skb->len, (is_tcp ? "tcp" : "udp"), sk->fd);
RECV_END:
    if (!sock_flag(lsk, SOCK_DONE)) {
        ssk_map_insert(sk);
    }
#if CONFIG_DPA_TC
    if (bpf_ret != 0 && is_tcp) {
        NS_ERR("sk_id=%lu, fd=%d, tc_recv_skb bpf&netfilter fail", sk->sk_id, sk->fd);
        sk->d2a_event = D2A_EVT_TCP_RX_TC_FAIL;
        sk->fdopt->migrate_d2a(sk);
    }
#endif
OUT:
    release_sock(lsk);
    return 0;
}

static void pkt_array_iov_release(msg_pkt_arrived_array *p_array)
{
    u8 i = 0;
    msg_pkt_arrived *p = &p_array->pkt_array[0];
    for (; i < p_array->num; ++i) {
        if (p->iov_segs == 0) {
            p = (msg_pkt_arrived *)((uintptr_t)p + sizeof(msg_pkt_arrived));
            continue;
        }
        msg_iovs_free(p->iov, p->iov_segs);
        p = (msg_pkt_arrived *)((uintptr_t)p + sizeof(msg_pkt_arrived) + (p->iov_segs * sizeof(msg_iov)));
    }
}

static s32 _dpa_pkt_array_arrived(data_com_msg *m)
{
    s32 ret = 0;
    u8 iov_segs_total = 0;
    u8 iov_segs_each_pkt = 0;
    int fd = m->param.fd;
    msg_pkt_arrived_array *p_array = (msg_pkt_arrived_array *)m->buffer;
    msg_pkt_arrived *p = &p_array->pkt_array[0];

    u8 i;
    u32 bytes = 0;
    for (i = 0; i < p_array->num; ++i) {
        iov_segs_total += (u8)p->iov_segs;
        u8 j = 0;
        for (; j < p->iov_segs; ++j) {
            bytes += p->iov[j].data_len;
        }
        p = (msg_pkt_arrived *)((uintptr_t)p + sizeof(msg_pkt_arrived) + (p->iov_segs * sizeof(msg_iov)));
    }

    sbr_global_stat_update(GLOBAL_RX_MSG_IN, iov_segs_total, bytes);
    if (p_array->num == 0) {
        NS_ERR("fd=%d, pkt arrived msg num zero", fd);
        sbr_global_stat_update(GLOBAL_RX_MSG_FROM_DPA_ERR, iov_segs_total, bytes);
        return -EINVAL;
    }
    sbr_socket_t *sk = get_dpa_sk(fd);
    if (sk == NULL) {
        sbr_global_stat_update(GLOBAL_RX_MSG_FROM_DPA_ERR, iov_segs_total, bytes);
        pkt_array_iov_release(p_array);
        NS_ERR("fd=%d, sk not found", fd);
        return -EBADF;
    }
    sbr_conn_stat_update(sk->stats, SBR_RX_MSG_IN, iov_segs_total, bytes);
    p = &p_array->pkt_array[0];
    for (i = 0; i < p_array->num; ++i) {
        s32 err = 0;
        if (p->iov_segs == 0) {
            p = (msg_pkt_arrived *)((uintptr_t)p + sizeof(msg_pkt_arrived));
            NS_ERR("sk_id=%lu, fd=%d, pkt arrived seg zero", sk->sk_id, sk->fd);
            continue;
        }
        iov_segs_each_pkt = p->iov_segs;
        err = _dpa_pkt_arrived(sk, p);
        p = (msg_pkt_arrived *)((uintptr_t)p + sizeof(msg_pkt_arrived) + (iov_segs_each_pkt * sizeof(msg_iov)));
        if (err < 0) {
            ret = err;
        }
    }
    if (iov_segs_total > 0) {
        sbr_global_stat_update(GLOBAL_RX_MSG_OUT, iov_segs_total, bytes);
        sbr_conn_stat_update(sk->stats, SBR_RX_MSG_OUT, iov_segs_total, bytes);
    } else {
        sbr_global_stat_update(GLOBAL_RX_MSG_FROM_DPA_ERR, iov_segs_total, bytes);
        sbr_conn_stat_update(sk->stats, SBR_RX_MSG_FROM_DPA_ERR, iov_segs_total, bytes);
    }
    put_dpa_sk(sk);
    return ret;
}

static s32 unsupport_acpu_msg(const data_com_msg *m)
{
    NS_ERR("type=%u", m->param.type);
    return -1;
}

static s32 _dpa_tx_enq(data_com_msg *m, bool is_global_tx)
{
    msg_tx_enq *_m = (msg_tx_enq *)m->buffer;
    struct sk_buff *skb;
    u32 enq_num = _m->enq_num;
    if (is_global_tx) {
        dmm_atomic_add(get_global_tx_num(), enq_num);
        get_dfx_sock_info()->global_tx_buf_enq += enq_num;
    } else {
        get_dfx_sock_info()->conn_tx_buf_enq += enq_num;
    }

    sbr_socket_t *sk = get_dpa_sk(m->param.fd);
    if (sk == NULL) {
        NS_ERR("sk not found]fd=%d", m->param.fd);
        return -EBADF;
    }

    struct sock *lsk = sk->sk;
    lock_sock(lsk);
    if (!is_global_tx) {
        sk->tx_sbuf_num += enq_num;
    }
    bool is_tcp = (lsk->sk_protocol == IPPROTO_TCP);
    if (is_tcp) {
        u32 i;
        for (i = 0; i < enq_num; i++) {
            skb = __skb_dequeue(&sk->dpa_queue);
            if (skb == NULL) {
                break;
            }

            struct tcp_sock *tp = tcp_sk(lsk);
            tp->snd_una += skb->len;
            sk_wmem_queued_add(lsk, (int)(-skb->truesize));
            kfree_skb(skb);
        }

        (void)sbr_handle_tcp_send(sk, true);
    }

    smp_mb();
    if (lsk->sk_socket &&
        test_bit(SOCK_NOSPACE, &lsk->sk_socket->flags)) {
        lsk->sk_write_space(lsk);
    }
    release_sock(lsk);
    put_dpa_sk(sk);
    return 0;
}

static s32 _stack_err_report(data_com_msg *m)
{
    msg_err_report *_m = (msg_err_report *)m->buffer;

    sbr_socket_t *sk = get_dpa_sk(m->param.fd);
    if (sk == NULL) {
        NS_ERR("sk not found]fd=%d", m->param.fd);
        return -EBADF;
    }

    struct sock *lsk = sk->sk;
    if (lsk->sk_protocol != IPPROTO_TCP) {
        NS_ERR("sk_id=%lu, fd=%d, is not tcp", sk->sk_id, sk->fd);
        release_sock(lsk);
        put_dpa_sk(sk);
        return -EBADF;
    }
    lock_sock(lsk);
    lsk->sk_err = -_m->errnum;
    if (inet_sk_state_load(lsk) != TCP_CLOSE) {
        tcp_done(lsk);
        if (!sock_flag(lsk, SOCK_DEAD) && (lsk->sk_err != 0)) {
            NS_ERR("sk_id=%lu, fd=%d, set sk_err %d", sk->sk_id, sk->fd, lsk->sk_err);
            lsk->sk_error_report(lsk);
        }
    }
    release_sock(lsk);
    put_dpa_sk(sk);
    return 0;
}

static s32 _stack_tcp_state_change(data_com_msg *m)
{
    msg_tcp_state_change *_m = (msg_tcp_state_change *)m->buffer;
    sbr_socket_t *sk = get_dpa_sk(m->param.fd);
    if (sk == NULL) {
        NS_WAR("sk not found]fd=%d, state is %hhu", m->param.fd, _m->tcp_state);
        return -EBADF;
    }

    NS_INF("sk_id=%lu, fd=%d, tcp_state %hhu", sk->sk_id, sk->fd, _m->tcp_state);
    struct sock *lsk = sk->sk;
    lock_sock(lsk);
    u8 tcp_state = _m->tcp_state;
    if (tcp_state == TCP_STATE_CLOSE_WAIT || tcp_state == TCP_STATE_CLOSING ||
        tcp_state == TCP_STATE_TIME_WAIT) {
        lsk->sk_shutdown |= RCV_SHUTDOWN;
        sock_set_flag(lsk, SOCK_DONE);
        if (!sock_flag(lsk, SOCK_DEAD)) {
            lsk->sk_state_change(lsk);

            if (tcp_state == TCP_STATE_CLOSING || tcp_state == TCP_STATE_TIME_WAIT) {
                /* Do not send POLL_HUP for half duplex close. */
                if (lsk->sk_shutdown == SHUTDOWN_MASK ||
                    lsk->sk_state == TCP_CLOSE)
                    sk_wake_async(lsk, SOCK_WAKE_WAITD, POLL_HUP);
                else
                    sk_wake_async(lsk, SOCK_WAKE_WAITD, POLL_IN);
            }
        }
    }
    release_sock(lsk);
    put_dpa_sk(sk);
    return 0;
}

static s32 _stack_route_query(data_com_msg *m)
{
    msg_route_notify *msg = (msg_route_notify *)m->buffer;
    sbr_socket_t *sk = get_dpa_sk(m->param.fd);
    if (sk == NULL) {
        NS_ERR("sk not found]fd=%d", m->param.fd);
        return -SPL_EBADF;
    }

    struct sock *lsk = sk->sk;
    lock_sock(lsk);
    if (sk->status != SK_MIGRATE_OK) {
        NS_ERR("sk_id=%lu, fd=%d, has migrate_d2a, d2a event=%d", sk->sk_id, sk->fd, sk->d2a_event);
        release_sock(lsk);
        put_dpa_sk(sk);
        return -EPIPE;
    }
    ip_addr_t nexthop;
    s32 netif_id = get_route_for_send(sk, &msg->dst_addr, msg->remote_port, &msg->src_addr, &nexthop);
    if (netif_id <= 0) {
        sk->d2a_event = D2A_EVT_NOROUTE;
        NS_ERR("sk_id=%lu, fd=%d, ret=%d, cannot find route, d2a migrate now, d2a event=%d",
            sk->sk_id, sk->fd, netif_id, sk->d2a_event);
        sbr_msg_retry_deinit(&sk->cork_send_timer.common);
        sbr_sk_remove_msg_wq(sk);
        s32 ret = sk->fdopt->migrate_d2a(sk);
        if (ret != 0) {
            NS_ERR("sk_id=%lu, fd=%d, migrate_d2a fail, ret %d", sk->sk_id, sk->fd, ret);
        }
        release_sock(lsk);
        put_dpa_sk(sk);
        return netif_id;
    }
    int ret = sbr_handle_route_query(sk, netif_id, &nexthop);
    if (ret < 0) {
        NS_ERR("sk_id=%lu, fd=%d, sbr_handle_route_query error", sk->sk_id, sk->fd);
        release_sock(lsk);
        put_dpa_sk(sk);
        return ret;
    }
    release_sock(lsk);
    put_dpa_sk(sk);
    return 0;
}

static s32 _stack_nd_query(data_com_msg *m)
{
    msg_nd_notify *msg = (msg_nd_notify *)m->buffer;
    struct net_device *dev = dev_get_by_index(&init_net, msg->netif_id);
    if (dev == NULL) {
        NS_ERR("dev is NULL, netif id is %d", msg->netif_id);
        return -SPL_ENODEV;
    }
    struct spl_in6_addr dst_addr = {0};
    struct spl_in6_addr src_addr = {0};
    inet6_addr_from_ip6addr(&dst_addr, &msg->ipdst);
    inet6_addr_from_ip6addr(&src_addr, &msg->ipsrc);
    struct sk_buff *skb = stack_malloc(sizeof(struct sk_buff));
    if (skb == NULL) {
        NS_ERR("kmalloc skb error");
        dev_put(dev);
        return -SPL_ENOMEM;
    }
    skb->head = stack_malloc(sizeof(struct ipv6hdr));
    skb->network_header = 0;
    if (ipv6_hdr(skb) == NULL) {
        NS_ERR("kmalloc v6hdr error");
        dev_put(dev);
        stack_free(skb);
        return -SPL_ENOMEM;
    }
    rcu_read_lock_bh();
    struct neighbour *neigh = __ipv6_neigh_lookup_noref(dev, (struct in6_addr*)&dst_addr);
    if (IS_ERR_OR_NULL(neigh)) {
        neigh = __neigh_create(&nd_tbl, (void *)&msg->ipdst, dev, false);
        if (IS_ERR_OR_NULL(neigh)) {
            NS_ERR("neigh is NULL, netif id is %d", msg->netif_id);
            dev_put(dev);
            rcu_read_unlock_bh();
            stack_free(skb->head);
            stack_free(skb);
            return (s32)PTR_ERR(neigh);
        }
        struct in6_addr *saddr = &ipv6_hdr(skb)->saddr;
        saddr->s6_addr32[0] = src_addr.s6_addr32[0];
        saddr->s6_addr32[1] = src_addr.s6_addr32[1];
        saddr->s6_addr32[2] = src_addr.s6_addr32[2];
        saddr->s6_addr32[3] = src_addr.s6_addr32[3];
        neigh->ops->solicit(neigh, skb);
    } else {
        struct eth_addr ha = {0};
        (void)memcpy_s(&ha, SPL_ETH_ALEN, neigh->ha, SPL_ETH_ALEN);
        int ret = notify_nd_event((void*)&msg->ipdst, ha, neigh->nud_state, AF_INET6, dev);
        if (ret != 0) {
            NS_ERR("notify_nd_event error");
        }
    }
    rcu_read_unlock_bh();
    stack_free(skb->head);
    stack_free(skb);
    dev_put(dev);
    return 0;
}

static s32 _stack_arp_query(data_com_msg *m)
{
    msg_arp_notify *msg = (msg_arp_notify *)m->buffer;
    struct net_device *dev = dev_get_by_index(&init_net, msg->netif_id);
    if (dev == NULL) {
        NS_ERR("dev is NULL, netif id is %d", msg->netif_id);
        return -SPL_ENODEV;
    }
    rcu_read_lock_bh();
    struct neighbour *neigh = __ipv4_neigh_lookup_noref(dev, msg->ipdst);
    if (IS_ERR_OR_NULL(neigh)) {
        neigh = __neigh_create(&arp_tbl, (void *)&msg->ipdst, dev, false);
        if (IS_ERR_OR_NULL(neigh)) {
            NS_ERR("neigh is NULL, netif id is %d", msg->netif_id);
            dev_put(dev);
            rcu_read_unlock_bh();
            return (s32)PTR_ERR(neigh);
        }
        arp_send(ARPOP_REQUEST, ETH_P_ARP, msg->ipdst, dev, msg->ipsrc,
            NULL, (const unsigned char *)msg->hwsrc.addr, NULL);
    } else {
        (void)memcpy_s(&msg->hwsrc, sizeof(msg->hwsrc), neigh->ha, sizeof(msg->hwsrc));
        int ret = notify_nd_event((void*)&msg->ipdst, msg->hwsrc, neigh->nud_state, AF_INET, dev);
        if (ret != 0) {
            NS_ERR("notify_nd_event error ret is %d", ret);
        }
    }
    rcu_read_unlock_bh();
    dev_put(dev);
    return 0;
}

static void migrate_backlog_purge(struct sock *sk)
{
    struct sk_buff *skb;
    spin_lock_bh(&sk->sk_lock.slock);
    if (sk->sk_backlog.tail == NULL) {
        spin_unlock_bh(&sk->sk_lock.slock);
        return;
    }

    skb = sk->sk_backlog.head;
    sk->sk_backlog.head = sk->sk_backlog.tail = NULL;
    NS_WAR("sk_backlog len %u", sk->sk_backlog.len);
    sk->sk_backlog.len = 0;
    spin_unlock_bh(&sk->sk_lock.slock);
    migrate_drop_skb(skb);
}

static bool is_migrate_sk_changed(sbr_socket_t *ssk)
{
    struct sock *sk = ssk->sk;
    if (sock_flag(sk, SOCK_DEAD) || (inet_sk_state_load(sk) != TCP_ESTABLISHED)) {
        return true;
    }

    if (inet_sk(sk)->dpa_enable != 1) {
        return true;
    }

    if (sk->sk_protocol == IPPROTO_TCP && !tcp_rtx_and_write_queues_empty(sk)) {
        return true;
    }

    return false;
}

static s32 _stack_migrate_resp(data_com_msg *m)
{
    msg_migrate_a2d_resp *_m = (msg_migrate_a2d_resp *)m->buffer;
    sbr_socket_t *ssk = coop_pop_migrate_id(_m->migrate_id);
    if (ssk == NULL) {
        NS_WAR("migrate_id %lu invalid fd=%d", _m->migrate_id, m->param.fd);
        if (m->param.fd >= 0) {
            (void)sbr_fd_close(0, m->param.fd, false);
        }
        return -EBADF;
    }

    struct sock *sk = ssk->sk;
    lock_sock(sk);
    NS_INF("sk_id=%lu, fd=%d", ssk->sk_id, m->param.fd);
    if (ssk->status == SK_MIGRATE_A2D) {
        sk_stop_timer(sk, &ssk->timer);
    }

    if (m->param.fd >= 0) {
        ssk->fd = m->param.fd;
        ssk->tx_sbuf_num = _m->tx_sbuf_num;
    } else {
        ssk->d2a_event = D2A_EVT_SK_NUM_FULL;
        ip_addr_t sip = {0};
        ip_addr_t rip = {0};
        get_sk_addr(sk, false, &sip);
        get_sk_addr(sk, true, &rip);
        NS_WAR("D2A_EVT_SK_NUM_FULL, sk_id=%lu, fd=%d, uid=%u, %s-%s, %hu-%hu, ifidx=%d, d2a event=%d", ssk->sk_id,
             ssk->fd, sk->sk_uid.val, ip_safety_x(&sip), ip_safety_x(&rip), sk->sk_num, ntohs(sk->sk_dport),
             ssk->ifidx, ssk->d2a_event);
        goto FAIL;
    }

    if (unlikely(ssk->status != SK_MIGRATE_A2D || is_migrate_sk_changed(ssk))) {
        (void)sbr_handle_close(ssk, false);
        ssk->fd = -1;
        ssk->d2a_event = D2A_EVT_SK_CLOSED;
        goto FAIL;
    } else if (likely(sbr_init_socket(sk) == 0)) {
        s32 ret = coop_filter_add(sk);
        if (ret != 0) {
            NS_ERR("sk_id=%lu, fd=%d, tcp_filter_add fail", ssk->sk_id, m->param.fd);
            release_dpa_sk(ssk);
            (void)sbr_handle_close(ssk, false);
            ssk->fd = -1;
            ssk->d2a_event = D2A_EVT_ADD_FILTER_FAIL;
            goto FAIL;
        }
        if (!ssk->is_tcp_server) {
            ssk->status = SK_MIGRATE_OK;
        }
        if (sk->sk_protocol == IPPROTO_TCP) {
            migrate_backlog_purge(sk);
            coop_migrate_a2d_backlog(sk, ssk->is_tcp_server ? 0 : 1, true);
            tcp_clear_xmit_timers(sk);
            if (ssk->is_tcp_server) {
                coop_migrate_timer_reset(sk, MIGRATE_TIMER_A2D_BACKLOG, 1);
            }
        }
    } else {
        ssk->d2a_event = D2A_EVT_SK_INIT_FAIL;
        /* sbr_init_socket() fail for dpa reset, don't need call sbr_init_socket() */
        ssk->fd = -1;
FAIL:
        coop_migrate_a2d_fail(sk, true, ssk->d2a_event);
    }

    if (ssk->status != SK_MIGRATE_A2D) {
        coop_migrate_wakeup(sk);
    }
    release_sock(sk);
    sock_put(sk); /* dec for coop_pop_migrate_id() */
    return 0;
}

static bool is_tcp_d2a_iov_valid(data_com_msg *m, bool is_snd)
{
    if (is_snd) {
        if (m->param.buffer_len != MSG_SIZE(sizeof(msg_tcp_d2a_iov_snd))) {
            NS_ERR("msg len err: msg_tcp_d2a_iov_snd,len=%u, buflen=%u, fd=%d",
                sizeof(msg_tcp_d2a_iov_snd), m->param.buffer_len, m->param.fd);
            return false;
        }
    } else {
        if (m->param.buffer_len != MSG_SIZE(sizeof(msg_tcp_d2a_iov_rcv))) {
            NS_ERR("msg len err: msg_tcp_d2a_iov_rcv,len=%u, buflen=%u, fd=%d",
                sizeof(msg_tcp_d2a_iov_rcv), m->param.buffer_len, m->param.fd);
            return false;
        }
    }
    return true;
}

static s32 _stack_migrate_d2a_resp_iov(data_com_msg *m, bool is_snd)
{
    msg_tcp_d2a_iov_snd *m_snd;
    msg_tcp_d2a_iov_rcv *m_rcv;
    msg_iov *iov;
    u8 iov_segs;

    if (!is_tcp_d2a_iov_valid(m, is_snd)) {
        return -EINVAL;
    }
    if (is_snd) {
        m_snd = (msg_tcp_d2a_iov_snd *)m->buffer;
        iov = m_snd->iov;
        iov_segs = m_snd->iov_segs;
    } else {
        m_rcv = (msg_tcp_d2a_iov_rcv *)m->buffer;
        iov = m_rcv->iov;
        iov_segs = m_rcv->iov_segs;
    }

    sbr_socket_t *ssk = get_dpa_sk(m->param.fd);
    if (ssk == NULL) {
        msg_iovs_free(iov, iov_segs);
        NS_ERR("sk not found]fd=%d", m->param.fd);
        return -EBADF;
    }

    struct sock *sk = ssk->sk;

    lock_sock(sk);
    if (ssk->status != SK_MIGRATE_D2A) {
        NS_WAR("fd=%d, status %u", m->param.fd, ssk->status);
        msg_iovs_free(iov, iov_segs);
    } else {
        s32 ret = coop_tcp_d2a_resp_iov(sk, is_snd ? (void *)m_snd : (void *)m_rcv, is_snd);
        if (ret != 0) {
            msg_iovs_free(iov, iov_segs);
            ssk->status = SK_CLOSE;
            sk->sk_err = ECONNABORTED;
            if (inet_sk_state_load(sk) != TCP_CLOSE) {
                tcp_done(sk);
            }
            migrate_revert(sk, true, false);
            release_dpa_sk(ssk);
            conn_stats_print(ssk);
            if (!sock_flag(sk, SOCK_DEAD)) {
                sk->sk_error_report(sk);
            }
            NS_ERR("sk_id=%lu, fd=%d, coop_tcp_d2a_resp_iov fail", ssk->sk_id, ssk->fd);
        }
    }
    release_sock(sk);
    put_dpa_sk(ssk);
    return 0;
}

static inline void update_sock_statistics_msg(struct sbr_socket *sk, stat_unit *stats)
{
#if CONFIG_DPA_TC
    tc_update_sock_statistics_msg(sk, stats);
#endif
}

static void dpa_tcp_conn_stats_print(u64 sk_id, s32 fd, stat_unit *stats)
{
    u16 i = 1;
    u16 index = 0;
    char *buffer = stack_malloc(STRING_LEN);
    if (buffer == NULL) {
        NS_ERR("sk_id=%lu,fd=%d, buffer malloc failed", sk_id, fd);
        return;
    }
    while (index < CONN_STATS_MAX_TYPE) {
        u32 len = 0;
        for (; index < CONN_STATS_MAX_TYPE; index++) {
            if (stats[index].cnt == 0) {
                continue;
            }
            int ret = snprintf_s(buffer + len, STRING_LEN - len, STRING_LEN - len - 1, "%s=[%u,%u,%u],",
                get_conn_stats_info()[index], stats[index].cnt, stats[index].pkts, stats[index].bytes);
            if (ret > 0) {
                len += ret;
            } else {
                break;
            }
        }
        if ((len > 0) && (len < STRING_LEN)) {
            buffer[len - 1] = '\0';
            NS_INF("sk_id=%lu,fd=%d,DPA stats[%d]:%s", sk_id, fd, i, buffer);
        } else {
            NS_INF("sk_id=%lu,fd=%d,DPA stats[%d]:%d in/out", sk_id, fd, i, len);
        }
        i++;
    }
    stack_free(buffer);
}

static s32 _stack_migrate_d2a_resp(data_com_msg *m)
{
    msg_tcp_migrate_d2a_resp *_m = (msg_tcp_migrate_d2a_resp *)m->buffer;
    sbr_socket_t *ssk = get_dpa_sk(m->param.fd);
    if (ssk == NULL) {
        NS_WAR("sk not found]fd=%d", m->param.fd);
        return -EBADF;
    }

    struct sock *sk = ssk->sk;
    if (sk->sk_protocol != IPPROTO_TCP) {
        put_dpa_sk(ssk);
        NS_WAR("sk is not tcp]sk_id=%lu, fd=%d", ssk->sk_id, m->param.fd);
        return -EBADF;
    }

    lock_sock(sk);
    dpa_tcp_conn_stats_print(ssk->sk_id, m->param.fd, ssk->conn_stats);
    update_sock_statistics_msg(ssk, ssk->conn_stats);
    sk_stop_timer(sk, &ssk->timer);
    if (ssk->status != SK_MIGRATE_D2A) {
        NS_WAR("sk_id=%lu, fd=%d, status %u is not SK_MIGRATE_D2A, set err", ssk->sk_id, m->param.fd, ssk->status);
        _m->err = -1;
        (void)coop_tcp_d2a_resp(sk, _m);
        coop_migrate_d2a_fail(ssk, true, -ECONNABORTED);
    } else {
        s32 ret = coop_tcp_d2a_resp(sk, _m);
        if (ret != 0) {
            coop_migrate_d2a_fail(ssk, true, ret);
        } else {
            NS_INF("sk_id=%lu, fd=%d, coop_tcp_d2a_resp succ", ssk->sk_id, m->param.fd);
            migrate_revert(sk, true, true);
            sk_dra_alloc_remove(ssk);
            release_dpa_sk(ssk);
            conn_stats_print(ssk);
            ssk->fd = -1;
        }
        coop_migrate_wakeup(sk);
    }
#ifdef CONFIG_DPA_CHR
    migrate_revert_stat(sk, ssk->d2a_event);
    chr_conn_stats_report(ssk->d2a_event, ssk->conn_stats_num, ssk->conn_stats);
#endif
    release_sock(sk);
    put_dpa_sk(ssk);
    return 0;
}

static void udp_pkt_redirect(msg_pkt_redirect *p, struct net_device *dev)
{
    u8 i;
    int ret;
    struct sk_buff *fake_skb;
    struct sk_buff *skb;
    ktime_t skb_time;
    msg_iov *iov = p->iov;
    u8 iov_segs = p->iov_segs;
    u32 maa_size;
    for (i = 0; i < iov_segs; i++) {
        void *virt = stack_mem_convert(iov[i].base_addr);
        if (virt == NULL) {
            NS_ERR("nstack_mem_convert failed");
            msg_iovs_free_with_unmap(iov, iov_segs, false, i);
            break;
        }
        fake_skb = stack_dra_unmap(iov[i].base_addr);
        if (fake_skb == NULL) {
            NS_ERR("stack_dra_unmap failed");
            msg_iovs_free_with_unmap(iov, iov_segs, false, i);
            break;
        }

        maa_size = get_maa_tot_size(virt, iov[i].data_len + iov[i].data_off);
        skb = sbr_build_skb(virt, maa_size, iov[i].head_frag);
        maa_cache_flush(iov[i].base_addr);
        if (skb == NULL) {
            NS_ERR("build_skb fail");
            sbr_global_stat_update(GLOBAL_RX_MSG_UDP_REDIRECT_SKB_NULL_ERR, p->iov_segs, 0);
            stack_maa_free((u64)stack_mem_to_page(virt), MAA_FLAG_UNMAP);
            msg_iovs_free_with_unmap(iov, iov_segs, false, i + 1);
            break;
        }
        if (i == 0) {
            skb_time = ktime_get_real();
        }
        __skb_set_length(skb, iov[i].data_len + iov[i].data_off);
        skb_reserve(skb, iov[i].data_off);
        skb->len -= iov[i].data_off;
        skb->tstamp = skb_time;
        skb->dev = dev;
        skb->ip_summed = CHECKSUM_NONE;
#ifndef CONFIG_DPA_PROTO
        /* fix qemu redirect busyloop */
        skb->redirected = 1;
#endif
        skb->csum_valid = 0;
        skb->transport_header = skb->data + p->trans_hdr_offset - skb->head;
        skb->network_header = skb->data + p->net_hdr_offset - skb->head;
        skb->mac_header = skb->network_header - ETH_HLEN;
        skb->protocol = p->is_ipv6 ? htons(ETH_P_IPV6) : htons(ETH_P_IP);
        __skb_push(skb, skb->data - skb_network_header(skb));
        local_bh_disable();
        ret = netif_rx(skb);
        local_bh_enable();
        if (ret != 0) {
            NS_DBG("netif_rx fail ret %d", ret);
        }
    }
}

static s32 _dpa_pkt_redirect(data_com_msg *m)
{
    int ret;
    msg_pkt_redirect *p = (msg_pkt_redirect *)m->buffer;
    struct net_device *dev = dev_get_by_index(&init_net, p->ifindex);
    if (dev == NULL) {
        NS_ERR("dev_get_by_index ifindex %u fail", p->ifindex);
        msg_iovs_free(p->iov, p->iov_segs);
        return -ENODEV;
    }

    if (!p->is_tcp) {
        udp_pkt_redirect(p, dev);
        dev_put(dev);
    } else {
        iov_desc_t desc = {
            .is_ipv6 = p->is_ipv6,
            .net_hdr_offset = p->net_hdr_offset,
            .trans_hdr_offset = p->trans_hdr_offset
        };
        struct sk_buff *skb = stack_iovs_build_skb(p->iov, &p->iov_segs, &desc, true);
        if (skb == NULL) {
            NS_ERR("stack_iovs_build_skb fail");
            sbr_global_stat_update(GLOBAL_RX_MSG_TCP_REDIRECT_SKB_NULL_ERR, p->iov_segs, 0);
            dev_put(dev);
            return -ENOMEM;
        }
        skb->dev = dev;
        skb->ip_summed = CHECKSUM_NONE;
#ifndef CONFIG_DPA_PROTO
        /* fix qemu redirect busyloop */
        skb->redirected = 1;
#endif
        skb->csum_valid = 0;
        struct sk_buff *list_skb = NULL;
        if (skb_has_frag_list(skb)) {
            skb_walk_frags(skb, list_skb) {
                list_skb->dev = dev;
                list_skb->ip_summed = CHECKSUM_NONE;
#ifndef CONFIG_DPA_PROTO
                /* fix qemu redirect busyloop */
                list_skb->redirected = 1;
#endif
                list_skb->csum_valid = 0;
            }
        }
        __skb_push(skb, skb->data - skb_network_header(skb));
        if (p->is_ipv6 == 0) {
            struct iphdr *iph = ip_hdr(skb);
            struct tcphdr *th = tcp_hdr(skb);
            if (p->head_repair) {
                csum_replace2(&iph->check, iph->tot_len, htons(p->net_len));
                iph->tot_len = htons(p->net_len);
                tcp_flag_byte(th) |= p->tcp_flags;
            }
            th->check = ~csum_tcpudp_magic(iph->saddr, iph->daddr,
                skb->len - (skb->transport_header - skb->network_header), IPPROTO_TCP, 0);
            skb->csum_start = skb->transport_header;
            skb->csum_offset = offsetof(struct tcphdr, check);
            skb->ip_summed = CHECKSUM_PARTIAL;
            NS_WAR("seq %x len %u", ntohl(th->seq), skb->len - (skb->transport_header - skb->network_header));
        } else {
            struct ipv6hdr *ip6h = ipv6_hdr(skb);
            struct tcphdr *th = tcp_hdr(skb);
            if (p->head_repair) {
                ip6h->payload_len = htons(p->net_len);
                tcp_flag_byte(th) |= p->tcp_flags;
            }
            th->check = ~tcp_v6_check(skb->len - (skb->transport_header - skb->network_header),
                &ip6h->saddr, &ip6h->daddr, 0);
            skb->csum_start = skb->transport_header;
            skb->csum_offset = offsetof(struct tcphdr, check);
            skb->ip_summed = CHECKSUM_PARTIAL;
            NS_WAR("seq %x len %u", ntohl(th->seq), skb->len - (skb->transport_header - skb->network_header));
        }
        local_bh_disable();
        ret = netif_rx(skb);
        local_bh_enable();
        dev_put(dev);
        if (ret != 0) {
            NS_DBG("netif_rx fail ret %d", ret);
        }
    }
    return 0;
}

static void dpa_conn_stats_copy(u64 sk_id, s32 fd, u16 stats_num, conn_stat_tv *stats)
{
    sbr_socket_t *ssk = get_dpa_sk(fd);
    if (ssk == NULL) {
        NS_WAR("sk not found]fd=%d", fd);
        return;
    }
    u16 i = 0;
    for (; i < stats_num; i++) {
        if (stats[i].type >= CONN_STATS_MAX_TYPE) {
            NS_ERR("sk_id=%lu,fd=%d,DPA stats[%d], stats_num:%d, Invalid stats type[%d]",
                sk_id, fd, i, stats_num, stats[i].type);
            continue;
        }
        ssk->conn_stats[stats[i].type].cnt = stats[i].cnt;
        ssk->conn_stats[stats[i].type].pkts = stats[i].pkts;
        ssk->conn_stats[stats[i].type].bytes = stats[i].bytes;
        ssk->conn_stats_num++;
    }
    put_dpa_sk(ssk);
}

static s32 _conn_stats_report(data_com_msg *m)
{
    msg_dpa_conn_stats_report *report = (msg_dpa_conn_stats_report *)m->buffer;
    if (report->is_udp) {
        dpa_udp_conn_stats_print(report->sk_id, m->param.fd, report->stats_num, report->stats, report);
    } else {
        // tcp need report conn stats to CHR, need wait other CONN_STATS_REPORT msg
        dpa_conn_stats_copy(report->sk_id, m->param.fd, report->stats_num, report->stats);
    }
    return 0;
}

static s32 _stack_migrate_d2a_req(data_com_msg *m)
{
    msg_migrate_d2a_req *_m = (msg_migrate_d2a_req *)m->buffer;
    sbr_socket_t *ssk = get_dpa_sk(m->param.fd);
    if (ssk == NULL) {
        NS_WAR("sk not found]fd=%d", m->param.fd);
        return -EBADF;
    }

    struct sock *sk = ssk->sk;
#ifdef CONFIG_HUAWEI_SMARTCOM
    smartcom_tcp_fallback(sk, SMARTCOM_TCP_FALLBACK_SYN_RST, 0);
#endif
    lock_sock(sk);
    if (ssk->status == SK_MIGRATE_OK) {
        sbr_msg_retry_deinit(&ssk->cork_send_timer.common);
        sbr_sk_remove_msg_wq(ssk);
        ssk->d2a_event = _m->req_code;
        s32 ret = ssk->fdopt->migrate_d2a(ssk);
        if (ret != 0) {
            NS_ERR("sk_id=%lu, fd=%d, migrate_d2a req_code %d fail ret %d", ssk->sk_id, ssk->fd, _m->req_code, ret);
        } else {
            NS_INF("sk_id=%lu, fd=%d, migrate d2a req_code %d", ssk->sk_id, ssk->fd, _m->req_code);
        }
    } else {
        NS_INF("sk_id=%lu, fd=%d, migrate d2a req_code %d skip", ssk->sk_id, ssk->fd, _m->req_code);
    }
    release_sock(sk);
    put_dpa_sk(ssk);
    return 0;
}

/* can only handle async msg */
s32 call_acpu_msg_fun(data_com_msg *m, bool msg_need_free)
{
#ifdef CONFIG_DPA_CHR
    msg_cost_time_stat(m);
#endif
    sbr_msg_handle_inc();
    s32 ret;
    switch (m->param.type) {
        case DPA_PKT_ARRIVED:
            ret = _dpa_pkt_array_arrived(m);
            break;
        case DPA_TX_ENQ:
            ret = _dpa_tx_enq(m, false);
            break;
        case DPA_GLOBAL_TX_ENQ:
            ret = _dpa_tx_enq(m, true);
            break;
        case STACK_ERR_REPORT:
            ret = _stack_err_report(m);
            break;
        case STACK_TCP_STATE_CHANGE:
            ret = _stack_tcp_state_change(m);
            break;
        case STACK_ARP_QUERY:
            ret = _stack_arp_query(m);
            break;
        case STACK_ROUTE_QUERY:
            ret = _stack_route_query(m);
            break;
        case STACK_ND_QUERY:
            ret = _stack_nd_query(m);
            break;
        case MIGRATE_A2D_RESP:
            ret = _stack_migrate_resp(m);
            break;
        case MIGRATE_D2A_IOV_SND:
            ret = _stack_migrate_d2a_resp_iov(m, true);
            break;
        case MIGRATE_D2A_IOV_RCV:
            ret = _stack_migrate_d2a_resp_iov(m, false);
            break;
        case MIGRATE_D2A_RESP:
            ret = _stack_migrate_d2a_resp(m);
            break;
        case DPA_PKT_REDIRECT:
            ret = _dpa_pkt_redirect(m);
            break;
        case CONN_STATS_REPORT:
            ret = _conn_stats_report(m);
            break;
        case MIGRATE_D2A_REQ:
            ret = _stack_migrate_d2a_req(m);
            break;
        default:
            ret = unsupport_acpu_msg(m);
            break;
    }

    if (stack_msg_is_last(m)) {
        ssk_map_schedule();
    }
    msg_free(m, msg_need_free);
    return ret;
}
