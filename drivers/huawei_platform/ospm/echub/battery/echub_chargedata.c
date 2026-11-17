/*
 * echub_chargedata.c
 *
 * driver for echub charge-log and big data
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
#include "echub_chargedata.h"
#include <linux/ctype.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <linux/delay.h>
#include "ospm_printf.h"
#include "hmi/hmi.h"

#define EC_I2C_DATA_MAXLEN               	  5
#define NTC_TEMP_INVALID					  (-23)
#define PD_LOG_HEADER_VALUE              	  0xAA
#define PD_DFX_TYPE_OFFSET					  6
#define PD_DFX_ATTACH						  1
#define PD_DFX_UNATTACH						  2
#define PD_DFX_PROTOCOL						  3
#define PD_DFX_STRUCT_SIZE					  19
#define SHIFT_OFFSET_1_BYTE 				  8
#define SHIFT_OFFSET_2_BYTE 				  16
#define SHIFT_OFFSET_3_BYTE 				  24
#define EC_I2C_CMD_PDO         			  	  0x0263
#define EC_I2C_CMD_PD_VBUS          		  0x0267
#define PD_VBUS_HIGH_BYTE					  0
#define PD_VBUS_LOW_BYTE					  1
#define PD_VBUS_READ_LEN					  4
#define EC_I2C_PDO_OFFSET					  0x12
#define SC_CHARGE_OFFSET					  8
#define IDX_SC_CHARGER_MAGIC                  0x5A5B
#define SC_CHARGER_TYPE                       3

#define ECHUB_MFDATE_BASE_YEAR  1980
#define MFDATE_YEAR_OFFSET      9
#define MFDATE_MONTH_OFFSET     5

// Params offset in EC dfx data block
#define ECHUB_GAUG_STA2_LEN     22
#define ECHUB_MFDATE_OFFSET     77
#define ECHUB_MFNAME_OFFSET     80
#define ECHUB_DEVNAME_OFFSET    134
#define ECHUB_GAUG_STA2_OFFSET  165
#define ECHUB_STA_TIME_OFFSET   172
#define ECHUB_DOD0_X_OFFSET     176
#define ECHUB_DOD0_PASS_OFFSET  184
#define ECHUB_DOD0_TIME_OFFSET  188
#define ECHUB_DODEOC_X_OFFSET   190

#define DUMP_HEAD				0
#define DUMP_CONTENT			1
#define DUMP_MF_BUF_MAX         28
#define DUMP_GAUG_BUF_MAX       48

static bool g_is_sc_charger = false;
static int g_resume_flag = 0;
static int g_count = 0;

static struct echub_chargedata_device_info *g_ec_chargedata_di;

typedef int (*charge_data_process_function)(int regoffset, char regdata, int bytes, int *temp);

struct echub_channel_sensor_info {
	char *sensor_type;
	int index;
	charge_data_process_function process;
	int regoffset;
	int regdata;
	int bytes;
};

typedef int (*charge_data_report_function)(char *buffer, int size, int type, int *rlen,
	struct echub_chargedata_device_info *di);

struct echub_charge_data_report_info {
	char* report_type;
	charge_data_report_function process;
};

enum {
	TYPE_DEMICAL = 0,
	TYPE_HEX,
	TYPE_STRING,
	TYPE_RESERVED
};

enum {
	ECHUB_DEVICENAME = 0,
	ECHUB_MFNAME,
	ECHUB_MFDATE,
	ECHUB_MF_INFO_NUM_MAX
};

struct echub_chargelog_str_head {
	char *name;
	char *val_str;
	int offset;
	int size;
	int type;
};

static struct echub_chargelog_str_head g_echub_chargelog_head_mfinfo[ECHUB_MF_INFO_NUM_MAX] = {
	{"deviceName", 	NULL,  ECHUB_DEVNAME_OFFSET, ECHUB_DEVNAME_LEN,  TYPE_STRING},
	{"mfName", 		NULL,  ECHUB_MFNAME_OFFSET,  ECHUB_MFNAME_LEN,   TYPE_STRING},
	{"mfDate", 		NULL,  ECHUB_MFDATE_OFFSET,  ECHUB_MFDATE_LEN,   TYPE_STRING},
};

enum {
	ECHUB_STATIME = 0,
	ECHUB_DOD0_X,
	ECHUB_DOD0_PASS,
	ECHUB_DOD0_TIME,
	ECHUB_DODEOC_X,
	ECHUB_GAUG2_INFO_NUM_MAX
};

static struct echub_chargelog_str_head g_echub_chargelog_head_gaug_sta2info[ECHUB_GAUG2_INFO_NUM_MAX] = {
	{"StaTime", 	NULL,  ECHUB_STA_TIME_OFFSET,  ECHUB_GAUGSTA_STATIME,   TYPE_DEMICAL},
	{"DOD0_X", 	    NULL,  ECHUB_DOD0_X_OFFSET,    ECHUB_GAUGSTA_DOD0_X,    TYPE_HEX},
	{"DOD0_PASS", 	NULL,  ECHUB_DOD0_PASS_OFFSET, ECHUB_GAUGSTA_DOD0_PASS, TYPE_HEX},
	{"DOD0_TIME", 	NULL,  ECHUB_DOD0_TIME_OFFSET, ECHUB_GAUGSTA_DOD0_TIME, TYPE_DEMICAL},
	{"DODEOC_X", 	NULL,  ECHUB_DODEOC_X_OFFSET,  ECHUB_GAUGSTA_DODEOC_X,  TYPE_HEX},
};

static const char *const g_sc_chg_type[SC_CHARGER_TYPE] = {"SC8571", "NU2205", "BQ25980"};

static const char *const g_echub_chargelog_head[ECHUB_CHARGEDATA_END] = {
	[ECHUB_CHARGEDATA_TEMPERATURE] = "Temp",
	[ECHUB_CHARGEDATA_VOLTAGE] = "Vbat",
	[ECHUB_CHARGEDATA_CURRENT] = "Ibat",
	[ECHUB_CHARGEDATA_AVERAGE_CURRENT] = "AvgIbat",
	[ECHUB_CHARGEDATA_RSOC] = "RSoc",
	[ECHUB_CHARGEDATA_ASOC] = "ASoc",
	[ECHUB_CHARGEDATA_REMAINING_CAPACITY] = "RmCap",
	[ECHUB_CHARGEDATA_FULL_CHARGE_CAPACITY] = "FulCap",
	[ECHUB_CHARGEDATA_CHARGING_CURRENT] = "Imax",
	[ECHUB_CHARGEDATA_CHARGING_VOLTAGE] = "Vmax",
	[ECHUB_CHARGEDATA_BATTERY_STATUS] = "BatSta",
	[ECHUB_CHARGEDATA_CYCLE_COUNT] = "Cycle",
	[ECHUB_CHARGEDATA_CELL_VOLTAGE1] = "Vcell1",
	[ECHUB_CHARGEDATA_CELL_VOLTAGE2] = "Vcell2",
	[ECHUB_CHARGEDATA_CELL_VOLTAGE3] = "Vcell3",
	[ECHUB_CHARGEDATA_CELL_VOLTAGE4] = "Vcell4",
	[ECHUB_CHARGEDATA_STATE_OF_HEALTH] = "SoH",
	[ECHUB_CHARGEDATA_SAFETY_STATUS] = "SafSta",
	[ECHUB_CHARGEDATA_PF_STATUS] = "PFSta",
	[ECHUB_CHARGEDATA_OPERATION_STATUS] = "OPSta",
	[ECHUB_CHARGEDATA_CHARGING_STATUS] = "BatChgSta",
	[ECHUB_CHARGEDATA_GAUING_STATUS] = "GauSta",
	[ECHUB_CHARGEDATA_INNER_TEMP] = "InTemp",
	[ECHUB_CHARGEDATA_TS1TEMP] = "Ts1Temp",
	[ECHUB_CHARGEDATA_TS2TEMP] = "Ts2Temp",
	[ECHUB_CHARGEDATA_TS3TEMP] = "Ts3Temp",
	[ECHUB_CHARGEDATA_TS4TEMP] = "Ts4Temp",
	[ECHUB_CHARGEDATA_CELL_TEMP] = "CelTemp",
	[ECHUB_CHARGEDATA_FET_TEMP] = "FetTemp",
	[ECHUB_CHARGEDATA_GAUG_TEMP] = "GaugTemp",
	[ECHUB_CHARGEDATA_ALGO_TEMP] = "AlgoTemp",
	[ECHUB_CHARGEDATA_SOHFCC] = "SohFcc",
	[ECHUB_CHARGEDATA_QMAX_CELL1] = "Qmax1",
	[ECHUB_CHARGEDATA_QMAX_CELL2] = "Qmax2",
	[ECHUB_CHARGEDATA_QMAX_CELL3] = "Qmax3",
	[ECHUB_CHARGEDATA_QMAX_CELL4] = "Qmax4",
	[ECHUB_CHARGEDATA_CHG_OP0] = "ChgOP0",
	[ECHUB_CHARGEDATA_CHG_OP1] = "ChgOP1",
	[ECHUB_CHARGEDATA_CHG_OP2] = "ChgOP2",
	[ECHUB_CHARGEDATA_CHG_OP3] = "ChgOP3",
	[ECHUB_CHARGEDATA_CHG_OP4] = "ChgOP4",
	[ECHUB_CHARGEDATA_CHG_OP5] = "ChgOP5",
	[ECHUB_CHARGEDATA_CHG_PROCHOTOP0] = "ChgPOp0",
	[ECHUB_CHARGEDATA_CHG_PROCHOTOP1] = "ChgPOp1",
	[ECHUB_CHARGEDATA_CHG_PROCHOTSTATUS] = "ChgPSta",
	[ECHUB_CHARGEDATA_CHG_STATUS] = "ChgSta",
	[ECHUB_CHARGEDATA_CHG_STATUS2] = "ChgSta2",
	[ECHUB_CHARGEDATA_CHG_VSYSMIN] = "ChgVsmin",
	[ECHUB_CHARGEDATA_CHG_VOLTAGE] = "ChgV",
	[ECHUB_CHARGEDATA_CHG_CURRENT] = "ChgI",
	[ECHUB_CHARGEDATA_CHG_INPUTCURRENT] = "ChgInC",
	[ECHUB_CHARGEDATA_CHG_INPUTVOLTAGE] = "ChgInV",
	[ECHUB_CHARGEDATA_CHG2_OP0] = "Chg2OP0",
	[ECHUB_CHARGEDATA_CHG2_OP1] = "Chg2OP1",
	[ECHUB_CHARGEDATA_CHG2_OP2] = "Chg2OP2",
	[ECHUB_CHARGEDATA_CHG2_OP3] = "Chg2OP3",
	[ECHUB_CHARGEDATA_CHG2_OP4] = "Chg2OP4",
	[ECHUB_CHARGEDATA_CHG2_OP5] = "Chg2OP5",
	[ECHUB_CHARGEDATA_CHG2_PROCHOTOP0] = "Chg2POp0",
	[ECHUB_CHARGEDATA_CHG2_PROCHOTOP1] = "Chg2POp1",
	[ECHUB_CHARGEDATA_CHG2_PROCHOTSTATUS] = "Chg2PSta",
	[ECHUB_CHARGEDATA_CHG2_STATUS] = "Chg2Sta",
	[ECHUB_CHARGEDATA_CHG2_STATUS2] = "Chg2Sta2",
	[ECHUB_CHARGEDATA_CHG2_VSYSMIN] = "Chg2Vsmin",
	[ECHUB_CHARGEDATA_CHG2_VOLTAGE] = "Chg2V",
	[ECHUB_CHARGEDATA_CHG2_CURRENT] = "Chg2I",
	[ECHUB_CHARGEDATA_CHG2_INPUTCURRENT] = "Chg2InC",
	[ECHUB_CHARGEDATA_CHG2_INPUTVOLTAGE] = "Chg2InV",
	[ECHUB_CHARGEDATA_PD_VBUS] = "PDVbus",
	[ECHUB_CHARGEDATA_PDO] = "PDO",
	[ECHUB_CHARGEDATA_SOC_NTC] = "SOCNTC",
	[ECHUB_CHARGEDATA_CHARGER_NTC] = "ChgNTC",
	[ECHUB_CHARGEDATA_CHARGER2_NTC] = "Chg2NTC",
	[ECHUB_CHARGEDATA_TYPEC1_NTC] = "Tc1NTC",
	[ECHUB_CHARGEDATA_TYPEC2_NTC] = "Tc2NTC",
	[ECHUB_CHARGEDATA_TYPEC3_NTC] = "Tc3NTC",
	[ECHUB_CHARGEDATA_TYPEC4_NTC] = "Tc4NTC",
	[ECHUB_CHARGEDATA_AMBIENCE1_NTC] = "Amb1NTC",
	[ECHUB_CHARGEDATA_AMBIENCE2_NTC] = "Amb2NTC",
	[ECHUB_CHARGEDATA_FAN0_SPEED] = "Fan0S",
	[ECHUB_CHARGEDATA_FAN1_SPEED] = "Fan1S",
	[ECHUB_CHARGEDATA_FAN2_SPEED] = "Fan2S",
	/* IDX CHARGE */
	[ECHUB_CHARGEDATA_IDX_CHARGE_RSOC_MAX] = "RsocMax",
	[ECHUB_CHARGEDATA_IDX_CHARGE_RSOC_MIN] = "RsocMin",
	[ECHUB_CHARGEDATA_IDX_CHARGE_STATUS] = "LogChgSts",
	[ECHUB_CHARGEDATA_IDX_CHARGE_SCENE] = "ChgScene",
	[ECHUB_CHARGEDATA_IDX_REQUEST_VBUS] = "ReqV",
	[ECHUB_CHARGEDATA_IDX_REQUEST_IBUS] = "ReqI",
	[ECHUB_CHARGEDATA_IDX_ADPATER_REAL_VBUS] = "RealVbus",
	[ECHUB_CHARGEDATA_IDX_ADPATER_REAL_IBUS] = "RealIbus",
	/* SC CHARGE */
	[ECHUB_CHARGEDATA_SC_MAGIC] = "magic",
	[ECHUB_CHARGEDATA_SC_VENDOR] = "vendor",
	[ECHUB_CHARGEDATA_SC_CHG_EN] = "chgEn",
	[ECHUB_CHARGEDATA_SC_ADC_CTRL] = "adcCtrl",
	[ECHUB_CHARGEDATA_SC_ADC_FN_DIS] = "adcFnDis",
	[ECHUB_CHARGEDATA_SC_VBUS] = "vbus",
	[ECHUB_CHARGEDATA_SC_IBUS] = "ibus",
	[ECHUB_CHARGEDATA_SC_VOUT] = "vout",
	[ECHUB_CHARGEDATA_SC_VBAT] = "vbat",
	[ECHUB_CHARGEDATA_SC_FLAG1] = "flag1",
	[ECHUB_CHARGEDATA_SC_FLAG2] = "flag2",
	[ECHUB_CHARGEDATA_SC_FLAG3] = "flag3",
	[ECHUB_CHARGEDATA_SC_FLAG4] = "flag4",
	[ECHUB_CHARGEDATA_SC_FLAG5] = "flag5",
	[ECHUB_CHARGEDATA_SC_STAT1] = "stat1",
	[ECHUB_CHARGEDATA_SC_STAT2] = "stat2",
	[ECHUB_CHARGEDATA_SC_STAT3] = "stat3",
	[ECHUB_CHARGEDATA_SC_STAT4] = "stat4",
	[ECHUB_CHARGEDATA_SC_STAT5] = "stat5",
	[ECHUB_CHARGEDATA_SC_EXTEND1] = "extend1",
	[ECHUB_CHARGEDATA_SC_EXTEND2] = "extend2",
	[ECHUB_CHARGEDATA_SC_EXTEND3] = "extend3",
	[ECHUB_CHARGEDATA_SC_EXTEND4] = "extend4",
	[ECHUB_CHARGEDATA_SC_EXTEND5] = "extend5",
	[ECHUB_CHARGEDATA_SC_EXTEND6] = "extend6",
};

