/*
 * hts_irq.h
 *
 * about hts irq
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

#ifndef _HTS_IRQ_H_
#define _HTS_IRQ_H_

#include <linux/atomic.h>
#include "hts_devinit.h"
#include "hts_platform.h"

struct hts_intr_info {
	struct work_struct intr_work[HTS_INTR_ERROR_NUM];
	struct workqueue_struct *intr_wq;
};

typedef enum {
	HTS_INTR_EXCEPT,
	HTS_INTR_MAX
} hts_intr_type;

struct hts_intr_proc_handle {
	hts_intr_error_type intr_type;
	void (*intr_proc_proc) (struct work_struct *work);
};

int hts_register_irq(struct hts_platform_info *platform_info);
void hts_unregister_irq(struct hts_platform_info *platform_info);
void hts_zero_eventid_func(struct work_struct *work);
void hts_event_in_check_func(struct work_struct *work);
void hts_ibuf_overflow_func(struct work_struct *work);
void hts_proc_no_rule_func(struct work_struct *work);
void hts_proc_illegal_rule_func(struct work_struct *work);
void hts_proc_cnt_overflow_func(struct work_struct *work);
void hts_obuf_overflow_func(struct work_struct *work);
#endif