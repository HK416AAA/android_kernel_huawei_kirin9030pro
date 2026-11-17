/*
 * dsm_usb.c
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
#include "usb.h"
#include "dsm_usb.h"
#include <dsm/dsm_pub.h>
#include <scsi/scsi_cmnd.h>
#include <linux/async.h>
#include <linux/of_gpio.h>
#include <securec.h>
#include <linux/kernel.h>

static bool dsm_usb_init_flag = false;
#define OK  0
#define ERR (-1)

#ifdef CONFIG_HISYSEVENT
struct error_no_usb_map {
	int error_no;
	char *name;
};

static int usb_errorno_to_str(int error_no, char *str, int str_len)
{
	int i;
	struct error_no_usb_map isp_error_no_usb_map[] = {
		{DSM_USB_SCSI_CMD_ERR, "DSM_USB_SCSI_CMD_ERR"},
		{DSM_USB_TIMEOUT_ERR, "DSM_USB_TIMEOUT_ERR"},
		{DSM_USB_SCSI_CMD_ABORT, "DSM_USB_SCSI_CMD_ABORT"},
		{DSM_USB_SCSI_RESET_DEVICE, "DSM_USB_SCSI_RESET_DEVICE"},
		{DSM_USB_SCSI_RESET_TARGET, "DSM_USB_SCSI_RESET_TARGET"},
		{DSM_USB_SCSI_RESET_BUS, "DSM_USB_SCSI_RESET_BUS"},
		{DSM_USB_SCSI_RESET_HOST, "DSM_USB_SCSI_RESET_HOST"},
		{DSM_USB_SCSI_RETRY_ERROR, "DSM_USB_SCSI_RETRY_ERROR"},
	};
	int isp_error_no_map_len = sizeof(isp_error_no_usb_map) / sizeof(struct error_no_usb_map);
	for (i = 0; i < isp_error_no_map_len; i++) {
		if (isp_error_no_usb_map[i].error_no == error_no) {
			if (strlen(isp_error_no_usb_map[i].name) >= str_len)
				return ERR;
			if (strncpy_s(str, str_len, isp_error_no_usb_map[i].name, str_len - 1) != EOK)
				return ERR;
			str[str_len - 1] = '\0';
			printk("dsm usb_errorno_to_str str=%s\n", str);
			return OK;
		}
	}
	return ERR;
}

enum hisysevent_type {
	/* fault event */
	FAULT = 1,
 
	/* statistic event */
	STATISTIC = 2,
 
	/* security event */
	SECURITY = 3,
 
	/* behavior event */
	BEHAVIOR = 4
};
 
static int usb_errorno_get_event_type(int error_no)
{
	return FAULT;
}

struct dsm_client_ops hisp_dsm_ops_usb = {
	.poll_state = NULL,
	.dump_func = NULL,
#ifdef CONFIG_HISYSEVENT
	.errorno_to_str = usb_errorno_to_str,
	.errorno_get_event_type = usb_errorno_get_event_type,
#endif
};
#endif

/* lint -e747 -e713 -e715 -e732 -e835 */
struct usb_dsm_log  g_usb_dsm_log;
struct dsm_client *usb_dclient;
unsigned int usb_dsm_real_upload_size;
static int dsm_usb_enable;
struct dsm_dev dsm_usb = {
#ifdef CONFIG_HISYSEVENT
	.name = "storage_dsm_usb_scsi_report",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &hisp_dsm_ops_usb,
	.buff_size = USB_DSM_BUFFER_SIZE,
#else
	.name = "dsm_usb_scsi_report",
	.buff_size = USB_DSM_BUFFER_SIZE,
#endif
};

