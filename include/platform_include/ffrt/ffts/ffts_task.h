/*
 * ffts_task.h
 *
 * ffts task
 *
 * Copyright (c) 2024-2030 Huawei Technologies Co., Ltd.
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
#ifndef _FFTS_TASK_H_
#define _FFTS_TASK_H_

#include <linux/types.h>

struct exception_task {
	uint16_t recv_event;
	uint16_t uid;
	uint16_t hwtype;
	uint16_t taskidx;
	uint16_t qos;
};

int ffts_query_exception_task(struct exception_task *task_info);

int ffts_process_exception_task(struct exception_task *task_info);

uint32_t ffts_notify_excep_event_to_rtb(struct exception_task *task_info);

#endif