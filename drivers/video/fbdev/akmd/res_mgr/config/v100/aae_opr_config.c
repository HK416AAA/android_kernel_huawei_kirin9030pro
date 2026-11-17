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

#include "aae_opr_config.h"

uint32_t g_aae_cld_offset[OPR_CLD_NUM] = {
	AAE_CLD0_OFFSET,
};

uint32_t g_aae_vscf_offset[OPR_VSCF_NUM] = {
	AAE_VSCF0_OFFSET,
};

uint32_t g_aae_arsr_offset[OPR_ARSR_NUM] = {
	AAE_INVALID_OFFSET, // AAE only use ARSR1;
	AAE_ARSR1_OFFSET
};