// SPDX-License-Identifier: GPL-2.0
/*
 * battery_monitor.c
 *
 * driver adapter for monitor.
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

#include <securec.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/limits.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/slab.h>
#include <linux/time.h>
#include <linux/workqueue.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <chipset_common/hwpower/battery/battery_soh.h>
#include <chipset_common/hwpower/common_module/power_time.h>

#define MONITOR_INVALID_TEMP                (-4000)
#define MONITOR_INVALID_CYCLE               (-1)
#define MONITOR_INVALID_SOC                 (-1)
#define MONITOR_MAX_BATT_NUM                5
#define MIN_MONITOR_COUNT                   12
#define DEFAULT_MONITOR_INTERVAL            5000
#define MONITOR_SOC_FULL                    100
#define MONITOR_TO_DEGREES_CELSIUS          10
#define MAX_UEVENT_BUF_SIZE                 512

#define HWLOG_TAG battery_monitor
HWLOG_REGIST();

struct monitor_batt_data {
	long charge_in_time;
	long charge_out_time;
	long charge_term_time;
	long charge_end_time;
	int start_vbat;
	int end_vbat;
	int batt_avg_temp;
	int batt_max_temp;
	int start_ui_soc;
	int end_ui_soc;
	int cycle;
	int batt_temp;
	int cap_fcc;
	int batt_cap;
	int monitor_count;
	bool is_charge_full;
	bool is_charging;
	bool is_charge_done;
	struct delayed_work monitor_work;
};

static struct monitor_batt_data g_monitor_data = { 0 };

static bool is_valid_monitor_batt_data(void)
{	
	if (g_monitor_data.charge_in_time <= 0 ||
		g_monitor_data.charge_out_time <= 0 ||
		(g_monitor_data.charge_out_time -  g_monitor_data.charge_in_time) <= 0 ||
		g_monitor_data.start_vbat < 0 ||
		g_monitor_data.end_vbat < 0 ||
		g_monitor_data.batt_avg_temp <= MONITOR_INVALID_TEMP ||
		g_monitor_data.batt_max_temp <= MONITOR_INVALID_TEMP ||
		g_monitor_data.start_ui_soc <= MONITOR_INVALID_SOC ||
		g_monitor_data.end_ui_soc <= MONITOR_INVALID_SOC ||
		g_monitor_data.cycle <= MONITOR_INVALID_CYCLE ||
		g_monitor_data.batt_temp <= MONITOR_INVALID_TEMP ||
		g_monitor_data.cap_fcc < 0 ||
		g_monitor_data.batt_cap < 0 ||
		g_monitor_data.monitor_count <= 0) {
		hwlog_err("check is invalid data !!");
		return false;
	}
	return true;
}

static int monitor_dump_data_to_buf(struct monitor_batt_data *data, char *buf, int len)
{
	return snprintf_s(buf, len, len - 1,
		"BSOH_EVT=EVT_MONITOR_UPDATE@CHINT:%ld,CHOUTT:%ld,CHTERT:%ld,CHENDT:%ld,SVBAT:%d,"
		"EVBAT:%d,BATAVGTEMP:%d,BATMAXTEMP:%d,SUISOC:%d,EUISOC:%d,CYCLE:%d,CAPFCC:%d,BATCAP:%d",
		data->charge_in_time, data->charge_out_time, data->charge_term_time, data->charge_end_time,
		data->start_vbat, data->end_vbat, data->batt_avg_temp, data->batt_max_temp, data->start_ui_soc,
		data->end_ui_soc, data->cycle, data->cap_fcc, data->batt_cap);
}

static void monitor_update_uevent(void)
{
	int len;

	char buf[MAX_UEVENT_BUF_SIZE] = { 0 };
	struct power_event_notify_data notify_data = { 0 };

	len = monitor_dump_data_to_buf(&g_monitor_data, buf, MAX_UEVENT_BUF_SIZE);
	if ((len <= 0) || (len > (MAX_UEVENT_BUF_SIZE - 1))) {
		hwlog_err("dump data failed !!, len = %d\n", len);
		return;
	}
	notify_data.event_len = len;
	notify_data.event = buf;
	power_event_report_uevent(&notify_data);
}

static int get_average_value(int old_value, int new_value, int count)
{
	if (count <= 0)
		return new_value;

	return (old_value * (count - 1) + new_value) / count;
}

static void monitor_get_batt_temp(void)
{
	int temp = 0;
	int ret = 0;

	ret = power_supply_get_int_property_value(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_TEMP, &temp);
	if (ret) {
		hwlog_err("failed to get  temp, ret = %d", ret);
		return;
	}
	g_monitor_data.batt_temp = temp / MONITOR_TO_DEGREES_CELSIUS;
	g_monitor_data.batt_avg_temp = get_average_value(g_monitor_data.batt_avg_temp,
		g_monitor_data.batt_temp, g_monitor_data.monitor_count);
	if (g_monitor_data.batt_temp > g_monitor_data.batt_max_temp)
		g_monitor_data.batt_max_temp = g_monitor_data.batt_temp;
}

static void monitor_get_charge_data(void)
{
	int soc = 0;

	if (g_monitor_data.is_charge_full)
		return;
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY,
		&soc, MONITOR_INVALID_SOC, 1);
	if (soc >= MONITOR_SOC_FULL) {
		g_monitor_data.charge_end_time = (long)power_get_current_kernel_time().tv_sec;
		g_monitor_data.is_charge_full = true;
	}
}

static void charge_monitor_work(struct work_struct *work)
{
	monitor_get_charge_data();
	monitor_get_batt_temp();
	g_monitor_data.monitor_count++;
	schedule_delayed_work(&g_monitor_data.monitor_work, msecs_to_jiffies(DEFAULT_MONITOR_INTERVAL));
}

static void monitor_batt_data_init(struct monitor_batt_data *data)
{
	if (!data)
		return;

	data->charge_in_time = 0;
	data->charge_out_time = 0;
	data->charge_term_time = 0;
	data->charge_end_time = 0;
	data->start_vbat = 0;
	data->end_vbat = 0;
	data->batt_avg_temp = MONITOR_INVALID_TEMP;
	data->batt_max_temp = MONITOR_INVALID_TEMP;
	data->start_ui_soc = MONITOR_INVALID_SOC;
	data->end_ui_soc = MONITOR_INVALID_SOC;
	data->cycle = MONITOR_INVALID_CYCLE;
	data->batt_temp = MONITOR_INVALID_TEMP;
	data->cap_fcc = 0;
	data->batt_cap = 0;
	data->monitor_count = 0;
	data->is_charge_full = false;
}

static void process_charge_start(void)
{    
	monitor_batt_data_init(&g_monitor_data);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY,
		&g_monitor_data.start_ui_soc, MONITOR_INVALID_SOC, 1);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_VOLTAGE_NOW,
		&g_monitor_data.start_vbat, 0, POWER_UV_PER_MV);
	g_monitor_data.charge_in_time = (long)power_get_current_kernel_time().tv_sec;
	cancel_delayed_work(&g_monitor_data.monitor_work);
	schedule_delayed_work(&g_monitor_data.monitor_work, 0);
}

static void process_charge_stop(void)
{
	int ret = 0;

	cancel_delayed_work_sync(&g_monitor_data.monitor_work);
	g_monitor_data.charge_out_time = (long)power_get_current_kernel_time().tv_sec;
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY,
		&g_monitor_data.end_ui_soc, MONITOR_INVALID_SOC, 1);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_VOLTAGE_NOW,
		&g_monitor_data.end_vbat, 0, POWER_UV_PER_MV);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY_FCC,
		&g_monitor_data.cap_fcc, 0, 1);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN,
		&g_monitor_data.batt_cap, 0, 1);
	ret = power_supply_get_int_property_value(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_CYCLE_COUNT, &g_monitor_data.cycle);
	if (ret) {
		g_monitor_data.cycle = MONITOR_INVALID_CYCLE;
		hwlog_err("failed to get  cycle, ret = %d", ret);
	}
	monitor_get_batt_temp();
	if (!is_valid_monitor_batt_data()) {
		hwlog_err("invalid monitor batt data !!");
		return;
	}
	if (g_monitor_data.monitor_count >= MIN_MONITOR_COUNT)
		monitor_update_uevent();
}

static void process_charge_done(void)
{
	g_monitor_data.charge_term_time = (long)power_get_current_kernel_time().tv_sec;
}

static int monitor_sys_init(struct bsoh_device *di)
{
	if (!di || !di->dev) {
		hwlog_err("info ENODEV\n");
		return -ENODEV;
	}

	monitor_batt_data_init(&g_monitor_data);
	g_monitor_data.is_charging = false;
	g_monitor_data.is_charge_done = false;
	INIT_DELAYED_WORK(&g_monitor_data.monitor_work, charge_monitor_work);
	hwlog_info("monitor init success");
	return 0;
}

static void monitor_sys_exit(struct bsoh_device *di)
{
	hwlog_info("monitor sys exit");
}

static void monitor_event_notify(struct bsoh_device *di, unsigned int event)
{
	hwlog_info("monitor_event_notify event:%d\n", event);

	switch (event) {
	case VCHRG_START_CHARGING_EVENT:
	case VCHRG_START_AC_CHARGING_EVENT:
	case VCHRG_START_USB_CHARGING_EVENT:
		if (g_monitor_data.is_charging) {
			hwlog_err("battery is charging !!\n");
			return;
		}
		g_monitor_data.is_charging = true;
		process_charge_start();
		break;
	case VCHRG_STOP_CHARGING_EVENT:
		process_charge_stop();
		g_monitor_data.is_charging = false;
		g_monitor_data.is_charge_done = false;
		break;
	case VCHRG_CHARGE_DONE_EVENT:
		if (g_monitor_data.is_charge_done) {
			hwlog_err("battery is charge done !!\n");
			return;
		}
		g_monitor_data.is_charge_done = true;
		process_charge_done();
		break;
	default:
		break;
	};
}

static const struct bsoh_sub_sys g_monitor_sys = {
	.sys_init = monitor_sys_init,
	.sys_exit = monitor_sys_exit,
	.event_notify = monitor_event_notify,
	.dmd_prepare = NULL,
	.type_name = "monitor",
	.notify_node = NULL
};

static int __init monitor_init(void)
{
	hwlog_info("monitor init");
	bsoh_register_sub_sys(BSOH_SUB_SYS_MONITOR, &g_monitor_sys);
	return 0;
}

static void __exit monitor_exit(void) {}

subsys_initcall(monitor_init);
module_exit(monitor_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("battery monitor driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");