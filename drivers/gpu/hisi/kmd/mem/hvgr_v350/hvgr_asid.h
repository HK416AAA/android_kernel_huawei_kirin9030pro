/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_ASID_H
#define HVGR_ASID_H

#include "hvgr_defs.h"

void hvgr_alloc_normal_static_asid(struct hvgr_ctx * ctx, uint32_t ssid);

uint32_t hvgr_alloc_ffrt_asid(struct hvgr_ctx *ctx);

void hvgr_release_asid(struct hvgr_ctx * ctx);

#endif