#ifndef __LINUX_MMC_HWSPINLOCK_H
#define __LINUX_MMC_HWSPINLOCK_H

#include <linux/err.h>
#include <linux/sched.h>

int __emmc_hwspin_lock_timeout(struct hwspinlock *, unsigned int, int, unsigned long *);
void __emmc_hwspin_unlock(struct hwspinlock *, int, unsigned long *);

static inline int emmc_hwspin_lock_timeout(struct hwspinlock *hwlock, unsigned int to)
{
	return __emmc_hwspin_lock_timeout(hwlock, to, 0, NULL);
}

static inline void emmc_hwspin_unlock(struct hwspinlock *hwlock)
{
	__emmc_hwspin_unlock(hwlock, 0, NULL);
}

#endif /* __LINUX_MMC_HWSPINLOCK_H */