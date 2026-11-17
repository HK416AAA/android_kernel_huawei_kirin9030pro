/*
 * ffts_lpid.c
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "ffts_lpid.h"
#include <linux/of.h>
#include "ffts_log.h"

int ffts_plat_parse_lpid(struct platform_device *pdev, struct ffts_platform_info *plat_info)
{
    int ret = of_property_read_u32(pdev->dev.of_node, "lpid_max", &plat_info->dts_info.lpid_max);
	ffts_drv_info("ffts max lpid %d\n", plat_info->dts_info.lpid_max);
	return ret;
}