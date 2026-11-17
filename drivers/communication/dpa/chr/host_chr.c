/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <securec.h>
#include <bsp_dmi.h>
#include <bsp_slice.h>
#include <bsp_print.h>
#include <bsp_dpa_chr.h>
#include "bsp_module_init.h"
#include "dpa_dmi.h"
#include "chr_stats.h"
#include "dpa_om_msg.h"
#include "dpa_chr_host_collec.h"
#ifdef CONFIG_CHR_NETLINK_MODULE
#include "dpa_chr_web_stat.h"
#endif
#include "dpa_chr_netlink.h"
#include "dpa_chr_info.h"
#include "host_chr.h"
#include "chr_pm.h"
#ifdef CONFIG_DPA_PROTO
#include <platform_include/basicplatform/linux/hck/net/hck_dpa.h>
#endif

struct dpa_host_chr_ctx g_dpa_host_chr_ctx = {0};
unsigned int g_dpa_chr_freq = 32768;
dpa_fw_chr_msg g_dpa_fw_chr_msg = {0};
dpa_fw_chr_stats_msg g_dpa_fw_chr_stats_msg = {0};
unsigned int g_dpa_chr_report_interval = 6 * 3600;                                 /* 默认6小时 */

static DEFINE_SPINLOCK(g_chr_event_lock);

#define DPA_CHR_REQUEST_INTERVAL_MS     (g_dpa_chr_report_interval * 1000)         /* 6h */
#define DPA_CHR_MIN_REPORT_EVENT_MS     (3600 * 1000)                              /* 1h */
#define DPA_CHR_EVENT_REPORT_MIN        5

#define FW_STATS_REQ                    1
#define BYTE_TO_MILLION_BYTE            (1024 * 1024)
#define DPA_CHR_STATS_MSG_COUNT         2                                          /* 当前chr统计量上报占用消息条数 */

#if DPA_CHR_DEBUG
void dpa_chr_report_set_in_second(unsigned int time)
{
    if (time <= 0) {
        time = 6 * 3600;
    }
    g_dpa_chr_report_interval = time;
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    mod_timer(&ctx->timer, jiffies + msecs_to_jiffies(DPA_CHR_REQUEST_INTERVAL_MS));
    dpa_pr_err("[dpa_chr] report_set_in_second: %u\n", time);
}

const char *g_dpa_opt[DPA_CHR_SOCK_OPT_LEVEL_MAX] = {
    "ip",
    "ipv6",
    "tcp",
    "udp",
    "socket",
    "unsupported",
};

void dpa_chr_sockopt_show(union dpa_opt *data, unsigned int len)
{
    union dpa_opt *opt = data;
    if (len != DPA_CHR_SOCK_OPT * sizeof(union dpa_opt)) {
        dpa_pr_err("[dpa_chr] opt collect len err, len = %u.\n", len);
        return;
    }
    int i;
    for (i = 0; i < DPA_CHR_SOCK_OPT; i++) {
        if (opt[i].opt != 0) {
            if (opt[i].u_bit.level >= DPA_CHR_SOCK_OPT_LEVEL_MAX) {
                dpa_pr_err("[dpa_chr] opt level err. [index, level]=[%u, %u]\n", i, opt[i].u_bit.level);
                continue;
            }
            dpa_pr_err("[dpa_chr] opt collect [idx, val, action, level, optname] = [%d, 0x%x, %d, %s, %d].\n",
                i, opt[i].opt, opt[i].u_bit.action, g_dpa_opt[opt[i].u_bit.level], opt[i].u_bit.optname);
        }
    }
}

