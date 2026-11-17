/*
 * echub_battery.c
 *
 * battery driver for echub
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/rtc.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/version.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/regmap.h>
#include <linux/fs.h>
#include <linux/suspend.h>
#include <linux/uaccess.h>
#include <securec.h>

#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/ioctl.h>
#include <linux/of_gpio.h>
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_ui_ne.h>
#include <chipset_common/hwpower/common_module/power_icon.h>
#include "echub_battery.h"
#ifdef CONFIG_HW_ECHUB_SHIP_MODE
#include "echub_ship_mode.h"
#endif
#include "ospm_printf.h"
#include "echub_float_charge.h"
#include "echub_turbo_charge.h"
#include "echub_basp.h"
#ifdef CONFIG_ARMPC_ECHUB_HMI
#include "hmi/hmi.h"
#endif

#define WINDOW_LEN                   (10)
#define WORK_INTERVAL_QUICK                 (1000)

#define BATTERY_CAPACITY_FULL                 (100)
#define BATTERY_CAPACITY_LOW                  (10)
#define BATTERY_CAPACITY_CRITICAL             (3)
#define BATTERY_VOLTAGE_MAX_DESIGN_4S1P       (17600000)
#define BATTERY_VOLTAGE_MAX_DESIGN_2S2P       (8800000)

#define BATTERY_SOH_NEW_CYCLE_COUNT           (50)
#define BATTERY_CAPACITY_DIFF                 (2)

#define BATTERY_2S_MAX                     (8000)
#define BATTERY_3S_MAX                     (12000)

#define MONITOR_WAIT_TIME             2000 /* 2s = 2000ms */

#define I2C_DATA_BYTE   2
#define GET_BATT_RBUF_SIZE   6
#define BATT_STATIC_BUFLEN  4
#define SHIFT_OFFSET_4  4
#define SHIFT_OFFSET_5  5
#define SHIFT_OFFSET_6  6
#define SHIFT_OFFSET_7  7
#define SHIFT_OFFSET_8  8

#define NUM_FUNCTIONS 7
 // Temp(K) - 2730 + 5 / 10 = Temp(C)
#define TEMP_CONVERT(m, n) (((((u16)(m)) << 8) + (n) - 2730 + 5) / 10)

enum ec_charge_status {
	CHG_STATE_CHARGE = 1,
	CHG_STATE_DISCHARGE,
	CHG_STATE_IDLE
};

static bool g_mmi_test_interface_support = false;
static unsigned int capacity_filter[WINDOW_LEN];
static unsigned int capacity_sum;

struct echub_batt_device_info *g_echub_bat_dev;

static enum power_supply_property echub_battery_props[] = {
	POWER_SUPPLY_PROP_STATUS,
	POWER_SUPPLY_PROP_HEALTH,
	POWER_SUPPLY_PROP_PRESENT,
	POWER_SUPPLY_PROP_ONLINE,
	POWER_SUPPLY_PROP_TECHNOLOGY,
	POWER_SUPPLY_PROP_VOLTAGE_NOW,
	POWER_SUPPLY_PROP_CURRENT_NOW,
	POWER_SUPPLY_PROP_CAPACITY,
	POWER_SUPPLY_PROP_CAPACITY_LEVEL,
	POWER_SUPPLY_PROP_TEMP,
	POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN,
	POWER_SUPPLY_PROP_CHARGE_FULL,
	POWER_SUPPLY_PROP_CHARGE_NOW,
	POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN,
	POWER_SUPPLY_PROP_ENERGY_FULL,
	POWER_SUPPLY_PROP_ENERGY_NOW,
	POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN,
	POWER_SUPPLY_PROP_CYCLE_COUNT,
	POWER_SUPPLY_PROP_BRAND,
};

static enum power_supply_property echub_ac_props[] = {
	POWER_SUPPLY_PROP_ONLINE,
	POWER_SUPPLY_PROP_HEALTH,
};

static ssize_t battery_soh_show(struct device *dev,
					  struct device_attribute *attr, char *buf)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;
	if (!di || !buf) {
		echub_err("[%s:%dL] di or buf is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	if (di->bat_cycle_count <= BATTERY_SOH_NEW_CYCLE_COUNT) {
		return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "New");
	}
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "Not new");
}

static DEVICE_ATTR(battery, 0440, battery_soh_show, NULL);

static struct attribute *batt_info_attributes[] = {
	&dev_attr_battery.attr,
	NULL
};

static const struct attribute_group huawei_batt_soh_info_node = {
	.attrs = batt_info_attributes,
};

static struct platform_device huawei_batt_soh_info = {
	.name = "huawei_batt_info",
	.id = -1,
};

struct echub_batt_device_info *echub_get_batt_di(void)
{
	return g_echub_bat_dev;
}

static int get_ac_status(struct echub_batt_device_info *di)
{
	int ret;
	int ac_status = 0;
	unsigned char r_buf[4] = {0}; // 4 is r_buf size
 
	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
		echub_info("%s di is null\n", __func__);
		return 0;
	}
 
	if (di->ac_status_from_ec) {
		ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, AC_STATUS_QUERY, r_buf, 4); // 4 is r_buf size
		if (ret != 0) {
			echub_err("%s failed, ret = %d", __func__, ret);
			return di->ac_online;
		}
		ac_status = r_buf[2] & 0x01; // 2 is data byte
		return ac_status;
	}
 
	if (di->ac_status_gpio > 0)
			ac_status = gpio_get_value(di->ac_status_gpio);
 
	return ac_status;
}

static void report_ac_status(struct echub_batt_device_info *di)
{
	int ac_status;

	if (!di) {
		echub_err("%s di is null\n", __func__);
		return;
	}

	ac_status = get_ac_status(di);
	if (di->ac_online == ac_status)
		return;
	di->ac_online = ac_status;
	if (ac_status) {
		di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
	} else {
		di->charge_status = POWER_SUPPLY_STATUS_DISCHARGING;
	}
	power_supply_changed(di->ac);
	power_supply_changed(di->bat);
}

#if defined(CONFIG_HW_ECHUB_FLOAT_CHARGE) || defined(CONFIG_HW_ECHUB_TURBO_CHARGE)
static void echub_notify_icon_type(int power)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;
	int last_power;
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}
	last_power = di->ac_power;
	if (power != di->ac_power) {
		echub_info("battery: ac power: %d\n", power);
		di->ac_power = power;
		power_ui_event_notify(POWER_UI_NE_INNER_MAX_POWER, &di->ac_power);
		if (di->ac_power < TURBO_CHG_ADAPTER_POWER) {
		    power_ui_int_event_notify(POWER_UI_NE_MAX_POWER, 0);
        } else {
            power_ui_int_event_notify(POWER_UI_NE_MAX_POWER, di->ac_power);
        }

		if (di->ac_power >= QUICK_CHG_ADAPTER_POWER) {
			power_icon_notify(ICON_TYPE_SUPER);
			if (di->ac_power >= TURBO_CHG_ADAPTER_POWER) {
				power_event_report_str_uevent("BMS_EVT=TURBO_CHARGE");
			}
			power_event_bnc_notify(POWER_BNT_SOC_DECIMAL, POWER_NE_SOC_DECIMAL_DC, &di->ac_power);
		} else if (di->ac_power > 0) {
			power_icon_notify(ICON_TYPE_NORMAL);
		} else {
			power_icon_notify(ICON_TYPE_INVALID);
		}
		if (di->ac_power < TURBO_CHG_ADAPTER_POWER && last_power >= TURBO_CHG_ADAPTER_POWER) {
			echub_info("reset turbo charge status");
#ifdef CONFIG_HW_ECHUB_TURBO_CHARGE
			echub_turbo_charge_reset_status();
#endif
		}
	}
}
#endif

