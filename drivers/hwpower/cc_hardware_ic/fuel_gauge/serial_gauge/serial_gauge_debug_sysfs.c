// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge_debug_sysfs.c
 *
 * serial gauge debug sysfs driver
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

#include "serial_gauge_debug_sysfs.h"

#include <securec.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>

#include "serial_gauge_base.h"

#define HWLOG_TAG serial_gauge_debug_sysfs
HWLOG_REGIST();

#ifdef CONFIG_SYSFS
#define U8_INVALID_DATA 0xFF
#define FW_VERSION_WRITE_LEN 3
#define FW_VERSION_READ_LEN 7
#define FW_VERSION_DATA_INDEX 3
#define DEFAULT_IPS_TIME_DELAY (7 * 24 * 3600)
#define POWER_SAVING_DELAY_TIME_MIN (60 * 1)
#define POWER_SAVING_HOUR_S 3600

static int check_download_status(char *buf, int size)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 write[FW_VERSION_WRITE_LEN] = { SERIAL_GAUGE_SUB_CMD_LEN,
		SERIAL_GAUGE_SUB_CMD_L(SERIAL_GAUGE_SUB_CMD_APP_VERSION),
		SERIAL_GAUGE_SUB_CMD_H(SERIAL_GAUGE_SUB_CMD_APP_VERSION) };
	u8 read[FW_VERSION_READ_LEN] = { 0 };
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return snprintf_s(buf, size, size - 1, "di get Null\n");

	if (judge_is_running_upgrade())
		return snprintf_s(buf, size, size - 1, "curr upgrade running, not allow i2c communicate\n");

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
	if (ret < 0)
		return snprintf_s(buf, size, size - 1, "read fw version fail\n");

	return snprintf_s(buf, size, size - 1, "fw version: %02x %02x %02x %02x\n",
		read[FW_VERSION_DATA_INDEX], read[FW_VERSION_DATA_INDEX + 1],
		read[FW_VERSION_DATA_INDEX + 1 + 1], read[FW_VERSION_DATA_INDEX + 1 + 1 + 1]);
}

static int get_download_result(char *buf, int size)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return snprintf_s(buf, size, size - 1, "di get Null\n");

	return snprintf_s(buf, size, size - 1, "download_result: %02x\n", di->factory_download_result);
}

static int serial_gauge_debug(u16 sub_cmd, u8 cmd_type)
{
	u8 data[FW_VERSION_WRITE_LEN + 1] = { SERIAL_GAUGE_SUB_CMD_LEN + 1,
		SERIAL_GAUGE_SUB_CMD_L(sub_cmd),
		SERIAL_GAUGE_SUB_CMD_H(sub_cmd), cmd_type };
	struct serial_gauge_device *di = serial_gauge_get_di();
	u8 data_len = FW_VERSION_WRITE_LEN + 1;

	if (!di)
		return SERIAL_GAUGE_FAILED;

	if (judge_is_running_upgrade())
		return SERIAL_GAUGE_SUCCESS;

	if (cmd_type == U8_INVALID_DATA) {
		data[0] = SERIAL_GAUGE_SUB_CMD_LEN;
		data_len = FW_VERSION_WRITE_LEN;
	}

	(void) serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, data, data_len);

	return SERIAL_GAUGE_SUCCESS;
}

static int serial_gauge_debug_info(char *buf, int size)
{
	return snprintf_s(buf, size, size - 1, "debug serial gauge: echo sum_cmd cmd_type > debug [data is decimal]\n");
}

static int serial_gauge_retrieve_info(char *buf, int size)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return snprintf_s(buf, size, size - 1, "di get Null\n");
	
	return snprintf_s(buf, size, size - 1, "Power off retrieve: %d\n", di->power_off_retrieve_time);
}

static int serial_gague_retrieve_set(int data)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	di->power_off_retrieve_time = data * POWER_SAVING_HOUR_S;
	if (data <= 0)
		di->power_off_retrieve_time = POWER_SAVING_DELAY_TIME_MIN;

	return SERIAL_GAUGE_SUCCESS;
}

