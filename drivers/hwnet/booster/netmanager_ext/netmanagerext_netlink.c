

#include "netmanagerext_netlink.h"
#include "networkslice_ip_para_collec_ex.h"
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/semaphore.h>
#include <linux/time.h>
#include <net/sock.h>
#include <net/netlink.h>
#include <linux/skbuff.h>
#include <huawei_platform/log/hw_log.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <uapi/linux/netlink.h>
#include <linux/kthread.h>
#include <linux/version.h>
#include <securec.h>
#include "tcp_para_collec.h"
#include "hw_booster_common.h"
#include "sock_destroy_handler.h"
#include "app_proxy.h"
#ifdef CONFIG_HW_NETWORK_SLICE_NETMGR
#include "netmanager_ext_ns_management.h"
#endif

#undef HWLOG_TAG_EXT
#define HWLOG_TAG monitor_handle
HWLOG_REGIST();
MODULE_LICENSE("GPL");

#define NETLINK_HANDLE_EXIT 0
#define NETLINK_HANDLE_INIT 1

#ifndef NETLINK_NETMANAGEREXT
#define NETLINK_NETMANAGEREXT 49
#endif

static DEFINE_MUTEX(g_recv_mtx_ns);
static DEFINE_MUTEX(g_send_mtx_ns);
static DEFINE_SPINLOCK(g_rpt_lock_ns);

/* The context of the message handle */
struct handle_ctx {
	/* Netlink socket fd */
	struct sock *nlfd;

	/* Save user space progress pid when user space netlink registering. */
	unsigned int native_pid;

	/* Tasks for sending messages. */
    struct task_struct *task;

	/* Channel status */
    int chan_state;

	/* Semaphore of the message sent */
    struct semaphore sema;

	/* Message queue header */
	struct list_head msg_head;

	/* Message processing callback functions */
    msg_process_ns *model_cb[MODEL_NUM_NS];
};
static struct handle_ctx g_ctx;

/* Message list structure */
struct msg_entity_ns {
	struct list_head head;
	struct res_msg_head_ns msg;
};

/* Message mapping table for external modules */
const u16 cmd_map_model_ext[CMD_NUM_MAX_NS][MAP_ENTITY_NUM_NS] = {
	{APP_QOE_SYNC_CMD_NS, IP_PARA_COLLEC_NS},
	{UPDATE_APP_INFO_CMD_NS, IP_PARA_COLLEC_NS},
	{INFER_MODEL_COLLECT_START_NS, IP_PARA_COLLEC_NS},
	{INFER_MODEL_COLLECT_STOP_NS, IP_PARA_COLLEC_NS},
	/* iaware game flow qoe cmd */
	{GAME_FLOW_QOE_CMD_NS, IP_PARA_COLLEC_NS},
	/* tcp recover cmd */
	{TCP_RECOVERY_BASE_ON_APP_CMD_NS, IP_PARA_COLLEC_NS},
	{SLICE_RPT_CTRL_CMD_NS, NETWORK_SLICE_MANAGEMENT_NS},
	{ BIND_PROCESS_TO_SLICE_CMD_NS, NETWORK_SLICE_MANAGEMENT_NS },
	{ DEL_SLICE_BIND_CMD_NS, NETWORK_SLICE_MANAGEMENT_NS },
	{ UPDAT_INTERFACE_NAME_NS, IP_PARA_COLLEC_NS },
	{ ADD_TOP_UID_NS, IP_PARA_COLLEC_NS },
	{ DEL_TOP_UID_NS, IP_PARA_COLLEC_NS },
	{ UPDATE_CELLULAR_MODE_NS, IP_PARA_COLLEC_NS },
	{ SYNC_TOP_UID_LIST_NS, IP_PARA_COLLEC_NS },
	{ UPDATE_WIFI_STATE_NS, IP_PARA_COLLEC_NS },
	{ UPDATE_VIRTUAL_SIM_STATE_NS, IP_PARA_COLLEC_NS },
	{ FG_CHANGE_UID_NS, IP_PARA_COLLEC_NS },
	{ UPDATE_TOP_APP_UID_LIST_NS, IP_PARA_COLLEC_NS },
	{ TRIGGER_TOP_APP_ABN_REPORT_NS, IP_PARA_COLLEC_NS },
	{ SMARTCURE_PARA_COLLEC_CMD_NS, TCP_PARA_COLLEC_NS },
	{ LABEL_HIGH_PRIORITY_CMD_NS, IP_PARA_COLLEC_NS }
};

