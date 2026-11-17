/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * bq25790_charger.h
 *
 * bq25790 driver
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

#ifndef _BQ25790_CHARGER_H_
#define _BQ25790_CHARGER_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/mutex.h>
#include <linux/i2c.h>
#include <linux/device.h>
#include <linux/workqueue.h>
#include <linux/bitops.h>
#include <securec.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>

/*************************struct define area***************************/
struct bq25790_device_info {
	struct i2c_client *client;
	struct device *dev;
	struct work_struct irq_work;
	struct delayed_work otg_work;
	int gpio_cd;
	int gpio_mosfet;
	int gpio_int;
	int gpio_lp;
	int irq_int;
	int irq_active;
	int device_id;
	u32 support_sc;
	u32 ic_role;
	u32 sc_max_input_current;
	u32 sc_max_charge_current;
	u32 lvc_max_input_current;
	u32 lvc_max_charge_current;
	u32 support_rchg_pd;
	u32 support_rvs_dc;
	u32 support_mosfet;
	struct dc_ic_ops sc_ops;
	struct dc_ic_ops lvc_ops;
	struct dc_batinfo_ops batinfo_ops;
	struct mutex io_lock;
	struct notifier_block event_nb;
	char name[CHIP_DEV_NAME_LEN];
	char ic_name[CHIP_DEV_NAME_LEN];
	u8 vendor_id;
	bool usb_plugged;
	bool probe_ok;
	bool otg_work_stop;
};

struct bq25790_dump_data {
	int vbus;
	int ibus;
	int vbat;
	int ibat;
	int vac1;
	int vac2;
	int temp;
};

/*************************marco define area***************************/
/* default value */
#define BQ25790_REG_NUM                              0x2F
#define BQ25790_FLAG_REG_NUM                         6
#define BQ25790_OTG_CURR_1P8A                        1800
#define BQ25790_OTG_CURR_2A                          2000
#define BQ25790_OTG_CURR_2P5A                        2500
#define BQ25790_OTG_CURR_3A                          3000
#define BQ25790_OTG_VOLT_5V                          5000
#define BQ25790_OTG_VOLT_9V                          9000
#define BQ25790_WORD_WR_LEN                          3

/* Register 00h */
#define BQ25790_REG_SYS_VOL                          0x00
#define BQ25790_VSYSMIN_MASK                         (BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define BQ25790_VSYSMIN_SHIFT                        0

/* Register 01h */
#define BQ25790_REG_VREG                             0x01
#define BQ25790_VREG_MASK                            (BIT(10) | BIT(9) | BIT(8) | BIT(7) | \
	BIT(6) | BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define BQ25790_VREG_SHIFT                           0
#define BQ25790_VREG_MIN_VOLTAGE                     3000
#define BQ25790_VREG_MAX_VOLTAGE                     18800
#define BQ25790_VREG_VOLTAGE_STEP                    10

/* Register 03h */
#define BQ25790_REG_ICHG                             0x03
#define BQ25790_ICHG_MASK                            (BIT(8) | BIT(7) | BIT(6) | BIT(5) | \
	BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define BQ25790_ICHG_SHIFT                           0
#define BQ25790_ICHG_MIN_CURRENT                     50
#define BQ25790_ICHG_MAX_CURRENT                     5000
#define BQ25790_ICHG_CURRENT_STEP                    10

/* Register 05h */
#define BQ25790_REG_VINDPM                           0x05
#define BQ25790_VINDPM_MIN_VOLTAGE                   3600
#define BQ25790_VINDPM_MAX_VOLTAGE                   22000
#define BQ25790_VINDPM_VOLTAGE_STEP                  100

/* Register 06h */
#define BQ25790_REG_ICL                              0x06
#define BQ25790_ICL_MASK                             (BIT(8) | BIT(7) | BIT(6) | BIT(5) | \
	BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define BQ25790_ICL_SHIFT                            0
