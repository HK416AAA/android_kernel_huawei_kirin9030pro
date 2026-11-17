/*
 * hts_arch_exception.h
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

#ifndef __HTS_ARCH_EXCEPTION_H_
#define __HTS_ARCH_EXCEPTION_H_
#include <linux/types.h>
#include "ffrt_configs.h"
#include <linux/cdev.h>

int hts_except_block_by_ip(soc_ip dev_id);
int hts_except_block_by_event(uint16_t event);
int hts_ffts_outbuff_except_block_by_event(uint16_t event);
int hts_except_block_by_proc(soc_ip dev_id, uint16_t uid);
int hts_store_event(uint16_t event_id);
int hts_unstore_event(uint16_t event_id);
int hts_lock_event_by_ip(soc_ip dev_id);
int hts_unlock_event_by_ip(soc_ip dev_id);
int hts_plat_notify_event_exception(soc_ip dev_id, int32_t pid);
#endif /* __HTS_ARCH_EXCEPTION_H_ */