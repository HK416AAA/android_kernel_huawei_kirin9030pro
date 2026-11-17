// SPDX-License-Identifier: GPL-2.0
/*
 * huawei_ts_kit_hybrid_control.c
 *
 * source file for hybrid ts control
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
#include <linux/gpio.h>
#include <linux/irq.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/wait.h>
#include "securec.h"
#include "huawei_ts_kit_api.h"
#include "lcd_kit_hybrid_swctrl.h"
#include "huawei_ts_kit.h"
#include <huawei_ts_kit_platform.h>
#if defined(CONFIG_HUAWEI_DSM)
#include <dsm/dsm_pub.h>
#endif

#define SET_AIM_STATE_MAX_RETRY 3

enum input_state {
	INPUT_OFF = 0,
	INPUT_ON = 1,
	INPUT_AOD = 2,
	INPUT_RESET = 11,
};

struct ts_kit_platform_data __attribute__((weak)) g_ts_kit_platform_data;

static void ts_kit_suspend(void)
{
	struct ts_cmd_node *in_cmd = NULL;
	struct ts_cmd_node *out_cmd = NULL;

	TS_LOG_INFO("%s get in\n", __func__);
	/* suspend ts */
	in_cmd = kzalloc(sizeof(*in_cmd), GFP_KERNEL);
	if (!in_cmd)
		goto out;
	in_cmd->command = TS_POWER_CONTROL;
	in_cmd->cmd_param.pub_params.pm_type = TS_BEFORE_SUSPEND;
	if (ts_cmd_need_process(in_cmd)) {
		out_cmd = kzalloc(sizeof(*out_cmd), GFP_KERNEL);
		if (!out_cmd)
			goto out;
		ts_power_control(g_ts_kit_platform_data.irq_id, in_cmd, out_cmd);
		in_cmd->cmd_param.pub_params.pm_type = TS_SUSPEND_DEVICE;
		ts_power_control(g_ts_kit_platform_data.irq_id, in_cmd, out_cmd);
	}
out:
	kfree(in_cmd);
	in_cmd = NULL;
	kfree(out_cmd);
	out_cmd = NULL;
}

static void ts_kit_resume(void)
{
	struct ts_cmd_node *in_cmd = NULL;
	struct ts_cmd_node *out_cmd = NULL;

	TS_LOG_INFO("%s get in\n", __func__);
	/* suspend ts */
	in_cmd = kzalloc(sizeof(*in_cmd), GFP_KERNEL);
	if (!in_cmd)
		goto out;
	in_cmd->command = TS_POWER_CONTROL;
	in_cmd->cmd_param.pub_params.pm_type = TS_RESUME_DEVICE;
	if (atomic_read(&g_ts_kit_platform_data.state) != TS_WORK) {
		out_cmd = kzalloc(sizeof(*out_cmd), GFP_KERNEL);
		if (!out_cmd)
			goto out;
		ts_power_control(g_ts_kit_platform_data.irq_id, in_cmd, out_cmd);
		in_cmd->cmd_param.pub_params.pm_type = TS_AFTER_RESUME;
		ts_power_control(g_ts_kit_platform_data.irq_id, in_cmd, out_cmd);
	}
out:
	kfree(in_cmd);
	in_cmd = NULL;
	kfree(out_cmd);
	out_cmd = NULL;
}

static void input_chips_suspend(struct ts_hybrid_ctrl *ts_ctrl)
{
	int i;
	int ret;

	if (!ts_ctrl)
		return;
	/* suspend all registered devices */
	mutex_lock(&ts_ctrl->chip_ops_lock);
	for (i = 0; i < ARRAY_SIZE(ts_ctrl->chip_ops); ++i) {
		if (!ts_ctrl->chip_ops[i] || !(ts_ctrl->chip_ops[i]->hybrid_suspend))
			continue;
		ret = ts_ctrl->chip_ops[i]->hybrid_suspend();
		/* repot dmd */
		if (ret) {
#if defined(CONFIG_HUAWEI_DSM)
			ts_dmd_report(DSM_TP_DEV_STATUS_ERROR_NO,
				"%s:suspend return err, i = %d\n", __func__, i);
#endif
			TS_LOG_ERR("%s ret = %d, i = %d\n", __func__, ret, i);
		}
	}
	mutex_unlock(&ts_ctrl->chip_ops_lock);
}