static const struct echub_chargedata_dfx_info g_echub_batt_info[] = {
	{ ECHUB_CHARGEDATA_RSOC, 1, 2 },
	{ ECHUB_CHARGEDATA_VOLTAGE, 3, 2 },
	{ ECHUB_CHARGEDATA_BATTERY_STATUS, 9, 2 },
	{ ECHUB_CHARGEDATA_CURRENT, 11, 2 },
	{ ECHUB_CHARGEDATA_AVERAGE_CURRENT, 13, 2 },
	{ ECHUB_CHARGEDATA_TEMPERATURE, 15, 2 },
	{ ECHUB_CHARGEDATA_CHARGING_CURRENT, 17, 2 },
	{ ECHUB_CHARGEDATA_CHARGING_VOLTAGE, 19, 2 },
	{ ECHUB_CHARGEDATA_FET_TEMP, 29, 2 },
	{ ECHUB_CHARGEDATA_CELL_VOLTAGE1, 31, 2 },
	{ ECHUB_CHARGEDATA_CELL_VOLTAGE2, 33, 2 },
	{ ECHUB_CHARGEDATA_CELL_VOLTAGE3, 35, 2 },
	{ ECHUB_CHARGEDATA_CELL_VOLTAGE4, 37, 2 },
	{ ECHUB_CHARGEDATA_TS1TEMP, 39, 2 },
	{ ECHUB_CHARGEDATA_TS2TEMP, 41, 2 },
	{ ECHUB_CHARGEDATA_TS3TEMP, 43, 2 },
	{ ECHUB_CHARGEDATA_TS4TEMP, 45, 2 },
	{ ECHUB_CHARGEDATA_SAFETY_STATUS, 49, 4 },
	{ ECHUB_CHARGEDATA_PF_STATUS, 53, 4 },
	{ ECHUB_CHARGEDATA_OPERATION_STATUS, 57, 4 },
	{ ECHUB_CHARGEDATA_STATE_OF_HEALTH, 61, 2 },
	{ ECHUB_CHARGEDATA_CHARGING_STATUS, 63, 4 },
	{ ECHUB_CHARGEDATA_ASOC, 67, 2 },
	{ ECHUB_CHARGEDATA_REMAINING_CAPACITY, 69, 2 },
	{ ECHUB_CHARGEDATA_FULL_CHARGE_CAPACITY, 71, 2 },
	{ ECHUB_CHARGEDATA_CYCLE_COUNT, 73, 2 },
	{ ECHUB_CHARGEDATA_INNER_TEMP, 155, 2 },
	{ ECHUB_CHARGEDATA_CELL_TEMP, 157, 2 },
	{ ECHUB_CHARGEDATA_GAUG_TEMP, 159, 2 },
	{ ECHUB_CHARGEDATA_GAUING_STATUS, 161, 4 },
	{ ECHUB_CHARGEDATA_QMAX_CELL1, 200, 2 },
	{ ECHUB_CHARGEDATA_QMAX_CELL2, 202, 2 },
	{ ECHUB_CHARGEDATA_QMAX_CELL3, 204, 2 },
	{ ECHUB_CHARGEDATA_QMAX_CELL4, 206, 2 },
	{ ECHUB_CHARGEDATA_SOHFCC, 210, 2 },          // sohFcc    209-211   1 len + 2 bytes
};

