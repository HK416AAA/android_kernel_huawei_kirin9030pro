/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include <net/protocol.h>
#include <net/inet_common.h>
#include <net/ipv6.h>
#include <net/tcp.h>
#include <net/udp.h>
#include "sockets.h"
#include "stack_types.h"
#include "stack_mem.h"
#include "runtime.h"
#include "common_msg.h"
#include "socket/sbr_socket.h"
#include "socket/sbr_prot_com.h"
#include "cooperation/cooperation.h"
#include "dfx/chr_stats.h"
#include "dfx/global_res_stats.h"
#include "dfx/conn_stats.h"
#include "socket/dpa_inet_socket.h"

#ifdef CONFIG_DPA_PROTO
#include <platform_include/basicplatform/linux/hck/net/hck_dpa.h>
#endif
#include "socket/dpa_inet_socket.h"

#define DPA_OPT_UNSUPPORT ((u32)-1)

static struct proto_ops dpa_inet_stream_ops;
static struct proto_ops dpa_inet_dgram_pre_ops;
static struct proto_ops dpa_inet_dgram_ops;
static struct proto dpa_inet_tcp_prot;
static struct proto dpa_inet_udp_prot;

static struct proto_ops dpa_inet6_stream_ops;
static struct proto_ops dpa_inet6_dgram_pre_ops;
static struct proto_ops dpa_inet6_dgram_ops;
static struct proto dpa_inet6_tcp_prot;
static struct proto dpa_inet6_udp_prot;

static int dpa_udp_prot_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;

    lock_sock(sk);
    NS_INF("sk_id=%lu, fd=%d reconnect", sbr_sk->sk_id, sbr_get_fd(sk));
    (void)sbr_close(sk);
    if (sbr_sk->save_ops != NULL) {
        WRITE_ONCE(sk->sk_socket->ops, sbr_sk->save_ops);
        sbr_sk->save_ops = NULL;
    }
    if (sbr_sk->save_prot != NULL) {
        WRITE_ONCE(sk->sk_prot, sbr_sk->save_prot);
        sbr_sk->save_prot = NULL;
    }
    release_sock(sk);
    return sk->sk_prot->connect(sk, uaddr, addr_len);
}

static s32 dpa_inet_fallback(struct sock *sk, s32 d2a_evnet)
{
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    lock_sock(sk);
    (void)sbr_migrate_d2a(sk, d2a_evnet);
    s32 status = (s32)sbr_sk->status;
    release_sock(sk);
    return status;
}

static void dpa_port_fallback(sbr_socket_t *sbr_sk, int sport, int dport)
{
    struct sock *sk = sbr_sk->sk;
    bool fallback = false;
    lock_sock(sk);
    /* both sport and dport is 0 will fallback all socks */
    fallback = (!sport && !dport) || (sk->sk_num == sport) || (ntohs(sk->sk_dport) == dport);
    if (!fallback || sbr_sk->status == SK_CLOSE) {
        release_sock(sk);
        return;
    }

    while (sbr_sk->status == SK_MIGRATE_A2D) {
        release_sock(sk);
        msleep(1);
        lock_sock(sk);
    }
    if (sbr_sk->status == SK_MIGRATE_OK) {
        sbr_sk->d2a_event = D2A_EVT_ECALL_FALLBACK;
        sbr_msg_retry_deinit(&sbr_sk->cork_send_timer.common);
        sbr_sk_remove_msg_wq(sbr_sk);
        NS_INF("migrate_d2a start sk_id=%lu, fd=%d", sbr_sk->sk_id, sbr_sk->fd);
        (void)sbr_sk->fdopt->migrate_d2a(sbr_sk);
    }
    release_sock(sk);
}

void dpa_ecall_fallback(int sport, int dport)
{
    int i;
    sbr_socket_t *sbr_sk = NULL;
    for (i = 1; i < SOCKET_NUM + 1; i++) {
        sbr_sk = get_dpa_sk(i);
        if (sbr_sk != NULL) {
            dpa_port_fallback(sbr_sk, sport, dport);
            put_dpa_sk(sbr_sk);
        }
    }
}
EXPORT_SYMBOL(dpa_ecall_fallback);

#define DPA_FALLBACK 100

