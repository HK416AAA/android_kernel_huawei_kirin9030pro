/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * phase.h
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

#undef TRACE_SYSTEM
#define TRACE_SYSTEM phase

#if !defined(_TRACE_PHASE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_PHASE_H

#include <platform_include/cee/linux/phase.h>
#include <linux/perf_event.h>
#include <linux/tracepoint.h>
#include <securec.h>

TRACE_EVENT(phase_calc_task_pmu_delta,

	TP_PROTO(struct task_struct *p, int event_id,
		 u64 prev, u64 curr, u64 delta),

	TP_ARGS(p, event_id, prev, curr, delta),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	int,	event_id		)
		__field(	u64,	prev			)
		__field(	u64,	curr			)
		__field(	u64,	delta			)
	),

	TP_fast_assign(
		memcpy_s(__entry->comm, TASK_COMM_LEN, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->event_id	= event_id;
		__entry->prev		= prev;
		__entry->curr		= curr;
		__entry->delta		= delta;
	),

	TP_printk("comm=%s pid=%d pmu_event_id=%#x "
		  "prev=%llu curr=%llu delta=%llu",
		   __entry->comm, __entry->pid, __entry->event_id,
		   __entry->prev, __entry->curr, __entry->delta)
);

TRACE_EVENT(phase_sched_time,

	TP_PROTO(struct task_struct *p, enum smt_mode mode, u64 sched_exec,
		 u64 sched_latency, u64 delta_exec),

	TP_ARGS(p, mode, sched_exec, sched_latency, delta_exec),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	enum smt_mode,	mode		)
		__field(	u64,	sched_exec		)
		__field(	u64,	sched_latency		)
		__field(	u64,	delta_exec		)
		__field(	u64,	load_avg		)
	),

	TP_fast_assign(
		memcpy_s(__entry->comm, TASK_COMM_LEN, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->mode		= mode;
		__entry->sched_exec	= sched_exec;
		__entry->sched_latency	= sched_latency;
		__entry->delta_exec	= delta_exec;
		__entry->load_avg	= p->se.avg.load_avg;
	),

	TP_printk("comm=%s pid=%d mode=%d sched_exec=%llu sched_latency=%llu "
		  "delta_exec=%llu load=%llu",
		   __entry->comm, __entry->pid, __entry->mode, __entry->sched_exec,
		   __entry->sched_latency, __entry->delta_exec, __entry->load_avg)
);

TRACE_EVENT(phase_tick_delta,

	TP_PROTO(unsigned long flags, struct task_struct *p, u64 delta_exec, u64 total_inst,
		 int *pevents, u64 *counters, int num),

	TP_ARGS(flags, p, delta_exec, total_inst, pevents, counters, num),

	TP_STRUCT__entry(
		__field(	unsigned long,	flags				)
		__array(	char,		comm,		TASK_COMM_LEN	)
		__field(	pid_t,		pid				)
		__field(	u64,		delta_exec			)
		__field(	u64,		total_inst			)
		__field(	int,		num				)
		__dynamic_array(u32,		pevents,	num		)
		__dynamic_array(u64,		counters,	num		)
	),

	TP_fast_assign(
		__entry->flags		= flags;
		memcpy_s(__entry->comm, TASK_COMM_LEN, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->delta_exec	= delta_exec;
		__entry->total_inst	= total_inst;
		__entry->num		= num;
		memcpy_s(__get_dynamic_array(pevents), num * sizeof(*pevents),
			 pevents, num * sizeof(*pevents));
		memcpy_s(__get_dynamic_array(counters), num * sizeof(*counters),
			 counters, num * sizeof(*counters));
	),

	TP_printk("pmu_delta[%lu]: comm=%s pid=%d delta_exec=%llu total_inst=%llu "
		  "event_ids=%s deltas=%s\n",
		   __entry->flags, __entry->comm, __entry->pid,
		   __entry->delta_exec, __entry->total_inst,
		   __print_array(__get_dynamic_array(pevents), __entry->num, 4),
		   __print_array(__get_dynamic_array(counters), __entry->num, 8))
);

TRACE_EVENT(phase_task_delta,

	TP_PROTO(struct task_struct *p, u64 delta_exec,
		 int *pevents, char *counters, int num),

	TP_ARGS(p, delta_exec, pevents, counters, num),

	TP_STRUCT__entry(
		__array(	char,		comm,		TASK_COMM_LEN	)
		__field(	pid_t,		pid				)
		__field(	u64,		delta_exec			)
		__field(	int,		num				)
		__dynamic_array(u32,		pevents,	num		)
		__array(	char,		counters,	TASK_PHASE_LEN	)
	),

	TP_fast_assign(
		memcpy_s(__entry->comm, TASK_COMM_LEN, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->delta_exec	= delta_exec;
		__entry->num		= num;
		memcpy_s(__get_dynamic_array(pevents), num * sizeof(*pevents),
			 pevents, num * sizeof(*pevents));
		memcpy_s(__entry->counters, TASK_PHASE_LEN, counters, TASK_PHASE_LEN);
	),

	TP_printk("comm=%s pid=%d delta_exec=%llu event_ids=%s deltas={%s}\n",
		   __entry->comm, __entry->pid, __entry->delta_exec,
		   __print_array(__get_dynamic_array(pevents), __entry->num, 4),
		   __entry->counters)
);

#endif /* _TRACE_PHASE_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
