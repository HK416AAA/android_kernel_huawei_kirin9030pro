/*
 * Copyright (c) 2019-2019, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <linux/workqueue.h>
#include <linux/semaphore.h>
#include <linux/list.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <securec.h>
#include "mdfx_event.h"
#include "mdfx_utils.h"
#include "mdfx_priv.h"
#if defined (CONFIG_HUAWEI_DSM) || defined (CONFIG_HUAWEI_OHOS_DSM)
#include <dsm/dsm_pub.h>
#endif

static void mdfx_event_handle(struct mdfx_pri_data *mdfx_data, struct mdfx_event *event, void *data)
{
	struct mdfx_event_listener *_node_ = NULL;
	struct mdfx_event_listener *listener_node = NULL;
	struct mdfx_event_manager_t *event_manager = NULL;
	int i = 0;

	mdfx_pr_info("%s visitor_id=%lld, actions=%llu, event_name=%s",
		event->timestamp, event->visitor_id, event->desc.current_visitor_actions, event->desc.event_name);

	event_manager = &mdfx_data->event_manager;
	list_for_each_entry_safe(listener_node, _node_, &event_manager->listener_list, node) {
		if (!IS_ERR_OR_NULL(listener_node)) {
			mdfx_pr_info("i=%d, actor_type=%u, listener_node=%pK", i++, listener_node->actor_type, listener_node);
			if (listener_node->handle)
				listener_node->handle(mdfx_data, event, data);
		}
	}
}

static bool mdfx_event_need_report_to_user(const struct mdfx_event_desc *desc)
{
	uint32_t i = 0;

	if ((desc->current_visitor_actions & NEED_REPORT_TO_USER_MODE_ACTIONS) != 0)
		return true;

	for (i = 0; i < VISITOR_TYPE_MAX; i++) {
		if ((desc->relevant_visitor_actions[i] & NEED_REPORT_TO_USER_MODE_ACTIONS) != 0)
            return true;
	}

	return false;
}

static void mdfx_event_report_to_user(struct mdfx_event_manager_t *event_manager,
	const struct mdfx_event *report_event)
{
	unsigned long flags = 0;

	if (!mdfx_event_need_report_to_user(&report_event->desc)) {
		mdfx_pr_info("%s don't need report to user", report_event->desc.event_name);
		return;
	}

	spin_lock_irqsave(&(event_manager->event_lock), flags);
	event_manager->report_to_user_event = *report_event;
	event_manager->need_report_event = 1;
	spin_unlock_irqrestore(&(event_manager->event_lock), flags);

	mdfx_pr_info("report to user");
	wake_up_interruptible_all(&(event_manager->event_wait));
}

static ssize_t mdfx_event_build_event_buf(struct mdfx_event_manager_t *event_manager, char *buf, ssize_t size)
{
	struct mdfx_event_desc *desc = NULL;
	ssize_t ret, len;
	uint32_t i;

	if (size <= 0 || size > PAGE_SIZE) //lint !e574
		return 0;

	if (mdfx_event_check_parameter(&event_manager->report_to_user_event) != 0)
		return 0;

	desc = &event_manager->report_to_user_event.desc;
	len = scnprintf(buf, size, "name=%s,visitor_id=%" PRIu64 ",actions=%" PRIu64 ",count=%u,frame_index=%u",
					desc->event_name, event_manager->report_to_user_event.visitor_id, desc->current_visitor_actions,
					VISITOR_TYPE_MAX, desc->frame_index);
	if (len >= size)
		return size;

	for (i = 0; i < VISITOR_TYPE_MAX; i++) {
		ret = scnprintf(buf + len, size - len - 1, ",relevant_visitor_actions[%u]=%" PRIu64,
					i, desc->relevant_visitor_actions[i]);
		if (ret >= size || ret + len >= size)
			return size;

		len += ret;
		if (len >= size)
			return size;
	}
	
	return len;
}

static ssize_t mdfx_show_event(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct mdfx_device_data *device_data = NULL;
	struct mdfx_event_manager_t *event_manager = NULL;
	int32_t ret;
	ssize_t len = 0;
	unsigned long flags = 0;

	if (IS_ERR_OR_NULL(dev) || IS_ERR_OR_NULL(attr) || IS_ERR_OR_NULL(buf))
		return -1;

	device_data = dev_get_drvdata(dev);
	if (IS_ERR_OR_NULL(device_data))
		return -1;

	event_manager = &device_data->data.event_manager;

	mdfx_pr_info("waiting report event");
	ret = wait_event_interruptible(event_manager->event_wait, (event_manager->need_report_event == 1)); //lint !e578
	if (!ret && event_manager->need_report_event) {
		spin_lock_irqsave(&(event_manager->event_lock), flags);
		len = mdfx_event_build_event_buf(event_manager, buf, PAGE_SIZE);
		event_manager->need_report_event = 0;
		spin_unlock_irqrestore(&(event_manager->event_lock), flags);
		mdfx_pr_info("report event, buf = %s", buf);
	}

	return len;
}
static DEVICE_ATTR(event_report, S_IRUSR | S_IRGRP | S_IROTH, mdfx_show_event, NULL);

/*
 * desc's client id need be assigned by caller
 */