void display_dpa_chr_info(void)
{
    struct dpa_chr_report *chr_report = NULL;
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    chr_report = &g_dpa_chr_report;
    int i, j;
    dpa_pr_err("[dpa_chr] display dpa chr info: report index = %u\n", ctx->report_cnt);
    dpa_pr_err("[dpa_chr] alive_time = %u, sum_link = %u, peak_link = %u, ",
                chr_report->alive_time, chr_report->sum_link, chr_report->peak_link);
    dpa_pr_err("[dpa_chr] peak_link: tcp = %u, udp = %u.\n", chr_report->peak_link_tcp, chr_report->peak_link_udp);
    dpa_pr_err("[dpa_chr] total bytes: [tcp_up, tcp_down, udp_up, udp_down] MB = [%u, %u, %u, %u] \n",
                chr_report->total_up_tcp_bytes, chr_report->total_down_tcp_bytes,
                chr_report->total_up_udp_bytes, chr_report->total_down_udp_bytes);
    dpa_pr_err("[dpa_chr] max_bridge_delay, uplink = %u, downlink = %u\n",
                chr_report->max_bridge_delay[1], chr_report->max_bridge_delay[0]);
    dpa_pr_err("[dpa_chr] total_web_num, %u\n", chr_report->web_info.total_web_num[0]);
    dpa_pr_err("[dpa_chr] total_websucc_num, %u\n", chr_report->web_info.total_websucc_num[0]);
    dpa_pr_err("[dpa_chr] total_webfail_num, %u\n", chr_report->web_info.total_webfail_num[0]);
    dpa_pr_err("[dpa_chr] web_delay, %u\n", chr_report->web_info.web_delay[0]);
    dpa_pr_err("[dpa_chr] http_get_delay, %u\n", chr_report->web_info.http_get_delay[0]);
    dpa_pr_err("[dpa_chr] http_get_num, %u\n", chr_report->web_info.http_get_num[0]);
    dpa_pr_err("[dpa_chr] dpa_web_byrat[0].fail_num, %u\n", chr_report->report_dpa_web_byrat[0].fail_num);
    dpa_pr_err("[dpa_chr] dpa_web_byrat[0].http_get_delay, %u\n", chr_report->report_dpa_web_byrat[0].http_get_delay);
    dpa_pr_err("[dpa_chr] dpa_web_byrat[0].http_get_num, %u\n", chr_report->report_dpa_web_byrat[0].http_get_num);
    dpa_pr_err("[dpa_chr] dpa_web_byrat[0].succ_num, %u\n", chr_report->report_dpa_web_byrat[0].succ_num);
    dpa_pr_err("[dpa_chr] dpa_web_byrat[0].web_delay, %u\n", chr_report->report_dpa_web_byrat[0].web_delay);
    for (i = 0; i < DPA_CHR_MAX_REPORT_APP_COUNT; i++) {
        dpa_pr_err("[dpa_chr] report_dpa_app_list app, add: %d\n", i);
        dpa_pr_err("[dpa_chr] [tcp_peak_link: %u, ", chr_report->report_dpa_app_list[i].app_peak_link_tcp);
        dpa_pr_err("[dpa_chr] udp_peak_link: %u, ", chr_report->report_dpa_app_list[i].app_peak_link_udp);
        dpa_pr_err("[dpa_chr] app_count, %u, ", chr_report->report_dpa_app_list[i].app_count);
        dpa_pr_err("[dpa_chr] app_alive_time, %u]\n", chr_report->report_dpa_app_list[i].app_alive_time);
        for (j = 0; j < IF_MAX_NUM; j++) {
            struct dpa_web_info *data = &chr_report->report_dpa_app_list[i].app_web_info;
            dpa_pr_err("[dpa_chr] [ifnum=%d, ", j);
            dpa_pr_err("[dpa_chr] total_web_num=%u, ", data->total_web_num[j]);
            dpa_pr_err("[dpa_chr] total_websucc_num=%u, ", data->total_websucc_num[j]);
            dpa_pr_err("[dpa_chr] total_webfail_num=%u, ", data->total_webfail_num[j]);
            dpa_pr_err("[dpa_chr] total_webnoack_num=%u, ", data->total_webnoack_num[j]);
            dpa_pr_err("[dpa_chr] web_delay=%u]\n", data->web_delay[j]);
        }
    }
    dpa_chr_sockopt_show(chr_report->sock_opt, sizeof(chr_report->sock_opt));
}

void display_chr_event_data(dpa_chr_event_msg *data, unsigned int block_size)
{
    int i;
    dpa_pr_err("[dpa_chr] event_id = %d, block_size = %u\n", data->header.event_id, block_size);
    for (i = 0; i < block_size; i++) {
        dpa_pr_err("[dpa_chr] event data block, name = %s\n", data->data_block[i].name);
        dpa_pr_err("[dpa_chr] data = [%d, %d, %d]\n", data->data_block[i].cnt, data->data_block[i].pkts, data->data_block[i].bytes);
    }
}

