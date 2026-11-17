/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#include <net/tcp.h>
#include <linux/socket.h>     // low version linux needs for struct sockaddr
#include <linux/route.h>
#include "sbr_res_mgr.h"
#include "socket/sbr_prot_com.h"
#include "cooperation/cooperation.h"
#include "securec.h"
#include "ring.h"
#include "socket/sbr_misc.h"
#include "sockets.h"
#include "opt.h"
#include "common_msg.h"
#include "msg/bridge_msg_api.h"
#include "stack_time.h"
#include "dfx/global_res_stats.h"
#include "dfx/conn_stats.h"
#ifdef CONFIG_DPA_CHR_WEB
#include "bsp_dpa_chr.h"
#endif
#include "sys_ifidx_convert.h"
#include "msg/bridge_msg_producer.h"

mring_handle g_bridge_msg_pool = NULL;
s32 bridge_msg_pool_init(void)
{
    mring_handle pool = sys_msg_pool_create(MBOX_RING_SIZE, MAX_MSG_SIZE);
    if (pool == NULL) {
        NS_ERR("bridge msg pool create failed");
        return -ENOMEM;
    }
    g_bridge_msg_pool = pool;
    return 0;
}

data_com_msg *sbr_msg_malloc(bool is_data)
{
    data_com_msg *m = NULL;
    if (!sbr_msg_queue_empty_lock()) {
        if (is_data) {
            return NULL;
        } else {
            m = stack_malloc(sizeof(data_com_msg));
            if (m != NULL) {
                msg_init(m);
                m->param.is_dmi_msg = false;
            }
            return m;
        }
    } else {
        m = msg_malloc(g_bridge_msg_pool);
        if (m != NULL) {
            m->param.is_dmi_msg = true;
        }
    }
    return m;
}

void *dmi_msg_malloc(void)
{
    return (void *)msg_malloc(g_bridge_msg_pool);
}

s32 msg_try_post(data_com_msg *m, mring_handle mhandle)
{
#ifdef CONFIG_DPA_CHR
    m->param.msg_post_ts = stack_get_stat_time();
#endif
    s32 ret = 0;
    data_com_msg *dmi_msg = NULL;
    bool is_dmi_msg = m->param.is_dmi_msg;
    sbr_msg_queue_lock();
    if (!sbr_msg_queue_empty()) {
        if (sbr_msg_enqueue_tail(m, mhandle) < 0) {
            NS_ERR("msg try post failed reason: enqueue failed -- queue not empty");
            goto FAILED;
        }
        sbr_msg_queue_unlock();
        return 0;
    }
    if (!is_dmi_msg) {
        dmi_msg = (data_com_msg *)dmi_msg_malloc();
        if (dmi_msg == NULL) {
            sbr_msg_post_fail_inc();
            if (sbr_msg_enqueue_tail(m, mhandle) < 0) {
                NS_ERR("msg try post failed reason: enqueue failed -- dmi_msg malloc failed");
                goto FAILED;
            }
            sbr_msg_queue_unlock();
            return 0;
        }
        void *dest = &dmi_msg->param;
        void *src = &m->param;
        size_t len = sizeof(data_com_msg) - DATA_MSG_PRE;
        (void)memcpy_s(dest, len, src, m->param.buffer_len);
        dmi_msg->param.is_dmi_msg = true;
    } else {
        dmi_msg = m;
    }
    ret = sys_msg_try_post(dmi_msg, mhandle);
    if (ret == 0) {
        sbr_msg_post_succ_inc();
        if (!is_dmi_msg) {
            stack_free(m);
        }
    } else {
        dmi_msg_send_fail_inc();
        if (!is_dmi_msg) {
            msg_free(dmi_msg, true);
        }
        if (ret != -EAGAIN) {
            sbr_msg_post_fail_inc();
            NS_ERR("msg try post failed reason: post ret val abnormal %d", ret);
            goto FAILED;
        }
        if (sbr_msg_enqueue_tail(m, mhandle) < 0) {
            NS_ERR("msg try post failed reason: enqueue failed -- msg post failed");
            goto FAILED;
        }
    }
    sbr_msg_queue_unlock();
    return 0;
FAILED:
    sbr_msg_free(m, true);
    sbr_msg_queue_unlock();
    return -1;
}

