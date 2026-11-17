/*
 * watch_low_power_manager.h
 *
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2024. All rights reserved.
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

#ifndef WATCH_LOW_POWER_MANAGER_H
#define WATCH_LOW_POWER_MANAGER_H

#include <linux/notifier.h>
#define WATCH_LOW_POWER_ENTER 0  /* enter str state */
#define WATCH_LOW_POWER_EXIT 1  /* exit str state */
#define WATCH_LOW_POWER_POWER_OFF 2  /* str state power off */
#define WATCH_LOW_POWER_REBOOT 3  /* str state reboot */

/* If device need to switch when str state enter, devcie can call this interface.
 * When str state enter, it will call the device notifier_block callback
 */
int register_watch_low_power_enter_notifier(int val, struct notifier_block *nb);

/* If device need to switch when str state exit, devcie can call this interface.
 * When str state exit, it will call the device notifier_block callback
 */
int register_watch_low_power_exit_notifier(int val, struct notifier_block *nb);

/* If device do not need to concern to str state enter after regsiter, device can call this interface */
int unregister_watch_low_power_enter_notifier(int val, struct notifier_block *nb);

/* If device do not need to concern to str state after regsiter, device can call this interface */
int unregister_watch_low_power_exit_notifier(int val, struct notifier_block *nb);

/* identify the devie power state */
bool is_watch_low_power_state(void);
#endif // WATCH_LOW_POWER_MANAGER_H