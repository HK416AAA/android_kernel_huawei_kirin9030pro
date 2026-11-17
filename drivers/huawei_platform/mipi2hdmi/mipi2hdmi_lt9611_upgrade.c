/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <securec.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/syscore_ops.h>
#include <linux/miscdevice.h>
#include <linux/sort.h>
#include <linux/workqueue.h>
#include <linux/gpio.h>
#include <linux/proc_fs.h>
#include "lt9611uxd_fw.h"
#include "lt9611uxc_fw.h"
#include "mipi2hdmi_lt9611.h"

#define READ_REG_VERSION_H1 0x21
#define READ_REG_VERSION_H2 0x20
#define ONE_BYTE_BITS 8
#define TWELVE_BITS 12
#define LT9611UXC_ADDR 0x2B
#define LT9611UXD_ADDR 0x41

#define I2C_WRITE_XFER_LEN 1
#define I2C_READ_XFER_LEN 2
#define I2C_REPEAT 3
#define I2C_ADAPTER 4
#define I2C_RECV_LEN 1
#define I2C_SEND_LEN 2

#define TIMER_DEBOUNCE 10
#define GPIO_OUT_HIGH 1
#define GPIO_OUT_LOW 0

#define PROC_NAME "proc_hdmi"
#define LT9611UXC_VERSION_PROCLEN 20
#define PROC_MODE 0444

#define GET_IC_VER_WAIT_ACK_TIMES 100
#define GET_IC_VER_DATA_SIZE 6
#define IC_VER_LOCATION1 4
#define IC_VER_LOCATION2 5
#define WORK_ADD_DLY_MS 1000
#define RETURN_DATA_REG 0x85

typedef enum {
    HDMI_CHIP_ECODE_OK = 0,
    HDMI_CHIP_ECODE_POWER_OFF,
    HDMI_CHIP_ECODE_UPDAE_ING,
    HDMI_CHIP_ECODE_PARA_INVALID,
    HDMI_CHIP_ECODE_I2C_COMM,
} hdmi_chip_ecode;

static struct i2c_client *g_lt9611ux_client = NULL;
static struct lt9611_fw_updater_data *g_pdata = NULL;
static bool g_update_finished = false;
static uint16_t g_at_chip_version = 0;
static int g_getVersion = 0;
static struct delayed_work fw_update_work;

static int lt9611ux_i2c_send_byte(char devaddr, const char regoffset, const char value)
{
    struct i2c_adapter *adap = NULL;
    int ret;
    char data[I2C_READ_XFER_LEN];
    struct i2c_msg msg[I2C_WRITE_XFER_LEN];
    int retries = I2C_REPEAT;
    unsigned char xfers = I2C_WRITE_XFER_LEN;

    adap = i2c_get_adapter(I2C_ADAPTER);
    if (!adap) {
        pr_info("lt9611ux_i2c_send_byte i2c_get_adapter err");
        return -ENODEV;
    }

    msg->addr = devaddr;
    msg->flags = 0;
    msg->len = I2C_SEND_LEN;
    msg->buf = data;
    data[0] = regoffset;
    data[1] = value;

    do {
        ret = i2c_transfer(adap, msg, xfers);
        pr_info("ret = %d", ret);
    } while (ret != xfers && --retries);
    pr_info("lt9611ux_i2c_send_byte regoffset = %d value=%d ret = %d \n", regoffset, value, ret);
    i2c_put_adapter(adap);
    if (ret == I2C_WRITE_XFER_LEN) {
        return 0;
    }
    return ret;
}

