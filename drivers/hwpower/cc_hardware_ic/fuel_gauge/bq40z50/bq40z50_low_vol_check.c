// SPDX-License-Identifier: GPL-2.0
/*
 * bq40z50_low_vol_check.c
 *
 * bq40z50 low voltage driver
 *
 * Copyright (c) 2026-2026 Huawei Technologies Co., Ltd.
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

#include "bq40z50_low_vol_check.h"
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <platform_include/basicplatform/linux/power/platform/bci_battery.h>
#include <securec.h>
#include <linux/rtc.h>
#include <linux/time64.h>

#define HWLOG_TAG bq40z50
HWLOG_REGIST();

#define BATTERY_VOL_LOW_ERR     2600

static void bq40z50_low_vol_lock_init(struct bq40z50_device_info *di)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	di->low_vol_check_lock = wakeup_source_register(NULL, "low_vol_wakelock");
#else
	di->low_vol_check_lock = wakeup_source_register("low_vol_wakelock");
#endif
	if (!di->low_vol_check_lock) {
		hwlog_err("%s wakeup source register failed\n", __func__);
		return;
	}
}

static void bq40z50_get_battery_vbat_mv_min(struct bq40z50_device_info *di, int *vbat_mv)
{
	int cell1_vbat_mv = 0;
	int cell2_vbat_mv = 0;

	if (!di)
		return;

	cell1_vbat_mv = bq40z50_get_cell_vbat_mv_base(di, BQ40Z50_REG_CELL1_VOLT,
		&(di->cache.cell1_vol));
	cell2_vbat_mv = bq40z50_get_cell_vbat_mv_base(di, BQ40Z50_REG_CELL2_VOLT,
		&(di->cache.cell2_vol));

	*vbat_mv = cell1_vbat_mv < cell2_vbat_mv ? cell1_vbat_mv : cell2_vbat_mv;
	hwlog_info("vbat_mv_min=%d\n", *vbat_mv);
}

#ifdef CONFIG_HUAWEI_CHARGER_AP
static void bq40z50_send_under_voltage_event(void)
{
	struct power_event_notify_data n_data;

	n_data.event = "BATTERY_UNDER_VOLTAGE=1";
	n_data.event_len = 23; /* length of BATTERY_UNDER_VOLTAGE=1 */
	power_event_report_uevent(&n_data);
	hwlog_err("battery under voltage, report uevent request shutdown\n");
}
#endif

/* apply bq40z50 wake_lock */
static void bq40z50_wake_lock(struct bq40z50_device_info *di)
{
	if (!di->low_vol_check_lock->active) {
		__pm_stay_awake(di->low_vol_check_lock);
		hwlog_info("coul core wake lock\n");
	}
}

/* release bq40z50 wake_lock */
static void bq40z50_wake_unlock(struct bq40z50_device_info *di)
{
	if (di->low_vol_check_lock->active) {
		__pm_relax(di->low_vol_check_lock);
		hwlog_info("coul core wake unlock\n");
	}
}

static void handle_low_vol_int(struct bq40z50_device_info *di,
	int vbat_mv, int cut_off_vol)
{
	int delta_soc;
	/* low_vol_int count according to dts */
	int count = di->low_vol_filter_cnt;
	struct blocking_notifier_head *notifier_list = NULL;

	get_notifier_list(&notifier_list);

	/* if battery vol is too low, it's false */
	if (vbat_mv < BATTERY_VOL_LOW_ERR)
		hwlog_err("Battery vol too low\n");

	if (vbat_mv > cut_off_vol) {
		hwlog_err("false low_int\n");
		return;
	}
	while (count--) {
		/* sleep 1s */
		power_msleep(DT_MSLEEP_1S, 0, NULL);
		bq40z50_get_battery_vbat_mv_min(di, &vbat_mv);
		hwlog_err("delay 1000ms and get vbat_mv is %dmv\n",
			vbat_mv);
		if (vbat_mv > cut_off_vol) {
			hwlog_err("false low vol int\n");
			return;
		}
	}

#ifdef CONFIG_HUAWEI_CHARGER_AP
	hwlog_info("send under voltage.\n");
	bq40z50_send_under_voltage_event();
#endif
	blocking_notifier_call_chain(notifier_list, BATTERY_LOW_SHUTDOWN, NULL);
}

static void bq40z50_low_vol_int_handle(struct bq40z50_device_info *di)
{
	int vbat_mv = 0;
	int cut_off_vol;
	int batt_temp = 0;

	if (di == NULL) {
		hwlog_info("NULL point in %s\n", __func__);
		return;
	}

	batt_temp = bq40z50_get_battery_temp_base(di);
	cut_off_vol = batt_temp <= LOW_INT_TEMP_THRED ?
		di->v_cut_off_low_temp : di->v_cut_off_normal_temp;

	bq40z50_get_battery_vbat_mv_min(di, &vbat_mv);

	handle_low_vol_int(di, vbat_mv, cut_off_vol);
}

static void bq40z50_low_vol_work(struct work_struct *work)
{
	hwlog_info("%s++\n", __func__);
	int vbat_mv = 0;
	struct bq40z50_device_info *di = container_of(work, struct bq40z50_device_info, 
		low_vol_check_work.work);
	int work_delay_ms = LOW_VOL_DELAY_NORMAL;
	
	if (!di) {
		hwlog_err("di is null\n");
		return;
	}

	bq40z50_get_battery_vbat_mv_min(di, &vbat_mv);
	if (vbat_mv <= NORMAL_CUTOFF_VOLT_MAX) {
		work_delay_ms = LOW_VOL_DELAY_UNDER_CUTOFF;
		bq40z50_wake_lock(di);
		bq40z50_low_vol_int_handle(di);
		bq40z50_wake_unlock(di);
	}
	queue_delayed_work(system_power_efficient_wq, &di->low_vol_check_work,
		round_jiffies_relative(msecs_to_jiffies(work_delay_ms)));
}

void bq40z50_low_vol_check_work(struct bq40z50_device_info *di)
{
	if (!di)
		return;

	bq40z50_low_vol_lock_init(di);

	INIT_DELAYED_WORK(&di->low_vol_check_work, bq40z50_low_vol_work);

	queue_delayed_work(system_power_efficient_wq, &di->low_vol_check_work,
		round_jiffies_relative(msecs_to_jiffies(LOW_VOL_DELAY_NORMAL)));

	hwlog_info("bq40z50_low_vol_check start run!\n");
}