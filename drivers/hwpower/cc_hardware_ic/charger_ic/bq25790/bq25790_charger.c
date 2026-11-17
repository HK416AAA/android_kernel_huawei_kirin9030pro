// SPDX-License-Identifier: GPL-2.0+
/*
 * bq25790_charger.c
 *
 * bq25790 driver
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

#include "bq25790_charger.h"
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/power/huawei_charger.h>
#include <huawei_platform/power/series_batt_charger.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_ic.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_device_id.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_pd.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG bq25790_charger
HWLOG_REGIST();

static struct bq25790_device_info *g_bq25790_dev;

#define BUF_LEN                       26
#define RETRY_MAX3                    3
#define DEFAULT_SC_MAX_INPUT_CURRENT  2200
#define DEFAULT_SC_MAX_CHARGE_CURRENT 4000
#define DEFAULT_LVC_MAX_INPUT_CURRENT 3000
#define DEFAULT_LVC_MAX_CHARGE_CURRENT 5000

static int bq25790_write_byte(u8 reg, u8 value)
{
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di)
		return -ENODEV;

	return power_i2c_u8_write_byte(di->client, reg, value);
}

static int bq25790_read_byte(u8 reg, u8 *value)
{
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di)
		return -ENODEV;

	return power_i2c_u8_read_byte(di->client, reg, value);
}

static int bq25790_read_block(u8 reg, u8 *data, unsigned int data_len)
{
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di)
		return -ENODEV;

	return power_i2c_read_block(di->client, &reg, 1, data, data_len);
}

static int bq25790_write_word(u8 reg, u16 value)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	u8 buf[BQ25790_WORD_WR_LEN] = { 0 };

	if (!di)
		return -ENODEV;
	/*
	 * big endian
	 * buf[0]: 8bit slave register address
	 * buf[1]: high-8bit data to be written
	 * buf[2]: low-8bit data to be written
	 */
	buf[0] = reg;
	buf[1] = value >> 8;
	buf[2] = value & 0xff;

	return power_i2c_write_block(di->client, buf, sizeof(buf));
}

static int bq25790_read_word(u8 reg, u16 *value)
{
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di)
		return -ENODEV;

	return power_i2c_u8_read_word(di->client, reg, value, true);
}

static int bq25790_write_mask(u8 reg, u8 mask, u8 shift, u8 value)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	int ret;

	if (!di)
		return -ENODEV;

	mutex_lock(&di->io_lock);
	ret = power_i2c_u8_write_byte_mask(di->client,
		reg, value, mask, shift);
	mutex_unlock(&di->io_lock);

	return ret;
}

static int bq25790_read_mask(u8 reg, u8 mask, u8 shift, u8 *value)
{
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di || !value)
		return -ENODEV;

	return power_i2c_u8_read_byte_mask(di->client,
		reg, value, mask, shift);
}

static int bq25790_write_word_mask(u8 reg, u16 mask, u16 shift, u16 value)
{
	int ret;
	u16 data = 0;
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di)
		return -ENODEV;

	mutex_lock(&di->io_lock);
	ret = bq25790_read_word(reg, &data);
	if (ret) {
		mutex_unlock(&di->io_lock);
		return ret;
	}

	data &= ~mask;
	data |= ((value << shift) & mask);

	ret = bq25790_write_word(reg, data);
	mutex_unlock(&di->io_lock);
	return ret;
}

static int bq25790_read_word_mask(u8 reg, u16 mask, u16 shift, u16 *value)
{
	int ret;
	u16 data = 0;

	ret = bq25790_read_word(reg, &data);
	if (ret)
		return ret;

	data &= mask;
	data >>= shift;
	*value = data;

	return 0;
}

static int bq25790_device_check(void)
{
	u8 reg = 0;
	u8 dev_ver;
	int ret;

	if (!g_bq25790_dev) {
		hwlog_err("%s chip not init\n", __func__);
		return -EIO;
	}

	ret = bq25790_read_byte(BQ25790_REG_PART_INFO, &reg);
	if (ret)
		return CHARGE_IC_BAD;

	hwlog_info("device_check [0x%x]=0x%x\n", BQ25790_REG_PART_INFO, reg);

	dev_ver = (reg & BQ25790_REG_PN_MASK) >> BQ25790_REG_PN_SHIFT;
	g_bq25790_dev->vendor_id = dev_ver;

	switch (dev_ver) {
	case BK8984_DEVICE_PN:
		hwlog_info("bk8984 is good\n");
		if (snprintf_s(g_bq25790_dev->ic_name, CHIP_DEV_NAME_LEN,
			CHIP_DEV_NAME_LEN - 1, "bk8984") < 0)
			hwlog_err("ic name set fail\n");
		return CHARGE_IC_GOOD;
	case AH0096_DEVICE_PN:
		hwlog_info("ah0096 is good\n");
		if (snprintf_s(g_bq25790_dev->ic_name, CHIP_DEV_NAME_LEN,
			CHIP_DEV_NAME_LEN - 1, "ah0096") < 0)
			hwlog_err("ic name set fail\n");
		return CHARGE_IC_GOOD;
	default:
		hwlog_err("no chip match, return ic bad\n");
		return CHARGE_IC_BAD;
	}
}

static int bq25790_set_ovpthreshold(int threshold)
{
	int ret;
	int try_cnt = 0;

	while (try_cnt < RETRY_MAX3) {
		try_cnt++;
		ret = bq25790_write_mask(BQ25790_REG_CHG_CTRL1,
			BQ25790_VAC_OVP_MASK, BQ25790_VAC_OVP_SHIFT, threshold);
		if (!ret) {
			hwlog_info("set ovp = %d success\n", threshold);
			return ret;
		}
		power_usleep(DT_USLEEP_10MS);
	}

	hwlog_err("set ovp %d fail\n", threshold);
	return ret;
}

static int bq25790_5v_chip_init(struct bq25790_device_info *di)
{
	int ret;

	if (!di) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	ret = bq25790_write_mask(BQ25790_REG_CHG_CTRL5,
		BQ25790_EXTILIM_ENABLE_MASK, BQ25790_EXTILIM_ENABLE_SHIFT, 0);
	if (ret < 0)
		hwlog_err("disable extilim fail\n");

	/* enable charging */
	gpio_set_value(di->gpio_cd, 0);
	hwlog_info("5v_chip_init ok\n");

	return ret;
}

static int bq25790_9v_chip_init(struct bq25790_device_info *di)
{
	return 0;
}

static int bq25790_chip_init(struct charge_init_data *init_crit)
{
	int ret = -1;
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di || !init_crit) {
		hwlog_err("di or init_crit is null\n");
		return -ENOMEM;
	}

	switch (init_crit->vbus) {
	case ADAPTER_5V:
		ret = bq25790_5v_chip_init(di);
		break;
	case ADAPTER_9V:
		ret = bq25790_9v_chip_init(di);
		break;
	default:
		hwlog_err("invalid init_crit vbus mode\n");
		break;
	}

	return ret;
}

static int bq25790_set_input_current(int value)
{
	if (value < BQ25790_ICL_MIN_CURRENT)
		value = BQ25790_ICL_MIN_CURRENT;
	else if (value > BQ25790_ICL_MAX_CURRENT)
		value = BQ25790_ICL_MAX_CURRENT;

	value = value / BQ25790_ICL_CURRENT_STEP;
	hwlog_info("set_input_current [0x%x]=0x%x\n", BQ25790_REG_ICL, value);

	return bq25790_write_word_mask(BQ25790_REG_ICL,
		BQ25790_ICL_MASK, BQ25790_ICL_SHIFT, value);
}

