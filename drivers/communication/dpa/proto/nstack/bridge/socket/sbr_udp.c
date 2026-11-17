/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#include <net/ipv6.h>
#include "socket/sbr_prot_com.h"
#include "msg/bridge_msg_producer.h"
#include "cooperation/cooperation.h"
#include "common_msg.h"
#include "securec.h"
#include "ip_addr.h"
#include "socket/sbr_socket.h"
#include "sbr_res_mgr.h"
#include "sbr_udp.h"
#include "stack_time.h"
#include "tc_interface.h"
#include "sys_ifidx_convert.h"
#include "dfx/global_res_stats.h"
#include "dfx/conn_stats.h"
#define SBUF_UDP_LEN (FRAME_MTU + ETHER_HLEN)

static s32 sbr_udp_migrate_a2d(sbr_socket_t *sk)
{
    s32 ret = coop_udp_migrate_a2d(sk->sk);
    if (ret == -EOPNOTSUPP) {
        sbr_migrate_a2d_not_support_inc();
    }
    if (ret != 0 && ret != -EOPNOTSUPP) {
        sbr_migrate_a2d_failed_inc();
    }

    return ret;
}

static s32 sbr_udp_migrate_d2a(sbr_socket_t *sk)
{
    sbr_migrate_d2a_request_inc();
    s32 ret = coop_udp_migrate_d2a(sk->sk);
    if (ret != 0) {
        sbr_migrate_d2a_failed_inc();
    } else {
        sbr_migrate_d2a_success_inc();
    }

    return ret;
}

static s32 sbr_udp_setsockopt(sbr_socket_t *sk, s32 level, s32 optname, const void *optval, socklen_t optlen)
{
    NS_DBG("udp setsockopt]fd=%d,level=%d,optname=%d", sk->fd, level, optname);
    s32 err;

    switch (level) {
        case SOL_SOCKET:
            err = sbr_setsockopt_sol_socket(sk, optname, optval, optlen);
            break;
        case IPPROTO_IP:
            err = sbr_setsockopt_ipproto_ip(optname, optlen, CONN_TYPE_UDP);
            break;
#if SPL_IPV6
        case IPPROTO_IPV6:
            err = sbr_setsockopt_ipproto_ipv6(optname, optval, optlen, CONN_TYPE_UDP);
            break;
#endif
        default:
            err = ENOPROTOOPT;
            break;
    }

    if (err != 0) {
        NS_WAR("fail]udp fd=%d,level=%d,optname=%d,err=%d", sk->fd, level, optname, err);
        return -err;
    }
    return sbr_handle_setsockopt(sk, level, optname, optval, optlen);
}

static s32 sbr_udp_recvmsg(sbr_socket_t *sk, struct msghdr *msg, size_t size, int flags)
{
    sbr_global_stat_cnt_inc(GLOBAL_RX_SBR_UDP_IN);
    int addr_len = 0;
    int ret = 0;
    int err = sk->save_prot->recvmsg(sk->sk, msg, size, flags & MSG_DONTWAIT, flags & ~MSG_DONTWAIT, &addr_len);
    if (err >= 0) {
        msg->msg_namelen = addr_len;
        sbr_global_stat_update(GLOBAL_RX_SBR_UDP_OUT, 0, (u32)err);
        sbr_conn_stat_update(sk->stats, SBR_RX_APP_OUT, 0, (u32)err);
        ret = get_gro_rcv(sk, msg, err);
    } else {
        NS_ERR("sbr_udp_recvmsg err=%d, fd=%d, id=%d, flags=%d", err, sk->fd, sk->sk_id, flags);
        sbr_global_stat_cnt_inc(GLOBAL_RX_SBR_UDP_OUT_ERR);
        sbr_conn_stat_cnt_inc(sk->stats, SBR_RX_APP_UDP_OUT_ERR);
    }

    return err;
}

