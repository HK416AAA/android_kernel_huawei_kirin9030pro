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

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/workqueue.h>
#include <linux/semaphore.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <securec.h>
#include "hisi_mdfx.h"
#include "mdfx_debug.h"
#include "mdfx_priv.h"

#define MDFX_SET_LOG_FILE_COUNT_STR    "log_file_count="
#define MDFX_DEBUG_SET_CAPS_STR        "mdfx_caps="
#define MDFX_DEBUG_TRIGGER_ACTOR_STR   "trigger_actor="
#define MDFX_UPDATE_DEBUGGER_STR       "update="
#define MDFX_LOG_FILE_MAX_COUNT 100

static ssize_t mdfx_debugger_event_store(struct device *device,
			struct device_attribute *attr, const char *buf, size_t count)
{
	int64_t visitor_id;
	uint32_t default_event;
	int ret;

	if (IS_ERR_OR_NULL(device) || IS_ERR_OR_NULL(attr) || IS_ERR_OR_NULL(buf))
		return -1;

	ret = sscanf_s(buf, "%lld %u", &visitor_id, &default_event);
	if (ret < 0)
		mdfx_pr_err("sscanf error");
	
	mdfx_pr_info("visitor_id=%lld, event=%u", visitor_id, default_event);

	mdfx_report_default_event(visitor_id, default_event, NULL, NULL);
	return count;
}

static ssize_t mdfx_debugger_event_show(struct device *device, struct device_attribute *attr, char *buf)
{
	if (IS_ERR_OR_NULL(device) || IS_ERR_OR_NULL(attr) || IS_ERR_OR_NULL(buf)) {
		mdfx_pr_err("dev or attr or buf is null");
		return -1;
	}

	mdfx_pr_info("enter!");

    return scnprintf(buf, PAGE_SIZE - 1, "cmd format is: xx yy"
					 "xx is visitor_id, yy is event_id,"
					 "event_id 0 is underflow, 1 is vactive timeout, 2 is fence timeout");
}

static DEVICE_ATTR(report_default_event, 0640, mdfx_debugger_event_show, mdfx_debugger_event_store);

static ssize_t mdfx_debugger_show(struct device *device, struct device_attribute *attr, char *buf)
{
	if (IS_ERR_OR_NULL(device) || IS_ERR_OR_NULL(attr) || IS_ERR_OR_NULL(buf)) {
		mdfx_pr_err("dev or attr or buf is null");
		return -1;
	}

	mdfx_pr_info("enter!");

    return scnprintf(buf, PAGE_SIZE - 1, "cmd format is: log_file_count=xx, "
					"or mdfx_caps=xx, or trigger_actor=xx");
}

static void mdfx_debugger_update_file_count(const char *buf, struct mdfx_pri_data *mdfx_data)
{
	uint32_t file_count = 0;
	int32_t ret;

	if (strstr(buf, MDFX_SET_LOG_FILE_COUNT_STR) != NULL) {
		ret = sscanf_s(buf + strlen(MDFX_SET_LOG_FILE_COUNT_STR), "%u", &file_count);
		if (ret < 0) {
			mdfx_pr_err("sscanf error");
			return;
		}

		if ((file_count <= MDFX_LOG_FILE_MAX_COUNT) && (file_count > 1)) {
			mdfx_pr_info("var_log_file_count = %u before", mdfx_data->var_log_file_count);
			mdfx_data->var_log_file_count = file_count;
			mdfx_pr_info("var_log_file_count = %u after", mdfx_data->var_log_file_count);
		}
	}
}

static void mdfx_debugger_update_caps(const char *buf)
{
	uint32_t mdfx_caps = 0;
	int32_t ret;

	if (strstr(buf, MDFX_DEBUG_SET_CAPS_STR) != NULL) {
		ret = sscanf_s(buf + strlen(MDFX_DEBUG_SET_CAPS_STR), "%u", &mdfx_caps);
		if (ret < 0) {
			mdfx_pr_err("sscanf error");
			return;
		}

		mdfx_pr_info("mdfx_caps = %u before", g_mdfx_caps);
		g_mdfx_caps = mdfx_caps;
		mdfx_pr_info("mdfx_caps = %u after", g_mdfx_caps);
	}
}

