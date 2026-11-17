/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:oal_dft.h
 * Author: dpa drivers
 */

#define HISI_LOG_TAG "[DFT]"

#include "securec.h"
#include "oal_util.h"

char *g_mpxx_loglevel_format[] = {
    "[MPXX]"
    "[E]",
    "[MPXX]"
    "[W]",
    "[MPXX]"
    "[I]",
    "[MPXX]"
    "[D]",
    "[MPXX]"
    "[V]"
};

int32_t g_mpxx_loglevel = MPXX_LOG_INFO;
