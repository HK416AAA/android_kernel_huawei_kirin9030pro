/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef CHR_PM_H
#define CHR_PM_H

#include "bsp_dpa_chr.h"

typedef struct {
    unsigned int dpa_chr_freq_duration_in_ms[MAX_DPA_FREQ_LEVEL];        /* 单位：毫秒ms, 个数：10 */
} dpa_chr_clk_info_s;

typedef struct {
    unsigned char irq_no[DPA_MAX_WAKEUP_SOURCE];
    unsigned int irq_wakeup_cnt[DPA_MAX_WAKEUP_SOURCE];                          /* 个数：10 */
    unsigned int dpa_wakeup_cnt;
    unsigned int dpa_on_duration_in_ms;
    unsigned int dpa_off_duration_in_ms;
} dpa_chr_pm_info_s;

typedef struct dpa_chr_dubai_info {
    dpa_chr_pm_info_s pm_info;
    dpa_chr_clk_info_s clk_info;
} dpa_chr_dubai_info_s;

#endif