// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_charger.c
 *
 * sc6605 charger driver
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

#include "sc6605_charger.h"
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_ic.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/hardware_channel/vbus_channel_charger.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_device_id.h>

#define HWLOG_TAG sc6605_charger
HWLOG_REGIST();

static struct sc6605_chg_device *g_sc6605_dev;
static int g_charge_ic_mode = UNKNOWN;

static int sc6605_chg_field_read(struct sc6605_chg_device *di, enum sc6605_chg_fields field_id)
{
	int ret;
	uint8_t reg_val = 0;
	uint8_t mask = GENMASK(sc6605_chg_reg_fields[field_id].msb, sc6605_chg_reg_fields[field_id].lsb);

	ret = regmap_bulk_read(di->rmap, sc6605_chg_reg_fields[field_id].reg, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] sc6605 chg read field %d fail: %d\n", __func__, field_id, ret);
		return ret;
	}

	reg_val &= mask;
	reg_val >>= sc6605_chg_reg_fields[field_id].lsb;

	return reg_val;
}

static int sc6605_chg_field_write(struct sc6605_chg_device *di, enum sc6605_chg_fields field_id,
	uint8_t val)
{
	int ret;
	uint8_t reg_val = 0, tmp = 0;
	uint8_t mask = GENMASK(sc6605_chg_reg_fields[field_id].msb, sc6605_chg_reg_fields[field_id].lsb);

	ret = regmap_bulk_read(di->rmap, sc6605_chg_reg_fields[field_id].reg, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] read field %d fail: %d\n", __func__, field_id, ret);
		return ret;
	}

	tmp = reg_val & ~mask;
	val <<= sc6605_chg_reg_fields[field_id].lsb;
	tmp |= val  & mask;

	if (tmp != reg_val) {
		ret = regmap_bulk_write(di->rmap, sc6605_chg_reg_fields[field_id].reg, &tmp, REG_COUNT1);
		if (ret) {
			hwlog_err("[%s] write field %d fail: %d\n", __func__, field_id, ret);
			return ret;
		}
	}

	return 0;
}

static int sc6605_chg_set_ico_enable(struct sc6605_chg_device *di, bool en)
{
	int ret;

	ret = sc6605_chg_field_write(di, F_ICO_EN, en);
	if (ret)
		hwlog_err("[%s] set_ico_enable failed\n", __func__);

	return ret;
}

