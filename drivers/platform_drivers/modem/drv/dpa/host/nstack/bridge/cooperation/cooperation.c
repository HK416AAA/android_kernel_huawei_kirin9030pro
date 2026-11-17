/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include <net/if_inet6.h>
#include <net/addrconf.h>
#include <net/netevent.h>
#include <net/route.h>
#include <net/ip6_route.h>
#include <net/tcp.h>
#include <net/checksum.h>
#include <net/net_namespace.h>
#include <linux/netdevice.h>
#include <linux/inetdevice.h>
#include <linux/route.h>
#include <linux/notifier.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include "common_msg.h"
#include "msg/bridge_msg_api.h"
#include "msg/bridge_msg_producer.h"
#include "socket/sbr_protocol_api.h"
#include "socket/sbr_prot_com.h"
#include "dfx/conn_stats.h"
#include "dfx/global_res_stats.h"
#include "dfx/chr_stats.h"
#include "sys_ifidx_convert.h"
#include "cooperation/cooperation.h"
#ifdef CONFIG_DPA_PROTO
#include <platform_include/basicplatform/linux/hck/net/hck_dpa.h>
#endif

extern mring_handle get_instance_control_box(u16 thread_index);

static struct list_head g_coop_migrate_a2d_list;
static dmm_spinlock_t g_coop_migrate_a2d_list_lock;
static volatile u8 g_dpa_cpu_overload_times = 0;

void coop_migrate_add(struct sbr_socket *ssk)
{
    dmm_spin_lock(&g_coop_migrate_a2d_list_lock);
    list_add_tail(&ssk->migrate_wait_list, &g_coop_migrate_a2d_list);
    dmm_spin_unlock(&g_coop_migrate_a2d_list_lock);
}

void coop_migrate_remove(struct sbr_socket *ssk)
{
    dmm_spin_lock(&g_coop_migrate_a2d_list_lock);
    list_del(&ssk->migrate_wait_list);
    dmm_spin_unlock(&g_coop_migrate_a2d_list_lock);
}

struct sbr_socket *coop_pop_migrate_id(u64 migrate_id)
{
    struct sbr_socket *ssk;
    dmm_spin_lock(&g_coop_migrate_a2d_list_lock);
    list_for_each_entry(ssk, &g_coop_migrate_a2d_list, migrate_wait_list) {
        if (ssk->sk_id == migrate_id) {
            list_del(&ssk->migrate_wait_list);
            sock_hold(ssk->sk);
            dmm_spin_unlock(&g_coop_migrate_a2d_list_lock);
            return ssk;
        }
    }
    dmm_spin_unlock(&g_coop_migrate_a2d_list_lock);
    return NULL;
}

s32 coop_filter_add(struct sock *sk)
{
    ip_addr_t sip = {0};
    ip_addr_t rip = {0};
    struct dpa_filter_tuple tuple = {0};
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    get_sk_addr(sk, false, &sip);
    get_sk_addr(sk, true, &rip);
    tuple.is_v6 = (sip.type == SPL_IP_ADDR_TYPE_V6) ? 1 : 0;
    if (tuple.is_v6) {
        (void)memcpy_s(&tuple.laddr.addr6, sizeof(tuple.laddr.addr6), &sip.ip6.addr, sizeof(sip.ip6.addr));
        (void)memcpy_s(&tuple.raddr.addr6, sizeof(tuple.raddr.addr6), &rip.ip6.addr, sizeof(rip.ip6.addr));
    } else {
        tuple.laddr.addr4.s_addr = sip.addr;
        tuple.raddr.addr4.s_addr = rip.addr;
    }
    tuple.lport = ntohs(sk->sk_num);
    tuple.rport = sk->sk_dport;
    tuple.is_tcp = sk->sk_protocol == IPPROTO_TCP ? 1 : 0;
    return sbr_filter_add(ssk, &tuple, ssk->ifidx);
}

static void coop_get_flowlabel(struct sock *sk, msg_common_migrate *comm)
{
    struct net *net = sock_net(sk);
    struct inet_sock *inet = inet_sk(sk);
    struct ipv6_pinfo *np = inet6_sk(sk);
    struct flowi6 fl6;

    (void)memset_s(&fl6, sizeof(fl6), 0, sizeof(fl6));
    fl6.flowi6_proto = (u8)sk->sk_protocol;
    fl6.daddr = sk->sk_v6_daddr;
    fl6.saddr = np->saddr;
    fl6.flowlabel = np->flow_label;
    IP6_ECN_flow_xmit(sk, fl6.flowlabel);
    fl6.flowi6_oif = sk->sk_bound_dev_if;
    fl6.flowi6_mark = sk->sk_mark;
    fl6.fl6_sport = inet->inet_sport;
    fl6.fl6_dport = inet->inet_dport;
    fl6.flowi6_uid = sk->sk_uid;
    security_sk_classify_flow(sk, flowi6_to_flowi(&fl6));

    __be32 flowlabel = fl6.flowlabel & IPV6_FLOWLABEL_MASK;
    comm->flowlabel = flowlabel;
    comm->is_auto_fl = 1;

    u16 is_autoflowlabel;
    if (!np->autoflowlabel_set) {
        is_autoflowlabel = (u16)ip6_default_np_autolabel(net);
    } else {
        is_autoflowlabel = np->autoflowlabel;
    }
    if (flowlabel || net->ipv6.sysctl.auto_flowlabels == IP6_AUTO_FLOW_LABEL_OFF ||
        (is_autoflowlabel == 0 && net->ipv6.sysctl.auto_flowlabels != IP6_AUTO_FLOW_LABEL_FORCED)) {
        comm->is_auto_fl = 0;
        return;
    }

    u32 hash = READ_ONCE(sk->sk_txhash);
    if (hash == 0) {
        struct flow_keys keys;
        hash = __get_hash_from_flowi6(&fl6, &keys);
    }
    comm->tx_hash = hash;
    comm->fl_stateless_flag = 0;
    if (net->ipv6.sysctl.flowlabel_state_ranges) {
        comm->fl_stateless_flag = IPV6_FLOWLABEL_STATELESS_FLAG;
    }
}

static s32 coop_comm_migrate_a2d(msg_common_migrate *comm, struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    if (sk->sk_bound_dev_if > 0) {
        if (!is_nic_valid_check_by_id((u8)sk->sk_bound_dev_if)) {
            NS_ERR("sk_id=%lu, fd=%d, phy_ifidx %u is invalid", ssk->sk_id, ssk->fd, (u8)sk->sk_bound_dev_if);
            return -ENODEV;
        }
    }
    comm->is_tcp = sk->sk_protocol == IPPROTO_TCP ? 1 : 0;
    comm->ipv6_only = sk->sk_ipv6only;
    comm->pmtudisc = inet_sk(sk)->pmtudisc;
    comm->bind_netif_id = (u8)sk->sk_bound_dev_if;
    comm->sk_mark = sk->sk_mark;
    comm->send_bufsize = sk->sk_sndbuf >> 1;
    /* use v4 addr and AF_INET family in stack if addr is IPV6_ADDR_MAPPED */
    u32 src_type = get_sk_addr(sk, false, &comm->sip);
    u32 dst_type = get_sk_addr(sk, true, &comm->rip);
    if (src_type != dst_type) {
        NS_ERR("sk_id=%lu, fd=%d, addr type not match, src=%u, dst=%u",
            ssk->sk_id, ssk->fd, src_type, dst_type);
        return -1;
    }
    if (dst_type == IPV6_ADDR_MAPPED) {
        NS_INF("sk_id=%lu, fd=%d, use IPv4-mapped IPv6 address", ssk->sk_id, ssk->fd);
        ssk->is_mapped_v6 = true;
    }
    comm->ipv6 = (sbr_sk_isv6(ssk) && !ssk->is_mapped_v6) ? 1 : 0;
    comm->tos = inet_sk(sk)->tos;
    if (comm->ipv6 == 0) {
        struct inet_sock *inet = inet_sk(sk);
        s32 ttl = inet->uc_ttl;
        if (ttl < 0) {
            struct rtable *rt = (struct rtable *)sk_dst_check(sk, 0);
            if (rt == NULL) {
                NS_ERR("sk_id=%lu, fd=%d, no rtable", ssk->sk_id, ssk->fd);
                return -EHOSTUNREACH;
            }
            ttl = ip4_dst_hoplimit(&rt->dst);
            dst_release((struct dst_entry *)rt);
        }
        comm->ttl = (u8)ttl;
    } else {
        const struct ipv6_pinfo *np = inet6_sk(sk);
        s32 hlimit = -1;
        if (np != NULL) {
            hlimit = np->hop_limit;
        }
        if (hlimit < 0) {
            struct dst_entry *dst = sk_dst_check(sk, inet6_sk(sk)->dst_cookie);
            if (dst == NULL) {
                NS_ERR("sk_id=%lu, fd=%d, no rtable", ssk->sk_id, ssk->fd);
                return -EHOSTUNREACH;
            }
            hlimit = ip6_dst_hoplimit(dst);
            dst_release(dst);
        }
        comm->ttl = (u8)hlimit;
        comm->tos = np->tclass;
        coop_get_flowlabel(sk, comm);
    }
    comm->mc_ttl = inet_sk(sk)->mc_ttl;
    comm->inet_id = inet_sk(sk)->inet_id;
    if (!ssk->is_tcp_server) {
        comm->inet_id++;
    }
    comm->sport = sk->sk_num;
    comm->dport = ntohs(sk->sk_dport);
    comm->uid = sk->sk_uid.val;

    comm->so_debug = sock_flag(sk, SOCK_DBG) ? 1 : 0;
    comm->so_reuse_addr = sk->sk_reuse ? 1 : 0;
    comm->so_reuse_port = sk->sk_reuseport ? 1 : 0;
    comm->so_dontroute = sock_flag(sk, SOCK_LOCALROUTE) ? 1 : 0;
    comm->so_keepalive = sock_flag(sk, SOCK_KEEPOPEN) ? 1 : 0;
    comm->so_broadcast = sock_flag(sk, SOCK_BROADCAST) ? 1 : 0;
    comm->so_urginline = sock_flag(sk, SOCK_KEEPOPEN) ? 1 : 0;

    coop_migrate_add(ssk);
    comm->sk_id = ssk->sk_id;
    return 0;
}