static int bq25790_get_input_current_set(void)
{
	u16 value = 0;
	int iin_set;

	(void)bq25790_read_word_mask(BQ25790_REG_ICL, BQ25790_ICL_MASK,
		BQ25790_ICL_SHIFT, &value);
	iin_set = (int)value * BQ25790_ICL_CURRENT_STEP;

	return iin_set;
}

static int bq25790_set_charge_current(int value)
{
	int convert_ratio = bc_ic_get_convert_ratio();

	if (convert_ratio == 0) {
		hwlog_err("invalid convert ratio\n");
		return -EINVAL;
	}

	value /= convert_ratio;
	if (value < BQ25790_ICHG_MIN_CURRENT)
		value = BQ25790_ICHG_MIN_CURRENT;
	else if (value > BQ25790_ICHG_MAX_CURRENT)
		value = BQ25790_ICHG_MAX_CURRENT;

	value = value / BQ25790_ICHG_CURRENT_STEP;
	hwlog_info("set_charge_current [0x%x]=0x%x\n", BQ25790_REG_ICHG, value);

	return bq25790_write_word_mask(BQ25790_REG_ICHG,
		BQ25790_ICHG_MASK, BQ25790_ICHG_SHIFT, (u16)value);
}

static int bq25790_get_boost_current(int *curr)
{
	int ret;
	u8 val = 0;

	if (!curr)
		return -EINVAL;

	ret = bq25790_read_mask(BQ25790_REG_OTG_CUR,
		BQ25790_IOTG_MASK, BQ25790_IOTG_SHIFT, &val);
	if (ret) {
		hwlog_err("get_charge_current failed, ret=%d\n", ret);
		return ret;
	}

	*curr = val * BQ25790_OTG_CURRENT_STEP;
	return 0;
}

static int bq25790_set_iotg_current(int iotg)
{
	int curr = iotg / BQ25790_OTG_CURRENT_STEP;

	hwlog_info("set_iotg_current [0x%x]=0x%x\n", BQ25790_REG_OTG_CUR, curr);

	return bq25790_write_mask(BQ25790_REG_OTG_CUR,
		BQ25790_IOTG_MASK, BQ25790_IOTG_SHIFT, curr);
}

static int bq25790_set_boost_current(int curr)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	int max_current, ret;

	if (!di)
		return -ENODEV;

	if (di->vendor_id == AH0096_DEVICE_PN) {
		max_current = BQ25790_OTG_MAX_CURRENT;
		ret = bq25790_write_mask(BQ25790_REG_CHG_CTRL5, BQ25790_IINDPM_ENABLE_MASK,
			BQ25790_IINDPM_ENABLE_SHIFT, (curr > BQ25790_OTG_MAX_CURRENT) ? 0 : 1);
		if (ret < 0)
			hwlog_err("set iindpm fail\n");
	} else {
		max_current = BK8984_OTG_MAX_CURRENT;
	}

	return bq25790_set_iotg_current(max_current);
}

static int bq25790_set_terminal_voltage(int value)
{
	value *= bc_ic_get_convert_ratio();
	if (value < BQ25790_VREG_MIN_VOLTAGE)
		value = BQ25790_VREG_MIN_VOLTAGE;
	else if (value > BQ25790_VREG_MAX_VOLTAGE)
		value = BQ25790_VREG_MAX_VOLTAGE;

	value = value / BQ25790_VREG_VOLTAGE_STEP;
	hwlog_info("set_terminal_voltage [0x%x]=0x%x\n", BQ25790_REG_VREG, value);

	return bq25790_write_word_mask(BQ25790_REG_VREG,
		BQ25790_VREG_MASK, BQ25790_VREG_SHIFT, value);
}

static int bq25790_set_dpm_voltage(int value)
{
	if (value < BQ25790_VINDPM_MIN_VOLTAGE)
		value = BQ25790_VINDPM_MIN_VOLTAGE;
	else if (value > BQ25790_VINDPM_MAX_VOLTAGE)
		value = BQ25790_VINDPM_MAX_VOLTAGE;

	value = value / BQ25790_VINDPM_VOLTAGE_STEP;
	hwlog_info("set_dpm_voltage [0x%x]=0x%x\n", BQ25790_REG_VINDPM, value);

	return bq25790_write_byte(BQ25790_REG_VINDPM, value);
}

static int bq25790_set_terminal_current(int value)
{
	if (value < BQ25790_ITERM_MIN_CURRENT)
		value = BQ25790_ITERM_MIN_CURRENT;
	else if (value > BQ25790_ITERM_MAX_CURRENT)
		value = BQ25790_ITERM_MAX_CURRENT;

	value = value / BQ25790_ITERM_CURRENT_STEP;
	hwlog_info("set_terminal_current [0x%x]=0x%x\n", BQ25790_REG_TERM_CTRL, value);

	return bq25790_write_mask(BQ25790_REG_TERM_CTRL,
		BQ25790_ITERM_MASK, BQ25790_ITERM_SHIFT, (u16)value);
}

static int bq25790_set_ibat_limit(void *dev_data, int ibat)
{
	int val = BQ25790_IBAT_CURRENT_5A_VAL;

	switch (ibat) {
	case BQ25790_IBAT_CURRENT_3A:
		val = BQ25790_IBAT_CURRENT_3A_VAL;
		break;
	case BQ25790_IBAT_CURRENT_4A:
		val = BQ25790_IBAT_CURRENT_4A_VAL;
		break;
	case BQ25790_IBAT_CURRENT_5A:
		val = BQ25790_IBAT_CURRENT_5A_VAL;
		break;
	case BQ25790_IBAT_DISABLE:
		val = BQ25790_IBAT_DISABLE_VAL;
		break;
	default:
		break;
	}

	return bq25790_write_mask(BQ25790_REG_CHG_CTRL5,
		BQ25790_IBAT_REG_MASK, BQ25790_IBAT_REG_SHIFT, val);
}

static int bq25790_set_charge_enable(int enable)
{
	return bq25790_write_mask(BQ25790_REG_CHG_CTRL,
		BQ25790_CHG_ENABLE_MASK, BQ25790_CHG_ENABLE_SHIFT, enable);
}

static int bq25790_set_boost_voltage(int voltage)
{
	if (voltage < BQ25790_OTG_MIN_VOLTAGE)
		voltage = BQ25790_OTG_MIN_VOLTAGE;
	else if (voltage > BQ25790_OTG_MAX_VOLTAGE)
		voltage = BQ25790_OTG_MAX_VOLTAGE;

	voltage = (voltage - BQ25790_OTG_BASE_VOLTAGE) / BQ25790_OTG_VOLTAGE_STEP;
	hwlog_info("set_boost_voltage [0x%x]=0x%x\n", BQ25790_REG_OTG_VOL, voltage);

	return bq25790_write_word_mask(BQ25790_REG_OTG_VOL,
		BQ25790_VOTG_MASK, BQ25790_VOTG_SHIFT, voltage);
}

