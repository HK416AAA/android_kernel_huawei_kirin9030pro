// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 *
 * Operations on the lowpower protocol
 * Authors: yangyanjun
 */
#ifdef CONFIG_LOWPOWER_PROTOCOL
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/printk.h>
#include <linux/list.h>
#include <linux/rwlock_types.h>
#include <linux/net_namespace.h>
#include <net/sock.h>
#include <net/ip.h>
#include <net/tcp.h>
#include <net/lowpower_protocol.h>
#ifdef CONFIG_DPA_API
#include <dpa/dpa_rproc.h>
#endif /* CONFIG_DPA_API */

#define OPT_LEN 3
#define DPA_WIFI_SWITCH_LEN 15
#define TO_DECIMAL 10
#define LIST_MAX 500
#define DECIMAL_CHAR_NUM 10 // u32 decimal characters (4,294,967,295)
#define DPA_WIFI_MAX_PARAM 10
#define DPA_STACK_BYPASS_LEN 16
#define DPA_STACK_BYPASS_PARAM 1
static DEFINE_RWLOCK(g_dpa_rwlock);
static u32 g_dpa_uid_list_cnt;
static struct list_head g_dpa_uid_list;
static atomic_t dpa_wifi_switch = ATOMIC_INIT(0);
static atomic_t dpa_stack_bypass_status = ATOMIC_INIT(0);

struct dpa_data {
	uid_t uid;
	u32 setopt;
	u32 dpa_wifi_switch;
	u32 dpa_stack_bypass_status;
};
struct dpa_node {
	struct list_head list_node;
	struct dpa_data node;
};
static ext_init g_dpa_init_fun;

// cat /proc/net/dpa_uid
static int dpa_uid_show(struct seq_file *seq, void *v)
{
	struct dpa_node *node = NULL;
	struct dpa_node *tmp_node = NULL;

	read_lock(&g_dpa_rwlock);
	seq_printf(seq, "*************************************\n");
	seq_printf(seq, "        dpa wifi switch\n");
	seq_printf(seq, "*************************************\n");
	seq_printf(seq, "         wifi status: %u\n\n", atomic_read(&dpa_wifi_switch));
	seq_printf(seq, "*************************************\n");
	seq_printf(seq, "        dpa stack bypass status\n");
	seq_printf(seq, "*************************************\n");
	seq_printf(seq, "         bypass status: %u\n\n", atomic_read(&dpa_stack_bypass_status) != 0);
	if (g_dpa_uid_list_cnt) {
		seq_printf(seq, "*************************************\n");
		seq_printf(seq, "        uid  sockopt  list-cnt(%u)\n", g_dpa_uid_list_cnt);
		seq_printf(seq, "*************************************\n");
	}
	list_for_each_entry_safe(node, tmp_node, &g_dpa_uid_list, list_node)
		seq_printf(seq, "%11u  %7u\n", node->node.uid, node->node.setopt);
	read_unlock(&g_dpa_rwlock);
	return 0;
}

// echo "add/del + uid1 + setOPT(0/1) + uid2 + setOPT(0/1) + ... \n" > /proc/net/dpa_uid
static int dpa_uid_add(struct dpa_data *input);
static int dpa_uid_del(struct dpa_data *input);
static int get_dpa_parameters(char *buf, size_t size, struct dpa_data *uid_list,
			u32 index_max, u32 *index);
static void dpa_ext_init(void);

static int dpa_uid_write(struct file *file, char *buf, size_t size)
{
	struct dpa_data *dpa_list;
	u32 index = 0;
	int ret = -EINVAL;
	int i;

	dpa_list = (struct dpa_data *)kmalloc(LIST_MAX * sizeof(struct dpa_data), GFP_KERNEL);
	if (!dpa_list)
		return ret;

	if (get_dpa_parameters(buf, size, dpa_list, LIST_MAX, &index) != 0) {
		kfree(dpa_list);
		pr_err("[dpa-uid-cfg] fail to parse dpa parameters\n");
		return ret;
	}

	if (strncmp(buf, "add", OPT_LEN) == 0) {
		dpa_ext_init();
		for (i = 0; i < index; i++) {
			ret = dpa_uid_add(dpa_list + i);
			if (ret != 0) {
				kfree(dpa_list);
				return ret;
			}
		}
	} else if (strncmp(buf, "del", OPT_LEN) == 0) {
		for (i = 0; i < index; i++) {
			ret = dpa_uid_del(dpa_list + i);
			if (ret != 0) {
				kfree(dpa_list);
				return ret;
			}
		}
	} else if (strncmp(buf, "dpa_wifi_switch", DPA_WIFI_SWITCH_LEN) == 0) {
		if (dpa_list->dpa_wifi_switch <= DPA_WIFI_MAX_PARAM) {
#ifdef CONFIG_DPA_API
			dpa_wlan_default_path_switch(dpa_list->dpa_wifi_switch);
#endif /* CONFIG_DPA_API */
			atomic_set(&dpa_wifi_switch, dpa_list->dpa_wifi_switch);
		} else {
			pr_err("[dpa-uid-cfg] dpa_wifi_switch=%u invalid\n", dpa_list->dpa_wifi_switch);
		}
		kfree(dpa_list);
		return 0;
	} else if (strncmp(buf, "dpa_stack_bypass", DPA_STACK_BYPASS_LEN) == 0) {
		if (dpa_list->dpa_stack_bypass_status <= DPA_STACK_BYPASS_PARAM) {
			atomic_set(&dpa_stack_bypass_status, (dpa_list->dpa_stack_bypass_status != 0));
		} else {
			pr_err("[dpa-uid-cfg] dpa_stack_bypass_status=%u invalid\n", dpa_list->dpa_stack_bypass_status);
		}
		kfree(dpa_list);
		return 0;
	} else {
		pr_err("[dpa-uid-cfg] cmd unknown\n");
	}
	kfree(dpa_list);
	return ret;
}

