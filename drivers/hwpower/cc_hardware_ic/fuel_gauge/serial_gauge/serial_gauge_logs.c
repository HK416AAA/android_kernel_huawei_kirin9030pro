// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge_logs.c
 *
 * serial gauge log driver, timer to read gauge log
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

#include "serial_gauge_logs.h"

#include <chipset_common/hwpower/battery/battery_ocv.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <securec.h>

#include "serial_gauge_data.h"

#define GAUGE_U16_MAX 0xFFFF

#define HWLOG_TAG serial_gauge_log
HWLOG_REGIST();

static u16 serial_gauge_get_gauge_log_cnt(struct serial_gauge_device *di)
{
	int ret = 0;
	u16 log_cnt = 0;
	int retry = SERIAL_GAUGE_RETRY_COUNT;

	if (judge_is_running_upgrade()) {
		return 0;
	}

	while (retry--) {
		ret = serial_gauge_read_word(SERIAL_GAUGE_LOG_CNT_CMD, &log_cnt);
		if (!ret)
			break;

		hwlog_err("retry[%d] read data LOG_COUNT fail\n", retry);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	power_msleep(DT_MSLEEP_10MS, 0, NULL);
	return (u16)(log_cnt & SERIAL_GAUGE_SINGLE_BIT_MASK);
}

static void write_log_to_kernel(u8 *data, u16 data_len)
{
	int i;
	int ret;
	int offset = 0;
	int len = data_len;
	char gauge_log[SERIAL_GAUGE_LOG_STR_LEN] = { 0 };

	if (data[0] <= 0)
		return;

	if (data[0] < data_len - 1)
		len = data[0];

	ret = snprintf_s(gauge_log, SERIAL_GAUGE_LOG_STR_LEN, SERIAL_GAUGE_LOG_STR_LEN - 1,
		"%02x", len);
	if (ret < 0 || ret >= (SERIAL_GAUGE_LOG_STR_LEN)) {
		hwlog_err("sprintf_s log first data fail!\n");
		return;
	}
	offset += ret;
	for (i = 0; i < len; i++) {
		ret = snprintf_s(gauge_log + offset, SERIAL_GAUGE_LOG_STR_LEN - offset,
			SERIAL_GAUGE_LOG_STR_LEN - offset - 1, "-%02x", data[i + 1]);
		 if (ret < 0 || ret >= (SERIAL_GAUGE_LOG_STR_LEN - offset)) {
			hwlog_err("sprintf_s log data fail!\n");
			return;
		}
		offset += ret;
	}

	hwlog_info("%s %s\n", SERIAL_GAUGE_LOG_LABEL, gauge_log);
}

static void record_gauge_log_in_kernel(struct serial_gauge_device *di)
{
	int ret;
	int retry = SERIAL_GAUGE_RETRY_COUNT;
	u8 buf[GAUGE_LOG_BUF_LEN] = { GAUGE_LOG_BUF_LEN - 1,
		(u8)(SERIAL_GAUGE_SUB_CMD_GAUGE_LOG & SERIAL_GAUGE_SINGLE_BIT_MASK),
		(u8)(SERIAL_GAUGE_SUB_CMD_GAUGE_LOG >> SERIAL_GAUGE_SINGLE_BIT_LEN) };
	u8 data[SERIAL_GAUGE_LOG_DATA_LEN] = { 0 };

	if (judge_is_running_upgrade()) {
		return;
	}

	di->block_delay = DT_MSLEEP_10MS;
	while (retry--) {
		ret = serial_gauge_write_read_block(buf, GAUGE_LOG_BUF_LEN, data, SERIAL_GAUGE_LOG_DATA_LEN);
		if (!ret)
			break;

		hwlog_err("%s retry[%d] read data fail\n", __func__, retry);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}
	di->block_delay = 0;
	if (ret)
		return;
	// data get
	if (data[0] > 0)
		write_log_to_kernel(data, SERIAL_GAUGE_LOG_DATA_LEN);
}

static void gauge_log_record(struct serial_gauge_device *di)
{
	int i;
	u16 log_cnt;

	// 1. get log count
	log_cnt = serial_gauge_get_gauge_log_cnt(di);
	hwlog_info("Get SerialGaugeLog: %d\n", log_cnt);
	if (log_cnt <= 0)
		return;

	// 2. loop get log and print in kernel
	for (i = 0; i < log_cnt; i++) {
		record_gauge_log_in_kernel(di);
		power_msleep(DT_MSLEEP_50MS, 0, NULL);
	}
}

static void gauge_basp_battery_ocv(void)
{
	int ret;
	int ocv = 0;

	ret = battery_ocv_get_ocv_by_cap(0, &ocv);
	if (ret) {
		hwlog_err("get battery ocv failed, ret=%d", ret);
		return;
	}

	if (ocv < 0 || ocv > GAUGE_U16_MAX) {
		hwlog_err("ocv value over limit, ocv=%d", ocv);
		return;
	}

	ret = gauge_send_battery_ocv((u16)ocv);
	if (ret)
		hwlog_err("send battery ocv to gauge failed, ret=%d", ret);
}

static void gauge_loop_5s_work(struct work_struct *work)
{
	int i;
	struct serial_gauge_device *di = container_of(work,
		struct serial_gauge_device, gauge_log_work.work);

	if (!di)
		return;

	if (judge_is_running_upgrade()) {
		hwlog_info("curr upgrade running, not allow i2c communicate\n");
		goto loop_work;
	}

	gauge_log_record(di);
	gauge_basp_battery_ocv();

loop_work:
	queue_delayed_work(di->serial_gauge_wq, &di->gauge_log_work,
		msecs_to_jiffies(SERIAL_GAUGE_PRINT_LOOP_5S));
}

void serial_gauge_soc_log1(char *buf, int size)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	gauge_get_gauge_status1(data, SERIAL_GAUGE_BLOCK_MAX_LEN);

	ret = snprintf_s(buf, size, size - 1, "%-10u%-10u%-10d%-10u%-10u%-11u%-10u%-14u%-10u%-10hd%-10u",
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG1_ACCUDCHGONE_INDEX]),
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG1_ACCUCHGONE_INDEX]),
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG1_COULCOUNT_INDEX]),
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG1_REMCAPDISPWRITE_INDEX]),
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG1_FULLCHRGCAPDISPWRITE_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG1_ACCUDCHGCAPSINFULCHGW_INDEX]),
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG1_REMCAPACTUALWRITE_INDEX]),
		data[SOC_LOG1_SOCDISPREVTYPESTSHLDW_INDEX],
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG1_ACCUDCHGCAPSINCHGW_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG1_PACKSOCDISPWRIDLYREV_INDEX]),
		data[SOC_LOG1_SOCREALREVTYPE_INDEX]);
	if (ret < 0)
		hwlog_err("serial_gauge_soc_log1 snprintf_s error!");
}

