/*
 * str.h
 *
 * str function
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef __H_STR_H__
#define __H_STR_H__
#ifdef CONFIG_SYS_PM_STR

#include <linux/types.h>
#include <linux/notifier.h>

#define PM_STR_ENTER 0
#define PM_STR_EXIT  1

int register_pm_str_notifier(unsigned long val, struct notifier_block *nb);
int unregister_pm_str_notifier(unsigned long val, struct notifier_block *nb);
bool is_str(void);

#endif /* CONFIG_SYS_PM_STR */
#endif /* __H_STR_H__ */
