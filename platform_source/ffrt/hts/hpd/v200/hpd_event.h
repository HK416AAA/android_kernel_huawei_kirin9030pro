/*
 * hpd_event.h
 *
 * about hts event
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

#ifndef __HPD_EVENT_H_
#define __HPD_EVENT_H_

#include <linux/types.h>
#include "ffrt_configs.h"
#include "hts_rule.h"
#include "hts_common.h"
#include "hts_event.h"

void hts_set_dev_ctx_events(void);
int hts_event_alloc(uint16_t uid, struct hts_alloc_info* events_info, uint32_t graph_id);
event_alloc_type hts_get_alloc_type_by_eventid(uint16_t event_id);
#endif // __HPD_RULE_H_
