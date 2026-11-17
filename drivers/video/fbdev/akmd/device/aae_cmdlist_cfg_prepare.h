/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
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

#ifndef AAE_CMD_CFG_PREPARE_H
#define AAE_CMD_CFG_PREPARE_H

#include <linux/types.h>

/**
* @brief Build cmdlist for init register cfg, use cmdlist ch7 load.
* @return Cmdlist id.
*/
uint32_t build_ch7_cmdlist(void);
 
#endif /* AAE_CMD_CFG_PREPARE_H */