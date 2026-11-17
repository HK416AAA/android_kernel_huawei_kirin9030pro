/* SPDX-License-Identifier: GPL-2.0 */
/*
 * serial_gauge_data.h
 *
 * serial gauge data driver
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

#ifndef _SERIAL_GAUGE_DATA_H_
#define _SERIAL_GAUGE_DATA_H_

#include "serial_gauge_base.h"

#define SERIAL_GAUGE_RECORD_DATA_LOG "[SERIAL_GAUGE_DATA]"

#define DATA_SERIAL_GAUGE_SUB_CMD_L(sub_cmd) ((sub_cmd) & 0xFF)
#define DATA_SERIAL_GAUGE_SUB_CMD_H(sub_cmd) (((sub_cmd) >> 8) & 0xFF)

/* block len and index */
#define SERIAL_GAUGE_SUB_CMD_LEN 2
#define SERIAL_GAUGE_BLOCK_BUF_ONLY_SUB_CMD_LEN (SERIAL_GAUGE_SUB_CMD_LEN + 1)
#define SERIAL_GAUGE_BLOCK_DATA_U32_LEN (SERIAL_GAUGE_SUB_CMD_LEN + 1 + 4)
#define SERIAL_GAUGE_BLOCK_MAX_LEN 35
#define SERIAL_GAUGE_BLOCK_DATA_MAX_LEN 32

#define GAUGE_DATA_SUB_CMD_INDEX 1
#define GAUGE_DATA_SUB_CMD_INDEX_RESULT 3
#define GAUGE_DATA_SUB_CMD_RESULT_LEN 4
#define GAUGE_DATA_SUB_CMD_U32_LEN 7
#define GAUGE_DATA_SUB_CMD_U16_LEN 5
#define GAUGE_DATA_BLOCK_U32_LEN 5

/* data function */
int gauge_get_soc(u16 *soc);
int gauge_get_battery_status(u16 *battery_status);
int gauge_get_battery_cycle(u16 *cycle);
int gauge_get_battery_dc(u16 *dc);
int gauge_get_safety_status(u32 *safety_status);
int gauge_get_pf_status(u32 *pf_status);
int gauge_get_operation_status(u32 *operation_status);
int gauge_get_charging_status(u32 *charging_status);
int gauge_get_gauging_status(u32 *gauging_status);
int gauge_get_soh_fcc(u32 *soh_fcc);
int gauge_get_da_status1(void);
int gauge_get_da_status2(void);
int gauge_get_gauge_status1(u8 *data, u16 data_len);
int gauge_get_gauge_status2(u8 *data, u16 data_len);
int gauge_get_gauge_status3(u8 *data, u16 data_len);
int gauge_get_gauge_status4(u8 *data, u16 data_len);
int gauge_get_cb_status1(u8 *data, u16 data_len);
int gauge_get_cb_status2(u8 *data, u16 data_len);
int gauge_get_eb_status1(u8 *data, u16 data_len);

void check_download_status(void);

int gauge_send_vterm(u32 vterm);
int gauge_send_battery_ocv(u16 ocv);

int gauge_get_mf_status(u16 *status);
int gauge_get_afe_status(u16 *status);
int gauge_get_cfet_status_l(u16 *status);
int gauge_get_cfet_status_h(u16 *status);
int gauge_get_dfet_status_l(u16 *status);
int gauge_get_dfet_status_h(u16 *status);
int gauge_get_power_saving_status(u16 *status);
int gauge_get_d_status(u16 *status);
int gauge_get_run_time(u32 *data);

#endif /* _SERIAL_GAUGE_DATA_H_ */