static int sc6605_chg_mask_buck_irq(struct sc6605_chg_device *di, int irq_channel)
{
	int ret;
	uint8_t val[3] = {0};

	ret = regmap_bulk_read(di->rmap, SC6605_REG_CHG_INT_MASK, val, REG_COUNT3);
	if (ret) {
		hwlog_err("[%s] CHG_IN read failed\n", __func__);
		return ret;
	}

	val[0] |= irq_channel;
	val[1] |= irq_channel >> SC6605_REG_SHIFT8;
	val[2] |= irq_channel >> SC6605_REG_SHIFT16;
	ret = regmap_bulk_write(di->rmap, SC6605_REG_CHG_INT_MASK, val, REG_COUNT3);
	if (ret)
		hwlog_err("[%s] CHG_IN write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_sys_volt_min(struct sc6605_chg_device *di, int vsys_min_val)
{
	int ret;

	if (vsys_min_val < SC6605_VSYS_MIN_2V6)
		vsys_min_val = SC6605_VSYS_MIN_2V6;

	if (vsys_min_val > SC6605_VSYS_MIN_3V7)
		vsys_min_val = SC6605_VSYS_MIN_3V7;

	ret = sc6605_chg_field_write(di, F_VSYS_MIN, vsys_min_val);
	if (ret)
		hwlog_err("[%s] F_VSYS_MIN write failed\n", __func__);

	return ret;
}

int sc6605_chg_get_adc(struct sc6605_chg_device *di, enum ADC_MODULE id)
{
	uint8_t val[2] = {0};
	u32 adc_val = 0;
	u32 ret;
	u32 reg = SC6605_REG_HK_IBUS_ADC + id * REG_COUNT2;

	ret = sc6605_chg_field_write(di, F_ADC_EN, true);
	if (ret) {
		hwlog_err("[%s] F_ADC_EN set fail!\n", __func__);
		return 0;
	}

	power_usleep(DT_MSLEEP_20MS);
	ret = regmap_bulk_read(di->rmap, reg, val, sizeof(val));
	if (ret) {
		hwlog_err("[%s] read reg[0x%x] fail\n", __func__, reg);
		return (int)ret;
	}
	adc_val = val[1] + (val[0] << 8);

	if (id == ADC_TDIE)
		adc_val = adc_val / ADC_TDIE_PERCENT;
	else
		adc_val *= adc_step[id];

	hwlog_info("[%s] channel: %d, val %d", __func__, id, (int)adc_val);
	return (int)adc_val;
}

static int sc6605_chg_chip_reset(struct sc6605_chg_device *di)
{
	int ret;

	ret = sc6605_chg_field_write(di, F_REG_RST, true);
	if (ret)
		hwlog_err("[%s] REG_RST write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_acdrv_enable(struct sc6605_chg_device *di, bool en)
{
	int ret;
	int cnt = 0;
	int acdrv_val;

	acdrv_val = sc6605_chg_field_read(di, F_ACDRV_EN);
	do {
		if (cnt++ > 3) {
			hwlog_err("[%s] [ERR]set acdrv failed\n", __func__);
			return -EIO;
		}

		ret = sc6605_chg_field_write(di, F_ACDRV_EN, en);
		if (ret)
			continue;

		acdrv_val = sc6605_chg_field_read(di, F_ACDRV_EN);
		if (acdrv_val < 0)
			continue;
	} while (en != acdrv_val);

	hwlog_info("[%s] acdrv set %d success\n", __func__, (int)en);
	return ret;
}

static int sc6605_chg_set_vac_ovp(struct sc6605_chg_device *di, int vac_ovp_val)
{
	int ret;

	if (vac_ovp_val > SC6605_VAC_OVP_15V)
		vac_ovp_val = SC6605_VAC_OVP_15V;

	ret = sc6605_chg_field_write(di, F_VAC_OVP, (u8)vac_ovp_val);
	if (ret)
		hwlog_err("[%s] F_VAC_OV write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_vbus_ovp(struct sc6605_chg_device *di, int vbus_ovp_val)
{
	int ret;

	if (vbus_ovp_val < SC6605_VBUS_OVP_6V)
		vbus_ovp_val = SC6605_VBUS_OVP_6V;

	if (vbus_ovp_val > SC6605_VBUS_OVP_14V)
		vbus_ovp_val = SC6605_VBUS_OVP_14V;

	ret = sc6605_chg_field_write(di, F_VBUS_OVP, (u8)vbus_ovp_val);
	if (ret)
		hwlog_err("[%s] F_VBUS_OVP write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_ibus_ocp_th_ma(struct sc6605_chg_device *di, int ibus_ocp)
{
	int ret, tmp;
	uint8_t reg_val;

	if (ibus_ocp <= IBUS_OCP_BASE)
		tmp = 0;
	else
		tmp = (ibus_ocp - IBUS_OCP_BASE) / IBUS_OCP_STEP;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_IBUS_OCP_UCP, &reg_val, REG_COUNT1);
	reg_val = (reg_val & IBUS_OCP_MASK) | tmp;
	ret |= regmap_bulk_write(di->rmap, SC6605_REG_IBUS_OCP_UCP, &reg_val, REG_COUNT1);
	return ret;
}

static int sc6605_chg_set_vbat_ovp_th_mv(struct sc6605_chg_device *di, int vbat_ovp)
{
	int ret, tmp;
	uint8_t reg_val;

	if (vbat_ovp <= VBAT_OVP_BASE)
		tmp = 0;
	else
		tmp = (vbat_ovp - VBAT_OVP_BASE) / VBAT_OVP_STEP;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_VBAT_SNS_OVP_DIS, &reg_val, REG_COUNT1);
	reg_val = (reg_val & VBAT_OVP_MASK) | tmp;
	ret |= regmap_bulk_write(di->rmap, SC6605_REG_VBAT_SNS_OVP_DIS, &reg_val, REG_COUNT1);
	return ret;
}

int sc6605_threshold_reg_init(int mode)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret, ibus_ocp, vac_ovp, vbus_ovp;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("[%s] mode = %d \n", __func__, mode);
	if (mode == SC6605_CHG_MODE_CHGPUMP) {
		vbus_ovp = SC6605_VBUS_OVP_12V;
		ibus_ocp = SC6605_SC_IBUS_OCP_TH_INIT;
	} else {
		vbus_ovp = SC6605_VBUS_OVP_10V;
		ibus_ocp = SC6605_LVC_IBUS_OCP_TH_INIT;
	}

	ret = sc6605_chg_set_vac_ovp(di, SC6605_VAC_OVP_12V);
	ret |= sc6605_chg_set_vbus_ovp(di, vbus_ovp);
	ret |= sc6605_chg_set_ibus_ocp_th_ma(di, ibus_ocp);
	ret |= sc6605_chg_set_vbat_ovp_th_mv(di, SC6605_VBAT_OVP_TH_INIT);
	if (ret)
		hwlog_info("protect threshold init failed\n");

	return ret;
}

static int sc6605_chg_mask_hk_irq(struct sc6605_chg_device *di, int irq_channel)
{
	int ret;
	uint8_t val;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_HK_INT_MASK, &val, REG_COUNT1);
	if (ret) {
		hwlog_err("%s read 0x%x fail, ret = %d", __func__, SC6605_REG_HK_INT_MASK, ret);
		return ret;
	}
	val |= irq_channel;
	ret = regmap_write(di->rmap, SC6605_REG_HK_INT_MASK, val);
	if (ret)
		hwlog_err("[%s] REG_HK_INT write failed\n", __func__);

	return ret;
}

void sc6605_set_charge_mode(int mode)
{
	g_charge_ic_mode = mode;
	hwlog_info("%s g_charge_ic_mode = %d\n", __func__, g_charge_ic_mode);
}

int sc6605_get_charge_mode(void)
{
	hwlog_info("%s g_charge_ic_mode = %d\n", __func__, g_charge_ic_mode);
	return g_charge_ic_mode;
}

struct current_charger_mode* sc6605_get_current_charge_mode(void)
{
	if (g_sc6605_dev == NULL) {
		hwlog_err("%s g_sc6605_dev is NULL\n", __func__);
		return NULL;
	}

	return &g_sc6605_dev->current_charge_mode;
}

static int sc6605_chg_get_input_curr_lmt(struct sc6605_chg_device *di, uint32_t *ma)
{
	int ret;

	ret = sc6605_chg_field_read(di, F_PERFORMANCE_EN);
	if (ret < 0) {
		hwlog_err("[%s] F_PERFORMANCE_EN read failed\n", __func__);
		return ret;
	}
	if (ret) {
		hwlog_info("buck is HIZ mode\n", __func__);
		*ma = 0;
		return 0;
	}
	ret = sc6605_chg_field_read(di, F_IINDPM);
	if (ret < 0) {
		hwlog_err("[%s] F_IINDPM read failed\n", __func__);
		return ret;
	}

	*ma = SC6605_BUCK_IINDPM_STEP * ret + SC6605_BUCK_IINDPM_OFFSET;
	return 0;
}

static int sc6605_chg_set_input_volt_lmt(struct sc6605_chg_device *di, int mv)
{
	int i, ret;

	if (mv > 0)
		di->now_vindpm = mv;

	if (mv < vindpm[0])
		mv = vindpm[0];

	if (mv > vindpm[ARRAY_SIZE(vindpm) - 1])
		mv = vindpm[ARRAY_SIZE(vindpm) - 1];

	for (i = 0; i < ARRAY_SIZE(vindpm); i++) {
		if (mv <= vindpm[i])
			break;
	}

	ret = sc6605_chg_field_write(di, F_VINDPM, i);
	if (ret) {
		hwlog_err("[%s] F_VINDPM write failed\n", __func__);
		return ret;
	}

	di->state.vindpm = vindpm[i];
	return 0;
}

static int sc6605_chg_set_ichg(struct sc6605_chg_device *di, int ma)
{
	int ret;

	if (ma <= SC6605_BUCK_ICHG_MIN)
		ma = SC6605_BUCK_ICHG_MIN;
	else if (ma >= SC6605_BUCK_ICHG_MAX)
		ma = SC6605_BUCK_ICHG_MAX;

	ma = (ma - SC6605_BUCK_ICHG_OFFSET) / SC6605_BUCK_ICHG_STEP;
	ret = sc6605_chg_field_write(di, F_ICHG_CC, ma);
	if (ret)
		hwlog_err("[%s] F_ICHG_CC write failed\n", __func__);

	return ret;
}

static int sc6605_chg_enable(struct sc6605_chg_device *di, bool en)
{
	int ret;

	ret = sc6605_chg_field_write(di, F_CHG_EN, en);
	if (ret)
		hwlog_err("[%s] F_CHG_EN write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_watchdog_timeout(struct sc6605_chg_device *di, int ms)
{
	int ret, i;

	if (ms < sc6605_chg_wd_time[0])
		ms = sc6605_chg_wd_time[0];

	if (ms > sc6605_chg_wd_time[ARRAY_SIZE(sc6605_chg_wd_time) - 1])
		ms = sc6605_chg_wd_time[ARRAY_SIZE(sc6605_chg_wd_time) - 1];

	for (i = 0; i < ARRAY_SIZE(sc6605_chg_wd_time); i++) {
		if (ms <= sc6605_chg_wd_time[i])
			break;
	}
	ret = sc6605_chg_field_write(di, F_WD_TIMER, i);
	if (ret)
		hwlog_err("[%s] F_WD_TIMER write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_otg(struct sc6605_chg_device *di, bool en)
{
	int ret;
	int cnt = 0;
	uint8_t boost_state;

	ret = sc6605_chg_enable(di, !en);
	if (ret) {
		hwlog_err("[%s] set_chg failed\n", __func__);
		return ret;
	}
	do {
		boost_state = 0;
		if (cnt++ > REG_CHG_INT_COUNT) {
			hwlog_err("[%s] set_otg try times out\n", __func__);
			sc6605_chg_enable(di, true);
			return -EIO;
		}
		ret = sc6605_chg_field_write(di, F_BOOST_EN, en);
		if (ret) {
			hwlog_err("[%s] F_BOOST_EN write failed\n", __func__);
			sc6605_chg_enable(di, true);
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

	hwlog_info("[%s] otg set success", __func__);
	return 0;
}

static int sc6605_chg_request_otg(struct sc6605_chg_device *di, int index, bool en)
{
	int ret;
	int is_cp_enable;

	if (en)
		set_bit(index, &di->request_otg);
	else 
		clear_bit(index, &di->request_otg);

	hwlog_info("[%s] now request_otg = %lx\n", __func__, di->request_otg);

	is_cp_enable = sc6605_chg_field_read(di, F_CP_STAT);
	if(is_cp_enable) {
		hwlog_info("%s cp enabled, ingore set buck otg\n", __func__);
		return 0;
	}

	ret = sc6605_chg_field_write(di, F_QB_EN, en);
	if (ret) {
		hwlog_err("%s field write  F_QB_EN failed\n", __func__);
		return ret;
	}

	if (!en && di->request_otg)
		return 0;

	ret = sc6605_chg_set_otg(di, en);
	if (ret) {
		if (en)
			clear_bit(index, &di->request_otg);
		else 
			set_bit(index, &di->request_otg);
		return ret;
	}

	return 0;
}

static int sc6605_chg_set_otg_curr(struct sc6605_chg_device *di, int ma)
{
	int ret, i;

	if (ma < boost_curr[0])
		ma = boost_curr[0];

	if (ma > boost_curr[ARRAY_SIZE(boost_curr) - 1])
		ma = boost_curr[ARRAY_SIZE(boost_curr) - 1];

	for (i = 0; i < ARRAY_SIZE(boost_curr); i++) {
		if (ma < boost_curr[i])
			break;
	}
	ret = sc6605_chg_field_write(di, F_IBOOST, i);
	if (ret)
		hwlog_err("[%s] F_IBOOST write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_otg_volt(struct sc6605_chg_device *di, int mv)
{
	int ret;
	uint16_t mv_reg;

	if (mv < SC6605_BUCK_OTG_VOLT_MIN)
		mv = SC6605_BUCK_OTG_VOLT_MIN;

	if (mv > SC6605_BUCK_OTG_VOLT_MAX)
		mv = SC6605_BUCK_OTG_VOLT_MAX;

	mv_reg = ((mv - SC6605_BUCK_OTG_VOLT_OFFSET) / SC6605_BUCK_OTG_VOLT_STEP);
	ret = sc6605_chg_field_write(di, F_VBOOST_L, mv_reg);
	ret |= sc6605_chg_field_write(di, F_VBOOST_H,
		mv_reg >> SC6605_BUCK_OTG_VOLT_REG2_OFFSET);
	if (ret)
		hwlog_err("[%s] F_VBOOST write failed\n", __func__);

	di->otg_vol = mv;
	return ret;
}

static int sc6605_chg_set_term_curr(struct sc6605_chg_device *di, int ma)
{
	int ret;

	if (ma < SC6605_BUCK_ITERM_MIN)
		ma = SC6605_BUCK_ITERM_MIN;

	if (ma > SC6605_BUCK_ITERM_MAX)
		ma = SC6605_BUCK_ITERM_MAX;

	ma = (ma - SC6605_BUCK_ITERM_OFFSET) / SC6605_BUCK_ITERM_STEP;
	ret = sc6605_chg_field_write(di, F_ITERM, ma);
	if (ret)
		hwlog_err("[%s] F_ITERM write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_term_volt(struct sc6605_chg_device *di, int mv)
{
	int ret = 0;

	if (mv < SC6605_BUCK_VBAT_MIN)
		mv = SC6605_BUCK_VBAT_MIN;

	if (mv > SC6605_BUCK_VBAT_MAX)
		mv = SC6605_BUCK_VBAT_MAX;

	mv = (mv - SC6605_BUCK_VBAT_OFFSET) / SC6605_BUCK_VBAT_STEP;
	ret = sc6605_chg_field_write(di, F_VBAT, mv);
	if (ret)
		hwlog_err("[%s] F_VBAT write failed\n", __func__);

	return ret;
}

static int sc6605_chg_set_prechg_curr(struct sc6605_chg_device *di, int ma)
{
	int ret;

	if (ma < SC6605_BUCK_PRE_CURR_MIN)
		ma = SC6605_BUCK_PRE_CURR_MIN;

	if (ma > SC6605_BUCK_PRE_CURR_MAX)
		ma = SC6605_BUCK_PRE_CURR_MAX;

	ma = (ma - SC6605_BUCK_PRE_CURR_OFFSET) / SC6605_BUCK_PRE_CURR_STEP;
	ret = sc6605_chg_field_write(di, F_IPRECHG, ma);
	if (ret)
		hwlog_err("[%s] F_IPRECHG write failed\n", __func__);

	return ret;
}

static int sc6605_chg_kick_wd(struct sc6605_chg_device *di)
{
	int ret;

	ret = sc6605_chg_field_write(di, F_WD_TIME_RST, true);
	if (ret)
		hwlog_err("[%s] F_WD_TIME_RST write failed\n", __func__);

	return ret;
}

static int sc6605_pumpuv_vsys(struct sc6605_chg_device *di)
{
	int ret = 0;
	struct i2c_client *i2c = NULL;
	u8 pump_vsys[] = {0xA5, 0x04};

	i2c = to_i2c_client(di->dev->parent);
	di->adp = i2c->adapter;
	struct i2c_msg msg = {
		.addr = 0x64,
		.flags = 0,
	};
	msg.len = sizeof(pump_vsys);
	msg.buf = pump_vsys;
	ret = i2c_transfer(di->adp, &msg, 1);

	return ret > 0 ? 0 : ret;
}

static int sc6605_reg_init(struct sc6605_chg_device *di)
{
	int ret, i;

	struct buck_reg_init_table reg_init_tbl[] = {
		{F_BATSNS_EN,         di->buck_init.batsns_en},
		{F_VBAT,              (di->buck_init.vbat - SC6605_BUCK_VBAT_OFFSET) / SC6605_BUCK_VBAT_STEP},
		{F_ICHG_CC,           (di->buck_init.ichg - SC6605_BUCK_ICHG_OFFSET) / SC6605_BUCK_ICHG_STEP},
		{F_IINDPM_DIS,        di->buck_init.iindpm_dis},
		{F_VBAT_PRECHG,       di->buck_init.vprechg},
		{F_IPRECHG,           (di->buck_init.iprechg - SC6605_BUCK_IPRECHG_OFFSET) / SC6605_BUCK_IPRECHG_STEP},
		{F_TERM_EN,           di->buck_init.iterm_en},
		{F_ITERM,             (di->buck_init.iterm - SC6605_BUCK_ITERM_OFFSET) / SC6605_BUCK_ITERM_STEP},
		{F_RECHG_DIS,         di->buck_init.rechg_dis},
		{F_RECHG_DG,          di->buck_init.rechg_dg},
		{F_VRECHG,            di->buck_init.rechg_volt},
		{F_CONV_OCP_DIS,      di->buck_init.conv_ocp_dis},
		{F_TSBAT_JEITA_DIS,   0},
		{F_IBAT_OCP_DIS,      di->buck_init.ibat_ocp_dis},
		{F_VPMID_OVP_OTG_DIS, di->buck_init.vpmid_ovp_otg_dis},
		{F_VBAT_OVP_BUCK_DIS, di->buck_init.vbat_ovp_buck_dis},
		{F_IBATOCP,           di->buck_init.ibat_ocp},
		{F_QB_EN,             false},
		{F_ACDRV_MANUAL_EN,   true},
		{F_ICO_EN,            false},
		{F_EDL_ACTIVE_LEVEL,  true},
		{F_ACDRV_MANUAL_PRE,  true},
		{F_HVDCP_EN,          false},
	};

	for (i = 0; i < ARRAY_SIZE(reg_init_tbl); i++)
		ret |= sc6605_chg_field_write(di, reg_init_tbl[i].field, reg_init_tbl[i].val);

	return ret;
}

static int sc6605_chg_hw_init(struct sc6605_chg_device *di)
{
	int ret;
	uint8_t val;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	/* reset all registers without flag registers */
	ret = sc6605_chg_chip_reset(di);
	ret |= sc6605_chg_enable(di, false);
	/* set buck freq = 1M , boost freq = 1M */
	ret |= regmap_write(di->rmap, SC6605_REG_CHG_CTRL + 4, SC6605_BUCK_BOOST_FREQ_1MHZ);
	/* set  charge timer = 20 hrs*/
	ret |= regmap_write(di->rmap, SC6605_REG_CHG_CTRL + 3, SC6605_CHG_TIME_20HOURS);
	ret |= sc6605_chg_enable(di, true);
	ret |= sc6605_chg_set_watchdog_timeout(di, 0);
	/* clear flt && flag */
	ret |= regmap_bulk_read(di->rmap, SC6605_REG_HK_FLT_FLG, &val, REG_COUNT1);
	ret |= sc6605_chg_set_vac_ovp(di, SC6605_VAC_OVP_14V);
	ret |= sc6605_chg_set_vbus_ovp(di, SC6605_VBUS_OVP_14V);
	ret |= sc6605_chg_set_ico_enable(di, false);
	ret |= sc6605_chg_set_acdrv_enable(di, true);
	ret |= sc6605_chg_set_sys_volt_min(di, SC6605_VSYS_MIN_3V5);
	ret |= sc6605_chg_mask_hk_irq(di, SC6605_HK_RESET_MASK |
		SC6605_HK_ADC_DONE_MASK | SC6605_HK_REGN_OK_MASK |
		SC6605_HK_VAC_PRESENT_MASK);

	ret |= sc6605_chg_mask_buck_irq(di, SC6605_BUCK_ICO_MASK |
		SC6605_BUCK_IINDPM_MASK | SC6605_BUCK_VINDPM_MASK |
		SC6605_BUCK_CHG_MASK | SC6605_BUCK_QB_ON_MASK |
		SC6605_BUCK_VSYSMIN_MASK);

	ret |= sc6605_reg_init(di);
	ret |= regmap_write(di->rmap, SC6605_REG_IBUS_OCP_UCP, REG_IBUS_OCP_1A5_UCP_160MS);
	ret |= sc6605_chg_field_write(di, F_AUTO_DPDM, false);
	ret |= sc6605_pumpuv_vsys(di);

	if(ret) {
		hwlog_err("[%s] chg_hw_init failed\n", __func__);
		return ret;
	}

	return 0;
}

static int sc6605_chg_set_batfet_disable(struct sc6605_chg_device *di, bool en)
{
	int ret;

	ret = sc6605_chg_field_write(di, F_BATFET_DIS, en);
	if (ret)
		hwlog_err("[%s] F_BATFET_DIS write failed\n", __func__);

	return ret;
}

static int sc6605_buck_init(uint vset)
{
	struct sc6605_chg_device *di = g_sc6605_dev;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	switch (vset) {
	case ADAPTER_5V:
		sc6605_chg_set_vac_ovp(di, SC6605_VAC_OVP_6V5);
		break;
	case ADAPTER_9V:
		sc6605_chg_set_vac_ovp(di, SC6605_VAC_OVP_11V);
		break;
	default:
		hwlog_err("[%s] set vac ovp not match\n", __func__);
		return -EINVAL;
	}

	/* set otg curr 1A */
	sc6605_chg_set_otg_curr(di, OTG_CURRENT_1A);
	/* set wdt 80S */
	sc6605_chg_set_watchdog_timeout(di, SC8546_WTD_CONFIG_TIMING_80S);
	/* set ipre 256ma; iterm 128ma */
	sc6605_chg_set_prechg_curr(di, PRECHG_CURR_256MA);
	sc6605_chg_set_term_curr(di, TERM_CURR_128MA);
	/* todo set vindpm track disable */
	sc6605_chg_field_write(di, F_VINDPM_VBAT, false);

	return 0;
}

static int sc6605_chip_init(struct charge_init_data *init_crit)
{
	int ret;
	struct sc6605_chg_device *di = g_sc6605_dev;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s, vbus %d \n", __func__, init_crit->vbus);
	switch (init_crit->vbus) {
		case ADAPTER_5V:
			ret = sc6605_buck_init(ADAPTER_5V);
			sc6605_set_charge_mode(BUCK5V);
			break;
		case ADAPTER_9V:
			ret = sc6605_buck_init(ADAPTER_9V);
			sc6605_set_charge_mode(BUCK9V);
			break;
		default:
			hwlog_err("[%s] invaid init_crit vbus mode\n", __func__);
			break;
	}

	return ret;
}

static int sc6605_device_check(void)
{
	u8 did;
	int ret;
	struct sc6605_chg_device *di = g_sc6605_dev;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_DEVICE_ID, &did, REG_COUNT1);
	if (ret || did != SC6605_DEVICE_ID) {
		hwlog_err("[%s] device not exists\n", __func__);
		return SC6605_CHG_IC_BAD;
	}

	hwlog_info("[%s] device_check 0x%x = 0x%x\n", __func__, SC6605_REG_DEVICE_ID, did);
	return SC6605_CHG_IC_GOOD;
}

static int sc6605_stop_charge_config(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s stop_charge\n", __func__);
	ret = sc6605_chg_set_watchdog_timeout(di, SC8546_WTD_CONFIG_TIMING_DIS);
	if (ret)
		hwlog_err("[%s] WT_TIMEOUT set failed\n", __func__);

	return ret;
}

static int sc6605_set_input_current(int ma)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s  ma = %d\n", __func__, ma);
	if (ma < SC6605_BUCK_IINDPM_MIN)
		ma = SC6605_BUCK_IINDPM_MIN;

	if (ma > SC6605_BUCK_IINDPM_MAX)
		ma = SC6605_BUCK_IINDPM_MAX;

	ma = (ma - SC6605_BUCK_IINDPM_OFFSET) / SC6605_BUCK_IINDPM_STEP;
	ret = sc6605_chg_field_write(di, F_IINDPM, ma);
	if (ret)
		hwlog_err("[%s] set_input_c failed\n", __func__);

	return ret;
}

static int sc6605_set_charge_current(int ma)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s ma = %d\n", __func__, ma);
	ret = sc6605_chg_set_ichg(di, ma);
	if (ret)
		hwlog_err("[%s] set_ichg failed\n", __func__);

	return ret;
}

static int sc6605_set_terminal_voltage(int mv)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s mv = %d\n", __func__, mv);
	ret = sc6605_chg_set_term_volt(di, mv);
	if (ret)
		hwlog_err("[%s] set_term_v failed\n", __func__);

	return ret;
}

static int sc6605_set_dpm_voltage(int mv)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s mv = %d\n", __func__, mv);
	ret = sc6605_chg_set_input_volt_lmt(di, mv);
	if (ret)
		hwlog_err("[%s] set_input_v failed\n", __func__);

	return ret;
}

static int sc6605_set_terminal_current(int ma)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s ma = %d\n", __func__, ma);
	ret = sc6605_chg_set_term_curr(di, ma);
	if (ret)
		hwlog_err("[%s] set_term_c failed\n", __func__);

	return ret;
}

static int sc6605_set_charge_enable(int en)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s enable = %d\n", __func__, en);
	ret = sc6605_chg_enable(di, en);
	if (ret)
		hwlog_err("[%s] set_chg failed\n", __func__);

	return ret;
}

static int sc6605_set_otg_enable(int en)
{
	int ret;
	struct sc6605_chg_device *di = g_sc6605_dev;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s enable = %d\n", __func__, en);
	ret = sc6605_chg_request_otg(di, SC6605_NORMAL_USE_OTG, en);
	if (ret) {
		hwlog_err("[%s] request_otg failed\n", __func__);
		return ret;
	}

	if(en) {
		if(di->otg_vol >= OTG_VOL_MAX)
			sc6605_set_charge_mode(OTG9V);
		else
			sc6605_set_charge_mode(OTG5V);
	}

	return ret;
}

static int sc6605_set_vbus_vset(u32 volt)
{
	return 0;
}

static int sc6605_set_boost_current(int ma)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s ma = %d\n", __func__, ma);
	ret = sc6605_chg_set_otg_curr(di, ma);
	if (ret)
		hwlog_err("[%s] set_otg_curr failed\n", __func__);

	return ret;
}

static int sc6605_set_term_enable(int en)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s enable = %d\n", __func__, en);
	ret = sc6605_chg_field_write(di, F_TERM_EN, en);
	if (ret)
		hwlog_err("[%s] chg_set_term failed\n", __func__);

	return ret;
}

static int sc6605_get_charge_state(unsigned int *state)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_chg_field_read(di, F_CHG_STAT);
	if (ret == SC6605_CHG_STATE_TERM) {
		*state |= CHAGRE_STATE_CHRG_DONE;
	}
	hwlog_info("%s get F_CHG_STAT = %d\n", __func__, ret);

	ret = sc6605_chg_field_read(di, F_VBUS_GOOD_STAT);
	if (!ret)
		*state |= CHAGRE_STATE_NOT_PG;
	hwlog_info("%s read F_VBUS_GOOD_STAT = %d\n", __func__, ret);

	ret = sc6605_chg_field_read(di, F_FLT_WD_OUT);
	if (ret)
		*state |= CHAGRE_STATE_WDT_FAULT;
	hwlog_info("%s read F_FLT_WD_OUT = %d\n", __func__, ret);

	ret = sc6605_chg_field_read(di, F_FLT_VBUS_OVP);
	if (ret)
		*state |= CHAGRE_STATE_VBUS_OVP;
	hwlog_info("%s read F_FLT_VBUS_OVP = %d\n", __func__, ret);

	ret = sc6605_chg_field_read(di, F_FLT_VBAT_OVP);
	if (ret)
		*state |= CHAGRE_STATE_BATT_OVP;
	hwlog_info("%s read F_FLT_VBAT_OVP = %d\n", __func__, ret);

	hwlog_info("[%s] state = %u\n", __func__, *state);
	return 0;
}

static int sc6605_reset_watchdog_timer(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s \n", __func__);
	ret = sc6605_chg_kick_wd(di);
	if (ret)
		hwlog_err("[%s] chg_kick_wd failed\n", __func__);

	return ret;
}

static int sc6605_set_watchdog_timer(int s)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s time = %d\n", __func__, s);
	ret = sc6605_chg_set_watchdog_timeout(di, s * SC8546_WTD_CONFIG_TIMING_1S);
	if (ret)
		hwlog_err("[%s] set_wd_timeout failed\n", __func__);

	return ret;
}

static int sc6605_set_batfet_disable(int en)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}
	hwlog_info("%s enable = %d\n", __func__, en);
	ret = sc6605_chg_set_batfet_disable(di, en);
	if (ret)
		hwlog_err("[%s] set_batfet failed\n", __func__);

	return ret;
}

static int sc6605_set_batfet_disable_delay(int delay)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s delay = %d\n", __func__, delay);
	if (delay > 0)
		delay = BATFET_DLY_12S;
	else
		delay = BATFET_DLY_0S;

	ret = sc6605_chg_field_write(di, F_BATFET_DLY, delay);
	if (ret)
		hwlog_err("[%s] set_batfet_dis failed\n", __func__);

	return ret;
}

