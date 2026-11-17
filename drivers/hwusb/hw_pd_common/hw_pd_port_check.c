/*
 * hw_pd_port_check.c
 *
 * Source file of port check of huawei PD driver
 *
 * Copyright (c) 2022-2025 Huawei Device Co., Ltd.
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2025. All rights reserved.
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2025. All rights reserved.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <huawei_platform/power/huawei_charger.h>
#include <chipset_common/hwusb/hw_pd/hw_pd_state.h>
#include <chipset_common/hwusb/hw_pd/hw_pd_interface.h>
#include <chipset_common/hwusb/hw_pd/hw_pd_port_check.h>
 #include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <huawei_platform/log/hw_log.h>
#include <securec.h>

#ifndef HWLOG_TAG
#define HWLOG_TAG huawei_pd_port_check
HWLOG_REGIST();
#endif /* HWLOG_TAG */

#define CC_STATE_DEFAULT 0
#define PORT_CHECK_EVENT_LENGTH 22

static struct fod_ops *g_scharger_fod_ops = NULL;

int fod_ops_register(struct fod_ops* ops)
{
	int ret = 0;

	if (g_scharger_fod_ops) {
		hwlog_err("scharger_fod_ops register fail, g_scharger_fod_ops busy\n");
		return -EBUSY;
	}

	if (ops) {
		g_scharger_fod_ops = ops;
	} else {
		hwlog_err("scharger_fod_ops register fail\n");
		ret = -EPERM;
	}
	return ret;
}

void hw_pd_port_check_vbus(void)
{
	int ret;
	unsigned int cc1 = 0;
	unsigned int cc2 = 0;
	struct power_event_notify_data n_data = { 0 };

	hwlog_info("%s start\n", __func__);

	ret = hw_pd_get_cc_state(&cc1, &cc2);
	if (ret) {
		hwlog_info("%s get cc info fail\n", __func__);
		cc1 = CC_STATE_DEFAULT;
		cc2 = CC_STATE_DEFAULT;
	}
	hwlog_info("%s cc1=%d, cc2=%d\n", __func__, cc1, cc2);

	if ((cc1 != PD_DPM_CC_OPEN) || (cc2 != PD_DPM_CC_OPEN)) {
		hwlog_info("%s cc state is no open\n", __func__);
		/* The typc port is connected to a device */
		n_data.event = "UI_PORT_CHECK_STATUS=0";
		n_data.event_len = PORT_CHECK_EVENT_LENGTH; /* length of UI_PORT_CHECK_STATUS=0 */
		power_event_report_uevent(&n_data);
		return;
	}
	hw_pd_set_cc_to_ufp();

	if (g_scharger_fod_ops && g_scharger_fod_ops->is_fod_state) {
		if (g_scharger_fod_ops->is_fod_state()) {
			hwlog_info("%s port check abnormal\n", __func__);
			/* Meets the conditions for reporting port foreign object detection */
			n_data.event = "UI_PORT_CHECK_STATUS=2";
			n_data.event_len = PORT_CHECK_EVENT_LENGTH; /* length of UI_PORT_CHECK_STATUS=2 */
			power_event_report_uevent(&n_data);
		} else {
			hwlog_info("%s port check normal\n", __func__);
			/* The condition for reporting port foreign object detection is not met */
			n_data.event = "UI_PORT_CHECK_STATUS=1";
			n_data.event_len = PORT_CHECK_EVENT_LENGTH; /* length of UI_PORT_CHECK_STATUS=1 */
			power_event_report_uevent(&n_data);
		}
	} else {
		hwlog_info("%s g_scharger_fod_ops is not ops\n", __func__);
	}

	hw_pd_set_cc_mode(PD_DPM_CC_MODE_DRP);

	hwlog_info("%s end\n", __func__);
}
