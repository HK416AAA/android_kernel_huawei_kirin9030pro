/* SPDX-License-Identifier: GPL-2.0 */
/*
 * serial_gague_base.h
 *
 * serial gauge base driver header file
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#ifndef _SERIAL_GAUGE_BASE_H_
#define _SERIAL_GAUGE_BASE_H_

#include <asm/unaligned.h>
#include <linux/bitops.h>
#include <linux/firmware.h>
#include <linux/fs.h>
#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <linux/power_supply.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>

#define SERIAL_GAUGE_SUCCESS 0
#define SERIAL_GAUGE_FAILED (-1)
#define SERIAL_GAUGE_RETRY_COUNT 3
#define SERIAL_GAUGE_ENABLE 1
#define SERIAL_GAUGE_DISABLE 0
#define SERIAL_GAUGE_SINGLE_BIT_MASK 0xFF
#define SERIAL_GAUGE_SINGLE_BIT_LEN 8
#define SERIAL_GAUGE_U32_MASK 0xFFFFFFFF

#define SERIAL_GAUGE_APP_TYPE_APPA 0x00
#define SERIAL_GAUGE_APP_TYPE_APPB 0x01
#define SERIAL_GAUGE_APP_TYPE_BOOTLOADER 0x02

/* serial gauge reg map */
#define SERIAL_GAUGE_REG_TEMP 0x08              /* temperature */
#define SERIAL_GAUGE_REG_VOLT 0x09              /* voltage */
#define SERIAL_GAUGE_REG_CURR 0x0A              /* current */
#define SERIAL_GAUGE_REG_AVRGCURR 0x0B          /* average current */
#define SERIAL_GAUGE_REG_SOC 0x0D               /* relative state of charge */
#define SERIAL_GAUGE_REG_RM 0x0F                /* remaining capacity */
#define SERIAL_GAUGE_REG_FCC 0x10               /* full charge capacity */
#define SERIAL_GAUGE_REG_TTE 0x12               /* average time to empty */
#define SERIAL_GAUGE_REG_TTF 0x13               /* average time to full */
#define SERIAL_GAUGE_REG_CHARGING_CURRENT 0x14  /* charging current */
#define SERIAL_GAUGE_REG_CHARGING_VOLTAGE 0x15  /* charging voltage */
#define SERIAL_GAUGE_REG_BATTERY_STATUS 0x16    /* battery status */
#define SERIAL_GAUGE_REG_CYCLE 0x17             /* cycle count */
#define SERIAL_GAUGE_REG_DC 0x18                /* design capacity */
#define SERIAL_GAUGE_REG_MANUFACTURER_DATE 0x1B /* pack's manufcaturer date */
#define SERIAL_GAUGE_REG_MANUFACTURER_NAME 0x20 /* pack's manufacturer name */
#define SERIAL_GAUGE_REG_DEVICE_NAME 0x21       /* device name */
#define SERIAL_GAUGE_REG_CELL4_VOLT 0x3C        /* cell4 voltage */
#define SERIAL_GAUGE_REG_CELL3_VOLT 0x3D        /* cell3 voltage */
#define SERIAL_GAUGE_REG_CELL2_VOLT 0x3E        /* cell2 voltage */
#define SERIAL_GAUGE_REG_CELL1_VOLT 0x3F        /* cell1 voltage */
#define SERIAL_GAUGE_BLOCK_ADDR 0x44            /* manufacturer block access send or read cmd */
#define SERIAL_GAUGE_REG_SOH 0x4F               /* state of health */
#define SERIAL_GAUGE_REG_SAFETY_STATUS 0x51     /* safety status */
#define SERIAL_GAUGE_REG_PF_STATUS 0x53         /* PF status */
#define SERIAL_GAUGE_REG_OP_STATUS 0x54         /* Operation status */
#define SERIAL_GAUGE_REG_CHARGING_STATUS 0x55   /* Charging status */
#define SERIAL_GAUGE_REG_GAUGING_STATUS 0x56    /* Gauging status */
#define SERIAL_GAUGE_REG_MF_STAT 0x57           /* Manufacturing Status */
#define SERIAL_GAUGE_REG_APP_TYPE 0x7C          /* APP_TYPE */
#define SERIAL_GAUGE_REG_RUN_TIME 0x7D          /* APP run time */
#define SERIAL_GAUGE_REG_OP_STAT_L 0x89         /* operation status L */
#define SERIAL_GAUGE_REG_AFE_STATUS 0x8E        /* Afe sattus */
#define SERIAL_GAUGE_REG_CFET_STATUS_H 0x8f     /* cfet sattus H */
#define SERIAL_GAUGE_REG_CFET_STATUS_L 0x90     /* cfet sattus H */
#define SERIAL_GAUGE_REG_DFET_STATUS_H 0x91     /* cfet sattus H */
#define SERIAL_GAUGE_REG_DFET_STATUS_L 0x92     /* cfet sattus H */
#define SERIAL_GAUGE_REG_PS_STATUS 0x93         /* cfet sattus H */
#define SERIAL_GAUGE_REG_DEBUG_STATUS 0x94      /* cfet sattus H */

