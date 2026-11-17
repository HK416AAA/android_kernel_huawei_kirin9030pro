/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HOST HAL MAIN
 * 作    者 :
 * 创建日期 : 2020年06月14日
 */

#include "host_hal_main.h"
#include "host_hal_tas.h"

void hal_main_init(void)
{
    wlan_hal_ops_init();
    hal_host_board_init();
    hal_host_ring_init();
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    hal_wifi_tas_init();
#endif
}

void hal_main_exit(void)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    hal_wifi_tas_deinit();
#endif
}
