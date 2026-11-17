/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <securec.h>
#include <linux/delay.h>

#include "hvgr_mmu_api.h"
#include "hvgr_cq_defs.h"
#include "hvgr_cq_schedule.h"
#include "hvgr_log_api.h"
#include "hvgr_kmd_defs.h"
#include "hvgr_pm_api.h"
#include "hvgr_cq_queue.h"
#include "hvgr_regmap_cq.h"
#include "hvgr_protect_mode.h"

#include "hvgr_ffts_api.h"
#include "hvgr_issueq_sched.h"
#include "hvgr_lock.h"

/* 10s */
#define ISSUEQ_WAIT_UNBIND_TIME			(10 * HZ)
#define ISSUEQ_UNBIND_TIMER				3

/* 2.5s 0x2600000 0x30000000U */
#define ISSUEQ_TASK_RUN_TIMEOUT			0x2600000
/* 2.5s 0x2600000 0x30000000U */
#define ISSUEQ_EMPTY_TIMEOUT			0x2600000

#define ISSUEQ_IRQ_MASK					0xFFFFFFFFU

#define ISSUEQ_CMD_BIND					1
#define ISSUEQ_CMD_UNBIND				2
#define ISSUEQ_CMD_FAULT_UNBIND			4

static void hvgr_issueq_bind_physical(struct hvgr_device * const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;

	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_BIND_ADDR_HI),
		(ffts->sw_area->gva >> 32));
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_BIND_ADDR_LO),
		(ffts->sw_area->gva & 0xFFFFFFFFU));
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_IRQ_MASK),
		ISSUEQ_IRQ_MASK);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_BIND_TASK_TIMEOUT),
		ISSUEQ_TASK_RUN_TIMEOUT);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_BIND_EMPTY_TIMEOUT),
		ISSUEQ_EMPTY_TIMEOUT);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_BIND_CMD), ISSUEQ_CMD_BIND);

	q->sch_state = ISSUEQ_SCH_RUNNING;
}

static void hvgr_issueq_unbind_timer_cb(struct timer_list *timer)
{
	struct hvgr_device *gdev = NULL;
	struct hvgr_cq_dev *gcqctx = NULL;
	struct hvgr_ffts_dev *ffts = NULL;
	struct hvgr_issueq_queue *q = NULL;

	q = container_of(timer, struct hvgr_issueq_queue, unbind_timer);
	ffts = container_of(q, struct hvgr_ffts_dev, queue);
	gdev = container_of(ffts, struct hvgr_device, ffts_dev);
	gcqctx = &gdev->cq_dev;

	hvgr_err(gdev, HVGR_FFTS, "unbind timer callback, need reset gpu");
	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	q->sch_state = ISSUEQ_SCH_STOPPING_ERROR;
	hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
}

/* under schedule lock
 * here we map all ctx to gpu
 */
static bool hvgr_issueq_bind(struct hvgr_device * const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;

	if (!q->power_en) {
		hvgr_err(gdev, HVGR_FFTS, "issueq is not poewr on, can't bind");
		return false;
	}

	/* to make sure bind to gpu, and go empty irq proc */
	if (ffts->ref_cnt == 0)
		hvgr_debug(gdev, HVGR_FFTS, "no issueq ctx, idle to bind");

	if (q->sch_state != ISSUEQ_SCH_IDLE) {
		hvgr_err(gdev, HVGR_FFTS, "sch_state is %d, can't bind",
			q->sch_state);
		return false;
	}

	hvgr_issueq_map_all_ctx(gdev);
	hvgr_issueq_bind_physical(gdev);

	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
	return true;
}

