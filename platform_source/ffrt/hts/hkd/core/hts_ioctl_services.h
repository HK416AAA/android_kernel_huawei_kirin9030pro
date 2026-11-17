/*
 * hts_ioctl_services.h
 *
 * hts ioctl services head file
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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

#ifndef __HTS_IOCTL_SERVICE_H
#define __HTS_IOCTL_SERVICE_H
#include <linux/cdev.h>
#include "hts_rule.h"

#define HTS_MAGIC   'H'
#define HTS_EVENT_ALLOC             _IO(HTS_MAGIC, 1)
#define HTS_EVENT_FREE              _IO(HTS_MAGIC, 2)
#define HTS_SET_RULE                _IO(HTS_MAGIC, 4)
#define HTS_UNSET_RULE              _IO(HTS_MAGIC, 5)
#define HTS_ENABLE_GRAPH       		_IO(HTS_MAGIC, 6)
#define HTS_DISABLE_GRAPH       	_IO(HTS_MAGIC, 7)
#ifdef HTS_DEBUG_EN
#define HTS_RESOURCE_CLEAR          _IO(HTS_MAGIC, 3)
#define HTS_PROFILING               _IO(HTS_MAGIC, 8)
#define HTS_PROC_EVENT_FREE         _IO(HTS_MAGIC, 9)
#endif
#define HTS_PROC_DESTORY_RULE       _IO(HTS_MAGIC, 10)
#define HTS_MAX_CMD                 11

typedef enum sched_type
{
	STATIC_SCHED = 0,
	DYNAMIC_SCHED,
	MAX_SCHED_TYPE
} sched_type;

struct hts_alloc_info {
    hts_graph_handle_t handle_t;
    uint16_t events[HTS_GRAPH_MAX_EVENT];
    uint32_t event_num;
    uint32_t event_type;
	uint32_t sched_type;
	uint32_t dev_type;
};

struct hts_event_set_param {
	int pid;
	uint32_t num;
	uint16_t events[HTS_GRAPH_MAX_EVENT];
};

struct hts_proc_destroy_rule_param {
	pid_t pid;
	uint32_t rule_num;
};

long hts_ioctl(struct file *filep, unsigned int cmd, unsigned long arg);

#endif