#define BQ25790_ICL_MIN_CURRENT                      100
#define BQ25790_ICL_MAX_CURRENT                      3300
#define BQ25790_ICL_CURRENT_STEP                     10

/* Register 08h */
#define BQ25790_REG_PRECHG_CTRL                      0x08
#define BQ25790_VBAT_LOW_MASK                        (BIT(7) | BIT(6))
#define BQ25790_VBAT_LOW_SHIFT                       6
#define BQ25790_IPRECHG_MASK                         (BIT(5) | BIT(4) | BIT(3) | BIT(2) | \
	BIT(1) | BIT(0))
#define BQ25790_IPRECHG_SHIFT                        0
#define BQ25790_IPRECHG_MIN_CURRENT                  40
#define BQ25790_IPRECHG_MAX_CURRENT                  2000
#define BQ25790_IPRECHG_CURRENT_STEP                 40

/* Register 09h */
#define BQ25790_REG_TERM_CTRL                        0x09
#define BQ25790_REG_RST_MASK                         BIT(6)
#define BQ25790_REG_RST_SHIFT                        6
#define BQ25790_ITERM_MASK                           (BIT(4) | BIT(3) |	BIT(2) | BIT(1) | BIT(0))
#define BQ25790_ITERM_SHIFT                          0
#define BQ25790_ITERM_MIN_CURRENT                    40
#define BQ25790_ITERM_MAX_CURRENT                    1000
#define BQ25790_ITERM_CURRENT_STEP                   40

/* Register 0Ah */
#define BQ25790_REG_RECHG_CTRL                       0x0A
#define BQ25790_CELL_MASK                            (BIT(7) | BIT(6))
#define BQ25790_CELL_SHIFT                           6
#define BQ25790_VRECHG_MASK                          (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define BQ25790_VRECHG_SHIFT                         0

/* Register 0Bh */
#define BQ25790_REG_OTG_VOL                          0x0B
#define BQ25790_VOTG_MASK                            (BIT(10) | BIT(9) | BIT(8) | BIT(7) | \
	BIT(6) | BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define BQ25790_VOTG_SHIFT                           0
#define BQ25790_OTG_BASE_VOLTAGE                     2800
#define BQ25790_OTG_MIN_VOLTAGE                      2800
#define BQ25790_OTG_MAX_VOLTAGE                      22000
#define BQ25790_OTG_VOLTAGE_STEP                     10

/* Register 0Dh */
#define BQ25790_REG_OTG_CUR                          0x0D
#define BQ25790_IOTG_MASK                            (BIT(6) | BIT(5) | BIT(4) | BIT(3) | \
	BIT(2) | BIT(1) | BIT(0))
#define BQ25790_IOTG_SHIFT                           0
#define BQ25790_OTG_MIN_CURRENT                      120
#define BQ25790_OTG_MAX_CURRENT                      3320
#define BK8984_OTG_MAX_CURRENT                       4900
#define BQ25790_OTG_CURRENT_STEP                     40
#define BQ25790_OTG_CURR_OFFSET                      300

/* Register 0Eh */
#define BQ25790_REG_TIMER_CTRL                       0x0E
#define BQ25790_CHG_TIMER_EN_MASK                    BIT(3)
#define BQ25790_CHG_TIMER_EN_SHIFT                   3

/* Register 0Fh */
#define BQ25790_REG_CHG_CTRL                         0x0F
#define BQ25790_CHG_ENABLE_MASK                      BIT(5)
#define BQ25790_CHG_ENABLE_SHIFT                     5
#define BQ25790_ICO_ENABLE_MASK                      BIT(4)
#define BQ25790_ICO_ENABLE_SHIFT                     4
#define BQ25790_HIZ_ENABLE_MASK                      BIT(2)
#define BQ25790_HIZ_ENABLE_SHIFT                     2
#define BQ25790_TERM_ENABLE_MASK                     BIT(1)
#define BQ25790_TERM_ENABLE_SHIFT                    1

