/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat debug log header file
 * Author: common drivers
 */

#ifndef __PLAT_DEBUG_H__
#define __PLAT_DEBUG_H__

#include "log.h"
#include "plat_oam.h"

#ifdef _PRE_LINUX_TEST
#define PRINT_ERR(fmt, arg...)      printf(fmt "\n", ##arg)
#define PRINT_WARN(fmt, arg...)     printf(fmt "\n", ##arg)
#define PRINT_INFO(fmt, arg...)     printf(fmt "\n", ##arg)
#define PRINT_DEBUG(fmt, arg...)    printf(fmt "\n", ##arg)

#else // _PRE_LINUX_TEST

#define PLAT_LOCAL_PRINT    0
#if PLAT_LOCAL_PRINT

#include <stdint.h>

extern void HAL_UartDebugPrintf(const char *fmt, ...);

#define sz_info(fmt, arg...)    HAL_UartDebugPrintf("[bfgx][i]"fmt, ##arg)
#define sz_warn(fmt, arg...)    HAL_UartDebugPrintf("[bfgx][w]"fmt, ##arg)
#define sz_err(fmt, arg...)     HAL_UartDebugPrintf("[bfgx][e]"fmt, ##arg)
#define sz_dbg(fmt, arg...)     HAL_UartDebugPrintf("[bfgx][d]"fmt, ##arg)

#ifdef PRINT_ERR
#undef PRINT_ERR
#define PRINT_ERR(fmt, arg...)      sz_err(fmt, ##arg)
#endif

#ifdef PRINT_WARN
#undef PRINT_WARN
#define PRINT_WARN(fmt, arg...)     sz_warn(fmt, ##arg)
#endif

#ifdef PRINT_INFO
#undef PRINT_INFO
#define PRINT_INFO(fmt, arg...)     sz_info(fmt, ##arg)
#endif

#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#define PRINT_DEBUG(fmt, arg...)    sz_dbg(fmt, ##arg)
#endif

#undef HILOG_ERROR
#undef HILOG_WARN
#undef HILOG_INFO
#define HILOG_ERROR(x, fmt, arg...)     sz_err(fmt, ##arg)
#define HILOG_WARN(x, fmt, arg...)      sz_warn(fmt, ##arg)
#define HILOG_INFO(x, fmt, arg...)      sz_info(fmt, ##arg)

#else  // PLAT_LOCAL_PRINT

extern uint8_t g_oam_save_log_flag;
#ifdef PRINT_ERR
#undef PRINT_ERR
#define PRINT_ERR(fmt, arg...) \
do { \
    if (g_oam_save_log_flag == OAM_SAVE_LOG_START) { \
        HILOG_ERROR(HILOG_MODULE_GPS, "[bfgx][E]"fmt, ##arg); \
    } \
} while (0)
#endif

#ifdef PRINT_WARN
#undef PRINT_WARN
#define PRINT_WARN(fmt, arg...) \
do { \
    if (g_oam_save_log_flag == OAM_SAVE_LOG_START) { \
        HILOG_WARN(HILOG_MODULE_GPS, "[bfgx][W]"fmt, ##arg); \
    } \
} while (0)
#endif

#ifdef PRINT_INFO
#undef PRINT_INFO
#define PRINT_INFO(fmt, arg...) \
do { \
    if (g_oam_save_log_flag == OAM_SAVE_LOG_START) { \
        HILOG_INFO(HILOG_MODULE_GPS, "[bfgx][I]"fmt, ##arg); \
    } \
} while (0)
#endif

#ifdef PRINT_DEBUG
#undef PRINT_DEBUG
#define PRINT_DEBUG(fmt, arg...)
#endif

#endif // PLAT_LOCAL_PRINT
#endif // _PRE_LINUX_TEST
#endif