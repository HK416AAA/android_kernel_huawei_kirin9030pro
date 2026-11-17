/*
 * hts_graph.c
 *
 * hts graph
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
#include <linux/slab.h>
#include <securec.h>
#include <stdbool.h>
#include "hts_common.h"
#include "hts_kernel_log.h"
#include "hts_graph_manager.h"
#include "hts_graph_resource.h"
#include "hts_rule.h"
#include "uniform_id.h"
#include "hpd_interface.h"
#include "hts_common_resource.h"
#include "hts_resmem.h"

static struct hts_rule_save_info* g_rule_infos[HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM];
static struct hts_event_save_info* g_event_infos[HTS_MAX_EVENT_NUM + 1];
static struct hts_graph_save_info g_hts_graph_info_map[HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM + HTS_DYNAMIC_GRAPH_ID_NUM];

int hts_set_events(struct hts_alloc_info* alloc_info)
{
	size_t i;
	size_t j;
	int ret = 0;
	struct hts_event_save_info* event_save_info;
	for (i = 0; i < alloc_info->event_num; i++) {
		if (g_event_infos[alloc_info->events[i]] != NULL) {
			hts_drv_err("already have event info\n");
			return -1;
		}
	}
	for (i = 0; i < alloc_info->event_num; i++) {
		event_save_info = kmalloc(sizeof(struct hts_event_save_info), GFP_KERNEL);
		cond_goto_error(event_save_info == NULL, hts_set_event_exit, ret, -ENOMEM, "malloc failed, need memeory\n");
		event_save_info->event = alloc_info->events[i];
		event_save_info->graph_id = alloc_info->handle_t.graph_id;
		event_save_info->sched_type = alloc_info->sched_type;
		event_save_info->dev_id = alloc_info->dev_type;
		g_event_infos[event_save_info->event] = event_save_info;
	}
	return 0;
hts_set_event_exit:
	for (j = 0; j < i; j++) {
		kfree(g_event_infos[alloc_info->events[j]]);
		g_event_infos[alloc_info->events[j]] = NULL;
	}
	return ret;
}

int hts_get_sched_type_by_event_id(uint16_t eventid)
{
	return g_event_infos[eventid]->sched_type;
}

int hts_get_events_by_event_id(uint16_t event, uint16_t* events, uint32_t* num)
{
	uint32_t graph_id;
	if (events == NULL) {
		hts_drv_err("events is NULL\n");
        return -1;
    }
    if (event > HTS_MAX_EVENT_NUM) {
		hts_drv_err("event num %u out of g_event_infos\n", event);
        return -1;
    }
	graph_id = g_event_infos[event]->graph_id;
	hts_get_events_by_graph_id(graph_id, events, num);
	return 0;
}

int hts_get_events_by_graph_id(uint32_t graph_id, uint16_t* events, uint32_t* num)
{
	size_t i;
	bool is_find = 0;
	*num = 0;
	for (i = 0; i < HTS_MAX_EVENT_NUM + 1; i++) {
		if (g_event_infos[i] == NULL)
			continue;
		if (g_event_infos[i]->graph_id == graph_id && g_event_infos[i]->event == i) {
			events[(*num)++] = g_event_infos[i]->event;
			is_find = 1;
		}
	}
	if (!is_find) {
		hts_drv_err("get events info is fail\n");
		return -1;
	}
	return 0;
}

void hts_remove_events_by_graph_id(uint32_t graph_id)
{
	size_t i;
	for (i = 0; i < HTS_MAX_EVENT_NUM + 1; i++) {
		if (g_event_infos[i] != NULL && g_event_infos[i]->graph_id == graph_id) {
			kfree(g_event_infos[i]);
			g_event_infos[i] = NULL;
		}
	}
}

int hts_get_rules_by_graph_id(uint32_t graph_id, struct hts_rule_save_info** rule_save_info)
{
	uint32_t rule_info_index = 0;
	struct hts_rule_save_info* rule_info;
	rule_info_index = graph_id >= HTS_TEST_GRAPH_ID_BEGIN ?
		graph_id - HTS_TEST_GRAPH_ID_BEGIN + HTS_GRAGH_NUM : graph_id;
	if (rule_info_index >= HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM) {
		hts_drv_err("rule_info_index exceed max len\n");
		return -EINVAL;
	}
	rule_info = g_rule_infos[rule_info_index];
	if (rule_info == NULL) {
		hts_drv_err("get rule info is NULL\n");
		return -EINVAL;
	}
	*rule_save_info = g_rule_infos[rule_info_index];
	return 0;
}

int hts_set_rules_by_graph_id(uint32_t graph_id, struct hts_set_rule_info* set_rule_info)
{
	int ret;
	uint32_t rule_info_index = 0;
	struct hts_rule_save_info* rule_save_info = NULL;
	rule_info_index = graph_id >= HTS_TEST_GRAPH_ID_BEGIN ? 
		graph_id - HTS_TEST_GRAPH_ID_BEGIN + HTS_GRAGH_NUM : graph_id;
	if (rule_info_index >= HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM) {
		hts_drv_err("rule_info_index exceed max len\n");
		return -EINVAL;
	}
	if (g_rule_infos[rule_info_index] != NULL) {
		hts_drv_err("already have rule info\n");
		return -1;
	}
	rule_save_info = kmalloc(sizeof(struct hts_rule_save_info), GFP_KERNEL);
	cond_return_error(rule_save_info == NULL, -ENOMEM, "malloc failed, need memeory\n");

	rule_save_info->rules = kmalloc(sizeof(struct hts_rule_info) * set_rule_info->rule_num, GFP_KERNEL);
	if (rule_save_info->rules == NULL) {
		hts_drv_err("malloc failed, need memeory\n");
		kfree(rule_save_info);
		return -ENOMEM;
	}

	rule_save_info->rule_num = set_rule_info->rule_num;
	rule_save_info->graph_id = set_rule_info->handle.graph_id;
	ret = memcpy_s(rule_save_info->rules, sizeof(struct hts_rule_info) * set_rule_info->rule_num,
		set_rule_info->graph_rules, sizeof(struct hts_rule_info) * set_rule_info->rule_num);
	if (ret != 0) {
		hts_drv_err("memcpy hts set rule info error\n");
		kfree(rule_save_info->rules);
		kfree(rule_save_info);
		return -EINVAL;
	}
	g_rule_infos[rule_info_index] = rule_save_info;
	return 0;
}

int hts_remove_rules_by_graph_id(uint32_t graph_id)
{
	uint32_t rule_info_index = 0;
	struct hts_rule_save_info* rule_info;
	rule_info_index = graph_id >= HTS_TEST_GRAPH_ID_BEGIN ?
		graph_id - HTS_TEST_GRAPH_ID_BEGIN + HTS_GRAGH_NUM : graph_id;
	rule_info = g_rule_infos[rule_info_index];
	if (rule_info == NULL) {
		hts_drv_err("remove rule info is NULL\n");
		return -EINVAL;
	}
	kfree(rule_info->rules);
	kfree(rule_info);
	g_rule_infos[rule_info_index] = NULL;
	return 0;
}

void hts_clear_graph_resource(void)
{
	size_t i;
	for (i = 0; i < HTS_MAX_EVENT_NUM + 1; i++) {
		if (g_event_infos[i] != NULL) {
			kfree(g_event_infos[i]);
			g_event_infos[i] = NULL;
		}
	}

	for (i = 0; i < HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM; i++) {
		if (g_rule_infos[i] != NULL) {
			if (g_rule_infos[i]->rules != NULL) {
				kfree(g_rule_infos[i]->rules);
				g_rule_infos[i]->rules = NULL;
			}
			kfree(g_rule_infos[i]);
			g_rule_infos[i] = NULL;
		}
		g_hts_graph_info_map[i].pid = 0;
		g_hts_graph_info_map[i].uid = 0;
	}

	for (i = HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM; i < HTS_GRAGH_NUM +
		HTS_TEST_GRAPH_NUM + HTS_DYNAMIC_GRAPH_ID_NUM; i++) {
		g_hts_graph_info_map[i].pid = 0;
		g_hts_graph_info_map[i].uid = 0;
	}
}

void hts_set_graph_info_map(uint32_t graph_id, uint32_t uid, pid_t pid)
{
	uint32_t index = 0;
	if (graph_id >= HTS_DYNAMIC_GRAPH_ID_BEGIN) {
		index = graph_id - HTS_DYNAMIC_GRAPH_ID_BEGIN +
			HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM;
	}else {
		index = graph_id >= HTS_TEST_GRAPH_ID_BEGIN ?
			graph_id - HTS_TEST_GRAPH_ID_BEGIN + HTS_GRAGH_NUM : graph_id; 
	}
	
	if (index >= HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM + HTS_DYNAMIC_GRAPH_ID_NUM) {
		hts_drv_err("graph_id is invalid, graph_id=%u\n", graph_id);
		return;
	}
	g_hts_graph_info_map[index].pid = pid;
	g_hts_graph_info_map[index].uid = uid;
}

uint32_t hts_get_uid_by_graph_id(uint32_t graph_id, pid_t pid)
{
	uint32_t index = 0;

	if (graph_id >= HTS_DYNAMIC_GRAPH_ID_BEGIN) {
		index = graph_id - HTS_DYNAMIC_GRAPH_ID_BEGIN +
			HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM;
	}else {
		index = graph_id >= HTS_TEST_GRAPH_ID_BEGIN ?
			graph_id - HTS_TEST_GRAPH_ID_BEGIN + HTS_GRAGH_NUM : graph_id; 
	}

	if (index >= HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM + HTS_DYNAMIC_GRAPH_ID_NUM) {
		hts_drv_err("graph_id is invalid, graph_id=%u\n", graph_id);
		return FFRT_INVALID_UNIFORM_ID;
	}
	if (g_hts_graph_info_map[index].uid == 0 || g_hts_graph_info_map[index].pid != pid) {
		hts_drv_err("uid is invalid or pid is not match, uid=%d, graph_pid=%d, pid=%d\n",
			g_hts_graph_info_map[index].uid, g_hts_graph_info_map[index].pid, pid);
		return FFRT_INVALID_UNIFORM_ID;
	}
	return g_hts_graph_info_map[index].uid;
}

void hts_set_dynamic_graph_info(uint16_t uid, struct hts_alloc_info *alloc_info)
{
	struct hpd_registry *hpd = NULL;
	cond_return_void(alloc_info == NULL, "alloc_info is invalid\n");
	hpd = hts_get_hpd_registry();
	cond_return_void(hpd == NULL, "hpd is not registered\n");

	cond_return_void(hpd->hts_set_dynamic_graph_info == NULL, "hts_set_dynamic_graph_info is invalid\n");
	hpd->hts_set_dynamic_graph_info(uid, alloc_info);
}

void hts_reset_dynamic_graph_info(uint32_t graph_id)
{
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_void(hpd == NULL, "hpd is not registered\n");

	cond_return_void(hpd->hts_reset_dynamic_graph_info == NULL, "hts_reset_dynamic_graph_info is invalid\n");
	hpd->hts_reset_dynamic_graph_info(graph_id);
}

int check_hts_use_gpu_gragh(uint32_t dev_id)
{
	int ret;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -1, "hpd is not registered\n");

	cond_return_error(hpd->hts_check_hts_use_gpu_gragh == NULL, -1, "hts_check_hts_use_gpu_gragh is invalid\n");
	ret = hpd->hts_check_hts_use_gpu_gragh(dev_id, g_hts_graph_info_map);
	return ret;
}

uint32_t hts_get_dev_id_by_event(uint16_t event)
{
	cond_return_error(event > HTS_MAX_EVENT_NUM, SOC_IPMAX, "event num %u out of proc_ctx event_infos\n", event);
	return g_event_infos[event]->dev_id;
}

uint32_t hts_get_graph_id_by_event(uint16_t event)
{
	cond_return_error(event > HTS_MAX_EVENT_NUM, HTS_MAX_GRAPH_ID, 
		"event num %u out of proc_ctx event_infos\n", event);
	return g_event_infos[event]->graph_id;
}

int32_t hts_get_pid_by_graph_id(uint32_t graph_id)
{
	uint32_t index = 0;
	hts_drv_info("graph_id=%u\n", graph_id);
	if (graph_id >= HTS_DYNAMIC_GRAPH_ID_BEGIN) {
		index = graph_id - HTS_DYNAMIC_GRAPH_ID_BEGIN +
			HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM;
	}else {
		index = graph_id >= HTS_TEST_GRAPH_ID_BEGIN ?
			graph_id - HTS_TEST_GRAPH_ID_BEGIN + HTS_GRAGH_NUM : graph_id; 
	}
	
	if (index >= HTS_GRAGH_NUM + HTS_TEST_GRAPH_NUM + HTS_DYNAMIC_GRAPH_ID_NUM) {
		hts_drv_err("graph_id is invalid, graph_id=%u\n", graph_id);
		return 0;
	}

	return g_hts_graph_info_map[index].pid;
}