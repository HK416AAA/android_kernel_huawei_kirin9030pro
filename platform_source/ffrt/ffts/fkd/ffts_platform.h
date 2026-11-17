/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts plat
 */

#ifndef _FFTS_PLATFORM_H_
#define _FFTS_PLATFORM_H_

#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "inc/ffts_common.h"

#define PAGE_SIZE_OFFSET (4 * 1024)

enum ffts_irq_index {
	FFTS_IRQ_NORMAL,
	FFTS_IRQ_ABNORMAL,
};

enum ffts_register_index {
	FFTS_USER_BASE_REG,
	FFTS_KERNEL_BASE_REG,
	FFTS_REG_MAX_RESOURCE,
};

struct ffts_mem_desc {
	u64 base;
	u64 len;
};

struct ffts_dts_info {
	void __iomem *reg_vaddr[FFTS_REG_MAX_RESOURCE];
	struct ffts_mem_desc reg_desc[FFTS_REG_MAX_RESOURCE];
	int irq_normal;
	int irq_abnormal;
	int lpid_max;
};

struct ffts_platform_info {
	struct ffts_dts_info dts_info;
	struct ffts_mem_info resmem_desc[FFTS_RESMEM_MAX];
};

vir_addr_t ffts_get_reg_base(void);
struct fpd_registry* get_fpd(void);
struct ffts_platform_info *ffts_plat_get_info(void);

#endif