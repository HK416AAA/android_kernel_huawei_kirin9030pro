// SPDX-License-Identifier: GPL-2.0
/*
 * huawei_ts_kit_hybrid_core.c
 *
 * source file for hybrid ts core
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
#include "huawei_ts_kit_hybrid_core.h"
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/jiffies.h>
#include "securec.h"
#include "huawei_ts_kit_api.h"
#include "huawei_ts_kit_hybrid_control.h"
#include "lcd_kit_hybrid_swctrl.h"
#include "lcd_kit_hybrid_core.h"
#if defined(CONFIG_HUAWEI_DSM)
#include <dsm/dsm_pub.h>
#endif
#include "huawei_ts_kit.h"
#include "hybrid_keypad.h"
#include "ext_sensorhub_api.h"

#define REQUEST_CONTROL_MAX_RETRY 3
#define WAIT_RESP_TIMEOUT_MS 200

/* lock for initial */
static DEFINE_MUTEX(init_mutex);

static struct ts_hybrid_ctrl *ts_ctrl;
struct ts_kit_platform_data __attribute__((weak)) g_ts_kit_platform_data;

struct cmd_handle {
	enum ts_kit_hybrid_cmd ts_cmd;
	int (*hybrid_cmd_handle)(struct ts_hybrid_ctrl *ts_ctrl);
};

static struct cmd_handle cmd_map[] = {
	{ TS_KIT_HYBRID_SUSPEND, ts_hybrid_suspend },
	{ TS_KIT_HYBRID_RESUME, ts_hybrid_resume },
	{ TS_KIT_HYBRID_IDLE, ts_hybrid_idle },

	{ TS_KIT_HYBRID_NORMAL_TO_MCU, ts_hybrid_normal2mcu },
	{ TS_KIT_HYBRID_IDLE_TO_MCU, ts_hybrid_idle2mcu },
	{ TS_KIT_HYBRID_SLEEP_TO_MCU, ts_hybrid_sleep2mcu },

	{ TS_KIT_HYBRID_NORMAL_TO_AP, ts_hybrid_normal2ap },
	{ TS_KIT_HYBRID_IDLE_TO_AP, ts_hybrid_idle2ap },
	{ TS_KIT_HYBRID_SLEEP_TO_AP, ts_hybrid_sleep2ap },

	{ TS_KIT_HYBRID_QUCIK_ON, ts_hybrid_quickon },
};

char * ts_kit_hybrid_cmd_str[] = {
	"TS_KIT_HYBRID_SUSPEND",
	"TS_KIT_HYBRID_RESUME",
	"TS_KIT_HYBRID_IDLE",

	"TS_KIT_HYBRID_NORMAL_TO_MCU",
	"TS_KIT_HYBRID_IDLE_TO_MCU",
	"TS_KIT_HYBRID_SLEEP_TO_MCU",

	"TS_KIT_HYBRID_NORMAL_TO_AP",
	"TS_KIT_HYBRID_IDLE_TO_AP",
	"TS_KIT_HYBRID_SLEEP_TO_AP",

	"TS_KIT_HYBRID_QUCIK_ON",
	/* check ts_kit_hybrid_switch_control when add enum */
	"TS_KIT_HYBRID_INVALID_CMD",
};
static int get_ts_irq_depth(int irq_id, unsigned int *depth)
{
	struct irq_desc *desc = irq_to_desc(irq_id);

	if (!depth)
		return -EINVAL;

	if (!desc) {
		TS_LOG_ERR("ts_kit get irq desc err\n");
		return -EINVAL;
	}
	if (desc->status_use_accessors & IRQ_PER_CPU_DEVID) {
		TS_LOG_ERR("ts_kit irq is _IRQ_PER_CPU_DEVID\n");
		return -EINVAL;
	}

	*depth = desc->depth;
	TS_LOG_INFO("ts_kit get irq depth:%lu\n", *depth);

	return NO_ERR;
}

void enable_ts_irq(void)
{
	unsigned int i;
	unsigned int depth = 0;

	if (!ts_ctrl)
		return;

	mutex_lock(&ts_ctrl->irq_lock);
	if (ts_ctrl->enable_irq_depth == 0) {
		mutex_unlock(&ts_ctrl->irq_lock);
		return;
	}

	if (get_ts_irq_depth(g_ts_kit_platform_data.irq_id, &depth) != 0)
		depth = ts_ctrl->enable_irq_depth;

	TS_LOG_INFO("%s depth =%d\n", __func__, depth);
	for (i = 0; i < depth; i++)
		enable_irq(g_ts_kit_platform_data.irq_id);

	ts_ctrl->enable_irq_depth = 0;
	mutex_unlock(&ts_ctrl->irq_lock);
}