static const struct echub_chargedata_dfx_info g_echub_charge_info[] = {
	/* CHG2 DFX INFO */
	{ ECHUB_CHARGEDATA_CHG_OP0, 1, 2 },
	{ ECHUB_CHARGEDATA_CHG_OP1, 3, 2 },
	{ ECHUB_CHARGEDATA_CHG_OP2, 5, 2 },
	{ ECHUB_CHARGEDATA_CHG_OP3, 7, 2 },
	{ ECHUB_CHARGEDATA_CHG_OP4, 9, 2 },
	{ ECHUB_CHARGEDATA_CHG_OP5, 11, 2 },
	{ ECHUB_CHARGEDATA_CHG_PROCHOTOP0, 13, 2 },
	{ ECHUB_CHARGEDATA_CHG_PROCHOTOP1, 15, 2 },
	{ ECHUB_CHARGEDATA_CHG_PROCHOTSTATUS, 17, 2 },
	{ ECHUB_CHARGEDATA_CHG_STATUS, 19, 2 },
	{ ECHUB_CHARGEDATA_CHG_STATUS2, 21, 2 },
	{ ECHUB_CHARGEDATA_CHG_VSYSMIN, 23, 2 },
	{ ECHUB_CHARGEDATA_CHG_VOLTAGE, 25, 2 },
	{ ECHUB_CHARGEDATA_CHG_CURRENT, 27, 2 },
	{ ECHUB_CHARGEDATA_CHG_INPUTCURRENT, 29, 2 },
	{ ECHUB_CHARGEDATA_CHG_INPUTVOLTAGE, 31, 2 },
	{ ECHUB_CHARGEDATA_CHG_VENDER_ID, 33, 2 },
	{ ECHUB_CHARGEDATA_CHG_VOLT_IN_ADC, 35, 2 },
	{ ECHUB_CHARGEDATA_CHG_CURR_IN_ADC, 37, 2 },
	{ ECHUB_CHARGEDATA_DUALCHG_STATE, 39, 2 },
	{ ECHUB_CHARGEDATA_SYS_STATE, 41, 2 },
	{ ECHUB_CHARGEDATA_PRE_JUMP_RSOC, 43, 2 },
	{ ECHUB_CHARGEDATA_POST_JUMP_RSOC, 45, 2 },
	{ ECHUB_CHARGEDATA_POWERBANK_CNT, 47, 2 },
	/* IDX CHG INFO */
	{ ECHUB_CHARGEDATA_IDX_CHARGE_RSOC_MAX, 49, 1 },
	{ ECHUB_CHARGEDATA_IDX_CHARGE_RSOC_MIN, 50, 1 },
	{ ECHUB_CHARGEDATA_IDX_CHARGE_STATUS, 51, 1 },
	{ ECHUB_CHARGEDATA_IDX_CHARGE_SCENE, 52, 1 },
	{ ECHUB_CHARGEDATA_IDX_REQUEST_VBUS, 53, 2 },
	{ ECHUB_CHARGEDATA_IDX_REQUEST_IBUS, 55, 2 },
	{ ECHUB_CHARGEDATA_IDX_ADPATER_REAL_VBUS, 57, 2 },
	{ ECHUB_CHARGEDATA_IDX_ADPATER_REAL_IBUS, 59, 2 },
	/* CHG2 DFX INFO, START AT 0x80 */
	{ ECHUB_CHARGEDATA_CHG2_OP0, 129, 2 },
	{ ECHUB_CHARGEDATA_CHG2_OP1, 131, 2 },
	{ ECHUB_CHARGEDATA_CHG2_OP2, 133, 2 },
	{ ECHUB_CHARGEDATA_CHG2_OP3, 135, 2 },
	{ ECHUB_CHARGEDATA_CHG2_OP4, 137, 2 },
	{ ECHUB_CHARGEDATA_CHG2_OP5, 139, 2 },
	{ ECHUB_CHARGEDATA_CHG2_PROCHOTOP0, 141, 2 },
	{ ECHUB_CHARGEDATA_CHG2_PROCHOTOP1, 143, 2 },
	{ ECHUB_CHARGEDATA_CHG2_PROCHOTSTATUS, 145, 2 },
	{ ECHUB_CHARGEDATA_CHG2_STATUS, 147, 2 },
	{ ECHUB_CHARGEDATA_CHG2_STATUS2, 149, 2 },
	{ ECHUB_CHARGEDATA_CHG2_VSYSMIN, 151, 2 },
	{ ECHUB_CHARGEDATA_CHG2_VOLTAGE, 153, 2 },
	{ ECHUB_CHARGEDATA_CHG2_CURRENT, 155, 2 },
	{ ECHUB_CHARGEDATA_CHG2_INPUTCURRENT, 157, 2 },
	{ ECHUB_CHARGEDATA_CHG2_INPUTVOLTAGE, 159, 2 },
	{ ECHUB_CHARGEDATA_CHG2_VENDER_ID, 161, 2 },
	{ ECHUB_CHARGEDATA_CHG2_VOLT_IN_ADC, 163, 2 },
	{ ECHUB_CHARGEDATA_CHG2_CURR_IN_ADC, 165, 2 },
	/* IDX SC_CHG INFO */
	{ ECHUB_CHARGEDATA_SC_MAGIC, 177, 2 }, // SC_CHG:0x5A5B
	{ ECHUB_CHARGEDATA_SC_VENDOR, 179, 1 }, // 0-"SC8571"  1-"NU2205"  2-"BQ25980"
	{ ECHUB_CHARGEDATA_SC_CHG_EN, 180, 1 },
	{ ECHUB_CHARGEDATA_SC_ADC_CTRL, 181, 1 },
	{ ECHUB_CHARGEDATA_SC_ADC_FN_DIS, 182, 1 },
	{ ECHUB_CHARGEDATA_SC_VBUS, 183, 2 },
	{ ECHUB_CHARGEDATA_SC_IBUS, 185, 2 },
	{ ECHUB_CHARGEDATA_SC_VOUT, 187, 2 },
	{ ECHUB_CHARGEDATA_SC_VBAT, 189, 2 },
	{ ECHUB_CHARGEDATA_SC_FLAG1, 191, 1 },
	{ ECHUB_CHARGEDATA_SC_FLAG2, 192, 1 },
	{ ECHUB_CHARGEDATA_SC_FLAG3, 193, 1 },
	{ ECHUB_CHARGEDATA_SC_FLAG4, 194, 1 },
	{ ECHUB_CHARGEDATA_SC_FLAG5, 195, 1 },
	{ ECHUB_CHARGEDATA_SC_STAT1, 196, 1 },
	{ ECHUB_CHARGEDATA_SC_STAT2, 197, 1 },
	{ ECHUB_CHARGEDATA_SC_STAT3, 198, 1 },
	{ ECHUB_CHARGEDATA_SC_STAT4, 199, 1 },
	{ ECHUB_CHARGEDATA_SC_STAT5, 200, 1 },
	{ ECHUB_CHARGEDATA_SC_EXTEND1, 201, 1 },
	{ ECHUB_CHARGEDATA_SC_EXTEND2, 202, 1 },
	{ ECHUB_CHARGEDATA_SC_EXTEND3, 203, 1 },
	{ ECHUB_CHARGEDATA_SC_EXTEND4, 204, 1 },
	{ ECHUB_CHARGEDATA_SC_EXTEND5, 205, 1 },
	{ ECHUB_CHARGEDATA_SC_EXTEND6, 206, 1 },
};

