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

#ifndef AKMD_AAE_POWER_H
#define AKMD_AAE_POWER_H

#include <linux/types.h>

struct aae_pipeline_sw;
struct aae_manager;
void aae_power_set_up(struct aae_pipeline_sw *pip_sw);
int32_t aae_regulator_enable(struct aae_manager *aae_mgr);
int32_t aae_regulator_disable(struct aae_manager *aae_mgr);

#endif /* AAE_POWER_H */