/* subcmd */
#define SERIAL_GAUGE_SUB_CMD_APP_VERSION 0x0002	  	  /* APP version */
#define SERIAL_GAUGE_SUB_CMD_HW_VERSION 0x0003    	  /* Hardware Version */
#define SERIAL_GAUGE_SUB_CMD_FULL_ACCESS 0x0032		  /* full access unlock */
#define SERIAL_GAUGE_SUB_CMD_DEVICE_RESET 0x0041 	  /* device soft reset */
#define SERIAL_GAUGE_SUB_CMD_CYCLE_CLEAR  0X0028      /* battery cycle clear */
#define SERIAL_GAUGE_SUB_CMD_MF_INFO 0x0070           /* ManufacturerInfo */
#define SERIAL_GAUGE_SUB_CMD_DA_STATUS1 0x0071        /* DAStatus1 */
#define SERIAL_GAUGE_SUB_CMD_DA_STATUS2 0x0072        /* temperature data */
#define SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS1 0x0073     /* GaugeStatus1 */
#define SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS2 0x0074     /* GaugeStatus2 */
#define SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS3 0x0075     /* GaugeStatus3 */
#define SERIAL_GAUGE_SUB_CMD_CB_STATUS1 0x0076        /* CBStatus */
#define SERIAL_GAUGE_SUB_CMD_SOH_FCC 0x0077           /* SOH_FCC */
#define SERIAL_GAUGE_SUB_CMD_CB_STATUS2 0x0079        /* CBStatus */
#define SERIAL_GAUGE_SUB_CMD_GAUGE_STATUS4 0x0083     /* GaugeStatus4 */
#define SERIAL_GAUGE_SUB_CMD_EB_STATUS1 0x0084        /* EBStatus1 */
#define SERIAL_GAUGE_PARAM_UPGRADE_SUB_CMD 0x0100	  /* param upgrade */
#define SERIAL_GAUGE_MODEL_UPGRADE_SUB_CMD 0x0101	  /* model upgrade */
#define SERIAL_GAUGE_MF_DATA_SUB_CMD 0x0102			  /* mf data read */
#define SERIAL_GAUGE_SUB_CMD_MODEL_VERSION 0x0201	  /* get model version */
#define SERIAL_GAUGE_SUB_CMD_SOC_BASP_VTERM 0x0210	  /* set basp vterm */
#define SERIAL_GAUGE_SUB_CMD_SOC_BASP_OCV 0x0211	  /* set basp battery ocv */
#define SERIAL_GAUGE_SUB_CMD_FW_UPGRADE 0x0F00		  /* fw upgrade operation */
#define SERIAL_GAUGE_SUB_CMD_RENTER_FW_UPGRADE 0x0F02 /* enter fw upgrade */
#define SERIAL_GAUGE_SUB_CMD_RENTER_FW_UPGRADE 0x0F02 /* clear user data */

#define SERIAL_GAUGE_CMD_LEN 1
#define FACTORY_DOWNLOAD_IS_RUN 1

#define SERIAL_GAUGE_OPERATION_MAX_SUB_STR 100
/* comon subcmd index and len */
#define SERIAL_GAUGE_SUB_CMD_LEN 2
#define SERIAL_GAUGE_BLOCK_BUF_ONLY_SUB_CMD_LEN (SERIAL_GAUGE_SUB_CMD_LEN + 1)
#define SERIAL_GAUGE_BLOCK_DATA_U32_LEN (SERIAL_GAUGE_SUB_CMD_LEN + 1 + 4)

