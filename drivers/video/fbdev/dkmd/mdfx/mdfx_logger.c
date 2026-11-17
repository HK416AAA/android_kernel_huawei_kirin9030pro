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
#include "mdfx_logger.h"
#include <linux/file.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <securec.h>
#include "mdfx_priv.h"
#include "mdfx_utils.h"
#include "mdfx_file.h"

static struct mdfx_log_buf_t* mdfx_get_using_log_buf(struct mdfx_logger_t *logger)
{
	struct mdfx_log_buf_t* log_buf = NULL;

	log_buf = &(logger->log_bufs[LOGGER_GET_BUF_INDEX(logger->using_index)]);
	if (IS_ERR_OR_NULL(log_buf->log_buf)) {
		mdfx_pr_err("log buf is null: index = %d", logger->using_index);
		return NULL;
	}

	return log_buf;
}

static void mdfx_logger_build_event_name(struct mdfx_logger_t *logger, struct mdfx_event *event)
{
	int ret;

	logger->frame_index = event->desc.frame_index;

	ret = scnprintf(logger->event_name, MDFX_EVENT_NAME_MAX, "%s", event->desc.event_name);
	if (unlikely(ret <= 0))
		logger->event_name[0] = '\0';
	
	ret = scnprintf(logger->timestamp, MDFX_EVENT_TIMESTAMP_MAX, "%s", event->timestamp);
	if (unlikely(ret <= 0))
		logger->timestamp[0] = '\0';
}

static struct file* mdfx_logger_open_file(struct mdfx_logger_t *logger)
{
	char file_postfix[FILENAME_LEN] = {0};
	int ret;
	int event_name_len;
	struct file *out_file = NULL;

	event_name_len = strlen(logger->event_name);
	if (event_name_len <= 0 || event_name_len > FILENAME_LEN)
		return NULL;

	ret = scnprintf(file_postfix, FILENAME_LEN, "_%s_log_%lld_frame_%u.txt", logger->event_name, logger->visitor_id, logger->frame_index);
	if (unlikely(ret <= 0)) {
		mdfx_pr_warn("scnprintf fail!ret=%d", ret);
		return NULL;
	}
	
	out_file = mdfx_file_create_file(DFX_LOGGER_DIR, logger->timestamp, file_postfix);
	if (IS_ERR_OR_NULL(out_file)) {
        mdfx_pr_err("create file error");
        return NULL;
	}

	return out_file;
}