static void mdfx_event_build_underflow_desc(struct mdfx_event_desc *desc)
{
	strcpy_s(desc->event_name, MDFX_EVENT_NAME_MAX, "underflow");
	desc->event_type = MDFX_EVENT_UNDERFLOW;
	desc->current_visitor_actions = DUMP_DETAIL_IMAGE_BUF | DUMP_DETAIL_LAYER_INFO |   // 保存图源和图层信息
									DUMP_DETAIL_DACC_LOG | // dacc log
	                       			TRACING_DETAIL_MASK | // 保存相关的tracing流程
	                       			LOG_DETAIL_STORE_USER_LOG | LOG_DETAIL_STORE_KMD_LOG | // 保存user和kernel log
	                      			NOTIFY_DETAIL_ALL_INFO;  // notify所有的user，执行保存相关信息的操作
}

static void mdfx_event_build_vactive_timeout_desc(struct mdfx_event_desc *desc)
{
	strcpy_s(desc->event_name, MDFX_EVENT_NAME_MAX, "vactive_timeout");
	desc->event_type = MDFX_EVENT_VACTIVE_TIMEOUT;
	desc->current_visitor_actions = DUMP_DETAIL_IMAGE_BUF | DUMP_DETAIL_LAYER_INFO |   // 保存图源和图层信息
									DUMP_DETAIL_DACC_LOG | // dacc log
	                       			TRACING_DETAIL_MASK | // 保存相关的tracing流程
	                       			LOG_DETAIL_STORE_USER_LOG | LOG_DETAIL_STORE_KMD_LOG | // 保存user和kernel log
	                      			NOTIFY_DETAIL_ALL_INFO;  // notify所有的user，执行保存相关信息的操作
}

static void mdfx_event_build_fence_timeout_desc(struct mdfx_event_desc *desc)
{
	strcpy_s(desc->event_name, MDFX_EVENT_NAME_MAX, "fence_timeout");
	desc->event_type = MDFX_EVENT_FENCE_TIMEOUT;
	desc->current_visitor_actions = DUMP_DETAIL_IMAGE_BUF | DUMP_DETAIL_LAYER_INFO | DUMP_DETAIL_ALL_CPU_RUNNABLE |
	                       			TRACING_DETAIL_0 | TRACING_DETAIL_1 | // 保存相关的tracing流程
	                       			LOG_DETAIL_STORE_KMD_LOG;
}

static void mdfx_event_build_sdma_hebc_error_desc(struct mdfx_event_desc *desc)
{
	strcpy_s(desc->event_name, MDFX_EVENT_NAME_MAX, "sdma_hebc_error");
	desc->event_type = MDFX_EVENT_SDMA_HEBC_ERROR;
	desc->current_visitor_actions = DUMP_DETAIL_IMAGE_BUF | DUMP_DETAIL_LAYER_INFO | LOG_DETAIL_STORE_USER_LOG;
}

static void mdfx_event_build_normal_trigger_desc(struct mdfx_event_desc *desc)
{
	strcpy_s(desc->event_name, MDFX_EVENT_NAME_MAX, "normal_trigger");
	desc->event_type = MDFX_EVENT_NORMAL_TRIGGER;
	desc->current_visitor_actions = DUMP_DETAIL_IMAGE_BUF | DUMP_DETAIL_LAYER_INFO | TRACING_DETAIL_MASK |
	                       			LOG_DETAIL_STORE_USER_LOG | LOG_DETAIL_STORE_KMD_LOG;
}

