/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * phase_feature_tracking.c
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/sched.h>
#include <linux/cpumask.h>
#include <linux/topology.h>
#include <linux/sched/task.h>
#include <securec.h>

#include <../kernel/sched/sched.h>
#include "phase_feature.h"
#include "../drivers/dubai/dubai_cpu_stats.h"
#include <platform_include/cee/linux/time_in_state.h>

#ifdef CONFIG_CPU_INTELLISENSE
#include "../../../../../platform_source/cee/drivers/cpu_intellisense/common.h"
#endif

#define CREATE_TRACE_POINTS
#include <trace/events/phase.h>

#define PHASE_SCALE_VALUE	1024

DECLARE_STATIC_KEY_FALSE(sched_phase);
__read_mostly unsigned int mips_task_enable;

static inline u64 phase_event_count_sub(u64 curr, u64 prev)
{
	if (prev == 0)
		return 0;
	return max_t(s64, 0, curr - prev);
}

static inline void phase_calc_delta(struct task_struct *p,
				    struct phase_event_count *prev,
				    struct phase_event_count *curr,
				    struct phase_event_count *delta)
{
	int index, event_id;
	int *pevents = phase_perf_events();

	for_each_phase_pevents(index, pevents) {
		event_id = pevents[index];
		delta->pcount.data[index] = phase_event_count_sub(curr->pcount.data[index],
								  prev->pcount.data[index]);
		trace_perf(phase_calc_task_pmu_delta, p, event_id, prev->pcount.data[index],
						curr->pcount.data[index], delta->pcount.data[index]);
	}
}

u64 phase_data_of_pevent(struct phase_event_pcount *counter, int event_id)
{
	int index;
	int *events = phase_perf_events();

	for_each_phase_pevents(index, events) {
		if (event_id == events[index])
			return counter->data[index];
	}

	return 0;
}

static inline void phase_count_split(struct phase_event_pcount *orig,
				     u64 ratio, struct phase_event_pcount *prev)
{
	int *events = phase_perf_events();
	int index;

	for_each_phase_pevents(index, events) {
		prev->data[index] = orig->data[index] * PHASE_SCALE_VALUE / ratio;
		orig->data[index] = orig->data[index] - prev->data[index];
	}
}

void phase_count_avg(struct phase_event_pcount *sum_count,
		     int num, struct phase_event_pcount *avg_count)
{
	int *events = phase_perf_events();
	int index;

	for_each_phase_pevents(index, events)
		avg_count->data[index] = sum_count->data[index] / num;
}

void phase_count_merge(struct phase_event_pcount *count,
		       struct phase_event_pcount *merge)
{
	int *events = phase_perf_events();
	int index;

	for_each_phase_pevents(index, events)
		count->data[index] += merge->data[index];
}

static inline void phase_count_assign(struct phase_event_pcount *count,
				      struct phase_event_pcount *assign)
{
	int *events = phase_perf_events();
	int index;

	for_each_phase_pevents(index, events)
		count->data[index] = assign->data[index];
}

static DEFINE_PER_CPU(struct phase_event_count, prev_phase_event_count);
static DEFINE_PER_CPU(struct phase_event_count, curr_phase_event_count);
static DEFINE_PER_CPU(struct phase_event_count, task_phase_event_count);
static DEFINE_PER_CPU(u64, phase_last_update_time);
static DEFINE_PER_CPU(u64, task_last_update_time);

static inline struct phase_event_count *phase_read_prev(int cpu)
{
	return &per_cpu(prev_phase_event_count, cpu);
}

static inline struct phase_event_count *phase_read_prev_task(int cpu)
{
	return &per_cpu(task_phase_event_count, cpu);
}

static inline struct phase_event_count *phase_read_curr(int cpu)
{
	struct phase_event_count *curr = &per_cpu(curr_phase_event_count, cpu);

#ifdef CONFIG_PHASE_PERF_AMU
	// amu events version.
	phase_perf_read_amu_events(cpu, curr->pcount.data);
#else
	// pmu events version.
	phase_perf_read_events(cpu, curr->pcount.data);
#endif

	return curr;
}

void phase_clear_count(struct phase_event_pcount *count)
{
	(void)memset_s(count, sizeof(*count), 0, sizeof(*count));
}

#ifdef CONFIG_MIPS_LOAD_TRACKING
void update_history_pcount(int cpu, struct phase_event_pcount *pcount, int nr_windows)
{
	int i;
	struct rq *rq = cpu_rq(cpu);

	for (i = NR_MIPS_WINDOW - 1; i >= nr_windows; i--)
		rq->pcount_nr_history[i] = rq->pcount_nr_history[i - nr_windows];
	for (; i >= 0; i--) {
		if(!pcount)
			phase_clear_count(&rq->pcount_nr_history[i]);
		else
			phase_count_assign(&rq->pcount_nr_history[i], pcount);
	}
}
#endif

