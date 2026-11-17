/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 *
 * file: bootfail_chipsets.h
 *
 * define platform-dependent common bootfail interfaces
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

#ifndef BOOTFAIL_CHIPSETS_H
#define BOOTFAIL_CHIPSETS_H

/* ---- includes ---- */
#include <linux/types.h>

/* ---- c++ support ---- */
#ifdef __cplusplus
extern "C" {
#endif

/* ---- export macroes ---- */
/* ---- export prototypes ---- */
/*---- export function prototypes ----*/
unsigned int get_bootup_time(void);
unsigned int get_long_timer_timeout_value(void);
unsigned int get_short_timer_timeout_value(void);
unsigned int get_action_timer_timeout_value(void);
char *get_bfi_dev_path(void);
size_t get_bfi_part_size(void);
long simulate_storge_rdonly(unsigned long arg);
#ifdef CONFIG_SHUT_DETECTOR
unsigned int get_shut_timer_timeout_value(void);
char *get_sfi_dev_path(void);
size_t get_sfi_part_size(void);
unsigned int get_sfi_dev_offset(void);
#endif
#ifdef CONFIG_BOOT_DETECTOR_SINGLE_FRAME
int kernel_bbox_notify(void);
#endif
#ifdef CONFIG_CPU_FAULT_HWDEGRADE_CDC
long read_soc_panic_info(char* buf);
long write_soc_panic_info(char* buf);
#define SOC_PANIC_INFO_OFFSET 0x7FCC00
#define SOC_PANIC_INFO_SIZE 0x3000
#endif

#ifdef CONFIG_USB_FAULT_ISOLATION_CDC
#define USB_FUALT_INFO_OFFSET 0x7FC800  // 8MB - 12KB(sizeof(struct soc_ft_policy)) - 1KB(sizeof(struct usb_ft_policy))
#define USB_FUALT_INFO_SIZE 1024
#define POWERKEY_INFO_SIZE 0x20
#define POWERKEY_INFO_OFFSET (USB_FUALT_INFO_OFFSET - POWERKEY_INFO_SIZE)
int read_usb_fault_info(char* buf);
int write_usb_fault_info(char* buf);

struct usb_hungtask_tsk_s {
	unsigned int magic;
	struct task_struct *tsk;
	int hungtask_time;
};
typedef void (*usb_hungtask_tsk_t)(struct usb_hungtask_tsk_s rec);
void register_usb_hungtask_tsk(usb_hungtask_tsk_t func);
#endif

/* ---- c++ support ---- */
#ifdef __cplusplus
}
#endif
#endif