/* Register 10h */
#define BQ25790_REG_CHG_CTRL1                        0x10
#define BQ25790_VAC_OVP_MASK                         (BIT(5) | BIT(4))
#define BQ25790_VAC_OVP_SHIFT                        4
#define BQ25790_VAC_OVP_26V                          0
#define BQ25790_VAC_OVP_22V                          1
#define BQ25790_VAC_OVP_12V                          2
#define BQ25790_VAC_OVP_7V                           3
#define BQ25790_WDT_RST_ENABLE_MASK                  BIT(3)
#define BQ25790_WDT_RST_ENABLE_SHIFT                 3
#define BQ25790_WDT_TIMER_MASK                       (BIT(2) | BIT(1) | BIT(0))
#define BQ25790_WDT_TIMER_SHIFT                      0
#define BQ25790_WDT_DISABLE                          0
#define BQ25790_WDT_40S                              5
#define BQ25790_WDT_80S                              6
#define BQ25790_WDT_160S                             7

/* Register 11h */
#define BQ25790_REG_CHG_CTRL2                        0x11
#define BQ25790_9V_ENABLE_MASK                       BIT(4)
#define BQ25790_9V_ENABLE_SHIFT                      4
#define BQ25790_HVDCP_ENABLE_MASK                    BIT(3)
#define BQ25790_HVDCP_ENABLE_SHIFT                   3

/* Register 12h */
#define BQ25790_REG_CHG_CTRL3                        0x12
#define BQ25790_ACDRV_DIS_MASK                       BIT(7)
#define BQ25790_ACDRV_DIS_SHIFT                      7
#define BQ25790_OTG_ENABLE_MASK                      BIT(6)
#define BQ25790_OTG_ENABLE_SHIFT                     6
#define BQ25790_OTG_OOA_DIS_MASK                     BIT(1)
#define BQ25790_OTG_OOA_DIS_SHIFT                    1

/* Register 13h */
#define BQ25790_REG_CHG_CTRL4                        0x13
#define BQ25790_ACDRV2_ENABLE_MASK                   BIT(7)
#define BQ25790_ACDRV2_ENABLE_SHIFT                  7
#define BQ25790_ACDRV1_ENABLE_MASK                   BIT(6)
#define BQ25790_ACDRV1_ENABLE_SHIFT                  6
#define BQ25790_PWM_FREQ_MASK                        BIT(5)
#define BQ25790_PWM_FREQ_SHIFT                       5
#define BQ25790_STAT_DIS_MASK                        BIT(4)
#define BQ25790_STAT_DIS_SHIFT                       4

/* Register 14h */
#define BQ25790_REG_CHG_CTRL5                        0x14
#define BQ25790_IBAT_ENABLE_MASK                     BIT(5)
#define BQ25790_IBAT_ENABLE_SHIFT                    5
#define BQ25790_IBAT_REG_MASK                        (BIT(4) | BIT(3))
#define BQ25790_IBAT_REG_SHIFT                       3
#define BQ25790_IBAT_CURRENT_3A                      3000
#define BQ25790_IBAT_CURRENT_3A_VAL                  0
#define BQ25790_IBAT_CURRENT_4A                      4000
#define BQ25790_IBAT_CURRENT_4A_VAL                  1
#define BQ25790_IBAT_CURRENT_5A                      5000
#define BQ25790_IBAT_CURRENT_5A_VAL                  2
#define BQ25790_IBAT_DISABLE                         0
#define BQ25790_IBAT_DISABLE_VAL                     3
#define BQ25790_IINDPM_ENABLE_MASK                   BIT(2)
#define BQ25790_IINDPM_ENABLE_SHIFT                  2
#define BQ25790_EXTILIM_ENABLE_MASK                  BIT(1)
#define BQ25790_EXTILIM_ENABLE_SHIFT                 1

/* Register 18h */
#define BQ25790_REG_NTC_CTRL1                        0x18
#define BQ25790_TS_IGNORE_MASK                       BIT(0)
#define BQ25790_TS_IGNORE_SHIFT                      0