static inline void display_dubai_info(dpa_chr_dubai_info_s *chr_dubai_info)
{
    if (chr_dubai_info == NULL) {
        return;
    }
    dpa_pr_err("[dpa_chr] dubai info :\n");
    dpa_pr_err("[dpa_chr] dubai info wakeup cnt = %u\n", chr_dubai_info->pm_info.dpa_wakeup_cnt);
    dpa_pr_err("[dpa_chr] dubai info sleep time = %u\n", chr_dubai_info->pm_info.dpa_off_duration_in_ms);
    dpa_pr_err("[dpa_chr] dubai info wakeup time = %u\n", chr_dubai_info->pm_info.dpa_on_duration_in_ms);
    dpa_pr_err("[dpa_chr] dubai info freq time in ms = [%u, %u, %u, %u]\n", 
                chr_dubai_info->clk_info.dpa_chr_freq_duration_in_ms[0], chr_dubai_info->clk_info.dpa_chr_freq_duration_in_ms[1],
                chr_dubai_info->clk_info.dpa_chr_freq_duration_in_ms[2], chr_dubai_info->clk_info.dpa_chr_freq_duration_in_ms[3]);
    dpa_pr_err("[dpa_chr] dubai info irq no = [%u, %u, %u, %u]\n", 
                chr_dubai_info->pm_info.irq_no[0], chr_dubai_info->pm_info.irq_no[1],
                chr_dubai_info->pm_info.irq_no[2], chr_dubai_info->pm_info.irq_no[3]);
    dpa_pr_err("[dpa_chr] dubai info irq cnt = [%u, %u, %u, %u]\n", 
                chr_dubai_info->pm_info.irq_wakeup_cnt[0], chr_dubai_info->pm_info.irq_wakeup_cnt[1],
                chr_dubai_info->pm_info.irq_wakeup_cnt[2], chr_dubai_info->pm_info.irq_wakeup_cnt[3]);
}

static void display_dpa_sock_info(struct dpa_chr_host_info *host_info)
{
    if (host_info == NULL) {
        return;
    }
    dpa_pr_err("[dpa_chr] display dpa sock info: \n");
    dpa_pr_err("[dpa_chr] cur_link total=%u, tcp=%u, udp=%u\n",
                host_info->sock_info.cur_count, host_info->sock_info.cur_count_tcp, host_info->sock_info.cur_count_udp);
    dpa_pr_err("[dpa_chr] peak_link tcp=%u, udp=%u\n",
                host_info->sock_info.max_count_tcp, host_info->sock_info.max_count_udp);
    dpa_pr_err("[dpa_chr] sum_link = %u\n", host_info->sock_info.sum_count);
    dpa_pr_err("[dpa_chr] fail_link tcp=%u, udp=%u\n",
                host_info->chr_stat.fail_count_tcp, host_info->chr_stat.fail_count_udp);
    dpa_pr_err("[dpa_chr] revert_link tcp=%u, udp=%u\n",
                host_info->chr_stat.revert_count_tcp, host_info->chr_stat.revert_count_udp);
    dpa_pr_err("[dpa_chr] alive_time %u s\n", host_info->chr_stat.alive_time);
}
#endif

static inline unsigned int ceil_div(unsigned long long a, unsigned int b)
{
    if (a % b == 0) {
        return (unsigned int)(a / b);
    } else {
        return (unsigned int)(a / b) + 1;
    }
}

void dpa_fail_event_add(unsigned int fail_event, unsigned int fail_type)
{
    if (fail_event >= DPA_FAIL_EVENT_MAX || fail_type >= DPA_FAIL_TYPE_MAX) {
        return;
    }
    switch (fail_event) {
        case DPA_DMI_MSG_SEND_FAIL:
            g_dpa_host_chr_ctx.bridge_fail_sum++;
            g_dpa_host_chr_ctx.bridge_fail_reason_count[fail_type]++;
            break;
        default:
            break;
    }
    return;
}

