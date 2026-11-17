/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:oal_tas_switch.c header file
 * Author: platform drivers
 */

#ifndef OAL_TAS_SWITCH_H
#define OAL_TAS_SWITCH_H

/* 其他头文件包含 */
#include "oal_types.h"

/* 函数声明 */
/**
 * @if Eng
 * @brief  Initialize the tas switch module.
 * @param  None.
 * @retval None.
 * @else
 * @brief  初始化TAS开关模块。
 * @param  无。
 * @retval 无。
 * @endif
 */
void oal_tas_l5_switch_init(void);

/**
 * @if Eng
 * @brief  Set the TAS status.
 * @param  [in]  tas_status TAS status value to set.
 * @retval None.
 * @else
 * @brief  设置TAS）状态。
 * @param  [in]  tas_status 要设置的TAS状态值。
 * @retval 无。
 * @endif
 */
void oal_tas_l5_switch_set(int32_t tas_status);

/**
 * @if Eng
 * @brief  Get the current TAS status.
 * @param  None.
 * @retval uint32_t Current TAS status value.
 * @else
 * @brief  获取当前TAS状态。
 * @param  无。
 * @retval uint32_t 当前的TAS状态值。
 * @endif
 */
int32_t oal_tas_l5_switch_get(void);
#endif /* end of oal_tas_switch */
