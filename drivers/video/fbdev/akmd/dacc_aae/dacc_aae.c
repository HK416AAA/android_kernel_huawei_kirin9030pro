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

#include <aae/soc_dpu_define.h>
#if defined(CONFIG_DRMDRIVER)
#include <platform_include/see/bl31_smc.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#endif
#include "dacc_aae.h"
#include "ukmd_utils.h"
#include "akmd_log.h"


#define DACC_CRG_CTL_CLEAR_TIMEOUT_THR 17 // 16ms

void dacc_aae_load(void)
{
	aae_pr_debug("+");
#if defined(CONFIG_DRMDRIVER)
	/* send cmd to bl31 or tzsp for aacc load */
	configure_dss_service_security(DSS_CH_DEFAULT_SEC_CONFIG, AAE_ACC, 0, 0);
	aae_pr_debug("-");
#endif
}

void dacc_aae_config_scene(char __iomem *aae_base, uint32_t scene_id, bool enable_cmdlist)
{
	char __iomem *dmc_base = aae_base + DACC_AAE_OFFSET + DMC_OFFSET;

	set_reg(SOC_DACC_AAE_CLK_SEL_REG_ADDR(dmc_base, scene_id), 1, 1, 0);
	set_reg(SOC_DACC_AAE_CLK_EN_REG_ADDR(dmc_base, scene_id), 1, 1, 0);
	set_reg(SOC_DACC_AAE_CTL_CFG_MODE0_ADDR(dmc_base, scene_id), (uint32_t)enable_cmdlist, 1, 0);
	set_reg(SOC_DACC_AAE_NEW_FRAME_RDY_CFG_ADDR(dmc_base, scene_id), 1, 1, 0);
}

uint32_t dacc_aae_handle_clear(char __iomem *aae_base, uint32_t scene_id)
{
	void_unused(aae_base);
	void_unused(scene_id);
	return 0;
}