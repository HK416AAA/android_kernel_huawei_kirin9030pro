// SPDX-License-Identifier: GPL-2.0
/*
 * battery_info_storage.c
 *
 * battery info storage driver
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

#include <linux/device.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/ctype.h>
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_nv.h>
#include <huawei_platform/power/batt_info_pub.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <platform_include/basicplatform/linux/power/platform/coul/battery_nvme_api.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <platform_include/basicplatform/linux/power/platform/coul/coul_drv.h>

#define HWLOG_TAG battery_info_storage
HWLOG_REGIST();

#define SOH_MIN                          1
#define SOH_MAX                          100
#define MAX_BAT_COUNT                    5
#define NV_BAT_COUNT                     3
#define BAT_COUNT                        1
#define DECIMAL_BASE                     10
#define BASE_YEAR                        2000
#define CONVERT_YEAR                     10000
#define CONVERT_MONTH                    100
#define BATTINFO_BATTERY_SN_LEN          16
#define BATTINFO_BATTERY_SN_LEN_MAX      20
#define BATTINFO_SN_BYTE_YEAR            6
#define BATTINFO_SN_BYTE_MONTH           7
#define BATTINFO_DATE_STR_LEN            9
#define BATTINFO_SCHEDULE_TIME           10000
#define BATTINFO_BUF_SIZE                64
#define RETRY_TIMES_MAX                  3
#define RES_PARA_LEN                     18
#define RES_LEN                          3

#define BATTERY_INFO_FLAG_ACT_DATE          (1 << 0)
#define BATTERY_INFO_FLAG_CYCLE             (1 << 1)
#define BATTERY_INFO_FLAG_REAL_SOH          (1 << 2)
#define BATTERY_INFO_FLAG_UI_SOH            (1 << 3)
#define BATTERY_INFO_FLAG_CHG_CNT           (1 << 4)
#define BATTERY_INFO_FLAG_PROD_DATE         (1 << 5)
#define BATTERY_INFO_FLAG_HVY_USR_SSOC_REC  (1 << 6)
#define BATTERY_INFO_FLAG_HVY_USR_VBAT_REC  (1 << 6)

#define GET_ACTIVATION_INFO_FROM_IC     (1 << 0)
#define GET_CYCLE_FROM_IC               (1 << 1)
#define GET_REAL_SOH_FROM_IC            (1 << 2)
#define GET_PROD_DATE_FROM_IC           (1 << 3)
#define GET_DISPLAY_SOH_FROM_IC         (1 << 4)

static char* g_batt_name[] = {"battery_gauge", "battery_gauge_aux", "battery_gauge_third"};

struct battery_info_storage_para {
	struct activation_info act_date;
	struct activation_info prod_date;
	u16 cycle;
	u8 real_soh;
};

struct battery_info_storage_dev {
	struct device *dev;
	struct battery_info_storage_para battery_info_para[MAX_BAT_COUNT];
	struct delayed_work bat_prod_work;
	struct delayed_work bat_nv_work;
	u32 batt_num;
	u32 storage_flags;
	u8 ui_soh;
	u16 hvy_usr_ssoc_rec;
	u16 hvy_usr_vbat_rec;
};

struct battery_date {
	u16 year;
	u8 month;
	u8 day;
};

struct battery_nv_info {
	u32 cycle;
	struct battery_date prod_date;
	struct battery_date act_date;
	u8 index;
	u8 real_soh;
	char res_para[RES_PARA_LEN];
};

#pragma pack(push, 1)
struct battery_nv {
	struct battery_nv_info info[NV_BAT_COUNT];
	u8 ui_soh;
	u16 hvy_usr_ssoc_rec;
	u16 hvy_usr_vbat_rec;
	char res[RES_LEN];
};
#pragma pack(pop)

enum battery_info_storage_sysfs_type {
	BATTERY_INFO_STORAGE_SYSFS_BEGIN = 0,
	BATTERY_INFO_STORAGE_SYSFS_BATTERY_ACT_DATE = BATTERY_INFO_STORAGE_SYSFS_BEGIN,
	BATTERY_INFO_STORAGE_SYSFS_BATTERY_PROD_DATE,
	BATTERY_INFO_STORAGE_SYSFS_BATTERY_CYCLE,
	BATTERY_INFO_STORAGE_SYSFS_REAL_SOH,
	BATTERY_INFO_STORAGE_SYSFS_CHG_CNT,
	BATTERY_INFO_STORAGE_SYSFS_UI_SOH,
	BATTERY_INFO_STORAGE_SYSFS_BATT_NUM,
	BATTERY_INFO_STORAGE_SYSFS_HVY_USR_SSOC_REC,
	BATTERY_INFO_STORAGE_SYSFS_HVY_USR_VBAT_REC,
	BATTERY_INFO_STORAGE_SYSFS_END,
};

static struct battery_info_storage_dev *g_battery_info_storage_dev;

static bool battery_or_mainboard_changed(void)
{
	if (check_battery_sn_changed()) {
		hwlog_info("battery_or_mainboard_changed return true !!\n");
		return true;
	}

	return false;
}

static u8 transform_sn_year(char sn_year)
{
	if (sn_year >= '0' && sn_year <= '9')
		return sn_year - '0';
	if (sn_year >= 'A' && sn_year < 'O')
		return sn_year - 'A' + DECIMAL_BASE;
	if (sn_year >= 'O' && sn_year < 'Z')
		return sn_year - 'A' + DECIMAL_BASE - 1;
	return 0;
}

static u8 transform_sn_month(char sn_month)
{
	if (sn_month >= '0' && sn_month <= '9')
		return sn_month - '0';
	if (sn_month >= 'A' && sn_month <= 'C')
		return sn_month - 'A' + DECIMAL_BASE;
	return 0;
}

static int fill_date(char *buf, struct activation_info *date)
{
	u32 year = date->year == 0 ? 0 : date->year + BASE_YEAR;
	u8 day = date->year && date->month;
	return snprintf_s(buf, BATTINFO_BUF_SIZE, BATTINFO_DATE_STR_LEN,
		"%04u%02u%02u\n", year, date->month, day);
}

static int get_date_from_sn(u32 i, struct activation_info *prod_date)
{
	char batt_sn[BATTINFO_BATTERY_SN_LEN_MAX] = { 0 };
	u32 sn_len = 0;
	u32 buff_size = BATTINFO_BATTERY_SN_LEN_MAX;
	int ret;

	ret = get_battery_sn_by_id(i, batt_sn, buff_size, &sn_len);
	if ((sn_len < BATTINFO_BATTERY_SN_LEN) || ret) {
		hwlog_info("batt%u get sn fail\n", i);
		return -ENODEV;
	}
	prod_date->year = transform_sn_year(batt_sn[BATTINFO_SN_BYTE_YEAR]);
	prod_date->month = transform_sn_month(batt_sn[BATTINFO_SN_BYTE_MONTH]);
	return 0;
}

static int get_each_battery_prod_date(u32 battery_id, struct battery_info_storage_para *info,
	struct battery_info_storage_dev *di)
{
	int ret = get_date_from_sn(battery_id, &info->prod_date);
	if (ret) {
		hwlog_info("get date failed for battery %u\n", battery_id);
		return ret;
	}
	di->battery_info_para[battery_id].prod_date = info->prod_date;
	hwlog_info("Battery %d Production Date: %04u-%02u\n", battery_id,
			di->battery_info_para[battery_id].prod_date.year,
			di->battery_info_para[battery_id].prod_date.month);	
	return 0;
}

static int get_prod_date_from_sn_info(struct battery_info_storage_dev *di)
{
	u32 i;
	struct battery_info_storage_para battery_info_p[MAX_BAT_COUNT] = { 0 };	
	int ret = 0;

	for (i = 0; i < di->batt_num; i++) {		
		ret += get_each_battery_prod_date(i, &battery_info_p[i], di);
	}
	return ret;
}

static int get_and_save_activation_info(u32 battery_id, struct battery_info_storage_para *info,
	struct battery_info_storage_dev *di, int *flags)
{
	int ret = get_battery_activation_info_by_id(battery_id, &info->act_date);
	if (ret) {
		hwlog_info("get activation failed for battery %u\n", battery_id);
		return ret;
	}
	di->battery_info_para[battery_id].act_date = info->act_date;
	*flags |= GET_ACTIVATION_INFO_FROM_IC;
	return 0;
}

static int get_and_save_cycle(u32 battery_id, struct battery_info_storage_para *info,
	struct battery_info_storage_dev *di, int *flags)
{
	int ret = get_battery_cycle_by_id(battery_id, &info->cycle);
	if (ret) {
		hwlog_info("get cycle failed for battery %u\n", battery_id);
		return ret;
	}
	di->battery_info_para[battery_id].cycle = info->cycle;
	*flags |= GET_CYCLE_FROM_IC;
	return 0;
}

static int get_and_save_real_soh(u32 battery_id, struct battery_info_storage_para *info,
	struct battery_info_storage_dev *di, int *flags)
{
	int ret = get_battery_real_soh_by_id(battery_id, &info->real_soh);
	if (ret) {
		hwlog_info("get real_soh failed for battery %u\n", battery_id);
		return ret;
	}
	di->battery_info_para[battery_id].real_soh = info->real_soh;
	*flags |= GET_REAL_SOH_FROM_IC;
	return 0;
}

static int get_and_save_prod_date(u32 battery_id, struct battery_info_storage_para *info,
	struct battery_info_storage_dev *di, int *flags)
{
	int ret = get_date_from_sn(battery_id, &info->prod_date);
	if (ret) {
		hwlog_info("get date failed for battery %u\n", battery_id);
		return ret;
	}
	di->battery_info_para[battery_id].prod_date = info->prod_date;
	*flags |= GET_PROD_DATE_FROM_IC;
	return 0;
}

static int get_cycle_from_power_supply(int *cycle, int index)
{
	int ret;

	if (index >= ARRAY_SIZE(g_batt_name)) {
		hwlog_err("index is invalid\n");
		return -EINVAL;
	}

	ret = power_supply_get_int_property_value(g_batt_name[index], POWER_SUPPLY_PROP_CYCLE_COUNT, cycle);
	return ret;
}

static int get_and_save_display_soh(u8 *ui_soh_p, struct battery_info_storage_dev *di, int *flags)
{
	int ret = get_battery_display_soh(ui_soh_p);
	if (ret) {
		hwlog_info("get_battery_display_soh failed\n");
		return ret;
	}
	di->ui_soh = *ui_soh_p;
	*flags |= GET_DISPLAY_SOH_FROM_IC;
	return 0;
}

static void get_data_from_nv(struct battery_info_storage_dev *di, struct battery_nv *nv_data)
{
	int cycle;
	int ret;
	u32 i;

	for (i = 0; i < di->batt_num; i++) {
		cycle = 0;
		ret = get_cycle_from_power_supply(&cycle, i);
		if (!ret) {
			nv_data->info[i].cycle = cycle;
			di->battery_info_para[i].cycle = cycle;
		} else {
			di->battery_info_para[i].cycle = nv_data->info[i].cycle;
		}

		di->battery_info_para[i].act_date.year = nv_data->info[i].act_date.year;
		di->battery_info_para[i].act_date.month = nv_data->info[i].act_date.month;

		di->battery_info_para[i].real_soh = nv_data->info[i].real_soh;

		ret = get_prod_date_from_sn_info(di);

		if (!ret) {
			nv_data->info[i].prod_date.year = di->battery_info_para[i].prod_date.year;
			nv_data->info[i].prod_date.month = di->battery_info_para[i].prod_date.month;
			hwlog_info("get prod date from sn info success !!\n");
		} else {			
			di->battery_info_para[i].prod_date.year = nv_data->info[i].prod_date.year;
			di->battery_info_para[i].prod_date.month = nv_data->info[i].prod_date.month;
			hwlog_err("get prod date from sn info failed !!\n");
		}
	}
	di->ui_soh = nv_data->ui_soh;
	di->hvy_usr_ssoc_rec = nv_data->hvy_usr_ssoc_rec;
	di->hvy_usr_vbat_rec = nv_data->hvy_usr_vbat_rec;
}

static void store_data_from_ic_or_nv(struct battery_info_storage_dev *di, struct battery_nv *nv_data, int flags)
{
	int cycle;
	int ret;
	u32 i;

	for (i = 0; i < di->batt_num; i++) {
		if (flags & GET_ACTIVATION_INFO_FROM_IC) {
			nv_data->info[i].act_date.year = di->battery_info_para[i].act_date.year;
			nv_data->info[i].act_date.month = di->battery_info_para[i].act_date.month;
			nv_data->info[i].act_date.day = 0;
		} else {
			di->battery_info_para[i].act_date.year = nv_data->info[i].act_date.year;
			di->battery_info_para[i].act_date.month = nv_data->info[i].act_date.month;
		}

		cycle = 0;
		ret = get_cycle_from_power_supply(&cycle, i);
		if (!ret) {
			nv_data->info[i].cycle = cycle;
			di->battery_info_para[i].cycle = cycle;
		} else {
			di->battery_info_para[i].cycle = nv_data->info[i].cycle;
		}

		if (flags & GET_REAL_SOH_FROM_IC)
			nv_data->info[i].real_soh = di->battery_info_para[i].real_soh;
		else
			di->battery_info_para[i].real_soh = nv_data->info[i].real_soh;

		if (flags & GET_PROD_DATE_FROM_IC) {
			nv_data->info[i].prod_date.year = di->battery_info_para[i].prod_date.year;
			nv_data->info[i].prod_date.month = di->battery_info_para[i].prod_date.month;
			nv_data->info[i].prod_date.day = 0;
		} else {
			di->battery_info_para[i].prod_date.year = nv_data->info[i].prod_date.year;
			di->battery_info_para[i].prod_date.month = nv_data->info[i].prod_date.month;
		}
	}

	if (flags & GET_DISPLAY_SOH_FROM_IC)
		nv_data->ui_soh = di->ui_soh;
	else
		di->ui_soh = nv_data->ui_soh;
}

static int get_batt_info_from_ic(struct battery_info_storage_dev *di, int *flags)
{
	u32 i;
	struct battery_info_storage_para battery_info_p[MAX_BAT_COUNT] = { 0 };
	u8 ui_soh_p = 0;
	int ret = 0;

	for (i = 0; i < di->batt_num; i++) {
		ret += get_and_save_activation_info(i, &battery_info_p[i], di, flags);
		ret += get_and_save_cycle(i, &battery_info_p[i], di, flags);
		ret += get_and_save_real_soh(i, &battery_info_p[i], di, flags);
		ret += get_and_save_prod_date(i, &battery_info_p[i], di, flags);
	}
	ret += get_and_save_display_soh(&ui_soh_p, di, flags);
	return ret;
}

static void batt_info_storage_work(struct work_struct *work)
{
	int err_flag = 0;
	int ret_from_ic = 1;
	int ret_from_nv = 1;
	int flags = 0;
	struct battery_nv nv_data = { 0 };
	struct battery_info_storage_dev *di =
		container_of(work, struct battery_info_storage_dev, bat_prod_work.work);
	if (!di)
		return;

	if (di->batt_num > MAX_BAT_COUNT || di->batt_num > NV_BAT_COUNT) {
		hwlog_err("batt_num: %d,out of range !!\n", di->batt_num);
		return;
	}

	do {
		if (ret_from_nv)
			ret_from_nv = power_nv_read(POWER_NV_BATTINFO, &nv_data, sizeof(nv_data));

		if (ret_from_ic)
			ret_from_ic = get_batt_info_from_ic(di, &flags);

		if (!ret_from_nv && !ret_from_ic)
			break;
	} while (++err_flag < RETRY_TIMES_MAX);

	if (err_flag == RETRY_TIMES_MAX) {
		hwlog_info("retry_times over %d\n", err_flag);
	}

	if (battery_or_mainboard_changed()) {
		store_data_from_ic_or_nv(di, &nv_data, flags);
	} else {
		get_data_from_nv(di, &nv_data);
	}

	if (power_nv_write(POWER_NV_BATTINFO, &nv_data, sizeof(nv_data))) {
		hwlog_info("power_nv_write fail !!\n");
		return;
	}
	hwlog_info("power_nv_write sucess !!\n");
}

#ifdef CONFIG_SYSFS
static ssize_t battery_info_storage_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);
static ssize_t battery_info_storage_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info battery_info_storage_sysfs_field_tbl[] = {
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_BATTERY_ACT_DATE, batt_act_date),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_BATTERY_PROD_DATE, batt_prod_date),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_BATTERY_CYCLE, cycle),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_REAL_SOH, real_soh),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_UI_SOH, ui_soh),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_BATT_NUM, batt_num),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_CHG_CNT, chg_cnt),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_HVY_USR_SSOC_REC, hvy_usr_ssoc_rec),
	power_sysfs_attr_rw(battery_info_storage, 0644,
		BATTERY_INFO_STORAGE_SYSFS_HVY_USR_VBAT_REC, hvy_usr_vbat_rec),
};

#define BATTERY_INFO_STORAGE_SYSFS_ATTRS_SIZE ARRAY_SIZE(battery_info_storage_sysfs_field_tbl)

static struct attribute *battery_info_storage_sysfs_attrs[BATTERY_INFO_STORAGE_SYSFS_ATTRS_SIZE + 1];

static const struct attribute_group battery_info_storage_sysfs_attr_group = {
	.attrs = battery_info_storage_sysfs_attrs,
};

static int battery_info_show_act_date(struct battery_info_storage_dev *di, char *buf)
{
	int ret = 0;
	u32 i;

	for (i = 0; i < di->batt_num; i++) {
		ret += fill_date(buf + ret, &di->battery_info_para[i].act_date);
		hwlog_info("Battery %u Active Date: %04u-%02u\n", i,
			di->battery_info_para[i].act_date.year,
			di->battery_info_para[i].act_date.month);
	}
	return ret;
}

static int battery_info_show_prod_date(struct battery_info_storage_dev *di, char *buf)
{
	int ret = 0;
	u32 i;

	get_prod_date_from_sn_info(di);
	for (i = 0; i < di->batt_num; i++) {
		ret += fill_date(buf + ret, &di->battery_info_para[i].prod_date);
		hwlog_info("Battery %u Production Date: %04u-%02u\n", i,
			di->battery_info_para[i].prod_date.year,
			di->battery_info_para[i].prod_date.month);
	}
	return ret;
}

static int battery_info_show_cycle(struct battery_info_storage_dev *di, char *buf)
{
	int ret = 0;
	int ret_from_psy = 0;
	int cycle = 0;
	u32 i;

	for (i = 0; i < di->batt_num; i++) {
		ret_from_psy = get_cycle_from_power_supply(&cycle, i);
		hwlog_info("Battery %u Cycle: %d\n", i, di->battery_info_para[i].cycle);

		if (!ret_from_psy) {
			di->battery_info_para[i].cycle = cycle;
			hwlog_info("Battery %u Cycle: %d\n", i, di->battery_info_para[i].cycle);
		}

		ret += snprintf_s(buf + ret, BATTINFO_BUF_SIZE - ret,
			BATTINFO_BUF_SIZE - ret - 1, "%d\n", di->battery_info_para[i].cycle);
		hwlog_info("Battery %u Cycle: %d\n", i, di->battery_info_para[i].cycle);
	}
	return ret;
}

static int battery_info_show_real_soh(struct battery_info_storage_dev *di, char *buf)
{
	int ret = 0;
	u32 i;

	for (i = 0; i < di->batt_num; i++) {
		ret += snprintf_s(buf + ret, BATTINFO_BUF_SIZE - ret,
			BATTINFO_BUF_SIZE - ret - 1, "%d\n", di->battery_info_para[i].real_soh);
		hwlog_info("Battery %u Real SOH: %d\n", i, di->battery_info_para[i].real_soh);
	}
	return ret;
}

static ssize_t battery_info_storage_sysfs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;
	struct battery_info_storage_dev *di = dev_get_drvdata(dev);
	int ret = 0;

	if (!di)
		return -ENODEV;

	if (di->batt_num > MAX_BAT_COUNT || di->batt_num > NV_BAT_COUNT) {
		hwlog_err("batt_num: %d,out of range !!\n", di->batt_num);
		return -EINVAL;
	}

	info = power_sysfs_lookup_attr(attr->attr.name,
		battery_info_storage_sysfs_field_tbl, BATTERY_INFO_STORAGE_SYSFS_ATTRS_SIZE);
	if (!info)
		return -ENODEV;

	switch (info->name) {
		case BATTERY_INFO_STORAGE_SYSFS_BATTERY_ACT_DATE:
			ret = battery_info_show_act_date(di, buf);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_BATTERY_PROD_DATE:
			ret = battery_info_show_prod_date(di, buf);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_BATTERY_CYCLE:
			ret = battery_info_show_cycle(di, buf);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_REAL_SOH:
			ret = battery_info_show_real_soh(di, buf);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_UI_SOH:
			ret = snprintf_s(buf, BATTINFO_BUF_SIZE, BATTINFO_BUF_SIZE - 1, "%d\n", di->ui_soh);
			hwlog_info("UI SOH: %d\n", di->ui_soh);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_BATT_NUM:
			ret = snprintf_s(buf, BATTINFO_BUF_SIZE, BATTINFO_BUF_SIZE - 1, "%d\n", di->batt_num);
			hwlog_info("BATT NUM: %d\n", di->batt_num);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_CHG_CNT:
			ret = snprintf_s(buf, BATTINFO_BUF_SIZE, BATTINFO_BUF_SIZE - 1, "%d\n", 0);
			hwlog_info("CHARGE CNT: %d\n", 0);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_HVY_USR_SSOC_REC:
			ret = snprintf_s(buf, BATTINFO_BUF_SIZE, BATTINFO_BUF_SIZE - 1, "%d\n", di->hvy_usr_ssoc_rec);
			break;
		case BATTERY_INFO_STORAGE_SYSFS_HVY_USR_VBAT_REC:
			ret = snprintf_s(buf, BATTINFO_BUF_SIZE, BATTINFO_BUF_SIZE - 1, "%d\n", di->hvy_usr_vbat_rec);
			break;
		default:
			break;
	}
	return ret;
}

static int battery_info_storage_parse_id(const char *buf, int *id, long *val)
{
	char input[BATTINFO_BUF_SIZE] = {0};
	char *space_pos = NULL;

	if (!buf)
		return -EINVAL;
	if (snprintf_s(input, BATTINFO_BUF_SIZE, BATTINFO_BUF_SIZE - 1, "%s", buf) < 0)
		return -EINVAL;

	space_pos = strchr(input, ' ');
	if (space_pos != NULL) {
		*space_pos = '\0';
		if (kstrtoint(input, POWER_BASE_DEC, id))
			return -EINVAL;
		return kstrtol(space_pos + 1, DECIMAL_BASE, val);
	} else {
		*id = -1;
		return kstrtol(input, DECIMAL_BASE, val);
	}
}

static void battery_info_storage_send_chg_cnt_clear(void)
{
	struct power_event_notify_data n_data;

	n_data.event = "BMS_EVT=CLEAR_DATA";
	n_data.event_len = 18; /* length of BMS_EVT=CLEAR_DATA */
	power_event_report_uevent(&n_data);
	hwlog_info("CLEAR_DATA, report uevent\n");
}

