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

#ifndef AAE_XPU_PROXY_H
#define AAE_XPU_PROXY_H

#include <linux/types.h>

/* 1.build the cmdlist ch7 node and send the address of ch7 to tzsp
 * 2.send the message to tzsp which build the cmdlist channel8 node. 
 */
int32_t aae_cmd_prepare(void);

/* destroy cmdlist ch7 node and reset the status of ch7 node */
void aae_cmd_destroy(void); 
#endif /* AAE_XPU_PROXY_H */