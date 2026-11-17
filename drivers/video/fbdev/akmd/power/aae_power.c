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

#include <linux/delay.h>
#include <linux/regulator/consumer.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#include <platform_include/see/bl31_smc.h>
#include <aae/soc_dpu_define.h>
#include <soc_media_pmctrl_interface.h>
#include <soc_media1_ctrl_interface.h>
#include <soc_media1_crg_interface.h>

#include "aae_power.h"
#include "dacc_aae.h"
#include "aae_gfx.h"
#include "aae_isr.h"
#include "aae_manager.h"
#include "aae_pip.h"
#include "aae_pip_hw.h"
#include "dvfs/aae_dvfs.h"
#include "akmd_log.h"
#include "ukmd_utils.h"
#include "aae_smmu.h"

int32_t aae_regulator_enable(struct aae_manager *aae_mgr)
{
	int32_t ret = 0;

	aae_pr_debug("+");
	if (IS_ERR_OR_NULL(aae_mgr->aae_regulator))
		return -1;

	mutex_lock(&aae_mgr->vote_pw_lock);

	if (aae_mgr->vote_pw_refcount == 0)
		ret = regulator_enable(aae_mgr->aae_regulator);
	if (ret) {
		aae_pr_err("aae_regulator enable failed, error=%d!", ret);
	} else {
		aae_mgr->vote_pw_refcount++;
	}

	mutex_unlock(&aae_mgr->vote_pw_lock);
	aae_pr_debug("-");
	return ret;
}

int32_t aae_regulator_disable(struct aae_manager *aae_mgr)
{
	int32_t ret = 0;

	aae_pr_debug("+");
	if (IS_ERR_OR_NULL(aae_mgr->aae_regulator))
		return -1;

	mutex_lock(&aae_mgr->vote_pw_lock);

	if (aae_mgr->vote_pw_refcount == 1)
		ret = regulator_disable(aae_mgr->aae_regulator);
	if (ret) {
		aae_pr_err("aae_regulator disable failed, error=%d!", ret);
	} else if (aae_mgr->vote_pw_refcount > 0) {
		aae_mgr->vote_pw_refcount--;
	}

	mutex_unlock(&aae_mgr->vote_pw_lock);
	aae_pr_debug("-");
	return ret;
}

void aae_hw_power_on(struct aae_manager *aae_mgr, struct aae_pipeline_sw *pip_sw)
{
	aae_pr_debug("+");

	aae_dvfs_enable_core_clock();
	aae_dvfs_vote_level(pip_sw->index, AAE_CLK_LEVEL_ON, false, false);
	aae_regulator_enable(aae_mgr);
	aae_dvfs_qos_qic_media1_config(AAE_CLK_LEVEL_ON);

	/* Cmdlist preparation, need to use the CPU configuration */
	set_reg(AAE_GLB_PART0_AAE_PM_CTRL_ADDR(aae_mgr->aae_base + AAE_GLB0_OFFSET), GLB_PM_CTRL_VALUE, 32, 0);

	set_reg(AAE_SDMA_DBG_CTRL0_ADDR(aae_mgr->aae_base + AAE_SDMA_OFFSET, 0), 1, 1, 20);
	aae_pr_debug("-");
}

void aae_hw_power_off(struct aae_manager *aae_mgr, struct aae_pipeline_sw *pip_sw)
{
	aae_regulator_disable(aae_mgr);
	aae_dvfs_vote_level(pip_sw->index, AAE_CLK_LEVEL_OFF, false, true);
	aae_dvfs_disable_core_clock();
}

static void media_regulator_enable(struct aae_manager *aae_mgr)
{
	int32_t ret = 0;

	aae_pr_debug("+");
	ret = regulator_enable(aae_mgr->media1_subsys_regulator);
	if (ret)
		aae_pr_err("regulator enable media1_subsys failed, error=%d!", ret);

	ret = regulator_enable(aae_mgr->vivobus_regulator);
	if (ret)
		aae_pr_err("regulator enable vivobus failed, error=%d!", ret);
	aae_pr_debug("-");
}

static void media_regulator_disable(struct aae_manager *aae_mgr)
{
	int32_t ret = 0;

	aae_pr_debug("+");

	ret = regulator_disable(aae_mgr->media1_subsys_regulator);
	if (ret)
		aae_pr_err("regulator enable media1_subsys failed, error=%d!", ret);

	ret = regulator_disable(aae_mgr->vivobus_regulator);
	if (ret)
		aae_pr_err("regulator enable vivobus failed, error=%d!", ret);

	aae_pr_debug("-");
}

