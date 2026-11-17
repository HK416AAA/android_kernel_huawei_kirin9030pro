/*
 * Copyright (c) 2019-2019, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef MDFX_TRACING_H
#define MDFX_TRACING_H

#include <linux/semaphore.h>
#include "mdfx_uapi.h"

#define MDFX_MOD_ADD(x, y, z)	(((x) + (y)) % (z))
#define MDFX_MOD_SUB(x, y, z)	(((x) + (z) - (y)) % (z))

struct mdfx_tracing_ctrl {
    struct semaphore tracing_sem;
	struct mdfx_event tracing_event;
	bool dir_is_ok;
};

// manager a tracing buffer for each visitor
struct mdfx_tracing_buf {
	int tracing_index;
	char *tracing_buf_addr;
	spinlock_t tracing_lock;
};

void mdfx_tracing_init(struct mdfx_tracing_buf *tracing_buf);
void mdfx_tracing_deinit(struct mdfx_tracing_buf *tracing_buf);

#endif
