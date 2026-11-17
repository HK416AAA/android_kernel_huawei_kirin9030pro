// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_log.c
 *
 * sc6605 log driver
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
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_log.h>

#define HWLOG_TAG sc6605_log
HWLOG_REGIST();

static const int sc6605_reg_range[][2] = {{0x00, 0X01}, {0x04, 0X09}, {0x0f, 0X0f}, {0x30, 0x43},
	{0x60, 0x66}, {0x90, 0x9F}};

struct chargerlog_adc_data {
	int ibus;
	int vbus;
	int ibat;
	int vusb;
	int vbat;
	int tdie;
	int tsbat;
	int vpsw;
	int vsysh;
};

struct chargerlog_data {
	struct chargerlog_adc_data adc_data;
	enum charger_mode chg_mode;
};

static void show_reg_head(char *buf, size_t str_len)
{
	int ret;
	int i, j, start, end, num;
	size_t len = 0;

	if (!buf)
		return;

	num = sizeof(sc6605_reg_range) / sizeof(sc6605_reg_range[0]);
	for (i = 0; i < num; i++) {
		start = sc6605_reg_range[i][0];
		end = sc6605_reg_range[i][1];
		for (j = start; j <= end; j++) {
			len = strlen(buf);
			ret = snprintf_s(buf + len, str_len - len, str_len - len -1, "R[0x%3x] ", j);
			if (ret < 0) {
				hwlog_err("(%s)snprintf_s fail ret = %d\n", __func__, ret);
				return;
			}
		}
	}
}

static ssize_t get_charger_head(char *buf, int str_len)
{
	int ret;

	if (!buf)
		return -EPERM;

	ret = snprintf_s(buf, str_len, str_len - 1, "%s",
		 "Mode     Ibus   Vbus   Ibat   Vusb   Vbat  Tdie  TsBat  Vpsw  Vsysh  ");
	if (ret < 0) {
		hwlog_err("(%s)snprintf_s fail ret = %d\n", __func__, ret);
		return 0;
	}

	show_reg_head(buf, str_len);

	return strlen(buf);
}

static enum charger_mode get_charge_mode(void)
{
	struct current_charger_mode *charger_mode;

	charger_mode = sc6605_get_current_charge_mode();
	if(charger_mode == NULL) {
		hwlog_err("%s charger_mode is NULL!\n", __func__);
		return -1;
	}
	charger_mode->chg_mode = sc6605_get_charge_mode();
	return charger_mode->chg_mode;
}

static void get_adc_data(struct chargerlog_adc_data *adc_data, struct sc6605_chg_device *di)
{
	if (!di || !adc_data) {
		hwlog_err("[%s] di or adc_data is null\n", __func__);
		return;
	}

	adc_data->ibus = sc6605_chg_get_adc(di, ADC_IBUS) / DEFAULT_PERCENT;
	adc_data->vbus = sc6605_chg_get_adc(di, ADC_VBUS) / DEFAULT_PERCENT;
	adc_data->ibat = sc6605_chg_get_adc(di, ADC_IBAT) / DEFAULT_PERCENT;
	adc_data->vusb = sc6605_chg_get_adc(di, ADC_VAC) / DEFAULT_PERCENT;
	adc_data->vbat = sc6605_chg_get_adc(di, ADC_VBATSNS) / DEFAULT_PERCENT;
	adc_data->tdie = sc6605_chg_get_adc(di, ADC_TDIE);
	adc_data->tsbat = 0;
	adc_data->vpsw = 0;
	adc_data->vsysh = 0;
}

