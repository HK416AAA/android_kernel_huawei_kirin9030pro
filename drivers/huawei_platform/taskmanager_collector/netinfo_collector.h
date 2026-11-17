/*
 * netinfo_collector.h
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

#ifndef NETINFO_COLLECTOR_H
#define NETINFO_COLLECTOR_H

#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/hashtable.h>
#include <linux/types.h>

#define COLLECTOR_ENABLE_BUF_SIZE            50
#define HASH_TABLE_BIT 8
#define HASH_TABLE_LEN (1 << HASH_TABLE_BIT)
#define HASH_KEY_MASK ((1 << HASH_TABLE_BIT) - 1)
#define MAX_FILE_SIZE 4096
#define MAX_HASH_NODE_NUM 10000

#define TASKMANAGER_DRIVER_NAME         "taskmanager,netinfo_collector"

typedef struct {
	unsigned long rx_bytes;
	unsigned long tx_bytes;
} proc_net_stats_value;

struct collector_cdev {
	struct device *dev;
	int collector_enable;
	char* net_stats;
};

struct collector_data {
	struct collector_cdev cdev;
	struct platform_device *pdev;
};

typedef struct {
	pid_t pid;
	proc_net_stats_value net_stat;
	struct hlist_node node;
} netinfo_node;

struct process_netinfo_hash_table {
	struct hlist_head process_netinfo_hash_head[HASH_TABLE_LEN];
};

void taskmanager_update_process_netinfo(unsigned long rx_bytes, unsigned long tx_bytes);
#endif