struct dsm_err_type_category err_type_category[] = {
	{USB_TIMEOUT_ERR, DSM_USB_TIMEOUT_ERR, "USB TimeOut Error"},
	{USB_SCSI_CMD_ERR, DSM_USB_SCSI_CMD_ERR, "USB SCSI CMD Error"},
	{USB_SCSI_CMD_ABORT, DSM_USB_SCSI_CMD_ABORT, "USB SCSI CMD Abort"},
	{USB_SCSI_RESET_DEVICE, DSM_USB_SCSI_RESET_DEVICE, "USB SCSI Reset Device"},
	{USB_SCSI_RESET_TARGET, DSM_USB_SCSI_RESET_TARGET, "USB SCSI Reset Target"},
	{USB_SCSI_RESET_BUS, DSM_USB_SCSI_RESET_BUS, "USB SCSI Reset Bus"},
	{USB_SCSI_RESET_HOST, DSM_USB_SCSI_RESET_HOST, "USB SCSI Reset Host"},
	{USB_SCSI_RETRY_ERROR, DSM_USB_SCSI_RETRY_ERROR, "USB SCSI Retry Error"},
};

static struct dsm_usb_hievent_ns_record dsm_usb_hievent_ns_record_list[] = {
    {DSM_USB_TIMEOUT_ERR, 0},
    {DSM_USB_SCSI_CMD_ERR, 0},
	{DSM_USB_SCSI_CMD_ABORT, 0},
	{DSM_USB_SCSI_RESET_DEVICE, 0},
	{DSM_USB_SCSI_RESET_TARGET, 0},
	{DSM_USB_SCSI_RESET_BUS, 0},
	{DSM_USB_SCSI_RESET_HOST, 0},
	{DSM_USB_SCSI_RETRY_ERROR, 0},
};

EXPORT_SYMBOL(usb_dclient);

unsigned long dsm_usb_if_err(struct us_data *us)
{
	return us->dsm_adaptor.err_type;
}

bool should_dsm_usb_hievent_report(int err_code)
{
    u64 now = ktime_get_ns();
    for (int i = 0; i < (int)sizeof(dsm_usb_hievent_ns_record_list)/sizeof(dsm_usb_hievent_ns_record_list[0]); i++) {
        if (err_code == dsm_usb_hievent_ns_record_list[i].err_no) {
            if ((abs(now - dsm_usb_hievent_ns_record_list[i].last_report_time) > DSM_USB_HIEVENT_NS_THRESHOLD) ||
                (dsm_usb_hievent_ns_record_list[i].last_report_time == 0)) {
                dsm_usb_hievent_ns_record_list[i].last_report_time = now;
                return true;
            }
        }
    }
    return false;
} 

