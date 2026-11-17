#ifdef CONFIG_LIBLINUX
#include <trace/hooks/liblinux.h>
#include <linux/preempt.h>
#include <linux/irqflags.h>
#endif
#ifdef CONFIG_LOWPOWER_PROTOCOL
#include <net/lowpower_protocol.h>
#endif
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <asm/ioctls.h>
#include <linux/skmsg.h>
#include <net/busy_poll.h>
#include <net/sock.h>
#include <net/inet_sock.h>
#include <net/udp.h>
#include <net/transp_v6.h>
#include <linux/filter.h>
#include <bsp_dra.h>
#include "dpa_linux_sock.h"
#include "dpa_netdev_mng.h"
#include "dpa_resolve_neigh.h"
#include "client.h"
#include "adrv_stub.h"

#define DPA_SOCK_USE_DPA 1    /* DPA_SOCK_USE_DPA:0 used for tracing linux sock functions */
#define DPA_SOCK_PRINT_PARA 0 /* print socket para for debug apps */
#define DPA_SOCK_IPV4_ONLY  1

#define DPA_SOCK_MIN_MTU 1400
#define DPA_SOCK_TCP_OPTION_MAX 40
#define DPA_SOCK_IP4_OPTION_MAX 40
#define DPA_SOCK_MAX_NUM 5//200
#define DPA_SOCK_EVT_RCV 0
#define DPA_SOCK_EVT_ERR 4

/* if add new opt / ioctl args need to check the max size */
#define DPA_SOCK_MAX_OPTVAL_SIZE sizeof(struct __kernel_sock_timeval)
#define DPA_SOCK_MAX_IOCTL_ARG_SIZE sizeof(unsigned long long)

#define DPA_SOCK_MAX_MSG_FRAGS        3
#define DPA_SOCK_MAX_PACKER_SIZE    (DRA_OPIPE_LEVEL_1_SIZE*DRA_OPIPE_LEVEL_1_SIZE + 1024)  /* 3*maa + msghdr */

/* ref sneif.c */
#define SNEIFNAME0      'd'
#define SNEIFNAME1      'p'
#define SNEIFNAME_END   '1'
#define DPA_CFG_SNE_IFNAME(if_name) do {\
    (if_name)[0] = SNEIFNAME0;\
    (if_name)[1] = SNEIFNAME1;\
    (if_name)[2] = SNEIFNAME_END;\
} while(0)

enum {
    DPA_SOCK_BPF_IPV4,
    DPA_SOCK_BPF_IPV6,
    DPA_SOCK_BPF_NUM_PROTS,
};

struct dpa_lwip_sockaddr_in {
    unsigned char sa_len;
    unsigned char sa_family;
    unsigned short port;
    unsigned int sin_addr;
    char sin_zero[8];
};

struct dpa_lwip_sockaddr_in6 {
    unsigned char sa_len;
    unsigned char sa_family;
    unsigned short port;
    unsigned int sin6_flowinfo;
    unsigned char u8_addr[16];
    unsigned int sin6_scope_id;
};

#define DPA_IFNAMSIZ 6
struct dpa_lwip_ifreq {
    char if_name[DPA_IFNAMSIZ];
};

struct dpa_linux_sock_ctx {
    int fd;
    int sock_type;
    int sock_family;
    int sock_state;
    int dst_resolved;
    int dev_mtu;
    int is_recv_block;
    char resolv_mac[ETH_ALEN];
    struct dpa_lwip_ifreq dpa_netdev_name;
    struct sockaddr_in remote_addr4;
    struct sockaddr_in6 remote_addr6;
    struct dpa_iovec dpa_send_iov[DPA_SOCK_MAX_MSG_FRAGS];
    struct dpa_iovec dpa_recv_iov[DPA_SOCK_MAX_MSG_FRAGS];
    char* send_buf;
};

static struct proto dpa_udp_bpf_prots[DPA_SOCK_BPF_NUM_PROTS];
static struct proto dpa_tcp_bpf_prots[DPA_SOCK_BPF_NUM_PROTS];
static int g_dpa_sock_redir_force_bypass = 0;
static int g_dpa_sock_redir_force_en = 0;
static atomic_t g_dpa_sock_ref;
struct sock *g_dpa_sock = NULL;

#if !DPA_SOCK_USE_DPA
static struct proto dpa_udp_base_prots[DPA_SOCK_BPF_NUM_PROTS];
static struct proto dpa_tcp_base_prots[DPA_SOCK_BPF_NUM_PROTS];
#endif

static int dpa_sock_conv_para_for_sockopt(int in_level, int *out_level, int in_optname, int *out_optname);
static int dpa_wan_bpf_v4_build_proto(void);
static int dpa_wan_bpf_v6_build_proto(void);
static int dpa_sock_get_sockopt_prepare(struct sock *sk, int in_level, int in_optname, char *out_value, int *out_len);
static int dpa_sock_set_sockopt_prepare(struct sock *sk, int in_level, int in_optname, char *in_value, int in_len);

const char *g_interest_proc[] = {
    "iperf",
    "dpa_test",
    "dpa_udp_test",
    "dpa_tcp_test",
};