static void echub_create_battery_strategy_sysfs(void)
{
#ifdef CONFIG_HW_ECHUB_FLOAT_CHARGE
	echub_float_charge_init(g_echub_bat_dev->dev);
#endif
#ifdef CONFIG_HW_ECHUB_TURBO_CHARGE
	echub_turbo_charge_sysfs_create_group(g_echub_bat_dev->dev);
#endif
	echub_basp_create_group();
}

static void start_monitor_notify_change(struct echub_batt_device_info *di)
{
	queue_delayed_work(system_power_efficient_wq, &di->echub_batt_monitor_work, msecs_to_jiffies(MONITOR_WAIT_TIME));
	power_supply_changed(di->ac);
	power_supply_changed(di->bat);
}

static void echub_ac_irq_work(struct work_struct *work)
{
	struct echub_batt_device_info *di = NULL;
	int ac_status = 0;
	if (!work) {
		echub_err("%s work is null\n", __func__);
		return;
	}
	di = container_of(work, struct echub_batt_device_info, irq_work.work);
	if (!di) {
		echub_err("%s di is null\n", __func__);
		return;
	}

	ac_status = get_ac_status(di);
	if (ac_status != di->ac_online) {
		echub_info("battery: ac status change to %d\n", ac_status);
		if (ac_status)
			di->ec_charge_status = CHG_STATE_CHARGE;
	}

	if (ac_status) {
		if (di->ac_online != 1) {
			di->ac_online = 1;
			start_monitor_notify_change(di);
		}
		if (di->capacity == BATTERY_CAPACITY_FULL) {
			if (di->charge_status != POWER_SUPPLY_STATUS_FULL) {
				di->charge_status = POWER_SUPPLY_STATUS_FULL;
				start_monitor_notify_change(di);
				power_event_bnc_notify(POWER_BNT_SOC_DECIMAL, POWER_NE_CHARGING_STOP, &di->ac_power);
			}
		} else if (di->ec_charge_status >= CHG_STATE_DISCHARGE) {
			if (di->charge_status != POWER_SUPPLY_STATUS_NOT_CHARGING) {
				di->charge_status = POWER_SUPPLY_STATUS_NOT_CHARGING;
				start_monitor_notify_change(di);
				power_event_bnc_notify(POWER_BNT_SOC_DECIMAL, POWER_NE_CHARGING_STOP, &di->ac_power);
			}
		} else if (di->charge_status != POWER_SUPPLY_STATUS_CHARGING) {
			di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
			start_monitor_notify_change(di);
		}
	} else if ((ac_status <= 0) && (di->charge_status != POWER_SUPPLY_STATUS_DISCHARGING)) {
		di->charge_status = POWER_SUPPLY_STATUS_DISCHARGING;
		di->ac_online = 0;
		start_monitor_notify_change(di);
		// ac out
		power_event_bnc_notify(POWER_BNT_SOC_DECIMAL, POWER_NE_CHARGING_STOP, &di->ac_power);
	}
	queue_delayed_work(system_power_efficient_wq, &di->irq_work, msecs_to_jiffies(WORK_INTERVAL_QUICK));
}

static int get_batt_health(struct echub_batt_device_info *di)
{
	int ret;
	u8 value[GET_BATT_RBUF_SIZE] = {0};

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_HEALTH_OFFSET, value, 4); // 4 is r_buf size
	if (ret != 0) {
		return ret;
	}
	if (((value[2] >> SHIFT_OFFSET_4) & 1) == 0) // Take the remainder of 2
		di->bat_health = POWER_SUPPLY_HEALTH_GOOD;
	else
		di->bat_health = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;

	if (((value[2] >> SHIFT_OFFSET_5) & 1) == 1) // Take the remainder of 2
		di->bat_health = POWER_SUPPLY_HEALTH_OVERHEAT;
	if (((value[2] >> SHIFT_OFFSET_6) & 1) == 1) // Take the remainder of 2
		di->bat_health = POWER_SUPPLY_HEALTH_OVERVOLTAGE;

	echub_info("battery: bat_health = %d\n", di->bat_health);
	return 0;
}

static int get_batt_exist(struct echub_batt_device_info *di)
{
	int ret;
	u8 value[GET_BATT_RBUF_SIZE] = {0};

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_EXIST_OFFSET, value, 4); // 4 is r_buf size
	if (ret != 0) {
		return ret;
	}
	if (((value[2] >> 1) & 1) == 1) // Take the remainder of 2
		di->bat_exist = 1;
	else
		di->bat_exist = 0;

	echub_info("battery: bat_exist = %d\n", di->bat_exist);
	return 0;
}

static int get_batt_voltage(struct echub_batt_device_info *di)
{
	int ret;
	u8 value[GET_BATT_RBUF_SIZE] = {0};
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG2, BATTERY_VOLTAGE_OFFSET, value, 5); // 5 is r_buf size
	if (ret) {
		echub_err("battery: get bat_voltage failed: %d\n", ret);
		return ret;
	}
	di->bat_voltage = (u16)(value[3] << SHIFT_OFFSET_8) + value[2]; // byte 2 and 3 is voltage low/high byte
	echub_info("battery: bat_voltage = %d\n", di->bat_voltage);
	return 0;
}

static int get_batt_current(struct echub_batt_device_info *di)
{
	int ret;
	u8 value[GET_BATT_RBUF_SIZE] = {0};
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG2, BATTERY_CURRENT_OFFSET, value, 5); // 5 is r_buf size
	if (ret) {
		echub_err("battery: get bat_current failed: %d\n", ret);
		return ret;
	}
	di->bat_current = (short)((u16)(value[3] << SHIFT_OFFSET_8) + (u16)value[2]); // 2 and 3 is current low/high byte
	echub_info("battery: bat_current = %d\n", di->bat_current);
	return 0;
}

static int get_batt_temperature(struct echub_batt_device_info *di)
{
	int ret;
	char value[GET_BATT_RBUF_SIZE] = {0};
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG2, BATTERY_TEMPERATURE_OFFSET, value, 5); // 5:r_buf size
	if (ret) {
		echub_err("battery: get bat_temperature failed: %d\n", ret);
		return ret;
	}
	di->bat_temperature = TEMP_CONVERT(value[3], value[2]); // 2 and 3 is temperature low/high byte
	echub_info("battery: bat_temperature = %d\n", di->bat_temperature);
	return 0;
}

static int get_batt_rmc(struct echub_batt_device_info *di)
{
	int ret;
	u8 value[GET_BATT_RBUF_SIZE] = {0};
	ret = di->echub_dev->read_func(di->echub_dev, 0x0263, 0x03, value, 5); // 5 is r_buf size
	if (ret) {
		echub_err("battery: get bat_rm failed: %d\n", ret);
		return ret;
	}
	di->bat_rm = (u16)(value[3] << SHIFT_OFFSET_8) + value[2]; // 2 and 3 is current low/high byte
	echub_info("battery: bat_rm = %d\n", di->bat_rm);
	return 0;
}