static void input_chips_resume(struct ts_hybrid_ctrl *ts_ctrl)
{
	int i;
	int ret;

	if (!ts_ctrl)
		return;
	/* resume all registered devices */
	mutex_lock(&ts_ctrl->chip_ops_lock);
	for (i = 0; i < ARRAY_SIZE(ts_ctrl->chip_ops); ++i) {
		if (!ts_ctrl->chip_ops[i] || !(ts_ctrl->chip_ops[i]->hybrid_resume))
			continue;
		ret = ts_ctrl->chip_ops[i]->hybrid_resume();
		/* repot dmd */
		if (ret) {
#if defined(CONFIG_HUAWEI_DSM)
			ts_dmd_report(DSM_TP_DEV_STATUS_ERROR_NO,
				"%s:resume return err, i = %d\n", __func__, i);
#endif
			TS_LOG_ERR("%s ret = %d, i = %d\n", __func__, ret, i);
		}
	}
	mutex_unlock(&ts_ctrl->chip_ops_lock);
}

static void input_chips_idle(struct ts_hybrid_ctrl *ts_ctrl)
{
	int i;

	if (!ts_ctrl)
		return;
	/* idle all registered devices */
	mutex_lock(&ts_ctrl->chip_ops_lock);
	for (i = 0; i < ARRAY_SIZE(ts_ctrl->chip_ops); ++i) {
		if (ts_ctrl->chip_ops[i] && ts_ctrl->chip_ops[i]->hybrid_idle)
			ts_ctrl->chip_ops[i]->hybrid_idle();
	}
	mutex_unlock(&ts_ctrl->chip_ops_lock);
}

static void input_chips_get_mode(struct ts_hybrid_ctrl *ts_ctrl, int mode)
{
	int i;

	if (!ts_ctrl)
		return;
	/* idle all registered devices */
	mutex_lock(&ts_ctrl->chip_ops_lock);
	for (i = 0; i < ARRAY_SIZE(ts_ctrl->chip_ops); ++i) {
		if (ts_ctrl->chip_ops[i] && ts_ctrl->chip_ops[i]->hybrid_get_mode)
			ts_ctrl->chip_ops[i]->hybrid_get_mode(mode);
	}
	mutex_unlock(&ts_ctrl->chip_ops_lock);
}


int ts_hybrid_idle(struct ts_hybrid_ctrl *ts_ctrl)
{
	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl)
		return -EFAULT;
	input_chips_idle(ts_ctrl);
	disable_ts_irq();
	enable_ts_irq();
	return NO_ERR;
}

static void input_chips_before_suspend(struct ts_hybrid_ctrl *ts_ctrl)
{
	int i;

	if (!ts_ctrl)
		return;
	/*check before suspend all registered devices */
	mutex_lock(&ts_ctrl->chip_ops_lock);
	for (i = 0; i < ARRAY_SIZE(ts_ctrl->chip_ops); ++i) {
		if (!ts_ctrl->chip_ops[i] || !(ts_ctrl->chip_ops[i]->hybrid_before_suspend))
			continue;
		ts_ctrl->chip_ops[i]->hybrid_before_suspend();
	}
	mutex_unlock(&ts_ctrl->chip_ops_lock);
}

int ts_hybrid_suspend(struct ts_hybrid_ctrl *ts_ctrl)
{
	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl)
		return -EFAULT;
	disable_ts_irq();
	input_chips_before_suspend(ts_ctrl);
	ts_kit_suspend();
	input_chips_suspend(ts_ctrl);

	/* power off here */
	if (ts_ctrl->input_sw_ops && ts_ctrl->input_sw_ops->power_control)
		ts_ctrl->input_sw_ops->power_control(ts_ctrl->input_sw_ops, 0);

	ts_kit_set_resp_state(1);
	wake_up_interruptible(&ts_ctrl->resp_wait);
	return NO_ERR;
}

int ts_hybrid_resume(struct ts_hybrid_ctrl *ts_ctrl)
{
	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl)
		return -EFAULT;
	/* power on here */
	if (ts_ctrl->input_sw_ops && ts_ctrl->input_sw_ops->power_control)
		ts_ctrl->input_sw_ops->power_control(ts_ctrl->input_sw_ops, 1);
	input_chips_resume(ts_ctrl);
	/* if disable irq in hybrid, try to enable in resume */
	disable_ts_irq();
	enable_ts_irq();
	return NO_ERR;
}

int ts_hybrid_normal2ap(struct ts_hybrid_ctrl *ts_ctrl)
{
	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl)
		return -EFAULT;
	/* switch i2c to AP */
	hybrid_i2c_request(1);
	/* power on here */
	if (ts_ctrl->input_sw_ops && ts_ctrl->input_sw_ops->power_control)
		ts_ctrl->input_sw_ops->power_control(ts_ctrl->input_sw_ops, 1);

	/* resume ts kit framework */
	ts_kit_resume();
	input_chips_resume(ts_ctrl);
	ts_kit_irq_reinit();
	disable_ts_irq();
	enable_ts_irq();
	input_chips_get_mode(ts_ctrl, TS_KIT_HYBRID_NORMAL_TO_AP);
	return NO_ERR;
}

