/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * phase_amu_event.c
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/slab.h>
#include <linux/limits.h>
#include <linux/printk.h>

#include <securec.h>

#include <platform_include/cee/linux/amuv1.h>

#include "phase_amu_event.h"

u64 phase_amu_event_count_read(phase_amu_event_t *pe)
{
	if (pe == NULL || pe->status == PHASE_AMU_EVENT_INACTIVE)
		return 0;

	return amu_read_counter(pe->id);
}

phase_amu_event_t *phase_amu_event_create(u32 event_id)
{
	int ret = 0;
	phase_amu_event_t *pe = NULL;

	pe = kzalloc(sizeof(phase_amu_event_t), GFP_KERNEL);
	if (pe == NULL) {
		pr_err("phase_amu_event_create, alloc failed\n");
		return NULL;
	}

	ret = amu_counter_enable(event_id);
	if (ret != 0) {
		kfree(pe);
		pr_err("phase_amu_event_create, enable failed\n");
		return NULL;
	}

	pe->id = event_id;
	pe->status = PHASE_AMU_EVENT_ACTIVE;

	return pe;
}

void phase_amu_event_release(phase_amu_event_t *pe)
{
	int ret = 0;

	if (pe == NULL)
		return;

	pe->status = PHASE_AMU_EVENT_INACTIVE;

	ret = amu_counter_disable(pe->id);
	if (ret != 0)
		pr_err("phase_amu_event_release, disable failed\n");

	(void)memset_s(pe, sizeof(*pe), 0, sizeof(*pe));

	kfree(pe);
}
