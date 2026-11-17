/*
 * audio_drv_trace.h
 *
 * audio trace point
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
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
#ifdef CONFIG_AUDIO_DEBUG

#undef TRACE_SYSTEM
#define TRACE_SYSTEM audio_drv_trace
/*lint +e773*/
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH platform_include/trace/events

#if !defined(_AUDIO_DRV_TRACE_H_) || defined(TRACE_HEADER_MULTI_READ)
#define _AUDIO_DRV_TRACE_H_

#include <linux/stringify.h>
#include <linux/types.h>
#include <linux/tracepoint.h>

TRACE_EVENT(audio_pcm_trace_performance_lack,
	TP_PROTO(const char *print_type, unsigned int delay_time, int pcm_device, int pcm_mode),
	TP_ARGS(print_type, delay_time, pcm_device, pcm_mode),
	TP_STRUCT__entry(
			__string(trace_name, print_type)
			__field(unsigned int, delay_time)
			__field(int, pcm_device)
			__field(int, pcm_mode)
	),
	TP_fast_assign(
            __assign_str(trace_name, print_type);
			__entry->delay_time = delay_time;
			__entry->pcm_device = pcm_device;
			__entry->pcm_mode = pcm_mode;
	),
	TP_printk("%s, delay time stamp diff is %u, pcm device %d pcm mode %d", __get_str(trace_name),
			__entry->delay_time, __entry->pcm_device, __entry->pcm_mode)
);

TRACE_EVENT(audio_pcm_trace_underrun,
	TP_PROTO(int device, int stream, long avail, long rt_period_size),
	TP_ARGS(device, stream, avail, rt_period_size),
	TP_STRUCT__entry(
			__field(int, device)
			__field(int, stream)
			__field(long, avail)
			__field(long, rt_period_size)
	),
	TP_fast_assign(
			__entry->device = device;
			__entry->stream = stream;
			__entry->avail = avail;
			__entry->rt_period_size = rt_period_size;
	),
	TP_printk("underrun, device is %d, mode is %d, avail[%ld] < period size[%ld]",
		__entry->device, __entry->stream, __entry->avail, __entry->rt_period_size)
);
#endif /* _AUDIO_DRV_TRACE_H_ */

/* This part must be outside protection */
#include <trace/define_trace.h>

#else
#include <linux/stringify.h>
#include <linux/types.h>

#if !defined(_AUDIO_DRV_TRACE_H_)
#define _AUDIO_DRV_TRACE_H_
static inline void trace_audio_pcm_trace_performance_lack(const char *print_type,
	unsigned int delay_time, int pcm_device, int pcm_mode)
{
}
static inline void trace_audio_pcm_trace_underrun(int device, int stream,
	long avail, long rt_period_size)
{
}
#endif /* _AUDIO_DRV_TRACE_H_ */
#endif