static void battery_info_act_date_store(struct battery_info_storage_dev *di,
	struct activation_info act_date, u32 start, u32 end, long val)
{
	act_date.year = (val / CONVERT_YEAR - BASE_YEAR) < 0 ? 0 : (val / CONVERT_YEAR - BASE_YEAR);
	act_date.month = (val / CONVERT_MONTH) % CONVERT_MONTH;
	for (; start < end; start++) {
		if (!val || !(di->battery_info_para[start].act_date.year +
			di->battery_info_para[start].act_date.month)) {
			di->battery_info_para[start].act_date = act_date;
		}
	}
}

static void battery_info_storage_batt_cycle_clear(void)
{
	if (power_platform_is_smart_battery())
		coul_drv_battery_cycle_clear();

	batt_nv_cycle_clear_all();
}

static int battery_info_storage_update_nv(struct battery_info_storage_dev *di)
{
	u32 i;
	int err_flag = 0;
	int ret;
	struct battery_nv nv_data = { 0 };
	bool is_clear_cycle = false;

	do {
		ret = power_nv_read(POWER_NV_BATTINFO, &nv_data, sizeof(nv_data));
		if (!ret)
			break;
		hwlog_info("power_nv_read fail\n");
	} while (++err_flag < RETRY_TIMES_MAX);
	if (ret != 0) {
		hwlog_info("power_nv_read fail\n");
		return -EINVAL;
	}

	for (i = 0; i < di->batt_num; i++) {
		if (di->storage_flags & BATTERY_INFO_FLAG_ACT_DATE) {
			if ((nv_data.info[i].act_date.year == 0 && nv_data.info[i].act_date.month == 0) ||
				(di->battery_info_para[i].act_date.year == 0 && di->battery_info_para[i].act_date.month == 0)) {
				nv_data.info[i].act_date.year = di->battery_info_para[i].act_date.year;
				nv_data.info[i].act_date.month = di->battery_info_para[i].act_date.month;
			}
			nv_data.info[i].act_date.day = 0;
		}
		if (di->storage_flags & BATTERY_INFO_FLAG_CYCLE) {
			if (di->battery_info_para[i].cycle == 0 && !is_clear_cycle) {
				battery_info_storage_batt_cycle_clear();
				is_clear_cycle = true;
				hwlog_info("clear cycle all in storage suc\n");
			}
			nv_data.info[i].cycle = di->battery_info_para[i].cycle;
		}

		if (di->storage_flags & BATTERY_INFO_FLAG_REAL_SOH)
			nv_data.info[i].real_soh = di->battery_info_para[i].real_soh;
	}

	if (di->storage_flags & BATTERY_INFO_FLAG_UI_SOH)
		nv_data.ui_soh = di->ui_soh;
	if (di->storage_flags & BATTERY_INFO_FLAG_HVY_USR_SSOC_REC)
		nv_data.hvy_usr_ssoc_rec = di->hvy_usr_ssoc_rec;
	if (di->storage_flags & BATTERY_INFO_FLAG_HVY_USR_VBAT_REC)
		nv_data.hvy_usr_vbat_rec = di->hvy_usr_vbat_rec;

	ret = power_nv_write(POWER_NV_BATTINFO, &nv_data, sizeof(nv_data));
	if (ret != 0) {
		hwlog_info("power_nv_write fail\n");
		return -EINVAL;
	}
	return 0;
}

