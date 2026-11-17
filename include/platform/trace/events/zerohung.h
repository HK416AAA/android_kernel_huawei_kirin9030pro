/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM zerohung

#if !defined(_TRACE_ZEROHUNG_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_ZEROHUNG_H

#include <linux/tracepoint.h>

TRACE_EVENT(hung_wp_screen_fake_power_off,

	TP_PROTO(int unused),

	TP_ARGS(unused),

	TP_STRUCT__entry(
	),

	TP_fast_assign(
	),

	TP_printk("hung_wp_screen_fake_power_off")
);

TRACE_EVENT(hung_wp_screen_getbl,

	TP_PROTO(int *screen_bl_level),

	TP_ARGS(screen_bl_level),

	TP_STRUCT__entry(
		__field(int *, screen_bl_level)
	),

	TP_fast_assign(
		__entry->screen_bl_level = screen_bl_level;
	),

	TP_printk("hung_wp_screen_getbl")
);

TRACE_EVENT(hung_wp_screen_setbl,

	TP_PROTO(int level),

	TP_ARGS(level),

	TP_STRUCT__entry(
		__field(int, level)
	),

	TP_fast_assign(
		__entry->level = level;
	),

	TP_printk("hung_wp_screen_setbl")
);

TRACE_EVENT(hung_wp_screen_setbl_with_type,

	TP_PROTO(int level, int type),

	TP_ARGS(level, type),

	TP_STRUCT__entry(
		__field(int, level)
		__field(int, type)
	),

	TP_fast_assign(
		__entry->level = level;
		__entry->type = type;
	),

	TP_printk("hung_wp_screen_setbl_with_type")
);
#ifdef CONFIG_ARMPC_ECHUB_LID
TRACE_EVENT(hung_wp_screen_set_lid_status,

	TP_PROTO(int status),

	TP_ARGS(status),

	TP_STRUCT__entry(
		__field(int, status)
	),

	TP_fast_assign(
		__entry->status = status;
	),

	TP_printk("hung_wp_screen_set_lid_status")
);
#endif
TRACE_EVENT(hung_wp_screen_qcom_pkey_press,

	TP_PROTO(int type, int state),

	TP_ARGS(type, state),

	TP_STRUCT__entry(
		__field(int, type)
		__field(int, state)
	),

	TP_fast_assign(
		__entry->type = type;
		__entry->state = state;
	),

	TP_printk("hung_wp_screen_qcom_pkey_press")
);

TRACE_EVENT(hung_wp_screen_powerkey_ncb,

	TP_PROTO(unsigned long event),

	TP_ARGS(event),

	TP_STRUCT__entry(
		__field(unsigned long, event)
	),

	TP_fast_assign(
		__entry->event = event;
	),

	TP_printk("hung_wp_screen_powerkey_ncb")
);

/*
 * TRACE_EVENT requires at least one argument to be defined.
 * This just throws in a dummy argument.
 */
TRACE_EVENT(dfx_watchdog_check_hung,

	TP_PROTO(int unused),

	TP_ARGS(unused),

	TP_STRUCT__entry(
	),

	TP_fast_assign(
	),

	TP_printk("dfx_watchdog_check_hung")
);

TRACE_EVENT(dfx_watchdog_lockup_init,

	TP_PROTO(int unused),

	TP_ARGS(unused),

	TP_STRUCT__entry(
	),

	TP_fast_assign(
	),

	TP_printk("dfx_watchdog_lockup_init")
);

TRACE_EVENT(dfx_watchdog_lockup_init_work,

	TP_PROTO(int unused),

	TP_ARGS(unused),

	TP_STRUCT__entry(
	),

	TP_fast_assign(
	),

	TP_printk("dfx_watchdog_lockup_init_work")
);

#endif /* _TRACE_ZEROHUNG_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
