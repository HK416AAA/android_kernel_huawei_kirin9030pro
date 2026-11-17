/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#ifndef NSTACK_TIME_H
#define NSTACK_TIME_H

#include <uapi/linux/time.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>
#include <linux/timecounter.h>
#include "config.h"
#include "stack_types.h"
#include "stack_time_unit.h"
#include "bsp_slice.h"

#define SPL_NS_PER_TICK 30500

static inline u32 stack_get_stat_time(void)
{
    return bsp_get_slice_value();
}

static inline void stack_ns_to_timespec(struct timespec *tp, ktime_t ns)
{
    if (ns == 0) {
        tp->tv_sec = 0;
        tp->tv_nsec = 0;
        return;
    }

    tp->tv_sec = (long)(ns / (long)SPL_NS_PER_S);
    /* as tv_sec needs millions of century to become negetive, so ignore this situation here */
    tp->tv_nsec = (long)(ns % (long)SPL_NS_PER_S);
}

static inline s32 stack_sys_clock_gettime(clockid_t clock_id, struct timespec *tp)
{
    ktime_t cur_time;
    if (clock_id == CLOCK_REALTIME) {
        cur_time = ktime_get_real();
    } else {
        cur_time = ktime_get_raw();
    }
    ktime_t ns = ktime_to_ns(cur_time);
    stack_ns_to_timespec(tp, ns);
    return 0;
}

static inline s64 stack_get_systime(clockid_t clock_id)
{
    ktime_t cur_time;
    if (clock_id == CLOCK_REALTIME) {
        cur_time = ktime_get_real();
    } else {
        cur_time = ktime_get_raw();
    }
    return ktime_to_ns(cur_time);
}

static inline long stack_time(long *seconds)
{
    s64 ns = stack_get_systime(CLOCK_REALTIME);
    long s = (long)(ns / (s64)SPL_NS_PER_S);
    if (seconds != NULL) {
        *seconds = s;
    }
    return s;
}

static inline s32 stack_sys_gettimeofday(struct timeval *tv, void *tz)
{
    struct timespec64 ts = {0};
    ktime_get_real_ts64(&ts);
    tv->tv_sec = ts.tv_sec;
    tv->tv_usec = ts.tv_nsec / SPL_NS_PER_US;
    return 0;
}

static inline u32 get_msec_since_midnight(void)
{
    struct timeval tv;
    if (stack_sys_gettimeofday(&tv, NULL) != 0) {
        return 0;
    }

    /* tv.tv_sec is the number of seconds since the Epoch, need to convert to milliseconds since the recent midnight */
    u32 cur_ms = (u32)((unsigned long)tv.tv_sec % SPL_S_PER_DAY * SPL_MS_PER_S);
    return cur_ms + (u32)((unsigned long)tv.tv_usec / SPL_US_PER_MS);
}

static inline long sys_now(void)
{
    s64 ns = stack_get_systime(CLOCK_MONOTONIC);
    return (long)(ns / (s64)SPL_NS_PER_MS);
}

static inline u32 stack_get_diff_time_u32(u32 begin, u32 end)
{
    return get_timer_slice_delta(begin, end);
}

#endif