NSTACK_STATIC int dpa_inet_setsockopt(struct socket *sock, int level, int optname, sockptr_t optval,
    unsigned int optlen)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;

    NS_INF("sk_id=%lu, fd=%d, level=%d, optname=%d, optlen=%u",
        sbr_sk->sk_id, sbr_get_fd(sk), level, optname, optlen);
    if (level == SOL_SOCKET && optname == DPA_FALLBACK) {
        int val;
        if (optlen < sizeof(int))
            return -EINVAL;

        if (copy_from_sockptr(&val, optval, sizeof(val)))
            return -EFAULT;

        if (val == 0) {
            return 0;
        }
        return (dpa_inet_fallback(sk, D2A_EVT_FALLBACK) == SK_CLOSE) ? 0 : -EPROTO;
    }

    lock_sock(sk);
    if (sbr_sk->status == SK_MIGRATE_A2D || sbr_sk->status == SK_MIGRATE_D2A) {
        long timeo = MAX_SCHEDULE_TIMEOUT;
        int err = sbr_wait_migrate(sbr_sk, &timeo);
        if (err) {
            NS_WAR("sk_id=%lu, fd=%d, status %u not ready", sbr_sk->sk_id, sbr_sk->fd, sbr_sk->status);
        }
    }

    enum opt_action action;
    if (sbr_sk->status == SK_MIGRATE_OK) {
        action = sbr_sockopt_get_action(level, optname);
        if (action == OPT_ACTION_FALLBACK) {
            (void)sbr_migrate_d2a(sk, D2A_EVT_OPT_UNSUPP);
            action = OPT_ACTION_LINUX;
        }
    } else {
        action = OPT_ACTION_LINUX;
    }

    int ret;
    if (action == OPT_ACTION_LINUX || action == OPT_ACTION_BOTH) {
        release_sock(sk);
        if (level == SOL_SOCKET) {
            ret = sock_setsockopt(sock, level, optname, optval, optlen);
        } else {
            ret = sbr_sk->save_ops->setsockopt(sock, level, optname, optval, optlen);
        }
        if (ret != 0 || action == OPT_ACTION_LINUX) {
            NS_DBG("sk_id=%lu, fd=%d, ret=%d, level=%d, optname=%d",
                sbr_sk->sk_id, sbr_get_fd(sk), ret, level, optname);
            return ret;
        }
        /* continue call sbr_setsockopt() */
        lock_sock(sk);
        /* status may change in prev release_sock() */
        if (sbr_sk->status != SK_MIGRATE_OK) {
            release_sock(sk);
            NS_DBG("migrate not ready, sk_id=%lu, fd=%d, ret=%d, level=%d, optname=%d, status=%u",
                sbr_sk->sk_id, sbr_get_fd(sk), ret, level, optname, sbr_sk->status);
            return ret;
        }
    }

    void *koptval = NULL;
    if ((level == SOL_SOCKET) && (optname == SO_BINDTODEVICE) && (optlen == 0UL)) {
        koptval = stack_malloc(1);
        if (koptval == NULL) {
            NS_ERR("sk_id=%lu, fd=%d, stack_malloc fail", sbr_sk->sk_id, sbr_get_fd(sk));
            release_sock(sk);
            return -ENOMEM;
        }
        *(char *)koptval = '\0';
    } else {
        koptval = stack_malloc(optlen);
        if (koptval == NULL) {
            NS_ERR("sk_id=%lu, fd=%d, stack_malloc fail", sbr_sk->sk_id, sbr_get_fd(sk));
            release_sock(sk);
            return -ENOMEM;
        }
        if (copy_from_sockptr(koptval, optval, optlen) != 0) {
            stack_free(koptval);
            NS_ERR("sk_id=%lu, fd=%d, copy_from_sockptr fail", sbr_sk->sk_id, sbr_get_fd(sk));
            release_sock(sk);
            return -EFAULT;
        }
    }

    s32 dpa_ret = sbr_setsockopt(sk, level, optname, koptval, optlen);
    if (dpa_ret != 0) {
        NS_ERR("sk_id=%lu, fd=%d, dpa_ret=%d, level=%d, optname=%d, optlen=%u",
            sbr_sk->sk_id, sbr_get_fd(sk), dpa_ret, level, optname, optlen);
    }
    stack_free(koptval);
    if (action == OPT_ACTION_DPA) {
        ret = dpa_ret;
    }
    release_sock(sk);
    return ret;
}

static int dpa_getsockopt_status(sbr_socket_t *sbr_sk, char __user *optval, int __user *optlen)
{
    struct dpa_status status;

    status.fd = sbr_sk->fd;
    status.status = sbr_sk->status;
    int len;

    if (get_user(len, optlen))
        return -EFAULT;
    if (len <= 0)
        return -EINVAL;
    len = min_t(int, sizeof(status), len);
    if (put_user(len, optlen))
        return -EFAULT;

    if (copy_to_user(optval, &status, (unsigned long)len))
        return -EFAULT;
    return 0;
}

NSTACK_STATIC int dpa_inet_getsockopt(struct socket *sock, int level, int optname, char __user *optval,
    int __user *optlen)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;

    NS_INF("sk_id=%lu, fd=%d, level=%d, optname=%d", sbr_sk->sk_id, sbr_get_fd(sk), level, optname);

    int ret;
    if (level == SOL_SOCKET) {
        if (optname == DPA_STATUS) {
            ret = dpa_getsockopt_status(sbr_sk, optval, optlen);
        } else {
            ret = sock_getsockopt(sock, level, optname, optval, optlen);
        }
    } else {
        ret = sbr_sk->save_ops->getsockopt(sock, level, optname, optval, optlen);
    }
    if (ret != 0) {
        NS_ERR("sk_id=%lu, fd=%d, ret=%d level %d optname %d", sbr_sk->sk_id, sbr_get_fd(sk), ret, level, optname);
    }
    return ret;
}

