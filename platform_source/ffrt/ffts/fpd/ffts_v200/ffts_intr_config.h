/*
 * ffts_intr_config.c
 *
 * ffts interrupt config
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
#ifndef _FFTS_INTR_CONFIG_H_
#define _FFTS_INTR_CONFIG_H_

#include <linux/types.h>
#include "ffts_interrupt.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"

int ffts_normal_intr_work(struct ffts_intr_info *intr_info, uint32_t st);
int ffts_add_normal_intr_workqueue(struct ffts_intr_info *intr_info);

int ffts_abnormal_intr_work(struct ffts_intr_info *intr_info, uint32_t st);
int ffts_add_abnormal_intr_workqueue(struct ffts_intr_info *intr_info);

void ffts_cancel_abnormal_by_uid(u16 uid);

#endif