static void dpa_chr_get_host_bridge_info(dpa_fw_chr_t *info)
{
    int i;
    info->bridge_fail_sum = g_dpa_host_chr_ctx.bridge_fail_sum;
    for (i = 0; i < DPA_FAIL_TYPE_MAX; i++) {
        info->bridge_fail_reason_count[i] = g_dpa_host_chr_ctx.bridge_fail_reason_count[i];
    }
    info->max_bridge_delay_host = g_dpa_host_chr_ctx.max_bridge_delay;
    g_dpa_host_chr_ctx.max_bridge_delay = 0;
    g_dpa_host_chr_ctx.bridge_fail_sum = 0;
    memset_s(g_dpa_host_chr_ctx.bridge_fail_reason_count, (sizeof(unsigned int) * DPA_FAIL_TYPE_MAX),
            0, (sizeof(unsigned int) * DPA_FAIL_TYPE_MAX));
}

void stack_msg_cost_time_cb(unsigned int cost_time)
{
    unsigned int cost_time_us;
    if (unlikely((cost_time / g_dpa_chr_freq) >= 1)) {
        g_dpa_host_chr_ctx.max_bridge_delay = 1000000;
        return;
    }
    cost_time_us = CHR_TS_TO_MICROSECOND * cost_time;
    if (g_dpa_host_chr_ctx.max_bridge_delay < cost_time_us) {
        g_dpa_host_chr_ctx.max_bridge_delay = cost_time_us;
    }
}

static void dpa_chr_combine_host_info(dpa_fw_chr_t *fw_info)
{
    struct dpa_chr_host_info *host_info = NULL;
    host_info = (struct dpa_chr_host_info *)kmalloc((sizeof(struct dpa_chr_host_info)), GFP_KERNEL);
    if (host_info == NULL) {
        dpa_pr_err("[dpa_chr] host_info kmalloc fail!\n");
        return;
    }
    get_dpa_chr_host_info(host_info);
    upload_dpa_chr_stat_info(host_info, fw_info);
    update_dpa_chr_app_web_info(host_info, fw_info);
#if DPA_CHR_DEBUG
    display_dpa_sock_info(host_info);
#endif
    if (memcpy_s(&g_last_dpa_chr_host_info, sizeof(struct dpa_chr_host_info), host_info, sizeof(struct dpa_chr_host_info))) {
        dpa_pr_err("[dpa_chr] last chr host info copy fail!\n");
    }
    kfree(host_info);
    return;
}

static void dpa_chr_combine_thp_info(dpa_fw_chr_stats_t *fw_info)
{
    struct dpa_chr_report *chr_report = &g_dpa_chr_report;
    int i;

    chr_report->total_up_tcp_bytes   = ceil_div(fw_info->total_stats.up_tcp_bytes, BYTE_TO_MILLION_BYTE);
    chr_report->total_down_tcp_bytes = ceil_div(fw_info->total_stats.down_tcp_bytes, BYTE_TO_MILLION_BYTE);
    chr_report->total_up_udp_bytes   = ceil_div(fw_info->total_stats.up_udp_bytes, BYTE_TO_MILLION_BYTE);
    chr_report->total_down_udp_bytes = ceil_div(fw_info->total_stats.down_udp_bytes, BYTE_TO_MILLION_BYTE);

    for (i = 0; i < DPA_CHR_MAX_REPORT_APP_COUNT; i++) {
        struct dpa_app_info *app_stats = &chr_report->report_dpa_app_list[i];
        app_stats->app_up_tcp_bytes   = ceil_div(fw_info->app_stats[i].up_tcp_bytes, BYTE_TO_MILLION_BYTE);
        app_stats->app_down_tcp_bytes = ceil_div(fw_info->app_stats[i].down_tcp_bytes, BYTE_TO_MILLION_BYTE);
        app_stats->app_up_udp_bytes   = ceil_div(fw_info->app_stats[i].up_udp_bytes, BYTE_TO_MILLION_BYTE);
        app_stats->app_down_udp_bytes = ceil_div(fw_info->app_stats[i].down_udp_bytes, BYTE_TO_MILLION_BYTE);
    }
    return;
}

static inline void dpa_report_chr(void)
{
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
#if DPA_CHR_DEBUG
    display_dpa_chr_info();
#endif
    dpa_chr_report_send();
    ctx->report_cnt++;
}

static int dpa_chr_report_proc(void)
{
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    if (ctx->chr_stats_msg_cnt < DPA_CHR_STATS_MSG_COUNT) {
        return 0;
    }

    dpa_chr_get_host_bridge_info(&g_dpa_fw_chr_msg.chr_report);
    dpa_chr_combine_host_info(&g_dpa_fw_chr_msg.chr_report);
    dpa_chr_combine_thp_info(&g_dpa_fw_chr_stats_msg.stats_info);
#ifdef CONFIG_CHR_NETLINK_MODULE
    upload_web_info();
#endif
    dpa_report_chr();
    return 0;
}

