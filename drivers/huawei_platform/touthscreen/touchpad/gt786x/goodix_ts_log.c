/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "hm_os_sys.h"
#include "goodix_ts_log.h"
#include <securec.h>

static int g_ts_log_level = TS_LOG_LEVEL_INFO;

#define MAX_LOG_MSG_LEN  1024
void ts_log_print(TS_LOG_LEVEL level, const char *fmt, ...)
{
    int ret;
    va_list arg;
    char buf[MAX_LOG_MSG_LEN] = {0};

    if (g_ts_log_level < level) {
        return;
    }
    
    va_start(arg, fmt);
    ret = vsnprintf_s(buf, MAX_LOG_MSG_LEN, MAX_LOG_MSG_LEN, fmt, arg);
    if (ret == -1) {
        ts_err("vsnprintf_s fail");
    }
    va_end(arg);

    sys_log_print(buf);
}

void ts_log_level_set(TS_LOG_LEVEL level)
{
    g_ts_log_level = level;
}

#define GOODIX_LINE_NODE_NUM 16
void ts_info_array(u8 *array, int len)
{
    int str_len = 0;
    int i;
    char str_buf[MAX_LOG_MSG_LEN] = {0};

    if (g_ts_log_level < TS_LOG_LEVEL_INFO) {
        return;
    }

    for (i = 0; i < len; i++) {
        if (MAX_LOG_MSG_LEN - str_len > 0)
            str_len += snprintf_s(str_buf + str_len, MAX_LOG_MSG_LEN - str_len, MAX_LOG_MSG_LEN - str_len,
                                  "%02x ", array[i]);
        if (i != 0 && (i % GOODIX_LINE_NODE_NUM == (GOODIX_LINE_NODE_NUM - 1))) {
            sys_log_print(str_buf);
            sys_log_print("\n");
            memset_s(str_buf, sizeof(str_buf), 0, sizeof(str_buf));
            str_len = 0;
        }
    }
    if (str_len) {
        sys_log_print(str_buf);
        sys_log_print("\n");
    }
}
