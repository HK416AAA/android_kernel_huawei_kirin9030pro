/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#include <linux/socket.h>
#include <linux/udp.h>
#include "net/tcp.h"
#include "opt.h"
#include "socket/sbr_protocol_api.h"
#include "socket/sbr_prot_com.h"
#include "sbr_res_mgr.h"
#include "stack_mem.h"
#include "stack_log.h"
#include "dmm_spinlock.h"
#include "sys_rx_filter.h"
#include "dfx/chr_stats.h"
#include "dfx/global_res_stats.h"
#include "dfx/conn_stats.h"
#include "socket/sbr_socket.h"
#include "sys_ifidx_convert.h"
#include "runtime.h"
#ifdef CONFIG_HW_NETWORK_AWARE
#include <network_aware/network_aware.h>
#endif
static sbr_socket_t **g_dpa_sk_table = NULL;
static dmm_spinlock_t g_dpa_sk_table_lock;
static volatile u8 g_dpa_reset = 0;

s8 set_dpa_sk(sbr_socket_t *sk)
{
    /* sk->fd MUST be set */
    dmm_spin_lock(&g_dpa_sk_table_lock);
    if (sbr_dpa_reseting()) {
        NS_ERR("sk_id=%lu, fd=%d]fd cannot set for dpa rst", sk->sk_id, sk->fd);
        dmm_spin_unlock(&g_dpa_sk_table_lock);
        return -1;
    }
    if (g_dpa_sk_table[sk->fd] != NULL) {
        NS_ERR("sk_id=%lu, fd=%d]fd was set", sk->sk_id, sk->fd);
    }
#ifdef CONFIG_DPA_CHR
    migrate_succ_stat(sk->sk);
    get_sbr_chr_stats()->flow_num_in_dpa++;
#endif

    sbr_migrate_sock_inc();
    sbr_migrate_a2d_success_inc();
    g_dpa_sk_table[sk->fd] = sk;
    dmm_spin_unlock(&g_dpa_sk_table_lock);
    return 0;
}

sbr_socket_t *get_dpa_sk(int fd)
{
    if ((fd < 1) || (fd > SOCKET_NUM)) {
        NS_ERR("fd is invalid]fd=%d", fd);
        return NULL;
    }

    dmm_spin_lock(&g_dpa_sk_table_lock);
    sbr_socket_t *sk = g_dpa_sk_table[fd];
    if (sk != NULL) {
        sock_hold(sk->sk);
    }
    dmm_spin_unlock(&g_dpa_sk_table_lock);
    return sk;
}

void put_dpa_sk(sbr_socket_t *sk)
{
    sock_put(sk->sk);
}

void release_dpa_sk(const sbr_socket_t *sk)
{
    if (unlikely((sk->fd < 1) || (sk->fd > SOCKET_NUM))) {
        NS_ERR("sk_id=%lu, fd=%d is invalid", sk->sk_id, sk->fd);
        return;
    }
    dmm_spin_lock(&g_dpa_sk_table_lock);
#ifdef CONFIG_DPA_CHR
    sock_close_stat(sk);
#endif

    sbr_migrate_sock_dec();
    g_dpa_sk_table[sk->fd] = NULL;
    dmm_spin_unlock(&g_dpa_sk_table_lock);
}

s8 sbr_init_socket(struct sock *lsk)
{
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    NS_INF("sk_id=%lu, fd=%d, tx_sbuf_num=%u", sk->sk_id, sk->fd, sk->tx_sbuf_num);
    return set_dpa_sk(sk);
}

s32 sbr_setsockopt(struct sock *lsk, s32 level, s32 optname, const void *optval, socklen_t optlen)
{
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    if (sk == NULL) {
        return -EFAULT;
    }

    s32 s = sk->fd;
    if (s < 0) {
        NS_ERR("fd=%d invalid", s);
        return -EFAULT;
    }

    if (optval == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, optval is null", sk->sk_id, sk->fd);
        return -EFAULT;
    }

    NS_DBG("setsockopt]sk_id=%lu, fd=%d,level=%d,optname=%d,optlen=%u", sk->sk_id, sk->fd, level, optname, optlen);
    return sk->fdopt->setsockopt(sk, level, optname, optval, optlen);
}

s32 sbr_recvmsg(struct sock *lsk, struct msghdr *msg, size_t size, int flags)
{
    sbr_global_stat_cnt_inc(GLOBAL_RX_SBR_IN);
    s32 ret;
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    if (sk == NULL) {
        return -EFAULT;
    }
    sbr_conn_stat_cnt_inc(sk->stats, SBR_RX_APP_IN);
    NS_DBG("recvmsg]fd=%d,flags=%d", sk->fd, flags);
#ifdef CONFIG_HW_NETWORK_AWARE
    sock_network_aware(lsk, true);
    sock_stat_bg_network_flow(lsk, true, size);
#endif
    ret = sk->fdopt->recvmsg(sk, msg, size, flags);
    return ret;
}