static int bq25790_set_otg_enable(int enable)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	int ret, iotg;
	u8 status = 0;
	u8 mask = BQ25790_IINDPM_ENABLE_MASK | BQ25790_IBAT_REG_MASK;

	if (!di)
		return -ENODEV;

	/*
	 * notice:
	 * why enable irq when entry to OTG mode only?
	 * because we care VBUS overloaded OCP or OVP's interrupt in boost mode
	 */
	if (!di->irq_active && enable) {
		di->irq_active = 1; /* active */
		enable_irq(di->irq_int);
	} else if (di->irq_active && !enable) {
		di->irq_active = 0; /* inactive */
		disable_irq(di->irq_int);
	}

	ret = bq25790_write_mask(BQ25790_REG_CHG_CTRL3,
		BQ25790_OTG_ENABLE_MASK, BQ25790_OTG_ENABLE_SHIFT, enable);
	ret += bq25790_read_byte(BQ25790_REG_CHG_STAT3, &status);
	if (enable) {
		if ((status & BQ25790_ACRB2_STAT_MASK) && !(status & BQ25790_ACRB1_STAT_MASK))
			ret += bq25790_write_mask(BQ25790_REG_CHG_CTRL4,
				BQ25790_ACDRV2_ENABLE_MASK, BQ25790_ACDRV2_ENABLE_SHIFT, enable);
		else if ((status & BQ25790_ACRB1_STAT_MASK) && !(status & BQ25790_ACRB2_STAT_MASK))
			ret += bq25790_write_mask(BQ25790_REG_CHG_CTRL4,
				BQ25790_ACDRV1_ENABLE_MASK, BQ25790_ACDRV1_ENABLE_SHIFT, enable);
		ret += bq25790_set_ibat_limit(di, BQ25790_IBAT_DISABLE_VAL);
		iotg = (di->vendor_id == BK8984_DEVICE_PN) ? BQ25790_OTG_CURR_2P5A : BQ25790_OTG_CURR_1P8A;
		ret += bq25790_set_iotg_current(iotg);
		di->otg_work_stop = false;
		mod_delayed_work(system_power_efficient_wq, &di->otg_work, 0);
	} else {
		ret += bq25790_write_mask(BQ25790_REG_CHG_CTRL5,
			mask, BQ25790_IINDPM_ENABLE_SHIFT, 5);
		di->otg_work_stop = true;
	}

	if (ret) {
		hwlog_err("set otg fail\n");
		return -EINVAL;
	}

	if (di->support_mosfet) {
		gpio_set_value(di->gpio_mosfet, enable);
		hwlog_info("set_otg_enable enable=%d, gpio_mosfet=%d\n",
			enable, gpio_get_value(di->gpio_mosfet));
	}

	return 0;
}

static int bq25790_get_charge_state(unsigned int *state)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	u8 reg = 0;
	int ret;

	if (!di || !state)
		return -ENODEV;

	ret = bq25790_read_byte(BQ25790_REG_CHG_STAT1, &reg);
	if (ret < 0) {
		hwlog_err("read chg stat1 reg fail\n");
		return ret;
	}

	hwlog_info("get_charge_state [0x%x]=0x%x\n", BQ25790_REG_CHG_STAT1, reg);
	if ((reg & BQ25790_CHG_STAT_MASK) == BQ25790_CHG_STAT_MASK)
		*state |= CHAGRE_STATE_CHRG_DONE;

	ret = bq25790_read_byte(BQ25790_REG_CHG_STAT0, &reg);
	if (ret < 0) {
		hwlog_err("read chg stat0 reg fail\n");
		return ret;
	}
	hwlog_info("get_charge_state [0x%x]=0x%x\n", BQ25790_REG_CHG_STAT0, reg);
	if (!(reg & BQ25790_PG_STAT_MASK))
		*state |= CHAGRE_STATE_NOT_PG;

	if ((reg & BQ25790_WD_STAT_MASK) == BQ25790_WD_STAT_MASK)
		*state |= CHAGRE_STATE_WDT_FAULT;

	ret = bq25790_read_byte(BQ25790_REG_FAULT_STAT0, &reg);
	if (ret < 0) {
		hwlog_err("read fault stat0 reg fail\n");
		return ret;
	}

	hwlog_info("get_charge_state [0x%x]=0x%x\n", BQ25790_REG_FAULT_STAT0, reg);
	if ((reg & BQ25790_VBUS_OVP_STAT_MASK) ==
		BQ25790_VBUS_OVP_STAT_MASK)
		*state |= CHAGRE_STATE_VBUS_OVP;

	if ((reg & BQ25790_VBAT_OVP_STAT_MASK) == BQ25790_VBAT_OVP_STAT_MASK)
		*state |= CHAGRE_STATE_BATT_OVP;

	return ret;
}

static int bq25790_set_term_enable(int enable)
{
	int ret;
	unsigned int state = CHAGRE_STATE_NORMAL;

	ret = bq25790_get_charge_state(&state);
	if (ret < 0) {
		hwlog_err("get_charge_state fail, ret = %d\n", ret);
		return -EINVAL;
	}
	if (state & CHAGRE_STATE_CHRG_DONE) {
		hwlog_info("state is charge done, can not set term_enable\n");
		return -EINVAL;
	}

	hwlog_info("%s enable = %d\n", __func__, enable);

	return bq25790_write_mask(BQ25790_REG_CHG_CTRL,
		BQ25790_TERM_ENABLE_MASK, BQ25790_TERM_ENABLE_SHIFT, enable);
}

static int bq25790_get_vbus_mv(unsigned int *vbus_mv)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	int ret;
	u16 data = 0;

	if (!di || !vbus_mv)
		return -EINVAL;

	if (!di->usb_plugged) {
		hwlog_info("vbus adc is disabled\n");
		return -EINVAL;
	}

	ret = bq25790_read_word(BQ25790_REG_VBUS_ADC, &data);
	if (ret) {
		hwlog_err("get vbus fail, ret=%d\n", ret);
		return ret;
	}

	if (di->vendor_id == BK8984_DEVICE_PN)
		*vbus_mv = (unsigned int)(data * BK8984_ADC_VOLTAGE_STEP);
	else
		*vbus_mv = (unsigned int)data;
	hwlog_info("vbus mv is %dmV\n", *vbus_mv);
	return ret;
}

static int bq25790_get_vac1_mv(int *vac1_mv)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	int ret;
	u16 data = 0;

	if (!di || !vac1_mv)
		return -EINVAL;

	if (!di->usb_plugged) {
		hwlog_info("vac adc is disabled\n");
		return -EINVAL;
	}

	ret = bq25790_read_word(BQ25790_REG_VAC1_ADC, &data);
	if (ret) {
		hwlog_err("get vac1 fail, ret=%d\n", ret);
		return ret;
	}

	if (di->vendor_id == BK8984_DEVICE_PN)
		*vac1_mv = (int)(data * BK8984_ADC_VOLTAGE_STEP);
	else
		*vac1_mv = (int)data;
	hwlog_info("vac1 mv is %dmV\n", *vac1_mv);
	return ret;
}

static int bq25790_get_vac2_mv(int *vac2_mv)
{
	struct bq25790_device_info *di = g_bq25790_dev;
	int ret;
	u16 data = 0;

	if (!di || !vac2_mv)
		return -EINVAL;

	if (!di->usb_plugged) {
		hwlog_info("vac2 adc is disabled\n");
		return -EINVAL;
	}

	ret = bq25790_read_word(BQ25790_REG_VAC2_ADC, &data);
	if (ret) {
		hwlog_err("get vac2 fail, ret=%d\n", ret);
		return ret;
	}

	if (di->vendor_id == BK8984_DEVICE_PN)
		*vac2_mv = (int)(data * BK8984_ADC_VOLTAGE_STEP);
	else
		*vac2_mv = (int)data;
	hwlog_info("vac2 mv is %dmV\n", *vac2_mv);
	return ret;
}

