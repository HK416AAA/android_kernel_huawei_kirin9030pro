/*
* Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
* Description: interface defination for pcie power driver
*
* This software is distributed under the terms of the GNU General
* Public License ("GPL") as published by the Free Software Foundation,
* either version 2 of that License or (at your option) any later version.
*/
#ifndef _PCIE_POWER_H_
#define _PCIE_POWER_H_

#define HDD_POWER_GPIO_NUM  34
#define PCIE_ID_DEFAULT     0

void set_hdd_locked_stat(bool flag);

#endif