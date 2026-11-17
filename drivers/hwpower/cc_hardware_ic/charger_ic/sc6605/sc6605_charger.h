/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * sc6605_charger.h
 *
 * sc6605 charger driver header file
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

#ifndef _SC6605_CHARGER_H_
#define _SC6605_CHARGER_H_

#include "sc6605_manager.h"
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>

#define SC6605_CHG_IC_GOOD                  0
#define SC6605_CHG_IC_BAD                   1

#define BATFET_DLY_12S                      1
#define BATFET_DLY_0S                       0

/* SC Charge Mode */
#define SC6605_CHG_MODE_CHGPUMP             0
#define SC6605_CHG_MODE_BYPASS              1
#define SC6605_CHG_MODE_BUCK                2

/* SC Protection threshold */
#define SC6605_VAC_OVP_TH_INIT              12000 /* mv */
#define SC6605_LVC_IBUS_OCP_TH_INIT         6000 /* ma */
#define SC6605_SC_IBUS_OCP_TH_INIT          4500 /* ma */
#define SC6605_VBAT_OVP_TH_INIT             5000 /* mv */
#define OTG_VOL_MAX                         9000 /* mv */

#define SC6605_NORMAL_USE_OTG               0

#define SC6605_BUCK_VBAT_OFFSET             3840
#define SC6605_BUCK_VBAT_STEP               8
#define SC6605_BUCK_VBAT_MIN                3840
#define SC6605_BUCK_VBAT_MAX                4856

#define SC6605_BUCK_ICHG_OFFSET             0
#define SC6605_BUCK_ICHG_STEP               50
#define SC6605_BUCK_ICHG_MIN                0
#define SC6605_BUCK_ICHG_MAX                3600

#define SC6605_BUCK_IINDPM_OFFSET           100
#define SC6605_BUCK_IINDPM_STEP             50
#define SC6605_BUCK_IINDPM_MIN              100
#define SC6605_BUCK_IINDPM_MAX              3250

#define SC6605_BUCK_IINDPM_ICO_OFFSET       100
#define SC6605_BUCK_IINDPM_ICO_STEP         50

#define SC6605_BUCK_IPRECHG_OFFSET          50
#define SC6605_BUCK_IPRECHG_STEP            50

#define SC6605_BUCK_ITERM_OFFSET            100
#define SC6605_BUCK_ITERM_STEP              50
#define SC6605_BUCK_ITERM_MIN               100
#define SC6605_BUCK_ITERM_MAX               1650

#define SC6605_BUCK_OTG_VOLT_OFFSET         3936
#define SC6605_BUCK_OTG_VOLT_STEP           96
#define SC6605_BUCK_OTG_VOLT_MIN            3936
#define SC6605_BUCK_OTG_VOLT_MAX            9600
#define SC6605_BUCK_OTG_VOLT_REG2_OFFSET    5

#define SC6605_BUCK_PRE_CURR_OFFSET         50
#define SC6605_BUCK_PRE_CURR_STEP           50
#define SC6605_BUCK_PRE_CURR_MIN            50
#define SC6605_BUCK_PRE_CURR_MAX            800

#define IBUS_OCP_MASK                       0xE0
#define IBUS_OCP_STEP                       250
#define IBUS_OCP_BASE                       1000
#define VBAT_OVP_MASK                       0xC0
#define VBAT_OVP_STEP                       25
#define VBAT_OVP_BASE                       3500

#define DEFAULT_PERCENT                     1000
#define ADC_TDIE_PERCENT                    2

#define REG_CHG_INT_SHIFT                   1
#define REG_CHG_INT_COUNT                   3
#define REG_CHG_INT_MASK                    BIT(4)

#define OTG_CURRENT_1A                      1000
#define SC8546_WTD_CONFIG_TIMING_80S        80000
#define SC8546_WTD_CONFIG_TIMING_DIS        0
#define SC8546_WTD_CONFIG_TIMING_1S         1000

#define PRECHG_CURR_256MA                   256
#define TERM_CURR_128MA                     128

#define REG_IBUS_OCP_1A5_UCP_160MS          0x16
#define SC6605_CHG_HIDE_REG_STATE           0x01
#define SC6605_CHG_LED_LEAK_DISABLE         0x03

#define SC6605_CHG_DONE_STAT_MASK           0x05
#define SC6605_CHG_DONE_DATA                0xE0