static int chr_stats_proc(unsigned char *data, unsigned int size)
{
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    if (data == NULL || size < CHR_MSG_SIZE(sizeof(dpa_fw_chr_stats_msg))) {
        dpa_pr_err("[dpa_chr] proc: msg data err!\n");
        return -1;
    }
    dpa_chr_msg *msg = (dpa_chr_msg *)data;
    if (msg->param.buffer_len > size) {
        dpa_pr_err("[dpa_chr] proc: msg len err!\n");
        return -1;
    }
    (void)memset_s(&g_dpa_fw_chr_stats_msg, sizeof(dpa_fw_chr_stats_msg),
                    0, sizeof(dpa_fw_chr_stats_msg));      /* 缓存清零 */
    if (memcpy_s(&g_dpa_fw_chr_stats_msg, sizeof(dpa_fw_chr_stats_msg), (dpa_fw_chr_stats_msg *)msg->buffer, sizeof(dpa_fw_chr_stats_msg))) {
        dpa_pr_err("[dpa_chr] stats msg copy fail!\n");
    }
    ctx->chr_stats_msg_cnt++;
    queue_work(ctx->report_wk, &ctx->report_work);

    return 0;
}

static int chr_proc(unsigned char *data, unsigned int size)
{
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    if (data == NULL || size < CHR_MSG_SIZE(sizeof(dpa_fw_chr_msg))) {
        dpa_pr_err("[dpa_chr] proc: msg data err!\n");
        return -1;
    }
    dpa_chr_msg *msg = (dpa_chr_msg *)data;
    if (msg->param.buffer_len != CHR_MSG_SIZE(sizeof(dpa_fw_chr_msg))) {
        dpa_pr_err("[dpa_chr] proc: msg len err!\n");
        return -1;
    }
    (void)memset_s(&g_dpa_fw_chr_msg, sizeof(dpa_fw_chr_msg), 0, sizeof(dpa_fw_chr_msg));      /* 缓存清零 */
    if (memcpy_s(&g_dpa_fw_chr_msg, sizeof(dpa_fw_chr_msg), (dpa_fw_chr_msg *)msg->buffer, sizeof(dpa_fw_chr_msg))) {
        dpa_pr_err("[dpa_chr] data copy fail\n");
    }
    ctx->chr_stats_msg_cnt++;
    queue_work(ctx->report_wk, &ctx->report_work);

    return 0;
}

int chr_event_check(void *data, unsigned int len, unsigned int event_id, unsigned int block_size)
{
    if (data == NULL) {
        dpa_pr_err("[dpa_chr] event check: msg data err!\n");
        return -1;
    }

    if ((block_size * sizeof(chr_event_data_block)) != len || (len + sizeof(dpa_chr_event_msg_header)) > 4080 ||
        block_size == 0) {
        dpa_pr_err("[dpa_chr] event check: msg len err, len = %u, block_size = %u!\n", len, block_size);
        return -1;
    }

    if (event_id >= (DPA_A2D_REVERT_NO_ERR_BASE + DPA_D2A_REVERT_NO_ERR_MAX)) {
        dpa_pr_err("[dpa_chr] event check: event [%u] invalid!\n", event_id);
        return -1;
    }

    unsigned int history_cnt;
    unsigned int report_flag = 0;
    unsigned int index;
    unsigned int cur_ms, report_ms, report_delay_ms;
    if (event_id >= DPA_A2D_REVERT_NO_ERR_BASE) {
        index = event_id - DPA_A2D_REVERT_NO_ERR_BASE;
        history_cnt = g_dpa_host_chr_ctx.save_revert_no_err_event[index];
        g_dpa_host_chr_ctx.save_revert_no_err_event[index]++;
    } else if (event_id >= DPA_A2D_REVERT_REASON_BASE && event_id < (DPA_A2D_REVERT_REASON_BASE + DPA_D2A_REVERT_REASON_MAX)) {
        index = event_id - DPA_A2D_REVERT_REASON_BASE;
        history_cnt = g_dpa_host_chr_ctx.save_revert_event[index];
        g_dpa_host_chr_ctx.save_revert_event[index]++;
    } else if (event_id >= DPA_A2D_FAIL_REASON_BASE && event_id < (DPA_A2D_FAIL_REASON_BASE + DPA_A2D_FAIL_REASON_MAX)){
        index = event_id - DPA_A2D_FAIL_REASON_BASE;
        history_cnt = g_dpa_host_chr_ctx.save_fail_event[index];
        g_dpa_host_chr_ctx.save_fail_event[index]++;
    } else {
        dpa_pr_err("[dpa_chr] event check: event [%u] not report!\n", event_id);
        return -1;
    }

    cur_ms = bsp_get_elapse_ms();
    report_ms = g_dpa_host_chr_ctx.last_event_report_ms;
    report_delay_ms = SUB_U32(cur_ms, report_ms);

    if (history_cnt >= DPA_CHR_EVENT_REPORT_MIN || report_delay_ms > DPA_CHR_MIN_REPORT_EVENT_MS) {
        report_flag = 1;
        g_dpa_host_chr_ctx.last_event_report_ms = cur_ms;
    }
    return report_flag;
}

