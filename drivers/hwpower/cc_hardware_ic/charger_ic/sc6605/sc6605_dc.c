// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_dc.c
 *
 * sc6605 dc driver
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
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

#include "sc6605_dc.h"
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_ic.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/hardware_channel/vbus_channel_charger.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_device_id.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_pd.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>

#define HWLOG_TAG sc6605_dc
HWLOG_REGIST();

static int sc6605_dc_field_read(struct sc6605_dc_dev *di, enum sc6605_chg_fields field_id)
{
	int ret;
	uint8_t reg_val;
	uint8_t mask = GENMASK(sc6605_chg_reg_fields[field_id].msb, sc6605_chg_reg_fields[field_id].lsb);

	ret = regmap_bulk_read(di->rmap, sc6605_chg_reg_fields[field_id].reg, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] sc6605 scp read field %d fail: %d\n", __func__, field_id, ret);
		return ret;
	}

	reg_val &= mask;
	reg_val >>= sc6605_chg_reg_fields[field_id].lsb;

	return reg_val;
}

static int sc6605_dc_field_write(struct sc6605_dc_dev *di, enum sc6605_chg_fields field_id, uint8_t val)
{
	int ret;
	uint8_t reg_val = 0, tmp = 0;
	uint8_t mask = GENMASK(sc6605_chg_reg_fields[field_id].msb, sc6605_chg_reg_fields[field_id].lsb);

	ret = regmap_bulk_read(di->rmap, sc6605_chg_reg_fields[field_id].reg, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] field %d fail: %d\n", __func__, field_id, ret);
		return ret;
	}

	tmp = reg_val & ~mask;
	val <<= sc6605_chg_reg_fields[field_id].lsb;
	tmp |= val  & mask;

	if (tmp != reg_val) {
		ret = regmap_bulk_write(di->rmap, sc6605_chg_reg_fields[field_id].reg, &tmp, REG_COUNT1);
		if (ret) {
			hwlog_err("[%s] sc6605 write field %d fail: %d\n", __func__, field_id, ret);
			return ret;
		}
	}

	return ret;
}

static int sc6605_dc_set_vac_ovp(struct sc6605_dc_dev *di, uint8_t vac_ovp_val)
{
	int ret;

	if (vac_ovp_val > SC6605_VAC_OVP_15V)
		vac_ovp_val = SC6605_VAC_OVP_15V;

	ret = sc6605_dc_field_write(di, F_VAC_OVP, vac_ovp_val);
	if (ret)
		hwlog_err("[%s] F_VAC_OVP write failed\n", __func__);

	return ret;
}

static int sc6605_dc_set_vbus_ovp(struct sc6605_dc_dev *di, uint8_t vbus_ovp_val)
{
	int ret;

	if (vbus_ovp_val < SC6605_VBUS_OVP_6V)
		vbus_ovp_val = SC6605_VBUS_OVP_6V;

	if (vbus_ovp_val > SC6605_VBUS_OVP_14V)
		vbus_ovp_val = SC6605_VBUS_OVP_14V;

	ret = sc6605_dc_field_write(di, F_VBUS_OVP, vbus_ovp_val);
	if (ret)
		hwlog_err("[%s] F_VBUS_OVP write failed\n", __func__);

	return ret;
}

static int sc6605_dc_set_ibus_ocp(struct sc6605_dc_dev *di, int ibus_ocp)
{
	int ret, tmp;
	uint8_t reg_val = 0;

	if (ibus_ocp <= IBUS_OCP_BASE)
		tmp = 0;
	else
		tmp = (ibus_ocp - IBUS_OCP_BASE) / IBUS_OCP_STEP;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_IBUS_OCP_UCP, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] sc6605 ibus ocp_ucp read fialed\n", __func__);
		return ret;
	}
	reg_val = (reg_val & IBUS_OCP_MASK) | tmp;
	ret = regmap_bulk_write(di->rmap, SC6605_REG_IBUS_OCP_UCP, &reg_val, REG_COUNT1);
	return ret;
}

