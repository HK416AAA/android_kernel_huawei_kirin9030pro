/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * sc6605_manager.h
 *
 * sc6605 manager driver header file
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
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

#ifndef _SC6605_MANAGER_H_
#define _SC6605_MANAGER_H_

#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of_platform.h>
#include <linux/regmap.h>
#include <linux/atomic.h>
#include <linux/of.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/power_supply.h>
#include <linux/kernel.h>
#include <linux/irq.h>
#include <linux/kthread.h>
#include <linux/of_device.h>
#include <securec.h>

#define SC6605_DEVICE_ID                   0X66

/* SC6605 IRQ NUM */
#define SC6605_IRQ_CHARGER                 0
#define SC6605_IRQ_DVCHG                   1
#define SC6605_IRQ_LED                     2
#define SC6605_IRQ_DPDM                    3
#define SC6605_IRQ_UFCS                    5
#define SC6605_IRQ_SCP                     6
#define SC6605_IRQ_CID                     7
#define SC6605_IRQ_HK                      8
#define SC6605_IRQ_MAX                     10
#define IQR_MASK                           0xff

#define REG_COUNT1                         1
#define REG_COUNT2                         2
#define REG_COUNT3                         3
#define SC6605_REG_SHIFT8                  8
#define SC6605_REG_SHIFT16                 16

#define SC6605_SLAVE_CHG                   0
#define SC6605_SLAVE_UFCS                  1
#define SC6605_SLAVE_MAX                   2

static const u8 sc6605_slave_addr[] = {
	0x61, 0x63,
};
struct sc6605_reg_field {
	uint32_t reg;
	uint32_t lsb;
	uint32_t msb;
};

#define SC6605_REG_FIELD(_reg, _lsb, _msb) {.reg = _reg, .lsb = _lsb, .msb = _msb,}

enum DPDM_DRIVE {
	DPDM_HIZ = 0,
	DPDM_20K_DOWN,
	DPDM_V0_6,
	DPDM_V1_8,
	DPDM_V2_7,
	DPDM_V3_3,
	DPDM_500K_DOWN,
};

enum {
	SC6605_REG_DEVICE_ID = 0X00,
	SC6605_REG_HK_GEN_STATE,
	SC6605_REG_HK_GEN_FLG,
	SC6605_REG_HK_GEN_MASK,
	SC6605_REG_VAC_VBUS_OVP,
	SC6605_REG_TSBUS_FAULT,
	SC6605_REG_TSBAT_FAULT,
	SC6605_REG_HK_CTRL,
	SC6605_REG_HK_INT_STAT = 0X09,
	SC6605_REG_HK_INT_FLG,
	SC6605_REG_HK_INT_MASK,
	SC6605_REG_HK_FLT_STAT,
	SC6605_REG_HK_FLT_FLG,
	SC6605_REG_HK_FLT_MASK,
	SC6605_REG_HK_ADC_CTRL,
	SC6605_REG_HK_IBUS_ADC = 0X11,
	SC6605_REG_HK_VBUS_ADC = 0X13,
	SC6605_REG_HK_VAC_ADC = 0X15,
	SC6605_REG_HK_VBATSNS_ADC = 0X17,
	SC6605_REG_HK_VBAT_ADC = 0X19,
	SC6605_REG_HK_IBAT_ADC = 0X1B,
	SC6605_REG_HK_VSYS_ADC = 0X1D,
	SC6605_REG_HK_TSBUS_ADC = 0X1F,
	SC6605_REG_HK_TSBAT_ADC = 0X21,
	SC6605_REG_HK_TDIE_ADC = 0X23,
	SC6605_REG_HK_BATID_ADC = 0X25,
	SC6605_REG_EDL_BUFFER = 0x27,

	/* Buck charger Reg */
	SC6605_REG_VSYS_MIN = 0x30,
	SC6605_REG_VBAT,
	SC6605_REG_ICHG_CC,
	SC6605_REG_VINDPM,
	SC6605_REG_IINDPM,
	SC6605_REG_ICO_CTRL,
	SC6605_REG_PRECHARGE_CTRL,
	SC6605_REG_TERMINATION_CTRL,
	SC6605_REG_RECHARGE_CTRL,
	SC6605_REG_VBOOST_CTRL,
	SC6605_REG_PROTECTION_DIS,
	SC6605_REG_RESET_CTRL,
	SC6605_REG_CHG_CTRL,
	SC6605_REG_CHG_INT_STAT = 0x41,
	SC6605_REG_CHG_INT_FLG = 0x44,
	SC6605_REG_CHG_INT_MASK = 0x47,
	SC6605_REG_CHG_FLT_STAT = 0x50,
	SC6605_REG_CHG_FLT_FLG = 0x52,
	SC6605_REG_CHG_FLT_MASK = 0x54,
	SC6605_REG_JEITA_TEMP = 0x56,
	SC6605_REG_BUCK_STAT,
	SC6605_REG_BUCK_FLG,
	SC6605_REG_BUCK_MASK,
	SC6605_REG_OTG_OVP = 0x5B,
	SC6605_REG_Internal = 0x5D,