void serial_gauge_soc_log2(char *buf, int size)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	gauge_get_gauge_status2(data, SERIAL_GAUGE_BLOCK_MAX_LEN);

	ret = snprintf_s(buf, size, size - 1, "%-10u%-10u%-07hd%-08hd%-09hd%-09hd%-07u%-07hd%-08hd%-07hd%-09hd"
		"%-10u%-09u%-10u%-05u%-05u%-07u",
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG2_PACKRATEDCAPACTUALW_INDEX]),
		GET_U32_FROM_U8_ARR4(&data[SOC_LOG2_SLEEPTIMEWRITE_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_ABSOLUTESOC_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_PACKSOCDISPWRITE_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_PACKSOCREALCONV_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_REALSOCTEMPCONV_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_BASPVDEC_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_CELLSOCMAXCOLOMBMETER_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_CELLSOCAVRGCOLOMBMETER_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_CELLSOCMINCOLOMBMETER_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG2_PACKSOCDISPFOLLWRITE_INDEX]),
		data[SOC_LOG2_SOCDISPREVTYPEWRITE_INDEX], data[SOC_LOG2_OCVREVMODEWRITE_INDEX],
		data[SOC_LOG2_SOCREALREVTYPEWRITE_INDEX], data[SOC_LOG2_FULLCHRGFLAG_INDEX],
		data[SOC_LOG2_EMPTYDISPCHRGFLAG_INDEX], data[SOC_LOG2_SOCFULKEEPFLAGWRITE_INDEX]);
	if (ret < 0)
		hwlog_err("serial_gauge_soc_log2 snprintf_s error!");
}

