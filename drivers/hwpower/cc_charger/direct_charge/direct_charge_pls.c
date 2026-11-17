/* SPDX-License-Identifier: GPL-2.0 */
/*
 * direct_charge_pulse.c
 *
 * direct_charge_pulse module
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

#include <chipset_common/hwpower/buck_charge/buck_charge_ic_manager.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_debug.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/direct_charge/direct_charger.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_pls.h>
#include <chipset_common/hwpower/common_module/power_interface.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_client.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_ic_intf.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/power/wireless/wireless_transmitter.h>

#define HWLOG_TAG direct_charge_pls
HWLOG_REGIST();

DECLARE_COMPLETION(g_pls_dc_exit_comp);
static struct dc_pls_dev *g_dc_pls_di;

static void dc_pls_restore_work(struct work_struct *work)
{
	struct dc_pls_dev *di = container_of(work, struct dc_pls_dev, restore_work.work);

	if (!di)
		return;

	hwlog_info("set restore work start\n");
	direct_charge_set_disable_flags(DC_CLEAR_DISABLE_FLAGS, DC_DISABLE_PLS_CHARGE);
	power_if_kernel_sysfs_set(POWER_IF_OP_TYPE_DCP,
		POWER_IF_SYSFS_VBUS_IIN_LIMIT, PLS_CTRL_IIN_UNLIMIT);
	charge_set_fcp_disable_flag(false, FCP_DISABLE_PLS_VOTER);
	switch (di->pls_para_group[di->index].discharge_para[di->discharge_para_index].pls_discharge_mode) {
	case DISCHARGE_WLTX:
		wltx_open_tx(WLTX_CLIENT_PLS_CHARGE, false);
		break;
	case DISCHARGE_NOOP:
	case DISCHARGE_CPU:
		break;
	default:
		break;
	}
	if (di->plugged_state)
		charge_request_charge_monitor();
	hwlog_info("set restore work end\n");
}

static void dc_pls_monitor_work(struct work_struct *work)
{
	int i, idx;
	struct dc_pls_dev *di = container_of(work, struct dc_pls_dev, monitor_work);
 
	if (!di)
		return;

	if (!di->plugged_state)
		return;
 
	idx = di->index;
	for (i = 0; i < di->pls_para_group[idx].pls_stage_size; i++) {
		if (di->pls_para_group[idx].discharge_para[i].pls_discharge_stage == di->charge_info.cur_stage)
			break;
	}

	if (i >= di->pls_para_group[idx].pls_stage_size) {
		hwlog_info("not target stage\n");
		return;
	}

	if (di->pls_para_group[idx].pls_flag[i]) {
		hwlog_info("pulse flag is true\n");
		return;
	}

	hwlog_info("set pls flag true\n");
	di->pls_para_group[idx].pls_flag[i] = true;
	di->discharge_para_index = i;
	reinit_completion(&g_pls_dc_exit_comp);
	direct_charge_set_disable_flags(DC_SET_DISABLE_FLAGS, DC_DISABLE_PLS_CHARGE);
	if (!wait_for_completion_timeout(&g_pls_dc_exit_comp, msecs_to_jiffies(DC_STOP_COMPLETE_TIMEOUT))) {
		hwlog_info("completion timeout\n");
		direct_charge_set_disable_flags(DC_CLEAR_DISABLE_FLAGS, DC_DISABLE_PLS_CHARGE);
		return;
	}
	hwlog_info("completion end, set iin 100ma\n");
	power_if_kernel_sysfs_set(POWER_IF_OP_TYPE_DCP,
		POWER_IF_SYSFS_VBUS_IIN_LIMIT, PLS_CTRL_IIN_LIMIT);
	charge_set_fcp_disable_flag(true, FCP_DISABLE_PLS_VOTER);
	switch (di->pls_para_group[idx].discharge_para[i].pls_discharge_mode) {
	case DISCHARGE_WLTX:
		wltx_open_tx(WLTX_CLIENT_PLS_CHARGE, true);
		break;
	case DISCHARGE_NOOP:
	case DISCHARGE_CPU:
		break;
	default:
		break;
	}

	schedule_delayed_work(&di->restore_work, msecs_to_jiffies(
		di->pls_para_group[idx].discharge_para[i].pls_discharge_time * PLS_DISCHANGE_TIME_MS));
	hwlog_info("set pls flag true end\n");
}

static int dc_pls_update_charge_info(struct power_event_notify_common_data *data, struct dc_pls_dev *di)
{
	int i;

	if (!data)
		return -EINVAL;

	di->charge_info.bat_temp = data->value[0];
	di->charge_info.cur_mode = data->value[1];
	di->charge_info.cur_stage = data->value[2];
	hwlog_info("%s temp=%d mode=%d stage=%d\n", __func__, di->charge_info.bat_temp, di->charge_info.cur_mode, di->charge_info.cur_stage);

	for (i = 0; i < di->pls_para_group_size; i++) {
		if ((di->charge_info.cur_mode & di->pls_para_group[i].mode) == 0)
			continue;

		if (di->charge_info.bat_temp >= di->pls_para_group[i].temp_high ||
			di->charge_info.bat_temp < di->pls_para_group[i].temp_low)
			continue;

		di->index = i;
		hwlog_info("%s index=%d\n", __func__, di->index);
		break;
	}

	if (i >= di->pls_para_group_size) {
		hwlog_info("%s not target mode\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static int dc_pls_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	int i, j;
	struct dc_pls_dev *di = g_dc_pls_di;

	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_DC_STAGE_CHANGE:
		hwlog_info("dc stage change\n");
		if (dc_pls_update_charge_info(data, di))
			break;
		schedule_work(&di->monitor_work);
		hwlog_info("dc stage change handled\n");
		break;
	case POWER_NE_DC_STOP_CHARGE:
		complete(&g_pls_dc_exit_comp);
		hwlog_info("dc stop charge complete g_pls_dc_exit_comp\n");
		break;
	case POWER_NE_USB_DISCONNECT:
		hwlog_info("usb disconnect\n");
		di->plugged_state = false;
		cancel_delayed_work(&di->restore_work);
		schedule_delayed_work(&di->restore_work, 0);
		hwlog_info("usb disconnect handled\n");
		break;
	case POWER_NE_USB_CONNECT:
		hwlog_info("usb connect\n");
		di->plugged_state = true;
		for (i = 0; i < di->pls_para_group_size; i++) {
			for (j = 0; j < di->pls_para_group[i].pls_stage_size; j++)
				di->pls_para_group[i].pls_flag[j] = false;
		}
		hwlog_info("usb connect handled\n");
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}
 
static int dc_pls_parse_pls_status_para(struct device_node *np, struct dc_pls_dev *di)
{
	int i, len, ret;
	int j;

	for (i = 0; i < di->pls_para_group_size; i++) {
		len = power_dts_read_u32_count(power_dts_tag(HWLOG_TAG), np, di->pls_para_group[i].pls_stage_name,
			DC_PLS_STAGE_MAX_SIZE, DC_PLS_DISCHARGE_PARA_TOTAL);
		if (len <= 0) {
			hwlog_err("%s parse failed\n", __func__);
			return -EINVAL;
		}
		ret = power_dts_read_u32_array(power_dts_tag(HWLOG_TAG), np, di->pls_para_group[i].pls_stage_name,
			(u32 *)di->pls_para_group[i].discharge_para, len);
		if (ret)
			return -EINVAL;
		di->pls_para_group[i].pls_stage_size = len / DC_PLS_DISCHARGE_PARA_TOTAL;
		for (j = 0; j < di->pls_para_group[i].pls_stage_size; j++)
			hwlog_info("pls_stage[%d][%d]=%d %d %d\n", i, j,
				di->pls_para_group[i].discharge_para[j].pls_discharge_stage,
				di->pls_para_group[i].discharge_para[j].pls_discharge_mode,
				di->pls_para_group[i].discharge_para[j].pls_discharge_time);
	}

	return 0;
}

static int dc_pls_parse_pls_para(struct device_node *np, struct dc_pls_dev *di)
{
	int i, ret, row, col, array_len, idata;
	const char *tmp_string = NULL;

	array_len = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), np,
		"pls_para", DC_PLS_PARA_MAX_SIZE, DC_PLS_PARA_TOTAL);
	if (array_len < 0) {
		hwlog_info("parse pls_para failed\n");
		return -EINVAL;
	}

	for (i = 0; i < array_len; i++) {
		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG), np, "pls_para", i, &tmp_string))
			return -EINVAL;
		row = i / DC_PLS_PARA_TOTAL;
		col = i % DC_PLS_PARA_TOTAL;
		switch (col) {
		case DC_PLS_PARA_BAT_ID:
			ret = strncpy_s(di->pls_para_group[row].batid, DC_PLS_BAT_BRAND_LEN_MAX, tmp_string,
				strlen(tmp_string));
			if (ret != EOK)
				return -EINVAL;
			break;
		case DC_PLS_PARA_TEMP_LOW:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return -EINVAL;
			di->pls_para_group[row].temp_low = idata;
			break;
		case DC_PLS_PARA_TEMP_HIGH:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return -EINVAL;
			di->pls_para_group[row].temp_high = idata;
			break;
		case DC_PLS_PARA_MODE:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return -EINVAL;
			di->pls_para_group[row].mode = idata;
			break;
		case DC_PLS_PARA_INDEX:
			ret = strncpy_s(di->pls_para_group[row].pls_stage_name, DC_PLS_STATUS_NAME_MAX_LEN,
				tmp_string, strlen(tmp_string));
			if (ret != EOK)
				return -EINVAL;
			break;
		default:
			break;
		}
	}

	di->pls_para_group_size = array_len / DC_PLS_PARA_TOTAL;
	return 0;
}

static int dc_pls_parse_dts(struct device_node *np, struct dc_pls_dev *di)
{
	int i, ret;
 
	ret = dc_pls_parse_pls_para(np, di);
	if (ret)
		return -EINVAL;

	for (i = 0; i < di->pls_para_group_size; i++)
		hwlog_info("pls_para[%d] %s %d %d %d %s\n", i, di->pls_para_group[i].batid,
			di->pls_para_group[i].temp_low, di->pls_para_group[i].temp_high,
			di->pls_para_group[i].mode, di->pls_para_group[i].pls_stage_name);

	return dc_pls_parse_pls_status_para(np, di);
}

static int dc_pls_probe(struct platform_device *pdev)
{
	int ret;
	struct dc_pls_dev *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;
	np = di->dev->of_node;

	if (dc_pls_parse_dts(np, di)) {
		hwlog_err("%s parse dts failed\n", __func__);
		return -EINVAL;
	}

	hwlog_info("%s parse dts succ\n", __func__);
	INIT_WORK(&di->monitor_work, dc_pls_monitor_work);
	INIT_DELAYED_WORK(&di->restore_work, dc_pls_restore_work);

	di->dc_nb.notifier_call = dc_pls_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_DC, &di->dc_nb);
	if (ret)
		goto fail_free_mem;

	di->plugged_nb.notifier_call = dc_pls_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CONNECT, &di->plugged_nb);
	if (ret)
		goto fail_free_mem1;

	platform_set_drvdata(pdev, di);
	g_dc_pls_di = di;
	hwlog_info("%s probe succ\n", __func__);
	return 0;

fail_free_mem1:
	power_event_bnc_unregister(POWER_BNT_DC, &di->dc_nb);
fail_free_mem:
	kfree(di);
	g_dc_pls_di = NULL;
	return ret;
}

static int dc_pls_remove(struct platform_device *pdev)
{
	struct dc_pls_dev *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	power_event_bnc_unregister(POWER_BNT_CONNECT, &di->plugged_nb);
	power_event_bnc_unregister(POWER_BNT_DC, &di->dc_nb);
	platform_set_drvdata(pdev, NULL);
	kfree(di);
	g_dc_pls_di = NULL;
	return 0;
}

static const struct of_device_id dc_pls_match_table[] = {
	{
		.compatible = "huawei,direct_charge_pulse",
		.data = NULL,
	},
	{},
};

static struct platform_driver dc_pls_driver = {
	.probe = dc_pls_probe,
	.remove = dc_pls_remove,
	.driver = {
		.name = "huawei,direct_charge_pulse",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(dc_pls_match_table),
	},
};

static int __init dc_pls_init(void)
{
	return platform_driver_register(&dc_pls_driver);
}

static void __exit dc_pls_exit(void)
{
	platform_driver_unregister(&dc_pls_driver);
}

late_initcall(dc_pls_init);
module_exit(dc_pls_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("direct charge pulse driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");