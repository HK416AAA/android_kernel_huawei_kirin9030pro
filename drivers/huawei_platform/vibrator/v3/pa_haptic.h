/*
 * pa_haptic.h
 *
 * common define for pa haptic drvier
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
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

#ifndef __PA_HAPTIC_H__
#define __PA_HAPTIC_H__

#include <linux/device.h>
#include <linux/i2c.h>
#include <linux/regmap.h>
#include <linux/types.h>
#include <linux/uaccess.h>

#define TFA9198                         101
#define AW88480                         201
#define YW5815                          301

#define REG_READ                        0x05
#define REG_RXORW                       0x04
#define REG_WRITE                       0x00
#define REG_CONT_READ                   0x10
#define SIG_REG_OPS_NUM                 5
#define MAX_OPS_REGS                    100
#define REG_CONT_READ_MAX               255

#define REG_UPDATE_BITS                 0x03
#define DELAY_US_GAP                    500
#define HAPTIC_WAKE_LOCK_GAP            300

#define IRQ_PARAMS_PER_EVENT            3
#define IRQ_SYSINT_OCPS                 1
#define IRQ_SYSINT_UVPS                 3
#define IRQ_SYSINT_OTPS                 5
#define IRQ_SYSINT_PORS                 7

// silicon battery config
enum {
	IS_SI_BAT            = 0,
	IS_TEMP_BELOW_ZERO   = 1,
	SPECIFIED_BAT_TEMP   = 2,
	SPECIFIED_BAT_POWER  = 3,
	SIL_BAT_CFG_SIZE,
};

#ifndef ARRAY_SIZE
	#define ARRAY_SIZE(x) ((sizeof(x)) / (sizeof((x)[0])))
#endif
enum {
	PA_DEV_OPS_BASE     = 0,
	PA_DEV_INIT         = 0x01,
	PA_DEV_ON           = 0x02,
	PA_DEV_OFF          = 0x03,
	PA_DEV_REDUCE_VOL   = 0x04,
	PA_DEV_DEFALUT_VOL  = 0x05,
	PA_DEV_REGS_DUMP    = 0x06,
	PA_DEV_OPS_MAX,
};

enum {
	PA_CMD = 0,
	CFG_SIZE = 1,
};

struct vendor_id_map_t {
	uint32_t vendor_id;
	uint32_t dsp_id;
};

struct pa_haptic_regs_ops_t {
	uint32_t reg_addr;
	uint32_t mask;
	uint32_t value;
	uint32_t delay;
	uint32_t ops_type;
};

struct pa_haptic_regs_ops_list_t {
	uint32_t pa_cmd;
	uint32_t regs_nums;
	struct pa_haptic_regs_ops_t *ops_list;
};

struct pa_dmd_info_t {
	uint32_t irq_addr;
	uint32_t irq_bit_flag;
	uint32_t irq_event;
};

struct pa_paptic_t {
	struct device *dev;
	struct i2c_client *i2c;
	struct regmap *regmap;
	struct wakeup_source *ws;
	unsigned char wk_lock_flag;
	struct pa_dmd_info_t *pa_dmd_info;
	uint32_t haptic_id;
	uint32_t vendor_id;
	int reset_pin;
	int irq_pin;
	uint32_t who_am_i_addr;
	uint32_t who_am_i_val;
	uint32_t real_i2c_addr;
	uint32_t irq_para_list_len;
	uint32_t dmd_event_size;
	int haptic_f0_val;
	int cali_rst;
	uint32_t new_re;
	uint32_t charge_calib_f0;
	uint32_t r_scale;
	uint16_t i2c_err_cnt;
	uint8_t i2c_dmd_report_cnt;
	bool power_status;
	struct pa_haptic_regs_ops_list_t pa_dev_ops[PA_DEV_OPS_MAX];
	bool probe_succ;
	int si_bat_cfg[SIL_BAT_CFG_SIZE];
};

/* define for pa drv SR & add & remove */
int haptic_i2c_suspend(struct device *dev);
int haptic_i2c_resume(struct device *dev);
int haptic_i2c_probe(struct i2c_client *i2c, const struct i2c_device_id *id);
int haptic_i2c_remove(struct i2c_client *i2c);
void haptic_i2c_shutdown(struct i2c_client *i2c);

/* define for pa driver ctrl */
int haptic_pa_power_on(struct pa_paptic_t *haptic_dev, bool on);
void haptic_pa_dump_data(struct pa_paptic_t *haptic_dev);
int pa_haptic_get_dev_cfgs(void __user *argp, struct pa_paptic_t *haptic_dev);
uint32_t vendor_id_convert_to_dsp(uint32_t vendor_id);
void haptic_pa_set_bst_cfg(struct pa_paptic_t *haptic_dev, bool force_uper_vol);

#endif
