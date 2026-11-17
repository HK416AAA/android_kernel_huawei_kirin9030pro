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

#include <platform_include/display/linux/dpu_drmdriver.h>
#include <platform_include/see/bl31_smc.h>
#include <aae/soc_aae_interface.h>
#include <aae/soc_dpu_define.h>
#include <ukmd_cmdlist.h>
#include "cmdlist_interface.h"
#include "akmd_log.h"
#include "aae_cmdlist_cfg_prepare.h"
#include "aae_xpu_proxy.h"

static uint32_t g_ch7_cmdlist_id = INVALID_CMDLIST_ID;

static dma_addr_t get_cmdlist_ch7_addr(void)
{
	uint32_t phy_addr_ch7;
	uint32_t cmdlist_dev_id;
	/* get dev id */
	cmdlist_dev_id = CMDLIST_DEV_ID_AAE;
	phy_addr_ch7 = ukmd_cmdlist_get_dma_addr(cmdlist_dev_id, DPU_SCENE_INITAIL, g_ch7_cmdlist_id);

	return phy_addr_ch7;
}

int32_t aae_cmd_prepare(void)
{
    uint32_t phy_addr_ch7;
	g_ch7_cmdlist_id = build_ch7_cmdlist();
	if (g_ch7_cmdlist_id == INVALID_CMDLIST_ID){
		aae_pr_warn("Invalid g_ch7_cmdlist_id %u",g_ch7_cmdlist_id);
		return -1;
	}
	phy_addr_ch7 = get_cmdlist_ch7_addr();
	configure_dss_service_security(AAE_SEC_CONFIG, phy_addr_ch7, AAE_SEC_CMDLIST_SET_CH7_ADDR, 0); // send ch7 address
	configure_dss_service_security(AAE_SEC_CONFIG, 0, AAE_SEC_CMDLIST_BUILD_CH8, 0); // build ch8 node
	
	return 0;
}

static void destroy_ch7_cmdlist(void)
{
	uint32_t dev_id = CMDLIST_DEV_ID_AAE;
	ukmd_cmdlist_release_locked(dev_id, DPU_SCENE_INITAIL, g_ch7_cmdlist_id);
}

void aae_cmd_destroy(void)
{
	destroy_ch7_cmdlist();
	configure_dss_service_security(AAE_SEC_CONFIG, 0, AAE_SEC_CLEAR_CMDLIST, 0);
	return ;
}