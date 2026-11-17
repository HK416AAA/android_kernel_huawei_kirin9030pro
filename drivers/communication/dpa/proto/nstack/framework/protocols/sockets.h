/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SPL_SOCKETS_H
#define SPL_SOCKETS_H

#include "stack_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SO_DEBUG        1
#define SO_REUSEADDR    2
#define SO_TYPE         3
#define SO_ERROR        4
#define SO_DONTROUTE    5
#define SO_BROADCAST    6
#define SO_SNDBUF       7
#define SO_RCVBUF       8
#define SO_KEEPALIVE    9
#define SO_OOBINLINE    10
#define SO_NO_CHECK     11
#define SO_PRIORITY     12
#define SO_LINGER       13
#define SO_BSDCOMPAT    14
#define SO_REUSEPORT    15
#define SPL_SO_SNDLOWAT     17
#define SO_RCVLOWAT     18
#define SO_RCVTIMEO     20 /* receive timeout */
#define SO_SNDTIMEO     21 /* send timeout */
#define SO_BINDTODEVICE 25
#define SO_TIMESTAMP    29 /* Enable or disable the receiving of the SO_TIMESTAMP control message */
#define SCM_TIMESTAMP   SO_TIMESTAMP
#define SO_ACCEPTCONN   30
#define SO_SNDBUFFORCE  32
#define SO_RCVBUFFORCE  33
#define SO_MARK         36
#ifndef SO_TIMESTAMPING
#define SO_TIMESTAMPING 37
#endif
#define SCM_TIMESTAMPING    SO_TIMESTAMPING
#define SO_PROTOCOL     38
#define SO_DOMAIN       39

#define F_GETFL        3 /* get file->f_flags */
#define F_SETFL        4 /* set file->f_flags */

#define SPL_O_RDWR        00000002
#define SPL_O_NONBLOCK    00004000
#define SPL_SOCK_CLOEXEC  02000000

#define FIONREAD    0x467f
#define FIONBIO     0x667e
#define TIOCOUTQ    0x5411
#define SIOCOUTQ    TIOCOUTQ
#define SIOCOUTQNSD 0x894B        /* output queue size (not sent only) */

#define SOL_SOCKET 1

#define AF_UNSPEC   0
#define AF_INET     2
#define PF_INET AF_INET
#define AF_INET6    10

#define MSG_OOB     1
#define MSG_PEEK    2
#define MSG_CTRUNC  8
#define MSG_DONTWAIT    0x40    /* Nonblocking io         */
#define MSG_ERRQUEUE    0x2000    /* Fetch message from error queue */
#define MSG_MORE    0x8000    /* Sender will send more */

enum spl_sock_type {
    SPL_SOCK_STREAM = 1,
    SPL_SOCK_DGRAM = 2,
    SPL_SOCK_RAW = 3,
    SPL_SOCK_RDM = 4,
    SPL_SOCK_SEQPACKET = 5,
    SPL_SOCK_DCCP = 6,
    SPL_SOCK_PACKET = 10,
};

#if !defined(spl_sa_family_t)
typedef u16 spl_sa_family_t;
#endif

struct spl_sockaddr {
    spl_sa_family_t sa_family;
    char sa_data[14];
};

#if !defined(in_addr_t)
typedef u32 in_addr_t;
#endif
#if !defined(in_port_t)
typedef u16 in_port_t;
#endif

struct spl_in_addr {
    in_addr_t s_addr;
};
struct spl_sockaddr_in {
    spl_sa_family_t     sin_family;
    in_port_t       sin_port;
    struct spl_in_addr  sin_addr;

#define SIN_ZERO_LEN 8
    char            sin_zero[SIN_ZERO_LEN];
};

struct spl_linger {
    s32 l_onoff;
    s32 l_linger;
};

struct spl_cmsghdr {
    u64 cmsg_len;
    s32 cmsg_level;
    s32 cmsg_type;
};

#define SPL_CMSG_ALIGN(len) (((len) + sizeof(long) - 1) & ~(sizeof(long) - 1))
#define SPL_CMSG_DATA(cmsg) ((void *)(cmsg) + sizeof(struct spl_cmsghdr))

struct spl_iovec {
    void *iov_base;
    size_t iov_len;
};

struct spl_msghdr {
    void *msg_name;
    socklen_t msg_namelen;
    struct spl_iovec *msg_iov;
    int msg_iovlen;
    void *msg_control;
    socklen_t msg_controllen;
    int msg_flags;
};

typedef unsigned int nfds_t;
struct spl_pollfd {
    int fd;
    short events;
    short revents;
};

struct spl_sockaddr_storage {
    spl_sa_family_t ss_family;
    char s2_data1[2];
    unsigned int s2_data2[3];
    unsigned int s2_data3[3];
};

#ifdef __cplusplus
}
#endif

#endif /* __SPL_SOCKETS_H__ */
