/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#include "stack_time.h"
#include "securec.h"
#include "dfx/chr_stats.h"
#include "stack_log.h"

#ifdef CONFIG_DPA_CHR
#include "bsp_dpa_chr.h"

static chr_stats_cb g_chr_stats_cb = {0};
static sbr_chr_stats g_sbr_chr_stats = {0};
static bst_check_http_cb g_bst_http_cb = {0};
 
void register_chr_stats_cb(chr_stats_cb *cb)
{
    g_chr_stats_cb.all_link = cb->all_link;
    g_chr_stats_cb.migrate_succ = cb->migrate_succ;
    g_chr_stats_cb.migrate_fail = cb->migrate_fail;
    g_chr_stats_cb.migrate_revert = cb->migrate_revert;
    g_chr_stats_cb.sock_close = cb->sock_close;
    g_chr_stats_cb.opt_use = cb->opt_use;
    g_chr_stats_cb.msg_cost_time = cb->msg_cost_time;
    g_chr_stats_cb.conn_stats_report = cb->conn_stats_report;
    NS_DBG("register_chr_stats_cb succ");
}

void bst_register_http_cb(bst_check_http_cb* cb)
{
    g_bst_http_cb.sendmsg_http = cb->sendmsg_http;
    g_bst_http_cb.recvmsg_http = cb->recvmsg_http;
    NS_DBG("bst_register_http_cb success");
}

chr_stats_cb* get_chr_stats_cb()
{
    return &g_chr_stats_cb;
}

sbr_chr_stats* get_sbr_chr_stats()
{
    return &g_sbr_chr_stats;
}

void bst_tx_check_http_cb(sbr_socket_t *sk, struct sk_buff *skb)
{
    if (g_bst_http_cb.sendmsg_http != NULL) {
        g_bst_http_cb.sendmsg_http(sk, skb);
    }
}

void bst_rx_check_http_cb(sbr_socket_t *sk, struct sk_buff *skb)
{
    if (g_bst_http_cb.recvmsg_http != NULL) {
        g_bst_http_cb.recvmsg_http(sk, skb);
    }
}

void chr_conn_stats_report(u32 event_id, u16 stats_num, stat_unit *stats)
{
    if (get_chr_stats_cb()->conn_stats_report != NULL) {
        if (event_id != D2A_EVT_REQ_RTO && event_id != D2A_EVT_NIF_NO_DL_PKT && event_id != D2A_EVT_CONN_NO_DL_PKT) {
            return;
        }
        u32 len = stats_num * sizeof(chr_event_data_block);
        chr_event_data_block *blks = stack_malloc(len);
        if (blks == NULL) {
            NS_ERR("blks malloc failed, event id is %u, len is %u", event_id, len);
            return;
        }
        u16 i = 0;
        u16 index = 0;
        for (; i < CONN_STATS_MAX_TYPE; i++) {
            if (stats[i].cnt > 0) {
                if (strcpy_s((char *)blks[index].name, CHR_EVENT_NAME_SIZE, get_conn_stats_info()[i]) != EOK) {
                    NS_ERR("strcpy %s failed", get_conn_stats_info()[i]);
                    continue;
                }
                blks[index].cnt = stats[i].cnt;
                blks[index].pkts = stats[i].pkts;
                blks[index].bytes = stats[i].bytes;
                index++;
            }
            if (index == stats_num) {
                break;
            }
        }
        get_chr_stats_cb()->conn_stats_report((void *)blks, len, event_id, stats_num);
        stack_free(blks);
    }
}
#endif