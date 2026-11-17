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
#include <linux/list.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <securec.h>
#include "mdfx_priv.h"
#include "mdfx_utils.h"
#include "mdfx_tracing.h"
#include "mdfx_file.h"

#define MAX_TRACING_MSG_LEN 150

static int mdfx_tracing_record_info(int64_t visitor_id, mdfx_traing_type_t tracing_type, const char *msg, int msg_len)
{
	char* buf = NULL;
	unsigned long flags = 0;
	struct mdfx_tracing_buf *tracing_buf = mdfx_visitor_get_tracing_buf(visitor_id, tracing_type);
	if (unlikely(!tracing_buf || (tracing_buf->tracing_buf_addr == NULL))) {
		mdfx_pr_err("mdfx_visitor_get_tracing_buf fail");
		return -1;
	}

	spin_lock_irqsave(&(tracing_buf->tracing_lock), flags);
	if ((tracing_buf->tracing_index + msg_len) > DEFAULT_MAX_TRACING_BUF_SIZE)
		tracing_buf->tracing_index = 0;

	buf = tracing_buf->tracing_buf_addr + tracing_buf->tracing_index;
	tracing_buf->tracing_index += msg_len;
	spin_unlock_irqrestore(&(tracing_buf->tracing_lock), flags);

	if (memcpy_s(buf, msg_len, msg, msg_len) != EOK)
		mdfx_pr_warn("memcpy_s fail!");

	return 0;
}

static struct file* mdfx_tracing_open_file(int64_t visitor_id, mdfx_traing_type_t tracing_type, struct mdfx_event *event)
{
	char postfix[FILENAME_LEN] = {0};
	int ret;
	int event_name_len;

	event_name_len = strlen(event->desc.event_name);
	if (event_name_len <= 0 || event_name_len > FILENAME_LEN)
		return NULL;

	mdfx_pr_info("enter mdfx_tracing_open_file");
	ret = scnprintf(postfix, FILENAME_LEN, "_%s_trace_%lld_frame_%u_type_%d.txt", 
		event->desc.event_name, visitor_id, event->desc.frame_index, tracing_type);
	if (unlikely(ret <= 0))
		return NULL;

	return mdfx_file_create_file(DFX_TRACING_DIR, event->timestamp, postfix);
}

static int mdfx_tracing_save_for_visitor(struct mdfx_event *event)
{
	struct mdfx_tracing_buf *tracing_buf = NULL;
	struct file *pfile = NULL;
	mm_segment_t old_fs;
	int32_t ret;
	uint32_t i;

	mdfx_pr_info("enter mdfx_tracing_save_for_visitor");
	
	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	for (i = 0; i < (uint32_t)MDFX_TRACING_TYPE_MAX; i++) {
		tracing_buf = mdfx_visitor_get_tracing_buf(event->visitor_id, i);
		if (IS_ERR_OR_NULL(tracing_buf) || tracing_buf->tracing_buf_addr == NULL)
			continue;

		pfile = mdfx_tracing_open_file(event->visitor_id, i, event);
		if (IS_ERR_OR_NULL(pfile)) {
			mdfx_pr_err("open tracing file error");
			continue;
		}

		ret = mdfx_file_write(pfile, tracing_buf->tracing_buf_addr, DEFAULT_MAX_TRACING_BUF_SIZE);
		if (ret != 0)
			mdfx_pr_err("write tracing buffer to file fail");

		filp_close(pfile, NULL);
	}

	set_fs(old_fs);
	mdfx_remove_redundant_files(DFX_TRACING_DIR);
	return 0;
}

/*
 * tracing maybe need save all visitors's tracing information of
 * the relevance types which assigned be desc.
 * dynamic allocated memory space that param data pointed, take care of releasing it.
 */
