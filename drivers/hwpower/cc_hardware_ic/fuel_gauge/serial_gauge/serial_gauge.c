// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge.c
 *
 * serial gauge firmware interface
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

#include "serial_gauge.h"

#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <securec.h>

#include "serial_gauge_debug_sysfs.h"
#include "serial_gauge_power_saving.h"
#include "serial_gauge_logs.h"
#include "serial_gauge_data.h"
#include "serial_gauge_mf_data.h"
#include "serial_gauge_upgrade/upgrade_interface.h"

#define HWLOG_TAG serial_gauge
HWLOG_REGIST();

static int get_dts_param(struct serial_gauge_device *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dts_node,
		"is_support_crc", (u32 *)&di->support_i2c_crc, 0);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dts_node,
		"power_saving_enable", (u32 *)&di->power_saving_enable, 0);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dts_node,
		"enable_factory_download", (u32 *)&di->enable_factory_download, 0);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dts_node,
		"write_mf_enable", (u32 *)&di->write_mf_enable, 0);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dts_node,
		"use_old_lqd", (u32 *)&di->use_old_lqd, 0);

	return SERIAL_GAUGE_SUCCESS;
}

void serial_gauge_probe(struct i2c_client *i2c, struct mutex *rw_lock,
	struct device_node *np, int device_id)
{
	struct serial_gauge_device *di = NULL;

	serial_gauge_register(i2c, np, rw_lock);
	di = serial_gauge_get_di();
	if (!di) {
		hwlog_err("serial_gauge_register failed, device is null");
		return;
	}
	di->device_id = device_id;
	get_dts_param(di);
	/* sysfs create */
	serial_gauge_sysfs_start();

	if (device_id != SERIAL_GAUGE_SELF_DEV_DEVICE_ID) {
		hwlog_info("device id[%d] is not self algorithm battery chip", device_id);
		return;
	}
	/* create work queue */
	di->serial_gauge_wq = create_workqueue("serial_gauge_wq");

	/* power saving */
	di->wake_lock = power_wakeup_source_register(di->dev, "serial_gauge_wakelock");
	serial_gauge_start_upgrade();
	serial_gauge_power_saving_restore();
	serial_gauge_loop_log_record(di);
	serial_gauge_write_mf_data();
}

void serial_gauge_shutdown(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	if (di->device_id == SERIAL_GAUGE_SELF_DEV_DEVICE_ID)
		serial_gauge_power_saving_shutdown();
}

void serial_gauge_remove(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return;

	serial_gauge_sysfs_end();

	if (di->device_id == SERIAL_GAUGE_SELF_DEV_DEVICE_ID) {
		power_wakeup_source_unregister(di->wake_lock);
		serial_gauge_upgrade_free();
		serial_gauge_power_saving_free_resource();
		serial_gauge_loop_log_free(di);
		serial_gauge_mf_free();
		destroy_workqueue(di->serial_gauge_wq);
	}
	serial_gauge_unregister();
}

int serial_gauge_log_data(char *buf, int size)
{
	int ret;
	char soc_log1[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	char soc_log2[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	char soc_log3[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	char soc_log4[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	char bal_log1[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	char bal_log2[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	char eb_log1[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	char base_data[SERIAL_GAUGE_LOG_STR_SINGLE_LEN] = { 0 };
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!buf || !di)
		return -EPERM;

	if (di->device_id != SERIAL_GAUGE_SELF_DEV_DEVICE_ID)
		return 0;

	if (judge_is_running_upgrade()) {
		hwlog_err("chip is in upgrade!");
		return 0;
	}

	serial_gauge_soc_log1(soc_log1, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);
	serial_gauge_soc_log2(soc_log2, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);
	serial_gauge_soc_log3(soc_log3, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);
	serial_gauge_soc_log4(soc_log4, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);
	serial_gauge_balance_log1(bal_log1, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);
	serial_gauge_balance_log2(bal_log2, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);
	serial_gauge_ext_balance_log1(eb_log1, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);

	serial_gauge_base_log_data(base_data, SERIAL_GAUGE_LOG_STR_SINGLE_LEN);
	ret = snprintf_s(buf, size, size - 1, " %s %s %s %s %s %s %s %s ", soc_log1, soc_log2,
		soc_log3, soc_log4, bal_log1, bal_log2, eb_log1, base_data);
	if (ret < 0)
		hwlog_err("serial_gauge_log_data snprintf_s error!");

	return 0;
}

int serial_gauge_log_head(char *buf, int size)
{
	int ret;
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!buf || !di)
		return -EPERM;

	if (di->device_id != SERIAL_GAUGE_SELF_DEV_DEVICE_ID)
		return 0;

	ret = snprintf_s(buf, size, size - 1, " %s%s %s%s %s%s %s %s%s %s%s %s%s %s ", "AccDchg   AccChg    ",
		"CC        RMDisp    FCCDisp   AccDFulChg RMActual  SOCDispRevTyp AccDCChg  PSOCDisp  RealRevTyp",
		"ActCap    SlpT      ASOC   SOCDisp SOCRConv SOCTConv Vdec   SOCMax SOCAvrg SOCMin SOCDispF ",
		"SOCDispRev OCVMode SOCRealTyp FCF EDF  SOCFKF ", "SOHDisp SOHReal Cycle  CLACap SOHReAW ",
		"SOHReAWB CCEn CellMax CellMin CellAvg SOCRng SOHBasp AccCCDchg SOE    VdecEb BaNotA ",
		"SOHVld  SOCMinPre SOCMaxPre SOHFst SOHFSt SOHScd SOHSSt SOHRSav APre   Achg   Apst   ",
		"BalCap1   BalCap2   BalCap3   BalCap4    BalSOC1 BalSOC1 BalSOC1 BalSOC1 ",
		"BalT1  BalT2  BalT3  BalT4  ", "BalTC1 BalTC2 BalTC3 BalTC4 CBalCap   SlpBalCap  Balst BalCmd ",
		"BalEnF BalSlp BalOT BalCir BalCNS NABal ChargF SlpM ICTmp ", "vcell1 vcell2 vcell3 vcell4 ",
		"soc1   soc2   qout1     qout2     EBOF EBC  EBE  VbO  EBReCap   ",
		"mfS    afeS   cfetSh cfetSl dfetSh dfetSl ps     dState runtime   ");
	if (ret < 0)
		hwlog_err("serial_gauge_log_head snprintf_s error!");

	return 0;
}

int judge_upgrade_can_i2c(void)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return SERIAL_GAUGE_SUCCESS;

	if (di->device_id != SERIAL_GAUGE_SELF_DEV_DEVICE_ID)
		return SERIAL_GAUGE_SUCCESS;

	return judge_is_running_upgrade();
}

int serial_gauge_set_vterm_dec(unsigned int nondc_volt_dec)
{
	struct serial_gauge_device *di = serial_gauge_get_di();

	if (!di)
		return SERIAL_GAUGE_SUCCESS;

	if (di->device_id != SERIAL_GAUGE_SELF_DEV_DEVICE_ID)
		return SERIAL_GAUGE_SUCCESS;

	return gauge_send_vterm(nondc_volt_dec);
}