int name_check(const char *str)
{
    int i;
    for (i = 0; i < sizeof(g_interest_proc) / sizeof(g_interest_proc[0]); i++) {
        if (strstr(str, g_interest_proc[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

static void dpa_assign_sock_prot(struct sock *sk)
{
    int dpa_family;
    int uid;

    if (sk->sk_family == AF_INET) {
        dpa_family = DPA_SOCK_BPF_IPV4;
    } else if (sk->sk_family == AF_INET6) {
        dpa_family = DPA_SOCK_BPF_IPV6;
#if DPA_SOCK_IPV4_ONLY
        printk("not support ipv6 prot offload\n");
        return;
#endif
    } else {
        printk("dpa unassign prot:%d\n", sk->sk_family);
        return;
    }

    memcpy(&uid, &sk->sk_uid, sizeof(uid));
    switch (sk->sk_type) {
        case SOCK_STREAM:
            printk("dpa assign tcp prot:%s, uid:%d(0x%x), sk:0x%llx\n",
                   dpa_family == DPA_SOCK_BPF_IPV4 ? ("ipv4") : ("ipv6"), uid, uid, (unsigned long long)sk);
            sk_psock_update_proto(sk, NULL, &dpa_tcp_bpf_prots[dpa_family]);
            sk->sk_user_data = NULL;
            break;
        case SOCK_DGRAM:
            printk("dpa assign udp prot:%s, uid:%d(0x%x), sk:0x%llx\n",
                   dpa_family == DPA_SOCK_BPF_IPV4 ? ("ipv4") : ("ipv6"), uid, uid, (unsigned long long)sk);
            sk_psock_update_proto(sk, NULL, &dpa_udp_bpf_prots[dpa_family]);
            sk->sk_user_data = NULL;
            break;
        default:
            return;
    }

#if !DPA_SOCK_USE_DPA
    {
        int total_num;
        total_num = atomic_inc_return(&g_dpa_sock_ref);
        printk("do_sock_create succ, sk:%0x%llx, family(2:ipv4,10:ipv6):%d, prot_type(1:tcp,2:udp):%d, total_num:%d\n",
               (unsigned long long)sk, sk->sk_family, sk->sk_type, total_num);
    }
#endif

    return;
}

bool dpa_sock_is_interested(struct sock *sk)
{
    struct task_struct *task;

    if (g_dpa_sock_redir_force_bypass) {
        return false;
    }

    if (g_dpa_sock_redir_force_en) {
        printk("dpa_sock will start redirect, force_en:%d\n", g_dpa_sock_redir_force_en);
        return true;
    }

#ifdef CONFIG_LOWPOWER_PROTOCOL
    /* just used in ohos version */
    if (dpa_uid_match(sk->sk_uid.val)) {
        printk("dpa_sock will start redirect, dpa_uid_match:%d\n", sk->sk_uid.val);
        return true;
    }
#endif

    task = (struct task_struct *)current;

#ifdef CONFIG_LIBLINUX
    if (!(in_irq() || irqs_disabled())) {
        trace_ldk_rvh_get_thread_name(task->pid, task->comm, TASK_COMM_LEN);
    }
#endif

    if (name_check(task->comm)) {
        printk("dpa_sock will start redirect, name:%s\n", task->comm);
        return true;
    }

    printk("dpa_sock will not redirect, name:%s\n", task->comm);
    return false;
}

static void dpa_sock_assign_sock_prot(struct sock *sk)
{
    if (!dpa_sock_is_interested(sk)) {
        return;
    }
    g_dpa_sock = sk;

    if (atomic_read(&g_dpa_sock_ref) > DPA_SOCK_MAX_NUM) {
        printk("dpa_sock created num is too much\n", DPA_SOCK_MAX_NUM);
        return;
    }

    if (refcount_inc_not_zero(&sk->sk_refcnt)) {
        dpa_assign_sock_prot(sk);
        sock_put(sk);
    }
}

#if !DPA_SOCK_USE_DPA
static inline struct proto *dpa_sock_get_base_prot(struct sock *sk)
{
    struct proto *base = NULL;
    int dpa_family;

    if (sk->sk_family == AF_INET) {
        dpa_family = DPA_SOCK_BPF_IPV4;
    } else if (sk->sk_family == AF_INET6) {
        dpa_family = DPA_SOCK_BPF_IPV6;
    }

    if (sk->sk_type == SOCK_STREAM) {
        base = &dpa_tcp_base_prots[dpa_family];
    } else if (sk->sk_type == SOCK_DGRAM) {
        base = &dpa_udp_base_prots[dpa_family];
    }

    return base;
}
#endif

void dpa_sock_offload(struct socket *sock)
{
    dpa_sock_assign_sock_prot(sock->sk);
}

int dpa_sock_force_redir_en(int en)
{
    g_dpa_sock_redir_force_en = en;
    return 0;
}
int dpa_sock_redir_force_bypass(int en)
{
    g_dpa_sock_redir_force_bypass = en;
    return en;
}

int dpa_sock_get_total_num(void)
{
    int num = atomic_read(&g_dpa_sock_ref);
    printk("dpa_sock total num:%d\n", num);
    return num;
}

/* set socket level opt */
static int dpa_sock_set_socket_opt(struct sock *sk, struct dpa_linux_sock_ctx *sock_ctx)
{
    int ret;
    int optval;

    /* socket sk reuse opt */
    if (sk->sk_reuse) {
        optval = 1;
        printk("dpa_sock_setsockopt(SO_REUSEADDR) fd:%d\n", sock_ctx->fd);
        ret = dpa_sock_setsockopt(sock_ctx->fd, DPA_SOCK_SOL_SOCKET, DPA_SOCK_SO_REUSEADDR, (void *)&optval,
                                  sizeof(optval));
        if (ret) {
            printk("dpa_sock_setsockopt error:%d\n", ret);
            return -EINVAL;
        }
    }

    /* add other socket opt later */

    return 0;
}

static int dpa_sock_get_prot_type(struct sock *sk)
{
    int prot_type = DPA_SOCK_DGRAM;

    switch (sk->sk_type) {
        case SOCK_STREAM:
            prot_type = DPA_SOCK_STREAM;
            break;
        case SOCK_DGRAM:
            prot_type = DPA_SOCK_DGRAM;
            break;
        default:
            return -1;
    }
    return prot_type;
}

static void dpa_sock_cleanup_recv_queue(struct sock *sk)
{
    while (!skb_queue_empty_lockless(&sk->sk_receive_queue)) {
        struct sk_buff *skb = skb_dequeue(&sk->sk_receive_queue);
        if (skb != NULL) {
            dev_kfree_skb_any(skb);
        }
    }
}

static void dpa_sock_event_cb(struct sock *priv, unsigned long long addr, unsigned int len, unsigned int offset)
{
    struct sk_buff *skb;
    unsigned long long orig;
    struct sock *sk = priv;

    skb = bsp_dra_unmap(addr, &orig);
    if ((skb == NULL) || (sk == NULL)) {
        bsp_dra_free(orig);
        return;
    }

    skb_reserve(skb, offset);
    skb_put(skb, len);

    sock_queue_rcv_skb(sk, skb);

    return;
}

static int dpa_sock_init_ctx(struct dpa_linux_sock_ctx *sock_ctx, int fd, struct sock *sk)
{
    int family = DPA_AF_INET;
    int prot_type = DPA_SOCK_DGRAM;

    if (sk->sk_family == AF_INET6) {
        family = DPA_AF_INET6;
    }
    prot_type = dpa_sock_get_prot_type(sk);
    if (prot_type < 0) {
        return -1;
    }
    sock_ctx->send_buf = kmalloc(DPA_SOCK_MAX_PACKER_SIZE, GFP_KERNEL);
    if (sock_ctx->send_buf == NULL) {
        printk("dpa_sock_init_ctx init send_buf fail\n");
        return -1;
    }
    sock_ctx->fd = fd;
    sock_ctx->sock_type = prot_type;
    sock_ctx->sock_family = family;
    (void)dpa_sock_register_event(fd, (void *)sk, dpa_sock_event_cb);

    return 0;
}

static int do_sock_create(struct sock *sk)
{
    int fd;
    int family = DPA_AF_INET;
    int prot_type = DPA_SOCK_DGRAM;
    int total_num;
    struct dpa_linux_sock_ctx *sock_ctx;

    sock_ctx = (struct dpa_linux_sock_ctx *)kzalloc(sizeof(struct dpa_linux_sock_ctx), GFP_KERNEL);
    if (sock_ctx == NULL) {
        printk("do_sock_pre_connect kmalloc fail\n");
        return -1;
    }

    /* bpf redirect just support AF_INET / AF_INET6 */
    if (sk->sk_family == AF_INET6) {
        family = DPA_AF_INET6;
    }

    prot_type = dpa_sock_get_prot_type(sk);
    if (prot_type < 0) {
        kfree((void *)sock_ctx);
        return -1;
    }

    fd = dpa_sock_create(family, prot_type);
    if (fd < 0) {
        printk("dpa_sock_create failed\n");
        kfree((void *)sock_ctx);
        return -1;
    }

    if (dpa_sock_init_ctx(sock_ctx, fd, sk) != 0) {
        printk("dpa_sock_init_ctx failed\n");
        dpa_sock_close(fd);
        if (sock_ctx->send_buf != NULL) {
            kfree(sock_ctx->send_buf);
        }
        kfree((void *)sock_ctx);
        return -1;
    }
    sk->sk_user_data = (void *)sock_ctx;
    total_num = atomic_inc_return(&g_dpa_sock_ref);
    printk("do_sock_create succ, sk:0x%llx, family(2:ipv4,10:ipv6):%d, prot_type(1:tcp,2:udp):%d, total_num:%d\n",
           (unsigned long long)sk, family, prot_type, total_num);

    return 0;
}

static int dpa_sock_resolve_dst(struct dpa_linux_sock_ctx *sock_ctx)
{
    struct net_device *linux_netdev;
    int ret;
    int idx;

    if (sock_ctx->dst_resolved) {
        return 0;
    }

    /* set static neigh */
    if (sock_ctx->sock_family == DPA_AF_INET) {
        linux_netdev = dpa_addr4_resolve(NULL, &sock_ctx->remote_addr4, sock_ctx->resolv_mac);
        if (linux_netdev == NULL) {
            printk("dpa_sock_resolve_dst dpa_addr4_resolve fail\n");
            return -1;
        }

    } else if (sock_ctx->sock_family == DPA_AF_INET6) {
        linux_netdev = dpa_addr6_resolve(NULL, &sock_ctx->remote_addr6, sock_ctx->resolv_mac);
        if (linux_netdev == NULL) {
            printk("dpa_sock_resolve_dst dpa_addr6_resolve fail\n");
            return -1;
        }
    } else {
        printk("dpa_sock_resolve_dst sock_family fail\n");
        return -1;
    }

    /* idx can be set to net_device */
    idx = dpa_netdev_get_by_ifindex(linux_netdev->ifindex);
    DPA_CFG_SNE_IFNAME(sock_ctx->dpa_netdev_name.if_name);
    ret = dpa_config_netdev(idx, linux_netdev->mtu);
    if (ret) {
        printk("dpa_sock_resolve_dst dpa_config_netdev fail:%d\n", ret);
        return -1;
    }
    sock_ctx->dev_mtu = linux_netdev->mtu;
    printk("dpa_sock_resolve_dst idx:%d, ifindex:%d, linux devname:%s, mtu:%d, dpa devname:%s, name_size:%d\n", idx,
           linux_netdev->ifindex, linux_netdev->name, linux_netdev->mtu, sock_ctx->dpa_netdev_name.if_name,
           sizeof(sock_ctx->dpa_netdev_name));

    /* set static neigh */
    if (sock_ctx->sock_family == DPA_AF_INET) {
        ret = dpa_add_static_arp_entry(idx, sock_ctx->remote_addr4.sin_addr.s_addr,
                                       (struct eth_addr *)sock_ctx->resolv_mac, 0);
    } else if (sock_ctx->sock_family == DPA_AF_INET6) {
        ret = dpa_add_static_nd6_entry((ip6_addr_t *)&(sock_ctx->remote_addr6.sin6_addr),
                                       (struct eth_addr *)sock_ctx->resolv_mac);
    }
    if (ret) {
        printk("dpa_sock_resolve_dst lwip_add_static_arp/nd6_entry fail:%d\n", ret);
        return -1;
    }

    /* set static out net interface to socket */
    ret = dpa_sock_setsockopt(sock_ctx->fd, DPA_SOL_SOCKET, DPA_SO_BINDTODEVICE, (void *)&sock_ctx->dpa_netdev_name,
                              sizeof(sock_ctx->dpa_netdev_name));
    if (ret) {
        printk("dpa_sock_resolve_dst setsockopt(SO_BINDTODEVICE) fail:%d\n", ret);
        return -1;
    }

    sock_ctx->dst_resolved = 1;
    return ret;
}

int do_sock_pre_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
    int ret = 0;

    if (sk->sk_user_data == NULL) {
        ret = do_sock_create(sk);
    }
    return ret;
}

int do_sock_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
    int ret;

#if DPA_SOCK_USE_DPA
    struct dpa_linux_sock_ctx *sock_ctx;
    struct dpa_sockaddr sock_addr;

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EBADF;
    }

    if (uaddr->sa_family == AF_INET) {
        struct sockaddr_in *linux_sockaddr = (struct sockaddr_in *)uaddr;
        struct dpa_lwip_sockaddr_in *sock_addr4 = (struct dpa_lwip_sockaddr_in *)&sock_addr;

        sock_addr4->sa_family = DPA_AF_INET;
        sock_addr4->port = linux_sockaddr->sin_port;
        memcpy(&sock_addr4->sin_addr, &linux_sockaddr->sin_addr, sizeof(linux_sockaddr->sin_addr));
        sock_ctx->remote_addr4 = *linux_sockaddr;
        sock_ctx->sock_family = DPA_AF_INET;
    } else if (uaddr->sa_family == AF_INET6) {
        struct sockaddr_in6 *linux_sockaddr6 = (struct sockaddr_in6 *)uaddr;
        struct dpa_lwip_sockaddr_in6 *sock_addr6 = (struct dpa_lwip_sockaddr_in6 *)&sock_addr;

        sock_addr6->sa_family = DPA_AF_INET6;
        sock_addr6->port = linux_sockaddr6->sin6_port;
        sock_addr6->sin6_flowinfo = linux_sockaddr6->sin6_flowinfo;
        sock_addr6->sin6_scope_id = linux_sockaddr6->sin6_scope_id;
        memcpy(sock_addr6->u8_addr, &linux_sockaddr6->sin6_addr, sizeof(linux_sockaddr6->sin6_addr));
        sock_ctx->remote_addr6 = *linux_sockaddr6;
        sock_ctx->sock_family = DPA_AF_INET6;
    } else {
        printk("do_sock_connect sa_family:%d not support\n", uaddr->sa_family);
        return -EINVAL;
    }

    ret = dpa_sock_resolve_dst(sock_ctx);
    if (ret) {
        printk("do_sock_connect resolve_dst error:%d\n", ret);
        return -EINVAL;
    }
    ret = dpa_sock_connect(sock_ctx->fd, &sock_addr, addr_len);
    if (ret) {
        printk("do_sock_connect error:%d\n", ret);
        return -EINVAL;
    }

    if (sock_ctx->sock_type == DPA_SOCK_STREAM) {
        /* update tcp sk_state for linux socket layer */
        sk->sk_state = TCP_ESTABLISHED;
    }
#else
    struct proto *base = dpa_sock_get_base_prot(sk);
    if (base == NULL) {
        return -1;
    }
    ret = base->connect(sk, uaddr, addr_len);
#endif

#if DPA_SOCK_PRINT_PARA
    if (uaddr->sa_family == AF_INET) {
        struct sockaddr_in *linux_sockaddr = (struct sockaddr_in *)uaddr;
        printk("dpa_sock connect sk:0x%llx, sk_type:%d, ipv4: %d.%d.%d.%d, port: %d\n", (unsigned long long)sk,
               sk->sk_type, (linux_sockaddr->sin_addr.s_addr & 0xFF), ((linux_sockaddr->sin_addr.s_addr >> 8) & 0xFF),
               ((linux_sockaddr->sin_addr.s_addr >> 16) & 0xFF), ((linux_sockaddr->sin_addr.s_addr >> 24) & 0xFF),
               ntohs(linux_sockaddr->sin_port));
    }
#endif

    return ret;
}

int do_sock_disconnect(struct sock *sk, int flags)
{
    int ret = 0;

#if DPA_SOCK_USE_DPA
    struct dpa_linux_sock_ctx *sock_ctx;

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EBADF;
    }

    if (sock_ctx->sock_type == DPA_SOCK_STREAM) {
        sk->sk_state = TCP_CLOSE;
    }
#else
    struct proto *base = dpa_sock_get_base_prot(sk);
    if (base == NULL) {
        return -1;
    }
    ret = base->disconnect(sk, flags);
#endif

#if DPA_SOCK_PRINT_PARA
    printk("dpa_sock disconnect sk:0x%llx, flags:0x%x\n", (unsigned long long)sk, flags);
#endif
    return ret;
}

static void dpa_sock_conv_value_for_setopt(int in_level, int in_optname, char *out_value, int *out_len, char *in_value)
{
    char *conv_value = in_value;
    int conv_len = sizeof(int);

    switch (in_level) {
        /* SOL_SOCKET proc in linux socket layer */
        case IPPROTO_IP:
        case IPPROTO_TCP:
        case IPPROTO_IPV6:
        case IPPROTO_UDPLITE:
        case IPPROTO_RAW:
        default:
            conv_len = sizeof(int);
            break;
    }

    *out_len = conv_len;
    memcpy(out_value, conv_value, conv_len);
    return;
}

int do_sock_setsockopt(struct sock *sk, int level, int optname, sockptr_t optval, unsigned int optlen)
{
    int ret;

#if DPA_SOCK_USE_DPA
    struct dpa_linux_sock_ctx *sock_ctx;
    int lwip_opt;
    int lwip_level;
    unsigned int conv_len;
    char linux_optval[DPA_SOCK_MAX_OPTVAL_SIZE];
    char lwip_optval[DPA_SOCK_MAX_OPTVAL_SIZE];

    if (optlen > DPA_SOCK_MAX_OPTVAL_SIZE) {
        return -EINVAL;
    }
    if (sk->sk_user_data == NULL) {
        ret = do_sock_create(sk);
        if (ret) {
            return -EINVAL;
        }
    }
    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EBADF;
    }

    ret = dpa_sock_conv_para_for_sockopt(level, &lwip_level, optname, &lwip_opt);
    if (ret) {
        printk("setsockopt dpa_sock_conv_para_for_sockopt error:%d\n", ret);
        return -EINVAL;
    }

    if (copy_from_sockptr((void *)linux_optval, optval, optlen)) {
        printk("do_sock_setsockopt copy_from_sockptr error:%d\n", ret);
        return -EINVAL;
    }

    /* do some sockopt impl just in linux */
    ret = dpa_sock_set_sockopt_prepare(sk, level, optname, linux_optval, optlen);
    if (ret <= 0) {
        return ret;
    }

    dpa_sock_conv_value_for_setopt(level, optname, lwip_optval, &conv_len, linux_optval);
    ret = dpa_sock_setsockopt(sock_ctx->fd, lwip_level, lwip_opt, (void *)lwip_optval, conv_len);
    if (ret) {
        printk("dpa_sock_setsockopt error:%d\n", ret);
        return -EINVAL;
    }
#else
    struct proto *base = dpa_sock_get_base_prot(sk);
    if (base == NULL) {
        return -1;
    }
    ret = base->setsockopt(sk, level, optname, optval, optlen);
#endif

#if DPA_SOCK_PRINT_PARA
    printk("dpa_sock setsockopt sk:0x%llx, level:%d, optname:%d, optlen:%d, ret:%d\n", (unsigned long long)sk, level,
           optname, optlen, ret);
#endif

    return ret;
}

