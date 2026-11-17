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

#ifndef __DISPLAY_ENGINE_INTERFACE_H__
#define __DISPLAY_ENGINE_INTERFACE_H__

#include "dkmd_lcd_interface.h"

/* The panel ID used to specify which panel would be configured.
 * And you can use DISPLAY_ENGINE_PANEL_INNER for single panel device.
 */

enum display_engine_panel_id {
    DISPLAY_ENGINE_PANEL_INVALID = -1,
    DISPLAY_ENGINE_PANEL_INNER,
    DISPLAY_ENGINE_PANEL_OUTER,
    DISPLAY_ENGINE_PANEL_COUNT,
};

struct edp_tp_safe {
	uint32_t tp_support;
	uint32_t tp_release_sfr_delay_time;
	uint32_t tp_safe_frame_rate;
};

int display_engine_get_param(void __user *argp);
int display_engine_set_param(void __user *argp);
int display_engine_update_frame_rate(const struct sfr_info *sfr_info);
int display_engine_init(void);
void tp_notify_display_engine(int val, int panel_id);

#endif