// SPDX-License-Identifier: GPL-2.0
/*
 * bq40z50_low_vol_check.h
 *
 * bq40z50 low voltage driver
 *
 * Copyright (c) 2026-2026 Huawei Technologies Co., Ltd.
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

#ifndef _BQ40Z50_LOW_VOL_CHECK_H_
#define _BQ40Z50_LOW_VOL_CHECK_H_

#include "bq40z50.h"

#define LOW_INT_TEMP_THRED          (-50) /* -5 */
#define NORMAL_CUTOFF_VOLT_MAX      3500 /* 3.5V */
#define LOW_VOL_DELAY_NORMAL        (30 * 1000)
#define LOW_VOL_DELAY_UNDER_CUTOFF  1000

void bq40z50_low_vol_check_work(struct bq40z50_device_info *di);

#endif /* _BQ40Z50_LOW_VOL_CHECK_H_ */