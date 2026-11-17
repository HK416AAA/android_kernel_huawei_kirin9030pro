/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2024. All rights reserved.
 */
#ifndef _LINUX_ECHUB_BATTERY_H
#define _LINUX_ECHUB_BATTERY_H

#include <linux/device.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/notifier.h>
#include <linux/power_supply.h>
#include <linux/notifier.h>
#include <linux/timer.h>

#include "echub_i2c.h"

enum charge_status_event {
	VCHRG_POWER_NONE_EVENT = 0,
	VCHRG_NOT_CHARGING_EVENT,
	VCHRG_START_CHARGING_EVENT,
	VCHRG_START_AC_CHARGING_EVENT,
	VCHRG_START_USB_CHARGING_EVENT,
	VCHRG_CHARGE_DONE_EVENT,
	VCHRG_STOP_CHARGING_EVENT,
	VCHRG_POWER_SUPPLY_OVERVOLTAGE,
	VCHRG_POWER_SUPPLY_WEAKSOURCE,
	VCHRG_STATE_WDT_TIMEOUT,
	VCHRG_STATE_WATER_INTRUSED,
	BATTERY_LOW_WARNING,
	BATTERY_LOW_SHUTDOWN,
	BATTERY_MOVE,
	SWITCH_INTB_WORK_EVENT,
	VCHRG_THERMAL_POWER_OFF,
	WIRELESS_TX_STATUS_CHANGED,
	WIRELESS_COVER_DETECTED,
	VCHRG_CURRENT_FULL_EVENT,
};

/* State-of-Charge-Threshold 1 bit */
#define BQ_FLAG_SOC1			(1<<2)
/* State-of-Charge-Threshold Final bit */
#define BQ_FLAG_SOCF			(1<<1)
#define BQ_FLAG_LOCK			(BQ_FLAG_SOC1 | BQ_FLAG_SOCF)

#define RECHG_PROTECT_THRESHOLD    (150)
#define WORK_INTERVAL_PARA_LEVEL    (5)
#define CAPACITY_MIN   0
#define CAPACITY_MAX 100
#define CAPACITY_FULL 100
#define WORK_INTERVAL_MIN             1
#define WORK_INTERVAL_MAX            60000 /* 60s */
#define WORK_INTERVAL_NOARMAL 10000 /* 10s */
#define WORK_INTERVAL_REACH_FULL 30000 /* 30s */

#define CAP_LOCK_PARA_LEVEL    (2)

#define CAPATICY_DEC_PARA_LEVEL       (2)

#define BASE_DECIMAL (10)
#define CAPACITY_DEC_SAMPLE_NUMS       (12)
#define CAPATICY_DEC_TIMER_INTERVAL  (800) /* time out setting, 0.8 seconds */
#define CAPATICY_DEC_PARA_LEVEL       (2)

/* battery registers and reg offset */
#define BATTERY_REG0	0x0263  // battery Reality data
#define BATTERY_REG1	0x0280
#define BATTERY_REG2	0x0451
#define AC_STATUS_QUERY	0x81
#define BATTERY_DESIGN_FCC_OFFSET1	0xa2
#define BATTERY_DESIGN_FCC_OFFSET2	0xa3
#define BATTERY_VOLT_AVG_OFFSET1	0xa4
#define BATTERY_VOLT_AVG_OFFSET2	0xa5
#define BATTERY_CYCLE_COUNT_OFFSET1	0xaa
#define BATTERY_CYCLE_COUNT_OFFSET2	0xab
#define BATTERY_CAPACITY_OFFSET	0x90
#define BATTERY_VOLTAGE_OFFSET	0x6
#define BATTERY_CURRENT_OFFSET	0x1
#define BATTERY_REMAIN_CAPACITY_OFFSET	0x7
#define BATTERY_FCC_OFFSET	0x8
#define BATTERY_STATUS              0x98
#define BATTERY_TEMPERATURE_OFFSET	0x9
#define BATTERY_HEALTH_OFFSET	0x82
#define BATTERY_EXIST_OFFSET	0x81
#define CHARGE_STATUS          0xE0

#define BATTERY_RMC  0x03
#define CHARGE_MAX_POWER  0x12

#define GET_WAKEUP_CAUSE_ADDR	0x0611
#define SET_LOW_BATTERY_ADDR	0x0612
#define BATT_NAME_LEN           32

#define EC_SMART_CHARGE        2

enum work_interval_para_info {
	WORK_INTERVAL_CAP_MIN = 0,
	WORK_INTERVAL_CAP_MAX,
	WORK_INTERVAL_VALUE,
	WORK_INTERVAL_PARA_TOTAL,
};

struct work_interval_para {
	int cap_min;
	int cap_max;
	int work_interval;
};

struct capacity_dec_para {
	u32 cap_dec_base_decimal;
	u32 cap_dec_sample_nums;
	u32 cap_dec_timer_interval;
};
struct cap_lock_para {
	int cap;
	int level_vol;
};

enum capacity_dec_para_info {
	CAP_DEC_BASE_DECIMAL = 0,
	CAP_DEC_SAMPLE_NUMS,
	CAP_DEC_TIMER_INTERVAL,
	CAP_DEC_PARA_TOTAL,
};

