/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#include <net/ipv6.h>
#include <net/tcp.h>
#include "socket/sbr_prot_com.h"
#include "msg/bridge_msg_producer.h"
#include "cooperation/cooperation.h"
#include "common_msg.h"
#include "securec.h"
#include "ip_addr.h"
#include "socket/sbr_socket.h"
#include "sbr_res_mgr.h"
#include "sbr_tcp.h"
#include "stack_time.h"
#include "tc_interface.h"
#include "dfx/chr_stats.h"
#include "dfx/global_res_stats.h"
#include "dfx/conn_stats.h"
#include "dfx/dfx_display.h"

enum {
    TCP_CMSG_TS = 1,
};

NSTACK_STATIC s32 sbr_tcp_migrate_a2d(sbr_socket_t *sk)
{
    s32 ret = coop_tcp_migrate_a2d(sk->sk);
    if (ret == -EOPNOTSUPP) {
        sbr_migrate_a2d_not_support_inc();
    }
    if (ret != 0 && ret != -EOPNOTSUPP) {
        sbr_migrate_a2d_failed_inc();
    }

    return ret;
}

NSTACK_STATIC s32 sbr_tcp_migrate_d2a(sbr_socket_t *sk)
{
    sbr_migrate_d2a_request_inc();
    s32 ret = coop_tcp_migrate_d2a(sk->sk);
    if (ret != 0) {
        sbr_migrate_d2a_failed_inc();
    } else {
        sbr_migrate_d2a_success_inc();
    }

    return ret;
}

static s32 sbr_sockopt_tcp_common_optname(s32 optname, int val)
{
    s32 err = 0;

    switch (optname) {
        case TCP_NODELAY:
        case TCP_CORK:
        case TCP_LINGER2:
        case TCP_MAXSEG:
#if SPL_TCP_DEFER_ACCEPT
        case TCP_DEFER_ACCEPT:
#endif
            break;
        case TCP_KEEPIDLE:
            if (val < 1 || val > MAX_TCP_KEEPIDLE)
                err = EINVAL;
            break;
        case TCP_KEEPINTVL:
            if (val < 1 || val > MAX_TCP_KEEPINTVL)
                err = EINVAL;
            break;
        case TCP_KEEPCNT:
            if (val < 1 || val > MAX_TCP_KEEPCNT)
                err = EINVAL;
            break;
        case TCP_QUICKACK:
        case TCP_THIN_LINEAR_TIMEOUTS:
            break;
        default:
            err = ENOPROTOOPT;
            break;
    }
    return err;
}

static s32 sbr_setsockopt_ipproto_tcp(s32 optname, const void *optval, socklen_t optlen)
{
    int val = *(const s32 *)optval;
    if (optname == TCP_CONGESTION) {
        if (optlen == 0) {
            return EINVAL;
        }
        return 0;
    }

    if (optlen < sizeof(s32)) {
        return EINVAL;
    }

    return sbr_sockopt_tcp_common_optname(optname, val);
}

NSTACK_STATIC void sbr_tcp_setsockopt_sync(sbr_socket_t *sk, s32 level, s32 optname, const void *optval)
{
    struct sock *lsk = sk->sk;

    int val = *(const s32 *)optval;
    if (level == SOL_SOCKET && optname == SO_KEEPALIVE) {
        sock_valbool_flag(lsk, SOCK_KEEPOPEN, (val == 0) ? false : true);
    } else if (level == SOL_TCP) {
        struct tcp_sock *tp = tcp_sk(lsk);

        if (optname == TCP_KEEPIDLE) {
            tp->keepalive_time = val * HZ;
        } else if (optname == TCP_KEEPINTVL) {
            tp->keepalive_intvl = val * HZ;
        } else if (optname == TCP_KEEPCNT) {
            tp->keepalive_probes = val;
        } else if (optname == TCP_QUICKACK) {
            if (!val) {
                inet_csk_enter_pingpong_mode(lsk);
            } else {
                inet_csk_exit_pingpong_mode(lsk);
            }
        }
    }
}