static struct mdfx_event_node *mdfx_get_event_node(struct mdfx_event_manager_t *manager, uint32_t event_type)
{
	struct mdfx_event_node *event_node = NULL;
	struct mdfx_event_node *_event_node_ = NULL;

	list_for_each_entry_safe(event_node, _event_node_, &manager->event_list, node) {
		if (event_node->event_type == event_type)
			return event_node;
	}

	return NULL;
}

static bool mdfx_update_event_timestamp(struct mdfx_event_node *event)
{
	struct timespec64 current_time;
	int interval;

	ktime_get_ts64(&current_time);
	if (event->event_type == MDFX_EVENT_NORMAL_TRIGGER) {
		event->time = current_time;
		return true;
	}

	interval = current_time.tv_sec - event->time.tv_sec;
	if (interval >= MDFX_REPORT_EVENT_INTERVAL_SEC) {
		event->time = current_time;
		return true;
	}

	mdfx_pr_info("update event timestamp fail interval=%d", interval);
	return false;
}

static bool mdfx_add_event_to_list(struct mdfx_event_manager_t *manager, uint32_t event_type)
{
	/* find the event, judge the timediff and update timestamp */
	struct mdfx_event_node *event = mdfx_get_event_node(manager, event_type);
	if (event)
		return mdfx_update_event_timestamp(event);

	event = kzalloc(sizeof(*event), GFP_KERNEL);
	if (!event)
		return false;

	event->event_type = event_type;
	ktime_get_ts64(&event->time);
	list_add_tail(&event->node, &manager->event_list);

	return true;
}

int mdfx_event_check_parameter(struct mdfx_event *event)
{
	if (event->visitor_id < VISITOR_ID_MIN) {
		mdfx_pr_err("invalid client id=%lld", event->visitor_id);
		return -1;
	}

	if (event->desc.current_visitor_actions == 0) {
		mdfx_pr_err("invalid action");
		return -1;
	}

	return 0;
}

#if defined (CONFIG_HUAWEI_DSM) || defined (CONFIG_HUAWEI_OHOS_DSM)
int mdfx_report_dmd(struct dsm_client *client, long dmd_no, const char *dmd_info)
{
	if (IS_ERR_OR_NULL(dmd_info) || IS_ERR_OR_NULL(client)) {
		mdfx_pr_info("para error: %lx\n", dmd_no);
		return -1;
	}

	/* it should be record in kmsg when dmd happened */
	mdfx_pr_info("dmd no: %lx - %s", dmd_no, dmd_info);
	if (!dsm_client_ocuppy(client)) {
		dsm_client_record(client, "DMD info:%s", dmd_info);
		dsm_client_notify(client, dmd_no);
	}
	return 0;
}
#endif

void mdfx_event_init(struct mdfx_pri_data *mdfx_data)
{
	struct mdfx_event_manager_t *event_manager = NULL;

	event_manager = &mdfx_data->event_manager;

	INIT_LIST_HEAD(&event_manager->listener_list);
	INIT_LIST_HEAD(&event_manager->event_list);
	spin_lock_init(&event_manager->event_lock);
	init_waitqueue_head(&event_manager->event_wait);
	event_manager->need_report_event = 0;

	mdfx_sysfs_append_attrs(mdfx_data, &dev_attr_event_report.attr);

	mdfx_event_build_underflow_desc(&event_manager->default_event[MDFX_EVENT_UNDERFLOW]);
	mdfx_event_build_vactive_timeout_desc(&event_manager->default_event[MDFX_EVENT_VACTIVE_TIMEOUT]);
	mdfx_event_build_fence_timeout_desc(&event_manager->default_event[MDFX_EVENT_FENCE_TIMEOUT]);
	mdfx_event_build_sdma_hebc_error_desc(&event_manager->default_event[MDFX_EVENT_SDMA_HEBC_ERROR]);
	mdfx_event_build_normal_trigger_desc(&event_manager->default_event[MDFX_EVENT_NORMAL_TRIGGER]);
}

void mdfx_event_deinit(struct mdfx_event_manager_t *event_manager)
{
	struct mdfx_event_listener* _node_ = NULL;
	struct mdfx_event_listener* listener_node = NULL;
	struct mdfx_event_node *event_node = NULL;
	struct mdfx_event_node *_event_node_ = NULL;

	list_for_each_entry_safe(listener_node, _node_, &event_manager->listener_list, node) {
		list_del(&listener_node->node);
		kfree(listener_node);
		listener_node = NULL;
	}

	list_for_each_entry_safe(event_node, _event_node_, &event_manager->event_list, node) {
		list_del(&event_node->node);
		kfree(event_node);
		event_node = NULL;
	}

	(void)memset_s(event_manager->default_event, sizeof(event_manager->default_event),
			 0, sizeof(event_manager->default_event));
}

