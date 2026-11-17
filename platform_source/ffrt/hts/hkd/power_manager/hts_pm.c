#include "hts_pm.h"
#include <linux/kernel.h>
#include "platform_include/see/ffa/ffa_msg_id.h"
#include "hts_kernel_log.h"
#include "hts_tzsp.h"
#include "hts_common.h"
#include "hpd_interface.h"

int hts_powerup(void)
{
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	struct hpd_registry *hpd = NULL;
	int ret;

	hts_drv_info("befor hts powerup");
	ret = tzsp_service_hts_smc(HTS_POWER_UP, 0, 0, 0);
	if (ret != FFRT_ALREADY_POWERUP && ret != FFRT_OK) {
		hts_drv_err("hts powerup fail, ret = 0x%x\n", ret);
		atomic_set(&dev_ctx->dev_power_status[0], 0);
		return -1;
	}
	hts_drv_info("after hts powerup");

	if (ret == FFRT_ALREADY_POWERUP) {
		hts_drv_err("hts already powerup, ret = 0x%x\n", ret);
		atomic_set(&dev_ctx->dev_power_status[0], 1);
		return FFRT_OK;
	}

	hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -1, "hpd is not registered\n");
	if (hpd->hts_resource_clear != NULL)
		hpd->hts_resource_clear();

	atomic_set(&dev_ctx->dev_power_status[0], 1);
	return ret;
}

