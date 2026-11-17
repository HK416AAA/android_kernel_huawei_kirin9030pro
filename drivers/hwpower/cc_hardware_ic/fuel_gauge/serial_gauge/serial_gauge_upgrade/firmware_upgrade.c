// SPDXLicenseIdentifier: GPL2.0
/*
 * cbm8580_firmware_upgrade.c
 *
 * cbm8580 firmware upgrade
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

#include "upgrade.h"

#include <securec.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_dts.h>

#define HWLOG_TAG serial_gauge_fw_upgrade
HWLOG_REGIST();

static const char *g_chip_app_file_name[SERIAL_GAUGE_HW_VERSION_END] = {
	NULL,
	NULL,
	"SY62540_FuelGauge_4S_APPA.pkg",
	"JW3408_FuelGauge_4S_APPA.pkg",
	"BK58540_FuelGauge_4S_APPA.pkg",
};

int only_sub_cmd_block(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((data[SERIAL_GAUGE_SUB_CMD_INDEX] == buf[SERIAL_GAUGE_SUB_CMD_INDEX]) &&
			(data[SERIAL_GAUGE_SUB_CMD_INDEX + 1] == buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1])) {
			return SERIAL_GAUGE_SUCCESS;
		}
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("block read failed retry %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

int read_hw_version(u32 *version)
{
	int ret, i;
	u32 version_temp = 0;
	u8 data[SERIAL_GAUGE_FW_UPGRADE_VERSION_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB] = { SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_HW_VERSION & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_HW_VERSION >> SERIAL_GAUGE_SINGLE_BIT_LEN)};

	ret = only_sub_cmd_block(buf, SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB, data,
		SERIAL_GAUGE_FW_UPGRADE_VERSION_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	for (i = 0; i < SERIAL_GAUGE_FW_VERSION_LEN; i++)
		version_temp = (version_temp << SERIAL_GAUGE_SINGLE_BIT_LEN) |
			(u32)data[i + SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB];

	hwlog_info("hw version from coul: 0x%08x\n", version_temp);
	*version = version_temp;
	return SERIAL_GAUGE_SUCCESS;
}

static int read_fw_version(u32 *version)
{
	int ret, i;
	u32 version_temp = 0;
	u8 data[SERIAL_GAUGE_FW_UPGRADE_VERSION_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB] = { SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_APP_VERSION & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_APP_VERSION >> SERIAL_GAUGE_SINGLE_BIT_LEN)};

	ret = only_sub_cmd_block(buf, SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB, data,
		SERIAL_GAUGE_FW_UPGRADE_VERSION_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	for (i = 0; i < SERIAL_GAUGE_FW_VERSION_LEN; i++)
		version_temp = (version_temp << SERIAL_GAUGE_SINGLE_BIT_LEN) |
			(u32)data[i + SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB];

	hwlog_info("fw version from coul: 0x%08x\n", version_temp);
	if (version_temp == 0)
		return SERIAL_GAUGE_FAILED;

	*version = version_temp;
	return SERIAL_GAUGE_SUCCESS;
}

static struct file *get_fw_upgrade_buf_by_file(struct serial_gauge_device *di, u32 hw_version)
{
	const char *img_path = NULL;
	char filepath[SERIAL_GAUGE_FILE_PATH_MAX_LEN] = { 0 };

	if ((hw_version < SERIAL_GAUGE_HW_VERSION_BEGIN) || (hw_version >= SERIAL_GAUGE_HW_VERSION_END))
		return NULL;

	if (!g_chip_app_file_name[hw_version])
		return NULL;

	if (power_dts_read_string(power_dts_tag(HWLOG_TAG), di->dts_node, "upgrade_file_dir", &img_path)) {
		hwlog_err("get upgrade_file_dir prop failed\n");
		return NULL;
	}

	if (snprintf_s(filepath, SERIAL_GAUGE_FILE_PATH_MAX_LEN, SERIAL_GAUGE_FILE_PATH_MAX_LEN - 1, "%s%s",
		img_path, g_chip_app_file_name[hw_version]) < 0) {
		hwlog_err("snprintf_s dir and filename failed\n");
		return NULL;
	}

	return serial_gauge_try_to_get_file(filepath);
}

static int enter_upgrade_mode(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB] = { SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_RENTER_FW_UPGRADE & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_RENTER_FW_UPGRADE >> SERIAL_GAUGE_SINGLE_BIT_LEN)};

	 while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf, SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("enter upgrade mode i2c failed %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int check_is_in_bootloader(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u16 app_type = 0;

	while (retry--) {
		ret = serial_gauge_read_word(SERIAL_GAUGE_REG_APP_TYPE, &app_type);
		if (!ret)
			break;

		hwlog_err("get app type retry %d time fialed\n", SERIAL_GAUGE_RETRY_COUNT - retry);
		power_msleep(DT_MSLEEP_50MS, 0, NULL);
	}
	if (ret)
		return SERIAL_GAUGE_FAILED;

	hwlog_info("get app_type ret= %d, app_type = %d", ret, app_type);
	if (app_type != SERIAL_GAUGE_APP_TYPE_BOOTLOADER) {
		hwlog_err("retry[%d], not in bootloader. app_type = %d", retry, app_type);
		return SERIAL_GAUGE_FAILED;
	}
	return SERIAL_GAUGE_SUCCESS;
}

static int get_access_status(u8 *status)
{
	int ret;
	u16 data = 0;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_read_word(SERIAL_GAUGE_REG_OP_STAT_L, &data);
		if (!ret)
			break;

		hwlog_err("get access status retry %d time fialed\n", SERIAL_GAUGE_RETRY_COUNT - retry);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	if (ret)
		return SERIAL_GAUGE_FAILED;

	*status = (u8)((data >> SERIAL_GAUGE_OP_STAT_H_FULL_ACCESS_FLAG) &
		SERIAL_GAUGE_OP_STAT_H_FULL_ACCESS_MASK);
	hwlog_info("access data = 0x%04x, status = 0x%02x", data, *status);

	return SERIAL_GAUGE_SUCCESS;
}

static int serial_gauge_full_access_unlock(u32 key)
{
	int ret, i, index;
	u8 buf[SERIAL_GAUGE_FW_UPGRADE_FULL_ACCESS_LEN] = { 0 };
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	buf[SERIAL_GAUGE_SUB_CMD_LEN_INDEX] = SERIAL_GAUGE_FW_UPGRADE_FULL_ACCESS_LEN - 1;
	buf[SERIAL_GAUGE_SUB_CMD_INDEX] = (u8)(SERIAL_GAUGE_SUB_CMD_FULL_ACCESS &
		SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1] = (u8)(SERIAL_GAUGE_SUB_CMD_FULL_ACCESS >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);

	hwlog_info("full access key = 0x%08x", key);
	for (i = 0; i < SERIAL_GAUGE_FULL_ACCESS_DATA_LEN; i++) {
		index = SERIAL_GAUGE_FULL_ACCESS_DATA_LEN - i - 1;
		buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE + index] = (u8)(key &
			SERIAL_GAUGE_SINGLE_BIT_MASK);
		key = key >> SERIAL_GAUGE_SINGLE_BIT_LEN;
	}

	while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf,
			SERIAL_GAUGE_FW_UPGRADE_FULL_ACCESS_LEN);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("full access unlock failed %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

int serial_gauge_access_operation(u32 key)
{
	u8 status = 0;

	if (get_access_status(&status))
		return SERIAL_GAUGE_FAILED;

	if (status <= SERIAL_GAUGE_OP_STAT_H_FULL_ACCESS_STATUS)
		return SERIAL_GAUGE_SUCCESS;

	if (serial_gauge_full_access_unlock(key))
		return SERIAL_GAUGE_FAILED;

	if (get_access_status(&status))
		return SERIAL_GAUGE_FAILED;

	if (status == SERIAL_GAUGE_OP_STAT_H_FULL_ACCESS_STATUS)
		return SERIAL_GAUGE_SUCCESS;

	hwlog_err("full access unlock failed\n");
	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_fw_upgrade_cmd(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((buf[SERIAL_GAUGE_SUB_CMD_INDEX] == data[SERIAL_GAUGE_SUB_CMD_INDEX]) &&
			(buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1] == data[SERIAL_GAUGE_SUB_CMD_INDEX + 1]) &&
			(buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE] == data[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE]) &&
			(data[SERIAL_GAUGE_SUB_CMD_INDEX_DATA] == SERIAL_GAUGE_SUB_CMD_FW_UPGRADE_SUCCESS))
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("%s retry[%d] read data fail\n", __func__, retry);
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_fw_upgrade_check_cmd(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_check_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((buf[SERIAL_GAUGE_SUB_CMD_INDEX] == data[SERIAL_GAUGE_SUB_CMD_INDEX]) &&
			(buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1] == data[SERIAL_GAUGE_SUB_CMD_INDEX + 1]) &&
			(buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE] == data[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE]) &&
			(data[SERIAL_GAUGE_SUB_CMD_INDEX_DATA] == SERIAL_GAUGE_SUB_CMD_FW_UPGRADE_SUCCESS))
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("%s retry[%d] read data fail\n", __func__, retry);
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

static int fw_upgrade_enter(void)
{
	int ret;
	u8 data[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT] = { 0 };
	u8 buf[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_TYPE] = { SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_TYPE - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE >> SERIAL_GAUGE_SINGLE_BIT_LEN), SERIAL_GAUGE_FW_UPGRADE_ENTER };

	ret = serial_gauge_fw_upgrade_check_cmd(buf, SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_TYPE, data,
		SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT);
	hwlog_info("fw upgrade enter ret = %d\n", ret);
	if (!ret)
		return SERIAL_GAUGE_SUCCESS;

	return SERIAL_GAUGE_FAILED;
}

static int fw_upgrade_header(const u8 *upgrade_buf, size_t buf_len)
{
	int ret;
	u8 data[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT] = { 0 };
	u8 header_buf[SERIAL_GAUGE_FW_UPGRADE_HEADER_BUF_LEN] = { 0 };

	header_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_LEN] = SERIAL_GAUGE_FW_UPGRADE_HEADER_BUF_LEN - 1;
	header_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_SUB_CMD] = (u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE &
		SERIAL_GAUGE_SINGLE_BIT_MASK);
	header_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_SUB_CMD + 1] = (u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);
	header_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CMD_TYPE] = SERIAL_GAUGE_FW_UPGRADE_HEADER;

	ret = memcpy_s(&header_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_INDEX],
		SERIAL_GAUGE_FW_UPGRADE_HEADER_LEN, &upgrade_buf[0], SERIAL_GAUGE_FW_UPGRADE_HEADER_LEN);

	ret += serial_gauge_fw_upgrade_cmd(header_buf, SERIAL_GAUGE_FW_UPGRADE_HEADER_BUF_LEN, data,
		SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT);
	hwlog_info("fw upgrade header ret = %d\n", ret);
	if (!ret)
		return SERIAL_GAUGE_SUCCESS;

	return SERIAL_GAUGE_FAILED;
}

static int fw_upgrade_content_send_cmd(const u8 *upgrade_buf, size_t buf_index, u8 *data_buf,
	u16 index, u16 send_size)
{
	int ret;
	u8 data[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT] = { 0 };
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return SERIAL_GAUGE_FAILED;

	if ((index + 1) % SERIAL_GAUGE_FW_UPGRADE_CONTENT_DELAY_NUM == 0)
		di->block_delay = DT_MSLEEP_1MS;

	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_INDEX] = (u8)(index &
		SERIAL_GAUGE_SINGLE_BIT_MASK);
	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_INDEX + 1] = (u8)(index >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);

	ret = memcpy_s(&data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_DATA], (size_t)send_size,
		&upgrade_buf[buf_index], (size_t)send_size);

	ret += serial_gauge_fw_upgrade_cmd(data_buf,
		send_size + SERIAL_GAUGE_FW_UPGRADE_CONTENT_INDEX_SIZE,
		data, SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT);
	di->block_delay = 0;
	return ret;
}

static int fw_upgrade_content(const u8 *upgrade_buf, size_t file_size)
{
	int ret;
	size_t i;
	u16 final_size;
	u16 index = 0;
	u16 send_size = SERIAL_GAUGE_FW_UPGRADE_CONTEN_SINGLE_LEN;
	u8 data_buf[SERIAL_GAUGE_FW_UPGRADE_CONTEN_LEN] = { 0 };

	final_size = (u16)((file_size - SERIAL_GAUGE_FW_UPGRADE_HEADER_LEN) %
		SERIAL_GAUGE_FW_UPGRADE_CONTEN_SINGLE_LEN);
	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_LEN] = SERIAL_GAUGE_FW_UPGRADE_CONTEN_LEN - 1;
	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_SUB_CMD] =
		(u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE & SERIAL_GAUGE_SINGLE_BIT_MASK);
	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_SUB_CMD + 1] =
		(u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE >> SERIAL_GAUGE_SINGLE_BIT_LEN);
	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CMD_TYPE] = SERIAL_GAUGE_FW_UPGRADE_CONTENT;
	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_SIZE] =
		(u8)(SERIAL_GAUGE_FW_UPGRADE_CONTEN_SINGLE_LEN & SERIAL_GAUGE_SINGLE_BIT_MASK);
	data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_SIZE + 1] =
		(u8)(SERIAL_GAUGE_FW_UPGRADE_CONTEN_SINGLE_LEN >> SERIAL_GAUGE_SINGLE_BIT_LEN);

	for (i = SERIAL_GAUGE_FW_UPGRADE_HEADER_LEN; i < file_size;
		i += SERIAL_GAUGE_FW_UPGRADE_CONTEN_SINGLE_LEN) {
		if (file_size - i < SERIAL_GAUGE_FW_UPGRADE_CONTEN_SINGLE_LEN) {
			send_size = final_size;
			data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_LEN] = final_size +
				SERIAL_GAUGE_FW_UPGRADE_CONTENT_INDEX_SIZE - 1;
			data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_SIZE] = (u8)(final_size &
				SERIAL_GAUGE_SINGLE_BIT_MASK);
			data_buf[SERIAL_GAUGE_FW_UPGRADE_INDEX_CONTENT_SIZE + 1] = (u8)(final_size >>
				SERIAL_GAUGE_SINGLE_BIT_LEN);
		}

		ret = fw_upgrade_content_send_cmd(upgrade_buf, i, data_buf, index, send_size);

		hwlog_info("fw upgrade content send ret = %d, i = %d, file_size = %d\n", ret, i, file_size);
		if (ret)
			return SERIAL_GAUGE_FAILED;

		index++;
	}

	return SERIAL_GAUGE_SUCCESS;
}

static int fw_upgrade_verify(void)
{
	int ret;
	u8 data[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT] = { 0 };
	u8 buf[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_TYPE] = { SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_TYPE - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_FW_UPGRADE >> SERIAL_GAUGE_SINGLE_BIT_LEN), SERIAL_GAUGE_FW_UPGRADE_VERIFY };

	ret = serial_gauge_fw_upgrade_cmd(buf, SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_TYPE, data,
		SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ADD_RESULT);
	hwlog_info("fw upgrade verify ret = %d\n", ret);
	if (!ret)
		return SERIAL_GAUGE_SUCCESS;

	return SERIAL_GAUGE_FAILED;
}

int serial_gauge_device_reset(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB] = { SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_DEVICE_RESET & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_DEVICE_RESET >> SERIAL_GAUGE_SINGLE_BIT_LEN)};

	 while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf, SERIAL_GAUGE_FW_UPGRADE_CMD_LEN_ONLY_SUB);
		if (!ret) {
			hwlog_info("upgrade reset to update firmware success\n");
			return SERIAL_GAUGE_SUCCESS;
		}

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("device soft reset i2c failed %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int check_gauge_long_in_boot(void)
{
	if (check_is_in_bootloader()) {
		return SERIAL_GAUGE_FAILED;
	}

	power_msleep(DT_MSLEEP_1S, 0, NULL);

	if (check_is_in_bootloader()) {
		return SERIAL_GAUGE_FAILED;
	}
	hwlog_info("serial gauge in boot long time, should to upgrade app\n");
	return SERIAL_GAUGE_SUCCESS;
}

static int start_fw_upgrade(struct serial_gauge_device *di, 
	const u8 *upgrade_buf, size_t buf_len)
{
	u32 version = SERIAL_GAUGE_U32_MASK;
	struct fw_header *header = (struct fw_header *)upgrade_buf;

	hwlog_info("app file version: 0x%08x\n", header->version);
	(void)read_fw_version(&version);
	di->fw_version = version;
	if (check_gauge_long_in_boot()) {
		if (header->version <= version)
			return SERIAL_GAUGE_SUCCESS;
	}

	// enter upgrade mode,not need to judge return value
	(void) enter_upgrade_mode();

	if (serial_gauge_device_reset())
		return SERIAL_GAUGE_FAILED;

	power_msleep(DT_MSLEEP_50MS, 0, NULL);
	// check in bootloader
	if (check_is_in_bootloader())
		return SERIAL_GAUGE_FAILED;

	// judge access status and unlock
	if (serial_gauge_access_operation(di->upgrade_info.key))
		return SERIAL_GAUGE_FAILED;

	// upgrade process enter
	if (fw_upgrade_enter())
		return SERIAL_GAUGE_FAILED;

	di->block_delay = DT_MSLEEP_2S;
	if (fw_upgrade_header(upgrade_buf, buf_len))
		return SERIAL_GAUGE_FAILED;
	di->block_delay = 0;
	if (fw_upgrade_content(upgrade_buf, buf_len))
		return SERIAL_GAUGE_FAILED;

	di->block_delay = DT_MSLEEP_1S;
	if (fw_upgrade_verify())
		return SERIAL_GAUGE_FAILED;
	di->block_delay = 0;
	if (serial_gauge_device_reset())
		return SERIAL_GAUGE_FAILED;

	power_msleep(DT_MSLEEP_500MS, 0, NULL);
	return SERIAL_GAUGE_SUCCESS;
}

int fw_upgrade_process(u32 hw_version)
{
	size_t file_size;
	struct file *fp = NULL;
	u8 *upgrade_buf = NULL;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di) {
		hwlog_err("fw_upgrade_process failed, device is null\n");
		return SERIAL_GAUGE_FAILED;
	}

	if (!di->upgrade_info.fw_upgrade_enable) {
		hwlog_info("config not allow firmware upgrade\n");
		return SERIAL_GAUGE_SUCCESS;
	}

	fp = get_fw_upgrade_buf_by_file(di, hw_version);
	if (!fp || IS_ERR(fp)) {
		hwlog_err("File: not exist\n");
		return SERIAL_GAUGE_FAILED;
	}
 
	file_size = file_inode(fp)->i_size;
	hwlog_info("file_size = %d\n", file_size);
	upgrade_buf = kzalloc(file_size, GFP_KERNEL);
	if (!upgrade_buf) {
		hwlog_err("upgrade buf alloc failed\n");
		goto fw_failed;
	}
 
	if (serial_gauge_file_read(fp, upgrade_buf, file_size, 0)) {
		hwlog_err("fw_upgrade_buf read failed\n");
		goto buf_failed;
	}
	di->upgrade_run = 1;
	if (start_fw_upgrade(di, upgrade_buf, file_size)) {
		di->upgrade_run = 0;
		goto buf_failed;
	}
	di->upgrade_run = 0;
	kfree(upgrade_buf);
	(void)filp_close(fp, NULL);
	hwlog_info("upgrade success\n");
	return SERIAL_GAUGE_SUCCESS;

buf_failed:
	kfree(upgrade_buf);
fw_failed:
	(void)filp_close(fp, NULL);
	hwlog_info("upgrade failed\n");
	return SERIAL_GAUGE_FAILED;
}