int ts_hybrid_idle2ap(struct ts_hybrid_ctrl *ts_ctrl)
{
	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl)
		return -EFAULT;
	hybrid_i2c_request(1);
	/* power on here */
	if (ts_ctrl->input_sw_ops && ts_ctrl->input_sw_ops->power_control)
		ts_ctrl->input_sw_ops->power_control(ts_ctrl->input_sw_ops, 1);

	input_chips_idle(ts_ctrl);
	ts_kit_irq_reinit();
	disable_ts_irq();
	enable_ts_irq();
	return NO_ERR;
}

int ts_hybrid_sleep2ap(struct ts_hybrid_ctrl *ts_ctrl)
{
	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl)
		return -EFAULT;
	hybrid_i2c_request(1);
	/* power on here */
	if (ts_ctrl->input_sw_ops && ts_ctrl->input_sw_ops->power_control)
		ts_ctrl->input_sw_ops->power_control(ts_ctrl->input_sw_ops, 0);

	ts_kit_irq_reinit();
	disable_ts_irq();
	ts_kit_suspend();
	input_chips_suspend(ts_ctrl);

	return NO_ERR;
}

int ts_hybrid_normal2mcu(struct ts_hybrid_ctrl *ts_ctrl)
{
	int ret;
	int retry = 0;

	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl || !ts_ctrl->input_sw_ops)
		return -EFAULT;
	ts_kit_suspend();
	input_chips_suspend(ts_ctrl);
	ts_kit_irq_deinit();

	while (retry < SET_AIM_STATE_MAX_RETRY) {
		if (ts_ctrl->input_sw_ops->send_hybrid_state) {
			/* send aim state message to MCU then switch i2c to MCU */
			ret = ts_ctrl->input_sw_ops->send_hybrid_state(ts_ctrl->input_sw_ops, INPUT_ON);
			if (ret >= 0)
				break;
		}
		TS_LOG_INFO("%s set tp aim state fail, retry:%d\n", __func__, retry);
		retry++;
	}

	if (ret != 0)
		goto failed;

	ret = hybrid_i2c_request(0);
	if (ret != 0)
		goto failed;

	return NO_ERR;
failed:
	ts_kit_irq_reinit();
	enable_ts_irq();
	return -EINVAL;
}

int ts_hybrid_idle2mcu(struct ts_hybrid_ctrl *ts_ctrl)
{
	int ret;

	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl || !ts_ctrl->input_sw_ops)
		return -EFAULT;
	ts_kit_suspend();
	input_chips_suspend(ts_ctrl);
	ts_kit_irq_deinit();

	if (ts_ctrl->input_sw_ops->send_hybrid_state) {
		/* send aim state message to MCU then switch i2c to MCU */
		ret = ts_ctrl->input_sw_ops->send_hybrid_state(ts_ctrl->input_sw_ops, INPUT_AOD);
		if (ret != 0)
			goto failed;
	}

	ret = hybrid_i2c_request(0);
	if (ret != 0)
		goto failed;
	return NO_ERR;

failed:
	ts_kit_irq_reinit();
	enable_ts_irq();
	return -EINVAL;
}

int ts_hybrid_sleep2mcu(struct ts_hybrid_ctrl *ts_ctrl)
{
	int ret;

	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl || !ts_ctrl->input_sw_ops)
		return -EFAULT;
	ts_kit_suspend();
	input_chips_suspend(ts_ctrl);
	ts_kit_irq_deinit();

	if (ts_ctrl->input_sw_ops->send_hybrid_state) {
		/* send aim state message to MCU then switch i2c to MCU */
		ret = ts_ctrl->input_sw_ops->send_hybrid_state(ts_ctrl->input_sw_ops, INPUT_OFF);
		if (ret != 0)
			goto failed;
	}

	/* mcu set to sleep and power off */
	ret = hybrid_i2c_request(0);
	if (ret != 0)
		goto failed;
	return NO_ERR;
failed:
	ts_kit_irq_reinit();
	return -EINVAL;
}

int ts_hybrid_quickon(struct ts_hybrid_ctrl *ts_ctrl)
{
	int ret;

	TS_LOG_INFO("%s get in\n", __func__);
	if (!ts_ctrl)
		return -EFAULT;

	ts_kit_hybrid_hw_reset();

	return 0;
}

int ts_hybrid_input_reset(struct ts_hybrid_ctrl *ts_ctrl)
{
	TS_LOG_INFO("%s get in\n", __func__);

	if (!ts_ctrl || !ts_ctrl->input_sw_ops)
		return -EFAULT;

	/* send aim state message to MCU then switch i2c to MCU */
	if (ts_ctrl->input_sw_ops->send_hybrid_state)
		return ts_ctrl->input_sw_ops->send_hybrid_state(ts_ctrl->input_sw_ops, INPUT_RESET);

	return NO_ERR;
}
