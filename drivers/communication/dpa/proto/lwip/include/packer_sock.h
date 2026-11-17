#ifndef PACKER_SOCK_H
#define PACKER_SOCK_H

#include "packer.h"
#include "client.h"

void pack_sock_create(struct packer_buffer *packer, int af_family, int type);
void unpack_sock_create(struct packer_buffer *packer, int *af_family, int *type);
void pack_sock_close(struct packer_buffer *packer, int sock_fd);
void unpack_sock_close(struct packer_buffer *packer, int *sock_fd);
void pack_sock_register_event(struct packer_buffer *packer, int s, unsigned long long sock_priv);
void unpack_sock_register_event(struct packer_buffer *packer, int *s, unsigned long long *sock_priv);
void pack_sock_connect(struct packer_buffer *packer, int fd, void *name, unsigned int namelen);
void unpack_sock_connect(struct packer_buffer *packer, int *fd, void *name, unsigned int *namelen);
void pack_sock_setsockopt(struct packer_buffer *packer, int fd, int level, int optname, void *optval,
                          unsigned int optlen);
void unpack_sock_setsockopt(struct packer_buffer *packer, int *fd, int *level, int *optname, void *optval,
                            unsigned int *optlen);
void pack_sock_sendmsg(struct packer_buffer *packer, int fd, struct dpa_msghdr *message, int msg_size, int flags);
void unpack_sock_sendmsg(struct packer_buffer *packer, int *fd, struct dpa_msghdr *message, int msg_size, int *flags);
void pack_sock_recvmsg(struct packer_buffer *packer, int fd, struct dpa_msghdr *msg, int msg_size, int flags);
void unpack_sock_recvmsg(struct packer_buffer *pack, int *fd, struct dpa_msghdr *msg, int msg_size, int *flags);
void pack_sock_getsockopt(struct packer_buffer *packer, int fd, int level, int optname, void *optval,
                          unsigned int *optlen);
void unpack_sock_getsockopt(struct packer_buffer *packer, int *fd, int *level, int *optname, void *optval,
                            unsigned int *optlen);
void pack_sock_ioctl(struct packer_buffer *packer, int fd, unsigned long long cmd, void *argp, int size);
void unpack_sock_ioctl(struct packer_buffer *packer, int *fd, unsigned long long *cmd, void *argp, int size);
void pack_sock_bind(struct packer_buffer *packer, int fd, void *name, unsigned int namelen);
void unpack_sock_bind(struct packer_buffer *packer, int *fd, void *name, unsigned int *namelen);
void pack_sock_listen(struct packer_buffer *packer, int fd, int backlog);
void unpack_sock_listen(struct packer_buffer *packer, int *fd, int *backlog);
void pack_sock_accept(struct packer_buffer *packer, int fd, void *addr, unsigned int *addrlen);
void unpack_sock_accept(struct packer_buffer *packer, int *fd, void *addr, unsigned int *addrlen);
void pack_sock_recv(struct packer_buffer *packer, void *priv, unsigned long long addr, unsigned int len, unsigned int offset);
void unpack_sock_recv(struct packer_buffer *packer, void **priv, unsigned long long *addr, unsigned int *len, unsigned int *offset);
#endif