s32 sbr_sendmsg(struct sock *lsk, struct msghdr *msg, size_t size)
{
    s32 ret;
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    if (sk == NULL) {
        return -EFAULT;
    }
#ifdef CONFIG_HW_NETWORK_AWARE
    sock_network_aware(lsk, false);
    sock_stat_bg_network_flow(lsk, false, size);
#endif
    ret = sk->fdopt->sendmsg(sk, msg, size);
    return ret;
}

s32 sbr_shutdown(struct sock *lsk, s32 how)
{
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    if (sk == NULL) {
        return -EFAULT;
    }

    (void)sbr_migrate_d2a(lsk, D2A_EVT_SHUTDOWN);
    release_sock(lsk);
    s32 err = sk->save_ops->shutdown(lsk->sk_socket, how);
    lock_sock(lsk);
    return err;
}

s32 sbr_migrate_a2d(struct sock *lsk)
{
    sbr_migrate_a2d_request_inc();
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    if (sk == NULL) {
        return -EFAULT;
    }

    s32 ret = sk->fdopt->migrate_a2d(sk);
    NS_INF("ret=%d, sk_id=%lu, fd=%d,", ret, sk->sk_id, sk->fd);
    return ret;
}

s32 sbr_migrate_d2a(struct sock *lsk, s32 d2a_event)
{
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    if (sk == NULL) {
        return -EFAULT;
    }

    if (sk->status == SK_MIGRATE_A2D || sk->status == SK_MIGRATE_D2A) {
        long timeo = MAX_SCHEDULE_TIMEOUT;
        int err = sbr_wait_migrate(sk, &timeo);
        if (err) {
            NS_WAR("sk %d status %u not ready", sk->fd, sk->status);
        }

        if (sk->status != SK_MIGRATE_OK) {
            return -EINVAL;
        }
    }
    sbr_msg_retry_deinit(&sk->cork_send_timer.common);
    sbr_sk_remove_msg_wq(sk);
    NS_INF("migrate_d2a start sk_id=%lu, fd=%d d2a_event=%d", sk->sk_id, sk->fd, d2a_event);
    sk->d2a_event = d2a_event;
    s32 ret = sk->fdopt->migrate_d2a(sk);
    if (ret == 0) {
        NS_INF("sk_id=%lu, fd=%d, migrate_d2a succ", sk->sk_id, sk->fd);
        long timeo = MAX_SCHEDULE_TIMEOUT;
        ret = sbr_wait_migrate(sk, &timeo);
        if (ret) {
            NS_WAR("sk_id=%lu, fd=%d, status %u not ready", sk->sk_id, sk->fd, sk->status);
        }
        if (sk->status == SK_CLOSE) {
            return 0;
        }
        return ret;
    } else {
        NS_ERR("sk_id=%lu, fd=%d, migrate_d2a fail ret %d", sk->sk_id, sk->fd, ret);
    }
    return ret;
}

void sbr_passive_close(struct sock *lsk)
{
    sbr_socket_t *sk = sbr_lookup_sk(lsk);
    if (sk == NULL) {
        return;
    }
    if (sk->status == SK_CLOSE) {
        return;
    }

    if (!sk->is_tcp_server) {
        NS_ERR("sk_id=%lu, fd=%d, status %u", sk->sk_id, sk->fd, sk->status);
        dump_stack();
        return;
    }

    while (sk->status == SK_MIGRATE_A2D || sk->status == SK_MIGRATE_D2A) {
        release_sock(lsk);
        msleep(1);
        lock_sock(lsk);
    }

    if (sk->fd >= 0) {
        release_dpa_sk(sk);
        sk->d2a_event = D2A_EVT_NOT_ACCEPT_CLOSE;
        sbr_filter_purge(sk);
        (void)sk->fdopt->close(sk, true);
        sk->fd = -1;
    }
    sk->status = SK_CLOSE;
}