#define SC6605_BUCK_BOOST_FREQ_1MHZ         0x8c /* BOOST 1MHz BUCK 1.5MHz */
#define SC6605_CHG_TIME_20HOURS             0xf6 /* 20hours */

/* HK reg BIT */
#define SC6605_HK_V2X_UVLO_MASK             BIT(7)
#define SC6605_HK_POR_MASK                  BIT(6)
#define SC6605_HK_RESET_MASK                BIT(5)
#define SC6605_HK_ADC_DONE_MASK             BIT(4)
#define SC6605_HK_REGN_OK_MASK              BIT(3)
#define SC6605_HK_VBAT_UVLO_MASK            BIT(2)
#define SC6605_HK_VBUS_PRESENT_MASK         BIT(1)
#define SC6605_HK_VAC_PRESENT_MASK          BIT(0)

/* HK timeout BIT */
#define SC6605_HK_WD_TIMEOUT_MASK           BIT(6)

/* BUCK reg BIT */
#define SC6605_BUCK_TDIE_REG_MASK           BIT(22)
#define SC6605_BUCK_TSBAT_COOL_MASK         BIT(21)
#define SC6605_BUCK_TSBAT_WARM_MASK         BIT(20)
#define SC6605_BUCK_ICO_MASK                BIT(18)
#define SC6605_BUCK_IINDPM_MASK             BIT(17)
#define SC6605_BUCK_VINDPM_MASK             BIT(16)
#define SC6605_BUCK_CHG_MASK                BIT(13)
#define SC6605_BUCK_BOOST_OK_MASK           BIT(12)
#define SC6605_BUCK_VSYSMIN_MASK            BIT(11)
#define SC6605_BUCK_QB_ON_MASK              BIT(10)
#define SC6605_BUCK_BATFET_MASK             BIT(8)
#define SC6605_BUCK_VSYS_SHORT_MASK         BIT(4)
#define SC6605_BUCK_VSLEEP_BUCK_MASK        BIT(3)
#define SC6605_BUCK_VBAT_DPL_MASK           BIT(2)
#define SC6605_BUCK_VBAT_LOW_BOOST_MASK     BIT(1)
#define SC6605_BUCK_VBUS_GOOD_MASK          BIT(0)

/* BUCK flag BIT */
#define SC6605_BUCK_FLAG_BOOST_GOOD         BIT(12)
#define SC6605_BUCK_FLAG_VBUS_GOOD          BIT(0)
#define SC6605_BUCK_GET_CHG_STATE(state)    ((state >> 13) & 0x7)

/* Protection BIT */
#define SC6605_TDIE_OTP_MASK                BIT(6)
#define SC6605_TBAT_OTP_MASK                BIT(5)
#define SC6605_WDT_TOT                      BIT(6)
#define SC6605_REGN_OCP_MASK                BIT(4)
#define SC6605_VAC_OVP_MASK                 BIT(0)
#define SC6605_VBUS_OVP_MASK                BIT(1)
#define SC6605_VBAT_OVP_MASK                BIT(0)
#define SC6605_VBAT_LV                      BIT(2)

enum vbus_ovp {
	SC6605_VBUS_OVP_6V = 0,
	SC6605_VBUS_OVP_10V,
	SC6605_VBUS_OVP_12V,
	SC6605_VBUS_OVP_14V,
};

enum vac_ovp {
	SC6605_VAC_OVP_12V = 0,
	SC6605_VAC_OVP_13V,
	SC6605_VAC_OVP_6V5,
	SC6605_VAC_OVP_11V,
	SC6605_VAC_OVP_16V,
	SC6605_VAC_OVP_17V,
	SC6605_VAC_OVP_14V,
	SC6605_VAC_OVP_15V,
};

enum vsys_min {
	SC6605_VSYS_MIN_2V6 = 0,
	SC6605_VSYS_MIN_2V8,
	SC6605_VSYS_MIN_3V,
	SC6605_VSYS_MIN_3V2,
	SC6605_VSYS_MIN_3V4,
	SC6605_VSYS_MIN_3V5,
	SC6605_VSYS_MIN_3V6,
	SC6605_VSYS_MIN_3V7,
};

enum {
	SC6605_CHG_STATE_NO_CHG = 0,
	SC6605_CHG_STATE_TRICK,
	SC6605_CHG_STATE_PRECHG,
	SC6605_CHG_STATE_CC,
	SC6605_CHG_STATE_CV,
	SC6605_CHG_STATE_TERM,
};

