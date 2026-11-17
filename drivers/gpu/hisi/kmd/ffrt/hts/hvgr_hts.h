/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */


#ifndef HVGR_HTS_H
#define HVGR_HTS_H

#include "hvgr_version.h"
#include "hvgr_defs.h"

#define HTS_EVENT_REF_LOAD                      (0u << 1)
#define HTS_EVENT_REF_STORE                     (1u << 1)
#define HTS_EVENT_REF_CLEAR                     (2u << 1)
#define HTS_EVENT_CMD_START                      1

#define HVGR_HTS_EVENT_PAGES                     1
#if hvgr_version_lt(500)
#define HTS_EVENT_REGISTER_MAX                   256
#else
#define HTS_EVENT_REGISTER_MAX                   1024
#endif
#define DEV_GPU                                  2
#define HVGR_CLEAN_GPU_REF_RAM                   1
#define HVGR_CLEAN_HTS_EVENT                     2
#define HVGR_HTS_TRY_TIMES_MAX                   1000

#if hvgr_version_ge(500)
union hts_event_info {
	struct {
		uint32_t ssid : 12;
		uint32_t refcnt : 8;
		uint32_t resv : 12;
	} st;
	uint32_t value;
};
#endif
#endif