/* Register 1Bh */
#define BQ25790_REG_CHG_STAT0                        0x1B
#define BQ25790_IINDPM_STAT_MASK                     BIT(7)
#define BQ25790_VINDPM_STAT_MASK                     BIT(6)
#define BQ25790_WD_STAT_MASK                         BIT(5)
#define BQ25790_PG_STAT_MASK                         BIT(3)
#define BQ25790_PG_STAT_SHIFT                        3
#define BQ25790_POWER_GOOD                           1

/* Register 1Ch */
#define BQ25790_REG_CHG_STAT1                        0x1C
#define BQ25790_CHG_STAT_MASK                        (BIT(7) | BIT(6) | BIT(5))
#define BQ25790_CHG_STAT_SHIFT                       5

/* Register 1Dh */
#define BQ25790_REG_CHG_STAT2                        0x1D

/* Register 1Eh */
#define BQ25790_REG_CHG_STAT3                        0x1E
#define BQ25790_ACRB2_STAT_MASK                      BIT(7)
#define BQ25790_ACRB1_STAT_MASK                      BIT(6)

/* Register 1Fh */
#define BQ25790_REG_CHG_STAT4                        0x1F

/* Register 20h */
#define BQ25790_REG_FAULT_STAT0                      0x20
#define BQ25790_VBUS_OVP_STAT_SHIFT                  6
#define BQ25790_VBUS_OVP_STAT_MASK                   BIT(6)
#define BQ25790_VBAT_OVP_STAT_SHIFT                  5
#define BQ25790_VBAT_OVP_STAT_MASK                   BIT(5)
#define BQ25790_IBUS_OCP_STAT_SHIFT                  4
#define BQ25790_IBUS_OCP_STAT_MASK                   BIT(4)
#define BQ25790_IBAT_OCP_STAT_SHIFT                  3
#define BQ25790_IBAT_OCP_STAT_MASK                   BIT(3)
#define BQ25790_CONV_OCP_STAT_SHIFT                  2
#define BQ25790_CONV_OCP_STAT_MASK                   BIT(2)
#define BQ25790_VAC2_OVP_STAT_SHIFT                  1
#define BQ25790_VAC2_OVP_STAT_MASK                   BIT(1)
#define BQ25790_VAC1_OVP_STAT_SHIFT                  0
#define BQ25790_VAC1_OVP_STAT_MASK                   BIT(0)

/* Register 21h */
#define BQ25790_REG_FAULT_STAT1                      0x21
#define BQ25790_VSYS_SHORT_STAT_SHIFT                7
#define BQ25790_VSYS_SHORT_STAT_MASK                 BIT(7)
#define BQ25790_VSYS_OVP_STAT_SHIFT                  6
#define BQ25790_VSYS_OVP_STAT_MASK                   BIT(6)
#define BQ25790_OTG_OVP_STAT_SHIFT                   5
#define BQ25790_OTG_OVP_STAT_MASK                    BIT(5)
#define BQ25790_OTG_UVP_STAT_SHIFT                   4
#define BQ25790_OTG_UVP_STAT_MASK                    BIT(4)
#define BQ25790_TSHUT_STAT_SHIFT                     2
#define BQ25790_TSHUT_STAT_MASK                      BIT(2)

/* Register 22h */
#define BQ25790_REG_CHG_FLAG0                        0x22

/* Register 23h */
#define BQ25790_REG_CHG_FLAG1                        0x23

/* Register 24h */
#define BQ25790_REG_CHG_FLAG2                        0x24

/* Register 25h */
#define BQ25790_REG_CHG_FLAG3                        0x25