/* only one issueq, so we can directly request or release pm */
static void hvgr_issueq_request_power(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	flush_workqueue(q->workq);

	if (q->power_en)
		return;

	(void)hvgr_pm_request_gpu(gdev, false);
	q->power_en = true;
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

static void hvgr_issueq_release_power(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	if (!q->power_en)
		return;

	hvgr_pm_release_gpu(gdev);
	q->power_en = false;
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

static void hvgr_issueq_set_submit_state(struct hvgr_issueq_queue *q,
	enum hvgr_issueq_submit_state s)
{
	/* submit state can changed to pending, only under
	 * 1. inner unsubmit and curent state is ready
	 * 2. outer submit and submit_allow is false
	 */
	q->submit_state = s;
}

static void hvgr_issueq_unbind(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_BIND_CMD),
		ISSUEQ_CMD_UNBIND);
	q->sch_state = ISSUEQ_SCH_STOPPING;
	(void)mod_timer(&q->unbind_timer, jiffies + (uint32_t)ISSUEQ_UNBIND_TIMER * HZ);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

static void hvgr_issueq_fault_unbind(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	del_timer(&q->unbind_timer);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_BIND_CMD),
		ISSUEQ_CMD_FAULT_UNBIND);
	q->sch_state = ISSUEQ_SCH_FAULT_STOPPING;
	hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_ERROR);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

static void hvgr_issueq_protect_mode_proc(struct hvgr_device *const gdev)
{
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	if (!gcqctx->protect_mode_info.protected_mode_transition)
		return;

	if (gcqctx->gpu_normalq_sch_sts != HVGR_GPU_IDLE)
		return;

	/* deal with protect mode when only issueq in gpu.
	 * power status will be hold by normalq
	 */

	hvgr_info(gdev, HVGR_FFTS, "%s enter protect mode", __func__);
	gcqctx->protect_mode_info.protected_state.enter =
		HVGR_CQ_ENTER_PROTECTED_CONFIG;
	hvgr_cq_protect_mode_check_stopped(NULL, gdev, 0);
}

static void hvgr_issueq_unbind_wq(struct work_struct *data)
{
	struct hvgr_device *gdev = NULL;
	struct hvgr_issueq_queue *q = NULL;
	struct hvgr_ffts_dev *ffts = NULL;

	q = container_of(data, struct hvgr_issueq_queue, worker);
	ffts = container_of(q, struct hvgr_ffts_dev, queue);
	gdev = container_of(ffts, struct hvgr_device, ffts_dev);

	hvgr_info(gdev, HVGR_FFTS, "%s enter", __func__);
	hvgr_issueq_release_power(gdev);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

void hvgr_issueq_fault_clean(struct hvgr_device *const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;

	(void)memset_s(ffts->hw_ctx, ffts->hw_area->pages << PAGE_SHIFT, 0, ffts->hw_area->pages << PAGE_SHIFT);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

static void hvgr_issueq_idle_wakeup(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	wake_up(&q->unbind_wait);

	if (hvgr_cq_sched_is_idle(gdev))
		wake_up(&gcqctx->stop_queue_done_wait);
}

static void hvgr_issueq_stopped_proc(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	if (q->is_need_resume) {
		hvgr_info(gdev, HVGR_FFTS, "%s resume", __func__);
		q->is_need_resume = false;
		hvgr_issueq_bind_physical(gdev);
		hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_READY);
		return;
	}

	hvgr_issueq_unmap_all_ctx(gdev);
	if (q->sch_state == ISSUEQ_SCH_FAULT_STOPPING)
		hvgr_issueq_fault_clean(gdev);

	q->sch_state = ISSUEQ_SCH_IDLE;
	hvgr_issueq_idle_wakeup(gdev);

	/* pending state hold */
	if (q->submit_state != ISSUEQ_SUBMIT_PENDING)
		hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_IDLE);

	hvgr_issueq_protect_mode_proc(gdev);
	(void)queue_work(q->workq, &q->worker);

	hvgr_info(gdev, HVGR_FFTS, "%s ok %d %d", __func__,
		q->submit_state, q->sch_state);
}

static void hvgr_issueq_stopping_proc(struct hvgr_device * const gdev,
	union reg_cq_issueq_stop_done val)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	del_timer(&q->unbind_timer);
	q->is_need_resume = (val.st.issueq_task_active == 1);
	hvgr_issueq_stopped_proc(gdev);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