static void sbr_mem_free(sbr_socket_t *sk)
{
    struct sock *lsk = sk->sk;
    struct sk_buff *skb, *next;

    bool is_tcp = (lsk->sk_protocol == IPPROTO_TCP);
    while ((skb = skb_dequeue(&lsk->sk_write_queue)) != NULL) {
        if (is_tcp) {
            sk_wmem_queued_add(lsk, (int)(-skb->truesize));
            __kfree_skb(skb);
        } else {
            sbr_udp_send_head_free(sk, skb);
        }
    }
    sk_dra_alloc_remove(sk);
    while ((skb = skb_dequeue(&sk->dpa_queue)) != NULL) {
        if (is_tcp) {
            sk_wmem_queued_add(lsk, (int)(-skb->truesize));
        } else {
            refcount_add((int)(-skb->truesize), &lsk->sk_wmem_alloc);
        }
        __kfree_skb(skb);
    }

    spin_lock_bh(&lsk->sk_lock.slock);
    skb = sk->dpa_head;
    sk->dpa_head = sk->dpa_tail = NULL;
    spin_unlock_bh(&lsk->sk_lock.slock);

    while (skb != NULL) {
        next = skb->next;
        skb->next = NULL;
        kfree_skb(skb);
        skb = next;
    }
}

static void sbr_dpa_done(sbr_socket_t *sk)
{
    struct sk_buff *skb;
    struct sock *lsk = sk->sk;
    lock_sock(lsk);
    sk->d2a_event = D2A_EVT_DPA_RESET;
#ifdef CONFIG_DPA_CHR
    migrate_revert_stat(lsk, sk->d2a_event);
#endif
    sbr_sk_remove_msg_wq(sk);
    release_dpa_sk(sk);
    sbr_filter_purge(sk);
    conn_stats_print(sk);
    sk->status = SK_CLOSE;
    sk->fd = -1;
    sbr_mem_free(sk);
    while ((skb = skb_dequeue(&lsk->sk_receive_queue)) != NULL) {
        __kfree_skb(skb);
    }
    if (!sock_flag(lsk, SOCK_DEAD) && lsk->sk_socket && sk->save_ops) {
        WRITE_ONCE(lsk->sk_socket->ops, sk->save_ops);
    }
    WRITE_ONCE(lsk->sk_prot, sk->save_prot);
    if (inet_sk_state_load(lsk) != TCP_CLOSE) {
        if (lsk->sk_protocol == IPPROTO_TCP) {
            tcp_done(lsk);
        }
        lsk->sk_err = ECONNABORTED;
        if (!sock_flag(lsk, SOCK_DEAD)) {
            lsk->sk_error_report(lsk);
        }
    }
    release_sock(lsk);
}

void sbr_dpa_socket_reset(void)
{
    u32 i = 0;
    sbr_socket_t *sk = NULL;
    for (i = 1; i < SOCKET_NUM + 1; ++i) {
        sk = get_dpa_sk(i);
        if (sk != NULL) {
            sbr_dpa_done(sk);
            put_dpa_sk(sk);
        }
    }
}

void sbr_dpa_rst_state_set(u8 stat)
{
    g_dpa_reset = stat;
}

u8 sbr_dpa_reseting(void)
{
    return g_dpa_reset;
}

s32 sbr_close(struct sock *lsk)
{
    s32 ret;
    sbr_socket_t *sk = sbr_lookup_sk(lsk);
    if (sk == NULL) {
        return -EFAULT;
    }

    NS_INF("sk_id=%lu, fd=%d, pre status=%u", sk->sk_id, sk->fd, sk->status);
    if (sk->status == SK_CLOSE) {
        return -EALREADY;
    } else if (sk->status == SK_MIGRATE_A2D || sk->status == SK_MIGRATE_D2A) {
        long timeo = MAX_SCHEDULE_TIMEOUT;
        int err = sbr_wait_migrate(sk, &timeo);
        if (err) {
            NS_WAR("sk_id=%lu, fd=%d, status=%u not ready", sk->sk_id, sk->fd, sk->status);
        }
    }

    if (sk->fd < 0) {
        return -EALREADY;
    }
    sbr_msg_retry_deinit(&sk->cork_send_timer.common);
    sbr_sk_remove_msg_wq(sk);
    if (lsk->sk_protocol == IPPROTO_TCP && inet_sk_state_load(lsk) != TCP_CLOSE) {
        ret = sbr_migrate_d2a(lsk, D2A_EVT_CLOSE);
        if (ret == 0 && sk->fd < 0) {
            return 0;
        }
    }

    release_dpa_sk(sk);
    sbr_filter_purge(sk);
    conn_stats_print(sk);
    bool need_rst = false;
    if (!skb_queue_empty(&lsk->sk_receive_queue) && inet_sk_state_load(lsk) != TCP_CLOSE) {
        need_rst = true;
    }
    sk->status = SK_CLOSE;
    sbr_mem_free(sk);
    ret = sk->fdopt->close(sk, need_rst);
    sk->fd = -1;
    return ret;
}

