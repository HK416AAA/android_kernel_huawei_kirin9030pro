// SPDXLicenseIdentifier: GPL2.0
/*
 * SERIAL_GAUGE_MODEL_UPGRADE.c
 *
 * serial_gauge bat model upgrade driver
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

#define HWLOG_TAG serial_gauge_model_upgrade
HWLOG_REGIST();

#define MODEL_MAX_NUM 4

static const char *g_chip_model_file_name[SERIAL_GAUGE_HW_VERSION_END] = {
	NULL,
	NULL,
	"SY62540",
	"JW3408",
	"BK58540",
};

static int result_sub_cmd_block(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((data[SERIAL_GAUGE_SUB_CMD_INDEX] == buf[SERIAL_GAUGE_SUB_CMD_INDEX]) &&
			(data[SERIAL_GAUGE_SUB_CMD_INDEX + 1] == buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1]) &&
			(buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE] == data[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE]) &&
			(data[SERIAL_GAUGE_SUB_CMD_INDEX_DATA] == SERIAL_GAUGE_SUB_CMD_FW_UPGRADE_SUCCESS)) {
			return SERIAL_GAUGE_SUCCESS;
		}
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("block read failed retry %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static struct file *get_model_upgrade_buf_by_file(struct serial_gauge_device *di,
	const char *model_name, u32 hw_version)
{
	const char *img_path = NULL;
	char filepath[SERIAL_GAUGE_FILE_PATH_MAX_LEN] = { 0 };

	if ((hw_version < SERIAL_GAUGE_HW_VERSION_BEGIN) || (hw_version >= SERIAL_GAUGE_HW_VERSION_END))
		return NULL;

	if (!g_chip_model_file_name[hw_version])
		return NULL;

	if (power_dts_read_string(power_dts_tag(HWLOG_TAG), di->dts_node, "upgrade_file_dir", &img_path)) {
		hwlog_err("get upgrade_file_dir prop failed\n");
		return NULL;
	}

	if (snprintf_s(filepath, SERIAL_GAUGE_FILE_PATH_MAX_LEN, SERIAL_GAUGE_FILE_PATH_MAX_LEN - 1, "%s%s_%s",
		img_path, g_chip_model_file_name[hw_version], model_name) < 0) {
		hwlog_err("snprintf_s dir and filename failed\n");
		return NULL;
	}

	return serial_gauge_try_to_get_file(filepath);
}

static int serial_gauge_model_upgrade_erase(void)
{
	int ret;
	u8 data[SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_SUB_CMD_TYPE_LEN] = { SERIAL_GAUGE_SUB_CMD_TYPE_LEN - 1,
		(u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		SERIAL_GAUGE_MODEL_UPGRADE_ERASE };

	ret = result_sub_cmd_block(buf, SERIAL_GAUGE_SUB_CMD_TYPE_LEN, data,
		SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN);

	hwlog_info("erase model ret = %d\n", ret);
	return ret;
}

static int serial_gauge_model_upgrade_all_erase(void)
{
	int ret;
	u8 data[SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_SUB_CMD_TYPE_LEN] = { SERIAL_GAUGE_SUB_CMD_TYPE_LEN - 1,
		(u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		SERIAL_GAUGE_MODEL_UPGRADE_ALL_ERASE };

	ret = result_sub_cmd_block(buf, SERIAL_GAUGE_SUB_CMD_TYPE_LEN, data,
		SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN);

	hwlog_info("erase all model ret = %d\n", ret);
	return ret;
}

static int serial_gauge_model_upgrade_write_header(const u8 *file_buf, size_t file_size)
{
	int ret;
	u8 data[SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_MODEL_UPGRADE_HEADER_LEN] = { 0 };

	buf[SERIAL_GAUGE_SUB_CMD_LEN_INDEX] = SERIAL_GAUGE_MODEL_UPGRADE_HEADER_LEN - 1;
	buf[SERIAL_GAUGE_SUB_CMD_INDEX] = (u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD &
		SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1] = (u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE] = SERIAL_GAUGE_MODEL_UPGRADE_WRITE_HEADER;

	ret = memcpy_s(&buf[SERIAL_GAUGE_SUB_CMD_INDEX_DATA], SERIAL_GAUGE_MODEL_UPGRADE_FILE_HEADER_LEN,
		&file_buf[0], SERIAL_GAUGE_MODEL_UPGRADE_FILE_HEADER_LEN);

	ret += result_sub_cmd_block(buf, SERIAL_GAUGE_MODEL_UPGRADE_HEADER_LEN,
		data, SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN);

	hwlog_info("%s model write header ret = %d\n", __func__, ret);
	return ret;
}

static int serial_gauge_model_send_cmd(const u8 *file_buf, size_t buf_index, u8 *buf,
	u16 index, u16 send_size)
{
	int ret;
	u8 data[SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN] = { 0 };

	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_OFFSET] = (u8)(index & SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_OFFSET + 1] = (u8)(index >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);

	ret = memcpy_s(&buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_CONTENT], (size_t)send_size,
		&file_buf[buf_index], (size_t)send_size);

	ret += result_sub_cmd_block(buf, send_size + SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_CONTENT,
		data, SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN);

	return ret;
}


static int serial_gauge_model_upgrade_write_content(const u8 *file_buf, size_t file_size)
{
	int ret;
	size_t i;
	u16 final_size;
	u16 index = 0;
	u16 send_size = SERIAL_GAUGE_MODEL_UPGRADE_SINGLE_SEND_LEN;
	u8 buf[SERIAL_GAUGE_MODEL_UPGRADE_CONTEN_SINGLE_LEN] = { 0 };

	final_size = (u16)((file_size - SERIAL_GAUGE_MODEL_UPGRADE_FILE_HEADER_LEN) %
		SERIAL_GAUGE_MODEL_UPGRADE_SINGLE_SEND_LEN);
	buf[SERIAL_GAUGE_SUB_CMD_LEN_INDEX] = SERIAL_GAUGE_MODEL_UPGRADE_CONTEN_SINGLE_LEN - 1;
	buf[SERIAL_GAUGE_SUB_CMD_INDEX] = (u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD &
		SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1] = (u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE] = SERIAL_GAUGE_MODEL_UPGRADE_WRITE_CONTENT;
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE] = (u8)(send_size &
		SERIAL_GAUGE_SINGLE_BIT_MASK);
	buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE + 1] = (u8)(send_size >>
		SERIAL_GAUGE_SINGLE_BIT_LEN);

	for (i = SERIAL_GAUGE_MODEL_UPGRADE_FILE_HEADER_LEN; i < file_size;
		i += SERIAL_GAUGE_MODEL_UPGRADE_SINGLE_SEND_LEN) {
		if (file_size - i < SERIAL_GAUGE_MODEL_UPGRADE_SINGLE_SEND_LEN) {
			send_size = final_size;
			buf[SERIAL_GAUGE_SUB_CMD_LEN_INDEX] = final_size +
				SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_CONTENT - 1;
			buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE] = (u8)(final_size &
				SERIAL_GAUGE_SINGLE_BIT_MASK);
			buf[SERIAL_GAUGE_SUB_CMD_INDEX_TYPE_SIZE + 1] = (u8)(final_size >>
				SERIAL_GAUGE_SINGLE_BIT_LEN);
		}

		ret = serial_gauge_model_send_cmd(file_buf, i, buf, index, send_size);

		hwlog_info("ret = %d, i = %d, file_size = %d\n", ret, i, file_size);
		if (ret)
			return SERIAL_GAUGE_FAILED;

		index += SERIAL_GAUGE_MODEL_UPGRADE_SINGLE_SEND_LEN;
	}

	return SERIAL_GAUGE_SUCCESS;
}

static int serial_gauge_model_upgrade_verify(void)
{
	int ret;
	u8 data[SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_SUB_CMD_TYPE_LEN] = { SERIAL_GAUGE_SUB_CMD_TYPE_LEN - 1,
		(u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		SERIAL_GAUGE_MODEL_UPGRADE_CHECK_SUM };

	ret = result_sub_cmd_block(buf, SERIAL_GAUGE_SUB_CMD_TYPE_LEN, data,
		SERIAL_GAUGE_SUB_CMD_TYPE_RESULT_LEN);

	hwlog_info("%s send_cmd ret = %d\n", __func__, ret);
	return ret;
}

static int serial_gauge_model_version(u32 chem_id, u32 *version)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u32 version_temp = 0;
	u8 data[SERIAL_GAUGE_FW_UPGRADE_VERSION_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_MODEL_UPGRADE_VERSION_SEND_LEN] = {
		SERIAL_GAUGE_MODEL_UPGRADE_VERSION_SEND_LEN - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_MODEL_VERSION & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_MODEL_VERSION >> SERIAL_GAUGE_SINGLE_BIT_LEN),
		(u8)U32_LL(chem_id), (u8)U32_LH(chem_id), (u8)U32_HL(chem_id),
		(u8)U32_HH(chem_id),
	};

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, SERIAL_GAUGE_MODEL_UPGRADE_VERSION_SEND_LEN,
			data, SERIAL_GAUGE_FW_UPGRADE_VERSION_LEN);
		if (ret)
			goto cmd_failed;
		
		hwlog_info("data: %02x %02x\n", data[SERIAL_GAUGE_SUB_CMD_INDEX], data[SERIAL_GAUGE_SUB_CMD_INDEX + 1]);
		if ((data[SERIAL_GAUGE_SUB_CMD_INDEX] == buf[SERIAL_GAUGE_SUB_CMD_INDEX]) &&
			(data[SERIAL_GAUGE_SUB_CMD_INDEX + 1] == buf[SERIAL_GAUGE_SUB_CMD_INDEX + 1])) {
			version_temp = GET_U32_FROM_U8_ARR4(&data[SERIAL_GAUGE_SUB_CMD_INDEX_RESULT]);
			hwlog_info("model version from coul: 0x%08x\n", version_temp);
			*version = version_temp;
			return SERIAL_GAUGE_SUCCESS;
		}
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("block read failed retry %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_start_model_upgrade(struct serial_gauge_device *di, const u8 *upgrade_file_buf,
	size_t buf_len)
{
	// judge access status and unlock
	if (serial_gauge_access_operation(di->upgrade_info.key))
		return SERIAL_GAUGE_FAILED;

	di->block_delay = DT_MSLEEP_10MS;
	if (serial_gauge_model_upgrade_erase())
		return SERIAL_GAUGE_FAILED;
	di->block_delay = DT_MSLEEP_1MS;
	if (serial_gauge_model_upgrade_write_header(upgrade_file_buf, buf_len))
		return SERIAL_GAUGE_FAILED;
	di->block_delay = DT_MSLEEP_1MS;
	if (serial_gauge_model_upgrade_write_content(upgrade_file_buf, buf_len))
		return SERIAL_GAUGE_FAILED;
	di->block_delay = DT_MSLEEP_20MS;
	if (serial_gauge_model_upgrade_verify())
		return SERIAL_GAUGE_FAILED;
	di->block_delay = 0;
	if (serial_gauge_device_reset())
		return SERIAL_GAUGE_FAILED;
	power_msleep(DT_MSLEEP_500MS, 0, NULL);
	return SERIAL_GAUGE_SUCCESS;
}

static int single_model_upgrade(struct serial_gauge_device *di,
	const char *model_name, u32 hw_version)
{
	size_t file_size;
	struct file *fp = NULL;
	u8 *upgrade_buf = NULL;

	fp = get_model_upgrade_buf_by_file(di, model_name, hw_version);
	if (!fp || IS_ERR(fp)) {
		hwlog_err("File: not exist\n");
		return SERIAL_GAUGE_FAILED;
	}
 
	file_size = file_inode(fp)->i_size;
	hwlog_info("file_size = %d\n", file_size);
	upgrade_buf = kzalloc(file_size, GFP_KERNEL);
	if (!upgrade_buf) {
		hwlog_err("upgrade buf alloc failed\n");
		goto model_failed;
	}
 
	if (serial_gauge_file_read(fp, upgrade_buf, file_size, 0)) {
		hwlog_err("model upgrade_buf read failed\n");
		goto buf_failed;
	}

	di->upgrade_run = 1;
	if (serial_gauge_start_model_upgrade(di, upgrade_buf, file_size)) {
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
model_failed:
	(void)filp_close(fp, NULL);
	hwlog_info("upgrade failed\n");
	return SERIAL_GAUGE_FAILED;
}

static int get_model_file_version(struct serial_gauge_device *di, u32 hw_version, u32 *version)
{
	size_t file_size;
	struct file *fp = NULL;
	u8 *upgrade_buf = NULL;
	const char *model_name = NULL;

	if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG), di->dts_node,
		"upgrade_model_list", 0, &model_name)) {
		hwlog_err("get first model file name failed\n");
		return SERIAL_GAUGE_FAILED;
	}

	fp = get_model_upgrade_buf_by_file(di, model_name, hw_version);
	if (!fp || IS_ERR(fp)) {
		hwlog_err("File: not exist\n");
		return SERIAL_GAUGE_FAILED;
	}
 
	file_size = file_inode(fp)->i_size;
	hwlog_info("file_size = %d\n", file_size);
	upgrade_buf = kzalloc(file_size, GFP_KERNEL);
	if (!upgrade_buf) {
		hwlog_err("upgrade buf alloc failed\n");
		goto model_failed;
	}
 
	if (serial_gauge_file_read(fp, upgrade_buf, file_size, 0)) {
		hwlog_err("model upgrade_buf read failed\n");
		goto buf_failed;
	}

	*version = GET_U32_FROM_U8_ARR4(&upgrade_buf[SERIAL_GAUGE_MODEL_VERSION_OFFSET]);
	hwlog_info("first file model version: 0x%08x\n", *version);
	return SERIAL_GAUGE_SUCCESS;
buf_failed:
	kfree(upgrade_buf);
model_failed:
	(void)filp_close(fp, NULL);
	hwlog_info("get first model version failed\n");
	return SERIAL_GAUGE_FAILED;
}

static int more_model_upgrade(struct serial_gauge_device *di, u32 hw_version)
{
	// prop_name: upgrade_model_list
	// 1. get count
	int i, ret;
	u32 file_version = 0;
	u32 version = 0;
	const char *model_name = NULL;
	int count = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), di->dts_node,
		"upgrade_model_list", MODEL_MAX_NUM , 1);

	if (count <= 0)
		return SERIAL_GAUGE_SUCCESS;

	if (get_model_file_version(di, hw_version, &file_version)) {
		hwlog_err("get model file version failed\n");
		return SERIAL_GAUGE_FAILED;
	}
	if (serial_gauge_model_version(0, &version)) {
		hwlog_err("model version from coul: 0x%08x\n", version);
		return SERIAL_GAUGE_FAILED;
	}

	if ((version != SERIAL_GAUGE_MODEL_INVALID_VERSION) && (file_version <= version))
		return SERIAL_GAUGE_SUCCESS;

	// erase all model sector
	di->block_delay = DT_MSLEEP_500MS;
	(void)serial_gauge_model_upgrade_all_erase();
	di->block_delay = 0;
	ret = SERIAL_GAUGE_SUCCESS;
	for (i = 0; i < count; i++) {
		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG), di->dts_node,
			"upgrade_model_list", i, &model_name)) {
			hwlog_err("get model file name failed: %d\n", i);
			ret += SERIAL_GAUGE_FAILED;
			continue;
		}
		ret += single_model_upgrade(di, model_name, hw_version);
	}

	return ret;
}

int model_file_upgrade_process(u32 hw_version)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di) {
		hwlog_err("model_upgrade_process failed, device is null\n");
		return SERIAL_GAUGE_FAILED;
	}

	if (!di->upgrade_info.model_upgrade_enable) {
		hwlog_info("config not allow param upgrade\n");
		return SERIAL_GAUGE_SUCCESS;
	}

	if (more_model_upgrade(di, hw_version)) {
		hwlog_err("had least one model failed\n");
		return SERIAL_GAUGE_FAILED;
	}

	hwlog_info("upgrade success\n");
	return SERIAL_GAUGE_SUCCESS;
}