static bool check_dev_match(struct sock *sk, struct net_device *dev, bool is_v6)
{
    bool match = false;

    rcu_read_lock();
    if (is_v6) {
        struct inet6_ifaddr *ifa;
        struct inet6_dev *idev = __in6_dev_get(dev);
        if (!idev) {
            goto out;
        }

        list_for_each_entry_rcu(ifa, &idev->addr_list, if_list) {
            if ((ifa->flags & IFA_F_TENTATIVE) &&
                (!(ifa->flags & IFA_F_OPTIMISTIC)))
                continue;

            if (memcmp(&ifa->addr, &sk->sk_v6_rcv_saddr, sizeof(struct in6_addr)) == 0) {
                match = true;
                goto out;
            }
        }
    } else {
        struct in_ifaddr *ifa;
        struct in_device *in_dev = __in_dev_get_rcu(dev);
        if (!in_dev) {
            goto out;
        }

        in_dev_for_each_ifa_rcu(ifa, in_dev) {
            if (ifa->ifa_flags & IFA_F_SECONDARY)
                continue;

            if (ifa->ifa_local == sk->sk_rcv_saddr) {
                match = true;
                goto out;
            }
        }
    }
out:
    rcu_read_unlock();
    return match;
}

static bool coop_tcp_migrate_a2d_unsupport(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    int addr_type = 0;
    if (sbr_sk_isv6(ssk)) {
        addr_type = ipv6_addr_type(&sk->sk_v6_daddr);
        if ((u32)addr_type & IPV6_ADDR_LOOPBACK) {
            NS_INF("sk_id=%lu, fd=%d,skip IPV6_ADDR_LOOPBACK", ssk->sk_id, ssk->fd);
            return true;
        }
    }
    if (sbr_sk_isv6(ssk) && ((u32)addr_type != IPV6_ADDR_MAPPED)) {
        struct dst_entry *dst;
        bool support = true;
        dst = sk_dst_check(sk, inet6_sk(sk)->dst_cookie);
        if (dst) {
            struct rt6_info *rt6 = (struct rt6_info *)dst;
            const struct in6_addr *nexthop_in6 = rt6_nexthop(rt6, &sk->sk_v6_daddr);
            spl_ip6_addr_cast_from_in6addr(&ssk->nexthop.ip6, (struct spl_in6_addr *)nexthop_in6);
            spl_ip_addr_set_type(&ssk->nexthop, SPL_IP_ADDR_TYPE_V6);
            NS_DBG("flags=%u, in6_addr=%x:*:*:*:*:*:*:%x", rt6->rt6i_flags, FUZZY_IPV6_VAR(&ssk->nexthop.ip6));
            ssk->ifidx = dst->dev->ifindex;
            if (!check_dev_match(sk, dst->dev, true)) {
                NS_WAR("sk_id=%lu dst dev %s not match saddr", ssk->sk_id, dst->dev->name);
                support = false;
            } else if (!is_nic_valid_check_by_id(dst->dev->ifindex)) {
                NS_DBG("skip iface %s", dst->dev->name);
                support = false;
            }
            dst_release(dst);
            if (!is_nic_valid_check_by_id(ssk->ifidx)) {
                NS_ERR("sk_id=%lu, fd=%d, fdphy_ifidx %d is invalid", ssk->sk_id, ssk->fd, ssk->ifidx);
                return true;
            }
        } else {
            NS_ERR("sk_id=%lu, fd=%d, no dst_entry", ssk->sk_id, ssk->fd);
            support = false;
        }
        return !support;
    } else {
        u16 rt_type;
        struct rtable *rt = (struct rtable *)sk_dst_check(sk, 0);
        if (rt == NULL) {
            NS_ERR("sk_id=%lu, fd=%d, no rtable", ssk->sk_id, ssk->fd);
            return true;
        }
        ssk->nexthop.addr = rt_nexthop(rt, sk->sk_daddr);
        spl_ip_addr_set_type(&ssk->nexthop, SPL_IP_ADDR_TYPE_V4);
        NS_DBG("gw family=%u, *.*.%u.%u", rt->rt_gw_family, FUZZY_IP_VAR(&ssk->nexthop.addr));
        rt_type = rt->rt_type;
        ssk->ifidx = (s32)rt->dst.dev->ifindex;
        if (!check_dev_match(sk, rt->dst.dev, false)) {
            NS_WAR("sk_id=%lu dst dev %s not match saddr", ssk->sk_id, rt->dst.dev->name);
            dst_release((struct dst_entry *)rt);
            return true;
        }
        if (!is_nic_valid_check_by_id(rt->dst.dev->ifindex)) {
            NS_DBG("skip iface %s", rt->dst.dev->name);
            dst_release((struct dst_entry *)rt);
            return true;
        }
        dst_release((struct dst_entry *)rt);

        if (rt_type != RTN_UNICAST) {
            NS_ERR("sk_id=%lu, fd=%d, rt_type %u not support", ssk->sk_id, ssk->fd, rt_type);
            return true;
        }
        if (!is_nic_valid_check_by_id(ssk->ifidx)) {
            NS_ERR("sk_id=%lu, fd=%d, phy_ifidx %d is invalid", ssk->sk_id, ssk->fd, ssk->ifidx);
            return true;
        }
    }

    return false;
}

void coop_migrate_wakeup(const struct sock *sk)
{
    struct socket_wq *wq;

    smp_mb();
    rcu_read_lock();
    wq = rcu_dereference(sk->sk_wq);
    if (skwq_has_sleeper(wq))
        wake_up_all(&wq->wait);
    rcu_read_unlock();
}

void coop_migrate_d2a_fail(sbr_socket_t *ssk, bool slock, int errcode)
{
    struct sock *sk = ssk->sk;
    struct sk_buff *skb;

    NS_WAR("fd=%d, coop_tcp_d2a_resp fail errcode %d", ssk->fd, errcode);
    ssk->status = SK_CLOSE;
    sk->sk_err = ECONNABORTED;
    if (inet_sk_state_load(sk) != TCP_CLOSE) {
        tcp_done(sk);
    }
    migrate_revert(sk, slock, false);
    while ((skb = skb_dequeue(&sk->sk_write_queue)) != NULL) {
        sk_wmem_queued_add(sk, (int)(-skb->truesize));
        __kfree_skb(skb);
    }
    sk_dra_alloc_remove(ssk);
    while ((skb = skb_dequeue(&ssk->dpa_queue)) != NULL) {
        sk_wmem_queued_add(sk, (int)(-skb->truesize));
        __kfree_skb(skb);
    }
    release_dpa_sk(ssk);
    conn_stats_print(ssk);

    ssk->fd = -1;
    if (!sock_flag(sk, SOCK_DEAD)) {
        sk->sk_error_report(sk);
    }
    coop_migrate_wakeup(sk);
}

#define MIGRATE_TIMEOUT HZ

static void coop_backlog_rcv(struct sock *sk)
{
    struct sk_buff *skb, *next;

    skb = sk->sk_backlog.head;
    sk->sk_backlog.head = sk->sk_backlog.tail = NULL;
    sk->sk_backlog.len = 0;

    while (skb != NULL) {
        next = skb->next;
        skb_mark_not_on_list(skb);
        sk_backlog_rcv(sk, skb);
        skb = next;
    }
}

static void migrate_timer(struct timer_list *t)
{
    sbr_socket_t *ssk = container_of(t, sbr_socket_t, timer);
    struct sock *sk = ssk->sk;

    /* Only process if socket is not in use. */
    bh_lock_sock(sk);
    if (time_after(ssk->timeout, jiffies)) {
        sk_reset_timer(sk, &ssk->timer, ssk->timeout);
        goto out;
    }

    if (sock_owned_by_user(sk)) {
        /* Try again later. */
        sk_reset_timer(sk, &ssk->timer, jiffies + 1);
        goto out;
    }

    if (ssk->migrate_pend == MIGRATE_TIMER_A2D && ssk->status == SK_MIGRATE_A2D) {
        coop_migrate_remove(ssk);
        ssk->d2a_event = D2A_EVT_A2D_TIMEOUT;
        ip_addr_t sip = {0};
        ip_addr_t rip = {0};
        get_sk_addr(sk, false, &sip);
        get_sk_addr(sk, true, &rip);
        NS_WAR("D2A_EVT_A2D_TIMEOUT, sk_id=%lu, fd=%d, uid=%u, %s-%s, %hu-%hu, ifidx=%d, d2a event=%d", ssk->sk_id,
            ssk->fd, sk->sk_uid.val, ip_safety_x(&sip), ip_safety_x(&rip), sk->sk_num, ntohs(sk->sk_dport),
            ssk->ifidx, ssk->d2a_event);
        coop_migrate_a2d_fail(sk, false, ssk->d2a_event);
        coop_migrate_wakeup(sk);
        if (sk->sk_backlog.tail) {
            NS_DBG("flush sock");
            coop_backlog_rcv(sk);
        }
    } else if (ssk->migrate_pend == MIGRATE_TIMER_A2D_BACKLOG && ssk->status == SK_MIGRATE_A2D) {
        ssk->status = SK_MIGRATE_OK;
        coop_migrate_a2d_backlog(sk, 1, false);
        coop_migrate_wakeup(sk);
        NS_INF("sk_id=%lu, fd=%d, SK_MIGRATE_OK", ssk->sk_id, ssk->fd);
    } else if (ssk->migrate_pend == MIGRATE_TIMER_D2A && ssk->status == SK_MIGRATE_D2A) {
        NS_WAR("sk_id=%lu, fd=%d, SK_MIGRATE_D2A timeout", ssk->sk_id, ssk->fd);
        coop_migrate_d2a_fail(ssk, false, -ETIMEDOUT);
        coop_migrate_wakeup(sk);
    }

out:
    bh_unlock_sock(sk);
    sock_put(sk);
}

static void rcv_fin_rst_timer(struct timer_list *t)
{
    sbr_socket_t *ssk = container_of(t, sbr_socket_t, fin_rst_tmr);
    struct sock *sk = ssk->sk;

    /* Only process if socket is not in use. */
    bh_lock_sock(sk);
    if (sock_owned_by_user(sk)) {
        /* Try again later. */
        sk_reset_timer(sk, &ssk->fin_rst_tmr, jiffies + 1);
        goto out;
    }

    if (ssk->status == SK_MIGRATE_OK) {
        sbr_msg_retry_deinit(&ssk->cork_send_timer.common);
        sbr_sk_remove_msg_wq(ssk);
        ssk->d2a_event = (ssk->rcv_fin_rst == RCV_FIN) ? D2A_EVT_RCV_FIN : D2A_EVT_RCV_RST;
        s32 ret = ssk->fdopt->migrate_d2a(ssk);
        if (ret == 0) {
            NS_INF("sk_id=%lu, fd=%d migrate_d2a succ", ssk->sk_id, ssk->fd);
        } else {
            NS_ERR("sk_id=%lu, fd=%d migrate_d2a fail ret %d", ssk->sk_id, ssk->fd, ret);
        }
    }

out:
    bh_unlock_sock(sk);
    sock_put(sk);
}