static int get_batt_fcc(struct echub_batt_device_info *di)
{
	int ret;
	char value[GET_BATT_RBUF_SIZE] = {0};
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG2, BATTERY_FCC_OFFSET, value, 5); // 5 is r_buf size
	if (ret) {
		echub_err("battery: get bat_fcc failed: %d\n", ret);
		return ret;
	}
	di->bat_fcc = (u16)(value[3] << SHIFT_OFFSET_8) + value[2]; // 2 and 3 is current low/high byte
	echub_info("battery: bat_fcc = %d\n", di->bat_fcc);
	return 0;
}

static int (*const g_get_batt_data_func[NUM_FUNCTIONS])(struct echub_batt_device_info *) = {
	get_batt_health,
	get_batt_exist,
	get_batt_temperature,
	get_batt_voltage,
	get_batt_current,
	get_batt_rmc,
	get_batt_fcc,
};

static int update_minor_data(struct echub_batt_device_info *di)
{
	if (di->ignore_minor_data) {
		di->ignore_minor_data = false;
		echub_info("battery: work ignore minor data\n");
		return 0;
	}

	for (int i = 0; i < ARRAY_SIZE(g_get_batt_data_func); i++) {
		if (g_get_batt_data_func[i](di) != 0) {
			return -1;
		}
		msleep(5); // sleep 5ms
	}

	return 0;
}

static void write_low_battery_thres(struct echub_batt_device_info *di)
{
	if (!di->sync_low_battery_thres || di->low_battery_thres == 0)
		return;

	int ret = di->echub_dev->write_func(di->echub_dev, SET_LOW_BATTERY_ADDR, di->low_battery_thres);
	if (ret) {
		echub_err("write low battery thres failed: %d\n", ret);
		return;
	}
	di->sync_low_battery_thres = false;
	echub_info("sync low battery thres:%d\n", di->low_battery_thres);
}

static int get_battery_capacity(struct echub_batt_device_info *di, bool *is_psy_changed)
{
	int ret;
	u8 value[6] = {0};

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_CAPACITY_OFFSET, value, NUM_4);
	if (ret) {
		echub_err("battery: get battery capacity failed: %d\n", ret);
		return ret;
	}

	*is_psy_changed = (*is_psy_changed) | (di->capacity != value[NUM_2]);
	di->capacity = value[NUM_2];
	echub_info("battery: get bat_capacity: %d, is_psy_changed %d", di->capacity, *is_psy_changed);
	return 0;
}

static int get_battery_rm_post_suspend(struct echub_batt_device_info *di, bool *is_psy_changed)
{
	int ret;
	u8 value[6] = {0};
	int temp_rm;

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG0, BATTERY_RMC, value, NUM_5);
	if (ret) {
		echub_err("battery: get battery rm failed: %d\n", ret);
		return ret;
	}
	temp_rm = (u16)(value[NUM_3] << NUM_8) + value[NUM_2];
	*is_psy_changed = (*is_psy_changed) | (di->bat_rm != temp_rm);
	di->bat_rm = temp_rm;
	echub_info("battery: get bat_rm: %d, is_psy_changed %d", di->bat_rm, *is_psy_changed);

	return 0;
}

static int get_charge_status(struct echub_batt_device_info *di, bool *is_psy_changed)
{
	int ret;
	char value[6] = {0};

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, CHARGE_STATUS, value, NUM_4);
	if (ret) {
		echub_err("battery: get ec_charge_status failed: %d\n", ret);
		return ret;
	}

	*is_psy_changed = (*is_psy_changed) | (di->ec_charge_status != value[NUM_2]);
	di->ec_charge_status = value[NUM_2];
	echub_info("battery: get ec_charge_status: %d, is_psy_changed %d", value[NUM_2], *is_psy_changed);
	return 0;
}

static void echub_battery_work(struct work_struct *work)
{
	struct echub_batt_device_info *di = NULL;
	u8 value[GET_BATT_RBUF_SIZE] = {0};
	int ret, power;
	bool is_psy_changed = false;

	if (!work) {
		echub_err("[%s:%dL] work is NULL\n", __func__, __LINE__);
		return;
	}
	di = container_of(work, struct echub_batt_device_info, echub_batt_monitor_work.work);
	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}

	// get battery capacity
	ret = get_battery_capacity(di, &is_psy_changed);
	if (ret)
		goto echub_trans_failed;
	msleep(10); // sleep 10ms

	// get battery rm post suspend
	ret = get_battery_rm_post_suspend(di, &is_psy_changed);
	if (ret)
		goto echub_trans_failed;
	msleep(10); // sleep 10ms
#ifdef CONFIG_HW_ECHUB_FLOAT_CHARGE
	// di->ec_charge_status
	ret = get_charge_status(di, &is_psy_changed);
	if (ret)
		goto echub_trans_failed;
	msleep(10); // sleep 10ms
#endif
#if defined(CONFIG_HW_ECHUB_FLOAT_CHARGE) || defined(CONFIG_HW_ECHUB_TURBO_CHARGE)
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG0, CHARGE_MAX_POWER, value, 5); // readbuff size 5
	if (ret)
		goto echub_trans_failed;

	power = (value[2] | (value[3] << SHIFT_OFFSET_8)) * 1000; // 2 3 is low/high byte, 1000 is kW to W
	echub_notify_icon_type(power);

	msleep(10); // sleep 10ms
#endif

	if (update_minor_data(di))
		goto echub_trans_failed;

	write_low_battery_thres(di);

echub_trans_failed:
	queue_delayed_work(system_power_efficient_wq, &di->echub_batt_monitor_work, msecs_to_jiffies(di->monitoring_interval));
	if (is_psy_changed)
		power_supply_changed(di->bat);
}

static int echub_ac_get_property(struct power_supply *psy,
				enum power_supply_property psp,
				union power_supply_propval *val)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;

	if (!di || !psy || !val) {
		echub_info("NULL point in [%s]\n", __func__);
		return -EINVAL;
	}

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		if (di->ac_online)
			val->intval = 1;
		else
			val->intval = 0;
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = di->power_supply_status;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