static int dpa_uid_add(struct dpa_data *input)
{
	bool exist = false;
	struct dpa_node *cur_node = NULL;
	struct dpa_node *tmp_node = NULL;

	write_lock(&g_dpa_rwlock);
	if (g_dpa_uid_list_cnt >= LIST_MAX) {
		write_unlock(&g_dpa_rwlock);
		return -EFBIG;
	}

	list_for_each_entry_safe(cur_node, tmp_node, &g_dpa_uid_list, list_node) {
		if (cur_node->node.uid == input->uid) {
			exist = true;
			cur_node->node.setopt = input->setopt;
			break;
		}
	}

	if (!exist) {
		cur_node = kzalloc(sizeof(*cur_node), GFP_ATOMIC);
		if (cur_node) {
			cur_node->node = *input;
			list_add_tail(&cur_node->list_node, &g_dpa_uid_list);
			g_dpa_uid_list_cnt++;
		}
	}
	write_unlock(&g_dpa_rwlock);
	return 0;
}

static int dpa_uid_del(struct dpa_data *input)
{
	struct dpa_node *cur_node = NULL;
	struct dpa_node *tmp_node = NULL;

	write_lock(&g_dpa_rwlock);
	list_for_each_entry_safe(cur_node, tmp_node, &g_dpa_uid_list, list_node) {
		if (cur_node->node.uid == input->uid) {
			list_del(&cur_node->list_node);
			if (g_dpa_uid_list_cnt)
				--g_dpa_uid_list_cnt;
			break;
		}
	}
	write_unlock(&g_dpa_rwlock);
	return 0;
}

static int parse_single_data(char *begin, char *end)
{
	char *cur = NULL;
	uid_t uid = 0;
	int ret = -1;
	u32 len = end - begin;

	// u32 decimal characters (4,294,967,295)
	if (len > DECIMAL_CHAR_NUM) {
		pr_err("[dpa-uid-cfg] single uid len(%u) overflow\n", len);
		return ret;
	}

	cur = begin;
	while (cur < end) {
		if (*cur < '0' || *cur > '9') {
			pr_err("[dpa-uid-cfg] invalid character '%c'\n", *cur);
			return ret;
		}
		cur++;
	}

	uid = simple_strtoul(begin, &begin, TO_DECIMAL);
	if (!begin) {
		pr_err("[dpa-uid-cfg] fail to change str to data");
		return ret;
	}

	return uid;
}

static int parse_uids(char *args, u32 args_len, struct dpa_data *uid_list,
		      u32 index_max, u32 *index)
{
	char *begin = args;
	char *end = strchr(args, ' ');
	int input = 0;
	u32 len = 0;

	uid_list[*index].uid = 0;
	uid_list[*index].setopt = 0;
	while (end) {
		// get uid
		// cur decimal characters cnt + ' '
		len += end - begin + 1;
		if (len > args_len || *index > index_max) {
			pr_err("[dpa-uid-cfg][uid] str len(%u) or index(%u) overflow\n",
			       len, *index);
			return -ENFILE;
		}

		input = parse_single_data(begin, end);
		if (!input) // uid != 0
			return -EINVAL;
		uid_list[*index].uid = input;

		// get setopt
		begin = ++end; // next decimal characters (skip ' ')
		end = strchr(begin, ' ');
		if (!end) {
			break;
		}
		len += end - begin + 1;
		if (len > args_len || *index > index_max) {
			pr_err("[dpa-uid-cfg][setopt] str len(%u) or index(%u) overflow\n",
			       len, *index);
			return -ENFILE;
		}

		input = parse_single_data(begin, end);
		if (input < 0) { // setopt[0/1/2/...]
			pr_err("[dpa-uid-cfg] setopt[%u]=%u invalid\n", *index, input);
			return -EINVAL;
		}
		uid_list[(*index)++].setopt = input;
		uid_list[*index].uid = 0;
		uid_list[*index].setopt = 0;
		begin = ++end; // next decimal characters (skip ' ')
		end = strchr(begin, ' ');
	}

	// find last characters
	// get setopt
	end = strchr(begin, '\n');
	if (!end || end == begin) {
		pr_err("[dpa-uid-cfg] last character is not '\\n' or no valid data\n");
		return -EINVAL;
	}

	// cur decimal characters cnt + \n'
	len += end - begin + 1;
	if (len > args_len || *index > index_max || !uid_list[*index].uid) {
		pr_err("[dpa-uid-cfg] str len(%u) or last index(%u) overflow or uid[%u]=%u invalid\n",
			len, *index, *index, uid_list[*index].uid);
		return -ENFILE;
	}

	input = parse_single_data(begin, end);
	if (input < 0) { // setopt[0/1/2/...]
		pr_err("[dpa-uid-cfg] setopt[%u]=%u invalid\n", *index, input);
		return -EINVAL;
	}
	uid_list[(*index)++].setopt = input;
	return 0;
}

