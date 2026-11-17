/*
 * hts_arch_exception.c
 *
 * hts arch exception
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
#include "hts_arch_exception.h"
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <securec.h>
#include "soc_hts_interface.h"
#include "soc_ffts_interface.h"
#include "hts_rule.h"
#include "hts_kernel_log.h"
#include "hts_resmem.h"
#include "hts_common.h"
#include "hts_cfg.h"
#include "hts_event.h"
#include "uniform_id.h"
#include "hpd_rule.h"
#include "hpd_event.h"
#include "hts_graph_manager.h"
#include "ffts_task.h"
#include "hts_common_resource.h"

#define HTS_READ_DDR_DELAY_TIMES 100
#define TRY_COUNT 3
#define TRY_DELAY_TIMES 10

static struct exception_event g_exception_event = {0};

static void lock_clear_event(struct event_list *events, soc_ip dev_id, bool is_need_wait_outstanding, bool need_clear_rule)
{
	uint32_t *rule_id = NULL;
	struct hts_dev_ctx *dev_ctx = NULL;
	uint32_t i;

	if (need_clear_rule) {
		dev_ctx = hts_get_dev_ctx();
		rule_id = kzalloc(sizeof(uint32_t) * (HTS_MAX_RULE_NUM + 1), GFP_KERNEL);
		if (rule_id == NULL) {
			hts_drv_err("rule_id is null");
			return;
		}
	}
	// Configure the src event lock reg register
	hts_set_event_lock(events->src_event, events->src_event_num);
	// Configure the dst event lock reg register
	hts_set_event_lock(events->dst_event, events->dst_event_num);
	// Configure the ibuf cnt clear register to clear the corresponding bits of the events
	hts_inbuf_clear(events->src_event, events->src_event_num);
	// Configure the event store_bitmap register 
	hts_cfg_event_unstore(events->dst_event, events->dst_event_num);
	// Configure the obuf cnt clear register
	hts_outbuf_clear(events->dst_event, events->dst_event_num);
	// Set rule_addr corresponding to src_event in the mapping table to 0
	if (need_clear_rule)
		hts_clear_mapping_table(events->src_event, events->src_event_num, rule_id);
	// Configure the ibuf_clr_bus_nopress_req register in HTS_WRAP_REG
	hts_wait_ibuf_event_clear();
	// Configure the ibuf cnt clear register again
	hts_inbuf_clear(events->src_event, events->src_event_num);
	// Configure the outbuf cnt clear register again
	hts_outbuf_clear(events->dst_event, events->dst_event_num);
	// Reconfigure the ibuf_clr_bus_nopress_req register in HTS_WRAP_REG
	hts_wait_ibuf_event_clear();
	if(is_need_wait_outstanding) {
		// Read the ost_cnt of the hts_wrap layer to ensure that there is no residual data on the bus
		wait_outstanding_clear(dev_id);
	}

	if (need_clear_rule) {
		// Set the corresponding UID of the CHECK Table to 0
		hts_check_table_clear(events->src_event, events->src_event_num);
		hts_check_table_clear(events->dst_event, events->dst_event_num);
		// Configure the corresponding rule in the rule table to all 0
		hts_rule_table_clear(rule_id, events->src_event_num);
		for (i = 0; i < events->src_event_num; i++)
			bitmap_clear(dev_ctx->res.rule_bitmap, (int)rule_id[i], 1);
		kfree(rule_id);
	}
}

int hts_except_block_by_ip(soc_ip dev_id)
{
	int ret = 0;
	uint16_t event;
	uint16_t src_event_id;
	struct hts_dev_ctx *dev_ctx = NULL;
	struct event_list *events = NULL;

	hts_drv_info("hts_block_by_ip enter start");
	cond_return_error((dev_id == SOC_HTS) || (dev_id >= SOC_IPMAX), -EINVAL, "dev_id is invalid, soc_ip:%u\n", dev_id);
	dev_ctx = hts_get_dev_ctx();
	events = kzalloc(sizeof(struct event_list), GFP_KERNEL);
	cond_return_error(events == NULL, -EINVAL, "events is null\n");
	hts_drv_info("hts_block_by_ip enter start, soc_ip:%u\n", dev_id);
	mutex_lock(&dev_ctx->mtx);
	for (event = 1; event <= HTS_MAX_EVENT_NUM; event++) {
		hts_check_table table = {0};
		hts_get_auth_table(event, &table);
		if (table.data.src_id == dev_id) {
			events->src_event[events->src_event_num++] = event;
		} else if (table.data.dst_id == dev_id) {
			events->dst_event[events->dst_event_num++] = event;
		    src_event_id = hts_get_src_event_by_dst_event(event);
			if(src_event_id != 0)
				events->src_event[events->src_event_num++] = src_event_id;
		}

		if (events->src_event_num >= HTS_GRAPH_MAX_EVENT || events->dst_event_num >= HTS_GRAPH_MAX_EVENT) {
			lock_clear_event(events, dev_id, false, true);
			ret = memset_s(events, sizeof(struct event_list), 0, sizeof(struct event_list));
			if (ret != 0) {
				hts_drv_err("memset failed");
				break;
			}
		}
	}
	if (ret == 0)
		lock_clear_event(events, dev_id, true, true);
	mutex_unlock(&dev_ctx->mtx);
	kfree(events);
	hts_drv_info("hts_block_by_ip end");
	return ret;
}

int hts_except_block_by_event(uint16_t event)
{
	hts_event_proc_rule_low low_rule = { 0 };
	hts_event_proc_rule_high high_rule = { 0 };
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_RULE_TABLE);
	uint32_t rule_id = 0;
	uintptr_t mapping_virt_addr = 0;
	SOC_HTS_EVENT_PROC_MAPPING_IDX_UNION reg_value;
	struct event_list *events;

	hts_drv_warn("hts_block_by_event enter, event:%u\n", event);
	// Find the rule ID based on the event
	mapping_virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_MAPPING_TABLE);
	cond_return_error((event <= 0) || (event >= 1024), -EINVAL, "event is invalid, event:%u\n", event);
	reg_value.value =
			readl(SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(mapping_virt_addr, event));
	rule_id = reg_value.reg.cfg_mapping_idx;
	// Find the rule table by rule id
	low_rule.value = readl(SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, rule_id * 2));
	high_rule.value = readl(SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, rule_id * 2 + 1));
	events = kzalloc(sizeof(struct event_list), GFP_KERNEL);
	cond_return_error(events == NULL, -EINVAL, "events is null\n");
	if (low_rule.reg.cmd_code == ONE_TO_N) {
		events->src_event[events->src_event_num++] = low_rule.reg.src_event0;
		events->dst_event[events->dst_event_num++] = low_rule.reg.dst_event0;
		events->dst_event[events->dst_event_num++] = high_rule.reg.cfg1;
		if (high_rule.reg.cfg2 != 0) 
		    events->dst_event[events->dst_event_num++] = high_rule.reg.cfg2;
	} else if (low_rule.reg.cmd_code == N_TO_ONE) {
		events->dst_event[events->dst_event_num++] = low_rule.reg.dst_event0;
		events->src_event[events->src_event_num++] = low_rule.reg.src_event0;
		events->src_event[events->src_event_num++] = high_rule.reg.cfg1;
		if (high_rule.reg.cfg2 != 0) 
		    events->src_event[events->src_event_num++] = high_rule.reg.cfg2;
	} else {
		events->src_event[events->src_event_num++] = low_rule.reg.src_event0;
		events->dst_event[events->dst_event_num++] = low_rule.reg.dst_event0;
	}
	mutex_lock(&dev_ctx->mtx);
	lock_clear_event(events, SOC_IPMAX, false, true);
	mutex_unlock(&dev_ctx->mtx);
	kfree(events);
	return 0;
}

int hts_ffts_outbuff_except_block_by_event(uint16_t event)
{
	uint32_t dev_id;
	uint32_t graph_id;
	int32_t pid;
	uint16_t uid;
	uint32_t st;
	dev_id = hts_get_dev_id_by_event(event);
	cond_return_error(dev_id >= SOC_IPMAX, -EINVAL, "dev_id is invalid\n");
	graph_id = hts_get_graph_id_by_event(event);
	cond_return_error(graph_id >= HTS_MAX_GRAPH_ID, -EINVAL, "graph_id is invalid\n");
	pid = hts_get_pid_by_graph_id(graph_id);
	cond_return_error(pid == 0, -EINVAL, "pid is invalid\n");
	uid = ffrt_get_uniform_id(pid);
	struct exception_task task_info = {event, uid, dev_id, 0, 2};
	st = ffts_notify_excep_event_to_rtb(&task_info);
	hts_drv_warn("event: %u, dev_id: %u, graph_id: %u, pid: %d, st: %u", event, dev_id, graph_id, pid, st);

	int i;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	struct event_list *events = kzalloc(sizeof(struct event_list), GFP_KERNEL);
	cond_return_error(events == NULL, -EINVAL, "events is null\n");
	uint16_t graph_events[HTS_GRAPH_MAX_EVENT] = {0};
	uint32_t graph_events_num = 0;

	mutex_lock(&dev_ctx->mtx);
	hts_get_events_by_event_id(event, graph_events, &graph_events_num);
	events->src_event_num = 0;
	events->dst_event_num = graph_events_num;
	for (i = 0; i < graph_events_num; i++) {
		events->dst_event[i] = graph_events[i];
	}
	lock_clear_event(events, SOC_IPMAX, false, false);
	// 清理后解锁events
	hts_set_event_unlock(events->dst_event, events->dst_event_num);
	mutex_unlock(&dev_ctx->mtx);
	kfree(events);
	return 0;
}

int hts_except_block_by_proc(soc_ip dev_id, uint16_t uid)
{
	int ret = 0;
	uint16_t event;
	struct hts_dev_ctx *dev_ctx = NULL;
	struct event_list *events = NULL;
	uint16_t src_event_id;

	hts_drv_info("hts_except_block_by_proc enter start");
	cond_return_error((dev_id == SOC_HTS) || (dev_id >= SOC_IPMAX), -EINVAL, "dev_id is invalid, soc_ip:%u\n", dev_id);
	cond_return_error(uid > HTS_MAX_UID, -EINVAL, "uid is invalid, uid:%u\n", uid);
	events = kzalloc(sizeof(struct event_list), GFP_KERNEL);
	cond_return_error(events == NULL, -EINVAL, "events is null\n");
	hts_drv_info("hts_block_by_ip enter start, soc_ip:%u\n", dev_id);
	dev_ctx = hts_get_dev_ctx();
	mutex_lock(&dev_ctx->mtx);
	for (event = 1; event <= HTS_MAX_EVENT_NUM; event++) {
		hts_check_table table = {0};
		hts_get_auth_table(event, &table);
		if (table.data.uid != uid)
			continue;
		if (table.data.src_id == dev_id) {
			events->src_event[events->src_event_num++] = event;
		} else if (table.data.dst_id == dev_id) {
			events->dst_event[events->dst_event_num++] = event;
			src_event_id = hts_get_src_event_by_dst_event(event);
			if (src_event_id != 0)
				events->src_event[events->src_event_num++] = src_event_id;
		}

		if (events->src_event_num >= HTS_GRAPH_MAX_EVENT || events->dst_event_num >= HTS_GRAPH_MAX_EVENT) {
			lock_clear_event(events, dev_id, false, true);
			ret = memset_s(events, sizeof(struct event_list), 0, sizeof(struct event_list));
			if (ret != 0) {
				hts_drv_err("memset failed");
				break;
			}
		}
	}
	if (ret == 0)
		lock_clear_event(events, dev_id, false, true);
	mutex_unlock(&dev_ctx->mtx);
	kfree(events);
	hts_drv_info("hts_except_block_by_proc end");
	return ret;
}

static void recycle_all_event(struct event_list *events)
{
	cond_return_void(events == NULL, "events is NULL");
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	hts_check_table table_set = {0};
	uint32_t i;
	table_set.data.src_id = SOC_IPMAX;
	table_set.data.dst_id = SOC_IPMAX;
	event_alloc_type type = 0;
	hts_drv_info("recycle src_event num  is %u\n", events->src_event_num);
	for (i = 0; i < events->src_event_num; i++) {
		type = hts_get_alloc_type_by_eventid(events->src_event[i]);
		if (type != MAX_ALLOC_TYPE) {
			dev_ctx->res.event_num[type]++;
		}
		bitmap_clear(dev_ctx->res.event_bitmap, (int)events->src_event[i], 1);
		(void)hts_set_auth_table(events->src_event[i], &table_set);
	}
	hts_drv_info("recycle dst_event num is %u\n ", events->dst_event_num);
	for (i = 0; i < events->dst_event_num; i++) {
		type = hts_get_alloc_type_by_eventid(events->dst_event[i]);
		if (type != MAX_ALLOC_TYPE) {
			dev_ctx->res.event_num[type]++;
		}
		bitmap_clear(dev_ctx->res.event_bitmap, (int)events->dst_event[i], 1);
		(void)hts_set_auth_table(events->dst_event[i], &table_set);
	}
	hts_drv_info("recycle unenable_event num is %u\n ", events->unenable_event_num);
	for (i = 0; i < events->unenable_event_num; i++) {
		type = hts_get_alloc_type_by_eventid(events->unenable_event[i]);
		if (type != MAX_ALLOC_TYPE) {
			dev_ctx->res.event_num[type]++;
		}
		bitmap_clear(dev_ctx->res.event_bitmap, (int)events->unenable_event[i], 1);
		(void)hts_set_auth_table(events->unenable_event[i], &table_set);
	}
}

int hts_store_event(uint16_t event_id)
{
	uint32_t val;
	int ret;
	uint32_t loop_count = 0;
	uint32_t group_id;
	uint32_t inner_group_id;
	SOC_HTS_EVENT_STORE_UNION event_store = {0};
	cond_return_error((event_id == 0) || (event_id > HTS_MAX_EVENT_NUM), -EINVAL, "event is invalid\n");

	group_id = event_id /
		(SOC_HTS_EVENT_STORE_hts_event_store_END - SOC_HTS_EVENT_STORE_hts_event_store_START + 1);
	inner_group_id = event_id % (SOC_HTS_EVENT_STORE_hts_event_store_END + 1);

	hts_check_table table_get = {0};
	// step1 config event store reg
	event_store.value = hts_event_store_en(inner_group_id);
	writel(event_store.value, SOC_HTS_EVENT_STORE_ADDR(hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE), group_id));

	// step2 config obuf clr bus nopress
	writel(1, SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_REQ_ADDR(hts_plat_get_reg_vaddr(HTS_REG_WRAP_REG)));

	// step3 util obuf bus nopress ack
	do {
		udelay(5);
		val = readl(SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ACK_ADDR(hts_plat_get_reg_vaddr(HTS_REG_WRAP_REG)));
		if ((val & 0x1) != 0) {
			break;
		}
		loop_count ++;	
	} while (loop_count < OBUF_NOPRESS_TRYTIMES);

	if (loop_count >= OBUF_NOPRESS_TRYTIMES) {
		hts_drv_err("store event wait obuf clear timeout in step3, loop_count:%u\n", loop_count);
		return -1;
	}
	// step 4 wait outstanding clear
	ret = hts_get_auth_table(event_id, &table_get);
	if (ret != 0)
		return ret;

	if (table_get.data.dst_id != SOC_IPMAX)
		wait_outstanding_clear(table_get.data.dst_id);

	return 0;
}
 
int hts_unstore_event(uint16_t event_id)
{
	uint32_t group_id;
	uint32_t inner_group_id;
	SOC_HTS_EVENT_STORE_UNION event_store = {0};
 	cond_return_error((event_id == 0) || (event_id > HTS_MAX_EVENT_NUM), -EINVAL, "event is invalid\n");

	group_id = event_id / (SOC_HTS_EVENT_STORE_hts_event_store_END - 
		SOC_HTS_EVENT_STORE_hts_event_store_START + 1);
	inner_group_id = event_id % (SOC_HTS_EVENT_STORE_hts_event_store_END + 1);

	// step1
	event_store.value = hts_event_store_dis(inner_group_id);
	writel(event_store.value, SOC_HTS_EVENT_STORE_ADDR(hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE), group_id));

	return 0;
}

int hts_lock_event_by_ip(soc_ip dev_id)
{
	uint32_t event;
	struct hts_dev_ctx *dev_ctx = NULL;
	struct event_list *events = NULL;
	uint16_t src_event_id;
	int ret = 0;

	hts_drv_info("hts_lock_event_by_ip enter start");
	cond_return_error((dev_id == SOC_HTS) || (dev_id >= SOC_IPMAX), -EINVAL, "dev_id is invalid, soc_ip:%u\n", dev_id);
	events = kzalloc(sizeof(struct event_list), GFP_KERNEL);
	cond_return_error(events == NULL, -EINVAL, "events is null\n");
	dev_ctx = hts_get_dev_ctx();
	mutex_lock(&dev_ctx->mtx);
	for (event = 1; event <= HTS_MAX_EVENT_NUM; event++) {
		hts_check_table table = {0};
		hts_get_auth_table(event, &table);
		if (table.data.dst_id == dev_id) {
			events->dst_event[events->dst_event_num++] = event;
		    src_event_id = hts_get_src_event_by_dst_event(event);
			if(src_event_id != 0)
				events->src_event[events->src_event_num++] = src_event_id;
		}

		if (events->src_event_num >= HTS_GRAPH_MAX_EVENT || events->dst_event_num >= HTS_GRAPH_MAX_EVENT) {
			lock_clear_event(events, dev_id, true, false);
			ret = memset_s(events, sizeof(struct event_list), 0, sizeof(struct event_list));
			if (ret != 0) {
				hts_drv_err("memset failed");
				break;
			}
		}
	}
	if (ret == 0)
		lock_clear_event(events, dev_id, true, false);
	mutex_unlock(&dev_ctx->mtx);
	kfree(events);
	hts_drv_info("hts_lock_event_by_ip end");
	return 0;
}

int hts_unlock_event_by_ip(soc_ip dev_id)
{
	uint32_t event;
	struct hts_dev_ctx *dev_ctx = NULL;
	uint32_t *events = NULL;
	uint32_t num = 0;
	uint16_t src_event_id;

	hts_drv_info("hts_unlock_event_by_ip enter start");
	cond_return_error((dev_id == SOC_HTS) || (dev_id >= SOC_IPMAX), -EINVAL, "dev_id is invalid, soc_ip:%u\n", dev_id);
	events = kzalloc(sizeof(uint32_t) * HTS_MAX_EVENT_NUM, GFP_KERNEL);
	cond_return_error(events == NULL, -EINVAL, "events is null\n");
	dev_ctx = hts_get_dev_ctx();
	mutex_lock(&dev_ctx->mtx);
	for (event = 1; event <= HTS_MAX_EVENT_NUM; event++) {
		hts_check_table table = {0};
		hts_get_auth_table(event, &table);
		if (table.data.dst_id == dev_id) {
			events[num++] = event;
		    src_event_id = hts_get_src_event_by_dst_event(event);
			if(src_event_id != 0)
				events[num++] = src_event_id;
		}
	}

	hts_set_event_unlock(events, num);
	mutex_unlock(&dev_ctx->mtx);
	kfree(events);
	hts_drv_info("hts_unlock_event_by_ip end");
	return 0;
}

static int hts_capture_exception_task(struct exception_event *event_info, struct exception_task *task_info)
{
	int task_cnt = 0;
	int ret = 0;
	uint16_t i = 0;
	uint16_t uid = ffrt_get_uniform_id(event_info->pid);
 
	for (i = 0; i < event_info->length; i++) {
		task_info[i].recv_event = event_info->events[i];
		task_info[i].uid = uid;
		task_info[i].hwtype = event_info->dev_id;

        ret = ffts_query_exception_task(&task_info[i]);
        if (ret > 0) {
			task_cnt++;
        }
    }
 
	return task_cnt;
}

static int hts_process_exception_task(struct exception_task *task_info, uint16_t length)
{
	uint16_t i = 0;
	int try_cnt = 0;
	int task_cnt = length;
	int ret = 0;

	while (try_cnt < TRY_COUNT && task_cnt > 0) {
		try_cnt++;
		hts_drv_err("try_cnt:%d, task_cnt:%d\n", try_cnt, task_cnt);
		task_cnt = 0;
		for (i = 0; i < length; i++) {
			// taskidx == 0，无需处理
			if (task_info[i].taskidx == 0) {
				continue;
			}
 
			ret = ffts_process_exception_task(&task_info[i]);
			if (ret != 0) {
				task_cnt++;
			}
		}
		msleep(TRY_DELAY_TIMES);
	}
 
	return task_cnt;
}

static void log_uncompleted_exception_task(struct exception_task *task_info, struct exception_event *event_info)
{
	int ret;
	uint16_t i;
	char log_buf[HTS_BUF_LEN_MAX + 1] = {0};
	int pos = 0;
	for (i = 0; i < event_info->length; i++) {
		if (task_info[i].taskidx == 0 || task_info[i].recv_event == 0) {
			continue;
		}
		if (pos >= HTS_BUF_LEN_MAX) {
            break;
        }
		ret = snprintf_s(log_buf + pos, HTS_BUF_LEN_MAX - pos, HTS_BUF_LEN_MAX - pos - 1, 
			" recv_event = %u | taskidx = %u,", task_info[i].recv_event, task_info[i].taskidx);
		if (ret < 0) {
			hts_drv_err("snprintf_s failed ret: %d, recv_event: %u, taskidx = %u\n",
				ret, task_info[i].recv_event, task_info[i].taskidx);
		}
		pos += ret;
	}
	hts_drv_err("handling try cnt exceeded, left uncompleted task, dev_id:%u, pid:%d, %s\n",
		event_info->dev_id, event_info->pid, log_buf);
}

static void hts_async_notify_work(struct work_struct *work)
{
	int ret;
	struct exception_task *task_info = NULL;
	struct exception_event *event_info = container_of(work, struct exception_event, work);
	if (event_info->length == 0) {
		hts_drv_err("event_info length is invalid\n");
		return;
	}
	task_info = kzalloc(sizeof(struct exception_task) * event_info->length, GFP_KERNEL);
	if (task_info == NULL) {
		hts_drv_err("kzalloc task_info failed\n");
		return;
	}
    // 捕获可能异常的ffts任务，记录task_info信息
	ret = hts_capture_exception_task(event_info, task_info);
	if (ret == 0) {
		hts_drv_err("no tasks need handling exception\n");
		kfree(task_info);
		return;
	}

	msleep(HTS_READ_DDR_DELAY_TIMES);

    // 处理异常的ffts任务，生成RTB任务并通知清理
	ret = hts_process_exception_task(task_info, event_info->length);
	if (ret > 0) {
		log_uncompleted_exception_task(task_info, event_info);
	}
	kfree(task_info);
}

int hts_plat_notify_event_exception(soc_ip dev_id, int32_t pid)
{
    int ret = 0;
	if ((dev_id <= SOC_NONE) || (dev_id >= SOC_IPMAX)) {
		hts_drv_err("dev_id is invalid, dev_id:%u\n", dev_id);
		return -EINVAL;
	}

	g_exception_event.dev_id = dev_id;
    g_exception_event.pid = pid;
    hts_filter_recv_events(&g_exception_event);
	if (g_exception_event.length == 0) {
		hts_drv_err("dev_id:%u, pid:%d, no events need handling\n", dev_id, pid);
		return -EINVAL;
	}

    hts_drv_warn("dev_id:%u, pid:%d, suspicious exception event count:%u\n", dev_id, pid, g_exception_event.length);
    INIT_WORK(&g_exception_event.work, hts_async_notify_work);
    queue_work(system_wq, &g_exception_event.work);

	return ret;
}