static int dpa_sock_conv_flags_for_sendmsg(struct dpa_linux_sock_ctx *sock_ctx, struct dpa_msghdr *to,
                                           struct msghdr *from, struct dpa_sockaddr *sock_addr)
{
    int ret;

    /* convert msg_control */
    if (from->msg_controllen != 0) {
        printk("not support msg_controllen:%ld\n", from->msg_controllen);
        return -EINVAL;
    }
    to->msg_control = NULL;
    to->msg_controllen = 0;

    /* convert msg_name */
    if (from->msg_namelen != 0 && from->msg_name != NULL) {
        if (sock_ctx->sock_family == DPA_AF_INET) {
            struct dpa_lwip_sockaddr_in *sock_addr4 = (struct dpa_lwip_sockaddr_in *)sock_addr;
            DECLARE_SOCKADDR(struct sockaddr_in *, usin, from->msg_name);

            if (from->msg_namelen < sizeof(*usin)) {
                return -EINVAL;
            }
            sock_addr4->sin_addr = usin->sin_addr.s_addr;
            sock_addr4->port = usin->sin_port;
            sock_addr4->sa_family = DPA_AF_INET;
            sock_addr4->sa_len = sizeof(struct dpa_lwip_sockaddr_in);
            to->msg_name = sock_addr;
            to->msg_namelen = sizeof(struct dpa_lwip_sockaddr_in);
            sock_ctx->remote_addr4 = *usin;
        } else if (sock_ctx->sock_family == DPA_AF_INET6) {
            struct dpa_lwip_sockaddr_in6 *sock_addr6 = (struct dpa_lwip_sockaddr_in6 *)sock_addr;
            DECLARE_SOCKADDR(struct sockaddr_in6 *, sin6, from->msg_name);

            if (from->msg_namelen < DPA_SOCK_SIN6_LEN_RFC2133) {
                return -EINVAL;
            }
            memcpy(sock_addr6->u8_addr, &sin6->sin6_addr, sizeof(sock_addr6->u8_addr));
            sock_addr6->port = sin6->sin6_port;
            sock_addr6->sa_family = DPA_AF_INET6;
            sock_addr6->sin6_scope_id = sin6->sin6_scope_id;
            sock_addr6->sa_len = sizeof(struct dpa_lwip_sockaddr_in6);
            to->msg_name = sock_addr;
            to->msg_namelen = sizeof(struct dpa_lwip_sockaddr_in6);
            sock_ctx->remote_addr6 = *sin6;
        }
    } else {
        to->msg_name = NULL;
        to->msg_namelen = 0;
    }