static int sc6605_discharge(int enable, void *dev_data)
{
	return 0;
}

static int sc6605_is_device_close(void *dev_data)
{
	int ret;
	int state, mode;
	struct sc6605_dc_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	state = sc6605_dc_field_read(di, F_CP_STAT);
	if (state < 0) {
		hwlog_err("[%s] sc6605 field read fail: %d\n", __func__, state);
		return state;
	}
	if(state) {
		hwlog_info("charge-pump is switching\n");
		mode = sc6605_dc_field_read(di, F_MODE);
		if(mode == MODE_CHG_2_1)
			sc6605_set_charge_mode(SC21);
		else
			sc6605_set_charge_mode(SC11);
	} else {
		hwlog_info("charge-pump is not switching\n");
		sc6605_set_charge_mode(UNKNOWN);
	}

	return !state;
}

static int sc6605_get_device_id(void *dev_data)
{
	u8 did;
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_DEVICE_ID, &did, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] REG_DEVICE_ID read failed\n", __func__);
		return -EOPNOTSUPP;
	}

	if (did == SC6605_DEVICE_ID)
		di->device_id = SWITCHCAP_SC6605;
	else
		di->device_id = DC_DEVICE_ID_END;

	hwlog_info("[%s] get_device_id [%x]=0x%x, device_id: 0x%x\n", __func__, SC6605_REG_DEVICE_ID,
		did, di->device_id);

	return di->device_id;
}

static int sc6605_config_watchdog_ms(int time, void *dev_data)
{
	struct sc6605_dc_dev *di = dev_data;
	int ret, i;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	if (time < sc6605_chg_wd_time[0])
		time = sc6605_chg_wd_time[0];

	if (time > sc6605_chg_wd_time[ARRAY_SIZE(sc6605_chg_wd_time) - 1])
		time = sc6605_chg_wd_time[ARRAY_SIZE(sc6605_chg_wd_time) - 1];

	for (i = 0; i < ARRAY_SIZE(sc6605_chg_wd_time); i++) {
		if (time <= sc6605_chg_wd_time[i])
			break;
	}
	ret = sc6605_dc_field_write(di, F_WD_TIMER, i);
	if (ret)
		hwlog_err("[%s] F_WD_TIMER write failed\n", __func__);

	return ret;
}

static int sc6605_kick_watchdog_ms(void *dev_data)
{
	struct sc6605_dc_dev *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_dc_field_write(di, F_WD_TIME_RST, true);
	if (ret)
		hwlog_err("[%s] F_WD_TIME_RST write failed\n", __func__);

	return ret;
}

static int sc6605_dc_set_work_mode(struct sc6605_dc_dev *di, uint8_t mode)
{
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_dc_field_write(di, F_MODE, mode);
	if (ret)
		hwlog_err("[%s] F_MODE write failed\n", __func__);

	return ret;
}

static int sc6605_dc_set_enable(struct sc6605_dc_dev *di, bool enable)
{
	int ret;

	ret = sc6605_dc_field_write(di, F_PERFORMANCE_EN, enable);
	power_usleep(DT_USLEEP_20MS);
	ret |= sc6605_dc_field_write(di, F_CP_EN, enable);
	if (ret)
		hwlog_err("[%s] F_CP_EN failed\n", __func__);

	return ret;
}

static int sc6605_sc_charge_enable(int enable, void *dev_data)
{
	struct sc6605_dc_dev *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("[%s] enter, enable = %d\n", __func__, enable);
	ret = sc6605_dc_set_work_mode(di, MODE_CHG_2_1);
	ret |= sc6605_dc_set_enable(di, enable);
	if (ret)
		hwlog_err("[%s] sc_charge failed\n", __func__);

	return ret;
}
static int sc6605_reg_init(struct sc6605_dc_dev *di)
{
	int ret;

	ret = sc6605_dc_field_write(di, F_IBUS_UCP_SET, true);
	ret |= regmap_write(di->rmap, SC6605_VBUS2OUT_OVP_REG, SC6605_VBUS2OUT_OVP_VAL);
	ret |= regmap_write(di->rmap, SC6605_VBATSNS_OVP_REG, SC6605_VBATSNS_OVP_VAL);
	if (ret)
		hwlog_err("[%s] reg init failed\n", __func__);

	return ret;
}

