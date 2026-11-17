#include "hts_event.h"
#include <linux/io.h>
#include <securec.h>
#include "hts_ioctl_services.h"
#include "hts_common.h"
#include "hts_kernel_log.h"
#include "hts_common_resource.h"
#include "hts_resmem.h"
#include "hts_rule.h"
#include "soc_hts_interface.h"
#include "hts_graph_manager.h"
#include "hts_graph_resource.h"
#include "hpd_interface.h"

uint32_t hts_event_get_num_by_uid(uint16_t uid)
{
	uint32_t i;
	uint32_t count = 0;
	hts_check_table auth_table = {0};
	struct hts_platform_info *plat_info = hts_plat_get_info();
 
	if (plat_info == NULL || plat_info->resmem_desc[HTS_RESMEM_AUTH_TABLE].virt_addr == (uint64_t)NULL) {
		hts_drv_err("get platform info or auth table error\n");
		return 0xFFFFFFFF;
	}
 
	for (i = 1; i <= HTS_MAX_EVENT_NUM; i++) {
		hts_get_auth_table(i, &auth_table);
		if (auth_table.data.valid == 1 && auth_table.data.uid == uid)
			count++;
	}
	
	return count;
}

void hts_event_set_uid(uint16_t uid) {
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	SOC_HTS_UID_UNION hts_uid = {0};
	hts_uid.reg.hts_uid = uid;
	writel(hts_uid.value, SOC_HTS_UID_ADDR(virt_addr));
}

int hts_event_free(uint16_t uid, uint16_t *tmp_events, uint32_t num)
{
	uint32_t i;
	uint32_t tmp_num = 0;
	hts_check_table table = {0};
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	struct hpd_registry *hpd = NULL;
	uint16_t* event_idle_num = NULL;
	event_alloc_type event_type;

	hts_drv_warn("cur input uid:%hu num:%u", uid, num);
	hpd = hts_get_hpd_registry();
	cond_return_error((hpd == NULL) || (hpd->hts_get_alloc_type_by_eventid == NULL), -EINVAL,
		"hpd or hts_get_alloc_type_by_eventid is not registered\n");
	event_type = hpd->hts_get_alloc_type_by_eventid(tmp_events[0]);
	if (event_type == MAX_ALLOC_TYPE) {
		hts_drv_err("get event_type fail, type:%d\n", event_type);
		return -EINVAL;
	}
	event_idle_num = &dev_ctx->res.event_num[event_type];
	
	hts_drv_warn("event_idle_num:%d, event type:%d", *event_idle_num, event_type);
	for (i = 0; i < num; i++) {
		hts_get_auth_table(tmp_events[i], &table);
		if (table.data.uid == uid && table.data.valid == 1) {
			hts_drv_warn("free event =%hu, tmp =%u", tmp_events[i], tmp_num);
			bitmap_clear(dev_ctx->res.event_bitmap, tmp_events[i], 1);
			table.data.valid = 0;
			table.data.uid = 0;
			(void)hts_set_auth_table(tmp_events[i], &table);
			tmp_num++;
		} else {
			hts_drv_err("auth tabel invalid,event:%hu uid:%hu valid:%u", tmp_events[i], table.data.uid, table.data.valid);
		}
	}
	*event_idle_num += tmp_num;

	return 0;
}

int hts_get_ip_event_by_uid(uint16_t uid, uint8_t dev_id, uint16_t *event_id, uint16_t buffer_num, uint16_t *event_num)
{
	int ret;
	uint16_t events[HTS_GRAPH_MAX_EVENT] = {0};
	uint16_t j = 0;
	uint16_t id;
	uint16_t num = 0;
	hts_check_table table = {0};
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();

	mutex_lock(&dev_ctx->mtx);
	for(id = 1; id <= HTS_MAX_EVENT_NUM; id++) {
		hts_get_auth_table(id, &table);
		if(table.data.uid == uid && table.data.valid == 1) {
			if (table.data.src_id == dev_id || table.data.dst_id == dev_id) {
				events[j++] = id;
				num ++;
			}
		}
		if (num > HTS_GRAPH_MAX_EVENT) {
			mutex_unlock(&dev_ctx->mtx);
			hts_drv_err("get event num is out of range, dev_id:%u, uid:%hu, event num:%hu,", dev_id, uid, num);
			return -EINVAL;
		}
	}
	mutex_unlock(&dev_ctx->mtx);
	*event_num = num;
	if (buffer_num < num) {
		hts_drv_err("buffer_num is too small, buffer_num:%hu, need num:%hu", buffer_num, num);
		return -EINVAL;
	}

	ret = memcpy_s(event_id, buffer_num * sizeof(uint16_t), events, num * sizeof(uint16_t));
	cond_return_error(ret != 0, -ENOMEM, "memcpy events failed \n");

	return 0;
}

void hts_event_lock_cfg(struct hts_rule_info *rule_info, hts_event_cmd_lock lock_cmd)
{
	uint8_t i;
	SOC_HTS_EVENT_LOCK_UNION event_lock = {0};
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	if (virt_addr == (uintptr_t)NULL) {
		hts_drv_err("get glb table addr failed\n");
		return;
	}

	// unlock src_event
	for (i = 0; i < rule_info->src_event_num; i++) {
		uint32_t event_lock_idx = rule_info->src_event[i] / HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM;
		uint32_t event_lock_bit = rule_info->src_event[i] % HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM;
		if (lock_cmd == EVENT_UNBLOCK) {
			event_lock.value = hts_event_unlock(event_lock_bit);
		} else {
			event_lock.value = hts_event_lock(event_lock_bit);
		}
		writel(event_lock.value, SOC_HTS_EVENT_LOCK_ADDR((virt_addr),event_lock_idx));	
	}
	// unlock dst_event
	for (i = 0; i < rule_info->dst_event_num; i++) {
		uint32_t event_lock_idx = rule_info->dst_event[i] / HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM;
		uint32_t event_lock_bit = rule_info->dst_event[i] % HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM;
		if (lock_cmd == EVENT_UNBLOCK) {
			if (atomic_read(&dev_ctx->dev_power_status[rule_info->dst_id[i]]) == 0)
				continue;
			event_lock.value = hts_event_unlock(event_lock_bit);
		} else {
			event_lock.value = hts_event_lock(event_lock_bit);
		}
		writel(event_lock.value,SOC_HTS_EVENT_LOCK_ADDR((virt_addr),event_lock_idx));	
	}
}

void hts_set_event_lock_or_unlock(uint16_t *events, uint32_t num, hts_event_cmd_lock lock_cmd)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	if (virt_addr == (uintptr_t)NULL) {
		hts_drv_err("get glb table addr failed\n");
		return;
	}
	for (i = 0; i < num; i++) {
		SOC_HTS_EVENT_LOCK_UNION event_lock = {0};
		if (lock_cmd == EVENT_UNBLOCK)
			event_lock.value = hts_event_unlock(events[i] % HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM);
		else
			event_lock.value = hts_event_lock(events[i] % HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM);
		writel(event_lock.value,
			  SOC_HTS_EVENT_LOCK_ADDR(virt_addr, events[i] / HTS_EVENT_LOCK_REG_CONTROL_EVENTS_NUM));  // each reg control 16 events
	}
}