    ret = dpa_sock_resolve_dst(sock_ctx);
    if (ret) {
        printk("sendmsg resolve_dst error:%d\n", ret);
        return -EINVAL;
    }
    /* convert msg_flags */
    to->msg_flags = 0;
    if (from->msg_flags & MSG_OOB) {
        to->msg_flags |= DPA_SOCK_MSG_OOB;
    }
    if (from->msg_flags & MSG_WAITALL) {
        to->msg_flags |= DPA_SOCK_MSG_WAITALL;
    }
    if (from->msg_flags & MSG_PEEK) {
        to->msg_flags |= DPA_SOCK_MSG_PEEK;
    }
    if (from->msg_flags & MSG_DONTWAIT) {
        to->msg_flags |= DPA_SOCK_MSG_DONTWAIT;
    }
    if (from->msg_flags & MSG_MORE) {
        to->msg_flags |= DPA_SOCK_MSG_MORE;
    }
    if (from->msg_flags &
        ~(unsigned int)(MSG_OOB | MSG_WAITALL | MSG_PEEK | MSG_DONTWAIT | MSG_MORE | MSG_CMSG_COMPAT | MSG_NOSIGNAL)) {
        printk("warning, sendmsg flags:0x%x not support\n", from->msg_flags);
    }
    to->msg_flags |= DPA_SOCK_MSG_ZEROCOPY;

    return 0;
}

static int dpa_sock_copy_msg_for_sendmsg(struct dpa_linux_sock_ctx *sock_ctx, struct dpa_msghdr *to,
                                         struct msghdr *from, struct dpa_sockaddr *sock_addr)
{
    int indx_msg = 0;
    int ret = 0;
    struct iov_iter *iov_from = &from->msg_iter;
    unsigned long long addr;
    unsigned int reserv_len = sizeof(struct ethhdr);
    unsigned int copy_len;
    int send_mtu = (sock_ctx->dev_mtu == 0) ? (DPA_SOCK_MIN_MTU) : (sock_ctx->dev_mtu);

    send_mtu += sizeof(struct ethhdr);
    if (sock_ctx->sock_family == DPA_AF_INET) {
        reserv_len += sizeof(struct iphdr);
    } else if (sock_ctx->sock_family == DPA_AF_INET6) {
        reserv_len += sizeof(struct ipv6hdr);
    }
    if (sock_ctx->sock_type == DPA_SOCK_DGRAM) {
        reserv_len += sizeof(struct udphdr);
    } else if (sock_ctx->sock_type == DPA_SOCK_STREAM) {
        reserv_len += (sizeof(struct tcphdr) + DPA_SOCK_TCP_OPTION_MAX);
    }

    /* convert msg_iov */
    do {
        unsigned char* virt_data;
        dra_buf_t dra_data;

        if (indx_msg >= DPA_SOCK_MAX_MSG_FRAGS) {
            printk("dpa_sock_copy_msg iov len too large:%d\n", indx_msg);
            /* send partial data */
            ret = 0;
            goto copy_msg_out;
        }
        addr = bsp_dra_alloc(DRA_OPIPE_LEVEL_1_SIZE);
        if (addr == 0) {
            ret = -1;
            printk("dpa_sock_copy_msg bsp_dra_alloc fail\n");
            goto copy_msg_out;
        }

        to->msg_iov[indx_msg].iov_base = addr + reserv_len;
        dra_data = (dra_buf_t)to->msg_iov[indx_msg].iov_base;
        virt_data = phys_to_virt(dra_data.bits.phyaddr);
        copy_len = (unsigned int)_copy_from_iter(virt_data, (size_t)(send_mtu - reserv_len), iov_from);
        to->msg_iov[indx_msg].iov_len = copy_len;
        to->msg_iov[indx_msg].iov_priv = addr;
        indx_msg++;

    } while (iov_from->count > 0);

copy_msg_out:
    to->msg_iovlen = indx_msg;
    return ret;
}

static void dpa_sock_msg_free_pkt(struct dpa_msghdr *lwip_msg)
{
    int i;
    unsigned long long addr;

    for (i = 0; i < lwip_msg->msg_iovlen; i++) {
        addr = lwip_msg->msg_iov[i].iov_priv;
        if (addr != NULL) {
            bsp_dra_free(addr);
        }
    }
    return;
}

int do_sock_sendmsg(struct sock *sk, struct msghdr *msg, size_t len)
{
    int ret;

#if DPA_SOCK_USE_DPA
    struct dpa_linux_sock_ctx *sock_ctx;
    struct dpa_msghdr lwip_msg;
    struct dpa_sockaddr sock_addr;

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (unlikely(sock_ctx == NULL)) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EBADF;
    }

    lwip_msg.msg_iov = sock_ctx->dpa_send_iov;
    lwip_msg.msg_iovlen = 0;
    ret = dpa_sock_conv_flags_for_sendmsg(sock_ctx, &lwip_msg, msg, &sock_addr);
    if (ret) {
        printk("do_sock_sendmsg conv_flags rslt:%d\n", ret);
        return ret;
    }
    ret = dpa_sock_copy_msg_for_sendmsg(sock_ctx, &lwip_msg, msg, &sock_addr);
    if (unlikely(ret < 0)) {
        dpa_sock_msg_free_pkt(&lwip_msg);
        printk("dpa_sock_copy_msg_for_sendmsg fd:%d, err:%d\n", sock_ctx->fd, ret);
        return -EFAULT;
    }

    ret = dpa_sock_sendmsg(sock_ctx->fd, sock_ctx->send_buf, DPA_SOCK_MAX_PACKER_SIZE, &lwip_msg, lwip_msg.msg_flags);
    if (unlikely(ret < 0)) {
        dpa_sock_msg_free_pkt(&lwip_msg);
        if (sk->sk_type == SOCK_STREAM) {
            (void)sk_stream_error(sk, msg->msg_flags, ret); /* for msg_flags: MSG_NOSIGNAL */
        }
        printk("dpa_sock_sendmsg err:%d\n", ret);
        return -EINVAL;
    }