/* Register 26h */
#define BQ25790_REG_FAULT_FLAG0                      0x26
#define BQ25790_IBAT_REG_FLAG_SHIFT                  7
#define BQ25790_IBAT_REG_FLAG_MASK                   BIT(7)
#define BQ25790_VBUS_OVP_FLAG_SHIFT                  6
#define BQ25790_VBUS_OVP_FLAG_MASK                   BIT(6)
#define BQ25790_VBAT_OVP_FLAG_SHIFT                  5
#define BQ25790_VBAT_OVP_FLAG_MASK                   BIT(5)
#define BQ25790_IBUS_OCP_FLAG_SHIFT                  4
#define BQ25790_IBUS_OCP_FLAG_MASK                   BIT(4)
#define BQ25790_IBAT_OCP_FLAG_SHIFT                  3
#define BQ25790_IBAT_OCP_FLAG_MASK                   BIT(3)
#define BQ25790_CONV_OCP_FLAG_SHIFT                  2
#define BQ25790_CONV_OCP_FLAG_MASK                   BIT(2)
#define BQ25790_VAC2_OVP_FLAG_SHIFT                  1
#define BQ25790_VAC2_OVP_FLAG_MASK                   BIT(1)
#define BQ25790_VAC1_OVP_FLAG_SHIFT                  0
#define BQ25790_VAC1_OVP_FLAG_MASK                   BIT(0)

/* Register 27h */
#define BQ25790_REG_FAULT_FLAG1                      0x27
#define BQ25790_VSYS_SHORT_FLAG_SHIFT                7
#define BQ25790_VSYS_SHORT_FLAG_MASK                 BIT(7)
#define BQ25790_VSYS_OVP_FLAG_SHIFT                  6
#define BQ25790_VSYS_OVP_FLAG_MASK                   BIT(6)
#define BQ25790_OTG_OVP_FLAG_SHIFT                   5
#define BQ25790_OTG_OVP_FLAG_MASK                    BIT(5)
#define BQ25790_OTG_UVP_FLAG_SHIFT                   4
#define BQ25790_OTG_UVP_FLAG_MASK                    BIT(4)
#define BQ25790_TSHUT_FLAG_SHIFT                     2
#define BQ25790_TSHUT_FLAG_MASK                      BIT(2)

/* Register 2Eh */
#define BQ25790_REG_ADC_CTRL                         0x2E
#define BQ25790_ADC_EN_MASK                          BIT(7)
#define BQ25790_ADC_EN_SHIFT                         7

/* Register 2Fh */
#define BQ25790_REG_ADC_DIS                          0x2F
#define BQ25790_TS_ADC_DIS_MASK                      BIT(2)
#define BQ25790_TS_ADC_DIS_SHIFT                     2

/* Register 31h */
#define BQ25790_REG_IBUS_ADC                         0x31

/* Register 33h */
#define BQ25790_REG_IBAT_ADC                         0x33

/* Register 35h */
#define BQ25790_REG_VBUS_ADC                         0x35
#define BK8984_ADC_VOLTAGE_STEP                      8

/* Register 37h */
#define BQ25790_REG_VAC1_ADC                         0x37

/* Register 39h */
#define BQ25790_REG_VAC2_ADC                         0x39

/* Register 3Bh */
#define BQ25790_REG_VBAT_ADC                         0x3B

/* Register 41h */
#define BQ25790_REG_TDIE_ADC                         0x41
#define BQ25790_TEMP_STEP                            2

/* Register 48h */
#define BQ25790_REG_PART_INFO                        0x48
#define BQ25790_REG_PN_SHIFT                         3
#define BQ25790_REG_PN_MASK                          (BIT(5) | BIT(4) | BIT(3))
#define BQ25790_REG_DEV_REV_SHIFT                    0
#define BQ25790_REG_DEV_REV_MASK                     (BIT(2) | BIT(1) | BIT(0))

#define BQ25790_RETRY_CNT                            3
#define BQ25790_OTG_WORK_DELAY                       1000
#define BQ25790_OTG_IBUS_IOUT_TH                     500

#define AH0096_DEVICE_PN                             0x0 /* AH0096 */
#define BK8984_DEVICE_PN                             0x2 /* BK8984 */
#endif /* _BQ25790_CHARGER_H_ */
