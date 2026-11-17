// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge_param_upgrade.c
 *
 * serial_gauge bat param sysfs write and read
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
#include "upgrade.h"

#include <securec.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_dts.h>

#define HWLOG_TAG serial_gauge_param_upgrade
HWLOG_REGIST();

static const char *g_chip_param_file_name[SERIAL_GAUGE_HW_VERSION_END] = {
	NULL,
	NULL,
	"SY62540",
	"JW3408",
	"BK58540",
};

static int serial_gauge_param_upgrade_cmd(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((buf[SERIAL_GAUGE_SUB_CMD_INDEX] == data[SERIAL_GAUGE_SUB_CMD_INDEX]) &&
			(buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1] == data[SERIAL_GAUGE_SUB_CMD_INDEX + 1]) &&
			(data[SERIAL_GAUGE_SUB_CMD_INDEX_RESULT] == SERIAL_GAUGE_SUB_CMD_FW_UPGRADE_SUCCESS))
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("%s retry[%d] read data fail\n", __func__, retry);
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

static struct file *get_param_upgrade_buf_by_file(struct serial_gauge_device *di, u32 hw_version)
{
	const char *img_path = NULL;
	const char *filename = NULL;
	char filepath[SERIAL_GAUGE_FILE_PATH_MAX_LEN] = { 0 };

	if ((hw_version < SERIAL_GAUGE_HW_VERSION_BEGIN) || (hw_version >= SERIAL_GAUGE_HW_VERSION_END))
		return NULL;

	if (!g_chip_param_file_name[hw_version])
		return NULL;

	if (power_dts_read_string(power_dts_tag(HWLOG_TAG), di->dts_node, "upgrade_param_name", &filename)) {
		hwlog_err("get upgrade_param_name prop failed\n");
		return NULL;
	}

	if (power_dts_read_string(power_dts_tag(HWLOG_TAG), di->dts_node, "upgrade_file_dir", &img_path)) {
		hwlog_err("get upgrade_file_dir prop failed\n");
		return NULL;
	}

	if (snprintf_s(filepath, SERIAL_GAUGE_FILE_PATH_MAX_LEN, SERIAL_GAUGE_FILE_PATH_MAX_LEN - 1, "%s%s_%s",
		img_path, g_chip_param_file_name[hw_version], filename) < 0) {
		hwlog_err("snprintf_s dir and filename failed\n");
		return NULL;
	}

	return serial_gauge_try_to_get_file(filepath);
}

static int serial_gauge_param_format(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[SERIAL_GAUGE_SUB_CMD_TYPE_LEN] = { SERIAL_GAUGE_SUB_CMD_TYPE_LEN - 1,
		(u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		SERIAL_GAUGE_PARAM_UPGRADE_FORMAT };

	while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf, SERIAL_GAUGE_SUB_CMD_TYPE_LEN);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_info("format param failed retry 3 times, ret = %d\n", ret);
	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_param_send_cmd(const u8 *file_buf, size_t buf_index, u8 *buf,
	u16 index, u16 send_size)
{
	int ret;
	u8 data[SERIAL_GAUGE_SUB_CMD_RESULT_LEN] = { 0 };

	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_OFFSET] = (u8)(index & SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_OFFSET + 1] = (u8)(index >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);

	ret = memcpy_s(&buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_CONTENT], (size_t)send_size,
		&file_buf[buf_index], (size_t)send_size);

	ret += serial_gauge_param_upgrade_cmd(buf, send_size + SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_CONTENT,
		data, SERIAL_GAUGE_SUB_CMD_RESULT_LEN);

	return ret;
}

int serial_gauge_param_write_content(const u8 *file_buf, size_t file_size, u16 index)
{
	int ret;
	size_t i;
	u16 final_size;
	u16 send_size = SERIAL_GAUGE_PARAM_UPGRADE_SEND_LEN;
	u8 buf[SERIAL_GAUGE_PARAM_UPGRADE_CONTEN_SINGLE_LEN] = { 0 };

	final_size = (u16)(file_size % SERIAL_GAUGE_PARAM_UPGRADE_SEND_LEN);
	buf[SERIAL_GAUGE_SUB_CMD_LEN_INDEX] = SERIAL_GAUGE_PARAM_UPGRADE_CONTEN_SINGLE_LEN - 1;
	buf[SERIAL_GAUGE_SUB_CMD_INDEX] = (u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD &
		SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1] = (u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE] = SERIAL_GAUGE_PARAM_UPGRADE_WRITE;
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE] = (u8)(send_size & SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE + 1] = (u8)(send_size >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);

	for (i = 0; i < file_size; i += SERIAL_GAUGE_PARAM_UPGRADE_SEND_LEN) {
		if (file_size - i < SERIAL_GAUGE_PARAM_UPGRADE_SEND_LEN) {
			send_size = final_size;
			buf[SERIAL_GAUGE_SUB_CMD_LEN_INDEX] = final_size +
				SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_CONTENT - 1;
			buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE] = (u8)(final_size &
				SERIAL_GAUGE_SINGLE_BIT_MASK);
			buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE + 1] = (u8)(final_size >>
				SERIAL_GAUGE_SINGLE_BIT_LEN);
		}

		ret = serial_gauge_param_send_cmd(file_buf, i, buf, index, send_size);
		hwlog_info("ret = %d, i = %d, file_size = %d\n", ret, i, file_size);
		if (ret)
			return SERIAL_GAUGE_FAILED;

		index += SERIAL_GAUGE_PARAM_UPGRADE_SEND_LEN;
	}

	return SERIAL_GAUGE_SUCCESS;
}

