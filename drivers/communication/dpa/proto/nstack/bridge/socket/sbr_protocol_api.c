/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#include "socket/sbr_misc.h"
#include "spl_common_opt.h"
#include "msg/bridge_msg_producer.h"
#include "sbr_res_mgr.h"
#include "sbr_udp.h"
#include "sbr_tcp.h"
#include "socket/sbr_protocol_api.h"

#ifndef SOCK_MAX
#define SOCK_MAX ((s32)SOCK_PACKET + 1)
#endif

static s32 sbr_get_inet_fdopt_check(s32 domain, s32 type)
{
    if (domain != AF_INET) {
#if SPL_IPV6
        if (domain != AF_INET6)
#endif
        {
            NS_ERR("domain is not AF_INET]domain=%d", domain);
            return -1;
        }
    }

    if (((u32)type & (~((u32)O_NONBLOCK | (u32)SOCK_CLOEXEC))) >= (u32)SOCK_MAX) {
        return -1;
    }

    return 0;
}

sbr_fdopt *sbr_get_fdopt(int32_t domain, int32_t type)
{
    if (sbr_get_inet_fdopt_check(domain, type) != 0) {
        return NULL;
    }

    sbr_fdopt *fdopt = NULL;
    switch ((u32)type & (~((u32)O_NONBLOCK | (u32)SOCK_CLOEXEC))) {
        case SOCK_DGRAM:
            fdopt = sbr_get_udp_fdopt();
            break;
        case SOCK_STREAM:
            fdopt = sbr_get_tcp_fdopt();
            break;
        default:
            NS_DBG("type is unknown]type=%d", type);
            return NULL;
    }

    return fdopt;
}

const char **get_sbr_conn_stats_info(void)
{
    static const char *info[SBR_CONN_STATS_MAX_TYPE] = {
        "tx_app_in",
        "tx_app_out",
        "tx_app_err",
        "tx_msg_in",
        "tx_msg_out",
        "tx_msg_post_err",

        "rx_msg_in",
        "rx_msg_out",
        "rx_msg_from_dpa_err",
        "rx_msg_skb_null_err",
        "rx_udp_msg_skb_null_err",
        "rx_tcp_backlog_in",
        "rx_tcp_backlog_out",
        "rx_tcp_backlog_msg_malloc_err",
        "rx_tcp_backlog_copy_hdr_err",
        "rx_tcp_backlog_post_err",
        "rx_app_in",
        "rx_app_out",
        "rx_app_udp_out_err",
        "rx_app_tcp_errqueue_err",
        "rx_app_tcp_fallback_err",

    };
    return info;
}