static int bq25790_reset_watchdog_timer(void)
{
	return bq25790_write_mask(BQ25790_REG_CHG_CTRL1,
		BQ25790_WDT_RST_ENABLE_MASK, BQ25790_WDT_RST_ENABLE_SHIFT, 0x01);
}

static int bq25790_get_ilim(void)
{
	short reg = 0;
	int ret;
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di || !di->usb_plugged) {
		hwlog_info("ibus adc is disabled\n");
		return -EINVAL;
	}

	ret = bq25790_read_word(BQ25790_REG_IBUS_ADC, &reg);
	if (ret)
		return ret;

	return (int)reg;
}

static int bq25790_check_charger_plugged(void)
{
	u8 reg = 0;
	int ret;

	ret = bq25790_read_mask(BQ25790_REG_CHG_STAT0,
		BQ25790_PG_STAT_MASK, BQ25790_PG_STAT_SHIFT, &reg);
	if (ret < 0)
		return 0;

	hwlog_info("check_charger_plugged [0x%x]=0x%x\n", BQ25790_REG_CHG_STAT0, reg);

	if (reg == BQ25790_POWER_GOOD)
		return BQ25790_POWER_GOOD;

	return 0;
}

static int bq25790_check_input_dpm_state(void)
{
	u8 reg = 0;
	int ret;

	ret = bq25790_read_byte(BQ25790_REG_CHG_STAT0, &reg);
	if (ret < 0)
		return FALSE;

	hwlog_info("check_input_dpm_state [0x%x]=0x%x\n", BQ25790_REG_CHG_STAT0, reg);

	if ((reg & BQ25790_VINDPM_STAT_MASK) || (reg & BQ25790_IINDPM_STAT_MASK))
		return TRUE;

	return FALSE;
}

static int bq25790_check_input_vdpm_state(void)
{
	u8 reg = 0;
	int ret;

	ret = bq25790_read_byte(BQ25790_REG_CHG_STAT0, &reg);
	if (ret < 0)
		return FALSE;

	hwlog_info("check_input_vdpm_state [0x%x]=0x%x\n", BQ25790_REG_CHG_STAT0, reg);

	if (reg & BQ25790_VINDPM_STAT_MASK)
		return TRUE;

	return FALSE;
}

static int bq25790_check_input_idpm_state(void)
{
	u8 reg = 0;
	int ret;

	ret = bq25790_read_byte(BQ25790_REG_CHG_STAT0, &reg);
	if (ret < 0)
		return FALSE;

	hwlog_info("check_input_idpm_state [0x%x]=0x%x\n", BQ25790_REG_CHG_STAT0, reg);

	if (reg & BQ25790_IINDPM_STAT_MASK)
		return TRUE;

	return FALSE;
}

static int bq25790_set_batfet_disable(int disable)
{
	return 0;
}

static int bq25790_set_batfet_disable_delay(int delay)
{
	return 0;
}

static int bq25790_set_ship_mode_enable(bool enable)
{
	return bq25790_set_batfet_disable(enable);
}

static int bq25790_set_watchdog_timer(int value)
{
	int val;

	if (value >= CHAGRE_WDT_160S)
		val = BQ25790_WDT_160S;
	else if (value >= CHAGRE_WDT_80S)
		val = BQ25790_WDT_80S;
	else if (value >= CHAGRE_WDT_40S)
		val = BQ25790_WDT_40S;
	else
		val = BQ25790_WDT_DISABLE;

	hwlog_info("set_watchdog_timer [0x%x]=0x%x\n", BQ25790_REG_CHG_CTRL1, val);

	return bq25790_write_mask(BQ25790_REG_CHG_CTRL1,
		BQ25790_WDT_TIMER_MASK, BQ25790_WDT_TIMER_SHIFT, val);
}

static int bq25790_stop_charge_config(void)
{
	return bq25790_set_watchdog_timer(CHAGRE_WDT_DISABLE);
}

static int bq25790_set_charger_hiz(int enable)
{
	int ret;

	ret = bq25790_write_mask(BQ25790_REG_CHG_CTRL, BQ25790_HIZ_ENABLE_MASK,
		BQ25790_HIZ_ENABLE_SHIFT, enable > 0 ? 1 : 0);

	return ret;
}

static int bq25790_set_vbus_vset(u32 volt)
{
	return 0;
}

static int bq25790_set_otg_switch_mode_enable(int enable)
{
	int ret, i;
	struct bq25790_device_info *di = g_bq25790_dev;

	if (!di) {
		hwlog_err("device info is not initialized\n");
		return -ENODEV;
	}

	if (enable) {
		hwlog_info("entering low-power mode\n");
		bq25790_write_mask(BQ25790_REG_ADC_CTRL,
			BQ25790_ADC_EN_MASK, BQ25790_ADC_EN_SHIFT, false);
		gpio_set_value(di->gpio_lp, 1);
		ret = bq25790_set_charger_hiz(1);
		if (ret) {
			hwlog_err("failed to enable hiz\n");
			gpio_set_value(di->gpio_lp, 0);
			return -EINVAL;
		}

		ret = bq25790_write_mask(BQ25790_REG_CHG_CTRL3, BQ25790_OTG_ENABLE_MASK,
			BQ25790_OTG_ENABLE_SHIFT, 0);
		if (ret) {
			hwlog_err("failed to disable OTG mode\n");
			return ret;
		}
	} else {
		hwlog_info("exiting low-power mode\n");
		for (i = 0; i < BQ25790_RETRY_CNT; i++) {
			ret = bq25790_set_charger_hiz(0);
			if (ret == 0)
				break;
			hwlog_err("failed to disable hiz\n");
			(void)power_msleep(DT_MSLEEP_100MS, 0, NULL);
		}

		for (i = 0; i < BQ25790_RETRY_CNT; i++) {
			gpio_set_value(di->gpio_lp, 0);
			if (gpio_get_value(di->gpio_lp) == 0)
				break;
			hwlog_err("failed to set gpio low, retry %d time\n", i);
			(void)power_msleep(DT_MSLEEP_100MS, 0, NULL);
		}
	}

	return 0;
}

static struct charge_device_ops bq25790_ops = {
	.chip_init = bq25790_chip_init,
	.dev_check = bq25790_device_check,
	.stop_charge_config = bq25790_stop_charge_config,
	.set_input_current = bq25790_set_input_current,
	.set_charge_current = bq25790_set_charge_current,
	.set_terminal_voltage = bq25790_set_terminal_voltage,
	.set_dpm_voltage = bq25790_set_dpm_voltage,
	.set_terminal_current = bq25790_set_terminal_current,
	.set_charge_enable = bq25790_set_charge_enable,
	.set_otg_enable = bq25790_set_otg_enable,
	.set_otg_current = bq25790_set_boost_current,
	.set_vbus_vset = bq25790_set_vbus_vset,
	.set_term_enable = bq25790_set_term_enable,
	.get_charge_state = bq25790_get_charge_state,
	.reset_watchdog_timer = bq25790_reset_watchdog_timer,
	.set_watchdog_timer = bq25790_set_watchdog_timer,
	.set_batfet_disable = bq25790_set_batfet_disable,
	.set_batfet_disable_delay = bq25790_set_batfet_disable_delay,
	.get_ibus = bq25790_get_ilim,
	.get_iin_set = bq25790_get_input_current_set,
	.check_charger_plugged = bq25790_check_charger_plugged,
	.set_otg_switch_mode_enable = bq25790_set_otg_switch_mode_enable,
	.check_input_dpm_state = bq25790_check_input_dpm_state,
	.check_input_vdpm_state = bq25790_check_input_vdpm_state,
	.check_input_idpm_state = bq25790_check_input_idpm_state,
	.set_charger_hiz = bq25790_set_charger_hiz,
	.get_charge_current = NULL,
	.set_boost_voltage = bq25790_set_boost_voltage,
	.get_vbus = bq25790_get_vbus_mv,
	.set_ship_mode_enable = bq25790_set_ship_mode_enable,
};

