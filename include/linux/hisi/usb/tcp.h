/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2  of
 * the License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _TCP_H_
#define _TCP_H_
#include <linux/types.h>

int tcp_set_port_irq_status(int portid, bool enable_irq);
int tcp_do_suspend(void);
int tcp_do_resume(void);

#endif /* _TCP_H_ */