s32 sbr_filter_add(sbr_socket_t *ssk, struct dpa_filter_tuple *tuple, s32 ifidx)
{
    if (ssk->sne.handle != NULL) {
        if ((ifidx == ssk->sne.ifidx) && (memcmp(&ssk->sne.tuple, tuple, sizeof(*tuple)) == 0)) {
            /* already added */
            return 0;
        }
        stack_filter_clear_flow(ssk->sne.handle);
        ssk->sne.handle = NULL;
    }
    struct filter_cb_param param;
    param.ifindex = (u32)ifidx;
    param.hash = (u32)ssk->fd;
    void *handle = stack_filter_set_flow(tuple, &param);
    if (handle == NULL) {
        NS_WAR("stack_filter_set_flow %hu-%hu fail", tuple->lport, tuple->rport);
        return -1;
    }

    ssk->sne.tuple = *tuple;
    ssk->sne.handle = handle;
    ssk->sne.ifidx = ifidx;
    bool isv6 = (tuple->is_v6 == 1);
    NS_INF("add tuple sk_id=%lu, fd=%d, uid=%u, %s-%s, %hu-%hu, ifidx=%d", ssk->sk_id, ssk->fd, ssk->sk->sk_uid.val,
        safety_in_x_addr(isv6, &tuple->laddr), safety_in_x_addr(isv6, &tuple->raddr), ntohs(ssk->sne.tuple.lport),
        ntohs(ssk->sne.tuple.rport), ifidx);
    dpa_event_report(ssk, SOCKET_A2D);
    return 0;
}

void sbr_filter_purge(sbr_socket_t *ssk)
{
    if (ssk->sne.handle != NULL) {
        struct dpa_filter_tuple *tuple = &ssk->sne.tuple;
        bool isv6 = (tuple->is_v6 == 1);
        NS_INF("del tuple, sk_id=%lu, fd=%d, uid=%u, %s-%s, %hu-%hu, ifidx=%d, d2a event=%d", ssk->sk_id, ssk->fd,
            ssk->sk->sk_uid.val, safety_in_x_addr(isv6, &tuple->laddr), safety_in_x_addr(isv6, &tuple->raddr),
            ntohs(tuple->lport), ntohs(tuple->rport), ssk->sne.ifidx, ssk->d2a_event);
        stack_filter_clear_flow(ssk->sne.handle);
        ssk->sne.handle = NULL;
    }
}

s32 sbr_init(void)
{
    dmm_spin_init(&g_dpa_sk_table_lock);
    size_t len = sizeof(sbr_socket_t *) * (SOCKET_NUM + 1);
    g_dpa_sk_table = (sbr_socket_t **)stack_malloc(len);
    if (g_dpa_sk_table == NULL) {
        return -1;
    }
    (void)memset_s(g_dpa_sk_table, len, 0, len);

    return 0;
}

s32 sbr_get_fd(struct sock *lsk)
{
    sbr_socket_t *sk = sbr_lookup_sk(lsk);
    if (sk == NULL) {
        return -1;
    }

    return sk->fd;
}