static struct charger_otg_device_ops bq25790_otg_ops = {
	.dev_name = "bq25790",
	.otg_set_charger_enable = bq25790_set_charge_enable,
	.otg_set_enable = bq25790_set_otg_enable,
	.otg_set_current = bq25790_set_boost_current,
	.otg_set_watchdog_timer = bq25790_set_watchdog_timer,
	.otg_reset_watchdog_timer = bq25790_reset_watchdog_timer,
};

static int bq25790_batinfo_exit(void *dev_data)
{
	return 0;
}

static int bq25790_batinfo_init(void *dev_data)
{
	return 0;
}

static int bq25790_get_vbat_mv(void *dev_data)
{
	struct bq25790_device_info *di = dev_data;
	u16 batt_volt = 0;
	int voltage;
	int ret;

	if (!di)
		return -ENODEV;

	if (!di->usb_plugged) {
		hwlog_info("vbat adc is disabled\n");
		return -EINVAL;
	}

	ret = bq25790_read_word(BQ25790_REG_VBAT_ADC, &batt_volt);
	if (ret)
		return ret;

	if (di->vendor_id == BK8984_DEVICE_PN)
		voltage = (int)(batt_volt * BK8984_ADC_VOLTAGE_STEP);
	else
		voltage = (int)batt_volt;

	hwlog_info("vbat mv is %dmV\n", batt_volt);
	return voltage;
}

static int bq25790_aux_sc_get_vbus_mv(int *vbus, void *dev_data)
{
	if (!dev_data || !vbus)
		return -EINVAL;

	return bq25790_get_vbus_mv(vbus);
}

static int bq25790_get_ibat_ma(int *ibat, void *dev_data)
{
	int ret;
	short reg = 0;

	if (!dev_data || !ibat)
		return -EINVAL;

	ret = bq25790_read_word(BQ25790_REG_IBAT_ADC, &reg);
	if (ret) {
		hwlog_err("get ibat fail, ret=%d\n", ret);
		return ret;
	}

	*ibat = (int)reg;
	hwlog_info("ibat ma is %dmA\n", *ibat);

	return ret;
}

static int bq25790_get_ibus_ma(int *ibus, void *dev_data)
{
	int ret;
	short reg = 0;
	struct bq25790_device_info *di = dev_data;

	if (!di || !ibus)
		return -EINVAL;

	if (!di->usb_plugged) {
		hwlog_info("ibus adc is disabled\n");
		return -EINVAL;
	}

	ret = bq25790_read_word(BQ25790_REG_IBUS_ADC, &reg);
	if (ret) {
		hwlog_err("get ibus fail, ret=%d\n", ret);
		return ret;
	}

	*ibus = (int)reg;
	hwlog_info("ibus ma is %dmA\n", *ibus);

	return ret;
}

static int bq25790_get_device_temp(int *temp, void *dev_data)
{
	int ret;
	short reg = 0;

	if (!dev_data || !temp)
		return -EINVAL;

	ret = bq25790_read_word(BQ25790_REG_TDIE_ADC, &reg);
	if (ret) {
		hwlog_err("get device temp fail, ret=%d\n", ret);
		return ret;
	}

	*temp = (int)reg / BQ25790_TEMP_STEP;
	hwlog_info("ic temp is %d\n", *temp);

	return ret;
}

static int bq25790_get_vusb_mv(int *vusb, void *dev_data)
{
	if (!dev_data || !vusb)
		return -EINVAL;

	return bq25790_get_vac1_mv(vusb);
}

static int bq25790_get_vout_mv(int *vout, void *dev_data)
{
	return 0;
}

static int bq25790_sc_charge_init(void *dev_data)
{
	struct bq25790_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EINVAL;
	}

	hwlog_info("%s enter\n", __func__);
	return bq25790_5v_chip_init(di);
}

static int bq25790_sc_charge_exit(void *dev_data)
{
	return 0;
}

static int bq25790_charge_enable(int enable, void *dev_data)
{
	struct bq25790_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EINVAL;
	}

	hwlog_info("%s enter, enable = %d\n", __func__, enable);
	if (enable == 0)
		return charge_set_hiz_enable(HIZ_MODE_ENABLE);

	charge_set_hiz_enable(HIZ_MODE_DISABLE);

	bq25790_set_input_current(di->sc_max_input_current);
	bq25790_set_charge_current(di->sc_max_charge_current * bc_ic_get_convert_ratio());
	bq25790_set_charge_enable(enable);
	power_usleep(DT_USLEEP_10MS);

	return 0;
}

static int bq25790_lvc_charge_enable(int enable, void *dev_data)
{
	struct bq25790_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EINVAL;
	}

	hwlog_info("%s enter, enable = %d\n", __func__, enable);
	if (enable == 0)
		return charge_set_hiz_enable(HIZ_MODE_ENABLE);

	charge_set_hiz_enable(HIZ_MODE_DISABLE);

	bq25790_set_input_current(di->lvc_max_input_current);
	bq25790_set_charge_current(di->lvc_max_charge_current * bc_ic_get_convert_ratio());
	bq25790_set_charge_enable(enable);
	power_usleep(DT_USLEEP_10MS);

	return 0;
}

static int bq25790_discharge(int enable, void *dev_data)
{
	return 0;
}

static int bq25790_is_device_close(void *dev_data)
{
	return 0;
}

static int bq25790_get_device_id(void *dev_data)
{
	struct bq25790_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EINVAL;
	}

	return di->device_id;
}

static int bq25790_config_watchdog_ms(int time, void *dev_data)
{
	return bq25790_set_watchdog_timer(time);
}

static int bq25790_kick_watchdog_ms(void *dev_data)
{
	return bq25790_reset_watchdog_timer();
}

static struct dc_batinfo_ops bq25790_batinfo_ops = {
	.init = bq25790_batinfo_init,
	.exit = bq25790_batinfo_exit,
	.get_bat_btb_voltage = bq25790_get_vbat_mv,
	.get_bat_package_voltage = bq25790_get_vbat_mv,
	.get_vbus_voltage = bq25790_aux_sc_get_vbus_mv,
	.get_bat_current = bq25790_get_ibat_ma,
	.get_ic_ibus = bq25790_get_ibus_ma,
	.get_ic_temp = bq25790_get_device_temp,
	.get_ic_vusb = bq25790_get_vusb_mv,
	.get_ic_vout = bq25790_get_vout_mv,
};

static struct dc_ic_ops bq25790_sysinfo_ops = {
	.dev_name = "bq25790",
	.ic_init = bq25790_sc_charge_init,
	.ic_exit = bq25790_sc_charge_exit,
	.ic_enable = bq25790_charge_enable,
	.ic_discharge = bq25790_discharge,
	.is_ic_close = bq25790_is_device_close,
	.get_ic_id = bq25790_get_device_id,
	.config_ic_watchdog = bq25790_config_watchdog_ms,
	.kick_ic_watchdog = bq25790_kick_watchdog_ms,
};

