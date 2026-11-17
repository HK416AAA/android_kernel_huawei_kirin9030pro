/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "sys_ifidx_convert.h"

bool is_nic_valid_check_by_id(int phy_id)
{
    return dpa_nic_invalid_check_by_id(phy_id);
}