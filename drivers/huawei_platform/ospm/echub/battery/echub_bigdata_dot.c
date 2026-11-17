/*
 * echub_bigdata_dot.c
 *
 * bigdata dot driver for echub
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
 */

#include <linux/device.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <securec.h>
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif

#include "echub_chargedata.h"
#include "echub_battery.h"
#include "ospm_printf.h"
#include "echub_i2c.h"
#include "hmi/hmi.h"

#define ECHUB_DMD_START_WAIT_TIME             10000 /* 10s = 1000ms */
#define ECHUB_DMD_MONITOR_INTERVAL            600000 /* 10min: 10*60*1000ms */
#define ECHUB_MINUTES_PER_HOUR                60 /* 1h = 60min */
#define ECHUB_SECONDS_PER_MINUTE              60 /* 1min = 60s */
#define ECHUB_SECONDS_PER_HOUR                3600 /* 1h = 3600s */
#define ECHUB_SECONDS_PER_DAY                 86400 /* 1day = 24*3600s */

#define CHG_ACOUT               	  		  1
#define CHG_ACIN					  		  0

#define CHG_BATJUMP_PRE               	      0
#define CHG_BATJUMP_POST					  1
#define CLEAR_STATE_DISABLE              	  0
#define CLEAR_STATE_ENABLE 				      1

#define BATTERY_DEVICENAME_CMD                0x0450
#define EC_I2C_READ_1BYTE_LEN                 4
#define EC_VERSION_SIZE                       5
#define EC_VERSION_MAX_SIZE                   20
#define DEVICENAME_BUF_SIZE                   16
#define DEVICENAME_BUF_SIZE_MAX               22

#define PER_DATA_SIZE                         5
#define LIFETIME_BUF_SIZE                     34
#define LIFETIME_STR_BUF_SIZE                 171 /* 171 = 34 * 5 + 1 */
#define LIFETIME_BUF_SIZE_MAX                 34
#define DASTATUS2_BUF_SIZE                    18
#define AC_DURATION_BUF_SIZE                  8
#define DESIGN_CAPACITY_OFFSET                21
#define MANUFACTURED_DATE_OFFSET              77
#define DEVICE_NAME_OFFSET                    133

#define POWER_DSM_BUF_SIZE_0256               256
#define PD_STRING_MAX_SIZE                    40
#define TURBO_CHARGE_MIN_POWER                90

#define ECHUB_BATT_DMD_PER_HOUR               954250000
#define ECHUB_BATT_DMD_PER_DAY                954250002

#define SHIFT_OFFSET_1_BYTE 8
#define SHIFT_OFFSET_2_BYTE 16
#define SHIFT_OFFSET_3_BYTE 24
struct echub_chg_hisysevent_info {
	char *name;
	int index;
	int func;
};

typedef int (*big_data_process_function)(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    );

typedef struct {
    int event_type;
    const char *domain;
    const char *casename;
    big_data_process_function process;
    struct echub_chg_hisysevent_info *casepara;
    enum hisysevent_type type;
} event_info;

struct echub_hisysevent_dot_scheduled {
	struct delayed_work dmd_monitor_work;
	struct timespec64 ts_start_hour;
	struct timespec64 ts_start_day;
	unsigned int dmd_monitor_interval;
	unsigned int dmd_cnt_hour;
	unsigned int dmd_cnt_day;
};

enum echub_get_para {
	/* charge log begin */
	ECHUB_PD_DATA = 0,
	ECHUB_CHARGEDATA,
	ECHUB_BAT_DFX_HMI,
	ECHUB_LIFE_TIME_HMI,
    ECHUB_OTHER_I2C
};

enum echub_bigdata_battery_para {
	ECHUB_BIGDATA_DESIGN_CAPACITY = 0,
	ECHUB_BIGDATA_MANUFACTURED_DATE,
	ECHUB_BIGDATA_DEVICENAME
};

enum echub_bigdata_lifetime_para {
	CHARGER_LIFETIME_DATA_BL1 = 0,
	CHARGER_LIFETIME_DATA_BL2,
	CHARGER_LIFETIME_DATA_BL3,
    CHARGER_LIFETIME_DATA_BL4,
    CHARGER_LIFETIME_DATA_BL5,
    CHARGER_LIFETIME_DATA_BL6,
    CHARGER_LIFETIME_DATA_BL7,
    CHARGER_LIFETIME_DATA_BL8,
    CHARGER_LIFETIME_DATA_BL9,
    CHARGER_LIFETIME_DATA_BL10,
    CHARGER_LIFETIME_DATA_BL11,
    CHARGER_LIFETIME_DATA_BL12,
    CHARGER_DASTATUS2,
    CHARGER_LIFETIME_DATA_END
};

enum echub_bigdata_pd_string {
	PD_VERSION = 0,
	PD_VBUS,
	PD_PCHREG,
    PD_STR_END
};

struct hmi_lifetime_info {
	u8 sendbuf;
    u8 recvbuf[LIFETIME_BUF_SIZE_MAX];
    char strbuf[LIFETIME_STR_BUF_SIZE];
};

struct batt_dfx_info {
	int designCapacity;
    int manufacturerDate;
    char deviceName[DEVICENAME_BUF_SIZE_MAX];
};

struct ec_i2c_acin_info {
	u32 ac_in_time_once;
    u32 ac_in_time_total;
    u32 ac_in_start_rsoc;
    u32 ac_in_end_rsoc;
    u32 ac_in_cycle;
};

