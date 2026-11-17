/*
 * hw_binder_record.c
 *
 * maintains a binder information table and provides the add, delete, modify, and query functions.
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
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

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/ioctl.h>
#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/rbtree.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <linux/sched/clock.h>
#include <linux/time.h>
#include <linux/workqueue.h>
#ifdef CONFIG_COMPAT
#include <linux/compat.h>
#endif /* CONFIG_COMPAT */
#include <securec.h>
#include <huawei_platform/power/hw_binder_record.h>

#define MIN_REPORT_INTERVAL 10      // minimum interval between two reports, ms
#define MAX_CALLER_NUM 10           // maximum number of callers
#define BINDER_RECORD_MAX_NUM 100
#define PRINT_BUFFER_SIZE 256
#define CUR_TIMESTAMP (local_clock() / NSEC_PER_MSEC)

enum binder_record_inner_event_type {
	BR_EVT_UPDATE_RECORD,
	BR_EVT_REMOVE_RECORD_BY_CALLEE,
	BR_EVT_REMOVE_RECORD_BY_CALLER,
	BR_EVT_CLEAR_RECORD,
};

struct binder_timestamp {
	int caller_pid;
	int callee_pid;
	u64 last_timestamp;  // last binder timstamp, ms
	u64 cur_timestamp;   // current timestamp, ms
};

struct binder_record_info {
	int caller_pid;
	int callee_pid;
	u64 timestamp;  // timstamp of the last binder communication
};

struct binder_record_list {
	unsigned int num;
	u64 cur_timestamp;  // current timestamp, ms
	struct binder_record_info node[BINDER_RECORD_MAX_NUM];
};

struct caller_info {
	bool status;
	int pid;
};

/* for ioctl cmd */
#define BINDER_RECORD_GET_TIMESTAMP _IOR('b', 1, struct binder_timestamp)
#define BINDER_RECORD_GET_ALL _IOR('b', 2, struct binder_record_list)
#define BINDER_RECORD_UPDATE_CALLER_STATUS _IOW('b', 3, struct caller_info)
#define BINDER_RECORD_PRINT_ALL _IO('b', 4)
#define BINDER_RECORD_REMOVE_PID _IOW('b', 5, int32_t)
#define BINDER_RECORD_REMOVE_ALL _IO('b', 6)

/* binder_record node info, associated under binder_record_base->rb_root */
struct binder_record {
	struct rb_node rb_node;                 // associated under rb_root
	struct binder_record_info binder_info;  // record binder information
};

/* binder_record base info, eg: rb_tree root node */
struct binder_record_base {
	struct mutex rb_lock;
	struct rb_root rb_root;  // rb_tree root node, to save binder_record
};

struct binder_record_last_report_info {
	int pid;        // last report pid
	u64 timestamp;  // last report timestamp, ms
	struct mutex lock;
};

struct work_info {
	struct binder_record_info binder_info;
};

struct binder_record_work {
	struct work_struct work_node;
	struct work_info work_info;
	unsigned int event_type;
};

/* process in the list need to record binder. */
struct caller_list {
	struct mutex lock;
	struct list_head head;
};

/* caller pid needs to record binder */
struct caller_node {
	int pid;
	struct list_head node;
};

typedef int (*traverse_proc_fun)(struct binder_record *, void *);
typedef void (*event_proc_fun)(struct work_info *);

static struct binder_record_base br_base_info;
static struct binder_record_last_report_info br_last_report_info;
static struct workqueue_struct *br_work_queue;
static struct caller_list br_caller_list;

static inline int binder_record_pid_cmp(const int pid1, const int pid2)
{
	if (pid1 < pid2) {
		return -1;
	} else if (pid1 > pid2) {
		return 1;
	} else {
		return 0;
	}
}

static inline void binder_record_update_data(struct binder_record_info *target, const struct binder_record_info *source)
{
	target->timestamp = source->timestamp;
	target->caller_pid = source->caller_pid;
}