static void coop_migrate_timer_init(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;

    timer_setup(&ssk->timer, migrate_timer, 0);
    ssk->migrate_pend = 0;
    timer_setup(&ssk->fin_rst_tmr, rcv_fin_rst_timer, 0);
}

void coop_migrate_timer_reset(struct sock *sk, u8 type, u32 timeout)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    ssk->migrate_pend = type;
    ssk->timeout = jiffies + timeout;
    sk_reset_timer(sk, &ssk->timer, ssk->timeout);
}

s32 coop_tcp_migrate_a2d(struct sock *sk)
{
    struct tcp_sock *tp = tcp_sk(sk);
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;

    if (coop_tcp_migrate_a2d_unsupport(sk)) {
        return -EOPNOTSUPP;
    }
    if (g_dpa_cpu_overload_times > 0) {
        ssk->d2a_event = D2A_EVT_CPU_OVERLOAD;
#ifdef CONFIG_DPA_CHR
        migrate_fail_stat(ssk->sk, ssk->d2a_event);
#endif
        return -EBUSY;
    }
    data_com_msg *pmsg = sbr_msg_malloc(false);
    if (pmsg == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, could not allocate pmsg", ssk->sk_id, ssk->fd);
        return -ENOMEM;
    }

    pmsg->param.type = MIGRATE_A2D;
    pmsg->param.op_type = MSG_ASYN_POST;
    pmsg->param.buffer_len = (u32)MSG_SIZE(sizeof(msg_tcp_migrate_a2d));

    msg_tcp_migrate_a2d *m = (msg_tcp_migrate_a2d *)pmsg->buffer;
    s32 ret = coop_comm_migrate_a2d(&m->comm, sk);
    if (ret != 0) {
        sbr_msg_free(pmsg, true);
        return ret;
    }
    m->nexthop = ssk->nexthop;
    m->shutdown = sk->sk_shutdown;
    m->nagle_off = (tp->nonagle & TCP_NAGLE_OFF) ? 1 : 0;
    m->tcp_quick_ack = !inet_csk_in_pingpong_mode(sk);
    m->thin_lto = tp->thin_lto;
    m->sack = (tp->rx_opt.sack_ok != 0) ? 1 : 0;
    m->tstamp = tp->rx_opt.tstamp_ok;
    m->wscale = tp->rx_opt.wscale_ok;

    m->rcv_nxt = tp->rcv_nxt;
    m->rcv_wnd = tp->rcv_wnd;

    m->peer_mss = tp->rx_opt.mss_clamp;
    m->effmss = (u16)tp->mss_cache;
    m->user_defined_mss = tp->rx_opt.user_mss;
    m->snd_rtt_est.sa = tp->srtt_us;
    m->snd_rtt_est.sv = tp->rttvar_us;
    m->snd_cwnd = tp->snd_cwnd;
    m->snd_ssthresh = tp->snd_ssthresh;

    m->snd_nxt = tp->snd_nxt;
    m->snd_wnd = tp->snd_wnd;
    m->keep_idle = (u32)keepalive_time_when(tp) / HZ;
    m->keep_cnt = (u32)keepalive_probes(tp);
    m->keep_intvl = (u32)keepalive_intvl_when(tp) / HZ;

    m->linger2 = tp->linger2;
    if (m->linger2 >= 0) {
        m->linger2 = (m->linger2 ? : sock_net(sk)->ipv4.sysctl_tcp_fin_timeout) / HZ;
    }
    m->ws_shift_cnt_w = tp->rx_opt.snd_wscale;
    m->ws_shift_cnt_r = tp->rx_opt.rcv_wscale;
    m->recv_buf_flag = (sk->sk_userlocks & SOCK_RCVBUF_LOCK) ? 1 : 0;
    m->rcv_bufsize = round_down(sk->sk_rcvbuf, tp->mss_cache) >> 1;
    m->ts_recent = tp->rx_opt.ts_recent;

    u64 val = tcp_clock_ns();
    tp->tcp_clock_cache = val;
    tp->tcp_mstamp = div_u64(val, NSEC_PER_USEC);
    m->ts_now = (u32)(tcp_ns_to_ts(max(tp->tcp_wstamp_ns, tp->tcp_clock_cache)) + tp->tsoffset);
    m->ifidx = ssk->ifidx;

    ret = msg_try_post(pmsg, sbr_get_msg_box(ssk));
    if (ret < 0) {
        ssk->d2a_event = D2A_EVT_A2D_MSG_FAIL;
#ifdef CONFIG_DPA_CHR
        migrate_fail_stat(ssk->sk, ssk->d2a_event);
#endif
        sbr_migrate_a2d_msg_failed_inc();
        coop_migrate_remove(ssk);
        NS_ERR("sk_id=%lu, fd=%d, failed to post msg", ssk->sk_id, ssk->fd);
        return -ENOMEM;
    }
    sbr_migrate_a2d_msg_success_inc();

    coop_migrate_timer_init(sk);
    coop_migrate_timer_reset(sk, MIGRATE_TIMER_A2D, MIGRATE_TIMEOUT);
    NS_INF("sk_id=%lu, fd=%d, MIGRATE_A2D sent", ssk->sk_id, ssk->fd);
    /* sk ref will dec in _stack_migrate_resp()  */
    return 0;
}

static bool migrate_add_backlog(struct sock *sk, struct sk_buff *skb)
{
    u32 limit = READ_ONCE(sk->sk_rcvbuf) + READ_ONCE(sk->sk_sndbuf);
    skb_dst_drop(skb);

    if (unlikely(tcp_checksum_complete(skb))) {
        __TCP_INC_STATS(sock_net(sk), TCP_MIB_CSUMERRORS);
        __TCP_INC_STATS(sock_net(sk), TCP_MIB_INERRS);
        return true;
    }

    /* Only socket owner can try to collapse/prune rx queues
     * to reduce memory overhead, so add a little headroom here.
     * Few sockets backlog are possibly concurrently non empty.
     */
    limit += (u16)-1;

    if (unlikely(sk_add_backlog(sk, skb, limit))) {
        __NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPBACKLOGDROP);
        return true;
    }
    return false;
}

void migrate_revert(struct sock *sk, bool slock, bool backlog)
{
    struct inet_sock *inet = inet_sk(sk);
    struct sbr_socket *ssk = inet->dpa_ctx;
    struct sk_buff *skb, *next;

    sk_stop_timer(sk, &ssk->fin_rst_tmr);
    sbr_filter_purge(ssk);
    if (slock) {
        spin_lock_bh(&sk->sk_lock.slock);
    }
    ssk->status = SK_CLOSE;
    skb = ssk->dpa_head;
    ssk->dpa_head = ssk->dpa_tail = NULL;
    if (!sock_flag(sk, SOCK_DEAD) && sk->sk_socket && ssk->save_ops) {
        WRITE_ONCE(sk->sk_socket->ops, ssk->save_ops);
    }
    WRITE_ONCE(sk->sk_prot, ssk->save_prot);
    if (slock) {
        spin_unlock_bh(&sk->sk_lock.slock);
    }

    while (skb != NULL) {
        next = skb->next;
        skb->next = NULL;
        if (backlog) {
            if (migrate_add_backlog(sk, skb)) {
                sk_drops_add(sk, skb);
                kfree_skb(skb);
            }
        } else {
            kfree_skb(skb);
        }
        skb = next;
    }
}

void coop_migrate_a2d_fail(struct sock *sk, bool slock, s32 errcode)
{
    migrate_revert(sk, slock, true);
    sbr_migrate_a2d_failed_inc();

#ifdef CONFIG_DPA_CHR
    migrate_fail_stat(sk, errcode);
    get_sbr_chr_stats()->flow_num_in_kernel++;
#endif
}

s32 coop_tcp_migrate_d2a(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;

    if (ssk->status != SK_MIGRATE_OK || sk->sk_state == TCP_CLOSE) {
        NS_INF("sk_id=%lu, fd=%d, status %u sk_state %u skip migrate_d2a",
            ssk->sk_id, ssk->fd, ssk->status, sk->sk_state);
        return -EPIPE;
    }
    ssk->migrate_ts = div_u64(ktime_get_ns(), NSEC_PER_USEC);
    data_com_msg *pmsg = sbr_msg_malloc(false);
    if (pmsg == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, could not allocate pmsg", ssk->sk_id, ssk->fd);
        return -ENOMEM;
    }

    pmsg->param.type = MIGRATE_D2A;
    pmsg->param.op_type = MSG_ASYN_POST;
    pmsg->param.fd = ssk->fd;
    pmsg->param.buffer_len = (u32)MSG_SIZE(0);

    int ret = msg_try_post(pmsg, sbr_get_msg_box(ssk));
    if (ret < 0) {
        sbr_msg_migrate_d2a_failed_inc();
        NS_ERR("sk_id=%lu, fd=%d, failed to post msg", ssk->sk_id, ssk->fd);
        return -ENOMEM;
    }
    ssk->status = SK_MIGRATE_D2A;
    sbr_filter_purge(ssk);
    sbr_msg_migrate_d2a_success_inc();

    coop_migrate_timer_reset(sk, MIGRATE_TIMER_D2A, MIGRATE_TIMEOUT);
    return 0;
}

static struct sk_buff *coop_tcp_write_alloc_skb(struct sock *sk, int size, gfp_t gfp)
{
    struct sk_buff *skb;
    int align_size;

    /* The TCP header must be at least 32-bit aligned.  */
    align_size = ALIGN(size, 4);

    skb = alloc_skb_fclone((u32)align_size + sk->sk_prot->max_header, gfp);
    if (likely(skb)) {
        sk_wmem_schedule(sk, skb->truesize);
        skb_reserve(skb, sk->sk_prot->max_header);
        /*
         * Make sure that we have exactly size bytes
         * available to the caller, no more, no less.
         */
        skb->reserved_tailroom = skb->end - skb->tail - align_size;
        (void)skb_put(skb, (u32)size);
        INIT_LIST_HEAD(&skb->tcp_tsorted_anchor);
        return skb;
    }
    return NULL;
}