NSTACK_STATIC int dpa_inet_recvmsg(struct socket *sock, struct msghdr *msg, size_t size, int flags)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    NS_DBG("fd=%d, size=%lu, flags=%d, msg->msg_flags=%d", sbr_get_fd(sk), size, flags, msg->msg_flags);
    s32 ret;
    if (sbr_socket_need_sync(sbr_sk)) {
        ret = sbr_recvmsg(sk, msg, size, flags);
    } else {
        ret = sbr_sk->save_ops->recvmsg(sock, msg, size, flags);
    }
    NS_DBG("fd=%d, ret=%d", sbr_get_fd(sk), ret);
    return ret;
}

NSTACK_STATIC int dpa_inet_sendmsg(struct socket *sock, struct msghdr *msg, size_t size)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    NS_DBG("fd=%d, size=%lu, msg->msg_flags=%d", sbr_get_fd(sk), size, msg->msg_flags);
    lock_sock(sk);
    s32 ret;
    if (sbr_socket_need_sync(sbr_sk)) {
        ret = sbr_sendmsg(sk, msg, size);
        release_sock(sk);
    } else {
        release_sock(sk);
        ret = sbr_sk->save_ops->sendmsg(sock, msg, size);
    }
    NS_DBG("fd=%d, ret=%d", sbr_get_fd(sk), ret);
    return ret;
}

NSTACK_STATIC int dpa_inet_shutdown(struct socket *sock, int how)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    NS_INF("sk_id=%lu, fd=%d, how=%d", sbr_sk->sk_id, sbr_get_fd(sk), how);
    lock_sock(sk);
    s32 ret;
    if (sbr_socket_need_sync(sbr_sk)) {
        ret = sbr_shutdown(sk, how);
        release_sock(sk);
    } else {
        release_sock(sk);
        ret = sbr_sk->save_ops->shutdown(sock, how);
    }
    if (ret != 0) {
        NS_INF("sk_id=%lu, fd=%d, ret=%d", sbr_sk->sk_id, sbr_get_fd(sk), ret);
    }
    return ret;
}

NSTACK_STATIC int dpa_inet_close(struct socket *sock)
{
    struct sock *sk = sock->sk;

    if (sk != NULL) {
        sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;

        NS_INF("sk_id=%lu, fd=%d", sbr_sk->sk_id, sbr_sk->fd);
        lock_sock(sk);
        s32 ret = 0;
        if (sbr_socket_need_sync(sbr_sk)) {
            ret = sbr_close(sk);
        }
        WRITE_ONCE(sock->ops, sbr_sk->save_ops);
        WRITE_ONCE(sk->sk_prot, sbr_sk->save_prot);
        release_sock(sk);
        if (ret != 0) {
            NS_INF("sk_id=%lu, fd=%d, ret=%d", sbr_sk->sk_id, sbr_sk->fd, ret);
        }
        return sock->ops->release(sock);
    }
    return 0;
}

static void dpa_sock_destruct(struct sock *sk)
{
    sbr_socket_t *sbr_sk = inet_sk(sk)->dpa_ctx;
    if (sbr_sk != NULL) {
        if (sbr_sk->fd > 0) {
            NS_WAR("sk_id=%lu, fd=%d not released", sbr_sk->sk_id, sbr_sk->fd);
        }
        inet_sk(sk)->dpa_ctx = NULL;
        kfree(sbr_sk);
    }

    if (sk->sk_protocol == IPPROTO_TCP) {
        inet_sock_destruct(sk);
    } else {
        udp_destruct_sock(sk);
    }
    sbr_cur_tot_sock_dec();
}

static void dpa_socket_migrate_a2d(sbr_socket_t *sbr_sock)
{
    struct sock *sk = sbr_sock->sk;
    struct socket *sock = sk->sk_socket;

    sbr_sock->status = SK_MIGRATE_A2D;
    if (sock != NULL) {
        sbr_sock->save_ops = sock->ops;
    } else {
        sbr_sock->is_tcp_server = 1;
    }
    sbr_sock->save_prot = sk->sk_prot;
    if (sk->sk_family == AF_INET) {
        if (sk->sk_protocol == IPPROTO_TCP) {
            if (sock != NULL) {
                WRITE_ONCE(sock->ops, &dpa_inet_stream_ops);
            }
            WRITE_ONCE(sk->sk_prot, &dpa_inet_tcp_prot);
        } else {
            if (sock != NULL) {
                WRITE_ONCE(sock->ops, &dpa_inet_dgram_ops);
            }
            WRITE_ONCE(sk->sk_prot, &dpa_inet_udp_prot);
        }
    } else {
        if (sk->sk_protocol == IPPROTO_TCP) {
            if (sock != NULL) {
                WRITE_ONCE(sock->ops, &dpa_inet6_stream_ops);
            }
            WRITE_ONCE(sk->sk_prot, &dpa_inet6_tcp_prot);
        } else {
            if (sock != NULL) {
                WRITE_ONCE(sock->ops, &dpa_inet6_dgram_ops);
            }
            WRITE_ONCE(sk->sk_prot, &dpa_inet6_udp_prot);
        }
    }

    sbr_sock->backup_sk_userlocks = sk->sk_userlocks;
    if ((sk->sk_protocol == IPPROTO_TCP) && ((sk->sk_userlocks & SOCK_RCVBUF_LOCK) == 0)) {
        s32 val = min_t(int, TCP_DEF_ACPU_RCVBUF, sock_net(sk)->ipv4.sysctl_tcp_rmem[2]);
        sk->sk_userlocks |= SOCK_RCVBUF_LOCK;
        WRITE_ONCE(sk->sk_rcvbuf, val);
    }

    s32 ret = sbr_migrate_a2d(sk);
    if (ret != 0) {
        sbr_sock->status = SK_CLOSE;
        if (sbr_sock->save_ops != NULL) {
            WRITE_ONCE(sock->ops, sbr_sock->save_ops);
        }
        WRITE_ONCE(sk->sk_prot, sbr_sock->save_prot);
        sk->sk_state_change(sk);
    }
}