static int serial_gauge_param_flash(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[SERIAL_GAUGE_SUB_CMD_TYPE_LEN] = { SERIAL_GAUGE_SUB_CMD_TYPE_LEN - 1,
		(u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		SERIAL_GAUGE_PARAM_UPGRADE_FLASH };
	
	while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, buf, SERIAL_GAUGE_SUB_CMD_TYPE_LEN);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_info("flash param failed retry 3 times, ret = %d\n", ret);
	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_param_version(u8 *version)
{
	int ret;
	u8 data[SERIAL_GAUGE_SUB_CMD_RESULT_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_OFFSET_SIZE_TYPE_LEN] = {
		SERIAL_GAUGE_OFFSET_SIZE_TYPE_LEN - 1,
		(u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		SERIAL_GAUGE_PARAM_UPGRADE_READ,
		(u8)(SERIAL_GAUGE_PARAM_VERSION_OFFSET & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_PARAM_VERSION_OFFSET >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		(u8)(SERIAL_GAUGE_PARAM_VERSION_SIZE & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_PARAM_VERSION_SIZE >> SERIAL_GAUGE_SINGLE_BIT_LEN),
	};

	ret = only_sub_cmd_block(buf, SERIAL_GAUGE_OFFSET_SIZE_TYPE_LEN, data,
		SERIAL_GAUGE_SUB_CMD_RESULT_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	hwlog_info("param version from coul: 0x%02x\n", data[SERIAL_GAUGE_SUB_CMD_RESULT_LEN - 1]);
	*version = data[SERIAL_GAUGE_SUB_CMD_RESULT_LEN - 1];
	return SERIAL_GAUGE_SUCCESS;
}

int serial_gauge_start_param_upgrade(struct serial_gauge_device *di, const u8 *param_upgrade_buf, size_t buf_len)
{
	u8 version = SERIAL_GAUGE_U32_MASK;

	if (serial_gauge_param_version(&version)) {
		hwlog_err("param version from coul: 0x%08x\n", version);
		return SERIAL_GAUGE_FAILED;
	}
	hwlog_info("upgrade file param version: 0x%02x\n", param_upgrade_buf[SERIAL_GAUGE_PARAM_VERSION_OFFSET]);
	if (version != SERIAL_GAUGE_PARAM_INVALID_VERSION &&
		param_upgrade_buf[SERIAL_GAUGE_PARAM_VERSION_OFFSET] <= version)
		return SERIAL_GAUGE_SUCCESS;

	// judge access status and unlock
	if (serial_gauge_access_operation(di->upgrade_info.key))
		return SERIAL_GAUGE_FAILED;

	if (serial_gauge_param_format())
		return SERIAL_GAUGE_FAILED;

	power_msleep(DT_MSLEEP_10MS, 0, NULL);

	if (serial_gauge_param_write_content(param_upgrade_buf, buf_len, 0))
		return SERIAL_GAUGE_FAILED;
	
	di->block_delay = DT_MSLEEP_10MS;
	if (serial_gauge_param_flash())
		return SERIAL_GAUGE_FAILED;
	di->block_delay = 0;
	power_msleep(DT_MSLEEP_50MS, 0, NULL);
	if (serial_gauge_device_reset())
		return SERIAL_GAUGE_FAILED;
	power_msleep(DT_MSLEEP_500MS, 0, NULL);

	return SERIAL_GAUGE_SUCCESS;
}

int param_file_upgrade_process(u32 hw_version)
{
	size_t file_size;
	u8 *upgrade_buf = NULL;
	struct file *fp = NULL;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di) {
		hwlog_err("fw_upgrade_process failed, device is null\n");
		return SERIAL_GAUGE_FAILED;
	}

	if (!di->upgrade_info.param_upgrade_enable) {
		hwlog_info("config not allow param upgrade\n");
		return SERIAL_GAUGE_SUCCESS;
	}

	if (di->upgrade_info.param_file_type != SERIAL_GAUGE_PARAM_FILE_UPGRADE) {
		hwlog_info("config not allow file param upgrade\n");
		return SERIAL_GAUGE_SUCCESS;
	}

	fp = get_param_upgrade_buf_by_file(di, hw_version);
	if (!fp || IS_ERR(fp)) {
		hwlog_err("File: not exist\n");
		return SERIAL_GAUGE_FAILED;
	}
 
	file_size = file_inode(fp)->i_size;
	hwlog_info("file_size = %d\n", file_size);
	upgrade_buf = kzalloc(file_size, GFP_KERNEL);
	if (!upgrade_buf) {
		hwlog_err("upgrade buf alloc failed\n");
		goto param_failed;
	}

	if (serial_gauge_file_read(fp, upgrade_buf, file_size, 0)) {
		hwlog_err("param upgrade_buf read failed\n");
		goto buf_failed;
	}

	di->upgrade_run = 1;
	if (serial_gauge_start_param_upgrade(di, upgrade_buf, file_size)) {
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
param_failed:
	(void)filp_close(fp, NULL);
	hwlog_info("upgrade failed\n");
	return SERIAL_GAUGE_FAILED;
}
