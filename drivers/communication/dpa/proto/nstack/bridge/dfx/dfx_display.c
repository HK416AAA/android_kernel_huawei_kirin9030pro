/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include <net/net_namespace.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include "socket/sbr_prot_com.h"
#include "global_res_stats.h"
#include "proto_conn_stats.h"
#include "dfx_display.h"

static void bridge_dfx_display(struct seq_file *m)
{
#if SPL_STATS
    sbr_dfx_sock_info *info = get_dfx_sock_info();
    seq_printf(m, "total sock:%llu\n", (u64)dmm_atomic64_get(&info->tot_sock));
    seq_printf(m, "cur total sock:%u\n", (u32)dmm_atomic_read(&info->cur_tot_sock));
    seq_printf(m, "migrate sock:%u\n", (u32)dmm_atomic_read(&info->migrate_sock));
    seq_printf(m, "migrate_a2d_request:%u\n", (u32)dmm_atomic_read(&info->migrate_a2d_request));
    seq_printf(m, "migrate_a2d_success:%u\n", (u32)dmm_atomic_read(&info->migrate_a2d_success));
    seq_printf(m, "migrate_a2d_failed:%u\n", (u32)dmm_atomic_read(&info->migrate_a2d_failed));
    seq_printf(m, "migrate_a2d_not_support:%u\n", (u32)dmm_atomic_read(&info->migrate_a2d_not_support));
    seq_printf(m, "migrate_a2d_msg_success:%u\n", (u32)dmm_atomic_read(&info->migrate_a2d_msg_success));
    seq_printf(m, "migrate_a2d_msg_failed:%u\n", (u32)dmm_atomic_read(&info->migrate_a2d_msg_failed));
    seq_printf(m, "migrate_d2a_request:%u\n", (u32)dmm_atomic_read(&info->migrate_d2a_request));
    seq_printf(m, "migrate_d2a_success:%u\n", (u32)dmm_atomic_read(&info->migrate_d2a_success));
    seq_printf(m, "migrate_d2a_failed:%u\n", (u32)dmm_atomic_read(&info->migrate_d2a_failed));
    seq_printf(m, "migrate_d2a_msg_success:%u\n", (u32)dmm_atomic_read(&info->migrate_d2a_msg_success));
    seq_printf(m, "migrate_d2a_msg_failed:%u\n", (u32)dmm_atomic_read(&info->migrate_d2a_msg_failed));
    seq_printf(m, "msg_post_succ:%u\n", (u32)dmm_atomic_read(&info->msg_post_succ));
    seq_printf(m, "msg_post_failed:%u\n", (u32)dmm_atomic_read(&info->msg_post_failed));
    seq_printf(m, "msg_handle:%u\n", info->msg_handle);
    seq_printf(m, "conn_tx_buf_alloc:%u\n", (u32)dmm_atomic_read(&info->conn_tx_buf_alloc));
    seq_printf(m, "conn_tx_buf_revert:%u\n", (u32)dmm_atomic_read(&info->conn_tx_buf_revert));
    seq_printf(m, "conn_tx_buf_post:%u\n", (u32)dmm_atomic_read(&info->conn_tx_buf_post));
    seq_printf(m, "conn_tx_buf_post_fail:%u\n", (u32)dmm_atomic_read(&info->conn_tx_buf_post_fail));
    seq_printf(m, "conn_tx_buf_enq:%u\n", info->conn_tx_buf_enq);
    seq_printf(m, "global_tx_buf_alloc:%u\n", (u32)dmm_atomic_read(&info->global_tx_buf_alloc));
    seq_printf(m, "global_tx_buf_revert:%u\n", (u32)dmm_atomic_read(&info->global_tx_buf_revert));
    seq_printf(m, "global_tx_buf_post:%u\n", (u32)dmm_atomic_read(&info->global_tx_buf_post));
    seq_printf(m, "global_tx_buf_post_fail:%u\n", (u32)dmm_atomic_read(&info->global_tx_buf_post_fail));
    seq_printf(m, "global_tx_buf_enq:%u\n", info->global_tx_buf_enq);
    seq_printf(m, "global_tx_buf_num:%d\n", dmm_atomic_read(get_global_tx_num()));
    seq_printf(m, "sbr_dra_alloc:%u\n", (u32)dmm_atomic_read(&info->sbr_dra_alloc));
    seq_printf(m, "sbr_dra_unmap_reuse:%u\n", (u32)dmm_atomic_read(&info->sbr_dra_unmap_reuse));
    seq_printf(m, "sbr_dra_free:%u\n", (u32)dmm_atomic_read(&info->sbr_dra_free));
    seq_printf(m, "sbr_dra_put_page:%u\n", (u32)dmm_atomic_read(&info->sbr_dra_put_page));
    seq_printf(m, "sbr_dra_free_err:%u\n", (u32)dmm_atomic_read(&info->sbr_dra_free_err));
    seq_printf(m, "dfx_version:%u\n", info->dfx_version);
    seq_printf(m, "dmi_msg_post_enqueue:%u\n", info->dmi_msg_post_enqueue);
    seq_printf(m, "sysmem_msg_post_enqueue:%u\n", info->sysmem_msg_post_enqueue);
    seq_printf(m, "dmi_msg_post_dequeue:%u\n", info->dmi_msg_post_dequeue);
    seq_printf(m, "sysmem_msg_post_dequeue:%u\n", info->sysmem_msg_post_dequeue);
    seq_printf(m, "dmi_low_event_cnt:%u\n", info->dmi_low_event_cnt);
    seq_printf(m, "dmi_msg_send_fail:%u\n", info->dmi_msg_send_fail);
    seq_printf(m, "sk_msg_queue_add:%u\n", info->sk_msg_queue_add);
    seq_printf(m, "sk_msg_queue_remove:%u\n", info->sk_msg_queue_remove);
    seq_printf(m, "global_rx_dra_alloc_num:%u\n", (u32)get_global_rx_dra_alloc_num());
    seq_printf(m, "conn_bypass:%u\n", info->conn_bypass);
#else
    seq_printf(m, "do not support SPL_STATS\n");
#endif
}

