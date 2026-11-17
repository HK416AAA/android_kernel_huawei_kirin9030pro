/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for oam
 * Author: plat drivers
 */

#include "hal_log.h"
#include "plat_debug.h"
#include "plat_oam.h"
#include "mpxx_oam.h"

void plat_oam_register_save_handle(plat_oam_save_handle handle)
{
    PRINT_INFO("plat_oam_register_save_handle %p.", handle);
    g_plat_oam_save_handle = handle;
}