NSTACK_STATIC s32 sbr_msg_post(data_com_msg *msg, mring_handle ring)
{
    s32 ret = msg_try_post(msg, ring);
    if (ret != 0) {
        NS_DBG("msg_try_post failed]msg=%hu,op=%hu", msg->param.type, msg->param.op_type);
    }
    return ret;
}

NSTACK_STATIC void sbr_construct_msg(data_com_msg *m, enum api_msg_type msg_type, u16 type, const sbr_socket_t *sk,
    u32 msg_len)
{
    m->param.type = (u16)msg_type;
    m->param.op_type = type;
    m->param.fd = sk->fd;
    m->param.buffer_len = msg_len;
}

s32 sbr_handle_udp_connect(sbr_socket_t *sk, const ip_addr_t *remote_ip, u16 remote_port,
    const ip_addr_t *local_ip, s32 flags)
{
    if (!is_nic_valid_check_by_id(sk->ifidx)) {
        NS_ERR("sk_id=%lu, fd=%d, phy_ifidx %d is invalid", sk->sk_id, sk->fd, sk->ifidx);
        return -ENODEV;
    }
    data_com_msg *m = sbr_msg_malloc(false);
    if (m == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, malloc msg failed", sk->sk_id, sk->fd);
        return -ENOMEM;
    }

    sbr_construct_msg(m, SBR_SPL_CONNECT, MSG_ASYN_POST, sk, (u32)MSG_SIZE(sizeof(msg_connect)));
    msg_connect *p = (msg_connect *)m->buffer;
    p->remote_ip = *remote_ip;
    p->remote_port = remote_port;
    p->local_ip = *local_ip;
    p->local_port = sk->sk->sk_num;
    p->ifidx = sk->ifidx;
    p->ipv6 = (sbr_sk_isv6(sk) && !sk->is_mapped_v6) ? 1U : 0U;
    p->is_nonblock = 0;
    p->update = 0;
    sbr_msg_post(m, sbr_get_msg_box(sk));
    return 0;
}

s32 sbr_handle_route_query(sbr_socket_t *sk, s32 netif_id, const ip_addr_t *nexthop)
{
    if (!is_nic_valid_check_by_id(netif_id)) {
        NS_ERR("sk_id=%lu, fd=%d, phy_ifidx %d is invalid", sk->sk_id, sk->fd, netif_id);
        return -ENODEV;
    }
    data_com_msg *m = sbr_msg_malloc(false);
    if (m == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, malloc msg failed", sk->sk_id, sk->fd);
        return -ENOMEM;
    }
    sbr_construct_msg(m, SBR_ROUTE_TICK_RSP, MSG_ASYN_POST, sk, (u32)MSG_SIZE(sizeof(msg_route_rsp)));
    msg_route_rsp *p = (msg_route_rsp *)m->buffer;
    p->netif_id = netif_id;
    (void)memcpy_s(&p->nexthop, sizeof(ip_addr_t), nexthop, sizeof(ip_addr_t));
    sbr_msg_post(m, sbr_get_msg_box(sk));
    return 0;
}

