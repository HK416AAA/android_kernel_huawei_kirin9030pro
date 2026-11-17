/*
 * watch_low_power_manager.c
 *
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2024. All rights reserved.
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

#include "watch_low_power_manager.h"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <platform_include/basicplatform/linux/nve/nve_ap_kernel_interface.h>

#include "ext_sensorhub_commu.h"
#include "ext_sensorhub_inner_cmd.h"
#include "str.h"
#include "ext_sensorhub_channel.h"
#include "securec.h"

#define SENSOR_DATA_MAX 0x03
#define SYS_CLS_MODE 0660
/* enter str success and send mesg to mcu */
#define DEVICE_MGR_SVR 0x01
#define APP_DEV_SET_NOTIFY_FINISH 0xA1
#define SEND_ID_TO_MCU_RETRY_COUNT 3
/* 580 is normal mode for NV number */
#define MODE_NV_NUMBER 580
#define MODE_NA_LEN 4
/* smtm is normal mode for NV data */
#define SMTM_MODE "smtm"
/* smtt is str mode  reopen for NV data */
#define SMTT_MODE "smtt"

#define ENTER_STR_DELAY 1000
#define EXIT_STR_DELAY  1000

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static struct wakeup_source *wake_lock;
#else
static struct wakeup_source wake_lock;
#endif

static int watch_low_power_state = 0;

enum {
	SMTM_MODE_STATE = 0,
	STRM_MODE_STATE = 1,
	SMTT_MODE_STATE = 2,
};

/* If device need to switch when str state enter, devcie can call this interface.
 * When str state enter, it will call the device notifier_block callback
 */
int register_watch_low_power_enter_notifier(int val, struct notifier_block *nb)
{
	return register_pm_str_notifier(val, nb);
}
EXPORT_SYMBOL_GPL(register_watch_low_power_enter_notifier);

/* If device need to switch when str state exit, devcie can call this interface.
 * When str state exit, it will call the device notifier_block callback
 */
int register_watch_low_power_exit_notifier(int val, struct notifier_block *nb)
{
	return register_pm_str_notifier(val, nb);
}
EXPORT_SYMBOL_GPL(register_watch_low_power_exit_notifier);

/* If device do not need to concern to str state after regsiter, device can call this interface */
int unregister_watch_low_power_enter_notifier(int val, struct notifier_block *nb)
{
	return unregister_pm_str_notifier(val, nb);
}
EXPORT_SYMBOL_GPL(unregister_watch_low_power_enter_notifier);
/* If device do not need to concern to str state after regsiter, device can call this interface */
int unregister_watch_low_power_exit_notifier(int val, struct notifier_block *nb)
{
	return unregister_pm_str_notifier(val, nb);
}
EXPORT_SYMBOL_GPL(unregister_watch_low_power_exit_notifier);

bool is_watch_low_power_state(void)
{
	return is_str();
}
EXPORT_SYMBOL_GPL(is_watch_low_power_state);

static void get_mode_nv_state(char *buf)
{
	struct opt_nve_info_user user_info;
	errno_t mts = memset_s(&user_info, sizeof(user_info), 0, sizeof(user_info));
	if (mts != EOK) {   
		printk(KERN_INFO "memcpy_s failed, mts = %d\n", mts);   
		return ;
	}
	user_info.nv_operation = NV_READ;
	user_info.nv_number = MODE_NV_NUMBER;
	user_info.valid_size = MODE_NA_LEN;
	int ret = nve_direct_access_interface(&user_info);
	printk(KERN_INFO "watch_low_power_manager nve_direct_access_interface ret =%d", ret);
	errno_t scs = strncpy_s(buf, MODE_NA_LEN + strlen(user_info.nv_data), user_info.nv_data, MODE_NA_LEN);
	if (scs != EOK) {
		printk(KERN_INFO "memcpy_s failed, scs = %d\n", scs);
		return ;
	}
	printk(KERN_INFO "watch_low_power_manager get_nv_data is =%s", buf);

	if (strlen(buf) == 0) {
		printk(KERN_INFO "watch_low_power_manager, buf is NULL, get nv error!");
		return;
	}
	if (!strcmp(buf, SMTM_MODE)) {
		watch_low_power_state = SMTM_MODE_STATE;
	} else if (!strcmp(buf, SMTT_MODE)) {
		watch_low_power_state = SMTT_MODE_STATE;
	} else {
		watch_low_power_state = STRM_MODE_STATE;
	}
	printk(KERN_INFO "watch_low_power_manager, get_mode_nv_state, watch_low_power_state =%d", watch_low_power_state);
}

/*  node read function */
static ssize_t str_mode_state_read(struct class *cls,struct class_attribute *attr, char *buf)
{
	get_mode_nv_state(buf);
	printk(KERN_INFO "watch_low_power_manager, str_mode_state_read, watch_low_power_state =%d", watch_low_power_state);

	return sprintf_s(buf, strlen(buf), "%d", watch_low_power_state);
}

/* creat watch_low_power_mode node for store str state*/
static struct class_attribute class_attr_str_mode_state_name = __ATTR(
	watch_low_power_mode_state,
	SYS_CLS_MODE,
	str_mode_state_read,
	NULL
);

