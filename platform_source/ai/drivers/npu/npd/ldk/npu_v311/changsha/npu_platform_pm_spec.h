/*
 * npu_platform_pm.h
 *
 * about npu hwts plat
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef __NPU_PLATFORM_PM_SPEC_H
#define __NPU_PLATFORM_PM_SPEC_H

#include <linux/types.h>

#define SELF_HEALING_FREQ_NUM 7
static u32 need_self_healing_freq[SELF_HEALING_FREQ_NUM] = { 0, 1, 2, 3, 4, 5, 6 }; // all freq
static u32 self_healing_voltage[SELF_HEALING_FREQ_NUM] = { 20, 20, 20, 20, 20, 20, 20 };
static u32 binx_self_healing_voltage[SELF_HEALING_FREQ_NUM] = { 30, 30, 30, 25, 25, 20, 20 };
static u32 factory_self_healing_voltage[SELF_HEALING_FREQ_NUM] = { 20, 20, 20, 20, 20, 20, 20 };

enum npu_subip {
	NPU_IP_TOP              = 0, /* npu subsys, npu bus */
	NPU_IP_NON_TOP             = 1, /* tzpc */
#ifndef NPU_AICORE_AUTOBOOT
	NPU_IP_AICORE_GE          = 2, /* ts subsys, hwts init, tcu */
	NPU_IP_AICORE_EFF         = 3, /* aicore subsys, aicore tbu init */
#endif
	NPU_IP_TSCPU, /* ts_subsys_tbu_connect, tscpu startup, doorbell */
	NPU_SUBIP_MAX,
};

#endif