static void binder_record_create_record(struct rb_node *parent_node, struct rb_node **link_node,
	const struct binder_record_info *binder_info)
{
	struct binder_record *new_record = kmalloc(sizeof(struct binder_record), GFP_KERNEL);
	if (unlikely(new_record == NULL)) {
		pr_err("%s: binder_record malloc fail\n", __func__);
		return;
	}

	(void)memcpy_s(&new_record->binder_info, sizeof(struct binder_record_info), binder_info,
		sizeof(struct binder_record_info));
	rb_link_node(&new_record->rb_node, parent_node, link_node);
	rb_insert_color(&new_record->rb_node, &br_base_info.rb_root);
	pr_debug("%s:new_record:%d-%d\n", __func__, new_record->binder_info.caller_pid, new_record->binder_info.callee_pid);
}

/*
* if the node exists, update it.
* if the node does not exist, create it.
*/
static void binder_record_update_record(struct work_info *work)
{
	int ret;
	struct rb_node *parent_node = NULL;
	struct rb_node **link_node = NULL;
	struct binder_record *tmp_record = NULL;
	struct binder_record_info *input = &work->binder_info;

	mutex_lock(&br_base_info.rb_lock);
	link_node = &br_base_info.rb_root.rb_node;
	while (*link_node) {
		parent_node = *link_node;
		tmp_record = rb_entry(parent_node, struct binder_record, rb_node);
		ret = binder_record_pid_cmp(input->callee_pid, tmp_record->binder_info.callee_pid);
		if (ret < 0) {
			link_node = &parent_node->rb_left;
		} else if (ret > 0) {
			link_node = &parent_node->rb_right;
		} else {
			/* node already exists, update it directly */
			binder_record_update_data(&tmp_record->binder_info, input);
			goto out;
		}
	}

	/* node not exist, create one */
	binder_record_create_record(parent_node, link_node, input);
out:
	mutex_unlock(&br_base_info.rb_lock);
}

/* no lock in this function. need lock when invoking the function. */
static struct binder_record *binder_record_query_record(const int pid)
{
	int ret;
	struct binder_record *tmp_record = NULL;

	struct rb_node *tmp_node = br_base_info.rb_root.rb_node;
	while (tmp_node) {
		tmp_record = rb_entry(tmp_node, struct binder_record, rb_node);
		ret = binder_record_pid_cmp(pid, tmp_record->binder_info.callee_pid);
		if (ret < 0) {
			tmp_node = tmp_node->rb_left;
		} else if (ret > 0) {
			tmp_node = tmp_node->rb_right;
		} else {
			return tmp_record;
		}
	}

	pr_debug("%s: not find pid(%d)\n", __func__, pid);
	return NULL;
}

static inline void binder_record_delete_node(struct binder_record *record)
{
	rb_erase(&record->rb_node, &br_base_info.rb_root);
	kfree(record);
}

static void binder_record_remove_record_by_callee(struct work_info *work)
{
	int pid = work->binder_info.callee_pid;
	mutex_lock(&br_base_info.rb_lock);
	struct binder_record *record = binder_record_query_record(pid);
	if (record == NULL) {
		mutex_unlock(&br_base_info.rb_lock);
		pr_debug("%s: cannot find pid=%d\n", __func__, pid);
		return;
	}

	binder_record_delete_node(record);
	mutex_unlock(&br_base_info.rb_lock);
	pr_debug("%s: pid=%d\n", __func__, pid);
}

static void binder_record_remove_record_by_caller(struct work_info *work)
{
	struct rb_node *node = NULL;
	struct rb_node *next = NULL;
	struct binder_record *record = NULL;
	unsigned int cnt = 0;
	const int caller_pid = work->binder_info.caller_pid;

	mutex_lock(&br_base_info.rb_lock);
	for (node = rb_first(&br_base_info.rb_root); node != NULL; node = next) {
		next = rb_next(node);
		record = rb_entry(node, struct binder_record, rb_node);
		if (record->binder_info.caller_pid == caller_pid) {
			binder_record_delete_node(record);
			cnt++;
		}
	}
	mutex_unlock(&br_base_info.rb_lock);
	pr_info("%s: caller_pid=%d cnt=%u\n", __func__, caller_pid, cnt);
}

static void binder_record_clear_record(struct work_info *work)
{
	unsigned int cnt = 0;
	struct rb_node *node = NULL;
	struct binder_record *record = NULL;

	mutex_lock(&br_base_info.rb_lock);
	while ((node = rb_last(&br_base_info.rb_root))) {
		record = rb_entry(node, struct binder_record, rb_node);
		binder_record_delete_node(record);
		cnt++;
	}
	mutex_unlock(&br_base_info.rb_lock);
	pr_info("%s: total cnt=%u\n", __func__, cnt);
}