static int send_id_to_mcu(enum ext_channel_id channel, int sid, int cid)
{
	struct command cmd = {0};
	int ret = 0;
	cmd.service_id = sid;
 	cmd.command_id = cid;
	ret = send_command(channel, &cmd, false, NULL);
	printk(KERN_INFO "watch_low_power_manager, send id to mcu");
	return ret;
}

static int watch_low_power_manager_notify(struct notifier_block __always_unused *nb,
	unsigned long mode,
	void __always_unused *data)
{
	int ret;
	int count = 0;
	char data_exit[SENSOR_DATA_MAX] = {mode};
	printk(KERN_INFO "watch_low_power_manager, receive watch low power manager notify mode =%d\n", mode);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	__pm_stay_awake(wake_lock);
#else
	__pm_stay_awake(&wake_lock);
#endif
	switch (mode) {
	case WATCH_LOW_POWER_ENTER:
		/* enter str mode */
		ret = send_id_to_mcu(DEBUG_CHANNEL, DEVICE_MGR_SVR, APP_DEV_SET_NOTIFY_FINISH);
		while (ret < 0 && count < SEND_ID_TO_MCU_RETRY_COUNT) {
			ret = send_id_to_mcu(DEBUG_CHANNEL, DEVICE_MGR_SVR, APP_DEV_SET_NOTIFY_FINISH);
            printk(KERN_INFO "watch_low_power_manager send_id_to_mcu retry ret = %d  count = %d", ret, count);
			count += 1;
		}
		msleep(ENTER_STR_DELAY);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		__pm_relax(wake_lock);
#else
		__pm_relax(&wake_lock);
#endif
		printk(KERN_INFO "watch_low_power_manager watch_low_power_manager send_id_to_mcu ret= %d\n", ret);
		break;
	case WATCH_LOW_POWER_EXIT:
		/* str mode exit */
		printk(KERN_INFO "watch_low_power_manager, receive watch low power manager notify exit\n");
	case WATCH_LOW_POWER_POWER_OFF:
		/* str mode power off */
		printk(KERN_INFO "watch_low_power_manager, receive watch low power manager notify power off\n");
	case WATCH_LOW_POWER_REBOOT:
		/* str mode reboot */
		printk(KERN_INFO "watch_low_power_manager, receive watch low power manager notify reboot\n");
		ret = send_inner_command(SERVICE_ID_COMMU, SERVICE_COMMU_EXIT_LOW_POWER, data_exit, sizeof(data_exit));
		msleep(EXIT_STR_DELAY);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		__pm_relax(wake_lock);
#else
		__pm_relax(&wake_lock);
#endif
		printk(KERN_INFO "watch_low_power_manager, send_inner_command ret = %d, data_exit = %s\n", ret, data_exit);
		break;
	default:
		break;
	}

	return 0;
}

/* If the service has high requirements on the execution priority,
*  you can set the priority value.
*  The priority value ranges from 0 to INT_MAX,
*  where INT_MAX indicates the highest priority and 0 indicates the lowest priority (default value).
*/
static struct notifier_block watch_low_power_manager_nb = {
	.notifier_call = watch_low_power_manager_notify,
	.priority = 0,
};

static int __init watch_low_power_manager_init(void)
{
	struct class *watch_low_power_manager_class;
	watch_low_power_manager_class = class_create(THIS_MODULE, "str_mode_state");
	if (class_create_file(watch_low_power_manager_class,
			      &class_attr_str_mode_state_name)) {
		printk(KERN_INFO "watch_low_power_manager, create files failed in watch_low_power_manager_init");
	}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	wake_lock = wakeup_source_register(NULL, "low_power_manager_lock");
#else
	wakeup_source_init(&wake_lock, "low_power_manager_lock");
#endif
	int ret_enter_str = register_watch_low_power_enter_notifier(WATCH_LOW_POWER_ENTER, &watch_low_power_manager_nb);
	int ret_exit_str = register_watch_low_power_exit_notifier(WATCH_LOW_POWER_EXIT, &watch_low_power_manager_nb);
	printk(KERN_INFO "watch_low_power_manager, register low power manager notifer ret_enter_str = %d\n", ret_enter_str);
	printk(KERN_INFO "watch_low_power_manager, register low power manager notifer ret_exit_str = %d\n", ret_exit_str);
	return 0;
}

static void __exit watch_low_power_manager_exit(void)
{
	int ret_enter_str = unregister_watch_low_power_enter_notifier(WATCH_LOW_POWER_ENTER, &watch_low_power_manager_nb);
	int ret_exit_str = unregister_watch_low_power_exit_notifier(WATCH_LOW_POWER_EXIT, &watch_low_power_manager_nb);
	printk(KERN_INFO "watch_low_power_manager, unregister low power manager notifer ret_enter_str = %d\n", ret_enter_str);
	printk(KERN_INFO "watch_low_power_manager, unregister low power manager notifer ret_exit_str = %d\n", ret_exit_str);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	wakeup_source_unregister(wake_lock);
	wake_lock = NULL;
#else
	wakeup_source_trash(&wake_lock);
#endif
}

module_init(watch_low_power_manager_init);
module_exit(watch_low_power_manager_exit);