/*
 * hpd_interface.h
 *
 * hpd interface head file
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

#ifndef __HPD_INTERFACE_H__
#define __HPD_INTERFACE_H__

#include <linux/types.h>
#include "hts_ioctl_services.h"
#include "hts_rule.h"
#include "hts_graph.h"
#include "hts_platform.h"
#include "hts_graph_manager.h"

#define HPD_REGISTRY_V100 1
#define HPD_REGISTRY_V200 2

// bit mask for chip-uarch dependent features.
// complex features should use hpd_query_sku_value interface

#define NPU_FEATUE_GLOBAL_EXCEPTION_REG		0x1
// other static features can be defined here

// data structure for HPD(hts Platform Driver) registry
struct hpd_registry {
	uint8_t version; // version of this structure
	uint8_t hts_chip_version;
	int (*hts_set_rule)(struct hts_rule_info *rule_info, uint32_t rule_num, uint32_t uid);
	int (*hts_destroy_rule)(struct hts_rule_info *rule_info, uint32_t rule_num, uint32_t uid);
	void (*hts_resource_clear)(void);
	int (*hts_except_block_by_ip)(soc_ip dst_id);
	int (*hts_except_block_by_event)(uint16_t event_id);
	int (*hts_ffts_outbuff_except_block_by_event)(uint16_t event_id);
	int (*hts_except_block_by_proc)(soc_ip dev_id, uint16_t uid);
	int (*hts_store_event)(uint16_t event_id);
	int (*hts_unstore_event)(uint16_t event_id);
	void (*hts_dump_info)(uint32_t id);
	void (*hts_get_resmem_info)(struct hts_platform_info *plat_info);
	int (*hts_get_ip_event_by_uid)(uint16_t uid, uint8_t dev_id, uint16_t *event_id,
		uint16_t buffer_num, uint16_t *event_num);
	int (*hts_lock_event_by_ip)(soc_ip dev_id);
	int (*hts_unlock_event_by_ip)(soc_ip dev_id);
	void (*hts_dbg_en_open_cfg)(void);
	uint16_t (*hts_obuf_overflow_profiling)(void);
	int (*hts_irq_init)(int irq_abnormal);
	int (*hts_event_alloc)(uint16_t uid, struct hts_alloc_info* events_info, uint32_t graph_id);
	event_alloc_type (*hts_get_alloc_type_by_eventid)(uint16_t event_id);
	void (*hts_set_dev_ctx_events)(void);
	int (*hts_notify_event_exception)(soc_ip dev_id, int32_t pid);
	int (*hts_check_hts_use_gpu_gragh)(uint32_t dev_id, struct hts_graph_save_info *graph_info);
	void (*hts_set_dynamic_graph_info)(uint16_t uid, struct hts_alloc_info *alloc_info);
	void (*hts_reset_dynamic_graph_info)(uint32_t graph_id);
};

struct hpd_registry *hts_get_hpd_registry(void);
int hkd_register_plat_driver(struct hpd_registry *hpd);
int hkd_unregister_plat_driver(void);

#endif // __HPD_INTERFACE_H__
