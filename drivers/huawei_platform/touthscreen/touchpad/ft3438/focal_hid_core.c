/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

/*****************************************************************************
*
* File Name: focal_hid_core.c
*
* Author: Focaltech Driver Team
*
* Created: 2024-12-05
*
* Abstract: entrance for focaltech hid driver
*
* Version: V1.0
*
*****************************************************************************/

/*****************************************************************************
* Included header files
*****************************************************************************/

#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/gpio/consumer.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/hid.h>
#include "focal_hid_core.h"
#include "../touchpad_func.h"

#define FTS_HID_DATA_OFF_4     4
#define FTS_HID_CHECKSUM       3


struct fts_hid_data *fts_hid_data = NULL;

static int fts_hid_get_checksum(u8 *buf, u8 len)
{
    unsigned int i = 0;
    unsigned char Checksum = 0;
    for (i = 0; i < len; i++) {
        Checksum ^= buf[i];
    }
    Checksum++;
    return Checksum;
}

static int fts_hid_get_report(u8 *buf, size_t size)
{
    int retval;
    int retries = 3;
    u8 fts_hid_buf[FTS_HID_BUFF_SIZE] = {0};
    struct hid_device *hdev = fts_hid_data->hdev;

    memset_s(fts_hid_buf, FTS_HID_BUFF_SIZE, 0xFF, FTS_HID_BUFF_SIZE);
    fts_hid_buf[0] = 0x06;
    if (!buf) {
        return 0;
    }
    do {
        retval = hid_hw_raw_request(hdev, fts_hid_buf[0],
            fts_hid_buf, FTS_HID_BUFF_SIZE, HID_INPUT_REPORT, HID_REQ_GET_REPORT);
    } while ((retval == -ETIMEDOUT || retval == -EAGAIN) && --retries);

    if (retval < 0) {
        FTS_ERROR("fts_get_report: ran out of retries (last error = %d)\n", retval);
    }

    memcpy_s(buf, size, fts_hid_buf + FTS_HID_DATA_OFF_4, size);
    return retval;
}

static int fts_hid_set_report(u8 *buf, size_t size)
{
    int retval;
    u8 check_sum = 0;
    int index = 0;
    u8 fts_hid_buf[FTS_HID_BUFF_SIZE] = {0};
    int retries = 3;
    struct hid_device *hdev = fts_hid_data->hdev;

    memset_s(fts_hid_buf, FTS_HID_BUFF_SIZE, 0xFF, FTS_HID_BUFF_SIZE);
    fts_hid_buf[index++] = 0x06;
    fts_hid_buf[index++] = 0xFF;
    fts_hid_buf[index++] = 0xFF;
    fts_hid_buf[index++] = size + FTS_HID_DATA_OFF_4;
    memcpy_s(fts_hid_buf + index, FTS_HID_BUFF_SIZE - index, buf, size);
    check_sum = fts_hid_get_checksum(fts_hid_buf + FTS_HID_CHECKSUM, size + 1);
    fts_hid_buf[FTS_HID_DATA_OFF_4 + size] = check_sum;

    do {
        retval = hid_hw_raw_request(hdev, fts_hid_buf[0], fts_hid_buf,
            FTS_HID_BUFF_SIZE, HID_OUTPUT_REPORT, HID_REQ_SET_REPORT);
    } while ((retval == -ETIMEDOUT || retval == -EAGAIN) && --retries);

    if (retval < 0) {
        FTS_ERROR("fts_set_report: ran out of retries (last error = %d)\n", retval);
    }

    return retval;
}


int fts_hid_write_data(u8 *buf, size_t size)
{
    return fts_hid_set_report(buf, size);
}


int fts_hid_read_data(u8 *buf, size_t size)
{
    return fts_hid_get_report(buf, size);
}


// 0x50
int fts_hid_read_reg(u8 addr, u8 *value)
{
    u8 cmd[FTS_CMD_LEN_2] = {0};
    u8 data[FTS_DATA_LEN_3] = {0};
    int ret = 0;

    cmd[0] = CMD_READ_REGISTER;
    cmd[1] = addr;

    mutex_lock(&fts_hid_data->bus_lock);
    ret = fts_hid_write_data(cmd, FTS_CMD_LEN_2);
    if (ret < 0) {
        FTS_ERROR("fts_hid_write_data fail\n");
        ret = -EINVAL;
        goto out;
    }

    ret = fts_hid_read_data(data, FTS_DATA_LEN_3);
    if (ret < 0) {
        FTS_ERROR("fts_hid_read_data fail\n");
        ret = -EINVAL;
        goto out;
    }

    if ((data[0] != CMD_READ_REGISTER) || (data[1] != addr)) {
        FTS_ERROR("fts_hid_read_reg fail cmd:%x, addr:%x\n", data[0], data[1]);
        ret = -EINVAL;
        goto out;
    } else {
        *value = data[FTS_INDEX_2];
        ret = 0;
    }
    out:
    mutex_unlock(&fts_hid_data->bus_lock);

    return ret;
}