static int echub_chargedata_convert2int(u8 *para, int length)
{
	int i;
	int res = 0;

	if (!para)
		return -EINVAL;

	for (i = 0; i < length; i++) {
		res += para[i] << (i * ECHUB_BITS_PER_BYTE);
	}

	return res;
}

static int echub_chargedata_convert_temp(int tempK)
{
	return (tempK - ECHUB_CAHRGEDATA_BAT_TEMP_ZERO) / ECHUB_CAHRGEDATA_BAT_TEMP_UNIT;
}

static void echub_chargedata_convert_manufacture(struct echub_chargedata_device_info *di, u8 *rev_buf, int len)
{
	uint16_t date_value;
	uint16_t year, month, day;
	int ret;

	if (!di || !rev_buf) {
		echub_err("[%s:%dL] di or rev_buf is NULL\n", __func__, __LINE__);
		return;
	}

	/* Date Value = Day + Month*32 + (Year–1980)*512 */
	date_value = (rev_buf[ECHUB_MFDATE_OFFSET + 1] << SHIFT_OFFSET_1_BYTE) | rev_buf[ECHUB_MFDATE_OFFSET];
	year = (date_value >> MFDATE_YEAR_OFFSET) + ECHUB_MFDATE_BASE_YEAR;
	month = (date_value >> MFDATE_MONTH_OFFSET) & 0xF;
	day = date_value & 0x1F;

	ret = snprintf_s(di->mfdate, ECHUB_MFDATE_LEN, ECHUB_MFDATE_LEN - 1, "%hu-%hu-%hu", year, month, day);
	if (ret < 0)
		echub_err("%s:snprintf err\n", __func__);
    g_echub_chargelog_head_mfinfo[ECHUB_MFDATE].val_str = di->mfdate;
	/* manufactureName offset in BAT_DFX is 79-92 */
    ret = memcpy_s(di->mfname, ECHUB_MFNAME_LEN, rev_buf + ECHUB_MFNAME_OFFSET, ECHUB_MFNAME_LEN);
	if (ret != 0)
		echub_err("%s: memcpy_s err\n", __func__);
	g_echub_chargelog_head_mfinfo[ECHUB_MFNAME].val_str = di->mfname;
	/* devname offset in BAT_DFX is 133-154 */
    ret = memcpy_s(di->devname, ECHUB_DEVNAME_LEN, rev_buf + ECHUB_DEVNAME_OFFSET, ECHUB_DEVNAME_LEN);
	if (ret != 0)
		echub_err("%s: memcpy_s err\n", __func__);
	g_echub_chargelog_head_mfinfo[ECHUB_DEVICENAME].val_str = di->devname;
}

static int echub_get_gauge_sta2_info_by_type(int index, u8 *rev_buf, int len, struct echub_chargedata_device_info *di)
{
	int i, ret;
	int offset = g_echub_chargelog_head_gaug_sta2info[index].offset;
	int size = g_echub_chargelog_head_gaug_sta2info[index].size;
	int type = g_echub_chargelog_head_gaug_sta2info[index].type;
	u32 res = 0;
	int retLen;
	char *pstr = NULL;
	
	switch (type) {
	case TYPE_DEMICAL:
		for (i = 0; i < size; i++)
			res += (rev_buf[offset + i] << (i * ECHUB_BITS_PER_BYTE));
		ret = snprintf_s(di->gaugSta2[index], ECHUB_GAUGSTA_BUFSIZE, ECHUB_GAUGSTA_BUFSIZE - 1, "%u", res);
		if (ret < 0)
			echub_err("%s:snprintf dec err, ret = %d\n", __func__, ret);
		break;
	case TYPE_HEX:
		pstr = di->gaugSta2[index];
		retLen = ECHUB_GAUGSTA_BUFSIZE;
		for (i = 0; i < size; i++) {
			ret = snprintf_s(pstr, retLen, retLen - 1, "%02x", rev_buf[offset + i]);
			if (ret != 2) {    /* 2: strlen of uint8 to char */
				echub_err("%s:snprintf hex err, ret = %d index = %d\n", __func__, ret, i);
				return -EINVAL;
			}
			pstr += ret;
			retLen = retLen - ret;
		}
		break;
	default:
		echub_err("%s: invalid type:%d\n", __func__, g_echub_chargelog_head_gaug_sta2info[index].type);
		return -EINVAL;
	}
	return 0;
}

static void echub_chargedata_convert_gauge_sta2(struct echub_chargedata_device_info *di, u8 *rev_buf, int len)
{
	int i = 0;
	int ret;

	if (!di || !rev_buf) {
		echub_err("[%s:%dL] di or rev_buf is NULL\n", __func__, __LINE__);
		return;
	}

	for (i = 0; i < ARRAY_SIZE(g_echub_chargelog_head_gaug_sta2info); i++) {
		ret = echub_get_gauge_sta2_info_by_type(i, rev_buf, len, di);
		if (ret != 0) {
			echub_err("%s: print %s fail!\n", __func__, g_echub_chargelog_head_gaug_sta2info[i].name);
			return;
		}
	}
}

