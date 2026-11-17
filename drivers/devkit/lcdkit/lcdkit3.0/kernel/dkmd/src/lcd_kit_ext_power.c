/*
 * lcd_kit_ext_power.c
 *
 * lcdkit power function for lcd driver
 *
 * Copyright (c) 2019-2020 Huawei Technologies Co., Ltd.
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

#include "lcd_kit_disp.h"
#include "lcd_kit_power.h"
#include "lcd_kit_common.h"
#include "lcd_kit_ext_power.h"

#define MAX_WAIT_POWER_OFF_TIME 500

/* global gpio */
uint32_t g_lcd_kit_gpio_plugin;
struct completion power_off_done;
struct lcd_pwr_off_optimize_config g_pwr_off_optimize_cfg;

/* gpio power */
static struct gpio_desc gpio_req_cmds[] = {
	{
		DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_NAME, &g_lcd_kit_gpio_plugin, 0
	},
};

static struct gpio_desc gpio_low_cmds[] = {
	{
		DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
		GPIO_NAME, &g_lcd_kit_gpio_plugin, 0
	},
};

static struct gpio_desc gpio_high_cmds[] = {
	{
		DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
		GPIO_NAME, &g_lcd_kit_gpio_plugin, 1
	},
};

static struct gpio_desc gpio_free_cmds[] = {
	{
		DTYPE_GPIO_FREE, WAIT_TYPE_US, 0,
		GPIO_NAME, &g_lcd_kit_gpio_plugin, 0
	},
};

static struct gpio_power_arra gpio_power_plugin[] = {
	{ GPIO_REQ, ARRAY_SIZE(gpio_req_cmds), gpio_req_cmds },
	{ GPIO_HIGH, ARRAY_SIZE(gpio_high_cmds), gpio_high_cmds },
	{ GPIO_LOW, ARRAY_SIZE(gpio_low_cmds), gpio_low_cmds },
	{ GPIO_FREE, ARRAY_SIZE(gpio_free_cmds), gpio_free_cmds },
};

void wait_power_off_done(int panel_id)
{
	int working_flag = g_pwr_off_optimize_cfg.working_flag;

	if (!disp_info->pwr_off_optimize_info.support)
		return;

	if (working_flag == panel_id + true) {
		LCD_KIT_INFO("power off completion\n");
		reinit_completion(&power_off_done);
		if (!wait_for_completion_timeout(&power_off_done,
			msecs_to_jiffies(MAX_WAIT_POWER_OFF_TIME))) {
			cancel_delayed_work(&g_pwr_off_optimize_cfg.pwr_off_optimize_work);
			g_pwr_off_optimize_cfg.working_flag = false;
			LCD_KIT_ERR("wait power off done time out!\n");
		}
	}
}

int lcd_kit_get_pwr_off_opt_work_flag(int panel_id)
{
	if (!disp_info->pwr_off_optimize_info.support)
		return LCD_KIT_OK;
	return g_pwr_off_optimize_cfg.working_flag;
}

static void lcd_kit_get_gpio_num(uint32_t type)
{
	switch (type) {
	case LCD_KIT_VCI:
		g_lcd_kit_gpio_plugin = g_pwr_off_optimize_cfg.lcd_vci->buf[POWER_NUM];
		break;
	case LCD_KIT_IOVCC:
		g_lcd_kit_gpio_plugin = g_pwr_off_optimize_cfg.lcd_iovcc->buf[POWER_NUM];
		break;
	case LCD_KIT_RST:
		g_lcd_kit_gpio_plugin = g_pwr_off_optimize_cfg.lcd_rst->buf[POWER_NUM];
		break;
	case LCD_KIT_VDD:
		g_lcd_kit_gpio_plugin = g_pwr_off_optimize_cfg.lcd_vdd->buf[POWER_NUM];
		break;
	case LCD_KIT_PMIC_CTRL:
		g_lcd_kit_gpio_plugin = g_pwr_off_optimize_cfg.lcd_pmic_ctrl->buf[POWER_NUM];
		break;
	case LCD_KIT_PMIC_RESET:
		g_lcd_kit_gpio_plugin = g_pwr_off_optimize_cfg.lcd_pmic_reset->buf[POWER_NUM];
		break;
	case LCD_KIT_INTEG_EN:
		g_lcd_kit_gpio_plugin = g_pwr_off_optimize_cfg.lcd_integ_en->buf[POWER_NUM];
		break;
	default:
		LCD_KIT_ERR("not support type:%d\n", type);
		break;
	}
}