void serial_gauge_soc_log3(char *buf, int size)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	gauge_get_gauge_status3(data, SERIAL_GAUGE_BLOCK_MAX_LEN);

	ret = snprintf_s(buf, size, size - 1, "%-08hd%-08hd%-07u%-07u%-08u%-09u%-05u%-08u%-08u%-08u%-07hd"
		"%-08hd%-10u%-07hd%-07hu%-07hu",
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_PACKSOHDISPWRT_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_PACKSOHREALWRT_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_BATTERYCYCLE_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_CALELIFEAGEDCAP_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_SOHREVISEDAGEDWEIGHT_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_SOHREVAGEWIGHTBASED_INDEX]), data[SOC_LOG3_CCRESETEN_INDEX],
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_CELLVOLTMAX_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_CELLVOLTMIN_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_CELLVOLTAVG_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_ACTUALSOCRNG_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_PACKSOHBASPWRT_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_ACCUCHGCAPSINDCHGW_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG3_PACKSOEDISPWRITE_INDEX]), data[SOC_LOG3_VDECENABLE_INDEX],
		data[SOC_LOG3_BALANCENOTALLOW_INDEX]);
	if (ret < 0)
		hwlog_err("serial_gauge_soc_log3 snprintf_s error!");
}

void serial_gauge_soc_log4(char *buf, int size)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	gauge_get_gauge_status4(data, SERIAL_GAUGE_BLOCK_MAX_LEN);

	ret = snprintf_s(buf, size, size - 1, "%-08hd%-10hd%-10hd%-07hd%-07u%-07hd%-07u%-08u%-07hd%-07hd%-07hd",
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_PACKSOHOCVREVVLD_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_SOCMINPRECHG_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_SOCMAXPRECHG_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_PACKSOHREALFSTWRT_INDEX]),
		data[SOC_LOG4_PACKSOHREALFSTVLDSTS_INDEX],
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_PACKSOHREALSCNDWRT_INDEX]),
		data[SOC_LOG4_PACKSOHREALSCNDVLDSTS_INDEX], data[SOC_LOG4_PACKSOHREALSAVMOD_INDEX],
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_ACMDCHGCAPCHGPRE_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_ACMCHGCAPCHGING_INDEX]),
		GET_U16_FROM_U8_ARR2(&data[SOC_LOG4_ACMDCHGCAPCHGPST_INDEX]));
	if (ret < 0)
		hwlog_err("serial_gauge_soc_log4 snprintf_s error!");
}

void serial_gauge_balance_log1(char *buf, int size)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	gauge_get_cb_status1(data, SERIAL_GAUGE_BLOCK_MAX_LEN);

	ret = snprintf_s(buf, size, size - 1, "%-10u%-10u%-10u%-11u%-08u%-08u%-08u%-08u%-07u%-07u%-07u%-07u",
		GET_U32_FROM_U8_ARR4(&data[BALANCE_LOG1_BALCAP1]), GET_U32_FROM_U8_ARR4(&data[BALANCE_LOG1_BALCAP2]),
		GET_U32_FROM_U8_ARR4(&data[BALANCE_LOG1_BALCAP3]), GET_U32_FROM_U8_ARR4(&data[BALANCE_LOG1_BALCAP4]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_REALSOCREV1]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_REALSOCREV2]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_REALSOCREV3]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_REALSOCREV4]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_CELLBALRMTIM1]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_CELLBALRMTIM2]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_CELLBALRMTIM3]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG1_CELLBALRMTIM4]));
	if (ret < 0)
		hwlog_err("serial_gauge_balance_log1 snprintf_s error!");
}

void serial_gauge_balance_log2(char *buf, int size)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	gauge_get_cb_status2(data, SERIAL_GAUGE_BLOCK_MAX_LEN);

	ret = snprintf_s(buf, size, size - 1, "%-07u%-07u%-07u%-07u%-10u%-11u%-06u%-07u%-07u%-07u%-06u"
		"%-07u%-07u%-06u%-07u%-05u%-06u",
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG2_CELLBALRMTIMCAL1]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG2_CELLBALRMTIMCAL2]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG2_CELLBALRMTIMCAL3]),
		GET_U16_FROM_U8_ARR2(&data[BALANCE_LOG2_CELLBALRMTIMCAL4]),
		GET_U32_FROM_U8_ARR4(&data[BALANCE_LOG2_CHGBALCAP]),
		GET_U32_FROM_U8_ARR4(&data[BALANCE_LOG2_SLPMODBALCAP]), data[BALANCE_LOG2_BALSTATE],
		data[BALANCE_LOG2_BALCMD], data[BALANCE_LOG2_VOLTREVCONSOCENFLAG],
		data[BALANCE_LOG2_SLEEPMODEBAL], data[BALANCE_LOG2_BALOVERTEMPFLT],
		data[BALANCE_LOG2_BALCIROPENFLT], data[BALANCE_LOG2_BALCLLNUMSUM],
		data[BALANCE_LOG2_NOTALLOWBALANCE], data[BALANCE_LOG2_CHARGING],
		data[BALANCE_LOG2_SLEEPMODE], data[BALANCE_LOG2_ICTEMPDEGC]);
	if (ret < 0)
		hwlog_err("serial_gauge_balance_log2 snprintf_s error!");
}