static void store_activation_date(struct battery_info_storage_dev *di,
	struct activation_info *act_date, u32 start, u32 end, long val)
{
	battery_info_act_date_store(di, *act_date, start, end, val);
	hwlog_info("Storing activation date for battery %d to %d with value %ld\n", start, end, val);
	di->storage_flags |= BATTERY_INFO_FLAG_ACT_DATE;
	return;
}

static void store_cycle_count(struct battery_info_storage_dev *di, u32 start, u32 end, long val)
{
	hwlog_info("Storing cycle count for battery %d to %d with value %ld\n", start, end, val);
	for (; start < end; start++) {
		di->battery_info_para[start].cycle = val;
	}
	di->storage_flags |= BATTERY_INFO_FLAG_CYCLE;
	return;
}

static int store_real_soh(struct battery_info_storage_dev *di, u32 start, u32 end, long val)
{
	if ((val < SOH_MIN) || (val > SOH_MAX)) {
		hwlog_err("val out of range\n");
		return -EINVAL;
	}

	hwlog_info("Storing real SOH for battery %d to %d with value %ld\n", start, end, val);
	for (; start < end; start++) {
		di->battery_info_para[start].real_soh = val;
	}
	di->storage_flags |= BATTERY_INFO_FLAG_REAL_SOH;
	return 0;
}

