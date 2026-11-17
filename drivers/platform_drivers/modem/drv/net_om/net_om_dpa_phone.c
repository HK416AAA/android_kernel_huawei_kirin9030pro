#include "net_om.h"
#include <dpa_dmi.h>
#include <bsp_rproc.h>
#include <linux/slab.h>
#include "dpa_reset.h"

#undef THIS_MODU
#define THIS_MODU mod_netom

struct net_om_frame_s{
    unsigned int report_swt;
    unsigned int report_period;
};

int net_om_send_cfg_to_dpa(net_om_diag_cmd_s *net_om_diag_cmd)
{
    int ret;
    struct dmi_msg *msg = NULL;
    struct net_om_frame_s *net_om_frame = NULL;
    struct net_trans_s *net_trans = &g_net_trans;
    
    unsigned int len = sizeof(struct dmi_msg) + sizeof(struct net_om_frame_s);

    msg = (struct dmi_msg *)kmalloc(len, GFP_KERNEL);
    if (msg == NULL) {
        return -1;
    }

    net_om_frame = (struct net_om_frame_s *)(msg->data.buf);

    net_om_frame->report_swt = net_om_diag_cmd->net_om_switch_dpa;
    net_om_frame->report_period = net_om_diag_cmd->report_log_period_dpa;
    net_trans->dpa_report_onoff = net_om_diag_cmd->net_om_switch_dpa;
    net_trans->dpa_report_period = net_om_diag_cmd->report_log_period_dpa;

    msg->plane = DMI_SERVICE_TYPE_COMM;
    msg->dmi_id = DMI_SERVICE_NETOM;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->data.len = len - sizeof(struct dmi_msg);

    ret = dpa_dmi_client_request_comm_wake(msg, sizeof(*msg) + msg->data.len);
    if (ret) {
        bsp_err("fail to send msg to dpa\n");
    }
    kfree(msg);

    return 0;
}

int net_om_dpa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    struct net_trans_s *net_trans = &g_net_trans;
    net_om_diag_cmd_s net_om_diag_cmd;

    if (enparam == DPA_RESET_AFTER && net_trans->dpa_report_onoff) {
        net_om_diag_cmd.net_om_switch_dpa = net_trans->dpa_report_onoff;
        net_om_diag_cmd.report_log_period_dpa = net_trans->dpa_report_period;
        net_om_send_cfg_to_dpa(&net_om_diag_cmd);
    }

    return 0;
}

int net_om_dpa_reset_init(void)
{
    int ret;

    ret = bsp_dpa_reset_register_cb("netom", net_om_dpa_reset_cb, 0, DPA_RESET_CB_LEVEL_COMMON);
    if (ret) {
        bsp_err("Failed to register DPA reset callback for netom\n");
        return ret;
    }
    return 0;
}

int net_om_msg_init(void)
{
    return 0;
}