void echub_chargedata_hmi_get_batt_info(struct echub_chargedata_device_info *di)
{
	int i, ret;
	u8 input_buff = 0;
	u8 rev_buf[ECHUB_HMI_REV_BUFF_LEN_BLOCK] = { 0 };

	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}

	ret = hmi_transfer(GET_BATTART_DFX_LOG, &input_buff, 1, rev_buf, ECHUB_HMI_REV_BUFF_LEN_BLOCK);
	if (ret) {
		echub_err("%s: hmi read err\n", __func__);
		return;
	}

	for (i = 0; i < ARRAY_SIZE(g_echub_batt_info); i++)
		di->charge_data[g_echub_batt_info[i].para] =
			echub_chargedata_convert2int(rev_buf + g_echub_batt_info[i].index, g_echub_batt_info[i].length);

	/* convert temp °K to °C */
	di->charge_data[ECHUB_CHARGEDATA_TEMPERATURE] =
		echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_TEMPERATURE]);
	di->charge_data[ECHUB_CHARGEDATA_TS1TEMP] = echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_TS1TEMP]);
	di->charge_data[ECHUB_CHARGEDATA_TS2TEMP] = echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_TS2TEMP]);
	di->charge_data[ECHUB_CHARGEDATA_TS3TEMP] = echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_TS3TEMP]);
	di->charge_data[ECHUB_CHARGEDATA_TS4TEMP] = echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_TS4TEMP]);
	di->charge_data[ECHUB_CHARGEDATA_INNER_TEMP] =
		echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_INNER_TEMP]);
	di->charge_data[ECHUB_CHARGEDATA_CELL_TEMP] =
		echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_CELL_TEMP]);
	di->charge_data[ECHUB_CHARGEDATA_FET_TEMP] =
		echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_FET_TEMP]);
	di->charge_data[ECHUB_CHARGEDATA_GAUG_TEMP] =
		echub_chargedata_convert_temp(di->charge_data[ECHUB_CHARGEDATA_GAUG_TEMP]);

	/* correct wrong Ibat to negative number */
	di->charge_data[ECHUB_CHARGEDATA_CURRENT] = (short)di->charge_data[ECHUB_CHARGEDATA_CURRENT];
	di->charge_data[ECHUB_CHARGEDATA_AVERAGE_CURRENT] = (short)di->charge_data[ECHUB_CHARGEDATA_AVERAGE_CURRENT];
	/* perform str data for mfdate, mfname, devname */
	echub_chargedata_convert_manufacture(di, rev_buf, ECHUB_HMI_REV_BUFF_LEN_BLOCK);
	/* perform str data for gauge status */
	echub_chargedata_convert_gauge_sta2(di, rev_buf, ECHUB_HMI_REV_BUFF_LEN_BLOCK);
}

void echub_chargedata_hmi_get_chager_info(struct echub_chargedata_device_info *di)
{
	int i, ret;
	u8 input_buff = 0;
	u8 rev_buf[ECHUB_HMI_REV_BUFF_LEN_BLOCK] = { 0 };

	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}

	ret = hmi_transfer(GET_CHARGE_DFX_LOG, &input_buff, 1, rev_buf, ECHUB_HMI_REV_BUFF_LEN_BLOCK);
	if (ret) {
		echub_err("%s: hmi read err\n", __func__);
		return;
	}

	for (i = 0; i < ARRAY_SIZE(g_echub_charge_info); i++)
		di->charge_data[g_echub_charge_info[i].para] =
			echub_chargedata_convert2int(rev_buf + g_echub_charge_info[i].index, g_echub_charge_info[i].length);

	/* modify special parameter */
	di->charge_data[ECHUB_CHARGEDATA_CHG_INPUTCURRENT] =
		(di->charge_data[ECHUB_CHARGEDATA_CHG_INPUTCURRENT] >> ECHUB_BITS_PER_BYTE) * INPUT_CURR_UNIT;
	di->charge_data[ECHUB_CHARGEDATA_CHG_INPUTVOLTAGE] += INPUT_VOLT_INCREMENT;

	di->charge_data[ECHUB_CHARGEDATA_CHG2_INPUTCURRENT] =
		(di->charge_data[ECHUB_CHARGEDATA_CHG2_INPUTCURRENT] >> ECHUB_BITS_PER_BYTE) * INPUT_CURR_UNIT;
	di->charge_data[ECHUB_CHARGEDATA_CHG2_INPUTVOLTAGE] += INPUT_VOLT_INCREMENT;

	/* check if sc charger */
	if (di->charge_data[ECHUB_CHARGEDATA_SC_MAGIC] == IDX_SC_CHARGER_MAGIC) {
		g_is_sc_charger = true;
		echub_info("[%s] Magic [5A5B] is match sc charger!\n", __func__);
	}
}

static int get_pd_dfx_info(int index, echub_bigdata_dmd_pd_data *pd_dfx)
{
	int ret;
    unsigned char value[PD_DFX_INFO_SIZE];
    unsigned char send = (unsigned char)index;
    struct echub_chargedata_device_info *di = get_chargedata_dev();

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
        echub_err("%s:%d di or echub_dev is null\n", __func__, __LINE__);
        return -EINVAL;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, 0x02d5, &send, 1, value, PD_DFX_INFO_SIZE);
    if (ret) {
        echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
        return ret;
    }

	ret = memcpy_s(pd_dfx, sizeof(echub_bigdata_dmd_pd_data), value, PD_DFX_INFO_SIZE);
    return ret;
}

static void config_pd_dfx_info(struct echub_chargedata_device_info *di, int i, echub_bigdata_dmd_pd_data pd_dfx)
{
	di->pd_data[i][ECHUB_PDDATA_SINKPATH] = pd_dfx.sinkPath;
	di->pd_data[i][ECHUB_PDDATA_PLUG_DIRECTION] = pd_dfx.plugDirection;
	di->pd_data[i][ECHUB_PDDATA_IS_HUAWEI_DEVICE] = pd_dfx.isHwDevice;
	di->pd_data[i][ECHUB_PDDATA_IS_DISPLAY] = pd_dfx.isDisplay;
	di->pd_data[i][ECHUB_PDDATA_IS_TBT] = pd_dfx.isTBT;
	di->pd_data[i][ECHUB_PDDATA_PROTOCOL] = pd_dfx.protocol;
	di->pd_data[i][ECHUB_PDDATA_PD_VERSION1] = pd_dfx.pdVersion1;
	di->pd_data[i][ECHUB_PDDATA_PD_VERSION2] = pd_dfx.pdVersion2;
	di->pd_data[i][ECHUB_PDDATA_PD_VERSION3] = pd_dfx.pdVersion3;
	di->pd_data[i][ECHUB_PDDATA_VBUS] = pd_dfx.vBus;
	di->pd_data[i][ECHUB_PDDATA_PCHREG] = pd_dfx.pchReg;
}

void echub_chargedata_hmi_get_pd_info(struct echub_chargedata_device_info *di)
{
	int ret, i;
	echub_bigdata_dmd_pd_data pd_info[PD_DFX_INFO_NUM_MAX] = { 0 };

	if (!di) {
		echub_err("%s: di NULL\n", __func__);
		return;
	}

	if (di->charge_data[ECHUB_CHARGEDATA_DUALCHG_STATE] == 1) {
		di->dual_status = 1; // 1 enable
		echub_err("[%s]: Charge_log get DUAL_CHARGER Enable, Set dual_status to 1\n", __func__);
	}
	for (i = 0; i < PD_DFX_INFO_NUM_MAX; i++) {
		ret = get_pd_dfx_info(i, &pd_info[i]);
		if (ret) {
			continue;
		}
		config_pd_dfx_info(di, i, pd_info[i]);
	}
}