NSTACK_STATIC s32 sbr_tcp_setsockopt(sbr_socket_t *sk, s32 level, s32 optname, const void *optval, socklen_t optlen)
{
    s32 err;
    switch (level) {
        case SOL_SOCKET:
            err = sbr_setsockopt_sol_socket(sk, optname, optval, optlen);
            break;
        case IPPROTO_IP:
            err = sbr_setsockopt_ipproto_ip(optname, optlen, CONN_TYPE_TCP);
            break;
#if SPL_IPV6
        case IPPROTO_IPV6:
            err = sbr_setsockopt_ipproto_ipv6(optname, optval, optlen, CONN_TYPE_TCP);
            break;
#endif
        case IPPROTO_TCP:
            err = sbr_setsockopt_ipproto_tcp(optname, optval, optlen);
            break;
        default:
            err = ENOPROTOOPT;
            break;
    }

    if (err != 0) {
        NS_WAR("fail]tcp fd=%d,level=%d,optname=%d,err=%d", sk->fd, level, optname, err);
        return -err;
    }
    sbr_tcp_setsockopt_sync(sk, level, optname, optval);
    err = sbr_handle_setsockopt(sk, level, optname, optval, optlen);
    return err;
}

static void sbr_tcp_update_recv_tstamps(struct sk_buff *skb, struct scm_timestamping_internal *tss)
{
    if (skb->tstamp)
        tss->ts[0] = ktime_to_timespec64(skb->tstamp);
    else
        tss->ts[0] = (struct timespec64) {0};

    if (skb_hwtstamps(skb)->hwtstamp)
        tss->ts[2] = ktime_to_timespec64(skb_hwtstamps(skb)->hwtstamp);
    else
        tss->ts[2] = (struct timespec64) {0};
}

/* Similar to __sock_recv_timestamp, but does not require an skb */
static void sbr_tcp_recv_timestamp(struct msghdr *msg, const struct sock *sk, struct scm_timestamping_internal *tss)
{
    int new_tstamp = sock_flag(sk, SOCK_TSTAMP_NEW);
    bool has_timestamping = false;

    if (tss->ts[0].tv_sec || tss->ts[0].tv_nsec) {
        if (sock_flag(sk, SOCK_RCVTSTAMP)) {
            if (sock_flag(sk, SOCK_RCVTSTAMPNS)) {
                if (new_tstamp) {
                    struct __kernel_timespec kts = {
                        .tv_sec = tss->ts[0].tv_sec,
                        .tv_nsec = tss->ts[0].tv_nsec,
                    };
                    put_cmsg(msg, SOL_SOCKET, SO_TIMESTAMPNS_NEW,
                            sizeof(kts), &kts);
                } else {
                    struct __kernel_old_timespec ts_old = {
                        .tv_sec = tss->ts[0].tv_sec,
                        .tv_nsec = tss->ts[0].tv_nsec,
                    };
                    put_cmsg(msg, SOL_SOCKET, SO_TIMESTAMPNS_OLD,
                            sizeof(ts_old), &ts_old);
                }
            } else {
                if (new_tstamp) {
                    struct __kernel_sock_timeval stv = {
                        .tv_sec = tss->ts[0].tv_sec,
                        .tv_usec = tss->ts[0].tv_nsec / 1000,
                    };
                    put_cmsg(msg, SOL_SOCKET, SO_TIMESTAMP_NEW,
                            sizeof(stv), &stv);
                } else {
                    struct __kernel_old_timeval tv = {
                        .tv_sec = tss->ts[0].tv_sec,
                        .tv_usec = tss->ts[0].tv_nsec / 1000,
                    };
                    put_cmsg(msg, SOL_SOCKET, SO_TIMESTAMP_OLD,
                            sizeof(tv), &tv);
                }
            }
        }

        if (sk->sk_tsflags & SOF_TIMESTAMPING_SOFTWARE)
            has_timestamping = true;
        else
            tss->ts[0] = (struct timespec64) {0};
    }

    if (tss->ts[2].tv_sec || tss->ts[2].tv_nsec) {
        if (sk->sk_tsflags & SOF_TIMESTAMPING_RAW_HARDWARE)
            has_timestamping = true;
        else
            tss->ts[2] = (struct timespec64) {0};
    }

    if (has_timestamping) {
        tss->ts[1] = (struct timespec64) {0};
        if (sock_flag(sk, SOCK_TSTAMP_NEW))
            put_cmsg_scm_timestamping64(msg, tss);
        else
            put_cmsg_scm_timestamping(msg, tss);
    }
}

