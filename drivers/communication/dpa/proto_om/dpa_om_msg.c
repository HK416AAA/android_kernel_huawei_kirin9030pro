/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <securec.h>
#include <bsp_diag.h>
#include <bsp_dmi.h>
#include <bsp_print.h>
#include "dpa_om.h"
#include "dpa_om_msg.h"

int dpa_om_msg_send(dpa_om_msg *info, unsigned int id)
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
    msg->dmi_id = DMI_SERVICE_PROTO_OM;
    msg->sub_id = id;
    msg->dmi_cb.cb = 0;
    msg->dmi_cb.cb_data = 0;

    msg->data.len = size;
    ret = memcpy_s(msg->data.buf, msg->data.len, info, size);
    if (ret) {
        goto end;
    }

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(struct dmi_msg) + msg->data.len);

end:
    kfree(msg);
    return ret;
}
