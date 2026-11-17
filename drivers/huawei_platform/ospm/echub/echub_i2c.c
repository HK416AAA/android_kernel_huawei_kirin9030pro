/*
 * echub_i2c.c
 *
 * I2C driver for echub
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/regmap.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/mfd/core.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <securec.h>
#include "ospm_printf.h"
#include "echub_i2c.h"

static int major;
static struct class *class;
struct echub_i2c_dev *g_echub_dev = NULL;

static struct mfd_cell echubs[] = {
	{
		.name = "echub-hmi",
		.of_compatible = "huawei,echub-hmi",
	},
	{
		.name = "echub-power",
		.of_compatible = "huawei,echub-power",
	},
	{
		.name = "echub_battery",
		.of_compatible = "huawei,echub_battery",
	},
	{
		.name = "echub-muteled",
		.of_compatible = "huawei,echub-muteled",
	},
	{
		.name = "echub-lid",
		.of_compatible = "huawei,echub-lid",
	},
	{
		.name = "echub-fnled",
		.of_compatible = "huawei,echub-fnled",
	},
	{
		.name = "echub_keyboard_smart_led",
		.of_compatible = "huawei,echub_keyboard_smart_led",
	},
	{
		.name = "echub_thermal",
		.of_compatible = "huawei,echub_thermal",
	},
	{
		.name = "echub-log",
		.of_compatible = "huawei,echub-log",
	},
	{
		.name = "echub-update",
		.of_compatible = "huawei,echub-update",
	},
	{
		.name = "echub_charge_status",
		.of_compatible = "huawei,echub_charge_status",
	},
	{
		.name = "echub_wakealarm",
		.of_compatible = "huawei,echub_wakealarm",
	},
	{
		.name = "echub-rtc",
		.of_compatible = "huawei,echub-rtc",
	},
	{
		.name = "echub_overheat",
		.of_compatible = "huawei,echub_overheat",
	},
	{
		.name = "echub_fan0",
		.of_compatible = "huawei,echub_fan0",
	},
	{
		.name = "echub_mcu_state_sync",
		.of_compatible = "huawei,echub_mcu_state_sync",
	},
	{
		.name = "echub_thermal_zone_sync",
		.of_compatible = "huawei,echub_thermal_zone_sync",
	},
	{
		.name = "echub_charger",
		.of_compatible = "huawei,echub_charger",
	},
	{
		.name = "echub_chargedata",
		.of_compatible = "huawei,echub_chargedata",
	},
	{
		.name = "echub_decimal",
		.of_compatible = "huawei,echub_decimal",
	},
	{
		.name = "echub_ladder_standby",
		.of_compatible = "huawei,echub_ladder_standby",
	},
	{
		.name = "echub_tablet_switch",
		.of_compatible = "huawei,echub_tablet_switch",
	},
	{
		.name = "echub_pogopin",
		.of_compatible = "huawei,echub_pogopin",
	}
};

struct echub_i2c_dev *get_echub_dev(void)
{
	return g_echub_dev;
}

static unsigned char calc_pec(unsigned char sourcebyte, unsigned char pec)
{
	unsigned char data = 0;
	unsigned char crc = 0;
	static const u8 pecTable[] = {
		0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15,
		0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D
	};

	data = pec ^ sourcebyte;
	crc = (crc << CRC_SHIFT) ^ pecTable[((crc ^ data) >> CRC_SHIFT) & CRC_MASK];
	data <<= CRC_SHIFT;
	pec = (crc << CRC_SHIFT) ^ pecTable[((crc ^ data) >> CRC_SHIFT) & CRC_MASK];

	return pec;
}

static unsigned char calc_multi_pec(u8 *buf, int len, unsigned char pec)
{
	int i = 0;
	unsigned char tmp = pec;

	for (i = 0; i < len; i++)
		tmp = calc_pec(buf[i], tmp);
	return tmp;
}

static unsigned char calc_layer_pec(struct i2c_msg *msg, int rlen)
{
    unsigned char addr;
    unsigned char pec  = 0;
// low---->high
// addr + cmdtype + cmd + sendlen + data + recv
    addr = msg[0].addr << 1;

    pec = calc_pec(addr, pec);    // i2c write addr: addr << 1
    pec = calc_multi_pec(msg[0].buf, msg[0].len, pec);
    pec = calc_pec(addr + 1, pec);    // i2c read addr: addr << 1 + 1
    pec = calc_multi_pec(msg[1].buf, rlen, pec);

	return pec;
}

static int echub_i2c_pec_check(struct i2c_msg *msg)
{
	unsigned char pecRead;
	unsigned char pecCalc;
	int recvLen;

	if (msg[1].len > CALLBACK_LEN) {
		pecRead = msg[1].buf[msg[1].len - 1];
		recvLen = msg[1].len - 1;
	} else if (msg[1].len == CALLBACK_LEN) {
		pecRead = msg[1].buf[CALLBACK_LEN - 1];
		recvLen = 1;
	} else {
		echub_err("%s: read len(%d) error!\n", __func__, msg[1].len);
		return -EINVAL;
	}

    pecCalc = calc_layer_pec(msg, recvLen);
    if (pecCalc != pecRead) {
		echub_err("%s: pec error, pec read/calc(%x/%x).\n", __func__, pecRead, pecCalc);
        return -EINVAL;
    }
    return EOK;
}

/**
 * echub_i2c_read - read data from EC
 * @echub_dev: i2c device
 * @regoffset: data register address offset
 * @regdata: the data flag to read
 * @value: buffer of read value
 * @bytes: the byte length of @value
 *
 * return value: 0-sucess or others-fail
 */
