/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This file is the impl file of network aware dmi client.
 * Author: wangdingbang
 * Create: 2025-04-26
 */
#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <securec.h>
#include "network_aware_dmi_client.h"
#include "booster_features.h"
#include "booster_dmi_client.h"

static struct dpa_aware_net_stat_total *g_net_stat_total = NULL;
static DEFINE_MUTEX(g_net_stat_total_lock);
static struct dpa_aware_bg_net_stat *g_bg_net_stat = NULL;
static DEFINE_MUTEX(g_bg_net_stat_lock);

static bool set_dpa_aware_ctrl_msg(char *buf, int len)
{
    if (buf == NULL) {
        return false;
    }
    return booster_dpa_request_async(NETWORK_AWARE_FEATURE, SET_AWARE_CTRL, buf, len + 1) == 0;
}

static bool set_dpa_bg_pids(int *ids, int len)
{
    if (ids == NULL) {
        return false;
    }
    return booster_dpa_request_async(NETWORK_AWARE_FEATURE, SET_BG_PID_LIST, 
                                     (unsigned char *)ids, len * sizeof(int)) == 0;
}

static bool set_dpa_bg_uids(int *ids, int len)
{
    if (ids == NULL) {
        return false;
    }
    return booster_dpa_request_async(NETWORK_AWARE_FEATURE, SET_BG_UID_LIST,
                                     (unsigned char *)ids, len * sizeof(int)) == 0;
}

static bool set_dpa_fg_uids(int *ids, int len)
{
    if (ids == NULL) {
        return false;
    }
    return booster_dpa_request_async(NETWORK_AWARE_FEATURE, SET_FG_UID_LIST,
                                     (unsigned char *)ids, len * sizeof(int)) == 0;
}

static bool get_dpa_net_stat_total(struct dpa_aware_net_stat_total *packet)
{
    if (packet == NULL) {
        return false;
    }
    (void)memcpy_s(packet, sizeof(struct dpa_aware_net_stat_total), 0, sizeof(struct dpa_aware_net_stat_total));
    mutex_lock(&g_net_stat_total_lock);
    g_net_stat_total = packet;
    int ret = booster_dpa_request_sync(NETWORK_AWARE_FEATURE, GET_NET_STAT_TOTAL, NULL, 0);
    mutex_unlock(&g_net_stat_total_lock);
    return ret == 0;
}

static bool get_dpa_bg_net_stat(struct dpa_aware_bg_net_stat *packet)
{
    if (packet == NULL) {
        return false;
    }
    (void)memcpy_s(packet, sizeof(struct dpa_aware_bg_net_stat), 0, sizeof(struct dpa_aware_bg_net_stat));
    mutex_lock(&g_bg_net_stat_lock);
    g_bg_net_stat = packet;
    int ret = booster_dpa_request_sync(NETWORK_AWARE_FEATURE, GET_BG_NET_STAT, NULL, 0);
    mutex_unlock(&g_bg_net_stat_lock);
    return ret == 0;
}


static void handle_get_net_stat_total_response(unsigned char *data, unsigned int len)
{
    if (data == NULL || g_net_stat_total == NULL) {
        return;
    }
    if (len != sizeof(struct dpa_aware_net_stat_total)) {
        return;
    }
    int ret = memcpy_s(g_net_stat_total, len, data, len);
    if (ret != EOK) {
        pr_err("handle_get_net_stat_total_response memcpy_s failed!");
        return;
    }
    g_net_stat_total = NULL;
}

static void handle_get_bg_net_stat_response(unsigned char *data, unsigned int len)
{
    if (data == NULL || g_bg_net_stat == NULL) {
        return;
    }
    if (len != sizeof(struct dpa_aware_net_stat_total)) {
        return;
    }
    int ret = memcpy_s(g_bg_net_stat, len, data, len);
    if (ret != EOK) {
        pr_err("handle_get_bg_net_stat_response memcpy_s failed!");
        return;
    }
    g_bg_net_stat = NULL;
}

static void network_aware_response_handler(unsigned short cmd, unsigned char *data, unsigned int len)
{
    switch (cmd) {
        case GET_NET_STAT_TOTAL:
            handle_get_net_stat_total_response(data, len);
            break;
        case GET_BG_NET_STAT:
            handle_get_bg_net_stat_response(data, len);
            break;
        default:
            break;
    }
}

void network_aware_dmi_client_init(void)
{
    mutex_init(&g_net_stat_total_lock);
    mutex_init(&g_bg_net_stat_lock);
    register_handle_response_func(NETWORK_AWARE_FEATURE, network_aware_response_handler);

    struct network_aware_dmi_client_ops ops = {
        .set_dpa_aware_ctrl_msg = set_dpa_aware_ctrl_msg,
        .set_dpa_bg_pids = set_dpa_bg_pids,
        .set_dpa_bg_uids = set_dpa_bg_uids,
        .set_dpa_fg_uids = set_dpa_fg_uids,
        .get_dpa_net_stat_total = get_dpa_net_stat_total,
        .get_dpa_bg_net_stat = get_dpa_bg_net_stat
    };
#ifdef CONFIG_HW_NETWORK_AWARE
    register_network_aware_dmi_ops(ops);
#endif
}