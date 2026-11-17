/*
 * hts_atf.h
 *
 * hpd atf head file
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

#ifndef _HTS_TZSP_H_
#define _HTS_TZSP_H_

#include <linux/types.h>
#include <ffa_plat_drv.h>

#define FFRT_OK                 0
#define FFRT_ALREADY_POWERUP    1

noinline int tzsp_service_hts_smc(uint64_t _service_id, uint64_t _cmd, uint64_t _arg1, uint64_t _arg2);

#endif