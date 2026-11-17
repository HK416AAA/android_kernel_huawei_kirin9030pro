/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#ifndef AAE_DACC_LOG_READ_H
#define AAE_DACC_LOG_READ_H

#include <linux/types.h>
#include "aae_manager.h"
#ifdef CONFIG_MDFX_KMD
void aae_dacc_log_read_init(char __iomem *aae_base);
void aae_dacc_log_read_deinit(void);
uint32_t aae_exception_dacc_log_dump(void);
void aae_dacc_log_thread_setup(struct aae_manager *aae_mgr);
void aae_dacc_log_thread_release(struct aae_manager *aae_mgr);
void aae_dacc_log_isr_handler(struct aae_manager *aae_mgr);
#else
#define aae_dacc_log_read_init(aae_base)
#define aae_dacc_log_read_deinit()
#define aae_exception_dacc_log_dump()
#define aae_dacc_log_thread_setup(aae_mgr)
#define aae_dacc_log_thread_release(aae_mgr)
#define aae_dacc_log_isr_handler(aae_mgr)
#endif

#endif