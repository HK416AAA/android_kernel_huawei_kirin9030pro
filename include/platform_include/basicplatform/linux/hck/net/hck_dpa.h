#ifndef __HCK_DPA__
#define __HCK_DPA__

#ifdef CONFIG_DPA_PROTO
#include <linux/types.h>
#include <linux/sockptr.h>
#include <platform_include/basicplatform/linux/hck_vendor_hooks.h>

/*
 * Following tracepoints are not exported in tracefs and provide a
 * mechanism for vendor modules to hook and extend functionality
 */

struct sock;
struct sk_buff;
struct socket;
struct packet_type;

DECLARE_HCK_VH(dpa_pre_offload,
	TP_PROTO(struct socket *sock),
	TP_ARGS(sock));

DECLARE_HCK_VH(dpa_try_offload,
	TP_PROTO(struct sock *sk),
	TP_ARGS(sk));

DECLARE_HCK_VH(dpa_tcp_backlog,
	TP_PROTO(struct sock *sk, struct sk_buff *skb),
	TP_ARGS(sk, skb));

DECLARE_HCK_VH(dpa_tcp_mtu_reduced,
	TP_PROTO(struct sock *sk, bool *skip_rtx),
	TP_ARGS(sk, skip_rtx));

DECLARE_HCK_VH(dpa_pre_setsockopt,
	TP_PROTO(struct socket *sock, int level, int optname, sockptr_t optval, int optlen, int *ret, bool *eat),
	TP_ARGS(sock, level, optname, optval, optlen, ret, eat));

DECLARE_HCK_VH(dpa_pre_getsockopt,
	TP_PROTO(struct socket *sock, int level, int optname, char __user *user_optval, int __user *optlen, int *ret, bool *eat),
	TP_ARGS(sock, level, optname, user_optval, optlen, ret, eat));

DECLARE_HCK_VH(dpa_setsockopt_check_support,
	TP_PROTO(struct sock *sk, int level, int optname),
	TP_ARGS(sk, level, optname));

DECLARE_HCK_VH(dpa_rt_tick,
	TP_PROTO(void *ptr),
	TP_ARGS(ptr));

DECLARE_HCK_VH(dpa_tcp_child_abort,
	TP_PROTO(struct sock *sk),
	TP_ARGS(sk));

DECLARE_HCK_VH(dpa_udp_unicast_rcv,
	TP_PROTO(struct sock *sk, struct sk_buff *skb),
	TP_ARGS(sk, skb));

DECLARE_HCK_VH(dpa_tcpdump_ctrl,
	TP_PROTO(int enable),
	TP_ARGS(enable));

DECLARE_HCK_VH(dpa_tcpdump_ctrl_new,
	TP_PROTO(struct packet_type *prot_hook, int enable),
	TP_ARGS(prot_hook, enable));

DECLARE_HCK_VH(acore_link_stat,
	TP_PROTO(int val),
	TP_ARGS(val));

#endif /* CONFIG_DPA_PROTO */
#endif /* __HCK_DPA__ */
