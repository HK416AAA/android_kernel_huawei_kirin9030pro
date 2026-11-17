/*
 * ffts_irq.c
 *
 * ffts irq
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
#include "ffts_irq.h"

#include <linux/irq.h>
#include <linux/interrupt.h>

#include "ffts_log.h"
#include "ffts_interrupt.h"

int ffts_plat_parse_irq(struct platform_device *pdev, struct ffts_platform_info *plat_info)
{
	plat_info->dts_info.irq_normal = platform_get_irq(pdev, FFTS_IRQ_NORMAL);
	ffts_drv_info("ffts normal irq %d\n", plat_info->dts_info.irq_normal);
	cond_return_error(plat_info->dts_info.irq_normal < 0,
		-EINVAL, "get normal irq fail %d\n", plat_info->dts_info.irq_normal);

	plat_info->dts_info.irq_abnormal = platform_get_irq(pdev, FFTS_IRQ_ABNORMAL);
	ffts_drv_info("ffts abnormal irq  %d\n", plat_info->dts_info.irq_abnormal);
	cond_return_error(plat_info->dts_info.irq_abnormal < 0,
		-EINVAL, "get abnormal irq fail %d\n", plat_info->dts_info.irq_abnormal);
	return 0;
}
