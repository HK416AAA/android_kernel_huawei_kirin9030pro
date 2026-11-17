/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#ifndef SYS_LOG_H
#define SYS_LOG_H

#include "stack_types.h"

void ns_log(s32 level, const char *func_name, s32 line, u32 log_sup_cnt, const char *format, ...);

#define NS_LOGPID(_level, fmt, ...) \
do { \
    if (MODULE_LOG_LEVEL >= (u32)(_level)) { \
        ns_log((_level), __func__, __LINE__, 0, fmt, ##__VA_ARGS__); \
    } \
} while (0)

#define NS_DFX(fmt, ...) \
do { \
    ns_log(NSLOG_ERR, __func__, __LINE__, 0, fmt, ##__VA_ARGS__); \
} while (0)

#ifdef _DEBUG
void stack_dump_stack(void);
#else
static inline void stack_dump_stack(void)
{
    return;
}
#endif

#endif /* #ifndef SYS_LOG_H */