static enum opt_action action_sol_socket[] = {
    OPT_ACTION_LINUX, /* SO_DEBUG */
    OPT_ACTION_BOTH, /* SO_REUSEADDR */
    OPT_ACTION_LINUX, /* SO_TYPE */
    OPT_ACTION_LINUX, /* SO_ERROR */
    OPT_ACTION_LINUX, /* SO_DONTROUTE */
    OPT_ACTION_BOTH, /* SO_BROADCAST */
    OPT_ACTION_BOTH, /* SO_SNDBUF */
    OPT_ACTION_BOTH, /* SO_RCVBUF */
    OPT_ACTION_DPA, /* SO_KEEPALIVE */
    OPT_ACTION_LINUX, /* SO_OOBINLINE */
    OPT_ACTION_LINUX, /* SO_NO_CHECK */
    OPT_ACTION_LINUX, /* SO_PRIORITY */
    OPT_ACTION_LINUX, /* SO_LINGER */
    OPT_ACTION_LINUX, /* SO_BSDCOMPAT */
    OPT_ACTION_BOTH, /* SO_REUSEPORT */
    OPT_ACTION_LINUX, /* SO_PASSCRED */
    OPT_ACTION_LINUX, /* SO_PEERCRED */
    OPT_ACTION_LINUX, /* SO_RCVLOWAT */
    OPT_ACTION_LINUX, /* SO_SNDLOWAT */
    OPT_ACTION_LINUX, /* SO_RCVTIMEO_OLD */
    OPT_ACTION_LINUX, /* SO_SNDTIMEO_OLD */
    OPT_ACTION_LINUX, /* SO_SECURITY_AUTHENTICATION */
    OPT_ACTION_LINUX, /* SO_SECURITY_ENCRYPTION_TRANSPORT */
    OPT_ACTION_LINUX, /* SO_SECURITY_ENCRYPTION_NETWORK */
    OPT_ACTION_BOTH, /* SO_BINDTODEVICE */
    OPT_ACTION_FALLBACK, /* SO_ATTACH_FILTER */
    OPT_ACTION_FALLBACK, /* SO_DETACH_FILTER */
    OPT_ACTION_LINUX, /* SO_PEERNAME */
    OPT_ACTION_LINUX, /* SO_TIMESTAMP_OLD */
    OPT_ACTION_LINUX, /* SO_ACCEPTCONN */
    OPT_ACTION_FALLBACK, /* SO_PEERSEC */
    OPT_ACTION_LINUX, /* SO_SNDBUFFORCE */
    OPT_ACTION_LINUX, /* SO_RCVBUFFORCE */
    OPT_ACTION_FALLBACK, /* SO_PASSSEC */
    OPT_ACTION_LINUX, /* SO_TIMESTAMPNS_OLD */
    OPT_ACTION_LINUX, /* SO_MARK */
    OPT_ACTION_LINUX, /* SO_TIMESTAMPING_OLD */
    OPT_ACTION_LINUX, /* SO_PROTOCOL */
    OPT_ACTION_LINUX, /* SO_DOMAIN */
    OPT_ACTION_FALLBACK, /* SO_RXQ_OVFL */
    OPT_ACTION_FALLBACK, /* SO_WIFI_STATUS */
    OPT_ACTION_LINUX, /* SO_PEEK_OFF */
    OPT_ACTION_LINUX, /* SO_NOFCS */
    OPT_ACTION_FALLBACK, /* SO_LOCK_FILTER */
    OPT_ACTION_LINUX, /* SO_SELECT_ERR_QUEUE */
    OPT_ACTION_FALLBACK, /* SO_BUSY_POLL */
    OPT_ACTION_FALLBACK, /* SO_MAX_PACING_RATE */
    OPT_ACTION_FALLBACK, /* SO_BPF_EXTENSIONS */
    OPT_ACTION_FALLBACK, /* SO_INCOMING_CPU */
    OPT_ACTION_FALLBACK, /* SO_ATTACH_BPF */
    OPT_ACTION_FALLBACK, /* SO_ATTACH_REUSEPORT_CBPF */
    OPT_ACTION_FALLBACK, /* SO_ATTACH_REUSEPORT_EBPF */
    OPT_ACTION_FALLBACK, /* SO_CNX_ADVICE */
    OPT_ACTION_FALLBACK, /* SCM_TIMESTAMPING_OPT_STATS */
    OPT_ACTION_LINUX, /* SO_MEMINFO */
    OPT_ACTION_FALLBACK, /* SO_INCOMING_NAPI_ID */
    OPT_ACTION_LINUX, /* SO_COOKIE */
    OPT_ACTION_FALLBACK, /* SCM_TIMESTAMPING_PKTINFO */
    OPT_ACTION_LINUX, /* SO_PEERGROUPS */
    OPT_ACTION_FALLBACK, /* SO_ZEROCOPY */
    OPT_ACTION_FALLBACK, /* SO_TXTIME */
    OPT_ACTION_BOTH, /* SO_BINDTOIFINDEX */
    OPT_ACTION_LINUX, /* SO_TIMESTAMP_NEW */
    OPT_ACTION_LINUX, /* SO_TIMESTAMPNS_NEW */
    OPT_ACTION_LINUX, /* SO_TIMESTAMPING_NEW */
    OPT_ACTION_LINUX, /* SO_RCVTIMEO_NEW */
    OPT_ACTION_LINUX, /* SO_SNDTIMEO_NEW */
    OPT_ACTION_FALLBACK, /* SO_DETACH_REUSEPORT_BPF */
};