static int sc6605_get_ilim(void)
{
	return 0;
}

static int sc6605_get_terminal_voltage(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	uint32_t mv = 0;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_chg_field_read(di, F_VBAT);
	if (ret < 0)
		hwlog_err("[%s] get F_VBAT failed\n", __func__);

	mv = ret * SC6605_BUCK_VBAT_STEP + SC6605_BUCK_VBAT_OFFSET;
	return mv;
}

static int sc6605_get_input_current_set(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int iin;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sc6605_chg_get_input_curr_lmt(di, &iin);
	if (ret) {
		hwlog_err("[%s] get_input_curr failed\n", __func__);
		return ret;
	}

	hwlog_info("%s iin = %d\n", __func__, iin);
	return iin;
}

static int sc6605_check_charger_plugged(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;
	bool online;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	online = di->state.online;
	hwlog_info("%s online = %d\n", __func__, online);
	return online;
}

static int sc6605_check_input_dpm_state(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int vindpm;
	int iindpm;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	vindpm = sc6605_chg_field_read(di, F_VINDPM_STAT);
	iindpm = sc6605_chg_field_read(di, F_IINDPM_STAT);
	if(vindpm < 0 || iindpm < 0) {
		hwlog_err("[%s] get_iindpm failed\n", __func__);
		return -EINVAL;
	}

	hwlog_info("%s vindpm:%d iindpm:%d\n", __func__, vindpm, iindpm);
	ret = (vindpm | iindpm);
	return ret;
}

