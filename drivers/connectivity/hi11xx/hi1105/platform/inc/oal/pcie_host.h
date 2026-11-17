/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:PCIE host header file
 * Author: platform drivers
 */

#ifndef PCIE_HOST_H
#define PCIE_HOST_H

#if (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_GF61_HOST)
#include "pcie_host_gfxx.h"
#else
#include "pcie_host_mpxx.h"
#endif

#endif