static int echub_battery_get_static_props(struct power_supply *psy,
					 enum power_supply_property psp,
					 union power_supply_propval *val)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;
	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	switch (psp) {
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = di->bat_exist;
		break;
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		if (!di->bat_exist)
			di->bat_technolog = POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
		else
			di->bat_technolog = POWER_SUPPLY_TECHNOLOGY_LION;
		val->intval = di->bat_technolog;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
		if (!di->bat_exist)
			val->intval = 0;
		else
			val->intval = di->bat_volt_max_design;
		break;
	case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
		if (!di->bat_exist)
			val->intval = 0;
		else
			val->intval = di->bat_info_type ? di->bat_design_fcc * 1000 : di->bat_design_fcc; // 1000 is mAh to Ah
		break;
	case POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN:
		if (!di->bat_exist)
			val->intval = 0;
		else
			val->intval = di->bat_design_fcc * di->bat_volt_avg;
		break;
	case POWER_SUPPLY_PROP_BRAND:
		val->strval = di->bat_manufactory_name;
		break;
	case POWER_SUPPLY_PROP_CYCLE_COUNT:
		val->intval = di->bat_cycle_count;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

static void echub_battery_update_charge_status(struct echub_batt_device_info *di)
{
	if (di->ac_online != 1) {
		return;
	}
	if (di->capacity == BATTERY_CAPACITY_FULL) {
		di->charge_status = POWER_SUPPLY_STATUS_FULL;
	} else if (di->ec_charge_status >= CHG_STATE_DISCHARGE) {
		di->charge_status = POWER_SUPPLY_STATUS_NOT_CHARGING;
	} else if (di->charge_status != POWER_SUPPLY_STATUS_CHARGING) {
		di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
	}
}

static void echub_battery_capacity_level(struct echub_batt_device_info *info)
{
	if (!info->bat_exist)
		info->bat_capacity_level = POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;
	else if (info->capacity <= BATTERY_CAPACITY_CRITICAL)
		info->bat_capacity_level = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
	else if (info->capacity <= BATTERY_CAPACITY_LOW)
		info->bat_capacity_level = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
	else if (info->capacity == BATTERY_CAPACITY_FULL)
		info->bat_capacity_level = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
	else
		info->bat_capacity_level = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
}

/**********************************************************
* Function:		echub_battery_get_property
* Discription:		OS get battery property
* Parameters:		struct power_supply *psy,
					enum power_supply_property psp,
					union power_supply_propval *val,
* return value:	0-sucess or others-fail
**********************************************************/
static int echub_battery_get_property(struct power_supply *psy,
					 enum power_supply_property psp,
					 union power_supply_propval *val)
{
	int ret;
	struct echub_batt_device_info *di = g_echub_bat_dev;

	if (!di || !psy || !val) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	ret = echub_battery_get_static_props(psy, psp, val);
	if (!ret)
		goto battery_get_property_end;

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		echub_battery_update_charge_status(di);
		val->intval = di->charge_status;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		val->intval = di->bat_voltage * 1000; // 1000 is mV to V
		break;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		val->intval = di->bat_info_type ? di->bat_current * 1000 : di->bat_current; // 1000 is mA to A
		break;
	case POWER_SUPPLY_PROP_TEMP:
		val->intval = di->bat_exist ? di->bat_temperature * 10 : 0; // decimal num 10
		break;
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = di->ac_online;
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = di->bat_exist ? di->bat_health : POWER_SUPPLY_HEALTH_UNKNOWN;
		break;
	case POWER_SUPPLY_PROP_CAPACITY:
		val->intval = di->capacity;
		break;
	case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
		echub_battery_capacity_level(di);
		val->intval = di->bat_capacity_level;
		break;
	case POWER_SUPPLY_PROP_CHARGE_NOW:
		val->intval = di->bat_info_type ? di->bat_rm * 1000 : di->bat_rm; // decimal num 1000
		break;
	case POWER_SUPPLY_PROP_CHARGE_FULL:
		val->intval = di->bat_info_type ? di->bat_fcc * 1000 : di->bat_fcc; // decimal num 1000
		break;
	case POWER_SUPPLY_PROP_ENERGY_FULL:
		val->intval = di->bat_fcc * di->bat_volt_avg;
		break;
	case POWER_SUPPLY_PROP_ENERGY_NOW:
		val->intval = di->bat_rm * di->bat_volt_avg;
		break;
	default:
		return -EINVAL;
	}
battery_get_property_end:
	return 0;
}

static char *echub_supplied_to[] = {
	"echub_battery",
};

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 13, 0))
static const struct power_supply_config echub_battery_cfg = {
	.supplied_to = echub_supplied_to,
	.num_supplicants = ARRAY_SIZE(echub_supplied_to),
};

static const struct power_supply_desc echub_battery_desc = {
	.name			= "Battery",
	.type			= POWER_SUPPLY_TYPE_BATTERY,
	.properties		= echub_battery_props,
	.num_properties		= ARRAY_SIZE(echub_battery_props),
	.get_property		= echub_battery_get_property,
};

static const struct power_supply_desc echub_mains_desc = {
	.name			= "Mains",
	.type			= POWER_SUPPLY_TYPE_MAINS,
	.properties		= echub_ac_props,
	.num_properties		= ARRAY_SIZE(echub_ac_props),
	.get_property		= echub_ac_get_property,
};
#endif
/**********************************************************
*  Function:       parse_cap_dec_dts
*  Discription:    parse the module dts config value of capacity decimal
*  Parameters:   np:device_node
*                      di:echub_batt_device_info
*  return value:  null
**********************************************************/
static void parse_cap_dec_dts(struct echub_batt_device_info *di)
{
	int ret = 0;
	int i = 0;
	int array_len = 0;
	u32 cap_dec_tmp[CAP_DEC_PARA_TOTAL * CAPATICY_DEC_PARA_LEVEL] = {0};
	struct device_node *np = di->dev->of_node;

	array_len = of_property_count_u32_elems(np, "capacity_dec_para");
	if ((array_len <= 0) || (array_len % CAP_DEC_PARA_TOTAL != 0)) {
		echub_err("capacity_dec_para is invalid, please check capacity_dec_para number!!\n");
		goto FuncEnd;
	} else if (array_len > CAPATICY_DEC_PARA_LEVEL * CAP_DEC_PARA_TOTAL) {
		echub_err("capacity_dec_para is too long, please check capacity_dec_para number!!\n");
		goto FuncEnd;
	} else {
		ret = of_property_read_u32_array(np, "capacity_dec_para", cap_dec_tmp, array_len);
		if (ret) {
			echub_err("dts:get capacity_dec_para fail!\n");
			goto FuncEnd;
		} else {
			di->capacity_dec_total_level = array_len / CAP_DEC_PARA_TOTAL;
			for (i = 0; i < di->capacity_dec_total_level; i++) {
				di->cap_dec_para[i].cap_dec_base_decimal =
					cap_dec_tmp[(int)(CAP_DEC_BASE_DECIMAL + CAP_DEC_PARA_TOTAL * i)];
				di->cap_dec_para[i].cap_dec_sample_nums =
					cap_dec_tmp[(int)(CAP_DEC_SAMPLE_NUMS + CAP_DEC_PARA_TOTAL * i)];
				di->cap_dec_para[i].cap_dec_timer_interval =
					cap_dec_tmp[(int)(CAP_DEC_TIMER_INTERVAL + CAP_DEC_PARA_TOTAL * i)];
				echub_info("cap_dec_para[%d], base_decimal: %-3d sample_nums: %-3d timer_interval: %-3d\n",
						i, di->cap_dec_para[i].cap_dec_base_decimal,
						di->cap_dec_para[i].cap_dec_sample_nums, di->cap_dec_para[i].cap_dec_timer_interval);
			}
			return;
		}
	}

FuncEnd:
	di->capacity_dec_total_level = 1;
	di->cap_dec_para[0].cap_dec_base_decimal = BASE_DECIMAL;
	di->cap_dec_para[0].cap_dec_sample_nums = CAPACITY_DEC_SAMPLE_NUMS;
	di->cap_dec_para[0].cap_dec_timer_interval = CAPATICY_DEC_TIMER_INTERVAL;
	echub_info("cap_dec_para[0], base_decimal: %-3d sample_nums: %-3d timer_interval: %-3d\n",
			di->cap_dec_para[0].cap_dec_base_decimal,
			di->cap_dec_para[0].cap_dec_sample_nums, di->cap_dec_para[0].cap_dec_timer_interval);
}
/**********************************************************
*  Function:       parse_cap_lock_dts
*  Discription:    parse the module dts config value
*  Parameters:   np:device_node
*                      di:echub_batt_device_info
*  return value:  0-sucess or others-fail
**********************************************************/
static int parse_vth_correct_dts(struct echub_batt_device_info *di)
{
	int i = 0;
	struct device_node *np = di->dev->of_node;

	if (of_property_read_u32(np, "vth_correct_en", (u32 *)&di->vth_correct_en)) {
		di->vth_correct_en = 0;
		echub_err("error:get vth_correct_en value failed, used default value!\n");
	}

	if (of_property_read_u32_array(np, "vth_correct_para",
			(u32 *)&di->vth_correct_data[0],
			sizeof(di->vth_correct_data) / sizeof(int))) {
		di->vth_correct_en = 0;
		echub_err("get vth_correct_para fail!!\n");
		return -EINVAL;
	}

	for (i = 0; i < CAP_LOCK_PARA_LEVEL; i++)
		echub_info("di->vth_correct_data[%d]:%d,%d\n", i,
			di->vth_correct_data[i].cap, di->vth_correct_data[i].level_vol);

	return 0;
}

