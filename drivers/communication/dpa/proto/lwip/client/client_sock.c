#include <bsp_dpa_client.h>
#include <linux/semaphore.h>
#include <linux/printk.h>
#include <securec.h>
#include "client.h"
#include "packer_helper.h"
#include "packer_sock.h"
#include "id.h"
#include <bsp_dra.h>

#define DATA_TRANS_BY_MSG

struct request_reply {
    struct semaphore *sema;
    unsigned char *data;
    unsigned int len;
};

static sock_recv_cb g_sock_recv_cb = NULL;

static void dpa_sock_request_return_cb(void *priv, unsigned char *data, unsigned int len)
{
    struct request_reply *reply = (struct request_reply *)priv;
    PACKER_BUFFER(packer, data, len);
    packer_buffer_pop_s32(&packer, (int *)reply->data);
    reply->len = len;
    up(reply->sema);
}

int dpa_sock_create(int af_family, int type)
{
    unsigned char data[64];

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_CREATE, dpa_sock_request_return_cb, &reply);
    pack_sock_create(&packer, af_family, type);
    packer_end(&packer);

    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_close(int fd)
{
    unsigned char data[64];

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_CLOSE, dpa_sock_request_return_cb, &reply);
    pack_sock_close(&packer, fd);
    packer_end(&packer);

    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_register_event(int s, void *sock_priv, sock_recv_cb event_cb)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    g_sock_recv_cb = event_cb;
    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_REGISTER_EVENT, dpa_sock_request_return_cb, &reply);
    pack_sock_register_event(&packer, s, sock_priv);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_connect(int fd, struct dpa_sockaddr *name, unsigned int namelen)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_CONNECT, dpa_sock_request_return_cb, &reply);
    pack_sock_connect(&packer, fd, name, namelen);
    packer_end(&packer);

    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_setsockopt(int fd, int level, int optname, void *optval, unsigned int optlen)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_SETSOCKOPT, dpa_sock_request_return_cb, &reply);
    pack_sock_setsockopt(&packer, fd, level, optname, optval, optlen);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_sendmsg(int fd, unsigned char* send_buf, unsigned int buf_size, struct dpa_msghdr *message, int flags)
{
    unsigned char* data = send_buf;
    int ret = -1;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    if (data != NULL) {
        PACKER_BUFFER(packer, data, buf_size);
        packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_SENDMSG, dpa_sock_request_return_cb, &reply);

        pack_sock_sendmsg(&packer, fd, message, sizeof(struct dpa_msghdr), flags);
        packer_end(&packer);

        bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

        down(&sema);
    } else {
        printk("%s packer is NULL\n", __func__);
        return -1;
    }

    return ret;
}

int dpa_sock_recvmsg(int fd, void *mem, int flags)
{
    unsigned char data[128];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };

    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_RECVMSG, dpa_sock_request_return_cb, &reply);
    pack_sock_recvmsg(&packer, fd, mem, sizeof(struct dpa_msghdr), flags);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

void dpa_sock_recvmsg_end(int fd, void *mem, int flags)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    packer_begin(&packer, SERVICE_RPOTO_SOCK, SOCK_RECVMSG_END);
    pack_sock_recvmsg(&packer, fd, mem, sizeof(struct dpa_msghdr), flags);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
}

int dpa_sock_getsockopt(int fd, int level, int optname, void *optval, unsigned int *optlen)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_GETSOCKOPT, dpa_sock_request_return_cb, &reply);
    pack_sock_getsockopt(&packer, fd, level, optname, optval, optlen);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_ioctl(int fd, long cmd, void *argp)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_IOCTL, dpa_sock_request_return_cb, &reply);
    pack_sock_ioctl(&packer, fd, cmd, argp, sizeof(unsigned long long));

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_bind(int fd, struct dpa_sockaddr *name, unsigned int namelen)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_BIND, dpa_sock_request_return_cb, &reply);
    pack_sock_bind(&packer, fd, name, namelen);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_listen(int fd, int backlog)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_LISTEN, dpa_sock_request_return_cb, &reply);
    pack_sock_listen(&packer, fd, backlog);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_accept(int fd, struct dpa_sockaddr *addr, unsigned int *addrlen)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_RPOTO_SOCK, SOCK_ACCEPT, dpa_sock_request_return_cb, &reply);
    pack_sock_accept(&packer, fd, addr, addrlen);
    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);

    down(&sema);
    return ret;
}

int dpa_sock_recv(unsigned char *data, unsigned int size)
{
    struct sock *sk;
    unsigned long long addr;
    unsigned int len;
    unsigned int offset;
#ifdef DATA_TRANS_BY_MSG
    char *payload;
#endif

    PACKER_BUFFER(packer, data, size);
    unpack_sock_recv(&packer, (void **)&sk, &addr, &len, &offset);
#ifdef DATA_TRANS_BY_MSG
    addr = bsp_dra_alloc(len);
    payload = phys_to_virt((addr + offset) & 0xfffffffff);
    packer_buffer_pop_array(&packer, payload, 1500);
#endif
    if (g_sock_recv_cb) {
        g_sock_recv_cb(sk, addr, len, offset);
        return 0;
    }
    printk("g_sock_recv_cb is NULL\n");
    return -1;
}

static int subscribe_cb(char *priv, unsigned int id, struct dpa_func_msg *msg)
{
    switch (id) {
        case SOCK_PUBLISH:
            break;
        case SOCK_RECV:
            return dpa_sock_recv(msg->buf, msg->len);
        default:
            return -1;
    }
    return 0;
}

static struct dpa_client g_subscribe = {
    .service_id = SERVICE_RPOTO_SOCK,
    .priv = (void *)&g_subscribe,
    .service_cb = NULL,
    .subscribe_sb = subscribe_cb,
};

int dpa_sock_subscribe(void)
{
    return bsp_dpa_client_register(&g_subscribe);
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(dpa_sock_subscribe);
#endif