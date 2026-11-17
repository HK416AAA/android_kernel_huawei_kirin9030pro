/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "stack_time.h"
#include "securec.h"
#include "msg/bridge_msg_producer.h"
#include "stack_log.h"
#include "cooperation/cooperation.h"
#include "dfx/conn_stats.h"
#include "dfx/global_res_stats.h"

#if SPL_STATS

#define NSTACK_DFX_VERSION 11

sbr_dfx_sock_info g_sbr_dfx_sock_info = {.dfx_version = NSTACK_DFX_VERSION};

sbr_dfx_sock_info *get_dfx_sock_info(void)
{
    return &g_sbr_dfx_sock_info;
}

unsigned int get_dfx_sock_info_size(void)
{
    return sizeof(g_sbr_dfx_sock_info);
}

u64 sbr_total_sock_inc_return(void)
{
    return (u64)dmm_atomic64_inc_return(&g_sbr_dfx_sock_info.tot_sock);
}

void sbr_cur_tot_sock_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.cur_tot_sock);
}

void sbr_cur_tot_sock_dec(void)
{
    dmm_atomic_dec(&g_sbr_dfx_sock_info.cur_tot_sock);
}

void sbr_migrate_sock_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_sock);
}

void sbr_migrate_sock_dec(void)
{
    dmm_atomic_dec(&g_sbr_dfx_sock_info.migrate_sock);
}

void sbr_migrate_a2d_request_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_a2d_request);
}

void sbr_migrate_a2d_success_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_a2d_success);
}

void sbr_migrate_a2d_failed_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_a2d_failed);
}

void sbr_migrate_a2d_not_support_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_a2d_not_support);
}

void sbr_migrate_a2d_msg_success_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_a2d_msg_success);
}

void sbr_migrate_a2d_msg_failed_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_a2d_msg_failed);
}

void sbr_migrate_d2a_request_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_d2a_request);
}

void sbr_migrate_d2a_success_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_d2a_success);
}

void sbr_migrate_d2a_failed_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_d2a_failed);
}

void sbr_msg_migrate_d2a_success_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_d2a_msg_success);
}

void sbr_msg_migrate_d2a_failed_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.migrate_d2a_msg_failed);
}

void sbr_msg_post_succ_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.msg_post_succ);
}

void sbr_msg_post_fail_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.msg_post_failed);
}

void sbr_msg_handle_inc(void)
{
    g_sbr_dfx_sock_info.msg_handle++;
}

s32 get_gro_rcv(sbr_socket_t *sk, struct msghdr *msg, int err)
{
    if (!udp_sk(sk->sk)->gro_enabled) {
        sbr_global_stat_pkts_add(GLOBAL_RX_SBR_UDP_OUT, 1);
        sbr_conn_stat_pkts_add(sk->stats, SBR_RX_APP_OUT, 1);
        return 0;
    }
    struct cmsghdr *cmsg;
    for (cmsg = CMSG_FIRSTHDR(msg); cmsg != NULL; cmsg = CMSG_NXTHDR(msg, cmsg)) {
        if (cmsg->cmsg_level == SOL_UDP && cmsg->cmsg_type == UDP_GRO) {
            u32 gso_size = *(u32 *)CMSG_DATA(cmsg);
            u32 pkt = (err + gso_size - 1) / gso_size;
            sbr_global_stat_pkts_add(GLOBAL_RX_SBR_UDP_OUT, (u8)pkt);
            sbr_conn_stat_pkts_add(sk->stats, SBR_RX_APP_OUT, (u8)pkt);
            return 1;
        }
    }
    sbr_global_stat_pkts_add(GLOBAL_RX_SBR_UDP_OUT, 1);
    sbr_conn_stat_pkts_add(sk->stats, SBR_RX_APP_OUT, 1);
    return 0;
}


void sbr_dra_alloc_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.sbr_dra_alloc);
}

void sbr_dra_unmap_reuse_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.sbr_dra_unmap_reuse);
}

void sbr_dra_free_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.sbr_dra_free);
}

void sbr_dra_put_page_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.sbr_dra_put_page);
}

void sbr_dra_free_err_inc(void)
{
    dmm_atomic_inc(&g_sbr_dfx_sock_info.sbr_dra_free_err);
}

