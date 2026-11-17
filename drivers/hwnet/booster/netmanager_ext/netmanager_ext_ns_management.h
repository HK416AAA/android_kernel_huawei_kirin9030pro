/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: This file is the internal header file for the
 *              network slice management module.
 */

#ifndef _NETMANAGER_EXT_NS_MANAGEMENT_H
#define _NETMANAGER_EXT_NS_MANAGEMENT_H

#include <linux/spinlock.h>
#include <linux/skbuff.h>

#include "netmanagerext_netlink.h"

struct uid_process_bind_req {
	u16 type;
	u16 len;
	u32 net_id;
	u32 uid;
};

struct del_uid_bind_req {
	u16 type;
	u16 len;
	u32 uid;
};

struct ip_para_rpt_ctrl_req {
	u16 type;
	u16 len;
	u32 enable;
};

msg_process_ns *network_slice_management_init(notify_event_ns *notify);
void slice_ip_para_report_ns(struct sk_buff *skb, unsigned short family);

#endif
