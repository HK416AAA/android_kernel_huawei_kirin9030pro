/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hts_graph.h
 */
#ifndef _HTS_GRAPH_MANAGER_H_
#define _HTS_GRAPH_MANAGER_H_

#include "hts_common_resource.h"
#include "hts_graph.h"
#include "hts_rule.h"
#include "hts_ioctl_services.h"

struct hts_event_save_info {
	uint16_t sched_type;
	uint16_t event;
	uint32_t graph_id;
	uint32_t dev_id;
};

struct hts_rule_save_info {
	uint32_t graph_id;
	uint32_t rule_num;
	struct hts_rule_info* rules;
};

struct hts_graph_save_info {
	pid_t pid;
	uint32_t uid;
};

struct hts_dynamic_event_save_info {
	pid_t pid;
	uint32_t uid;
	uint32_t dev_id;
	uint16_t events[HTS_DYNAMIC_ALLOC_EVENT_MAX_NUM];
};

int hts_set_events(struct hts_alloc_info* alloc_info);
int hts_get_sched_type_by_event_id(uint16_t eventid);
int hts_get_events_by_graph_id(uint32_t graph_id, uint16_t* events, uint32_t* num);
void hts_remove_events_by_graph_id(uint32_t graph_id);
int hts_get_rules_by_graph_id(uint32_t graph_id, struct hts_rule_save_info** rule_save_info);
int hts_set_rules_by_graph_id(uint32_t graph_id, struct hts_set_rule_info* set_rule_info);
int hts_remove_rules_by_graph_id(uint32_t graph_id);
void hts_clear_graph_resource(void);
void hts_set_graph_info_map(uint32_t graph_id, uint32_t uid, pid_t pid);
uint32_t hts_get_uid_by_graph_id(uint32_t graph_id, pid_t pid);
int check_hts_use_gpu_gragh(uint32_t dev_id);
int hts_get_events_by_event_id(uint16_t event, uint16_t* events, uint32_t* num);
void hts_set_dynamic_graph_info(uint16_t uid, struct hts_alloc_info *alloc_info);
void hts_reset_dynamic_graph_info(uint32_t graph_id);
uint32_t hts_get_dev_id_by_event(uint16_t event);
uint32_t hts_get_graph_id_by_event(uint16_t event);
int32_t hts_get_pid_by_graph_id(uint32_t graph_id);
#endif