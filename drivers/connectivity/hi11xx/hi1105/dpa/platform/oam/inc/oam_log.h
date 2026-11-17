/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oam_log.c header file
 * Author: dpa drivers
 */

#ifndef OAM_LOG_H
#define OAM_LOG_H

#include "oam_logger.h"
#include "osl_list.h"

#define OAM_LOG_ENTRY_PARA_NUM   4                      // 日志携带参数个数

/* 日志全局管理结构体 */
typedef struct {
    oal_switch_enum_uint8 en_global_log_switch; /* 日志全局开关 */
    uint8_t log_level;                          /* 特性日志级别 */
} oam_log_ctx_stru;

typedef struct {
    /* 输出方式 */
    uint8_t en_output_type;
    /* LOG模块管理上下文 */
    oam_log_ctx_stru log_ctx;
} oam_mng_ctx_stru;

extern oam_mng_ctx_stru g_oam_mng_ctx;

int32_t oam_log_init(void);
void oam_log_deinit(void);

#endif /* end of oam_log.h */
