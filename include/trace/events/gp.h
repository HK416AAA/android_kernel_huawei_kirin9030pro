/*
 * gp.h
 *
 * cpu gp trace
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
#define TRACE_SYSTEM gp
 
#if !defined(_TRACE_GP_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_GP_H
 
#include <linux/stringify.h>
#include <linux/tracepoint.h>
 
TRACE_EVENT(set_gp,
	TP_PROTO(int active, int tid, uint8_t way_mask),
	TP_ARGS(active, tid, way_mask),
	TP_STRUCT__entry(
		__field(int, active)
		__field(int, tid)
		__field(uint8_t, way_mask)
	),
	TP_fast_assign(
		__entry->active = active;
		__entry->tid = tid;
		__entry->way_mask = way_mask;
	),
	TP_printk("%c tid %d way_mask %d", __entry->active ? 'B':'E',
		__entry->tid, __entry->way_mask)
);
 
#endif /* _TRACE_GP_H */
 
/* This part must be outside protection */
#include <trace/define_trace.h>