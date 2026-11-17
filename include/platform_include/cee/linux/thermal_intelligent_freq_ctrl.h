/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Thermal intelligent cpufreq ctrl.
 */
#ifndef __THERMAL_INTELLIGENT_FREQ_CTRL_H
#define __THERMAL_INTELLIGENT_FREQ_CTRL_H

#ifdef CONFIG_THERMAL_INTELLIGENT_FREQ_CTRL
extern unsigned int thermal_freq_ctrl_enable;
#ifdef CONFIG_THERMAL_EMULATION
extern unsigned int shell_thermal_emul_temp;
#endif
extern unsigned int thermal_intelligent_ctrl;
void thermal_intelligent_update(int cpu, struct task_struct *next);
unsigned int thermal_intelligent_freq_limit(struct cpufreq_policy *policy);
void thermal_intelligent_update_busy(void);
void update_doframe_status(bool begin);
void handle_art_gc_wait(bool begin);
void thermal_intelligent_whitelist_update(struct task_struct *p);
#endif

#endif