static void mdfx_debugger_trigger_actor(const char *buf, struct mdfx_pri_data *mdfx_data)
{
	int ret;
	uint32_t actor_index = 0;
	struct mdfx_actor_t *actor = NULL;
	struct mdfx_event event = {0};

	if (strstr(buf, MDFX_DEBUG_TRIGGER_ACTOR_STR) != NULL) {
		ret = sscanf_s(buf + strlen(MDFX_DEBUG_TRIGGER_ACTOR_STR), "%u", &actor_index);
		if (ret < 0) {
			mdfx_pr_err("sscanf error");
			return;
		}

		if (actor_index >= ACTOR_MAX) {
			mdfx_pr_err("actor %u is error", actor_index);
			return;
		}
		mdfx_pr_info("trigger actor %u", actor_index);
		actor = &mdfx_data->actors[actor_index];
        if (actor->ops != NULL && actor->ops->act != NULL) {
			event.visitor_id = mdfx_get_visitor_id(&mdfx_data->visitors, VISITOR_GRAPHIC_HDM);
			strcpy_s(event.desc.event_name, sizeof(event.desc.event_name), "debugger_event");
			(void)memset_s(&event.desc.relevant_visitor_actions, sizeof(event.desc.relevant_visitor_actions),
					 0, sizeof(event.desc.relevant_visitor_actions));
			event.desc.current_visitor_actions = (uint64_t)-1;
			actor->ops->act(mdfx_data, &event, NULL);
		}
	}
}

static void mdfx_debugger_update_client_debugger(const char *buf, struct mdfx_pri_data *mdfx_data)
{
	struct mdfx_debugger_t *debugger = &mdfx_data->debugger;
	uint32_t update = 0;
	int ret;

	if (strstr(buf, MDFX_UPDATE_DEBUGGER_STR) != NULL) {
		ret = sscanf_s(buf + strlen(MDFX_UPDATE_DEBUGGER_STR), "%u", &update);
		if (ret < 0)
			mdfx_pr_err("sscanf error");
		if (update != 1) {
			mdfx_pr_info("update_client_debugger update=%u", update);
			return;
		}

		down(&debugger->debugger_sem);
		debugger->need_update_debugger = 1;
		up(&debugger->debugger_sem);

		wake_up_interruptible_all(&(debugger->debugger_wait));
		mdfx_pr_info("trigger update_client_debugger, call wake_up_interruptible_all");
	}
}

static ssize_t mdfx_debugger_store(struct device *device,
			struct device_attribute *attr, const char *buf, size_t count)
{
	struct mdfx_device_data *device_data = NULL;

	if (IS_ERR_OR_NULL(device) || IS_ERR_OR_NULL(attr) || IS_ERR_OR_NULL(buf)) {
		mdfx_pr_err("dev or attr or buf is null");
		return -1;
	}

	device_data = dev_get_drvdata(device);
	if (IS_ERR_OR_NULL(device_data)) {
		mdfx_pr_err("device data is null");
		return -1;
	}

	mdfx_pr_info("debugger store %s", buf);
	mdfx_pr_info("g_mdfx_log_level: %d", g_mdfx_log_level);

	mdfx_debugger_update_file_count(buf, &device_data->data);
	mdfx_debugger_update_caps(buf);
	mdfx_debugger_trigger_actor(buf, &device_data->data);
	mdfx_debugger_update_client_debugger(buf, &device_data->data);

	return count;
}

static DEVICE_ATTR(debug, 0640, mdfx_debugger_show, mdfx_debugger_store);

static ssize_t mdfx_show_debugger(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct mdfx_device_data *device_data = NULL;
	struct mdfx_debugger_t *debugger = NULL;
	int32_t ret;
	ssize_t len = 0;

	mdfx_pr_info("enter!");

	if (IS_ERR_OR_NULL(dev) || IS_ERR_OR_NULL(attr) || IS_ERR_OR_NULL(buf)) {
		mdfx_pr_err("dev or attr or buf is null");
		return -1;
	}
	device_data = dev_get_drvdata(dev);
	if (IS_ERR_OR_NULL(device_data)) {
		mdfx_pr_err("device data is null");
		return -1;
	}

	debugger = &device_data->data.debugger;

	mdfx_pr_info("start wait update=%u!", debugger->need_update_debugger);
	ret = wait_event_interruptible(debugger->debugger_wait, (debugger->need_update_debugger == 1)); //lint !e578
	if (debugger->need_update_debugger) {
		down(&debugger->debugger_sem);
		len = scnprintf(buf, PAGE_SIZE - 1, "update_debugger=1");
		debugger->need_update_debugger = 0;
		up(&debugger->debugger_sem);
	}
	mdfx_pr_info("debugger update! len=%ld, ret=%d, update=%u", len, ret, debugger->need_update_debugger);
	return len;
}

static DEVICE_ATTR(update_debugger, S_IRUSR | S_IRGRP | S_IROTH, mdfx_show_debugger, NULL);

void mdfx_debugger_init(struct mdfx_pri_data *mdfx_data)
{
	struct mdfx_debugger_t *debugger = &mdfx_data->debugger;

	sema_init(&debugger->debugger_sem, 1);
	init_waitqueue_head(&debugger->debugger_wait);
	debugger->need_update_debugger = 0;

	mdfx_sysfs_append_attrs(mdfx_data, &dev_attr_report_default_event.attr);
	mdfx_sysfs_append_attrs(mdfx_data, &dev_attr_debug.attr);
	mdfx_sysfs_append_attrs(mdfx_data, &dev_attr_update_debugger.attr);
}
