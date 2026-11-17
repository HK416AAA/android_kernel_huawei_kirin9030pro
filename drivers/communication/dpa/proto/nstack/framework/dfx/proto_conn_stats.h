/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef PROTO_CONN_STATS_H
#define PROTO_CONN_STATS_H

#include "stack_types.h"

#define STRING_LEN 400
#define STRING_SHORT_LEN 80

typedef struct {
    u32 cnt;
    u32 pkts;
    u32 bytes;
} stat_unit;

typedef struct {
    u64 cnt;
    u64 pkts;
    u64 bytes;
} stat64_unit;

enum proto_conn_stats_type {
    TX_L4_ENQ_IN,
    TX_L4_ENQ_OUT,
    TX_L4_ENQ_PCB_FATAL_ERR,
    TX_L4_ENQ_PCB_STATE_ERR,
    TX_L4_ENQ_ALLOC_SBUF_ERR,
    TX_L4_ENQ_MEM_ERR,

    TX_L4_IN,
    TX_L4_OUT,
    TX_L4_PCB_FATAL_ERR,
    TX_L4_MEM_ERR,
    TX_L4_NO_ROUTE_ERR,
    TX_L4_DEV_BUSY_ERR,

    TX_TCP_ACK_IN,
    TX_TCP_ACK_OUT,
    TX_TCP_ACK_MEM_ERR,
    TX_TCP_ACK_SEND_ERR,

    TX_TCP_REXMIT_IN,
    TX_TCP_REXMIT_OUT,
    TX_TCP_REXMIT_DEV_BUSY_ERR,
    TX_TCP_REXMIT_MEM_ERR,
    TX_TCP_REXMIT_SEND_ERR,

    TX_IP_IN,
    TX_IP_OUT,
    TX_IP_LOOP_OUT,
    TX_IP_DISCARD,
    TX_IP_NO_ROUTE_ERR,

    TX_GSO_IN,
    TX_GSO_OUT,
    TX_FILTER_IN,
    TX_FILTER_OUT,

    RX_FILTER_IN,
    RX_GRO_IN,
    RX_GRO_OUT,

    RX_ETH_IN,
    RX_ETH_OUT,
    RX_ETH_DEV_ID_ERR,
    RX_ETH_NETIF_DOWN,
    RX_ETH_CSUM_ERR,
    RX_ETH_HDR_LEN_ERR,
    RX_ETH_MOVE_HDR_ERR,
    RX_ETH_PROTO_ERR,

    RX_IP_IN,
    RX_IP_OUT,
    RX_IP_HDR_ERR,
    RX_IP_ADDR_ERR,
    RX_IP_OPT_ERR,
    RX_IP_PROTO_ERR,
    RX_IP_DST_ADDR_ERR,
    RX_IP_MOVE_HDR_ERR,
    RX_IP_TYPE_NONE_ERR,

    RX_L4_IN,
    RX_L4_OUT,
    RX_L4_BACKLOG,
    RX_L4_STATE_PROCESS_ERR,
    RX_L4_RST_ACCEPTED_ERR,
    RX_L4_LAST_ACK_ACCEPTED_ERR,
    RX_L4_TCP_ACKED_ERR,
    RX_L4_TCP_SHUTDOWN_ERR,
    RX_L4_CPCB_CLOSED_ERR,

    RX_TCP_ACPU_BACKLOG,
    RX_TCP_OOS,
    RX_TCP_OOS_DISCARD,
    RX_TCP_OVERLAP,
    RX_TCP_ACK, /* ack without data */

    RX_MSG_IN,
    RX_MSG_OUT,
    RX_MSG_D2A_IOV_UNSENT,
    RX_MSG_D2A_IOV_UNACK,
    RX_MSG_D2A_IOV_OFO,
    RX_MSG_D2A_IOV_RCV,
    RX_MSG_NULL_ERR,
    RX_MSG_POST_ERR,

    CONN_STATS_MAX_TYPE
};

const char **get_conn_stats_info(void);

#endif /* PROTO_CONN_STATS_H */
