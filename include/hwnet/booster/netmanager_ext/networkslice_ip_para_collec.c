/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: This module is to collect TCP/IP stack parameters
 */

#include "networkslice_ip_para_collec.h"

#include <linux/net.h>
#include <linux/list.h>
#include <linux/inet.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <net/tcp.h>
#include <net/udp.h>
#include "hw_booster_common.h"
#include "networkslice_ip_para_collec_ex.h"
#include "netmanagerext_netlink.h"
#include "data_dubai_collect.h"
#include "model_para_collec.h"
#include "tcp_para_collec.h"
#include "../chr/wbc_hw_hook.h"
#include <securec.h>
#ifdef CONFIG_HW_NETWORK_SLICE_NETMGR
#include "netmanager_ext_ns_management.h"
#endif

#ifdef CONFIG_STREAM_DETECT
#include "stream_detect.h"
#endif

#define TCP_HDR_IHL_QUAD 4


inline u32 get_sock_uid_ns(struct sock *sk)
{
	return (u32)sk->sk_uid.val;
}

#if defined(CONFIG_HUAWEI_KSTATE)
inline u32 get_sock_pid_ns(struct sock *sk)
{
	if (sk->sk_socket == NULL)
		return 0;
	return (u32)sk->sk_socket->pid;
}
#endif


static bool is_local_or_lan_addr(__be32 ip_addr)
{
	if (ipv4_is_loopback(ip_addr) ||
		ipv4_is_multicast(ip_addr) ||
		ipv4_is_local_multicast(ip_addr) ||
		ipv4_is_lbcast(ip_addr) ||
		ipv4_is_private_10(ip_addr) ||
		ipv4_is_private_172(ip_addr) ||
		ipv4_is_private_192(ip_addr) ||
		ipv4_is_linklocal_169(ip_addr))
		return true;
	else
		return false;
}

static bool is_private_v6_addr(struct sock *sk)
{
	const unsigned int clat_ipv4_index = 3;
	__be32 addr;
	int addr_type;
#if IS_ENABLED(CONFIG_IPV6)
	if (sk == NULL)
		return false;
	addr_type = ipv6_addr_type(&sk->sk_v6_daddr);
	if ((sk->sk_family == AF_INET6) &&
		(addr_type & IPV6_ADDR_MAPPED)) {
		addr = sk->sk_v6_daddr.s6_addr32[clat_ipv4_index];
		return is_local_or_lan_addr(addr);
	}
#endif
	return false;
}


static bool is_sk_fullsock(struct sock *sk)
{
	if (sk != NULL && sk_fullsock(sk))
		return true;

	return false;
}

static bool is_tcp_udp_sock(struct sock *sk)
{
	if (!is_sk_fullsock(sk))
		return false;

	return (sk->sk_type == SOCK_STREAM || sk->sk_type == SOCK_DGRAM);
}

static unsigned int hook4(void *priv,
	struct sk_buff *skb,
	const struct nf_hook_state *state)
{
	const struct iphdr *iph = NULL;
	struct sock *sk = NULL;
	u16 payload_len;

	if (state == NULL)
		return NF_ACCEPT;

#ifdef CONFIG_HW_NETWORK_SLICE_NETMGR
	if (state->hook == NF_INET_LOCAL_OUT)
		slice_ip_para_report_ns(skb, AF_INET);
#endif

	iph = ip_hdr(skb);
	if (iph == NULL)
		return NF_ACCEPT;
	if (iph->protocol == IPPROTO_UDP && state->hook == NF_INET_LOCAL_IN)
		return NF_ACCEPT;
	sk = skb_to_full_sk(skb);
	if (sk == NULL)
		sk = state->sk;
	if (!is_tcp_udp_sock(sk))
		return NF_ACCEPT;

	if (iph->protocol == IPPROTO_TCP &&
		is_local_or_lan_addr(sk->sk_daddr))
		return NF_ACCEPT;

	payload_len = ntohs(iph->tot_len) - iph->ihl * TCP_HDR_IHL_QUAD; // 32bits to byte
	return NF_ACCEPT;
}

