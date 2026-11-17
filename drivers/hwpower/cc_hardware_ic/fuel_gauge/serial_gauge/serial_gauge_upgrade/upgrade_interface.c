// SPDX-License-Identifier: GPL-2.0
/*
 * upgrade_interface.c
 *
 * serial gauge upgrade interface
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

#include "upgrade_interface.h"

#include <securec.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#include "../serial_gauge_base.h"
#include "../serial_gauge_data.h"
#include "upgrade.h"

#define HWLOG_TAG serial_gauge_upgrade
HWLOG_REGIST();

// dtsi base param
static void serial_gauge_get_upgrade_config(struct serial_gauge_device *di)
{
	(void)power_dts_read_u8(power_dts_tag(HWLOG_TAG), di->dts_node,
		"fw_upgrade_enable", &di->upgrade_info.fw_upgrade_enable, SERIAL_GAUGE_DISABLE);

	(void)power_dts_read_u8(power_dts_tag(HWLOG_TAG), di->dts_node,
		"model_upgrade_enable", &di->upgrade_info.model_upgrade_enable, SERIAL_GAUGE_DISABLE);

	(void)power_dts_read_u8(power_dts_tag(HWLOG_TAG), di->dts_node,
		"param_upgrade_enable", &di->upgrade_info.param_upgrade_enable, SERIAL_GAUGE_DISABLE);

	(void)power_dts_read_u8(power_dts_tag(HWLOG_TAG), di->dts_node,
		"upgrade_low_soc_enable", &di->upgrade_info.upgrade_low_soc_enable, SERIAL_GAUGE_ENABLE);

	(void)power_dts_read_u8(power_dts_tag(HWLOG_TAG), di->dts_node,
		"param_file_type", &di->upgrade_info.param_file_type, SERIAL_GAUGE_DISABLE);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dts_node,
		"key", (u32 *)&di->upgrade_info.key, 0);
}

static void serial_gauge_upgrade_work(struct work_struct *work)
{
	int ret;
	u32 version = 0;
	struct serial_gauge_device *di = container_of(work, struct serial_gauge_device, upgrade_work.work);

	if (!di)
		return;
	
	di->fw_version = SERIAL_GAUGE_FW_DEFAULT_VERSION;
	hwlog_info("upgrade work enter\n");

	if (read_hw_version(&version)) {
		hwlog_err("hw version i2c failed\n");
		goto work_loop;
	}

	power_wakeup_lock(di->wake_lock, true);
	ret = fw_upgrade_process(version);
	if (ret) {
		hwlog_err("upgrade APP failed\n");
		goto work_loop;
	}

	ret = model_file_upgrade_process(version);
	if (ret) {
		hwlog_err("upgrade Model failed\n");
		goto work_loop;
	}

	ret = param_file_upgrade_process(version);
	if (ret) {
		hwlog_err("upgrade Param failed\n");
		goto work_loop;
	}

	power_msleep(DT_MSLEEP_1S, 0, NULL);
	hwlog_info("upgrade success\n");
	di->upgrade_info.upgrade_retry_num = 0;
	power_wakeup_unlock(di->wake_lock, true);
	return;

work_loop:
	di->upgrade_info.upgrade_retry_num--;
	power_wakeup_unlock(di->wake_lock, true);
	hwlog_info("upgrade work retry count = %d\n", di->upgrade_info.upgrade_retry_num);
	if (di->upgrade_info.upgrade_retry_num > 0)
		queue_delayed_work(di->serial_gauge_wq, &di->upgrade_work, msecs_to_jiffies(DT_MSLEEP_1S));
}

void serial_gauge_start_upgrade(void)
{
	u16 soc = 0;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	serial_gauge_get_upgrade_config(di);
	if (gauge_get_soc(&soc))
		return;

	if ((di->upgrade_info.upgrade_low_soc_enable == SERIAL_GAUGE_ENABLE) &&
		(soc <= SERIAL_GAUGE_MAX_LOW_SOC))
		return;

	di->upgrade_info.upgrade_retry_num = SERIAL_GAUGE_RETRY_COUNT;
	INIT_DELAYED_WORK(&di->upgrade_work, serial_gauge_upgrade_work);
	queue_delayed_work(di->serial_gauge_wq, &di->upgrade_work, msecs_to_jiffies(DT_MSLEEP_5S));
	hwlog_info("fw_upgrade work init success!\n");
}

void serial_gauge_upgrade_free(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	hwlog_info("fw upgrade free resource");
	cancel_delayed_work_sync(&di->upgrade_work);
}
