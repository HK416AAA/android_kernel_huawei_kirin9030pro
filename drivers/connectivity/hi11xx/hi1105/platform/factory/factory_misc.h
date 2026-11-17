/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: factory_misc.c header file
 * Author: platform drivers
 */

#ifndef FACTORY_MISC_H
#define FACTORY_MISC_H

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include <linux/types.h>
#endif

int32_t factory_check_device_ready(void);
int32_t factory_dev_io_test(void);

#endif
