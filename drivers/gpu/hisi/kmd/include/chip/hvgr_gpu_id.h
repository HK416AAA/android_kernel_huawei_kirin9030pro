/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_GPU_ID_H
#define HVGR_GPU_ID_H

#include "hvgr_fcp.h"

#define HVGR_GPU_VSTAT_BIT_START         0
#define HVGR_GPU_VMIN_BIT_START          4
#define HVGR_GPU_VMAJ_BIT_START          12
#define HVGR_GPU_PMAJ_BIT_START          16
#define HVGR_GPU_AREV_BIT_START          20
#define HVGR_GPU_AMIN_BIT_START          24
#define HVGR_GPU_AMAJ_BIT_START          28
#define HVGR_GPU_VSTAT_MASK       ((u32)0xF << HVGR_GPU_VSTAT_BIT_START)
#define HVGR_GPU_VMIN_MASK        ((u32)0xFF << HVGR_GPU_VMIN_BIT_START)
#define HVGR_GPU_VMAJ_MASK        ((u32)0xF << HVGR_GPU_VMAJ_BIT_START)
#define HVGR_GPU_PMAJ_MASK        ((u32)0xF << HVGR_GPU_PMAJ_BIT_START)
#define HVGR_GPU_AREV_MASK        ((u32)0xF << HVGR_GPU_AREV_BIT_START)
#define HVGR_GPU_AMIN_MASK        ((u32)0xF << HVGR_GPU_AMIN_BIT_START)
#define HVGR_GPU_AMAJ_MASK        ((u32)0xF << HVGR_GPU_AMAJ_BIT_START)
#define HVGR_GET_GPU_DRV_VER(gpu_id) \
    ((gpu_id) & (HVGR_GPU_AMAJ_MASK | HVGR_GPU_PMAJ_MASK))

struct hvgr_reg_base_cfg {
	uint32_t gpu_id;
	struct hvgr_register_module_base reg_base;
};

/*
 * Helper macro to create a partial GPU_ID (new format) that identifies
 * a particular GPU model by its AMAJ and PMAJ.
 */
#define hvgr_gpu_drv_ver(arch_major, product_major) \
		((((u32)(arch_major)) << HVGR_GPU_AMAJ_BIT_START)  | \
		(((u32)(product_major)) << HVGR_GPU_PMAJ_BIT_START))

#endif /* HVGR_GPU_ID_H */
