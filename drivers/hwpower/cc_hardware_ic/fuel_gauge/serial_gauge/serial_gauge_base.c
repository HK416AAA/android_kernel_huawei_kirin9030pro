// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gague_base.c
 *
 * serial gauge base driver
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

#include "serial_gauge_base.h"

#include <securec.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG serial_gauge_base
HWLOG_REGIST();

static struct serial_gauge_device *g_self_dev;

struct serial_gauge_device *serial_gauge_get_di(void)
{
	if (!g_self_dev) {
		hwlog_err("self algorithm device get failed\n");
		return NULL;
	}

	return g_self_dev;
}

int serial_gauge_read_word(u8 reg, u16 *data)
{
	int ret;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di || !data)
		return -EINVAL;

	mutex_lock(di->rw_lock);
	if (di->support_i2c_crc)
		ret = power_i2c_u8_read_word_with_crc(di->i2c, reg, data, false);
	else
		ret = power_i2c_u8_read_word(di->i2c, reg, data, false);
	mutex_unlock(di->rw_lock);
	if (ret < 0)
		hwlog_err("self algorithm read word reg=0x%x read fail\n", reg);

	return ret;
}

int serial_gauge_read_block(u8 reg, u8 *buf, u8 buf_len)
{
	int ret;
	u8 cmd[SERIAL_GAUGE_CMD_LEN] = { 0 };
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di || !buf)
		return -EINVAL;

	cmd[0] = reg;
	mutex_lock(di->rw_lock);
	if (di->support_i2c_crc)
		ret = power_i2c_read_block_with_crc(di->i2c, cmd, sizeof(cmd), buf, buf_len);
	else
		ret = power_i2c_read_block(di->i2c, cmd, sizeof(cmd), buf, buf_len);
	mutex_unlock(di->rw_lock);
	if (ret < 0)
		hwlog_err("self algorithm reg=0x%x read block fail\n", reg);

	return ret;
}

int serial_gauge_write_block(u8 reg, u8 *buf, u8 buf_len)
{
	int ret;
	u8 *cmd = NULL;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di || !buf)
		return -EINVAL;

	cmd = kcalloc(SERIAL_GAUGE_CMD_LEN + buf_len, sizeof(u8), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd[0] = reg;
	(void)memcpy_s(&cmd[SERIAL_GAUGE_CMD_LEN], buf_len, buf, buf_len);

	mutex_lock(di->rw_lock);
	if (di->support_i2c_crc)
		ret = power_i2c_write_block_with_crc(di->i2c, cmd, SERIAL_GAUGE_CMD_LEN + buf_len);
	else
		ret = power_i2c_write_block(di->i2c, cmd, SERIAL_GAUGE_CMD_LEN + buf_len);
	mutex_unlock(di->rw_lock);
	if (ret < 0)
		hwlog_err("reg=0x%x write block fail, ret = %d\n", reg, ret);
	kfree(cmd);

	return ret;
}

int serial_gauge_write_read_block(u8 *wr_buf, u8 wbuf_len, u8 *rd_buf, u8 rbuf_len)
{
	int ret;
	u8 read_cmd[SERIAL_GAUGE_CMD_LEN] = { 0 };
	u8 *write_cmd = NULL;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di || !wr_buf || !rd_buf)
		return -EINVAL;

	write_cmd = kcalloc(SERIAL_GAUGE_CMD_LEN + wbuf_len, sizeof(u8), GFP_KERNEL);
	if (!write_cmd)
		return -ENOMEM;

	write_cmd[0] = SERIAL_GAUGE_BLOCK_ADDR;
	(void)memcpy_s(&write_cmd[SERIAL_GAUGE_CMD_LEN], wbuf_len, wr_buf, wbuf_len);

	read_cmd[0] = SERIAL_GAUGE_BLOCK_ADDR;
	mutex_lock(di->rw_lock);
	if (di->support_i2c_crc)
		ret = power_i2c_write_block_with_crc(di->i2c, write_cmd, SERIAL_GAUGE_CMD_LEN + wbuf_len);
	else
		ret = power_i2c_write_block(di->i2c, write_cmd, SERIAL_GAUGE_CMD_LEN + wbuf_len);

	if (ret < 0)
		goto unlock;

	if (di->block_delay > 0)
		power_msleep(di->block_delay, 0, NULL);

	if (di->support_i2c_crc)
		ret = power_i2c_read_block_with_crc(di->i2c, read_cmd, sizeof(read_cmd), rd_buf, rbuf_len);
	else
		ret = power_i2c_read_block(di->i2c, read_cmd, sizeof(read_cmd), rd_buf, rbuf_len);

unlock:
	mutex_unlock(di->rw_lock);
	kfree(write_cmd);
	if (ret < 0)
		hwlog_err("write_and_read block fail, ret = %d\n", ret);

	return ret;
}

