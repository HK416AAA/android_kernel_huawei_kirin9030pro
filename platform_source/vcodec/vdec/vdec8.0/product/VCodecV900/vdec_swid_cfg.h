/*
 * vdec_swid_cfg.h
 *
 * swid cfg file.
 *
 * Copyright (c) 2025-2025 Huawei Technologies CO., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef VDEC_SWID_CFG_H
#define VDEC_SWID_CFG_H

// smmu_pre channle id
#define VDE_RCHN_RV_INST	28
#define VDE_RCHN_RV_DATA	29
#define VDE_WCHN_RV_DATA	47

// pxp sc channel id
#define VDEC_RCHN_PXPC_START_SWID 21
#define VDEC_RCHN_PXPC_END_SWID   22 // vde_rchn_pxpc_sc + 1
#define VDEC_WCHN_PXPC_START_SWID 45
#define VDEC_WCHN_PXPC_END_SWID   47 // vde_wchn_pxpc1_sc + 1

#endif

