/*
 * hpd_rule.h
 *
 * about hpd rule
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __HPD_PROFILING_H_
#define __HPD_PROFILING_H_

#include <linux/types.h>
#include "hts_profiling.h"

void hts_dump_ffts_event_out_info(void);
void hts_dump_info(uint32_t id);
uint16_t hts_obuf_overflow_profiling(void);
uint16_t hts_ffts_obuf_overflow_profiling(void);
#endif