/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#include <linux/types.h>
#include <linux/version.h>
#include <net/ip6_route.h>
#include <linux/errno.h>
#include <linux/socket.h>     // low version linux needs for struct sockaddr
#include <linux/route.h>
#include "net/udp.h"
#include "msg/bridge_msg_producer.h"
#include "securec.h"
#include "sbr_res_mgr.h"
#include "ip_addr.h"
#include "stack_mem.h"
#include "opt.h"
#include "socket/sbr_prot_com.h"
#include "stack_time.h"
#include "tc_interface.h"
#include "cooperation/cooperation.h"
#include "dfx/chr_stats.h"
#include "dfx/global_res_stats.h"
#include "dfx/conn_stats.h"

static dmm_atomic_t g_tx_dra_alloc_num;
static dmm_atomic_t g_rx_dra_alloc_num = ATOMIC_INIT(0);

#if COST_TIME_STAT
hds_pkt_fn_t g_sbr_time_stat_cb = NULL;
#endif

static dmm_atomic_t g_global_tx_buf_num;

dmm_atomic_t *get_global_tx_num(void)
{
    return &g_global_tx_buf_num;
}

void global_tx_num_init(void)
{
    dmm_atomic_set(&g_global_tx_buf_num, GLOBAL_TX_BUF_POOL_SIZE);
}

s32 is_global_tx_num_available(u32 num)
{
    u32 old_val, new_val;
    do {
        old_val = dmm_atomic_read(&g_global_tx_buf_num);
        if (num > old_val) {
            return -SPL_ENOMEM;
        }
        new_val = old_val - num;
    } while (!dmm_atomic_swap(&g_global_tx_buf_num, old_val, new_val));
    return 0;
}

static s32 sbr_sockopt_ipproto_common(s32 optname, socklen_t optlen, conn_type_t type)
{
    s32 err = 0;

    switch (optname) {
        case IP_TOS:
        case IP_TTL:
            if (optlen < (socklen_t)sizeof(u8)) {
                err = EINVAL;
            }
            break;
        case IP_MULTICAST_TTL:
            if (optlen < (socklen_t)sizeof(u8)) {
                err = EINVAL;
                break;
            }

            if (type != CONN_TYPE_UDP) {
                err = EAFNOSUPPORT;
                break;
            }
            break;
        case IP_MULTICAST_IF:
            if (optlen < (socklen_t)sizeof(struct in_addr)) {
                err = EINVAL;
                break;
            }

            if (type != CONN_TYPE_UDP) {
                err = EAFNOSUPPORT;
                break;
            }
            break;
        case IP_MULTICAST_LOOP:
        case IP_MULTICAST_ALL:
            if (optlen < (socklen_t)sizeof(u8)) {
                err = EINVAL;
                break;
            }

            if (type != CONN_TYPE_UDP) {
                err = EAFNOSUPPORT;
                break;
            }
            break;
        case IP_PKTINFO:
            if (optlen < (socklen_t)sizeof(char)) {
                err = EINVAL;
                break;
            }

            if (type != CONN_TYPE_UDP) {
                err = EAFNOSUPPORT;
                break;
            }
            break;
        case IP_MTU_DISCOVER:
            if (optlen < (socklen_t)sizeof(u8)) {
                err = EINVAL;
            }
            break;
        default:
            err = ENOPROTOOPT;
            break;
    }

    return err;
}

static s32 sbr_set_priority(const s32 *optval, socklen_t optlen)
{
    if (optlen < sizeof(s32)) {
        return EINVAL;
    }

    s32 priority = *optval;
    if ((priority < 0) || (priority >= VLAN_PRIO_MAX)) {
        return EINVAL;
    }
    return 0;
}

s32 sbr_setsockopt_sol_socket(sbr_socket_t *sk, s32 optname, const void *optval, socklen_t optlen)
{
    s32 err = 0;

    switch (optname) {
        case SO_MARK:
            if (!ns_capable(sock_net(sk->sk)->user_ns, CAP_NET_ADMIN)) {
                return EPERM;
            }
            if (optlen < sizeof(u32)) {
                return EINVAL;
            }
            if (sk->sk->sk_mark != *(u32 *)optval) {
                sk->sk->sk_mark = *(u32 *)optval;
                sk_dst_reset(sk->sk);
            }
            break;
#if SPL_REUSEPORT
        case SO_REUSEPORT:
#endif
        case SO_REUSEADDR:
        case SO_BROADCAST:
        case SO_KEEPALIVE:
        case SO_RCVBUF:
        case SO_SNDBUF:
        case SO_TIMESTAMP:
        case SO_TIMESTAMPING:
            if (optlen < sizeof(s32)) {
                err = EINVAL;
            }
            break;
        case SO_PRIORITY:
            err = sbr_set_priority((s32 *)optval, optlen);
            break;
        case SO_RCVTIMEO_NEW:
        case SO_RCVTIMEO_OLD:
        case SO_SNDTIMEO_NEW:
        case SO_SNDTIMEO_OLD:
            err = 0;
            break;
        case SO_LINGER:
            if (optlen < sizeof(struct linger)) {
                err = EINVAL;
            }
            break;
        case SO_BINDTODEVICE:
            if ((s32)optlen < 0) {
                err = EINVAL;
            }
            break;
        default:
            err = ENOPROTOOPT;
            break;
    }

    return err;
}

