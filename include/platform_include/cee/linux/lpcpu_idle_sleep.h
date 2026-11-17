/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 * Description : information about cpuidle
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __LPCPU_IDLE_SLEEP_H__
#define __LPCPU_IDLE_SLEEP_H__

#include <linux/cpumask.h>

enum {
	ID_MODEM = 0,
	ID_IOMCU,
	ID_GPS,
	ID_UFS,
	ID_WIFI,
	ID_MOTOR,
	ID_MOTOR_LRA,
	ID_FINGERPRINT,
	ID_BBIC,
	ID_IODIE,
	ID_MUX,
};

#ifdef CONFIG_LPCPU_MULTIDRV_CPUIDLE
u32 lpcpu_get_idle_cpumask(void);
#else
static inline u32 lpcpu_get_idle_cpumask(void) { return 0; }
#endif

#ifdef CONFIG_LPCPU_IDLE_SLEEP
s32 lpcpu_idle_sleep_vote(u32 modid, u32 val);
u32 lpcpu_idle_sleep_getval(void);
#else
static inline s32 lpcpu_idle_sleep_vote(u32 modid, u32 val) { return 0; }
static inline u32 lpcpu_idle_sleep_getval(void) { return 0; }
#endif

#ifdef CONFIG_BHSVOLT_DYNAMIC
extern u32 *bhs_cfg_addr;
extern bool g_bhs_flag[NR_CPUS];
extern void bhs_volt_cfg(int bhs_cpu, int cfg);
extern int bhs_volt_init(struct device_node *np);
#else
static inline void bhs_volt_cfg(int bhs_cpu, int cfg) {}
static inline int bhs_volt_init(struct device_node *np) { return 0; }
#endif

#endif
