/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2024. All rights reserved.
 */
#include <linux/platform_device.h>
#include <linux/timer.h>
#include <linux/err.h>
#include <linux/power_supply.h>
#include <linux/notifier.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <securec.h>
#include "echub_battery.h"
#include "ospm_printf.h"
#include "echub_i2c.h"

#define SMART_CHARGE_MONITOR_INTERVAL        (1000 * 60 * 10) // 10 min
#define INTERVAL_CNT_PER_HOUR                6
#define MONITOR_TRIGGER_NOW                  5
#define SMART_CHARGE_TRIGGER_TIME            72 // hours
#define ECHUB_CHARGE_RSOC_MAX           	 100
#define EC_I2C_READ_LEN                      8

enum ec_float_sysfs_type {
	FLOAT_CHARGE_STRATEGY,
	FLOAT_CHARGE_CONTROL,
};

static u16 g_ac_online_time; // hours
static bool g_user_resumed;
static bool g_is_reported;
static u8 g_monitor_cnt;

#ifdef CONFIG_SYSFS
static ssize_t ec_float_charge_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);
static ssize_t ec_float_charge_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info float_charge_sysfs_tbl[] = {
	power_sysfs_attr_rw(ec_float_charge, 0660, FLOAT_CHARGE_STRATEGY, strategy),
	power_sysfs_attr_rw(ec_float_charge, 0660, FLOAT_CHARGE_CONTROL, control),
};

static struct attribute *float_charge_sysfs_attrs[ARRAY_SIZE(float_charge_sysfs_tbl) + 1];

static const struct attribute_group float_charge_sysfs_attr_group = {
	.attrs = float_charge_sysfs_attrs,
};

static inline void smart_charge_start_monitor(void)
{
	struct echub_batt_device_info *di = echub_get_batt_di();
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}
	g_monitor_cnt = MONITOR_TRIGGER_NOW;
	mod_delayed_work(system_power_efficient_wq, &di->echub_smart_charge_work, 0);
}

static int smart_charge_battery_status_notify(struct notifier_block *nb,
				      unsigned long val, void *data)
{
	static int status = -1;
	struct power_supply *psy = data;
	struct echub_batt_device_info *di = echub_get_batt_di();
	union power_supply_propval propval;

	if (!psy || !di) {
		echub_err("%s psy or di is null\n", __func__);
		return NOTIFY_OK;
	}

	if ((val != PSY_EVENT_PROP_CHANGED) || (psy->desc->type != POWER_SUPPLY_TYPE_BATTERY))
		return NOTIFY_OK;

	if (power_supply_get_property(psy, POWER_SUPPLY_PROP_STATUS, &propval) != EOK) {
		echub_err("%s power_supply_get_property fail\n", __func__);
		return NOTIFY_OK;
	}

	if (di->ac_online && (di->charge_strategy == EC_SMART_CHARGE) &&
		(status == POWER_SUPPLY_STATUS_CHARGING) &&
		(propval.intval == POWER_SUPPLY_STATUS_NOT_CHARGING) &&
		(!g_user_resumed)) {
		g_is_reported = false;
		smart_charge_start_monitor();
	}
	status = propval.intval;

	return NOTIFY_OK;
}

static void echub_smart_charge_monitor_work(struct work_struct *work)
{
	u8 read_buf[EC_I2C_READ_LEN];
	int ret;
	struct echub_batt_device_info *di = echub_get_batt_di();

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s: di is null\n", __func__);
		return;
	}

	g_monitor_cnt++;
	if ((g_monitor_cnt % INTERVAL_CNT_PER_HOUR) != 0) {
		return;
	}
	g_monitor_cnt = 0;

	ret = di->echub_dev->transfer_func(di->echub_dev, 0x02E2, NULL, 0, read_buf, EC_I2C_READ_LEN);
	if (ret) {
		echub_err("%s get ac online time failed, ret=%d\n", __func__, ret);
		goto smart_charge_monitor_end;
	}
	g_ac_online_time = ((u16)read_buf[1] << 8) + read_buf[0]; // shift offset 8 bits
	echub_info("float chg online time: %d, reported:%d, stratery:%d\n",
		g_ac_online_time, g_is_reported, di->charge_strategy);
	if ((di->charge_strategy == EC_SMART_CHARGE) && (!g_is_reported) &&
		(g_ac_online_time >= SMART_CHARGE_TRIGGER_TIME)) {
		echub_info("send SMART CHARGE EVT\n");
		power_event_report_str_uevent("BMS_EVT=EC_SMART_CHARGE");
		g_is_reported = true;
	}

	ret = di->echub_dev->transfer_func(di->echub_dev, 0x02E6, NULL, 0, read_buf, 1);
	if (ret) {
		echub_err("%s get user resume flag failed, ret=%d\n", __func__, ret);
		goto smart_charge_monitor_end;
	}
	g_user_resumed = read_buf[0];

smart_charge_monitor_end:
	queue_delayed_work(system_power_efficient_wq, &di->echub_smart_charge_work,
		msecs_to_jiffies(SMART_CHARGE_MONITOR_INTERVAL));
}

