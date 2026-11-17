/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */
#ifndef NSTACK_LOG_H
#define NSTACK_LOG_H

#include "sys_log.h"
#include "stack_types.h"

#define NSLOG_DBG 0x10
#define NSLOG_INF 0x08
#define NSLOG_WAR 0x04
#define NSLOG_ERR 0x02
#define NSLOG_EMG 0x01


#ifdef BUILD_BRIDGE
extern u32 g_bridge_log_level;
#define MODULE_LOG_LEVEL   g_bridge_log_level
#elif BUILD_STACK
extern u32 g_stack_log_level;
#define MODULE_LOG_LEVEL   g_stack_log_level
#endif

#define NS_INF(fmt, ...) NS_LOGPID(NSLOG_INF, fmt, ##__VA_ARGS__)
#define NS_DBG(fmt, ...) NS_LOGPID(NSLOG_DBG, fmt, ##__VA_ARGS__)
#define NS_WAR(fmt, ...) NS_LOGPID(NSLOG_WAR, fmt, ##__VA_ARGS__)
#define NS_ERR(fmt, ...) NS_LOGPID(NSLOG_ERR, fmt, ##__VA_ARGS__)

#endif /* _NSTACK_LOG_H_ */
