/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <aae/soc_aae_interface.h>
#include <aae/dpu_dm.h>
#include "ukmd_utils.h"
#include "akmd_log.h"

void dump_aae_sdma_dbg_info(char __iomem *module_base)
{
	uint32_t i;

	for (i = 0; i < OPR_SDMA_NUM; ++i) {
		aae_pr_warn("SDMA[%u]:\n"
			"\tSDMA_DBG_OUT0=%#x\n"
			"\tSDMA_DBG_MONITOR0=%#x\t\tSDMA_DBG_MONITOR1=%#x\n\tSDMA_DBG_MONITOR2=%#x\t\tSDMA_DBG_MONITOR3=%#x\n"
			"\tSDMA_DBG_MONITOR4=%#x\t\tSDMA_DBG_MONITOR5=%#x\n\tSDMA_W_DBG0=%#x\t\tSDMA_W_DBG1=%#x\n"
			"\tSDMA_W_DBG2=%#x\t\tSDMA_W_DBG3=%#x\tSDMA_CTRL=%#x\t\n\n", i,
			inp32(AAE_GLB_PART0_SDMA_DBG_OUT0_ADDR(module_base, i)), /* bit0-14:sdma cmd num that not get ACK from bus */
			inp32(AAE_GLB_PART0_SDMA_DBG_MONITOR0_ADDR(module_base, i)), inp32(AAE_GLB_PART0_SDMA_DBG_MONITOR1_ADDR(module_base, i)),
			inp32(AAE_GLB_PART0_SDMA_DBG_MONITOR2_ADDR(module_base, i)), inp32(AAE_GLB_PART0_SDMA_DBG_MONITOR3_ADDR(module_base, i)),
			inp32(AAE_GLB_PART0_SDMA_DBG_MONITOR4_ADDR(module_base, i)), inp32(AAE_GLB_PART0_SDMA_DBG_MONITOR5_ADDR(module_base, i)),
			inp32(AAE_GLB_PART0_SDMA_W_DBG0_ADDR(module_base, i)), inp32(AAE_GLB_PART0_SDMA_W_DBG1_ADDR(module_base, i)),
			inp32(AAE_GLB_PART0_SDMA_W_DBG2_ADDR(module_base, i)), inp32(AAE_GLB_PART0_SDMA_W_DBG3_ADDR(module_base, i)),
			inp32(AAE_GLB_PART0_SDMA_CTRL0_ADDR(module_base, i)));
	}
}