static struct dc_ic_ops bq25790_lvc_ops = {
	.dev_name = "bq25790",
	.ic_init = bq25790_sc_charge_init,
	.ic_exit = bq25790_sc_charge_exit,
	.ic_enable = bq25790_lvc_charge_enable,
	.ic_discharge = bq25790_discharge,
	.is_ic_close = bq25790_is_device_close,
	.get_ic_id = bq25790_get_device_id,
	.config_ic_watchdog = bq25790_config_watchdog_ms,
	.kick_ic_watchdog = bq25790_kick_watchdog_ms,
};

static int bq25790_dump_register(char *reg_value, int size, void *dev_data)
{
	u8 reg[BQ25790_REG_NUM] = { 0 };
	char buff[BUF_LEN] = { 0 };
	int reg_num = BQ25790_REG_NUM;
	int i;
	int ret;
	struct bq25790_dump_data data = { 0 };
	struct bq25790_device_info *di = dev_data;

	if (!di || !reg_value)
		return -EPERM;

	if (memset_s(reg_value, size, 0, size))
		return -ENOMEM;

	(void)bq25790_get_vbus_mv(&data.vbus);
	data.vbat = bq25790_get_vbat_mv(di);
	(void)bq25790_get_ibus_ma(&data.ibus, di);
	(void)bq25790_get_ibat_ma(&data.ibat, di);
	(void)bq25790_get_vac1_mv(&data.vac1);
	(void)bq25790_get_vac2_mv(&data.vac2);
	(void)bq25790_get_device_temp(&data.temp, di);

	ret = snprintf_s(reg_value, size, size - 1, "%-10s%-7d%-7d%-7d%-7d%-7d%-7d%-7d",
		di->ic_name, data.vbus, data.ibus, data.vbat,
		data.ibat, data.vac1, data.vac2, data.temp);
	if (ret < 0)
		return ret;

	for (i = 0; i < reg_num; i++) {
		ret = bq25790_read_byte(i, &reg[i]);
		if (ret)
			hwlog_err("dump_register read fail\n");

		if (snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "0x%-8.2x", reg[i]) < 0)
			return -ENOMEM;
		if (strncat_s(reg_value, size, buff, strlen(buff)))
			return -ENOMEM;
	}

	return 0;
}

static int bq25790_get_register_head(char *reg_head, int size, void *dev_data)
{
	char buff[BUF_LEN] = { 0 };
	int reg_num = BQ25790_REG_NUM;
	int i;

	if (!reg_head)
		return 0;

	if (memset_s(reg_head, size, 0, size))
		return -ENOMEM;

	if (snprintf_s(reg_head, size, size - 1,
		"dev       Vbus   Ibus   Vbat   Ibat   Vac1   Vac2   Temp   ") < 0)
		return -ENOMEM;

	for (i = 0; i < reg_num; i++) {
		if (snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "Reg[0x%-2.2x] ", i) < 0)
			return -ENOMEM;
		if (strncat_s(reg_head, size, buff, strlen(buff)))
			return -ENOMEM;
	}

	return 0;
}

static struct power_log_ops bq25790_log_ops = {
	.dev_name = "bq25790",
	.dump_log_head = bq25790_get_register_head,
	.dump_log_content = bq25790_dump_register,
};

static int bq25790_set_vcg_on(void *dev_data, int enable)
{
	return 0;
}

static int bq25790_set_idle_mode(void *dev_data, int mode)
{
	return 0;
}

static int bq25790_set_vbus_mv(void *dev_data, int vbus)
{
	struct bq25790_device_info *di = dev_data;

	if (!di || (vbus <= 0))
		return -EINVAL;

	return bq25790_set_boost_voltage(vbus);
}

static int bq25790_set_ibus_ma(void *dev_data, int ibus)
{
	struct bq25790_device_info *di = dev_data;

	if (!di || (ibus <= 0))
		return -EINVAL;

	return bq25790_set_boost_current(ibus);
}

static int bq25790_get_rt_iout_ma(void *dev_data, int *iout)
{
	struct bq25790_device_info *di = dev_data;
	int ret;
	int ibus = 0;

	if (!di || !iout)
		return -EINVAL;

	ret = bq25790_get_ibus_ma(&ibus, di);
	*iout = -ibus; //ibus is negtive when discharging
	return ret;
}

static int bq25790_get_rt_vout_mv(void *dev_data, int *vout)
{
	struct bq25790_device_info *di = dev_data;

	if (!di || !vout)
		return -EINVAL;

	return bq25790_get_vbus_mv(vout);
}

static int bq25790_ic_enable(void *dev_data, int enable)
{
	struct bq25790_device_info *di = dev_data;
	int ret = 0;

	if (!di)
		return -ENODEV;

	if (enable)
		ret = bq25790_set_charger_hiz(0);
	ret += bq25790_set_otg_enable(enable);

	return ret;
}

static struct boost_ops bq25790_boost_ops = {
	.chip_name = "bq25790",
	.set_vcg_on = bq25790_set_vcg_on,
	.set_vbus = bq25790_set_vbus_mv,
	.set_ibus = bq25790_set_ibus_ma,
	.set_ibat_limit = bq25790_set_ibat_limit,
	.get_ibus = bq25790_get_rt_iout_ma,
	.get_vbus = bq25790_get_rt_vout_mv,
	.ic_enable = bq25790_ic_enable,
	.set_idle_mode = bq25790_set_idle_mode,
};

static int bq25790_enable_reverse_9v_pd_charge(bool enable, void *dev_data)
{
	struct sc8726_device_info *di = dev_data;
	int ret;

	if (!di)
		return -ENODEV;

	if (enable) {
		ret = bq25790_set_boost_voltage(BQ25790_OTG_VOLT_9V);
		ret += bq25790_set_boost_current(BQ25790_OTG_CURR_2A);
	} else {
		ret = bq25790_set_boost_voltage(BQ25790_OTG_VOLT_5V);
		ret += bq25790_set_boost_current(BQ25790_OTG_CURR_3A);
	}

	return ret;
}

static struct rchg_pd_ic_ops bq25790_rchg_pd_ops = {
	.dev_name = "bq25790",
	.enable_reverse_charge = bq25790_enable_reverse_9v_pd_charge,
};

static void bq25790_irq_work(struct work_struct *work)
{
	struct bq25790_device_info *di = NULL;
	u8 addr = BQ25790_REG_CHG_FLAG0;
	u8 flag[BQ25790_FLAG_REG_NUM] = { 0 };
	int ret;
	int i;

	if (!work) {
		hwlog_err("work is null\n");
		return;
	}

	di = container_of(work, struct bq25790_device_info, irq_work);
	if (!di) {
		hwlog_err("di is null\n");
		return;
	}

	ret = bq25790_read_block(addr, flag, BQ25790_FLAG_REG_NUM);
	if (ret)
		hwlog_err("irq_work read fail\n");

	for (i = 0; i < BQ25790_FLAG_REG_NUM; i++) {
		if (flag[i])
			hwlog_err("fault_flag [0x%x]=0x%x\n", i + BQ25790_REG_CHG_FLAG0, flag[i]);
	}

	if (di->irq_active == 0) {
		di->irq_active = 1;
		enable_irq(di->irq_int);
	}
}