// 0x51
int fts_hid_write_reg(u8 addr, u8 value)
{
    u8 cmd[FTS_DATA_LEN_3] = {0};
    u8 data[FTS_DATA_LEN_2] = {0};
    int ret = 0;

    cmd[0] = CMD_WRITE_REGISTER;
    cmd[1] = addr;
    cmd[FTS_DATA_LEN_2] = value;
    mutex_lock(&fts_hid_data->bus_lock);
    ret = fts_hid_write_data(cmd, FTS_DATA_LEN_3);
    if (ret) {
        FTS_ERROR("fts_hid_write_data fail\n");
        ret = -EINVAL;
        goto out;
    }

    ret = fts_hid_read_data(data, FTS_DATA_LEN_2);
    if (ret) {
        FTS_ERROR("fts_hid_read_data fail\n");
        ret = -EINVAL;
        goto out;
    }

    if ((data[0] != CMD_WRITE_REGISTER) || (data[1] != addr)) {
        FTS_ERROR("fts_hid_write_reg fail cmd:%x, value:%x\n", data[0], data[1]);
        ret = -EINVAL;
        goto out;
    }
    out:
    mutex_unlock(&fts_hid_data->bus_lock);

    return ret;
}


int fts_hw_reset(int hdelayms)
{
    FTS_INFO("tp hw reset");
    gpiod_direction_output(fts_hid_data->reset_gpio, 0);
    msleep(1);
    gpiod_direction_output(fts_hid_data->reset_gpio, 1);
    if (hdelayms) {
        msleep(hdelayms);
    }

    return 0;
}
#ifdef TOUCHPAD_FACTORY_ENABLE
int fts_sw_reset(int hdelayms)
{
    FTS_INFO("tp sw reset");
    fts_i2c_write_reg(0xFC, 0xAA);
    msleep(1);
    fts_i2c_write_reg(0xFC, 0x66);
    if (hdelayms) {
        msleep(hdelayms);
    }
 
    return 0;
}
 
int fts_reset(int hdelayms)
{
    if (IS_ERR(fts_hid_data->reset_gpio)) {
        fts_sw_reset(hdelayms);
    } else {
        fts_hw_reset(hdelayms);
    }
 
    return 0;
}

void focal_hid2std(void)
{
    int ret = 0;
    u8 buf[FTS_DATA_LEN_3] = {0xEB, 0xAA, 0x09};
 
    ret = fts_i2c_write(buf, FTS_DATA_LEN_3);
    if (ret < 0) {
        FTS_ERROR("hid2std cmd write fail");
    } else {
        msleep(FTS_DELAY_MS_10);
        buf[0] = buf[1] = buf[FTS_DATA_LEN_2] = 0;
        ret = fts_i2c_read(NULL, 0, buf, FTS_DATA_LEN_3);
        if (ret < 0) {
            FTS_ERROR("hid2std cmd read fail");
        } else if ((0xEB == buf[0]) && (0xAA == buf[1]) && (0x08 == buf[FTS_DATA_LEN_2])) {
            FTS_DEBUG("hidi2c change to stdi2c successful");
        } else {
            FTS_DEBUG("hidi2c change to stdi2c not support or fail");
        }
    }
}
#endif

void focal_irq_disable(void)
{
    unsigned long irqflags;

    FTS_FUNC_ENTER();
    spin_lock_irqsave(&fts_hid_data->irq_lock, irqflags);

    if (!fts_hid_data->irq_disabled) {
        disable_irq_nosync(fts_hid_data->irq);
        fts_hid_data->irq_disabled = true;
    }

    spin_unlock_irqrestore(&fts_hid_data->irq_lock, irqflags);
    FTS_FUNC_EXIT();
}

void focal_irq_enable(void)
{
    unsigned long irqflags = 0;

    FTS_FUNC_ENTER();
    spin_lock_irqsave(&fts_hid_data->irq_lock, irqflags);

    if (fts_hid_data->irq_disabled) {
        enable_irq(fts_hid_data->irq);
        fts_hid_data->irq_disabled = false;
    }

    spin_unlock_irqrestore(&fts_hid_data->irq_lock, irqflags);
    FTS_FUNC_EXIT();
}

static int fts_hid_parse_gpio(struct fts_hid_data *fts_hid_data_local)
{
    FTS_FUNC_ENTER();

    fts_hid_data_local->reset_gpio = devm_gpiod_get(fts_hid_data->dev, "reset", GPIOD_OUT_HIGH);
    if (IS_ERR(fts_hid_data_local->reset_gpio)) {
        FTS_ERROR("get reset gpio fail\n");
        return PTR_ERR(fts_hid_data_local->reset_gpio);
    }

    FTS_INFO("fts_hid_parse_gpio success\n");
    return 0;
}