void disable_ts_irq(void)
{
	if (!ts_ctrl)
		return;

	mutex_lock(&ts_ctrl->irq_lock);
	if (ts_ctrl->enable_irq_depth > 0) {
		mutex_unlock(&ts_ctrl->irq_lock);
		return;
	}

	disable_irq(g_ts_kit_platform_data.irq_id);
	ts_ctrl->enable_irq_depth++;
	TS_LOG_INFO("%s depth =%d\n", __func__, ts_ctrl->enable_irq_depth);
	mutex_unlock(&ts_ctrl->irq_lock);
}

void ts_kit_hybrid_hw_reset(void)
{
	lcd_kit_hybrid_gesture_qon();
}

void ts_kit_hybrid_irq_open(void)
{
	enable_ts_irq();
}

void ts_kit_hybrid_irq_close(void)
{
	disable_ts_irq();
}

unsigned int get_gesture_switch(void)
{
	struct ts_easy_wakeup_info *info = NULL;

	if (g_ts_kit_platform_data.chip_data == NULL) {
		TS_LOG_INFO("%s chip_data is NULL\n", __func__);
		return NO_ERR; //chip init failed ,return 0 means gretrue is off for lcdkit use
	}

	info = &(g_ts_kit_platform_data.chip_data->easy_wakeup_info);

	TS_LOG_INFO("%s easy_wakeup_gesture :%d\n", __func__, info->easy_wakeup_gesture);
	return info->easy_wakeup_gesture;
}

void send_hybrid_ts_cmd(enum ts_kit_hybrid_cmd sub_cmd)
{
	struct ts_cmd_node cmd = {0};

	switch (sub_cmd) {
	case TS_KIT_HYBRID_NORMAL_TO_MCU:
	case TS_KIT_HYBRID_SUSPEND:
	case TS_KIT_HYBRID_IDLE_TO_MCU:
	case TS_KIT_HYBRID_SLEEP_TO_MCU:
		disable_ts_irq();
		break;
	default:
		break;
	}

	cmd.command = TS_HYBRID_SWITCH_CONTROL;
	cmd.cmd_param.prv_params = (void *)sub_cmd;
	/* put one hybrid command for ts thread */
	ts_kit_put_one_cmd(&cmd, 0);
}

void ts_kit_hybrid_switch_control_func(struct ts_cmd_node *proc_cmd,
	struct ts_cmd_node *out_cmd, struct ts_cmd_sync *sync)
{
	if (!proc_cmd)
		return;

	(void)out_cmd;
	(void)sync;
	ts_kit_hybrid_switch_control(proc_cmd);
}

void ts_kit_hybrid_switch_control(struct ts_cmd_node *proc_cmd)
{
	int i;
	enum ts_kit_hybrid_cmd cmd = TS_KIT_HYBRID_SUSPEND;

	TS_LOG_INFO("%s get in\n", __func__);
	if (!proc_cmd)
		return;

	cmd = (enum ts_kit_hybrid_cmd)proc_cmd->cmd_param.prv_params;
	if (cmd >= TS_KIT_HYBRID_INVALID_CMD) {
		TS_LOG_INFO("%s hybrid invalid cmd\n");
		return;
	}
	TS_LOG_INFO("%s get hybrid cmd:%u ==> %s\n", __func__, cmd, ts_kit_hybrid_cmd_str[cmd]);
	if (!ts_ctrl)
		return;

	mutex_lock(&ts_ctrl->ts_lock);
	/* match command and handle */
	for (i = 0; i < ARRAY_SIZE(cmd_map); ++i) {
		if (cmd != cmd_map[i].ts_cmd)
			continue;
		if (cmd_map[i].hybrid_cmd_handle)
			cmd_map[i].hybrid_cmd_handle(ts_ctrl);
		mutex_unlock(&ts_ctrl->ts_lock);
		return;
	}
	mutex_unlock(&ts_ctrl->ts_lock);
}

int hybrid_i2c_request(int value)
{
	int ret;
	int retry = 0;

	/* get i2c switch interface to request i2c */
	if (!ts_ctrl || !ts_ctrl->input_sw_ops)
		return -EINVAL;

	while (retry < REQUEST_CONTROL_MAX_RETRY) {
		if (ts_ctrl->input_sw_ops->request_control) {
			ret = ts_ctrl->input_sw_ops->request_control(ts_ctrl->input_sw_ops, value);
			if (ret >= 0)
				break;
		}
		retry++;
		TS_LOG_ERR("%s:request i2c timeout retry: %d\n", __func__, retry);
#if defined CONFIG_HUAWEI_DSM
		ts_dmd_report(DSM_SHB_ERR_TP_I2C_ERROR, "i2c request:%d timeout\n", value);
#endif
	}
	return ret;
}

