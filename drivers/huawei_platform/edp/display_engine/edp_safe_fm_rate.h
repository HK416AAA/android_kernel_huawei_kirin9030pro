/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
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
 
#ifndef __EDP_SAFE_FRM_RATE_
#define __EDP_SAFE_FRM_RATE_

#include "display_engine_info.h"
#include "dkmd_lcd_interface.h"
#include "dkmd_dfr_interface.h"

int display_engine_set_safe_frame_rate(struct display_engine_param* de_param);
int edp_safe_frame_rate_ctrl(const struct sfr_info *sfr_info);
int edp_safe_frame_rate_init(void);
void edp_tp_notify_de_event(int val, int panel_id);

#endif