static bool sbr_tcp_flags_fallback(sbr_socket_t *sk, int flags)
{
    if (flags & (MSG_OOB | MSG_ZEROCOPY)) {
        sk->d2a_event = D2A_EVT_TCP_FLAG_UNSUPP;
        sk->fdopt->migrate_d2a(sk);
        long timeo = MAX_SCHEDULE_TIMEOUT;
        int err = sbr_wait_migrate(sk, &timeo);
        if (err) {
            NS_WAR("sk %d sbr_wait_migrate err %d", sk->fd, err);
        }
        return true;
    }

    return false;
}

static s32 sbr_tcp_recvmsg(sbr_socket_t *ssk, struct msghdr *msg, size_t len, int flags)
{
    sbr_global_stat_cnt_inc(GLOBAL_RX_SBR_TCP_IN);
    struct sock *sk = ssk->sk;
    struct tcp_sock *tp = tcp_sk(sk);
    int copied = 0;
    u32 peek_seq;
    u32 *seq;
    u16 free_pcount = 0;
    unsigned long used;
    int err;
    int target;     /* Read at least this many bytes */
    long timeo;
    struct sk_buff *skb, *last;
    struct scm_timestamping_internal tss;
    int cmsg_flag = 0;

    if (unlikely(flags & MSG_ERRQUEUE)) {
        sbr_global_stat_cnt_inc(GLOBAL_RX_SBR_TCP_ERRQUEUE_ERR);
        sbr_conn_stat_cnt_inc(ssk->stats, SBR_RX_APP_TCP_ERRQUEUE_ERR);
        return -EAGAIN;
    }
    lock_sock(sk);
    timeo = MAX_SCHEDULE_TIMEOUT;
    err = sbr_wait_migrate(ssk, &timeo);
    if (err) {
        NS_WAR("sk %d status %u not ready", ssk->fd, ssk->status);
    }

    if (ssk->status != SK_MIGRATE_OK || sbr_tcp_flags_fallback(ssk, flags)) {
        goto fallback;
    }

    seq = &tp->copied_seq;
    if (flags & MSG_PEEK) {
        peek_seq = tp->copied_seq;
        seq = &peek_seq;
    }

    timeo = sock_rcvtimeo(sk, (int)(flags & MSG_DONTWAIT));
    target = sock_rcvlowat(sk, (int)(flags & MSG_WAITALL), (int)len);

    do {
        u32 offset;

        /* Next get a buffer. */
        last = skb_peek_tail(&sk->sk_receive_queue);
        skb_queue_walk(&sk->sk_receive_queue, skb) {
            last = skb;

            /* Now that we have two receive queues this
             * shouldn't happen.
             */
            if (before(*seq, TCP_SKB_CB(skb)->seq)) {
                 NS_ERR("sk_id=%lu, fd=%d, TCP recvmsg seq # bug: copied %X, seq %X, rcvnxt %X, fl %X",
                    ssk->sk_id, ssk->fd, *seq, TCP_SKB_CB(skb)->seq, tp->rcv_nxt, flags);
                break;
            }

            offset = *seq - TCP_SKB_CB(skb)->seq;
            if (offset < skb->len)
                goto found_ok_skb;
            if (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN)
                goto found_fin_ok;
            if (!(flags & MSG_PEEK))
                NS_ERR("sk_id=%lu, fd=%d, TCP recvmsg seq # bug 2: copied %X, seq %X, rcvnxt %X, fl %X",
                    ssk->sk_id, ssk->fd, *seq, TCP_SKB_CB(skb)->seq, tp->rcv_nxt, flags);
        }

        /* Well, if we have backlog, try to process it now yet. */
        if (copied >= target)
            break;

        if (copied) {
            if (sk->sk_err ||
                sk->sk_state == TCP_CLOSE ||
                (sk->sk_shutdown & RCV_SHUTDOWN) ||
                !timeo ||
                signal_pending(current))
                break;
        } else {
            if (sock_flag(sk, SOCK_DONE))
                break;

            if (sk->sk_err) {
                copied = sock_error(sk);
                break;
            }

            if (sk->sk_shutdown & RCV_SHUTDOWN)
                break;

            if (sk->sk_state == TCP_CLOSE) {
                copied = -ENOTCONN;
                break;
            }

            if (!timeo) {
                copied = -EAGAIN;
                break;
            }

            if (signal_pending(current)) {
                copied = sock_intr_errno(timeo);
                break;
            }
        }

        (void)sbr_handle_tcp_recved(ssk, free_pcount);
        free_pcount = 0;
        sk_wait_data(sk, &timeo, last);
        if (ssk->status == SK_CLOSE) {
            goto fallback;
        } else if (ssk->status == SK_MIGRATE_A2D || ssk->status == SK_MIGRATE_D2A) {
            err = sbr_wait_migrate(ssk, &timeo);
            if (ssk->status == SK_CLOSE) {
fallback:
                if (copied) {
                    break;
                }
                int addr_len = 0;
                release_sock(sk);
                err = ssk->save_prot->recvmsg(sk, msg, len, flags & MSG_DONTWAIT, flags & ~MSG_DONTWAIT,  &addr_len);
                if (err >= 0) {
                    msg->msg_namelen = addr_len;
                }
                NS_DBG("sk %d status %u fallback ret %d", ssk->fd, ssk->status, err);
                sbr_global_stat_cnt_inc(GLOBAL_RX_SBR_TCP_FALLBACK_ERR);
                sbr_conn_stat_cnt_inc(ssk->stats, SBR_RX_APP_TCP_FALLBACK_ERR);
                return err;
            }
            if (err != 0 || ssk->status != SK_MIGRATE_OK) {
                NS_DBG("sk %d status %u copied %u", ssk->fd, ssk->status, copied);
                copied = copied ? : err;
                break;
            }
        } else if (ssk->status != SK_MIGRATE_OK) {
            copied = -EPIPE;
            break;
        }
        continue;

found_ok_skb:
        /* Ok so how much can we use? */
        used = skb->len - offset;
        if (len < used)
            used = len;

        if (!(flags & MSG_TRUNC)) {
            err = skb_copy_datagram_msg(skb, (s32)offset, msg, (int)used);
            if (err) {
                /* Exception. Bailout! */
                if (!copied)
                    copied = -EFAULT;
                break;
            }
        }

        WRITE_ONCE(*seq, (u32)(*seq + used));
        sbr_global_stat_bytes_add(GLOBAL_RX_SBR_UDP_OUT, (u32)used);
        sbr_conn_stat_bytes_add(ssk->stats, SBR_RX_APP_OUT, (u32)used);
        copied += (int)used;
        len -= used;
        if (skb->tstamp || skb_hwtstamps(skb)->hwtstamp) {
            sbr_tcp_update_recv_tstamps(skb, &tss);
            cmsg_flag |= TCP_CMSG_TS;
        }

        if (used + offset < skb->len)
            continue;

        if (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN)
            goto found_fin_ok;
        if (!(flags & MSG_PEEK)) {
            __skb_unlink(skb, &sk->sk_receive_queue);
            free_pcount += TCP_SKB_CB(skb)->tcp_gso_segs;
            __kfree_skb(skb);
        }
        continue;
found_fin_ok:
        /* Process the FIN. */
        WRITE_ONCE(*seq, *seq + 1);
        if (!(flags & MSG_PEEK)) {
            __skb_unlink(skb, &sk->sk_receive_queue);
            free_pcount += TCP_SKB_CB(skb)->tcp_gso_segs;
            __kfree_skb(skb);
        }
    } while (len > 0);

    sbr_global_stat_cnt_inc(GLOBAL_RX_SBR_TCP_OUT);
    sbr_conn_stat_cnt_inc(ssk->stats, SBR_RX_APP_OUT);

    (void)sbr_handle_tcp_recved(ssk, free_pcount);
    release_sock(sk);
    if (cmsg_flag && copied >= 0) {
        if (cmsg_flag & TCP_CMSG_TS) {
            sbr_tcp_recv_timestamp(msg, sk, &tss);
        }
    }
    return copied;
}

