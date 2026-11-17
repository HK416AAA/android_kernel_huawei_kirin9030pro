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
#ifndef MIPI_DSI_ASYNC_TEST_H
#define MIPI_DSI_ASYNC_TEST_H
#include "dkmd_connector.h"

struct dpu_connector;

int32_t kthread_mipi_async_test_init(struct dpu_connector  *pinfo);
void kthread_mipi_async_test_exit(void);
void mipi_async_test_send_flw_frame(struct dpu_connector *connector);

#endif