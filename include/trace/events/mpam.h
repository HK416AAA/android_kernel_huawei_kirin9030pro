/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * mpam.h
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
#define TRACE_SYSTEM mpam

#if !defined(_TRACE_MPAM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MPAM_H

#include <linux/tracepoint.h>

TRACE_EVENT(mpam_policy,
	TP_PROTO(int user, int policy_type_curr, int policy_type_next),
	TP_ARGS(user, policy_type_curr, policy_type_next),
	TP_STRUCT__entry(
		__field(int, user)
		__field(int, policy_type_curr)
		__field(int, policy_type_next)
	),
	TP_fast_assign(
		__entry->user = user;
		__entry->policy_type_curr = policy_type_curr;
		__entry->policy_type_next = policy_type_next;
	),

	TP_printk("mpam user id=%d policy_type_curr=%d policy_type_next=%d",
		  __entry->user, __entry->policy_type_curr, __entry->policy_type_next)
);

#endif /* _TRACE_MPAM_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
