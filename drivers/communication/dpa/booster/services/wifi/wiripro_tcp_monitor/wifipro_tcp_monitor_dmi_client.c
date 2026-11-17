/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This file is the impl file of wifipro tcp monitor dmi client.
 * Author: wangdingbang
 * Create: 2025-04-26
 */
#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <hwnet/ipv4/wifipro_tcp_monitor_dmi_client.h>
#include <securec.h>
#include "booster_features.h"
#include "booster_dmi_client.h"
#include "bsp_slice.h"
#include "bsp_print.h"

#define WIFIPRO_CONG_ARRAY 5
#define WIFIPRO_MAX_CA_NAME 12
#define SLEEP_TIME 20
#define MAX(x, y) ((x) > (y) ? (x) : (y))

enum uid_tcp_stat_type {
    UID_TCP_WLAN_STAT,
    UID_TCP_RMNET_STAT,
    UID_TCP_HIDATA_STAT,
    UID_TCP_STAT_TYPE_NUM
};

enum rtt_second_stat_type {
    RTT_SECOND_WLAN_STAT,
    RTT_SECOND_RMNET_STAT,
    RTT_SECOND_STAT_TYPE_NUM
};

struct wifipro_nl_packet_msg {
    unsigned int msg_from; /* kernel notify or app query */
    unsigned int rtt; /* average rtt within last 3 seconds */
    unsigned int rtt_pkts; /* packet counts of rtt calculation */
    unsigned int rtt_when; /* when recorded rtt */
    unsigned int congestion; /* congestion stat */
    unsigned int cong_when; /* when recorded congestion */
    unsigned int tcp_quality; /* tcp quality */
    unsigned int tcp_tx_pkts;
    unsigned int tcp_rx_pkts;
    unsigned int tcp_retrans_pkts;
};

struct wifipro_congestion_socket {
    char state_name[WIFIPRO_MAX_CA_NAME];
    unsigned int dst_addr;
    unsigned int dst_port;
    unsigned int amount;
    unsigned long long when;
};

// dmi tmp object pointer
static struct wifipro_nl_packet_msg *g_tcp_monitor_packet = NULL;
static DEFINE_MUTEX(g_tcp_monitor_packet_lock);
static struct wifipro_congestion_socket *g_cong_packet = NULL;
static DEFINE_MUTEX(g_cong_packet_lock);
static struct dpa_wifipro_tcp_stat *g_tcp_stat = NULL;
static DEFINE_MUTEX(g_tcp_stat_lock);
static struct dpa_uid_tcp_stat *g_uid_tcp_stat_packet = NULL;
static int g_curent_uid_tcp_stat_type = UID_TCP_WLAN_STAT;
static DEFINE_MUTEX(g_uid_tcp_stat_packet_lock);
struct dpa_rtt_second_stat *g_rtt_second_stat_packet = NULL;
static int g_curent_rtt_second_stat_type = RTT_SECOND_WLAN_STAT;
static DEFINE_MUTEX(g_rtt_second_stat_packet_lock);
static int *g_unknown_dev_count = NULL;
static int *g_unknown_segs_count = NULL;
static DEFINE_MUTEX(g_unknown_count_lock);

static bool start_dpa_monitor(bool is_beta)
{
    char param[] = { (is_beta ? 1 : 0) };
    int ret = booster_dpa_request_async(WIFIPRO_TCP_MONITOR_FEATURE, WIFIPRO_START_MONITOR, param, sizeof(param));
        return ret == 0;
}

static void merge_wifipro_nl_packet_msg(struct wifipro_nl_packet_msg *dest, struct wifipro_nl_packet_msg *addend)
{
    if (dest == NULL || addend == NULL) {
        return;
    }
    dest->rtt = (dest->rtt + addend->rtt) / 2;
    dest->rtt_pkts += addend->rtt_pkts;
    dest->rtt_when = MAX(dest->rtt_when, addend->rtt_when);
    dest->congestion |= addend->congestion;
    dest->cong_when = MAX(dest->rtt_when, addend->cong_when);
    dest->tcp_tx_pkts += addend->tcp_tx_pkts;
    dest->tcp_rx_pkts += addend->tcp_rx_pkts;
    dest->tcp_retrans_pkts += addend->tcp_retrans_pkts;
}