static int32_t aae_power_on_no_lock(struct aae_pipeline_sw *pip_sw)
{
	struct aae_manager *aae_mgr = pip_sw->aae_mgr;
	aae_assert(!aae_mgr);

	aae_pr_info("power_status=0x%llx pip=%u enter", aae_mgr->power_status.status, pip_sw->index);

	if (pip_sw->power_on) {
		aae_mgr->power_status.refcount.value[pip_sw->index]++;
		aae_pr_info("aae pip has already power up! power_status=0x%llx pip=%u ",
			aae_mgr->power_status.status, pip_sw->index);
		up(&pip_sw->sem);
		return 0;
	}

	if (aae_mgr->power_status.status == 0) {
		media_regulator_enable(aae_mgr);
		aae_hw_power_on(aae_mgr, pip_sw);
		dacc_aae_load();

		aae_glb_isr_enable(aae_mgr);
		aae_pip_isr_enable(pip_sw);
		aae_pip_smmuv3_on(pip_sw);
		aae_pip_hw_setup(pip_sw);
	} else {
		aae_pr_info("aae has already power up! power_status=0x%llx pip=%u",
			aae_mgr->power_status.status, pip_sw->index);
		if (aae_mgr->power_status.refcount.value[pip_sw->index] == 0) {
			aae_pip_isr_enable(pip_sw);
			aae_pip_smmuv3_on(pip_sw);
		}
	}

	aae_mgr->power_status.refcount.value[pip_sw->index]++;
	pip_sw->power_on = true;
	
	aae_pr_info("power_status=0x%llx pip=%u exit", aae_mgr->power_status.status, pip_sw->index);
	return 0;
}

static int32_t aae_power_off_no_lock(struct aae_pipeline_sw *pip_sw)
{
	struct aae_manager *aae_mgr = pip_sw->aae_mgr;
	aae_assert(!aae_mgr);

	if (!g_debug_aae_power_off_enable)
		return 0;

	aae_pr_info("power_status=0x%llx pip=%u enter", aae_mgr->power_status.status, pip_sw->index);

	if (unlikely(!pip_sw->power_on))
		return 0;

	if (aae_mgr->power_status.refcount.value[pip_sw->index] == 1) {
		aae_pip_isr_disable(pip_sw);
		aae_pip_smmuv3_off(pip_sw);

		aae_mgr->power_status.refcount.value[pip_sw->index]--;
		if (aae_mgr->power_status.status == 0) {
			aae_glb_isr_disable(aae_mgr);
			aae_hw_power_off(aae_mgr, pip_sw);
			media_regulator_disable(aae_mgr);
		}
	} else {
		if (aae_mgr->power_status.refcount.value[pip_sw->index] != 0) {
			aae_mgr->power_status.refcount.value[pip_sw->index]--;
			aae_pr_info("aae pip=%u set too many power down, refcount %hhu!", pip_sw->index,
				aae_mgr->power_status.refcount.value[pip_sw->index]);
		}
	}

	pip_sw->power_on = false;
	aae_pr_info("power_status=0x%llx exit", aae_mgr->power_status.status);
	return 0;
}

void aae_power_restart_no_lock(struct aae_pipeline_sw *pip_sw)
{
	struct aae_manager *aae_mgr = pip_sw->aae_mgr;
	struct aae_pipeline_sw *pipeline_sw = NULL;
	uint32_t index;
	int32_t ret;
	bool power_status[AAE_PIP_MAX] = {false};

	aae_pr_warn("index=%u enter", pip_sw->index);
	for (index = 0; index < AAE_PIP_MAX; index++) {
		pipeline_sw = aae_mgr->pip_sws[index];
		if (!pipeline_sw || !pipeline_sw->power_on)
			continue;
		ret = aae_power_off_no_lock(pipeline_sw);
		if (ret)
			continue;
		power_status[index] = true;
	}

	for (index = 0; index < AAE_PIP_MAX; index++) {
		pipeline_sw = aae_mgr->pip_sws[index];
		if (!pipeline_sw)
			continue;
		if (power_status[index]) {
			ret = aae_power_on_no_lock(pipeline_sw);
			if (ret)
				aae_pr_err("power on failed index=%u", index);
		}
	}
	aae_pr_warn("index=%u exit", pip_sw->index);
}

static void aae_reset_hardware(struct aae_pipeline_sw *pip_sw)
{
	aae_power_restart_no_lock(pip_sw);
	aae_pr_warn("reset hardware finished!");
}

void aae_power_set_up(struct aae_pipeline_sw *pip_sw)
{
	aae_assert(!pip_sw);

	pip_sw->on_func_no_lock = aae_power_on_no_lock;
	pip_sw->off_func_no_lock = aae_power_off_no_lock;
	pip_sw->reset_func = aae_reset_hardware;
}