static struct sk_buff *sbr_tcp_walloc_skb(sbr_socket_t *sk, int size, gfp_t gfp)
{
    struct sk_buff *skb;
    struct sock *lsk = sk->sk;
    int tcp_header_len = TCP_HLEN + (tcp_sk(lsk)->rx_opt.tstamp_ok ? TCPOLEN_TSTAMP_ALIGNED : 0);
    int ip_header_len = (sbr_sk_isv6(sk) && !sk->is_mapped_v6) ? IP6_HLEN : IP_HLEN;
    int max_header = ETHER_HLEN + ip_header_len + tcp_header_len;
    int tot_size;

    if (!sk_stream_memory_free(lsk))
        return NULL;

    tot_size = ALIGN(size + max_header, 4);
    /* alloc memory for shared_info implicitly */
    u64 data = stack_maa_alloc((size_t)tot_size);
    if (data == 0) {
        NS_WAR("stack_maa_alloc failed, fd=%d", sk->fd);
        return NULL;
    }
    void *convert_addr = stack_mem_convert(data);
    if (convert_addr == NULL) {
        NS_WAR("stack_mem_convert failed, fd=%d", sk->fd);
        stack_maa_free(data, MAA_FLAG_PAGE);
        return NULL;
    }
    skb = sbr_build_skb(convert_addr, (unsigned int)(tot_size + SKB_DATA_ALIGN(sizeof(struct skb_shared_info))), 1);
    if (likely(skb)) {
        struct sbr_tcp_skb_cb *tcb = SBR_TCP_SKB_CB(skb);
        tcb->maa_addr = data;
        skb->destructor = sbr_destruct_tx_skb;
        skb->sk = lsk;

        skb_reserve(skb, max_header);
        /*
         * Make sure that we have exactly size bytes
         * available to the caller, no more, no less.
         */
        skb->reserved_tailroom = skb->end - skb->tail - size;
        maa_cache_flush(data);
        (void)memset_s(convert_addr, tot_size, 0, max_header);
        return skb;
    }
    stack_maa_free(data, MAA_FLAG_PAGE);
    NS_ERR("sk_id=%lu, fd=%d, sbr_alloc_skb failed", sk->sk_id, sk->fd);
    return NULL;
}

