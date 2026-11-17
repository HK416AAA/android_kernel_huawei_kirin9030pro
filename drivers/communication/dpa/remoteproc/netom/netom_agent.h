#ifndef __NETOM_AGENT_H__
#define __NETOM_AGENT_H__

#include <linux/list.h>
#include <bsp_print.h>
#include "bsp_dpa_net_om.h"

struct net_trans_s {
    struct list_head list;
    unsigned int init;
};

#endif