
#include "hts_ioctl_services.h"
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>
#include "hts_kernel_log.h"
#include "hts_devinit.h"
#include "hpd_interface.h"
#include "uniform_id.h"
#include "hts_common.h"
#include "hts_rule.h"
#include "hts_event.h"
#include "hts_graph_manager.h"
#include "hts_graph_resource.h"
#include "hts_profiling.h"

static int hts_ioctl_set_rule(unsigned long arg)
{
	int ret;
	uint32_t uid;
	struct hts_set_rule_info *set_rule_info = NULL;
	struct hpd_registry *hpd = NULL;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();

	hts_drv_info("enter ioctl set rule\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "dev ctx is null\n");
	cond_return_error(atomic_read(&dev_ctx->dev_power_status[0]) == 0, -EINVAL,
		"hts power off, can not set rule\n");
	hpd = hts_get_hpd_registry();
	cond_return_error((hpd == NULL) || (hpd->hts_set_rule == NULL), -EINVAL,
		"hpd or set_rule is not registered\n");

	set_rule_info = kmalloc(sizeof(struct hts_set_rule_info), GFP_KERNEL);
	cond_return_error(set_rule_info == NULL, -ENOMEM, "malloc failed, need memeory\n");

	ret = hts_copy_from_user_safe(set_rule_info, (void __user *)(uintptr_t)arg, sizeof(struct hts_set_rule_info));
	if (ret != 0) {
		hts_drv_err("fail to copy set_rule_info, ret=%d\n", ret);
		kfree(set_rule_info);
		return -EINVAL;
	}
	if ((set_rule_info->handle.graph_id < 0) || (set_rule_info->handle.graph_id >=
		HTS_TEST_GRAPH_ID_BEGIN + HTS_TEST_GRAPH_NUM)) {
		hts_drv_err("graph id is invalid, ret=%d\n", ret);
		kfree(set_rule_info);
		return -EINVAL;
	}

	mutex_lock(&dev_ctx->mtx);
	uid = ffrt_get_uniform_id_with_reserve(set_rule_info->handle.pid);
	cond_goto_error(uid == FFRT_INVALID_UNIFORM_ID, set_rule_exit, ret, -EINVAL,
					"ffrt get uid error uid = %u\n", uid);
	cond_goto_error(uid != hts_get_uid_by_graph_id(set_rule_info->handle.graph_id, set_rule_info->handle.pid), set_rule_exit,
					ret, -EINVAL, "uid is not match\n");

	cond_goto_error((set_rule_info->rule_num <= 0) || (set_rule_info->rule_num > HTS_GRAPH_MAX_RULE),
					set_rule_exit, ret, -EINVAL, "rule num is invalid, rule_num=%d\n", set_rule_info->rule_num);
	cond_goto_error(set_rule_info->rule_num > dev_ctx->res.rule_num, set_rule_exit, ret, -EINVAL,
					"rule resource is not enough\n");
	ret = hpd->hts_set_rule(set_rule_info->graph_rules, set_rule_info->rule_num, uid);
	cond_goto_error(ret != 0, set_rule_exit, ret, -EINVAL, "fail to set rule, ret=%d\n", ret);

	ret = hts_set_rules_by_graph_id(set_rule_info->handle.graph_id, set_rule_info);
	if (ret != 0) {
		hts_drv_err("set rules by graph id fail\n");
		(void)hpd->hts_destroy_rule(set_rule_info->graph_rules, set_rule_info->rule_num, uid);
		goto set_rule_exit;
	}
	
	dev_ctx->res.rule_num -= (uint16_t)set_rule_info->rule_num;

set_rule_exit:
	mutex_unlock(&dev_ctx->mtx);
	kfree(set_rule_info);
	return ret;
}

static int hts_ioctl_unset_rule(unsigned long arg)
{
	int ret;
	uint32_t uid;
	struct hpd_registry *hpd = NULL;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	hts_graph_handle_t graph_handle = {};
	struct hts_rule_save_info* rule_info;
 
	hts_drv_info("start\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "dev ctx is null\n");
	cond_return_error(atomic_read(&dev_ctx->dev_power_status[0]) == 0, -EINVAL,
		"hts power off, can not set rule\n");
	hpd = hts_get_hpd_registry();
	cond_return_error((hpd == NULL) || (hpd->hts_destroy_rule == NULL), -EINVAL,
		"hpd or hts_destroy_rule is not registered\n");
 
	ret = hts_copy_from_user_safe(&graph_handle, (void __user *)(uintptr_t)arg, sizeof(hts_graph_handle_t));
	cond_return_error(ret != 0, -ENOMEM, "fail to copy graph_handle, ret=%d\n", ret);

	cond_return_error((graph_handle.graph_id < 0) || (graph_handle.graph_id >= HTS_TEST_GRAPH_ID_BEGIN + HTS_TEST_GRAPH_NUM), 
		-EINVAL, "graph id is invalid, ret=%d\n", ret);
	hts_drv_info("unset rule pid%u, graph id%u\n", graph_handle.pid, graph_handle.graph_id);
	mutex_lock(&dev_ctx->mtx);
	uid = hts_get_uid_by_graph_id(graph_handle.graph_id, graph_handle.pid);
	cond_goto_error(uid == FFRT_INVALID_UNIFORM_ID, unset_rule_exit, ret, -EINVAL,
					"ffrt get uid error uid = %u\n", uid);
	ret = hts_get_rules_by_graph_id(graph_handle.graph_id, &rule_info);
	cond_goto_error(ret != 0, unset_rule_exit, ret, -EINVAL, "fail to get rules, ret=%d\n", ret);
	hts_drv_warn("unset rule pid:%d, rule num:%u, rule_res:%hu\n",
				graph_handle.pid, rule_info->rule_num, dev_ctx->res.rule_num);

	ret = hpd->hts_destroy_rule(rule_info->rules, rule_info->rule_num, uid);
	cond_goto_error(ret != 0, unset_rule_exit, ret, -EINVAL, "ioctl destory rule end ret=%d\n", ret);
	dev_ctx->res.rule_num += (uint16_t)rule_info->rule_num;

	ret = hts_remove_rules_by_graph_id(graph_handle.graph_id);
	if (ret != 0) {
		hts_drv_err("remove rules by graph id fail\n");
	}
unset_rule_exit:
	mutex_unlock(&dev_ctx->mtx);
	return ret;
}

static int hts_ioctl_event_alloc(unsigned long arg)
{
	int ret;
	uint16_t uid = 0;
	struct hts_alloc_info events_info = {0};
	struct hpd_registry *hpd = NULL;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();

    cond_return_error(dev_ctx == NULL, -EINVAL, "dev ctx is null\n");
	ret = hts_copy_from_user_safe(&events_info , (void __user *)(uintptr_t)arg, sizeof(struct hts_alloc_info));
	cond_return_error(ret != 0, -EINVAL, "fail to copy event_info, ret = %d", ret);

	cond_return_error(events_info.event_num > HTS_GRAPH_MAX_EVENT, -EINVAL, "event num %d is too large", events_info.event_num);
	cond_return_error(events_info.sched_type >= MAX_SCHED_TYPE, -EINVAL, "sched_type %d is illegal", events_info.sched_type);
	cond_return_error((events_info.handle_t.graph_id < 0) || (events_info.handle_t.graph_id >= HTS_MAX_GRAPH_ID),
		-EINVAL, "graph id is invalid, ret=%d\n", ret);
	cond_return_error(events_info.dev_type >= SOC_IPMAX, -EINVAL, "dev_type %u is illegal", events_info.dev_type);
	hpd = hts_get_hpd_registry();
	cond_return_error((hpd == NULL) || (hpd->hts_event_alloc == NULL), -EINVAL,
		"hpd or hts_event_alloc is not registered\n");
	uid = ffrt_get_uniform_id_with_reserve(events_info.handle_t.pid);
	cond_return_error(uid == FFRT_INVALID_UNIFORM_ID, -EINVAL, "ffrt get uid error uid = %u\n", uid);
	hts_drv_info("uid = %u ,graph_id = %d, pid = %d, dev_type = %d, sched_type = %d\n", uid, events_info.handle_t.graph_id, 
		events_info.handle_t.pid, events_info.dev_type, events_info.sched_type);
	mutex_lock(&dev_ctx->mtx);

	ret = hpd->hts_event_alloc(uid, &events_info, events_info.handle_t.graph_id);
	cond_goto_error(ret != 0, alloc_event_fail, ret, -EINVAL, "fail to alloc event");
	ret = hts_set_events(&events_info);
	if (ret != 0) {
		hts_drv_err("set events fail\n");
		(void)hts_event_free(uid, &events_info.events[0], events_info.event_num);
		goto alloc_event_fail;
	}
	hts_event_set_uid(uid);
	hts_set_graph_info_map(events_info.handle_t.graph_id, uid, events_info.handle_t.pid);

	if (events_info.sched_type == DYNAMIC_SCHED) {
		hts_set_dynamic_graph_info(uid, &events_info);
		hts_set_event_lock_or_unlock(&events_info.events[0], events_info.event_num, EVENT_UNBLOCK);
	}
	ret = hts_copy_to_user_safe((void __user *)(uintptr_t)arg, &events_info, sizeof(struct hts_alloc_info));
	cond_goto_error(ret != 0, copy_to_user_fail, ret, -EINVAL, "fail to copy events, ret = %d", ret);
	mutex_unlock(&dev_ctx->mtx);

#ifdef HTS_DEBUG_EN
	hts_record_key_info();
#endif
	return ret;
copy_to_user_fail:
	hts_remove_events_by_graph_id(events_info.handle_t.graph_id);
	hts_set_graph_info_map(events_info.handle_t.graph_id, 0, 0);
	if (events_info.sched_type == DYNAMIC_SCHED) {
		hts_set_event_lock_or_unlock(&events_info.events[0], events_info.event_num, EVENT_BLOCK);
		hts_reset_dynamic_graph_info(events_info.handle_t.graph_id);
	}
	(void)hts_event_free(uid, &events_info.events[0], events_info.event_num);
alloc_event_fail:
	mutex_unlock(&dev_ctx->mtx);
	return ret;
}

static int hts_ioctl_event_free(unsigned long arg)
{
	int ret;
	uint16_t uid;
	uint32_t event_num;
	sched_type schedule_type;
	hts_graph_handle_t graph_handle = {};
	uint16_t events[HTS_GRAPH_MAX_EVENT] = {0};
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();

	cond_return_error(dev_ctx == NULL, -EINVAL, "dev ctx is null\n");

#ifdef HTS_DEBUG_EN
	hts_record_key_info();
#endif

	ret = hts_copy_from_user_safe(&graph_handle , (void __user *)(uintptr_t)arg, sizeof(hts_graph_handle_t));
	cond_return_error(ret != 0, -EINVAL, "fail to copy graph_handle, ret = %d", ret);

	cond_return_error((graph_handle.graph_id < 0) || (graph_handle.graph_id >= HTS_MAX_GRAPH_ID), 
		-EINVAL, "graph id is invalid, ret=%d\n", ret);
	uid = hts_get_uid_by_graph_id(graph_handle.graph_id, graph_handle.pid);
	if (uid == FFRT_INVALID_UNIFORM_ID) {
		hts_drv_err("ffrt get uid error uid = %u\n", uid);
		return -EINVAL;
	}

	mutex_lock(&dev_ctx->mtx);
	ret = hts_get_events_by_graph_id(graph_handle.graph_id, events, &event_num);
	if (ret != 0) {
		hts_drv_err("get events fail\n");
		mutex_unlock(&dev_ctx->mtx);
		return ret;
	}

	(void)hts_event_free(uid, events, event_num);
	schedule_type = hts_get_sched_type_by_event_id(events[0]);
	hts_remove_events_by_graph_id(graph_handle.graph_id);
	hts_set_graph_info_map(graph_handle.graph_id, 0, 0);

	if (schedule_type == DYNAMIC_SCHED) {
		hts_set_event_lock_or_unlock(&events[0], event_num, EVENT_BLOCK);
		hts_reset_dynamic_graph_info(graph_handle.graph_id);
	}
	mutex_unlock(&dev_ctx->mtx);

	return 0;
}

static int hts_ioctl_enable_graph(unsigned long arg)
{
	int ret;
	size_t i;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	hts_graph_handle_t graph_handle = {};
	struct hts_rule_save_info* rule_info;

	hts_drv_info("enter ioctl enable graph\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "dev ctx is null\n");
	cond_return_error(atomic_read(&dev_ctx->dev_power_status[0]) == 0, -EINVAL,
		"hts power off, can not enable graph\n");
 
	ret = hts_copy_from_user_safe(&graph_handle, (void __user *)(uintptr_t)arg, sizeof(hts_graph_handle_t));
	cond_return_error(ret != 0, -ENOMEM, "fail to copy graph_handle, ret=%d\n", ret);
	cond_return_error((graph_handle.graph_id < 0) || (graph_handle.graph_id >= HTS_TEST_GRAPH_ID_BEGIN + HTS_TEST_GRAPH_NUM), 
		-EINVAL, "graph id is invalid, ret=%d\n", ret);
	hts_drv_warn("enable graph pid%u, graph id%u\n", graph_handle.pid, graph_handle.graph_id);
 
	mutex_lock(&dev_ctx->mtx);
	ret = hts_get_rules_by_graph_id(graph_handle.graph_id, &rule_info);
	if (ret != 0) {
		hts_drv_err("fail to get rules\n");
		mutex_unlock(&dev_ctx->mtx);
		return ret;
	}
	for (i = 0; i < rule_info->rule_num; i++)
		hts_event_lock_cfg(&(rule_info->rules[i]), EVENT_UNBLOCK);
	mutex_unlock(&dev_ctx->mtx);
	return ret;
}

static int hts_ioctl_disable_graph(unsigned long arg)
{
	int ret;
	size_t i;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	hts_graph_handle_t graph_handle = {};
	struct hts_rule_save_info* rule_info = NULL;

	hts_drv_info("enter ioctl disable graph\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "dev ctx is null\n");
	cond_return_error(atomic_read(&dev_ctx->dev_power_status[0]) == 0, -EINVAL,
		"hts power off, can not disable graph\n");
 
	ret = hts_copy_from_user_safe(&graph_handle, (void __user *)(uintptr_t)arg, sizeof(hts_graph_handle_t));
	cond_return_error(ret != 0, -ENOMEM, "fail to copy graph_handle, ret=%d\n", ret);
	cond_return_error((graph_handle.graph_id < 0) || (graph_handle.graph_id >= HTS_TEST_GRAPH_ID_BEGIN + HTS_TEST_GRAPH_NUM), 
		-EINVAL, "graph id is invalid, ret=%d\n", ret);
	hts_drv_warn("disable graph pid%u, graph id%u\n", graph_handle.pid, graph_handle.graph_id);

	mutex_lock(&dev_ctx->mtx);
	ret = hts_get_rules_by_graph_id(graph_handle.graph_id, &rule_info);
	if (ret != 0) {
		hts_drv_err("fail to get rules\n");
		mutex_unlock(&dev_ctx->mtx);
		return ret;
	}
	for (i = 0; i < rule_info->rule_num; i++)
		hts_event_lock_cfg(&(rule_info->rules[i]), EVENT_BLOCK);
	mutex_unlock(&dev_ctx->mtx);
	return ret;
}

#ifdef HTS_DEBUG_EN
static int hts_ioctl_profiling(unsigned long arg)
{
	int ret;
	uint32_t id;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
 
	hts_drv_info("enter ioctl profiling\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "dev ctx is null\n");
	if (atomic_read(&dev_ctx->dev_power_status[0]) == 0) {
		hts_drv_err("hts power off, can not profiling\n");
		return -EINVAL;
	}

	ret = hts_copy_from_user_safe(&id, (void __user *)(uintptr_t)arg, sizeof(uint32_t));
	if (ret != 0) {
		hts_drv_err("fail to copy set_rule_info, ret=%d\n", ret);
		return -ENOMEM;
	}
 
	hts_info_readback(id);
	hts_drv_info("ioctl profiling end ret=%d\n", ret);
	return ret;
}
#endif

static int (*hts_ioctl_call[HTS_MAX_CMD])(unsigned long arg) = {
	[_IOC_NR(HTS_PROC_DESTORY_RULE)] = NULL,
	[_IOC_NR(HTS_EVENT_ALLOC)] = hts_ioctl_event_alloc,
	[_IOC_NR(HTS_EVENT_FREE)] = hts_ioctl_event_free,
	[_IOC_NR(HTS_SET_RULE)] = hts_ioctl_set_rule,
	[_IOC_NR(HTS_UNSET_RULE)] = hts_ioctl_unset_rule,
	[_IOC_NR(HTS_ENABLE_GRAPH)] = hts_ioctl_enable_graph,
	[_IOC_NR(HTS_DISABLE_GRAPH)] = hts_ioctl_disable_graph,
#ifdef HTS_DEBUG_EN
	[_IOC_NR(HTS_PROC_EVENT_FREE)] = NULL,
	[_IOC_NR(HTS_RESOURCE_CLEAR)] = NULL,
	[_IOC_NR(HTS_PROFILING)] = hts_ioctl_profiling,
#endif
};

long hts_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
	int ret;
	unused(filep);
	if (cmd < _IO(HTS_MAGIC, 1) || cmd >= _IO(HTS_MAGIC, HTS_MAX_CMD)) {
		hts_drv_err("parameter,arg = 0x%lx, cmd = %u\n", arg, cmd);
		return -EINVAL;
	}
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");

	if (hts_ioctl_call[_IOC_NR(cmd)] == NULL) {
		hts_drv_err("invalid cmd = %u\n", cmd);
		return -EINVAL;
	}

	ret = hts_ioctl_call[_IOC_NR(cmd)](arg);
	if (ret != 0) {
		hts_drv_err("process failed, cmd = %u\n", cmd);
		return -EINVAL;
	}

	return ret;
}
