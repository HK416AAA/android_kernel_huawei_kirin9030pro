/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include "stack_log.h"
#include "securec.h"
#include "dfx/global_res_stats.h"
#include "common_msg.h"
#include "sys_msg.h"

typedef struct client_service_table {
    sys_msg_func client_handle_msg;
    sys_msg_func client_handle_err_msg;
    dmi_client_event client_event_callback;
} client_service_table;

static client_service_table g_client_service_table = {
    .client_handle_msg = NULL,
};

static int check_recv_service_msg_valid(struct dmi_msg_data *msg)
{
    if (msg->len < sizeof(msg_param)) {
        NS_DBG("client bridge service msg len invalid %u, len min %u", msg->len, sizeof(msg_param));
        return -1;
    }
    msg_param *param = (msg_param *)&msg->buf[0];
    if (msg->len != param->buffer_len) {
        NS_DBG("client bridge service msg len invalid %u, param buffer len %u", msg->len, param->buffer_len);
        return -1;
    }
    return 0;
}

static int client_recvmsg_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    if (msg == NULL) {
        sbr_global_stat_cnt_inc(GLOBAL_RX_DMI_MSG_NULL_ERR);
        NS_DBG("client service msg NULL");
        return -1;
    }
    if (priv == NULL) {
        bsp_dmi_msg_free(msg);
        sbr_global_stat_cnt_inc(GLOBAL_RX_DMI_MSG_PRIV_NULL_ERR);
        NS_DBG("client service msg cb not register");
        return -1;
    }
    if (check_recv_service_msg_valid(msg) < 0) {
        bsp_dmi_msg_free(msg);
        sbr_global_stat_cnt_inc(GLOBAL_RX_DMI_MSG_CHECK_ERR);
        NS_DBG("client service msg recv check failed");
        return -1;
    }
    client_service_table *table = (client_service_table *)priv;
    /* move back to dmi_msg */
    table->client_handle_msg((void *)msg - sizeof(struct dmi_msg) + sizeof(struct dmi_msg_data));
    return 0;
}

static void client_recvmsg_err_cb(void *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    if (msg == NULL) {
        sbr_global_stat_cnt_inc(GLOBAL_RX_DMI_MSG_NULL_ERR);
        NS_DBG("client service msg NULL");
        return;
    }
    if (priv == NULL) {
        sbr_global_stat_cnt_inc(GLOBAL_RX_DMI_MSG_PRIV_NULL_ERR);
        NS_DBG("client service msg cb not register");
        return;
    }
    if (check_recv_service_msg_valid(msg) < 0) {
        sbr_global_stat_cnt_inc(GLOBAL_RX_DMI_MSG_CHECK_ERR);
        NS_DBG("client service msg recv check failed");
        return;
    }
    client_service_table *table = (client_service_table *)priv;
    /* move back to dmi_msg */
    table->client_handle_err_msg((void *)msg - sizeof(struct dmi_msg) + sizeof(struct dmi_msg_data));
}

static void client_dmi_event_cb(unsigned int plane, enum dmi_event_type_e event)
{
    if (plane != DMI_SERVICE_TYPE_DATA || event != DMI_EVENT_CHN_NOT_FULL) {
        return;
    }
    g_client_service_table.client_event_callback();
}

static void init_client_service(struct dmi_client *client_service, char *priv)
{
    (void)bsp_dmi_client_init(client_service);
    client_service->dmi_id = DMI_SERVICE_STACK;
    client_service->priv = priv;
    client_service->service_cb = client_recvmsg_cb;
    client_service->err_process = client_recvmsg_err_cb;
    client_service->dmi_client_event_cbk = client_dmi_event_cb;
}

s32 sys_msg_listen(void *mhandle, sys_msg_func func, sys_msg_func err_func)
{
    client_service_table *table = (client_service_table *)mhandle;
    struct dmi_client client_service;
    if (func == NULL) {
        NS_ERR("client msg handle NULL");
        return -1;
    }
    table->client_handle_msg = func;
    table->client_handle_err_msg = err_func;
    init_client_service(&client_service, (char *)table);
    return bsp_dmi_client_register(&client_service);
}

void sys_msg_register_event_cb(dmi_client_event cb)
{
    g_client_service_table.client_event_callback = cb;
}

void *sys_msg_pool_create(u32 pool_size, u32 msg_len)
{
    (void)pool_size;
    return (void *)&g_client_service_table;
}

void *sys_msg_box_create(u32 size)
{
    (void)size;
    client_service_table *table = stack_malloc(sizeof(client_service_table));
    if (table == NULL) {
        NS_ERR("client service malloc table failed");
        return NULL;
    }
    return (void *)table;
}

void *sys_msg_malloc(void *mhandle)
{
    (void)mhandle;
    void *msg = NULL;
    msg = (void *)bsp_dmi_msg_alloc(DMI_SERVICE_STACK, sizeof(data_com_msg));
    return msg;
}

void sys_msg_free(void *msg, bool need_to_free)
{
    struct dmi_msg_data *data = &(((struct dmi_msg *)msg)->data);
    if (need_to_free) {
        bsp_dmi_msg_free(data);
    }
}

s32 sys_msg_try_post(void *msg, void *mhandle)
{
    int ret;
    u32 type = (u32)(uintptr_t)mhandle; // get msg type : control or data
    data_com_msg *data_msg = (data_com_msg *)msg;
    struct dmi_msg *service_msg = (struct dmi_msg *)data_msg->msg_pre;
    service_msg->plane = type;
    service_msg->dmi_id = DMI_SERVICE_STACK;
    service_msg->type = DMI_SERVICE_TYPE_REQUEST;
    service_msg->dmi_cb.cb = 0;
    service_msg->dmi_cb.cb_data = 0;
    service_msg->data.len = data_msg->param.buffer_len;
    ret = bsp_dmi_client_request(service_msg, (u32)(data_msg->param.buffer_len + DATA_MSG_PRE));
    if (ret < 0) {
        NS_DBG("client bridge msg try post failed, %d", ret);
        return ret;
    }
    return 0;
}
