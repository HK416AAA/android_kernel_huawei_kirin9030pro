/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * lpcpu_cpufreq_hv.h
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _LPCPU_CPUFREQ_HV_H
#define _LPCPU_CPUFREQ_HV_H
#include <linux/cpufreq.h>
#ifdef CONFIG_LPCPU_CPUFREQ_HV
void hv_set_max_freq(struct cpufreq_policy *policy);
#else
static inline void hv_set_max_freq(struct cpufreq_policy *policy __maybe_unused) {}
#endif
#endif