static bool append_dpa_tcp_monitor_stat(struct wifipro_nl_packet_msg *packet)
{
    struct wifipro_nl_packet_msg tmp;
    (void)memset_s(&tmp, sizeof(tmp), 0, sizeof(tmp));
    mutex_lock(&g_tcp_monitor_packet_lock);
    g_tcp_monitor_packet = &tmp;
    int ret = booster_dpa_request_async(WIFIPRO_TCP_MONITOR_FEATURE, WIFIPRO_GET_MSG, NULL, 0);
    if (ret == 0) {
        msleep(SLEEP_TIME);
        merge_wifipro_nl_packet_msg(packet, g_tcp_monitor_packet);
    }
    g_tcp_monitor_packet = NULL;
    mutex_unlock(&g_tcp_monitor_packet_lock);
    return ret == 0;
}

static bool get_dpa_cong_stat(struct wifipro_congestion_socket *packet)
{
    if (packet == NULL) {
        return false;
    }
    (void)memset_s(packet, sizeof(*packet) * WIFIPRO_CONG_ARRAY, 0, sizeof(*packet) * WIFIPRO_CONG_ARRAY);
    mutex_lock(&g_cong_packet_lock);
    g_cong_packet = packet;
    int ret = booster_dpa_request_async(WIFIPRO_TCP_MONITOR_FEATURE, WIFIPRO_GET_CONG, NULL, 0);
    if (ret == 0) {
        msleep(SLEEP_TIME);
    }
    g_cong_packet = NULL;
    mutex_unlock(&g_cong_packet_lock);
    return ret == 0;
}

static bool get_dpa_wifipro_tcp_stat(struct dpa_wifipro_tcp_stat *packet)
{
    if (packet == NULL) {
        return false;
    }
    (void)memset_s(packet, sizeof(*packet), 0, sizeof(*packet));
    mutex_lock(&g_tcp_stat_lock);
    g_tcp_stat = packet;
    int ret = booster_dpa_request_async(WIFIPRO_TCP_MONITOR_FEATURE, WIFIPRO_GET_MIB, NULL, 0);
    if (ret == 0) {
        msleep(SLEEP_TIME);
    }
    g_tcp_stat = NULL;
    mutex_unlock(&g_tcp_stat_lock);
    return ret == 0;
}

static bool get_dpa_uid_tcp_stat(struct dpa_uid_tcp_stat *packet)
{
    if (packet == NULL) {
        return false;
    }
    (void)memset_s(packet, sizeof(struct dpa_uid_tcp_stat), 0, sizeof(struct dpa_uid_tcp_stat));
    mutex_lock(&g_uid_tcp_stat_packet_lock);
    g_uid_tcp_stat_packet = packet;
    g_curent_uid_tcp_stat_type = 0;
    int i, ret = 0;
    for (i = 0; i < UID_TCP_STAT_TYPE_NUM && ret == 0; i++) {
        char tag[] = { i };
        ret = booster_dpa_request_async(WIFIPRO_TCP_MONITOR_FEATURE, WIFIPRO_GET_UID_STAT, tag, sizeof(tag));
        if (ret) {
            break;
        }
        msleep(SLEEP_TIME);
    }
    g_uid_tcp_stat_packet = NULL;
    mutex_unlock(&g_uid_tcp_stat_packet_lock);
    return ret == 0;
}

