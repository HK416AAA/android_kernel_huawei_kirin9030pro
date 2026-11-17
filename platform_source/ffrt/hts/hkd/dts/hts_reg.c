/*
 * hts_reg.c
 *
 * about hts platform
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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

#include "hts_reg.h"
#include <linux/irq.h>
#include <linux/irqchip/arm-gic-v3.h>
#include <linux/module.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <securec.h>
#include "hts_kernel_log.h"

void hts_plat_unmap_reg(struct platform_device *pdev,
	struct hts_platform_info *plat_info)
{
	int i;

	for (i = 0; i < HTS_REG_MAX_RESOURCE; i++) {
		if (plat_info->dts_info.reg_vaddr[i] == NULL) {
			continue;
		}
		devm_iounmap(&pdev->dev, plat_info->dts_info.reg_vaddr[i]);
	}
}

int hts_plat_map_reg(struct platform_device *pdev,
	struct hts_platform_info *plat_info)
{
	int i;
	void __iomem *base = NULL;
	struct hts_mem_desc *mem_desc = NULL;

	for (i = 0; i < HTS_REG_MAX_RESOURCE; i++) {
		mem_desc = &plat_info->dts_info.reg_desc[i];
		if (mem_desc->base == 0 || mem_desc->len == 0) {
			plat_info->dts_info.reg_vaddr[i] = NULL;
			continue;
		}

		base = devm_ioremap(&pdev->dev, mem_desc->base, mem_desc->len);
		if (base == NULL) {
			hts_drv_err("platform_get_resource failed i = %d\n", i);
			goto map_platform_reg_fail;
		}
		plat_info->dts_info.reg_vaddr[i] = base;
	}
	return 0;
map_platform_reg_fail:
	(void)memset_s(plat_info->dts_info.reg_desc, sizeof(plat_info->dts_info.reg_desc),
		0, sizeof(plat_info->dts_info.reg_desc));
	hts_plat_unmap_reg(pdev, plat_info);
	return -1;
}

int hts_plat_parse_reg_desc(struct platform_device *pdev,
	struct hts_platform_info *plat_info)
{
	unsigned int i;
	struct hts_mem_desc *mem_desc = NULL;
	struct resource *info = NULL;

	for (i = 0; i < HTS_REG_MAX_RESOURCE; i++) {
		info = platform_get_resource(pdev, IORESOURCE_MEM, i);
		if (info == NULL || info->end <= info->start) {
			hts_drv_err("info is invalid, i = %u\n", i);
			return -EINVAL;
		}
		mem_desc = &plat_info->dts_info.reg_desc[i];
		mem_desc->base = info->start;
		mem_desc->len = resource_size(info);
	}

	return 0;
}