static int sc6605_check_input_vdpm_state(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int state;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	state = sc6605_chg_field_read(di, F_VINDPM_STAT);
	if (state < 0) {
		hwlog_err("[%s] get F_VINDPM_STAT failed\n", __func__);
		return state;
	}

	hwlog_info("%s state = %d\n", __func__, state);
	return state;
}

static int sc6605_check_input_idpm_state(void)
{
	int state;
	struct sc6605_chg_device *di = g_sc6605_dev;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	state = sc6605_chg_field_read(di, F_IINDPM_STAT);
	if (state < 0) {
		hwlog_err("[%s] get F_IINDPM_STAT failed\n", __func__);
		return 0;
	}

	hwlog_info("%s state = %d\n", __func__, state);
	return state;
}

static int sc6605_set_charger_hiz(int enable)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("%s enable = %d\n", __func__, enable);
	ret = sc6605_chg_field_write(di, F_PERFORMANCE_EN, enable);
	if (ret)
		hwlog_err("[%s] F_PERFORMANCE_EN write failed\n", __func__);

	return ret;
}

static int sc6605_get_charge_current(void)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ma;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ma = sc6605_chg_get_adc(di, ADC_IBAT) / DEFAULT_PERCENT;
	if (ma < 0) {
		hwlog_err("[%s] chg_get_adc failed\n", __func__);
		return 0;
	}

	hwlog_info("[%s] ma = %d\n", __func__, ma);
	return ma;
}

