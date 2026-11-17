/*
 * lcd_kit_bl_test.c
 *
 * display engine backlight test in lcdkit
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
 *
 */

#include "lcd_kit_bl_test.h"
#include "lcd_kit_adapt.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_disp.h"

void lcd_kit_parse_bl_test(int panel_id, struct device_node *np)
{
	/* panel bl test */
	LCD_KIT_INFO("DISPLAY_ENGINE_BL_TEST parse panel xml data");
	lcd_kit_parse_u32(np, "lcd-kit,backlight-test-support", &disp_info->bl_test.support, 0);
	if (!disp_info->bl_test.support)
		return;

	lcd_kit_parse_dcs_cmds(np, "lcd-kit,backlight-test-enter-cmds",
		"lcd-kit,backlight-test-enter-cmds-state", &disp_info->bl_test.enter_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,backlight-test-exit-cmds",
		"lcd-kit,backlight-test-exit-cmds-state", &disp_info->bl_test.exit_cmds);
}

void display_engine_set_bl_level(int panel_id, bool is_high_level)
{
	LCD_KIT_INFO("+\n");
	if (is_high_level)
		disp_info->bl_test.bl_test_flag = 1;
	else
		disp_info->bl_test.bl_test_flag = 0;
	LCD_KIT_INFO("-\n");
}

int display_engine_set_gamma_mode(int panel_id, bool is_bl_test)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	LCD_KIT_INFO("+\n");
	if (!disp_info->bl_test.support) {
		LCD_KIT_INFO("ap bl test not support\n");
		return LCD_KIT_FAIL;
	}
	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("mipi tx not support!\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->lcd_power_seq != LCD_KIT_POWER_ON)
		disp_info->bl_test.exit_cmds.async_param.sync_mode = MIPI_DSI_MODE_TRANS_SYNC;
	else 
		disp_info->bl_test.exit_cmds.async_param.sync_mode = MIPI_DSI_MODE_TRANS_ASYNC;

	if (is_bl_test) {
		disp_info->bl_test.bl_test_flag = 1;
		ret = adapt_ops->mipi_tx(panel_id, NULL, &disp_info->bl_test.enter_cmds);
	} else {
		disp_info->bl_test.bl_test_flag = 0;
		ret = adapt_ops->mipi_tx(panel_id, NULL, &disp_info->bl_test.exit_cmds);
	}

	if (ret != LCD_KIT_OK)
		LCD_KIT_ERR("mipi_tx failed! ret = %d\n", ret);
	LCD_KIT_INFO("-\n");
	return ret;
}