static void dpa_migrate_pend_check(struct socket *sock)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    lock_sock(sk);
    if (sbr_sk->udp_wait_migrate) {
        sbr_sk->udp_wait_migrate = false;
        WRITE_ONCE(sock->ops, sbr_sk->save_ops);
        sbr_sk->save_ops = NULL;
        dpa_socket_migrate_a2d(sbr_sk);
    }
    release_sock(sk);
}

static int dpa_inet_pre_recvmsg(struct socket *sock, struct msghdr *msg, size_t size, int flags)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    int ret = sbr_sk->save_ops->recvmsg(sock, msg, size, flags);
    if (ret > 0 && sbr_sk->udp_wait_migrate) {
        dpa_migrate_pend_check(sock);
    }
    return ret;
}

static int dpa_inet_pre_sendmsg(struct socket *sock, struct msghdr *msg, size_t size)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;
    int ret = sbr_sk->save_ops->sendmsg(sock, msg, size);
    if (ret > 0 && sbr_sk->udp_wait_migrate) {
        dpa_migrate_pend_check(sock);
    }
    return ret;
}

/* sk lock aleady hold */
static void dpa_socket_take(struct sock *sk)
{
    struct socket *sock = sk->sk_socket;
    sbr_socket_t *sbr_sock = inet_sk(sk)->dpa_ctx;
    bool sbr_sock_alloc = false;

    if (sk->sk_kern_sock) {
        return;
    }

    if ((sk->sk_family != AF_INET && sk->sk_family != AF_INET6) ||
        (sk->sk_protocol != IPPROTO_TCP && sk->sk_protocol != IPPROTO_UDP)) {
        NS_DBG("sk_family %u sk_protocol %u unsupport", sk->sk_family, sk->sk_protocol);
        return;
    }

    if (inet_sk(sk)->dpa_enable != 1) {
        return;
    }

    /* skip system port */
    if (sk->sk_num < 1000 || ntohs(sk->sk_dport) == DNS_PORT) {
        NS_DBG("skip %s sk_num %u sk_dport %u", (sk->sk_protocol == IPPROTO_UDP) ? "udp" : "tcp",
            sk->sk_num, ntohs(sk->sk_dport));
        return;
    }

    if (sbr_sock != NULL) {
        if (sbr_sock->is_tcp_server) {
            spin_lock_bh(&sk->sk_lock.slock);
            /* socket is accepted */
            if (sbr_sock->status == SK_MIGRATE_A2D || sbr_sock->status == SK_MIGRATE_OK) {
                sbr_sock->save_ops = sock->ops;
                if (sk->sk_family == AF_INET) {
                    WRITE_ONCE(sock->ops, &dpa_inet_stream_ops);
                } else {
                    WRITE_ONCE(sock->ops, &dpa_inet6_stream_ops);
                }
            }
            spin_unlock_bh(&sk->sk_lock.slock);
            return;
        } else if (sbr_sock->status != SK_CLOSE) {
            NS_INF("sk_id=%ld,domain=%d,type=%d,protocol=%d status unexpect", sbr_sock->sk_id,
                sk->sk_family, sk->sk_type, sk->sk_protocol, sbr_sock->status);
            return;
        }
        if (sbr_sock->save_ops != NULL && sbr_sock->save_ops != sock->ops) {
            WRITE_ONCE(sock->ops, sbr_sock->save_ops);
        }
        if (sbr_sock->save_prot != NULL && sbr_sock->save_prot != sk->sk_prot) {
            WRITE_ONCE(sk->sk_prot, sbr_sock->save_prot);
        }
        (void)memset_s(sbr_sock, sizeof(sbr_socket_t), 0, sizeof(sbr_socket_t));
    } else {
        sbr_sock = kzalloc(sizeof(sbr_socket_t), GFP_ATOMIC);
        if (sbr_sock == NULL) {
            NS_WAR("kzalloc fail");
            return;
        }
        sbr_sock_alloc = true;
    }

    sbr_fdopt *fdopt = sbr_get_fdopt(sk->sk_family, sk->sk_type);
    if (fdopt == NULL) {
        kfree(sbr_sock);
        return;
    }

    sbr_sock->sk_id = sbr_total_sock_inc_return();
    sbr_sock->fd = -1;
    sbr_sock->fdopt = fdopt;
    sbr_sock->sk = sk;
    skb_queue_head_init(&sbr_sock->dpa_queue);
    sbr_sock->in_msg_wq = false;
    if (sk->sk_protocol == IPPROTO_TCP) {
        sbr_sock->sk_msg_recovery_handle = sbr_tcp_msg_wq_handle;
    } else if (sk->sk_protocol == IPPROTO_UDP) {
        sbr_sock->sk_msg_recovery_handle = sbr_udp_msg_wq_handle;
    }
    INIT_LIST_HEAD(&sbr_sock->sk_msg_wq_node);
    INIT_LIST_HEAD(&sbr_sock->migrate_iov_list);
    INIT_LIST_HEAD(&sbr_sock->migrate_wait_list);

    NS_INF("sk_id=%ld,domain=%d,type=%d,protocol=%d,sport=%u,dport=%u", sbr_sock->sk_id,
        sk->sk_family, sk->sk_type, sk->sk_protocol, sk->sk_num, ntohs(sk->sk_dport));
    if (sbr_sock_alloc) {
        /* this will block the socket's packet receive */
        WRITE_ONCE(inet_sk(sk)->dpa_ctx, (void *)sbr_sock);
        sbr_sock->save_sk_destruct = sk->sk_destruct;
        WRITE_ONCE(sk->sk_destruct, dpa_sock_destruct);
        sbr_cur_tot_sock_inc();
    }
    if (sk->sk_protocol == IPPROTO_UDP) {
        sbr_sock->status = SK_CLOSE;
        sbr_sock->save_ops = sock->ops;
        sbr_sock->udp_wait_migrate = true;
        if (sk->sk_family == AF_INET) {
            WRITE_ONCE(sock->ops, &dpa_inet_dgram_pre_ops);
        } else {
            WRITE_ONCE(sock->ops, &dpa_inet6_dgram_pre_ops);
        }
        return;
    }
    dpa_socket_migrate_a2d(sbr_sock);
}

