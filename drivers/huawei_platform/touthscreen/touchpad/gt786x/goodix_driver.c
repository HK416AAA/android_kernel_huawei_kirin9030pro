/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
/*
  * Goodix Touchscreen Driver
  * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be a reference
  * to you, when you are integrating the GOODiX's CTP IC into your system,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  * General Public License for more details.
  *
  */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/kthread.h>
#include <linux/hid.h>
#include "hm_os_sys.h"
#include "goodix_ts_log.h"
#include "goodix_ts_core.h"
#include "../touchpad_func.h"
#ifdef TOUCHPAD_FACTORY_ENABLE
#include "gt786x_inspect.h"
#endif

static struct delayed_work fw_upgrade_work;

static void goodix_work(struct work_struct *work)
{
    int ret;
    ts_info("goodix fw update work start");
    /* 600000: Wait for chip_prod image mount complete, timeout 60s */
    wait_chip_prod_mount(60000);
    if (goodix_fw_update_proc()) {
        ts_err("failed do fw update");
    }
}

static int goodix_init(struct hid_device *hdev)
{
    int ret = 0;
    struct i2c_client *client = hdev->driver_data;
 
    ts_info("enter goodix_init");

    if (!hdev || !client) {
        ts_err("hdev or client is NULL");
        return -ENODEV;
    }
 
    ts_info("goodix gt7861 probe in");
    ret = i2c_check_functionality(client->adapter,
        I2C_FUNC_I2C);
    if (!ret)
        return -EIO;

#ifdef TOUCHPAD_FACTORY_ENABLE
    touchpad_register_test_func(gtx8_do_inspect);
#endif
 
    dev_i2c_init(client);
    /* create and run update thread */
 
    ts_info("create fw update delay work queue");
    INIT_DELAYED_WORK(&fw_upgrade_work, goodix_work);
    queue_delayed_work(system_wq, &fw_upgrade_work, msecs_to_jiffies(10000)); // 10000: delay 10s
 
    return EOK;
}

struct touchpad_device_info goodix_device_info = {
    .name = "goodix touchpad",
    .entry = goodix_init,
    .device_id = {
        .vendor = 0x27C6,
        .product = 0x01E0,
    },
};

static int __init goodix_driver_init(void)
{
    ts_info("goodix_driver_init\n");
    touchpad_thirdparty_register(&goodix_device_info);
    return 0;
}

void __exit  goodix_driver_exit(void)
{
    ts_info("Goodix tp driver exit");
    cancel_delayed_work_sync(&fw_upgrade_work);
}

module_init(goodix_driver_init);
module_exit(goodix_driver_exit);

MODULE_DESCRIPTION("Goodix Touchscreen Core Module");
MODULE_AUTHOR("Goodix, Inc.");
MODULE_LICENSE("GPL v2");