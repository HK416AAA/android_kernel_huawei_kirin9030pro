/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#include <securec.h>
#include <linux/string.h>
#include <linux/unistd.h>
#include <linux/fcntl.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/zlib.h>
#include <linux/syscalls.h>
#include <aae/soc_aae_define.h>

#include "akmd_log.h"
#include "ukmd_dacc_log_funcs.h"
#include "aae_dacc_log_read.h"

static struct ukmd_dacc_log_dump_infos g_aae_dacc_log_info;

void aae_dacc_log_read_init(char __iomem *aae_base)
{
	aae_pr_info("aae dacc log init");
	ukmd_dacc_log_read_init(aae_base, DACC_AAE_OFFSET, AAE_DACC_LOG, &g_aae_dacc_log_info);
}

void aae_dacc_log_read_deinit(void)
{
	aae_pr_info("aae dacc log deinit");
	ukmd_dacc_log_read_deinit(&g_aae_dacc_log_info);
}

static void aae_dacc_log_read(struct kthread_work *work)
{
	struct aae_manager *aae_mgr = NULL;
	aae_pr_debug("aae read log work");

	aae_mgr = container_of(work, struct aae_manager, aae_dacc_log_work);
	aae_check_and_no_retval(!aae_mgr, err, "aae_mgr is NULL");
	ukmd_read_dacc_log_to_file(&g_aae_dacc_log_info);
}

/*
* set up thread for aae dacc log read
*/
void aae_dacc_log_thread_setup(struct aae_manager *aae_mgr)
{
	aae_pr_info("aae create and wake up log thread");
	aae_check_and_no_retval(!aae_mgr, err, "aae_mgr is null!");
	kthread_init_worker(&aae_mgr->aae_dacc_log_worker);
	kthread_init_work(&aae_mgr->aae_dacc_log_work, aae_dacc_log_read);
	aae_mgr->aae_dacc_log_thread = kthread_create(kthread_worker_fn, &aae_mgr->aae_dacc_log_worker, "aae log thread");
	if (IS_ERR_OR_NULL(aae_mgr->aae_dacc_log_thread)) {
		aae_pr_err("failed to create aae dacc log thread!");
		aae_mgr->aae_dacc_log_thread = NULL;
		return;
	}
	wake_up_process(aae_mgr->aae_dacc_log_thread);
}

/*
* relseae thread for aae dacc log read
*/
void aae_dacc_log_thread_release(struct aae_manager *aae_mgr)
{
	aae_pr_info("aae release log thread");
	aae_check_and_no_retval(!aae_mgr, err, "aae_mgr is null!");
	if (IS_ERR_OR_NULL(aae_mgr->aae_dacc_log_thread))
		return;
	kthread_stop(aae_mgr->aae_dacc_log_thread);
	aae_mgr->aae_dacc_log_thread = NULL;
}

void aae_dacc_log_isr_handler(struct aae_manager *aae_mgr)
{
	aae_pr_debug("aae dacc log isr");
	aae_check_and_no_retval(!aae_mgr, err, "aae_mgr is NULL");
	kthread_queue_work(&aae_mgr->aae_dacc_log_worker, &aae_mgr->aae_dacc_log_work);
}

/*
* ecall dump aae dacc' reserved log, which cannot be read by 
* buf full irq
*/
uint32_t aae_dacc_dump_reserved_log(void)
{
	return ukmd_dacc_dump_reserved_log(&g_aae_dacc_log_info);
}
EXPORT_SYMBOL_GPL(aae_dacc_dump_reserved_log);

/*
*	for exception dump or ecall, dump all aae dacc' s log, 
*	poen dacc's overwrite
*/
#ifdef CONFIG_MDFX_KMD
uint32_t aae_exception_dacc_log_dump(void)
{
	return ukmd_exception_dacc_log_dump(&g_aae_dacc_log_info);
}
EXPORT_SYMBOL_GPL(aae_exception_dacc_log_dump);
#endif