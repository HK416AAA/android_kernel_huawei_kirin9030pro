/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef MIPI_DSI_COMMAND_TEST_H
#define MIPI_DSI_COMMAND_TEST_H
 
#include "dkmd_mipi_dsi_itf.h"
 
void signal_mipi_sync_group_test(void);
void dual_mipi_sync_group_test(void);
 
void signal_mipi_async_short_hardwait_test(void);
void dual_mipi_async_short_hardwait_test(void);
void singal_mipi_async_long_hardwait_test(void);
 
void signal_mipi_sync_single_model_test(void);
void signal_mipi_async_signle_model_test(void);
 
struct mipi_payload {
    char payloads[10];
};
struct params_body {
    uint32_t panel_type;
    enum mipi_dsi_id dsi_id;
    enum mipi_dsi_power_mode power_mode;
    enum mipi_dsi_trans_mode trans_model; 
	uint32_t hardware_wait;
    uint32_t cmds_num;
};
 
#endif