#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/net.h>
#include <linux/skbuff.h>
#include <net/sock.h>
#include <net/udp.h>
#include <net/tcp.h>
#include <bsp_dra.h>
#include "client.h"

int test_dpa_sock_create(void)
{
    int fd = dpa_sock_create(AF_INET, SOCK_STREAM);
    printk("dpa_sock_create, return fd = %d\n", fd);
    return fd;
}

int test_dpa_sock_close(void)
{
    int ret = dpa_sock_close(38);
    printk("dpa_sock_close, return ret = %d\n", ret);
    return ret;
}

const char *text = "Hello, world!";

static void test_event_cb(void* priv, unsigned char *data, unsigned int len)
{
    const char *str = (const char *)priv;
    printk("test_event_cb:%s\n", str);
}

int test_dpa_sock_register_event(void)
{
    int ret = dpa_sock_register_event(38, (void *)text, (void *)test_event_cb);
    printk("dpa_sock_register_event, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_connect(void)
{
    struct dpa_sockaddr name;
    name.sa_len = 4;
    name.sa_family = AF_INET;
    name.sa_data[0] = 192;
    name.sa_data[1] = 168;
    name.sa_data[2] = 1;
    name.sa_data[3] = 100;
    int ret = dpa_sock_connect(38, &name, 6);
    printk("dpa_sock_connect, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_setsockopt(void)
{
    int val = 123;
    int ret = dpa_sock_setsockopt(38, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    printk("dpa_sock_setsockopt, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_sendmsg(void)
{
    struct dpa_msghdr message;
    struct dpa_sockaddr name;
    unsigned long long addr;
    struct sk_buff *skb;
    struct dpa_iovec iov;

    name.sa_len = 4;
    name.sa_family = AF_INET;
    name.sa_data[0] = 192;
    name.sa_data[1] = 168;
    name.sa_data[2] = 1;
    name.sa_data[3] = 100;

    addr = bsp_dra_alloc(DRA_OPIPE_LEVEL_1_SIZE);
    skb = bsp_dra_get_skb(addr);
    if (skb == NULL) {
        printk("dpa_sock_copy_msg alloc pkt fail\n");
        return -1;
    }

    skb_reserve(skb, 40);
    skb_put(skb, 1024);

    iov.iov_base = addr + 40;
    iov.iov_len = 1024;
    iov.iov_priv = (void *)skb;

    message.msg_name = &name;
    message.msg_namelen = sizeof(name);
    message.msg_iov = &iov;
    message.msg_iovlen = sizeof(iov);
    message.msg_control = NULL;
    message.msg_controllen = 0;
    message.msg_flags = 0xdeadbeef;
    int ret = dpa_sock_sendmsg(38, NULL, 0, &message, 0);
    printk("dpa_sock_sendmsg, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_recvmsg(void)
{
    struct dpa_msghdr message;
    struct dpa_sockaddr name;
    unsigned long long addr;
    struct sk_buff *skb;
    struct dpa_iovec iov;

    name.sa_len = 4;
    name.sa_family = AF_INET;
    name.sa_data[0] = 192;
    name.sa_data[1] = 168;
    name.sa_data[2] = 1;
    name.sa_data[3] = 100;

    addr = bsp_dra_alloc(DRA_OPIPE_LEVEL_1_SIZE);
    skb = bsp_dra_get_skb(addr);
    if (skb == NULL) {
        printk("dpa_sock_copy_msg alloc pkt fail\n");
        return -1;
    }

    skb_reserve(skb, 40);
    skb_put(skb, 1024);

    iov.iov_base = addr + 40;
    iov.iov_len = 1024;
    iov.iov_priv = (void *)skb;

    message.msg_name = &name;
    message.msg_namelen = sizeof(name);
    message.msg_iov = &iov;
    message.msg_iovlen = sizeof(iov);
    message.msg_control = NULL;
    message.msg_controllen = 0;
    message.msg_flags = 0xdeadbeef;
    int ret = dpa_sock_recvmsg(38, &message, 0);
    printk("dpa_sock_recvmsg, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_getsockopt(void)
{
    int val = 32;
    unsigned int optlen = sizeof(val);
    int ret = dpa_sock_getsockopt(38, SOL_SOCKET, SO_REUSEADDR, &val, &optlen);
    printk("dpa_sock_getsockopt, return ret = %d, optlen = %d, val = %d\n", ret, optlen, val);
    return ret;
}

int test_dpa_sock_ioctl(void)
{
    int cmd = 12;
    unsigned int val = 23;
    int ret = dpa_sock_ioctl(38, cmd, &val);
    printk("dpa_sock_ioctl, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_bind(void)
{
    struct dpa_sockaddr name;
    name.sa_len = 4;
    name.sa_family = AF_INET;
    name.sa_data[0] = 192;
    name.sa_data[1] = 168;
    name.sa_data[2] = 1;
    name.sa_data[3] = 100;
    int ret = dpa_sock_bind(38, &name, 6);
    printk("dpa_sock_bind, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_listen(void)
{
    int ret = dpa_sock_listen(38, 5);
    printk("dpa_sock_listen, return ret = %d\n", ret);
    return ret;
}

int test_dpa_sock_accept(void)
{
    struct dpa_sockaddr name;
    unsigned int addrlen = 6;
    int ret = dpa_sock_accept(38, &name, &addrlen);
    printk("dpa_sock_accept, return ret = %d\n", ret);
    return ret;
}

struct sock g_sk;
static void sock_event_cb(struct sock *sk, unsigned long long addr, unsigned int len, unsigned int offset)
{
    printk("sock_event_cb, sk = %p, addr = %llx, len = %u, offset = %u\n", sk, addr, len, offset);
}

int dpa_sock_init_ctx(void)
{
    int fd = 38;
    int ret;

    ret = dpa_sock_register_event(fd, &g_sk, sock_event_cb);
    printk("ret:%d\n", ret);

    return 0;
}

extern struct sock *g_dpa_sock;
extern int name_check(const char* str);

void sock_target(struct sock *sk)
{
    struct task_struct *task = (struct task_struct *)current;
    if (name_check(task->comm)) {
        g_dpa_sock = sk;
    }
}

int dpa_sock_event_cb(struct sock *priv, unsigned long long addr, unsigned int len, unsigned int offset)
{
    int ret;
    struct sk_buff *skb;
    unsigned long long orig;
    struct sock *sk;
    int i;

    sk = g_dpa_sock;
    skb = bsp_dra_unmap(addr, &orig);
    if ((skb == NULL) || (sk == NULL)) {
        printk("dpa_sock_event_cb, skb = %p, sk = %p\n", skb, sk);
        bsp_dra_free(orig);
        return -1;
    }

    skb_reserve(skb, offset);
    skb_put(skb, len);
    skb->ip_summed = CHECKSUM_UNNECESSARY;
    udp_skb_scratch(skb)->csum_unnecessary = true;
    for (i = 0; i < 100; i++) {
        skb->data[i] = i;
    }

    ret = sock_queue_rcv_skb(sk, skb);
    printk("sk->sk_protocol %d\n", sk->sk_protocol);
    printk("SOCK_DEAD:%d\n", sock_flag(sk, SOCK_DEAD) ? 1:0);

    if ((sk->sk_protocol == IPPROTO_TCP) && (!sock_flag(sk, SOCK_DEAD))) {
        printk("tcp_data_ready\n");
        sk->sk_data_ready(sk);
    }
    return ret;
}

int test_sock_queue()
{
    unsigned long long addr = bsp_dra_alloc(DRA_OPIPE_LEVEL_1_SIZE);
    return dpa_sock_event_cb(g_dpa_sock, addr, 100, 40);
}