void chr_event_msg_proc(void *data, unsigned int len, unsigned int event_id, unsigned int block_size)
{
    int ret;
    ret = chr_event_check(data, len, event_id, block_size);
    if (ret == 0) {
        dpa_pr_err("[dpa_chr] event msg proc: report delay!\n");
        return;
    } else if (ret == -1) {
        dpa_pr_err("[dpa_chr] event msg proc: param err!\n");
        return;
    }
    spin_lock_bh(&g_chr_event_lock);
    dpa_chr_event_msg *msg = kmalloc((len + sizeof(dpa_chr_event_msg_header)), GFP_KERNEL);
    if (msg == NULL) {
        dpa_pr_err("[dpa_chr] event msg proc: mem alloc fail!\n");
        spin_unlock_bh(&g_chr_event_lock);
        return;
    }
    chr_event_data_block *data_block = (chr_event_data_block *)data;
    msg->header.event_id= event_id;
    msg->header.data_block_size = block_size;
    if (memcpy_s(msg->data_block, len, data_block, len)) {
        dpa_pr_err("[dpa_chr] event msg proc: mem copy fail!\n");
        goto free;
    }

    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    (void)memcpy_s(msg->header.save_revert_event, DPA_D2A_REVERT_REASON_MAX * sizeof(unsigned short),
                   ctx->save_revert_event, DPA_D2A_REVERT_REASON_MAX * sizeof(unsigned short));
    (void)memcpy_s(msg->header.save_revert_no_err_event, DPA_D2A_REVERT_NO_ERR_MAX * sizeof(unsigned short),
                   ctx->save_revert_no_err_event, DPA_D2A_REVERT_NO_ERR_MAX * sizeof(unsigned short));
    (void)memcpy_s(msg->header.save_fail_event, DPA_A2D_FAIL_REASON_MAX * sizeof(unsigned short),
                   ctx->save_fail_event, DPA_A2D_FAIL_REASON_MAX * sizeof(unsigned short));

    if (dpa_chr_event_report_send(msg, len + sizeof(dpa_chr_event_msg_header))) {
        dpa_pr_err("[dpa_chr] event report send fail!\n");
        goto free;
    }
#if DPA_CHR_DEBUG
    display_chr_event_data(msg, block_size);
#endif
    (void)memset_s(ctx->save_revert_event, DPA_D2A_REVERT_REASON_MAX * sizeof(unsigned short),
                   0, DPA_D2A_REVERT_REASON_MAX * sizeof(unsigned short));
    (void)memset_s(ctx->save_revert_no_err_event, DPA_D2A_REVERT_NO_ERR_MAX * sizeof(unsigned short),
                   0, DPA_D2A_REVERT_NO_ERR_MAX * sizeof(unsigned short));
    (void)memset_s(ctx->save_fail_event, DPA_A2D_FAIL_REASON_MAX * sizeof(unsigned short),
                   0, DPA_A2D_FAIL_REASON_MAX * sizeof(unsigned short));

free:
    kfree(msg);
    spin_unlock_bh(&g_chr_event_lock);
    return;
}