static int fts_hid_data_init(struct hid_device *hdev)
{
    fts_hid_data = kzalloc(sizeof(struct fts_hid_data), GFP_KERNEL);
    if (IS_ERR(fts_hid_data)) {
        FTS_ERROR("kzalloc fts_hid_data fail\n");
        return PTR_ERR(fts_hid_data);
    }

    /* init driver data */
    mutex_init(&fts_hid_data->bus_lock);
    mutex_init(&fts_hid_data->debug_lock);
    spin_lock_init(&fts_hid_data->irq_lock);

    fts_hid_data->hdev   = hdev;
    fts_hid_data->client = hdev->driver_data;
    fts_hid_data->dev    = &fts_hid_data->client->dev;
    fts_hid_data->irq    = fts_hid_data->client->irq;

    fts_hid_data->ts_workqueue = create_singlethread_workqueue("fts_wq");
    if (IS_ERR(fts_hid_data->ts_workqueue)) {
        FTS_ERROR("create fts workqueue fail");
        return PTR_ERR(fts_hid_data->ts_workqueue);
    }

    return 0;
}

static int fts_hid_exfunc_init(void)
{
    int ret = 0;
 
#ifdef TOUCHPAD_FACTORY_ENABLE
    ret = fts_create_sysfs(fts_hid_data);
    if (ret < 0) {
        FTS_ERROR("fts_create_sysfs fail\n");
    }
 
    ret = focal_create_apk_debug_channel(fts_hid_data);
    if (ret < 0) {
        FTS_ERROR("create apk debug node fail");
    }
#endif

    ret = fts_hid_parse_gpio(fts_hid_data);
    if (ret < 0) {
        FTS_ERROR("hw reset not support,will use sw reset\n");
    }
    
    return ret;
}

int fts_hid_probe_entry(struct hid_device *hdev)
{
    int ret;

    FTS_FUNC_ENTER();

    fts_hid_data_init(hdev);
    fts_hid_exfunc_init();
    /* set device as wakeup source */
    ret = device_init_wakeup(fts_hid_data->dev, 1);
    if (ret) {
        FTS_ERROR("device_init_wakeup fail\n");
        goto err;
    }

#ifdef TOUCHPAD_FACTORY_ENABLE
    focal_bus_init(fts_hid_data);
#endif

    fts_hid_data->ws = wakeup_source_register(&hdev->dev, "focal_wakelock");
    if (!fts_hid_data->ws) {
        FTS_ERROR("wakeup source request failed\n");
    }

#ifdef TOUCHPAD_FACTORY_ENABLE
    ret = fts_test_init(fts_hid_data);
    if (ret) {
        FTS_ERROR("init host test fail");
    }
#endif

    ret = focal_esdcheck_init(fts_hid_data);
    if (ret) {
        FTS_ERROR("init esd check fail");
    }

    ret = focal_fwupg_init(fts_hid_data);
    if (ret) {
        FTS_ERROR("init fw upgrade fail");
    }

    FTS_FUNC_EXIT();
    return 0;
    err:
    if (fts_hid_data) {
        kfree(fts_hid_data);
    }

    return ret;
}


int fts_ts_remove_entry(void)
{
    struct fts_hid_data *ts_data = fts_hid_data;
    FTS_FUNC_ENTER();

#ifdef TOUCHPAD_FACTORY_ENABLE
    focal_release_apk_debug_channel(ts_data);
    fts_remove_sysfs(ts_data);
#endif

    focal_fwupg_exit(ts_data);

#ifdef TOUCHPAD_FACTORY_ENABLE
    fts_test_exit(ts_data);
#endif

    focal_esdcheck_exit(ts_data);

#ifdef TOUCHPAD_FACTORY_ENABLE
    focal_bus_exit(ts_data);
#endif

    if (ts_data->ts_workqueue) {
        destroy_workqueue(ts_data->ts_workqueue);
    }
    
    if (ts_data) {
        kfree(ts_data);
    }

    FTS_FUNC_EXIT();

    return 0;
}

struct touchpad_device_info focal_device_info = {
    .name = "focal touchpad",
    .entry = fts_hid_probe_entry,
    .device_id = {
        .vendor = 0x2808,
        .product = 0x0101,
    },
};

static int __init fts_driver_init(void)
{
    FTS_INFO("fts_driver_init\n");
    touchpad_thirdparty_register(&focal_device_info);
    return EOK;
}

static void __exit fts_driver_exit(void)
{
    FTS_INFO("Driver exiting\n");
    fts_ts_remove_entry();
}

module_init(fts_driver_init);
module_exit(fts_driver_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("FocalTech Driver Team");
MODULE_DESCRIPTION("FocalTech Touchscreen Driver(HID)");