enum {
	IRQ_HK = 0,
	IRQ_BUCK,
	IRQ_MAX,
};

enum cp_mode {
	MODE_CHG_2_1 = 0,
	MODE_CHG_1_1,
	MODE_OTG_1_2,
	MODE_OTG_1_1,
};

enum charger_mode {
	UNKNOWN = 0,
	BUCK5V,
	BUCK9V,
	SC11,
	SC21,
	RSC11,
	RSC12,
	OTG5V,
	OTG9V,
	WDRC12
};

struct current_charger_mode {
	enum charger_mode chg_mode;
};

enum ADC_MODULE {
	ADC_IBUS = 0,
	ADC_VBUS,
	ADC_VAC,
	ADC_VBATSNS,
	ADC_VBAT,
	ADC_IBAT,
	ADC_VSYS,
	ADC_TSBUS,
	ADC_TSBAT,
	ADC_TDIE,
	ADC_BATID,
};

static const u32 adc_step[] = {
	2500, 3750, 5000, 1250, 1250,
	1562, 1250, 9766, 9766, 5, 156,
};

enum sc6605_chg_fields {
	F_VAC_OVP, F_VBUS_OVP,
	F_TSBUS_FLT,
	F_TSBAT_FLT,
	F_ACDRV_MANUAL_PRE, F_ACDRV_EN, F_ACDRV_MANUAL_EN, F_WD_TIME_RST, F_WD_TIMER,
	F_REG_RST, F_VBUS_PD, F_VAC_PD, F_CID_EN,
	F_FLT_WD_OUT, F_FLT_VBUS_OVP,
	F_ADC_EN, F_ADC_RATE, F_ADC_FREEZE, F_BATID_ADC_EN,
	F_EDL_ACTIVE_LEVEL,
	/* charger */
	F_VSYS_MIN,
	F_BATSNS_EN,F_VBAT,
	F_ICHG_CC,
	F_VINDPM_VBAT, F_VINDPM_DIS,F_VINDPM,
	F_IINDPM_DIS, F_IINDPM,
	F_FORCE_ICO, F_ICO_EN, F_IINDPM_ICO,
	F_VBAT_PRECHG, F_IPRECHG,
	F_TERM_EN, F_ITERM,
	F_RECHG_DIS, F_RECHG_DG, F_VRECHG,
	F_VBOOST_L, F_IBOOST,
	F_CONV_OCP_DIS, F_TSBAT_JEITA_DIS, F_IBAT_OCP_DIS, F_VPMID_OVP_OTG_DIS, F_VBAT_OVP_BUCK_DIS, F_VBOOST_H,
	F_T_BATFET_RST, F_T_PD_nRST, F_BATFET_RST_EN, F_BATFET_DLY, F_BATFET_DIS, F_nRST_SHIPMODE_DIS,
	F_HIZ_EN, F_PERFORMANCE_EN, F_DIS_BUCKCHG_PATH, F_DIS_SLEEP_FOR_OTG, F_QB_EN, F_BOOST_EN, F_CHG_EN,
	F_VBAT_TRACK, F_IBATOCP, F_VSYSOVP_DIS, F_VSYSOVP_TH,
	F_BAT_COMP, F_VCLAMP, F_JEITA_ISET_COOL, F_JEITA_VSET_WARM,
	F_TMR2X_EN, F_CHG_TIMER_EN, F_CHG_TIMER, F_TDIE_REG_DIS, F_TDIE_REG, F_PFM_DIS,
	F_BAT_COMP_OFF, F_VBAT_LOW_OTG, F_BOOST_FREQ, F_BUCK_FREQ, F_BAT_LOAD_EN,
	F_VSYS_SHORT_STAT, F_VSLEEP_BUCK_STAT, F_VBAT_DPL_STAT, F_VBAT_LOW_BOOST_STAT, F_VBUS_GOOD_STAT,
	F_CHG_STAT, F_BOOST_OK_STAT, F_VSYSMIN_REG_STAT, F_QB_ON_STAT, F_BATFET_STAT,
	F_FLT_VBAT_OVP,
	F_OTG_OVP,
	F_TDIE_REG_STAT, F_TSBAT_COOL_STAT, F_TSBAT_WARM_STAT, F_ICO_STAT, F_IINDPM_STAT, F_VINDPM_STAT,
	F_TESTM_EN,
	F_KEY_EN_OWN,
	/* dvchg reg */
	F_VBUS2OUT_UVP,
	F_CP_EN, F_MODE,
	F_CP_STAT, F_CP_ERR_STAT,
	F_IBUS_UCP_SET,
	F_HVDCP_EN,
	F_AUTO_DPDM,
	F_LED_EN,
	F_MAX_FIELDS,
};

