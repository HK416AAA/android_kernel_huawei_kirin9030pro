/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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

#include <soc_spec_info.h>
#include <linux/of.h>
#include <linux/kernel.h>
#include <linux/of_device.h>
#include "dpu_comp_mgr.h"
#include "dkmd_log.h"
#include "dpu_config_utils.h"

typedef struct dpu_pg {
	char* name;
	bool bypass;
} dpu_spec_pg;

dpu_spec_pg dpu_spec_pg_info[] = {
	{.name = SOC_SPEC_LEVEL1_CDC_STR, .bypass = false},
	{.name = SOC_SPEC_LEVEL2_CDC_STR, .bypass = false},
	{.name = SOC_SPEC_LITE_CDC_STR, .bypass = false},
	{.name = SOC_SPEC_DESKTOP_PC_STR, .bypass = false},
	{.name = SOC_SPEC_PC_STR, .bypass = false},
	{.name = SOC_SPEC_PAD_PC_STR, .bypass = false},
	{.name = SOC_SPEC_LEVEL1_STR, .bypass = false},
};

dpu_spec_pg litedpu_spec_pg_info[] = {
	{.name = SOC_SPEC_LEVEL1_CDC_STR, .bypass = false},
	{.name = SOC_SPEC_LEVEL2_CDC_STR, .bypass = false},
	{.name = SOC_SPEC_LITE_CDC_STR, .bypass = false},
	{.name = SOC_SPEC_DESKTOP_PC_STR, .bypass = true},
	{.name = SOC_SPEC_PC_STR, .bypass = false},
	{.name = SOC_SPEC_PAD_PC_STR, .bypass = true},
	{.name = SOC_SPEC_LEVEL1_STR, .bypass = false},
};

bool composer_manager_v740_is_bypass_by_pg(void)
{
	const char *soc_spec = NULL;
	uint32_t index;
	bool bypass;

	struct device_node *np = of_find_compatible_node(NULL, NULL, "hisilicon, soc_spec");
	if (!np) {
		dpu_pr_err("no soc_spec dts node\n");
		return false;
	}

	if (of_property_read_string(np, "soc_spec_set", &soc_spec)) {
		dpu_pr_err("no soc_spec_set dts info\n");
		return false;
	}

	if (soc_spec == NULL) {
		dpu_pr_err("get pg type fail\n");
		return false;
	}

	dpu_pr_info("soc spec is %s:", soc_spec);
	for (index = 0; index < ARRAY_SIZE(dpu_spec_pg_info); index++) {
		if (strncmp(soc_spec, dpu_spec_pg_info[index].name, strlen(dpu_spec_pg_info[index].name)) == 0) {
			bypass = dpu_spec_pg_info[index].bypass;
			dpu_pr_info("Compare succ: dpu spec: %s, bypass flag: %d\n", dpu_spec_pg_info[index].name, bypass);
			break;
		}
	}

	if (index == ARRAY_SIZE(dpu_spec_pg_info)) {
		dpu_pr_err("unknown spec=%s, non bypass\n", soc_spec);
		bypass = false;
	}

	return bypass;
}

bool composer_manager_v741_is_bypass_by_pg(void)
{
	const char *soc_spec = NULL;
	uint32_t index;
	bool bypass;

	struct device_node *np = of_find_compatible_node(NULL, NULL, "hisilicon, soc_spec");
	if (!np) {
		dpu_pr_err("no soc_spec dts node\n");
		return false;
	}

	if (of_property_read_string(np, "soc_spec_set", &soc_spec)) {
		dpu_pr_err("no soc_spec_set dts info\n");
		return false;
	}

	if (soc_spec == NULL) {
		dpu_pr_err("get pg type fail\n");
		return false;
	}

	dpu_pr_info("soc spec is %s:", soc_spec);
	for (index = 0; index < ARRAY_SIZE(litedpu_spec_pg_info); index++) {
		if (strncmp(soc_spec, litedpu_spec_pg_info[index].name, strlen(litedpu_spec_pg_info[index].name)) == 0) {
			bypass = litedpu_spec_pg_info[index].bypass;
			dpu_pr_info("Compare succ: litedpu spec: %s, bypass flag: %d\n", litedpu_spec_pg_info[index].name, bypass);
			break;
		}
	}

	if (index == ARRAY_SIZE(litedpu_spec_pg_info)) {
		dpu_pr_err("unknown spec=%s, non bypass\n", soc_spec);
		bypass = false;
	}

	return bypass;
}