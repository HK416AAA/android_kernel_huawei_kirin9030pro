#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include "bsp_dra.h"
#include "packer_sock.h"

void pack_sock_create(struct packer_buffer *packer, int af_family, int type)
{
    packer_buffer_append_s32(packer, af_family);
    packer_buffer_append_s32(packer, type);
}

void unpack_sock_create(struct packer_buffer *packer, int *af_family, int *type)
{
    packer_buffer_pop_s32(packer, af_family);
    packer_buffer_pop_s32(packer, type);
}

void pack_sock_close(struct packer_buffer *packer, int sock_fd)
{
    packer_buffer_append_s32(packer, sock_fd);
}

void unpack_sock_close(struct packer_buffer *packer, int *sock_fd)
{
    packer_buffer_pop_s32(packer, sock_fd);
}

void pack_sock_register_event(struct packer_buffer *packer, int s, unsigned long long sock_priv)
{
    packer_buffer_append_s32(packer, s);
    packer_buffer_append_u64(packer, sock_priv);
}

void unpack_sock_register_event(struct packer_buffer *packer, int *s, unsigned long long *sock_priv)
{
    packer_buffer_pop_s32(packer, s);
    packer_buffer_pop_u64(packer, sock_priv);
}

void pack_sock_connect(struct packer_buffer *packer, int fd, void *name, unsigned int namelen)
{
    packer_buffer_append_s32(packer, fd);
    packer_buffer_append_u32(packer, namelen);
    packer_buffer_append_array(packer, name, namelen);
}

void unpack_sock_connect(struct packer_buffer *packer, int *fd, void *name, unsigned int *namelen)
{
    packer_buffer_pop_s32(packer, fd);
    packer_buffer_pop_u32(packer, namelen);
    packer_buffer_pop_array(packer, name, *namelen);
}

void pack_sock_setsockopt(struct packer_buffer *packer, int fd, int level, int optname, void *optval,
                          unsigned int optlen)
{
    packer_buffer_append_s32(packer, fd);
    packer_buffer_append_s32(packer, level);
    packer_buffer_append_s32(packer, optname);
    packer_buffer_append_u32(packer, optlen);
    packer_buffer_append_array(packer, optval, optlen);
}

void unpack_sock_setsockopt(struct packer_buffer *packer, int *fd, int *level, int *optname, void *optval,
                            unsigned int *optlen)
{
    packer_buffer_pop_s32(packer, fd);
    packer_buffer_pop_s32(packer, level);
    packer_buffer_pop_s32(packer, optname);
    packer_buffer_pop_u32(packer, optlen);
    packer_buffer_pop_array(packer, optval, *optlen);
}

void pack_sock_dpa_msg(struct packer_buffer *packer, struct dpa_msghdr *message, int msg_size)
{
    packer_buffer_append_array(packer, (unsigned char *)message->msg_name, message->msg_namelen);
    packer_buffer_append_array(packer, (unsigned char *)message->msg_iov, message->msg_iovlen);
    packer_buffer_append_array(packer, (unsigned char *)message->msg_control, message->msg_controllen);
    packer_buffer_append_u32(packer, message->msg_flags);
}

void unpack_sock_dpa_msg(struct packer_buffer *packer, struct dpa_msghdr *message, int msg_size)
{
    packer_buffer_pop_array_nocopy(packer, (unsigned char **)&message->msg_name, &message->msg_namelen);
    packer_buffer_pop_array_nocopy(packer, (unsigned char **)&message->msg_iov, &message->msg_iovlen);
    packer_buffer_pop_array_nocopy(packer, (unsigned char **)&message->msg_control, &message->msg_controllen);
    packer_buffer_pop_u32(packer, &message->msg_flags);
}

static void pack_sock_dpa_msg_and_data(struct packer_buffer *packer, struct dpa_msghdr *message, int msg_size)
{
    int i;

    packer_buffer_append_u32(packer, message->msg_flags);
    packer_buffer_append_u32(packer, message->msg_iovlen);
    packer_buffer_append_u32(packer, message->msg_namelen);
    packer_buffer_append_u32(packer, message->msg_controllen);
    packer_buffer_append_array(packer, (unsigned char *)message->msg_name, message->msg_namelen);
    packer_buffer_append_array(packer, (unsigned char *)message->msg_control, message->msg_controllen);

    /* pack data to msg */
    packer_buffer_append_array(packer, message->msg_iov, message->msg_iovlen * sizeof(struct dpa_iovec));
}

static void unpack_sock_dpa_msg_and_data(struct packer_buffer *packer, struct dpa_msghdr *message, int msg_size)
{
    int i;

    packer_buffer_pop_u32(packer, &message->msg_flags);
    packer_buffer_pop_u32(packer, &message->msg_iovlen);
    packer_buffer_pop_u32(packer, &message->msg_namelen);
    packer_buffer_pop_u32(packer, &message->msg_controllen);
    packer_buffer_pop_array(packer, (unsigned char *)message->msg_name, message->msg_namelen);
    packer_buffer_pop_array(packer, (unsigned char *)message->msg_control, message->msg_controllen);

    /* unpack msg data to maa */
    for (i = 0; i < message->msg_iovlen; i++) {
        unsigned long long dra_addr = bsp_dra_alloc(DRA_OPIPE_LEVEL_1_SIZE);
        dra_buf_t dra_data = (dra_buf_t)dra_addr;
        unsigned char* virt_data;

        message->msg_iov[i].iov_base = 0;
        if (dra_addr == NULL) {
            goto alloc_fail;
        }

        virt_data = phys_to_virt(dra_data.bits.phyaddr);
        packer_buffer_pop_u32(packer, &message->msg_iov[i].iov_len);
        packer_buffer_pop_array(packer, virt_data, message->msg_iov[i].iov_len);
        message->msg_iov[i].iov_base = (unsigned long long)virt_data;
        message->msg_iov[i].iov_priv = dra_addr;
    }

    return;

alloc_fail:
    for (i = 0; i < message->msg_iovlen; i++) {
        if (message->msg_iov[i].iov_base != 0) {
            bsp_dra_free(message->msg_iov[i].iov_base);
            message->msg_iov[i].iov_base = 0;
        }
    }
    message->msg_iovlen = 0;
    return;
}