static int get_pd_vbus_from_i2c(void)
{
	struct echub_chargedata_device_info *di = g_ec_chargedata_di;
	char value0[PD_VBUS_READ_LEN] = {0};
	char value1[PD_VBUS_READ_LEN] = {0};
	int pd_vbus;
	int ret;

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
        echub_err("%s:%d di or echub_dev is null\n", __func__, __LINE__);
        return -EINVAL;
    }
	// pd_vbus
	ret = di->echub_dev->read_func(di->echub_dev, EC_I2C_CMD_PD_VBUS, PD_VBUS_HIGH_BYTE, value0, PD_VBUS_READ_LEN);
	if (ret < 0) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	ret = di->echub_dev->read_func(di->echub_dev, EC_I2C_CMD_PD_VBUS, PD_VBUS_LOW_BYTE, value1, PD_VBUS_READ_LEN);
	if (ret < 0) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	pd_vbus = (value0[2] << SHIFT_OFFSET_1_BYTE) + value1[2]; // 2 is the data byte
	return pd_vbus;
}

static int get_pdo_max_from_i2c(void)
{
	struct echub_chargedata_device_info *di = g_ec_chargedata_di;
	char value[EC_I2C_DATA_MAXLEN] = {0};
	int pdo;
	int ret;

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
        echub_err("%s:%d di or echub_dev is null\n", __func__, __LINE__);
        return -EINVAL;
    }
	ret = di->echub_dev->read_func(di->echub_dev, EC_I2C_CMD_PDO, EC_I2C_PDO_OFFSET, value, EC_I2C_DATA_MAXLEN);
	if (ret < 0) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	pdo = (value[3] << SHIFT_OFFSET_1_BYTE) + value[2]; // 2,3 is the data bytes
	return pdo;
}

static int get_pd_data_from_i2c(int regoffset, char regdata, int bytes, int *temp)
{
	int ret;
	struct echub_chargedata_device_info *di = g_ec_chargedata_di;

	if (!di) {
        echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
        return -EINVAL;
    }
	switch (regdata) {
	case PDVBUS_PD:
		ret = get_pd_vbus_from_i2c();
		if (ret < 0) {
			echub_err("get pd_vbus failed, ret = %d\n", ret);
			return ret;
		}
		di->pdvbus = ret;
		*temp = ret;
		break;
	case PDO_PD:
		ret = get_pdo_max_from_i2c();
		if (ret < 0) {
			echub_err("get pdo_max failed, ret = %d\n", ret);
			return ret;
		}
		di->pdo_max = ret;
		*temp = ret;
		break;
	default:
		echub_err("[%s] put paras error\n", __func__);
		return -ENODEV;
    }

	return 0;
}

static int get_fan_speed_from_i2c(int regoffset, char regdata, int bytes, int *temp)
{
	struct echub_chargedata_device_info *di = g_ec_chargedata_di;
	char value[EC_I2C_DATA_MAXLEN] = {0};
	
	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
        echub_err("%s:%d di or echub_dev is null\n", __func__, __LINE__);
        return -EINVAL;
    }
	// fan_speed
	int ret = di->echub_dev->read_func(di->echub_dev, regoffset, regdata, value, bytes);
	if (ret) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	*temp = (value[3] << SHIFT_OFFSET_1_BYTE) + value[2]; // 2,3 is the data bytes
	return 0;
}

static int get_ntc_data_from_i2c(int regoffset, char regdata, int bytes, int *temp)
{
	struct echub_chargedata_device_info *di = g_ec_chargedata_di;
	char value[EC_I2C_DATA_MAXLEN] = {0};
	
	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
        echub_err("%s:%d di or echub_dev is null\n", __func__, __LINE__);
        return -EINVAL;
    }
	// sensor_temp
	int ret = di->echub_dev->read_func(di->echub_dev, regoffset, regdata, value, bytes);
	if (ret) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
	*temp = ((value[3] << SHIFT_OFFSET_1_BYTE) + value[2]) / 10; // 2,3 is the data bytes, 10 means decimal notation
	return 0;
}

static const struct echub_channel_sensor_info echub_func_list[] = {
	{"PDVbus", ECHUB_CHARGEDATA_PD_VBUS,      get_pd_data_from_i2c,   EC_I2C_CMD_PDO, PDVBUS_PD, I2C_NTC_DATA_MAXLEN},
	{"PDO",    ECHUB_CHARGEDATA_PDO,          get_pd_data_from_i2c,   EC_I2C_CMD_PD_VBUS, PDO_PD,  PD_VBUS_READ_LEN},
	{"SOCNTC", ECHUB_CHARGEDATA_SOC_NTC,      get_ntc_data_from_i2c,  EC_I2C_CMD_NTC,  SOC_NTC, I2C_NTC_DATA_MAXLEN},
	{"ChgNTC", ECHUB_CHARGEDATA_CHARGER_NTC,  get_ntc_data_from_i2c,  EC_I2C_CMD_NTC,  CHRG_NTC, I2C_NTC_DATA_MAXLEN},
	{"Chg2NTC", ECHUB_CHARGEDATA_CHARGER2_NTC,  get_ntc_data_from_i2c,  EC_I2C_CMD_NTC,  CHRG2_NTC, I2C_NTC_DATA_MAXLEN},
	{"Tc1NTC", ECHUB_CHARGEDATA_TYPEC1_NTC, get_ntc_data_from_i2c,  EC_I2C_CMD_NTC,  TYPEC1_NTC, I2C_NTC_DATA_MAXLEN},
	{"Tc2NTC", ECHUB_CHARGEDATA_TYPEC2_NTC, get_ntc_data_from_i2c,  EC_I2C_CMD_NTC,  TYPEC2_NTC, I2C_NTC_DATA_MAXLEN},
	{"Tc3NTC", ECHUB_CHARGEDATA_TYPEC3_NTC, get_ntc_data_from_i2c,  EC_I2C_CMD_NTC,  TYPEC3_NTC, I2C_NTC_DATA_MAXLEN},
	{"Tc4NTC", ECHUB_CHARGEDATA_TYPEC4_NTC, get_ntc_data_from_i2c,  EC_I2C_CMD_NTC,  TYPEC4_NTC, I2C_NTC_DATA_MAXLEN},
	{"Amb1NTC", ECHUB_CHARGEDATA_AMBIENCE1_NTC, get_ntc_data_from_i2c, EC_I2C_CMD_NTC, AMBIENCE1_NTC, I2C_NTC_DATA_MAXLEN},
	{"Amb2NTC", ECHUB_CHARGEDATA_AMBIENCE2_NTC, get_ntc_data_from_i2c, EC_I2C_CMD_NTC, AMBIENCE2_NTC, I2C_NTC_DATA_MAXLEN},
	{"Fan0S",  ECHUB_CHARGEDATA_FAN0_SPEED,   get_fan_speed_from_i2c, EC_I2C_CMD_FAN,  FAN0_SPEED,  I2C_NTC_DATA_MAXLEN},
	{"Fan1S",  ECHUB_CHARGEDATA_FAN1_SPEED,   get_fan_speed_from_i2c, EC_I2C_CMD_FAN,  FAN1_SPEED,  I2C_NTC_DATA_MAXLEN},
	{"Fan2S",  ECHUB_CHARGEDATA_FAN2_SPEED,   get_fan_speed_from_i2c, EC_I2C_CMD_FAN,  FAN2_SPEED,  I2C_NTC_DATA_MAXLEN},
};

void echub_chargedata_i2c_get_ntc_info(struct echub_chargedata_device_info *info)
{
	int i, ret;
	int raw_temp = NTC_TEMP_INVALID;

	for (i = 0; i < ARRAY_SIZE(echub_func_list); i++) {
		ret = echub_func_list[i].process(echub_func_list[i].regoffset,
			echub_func_list[i].regdata,
			echub_func_list[i].bytes,
			&raw_temp);
		if (ret) {
			echub_err("%s failed %d ret = %d sensor:%s\n",
				__func__, __LINE__, ret, echub_func_list[i].sensor_type);
			continue;
		}
		info->charge_data[echub_func_list[i].index] = raw_temp;
	}
}

static int echub_chargedata_dump_space_before(char *buffer, int size, int type, int *rlen,
	struct echub_chargedata_device_info *di)
{
	int ret;
	char front_space[] = "    ";

	ret = snprintf_s(buffer, size, size - 1, "%s", front_space);
	if (ret < 0) {
		echub_err("%s:snprintf err\n", __func__);
		return ret;
	}
	rlen = strlen(front_space);
	return 0;
}

