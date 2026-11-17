/*
 * drv_venc_mcore.h
 *
 * This is for Operations Related to mcore.
 *
 * Copyright (c) 2021-2021 Huawei Technologies CO., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _DRV_VENC_MCU_H_
#define _DRV_VENC_MCU_H_

#include <linux/types.h>
#include "drv_common.h"

int32_t venc_mcore_open(bool last_power_off_by_rt);
void venc_mcore_close(bool power_off_by_rt);
void venc_mcore_log_dump(void);
int32_t venc_mcore_alloc_ddr(struct platform_device *pdev);
void venc_mcore_free_ddr(struct platform_device *pdev);
bool venc_check_mcore_wfi(void);
#endif