static int chr_dubai_stats_proc(unsigned char *data, unsigned int size)
{
    if (data == NULL || size < CHR_MSG_SIZE(sizeof(dpa_chr_dubai_info_s))) {
        dpa_pr_err("dpa_chr dubai msg proc: msg data err!\n");
        return -1;
    }
    dpa_chr_msg *msg = (dpa_chr_msg *)data;
    if (msg->param.buffer_len > size) {
        dpa_pr_err("dpa_chr proc: msg len err!\n");
        return -1;
    }
    int len = msg->param.buffer_len -sizeof(chr_msg_param);
    dpa_dubai_report_send((dpa_chr_dubai_info_s *)msg->buffer, len);
#if DPA_CHR_DEBUG
    display_dubai_info((dpa_chr_dubai_info_s *)msg->buffer);
#endif
    return 0;
}

static int dpa_chr_cb(char *priv, unsigned int id, struct dmi_msg_data *msg)
{
    int ret;
    switch (id) {
        case DPA_CHR_FW_STATS_REPLY:
            ret = chr_stats_proc(msg->buf, msg->len);
            break;
        case DPA_CHR_FW_REPLY:
            ret = chr_proc(msg->buf, msg->len);
            break;
        case DPA_CHR_DUBAI_REPLY:
            ret = chr_dubai_stats_proc(msg->buf, msg->len);
            break;
        default:
            ret = -1;
            break;
    }
    return ret;
}

static void dpa_chr_err_cb(void *priv, unsigned int id, struct dmi_msg_data *msg)
{
    switch (id) {
        case DPA_CHR_FW_STATS_REPLY:
            chr_stats_proc(msg->buf, msg->len);
            break;
        case DPA_CHR_FW_REPLY:
            chr_proc(msg->buf, msg->len);
            break;
        case DPA_CHR_DUBAI_REPLY:
            chr_dubai_stats_proc(msg->buf, msg->len);
            break;
        default:
            break;
    }
    return;
}

int dpa_chr_msg_send(dpa_om_msg *info, unsigned int id)
{
    int ret;
    struct dmi_msg *msg = NULL;
    unsigned int size = info->param.buffer_len;
    unsigned int len = sizeof(struct dmi_msg) + size;

    msg = (struct dmi_msg *)kmalloc(len, GFP_KERNEL);
    if (msg == NULL) {
        return -1;
    }

    msg->plane = DMI_SERVICE_TYPE_COMM;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_CHR;
    msg->sub_id = id;
    msg->dmi_cb.cb = 0;
    msg->dmi_cb.cb_data = 0;

    msg->data.len = size;
    ret = memcpy_s(msg->data.buf, msg->data.len, info, size);
    if (ret) {
        dpa_pr_err("[dpa_chr] msg copy fail\n");
        goto end;
    }

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(struct dmi_msg) + msg->data.len);
    if (ret) {
        dpa_pr_err("[dpa_chr] msg send fail\n");
    }
end:
    kfree(msg);
    return ret;
}

static int dpa_chr_fw_request(int en)
{
    dpa_om_msg dpa_msg = {0};
    dpa_msg.param.buffer_len = (unsigned int)OM_MSG_SIZE(sizeof(ctrl_pkt));
    ctrl_pkt *msg = (ctrl_pkt *)dpa_msg.buffer;
    msg->report_enable = en;

    return dpa_chr_msg_send(&dpa_msg, DPA_CHR_FW_STATS_REQUEST);
}

int dpa_chr_dubai_request(int en)
{
    dpa_om_msg dpa_msg = {0};
    dpa_msg.param.buffer_len = (unsigned int)OM_MSG_SIZE(sizeof(ctrl_pkt));
    ctrl_pkt *msg = (ctrl_pkt *)dpa_msg.buffer;
    msg->report_enable = en;

    return dpa_chr_msg_send(&dpa_msg, DPA_CHR_DUBAI_REQUEST);
}

int dpa_chr_subscribe(void)
{
    int ret;
    struct dmi_client dpa_chr_client;
    ret = bsp_dmi_client_init(&dpa_chr_client);
    if (ret != 0) {
        dpa_pr_err("[dpa_chr] client_dmi init fail\n");
        return ret;
    }
    dpa_chr_client.dmi_id = DMI_SERVICE_CHR;
    dpa_chr_client.service_cb = dpa_chr_cb;
    dpa_chr_client.err_process = dpa_chr_err_cb;

    ret = bsp_dmi_client_register(&dpa_chr_client);
    if (ret != 0) {
        dpa_pr_err("[dpa_chr] client_dmi fail\n");
        return ret;
    }
    return ret;
}