static s32 sbr_validate_udp_addr_info(const sbr_socket_t *sk, sa_family_t family,
    sa_family_t conn_family, socklen_t tolen)
{
    if (family == AF_INET) {
        if (tolen < sizeof(struct sockaddr_in)) {
            NS_WAR("invalid address len]fd=%d,tolen=%u", sk->fd, tolen);
            return -EINVAL;
        }

        if (conn_family != AF_INET) {
            NS_WAR("family is not equal]fd=%d, socket_domain=%hu, name_family:%hu namelen=%d",
                sk->fd, conn_family, family, tolen);
            return -EAFNOSUPPORT;
        }
    }
#if SPL_IPV6
    else if (family == AF_INET6) {
        if (tolen < sizeof(struct sockaddr_in6)) {
            NS_WAR("invalid address len]fd=%d,tolen=%u", sk->fd, tolen);
            return -EINVAL;
        }

        if (conn_family != AF_INET6) {
            NS_WAR("family is not equal]fd=%d, socket_domain=%d, name_family:%d namelen=%d", sk->fd,
                conn_family, family, tolen);
            return -EAFNOSUPPORT;
        }
    }
#endif
    else {
        NS_WAR("invalid address family]fd=%d,family=%hu", sk->fd, family);
        return -EAFNOSUPPORT;
    }

    return 0;
}

static s32 sbr_udp_fill_netbuf(sbr_socket_t *sk, const struct sockaddr *to,
    socklen_t tolen, struct netbuf *buf)
{
    sa_family_t family = to != NULL ? to->sa_family : AF_UNSPEC;
    sa_family_t conn_family = (sa_family_t)sbr_sk_family(sk);

    if (family == AF_UNSPEC) {
        family = conn_family;
    }
    if (to != NULL) {
        s32 ret = sbr_validate_udp_addr_info(sk, family, conn_family, tolen);
        if (ret != 0) {
            return ret;
        }
    } else if (sk->sk->sk_dport == 0) {
        return -EDESTADDRREQ;
    }

    if (family == AF_INET) {
        const struct sockaddr_in *to_in = (const struct sockaddr_in *)to;
        const struct in_addr *sin_addr = to_in == NULL ? (struct in_addr *)&sk->sk->sk_daddr :
            &to_in->sin_addr;
        u16 port = to_in == NULL ? ntohs(sk->sk->sk_dport) : ntohs(to_in->sin_port);
        NS_DBG("fd=%d,addr=*.*.%u.%u,port=%hu", sk->fd,
            FUZZY_IP_VAR(&sin_addr->s_addr), port);
        spl_ip4_addr_cast_from_inaddr(spl_ip_addr_get_ipv4_ptr(&buf->addr), sin_addr);
        spl_ip_addr_set_type(&buf->addr, SPL_IP_ADDR_TYPE_V4);
        buf->port = port;
    }

#if SPL_IPV6
    if (family == AF_INET6) {
        const struct sockaddr_in6 *to_in6 = (const struct sockaddr_in6 *)to;
        const struct in6_addr *sin6_addr = to_in6 == NULL ? &sk->sk->sk_v6_daddr : &to_in6->sin6_addr;
        u16 port = to_in6 == NULL ? ntohs(sk->sk->sk_dport) : ntohs(to_in6->sin6_port);
        s32 addr_type = ipv6_addr_type(sin6_addr);
        if (((u32)addr_type & IPV6_ADDR_MAPPED) != 0) {
            struct in_addr sin_addr;
            sin_addr.s_addr = to_in6 == NULL ? sk->sk->sk_daddr :
                sin6_addr->s6_addr32[3];
            NS_DBG("fd=%d,addr=*.*.%u.%u,port=%hu", sk->fd,
                FUZZY_IP_VAR(&sin_addr.s_addr), port);
            spl_ip4_addr_cast_from_inaddr(spl_ip_addr_get_ipv4_ptr(&buf->addr), &sin_addr);
            spl_ip_addr_set_type(&buf->addr, SPL_IP_ADDR_TYPE_V4);
        } else {
            inet6_addr_to_ip6addr(IP6OFX_W(&buf->addr), (struct spl_in6_addr *)sin6_addr);
            spl_ip_addr_set_type(&buf->addr, SPL_IP_ADDR_TYPE_V6);
            if (conn_family == AF_INET) {
                NS_WAR("family is not equal]fd=%d can't support IPV6 addr %s",
                    sk->fd, ip6_fuzzy(&buf->addr.ip6));
                return -EAFNOSUPPORT;
            }
            NS_DBG("fd=%d,addr=%s,port=%d", sk->fd, ip6_fuzzy(&buf->addr.ip6), port);
        }

        buf->port = port;
    }
#endif

    if (buf->port == 0U) {
        return -EDESTADDRREQ;
    }
    return 0;
}