int mdfx_event_register_listener(struct mdfx_pri_data *mdfx_data, uint32_t actor_type, listener_act_func cb)
{
	struct mdfx_event_listener *listener = NULL;

	mdfx_pr_info("actor_type = %u, cb=%pK", actor_type, cb);

	listener = kzalloc(sizeof(*listener), GFP_KERNEL);
	if (!listener)
		return -ENOMEM;

	listener->actor_type = actor_type;
	listener->handle = cb;

	list_add_tail(&listener->node, &mdfx_data->event_manager.listener_list);

	mdfx_pr_info("actor_type=%u, listener=%pK", actor_type, listener);

	return 0;
}

int mdfx_deliver_event(struct mdfx_pri_data *mdfx_data, const void __user *argp)
{
	struct mdfx_event event = {0};

	if ((mdfx_data == NULL) || (argp == NULL))
		return -EINVAL;

	if (!MDFX_HAS_CAPABILITY(g_mdfx_caps, MDFX_CAP_EVENT))
		return 0;

	if (copy_from_user(&event, argp, sizeof(event))) {
		mdfx_pr_err("copy event event fail from user");
		return -1;
	}

	if (mdfx_event_check_parameter(&event)) {
		mdfx_pr_err("check parameter fail");
		return -1;
	}

	/* event can't be reported too often, the same events must have at least 5 second interval */
	if (!mdfx_add_event_to_list(&mdfx_data->event_manager, event.desc.event_type)) {
		mdfx_pr_info("add event to list fail");
		return 0;
	}

	mdfx_get_file_name_timestamp(event.timestamp, MDFX_EVENT_TIMESTAMP_MAX);
	mdfx_event_handle(mdfx_data, &event, NULL);
	return 0;
}

void mdfx_report_event(int64_t visitor_id, struct mdfx_event_desc *desc, void *data)
{
	struct mdfx_event event = {0};

	if (IS_ERR_OR_NULL(desc) || IS_ERR_OR_NULL(g_mdfx_data) || (visitor_id < VISITOR_ID_MIN))
		return;

	if (!MDFX_HAS_CAPABILITY(g_mdfx_caps, MDFX_CAP_EVENT))
		return;

	if (desc->current_visitor_actions == 0) {
		mdfx_pr_warn("invalid event desc");
		return;
	}

	/* event can't be reported too often, the same events must have at least 5 second interval */
	if (!mdfx_add_event_to_list(&g_mdfx_data->event_manager, desc->event_type)) {
		mdfx_pr_info("add event to list fail");
		return;
	}

	mdfx_pr_info("report event=%s, actions=%llu", desc->event_name, desc->current_visitor_actions);

	event.visitor_id = visitor_id;
	if (memcpy_s(&event.desc, sizeof(event.desc), desc, sizeof(*desc)) != EOK) {
		mdfx_pr_warn("memcpy_s fail!");
	}

	mdfx_get_file_name_timestamp(event.timestamp, MDFX_EVENT_TIMESTAMP_MAX);
	mdfx_event_handle(g_mdfx_data, &event, data);   // listeners will handle this event

	/* some events need mdfx server to handle it,
	 * so need report to user.
	 */
	mdfx_event_report_to_user(&g_mdfx_data->event_manager, &event);
}
EXPORT_SYMBOL(mdfx_report_event); //lint !e580

void mdfx_report_default_event(int64_t visitor_id, uint32_t default_event_type, uint32_t frame_index, void *data)
{
	struct mdfx_event_desc *default_desc = NULL;

	if ((default_event_type >= MDFX_EVENT_MAX) || (visitor_id < VISITOR_ID_MIN) || (IS_ERR_OR_NULL(g_mdfx_data)))
		return;

	mdfx_pr_info("report default event visitor=%lld, event_type=%u", visitor_id, default_event_type);

	default_desc = &g_mdfx_data->event_manager.default_event[default_event_type];
	default_desc->frame_index = frame_index;
	mdfx_report_event(visitor_id, default_desc, data);
}
EXPORT_SYMBOL(mdfx_report_default_event); //lint !e580
