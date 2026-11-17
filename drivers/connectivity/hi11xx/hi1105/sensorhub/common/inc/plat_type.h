/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat type header file
 * Author: common drivers
 */

#ifndef PLAT_TYPE_H
#define PLAT_TYPE_H

#include "stdint.h"

#if (defined(_PRE_PC_LINT) || defined(WIN32))
#define unref_param(P)      (void)(P)
#else
#define unref_param(P)
#endif

#ifdef _PRE_LINUX_TEST
#define os_str_len(s) strlen(s)
#ifndef STATIC
#define STATIC
#endif
#else
#ifndef STATIC
#define STATIC static
#endif
#endif

#endif /* PLAT_TYPE_H */