static int erase_boot_first_sector(char *buf, int size)
{
	u8 write[FW_VERSION_WRITE_LEN] = { SERIAL_GAUGE_SUB_CMD_LEN,
		SERIAL_GAUGE_SUB_CMD_L(SERIAL_GAUGE_SUB_CMD_ERASE_BOOT),
		SERIAL_GAUGE_SUB_CMD_H(SERIAL_GAUGE_SUB_CMD_ERASE_BOOT) };
	u8 reset[FW_VERSION_WRITE_LEN] = { SERIAL_GAUGE_SUB_CMD_LEN,
		SERIAL_GAUGE_SUB_CMD_L(SERIAL_GAUGE_SUB_CMD_DEVICE_RESET),
		SERIAL_GAUGE_SUB_CMD_H(SERIAL_GAUGE_SUB_CMD_DEVICE_RESET) };
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return snprintf_s(buf, size, size - 1, "di get Null\n");

	if (judge_is_running_upgrade())
		return snprintf_s(buf, size, size - 1, "curr upgrade running, not allow i2c communicate\n");

	(void) serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, write, FW_VERSION_WRITE_LEN);
	power_msleep(DT_MSLEEP_50MS, 0, NULL);
	(void) serial_gauge_write_block(SERIAL_GAUGE_BLOCK_ADDR, reset, FW_VERSION_WRITE_LEN);

	return snprintf_s(buf, size, size - 1, "erase success\n");
}

static int parse_str_gauge_operation(struct serial_gauge_device *di,
	const char *buf, int size)
{
	int ret;
	char operation_type;
	char* token;
	char* next_token = NULL;
	char str[SERIAL_GAUGE_SYSFS_SHOW_STR_LEN];
	int count = 0, data = 0;

	ret = strcpy_s(str, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN, buf);
	if (ret) {
		hwlog_info("copy str failed");
		return SERIAL_GAUGE_FAILED;
	}
	hwlog_info("buf: %s", buf);
	token = strtok_s(str, " ", &next_token);
	if (sscanf_s(token, "%c", &operation_type, sizeof(operation_type)) <= 0) {
		hwlog_info("sscanf_s parse operation_type failed");
		return SERIAL_GAUGE_FAILED;
	}
	while (token != NULL && count < SERIAL_GAUGE_OPERATION_MAX_SUB_STR) {
		hwlog_info("sub_str %d: %s\n", count, token);
		count++;
		token = strtok_s(NULL, " ", &next_token);
		if ((operation_type == SERIAL_GAUGE_OPERATION_READ_SCHAR) ||
			(operation_type == SERIAL_GAUGE_OPERATION_READ_LCHAR)) {
			ret = sscanf_s(token, "%x", &data);
			di->i2c_info.read_data[count - 1] = data;
			hwlog_info("sscanf_s parse read %d: %02x", count - 1,
				di->i2c_info.read_data[count - 1]);
			if (ret <= 0)
				token = NULL;
		}
		if ((operation_type == SERIAL_GAUGE_OPERATION_WRITE_SCHAR) ||
			(operation_type == SERIAL_GAUGE_OPERATION_WRITE_LCHAR)) {
			ret = sscanf_s(token, "%x", &data);
			di->i2c_info.write_data[count - 1] = data;
			hwlog_info("sscanf_s parse write %d: %02x", count - 1,
				di->i2c_info.write_data[count - 1]);
			if (ret > 0)
				di->i2c_info.write_len++;
		}
	}

	if ((operation_type == SERIAL_GAUGE_OPERATION_READ_SCHAR) ||
		(operation_type == SERIAL_GAUGE_OPERATION_READ_LCHAR))
		di->i2c_info.read_len = di->i2c_info.read_data[count - 1];

	return SERIAL_GAUGE_SUCCESS;
}