static ssize_t dpa_sendpage(struct socket *sock, struct page *page, int offset,
    size_t size, int flags)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;

    NS_INF("sk_id=%lu, fd=%d, fallback", sbr_sk->sk_id, sbr_sk->fd);
    s32 status = dpa_inet_fallback(sk, D2A_EVT_API_UNSUPP);
    if (status != SK_CLOSE) {
        NS_ERR("sk_id=%lu, fd=%d, incorrect status %u", sbr_sk->sk_id, sbr_sk->fd, status);
        return -EPROTO;
    }
    return sbr_sk->save_ops->sendpage(sock, page, offset, size, flags);
}

static ssize_t dpa_splice_read(struct socket *sock, loff_t *ppos, struct pipe_inode_info *pipe,
    size_t len, unsigned int flags)
{
    struct sock *sk = sock->sk;
    sbr_socket_t *sbr_sk = (sbr_socket_t *)inet_sk(sk)->dpa_ctx;

    NS_INF("sk_id=%lu, fd=%d,  fallback", sbr_sk->sk_id, sbr_sk->fd);
    s32 status = dpa_inet_fallback(sk, D2A_EVT_API_UNSUPP);
    if (status != SK_CLOSE) {
        NS_ERR("sk_id=%lu, fd=%d, incorrect status %u", sbr_sk->sk_id, sbr_sk->fd, status);
        return -EPROTO;
    }
    return sbr_sk->save_ops->splice_read(sock, ppos, pipe, len, flags);
}

static void dpa_ops_init(struct proto_ops *ops)
{
    ops->release = dpa_inet_close;
    ops->setsockopt = dpa_inet_setsockopt;
    ops->getsockopt = dpa_inet_getsockopt;
    ops->sendmsg = dpa_inet_sendmsg;
    ops->recvmsg = dpa_inet_recvmsg;
    ops->shutdown = dpa_inet_shutdown;
    ops->sendpage = dpa_sendpage;
}

#ifndef CONFIG_DPA_PROTO
typedef void (*sk_backlog_func)(struct sock *sk, struct sk_buff *skb);
extern void dpa_backlog_func_register(sk_backlog_func func);
typedef void (*tcp_child_abort_func)(struct sock *sk);
extern void tcp_child_abort_hook_register(tcp_child_abort_func func);
typedef void (*setsockopt_hook_func)(struct sock *sk, int level, int optname);
extern void setsockopt_hook_register(setsockopt_hook_func func);
typedef void (*sock_offload_func)(struct socket *sock);
extern void sock_offload_func_register(sock_offload_func func);
typedef void (*setsockopt_prehook_func)(struct socket *sock, int level, int optname, sockptr_t optval,
    int optlen, int *ret, bool *eat);
