/*
 * hts_event.h
 *
 * hts event head file
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
#ifndef __HTS_EVENT_H
#define __HTS_EVENT_H

#include "hts_ioctl_services.h"

#define HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM      16
struct event_range {
	event_alloc_type type;
	unsigned int event_id_start;
	unsigned int event_id_end;
};

struct graph_event_range {
	uint32_t graph_id;
	unsigned int event_id_start;
	unsigned int event_id_end;
};

int hts_event_free(uint16_t uid, uint16_t *tmp_events, uint32_t num);
uint32_t hts_event_get_num_by_uid(uint16_t uid);
void hts_event_set_uid(uint16_t uid);
int hts_get_ip_event_by_uid(uint16_t uid, uint8_t dev_id, uint16_t *event_id, uint16_t buffer_num, uint16_t *event_num);
void hts_event_lock_cfg(struct hts_rule_info *rule_info, hts_event_cmd_lock lock_cmd);
void hts_set_event_lock_or_unlock(uint16_t *events, uint32_t num, hts_event_cmd_lock lock_cmd);
#endif // __HTS_EVENT_H