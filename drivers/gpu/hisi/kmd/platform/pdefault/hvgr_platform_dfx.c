/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include <securec.h>
#include "hvgr_platform_api.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_ffa.h"

bool hvgr_dmd_need_check_nv(struct hvgr_device *gdev)
{
	struct gpu_dmd_msg *dmd_msg = gdev->dm_dev.dmd_msg;
	u64 *check_ts = &(dmd_msg->dmd_check_ts[0]);
	u32 last_idx;
	u32 first_idx;

	if (!dmd_msg->enable_sh_check)
		return false;
	if (dmd_msg->dmd_fault_cnt < dmd_msg->dmd_check_cnt) {
		hvgr_err(gdev, HVGR_DM, "invalid fault cnt dmd_fault_cnt=%u dmd_check_cnt=%u!\n",
			dmd_msg->dmd_fault_cnt, dmd_msg->dmd_check_cnt);
		return false;
	}

	if ((dmd_msg->dmd_fault_cnt - dmd_msg->dmd_check_cnt) < MAX_DMD_CHECK_CNT)
		return false;

	last_idx = (dmd_msg->dmd_fault_cnt - 1u) % MAX_DMD_CHECK_CNT;
	first_idx = (1u + last_idx) % MAX_DMD_CHECK_CNT;
	hvgr_debug(gdev, HVGR_DM, "gpu fault last tick=%llu first tick=%llu!\n",
		check_ts[last_idx], check_ts[first_idx]);

	if (check_ts[last_idx] <= check_ts[first_idx]) {
		dmd_msg->dmd_check_cnt = dmd_msg->dmd_fault_cnt;
		return false;
	}

	if ((check_ts[last_idx] - check_ts[first_idx]) <= MAX_DMD_CHECK_INTERVAL) {
		dmd_msg->dmd_check_cnt = dmd_msg->dmd_fault_cnt;
		return true;
	}

	dmd_msg->dmd_check_cnt++;
	return false;
}

bool hvgr_dfv_check_time(struct hvgr_device *gdev)
{
	struct gpu_dmd_msg *dmd_msg = gdev->dm_dev.dmd_msg;
	u64 *check_ts = &(dmd_msg->dfv_check_ts[0]);
	u32 last_idx;
	u32 first_idx;

	if (dmd_msg->dmd_fault_cnt < dmd_msg->dfv_check_cnt) {
		hvgr_err(gdev, HVGR_DM, "invalid fault cnt dmd_fault_cnt=%u dfv_check_cnt=%u!\n",
			dmd_msg->dmd_fault_cnt, dmd_msg->dfv_check_cnt);
		return false;
	}

	if ((dmd_msg->dmd_fault_cnt - dmd_msg->dfv_check_cnt) < MAX_DFV_CHECK_CNT)
		return false;

	last_idx = (dmd_msg->dmd_fault_cnt - 1u) % MAX_DFV_CHECK_CNT;
	first_idx = (1u + last_idx) % MAX_DFV_CHECK_CNT;
	hvgr_debug(gdev, HVGR_DM, "gpu fault dfv last tick=%llu first tick=%llu!\n",
		check_ts[last_idx], check_ts[first_idx]);

	if (check_ts[last_idx] <= check_ts[first_idx]) {
		dmd_msg->dfv_check_cnt = dmd_msg->dmd_fault_cnt;
		return false;
	}

	if ((check_ts[last_idx] - check_ts[first_idx]) <= MAX_DMD_CHECK_INTERVAL) {
		dmd_msg->dfv_check_cnt = dmd_msg->dmd_fault_cnt;
		return true;
	}

	dmd_msg->dfv_check_cnt++;
	return false;
}

uint64_t __attribute__((weak)) hvgr_platform_sh_runtime(struct hvgr_device *gdev, u8 *buf, u64 size)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_dfv_runtime(struct hvgr_device *gdev, u8 *buf, u64 size)
{
	return 0;
}
int hvgr_dmd_sh_process(void *data)
{
	enum dmd_nv_mark nv_mark;
	struct hvgr_dmd_nv_data nv_data = {0};
	struct hvgr_device *gdev = (struct hvgr_device *)data;
	struct gpu_dmd_msg *dmd_msg = NULL;

	if (unlikely(gdev == NULL))
		return -1;

	dmd_msg = gdev->dm_dev.dmd_msg;
	mutex_lock(&dmd_msg->dmd_lock);
	hvgr_dmd_sr_awake(gdev);
	if (hvgr_dmd_nv_read(gdev, &nv_data) != 0)
		goto err_end;

	if (nv_data.info.bit.freq_mark == 1u) {
		/* unmark, write freq_mark to 0 */
		nv_data.info.bit.freq_mark = 0u;
		if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
			goto err_end;
		hvgr_debug(gdev, HVGR_DM, "already set freq mark and unmark it!\n");
		hvgr_dmd_sr_relax(gdev);
		nv_mark = DMD_NV_UNMARK;
		goto end;
	}
	/* mark, write dmd nv to mark value */
	nv_data.info.bit.freq_mark = 1u;
	if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
		goto err_end;

	hvgr_dmd_sr_relax(gdev);
	nv_mark = DMD_NV_MARK;
	(void)hvgr_platform_sh_runtime(gdev, (unsigned char *)&nv_data, sizeof(nv_data));
end:
	dmd_msg->dmd_sh_flag = 1u;
	mutex_unlock(&dmd_msg->dmd_lock);
	if (nv_mark == DMD_NV_MARK)
		hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd sh nv mark");
	else
		hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd sh nv unmark");
	hvgr_dmd_msg_report(gdev);
	return 0;
err_end:
	dmd_msg->dmd_sh_flag = 0u;
	hvgr_dmd_sr_relax(gdev);
	mutex_unlock(&dmd_msg->dmd_lock);
	return -1;
}