static void mdfx_logger_gen_file(void *data)
{
	struct mdfx_logger_t *logger = NULL;
	struct mdfx_log_buf_t *log_buf = NULL;
	struct file *saver_file = NULL;
	mm_segment_t old_fs;
	int ret;
	uint32_t i;

	if (IS_ERR_OR_NULL(data) || IS_ERR_OR_NULL(g_mdfx_data)) {
		mdfx_pr_err("data is null");
		return;
	}

	logger = (struct mdfx_logger_t *)data;

	if (logger->dir_is_ok != true) {
		if (mdfx_create_dir(DFX_LOGGER_DIR) != 0) {
			mdfx_pr_err("create dir failed name=%s\n", DFX_LOGGER_DIR);
			return;
		}
		logger->dir_is_ok = true;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	saver_file = mdfx_logger_open_file(logger);
	if (IS_ERR_OR_NULL(saver_file)) {
		mdfx_pr_err("saver file is null");
		set_fs(old_fs);
		return;
	}

	for (i = 0; i < LOGGER_BUF_MAX_COUNT; i++) {
		log_buf = &logger->log_bufs[i];
		if (IS_ERR_OR_NULL(log_buf->log_buf))
            continue;

		ret = mdfx_file_write(saver_file, log_buf->log_buf, LOGGER_BUF_LEN);
		if (ret < 0)
			mdfx_pr_err("mdfx_file_write error");
	}

	filp_close(saver_file, NULL);
	set_fs(old_fs);

	mdfx_remove_redundant_files(DFX_LOGGER_DIR);
}

/* log format:
 * ________________________________________________________________
 * | header1 | text1 | header2 | text2 | .....next log ...        |
 * ----------------------------------------------------------------
 */
static void mdfx_logger_fill_text(char* log_buf, const char *text, uint32_t text_len,
								  const char *header_buf, uint32_t header_len)
{
	/* fill message */
	if (memcpy_s(log_buf, header_len, header_buf, header_len) != EOK)
		mdfx_pr_warn("memcpy_s fail!");
	
	if (memcpy_s(log_buf + header_len, text_len, text, text_len) != EOK)
		mdfx_pr_warn("memcpy_s fail!");
}

static int mdfx_logger_store_log(struct mdfx_logger_t *logger, const char *text, int text_len)
{
	char* log_buf = NULL;
	char header_buf[LOGGER_HEADER_MAX_LEN];
	unsigned long flags = 0;
	struct mdfx_log_buf_t *using_log_buf = mdfx_get_using_log_buf(logger);
	int header_len = mdfx_get_msg_header(header_buf, LOGGER_HEADER_MAX_LEN);
	int msg_len;

	if (unlikely((using_log_buf == NULL) || (header_len <= 0)))
		return 0;

	msg_len = header_len + text_len;
	spin_lock_irqsave(&(logger->logger_lock), flags);
	if ((using_log_buf->next_idx + msg_len) > LOGGER_BUF_LEN) {
		/* not just have one buf, get a new log buff, start from 0 */
#ifdef CONFIG_MDFX_KMD_ENG_MODE
		logger->using_index = LOGGER_GET_BUF_INDEX(logger->using_index + 1);
		using_log_buf = mdfx_get_using_log_buf(logger);
		if (unlikely(using_log_buf == NULL)) {
			spin_unlock_irqrestore(&(logger->logger_lock), flags);
			return 0;
		}
#endif
		using_log_buf->next_idx = 0;
	}

	log_buf = (char*)(using_log_buf->log_buf + using_log_buf->next_idx);
	using_log_buf->next_idx += msg_len;
	spin_unlock_irqrestore(&(logger->logger_lock), flags);

	mdfx_logger_fill_text(log_buf, text, text_len, header_buf, header_len);
	return 0;
}

int mdfx_logger_emit(int64_t visitor_id, const char *fmt, ...)
{
	char textbuf[LOGGER_EACH_TEXT_MAX_LEN];
	int text_len;
	struct mdfx_logger_t *logger = mdfx_get_visitor_logger(visitor_id);
	va_list args;
	int ret;

	if (unlikely(!logger || logger->visitor_id == 0))
		return -1;

	va_start(args, fmt);

	/*
	 * The printf needs to come first; we need the syslog
	 * prefix which might be passed-in as a parameter.
	 */
	text_len = vscnprintf(textbuf, sizeof(textbuf), fmt, args);
	if (unlikely(text_len <= 0)) {
		va_end(args);
		return 0;
	}

	ret = mdfx_logger_store_log(logger, textbuf, text_len);
	va_end(args);
	return ret;
}

void mdfx_logger_init(struct mdfx_logger_t *logger, int64_t id)
{
	struct mdfx_log_buf_t *mdfx_log_buf = NULL;
	uint32_t i;

	for (i = 0; i < LOGGER_BUF_MAX_COUNT; i++) {
		mdfx_log_buf = &logger->log_bufs[i];
		mdfx_log_buf->next_idx = 0;
		mdfx_log_buf->log_buf = kmalloc(LOGGER_BUF_LEN, GFP_KERNEL);
	}

	logger->using_index = 0;
	logger->visitor_id = id;
	logger->dir_is_ok = false;

	spin_lock_init(&logger->logger_lock);
}

void mdfx_logger_deinit(struct mdfx_logger_t *logger)
{
	struct mdfx_log_buf_t *log_buf = NULL;
	uint32_t i;

	for (i = 0; i < LOGGER_BUF_MAX_COUNT; i++) {
		log_buf = &logger->log_bufs[i];
		log_buf->next_idx = 0;

		if (log_buf->log_buf != NULL) {
			kfree(log_buf->log_buf);
			log_buf->log_buf = NULL;
		}
	}

	logger->using_index = 0;
	logger->visitor_id = INVALID_VISITOR_ID;
}

static void mdfx_logger_save_visitor_log(struct mdfx_pri_data *mdfx_data, int64_t visitor_id,
	uint64_t actions, struct mdfx_event *event)
{
	struct mdfx_logger_t *logger = NULL;

	if (unlikely(visitor_id < VISITOR_ID_MIN)) {
		mdfx_pr_info("invalid visitor id, actions = %" PRIu64, actions);
		return;
	}

	if (!IS_ENABLE_BITS_FIELD(actions, LOG_DETAIL_STORE_KMD_LOG)) {
		mdfx_pr_info("no need save kmd log, actions = %" PRIu64, actions);
		return;
	}

	logger = mdfx_get_visitor_logger(visitor_id);
	if (logger == NULL || logger->visitor_id < 0)
		return;

	mdfx_logger_build_event_name(logger, event);
	mdfx_saver_triggle_thread(&mdfx_data->actors[ACTOR_LOGGER].saving_thread, logger);

	mdfx_pr_info("triggle log_saving_thread");
}

static int mdfx_logger_act(struct mdfx_pri_data *mdfx_data, struct mdfx_event *event, void *value)
{
	uint32_t i = 0;
	int64_t visitor_id;

	mdfx_pr_info("enter mdfx_logger_act");
	if (IS_ERR_OR_NULL(mdfx_data) || IS_ERR_OR_NULL(event))
		return -1;

	if (mdfx_event_check_parameter(event))
		return -1;

	if (!MDFX_HAS_CAPABILITY(g_mdfx_caps, MDFX_CAP_LOGGER))
		return 0;

	mdfx_logger_save_visitor_log(mdfx_data, event->visitor_id, event->desc.current_visitor_actions, event);

	for (i = 0; i < VISITOR_TYPE_MAX; i++) {
		if (!IS_ENABLE_BITS_FIELD(event->desc.relevant_visitor_actions[i], LOG_DETAIL_STORE_KMD_LOG)) {
			mdfx_pr_info("visitor %u no need save kmd log, actions = %" PRIu64, i,
						 event->desc.relevant_visitor_actions[i]);
			continue;
		}

		visitor_id = mdfx_get_visitor_id(&mdfx_data->visitors, BIT64(i));
		mdfx_logger_save_visitor_log(mdfx_data, visitor_id, event->desc.relevant_visitor_actions[i], event);
	}

	return 0;
}

static struct mdfx_actor_ops_t mdfx_logger_ops = {
	.act = mdfx_logger_act,
	.do_ioctl = NULL,
};

void mdfx_logger_init_actor(struct mdfx_actor_t *actor)
{
	int32_t ret;

	actor->actor_type = ACTOR_LOGGER;
	actor->ops = &mdfx_logger_ops;

	ret = mdfx_saver_kthread_init(&actor->saving_thread, "mdfx_log_saver", mdfx_logger_gen_file, NULL);
	if (ret != 0)
		mdfx_pr_err("log saving kernel thread init failed, ret = %d\n", ret);
}