static int sc6605_get_vbus_mv(unsigned int *vbus_mv)
{
	struct sc6605_chg_device *di = g_sc6605_dev;

	if (!di || !vbus_mv) {
		hwlog_err("[%s] di or vbus_mv is null\n", __func__);
		return -ENOMEM;
	}
	
	*vbus_mv = (unsigned int)sc6605_chg_get_adc(di, ADC_VBUS) / DEFAULT_PERCENT;
	if (*vbus_mv < 0)
		*vbus_mv = 0;
	
	hwlog_info("[%s] vbus_mv = %d, vac_mv = %d\n", __func__, *vbus_mv,
		sc6605_chg_get_adc(di, ADC_VAC) / DEFAULT_PERCENT);
	return 0;
}

static int sc6605_set_boost_voltage(int mv)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("[%s] enable = %d\n", __func__, mv);
	ret = sc6605_chg_set_otg_volt(di, mv);
	if (ret)
		hwlog_err("[%s] set_otg_volt failed\n", __func__);

	return ret;
}

static int sc6605_set_ship_mode_enable(bool en)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("[%s] enable = %d\n", __func__, en);
	ret = sc6605_chg_set_batfet_disable(di, en);
	if (ret)
		hwlog_err("[%s] set_batfet failed\n", __func__);

	return ret;
}