static void hvgr_issueq_fault_stopping_proc(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	del_timer(&q->unbind_timer);
	hvgr_issueq_stopped_proc(gdev);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

bool hvgr_issueq_is_idle(struct hvgr_device *const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	return (q->sch_state == ISSUEQ_SCH_IDLE);
}

static void hvgr_issueq_idle_submit_proc(struct hvgr_device *const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	hvgr_issueq_request_power(gdev);

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	if (!gcqctx->submit_allow) {
		hvgr_info(gdev, HVGR_FFTS, "%s sch close", __func__);
		hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_PENDING);
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		hvgr_issueq_release_power(gdev);
		return;
	}

	(void)hvgr_issueq_bind(gdev);
	hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_READY);
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

void hvgr_issueq_submit(void)
{
	struct hvgr_device *gdev = hvgr_get_device();
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	mutex_lock(&ffts->lock);

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	if (ffts->ref_cnt == 0) {
		hvgr_err(gdev, HVGR_FFTS, "no issueq ctx, can't bind");
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		goto out;
	}

	/* not idle, maybe in such case, no need submit
	 * 1. gpu resetting
	 * 2. under protect
	 * 3. cq suspend
	 */
	if (q->submit_state != ISSUEQ_SUBMIT_IDLE) {
		hvgr_info(gdev, HVGR_FFTS, "%s not idle wait for done", __func__);
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		goto out;
	}

	if (!gcqctx->submit_allow) {
		hvgr_info(gdev, HVGR_FFTS, "%s sch close", __func__);
		hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_PENDING);
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		goto out;
	}

	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
	hvgr_issueq_idle_submit_proc(gdev);
	hvgr_info(gdev, HVGR_FFTS, "%s submit ok", __func__);

out:
	mutex_unlock(&ffts->lock);
}

void hvgr_issueq_unsubmit(void)
{
	struct hvgr_device *gdev = hvgr_get_device();

	hvgr_info(gdev, HVGR_FFTS, "%s unsubmit ok", __func__);
}

/* issueq scheduler out proc of inner call.
 * only can deal with such case
 * 1. running, need to unbind
 * 2. stopping_err, need to fault unbind
 * CASE STOPPING_ERROR be set when
 * 1. unbind timeout
 * 2. gpu immediatelt reset or normal reset enter job_done case
 */
static void hvgr_issueq_sch_out(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	hvgr_info(gdev, HVGR_FFTS, "%s enter %d %d", __func__,
		q->submit_state, q->sch_state);
	switch (q->sch_state) {
	case ISSUEQ_SCH_IDLE:
		hvgr_info(gdev, HVGR_FFTS, "%s is idle no need out", __func__);
		break;
	case ISSUEQ_SCH_RUNNING:
		hvgr_issueq_unbind(gdev);
		break;
	case ISSUEQ_SCH_STOPPING:
		hvgr_info(gdev, HVGR_FFTS, "%s is stopping", __func__);
		break;
	case ISSUEQ_SCH_STOPPING_ERROR:
		hvgr_issueq_fault_unbind(gdev);
		break;
	case ISSUEQ_SCH_FAULT_STOPPING:
		hvgr_info(gdev, HVGR_FFTS, "%s is fault stopping", __func__);
		break;
	default:
		hvgr_info(gdev, HVGR_FFTS, "%s invalid state", __func__);
		break;
	}
}

/* issueq scheduler out proc of irq.
 * can deal with all sch state.
 */