static enum opt_action action_sol_ip[] = {
    OPT_ACTION_BOTH, /* IP_TOS */
    OPT_ACTION_BOTH, /* IP_TTL */
    OPT_ACTION_LINUX, /* IP_HDRINCL */
    OPT_ACTION_FALLBACK, /* IP_OPTIONS */
    OPT_ACTION_FALLBACK, /* IP_ROUTER_ALERT */
    OPT_ACTION_FALLBACK, /* IP_RECVOPTS */
    OPT_ACTION_FALLBACK, /* IP_RETOPTS */
    OPT_ACTION_LINUX, /* IP_PKTINFO */
    OPT_ACTION_LINUX, /* IP_PKTOPTIONS */
    OPT_ACTION_LINUX, /* IP_MTU_DISCOVER */
    OPT_ACTION_LINUX, /* IP_RECVERR */
    OPT_ACTION_LINUX, /* IP_RECVTTL */
    OPT_ACTION_LINUX, /* IP_RECVTOS */
    OPT_ACTION_LINUX, /* IP_MTU */
    OPT_ACTION_LINUX, /* IP_FREEBIND */
    OPT_ACTION_FALLBACK, /* IP_IPSEC_POLICY */
    OPT_ACTION_FALLBACK, /* IP_XFRM_POLICY */
    OPT_ACTION_FALLBACK, /* IP_PASSSEC */
    OPT_ACTION_FALLBACK, /* IP_TRANSPARENT */
    OPT_ACTION_LINUX, /* IP_ORIGDSTADDR */
    OPT_ACTION_LINUX, /* IP_MINTTL */
    OPT_ACTION_LINUX, /* IP_NODEFRAG */
    OPT_ACTION_LINUX, /* IP_CHECKSUM */
    OPT_ACTION_FALLBACK, /* IP_BIND_ADDRESS_NO_PORT */
    OPT_ACTION_FALLBACK, /* IP_RECVFRAGSIZE */
    OPT_ACTION_LINUX, /* IP_RECVERR_RFC4884 */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_LINUX, /* IP_MULTICAST_IF */
    OPT_ACTION_LINUX, /* IP_MULTICAST_TTL */
    OPT_ACTION_LINUX, /* IP_MULTICAST_LOOP */
    OPT_ACTION_LINUX, /* IP_ADD_MEMBERSHIP */
    OPT_ACTION_LINUX, /* IP_DROP_MEMBERSHIP */
    OPT_ACTION_LINUX, /* IP_UNBLOCK_SOURCE */
    OPT_ACTION_LINUX, /* IP_BLOCK_SOURCE */
    OPT_ACTION_LINUX, /* IP_ADD_SOURCE_MEMBERSHIP */
    OPT_ACTION_LINUX, /* IP_DROP_SOURCE_MEMBERSHIP */
    OPT_ACTION_LINUX, /* IP_MSFILTER */
    OPT_ACTION_LINUX, /* MCAST_JOIN_GROUP */
    OPT_ACTION_LINUX, /* MCAST_BLOCK_SOURCE */
    OPT_ACTION_LINUX, /* MCAST_UNBLOCK_SOURCE */
    OPT_ACTION_LINUX, /* MCAST_LEAVE_GROUP */
    OPT_ACTION_LINUX, /* MCAST_JOIN_SOURCE_GROUP */
    OPT_ACTION_LINUX, /* MCAST_LEAVE_SOURCE_GROUP */
    OPT_ACTION_LINUX, /* MCAST_MSFILTER */
    OPT_ACTION_LINUX, /* IP_MULTICAST_ALL */
    OPT_ACTION_LINUX, /* IP_UNICAST_IF */
};