static int store_ui_soh(struct battery_info_storage_dev *di, long val)
{
	if ((val < SOH_MIN) || (val > SOH_MAX)) {
		hwlog_err("val out of range\n");
		return -EINVAL;
	}
	hwlog_info("Storing UI SOH with value %ld\n", val);
	di->ui_soh = val;
	di->storage_flags |= BATTERY_INFO_FLAG_UI_SOH;
	return 0;
}

static int store_hvy_usr_ssoc_rec(struct battery_info_storage_dev *di, long val)
{
	hwlog_info("Storing heavy user ssoc record with value %ld\n", val);
	di->hvy_usr_ssoc_rec = (u16)val;
	di->storage_flags |= BATTERY_INFO_FLAG_HVY_USR_SSOC_REC;
	return 0;
}

static int store_hvy_usr_vbat_rec(struct battery_info_storage_dev *di, long val)
{
	hwlog_info("Storing heavy user vbat record with value %ld\n", val);
	di->hvy_usr_vbat_rec = (u16)val;
	di->storage_flags |= BATTERY_INFO_FLAG_HVY_USR_VBAT_REC;
	return 0;
}

static void clear_charge_count(struct battery_info_storage_dev *di)
{
	battery_info_storage_send_chg_cnt_clear();
	hwlog_info("Clearing charge count\n");
	di->storage_flags |= BATTERY_INFO_FLAG_CHG_CNT;
	return;
}