static void hvgr_issueq_sch_out_irq(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;
	union reg_cq_issueq_stop_done stop_info;

	hvgr_info(gdev, HVGR_FFTS, "%s enter %d %d", __func__,
		q->submit_state, q->sch_state);
	switch (q->sch_state) {
	case ISSUEQ_SCH_IDLE:
		hvgr_info(gdev, HVGR_FFTS, "%s is idle no need out", __func__);
		break;
	case ISSUEQ_SCH_RUNNING:
		hvgr_issueq_unbind(gdev);
		break;
	case ISSUEQ_SCH_STOPPING:
		stop_info.value = hvgr_read_reg(gdev,
			cq_control_reg(gdev, CQ_ISSUEQ_BIND_STOP_DONE_IRQ_INFO));
		hvgr_issueq_stopping_proc(gdev, stop_info);
		break;
	case ISSUEQ_SCH_STOPPING_ERROR:
		hvgr_issueq_fault_unbind(gdev);
		break;
	case ISSUEQ_SCH_FAULT_STOPPING:
		hvgr_issueq_fault_stopping_proc(gdev);
		break;
	default:
		hvgr_info(gdev, HVGR_FFTS, "%s invalid state", __func__);
		break;
	}
}

/* issueq scheduler out proc of deep.
 * only can deal with idle and running state.
 */
static void hvgr_issueq_sch_out_deep(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	hvgr_info(gdev, HVGR_FFTS, "%s enter %d %d", __func__,
		q->submit_state, q->sch_state);
	switch (q->sch_state) {
	case ISSUEQ_SCH_IDLE:
		hvgr_info(gdev, HVGR_FFTS, "%s is idle no need out", __func__);
		break;
	case ISSUEQ_SCH_RUNNING:
		hvgr_issueq_unbind(gdev);
		break;
	default:
		hvgr_info(gdev, HVGR_FFTS, "%s invalid state", __func__);
		break;
	}
}

/* issueq scheduler in inner proc.
 * only can deal with sch state idle.
 */
static void hvgr_issueq_sch_in(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	hvgr_info(gdev, HVGR_FFTS, "%s enter %d %d", __func__,
		q->submit_state, q->sch_state);
	switch (q->sch_state) {
	case ISSUEQ_SCH_IDLE:
		hvgr_issueq_bind(gdev);
		break;
	case ISSUEQ_SCH_RUNNING:
		hvgr_info(gdev, HVGR_FFTS, "%s is idle no need in", __func__);
		break;
	case ISSUEQ_SCH_STOPPING:
		hvgr_err(gdev, HVGR_FFTS, "%s is stopping", __func__);
		break;
	case ISSUEQ_SCH_STOPPING_ERROR:
		hvgr_err(gdev, HVGR_FFTS, "%s is stopping err", __func__);
		break;
	case ISSUEQ_SCH_FAULT_STOPPING:
		hvgr_info(gdev, HVGR_FFTS, "%s is fault stopping", __func__);
		break;
	default:
		hvgr_info(gdev, HVGR_FFTS, "%s invalid state", __func__);
		break;
	}
}

/* inner unsubmit process.
 * deal with such case
 * 1. if ready, change to pending, wait for resume.
 *  1.1 normal reset enter. isuueq will be resume after reset done.
 *  1.2 deep unsubmit unbind timeout and call gpu reset. submit state will change to idle.
 * 2. if pending.
 *  2.1 normal reset, unbind timeout. submit state will change to idle.
 *  2.2 immedatelty reset, force to do fault unbind. submit state will change to idle.
 */
void hvgr_issueq_unsubmit_inner_proc_nolock(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	del_timer(&q->unbind_timer);
	hvgr_info(gdev, HVGR_FFTS, "%s enter %d %d", __func__,
		q->submit_state, q->sch_state);
	switch (q->submit_state) {
	case ISSUEQ_SUBMIT_IDLE:
		hvgr_info(gdev, HVGR_FFTS, "%s idel", __func__);
		break;
	case ISSUEQ_SUBMIT_READY:
		hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_PENDING);
		hvgr_issueq_sch_out(gdev);
		break;
	case ISSUEQ_SUBMIT_PENDING:
		hvgr_issueq_sch_out(gdev);
		hvgr_info(gdev, HVGR_FFTS, "%s pending proc ok", __func__);
		break;
	default:
		hvgr_info(gdev, HVGR_FFTS, "%s invalid state", __func__);
		break;
	}
}

void hvgr_issueq_unsubmit_inner_proc(struct hvgr_device * const gdev)
{
	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	hvgr_issueq_unsubmit_inner_proc_nolock(gdev);
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
}