s32 sbr_handle_setsockopt(sbr_socket_t *sk, s32 level, s32 optname, const void *optval,
    socklen_t optlen)
{
    /* SO_SNDTIMEOUT/SO_RCVTIMEO already set to connect_t */
    if ((level == SOL_SOCKET) && ((optname == SO_RCVTIMEO) || (optname == SO_SNDTIMEO))) {
        return 0;
    }
    struct sock *lsk = sk->sk;
    if ((level == SOL_SOCKET) && (optname == SO_BINDTODEVICE) && (lsk->sk_bound_dev_if != 0)) {
        if (!is_nic_valid_check_by_id(lsk->sk_bound_dev_if)) {
            NS_ERR(" ifidx is invalid, sk_id=%lu, fd=%d, phy_ifidx=%d", sk->sk_id, sk->fd, lsk->sk_bound_dev_if);
            sk->d2a_event = D2A_EVT_OPT_UNSUPP;
            s32 ret = sk->fdopt->migrate_d2a(sk);
            if (ret != 0) {
                NS_ERR("migrate_d2a D2A_EVT_OPT_UNSUPP fail ret %d", ret);
                return ret;
            }
            return -ENODEV;
        }
    }
    data_com_msg *m = sbr_msg_malloc(false);
    socklen_t tmp_len = optlen;
    if (m == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, malloc msg failed", sk->sk_id, sk->fd);
        return -ENOMEM;
    }

    sbr_construct_msg(m, SBR_SPL_SETSOCKOPT, MSG_ASYN_POST, sk, (u32)MSG_SIZE(sizeof(msg_setgetsockopt)));
    msg_setgetsockopt *p = (msg_setgetsockopt *)m->buffer;
    p->level = level;
    p->optname = optname;

    if (tmp_len > (socklen_t)sizeof(p->optval)) {
        tmp_len = (socklen_t)sizeof(p->optval);
    }

    s32 err = memcpy_s(&p->optval, sizeof(p->optval), optval, tmp_len);
    if (err != 0) {
        NS_ERR("sk_id=%lu, fd=%d, memcpy_s failed ret=%d", sk->sk_id, sk->fd, err);
        err = -EINVAL;
        sbr_msg_free(m, true);
        return err;
    }
    p->optlen = tmp_len;
    if ((level == SOL_SOCKET) && (optname == SO_BINDTODEVICE)) {
        p->optval.int_optval = lsk->sk_bound_dev_if;
        const char *char_optval = (const char *)optval;
        if (char_optval != NULL && char_optval[0] == '\0') {
            p->optval.int_optval = -1;
        }
    }
    sbr_msg_post(m, sbr_get_msg_box(sk));
    return err;
}

s32 sbr_fd_close(u64 sk_id, s32 fd, bool need_rst)
{
    data_com_msg *m = sbr_msg_malloc(false);
    if (m == NULL) {
        NS_ERR("sk_id=%lu,fd=%d, sbr_msg_malloc failed", sk_id, fd);
        return -ENOMEM;
    }

    m->param.type = (u16)SBR_SPL_CLOSE;
    m->param.op_type = MSG_ASYN_POST;
    m->param.fd = fd;
    m->param.buffer_len = (u32)MSG_SIZE(sizeof(msg_delete_connect));

    msg_delete_connect *p = (msg_delete_connect *)m->buffer;
    p->need_rst = 0;
    p->time_started = 0;
    p->shut = 0;
    sbr_msg_post(m, get_instance_msg_box(GLOBAL_THREAD_INDEX));
    return 0;
}

s32 sbr_handle_close(sbr_socket_t *sk, bool need_rst)
{
    return sbr_fd_close(sk->sk_id, sk->fd, need_rst);
}

static void sbr_skb_2_iov(msg_iov *iov, struct sk_buff *skb, u64 base_addr)
{
    iov->base_addr = base_addr;
    iov->data_off = (u16)(skb->data - skb->head);
    iov->data_len = (u16)skb->len;
    iov->head_frag = skb->head_frag;
}