void pre_setsockopt_hook_register(setsockopt_prehook_func func);

typedef void (*getsockopt_prehook_func)(struct socket *sock, int level, int optname, char __user *user_optval,
    int __user *optlen, int *ret, bool *eat);
void pre_getsockopt_hook_register(getsockopt_prehook_func func);
#endif

extern const struct proto_ops inet_stream_ops;
extern struct proto tcp_prot;
extern const struct proto_ops inet_dgram_ops;
extern struct proto udp_prot;
extern const struct proto_ops inet6_stream_ops;
extern struct proto tcpv6_prot;
extern const struct proto_ops inet6_dgram_ops;
extern struct proto udpv6_prot;

static void dpa_tcp_backlog_queue(sbr_socket_t *sbr_sock, struct sk_buff *skb)
{
    skb_dst_force(skb);
    if (!sbr_sock->dpa_tail)
        WRITE_ONCE(sbr_sock->dpa_head, skb);
    else
        sbr_sock->dpa_tail->next = skb;
    WRITE_ONCE(sbr_sock->dpa_tail, skb);
    skb->next = NULL;
}

static void dpa_tcp_backlog_add(struct sock *sk, struct sk_buff *skb)
{
    sbr_socket_t *sbr_sock = inet_sk(sk)->dpa_ctx;
    dpa_tcp_backlog_queue(sbr_sock, skb);
    u8 iov_cnt = (u8)DIV_ROUND_UP(skb->len, MAA_UNMAP_SIZE);
    sbr_conn_stat_update(sbr_sock->stats, SBR_RX_TCP_BACKLOG_IN, iov_cnt, (u32)skb->len);
    if (sbr_sock->status != SK_MIGRATE_OK) {
        return;
    }
    if (tcp_hdr(skb)->fin || tcp_hdr(skb)->rst) {
        if (sock_owned_by_user(sk)) {
            if (sbr_sock->rcv_fin_rst == 0) {
                sbr_sock->rcv_fin_rst = tcp_hdr(skb)->fin ? RCV_FIN : RCV_RST;
                /* Try again later. */
                sk_reset_timer(sk, &sbr_sock->fin_rst_tmr, jiffies + 1);
            }
        } else {
            sbr_sock->d2a_event = tcp_hdr(skb)->fin ? D2A_EVT_RCV_FIN : D2A_EVT_RCV_RST;
            s32 ret = sbr_sock->fdopt->migrate_d2a(sbr_sock);
            if (ret == 0) {
                NS_INF("sk_id=%lu, fd=%d, tcp backlog migrate_d2a succ", sbr_sock->sk_id, sbr_sock->fd);
            } else {
                NS_ERR("sk_id=%lu, fd=%d, tcp backlog migrate_d2a fail ret %d", sbr_sock->sk_id, sbr_sock->fd, ret);
            }
        }
    } else {
        coop_migrate_a2d_backlog(sk, 1, false);
    }
}

/* Passive create tcp socket may use this */
static void dpa_tcp_child_abort_hook(struct sock *sk)
{
    lock_sock(sk);
    sbr_passive_close(sk);
    release_sock(sk);
}

static void dpa_setsockopt_hook(struct sock *sk, int level, int optname)
{
    if (net_eq(sock_net(sk), &init_net) == 0) {
        return;
    }

    if ((sk->sk_family != AF_INET && sk->sk_family != AF_INET6) ||
        (sk->sk_protocol != IPPROTO_TCP && sk->sk_protocol != IPPROTO_UDP)) {
        return;
    }

    lock_sock(sk);

    /* Don't race with BH socket. */
    local_bh_disable();
    bh_lock_sock(sk);
    if (inet_sk(sk)->dpa_opt == DPA_OPT_UNSUPPORT) {
        goto out;
    }

    if (!sbr_sockopt_is_support(level, optname)) {
        NS_INF("uid %u opt level %d optname %d not support, dpa is disabled", sk->sk_uid.val, level, optname);
        inet_sk(sk)->dpa_enable = 0;
        inet_sk(sk)->dpa_opt = DPA_OPT_UNSUPPORT;
#ifdef CONFIG_DPA_CHR
        migrate_fail_stat(sk, D2A_EVT_PRE_OPT_UNSUPP);
#endif
    }

out:
    bh_unlock_sock(sk);
    local_bh_enable();
    release_sock(sk);
}

typedef void (*tcp_mtu_reduced_func)(struct sock *sk, bool *skip_rtx);
extern void tcp_mtu_reduced_hook_register(tcp_mtu_reduced_func func);