static const struct sc6605_reg_field sc6605_chg_reg_fields[] = {
	[F_VAC_OVP]          = SC6605_REG_FIELD(SC6605_REG_VAC_VBUS_OVP, 4, 7),
	[F_VBUS_OVP]         = SC6605_REG_FIELD(SC6605_REG_VAC_VBUS_OVP, 0, 2),
	[F_TSBUS_FLT]        = SC6605_REG_FIELD(SC6605_REG_VAC_VBUS_OVP, 0, 7),
	[F_TSBAT_FLT]        = SC6605_REG_FIELD(SC6605_REG_VAC_VBUS_OVP, 0, 7),
	[F_ACDRV_MANUAL_PRE] = SC6605_REG_FIELD(SC6605_REG_HK_CTRL, 7, 7),
	[F_ACDRV_EN]         = SC6605_REG_FIELD(SC6605_REG_HK_CTRL, 5, 5),
	[F_ACDRV_MANUAL_EN]  = SC6605_REG_FIELD(SC6605_REG_HK_CTRL, 4, 4),
	[F_WD_TIME_RST]      = SC6605_REG_FIELD(SC6605_REG_HK_CTRL, 3, 3),
	[F_WD_TIMER]         = SC6605_REG_FIELD(SC6605_REG_HK_CTRL, 0, 2),
	[F_REG_RST]          = SC6605_REG_FIELD(SC6605_REG_HK_CTRL + 1, 7, 7),
	[F_VBUS_PD]          = SC6605_REG_FIELD(SC6605_REG_HK_CTRL + 1, 6, 6),
	[F_VAC_PD]           = SC6605_REG_FIELD(SC6605_REG_HK_CTRL + 1, 5, 5),
	[F_CID_EN]           = SC6605_REG_FIELD(SC6605_REG_HK_CTRL + 1, 3, 3),
	[F_FLT_WD_OUT]       = SC6605_REG_FIELD(SC6605_REG_HK_FLT_STAT + 1, 6, 6),
	[F_FLT_VBUS_OVP]     = SC6605_REG_FIELD(SC6605_REG_HK_FLT_STAT, 1, 1),
	[F_ADC_EN]           = SC6605_REG_FIELD(SC6605_REG_HK_ADC_CTRL, 7, 7),
	[F_ADC_RATE]         = SC6605_REG_FIELD(SC6605_REG_HK_ADC_CTRL, 6, 6),
	[F_ADC_FREEZE]       = SC6605_REG_FIELD(SC6605_REG_HK_ADC_CTRL, 5, 5),
	[F_BATID_ADC_EN]     = SC6605_REG_FIELD(SC6605_REG_HK_ADC_CTRL, 3, 3),
	[F_EDL_ACTIVE_LEVEL] = SC6605_REG_FIELD(SC6605_REG_EDL_BUFFER, 1, 1),
	[F_VSYS_MIN]         = SC6605_REG_FIELD(SC6605_REG_VSYS_MIN, 0, 2),
	[F_BATSNS_EN]        = SC6605_REG_FIELD(SC6605_REG_VBAT, 7, 7),
	[F_VBAT]             = SC6605_REG_FIELD(SC6605_REG_VBAT, 0, 6),
	[F_ICHG_CC]          = SC6605_REG_FIELD(SC6605_REG_ICHG_CC, 0, 6),
	[F_VINDPM_VBAT]      = SC6605_REG_FIELD(SC6605_REG_VINDPM, 5, 6),
	[F_VINDPM_DIS]       = SC6605_REG_FIELD(SC6605_REG_VINDPM, 4, 4),
	[F_VINDPM]           = SC6605_REG_FIELD(SC6605_REG_VINDPM, 0, 3),
	[F_IINDPM_DIS]       = SC6605_REG_FIELD(SC6605_REG_IINDPM, 7, 7),
	[F_IINDPM]           = SC6605_REG_FIELD(SC6605_REG_IINDPM, 0, 5),
	[F_FORCE_ICO]        = SC6605_REG_FIELD(SC6605_REG_ICO_CTRL, 7, 7),
	[F_ICO_EN]           = SC6605_REG_FIELD(SC6605_REG_ICO_CTRL, 6, 6),
	[F_IINDPM_ICO]       = SC6605_REG_FIELD(SC6605_REG_ICO_CTRL, 0, 5),
	[F_VBAT_PRECHG]      = SC6605_REG_FIELD(SC6605_REG_PRECHARGE_CTRL, 6, 7),
	[F_IPRECHG]          = SC6605_REG_FIELD(SC6605_REG_PRECHARGE_CTRL, 0, 3),
	[F_TERM_EN]          = SC6605_REG_FIELD(SC6605_REG_TERMINATION_CTRL, 7, 7),
	[F_ITERM]            = SC6605_REG_FIELD(SC6605_REG_TERMINATION_CTRL, 0, 4),
	[F_RECHG_DIS]        = SC6605_REG_FIELD(SC6605_REG_RECHARGE_CTRL, 4, 4),
	[F_RECHG_DG]         = SC6605_REG_FIELD(SC6605_REG_RECHARGE_CTRL, 2, 3),
	[F_VRECHG]           = SC6605_REG_FIELD(SC6605_REG_RECHARGE_CTRL, 0, 1),
	[F_VBOOST_L]         = SC6605_REG_FIELD(SC6605_REG_VBOOST_CTRL, 3, 7),
	[F_IBOOST]           = SC6605_REG_FIELD(SC6605_REG_VBOOST_CTRL, 0, 2),
	[F_VBOOST_H]         = SC6605_REG_FIELD(SC6605_REG_PROTECTION_DIS, 7, 7),
	[F_CONV_OCP_DIS]     = SC6605_REG_FIELD(SC6605_REG_PROTECTION_DIS, 4, 4),
	[F_TSBAT_JEITA_DIS]  = SC6605_REG_FIELD(SC6605_REG_PROTECTION_DIS, 3, 3),
	[F_IBAT_OCP_DIS]     = SC6605_REG_FIELD(SC6605_REG_PROTECTION_DIS, 2, 2),
	[F_VPMID_OVP_OTG_DIS] = SC6605_REG_FIELD(SC6605_REG_PROTECTION_DIS, 1, 1),
	[F_VBAT_OVP_BUCK_DIS] = SC6605_REG_FIELD(SC6605_REG_PROTECTION_DIS, 0, 0),
	[F_T_BATFET_RST]     = SC6605_REG_FIELD(SC6605_REG_RESET_CTRL, 5, 5),
	[F_BATFET_RST_EN]    = SC6605_REG_FIELD(SC6605_REG_RESET_CTRL, 3, 3),
	[F_BATFET_DLY]       = SC6605_REG_FIELD(SC6605_REG_RESET_CTRL, 2, 2),
	[F_BATFET_DIS]       = SC6605_REG_FIELD(SC6605_REG_RESET_CTRL, 1, 1),
	[F_HIZ_EN]           = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL, 7, 7),
	[F_PERFORMANCE_EN]   = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL, 6, 6),
	[F_DIS_BUCKCHG_PATH] = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL, 5, 5),
	[F_DIS_SLEEP_FOR_OTG] = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL, 4, 4),
	[F_QB_EN]            = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL, 2, 2),
	[F_BOOST_EN]         = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL, 1, 1),
	[F_CHG_EN]           = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL, 0, 0),
	[F_VBAT_TRACK]       = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 1, 5, 5),
	[F_IBATOCP]          = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 1, 3, 4),
	[F_VSYSOVP_DIS]      = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 1, 2, 2),
	[F_VSYSOVP_TH]       = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 1, 0, 1),
	[F_BAT_COMP]         = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 2, 5, 7),
	[F_VCLAMP]           = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 2, 2, 4),
	[F_JEITA_ISET_COOL]  = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 2, 1, 1),
	[F_JEITA_VSET_WARM]  = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 2, 0, 0),
	[F_TMR2X_EN]         = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 3, 7, 7),
	[F_CHG_TIMER_EN]     = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 3, 6, 6),
	[F_CHG_TIMER]        = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 3, 4, 5),
	[F_TDIE_REG_DIS]     = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 3, 3, 3),
	[F_TDIE_REG]         = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 3, 1, 2),
	[F_PFM_DIS]          = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 3, 0, 0),
	[F_BAT_COMP_OFF]     = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 4, 6, 7),
	[F_VBAT_LOW_OTG]     = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 4, 5, 5),
	[F_BOOST_FREQ]       = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 4, 3, 4),
	[F_BUCK_FREQ]        = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 4, 1, 2),
	[F_BAT_LOAD_EN]      = SC6605_REG_FIELD(SC6605_REG_CHG_CTRL + 4, 0, 0),
	[F_VBUS_GOOD_STAT]   = SC6605_REG_FIELD(SC6605_REG_CHG_INT_STAT, 0, 0),
	[F_CHG_STAT]         = SC6605_REG_FIELD(SC6605_REG_CHG_INT_STAT + 1, 5, 7),
	[F_IINDPM_STAT]      = SC6605_REG_FIELD(SC6605_REG_CHG_INT_STAT + 2, 1, 1),
	[F_VINDPM_STAT]      = SC6605_REG_FIELD(SC6605_REG_CHG_INT_STAT + 2, 0, 0),
	[F_FLT_VBAT_OVP]     = SC6605_REG_FIELD(SC6605_REG_CHG_FLT_STAT, 0, 0),
	[F_OTG_OVP]          = SC6605_REG_FIELD(SC6605_REG_OTG_OVP, 0, 0),
	[F_TESTM_EN]         = SC6605_REG_FIELD(SC6605_REG_Internal, 0, 0),
	[F_KEY_EN_OWN]       = SC6605_REG_FIELD(SC6605_REG_Internal + 1, 0, 0),
	[F_VBUS2OUT_UVP]     = SC6605_REG_FIELD(SC6605_REG_VBUS2OUT_UVP, 0, 2),
	[F_CP_EN]            = SC6605_REG_FIELD(SC6605_REG_CP_CTRL_1, 0, 0),
	[F_MODE]             = SC6605_REG_FIELD(SC6605_REG_CP_CTRL_1, 1, 2),
	[F_CP_STAT]          = SC6605_REG_FIELD(SC6605_REG_CP_INT_STAT, 0, 0),
	[F_CP_ERR_STAT]      = SC6605_REG_FIELD(SC6605_REG_CP_INT_STAT, 1, 2),
	[F_IBUS_UCP_SET]     = SC6605_REG_FIELD(SC6605_REG_CP_CTRL_4, 5, 5),
	[F_HVDCP_EN]         = SC6605_REG_FIELD(SC6605_REG_DPDM_EN, 5, 5),
	[F_AUTO_DPDM]        = SC6605_REG_FIELD(SC6605_REG_DPDM_EN, 6, 6),
	[F_LED_EN]           = SC6605_REG_FIELD(SC6605_REG_LED_EN, 5, 6),
};

