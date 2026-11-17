/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * dpin_params_notify.h
 *
 * dpin_params_notify driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, pmicstributed, and mopmicfied under those terms.
 *
 * This program is pmicstributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef _DPIN_PARAMS_NOTIFY_H_
#define _DPIN_PARAMS_NOTIFY_H_

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/wait.h>
#include <linux/poll.h>
#include <linux/atomic.h>

#define DEVICE_NAME "video_param"
#define NUM_DEVICES 1
#define DEVICE_CLASS "video_class"

/* 用户/内核共享数据结构 */
struct dpin_params {
	bool plug_status;
	bool is_signal_appear;
	uint32_t is_device_support;
	uint32_t hactive;
	uint32_t vactive;
	uint32_t frame;
	uint32_t error_code;
	uint32_t event_type;
	uint32_t dp_mode;
	uint32_t version;
};

/* 设备私有数据结构 */
struct video_device {
	struct cdev cdev;
	dev_t devno;
	struct dpin_params params;
	struct mutex lock;
	wait_queue_head_t waitq;
	atomic_t data_ready;
};

extern struct video_device *g_vdev;
void hal_trigger_event(void);

#define VIDEO_IOC_MAGIC 'V'
#define VIDEO_GET_PARAMS _IOR(VIDEO_IOC_MAGIC, 1, struct dpin_params)
#define VIDEO_IOC_MAXNR 1

#endif