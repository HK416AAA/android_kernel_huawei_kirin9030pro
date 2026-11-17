#include "netom_agent.h"

struct net_trans_s g_net_trans_dpa;
int net_om_dpa_report_init(void)
{
    /* init list */
    struct net_trans_s *net_trans = &g_net_trans_dpa;

    if (net_trans->init != 1) {
        INIT_LIST_HEAD(&net_trans->list);
        net_trans->init = 1;
    }

    return 0;
}

int bsp_dpa_net_report_register(struct net_om_info *info)
{
    net_om_dpa_report_init();
    if (info == NULL || info->data == NULL || info->size == 0 || info->func_cb == NULL) {
        return -1;
    }

    list_add_tail(&info->list, &g_net_trans_dpa.list);

    return 0;
}

struct list_head *bsp_dpa_netom_get_list(void)
{
    if (list_empty(&g_net_trans_dpa.list)) {
        return NULL;
    }

    return &g_net_trans_dpa.list;
}
EXPORT_SYMBOL_GPL(bsp_dpa_netom_get_list);