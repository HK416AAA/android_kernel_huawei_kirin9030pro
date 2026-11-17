/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include <securec.h>
#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
#include <platform_include/basicplatform/linux/rdr_pub.h>
#include <platform_include/basicplatform/linux/rdr_platform.h>
#include "mntn_public_interface.h"
#endif

#include "bbox/hvgr_bbox.h"
#include "hvgr_defs.h"
#include "hvgr_log_api.h"
#ifdef CONFIG_HVGR_DFX_MNTN_REPORT
#include "datan/hvgr_mntn.h"
#endif

int hvgr_bbox_init(struct hvgr_device * const gdev)
{
	struct rdr_register_module_result retinfo = {0};
	struct rdr_module_ops_pub module_ops = {0};
	int ret;

#ifdef CONFIG_HVGR_DFX_MNTN_REPORT
	module_ops.ops_dump = hvgr_mntn_dump;
#else
	module_ops.ops_dump = NULL;
#endif
	module_ops.ops_reset = NULL;

	ret = rdr_register_module_ops(RDR_GPU, &module_ops, &retinfo);
	if (ret < 0) {
		hvgr_debug(gdev, HVGR_DM, "rdr register failed! ret = %d\n", ret);
		gdev->dm_dev.bbox_register_succ = false;
		return ret;
	}

	gdev->dm_dev.bbox_register_succ = true;
#if hvgr_version_ge(350)
	if (retinfo.log_addr == 0UL || retinfo.log_len == 0U) {
		gdev->dm_dev.bbox_buffer = NULL;
		gdev->dm_dev.bbox_buffer_size = 0U;
		hvgr_debug(gdev, HVGR_DM, "not support bbox space.");
		return 0;
	}
	atomic_set(&gdev->dm_dev.bbox_buffer_wrlen, 0U);
	gdev->dm_dev.bbox_buffer = (char *)dfx_bbox_map(retinfo.log_addr, retinfo.log_len);
	gdev->dm_dev.bbox_buffer_size = retinfo.log_len;
	if (gdev->dm_dev.bbox_buffer == NULL)
		hvgr_err(gdev, HVGR_DM, "map bbox buffer fail!");
#endif
	return 0;
}

int hvgr_bbox_term(struct hvgr_device * const gdev)
{
	int ret;

#if hvgr_version_ge(350)
	if (gdev->dm_dev.bbox_buffer != NULL)
		dfx_bbox_unmap(gdev->dm_dev.bbox_buffer);
	gdev->dm_dev.bbox_buffer = NULL;
	gdev->dm_dev.bbox_buffer_size = 0U;
	atomic_set(&gdev->dm_dev.bbox_buffer_wrlen, 0U);
#endif
	gdev->dm_dev.bbox_register_succ = false;
	ret = rdr_unregister_module_ops(RDR_GPU);
	if (ret != 0)
		hvgr_err(gdev, HVGR_DM, "rdr unregister failed! ret = %d\n", ret);
	return ret;
}

uint64_t hvgr_get_current_kernel_time(void)
{
#if hvgr_version_ge(350)
	return (dfx_getcurtime() / 1000ULL);
#else
	return 0U;
#endif
}

#if hvgr_version_ge(350)
void hvgr_bbox_log(struct hvgr_device *gdev, const char *format, ...)
{
	char buffer_tmp[HVGR_BBOX_ONCE_LOG_LEN] = {0};
	struct hvgr_dm_dev *dm_dev = &gdev->dm_dev;
	int ret;
	va_list argList;
	uint32_t buffer_len;
	uint32_t wrlen;
	uint32_t wrlen_old;
	uint32_t wr_point;

	/* the current platform doesnot support bbox space */
	if (dm_dev->bbox_buffer == NULL || dm_dev->bbox_buffer_size == 0U)
		return;

	/* collect log */
	va_start(argList, format);
	ret = vsnprintf_s(buffer_tmp, HVGR_BBOX_ONCE_LOG_LEN, HVGR_BBOX_ONCE_LOG_LEN - 1,
		format, argList);
	va_end(argList);
	(void)argList;

	if (ret <= 0)
		hvgr_debug(gdev, HVGR_DFX, "bbox log is too loog");

	buffer_len = strlen(buffer_tmp);
	do {
		/* get wr point and now wrlen */
		wrlen_old = atomic_read(&dm_dev->bbox_buffer_wrlen);
		wr_point = wrlen_old;
		wrlen = wrlen_old + buffer_len;
		/* check is the remaining buffer sufficient */
		if (wrlen >= dm_dev->bbox_buffer_size) {
			wr_point = 0U;
			wrlen = buffer_len;
		}
		/* check if wrlen was taken by others */
	} while (atomic_cmpxchg(&dm_dev->bbox_buffer_wrlen, wrlen_old, wrlen) != wrlen_old);
	ret = memcpy_s(&dm_dev->bbox_buffer[wr_point], buffer_len, buffer_tmp, buffer_len);
	if (ret != EOK)
		hvgr_debug(gdev, HVGR_DFX, "output log to bbox space fail!");
	hvgr_info(gdev, HVGR_DFX, "ntime=%llu wrlen_o=%u wrp=%u wrlen=%u buffer_len=%u s=%s",
		hvgr_get_current_kernel_time(), wrlen_old, wr_point, wrlen, buffer_len, buffer_tmp);
}
#endif
