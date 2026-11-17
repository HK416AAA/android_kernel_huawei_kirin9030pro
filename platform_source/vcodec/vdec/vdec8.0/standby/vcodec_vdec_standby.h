/*
 * vcodec_vdec_standby.h
 *
 * This is for vdec standby in idle
 *
 * Copyright (c) 2025-2025 Huawei Technologies CO., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef VCODEC_VDEC_STANDBY
#define VCODEC_VDEC_STANDBY

#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/workqueue.h>
#include "vcodec_types.h"

typedef struct {
	// the timing duration of the timer, unit ms
	uint32_t ctrl_time;
	struct timer_list timer;
	struct work_struct work;
	struct workqueue_struct *queue;
} vdec_standby;

int32_t vdec_standby_control_init(void);
void vdec_standby_control_deinit(void);
void reset_timer(void);
void stop_timer(bool is_sync);

#endif