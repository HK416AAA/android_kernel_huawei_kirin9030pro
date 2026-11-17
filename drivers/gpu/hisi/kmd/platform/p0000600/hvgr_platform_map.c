/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 */

#include "hvgr_platform_api.h"

#include <linux/of.h>
#include <linux/io.h>
#include <linux/errno.h>
#include "hvgr_mem_api.h"

#define GPU_FFAP1_DRAIN_TH_REG			0x1018U
#define GPU_FFPA1_DRAIN_TH_MASK			0xffffff00U
#define GPU_FFPA1_DRAIN_TH_TD_TH_VAL	0xffU

int hvgr_platform_map_reg_addr(struct platform_device *pdev, struct hvgr_device *gdev)
{
	struct hvgr_ffap1_resource *ffap1_reg = &gdev->dm_dev.ffap1_reg;
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	struct hvgr_scs_resource *scs_reg = &gdev->dm_dev.scs_reg;

	if (of_property_read_u32_array(gdev->dev->of_node, "scs-reg",
		(uint32_t *)scs_reg, HVGR_SCS_REG_PARA_NUM) != 0) {
		dev_err(gdev->dev, "Can't find gpu scs-reg register config");
		return 0;
	}

	scs_reg->reg_base = devm_ioremap(&pdev->dev, scs_reg->reg_start, scs_reg->reg_size);
	if (scs_reg->reg_base == NULL)
		dev_err(gdev->dev, "map scs-reg register failed");
#endif

	if (of_property_read_u32_array(gdev->dev->of_node, "ffap1-reg",
		(uint32_t *)ffap1_reg, HVGR_FFAP1_REG_PARA_NUM) != 0) {
		dev_err(gdev->dev, "Can't find gpu ffap1-reg register config");
		return 0;
	}

	ffap1_reg->reg_base = devm_ioremap(&pdev->dev, ffap1_reg->reg_start, ffap1_reg->reg_size);
	if (ffap1_reg->reg_base == NULL)
		dev_err(gdev->dev, "map ffap1-reg register failed");

	return 0;
}

void hvgr_platform_set_ffap1_drain_th(struct hvgr_device *gdev)
{
	struct hvgr_ffap1_resource *ffap1_reg = &gdev->dm_dev.ffap1_reg;
	uint32_t val;

	if (ffap1_reg->reg_base == NULL) {
		dev_err(gdev->dev, "ffap1-reg register is NULL");
		return;
	}

	val = readl(ffap1_reg->reg_base + GPU_FFAP1_DRAIN_TH_REG);
	val &= GPU_FFPA1_DRAIN_TH_MASK;
	val |= GPU_FFPA1_DRAIN_TH_TD_TH_VAL;
	writel(val, (ffap1_reg->reg_base + GPU_FFAP1_DRAIN_TH_REG));

	return;
}