static struct charge_device_ops sc6605_ops = {
	.chip_init = sc6605_chip_init,
	.dev_check = sc6605_device_check,
	.stop_charge_config = sc6605_stop_charge_config,
	.set_input_current = sc6605_set_input_current,
	.set_charge_current = sc6605_set_charge_current,
	.set_terminal_voltage = sc6605_set_terminal_voltage,
	.set_dpm_voltage = sc6605_set_dpm_voltage,
	.set_terminal_current = sc6605_set_terminal_current,
	.set_charge_enable = sc6605_set_charge_enable,
	.set_otg_enable = sc6605_set_otg_enable,
	.set_otg_current = sc6605_set_boost_current,
	.set_vbus_vset = sc6605_set_vbus_vset,
	.set_term_enable = sc6605_set_term_enable,
	.get_charge_state = sc6605_get_charge_state,
	.reset_watchdog_timer = sc6605_reset_watchdog_timer,
	.set_watchdog_timer = sc6605_set_watchdog_timer,
	.set_batfet_disable = sc6605_set_batfet_disable,
	.set_batfet_disable_delay = sc6605_set_batfet_disable_delay,
	.get_ibus = sc6605_get_ilim,
	.get_terminal_voltage = sc6605_get_terminal_voltage,
	.get_iin_set = sc6605_get_input_current_set,
	.check_charger_plugged = sc6605_check_charger_plugged,
	.check_input_dpm_state = sc6605_check_input_dpm_state,
	.check_input_vdpm_state = sc6605_check_input_vdpm_state,
	.check_input_idpm_state = sc6605_check_input_idpm_state,
	.set_charger_hiz = sc6605_set_charger_hiz,
	.get_charge_current = sc6605_get_charge_current,
	.set_boost_voltage = sc6605_set_boost_voltage,
	.get_vbus = sc6605_get_vbus_mv,
	.set_ship_mode_enable = sc6605_set_ship_mode_enable,
 };

static struct charger_otg_device_ops sc6605_otg_ops = {
	.dev_name = "sc6605",
	.otg_set_charger_enable = sc6605_set_charge_enable,
	.otg_set_enable = sc6605_set_otg_enable,
	.otg_set_current = sc6605_set_boost_current,
	.otg_set_watchdog_timer = sc6605_set_watchdog_timer,
	.otg_reset_watchdog_timer = sc6605_reset_watchdog_timer,
};

static struct power_log_ops sc6605_log_ops = {
	.dev_name = "sc6605",
	.dump_log_head = sc6605_get_register_head,
	.dump_log_content = sc6605_dump_register,
};

