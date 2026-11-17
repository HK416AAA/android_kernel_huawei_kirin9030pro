/*
 * audio iodie pinctrl driver.
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/bitops.h>
#include <linux/platform_device.h>
#include "audio_log.h"
#include "audio_pinctrl.h"

#define LOG_TAG "audio_iodie_pinctrl"

static struct audio_pinctrl_handler g_iodie_pinctrl_handler;

static int iodie_pinctrl_probe(struct platform_device *pdev)
{
	int ret;
	unsigned int val;

	if (pdev == NULL) {
		AUDIO_LOGE("iodie audio driver probe error");
        return -1;
    }

	AUDIO_LOGI("iodie audio probe start");
	platform_set_drvdata(pdev, &g_iodie_pinctrl_handler);

	ret = audio_pinctrl_handler_init(pdev);
	if (ret < 0) {
		AUDIO_LOGE("iodie audio pintctrl init failed, ret %d", ret);
		return ret;
	}

	audio_pinctrl_handler_register(AUDIO_PINCTRL_IODIE, &g_iodie_pinctrl_handler);
	AUDIO_LOGI("iodie audio probe success");
	return 0;
}

static int iodie_pinctrl_remove(struct platform_device *pdev)
{
	if (pdev == NULL) {
		AUDIO_LOGE("iodie audio driver probe error");
        return -1;
    }

	audio_pinctrl_handler_deinit(pdev);
	audio_pinctrl_handler_unregister(AUDIO_PINCTRL_IODIE);
	return 0;
}

static const struct of_device_id g_iodie_pinctrl_match[] = {
    { .compatible = "hisilicon,audio-iodie", },
	{},
};

static struct platform_driver g_iodie_pinctrl = {
	.driver = {
		.name  = "audio-iodie",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(g_iodie_pinctrl_match),
	},
	.probe  = iodie_pinctrl_probe,
	.remove = iodie_pinctrl_remove,
};

static int __init iodie_pinctrl_init(void)
{
	AUDIO_LOGI("iodie audio init enter");
	return platform_driver_register(&g_iodie_pinctrl);
}

fs_initcall(iodie_pinctrl_init);

static void __exit iodie_pinctrl_exit(void)
{
	platform_driver_unregister(&g_iodie_pinctrl);
}

module_exit(iodie_pinctrl_exit);

MODULE_DESCRIPTION("audio iodie pinctrl driver");
MODULE_LICENSE("GPL");
