// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_protocol_ufcs.c
 *
 * reverse ufcs protocol driver
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
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

#include "reverse_protocol_ufcs_base.h"
#include "reverse_protocol_ufcs_interface.h"
#include "reverse_protocol_ufcs_handle.h"
#include <chipset_common/hwpower/protocol/reverse_protocol_ufcs.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG rvs_ufcs_protocol
HWLOG_REGIST();

static struct rvs_ufcs_dev *g_rvs_ufcs_dev;
static struct hwufcs_power_change_data g_power_change_data;

static struct rvs_ufcs_dev *rvs_ufcs_get_dev(void)
{
	if (!g_rvs_ufcs_dev) {
		hwlog_err("g_rvs_ufcs_dev is null\n");
		return NULL;
	}

	return g_rvs_ufcs_dev;
}

int rvs_ufcs_get_protocol_register_state(void)
{
	return rvs_ufcs_check_dev_id();
}

static bool rvs_ufcs_need_send_power_change(struct rvs_ufcs_dev *di)
{
	int requested_curr = 0;

	if (di->power_change_first_time)
		return true;

	(void)rvs_ufcs_handle_get_request_curr(&requested_curr);
	hwlog_info("drop curr:%d, request curr:%d\n",
		g_power_change_data.max_curr, requested_curr);

	if (g_power_change_data.max_curr >= requested_curr)
		return false;

	return true;
}

static int rvs_ufcs_update_drop_cur(int ibus)
{
	struct rvs_ufcs_dev *l_dev = rvs_ufcs_get_dev();

	if (!l_dev)
		return -EPERM;

	/* send power change only once when drop curr increases */
	if ((ibus > g_power_change_data.max_curr) && (g_power_change_data.max_curr != 0))
		l_dev->power_change_first_time = true;

	g_power_change_data.max_curr = ibus;
	g_power_change_data.output_mode = 1;

	if (!rvs_ufcs_need_send_power_change(l_dev))
		return 0;

	if (!l_dev->power_change_work_running) {
		l_dev->power_change_work_running = true;
		schedule_delayed_work(&l_dev->send_power_change_work, msecs_to_jiffies(0));
	}
	return 0;
}

static int rvs_ufcs_enable_protocol(int enable)
{
	rvs_ufcs_handle_clear_request_data();
	return rvs_ufcs_enable_rprot(enable);
}

static int rvs_ufcs_set_power_curve(struct rchg_power_curve *power_curve)
{
	if (!power_curve)
		return -EINVAL;

	return rvs_ufcs_handle_set_power_curve(power_curve->current_curve,
		power_curve->volt_curve);
}

static int rvs_ufcs_start_auth_process(void)
{
	return rvs_ufcs_auth_process();
}

static struct rvs_charge_protocol_ops reverse_protocol_ufcs_ops = {
	.type_name = "rchg_ufcs",
	.protocol_ic_reset = rvs_ufcs_ic_reset,
	.update_source_info = rvs_ufcs_handle_set_source_info,
	.update_drop_cur = rvs_ufcs_update_drop_cur,
	.enable_rprot = rvs_ufcs_enable_protocol,
	.enable_sleep = rvs_ufcs_enable_sleep,
	.get_request_vbus = rvs_ufcs_handle_get_request_volt,
	.get_request_ibus = rvs_ufcs_handle_get_request_curr,
	.check_protocol_state = rvs_ufcs_check_protocol_state,
	.detect_device = rvs_ufcs_detect_device,
	.get_dev_det_result = rvs_ufcs_get_dev_det_result,
	.start_auth_process = rvs_ufcs_start_auth_process,
	.set_power_curve = rvs_ufcs_set_power_curve,
	.protocol_ic_pwr_switch = rvs_ufcs_ic_pwr_switch,
};

static void rvs_ufcs_handle_msg_work(struct work_struct *work)
{
	if (!work)
		return;

	rvs_ufcs_handle_msg();
}