static void sc6605_buck_parse_dts(struct sc6605_chg_device *di, struct device_node *np)
{
	int i;
	struct dts_name_tbl buck_dts_data[] = {
		{"vsys-limit",        &(di->buck_init.vsyslim),             0},
		{"batsnc-enable",     &(di->buck_init.batsns_en),           0},
		{"vbat",              &(di->buck_init.vbat),                0},
		{"charge-curr",       &(di->buck_init.ichg),                0},
		{"iindpm-disable",    &(di->buck_init.iindpm_dis),          0},
		{"input-curr-limit",  &(di->buck_init.iindpm),              0},
		{"ico-enable",        &(di->buck_init.ico_enable),          0},
		{"iindpm-ico",        &(di->buck_init.iindpm_ico),          0},
		{"precharge-volt",    &(di->buck_init.vprechg),             0},
		{"precharge-curr",    &(di->buck_init.iprechg),             0},
		{"term-en",           &(di->buck_init.iterm_en),            0},
		{"term-curr",         &(di->buck_init.iterm),               0},
		{"rechg-dis",         &(di->buck_init.rechg_dis),           0},
		{"rechg-dg",          &(di->buck_init.rechg_dg),            0},
		{"rechg-volt",        &(di->buck_init.rechg_volt),          0},
		{"boost-voltage",     &(di->buck_init.vboost),              0},
		{"boost-max-current", &(di->buck_init.iboost),              0},
		{"conv-ocp-dis",      &(di->buck_init.conv_ocp_dis),        0},
		{"tsbat-jeita-dis",   &(di->buck_init.tsbat_jeita_dis),     0},
		{"ibat-ocp-dis",      &(di->buck_init.ibat_ocp_dis),        0},
		{"vpmid-ovp-otg-dis", &(di->buck_init.vpmid_ovp_otg_dis),   0},
		{"vbat-ovp-buck-dis", &(di->buck_init.vbat_ovp_buck_dis),   0},
		{"ibat-ocp",          &(di->buck_init.ibat_ocp),            0},
	};
	for (i = 0; i < ARRAY_SIZE(buck_dts_data); i++) {
		(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
			buck_dts_data[i].name, buck_dts_data[i].val, buck_dts_data[i].default_val);
	}
}

static void sc6605_chg_fault_handle(struct sc6605_chg_device *di)
{
	int ret;
	uint8_t chg_stat_val[3];
	uint8_t chg_flt_val[2];
	ret = regmap_bulk_read(di->rmap, SC6605_REG_CHG_INT_STAT, chg_stat_val, REG_COUNT3);
	ret |= regmap_bulk_read(di->rmap, SC6605_REG_CHG_FLT_STAT, chg_flt_val, REG_COUNT2);
	if (ret) {
		hwlog_err("[%s] Buck Flag read failed\n", __func__);
		return;
	}

	if ((chg_stat_val[1] & SC6605_CHG_DONE_DATA) == SC6605_CHG_DONE_STAT_MASK) {
		power_event_anc_notify(POWER_ANT_CHARGE_FAULT, POWER_NE_CHG_FAULT_CHARGE_DONE, NULL);
		hwlog_info("[%s] Buck Flag FAULT_CHG_DONE\n", __func__);
	} else if (chg_stat_val[2] & SC6605_TDIE_OTP_MASK) {
		power_event_anc_notify(POWER_ANT_SC_FAULT, POWER_NE_DC_FAULT_TDIE_OTP, NULL);
		hwlog_info("[%s] Buck Flag FAULT_TDIE_OTP\n", __func__);
	} else if (chg_stat_val[2] & SC6605_TBAT_OTP_MASK) {
		power_event_anc_notify(POWER_ANT_SC_FAULT, POWER_NE_DC_FAULT_TSBAT_OTP, NULL);
		hwlog_info("[%s] Buck Flag FAULT_TBAT_OTP\n", __func__);
	} else if ((chg_flt_val[0] & SC6605_REGN_OCP_MASK) || (chg_flt_val[0] & SC6605_VBAT_OVP_MASK)) {
		power_event_anc_notify(POWER_ANT_SC_FAULT, POWER_NE_DC_FAULT_IC, NULL);
		hwlog_info("[%s] Buck Flag fault IC happened\n", __func__);
	}
}

static irqreturn_t sc6605_chg_buck_interrupt_handler(int irq, void *data)
{
	struct sc6605_chg_device *di = data;
	int ret;
	uint8_t val[3];
	u32 flt, state;
	
	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_CHG_FLT_FLG, val, REG_COUNT2);
	if (ret) {
		hwlog_err("[%s] EG_CHG read failed\n", __func__);
		return ret;
	}
	flt = val[0] + (val[1] << SC6605_REG_SHIFT8);
	if (flt) {
		hwlog_err("[%s] Buck FAULT : 0x%x\n", __func__, flt);
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_CHG_INT_STAT, val, REG_COUNT3);
	if (ret) {
		hwlog_err("[%s] REG_CHG_INT read failed\n", __func__);
		return ret;
	}
	state = val[0] + (val[1] << SC6605_REG_SHIFT8) + (val[2] << SC6605_REG_SHIFT16);
	hwlog_info("[%s] irq number: %d, buck state: 0x%x\n", __func__, irq, state);

	sc6605_chg_fault_handle(di);
	di->state.boost_good = !!(state & SC6605_BUCK_FLAG_BOOST_GOOD);
	di->state.chg_state = SC6605_BUCK_GET_CHG_STATE(state);

	return IRQ_HANDLED;
}

static irqreturn_t sc6605_chg_hk_interrupt_handler(int irq, void *data)
{
	struct sc6605_chg_device *di = data;
	static int last_online = 0;
	int ret;
	uint8_t reg_val;
	uint8_t hk_flt_val;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return IRQ_HANDLED;
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_HK_FLT_FLG, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] REG_HK_FLT read failed\n", __func__);
		return IRQ_HANDLED;
	}
	if (reg_val) {
		hwlog_err("[%s] House Keeping FAULT : 0x%x\n", __func__, reg_val);

		ret = regmap_bulk_read(di->rmap, SC6605_REG_HK_FLT_STAT, &hk_flt_val, REG_COUNT1);
		hwlog_err("%s hk_flt_val: 0x%x\n", __func__, hk_flt_val);
		if ((hk_flt_val & SC6605_VBUS_OVP_MASK) || (hk_flt_val & SC6605_VAC_OVP_MASK) ||
		(hk_flt_val & SC6605_WDT_TOT)) {
			power_event_anc_notify(POWER_ANT_SC_FAULT, POWER_NE_DC_FAULT_IC, NULL);
			hwlog_err("%s House Keeping Flag fault IC happened\n", __func__);
		}

		if (reg_val & SC6605_HK_WD_TIMEOUT_MASK) {
			sc6605_chg_hw_init(di);
			return IRQ_HANDLED;
		}
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_HK_INT_STAT, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("%s read 0x%x failed, ret = %d\n", __func__, SC6605_REG_HK_INT_STAT, ret);
		return IRQ_HANDLED;
	}
	
	di->state.online = (reg_val & BIT(0)) && (reg_val & BIT(1));
	if (last_online && !di->state.online) {
		hwlog_info("[%s] !!! plug out\n", __func__);
		sc6605_set_charge_mode(UNKNOWN);
	}

	last_online = di->state.online;
	hwlog_info("[%s] House Keeping State : 0x%x\n", __func__, reg_val);

	return IRQ_HANDLED;
}

