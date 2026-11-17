/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <bsp_dmi.h>
#include "bsp_print.h"
#include "dpa_om_hids.h"
#include "dpa_om_tcpdump.h"
#include "dpa_om.h"
#ifdef CONFIG_DPA_PROTO
#include <platform_include/basicplatform/linux/hck/net/hck_dpa.h>
#endif

static int dpa_om_cb(char *priv, unsigned int id, struct dmi_msg_data *msg)
{
    int ret;
    switch (id) {
        case DPA_STACK_TCPDUMP_PKT:
            ret = dpa_tcpdump_proc_cb(msg->buf, msg->len);
            break;
        case DPA_STACK_HIDS_PKT:
            ret = dpa_host_pkt_report_ctrl(msg->buf, msg->len);
            break;

        default:
            ret = -1;
            break;
    }
    return ret;
}

void dpa_om_err_proc(void *priv, unsigned int id, struct dmi_msg_data *msg)
{
    switch (id) {
        case DPA_STACK_TCPDUMP_PKT:
            dpa_tcpdump_proc_cb(msg->buf, msg->len);
            break;
        case DPA_STACK_HIDS_PKT:
            dpa_host_pkt_report_ctrl(msg->buf, msg->len);
            break;

        default:
            break;
    }
    return;
}

int dpa_om_subscribe(void)
{
    int ret;
    struct dmi_client dpa_stack_om_client;
    ret = bsp_dmi_client_init(&dpa_stack_om_client);
    if (ret != 0) {
        dpa_pr_err("dpa_proto om client_dmi init fail\n");
        return ret;
    }
    dpa_stack_om_client.dmi_id = DMI_SERVICE_PROTO_OM;
    dpa_stack_om_client.service_cb = dpa_om_cb;
    dpa_stack_om_client.err_process = dpa_om_err_proc;

    ret = bsp_dmi_client_register(&dpa_stack_om_client);
    if (ret != 0) {
        dpa_pr_err("dpa_proto om client_dmi fail\n");
        return ret;
    }
    return ret;
}

void dpa_tcpdump_service_ctrl(struct packet_type *prot_hook, int enable)
{
    if (is_packet_rcv(prot_hook->func) == 0) {
        return;
    }
    dpa_pr_err("dpa_tcpdump service recv ctrl: %d (0:stop, 1:start)\n", enable);
    if (enable) {
        start_dpa_tcpdump_service();
    } else {
        exit_dpa_tcpdump_service();
    }
}

int dpa_stack_om_init(void)
{
    int ret;
    ret = dpa_om_subscribe();
    if (ret) {
        dpa_pr_err("dpa_tcpdump subscribe init fail\n");
        return ret;
    }

    dpa_om_hds_report_init();
    ret = dpa_tcpdump_service_init();
    if (ret) {
        dpa_pr_err("dpa_tcpdump service init fail\n");
        return ret;
    }

    REGISTER_HCK_VH(dpa_tcpdump_ctrl_new, dpa_tcpdump_service_ctrl);

    dpa_pr_err("dpa_proto_om init success.\n");
    return 0;
}
EXPORT_SYMBOL(dpa_stack_om_init);