/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: This module is to collect TCP stack parameters
 * Author: liuleimin1@huawei.com
 * Create: 2019-04-18
 */

#include "tcp_para_collec.h"

#include <linux/net.h>
#include <net/sock.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <net/tcp.h>
#include <securec.h>
#ifdef CONFIG_DPA_PROTO
#include <linux/kthread.h>
#include <linux/semaphore.h>
#endif

#include "hw_booster_common.h"

static DEFINE_SPINLOCK(g_tcp_para_collec_lock);

static long tcp_tx_pkt_sum = 0;
static long tcp_rx_pkt_sum = 0;
static long dns_tx_pkt_sum = 0;
static long dns_rx_pkt_sum = 0;
static long tcp_tx_v6_pkt_sum = 0;
static long tcp_rx_v6_pkt_sum = 0;
static long tcp_tx_v4_pkt_sum = 0;
static long tcp_rx_v4_pkt_sum = 0;
static long dns_v4_tx_pkt_sum = 0;
static long dns_v4_rx_pkt_sum = 0;
static long dns_v6_tx_pkt_sum = 0;
static long dns_v6_rx_pkt_sum = 0;
static notify_event *notifier = NULL;
#ifdef CONFIG_DPA_PROTO
static int g_dpa_msg_type = 0;
static struct semaphore dpa_sema;
struct task_struct *dpa_tcp_para_task = NULL;

typedef void (*get_pkt_num)(long *tcp_rx, long *tcp_tx, long *dns_rx, long *dns_tx);
static get_pkt_num g_dpa_ops = NULL;
void register_tcp_pkt_num_dmi_ops(get_pkt_num func)
{
	printk(KERN_INFO "register_tcp_pkt_num_dmi_ops success\n");
	g_dpa_ops = func;
}
EXPORT_SYMBOL(register_tcp_pkt_num_dmi_ops);
#endif

void booster_update_dns_tx_statistics(struct sk_buff *skb,
	struct net_device *in, struct net_device *out, int proto, u_int8_t af)
{
	struct sock *sk = NULL;
	if (proto != IPPROTO_UDP)
		return;

	sk = skb_to_full_sk(skb);
	if (sk == NULL)
		return;

	spin_lock_bh(&g_tcp_para_collec_lock);
	if (htons(inet_sk(sk)->inet_dport) == DNS_PORT) {
		if (out != NULL) {
			dns_tx_pkt_sum++;
			if (af == AF_INET)
				dns_v4_tx_pkt_sum++;
			if (af == AF_INET6)
				dns_v6_tx_pkt_sum++;
		}
	}
	spin_unlock_bh(&g_tcp_para_collec_lock);
	return;
}

void booster_update_udp_recv_statistics(struct sk_buff *skb, struct sock *sk)
{
	const struct iphdr *iph = NULL;
	u8 protocol;

	if (skb == NULL || sk == NULL)
		return;
	if (skb->dev == NULL)
		return;
	if (!is_ds_rnic(skb->dev))
		return;
	iph = ip_hdr(skb);
	if (iph == NULL)
		return;
	protocol = iph->protocol;

	spin_lock_bh(&g_tcp_para_collec_lock);
	if (protocol == IPPROTO_UDP &&
		htons(inet_sk(sk)->inet_dport) == DNS_PORT) {
			dns_rx_pkt_sum++;
			dns_v4_rx_pkt_sum++;
		}
	spin_unlock_bh(&g_tcp_para_collec_lock);
}

void booster_update_udp6_recv_statistics(struct sk_buff *skb, struct sock *sk)
{
	const struct ipv6hdr *iph = NULL;
	u8 protocol;

	if (skb == NULL || sk == NULL)
		return;
	if (skb->dev == NULL)
		return;
	if (!is_ds_rnic(skb->dev))
		return;
	iph = ipv6_hdr(skb);
	if (iph == NULL)
		return;
	protocol = iph->nexthdr;

	spin_lock_bh(&g_tcp_para_collec_lock);
	if (protocol == IPPROTO_UDP &&
		htons(inet_sk(sk)->inet_dport) == DNS_PORT) {
			dns_rx_pkt_sum++;
			dns_v6_rx_pkt_sum++;
		}
	spin_unlock_bh(&g_tcp_para_collec_lock);
}

