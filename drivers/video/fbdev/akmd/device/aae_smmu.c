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
#if defined(CONFIG_DRMDRIVER)
#include <platform_include/see/bl31_smc.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#endif
#include <soc_smmuv3_tbu_interface.h>
#include <aae/soc_dpu_define.h>
#include <aae/dpu_smmu.h>
#include <aae/soc_aae_interface.h>
#include <linux/iommu/mm_iommu.h>
#include "aae_manager.h"
#include "aae_pip.h"
#include "ukmd_utils.h"
#include "aae_config_utils.h"
#include "aae_res_mgr.h"
#include "akmd_log.h"

#define SMMU_TIMEOUT 1000   /* us */
#define AAE_TBU1_DTI_NUMS 0x0F
#define AAE_SSID_MAX_NUM 3

enum smmu_event {
	TBU_DISCONNECT = 0x0,
	TBU_CONNECT = 0x1,
};

static int32_t g_tbu_sr_refcount;

typedef bool (*smmu_event_cmp)(uint32_t value, uint32_t expect_value);

static bool aae_smmu_connect_event_cmp(uint32_t value, uint32_t expect_value)
{
	return (value & 0x3) == 0x3;
}

static bool aae_smmu_disconnect_event_cmp(uint32_t value, uint32_t expect_value)
{
	void_unused(expect_value);
	return (value & 0x3) == 0x1;
}

static int32_t aae_smmu_event_request(char __iomem *smmu_base,
	smmu_event_cmp cmp_func, enum smmu_event event, uint32_t check_value)
{
	uint32_t smmu_tbu_crack;
	uint32_t delay_count = 0;

	/* request event config */
	set_reg(SOC_SMMUv3_TBU_SMMU_TBU_CR_ADDR(smmu_base), check_value, 8, 8);
	set_reg(SOC_SMMUv3_TBU_SMMU_TBU_CR_ADDR(smmu_base), event, 1, 0);

	/* check ack */
	do {
		smmu_tbu_crack = inp32(SOC_SMMUv3_TBU_SMMU_TBU_CRACK_ADDR(smmu_base));
		if (cmp_func(smmu_tbu_crack, check_value))
			break;

		udelay(1);
		delay_count++;
	} while (delay_count < SMMU_TIMEOUT);

	if (delay_count == SMMU_TIMEOUT) {
		aae_pr_warn("smmu ack timeout, smmu=0x%x event=%d smmu_tbu_crack=0x%x check_value=0x%x!",
			smmu_base, event, smmu_tbu_crack, check_value);
		return -1;
	}
	return 0;
}

void aae_pip_smmuv3_on(struct aae_pipeline_sw *pip_sw)
{
	char __iomem *tbu_base = NULL;
	struct aae_manager *aae_mgr = NULL;

	aae_assert(!pip_sw);

	if (aae_is_smmu_bypass()) {
		aae_pr_info("aae smmu bypass");
		return;
	}

	aae_mgr = pip_sw->aae_mgr;
	mutex_lock(&aae_mgr->tbu_sr_lock);
	if (g_tbu_sr_refcount == 0) {
		tbu_base = aae_mgr->aae_base + AAE_SMMU_OFFSET;
		#if defined(CONFIG_DRMDRIVER)
			configure_dss_service_security(DSS_SMMU_INIT, 0, 4, AAE_ACC);
		#endif
			aae_smmu_event_request(tbu_base, aae_smmu_connect_event_cmp, TBU_CONNECT, AAE_TBU1_DTI_NUMS);
	}

	g_tbu_sr_refcount++;
	aae_pr_info("tbu_sr_refcount=%d", g_tbu_sr_refcount);

	mutex_unlock(&aae_mgr->tbu_sr_lock);
}

void aae_pip_smmuv3_off(struct aae_pipeline_sw *pip_sw)
{
	struct aae_manager *aae_mgr = NULL;

	aae_assert(!pip_sw);

	if (aae_is_smmu_bypass()) {
		aae_pr_info("aae smmu bypass");
		return;
	}

	aae_mgr = pip_sw->aae_mgr;

	mutex_lock(&aae_mgr->tbu_sr_lock);
	g_tbu_sr_refcount--;
	if (g_tbu_sr_refcount == 0)
		aae_smmu_event_request(aae_mgr->aae_base + AAE_SMMU_OFFSET,
			aae_smmu_disconnect_event_cmp, TBU_DISCONNECT, 0);

	aae_pr_info("tbu_sr_refcount=%d", g_tbu_sr_refcount);

	mutex_unlock(&aae_mgr->tbu_sr_lock);
}

void aae_pip_smmu_tlb_flush(uint32_t scene_id, uint32_t block_num)
{
	uint32_t i = 0;
	uint32_t mmu_id = scene_id * AAE_SSID_MAX_NUM;

	if (aae_is_smmu_bypass()) {
		aae_pr_debug("aae smmu bypass");
		return;
	}

	for (; i < block_num; ++i) {
		mm_iommu_dev_flush_tlb(aae_res_get_device(), mmu_id + i);
		aae_pr_debug("scene_id=%u block_num=%u flush mmu_id=0x%x", scene_id, block_num, mmu_id + i);
	}
}

int32_t aae_tbu_connect(char __iomem *aae_base)
{
	int32_t ret = 0;
	aae_check_and_return(!aae_base, -1, err, "aae_base is null!");
	/* cmdlist select srt0 */
	set_reg(AAE_DBCU_CMDLIST_AXI_SEL_ADDR(aae_base + AAE_DBCU_OFFSET), 0x1, 2, 0);
	set_reg(AAE_DBCU_MMU0_ID_ATTR_NS_ADDR(aae_base + AAE_DBCU_OFFSET), 0x3F, 32, 0);
	set_reg(AAE_DBCU_AIF_CMD_RELOAD_ADDR(aae_base + AAE_DBCU_OFFSET), 0x1, 1, 0);
	#if defined(CONFIG_DRMDRIVER)
		configure_dss_service_security(DSS_SMMU_INIT, 0, 4, AAE_ACC);
	#endif
	ret = aae_smmu_event_request(aae_base + AAE_SMMU_OFFSET, aae_smmu_connect_event_cmp, TBU_CONNECT, AAE_TBU1_DTI_NUMS);
	if (ret != 0) {
		aae_pr_err("aae tbu connect failed!");
		return -1;
	}

	aae_pr_debug("aae tbu connect success");
	return 0;
}

int32_t aae_tbu_disconnect(char __iomem *aae_base)
{
	int32_t ret = 0;
	aae_check_and_return(!aae_base, -1, err, "aae_base is null!");
	ret = aae_smmu_event_request(aae_base + AAE_SMMU_OFFSET,
			aae_smmu_disconnect_event_cmp, TBU_DISCONNECT, 0);
	if (ret != 0) {
		aae_pr_err("aae tbu disconnect failed!");
		return -1;
	}
	aae_pr_debug("aae tbu disconnect success");
	return 0;
}