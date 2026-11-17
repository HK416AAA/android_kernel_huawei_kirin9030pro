/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#include "socket/sbr_prot_com.h"
#include "ip_addr.h"
#include "dfx/conn_stats.h"
#include "runtime.h"

#if SPL_STATS

/* report buff size is 976 bytes, need to report in batches */
#define BRIDGE_REPORT_BUFFER_SIZE 976
#define NETSTAT_INFO_REPORT_NUM_ONE_TURN (BRIDGE_REPORT_BUFFER_SIZE / sizeof(struct conn_stats))
struct conn_stats g_conn_stats[NETSTAT_INFO_REPORT_NUM_ONE_TURN];
static int g_om_fd = 1;

struct conn_stats *get_dfx_conn_stats_info(void)
{
    return g_conn_stats;
}

unsigned int get_dfx_conn_stats_size(void)
{
    return sizeof(g_conn_stats);
}

static void copy_dfx_info_to_conn_stats(s32 num)
{
    sbr_socket_t *sock = get_dpa_sk(g_om_fd);
    if (sock == NULL) {
        return;
    }
    struct sock *sk = sock->sk;
    g_conn_stats[num].fd = g_om_fd;
    ip_addr_t sip;
    ip_addr_t rip;
    get_sk_addr(sk, false, &sip);
    get_sk_addr(sk, true, &rip);

    if (sbr_sk_isv6(sock) && !sock->is_mapped_v6) {
        g_conn_stats[num].sip_h = SPL_IP6_ADDR_BLOCK1(&sip.ip6);
        g_conn_stats[num].sip_l = SPL_IP6_ADDR_BLOCK2(&sip.ip6);
        g_conn_stats[num].rip_h = SPL_IP6_ADDR_BLOCK1(&rip.ip6);
        g_conn_stats[num].rip_l = SPL_IP6_ADDR_BLOCK2(&rip.ip6);
    } else {
        g_conn_stats[num].sip_h = ipv4_addr1_u16(&sip.addr);
        g_conn_stats[num].sip_l = ipv4_addr2_u16(&sip.addr);
        g_conn_stats[num].rip_h = ipv4_addr1_u16(&rip.addr);
        g_conn_stats[num].rip_l = ipv4_addr2_u16(&rip.addr);
    }
    g_conn_stats[num].protocol = (u8)sk->sk_protocol;
    g_conn_stats[num].sport = sk->sk_num;
    g_conn_stats[num].dport = ntohs(sk->sk_dport);

    stat_unit *stats = sock->stats;
    (void)memcpy_s(g_conn_stats[num].stats, SBR_CONN_STATS_MAX_TYPE * sizeof(stat_unit), stats,
        SBR_CONN_STATS_MAX_TYPE * sizeof(stat_unit));

    put_dpa_sk(sock);
}

void bridge_om_cb(void)
{
    s32 num;
    for (num = 0; num < NETSTAT_INFO_REPORT_NUM_ONE_TURN; num++) {
        copy_dfx_info_to_conn_stats(num);
        g_om_fd++;
        if (g_om_fd > SOCKET_NUM) {
            g_om_fd = 1;
            break;
        }
    }
}
#endif

void conn_stats_print(sbr_socket_t *sk)
{
    struct sock *lsk = sk->sk;
    ip_addr_t sip;
    ip_addr_t rip;
    get_sk_addr(lsk, false, &sip);
    get_sk_addr(lsk, true, &rip);

    NS_INF("sk_id=%lu,fd=%d,sip=%s,dip=%s,sport=%hu,dport=%hu,%s,d2a_evt=%d,sk_dra_alloc_num=%u", sk->sk_id,
        sk->fd, ip_safety_x(&sip), ip_safety_x(&rip),
        lsk->sk_num, ntohs(lsk->sk_dport), (lsk->sk_protocol == IPPROTO_TCP ? "tcp" : "udp"), sk->d2a_event,
        sk->dra_alloc_num);

    stat_unit *stats = sk->stats;
    u16 index = 0;
    u16 i = 1;
    while (index < SBR_CONN_STATS_MAX_TYPE) {
        char buffer[STRING_LEN] = {0};
        u32 len = 0;
        for (; index < SBR_CONN_STATS_MAX_TYPE; index++) {
            if (stats[index].cnt == 0) {
                continue;
            }
            int ret = snprintf_s(buffer + len, sizeof(buffer) - len, sizeof(buffer) - len - 1, "%s=[%u,%u,%u],",
                get_sbr_conn_stats_info()[index], stats[index].cnt, stats[index].pkts, stats[index].bytes);
            if (ret > 0) {
                len += (u32)ret;
            } else {
                break;
            }
        }
        if ((len > 0) && (len < STRING_LEN)) {
            buffer[len - 1] = '\0';
            NS_INF("sk_id=%lu,fd=%d,ACPU stats[%u]:%s", sk->sk_id, sk->fd, i, buffer);
        } else {
            NS_INF("sk_id=%lu,fd=%d,ACPU stats[%u]:%u in/out", sk->sk_id, sk->fd, i, len);
        }
        i++;
    }

    dpa_event_report(sk, SOCKET_D2A);
}

void dpa_udp_conn_stats_print(u64 sk_id, s32 fd, u16 stats_num, conn_stat_tv *stats, msg_dpa_conn_stats_report *report)
{
    if (report != NULL) {
        NS_INF("sk_id=%lu,fd=%d,sip=%s,dip=%s,sport=%hu,dport=%hu,%s", sk_id, fd,
            ip_safety_x(&report->sip), ip_safety_x(&report->rip),
            report->sport, report->dport, (report->is_udp ? "udp" : "tcp"));
    }

    u16 index = 0;
    u16 i = 1;
    while (index < stats_num) {
        char buffer[STRING_LEN] = {0};
        u32 len = 0;
        for (; index < stats_num; index++) {
            if (stats[index].type >= CONN_STATS_MAX_TYPE) {
                NS_ERR("sk_id=%lu,fd=%d,DPA stats[%d], stats_num:%d, Invalid stats type[%d]",
                    sk_id, fd, i, stats_num, stats[index].type);
                break;
            }
            int ret = snprintf_s(buffer + len, sizeof(buffer) - len, sizeof(buffer) - len - 1, "%s=[%u,%u,%u],",
                get_conn_stats_info()[stats[index].type], stats[index].cnt, stats[index].pkts, stats[index].bytes);
            if (ret > 0) {
                len += ret;
            } else {
                break;
            }
        }
        if ((len > 0) && (len < STRING_LEN)) {
            buffer[len - 1] = '\0';
            NS_INF("sk_id=%lu,fd=%d,DPA stats[%u]:%s", sk_id, fd, i, buffer);
        } else {
            NS_INF("sk_id=%lu,fd=%d,DPA stats[%u]:%u in/out", sk_id, fd, i, len);
        }
        i++;
    }
}
