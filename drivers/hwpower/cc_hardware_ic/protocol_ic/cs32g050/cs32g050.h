/* SPDX-License-Identifier: GPL-2.0 */
/*
 * cs32g050.h
 *
 * cs32g050 driver
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
 *
 */

#ifndef _CS32G050_H_
#define _CS32G050_H_

#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/bitops.h>
#include <securec.h>

#define UFCS_MAX_IRQ_LEN                            2
#define CS32G050_UFCS_BUF_LEN_MAX                   63
#define CS32G050_IC_STATUS_LEN                      11
#define CS32G050_PWR_DOWN_DELAY                		5000
#define CS32G050_IIC_READY_CHECK_RETRY				5

struct cs32g050_pwr_ctrl {
	struct work_struct pwr_on_work;
	struct delayed_work pwr_down_work;
	bool is_power_on;
	bool is_slave_iic_ready;
};

struct cs32g050_ufcs_ram {
	u8 data[CS32G050_UFCS_BUF_LEN_MAX];
	u8 len;
	u8 state; /* 0: fifo is null, 1:data ready, read end set state 0 */
};

struct cs32g050_rvs_charge_power {
	int max_design_ibus;
	int max_design_vbus;
};

struct cs32g050_param {
	int scp_support;
	int fcp_support;
	int ufcs_support;
	int rscp_support;
	int rufcs_support;
};

struct cs32g050_fw_param {
	u8 *bin_file;
	int bin_size;
	int fw_update_mode;
	int fw_version;
};

#pragma pack(push, 1)
struct cs32g050_ic_info {
	u8 chip_id;
	u8 run_bank;
	u32 boot_version;
	u32 app_version;
	u8 fail_time;
};

union cs32g050_ic_status {
	struct cs32g050_ic_info info;
	u8 status[CS32G050_IC_STATUS_LEN];
};
#pragma pack(pop)

struct cs32g050_device_info {
	struct i2c_client *client;
	struct device *dev;
	struct work_struct irq_work;
	struct mutex accp_adapter_reg_lock;
	struct mutex cmd_write_lock;
	struct mutex ufcs_detect_lock;
	struct mutex pwr_ctrl_lock;
	struct notifier_block event_nb;
	struct wakeup_source *wakelock;
	struct delayed_work fw_work;
	struct work_struct fw_reboot_work;
	struct cs32g050_param param_dts;
	struct cs32g050_fw_param fw_param;
	struct cs32g050_rvs_charge_power rvs_charge_power;
	union cs32g050_ic_status ic_info;
	int gpio_rst;
	int gpio_en;
	int gpio_int;
	int irq_int;
	int chip_already_init;
	int device_id;
	bool usb_connect;
	bool otg_connect;
	bool ufcs_communicating_flag;
	bool ready_for_reboot;
	bool fw_update;
	u8 ufcs_irq[UFCS_MAX_IRQ_LEN];
	struct cs32g050_ufcs_ram ufcs_rx_fifo;
	bool scp_handshake_flag;
	bool is_in_rufcs_mode;
	bool is_rufcs_handshake_success;
	struct cs32g050_pwr_ctrl pwr_ctrl;
};

#define CS32G050_FW_VERSION_LEN                         15
#define CS32G050_FW_SOC_MIN                             0

/* CHIP ID */
#define CS32G050_CHIP_ID                                0x08
#define CS32G050_GET_IC_STATUS                          0x3A, 0x03, 0x00, 0x00
#define CS32G050_GET_IC_STATUS_BUF_LEN                  5

/* CS32G050 NORMAL CMD FORMAT: CMD + WR_DATA_LEN + SUB_CMD + PORT_NUM */
#define CS32G050_NORMAL_CMD_LEN                         4

#define CS32G050_CMD_DEFAULT                            0x0D
#define CS32G050_WR_DATA_LEN_DEFAULT                    0x02
#define CS32G050_PORT_DEFAULT                           0x00

/* READ IRQ REG */
#define CS32G050_GET_IRQ_STATUS_SUB_CMD                 0x04
#define CS32G050_IRQ_REG_NUM                            3

/* MUX_CTRL */
#define CS32G050_SET_MUX_CTRL_SUB_CMD                   0x16
#define CS32G050_MUX_CTRL_SCP                           0x00
#define CS32G050_MUX_CTRL_UFCS                          0x00
#define CS32G050_MUX_CTRL_RSCP                          0x01
#define CS32G050_MUX_CTRL_RUFCS                         0x01

/* USB_PROTOCOL MUX_CTRL */
#define CS32G050_SET_USB_PROTOCOL_MUX_SUB_CMD           0x1E

#define CS32G050_MUX_CTRL_USB                           0x00
#define CS32G050_MUX_CTRL_PROTOCOL                      0x01

/* IC_RESET */
#define CS32G050_IC_RESET_SUB_CMD                       0x21

/* CS32G050_RET_DATA reg=0x80 */
#define CS32G050_RET_DATA_REG                           0x80

/* CS32G050_PING_STATUS */
#define CS32G050_PING_STATUS_CMD_STATUS_MASK            0x03
#define CS32G050_PING_STATUS_CMD_STATUS_SHIFT           0
#define CS32G050_PING_STATUS_DATA_LEN_MASK              0xFC
#define CS32G050_PING_STATUS_DATA_LEN_SHIFT             2

#define CS32G050_PING_RETRY_MAX_CNT                     5
#define CS32G050_DEV_CHECK_RETRY_CNT                    3

#define CS32G050_CMD_STATUS_WAIT                        0
#define CS32G050_CMD_STATUS_COMPLETE                    1
#define CS32G050_CMD_STATUS_BUZY                        2
#define CS32G050_CMD_STATUS_ERROR                       3

void cs32g050_hard_reset(struct cs32g050_device_info *di);
int cs32g050_ic_reset(void *dev_data);
int cs32g050_driver_set_usb_protocol_mux(void *dev_data, u8 muxCtrlStatus);
int cs32g050_driver_set_mux_ctrl(void *dev_data, u8 muxCtrlStatus);
int cs32g050_read_irq_reg(void *dev_data, u8 *data, u8 len);
int cs32g050_get_ic_status(struct cs32g050_device_info *di);
int cs32g050_ic_pwr_switch(void *dev_data, bool is_pwr_on);
#endif /* _CS32G050_H_ */
