/*
 * tcon_uart.h
 *
 * interface for huawei tcon_uart driver
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#ifndef _TCON_UART_H_
#define _TCON_UART_H_
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/workqueue.h>

/* success or fail */
#define TCON_UART_OK 0
#define TCON_UART_FAIL (-1)

#define tcon_log_pri(fmt, args...) \
do { \
		printk(KERN_ERR "[tcon_log] " fmt, ##args); \
} while (0)

struct tcon_uart {
	uint8_t support;
	const char *tty_name;
	u32 default_baud;
	struct delayed_work recv_work;
};

int tcon_uart_write(const char *buf, size_t len);
int tcon_uart_register(struct tcon_uart *uart);
#endif /* _TCON_UART_H_ */
