/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * phase_amu_event.h
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

#ifndef __PHASE_AMU_EVENT_H
#define __PHASE_AMU_EVENT_H

#include <linux/types.h>

typedef enum {
	PHASE_AMU_EVENT_INACTIVE = 0,
	PHASE_AMU_EVENT_ACTIVE,
	PHASE_AMU_EVENT_MAX,
} phase_amu_status_t;

typedef struct phase_amu_event {
	u32 id;                    // event id.
	phase_amu_status_t status; // event status.
} phase_amu_event_t;

#ifdef CONFIG_PHASE_PERF_AMU

u64 phase_amu_event_count_read(phase_amu_event_t *pe);

phase_amu_event_t *phase_amu_event_create(u32 event_id);

void phase_amu_event_release(phase_amu_event_t *pe);

#else

static inline
u64 phase_amu_event_count_read(phase_amu_event_t *pe __maybe_unused)
{
	return 0;
}

static inline
phase_amu_event_t *phase_amu_event_create(u32 event_id __maybe_unused)
{
	return NULL;
}

static inline
void phase_amu_event_release(phase_amu_event_t *pe __maybe_unused)
{
}

#endif

#endif
