/*
* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
* Description: interface defination for usb hub
*
* This software is distributed under the terms of the GNU General
* Public License ("GPL") as published by the Free Software Foundation,
* either version 2 of that License or (at your option) any later version.
*/
#ifndef _HW_USB_HUB_H_
#define _HW_USB_HUB_H_
#define pr_fmt(fmt) "[usb_hub]: " fmt

#define GPIO_LOW 0
#define GPIO_HIGH 1
#define MAX_CMD_NUM 6

/* add regulator i2c transfer define */
#define REG_SEND_ADDR		0x38
#define REG_SEND_ADAPTER    0x07

#define ECHUB_SEND_BYTE_LEN		0x04
#define BIT_OFFSET				0x08
#define REG_DATE_LEN 			0x01
#define ECHUB_SEND_TRANS_LEN	0x02

#define SEC_TO_MILLISEC 1000
#define MILLISEC_TO_NANOSEC (1000 * 1000)

#define DP2VGA_RESET_GPIO		183
#define TIMER_DELAY      (100)
#define POWER_KEY_RELEASE 0
#define POWER_KEY_PRESS 1
#define DEFAULT_DELAY_TIME 0
#define RESET_TIME 100
#define S5_HUB_LEVEL2_POWERON_DELAYTIME 300
#define HUB_RESET_TIME (RESET_TIME * 5)
#define DEVICE_RESET_TIME (RESET_TIME * 15)
#define HUB_POWEROFF_TIME 1000
#define S5_HUB_POWEROFF_TIME (HUB_POWEROFF_TIME *2)
#define INIT_GPIO_SUCC 0
#define NO_GPIO_IN_DTS 1
#define INIT_GPIO_FAIL 2

struct usb_hub {
	struct device *dev;

	/* Usb-related power gpio info */
	u32 hub_bpwr_gpio;
	u32 hub_level2_bpwr_gpio;
	u32 hub_level2_bpwr2_gpio;
	u32 back_hub_reset_gpio;
	u32 usbhub_vdd_on_gpio;
	u32 usbhub_level2_vdd_on_gpio;
	u32 usbhub_1v05_gpio;
	u32 usbcam_pwr_en_gpio;
	u32 usbnet_power_gpio;
	u32 xh_hub_level1_reset_gpio;

	/* Save the usb camera power gpio status set in the BIOS phase */
	u32 bios_usbcam_pwr_status;
	u32 bios_usbnet_pwr_status;

	/* Some delay time required by the timing */
	u32 reset_or_bpwr_delay_time;
	u32 reset_or_bpwr2_delay_time;
	u32 hub_1v05_gpio_delay_time;
	u32 hub_vdd_gpio_delay_time;
	u32 hub_cam_gpio_delay_time;
	u32 hub_net_gpio_delay_time;
	u32 usbnet_reset_time;
	u32 usb_device_poweron_wait_time;
	u32 poweroff_time;
	u32 poweron_time;
	u32 hub_resume_soc_gpio;
	int wakeup_irq;
	u32 roothub_num;
	u32 hub_num;
	/* Info used to control the power supply on the EC */
	u32 ec_addr;
	u32 ec_cmd_nums;
	u32 ec_cmd_off_list[MAX_CMD_NUM];
	u32 ec_cmd_on_list[MAX_CMD_NUM];
	u32 ec_cmd_delay_time_list[MAX_CMD_NUM];

	/* Flag indicating whether S3 is powered off */
	u32 s3_is_off;

	/* Usb-related sysfs class */
	struct class *usb_hub_class;

	struct notifier_block usbhub_nb;
	struct notifier_block roothub_nb;
	struct mutex notify_count_lock;
	int notify_bus_add_count;
	int notify_roothub_resume_count;
	bool disable_usbhub_notifier;
	bool skip_s4;
	struct input_dev *input_dev;
    struct delayed_work power_event_work;
	struct delayed_work power_work;
	struct delayed_work power_work2;
};

#endif