static void mdfx_tracing_save_info(void *data)
{
	struct mdfx_event *event = NULL;
	struct mdfx_tracing_ctrl *tracing_ctrl = NULL;
	uint64_t detail;

	if (IS_ERR_OR_NULL(g_mdfx_data) || IS_ERR_OR_NULL(data)) {
		mdfx_pr_err("g_mdfx_data or data is null");
		return;
	}

	tracing_ctrl = (struct mdfx_tracing_ctrl *)data;

	down(&tracing_ctrl->tracing_sem);
	event = &tracing_ctrl->tracing_event;
	detail = event->desc.current_visitor_actions & TRACING_DETAIL_MASK;

	if (event->visitor_id < VISITOR_ID_MIN) {
		up(&tracing_ctrl->tracing_sem);
		return;
	}

	if (!IS_ENABLE_BITS_FIELD(detail, TRACING_DETAIL_MASK)) {
		mdfx_pr_err("current_visitor_actions have not tracing detail");
		up(&tracing_ctrl->tracing_sem);
		return;
	}

	mdfx_pr_info("enter mdfx_tracing_save_info, detail=%llu", detail);
	mdfx_tracing_save_for_visitor(event);

	(void)memset_s(&tracing_ctrl->tracing_event, sizeof(tracing_ctrl->tracing_event),
			 0, sizeof(tracing_ctrl->tracing_event));

	up(&tracing_ctrl->tracing_sem);
}

static int mdfx_tracing_event_act(struct mdfx_pri_data *mdfx_data, struct mdfx_event *event, void *value)
{
	struct mdfx_tracing_ctrl *tracing_ctrl = NULL;

	if (IS_ERR_OR_NULL(mdfx_data) || IS_ERR_OR_NULL(event)) {
		mdfx_pr_err("mdfx_data or event is null");
		return -1;
	}

	if (!MDFX_HAS_CAPABILITY(g_mdfx_caps, MDFX_CAP_TRACING))
		return 0;

	if (!IS_ENABLE_BITS_FIELD(event->desc.current_visitor_actions, TRACING_DETAIL_MASK)) {
		mdfx_pr_err("current_visitor_actions have not tracing detail");
		return -1;
	}

	if (event->visitor_id < VISITOR_ID_MIN) {
		mdfx_pr_err("invalid visitor id");
		return -1;
	}

	mdfx_pr_info("enter mdfx_tracing_event_act");
	tracing_ctrl = (struct mdfx_tracing_ctrl *)mdfx_data->actors[ACTOR_TRACING].actor_data;
	if (tracing_ctrl == NULL) {
		mdfx_pr_err("tracing ctrl is null");
		return -1;
	}

	down(&tracing_ctrl->tracing_sem);
	if (memcpy_s(&tracing_ctrl->tracing_event, sizeof(tracing_ctrl->tracing_event), event, sizeof(*event)) != EOK)
		mdfx_pr_warn("memcpy_s fail!");

	mdfx_saver_triggle_thread(&mdfx_data->actors[ACTOR_TRACING].saving_thread, tracing_ctrl);
	mdfx_pr_info("triggle trace_saving_thread");

	up(&tracing_ctrl->tracing_sem);
	return 0;
}

static bool mdfx_tracing_valid_parameter(struct mdfx_tracing_desc *desc)
{
	if (desc->id < VISITOR_ID_MIN) {
		mdfx_pr_err("invalid id =%" PRId64, desc->id);
		return false;
	}

	if (unlikely((desc->msg_len == 0) || (desc->msg_len >= TRACING_POINT_MSG_MAX_LEN))) {
		mdfx_pr_err("invalid msg len = %u", desc->msg_len);
		return false;
	}

	desc->type_name[TRACING_TYPE_NAME_MSX_LEN - 1] = '\0';
	desc->msg[desc->msg_len] = '\0';
	return true;
}

static int mdfx_tracing_build_msg(const char *tracing_type, const char *msg, char *record_msg)
{
	int msg_len;
	int ret;

	msg_len = mdfx_get_msg_header(record_msg, MAX_TRACING_MSG_LEN);
	if (unlikely(msg_len <= 0)) {
		mdfx_pr_err("get head fail!ret=%d", msg_len);
		return -1;
	}

	ret = scnprintf(record_msg + msg_len, MAX_TRACING_MSG_LEN - msg_len, "[%s] %s\n", tracing_type, msg);
	if (unlikely(ret <= 0)) {
		mdfx_pr_err("mdfx_tracing_build_msg fail!ret=%d\n", ret);
		return -1;
	}

	msg_len += ret;
	return msg_len;
}