static int block_read_power_i2c(struct serial_gauge_device *di, u8 *data, u16 rlen)
{
	int ret;
	u8 read_cmd[SERIAL_GAUGE_CMD_LEN] = { 0 };

	read_cmd[0] = di->i2c_info.read_data[0];
	if (di->support_i2c_crc)
		ret = power_i2c_read_block_with_crc(di->i2c, read_cmd, sizeof(read_cmd), data, rlen);
	else
		ret = power_i2c_read_block(di->i2c,  read_cmd, sizeof(read_cmd), data, rlen);

	return ret;
}

static int block_write_power_i2c(struct serial_gauge_device *di, u16 wlen)
{
	int ret;

	if (di->support_i2c_crc)
		ret = power_i2c_write_block_with_crc(di->i2c, di->i2c_info.write_data, wlen);
	else
		ret = power_i2c_write_block(di->i2c, di->i2c_info.write_data, wlen);

	return ret;
}

static int serial_gauge_i2c_block(char *buf, int size)
{
	int i;
	int ret = 0;
	u16 offset = 0;
	u16 wlen, rlen;
	char info[SERIAL_GAUGE_SYSFS_SHOW_STR_LEN] = { 0 };
	u8 data[SERIAL_GAUGE_DATA_MAX_LEN] = { 0 };
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return snprintf_s(buf, size, size - 1, "di get failed, is NULL\n");

	if (judge_is_running_upgrade())
		return snprintf_s(buf, size, size - 1, "curr upgrade running, not allow i2c communicate\n");
	
	wlen = di->i2c_info.write_len;
	rlen = di->i2c_info.read_len;
	di->i2c_info.read_len = 0;
	di->i2c_info.write_len = 0;
	hwlog_info("write len: %d, read len: %d", wlen, rlen);
	if (rlen >= SERIAL_GAUGE_DATA_MAX_LEN)
		return snprintf_s(buf, size, size - 1, "rlen over limit %d\n", SERIAL_GAUGE_DATA_MAX_LEN);
	mutex_lock(di->rw_lock);
	if (wlen > 0)
		ret = block_write_power_i2c(di, wlen);

	if (ret)
		goto unlock;

	if (rlen > 0)
		ret = block_read_power_i2c(di, data, rlen);
unlock:
	mutex_unlock(di->rw_lock);
	if (ret) {
		hwlog_err("gauge operation fail, ret = %d\n", ret);
		return snprintf_s(buf, size, size - 1, "gauge operation fail, ret = %d\n", ret);
	}

	for (i = 0; i < rlen; i++) {
		ret = snprintf_s(info + offset, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN - offset,
			SERIAL_GAUGE_SYSFS_SHOW_STR_LEN - offset - 1, " %02x", data[i]);
		if (ret <= 0)
			return snprintf_s(buf, size, size - 1, "data print failed\n");
		offset += ret;
	}

	return snprintf_s(buf, size, size - 1, "%s\n", info);
}

static ssize_t serial_gauge_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);
static ssize_t serial_gauge_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info serial_gauge_sysfs_field_tbl[] = {
	power_sysfs_attr_rw(serial_gauge, 0660, SERIAL_GAUGE_SYSFS_CHECK_DOWNLOAD, check_download),
	power_sysfs_attr_rw(serial_gauge, 0660, SERIAL_GAUGE_SYSFS_DOWNLOAD_RESULT, download_result),
	power_sysfs_attr_rw(serial_gauge, 0660, SERIAL_GAUGE_SYSFS_DEBUG, debug),
	power_sysfs_attr_rw(serial_gauge, 0660, SERIAL_GAUGE_SYSFS_RETRIEVE, retrieve),
	power_sysfs_attr_rw(serial_gauge, 0660, SERIAL_GAUGE_SYSFS_I2C_OPERATION, gauge_operation),
};

#define SERIAL_GAUGE_SYSFS_ATTRS_SIZE ARRAY_SIZE(serial_gauge_sysfs_field_tbl)
static struct attribute *serial_gauge_sysfs_attrs[SERIAL_GAUGE_SYSFS_ATTRS_SIZE + 1];

