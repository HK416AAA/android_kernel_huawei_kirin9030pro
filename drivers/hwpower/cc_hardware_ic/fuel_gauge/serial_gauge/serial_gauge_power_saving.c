// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge_power_saving.c
 *
 * Intelligent power protection driver
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

#include "serial_gauge_power_saving.h"

#include <linux/reboot.h>
#include <linux/suspend.h>
#include <linux/timer.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#ifdef CONFIG_DKMD_DKSM
#include <platform_include/display/dkmd/dkmd_notify.h>
#endif

#define HWLOG_TAG serial_gauge_power_saving
HWLOG_REGIST();

#define SERIAL_GAUGE_HW_VERSION_DATA_LEN 7
#define SERIAL_GAUGE_CMD_LEN_ONLY_SUB 3
#define SERIAL_GAUGE_HW_VERSION_LEN 4
#define POWER_SAVING_SUB_CMD_INDEX 1

static u32 ipsStatusTimeList[SOC_SYS_STATUS_END] = {
	POWER_SAVING_DELAY_TIME_5MIN, POWER_SAVING_DELAY_TIME_5MIN, POWER_SAVING_DELAY_TIME_5MIN
};

static int serial_gauge_sub_cmd_verify(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	u16 data_sub_cmd = (u16)data[SERIAL_GAUGE_FW_SUB_CMD_INDEX] |
		(u16)(data[SERIAL_GAUGE_FW_SUB_CMD_INDEX + 1] <<
		SERIAL_GAUGE_FW_SINGLE_BIT_LEN);
	u16 sub_cmd = (u16)buf[SERIAL_GAUGE_FW_SUB_CMD_INDEX] |
		(u16)(buf[SERIAL_GAUGE_FW_SUB_CMD_INDEX + 1] <<
		SERIAL_GAUGE_FW_SINGLE_BIT_LEN);

	hwlog_info("%s buf: sub_cmd = 0x%x, data: sub_cmd = 0x%x\n",
		__func__, sub_cmd, data_sub_cmd);
	if (data_sub_cmd == sub_cmd)
		return SERIAL_GAUGE_SUCCESS;

	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_single_cmd_operation(struct serial_gauge_device *di, u8 *buf,
	u8 buf_len, u8 *data, u8 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_FW_REG, buf, buf_len);
		if (ret) {
			hwlog_err("%s retry[%d] write buf fail, ret = %d\n",
				__func__, retry, ret);
			goto cmd_failed;
		}

		ret = serial_gauge_read_block(SERIAL_GAUGE_FW_REG, data, data_len);
		if (ret) {
			hwlog_err("%s retry[%d] read block ret = %d\n",
				__func__, retry, ret);
			goto cmd_failed;
		}

		if (!serial_gauge_sub_cmd_verify(buf, buf_len, data, data_len))
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("%s retry[%d] read data fail\n", __func__, retry);
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_bat_param_only_write(struct serial_gauge_device *di, u8 *buf,
	u8 buf_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_FW_REG, buf, buf_len);
		hwlog_info("%s write block sub_cmd = 0x%x %x, ret = %d\n", __func__,
			buf[SERIAL_GAUGE_FW_SUB_CMD_INDEX + 1], buf[SERIAL_GAUGE_FW_SUB_CMD_INDEX], ret);
		if (!ret)
			return SERIAL_GAUGE_SUCCESS;

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_info("%s write block sub_cmd = 0x%x %x, ret = %d\n", __func__,
		buf[SERIAL_GAUGE_FW_SUB_CMD_INDEX + 1], buf[SERIAL_GAUGE_FW_SUB_CMD_INDEX], ret);
	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_write_rtc_time2coul(struct serial_gauge_device *di, struct rtc_time *tm)
{
	int ret;
	int idx = 0;
	u8 rtc_time[SERIAL_GAUGE_FW_WRITE_RTC_LEN + 1] = { 0 };

	rtc_time[idx++] = SERIAL_GAUGE_FW_WRITE_RTC_LEN;
	rtc_time[idx++] = (u8)(SERIAL_GAUGE_FW_SUB_CMD_WRITE_RTC & SERIAL_GAUGE_FW_SINGLE_BIT_MASK);
	rtc_time[idx++] = (u8)(SERIAL_GAUGE_FW_SUB_CMD_WRITE_RTC >> SERIAL_GAUGE_FW_SINGLE_BIT_LEN);
	rtc_time[idx++] = tm->tm_year;
	rtc_time[idx++] = tm->tm_mon;
	rtc_time[idx++] = tm->tm_mday;
	rtc_time[idx++] = tm->tm_hour;
	rtc_time[idx++] = tm->tm_min;
	rtc_time[idx++] = tm->tm_sec;

	ret = serial_gauge_bat_param_only_write(di, rtc_time, SERIAL_GAUGE_FW_WRITE_RTC_LEN + 1);
	if (ret) {
		hwlog_err("write time to serial_gauge err\n");
		return ret;
	}
	hwlog_info("write time to serial_gauge succeed\n");
	return SERIAL_GAUGE_SUCCESS;
}

static int serial_gauge_read_rtc_time_from_coul(struct serial_gauge_device *di, struct rtc_time *tm)
{
	int ret;
	u8 buf[SERIAL_GAUGE_FW_READ_RTC_1_LEN + 1] = { SERIAL_GAUGE_FW_READ_RTC_1_LEN,
		(u8)(SERIAL_GAUGE_FW_SUB_CMD_READ_RTC & SERIAL_GAUGE_FW_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_FW_SUB_CMD_READ_RTC >> SERIAL_GAUGE_FW_SINGLE_BIT_LEN),
		SERIAL_GAUGE_FW_READ_RTC_FORMAT_HEX };
	u8 rtc_time[SERIAL_GAUGE_FW_READ_RTC_2_LEN + 1] = { 0 };
	int idx = SERIAL_GAUGE_FW_RTC_DATA_INDEX;

	ret = serial_gauge_single_cmd_operation(di, buf, SERIAL_GAUGE_FW_READ_RTC_1_LEN + 1,
		rtc_time, SERIAL_GAUGE_FW_READ_RTC_2_LEN + 1);
	if (ret) {
		hwlog_err("read time from serial_gauge err\n");
		return ret;
	}

	tm->tm_year = rtc_time[idx++];
	tm->tm_mon = rtc_time[idx++];
	tm->tm_mday = rtc_time[idx++];
	tm->tm_hour = rtc_time[idx++];
	tm->tm_min = rtc_time[idx++];
	tm->tm_sec = rtc_time[idx++];

	hwlog_info("read time from serial_gauge succeed\n");
	return SERIAL_GAUGE_SUCCESS;
}

static void serial_gauge_set_delay(u8 *buf, u8 start, u8 len, u8 sss)
{
	u8 i;
	u32 delay = POWER_SAVING_DELAY_TIME_5MIN;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if(!di)
		return;

	if ((sss > 0) && (sss < SOC_SYS_STATUS_END - 1))
		delay = ipsStatusTimeList[sss];

	if ((sss == SOC_SYS_STATUS_S5 && (di->power_off_retrieve_time > 0)))
		delay = di->power_off_retrieve_time;

	for (i = 0; i < len - start; i++)
		buf[start + i] = (delay >> (SERIAL_GAUGE_FW_SINGLE_BIT_LEN * i)) & SERIAL_GAUGE_FW_SINGLE_BIT_MASK;
}

static int serial_gauge_update_shutdown_flag(struct serial_gauge_device *di, u8 sss)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u16 data;
	u8 buf[SERIAL_GAUGE_UPDATE_SHUTDOWN_FLAG_LEN] = { SERIAL_GAUGE_UPDATE_SHUTDOWN_FLAG_LEN - 1,
		(u8)(SERIAL_GAUGE_FW_SUB_CMD_SHUTDOWN_FLAG & SERIAL_GAUGE_FW_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_FW_SUB_CMD_SHUTDOWN_FLAG >> SERIAL_GAUGE_FW_SINGLE_BIT_LEN) };

	serial_gauge_set_delay(buf, SERIAL_GAUGE_FW_RTC_DATA_INDEX, SERIAL_GAUGE_UPDATE_SHUTDOWN_FLAG_LEN, sss);
	while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_FW_REG, buf, SERIAL_GAUGE_UPDATE_SHUTDOWN_FLAG_LEN);
		if (ret) {
			hwlog_err("%s retry[%d] write buf fail, ret = %d\n", __func__, retry, ret);
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}

		ret = serial_gauge_read_word(SERIAL_GAUGE_POWER_SAVING_STATUS_REG, &data);
		hwlog_info("%s retry[%d] read block ret = %d, data = 0x%04x, sss = %u\n",
			__func__, retry, ret, data, sss);
		if (!ret && (((data >> SERIAL_GAUGE_OP_STAT_H_SHUTDOWN_FLAG_BIT) & 0x1) == 0x1))
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("%s retry[%d] read data fail\n", __func__, retry);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

