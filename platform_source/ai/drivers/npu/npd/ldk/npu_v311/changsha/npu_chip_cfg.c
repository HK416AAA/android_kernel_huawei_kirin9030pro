/*
 * npu_chip_cfg.c
 *
 * about chip config
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/io.h>
#include <npu_shm_config.h>
#include "npu_log.h"
#include "npu_common.h"
#include "npu_platform.h"
#include "npu_atf_subsys.h"
#include "npu_adapter.h"
#include "soc_spec.h"
#include "npu_pm_internal.h"

static u32 eff_aic_disable_map = 0x3;

/*
 * return value : 1 support ispnn; 0 not support ispnn
 */
bool npu_plat_is_support_ispnn(void)
{
	return false;
}

/*
 * return value : 1 support sc; 0 not support sc
 */
bool npu_plat_is_support_sc(void)
{
	return true;
}

/*
 * return value : 0x1 | 0x2 disable core; 0x3 not disable core
 */
int npu_plat_aicore_get_disable_status(u32 core_id)
{
	unused(core_id);
	return eff_aic_disable_map;
}

/*
 * return value : NPU_NON_BYPASS, NPU_BYPASS
 */
int npu_plat_bypass_status(void)
{
#if defined(CONFIG_SOC_PG_INFO)
	struct soc_component_pg_info pg_pwr_info = {0};
	get_soc_pg_info_by_index(SOC_COMPONENT_NPU_PWR_CORE_INFO, &pg_pwr_info);

	npu_drv_warn("[SOC_PG_INFO]efuse_value[%u], tailor_strategy[%u]",
		pg_pwr_info.efuse_value, pg_pwr_info.tailor_strategy);

	switch (pg_pwr_info.tailor_strategy) {
		case SOC_COMPONENT_NOT_TAILOR_EFUSE_NONE:
			break;
		case SOC_COMPONENT_NOT_TAILOR:
			if ((pg_pwr_info.efuse_value & 0x1U) == 0 || (pg_pwr_info.efuse_value & 0x2U) == 0){
				npu_drv_err("[SOC_PG_INFO]invalid efuse_value, efuse_value[%u]", pg_pwr_info.efuse_value);
				return NPU_BYPASS;
			}
			break;
		case SOC_COMPONENT_TAILOR_STRATEGY_1:
			if ((pg_pwr_info.efuse_value & 0x1U) == 0x1U)
				eff_aic_disable_map = 0x2U;
			else if ((pg_pwr_info.efuse_value & 0x2U) == 0x2U)
				eff_aic_disable_map = 0x1U;
			else {
				npu_drv_err("[SOC_PG_INFO]invalid efuse_value, efuse_value[%u]", pg_pwr_info.efuse_value);
				return NPU_BYPASS;
			}
			npu_drv_warn("[SOC_PG_INFO]Soc is npu partial tailored, tailor core: %u", eff_aic_disable_map);
			break;
		case SOC_COMPONENT_TAILOR_STRATEGY_2:
			npu_drv_warn("[SOC_PG_INFO]npu plat bypass");
			return NPU_BYPASS;
		default:
			npu_drv_err("[SOC_PG_INFO]invalid strategy, tailor_strategy[%u]", pg_pwr_info.tailor_strategy);
			return NPU_BYPASS;
	}
#endif
	return NPU_NON_BYPASS;
}