static enum opt_action action_sol_ipv6[] = {
    OPT_ACTION_FALLBACK, /* IPV6_ADDRFORM */
    OPT_ACTION_FALLBACK, /* IPV6_2292PKTINFO */
    OPT_ACTION_LINUX, /* IPV6_2292HOPOPTS */
    OPT_ACTION_FALLBACK, /* IPV6_2292DSTOPTS */
    OPT_ACTION_FALLBACK, /* IPV6_2292RTHDR */
    OPT_ACTION_FALLBACK, /* IPV6_2292PKTOPTIONS */
    OPT_ACTION_FALLBACK, /* IPV6_CHECKSUM */
    OPT_ACTION_LINUX, /* IPV6_2292HOPLIMIT */
    OPT_ACTION_LINUX, /* IPV6_NEXTHOP */
    OPT_ACTION_LINUX, /* IPV6_AUTHHDR */
    OPT_ACTION_FALLBACK, /* IPV6_FLOWINFO */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_LINUX, /* IPV6_UNICAST_HOPS */
    OPT_ACTION_LINUX, /* IPV6_MULTICAST_IF */
    OPT_ACTION_LINUX, /* IPV6_MULTICAST_HOPS */
    OPT_ACTION_LINUX, /* IPV6_MULTICAST_LOOP */
    OPT_ACTION_LINUX, /* IPV6_ADD_MEMBERSHIP */
    OPT_ACTION_LINUX, /* IPV6_DROP_MEMBERSHIP */
    OPT_ACTION_LINUX, /* IPV6_ROUTER_ALERT */
    OPT_ACTION_LINUX, /* IPV6_MTU_DISCOVER */
    OPT_ACTION_FALLBACK, /* IPV6_MTU */
    OPT_ACTION_FALLBACK, /* IPV6_RECVERR */
    OPT_ACTION_BOTH, /* IPV6_V6ONLY */
    OPT_ACTION_FALLBACK, /* IPV6_JOIN_ANYCAST */
    OPT_ACTION_FALLBACK, /* IPV6_LEAVE_ANYCAST */
    OPT_ACTION_LINUX, /* IPV6_MULTICAST_ALL */
    OPT_ACTION_FALLBACK, /* IPV6_ROUTER_ALERT_ISOLATE */
    OPT_ACTION_FALLBACK, /* IPV6_RECVERR_RFC4884 */
    OPT_ACTION_FALLBACK, /* IPV6_FLOWLABEL_MGR */
    OPT_ACTION_FALLBACK, /* IPV6_FLOWINFO_SEND */
    OPT_ACTION_FALLBACK, /* IPV6_IPSEC_POLICY */
    OPT_ACTION_FALLBACK, /* IPV6_XFRM_POLICY */
    OPT_ACTION_LINUX, /* IPV6_HDRINCL */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_LINUX, /* MCAST_JOIN_GROUP */
    OPT_ACTION_LINUX, /* MCAST_BLOCK_SOURCE */
    OPT_ACTION_LINUX, /* MCAST_UNBLOCK_SOURCE */
    OPT_ACTION_LINUX, /* MCAST_LEAVE_GROUP */
    OPT_ACTION_LINUX, /* MCAST_JOIN_SOURCE_GROUP */
    OPT_ACTION_LINUX, /* MCAST_LEAVE_SOURCE_GROUP */
    OPT_ACTION_LINUX, /* MCAST_MSFILTER */
    OPT_ACTION_LINUX, /* IPV6_RECVPKTINFO */
    OPT_ACTION_FALLBACK, /* IPV6_PKTINFO */
    OPT_ACTION_LINUX, /* IPV6_RECVHOPLIMIT */
    OPT_ACTION_LINUX, /* IPV6_HOPLIMIT */
    OPT_ACTION_FALLBACK, /* IPV6_RECVHOPOPTS */
    OPT_ACTION_LINUX, /* IPV6_HOPOPTS */
    OPT_ACTION_FALLBACK, /* IPV6_RTHDRDSTOPTS */
    OPT_ACTION_FALLBACK, /* IPV6_RECVRTHDR */
    OPT_ACTION_FALLBACK, /* IPV6_RTHDR */
    OPT_ACTION_FALLBACK, /* IPV6_RECVDSTOPTS */
    OPT_ACTION_FALLBACK, /* IPV6_DSTOPTS */
    OPT_ACTION_FALLBACK, /* IPV6_RECVPATHMTU */
    OPT_ACTION_LINUX, /* IPV6_PATHMTU */
    OPT_ACTION_FALLBACK, /* IPV6_DONTFRAG */
    OPT_ACTION_LINUX, /* IPV6_USE_MIN_MTU */
    OPT_ACTION_FALLBACK, /* IP6T_SO_SET_REPLACE */
    OPT_ACTION_FALLBACK, /* IP6T_SO_SET_ADD_COUNTERS */
    OPT_ACTION_LINUX, /* IPV6_RECVTCLASS */
    OPT_ACTION_LINUX, /* IPV6_TCLASS */
    OPT_ACTION_LINUX, /* IP6T_SO_GET_REVISION_MATCH */
    OPT_ACTION_LINUX, /* IP6T_SO_GET_REVISION_TARGET */
    OPT_ACTION_FALLBACK, /* IPV6_AUTOFLOWLABEL */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_LINUX, /* IPV6_ADDR_PREFERENCES */
    OPT_ACTION_LINUX, /* IPV6_MINHOPCOUNT */
    OPT_ACTION_LINUX, /* IPV6_ORIGDSTADDR */
    OPT_ACTION_FALLBACK, /* IPV6_TRANSPARENT */
    OPT_ACTION_LINUX, /* IPV6_UNICAST_IF */
    OPT_ACTION_FALLBACK, /* IPV6_RECVFRAGSIZE */
    OPT_ACTION_LINUX, /* IPV6_FREEBIND */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_LINUX, /* IP6T_SO_ORIGINAL_DST */
};

