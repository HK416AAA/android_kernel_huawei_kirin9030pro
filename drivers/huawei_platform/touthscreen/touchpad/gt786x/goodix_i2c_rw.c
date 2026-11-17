/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/firmware.h>

#include "goodix_ts_core.h"
#include "goodix_ts_log.h"

#define GT786X_I2C_RW_DELAY		200
#define I2C_MAX_TRANSFER_SIZE		256
#define GOODIX_BUS_RETRY_TIMES		2
#define GOODIX_REG_ADDR_SIZE		4
#define TS_ADDR_LENGTH			2
#define GOODIX_HID_RW_BUF_SIZE		64

struct i2c_client *g_i2c_client;

int _do_i2c_read(unsigned int reg, unsigned char *data, unsigned int len, struct i2c_msg *msgs)
{
    struct i2c_client *client = g_i2c_client;
    unsigned int transfer_length = 0, pos = 0, address = reg;
    int retry;

    while (pos != len) {
        if (unlikely(len - pos > I2C_MAX_TRANSFER_SIZE)) {
            transfer_length = I2C_MAX_TRANSFER_SIZE;
        } else {
            transfer_length = len - pos;
        }

        msgs[0].buf[0] = GOODIX_MOVE_8BIT(address) & 0xFF;
        msgs[0].buf[1] = address & 0xFF;
        msgs[1].len = transfer_length;

        for (retry = 0; retry < GOODIX_BUS_RETRY_TIMES; retry++) {
            if (likely(i2c_transfer(client->adapter, msgs, TS_ADDR_LENGTH) == TS_ADDR_LENGTH)) {
                memcpy_s(&data[pos], transfer_length, msgs[1].buf, transfer_length);
                pos += transfer_length;
                address += transfer_length;
                udelay(GT786X_I2C_RW_DELAY);
                break;
            }
            ts_info("I2c read retry[%d]:0x%x", retry + 1, reg);
            msleep(GOODIX_DELAY_20MS);
        }
        if (unlikely(retry == GOODIX_BUS_RETRY_TIMES)) {
            ts_err("I2c read failed,dev:%02x,reg:%04x,size:%u",
                   client->addr, reg, len);
            return -EFAULT;
        }
    }
    return 0;
}

int dev_i2c_read(unsigned int reg, unsigned char *data, unsigned int len)
{
    struct i2c_client *client = g_i2c_client;
    unsigned char get_buf[GOODIX_HID_RW_BUF_SIZE], addr_buf[TS_ADDR_LENGTH];
    int r = 0;

    struct i2c_msg msgs[] = {
        {
            .addr = client->addr,
            .flags = !I2C_M_RD,
            .buf = &addr_buf[0],
            .len = TS_ADDR_LENGTH,
        }, {
            .addr = client->addr,
            .flags = I2C_M_RD,
        }
    };

    if (likely(len < sizeof(get_buf))) {
        /* code optimize, use stack memory */
        msgs[1].buf = &get_buf[0];
    } else {
        msgs[1].buf = kzalloc(I2C_MAX_TRANSFER_SIZE < len ? I2C_MAX_TRANSFER_SIZE : len, GFP_KERNEL);
        if (msgs[1].buf == NULL) {
            return -ENOMEM;
        }
    }

    r = _do_i2c_read(reg, data, len, msgs);

    if (unlikely(len >= sizeof(get_buf))) {
        kfree(msgs[1].buf);
    }
    return r;
}

/**
 * goodix_i2c_write - write device register through i2c bus
 * @dev: pointer to device data
 * @addr: register address
 * @data: write buffer
 * @len: bytes to write
 * return: 0 - write ok; < 0 - i2c transter error.
 */
int dev_i2c_write(unsigned int reg, unsigned char *data, unsigned int len)
{
    struct i2c_client *client = g_i2c_client;
    unsigned int pos = 0, transfer_length = 0, address = reg;
    unsigned char put_buf[GOODIX_HID_RW_BUF_SIZE];
    int retry, r = 0;
    struct i2c_msg msg = {
        .addr = client->addr,
        .flags = !I2C_M_RD,
    };

    if (likely(len + TS_ADDR_LENGTH < sizeof(put_buf))) {
        /* code optimize,use stack memory */
        msg.buf = &put_buf[0];
    } else {
        msg.buf = kmalloc(I2C_MAX_TRANSFER_SIZE < len + TS_ADDR_LENGTH ?
                          I2C_MAX_TRANSFER_SIZE : len + TS_ADDR_LENGTH, GFP_KERNEL);
        if (msg.buf == NULL) {
            return -ENOMEM;
        }
    }

    while (pos != len) {
        if (unlikely(len - pos > I2C_MAX_TRANSFER_SIZE - TS_ADDR_LENGTH)) {
            transfer_length = I2C_MAX_TRANSFER_SIZE - TS_ADDR_LENGTH;
        } else {
            transfer_length = len - pos;
        }

        msg.buf[0] = (unsigned char)(GOODIX_MOVE_8BIT(address) & 0xFF);
        msg.buf[1] = (unsigned char)(address & 0xFF);
        msg.len = transfer_length + TS_ADDR_LENGTH;
        memcpy_s(&msg.buf[TS_ADDR_LENGTH], transfer_length, &data[pos], transfer_length);

        for (retry = 0; retry < GOODIX_BUS_RETRY_TIMES; retry++) {
            if (likely(i2c_transfer(client->adapter, &msg, 1) == 1)) {
                pos += transfer_length;
                address += transfer_length;
                udelay(GT786X_I2C_RW_DELAY);
                break;
            }
            ts_debug("I2c write retry[%d]", retry + 1);
            msleep(GOODIX_DELAY_20MS);
        }
        if (unlikely(retry == GOODIX_BUS_RETRY_TIMES)) {
            ts_debug("I2c write failed,dev:%02x,reg:%04x,size:%u", client->addr, reg, len);
            r = -EFAULT;
            goto write_exit;
        }
    }
write_exit:
    if (likely(len + TS_ADDR_LENGTH >= sizeof(put_buf))) {
        kfree(msg.buf);
    }
    return r;
}

void dev_i2c_init(struct i2c_client *client)
{
    g_i2c_client = client;
}

#define GOODIX_RETRY_3 3
const struct firmware *goodix_request_firmware(const char *name)
{
    struct device *dev = &(g_i2c_client->dev);
    const struct firmware *firmware;
    int retry = GOODIX_RETRY_3;
    int r;

    ts_info("Request firmware image [%s]", name);

    while (retry--) {
        r = request_firmware(&firmware, name, dev);
        if (!r) {
            break;
        }
        ts_info("get fw bin retry:[%d]", GOODIX_RETRY_3 - retry);
        msleep(GOODIX_DELAY_200MS);
    }
    if (retry < 0) {
        ts_err("Firmware image [%s] not available,errno:%d", name, r);
        return NULL;
    }

    ts_info("Firmware image [%s] is ready", name);
    return firmware;
}