static void coop_wskb_fill_cb(struct sk_buff *skb, u32 seq, u32 end_seq, u8 tcp_flags)
{
    struct tcp_skb_cb *tcb = TCP_SKB_CB(skb);

    skb->csum = 0;
    tcb->seq = seq;
    tcb->end_seq = end_seq;
    tcb->tcp_flags = tcp_flags;
    tcb->sacked  = 0;
    tcp_skb_pcount_set(skb, 1);
    tcb->tcp_gso_size = 0;
    __skb_header_release(skb);
}

static void coop_wskb_entail(struct sock *sk, struct sk_buff *skb)
{
    struct tcp_sock *tp = tcp_sk(sk);

    __skb_queue_tail(&sk->sk_write_queue, skb);
    sk_wmem_queued_add(sk, skb->truesize);
    sk_mem_charge(sk, skb->truesize);
    if (tp->nonagle & TCP_NAGLE_PUSH)
        tp->nonagle &= ~TCP_NAGLE_PUSH;
}

static void coop_tcp_rbtree_insert(struct rb_root *root, struct sk_buff *skb)
{
    struct rb_node **p = &root->rb_node;
    struct rb_node *parent = NULL;
    struct sk_buff *skb1;

    while (*p) {
        parent = *p;
        skb1 = rb_to_skb(parent);
        if (before(TCP_SKB_CB(skb)->seq, TCP_SKB_CB(skb1)->seq))
            p = &parent->rb_left;
        else
            p = &parent->rb_right;
    }
    rb_link_node(&skb->rbnode, parent, p);
    rb_insert_color(&skb->rbnode, root);
}

static void coop_wskb_rtx_entail(struct sock *sk, struct sk_buff *skb)
{
    struct tcp_sock *tp = tcp_sk(sk);

    sk_wmem_queued_add(sk, skb->truesize);
    sk_mem_charge(sk, skb->truesize);
    skb->next = skb->prev = NULL;
    coop_tcp_rbtree_insert(&sk->tcp_rtx_queue, skb);

    if (tp->highest_sack == NULL)
        tp->highest_sack = skb;

    tp->packets_out += (u32)tcp_skb_pcount(skb);
    NET_ADD_STATS(sock_net(sk), LINUX_MIB_TCPORIGDATASENT,
              tcp_skb_pcount(skb));
}

static void coop_tcp_mstamp_refresh(struct tcp_sock *tp)
{
    struct inet_connection_sock *icsk = &tp->inet_conn;
    u64 val = tcp_clock_ns();

    tp->tcp_clock_cache = val;
    tp->tcp_mstamp = div_u64(val, NSEC_PER_USEC);

    icsk->icsk_ack.lrcvtime = tcp_jiffies32;
    tp->rcv_tstamp = tcp_jiffies32;
    tp->lsndtime = tcp_jiffies32;
    tp->snd_cwnd_stamp = tcp_jiffies32;
}

static s32 coop_tcp_d2a_write_build(struct sock *sk, msg_iov *iov, iov_desc_t *desc)
{
    struct tcp_sock *tp = tcp_sk(sk);
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    void *convert_addr = stack_mem_convert(iov->base_addr);
    if (convert_addr == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, stack_mem_convert fail", ssk->sk_id, ssk->fd);
        return -1;
    }

    struct sk_buff *skb = coop_tcp_write_alloc_skb(sk, iov->data_len, sk->sk_allocation);
    if (skb == NULL) {
        msg_iov_free(iov);
        NS_ERR("sk_id=%lu, fd=%d, coop_tcp_write_alloc_skb fail", ssk->sk_id, ssk->fd);
        return -1;
    }

    maa_cache_flush(iov->base_addr);
    (void)memcpy_s(skb->data, skb->len, (u8 *)convert_addr + iov->data_off, iov->data_len);
    skb->csum = 0;
    __wsum csum = csum_partial(skb->data, skb->len, ~0U);
    skb->csum = csum_block_add(skb->csum, csum, 0);
    skb->ip_summed = CHECKSUM_PARTIAL;

    u32 end_seq = desc->start_seq + iov->data_len + desc->fin;
    u8 tcp_flags = TCPHDR_ACK;
    if (desc->fin) {
        tcp_flags |= TCPHDR_FIN;
    }
    if (desc->push) {
        tcp_flags |= TCPHDR_PSH;
    }

    skb->skb_mstamp_ns = tp->tcp_wstamp_ns - desc->send_time;
    NS_DBG("seq %u~%u type %u", desc->start_seq, end_seq, desc->type);
    coop_wskb_fill_cb(skb, desc->start_seq, end_seq, tcp_flags);
    WRITE_ONCE(tp->write_seq, end_seq);
    if (desc->type == IOV_TYPE_UNSENT && after(end_seq, tp->snd_nxt)) {
        coop_wskb_entail(sk, skb);
    } else {
        struct tcp_skb_cb *tcb = TCP_SKB_CB(skb);
        if (desc->sacked) {
            tcb->sacked |= TCPCB_SACKED_ACKED;
            tp->sacked_out += (u32)tcp_skb_pcount(skb);
        }
        if (desc->retrans) {
            tcb->sacked |= TCPCB_RETRANS;
            tp->retrans_out += (u32)tcp_skb_pcount(skb);
            if (tp->retrans_stamp == 0) {
                tp->retrans_stamp = tcp_skb_timestamp(skb);
            }
        }
        coop_wskb_rtx_entail(sk, skb);
    }
    msg_iov_free(iov);
    return 0;
}

static s32 coop_tcp_d2a_recv_build_ofo(struct sock *sk, struct sk_buff *skb)
{
    struct tcp_sock *tp = tcp_sk(sk);
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    struct rb_node **p, *parent;
    u32 seq, end_seq;

    inet_csk_schedule_ack(sk);
    tp->rcv_ooopack += max_t(u16, 1, skb_shinfo(skb)->gso_segs);
    NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPOFOQUEUE);
    seq = TCP_SKB_CB(skb)->seq;
    end_seq = TCP_SKB_CB(skb)->end_seq;
    NS_DBG("seq %u~%u", seq, end_seq);

    p = &tp->out_of_order_queue.rb_node;
    if (RB_EMPTY_ROOT(&tp->out_of_order_queue)) {
        rb_link_node(&skb->rbnode, NULL, p);
        rb_insert_color(&skb->rbnode, &tp->out_of_order_queue);
        tp->ooo_last_skb = skb;
        return 0;
    }

    /* Can avoid an rbtree lookup if we are adding skb after ooo_last_skb */
    if (before(seq, TCP_SKB_CB(tp->ooo_last_skb)->end_seq)) {
        NS_ERR("sk_id=%lu, fd=%d, seq %d invaild, ooo_last_skb seq %d",
            ssk->sk_id, ssk->fd, seq, TCP_SKB_CB(tp->ooo_last_skb)->end_seq);
        return -1;
    }

    parent = &tp->ooo_last_skb->rbnode;
    p = &parent->rb_right;
    /* Insert segment into RB tree. */
    rb_link_node(&skb->rbnode, parent, p);
    rb_insert_color(&skb->rbnode, &tp->out_of_order_queue);
    tp->ooo_last_skb = skb;
    return 0;
}

static s32 coop_tcp_d2a_recv_build(struct sock *sk, msg_tcp_d2a_iov_rcv *m)
{
    s32 ret = 0;
    struct tcp_sock *tp = tcp_sk(sk);
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    iov_desc_t *desc = &m->desc;

    struct sk_buff *skb = stack_iovs_build_skb(m->iov, &m->iov_segs, desc, true);
    if (skb == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, build_skb fail", ssk->sk_id, ssk->fd);
        sbr_global_stat_update(GLOBAL_RX_MSG_TCP_D2A_SKB_NULL_ERR, m->iov_segs, 0);
        return -1;
    }

    struct skb_shared_info *shinfo = skb_shinfo(skb);
    struct tcp_skb_cb *tcb = TCP_SKB_CB(skb);
    tcb->seq = desc->start_seq;
    tcb->end_seq = desc->start_seq + skb->len + desc->fin;
    tcb->ack_seq = tp->snd_nxt;
    tcb->tcp_flags = TCPHDR_ACK;
    if (desc->fin) {
        tcb->tcp_flags |= TCPHDR_FIN;
    }
    if (desc->push) {
        tcb->tcp_flags |= TCPHDR_PSH;
    }
    tcb->has_rxtstamp = 1;
    tcb->tcp_gso_segs = m->iov_segs;
    shinfo->gso_segs = m->iov_segs;
    if (tcb->tcp_gso_segs > 1) {
        tcb->tcp_gso_size = m->iov[0].data_len;
    }
    skb_set_owner_r(skb, sk);
    sk_rmem_schedule(sk, skb, skb->truesize);
    if (desc->type == IOV_TYPE_RCV) {
        NS_DBG("seq %u~%u", tcb->seq, tcb->end_seq);
        __skb_queue_tail(&sk->sk_receive_queue, skb);
    } else {
        ret = coop_tcp_d2a_recv_build_ofo(sk, skb);
        if (ret != 0) {
            kfree_skb(skb);
        }
    }
    return ret;
}

typedef struct {
    struct list_head node;
    union {
        msg_tcp_d2a_iov_snd snd;
        msg_tcp_d2a_iov_rcv rcv;
    };
    bool is_snd;
} msg_d2a_resp_iov;

static s32 coop_tcp_d2a_resp_iov_handle(struct sock *sk, msg_d2a_resp_iov *iov)
{
    if (iov->is_snd) {
        msg_tcp_d2a_iov_snd *m = &iov->snd;
        u8 i;
        s32 err = 0;
        for (i = 0; i < m->iov_segs; i++) {
            if (err == 0) {
                s32 ret = coop_tcp_d2a_write_build(sk, &m->iov[i], &m->desc[i]);
                if (ret != 0) {
                    err = ret;
                }
            } else {
                msg_iov_free(&m->iov[i]);
            }
        }
        return err;
    } else {
        msg_tcp_d2a_iov_rcv *m = &iov->rcv;
        return coop_tcp_d2a_recv_build(sk, m);
    }
}