static unsigned int hook6(void *priv,
	struct sk_buff *skb,
	const struct nf_hook_state *state)
{
	const struct ipv6hdr *iph = NULL;
	struct sock *sk = NULL;
	u16 payload_len;

	if (state == NULL)
		return NF_ACCEPT;

#ifdef CONFIG_HW_NETWORK_SLICE_NETMGR
	if (state->hook == NF_INET_LOCAL_OUT)
		slice_ip_para_report_ns(skb, AF_INET6);
#endif

	iph = ipv6_hdr(skb);
	if (iph == NULL)
		return NF_ACCEPT;
	if (iph->nexthdr == IPPROTO_UDP && state->hook == NF_INET_LOCAL_IN)
		return NF_ACCEPT;
	sk = skb_to_full_sk(skb);
	if (sk == NULL)
		sk = state->sk;
	if (!is_tcp_udp_sock(sk))
		return NF_ACCEPT;

	if (iph->nexthdr == IPPROTO_TCP &&
		is_private_v6_addr(sk))
		return NF_ACCEPT;

	payload_len = ntohs(iph->payload_len);
	return NF_ACCEPT;
}

static struct nf_hook_ops net_hooks[] = {
	{
		.hook = hook4,
		.pf = PF_INET,
		.hooknum = NF_INET_LOCAL_IN,
		.priority = NF_IP_PRI_FILTER + 1,
	},
	{
		.hook = hook4,
		.pf = PF_INET,
		.hooknum = NF_INET_POST_ROUTING,
		.priority = NF_IP_PRI_FILTER + 1,
	},
	{
		.hook = hook4,
		.pf = PF_INET,
		.hooknum = NF_INET_FORWARD,
		.priority = NF_IP_PRI_FILTER - 1,
	},
	{
		.hook = hook4,
		.pf = PF_INET,
		.hooknum = NF_INET_LOCAL_OUT,
		.priority = NF_IP_PRI_FILTER - 1,
	},
	{
		.hook = hook6,
		.pf = PF_INET6,
		.hooknum = NF_INET_LOCAL_IN,
		.priority = NF_IP_PRI_FILTER + 1,
	},
	{
		.hook = hook6,
		.pf = PF_INET6,
		.hooknum = NF_INET_POST_ROUTING,
		.priority = NF_IP_PRI_FILTER + 1,
	},
	{
		.hook = hook6,
		.pf = PF_INET6,
		.hooknum = NF_INET_FORWARD,
		.priority = NF_IP_PRI_FILTER - 1,
	},
	{
		.hook = hook6,
		.pf = PF_INET6,
		.hooknum = NF_INET_LOCAL_OUT,
		.priority = NF_IP_PRI_FILTER - 1,
	},
};

static void cmd_process(struct req_msg_head_ns *msg, u32 len)
{
	if (len < sizeof(struct req_msg_head_ns) || msg->len > MAX_REQ_DATA_LEN)
		return;

	if (msg->len != len) {
		pr_err("ip_para_collec msg len error!!! left = %d, right = %d", msg->len, len);
		return;
	}
}

/*
 * Initialize internal variables and external interfaces
 */
msg_process_ns *networkslice_ip_para_collec_init(notify_event_ns *fn)
{
	pr_info("networkslice_ip_para_collec_init\n");
	int i;
	int ret;

	if (fn == NULL)
		return NULL;
	pr_info("networkslice_nf_register_net_hooks_begin\n");
	ret = nf_register_net_hooks(&init_net, net_hooks,
				    ARRAY_SIZE(net_hooks));
	if (ret) {
		pr_info("[IP_PARA]nf_init_in ret=%d  ", i);
		goto init_error;
	}
	return cmd_process;

init_error:
	return NULL;
}

void networkslice_ip_para_collec_exit(void)
{
}
