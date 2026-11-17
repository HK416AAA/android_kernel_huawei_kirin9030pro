/*
 * Copyright (c) 2025-2025, Hisilicon Tech. Co., Ltd. All rights reserved.
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
#ifndef MDFX_NOTIFIER_H
#define MDFX_NOTIFIER_H

#include "mdfx_notify.h"

struct mdfx_notifier {
    struct raw_notifier_head visitor_notifier_list;
    struct blocking_notifier_head visitor_blocking_notifier_list;
};

struct mdfx_notifier *mdfx_get_notifier(uint64_t visitor_type);

#endif