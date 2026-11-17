/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: Backlight Test.
 */

#ifndef __LCD_KIT_BL_TEST__
#define __LCD_KIT_BL_TEST__

#include <linux/kernel.h>
#include "lcd_kit_common.h"

void lcd_kit_parse_bl_test(int panel_id, struct device_node *np);
void display_engine_set_bl_level(int panel_id, bool is_high_level);
int display_engine_set_gamma_mode(int panel_id, bool is_bl_test);

#endif