static void binder_record_traverse_record(traverse_proc_fun fun, void *param)
{
	int ret;
	struct rb_node *node = NULL;
	struct binder_record *record = NULL;

	mutex_lock(&br_base_info.rb_lock);
	for (node = rb_first(&br_base_info.rb_root); node != NULL; node = rb_next(node)) {
		record = rb_entry(node, struct binder_record, rb_node);
		ret = fun(record, param);
		if (ret < 0) {
			pr_err("%s: traverse_proc fail(%d) at(%d).\n", __func__, ret, record->binder_info.callee_pid);
			break;
		}
	}
	mutex_unlock(&br_base_info.rb_lock);
}

static const event_proc_fun event_proc_tbl[] = {
	[BR_EVT_UPDATE_RECORD] = binder_record_update_record,
	[BR_EVT_REMOVE_RECORD_BY_CALLEE] = binder_record_remove_record_by_callee,
	[BR_EVT_REMOVE_RECORD_BY_CALLER] = binder_record_remove_record_by_caller,
	[BR_EVT_CLEAR_RECORD] = binder_record_clear_record,
};

static void binder_record_event_handler(struct work_struct *node)
{
	if (unlikely(!node)) {
		pr_err("%s: node null\n", __func__);
		return;
	}

	struct binder_record_work *work = container_of(node, struct binder_record_work, work_node);
	pr_debug("%s: event_type(%u) pid(%d)\n", __func__, work->event_type, work->work_info.binder_info.callee_pid);
	if (unlikely(work->event_type >= sizeof(event_proc_tbl) / sizeof(event_proc_tbl[0]))) {
		pr_err("%s: unknown event_type=%u\n", __func__, work->event_type);
		goto out;
	}

	if (likely(event_proc_tbl[work->event_type])) {
		event_proc_tbl[work->event_type](&work->work_info);
	}
out:
	kfree(work);
}

static void binder_record_send_event(const unsigned int event_type, const struct work_info *input)
{
	if (unlikely(br_work_queue == NULL)) {
		pr_err("%s: work_queue is null\n", __func__);
		return;
	}

	struct binder_record_work *work = kmalloc(sizeof(struct binder_record_work), GFP_KERNEL);
	if (unlikely(work == NULL)) {
		pr_err("%s: malloc work fail\n", __func__);
		return;
	}

	/* some events do not need input, eg: clear all */
	if (input != NULL) {
		(void)memcpy_s(&work->work_info, sizeof(struct work_info), input, sizeof(struct work_info));
	}
	work->event_type = event_type;
	INIT_WORK(&work->work_node, binder_record_event_handler);
	queue_work(br_work_queue, &work->work_node);
}

/* no lock in this function. need lock when invoking the function. */
static struct caller_node *binder_record_query_caller_node(const int pid)
{
	struct caller_node *caller = NULL;
	list_for_each_entry(caller, &br_caller_list.head, node) {
		if (caller->pid == pid) {
			return caller;
		}
	}
	pr_debug("%s: not found caller pid:%d\n", __func__, pid);
	return NULL;
}

static void binder_record_creat_caller_node(const int pid)
{
	struct caller_node *node = kmalloc(sizeof(struct caller_node), GFP_KERNEL);
	if (unlikely(node == NULL)) {
		pr_err("%s: malloc caller_node fail\n", __func__);
		return;
	}
	node->pid = pid;
	list_add_tail(&node->node, &br_caller_list.head);
	pr_info("%s: insert caller pid %d\n", __func__, pid);
}

static inline void binder_record_delete_caller_node(struct caller_node *caller_node)
{
	pr_info("%s: delete caller pid %d\n", __func__, caller_node->pid);
	list_del(&caller_node->node);
	kfree(caller_node);
}

static void binder_record_update_caller_list(struct caller_info *info)
{
	mutex_lock(&br_caller_list.lock);
	struct caller_node *caller = binder_record_query_caller_node(info->pid);
	if (info->status && caller == NULL) {
		/* if not exist, create one */
		binder_record_creat_caller_node(info->pid);
	} else if (!info->status && caller != NULL) {
		/* if exist, delete it */
		binder_record_delete_caller_node(caller);
		struct work_info work = {0};
		work.binder_info.caller_pid = info->pid;
		binder_record_send_event(BR_EVT_REMOVE_RECORD_BY_CALLER, &work);
	}
	mutex_unlock(&br_caller_list.lock);
}