/**********************************************************
*  Function:       get_ac_status_gpio
*  Discription:    get and init the ac_status_gpio
*  Parameters:   np:device_node
*                      di:echub_batt_device_info
*  return value:  0-sucess or others-fail
**********************************************************/
static int get_ac_status_gpio(struct echub_batt_device_info *di)
{
	struct device_node *np = di->dev->of_node;

	di->ac_status_gpio = of_get_named_gpio(np, "ac_status_gpio", 0);
	if (di->ac_status_gpio < 0) {
		echub_err("Get ac_status_gpio failed\n");
		return -EINVAL;
	}

	if (!gpio_is_valid(di->ac_status_gpio)) {
		echub_err("ac_status_gpio is not valid\n");
		return -EINVAL;
	}

	if (devm_gpio_request(di->dev, di->ac_status_gpio, "ac_status_gpio")) {
		echub_err("Could not request %d gpio\n", di->ac_status_gpio);
		return -EINVAL;
	} else if (gpio_direction_input(di->ac_status_gpio)) {
		echub_err("Could not set gpio %d as input\n", di->ac_status_gpio);
		return -EINVAL;
	}

	echub_info("ac_status_gpio = %d\n", di->ac_status_gpio);
	return 0;
}

static int get_batt_name(struct echub_batt_device_info *di)
{
	int ret, rbuf_len, i;
	char brand[BATT_NAME_LEN + 1] = {0};
	int cell_brand, package_brand;
	int cell_valid;
	int package_valid;

	rbuf_len = BATT_NAME_LEN + 1;
	ret = di->echub_dev->transfer_func(di->echub_dev, 0x044F, NULL, 0, brand, rbuf_len);
	if (ret) {
		echub_err("get battery name failed: %d\n", ret);
		return ret;
	}

	if (brand[BATT_NEW_PACK_BIT] >= '0' && brand[BATT_NEW_PACK_BIT] <= '9') {
		cell_valid = BATT_OLD_CELL_BIT;
		package_valid = BATT_OLD_PACK_BIT;
		echub_info("bit[6]:%c is number, old frame\n", brand[BATT_NEW_PACK_BIT]);
	} else if (brand[BATT_NEW_PACK_BIT] >= 'A' && brand[BATT_NEW_PACK_BIT] <= 'Z') {
		cell_valid = BATT_NEW_CELL_BIT;
		package_valid = BATT_NEW_PACK_BIT;
		echub_info("bit[6]:%c is not number, new frame\n", brand[BATT_NEW_PACK_BIT]);
	} else {
		echub_err("get battery bit[6]:%c invalid\n", brand[BATT_NEW_PACK_BIT]);
		return -EINVAL;
	}
	
	for (i = 0; i < sizeof(batt_cell_brand) / sizeof(batt_cell_brand[0]); i++) {
		if (batt_cell_brand[i].code == brand[cell_valid]) {
			cell_brand = i;
			cell_valid = 0;
			break;
		}
	}
	for (i = 0; i < sizeof(batt_package_brand) / sizeof(batt_package_brand[0]); i++) {
		if (batt_package_brand[i].code == brand[package_valid]) {
			package_brand = i;
			package_valid = 0;
			break;
		}
	}
	if (cell_valid || package_valid) {
		echub_err("[%s] cell_valid | package_valid = %d|%d not found in table\n", __func__, cell_valid, package_valid);
		return -EINVAL;
	}
	scnprintf(di->bat_manufactory_name, BATT_NAME_LEN, "%s%s",
		batt_package_brand[package_brand].name, batt_cell_brand[cell_brand].name);
	echub_info("[%s] di->bat_manufactory_name = %s\n", __func__, di->bat_manufactory_name);
	return 0;
}

static void update_bat_design_fcc(struct echub_batt_device_info *di)
{
	int ret = 0;
	u8 temp = 0;
	u8 value[BATT_STATIC_BUFLEN] = {0};

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_DESIGN_FCC_OFFSET1, value, BATT_STATIC_BUFLEN);
	if (ret) {
		echub_err("get bat_design_fcc low 8bits failed %d\n", ret);
	} else {
		temp = value[I2C_DATA_BYTE];
	}
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_DESIGN_FCC_OFFSET2, value, BATT_STATIC_BUFLEN);
	if (ret) {
		echub_err("get bat_design_fcc high 8bits failed %d\n", ret);
		return;
	}
	di->bat_design_fcc = ((u16)value[I2C_DATA_BYTE] << SHIFT_OFFSET_8) + temp;
	echub_info("di->bat_design_fcc = %d\n", di->bat_design_fcc);
}

static void update_bat_volt_avg(struct echub_batt_device_info *di)
{
	int ret = 0;
	u8 temp = 0;
	u8 value[BATT_STATIC_BUFLEN] = {0};

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_VOLT_AVG_OFFSET1, value, BATT_STATIC_BUFLEN);
	if (ret) {
		echub_err("get bat_volt_avg low 8bits failed %d\n", ret);
	} else {
		temp = value[I2C_DATA_BYTE];
	}
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_VOLT_AVG_OFFSET2, value, BATT_STATIC_BUFLEN);
	if (ret) {
		echub_err("get bat_volt_avg high 8bits failed %d\n", ret);
		return;
	}
	di->bat_volt_avg = ((u16)value[I2C_DATA_BYTE] << SHIFT_OFFSET_8) + temp;
	echub_info("di->bat_volt_avg = %d\n", di->bat_volt_avg);
}

