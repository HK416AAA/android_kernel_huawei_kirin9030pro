/*
 * ffts_reg.c
 *
 * ffts reg
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
#include "ffts_reg.h"

#include <linux/of_address.h>
#include <securec.h>

#include "ffts_log.h"

int ffts_plat_parse_reg_desc(struct platform_device *pdev, struct ffts_platform_info *plat_info)
{
	unsigned int i;
	struct resource *info = NULL;
	struct ffts_mem_desc *mem_desc = NULL;
	unsigned int max_regs = FFTS_REG_MAX_RESOURCE;

	for (i = 0; i < max_regs; i++) {
		info = platform_get_resource(pdev, IORESOURCE_MEM, i);
		if (info == NULL || info->end <= info->start) {
			ffts_drv_err("info is invalid, i = %d\n", i);
			return -1;
		}
		mem_desc = &plat_info->dts_info.reg_desc[i];
		mem_desc->base = info->start;
		mem_desc->len = info->end - info->start + 1;
	}

	return 0;
}

int ffts_plat_map_reg(struct platform_device *pdev, struct ffts_platform_info *plat_info)
{
	void __iomem *base = NULL;
	struct ffts_mem_desc *mem_desc = NULL;
	
	mem_desc = &plat_info->dts_info.reg_desc[FFTS_KERNEL_BASE_REG];
	if (mem_desc->base == 0 || mem_desc->len == 0) {
		plat_info->dts_info.reg_vaddr[FFTS_KERNEL_BASE_REG] = NULL;
		ffts_drv_err("mem desc error\n");
		return -1;
	}

	base = devm_ioremap(&pdev->dev, mem_desc->base, mem_desc->len);
	if (base == NULL) {
		ffts_drv_err("devm ioremap failed\n");
		return -1;
	}

	plat_info->dts_info.reg_vaddr[FFTS_KERNEL_BASE_REG] = base;

	return 0;
}

int ffts_plat_unmap_reg(struct platform_device *pdev, struct ffts_platform_info *plat_info)
{
	if (plat_info->dts_info.reg_vaddr[FFTS_KERNEL_BASE_REG] == NULL) {
		ffts_drv_err("kernel base vaddr error\n");
		return -1;
	}

	devm_iounmap(&pdev->dev, plat_info->dts_info.reg_vaddr[FFTS_KERNEL_BASE_REG]);
	plat_info->dts_info.reg_vaddr[FFTS_KERNEL_BASE_REG] = NULL;

	return 0;
}
