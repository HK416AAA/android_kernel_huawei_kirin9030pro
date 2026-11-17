/*
 * hts_reg.h
 *
 * about hts reg
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

#ifndef _HTS_REG_H_
#define _HTS_REG_H_
#include "hts_platform.h"
#include <linux/platform_device.h>


int hts_plat_parse_reg_desc(struct platform_device *pdev, struct hts_platform_info *plat_info);
void hts_plat_unmap_reg(struct platform_device *pdev, struct hts_platform_info *plat_info);
int hts_plat_map_reg(struct platform_device *pdev, struct hts_platform_info *plat_info);
#endif