enum wakeup_type_for_battery {
	WAKEUP_S3 = 1,
	WAKEUP_ULSR,
	WAKEUP_S4,
};

struct echub_batt_device_info {
	int bat_cycle_count;
	int bat_voltage;
	int bat_volt_avg;
	int bat_volt_max_design;
	int bat_exist;
	int bat_temperature;
	int bat_health;
	int bat_capacity;
	int bat_capacity_level;
	int bat_technolog;
	int bat_rm;
	int bat_fcc;
	int bat_design_fcc;
	int bci_soc_at_term;
	int bat_current;
	int gpio_int;
	int irq_int;
	unsigned int bat_err;
	bool ac_status_from_ec;
	bool report_ac_status_after_resume;
	int ac_status_gpio;
	u8 ac_online;
	int ac_power;
	int ec_charge_status;
	int charge_status;
	u8 chargedone_stat;
	int power_supply_status;
	u16 monitoring_interval;
	unsigned int capacity;
	unsigned int prev_capacity;
	unsigned int capacity_filter_count;
	unsigned int charge_full_count;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0))
	struct power_supply bat;
	struct power_supply usb;
	struct power_supply ac;
	struct power_supply bk_bat;
#else
	struct power_supply    *bat;
	struct power_supply    *usb;
	struct power_supply    *ac;
	struct power_supply    *wireless;
	struct power_supply    *bk_bat;
#endif
	struct device *dev;
	struct echub_i2c_dev *echub_dev;
	struct notifier_block hmi_event_nb;
	struct notifier_block pm_nb;
	struct delayed_work echub_batt_monitor_work;
	struct delayed_work irq_work;
	struct delayed_work echub_smart_charge_work;
	struct work_interval_para interval_data[WORK_INTERVAL_PARA_LEVEL];
	struct hrtimer capacity_dec_timer;
	unsigned int capacity_dec;
	int capacity_dec_base_decimal;
	int capacity_dec_sample_nums;
	int capacity_dec_timer_interval;
	int capacity_dec_total_level;
	struct capacity_dec_para cap_dec_para[CAPATICY_DEC_PARA_LEVEL];
	unsigned int vth_correct_en;
	struct cap_lock_para vth_correct_data[CAP_LOCK_PARA_LEVEL];
	unsigned int bat_info_type;
	unsigned char low_battery_thres;
	bool sync_low_battery_thres;
	unsigned char charge_strategy;
	char bat_manufactory_name[BATT_NAME_LEN];
	bool ignore_minor_data;
	int turbo_status;
	char wakeup_cause;
	int wakeup_type_for_charger_control;
};

struct echub_batt_device_info *echub_get_batt_di(void);
void echub_capacity_sync_filter(int rep_soc, int round_soc, int base);

#define MAX_CELL_CNT 4
#pragma pack(1)
typedef struct {
    u16 magic;
    u32 power_0;
    u16 temp_max_0;
    u16 temp_min_0;
    u16 temp_max_1;
    u16 temp_min_1;
    u16 vcell_x_0[MAX_CELL_CNT];
    u16 vcell_x_1[MAX_CELL_CNT];
    u16 vcell_min_0;
    u16 vcell_min_1;
    u16 vcell_max_0;
    u16 lcdTime;
    u16 cvt_0;
    u16 cvt_x_1[MAX_CELL_CNT];
    u16 cvt_x_2[MAX_CELL_CNT];
    u16 cvt_max;
    u16 cvt_min;
    u16 cvt_delta_max_1;
    u16 cvt_delta_max_2;
    u16 vcell_x_range[MAX_CELL_CNT];
    u16 vcell_rang_max;
    u16 vcell_rang_delta_max;
    u16 vcell_delta_max;
    u16 temp_delta_max;
    u16 current_min;
    u16 cycle;
    u16 soh;
    u16 fcc;
    u16 designCapacity;
    u16 chargeNumber;
    u16 cell_number_x[MAX_CELL_CNT];
    u32 chgStartTime;
    u32 chgEndTime;
    u16 checkSum;
    u8  reserved[18];
} battery_fault_info;

typedef struct {
    u16 magic;
    u16 power_0_threshold;
    u16 vcell_min_0_threshold;
    u16 vcell_max_0_threshold;
    u16 vcell_min_2_threshold;
    u16 temp_max_0_threshold;
    u16 temp_min_0_threshold;
    u16 temp_max_1_threshold;
    u16 temp_min_1_threshold;
    u16 vcell_min_1_threshold;
    u16 vcell_start_threshold;
    u16 vcell_end_threshold;
    u16 cycle_min_threshold;
    u16 cycle_max_threshold;
    u16 vcell_delta_min_threshold;
    u16 vcell_delta_max_threshold;
    u16 temp_delta_min_threshold;
    u16 temp_delta_max_threshold;
    u16 soh_min_threshold;
    u16 soh_max_threshold;
    u16 current_min_threshold;
    u16 lcd_time_threshold;
    u16 checkSum;
    u8  reserved[18];
} fault_threshold_info;
#pragma pack()

void echub_battery_diagnosis_entry(struct echub_batt_device_info *di);

#endif
