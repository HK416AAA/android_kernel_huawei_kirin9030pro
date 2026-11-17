/*
 * ffts_resmem.c
 *
 * ffts resmem
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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
#include "ffts_resmem.h"
 
#include <linux/types.h>
#include <asm/io.h>
#include <securec.h>
#include "dfx/ffts_log.h"
#include "inc/ffts_common.h"

static void ffts_plat_set_resmem_info(struct ffts_mem_info *resmem_info, phys_addr_t base, size_t len)
{
	if (resmem_info != NULL) {
		resmem_info->phy_addr = base;
		resmem_info->size = len;
	}
}

void ffts_plat_get_resmem_info(struct ffts_platform_info *plat_info)
{
	cond_return_void(plat_info == NULL, "plat_info is null\n");
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_PROCCTX_DDR],
		FFTS_PROCCTX_BASE_ADDR, FFTS_PROCCTX_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_THREADCTX_DDR],
		FFTS_THREADCTX_BASE_ADDR, FFTS_THREADCTX_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_TASKCTX_DDR], FFTS_TASKCTX_BASE_ADDR, FFTS_TASKCTX_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_VERCTX_DDR], FFTS_VERCTX_BASE_ADDR, FFTS_VERCTX_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_SIGCTX_DDR], FFTS_SIGCTX_BASE_ADDR, FFTS_SIGCTX_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_HWRTB_DDR], FFTS_HWRTB_BASE_ADDR, FFTS_HWRTB_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_ACPU_INT_QUEUE_DDR],
		FFTS_ACPU_INT_QUEUE_BASE_ADDR, FFTS_ACPU_INT_QUEUE_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_ISP_INT_QUEUE_DDR],
		FFTS_ISP_INT_QUEUE_BASE_ADDR, FFTS_ISP_INT_QUEUE_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_SR_DDR], FFTS_SR_BASE_ADDR, FFTS_SR_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_HTS_AUTH_TABLE_DDR],
		FFTS_HTS_AUTH_TABLE_BASE_DDR, FFTS_HTS_AUTH_TABLE_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_PERF_DDR],
		FFTS_PERF_BASE_ADDR, FFTS_PERF_DDR_LEN);
    ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_MDM_TSP_INT_QUEUE_DDR],
		FFTS_MDM_TSP_INT_QUEUE_BASE_ADDR  , FFTS_MDM_TSP_INT_QUEUE_DDR_LEN );
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_MDM_PSA_INT_QUEUE_DDR],
		FFTS_MDM_PSA_INT_QUEUE_BASE_ADDR  , FFTS_MDM_PSA_INT_QUEUE_DDR_LEN);
	ffts_plat_set_resmem_info(&plat_info->resmem_desc[FFTS_MDM_DPA_INT_QUEUE_DDR],
		FFTS_MDM_DPA_INT_QUEUE_BASE_ADDR  , FFTS_MDM_DPA_INT_QUEUE_DDR_LEN );
}