s32 sbr_handle_udp_send(sbr_socket_t *sk, struct sk_buff *skb)
{
    struct sock *lsk = sk->sk;
    data_com_msg *m;

    struct sbr_udp_skb_cb *ucb = SBR_UDP_SKB_CB(skb);
    m = sbr_msg_malloc(true);
    if (m == NULL) {
        sbr_udp_send_head_free(sk, skb);
        NS_DBG("sk_id=%lu, fd=%d, attach msg failed", sk->sk_id, sk->fd);
        return -SPL_ENOMEM;
    }

    sbr_construct_msg(m, SBR_SPL_SEND, MSG_ASYN_POST, sk, (u32)MSG_SIZE(sizeof(msg_send_buf)));
    msg_send_buf *p = (msg_send_buf *)m->buffer;

    p->iov_segs = 0;
    if (ucb->addr_type == SPL_IP_ADDR_TYPE_V4) {
        struct iphdr *ip_hdr = (struct iphdr *)skb_network_header(skb);
        p->local_ip.addr = ip_hdr->saddr;
        spl_ip_addr_set_type(&p->local_ip, SPL_IP_ADDR_TYPE_V4);
        p->remote_ip.addr = ip_hdr->daddr;
        spl_ip_addr_set_type(&p->remote_ip, SPL_IP_ADDR_TYPE_V4);
        p->nexthop.addr = ucb->nexthop.addr.s_addr;
        spl_ip_addr_set_type(&p->nexthop, SPL_IP_ADDR_TYPE_V4);
    } else {
        struct ipv6hdr *ip6_hdr = (struct ipv6hdr *)skb_network_header(skb);
        inet6_addr_to_ip6addr(IP6OFX_W(&p->local_ip), (struct spl_in6_addr *)&ip6_hdr->saddr);
        spl_ip_addr_set_type(&p->local_ip, SPL_IP_ADDR_TYPE_V6);
        inet6_addr_to_ip6addr(IP6OFX_W(&p->remote_ip), (struct spl_in6_addr *)&ip6_hdr->daddr);
        spl_ip_addr_set_type(&p->remote_ip, SPL_IP_ADDR_TYPE_V6);
        inet6_addr_to_ip6addr(IP6OFX_W(&p->nexthop), &ucb->nexthop.addr6);
        spl_ip_addr_set_type(&p->nexthop, SPL_IP_ADDR_TYPE_V6);
    }
    p->remote_port = ucb->remote_port;
    p->ifidx = ucb->ifidx;

    sbr_skb_2_iov(&p->iov[p->iov_segs], skb, ucb->maa_addr);
    p->iov_segs++;
    p->len = (u16)skb->len;
    if (ucb->is_global_buf == 1) {
        p->conn_tx_cost = 0;
        p->global_tx_cost = 1;
        dmm_atomic_inc(&get_dfx_sock_info()->global_tx_buf_post);
    } else {
        p->conn_tx_cost = 1;
        p->global_tx_cost = 0;
        dmm_atomic_inc(&get_dfx_sock_info()->conn_tx_buf_post);
    }

    mring_handle msg_box = sbr_get_msg_box(sk);
    p->tcp_push = 0;
    p->is_sbuf = 0;
    p->post_msg_timestamp = 0;
    p->socket_timestamp = 0;
#if COST_TIME_STAT
    if (sbr_cost_time_stat_is_enabled() && skb->tstamp != 0) {
        p->socket_timestamp = (u32)skb->tstamp;
        p->post_msg_timestamp = stack_get_stat_time();
    }
#endif

    u8 seg_num = p->iov_segs;
    sbr_global_stat_update(GLOBAL_TX_MSG_UDP_IN, seg_num, (u32)p->len);
    sbr_conn_stat_update(sk->stats, SBR_TX_MSG_IN, seg_num, (u32)p->len);
    p->inet_id = inet_sk(lsk)->inet_id;
    inet_sk(lsk)->inet_id += seg_num;
    s32 ret = sbr_msg_post(m, msg_box);
    if (ret != 0) {
        if (ucb->is_global_buf == 1) {
            dmm_atomic_inc(get_global_tx_num());
            dmm_atomic_inc(&get_dfx_sock_info()->global_tx_buf_post_fail);
        } else {
            sk->tx_sbuf_num++;
            dmm_atomic_inc(&get_dfx_sock_info()->conn_tx_buf_post_fail);
        }
        refcount_add((int)(-skb->truesize), &lsk->sk_wmem_alloc);
        kfree_skb(skb);
        sbr_global_stat_update(GLOBAL_TX_MSG_UDP_POST_ERR, seg_num, (u32)p->len);
        sbr_conn_stat_update(sk->stats, SBR_TX_MSG_POST_ERR, seg_num, (u32)p->len);
        return -EAGAIN;
    }
    /* requeue the skb sent to the DPA queue */
    sbr_global_stat_update(GLOBAL_TX_MSG_UDP_OUT, seg_num, (u32)p->len);
    sbr_conn_stat_update(sk->stats, SBR_TX_MSG_OUT, seg_num, (u32)p->len);
    refcount_add((int)(-skb->truesize), &lsk->sk_wmem_alloc);
    skb->head = NULL;
    kfree_skb(skb);
    return 0;
}

