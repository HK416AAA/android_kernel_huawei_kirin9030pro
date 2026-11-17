/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: tas switch status
 * Author: platform drivers
 */

/* 头文件包含 */
#include "oal_tas_switch.h"
#include "oal_schedule.h"

OAL_STATIC int32_t g_oal_tas_status = 0;
oal_spin_lock_stru g_tas_spinlock;

void oal_tas_l5_switch_init(void)
{
    oal_spin_lock_init(&g_tas_spinlock);
}

void oal_tas_l5_switch_set(int32_t tas_status)
{
    unsigned long flags;
    oal_spin_lock_irq_save(&g_tas_spinlock, &flags);
    g_oal_tas_status = tas_status;
    oal_spin_unlock_irq_restore(&g_tas_spinlock, &flags);
}

int32_t oal_tas_l5_switch_get(void)
{
    return g_oal_tas_status;
}

oal_module_symbol(oal_tas_l5_switch_init);
oal_module_symbol(oal_tas_l5_switch_set);
oal_module_symbol(oal_tas_l5_switch_get);
oal_module_license("GPL");
