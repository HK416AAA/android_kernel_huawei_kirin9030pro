/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe低功耗头文件
 * 作    者 : y30038709
 * 创建日期 : 2025年6月25日
 */
#ifndef DPE_PM_H
#define DPE_PM_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_pm_wkup_src_parse_set(uint8_t en);
uint8_t dpe_pm_wkup_src_parse_get(void);
uint32_t wlan_pm_wkup_src_debug_get(void);
void wlan_pm_wkup_src_debug_set(uint32_t en);
#endif /* end of _PRE_MULTI_CORE_DPE_OFFLOAD */
#endif
