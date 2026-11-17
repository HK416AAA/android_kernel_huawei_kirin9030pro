/*
 * echub_fan.c
 *
 * fan driver for echub
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
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
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/err.h>
#include <linux/workqueue.h>
#include <linux/pwm.h>
#include "ospm_printf.h"
#include "echub_i2c.h"
#include "echub_thermal.h"

#define FAN_FULL_SPEED_MODE				1
#define FAN_FULL_SPEED_DUTY				100
#define FAN_PWM_PERIOD					40000 // unit us, is equivalent to 25K HZ
#define MAX_FAN_GEAR_SIZE				8
#define MAX_TEMP_TRRIGER_SIZE				((MAX_FAN_GEAR_SIZE - 1) * MAX_TEMP_SIZE)

// key -- pwm duty, value -- speed rpm
struct key_value_pair g_rpm_to_duty[] = {
	{0, 0}, {12, 188}, {16, 324}, {28, 752}, {36, 1029},
	{45, 1337}, {50, 1507}, {60, 1849}, {68, 2118},
	{76, 2391}, {84, 2664}, {92, 2800}, {100, 3202},
};

struct echub_fan_device_info {
	struct device *dev;
	struct echub_i2c_dev *echub_dev;
	struct pwm_device *pwm_dev;
	struct delayed_work fan_speed_regulate_work;
	struct mutex lock;
	int fan_idx;
	int p_fan_gear[MAX_FAN_GEAR_SIZE];
	u8 fan_gear_size;
	struct key_value_pair *p_rpm_to_duty;
	u8 size_rpm_to_duty;
	struct temp_trigger_fallback *p_fan_temp_info;
	u8 size_fan_temp_info;
	struct temp_trigger_fallback p_fan_temp_table1[MAX_TEMP_TRRIGER_SIZE];
	int time_to_trigger;
	u8 is_support_temp_table2;
	u8 curr_table;
	bool table_changed;
	struct temp_trigger_fallback switch_table2_conds;
	struct temp_trigger_fallback p_fan_temp_table2[MAX_TEMP_TRRIGER_SIZE];
	int filter_coefficient;
	int curr_temp[MAX_TEMP_ID];
	int trigger_gear_count[MAX_TEMP_ID];
	int fallback_gear_count[MAX_TEMP_ID];
	u8 curr_gear;
	bool gear_changed;
	int set_to_duty;
	int curr_speed;
	int dest_speed;
	bool dest_changed;
	int fan_mode;
	int test_speed;
	bool test_changed;
	u8 is_fan_test_mode;
	u8 is_mfg_mode;
};

struct echub_fan_device_info *g_echub_fan_dev = NULL;

static ssize_t echub_fan_speed_show(struct device *dev,
	struct device_attribute *attr, char *buf);

static ssize_t echub_fan_mode_show(struct device *dev,
	struct device_attribute *attr, char *buf);

static ssize_t echub_fan_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static DEVICE_ATTR(echub_fan_speed, S_IRUGO, echub_fan_speed_show, NULL);
static DEVICE_ATTR(echub_fan_mode, S_IWUSR | S_IRUGO, echub_fan_mode_show,
	echub_fan_mode_store);

static struct device_attribute *echub_fan_dev_attrs[] = {
	&dev_attr_echub_fan_speed,
	&dev_attr_echub_fan_mode,
	NULL,
};

static struct echub_fan_device_info *echub_fan_device_get(void)
{
	if (!g_echub_fan_dev) {
		echub_err("g_echub_fan_dev not init\n");
		return NULL;
	}

	return g_echub_fan_dev;
}

static int echub_fan_filter_temp_calc(int curr_temp, int filter_temp, u8 filter_coeff)
{
	int new_temp = INVALID_VALUE;
	if (curr_temp == INVALID_VALUE || filter_coeff > 100) { // filter_coeff max 100
		echub_err("%s para curr_temp %d or filter_coeff %d out of range\n", __func__, curr_temp, filter_coeff);
		return INVALID_VALUE;
	}
	if (filter_temp == INVALID_VALUE)
		new_temp = curr_temp;
	else
		new_temp = (filter_temp * filter_coeff + curr_temp * (NUM_100 - filter_coeff)) / NUM_100;

	return new_temp;
}

static struct temp_trigger_fallback *echub_fan_temp_table_get(void)
{
	int i, temp_id;
	int curr_temp = INVALID_VALUE;
	static int trigger_table_count = 0;
	static int fallback_table_count = 0;
	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL)
		return NULL;

	if (di->is_support_temp_table2 == 0)
		return di->p_fan_temp_table1;

	temp_id = di->switch_table2_conds.temp_id;
	curr_temp = temp_virtual_celsius_get(temp_id);
	if (curr_temp >= di->switch_table2_conds.temp_trigger) {
		trigger_table_count += 1;
		fallback_table_count = 0;
	} else if (curr_temp < di->switch_table2_conds.temp_fallback) {
		trigger_table_count = 0;
		fallback_table_count += 1;
	}

	if ((trigger_table_count >= di->time_to_trigger) && (di->curr_table != 1)) {
		di->curr_table = 1;
		di->table_changed = true;
		di->p_fan_temp_info = di->p_fan_temp_table2;
		echub_info("%s temp table switch to table2", __func__);
	} else if ((fallback_table_count >= di->time_to_trigger) && (di->curr_table != 0)) {
		di->curr_table = 0;
		di->table_changed = true;
		di->p_fan_temp_info = di->p_fan_temp_table1;
		echub_info("%s temp table switch to table1", __func__);
	} else {
		return di->p_fan_temp_info;
	}

	if (di->table_changed) {
		for (i = 0; i < MAX_TEMP_ID; ++i) {
			di->trigger_gear_count[i] = 0;
			di->fallback_gear_count[i] = 0;
		}
	}
	return di->p_fan_temp_info;
}

static int echub_fan_gear_calc(void)
{
	int i, temp_id;
	int trigger_temp_count = 0;
	int fallback_temp_count = 0;
	int curr_temp = INVALID_VALUE;
	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL)
		return -EINVAL;

	for (i = 0; i < di->size_fan_temp_info; i += di->fan_gear_size - 1) {
		temp_id = di->p_fan_temp_info[i].temp_id;
		curr_temp = temp_virtual_celsius_get(temp_id);
		if (temp_id == CPU_DTS_ID)
			di->curr_temp[temp_id] = echub_fan_filter_temp_calc(curr_temp, di->curr_temp[temp_id], di->filter_coefficient);
		else if (temp_id < MAX_TEMP_ID)
			di->curr_temp[temp_id] = curr_temp;

		if ((di->curr_gear < di->fan_gear_size - 1) && (i + di->curr_gear < di->size_fan_temp_info) &&
			(di->curr_temp[temp_id] >= di->p_fan_temp_info[i + di->curr_gear].temp_trigger)) {
			di->trigger_gear_count[temp_id] += 1;
			di->fallback_gear_count[temp_id] = 0;
		} else if ((di->curr_gear > 0) && (i + di->curr_gear - 1 < di->size_fan_temp_info) &&
			(di->curr_temp[temp_id] < di->p_fan_temp_info[i + di->curr_gear - 1].temp_fallback)) {
			di->trigger_gear_count[temp_id] = 0;
			di->fallback_gear_count[temp_id] += 1;
		}
		if (di->trigger_gear_count[temp_id] >= di->time_to_trigger)
			++trigger_temp_count;
		else if (di->fallback_gear_count[temp_id] >= di->time_to_trigger)
			++fallback_temp_count;
	}
	if ((trigger_temp_count > 0) || (fallback_temp_count >= di->size_fan_temp_info / (di->fan_gear_size - 1))) {
		for (i = 0; i < di->size_fan_temp_info; i += di->fan_gear_size - 1) {
			temp_id = di->p_fan_temp_info[i].temp_id;
			di->trigger_gear_count[temp_id] = 0;
			di->fallback_gear_count[temp_id] = 0;
			echub_info("%s temp id %d value %d.%d", __func__, temp_id,
				di->curr_temp[temp_id] / DECIMAL_MAGNIFICATION, di->curr_temp[temp_id] % DECIMAL_MAGNIFICATION);
		}
		if ((trigger_temp_count > 0) && (di->curr_gear < di->fan_gear_size - 1))
			di->curr_gear += 1;
		else if ((fallback_temp_count >= di->size_fan_temp_info / (di->fan_gear_size - 1)) && (di->curr_gear > 0))
			di->curr_gear -= 1;

		di->gear_changed = true;
		echub_info("%s curr_gear %d trigger_temp_count = %d fallback_temp_count = %d",
			__func__, di->curr_gear, trigger_temp_count, fallback_temp_count);
	}
	return di->curr_gear;
}

static int echub_fan_rpm2pwm(int speed_rpm)
{
	int i;
	int duty = 0;
	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL) {
		echub_err("%s echub_fan_device_info is NULL return\n", __func__);
		return -EINVAL;
	}
	if (speed_rpm > di->p_rpm_to_duty[di->size_rpm_to_duty - 1].value)
		speed_rpm = di->p_rpm_to_duty[di->size_rpm_to_duty - 1].value;
	else if (speed_rpm < di->p_rpm_to_duty[0].value)
		speed_rpm = di->p_rpm_to_duty[0].value;

	for (i = 0; i < di->size_rpm_to_duty - 1; ++i) {
		if (speed_rpm < di->p_rpm_to_duty[i + 1].value) {
			duty = di->p_rpm_to_duty[i].key + (speed_rpm - di->p_rpm_to_duty[i].value) *
				(di->p_rpm_to_duty[i + 1].key - di->p_rpm_to_duty[i].key) /
				(di->p_rpm_to_duty[i + 1].value - di->p_rpm_to_duty[i].value);
			break;
		}
	}
	return duty;
}

static int echub_fan_speed_get(u8 fan_id)
{
	int ret = 0;
	char value[5] = {0};

	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL || fan_id >= MAX_FAN_ID) {
		echub_err("%s echub_fan_device_info is NULL or fan id %d out of range\n", __func__, fan_id);
		return -EINVAL;
	}

	// get fan speed
	switch (fan_id) {
	case FAN_0:
		ret = di->echub_dev->read_func(di->echub_dev, FAN0_SPEED_REG, 0, value, sizeof(value) / sizeof(char));
		break;
	case FAN_1:
		ret = di->echub_dev->read_func(di->echub_dev, FAN1_SPEED_REG, 0, value, sizeof(value) / sizeof(char));
		break;
	default:
		break;
	}
	if (ret) {
		echub_err("get fan id %d speed failed %d\n", fan_id, ret);
		return -EINVAL;
	}
	di->curr_speed = (u16)(value[NUM_2] << NUM_8) + value[NUM_3];

	return di->curr_speed;
}

static int echub_fan_speed_set(int pwm_duty, int pwm_period)
{
	int ret;
	struct pwm_state state;

	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL || pwm_duty > FAN_FULL_SPEED_DUTY) {
		echub_err("%s echub_fan_device_info is NULL or pwm_duty %d out of range\n", __func__, pwm_duty);
		return -EINVAL;
	}

	state.period = pwm_period;
	state.duty_cycle = pwm_duty * state.period / FAN_FULL_SPEED_DUTY;
	state.polarity = PWM_POLARITY_NORMAL;
	state.enabled = true;
	ret = pwm_apply_state(di->pwm_dev, &state);
	if (ret) {
		echub_err("%s pwm_apply_state %d failed", __func__, ret);
		return -EINVAL;
	}
	return 0;
}

static int echub_fan_dest_speed_calc(struct echub_fan_device_info *di)
{
	di->is_mfg_mode = mfg_test_mode_get();
	if (di->is_mfg_mode == 0x0)
		di->is_fan_test_mode = 0x0;

	if (di->is_fan_test_mode == 0x0) {
		di->p_fan_temp_info = echub_fan_temp_table_get();
		if (di->p_fan_temp_info)
			di->curr_gear = echub_fan_gear_calc();

		if (di->gear_changed && di->curr_gear >= 0 && di->curr_gear < di->fan_gear_size) {
			di->gear_changed = false;
			di->dest_speed = di->p_fan_gear[di->curr_gear];
			di->dest_changed = true;
		}
	} else {
		if (di->test_changed) {
			di->test_changed = false;
			di->dest_speed = di->test_speed;
			di->dest_changed = true;
		}
	}

	return di->dest_speed;
}

static void echub_fan_work(struct work_struct *work)
{
	int step = 0;
	struct echub_fan_device_info *di = container_of(work, struct echub_fan_device_info, fan_speed_regulate_work.work);
	if (di == NULL) {
		echub_err("%s echub_fan_device_info is NULL return\n", __func__);
		return;
	}

	di->dest_speed = echub_fan_dest_speed_calc(di);
	di->curr_speed = echub_fan_speed_get(di->fan_idx);

	if (di->curr_speed < 0 || di->dest_changed) {
		di->set_to_duty = echub_fan_rpm2pwm(di->dest_speed);
		di->dest_changed = false;
		echub_info("%s curr gear %d, curr speed %d, set to duty %d, dest speed %d, test mode %d",
			__func__, di->curr_gear, di->curr_speed, di->set_to_duty, di->dest_speed, di->is_fan_test_mode);
	} else if (abs(di->dest_speed - di->curr_speed) >= FAN_SPEED_ACCURACY) {
		step = (di->dest_speed - di->curr_speed) / FAN_SPEED_ACCURACY;
		if (di->set_to_duty + step > di->p_rpm_to_duty[0].key &&
			di->set_to_duty + step < di->p_rpm_to_duty[di->size_rpm_to_duty - 1].key)
			di->set_to_duty += step;
		echub_info("%s curr speed %d, set to duty %d, dest speed %d, step %d",
			__func__, di->curr_speed, di->set_to_duty, di->dest_speed, step);
	}

	if (di->fan_mode == FAN_FULL_SPEED_MODE)
		echub_fan_speed_set(FAN_FULL_SPEED_DUTY, FAN_PWM_PERIOD);
	else
		echub_fan_speed_set(di->set_to_duty, FAN_PWM_PERIOD);

	schedule_delayed_work(&di->fan_speed_regulate_work, msecs_to_jiffies(FAN_WORK_SCHEDULE_PERIOD));
}

static ssize_t echub_fan_speed_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = NULL;
	struct echub_fan_device_info *di = NULL;

	if (!dev || !buf) {
		echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	pdev = to_platform_device(dev);
	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}

	if (di->curr_speed < 0)
		echub_err("%s Failed to read curr speed %d from the MCU", __func__, di->curr_speed);

	return scnprintf(buf, PAGE_SIZE, "%d\n", di->curr_speed);
}

static ssize_t echub_fan_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev = NULL;
	struct echub_fan_device_info *di = NULL;

	if (!dev || !buf) {
		echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	pdev = to_platform_device(dev);
	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	return scnprintf(buf, PAGE_SIZE, "%d\n", di->fan_mode);
}

static ssize_t echub_fan_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret, val;
	struct platform_device *pdev = NULL;
	struct echub_fan_device_info *di = NULL;

	if (!dev || !buf) {
		echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	pdev = to_platform_device(dev);
	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}

	ret = kstrtoint(buf, 0, &val);
	if (ret < 0)
		return ret;

	di->fan_mode = val;

	return count;
}

static void echub_fan_sysfs_create(struct platform_device *pdev)
{
	int i, ret;

	for (i = 0; i < ARRAY_SIZE(echub_fan_dev_attrs); i++) {
		if (!echub_fan_dev_attrs[i])
			break;
		ret = device_create_file(&pdev->dev, echub_fan_dev_attrs[i]);
		if (ret)
			echub_err("%s sys device file create failed, ret %d", __func__, ret);
	}

	return;
}

static int echub_fan_parameter_init(struct echub_fan_device_info *di)
{
	int i;
	if (di == NULL) {
		echub_err("echub_fan_device_info is NULL return\n");
		return -ENOMEM;
	}
	di->p_rpm_to_duty = g_rpm_to_duty;
	di->size_rpm_to_duty = sizeof(g_rpm_to_duty) / sizeof(struct key_value_pair);
	di->p_fan_temp_info = di->p_fan_temp_table1;
	di->filter_coefficient = TEMP_FILTER_COEFFICIENT;
	di->time_to_trigger = CONTINUOUS_TRIGGER_TIME;
	di->is_support_temp_table2 = 0;
	di->curr_table = 0;
	di->table_changed = false;
	di->curr_gear = 0;
	di->gear_changed = false;
	di->set_to_duty = 0;
	di->curr_speed = 0;
	di->dest_speed = 0;
	di->dest_changed = false;
	di->fan_mode = 0;
	di->test_speed = 0;
	di->test_changed = false;
	for (i = 0; i < MAX_TEMP_ID; ++i) {
		di->curr_temp[i] = INVALID_VALUE;
		di->trigger_gear_count[i] = 0;
		di->fallback_gear_count[i] = 0;
	}
	di->is_fan_test_mode = 0x0;
	di->is_mfg_mode = 0x0;

	return 0;
}

static int echub_fan_temp_info_parse(struct echub_fan_device_info *di,
	struct temp_trigger_fallback *table, const char *prop)
{
	int i, len, tmp_data;
	const char *tmp_str = NULL;
	struct device_node *np = di->dev->of_node;

	len = of_property_count_strings(np, prop);
	if ((len <= 0) || (len % TEMP_PARA_IDX_SIZE != 0) ||
		(len > (TEMP_PARA_IDX_SIZE * MAX_TEMP_TRRIGER_SIZE)) ||
		((strncmp(prop, "switch_table2_conds", strlen(prop)) != 0) &&
		(len % (TEMP_PARA_IDX_SIZE * (di->fan_gear_size - 1)) != 0))) {
		echub_err("prop %s length read fail\n", prop);
		return -EINVAL;
	}
	if (strncmp(prop, "temp_trigger_fallback_table1", strlen(prop)) == 0)
		di->size_fan_temp_info = len / TEMP_PARA_IDX_SIZE;
	echub_info("%s prop %s len %d, size_fan_temp_info %d \n", __func__, prop, len, di->size_fan_temp_info);

	for (i = 0; i < len; i++) {
		if (of_property_read_string_index(np, prop, i, &tmp_str)) {
			echub_err("prop %s[%d] read fail\n", prop, i);
			return -EINVAL;
		}
		if (kstrtoint(tmp_str, 0, &tmp_data))
			return -EINVAL;

		switch (i % TEMP_PARA_IDX_SIZE) {
		case TEMPID_IDX:
			table[i / TEMP_PARA_IDX_SIZE].temp_id = tmp_data;
			break;
		case TRIGGER_IDX:
			table[i / TEMP_PARA_IDX_SIZE].temp_trigger = tmp_data;
			break;
		case FALLBACK_IDX:
			table[i / TEMP_PARA_IDX_SIZE].temp_fallback = tmp_data;
			break;
		default:
			break;
		}
	}
	return 0;
}

static int echub_fan_parse_dt(struct echub_fan_device_info *di)
{
	int i, ret, len, tmp_data;
	const char *tmp_str = NULL;
	struct device_node *np = di->dev->of_node;

	if (of_property_read_u32(np, "fan_idx", &di->fan_idx))
		echub_err("Get fan_idx from DTS failed!\n");
	else
		echub_info("Get fan_idx = %d from DTS!\n", di->fan_idx);

	if (of_property_read_u32(np, "time_to_trigger", &di->time_to_trigger))
		echub_err("Get time_to_trigger from DTS failed!\n");
	else
		echub_info("Get time_to_trigger = %d from DTS!\n", di->time_to_trigger);

	if (of_property_read_u32(np, "filter_coefficient", &di->filter_coefficient))
		echub_err("Get filter_coefficient from DTS failed!\n");
	else
		echub_info("Get filter_coefficient = %d from DTS!\n", di->filter_coefficient);

	len = of_property_count_strings(np, "fan_gear_table");
	if ((len <= 0) || (len > MAX_FAN_GEAR_SIZE)) {
		echub_err("prop %s length read fail\n", "fan_gear_table");
		return -EINVAL;
	}
	di->fan_gear_size = len;
	for (i = 0; i < len; i++) {
		if (of_property_read_string_index(np, "fan_gear_table", i, &tmp_str)) {
			echub_err("prop %s[%d] read fail\n", "fan_gear_table", i);
			return -EINVAL;
		}
		if (kstrtoint(tmp_str, 0, &tmp_data))
			return -EINVAL;
		di->p_fan_gear[i] = tmp_data;
	}

	ret = echub_fan_temp_info_parse(di, di->p_fan_temp_table1, "temp_trigger_fallback_table1");
	if (ret != 0)
		echub_err("Get temp_trigger_fallback_table1 from DTS failed!\n");

	len = of_property_count_strings(np, "switch_table2_conds");
	if (len != TEMP_PARA_IDX_SIZE) {
		echub_err("prop %s len %d read error from DTS!\n", "switch_table2_conds", len);
		return ret;
	}

	di->is_support_temp_table2 = 0x1;
	ret = echub_fan_temp_info_parse(di, &di->switch_table2_conds, "switch_table2_conds");
	if (ret != 0)
		echub_err("Get switch_table2_conds from DTS failed!\n");
	ret = echub_fan_temp_info_parse(di, di->p_fan_temp_table2, "temp_trigger_fallback_table2");
	if (ret != 0)
		echub_err("Get switch_table2_conds from DTS failed!\n");

	return ret;
}

/**********************************************************
*  Function:       echub_fan_probe
*  Discription:    module probe
*  Parameters:     platform_device, i2c_device_id
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_fan_probe(struct platform_device *pdev)
{
	struct echub_fan_device_info *di = NULL;
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
			echub_err("echub_dev is NULL return\n");
			return -ENODEV;
		}
	}

	echub_info("echub_fan Probe start\n");

	di = devm_kzalloc(&pdev->dev, sizeof(struct echub_fan_device_info), GFP_KERNEL);
	if (!di) {
		echub_err("echub_fan_device kzalloc is null return\n");
		return -ENOMEM;
	}

	di->pwm_dev = devm_pwm_get(&pdev->dev, NULL);
	if (di->pwm_dev == NULL) {
		echub_err("%s devm_pwm_get failed", __func__);
		return -EINVAL;
	}

	di->dev = &pdev->dev;
	di->echub_dev = echub_dev;
	echub_fan_parameter_init(di);

	platform_set_drvdata(pdev, di);
	if (echub_fan_parse_dt(di) < 0) {
		echub_err("%s dts parse failed", __func__);
		return -EINVAL;
	}
	mutex_init(&di->lock);
	g_echub_fan_dev = di;
	echub_fan_sysfs_create(pdev);

	INIT_DELAYED_WORK(&di->fan_speed_regulate_work, echub_fan_work);
	schedule_delayed_work(&di->fan_speed_regulate_work, msecs_to_jiffies(10)); // delay 10 ms

	echub_info("echub_fan probe ok!\n");

	return 0;
}

static int echub_fan_remove(struct platform_device *pdev)
{
	int i;
	struct echub_fan_device_info *di = NULL;

	pr_info("remove\n");
	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL!\n", __func__, __LINE__);
		return -ENODEV;
	}

	for (i = 0; i < ARRAY_SIZE(echub_fan_dev_attrs); i++) {
		if (!echub_fan_dev_attrs[i])
			break;
		device_remove_file(&pdev->dev, echub_fan_dev_attrs[i]);
	}
	cancel_delayed_work(&di->fan_speed_regulate_work);
	platform_set_drvdata(pdev, NULL);
	mutex_destroy(&di->lock);
	g_echub_fan_dev = NULL;
	di = NULL;

	return 0;
}

static int echub_fan_pm_suspend(struct device *dev)
{
	struct platform_device *pdev = NULL;
	struct echub_fan_device_info *di = NULL;

	if (!dev) {
		echub_err("[%s:%dL] dev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	pdev = to_platform_device(dev);
	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL!\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_info("%s:+\n", __func__);
	echub_fan_speed_set(0, FAN_PWM_PERIOD);
	cancel_delayed_work(&di->fan_speed_regulate_work);
	echub_info("%s:-\n", __func__);
	return 0;
}

static int echub_fan_pm_resume(struct device *dev)
{
	struct platform_device *pdev = NULL;
	struct echub_fan_device_info *di = NULL;

	if (!dev) {
		echub_err("[%s:%dL] dev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	pdev = to_platform_device(dev);
	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL!\n", __func__, __LINE__);
		return -ENODEV;
	}

	echub_info("%s:+\n", __func__);
	echub_fan_parameter_init(di);
	schedule_delayed_work(&di->fan_speed_regulate_work, msecs_to_jiffies(0));
	echub_info("%s:-\n", __func__);
	return 0;
}

static const struct dev_pm_ops echub_fan_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(echub_fan_pm_suspend, echub_fan_pm_resume)
};

static struct of_device_id echub_fan_match_table[] = {
	{ .compatible = "huawei,echub_fan0", .data = NULL },
	{},
};

static struct platform_driver echub_fan_driver = {
	.probe = echub_fan_probe,
	.remove = echub_fan_remove,
	.driver = {
		   .name = "huawei,echub_fan",
		   .owner = THIS_MODULE,
		   .pm = &echub_fan_pm_ops,
		   .of_match_table = of_match_ptr(echub_fan_match_table),
		   },
};

int fan_test_speed_get(u8 fan_id)
{
	int curr_speed;
	if (fan_id >= MAX_FAN_ID) {
		echub_err("%s fan id %d out of range \n", __func__, fan_id);
		return -EINVAL;
	}
	curr_speed = echub_fan_speed_get(fan_id);
	echub_info("%s get fan id %d, speed %d", __func__, fan_id, curr_speed);
	return curr_speed;
}

#ifdef CONFIG_THERMAL_DEVICE_INTERFACE
u8 fan_test_mode_get(void)
{
	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL)
		return -EINVAL;

	echub_info("%s get fan mode %d", __func__, di->is_fan_test_mode);
	return di->is_fan_test_mode;
}

int fan_test_mode_set(u8 mode)
{
	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL)
		return -EINVAL;

	if (di->is_mfg_mode == 0x0) {
		echub_err("%s mfg mode is closed, fan test mode is not supported!\n", __func__);
		return -EINVAL;
	}
	di->is_fan_test_mode = mode;
	di->gear_changed = true;
	echub_info("%s set fan mode %d", __func__, di->is_fan_test_mode);
	return 0;
}

int fan_test_speed_set(u8 fan_id, int set_speed)
{
	struct echub_fan_device_info *di = echub_fan_device_get();
	if (di == NULL)
		return -EINVAL;

	if (di->is_fan_test_mode == 0x0) {
		echub_err("%s fan test mode is closed, set fan speed failed \n", __func__);
		return -EINVAL;
	}
	if (fan_id >= MAX_FAN_ID) {
		echub_err("%s fan id %d or speed rpm %d out of range \n", __func__, fan_id, set_speed);
		return -EINVAL;
	}

	if (abs(di->dest_speed - set_speed) >= FAN_SPEED_ACCURACY) {
		mutex_lock(&di->lock);
		di->test_speed = set_speed;
		di->test_changed = true;
		mutex_unlock(&di->lock);
	}
	echub_info("set fan id %d speed %d", fan_id, set_speed);
	return 0;
}
#endif

static int __init echub_fan_init(void)
{
	int ret;

	echub_info("%s enter\n", __func__);
	ret = platform_driver_register(&echub_fan_driver);
	if (ret)
		echub_err("echub_fan_driver platform driver register err\n");

	return ret;
}

late_initcall(echub_fan_init);

static void __exit echub_fan_exit(void)
{
	echub_info("%s enter\n", __func__);
	platform_driver_unregister(&echub_fan_driver);
}

module_exit(echub_fan_exit);

MODULE_LICENSE("GPL");
MODULE_ALIAS("armpc echub_fan");
