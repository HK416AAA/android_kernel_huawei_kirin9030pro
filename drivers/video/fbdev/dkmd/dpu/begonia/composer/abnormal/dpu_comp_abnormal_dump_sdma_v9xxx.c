/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#include <dpu/soc_dpu_define.h>
#include <dpu/soc_dpu_interface.h>
#include <dpu/dpu_dm.h>
#include "dkmd_log.h"
#include "dkmd_object.h"

void dpu_comp_abnormal_dump_sdma_info(char __iomem *module_base)
{
	uint32_t i;
 
	for (i = 0; i < OPR_SDMA_NUM; ++i) {
		dpu_pr_warn("SDMA[%u]:\n"
			"\tSDMA_DBG_OUT0=%#x\n"
			"\tSDMA_DBG_MONITOR0=%#x\t\tSDMA_DBG_MONITOR1=%#x\n\tSDMA_DBG_MONITOR2=%#x\t\tSDMA_DBG_MONITOR3=%#x\n"
			"\tSDMA_DBG_MONITOR4=%#x\t\tSDMA_DBG_MONITOR5=%#x\n\tSDMA_CTRL=%#x\t\n\n", i,
			inp32(DPU_SDMA_DBG_OUT0_ADDR(module_base, i)), /* bit0-14:sdma cmd num that not get ACK from bus */
			inp32(DPU_SDMA_DBG_MONITOR0_ADDR(module_base, i)), inp32(DPU_SDMA_DBG_MONITOR1_ADDR(module_base, i)),
			inp32(DPU_SDMA_DBG_MONITOR2_ADDR(module_base, i)), inp32(DPU_SDMA_DBG_MONITOR3_ADDR(module_base, i)),
			inp32(DPU_SDMA_DBG_MONITOR4_ADDR(module_base, i)), inp32(DPU_SDMA_DBG_MONITOR5_ADDR(module_base, i)),
			inp32(DPU_SDMA_CTRL0_ADDR(module_base, i)));
	}

	dpu_pr_warn("SDMA WRAP:\n"
		"\tSDMA_WRAP_DEBUG2=%#x\t\tSDMA_WRAP_DEBUG3=%#x\n\tSDMA_WRAP_DEBUG4=%#x\t\tSDMA_WRAP_DEBUG5=%#x\n",
		inp32(DPU_SDMA_WRAP_DBG_OUT2_ADDR(module_base)),
		inp32(DPU_SDMA_WRAP_DBG_OUT3_ADDR(module_base)),
		inp32(DPU_SDMA_WRAP_DBG_OUT4_ADDR(module_base)),
		inp32(DPU_SDMA_WRAP_DBG_OUT5_ADDR(module_base)));
}