s32 coop_tcp_d2a_resp_iov(struct sock *sk, void *msg, bool is_snd)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;

    msg_d2a_resp_iov *iov = kmalloc(sizeof(msg_d2a_resp_iov), GFP_KERNEL);
    if (iov == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, kmalloc failed", ssk->sk_id, ssk->fd);
        return -1;
    }

    iov->is_snd = is_snd;
    if (is_snd) {
        (void)memcpy_s(&iov->snd, sizeof(msg_tcp_d2a_iov_snd), msg, sizeof(msg_tcp_d2a_iov_snd));
    } else {
        (void)memcpy_s(&iov->rcv, sizeof(msg_tcp_d2a_iov_rcv), msg, sizeof(msg_tcp_d2a_iov_rcv));
    }
    list_add_tail(&iov->node, &ssk->migrate_iov_list);
    return 0;
}

static u8 coop_tcp_state_convert(u8 tcp_state)
{
    u8 state;

    switch (tcp_state) {
        case TCP_STATE_CLOSED:
            state = TCP_CLOSE;
            break;
        case TCP_STATE_LISTEN:
            state = TCP_LISTEN;
            break;
        case TCP_STATE_SYN_SENT:
            state = TCP_SYN_SENT;
            break;
        case TCP_STATE_SYN_RCVD:
            state = TCP_SYN_RECV;
            break;
        case TCP_STATE_ESTABLISHED:
            state = TCP_ESTABLISHED;
            break;
        case TCP_STATE_FIN_WAIT_1:
            state = TCP_FIN_WAIT1;
            break;
        case TCP_STATE_FIN_WAIT_2:
            state = TCP_FIN_WAIT2;
            break;
        case TCP_STATE_CLOSE_WAIT:
            state = TCP_CLOSE_WAIT;
            break;
        case TCP_STATE_CLOSING:
            state = TCP_CLOSING;
            break;
        case TCP_STATE_LAST_ACK:
            state = TCP_LAST_ACK;
            break;
        case TCP_STATE_TIME_WAIT:
            state = TCP_TIME_WAIT;
            break;
        default:
            NS_ERR("Invalid tcp_state=%hhu.", tcp_state);
            state = TCP_CLOSE;
            break;
    }

    return state;
}

static s32 coop_tcp_recv_rebuild(struct sock *sk)
{
    struct sk_buff *skb;
    struct sk_buff_head temp_receive_queue;
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;

    skb_queue_head_init(&temp_receive_queue);
    skb_queue_splice_tail_init(&sk->sk_receive_queue, &temp_receive_queue);

    while ((skb = skb_peek(&temp_receive_queue))) {
        struct sk_buff *head = skb_copy(skb, sk->sk_allocation);
        if (head == NULL) {
            skb_queue_purge(&temp_receive_queue);
            NS_ERR("sk_id=%lu, fd=%d, skb_copy fail", ssk->sk_id, ssk->fd);
            return -1;
        }

        head->tstamp = skb->tstamp;
        struct tcp_skb_cb *tcb = TCP_SKB_CB(skb);
        struct tcp_skb_cb *htcb = TCP_SKB_CB(head);
        htcb->seq = tcb->seq;
        htcb->end_seq = tcb->seq + skb->len;
        htcb->ack_seq = tcb->ack_seq;
        htcb->tcp_flags = tcb->tcp_flags;
        htcb->has_rxtstamp = tcb->has_rxtstamp;
        htcb->tcp_gso_segs = 1;
        htcb->tcp_gso_size = 0;
        NS_DBG("seq %x~%x", htcb->seq, htcb->end_seq);
        __skb_queue_tail(&sk->sk_receive_queue, head);
        skb_set_owner_r(head, sk);
        skb_list_del_init(skb);
        __kfree_skb(skb);
    }

    return 0;
}

static s32 coop_tcp_d2a_build_skbs(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    struct tcp_sock *tp = tcp_sk(sk);
    msg_d2a_resp_iov *iov;
    s32 ret = 0;

    ret = coop_tcp_recv_rebuild(sk);
    struct sk_buff_head temp_write_queue;
    struct sk_buff *skb;

    skb_queue_head_init(&temp_write_queue);
    skb_queue_splice_tail_init(&sk->sk_write_queue, &temp_write_queue);

    while ((iov = list_first_entry_or_null(&ssk->migrate_iov_list, msg_d2a_resp_iov, node)) != NULL) {
        if (ret == 0) {
            s32 err = coop_tcp_d2a_resp_iov_handle(sk, iov);
            if (err != 0) {
                ret = err;
            }
        } else {
            msg_iovs_free(iov->is_snd ? iov->snd.iov : iov->rcv.iov,
                iov->is_snd ? iov->snd.iov_segs : iov->rcv.iov_segs);
        }

        list_del(&iov->node);
        kfree(iov);
    }

    while ((skb = __skb_dequeue(&temp_write_queue)) != NULL) {
        if (ret == 0) {
            struct sk_buff *n = coop_tcp_write_alloc_skb(sk, skb->len, sk->sk_allocation);
            if (n == NULL) {
                NS_ERR("sk_id=%lu, fd=%d, coop_tcp_write_alloc_skb fail", ssk->sk_id, ssk->fd);
                ret = -1;
                continue;
            }
            BUG_ON(skb_copy_bits(skb, 0, n->data, skb->len));
            n->csum = 0;
            __wsum csum = csum_partial(n->data, n->len, ~0U);
            n->csum = csum_block_add(n->csum, csum, 0);
            n->ip_summed = CHECKSUM_PARTIAL;

            u32 seq = tp->write_seq;
            u32 end_seq = seq + n->len;
            u8 tcp_flags = TCPHDR_ACK;
            struct sbr_tcp_skb_cb *tcb = SBR_TCP_SKB_CB(skb);
            if (tcb->tcp_push) {
                tcp_flags |= TCPHDR_PSH;
            }
            NS_DBG("write_queue seq %u~%u", seq, end_seq);
            coop_wskb_fill_cb(n, seq, end_seq, tcp_flags);
            WRITE_ONCE(tp->write_seq, end_seq);
            coop_wskb_entail(sk, n);
        }
        sk_wmem_queued_add(sk, -skb->truesize);
        __kfree_skb(skb);
    }

    tp->snd_cwnd_used = tp->packets_out;
    while ((skb = __skb_dequeue(&ssk->dpa_queue)) != NULL) {
        sk_wmem_queued_add(sk, -skb->truesize);
        __kfree_skb(skb);
    }
    return ret;
}

#if defined(CONFIG_TCP_NATA_URC) || defined(CONFIG_TCP_NATA_STL)
static void coop_reset_xmit_timer_helper(struct sock *sk, const int what,
    unsigned long when, const unsigned long max_when)
{
    struct inet_connection_sock *icsk = inet_csk(sk);

    if (when > max_when) {
        when = max_when;
    }

    if (what == ICSK_TIME_RETRANS || what == ICSK_TIME_PROBE0 ||
        what == ICSK_TIME_EARLY_RETRANS || what == ICSK_TIME_LOSS_PROBE ||
        what == ICSK_TIME_REO_TIMEOUT) {
        icsk->icsk_pending = what;
        icsk->icsk_timeout = jiffies + when;
        sk_reset_timer(sk, &icsk->icsk_retransmit_timer, icsk->icsk_timeout);
    } else if (what == ICSK_TIME_DACK) {
        icsk->icsk_ack.pending |= ICSK_ACK_TIMER;
        icsk->icsk_ack.timeout = jiffies + when;
        sk_reset_timer(sk, &icsk->icsk_delack_timer, icsk->icsk_ack.timeout);
    } else {
        NS_DBG("inet_csk BUG: unknown timer value");
    }
}

static inline void coop_reset_xmit_timer(struct sock *sk, const int what,
    unsigned long when, const unsigned long max_when)
{
    coop_reset_xmit_timer_helper(sk, what, when + tcp_pacing_delay(sk),
                  max_when);
}
#else
static inline void coop_reset_xmit_timer(struct sock *sk, const int what,
    unsigned long when, const unsigned long max_when)
{
    tcp_reset_xmit_timer(sk, what, when, max_when);
}
#endif

static void coop_tcp_timer_start(struct sock *sk)
{
    struct tcp_sock *tp = tcp_sk(sk);
    struct inet_connection_sock *icsk = inet_csk(sk);
    sbr_socket_t *sbr_sk = inet_sk(sk)->dpa_ctx;
    u32 timeout;
    s64 rto_delta_us;
    int early_retrans;

    if (sock_flag(sk, SOCK_KEEPOPEN)) {
        u32 elapsed = keepalive_time_elapsed(tp);
        if (tp->keepalive_time > elapsed)
            elapsed = tp->keepalive_time - elapsed;
        else
            elapsed = 0;
        NS_DBG("keepalive %u", elapsed);
        inet_csk_reset_keepalive_timer(sk, elapsed);
    }

    if (sbr_sk->d2a_event == D2A_EVT_REQ_RTO || sbr_sk->d2a_event == D2A_EVT_NIF_NO_DL_PKT ||
        sbr_sk->d2a_event == D2A_EVT_CONN_NO_DL_PKT) {
        if (icsk->icsk_retransmits > 0) {
            icsk->icsk_retransmits--;
            icsk->icsk_rto = min(icsk->icsk_rto >> 1, TCP_RTO_MAX);
            NS_DBG("rto immediately");
        } else {
            NS_ERR("sk_id=%lu, icsk_retransmits not correct %u", sbr_sk->sk_id, icsk->icsk_retransmits);
        }
        coop_reset_xmit_timer(sk, ICSK_TIME_RETRANS, TCP_TIMEOUT_MIN, TCP_RTO_MAX);
        return;
    }

    early_retrans = sock_net(sk)->ipv4.sysctl_tcp_early_retrans;
    /* ER or TLP */
    if ((early_retrans == 3 || early_retrans == 4) && tp->packets_out && tcp_is_sack(tp)) {
        if (tp->srtt_us != 0) {
            timeout = usecs_to_jiffies(tp->srtt_us >> 2);
            if (tp->packets_out == 1)
                timeout += TCP_RTO_MIN;
            else
                timeout += TCP_TIMEOUT_MIN;
        } else {
            timeout = TCP_TIMEOUT_INIT;
        }
        /* If the RTO formula yields an earlier time, then use that time. */
        rto_delta_us = tcp_rto_delta_us(sk);  /* How far in future is RTO? */
        if (rto_delta_us > 0)
            timeout = min_t(u32, timeout, usecs_to_jiffies((u32)rto_delta_us));

        NS_DBG("tlp %u", timeout);
        coop_reset_xmit_timer(sk, ICSK_TIME_LOSS_PROBE, timeout, TCP_RTO_MAX);
        return;
    } else if (tp->packets_out) {
        NS_DBG("rto %u", inet_csk(sk)->icsk_rto);
        coop_reset_xmit_timer(sk, ICSK_TIME_RETRANS, inet_csk(sk)->icsk_rto, TCP_RTO_MAX);
        return;
    }

    if (!tcp_sk(sk)->packets_out && !inet_csk(sk)->icsk_pending)
        coop_reset_xmit_timer(sk, ICSK_TIME_PROBE0,
                     tcp_probe0_base(sk), TCP_RTO_MAX);
}

