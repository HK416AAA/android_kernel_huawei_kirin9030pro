/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef HM_OS_SYS_H
#define HM_OS_SYS_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/slab.h>

/* error code */

#define VALUE_TRUE          1
#define VALUE_FALSE         0

#define MALLOC(x)           kzalloc(x, GFP_KERNEL)
#define FREE                kfree

void sys_log_print(const char *msg);
void sys_delay_ms(int ms);
int sys_reg_read(u32 addr, u8 *buf, int len);
int sys_reg_write(u32 addr, const u8 *buf, int len);
void *sys_malloc(u32 size);
void sys_free(void *buf);

#endif