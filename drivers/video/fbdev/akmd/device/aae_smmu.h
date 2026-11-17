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

#ifndef AKMD_AAE_SMMU_H
#define AKMD_AAE_SMMU_H

#include <linux/types.h>

struct aae_pipeline_sw;

void aae_pip_smmu_tlb_flush(uint32_t scene_id, uint32_t block_num);

void aae_pip_smmuv3_on(struct aae_pipeline_sw *pip_sw);
void aae_pip_smmuv3_off(struct aae_pipeline_sw *pip_sw);

int32_t aae_tbu_connect(char __iomem *aae_base);
int32_t aae_tbu_disconnect(char __iomem *aae_base);
#endif