static long sbr_udp_wait_for_wmem(struct sock *sk, long timeo)
{
    DEFINE_WAIT(wait);
    sbr_socket_t *sbr_sock = inet_sk(sk)->dpa_ctx;

    sk_clear_bit(SOCKWQ_ASYNC_NOSPACE, sk);
    for (;;) {
        if (!timeo)
            break;
        if (signal_pending(current))
            break;
        set_bit(SOCK_NOSPACE, &sk->sk_socket->flags);
        prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
        if (sbr_msg_queue_empty_lock() && (sbr_sock->tx_sbuf_num > 0 || dmm_atomic_get(get_global_tx_num())) > 0)
            break;
        if (sk->sk_shutdown & SEND_SHUTDOWN)
            break;
        if (sk->sk_err)
            break;
        release_sock(sk);
        timeo = schedule_timeout(timeo);
        lock_sock(sk);
    }
    finish_wait(sk_sleep(sk), &wait);
    return timeo;
}

static struct sk_buff *sbr_udp_walloc_skb(sbr_socket_t *sk, int size, gfp_t gfp, bool noblock)
{
    struct sk_buff *skb;
    struct sock *lsk = sk->sk;
    int tot_size;
    long timeo;
    int err;
    bool is_global_buf = false;

    timeo = sock_sndtimeo(lsk, noblock);
    for (;;) {
        err = sock_error(lsk);
        if (err != 0)
            return ERR_PTR(err);

        err = -EPIPE;
        if (lsk->sk_shutdown & SEND_SHUTDOWN)
            return ERR_PTR(err);
        if (sbr_msg_queue_empty_lock()) {
            sbr_sk_remove_msg_wq(sk);
            if (sk->tx_sbuf_num > 0) {
                break;
            } else if (is_global_tx_num_available(1) == 0) {
                dmm_atomic_inc(&get_dfx_sock_info()->global_tx_buf_alloc);
                is_global_buf = true;
                break;
            }
        } else {
            sbr_sk_add_msg_wq(sk);
        }
        sk_set_bit(SOCKWQ_ASYNC_NOSPACE, lsk);
        set_bit(SOCK_NOSPACE, &lsk->sk_socket->flags);
        err = -EAGAIN;
        if (!timeo)
            return ERR_PTR(err);
        if (signal_pending(current)) {
            err = sock_intr_errno(timeo);
            return ERR_PTR(err);
        }
        timeo = sbr_udp_wait_for_wmem(lsk, timeo);
    }

    tot_size = ALIGN(size, 4);
    /* alloc memory for shared_info implicitly */
    u64 data = stack_maa_alloc((size_t)tot_size);
    if (data == 0) {
        err = -SPL_ENOMEM;
        goto ERR;
    }
    void *convert_addr = stack_mem_convert(data);
    if (convert_addr == NULL) {
        stack_maa_free(data, MAA_FLAG_PAGE);
        err = -SPL_EFAULT;
        goto ERR;
    }

    skb = sbr_build_skb(convert_addr, (unsigned int)(tot_size + SKB_DATA_ALIGN(sizeof(struct skb_shared_info))), 1);
    if (likely(skb)) {
        struct sbr_udp_skb_cb *ucb = SBR_UDP_SKB_CB(skb);
        ucb->maa_addr = data;
        if (is_global_buf) {
            ucb->is_global_buf = 1;
        } else {
            ucb->is_global_buf = 0;
            sk->tx_sbuf_num--;
            dmm_atomic_inc(&get_dfx_sock_info()->conn_tx_buf_alloc);
        }
        skb->destructor = sbr_destruct_tx_skb;
        skb->sk = lsk;
        refcount_add(skb->truesize, &lsk->sk_wmem_alloc);

        /*
         * Make sure that we have exactly size bytes
         * available to the caller, no more, no less.
         */
        skb->reserved_tailroom = skb->end - skb->tail - size;
        return skb;
    }
    stack_maa_free(data, MAA_FLAG_PAGE);
    err = -SPL_ENOBUFS;
ERR:
    if (is_global_buf) {
        dmm_atomic_inc(get_global_tx_num());
        dmm_atomic_inc(&get_dfx_sock_info()->global_tx_buf_revert);
    }
    return ERR_PTR(err);
}

