/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts plat reg
 */
#ifndef _FFTS_REG_H_
#define _FFTS_REG_H_

#include <linux/types.h>
#include <linux/platform_device.h>
#include "ffts_platform.h"

int ffts_plat_parse_reg_desc(struct platform_device *pdev, struct ffts_platform_info *plat_info);
int ffts_plat_map_reg(struct platform_device *pdev, struct ffts_platform_info *plat_info);
int ffts_plat_unmap_reg(struct platform_device *pdev, struct ffts_platform_info *plat_info);

#endif