void booster_count_tcp_tx_rx(u_int8_t af, struct net_device *in, struct net_device *out)
{
	spin_lock_bh(&g_tcp_para_collec_lock);
	if (out != NULL) {
		tcp_tx_pkt_sum++;
		if (af == AF_INET6)
			tcp_tx_v6_pkt_sum++;
		if (af == AF_INET)
			tcp_tx_v4_pkt_sum++;
	}
	if (in != NULL) {
		tcp_rx_pkt_sum++;
		if (af == AF_INET6)
			tcp_rx_v6_pkt_sum++;
		if (af == AF_INET)
			tcp_rx_v4_pkt_sum++;
	}
	spin_unlock_bh(&g_tcp_para_collec_lock);
}

void booster_update_tcp_statistics(u_int8_t af, struct sk_buff *skb,
	struct net_device *in, struct net_device *out)
{
	unsigned int thoff = 0;
	int proto;
	struct tcphdr *tcph = NULL;

	if (skb == NULL)
		return;
	if (!is_ds_rnic(out) && !is_ds_rnic(in))
		return;
	if (af == AF_INET6)
		proto = ipv6_find_hdr(skb, &thoff, -1, NULL, NULL);
	else if (af == AF_INET)
		proto = ip_hdr(skb)->protocol;
	else
		proto = IPPROTO_RAW;

	booster_update_dns_tx_statistics(skb, in, out, proto, af);

	if (proto != IPPROTO_TCP)
		return;
	tcph = tcp_hdr(skb);
	if (tcph != NULL && skb->data != NULL && tcph->doff != 0) {
		if (tcph->fin == 1)
			return;
		if (tcph->rst == 1)
			return;
	}
	booster_count_tcp_tx_rx(af, in, out);
	return;
}

static unsigned int hook(void *priv, struct sk_buff *skb,
	const struct nf_hook_state *state)
{
	u_int8_t af;
	if (skb == NULL || state == NULL)
		return NF_ACCEPT;

	if (state->pf == NFPROTO_IPV4)
		af = AF_INET;
	else if (state->pf == NFPROTO_IPV6)
		af = AF_INET6;
	else
		af = AF_UNSPEC;
	// downlink tcp statistics
	booster_update_tcp_statistics(af, skb, state->in, NULL);
	return NF_ACCEPT;
}

static struct nf_hook_ops net_hooks[] = {
	{
		.hook = hook,
		.pf = NFPROTO_IPV4,
		.hooknum = NF_INET_PRE_ROUTING,
		.priority = NF_IP_PRI_FILTER,
	},
	{
		.hook = hook,
		.pf = NFPROTO_IPV6,
		.hooknum = NF_INET_PRE_ROUTING,
		.priority = NF_IP_PRI_FILTER,
	},
};

static void notify_tcp_collec_event(u16 type)
{
	char event[NOTIFY_BUF_LEN];
	char *p = event;
	const int notify_len = (type == TCP_PKT_COLLEC_WITH_IP_TYPE_CMD) ? 100 : 36;
	const int data_sum_len = 8;

	if (!notifier)
		return;
	memset_s(&event, NOTIFY_BUF_LEN, 0, NOTIFY_BUF_LEN);
	// type
	if (type == TCP_PKT_COLLEC_CMD || type == TCP_PKT_COLLEC_WITH_IP_TYPE_CMD)
		assign_short(p, TCP_PKT_CONUT_RPT);
	if (type == SMARTCURE_PARA_COLLEC_CMD)
		assign_short(p, SMARTCURE_PKT_COUNT_RPT);
	skip_byte(p, sizeof(s16));
	// len(2B type + 2B len + 8B tcp_tx_pkt_sum + 8B tcp_rx_pkt_sum +
	// 8B dns_tx_pkt_sum + 8B dns_rx_pkt_sum)
	assign_short(p, notify_len);
	skip_byte(p, sizeof(s16));
#ifdef CONFIG_DPA_PROTO
    if (g_dpa_ops) {
        g_dpa_ops(&tcp_tx_pkt_sum, &tcp_rx_pkt_sum, &dns_tx_pkt_sum, &dns_rx_pkt_sum);
    }
#endif
	spin_lock_bh(&g_tcp_para_collec_lock);
	// 8B tcp_tx_pkt_sum
	assign_long(p, tcp_tx_pkt_sum);
	skip_byte(p, data_sum_len);
	// 8B tcp_rx_pkt_sum
	assign_long(p, tcp_rx_pkt_sum);
	skip_byte(p, data_sum_len);
	// 8B dns_tx_pkt_sum
	assign_long(p, dns_tx_pkt_sum);
	skip_byte(p, data_sum_len);
	// 8B dns_rx_pkt_sum
	assign_long(p, dns_rx_pkt_sum);
	if (type == TCP_PKT_COLLEC_WITH_IP_TYPE_CMD) {
		skip_byte(p, data_sum_len);
		// 8B tcp_tx_v6_pkt_sum
		assign_long(p, tcp_tx_v6_pkt_sum);
		skip_byte(p, data_sum_len);
		// 8B tcp_rx_v6_pkt_sum
		assign_long(p, tcp_rx_v6_pkt_sum);
		skip_byte(p, data_sum_len);
		// 8B tcp_tx_v4_pkt_sum
		assign_long(p, tcp_tx_v4_pkt_sum);
		skip_byte(p, data_sum_len);
		// 8B tcp_tx_v4_pkt_sum
		assign_long(p, tcp_rx_v4_pkt_sum);
		skip_byte(p, data_sum_len);
		// 8B tcp_tx_v4_pkt_sum
		assign_long(p, dns_v4_tx_pkt_sum);
		skip_byte(p, data_sum_len);
		// 8B tcp_tx_v4_pkt_sum
		assign_long(p, dns_v4_rx_pkt_sum);
		skip_byte(p, data_sum_len);
		// 8B tcp_tx_v4_pkt_sum
		assign_long(p, dns_v6_tx_pkt_sum);
		skip_byte(p, data_sum_len);
		// 8B tcp_tx_v4_pkt_sum
		assign_long(p, dns_v6_rx_pkt_sum);
	}

	spin_unlock_bh(&g_tcp_para_collec_lock);
	notifier((struct res_msg_head *)event);
}

