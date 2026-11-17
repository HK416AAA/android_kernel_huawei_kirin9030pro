/* Copyright (c) Huawei Technologies Co., Ltd. 2026-2026. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
 
#ifndef __DPU_IMPROVE_YIELD_H__
#define __DPU_IMPROVE_YIELD_H__
 
#if defined(CONFIG_DFX_IMPROVE_YIELD) && defined(CONFIG_FACTORY_MODE)
#include <linux/types.h>

bool dpu_is_pv_flag_true(void);
int dpu_set_iy_nv_flag(void);
#endif
 
#endif /* __DPU_IMPROVE_YIELD_H__ */