NSTACK_STATIC int sbr_stream_wait_memory(struct sock *sk, long *timeo_p)
{
    int err = 0;
    long vm_wait = 0;
    long current_timeo = *timeo_p;
    DEFINE_WAIT_FUNC(wait, woken_wake_function);
    sbr_socket_t *ssk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;

    if (sk_stream_memory_free(sk))
        current_timeo = vm_wait = (prandom_u32() % (HZ / 5)) + 2;

    add_wait_queue(sk_sleep(sk), &wait);

    while (1) {
        sk_set_bit(SOCKWQ_ASYNC_NOSPACE, sk);

        if (sk->sk_err || (sk->sk_shutdown & SEND_SHUTDOWN)) {
            err = -EPIPE;
            goto out;
        }
        if (!*timeo_p) {
            /* Make sure that whenever EAGAIN is returned, EPOLLOUT event can
             * be generated later.
             * When TCP receives ACK packets that make room, tcp_check_space()
             * only calls tcp_new_space() if SOCK_NOSPACE is set.
             */
            set_bit(SOCK_NOSPACE, &sk->sk_socket->flags);
            err = -EAGAIN;
            goto out;
        }
        if (signal_pending(current)) {
            err = sock_intr_errno(*timeo_p);
            goto out;
        }
        sk_clear_bit(SOCKWQ_ASYNC_NOSPACE, sk);
        if ((sk_stream_memory_free(sk) || (ssk->status != SK_MIGRATE_OK)) && !vm_wait)
            break;

        set_bit(SOCK_NOSPACE, &sk->sk_socket->flags);
        sk->sk_write_pending++;
        sk_wait_event(sk, &current_timeo, sk->sk_err ||
                          (sk->sk_shutdown & SEND_SHUTDOWN) ||
                          ((sk_stream_memory_free(sk) || (ssk->status == SK_CLOSE)) && !vm_wait),
                          &wait);
        sk->sk_write_pending--;

        if (vm_wait) {
            vm_wait -= current_timeo;
            current_timeo = *timeo_p;
            if (current_timeo != MAX_SCHEDULE_TIMEOUT &&
                (current_timeo -= vm_wait) < 0)
                current_timeo = 0;
            vm_wait = 0;
        }
        *timeo_p = current_timeo;
    }
out:
    remove_wait_queue(sk_sleep(sk), &wait);
    return err;
}

