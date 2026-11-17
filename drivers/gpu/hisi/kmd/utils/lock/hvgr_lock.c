/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_lock.h"
#include "hvgr_log_api.h"

#define HVGR_HOLDLOCK_THRESHOLD 50  /* ms */
#define HVGR_TRY_LOCK_TIMES     5000000 /* us */
#define HVGR_DEAD_LOCK_ENABLE   0

void hvgr_spin_lock_init(struct hvgr_spin_lock *lock, const char * lock_name)
{
	spin_lock_init(&lock->spin_lock);
	lock->name = lock_name;
}

#if defined(HVGR_DEAD_LOCK_ENABLE) && HVGR_DEAD_LOCK_ENABLE != 0
void hvgr_spin_lock_irqsave(struct hvgr_device * const gdev, struct hvgr_spin_lock *lock,
	const char *func_name)
{
	ktime_t time;
	int try_times = HVGR_TRY_LOCK_TIMES;

	hvgr_info(gdev, HVGR_LOCK, "%s %s will come to get %s.", __func__,
		func_name, lock->name);
	time = ktime_get();
	while (spin_trylock_irqsave(&lock->spin_lock, lock->flags) == 0) {
		udelay(1);
		try_times--;
		if (try_times == 0) {
			hvgr_err(gdev, HVGR_LOCK, "%s %s get %s timeout, deaklock may happen. owner=%s",
				__func__, func_name, lock->name, lock->owner);
			dump_stack();
			BUG_ON(1);
			return;
		}
	}
	lock->lock_time = ktime_get();
	lock->owner = func_name;
	hvgr_info(gdev, HVGR_LOCK, "%s %s get %s time=%u ns. try_times=%d", __func__, lock->owner,
		lock->name, ktime_to_ns(lock->lock_time - time), HVGR_TRY_LOCK_TIMES- try_times);
}
#else 
void hvgr_spin_lock_irqsave(struct hvgr_device * const gdev, struct hvgr_spin_lock *lock,
	const char *func_name)
{
	spin_lock_irqsave(&lock->spin_lock, lock->flags);
}
#endif

void hvgr_spin_unlock_irqrestore(struct hvgr_device * const gdev, struct hvgr_spin_lock *lock)
{	

	spin_unlock_irqrestore(&lock->spin_lock, lock->flags);
}