const char **get_global_stats_info(void)
{
    static const char *info[GLOBAL_STAT_TYPE_MAX] = {
        "tx_sbr_tcp_in",
        "tx_sbr_tcp_out",
        "tx_sbr_tcp_not_ready_err",
        "tx_sbr_tcp_sk_status_err",
        "tx_sbr_tcp_lsk_err",
        "tx_sbr_tcp_no_mem_err",
        "tx_sbr_tcp_copy_err",
        "tx_sbr_udp_in",
        "tx_sbr_udp_out",
        "tx_sbr_udp_get_vid_err",
        "tx_sbr_udp_len_err",
        "tx_sbr_udp_oob_err",
        "tx_sbr_udp_netbuf_err",
        "tx_sbr_udp_addr_err",
        "tx_sbr_udp_route_err",
        "tx_sbr_udp_dns_port_err",
        "tx_sbr_udp_device_err",
        "tx_sbr_udp_lo_err",
        "tx_sbr_udp_general_err",
        "tx_sbr_udp_bpf_err",
        "tx_sbr_udp_mem_err",

        "tx_msg_tcp_in",
        "tx_msg_tcp_out",
        "tx_msg_tcp_post_err",
        "tx_msg_udp_in",
        "tx_msg_udp_out",
        "tx_msg_udp_post_err",

        "rx_msg_in",
        "rx_msg_out",
        "rx_msg_tcp_out",
        "rx_msg_udp_out",
        "rx_msg_skb_next_list",
        "rx_msg_from_dpa_err",
        "rx_msg_skb_null_err",
        "rx_msg_sk_closed_err",
        "rx_msg_sk_rmem_err",
        "rx_msg_udp_bpf_err",
        "rx_msg_segs_err",
        "rx_msg_tcp_d2a_skb_null_err",
        "rx_msg_tcp_redirect_skb_null_err",
        "rx_msg_udp_redirect_skb_null_err",
        "rx_dmi_msg_null_err",
        "rx_dmi_msg_priv_null_err",
        "rx_dmi_msg_check_err",

        "rx_sbr_in",
        "rx_sbr_tcp_in",
        "rx_sbr_tcp_out",
        "rx_sbr_tcp_errqueue_err",
        "rx_sbr_tcp_fallback_err",
        "rx_sbr_udp_in",
        "rx_sbr_udp_out",
        "rx_sbr_udp_out_err",
    };
    return info;
}

void dmi_msg_post_enqueue_inc(void)
{
    g_sbr_dfx_sock_info.dmi_msg_post_enqueue++;
}

void sysmem_msg_post_enqueue_inc(void)
{
    g_sbr_dfx_sock_info.sysmem_msg_post_enqueue++;
}

void dmi_msg_post_dequeue_inc(void)
{
    g_sbr_dfx_sock_info.dmi_msg_post_dequeue++;
}

void sysmem_msg_post_dequeue_inc(void)
{
    g_sbr_dfx_sock_info.sysmem_msg_post_dequeue++;
}

void dmi_low_event_cnt_inc(void)
{
    g_sbr_dfx_sock_info.dmi_low_event_cnt++;
}

void dmi_msg_send_fail_inc(void)
{
    g_sbr_dfx_sock_info.dmi_msg_send_fail++;
}

void sk_msg_queue_add_inc(void)
{
    g_sbr_dfx_sock_info.sk_msg_queue_add++;
}

void sk_msg_queue_remove_inc(void)
{
    g_sbr_dfx_sock_info.sk_msg_queue_remove++;
}

void conn_bypass_inc(void)
{
    g_sbr_dfx_sock_info.conn_bypass++;
}

void msg_queue_dfx_deinit(void)
{
    g_sbr_dfx_sock_info.dmi_msg_post_enqueue = 0;
    g_sbr_dfx_sock_info.sysmem_msg_post_enqueue = 0;
    g_sbr_dfx_sock_info.dmi_msg_post_dequeue = 0;
    g_sbr_dfx_sock_info.sysmem_msg_post_dequeue = 0;
    g_sbr_dfx_sock_info.dmi_low_event_cnt = 0;
    g_sbr_dfx_sock_info.dmi_msg_send_fail = 0;
    g_sbr_dfx_sock_info.sk_msg_queue_add = 0;
    g_sbr_dfx_sock_info.sk_msg_queue_remove = 0;
}

#endif
