/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: board.c header file
 * Author: plat drivers
 */

#ifndef __BOARD_H__
#define __BOARD_H__

/* 其他头文件包含 */
#include "plat_type.h"

#define DSM_1103_TCXO_ERROR        909030001
#define DSM_1103_DOWNLOAD_FIRMWARE 909030033
#define DSM_BUCK_PROTECTED         909030034
#define DSM_1103_HALT              909030035
#define DSM_WIFI_FEMERROR          909030036
#define DSM_PCIE_SWITCH_SDIO_FAIL  909030043
#define DSM_PCIE_SWITCH_SDIO_SUCC  909030044
#define DSM_BT_FEMERROR            913002007

extern void hw_110x_dsm_client_notify(int sub_sys, int dsm_id, const char *fmt, ...);

/* 宏定义 */
#define BOARD_SUCC 0
#define BOARD_FAIL (-1)

#define BOARD_VERSION_LEN    128

typedef enum _hi110x_release_vtype_ {
    HI110X_VTYPE_RELEASE = 0, /* release version */
    HI110X_VTYPE_RELEASE_DEBUG, /* beta user */
    HI110X_VTYPE_DEBUG, /* debug version */
    HI110X_VTYPE_BUT
} hi110x_release_vtype;

// TODO: 低功耗相关待适配
#define GPIO_BT_WAKEUP_MCU 0
#define GPIO_HIGHLEVEL 1
#define GPIO_LOWLEVEL  0

#ifndef HI1XX_OS_BUILD_VARIANT_USER
#define HI1XX_OS_BUILD_VARIANT_ROOT 1
#define HI1XX_OS_BUILD_VARIANT_USER 2
#endif
/* 函数声明 */
int32_t hi11xx_get_os_build_variant(void);
hi110x_release_vtype hi110x_get_release_type(void);
int32_t hi110x_board_init(void);
void hi110x_board_exit(void);
#endif