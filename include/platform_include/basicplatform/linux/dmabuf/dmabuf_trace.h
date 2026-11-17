/*
 * dmabuf_trace.h
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: Implement of dmabuf trace.
 * Create: 2025-05-14
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

#ifndef _DMABUF_TRACE_H
#define _DMABUF_TRACE_H

#undef TRACE_SYSTEM
#define TRACE_SYSTEM dmabuf

#if !defined(DMABUF_TRACE_H)
#define DMABUF_TRACE_H

#include <linux/types.h>
#include <linux/tracepoint.h>

TRACE_EVENT(tracing_mark_write,
	TP_PROTO(int pid, const char *name, bool trace_begin),
	TP_ARGS(pid, name, trace_begin),
	TP_STRUCT__entry(
		__field(int, pid)
		__string(trace_name, name)
		__field(bool, trace_begin)
	),
	TP_fast_assign(
		__entry->pid = pid;
		__assign_str(trace_name, name);
		__entry->trace_begin = trace_begin;
	),
	TP_printk("%s|%d|%s", __entry->trace_begin ? "B" : "E",
		__entry->pid, __get_str(trace_name))
)

void dmabuf_systrace_begin(const char *fmt, ...);
void dmabuf_systrace_end(void);

#endif

/* This part must be outside protection */
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH DMABUF_TRACE_INCLUDE_PATH

#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE dmabuf_trace

#include <trace/define_trace.h>

#endif /* _DMABUF_TRACE_H */