bool hybrid_i2c_check(void)
{
	/* get i2c switch interface to check i2c status */
	if (ts_ctrl && ts_ctrl->input_sw_ops && ts_ctrl->input_sw_ops->sw_status_check)
		return ts_ctrl->input_sw_ops->sw_status_check(ts_ctrl->input_sw_ops);

	return true;
}

static void input_msg_handle(int sw, int req)
{
	TS_LOG_INFO("%s get in\n", __func__);
}

int ts_hybrid_ops_register(struct ts_hybrid_chip_ops *ops)
{
	int i;

	if (!ops) {
		TS_LOG_ERR("%s param error\n", __func__);
		return -EFAULT;
	}

	if (!ts_ctrl)
		ts_kit_hybrid_init();
	if (!ts_ctrl)
		return NO_ERR;

	mutex_lock(&ts_ctrl->chip_ops_lock);
	for (i = 0; i < ARRAY_SIZE(ts_ctrl->chip_ops); ++i) {
		if (!ts_ctrl->chip_ops[i]) {
			ts_ctrl->chip_ops[i] = ops;
			TS_LOG_INFO("%s register dev ops at index:%d\n", __func__, i);
			break;
		}
	}
	mutex_unlock(&ts_ctrl->chip_ops_lock);
	return NO_ERR;
}

void ts_kit_hybrid_init(void)
{
	mutex_lock(&init_mutex);
	if (ts_ctrl) {
		/* already init */
		mutex_unlock(&init_mutex);
		return;
	}
	TS_LOG_INFO("%s +\n", __func__);
	ts_ctrl = kzalloc(sizeof(*ts_ctrl), GFP_KERNEL);
	if (!ts_ctrl) {
		mutex_unlock(&init_mutex);
		return;
	}
	/* get the input switch interface */
	ts_ctrl->input_sw_ops = hybrid_swctrl_init(input_msg_handle, "input", INPUT_CHANNEL);
	if (!ts_ctrl->input_sw_ops) {
		TS_LOG_ERR("init i2c switch failed!\n");
		kfree(ts_ctrl);
		ts_ctrl = NULL;
		mutex_unlock(&init_mutex);
		return;
	}
	ts_ctrl->enable_irq_depth = 0;
	mutex_init(&ts_ctrl->ts_lock);
	mutex_init(&ts_ctrl->irq_lock);
	mutex_init(&ts_ctrl->chip_ops_lock);

	ts_ctrl->power_resp_state = 0;
	init_waitqueue_head(&ts_ctrl->resp_wait);

	/* init request i2c to AP */
	hybrid_i2c_request(1);
	hybrid_key_init();
	TS_LOG_INFO("%s -\n", __func__);
	mutex_unlock(&init_mutex);
}

void ts_kit_hybrid_release(void)
{
	if (ts_ctrl && ts_ctrl->input_sw_ops)
		hybrid_swctrl_release(ts_ctrl->input_sw_ops);

	kfree(ts_ctrl);
	ts_ctrl = NULL;
	hybrid_key_release();
}

int ts_hybrid_reset(void)
{
	if (!ts_ctrl)
		return -EINVAL;

	return ts_hybrid_input_reset(ts_ctrl);
}

int ts_hybrid_crown_power_control(bool power_status)
{
	int ret = -1;

	if (!ts_ctrl || !ts_ctrl->input_sw_ops || !ts_ctrl->input_sw_ops->power_control)
		return ret;

	if (power_status == true)
		ret = ts_ctrl->input_sw_ops->power_control(ts_ctrl->input_sw_ops, 3);
	else
		ret = ts_ctrl->input_sw_ops->power_control(ts_ctrl->input_sw_ops, 2);

	TS_LOG_ERR("%s,ret=%d", __func__, ret);

	return ret;
}

void ts_kit_set_resp_state(int state)
{
	if (!ts_ctrl)
		return;

	ts_ctrl->power_resp_state = state;
}

void ts_hybrid_wait_resp(void)
{
	int ret;

	if (!ts_ctrl)
		return;

	TS_LOG_ERR("%s get in", __func__);

	ret = wait_event_interruptible_timeout(
		ts_ctrl->resp_wait, ts_ctrl->power_resp_state == 1,
		msecs_to_jiffies(WAIT_RESP_TIMEOUT_MS));
	TS_LOG_ERR("%s wait resp ret %d", __func__, ret);
	ts_kit_set_resp_state(0);
}