s32 sbr_setsockopt_ipproto_ip(s32 optname, socklen_t optlen, conn_type_t type)
{
    s32 err = 0;

    switch (optname) {
        case IP_ADD_MEMBERSHIP:
        case IP_DROP_MEMBERSHIP:
            if (optlen < (socklen_t)sizeof(struct ipmreq)) {
                err = EINVAL;
                break;
            }

            if (type != CONN_TYPE_UDP) {
                err = EAFNOSUPPORT;
                break;
            }
            break;
        default:
            err = sbr_sockopt_ipproto_common(optname, optlen, type);
            break;
    }

    return err;
}

#if SPL_IPV6
s32 sbr_setsockopt_ipproto_ipv6(s32 optname, const void *optval, socklen_t optlen, conn_type_t type)
{
    s32 err = 0;

    switch (optname) {
        case IPV6_RECVPKTINFO:
            if (optlen < sizeof(char)) {
                err = EINVAL;
            } else if (type != CONN_TYPE_UDP) {
                err = EAFNOSUPPORT;
            }
            break;
        case IPV6_TCLASS:
            if ((optlen < sizeof(s32)) || ((*(s32 *)optval) < -1) || ((*(s32 *)optval) > U8_MAX)) {
                err = EINVAL;
                break;
            }
            break;
        case IPV6_MTU_DISCOVER:
            if (optlen < sizeof(s32)) {
                err = EINVAL;
                break;
            }
            if ((*(s32 *)optval) < IPV6_PMTUDISC_DONT || (*(s32 *)optval) > IPV6_PMTUDISC_OMIT) {
                err = EINVAL;
                break;
            }
            break;
        case IPV6_V6ONLY:
            if (optlen < sizeof(s32)) {
                err = EINVAL;
            }
            break;
        case IPV6_UNICAST_HOPS:
            if (optlen < sizeof(int)) {
                err = EINVAL;
                break;
            }
            if ((*(s32 *)optval) > U8_MAX || (*(s32 *)optval) < -1) {
                err = EINVAL;
                break;
            }
            break;
        case IPV6_MULTICAST_HOPS:
            if (type != CONN_TYPE_UDP) {
                err = ENOPROTOOPT;
                break;
            }
            if (optlen < sizeof(int)) {
                err = EINVAL;
                break;
            }
            if ((*(s32 *)optval) > U8_MAX || (*(s32 *)optval) < -1) {
                err = EINVAL;
                break;
            }
            break;
        default:
            err = ENOPROTOOPT;
            break;
    }

    return err;
}
#endif

static int get_route_v6(sbr_socket_t *sk, const spl_ip6_addr_t *dst_addr, u16 dst_port,
    spl_ip6_addr_t *src_addr, spl_ip6_addr_t *nexthop, enum sbr_route_state state)
{
    int err = 0;
    struct sock *lsk = sk->sk;
    struct flowi6 fl6;
    struct dst_entry *dst = NULL;
    struct ipv6_pinfo *np = inet6_sk(lsk);
    if (np == NULL) {
        NS_WAR("sk_id=%lu, fd=%d, sk->sk_state=%hhu", sk->sk_id, sk->fd, lsk->sk_state);
    }
    (void)memset_s(&fl6, sizeof(fl6), 0, sizeof(fl6));

    fl6.flowi6_proto = (__u8)lsk->sk_protocol;
    memcpy_s(&fl6.daddr, sizeof(fl6.daddr), dst_addr->addr, sizeof(dst_addr->addr));
    memcpy_s(&fl6.saddr, sizeof(fl6.saddr), src_addr->addr, sizeof(src_addr->addr));
    fl6.fl6_dport = dst_port;
    fl6.fl6_sport = lsk->sk_num;
    fl6.flowi6_oif = lsk->sk_bound_dev_if;
    fl6.flowi6_mark = lsk->sk_mark;
    fl6.flowi6_uid = lsk->sk_uid;
    if (!fl6.flowi6_oif && (np != NULL)) {
        fl6.flowi6_oif = np->ucast_oif;
    }
    if (state == SBR_ROUTE_STATE_SEND) {
        bool is_connected = !(ipv6_addr_any(&lsk->sk_v6_daddr));
        dst = ip6_sk_dst_lookup_flow(lsk, &fl6, NULL, is_connected);
    } else { /* SBR_ROUTE_STATE_CONNECT */
        dst = ip6_dst_lookup_flow(sock_net(lsk), lsk, &fl6, NULL);
    }
    if (IS_ERR(dst)) {
        err = (int)PTR_ERR(dst);
        return err;
    }

    if (spl_ip6_addr_is_any(src_addr)) {
        __be16 *daddr = fl6.saddr.s6_addr16;
        NS_INF("sk_id=%lu, fd=%d, in6_addr=%x:%x:*:*:*:*", sk->sk_id, sk->fd, ntohs(daddr[0]), ntohs(daddr[1]));
        spl_ip6_addr_cast_from_in6addr(src_addr, (struct spl_in6_addr *)&fl6.saddr);
    }

    struct rt6_info *rt6 = (struct rt6_info *)dst;
    const struct in6_addr *nexthop_in6 = rt6_nexthop(rt6, &fl6.daddr);
    spl_ip6_addr_cast_from_in6addr(nexthop, (struct spl_in6_addr *)nexthop_in6);
    NS_DBG("flags=%u, in6_addr=%x:*:*:*:*:*:*:%x", rt6->rt6i_flags, FUZZY_IPV6_VAR(nexthop));

    int ifidx = dst->dev->ifindex;
    if (state == SBR_ROUTE_STATE_SEND) {
        dst_release(dst);
    } else { /* SBR_ROUTE_STATE_CONNECT */
        ip6_dst_store(lsk, dst, NULL, NULL);
    }
    return ifidx;
}