static int lt9611ux_i2c_recv_byte(char devaddr, const char regoffset, char *value)
{
    struct i2c_adapter *adap;
    int ret;
    struct i2c_msg msg[I2C_READ_XFER_LEN];
    int retries = I2C_REPEAT;
    unsigned char xfers = I2C_READ_XFER_LEN;

    adap = i2c_get_adapter(I2C_ADAPTER);
    if (!adap) {
        pr_info("lt9611ux_i2c_recv_byte i2c_get_adapter err");
        return -ENODEV;
    }

    msg[0].addr = devaddr;
    msg[0].flags = 0;
    msg[0].len = I2C_RECV_LEN;
    msg[0].buf = (uint8_t *)&regoffset;

    msg[1].addr = devaddr;
    msg[1].flags = 0x01;
    msg[1].len = I2C_RECV_LEN;
    msg[1].buf = value;
    do {
        ret = i2c_transfer(adap, msg, xfers);
        pr_info("ret = %d", ret);
    } while (ret != xfers && --retries);

    if (value != NULL) {
        pr_info("lt9611ux_i2c_recv_byte regoffset=%d value=%d ret = %d \n", regoffset, value[0], ret);
    }
    i2c_put_adapter(adap);
    if (ret == I2C_READ_XFER_LEN) {
        return 0;
    }
    return ret;
}

static void lt9611ux_fw_reset(void)
{
    if (g_lt9611ux_client == NULL) {
        return;
    }
    (void)g_pdata->reset_chip(g_lt9611ux_client, TIMER_DEBOUNCE);
}

static int lt9611uxc_get_version(unsigned short *ver)
{
    pr_info("[%s:] in\n", __func__);
    if (!g_update_finished) {
        pr_info("[%s:] invalid parameter g_update_finished\n", __func__);
        return HDMI_CHIP_ECODE_UPDAE_ING;
    }

    uint8_t version1 = 0;
    uint8_t version2 = 0;

    int ret;
    ret = lt9611ux_i2c_send_byte(LT9611UXC_ADDR, 0xFF, 0x80);
    if (ret != 0) {
        pr_info("[%s:] I2C communication failure\n", __func__);
        return ret;
    }

    lt9611ux_i2c_send_byte(LT9611UXC_ADDR, 0xFF, 0x80);
    lt9611ux_i2c_send_byte(LT9611UXC_ADDR, 0xEE, 0x01);
    lt9611ux_i2c_send_byte(LT9611UXC_ADDR, 0xFF, 0xB0);

    if (lt9611ux_i2c_recv_byte(LT9611UXC_ADDR, READ_REG_VERSION_H2, &version2) != 0) {
        pr_info("[%s:] read %x failed\n", __func__, READ_REG_VERSION_H2);
        return HDMI_CHIP_ECODE_I2C_COMM;
    }
    if (lt9611ux_i2c_recv_byte(LT9611UXC_ADDR, READ_REG_VERSION_H1, &version1) != 0) {
        pr_info("[%s:] read %x failed\n", __func__, READ_REG_VERSION_H1);
        return HDMI_CHIP_ECODE_I2C_COMM;
    }
    *ver = ((unsigned short)version1 << ONE_BYTE_BITS) | ((unsigned short)version2);

    lt9611ux_i2c_send_byte(LT9611UXC_ADDR, 0xFF, 0x80);
    lt9611ux_i2c_send_byte(LT9611UXC_ADDR, 0xEE, 0x00);

    pr_info("[%s:] success\n", __func__);
    return HDMI_CHIP_ECODE_OK;
}

static void lt9611uxd_ver_write_cmd(void)
{
    // Write Cmd Content
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xB0, 0x52);
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xB1, 0x43);
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xB2, 0x31);
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xB3, 0x3A);
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xB4, 0x00);
}

