/*
 * hts_config.h
 *
 * about hts config
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

#ifndef __HTS_CFG_H_
#define __HTS_CFG_H_

#include <linux/types.h>
#include "ffrt_configs.h"
#include "hts_rule.h"
#include "hts_common.h"
#include "hts_event.h"
#include "hts_graph_manager.h"

struct event_list {
	uint32_t src_event[HTS_GRAPH_MAX_EVENT];
	uint32_t src_event_num;
	uint32_t dst_event[HTS_GRAPH_MAX_EVENT];
	uint32_t dst_event_num;
	uint32_t unenable_event[HTS_GRAPH_MAX_EVENT];
	uint32_t unenable_event_num;
};

void hts_set_event_lock(uint32_t *events, uint32_t num);
void hts_set_event_unlock(uint32_t *events, uint32_t num);
void hts_inbuf_clear(uint32_t *events, uint32_t num);
void hts_cfg_event_unstore(uint32_t *events, uint32_t num);
void hts_outbuf_clear(uint32_t *events, uint32_t num);
void hts_clear_mapping_table(uint32_t *events, uint32_t num, uint32_t *rule_id);
void hts_clear_dst_mapping_table(uint32_t *events, uint32_t num);
void hts_wait_ibuf_event_clear(void);
void wait_outstanding_clear(soc_ip dev_id);
void hts_check_table_clear(uint32_t *events, uint32_t num);
void hts_rule_table_clear(uint32_t *rule_id, uint32_t num);
uint16_t hts_get_src_event_by_dst_event(uint16_t dst_event);
void hts_dbg_en_open_cfg(void);
int hts_plat_check_hts_use_gpu_gragh(uint32_t dev_id, struct hts_graph_save_info *graph_info);
void hts_plat_set_dynamic_graph_info(uint16_t uid, struct hts_alloc_info *alloc_info);
void hts_plat_reset_dynamic_graph_info(uint32_t graph_id);
void hts_filter_recv_events(struct exception_event *event_info);
#endif // __HPD_RULE_H_
