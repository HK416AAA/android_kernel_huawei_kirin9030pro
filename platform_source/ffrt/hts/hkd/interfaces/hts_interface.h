/*
 * hts_interface.h
 *
 * hts interface head file
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

#ifndef __HTS_INTERFACE_H__
#define __HTS_INTERFACE_H__
#include <linux/types.h>
#define HTS_INTERFACE_MAX_EVENT_BUFF             100

struct dev_event_info {
	uint8_t dev_id;
	uint16_t uid;
	uint16_t events[HTS_INTERFACE_MAX_EVENT_BUFF];
	uint16_t event_count;
};

struct dev_pid_info {
	uint32_t dev_id;
	int32_t pid;
};

int hts_block_dev(uint32_t dev_id);
int hts_block_event(uint16_t event);
int ffts_outbuff_block_event(uint16_t event);
int hts_block_proc(struct dev_pid_info info);
int ip_get_hts_uid_event(struct dev_event_info *info);
int hts_event_outbuff_enable(uint16_t *event_id, uint16_t event_num);
int hts_event_outbuff_disable(uint16_t *event_id, uint16_t event_num);
int hts_event_outbuff_enable_by_dev(uint32_t dev_id);
int hts_event_outbuff_disable_by_dev(uint32_t dev_id);
int hts_connect(uint32_t dev_id);
int hts_disconnect(uint32_t dev_id);
int hts_notify_event_exception(struct dev_pid_info info);
#endif