static enum opt_action action_sol_tcp[] = {
    OPT_ACTION_BOTH, /* TCP_NODELAY */
    OPT_ACTION_LINUX, /* TCP_MAXSEG */
    OPT_ACTION_LINUX, /* TCP_CORK */
    OPT_ACTION_DPA, /* TCP_KEEPIDLE */
    OPT_ACTION_DPA, /* TCP_KEEPINTVL */
    OPT_ACTION_DPA, /* TCP_KEEPCNT */
    OPT_ACTION_LINUX, /* TCP_SYNCNT */
    OPT_ACTION_LINUX, /* TCP_LINGER2 */
    OPT_ACTION_LINUX, /* TCP_DEFER_ACCEPT */
    OPT_ACTION_LINUX, /* TCP_WINDOW_CLAMP */
    OPT_ACTION_DPA, /* TCP_INFO */
    OPT_ACTION_DPA, /* TCP_QUICKACK */
    OPT_ACTION_LINUX, /* TCP_CONGESTION */
    OPT_ACTION_FALLBACK, /* TCP_MD5SIG */
    OPT_ACTION_FALLBACK, /* UNUSED */
    OPT_ACTION_BOTH, /* TCP_THIN_LINEAR_TIMEOUTS */
    OPT_ACTION_LINUX, /* TCP_THIN_DUPACK */
    OPT_ACTION_LINUX, /* TCP_USER_TIMEOUT */
    OPT_ACTION_FALLBACK, /* TCP_REPAIR */
    OPT_ACTION_FALLBACK, /* TCP_REPAIR_QUEUE */
    OPT_ACTION_FALLBACK, /* TCP_QUEUE_SEQ */
    OPT_ACTION_FALLBACK, /* TCP_REPAIR_OPTIONS */
    OPT_ACTION_LINUX, /* TCP_FASTOPEN */
    OPT_ACTION_FALLBACK, /* TCP_TIMESTAMP */
    OPT_ACTION_LINUX, /* TCP_NOTSENT_LOWAT */
    OPT_ACTION_FALLBACK, /* TCP_CC_INFO */
    OPT_ACTION_LINUX, /* TCP_SAVE_SYN */
    OPT_ACTION_LINUX, /* TCP_SAVED_SYN */
    OPT_ACTION_FALLBACK, /* TCP_REPAIR_WINDOW */
    OPT_ACTION_LINUX, /* TCP_FASTOPEN_CONNECT */
    OPT_ACTION_FALLBACK, /* TCP_ULP */
    OPT_ACTION_FALLBACK, /* TCP_MD5SIG_EXT */
    OPT_ACTION_LINUX, /* TCP_FASTOPEN_KEY */
    OPT_ACTION_LINUX, /* TCP_FASTOPEN_NO_COOKIE */
    OPT_ACTION_FALLBACK, /* TCP_ZEROCOPY_RECEIVE */
    OPT_ACTION_FALLBACK, /* TCP_INQ */
    OPT_ACTION_LINUX, /* TCP_TX_DELAY */
};

enum opt_action sbr_sockopt_get_action(int level, int optname)
{
    int idx = optname - 1;
    if (level == SOL_SOCKET) {
#ifdef CONFIG_LIBLINUX
        if (optname == SO_EVENTS) {
            return OPT_ACTION_LINUX;
        }
#endif
        if (idx >= 0 && idx < ARRAY_SIZE(action_sol_socket)) {
            return action_sol_socket[idx];
        }
        return OPT_ACTION_FALLBACK;
    } else if (level == SOL_IP) {
        if (idx >= 0 && idx < ARRAY_SIZE(action_sol_ip)) {
            return action_sol_ip[idx];
        }
        return OPT_ACTION_FALLBACK;
    } else if (level == SOL_IPV6) {
        if (idx >= 0 && idx < ARRAY_SIZE(action_sol_ipv6)) {
            return action_sol_ipv6[idx];
        }
        return OPT_ACTION_FALLBACK;
    } else if (level == SOL_TCP) {
        if (idx >= 0 && idx < ARRAY_SIZE(action_sol_tcp)) {
            return action_sol_tcp[idx];
        }
        return OPT_ACTION_FALLBACK;
    } else if (level == SOL_UDP) {
        if (optname == UDP_CORK || optname == UDP_GRO || optname == UDP_SEGMENT) {
            return OPT_ACTION_LINUX;
        }
        return OPT_ACTION_FALLBACK;
    }
    return OPT_ACTION_FALLBACK;
}

bool sbr_sockopt_is_support(int level, int optname)
{
    return (sbr_sockopt_get_action(level, optname) != OPT_ACTION_FALLBACK);
}
