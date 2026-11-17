/*
 * flo.h
 *
 * cpu flo trace
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM flo

#if !defined(_TRACE_FLO_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_FLO_H

#include <linux/stringify.h>
#include <linux/tracepoint.h>

TRACE_EVENT(flo_set,
	TP_PROTO(int active, pid_t tgid, pid_t pid, unsigned long ctrl,
		unsigned long posn),
	TP_ARGS(active, tgid, pid, ctrl, posn),
	TP_STRUCT__entry(
		__field(int, active)
		__field(pid_t, tgid)
		__field(pid_t, pid)
		__field(unsigned long, ctrl)
		__field(unsigned long, posn)
	),
	TP_fast_assign(
		__entry->active = active;
		__entry->tgid = tgid;
		__entry->pid = pid;
		__entry->ctrl = ctrl;
		__entry->posn = posn;
	),
	TP_printk("%c|%d|%d|0x%lx|0x%lx", __entry->active ? 'B':'E',
			__entry->tgid, __entry->pid,
			__entry->ctrl, __entry->posn)
);

#endif /* _TRACE_FLO_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