static int sc6605_lvc_charge_init(void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}
	hwlog_info("[%s] enter\n", __func__);
	ret = sc6605_reg_init(di);
	ret |= sc6605_threshold_reg_init(SC6605_CHG_MODE_BYPASS);
	if (ret)
		hwlog_err("[%s] charge init failed\n", __func__);

	return ret;
}

static int sc6605_sc_charge_init(void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("[%s] enter\n", __func__);
	ret = sc6605_reg_init(di);
	ret |= sc6605_threshold_reg_init(SC6605_CHG_MODE_CHGPUMP);
	if (ret)
		hwlog_err("[%s] charge init failed\n", __func__);

	return ret;
}

static int sc6605_charge_exit(void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_dc_field_write(di, F_CHG_EN, 0);
	if (ret)
		hwlog_err("[%s] F_CHG_EN write failed\n", __func__);

	return ret;
}

static int sc6605_lvc_charge_enable(int enable, void *dev_data)
{
	struct sc6605_dc_dev *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("[%s] enter, enable = %d\n", __func__, enable);
	ret = sc6605_dc_set_work_mode(di, MODE_CHG_1_1);
	ret |= sc6605_dc_set_enable(di, enable);
	if (ret)
		hwlog_err("[%s] lvc_charge_enable failed\n", __func__);

	return ret;
}

static int sc6605_get_adc(struct sc6605_dc_dev *di, enum ADC_MODULE id)
{
	u16 reg = SC6605_REG_HK_IBUS_ADC + id * REG_COUNT2;
	uint8_t val[2] = {0};
	u32 ret, data;

	ret = sc6605_dc_field_write(di, F_ADC_EN, true);
	if (ret) {
		hwlog_err("[%s] F_ADC_EN set fail!\n", __func__);
		return ret;
	}

	power_usleep(DT_USLEEP_20MS);

	ret = regmap_bulk_read(di->rmap, reg, &val, sizeof(val));
	if (ret) {
		hwlog_err("[%s] read reg[0x%x] fail\n", __func__, reg);
		return ret;
	}

	ret = val[1] + (val[0] << SC6605_REG_SHIFT8);

	if (id == ADC_TDIE) {
		ret = ret / ADC_TDIE_PERCENT;
	} else {
		ret *= adc_step[id];
	}

	hwlog_info("[%s] channel: %d, val %d\n", __func__, id, ret);
	return (int)ret;
}

