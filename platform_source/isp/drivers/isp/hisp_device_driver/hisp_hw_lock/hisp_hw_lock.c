
#include "hisp_hw_lock.h"
#include <linux/hwspinlock.h>
#include "isp_ddr_map.h"
#include "hisp_internel.h"

static struct hwspinlock *hisp_hwlock = NULL;

int hisp_hw_lock_init(void)
{
	hisp_hwlock = hwspin_lock_request_specific(HISP_HW_SPIN_LOCK_ID);
	if (hisp_hwlock == NULL) {
		pr_err("[%s] get hwspinlock fail, id.%u\n",
			__func__, HISP_HW_SPIN_LOCK_ID);
		return -1;
	}

	return 0;
}

void hisp_hw_lock_exit(void)
{
	if (hisp_hwlock != NULL) {
		(void)hwspin_lock_free(hisp_hwlock);
		hisp_hwlock = NULL;
	}
}

int hisp_hw_lock_get(void)
{
	int ret = 0;

	if (hisp_hwlock != NULL) {
		ret = hwspin_lock_timeout(hisp_hwlock, HISP_HW_SPIN_LOCK_TIMEOUT);
		if (ret != 0) {
			pr_err("[%s] hw spin lock fail ret %d\n", __func__, ret);
			return -1;
		}
		return 0;
	} else {
		pr_err("[%s] hw spin lock not init\n", __func__);
		return -1;
	}
}

void hisp_hw_lock_put(void)
{
	hwspin_unlock(hisp_hwlock);
}

