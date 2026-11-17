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

#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/wait.h>
#include <linux/semaphore.h>
#include <linux/workqueue.h>
#include <securec.h>
#include "mdfx_saver.h"
#include "mdfx_priv.h"
#include "mdfx_utils.h"
#include "mdfx_file.h"

static int mdfx_saver_kthread(void *data)
{
	struct mdfx_saver_thread_t *saver_thread = NULL;
	if (IS_ERR_OR_NULL(data))
		return -1;

	saver_thread = (struct mdfx_saver_thread_t *)data;
	while(1) {
		wait_event(saver_thread->saver_wq, (atomic_read(&saver_thread->saver_wq_flag) == 1) || kthread_should_stop()); //lint !e666
		if (kthread_should_stop())
			break;

		// process file saving operation first, then modify flag
		// file saving operation will bring scheduling, that is not allowed to be locked by spin_lock
		saver_thread->saver_data.handle(saver_thread->saver_data.data);

		atomic_set(&saver_thread->saver_wq_flag, 0);
	}

	return 0;
}

/*
 * we need buffer queue to manager all saving request, like product and consumer model.
 */
void mdfx_saver_triggle_thread(struct mdfx_saver_thread_t *saver_thread, void *data)
{
	unsigned long flags = 0;

	spin_lock_irqsave(&(saver_thread->saver_lock), flags);

	if (atomic_read(&saver_thread->saver_wq_flag) == 1) {
		mdfx_pr_err("another saving work is doing");
		spin_unlock_irqrestore(&(saver_thread->saver_lock), flags);
		return;
	}
	saver_thread->saver_data.data = data;
	atomic_set(&saver_thread->saver_wq_flag, 1);

	spin_unlock_irqrestore(&(saver_thread->saver_lock), flags);

	wake_up(&saver_thread->saver_wq);
}

int mdfx_saver_kthread_init(struct mdfx_saver_thread_t *saver_thread, const char* thread_name,
							msg_handle_func handle, void *data)
{
	mdfx_pr_info("saver kernel thread initalizing...\n");

	init_waitqueue_head(&saver_thread->saver_wq);

	spin_lock_init(&saver_thread->saver_lock);
	atomic_set(&(saver_thread->saver_wq_flag), 0);

	saver_thread->saver_task = kthread_create(mdfx_saver_kthread, saver_thread, thread_name); //lint !e592
	if(IS_ERR_OR_NULL(saver_thread->saver_task)) {
		mdfx_pr_err("start kernel thread failed\n");
		saver_thread->saver_task = NULL;
		return -1;
	}
	saver_thread->saver_data.handle = handle;
	saver_thread->saver_data.data = data;
	wake_up_process(saver_thread->saver_task);
	return 0;
}

void mdfx_saver_thread_deinit(struct mdfx_saver_thread_t *saver_thread)
{
	if (saver_thread->saver_task) {
		kthread_stop(saver_thread->saver_task);
		saver_thread->saver_task = NULL;

		mdfx_pr_info("stop saver kernel thread\n");
	}
}

int mdfx_save_buffer_to_file(const char *postfix, const char *buf, uint32_t size)
{
	struct mdfx_time dt = {0};
	char filename[FILENAME_LEN];
	int ret;

	if (size == 0)
		return -1;

	mdfx_get_rtc_time(&dt);
	ret = scnprintf(filename, FILENAME_LEN, "%s/%.4d%.2d%.2d_%.2d%.2d%.2d.%03ld%s", DFX_DUMPER_DIR,
		dt.tm_rtc.tm_year + 1900, dt.tm_rtc.tm_mon + 1, dt.tm_rtc.tm_mday, dt.tm_rtc.tm_hour,
					dt.tm_rtc.tm_min, dt.tm_rtc.tm_sec, dt.tv.tv_nsec / 1000000, postfix);
	if (ret <= 0) {
		mdfx_pr_err("scnprintf error");
		return -1;
	}

	ret = mdfx_create_dir(DFX_DUMPER_DIR);
	if (ret) {
		mdfx_pr_err("create dir failed name=%s\n", DFX_DUMPER_DIR);
		return -1;
	}

	return mdfx_file_save(filename, buf, size);
}

