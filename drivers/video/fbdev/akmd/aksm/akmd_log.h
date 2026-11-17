/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef AKMD_LOG_H
#define AKMD_LOG_H

#include <linux/types.h>
#include <linux/ktime.h>
#include "aksm_debug.h"
#include "ukmd_log.h"

#define aae_pr_err(msg, ...)  xkmd_pr_err("AKMD", msg, ##__VA_ARGS__)

#define aae_pr_warn(msg, ...) xkmd_pr_warn("AKMD", g_akmd_log_level, msg, ##__VA_ARGS__)

#define aae_pr_info(msg, ...) xkmd_pr_info("AKMD", g_akmd_log_level, msg, ##__VA_ARGS__)

#define aae_pr_debug(msg, ...) xkmd_pr_debug("AKMD", g_akmd_log_level, msg, ##__VA_ARGS__)


#define aae_check_and_return(condition, ret, level, msg, ...) \
	do { \
		if (condition) { \
			aae_pr_##level(msg, ##__VA_ARGS__);\
			return ret; \
		} \
	} while (0)

#define aae_check_and_no_retval(condition, level, msg, ...) \
	do { \
		if (condition) { \
			aae_pr_##level(msg, ##__VA_ARGS__);\
			return; \
		} \
	} while (0)

#ifdef CONFIG_AKMD_ASSERT_ENABLE
#define aae_assert(cond)  do { \
		if (cond) { \
			aae_pr_err("assertion failed! %s,%s:%d,%s\n", #cond,  __FILE__, __LINE__, __func__); \
			BUG(); \
		} \
	} while (0)
#else
#define aae_assert(ptr)
#endif

static inline void aae_get_timestamp(uint64_t *start_ns)
{
	*start_ns = ktime_get_mono_fast_ns();
}

#define aae_trace_ts_begin(start_ns) aae_get_timestamp(start_ns)
#define aae_trace_ts_end(start_ns, msg)  do { \
		if (g_akmd_log_level >= UKMD_LOG_LVL_DEBUG) { \
			uint64_t end_ns; \
			aae_get_timestamp(&end_ns); \
			aae_pr_info("%s timediff=%llu us", msg, div_u64(end_ns - *(start_ns), 1000)); \
		} \
	} while (0)

#define aae_print_timestamp(msg) do { \
		if (g_akmd_log_level >= UKMD_LOG_LVL_DEBUG) { \
			ktime_t timestamp; \
			timestamp = ktime_get();; \
			aae_pr_debug("%s timestamp_ns=%llu ns", msg,  ktime_to_ns(timestamp)); \
		} \
	} while (0)

#endif /* AKMD_LOG_H */