static void update_bat_cycle_count(struct echub_batt_device_info *di)
{
	int ret = 0;
	u8 temp = 0;
	u8 value[BATT_STATIC_BUFLEN] = {0};

	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_CYCLE_COUNT_OFFSET1, value, BATT_STATIC_BUFLEN);
	if (ret) {
		echub_err("get bat_cycle_count low 8bits failed %d\n", ret);
	} else {
		temp = value[I2C_DATA_BYTE];
	}
	ret = di->echub_dev->read_func(di->echub_dev, BATTERY_REG1, BATTERY_CYCLE_COUNT_OFFSET2, value, BATT_STATIC_BUFLEN);
	if (ret) {
		echub_err("get bat_cycle_count high 8bits failed %d\n", ret);
		return;
	}
	di->bat_cycle_count = ((u16)value[I2C_DATA_BYTE] << SHIFT_OFFSET_8) + temp;
	echub_info("di->bat_cycle_count = %d\n", di->bat_cycle_count);
}

static void get_battery_static_paras_from_ec(struct echub_batt_device_info *di)
{
	int ret = 0;

	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}
	
	update_bat_design_fcc(di);
	update_bat_volt_avg(di);
	update_bat_cycle_count(di);

	ret = get_batt_name(di);
	if (ret)
		echub_err("get batt_name failed %d\n", ret);
}

static int device_info_interval_data_init(struct echub_batt_device_info *di, int array_len)
{
	int idata = 0;
	int i = 0;
	int ret = 0;
	const char *bci_data_string = NULL;

	if (!di || !di->dev)
		return -EINVAL;

	for (i = 0; i < array_len; i++) {
		ret = of_property_read_string_index(di->dev->of_node, "bci_work_interval_para", i, &bci_data_string);
		if (ret) {
			echub_err("get bci_work_interval_para failed\n");
			return -EINVAL;
		}

		if (kstrtoint(bci_data_string, 10, &idata)) // 10 means decimal notation
			continue;
		switch (i % WORK_INTERVAL_PARA_TOTAL) {
		case WORK_INTERVAL_CAP_MIN:
			if ((idata < CAPACITY_MIN) || (idata > CAPACITY_MAX)) {
				echub_err("the bci_work_interval_para cap_min is out of range!!\n");
				return -EINVAL;
			}
			di->interval_data[i / (WORK_INTERVAL_PARA_TOTAL)].cap_min = idata;
			break;
		case WORK_INTERVAL_CAP_MAX:
			if ((idata < CAPACITY_MIN) || (idata > CAPACITY_MAX)) {
				echub_err("the bci_work_interval_para cap_max is out of range!!\n");
				return -EINVAL;
			}
			di->interval_data[i / (WORK_INTERVAL_PARA_TOTAL)].cap_max = idata;
			break;
		case WORK_INTERVAL_VALUE:
			if ((idata < WORK_INTERVAL_MIN) || (idata > WORK_INTERVAL_MAX)) {
				echub_err("the bci_work_interval_para work_interval is out of range!!\n");
				return -EINVAL;
			}
			di->interval_data[i / (WORK_INTERVAL_PARA_TOTAL)].work_interval = idata;
			break;
		default:
			echub_err("bad work interval VALUE!!\n");
			break;
		}
		echub_info("di->interval_data[%d][%d] = %d\n",
					i / (WORK_INTERVAL_PARA_TOTAL), i % (WORK_INTERVAL_PARA_TOTAL), idata);
	}

	return 0;
}

/**********************************************************
*  Function:       echub_batt_parse_dts
*  Discription:    parse the module dts config value
*  Parameters:   np:device_node
*                      di:echub_batt_device_info
*  return value:  0-sucess or others-fail
**********************************************************/
static int echub_batt_parse_dts(struct echub_batt_device_info *di)
{
	int ret = 0;
	int array_len = 0;
	struct device_node *np = di->dev->of_node;

	if (!np) {
		echub_err("[%s:%dL] np is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	if (of_property_read_u32(np, "bci_soc_at_term", (u32 *)&di->bci_soc_at_term)) {
		di->bci_soc_at_term = 100; // 100 is default value
		echub_err("error:get bci_soc_at_term value failed, no early term in bci !\n");
	}
	echub_info("bci_soc_at_term =%d", di->bci_soc_at_term);

	di->ac_status_from_ec = of_property_read_bool(np, "ac_status_from_ec");
	di->report_ac_status_after_resume = of_property_read_bool(np, "report_ac_status_after_resume");
	if (get_ac_status_gpio(di))
		echub_err("get ac_status_gpio failed\n");

	g_mmi_test_interface_support = of_property_read_bool(np, "mmi_test_interface_support");

	/* bci_work_interval_para */
	array_len = of_property_count_strings(np, "bci_work_interval_para");
	if ((array_len <= 0) || (array_len % WORK_INTERVAL_PARA_TOTAL != 0)) {
		echub_err("bci_work_interval_para is invalid,please check iput number!!\n");
		return -EINVAL;
	}

	if (array_len > WORK_INTERVAL_PARA_LEVEL * WORK_INTERVAL_PARA_TOTAL) {
		echub_err("bci_work_interval_para is too long,use only front %d paras!!\n", array_len);
		return -EINVAL;
	}

	ret = memset_s(di->interval_data, sizeof(di->interval_data),
			0, WORK_INTERVAL_PARA_LEVEL * sizeof(struct work_interval_para));
	if (ret) {
		echub_err("memset_s failed\n");
		return -EINVAL;
	}

	ret = device_info_interval_data_init(di, array_len);
	if (ret)
		return ret;

	if (of_property_read_u32(np, "battery_info_type", (u32 *)&di->bat_info_type))
		di->bat_info_type = 1;

	parse_cap_dec_dts(di);
	ret |= parse_vth_correct_dts(di);
	return ret;
}

struct echub_batt_device_info *create_battery_device_info(struct platform_device *pdev, struct echub_i2c_dev *echub_dev)
{
	struct echub_batt_device_info *di = NULL;

	if (!pdev || !echub_dev)
		return NULL;

	di = devm_kzalloc(&pdev->dev, sizeof(struct echub_batt_device_info), GFP_KERNEL);
	if (!di)
		return NULL;

	di->monitoring_interval = WORK_INTERVAL_NOARMAL;
	di->dev = &pdev->dev;
	di->echub_dev = echub_dev;
	di->bat_health = POWER_SUPPLY_HEALTH_GOOD;
	di->bat_err = 0;
	di->power_supply_status = POWER_SUPPLY_HEALTH_GOOD;
	di->charge_status = POWER_SUPPLY_STATUS_NOT_CHARGING;
	di->ac_status_from_ec = false;
	di->report_ac_status_after_resume = false;

	get_battery_static_paras_from_ec(di);

	/* Battery is 4S1S or 2S2S */
	if (di->bat_volt_avg < BATTERY_2S_MAX) {
		echub_info("Battery is 2S\n");
		di->bat_volt_max_design = BATTERY_VOLTAGE_MAX_DESIGN_2S2P;
	} else if (di->bat_volt_avg < BATTERY_3S_MAX) {
		echub_info("Battery is 3S\n");
		di->bat_volt_max_design = BATTERY_VOLTAGE_MAX_DESIGN_4S1P;
	} else {
		echub_info("Battery is 4S\n");
		di->bat_volt_max_design = BATTERY_VOLTAGE_MAX_DESIGN_4S1P;
	}

	di->capacity = -1;
	di->capacity_filter_count = 0;
	di->charge_full_count = 0;
	di->wakeup_type_for_charger_control = 0;

	return di;
}

static ssize_t low_battery_thres_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (!buf || !g_echub_bat_dev) {
		echub_err("[%s:%dL] buf is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "low battery thres:%d\n", g_echub_bat_dev->low_battery_thres);
}

static ssize_t low_battery_thres_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	struct echub_batt_device_info *di = g_echub_bat_dev;
	int battery_thres = 0x0;

	if (!buf || !di) {
		echub_err("[%s:%dL] buf or di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	ret = kstrtouint(buf, 0, &battery_thres);
	if (ret < 0)
		return ret;

	if ((battery_thres < CAPACITY_MIN) || (battery_thres > CAPACITY_MAX)) {
		echub_err("battery_thres is invalid\n");
		return -EINVAL;
	}
	di->low_battery_thres = battery_thres;
	echub_info("low battery thres : %d\n", di->low_battery_thres);

	ret = di->echub_dev->write_func(di->echub_dev, SET_LOW_BATTERY_ADDR, di->low_battery_thres);
	if (ret) {
		echub_err("set low battery thres failed: %d\n", ret);
		return ret;
	}

	return count;
}
static DEVICE_ATTR(low_battery_thres, 0660, low_battery_thres_show, low_battery_thres_store);

static void echub_battery_update_wakeup_cause(void)
{
	int ret;
	char value[0x4] = {0};
	struct echub_batt_device_info *di = g_echub_bat_dev;
	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}
	ret = di->echub_dev->read_func(di->echub_dev, GET_WAKEUP_CAUSE_ADDR, 0x0, value, 0x4);
	if (ret) {
		echub_err("get wakeup cause failed %d\n", ret);
		return;
	}
	di->wakeup_cause = value[0x2];
	echub_info("wakeup cause %d\n", di->wakeup_cause);
}

static ssize_t wakeup_cause_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	echub_info("[%s] enter\n", __func__);
	bool ret = false;
	char wakeup_cause = 0x0;
	struct echub_batt_device_info *di = g_echub_bat_dev;
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

#ifdef CONFIG_SYS_PM_ULSR
    ret = is_ulsr();
#endif
    ret |= (di->wakeup_cause == 0x0);
	if (ret) {
		echub_battery_update_wakeup_cause();
	}
	wakeup_cause = di->wakeup_cause;
	di->wakeup_cause = 0x0;
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", wakeup_cause);
}
static DEVICE_ATTR(wakeup_cause, 0440, wakeup_cause_show, NULL);

static struct attribute *echub_battery_dev_attrs[] = {
	&dev_attr_low_battery_thres.attr,
	&dev_attr_wakeup_cause.attr,
	NULL,
};

static const struct attribute_group echub_battery_sysfs_attr_group = {
	.attrs = echub_battery_dev_attrs,
};

static void echub_pm_post_suspend(unsigned long event)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;

	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}

	echub_info("%s:+\n", __func__);