static irqreturn_t bq25790_interrupt(int irq, void *_di)
{
	struct bq25790_device_info *di = _di;

	if (!di) {
		hwlog_err("di is null\n");
		return IRQ_HANDLED;
	}

	hwlog_info("bq25790 int happened\n");

	if (di->irq_active == 1) {
		di->irq_active = 0;
		disable_irq_nosync(di->irq_int);
		schedule_work(&di->irq_work);
	} else {
		hwlog_info("the irq is not enable, do nothing\n");
	}

	return IRQ_HANDLED;
}

static void bq25790_init_ops_dev_data(struct bq25790_device_info *di)
{
	if (memcpy_s(&di->sc_ops, sizeof(struct dc_ic_ops),
		&bq25790_sysinfo_ops, sizeof(struct dc_ic_ops)) == EOK)
		di->sc_ops.dev_data = (void *)di;
	if (memcpy_s(&di->lvc_ops, sizeof(struct dc_ic_ops),
		&bq25790_lvc_ops, sizeof(struct dc_ic_ops)) == EOK)
		di->lvc_ops.dev_data = (void *)di;
	if (memcpy_s(&di->batinfo_ops, sizeof(struct dc_batinfo_ops),
		&bq25790_batinfo_ops, sizeof(struct dc_batinfo_ops)) == EOK)
		di->batinfo_ops.dev_data = (void *)di;

	if (!di->ic_role) {
		if (snprintf_s(di->name, CHIP_DEV_NAME_LEN,
			CHIP_DEV_NAME_LEN - 1, "bq25790") < 0)
			hwlog_err("dev name set fail\n");
	} else {
		if (snprintf_s(di->name, CHIP_DEV_NAME_LEN,
			CHIP_DEV_NAME_LEN - 1, "bq25790_%u", di->ic_role) < 0)
			hwlog_err("dev name set fail\n");
		di->sc_ops.dev_name = di->name;
		di->lvc_ops.dev_name = di->name;
	}
}

static void bq25790_dc_ops_register(struct bq25790_device_info *di)
{
	int ret;

	bq25790_init_ops_dev_data(di);

	ret = dc_ic_ops_register(LVC_MODE, di->ic_role, &di->lvc_ops);
	ret = dc_ic_ops_register(SC_MODE, di->ic_role, &di->sc_ops);
	ret += dc_batinfo_ops_register(di->ic_role, &di->batinfo_ops, di->device_id);
	if (ret)
		hwlog_err("sc ops or sysinfo ops register fail\n");
}

static int bq25790_ops_register(struct bq25790_device_info *di)
{
	int ret;

	ret = series_batt_ops_register(&bq25790_ops);
	if (ret) {
		hwlog_err("bq25790 charge ops register fail\n");
		return ret;
	}

	ret = charger_otg_ops_register(&bq25790_otg_ops);
	if (ret) {
		hwlog_err("bq25790 charger_otg ops register fail\n");
		return ret;
	}

	bq25790_log_ops.dev_data = (void *)di;
	(void)power_log_ops_register(&bq25790_log_ops);

	if (di->support_sc)
		bq25790_dc_ops_register(di);

	if (di->support_rchg_pd) {
		bq25790_rchg_pd_ops.dev_data = (void *)di;
		(void)rchg_pd_ops_register(&bq25790_rchg_pd_ops);
	}

	if (di->support_rvs_dc) {
		bq25790_boost_ops.dev_data = (void *)di;
		(void)boost_ops_register(&bq25790_boost_ops);
	}
	return 0;
}

static void bq25790_parse_dts(struct device_node *np, struct bq25790_device_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"support_sc", &di->support_sc, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"ic_role", &di->ic_role, IC_TWO);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sc_max_input_current", &di->sc_max_input_current, DEFAULT_SC_MAX_INPUT_CURRENT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sc_max_charge_current", &di->sc_max_charge_current, DEFAULT_SC_MAX_CHARGE_CURRENT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"lvc_max_input_current", &di->lvc_max_input_current, DEFAULT_LVC_MAX_INPUT_CURRENT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"lvc_max_charge_current", &di->lvc_max_charge_current, DEFAULT_LVC_MAX_CHARGE_CURRENT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"support_rchg_pd", &di->support_rchg_pd, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"support_rvs_dc", &di->support_rvs_dc, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"support_mosfet", &di->support_mosfet, 0);
}

static void bq25790_reg_init(struct bq25790_device_info *di)
{
	int ret;

	ret = bq25790_set_watchdog_timer(CHAGRE_WDT_DISABLE);
	if (ret < 0)
		hwlog_err("disable watchdog fail\n");

	ret = bq25790_write_mask(BQ25790_REG_PRECHG_CTRL,
		BQ25790_VBAT_LOW_MASK, BQ25790_VBAT_LOW_SHIFT, 0);
	if (ret < 0)
		hwlog_err("config precharge volt fail\n");

	ret = bq25790_write_mask(BQ25790_REG_ADC_DIS,
		BQ25790_TS_ADC_DIS_MASK, BQ25790_TS_ADC_DIS_SHIFT, true);
	if (ret < 0)
		hwlog_err("disable ts adc fail\n");

	ret = bq25790_write_mask(BQ25790_REG_CHG_CTRL4,
		BQ25790_STAT_DIS_MASK, BQ25790_STAT_DIS_SHIFT, true);
	if (ret < 0)
		hwlog_err("disable state pin output fail\n");

	ret = bq25790_write_byte(BQ25790_REG_CHG_CTRL2, 0);
	if (ret < 0)
		hwlog_err("disable bc1.2 fail\n");

	ret = bq25790_set_boost_voltage(BQ25790_OTG_VOLT_5V);
	if (ret < 0)
		hwlog_err("set bq25790 boost voltage fail\n");

	ret = bq25790_write_mask(BQ25790_REG_NTC_CTRL1, BQ25790_TS_IGNORE_MASK,
		BQ25790_TS_IGNORE_SHIFT, 1);
	if (ret < 0)
		hwlog_err("ignore ts feedback fail\n");

	ret = bq25790_set_ovpthreshold(BQ25790_VAC_OVP_22V);
	if (ret < 0)
		hwlog_err("init ovp fail\n");

	ret = bq25790_write_mask(BQ25790_REG_TIMER_CTRL, BQ25790_CHG_TIMER_EN_MASK,
		BQ25790_CHG_TIMER_EN_SHIFT, 0);
	if (ret < 0)
		hwlog_err("fast charge timer disable fail\n");
}

static int bq25790_usb_notifier_call(struct notifier_block *event_nb,
	unsigned long event, void *data)
{
	struct bq25790_device_info *di = container_of(event_nb,
		struct bq25790_device_info, event_nb);

	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_USB_CONNECT:
	case POWER_NE_OTG_INSERT:
		bq25790_write_mask(BQ25790_REG_ADC_CTRL,
			BQ25790_ADC_EN_MASK, BQ25790_ADC_EN_SHIFT, true);
		di->usb_plugged = true;
		break;
	case POWER_NE_USB_DISCONNECT:
	case POWER_NE_OTG_REMOVE:
		bq25790_write_mask(BQ25790_REG_ADC_CTRL,
			BQ25790_ADC_EN_MASK, BQ25790_ADC_EN_SHIFT, false);
		di->usb_plugged = false;
		break;
	default:
		return NOTIFY_OK;
	}

	return NOTIFY_OK;
}

static void bq25790_register_pwr_dev_info(struct bq25790_device_info *di)
{
	struct power_devices_info_data *power_dev_info = NULL;

	power_dev_info = power_devices_info_register();
	if (power_dev_info) {
		power_dev_info->dev_name = di->dev->driver->name;
		power_dev_info->dev_id = 0;
		power_dev_info->ver_id = 0;
	}
}