static void nl_notify_event(struct res_msg_head_ns *msg)
{
	struct msg_entity_ns *p = NULL;
	u32 len;

	if (!msg) {
		hwlog_err("%s:null data\n", __func__);
		return;
	}

	if (g_ctx.chan_state != NETLINK_HANDLE_INIT) {
		hwlog_err("%s:module not inited\n", __func__);
		return;
	}

	len = sizeof(struct list_head) + msg->len;
	p = kmalloc(len, GFP_ATOMIC);
	if (!p) {
		printk(KERN_ERR "%s: kmalloc() failed!\n", __func__);
		return;
	}
	memcpy_s(&p->msg, msg->len, msg, msg->len);
	spin_lock_bh(&g_rpt_lock_ns);
	list_add((struct list_head *)(p), &g_ctx.msg_head);
	spin_unlock_bh(&g_rpt_lock_ns);

	up(&g_ctx.sema);
}

static void process_cmd(struct req_msg_head_ns *cmd, u32 len)
{
	int i;

	if (cmd == NULL)
		return;

	for (i = 0; i < CMD_NUM_MAX_NS; i++) {
		if (cmd_map_model_ext[i][MAP_KEY_INDEX_NS] != cmd->type)
			continue;
		if (g_ctx.model_cb[cmd_map_model_ext[i][MAP_VALUE_INDEX_NS]] == NULL)
			break;
		g_ctx.model_cb[cmd_map_model_ext[i][MAP_VALUE_INDEX_NS]](cmd, len);
	}
}

static void netmanagerext_netlink_handle_rcv(struct sk_buff *__skb)
{
	hwlog_info("netmanagerext_netlink_handle_rcv\n");
	struct nlmsghdr *nlh = NULL;
	struct sk_buff *skb = NULL;

	if (g_ctx.chan_state != NETLINK_HANDLE_INIT) {
		hwlog_err("%s:module not inited\n", __func__);
		return;
	}
	if (__skb == NULL) {
		hwlog_err("Invalid param: zero pointer reference(__skb)\n");
		return;
	}
	skb = skb_get(__skb);
	if (skb == NULL) {
		hwlog_err("netmanagerext_netlink_handle_rcv: skb = NULL\n");
		return;
	}
	mutex_lock(&g_recv_mtx_ns);
	if (skb->len < NLMSG_HDRLEN) {
		hwlog_err("netmanagerext_netlink_handle_rcv:skb len error\n");
		goto skb_free;
	}
	nlh = nlmsg_hdr(skb);
	if (nlh == NULL) {
		hwlog_err("netmanagerext_netlink_handle_rcv:nlh = NULL\n");
		goto skb_free;
	}
	if ((nlh->nlmsg_len < sizeof(struct nlmsghdr))
		|| (skb->len < nlh->nlmsg_len)) {
		hwlog_err("netmanagerext_netlink_handle_rcv:nlmsg len error\n");
		goto skb_free;
	}
	switch (nlh->nlmsg_type) {
	case NL_MSG_REG_NS:
		hwlog_info("netmanagerext_NL_MSG_REG\n");
		g_ctx.native_pid = nlh->nlmsg_pid;
		break;
	case NL_MSG_JNI_REQ_NS:
		hwlog_info("netmanagerext_NL_MSG_JNI_REQ\n");
		process_cmd((struct req_msg_head_ns *)NLMSG_DATA(nlh), nlh->nlmsg_len - sizeof(struct nlmsghdr));
		break;
	default:
		hwlog_err("invalid nlmsg_type %d\n", nlh->nlmsg_type);
		break;
	}

skb_free:
	kfree_skb(skb);
	mutex_unlock(&g_recv_mtx_ns);
}

static struct msg_entity_ns *get_msg(void)
{
	struct msg_entity_ns *p = NULL;

	spin_lock_bh(&g_rpt_lock_ns);
	if (!list_empty_careful(&g_ctx.msg_head)) {
		p = list_last_entry(&g_ctx.msg_head, struct msg_entity_ns, head);
		list_del((struct list_head *)p);
	}
	spin_unlock_bh(&g_rpt_lock_ns);
	return p;
}

/* send a message to user space */
static int __nl_notify_event(struct res_msg_head_ns *msg)
{
	hwlog_info("__nl_notify_event\n");
	int ret = 0;
	struct sk_buff *skb = NULL;
	struct nlmsghdr *nlh = NULL;
	void *pdata = NULL;

	mutex_lock(&g_send_mtx_ns);
	if (!g_ctx.native_pid || !g_ctx.nlfd) {
		hwlog_err("%s: err pid = %d\n", __func__, g_ctx.native_pid);
		ret = -1;
		goto nty_end;
	}

	skb = nlmsg_new(msg->len, GFP_ATOMIC);
	if (!skb) {
		hwlog_info("%s: alloc skb fail\n", __func__);
		ret = -1;
		goto nty_end;
	}
	nlh = nlmsg_put(skb, 0, 0, msg->type, msg->len, 0);
	if (!nlh) {
		kfree_skb(skb);
		skb = NULL;
		ret = -1;
		goto nty_end;
	}

	pdata = nlmsg_data(nlh);
	memcpy_s(pdata, msg->len, msg, msg->len);

	/* skb will be freed in netlink_unicast */
	ret = netlink_unicast(g_ctx.nlfd, skb, g_ctx.native_pid, MSG_DONTWAIT);

nty_end:
	mutex_unlock(&g_send_mtx_ns);
	return ret;
}

