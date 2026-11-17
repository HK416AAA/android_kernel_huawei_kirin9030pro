/*
 * hts_platform.h
 *
 * about hts platform
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

#ifndef _HTS_PLATFORM_H_
#define _HTS_PLATFORM_H_
#include <linux/interrupt.h>
#include "hts_common_resource.h"

struct hts_mem_desc {
	uint64_t base;
	uint64_t len;
};
struct hts_resmem_info {
	size_t size;
	uint64_t virt_addr;
	uint64_t phy_addr;
};

struct hts_dts_info {
	int irq_abnormal;
	void __iomem *reg_vaddr[HTS_REG_MAX_RESOURCE];
	struct hts_mem_desc reg_desc[HTS_REG_MAX_RESOURCE];
};

struct hts_platform_info {
	struct hts_dts_info dts_info;
	struct device *pdev;
	struct hts_resmem_info resmem_desc[HTS_RESMEM_MAX_RESOURCE];
};

struct hts_platform_info *hts_plat_get_info(void);
struct hpd_registry *hts_get_hpd_registry(void);
uint8_t *hts_plat_get_reg_vaddr(hts_register_index idx);
#endif