s32 sbr_handle_tcp_recved(sbr_socket_t *sk, u16 pcount)
{
    if (pcount == 0) {
        return 0;
    }
    int ret;
    data_com_msg *m = sbr_msg_malloc(true);
    if (m == NULL) {
        NS_DBG("sk_id=%lu, fd=%d, attach msg failed", sk->sk_id, sk->fd);
        sk->recvd_total_count += pcount;
        sbr_sk_add_msg_wq(sk);
        return -EBUSY;
    }

    sbr_construct_msg(m, SBR_SPL_RECVED, MSG_ASYN_POST, sk, (u32)MSG_SIZE(sizeof(msg_recv_buf)));
    msg_recv_buf *p = (msg_recv_buf *)m->buffer;
    p->count = pcount;
    mring_handle box = sbr_get_msg_box(sk);
    ret = sbr_msg_post(m, box);
    if (ret < 0) {
        NS_DBG("sbr_msg_post_ret failed", sk->sk_id, sk->fd);
        sk->recvd_total_count += pcount;
        sbr_sk_add_msg_wq(sk);
        return -EBUSY;
    }
    return 0;
}

static bool sbr_tcp_should_autocork(const sbr_socket_t *sk, const struct sk_buff *skb, bool push)
{
    return skb->len < tcp_sk(sk->sk)->mss_cache &&
           sock_net(sk->sk)->ipv4.sysctl_tcp_autocorking &&
           !skb_queue_empty(&sk->dpa_queue) && !push;
}

