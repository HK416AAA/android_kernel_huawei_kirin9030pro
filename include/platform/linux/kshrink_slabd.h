/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#ifndef _KSHRINK_SLABD_H
#define _KSHRINK_SLABD_H

#include <linux/gfp.h>
#include <linux/types.h>

bool should_shrink_slab_async(gfp_t gfp_mask, int nid,
	struct mem_cgroup *memcg, int priority);
bool is_kshrink_slabd_enable(void);

extern unsigned long shrink_slab(gfp_t gfp_mask, int nid,
	struct mem_cgroup *memcg, int priority);

#endif