static int netlink_handle_thread(void *data)
{
	struct msg_entity_ns *p = NULL;

	while (!kthread_should_stop()) {
		down(&g_ctx.sema);
		hwlog_info("g_ctx.native_pid = %d\n", g_ctx.native_pid);
		if (g_ctx.native_pid == 0)
			continue;

		p = get_msg();
		while (p != NULL) {
			hwlog_info("netmanager_ext_netlink_handle_thread2, msgtype = %d\n", p->msg.type);			
			if (p->msg.type < INTER_MSG_BASE) {
				__nl_notify_event(&p->msg);
			} else {
				process_cmd((struct req_msg_head_ns *)&p->msg, p->msg.len);
			}
			kfree(p);
			p = get_msg();
		}
	}
	return 0;
}

/* netlink init function */
static int netmanagerext_netlink_handle_init(void)
{
	hwlog_info("%s: netmanagerext_netlink_handle_init_start\n", __func__);
	struct netlink_kernel_cfg nb_nl_cfg = {
		.input = netmanagerext_netlink_handle_rcv,
	};

	g_ctx.nlfd = netlink_kernel_create(&init_net,
		NETLINK_NETMANAGEREXT, &nb_nl_cfg);
	if (!g_ctx.nlfd) {
		hwlog_info("%s: netlink_handle_init failed\n", __func__);
		return -1;
	}
	sema_init(&g_ctx.sema, 0);

	g_ctx.task = kthread_run(netlink_handle_thread, NULL, "netlink_handle");
	if (IS_ERR(g_ctx.task)) {
		hwlog_err("%s:failed to create thread\n", __func__);
		g_ctx.task = NULL;
		return -1;
	}
	g_ctx.chan_state = NETLINK_HANDLE_INIT;
	g_ctx.msg_head.prev = &g_ctx.msg_head;
	g_ctx.msg_head.next = &g_ctx.msg_head;
	hwlog_info("%s: netmanagerext_netlink_handle_init_end\n", __func__);
	return 0;
}

/* netlink deinit function */
static void netmanagerext_netlink_handle_exit(void)
{
	if (g_ctx.nlfd && g_ctx.nlfd->sk_socket) {
		sock_release(g_ctx.nlfd->sk_socket);
		g_ctx.nlfd = NULL;
	}

	if (g_ctx.task) {
		kthread_stop(g_ctx.task);
		g_ctx.task = NULL;
	}
}

typedef msg_process_ns* (*net_link_init_func)(notify_event_ns *fn);
typedef struct {
	enum install_model_ns model;
	net_link_init_func pfn_handler;
	char* func_name;
} net_link_func_handler_stru;

static const net_link_func_handler_stru s_init_comm_msg_tbl[] = {
#ifdef CONFIG_HW_NETWORK_QOE
 	{ IP_PARA_COLLEC_NS, networkslice_ip_para_collec_init, "networkslice_ip_para_collec_init" },
#endif
#ifdef CONFIG_HW_NETWORK_SLICE_NETMGR
	{ NETWORK_SLICE_MANAGEMENT_NS, network_slice_management_init, "network_slice_management_init" },
#endif	
};

static int __init netmanagerext_netlink_module_init(void)
{
	int index;
	int count;
	msg_process_ns *fn = NULL;

	if (netmanagerext_netlink_handle_init()) {
		hwlog_err("%s:init netlink_handle module failed\n", __func__);
		g_ctx.chan_state = NETLINK_HANDLE_EXIT;
		return -1;
	}

	memset_s(&g_ctx.model_cb[0], MODEL_NUM_NS * sizeof(msg_process_ns *), 0, MODEL_NUM_NS * sizeof(msg_process_ns *));
	count = (int)(sizeof(s_init_comm_msg_tbl) / sizeof(s_init_comm_msg_tbl[0]));
	for (index = 0; index < count; index++) {
		fn = s_init_comm_msg_tbl[index].pfn_handler(nl_notify_event);
		if (fn == NULL) {
			hwlog_err("%s:init %s failed\n", __func__, s_init_comm_msg_tbl[index].func_name);
			return -1;
		}
		g_ctx.model_cb[s_init_comm_msg_tbl[index].model] = fn;
	}
	hwlog_info("%s:netlink_handle module inited:\n", __func__);
	return 0;
}

static void __exit netmanagerext_netlink_module_exit(void)
{
#ifdef CONFIG_HW_NETWORK_QOE
	networkslice_ip_para_collec_exit();
#endif
	g_ctx.chan_state = NETLINK_HANDLE_EXIT;
	netmanagerext_netlink_handle_exit();
}

module_init(netmanagerext_netlink_module_init);
module_exit(netmanagerext_netlink_module_exit);