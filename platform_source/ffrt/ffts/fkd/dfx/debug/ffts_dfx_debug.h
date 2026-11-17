/*
 * ffts_dfx_debug.h
 *
 * about ffts dfx debug
 *
 * Copyright (c) 2012-2023 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef __FFTS_DFX_DEBUG_H
#define __FFTS_DFX_DEBUG_H

#include "ffts_common.h"

void ffts_debug_info_init(void);
void ffts_debug_info_deinit(void);

uint32_t ffts_get_debug_info(u16 debug_cfg_addr, u16 debug_info_index);
void ffts_get_whole_debug_info(u16 debug_cfg_addr, u32 *debug_info);

#endif /* __FFTS_DFX_DEBUG_H */