int set_coul_soc_system_status(struct serial_gauge_device *di, u8 status)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u16 data;
	u8 buf[SERIAL_GAUGE_SUB_CMD_TYPE_LEN] = { SERIAL_GAUGE_SUB_CMD_TYPE_LEN - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_SSS_SET & SERIAL_GAUGE_FW_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_SSS_SET >> SERIAL_GAUGE_FW_SINGLE_BIT_LEN), status };

	while (retry--) {
		ret = serial_gauge_write_block(SERIAL_GAUGE_FW_REG, buf, SERIAL_GAUGE_SUB_CMD_TYPE_LEN);
		if (ret) {
			hwlog_err("%s retry[%d] write buf fail, ret = %d\n", __func__, retry, ret);
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
		ret = serial_gauge_read_word(SERIAL_GAUGE_POWER_SAVING_STATUS_REG, &data);
		hwlog_info("%s retry[%d] read block ret = %d, data = 0x%04x, status = %u\n",
			__func__, retry, ret, data, status);
		if (!ret && (((data >> SERIAL_GAUGE_GAUGE_STAT_H_SSS_BIT) & SERIAL_GAUGE_GAUGE_STAT_H_SSS_MASK) == status))
			return SERIAL_GAUGE_SUCCESS;

		hwlog_err("%s retry[%d] read data fail\n", __func__, retry);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	return SERIAL_GAUGE_FAILED;
}

static void serial_gauge_rtc2coul(struct rtc_time *tm)
{
	tm->tm_mon = tm->tm_mon + 1;
	tm->tm_year = tm->tm_year + SERIAL_GAUGE_BASE_YEAR - SERIAL_GAUGE_CUR_YEAR;
}

static void serial_gauge_coul2rtc(struct rtc_time *tm)
{
	tm->tm_mon = tm->tm_mon - 1;
	tm->tm_year = SERIAL_GAUGE_CUR_YEAR + tm->tm_year - SERIAL_GAUGE_BASE_YEAR;
}

static int has_wakealarm(struct device *dev, const void *data)
{
	struct rtc_device *candidate = to_rtc_device(dev);

	hwlog_info("RTCX: devname is %s!\n", dev_name(dev));
	if (!candidate->ops->read_alarm) {
		hwlog_err("RTCX: read_alarm not support!\n");
		return 0;
	}
	if (!device_may_wakeup(candidate->dev.parent)) {
		hwlog_err("RTCX: can_wakeup not support!\n");
		return 0;
	}
	hwlog_info("RTCX: has_wakealarm!\n");
	return 1;
}

static struct rtc_device *serial_gauge_open_rtc_device(void)
{
	struct rtc_device *rtc = NULL;
	struct device *dev;

	dev = class_find_device(rtc_class, NULL, NULL, has_wakealarm);
	if (dev) {
		rtc = rtc_class_open(dev_name(dev));
		put_device(dev);
		hwlog_info("RTCX: dev ok(name:%s)!\n", dev_name(dev));
	}
	if (!rtc) {
		hwlog_err("RTCX: rtc_class_open failed!\n");
		return NULL;
	} else {
		hwlog_info("RTCX: rtc_class_open success!\n");
		return rtc;
	}
}

static void serial_gauge_coul_save_rtc_time(struct serial_gauge_device *di)
{
	struct rtc_time tm;

	if (!rtc_read_time(di->rtc_dev, &tm)) {
		serial_gauge_rtc2coul(&tm);
		(void)serial_gauge_write_rtc_time2coul(di, &tm);
		if (di->enter_std_proc) {
			(void)serial_gauge_update_shutdown_flag(di, SOC_SYS_STATUS_S4);
		} else {
			(void)serial_gauge_update_shutdown_flag(di, SOC_SYS_STATUS_S5);
		}
	}
}

static void serial_gauge_rtc_hctosys(struct rtc_device *rtc)
{
	int err;
	struct rtc_time tm;
	struct timespec64 tv64 = {
		.tv_nsec = NSEC_PER_SEC >> 1,
	};

	hwlog_err("start to hctosys sync serial_gauge time\n");
	err = rtc_read_time(rtc, &tm);
	if (err) {
		hwlog_err("hctosys: unable to read the hardware clock, ret = %d\n", err);
		return;
	}

	hwlog_info("after: rtc time: %d, %d, %d, %d, %d, %d, %d\n",
		tm.tm_sec, tm.tm_min, tm.tm_hour, tm.tm_wday, tm.tm_mday, tm.tm_mon,
		tm.tm_year);
	tv64.tv_sec = rtc_tm_to_time64(&tm);

#if BITS_PER_LONG == 32
	if (tv64.tv_sec > INT_MAX) {
		err = -ERANGE;
		return;
	}
#endif

	err = do_settimeofday64(&tv64);
	if (err)
		hwlog_err("do_settimeofday64 err, ret = %d\n", err);

	hwlog_info("end to hctosys sync serial_gauge time\n");
	return;
}

static int serial_gauge_time_compare_soc(struct rtc_time *tm, struct rtc_time *soc)
{
	if ((tm->tm_year > soc->tm_year) || (tm->tm_mon > soc->tm_mon) ||
		(tm->tm_mday > soc->tm_mday) || (tm->tm_hour > soc->tm_hour) ||
		(tm->tm_min > soc->tm_min) || (tm->tm_sec > soc->tm_sec))
		return SERIAL_GAUGE_SUCCESS;

	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_check_boot_from_intell_power(void)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 write_bf[SERIAL_GAUGE_WRITE_BUF_LEN] = {SERIAL_GAUGE_WRITE_BUF_LEN - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_BOOT_FROM_INTELL_POWER & SERIAL_GAUGE_FW_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_BOOT_FROM_INTELL_POWER >> SERIAL_GAUGE_FW_SINGLE_BIT_LEN)};
	u8 read_bf[SERIAL_GAUGE_READ_BUF_LEN] = {0};

	while (retry--) {
		ret = serial_gauge_write_read_block(write_bf, SERIAL_GAUGE_WRITE_BUF_LEN, read_bf, SERIAL_GAUGE_READ_BUF_LEN);
		if (!ret) {
			hwlog_info("Intelligent power status code: %d\n", read_bf[SERIAL_GAUGE_FW_RTC_DATA_INDEX]);
			return read_bf[SERIAL_GAUGE_FW_RTC_DATA_INDEX];
		}

		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}
	hwlog_err("serial_gauge_write_read_block error: %d\n", ret);
	return 0;
}

