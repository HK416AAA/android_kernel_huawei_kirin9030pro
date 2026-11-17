/*
 * Copyright (c) 2015-2020 Huawei Device Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __CPUIDLE_NOTIFIER_H
#define __CPUIDLE_NOTIFIER_H

#ifdef CONFIG_HUAWEI_IDLE_NOTIFY
extern struct atomic_notifier_head idle_status_notifier_list;
int idle_status_notifier_register(struct notifier_block *nb);
int idle_status_notifier_unregister(struct notifier_block *nb);
#else
static inline int idle_status_notifier_register(struct notifier_block *nb)
{
	return 0;
}

static inline int idle_status_notifier_unregister(struct notifier_block *nb)
{
	return 0;
}
#endif

#endif
