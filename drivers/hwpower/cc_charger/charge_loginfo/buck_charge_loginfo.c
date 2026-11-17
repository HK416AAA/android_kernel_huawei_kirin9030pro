// SPDX-License-Identifier: GPL-2.0+
/*
 * buck_charge_loginfo.c
 *
 * buck charge loginfo module
 *
 * Copyright (C) 2025-2025 Huawei Technologies Co., Ltd.
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

#include <securec.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_sysfs.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>

static int buck_charge_loginfo_get_online(void)
{
	int usb_online = 0;
	int wls_online = 0;

	power_supply_get_int_prop(POWER_PLATFORM_USB_PSY_NAME, POWER_SUPPLY_PROP_ONLINE,
		&usb_online, 0, 1);
	power_supply_get_int_prop("Wireless", POWER_SUPPLY_PROP_ONLINE, &wls_online, 0, 1);

	return (usb_online || wls_online);
}

static const char *buck_charge_loginfo_get_charge_type(void)
{
	return charge_get_charger_type_name(charge_get_charger_type());
}

static int buck_charge_loginfo_get_usb_voltage(void)
{
	int usb_vol = 0;

	power_supply_get_int_prop(POWER_PLATFORM_USB_PSY_NAME, POWER_SUPPLY_PROP_VOLTAGE_NOW,
		&usb_vol, 0, POWER_UV_PER_MV);

	return usb_vol;
}

static const char *buck_charge_loginfo_get_charge_status(void)
{
	int status = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_STATUS,
		&status, 0, 1);

	switch (status) {
	case POWER_SUPPLY_STATUS_CHARGING:
		return "CHARGING";
	case POWER_SUPPLY_STATUS_DISCHARGING:
		return "DISCHARGING";
	case POWER_SUPPLY_STATUS_NOT_CHARGING:
		return "NOTCHARGING";
	case POWER_SUPPLY_STATUS_FULL:
		return "FULL";
	case POWER_SUPPLY_STATUS_UNKNOWN:
	default:
		return "UNKNOWN";
	}
}

static const char *buck_charge_loginfo_get_bat_health(void)
{
	int health = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_HEALTH,
		&health, 0, 1);

	switch (health) {
	case POWER_SUPPLY_HEALTH_OVERHEAT:
		return "OVERHEAT";
	case POWER_SUPPLY_HEALTH_COLD:
		return "COLD";
	case POWER_SUPPLY_HEALTH_WARM:
		return "WARM";
	case POWER_SUPPLY_HEALTH_COOL:
		return "COOL";
	case POWER_SUPPLY_HEALTH_GOOD:
		return "GOOD";
#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
	case POWER_SUPPLY_HEALTH_UNDERVOLTAGE:
		return "UNDERVOL";
#endif
	default:
		return "UNKNOWN";
	}
}

static int buck_charge_loginfo_get_bat_present(void)
{
	int present = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_PRESENT,
		&present, 0, 1);

	return present;
}

static int buck_charge_loginfo_get_bat_voltage(void)
{
	int vol = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_VOLTAGE_NOW,
		&vol, 0, POWER_UV_PER_MV);

	return vol;
}

static int buck_charge_loginfo_get_bat_current(void)
{
	int cur = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CURRENT_NOW,
		&cur, 0, 1);

	return cur;
}

static int buck_charge_loginfo_get_charge_state(void)
{
	int state = 0;

	if (charge_get_charging_state(&state))
		return -EINVAL;

	return state;
}

static int buck_charge_loginfo_get_bat_capacity(void)
{
	int capacity = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY,
		&capacity, 0, 1);

	return capacity;
}

static int buck_charge_loginfo_get_bat_fcc(void)
{
	int bat_fcc = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY_FCC,
		&bat_fcc, 0, 1);

	return bat_fcc;
}

static int buck_charge_loginfo_get_bat_cycle(void)
{
	int cycle = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CYCLE_COUNT,
		&cycle, 0, 1);

	return cycle;
}

static const char *buck_charge_loginfo_get_shutdown_flag(void)
{
	if (power_cmdline_is_powerdown_charging_mode())
		return "OFF";
	else
		return "ON";
}

static int buck_charge_loginfo_dump_content(char *buf, int size, void *dev_data)
{
	int ret;

	if (!buf || (size <= 0))
		return -EINVAL;

	ret = snprintf_s(buf, size, size - 1, "%-6d %-10s  %-7d  %-7d  %-8d  %-8d  %-5d  %-12s  "
		"%-6d  %-7d  %-8d  %-6d  %-5d  %-4d  %-8d  %-8s  %-7d  %-5d  %-6s",
		buck_charge_loginfo_get_online(), buck_charge_loginfo_get_charge_type(),
		buck_charge_loginfo_get_usb_voltage(), charge_get_ibus(),
		charge_sysfs_get_sysfs_value(CHARGE_SYSFS_IIN_THERMAL), charge_get_iin_set(),
		charge_get_charge_enable_status(), buck_charge_loginfo_get_charge_status(),
		buck_charge_loginfo_get_bat_voltage(), buck_charge_loginfo_get_bat_current(),
		charge_get_charge_current(), charge_get_terminal_voltage(),
		buck_charge_loginfo_get_charge_state(), buck_charge_loginfo_get_bat_capacity(),
		buck_charge_loginfo_get_bat_fcc(), buck_charge_loginfo_get_bat_health(),
		buck_charge_loginfo_get_bat_present(), buck_charge_loginfo_get_bat_cycle(),
		buck_charge_loginfo_get_shutdown_flag());
	if (ret <= 0)
		return -EINVAL;

	return 0;
}

static int buck_charge_loginfo_dump_head(char *buf, int size, void *dev_data)
{
	int ret;

	if (!buf || (size <= 0))
		return -EINVAL;

	ret = snprintf_s(buf, size, size - 1, "online in_type     usb_vol  ibus     ibus_thl  "
		"ibus_set  ch_en  status        vol     cur      ibat_set  vterm   state  cap   "
		"bat_fcc   health    present  cycle  mode  ");
	if (ret <= 0)
		return -EINVAL;

	return 0;
}

static struct power_log_ops buck_charge_loginfo_ops = {
	.dev_name = "buck_charge",
	.dump_log_head = buck_charge_loginfo_dump_head,
	.dump_log_content = buck_charge_loginfo_dump_content,
};

static int __init buck_charge_loginfo_init(void)
{
	return power_log_ops_register(&buck_charge_loginfo_ops);
}

static void __exit buck_charge_loginfo_exit(void)
{
}

late_initcall(buck_charge_loginfo_init);
module_exit(buck_charge_loginfo_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("buck charge loginfo module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
