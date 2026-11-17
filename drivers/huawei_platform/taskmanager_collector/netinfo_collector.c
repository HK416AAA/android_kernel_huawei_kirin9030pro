/*
 * netinfo_collector.c
 *
 * task manager process netinfo collector driver
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "netinfo_collector.h"

#include <securec.h>
#include <huawei_platform/log/hw_log.h>
#include <linux/sched/signal.h>
#include <linux/sched/task.h>
#include <linux/of.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/spinlock.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG taskmanager_collector
HWLOG_REGIST();

static struct class *collector_class;
static char kernel_buf[MAX_FILE_SIZE];
static int netinfo_collector_enable = 0;
static char *netinfo2str(void);
static void process_netinfo_hash_table_clean(void);
static int hash_node_num = 0;
spinlock_t task_manager_netinfo_spinlock;

static struct platform_device process_netinfo_collect_dev = {
	.name = "netinfo_collector",
	.id = -1,
};

static ssize_t collector_enable_show(struct device *dev,
				  struct device_attribute *attr,
				  char *buf)
{
	if (!dev || !attr || !buf) {
		hwlog_err("input NULL\n");
		return -EINVAL;
	}

	return snprintf_s(buf, COLLECTOR_ENABLE_BUF_SIZE, COLLECTOR_ENABLE_BUF_SIZE - 1, "%d\n", netinfo_collector_enable);
}

static ssize_t collector_enable_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf,
				 size_t size)
{
	int value = 0;
	if (!dev || !attr || !buf) {
		hwlog_err("input NULL\n");
		return -EINVAL;
	}

	if (kstrtoint(buf, 10, &value))
		return -EINVAL;

	if (value == 0) {
		spin_lock(&task_manager_netinfo_spinlock);
		process_netinfo_hash_table_clean();
		spin_unlock(&task_manager_netinfo_spinlock);
	}
	netinfo_collector_enable = value;

	return (ssize_t)size;
}

static ssize_t netinfo_show(struct device *dev,
				  struct device_attribute *attr,
				  char *buf)
{
	if (!dev || !attr || !buf) {
		hwlog_err("input NULL\n");
		return -EINVAL;
	}

	return snprintf_s(buf, MAX_FILE_SIZE, MAX_FILE_SIZE - 1, netinfo2str());
}

DEVICE_ATTR(collector_enable, 0600, collector_enable_show, collector_enable_store);
DEVICE_ATTR(process_netinfo, 0400, netinfo_show, NULL);

static struct attribute *collector_attributes[] = {
	&dev_attr_collector_enable.attr,
	&dev_attr_process_netinfo.attr,
	NULL,
};

static const struct attribute_group collector_attr_group = {
	.attrs = collector_attributes,
};

static const struct attribute_group *collector_attr_groups[] = {
	&collector_attr_group,
	NULL,
};

static const struct of_device_id taskmanager_driver_match_table[] = {
	{ .compatible = "huawei,taskmanager,netinfo_collector", },
	{},
};

MODULE_DEVICE_TABLE(of, taskmanager_driver_match_table);

static int collector_register(struct collector_cdev *cdev)
{
	if (!cdev) {
		hwlog_err("input NULL\n");
		return -EINVAL;
	}

	cdev->dev = device_create(collector_class, NULL, 0, cdev, "taskmanager_collector");
	if (cdev->dev == NULL) {
		hwlog_err("[%s] Failed to create taskmanager collector dev", __func__);
		return -EINVAL;
	}

	return 0;
}

static void collector_unregister(struct collector_cdev *cdev)
{
	device_destroy(collector_class, 0);
}

static int taskmanager_driver_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct collector_data *data = NULL;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;

	data->pdev = pdev;
	ret = collector_register(&data->cdev);
	if (ret != 0){
		devm_kfree(&pdev->dev, data);
		return ret;
	}
	platform_set_drvdata(pdev, data);
	return 0;
}

static int taskmanager_driver_remove(struct platform_device *pdev)
{
	struct collector_data *data = platform_get_drvdata(pdev);

	if (data == NULL) {
		hwlog_err("collector data null\n");
		return -ENOMEM;
	}

	collector_unregister(&data->cdev);
	return 0;
}

struct platform_driver taskmanager_driver = {
	.probe = taskmanager_driver_probe,
	.remove = taskmanager_driver_remove,
	.driver = {
		.name = TASKMANAGER_DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(taskmanager_driver_match_table),
	},
};

static struct process_netinfo_hash_table *p_netinfo_hash_table = NULL;

static inline unsigned int pid_hashfn(pid_t pid)
{
	return (unsigned int) pid & HASH_KEY_MASK;
}

static netinfo_node *find_netinfo_node(pid_t pid)
{
	struct hlist_head *head = &p_netinfo_hash_table->process_netinfo_hash_head[pid_hashfn(pid)];
	netinfo_node *pos;

	hlist_for_each_entry(pos, head, node) {
		if (pos->pid == pid)
			return pos;
	}

	return NULL;
}

static void update_netinfo(pid_t pid, unsigned long rx_bytes, unsigned long tx_bytes)
{
	netinfo_node *node = find_netinfo_node(pid);
	if (!node && hash_node_num <= MAX_HASH_NODE_NUM) {
		node = kzalloc(sizeof(netinfo_node), GFP_KERNEL);
		if (!node) {
			return;
		}
		node->pid = pid;
		node->net_stat.rx_bytes = rx_bytes;
		node->net_stat.tx_bytes = tx_bytes;
		hash_node_num++;
		INIT_HLIST_NODE(&node->node);

		hlist_add_head(&node->node, &p_netinfo_hash_table->process_netinfo_hash_head[pid_hashfn(pid)]);
	} else if (node) {
		node->net_stat.rx_bytes += rx_bytes;
		node->net_stat.tx_bytes += tx_bytes;
	}
}

void taskmanager_update_process_netinfo(unsigned long rx_bytes, unsigned long tx_bytes)
{
	if (netinfo_collector_enable != 1) {
		return;
	}

	pid_t pid = task_tgid_nr(current);

    if (!p_netinfo_hash_table) {
        return;
    }
    spin_lock(&task_manager_netinfo_spinlock);
	update_netinfo(pid, rx_bytes, tx_bytes);
	spin_unlock(&task_manager_netinfo_spinlock);
}
EXPORT_SYMBOL(taskmanager_update_process_netinfo);

static int process_netinfo_hash_table_init(void)
{
	int i;
	p_netinfo_hash_table = kzalloc(sizeof(struct process_netinfo_hash_table), GFP_KERNEL);
	if (!p_netinfo_hash_table) {
		hwlog_err("kzalloc failed!\n");
		return -ENOMEM;
	}

    for (i = 0; i < HASH_TABLE_LEN; i++) {
        INIT_HLIST_HEAD(&p_netinfo_hash_table->process_netinfo_hash_head[i]);
    }
    spin_lock_init(&task_manager_netinfo_spinlock);
	return 0;
}

static void process_netinfo_hash_table_clean(void)
{
	int i;
	struct hlist_node *tmp;
	struct hlist_head *head;
	netinfo_node *entry;

	hash_node_num = 0;
    if (p_netinfo_hash_table == NULL) {
        return;
    }

	for (i = 0; i < HASH_TABLE_LEN; i++) {
		head = &p_netinfo_hash_table->process_netinfo_hash_head[i];
		hlist_for_each_entry_safe(entry, tmp, head, node) {
			hlist_del(&entry->node);
			kfree(entry);
		}
	}
}

static void process_netinfo_hash_table_exit(void)
{
	process_netinfo_hash_table_clean();
	kfree(p_netinfo_hash_table);
	p_netinfo_hash_table = NULL;
}

static char *netinfo2str(void)
{
	int left = MAX_FILE_SIZE - 1;
	int cur = 0;
	int line_max = 100;
	int ret = 0;

	ret = memset_s(kernel_buf, sizeof(kernel_buf), 0, sizeof(kernel_buf));
	if (ret != 0){
		hwlog_err("%s: init memset fail\n", __func__);
	}

	spin_lock(&task_manager_netinfo_spinlock);
	for (int i = 0; i < HASH_TABLE_LEN; i++) {
		struct hlist_head *head = &p_netinfo_hash_table->process_netinfo_hash_head[i];
		netinfo_node *entry;
		struct hlist_node *tmp;

		hlist_for_each_entry_safe(entry, tmp, head, node) {
			int needed = snprintf_s(kernel_buf + cur, left + 1, left, "PID: %d, RX Bytes: %lu, TX Bytes: %lu\n",
				entry->pid, entry->net_stat.rx_bytes, entry->net_stat.tx_bytes);
			if (needed < 0) {
				break;
			}

			cur += needed;
			left -= needed;

			if (left <= 0) {
				break;
			}
		}

		if (left <= 0) {
			break;
		}
	}
	spin_unlock(&task_manager_netinfo_spinlock);
	ret = memset_s(kernel_buf + cur, left + 1, 0 ,left);
	if (ret != 0){
		hwlog_err("%s: Format memset fail\n", __func__);
	}
	return kernel_buf;
}

static int taskmanager_collector_init(void)
{
	int ret = 0;
	collector_class = class_create(THIS_MODULE, "taskmanager_collector");
    if (IS_ERR(collector_class)) {
        return PTR_ERR(collector_class);
    }

	hwlog_info("[%s]collector init\n", __func__);
	collector_class->dev_groups = collector_attr_groups;
	ret = platform_driver_register(&taskmanager_driver);
	if (ret) {
		hwlog_err("platform_driver_register error ret =%d\n", ret);
		goto platform_driver_register_err;
	}
	process_netinfo_hash_table_init();
	ret = platform_device_register(&process_netinfo_collect_dev);
	if (ret) {
		hwlog_err("%s: platform_device_register failed %d\n", __func__, ret);
		goto platform_device_register_err;
	}

	ret = sysfs_create_group(&process_netinfo_collect_dev.dev.kobj, &collector_attr_group);
	if (ret) {
		hwlog_err("collector_register sysfs_create_group error ret =%d\n", ret);
		goto sysfs_create_group_err;
	}

	return 0;
sysfs_create_group_err:
	platform_device_unregister(&process_netinfo_collect_dev);
platform_device_register_err:
	platform_driver_unregister(&taskmanager_driver);
platform_driver_register_err:
	class_destroy(collector_class);

	return ret;
}

static void taskmanager_collector_exit(void)
{
	hwlog_info("exit\n");
	class_destroy(collector_class);
	platform_driver_unregister(&taskmanager_driver);
	process_netinfo_hash_table_exit();
}

module_init(taskmanager_collector_init);
module_exit(taskmanager_collector_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("taskmanager collector driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");