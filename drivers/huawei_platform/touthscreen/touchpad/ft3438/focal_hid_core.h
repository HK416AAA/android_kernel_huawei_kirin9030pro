/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/*
 *
 * FocalTech TouchScreen driver.
 *
 * Copyright (c) 2012-2020, Focaltech Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
/*****************************************************************************
*
* File Name: focal_hid_core.h

* Author: Focaltech Driver Team
*
* Created: 2025-12-05
*
* Abstract:
*
* Reference:
*
*****************************************************************************/


#ifndef __LINUX_FOCALTECH_CORE_H__
#define __LINUX_FOCALTECH_CORE_H__
#include <linux/firmware.h>
#include <linux/input.h>
#include <linux/i2c.h>
#include <linux/uaccess.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/input/mt.h>
#include <linux/hid.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <securec.h>
#include <linux/vmalloc.h>

#define ENABLE                              1
#define DISABLE                             0
#define     FTS_DEBUG_EN        1
#define		WRITE_REQUEST_SIZE	72
#define		READ_REQUEST_SIZE	6
#define		READ_RESPONSE_SIZE	66
#define 	CMD_ACK 		0xF0
#define     FTS_HID_BUFF_SIZE   64
#define FTS_MAX_COMMMAND_LENGTH             16
#define FILE_NAME_LENGTH                    128

//================================ CMD
#define		CMD_ENTER_UPGRADE_MODE			0x40
#define		CMD_CHECK_CURRENT_STATE			0x41
#define		CMD_READY_FOR_UPGRADE			0x42
#define		CMD_SEND_DATA				0x43
#define		CMD_UPGRADE_CHECKSUM			0x44
#define		CMD_EXIT_UPRADE_MODE			0x45
#define		CMD_USB_READ_UPGRADE_ID			0x46
#define		CMD_USB_ERASE_FLASH 			0x47
#define		CMD_USB_UPGRADE_MODE 			0x4B
#define		CMD_READ_REGISTER			0x50
#define		CMD_WRITE_REGISTER			0x51

#define     FTS_REG_CHIP_ID_H             0xA3
#define     FTS_REG_CHIP_ID_L             0x9F
#define     FTS_REG_FW_VERSION            0xA6


#define FTS_BOOT_ID_H    0x54
#define FTS_BOOT_ID_L    0x5E

#define FTS_CHIP_ID_H    0x54
#define FTS_CHIP_ID_L    0x52

#define FTS_DELAY_MS_10       10
#define FTS_DELAY_MS_50       50
#define FTS_DELAY_MS_200       200
#define FTS_DELAY_MS_500       500
#define FTS_DELAY_MS_100       100
#define FTS_DELAY_MAX       1000

#define FTS_DATA_LEN_2       2
#define FTS_DATA_LEN_5       5
#define FTS_DATA_LEN_4       4

#define FTS_DATA_LEN_3       3
#define FTS_RETRY_NUM_20       20
#define FTS_RETRY_NUM_50       50

#define FTS_RETRY_NUM_15       15
#define FTS_RETRY_NUM_100       100
#define FTS_RETRY_NUM_3       3


#define FTS_DATA_BYTE_2        2
#define FTS_BYTE_OFF_8         8
#define FTS_BYTE_OFF_16        16
#define FTS_BYTE_OFF_24        24
#define FTS_HOV_DATA_NUM        4
#define FTS_CMD_LEN_2            2
#define FTS_CMD_LEN_4            4
#define FTS_CMD_BYTE_0            0
#define FTS_CMD_BYTE_1            1
#define FTS_CMD_BYTE_2            2
#define FTS_CMD_BYTE_3            3
#define FTS_LOG_LEVEL_3           3

#define FTS_INDEX_2           2

#if FTS_DEBUG_EN
#define FTS_DEBUG(fmt, args...) do { \
    printk("[FTS_TS]%s:"fmt, __func__, ##args); \
} while (0)

#define FTS_FUNC_ENTER() do { \
    printk("[FTS_TS]%s: Enter\n", __func__); \
} while (0)

#define FTS_FUNC_EXIT() do { \
    printk("[FTS_TS]%s: Exit(%d)\n", __func__, __LINE__); \
} while (0)
#else /* #if FTS_DEBUG_EN */
#define FTS_DEBUG(fmt, args...)
#define FTS_FUNC_ENTER()
#define FTS_FUNC_EXIT()
#endif