#else
    struct proto *base = dpa_sock_get_base_prot(sk);
    if (base == NULL) {
        return -1;
    }
    ret = base->sendmsg(sk, msg, len);
#endif

#if DPA_SOCK_PRINT_PARA
    printk("do_sock_sendmsg sk_type:%d, len:%d, ret:%d, sk:0x%llx, msg_flags:0x%x\n", sk->sk_type, len, ret,
           (unsigned long long)sk, msg->msg_flags);
#endif

    return ret;
}

static int dpa_sock_conv_flags_for_recvmsg(int noblock, int flags)
{
    int lwip_flags = 0;

    lwip_flags |= noblock ? DPA_SOCK_MSG_DONTWAIT : 0;

    if (flags & MSG_DONTWAIT) {
        lwip_flags |= DPA_SOCK_MSG_DONTWAIT;
    }
    if (flags & MSG_PEEK) {
        lwip_flags |= DPA_SOCK_MSG_PEEK;
    }
    if (flags & ~(unsigned int)(MSG_DONTWAIT | MSG_PEEK | MSG_CMSG_COMPAT)) {
        printk("warning, recvmsg flags:0x%x not support\n", flags);
    }

    /* zero copy in dpa sock, copy to user in linux sock */
    return (lwip_flags | DPA_SOCK_MSG_ZEROCOPY);
}

static void dpa_sock_copy_msg_from_recvmsg(struct sock *sk, struct msghdr *to, struct dpa_msghdr *from)
{
#define MSG_IOVLEN_BITS 16
#define MSG_IOVLEN_MASK ((1 << MSG_IOVLEN_BITS) - 1)
    int i;
    struct iov_iter *iov_to = &to->msg_iter;
    int ret;
    int copy_len = 0;
    int recv_num;
    int total_num;

    recv_num = from->msg_iovlen >> MSG_IOVLEN_BITS;
    total_num = from->msg_iovlen & MSG_IOVLEN_MASK;
    if (unlikely(recv_num > total_num)) {
        printk("fatal err, recv_num:0x%x larger than total_num:%d\n", recv_num, total_num);
        return;
    }
    for (i = 0; i < recv_num; i++) {
        ret = (int)_copy_to_iter(from->msg_iov[i].iov_base, from->msg_iov[i].iov_len, iov_to);
        if (ret == 0) {
            printk("fatal err, recvmsg copy_to_iter error\n");
            break;
        }
        if (from->msg_iov[i].iov_priv != 0) {
            struct sk_buff *skb = skb_dequeue(&sk->sk_receive_queue);
            if (skb != NULL) {
                dev_kfree_skb_any(skb);
            }
        }
        copy_len += ret;
    }
    return;
}

int do_sock_recvmsg(struct sock *sk, struct msghdr *msg, size_t len, int noblock, int flags, int *addr_len)
{
    int ret;

#if DPA_SOCK_USE_DPA
    struct dpa_linux_sock_ctx *sock_ctx;
    struct dpa_msghdr lwip_msg;
    struct dpa_msghdr lwip_msg_wrap;
    struct dpa_iovec lwip_iov_wrap[1];
    struct dpa_sockaddr sock_addr;
    int lwip_flags;

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EINVAL;
    }

    if (skb_queue_empty_lockless(&sk->sk_receive_queue)) {
        if (noblock) {
            return -EAGAIN;
        } else {
            sock_ctx->is_recv_block = 1;
        }
    }

    lwip_msg_wrap.msg_iov = (void *)lwip_iov_wrap;
    lwip_msg_wrap.msg_iovlen = 1;
    lwip_iov_wrap[0].iov_base = (void *)&lwip_msg;
    lwip_iov_wrap[0].iov_len = msg->msg_iter.count;
    lwip_msg_wrap.msg_name = &sock_addr;
    lwip_msg_wrap.msg_namelen = sizeof(sock_addr);
    lwip_msg.msg_iov = sock_ctx->dpa_recv_iov;
    lwip_msg.msg_iovlen = DPA_SOCK_MAX_MSG_FRAGS;

    lwip_flags = dpa_sock_conv_flags_for_recvmsg(noblock, flags);

    /* recv msg from dpa stack */
    ret = dpa_sock_recvmsg(sock_ctx->fd, (void *)&lwip_msg_wrap, lwip_flags);
    if (unlikely(ret < 0)) {
        if (ret == DPA_SOCK_ERRNO_EAGAIN) {
            /* errno: DPA_SOCK_ERRNO_EAGAIN in lwip is EAGAIN */
            ret = -EAGAIN;
        }
    } else {
        /* copy lwip msg to linux usr space */
        dpa_sock_copy_msg_from_recvmsg(sk, msg, &lwip_msg);
        dpa_sock_recvmsg_end(sock_ctx->fd, (void *)&lwip_msg, lwip_flags);
    }

    if (msg->msg_name != NULL) {
        if (sock_ctx->sock_family == DPA_AF_INET) {
            struct dpa_lwip_sockaddr_in *sock_addr4 = (struct dpa_lwip_sockaddr_in *)&sock_addr;
            DECLARE_SOCKADDR(struct sockaddr_in *, sin, msg->msg_name);
            sin->sin_family = AF_INET;
            sin->sin_port = sock_addr4->port;
            sin->sin_addr.s_addr = sock_addr4->sin_addr;
            memset(sin->sin_zero, 0, sizeof(sin->sin_zero));
            *addr_len = sizeof(*sin);
        } else if (sock_ctx->sock_family == DPA_AF_INET6) {
            struct dpa_lwip_sockaddr_in6 *sock_addr6 = (struct dpa_lwip_sockaddr_in6 *)&sock_addr;
            DECLARE_SOCKADDR(struct sockaddr_in6 *, sin6, msg->msg_name);
            sin6->sin6_family = AF_INET6;
            sin6->sin6_port = sock_addr6->port;
            sin6->sin6_flowinfo = sock_addr6->sin6_flowinfo;
            sin6->sin6_scope_id = sock_addr6->sin6_scope_id;
            memcpy(&sin6->sin6_addr, sock_addr6->u8_addr, sizeof(sock_addr6->u8_addr));
            *addr_len = sizeof(*sin6);
        }
    }
#else
    struct proto *base = dpa_sock_get_base_prot(sk);
    if (base == NULL) {
        return -1;
    }
    ret = base->recvmsg(sk, msg, len, noblock, flags, addr_len);
#endif

#if DPA_SOCK_PRINT_PARA
    printk("do_sock_recvmsg sk_type:%d, len: %d, ret:%d, sk:0x%llx, msg_flags:0x%x, flags:0x%x,\n", sk->sk_type, len,
           ret, (unsigned long long)sk, msg->msg_flags, flags);
#endif

    return ret;
}

struct sk_buff *do_skb_recv(struct sock *sk, unsigned int flags, int noblock, int *off, int *err)
{
    struct sk_buff_head *sk_queue = &sk->sk_receive_queue;
    struct sk_buff *last;
    long timeo;
    int error;

    flags |= noblock ? MSG_DONTWAIT : 0;
    timeo = sock_rcvtimeo(sk, flags & MSG_DONTWAIT);
    do {
        struct sk_buff *skb;

        error = sock_error(sk);
        if (error)
            break;

        error = -EAGAIN;
        do {
            skb = __skb_try_recv_datagram(sk, sk_queue, flags, off, err, &last);
            if (skb)
                return skb;
        } while (!skb_queue_empty_lockless(sk_queue));

        /* sk_queue is empty, reader_queue may contain peeked packets */
    } while (timeo &&
             !__skb_wait_for_more_packets(sk, &sk->sk_receive_queue, &error, &timeo, (struct sk_buff *)sk_queue));

    *err = error;
    return NULL;
}

