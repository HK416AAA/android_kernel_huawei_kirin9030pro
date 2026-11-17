/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oam_main.c header file
 * Author: dpa drivers
 */

#ifndef OAM_MAIN_H
#define OAM_MAIN_H

#include "oal_types.h"

void oam_log_set_log_level(uint8_t log_level);
int32_t oam_main_init(void);
void oam_main_deinit(void);

#endif /* end of oam_main */
