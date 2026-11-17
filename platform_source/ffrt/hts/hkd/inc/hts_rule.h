/*
 * hts_rule.h
 *
 * about hts rule
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

#ifndef __HTS_RULE_H_
#define __HTS_RULE_H_

#include "hts_common_resource.h"

typedef enum {
	EVENT_UNBLOCK = 0,
	EVENT_BLOCK = 1
} hts_event_cmd_lock;

typedef enum {
	ONE_TO_ONE = 0,
	N_TO_ONE,
	ONE_TO_N,
} hts_rule_cmd_mode;

typedef struct {
    pid_t pid;
    uint32_t graph_id;
} hts_graph_handle_t;

struct hts_set_rule_info {
    hts_graph_handle_t handle;
    struct hts_rule_info graph_rules[HTS_GRAPH_MAX_RULE];
    uint32_t rule_num;
};

#endif // __HTS_RULE_H_