static void serial_gauge_sync_time_to_soc_work(struct work_struct *work)
{
	struct rtc_time tm;
	struct rtc_time soc_tm;
	struct serial_gauge_device *di = container_of(work, struct serial_gauge_device, soc_sync_rtc.work);

	if (!di)
		return;

	hwlog_info("%s enter\n", __func__);

	di->rtc_dev = serial_gauge_open_rtc_device();
	if (!di->rtc_dev) {
		queue_delayed_work(di->serial_gauge_wq, &di->soc_sync_rtc,
			msecs_to_jiffies(DT_MSLEEP_1S));
		return;
	}

	if (!serial_gauge_check_boot_from_intell_power())
		return;

	if (serial_gauge_read_rtc_time_from_coul(di, &tm))
		return;

	hwlog_info("time from serial_gauge: %d, %d, %d, %d, %d, %d, %d\n",
		tm.tm_year, tm.tm_mon, tm.tm_mday, tm.tm_wday, tm.tm_hour,
		tm.tm_min, tm.tm_sec);

	serial_gauge_coul2rtc(&tm);
	if (rtc_read_time(di->rtc_dev, &soc_tm))
		hwlog_err("soc read rtc time err\n");

	hwlog_info("before rtc time: %d, %d, %d, %d, %d, %d, %d\n",
		soc_tm.tm_year, soc_tm.tm_mon, soc_tm.tm_mday, soc_tm.tm_wday,
		soc_tm.tm_hour, soc_tm.tm_min, soc_tm.tm_sec);

	hwlog_info("serial_gauge time to trans rtc format: %d, %d, %d, %d, %d, %d, %d\n",
		tm.tm_year, tm.tm_mon, tm.tm_mday, tm.tm_wday, tm.tm_hour, tm.tm_min,
		tm.tm_sec);

	if (rtc_set_time(di->rtc_dev, &tm)) {
		hwlog_err("serial_gauge set rtc time err\n");
		return;
	}

	serial_gauge_rtc_hctosys(di->rtc_dev);
}

