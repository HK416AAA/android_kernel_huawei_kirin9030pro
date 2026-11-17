/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_dpa_util.h
 * Author: dpa drivers
 */

#ifndef OAL_DPA_UTIL_H
#define OAL_DPA_UTIL_H

#include <mdrv_sys.h>
#include <mdrv_base.h>
#include <bsp_print.h>
#include <bsp_record.h>
#include "bsp_dump.h"
#include "oal_types.h"
#include "securec.h"

enum wifi_sub_mod {
    smod_hcc = 0,
};

#undef THIS_MODU
#define THIS_MODU mod_wifi

#define MUTEX_CALLSTACK_MAX_DEPTH 8

#define oal_likely(_expr)   ((_expr) ? true : false)
#define oal_unlikely(_expr) ((_expr) ? true : false)

#ifndef HISI_LOG_TAG
#define HISI_LOG_TAG
#endif
#define NEWLINE "\n"

/* 比较宏 */
#define oal_min(_A, _B) (((_A) < (_B)) ? (_A) : (_B))

/* 比较宏 */
#define oal_max(_A, _B) (((_A) > (_B)) ? (_A) : (_B))

#define oal_sub(_A, _B) (((_A) > (_B)) ? ((_A) - (_B)) : (0))

// 仅用于ete_comm驱动，保持和dev代码一致
#define oal_io_print(fmt, arg...)                      \
    do {                                               \
        bsp_dpa_record(HISI_LOG_TAG "" fmt, ##arg); \
    } while (0)

#define oal_warn_on(condition)  ((condition) ? true : false)

#define oal_build_bug_on(_con) ((oal_void)sizeof(char[1 - 2 * !!(_con)])) // 数字1 2 无实际含义，仅做编译验证

#define oal_bug_on(_con)        \
    do {                        \
        if ((_con)) {           \
            bsp_print("oal_bug_on !!!!!![%s:%d]\n", __FUNCTION__, __LINE__); \
        }                    \
    } while (0)

#define sys_abort(errorno)  \
    do {                    \
        system_error(WLAN_ERRNO_START, 0, 0, NULL, 0);      \
    } while (0)

static inline void oal_dump_callstack(void)
{
    uint32_t i;
    uint32_t call_depth = MUTEX_CALLSTACK_MAX_DEPTH - 1;
    unsigned long func_stack[MUTEX_CALLSTACK_MAX_DEPTH] = {0};
    if (mdrv_get_callstack(&call_depth, &func_stack[0]) == MDRV_OK) {
        for (i = 0; i < call_depth && i < MUTEX_CALLSTACK_MAX_DEPTH; i++) {
            bsp_dpa_record("layer%u : [0x%x]", i, (uint32_t)func_stack[i]);
        }
    }
}
#endif
