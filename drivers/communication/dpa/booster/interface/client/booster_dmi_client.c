/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: This file is the impl file of acpu communicate with dpa.
 * Author: wangdingbang
 * Create: 2024-12-12
 */

#include <linux/atomic.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include "bsp_print.h"
#include "booster_dmi_client.h"
#include "booster_features.h"
#include "bsp_dmi.h"
#include "securec.h"

typedef struct {
    unsigned short feature_id;
    unsigned short cmd_id;
} booster_dmi_hdr;

handle_response_func g_handle_response_funcs[FEATURES_NUM];

int booster_dpa_request_async(unsigned short feature_id, unsigned short cmd_id,
                              unsigned char *buf, unsigned int buf_len)
{
    if (buf == NULL) {
        buf_len = 0;
    }
    unsigned int len = sizeof(struct dmi_msg) + sizeof(booster_dmi_hdr) + buf_len;
    struct dmi_msg *msg = (struct dmi_msg *) kmalloc(len, GFP_KERNEL);
    if (msg == NULL) {
        dpa_pr_err("alloc dmi_msg malloc fail");
        return -1;
    }

    msg->type = DMI_SERVICE_TYPE_REQUEST_CB;
    msg->dmi_id = DMI_SERVICE_BOOSTER;
    msg->data.len = sizeof(booster_dmi_hdr) + buf_len;

    booster_dmi_hdr *booster_hdr = (booster_dmi_hdr *)msg->data.buf;
    booster_hdr->feature_id = feature_id;
    booster_hdr->cmd_id = cmd_id;
    if (buf != NULL && memcpy_s(msg->data.buf + sizeof(booster_dmi_hdr), buf_len, buf, buf_len) != EOK) {
        kfree(msg);
        dpa_pr_err("booster dmi_msg memcpy_s fail");
        return -1;
    }

    int ret = bsp_dmi_client_request_comm_wake(msg, len);
    if (ret) {
        dpa_pr_err("booster_dpa_request_async bsp_dmi_client_request_comm_wake failed, ret = %d\n", ret);
    }
    kfree(msg);
    return ret;
}

static void handle_response(unsigned short feature_id, unsigned short cmd_id, unsigned char *buf, unsigned int len)
{
    if (feature_id >= FEATURES_NUM || g_handle_response_funcs[feature_id] == NULL) {
        dpa_pr_err("handle_response have not handle func\n");
        return;
    }
    g_handle_response_funcs[feature_id](cmd_id, buf, len);
}
 
static int handle_response_cb(char *priv, unsigned int sub_id, struct dmi_msg_data *msg_data)
{
    if (msg_data->len < sizeof(booster_dmi_hdr)) {
        return -1;
    }
    booster_dmi_hdr *booster_hdr = (booster_dmi_hdr *)(msg_data->buf);
    unsigned short feature_id = booster_hdr->feature_id;
    unsigned short cmd_id = booster_hdr->cmd_id;

    handle_response(feature_id, cmd_id, msg_data->buf + sizeof(booster_dmi_hdr),
        msg_data->len - sizeof(booster_dmi_hdr));
    return 0;
}

static void err_handle_cb(void *priv, unsigned int sub_id, struct dmi_msg_data *msg_data)
{
    if (msg_data->len < sizeof(booster_dmi_hdr)) {
        return;
    }
    booster_dmi_hdr *booster_hdr = (booster_dmi_hdr *)(msg_data->buf);
    unsigned short feature_id = booster_hdr->feature_id;
    unsigned short cmd_id = booster_hdr->cmd_id;

    handle_response(feature_id, cmd_id, msg_data->buf + sizeof(booster_dmi_hdr),
        msg_data->len - sizeof(booster_dmi_hdr));
}

void register_handle_response_func(unsigned short feature_id, handle_response_func handler)
{
    if (feature_id >= FEATURES_NUM) {
        dpa_pr_err("register_handle_response_func unknow feature_id:%hd\n", feature_id);
        return;
    }
    g_handle_response_funcs[feature_id] = handler;
}

void init_booster_dmi_client(void)
{
    struct dmi_client dmi_client_booster;
    int ret = bsp_dmi_client_init(&dmi_client_booster);
    if (ret) {
        dpa_pr_err("dmi_client_booster init fail");
    }
    dmi_client_booster.dmi_id = DMI_SERVICE_BOOSTER;
    dmi_client_booster.service_cb = handle_response_cb;
    dmi_client_booster.err_process = err_handle_cb;
    ret = bsp_dmi_client_register(&dmi_client_booster);
    if (ret) {
        dpa_pr_err("init_booster_dmi_client init failed\n");
    }
}