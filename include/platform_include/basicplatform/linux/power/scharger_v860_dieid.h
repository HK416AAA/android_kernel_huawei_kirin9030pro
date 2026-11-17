/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * scharger_v860_dieid.h
 *
 * dieid of schargerv860
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

#ifndef _SCHARGER_V860_DIEID_H_
#define _SCHARGER_V860_DIEID_H_

#ifdef CONFIG_SCHARGER_V860
int scharger_v860_get_dieid(char *dieid, unsigned int len);
#endif

#endif