/* send power_change msg per second */
static void rvs_ufcs_send_power_change_work(struct work_struct *work)
{
	struct rvs_ufcs_dev *di = NULL;
	int ret;

	if (!work)
		return;

	di = container_of(work, struct rvs_ufcs_dev, send_power_change_work.work);
	if (!di)
		return;

	hwlog_info("enter power change work\n");
	if (!di->plugged_state) {
		hwlog_info("slave device plugs out, stop power change work\n");
		di->power_change_work_running = false;
		return;
	}

	if (!rvs_ufcs_need_send_power_change(di)) {
		di->power_change_work_running = false;
		hwlog_info("no need power change, stop power change work\n");
		return;
	}

	ret = rvs_ufcs_request_communication(true);
	if (ret)
		goto next_loop;
	ret = rvs_ufcs_send_power_change_data_msg(&g_power_change_data);
	if (!ret)
		di->power_change_first_time = false;
	rvs_ufcs_request_communication(false);

next_loop:
	schedule_delayed_work(&di->send_power_change_work, msecs_to_jiffies(1000));
}

static int rvs_ufcs_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct rvs_ufcs_dev *di = rvs_ufcs_get_dev();

	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_OTG_REMOVE:
		di->plugged_state = false;
		memset_s(&g_power_change_data, sizeof(g_power_change_data), 0, sizeof(g_power_change_data));
		rvs_ufcs_handle_clear_request_data();
		cancel_delayed_work(&di->send_power_change_work);
		di->power_change_work_running = false;
		break;
	case POWER_NE_OTG_INSERT:
		di->plugged_state = true;
		break;
	case POWER_NE_RVS_CHG_UFCS_RECV_DATA:
		hwlog_info("receive msg not when waiting\n");
		schedule_work(&di->handle_msg_work);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int __init rvs_ufcs_init(void)
{
	int ret;
	struct rvs_ufcs_dev *l_dev = NULL;

	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;

	g_rvs_ufcs_dev = l_dev;
	l_dev->plugged_state = false;
	l_dev->power_change_first_time = false;
	l_dev->power_change_work_running = false;
	INIT_WORK(&l_dev->handle_msg_work, rvs_ufcs_handle_msg_work);
	INIT_DELAYED_WORK(&l_dev->send_power_change_work, rvs_ufcs_send_power_change_work);

	l_dev->event_ufcs_nb.notifier_call = rvs_ufcs_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_UFCS, &l_dev->event_ufcs_nb);
	if (ret)
		goto rvs_ufcs_fail_0;

	l_dev->event_nb.notifier_call = rvs_ufcs_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_OTG, &l_dev->event_nb);
	if (ret)
		goto rvs_ufcs_fail_1;

	ret = rvs_charge_protocol_ops_register(&reverse_protocol_ufcs_ops);
	if (ret)
		goto rvs_ufcs_fail_2;

	rvs_ufcs_init_msg_number_lock();
	return 0;

rvs_ufcs_fail_2:
	power_event_bnc_unregister(POWER_BNT_OTG, &g_rvs_ufcs_dev->event_nb);
rvs_ufcs_fail_1:
	power_event_bnc_unregister(POWER_BNT_UFCS, &g_rvs_ufcs_dev->event_ufcs_nb);
rvs_ufcs_fail_0:
	kfree(l_dev);
	g_rvs_ufcs_dev = NULL;
	return ret;
}

static void __exit rvs_ufcs_exit(void)
{
	if (!g_rvs_ufcs_dev)
		return;

	power_event_bnc_unregister(POWER_BNT_UFCS, &g_rvs_ufcs_dev->event_ufcs_nb);
	power_event_bnc_unregister(POWER_BNT_OTG, &g_rvs_ufcs_dev->event_nb);
	rvs_ufcs_destroy_msg_number_lock();
	cancel_delayed_work(&g_rvs_ufcs_dev->send_power_change_work);
	kfree(g_rvs_ufcs_dev);
	g_rvs_ufcs_dev = NULL;
}

subsys_initcall_sync(rvs_ufcs_init);
module_exit(rvs_ufcs_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("reverse ufcs protocol driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