void clear_cpu_phase_count(int cpu)
{
	struct phase_event_count *curr = &per_cpu(curr_phase_event_count, cpu);
	struct phase_event_count *prev = &per_cpu(prev_phase_event_count, cpu);

	phase_clear_count(&curr->pcount);
	phase_clear_count(&prev->pcount);
}

#ifdef CONFIG_PHASE_TASK_PERF
void clear_task_phase_count(struct task_struct *p)
{
	if (!p || !p->phase_info)
		return;
	phase_clear_count(&p->phase_info->prev.pcount);
	phase_clear_count(&p->phase_info->curr.pcount);
}
#endif

static inline void phase_clear_count_window(phase_counter_window *window)
{
	phase_clear_count(phase_active_counter(window));
}

static inline void phase_save_count_window(struct phase_info *info,
					   struct phase_event_pcount *delta,
					   u64 delta_exec, enum smt_mode smt)
{
	struct phase_event_pcount *counter = phase_active_counter(&info->window);

	phase_count_assign(counter, delta);
}

int phase_fork(struct task_struct *p)
{
	struct phase_info *info = NULL;

	info = kzalloc(sizeof(*info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	info->new_task = true;
	info->last_mode = NR_SMT_MODE;
	phase_clear_count_window(&info->window);
#ifdef CONFIG_CPU_INTELLISENSE
	info->discard = false;
#endif

	p->phase_info = info;
	return 0;
}

void phase_free(struct task_struct *p)
{
	if (p->phase_info) {
		kfree(p->phase_info);
		p->phase_info = NULL;
	}
}

static void print_phase_tick_delta(struct task_struct *p, u64 delta_exec,
				   struct phase_event_count *delta,
				   unsigned long flags, u64 total_inst)
{
	int num;
	int *pevents = phase_perf_events();

	for_each_phase_pevents(num, pevents);

	trace_perf(phase_tick_delta, flags, p, delta_exec, total_inst,
		   pevents, delta->pcount.data, num);
}

static void print_phase_task_delta(struct task_struct *p, u64 delta_exec,
				   struct phase_event_count *delta)
{
	int ret, offset;
	int num;
	int *pevents = phase_perf_events();
	char output[TASK_PHASE_LEN] = {0};

	offset = 0;
	for_each_phase_pevents(num, pevents) {
		ret = sprintf_s(output + offset, sizeof(output) - offset,
				"%llu,", delta->pcount.data[num]);
		if (ret < 0)
			break;
		offset += ret;
	}

	trace_perf(phase_task_delta, p, delta_exec, pevents, output, num);
}

static void __phase_account_task(struct task_struct *p,
				 unsigned int cpu,
				 struct phase_event_count *delta,
				 u64 now,
				 unsigned long flags)
{
	struct phase_info *info = p->phase_info;
	u64 *phase_update_time = NULL;
	u64 *task_update_time = NULL;
	u64 delta_exec;

	if (!info || is_idle_task(p))
		return;
#ifdef CONFIG_CPU_INTELLISENSE
	do_sense(p, cpu, delta, flags);
#endif
	phase_update_time = &per_cpu(phase_last_update_time, cpu);
	task_update_time = &info->last_update_time;
	if (now < *phase_update_time)
		return;

	/*
	 *	SWITCH_OUT              OTHER_PRCOESS   SWITCH_IN               SWITCH_OUT
	 *	task_last_update_time   ......          phase_last_update_time  now
	 */
	delta_exec = now - *phase_update_time;

	/* update last phase update time */
	*task_update_time = now;
	*phase_update_time = now;

	/* ignore invalid PMU data */
	if (delta_exec == 0 || phase_data_of_pevent(&delta->pcount, CYCLES) == 0)
		return;

	info->total_inst += phase_data_of_pevent(&delta->pcount, INST_RETIRED);
#ifdef CONFIG_SOC_DFX
	if (soc_dfx_enable)
		print_phase_tick_delta(p, delta_exec, delta, flags, info->total_inst);
#endif
}

#ifdef CONFIG_MIPS_LOAD_TRACKING
static void phase_account_mips(struct task_struct *prev_task,
			       struct task_struct *next_task,
			       unsigned int cpu,
			       struct phase_event_count *delta,
			       u64 now,
			       unsigned long flags)
{
	u64 prev_inst, prev_cycle;
	struct rq *rq = cpu_rq(cpu);

	if (!is_idle_task(prev_task)) {
		prev_inst = phase_data_of_pevent(&delta->pcount, INST_RETIRED);
		prev_cycle = phase_data_of_pevent(&delta->pcount, CYCLES);
		phase_update_task_tmipsd(prev_task, cpu,  prev_inst, prev_cycle, flags);
		phase_update_rq_rmipsd(rq, &delta->pcount, flags);
	}
	update_mips_window(next_task, rq, now, flags);
}
#endif

static bool account_filter(int cpu __maybe_unused, u64 wallclock __maybe_unused,
			   unsigned long flags __maybe_unused)
{
	if (!static_branch_likely(&sched_phase))
		return true;

	if (!cpumask_test_cpu(cpu, &sysctl_phase_cpumask))
		return true;

#ifdef CONFIG_CPU_INTELLISENSE
	return false;
#endif

#ifdef CONFIG_MIPS_LOAD_TRACKING
	if (trace_phase_task_delta_enabled() || mips_task_enable || flags == PHASE_TASK_TICK ||
	    wallclock - cpu_rq(cpu)->rmipsd.mips_window_start >= mips_window_size)
		return false;
#endif
	return true;
}

static void update_task_phase(struct task_struct *p, int cpu,
			      struct phase_event_count *curr, u64 now)
{
	struct phase_event_count *prev_task = NULL;
	struct phase_event_count delta;
	u64 *task_update_time = NULL;
	u64 delta_exec;

	if (!trace_phase_task_delta_enabled())
		return;

	prev_task = phase_read_prev_task(cpu);
	phase_calc_delta(p, prev_task, curr, &delta);
	*prev_task = *curr;

	task_update_time = &per_cpu(task_last_update_time, cpu);
	delta_exec = now - *task_update_time;
	*task_update_time = now;

#ifdef CONFIG_SOC_DFX
	if (soc_dfx_enable)
		print_phase_task_delta(p, delta_exec, &delta);
#endif
}

void phase_account_task(struct task_struct *prev_task, struct task_struct *next_task,
			int cpu, u64 wallclock, unsigned long flags)
{
	struct phase_event_count delta;
	struct phase_event_count next_delta;
	struct phase_event_count *prev = NULL;
	struct phase_event_count *curr = NULL;

	if (account_filter(cpu, wallclock, flags))
		return;

	/* update phase_event_count */
	prev = phase_read_prev(cpu);
	curr = phase_read_curr(cpu);
	phase_calc_delta(prev_task, prev, curr, &delta);
	(void)memset_s(&next_delta, sizeof(next_delta), 0, sizeof(next_delta));
	*prev = *curr;

#ifdef CONFIG_MIPS_LOAD_TRACKING
	phase_account_mips(prev_task, next_task, cpu, &delta, wallclock, flags);
#endif

	dubai_add_cpu_inst(cpu, phase_data_of_pevent(&delta.pcount, INST_RETIRED));
#ifdef CONFIG_SOC_DFX
	if (soc_dfx_enable)
		update_cpu_instructions(cpu, phase_data_of_pevent(&curr->pcount, INST_RETIRED));
#endif

	/* calculate phase */
	if (prev_task == next_task) {
		__phase_account_task(prev_task, cpu, &delta, wallclock, flags);
	} else {
		__phase_account_task(prev_task, cpu, &delta, wallclock, PHASE_PREV_MODE | PHASE_TASK_SWITCH);
		__phase_account_task(next_task, cpu, &next_delta, wallclock, PHASE_RESET_MT_INFO | PHASE_TASK_SWITCH);
		update_task_phase(prev_task, cpu, curr, wallclock);
	}
}

#ifdef CONFIG_PHASE_TASK_PERF
static inline struct phase_event_count *phase_task_read_prev(struct task_struct *p)
{
	return &p->phase_info->prev;
}

static inline struct phase_event_count *phase_task_read_curr(struct task_struct *p)
{
	struct phase_event_count *curr = &p->phase_info->curr;

	phase_perf_task_read_events(p, curr->pcount.data);

	return curr;
}

void __phase_task_event(struct task_struct *p, struct phase_event_count *delta,
			unsigned long flags)
{
	struct phase_info *info = p->phase_info;
	u64 delta_exec, now;

	if (!info || !fair_policy(p->policy) || is_idle_task(p))
		return;

	now = sched_ktime_clock();
	delta_exec = now - info->last_update_time;
	info->last_update_time = now;
	info->total_inst += phase_data_of_pevent(&delta->pcount, INST_RETIRED);
#ifdef CONFIG_SOC_DFX
	if (soc_dfx_enable)
		print_phase_tick_delta(p, delta_exec, delta, flags, info->total_inst);
#endif
}

void phase_task_event(struct task_struct *p, unsigned long flags)
{
	struct phase_event_count delta;
	struct phase_event_count *prev = NULL;
	struct phase_event_count *curr = NULL;

	if (!static_branch_likely(&sched_phase))
		return;

	/* update phase_event_count */
	prev = phase_task_read_prev(p);
	curr = phase_task_read_curr(p);
	phase_calc_delta(p, prev, curr, &delta);
	*prev = *curr;
	__phase_task_event(p, &delta, flags);
}

#endif