static int bq25790_gpio_init(struct device_node *np, struct bq25790_device_info *di)
{
	int ret;

	/* set gpio to control CD pin to disable/enable bq25790 IC */
	ret = power_gpio_config_output(np,
		"gpio_cd", "charger_cd", &di->gpio_cd, 0);
	if (ret)
		return ret;

	INIT_WORK(&di->irq_work, bq25790_irq_work);

	ret = power_gpio_config_interrupt(np,
		"gpio_int", "charger_int", &di->gpio_int, &di->irq_int);
	if (ret) {
		gpio_free(di->gpio_cd);
		return ret;
	}

	ret = power_gpio_config_output(np,
		"gpio_lp", "charger_lp", &di->gpio_lp, 0);
	if (ret) {
		gpio_free(di->gpio_cd);
		gpio_free(di->gpio_int);
		return ret;
	}

	ret = request_irq(di->irq_int, bq25790_interrupt, IRQF_TRIGGER_FALLING,
		"charger_int_irq", di);
	if (ret) {
		hwlog_err("gpio irq request fail\n");
		di->irq_int = -1;
		gpio_free(di->gpio_cd);
		gpio_free(di->gpio_int);
		gpio_free(di->gpio_lp);
		return ret;
	}

	if (di->support_mosfet) {
		ret = power_gpio_config_output(np,
			"gpio_mosfet", "charger_mosfet", &di->gpio_mosfet, 0);
		if (ret) {
			free_irq(di->irq_int, di);
			gpio_free(di->gpio_cd);
			gpio_free(di->gpio_int);
			gpio_free(di->gpio_lp);
			return ret;
		}
	}

	enable_irq_wake(di->irq_int);
	di->irq_active = 1;
	return 0;
}

static void bk8984_otg_work(struct work_struct *work)
{
	struct bq25790_device_info *di = NULL;
	int ibus = 0, iotg = 0;
	int ret, i;

	di = container_of(work, struct bq25790_device_info, otg_work.work);
	if (!di)
		return;

	if ((di->vendor_id != BK8984_DEVICE_PN) || di->otg_work_stop)
		return;

	for (i = 0; i < BQ25790_RETRY_CNT; i++) {
		ret = bq25790_get_rt_iout_ma(di, &ibus);
		ret += bq25790_get_boost_current(&iotg);
		if (ret) {
			hwlog_err("read ibus or iout failed\n");
			break;
		}
		if (ibus <= iotg - BQ25790_OTG_IBUS_IOUT_TH)
			break;

		(void)power_msleep(DT_MSLEEP_100MS, 0, NULL);
	}

	if (i == BQ25790_RETRY_CNT) {
		hwlog_err("ocp happened, disable otg\n");
		bq25790_set_otg_enable(0);
		return;
	}

	hwlog_info("bk8984 iotg=%d, ibus=%d\n", iotg, ibus);
	schedule_delayed_work(&di->otg_work, msecs_to_jiffies(BQ25790_OTG_WORK_DELAY));
}

static int bq25790_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	int ret;
	struct bq25790_device_info *di = NULL;
	struct device_node *np = NULL;

	if (g_bq25790_dev && g_bq25790_dev->probe_ok) {
		hwlog_err("bq25790 probe ok already\n");
		return -ENODEV;
	}

	if (!client || !client->dev.of_node || !id)
		return -ENODEV;

	di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_bq25790_dev = di;
	di->dev = &client->dev;
	np = di->dev->of_node;
	di->client = client;
	i2c_set_clientdata(client, di);
	mutex_init(&di->io_lock);

	/* check if bq25790 exist */
	if (bq25790_device_check() == CHARGE_IC_BAD) {
		hwlog_err("bq25790 not exists\n");
		ret = -EINVAL;
		goto bq25790_fail_0;
	}
	di->device_id = BUCK_BQ25790;
	di->usb_plugged = false;
	bq25790_parse_dts(np, di);
	bq25790_register_pwr_dev_info(di);
	bq25790_reg_init(di);
	INIT_DELAYED_WORK(&di->otg_work, bk8984_otg_work);
	ret = bq25790_gpio_init(np, di);
	if (ret)
		goto bq25790_fail_0;

	ret = bq25790_ops_register(di);
	if (ret)
		goto bq25790_fail_1;

	di->event_nb.notifier_call = bq25790_usb_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_OTG, &di->event_nb);
	if (ret)
		goto bq25790_fail_1;

	ret = power_event_bnc_register(POWER_BNT_CONNECT, &di->event_nb);
	if (ret)
		goto bq25790_fail_2;

	hwlog_info("bq25790 probe success\n");
	g_bq25790_dev->probe_ok = true;
	return 0;

bq25790_fail_2:
	power_event_bnc_unregister(POWER_BNT_OTG, &di->event_nb);
bq25790_fail_1:
	free_irq(di->irq_int, di);
	gpio_free(di->gpio_int);
	gpio_free(di->gpio_cd);
	gpio_free(di->gpio_lp);
	if (di->support_mosfet)
		gpio_free(di->gpio_mosfet);
bq25790_fail_0:
	mutex_destroy(&di->io_lock);
	devm_kfree(&client->dev, di);
	g_bq25790_dev = NULL;
	hwlog_err("bq25790 probe failed\n");
	return ret;
}

static void bq25790_shutdown(struct i2c_client *client)
{
	int ret;

	/* ic reset */
	ret = bq25790_write_mask(BQ25790_REG_TERM_CTRL,
		BQ25790_REG_RST_MASK, BQ25790_REG_RST_SHIFT, 1);
	if (ret)
		hwlog_err("bq25790 ic reset fail\n");
}

static int bq25790_remove(struct i2c_client *client)
{
	struct bq25790_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return -ENODEV;

	power_event_bnc_unregister(POWER_BNT_OTG, &di->event_nb);
	power_event_bnc_unregister(POWER_BNT_CONNECT, &di->event_nb);
	gpio_set_value(di->gpio_cd, 1);

	if (di->gpio_cd)
		gpio_free(di->gpio_cd);

	if (di->support_mosfet && di->gpio_mosfet)
		gpio_free(di->gpio_mosfet);

	if (di->irq_int)
		free_irq(di->irq_int, di);

	if (di->gpio_int)
		gpio_free(di->gpio_int);

	di->otg_work_stop = true;
	cancel_delayed_work(&di->otg_work);
	mutex_destroy(&di->io_lock);
	devm_kfree(&client->dev, di);
	g_bq25790_dev = NULL;

	return 0;
}

MODULE_DEVICE_TABLE(i2c, bq25790);
static const struct of_device_id bq25790_of_match[] = {
	{
		.compatible = "huawei,bq25790_charger",
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id bq25790_i2c_id[] = {
	{ "bq25790_charger", 0 }, {}
};

static struct i2c_driver bq25790_driver = {
	.probe = bq25790_probe,
	.remove = bq25790_remove,
	.shutdown = bq25790_shutdown,
	.id_table = bq25790_i2c_id,
	.driver = {
		.owner = THIS_MODULE,
		.name = "bq25790_charger",
		.of_match_table = of_match_ptr(bq25790_of_match),
	},
};

static int __init bq25790_init(void)
{
	return i2c_add_driver(&bq25790_driver);
}

static void __exit bq25790_exit(void)
{
	i2c_del_driver(&bq25790_driver);
}

module_init(bq25790_init);
module_exit(bq25790_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("bq25790 charger module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
