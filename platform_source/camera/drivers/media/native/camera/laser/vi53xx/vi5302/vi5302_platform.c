/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/slab.h>

#include "vi5302_platform.h"

static int32_t vi5302_i2c_write(vi5302_dev dev, uint16_t reg, uint8_t *data, uint8_t len)
{
	int ret = 0;
	uint8_t *addr_buf;
	struct i2c_msg msg;
	struct i2c_client *client = dev->client;

	if(!client)
		return -EINVAL;
	addr_buf = kmalloc(len + 2, GFP_KERNEL);
	if (!addr_buf)
		return -ENOMEM;
	addr_buf[0] = reg >> 8;
	addr_buf[1] = reg & 0xFF;
	if (memcpy_s(&addr_buf[2], len, data, len) != EOK) {
		pr_err("memcpy error\n");
		return -1;
	}
	msg.addr = client->addr;
	msg.flags = 0;
	msg.buf = addr_buf;
	msg.len = len + 2;

	ret = i2c_transfer(client->adapter, &msg, 1);
	if(ret != 1) {
		pr_err("%s: i2c_transfer err:%d, addr:0x%x, reg:0x%x\n",
			__func__, ret, client->addr, reg);
		laser_dsm_report_dmd(HWLASER_VI5300, DSM_LASER_I2C_ERROR_NO);
	}
	kfree(addr_buf);
	addr_buf = NULL;
	return ret < 0 ? ret : (ret != 1 ? -EIO : 0);
}

static int32_t vi5302_i2c_read(vi5302_dev dev, uint16_t reg, uint8_t *data, uint8_t len)
{
	int ret = 0;
	struct i2c_msg msg[2];
	struct i2c_client *client = dev->client;
	uint8_t buff[2];

	if(!client)
		return -EINVAL;
	buff[0] = reg >> 8;
	buff[1] = reg & 0xFF;
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = buff;
	msg[0].len = 2;

	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].buf = data;
	msg[1].len = len;
	ret = i2c_transfer(client->adapter, msg, 2);
	if(ret != 2) {
		pr_err("%s: i2c_transfer err:%d, addr:0x%x, reg:0x%x\n",
			__func__, ret, client->addr, reg);
		laser_dsm_report_dmd(HWLASER_VI5300, DSM_LASER_I2C_ERROR_NO);
	}

	return ret < 0 ? ret : (ret != 2 ? -EIO : 0);
}

int32_t vi5302_write_byte(vi5302_dev dev, uint16_t reg, uint8_t data)
{
	return vi5302_i2c_write(dev, reg, &data, 1);
}

int32_t vi5302_read_byte(vi5302_dev dev, uint16_t reg, uint8_t *data)
{
	return vi5302_i2c_read(dev, reg, data, 1);
}

int32_t vi5302_write_multibytes(vi5302_dev dev, uint16_t reg, uint8_t *data, int32_t count)
{
	return vi5302_i2c_write(dev, reg, data, count);
}

int32_t vi5302_read_multibytes(vi5302_dev dev, uint16_t reg, uint8_t *data, int32_t count)
{
	return vi5302_i2c_read(dev, reg, data, count);
}

int32_t vi5302_write_reg_offset(vi5302_dev dev, uint16_t reg, uint8_t offset, uint8_t data)
{
	return vi5302_write_byte(dev, reg + offset, data);
}

int32_t vi5302_read_reg_offset(vi5302_dev dev, uint16_t reg, uint8_t offset, uint8_t *data)
{
	return vi5302_read_byte(dev, reg + offset, data);
}