// copied > 0 direct return err, or wait migrate
NSTACK_STATIC s32 tcp_migrate_for_dra_limit(sbr_socket_t *sk, s32 copied)
{
    s32 err = sk->fdopt->migrate_d2a(sk);
    if (err == 0) {
        long timeo = MAX_SCHEDULE_TIMEOUT;
        if (!copied) {
            err = sbr_wait_migrate(sk, &timeo);
        }
        if (err) {
            NS_WAR("sk_id=%lu, fd=%d, sbr_wait_migrate err=%d", sk->sk_id, sk->fd, err);
        }
    } else {
        NS_ERR("sk_id=%lu, fd=%d, migrate_d2a fail ret=%d", sk->sk_id, sk->fd, err);
    }
    return err;
}

NSTACK_STATIC s32 sbr_tcp_sendmsg(sbr_socket_t *sk, struct msghdr *msg, size_t size)
{
    sbr_global_stat_update(GLOBAL_TX_SBR_TCP_IN, 0, (u32)size);
    sbr_conn_stat_update(sk->stats, SBR_TX_APP_IN, 0, (u32)size);
    struct sock *lsk = sk->sk;
    struct sk_buff *skb;
    struct tcphdr *tcph;
    struct iphdr *iph;
    struct ipv6hdr *ipv6h;
    int flags, err, copied = 0;
    long timeo;
    u32 mss;
    u64 maa;
    flags = (int)msg->msg_flags;

    timeo = MAX_SCHEDULE_TIMEOUT;
    err = sbr_wait_migrate(sk, &timeo);
    if (err) {
        NS_WAR("sk_id=%lu, fd=%d, status %u not ready", sk->sk_id, sk->fd, sk->status);
        sbr_global_stat_update(GLOBAL_TX_SBR_TCP_NOT_READY_ERR, 0, (u32)size);
        sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 0, (u32)size);
        return err;
    }

    if (sk->status == SK_CLOSE || sbr_tcp_flags_fallback(sk, flags)) {
        sbr_global_stat_update(GLOBAL_TX_SBR_TCP_SK_STATUS_ERR, 0, (u32)size);
        goto fallback;
    }

    /* This should be in poll */
    sk_clear_bit(SOCKWQ_ASYNC_NOSPACE, lsk);
    mss = tcp_sk(lsk)->mss_cache;

    err = -EPIPE;
    if (lsk->sk_err || (lsk->sk_shutdown & SEND_SHUTDOWN)) {
        sbr_global_stat_update(GLOBAL_TX_SBR_TCP_LSK_ERR, 0, (u32)size);
        goto do_ret;
    }
    if ((lsk->sk_state != TCP_ESTABLISHED) && (lsk->sk_state != TCP_CLOSE_WAIT)) {
        sbr_global_stat_update(GLOBAL_TX_SBR_TCP_LSK_ERR, 0, (u32)size);
        goto do_ret;
    }

    timeo = sock_sndtimeo(lsk, flags & MSG_DONTWAIT);
    while (msg_data_left(msg)) {
        int copy = 0;

        skb = skb_peek_tail(&lsk->sk_write_queue);
        if (skb)
            copy = (int)(mss - skb->len);

        if (copy <= 0) {
            if (is_global_dra_alloc_available(1) == false) {
                NS_WAR("sk_id=%lu, fd=%d, migrate for tx dra alloc limit", sk->sk_id, sk->fd);
                sk->d2a_event = D2A_EVT_TX_DRA_LIMIT;
                err = tcp_migrate_for_dra_limit(sk, copied);
                if (err == 0 && copied == 0) {
                    goto fallback;
                }
                goto do_ret;
            }
            skb = sbr_tcp_walloc_skb(sk, (int)mss, lsk->sk_allocation);
            if (!skb) {
                dmm_atomic_dec(get_global_dra_alloc_num());
                set_bit(SOCK_NOSPACE, &lsk->sk_socket->flags);
                if (copied) {
                    (void)sbr_handle_tcp_send(sk, false);
                }
                err = sbr_stream_wait_memory(lsk, &timeo);
                if (unlikely(err)) {
                    sbr_global_stat_update(GLOBAL_TX_SBR_TCP_NO_MEM_ERR, 0, (u32)(size - copied));
                    goto do_ret;
                }

                if (unlikely(sk->status == SK_MIGRATE_D2A)) {
                    long time_max = MAX_SCHEDULE_TIMEOUT;
                    (void)sbr_wait_migrate(sk, &time_max);
                }

                if (unlikely(sk->status == SK_CLOSE)) {
                    sbr_global_stat_update(GLOBAL_TX_SBR_TCP_SK_STATUS_ERR, 0, (u32)(size - copied));
                    if (copied) {
                        goto do_ret;
                    }
fallback:
                    release_sock(sk->sk);
                    err = sk->save_prot->sendmsg(sk->sk, msg, size);
                    lock_sock(sk->sk);
                    NS_WAR("sk %d status %u fallback ret %d", sk->fd, sk->status, err);
                    sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 0, (u32)size);
                    return err;
                } else if (unlikely(sk->status != SK_MIGRATE_OK)) {
                    sbr_global_stat_update(GLOBAL_TX_SBR_TCP_SK_STATUS_ERR, 0, (u32)(size - copied));
                    NS_WAR("sk %d status %u copied %u", sk->fd, sk->status, copied);
                    goto do_ret;
                }
                continue;
            }

            skb->ip_summed = CHECKSUM_UNNECESSARY;
            __skb_queue_tail(&lsk->sk_write_queue, skb);
            sk_wmem_queued_add(lsk, (int)skb->truesize);
            sbr_global_stat_pkts_add(GLOBAL_TX_SBR_TCP_OUT, 1);
            sbr_conn_stat_pkts_add(sk->stats, SBR_TX_APP_OUT, 1);
            copy = (int)mss;
            sk->dra_alloc_num++;
        }

        /* Try to append data to the end of skb. */
        if (copy > msg_data_left(msg))
            copy = (int)msg_data_left(msg);

        /* We have some space in skb head. Superb! */
        copy = min_t(int, copy, skb_availroom(skb));
        err = skb_add_data_nocache(lsk, skb, &msg->msg_iter, copy);
        if (err) {
            __skb_unlink(skb, &lsk->sk_write_queue);
            sbr_global_stat_pkts_dec(GLOBAL_TX_SBR_TCP_OUT);
            sbr_global_stat_update(GLOBAL_TX_SBR_TCP_COPY_ERR, 0, (u32)(size - copied));
            sbr_conn_stat_pkts_dec(sk->stats, SBR_TX_APP_OUT);
            dmm_atomic_dec(get_global_dra_alloc_num());
            sk->dra_alloc_num--;
            sk_wmem_queued_add(lsk, (int)(-skb->truesize));
            __kfree_skb(skb);
            if (copied) {
                goto out;
            }
            goto do_ret;
        }

