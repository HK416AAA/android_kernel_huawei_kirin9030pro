/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef __GOODIX_TS_LOG_H__
#define __GOODIX_TS_LOG_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "hm_os_sys.h"

typedef enum {
    TS_LOG_LEVEL_NONE,
    TS_LOG_LEVEL_ERROR,
    TS_LOG_LEVEL_WARN,
    TS_LOG_LEVEL_INFO,
    TS_LOG_LEVEL_DEBUG,
} TS_LOG_LEVEL;

void ts_log_print(TS_LOG_LEVEL level, const char *fmt, ...);
void ts_log_level_set(TS_LOG_LEVEL level);
void ts_info_array(u8 *array, int len);

/* log macro */
#if 1
#define	ts_err(f, ...) \
		ts_log_print(TS_LOG_LEVEL_ERROR, (f), ## __VA_ARGS__)
#define ts_info(f, ...) \
		ts_log_print(TS_LOG_LEVEL_INFO, (f), ## __VA_ARGS__)
#define ts_debug(f, ...) \
		ts_log_print(TS_LOG_LEVEL_DEBUG, (f), ## __VA_ARGS__)
#else
#define ts_err(f, ...) \
        do {} while (0)
#define ts_info(f, ...) \
        do {} while (0)
#define ts_debug(f, ...) \
        do {} while (0)

#endif
#ifdef __cplusplus
}
#endif
#endif
