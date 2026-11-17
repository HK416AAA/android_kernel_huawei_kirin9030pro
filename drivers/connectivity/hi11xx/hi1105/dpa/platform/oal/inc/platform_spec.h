/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef PLATFORM_SPEC_H
#define PLATFORM_SPEC_H

/* 其他头文件包含 */
/* 每个board支持chip的最大个数，总数不会超过8个 */
#ifdef _PRE_DUAL_CHIP
#define WLAN_CHIP_MAX_NUM_PER_BOARD 2
#else
#define WLAN_CHIP_MAX_NUM_PER_BOARD 1
#endif
#define WLAN_VAP_SUPPORT_MAX_NUM_LIMIT 6


#endif /* end of wal_ext_if.h */
