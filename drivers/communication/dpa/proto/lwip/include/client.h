/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef DPA_CLIENT_H
#define DPA_CLIENT_H

#include <linux/types.h>
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/skbuff.h>

#define DPA_NET_EVT_RCV     0
#define DPA_NET_EVT_SEND    1
#define DPA_NET_EVT_ERR     2

typedef void (*sock_recv_cb)(struct sock *sk, unsigned long long addr, unsigned int len, unsigned int offset);

struct dpa_sock_pkt_info {
    unsigned long long data_org;
    unsigned short len;
    unsigned short data_off;
};

struct dpa_data {
    int fd;
    unsigned long long addr;
    unsigned long len;
};

struct dpa_sockaddr {
    unsigned char sa_len;
    unsigned char sa_family;
    char sa_data[26];
};

struct dpa_iovec {
    unsigned long long iov_base;
    unsigned int iov_len;
    unsigned long long iov_priv;
};

struct dpa_msghdr {
    struct dpa_sockaddr *msg_name;
    unsigned int msg_namelen;
    struct dpa_iovec *msg_iov;
    int msg_iovlen;
    void *msg_control;
    unsigned int msg_controllen;
    unsigned int msg_flags;
};

struct eth_addr {
    u8 addr[6];
};

struct ip6_addr {
    u32 addr[4];
};
typedef struct ip6_addr ip6_addr_t;

int dpa_config_netdev(int idx, int mtu);
int dpa_netdev_add(struct eth_addr *mac, int is_no_arp);
int dpa_netdev_remove(int idx);
int dpa_netdev_update(int idx, int is_no_arp);
int dpa_netdev_cfg_ip4addr(int idx, unsigned int local, unsigned int mask);

int dpa_add_static_arp_entry(int idx, unsigned int ip_addr, struct eth_addr *mac_addr, int is_notif);
int dpa_del_static_arp_entry(unsigned int addr);
int dpa_add_static_nd6_entry(const ip6_addr_t *ip_addr, struct eth_addr *mac_addr);
int dpa_del_static_nd6_entry(const ip6_addr_t *ip_addr);
void dpa_etharp_register_notifier(void *notif_cb);
void dpa_nd6_register_notifier(void *notif_cb);

int dpa_sock_create(int af_family, int type);
int dpa_sock_close(int fd);
int dpa_sock_register_event(int s, void *sock_priv, sock_recv_cb event_cb);
int dpa_sock_connect(int fd, struct dpa_sockaddr *name, unsigned int namelen);
int dpa_sock_setsockopt(int fd, int level, int optname, void *optval, unsigned int optlen);
int dpa_sock_sendmsg(int fd, unsigned char* send_buf, unsigned int buf_size, struct dpa_msghdr *message, int flags);
int dpa_sock_recvmsg(int fd, void *mem, int flags);
void dpa_sock_recvmsg_end(int fd, void *mem, int flags);
int dpa_sock_getsockopt(int fd, int level, int optname, void *optval, unsigned int *optlen);
int dpa_sock_ioctl(int fd, long cmd, void *argp);
int dpa_sock_bind(int fd, struct dpa_sockaddr *name, unsigned int namelen);
int dpa_sock_listen(int fd, int backlog);
int dpa_sock_accept(int fd, struct dpa_sockaddr *addr, unsigned int *addrlen);
void client_init(int (*func)(void *, int));
int client_send(void *param, int len);

#endif