static void echub_clear_and_set_new_space(char *buffer, int size, int space_size)
{
	int ret;

	ret = memset_s(buffer, size, 0, size);
	if (ret != 0) {
		echub_err("%s:separate_space clear err!\n", __func__);
		return;
	}
	ret = memset_s(buffer, size, ' ', space_size);
	if (ret != 0) {
		echub_err("%s:separate_space set space err!\n", __func__);
		return;
	}
}

static int echub_chargedata_dump_manufacture_info(char *buffer, int size, int type, int *rlen,
	struct echub_chargedata_device_info *di)
{
	int ret, i;
	int retlen = 0;
	char mf_info[CHGLOG_HEAD_LEN] = { 0 };
	char separate_space[CHGLOG_BUF_LEN] = { 0 };

	for (i = 0; i < ECHUB_MF_INFO_NUM_MAX; i++) {
		if (type == DUMP_HEAD) {
			ret = snprintf_s(mf_info, CHGLOG_HEAD_LEN, CHGLOG_HEAD_LEN - 1, "%-*s",
				g_echub_chargelog_head_mfinfo[i].size, g_echub_chargelog_head_mfinfo[i].name);
			if (ret < 0) {
				echub_err("%s:snprintf mf head err\n", __func__);
				return ret;
			}
		} else if (type == DUMP_CONTENT) {
			if (g_count == 1) {
				echub_clear_and_set_new_space(separate_space, CHGLOG_BUF_LEN, g_echub_chargelog_head_mfinfo[i].size);
				ret = snprintf_s(mf_info, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%-*s",
					g_echub_chargelog_head_mfinfo[i].size, separate_space);
			} else {
				ret = snprintf_s(mf_info, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%-*s",
					g_echub_chargelog_head_mfinfo[i].size, g_echub_chargelog_head_mfinfo[i].val_str);
			}
			if (ret < 0) {
				echub_err("%s:snprintf mf content err\n", __func__);
				return ret;
			}
		}

		ret = strcat_s(buffer, size, mf_info);
		if (ret) {
			echub_err("%s:strcat mf_info err\n", __func__);
			return ret;
		}
		retlen += DUMP_MF_BUF_MAX;    // 24mfinfo + 4space
	}
	*rlen = retlen;
	return 0;
}

