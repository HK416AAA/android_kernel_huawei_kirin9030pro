// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge_data.c
 *
 * serial gauge data driver
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

#include "serial_gauge_data.h"

#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <securec.h>

#define FW_VERSION_WRITE_LEN 3
#define FW_VERSION_READ_LEN 7
#define FW_VERSION_DATA_INDEX 3

#define HWLOG_TAG serial_gauge_data
HWLOG_REGIST();

static int retry_read_word(u8 reg, u16 *data)
{
	int ret = 0;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	if (judge_is_running_upgrade())
		return SERIAL_GAUGE_FAILED;

	while (retry--) {
		ret = serial_gauge_read_word(reg, data);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("retry[%d] read data reg[0x%02x] fail\n", retry, reg);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

static int retry_read_u32(u8 reg, u32 *data)
{
	int ret = 0;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 rbuf[GAUGE_DATA_BLOCK_U32_LEN] = { 0 };

	if (judge_is_running_upgrade())
		return SERIAL_GAUGE_FAILED;

	while (retry--) {
		ret = serial_gauge_read_block(reg, rbuf, GAUGE_DATA_BLOCK_U32_LEN);
		if (!ret) {
			*data = GET_U32_FROM_U8_ARR4(&rbuf[1]);
			hwlog_info("get[%02x] data: %u\n", reg, *data);
			return SERIAL_GAUGE_SUCCESS;
		}

		hwlog_err("retry[%d] read data reg[0x%02x] fail\n", retry, reg);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

static int retry_wr_block(u8 *buf, u8 buf_len, u8 *data, u8 data_len)
{
	int ret = 0;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("retry[%d] wr block fail\n", retry);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

void check_download_status(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 write[FW_VERSION_WRITE_LEN] = { SERIAL_GAUGE_SUB_CMD_LEN,
		DATA_SERIAL_GAUGE_SUB_CMD_L(SERIAL_GAUGE_SUB_CMD_APP_VERSION),
		DATA_SERIAL_GAUGE_SUB_CMD_H(SERIAL_GAUGE_SUB_CMD_APP_VERSION) };
	u8 read[FW_VERSION_READ_LEN] = { 0 };
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di) {
		hwlog_info("di is null");
		return;
	}

	di->block_delay = DT_MSLEEP_10MS;
	while (retry--) {
		ret = serial_gauge_write_read_block(write, FW_VERSION_WRITE_LEN, read, FW_VERSION_READ_LEN);
		if (ret < 0) {
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}
		break;
	}
	di->block_delay = 0;
	if (ret < 0) {
		hwlog_info("read fw version fail");
		return;
	}

	hwlog_info("fw version: %02x %02x %02x %02x", read[FW_VERSION_DATA_INDEX], read[FW_VERSION_DATA_INDEX + 1],
		read[FW_VERSION_DATA_INDEX + 1 + 1], read[FW_VERSION_DATA_INDEX + 1 + 1 + 1]);
}

int gauge_get_soc(u16 *soc)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_SOC, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	hwlog_info("soc is 0x%04x", data);
	*soc = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_battery_status(u16 *battery_status)
{
	int ret;
	u16 status = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_BATTERY_STATUS, &status);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	hwlog_info("battery_status is 0x%04x", status);
	*battery_status = status;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_battery_cycle(u16 *cycle)
{
	int ret;
	u16 cycle_value = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_CYCLE, &cycle_value);
	if (ret)
		return SERIAL_GAUGE_FAILED;
	hwlog_info("cycle_value is %u", cycle_value);

	*cycle = cycle_value;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_battery_dc(u16 *dc)
{
	int ret;
	u16 dc_value = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_DC, &dc_value);
	if (ret)
		return SERIAL_GAUGE_FAILED;
	hwlog_info("dc_value is %u", dc_value);

	*dc = dc_value;
	return SERIAL_GAUGE_SUCCESS;
}

static int serial_gauge_get_u32(u16 reg, u32 *data)
{
	int ret;
	u8 buf[SERIAL_GAUGE_BLOCK_BUF_ONLY_SUB_CMD_LEN] = { 
		SERIAL_GAUGE_SUB_CMD_LEN, U16_L_U8(reg), U16_H_U8(reg) };
	u8 ret_data[SERIAL_GAUGE_BLOCK_DATA_U32_LEN] = { 0 };

	if (judge_is_running_upgrade())
		return SERIAL_GAUGE_FAILED;

	ret = retry_wr_block(buf, SERIAL_GAUGE_BLOCK_BUF_ONLY_SUB_CMD_LEN,
			ret_data, SERIAL_GAUGE_BLOCK_DATA_U32_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*data = GET_U32_FROM_U8_ARR4(&ret_data[SERIAL_GAUGE_SUB_CMD_LEN + 1]);
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_safety_status(u32 *safety_status)
{
	int ret;

	ret = serial_gauge_get_u32(SERIAL_GAUGE_REG_SAFETY_STATUS, safety_status);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_pf_status(u32 *pf_status)
{
	int ret;

	ret = serial_gauge_get_u32(SERIAL_GAUGE_REG_PF_STATUS, pf_status);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_operation_status(u32 *operation_status)
{
	int ret;

	ret = serial_gauge_get_u32(SERIAL_GAUGE_REG_OP_STATUS, operation_status);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_charging_status(u32 *charging_status)
{
	int ret;

	ret = serial_gauge_get_u32(SERIAL_GAUGE_REG_CHARGING_STATUS, charging_status);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_gauging_status(u32 *gauging_status)
{
	int ret;

	ret = serial_gauge_get_u32(SERIAL_GAUGE_REG_GAUGING_STATUS, gauging_status);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_soh_fcc(u32 *soh_fcc)
{
	int ret;

	ret = serial_gauge_get_u32(SERIAL_GAUGE_SUB_CMD_SOH_FCC, soh_fcc);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

static int serial_gauge_record_log(u16 reg, u8 *value, int len)
{
	int ret;
	u8 buf[SERIAL_GAUGE_BLOCK_BUF_ONLY_SUB_CMD_LEN] = { 
		SERIAL_GAUGE_SUB_CMD_LEN, U16_L_U8(reg), U16_H_U8(reg) };
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	if (judge_is_running_upgrade())
		return SERIAL_GAUGE_FAILED;

	ret = retry_wr_block(buf, SERIAL_GAUGE_BLOCK_BUF_ONLY_SUB_CMD_LEN, data, len);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	if (data[0] <= SERIAL_GAUGE_SUB_CMD_LEN) {
		hwlog_err("get i2c data err, len: %d", data[0]);
		return SERIAL_GAUGE_FAILED;
	}

	value[0] = data[0] - SERIAL_GAUGE_SUB_CMD_LEN;
	if (value[0] > SERIAL_GAUGE_BLOCK_DATA_MAX_LEN) {
		hwlog_err("block len err, len: %d", data[0]);
		return SERIAL_GAUGE_FAILED;
	}

	if (memcpy_s(&value[1], value[0], &data[SERIAL_GAUGE_SUB_CMD_LEN + 1],
		data[0] - SERIAL_GAUGE_SUB_CMD_LEN) != EOK) {
		hwlog_err("memcpy_s subcmd data fail!, subcmd: %04x", reg);
		return SERIAL_GAUGE_FAILED;
	}

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_da_status1(void)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_DA_STATUS1, data, SERIAL_GAUGE_BLOCK_MAX_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_da_status2(void)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_DA_STATUS2, data, SERIAL_GAUGE_BLOCK_MAX_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_gauge_status1(u8 *data, u16 data_len)
{
	int ret;

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS1, data, data_len);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_gauge_status2(u8 *data, u16 data_len)
{
	int ret;

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS2, data, data_len);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_gauge_status3(u8 *data, u16 data_len)
{
	int ret;

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS3, data, data_len);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_gauge_status4(u8 *data, u16 data_len)
{
	int ret;

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS4, data, data_len);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_cb_status1(u8 *data, u16 data_len)
{
	int ret;

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_CB_STATUS1, data, SERIAL_GAUGE_BLOCK_MAX_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_cb_status2(u8 *data, u16 data_len)
{
	int ret;

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_CB_STATUS2, data, SERIAL_GAUGE_BLOCK_MAX_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_eb_status1(u8 *data, u16 data_len)
{
	int ret;

	ret = serial_gauge_record_log(SERIAL_GAUGE_SUB_CMD_EB_STATUS1, data, SERIAL_GAUGE_BLOCK_MAX_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}

/* next is write data to serial gauge */
static int retry_wr_check_block(u8 *buf, u8 buf_len, u8 *data, u8 data_len)
{
	int ret = 0;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	if (judge_is_running_upgrade())
		return SERIAL_GAUGE_FAILED;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto end;
		
		if ((data[GAUGE_DATA_SUB_CMD_INDEX] == buf[GAUGE_DATA_SUB_CMD_INDEX]) &&
			(data[GAUGE_DATA_SUB_CMD_INDEX + 1] == buf[GAUGE_DATA_SUB_CMD_INDEX + 1]) &&
			(data[GAUGE_DATA_SUB_CMD_INDEX_RESULT] == SERIAL_GAUGE_SUCCESS)) {
			return SERIAL_GAUGE_SUCCESS;
		}
end:
		hwlog_err("retry[%d] wr block fail\n", retry);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

int gauge_send_vterm(u32 vterm)
{
	int ret;
	u8 buf[GAUGE_DATA_SUB_CMD_U32_LEN] = { 
		GAUGE_DATA_SUB_CMD_U32_LEN - 1,
		U16_L_U8(SERIAL_GAUGE_SUB_CMD_SOC_BASP_VTERM), U16_H_U8(SERIAL_GAUGE_SUB_CMD_SOC_BASP_VTERM),
		U32_LL(vterm), U32_LH(vterm), U32_HL(vterm), U32_HH(vterm)
	};
	u8 data[GAUGE_DATA_SUB_CMD_RESULT_LEN] = { 0 };

	if (judge_is_running_upgrade()) {
		hwlog_info("curr upgrade running, not allow i2c communicate\n");
		return SERIAL_GAUGE_FAILED;
	}
	hwlog_info("send vterm = %08x\n", vterm);
	ret = retry_wr_check_block(buf, GAUGE_DATA_SUB_CMD_U32_LEN, data, GAUGE_DATA_SUB_CMD_RESULT_LEN);
	if (ret) {
		hwlog_err("send vterm fail, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_send_battery_ocv(u16 ocv)
{
	int ret;
	u8 buf[GAUGE_DATA_SUB_CMD_U16_LEN] = { 
		GAUGE_DATA_SUB_CMD_U16_LEN - 1,
		U16_L_U8(SERIAL_GAUGE_SUB_CMD_SOC_BASP_OCV), U16_H_U8(SERIAL_GAUGE_SUB_CMD_SOC_BASP_OCV),
		U16_L_U8(ocv), U16_H_U8(ocv)
	};
	u8 data[GAUGE_DATA_SUB_CMD_RESULT_LEN] = { 0 };

	if (judge_is_running_upgrade()) {
		hwlog_info("curr upgrade running, not allow i2c communicate\n");
		return SERIAL_GAUGE_FAILED;
	}
	hwlog_info("send battery ocv = %04x\n", ocv);
	ret = retry_wr_check_block(buf, GAUGE_DATA_SUB_CMD_U16_LEN, data, GAUGE_DATA_SUB_CMD_RESULT_LEN);
	if (ret) {
		hwlog_err("send battery ocv fail, ret=%d\n", ret);
		return SERIAL_GAUGE_FAILED;
	}
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_mf_status(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_MF_STAT, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_afe_status(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_AFE_STATUS, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_cfet_status_l(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_CFET_STATUS_L, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_cfet_status_h(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_CFET_STATUS_H, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_dfet_status_l(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_DFET_STATUS_L, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_dfet_status_h(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_DFET_STATUS_H, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_power_saving_status(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_PS_STATUS, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_d_status(u16 *status)
{
	int ret;
	u16 data = 0;

	ret = retry_read_word(SERIAL_GAUGE_REG_DEBUG_STATUS, &data);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = data;
	return SERIAL_GAUGE_SUCCESS;
}

int gauge_get_run_time(u32 *data)
{
	int ret;
	u32 temp = 0;

	ret = retry_read_u32(SERIAL_GAUGE_REG_RUN_TIME, &temp);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	*data = temp;
	return SERIAL_GAUGE_SUCCESS;
}