#ifdef CONFIG_HW_ECHUB_FLOAT_CHARGE
	if (di->charge_strategy == EC_SMART_CHARGE)
		queue_delayed_work(system_power_efficient_wq, &di->echub_smart_charge_work, 0);
#endif
	if (di->report_ac_status_after_resume)
		report_ac_status(di);
	queue_delayed_work(system_power_efficient_wq, &di->irq_work, 0);
#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
		queue_delayed_work(system_power_efficient_wq, &di->echub_batt_monitor_work, msecs_to_jiffies(1500)); // 1500ms
		return;
	}
#endif
	di->ignore_minor_data = true;
	if (event == PM_POST_HIBERNATION)
		di->sync_low_battery_thres = true;
	queue_delayed_work(system_power_efficient_wq, &di->echub_batt_monitor_work, 0);

	echub_info("%s:-\n", __func__);
}

static int echub_pm_notify_callback(struct notifier_block *nb, unsigned long event, void *ptr)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;

	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return NOTIFY_OK;
	}

	switch (event) {
	case PM_SUSPEND_PREPARE:
	case PM_HIBERNATION_PREPARE:
		echub_info("%s:+\n", __func__);
		cancel_delayed_work_sync(&di->irq_work);
		cancel_delayed_work_sync(&di->echub_batt_monitor_work);
#ifdef CONFIG_HW_ECHUB_FLOAT_CHARGE
		if (di->charge_strategy == EC_SMART_CHARGE)
			cancel_delayed_work_sync(&di->echub_smart_charge_work);
#endif
		echub_info("%s:-\n", __func__);
		break;
	case PM_POST_SUSPEND:
	case PM_POST_HIBERNATION:
		echub_pm_post_suspend(event);
		break;
	default:
		break;
	}
	return NOTIFY_OK;
}

static void echub_battery_work_init(void)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;
	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}
	INIT_DELAYED_WORK(&di->irq_work, echub_ac_irq_work);
	INIT_DELAYED_WORK(&di->echub_batt_monitor_work, echub_battery_work);
	queue_delayed_work(system_power_efficient_wq, &di->irq_work, 0);
	queue_delayed_work(system_power_efficient_wq, &di->echub_batt_monitor_work, 0);
}

static void echub_battery_soh_init(void)
{
	int ret = platform_device_register(&huawei_batt_soh_info);
	if (ret != 0) {
		echub_err("%s failed to register device\n");
		return;
	}

	ret = sysfs_create_group(&huawei_batt_soh_info.dev.kobj, &huawei_batt_soh_info_node);
	if (ret != 0) {
		echub_err("%s failed to create sysfs\n");
	}
}

#ifdef CONFIG_ARMPC_ECHUB_HMI
static struct notifier_block g_hmi_event_nb;

static int echub_battery_hmi_event_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	switch (event) {
	case QEVENT_BATTERY_HIGH_TEMP_STOP_CHG:
	case ACTIVE_DISCHARGE_REPORT_QEVENT:
		power_event_report_str_uevent("BMS_EVT=HIGH_TEMP_DISCHARGE");
		break;
	case QEVENT_BATTERY_NORMAL_TEMP_RE_CHG:
		power_event_report_str_uevent("BMS_EVT=HIGH_TEMP_RECHARGE");
		break;
	case AC_STATUS_CHANGE:
		echub_info("%s:ac status change", __func__);
		if (g_echub_bat_dev)
			mod_delayed_work(system_power_efficient_wq, &g_echub_bat_dev->irq_work, 0);
		break;
	case S_FAST_ADAPTER_POWER_CHANGE:
		echub_info("%s:ac power change", __func__);
		if (g_echub_bat_dev)
			mod_delayed_work(system_power_efficient_wq, &g_echub_bat_dev->echub_batt_monitor_work, 0);
		break;
	case QEVENT_BATT_DIAGNOSIS:
		echub_info("%s:battery diagnosis entry", __func__);
		if (g_echub_bat_dev)
			echub_battery_diagnosis_entry(g_echub_bat_dev);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}
#endif

static void create_mfg_sysfs(void)
{
#ifdef CONFIG_HW_ECHUB_SHIP_MODE
	echub_mfg_sysfs_create();
	if (g_mmi_test_interface_support)
		echub_mmi_interface_sysfs_create();
#endif
}