static int echub_chargedata_prepare_data(int i, char *content_buff, int len, struct echub_chargedata_device_info *di)
{
	int ret;
	char content_space[] = "            ";    // Add 12 spaces instead of the same length data when g_count = 1
	
	if (((i >= ECHUB_CHARGEDATA_CHG_VENDER_ID) && (i <= ECHUB_CHARGEDATA_POWERBANK_CNT)) ||
		(i >= ECHUB_CHARGEDATA_CHG2_VENDER_ID && i <= ECHUB_CHARGEDATA_CHG2_CURR_IN_ADC))
		return 0;
	if (g_count == 1) {
		ret = snprintf_s(content_buff, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%s", content_space);
		return ret;
	}
	switch (i) {
	case ECHUB_CHARGEDATA_SC_VENDOR:
		ret = snprintf_s(content_buff, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%-12s", g_sc_chg_type[di->charge_data[i]]);
		break;
	case ECHUB_CHARGEDATA_STA_TIME:
		ret = snprintf_s(content_buff, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%-12s", di->staTime);
		break;
	case ECHUB_CHARGEDATA_SAFETY_STATUS:
	case ECHUB_CHARGEDATA_GAUING_STATUS:
	case ECHUB_CHARGEDATA_CHG_OP0:
	case ECHUB_CHARGEDATA_CHG_STATUS2:
	case ECHUB_CHARGEDATA_CHG2_OP0:
	case ECHUB_CHARGEDATA_CHG2_STATUS2:
	case ECHUB_CHARGEDATA_SC_FLAG1:
	case ECHUB_CHARGEDATA_SC_EXTEND6:
	case ECHUB_CHARGEDATA_SC_MAGIC:
		ret = snprintf_s(content_buff, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "0x%-10x", di->charge_data[i]);
		break;
	default:
		ret = snprintf_s(content_buff, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%-12d", di->charge_data[i]);
		break;
	}
	if (ret < 0)
		echub_err("%s:snprintf err\n", __func__);
	return ret;
}

static int echub_chargedata_dump_chargelog_main(char *buffer, int size, int type, int *rlen,
	struct echub_chargedata_device_info *di)
{
	int i, ret;
	int retlen = 0;
	char data_buff[CHGLOG_BUF_LEN] = { 0 };

	for (i = 0; i < ECHUB_CHARGELOG_END; i++) {
		if ((i >= ECHUB_CHARGEDATA_CHG_VENDER_ID && i <= ECHUB_CHARGEDATA_POWERBANK_CNT) ||
			(i >= ECHUB_CHARGEDATA_CHG2_VENDER_ID && i <= ECHUB_CHARGEDATA_CHG2_CURR_IN_ADC))
			continue;
		
		if (type == DUMP_HEAD) {
			ret = snprintf_s(data_buff, CHGLOG_HEAD_LEN, CHGLOG_HEAD_LEN - 1, "%-12s", g_echub_chargelog_head[i]);
			if (ret < 0) {
				echub_err("%s:snprintf err\n", __func__);
				return ret;
			}
		} else if (type == DUMP_CONTENT) {
			ret = echub_chargedata_prepare_data(i, data_buff, CHGLOG_BUF_LEN, di);
			if (ret == 0)    // ret = 0 means skip current data in list
				continue;
			if (ret < 0) {
				echub_err("%s:prepare data err\n", __func__);
				return ret;
			}
		}

		ret = strcat_s(buffer, size, data_buff);
		if (ret) {
			echub_err("%s:strcat err\n", __func__);
			return ret;
		}
		retlen += strlen(data_buff);
	}
	*rlen = retlen;
	return 0;
}

static int echub_chargedata_dump_chargelog_extra(char *buffer, int size, int type, int *rlen,
	struct echub_chargedata_device_info *di)
{
	int i, ret;
	int start_data, end_data;
	int retlen = 0;
	char data_buff[CHGLOG_BUF_LEN] = { 0 };

	start_data = ECHUB_CHARGEDATA_IDX_CHARGE_RSOC_MAX;
	if (!g_is_sc_charger)
		end_data = ECHUB_CHARGEDATA_SC_MAGIC;
	else
		end_data = ECHUB_CHARGEDATA_SC_EXTEND6;

	for (i = start_data; i <= end_data; i++) {
		if (type == DUMP_HEAD) {
			ret = snprintf_s(data_buff, CHGLOG_HEAD_LEN, CHGLOG_HEAD_LEN - 1, "%-12s", g_echub_chargelog_head[i]);
			if (ret < 0) {
				echub_err("%s:snprintf err\n", __func__);
				return ret;
			}
		} else if (type == DUMP_CONTENT) {
			ret = echub_chargedata_prepare_data(i, data_buff, CHGLOG_BUF_LEN, di);
			if (ret == 0)    // ret = 0 means skip current data in list
				continue;
			if (ret < 0) {
				echub_err("%s:prepare data err\n", __func__);
				return ret;
			}
		}

		ret = strcat_s(buffer, size, data_buff);
		if (ret) {
			echub_err("%s:strcat err\n", __func__);
			return ret;
		}
		retlen += strlen(data_buff);
	}
	*rlen = retlen;
	return 0;
}

static int echub_chargedata_dump_gauge_state(char *buffer, int size, int type, int *rlen,
	struct echub_chargedata_device_info *di)
{
	int i, ret;
	int retlen = 0;
	char gaug_info[CHGLOG_HEAD_LEN] = { 0 };
	char separate_space[CHGLOG_BUF_LEN] = { 0 };

	ret = memset_s(separate_space, CHGLOG_BUF_LEN, ' ', ECHUB_GAUGSTA_BUFSIZE - 1);
	if (ret != 0) {
		echub_err("%s: memset_s err\n", __func__);
		return ret;
	}

	for (i = 0; i < ECHUB_GAUG2_INFO_NUM_MAX; i++) {
		if (type == DUMP_HEAD) {
			ret = snprintf_s(gaug_info, CHGLOG_HEAD_LEN, CHGLOG_HEAD_LEN - 1, "%-20s",
				g_echub_chargelog_head_gaug_sta2info[i].name);
			if (ret < 0) {
				echub_err("%s:snprintf gaugSta2 head err\n", __func__);
				return ret;
			}
		} else if (type == DUMP_CONTENT) {
			if (g_count == 1)
				ret = snprintf_s(gaug_info, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%-20s", separate_space);
			else
				ret = snprintf_s(gaug_info, CHGLOG_BUF_LEN, CHGLOG_BUF_LEN - 1, "%-20s", di->gaugSta2[i]);
			if (ret < 0) {
				echub_err("%s:snprintf gaugSta2 content err\n", __func__);
				return ret;
			}
		}

		ret = strcat_s(buffer, size, gaug_info);
		if (ret) {
			echub_err("%s:strcat mf_info err\n", __func__);
			return ret;
		}
		retlen += ECHUB_GAUGSTA_BUFSIZE;
	}
	*rlen = retlen;
	return 0;
}

static int echub_chargedata_dump_batt_gauge_info(char *buffer, int size, int type, int *rlen,
	struct echub_chargedata_device_info *di)
{
	int i, ret;
	int retlen = 0;
	char data_buff[CHGLOG_BUF_LEN] = { 0 };

	for (i = ECHUB_CHARGEDATA_SOHFCC; i <= ECHUB_CHARGEDATA_QMAX_CELL4; i++) {
		if (type == DUMP_HEAD) {
			ret = snprintf_s(data_buff, CHGLOG_HEAD_LEN, CHGLOG_HEAD_LEN - 1, "%-12s", g_echub_chargelog_head[i]);
			if (ret < 0) {
				echub_err("%s:snprintf err\n", __func__);
				return ret;
			}
		} else if (type == DUMP_CONTENT) {
			ret = echub_chargedata_prepare_data(i, data_buff, CHGLOG_BUF_LEN, di);
			if (ret == 0)    // ret = 0 means skip current data in list
				continue;
			if (ret < 0) {
				echub_err("%s:prepare data err\n", __func__);
				return ret;
			}
		}

		ret = strcat_s(buffer, size, data_buff);
		if (ret) {
			echub_err("%s:strcat err\n", __func__);
			return ret;
		}
		retlen += strlen(data_buff);
	}
	*rlen = retlen;
	return 0;
}

static const struct echub_charge_data_report_info echub_report_list[] = {
	{"dump_space_before", echub_chargedata_dump_space_before},
	{"dump_manufacture_info", echub_chargedata_dump_manufacture_info},
	{"dump_chargelog_main", echub_chargedata_dump_chargelog_main},
	{"dump_chargelog_extra", echub_chargedata_dump_chargelog_extra},
	{"dump_batt_gauge_info", echub_chargedata_dump_batt_gauge_info},
	{"dump_batt_gauge_state", echub_chargedata_dump_gauge_state}
};

static int echub_chargedata_dump_head(char *buffer, int size, void *dev_data)
{
	int i, ret;
	int bufSize = 0;
	struct echub_chargedata_device_info *di = dev_data;

	if (!buffer || !di) {
		echub_err("[%s:%d] input paras is null\n", __func__, __LINE__);
		return -EPERM;
	}

	// set g_is_sc_charger before dump head
	echub_chargedata_hmi_get_chager_info(di);

	for (i = 0; i < ARRAY_SIZE(echub_report_list); i++) {
		ret = echub_report_list[i].process(buffer, size, DUMP_HEAD, &bufSize, di);
		if (ret) {
			echub_err("[%s] func: %s failed, ret = %d\n", __func__, echub_report_list[i].report_type, ret);
			continue;
		}
		if (size >= bufSize) {
			size -= bufSize;
		} else {
			echub_err("[%s] func: size overflow next func: %s \n", __func__, echub_report_list[i].report_type);
			return -EINVAL;
		}
	}

	return 0;
}

static int echub_chargedata_dump_content(char *buffer, int size, void *dev_data)
{
	int i, ret;
	int bufSize = 0;
	struct echub_chargedata_device_info *di = dev_data;

	if (!buffer || !di) {
		echub_err("%s di is NULL\n", __func__);
		return -EPERM;
	}

	if (g_resume_flag == 1) {
		g_resume_flag = 0;
		mdelay(100);    // chartgedatadump delay 100ms for s3 resume
	}

	if (g_count == 0) {
		echub_chargedata_hmi_get_batt_info(di);
		echub_chargedata_hmi_get_chager_info(di);
		echub_chargedata_i2c_get_ntc_info(di);
	}

	for (i = 0; i < ARRAY_SIZE(echub_report_list); i++) {
		ret = echub_report_list[i].process(buffer, size, DUMP_CONTENT, &bufSize, di);
		if (ret) {
			echub_err("[%s] func: %s failed, ret = %d\n", __func__, echub_report_list[i].report_type, ret);
			continue;
		}
		if (size >= bufSize) {
			size -= bufSize;
		} else {
			echub_err("[%s] func: size overflow next func: %s \n", __func__, echub_report_list[i].report_type);
			return -EINVAL;
		}
	}

	g_count ^= 1;
	return 0;
}
struct echub_chargedata_device_info *get_chargedata_dev(void)
{
	return g_ec_chargedata_di;
}

static struct power_log_ops echub_chargelog_ops = {
	.dev_name = "echub_chargedata",
	.dump_log_head = echub_chargedata_dump_head,
	.dump_log_content = echub_chargedata_dump_content,
};

static int echub_chargedata_probe(struct platform_device *pdev)
{
	int ret;
	struct echub_chargedata_device_info *di = NULL;

	echub_info("[%s] enter\n", __func__);
	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	struct echub_i2c_dev *echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form func\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("get_echub_dev null\n");
			return -ENODEV;
		}
	}

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	platform_set_drvdata(pdev, di);
	g_ec_chargedata_di = di;
	di->pdev = pdev;
	di->echub_dev = echub_dev;

	echub_chargelog_ops.dev_data = (void *)di;
	ret = power_log_ops_register(&echub_chargelog_ops);
	if (ret < 0) {
		echub_err("%s:power log ops register fail\n", __func__);
		goto FERR_DEVICE_INFO;
	}

	echub_info("%s ok\n", __func__);
	return 0;

FERR_DEVICE_INFO:
	platform_set_drvdata(pdev, NULL);
	g_ec_chargedata_di = NULL;
	echub_err("%s fail\n", __func__);
	return ret;
}

static int echub_chargedata_remove(struct platform_device *pdev)
{
	struct echub_chargedata_device_info *di = NULL;

	if (!pdev)
		return -ENODEV;

	di = platform_get_drvdata(pdev);
	platform_set_drvdata(pdev, NULL);
	g_ec_chargedata_di = NULL;
	return 0;
}

#ifdef CONFIG_PM
static int echub_chargedata_resume(struct platform_device *pdev)
{
	g_resume_flag = 1;
	return 0;
}
#endif /* CONFIG_PM */
static const struct of_device_id echub_chargedata_match_table[] = {
	{ .compatible = "huawei,echub_chargedata" },
	{},
};

static struct platform_driver echub_chargedata_driver = {
	.probe = echub_chargedata_probe,
	.remove = echub_chargedata_remove,
	.driver = {
		.name = "huawei,echub_chargedata",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(echub_chargedata_match_table),
	},
#ifdef CONFIG_PM
	.resume = echub_chargedata_resume,
#endif /* CONFIG_PM */
};

static int __init echub_chargedata_init(void)
{
	echub_info("[%s] enter\n", __func__);
	return platform_driver_register(&echub_chargedata_driver);
}

static void __exit echub_chargedata_exit(void)
{
	platform_driver_unregister(&echub_chargedata_driver);
}

late_initcall(echub_chargedata_init);
module_exit(echub_chargedata_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("echub chargedata driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");