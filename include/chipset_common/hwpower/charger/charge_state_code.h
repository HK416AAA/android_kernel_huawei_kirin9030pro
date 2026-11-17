/* SPDX-License-Identifier: GPL-2.0 */
/*
 * charge_state_code.h
 *
 * status process interface for charge
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#ifndef _CHARGE_STATE_CODE_H_
#define _CHARGE_STATE_CODE_H_

#include <linux/kernel.h>
#include <linux/stat.h>

#define CSC_DC_BASE           10
#define CSC_WL_BASE           100
#define CSC_FG_BASE           200
#define CSC_BUCK_BASE         300
#define CSC_BC12_BASE         350
#define CSC_PUBLIC_MSG_LIMIT   10
#define CSC_DC_ADAPTER_BASE    20
#define CSC_DC_CHECK_BASE      30
#define CSC_DC_CHECK_INTF_BASE 60
#define INVALID_RETURN         "invalid"
#define NULL_RETURN	           ""

typedef enum {
    STEP_SUCCESS = 0,
	STEP_RECORD,
    STEP_ERROR,
	STEP_INVALID,
} StepStatus;

enum charge_csc_flow_list {
	CSC_FLOW_BEGIN,
	CSC_CHARGE_ICON,
	CSC_UI_POWER,
	CSC_TURBO_STATUS,
	CSC_BC12_TYPE,                                 /* 0:SDP to 12:POGOPIN from charger_type.h */
	CSC_PD_TRY_SCP = CSC_PUBLIC_MSG_LIMIT + 1,
	CSC_DC_ADAPTER_DETECT = CSC_DC_ADAPTER_BASE,   /* 20 */
	CSC_DC_ADAPTER_PING,
	CSC_DC_PMODE_CHK,
	CSC_DC_CHECK_BEGIN = CSC_DC_CHECK_BASE,        /* 30:checkbegin to 52:CHECK_ABEND_2, from fsm_charging_map */
	CSC_DC_CHECK_START_CHK,
	CSC_DC_CHECK_ANOMALY_CHK,
	CSC_DC_CHECK_EVT_PRE_REPT,
	CSC_DC_CHECK_ANTIFAKE_CHK,
	CSC_DC_CHECK_PROT_CHK,                         /* 35 */
	CSC_DC_CHECK_EVT_REPT,
	CSC_DC_CHECK_MODE_RECHK,
	CSC_DC_CHECK_UPD_ADAP_INFO,
	CSC_DC_CHECK_BAT_CHK,
	CSC_DC_CHECK_ANTIFAKE_RECHK,                   /* 40 */
	CSC_DC_CHECK_SWITCH_PATH,
	CSC_DC_CHECK_WLTX_DOWN,
	CSC_DC_CHECK_INIT,
	CSC_DC_CHECK_VADAP_CHK,
	CSC_DC_CHECK_ILEAK_CHK,                        /* 45 */
	CSC_DC_CHECK_OPEN_CHK,
	CSC_DC_CHECK_WLTX_ON,
	CSC_DC_CHECK_RES_CHK,
	CSC_DC_CHECK_START_CHA,
	CSC_DC_CHECK_ABEND_RECHK,                      /* 50 */
	CSC_DC_CHECK_ABEND_1,
	CSC_DC_CHECK_ABEND_2,
	CSC_DC_CHECK_END,
	CSC_DC_CHECK_PORT_CHECK = CSC_DC_CHECK_INTF_BASE,
	CSC_DC_CHECK_CABLE_CHECK,
};

enum charge_csc_code_list {
	CSC_BEGIN,
	CSC_CHARGER_INSERT = CSC_BEGIN,
	CSC_BC12_RESULT,
	CSC_BUCK_CHARGE,
	CSC_START_CHECK = CSC_DC_BASE, /* 10 */
	CSC_MODE_MATCH,
	CSC_MODE_CHECK,
	CSC_FSM_STATE,
	CSC_DC_SUCC,
	/* for wireless charge */
	CSC_WL_START = CSC_WL_BASE, /* 100 */
	/* for fuel gauge */
	CSC_FG_START = CSC_FG_BASE, /* 200 */
	/* for buck charge */
	CSC_BUCK_START = CSC_BUCK_BASE, /* 300 */
};

void charge_state_code_set(unsigned int code, char *para);
void charge_csc_flow_add_step(int step_id, StepStatus status, const char* err_msg);

#endif /* _CHARGE_STATE_CODE_H_ */