static void binder_record_clear_caller_list(void)
{
	unsigned int cnt = 0;
	struct caller_node *entry = NULL;
	struct caller_node *tmp = NULL;

	mutex_lock(&br_caller_list.lock);
	list_for_each_entry_safe(entry, tmp, &br_caller_list.head, node) {
		binder_record_delete_caller_node(entry);
		cnt++;
	}
	INIT_LIST_HEAD(&br_caller_list.head);
	mutex_unlock(&br_caller_list.lock);
	pr_info("%s: total cnt:%u\n", __func__, cnt);
}

void binder_record_remove_pid(const int pid)
{
	pr_debug("%s: pid=%d\n", __func__, pid);
	struct work_info info = {0};
	info.binder_info.callee_pid = pid;
	binder_record_send_event(BR_EVT_REMOVE_RECORD_BY_CALLEE, &info);
}

static bool binder_record_need_filter_caller(const int caller_pid)
{
	mutex_lock(&br_caller_list.lock);
	bool ret = (binder_record_query_caller_node(caller_pid) == NULL);
	mutex_unlock(&br_caller_list.lock);
	return ret;
}

/* one pid will call the function many times at the same time,
 * so add a filter here to avoid sending too many same events */
static bool binder_record_need_filter_timestamp(const int pid, const u64 timestamp)
{
	if (!mutex_trylock(&br_last_report_info.lock)) {
		/* if trylock fail, add record directly */
		pr_debug("%s: try lock fail, pid(%d) timestamp(%llu)\n", __func__, pid, timestamp);
		return false;
	}
	if (pid != br_last_report_info.pid) {
		br_last_report_info.pid = pid;
		br_last_report_info.timestamp = timestamp;
		mutex_unlock(&br_last_report_info.lock);
		return false;
	}
	if (timestamp > br_last_report_info.timestamp &&
		timestamp - br_last_report_info.timestamp >= MIN_REPORT_INTERVAL) {
		br_last_report_info.timestamp = timestamp;
		mutex_unlock(&br_last_report_info.lock);
		return false;
	}

	pr_debug("%s: ignore pid(%d) timestamp(%llu-%llu)\n", __func__, pid, timestamp, br_last_report_info.timestamp);
	mutex_unlock(&br_last_report_info.lock);
	return true;
}

void binder_record_add_record(const int caller_pid, const int callee_pid)
{
	if (likely(binder_record_need_filter_caller(caller_pid))) {
		return;
	}
	u64 timestamp = CUR_TIMESTAMP;
	if (binder_record_need_filter_timestamp(callee_pid, timestamp)) {
		return;
	}

	struct work_info info = {0};
	info.binder_info.caller_pid = caller_pid;
	info.binder_info.callee_pid = callee_pid;
	info.binder_info.timestamp = timestamp;
	binder_record_send_event(BR_EVT_UPDATE_RECORD, &info);
}

static void binder_record_query_timestamp(struct binder_timestamp *timestamp_info)
{
	mutex_lock(&br_base_info.rb_lock);
	struct binder_record *record = binder_record_query_record(timestamp_info->callee_pid);
	if (record != NULL) {
		timestamp_info->caller_pid = record->binder_info.caller_pid;
		timestamp_info->last_timestamp = record->binder_info.timestamp;
		timestamp_info->cur_timestamp = CUR_TIMESTAMP;
	}
	mutex_unlock(&br_base_info.rb_lock);
	pr_debug("%s: pid=%d-%d, timestamp=%llu-%llu\n", __func__, timestamp_info->caller_pid, timestamp_info->callee_pid,
		timestamp_info->cur_timestamp, timestamp_info->last_timestamp);
}

static long binder_record_ioctl_get_timestamp(unsigned int cmd, unsigned long arg)
{
	void __user *buff = (void __user *)arg;
	struct binder_timestamp timestamp_info = {0};
	if (unlikely(_IOC_SIZE(cmd) != sizeof(timestamp_info))) {
		pr_err("%s: invalid size=%lu\n", __func__, _IOC_SIZE(cmd));
		return -EINVAL;
	}
	int ret = copy_from_user(&timestamp_info, buff, sizeof(timestamp_info));
	if (unlikely(ret != 0)) {
		pr_err("%s: copy_from_user fail=%d\n", __func__, ret);
		return ret;
	}

	binder_record_query_timestamp(&timestamp_info);
	ret = copy_to_user(buff, &timestamp_info, sizeof(timestamp_info));
	if (unlikely(ret != 0)) {
		pr_err("%s: copy_to_user fail=%d\n", __func__, ret);
		return ret;
	}

	return 0;
}