static void bridge_netstat(struct seq_file *m, u32 level)
{
    s32 fd;
    seq_printf(m, "[fd,sip,dip][sport,dport,protocol]\n");
    for (fd = 1; fd < SOCKET_NUM + 1; fd++) {
        sbr_socket_t *sock = get_dpa_sk(fd);
        if (sock == NULL) {
            continue;
        }
        struct sock *sk = sock->sk;
        ip_addr_t sip;
        ip_addr_t rip;
        u16 sport;
        u16 dport;
        bool is_v6 = sbr_sk_isv6(sock) && !sock->is_mapped_v6;
        get_sk_addr(sk, false, &sip);
        get_sk_addr(sk, true, &rip);
        sport = sk->sk_num;
        dport = ntohs(sk->sk_dport);

        seq_printf(m, "[%d,%s,%s] [%u,%u,%u]\n", fd, ip_fuzzy_x(is_v6, &sip), ip_fuzzy_x(is_v6, &rip),
        (u32)sport, (u32)dport, sk->sk_protocol);

        if (level == 1) {
            stat_unit *stats = sock->stats;
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
                    seq_printf(m, "fd=%d,[%u]:%s\n", fd, i, buffer);
                } else {
                    seq_printf(m, "fd=%d,[%u]:%u in/out\n", fd, i, len);
                }
                i++;
            }
            seq_printf(m, "fd=%d,tx_sbuf_num=%u,tx_dra_alloc_num=%u\n", fd, sock->tx_sbuf_num, sock->dra_alloc_num);
        }

        put_dpa_sk(sock);
    }
}

static void bridge_netstat_s(struct seq_file *m)
{
    dfx_stat_unit *stats = get_dfx_sock_info()->stats;
    u16 index = 0;
    u16 i = 1;
    while (index < GLOBAL_STAT_TYPE_MAX) {
        char buffer[STRING_LEN] = {0};
        u32 len = 0;
        for (; index < GLOBAL_STAT_TYPE_MAX; index++) {
            if ((u64)dmm_atomic64_get(&stats[index].cnt) == 0) {
                continue;
            }
            int ret = snprintf_s(buffer + len, sizeof(buffer) - len, sizeof(buffer) - len - 1, "%s=[%llu,%llu,%llu],",
                get_global_stats_info()[index], (u64)dmm_atomic64_get(&stats[index].cnt),
                (u64)dmm_atomic64_get(&stats[index].pkts), (u64)dmm_atomic64_get(&stats[index].bytes));
            if (ret > 0) {
                len += (u32)ret;
            } else {
                break;
            }
        }
        if ((len > 0) && (len < STRING_LEN)) {
            buffer[len - 1] = '\0';
            seq_printf(m, "[%u]:%s\n", i, buffer);
        } else {
            seq_printf(m, "[%u]:%u in/out\n", i, len);
        }
        i++;
    }
}

static int bridge_dfx_info_show(struct seq_file *m, void *v)
{
    (void)v;
    seq_printf(m, "----bridge_dfx_display----\n");
    bridge_dfx_display(m);
    seq_printf(m, "----bridge_netstat----\n");
    bridge_netstat(m, 1);
    seq_printf(m, "----bridge_netstat_s----\n");
    bridge_netstat_s(m);
    return 0;
}

int bridge_dfx_info_init(void)
{
    struct proc_dir_entry *entry;

    entry = proc_create_net_single("bridge_dfx_info", 0444, init_net.proc_net, bridge_dfx_info_show, NULL);
    if (!entry) {
        NS_ERR("Failed to create /proc/bridge_dfx_info");
        return -1;
    }

    NS_INF("bridge_dfx_info proc file created");
    return 0;
}