static int mdfx_tracing_trace_info(struct mdfx_pri_data *mdfx_data, const void __user *argp)
{
	int ret;
	struct mdfx_tracing_desc tracing_desc;

	if ((mdfx_data == NULL) || (argp == NULL)){
		mdfx_pr_err("Invalid argument\n");
		return -EINVAL;
	}

	ret = (int)copy_from_user(&tracing_desc, argp, sizeof(tracing_desc));
	if (ret) {
		mdfx_pr_err("copy_from_user failed!ret=%d!\n", ret);
		return -EFAULT;
	}

	if (!mdfx_tracing_valid_parameter(&tracing_desc)) {
		mdfx_pr_err("invalid parameter, id=%lld, msg len=%u!\n", tracing_desc.id, tracing_desc.msg_len);
		return -1;
	}

	mdfx_pr_info("enter mdfx_tracing_trace_info");
	mdfx_tracing_point(tracing_desc.id, MDFX_TRACING_TYPE_HF, tracing_desc.type_name, tracing_desc.msg);

	return 0;
}

static struct mdfx_actor_ops_t tracing_ops = {
	.act = mdfx_tracing_event_act,
	.do_ioctl = mdfx_tracing_trace_info,
};

void mdfx_tracing_init_actor(struct mdfx_actor_t *actor)
{
	struct mdfx_tracing_ctrl *tracing_ctrl = NULL;
	int32_t ret;

	actor->actor_type = ACTOR_TRACING;
	actor->ops = &tracing_ops;

	tracing_ctrl = kzalloc(sizeof(struct mdfx_tracing_ctrl), GFP_KERNEL);
	if (tracing_ctrl == NULL)
		return;

	sema_init(&tracing_ctrl->tracing_sem, 1);
	actor->actor_data = tracing_ctrl;

	ret = mdfx_saver_kthread_init(&actor->saving_thread, "mdfx_trace_saver",
								  mdfx_tracing_save_info, tracing_ctrl);
	if (ret != 0)
		mdfx_pr_err("trace saving kernel thread init failed, ret = %d\n", ret);
}

void mdfx_tracing_init(struct mdfx_tracing_buf *tracing_buf)
{
	tracing_buf->tracing_index = 0;
	if (tracing_buf->tracing_buf_addr == NULL) {
		tracing_buf->tracing_buf_addr = kmalloc(DEFAULT_MAX_TRACING_BUF_SIZE, GFP_KERNEL);
		if (tracing_buf->tracing_buf_addr == NULL)
			mdfx_pr_err("kmalloc fail");
	}

	spin_lock_init(&tracing_buf->tracing_lock);
}

void mdfx_tracing_deinit(struct mdfx_tracing_buf *tracing_buf)
{
	if (tracing_buf->tracing_buf_addr != NULL) {
		kfree(tracing_buf->tracing_buf_addr);
        tracing_buf->tracing_buf_addr = NULL;
    }
	tracing_buf->tracing_index = 0;
}

void mdfx_tracing_point(int64_t visitor_id, mdfx_traing_type_t tracing_type, const char *tracing_tag, char *msg)
{
	char record_msg[MAX_TRACING_MSG_LEN];
	int msg_len;

	if (unlikely(IS_ERR_OR_NULL(msg) || IS_ERR_OR_NULL(tracing_tag)))
		return;

	msg_len = mdfx_tracing_build_msg(tracing_tag, msg, record_msg);
	if (unlikely(msg_len <= 0)) {
		mdfx_pr_err("build msg fail");
		return;
	}

	if (mdfx_tracing_record_info(visitor_id, tracing_type, record_msg, msg_len))
		mdfx_pr_err("tracing fail, id=%lld msg=%s", visitor_id, record_msg);
}

