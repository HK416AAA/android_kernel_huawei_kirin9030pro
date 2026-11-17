/*
 * Huawei touchpad thirdparty fw update
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

#include <linux/mutex.h>
#include <linux/hid.h>
#include <linux/i2c.h>
#include <securec.h>
#include <../drivers/hid/i2c-hid/i2c-hid.h>
#include "touchpad_func.h"
#include "touchpad_log.h"

#define MAX_DEV_NUM  3

struct mutex thirdparty_lock;

struct touchpad_device_info* g_dev_info[MAX_DEV_NUM] = { NULL };

void touchpad_thirdparty_register(struct touchpad_device_info *info)
{
    if (!info || !info->entry || !info->name || !info->device_id.vendor || !info->device_id.product) {
        tp_log_err("invalid arg");
        return;
    }
    static int i = 0;
    mutex_lock(&thirdparty_lock);
    if (i < MAX_DEV_NUM) {
        tp_log_info("register device: %s", info->name);
        g_dev_info[i] = info;
        i++;
    }
    mutex_unlock(&thirdparty_lock);
}

static int touchpad_thirdparty_update_probe(struct i2c_client *client)
{
    int i = 0;

    tp_log_info("Enter touchpad_thirdparty_update_probe");

    if (!client) {
        tp_log_info("client is NULL");
        return -EINVAL;
    }

	struct i2c_hid *ihid = i2c_get_clientdata(client);
	if (!ihid || !ihid->hid) {
		tp_log_err("ihid is NULL");
		return -EINVAL;
	}

    for (i = 0; i < MAX_DEV_NUM; i++) {
        if (!g_dev_info[i] || !g_dev_info[i]->entry || !g_dev_info[i]->name ||
        !g_dev_info[i]->device_id.vendor || !g_dev_info[i]->device_id.product) {
            tp_log_err("invalid g_dev_info[%d]", i);
            continue;
        }

        if ((ihid->hid->vendor == g_dev_info[i]->device_id.vendor) &&
            (ihid->hid->product == g_dev_info[i]->device_id.product) &&
            (g_dev_info[i]->entry)) {
            tp_log_info("start thirdparty touchpad entry");
            g_dev_info[i]->entry(ihid->hid);
            break;
        }
    }
    return EOK;
}

static void touchpad_thirdparty_update_remove()
{
    tp_log_info("Enter touchpad_thirdparty_update_remove");
}

static struct touchpad_func thirdparty_fw_update = {
	.name = "thirdparty_fw_update",
	.type = TOUCHPAD_THIRD_UPDATE,
	.probe = touchpad_thirdparty_update_probe,
	.remove = touchpad_thirdparty_update_remove,
};

static int __init touchpad_thirdparty_init(void)
{
    tp_log_info("Enter touchpad_thirdparty_init");
    mutex_init(&thirdparty_lock);
	return touchpad_register_func(&thirdparty_fw_update);
}

static void __exit touchpad_thirdparty_exit(void)
{
    tp_log_info("touchpad_thirdparty_exit");
}

late_initcall(touchpad_thirdparty_init);
module_exit(touchpad_thirdparty_exit);