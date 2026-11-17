/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for board
 * Author: plat drivers
 */

#define USE_LOG_TAG_FUNC
#define pr_fmt(fmt) "2[hisi_plat]" fmt

#include "board.h"
#include "plat_debug.h"

int32_t hi110x_board_init(void)
{
    // 中断初始化 & 解析从ap侧过来的定制化数据
    return BOARD_SUCC;
}

void hi110x_board_exit(void)
{
}

int32_t hi11xx_get_os_build_variant(void)
{
    return 0;
}

hi110x_release_vtype hi110x_get_release_type(void)
{
    hi110x_release_vtype vtype = HI110X_VTYPE_DEBUG;

    /* check the version release or debug */
    if (hi11xx_get_os_build_variant() == HI1XX_OS_BUILD_VARIANT_ROOT) {
        return vtype;
    }

#if defined(CONFIG_LOG_EXCEPTION) && !defined(CONFIG_HI110X_KERNEL_MODULES_BUILD_SUPPORT)
    if (get_logusertype_flag() == BETA_USER) {
        /* beta user */
        return HI110X_VTYPE_RELEASE_DEBUG;
    } else {
        /* release(user & non beta user) */
        return HI110X_VTYPE_RELEASE;
    }
#else
    /* kernel module or no beta user function */
    vtype = HI110X_VTYPE_DEBUG;
#endif

    return vtype;
}