static bool get_dpa_rtt_second_stat(struct dpa_rtt_second_stat *packet)
{
    if (packet == NULL) {
        return false;
    }
    (void)memset_s(packet, sizeof(struct dpa_rtt_second_stat), 0, sizeof(struct dpa_rtt_second_stat));
    mutex_lock(&g_rtt_second_stat_packet_lock);
    g_rtt_second_stat_packet = packet;
    g_curent_rtt_second_stat_type = 0;
    int i, ret = 0;
    for (i = 0; i < RTT_SECOND_STAT_TYPE_NUM && ret == 0; i++) {
        char tag[] = { i };
        ret = booster_dpa_request_async(WIFIPRO_TCP_MONITOR_FEATURE, WIFIPRO_GET_RTT_STAT, tag, sizeof(tag));
        if (ret) {
            break;
        }
        msleep(SLEEP_TIME);
    }
    g_rtt_second_stat_packet = NULL;
    mutex_unlock(&g_rtt_second_stat_packet_lock);
    return ret == 0;
}

static bool get_dpa_unknown_counts(int *unknown_dev_count, int *unknown_segs_count)
{
    if (unknown_dev_count != NULL) {
        *unknown_dev_count = 0;
    }
    if (unknown_segs_count != NULL) {
        *unknown_segs_count = 0;
    }
    mutex_lock(&g_unknown_count_lock);
    g_unknown_dev_count = unknown_dev_count;
    g_unknown_segs_count = unknown_segs_count;
    int ret = booster_dpa_request_async(WIFIPRO_TCP_MONITOR_FEATURE, WIFIPRO_GET_UNKNOWN_COUNT, NULL, 0);
    if (ret == 0) {
        msleep(SLEEP_TIME);
    }
    g_unknown_dev_count = NULL;
    g_unknown_segs_count = NULL;
    mutex_unlock(&g_unknown_count_lock);
    return ret == 0;
}

static void handle_get_msg_response(unsigned char *data, unsigned int len)
{
    pr_info("WIFIPRO_GET_MSG handle_get_msg_response");
    if (g_tcp_monitor_packet == NULL || data == NULL) {
        return;
    }
    if (len != sizeof(*g_tcp_monitor_packet)) {
        pr_err("handle_get_msg_response recv invalid len = %u", len);
        return;
    }
    int ret = memcpy_s(g_tcp_monitor_packet, sizeof(*g_tcp_monitor_packet), data, len);
    if (ret != EOK) {
        pr_err("handle_get_msg_response memcpy_s failed!");
        return;
    }
}

static void handle_get_cong_response(unsigned char *data, unsigned int len)
{
    if (g_cong_packet == NULL || data == NULL) {
        return;
    }
    if (len != sizeof(*g_cong_packet) * WIFIPRO_CONG_ARRAY) {
        return;
    }
    int ret = memcpy_s(g_cong_packet, sizeof(*g_cong_packet) * WIFIPRO_CONG_ARRAY, data, len);
    if (ret != EOK) {
        pr_err("handle_get_cong_response memcpy_s failed!");
        return;
    }
}

static void handle_get_mib_response(unsigned char *data, unsigned int len)
{
    if (g_tcp_stat == NULL || data == NULL) {
        return;
    }
    if (len != sizeof(*g_tcp_stat)) {
        pr_err("handle_get_mib_response recv invalid len = %u", len);
        return;
    }
    int ret = memcpy_s(g_tcp_stat, sizeof(*g_tcp_stat), data, len);
    if (ret != EOK) {
        pr_err("handle_get_mib_response memcpy_s failed!");
        return;
    }
}

static void handle_get_uid_stat_response(unsigned char *data, unsigned int len)
{
    if (g_uid_tcp_stat_packet == NULL || data == NULL) {
        return;
    }
    if (len != sizeof(struct uid_tcp_stat_dmi_packet) * MAX_UID_CNT) {
        return;
    }
    struct uid_tcp_stat_dmi_packet *cur = NULL;
    switch (g_curent_uid_tcp_stat_type) {
        case UID_TCP_WLAN_STAT:
            cur = g_uid_tcp_stat_packet->wlan_stat;
            break;
        case UID_TCP_RMNET_STAT:
            cur = g_uid_tcp_stat_packet->rmnet_stat;
            break;
        case UID_TCP_HIDATA_STAT:
            cur = g_uid_tcp_stat_packet->hidata_stat;
            break;
        default:
            break;
    }
    if (cur == NULL) {
        return;
    }
    int ret = memcpy_s(cur, len, data, len);
    if (ret != EOK) {
        pr_err("handle_get_uid_stat_response memcpy_s failed!");
        return;
    }
    g_curent_uid_tcp_stat_type++;
}