static int serial_gauge_usb_event_notifier_callback(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct serial_gauge_device *di = container_of(nb, struct serial_gauge_device, usb_event_nb);

	if (!di) {
		hwlog_err("serial_gauge usb nb callback err!");
		return NOTIFY_OK;
	}

	switch (event) {
	case POWER_NE_USB_DISCONNECT:
		di->is_usb_connected = false;
		hwlog_info("serial_gauge usb disconnected\n");
		break;
	case POWER_NE_USB_CONNECT:
		di->is_usb_connected = true;
		hwlog_info("serial_gauge usb connected\n");
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int serial_gauge_hibernate_callback(struct notifier_block *nb, unsigned long event, void *ptr)
{
	struct serial_gauge_device *di = container_of(nb, struct serial_gauge_device, std_event_nb);

	if (!di) {
		hwlog_err("serial_gauge coul hibernate nb callback error!");
		return NOTIFY_BAD;
	}

	switch (event) {
	case PM_HIBERNATION_PREPARE:
		di->enter_std_proc = true;
		break;
	case PM_POST_HIBERNATION:
	case PM_RESTORE_PREPARE:
	case PM_POST_RESTORE:
		di->enter_std_proc = false;
		break;
	default:
		break;
	}

	hwlog_info("mcu receive hibernate event %d", event);
	return NOTIFY_OK;
}

#ifdef CONFIG_DKMD_DKSM
static int tcon_logo_notifier_call(struct notifier_block *nb, unsigned long action, void *data)
{
	struct serial_gauge_device *di = container_of(nb, struct serial_gauge_device, tcon_logo_event_nb);

	if (!di) {
		hwlog_err("serial_gauge coul hibernate nb callback error!");
		return NOTIFY_BAD;
	}

	if (action != DKMD_EVENT_CLOSE_TCON_LOGO)
		return NOTIFY_OK;

	/* notify coul close TCON logo */
	(void)set_coul_soc_system_status(di, SOC_SYS_STATUS_S0);
	return NOTIFY_OK;
}
#endif

static int power_saving_only_sub_cmd_block(u8 *buf, u16 buf_len, u8 *data, u16 data_len)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	while (retry--) {
		ret = serial_gauge_write_read_block(buf, buf_len, data, data_len);
		if (ret)
			goto cmd_failed;

		if ((data[POWER_SAVING_SUB_CMD_INDEX] == buf[POWER_SAVING_SUB_CMD_INDEX]) &&
			(data[POWER_SAVING_SUB_CMD_INDEX + 1] == buf[POWER_SAVING_SUB_CMD_INDEX + 1])) {
			return SERIAL_GAUGE_SUCCESS;
		}
cmd_failed:
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("block read failed retry %d times\n", SERIAL_GAUGE_RETRY_COUNT);
	return SERIAL_GAUGE_FAILED;
}

static int serial_gauge_read_hw_version(u32 *version)
{
	int ret, i;
	u32 version_temp = 0;
	u8 data[SERIAL_GAUGE_HW_VERSION_DATA_LEN] = { 0 };
	u8 buf[SERIAL_GAUGE_CMD_LEN_ONLY_SUB] = { SERIAL_GAUGE_CMD_LEN_ONLY_SUB - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_HW_VERSION & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_HW_VERSION >> SERIAL_GAUGE_SINGLE_BIT_LEN)};

	ret = power_saving_only_sub_cmd_block(buf, SERIAL_GAUGE_CMD_LEN_ONLY_SUB, data,
		SERIAL_GAUGE_HW_VERSION_DATA_LEN);
	if (ret)
		return SERIAL_GAUGE_FAILED;

	for (i = 0; i < SERIAL_GAUGE_HW_VERSION_LEN; i++)
		version_temp = (version_temp << SERIAL_GAUGE_SINGLE_BIT_LEN) |
			(u32)data[i + SERIAL_GAUGE_CMD_LEN_ONLY_SUB];

	hwlog_info("power saving hw version from coul: 0x%08x\n", version_temp);
	*version = version_temp;
	return SERIAL_GAUGE_SUCCESS;
}

static bool serial_gauge_judge_enable_power_saving(struct serial_gauge_device *di)
{
	u32 hw_version = 0;
	u32 enable_jht_power_saving = 0;

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dts_node,
		"enable_jht_power_saving", (u32 *)&enable_jht_power_saving, 0);
	if (enable_jht_power_saving == 0)
		return false;

	(void)serial_gauge_read_hw_version(&hw_version);
	if (hw_version == SERIAL_GAUGE_HW_VERSION_JW3408)
		return true;

	return false;
}

