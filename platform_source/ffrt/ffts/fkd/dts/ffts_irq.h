/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts irq
 */
#ifndef _FFTS_IRQ_H_
#define _FFTS_IRQ_H_

#include <linux/types.h>
#include <linux/platform_device.h>
#include "ffts_platform.h"

int ffts_plat_parse_irq(struct platform_device *pdev, struct ffts_platform_info *plat_info);

#endif