int do_udp_recvmsg(struct sock *sk, struct msghdr *msg, size_t len, int noblock, int flags, int *addr_len)
{
    DECLARE_SOCKADDR(struct sockaddr_in *, sin, msg->msg_name);
    struct sk_buff *skb;
    unsigned int copied;
    int off, err, peeking = flags & MSG_PEEK;

    off = sk_peek_offset(sk, flags);
    skb = do_skb_recv(sk, flags, noblock, &off, &err);
    if (!skb) {
        printk("skb null, err:%d\n", err);
        return err;
    }

    copied = skb->len;
    err = skb_copy_datagram_msg(skb, 0, msg, copied);
    if (unlikely(err)) {
        atomic_inc(&sk->sk_drops);
        UDP_INC_STATS(sock_net(sk), UDP_MIB_INERRORS, 0);
        kfree_skb(skb);
        return err;
    }

    sock_recv_ts_and_drops(msg, sk, skb);

    if (sin) {
        // sin->sin_family = AF_INET;
        // sin->sin_port = udp_hdr(skb)->source;
        // sin->sin_addr.s_addr = ip_hdr(skb)->saddr;
        // memset(sin->sin_zero, 0, sizeof(sin->sin_zero));
        // *addr_len = sizeof(*sin);
        *addr_len = 0;
    }

    skb_consume_udp(sk, skb, peeking ? -copied : copied);

    return copied;
}

int do_tcp_recvmsg(struct sock *sk, struct msghdr *msg, size_t len, int noblock, int flags, int *addr_len)
{
    struct sk_buff *skb;
    unsigned int copied;
    int off, err, peeking = flags & MSG_PEEK;

    off = sk_peek_offset(sk, flags);
    skb = do_skb_recv(sk, flags, noblock, &off, &err);
    if (!skb)
        return err;

    copied = skb->len;
    err = skb_copy_datagram_msg(skb, 0, msg, copied);
    if (unlikely(err)) {
        atomic_inc(&sk->sk_drops);
        UDP_INC_STATS(sock_net(sk), UDP_MIB_INERRORS, 0);
        kfree_skb(skb);
        return err;
    }

    sock_recv_ts_and_drops(msg, sk, skb);
    skb_consume_udp(sk, skb, peeking ? -copied : copied);
    return copied;
}

int do_sock_sendpage(struct sock *sk, struct page *page, int offset, size_t size, int flags)
{
    printk("do_sock_sendpage not support\n");
    return -1;
}

static int dpa_sock_get_sockopt_prepare(struct sock *sk, int in_level, int in_optname, char *out_value, int *out_len)
{
    struct inet_sock *inet = inet_sk(sk);
    int conv_len = 0;
    int conv_value = sizeof(conv_value);

    switch (in_level) {
        /* SOL_SOCKET proc in linux socket layer */
        case IPPROTO_IP:
            switch (in_optname) {
                case IP_MTU_DISCOVER:
                    conv_value = inet->pmtudisc;
                    break;
                case IP_RECVERR:
                    conv_value = inet->recverr;
                    break;
                case IP_RECVTTL:
                    conv_value = (inet->cmsg_flags & IP_CMSG_TTL) != 0;
                    break;
                case IP_RECVTOS:
                    conv_value = (inet->cmsg_flags & IP_CMSG_TOS) != 0;
                    break;
                default:
                    return 1;
            } /* switch (in_optname) */
            break;
    }

    if (copy_to_user(out_len, &conv_len, sizeof(int))) {
        printk("dpa_sock_conv_value_for_getopt copy_to_user len fail\n");
        return 0;
    }
    if (copy_to_user(out_value, &conv_value, conv_len)) {
        printk("dpa_sock_conv_value_for_getopt copy_to_user value fail\n");
        return 0;
    }

    return 0;
}

static int dpa_sock_set_sockopt_prepare(struct sock *sk, int in_level, int in_optname, char *in_value, int in_len)
{
    struct inet_sock *inet = inet_sk(sk);
    int value = *(int *)in_value;

    switch (in_level) {
        /* SOL_SOCKET proc in linux socket layer */
        case IPPROTO_IP:
            switch (in_optname) {
                case IP_MTU_DISCOVER:
                    /* IP_PMTUDISC_DONT/IP_PMTUDISC_WANT/IP_PMTUDISC_DO/IP_PMTUDISC_PROBE/IP_PMTUDISC_INTERFACE */
                    if (value < IP_PMTUDISC_DONT || value > IP_PMTUDISC_OMIT) {
                        return -EINVAL;
                    }
                    inet->pmtudisc = value;
                    printk("dpa_sock_set_sockopt IPPROTO_IP: IP_MTU_DISCOVER: %d\n", value);
                    break;
                case IP_RECVERR:
                    inet->recverr = !!value;
                    break;
                case IP_RECVTTL:
                    if (value)
                        inet->cmsg_flags |= IP_CMSG_TTL;
                    else
                        inet->cmsg_flags &= ~IP_CMSG_TTL;
                    break;
                case IP_RECVTOS:
                    if (value)
                        inet->cmsg_flags |= IP_CMSG_TOS;
                    else
                        inet->cmsg_flags &= ~IP_CMSG_TOS;
                    break;
                default:
                    return 1;
            } /* switch (in_optname) */
            break;
    }

    return 0;
}

static int dpa_sock_conv_para_for_sockopt(int in_level, int *out_level, int in_optname, int *out_optname)
{
    *out_level = in_level; /* almost the level is same value */

    switch (in_level) {
        /* SOL_SOCKET proc in linux socket layer */
        case IPPROTO_IP:
            switch (in_optname) {
                case IP_MTU_DISCOVER:
                case IP_RECVERR:
                case IP_RECVTTL:
                case IP_RECVTOS:
                    /* do nothing: process in set_sockopt_prepare */
                    break;
                case IP_TTL:
                case IP_TOS:
                case IP_MULTICAST_TTL:
                case IP_MULTICAST_IF:
                case IP_MULTICAST_LOOP:
                default:
                    printk("sockopt not support level:%d, optname:%d\n", in_level, in_optname);
                    return -1;
            } /* switch (in_optname) */
            break;
        case IPPROTO_TCP:
            switch (in_optname) {
                case TCP_NODELAY:
                    *out_optname = DPA_SOCK_TCP_NODELAY;
                    break;
#if 0
        case TCP_KEEPALIVE:
            *out_optname = DPA_SOCK_TCP_KEEPALIVE;
            break;
#endif
                case TCP_KEEPIDLE:
                    *out_optname = DPA_SOCK_TCP_KEEPIDLE;
                    break;
                case TCP_KEEPINTVL:
                    *out_optname = DPA_SOCK_TCP_KEEPINTVL;
                    break;
                case TCP_KEEPCNT:
                    *out_optname = DPA_SOCK_TCP_KEEPCNT;
                    break;
                case TCP_MAXSEG:
                    *out_optname = DPA_SOCK_TCP_MAXSEG;
                    break;
                default:
                    printk("sockopt not support level:%d, optname:%d\n", in_level, in_optname);
                    return -1;
            } /* switch (in_optname) */
            break;
        case IPPROTO_IPV6:
            switch (in_optname) {
                case IPV6_CHECKSUM:
                    *out_optname = DPA_SOCK_IPV6_CHECKSUM;
                    break;
                case IPV6_V6ONLY:
                    *out_optname = DPA_SOCK_IPV6_V6ONLY;
                    break;
                case IPV6_TCLASS:
                    *out_optname = DPA_SOCK_IPV6_TCLASS;
                    break;
                default:
                    printk("sockopt not support level:%d, optname:%d\n", in_level, in_optname);
                    return -1;
            } /* switch (in_optname) */
            break;
        case IPPROTO_UDPLITE:
        case IPPROTO_RAW:
        default:
            printk("sockopt not support level:%d, optname:%d\n", in_level, in_optname);
            return -1;
    }
    return 0;
}

static int dpa_sock_conv_value_for_getopt(int in_level, int in_optname, char *out_value, int *out_len, char *in_value)
{
    char *conv_value = in_value;
    int conv_len = sizeof(int);

    switch (in_level) {
        /* SOL_SOCKET proc in linux socket layer */
        case IPPROTO_IP:
        case IPPROTO_TCP:
        case IPPROTO_IPV6:
        case IPPROTO_UDPLITE:
        case IPPROTO_RAW:
        default:
            conv_len = sizeof(int);
            break;
    }

    if (copy_to_user(out_len, &conv_len, sizeof(int))) {
        printk("dpa_sock_conv_value_for_getopt copy_to_user len fail\n");
        return -EFAULT;
    }
    if (copy_to_user(out_value, &conv_value, conv_len)) {
        printk("dpa_sock_conv_value_for_getopt copy_to_user value fail\n");
        return -EFAULT;
    }
    return 0;
}

