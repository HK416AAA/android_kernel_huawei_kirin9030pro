// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge_mf_data.c
 *
 * serial gauge write mf data driver
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

#include "serial_gauge_mf_data.h"

#include <linux/version.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <huawei_platform/power/batt_info_pub.h>
#include <securec.h>

#include "serial_gauge_power_saving.h"

#define HWLOG_TAG serial_gauge_mf_data
HWLOG_REGIST();

static int mf_result_sub_cmd_block(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((data[MF_INFO_SUB_CMD_INDEX] == buf[MF_INFO_SUB_CMD_INDEX]) &&
			(data[MF_INFO_SUB_CMD_INDEX + 1] == buf[MF_INFO_SUB_CMD_INDEX + 1]) &&
			(data[MF_INFO_NOT_TYPE_RESULT] == SERIAL_GAUGE_SUCCESS)) {
			return SERIAL_GAUGE_SUCCESS;
		}
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("mf block read failed retry %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int write_battery_sn_to_gauge(u8 *battery_gauge_sn, u16 len)
{
	int ret, i;
	char battery_sn[MF_INFO_BATTERY_SN_STR_LEN] = { 0 };
	u8 buf[MF_INFO_BATTERY_SN_SUB_CMD_BUF_LEN] = { 0 };
	u8 data[MF_INFO_BATTERY_SN_SUB_CMD_DATA_LEN] = { 0 };

	ret = get_battery_identifier(battery_sn, MF_INFO_BATTERY_SN_STR_LEN, 0, MF_INFO_BATTERY_SN_LEN);
	if (ret) {
		hwlog_err("get battery identifier fail, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}
	if ((battery_gauge_sn[MF_INFO_BATTERY_SN_A5_INDEX] == battery_sn[MF_INFO_BATTERY_SN_A5_INDEX]) &&
		(battery_gauge_sn[MF_INFO_BATTERY_SN_A11_INDEX] == battery_sn[MF_INFO_BATTERY_SN_A11_INDEX])) {
		hwlog_info("not need to write battery sn\n");
		return SERIAL_GAUGE_FAILED;
	}
	i = 0;
	buf[i++] = MF_INFO_BATTERY_SN_SUB_CMD_BUF_LEN - 1;
	buf[i++] = U16_L_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD);
	buf[i++] = U16_H_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD);
	buf[i++] = MF_INFO_SYS_DATE_WRITE_CMD_TYPE;
	buf[i++] = U16_L_U8(MF_INFO_BATTERY_SN_OFFSET);
	buf[i++] = U16_H_U8(MF_INFO_BATTERY_SN_OFFSET);
	buf[i++] = U16_L_U8(MF_INFO_BATTERY_SN_LEN);
	buf[i++] = U16_H_U8(MF_INFO_BATTERY_SN_LEN);
	ret = memcpy_s(buf + i, MF_INFO_BATTERY_SN_LEN, battery_sn, MF_INFO_BATTERY_SN_LEN);
	if (ret) {
		hwlog_err("cpy battery sn fail, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}

	ret = mf_result_sub_cmd_block(buf, MF_INFO_BATTERY_SN_SUB_CMD_BUF_LEN,
		data, MF_INFO_BATTERY_SN_SUB_CMD_DATA_LEN);
	if (ret) {
		hwlog_err("write battery sn to gauge failed, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}
	return SERIAL_GAUGE_SUCCESS;
}

static int mf_read_data_sub_cmd_block(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((data[MF_INFO_SUB_CMD_INDEX] == buf[MF_INFO_SUB_CMD_INDEX]) &&
			(data[MF_INFO_SUB_CMD_INDEX + 1] == buf[MF_INFO_SUB_CMD_INDEX + 1])) {
			return SERIAL_GAUGE_SUCCESS;
		}
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("mf block read failed retry %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int read_gauge_battery_sn(u8 *battery_sn, u16 len)
{
	int ret, i;
	u8 buf[MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN] = { 0 };
	u8 data[MF_INFO_BATTERY_SN_SUB_CMD_READ_DATA_LEN] = { 0 };

	i = 0;
	buf[i++] = MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN - 1;
	buf[i++] = U16_L_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD);
	buf[i++] = U16_H_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD);
	buf[i++] = MF_INFO_SYS_DATE_READ_CMD_TYPE;
	buf[i++] = U16_L_U8(MF_INFO_BATTERY_SN_OFFSET);
	buf[i++] = U16_H_U8(MF_INFO_BATTERY_SN_OFFSET);
	buf[i++] = U16_L_U8(MF_INFO_BATTERY_SN_LEN);
	buf[i++] = U16_H_U8(MF_INFO_BATTERY_SN_LEN);

	ret = mf_read_data_sub_cmd_block(buf, MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN,
		data, MF_INFO_BATTERY_SN_SUB_CMD_READ_DATA_LEN);
	if (ret) {
		hwlog_err("read gauge battery sn  failed, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,6,0))
	ret = memcpy_s(battery_sn, len, (const void *)&data[MF_INFO_NOT_TYPE_RESULT], len);
#else
	ret = memcpy_s(battery_sn, len, &data[MF_INFO_NOT_TYPE_RESULT], len);
#endif
	if (ret) {
		hwlog_err("cpy battery sn fail, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}
	return SERIAL_GAUGE_SUCCESS;
}

static int gauge_write_mf_flash(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[MF_INFO_SUB_CMD_LEN_ADD_TYPE] = { MF_INFO_SUB_CMD_LEN_ADD_TYPE - 1,
		(u8)(SERIAL_GAUGE_MF_DATA_SUB_CMD & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_MF_DATA_SUB_CMD >> SERIAL_GAUGE_SINGLE_BIT_LEN), MF_INFO_SYS_DATE_FLASH_CMD_TYPE};

	 while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf, MF_INFO_SUB_CMD_LEN_ADD_TYPE);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("mf write to flash i2c failed %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int mf_device_reset(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[MF_INFO_NOT_TYPE_RESULT] = { MF_INFO_NOT_TYPE_RESULT - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_DEVICE_RESET & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_DEVICE_RESET >> SERIAL_GAUGE_SINGLE_BIT_LEN)};

	 while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf, MF_INFO_NOT_TYPE_RESULT);
		if (!ret) {
			hwlog_info("mf reset to updste sysdata success\n");
			return SERIAL_GAUGE_SUCCESS;
		}

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("device soft reset i2c failed %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_battery_cycle_clear_cmd(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[MF_INFO_NOT_TYPE_RESULT] = { MF_INFO_NOT_TYPE_RESULT - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_CYCLE_CLEAR & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_CYCLE_CLEAR >> SERIAL_GAUGE_SINGLE_BIT_LEN)};

	 while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf, MF_INFO_NOT_TYPE_RESULT);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("battery cycle clear i2c failed %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

int serial_gauge_battery_cycle_clear(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();
	int ret;

	if (!di) {
		hwlog_err("di is NULL\n");
		return SERIAL_GAUGE_FAILED;
	}

	di->upgrade_run = 1;
	ret = serial_gauge_battery_cycle_clear_cmd();
	if (ret)
		goto clear_fail;

	power_msleep(DT_MSLEEP_10MS, 0, NULL);

	ret = mf_device_reset();
	if (ret)
		goto clear_fail;

	power_msleep(DT_MSLEEP_500MS, 0, NULL);
	hwlog_info("%s success.\n", __func__);

clear_fail:
	di->upgrade_run = 0;
	return ret;
}

static int write_battery_sn(struct serial_gauge_device *di)
{
	int ret;
	u8 battery_sn[MF_INFO_BATTERY_SN_LEN] = { 0 };

	if (!di->write_mf_enable) {
		hwlog_info("Config not to write battery sn\n");
		return SERIAL_GAUGE_FAILED;
	}

	/* write mfData A1-A16 */
	ret = read_gauge_battery_sn(battery_sn, MF_INFO_BATTERY_SN_LEN);
	if (ret) {
		hwlog_err("read gauge battery sn failed, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}

	ret = write_battery_sn_to_gauge(battery_sn, MF_INFO_BATTERY_SN_LEN);
	if (ret) {
		hwlog_err("write gauge battery sn failed, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}

	return SERIAL_GAUGE_SUCCESS;
}

static int read_mf_init_status(struct serial_gauge_device *di, u16 *init_status)
{
	int ret;
	u8 buf[MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN] = {
		MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN - 1,
		U16_L_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD), U16_H_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD),
		MF_INFO_SYS_DATE_READ_CMD_TYPE,
		U16_L_U8(MF_INFO_STATUS_OFFSET), U16_H_U8(MF_INFO_STATUS_OFFSET),
		U16_L_U8(MF_INFO_STATUS_SIZE), U16_H_U8(MF_INFO_STATUS_SIZE),
	};
	u8 data[MF_INFO_STATUS_DATA_LEN] = { 0 };

	ret = mf_read_data_sub_cmd_block(buf, MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN,
		data, MF_INFO_STATUS_DATA_LEN);
	if (ret) {
		hwlog_err("read gauge mf status failed, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}

	*init_status = GET_U16_FROM_U8_ARR2(&data[MF_INFO_STATUS_DATA_LEN - MF_INFO_STATUS_SIZE]);
	hwlog_info("read gauge mf status is: %04x\n", *init_status);
	return SERIAL_GAUGE_SUCCESS;
}

static int write_mf_init_status(struct serial_gauge_device *di, u16 init_status)
{
	int ret;
	u8 buf[MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN + MF_INFO_STATUS_SIZE] = {
		MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN + MF_INFO_STATUS_SIZE - 1,
		U16_L_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD), U16_H_U8(SERIAL_GAUGE_MF_DATA_SUB_CMD),
		MF_INFO_SYS_DATE_WRITE_CMD_TYPE,
		U16_L_U8(MF_INFO_STATUS_OFFSET), U16_H_U8(MF_INFO_STATUS_OFFSET),
		U16_L_U8(MF_INFO_STATUS_SIZE), U16_H_U8(MF_INFO_STATUS_SIZE),
		U16_L_U8(init_status), U16_H_U8(init_status),
	};
	u8 data[MF_INFO_BATTERY_SN_SUB_CMD_DATA_LEN] = { 0 };

	ret = mf_result_sub_cmd_block(buf, MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN + MF_INFO_STATUS_SIZE,
		data, MF_INFO_BATTERY_SN_SUB_CMD_DATA_LEN);
	if (ret) {
		hwlog_err("write mf init status to gauge failed, ret=%d, init_status=%04x\n", ret, init_status);
		return SERIAL_GAUGE_FAILED;
	}
	return SERIAL_GAUGE_SUCCESS;
}

static int send_use_old_lqd_to_gauge(struct serial_gauge_device *di)
{
	int ret;
	u16 init_status = 0;
	u16 old_lqd = 0;

	ret = read_mf_init_status(di, &init_status);
	if (ret) {
		hwlog_err("read mf init status failed\n");
		return SERIAL_GAUGE_FAILED;
	}
	old_lqd = di->use_old_lqd ? MF_INFO_STATUS_USE_OLD_LQD_MASK : 0;
	if ((init_status & MF_INFO_STATUS_USE_OLD_LQD_MASK) == old_lqd) {
		hwlog_info("had use old logo display show, not to edit\n");
		return SERIAL_GAUGE_FAILED;
	}
	init_status = (old_lqd == 0) ? (init_status & (~MF_INFO_STATUS_USE_OLD_LQD_MASK)) :
		(init_status | MF_INFO_STATUS_USE_OLD_LQD_MASK);
	ret = write_mf_init_status(di, init_status);
	if (ret) {
		hwlog_err("write mf init status failed\n");
		return SERIAL_GAUGE_FAILED;
	}
	return SERIAL_GAUGE_SUCCESS;
}

static void write_sys_data_work(struct work_struct *work)
{
	int ret;
	int need_reset = 0;
	struct serial_gauge_device *di = container_of(work, struct serial_gauge_device, mf_work.work);

	if (!di)
		return;
	hwlog_info("write_sys_data_work enter\n");
	if (judge_is_running_upgrade()) {
		hwlog_info("curr upgrade running, not allow i2c communicate\n");
		return;
	}
	
	di->block_delay = DT_MSLEEP_20MS;
	ret = write_battery_sn(di);
	if (!ret)
		need_reset = 1;

	di->block_delay = DT_MSLEEP_10MS;
	ret = send_use_old_lqd_to_gauge(di);
	if (!ret)
		need_reset = 1;
	di->block_delay = 0;
	if (need_reset) {
		/* sysData write to flash */
		gauge_write_mf_flash();
		power_msleep(DT_MSLEEP_50MS, 0, NULL);
		di->upgrade_run = 1;
		mf_device_reset();
		hwlog_info("mf save sysdata success\n");
		power_msleep(DT_MSLEEP_2S, 0, NULL);
		di->upgrade_run = 0;
	}
}

void serial_gauge_write_mf_data(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di || !di->serial_gauge_wq)
		return;

	INIT_DELAYED_WORK(&di->mf_work, write_sys_data_work);
	queue_delayed_work(di->serial_gauge_wq, &di->mf_work, msecs_to_jiffies(DT_MSLEEP_2S));
	hwlog_info("mf_work work start run!\n");
}

void serial_gauge_mf_free(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	cancel_delayed_work_sync(&di->mf_work);
}