static void serial_gauge_delay_send_work(struct work_struct *work)
{
	struct serial_gauge_device *di = container_of(work, struct serial_gauge_device, delay_send_work.work);

	if (!di)
		return;

	hwlog_info("%s enter\n", __func__);

	(void)set_coul_soc_system_status(di, SOC_SYS_STATUS_S0);
}

void serial_gauge_power_saving_restore(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	INIT_DELAYED_WORK(&di->delay_send_work, serial_gauge_delay_send_work);
	queue_delayed_work(di->serial_gauge_wq, &di->delay_send_work, msecs_to_jiffies(DT_MSLEEP_5S));
	hwlog_info("delay_send_work work start run!\n");

	di->enter_std_proc = false;
	if (!serial_gauge_judge_enable_power_saving(di)) {
		if (!di->power_saving_enable)
			return;
	}

	INIT_DELAYED_WORK(&di->soc_sync_rtc, serial_gauge_sync_time_to_soc_work);
	queue_delayed_work(di->serial_gauge_wq, &di->soc_sync_rtc, msecs_to_jiffies(DT_MSLEEP_1S));
	hwlog_info("soc_sync_rtc work start run!\n");

	/* default true not go to power saving */
	di->is_usb_connected = true;
	di->usb_event_nb.notifier_call = serial_gauge_usb_event_notifier_callback;
	if (power_event_bnc_register(POWER_BNT_CONNECT, &di->usb_event_nb)) {
		hwlog_err("register usb event err\n");
		return;
	}

	di->std_event_nb.notifier_call = serial_gauge_hibernate_callback;
	if (register_pm_notifier(&di->std_event_nb)) {
		hwlog_err("register std event err\n");
		power_event_bnc_unregister(POWER_BNT_CONNECT, &di->usb_event_nb);
		return;
	}

#ifdef CONFIG_DKMD_DKSM
	di->tcon_logo_event_nb.notifier_call = tcon_logo_notifier_call;
	dkmd_register_client(&di->tcon_logo_event_nb);
#endif
	hwlog_info("usb event and std event notify registe success\n");
}

