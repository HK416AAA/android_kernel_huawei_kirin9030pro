/*
 * sched_chip_info.h
 *
 * head file for sched chip info
 *
 * Copyright (c) 2025-2026 Huawei Technologies Co., Ltd.
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
#ifndef __SCHED_CHIP_INFO_H__
#define __SCHED_CHIP_INFO_H__

#ifdef CONFIG_SCHED_CHIP_INFO
bool get_soc_is_bottom_power(void);
#else
static inline bool get_soc_is_bottom_power(void) { return false; }
#endif

#endif