static int sc6605_chg_request_irq_thread(struct sc6605_chg_device *di)
{
	int i, ret;
	const struct {
		char *name;
		irq_handler_t hdlr;
	} sc6605_chg_chg_irqs[] = {
		{"House Keeping", sc6605_chg_hk_interrupt_handler},
		{"Buck Charger", sc6605_chg_buck_interrupt_handler},
	};

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}
	for (i = 0; i < ARRAY_SIZE(sc6605_chg_chg_irqs); i++) {
		ret = platform_get_irq_byname(to_platform_device(di->dev), sc6605_chg_chg_irqs[i].name);
		if (ret < 0) {
			hwlog_err("[%s] failed to get irq %s\n", __func__, sc6605_chg_chg_irqs[i].name);
			return ret;
		}

		di->irq[i] = ret;

		hwlog_info("[%s] %s irq = %d\n", __func__, sc6605_chg_chg_irqs[i].name, ret);
		ret = devm_request_threaded_irq(di->dev, ret, NULL, sc6605_chg_chg_irqs[i].hdlr,
			IRQF_ONESHOT, dev_name(di->dev), di);
		if (ret < 0) {
			hwlog_err("[%s] failed to request irq %s\n", __func__, sc6605_chg_chg_irqs[i].name);
			return ret;
		}

	}

	return 0;
}

static int init_ops_register(struct sc6605_chg_device *di)
{
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret = charge_ops_register(&sc6605_ops, BUCK_IC_TYPE_THIRDPARTY);
	if (ret) {
		hwlog_err("[%s] sc6605 charge ops register fail\n", __func__);
		return ret;
	}

	ret = charger_otg_ops_register(&sc6605_otg_ops);
	if (ret) {
		hwlog_err("[%s] sc6605charger_otg ops register fail\n", __func__);
		return ret;
	}

	sc6605_log_ops.dev_data = (void *)di;
	power_log_ops_register(&sc6605_log_ops);

	return 0;
}

static int sc6605_chg_enter_hides_mode(struct sc6605_chg_device *di, bool en)
{
	int ret = 0;
	int i = 0;
	uint8_t reg_val = 0;
	uint8_t buf[] = {0x44, 0x49, 0x53, 0x43, 0x4F, 0x56, 0x45, 0x52, 0x59, 0x50};

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	ret |= regmap_bulk_read(di->rmap, SC6605_REG_Internal, &reg_val, REG_COUNT1);
	if(en && (reg_val != SC6605_CHG_HIDE_REG_STATE)) {
		for (i = 0; i < ARRAY_SIZE(buf); i++) {
			ret = regmap_bulk_write(di->rmap, SC6605_REG_Internal, &buf[i], REG_COUNT1);
		}
		hwlog_info("[%s] enter hides mode\n", __func__);
	}

	if(!en && (reg_val == SC6605_CHG_HIDE_REG_STATE)) {
		for (i = 0; i < ARRAY_SIZE(buf); i++) {
			ret = regmap_bulk_write(di->rmap, SC6605_REG_Internal, &buf[i], REG_COUNT1);
		}
		hwlog_info("[%s] exit hides mode\n", __func__);
	}

	return ret;
}

static int chg_fix_led_leak_current(struct sc6605_chg_device *di)
{
	int ret = 0;
	uint8_t reg_val = 0;

	ret = sc6605_chg_enter_hides_mode(di, true);
	ret |= sc6605_chg_field_write(di, F_LED_EN, SC6605_CHG_LED_LEAK_DISABLE);

	ret |= sc6605_chg_enter_hides_mode(di, false);
	if (ret) {
		hwlog_err("[%s] led_leak failed\n", __func__);
		return ret;
	}

	reg_val = sc6605_chg_field_read(di, F_LED_EN);
	hwlog_info("[%s]  led reg state = %d\n", __func__, reg_val);
	return 0;
}

static int sc6605_charge_probe(struct platform_device *pdev)
{
	int ret;
	struct device *dev = NULL;
	struct i2c_client *i2c = NULL;
	struct sc6605_chg_device *di = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	dev = &pdev->dev;
	i2c = to_i2c_client(dev->parent);
	di = devm_kzalloc(dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_sc6605_dev = di;

	di->rmap = dev_get_regmap(dev->parent, NULL);
	if (!di->rmap) {
		hwlog_err("[%s] failed to get regmap\n", __func__);
		return -ENODEV;
	}

	di->dev = dev;
	platform_set_drvdata(pdev, di);

	sc6605_buck_parse_dts(di, dev->of_node);

	if (sc6605_device_check() == SC6605_CHG_IC_BAD) {
		hwlog_err("sc6605 not exists\n");
		ret = -EINVAL;
		goto sc6605_charge_fail_0;
	}

	ret = sc6605_chg_hw_init(di);
	if (ret) {
		hwlog_err("[%s] hw init failed\n", __func__);
		goto sc6605_charge_fail_0;
	}

	ret = init_ops_register(di);
	if (ret)
		goto sc6605_charge_fail_0;
	
	di->request_otg = 0;

	ret = sc6605_chg_request_irq_thread(di);
	if (ret < 0) {
		hwlog_err("[%s] irq request failed\n", __func__);
		goto sc6605_charge_fail_0;
	}
	ret = chg_fix_led_leak_current(di);

	sc6605_set_charge_mode(UNKNOWN);
	sc6605_chg_hk_interrupt_handler(0, di);
	sc6605_chg_buck_interrupt_handler(0, di);
	hwlog_info("[%s] success\n", __func__);
	return 0;

sc6605_charge_fail_0:
	hwlog_err("[%s] failed\n", __func__);
	return ret;
}

static int sc6605_chg_remove(struct platform_device *pdev)
{
	struct sc6605_chg_device *di = g_sc6605_dev;
	int i;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	hwlog_info("[%s] \n", __func__);
	for (i = 0; i < IRQ_MAX; i++)
		disable_irq(di->irq[i]);

	return 0;
}

static void sc6605_chg_shutdown(struct platform_device *pdev)
{
	struct sc6605_chg_device *di = g_sc6605_dev;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return;
	}

	hwlog_info("[%s] \n", __func__);
	sc6605_chg_chip_reset(di);
	chg_fix_led_leak_current(di);
}

static const struct of_device_id sc6605_chg_of_match[] = {
	{
		.compatible = "huawei,sc6605_chg",
		.data = NULL,
	},
	{},
};

static struct platform_driver sc6605_chg_driver = {
	.driver = {
		.name = "sc6605_chg",
		.of_match_table = of_match_ptr(sc6605_chg_of_match),
	},
	.probe = sc6605_charge_probe,
	.remove = sc6605_chg_remove,
	.shutdown = sc6605_chg_shutdown,
};
module_platform_driver(sc6605_chg_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("sc6605 charger module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");