static void echub_charge_control(u8 start_rsoc, u8 stop_rsoc)
{
	static int ret = 0;
	u8 write_buf[] = {0x01, 72, 65, 70};
	u8 resume_flag_disable = 0x00;
	static u8 last_strategy = 0xFF;
	static u8 last_start_rsoc = 0x00;
	static u8 last_stop_rsoc = 0x00;
	struct echub_batt_device_info *di = echub_get_batt_di();

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s: di is null\n", __func__);
		return;
	}

	if ((last_strategy != di->charge_strategy) || (last_start_rsoc != start_rsoc) ||
		(last_stop_rsoc != stop_rsoc) || ret) {
		last_strategy = di->charge_strategy;
		last_start_rsoc = start_rsoc;
		last_stop_rsoc = stop_rsoc;
	} else {
		if (di->wakeup_type_for_charger_control != 0) {
			di->wakeup_type_for_charger_control = 0;
		} else {
			echub_info("[%s] same data has reported, return!\n", __func__);
			return;
		}
	}

	if ((di->charge_strategy == EC_SMART_CHARGE) && (stop_rsoc == ECHUB_CHARGE_RSOC_MAX)) {
		ret = di->echub_dev->transfer_func(di->echub_dev, 0x02E5, write_buf, 1, NULL, 0);
		g_user_resumed = true;
		goto echub_charge_control_end;
	}

	if (di->charge_strategy == EC_SMART_CHARGE) {
		write_buf[0] = 0x04;
		smart_charge_start_monitor();
	} else {
		echub_info("[%s] charge mod is not smart, set resume_chg_flag to disable!\n", __func__);
		ret = di->echub_dev->transfer_func(di->echub_dev, 0x02E5, &resume_flag_disable, 1, NULL, 0);
		if (ret)
			echub_err("%s set resume_chg_flag to disable failed! i2c transfer failed, ret=%d\n", __func__, ret);
		g_is_reported = false;
		cancel_delayed_work(&di->echub_smart_charge_work);
		write_buf[2] = start_rsoc; // 2 start_rsoc data byte for i2c write
		write_buf[3] = stop_rsoc;  // 3 stop_rsoc data byte for i2c write
	}
	echub_err("[%s] mode: %d, rsoc %d ~ %d\n", __func__, write_buf[0], write_buf[NUM_2], write_buf[NUM_3]);
	ret = di->echub_dev->transfer_func(di->echub_dev, 0x02E3, write_buf, 4, NULL, 0); // 4 is write_buf size
echub_charge_control_end:
	if (ret) {
		echub_err("%s i2c transfer failed, ret=%d\n", __func__, ret);
	}
}

static ssize_t ec_float_charge_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	u8 strategy = 0;
	u8 start_rsoc;
	u8 stop_rsoc;
	struct power_sysfs_attr_info *info = NULL;
	struct echub_batt_device_info *di = echub_get_batt_di();

	if (!attr || !buf) {
		echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	info = power_sysfs_lookup_attr(attr->attr.name,
		float_charge_sysfs_tbl, ARRAY_SIZE(float_charge_sysfs_tbl));
	if (!info || !di) {
		echub_err("%s info is NULL\n", __func__);
		return -EINVAL;
	}
	echub_info("%s float chg info: %d, %s\n", __func__, info->name, buf);
	switch (info->name) {
	case FLOAT_CHARGE_STRATEGY:
		if (sscanf_s(buf, "hidl %d", &strategy) != 1) {
			echub_err("%s incorrect strategy format\n", __func__);
			return -EINVAL;
		}
		if (strategy > EC_SMART_CHARGE) {
			echub_err("%s incorrect strategy param\n", __func__);
			return -EINVAL;
		}
		di->charge_strategy = strategy;
		break;
	case FLOAT_CHARGE_CONTROL:
		if (sscanf_s(buf, "hidl %d %d %d", &strategy, &start_rsoc, &stop_rsoc) != 3) { // scanf 3 paras from buf
			echub_err("%s incorrect control format\n", __func__);
			return -EINVAL;
		}
		if ((strategy > EC_SMART_CHARGE) || (start_rsoc >= stop_rsoc) || (stop_rsoc > ECHUB_CHARGE_RSOC_MAX)) {
			echub_err("%s incorrect control param\n", __func__);
			return -EINVAL;
		}
		echub_charge_control(start_rsoc, stop_rsoc);
		break;
	default:
		echub_warn("%s unknown para: %d", __func__, info->name);
	}

	return count;
}

static ssize_t ec_float_charge_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct echub_batt_device_info *di = echub_get_batt_di();
	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s di is NULL\n", __func__);
		return -EINVAL;
	}
	return 0;
}

static struct notifier_block smart_charge_notifier = {
	.notifier_call = smart_charge_battery_status_notify,
};

void echub_float_charge_init(struct device *dev)
{
	struct echub_batt_device_info *di = echub_get_batt_di();

	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}
	power_sysfs_init_attrs(float_charge_sysfs_attrs,
		float_charge_sysfs_tbl, ARRAY_SIZE(float_charge_sysfs_tbl));
	power_sysfs_create_group("hw_power", "soc_control", &float_charge_sysfs_attr_group);
	if (power_supply_reg_notifier(&smart_charge_notifier) != EOK) {
		echub_err("%s smart_charge_notifier reg failed\n", __func__);
	}

	INIT_DELAYED_WORK(&di->echub_smart_charge_work, echub_smart_charge_monitor_work);
}

void echub_float_charge_exit(void)
{
	struct echub_batt_device_info *di = echub_get_batt_di();
	struct device* dev = power_sysfs_get_device("hw_power", "soc_control");

	if (!di || !dev) {
		echub_err("%s: di or dev is null\n", __func__);
		return;
	}
	power_sysfs_remove_group(dev, &float_charge_sysfs_attr_group);
	cancel_delayed_work(&di->echub_smart_charge_work);
}
#else
void echub_float_charge_init(struct device *dev)
{
}

void echub_float_charge_exit(void)
{
}
#endif