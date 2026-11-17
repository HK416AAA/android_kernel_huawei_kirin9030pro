/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#include "proto_conn_stats.h"

const char **get_conn_stats_info(void)
{
    static const char *proto_conn_stats_info[CONN_STATS_MAX_TYPE] = {
        "tx_l4_enq_in",
        "tx_l4_enq_out",
        "tx_l4_enq_pcb_fatal_err",
        "tx_l4_enq_pcb_state_err",
        "tx_l4_enq_alloc_sbuf_err",
        "tx_l4_enq_mem_err",

        "tx_l4_in",
        "tx_l4_out",
        "tx_l4_pcb_fatal_err",
        "tx_l4_mem_err",
        "tx_l4_no_route_err",
        "tx_l4_dev_busy_err",

        "tx_tcp_ack_in",
        "tx_tcp_ack_out",
        "tx_tcp_ack_mem_err",
        "tx_tcp_ack_send_err",

        "tx_tcp_rexmit_in",
        "tx_tcp_rexmit_out",
        "tx_tcp_rexmit_dev_busy_err",
        "tx_tcp_rexmit_mem_err",
        "tx_tcp_rexmit_send_err",

        "tx_ip_in",
        "tx_ip_out",
        "tx_ip_loop_out",
        "tx_ip_discard",
        "tx_ip_no_route_err",

        "tx_gso_in",
        "tx_gso_out",
        "tx_filter_in",
        "tx_filter_out",

        "rx_filter_in",
        "rx_gro_in",
        "rx_gro_out",

        "rx_eth_in",
        "rx_eth_out",
        "rx_eth_dev_id_err",
        "rx_eth_netif_down",
        "rx_eth_csum_err",
        "rx_eth_hdr_len_err",
        "rx_eth_move_hdr_err",
        "rx_eth_proto_err",

        "rx_ip_in",
        "rx_ip_out",
        "rx_ip_hdr_err",
        "rx_ip_addr_err",
        "rx_ip_opt_err",
        "rx_ip_proto_err",
        "rx_ip_dst_addr_err",
        "rx_ip_move_hdr_err",
        "rx_ip_type_none_err",

        "rx_l4_in",
        "rx_l4_out",
        "rx_l4_backlog",
        "rx_l4_state_process_err",
        "rx_l4_rst_accepted_err",
        "rx_l4_last_ack_accepted_err",
        "rx_l4_tcp_acked_err",
        "rx_l4_tcp_shutdown_err",
        "rx_l4_cpcb_closed_err",

        "rx_tcp_acpu_backlog",
        "rx_tcp_oos",
        "rx_tcp_oos_discard",
        "rx_tcp_overlap",
        "rx_tcp_ack",

        "rx_msg_in",
        "rx_msg_out",
        "rx_msg_d2a_iov_unsent",
        "rx_msg_d2a_iov_unack",
        "rx_msg_d2a_iov_ofo",
        "rx_msg_d2a_iov_rcv",
        "rx_msg_null_err",
        "rx_msg_post_err",
    };
    return proto_conn_stats_info;
}