int do_sock_getsockopt(struct sock *sk, int level, int optname, char __user *optval, int __user *optlen)
{
    int ret;

#if DPA_SOCK_USE_DPA
    char lwip_optval[DPA_SOCK_MAX_OPTVAL_SIZE];
    struct dpa_linux_sock_ctx *sock_ctx;
    int lwip_level;
    int lwip_optname;
    int lwip_optlen = sizeof(lwip_optval);

    if (sk->sk_user_data == NULL) {
        ret = do_sock_create(sk);
        if (ret) {
            return -EINVAL;
        }
    }

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EINVAL;
    }

    ret = dpa_sock_get_sockopt_prepare(sk, level, optname, optval, optlen);
    if (ret == 0) {
        return 0;
    }

    ret = dpa_sock_conv_para_for_sockopt(level, &lwip_level, optname, &lwip_optname);
    if (ret) {
        printk("getsockopt dpa_sock_conv_para_for_sockopt error:%d\n", ret);
        return -EINVAL;
    }
    ret = dpa_sock_getsockopt(sock_ctx->fd, lwip_level, lwip_optname, lwip_optval, &lwip_optlen);
    if (ret) {
        printk("dpa_sock_getsockopt error:%d\n", ret);
        return -EINVAL;
    }
    ret = dpa_sock_conv_value_for_getopt(level, optname, optval, optlen, lwip_optval);
    if (ret) {
        return -EINVAL;
    }
#else
    struct proto *base = dpa_sock_get_base_prot(sk);
    if (base == NULL) {
        return -1;
    }
    ret = base->getsockopt(sk, level, optname, optval, optlen);
#endif

#if DPA_SOCK_PRINT_PARA
    printk("dpa_sock getsockopt sk:0x%llx, level:%d, optname:%d, ret:%d\n", (unsigned long long)sk, level, optname,
           ret);
#endif
    return ret;
}

/* input: conv arg for linux -> lwip */
int dpa_sock_conv_for_ioctl_input(int in_cmd, int *out_cmd, void *in_arg, char *out_arg)
{
    switch (in_cmd) {
        case FIONREAD:
            *out_cmd = DPA_SOCK_FIONREAD;
            /* output para */
            break;
        case FIONBIO:
            *out_cmd = DPA_SOCK_FIONBIO;
            /* input para */
            if (copy_from_user((void *)out_arg, (void *)in_arg, sizeof(int))) {
                printk("copy_from_user fail:%d\n", __LINE__);
                return -EFAULT;
            }
            break;
        case SIOCATMARK:
        case SIOCOUTQ:
        case SIOCOUTQNSD:
            printk("dpa_sock tcp/udp ioctl cmd:0x%x not support\n", in_cmd);
            return -ENOTSUPP;
        default:
            /* process in other layer */
            return -ENOIOCTLCMD;
    }
    return 0;
}

/* input: conv arg for lwip -> linux */
int dpa_sock_conv_for_ioctl_output(int in_cmd, void *in_arg, void *out_arg)
{
    switch (in_cmd) {
        case FIONREAD:
            /* output para */
            if (copy_to_user(out_arg, in_arg, sizeof(int))) {
                printk("copy_to_user fail:%d\n", __LINE__);
                return -EFAULT;
            }
            break;
        case FIONBIO:
            /* input para */
            break;
        default:
            printk("sock ioctl cmd:0x%x not support\n", in_cmd);
            return -ENOTSUPP;
    }
    return 0;
}

int do_sock_ioctl(struct sock *sk, int cmd, unsigned long arg)
{
    struct dpa_linux_sock_ctx *sock_ctx;
    int ret;
    int lwip_cmd;
    char lwip_arg[DPA_SOCK_MAX_IOCTL_ARG_SIZE];

    if (sk->sk_user_data == NULL) {
        ret = do_sock_create(sk);
        if (ret) {
            return -EINVAL;
        }
    }
    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EBADF;
    }
    ret = dpa_sock_conv_for_ioctl_input(cmd, &lwip_cmd, (void *)arg, lwip_arg);
    if (ret) {
        return -EINVAL;
    }
    ret = dpa_sock_ioctl(sock_ctx->fd, lwip_cmd, (void *)lwip_arg);
    if (ret) {
        printk("dpa_sock_ioctl error:%d\n", ret);
        return -EINVAL;
    }
    ret = dpa_sock_conv_for_ioctl_output(cmd, lwip_arg, (void *)arg);
    if (ret) {
        return -EINVAL;
    }
    return 0;
}

int do_sock_bind(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
    struct dpa_linux_sock_ctx *sock_ctx;
    struct sockaddr_in *addr_linux = (struct sockaddr_in *)uaddr;
    struct dpa_sockaddr sock_addr;
    int ret = -1;

    if (addr_len < sizeof(struct sockaddr_in)) {
        return -EINVAL;
    }

    if (sk->sk_user_data == NULL) {
        ret = do_sock_create(sk);
        if (ret) {
            return -EINVAL;
        }
    }
    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;

    /* set socket opt value for linux */
    (void)dpa_sock_set_socket_opt(sk, sock_ctx);

    if (uaddr->sa_family == AF_INET) {
        struct dpa_lwip_sockaddr_in *sock_addr4 = (struct dpa_lwip_sockaddr_in *)&sock_addr;
        sock_addr4->sin_addr = addr_linux->sin_addr.s_addr;
        sock_addr4->port = addr_linux->sin_port;
        sock_addr4->sa_family = DPA_AF_INET;
        sock_addr4->sa_len = sizeof(struct dpa_lwip_sockaddr_in);
        sock_ctx->sock_family = DPA_AF_INET;
        ret = dpa_sock_bind(sock_ctx->fd, (struct dpa_sockaddr *)sock_addr4, sock_addr4->sa_len);
        if (ret) {
            printk("dpa_sock_bind error:%d\n", ret);
            return -EINVAL;
        }
    } else if (uaddr->sa_family == AF_INET6) {
        struct dpa_lwip_sockaddr_in6 *sock_addr6 = (struct dpa_lwip_sockaddr_in6 *)&sock_addr;
        struct sockaddr_in6 *addr6_linux = (struct sockaddr_in6 *)uaddr;
        sock_addr6->port = addr6_linux->sin6_port;
        sock_addr6->sin6_flowinfo = addr6_linux->sin6_flowinfo;
        sock_addr6->sa_family = DPA_AF_INET6;
        sock_addr6->sa_len = sizeof(struct dpa_lwip_sockaddr_in6);
        sock_addr6->sin6_scope_id = addr6_linux->sin6_scope_id;
        sock_ctx->sock_family = DPA_AF_INET6;
        memcpy(sock_addr6->u8_addr, &addr6_linux->sin6_addr, sizeof(addr6_linux->sin6_addr));
        ret = dpa_sock_bind(sock_ctx->fd, (struct dpa_sockaddr *)sock_addr6, sock_addr6->sa_len);
        if (ret) {
            printk("dpa_sock_bind error:%d\n", ret);
            return -EINVAL;
        }
    }

    return 0;
}

void do_sock_close(struct sock *sk, long timeout)
{
#if DPA_SOCK_USE_DPA
    struct dpa_linux_sock_ctx *sock_ctx;
    int ret;
    int fd = -1;

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        goto out;
    }

    if (sock_ctx->sock_type == DPA_SOCK_STREAM) {
        sk->sk_state = TCP_CLOSE;
    }

    if (sock_ctx->dst_resolved) {
        (void)dpa_del_static_arp_entry(sock_ctx->remote_addr4.sin_addr.s_addr);
        sock_ctx->dst_resolved = 0;
    }

    fd = sock_ctx->fd;

    ret = dpa_sock_close(fd);
    if (ret) {
        printk("dpa_sock_close error:%d\n", ret);
    }
    dpa_sock_cleanup_recv_queue(sk);

    sk->sk_user_data = NULL;
    atomic_dec(&g_dpa_sock_ref);
    if (sock_ctx->send_buf != NULL) {
        kfree(sock_ctx->send_buf);
    }
    kfree((void *)sock_ctx);

out:
    /* call linux udp_lib_close */
    sk_common_release(sk);
#else
    struct proto *base = dpa_sock_get_base_prot(sk);
    if (base == NULL) {
        return;
    }
    atomic_dec(&g_dpa_sock_ref);
    base->close(sk, timeout);
#endif

#if DPA_SOCK_PRINT_PARA
    printk("do_sock_close sk:0x%llx\n", (unsigned long long)sk);