static void coop_tcp_enter_recovery(struct sock *sk)
{
    struct tcp_sock *tp = tcp_sk(sk);
    int mib_idx;

    if (tcp_is_reno(tp))
        mib_idx = LINUX_MIB_TCPRENORECOVERY;
    else
        mib_idx = LINUX_MIB_TCPSACKRECOVERY;

    NET_INC_STATS(sock_net(sk), mib_idx);

    tp->prior_ssthresh = 0;
    tp->undo_marker = tp->snd_una;
    tp->undo_retrans = (int)tp->retrans_out;

    tp->prior_ssthresh = tp->snd_ssthresh;
    tp->high_seq = tp->snd_nxt;
    tp->tlp_high_seq = 0;
    tp->snd_cwnd_cnt = 0;
    tp->prior_cwnd = tp->snd_cwnd;
    tp->prr_delivered = 0;
    tp->prr_out = 0;
    tcp_set_ca_state(sk, TCP_CA_Recovery);
}

static void stack_migrate_iov_list_free(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;

    msg_d2a_resp_iov *iov;
    while ((iov = list_first_entry_or_null(&ssk->migrate_iov_list, msg_d2a_resp_iov, node)) != NULL) {
        msg_iovs_free(iov->is_snd ? iov->snd.iov : iov->rcv.iov, iov->is_snd ? iov->snd.iov_segs : iov->rcv.iov_segs);
        list_del(&iov->node);
        kfree(iov);
    }
}

s32 coop_tcp_d2a_resp(struct sock *sk, msg_tcp_migrate_d2a_resp *m)
{
    struct tcp_sock *tp = tcp_sk(sk);
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    struct inet_connection_sock *icsk = inet_csk(sk);
    int i;

    if (m->err != 0) {
        stack_migrate_iov_list_free(sk);
        NS_ERR("sk_id=%lu, fd=%d, err %d", ssk->sk_id, ssk->fd, m->err);
        return m->err;
    }

    coop_tcp_mstamp_refresh(tp);
    tp->tcp_wstamp_ns = max(tp->tcp_wstamp_ns, tp->tcp_clock_cache);
    tp->tsoffset = m->ts_now - tcp_ns_to_ts(tp->tcp_wstamp_ns);
    unsigned char state = coop_tcp_state_convert(m->tcp_state);
    tp->rcv_nxt = m->rcv_nxt;
    tp->rcv_wnd = m->rcv_wnd;
    sk->sk_userlocks = ssk->backup_sk_userlocks;
    sk->sk_rcvbuf = (int)(m->rcv_buf << 1);
    tp->srtt_us = m->snd_rtt_est.sa;
    tp->rttvar_us = max(m->snd_rtt_est.sv, tcp_rto_min_us(sk));
    tp->mdev_max_us = tp->rttvar_us;
    tp->mdev_us = m->snd_rtt_est.sv;
    (void)memcpy_s(&tp->rtt_min, sizeof(tp->rtt_min), &m->rtt_min, sizeof(m->rtt_min));
    tp->snd_cwnd = m->snd_cwnd;
    tp->snd_ssthresh = m->snd_ssthresh;
    icsk->icsk_probes_out = m->persist_cnt > 0 ? (u8)m->persist_cnt : m->keep_cnt_sent;
    inet_sk(sk)->inet_id = m->inet_id;
    WRITE_ONCE(sk->sk_txhash, m->tx_hash);

    sk->sk_sndbuf = (int)(m->snd_buf << 1);
    tp->snd_nxt = m->snd_nxt;
    tp->write_seq = tp->snd_nxt;
    tp->snd_sml = m->snd_sml;
    tp->snd_wnd = m->snd_wnd;
    tp->snd_una = m->snd_una;
    tp->max_window = tp->snd_wnd;
    tp->rcv_wup = m->rcv_wup;
    tp->retrans_stamp = 0;
    icsk->icsk_ack.quick = (u8)m->quick_ack;
    icsk->icsk_retransmits = m->retransmits;

    tp->snd_wl1 = m->snd_wl1;
    tp->rx_opt.ts_recent = m->ts_recent;
    (void)memcpy_s(tp->selective_acks, sizeof(tp->selective_acks), m->sack_seq, sizeof(m->sack_seq));
    for (i = 0; i < MAX_NUM_SACK; i++) {
        if (!before(tp->selective_acks[i].start_seq, tp->selective_acks[i].end_seq)) {
            break;
        }
        NS_WAR("%d sack %u~%u", i, tp->selective_acks[i].start_seq, tp->selective_acks[i].end_seq);
    }
    if (tcp_is_sack(tp)) {
        tp->rx_opt.num_sacks = (u8)i;
    }
    (void)memcpy_s(tp->recv_sack_cache, sizeof(tp->recv_sack_cache), m->recv_sack, sizeof(m->recv_sack));

    if (tp->srtt_us != 0) {
        icsk->icsk_rto = __tcp_set_rto(tp);
        tcp_bound_rto(sk);
        icsk->icsk_rto = min(icsk->icsk_rto << icsk->icsk_retransmits, TCP_RTO_MAX);
    }

    s32 ret = coop_tcp_d2a_build_skbs(sk);
    if (ret != 0) {
        return ret;
    }

    if (sk->sk_sndbuf < sk->sk_wmem_queued) {
        sk->sk_sndbuf = sk->sk_wmem_queued;
    }

    s32 rmem_alloc = sk_rmem_alloc_get(sk) * 2;
    if (sk->sk_rcvbuf < rmem_alloc) {
        sk->sk_rcvbuf = rmem_alloc;
    }

    if (tp->max_packets_out < tp->packets_out) {
        tp->max_packets_out = tp->packets_out;
    }
    tp->max_packets_seq = tp->snd_nxt;

    if (tp->retrans_out) {
        coop_tcp_enter_recovery(sk);
    }
    coop_tcp_timer_start(sk);
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    u64 now_ts = div_u64(ktime_get_ns(), NSEC_PER_USEC);
    NS_INF("sk_id=%lu,fd=%d d2a use %lu us,sk_state=%u,snd_nxt=%x,rcv_nxt=%x,write_seq=%x,copied_seq=%x,snd_cwnd=%u,"
        "snd_wnd=%u,snd_ssthresh=%u,sk_wmem_queued=%u", sbr_sk->sk_id, ssk->fd, now_ts - sbr_sk->migrate_ts, state,
        tp->snd_nxt, tp->rcv_nxt, tp->write_seq, tp->copied_seq, tp->snd_cwnd, tp->snd_wnd, tp->snd_ssthresh,
        sk->sk_wmem_queued);
    NS_INF("sk_id=%lu,sk_rmem_alloc=%u,sk_rcvbuf=%u,sk_sndbuf=%u,packets_out=%u,retrans_out=%u,snd_una=%u,srtt_us=%u"
        "rttvar_us=%u, icsk_rto=%u, icsk_retransmits=%u",
        sbr_sk->sk_id, sk->sk_rmem_alloc, sk->sk_rcvbuf, sk->sk_sndbuf, tp->packets_out, tp->retrans_out, tp->snd_una,
        tp->srtt_us, tp->rttvar_us, icsk->icsk_rto, icsk->icsk_retransmits);
    if (state == TCP_TIME_WAIT) {
        if (sk_fullsock(sk)) {
            tcp_time_wait(sk, TCP_TIME_WAIT, 0);
        } else {
            tcp_set_state(sk, state);
        }
    } else {
        tcp_set_state(sk, state);
        if (!skb_queue_empty(&sk->sk_receive_queue)) {
            sk->sk_data_ready(sk);
        }
    }
    return 0;
}

static bool coop_udp_migrate_a2d_unsupport(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    if (sbr_sk_isv6(ssk)) {
        if (ipv6_addr_loopback(&sk->sk_v6_rcv_saddr) || ipv6_addr_v4mapped_loopback(&sk->sk_v6_rcv_saddr)) {
            NS_WAR("skip IPV6_ADDR_LOOPBACK");
            return true;
        }

        if (ipv6_addr_is_multicast(&sk->sk_v6_rcv_saddr) || ipv6_addr_is_multicast(&sk->sk_v6_daddr)) {
            NS_WAR("skip IPV6 multicast");
            return true;
        }
    }

    if (sbr_sk_isv6(ssk) && !ipv6_addr_v4mapped(&sk->sk_v6_daddr)) {
        struct dst_entry *dst = sk_dst_check(sk, inet6_sk(sk)->dst_cookie);
        if (dst != NULL) {
            if (!check_dev_match(sk, dst->dev, true)) {
                NS_WAR("sk_id=%lu, dst dev %s not match saddr", ssk->sk_id, dst->dev->name);
                dst_release(dst);
                return true;
            }
            ssk->ifidx = dst->dev->ifindex;
            dst_release(dst);
        } else {
            NS_ERR("sk_id=%lu, fd=%d, no dst_entry", ssk->sk_id, ssk->fd);
            return true;
        }
    } else {
        u16 rt_type;
        struct rtable *rt;

        if (sk->sk_rcv_saddr == htonl(INADDR_LOOPBACK)) {
            NS_WAR("skip LOOPBACK");
            return true;
        }

        if (ipv4_is_multicast(sk->sk_rcv_saddr) || ipv4_is_multicast(sk->sk_daddr)) {
            NS_WAR("skip multicast");
            return true;
        }

        /* if socket is connected */
        rt = (struct rtable *)sk_dst_check(sk, 0);
        if (rt != NULL) {
            rt_type = rt->rt_type;
            ssk->ifidx = (s32)rt->dst.dev->ifindex;
            if (!check_dev_match(sk, rt->dst.dev, false)) {
                NS_WAR("sk_id=%lu, dst dev %s not match saddr", ssk->sk_id, rt->dst.dev->name);
                dst_release((struct dst_entry *)rt);
                return true;
            }
            dst_release((struct dst_entry *)rt);

            if (rt_type != RTN_UNICAST) {
                NS_ERR("sk_id=%lu, fd=%d, rt_type %u support", ssk->sk_id, ssk->fd, rt_type);
                return true;
            }
        } else {
            NS_ERR("sk_id=%lu, fd=%d, phy_ifidx %d get vir_ifidx failed", ssk->sk_id, ssk->fd, ssk->ifidx);
            return true;
        }
    }
    if (!is_nic_valid_check_by_id(ssk->ifidx)) {
        NS_ERR("sk_id=%lu, fd=%d, phy_ifidx %d is invalid", ssk->sk_id, ssk->fd, ssk->ifidx);
        return true;
    }

    return false;
}

