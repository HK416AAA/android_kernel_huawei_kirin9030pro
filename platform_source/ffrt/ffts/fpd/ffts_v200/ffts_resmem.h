 /*
 * ffts_resmem.c
 *
 * ffts resmem
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
#ifndef _FFTS_RESMEM_H_
#define _FFTS_RESMEM_H_

#include <linux/types.h>

#include "ffts_platform.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"

void ffts_plat_get_resmem_info(struct ffts_platform_info *plat_info);

#endif