static s32 sbr_udp_send_alloc_buf(sbr_socket_t *sk, struct msghdr *msg, size_t size, u16 mtu,
    struct sk_buff **skb_udp, bool is_v6)
{
    u16 max_len = (u16)SPL_MIN(((u32)ETHER_HLEN + (u32)mtu), SBUF_DATA_MAX_LEN);
    u16 head_len = ETHER_HLEN + IP_HLEN + UDP_HLEN;
    u16 ipv6_ext_hlen = is_v6  ? (IP6_HLEN - IP_HLEN) : 0;
    u64 maa;
    struct sk_buff *skb;
    struct sock *lsk = sk->sk;
    /* For IPv6
     * ETH_HEADER / IP_HEADER / IPV6_EXTEN /  UDP_HEADER / DATA
     * |------------------------HEADER-------------------|-------------payload----------|
     * SBUF_UDP_LEN : mtu + 14
     * head_len : 42(ipv4) / 62(ipv6)
     */
    head_len += ipv6_ext_hlen;
    if (size > (max_len - head_len)) {
        NS_ERR("sk_id=%lu, fd=%d, should not send pkt over mtu, size=%u", sk->sk_id, sk->fd, size);
        return -EINVAL;
    }

    bool noblock = !!(msg->msg_flags & MSG_DONTWAIT);
    u16 alloc_len = head_len + size;
    skb = sbr_udp_walloc_skb(sk, alloc_len, lsk->sk_allocation, noblock);
    if (IS_ERR(skb)) {
        NS_ERR("sk_id=%lu, fd=%d, sbr_udp_walloc_skb fail, err=%d", sk->sk_id, sk->fd, (s32)PTR_ERR(skb));
        return (s32)PTR_ERR(skb);
    }

    skb_reserve(skb, head_len);
    skb->ip_summed = CHECKSUM_UNNECESSARY;
    int err = skb_add_data_nocache(lsk, skb, &msg->msg_iter, size);
    if (err) {
        sbr_udp_send_head_free(sk, skb);
        NS_ERR("sk_id=%lu, fd=%d, skb_add_data_nocache fail", sk->sk_id, sk->fd);
        return -EFAULT;
    }
    maa = SBR_UDP_SKB_CB(skb)->maa_addr;
    maa_cache_map(maa);
    __skb_header_release(skb);
    skb_frag_list_init(skb);

    *skb_udp = skb;
    return 0;
}

static bool sbr_check_addr_support(const ip_addr_t *addr)
{
    if (addr->type == SPL_IP_ADDR_TYPE_V4) {
        if (spl_ip4_addr_is_multicast(IP4OFX(addr)) || spl_ipv4_addr_is_lbcast(IP4OFX(addr)) ||
            spl_ip4_addr_is_loopback(IP4OFX(addr))) {
            return false;
        }
    } else {
        if (ip6_addr_isloopback(IP6OFX(addr)) || spl_ip6_addr_ismulticast(IP6OFX(addr))) {
            return false;
        }
    }
    return true;
}

static void sbr_get_local_addr(sbr_socket_t *sk, ip_addr_t *local_ip)
{
    if (sbr_sk_isv6(sk)) {
        inet6_addr_to_ip6addr(IP6OFX_W(local_ip), (struct spl_in6_addr *)&sk->sk->sk_v6_rcv_saddr);
        if (ip6_addr_isipv4mappedipv6(IP6OFX_W(local_ip))) {
            local_ip->addr = local_ip->ip6.addr[3];
            spl_ip_addr_set_type(local_ip, SPL_IP_ADDR_TYPE_V4);
        } else {
            spl_ip_addr_set_type(local_ip, SPL_IP_ADDR_TYPE_V6);
        }
    } else {
        spl_ip4_addr_cast_from_inaddr(IP4OFX(local_ip), (struct in_addr *)&sk->sk->sk_rcv_saddr);
        spl_ip_addr_set_type(local_ip, SPL_IP_ADDR_TYPE_V4);
    }
}