static void cmd_process(struct req_msg_head *msg, u32 len)
{
	if (!msg) {
		pr_err("msg is null\n");
		return;
	}
#ifdef CONFIG_DPA_PROTO
    g_dpa_msg_type = msg->type;
    up(&dpa_sema);
	return;
#endif
	if (msg->type == TCP_PKT_COLLEC_CMD)
		notify_tcp_collec_event(TCP_PKT_COLLEC_CMD);

	if (msg->type == TCP_PKT_COLLEC_WITH_IP_TYPE_CMD)
		notify_tcp_collec_event(TCP_PKT_COLLEC_WITH_IP_TYPE_CMD);

	if (msg->type == SMARTCURE_PARA_COLLEC_CMD)
		notify_tcp_collec_event(SMARTCURE_PARA_COLLEC_CMD);
	return;
}

#ifdef CONFIG_DPA_PROTO
static void dpa_cmd_process()
{
	if (g_dpa_msg_type == TCP_PKT_COLLEC_CMD)
		notify_tcp_collec_event(TCP_PKT_COLLEC_CMD);
	if (g_dpa_msg_type == TCP_PKT_COLLEC_WITH_IP_TYPE_CMD)
		notify_tcp_collec_event(TCP_PKT_COLLEC_WITH_IP_TYPE_CMD);
	if (g_dpa_msg_type == SMARTCURE_PARA_COLLEC_CMD)
		notify_tcp_collec_event(SMARTCURE_PARA_COLLEC_CMD);
	return;
}

static int stat_report_thread(void *arg)
{
	while (!kthread_should_stop()) {
		down(&dpa_sema);
		dpa_cmd_process();
	}
	return 0;
}
#endif

msg_process *tcp_para_collec_init(notify_event *notify)
{
	int ret;

	if (notify == NULL) {
		pr_err("%s: notify parameter is null\n", __func__);
		return NULL;
	}

	ret = nf_register_net_hooks(&init_net, net_hooks,
		ARRAY_SIZE(net_hooks));
	if (ret) {
		pr_info("nf_init_in error");
		goto init_error;
	}
#ifdef CONFIG_DPA_PROTO
    sema_init(&dpa_sema, 0);
    dpa_tcp_para_task = kthread_run(stat_report_thread, NULL, "stat_report");
	if (IS_ERR(dpa_tcp_para_task)) {
		dpa_tcp_para_task = NULL;
		goto init_error;
    }
#endif
	notifier = notify;
	return cmd_process;

init_error:
	return NULL;
}

long get_dns_rx_pkt_num(void)
{
	return dns_rx_pkt_sum;
}

long get_dns_tx_pkt_num(void)
{
	return dns_tx_pkt_sum;
}