static void handle_get_rtt_stat_response(unsigned char *data, unsigned int len)
{
    if (g_rtt_second_stat_packet == NULL || data == NULL) {
        return;
    }
    if (len != sizeof(g_rtt_second_stat_packet->wlan_stat)) {
        return;
    }
    struct rtt_second_stat_dmi_packet *cur = NULL;
    switch (g_curent_rtt_second_stat_type) {
        case RTT_SECOND_WLAN_STAT:
            cur = g_rtt_second_stat_packet->wlan_stat;
            break;
        case RTT_SECOND_RMNET_STAT:
            cur = g_rtt_second_stat_packet->rmnet_stat;
            break;
        default:
            break;
    }
    if (cur == NULL) {
        return;
    }
    int ret = memcpy_s(cur, len, data, len);
    if (ret != EOK) {
        pr_err("handle_get_uid_stat_response memcpy_s failed!");
        return;
    }
    g_curent_rtt_second_stat_type++;
}

static void handle_get_unknown_count_response(unsigned char *data, unsigned int len)
{
    if (data == NULL || len != sizeof(int) + sizeof(int)) {
        return;
    }
    int *result = (int*)data;
    if (g_unknown_dev_count != NULL) {
        *g_unknown_dev_count = *result;
    }
    result++;
    if (g_unknown_segs_count != NULL) {
        *g_unknown_segs_count = *result;
    }
}

static void wifipro_tcp_monitor_response_handler(unsigned short cmd, unsigned char *data, unsigned int len)
{
    switch (cmd) {
        case WIFIPRO_GET_MSG:
            handle_get_msg_response(data, len);
            break;
        case WIFIPRO_GET_CONG:
            handle_get_cong_response(data, len);
            break;
        case WIFIPRO_GET_MIB:
            handle_get_mib_response(data, len);
            break;
        case WIFIPRO_GET_UID_STAT:
            handle_get_uid_stat_response(data, len);
            break;
        case WIFIPRO_GET_RTT_STAT:
            handle_get_rtt_stat_response(data, len);
            break;
        case WIFIPRO_GET_UNKNOWN_COUNT:
            handle_get_unknown_count_response(data, len);
            break;
        default:
            break;
    }
}

void wifipro_tcp_monitor_dmi_client_init(void)
{
    mutex_init(&g_tcp_monitor_packet_lock);
    mutex_init(&g_cong_packet_lock);
    mutex_init(&g_tcp_stat_lock);
    mutex_init(&g_uid_tcp_stat_packet_lock);
    mutex_init(&g_rtt_second_stat_packet_lock);
    mutex_init(&g_unknown_count_lock);
    register_handle_response_func(WIFIPRO_TCP_MONITOR_FEATURE, wifipro_tcp_monitor_response_handler);

    struct wifipro_tcp_monitor_dmi_client_ops ops = {
        .append_dpa_tcp_monitor_stat = append_dpa_tcp_monitor_stat,
        .get_dpa_cong_stat = get_dpa_cong_stat,
        .get_dpa_wifipro_tcp_stat = get_dpa_wifipro_tcp_stat,
        .get_dpa_uid_tcp_stat = get_dpa_uid_tcp_stat,
        .get_dpa_rtt_second_stat = get_dpa_rtt_second_stat,
        .get_dpa_unknown_counts = get_dpa_unknown_counts,
        .start_dpa_monitor = start_dpa_monitor
    };
#ifdef CONFIG_HW_WIFIPRO
    register_wifipro_tcp_monitor_dmi_ops(ops);
#endif
}