int serial_gauge_write_read_check_block(u8 *wr_buf, u8 wbuf_len, u8 *rd_buf, u8 rbuf_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 read_cmd[SERIAL_GAUGE_CMD_LEN] = { 0 };
	u8 *write_cmd = NULL;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di || !wr_buf || !rd_buf)
		return -EINVAL;

	write_cmd = kcalloc(SERIAL_GAUGE_CMD_LEN + wbuf_len, sizeof(u8), GFP_KERNEL);
	if (!write_cmd)
		return -ENOMEM;

	write_cmd[0] = SERIAL_GAUGE_BLOCK_ADDR;
	(void)memcpy_s(&write_cmd[SERIAL_GAUGE_CMD_LEN], wbuf_len, wr_buf, wbuf_len);

	read_cmd[0] = SERIAL_GAUGE_BLOCK_ADDR;
	mutex_lock(di->rw_lock);
	if (di->support_i2c_crc)
		ret = power_i2c_write_block_with_crc(di->i2c, write_cmd, SERIAL_GAUGE_CMD_LEN + wbuf_len);
	else
		ret = power_i2c_write_block(di->i2c, write_cmd, SERIAL_GAUGE_CMD_LEN + wbuf_len);

	if (ret < 0)
		goto unlock;
	while (retry--) {
		if (di->block_delay > 0)
			power_msleep(di->block_delay, 0, NULL);

		if (di->support_i2c_crc)
			ret = power_i2c_read_block_with_crc(di->i2c, read_cmd, sizeof(read_cmd), rd_buf, rbuf_len);
		else
			ret = power_i2c_read_block(di->i2c, read_cmd, sizeof(read_cmd), rd_buf, rbuf_len);
		if (!ret)
			goto unlock;

		hwlog_err("read block try[%d] fail, ret = %d\n", retry, ret);
	}
unlock:
	mutex_unlock(di->rw_lock);
	kfree(write_cmd);
	if (ret < 0)
		hwlog_err("write_and_read block fail, ret = %d\n", ret);

	return ret;
}

struct file *serial_gauge_open_file(const char *path)
{
	struct file *fp = NULL;

	if (!path)
		return NULL;

	fp = filp_open(path, O_RDONLY, 0);
	if (!IS_ERR(fp))
		return fp;

	hwlog_info("%s: file %s not exist, err: %d\n", __func__, path, PTR_ERR(fp));
	return NULL;
}

struct file *serial_gauge_try_to_get_file(const char *path)
{
	struct file *fp = NULL;
	int try_num = GET_FILE_TRY_NUM;

	hwlog_info("filepath: %s\n", path);
	while (try_num--) {
		fp = serial_gauge_open_file(path);
		if (!fp || IS_ERR(fp)) {
			hwlog_err("File[%d]: not exist, err: %d\n", try_num, PTR_ERR(fp));
			power_msleep(GET_FILE_ERROR_WAIT_TIME_MS, 0, NULL);
			continue;
		}
		break;
	}
	return fp;
}

int serial_gauge_file_read(struct file *fp, u8 *file_buf, size_t file_size,
	u32 offset)
{
	int ret;
	mm_segment_t old_fs;
	loff_t start;
	loff_t pos = offset;

	if (!fp || !file_buf)
		return SERIAL_GAUGE_FAILED;

	start = offset;
	old_fs = get_fs();
	set_fs(KERNEL_DS);
	ret = vfs_read(fp, file_buf, file_size, &pos);
	set_fs(old_fs);
	hwlog_info("start: %08x, pos: %08x, file_size: %08x\n", start, pos, file_size);
	if (ret <= 0 || (pos - start != file_size)) {
		hwlog_err("file read failed, ret = %d", ret);
		return SERIAL_GAUGE_FAILED;
	}

	return SERIAL_GAUGE_SUCCESS;
}

void serial_gauge_register(struct i2c_client *i2c, struct device_node *dts_node,
	struct mutex *rw_lock)
{
	struct serial_gauge_device *l_dev = NULL;

	if (!i2c || !dts_node || !rw_lock) {
		hwlog_err("param had one or three is null\n");
		return;
	}

	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return;

	l_dev->i2c = i2c;
	l_dev->dev = &i2c->dev;
	l_dev->dts_node = dts_node;
	l_dev->rw_lock = rw_lock;
	g_self_dev = l_dev;

	hwlog_info("self algorithm register success!");
}

void serial_gauge_unregister(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	kfree(di);
	g_self_dev = NULL;
	hwlog_info("self algorithm unregister success!");
}

int judge_is_running_upgrade(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return SERIAL_GAUGE_SUCCESS;

	if (di->upgrade_run == 1)
		return SERIAL_GAUGE_FAILED;

	return SERIAL_GAUGE_SUCCESS;
}