/* deep unsubmit
 * submit state is always ready until sched out idle.
 */
static void hvgr_issueq_unsubmit_deep(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	hvgr_info(gdev, HVGR_FFTS, "%s enter %d %d", __func__,
		q->submit_state, q->sch_state);
	switch (q->submit_state) {
	case ISSUEQ_SUBMIT_IDLE:
		hvgr_info(gdev, HVGR_FFTS, "%s idel", __func__);
		break;
	case ISSUEQ_SUBMIT_READY:
		hvgr_issueq_sch_out_deep(gdev);
		break;
	case ISSUEQ_SUBMIT_PENDING:
		hvgr_issueq_sch_out_deep(gdev);
		hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_IDLE);
		hvgr_info(gdev, HVGR_FFTS, "%s pending proc ok", __func__);
		break;
	default:
		hvgr_info(gdev, HVGR_FFTS, "%s invalid state", __func__);
		break;
	}
}

/* here to make sure issueq idle,
 * 1. for normal reset, if unbind timeout, this will be called before timer cb.
 * 2. for immediately reset, this will be called immediately after unbind.
 * 3. unbind timer cb call gpu reset, here sched state should be idle.
 */
void hvgr_issueq_reset_job_done_proc(struct hvgr_device * const gdev)
{
	int ret;
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	/* force to do fault unbind */
	if (q->sch_state == ISSUEQ_SCH_STOPPING) {
		hvgr_err(gdev, HVGR_FFTS, "%s stop failed need to fault stop", __func__);
		q->sch_state = ISSUEQ_SCH_STOPPING_ERROR;
	}
	hvgr_issueq_unsubmit_inner_proc_nolock(gdev);
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);

	ret = (int)wait_event_timeout(q->unbind_wait,
		hvgr_issueq_is_idle(gdev), ISSUEQ_WAIT_UNBIND_TIME);
	if (ret == 0)
		hvgr_err(gdev, HVGR_FFTS, "%s unbind wait timeout", __func__);

	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

/* inner call issueq submit,
 * check submit stats, only when pending can submit
 */
static bool hvgr_issueq_submit_inner_proc_nolock(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	if (!gcqctx->submit_allow) {
		hvgr_info(gdev, HVGR_FFTS, "%s sch close", __func__);
		return false;
	}

	hvgr_info(gdev, HVGR_FFTS, "%s enter %d %d", __func__,
		q->submit_state, q->sch_state);
	switch (q->submit_state) {
	case ISSUEQ_SUBMIT_IDLE:
		hvgr_info(gdev, HVGR_FFTS, "%s idel cannot submit", __func__);
		break;
	case ISSUEQ_SUBMIT_READY:
		hvgr_info(gdev, HVGR_FFTS, "%s ready no need submit", __func__);
		break;
	case ISSUEQ_SUBMIT_PENDING:
		hvgr_issueq_set_submit_state(q, ISSUEQ_SUBMIT_READY);
		hvgr_issueq_sch_in(gdev);
		hvgr_info(gdev, HVGR_FFTS, "%s pending proc ok", __func__);
		break;
	default:
		hvgr_info(gdev, HVGR_FFTS, "%s invalid state", __func__);
		break;
	}

	return true;
}

void hvgr_issueq_submit_inner_proc(struct hvgr_device * const gdev)
{
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	bool ret = false;

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	if (!gcqctx->submit_allow) {
		hvgr_info(gdev, HVGR_FFTS, "%s sch close", __func__);
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		return;
	}

	/* only when pending need submit */
	if (q->submit_state != ISSUEQ_SUBMIT_PENDING) {
		hvgr_info(gdev, HVGR_FFTS, "%s no need submit %d %d", __func__,
			q->submit_state, q->sch_state);
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		return;
	}
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);

	hvgr_issueq_request_power(gdev);

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);
	ret = hvgr_issueq_submit_inner_proc_nolock(gdev);
	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
	if (!ret)
		hvgr_issueq_release_power(gdev);

	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