struct dts_name_tbl {
	const char *name;
	u32 *val;
	u32 default_val;
};

struct buck_reg_init_table {
	enum sc6605_chg_fields field;
	u32 val;
};

struct chip_state {
	bool online;
	bool boost_good;
	int vbus_type;
	int chg_state;
	int vindpm;
};

struct buck_init_data {
	u32 vsyslim;
	u32 batsns_en;
	u32 vbat;
	u32 ichg;
	u32 vindpm;
	u32 iindpm_dis;
	u32 iindpm;
	u32 ico_enable;
	u32 iindpm_ico;
	u32 vprechg;
	u32 iprechg;
	u32 iterm_en;
	u32 iterm;
	u32 rechg_dis;
	u32 rechg_dg;
	u32 rechg_volt;
	u32 vboost;
	u32 iboost;
	u32 conv_ocp_dis;
	u32 tsbat_jeita_dis;
	u32 ibat_ocp_dis;
	u32 vpmid_ovp_otg_dis;
	u32 vbat_ovp_buck_dis;
	u32 ibat_ocp;
};

struct sc6605_chg_device {
	struct device *dev;
	struct i2c_adapter *adp;
	struct regmap *rmap;
	struct buck_init_data buck_init;
	struct chip_state state;
	unsigned long request_otg;
	int irq[IRQ_MAX];
	int now_vindpm;
	int device_id;
	struct current_charger_mode current_charge_mode;
	uint16_t otg_vol;
};

int sc6605_chg_get_adc(struct sc6605_chg_device *sc, enum ADC_MODULE id);
int sc6605_get_register_head(char *buf, int size, void *dev_data);
int sc6605_dump_register(char *buf, int size, void *dev_data);
int sc6605_get_charge_mode(void);
struct current_charger_mode* sc6605_get_current_charge_mode(void);
void sc6605_set_charge_mode(int mode);
int sc6605_threshold_reg_init(int mode);

#endif /* _SC6605_CHARGER_H_ */