/* upgrade wait file load */
#define GET_FILE_TRY_NUM 60
#define GET_FILE_ERROR_WAIT_TIME_MS 1000

#define GET_U16_FROM_U8_ARR2(data) (((data)[0]) | ((u16)((data)[1]) << 8))
#define GET_U32_FROM_U8_ARR4(data) (((data)[0]) | ((u32)((data)[1]) << 8) | \
	((u32)((data)[2]) << 16) | ((u32)((data)[3]) << 24))
#define U16_L_U8(val) ((u8)((val) & 0xFF))
#define U16_H_U8(val) ((u8)(((val) >> 8) & 0xFF))
#define U32_LL(data) ((data) & 0xFF)
#define U32_LH(data) (((data) >> 8) & 0xFF)
#define U32_HL(data) (((data) >> 16) & 0xFF)
#define U32_HH(data) (((data) >> 24) & 0xFF)

typedef enum {
	SERIAL_GAUGE_HW_VERSION_BEGIN,
	SERIAL_GAUGE_HW_VERSION_SERIAL_GAUGE,
	SERIAL_GAUGE_HW_VERSION_SY62540,
	SERIAL_GAUGE_HW_VERSION_JW3408,
	SERIAL_GAUGE_HW_VERSION_BK58540,
	SERIAL_GAUGE_HW_VERSION_END
} hw_version_type;

struct reg_cache_value {
	u32 safety_status;
	u32 pf_status;
	u32 op_status;
	u32 sohfcc;
};

struct serial_gauge_upgrade_info {
	u8 fw_upgrade_enable;
	u8 model_upgrade_enable;
	u8 param_upgrade_enable;
	u8 param_file_type;
	u8 upgrade_low_soc_enable;
	u8 upgrade_result;
	int upgrade_retry_num;
	u32 key;
};

struct serial_gauge_i2c_info {
	u8 read_data[SERIAL_GAUGE_OPERATION_MAX_SUB_STR];
	u8 write_data[SERIAL_GAUGE_OPERATION_MAX_SUB_STR];
	u16 read_len;
	u16 write_len;
};

struct serial_gauge_device {
	struct i2c_client *i2c;
	struct device *dev;
	struct device_node *dts_node;
	struct mutex *rw_lock;
	struct wakeup_source *wake_lock;
	struct workqueue_struct *serial_gauge_wq;
	struct delayed_work upgrade_work; 
	struct delayed_work soc_sync_rtc;
	struct delayed_work delay_send_work;
	struct delayed_work gauge_log_work;
	struct delayed_work mf_work;
	struct rtc_device *rtc_dev;
	struct notifier_block usb_event_nb;
	struct notifier_block reboot_event_nb;
	struct notifier_block std_event_nb;
	struct notifier_block tcon_logo_event_nb;
	struct device *sysfs_dev;
	struct reg_cache_value cache_value;
	struct serial_gauge_upgrade_info upgrade_info;
	struct serial_gauge_i2c_info i2c_info;
	int device_id;
	int support_i2c_crc;
	bool enter_std_proc;
	int power_saving_enable;
	bool is_usb_connected;
	u32 enable_factory_download;
	u32 factory_download_result;
	int block_delay;
	int power_off_retrieve_time;
	int upgrade_run;
	u32 fw_version;
	int write_mf_enable;
	int use_old_lqd;
};

struct file *serial_gauge_open_file(const char *path);
struct file *serial_gauge_try_to_get_file(const char *path);
int serial_gauge_file_read(struct file *fp, u8 *file_buf, size_t file_size, u32 offset);

struct serial_gauge_device *serial_gauge_get_di(void);
void serial_gauge_register(struct i2c_client *i2c, struct device_node *dts_node,
	struct mutex *rw_lock);
void serial_gauge_unregister(void);

int serial_gauge_read_word(u8 reg, u16 *data);
int serial_gauge_read_block(u8 reg, u8 *buf, u8 buf_len);
int serial_gauge_write_block(u8 reg, u8 *buf, u8 buf_len);
int serial_gauge_write_read_block(u8 *buf, u8 buf_len, u8 *data, u8 data_len);
int serial_gauge_write_read_check_block(u8 *wr_buf, u8 wbuf_len, u8 *rd_buf, u8 rbuf_len);

int judge_is_running_upgrade(void);

#endif /* _SERIAL_GAUGE_BASE_H_ */