	/* DC Reg */
	SC6605_REG_VBAT_SNS_OVP_DIS = 0x60,
	SC6605_REG_IBUS_OCP_UCP,
	SC6605_REG_VBUS2OUT_OVP,
	SC6605_REG_VBUS2OUT_UVP,
	SC6605_REG_CP_CTRL_1,
	SC6605_REG_CP_CTRL_2, 
	SC6605_REG_CP_INT_STAT,
	SC6605_REG_CP_INT_FLG,
	SC6605_REG_CP_INT_MASK,
	SC6605_REG_CP_FLT_STAT_1,
	SC6605_REG_CP_FLT_STAT_2,
	SC6605_REG_CP_FLT_FLG_1,
	SC6605_REG_CP_FLT_FLG_2,
	SC6605_REG_CP_FLT_MASK_1,
	SC6605_REG_CP_FLT_MASK_2,
	SC6605_REG_CP_FLT_DIS,
	SC6605_REG_CP_CTRL_3 = 0x73, 
	SC6605_REG_CP_CTRL_4 = 0x77,

	/* Dpdm charger Reg */
	SC6605_REG_DPDM_EN = 0x90,
	SC6605_REG_DPDM_CTRL,
	SC6605_REG_DPDM_FC_CTRL,
	SC6605_REG_DPDM_TFCP_CTRL,
	SC6605_REG_DPDM_INT_FLAG,
	SC6605_REG_DPDM_INT_MASK,
	SC6605_REG_FC3_INT_FLAG,
	SC6605_REG_FC3_INT_MASK,
	SC6605_REG_DP_STAT,
	SC6605_REG_DM_STAT,
	SC6605_REG_DPDM_INTERNAL,
	SC6605_REG_DPDM_CTRL_2 = 0x9D,
	SC6605_REG_DPDM_NONSTD_STAT,

	/* SCP Reg */
	SC6605_REG_SCP_EN = 0x9F,
	SC6605_REG_SCP_WDATA = 0xAB,
	SC6605_REG_SCP_RDATA,
	SC6605_REG_SCP_FIFO_STAT,
	SC6605_REG_SCP_STAT,
	SC6605_REG_SCP_FLAG_MASK,

	/* led Reg */
	SC6605_REG_LED_EN = 0xD4,

	/* UFCS Reg */   
	SC6605_REG_UFCS_CTRL_1 = 0x0100,
	SC6605_REG_UFCS_CTRL_2,
	SC6605_REG_UFCS_INT_FLAG1 = 0x0103,
	SC6605_REG_TX_LENGTH = 0x0109,
	SC6605_REG_TX_BUFFER0 = 0x010A,
	SC6605_REG_RX_LENGTH = 0x012E,
	SC6605_REG_RX_BUFFER0 = 0x012F,
	SC6605_REG_UFCS_OPTION2 = 0x0170,
	SC6605_REG_UFCS_OPTION4 = 0x0172,
	SC6605_REG_UFCS_OPTION5 = 0x0175,

	SC6605_REG_MAX,
};

static const int boost_curr[] = {
	500, 900, 1300, 1500, 2100, 2500, 2900, 3250,
};

static const int vindpm[] = {
	4000, 4100, 4200, 4300, 4400, 4500, 4600, 4700, 4800,
	7600, 8200, 8400, 8600, 10000, 10500, 10700,
};

static const int rechg_volt[] = {
	100, 200, 300, 400,
};

static const int sc6605_chg_wd_time[] = {
	0, 500, 1000, 2000, 20000, 40000, 80000, 160000,
};

struct sc6605_device {
	struct device *dev;
	struct i2c_client *i2c[SC6605_SLAVE_MAX];
	int irqn;
	struct irq_domain *domain;
	struct irq_chip irq_chip;
	struct mutex irq_lock;
	uint8_t irq_mask;
	atomic_t in_sleep;
	struct regmap *rmap;
};

#endif /* _SC6605_MANAGER_H_ */