static s32 sbr_udp_sendmsg(sbr_socket_t *sk, struct msghdr *msg, size_t size)
{
    sbr_global_stat_update(GLOBAL_TX_SBR_UDP_IN, 1, (u32)size);
    sbr_conn_stat_update(sk->stats, SBR_TX_APP_IN, 1, (u32)size);
    size_t max_len = IPV4_UDP_SEND_MAX_LEN;
    s32 err, ret;
    struct udp_sock *up = udp_sk(sk->sk);
    int corkreq = READ_ONCE(up->corkflag) || (msg->msg_flags & MSG_MORE);
    if (sk->status != SK_MIGRATE_OK || sk->fd < 0 || corkreq || msg->msg_controllen) {
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_GENERAL_ERR, 1, (u32)size);
        goto fallback;
    }

    if (msg->msg_flags & MSG_OOB) { /* Mirror BSD error message compatibility */
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_OOB_ERR, 1, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        return -EOPNOTSUPP;
    }

    struct netbuf buf;
    err = sbr_udp_fill_netbuf(sk, (struct sockaddr *)msg->msg_name, (socklen_t)msg->msg_namelen, &buf);
    if (err != 0) {
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_NETBUF_ERR, 1, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        return err;
    }
    if (buf.port == DNS_PORT) {
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_DNS_PORT_ERR, 1, (u32)size);
        goto fallback;
    }
    bool is_v6 = (buf.addr.type == SPL_IP_ADDR_TYPE_V6);
#if SPL_IPV6
    if (is_v6) {
        max_len = (size_t)(INT_MAX - sizeof(struct udphdr));
    }
#endif
    if (size > max_len) {
        NS_WAR("sk_id=%lu, fd=%d, size=%u over max len=%u", sk->sk_id, sk->fd, size, max_len);
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_LEN_ERR, 1, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        return -EMSGSIZE;
    }

    ip_addr_t local_ip;
    sbr_get_local_addr(sk, &local_ip);
    if (!sbr_check_addr_support(&buf.addr) || !sbr_check_addr_support(&local_ip)) {
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_ADDR_ERR, 1, (u32)size);
        goto fallback;
    }
    ip_addr_t nexthop;
    ip_addr_set_any(is_v6, &nexthop);
    s32 ifidx = get_route_for_send(sk, &buf.addr, buf.port, &local_ip, &nexthop);
    if (ifidx <= 0) {
        NS_ERR("sk_id=%lu, fd=%d, get route failed, ret=%d", sk->sk_id, sk->fd, ifidx);
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_ROUTE_ERR, 1, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        return ifidx;
    }

    if (!is_nic_valid_check_by_id(ifidx)) {
        NS_ERR("sk_id=%lu, fd=%d, net_device NULL", sk->sk_id, sk->fd);
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_GET_VID_ERR, 1, (u32)size);
        goto fallback;
    }
    struct net_device *dev = dev_get_by_index(sock_net(sk->sk), ifidx);
    if (dev == NULL) {
        NS_ERR("net_device NULL]fd=%d", sk->fd);
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_DEVICE_ERR, 1, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        return -ENODEV;
    }

    if (strncmp(dev->name, "lo", IFNAMSIZ) == 0) {
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_LO_ERR, 1, (u32)size);
        dev_put(dev);
        goto fallback;
    }

    u16 ip_hdr_len = (local_ip.type == SPL_IP_ADDR_TYPE_V4) ? IP_HLEN : IP6_HLEN;
    u16 tot_hdr_len = ip_hdr_len + UDP_HLEN;
    u16 mtu = (u16)dev->mtu;
    if ((mtu < tot_hdr_len) || (size > (mtu - tot_hdr_len))) {
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_LEN_ERR, 1, (u32)size);
        dev_put(dev);
fallback:
        release_sock(sk->sk);
        NS_DBG("sk_id=%lu, fd=%d, send fallback", sk->sk_id, sk->fd);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        err = sk->save_prot->sendmsg(sk->sk, msg, size);
        lock_sock(sk->sk);
        return err;
    }
    dev_put(dev);

#if CONFIG_DPA_TC
    /* for bpf&netfilter */
    struct sock *lsk = sk->sk;
    DECLARE_SOCKADDR(struct sockaddr_in *, usin, msg->msg_name);
    if (usin || lsk->sk_state != TCP_ESTABLISHED) {
        ret = tc_udp_bpf(sk, msg);
        if (ret) {
            NS_WAR("BPF_CGROUP_RUN_PROG_UDP4/6_SENDMSG_LOCK error:%d", ret);
            sbr_global_stat_update(GLOBAL_TX_SBR_UDP_BPF_ERR, 1, (u32)size);
            sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
            return ret;
        }
    }
#endif
    struct sk_buff *skb_udp = NULL;
    err = sbr_udp_send_alloc_buf(sk, msg, size, mtu, &skb_udp, is_v6);
    if (err < 0) {
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_MEM_ERR, 1, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        return err;
    }

