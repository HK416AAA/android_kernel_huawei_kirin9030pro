/* SPDX-License-Identifier: GPL-2.0 */
/*
 * direct_charge_work.h
 *
 * direct charge work module
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _DIRECT_CHARGE_WORK_H_
#define _DIRECT_CHARGE_WORK_H_

#include <linux/hrtimer.h>
#include <linux/workqueue.h>

#ifdef CONFIG_DIRECT_CHARGER
void dc_init_work(int local_mode);
void dc_reset_work_para(void);
#else
static inline void dc_init_work(int local_mode)
{
}

static inline void dc_reset_work_para(void)
{
}
#endif /* CONFIG_DIRECT_CHARGER */

#endif /* _DIRECT_CHARGE_WORK_H_ */
