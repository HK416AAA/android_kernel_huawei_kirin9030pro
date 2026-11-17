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
#include "aae_dev_config.h"
#include "aae_cmdlist_cfg_prepare.h"

uint32_t build_ch7_cmdlist(void)
{
	uint32_t cmdlist_id;
	uint32_t cmdlist_dev_id;
	uint32_t init_cmdlist_id = INVALID_CMDLIST_ID;

    if (!cmdlist_is_ready(CMDLIST_DEV_ID_AAE)) {
        aae_pr_warn("The cmdlist of AAE is not ready, which id is %d ", CMDLIST_DEV_ID_AAE);
        return INVALID_CMDLIST_ID;
    }

	cmdlist_dev_id = CMDLIST_DEV_ID_AAE; // 0 is invalid
	/* 1. request initialize cmdlist scene id */
	init_cmdlist_id = cmdlist_create_user_client(cmdlist_dev_id,
		DPU_SCENE_INITAIL, SCENE_NOP_TYPE, 0, 0); // 0 is not invalid

	/* 2. prepare cmdlist buffer content */
	cmdlist_id = cmdlist_create_user_client(cmdlist_dev_id,
		DPU_SCENE_INITAIL, REGISTER_CONFIG_TYPE, 0, PAGE_SIZE);

	if (aae_enable_lp_flag()) {
		aae_clock_lp(cmdlist_id);
		aae_memory_lp(cmdlist_id);
	} else {
		aae_memory_no_lp(cmdlist_id);
	}

	aae_sdma_debug_init(cmdlist_id);
	cmdlist_append_client(cmdlist_dev_id, DPU_SCENE_INITAIL, init_cmdlist_id, cmdlist_id);
	cmdlist_flush_client(cmdlist_dev_id, DPU_SCENE_INITAIL, init_cmdlist_id);

#ifdef CONFIG_UKMD_DEBUG_ENABLE
	ukmd_cmdlist_dump_scene(cmdlist_dev_id, DPU_SCENE_INITAIL);
#endif
	return init_cmdlist_id;
}