void pack_sock_sendmsg(struct packer_buffer *packer, int fd, struct dpa_msghdr *message, int msg_size, int flags)
{
    packer_buffer_append_s32(packer, fd);
    pack_sock_dpa_msg_and_data(packer, message, msg_size);
    packer_buffer_append_s32(packer, flags);
}

void unpack_sock_sendmsg(struct packer_buffer *packer, int *fd, struct dpa_msghdr *message, int msg_size, int *flags)
{
    packer_buffer_pop_s32(packer, fd);
    unpack_sock_dpa_msg_and_data(packer, message, msg_size);
    packer_buffer_pop_s32(packer, flags);
}

void pack_sock_recvmsg(struct packer_buffer *packer, int fd, struct dpa_msghdr *msg, int msg_size, int flags)
{
    packer_buffer_append_s32(packer, fd);
    pack_sock_dpa_msg(packer, msg, msg_size);
    packer_buffer_append_s32(packer, flags);
}

void unpack_sock_recvmsg(struct packer_buffer *pack, int *fd, struct dpa_msghdr *msg, int msg_size, int *flags)
{
    packer_buffer_pop_s32(pack, fd);
    unpack_sock_dpa_msg(pack, msg, msg_size);
    packer_buffer_pop_s32(pack, flags);
}

void pack_sock_getsockopt(struct packer_buffer *packer, int fd, int level, int optname, void *optval,
                          unsigned int *optlen)
{
    packer_buffer_append_s32(packer, fd);
    packer_buffer_append_s32(packer, level);
    packer_buffer_append_s32(packer, optname);
    packer_buffer_append_u32(packer, *optlen);
    packer_buffer_append_array(packer, optval, *optlen);
}

void unpack_sock_getsockopt(struct packer_buffer *packer, int *fd, int *level, int *optname, void *optval,
                            unsigned int *optlen)
{
    packer_buffer_pop_s32(packer, fd);
    packer_buffer_pop_s32(packer, level);
    packer_buffer_pop_s32(packer, optname);
    packer_buffer_pop_u32(packer, optlen);
    packer_buffer_pop_array(packer, optval, *optlen);
}

void pack_sock_ioctl(struct packer_buffer *packer, int fd, unsigned long long cmd, void *argp, int size)
{
    packer_buffer_append_s32(packer, fd);
    packer_buffer_append_u64(packer, cmd);
    packer_buffer_append_array(packer, argp, size);
}

void unpack_sock_ioctl(struct packer_buffer *packer, int *fd, unsigned long long *cmd, void *argp, int size)
{
    packer_buffer_pop_s32(packer, fd);
    packer_buffer_pop_u64(packer, cmd);
    packer_buffer_pop_array(packer, argp, size);
};

void pack_sock_bind(struct packer_buffer *packer, int fd, void *name, unsigned int namelen)
{
    packer_buffer_append_s32(packer, fd);
    packer_buffer_append_s32(packer, namelen);
    packer_buffer_append_array(packer, name, namelen);
}

void unpack_sock_bind(struct packer_buffer *packer, int *fd, void *name, unsigned int *namelen)
{
    packer_buffer_pop_s32(packer, fd);
    packer_buffer_pop_u32(packer, namelen);
    packer_buffer_pop_array(packer, name, *namelen);
}

void pack_sock_listen(struct packer_buffer *packer, int fd, int backlog)
{
    packer_buffer_append_s32(packer, fd);
    packer_buffer_append_s32(packer, backlog);
}

void unpack_sock_listen(struct packer_buffer *packer, int *fd, int *backlog)
{
    packer_buffer_pop_s32(packer, fd);
    packer_buffer_pop_s32(packer, backlog);
}

void pack_sock_accept(struct packer_buffer *packer, int fd, void *addr, unsigned int *addrlen)
{
    packer_buffer_append_s32(packer, fd);
    packer_buffer_append_u32(packer, *addrlen);
    packer_buffer_append_array(packer, addr, *addrlen);
}

void unpack_sock_accept(struct packer_buffer *packer, int *fd, void *addr, unsigned int *addrlen)
{
    packer_buffer_pop_s32(packer, fd);
    packer_buffer_pop_u32(packer, addrlen);
    packer_buffer_pop_array(packer, addr, *addrlen);
}

void pack_sock_recv(struct packer_buffer *packer, void *priv, unsigned long long addr, unsigned int len, unsigned int offset)
{
    packer_buffer_append_ptr(packer, priv);
    packer_buffer_append_u64(packer, addr);
    packer_buffer_append_u32(packer, len);
    packer_buffer_append_u32(packer, offset);
}

void unpack_sock_recv(struct packer_buffer *packer, void **priv, unsigned long long *addr, unsigned int *len, unsigned int *offset)
{
    packer_buffer_pop_ptr(packer, priv);
    packer_buffer_pop_u64(packer, addr);
    packer_buffer_pop_u32(packer, len);
    packer_buffer_pop_u32(packer, offset);
}