static void batt_info_nv_work(struct work_struct *work)
{
	int ret = 0;
	struct battery_info_storage_dev *di =
		container_of(work, struct battery_info_storage_dev, bat_nv_work.work);
	if (!di)
		return;

	if (di->batt_num > MAX_BAT_COUNT || di->batt_num > NV_BAT_COUNT) {
		hwlog_err("batt_num: %d,out of range !!\n", di->batt_num);
		return;
	}
	ret = battery_info_storage_update_nv(di);
	if (ret)
		hwlog_info("power_nv_write fail !!!\n");
	else
		hwlog_info("power_nv_write success !!!\n");
}

static ssize_t battery_info_storage_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct power_sysfs_attr_info *info = NULL;
	struct battery_info_storage_dev *di = dev_get_drvdata(dev);
	long val = 0;
	int buf_id = -1;
	u32 start, end;
	struct activation_info act_date = {0};
	int ret = 0;

	if (di->batt_num > MAX_BAT_COUNT || di->batt_num > NV_BAT_COUNT) {
		hwlog_err("batt_num: %d,out of range !!\n", di->batt_num);
		return -EINVAL;
	}

	info = power_sysfs_lookup_attr(attr->attr.name,
		battery_info_storage_sysfs_field_tbl, BATTERY_INFO_STORAGE_SYSFS_ATTRS_SIZE);
	if (!info || !di)
		return -EINVAL;

	if (battery_info_storage_parse_id(buf, &buf_id, &val))
		return -EINVAL;

	start = buf_id < 0 ? 0 : buf_id;
	end = buf_id < 0 ? di->batt_num : (start + 1);
	switch (info->name) {
	case BATTERY_INFO_STORAGE_SYSFS_BATTERY_ACT_DATE:
		store_activation_date(di, &act_date, start, end, val);
		break;
	case BATTERY_INFO_STORAGE_SYSFS_BATTERY_CYCLE:
		store_cycle_count(di, start, end, val);
		break;
	case BATTERY_INFO_STORAGE_SYSFS_REAL_SOH:
		ret = store_real_soh(di, start, end, val);
		break;
	case BATTERY_INFO_STORAGE_SYSFS_UI_SOH:
		ret = store_ui_soh(di, val);
		break;
	case BATTERY_INFO_STORAGE_SYSFS_CHG_CNT:
		clear_charge_count(di);
		break;
	case BATTERY_INFO_STORAGE_SYSFS_HVY_USR_SSOC_REC:
		ret = store_hvy_usr_ssoc_rec(di, val);
		break;
	case BATTERY_INFO_STORAGE_SYSFS_HVY_USR_VBAT_REC:
		ret = store_hvy_usr_vbat_rec(di, val);
		break;
	default:
		break;
	}

	if (ret)
		return ret;

	schedule_delayed_work(&di->bat_nv_work, msecs_to_jiffies(0));

	return count;
}

