/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe低功耗相关文件
 * 作    者 : y30038709
 * 创建日期 : 2025年6月25日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_wlan_resource.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_PM_C

static uint8_t g_wlan_wkup_src_parse_switch = OAL_FALSE;

void dpe_pm_wkup_src_parse_set(uint8_t en)
{
    g_wlan_wkup_src_parse_switch = en;
}
uint8_t dpe_pm_wkup_src_parse_get(void)
{
    return g_wlan_wkup_src_parse_switch;
}
#endif