static const struct attribute_group serial_gauge_sysfs_attr_group = {
	.attrs = serial_gauge_sysfs_attrs,
};

static ssize_t serial_gauge_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;

	info = power_sysfs_lookup_attr(attr->attr.name,
		serial_gauge_sysfs_field_tbl, SERIAL_GAUGE_SYSFS_ATTRS_SIZE);
	if (!info)
		return -EINVAL;

	switch (info->name) {
	case SERIAL_GAUGE_SYSFS_CHECK_DOWNLOAD:
		return check_download_status(buf, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN);
	case SERIAL_GAUGE_SYSFS_DOWNLOAD_RESULT:
		return get_download_result(buf, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN);
	case SERIAL_GAUGE_SYSFS_ERASE_BOOT:
		return erase_boot_first_sector(buf, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN);
	case SERIAL_GAUGE_SYSFS_DEBUG:
		return serial_gauge_debug_info(buf, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN);
	case SERIAL_GAUGE_SYSFS_RETRIEVE:
		return serial_gauge_retrieve_info(buf, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN);
	case SERIAL_GAUGE_SYSFS_I2C_OPERATION:
		return serial_gauge_i2c_block(buf, SERIAL_GAUGE_SYSFS_SHOW_STR_LEN);
	default:
		return 0;
	}
}

static ssize_t serial_gauge_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	u8 cmd_type = 0;
	u16 param = 0;
	int data = 0;
	struct power_sysfs_attr_info *info = NULL;
	struct serial_gauge_device *di = serial_gauge_get_di();

	info = power_sysfs_lookup_attr(attr->attr.name,
		serial_gauge_sysfs_field_tbl, SERIAL_GAUGE_SYSFS_ATTRS_SIZE);
	if (!info || !di)
		return -EINVAL;

	switch (info->name) {
	case SERIAL_GAUGE_SYSFS_DEBUG:
		if (sscanf_s(buf, "%04x %02x", &param, &cmd_type) <= 0)
			return -EINVAL;

		hwlog_info("buf: %s, count:%d, cmd_type: %02x, sub_cmd: %04x\n", buf, count, cmd_type, param);
		ret = serial_gauge_debug(param, cmd_type);
		if (ret)
			return -EINVAL;
		break;
	case SERIAL_GAUGE_SYSFS_RETRIEVE:
		if (sscanf_s(buf, "%10d", &data) <= 0)
			return -EINVAL;

		hwlog_info("buf: %s, count:%d, data: %d\n", buf, count, data);
		ret = serial_gague_retrieve_set(data);
		if (ret)
			return -EINVAL;
		break;
	case SERIAL_GAUGE_SYSFS_I2C_OPERATION:
		if (parse_str_gauge_operation(di, buf, count))
			return -EINVAL;
		break;
	default:
		break;
	}

	return count;
}

static struct device *serial_gauge_sysfs_create_group(void)
{
	power_sysfs_init_attrs(serial_gauge_sysfs_attrs,
		serial_gauge_sysfs_field_tbl, SERIAL_GAUGE_SYSFS_ATTRS_SIZE);
	return power_sysfs_create_group("hw_power", "serial_gauge",
		&serial_gauge_sysfs_attr_group);
}

/* remove the cbm8580 device sysfs group */
static void serial_gauge_sysfs_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &serial_gauge_sysfs_attr_group);
}

#else
static struct device *serial_gauge_sysfs_create_group(void)
{
	return 0;
}

static inline void serial_gauge_sysfs_remove_group(struct device *dev)
{
	/* do nothing */
}
#endif /* CONFIG_SYSFS */

void serial_gauge_sysfs_start(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di) {
		hwlog_err("%s self dev chip init failed", __func__);
		return;
	}

	di->sysfs_dev = serial_gauge_sysfs_create_group();
}

void serial_gauge_sysfs_end(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	serial_gauge_sysfs_remove_group(di->sysfs_dev);
}