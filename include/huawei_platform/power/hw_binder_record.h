/*
* hw_binder_record.h
*
* This file use to record binder info, eg: timestamp
*
* Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
*
* This software is licensed under the terms of the GNU General Public
* License version 2, as published by the Free Software Foundation, and
* may be copied, distributed, and modified under those terms.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*/

#ifndef _HW_BINDER_RECORD_H
#define _HW_BINDER_RECORD_H

#include <linux/types.h>

void binder_record_add_record(const int caller_pid, const int callee_pid);
void binder_record_remove_pid(const int pid);

#endif /* _HW_BINDER_RECORD_H */