void serial_gauge_power_saving_shutdown(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	if (di->enter_std_proc)
		(void)set_coul_soc_system_status(di, SOC_SYS_STATUS_S4);
	else
		(void)set_coul_soc_system_status(di, SOC_SYS_STATUS_S5);

	if (!serial_gauge_judge_enable_power_saving(di)) {
		if (!di->power_saving_enable)
			return;
	}

	if (poweroff_rtc_alarm.enabled)
		return;

	if (!di->is_usb_connected)
		serial_gauge_coul_save_rtc_time(di);
}

void serial_gauge_power_saving_free_resource(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	if (!serial_gauge_judge_enable_power_saving(di)) {
		if (!di->power_saving_enable)
			return;
	}

	hwlog_info("%s enter. di->rtc_dev = 0x%x, work = 0x%x\n", __func__,
		di->rtc_dev, &di->soc_sync_rtc);
	cancel_delayed_work(&di->soc_sync_rtc);
	(void)power_event_bnc_unregister(POWER_BNT_CONNECT, &di->usb_event_nb);
	(void)unregister_pm_notifier(&di->std_event_nb);
#ifdef CONFIG_DKMD_DKSM
	dkmd_unregister_client(&di->tcon_logo_event_nb);
#endif

	if (di->rtc_dev)
		rtc_class_close(di->rtc_dev);
}