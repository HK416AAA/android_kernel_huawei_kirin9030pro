/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * onewire adapter driver.
 *
 * Copyright (c) 2006 Texas Instruments.
 * Copyright (c) 2007 MontaVista Software Inc.
 * Copyright (c) 2009 Provigent Ltd.
 *
 * ----------------------------------------------------------------------------
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * ----------------------------------------------------------------------------
 *
 */
 
#ifndef __ONEWIRE_H_
#define __ONEWIRE_H_

#include <linux/device.h>
#include <linux/list.h>
#include <linux/types.h>

/*
 * Several modes currently supported
 */
enum onewire_mode {
	INFINEON_MODE,
	ZG_MODE,
	FDW1210_MODE,
	FDW1230_MODE,
	ONEWIRE_MODE_MAX
};

#define CRC8 0
#define CRC16 1

#define CRC_MODE0 0
#define CRC_MODE1 1
#define CRC_MODE2 2
#define CRC_MODE_MAX 3

#define DELAY_TIME_500U                      1
#define DELAY_TIME_2P5M                      2
#define DELAY_TIME_15M                       3
#define DELAY_TIME_25M                       4
#define DELAY_TIME_50M                       5
#define DELAY_TIME_100M                      6
#define DELAY_TIME_120M                      7

#define MAX_ONEWIRE_MASTER                   5

struct onewire_crc_info{
  u8 crc_en;
  u8 crc_mode;
  u8 crc_toggle_out;
  u8 crc_refl_out;
  u8 crc_send_start_byte;
  u8 crc_resp_start_byte;
  u16 crc_poly;
  u16 crc_init_value;
};

struct onewire_data_op{
  u8  *send_buf;
  u8   send_len;
  u8  *recv_buf;
  u8   recv_len;
  u8   cmd_send_recv_crc_resp;
  u8   rsv1;
  u8   rsv2;
  u8   rsv3;
  u32  delay_time;
  struct onewire_crc_info crc_info[CRC_MODE_MAX];
};

extern struct list_head onewire_list;

struct onewire_adapter {
	struct module *owner;
	u32 bus_num;
	struct device dev;
	struct list_head	 list;
	int (*master_init)(struct onewire_adapter *adapter);
	int (*transfer_message)(struct onewire_adapter *adapter,
				struct onewire_data_op *dataop);
	int (*master_exit)(struct onewire_adapter *adapter);
};

#define to_onewire_adapter(d) container_of(d, struct onewire_adapter, dev)

static inline void *onewire_get_master(const struct onewire_adapter *adap)
{
	return dev_get_drvdata(&adap->dev);
}

static inline void onewire_set_adapdata(struct onewire_adapter *adap, void *data)
{
	dev_set_drvdata(&adap->dev, data);
}

int onewire_master_init(u32 bus_num);
int onewire_message_transfer(u32 bus_num, struct onewire_data_op *dataop);
int onewire_master_exit(u32 bus_num);
void onewire_add_adapter(struct onewire_adapter *adapter);
void onewire_del_adapter(struct onewire_adapter *adapter);

#endif