int echub_i2c_read(struct echub_i2c_dev *echub_dev, int regoffset,
			char regdata, char *value, int bytes)
{
	int ret;
	struct i2c_client *client = echub_dev->client;
	struct i2c_msg msg[2];
	unsigned char data[4] = {0};

	if (!client) {
		echub_err("[%s:%dL] client is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	/* write data buffer */
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = ECHUB_SEND_BYTE_LEN;
	msg[0].buf = data;
	data[0] = (u8)(regoffset >> BIT_OFFSET);
	data[1] = (u8)(regoffset & 0xFF);
	data[2] = REG_DATA_LEN; // 2: index
	data[3] = regdata; // 3: index
	/* read data buffer */
	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = bytes;
	msg[1].buf = value;

	mutex_lock(&echub_dev->lock);
	ret = i2c_transfer(client->adapter, msg, ECHUB_SEND_TRANS_LEN);
	mutex_unlock(&echub_dev->lock);

	/* check i2c transfer result */
	if (ret != ECHUB_SEND_TRANS_LEN)
		return -ENODEV;
	if (value[0]) {
		echub_err("%s failed, value[0] = %d\n", __func__, value[0]);
		return -EIO;
	}
	if (value[1] != 1 && value[1] != 2) { // 2: 2byte
		echub_err("%s failed, regoffset = 0x%04x, value[1] = %d\n", __func__, regoffset, value[1]);
		return -EINVAL;
	}
	if (echub_i2c_pec_check(msg) != 0) {
		echub_err("%s, pec calc failed!\n", __func__);
		return -EINVAL;
	}
	return 0;
}

/**
 * echub_i2c_write - write data to EC
 * @echub_dev: i2c device
 * @regoffset: data register address offset
 * @regdata: the data to write
 *
 * return value: 0-sucess or others-fail
 */
int echub_i2c_write(struct echub_i2c_dev *echub_dev, int regoffset, char regdata)
{
	int ret;
	struct i2c_client *client = echub_dev->client;
	struct i2c_msg msg[2];
	unsigned char data[4];
	unsigned char value[2] = {0};

	if (!client) {
		echub_err("[%s:%dL] client is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	/* write data buffer */
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = ECHUB_SEND_BYTE_LEN;
	msg[0].buf = data;
	data[0] = (u8)(regoffset >> BIT_OFFSET);
	data[1] = (u8)(regoffset & 0xFF);
	data[2] = REG_DATA_LEN; // 2: index
	data[3] = regdata; // 3: index

	/* read data buffer */
	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = ECHUB_SEND_TRANS_LEN;
	msg[1].buf = value;

	mutex_lock(&echub_dev->lock);
	ret = i2c_transfer(client->adapter, msg, ECHUB_SEND_TRANS_LEN);
	mutex_unlock(&echub_dev->lock);
	/* check i2c transfer result */
	if (ret != ECHUB_SEND_TRANS_LEN)
		return -ENODEV;
	if (value[0])
		return -EIO;
	if (echub_i2c_pec_check(msg) != 0) {
		echub_err("%s, pec calc failed!\n", __func__);
		return -EINVAL;
	}
	return 0;
}

static int config_transfer_msg(struct i2c_msg *msg, struct echub_i2c_dev *echub_dev, int regoffset,
			unsigned char *wbuf, int wblen, unsigned char *rbuf, int rblen)
{
	int ret = EOK;
	struct i2c_client *client = echub_dev->client;

	msg[0].buf = kmalloc(ECHUB_I2C_WRITE_DATA_HEAD + wblen, GFP_KERNEL);
	if (!(msg[0].buf))
		return -ENOMEM;
	(msg[0].buf)[0] = (u8)(regoffset >> BIT_OFFSET);
	(msg[0].buf)[1] = (u8)(regoffset & 0xFF);
	(msg[0].buf)[2] = wblen; // 2: index
	if (wbuf != NULL && wblen != 0) {
		ret = memcpy_s(&(msg[0].buf)[ECHUB_I2C_WRITE_DATA_HEAD], wblen, wbuf, wblen);
		if (ret != EOK) {
			kfree(msg[0].buf);
			return -EINVAL;
		}
	}
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = ECHUB_I2C_WRITE_DATA_HEAD + wblen;

	/* read data buffer */
	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = (rbuf != NULL && rblen != 0) ? ECHUB_SEND_TRANS_LEN + 0x1 + rblen : ECHUB_SEND_TRANS_LEN;
	msg[1].buf = kmalloc(msg[1].len, GFP_KERNEL);
	if (!(msg[1].buf)) {
		kfree(msg[0].buf);
		return -EINVAL;
	}

	mutex_lock(&echub_dev->lock);
	ret = i2c_transfer(client->adapter, msg, ECHUB_SEND_TRANS_LEN);
	mutex_unlock(&echub_dev->lock);
	if (ret != ECHUB_SEND_TRANS_LEN || (msg[1].buf)[0] != 0) {
		echub_err("%s i2c transfer error, ret = 0x%x, msg[1].buf[0] = 0x%x\n", __func__, ret, (msg[1].buf)[0]);
		ret = -EIO;
		goto free_r_mem;
	}

	if (echub_i2c_pec_check(msg) != 0) {
		echub_err("%s, pec calc failed!\n", __func__);
		goto free_r_mem;
	}

	ret = 0;
	if (rbuf != NULL && rblen != 0) {
		ret = memcpy_s(rbuf, rblen, &(msg[1].buf)[NUM_2], rblen);
		if (ret != EOK)
			echub_err("%s: rb memcpy failed!\n", __func__);
	}

free_r_mem:
	kfree(msg[1].buf);
	kfree(msg[0].buf);
	return ret;
}

int echub_i2c_transfer(struct echub_i2c_dev *echub_dev, int regoffset, unsigned char *wb, int wblen,
			unsigned char *rb, int rblen)
{
	int ret = 0;
	struct i2c_msg msg[2];
	struct i2c_client *client = echub_dev->client;

	if (!client || (wb == NULL && rb == NULL) || wblen > ECHUB_I2C_MSG_MAX_LEN || rblen > ECHUB_I2C_MSG_MAX_LEN) {
		echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	ret = config_transfer_msg(msg, echub_dev, regoffset, wb, wblen, rb, rblen);
	if (ret != 0) {
		echub_err("[%s:%dL] config_transfer_msg failed\n", __func__, __LINE__);
		return -EINVAL;
	}

	return ret;
}

static struct file_operations echub_i2c_fops = {
	.owner = THIS_MODULE,
	/* add fops used in user space */
};

static int echub_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int err;
	struct echub_i2c_dev *echub_dev = NULL;

	echub_info("%s enter\n", __func__);

	echub_dev = devm_kzalloc(&client->dev, sizeof(struct echub_i2c_dev), GFP_KERNEL);
	if (echub_dev == NULL) {
		echub_err("%s kzalloc fail\n", __func__);
		return -ENOMEM;
	}

	echub_dev->dev = &client->dev;

	/* init struct echub_i2c_dev echub_i2c_data */
	mutex_init(&echub_dev->lock);
	echub_dev->client = client;
	echub_dev->write_func = echub_i2c_write;
	echub_dev->read_func = echub_i2c_read;
	echub_dev->transfer_func = echub_i2c_transfer;

	i2c_set_clientdata(client, echub_dev);
	/* set i2c data  tmp */
	g_echub_dev = echub_dev;

	err = devm_mfd_add_devices(echub_dev->dev, -1, echubs,
				  ARRAY_SIZE(echubs), NULL, 0, NULL);
	if (err) {
		echub_err("add mfd devices failed with err: %d\n", err);
		return -EFAULT;
	}

	/*
	 * Create a char device named echub_i2c with echub_i2c_fops
	 * /dev/echub_i2c
	 */
	major = register_chrdev(0, "echub_i2c", &echub_i2c_fops);
	if (major < 0) {
		echub_err("register echub_i2c dev fail\n");
		return -EFAULT;
	}
	class = class_create(THIS_MODULE, "echub_i2c");
	if (IS_ERR(class)) {
		echub_err("class_create echub_i2c fail\n");
		err = -EFAULT;
		goto err_class_create;
	}
	device_create(class, NULL, MKDEV(major, 0), NULL, "echub_i2c");
	echub_info("%s ok\n", __func__);

	return 0;
err_class_create:
    unregister_chrdev(major, "echub_i2c");
	g_echub_dev = NULL;
	return err;
}


static int echub_i2c_remove(struct i2c_client *client)
{
	echub_info("%s\n", __func__);
	device_destroy(class, MKDEV(major, 0));
	class_destroy(class);
	unregister_chrdev(major, "echub_i2c");
	g_echub_dev = NULL;

	return 0;
}

static const struct of_device_id echub_i2c_of_match[] = {
	{ .compatible = "huawei,echub_i2c" },
	{},
};

MODULE_DEVICE_TABLE(of, echub_i2c_of_match);

static const struct i2c_device_id echub_i2c_id_table[] = {
	{ "echub_i2c", 0 },
	{ },
};

MODULE_DEVICE_TABLE(i2c, echub_i2c_id_table);

static struct i2c_driver echub_i2c_driver = {
	.driver = {
		.name           = "echub_i2c",
		.of_match_table = of_match_ptr(echub_i2c_of_match),
	},

	.probe       = echub_i2c_probe,
	.remove      = echub_i2c_remove,
	.id_table    = echub_i2c_id_table,
};

static int __init echub_i2c_init(void)
{
	echub_info("%s\n", __func__);
	return i2c_add_driver(&echub_i2c_driver);
}
module_init(echub_i2c_init);

static void __exit echub_i2c_exit(void)
{
	echub_info("%s\n", __func__);
	i2c_del_driver(&echub_i2c_driver);
}
module_exit(echub_i2c_exit);

MODULE_ALIAS("armpc echub i2c module");
MODULE_DESCRIPTION("armpc echub i2c driver");
MODULE_LICENSE("GPL");