int hvgr_dmd_dfv_process(void *data)
{
	struct hvgr_dmd_nv_data nv_data = {0};
	struct hvgr_device *gdev = (struct hvgr_device *)data;
	struct gpu_dmd_msg *dmd_msg = NULL;
	union hvgr_dmd_nv_dfv_data *dfv_data = NULL;
	uint8_t dfv_en = 1u;

	if (unlikely(gdev == NULL))
		return -1;

	dmd_msg = gdev->dm_dev.dmd_msg;
	mutex_lock(&dmd_msg->dmd_lock);
	hvgr_dmd_sr_awake(gdev);
	if (hvgr_dmd_nv_read(gdev, &nv_data) != 0)
		goto err_end;

	dfv_data = (union hvgr_dmd_nv_dfv_data *)(&nv_data.buf[HVGR_DMD_DFV_IDX]);
	if (dfv_data->bit.en != 0) {
		hvgr_dmd_sr_relax(gdev);
		mutex_unlock(&dmd_msg->dmd_lock);
		return 0;
	}

	/* mark, write gpu nv to mark value */
	dfv_data->bit.en = 1u;
	if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
		goto err_end;

	hvgr_dmd_sr_relax(gdev);
	(void)hvgr_platform_dfv_runtime(gdev, (unsigned char *)&dfv_en, sizeof(dfv_en));
	dmd_msg->dfv_sh_triggered = true;
	mutex_unlock(&dmd_msg->dmd_lock);
	hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd dfv nv mark");
	hvgr_dmd_msg_report(gdev);
	return 0;
err_end:
	dmd_msg->dfv_sh_triggered = false;
	hvgr_dmd_sr_relax(gdev);
	mutex_unlock(&dmd_msg->dmd_lock);
	return -1;
}

int hvgr_dmd_sh_dsc_process(void *data)
{
	enum dmd_nv_mark nv_mark;
	struct hvgr_dmd_nv_data nv_data = {0};
	struct hvgr_device *gdev = (struct hvgr_device *)data;
	struct gpu_dmd_msg *dmd_msg = NULL;
	struct hvgr_dmd_nv_dsc_data *dsc_data = NULL;
	char log_buf[MAX_DMD_LOG_LENTH] = {0};
	int ret;

	if (unlikely(gdev == NULL))
		return -1;

	dmd_msg = gdev->dm_dev.dmd_msg;

	mutex_lock(&dmd_msg->dmd_lock);
	hvgr_dmd_sr_awake(gdev);
	if (hvgr_dmd_nv_read(gdev, &nv_data) != 0)
		goto err_end;

	dsc_data = (struct hvgr_dmd_nv_dsc_data *)(&nv_data.buf[HVGR_DMD_DSC_IDX]);
	if (dsc_data->info.bit.dsc_mark == 1U) {
		/* unmark, write dsc_mark to 0 */
		dmd_msg->dsc_mask = 0U;
		dmd_msg->enable_dsc_flag = false;
		dsc_data->info.bit.dsc_mark = 0U;
		dsc_data->nv_dsc_mask = 0U;
		if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
			goto err_end;

		hvgr_debug(gdev, HVGR_DM, "already set dsc mark and unmark it!\n");
		hvgr_dmd_sr_relax(gdev);
		nv_mark = DMD_NV_UNMARK;
		goto end;
	}
	if (!hvgr_is_single_bit(dmd_msg->dmd_dsc_mask)) {
		hvgr_err(gdev, HVGR_DM, "dsc mark is not single bit!\n");
		goto err_end;
	}

	/* mark, write dmd nv to mark value */
	dmd_msg->dsc_mask = dmd_msg->dmd_dsc_mask;
	dmd_msg->enable_dsc_flag = true;
	dsc_data->info.bit.dsc_mark = 1U;
	dsc_data->nv_dsc_mask = dmd_msg->dmd_dsc_mask;
	if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
		goto err_end;

	hvgr_dmd_sr_relax(gdev);
	nv_mark = DMD_NV_MARK;
end:
	dmd_msg->dmd_dsc_flag = 1U;
	mutex_unlock(&dmd_msg->dmd_lock);
	if (nv_mark == DMD_NV_MARK) {
		ret = sprintf_s(log_buf, MAX_DMD_LOG_LENTH, "dmd dsc sh nv mark, gpc 0x%x/0x%x",
			dmd_msg->dsc_mask, hvgr_pm_get_availiable_cores(gdev));
		if (ret < 0)
			hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd dsc sh nv mark");
		else
			hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, log_buf);
	} else {
		hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd dsc sh nv unmark");
	}
	hvgr_dmd_msg_report(gdev);
	return 0;
err_end:
	dmd_msg->dmd_dsc_flag = 0U;
	hvgr_dmd_sr_relax(gdev);
	mutex_unlock(&dmd_msg->dmd_lock);
	return -1;
}

void __attribute__((weak)) hvgr_dmd_msg_check(struct hvgr_device *gdev)
{
	return;
}

void __attribute__((weak)) hvgr_dfv_health_check(struct hvgr_device *gdev)
{
	return;
}

void __attribute__((weak)) hvgr_dmd_dsc_check(struct hvgr_device *gdev)
{
	return;
}
