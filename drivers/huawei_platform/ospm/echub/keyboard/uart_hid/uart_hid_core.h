/*
 * Huawei uart hid Driver
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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

#ifndef UART_HID_CORE_H
#define UART_HID_CORE_H

#include <linux/regulator/consumer.h>
#include <linux/sched.h>
#include <linux/workqueue.h>
#include <linux/pm_wakeup.h>
#include <linux/time.h>
#include <linux/time64.h>
#include <linux/time_namespace.h>
#include <linux/timekeeping.h>


/* flags */
#define UART_HID_STARTED 0
#define UART_HID_SUSPEND 1
#define UART_HID_READ_SCHEDULE 2
#define UART_HID_WRITE_PENDING 3
#define UART_DEV_CHECK_RETRY_NUM 3
#define UART_DEV_CHECK_DELAY_TIME 30

#define SHIFT_OFFSET_1_BYTE 8
#define SHIFT_OFFSET_2_BYTE 16
#define SHIFT_OFFSET_3_BYTE 24

struct uart_hid_platform_data {
	u16 hid_descriptor_address;
	struct regulator_bulk_data supplies[2];
	int post_power_delay_ms;
	int irq_gpio; /* the device irq */
	int response_ec_gpio;
	int tty_baud; /* the tty_baudrate */
	const char *tty_name; /* tty name */
};

struct uart_hid_desc {
	__le16 hid_desc_length;
	__le16 bcd_version;
	__le16 report_desc_length;
	__le16 report_desc_register;
	__le16 input_register;
	__le16 max_input_length;
	__le16 output_register;
	__le16 max_output_length;
	__le16 command_register;
	__le16 data_register;
	__le16 vendor_id;
	__le16 product_id;
	__le16 version_id;
	__le32 reserved;
} __packed;

struct uart_hid {
	struct platform_device *pdev; /* platform_device  */
	struct hid_device *hid; /* pointer to corresponding HID dev */
	union {
		__u8 hdesc_buffer[sizeof(struct uart_hid_desc)];
		struct uart_hid_desc hdesc; /* the HID Descriptor */
	};
	__le16 hid_desc_reg; /* register of the HID descriptor. */
	unsigned int buf_size; /* uart buffer size */
	u8 *input_buf; /* Input buffer */
	u8 *cmd_buf; /* Command buffer */
	u8 *args_buf; /* Command arguments buffer */

	unsigned long flags; /* device flags */

	struct uart_hid_platform_data pdata;
	struct wakeup_source *wake;
	struct mutex send_lock;

	struct delayed_work read_work;
	struct work_struct notify_work;

	int irq;
};

int uart_hid_send_buf(struct uart_hid *ihid, u8 *out_buf, int len);

int uart_hid_get_irq_num(void);
struct timespec64 uart_hid_get_irq_ts(void);
#endif /* UART_HID_CORE_H */
