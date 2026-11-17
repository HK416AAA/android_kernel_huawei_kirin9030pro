/*
 * dsm_usb.h
 *
 * deal with dsm_usb
 *
 * Copyright (c) 2019 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef LINUX_DSM_USB_H
#define LINUX_DSM_USB_H

#ifdef CONFIG_HUAWEI_USB_DSM
#include <linux/time.h>
#include <dsm/dsm_pub.h>

struct us_data;

#ifndef min
	#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

#define USB_DSM_BUFFER_SIZE    1000
#define USB_MSG_MAX_SIZE        256

#define	DSM_USB_TIMEOUT_ERR			928008100
#define	DSM_USB_SCSI_CMD_ERR		928008101
#define	DSM_USB_SCSI_CMD_ABORT		928008103
#define	DSM_USB_SCSI_RESET_DEVICE	928008104
#define	DSM_USB_SCSI_RESET_TARGET	928008105
#define	DSM_USB_SCSI_RESET_BUS		928008106
#define	DSM_USB_SCSI_RESET_HOST		928008107
#define	DSM_USB_SCSI_RETRY_ERROR	928008108

#define DELAY_MS_100        100
#define MAX_ERR_DESCRIPTION 100

#define DSM_LOG_BUFF_LEFT   256
#define USB_DSM_RETRY_NUM   150

#define MAX_CDB_SIZE 16
#define SCSI_SENSE_BUFFERSIZE 96

extern struct dsm_client *usb_dclient;
extern unsigned int usb_dsm_real_upload_size;
extern struct usb_dsm_log g_usb_dsm_log;

struct dsm_err_type_category {
	unsigned long err_bit;
	unsigned long err_no;
	char err_desc[MAX_ERR_DESCRIPTION];
};

struct dsm_usb_hievent_ns_record {
    int err_no;
    u64 last_report_time;
};

#define DSM_USB_HIEVENT_NS_THRESHOLD 600000000000

struct usb_dsm_adaptor {
	unsigned long err_type;
#define	USB_TIMEOUT_ERR			0
#define	USB_SCSI_CMD_ERR		1
#define	USB_SCSI_CMD_ABORT		2
#define	USB_SCSI_RESET_DEVICE	3
#define	USB_SCSI_RESET_TARGET	4
#define	USB_SCSI_RESET_BUS		5
#define	USB_SCSI_RESET_HOST		6
#define	USB_SCSI_RETRY_ERROR	7

	/* for time out error */
	unsigned char timeout_scmd[MAX_CDB_SIZE];
	int scsi_status;
	char sense_buffer[SCSI_SENSE_BUFFERSIZE];
	u32 manufacturer_id;
};

struct dsm_usb_cmd_log_entry {
	u8 lun;
	u8 cmd_op;
	u8 dpo;
	u8 fua;
	sector_t lba;
	int transfer_len;
	unsigned int tag;
	ktime_t issue_time;
	ktime_t complete_time;
};

struct dsm_usb_cmd_log {
	unsigned int pos;
	struct dsm_usb_cmd_log_entry *cmd_log_entry;
};

struct usb_reset_info {
	struct dsm_usb_cmd_log *cmd_log;
	bool full_reset_flag;
};

struct usb_dsm_log {
	char dsm_log[USB_DSM_BUFFER_SIZE];
	struct mutex lock; /* mutex */
	struct usb_reset_info *usb_reset_dmd;
};

int dsm_usb_update_usb_info(struct us_data *us, int tag, int err_code);
int dsm_usb_get_log(struct us_data *us, unsigned long code, char *err_msg);
void dsm_usb_handle_work(struct work_struct *work);
int dsm_usb_enabled(void);
unsigned long dsm_usb_if_err(struct us_data *us);
void dsm_usb_init(struct us_data *us);
void schedule_usb_dsm_work(struct us_data *us);
bool should_dsm_usb_hievent_report(int err_code);

#define dsm_usb_log(hba, no, fmt, a...)\
	do {\
		char msg[USB_MSG_MAX_SIZE];\
		snprintf(msg, USB_MSG_MAX_SIZE - 1, fmt, ## a);\
		mutex_lock(&g_usb_dsm_log.lock);\
		if (dsm_usb_get_log(hba, (no), (msg))) {\
			if (!dsm_client_ocuppy(usb_dclient)) {\
				dsm_client_copy(usb_dclient, \
						g_usb_dsm_log.dsm_log, \
						usb_dsm_real_upload_size + 1);\
				dsm_client_notify(usb_dclient, (no));\
			} \
		} \
		mutex_unlock(&g_usb_dsm_log.lock);\
	} while (0)

#define dsm_usb_report(host, code)\
	do {\
		if (host->device_type == USB_DEVICE_TYPE) {\
			struct us_data *us = host_to_us(host);\
			if(should_dsm_usb_hievent_report(code) && us) {\
				dsm_usb_update_usb_info(us, 0, code);\
				schedule_usb_dsm_work(us);\
			} \
		} \
	} while (0)
#endif /* CONFIG_HUAWEI_USB_DSM */
#endif