s32 coop_udp_migrate_a2d(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;
    if (coop_udp_migrate_a2d_unsupport(sk)) {
        return -EOPNOTSUPP;
    }
    if (g_dpa_cpu_overload_times > 0) {
        ssk->d2a_event = D2A_EVT_CPU_OVERLOAD;
#ifdef CONFIG_DPA_CHR
        migrate_fail_stat(ssk->sk, ssk->d2a_event);
#endif
        return -EBUSY;
    }
    data_com_msg *pmsg = sbr_msg_malloc(false);
    if (pmsg == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, could not allocate pmsg", ssk->sk_id, ssk->fd);
        return -ENOMEM;
    }

    if (sizeof(msg_udp_migrate_a2d) > sizeof(pmsg->buffer)) {
        NS_ERR("sk_id=%lu, fd=%d, could not allocate pmsg", ssk->sk_id, ssk->fd);
        sbr_msg_free(pmsg, true);
        return -EMSGSIZE;
    }
    pmsg->param.type = MIGRATE_A2D;
    pmsg->param.op_type = MSG_ASYN_POST;
    pmsg->param.buffer_len = (u32)MSG_SIZE(sizeof(msg_udp_migrate_a2d));

    msg_udp_migrate_a2d *m = (msg_udp_migrate_a2d *)pmsg->buffer;
    int ret = coop_comm_migrate_a2d(&m->comm, sk);
    if (ret != 0) {
        sbr_msg_free(pmsg, true);
        return ret;
    }
    ret = msg_try_post(pmsg, sbr_get_msg_box(ssk));
    if (ret < 0) {
        ssk->d2a_event = D2A_EVT_A2D_MSG_FAIL;
#ifdef CONFIG_DPA_CHR
        migrate_fail_stat(ssk->sk, ssk->d2a_event);
#endif
        coop_migrate_remove(ssk);
        sbr_migrate_a2d_msg_failed_inc();
        NS_ERR("sk_id=%lu, fd=%d, failed to post msg", ssk->sk_id, ssk->fd);
        return -ENOMEM;
    }
    sbr_migrate_a2d_msg_success_inc();

    coop_migrate_timer_init(sk);
    coop_migrate_timer_reset(sk, MIGRATE_TIMER_A2D, MIGRATE_TIMEOUT);
    /* sk ref will dec in _stack_migrate_resp() */
    return 0;
}

s32 coop_udp_migrate_d2a(struct sock *sk)
{
    struct sbr_socket *ssk = (struct sbr_socket *)inet_sk(sk)->dpa_ctx;

    if (ssk->status != SK_MIGRATE_OK) {
        NS_ERR("sk_id=%lu,fd=%d,status %u skip migrate_d2a", ssk->sk_id, ssk->fd, ssk->status);
        return -EPIPE;
    }

    int ret = sbr_handle_close(ssk, 0);
    if (ret == 0) {
        spin_lock_bh(&sk->sk_lock.slock);
        ssk->status = SK_CLOSE;
        if (!sock_flag(sk, SOCK_DEAD) && sk->sk_socket) {
            WRITE_ONCE(sk->sk_socket->ops, ssk->save_ops);
        }
        WRITE_ONCE(sk->sk_prot, ssk->save_prot);
        spin_unlock_bh(&sk->sk_lock.slock);
        ssk->status = SK_CLOSE;
        release_dpa_sk(ssk);
        conn_stats_print(ssk);
        sbr_filter_purge(ssk);
        ssk->fd = -1;
        sk->sk_state_change(sk);
    }
    return ret;
}

static u16 backlog_skb_2_iov(struct sbr_socket *ssk, msg_iov *iov, struct sk_buff *skb)
{
    u16 i;
    u16 iov_cnt = (u16)DIV_ROUND_UP(skb->len, MAA_UNMAP_SIZE);
    u32 offset = 0;
    int ret;
    struct iphdr *iph = (struct iphdr *)skb_network_header(skb);

    NS_DBG("skb->len %u iph tot_len %u iov_cnt %u", skb->len, ntohs(iph->tot_len), iov_cnt);
    if (iov_cnt > MAX_FRAGS) {
        NS_ERR("sk_id=%lu, fd=%d, iov_cnt %u too big, skb->len %u", ssk->sk_id, ssk->fd, iov_cnt, skb->len);
        return 0;
    }
    for (i = 0; i < iov_cnt; i++) {
        iov[i].base_addr = stack_maa_alloc(MAA_UNMAP_SIZE);
        if (iov[i].base_addr == 0) {
            NS_ERR("sk_id=%lu, fd=%d, stack_maa_alloc failed", ssk->sk_id, ssk->fd);
            msg_iovs_free(iov, i);
            return 0;
        }
        iov[i].data_off = 0;
        iov[i].data_len = (u16)(skb->len - offset);
        if (iov[i].data_len > MAA_UNMAP_SIZE) {
            iov[i].data_len = MAA_UNMAP_SIZE;
        }
        iov[i].head_frag = 1;

        void *virt = stack_mem_convert(iov[i].base_addr);
        ret = skb_copy_bits(skb, (int)offset, virt, iov[i].data_len);
        if (ret != 0) {
            NS_ERR("sk_id=%lu, fd=%d, skb_copy_bits failed", ssk->sk_id, ssk->fd);
            msg_iovs_free(iov, i + 1);
            return 0;
        }
        maa_cache_map(iov[i].base_addr);
        offset += iov[i].data_len;
    }

    return iov_cnt;
}

void migrate_drop_skb(struct sk_buff *skb)
{
    struct sk_buff *next;
    while (skb != NULL) {
        next = skb->next;
        prefetch(next);
        WARN_ON_ONCE(skb_dst_is_noref(skb));
        skb_mark_not_on_list(skb);
        kfree_skb(skb);
        skb = next;
    }
}

static s32 coop_migrate_a2d_backlog_msg(struct sbr_socket *ssk, struct sk_buff *skb, int ifidx, u8 last)
{
    s32 ret;
    u8 iov_segs;
    int header_offset = 0;
    data_com_msg *m = sbr_msg_malloc(false);
    if (m == NULL) {
        NS_ERR("sk_id=%lu, fd=%d, attach msg failed", ssk->sk_id, ssk->fd);
        if (skb != NULL) {
            u8 iov_cnt = (u8)DIV_ROUND_UP(skb->len, MAA_UNMAP_SIZE);
            sbr_conn_stat_update(ssk->stats, SBR_RX_TCP_BACKLOG_MSG_MALLOC_ERR, iov_cnt, (u32)skb->len);
        }
        return -1;
    }

    m->param.type = MIGRATE_A2D_BACKLOG;
    m->param.op_type = MSG_ASYN_POST;
    m->param.buffer_len = (u32)MSG_SIZE(sizeof(msg_backlog_buf));
    m->param.fd = ssk->fd;
    msg_backlog_buf *p = (msg_backlog_buf *)m->buffer;
    p->ifidx = ifidx;
    p->last = last;

    if (skb != NULL) {
        header_offset = skb_transport_header(skb) - skb_network_header(skb) + ETHER_HLEN;
        p->ipv6 = (skb->protocol == htons(ETH_P_IPV6)) ? 1 : 0;
        __skb_push(skb, header_offset);
        iov_segs = (u8)backlog_skb_2_iov(ssk, p->iov, skb);
    } else {
        iov_segs = 0;
    }

    if (iov_segs > 0) {
        const struct tcphdr *th = (const struct tcphdr *)(skb->data + header_offset);
        p->has_iov = 1;
        p->ipv6 = (htons(skb->protocol) == ETH_P_IPV6) ? 1 : 0;
        p->iov_segs = iov_segs;
        p->tcp_head_len = (u16)__tcp_hdrlen(th);
        p->header_offset = header_offset;
        ret = memcpy_s(p->tcp_head, TCP_MAX_HDR_LEN, th, p->tcp_head_len);
        if (ret != EOK) {
            NS_ERR("sk_id=%lu, fd=%d, memcpy_s maa_head failed", ssk->sk_id, ssk->fd);
            sbr_msg_free(m, true);
            sbr_conn_stat_update(ssk->stats, SBR_RX_TCP_BACKLOG_COPY_HDR_ERR, iov_segs, (u32)skb->len);
            return -1;
        }
    } else {
        p->has_iov = 0;
        p->ipv6 = 0;
        p->iov_segs = 0;
        p->tcp_head_len = 0;
        p->header_offset = 0;
        (void)memset_s(p->tcp_head, TCP_MAX_HDR_LEN, 0, TCP_MAX_HDR_LEN);
    }

    ret = msg_try_post(m, get_instance_msg_box(0));
    if (ret < 0) {
        msg_iovs_free(p->iov, p->iov_segs);
        NS_ERR("sk_id=%lu, fd=%d, failed to post msg", ssk->sk_id, ssk->fd);
        if (skb != NULL) {
            sbr_conn_stat_update(ssk->stats, SBR_RX_TCP_BACKLOG_POST_ERR, iov_segs, (u32)skb->len);
        }
        return -1;
    }
    if (skb != NULL) {
        sbr_conn_stat_update(ssk->stats, SBR_RX_TCP_BACKLOG_OUT, iov_segs, (u32)skb->len);
    }
    return 0;
}