void hvgr_issueq_unsubmit_sync_nolock(struct hvgr_device * const gdev)
{
	int ret;
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	hvgr_issueq_unsubmit_deep(gdev);
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);

	ret = (int)wait_event_timeout(q->unbind_wait,
		hvgr_issueq_is_idle(gdev), ISSUEQ_WAIT_UNBIND_TIME);
	if (ret == 0)
		hvgr_err(gdev, HVGR_FFTS, "%s unbind wait timeout", __func__);

	hvgr_info(gdev, HVGR_FFTS, "%s ok", __func__);
}

static void hvgr_issueq_irq_boundary_proc(struct hvgr_device * const gdev)
{
	union reg_cq_issueq_status_boundary boundary = {0};

	hvgr_info(gdev, HVGR_FFTS, "%s entry_boundary irq", __func__);
	boundary.value = hvgr_read_reg(gdev,
		cq_control_reg(gdev, CQ_ISSUEQ_ENTRY_BOUNDARY_IRQ_INFO));
	hvgr_info(gdev, HVGR_FFTS, "%s entry_boundary 0x%x", __func__, boundary.value);

	while ((boundary.st.irq_info_vld == 1) && (boundary.st.task_idx != 0)) {
		boundary.value = hvgr_read_reg(gdev,
			cq_control_reg(gdev, CQ_ISSUEQ_ENTRY_BOUNDARY_IRQ_INFO));
		hvgr_info(gdev, HVGR_FFTS, "%s entry_boundary 0x%x", __func__, boundary.value);
	}
}

void hvgr_issueq_irq_proc(struct hvgr_device * const gdev)
{
	union reg_cq_issueq_irq iirq = {0};

	iirq.value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_IRQ_STATUS));
	hvgr_info(gdev, HVGR_FFTS, "issueq irq_state 0x%x", iirq.value);

	if (iirq.st.empty_timeout != 0) {
		hvgr_info(gdev, HVGR_FFTS, "%s empty_timeout irq", __func__);
		hvgr_issueq_sch_out_irq(gdev);
	}

	if (iirq.st.task_timeout != 0) {
		hvgr_err(gdev, HVGR_FFTS, "%s task_timeout irq", __func__);
		hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);
	}

	if (iirq.st.entry_boundary != 0)
		hvgr_issueq_irq_boundary_proc(gdev);

	if (iirq.st.stop != 0) {
		hvgr_info(gdev, HVGR_FFTS, "%s stop irq", __func__);
		hvgr_issueq_sch_out_irq(gdev);
	}

	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ISSUEQ_IRQ_CLEAR), iirq.value);
}

void hvgr_issueq_task_config(struct hvgr_device *gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;

	hvgr_write_reg(gdev,
		cq_control_reg(gdev, CQ_ISSUEQ_TASKQ_CONFIG), q->cq_issueq_task);
	hvgr_write_reg(gdev,
		cq_control_reg(gdev, CQ_ISSUEQ_TASK_OS_CONFIG), q->cq_issueq_task_os);
}

int hvgr_issueq_sched_init(struct hvgr_device * const gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;
	struct workqueue_struct *wq = NULL;

	/* wait should out of ffts dev lock */
	init_waitqueue_head(&q->unbind_wait);
	wq = alloc_workqueue("gpu-ffts-issueq", WQ_HIGHPRI | WQ_UNBOUND, 1);
	if (wq == NULL)
		return -ENOMEM;

	q->workq = wq;
	INIT_WORK(&q->worker, hvgr_issueq_unbind_wq);

	hvgr_timer_setup(&q->unbind_timer, hvgr_issueq_unbind_timer_cb);

	q->cq_issueq_task = 0;
	q->cq_issueq_task_os = 0;

	return 0;
}

void hvgr_issueq_sched_term(struct hvgr_device *gdev)
{
	struct hvgr_ffts_dev *ffts = &gdev->ffts_dev;
	struct hvgr_issueq_queue *q = &ffts->queue;

	if (!IS_ERR_OR_NULL(q->workq))
		destroy_workqueue(q->workq);
}
