/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: config for reporting fault to fault manager.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <net/sock.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <securec.h>
#include "teek_client_constants.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "cmdmonitor.h"
#include "fault_manager.h"
#include "fault_mode_netlink.h"
#include "teek_ns_client.h"

static struct sock *g_netlink_sock = NULL;

static int get_uuid_str(const struct tc_uuid *uuid, char *buff, uint32_t len)
{
	if (uuid == NULL || buff == NULL || len < UUID_STR_FORMAT_LEN) {
		tloge("invalid parameter\n");
		return TEEC_ERROR_GENERIC;
	}

	int ret = snprintf_s(buff, len, UUID_STR_FORMAT_LEN - 1, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
			     uuid->time_low, uuid->time_mid, uuid->timehi_and_version, uuid->clockseq_and_node[0],
			     uuid->clockseq_and_node[1], uuid->clockseq_and_node[2], uuid->clockseq_and_node[3],
			     uuid->clockseq_and_node[4], uuid->clockseq_and_node[5], uuid->clockseq_and_node[6],
			     uuid->clockseq_and_node[7]); // refer uuid format definitions
	if (ret <= 0) {
		tloge("Convert uuid to string failed\n");
		return TEEC_ERROR_GENERIC;
	}
	return TEEC_SUCCESS;
}

int tee_netlink_init(void)
{
	struct netlink_kernel_cfg cfg = {
		.groups = NL_TEE_ERROR_GROUP,
		.input = NULL,
	};
	g_netlink_sock = netlink_kernel_create(&init_net, NETLINK_SMC, &cfg);
	if (g_netlink_sock == NULL) {
		tloge("Init netlink failed\n");
		return -EFAULT;
	}
	return 0;
}

int netlink_generate_fault_info(int32_t type, const uint8_t *ta_uuid)
{
	int ret;
	struct nlmsghdr *nlh = NULL;
	struct sk_buff *nl_skb = NULL;
	struct tee_fault_msg *fault_msg = NULL;
	int size = NLMSG_SPACE(sizeof(struct tee_fault_msg));
	nl_skb = nlmsg_new(size, GFP_ATOMIC);
	if(nl_skb == NULL) {
		tlogw("netlink alloc failure!\n");
		return TEEC_ERROR_GENERIC;
	}
	/* set netlink header */
	nlh = nlmsg_put(nl_skb, 0, 0, NETLINK_SMC, size - sizeof(*nlh), 0);
	if (nlh == NULL) {
		tlogw("nlmsg_put failaure!\n");
		nlmsg_free(nl_skb);
		return TEEC_ERROR_BAD_STATE;
	}
	fault_msg = (struct tee_fault_msg *)NLMSG_DATA(nlh);
	ret = parse_type_info(type, fault_msg);
	if (ret != TEEC_SUCCESS) {
		tlogw("parse type failed, err = 0x%x\n", ret);
		nlmsg_free(nl_skb);
		return ret;
	}
	if (type == TYPE_KILLED_TA || type == TYPE_CRASH_TA)
		ret = get_uuid_str((struct tc_uuid *)ta_uuid, fault_msg->ta_uuid, UUID_STR_FORMAT_LEN);
	if (ret != TEEC_SUCCESS) {
		tlogw("get uuid str failed, err = 0x%x\n", ret);
		nlmsg_free(nl_skb);
		return ret;
	}
	ret = netlink_broadcast(g_netlink_sock, nl_skb, 0, NL_TEE_ERROR_GROUP, GFP_ATOMIC);
	if (ret != 0)
		tlogw("netlink broadcast err = 0x%x\n", ret);
	return ret;
}

void tee_netlink_exit(void)
{
	if (g_netlink_sock != NULL) {
		netlink_kernel_release(g_netlink_sock);
		g_netlink_sock = NULL;
	}
}