static void battery_info_storage_sysfs_create_group(struct device *dev)
{
	power_sysfs_init_attrs(battery_info_storage_sysfs_attrs,
		battery_info_storage_sysfs_field_tbl, BATTERY_INFO_STORAGE_SYSFS_ATTRS_SIZE);
	power_sysfs_create_link_group("hw_power", "battery", "battery_info_storage",
		dev, &battery_info_storage_sysfs_attr_group);
}

static void battery_info_storage_sysfs_remove_group(struct device *dev)
{
	power_sysfs_remove_link_group("hw_power", "battery", "battery_info_storage",
		dev, &battery_info_storage_sysfs_attr_group);
}
#else
static inline void battery_info_storage_sysfs_create_group(struct device *dev)
{
}

static inline void battery_info_storage_sysfs_remove_group(struct device *dev)
{
}

static inline void batt_info_nv_work(struct work_struct *work)
{
}
#endif /* CONFIG_SYSFS */

static int battery_info_storage_probe(struct platform_device *pdev)
{
	struct battery_info_storage_dev *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;
	di->storage_flags = 0;
	np = di->dev->of_node;

	power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "batt_num", &(di->batt_num), BAT_COUNT);
	INIT_DELAYED_WORK(&di->bat_prod_work, batt_info_storage_work);
	INIT_DELAYED_WORK(&di->bat_nv_work, batt_info_nv_work);
	battery_info_storage_sysfs_create_group(di->dev);
	platform_set_drvdata(pdev, di);
	g_battery_info_storage_dev = di;

	schedule_delayed_work(&di->bat_prod_work, msecs_to_jiffies(BATTINFO_SCHEDULE_TIME));
	return 0;
}

static int battery_info_storage_remove(struct platform_device *pdev)
{
	struct battery_info_storage_dev *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;
	cancel_delayed_work(&di->bat_prod_work);
	battery_info_storage_sysfs_remove_group(di->dev);
	devm_kfree(&pdev->dev, di);
	g_battery_info_storage_dev = NULL;
	platform_set_drvdata(pdev, NULL);
	return 0;
}

static const struct of_device_id battery_info_storage_match_table[] = {
	{
		.compatible = "huawei,battery_info_storage",
		.data = NULL,
	},
	{},
};

static struct platform_driver battery_info_storage_driver = {
	.probe = battery_info_storage_probe,
	.remove = battery_info_storage_remove,
	.driver = {
		.name = "huawei,battery_info_storage",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(battery_info_storage_match_table),
	},
};
module_platform_driver(battery_info_storage_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("battery info storage driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