int lcd_kit_gpio_tx_plugin(uint32_t type, uint32_t op)
{
	uint32_t i;
	int ret;
	struct gpio_power_arra *gpio_cm = NULL;

	lcd_kit_get_gpio_num(type);

	for (i = 0; i < ARRAY_SIZE(gpio_power_plugin); i++) {
		if (gpio_power_plugin[i].oper == op) {
			gpio_cm = &gpio_power_plugin[i];
			break;
		}
	}
	if (i >= ARRAY_SIZE(gpio_power_plugin)) {
		LCD_KIT_ERR("not found cm from gpio_power\n");
		return LCD_KIT_FAIL;
	}
	if (!gpio_cm) {
		LCD_KIT_ERR("gpio_cm is null!\n");
		return LCD_KIT_FAIL;
	}
	if (gpio_cm->num > 0) {
		ret = lcd_kit_gpio_cmds_tx(gpio_cm->cm, gpio_cm->num);
		LCD_KIT_INFO("gpio:%d ,op:%d\n", *gpio_cm->cm->gpio, op);
		return ret;
	} else {
		LCD_KIT_INFO("gpio is not bigger than 0\n");
		return LCD_KIT_FAIL;
	}
}

static int lcd_kit_power_ctrl(int panel_id, uint32_t data,
	uint32_t gpio_type, uint32_t power_type)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = lcd_kit_get_adapt_ops();

	if (!adapt_ops) {
		LCD_KIT_ERR("can not register adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	if (data > 0) {
		LCD_KIT_ERR("do not handle power on event!\n");
		return LCD_KIT_FAIL;
	}
	switch (power_type) {
	case GPIO_MODE:
		if (adapt_ops->gpio_disable_plugin)
			ret = adapt_ops->gpio_disable_plugin(gpio_type);
		break;
	case REGULATOR_MODE:
		if (adapt_ops->regulator_enable)
			ret = adapt_ops->regulator_enable(panel_id, gpio_type, data);
		break;
	default:
		LCD_KIT_ERR("power mode is not support\n");
		return LCD_KIT_FAIL;
	}
	return ret;
}

uint32_t get_power_type_vci(void)
{
	if (g_pwr_off_optimize_cfg.lcd_vci == NULL) {
		LCD_KIT_INFO("g_pwr_off_optimize_cfg.lcd_vci is null\n");
		return LCD_KIT_OK;
	}
	return g_pwr_off_optimize_cfg.lcd_vci->buf[POWER_MODE];
}

uint32_t get_power_type_iovcc(void)
{
	if (g_pwr_off_optimize_cfg.lcd_iovcc == NULL) {
		LCD_KIT_INFO("g_pwr_off_optimize_cfg.lcd_iovcc is null\n");
		return LCD_KIT_OK;
	}
	return g_pwr_off_optimize_cfg.lcd_iovcc->buf[POWER_MODE];
}

uint32_t get_power_type_rst(void)
{
	if (g_pwr_off_optimize_cfg.lcd_rst == NULL) {
		LCD_KIT_INFO("g_pwr_off_optimize_cfg.lcd_rst is null\n");
		return LCD_KIT_OK;
	}
	return g_pwr_off_optimize_cfg.lcd_rst->buf[POWER_MODE];
}

uint32_t get_power_type_vdd(void)
{
	if (g_pwr_off_optimize_cfg.lcd_vdd == NULL) {
		LCD_KIT_INFO("g_pwr_off_optimize_cfg.lcd_vdd is null\n");
		return LCD_KIT_OK;
	}
	return g_pwr_off_optimize_cfg.lcd_vdd->buf[POWER_MODE];
}