#endif

    return;
}

int dpa_sock_tcp_get_port(struct sock *sk, unsigned short snum)
{
    int ret;
    struct dpa_linux_sock_ctx *sock_ctx;

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return -EBADF;
    }

    if (sk->sk_state == TCP_LISTEN && sock_ctx->sock_state == 0) {
        unsigned int backlog;

        backlog = READ_ONCE(sk->sk_max_ack_backlog);
        printk("dpa_sock_listen fd:%d\n", sock_ctx->fd);
        ret = dpa_sock_listen(sock_ctx->fd, backlog);
        if (ret) {
            printk("dpa_sock_listen error:%d\n", ret);
            return -EINVAL;
        }
        sock_ctx->sock_state = TCP_LISTEN;
    }
    ret = inet_csk_get_port(sk, snum);
    return ret;
}

static void dpa_sock_init_inet_sk(struct sock *sk)
{
    struct inet_connection_sock *icsk = inet_csk(sk);

    icsk->icsk_bind_hash = NULL;
    return;
}

struct sock *dpa_sock_tcp_accept(struct sock *sk, int flags, int *err, bool kern)
{
    int new_fd;
    unsigned int addrlen_ret;
    struct sock *new_sock;
    struct dpa_sockaddr addr_ret;
    struct dpa_linux_sock_ctx *sock_ctx;
    struct dpa_linux_sock_ctx *new_sock_ctx;

    sock_ctx = (struct dpa_linux_sock_ctx *)sk->sk_user_data;
    if (sock_ctx == NULL) {
        printk("invalid sock context line:%d\n", __LINE__);
        return NULL;
    }

    new_sock_ctx = (struct dpa_linux_sock_ctx *)kzalloc(sizeof(struct dpa_linux_sock_ctx), GFP_KERNEL);
    if (new_sock_ctx == NULL) {
        printk("dpa_sock_tcp_accept kmalloc fail\n");
        return NULL;
    }

    addrlen_ret = sizeof(addr_ret);
    new_fd = dpa_sock_accept(sock_ctx->fd, &addr_ret, &addrlen_ret);
    if (new_fd < 0) {
        printk("dpa_sock_accept error:%d\n", new_fd);
        kfree((void *)new_sock_ctx);
        return NULL;
    }

    new_sock = sk_clone_lock(sk, GFP_KERNEL);
    if (new_sock != NULL) {
        struct inet_sock *inet = inet_sk(new_sock);

        if (dpa_sock_init_ctx(new_sock_ctx, new_fd, new_sock) != 0) {
            printk("dpa_sock_init_ctx in accept failed\n");
            dpa_sock_close(new_fd);
            if (new_sock_ctx->send_buf != NULL) {
                kfree(new_sock_ctx->send_buf);
            }
            kfree((void *)new_sock_ctx);
            bh_unlock_sock(new_sock);
            return NULL;
        }
        if (addr_ret.sa_family == AF_INET) {
            struct dpa_lwip_sockaddr_in *sock_addr4 = (struct dpa_lwip_sockaddr_in *)&addr_ret;
            inet->inet_dport = sock_addr4->port;
            inet->inet_daddr = sock_addr4->sin_addr;
            new_sock->sk_state = TCP_ESTABLISHED;
            new_sock->sk_user_data = (void *)new_sock_ctx;
            dpa_sock_init_inet_sk(new_sock);
            /* bh_lock in sk_clone_lock */
            bh_unlock_sock(new_sock);

            new_sock_ctx->remote_addr4.sin_addr.s_addr = sock_addr4->sin_addr;
            new_sock_ctx->remote_addr4.sin_family = AF_INET;
            new_sock_ctx->remote_addr4.sin_port = sock_addr4->port;
            printk("dpa_sock_tcp_accept inet ipv4 %d.%d.%d.%d : %d\n", (inet->inet_daddr & 0xFF),
                   ((inet->inet_daddr >> 8) & 0xFF), ((inet->inet_daddr >> 16) & 0xFF),
                   ((inet->inet_daddr >> 24) & 0xFF), ntohs(inet->inet_dport));
        } else if (addr_ret.sa_family == AF_INET6) {
            struct dpa_lwip_sockaddr_in6 *sock_addr6 = (struct dpa_lwip_sockaddr_in6 *)&addr_ret;
            inet->inet_dport = sock_addr6->port;
            memcpy(&inet->sk.sk_v6_daddr, sock_addr6->u8_addr, sizeof(sock_addr6->u8_addr));
            new_sock->sk_state = TCP_ESTABLISHED;

            new_sock->sk_user_data = (void *)new_sock_ctx;
            dpa_sock_init_inet_sk(new_sock);
            /* bh_lock in sk_clone_lock */
            bh_unlock_sock(new_sock);
            printk("dpa_sock_tcp_accept inet ipv6, port: %d\n", ntohs(inet->inet_dport));
        }
        atomic_inc_return(&g_dpa_sock_ref);
    }

    return new_sock;
}

static bool dpa_sock_stream_data_ready(const struct sock *sk)
{
    if (!skb_queue_empty_lockless(&sk->sk_receive_queue)) {
        return true;
    }
    return false;
}

static void dpa_sock_bpf_rebuild_protos(struct proto *prot, const struct proto *base, int sock_family, int prot_type)
{
    *prot = *base;

#if DPA_SOCK_USE_DPA
    /* common proto setting */
    prot->pre_connect = do_sock_pre_connect;
    prot->connect = do_sock_connect;
    prot->disconnect = do_sock_disconnect;
    prot->bind = do_sock_bind;

    prot->setsockopt = do_sock_setsockopt;
    prot->getsockopt = do_sock_getsockopt;

    prot->sendmsg = do_sock_sendmsg;
    prot->sendpage = do_sock_sendpage;

    prot->ioctl = do_sock_ioctl;
    prot->close = do_sock_close;

    /* tcp proto only */
    if (prot_type == DPA_SOCK_STREAM) {
        prot->get_port = dpa_sock_tcp_get_port;
        prot->accept = dpa_sock_tcp_accept;
        prot->stream_memory_read = dpa_sock_stream_data_ready;
        prot->recvmsg = do_tcp_recvmsg;
    } else {
        prot->recvmsg = do_udp_recvmsg;
    }
#else
    if (prot_type == DPA_SOCK_STREAM) {
        dpa_tcp_base_prots[sock_family] = *base;
    } else if (prot_type == DPA_SOCK_DGRAM) {
        dpa_udp_base_prots[sock_family] = *base;
    }

    /* must add tracing functions in following cb */
    prot->connect = do_sock_connect;
    prot->disconnect = do_sock_disconnect;
    prot->sendmsg = do_sock_sendmsg;
    prot->recvmsg = do_sock_recvmsg;
    prot->setsockopt = do_sock_setsockopt;
    prot->getsockopt = do_sock_getsockopt;
    prot->close = do_sock_close;
#endif

    return;
}

static int dpa_wan_bpf_v4_build_proto(void)
{
    dpa_sock_bpf_rebuild_protos(&dpa_udp_bpf_prots[DPA_SOCK_BPF_IPV4], &udp_prot, DPA_SOCK_BPF_IPV4, DPA_SOCK_DGRAM);
    dpa_sock_bpf_rebuild_protos(&dpa_tcp_bpf_prots[DPA_SOCK_BPF_IPV4], &tcp_prot, DPA_SOCK_BPF_IPV4, DPA_SOCK_STREAM);
    return 0;
}

static int dpa_wan_bpf_v6_build_proto(void)
{
#if !DPA_SOCK_IPV4_ONLY
    dpa_sock_bpf_rebuild_protos(&dpa_udp_bpf_prots[DPA_SOCK_BPF_IPV6], &udpv6_prot, DPA_SOCK_BPF_IPV6, DPA_SOCK_DGRAM);
    dpa_sock_bpf_rebuild_protos(&dpa_tcp_bpf_prots[DPA_SOCK_BPF_IPV6], &tcpv6_prot, DPA_SOCK_BPF_IPV6, DPA_SOCK_STREAM);
#endif
    return 0;
}

int dpa_net_init(void)
{
    atomic_set(&g_dpa_sock_ref, 0);
    dpa_wan_bpf_v4_build_proto();
    dpa_wan_bpf_v6_build_proto();
    sock_offload_func_register((void *)dpa_sock_offload);

    dpa_netdev_event_init();
    printk("dpa_net_init ok\n");
    return 0;
}
