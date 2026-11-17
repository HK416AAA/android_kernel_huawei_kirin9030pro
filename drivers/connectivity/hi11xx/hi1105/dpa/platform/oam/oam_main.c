/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Initializing and Uninstalling the OAM Module
 * Author: dpa drivers
 */

/* 头文件包含 */
#include "oal_util.h"
#include "oam_main.h"
#include "oam_log.h"
#include "securec.h"

#define OAM_LOG_DEFAULT_LEVEL OAM_LOG_LEVEL_WARNING

/*
 * 全局变量定义
 * OAM模块统一使用的全局操作变量上下文，包括OAM其他子模块全局上下文
 */
oam_mng_ctx_stru g_oam_mng_ctx;

/*
 * 函 数 名  : oam_log_set_global_switch
 * 功能描述  : 设置日志全局开关状态
 */
OAL_STATIC OAL_INLINE void oam_log_set_global_switch(oal_switch_enum_uint8 log_switch)
{
    g_oam_mng_ctx.log_ctx.en_global_log_switch = log_switch;
}

/*
 * 函 数 名  : oam_log_set_log_level
 * 功能描述  : 设置所有日志级别为log_level
 */
void oam_log_set_log_level(uint8_t log_level)
{
    if ((log_level >= OAM_LOG_LEVEL_BUTT) || (log_level < OAM_LOG_LEVEL_ERROR)) {
        return;
    }

    g_oam_mng_ctx.log_ctx.log_level = log_level;
}

/*
 * 函 数 名  : oam_main_init
 * 功能描述  : OAM模块初始化总入口，包含OAM模块内部所有特性的初始化。
 */
int32_t oam_main_init(void)
{
    int32_t ret;

    /* 日志全局开关默认为开 */
    oam_log_set_global_switch(OAL_SWITCH_ON);

    /* 日志级别设置 */
    oam_log_set_log_level(OAM_LOG_DEFAULT_LEVEL);

    /* 完成LOG模块的初始化操作 */
    ret = oam_log_init();
    if (ret != OAL_SUCC) {
        return ret;
    }

    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "oam_main_init succ");
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_main_deinit
 * 功能描述  : OAM模块注销总入口。
 */
void oam_main_deinit(void)
{
    /* 完成LOG模块的去初始化操作 */
    oam_log_deinit();

    memset_s((void *)&g_oam_mng_ctx, sizeof(g_oam_mng_ctx), 0, sizeof(g_oam_mng_ctx));
}

