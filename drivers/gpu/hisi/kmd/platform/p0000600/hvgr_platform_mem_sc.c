/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 */

#include "hvgr_platform_api.h"

#include <securec.h>

#include "hvgr_mem_api.h"
#include "hvgr_log_api.h"

#define SCS_BYPASS_EN_REG 0x118U
#define SCS_GID_REMAP_EN_REG 0x11CU

void hvgr_sc_enable_scs(struct hvgr_device *gdev)
{
	struct hvgr_scs_resource *scs_reg = &gdev->dm_dev.scs_reg;
	if (scs_reg->reg_base == NULL) {
		hvgr_err(gdev, HVGR_MEM, "%s scs reg_base is null", __func__);
		return;
	}

	writel(0U, (scs_reg->reg_base + SCS_BYPASS_EN_REG));
	writel(1U, (scs_reg->reg_base + SCS_GID_REMAP_EN_REG));
}

void hvgr_sc_init_remap_regs(struct hvgr_device *gdev)
{
	struct hvgr_sc_dev_data *sc_data = &gdev->mem_dev.sc_data;
	uint32_t remap_regs[SCS_REMAP_REG_NUM] = {
		0x3F3F3F00, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F0E0D3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x2B2A3F3F, 0x2F2E2D2C,
		0x33323130, 0x37363534, 0x3B3A3938, 0x3F3E3D3C, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
		0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F,
	};

	(void)memcpy_s(sc_data->remap_regs, (sizeof(uint32_t) * SCS_REMAP_REG_NUM), remap_regs,
		(sizeof(uint32_t) * SCS_REMAP_REG_NUM));
}

void hvgr_sc_store_remap_regs(struct hvgr_device *gdev)
{
	struct hvgr_scs_resource *scs_reg = &gdev->dm_dev.scs_reg;
	uint32_t addr;

	if (scs_reg->reg_base == NULL) {
		hvgr_err(gdev, HVGR_MEM, "%s scs reg_base is null", __func__);
		return;
	}

	for (addr = SCS_REMAP_REG_ADDR_START; addr <= SCS_REMAP_REG_ADDR_END; addr += 4U)
		gdev->mem_dev.sc_data.remap_regs[addr >> 2U] = readl(scs_reg->reg_base + addr);

	if (unlikely((gdev->mem_dev.sc_data.remap_regs[0] & (uint32_t)0xFFU) != 0)) {
		hvgr_err(gdev, HVGR_MEM, "%s scs v2p[0] err 0x%x",
			__func__, gdev->mem_dev.sc_data.remap_regs[0]);
		gdev->mem_dev.sc_data.remap_regs[0] &= (~(uint32_t)0xFFU);
	}
}

void hvgr_sc_recover_remap_regs(struct hvgr_device *gdev)
{
	struct hvgr_scs_resource *scs_reg = &gdev->dm_dev.scs_reg;
	uint32_t addr;

	if (scs_reg->reg_base == NULL) {
		hvgr_err(gdev, HVGR_MEM, "%s scs reg_base is null", __func__);
		return;
	}

	for (addr = SCS_REMAP_REG_ADDR_START; addr <= SCS_REMAP_REG_ADDR_END; addr += 4U)
		writel(gdev->mem_dev.sc_data.remap_regs[addr >> 2U],
			(scs_reg->reg_base + addr));
}