struct echub_chg_hisysevent_info ac_in_para[] = {
	{"AC_IN_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"SYS_STATE", ECHUB_CHARGEDATA_SYS_STATE, 1},
    {"SINK_PATH", ECHUB_PDDATA_SINKPATH, 0},
    {"CC_DIRECTION", ECHUB_PDDATA_PLUG_DIRECTION, 0},
    {"DEVICE_TYPE1", ECHUB_PDDATA_IS_HUAWEI_DEVICE, 0},
    {"DEVICE_TYPE2", ECHUB_PDDATA_IS_DISPLAY, 0},
    {"DEVICE_TYPE3", ECHUB_PDDATA_IS_TBT, 0},
    {"PROTOCOL", ECHUB_PDDATA_PROTOCOL, 0}
};

struct echub_chg_hisysevent_info ac_out_para[] = {
	{"AC_OUT_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"SYS_STATE", ECHUB_CHARGEDATA_SYS_STATE, 1},
    {"POWERBANK_CYCLE", ECHUB_CHARGEDATA_POWERBANK_CNT, 1}
};

struct echub_chg_hisysevent_info abnormal_para[] = {
    // batt info from CHARGEDATA
    {"BAT_TEMP", ECHUB_CHARGEDATA_TEMPERATURE, 1},
    {"BAT_VOLTAGE", ECHUB_CHARGEDATA_VOLTAGE, 1},
    {"BAT_CURRENT", ECHUB_CHARGEDATA_CURRENT, 1},
    {"BAT_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"BAT_RMC", ECHUB_CHARGEDATA_REMAINING_CAPACITY, 1},
    {"BAT_FCC", ECHUB_CHARGEDATA_FULL_CHARGE_CAPACITY, 1},
    {"BAT_CC", ECHUB_CHARGEDATA_CHARGING_CURRENT, 1},
    {"BAT_CV", ECHUB_CHARGEDATA_CHARGING_VOLTAGE, 1},
    {"BAT_CYCLECOUNT", ECHUB_CHARGEDATA_CYCLE_COUNT, 1},
    {"BAT_CELL1VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE1, 1},
    {"BAT_CELL2VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE2, 1},
    {"BAT_CELL3VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE3, 1},
    {"BAT_CELL4VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE4, 1},
    {"BAT_SAFETYSTATUS", ECHUB_CHARGEDATA_SAFETY_STATUS, 1},
    {"BAT_PF_STATUS", ECHUB_CHARGEDATA_PF_STATUS, 1},
    {"SOC_NTC", ECHUB_CHARGEDATA_SOC_NTC, 1},
    {"CHARGER_NTC", ECHUB_CHARGEDATA_CHARGER_NTC, 1},
    {"CHARGER2_NTC", ECHUB_CHARGEDATA_CHARGER2_NTC, 1},
    {"TYPEC_NTC1", ECHUB_CHARGEDATA_TYPEC1_NTC, 1},
    {"TYPEC_NTC2", ECHUB_CHARGEDATA_TYPEC2_NTC, 1},
    {"TYPEC_NTC3", ECHUB_CHARGEDATA_TYPEC3_NTC, 1},
    {"TYPEC_NTC4", ECHUB_CHARGEDATA_TYPEC4_NTC, 1},
    {"AMB_NTC1", ECHUB_CHARGEDATA_AMBIENCE1_NTC, 1},
    {"AMB_NTC2", ECHUB_CHARGEDATA_AMBIENCE2_NTC, 1},
    {"FAN0_SPEED", ECHUB_CHARGEDATA_FAN0_SPEED, 1},
    {"FAN1_SPEED", ECHUB_CHARGEDATA_FAN1_SPEED, 1},
    {"FAN2_SPEED", ECHUB_CHARGEDATA_FAN2_SPEED, 1},
    // charge1 info
    {"CHG1_OP0", ECHUB_CHARGEDATA_CHG_OP0, 1},
    {"CHG1_OP1", ECHUB_CHARGEDATA_CHG_OP1, 1},
    {"CHG1_OP2", ECHUB_CHARGEDATA_CHG_OP2, 1},
    {"CHG1_OP3", ECHUB_CHARGEDATA_CHG_OP3, 1},
    {"CHG1_STATUS", ECHUB_CHARGEDATA_CHG_STATUS, 1},
    {"CHG1_STATUS2", ECHUB_CHARGEDATA_CHG_STATUS2, 1},
    {"CHG1_VSYSMIN", ECHUB_CHARGEDATA_CHG_VSYSMIN, 1},
    {"CHG1_VOLTAGE", ECHUB_CHARGEDATA_CHG_VOLTAGE, 1},
    {"CHG1_CURRENT", ECHUB_CHARGEDATA_CHG_CURRENT, 1},
    {"CHG1_INPUTCURRENT", ECHUB_CHARGEDATA_CHG_INPUTCURRENT, 1},
    {"CHG1_INPUTVOLTAGE", ECHUB_CHARGEDATA_CHG_INPUTVOLTAGE, 1},
    {"CHG1_ID", ECHUB_CHARGEDATA_CHG_VENDER_ID, 1},
    {"CHG1_VIN_ADC", ECHUB_CHARGEDATA_CHG_VOLT_IN_ADC, 1},
    {"CHG1_IIN_ADC", ECHUB_CHARGEDATA_CHG_CURR_IN_ADC, 1},
    // charge2 info
    {"CHG2_OP0", ECHUB_CHARGEDATA_CHG2_OP0, 1},
    {"CHG2_OP1", ECHUB_CHARGEDATA_CHG2_OP1, 1},
    {"CHG2_OP2", ECHUB_CHARGEDATA_CHG2_OP2, 1},
    {"CHG2_OP3", ECHUB_CHARGEDATA_CHG2_OP3, 1},
    {"CHG2_STATUS", ECHUB_CHARGEDATA_CHG2_STATUS, 1},
    {"CHG2_STATUS2", ECHUB_CHARGEDATA_CHG2_STATUS2, 1},
    {"CHG2_VSYSMIN", ECHUB_CHARGEDATA_CHG2_VSYSMIN, 1},
    {"CHG2_VOLTAGE", ECHUB_CHARGEDATA_CHG2_VOLTAGE, 1},
    {"CHG2_CURRENT", ECHUB_CHARGEDATA_CHG2_CURRENT, 1},
    {"CHG2_INPUTCURRENT", ECHUB_CHARGEDATA_CHG2_INPUTCURRENT, 1},
    {"CHG2_INPUTVOLTAGE", ECHUB_CHARGEDATA_CHG2_INPUTVOLTAGE, 1},
    {"CHG2_ID", ECHUB_CHARGEDATA_CHG2_VENDER_ID, 1},
    {"CHG2_VIN_ADC", ECHUB_CHARGEDATA_CHG2_VOLT_IN_ADC, 1},
    {"CHG2_IIN_ADC", ECHUB_CHARGEDATA_CHG2_CURR_IN_ADC, 1}
};

struct echub_chg_hisysevent_info prochot_para[] = {
    {"CHG1_PROCHOTOP0", ECHUB_CHARGEDATA_CHG_PROCHOTOP0, 1},
    {"CHG1_PROCHOTOP1", ECHUB_CHARGEDATA_CHG_PROCHOTOP1, 1},
    {"CHG1_PROCHOTOP_STATUS", ECHUB_CHARGEDATA_CHG_PROCHOTSTATUS, 1},
    {"CHG2_PROCHOTOP0", ECHUB_CHARGEDATA_CHG2_PROCHOTOP0, 1},
    {"CHG2_PROCHOTOP1", ECHUB_CHARGEDATA_CHG2_PROCHOTOP1, 1},
    {"CHG2_PROCHOTOP_STATUS", ECHUB_CHARGEDATA_CHG2_PROCHOTSTATUS, 1}
};

struct echub_chg_hisysevent_info batjump_para[] = {
    {"BAT_CURRENT", ECHUB_CHARGEDATA_CURRENT, 1},
    {"BAT_CELL1VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE1, 1},
    {"BAT_CELL2VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE2, 1},
    {"BAT_CELL3VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE3, 1},
    {"BAT_CELL4VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE4, 1},
    {"BAT_TEMP", ECHUB_CHARGEDATA_TEMPERATURE, 1},
    {"BAT_RMC", ECHUB_CHARGEDATA_REMAINING_CAPACITY, 1},
    {"BAT_FCC", ECHUB_CHARGEDATA_FULL_CHARGE_CAPACITY, 1},
    {"PRE_JUMP", ECHUB_CHARGEDATA_PRE_JUMP_RSOC, 1},
    {"POST_JUMP", ECHUB_CHARGEDATA_POST_JUMP_RSOC, 1}
};

struct echub_chg_hisysevent_info chg_rate_para[] = {
    {"CHG1_STATUS", ECHUB_CHARGEDATA_CHG_STATUS, 1},
    {"CHG1_VSYSMIN", ECHUB_CHARGEDATA_CHG_VSYSMIN, 1},
    {"CHG1_VOLTAGE", ECHUB_CHARGEDATA_CHG_VOLTAGE, 1},
    {"CHG1_CURRENT", ECHUB_CHARGEDATA_CHG_CURRENT, 1},
    {"CHG1_INPUTCURRENT", ECHUB_CHARGEDATA_CHG_INPUTCURRENT, 1},
    {"CHG1_INPUTVOLTAGE", ECHUB_CHARGEDATA_CHG_INPUTVOLTAGE, 1},
    {"CHG1_VIN_ADC", ECHUB_CHARGEDATA_CHG_VOLT_IN_ADC, 1},
    {"CHG1_IIN_ADC", ECHUB_CHARGEDATA_CHG_CURR_IN_ADC, 1},
    {"CHG2_STATUS", ECHUB_CHARGEDATA_CHG2_STATUS, 1},
    {"CHG2_VSYSMIN", ECHUB_CHARGEDATA_CHG2_VSYSMIN, 1},
    {"CHG2_VOLTAGE", ECHUB_CHARGEDATA_CHG2_VOLTAGE, 1},
    {"CHG2_CURRENT", ECHUB_CHARGEDATA_CHG2_CURRENT, 1},
    {"CHG2_INPUTCURRENT", ECHUB_CHARGEDATA_CHG2_INPUTCURRENT, 1},
    {"CHG2_INPUTVOLTAGE", ECHUB_CHARGEDATA_CHG2_INPUTVOLTAGE, 1},
    {"CHG2_VIN_ADC", ECHUB_CHARGEDATA_CHG2_VOLT_IN_ADC, 1},
    {"CHG2_IIN_ADC", ECHUB_CHARGEDATA_CHG2_CURR_IN_ADC, 1},
    {"BAT_TEMP", ECHUB_CHARGEDATA_TEMPERATURE, 1},
    {"BAT_VOLTAGE", ECHUB_CHARGEDATA_VOLTAGE, 1},
    {"BAT_CURRENT", ECHUB_CHARGEDATA_CURRENT, 1},
    {"BAT_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"BAT_RMC", ECHUB_CHARGEDATA_REMAINING_CAPACITY, 1},
    {"BAT_FCC", ECHUB_CHARGEDATA_FULL_CHARGE_CAPACITY, 1},
    {"BAT_CC", ECHUB_CHARGEDATA_CHARGING_CURRENT, 1},
    {"BAT_CV", ECHUB_CHARGEDATA_CHARGING_VOLTAGE, 1},
    {"BAT_CYCLECOUNT", ECHUB_CHARGEDATA_CYCLE_COUNT, 1},
    {"BAT_CELL1VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE1, 1},
    {"BAT_CELL2VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE2, 1},
    {"BAT_CELL3VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE3, 1},
    {"BAT_CELL4VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE4, 1},
    {"BAT_PF_STATUS", ECHUB_CHARGEDATA_PF_STATUS, 1},
    {"VENDOR_ID", ECHUB_CHARGEDATA_CHG_VENDER_ID, 1},
    {"SOC_NTC", ECHUB_CHARGEDATA_SOC_NTC, 1},
    {"CHARGER_NTC", ECHUB_CHARGEDATA_CHARGER_NTC, 1},
    {"CHARGER2_NTC", ECHUB_CHARGEDATA_CHARGER2_NTC, 1},
    {"TYPEC_NTC1", ECHUB_CHARGEDATA_TYPEC1_NTC, 1},
    {"TYPEC_NTC2", ECHUB_CHARGEDATA_TYPEC2_NTC, 1},
    {"TYPEC_NTC3", ECHUB_CHARGEDATA_TYPEC3_NTC, 1},
    {"TYPEC_NTC4", ECHUB_CHARGEDATA_TYPEC4_NTC, 1},
    {"AMB_NTC1", ECHUB_CHARGEDATA_AMBIENCE1_NTC, 1},
    {"AMB_NTC2", ECHUB_CHARGEDATA_AMBIENCE2_NTC, 1},
    {"FAN0_SPEED", ECHUB_CHARGEDATA_FAN0_SPEED, 1},
    {"FAN1_SPEED", ECHUB_CHARGEDATA_FAN1_SPEED, 1},
    {"FAN2_SPEED", ECHUB_CHARGEDATA_FAN2_SPEED, 1}
};

struct echub_chg_hisysevent_info temp_abnormal_para[] = {
    {"BAT_TEMP", ECHUB_CHARGEDATA_TEMPERATURE, 1},
    {"BAT_VOLTAGE", ECHUB_CHARGEDATA_VOLTAGE, 1},
    {"BAT_CURRENT", ECHUB_CHARGEDATA_CURRENT, 1},
    {"BAT_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"BAT_DASTATUS2", CHARGER_DASTATUS2, 3},
    {"IC_TEMP", ECHUB_CHARGEDATA_INNER_TEMP, 1},
    {"TS1_TEMP", ECHUB_CHARGEDATA_TS1TEMP, 1},
    {"TS2_TEMP", ECHUB_CHARGEDATA_TS2TEMP, 1},
    {"TS3_TEMP", ECHUB_CHARGEDATA_TS3TEMP, 1},
    {"TS4_TEMP", ECHUB_CHARGEDATA_TS4TEMP, 1},
    {"CELL_TEMP", ECHUB_CHARGEDATA_CELL_TEMP, 1},
    {"FET_TEMP", ECHUB_CHARGEDATA_FET_TEMP, 1},
    {"GAUGE_TEMP", ECHUB_CHARGEDATA_GAUG_TEMP, 1}
};

struct echub_chg_hisysevent_info over_voltage_para[] = {
    {"BAT_TEMP", ECHUB_CHARGEDATA_TEMPERATURE, 1},
    {"BAT_CURRENT", ECHUB_CHARGEDATA_CURRENT, 1},
    {"BAT_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"BAT_CC", ECHUB_CHARGEDATA_CHARGING_CURRENT, 1},
    {"BAT_CV", ECHUB_CHARGEDATA_CHARGING_VOLTAGE, 1},
    {"BAT_CELL1VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE1, 1},
    {"BAT_CELL2VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE2, 1},
    {"BAT_CELL3VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE3, 1},
    {"BAT_CELL4VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE4, 1}
};

struct echub_chg_hisysevent_info bat_abnormal_para[] = {
    {"BAT_CYCLECOUNT", ECHUB_CHARGEDATA_CYCLE_COUNT, 1},
    {"BAT_SAFETYSTATUS", ECHUB_CHARGEDATA_SAFETY_STATUS, 1},
    {"BAT_PF_STATUS", ECHUB_CHARGEDATA_PF_STATUS, 1}
};

struct echub_chg_hisysevent_info voltage_imbalance_para[] = {
    {"BAT_CURRENT", ECHUB_CHARGEDATA_CURRENT, 1},
    {"BAT_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"BAT_CYCLECOUNT", ECHUB_CHARGEDATA_CYCLE_COUNT, 1},
    {"BAT_CELL1VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE1, 1},
    {"BAT_CELL2VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE2, 1},
    {"BAT_CELL3VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE3, 1},
    {"BAT_CELL4VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE4, 1},
    {"BAT_OPERATION_STATUS", ECHUB_CHARGEDATA_OPERATION_STATUS, 1}
};

struct echub_chg_hisysevent_info echub_dot_1h_para[] = {
    {"BAT_TEMP", ECHUB_CHARGEDATA_TEMPERATURE, 1},
    {"BAT_VOLTAGE", ECHUB_CHARGEDATA_VOLTAGE, 1},
    {"BAT_CURRENT", ECHUB_CHARGEDATA_CURRENT, 1},
    {"BAT_RSOC", ECHUB_CHARGEDATA_RSOC, 1},
    {"BAT_RMC", ECHUB_CHARGEDATA_REMAINING_CAPACITY, 1},
    {"BAT_FCC", ECHUB_CHARGEDATA_FULL_CHARGE_CAPACITY, 1},
    {"BAT_CC", ECHUB_CHARGEDATA_CHARGING_CURRENT, 1},
    {"BAT_CV", ECHUB_CHARGEDATA_CHARGING_VOLTAGE, 1},
    {"BAT_STATUS", ECHUB_CHARGEDATA_BATTERY_STATUS, 1},
    {"BAT_CELL1VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE1, 1},
    {"BAT_CELL2VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE2, 1},
    {"BAT_CELL3VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE3, 1},
    {"BAT_CELL4VOL", ECHUB_CHARGEDATA_CELL_VOLTAGE4, 1},
    {"BAT_CYCLECOUNT", ECHUB_CHARGEDATA_CYCLE_COUNT, 1},
    {"IC_TEMP", ECHUB_CHARGEDATA_INNER_TEMP, 1},
    {"TS1_TEMP", ECHUB_CHARGEDATA_TS1TEMP, 1},
    {"TS2_TEMP", ECHUB_CHARGEDATA_TS2TEMP, 1},
    {"TS3_TEMP", ECHUB_CHARGEDATA_TS3TEMP, 1},
    {"TS4_TEMP", ECHUB_CHARGEDATA_TS4TEMP, 1},
    {"CELL_TEMP", ECHUB_CHARGEDATA_CELL_TEMP, 1},
    {"FET_TEMP", ECHUB_CHARGEDATA_FET_TEMP, 1},
    {"GAUGE_TEMP", ECHUB_CHARGEDATA_GAUG_TEMP, 1}
};

struct echub_chg_hisysevent_info echub_dot_1day_para[] = {
    {"DESIGN_CAPACITY", ECHUB_BIGDATA_DESIGN_CAPACITY, ECHUB_BAT_DFX_HMI},
    {"MANUFACTURED_DATE", ECHUB_BIGDATA_MANUFACTURED_DATE, ECHUB_BAT_DFX_HMI},
    {"DEVICENAME", ECHUB_BIGDATA_DEVICENAME, ECHUB_BAT_DFX_HMI},
    {"BAT_CYCLECOUNT", ECHUB_CHARGEDATA_CYCLE_COUNT, ECHUB_CHARGEDATA},
    {"BAT_STATE_OF_HEALTH", ECHUB_CHARGEDATA_STATE_OF_HEALTH, ECHUB_CHARGEDATA},
    {"BAT_SAFETY_STATUS", ECHUB_CHARGEDATA_SAFETY_STATUS, ECHUB_CHARGEDATA},
    {"BAT_PF_STATUS", ECHUB_CHARGEDATA_PF_STATUS, ECHUB_CHARGEDATA},
    {"BAT_FCC", ECHUB_CHARGEDATA_FULL_CHARGE_CAPACITY, ECHUB_CHARGEDATA},
    {"DASTATUS2", CHARGER_DASTATUS2, ECHUB_LIFE_TIME_HMI},
    {"BAT_TEMP_MAX", ECHUB_CHARGEDATA_TEMPERATURE, ECHUB_CHARGEDATA},
    {"TS1_TEMP", ECHUB_CHARGEDATA_TS1TEMP, ECHUB_CHARGEDATA},
    {"TS2_TEMP", ECHUB_CHARGEDATA_TS2TEMP, ECHUB_CHARGEDATA},
    {"TS3_TEMP", ECHUB_CHARGEDATA_TS3TEMP, ECHUB_CHARGEDATA},
    {"TS4_TEMP", ECHUB_CHARGEDATA_TS4TEMP, ECHUB_CHARGEDATA},
    {"CELL_TEMP", ECHUB_CHARGEDATA_CELL_TEMP, ECHUB_CHARGEDATA},
    {"FET_TEMP", ECHUB_CHARGEDATA_FET_TEMP, ECHUB_CHARGEDATA},
    {"GAUGE_TEMP", ECHUB_CHARGEDATA_GAUG_TEMP, ECHUB_CHARGEDATA}
};

static struct notifier_block g_hmi_batt_event_nb;

static struct notifier_block g_hmi_pd_event_nb;

static struct echub_hisysevent_dot_scheduled g_dot_scheduled_di = {0};

static struct hmi_lifetime_info g_lifetime_data[CHARGER_LIFETIME_DATA_END] = { 0 };

static struct batt_dfx_info g_batt_dfx_data;

static struct ec_i2c_acin_info g_i2c_acin_data = {0};

static char g_ec_version[EC_VERSION_MAX_SIZE] = {0};

static bool echub_get_ac_state(void)
{
    char value[EC_I2C_READ_1BYTE_LEN] = {0};
	struct echub_chargedata_device_info *di = get_chargedata_dev();

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
        echub_err("[%s:%d] di or echub_dev is null\n", __func__, __LINE__);
        return FALSE;
    }
    int ret = di->echub_dev->read_func(di->echub_dev, 0x0280, 0x81, value, EC_I2C_READ_1BYTE_LEN);
	if (ret) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}

    if (value[2] & 0x01) { // 2 is data byte
        return TRUE;
    }
    return FALSE;
}

static int get_ec_version(char *version, int buf_len)
{
	int ret;
    u8 main_version[EC_VERSION_SIZE + 1] = {0};
    u8 sub_version[EC_VERSION_SIZE + 1] = {0};
    struct echub_chargedata_device_info *di = get_chargedata_dev();

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("[%s:%d] di or echub_dev is null\n", __func__, __LINE__);
        return -EINVAL;
    }

	ret = di->echub_dev->transfer_func(di->echub_dev, 0x0681, NULL, 0, main_version, EC_VERSION_SIZE);
	msleep(10); // delay 10ms
	ret |= di->echub_dev->transfer_func(di->echub_dev, 0x0691, NULL, 0, sub_version, EC_VERSION_SIZE);
	if (ret) {
		echub_err("%s, get ec version failed: %d\n", __func__, ret);
        return ret;
	}

    return snprintf_s(version, PAGE_SIZE, PAGE_SIZE - 1, "v%s-%s\n", main_version, sub_version);
}

static char *get_batt_manufacture(void)
{
    struct echub_batt_device_info *di = echub_get_batt_di();

    if (!di || !di->bat_manufactory_name) {
        echub_err("[%s:%d] di or bat_manufactory_name is null\n", __func__, __LINE__);
        return NULL;
    }

    echub_info("[%s] get bat_manufactory_name: %s\n", __func__, di->bat_manufactory_name);
    return di->bat_manufactory_name;
}

static void get_ac_in_duration(void)
{
	int ret;
    u8 value[AC_DURATION_BUF_SIZE] = {0};
    struct echub_chargedata_device_info *di = get_chargedata_dev();

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("[%s:%d] di or echub_dev is null\n", __func__, __LINE__);
        return;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, 0x02e2, NULL, 0, value, AC_DURATION_BUF_SIZE);
    if (ret) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return;
	}
    g_i2c_acin_data.ac_in_time_once = (((value[1] << SHIFT_OFFSET_1_BYTE) | value[0]) * ECHUB_MINUTES_PER_HOUR) +
                                        ((value[3] << SHIFT_OFFSET_1_BYTE) | value[2]);    // 2,3 is array subscript
    g_i2c_acin_data.ac_in_time_total = (value[7] << SHIFT_OFFSET_3_BYTE) | // byte 7 is the highest
                                       (value[6] << SHIFT_OFFSET_2_BYTE) | // byte 6 is the second highest
                                       (value[5] << SHIFT_OFFSET_1_BYTE) | // byte 5 is the second lowest
                                       (value[4]); // byte 4 is the lowest
    echub_info("[%s] ac_in_time_once = %d, ac_in_time_total = %d\n",
        __func__, g_i2c_acin_data.ac_in_time_once, g_i2c_acin_data.ac_in_time_total);
}

static int get_ac_out_dual_state(int need_clear)
{
    int dual_state;
    struct echub_chargedata_device_info *di = get_chargedata_dev();

    dual_state = di->dual_status;
    echub_info("[%s] dual_state = 0x%X\n", __func__, dual_state);

    if (need_clear == CLEAR_STATE_ENABLE && di->dual_status == 1)
        di->dual_status = 0;

    return dual_state;
}

static int get_ac_out_turbo_state(int need_clear)
{
    int tbo_state;
    struct echub_batt_device_info *di = echub_get_batt_di();
 
    tbo_state = di->turbo_status;
    echub_info("[%s] di->turbo_status = 0x%X\n", __func__, tbo_state);

    if (need_clear == CLEAR_STATE_ENABLE && di->turbo_status == 1)
        di->turbo_status = 0;

    return tbo_state;
}

static int get_soc_limit_value(void)
{
	int ret;
    char value[EC_I2C_READ_1BYTE_LEN];
    struct echub_chargedata_device_info *di = get_chargedata_dev();

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
        echub_err("%s:%d di or echub_dev is null\n", __func__, __LINE__);
        return -EINVAL;
    }
	ret = di->echub_dev->read_func(di->echub_dev, 0x0269, 0x02, value, EC_I2C_READ_1BYTE_LEN);
    if (ret) {
		echub_err("%s failed %d ret = %d\n", __func__, __LINE__, ret);
		return ret;
	}
    return (int)value[2]; // 2 is data byte
}

static int print_buffer(char *buffer, const char *recvbuf, int size)
{
    int i, ret;
    char *formatted_buffer = NULL;
    int buf_len = size * PER_DATA_SIZE + 1;

    if (recvbuf[0] == 0x00 && recvbuf[1] == 0x0) {
        ret = snprintf_s(buffer, LIFETIME_STR_BUF_SIZE, LIFETIME_STR_BUF_SIZE - 1, "0x00 ");
        return ret;
    }

    formatted_buffer = kzalloc(buf_len, GFP_KERNEL);
	if (!formatted_buffer)
		return -ENOMEM;

    for (i = 0; i < size; i++) {
        ret = snprintf_s(formatted_buffer + (i * PER_DATA_SIZE),
            (size - i) * PER_DATA_SIZE + 1, PER_DATA_SIZE, "0x%02X ", recvbuf[i]);
        if (ret < 0) {
			echub_err("%s:snprintf err\n", __func__);
			kfree(formatted_buffer);
			return ret;
		}
    }

    ret = memcpy_s(buffer, LIFETIME_STR_BUF_SIZE, formatted_buffer, size * PER_DATA_SIZE + 1);
	if (ret < 0) {
        echub_err("%s:memcpy_s err! ret:%d\n", __func__, ret);
    }
    kfree(formatted_buffer);
    return ret;
}

static void echub_chargedata_hmi_get_lifetime_info(void)
{
    int ret, i;

    // Get LifeTime 1-12 from HMI
    for (i = 0; i <= CHARGER_LIFETIME_DATA_BL12; i++) {
        g_lifetime_data[i].sendbuf = i + 1;
        ret = hmi_transfer(i, &g_lifetime_data[i].sendbuf, 1, g_lifetime_data[i].recvbuf, LIFETIME_BUF_SIZE);
        if (ret) {
            echub_err("%s: hmi read lifetime%d err\n", __func__, i + 1);
        }
        print_buffer(g_lifetime_data[i].strbuf, g_lifetime_data[i].recvbuf, LIFETIME_BUF_SIZE);
    }
    // Get DASTATUS2 from HMI
    g_lifetime_data[i].sendbuf = 0x01;
    ret = hmi_transfer(i, g_lifetime_data[i].sendbuf, 1, g_lifetime_data[i].recvbuf, DASTATUS2_BUF_SIZE);
    if (ret) {
        echub_err("%s: hmi read DASTATUS2 err\n", __func__);
        return;
    }
    print_buffer(g_lifetime_data[i].strbuf, g_lifetime_data[i].recvbuf, DASTATUS2_BUF_SIZE);
}

static void echub_chargedata_hmi_get_batt_dfx_info(void)
{
    int ret, i;
    u8 input_buff = 0;
    u8 rev_buf[ECHUB_HMI_REV_BUFF_LEN_BLOCK] = { 0 };

    ret = hmi_transfer(GET_BATTART_DFX_LOG, &input_buff, 1, rev_buf, ECHUB_HMI_REV_BUFF_LEN_BLOCK);
	if (ret) {
		echub_err("%s: hmi read err\n", __func__);
		return;
	}

    g_batt_dfx_data.designCapacity =
            ((rev_buf[DESIGN_CAPACITY_OFFSET + 1]) << ECHUB_BITS_PER_BYTE) + rev_buf[DESIGN_CAPACITY_OFFSET];
    g_batt_dfx_data.manufacturerDate =
            ((rev_buf[MANUFACTURED_DATE_OFFSET + 1]) << ECHUB_BITS_PER_BYTE) + rev_buf[MANUFACTURED_DATE_OFFSET];
    for (i = 1; i < DEVICENAME_BUF_SIZE_MAX; i++) {
        g_batt_dfx_data.deviceName[i - 1] = (char)rev_buf[i + DEVICE_NAME_OFFSET];
    }
}

static bool is_duplicate_pdo(struct echub_chargedata_device_info *di, int type)
{
    static int old_pdo = 0;
    int new_pdo = di->pdo_max;
    bool ret = false;

    echub_info("[%s] Get old_pdo=%d, new_pdo=%d\n", __func__, old_pdo, new_pdo);
    switch (type) {
    case CHG_ACIN:
        return true;
    case CHG_ACOUT:
        if (new_pdo < old_pdo && old_pdo != 0) {
            ret = true;
            echub_err("[%s] Get valid pdo %d, return %d\n", __func__, new_pdo, ret);
        }
        break;
    default:
        echub_err("[%s] put paras error\n", __func__);
        return ret;
    }
    old_pdo = new_pdo;
    return ret;
}

static void ConcatPdString(struct echub_chargedata_device_info *di, int type, int i, char *tmp_str, int len)
{
    if (tmp_str == NULL) {
        echub_err("[%s] input str is null\n", __func__);
        return;
    }

    switch (type) {
    case PD_VERSION:
        (void)snprintf_s(tmp_str, PD_STRING_MAX_SIZE, PD_STRING_MAX_SIZE - 1, "%d.%d.%d",
        di->pd_data[i][ECHUB_PDDATA_PD_VERSION3],
        di->pd_data[i][ECHUB_PDDATA_PD_VERSION2],
        di->pd_data[i][ECHUB_PDDATA_PD_VERSION1]);
        break;
    case PD_VBUS:
        (void)snprintf_s(tmp_str, PD_STRING_MAX_SIZE, PD_STRING_MAX_SIZE - 1, "%d",
            di->pd_data[i][ECHUB_PDDATA_VBUS] * 50); //  vbus unit is 50(mv)
        break;
    case PD_PCHREG:
        (void)snprintf_s(tmp_str, PD_STRING_MAX_SIZE, PD_STRING_MAX_SIZE - 1, "%08X",
            di->pd_data[i][ECHUB_PDDATA_PCHREG]);
        break;
    default:
        echub_err("[%s] put paras error\n", __func__);
        (void)snprintf_s(tmp_str, PD_STRING_MAX_SIZE, PD_STRING_MAX_SIZE - 1, "NULL");
        break;
    }
}

static void ConcatPdAllData(struct echub_chargedata_device_info *di, int *pd_integer, char *pd_string, int pd_str_len)
{
    int i, type;
    int len = 0;
    char *tmp_str = NULL;
    char *temp = NULL;

    // concat pd interger data
    for (i = 0; i < PD_DFX_INFO_NUM_MAX; i++) {
        pd_integer[ECHUB_PDDATA_SINKPATH]         |= (di->pd_data[i][ECHUB_PDDATA_SINKPATH] << (i * 1));
        pd_integer[ECHUB_PDDATA_PLUG_DIRECTION]   |= (di->pd_data[i][ECHUB_PDDATA_PLUG_DIRECTION] << (i * 1));
        pd_integer[ECHUB_PDDATA_IS_HUAWEI_DEVICE] |= (di->pd_data[i][ECHUB_PDDATA_IS_HUAWEI_DEVICE] << (i * 1));
        pd_integer[ECHUB_PDDATA_IS_DISPLAY]       |= (di->pd_data[i][ECHUB_PDDATA_IS_DISPLAY] << (i * 1));
        pd_integer[ECHUB_PDDATA_IS_TBT]           |= (di->pd_data[i][ECHUB_PDDATA_IS_TBT] << (i * 1));
        pd_integer[ECHUB_PDDATA_PROTOCOL]         |= (di->pd_data[i][ECHUB_PDDATA_PROTOCOL] << (i * 3)); // 3 bits
    }
    // concat pd string data
    tmp_str = kzalloc(PD_STRING_MAX_SIZE, GFP_KERNEL);
    if (!tmp_str)
		return;

    for (type = 0; type < PD_STR_END; type++) {
        len = 0;
        temp = pd_string + PD_STRING_MAX_SIZE * type;
        for (i = 0; i < PD_DFX_INFO_NUM_MAX; i++) {
            memset_s(tmp_str, PD_STRING_MAX_SIZE, 0, PD_STRING_MAX_SIZE);
            ConcatPdString(di, type, i, tmp_str, PD_STRING_MAX_SIZE);
            if (memcpy_s(temp + len, PD_STRING_MAX_SIZE - len, tmp_str, strlen(tmp_str)))
                echub_err("[%s] memcpy_s err! type:%d\n", __func__, type);
            if (i < PD_DFX_INFO_NUM_MAX - 1)
                (void)strcat_s(temp, PD_STRING_MAX_SIZE, ",");
            len = i < PD_DFX_INFO_NUM_MAX - 1 ? len + strlen(tmp_str) + 1 : len + strlen(tmp_str);
        }
    }

    kfree(tmp_str);
}

static int hisysevent_put_para_ac_in(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    int pd_integer[ECHUB_PDDATA_END] = {0};
    char pd_string[PD_STR_END][PD_STRING_MAX_SIZE] = {0};

    g_i2c_acin_data.ac_in_start_rsoc = di->charge_data[ECHUB_CHARGEDATA_RSOC];
    g_i2c_acin_data.ac_in_cycle++;

    ConcatPdAllData(di, pd_integer, pd_string[0], PD_STR_END);
    for (int i = 0; i < ARRAY_SIZE(ac_in_para); i++) {
        switch (ac_in_para[i].func) {
        case ECHUB_PD_DATA:
            ret = hisysevent_put_integer(event, ac_in_para[i].name, pd_integer[ac_in_para[i].index]);
            break;
        case ECHUB_CHARGEDATA:
            ret = hisysevent_put_integer(event, ac_in_para[i].name, di->charge_data[ac_in_para[i].index]);
            break;
        default:
            echub_err("[%s] put paras error\n", __func__);
            ret = -1;
            break;
        }
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
        }
    }

    hisysevent_put_integer(event, "PDO", di->pdo_max);
    hisysevent_put_string(event, "EC_VERSION", g_ec_version);
    hisysevent_put_string(event, "PD_VERSIONS", pd_string[PD_VERSION]);
    hisysevent_put_string(event, "VBUS_", pd_string[PD_VBUS]);
    hisysevent_put_string(event, "PCH_REGS", pd_string[PD_PCHREG]);

    return 0;
}

static int hisysevent_put_para_ac_out(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    int clear_state = di->pdo_max < TURBO_CHARGE_MIN_POWER ? CLEAR_STATE_ENABLE : CLEAR_STATE_DISABLE;

    g_i2c_acin_data.ac_in_end_rsoc = di->charge_data[ECHUB_CHARGEDATA_RSOC];

    for (int i = 0; i < ARRAY_SIZE(ac_out_para); i++) {
        ret = hisysevent_put_integer(event, ac_out_para[i].name, di->charge_data[ac_out_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
        }
    }
    get_ac_in_duration();
    hisysevent_put_integer(event, "AC_CYCLE", g_i2c_acin_data.ac_in_cycle);
    hisysevent_put_integer(event, "AC_IN_TIME_ONCE", g_i2c_acin_data.ac_in_time_once);
    hisysevent_put_integer(event, "AC_IN_TIME_TOTAL", g_i2c_acin_data.ac_in_time_total);
    hisysevent_put_integer(event, "TURBOCHG_CYCLE", get_ac_out_turbo_state(clear_state));
    hisysevent_put_integer(event, "DUALCHG_CYCLE", get_ac_out_dual_state(CLEAR_STATE_ENABLE));
    hisysevent_put_string(event, "EC_VERSION", g_ec_version);

    return 0;
}

static int hisysevent_put_para_status_abnormal(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    for (int i = 0; i < ARRAY_SIZE(abnormal_para); i++) {
        ret = hisysevent_put_integer(event, abnormal_para[i].name, di->charge_data[abnormal_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
	    }
    }
    hisysevent_put_integer(event, "CHG_LIMIT", get_soc_limit_value());
    hisysevent_put_integer(event, "PDO", di->pdo_max);
    hisysevent_put_string(event, "EC_VERSION", g_ec_version);

    return 0;
}
static int hisysevent_put_para_prochot_status(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    for (int i = 0; i < ARRAY_SIZE(prochot_para); i++) {
        ret = hisysevent_put_integer(event, prochot_para[i].name, di->charge_data[prochot_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
	    }
    }
    hisysevent_put_string(event, "EC_VERSION", g_ec_version);
    return 0;
}
static int hisysevent_put_para_batjump(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    for (int i = 0; i < ARRAY_SIZE(batjump_para); i++) {
        ret = hisysevent_put_integer(event, batjump_para[i].name, di->charge_data[batjump_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
	    }
    }
    hisysevent_put_string(event, "EC_VERSION", g_ec_version);
    return 0;
}
static int hisysevent_put_para_rate(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int i, ret;
    int sinkPath = 0;
    
    for (i = 0; i < ARRAY_SIZE(chg_rate_para); i++) {
        ret = hisysevent_put_integer(event, chg_rate_para[i].name, di->charge_data[chg_rate_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
	    }
    }
    for (i = 0; i < PD_DFX_INFO_NUM_MAX; i++)
        sinkPath |= (di->pd_data[i][ECHUB_PDDATA_SINKPATH] << i);

    hisysevent_put_integer(event, "SINK_PATH", sinkPath);
    hisysevent_put_integer(event, "CHG_LIMIT", get_soc_limit_value());
    hisysevent_put_integer(event, "PDO", di->pdo_max);
    hisysevent_put_integer(event, "TURBOCHG_STATE", get_ac_out_turbo_state(CLEAR_STATE_DISABLE));
    hisysevent_put_integer(event, "DUALCHG_STATE", get_ac_out_dual_state(CLEAR_STATE_DISABLE));
    hisysevent_put_string(event, "EC_VERSION", g_ec_version);

    return 0;
}
static int hisysevent_put_para_temp(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    echub_chargedata_hmi_get_lifetime_info();
    
    for (int i = 0; i < ARRAY_SIZE(temp_abnormal_para); i++) {
        switch (temp_abnormal_para[i].func) {
        case ECHUB_CHARGEDATA:
            if (temp_abnormal_para[i].index < ECHUB_CHARGEDATA_END) {
                ret = hisysevent_put_integer(event, temp_abnormal_para[i].name,
                                         di->charge_data[temp_abnormal_para[i].index]);
            }
            break;
        case ECHUB_LIFE_TIME_HMI:
            if (temp_abnormal_para[i].index < CHARGER_LIFETIME_DATA_END) {
                ret = hisysevent_put_string(event, temp_abnormal_para[i].name,
                                        g_lifetime_data[temp_abnormal_para[i].index].strbuf);
            }
            break;
        default:
            echub_err("[%s] put paras error\n", __func__);
            ret = -1;
            break;
        }
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
        }
    }
    return 0;
}
static int hisysevent_put_para_over_voltage(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    for (int i = 0; i < ARRAY_SIZE(over_voltage_para); i++) {
        ret = hisysevent_put_integer(event, over_voltage_para[i].name, di->charge_data[over_voltage_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
	    }
    }
    return 0;
}
static int hisysevent_put_para_bat_abnormal(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    for (int i = 0; i < ARRAY_SIZE(bat_abnormal_para); i++) {
        ret = hisysevent_put_integer(event, bat_abnormal_para[i].name, di->charge_data[bat_abnormal_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
	    }
    }
    return 0;
}
static int hisysevent_put_para_voltage_imbalance(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    for (int i = 0; i < ARRAY_SIZE(voltage_imbalance_para); i++) {
        ret = hisysevent_put_integer(event, voltage_imbalance_para[i].name,
                                     di->charge_data[voltage_imbalance_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
        }
    }
    return 0;
}

static int hisysevent_put_para_per_hour(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    for (int i = 0; i < ARRAY_SIZE(echub_dot_1h_para); i++) {
        ret = hisysevent_put_integer(event, echub_dot_1h_para[i].name, di->charge_data[echub_dot_1h_para[i].index]);
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
	    }
    }
    get_ac_in_duration();
    hisysevent_put_integer(event, "AC_IN_TIME_ONCE", g_i2c_acin_data.ac_in_time_once);
    hisysevent_put_integer(event, "AC_IN_TIME_TOTAL", g_i2c_acin_data.ac_in_time_total);
    hisysevent_put_integer(event, "AC_IN_START_RSOC", g_i2c_acin_data.ac_in_start_rsoc);
    hisysevent_put_integer(event, "AC_IN_END_RSOC", g_i2c_acin_data.ac_in_end_rsoc);

    return 0;
}

static int hisysevent_put_para_per_day(
    struct hiview_hisysevent *event,
    struct echub_chargedata_device_info *di,
    struct echub_chg_hisysevent_info *casepara
    )
{
    int ret;
    
    echub_chargedata_hmi_get_lifetime_info();

    for (int i = 0; i < ARRAY_SIZE(echub_dot_1day_para); i++) {
        switch (echub_dot_1day_para[i].func) {
        case ECHUB_CHARGEDATA:
            ret = hisysevent_put_integer(event, echub_dot_1day_para[i].name,
                                         di->charge_data[echub_dot_1day_para[i].index]);
            break;
        case ECHUB_BAT_DFX_HMI:
            break;
        case ECHUB_LIFE_TIME_HMI:
            ret = hisysevent_put_string(event, echub_dot_1day_para[i].name,
                                        g_lifetime_data[echub_dot_1day_para[i].index].strbuf);
            break;
        default:
            echub_err("[%s] put paras error\n", __func__);
            break;
        }
        if (ret != 0) {
            echub_err("[%s]failed to put value/int to event, ret=%d\n", __func__, ret);
            return ret;
        }
    }
    (void)hisysevent_put_integer(event, "DESIGN_CAPACITY", g_batt_dfx_data.designCapacity);
    (void)hisysevent_put_integer(event, "MANUFACTURED_DATE", g_batt_dfx_data.manufacturerDate);
    (void)hisysevent_put_string(event, "DEVICENAME", g_batt_dfx_data.deviceName);
    (void)hisysevent_put_string(event, "BAT_MANUFACTURE", get_batt_manufacture());
    return 0;
}

event_info g_hisyevent_info[] = {
    {NOTIFY_GET_PD_DFX_DATA, "BATTERY", "ECHUB_CHARGE_ACIN", hisysevent_put_para_ac_in, ac_in_para, STATISTIC},
    {AC_STATUS_CHANGE, "BATTERY", "ECHUB_CHARGE_ACOUT", hisysevent_put_para_ac_out, ac_out_para, STATISTIC},
    {CHARGE_STATUS_ABNORMAL, "BATTERY", "ECHUB_CHG_STATUSABNORMAL",
     hisysevent_put_para_status_abnormal, abnormal_para, STATISTIC},
    {CHARGE_PROCHOT_STATUS, "BATTERY", "ECHUB_CHG_PROCHOT_STATUS",
     hisysevent_put_para_prochot_status, prochot_para, STATISTIC},
    {CHARGE_BAT_JUMP, "BATTERY", "ECHUB_CHARGE_BAT_JUMP", hisysevent_put_para_batjump, batjump_para, STATISTIC},
    {CHARGE_RATE, "BATTERY", "ECHUB_CHARGE_RATE", hisysevent_put_para_rate, chg_rate_para, STATISTIC},
    {BATTERY_TEMP_ABNORMAL, "BATTERY", "BAT_TEMPERATURE_ABNORMAL", hisysevent_put_para_temp, temp_abnormal_para, FAULT},
    {CELL_OVER_VOLTAGE, "BATTERY", "CELL_OVERVOLTAGE", hisysevent_put_para_over_voltage, over_voltage_para, FAULT},
    {BATTERY_ABNORMAL, "BATTERY", "BAT_ABNORMAL", hisysevent_put_para_bat_abnormal, bat_abnormal_para, FAULT},
    {CELL_VOLTAGE_IMBALANCE, "BATTERY", "CELL_VOLTAGE_IMBALANCE",
     hisysevent_put_para_voltage_imbalance, voltage_imbalance_para, FAULT},
};

event_info g_hisyevent_dot[] = {
    {ECHUB_BATTERY_MONITOR_ONE_HOUR, "BATTERY", "BAT_ONEHOUR_REPORT",
     hisysevent_put_para_per_hour, echub_dot_1h_para, STATISTIC},
    {ECHUB_BATTERY_MONITOR_ONE_DAY_TI, "BATTERY", "TIR3_BATTERY_ONEDAY_REPORT",
     hisysevent_put_para_per_day, echub_dot_1day_para, STATISTIC},
    {ECHUB_BATTERY_MONITOR_ONE_DAY_SH, "BATTERY", "SH_BATTERY_ONEDAY_REPORT",
     hisysevent_put_para_per_day, echub_dot_1day_para, STATISTIC},
};

#ifdef CONFIG_HISYSEVENT
static void echub_hiview_hisysevent(int i, struct echub_chargedata_device_info *di)
{
	struct hiview_hisysevent *event = NULL;
	int ret;

	event = hisysevent_create(g_hisyevent_info[i].domain, g_hisyevent_info[i].casename, g_hisyevent_info[i].type);
	if (!event) {
		echub_err("[%s] failed to create event\n", __func__);
		return;
	}

    ret = g_hisyevent_info[i].process(event, di, g_hisyevent_info[i].casepara);
	if (ret != 0) {
		echub_err("[%s] failed to put value/int to event, ret=%d\n", __func__, ret);
		goto hisysevent_end;
	}

	ret = hisysevent_write(event);
	if (ret != 0)
		echub_err("[%s] failed to write hisysevent fail, %s\n", __func__, g_hisyevent_info[i].casename);

hisysevent_end:
	hisysevent_destroy(&event);
}

static void echub_chargedata_report_battery(struct echub_chargedata_device_info *di, uint32_t i)
{
    struct hiview_hisysevent *event = NULL;
    int ret;
 
	if (!di) {
		echub_err("%s:di null\n", __func__);
		return;
	}
 
    event = hisysevent_create(g_hisyevent_dot[i].domain, g_hisyevent_dot[i].casename, g_hisyevent_dot[i].type);
    if (!event) {
        echub_err("[%s] failed to create event\n", __func__);
        return;
    }

    ret = g_hisyevent_dot[i].process(event, di, g_hisyevent_dot[i].casepara);
    if (ret != 0) {
        echub_err("[%s] failed to put value/int to event, ret=%d\n", __func__, ret);
        goto hisysevent_end;
    }
	ret = hisysevent_write(event);
	if (ret != 0)
		echub_err("[%s] failed to write hisysevent fail, %s\n", __func__, g_hisyevent_dot[i].casename);

hisysevent_end:
	hisysevent_destroy(&event);
}
#else
static void echub_hiview_hisysevent(int i, struct echub_chargedata_device_info *di)
{
}
static void echub_chargedata_report_battery(struct echub_chargedata_device_info *di, uint32_t i)
{
}
#endif

static void echub_chargedata_dmd_monitor_work(struct work_struct *work)
{
	int hours, minutes, seconds;
	struct echub_chargedata_device_info *di = get_chargedata_dev();
    struct echub_hisysevent_dot_scheduled *time = &g_dot_scheduled_di;
	struct timespec64 ts_now;
	struct timespec64 ts_delta;
 
	if (!di || !work || !time) {
        echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
        return;
    }

    echub_chargedata_hmi_get_batt_info(di);
    echub_chargedata_hmi_get_chager_info(di);
    echub_chargedata_i2c_get_ntc_info(di);
    echub_chargedata_hmi_get_pd_info(di);
    echub_chargedata_hmi_get_batt_dfx_info();

	ktime_get_ts64(&ts_now);
	ts_delta = timespec64_sub(ts_now, time->ts_start_hour);
	if ((time->dmd_cnt_hour == 0) || (ts_delta.tv_sec >= ECHUB_SECONDS_PER_HOUR)) {
		echub_chargedata_report_battery(di, ECHUB_BATTERY_MONITOR_ONE_HOUR);
		time->dmd_cnt_hour++;
		hours = ts_now.tv_sec / ECHUB_SECONDS_PER_HOUR;
		minutes = ts_now.tv_sec % ECHUB_SECONDS_PER_HOUR / ECHUB_MINUTES_PER_HOUR;
		seconds = ts_now.tv_sec % ECHUB_SECONDS_PER_MINUTE;
		echub_err("%s: report per hour, cnt = %d, time: %02d:%02d:%02d\n",
			__func__, time->dmd_cnt_hour, hours, minutes, seconds);
		ktime_get_ts64(&time->ts_start_hour);
	}

	ts_delta = timespec64_sub(ts_now, time->ts_start_day);
	if ((time->dmd_cnt_day == 0) || (ts_delta.tv_sec >= ECHUB_SECONDS_PER_DAY)) {
		echub_chargedata_report_battery(di, ECHUB_BATTERY_MONITOR_ONE_DAY_TI);
		time->dmd_cnt_day++;
		hours = ts_now.tv_sec / ECHUB_SECONDS_PER_HOUR;
		minutes = ts_now.tv_sec % ECHUB_SECONDS_PER_HOUR / ECHUB_MINUTES_PER_HOUR;
		seconds = ts_now.tv_sec % ECHUB_SECONDS_PER_MINUTE;
		echub_err("%s: report per day, cnt = %d, time: %02d:%02d:%02d\n",
			__func__, time->dmd_cnt_day, hours, minutes, seconds);
		ktime_get_ts64(&time->ts_start_day);
	}
	schedule_delayed_work(&time->dmd_monitor_work, msecs_to_jiffies(time->dmd_monitor_interval));
}

static void echub_bigdata_report(int index)
{
    struct echub_chargedata_device_info *di = get_chargedata_dev();

	if (!di) {
        echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
        return;
    }

    echub_chargedata_hmi_get_batt_info(di);
    echub_chargedata_hmi_get_chager_info(di);
    echub_chargedata_i2c_get_ntc_info(di);

    if (index == CHG_ACIN || index == CHG_ACOUT) {    // AC_IN/OUT event may ad deduplication first
        if (!is_duplicate_pdo(di, index)) {
            echub_err("[%s] skip ac in/out event due to duplicate pdo\n", __func__);
            return;
        }
    }
    echub_chargedata_hmi_get_pd_info(di);

    echub_hiview_hisysevent(index, di);
}

static int echub_batt_hmi_event_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
    for (int i = 1; i < ARRAY_SIZE(g_hisyevent_info); i++) {
        if (event == g_hisyevent_info[i].event_type) {
            echub_bigdata_report(i);
            break;
        }
    }
    return NOTIFY_OK;
}

// AC_IN used pd_event to monitor
static int echub_pd_hmi_event_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
    echub_err("[%s:%dL] trigger pd_dfx_event!\n", __func__, __LINE__);
    for (int i = 0; i < ARRAY_SIZE(g_hisyevent_info); i++) {
        if (event == g_hisyevent_info[i].event_type) {
            if (event == NOTIFY_GET_PD_DFX_DATA && echub_get_ac_state())
                echub_bigdata_report(i);
            break;
        }
    }
    return NOTIFY_OK;
}

static void echub_chargedata_dmd_para_init(struct echub_hisysevent_dot_scheduled *di)
{
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
        return;
    }
	di->dmd_monitor_interval = ECHUB_DMD_MONITOR_INTERVAL;
	di->dmd_cnt_hour = 0;
	di->dmd_cnt_day = 0;
	ktime_get_ts64(&di->ts_start_hour);
	ktime_get_ts64(&di->ts_start_day);

	INIT_DELAYED_WORK(&di->dmd_monitor_work, echub_chargedata_dmd_monitor_work);
}

static int __init echub_bigdata_dot_notifier_call_init(void)
{
	int ret;
    struct echub_hisysevent_dot_scheduled *di = &g_dot_scheduled_di;

	if (!di) {
        echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
        return -EINVAL;
    }
    ret = get_ec_version(g_ec_version, EC_VERSION_MAX_SIZE);
    if (ret < 0)
        echub_err("[%s:%dL] get_ec_version fail!\n", __func__, __LINE__);

    g_hmi_batt_event_nb.notifier_call = echub_batt_hmi_event_notifier_call;
	ret = hmi_event_bnc_register(HMI_BATTERY_EVENT, &g_hmi_batt_event_nb);
    if (ret != 0) {
        echub_err("[%s]failed to init batt bigdata_dot_notifier, ret=%d\n", __func__, ret);
        return ret;
    }
    g_hmi_pd_event_nb.notifier_call = echub_pd_hmi_event_notifier_call;
	ret = hmi_event_bnc_register(HMI_PD_EVENT, &g_hmi_pd_event_nb);
    if (ret != 0) {
        echub_err("[%s]failed to init pd bigdata_dot_notifier, ret=%d\n", __func__, ret);
        return ret;
    }
    echub_chargedata_dmd_para_init(di);
    schedule_delayed_work(&di->dmd_monitor_work, msecs_to_jiffies(ECHUB_DMD_START_WAIT_TIME));
    return 0;
}

static void __exit echub_bigdata_dot_notifier_call_exit(void)
{
	int ret;
    ret = hmi_event_bnc_unregister(HMI_BATTERY_EVENT, &g_hmi_batt_event_nb);
	if (ret)
		echub_err("%s: hmi batt event bnc unregister fail\n", __func__);
    ret = hmi_event_bnc_unregister(HMI_PD_EVENT, &g_hmi_pd_event_nb);
	if (ret)
		echub_err("%s: hmi pd event bnc unregister fail\n", __func__);
}

late_initcall(echub_bigdata_dot_notifier_call_init);
module_exit(echub_bigdata_dot_notifier_call_exit);