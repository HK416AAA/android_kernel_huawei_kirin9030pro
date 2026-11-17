/*
 * audio_wakeup_info.c
 *
 * audio wakeup info driver
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
 */

#include <linux/module.h>
#include <linux/ioctl.h>
#include <linux/platform_device.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <securec.h>
#include <huawei_platform/log/hw_log.h>
#include "audio_wakeup_info.h"

#define HWLOG_TAG audio_wakeup_info
#define MOD_NAME "audio_wakeup_info"

HWLOG_REGIST();

static long audio_wakeup_info_ioctl(unsigned int cmd, unsigned long arg)
{
    long ret = 0;
    char wakeupInfo[AUDIO_WAKEUP_INFO_LENTH + 1] = {0};
    if (arg == 0) {
        hwlog_err("%s: invalid arg\n", __func__);
        return -1;
    }

    if (cmd == AUDIO_WAKEUP_INFO_EVENT) {
        hwlog_info("%s: cmd==AUDIO_WAKEUP_INFO_EVENT, command = 0x%x\n", __func__, cmd);
        ret = copy_from_user(wakeupInfo, (uint32_t *)(uintptr_t)arg, sizeof(wakeupInfo));
        if (ret) {
            hwlog_err("%s: copy_from_user failed\n", __func__);
            return ret;
        }
        hwlog_info("%s: MOD_NAME: %s, wakeupInfo: %s\n", __func__, MOD_NAME, wakeupInfo);
        audio_misc_report_uevent(MOD_NAME, wakeupInfo);
    } else {
        hwlog_err("%s: not support command = 0x%x\n", __func__, cmd);
        return -EINVAL;
    }

    return ret;
}

static void audio_wakeup_info_remove(void *priv)
{
    (void)(priv);
}

static const struct audio_misc_module_ops audio_wakeup_info_ops = {
    .ioctl = audio_wakeup_info_ioctl,
    .remove = audio_wakeup_info_remove,
};

int audio_wakeup_info_probe(struct device *dev, struct device_node *np)
{
    int ret;
    hwlog_info("%s: in\n", __func__);

    ret = audio_misc_module_constructor(MOD_NAME, NULL, AUDIO_WAKEUP_INFO_IOCTL_TYPE, &audio_wakeup_info_ops);
    if (ret) {
        hwlog_err("%s: constructor audio_wakeup_info fail\n", __func__);
        ret = -ENOMEM;
    }

    hwlog_info("%s: exit, constructor audio_wakeup_info success\n", __func__);
    return ret;
}
