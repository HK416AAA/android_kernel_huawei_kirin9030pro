/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: manage the platfrom nv ram
 * Author: platform drivers
 */

#include "board.h"
#include "nvram_mp17c.h"
#include "plat_nvram.h"

plat_nvram_ops_stru g_plat_nvram_ops_mpxx;

plat_nvram_ops_stru *get_plat_nvram_ops(void)
{
    return &g_plat_nvram_ops_mpxx;
}
EXPORT_SYMBOL(get_plat_nvram_ops);