static void show_chg_mode_chargerlog(char *buf, int str_len, enum charger_mode chg_mode)
{
	int ret;
	size_t len = 0;

	if (!buf)
		return;

	len = strlen(buf);
	if (chg_mode == BUCK5V)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "BUCK5V   ");
	else if (chg_mode == BUCK9V)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "BUCK9V   ");
	else if (chg_mode == SC11)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "SC11     ");
	else if (chg_mode == SC21)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "SC21     ");
	else if (chg_mode == RSC11)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "RSC11    ");
	else if (chg_mode == RSC12)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "RSC12    ");
	else if (chg_mode == OTG5V)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "OTG5V    ");
	else if (chg_mode == OTG9V)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "OTG9V    ");
	else if (chg_mode == WDRC12)
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "WDRC12   ");
	else
		ret = snprintf_s(buf + len, str_len - len, str_len - len - 1, "UNKNOWN  ");
	if (ret < 0)
		hwlog_err("[%s]snprintf_s fail, %s\n", __func__, buf);
}

static void show_adc_chargerlog(char *buf, int str_len,
	struct chargerlog_adc_data *adc_data)
{
	int ret;
	size_t len = 0;

	if (!adc_data || !buf)
		return;

	len = strlen(buf);
	ret = snprintf_s(buf + len, str_len - len, str_len -len - 1,
		"%-5d  %-5d  %-5d  %-5d  %-4d  %-4d  %-5d  %-4d  %-5d  ",
		 adc_data->ibus, adc_data->vbus, adc_data->ibat, adc_data->vusb,
		 adc_data->vbat, adc_data->tdie, adc_data->tsbat, adc_data->vpsw, adc_data->vsysh);
	if (ret < 0) {
		hwlog_err("(%s)snprintf_s fail ret = %d\n", __func__, ret);
		return;
	}
}

static void show_chargerlog(char *buf, int str_len, struct chargerlog_data *chglog_data)
{
	if (!buf || !chglog_data)
		return;

	show_chg_mode_chargerlog(buf, str_len, chglog_data->chg_mode);
	show_adc_chargerlog(buf, str_len, &chglog_data->adc_data);
}

static void show_reg_value_chargerlog(char *buf, int str_len, struct sc6605_chg_device *di)
{
	int ret;
	int i, j, start, end, num;
	size_t len = 0;
	uint8_t val = 0;

	num = sizeof(sc6605_reg_range) / sizeof(sc6605_reg_range[0]);
	for (i = 0; i < num; i++) {
		start = sc6605_reg_range[i][0];
		end = sc6605_reg_range[i][1];
		for (j = start; j <= end; j++) {
			ret = regmap_bulk_read(di->rmap, j, &val, REG_COUNT1);
			if (ret < 0) {
				hwlog_err("read 0x%x fail\n", j);
				return;
			}
			len = strlen(buf);
			ret = snprintf_s(buf + len, str_len - len, str_len - len -1, "0x%-7x", val);
			if (ret < 0) {
				hwlog_err("(%s)snprintf_s fail ret = %d\n", __func__, ret);
				return;
			}
		}
	}
}

static ssize_t sc6605_show_chargerlog(char *buf, int size, struct sc6605_chg_device *di)
{
	struct chargerlog_data chglog_data = {0};
	int str_len = size - 1;

	get_adc_data(&chglog_data.adc_data, di);
	chglog_data.chg_mode = get_charge_mode();

	show_chargerlog(buf, str_len, &chglog_data);

	show_reg_value_chargerlog(buf, str_len, di);

	return strlen(buf);
}

int sc6605_get_register_head(char *buf, int size, void *dev_data)
{
	struct sc6605_chg_device *di = dev_data;
	int str_len = size - 1;
	int err;

	if (!di || !buf)
		return -EPERM;

	err = memset_s(buf, size, 0, size);
	if (err != EOK)
		hwlog_err("[%s]memset_s fail, err=%d\n", __func__, err);
	get_charger_head(buf, str_len);

	return 0;
}

int sc6605_dump_register(char *buf, int size, void *dev_data)
{
	struct sc6605_chg_device *di = dev_data;
	int err;

	if (!di || !buf)
		return -EPERM;

	err = memset_s(buf, size, 0, size);
	if (err != EOK)
		hwlog_err("[%s]memset_s fail, err=%d\n", __func__, err);

	sc6605_show_chargerlog(buf, size, di);

	return 0;
}