static void dpa_tcp_mtu_reduced_hook(struct sock *sk, bool *skip_rtx)
{
    sbr_socket_t *sbr_sock = inet_sk(sk)->dpa_ctx;
    if (sbr_sock == NULL || sbr_sock->status != SK_MIGRATE_OK) {
        *skip_rtx = false;
        return;
    }
    NS_WAR("sk_id=%lu, fd=%d, because of mtu reduced, migrate_d2a start", sbr_sock->sk_id, sbr_sock->fd);
    sbr_sock->d2a_event = D2A_EVT_PMTU_REDUCED;
    s32 ret = sbr_sock->fdopt->migrate_d2a(sbr_sock);
    if (ret == 0) {
        NS_INF("sk_id=%lu, fd=%d, migrate_d2a succ", sbr_sock->sk_id, sbr_sock->fd);
    } else {
        NS_ERR("sk_id=%lu, fd=%d, migrate_d2a fail ret %d", sbr_sock->sk_id, sbr_sock->fd, ret);
    }
    *skip_rtx = true;
}

static int dpa_prot_abort(struct sock *sk, int err)
{
    sbr_socket_t *sbr_sock = inet_sk(sk)->dpa_ctx;

    lock_sock(sk);
    while (sbr_sock->status == SK_MIGRATE_A2D) {
        release_sock(sk);
        msleep(1);
        lock_sock(sk);
    }
    if (sbr_sock->status == SK_MIGRATE_OK) {
        sbr_sock->d2a_event = D2A_EVT_DIAG_ABORT;
        sbr_msg_retry_deinit(&sbr_sock->cork_send_timer.common);
        sbr_sk_remove_msg_wq(sbr_sock);
        NS_INF("migrate_d2a start sk_id=%lu, fd=%d", sbr_sock->sk_id, sbr_sock->fd);
        (void)sbr_sock->fdopt->migrate_d2a(sbr_sock);
    }
    while (sbr_sock->status == SK_MIGRATE_D2A) {
        release_sock(sk);
        msleep(1);
        lock_sock(sk);
    }
    release_sock(sk);

    return sbr_sock->save_prot->diag_destroy(sk, err);
}

static int dpa_prot_disconnect(struct sock *sk, int flags)
{
    sbr_socket_t *sbr_sock = inet_sk(sk)->dpa_ctx;
    NS_INF("sk_id=%lu, fd=%d disconnect", sbr_sock->sk_id, sbr_sock->fd);
    (void)sbr_close(sk);
    if (sbr_sock->save_ops != NULL) {
        WRITE_ONCE(sk->sk_socket->ops, sbr_sock->save_ops);
        sbr_sock->save_ops = NULL;
    }

    if (sbr_sock->save_prot != NULL) {
        WRITE_ONCE(sk->sk_prot, sbr_sock->save_prot);
        sbr_sock->save_prot = NULL;
    }
    sbr_sock->is_tcp_server = 0;
    return sk->sk_prot->disconnect(sk, flags);
}

#define SO_OFFLOAD 255

static void dpa_pre_setsockopt_hook(struct socket *sock, int level, int optname, sockptr_t optval, int optlen,
    int *ret, bool *eat)
{
    struct sock *sk = sock->sk;
    if ((sk->sk_family != AF_INET && sk->sk_family != AF_INET6) ||
        (sk->sk_protocol != IPPROTO_TCP && sk->sk_protocol != IPPROTO_UDP)) {
        return;
    }
#ifdef CONFIG_DPA_CHR
    enum opt_action action;
    action = sbr_sockopt_get_action(level, optname);
    opt_use_stat(sk, level, optname, action);
#endif
    if (level != SOL_SOCKET || optname != SO_OFFLOAD) {
        *eat = false;
        return;
    }

    *eat = true;
	if (optlen < sizeof(struct so_offload)) {
		*ret = -EINVAL;
        return;
    }

    struct so_offload offload;
	if (copy_from_sockptr(&offload, optval, sizeof(offload))) {
		*ret = -EFAULT;
        return;
    }


    lock_sock(sk);
    if (sk->sk_state != TCP_CLOSE) {
        *ret = -EINVAL;
        release_sock(sk);
        return;
    }

    if (inet_sk(sk)->dpa_ctx != NULL) {
        NS_INF("dpa_ctx is set");
        release_sock(sk);
        *ret = -EINVAL;
        return;
    }

    (void)memcpy_s(&inet_sk(sk)->dpa_cfg, sizeof(struct so_offload), &offload, sizeof(struct so_offload));
    if (offload.enable) {
        if (inet_sk(sk)->dpa_opt == 2) {
            inet_sk(sk)->dpa_enable = 1;
            *ret = 0;
        } else {
            *ret = -EINVAL;
        }
    } else {
        inet_sk(sk)->dpa_enable = 0;
        *ret = 0;
    }
    release_sock(sk);
    NS_INF("offload.enable %d dpa_opt %d dpa_enable %u", offload.enable, inet_sk(sk)->dpa_opt,
        inet_sk(sk)->dpa_enable);
}