void serial_gauge_ext_balance_log1(char *buf, int size)
{
	int ret;
	u8 data[SERIAL_GAUGE_BLOCK_MAX_LEN] = { 0 };

	gauge_get_eb_status1(data, SERIAL_GAUGE_BLOCK_MAX_LEN);

	ret = snprintf_s(buf, size, size - 1, "%-07u%-07u%-07u%-07u%-07d%-07d%-10u%-10u%-05u%-05x%-05u%-05u%-10u",
		GET_U16_FROM_U8_ARR2(&data[EXT_BALANCE_LOG1_VCELL1]),
		GET_U16_FROM_U8_ARR2(&data[EXT_BALANCE_LOG1_VCELL2]),
		GET_U16_FROM_U8_ARR2(&data[EXT_BALANCE_LOG1_VCELL3]),
		GET_U16_FROM_U8_ARR2(&data[EXT_BALANCE_LOG1_VCELL4]),
		GET_U16_FROM_U8_ARR2(&data[EXT_BALANCE_LOG1_SOC1]),
		GET_U16_FROM_U8_ARR2(&data[EXT_BALANCE_LOG1_SOC2]),
		GET_U32_FROM_U8_ARR4(&data[EXT_BALANCE_LOG1_QOUT1]),
		GET_U32_FROM_U8_ARR4(&data[EXT_BALANCE_LOG1_QOUT2]),
		data[EXT_BALANCE_LOG1_EXTBALOCVFLAG], data[EXT_BALANCE_LOG1_EXTBALCMD],
		data[EXT_BALANCE_LOG1_EXTBALEN], data[EXT_BALANCE_LOG1_VBUSON],
		GET_U32_FROM_U8_ARR4(&data[EXT_BALANCE_LOG1_EXTBALCAP]));
	if (ret < 0)
		hwlog_err("serial_gauge_ext_balance_log1 snprintf_s error!");
}

void serial_gauge_base_log_data(char *buf, int size)
{
	int ret;
	struct serial_gauge_log_base_data base_data = { 0 };

	(void)gauge_get_mf_status(&base_data.mf_status);
	(void)gauge_get_afe_status(&base_data.afe_status);
	(void)gauge_get_cfet_status_l(&base_data.cfet_status_l);
	(void)gauge_get_cfet_status_h(&base_data.cfet_status_h);
	(void)gauge_get_dfet_status_l(&base_data.dfet_status_l);
	(void)gauge_get_dfet_status_h(&base_data.dfet_status_h);
	(void)gauge_get_power_saving_status(&base_data.power_saving_status);
	(void)gauge_get_d_status(&base_data.d_status);
	(void)gauge_get_run_time(&base_data.runtime);
	ret = snprintf_s(buf, size, size - 1, "%-07x%-07x%-07x%-07x%-07x%-07x%-07x%-07x%-10u",
		base_data.mf_status, base_data.afe_status, base_data.cfet_status_h, base_data.cfet_status_l,
		base_data.dfet_status_h, base_data.dfet_status_l, base_data.power_saving_status,
		base_data.d_status, base_data.runtime);
	if (ret < 0)
		hwlog_err("serial_gauge_ext_balance_log1 snprintf_s error!");
}

void serial_gauge_loop_log_record(struct serial_gauge_device *di)
{
	if (!di || !di->serial_gauge_wq)
		return;

	check_download_status();

	INIT_DELAYED_WORK(&di->gauge_log_work, gauge_loop_5s_work);
	queue_delayed_work(di->serial_gauge_wq, &di->gauge_log_work,
		msecs_to_jiffies(SERIAL_GAUGE_PRINT_LOOP_5S));
}

void serial_gauge_loop_log_free(struct serial_gauge_device *di)
{
	if (!di)
		return;

	cancel_delayed_work_sync(&di->gauge_log_work);
}
