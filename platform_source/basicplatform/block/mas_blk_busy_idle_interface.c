/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 * Description: mas block busy idle interface
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

#include "mas_blk_busy_idle_interface.h"
#include "mas_blk_busy_idle_notify.h"

void __cfi_mas_blk_busyidle_handler_latency_check_timer_expire(
	struct timer_list *timer)
{
	mas_blk_busyidle_handler_latency_check_timer_expire(timer);
}

static int __cfi_mas_blk_busyidle_notify_handler(
	struct notifier_block *nb, unsigned long val, void *v)
{
	return mas_blk_busyidle_notify_handler(nb, val, v);
}

void __cfi_mas_blk_busyidle_notify_nb_init(struct blk_busyidle_nb *nb)
{
	timer_setup(&nb->handler_dur_check_timer,
	__cfi_mas_blk_busyidle_handler_latency_check_timer_expire, 0);
	nb->busyidle_nb.notifier_call = __cfi_mas_blk_busyidle_notify_handler;
}

static void __cfi_mas_blk_idle_notify_work(struct work_struct *work)
{
	mas_blk_idle_notify_work(work);
}

void __cfi_mas_blk_idle_notify_delayed_work_init(struct blk_idle_state *blk_idle)
{
	INIT_DELAYED_WORK(
		&blk_idle->idle_notify_worker, __cfi_mas_blk_idle_notify_work);
}

static void __cfi_mas_blk_busyidle_end_rq(struct request *rq, blk_status_t error)
{
	mas_blk_busyidle_end_rq(rq, error);
}

void __cfi_mas_blk_busyidle_end_io_func_init(struct request *rq)
{
	rq->end_io = __cfi_mas_blk_busyidle_end_rq;
}

#ifdef CONFIG_MAS_DEBUG_FS
ssize_t __cfi_mas_queue_busyidle_enable_store(
	struct request_queue *q, const char *page, size_t count)
{
	return mas_queue_busyidle_enable_store(q, page, count);
}

ssize_t __cfi_mas_queue_busyidle_statistic_reset_store(
	struct request_queue *q, const char *page, size_t count)
{
	return mas_queue_busyidle_statistic_reset_store(q, page, count);
}

ssize_t __cfi_mas_queue_busyidle_statistic_show(
	struct request_queue *q, char *page)
{
	return mas_queue_busyidle_statistic_show(q, page, PAGE_SIZE);
}

ssize_t __cfi_mas_queue_hw_idle_enable_show(
	struct request_queue *q, char *page)
{
	return mas_queue_hw_idle_enable_show(q, page, PAGE_SIZE);
}

ssize_t __cfi_mas_queue_idle_state_show(struct request_queue *q, char *page)
{
	return mas_queue_idle_state_show(q, page, PAGE_SIZE);
}
#endif /* CONFIG_MAS_DEBUG_FS */

