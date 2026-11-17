/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 * Description: block busy idle interface
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MAS_BLK_BUSY_IDLE_INTERFACE_H__
#define __MAS_BLK_BUSY_IDLE_INTERFACE_H__
#include <linux/kernel.h>
#include <linux/blkdev.h>
#include <linux/types.h>
#include <linux/version.h>
#include <linux/timer.h>
#include "mas_blk_busy_idle_notify.h"

extern void __cfi_mas_blk_busyidle_handler_latency_check_timer_expire(
	struct timer_list *timer);
extern void mas_blk_busyidle_handler_latency_check_timer_expire(
	struct timer_list *timer);
extern int mas_blk_busyidle_notify_handler(
	const struct notifier_block *nb, unsigned long event, const void *v);
extern void mas_blk_idle_notify_work(const struct work_struct *work);
extern ssize_t __cfi_mas_queue_busyidle_enable_store(
	struct request_queue *q, const char *page, size_t count);
extern ssize_t __cfi_mas_queue_busyidle_statistic_reset_store(
	struct request_queue *q, const char *page, size_t count);
extern ssize_t __cfi_mas_queue_busyidle_statistic_show(
	struct request_queue *q, char *page);
extern ssize_t __cfi_mas_queue_hw_idle_enable_show(
	struct request_queue *q, char *page);
extern ssize_t __cfi_mas_queue_idle_state_show(
	struct request_queue *q, char *page);
extern void mas_blk_busyidle_end_rq(
	const struct request *rq, blk_status_t error);
void __cfi_mas_blk_busyidle_notify_nb_init(struct blk_busyidle_nb *nb);
void __cfi_mas_blk_idle_notify_delayed_work_init(struct blk_idle_state *blk_idle);
void __cfi_mas_blk_busyidle_end_io_func_init(struct request *rq);
#ifdef CONFIG_MAS_DEBUG_FS
extern ssize_t mas_queue_busyidle_enable_store(
	const struct request_queue *q, const char *page, size_t count);
extern ssize_t mas_queue_busyidle_statistic_reset_store(
	const struct request_queue *q, const char *page, size_t count);
extern ssize_t mas_queue_busyidle_statistic_show(
	const struct request_queue *q, char *page, unsigned long len);
extern ssize_t mas_queue_hw_idle_enable_show(
	const struct request_queue *q, char *page, unsigned long len);
extern ssize_t mas_queue_idle_state_show(
	const struct request_queue *q, char *page, unsigned long len);
#endif /* CONFIG_MAS_DEBUG_FS */
#endif /* __MAS_BLK_BUSY_IDLE_INTERFACE_H__ */