static int get_route_for_send_v4(sbr_socket_t *sk, const spl_ip4_addr_t *dst_addr, u16 dst_port,
    spl_ip4_addr_t *src_addr, spl_ip4_addr_t *nexthop)
{
    int err = 0;
    struct sock *lsk = sk->sk;
    struct inet_sock *inet = inet_sk(lsk);
    struct flowi4 tmp_fl4;
    struct flowi4 *fl4;
    struct rtable *rt = NULL;
    s32 oif = lsk->sk_bound_dev_if;

    bool is_connected = !(ipv4_is_zeronet(lsk->sk_rcv_saddr));
    if (is_connected) {
        rt = (struct rtable *)sk_dst_check(lsk, 0);
    }

    if (rt == NULL) {
        struct net *net = sock_net(lsk);
        __u8 flow_flags = inet_sk_flowi_flags(lsk);
        fl4 = &tmp_fl4;
        if (!oif) {
            oif = inet->uc_index;
        }
        flowi4_init_output(fl4, oif, lsk->sk_mark, RT_TOS(inet->tos),
                   (__u8)RT_SCOPE_UNIVERSE, (__u8)lsk->sk_protocol,
                   flow_flags,
                   *dst_addr, *src_addr, dst_port, lsk->sk_num,
                   lsk->sk_uid);

        security_sk_classify_flow(lsk, flowi4_to_flowi(fl4));
        rt = ip_route_output_flow(net, fl4, lsk);
        if (IS_ERR(rt)) {
            err = (int)PTR_ERR(rt);
            return err;
        }
        if (is_connected) {
            sk_dst_set(lsk, dst_clone(&rt->dst));
        }

        if (*src_addr == IP_ADDR_ANY) {
            NS_INF("sk_id=%lu, fd=%d, send src ip set to %u.%u.*.*", sk->sk_id, sk->fd, SAFETY_IP_VAR(&fl4->saddr));
            *src_addr = fl4->saddr;
        }
    }

    *nexthop = rt_nexthop(rt, *dst_addr);
    NS_DBG("gw family=%u, *.*.%u.%u", rt->rt_gw_family, FUZZY_IP_VAR(nexthop));

    int ifidx = rt->dst.dev->ifindex;
    ip_rt_put(rt);
    return ifidx;
}

s32 get_route_for_send(sbr_socket_t *sk, const ip_addr_t *dst_addr, u16 dst_port, ip_addr_t *src_addr,
    ip_addr_t *nexthop)
{
    s32 ret = -EHOSTUNREACH;
    src_addr->type = dst_addr->type;
    nexthop->type = dst_addr->type;
    if (dst_addr->type == SPL_IP_ADDR_TYPE_V6) {
#if SPL_IPV6
        if (!sbr_sk_isv6(sk)) {
            NS_ERR("sk_id=%lu, fa=%d, not match ip addr type", sk->sk_id, sbr_sk_family(sk));
        }
        ret = get_route_v6(sk, IP6OFX(dst_addr), dst_port, IP6OFX_W(src_addr), IP6OFX_W(nexthop),
            SBR_ROUTE_STATE_SEND);
#endif
    } else if (dst_addr->type == SPL_IP_ADDR_TYPE_V4) {
        ret = get_route_for_send_v4(sk, IP4OFX(dst_addr), dst_port, IP4OFX(src_addr), IP4OFX(nexthop));
    } else {
        NS_ERR("sk_id=%lu, fa=%d, ip addr type=%u is not v4 or v6", sk->sk_id, sbr_sk_family(sk), dst_addr->type);
    }
    return ret;
}