static int lt9611uxd_get_version(unsigned short *ver)
{
    pr_info("[%s:] in\n", __func__);
    if (!g_update_finished) {
        pr_info("[%s:] invalid parameter g_update_finished\n", __func__);
        return HDMI_CHIP_ECODE_UPDAE_ING;
    }

    uint8_t ic_ver1 = 0;
    uint8_t ic_ver2 = 0;
    unsigned char temp = 0;
    unsigned char count = 0;
    unsigned char rxbuff[6] = { 0 };

    int ret;
    ret = lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xFF, 0xE0);
    if (ret != 0) {
        pr_info("[%s:] I2C communication failure\n", __func__);
        return ret;
    }

    // Write Start
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xFF, 0xE0);
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xDE, 0x01);

    // Read Ack 01
    count = 0;
    do {
        lt9611ux_i2c_recv_byte(LT9611UXD_ADDR, 0xAE, &temp);
        msleep(1);
        count++;
    } while ((count < GET_IC_VER_WAIT_ACK_TIMES) && (temp != 0x01));
    if (count >= GET_IC_VER_WAIT_ACK_TIMES) {
        return UPDATE_ECODE_GET_IC_VER;
    }

    lt9611uxd_ver_write_cmd();

    // Write End
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xFF, 0xE0);
    lt9611ux_i2c_send_byte(LT9611UXD_ADDR, 0xDE, 0x02);

    // Read Ack 02
    count = 0;
    do {
        lt9611ux_i2c_recv_byte(LT9611UXD_ADDR, 0xAE, &temp);
        msleep(1);
        count++;
    } while ((count < GET_IC_VER_WAIT_ACK_TIMES) && (temp != 0x02));
    if (count >= GET_IC_VER_WAIT_ACK_TIMES) {
        return UPDATE_ECODE_GET_IC_VER;
    }

    // Read Return Data
    for (count = 0; count < GET_IC_VER_DATA_SIZE; count++) {
        lt9611ux_i2c_recv_byte(LT9611UXD_ADDR, RETURN_DATA_REG + count, &rxbuff[count]);
    }

    ic_ver1 = rxbuff[IC_VER_LOCATION1];
    ic_ver2 = rxbuff[IC_VER_LOCATION2];
    pr_info("[%s:] get ic_version success. verion = V%x.%x\n", __func__, ic_ver1, ic_ver2);
    *ver = (ic_ver1 << ONE_BYTE_BITS) | (ic_ver2);

    pr_info("[%s:] success\n", __func__);
    return HDMI_CHIP_ECODE_OK;
}

static ssize_t lt9611ux_ver_read(struct file *filp, char __user *ubuf, size_t cnt, loff_t *ppos)
{
    (void)filp;
    int len = 0;
    char buf[LT9611UXC_VERSION_PROCLEN];

    uint8_t main_ver1 = 0;
    uint8_t main_ver2 = 0;
    uint8_t sub_ver = 0;

    pr_info("[%s:] lt9611ux's addr is 0x%X\n", __func__, g_lt9611ux_client->addr);
    if (g_lt9611ux_client->addr == LT9611UXD_ADDR) {
        main_ver1 = (g_getVersion & 0xFF00) >> ONE_BYTE_BITS;
        sub_ver = (g_getVersion & 0x00FF);
        len = snprintf_s(buf, sizeof(buf), sizeof(buf) - 1, "UXD %x.%x\n", main_ver1, sub_ver);
    } else if (g_lt9611ux_client->addr == LT9611UXC_ADDR) {
        main_ver1 = (g_getVersion & 0xF000) >> TWELVE_BITS;
        main_ver2 = (g_getVersion & 0x0F00) >> ONE_BYTE_BITS;
        sub_ver = (g_getVersion & 0x00FF);
        len = snprintf_s(buf, sizeof(buf), sizeof(buf) - 1, "UXC %x.%x.%x\n", main_ver1, main_ver2, sub_ver);
    }

    if (len == 0) {
        pr_info("[%s:] lt9611_ver_read failed!", __func__);
        return 0;
    }

    return simple_read_from_buffer(ubuf, cnt, ppos, buf, len);
}

static struct proc_ops lt9611ux_ver_info_fops = {
    .proc_read = lt9611ux_ver_read,
};

static int lt9611ux_ver_proc_create(void)
{
    int ret = proc_create(PROC_NAME, PROC_MODE, NULL, &lt9611ux_ver_info_fops);
    if (!ret) {
        pr_info("[%s:] lt9611ux_ver_proc_create failed!\n", __func__);
        return -EINVAL;
    }
    pr_info("[%s:] success\n", __func__);
    return 0;
}