#if COST_TIME_STAT
        if (sbr_cost_time_stat_is_enabled()) {
            skb->tstamp = stack_get_stat_time();
        } else {
            skb->tstamp = 0;
        }
#endif

        bst_tx_check_http_cb(sk, skb);
        sbr_global_stat_bytes_add(GLOBAL_TX_SBR_TCP_OUT, (u32)copy);
        sbr_conn_stat_bytes_add(sk->stats, SBR_TX_APP_OUT, (u32)copy);
        copied += copy;
        struct tcp_sock *tp = tcp_sk(lsk);
        tp->write_seq += (u32)copy;
        SBR_TCP_SKB_CB(skb)->copied_len = (u32)copy;
#if CONFIG_DPA_TC
        struct dst_entry *dst;
        skb->pkt_type = PACKET_OUTGOING;
        skb->protocol = (sbr_sk_isv6(sk) && !sk->is_mapped_v6) ? htons(ETH_P_IPV6) : htons(ETH_P_IP);
        skb->transport_header = skb->data - sizeof(struct tcphdr) - skb->head;
        if (skb->protocol == htons(ETH_P_IP)) {
            dst = sk_dst_check(lsk, 0);
            skb->network_header = skb_transport_header(skb)  - sizeof(struct iphdr) - skb->head;
            iph = (struct iphdr *)skb_network_header(skb);
            iph->saddr = lsk->sk_rcv_saddr;
            iph->daddr = lsk->sk_daddr;
            iph->protocol = SPL_IPPROTO_TCP;
        } else {
            dst = sk_dst_check(lsk, inet6_sk(lsk)->dst_cookie);
            skb->network_header = skb_transport_header(skb) - sizeof(struct ipv6hdr) - skb->head;
            ipv6h = (struct ipv6hdr *)skb_network_header(skb);
            ipv6h->saddr = lsk->sk_v6_rcv_saddr;
            ipv6h->daddr = lsk->sk_v6_daddr;
            ipv6h->nexthdr = SPL_IPPROTO_TCP;
        }
        if (dst) {
            skb->dev = dst->dev;
        }
        skb_dst_set(skb, dst);
        skb->mac_header = skb_network_header(skb) - ETH_HLEN - skb->head;
        tcph = (struct tcphdr *)skb_transport_header(skb);
        tcph->source = htons(lsk->sk_num);
        tcph->dest = lsk->sk_dport;
        s32 bpf_ret = tc_tcp_send_skb(skb);
        skb->_skb_refdst = 0UL;
        skb->dev = NULL;
        dst_release(dst);
        if (bpf_ret != 0) {
            NS_WAR("tc_tcp_send_skb bpf&netfilter fail]fd=%d", sk->fd);
            sk->d2a_event = D2A_EVT_TCP_TX_TC_FAIL;
            sbr_tcp_migrate_d2a(sk);
            return copied;
        }