void coop_migrate_a2d_backlog(struct sock *sk, u8 last, bool slock)
{
    struct inet_sock *inet = inet_sk(sk);
    struct sbr_socket *ssk = inet->dpa_ctx;
    struct sk_buff *skb, *next, *skb_tail;

    if (slock) {
        spin_lock_bh(&sk->sk_lock.slock);
    }
    skb = ssk->dpa_head;
    skb_tail = ssk->dpa_tail;
    ssk->dpa_head = ssk->dpa_tail = NULL;
    if (slock) {
        spin_unlock_bh(&sk->sk_lock.slock);
    }
    s32 ifidx = (s32)ssk->ifidx;

    if (skb == NULL) {
        if (last) {
            (void)coop_migrate_a2d_backlog_msg(ssk, NULL, ifidx, 1);
        }
        return;
    }

    do {
        bool last_skb = (skb->next == NULL) && !!last;
        struct tcphdr *tcph = tcp_hdr(skb);
        int head_len = -skb_mac_offset(skb) + __tcp_hdrlen(tcph);
        if (head_len > MAX_HEAD_LEN) {
            NS_WAR("migrate_a2d_backlog_msg head over 128, head_len=%d", head_len);
            ssk->d2a_event = D2A_EVT_HEAD_OVERLONG;
            s32 ret = ssk->fdopt->migrate_d2a(ssk);
            if (ret != 0) {
                NS_ERR("sk_id=%lu, fd=%d, migrate_d2a D2A_EVT_HEAD_OVERLONG fail ret %d", ssk->sk_id, ssk->fd, ret);
            }
            if (slock) {
                spin_lock_bh(&sk->sk_lock.slock);
            }
            if (ssk->dpa_head == NULL && ssk->dpa_tail == NULL) {
                ssk->dpa_head = skb;
                ssk->dpa_tail = skb_tail;
            } else {
                skb_tail->next = ssk->dpa_head;
                ssk->dpa_head = skb;
            }
            if (slock) {
                spin_unlock_bh(&sk->sk_lock.slock);
            }
            return;
        }
        s32 ret = coop_migrate_a2d_backlog_msg(ssk, skb, ifidx, last_skb ? 1 : 0);
        if (ret != 0) {
            migrate_drop_skb(skb);
            return;
        }

        next = skb->next;
        skb->next = NULL;
        kfree_skb(skb);
        skb = next;
    } while (skb != NULL);
}

static int ip_event(struct notifier_block *this, unsigned long event, void *ptr)
{
    struct in_ifaddr *ifa = (struct in_ifaddr *)ptr;
    struct net_device *dev = ifa->ifa_dev->dev;
    if (net_eq(dev_net(dev), &init_net) == 0) {
        return NOTIFY_DONE;
    }
    if (!is_nic_valid_check_by_id(dev->ifindex)) {
        NS_ERR("ifidx is invalid, phy_ifidx=%d, phy_name=%s", dev->ifindex, dev->name);
        return NOTIFY_DONE;
    }
    data_com_msg *pmsg = sbr_msg_malloc(false);
    if (pmsg == NULL) {
        NS_ERR("could not allocate pmsg");
        return NOTIFY_DONE;
    }
    pmsg->param.type = NETIF_SYNC_ADDR;
    pmsg->param.op_type = MSG_ASYN_POST;
    pmsg->param.buffer_len = (u32)MSG_SIZE(sizeof(msg_sync_netif_addr));

    msg_sync_netif_addr *m = (msg_sync_netif_addr *)pmsg->buffer;
    (void)memset_s(m, sizeof(msg_sync_netif_addr), 0, sizeof(msg_sync_netif_addr));
    m->ifindex = dev->ifindex;
    m->event = event;
    m->addr.sin_addr.s_addr = ifa->ifa_local;
    m->mask.sin_addr.s_addr = ifa->ifa_mask;
    NS_INF("dev_id=%d, event=%lu, addr=%u.%u.*.*, maslen=%d", dev->ifindex, event, SAFETY_IP_VAR(&ifa->ifa_local),
        get_len_from_mask(ifa->ifa_mask));

    int ret = msg_try_post(pmsg, get_instance_control_box(0));
    if (ret < 0) {
        NS_ERR("failed to post msg");
    }

    return NOTIFY_DONE;
}

static struct notifier_block g_ip_notifier = {
    .notifier_call = ip_event,
};

#if SPL_IPV6
static int ip6_addr_event(struct notifier_block *this, unsigned long event, void *ptr)
{
    struct inet6_ifaddr *ifa = (struct inet6_ifaddr *)ptr;
    if (net_eq(dev_net(ifa->idev->dev), &init_net) == 0) {
        return NOTIFY_DONE;
    }
    if (!is_nic_valid_check_by_id(ifa->idev->dev->ifindex)) {
        NS_ERR("ifidx is invalid,ifa_ifidx=%d, phy_name=%s", ifa->idev->dev->ifindex, ifa->idev->dev->name);
        return NOTIFY_DONE;
    }
    spl_ip6_addr_t addr;
    if (memcpy_s(addr.addr, sizeof(addr.addr), ifa->addr.s6_addr32, sizeof(ifa->addr.s6_addr32)) != EOK) {
        NS_ERR("memcpy_s failed");
        return NOTIFY_DONE;
    }
    addr.zone = (u8)ipv6_iface_scope_id(&ifa->addr, ifa->idev->dev->ifindex);
    data_com_msg *pmsg = sbr_msg_malloc(false);
    if (pmsg == NULL) {
        NS_ERR("could not allocate pmsg");
        return NOTIFY_DONE;
    }
    pmsg->param.type = NETIF_SYNC_IP6ADDR;
    pmsg->param.op_type = MSG_ASYN_POST;
    pmsg->param.buffer_len = (u32)MSG_SIZE(sizeof(msg_sync_netif_ip6addr));

    msg_sync_netif_ip6addr *m = (msg_sync_netif_ip6addr *)pmsg->buffer;
    m->ifindex = ifa->idev->dev->ifindex;
    m->event = event;
    m->addr = addr;
    m->mask_len = ifa->prefix_len;
    NS_INF("dev_id=%d, event=%lu, addr=%x:%x:***, maslen=%u", ifa->idev->dev->ifindex, event,
        SAFETY_IPV6_VAR(&addr), m->mask_len);
    int ret = msg_try_post(pmsg, get_instance_control_box(0));
    if (ret < 0) {
        NS_ERR("failed to post msg");
    }

    return NOTIFY_DONE;
}

static struct notifier_block g_ip6_addr_notifier = {
    .notifier_call = ip6_addr_event,
};
#endif

int notify_nd_event(void *ipaddr, struct eth_addr ha, u8 nud_state, s32 family, struct net_device *dev)
{
    if (!is_nic_valid_check_by_id(dev->ifindex)) {
        NS_ERR("ifidx is invalid");
        return -SPL_ENODEV;
    }
    data_com_msg *pmsg = sbr_msg_malloc(false);
    if (pmsg == NULL) {
        NS_ERR("could not allocate pmsg");
        return -SPL_ENOMEM;
    }
    pmsg->param.type = DPA_SYNC_ARP;
    pmsg->param.op_type = MSG_ASYN_POST;
    pmsg->param.buffer_len = (u32)MSG_SIZE(sizeof(msg_sync_arp));

    msg_sync_arp *m = (msg_sync_arp *)pmsg->buffer;
    m->ifindex = dev->ifindex;
    if (family == AF_INET) {
        m->addr.addr = *(spl_ip4_addr_t *)ipaddr;
        m->addr.type = SPL_IP_ADDR_TYPE_V4;
    } else {
        (void)memcpy_s(m->addr.ip6.addr, sizeof(m->addr.ip6.addr), ipaddr, sizeof(m->addr.ip6.addr));
        m->addr.ip6.zone = 0;
        m->addr.type = SPL_IP_ADDR_TYPE_V6;
    }
    m->nud_state = nud_state;
    m->ha = ha;
    int ret = msg_try_post(pmsg, get_instance_control_box(0));
    if (ret < 0) {
        NS_ERR("failed to post msg");
        return ret;
    }
    return 0;
}

static void ns_rttick_event(void)
{
    data_com_msg *pmsg = sbr_msg_malloc(false);
    if (pmsg == NULL) {
        NS_ERR("could not allocate pmsg");
        return;
    }
    pmsg->param.type = ROUTE_TICK_UPDATE;
    pmsg->param.op_type = MSG_ASYN_POST;
    pmsg->param.buffer_len = (u32)MSG_SIZE(0);
    int ret = msg_try_post(pmsg, get_instance_control_box(0));
    if (ret < 0) {
        NS_ERR("failed to post msg");
    }
}

void sbr_dpa_cpu_overload_times_inc(void)
{
    g_dpa_cpu_overload_times++;
}

void sbr_dpa_cpu_overload_times_reset(void)
{
    g_dpa_cpu_overload_times = 0;
}

u8 sbr_dpa_cpu_overload_times_get(void)
{
    return g_dpa_cpu_overload_times;
}

static int ns_net_event(struct notifier_block *notifier, unsigned long event, void *ptr)
{
    struct eth_addr *ha;
    struct neighbour *neigh = ptr;
    struct net_device *dev = neigh->dev;

    if (event == NETEVENT_NEIGH_UPDATE) {
        ha = (struct eth_addr *)neigh->ha;
        int family = neigh->ops->family;
        if (net_eq(dev_net(dev), &init_net) == 0) {
            return NOTIFY_DONE;
        }
        (void)notify_nd_event((void*)neigh->primary_key, *ha, neigh->nud_state, family, dev);
    }
    return NOTIFY_DONE;
}

static struct notifier_block g_ns_net_notifier = {
    .notifier_call = ns_net_event
};

#ifdef CONFIG_DPA_PROTO
static void ns_rttick_event_wrap(void *unused)
{
    (void)unused;
    ns_rttick_event();
}
#endif

void init_cooperation(void)
{
    INIT_LIST_HEAD(&g_coop_migrate_a2d_list);
    dmm_spin_init(&g_coop_migrate_a2d_list_lock);
    register_inetaddr_notifier(&g_ip_notifier);
#if SPL_IPV6
    register_inet6addr_notifier(&g_ip6_addr_notifier);
#endif
    register_netevent_notifier(&g_ns_net_notifier);
#ifdef CONFIG_DPA_PROTO
    REGISTER_HCK_VH(dpa_rt_tick, ns_rttick_event_wrap);
#else
    register_rttick_notify(ns_rttick_event);
#endif
}

_Static_assert(sizeof(msg_tcp_migrate_a2d) <= MSG_BUF_SIZE, "size of msg_tcp_migrate_a2d exceeds limit");
_Static_assert(sizeof(struct sack_block) == sizeof(struct tcp_sack_block), "size of sack_block exceeds limit");
_Static_assert(sizeof(struct rtt_minmax) == sizeof(struct minmax), "size of rtt_minmax exceeds limit");
