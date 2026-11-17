/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef AAE_OPR_CONFIG_H
#define AAE_OPR_CONFIG_H

#include <linux/types.h>
#include <aae/dpu_dm.h>

extern uint32_t g_aae_cld_offset[OPR_CLD_NUM];
extern uint32_t g_aae_vscf_offset[OPR_VSCF_NUM];
extern uint32_t g_aae_arsr_offset[OPR_ARSR_NUM];

#endif