#endif
        maa = SBR_TCP_SKB_CB(skb)->maa_addr;
        maa_cache_map(maa);
        if (!msg_data_left(msg)) {
            if (((u32)flags & MSG_MORE) == 0) {
                SBR_TCP_SKB_CB(skb)->tcp_push = 1;
            }
            goto out;
        }
        if (skb_queue_len(&lsk->sk_write_queue) == MAX_FRAGS) {
            (void)sbr_handle_tcp_send(sk, false);
        }
    }

out:
    if (copied) {
        sbr_global_stat_cnt_inc(GLOBAL_TX_SBR_TCP_OUT);
        sbr_conn_stat_cnt_inc(sk->stats, SBR_TX_APP_OUT);
        (void)sbr_handle_tcp_send(sk, false);
    }
    return copied;
do_ret:
    if (copied) {
        sbr_global_stat_cnt_inc(GLOBAL_TX_SBR_TCP_OUT);
        sbr_conn_stat_cnt_inc(sk->stats, SBR_TX_APP_OUT);
        return copied;
    }
    sbr_conn_stat_update(sk->stats, SBR_TX_APP_ERR, 0, (u32)(size - copied));
    return err;
}

NSTACK_STATIC s32 sbr_tcp_close(sbr_socket_t *sk, bool need_rst)
{
    int ret = sbr_handle_close(sk, need_rst);
    return ret;
}

static sbr_fdopt g_tcp_fdopt = {
    .migrate_a2d = sbr_tcp_migrate_a2d,
    .migrate_d2a = sbr_tcp_migrate_d2a,
    .getsockopt = NULL,
    .setsockopt = sbr_tcp_setsockopt,
    .recvmsg = sbr_tcp_recvmsg,
    .sendmsg = sbr_tcp_sendmsg,
    .close = sbr_tcp_close,
};

sbr_fdopt *sbr_get_tcp_fdopt(void)
{
    return &g_tcp_fdopt;
}

