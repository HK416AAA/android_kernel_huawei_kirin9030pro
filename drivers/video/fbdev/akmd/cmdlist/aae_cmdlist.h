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

#ifndef AKMD_AAE_CMDLIST_H
#define AKMD_AAE_CMDLIST_H

#include <linux/types.h>

void aae_cmdlist_init_commit(char __iomem *aae_base, dma_addr_t cmdlist_buf_addr);
void aae_cmdlist_pip_commit(char __iomem *aae_base, uint32_t scene_id, uint32_t cmdlist_id);

void cmdlist_init(char __iomem *aae_base);

#endif