/* exit scp (example : 87.5% to 87%) */
static void echub_reset_capacity_fifo(struct echub_batt_device_info *di,
	int rep_soc, int round_soc, int base)
{
	int i;
	int remaing;

	for (i = 0; i < WINDOW_LEN; i++)
		capacity_filter[i] = (unsigned int)round_soc;

	di->capacity_filter_count = 0;
	capacity_sum = (unsigned int)(rep_soc * WINDOW_LEN / base);
	remaing = (int)capacity_sum - round_soc * WINDOW_LEN;

	for (i = 0; i < remaing; i++) {
		capacity_filter[i] += 1;
		di->capacity_filter_count = (unsigned int)i;
	}
}

void echub_capacity_sync_filter(int rep_soc, int round_soc, int base)
{
	struct echub_batt_device_info *di = g_echub_bat_dev;
	static int prev_soc = -1;

	if (!di) {
		echub_err("di is null\n");
		return;
	}

	if (base == 0) {
		echub_err("base is 0\n");
		return;
	}

	/* step1: reset capacity fifo */
	echub_reset_capacity_fifo(di, rep_soc, round_soc, base);

	/* step2: capacity changed (example: 86% to 87%) */
	if (prev_soc != round_soc) {
		echub_info("[%s] power supply changed, capacity %d, round_soc %d\n",
			__func__, di->capacity, round_soc);
		di->capacity = round_soc;
		di->prev_capacity = (unsigned int)round_soc;
		power_supply_changed(di->bat);
	}
	prev_soc = round_soc;
}

static void echub_battery_probe_init(struct platform_device *pdev, struct echub_batt_device_info *di)
{
	di->wakeup_cause = 0x0;
    device_enable_async_suspend(&pdev->dev);
	register_pm_notifier(&di->pm_nb);
	echub_battery_work_init();
	echub_battery_soh_init();
	echub_create_battery_strategy_sysfs();
	create_mfg_sysfs();
}

/**********************************************************
*  Function:       echub_battery_probe
*  Discription:    module probe
*  Parameters:     platform_device, i2c_device_id
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_battery_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct echub_batt_device_info *di = NULL;
	struct echub_i2c_dev *echub_dev = NULL;

	if (!pdev || !pdev->dev.parent) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form tmp\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			return -ENODEV;
		}
	}

	di = create_battery_device_info(pdev, echub_dev);
	if (!di)
		return -ENOMEM;

	g_echub_bat_dev = di;

	hrtimer_init(&di->capacity_dec_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);

	platform_set_drvdata(pdev, di);

	ret = echub_batt_parse_dts(di);
	if (ret)
		echub_err("battery parse dts failed, please check\n");

	di->bat = power_supply_register(&pdev->dev, &echub_battery_desc, &echub_battery_cfg);
	if (IS_ERR(di->bat)) {
		echub_info("failed to register main battery\n");
		goto batt_failed;
	}

	di->ac = power_supply_register(&pdev->dev, &echub_mains_desc, NULL);
	if (IS_ERR(di->ac)) {
		echub_info("failed to register ac power supply\n");
		goto ac_failed;
	}
	di->pm_nb.notifier_call = echub_pm_notify_callback;

	ret = sysfs_create_group(&pdev->dev.kobj, &echub_battery_sysfs_attr_group);
	if (ret < 0) {
		echub_info("register sysfs echub_battery failed\n");
		goto ac_failed;
	}
	echub_battery_probe_init(pdev, di);

	return 0;

ac_failed:
	power_supply_unregister(di->bat);
batt_failed:
	platform_set_drvdata(pdev, NULL);
	return ret;
}

static int echub_battery_remove(struct platform_device *pdev)
{
	struct echub_batt_device_info *di = NULL;

	pr_info("remove\n");
	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	unregister_pm_notifier(&di->pm_nb);
#ifdef CONFIG_HW_ECHUB_FLOAT_CHARGE
	echub_float_charge_exit();
#endif
#ifdef CONFIG_HW_ECHUB_TURBO_CHARGE
	echub_turbo_charge_remove_group(di->dev);
#endif
#ifdef CONFIG_HW_ECHUB_SHIP_MODE
    echub_mfg_sysfs_remove();
	if (g_mmi_test_interface_support)
		echub_mmi_interface_sysfs_remove();
#endif
	echub_basp_remove_group(di->dev);
	sysfs_remove_group(&pdev->dev.kobj, &echub_battery_sysfs_attr_group);
	cancel_delayed_work(&di->irq_work);
	cancel_delayed_work(&di->echub_batt_monitor_work);
	platform_device_unregister(&huawei_batt_soh_info);
	platform_set_drvdata(pdev, NULL);

	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int echub_battery_pm_suspend(struct device *dev)
{
#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
	    return 0;
	}
#endif
	echub_info("[%s] enter\n", __func__);
    struct echub_batt_device_info *di = g_echub_bat_dev;
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return 0;
	}
	di->wakeup_cause = 0x0;
	return 0;
}

static int echub_battery_pm_resume(struct device *dev)
{
    echub_info("[%s] enter\n", __func__);
    struct echub_batt_device_info *di = g_echub_bat_dev;
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return 0;
	}
#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
		di->wakeup_type_for_charger_control = WAKEUP_ULSR;
	    return 0;
	}
#endif
	di->wakeup_type_for_charger_control = WAKEUP_S3;
	echub_battery_update_wakeup_cause();
	return 0;
}

static int echub_battery_pm_freeze(struct device *dev)
{
    echub_info("[%s] enter\n", __func__);
    struct echub_batt_device_info *di = g_echub_bat_dev;
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return 0;
	}

	di->wakeup_type_for_charger_control = WAKEUP_S4;
	return 0;
}
#endif

static struct of_device_id echub_battery_match_table[] = {
	{ .compatible = "huawei,echub_battery", .data = NULL },
	{},
};

static const struct dev_pm_ops echub_battery_pm_ops = {
#ifdef CONFIG_PM_SLEEP
	.suspend = echub_battery_pm_suspend,
	.resume = echub_battery_pm_resume,
	.freeze = echub_battery_pm_freeze,
#endif
};

static struct platform_driver echub_battery_driver = {
	.probe = echub_battery_probe,
	.remove = echub_battery_remove,
	.driver = {
		   .name = "huawei,echub_battery",
		   .owner = THIS_MODULE,
		   .of_match_table = of_match_ptr(echub_battery_match_table),
		   .pm = &echub_battery_pm_ops,
		   },
};

static int __init echub_battery_init(void)
{
	return platform_driver_register(&echub_battery_driver);
}

module_init(echub_battery_init);

static int __init echub_battery_event_init(void)
{
#ifdef CONFIG_ARMPC_ECHUB_HMI
	g_hmi_event_nb.notifier_call = echub_battery_hmi_event_notifier_call;
	int ret = hmi_event_bnc_register(HMI_BATTERY_EVENT, &g_hmi_event_nb);
	if (ret)
		echub_err("%s: hmi event bnc register fail\n", __func__);
#endif
	return 0;
}
late_initcall(echub_battery_event_init);

static void __exit echub_battery_exit(void)
{
#ifdef CONFIG_ARMPC_ECHUB_HMI
	hmi_event_bnc_unregister(HMI_BATTERY_EVENT, &g_hmi_event_nb);
#endif
	platform_driver_unregister(&echub_battery_driver);
}

module_exit(echub_battery_exit);

MODULE_LICENSE("GPL");
MODULE_ALIAS("armpc echub_battery");