static void dpa_pre_getsockopt_hook(struct socket *sock, int level, int optname, char __user *user_optval,
    int __user *optlen, int *ret, bool *eat)
{
    struct sock *sk = sock->sk;
    if ((sk->sk_family != AF_INET && sk->sk_family != AF_INET6) ||
        (sk->sk_protocol != IPPROTO_TCP && sk->sk_protocol != IPPROTO_UDP)) {
        return;
    }
#ifdef CONFIG_DPA_CHR
    enum opt_action action;
    action = sbr_sockopt_get_action(level, optname);
    opt_use_stat(sk, level, optname, action);
#endif
    if (level != SOL_SOCKET || optname != SO_OFFLOAD) {
        *eat = false;
        return;
    }

    *eat = true;
    int len;
	if (get_user(len, optlen)) {
		*ret = -EFAULT;
        return;
    }
	if (len <= 0) {
		*ret = -EINVAL;
        return;
    }
	len = min_t(int, sizeof(struct so_offload), len);
	if (put_user(len, optlen)) {
		*ret = -EFAULT;
        return;
    }

    lock_sock(sk);
    struct so_offload offload = inet_sk(sk)->dpa_cfg;
    release_sock(sk);
	if (copy_to_user(user_optval, &offload, len)) {
		*ret = -EFAULT;
        return;
    }
    *ret = 0;
}

void socket_take_over_init(void)
{
    dpa_inet_stream_ops = inet_stream_ops;
    dpa_ops_init(&dpa_inet_stream_ops);
    dpa_inet_stream_ops.splice_read = dpa_splice_read,
    dpa_inet_dgram_ops = inet_dgram_ops;
    dpa_ops_init(&dpa_inet_dgram_ops);
    dpa_inet_dgram_pre_ops = inet_dgram_ops;
    dpa_inet_dgram_pre_ops.sendmsg = dpa_inet_pre_sendmsg;
    dpa_inet_dgram_pre_ops.recvmsg = dpa_inet_pre_recvmsg;

    dpa_inet_tcp_prot = tcp_prot;
    dpa_inet_tcp_prot.stream_memory_free = NULL;
    dpa_inet_tcp_prot.diag_destroy = dpa_prot_abort;
    dpa_inet_tcp_prot.disconnect = dpa_prot_disconnect;
    dpa_inet_udp_prot = udp_prot;
    dpa_inet_udp_prot.connect = dpa_udp_prot_connect;
    dpa_inet_udp_prot.diag_destroy = dpa_prot_abort;
    dpa_inet_udp_prot.disconnect = dpa_prot_disconnect;

    dpa_inet6_stream_ops = inet6_stream_ops;
    dpa_ops_init(&dpa_inet6_stream_ops);
    dpa_inet6_stream_ops.splice_read = dpa_splice_read,
    dpa_inet6_dgram_ops = inet6_dgram_ops;
    dpa_ops_init(&dpa_inet6_dgram_ops);
    dpa_inet6_dgram_pre_ops = inet6_dgram_ops;
    dpa_inet6_dgram_pre_ops.sendmsg = dpa_inet_pre_sendmsg;
    dpa_inet6_dgram_pre_ops.recvmsg = dpa_inet_pre_recvmsg;

    dpa_inet6_tcp_prot = tcpv6_prot;
    dpa_inet6_tcp_prot.stream_memory_free = NULL;
    dpa_inet6_tcp_prot.diag_destroy = dpa_prot_abort;
    dpa_inet6_tcp_prot.disconnect = dpa_prot_disconnect;
    dpa_inet6_udp_prot = udpv6_prot;
    dpa_inet6_udp_prot.connect = dpa_udp_prot_connect;
    dpa_inet6_udp_prot.diag_destroy = dpa_prot_abort;
    dpa_inet6_udp_prot.disconnect = dpa_prot_disconnect;

#ifdef CONFIG_DPA_PROTO
    REGISTER_HCK_VH(dpa_tcp_child_abort, dpa_tcp_child_abort_hook);
    REGISTER_HCK_VH(dpa_tcp_backlog, dpa_tcp_backlog_add);
    REGISTER_HCK_VH(dpa_pre_setsockopt, dpa_pre_setsockopt_hook);
    REGISTER_HCK_VH(dpa_pre_getsockopt, dpa_pre_getsockopt_hook);
    REGISTER_HCK_VH(dpa_setsockopt_check_support, dpa_setsockopt_hook);
    REGISTER_HCK_VH(dpa_pre_offload, dpa_socket_pre_take);
    REGISTER_HCK_VH(dpa_try_offload, dpa_socket_take);
    REGISTER_HCK_VH(dpa_tcp_mtu_reduced, dpa_tcp_mtu_reduced_hook);
#else
    tcp_child_abort_hook_register(dpa_tcp_child_abort_hook);
    dpa_backlog_func_register(dpa_tcp_backlog_add);
    pre_setsockopt_hook_register(dpa_pre_setsockopt_hook);
    pre_getsockopt_hook_register(dpa_pre_getsockopt_hook);
    setsockopt_hook_register(dpa_setsockopt_hook);
    sock_offload_func_register(dpa_socket_pre_take);
    tcp_mtu_reduced_hook_register(dpa_tcp_mtu_reduced_hook);
    dpa_offload_func_register(dpa_socket_take);
#endif
}