static int sc6605_get_device_temp(int *temp, void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di || !temp) {
		hwlog_err("[%s] di or temp is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_get_adc(di, ADC_TDIE);
	if (ret < 0) {
		*temp = 0;
		hwlog_err("[%s] get_adc ADC_TDIE failed\n", __func__);
		return ret;
	}

	*temp = ret;
	return 0;
}

static int sc6605_get_vusb_mv(int *vusb, void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di || !vusb) {
		hwlog_err("[%s] di or vusb is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_get_adc(di, ADC_VAC) / DEFAULT_PERCENT;
	if (ret < 0) {
		hwlog_err("[%s] get_adc ADC_VAC failed\n", __func__);
		*vusb = 0;
		return ret;
	}

	*vusb = ret;
	return 0;
}

static int sc6605_get_ibus_ma(int *ibus, void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di || !ibus) {
		hwlog_err("[%s] di or ibus is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_get_adc(di, ADC_IBUS) / DEFAULT_PERCENT;
	if (ret < 0) {
		hwlog_err("[%s] get_adc ADC_IBUS failed\n", __func__);
		*ibus = 0;
		return ret;
	}

	*ibus = ret;
	hwlog_info("[%s] sc6605_ibus=%d\n", __func__, *ibus);
	return 0;
}

static int sc6605_get_ibat_ma(int *ibat, void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di || !ibat) {
		hwlog_err("[%s] di or ibat is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_get_adc(di, ADC_IBAT) / DEFAULT_PERCENT;
	if (ret < 0) {
		*ibat = 0;
		hwlog_err("[%s] get_adc ADC_IBAT failed\n", __func__);
		return ret;
	}

	*ibat = ret;
	return 0;
}

static int sc6605_dc_get_vbus_mv(int *vbus, void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di || !vbus) {
		hwlog_err("[%s] di or vbus is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_get_adc(di, ADC_VBUS) / DEFAULT_PERCENT;
	if (ret < 0) {
		*vbus = 0;
		hwlog_err("[%s] get_adc ADC_VBUS failed\n", __func__);
		return ret;
	}

	*vbus = ret;
	hwlog_info("[%s] mv = %d\n", __func__, *vbus);
	return 0;
}

static int sc6605_get_vbat_mv(void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_get_adc(di, ADC_VBATSNS) / DEFAULT_PERCENT;
	if (ret < 0) {
		hwlog_err("[%s] get ADC_VBATSNS failed\n", __func__);
		return 0;
	}

	return ret;
}
static int sc6605_batinfo_init(void *dev_data)
{
	return 0;
}

static int sc6605_batinfo_exit(void *dev_data)
{
	return 0;
}

static int sc6605_chg_set_otg_volt(struct sc6605_dc_dev *di, int mv)
{
	int ret;
	uint16_t mv_reg = 0;

	if (mv < SC6605_BUCK_OTG_VOLT_MIN)
		mv = SC6605_BUCK_OTG_VOLT_MIN;

	if (mv > SC6605_BUCK_OTG_VOLT_MAX)
		mv = SC6605_BUCK_OTG_VOLT_MAX;

	mv_reg = ((mv - SC6605_BUCK_OTG_VOLT_OFFSET) / SC6605_BUCK_OTG_VOLT_STEP);
	ret = sc6605_dc_field_write(di, F_VBOOST_L, mv_reg);
	ret |= sc6605_dc_field_write(di, F_VBOOST_H,
		mv_reg >> SC6605_BUCK_OTG_VOLT_REG2_OFFSET);
	if (ret)
		hwlog_err("[%s] F_VBOOST write failed\n", __func__);

	return ret;
}

static int sc6605_dc_threshold_reg_init(struct sc6605_dc_dev *di, u8 mode)
{
	int ret, vwpc_ovp, ibus_ocp;
	int otg_ovp = 0;
	uint8_t vusb_ovp, vbus_ovp = 0;

	hwlog_info("%s enable=%u \n", __func__, mode);
	if (mode == MODE_CHG_1_1) {
		vbus_ovp = SC6605_VAC_OVP_6V5;
		vusb_ovp = SC6605_VBUS_OVP_6V;
		ibus_ocp = SC6605_LVC_IBUS_OCP_TH_INIT;
		otg_ovp = false;
	} else if (mode == MODE_CHG_2_1 || mode == MODE_OTG_1_2) {
		vbus_ovp = SC6605_VBUS_OVP_12V;
		vusb_ovp = SC6605_VAC_OVP_12V;
		ibus_ocp = SC6605_SC_IBUS_OCP_TH_INIT;
		otg_ovp = true;
	} else {
		vbus_ovp = SC6605_VBUS_OVP_6V;
		vusb_ovp = SC6605_VAC_OVP_6V5;
		ibus_ocp = SC6605_LVC_IBUS_OCP_TH_INIT;
		otg_ovp = false;
	}

	ret = sc6605_dc_set_vac_ovp(di, vusb_ovp);
	ret |= sc6605_dc_set_vbus_ovp(di, vbus_ovp);
	ret |= sc6605_dc_set_ibus_ocp(di, ibus_ocp);
	ret |= sc6605_dc_field_write(di, F_OTG_OVP, otg_ovp);
	if (ret)
		hwlog_err("[%s] ic protect threshold init failed\n", __func__);

	return ret;
}

static int sc6605_dc_reverse12_set_threshold(bool enable, struct sc6605_dc_dev *di)
{
	u8 mode = enable ? MODE_OTG_1_2 : MODE_CHG_2_1;

	return sc6605_dc_threshold_reg_init(di, mode);
}

static int sc6605_dc_request_buck_otg(struct sc6605_dc_dev *di, bool en)
{
	int ret = 0;
	int cnt = 0;
	uint8_t boost_state;

	ret = sc6605_dc_field_write(di, F_CHG_EN, !en);
	if (ret) {
		hwlog_err("[%s] set_chg failed\n", __func__);
		return ret;
	}
	do {
		boost_state = 0;
		if (cnt++ > REG_CHG_INT_COUNT) {
			hwlog_err("[%s] set_otg try times out\n", __func__);
			sc6605_dc_field_write(di, F_CHG_EN, true);
			return -EIO;
		}

		ret = sc6605_dc_field_write(di, F_BOOST_EN, en);
		if (ret) {
			hwlog_err("[%s] F_BOOST_EN write failed\n", __func__);
			sc6605_dc_field_write(di, F_CHG_EN, true);
			return ret;
		}

		power_msleep(DT_MSLEEP_30MS, 0, NULL);
		ret = regmap_bulk_read(di->rmap, SC6605_REG_CHG_INT_STAT + REG_CHG_INT_SHIFT,
			&boost_state, REG_COUNT1);
		if (ret) {
			hwlog_err("%s read 0x%x fail, ret = %d", __func__, SC6605_REG_CHG_INT_STAT + REG_CHG_INT_SHIFT, ret);
			return ret;
		}
	} while (en != (!!(boost_state & REG_CHG_INT_MASK)));

	ret = sc6605_dc_field_write(di, F_QB_EN, en);
	hwlog_info("[%s] otg set success", __func__);
	return ret;
}


static int sc6605_dc_wired_reverse_mode_enable(bool enable, struct sc6605_dc_dev *di)
{
	int ret;
	int retry = 5;
	int vbat = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &vbat,
		POWER_SUPPLY_DEFAULT_VOLTAGE_NOW, POWER_UV_PER_MV);
	hwlog_info("[%s] vbat=%d\n", __func__, vbat);

	if(enable) {
		ret = sc6605_dc_reverse12_set_threshold(true, di);
		ret |= sc6605_dc_field_write(di, F_VBUS2OUT_UVP, VBUS2OUT_UVP_MAX);
		ret |= sc6605_chg_set_otg_volt(di, vbat * MODE_OTG_1_2 - SC6605_OTG_VBAT_STEP);
		sc6605_dc_request_buck_otg(di, true);
		power_msleep(DT_MSLEEP_30MS, 0, NULL);
		ret |= sc6605_dc_set_work_mode(di, MODE_OTG_1_2);
		power_msleep(DT_MSLEEP_30MS, 0, NULL);
		ret |= sc6605_dc_set_enable(di, true);
	} else {
		ret = sc6605_dc_set_enable(di, false);
		sc6605_set_charge_mode(OTG5V);
	}

	if (ret) {
		hwlog_err("[%s] dc enable failed\n", __func__);
		return ret;
	}

	if (enable) {
		do {
			if (!sc6605_is_device_close(di)) {
				hwlog_info("[%s] set rvs cp open succ\n", __func__);
				sc6605_set_charge_mode(RSC12);
				power_usleep(DT_USLEEP_10MS);
				ret = sc6605_chg_set_otg_volt(di, SC6605_OTG_VOUT_5V1);
				return 0;
			}
			sc6605_dc_set_enable(di, enable);
			power_msleep(DT_MSLEEP_100MS, 0, NULL);
		} while (retry-- > 0);
		hwlog_err("[%s] set rvs cp open failed\n", __func__);
		return -EIO;
	}
	ret |= sc6605_dc_set_enable(di, enable);
	if (ret)
		hwlog_err("[%s] dc enable failed\n", __func__);
	return ret;
}

static int sc6605_dc_enable_wired_reverse_charge(bool enable, void *dev_data)
{
	int ret;
	struct sc6605_dc_dev *di = dev_data;

	if (!di)
		return -EPERM;

	hwlog_info("%s enable=%d \n", __func__, enable);
	ret = sc6605_dc_reverse12_set_threshold(enable, di);
	if (ret)
		return ret;

	return sc6605_dc_wired_reverse_mode_enable(enable, di);
}

static struct rchg_pd_ic_ops sc6605_dc_wired_rc_ops = {
	.dev_name = "sc6605",
	.enable_reverse_charge = sc6605_dc_enable_wired_reverse_charge,
};

static struct dc_ic_ops g_sc6605_lvc_ops = {
	.dev_name = "sc6605_dc",
	.ic_init = sc6605_lvc_charge_init,
	.ic_exit = sc6605_charge_exit,
	.ic_enable = sc6605_lvc_charge_enable,
	.ic_discharge = sc6605_discharge,
	.is_ic_close = sc6605_is_device_close,
	.get_ic_id = sc6605_get_device_id,
	.config_ic_watchdog = sc6605_config_watchdog_ms,
	.kick_ic_watchdog = sc6605_kick_watchdog_ms,
};

static struct dc_ic_ops g_sc6605_sc_ops = {
	.dev_name = "sc6605_dc",
	.ic_init = sc6605_sc_charge_init,
	.ic_exit = sc6605_charge_exit,
	.ic_enable = sc6605_sc_charge_enable,
	.ic_discharge = sc6605_discharge,
	.is_ic_close = sc6605_is_device_close,
	.get_ic_id = sc6605_get_device_id,
	.config_ic_watchdog = sc6605_config_watchdog_ms,
	.kick_ic_watchdog = sc6605_kick_watchdog_ms,
};

static struct dc_batinfo_ops g_sc6605_batinfo_ops = {
	.init = sc6605_batinfo_init,
	.exit = sc6605_batinfo_exit,
	.get_bat_btb_voltage = sc6605_get_vbat_mv,
	.get_bat_package_voltage = sc6605_get_vbat_mv,
	.get_vbus_voltage = sc6605_dc_get_vbus_mv,
	.get_bat_current = sc6605_get_ibat_ma,
	.get_ic_ibus = sc6605_get_ibus_ma,
	.get_ic_vusb = sc6605_get_vusb_mv,
	.get_ic_temp = sc6605_get_device_temp,
};

static void sc6605_ops_register(struct sc6605_dc_dev *di)
{
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return;
	}

	memcpy_s(&di->lvc_ops, sizeof(struct dc_ic_ops), &g_sc6605_lvc_ops, sizeof(struct dc_ic_ops));
	di->lvc_ops.dev_data = (void *)di;
	memcpy_s(&di->sc_ops, sizeof(struct dc_ic_ops), &g_sc6605_sc_ops, sizeof(struct dc_ic_ops));
	di->sc_ops.dev_data = (void *)di;
	memcpy_s(&di->batinfo_ops, sizeof(struct dc_batinfo_ops), &g_sc6605_batinfo_ops, sizeof(struct dc_batinfo_ops));
	di->batinfo_ops.dev_data = (void *)di;

	sc6605_dc_wired_rc_ops.dev_data = (void *)di;
	(void)rchg_pd_ops_register(&sc6605_dc_wired_rc_ops);
	ret = dc_ic_ops_register(LVC_MODE, IC_ONE, &di->lvc_ops);
	ret += dc_ic_ops_register(SC_MODE, IC_ONE, &di->sc_ops);
	ret += dc_batinfo_ops_register(IC_ONE, &di->batinfo_ops, di->device_id);
	if (ret)
		hwlog_err("[%s] sysinfo ops register failed\n", __func__);
}

static irqreturn_t sc6605_dc_interrupt_handler(int irq, void *data)
{
	struct sc6605_dc_dev *di = data;
	int i, ret;
	uint8_t reg_val;
	uint8_t dc_flt_val[2];

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return IRQ_NONE;
	}

	for (i = DC_REG_DUMP; i <= DC_REG_COUNT; i++) {
		ret = regmap_bulk_read(di->rmap, i, &reg_val, REG_COUNT1);
		hwlog_info("[%s] 0x%x->0x%x;", __func__, i, reg_val);
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_CP_FLT_STAT_1, dc_flt_val, REG_COUNT2);
	if (ret) {
		hwlog_err("%s read fault handle flag failed \n", __func__);
		return IRQ_NONE;
	}

	if (dc_flt_val[0] & IBUS_OCP_STAT_MASK) {
		power_event_anc_notify(POWER_ANT_SC_FAULT, POWER_NE_DC_FAULT_IBUS_OCP, NULL);
		hwlog_err("Buck Flag FAULT_IBUS_OCP\n");
	} else if (dc_flt_val[0] & VBAT_OVP_CP_STAT_MASK) {
		power_event_anc_notify(POWER_ANT_SC_FAULT, POWER_NE_DC_FAULT_VBAT_OVP, NULL);
		hwlog_err("Buck Flag FAULT_VBAT_OVP\n");
	}

	hwlog_info("[%s] enter\n", __func__);
	return IRQ_HANDLED;
}

static int sc6605_dc_request_irq(struct sc6605_dc_dev *di)
{
	int ret;
	const char *irq_name = "SC6605_DC";

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = platform_get_irq_byname(to_platform_device(di->dev), irq_name);
	if (ret < 0) {
		hwlog_err("[%s] failed to get irq %s\n", __func__, irq_name);
		return ret;   
	}

	di->irq = ret;
	hwlog_info("[%s] %s irq = %d\n", __func__, irq_name, ret);
	ret = devm_request_threaded_irq(di->dev, ret, NULL, sc6605_dc_interrupt_handler,
		IRQF_ONESHOT, dev_name(di->dev), di);
	if (ret)
		hwlog_err("[%s] failed to request irq %s\n", __func__, irq_name);

	return ret;
}

static int sc6605_dc_probe(struct platform_device *pdev)
{
	int ret;
	struct sc6605_dc_dev *di = NULL;
	struct device *dev = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	dev = &pdev->dev;
	di = devm_kzalloc(dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->rmap = dev_get_regmap(dev->parent, NULL);
	if (!di->rmap) {
		hwlog_err("[%s] failed to get regmap\n", __func__);
		return -ENODEV;
	}

	di->dev = dev;
	platform_set_drvdata(pdev, di);
	ret = sc6605_dc_request_irq(di);
	if (ret) {
		hwlog_err("dc request irq fail\n");
		goto sc6605_dc_fail_0;
	}
	sc6605_ops_register(di);
	hwlog_info("[%s] success\n", __func__);
	return 0;

sc6605_dc_fail_0:
	hwlog_err("[%s] failed\n", __func__);
	return ret;
}

static int sc6605_dc_remove(struct platform_device *pdev)
{
	hwlog_info("%s\n", __func__);
	return 0;
}

static const struct of_device_id sc6605_dc_of_match[] = {
	{
		.compatible = "huawei,sc6605_dc",
		.data = NULL,
	},
	{},
};

static struct platform_driver sc6605_dc_driver = {
	.driver = {
		.name = "sc6605_dc",
		.of_match_table = of_match_ptr(sc6605_dc_of_match),
	},
	.probe = sc6605_dc_probe,
	.remove = sc6605_dc_remove,
};

module_platform_driver(sc6605_dc_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("sc6605 dc module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");