/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: This file is the internal header file for the
 *              TCP/IP parameter collection module.
 */

#ifndef _NETWORKSLICE_IP_PARA_COLLEC_EX_H
#define _NETWORKSLICE_IP_PARA_COLLEC_EX_H

#include <linux/skbuff.h>
#include <net/tcp.h>

#include "netmanagerext_netlink.h"
#include "networkslice_ip_para_collec.h"

/* initialization function for external modules */
msg_process_ns *networkslice_ip_para_collec_init(notify_event_ns *fn);
void networkslice_ip_para_collec_exit(void);
#endif // _NETWORKSLICE_IP_PARA_COLLEC_EX_H