uint32_t get_power_type_pmic_ctrl(void)
{
	if (g_pwr_off_optimize_cfg.lcd_pmic_ctrl == NULL) {
		LCD_KIT_INFO("g_pwr_off_optimize_cfg.lcd_pmic_ctrl is null\n");
		return LCD_KIT_OK;
	}
	return g_pwr_off_optimize_cfg.lcd_pmic_ctrl->buf[POWER_MODE];
}

uint32_t get_power_type_pmic_reset(void)
{
	if (g_pwr_off_optimize_cfg.lcd_pmic_reset == NULL) {
		LCD_KIT_INFO("g_pwr_off_optimize_cfg.lcd_pmic_reset is null\n");
		return LCD_KIT_OK;
	}
	return g_pwr_off_optimize_cfg.lcd_pmic_reset->buf[POWER_MODE];
}

uint32_t get_power_type_integ_en(void)
{
	if (g_pwr_off_optimize_cfg.lcd_integ_en == NULL) {
		LCD_KIT_INFO("g_pwr_off_optimize_cfg.lcd_integ_en is null\n");
		return LCD_KIT_OK;
	}
	return g_pwr_off_optimize_cfg.lcd_integ_en->buf[POWER_MODE];
}

typedef struct {
	uint32_t event_type;
	uint32_t gpio_type;
	uint32_t (*get_power_type)(void);
} event_handler_entry;

static const event_handler_entry event_handlers[] = {
	{ EVENT_VCI, LCD_KIT_VCI, get_power_type_vci },
	{ EVENT_IOVCC, LCD_KIT_IOVCC, get_power_type_iovcc },
	{ EVENT_RESET, LCD_KIT_RST, get_power_type_rst },
	{ EVENT_VDD, LCD_KIT_VDD, get_power_type_vdd },
	{ EVENT_PMIC_CTRL, LCD_KIT_PMIC_CTRL, get_power_type_pmic_ctrl },
	{ EVENT_PMIC_RESET, LCD_KIT_PMIC_RESET, get_power_type_pmic_reset },
	{ EVENT_INTEG_EN, LCD_KIT_INTEG_EN, get_power_type_integ_en },
};

static const event_handler_entry *find_event_handler(uint32_t event)
{
	size_t num_entries = sizeof(event_handlers) / sizeof(event_handlers[0]);
	size_t i;
	for (i = 0; i < num_entries; ++i) {
		if (event_handlers[i].event_type == event) {
			return &event_handlers[i];
		}
	}
	return NULL;
}

static bool should_skip_event(int panel_id, uint32_t event)
{
	if (!common_info->poweric_reuse.support)
		return false;
	/* pmic reset and integ en event not execute when switch panel */
	return (event == EVENT_PMIC_RESET || event == EVENT_INTEG_EN);
}

static int lcd_kit_event_handler_plugin(int panel_id, uint32_t event,
	uint32_t data, uint32_t delay)
{
	int ret = LCD_KIT_OK;
	uint32_t power_type;
	uint32_t gpio_type;
	const event_handler_entry *handler = NULL;

	LCD_KIT_INFO("panel_id = %d, event = %u, data = %u, delay = %u\n", panel_id, event, data, delay);
	if (should_skip_event(panel_id, event))
		return ret;
	handler = find_event_handler(event);
	if (handler != NULL) {
		gpio_type = handler->gpio_type;
		power_type = handler->get_power_type();
		ret = lcd_kit_power_ctrl(panel_id, data, gpio_type, power_type);
	} else if (event == EVENT_NONE) {
		LCD_KIT_INFO("none event\n");
	} else {
		LCD_KIT_INFO("event not exist\n");
	}
	lcd_kit_delay(delay, LCD_KIT_WAIT_MS, true);
	return ret;
}