#if COST_TIME_STAT
        if (sbr_cost_time_stat_is_enabled()) {
            skb_udp->tstamp = stack_get_stat_time();
        } else {
            skb_udp->tstamp = 0;
        }
#endif
    struct sbr_udp_skb_cb *ucb = SBR_UDP_SKB_CB(skb_udp);
    ucb->ifidx = (u8)ifidx;
    ucb->addr_type = buf.addr.type;
    ucb->remote_port = buf.port;

    skb_udp->protocol = is_v6 ? htons(ETH_P_IPV6) : htons(ETH_P_IP);
    skb_udp->transport_header = skb_udp->data - sizeof(struct udphdr) - skb_udp->head;
    if (skb_udp->protocol == htons(ETH_P_IP)) {
        skb_udp->network_header = skb_transport_header(skb_udp)  - sizeof(struct iphdr) - skb_udp->head;
        struct iphdr *ip_hdr = (struct iphdr *)skb_network_header(skb_udp);
        ip_hdr->saddr = local_ip.addr;
        ip_hdr->daddr = buf.addr.addr;
        ip_hdr->protocol = SPL_IPPROTO_UDP;
        ucb->nexthop.addr.s_addr = nexthop.addr;
    } else {
        skb_udp->network_header = skb_transport_header(skb_udp) - sizeof(struct ipv6hdr) - skb_udp->head;
        struct ipv6hdr *ip6_hdr = (struct ipv6hdr *)skb_network_header(skb_udp);
        ip6_hdr->saddr = *((struct in6_addr *)&local_ip.ip6);
        ip6_hdr->daddr = *((struct in6_addr *)&buf.addr.ip6);
        ip6_hdr->nexthdr = SPL_IPPROTO_UDP;
        ucb->nexthop.addr6 = *((struct spl_in6_addr *)&nexthop.ip6);
    }
#if CONFIG_DPA_TC
    struct dst_entry *dst;
    if (skb_udp->protocol == htons(ETH_P_IP)) {
        dst = sk_dst_check(lsk, 0);
    } else {
        dst = sk_dst_check(lsk, inet6_sk(lsk)->dst_cookie);
    }
    if (dst) {
        skb_udp->dev = dst->dev;
    }
    skb_dst_set(skb_udp, dst);
    skb_udp->pkt_type = PACKET_OUTGOING;
    skb_udp->mac_header = skb_network_header(skb_udp) - ETH_HLEN - skb_udp->head;
    struct udphdr *udph = (struct udphdr *)skb_transport_header(skb_udp);
    udph->source = htons(lsk->sk_num);
    udph->dest = buf.port;
    ret = tc_udp_send_skb(skb_udp);
    skb_udp->_skb_refdst = 0UL;
    skb_udp->dev = NULL;
    dst_release(dst);
    if (ret != 0) {
        NS_ERR("sk_id=%lu, fd=%d, tc_udp_send_skb bpf&netfilter fail", sk->sk_id, sk->fd);
        sbr_global_stat_update(GLOBAL_TX_SBR_UDP_BPF_ERR, 1, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 1, (u32)(size));
        sbr_udp_send_head_free(sk, skb_udp);
        return (s32)size;
    }
#endif

    ret = sbr_handle_udp_send(sk, skb_udp);
    if (ret != 0) {
        return -EAGAIN;
    }
    sbr_global_stat_update(GLOBAL_TX_SBR_UDP_OUT, 1, (u32)size);
    sbr_conn_stat_update(sk->stats, SBR_TX_APP_OUT, 1, (u32)size);
    return (s32)size;
}

static s32 sbr_udp_close(sbr_socket_t *sk, bool need_rst)
{
    int ret = sbr_handle_close(sk, need_rst);
    return ret;
}

static sbr_fdopt g_udp_fdopt = {
    .migrate_a2d = sbr_udp_migrate_a2d,
    .migrate_d2a = sbr_udp_migrate_d2a,
    .getsockopt = NULL,
    .setsockopt = sbr_udp_setsockopt,
    .recvmsg = sbr_udp_recvmsg,
    .sendmsg = sbr_udp_sendmsg,
    .close = sbr_udp_close,
};

sbr_fdopt *sbr_get_udp_fdopt(void)
{
    return &g_udp_fdopt;
}
