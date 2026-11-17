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

#ifndef AKMD_ISR_H
#define AKMD_ISR_H

#include "ukmd_isr.h"

#define AAE_DACC_LOG_BIT 14

enum {
	AAE_PIPE_CTRL3_NS_INT = BIT(8),
	AAE_PIPE_CTRL2_NS_INT = BIT(7),
	AAE_PIPE_CTRL1_NS_INT = BIT(6),
	AAE_PIPE_CTRL0_NS_INT = BIT(5),
	AAE_HDR_NS_INT = BIT(4),
	AAE_DACC_NS_INT = BIT(3),
	AAE_ROT_WDMA_NS_INT = BIT(2),
	AAE_SDMA0_NS_INT = BIT(1),
	AAE_CMDLIST_NS_INT = BIT(0),
};

enum {
	WCH_WDMA_END_INTS = BIT(4),
	WCH_BLK_END_INTS = BIT(10),
	WCH_FRM_END_INTS = BIT(11),
};

enum {
	AAE_DACC_LOG_INTS = BIT(AAE_DACC_LOG_BIT),
	WDT_RST_NS_INTS = BIT(16),
};

#endif /* AKMD_ISR_H */