static void lcd_kit_power_off_optimize_work(struct work_struct *work)
{
	int ret;
	unsigned int i;
	struct lcd_kit_array_data *pevent = NULL;
	int panel_id;

	if (!g_pwr_off_optimize_cfg.working_flag) {
		LCD_KIT_INFO("work state is err!\n");
		return;
	}

	LCD_KIT_INFO("power off work start!\n");
	panel_id = g_pwr_off_optimize_cfg.working_flag - true;
	pevent = g_pwr_off_optimize_cfg.panel_power_off_event;
	for (i = 0; i < g_pwr_off_optimize_cfg.panel_power_off_seq_cnt; i++) {
		if (!pevent || !pevent->buf || !g_pwr_off_optimize_cfg.working_flag) {
			LCD_KIT_ERR("pevent is null or worker is done\n");
			g_pwr_off_optimize_cfg.working_flag = false;
			return;
		}
		ret = lcd_kit_event_handler_plugin(panel_id,
			pevent->buf[EVENT_NUM],
			pevent->buf[EVENT_DATA],
			pevent->buf[EVENT_DELAY]);
		if (ret) {
			LCD_KIT_ERR("send event 0x%x error!\n", pevent->buf[EVENT_NUM]);
			g_pwr_off_optimize_cfg.working_flag = false;
			break;
		}
		pevent++;
	}
	g_pwr_off_optimize_cfg.working_flag = false;
	lcd_kit_set_skip_power_on_off(false);
	complete_all(&power_off_done);
	LCD_KIT_INFO("power off work end!\n");
	return;
}

void lcd_kit_power_off_optimize_handle(int panel_id)
{
	if (!disp_info->pwr_off_optimize_info.support)
		return;

	if (g_pwr_off_optimize_cfg.working_flag) {
		LCD_KIT_ERR("last power off work still running!\n");
		return;
	}

	if (!lcd_kit_get_skip_power_on_off()) {
		lcd_kit_delay(disp_info->pwr_off_optimize_info.delay_time,
			LCD_KIT_WAIT_MS, true);
		LCD_KIT_INFO("is not power off work\n");
		return;
	}
	if (power_seq == NULL || power_hdl == NULL) {
		LCD_KIT_ERR("power_seq or power_hdl is NULL\n");
		return;
	}
	LCD_KIT_INFO("power off work init\n");
	g_pwr_off_optimize_cfg.working_flag = panel_id + true;
	g_pwr_off_optimize_cfg.panel_power_off_seq_cnt = (unsigned int)power_seq->power_off_seq.cnt;
	g_pwr_off_optimize_cfg.panel_power_off_event = power_seq->power_off_seq.arry_data;
	g_pwr_off_optimize_cfg.lcd_iovcc = &power_hdl->lcd_iovcc;
	g_pwr_off_optimize_cfg.lcd_vci = &power_hdl->lcd_vci;
	g_pwr_off_optimize_cfg.lcd_vdd = &power_hdl->lcd_vdd;
	g_pwr_off_optimize_cfg.lcd_rst = &power_hdl->lcd_rst;
	g_pwr_off_optimize_cfg.lcd_pmic_ctrl = &power_hdl->lcd_pmic_ctrl;
	g_pwr_off_optimize_cfg.lcd_pmic_reset = &power_hdl->lcd_pmic_reset;
	g_pwr_off_optimize_cfg.lcd_integ_en = &power_hdl->lcd_integ_en;
	schedule_delayed_work(&g_pwr_off_optimize_cfg.pwr_off_optimize_work,
		msecs_to_jiffies(disp_info->pwr_off_optimize_info.delay_time));
}

void lcd_kit_register_power_off_optimize(void)
{
	struct delayed_work *pwr_off_optimize_work = NULL;

	pwr_off_optimize_work = &g_pwr_off_optimize_cfg.pwr_off_optimize_work;
	INIT_DELAYED_WORK(pwr_off_optimize_work, lcd_kit_power_off_optimize_work);
	init_completion(&power_off_done);
	LCD_KIT_INFO("power off work regist!\n");
}
