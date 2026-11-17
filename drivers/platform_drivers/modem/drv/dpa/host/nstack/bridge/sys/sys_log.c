/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */

#include <linux/printk.h>
#include <linux/ratelimit.h>
#include <linux/ratelimit_types.h>
#include "stack_log.h"
#include "securec.h"
#include "sys_log.h"

#define LOG_SUP_MSG_LEN 16
#define AOS_MAX_LOG_LEN 512
struct ratelimit_state g_log_ratelimit_state;
DEFINE_RATELIMIT_STATE(g_log_ratelimit_state, 1 * HZ, 30);
#if defined(DPA_MODE)
#define MODULE_NAME "TongTu_DPA_Data_Plane"
#endif

static int log_ratelimit(void)
{
    return __ratelimit(&g_log_ratelimit_state);
}

void ns_log(s32 level, const char *func_name, s32 line, u32 log_sup_cnt, const char *format, ...)
{
    s32 ret;
    char log_buf[AOS_MAX_LOG_LEN] = {0};
    char log_suppress_msg[LOG_SUP_MSG_LEN] = {0};
    va_list arglist;
    va_start(arglist, format);
    ret = vsprintf_s(log_buf, AOS_MAX_LOG_LEN, format, arglist);
    if (ret == -1) {
        va_end(arglist);
        return;
    }
    va_end(arglist);

    if (log_sup_cnt != 0U) {
        ret = sprintf_s(log_suppress_msg, (size_t)LOG_SUP_MSG_LEN, "[%u]", log_sup_cnt);
        if (ret == -1) {
            return;
        }
    }
    if (level == NSLOG_DBG) {
        pr_info("[D][%s][%s %d]%s %s\n", MODULE_NAME, func_name, line, log_suppress_msg, log_buf);
    } else if (level == NSLOG_INF) {
        pr_info("[I][%s][%s %d]%s %s\n", MODULE_NAME, func_name, line, log_suppress_msg, log_buf);
    } else if (level == NSLOG_WAR && log_ratelimit() == 1) {
        pr_warn("[W][%s][%s %d]%s %s\n", MODULE_NAME, func_name, line, log_suppress_msg, log_buf);
    } else if (level == NSLOG_ERR && log_ratelimit() == 1) {
        pr_err("[E][%s][%s %d]%s %s\n", MODULE_NAME, func_name, line, log_suppress_msg, log_buf);
    } else if (level == NSLOG_EMG && log_ratelimit() == 1) {
        pr_emerg("[EMG][%s][%s %d]%s %s\n", MODULE_NAME, func_name, line, log_suppress_msg, log_buf);
    }
}

#ifdef _DEBUG
void stack_dump_stack(void)
{
    dump_stack();
}
#endif
