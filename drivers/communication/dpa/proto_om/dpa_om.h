/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef DPA_OM_H
#define DPA_OM_H

#include "common_msg.h"
#include "sbr_prot_com.h"
#include "bsp_diag.h"

enum dpa_stack_om_functions_id {
    DPA_STACK_TCPDUMP_PKT,
    DPA_STACK_HIDS_PKT,

    DPA_STACK_OM_FUNCTIONS_END
};

enum {
    PKT_UPLINK = 1,
    PKT_DOWNLINK,
};

#endif