int sbr_wait_migrate(sbr_socket_t *ssk, long *timeo_p)
{
    DEFINE_WAIT_FUNC(wait, woken_wake_function);
    int done;
    struct sock *sk = ssk->sk;
    long timeo = *timeo_p;

    if (ssk->status == SK_MIGRATE_OK || ssk->status == SK_CLOSE) {
        return 0;
    }

    if (*timeo_p > HZ) {
        *timeo_p = HZ;
        timeo -= HZ;
    }
    do {
        int rc;
        int err = sock_error(sk);
        if (err)
            return err;
        if (ssk->status != SK_MIGRATE_A2D && ssk->status != SK_MIGRATE_D2A)
            break;
        if (!*timeo_p)
            return -EAGAIN;

        add_wait_queue(sk_sleep(sk), &wait);
        sk->sk_write_pending++;
        release_sock(sk);
        rc = (ssk->status == SK_MIGRATE_OK || ssk->status == SK_CLOSE);
        if (!rc) {
            *timeo_p = wait_woken(&wait,
                        TASK_UNINTERRUPTIBLE,
                        *timeo_p);
        }
        sched_annotate_sleep();
        lock_sock(sk);
        if (!*timeo_p) {
            NS_ERR("sk_id=%lu, fd=%d, status %u", ssk->sk_id, ssk->fd, ssk->status);
            *timeo_p = (timeo > HZ) ? HZ : timeo;
            timeo -= *timeo_p;
        }
        done = (ssk->status == SK_MIGRATE_OK || ssk->status == SK_CLOSE);
        remove_wait_queue(sk_sleep(sk), &wait);
        sk->sk_write_pending--;
    } while (!done);

    if (ssk->status == SK_MIGRATE_OK || ssk->status == SK_CLOSE) {
        return 0;
    }
    return -EPIPE;
}

static void sbr_build_skb_around(struct sk_buff *skb,
                      void *data, unsigned int frag_size)
{
    struct skb_shared_info *shinfo;
    unsigned int size = frag_size ? : (unsigned int)ksize(data);

    size -= SKB_DATA_ALIGN(sizeof(struct skb_shared_info));

    /* Assumes caller memset cleared SKB */
    skb->truesize = SKB_TRUESIZE(size);
    refcount_set(&skb->users, 1);
    skb->head = data;
    skb->data = data;
    skb_reset_tail_pointer(skb);
    skb->end = skb->tail + size;
    skb->mac_header = (typeof(skb->mac_header))~0U;
    skb->transport_header = (typeof(skb->transport_header))~0U;

    /* make sure we initialize shinfo sequentially */
    shinfo = skb_shinfo(skb);
    size_t count = offsetof(struct skb_shared_info, dataref);
    (void)memset_s(shinfo, count, 0, count);
    atomic_set(&shinfo->dataref, 1);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 54)
    skb_set_kcov_handle(skb, kcov_common_handle());
#endif
}

static struct sk_buff *sbr_alloc_skb(void *data, unsigned int frag_size)
{
    struct sk_buff *skb;

    skb = kmem_cache_alloc(skbuff_head_cache, GFP_KERNEL);
    if (unlikely(!skb))
        return NULL;

    size_t count = offsetof(struct sk_buff, tail);
    (void)memset_s(skb, count, 0, count);

    sbr_build_skb_around(skb, data, frag_size);
    return skb;
}

struct sk_buff *sbr_build_skb(void *data, unsigned int frag_size, u8 head_frag)
{
    struct sk_buff *skb = sbr_alloc_skb(data, frag_size);
    if (skb && frag_size) {
        skb->head_frag = head_frag;
        if (head_frag && stack_is_pfmemalloc(data))
            skb->pfmemalloc = 1;
    }
    return skb;
}

static void sbr_skb_free_head(struct sk_buff *skb, u8 flags)
{
    if (skb->head_frag) {
        stack_maa_free((u64)stack_mem_to_page(skb->head), MAA_FLAG_PAGE | flags);
    } else {
        kfree(skb->head);
    }
}

void sbr_destruct_skb(struct sk_buff *head_skb)
{
    struct skb_shared_info *shinfo = skb_shinfo(head_skb);
    s32 i;
    if ((head_skb == NULL) || (head_skb->head == NULL)) {
        return;
    }
    for (i = 0; i < shinfo->nr_frags; i++) {
        stack_maa_page_free(skb_frag_page(&shinfo->frags[i]), skb_frag_off(&shinfo->frags[i]));
    }
    global_rx_dra_num_sub(shinfo->nr_frags);
    struct sk_buff *tmp = shinfo->frag_list;
    while (tmp != NULL) {
        struct sk_buff *next = tmp->next;
        tmp->destructor = sbr_destruct_skb;
        kfree_skb(tmp);
        tmp = next;
    }

    sbr_skb_free_head(head_skb, MAA_FLAG_UNMAP);
    head_skb->head = NULL;
}

void sbr_tcp_rx_destruct_skb(struct sk_buff *head_skb)
{
    struct skb_shared_info *shinfo = skb_shinfo(head_skb);
    s32 i;
    sock_rfree(head_skb);
    if ((head_skb == NULL) || (head_skb->head == NULL)) {
        return;
    }
    for (i = 0; i < shinfo->nr_frags; i++) {
        stack_maa_page_free(skb_frag_page(&shinfo->frags[i]), skb_frag_off(&shinfo->frags[i]));
    }
    global_rx_dra_num_sub(shinfo->nr_frags);
    struct sk_buff *tmp = shinfo->frag_list;
    while (tmp != NULL) {
        struct sk_buff *next = tmp->next;
        tmp->destructor = sbr_destruct_skb;
        kfree_skb(tmp);
        tmp = next;
    }

    sbr_skb_free_head(head_skb, MAA_FLAG_UNMAP);
    head_skb->head = NULL;
}

