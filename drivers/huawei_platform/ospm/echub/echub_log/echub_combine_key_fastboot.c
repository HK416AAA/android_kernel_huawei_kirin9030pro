/*
 * echub_combine_key_fastboot.c
 *
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#include <linux/notifier.h>
#include <platform_include/basicplatform/linux/rdr_pub.h>
#include <platform_include/basicplatform/linux/rdr_platform.h>
#include <platform_include/basicplatform/linux/util.h>

#include "ospm_printf.h"
#ifdef CONFIG_ARMPC_ECHUB_HMI
#include "hmi/hmi.h"

static struct notifier_block g_hmi_event_nb;

static int echub_fastboot_event_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	switch (event) {
	case REBOOT_FASTBOOT:
		if (check_mntn_switch(MNTN_PRESS_KEY_TO_FASTBOOT)) {
			echub_info("combine hot key trigger fastboot\n");
			rdr_syserr_process_for_ap(MODID_AP_S_COMBINATIONKEY, 0, 0);
		}
		break;
    default:
		break;
	}

	return NOTIFY_OK;
}

static int __init echub_fastboot_event_init(void)
{
	g_hmi_event_nb.notifier_call = echub_fastboot_event_notifier_call;
	int ret = hmi_event_bnc_register(HMI_KEYBOARD_EVENT, &g_hmi_event_nb);
	if (ret)
		echub_err("%s: hmi event bnc register fail\n", __func__);
	return ret;
}

static void __exit echub_fastboot_event_exit(void)
{
	int ret;
    ret = hmi_event_bnc_unregister(HMI_KEYBOARD_EVENT, &g_hmi_event_nb);
	if (ret)
		echub_err("%s: hmi keyboard event bnc unregister fail\n", __func__);
}

late_initcall(echub_fastboot_event_init);
module_exit(echub_fastboot_event_exit);

#endif

MODULE_DESCRIPTION("echub combine key to fastboot driver");
MODULE_LICENSE("GPL");