int dsm_usb_update_usb_info(struct us_data *us, int tag, int err_code)
{
	struct scsi_cmnd *scmd = NULL;
	int i;
	if (!dsm_usb_enabled())
		return -1;
	switch (err_code) {
	case DSM_USB_TIMEOUT_ERR:
		if (test_and_set_bit_lock(USB_TIMEOUT_ERR,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	case DSM_USB_SCSI_CMD_ERR:
		if (test_and_set_bit_lock(USB_SCSI_CMD_ERR,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	case DSM_USB_SCSI_CMD_ABORT:
		if (test_and_set_bit_lock(USB_SCSI_CMD_ABORT,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	case DSM_USB_SCSI_RESET_DEVICE:
		if (test_and_set_bit_lock(USB_SCSI_RESET_DEVICE,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	case DSM_USB_SCSI_RESET_TARGET:
		if (test_and_set_bit_lock(USB_SCSI_RESET_TARGET,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	case DSM_USB_SCSI_RESET_BUS:
		if (test_and_set_bit_lock(USB_SCSI_RESET_BUS,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	case DSM_USB_SCSI_RESET_HOST:
		if (test_and_set_bit_lock(USB_SCSI_RESET_HOST,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	case DSM_USB_SCSI_RETRY_ERROR:
		if (test_and_set_bit_lock(USB_SCSI_RETRY_ERROR,
			&us->dsm_adaptor.err_type))
			return -1;
        break;
	default:
		return -1;
	}
	if (tag != -1) {
		scmd = us->srb;
		for (i = 0; i < min(COMMAND_SIZE(scmd->cmnd[0]), MAX_CDB_SIZE); i++) {
		    us->dsm_adaptor.timeout_scmd[i] = scmd->cmnd[i];
        }
	} else {
		for (i = 0; i < MAX_CDB_SIZE; i++) {
		    us->dsm_adaptor.timeout_scmd[i] = 0;
        }
	}
	return 0;
}

static void update_common_err_log(struct us_data *us, char *log_buff, int *size,
	unsigned long code)
{
	int ret, i;
	if (*size < DSM_LOG_BUFF_LEFT) {
		printk("dsm log buff left space too small to load log.\n");
		return;
	}
	for (i = 0; i < COMMAND_SIZE(us->dsm_adaptor.timeout_scmd[0]); i++) {
		ret = snprintf(log_buff, *size, "%02x",
			us->dsm_adaptor.timeout_scmd[i]);
		log_buff += ret;
		*size -= ret;
	}
}

static int update_log_buff(struct us_data *us, char *log_buff,
	int *size, unsigned long code)
{
	switch (code) {
    case DSM_USB_SCSI_CMD_ERR:
		/* fall through */
	case DSM_USB_TIMEOUT_ERR:
		/* fall through */
	case DSM_USB_SCSI_CMD_ABORT:
		/* fall through */
	case DSM_USB_SCSI_RESET_DEVICE:
		/* fall through */
	case DSM_USB_SCSI_RESET_TARGET:
		/* fall through */
	case DSM_USB_SCSI_RESET_BUS:
		/* fall through */
	case DSM_USB_SCSI_RESET_HOST:
		/* fall through */
	case DSM_USB_SCSI_RETRY_ERROR:
		update_common_err_log(us, log_buff, size, code);
		break;
	default:
		printk("unknown error code: %lu\n", code);
		return -1;
	}
	return 0;
}

static void update_dsm_usb_basic_info(const struct us_data *us, char **dsm_log_buff_p, int *buff_size_p)
{
    int ret;
    const char *string;

    if (us->pusb_dev->manufacturer)
        string = us->pusb_dev->manufacturer;
    else if (us->unusual_dev->vendorName)
        string = us->unusual_dev->vendorName;
    else
        string = "Unknown";
    ret = snprintf(*dsm_log_buff_p, *buff_size_p, "manufacture:%s, ", string);
    printk("dsm_usb manufacture:%s\n", string);
	*dsm_log_buff_p += ret;
	*buff_size_p -= ret;

    if (us->pusb_dev->product)
        string = us->pusb_dev->product;
    else if (us->unusual_dev->productName)
        string = us->unusual_dev->productName;
    else
        string = "Unknown";
    ret = snprintf(*dsm_log_buff_p, *buff_size_p, "product:%s, ", string);
    printk("dsm_usb product:%s\n", string);
	*dsm_log_buff_p += ret;
	*buff_size_p -= ret;

    if (us->pusb_dev->serial)
        string = us->pusb_dev->serial;
    else
        string = "None";
    ret = snprintf(*dsm_log_buff_p, *buff_size_p, "serial:%s, ", string);
    printk("dsm_usb serial:%s\n", string);
	*dsm_log_buff_p += ret;
	*buff_size_p -= ret;
}

int dsm_usb_get_log(struct us_data *us, unsigned long code, char *err_msg)
{
	int ret, buff_size;
	char *dsm_log_buff = NULL;
	buff_size = sizeof(g_usb_dsm_log.dsm_log);
	dsm_log_buff = g_usb_dsm_log.dsm_log;
	if (!dsm_usb_enabled())
		return 0;
	memset(g_usb_dsm_log.dsm_log, 0, buff_size);

	update_dsm_usb_basic_info(us, &dsm_log_buff, &buff_size);

    printk("dsm_usb dsm_log_buff: %s\n", dsm_log_buff);

	ret = snprintf(dsm_log_buff, buff_size,
		", Error Num:%lu, %s, ",
		code, err_msg);
	dsm_log_buff += ret;
	buff_size -= ret;

	/* print scsi info */
	ret = update_log_buff(us, dsm_log_buff, &buff_size, code);
	if (ret) {
		printk("unknown error code: %lu\n", code);
		return 0;
	}
	if (buff_size <= 0) {
		usb_dsm_real_upload_size = sizeof(g_usb_dsm_log.dsm_log) - 1;
		printk("dsm log buff overflow!\n");
	} else {
		usb_dsm_real_upload_size = sizeof(g_usb_dsm_log.dsm_log) - (unsigned int)buff_size;
	}

	printk("dsm_log: %s\n", g_usb_dsm_log.dsm_log);
	printk("buff_size = %d\n", buff_size);
	return 1;
}

int dsm_usb_enabled(void)
{
	return dsm_usb_enable;
}

static void dsm_usb_err_handle(struct dsm_err_type_category usb_err,
    struct us_data *us)
{
    if (us->dsm_adaptor.err_type & (unsigned long)(unsigned)(1 << usb_err.err_bit)) {
        dsm_usb_log(us, usb_err.err_no, usb_err.err_desc);
        clear_bit_unlock(usb_err.err_bit, &us->dsm_adaptor.err_type);
    }
}

#ifdef CONFIG_HISYSEVENT
#ifndef CONFIG_LIBLINUX_UDK_USB
static bool dsm_hisysevent_is_ready()
{
	int count = 0;
	bool ret;
	struct file *filp;

	while (count < USB_DSM_RETRY_NUM) {
		filp = filp_open("/dev/bbox", O_WRONLY, 0);
		if (!filp || IS_ERR(filp)) {
			msleep(DELAY_MS_100);
			count++;
		} else {
			filp_close(filp, NULL);
			break;
		}
	}

	ret = (count < USB_DSM_RETRY_NUM)? true : false;
	return ret;
}
#endif
#endif

void dsm_usb_handle_work(struct work_struct *work)
{
	struct us_data *us;
	int len, i;

#ifdef CONFIG_HISYSEVENT
#ifndef CONFIG_LIBLINUX_UDK_USB
	if (!dsm_hisysevent_is_ready()) {
		printk("hisysevent is not ready after retry\n");
		return;
	}
#endif
#endif
	us = container_of(work, struct us_data, dsm_work);
	mutex_lock(&us->dev_mutex);
	len = sizeof(err_type_category) / sizeof(err_type_category[0]);
	for (i = 0; i < len; i++) {
		switch (err_type_category[i].err_bit) {
            default:
                dsm_usb_err_handle(err_type_category[i], us);
                break;
		}
	}
	mutex_unlock(&us->dev_mutex);
}

void schedule_usb_dsm_work(struct us_data *us)
{
	if ((dsm_usb_enabled()) && (dsm_usb_if_err(us)))
		queue_work(system_freezable_wq, &us->dsm_work);
}

void dsm_usb_init(struct us_data *us)
{
	int usb_volt_irq;
	struct usb_device *dev = us->pusb_dev;
    printk("dsm_usb_init start\n");
	memset((void*)&us->dsm_adaptor, 0, sizeof(us->dsm_adaptor));
	if (dsm_usb_init_flag == true) {
        INIT_WORK(&us->dsm_work, dsm_usb_handle_work);
        printk("dsm_usb_init has been inited, end\n");
		return;
	}
	usb_dclient = dsm_register_client(&dsm_usb);
	if (!usb_dclient) {
		printk("usb dclient init error");
		return;
	}
    dsm_usb_init_flag = true;
	INIT_WORK(&us->dsm_work, dsm_usb_handle_work);
	mutex_init(&g_usb_dsm_log.lock);
	dsm_usb_enable = 1;
    printk("dsm_usb_init end\n");
}
