/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <linux/module.h>
#include "akmd_log.h"

uint32_t g_akmd_log_level = UKMD_LOG_LVL_INFO;
uint32_t g_debug_aae_perf_level = 0;
uint32_t g_debug_aae_pip_wait_time = 0;
uint32_t g_debug_aae_clear_enable = 0;
uint32_t g_debug_aae_power_off_enable = 1;

#ifdef CONFIG_AKMD_DEBUG_ENABLE
module_param_named(debug_msg_level, g_akmd_log_level, uint, 0640);
MODULE_PARM_DESC(debug_msg_level, "aae msg level");

module_param_named(debug_aae_perf_level, g_debug_aae_perf_level, uint, 0640);
MODULE_PARM_DESC(debug_aae_perf_level, "aae perf level");

module_param_named(debug_aae_pip_wait_time, g_debug_aae_pip_wait_time, uint, 0640);
MODULE_PARM_DESC(debug_aae_pip_wait_time, "aae pip wait time");

module_param_named(debug_aae_clear_enable, g_debug_aae_clear_enable, uint, 0640);
MODULE_PARM_DESC(debug_aae_clear_enable, "aae clear enable");

module_param_named(debug_aae_power_off_enable, g_debug_aae_power_off_enable, uint, 0640);
MODULE_PARM_DESC(debug_aae_power_off_enable, "aae power off enable");
#endif