static int binder_record_get_single_record(struct binder_record *record, void *param)
{
	struct binder_record_list *list = (struct binder_record_list *)param;
	if (unlikely(list->num >= BINDER_RECORD_MAX_NUM)) {
		pr_err("%s: num over max\n", __func__);
		return -1;
	}
	list->node[list->num++] = record->binder_info;
	return 0;
}

static long binder_record_ioctl_get_all(unsigned int cmd, unsigned long arg)
{
	struct binder_record_list __user *p = (struct binder_record_list __user *)arg;
	struct binder_record_list list;
	list.num = 0;
	binder_record_traverse_record(binder_record_get_single_record, &list);

	if (unlikely(_IOC_SIZE(cmd) < sizeof(list))) {
		pr_err("%s: size %lu < %lu\n", __func__, _IOC_SIZE(cmd), sizeof(list));
		return -EINVAL;
	}
	if (unlikely(put_user(CUR_TIMESTAMP, &p->cur_timestamp))) {
		pr_err("%s: set timestamp fail\n", __func__);
		return -EFAULT;
	}
	if (unlikely(put_user(list.num, &p->num))) {
		pr_err("%s: set num fail\n", __func__);
		return -EFAULT;
	}
	if (unlikely(copy_to_user(p->node, list.node, sizeof(list.node[0]) * list.num))) {
		pr_err("%s: copy node fail\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static void binder_record_ioctl_update_caller_status(unsigned int cmd, unsigned long arg)
{
	void __user *buff = (void __user *)arg;
	struct caller_info info = {0};
	if (unlikely(_IOC_SIZE(cmd) != sizeof(struct caller_info))) {
		pr_err("%s: invalid size=%lu\n", __func__, _IOC_SIZE(cmd));
		return;
	}
	int ret = copy_from_user(&info, buff, sizeof(struct caller_info));
	if (ret != 0 || info.pid <= 0) {
		pr_err("%s: copy_from_user fail=%d pid=%d\n", __func__, ret, info.pid);
		return;
	}

	pr_debug("%s: pid=%d status=%d\n", __func__, info.pid, info.status);
	binder_record_update_caller_list(&info);
}

static void binder_record_print_last_report_info(void)
{
	mutex_lock(&br_last_report_info.lock);
	pr_info("last_report pid=%d, timestamp=%llu\n", br_last_report_info.pid, br_last_report_info.timestamp);
	mutex_unlock(&br_last_report_info.lock);
}

static void binder_record_print_caller_list(void)
{
	char buffer[PRINT_BUFFER_SIZE] = {0};
	char *p = buffer;
	int left_size = PRINT_BUFFER_SIZE;
	struct caller_node *node = NULL;

	mutex_lock(&br_caller_list.lock);
	list_for_each_entry(node, &br_caller_list.head, node) {
		int n = sprintf_s(p, left_size, "%d,", node->pid);
		if (unlikely(n <= 0)) {
			buffer[0] = '\0';
			break;
		}
		left_size -= n;
		p += n;
	}
	mutex_unlock(&br_caller_list.lock);
	pr_info("caller_pid list:%s\n", buffer);
}

static int binder_record_print_single_record(struct binder_record *record, void *param)
{
	unsigned int *cnt = (unsigned int *)param;
	(*cnt)++;
	pr_info("%-10d %-10d %-20llu\n", record->binder_info.caller_pid, record->binder_info.callee_pid,
		record->binder_info.timestamp);
	return 0;
}

static void binder_record_ioctl_print_all(void)
{
	pr_info("binder_record_info:\n");
	pr_info("current timestamp=%llu\n", CUR_TIMESTAMP);
	binder_record_print_last_report_info();
	binder_record_print_caller_list();

	pr_info("%-10s %-10s %-20s\n", "caller", "callee", "timestamp");
	unsigned int cnt = 0;
	binder_record_traverse_record(binder_record_print_single_record, &cnt);
	pr_info("binder_record_end count=%u\n", cnt);
}

static long binder_record_ioctl_remove_pid(unsigned int cmd, unsigned long arg)
{
	if (unlikely(_IOC_SIZE(cmd) != sizeof(int32_t))) {
		pr_err("%s: invalid size=%lu\n", __func__, _IOC_SIZE(cmd));
		return -EINVAL;
	}
	int32_t pid = 0;
	if (unlikely(get_user(pid, (int32_t __user *)arg))) {
		pr_err("%s: get pid fail\n", __func__);
		return -EFAULT;
	}
	if (unlikely(pid <= 0)) {
		pr_err("%s: invalid pid:%d\n", __func__, pid);
		return -EFAULT;
	}

	binder_record_remove_pid(pid);
	return 0;
}

static void binder_record_ioctl_remove_all(void)
{
	binder_record_clear_caller_list();
	binder_record_send_event(BR_EVT_CLEAR_RECORD, NULL);
}

/* provides interfaces for the user layer */
static long binder_record_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	long ret = 0;
	switch (cmd) {
	case BINDER_RECORD_GET_TIMESTAMP:
		ret = binder_record_ioctl_get_timestamp(cmd, arg);
		break;
	case BINDER_RECORD_GET_ALL:
		ret = binder_record_ioctl_get_all(cmd, arg);
		break;
	case BINDER_RECORD_UPDATE_CALLER_STATUS:
		binder_record_ioctl_update_caller_status(cmd, arg);
		break;
	case BINDER_RECORD_PRINT_ALL:
		binder_record_ioctl_print_all();
		break;
	case BINDER_RECORD_REMOVE_PID:
		ret = binder_record_ioctl_remove_pid(cmd, arg);
		break;
	case BINDER_RECORD_REMOVE_ALL:
		binder_record_ioctl_remove_all();
		break;
	default:
		ret = -EINVAL;
		pr_err("%s: unknown cmd=%u\n", __func__, cmd);
		break;
	};

	pr_debug("%s: cmd=%u, ret=%ld arg=%llu\n", __func__, cmd, ret, arg);
	return ret;
}

#ifdef CONFIG_COMPAT
static long binder_record_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	/* normally, not go here */
	pr_info("%s: cmd=%u\n", __func__, cmd);
	return binder_record_ioctl(filp, cmd, (unsigned long)compat_ptr(arg));
}
#endif

static int binder_record_open(struct inode *inode, struct file *filp)
{
	pr_info("%s: enter\n", __func__);
	return 0;
}
static int binder_record_release(struct inode *inode, struct file *filp)
{
	pr_info("%s: enter\n", __func__);
	return 0;
}

static const struct file_operations binder_record_device_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = binder_record_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = binder_record_compat_ioctl,
#endif
	.open = binder_record_open,
	.release = binder_record_release,
};

