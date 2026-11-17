/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SPL_COMMON_OPT_H
#define SPL_COMMON_OPT_H

#include "sockets.h"
#include "in.h"

#ifdef __cplusplus
extern "C" {
#endif

/* For the connect API, these values are use as a bitmask! */
#define SPL_SHUT_RD 1U
#define SPL_SHUT_WR 2U
#define SPL_SHUT_RDWR (SPL_SHUT_RD | SPL_SHUT_WR)

/* Flags for connect_write */
#define CONN_WT_COPY 0x01U
#define CONN_WT_MORE 0x02U
#define CONN_WT_NOBLOCK 0x04

typedef enum conn_type {
    CONN_TYPE_INVALID = 0,
    CONN_TYPE_TCP = 0x10,
    CONN_TYPE_UDP = 0x20
} conn_type_t;

static inline s32 conn_type_2_proto(enum conn_type type)
{
    if (type == CONN_TYPE_TCP) {
        return SPL_IPPROTO_TCP;
    } else if (type == CONN_TYPE_UDP) {
        return SPL_IPPROTO_UDP;
    } else {
        return -1;
    }
}

#define TCP_CA_NAME_MAX 16

enum {
    TCP_STATE_CLOSED,
    TCP_STATE_LISTEN,
    TCP_STATE_SYN_SENT,
    TCP_STATE_SYN_RCVD,
    TCP_STATE_ESTABLISHED,
    TCP_STATE_FIN_WAIT_1,
    TCP_STATE_FIN_WAIT_2,
    TCP_STATE_CLOSE_WAIT,
    TCP_STATE_CLOSING,
    TCP_STATE_LAST_ACK,
    TCP_STATE_TIME_WAIT
};

static inline bool tcp_state_unwriteable(u8 s)
{
    return !(((s) == (u8)TCP_STATE_ESTABLISHED) || ((s) == (u8)TCP_STATE_CLOSE_WAIT));
}
typedef struct ipmreq {
    struct spl_in_addr imr_multiaddr; /* IP multicast address of group */
    struct spl_in_addr imr_interface; /* local IPaddress of interface */
} ipmreq;

#ifdef __cplusplus
}
#endif

#endif
