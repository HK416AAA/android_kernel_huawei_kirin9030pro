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

#ifndef AKMD_AAE_EXP_H
#define AKMD_AAE_EXP_H

#include <linux/types.h>

struct aae_manager;
int32_t aae_exp_handle(struct aae_manager *aae_mgr);
void mask_aae_dacc_isr(char __iomem *aae_base);
void umask_aae_dacc_isr(char __iomem *aae_base);

#endif /* AKMD_AAE_EXP_H */