static struct miscdevice binder_record_device = {
	.name = "binder_record",
	.fops = &binder_record_device_fops,
	.minor = MISC_DYNAMIC_MINOR,
};

static int __init binder_record_init(void)
{
	if (misc_register(&binder_record_device)) {
		pr_err("%s: misc_register fail\n", __func__);
		return -EFAULT;
	}

	mutex_init(&br_base_info.rb_lock);
	br_base_info.rb_root = RB_ROOT;
	mutex_init(&br_last_report_info.lock);
	br_last_report_info.pid = 0;
	br_last_report_info.timestamp = 0;
	mutex_init(&br_caller_list.lock);
	INIT_LIST_HEAD(&br_caller_list.head);
	br_work_queue = alloc_workqueue("%s", WQ_UNBOUND | WQ_HIGHPRI, 1, "binder_record_work_queue");
	if (!br_work_queue) {
		misc_deregister(&binder_record_device);
		pr_err("%s: alloc_workqueue failed\n", __func__);
		return -ENOMEM;
	}

	pr_info("%s end.\n", __func__);
	return 0;
}

static void __exit binder_record_exit(void)
{
	misc_deregister(&binder_record_device);

	if (br_work_queue) {
		flush_workqueue(br_work_queue);
		destroy_workqueue(br_work_queue);
		br_work_queue = NULL;
	}

	binder_record_clear_caller_list();
	binder_record_clear_record(NULL);
	pr_info("%s end.\n", __func__);
}

module_init(binder_record_init);
module_exit(binder_record_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Huawei Binder Record Driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");