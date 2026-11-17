/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef OAL_EXT_IF_H
#define OAL_EXT_IF_H

/* 其他头文件包含 */

#include "oal_types.h"
#include "oal_util.h"
#include "oal_util_wifi.h"
#include "oal_net.h"
#include "oal_net_wifi.h"
#include "oal_list.h"
#include "oal_schedule.h"
#include "oal_schedule_wifi.h"
#include "oal_hardware.h"
#include "oal_mm.h"
#include "oal_mm_wifi.h"
#include "plat_pm_wlan.h"
#include "hcc_comm.h"
#include "oal_mem.h"
#include "oal_hardware.h"
#include "oal_mutex.h"
#include "oam_ext_if.h"
#include "board_pm.h"
#include "bsp_memory.h"

#ifndef DECLARE_PACKED
#define DECLARE_PACKED
#endif
#ifndef OAL_DECLARE_PACKED
#define OAL_DECLARE_PACKED
#endif

OAL_STATIC OAL_INLINE void oal_smp_mb(void)
{
}

#define chr_exception(chr_errno)
#define chr_exception_p(chr_errno, chr_ptr, chr_len)
#define chr_exception_q(chr_errno, chr_flag, chr_ptr, chr_len)
#define chr_exception_report(excption_event, module, plant, subplant, errid)
#endif /* end of wal_ext_if.h */