#define FTS_INFO(fmt, args...) do { \
    printk(KERN_INFO "[FTS_TS/I]%s:"fmt"\n", __func__, ##args); \
} while (0)

#define FTS_ERROR(fmt, args...) do { \
    printk(KERN_ERR "[FTS_TS/E]%s:"fmt"\n", __func__, ##args); \
} while (0)

#define FTS_SYSFS_ECHO_ON(buf)      ((buf)[0] == '1')
#define FTS_SYSFS_ECHO_OFF(buf)     ((buf)[0] == '0')

#ifdef TOUCHPAD_FACTORY_ENABLE
// static struct early_suspend early_suspend;
struct ftxxxx_proc {
    struct proc_dir_entry *proc_entry;
    u8 opmode;
    u8 cmd_len;
    u8 cmd[FTS_MAX_COMMMAND_LENGTH];
};
#endif

struct fts_hid_data {
    struct i2c_client *client;
    struct device *dev;
    struct mutex bus_lock;
    struct mutex debug_lock;
    struct input_dev *ts_input_dev;
    struct input_dev *pen_input_dev;
    struct workqueue_struct *ts_workqueue;
    struct delayed_work fwupg_work;
    struct work_struct esd_work;
    struct delayed_work esdcheck_work;
    struct delayed_work input_init_work;
    struct work_struct recovery_work;
    struct gpio_desc *reset_gpio;
    unsigned long intr_jiffies;
    int irq;
    spinlock_t irq_lock;
    struct wakeup_source *ws;
#ifdef TOUCHPAD_FACTORY_ENABLE
    struct ftxxxx_proc proc;
#endif
    struct timer_list timer;
    bool suspended;
    bool irq_disabled;
    int log_level;
    bool gesture_mode;
    bool fw_loading;
    bool esd_support;
    u8 *bus_tx_buf;
    u8 *bus_rx_buf;
    struct hid_device *hdev;
};

#ifdef TOUCHPAD_FACTORY_ENABLE
void focal_hid2std(void);

int fts_reset(int hdelayms);

int fts_i2c_read(u8 *cmd, u32 cmdlen, u8 *data, u32 datalen);
int fts_i2c_write(u8 *writebuf, u32 writelen);
int fts_i2c_read_reg(u8 addr, u8 *value);
int fts_i2c_write_reg(u8 addr, u8 value);

int focal_bus_init(struct fts_hid_data *ts_data);
int focal_bus_exit(struct fts_hid_data *ts_data);
 
int fts_test_init(struct fts_hid_data *ts_data);
int fts_test_exit(struct fts_hid_data *ts_data);

int focal_create_apk_debug_channel(struct fts_hid_data *ts_data);
void focal_release_apk_debug_channel(struct fts_hid_data *ts_data);
 
int fts_create_sysfs(struct fts_hid_data *ts_data);
int fts_remove_sysfs(struct fts_hid_data *ts_data);
int focal_hid_upgrade_bin(char *fw_name);
#endif

int focal_fwupg_init(struct fts_hid_data *ts_data);
int focal_fwupg_exit(struct fts_hid_data *ts_data);


int fts_hw_reset(int hdelayms);


int focal_wait_tp_to_valid(void);

void focal_irq_disable(void);
void focal_irq_enable(void);

int fts_hid_write_reg(u8 addr, u8 value);
int fts_hid_read_reg(u8 addr, u8 *value);
int fts_hid_read_data(u8 *buf, size_t size);
int fts_hid_write_data(u8 *buf, size_t size);

int fts_hid_probe_entry(struct hid_device *hdev);

void focal_esdcheck_suspend(struct fts_hid_data *ts_data);
void focal_esdcheck_resume(struct fts_hid_data *ts_data);


int focal_esdcheck_init(struct fts_hid_data *ts_data);
int focal_esdcheck_exit(struct fts_hid_data *ts_data);
void focal_esdcheck_switch(struct fts_hid_data *ts_data, bool enable);
int fts_update_esd_value(u8 tp_esd_value, u8 lcd_esd_value);
int fts_recovery_state(struct fts_hid_data *ts_data);


extern struct fts_hid_data *fts_hid_data;


#endif /* __LINUX_FOCALTECH_CORE_H__ */