static int get_dpa_parameters(char *buf, size_t size, struct dpa_data *uid_list,
			u32 index_max, u32 *index)
{
	char *args = NULL;
	u32 opt_len;
	u32 data_len;

	// split into cmd and argslist
	args = strchr(buf, ' ');
	if (!args) {
		pr_err("[dpa-uid-cfg] cmd fmt invalid\n");
		return -EINVAL;
	}

	// cmd is add or del, len is 3
	opt_len = args - buf;
	if (opt_len == OPT_LEN) {
		data_len = size - (opt_len + 1);
		return parse_uids(args + 1, data_len, uid_list, index_max, index);
	} else if (opt_len == DPA_WIFI_SWITCH_LEN || opt_len == DPA_STACK_BYPASS_LEN) {
		char *begin = args + 1;
		char *end = strchr(begin, '\n');
		int ret = -EINVAL;

		if (!end || end == begin) {
			pr_err("[dpa-uid-cfg] last character is not '\\n' or no valid data\n");
			return -EINVAL;
		}

		ret = parse_single_data(begin, end);
		if (ret < 0) {
			pr_err("[dpa-uid-cfg] failed to fetch dpa wifi state, ret=%u\n", ret);
			return -EINVAL;
		}
		if (opt_len == DPA_WIFI_SWITCH_LEN) {
			uid_list[*index].dpa_wifi_switch = ret;
		} else if (opt_len == DPA_STACK_BYPASS_LEN) {
			uid_list[*index].dpa_stack_bypass_status = ret;
		}
		return 0;
	} else {
		pr_err("[dpa-uid-cfg] cmd len invalid\n");
		return -EINVAL;
	}

	return -EINVAL;
}

enum uid_match_t {
	NOT_MATCH = 0,
	UID_MATCH = 1,
};

bool get_dpa_stack_bypass_status(void)
{
    return atomic_read(&dpa_stack_bypass_status) != 0;
}
EXPORT_SYMBOL(get_dpa_stack_bypass_status);

u32 dpa_uid_match(uid_t kuid)
{
	u32 match = (u32)NOT_MATCH;
	struct dpa_node *cur_node = NULL;
	struct dpa_node *tmp_node = NULL;

	if (kuid == 0)
		return match;

	read_lock(&g_dpa_rwlock);
	list_for_each_entry_safe(cur_node, tmp_node, &g_dpa_uid_list, list_node) {
		if (cur_node->node.uid == kuid) {
			match = (u32)UID_MATCH + cur_node->node.setopt;
			break;
		}
	}
	read_unlock(&g_dpa_rwlock);
	return match;
}
EXPORT_SYMBOL(dpa_uid_match);

u32 dpa_uid_list_cnt(void)
{
	u32 cnt;
	read_lock(&g_dpa_rwlock);
	cnt = g_dpa_uid_list_cnt;
	read_unlock(&g_dpa_rwlock);
	return cnt;
}
EXPORT_SYMBOL(dpa_uid_list_cnt);

void regist_dpa_init(ext_init fun)
{
	if (!fun)
		return;
	g_dpa_init_fun = fun;
}
EXPORT_SYMBOL(regist_dpa_init);

static void dpa_ext_init(void)
{
	if (g_dpa_init_fun)
		g_dpa_init_fun();
}

void __net_exit lowpower_protocol_net_exit(struct net *net)
{
	remove_proc_entry("dpa_uid", net->proc_net);
}
// call this fun in net/ipv4/af_inet.c inet_init_net()
void __net_init lowpower_protocol_net_init(struct net *net)
{
	if (!proc_create_net_single_write("dpa_uid", 0644,
					  net->proc_net,
					  dpa_uid_show,
					  dpa_uid_write,
					  NULL))
		pr_err("fail to create /proc/net/dpa_uid");
}

static int __init lowpower_register(void)
{
	INIT_LIST_HEAD(&g_dpa_uid_list);
	return 0;
}

module_init(lowpower_register);
#endif /* CONFIG_LOWPOWER_PROTOCOL */