void set_hdmi_fw_ver(int ver)
{
    g_getVersion = ver;

    uint8_t main_ver1 = 0;
    uint8_t main_ver2 = 0;
    uint8_t sub_ver = 0;

    pr_info("[%s:] lt9611ux's addr is 0x%X\n", __func__, g_lt9611ux_client->addr);
    if (g_lt9611ux_client->addr == LT9611UXD_ADDR) {
        main_ver1 = (g_getVersion & 0xFF00) >> ONE_BYTE_BITS;
        sub_ver = (g_getVersion & 0x00FF);
        pr_info("set UXD fw_ver for AT:%x.%x\n", main_ver1, sub_ver);
    } else if (g_lt9611ux_client->addr == LT9611UXC_ADDR) {
        main_ver1 = (g_getVersion & 0xF000) >> TWELVE_BITS;
        main_ver2 = (g_getVersion & 0x0F00) >> ONE_BYTE_BITS;
        sub_ver = (g_getVersion & 0x00FF);
        pr_info("set UXC fw_ver for AT:%x.%x.%x\n", main_ver1, main_ver2, sub_ver);
    }
}

static void lt9611ux_fw_update_work(struct work_struct *work)
{
    struct device_node *node = NULL;
    int ret;
    pr_info("[%s:] begin\n", __func__);
    if (!work) {
        pr_info("[%s:] invalid parameter work\n", __func__);
        goto func_out;
    }

    g_pdata->set_update_status(g_lt9611ux_client, FW_UPDATE_STATUS_ONGOING);

    node = g_lt9611ux_client->dev.of_node;

    pr_info("[%s:] lt9611ux's addr is 0x%X\n", __func__, g_lt9611ux_client->addr);
    if (g_lt9611ux_client->addr == LT9611UXD_ADDR) {
        ret = lt9611uxd_update(g_lt9611ux_client, node, lt9611ux_fw_reset);
    } else if (g_lt9611ux_client->addr == LT9611UXC_ADDR) {
        ret = lt9611uxc_update(g_lt9611ux_client, node, lt9611ux_fw_reset);
    }
    if (ret != 0) {
        pr_info("[%s:] lt9611ux_update failed. ret =%d\n", __func__, ret);
        goto func_out;
    }
    pr_info("[%s:] lt9611ux_update success\n", __func__);

func_out:
    g_update_finished = true;
    pr_info("[%s:] lt9611ux's addr is 0x%X\n", __func__, g_lt9611ux_client->addr);

    if (g_lt9611ux_client->addr == LT9611UXD_ADDR) {
        ret = lt9611uxd_get_version(&g_at_chip_version);
    } else if (g_lt9611ux_client->addr == LT9611UXC_ADDR) {
        ret = lt9611uxc_get_version(&g_at_chip_version);
    }

    if (ret != 0) {
        pr_info("[%s:] lt9611ux_get_version failed. ret =%d\n", __func__, ret);
    }
    pr_info("[%s:] AT_chip_version = %x\n", __func__, g_at_chip_version);
    set_hdmi_fw_ver(g_at_chip_version);

    g_pdata->set_update_status(g_lt9611ux_client, FW_UPDATE_STATUS_ONGOING_POWER_OFF);
    g_pdata->power_off_sequence(g_lt9611ux_client);
    g_pdata->set_update_status(g_lt9611ux_client, FW_UPDATE_STATUS_DONE);
}

void lt9611_upgrade_firmware(struct i2c_client *client, struct lt9611_fw_updater_data *pdata)
{
    pr_info("[%s:] begin\n", __func__);
    if (client == NULL) {
        return;
    }

    int ret;
    g_lt9611ux_client = client;
    g_pdata = pdata;

    ret = lt9611ux_ver_proc_create();
    if (ret != 0) {
        pr_info("[%s:] proc create failed\n", __func__);
    }

    g_pdata->power_on_sequence(g_lt9611ux_client);

    INIT_DELAYED_WORK(&fw_update_work, lt9611ux_fw_update_work);
    schedule_delayed_work(&fw_update_work, msecs_to_jiffies(WORK_ADD_DLY_MS));
}

struct lt9611_fw_updater lt9611_firmware_updater = {
    .chip_model = "lt9611",
    .update_firmware = lt9611_upgrade_firmware
};

static int __init lt9611ux_register(void)
{
    int ret = 0;

    pr_info("lt9611ux_register: +");
    ret = lt9611_register_fw_updater(&lt9611_firmware_updater);
    pr_info("lt9611ux_register: -");

    return ret;
}

fs_initcall(lt9611ux_register);