s32 sbr_handle_tcp_send(sbr_socket_t *sk, bool push)
{
    struct sock *lsk = sk->sk;
    struct tcp_sock *tp = tcp_sk(lsk);
    s32 ret, bytes;
    struct sk_buff *skb;
    data_com_msg *m;
    u32 tx_num;
    bool cork;

    if (sk->status != SK_MIGRATE_OK) {
        NS_DBG("sk_id=%lu, fd=%d, status %u skip send", sk->sk_id, sk->fd, sk->status);
        return 0;
    }

    while (skb_queue_len(&lsk->sk_write_queue) > 0 && sk->tx_sbuf_num > 0) {
        m = sbr_msg_malloc(true);
        if (m == NULL) {
            sbr_sk_add_msg_wq(sk);
            NS_DBG("sk_id=%lu, fd=%d, attach msg failed", sk->sk_id, sk->fd);
            return -ENOMEM;
        }

        u32 global_tx_cost = (sk->tx_sbuf_num >= MAX_FRAGS) ? 0 : (MAX_FRAGS - sk->tx_sbuf_num);
        if (global_tx_cost > 0) {
            if (is_global_tx_num_available(global_tx_cost) != 0) {
                /* if global tx num not enough, use tx_sbuf_num only */
                global_tx_cost = 0;
            } else {
                dmm_atomic_add(&get_dfx_sock_info()->global_tx_buf_alloc, global_tx_cost);
            }
        }
        u32 max_tx_num = min_t(u32, sk->tx_sbuf_num + global_tx_cost, MAX_FRAGS);
        u32 conn_tx_cost = max_tx_num - global_tx_cost;
        sbr_construct_msg(m, SBR_SPL_SEND, MSG_ASYN_POST, sk, (u32)MSG_SIZE(sizeof(msg_send_buf)));
        msg_send_buf *p = (msg_send_buf *)m->buffer;
        p->iov_segs = 0;
        p->is_sbuf = 0;
        bytes = 0;
        cork = false;
        skb_queue_walk(&lsk->sk_write_queue, skb) {
            if (skb == skb_peek_tail(&lsk->sk_write_queue) && sbr_tcp_should_autocork(sk, skb, push)) {
                cork = true;
                break;
            }
#ifdef CONFIG_CHR_NETLINK_MODULE
            struct net_device *dev = dev_get_by_index(sock_net(sk->sk), sk->ifidx);
            skb->dev = dev;
            dpa_hook_local_out(skb);
            if (dev != NULL) {
                dev_put(dev);
                skb->dev = NULL;
            }
#endif
            struct sbr_tcp_skb_cb *tcb = SBR_TCP_SKB_CB(skb);
            sbr_skb_2_iov(&p->iov[p->iov_segs], skb, tcb->maa_addr);
            bytes += (s32)skb->len;
            p->iov_segs++;
            if (p->iov_segs == max_tx_num) {
                break;
            }
        }
        if (cork) {
            cork_send_timer_handle handle = sbr_handle_tcp_send;
            sbr_cork_send_timer_start(sk, handle, p->iov_segs > 0 ? true : false);
        } else {
            if (sk->cork_send_timer.common.is_timer_start) {
                sbr_msg_retry_deinit(&sk->cork_send_timer.common);
            }
        }
        if (p->iov_segs == 0) {
            sbr_msg_free(m, true);
            dmm_atomic_add(get_global_tx_num(), global_tx_cost);
            dmm_atomic_add(&get_dfx_sock_info()->global_tx_buf_revert, global_tx_cost);
            return 0;
        }
        p->tcp_push = 0;
        if (SBR_TCP_SKB_CB(lsk->sk_write_queue.prev)->tcp_push != 0) {
            p->tcp_push = 1;
        }
        p->len = (u16)bytes;
        tx_num = p->iov_segs;
        if (tx_num <= conn_tx_cost) {
            conn_tx_cost = tx_num;
            p->conn_tx_cost = conn_tx_cost;
            p->global_tx_cost = 0;
        } else {
            p->conn_tx_cost = conn_tx_cost;
            p->global_tx_cost = (tx_num - conn_tx_cost);
        }
        dmm_atomic_add(&get_dfx_sock_info()->conn_tx_buf_post, conn_tx_cost);
        dmm_atomic_add(&get_dfx_sock_info()->global_tx_buf_post, (tx_num - conn_tx_cost));
        u32 global_revert = global_tx_cost - p->global_tx_cost;

        tp->snd_nxt += p->len;
        mring_handle box = sbr_get_msg_box(sk);
        // init remote_ip, local_ip, nexthop
        (void)memset_s(&p->remote_ip, 3 * sizeof(ip_addr_t), 0, 3 * sizeof(ip_addr_t));
        p->remote_port = 0;
        p->ifidx = 0;
        p->inet_id = 0;
        p->post_msg_timestamp = 0;
        p->socket_timestamp = 0;
#if COST_TIME_STAT
        if (sbr_cost_time_stat_is_enabled() && skb_peek(&lsk->sk_write_queue)->tstamp != 0) {
            p->socket_timestamp = (u32)skb_peek(&lsk->sk_write_queue)->tstamp;
            p->post_msg_timestamp = stack_get_stat_time();
        }
#endif
        sbr_global_stat_update(GLOBAL_TX_MSG_TCP_IN, p->iov_segs, bytes);
        sbr_conn_stat_update(sk->stats, SBR_TX_MSG_IN, p->iov_segs, bytes);
        ret = sbr_msg_post(m, box);
        if (ret != 0) {
            NS_DBG("sbr_msg_post_ret failed]fd=%d", sk->fd);
            sbr_sk_add_msg_wq(sk);
            sbr_global_stat_update(GLOBAL_TX_MSG_TCP_POST_ERR, p->iov_segs, bytes);
            sbr_conn_stat_update(sk->stats, SBR_TX_MSG_POST_ERR, p->iov_segs, bytes);
            dmm_atomic_add(get_global_tx_num(), global_tx_cost);
            dmm_atomic_add(&get_dfx_sock_info()->conn_tx_buf_post_fail, conn_tx_cost);
            dmm_atomic_add(&get_dfx_sock_info()->global_tx_buf_revert, global_revert);
            dmm_atomic_add(&get_dfx_sock_info()->global_tx_buf_post_fail, (tx_num - conn_tx_cost));
            return -EBUSY;
        }
        sk->tx_sbuf_num -= conn_tx_cost;
        dmm_atomic_add(&get_dfx_sock_info()->conn_tx_buf_alloc, conn_tx_cost);

        dmm_atomic_add(get_global_tx_num(), global_revert);
        dmm_atomic_add(&get_dfx_sock_info()->global_tx_buf_revert, global_revert);
        u32 i;
        /* requeue the skb sent to the DPA queue */
        for (i = 0; i < tx_num; i++) {
            skb = __skb_dequeue(&lsk->sk_write_queue);
            /* head free by DPA */
            skb->head = NULL;
            tp->snd_nxt += SBR_TCP_SKB_CB(skb)->copied_len;
            __skb_queue_tail(&sk->dpa_queue, skb);
        }
        sk_dra_alloc_sub(sk, tx_num);
        sbr_global_stat_update(GLOBAL_TX_MSG_TCP_OUT, p->iov_segs, bytes);
        sbr_conn_stat_update(sk->stats, SBR_TX_MSG_OUT, p->iov_segs, bytes);
    }
    return 0;
}
