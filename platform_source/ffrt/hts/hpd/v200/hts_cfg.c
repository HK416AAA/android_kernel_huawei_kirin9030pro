/*
 * hts_cfg.c
 *
 * hts cfg
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
#include "hts_cfg.h"
#include <securec.h>
#include <linux/io.h>
#include <linux/delay.h>
#include "soc_hts_interface.h"
#include "hts_platform.h"
#include "hts_kernel_log.h"
#include "hpd_rule.h"
#include "hts_graph_resource.h"
#include "hts_common_resource.h"

static struct hts_dynamic_event_save_info g_dynamic_event_info_map[HTS_DYNAMIC_GRAPH_ID_NUM];

void hts_set_event_lock(uint32_t *events, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	for (i = 0; i < num; i++) {
		SOC_HTS_EVENT_LOCK_UNION event_lock = {0};
		event_lock.value = hts_event_lock(events[i] % 16);  // each reg control 16 events
		writel(event_lock.value,
			  SOC_HTS_EVENT_LOCK_ADDR(virt_addr, events[i] / 16));  // each reg control 16 events
	}
}

void hts_set_event_unlock(uint32_t *events, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	for (i = 0; i < num; i++) {
		SOC_HTS_EVENT_LOCK_UNION event_lock = {0};
		event_lock.value = hts_event_unlock(events[i] % 16);  // each reg control 16 events
		writel(event_lock.value,
			  SOC_HTS_EVENT_LOCK_ADDR(virt_addr, events[i] / 16));  // each reg control 16 events
	}
}

void hts_inbuf_clear(uint32_t *events, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	for (i = 0; i < num; i++) {
		SOC_HTS_IBUF_EVENT_CNT_CLR_UNION val = {0};
		val.value = 1 << (events[i] % 32);
		writel(val.value,
			   SOC_HTS_IBUF_EVENT_CNT_CLR_ADDR(virt_addr, events[i] / 32));
	}
}

void hts_cfg_event_unstore(uint32_t *events, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	for (i = 0; i < num; i++) {
		hts_drv_warn("unstore event_id:%u \n", events[i]);
		SOC_HTS_EVENT_STORE_UNION val = {0};
		val.value = hts_event_store_dis((events[i] % 16));
		writel(val.value, SOC_HTS_EVENT_STORE_ADDR(virt_addr, events[i] / 16));
	}
}

void hts_outbuf_clear(uint32_t *events, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	for (i = 0; i < num; i++) {
		SOC_HTS_OBUF_EVENT_CNT_CLR_UNION val = {0};
		val.value = 1 << (events[i] % 32);
		writel(val.value,
		       SOC_HTS_OBUF_EVENT_CNT_CLR_ADDR(virt_addr, events[i] / 32));
	}
}

void hts_clear_mapping_table(uint32_t *events, uint32_t num, uint32_t *rule_id)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_MAPPING_TABLE);
	for (i = 0; i < num; i++) {
		SOC_HTS_EVENT_PROC_MAPPING_IDX_UNION reg_value;
		reg_value.value =
				readl(SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(virt_addr, events[i]));
		rule_id[i] = reg_value.reg.cfg_mapping_idx;
		reg_value.reg.cfg_mapping_idx = 0;
		writel(reg_value.value,
		       SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(virt_addr, events[i]));
	}
}

void hts_clear_dst_mapping_table(uint32_t *events, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_MAPPING_TABLE);
	for (i = 0; i < num; i++) {
		SOC_HTS_EVENT_PROC_MAPPING_IDX_UNION reg_value;
		reg_value.value =
				readl(SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(virt_addr, events[i]));
		reg_value.reg.cfg_mapping_idx = 0;
		writel(reg_value.value,
		       SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(virt_addr, events[i]));
	}
}

void hts_wait_ibuf_event_clear(void)
{
	uint32_t value = 0;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_WRAP_REG);
	uint32_t loop_count = 0;
	writel(1, SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_REQ_ADDR(virt_addr));
	do {
		udelay(5);
		value = readl(SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ACK_ADDR(virt_addr));
		if (value == 1) {
			break;
		}
		loop_count ++;
	} while (loop_count < 10000);
	hts_drv_warn("hts_wait_ibuf_event_clear end loop_count%u\n", loop_count);
}

void wait_outstanding_clear(soc_ip dev_id)
{
	SOC_HTS_WRAP_OST_CNT_0_UNION rule_outstanding = {0};
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_WRAP_REG);
	rule_outstanding.value = readl(SOC_HTS_WRAP_OST_CNT_0_ADDR(virt_addr));
	for (i = 0; i < OTS_COUNT_TIMES; i++) {
		if (dev_id == SOC_TSCPU) {
			while (rule_outstanding.reg.npu_tscpu_ost_cnt != 0)
				rule_outstanding.value = readl(SOC_HTS_WRAP_OST_CNT_0_ADDR(virt_addr));
		} else if (dev_id == SOC_HWTS) {
			while (rule_outstanding.reg.npu_hwts_ost_cnt != 0)
				rule_outstanding.value = readl(SOC_HTS_WRAP_OST_CNT_0_ADDR(virt_addr));
		} else if (dev_id == SOC_GPU) {
			while (rule_outstanding.reg.gpu_ost_cnt != 0)
				rule_outstanding.value = readl(SOC_HTS_WRAP_OST_CNT_0_ADDR(virt_addr));
		} else {
			while (rule_outstanding.reg.total_ost_cnt != 0)
				rule_outstanding.value = readl(SOC_HTS_WRAP_OST_CNT_0_ADDR(virt_addr));
		}
	}
}

void hts_check_table_clear(uint32_t *events, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_CHECK_TABLE);
	for (i = 0; i < num; i++)
		writel(0, SOC_HTS_EVENT_IN_CHECK_ADDR(virt_addr, events[i]));
}

void hts_rule_table_clear(uint32_t *rule_id, uint32_t num)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_RULE_TABLE);
	for (i = 0; i < num; i++) {
		writel(0, SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, rule_id[i] * 2));
		writel(0, SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, rule_id[i] * 2 + 1));
	}
}

uint16_t hts_get_src_event_by_dst_event(uint16_t dst_event) {
	uint16_t i;
	hts_event_proc_rule_low rule_low = { 0 };
	hts_event_proc_rule_high rule_high = { 0 };
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_RULE_TABLE);
	if (dst_event == 0 || dst_event > HTS_MAX_EVENT_NUM)
		return 0;
	for(i = 1; i <= HTS_MAX_EVENT_NUM; i++) {
		rule_low.value = readl(SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, i * 2));
		if (rule_low.reg.dst_event0 == dst_event)
			return rule_low.reg.src_event0;
		
		if (rule_low.reg.cmd_code == ONE_TO_N) {
			rule_high.value = readl(SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, i * 2 + 1));
			if (rule_high.reg.cfg1 == dst_event || rule_high.reg.cfg2 == dst_event)
				return rule_low.reg.src_event0;
		}
	}
	return 0;
}

void hts_dbg_en_open_cfg(void)
{
	// dbg_en_open
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	SOC_HTS_DBG_EN_UNION dbg_en = { 0 };
	dbg_en.reg.hts_dbg_en = 1;
	writel(dbg_en.value, SOC_HTS_DBG_EN_ADDR(virt_addr));

	// event_profiling_en_open
	SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_UNION event_in_src_id_event_cnt_en = { 0 };
	SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_UNION event_out_dst_id_event_cnt_en = { 0 };
	event_in_src_id_event_cnt_en.value = 0xFFFFFFFF;
	writel(event_in_src_id_event_cnt_en.value, SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_ADDR(virt_addr, 0)); // src_id limit 15

	event_out_dst_id_event_cnt_en.value = 0xFFFFFFFF;
	writel(event_out_dst_id_event_cnt_en.value, SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_ADDR(virt_addr, 0)); // dst_id limit 15
}

int hts_plat_check_hts_use_gpu_gragh(uint32_t dev_id, struct hts_graph_save_info *graph_info)
{
    uint32_t gpu_graph_id[] = {DLSS, NEURAL_UPSCALE, GLES_DLSS, NEURAL_FRAME, FLASH_LIGHT, DLSS_FI};
	int num = sizeof(gpu_graph_id) / sizeof(uint32_t);
	int i;
	for (i = 0; i < num; i++) {
		if (graph_info[gpu_graph_id[i]].uid != 0)
			return 0;
	}

	for (i = 0; i < HTS_DYNAMIC_GRAPH_ID_NUM; i++) {
		if (g_dynamic_event_info_map[i].dev_id == dev_id) {
			return 0;
		}
	}
	return -1;
}

void hts_plat_set_dynamic_graph_info(uint16_t uid, struct hts_alloc_info *alloc_info)
{
	int ret;
	uint32_t index = 0;
	uint32_t graph_id = 0;
	cond_return_void(alloc_info == NULL, "alloc_info is invalid\n");
	graph_id = alloc_info->handle_t.graph_id;
	if (graph_id < HTS_DYNAMIC_GRAPH_ID_BEGIN || graph_id >= HTS_DYNAMIC_GRAPH_ID_BEGIN + HTS_DYNAMIC_GRAPH_ID_NUM) {
		hts_drv_err("invalid graph_id=%u\n", graph_id);
		return;
	}
	index = graph_id - HTS_DYNAMIC_GRAPH_ID_BEGIN;

	g_dynamic_event_info_map[index].pid = alloc_info->handle_t.pid;
	g_dynamic_event_info_map[index].uid = uid;
	g_dynamic_event_info_map[index].dev_id = alloc_info->dev_type;
	ret = memcpy_s(g_dynamic_event_info_map[index].events, sizeof(uint16_t) * HTS_DYNAMIC_ALLOC_EVENT_MAX_NUM,
		alloc_info->events, sizeof(uint16_t) * HTS_DYNAMIC_ALLOC_EVENT_MAX_NUM);
	if (ret != 0) {
		hts_drv_err("memcpy events error, ret=%d\n", ret);
	}
}

void hts_plat_reset_dynamic_graph_info(uint32_t graph_id)
{
	int ret = 0;
	uint32_t index = 0;
	if (graph_id < HTS_DYNAMIC_GRAPH_ID_BEGIN || graph_id >= HTS_DYNAMIC_GRAPH_ID_BEGIN + HTS_DYNAMIC_GRAPH_ID_NUM) {
		hts_drv_err("invalid graph_id=%u\n", graph_id);
		return;
	}
	index = graph_id - HTS_DYNAMIC_GRAPH_ID_BEGIN;

	g_dynamic_event_info_map[index].pid = 0;
	g_dynamic_event_info_map[index].uid = 0;
	g_dynamic_event_info_map[index].dev_id = 0;
	ret = memset_s(g_dynamic_event_info_map[index].events, sizeof(g_dynamic_event_info_map[index].events),
		0, sizeof(g_dynamic_event_info_map[index].events));
	if (ret != 0) {
		hts_drv_err("memset failed, ret=%d\n", ret);
	}
}

void hts_filter_recv_events(struct exception_event *event_info)
{
	uint32_t i = 0;
	event_info->length = 0;
	for (i = 0; i < HTS_DYNAMIC_GRAPH_ID_NUM; i++) {
		if (g_dynamic_event_info_map[i].pid != event_info->pid || g_dynamic_event_info_map[i].dev_id != event_info->dev_id) {
			continue;
		}
		if (g_dynamic_event_info_map[i].events[1] != 0) {
			event_info->events[event_info->length] = g_dynamic_event_info_map[i].events[1];
			event_info->length++;
		}
	}
}