void sbr_destruct_tx_skb(struct sk_buff *head_skb)
{
    struct sk_buff *next;

    if ((head_skb == NULL) || (head_skb->head == NULL)) {
        return;
    }

    struct sk_buff *skb = skb_shinfo(head_skb)->frag_list;
    skb_frag_list_init(head_skb);

    while (skb != NULL) {
        next = skb->next;
        u64 maa = SBR_COMM_SKB_CB(skb)->maa_addr;
        stack_maa_free(maa, skb->head_frag ? MAA_FLAG_PAGE : 0);
        skb->head = NULL;
        skb->next = NULL;
        __kfree_skb(skb);
        skb = next;
    }

    u64 maa = SBR_COMM_SKB_CB(head_skb)->maa_addr;
    stack_maa_free(maa, head_skb->head_frag ? MAA_FLAG_PAGE : 0);
    head_skb->head = NULL;
}

void sbr_udp_send_head_free(sbr_socket_t *sk, struct sk_buff *head_skb)
{
    struct sock *lsk = sk->sk;
    struct sk_buff *skb;
    if (head_skb == NULL) {
        return;
    }

    struct sbr_udp_skb_cb *ucb = SBR_UDP_SKB_CB(head_skb);
    if (ucb->is_global_buf == 1) {
        dmm_atomic_inc(get_global_tx_num());
        dmm_atomic_inc(&get_dfx_sock_info()->global_tx_buf_revert);
    } else {
        sk->tx_sbuf_num++;
        dmm_atomic_inc(&get_dfx_sock_info()->conn_tx_buf_revert);
    }
    skb = skb_shinfo(head_skb)->frag_list;
    while (skb != NULL) {
        refcount_add((int)(-skb->truesize), &lsk->sk_wmem_alloc);
        skb = skb->next;
    }

    refcount_add((int)(-head_skb->truesize), &lsk->sk_wmem_alloc);
    kfree_skb(head_skb);
}

void dump_memory(const char *level, u8 *addr, u32 len)
{
    const u8 *ptr = (const u8 *)addr;
    u32 i;
    /* print 8 bytes in one line */
    for (i = 0; i < len; i += 8) {
        u32 end = i + 8;
        end = end < len ? end : len;
        u32 j;
        for (j = i; j < end; j++) {
            printk("%s%02x", level, ptr[j]);
            if (j != end - 1) {
                printk("%s ", level);
            }
        }
        printk("%s\n", level);
    }
}

void bridge_skb_dump(const char *level, struct sk_buff *skb, int cnt)
{
    struct sk_buff *list_skb = NULL;
    printk("%sskb dump: shinfo->gso_size=%u, shinfo->gso_segs=%u\n",
        level, skb_shinfo(skb)->gso_size, skb_shinfo(skb)->gso_segs);
    printk("%sskb[%d]:%lx, head=%lx, data=%lx, len=%u, data_len=%u, truesize=%u, nr_frags=%u\n",
        level, cnt, (uintptr_t)skb, (uintptr_t)skb->head, (uintptr_t)skb->data, skb->len,
        skb->data_len, skb->truesize, skb_shinfo(skb)->nr_frags);
    printk("%stransport_header=%u, network_header=%u, mac_header=%u\n",
        level, skb->transport_header, skb->network_header, skb->mac_header);

    int i;
    for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
        skb_frag_t *frags = skb_shinfo(skb)->frags;
        printk("%sfrag[%d]:page=%lx, len=%u, offset=%u\n",
            level, i, (uintptr_t)frags[i].bv_page, frags[i].bv_len, frags[i].bv_offset);
    }
    if (skb_has_frag_list(skb)) {
        printk("%sfrag list %d:", level, cnt + 1);
        skb_walk_frags(skb, list_skb)
            bridge_skb_dump(level, list_skb, cnt + 1);
    }
}

u32 get_sk_addr(struct sock *sk, bool peer, ip_addr_t *addr)
{
    (void)memset_s(addr, sizeof(*addr), 0, sizeof(*addr));
    if (peer) {
        if (sk->sk_family == AF_INET6) {
            if (ipv6_addr_type(&sk->sk_v6_daddr) == IPV6_ADDR_MAPPED) {
                addr->addr = sk->sk_v6_daddr.s6_addr32[3];
                spl_ip_addr_set_type(addr, SPL_IP_ADDR_TYPE_V4);
                return IPV6_ADDR_MAPPED;
            } else {
                inet6_addr_to_ip6addr(IP6OFX_W(addr), (struct spl_in6_addr *)&sk->sk_v6_daddr);
                spl_ip_addr_set_type(addr, SPL_IP_ADDR_TYPE_V6);
            }
        } else {
            addr->addr = sk->sk_daddr;
            spl_ip_addr_set_type(addr, SPL_IP_ADDR_TYPE_V4);
        }
    } else {
        if (sk->sk_family == AF_INET6) {
            if (ipv6_addr_type(&sk->sk_v6_rcv_saddr) == IPV6_ADDR_MAPPED) {
                addr->addr = sk->sk_v6_rcv_saddr.s6_addr32[3];
                spl_ip_addr_set_type(addr, SPL_IP_ADDR_TYPE_V4);
                return IPV6_ADDR_MAPPED;
            } else {
                inet6_addr_to_ip6addr(IP6OFX_W(addr), (struct spl_in6_addr *)&sk->sk_v6_rcv_saddr);
                spl_ip_addr_set_type(addr, SPL_IP_ADDR_TYPE_V6);
            }
        } else {
            addr->addr = sk->sk_rcv_saddr;
            spl_ip_addr_set_type(addr, SPL_IP_ADDR_TYPE_V4);
        }
    }
    return 0;
}

