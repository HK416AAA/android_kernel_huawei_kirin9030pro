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

#ifndef AKMD_AAE_PIP_H
#define AKMD_AAE_PIP_H

#include "akmd_pip.h"

void aae_pip_setup(struct aae_pipeline_sw *pip_sw);
void aae_pip_release(struct aae_pipeline_sw *pip_sw);
int32_t aae_pip_parse_dt(struct aae_pipeline_sw *pip_sw, struct device_node *np);
int32_t aae_pip_init(struct aae_pipeline_sw **pip_sw);
void aae_pip_deinit(struct aae_pipeline_sw **pip_sw);
void aae_pip_close(struct aae_pipeline_sw *pip_sw);

#endif /* AKMD_AAE_PIP_H */
