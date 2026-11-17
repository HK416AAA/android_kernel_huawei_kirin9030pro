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

#include <linux/of_address.h>
#include <linux/clk.h>
#include "akmd_log.h"
#include "aae_config_utils.h"

struct aae_config g_aae_config_data;

static void _config_get_ip_base(struct device_node *np, char  *ip_base_addrs[], uint32_t ip_count)
{
	uint32_t i;

	for (i = 0; i < ip_count; i++) {
		ip_base_addrs[i] = of_iomap(np, (int32_t)i);
		if (!ip_base_addrs[i])
			aae_pr_err("get ip %u base addr fail", i);

		aae_pr_debug("ip %u", i);
	}
}

static void _config_get_aae_version_value(struct device_node *np)
{
	int ret;
	uint32_t is_fpga = 0;

	ret = of_property_read_u32(np, "fpga_flag", &is_fpga);
	if (ret != 0)
		aae_pr_err("failed to get fpga_flag");

	g_aae_config_data.version.info.version = aae_config_get_version();
	g_aae_config_data.version.info.hw_type = (is_fpga == 0) ? AAE_HW_TYPE_ASIC : AAE_HW_TYPE_FPGA;
	aae_pr_debug("aae version 0x%llx", g_aae_config_data.version.value);
}

static void _config_get_dvfs_config(struct device_node *np)
{
	aae_pr_debug("+");

	g_aae_config_data.clk_gate_aae = of_clk_get(np, 0);

	if (IS_ERR(g_aae_config_data.clk_gate_aae))
		aae_pr_err("failed to get clk_gate_aae!");
}

static int32_t _config_get_scene_id_array(struct device_node *np, const char *node_name, uint32_t max_len,
	uint32_t *scene_ids, uint32_t len)
{
	uint32_t i;

	if (len < max_len) {
		aae_pr_err("scene_id array len=%u is smaller than %u", len, max_len);
		return -1;
	}

	for (i = 0; i < max_len; ++i) {
		if (of_property_read_u32_index(np, node_name, i, &scene_ids[i])) {
			aae_pr_info("read offline_scene_id fail");
			break;
		}
		aae_pr_info("get offline_scene_id %u", scene_ids[i]);
		++g_aae_config_data.offline_scene_id_count;
	}
	aae_pr_info("get offline_scene_id size=%u", g_aae_config_data.offline_scene_id_count);

	return 0;
}

static int32_t _config_get_offline_scene_id_array(struct device_node *np)
{
	return _config_get_scene_id_array(np, "offline_scene_id", DTS_OFFLINE_SCENE_ID_MAX,
		g_aae_config_data.offline_scene_ids, ARRAY_SIZE(g_aae_config_data.offline_scene_ids));
}

int32_t aae_res_init_config(struct platform_device *device)
{
	struct device_node *np = NULL;

	aae_assert(!device);

	np = device->dev.of_node;
	if (!np) {
		aae_pr_err("node of aae device is null");
		return -1;
	}

	_config_get_ip_base(np, g_aae_config_data.ip_base_addrs, AKMD_IP_MAX);
	_config_get_aae_version_value(np);
	_config_get_dvfs_config(np);
	return _config_get_offline_scene_id_array(np);
}