void msg_iovs_free_with_unmap(msg_iov *iov, u32 segs, bool need_unmap_free, u32 unmap_end_index)
{
    u32 i;
    for (i = unmap_end_index; i < segs; i++) {
        msg_iov_free(&iov[i]);
    }
    if (!need_unmap_free) {
        return;
    }
    for (i = 0; i < unmap_end_index; i++) {
        if (iov->head_frag) {
            stack_maa_free((u64)stack_mem_to_page(stack_mem_convert(iov[i].base_addr)), MAA_FLAG_PAGE | MAA_FLAG_UNMAP);
        } else {
            stack_maa_free(iov[i].base_addr, 0);
        }
    }
}

static u32 get_iov_segs_total_len(msg_pkt_arrived *p)
{
    u8 i = 0;
    u32 total_len = 0;
    for (i = 0; i < p->iov_segs; i++) {
        total_len += p->iov[i].data_len;
    }
    return total_len;
}

u8 stack_iovs_to_skb_recv_queue(sbr_socket_t *sk, msg_pkt_arrived *p)
{
    u8 i;
    struct sk_buff *skb;
    struct sk_buff *fake_skb;
    u32 maa_size;
    int size, amt, delta;
    struct sock *lsk = sk->sk;
    struct sk_buff_head *sk_queue = &lsk->sk_receive_queue;
    ktime_t skb_time;
    msg_iov *iov = p->iov;
    u8 iov_segs = p->iov_segs;
    u8 iov_segs_in_list = 0;
    if (sk->status == SK_CLOSE) {
        sbr_global_stat_update(GLOBAL_RX_MSG_SK_CLOSED_ERR, p->iov_segs, get_iov_segs_total_len(p));
        msg_iovs_free(p->iov, p->iov_segs);
        return iov_segs_in_list;
    }
#if CONFIG_DPA_TC
    struct net_device *dev = dev_get_by_index(sock_net(sk->sk), p->ifidx);
#endif
    for (i = 0; i < iov_segs; i++) {
        void *virt = stack_mem_convert(iov[i].base_addr);
        if (virt == NULL) {
            NS_ERR("sk_id=%lu, fd=%d, frag list nstack_mem_convert failed", sk->sk_id, sk->fd);
            msg_iovs_free_with_unmap(iov, iov_segs, false, i);
            break;
        }
        fake_skb = stack_dra_unmap(iov[i].base_addr);
        if (fake_skb == NULL) {
            NS_ERR("sk_id=%lu, fd=%d, frag list stack_dra_unmap failed", sk->sk_id, sk->fd);
            msg_iovs_free_with_unmap(iov, iov_segs, false, i);
            break;
        }

        maa_size = get_maa_tot_size(virt, iov[i].data_len + iov[i].data_off);
        skb = sbr_build_skb(virt, maa_size, iov[i].head_frag);
        maa_cache_flush(iov[i].base_addr);
        if (skb == NULL) {
            NS_ERR("sk_id=%lu, fd=%d, frag list build_skb fail", sk->sk_id, sk->fd);
            sbr_global_stat_update(GLOBAL_RX_MSG_SKB_NULL_ERR, p->iov_segs, 0);
            sbr_conn_stat_update(sk->stats, SBR_RX_UDP_MSG_SKB_NULL_ERR, p->iov_segs, 0);
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
        skb->ip_summed = CHECKSUM_COMPLETE;
        skb->csum_valid = 1;
        skb->transport_header = skb->data + p->trans_hdr_offset - skb->head;
        skb->network_header = skb->data + p->net_hdr_offset - skb->head;
        skb->protocol = p->is_ipv6 ? htons(ETH_P_IPV6) : htons(ETH_P_IP);
        skb->destructor = sbr_destruct_skb;
#if CONFIG_DPA_TC
        unsigned long dev_scratch = skb->dev_scratch;
        skb->dev = dev;
        skb->sk = lsk;
        skb->mac_header = skb->network_header - ETHER_HLEN;
        s32 ret = tc_recv_skb(skb);
        skb->sk = NULL;
        skb->dev = NULL;
        skb->dev_scratch = dev_scratch;
        if (ret != 0) {
            NS_ERR("sk_id=%lu, fd=%d, tc_recv_skb bpf&netfilter fail]ret=%d", sk->sk_id, sk->fd, ret);
            sbr_global_stat_update(GLOBAL_RX_MSG_UDP_BPF_ERR, 1, (u32)skb->len);
            kfree_skb(skb);
            continue;
        }
#endif
        struct udp_dev_scratch *scratch = udp_skb_scratch(skb);
        scratch->_tsize_state = skb->truesize;
#if BITS_PER_LONG == 64
        scratch->len = (u16)skb->len;
        scratch->csum_unnecessary = !!skb_csum_unnecessary(skb);
        scratch->is_linear = !skb_is_nonlinear(skb);
#endif
        size = (int)skb->truesize;
        (void)atomic_add_return(size, &lsk->sk_rmem_alloc);
        spin_lock_bh(&sk_queue->lock);
        if (size >= lsk->sk_forward_alloc) {
            amt = sk_mem_pages(size);
            delta = amt << SK_MEM_QUANTUM_SHIFT;
            if (!__sk_mem_raise_allocated(lsk, delta, amt, SK_MEM_RECV)) {
                spin_unlock_bh(&sk_queue->lock);
                atomic_sub(skb->truesize, &lsk->sk_rmem_alloc);
                sbr_global_stat_update(GLOBAL_RX_MSG_SK_RMEM_ERR, 1, (u32)skb->len);
                kfree_skb(skb);
                msg_iovs_free_with_unmap(iov, iov_segs, false, i + 1);
                UDP_INC_STATS(sock_net(lsk), UDP_MIB_INERRORS, false);
                goto OUT;
            }
            lsk->sk_forward_alloc += delta;
        }
        lsk->sk_forward_alloc -= size;
#ifdef CONFIG_DPA_CHR
        u64 rcv_time_ns = (u64)(stack_get_stat_time() - p->arrived_timestamp) * SPL_NS_PER_TICK;
        skb->tstamp = ktime_get_real() - rcv_time_ns;
        bst_rx_check_http_cb(sk, skb);
#endif
        __skb_queue_tail(sk_queue, skb);
        iov_segs_in_list++;
        spin_unlock_bh(&sk_queue->lock);
    }
OUT:
    sbr_global_stat_update(GLOBAL_RX_MSG_SEGS_ERR, iov_segs - iov_segs_in_list, 0);
#if CONFIG_DPA_TC
    if (dev != NULL) {
        dev_put(dev);
    }
#endif
    NS_DBG("frag list skb %u", iov_segs);
    return iov_segs_in_list;
}

struct sk_buff *stack_iovs_build_skb(msg_iov *iov, u8 *iov_segs, const iov_desc_t *desc, bool is_unmap_all)
{
    u8 i = 0;
    u8 iov_num = *iov_segs;
    u32 maa_size;
    struct sk_buff *fake_skb;
    struct sk_buff *first_skb = NULL;
    struct sk_buff *cur_skb = NULL;
    u8 maa_seg_num = 0;
    void *virt = stack_mem_convert(iov[0].base_addr);
    if (virt == NULL) {
        NS_ERR("nstack_mem_convert failed");
        msg_iovs_free(iov, iov_num);
        goto OUT;
    }
    fake_skb = stack_dra_unmap(iov[0].base_addr);
    if (fake_skb == NULL) {
        NS_ERR("stack_dra_unmap failed");
        msg_iovs_free(iov, iov_num);
        goto OUT;
    }

    maa_size = get_maa_tot_size(virt, iov[0].data_len + iov[0].data_off);
    first_skb = sbr_build_skb(virt, maa_size, iov[0].head_frag);
    maa_cache_flush(iov[0].base_addr);
    if (first_skb == NULL) {
        NS_ERR("build_skb fail");
        msg_iovs_free_with_unmap(iov, iov_num, true, 1);
        goto OUT;
    }

    NS_DBG("i=0, data_off=%u, data_len=%u", iov[0].data_off, iov[0].data_len);
    __skb_set_length(first_skb, iov[0].data_len + iov[0].data_off);
    skb_reserve(first_skb, iov[0].data_off);
    first_skb->len -= iov[0].data_off;
    ktime_t cur_time = ktime_get_real();
    first_skb->tstamp = cur_time;
    first_skb->ip_summed = CHECKSUM_COMPLETE;
    first_skb->csum_valid = 1;
    struct skb_shared_info *shinfo = skb_shinfo(first_skb);
    cur_skb = first_skb;
    for (i = 1; i < iov_num; i++) {
        virt = stack_mem_convert(iov[i].base_addr);
        if (virt == NULL) {
            NS_ERR("nstack_mem_convert failed");
            msg_iovs_free_with_unmap(iov, iov_num, false, i);
            break;
        }
        NS_DBG("i=%d, data_off=%u, data_len=%u", i, iov[i].data_off, iov[i].data_len);
        if (shinfo->nr_frags == MAX_SKB_FRAGS) {
            fake_skb = stack_dra_unmap(iov[i].base_addr);
            if (fake_skb == NULL) {
                NS_ERR("stack_dra_unmap failed");
                msg_iovs_free_with_unmap(iov, iov_num, false, i);
                break;
            }

            maa_size = get_maa_tot_size(virt, iov[i].data_len + iov[i].data_off);
            struct sk_buff *new_skb = sbr_build_skb(virt, maa_size, iov[i].head_frag);
            if (new_skb == NULL) {
                NS_ERR("sbr_build_skb failed");
                stack_maa_free((u64)stack_mem_to_page(virt), MAA_FLAG_UNMAP);
                msg_iovs_free_with_unmap(iov, iov_num, false, i + 1);
                break;
            }
            if (!skb_has_frag_list(first_skb)) {
                skb_shinfo(first_skb)->frag_list = new_skb;
            } else {
                cur_skb->next = new_skb;
                first_skb->truesize += cur_skb->truesize;
                first_skb->len += cur_skb->len;
                first_skb->data_len += cur_skb->len;
            }
            cur_skb = new_skb;
            __skb_set_length(cur_skb, iov[i].data_len + iov[i].data_off);
            skb_reserve(cur_skb, iov[i].data_off);
            cur_skb->len -= iov[i].data_off;
            cur_skb->tstamp = cur_time;
            cur_skb->ip_summed = CHECKSUM_COMPLETE;
            cur_skb->csum_valid = 1;
            cur_skb->transport_header = cur_skb->data + desc->trans_hdr_offset - cur_skb->head;
            cur_skb->network_header = cur_skb->data + desc->net_hdr_offset - cur_skb->head;
            cur_skb->mac_header = cur_skb->network_header - ETHER_HLEN;
            cur_skb->protocol = desc->is_ipv6 ? htons(ETH_P_IPV6) : htons(ETH_P_IP);
            cur_skb->pkt_type = PACKET_HOST;
            maa_cache_flush(iov[i].base_addr);
            shinfo = skb_shinfo(cur_skb);
            continue;
        }
        u32 offset;
        struct page *page = stack_mem_to_page(virt);
        if (is_unmap_all) {
            fake_skb = stack_dra_unmap(iov[i].base_addr);
            if (fake_skb == NULL) {
                NS_ERR("stack_dra_unmap failed");
                msg_iovs_free_with_unmap(iov, iov_num, false, i);
                break;
            }
            u32 page_offset = stack_cal_page_offset(virt, page);
            offset = page_offset + iov[i].data_off;
        } else {
            offset = (u8 *)virt + iov[i].data_off - (u8 *)page_address(page);
            maa_seg_num++;
        }
        maa_cache_flush(iov[i].base_addr);
        skb_add_rx_frag(cur_skb, (s32)shinfo->nr_frags, page, (s32)offset,
            (s32)iov[i].data_len, iov[i].data_len + iov[i].data_off);
    }
    global_rx_dra_add(maa_seg_num);
    if (first_skb != cur_skb) {
        first_skb->truesize += cur_skb->truesize;
        first_skb->len += cur_skb->len;
        first_skb->data_len += cur_skb->len;
    }
    first_skb->transport_header = first_skb->data + desc->trans_hdr_offset - first_skb->head;
    first_skb->network_header = first_skb->data + desc->net_hdr_offset - first_skb->head;
    first_skb->mac_header = first_skb->network_header - ETHER_HLEN;
    first_skb->protocol = desc->is_ipv6 ? htons(ETH_P_IPV6) : htons(ETH_P_IP);
    first_skb->pkt_type = PACKET_HOST;
OUT:
    *iov_segs = i;
    return first_skb;
}

dmm_atomic_t *get_global_dra_alloc_num(void)
{
    return &g_tx_dra_alloc_num;
}

void global_dra_alloc_num_init(void)
{
    dmm_atomic_set(&g_tx_dra_alloc_num, 0);
}

void global_rx_dra_num_init(void)
{
    dmm_atomic_set(&g_rx_dra_alloc_num, 0);
}

s32 get_global_rx_dra_alloc_num(void)
{
    return dmm_atomic_read(&g_rx_dra_alloc_num);
}

void global_rx_dra_add(s32 num)
{
    dmm_atomic_add(&g_rx_dra_alloc_num, num);
}

void global_rx_dra_num_sub(s32 num)
{
    dmm_atomic_sub(&g_rx_dra_alloc_num, num);
}

// retval true: snd buf limit and migrate sk
bool is_global_dra_alloc_available(u32 req_num)
{
    u32 old_val, new_val;
    do {
        old_val = dmm_atomic_read(get_global_dra_alloc_num());
        if (old_val + req_num > TX_DRA_CACHE_LIMIT) {
            return false;
        } else {
            new_val = old_val + req_num;
        }
    } while (!dmm_atomic_swap(get_global_dra_alloc_num(), old_val, new_val));
    return true;
}

void sk_dra_alloc_sub(sbr_socket_t *sk, u32 pkt_diff)
{
    dmm_atomic_sub(get_global_dra_alloc_num(), pkt_diff);
    sk->dra_alloc_num -= pkt_diff;
}

void sk_dra_alloc_remove(sbr_socket_t *sk)
{
    dmm_atomic_sub(get_global_dra_alloc_num(), sk->dra_alloc_num);
}

#if COST_TIME_STAT
void sbr_register_time_stat_cb(hds_pkt_fn_t cb)
{
    g_sbr_time_stat_cb = cb;
}

int sbr_get_cost_time_stat(void* p, cost_time_stats *stat, int link_type)
{
    if (g_sbr_time_stat_cb == NULL) {
        return -1;
    }
    return g_sbr_time_stat_cb(p, stat, link_type);
}

bool sbr_cost_time_stat_is_enabled(void)
{
    return g_sbr_time_stat_cb != NULL;
}
#endif