void dpa_chr_host_info_init(void)
{
    chr_stats_cb dpa_chr_stats_cb;
    dpa_chr_stats_cb.all_link = dpa_all_link_cb;
    dpa_chr_stats_cb.migrate_succ = dpa_migrate_succ_cb;
    dpa_chr_stats_cb.migrate_fail = dpa_migrate_fail_cb;
    dpa_chr_stats_cb.migrate_revert = dpa_migrate_revert_cb;
    dpa_chr_stats_cb.sock_close = dpa_sock_close_cb;
    dpa_chr_stats_cb.opt_use = dpa_opt_use_cb;
    dpa_chr_stats_cb.msg_cost_time = stack_msg_cost_time_cb;
    dpa_chr_stats_cb.conn_stats_report = chr_event_msg_proc;
    register_chr_stats_cb(&dpa_chr_stats_cb);
}

void dpa_host_chr_transtimeout(struct timer_list *t)
{
    int ret;
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    mod_timer(&ctx->timer, jiffies + msecs_to_jiffies(DPA_CHR_REQUEST_INTERVAL_MS));
    ctx->chr_stats_msg_cnt = 0;
    ret = dpa_chr_fw_request(FW_STATS_REQ);
    if (ret) {
        dpa_pr_err("[dpa_chr] request fw stats send fail!\n");
    }
    return;
}

void dpa_chr_msg_work(struct work_struct *work)
{
    dpa_chr_report_proc();
    return;
}

int dpa_chr_init(void)
{
#ifdef CONFIG_LIBLINUX
    struct dpa_host_chr_ctx *ctx = &g_dpa_host_chr_ctx;
    INIT_WORK(&ctx->report_work, dpa_chr_msg_work);
    ctx->report_wk = alloc_ordered_workqueue("dpa_chr_work", 0);
    if (ctx->report_wk == NULL) {
        dpa_pr_err("[dpa_chr] alloc wk fail\n");
        return -1;
    }
    g_dpa_chr_freq = bsp_get_slice_freq();

    if (dpa_chr_subscribe()) {
        dpa_pr_err("[dpa_chr] subscribe init fail\n");
        destroy_workqueue(ctx->report_wk);
        ctx->report_wk = NULL;
        return -1;
    }
    dpa_chr_host_info_init();
#ifdef CONFIG_CHR_NETLINK_MODULE
    dpa_web_chr_init();
#endif
    dpa_chr_netlink_init();

    timer_setup(&ctx->timer, dpa_host_chr_transtimeout, 0);
    mod_timer(&ctx->timer, jiffies + msecs_to_jiffies(DPA_CHR_REQUEST_INTERVAL_MS));

    REGISTER_HCK_VH(acore_link_stat, acore_link_stat);
    ctx->last_event_report_ms = 0xF0000000;
    dpa_pr_err("[dpa_chr] init success.\n");
#endif
    return 0;
}
EXPORT_SYMBOL(dpa_chr_init);

#if DPA_CHR_DEBUG
chr_event_data_block data = {.name = "test", .cnt = 101, .pkts = 202, .bytes = 123456};

void dpa_chr_event_test(int err_code)
{
    chr_event_msg_proc(&data, sizeof(chr_event_data_block), err_code, 1);
}

void dpa_sock_opt_test(u8 offload, u8 action, u8 level, u8 optname)
{
    dpa_pr_err("[dpa_chr] dpa_sock_opt_test [offload, action, level, optname] = [%u, %u, %u, %u]\n",
           offload, action, level, optname);
    struct inet_sock sock = {0};
    sock.dpa_opt = offload;
    dpa_opt_use_cb((struct sock *)&sock, level, optname, action);
    struct dpa_host_chr_stat *chr_stat = &g_dpa_chr_host_info.chr_stat;
    dpa_chr_sockopt_show(chr_stat->opt, sizeof(chr_stat->opt));
}
#endif

_Static_assert(sizeof(struct dpa_chr_report) <= 4080, "size of dpa_chr_report exceeds limit");
