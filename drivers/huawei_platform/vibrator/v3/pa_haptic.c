/*
 * pa_haptic.c
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
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

#include <linux/delay.h>
#include <linux/regmap.h>
#include <linux/module.h>
#include <linux/of_gpio.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <huawei_platform/log/hw_log.h>
#include <securec.h>

#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
#include <linux/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#endif

#include "pa_haptic.h"
#include "haptic_dsp.h"
#include "pahaptic_dmd.h"

#define DEVICE_NAME "pa_haptic"

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG ap_haptic_comm
HWLOG_REGIST();

static int haptic_pa_init_cfg(struct pa_paptic_t *haptic_dev);

static struct vendor_id_map_t vendor_id_map[] = {
	{ TFA9198, 0 },
	{ AW88480, 1 },
	{ YW5815, 2 }
};

static const struct regmap_config pa_i2c_regmap_config = {
	.name = DEVICE_NAME,
	.reg_bits = 8, /* 8 bit addr */
	.val_bits = 16, /* 16 bit value */
	.max_register = 0xFF, /* max 255 regs */
	.cache_type = REGCACHE_NONE, /* disable cache */
};

static int reg_write(struct pa_paptic_t *haptic_dev, const struct pa_haptic_regs_ops_t *reg)
{
	int ret;

	hwlog_info("%s adr = 0x%x, mask = 0x%x, value = 0x%x", __func__, reg->reg_addr, reg->mask, reg->value);
	ret = regmap_update_bits(haptic_dev->regmap, reg->reg_addr, reg->mask, reg->value);
	if (ret < 0) {
		hwlog_err("%s update_bit 0x%x fail, ret = %d", __func__, reg->reg_addr, ret);
		return -EFAULT;
	}
	if (reg->delay != 0)
		usleep_range(reg->delay, reg->delay + DELAY_US_GAP);
	return 0;
}

static int reg_read(struct pa_paptic_t *haptic_dev, const struct pa_haptic_regs_ops_t *reg)
{
	uint32_t read_val = 0;
	int ret;

	ret = regmap_read(haptic_dev->regmap, reg->reg_addr, &read_val);
	if (ret) {
		hwlog_err("%s read 0x%x failed, ret = %d", __func__, reg->reg_addr, ret);
		return ret;
	}
	hwlog_info("%s read addr = 0x%x, val = 0x%x", __func__, reg->reg_addr, read_val);
	return 0;
}

static int reg_rxorw(struct pa_paptic_t *haptic_dev, const struct pa_haptic_regs_ops_t *reg)
{
	uint32_t read_val = 0;
	uint32_t temp_val;
	int ret;

	ret = regmap_read(haptic_dev->regmap, reg->reg_addr, &read_val);
	if (ret) {
		hwlog_err("%s read 0x%x failed, ret = %d", __func__, reg->reg_addr, ret);
		return ret;
	}
	temp_val = reg->mask ^ read_val;
	ret = regmap_write(haptic_dev->regmap, reg->reg_addr, temp_val);
	if (ret < 0) {
		hwlog_err("%s update_bit 0x%x fail, ret = %d", __func__, reg->reg_addr, ret);
		return -EFAULT;
	}
	if (reg->delay != 0)
		usleep_range(reg->delay, reg->delay + DELAY_US_GAP);
	return 0;
}

static int reg_cont_read(struct pa_paptic_t *haptic_dev, const struct pa_haptic_regs_ops_t *reg)
{
	uint32_t read_val = 0;
	int ret;
	uint32_t reg_addr;

	if ((reg->value < reg->reg_addr) || ((reg->value - reg->reg_addr) > REG_CONT_READ_MAX)) {
		hwlog_err("%s addr out of range", __func__);
		return -1;
	}

	for (reg_addr = reg->reg_addr; reg_addr <= reg->value; reg_addr++) {
		ret = regmap_read(haptic_dev->regmap, reg_addr, &read_val);
		if (ret) {
			hwlog_err("%s read 0x%x failed, ret = %d", __func__, reg_addr, ret);
			return ret;
		}
		hwlog_info("%s dump reg-0x%x = 0x%x", __func__, reg_addr, read_val);
	}
	return 0;
}

static int dev_reg_rw(struct pa_paptic_t *haptic_dev, const struct pa_haptic_regs_ops_t *reg)
{
	int ret = 0;

	switch (reg->ops_type) {
	case REG_WRITE:
		ret = reg_write(haptic_dev, reg);
		break;
	case REG_READ:
		ret = reg_read(haptic_dev, reg);
		break;
	case REG_RXORW:
		ret = reg_rxorw(haptic_dev, reg);
		break;
	case REG_CONT_READ:
		ret = reg_cont_read(haptic_dev, reg);
		break;
	default:
		hwlog_err("%s unknown operation type %d", __func__, reg->ops_type);
		break;
	}

	if (ret)
		i2c_err_dmd(haptic_dev);
	return ret;
}

static int dev_regs_rw(struct pa_paptic_t *haptic_dev, const struct pa_haptic_regs_ops_t *regs, uint32_t size)
{
	uint32_t idx;

	for (idx = 0; idx < size; idx++) {
		if (dev_reg_rw(haptic_dev, &regs[idx]))
			return -EFAULT;
	}
	return 0;
}

static void haptic_pa_print_regs_info(struct pa_paptic_t *haptic_dev, uint32_t pa_cmd)
{
	uint32_t idx;

	for (idx = 0; idx < haptic_dev->pa_dev_ops[pa_cmd].regs_nums; idx++)
		hwlog_info("%s, ops_list = 0x%x, 0x%x, 0x%x, 0x%x, 0x%x", __func__,
			haptic_dev->pa_dev_ops[pa_cmd].ops_list[idx].reg_addr,
			haptic_dev->pa_dev_ops[pa_cmd].ops_list[idx].mask,
			haptic_dev->pa_dev_ops[pa_cmd].ops_list[idx].value,
			haptic_dev->pa_dev_ops[pa_cmd].ops_list[idx].delay,
			haptic_dev->pa_dev_ops[pa_cmd].ops_list[idx].ops_type);
}

static void haptic_pa_set_vol_cfg(struct pa_paptic_t *haptic_dev, uint32_t pa_cmd)
{
	if (!haptic_dev)
		return;

	hwlog_info("%s vendor-%u pa_cmd-%u", __func__, haptic_dev->vendor_id, pa_cmd);

	if (haptic_dev->pa_dev_ops[pa_cmd].ops_list == NULL) {
		hwlog_err("%s para err", __func__);
		return;
	}
	dev_regs_rw(haptic_dev, haptic_dev->pa_dev_ops[pa_cmd].ops_list,
		haptic_dev->pa_dev_ops[pa_cmd].regs_nums);
}

static void haptic_pa_regs_dump(struct pa_paptic_t *haptic_dev)
{
	if (!haptic_dev)
		return;

	hwlog_info("%s vendor-%u", __func__, haptic_dev->vendor_id);

	if (haptic_dev->pa_dev_ops[PA_DEV_REGS_DUMP].ops_list == NULL) {
		hwlog_err("%s para err", __func__);
		return;
	}
	dev_regs_rw(haptic_dev, haptic_dev->pa_dev_ops[PA_DEV_REGS_DUMP].ops_list,
		haptic_dev->pa_dev_ops[PA_DEV_REGS_DUMP].regs_nums);
}

static int pa_haptic_do_cfgs_cmd(struct pa_paptic_t *haptic_dev, uint32_t pa_cmd)
{
	int ret = 0;

	switch (pa_cmd) {
	case PA_DEV_INIT:
		ret = haptic_pa_init_cfg(haptic_dev);
		break;
	case PA_DEV_ON:
	case PA_DEV_OFF:
		haptic_pa_print_regs_info(haptic_dev, pa_cmd);
		break;
	case PA_DEV_DEFALUT_VOL:
	case PA_DEV_REDUCE_VOL:
		haptic_pa_set_vol_cfg(haptic_dev, pa_cmd);
		break;
	case PA_DEV_REGS_DUMP:
		haptic_pa_regs_dump(haptic_dev);
		break;
	default:
		break;
	}
	return ret;
}

static int pa_haptic_regs_valid_check(struct pa_haptic_regs_ops_list_t *pa_list)
{
	if (pa_list->pa_cmd == PA_DEV_OPS_BASE || pa_list->pa_cmd >= PA_DEV_OPS_MAX)
		return -EINVAL;
	// check valid cfg size, regs must be 5 * xx, and cannot over 100 arrays
	if (pa_list->regs_nums == 0 || (pa_list->regs_nums > MAX_OPS_REGS))
		return -EINVAL;
	return 0;
}

int pa_haptic_get_dev_cfgs(void __user *argp, struct pa_paptic_t *haptic_dev)
{
	struct pa_haptic_regs_ops_list_t pa_list;
	int ret;

	if (!argp || !haptic_dev)
		return -EINVAL;

	(void)memset_s(&pa_list, sizeof(struct pa_haptic_regs_ops_list_t), 0, sizeof(struct pa_haptic_regs_ops_list_t));
	if (copy_from_user(&pa_list, argp, sizeof(struct pa_haptic_regs_ops_list_t)))
		return -EFAULT;

	hwlog_info("%s get cmd = %u, size = %u", __func__, pa_list.pa_cmd, pa_list.regs_nums);
	if (pa_haptic_regs_valid_check(&pa_list))
		return -EINVAL;
	if (haptic_dev->pa_dev_ops[pa_list.pa_cmd].ops_list) {
		hwlog_err("%s cfg info alreay requested, return", __func__);
		return 0;
	}
	haptic_dev->pa_dev_ops[pa_list.pa_cmd].regs_nums = pa_list.regs_nums;
	haptic_dev->pa_dev_ops[pa_list.pa_cmd].pa_cmd = pa_list.pa_cmd;
	hwlog_info("%s get pa ops nums %u", __func__, haptic_dev->pa_dev_ops[pa_list.pa_cmd].regs_nums);
	haptic_dev->pa_dev_ops[pa_list.pa_cmd].ops_list =
		kzalloc(pa_list.regs_nums * sizeof(uint32_t) * SIG_REG_OPS_NUM, GFP_KERNEL);
	if (!haptic_dev->pa_dev_ops[pa_list.pa_cmd].ops_list) {
		hwlog_err("%s malloc info error", __func__);
		return -ENOMEM;
	}
	if (copy_from_user(haptic_dev->pa_dev_ops[pa_list.pa_cmd].ops_list,
		(void __user *)pa_list.ops_list, pa_list.regs_nums * sizeof(uint32_t) * SIG_REG_OPS_NUM)) {
		hwlog_err("%s copy_from_user error", __func__);
		kfree(haptic_dev->pa_dev_ops[pa_list.pa_cmd].ops_list);
		haptic_dev->pa_dev_ops[pa_list.pa_cmd].ops_list = NULL;
		return -EINVAL;
	}
	if (pa_list.pa_cmd == PA_DEV_REGS_DUMP)
		return 0;

	ret = pa_haptic_do_cfgs_cmd(haptic_dev, pa_list.pa_cmd);
	return ret;
}

static int pa_haptic_gpio_request(struct pa_paptic_t *haptic_dev)
{
	int ret;

	if (!gpio_is_valid(haptic_dev->reset_pin)) {
		hwlog_err("%s gpio-%d is invalid", __func__, haptic_dev->reset_pin);
		return -EFAULT;
	}

	ret = devm_gpio_request_one(haptic_dev->dev, haptic_dev->reset_pin, GPIOF_OUT_INIT_HIGH, "haptic_en");
	if (ret) {
		hwlog_err("haptic_en gpio request failed");
		return -EFAULT;
	}

	gpio_set_value_cansleep(haptic_dev->reset_pin, 1);
	usleep_range(3500, 4000);

	if (!gpio_is_valid(haptic_dev->irq_pin)) {
		hwlog_err("%s irq_gpio-%d is invalid", __func__, haptic_dev->irq_pin);
		return 0;
	}

	ret = devm_gpio_request_one(haptic_dev->dev, haptic_dev->irq_pin, GPIOF_OUT_INIT_HIGH, "haptic_int");
	if (ret)
		hwlog_info("haptic_int request failed");

	return 0;
}

uint32_t vendor_id_convert_to_dsp(uint32_t vendor_id)
{
	for (size_t i = 0; i < ARRAY_SIZE(vendor_id_map); i++) {
		if (vendor_id_map[i].vendor_id == vendor_id)
			return vendor_id_map[i].dsp_id;
	}
	return 0; // if connot get, return 0
}

static int pa_haptic_read_chipid(struct pa_paptic_t *haptic_dev)
{
	int ret;
	unsigned int chipid = 0;

	ret = pa_haptic_gpio_request(haptic_dev);
	if (ret) {
		hwlog_err("pa_haptic_gpio_request failed, ret = %d", ret);
		return ret;
	}
	ret = regmap_read(haptic_dev->regmap, (uint32_t)haptic_dev->who_am_i_addr, &chipid);
	if (ret) {
		hwlog_err("read chipid failed, ret = %d", ret);
		return ret;
	}
	if (chipid != haptic_dev->who_am_i_val) {
		hwlog_err("%s dectect chip fail, chip_id = 0x%x", __func__, chipid);
		return -EINVAL;
	}
	hwlog_info("%s vendor_id = %u detect succ", __func__, haptic_dev->vendor_id);
	return 0;
}

static void pa_haptic_parse_irq_parameters(struct pa_paptic_t *haptic_dev)
{
	int ret;
	struct device_node *node = haptic_dev->i2c->dev.of_node;

	ret = of_property_read_u32(node, "irq_para_list_len", &haptic_dev->irq_para_list_len);
	if (ret) {
		hwlog_err("%s get irq_para_list_len fail", __func__);
		return;
	}
	hwlog_info("%s irq_para_list_len = %d", __func__, haptic_dev->irq_para_list_len);

	haptic_dev->pa_dmd_info = (struct pa_dmd_info_t *)kzalloc(haptic_dev->irq_para_list_len *
		sizeof(uint32_t), GFP_KERNEL);
	if (haptic_dev->pa_dmd_info == NULL) {
		hwlog_err("%s failed to allocate strength haptic_dev->pa_dmd_info cfg\n", __func__);
		return;
	}

	ret = of_property_read_u32_array(node, "irq_para_list", (uint32_t *)haptic_dev->pa_dmd_info,
		haptic_dev->irq_para_list_len);
	if (ret) {
		hwlog_err("%s get irq_para_list fail", __func__);
		goto free_pa_dmd_info;
	}

	haptic_dev->dmd_event_size = haptic_dev->irq_para_list_len / IRQ_PARAMS_PER_EVENT;

	for (uint32_t i = 0; i < haptic_dev->dmd_event_size; i++) {
		hwlog_info("pa_dmd_info[%d]: irq_addr=0x%02x, irq_bit_flag=0x%x, irq_event=%u\n",
			i, haptic_dev->pa_dmd_info[i].irq_addr, haptic_dev->pa_dmd_info[i].irq_bit_flag,
			haptic_dev->pa_dmd_info[i].irq_event);
	}
	return;
free_pa_dmd_info:
	kfree(haptic_dev->pa_dmd_info);
	haptic_dev->pa_dmd_info = NULL;
}

static void pa_haptic_parse_si_bat_parameters(struct pa_paptic_t *haptic_dev)
{
	int ret;
	int i;
	struct device_node *node = haptic_dev->i2c->dev.of_node;

	ret = of_property_read_u32_array(node, "si_bat_cfg",
			haptic_dev->si_bat_cfg, ARRAY_SIZE(haptic_dev->si_bat_cfg));
	if (ret) {
		hwlog_err("%s get si_bat_cfg fail", __func__);
		return;
	}

	if (haptic_dev->si_bat_cfg[IS_TEMP_BELOW_ZERO])
		haptic_dev->si_bat_cfg[SPECIFIED_BAT_TEMP] = -haptic_dev->si_bat_cfg[SPECIFIED_BAT_TEMP];

	for (i = 0; i < SIL_BAT_CFG_SIZE; i++)
		hwlog_info("%s si_bat_cfg[%d] = %d", __func__, i, haptic_dev->si_bat_cfg[i]);
}

static int pa_haptic_parse_dts_para(struct pa_paptic_t *haptic_dev)
{
	int ret;
	struct device_node *node = haptic_dev->i2c->dev.of_node;

	if (!node) {
		hwlog_err("%s get node fail", __func__);
		return -EINVAL;
	}
	ret = of_property_read_u32(node, "i2c_real_addr", &haptic_dev->real_i2c_addr);
	if (ret != 0)
		hwlog_info("i2c_real_addr is not found");
	if (haptic_dev->real_i2c_addr != 0) {
		hwlog_info("i2c_real_addr is %d", haptic_dev->real_i2c_addr);
		haptic_dev->i2c->addr = (uint16_t) haptic_dev->real_i2c_addr;
	}
	hwlog_info("%s get haptic dev addr = 0x%x", __func__, haptic_dev->i2c->addr);
	haptic_dev->reset_pin = of_get_named_gpio(node, "reset_gpio", 0);
	haptic_dev->irq_pin = of_get_named_gpio(node, "irq_gpio", 0);
	hwlog_info("%s get reset_pin = %d irq_pin = %d", __func__, haptic_dev->reset_pin, haptic_dev->irq_pin);

	ret = of_property_read_u32(node, "vendor_id", &haptic_dev->vendor_id);
	if (ret) {
		hwlog_err("%s get vendor_id fail", __func__);
		return -EINVAL;
	}
	ret = of_property_read_u32(node, "who_am_i_addr", &haptic_dev->who_am_i_addr);
	if (ret) {
		hwlog_err("%s get who_am_i_addr fail", __func__);
		return -EINVAL;
	}
	ret = of_property_read_u32(node, "who_am_i_val", &haptic_dev->who_am_i_val);
	if (ret) {
		hwlog_err("%s get who_am_i_val fail", __func__);
		return -EINVAL;
	}
	hwlog_info("%s vendor_id = %u, who_am_i addr = 0x%x, val = 0x%x", __func__,
		haptic_dev->vendor_id, haptic_dev->who_am_i_addr, haptic_dev->who_am_i_val);

	ret = of_property_read_u32(node, "r_scale", &haptic_dev->r_scale);
	if (ret)
		hwlog_err("%s get r_scale fail", __func__);
	hwlog_info("%s r_scale = %u", __func__, haptic_dev->r_scale);

	pa_haptic_parse_irq_parameters(haptic_dev);
	pa_haptic_parse_si_bat_parameters(haptic_dev);

	return ret;
}

static uint32_t pa_haptic_get_haptic_id(struct i2c_client *i2c)
{
	int ret = 0;
	uint32_t haptic_id = 0;
	struct device_node *node = NULL;

	node = i2c->dev.of_node;
	ret = of_property_read_u32(node, "haptic_id", &haptic_id);
	if (ret) {
		hwlog_err("%s get haptic id fail", __func__);
		return MAX_HAPTIC_NUM;
	} else {
		hwlog_info("%s get haptic id = %u", __func__, haptic_id);
	}
	return haptic_id;
}

static void get_irq_state(struct pa_paptic_t *haptic_dev)
{
	unsigned int reg_val = 0;
	uint32_t i;
	int ret;
	uint32_t last_irq_addr = 0xfff;

	if (!haptic_dev || !haptic_dev->pa_dmd_info) {
		hwlog_err("haptic_dev or pa_dmd_info is null");
		return;
	}
	__pm_wakeup_event(haptic_dev->ws, HAPTIC_WAKE_LOCK_GAP);
	for (i = 0; i < haptic_dev->dmd_event_size; i++) {
		if (haptic_dev->pa_dmd_info[i].irq_addr != last_irq_addr) {
			ret = regmap_read(haptic_dev->regmap, haptic_dev->pa_dmd_info[i].irq_addr, &reg_val);
			if (ret) {
				hwlog_err("%s read 0x%x failed, ret = %d", __func__, haptic_dev->pa_dmd_info[i].irq_addr, ret);
				i2c_err_dmd(haptic_dev);
				return;
			}
			hwlog_info("%s reg = 0x%x  reg_val = 0x%x", __func__, haptic_dev->pa_dmd_info[i].irq_addr, reg_val);
			last_irq_addr = haptic_dev->pa_dmd_info[i].irq_addr;
		}
		if (reg_val & haptic_dev->pa_dmd_info[i].irq_bit_flag)
			pa_haptic_dmd_work(haptic_dev->pa_dmd_info[i].irq_event);
	}
	pa_haptic_do_cfgs_cmd(haptic_dev, PA_DEV_REGS_DUMP);
	pa_haptic_do_cfgs_cmd(haptic_dev, PA_DEV_INIT);
}

static irqreturn_t irq_handle(int irq, void *data)
{
	struct pa_paptic_t *haptic_dev = NULL;

	if (!data)
		return IRQ_HANDLED;
	haptic_dev = data;

	hwlog_info("irq process work");
	get_irq_state(haptic_dev);
	return IRQ_HANDLED;
}

static int irq_config(struct device *dev, struct pa_paptic_t *haptic_dev)
{
	int ret;
	int irq_flags;

	if (!dev || !haptic_dev) {
		hwlog_err("dev or haptic_dev is null");
		return -EINVAL;
	}

	if (!gpio_is_valid(haptic_dev->irq_pin)) {
		hwlog_info("skipping IRQ registration");
		return 0;
	}

	irq_flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
	gpiod_direction_input(gpio_to_desc(haptic_dev->irq_pin));
	ret = devm_request_threaded_irq(dev, gpio_to_irq(haptic_dev->irq_pin),
		NULL, irq_handle, irq_flags, "haptic_dev", haptic_dev);
	if (ret != 0)
		hwlog_err("failed to request IRQ %d: %d", gpio_to_irq(haptic_dev->irq_pin), ret);

	hwlog_info("request IRQ succ");
	return 0;
}

static int pa_haptic_init(struct pa_paptic_t *haptic_dev)
{
	int ret;

	ret = pa_haptic_parse_dts_para(haptic_dev);
	if (ret) {
		hwlog_err("%s parse dts para fail", __func__);
		return ret;
	}
	haptic_dev->regmap = devm_regmap_init_i2c(haptic_dev->i2c, &pa_i2c_regmap_config);
	if (!haptic_dev->regmap) {
		hwlog_err("haptic regmap init failed");
		return -EFAULT;
	}

	ret = pa_haptic_read_chipid(haptic_dev);
	if (ret)
		return -EFAULT;

	ret = irq_config(haptic_dev->dev, haptic_dev);
	if (ret != 0)
		return -EFAULT;
	pa_haptic_dsm_register();

	haptic_dev->ws = wakeup_source_register(haptic_dev->dev, "pa_haptic");
	if (!haptic_dev->ws) {
		hwlog_err("wakeup_source_register failed");
		return -EFAULT;
	}

	return ret;
}

#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
static void set_bst_vol(struct pa_paptic_t *haptic_dev, bool force_uper_vol)
{
	int bat_power = 0;
	int bat_temp = 0;
	bool is_need_set_reduce_vol = false;
	static bool prev_is_need_set_reduce_vol = false;

	power_supply_get_int_property_value("Battery", POWER_SUPPLY_PROP_CAPACITY, &bat_power);
	power_supply_get_int_property_value("Battery", POWER_SUPPLY_PROP_TEMP, &bat_temp);
	bat_temp /= 10; // The temperature read is ten times the actual temperature
	hwlog_info("bat_power = %d bat_temp = %d!", bat_power, bat_temp);

	is_need_set_reduce_vol = (bat_power <= haptic_dev->si_bat_cfg[SPECIFIED_BAT_POWER]) ||
		(bat_temp <= haptic_dev->si_bat_cfg[SPECIFIED_BAT_TEMP]);

	if (force_uper_vol) {
		if (!prev_is_need_set_reduce_vol)
			return;
		haptic_pa_set_vol_cfg(haptic_dev, PA_DEV_DEFALUT_VOL);
		prev_is_need_set_reduce_vol = false;
		return;
	}
	if (is_need_set_reduce_vol != prev_is_need_set_reduce_vol) {
		haptic_pa_set_vol_cfg(haptic_dev, is_need_set_reduce_vol ? PA_DEV_REDUCE_VOL : PA_DEV_DEFALUT_VOL);
		prev_is_need_set_reduce_vol = is_need_set_reduce_vol;
	}
}
#endif

void haptic_pa_set_bst_cfg(struct pa_paptic_t *haptic_dev, bool force_uper_vol)
{
	if (!haptic_dev) {
		hwlog_err("haptic_dev is null");
		return;
	}
#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
	set_bst_vol(haptic_dev, force_uper_vol);
#endif
}

int haptic_pa_power_on(struct pa_paptic_t *haptic_dev, bool on)
{
	int ret;
	uint32_t cmd;

	if (!haptic_dev)
		return -EFAULT;

	hwlog_info("%s ic-%u state = %u", __func__, haptic_dev->vendor_id, on);

#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
	if (haptic_dev->si_bat_cfg[IS_SI_BAT] && on)
		haptic_pa_set_bst_cfg(haptic_dev, false);
#endif

	if (haptic_dev->power_status == on) {
		hwlog_info("%s power status not changed, do not reconfig", __func__);
		return ret;
	}
	haptic_dev->power_status = on;
	// pa ic power on/off
	cmd = on ? PA_DEV_ON : PA_DEV_OFF;
	if (haptic_dev->pa_dev_ops[cmd].ops_list == NULL) {
		hwlog_info("%s do not need power set", __func__);
		return 0;
	}
	ret = dev_regs_rw(haptic_dev, haptic_dev->pa_dev_ops[cmd].ops_list,
		haptic_dev->pa_dev_ops[cmd].regs_nums);
	return ret;
}

static void pa9198_regs_dump(struct pa_paptic_t *haptic_dev)
{
	uint8_t idx;
	int ret = 0;
	uint32_t read_val = 0;
	uint32_t pa9198_regs[] = { 0x00, 0x02, 0x03, 0x08, 0x0a, 0x12, 0x13, 0x14, 0x15, 0x16 };

	for (idx = 0; idx < ARRAY_SIZE(pa9198_regs); idx++) {
		ret = regmap_read(haptic_dev->regmap, pa9198_regs[idx], &read_val);
		if (ret < 0) {
			hwlog_err("%s read reg 0x%x fail", __func__, pa9198_regs[idx]);
			return;
		} else {
			hwlog_info("%s dump reg-0x%x = 0x%x", __func__, pa9198_regs[idx], read_val);
		}
	}
}

void haptic_pa_dump_data(struct pa_paptic_t *haptic_dev)
{
	int ret;
	uint32_t idx;
	uint32_t read_val = 0;

	if (!haptic_dev)
		return;
	if (haptic_dev->pa_dev_ops[PA_DEV_INIT].ops_list == NULL) {
		hwlog_err("%s para err", __func__);
		return;
	}

	for (idx = 0; idx < haptic_dev->pa_dev_ops[PA_DEV_INIT].regs_nums; idx++) {
		ret = regmap_read(haptic_dev->regmap, haptic_dev->pa_dev_ops[PA_DEV_INIT].ops_list[idx].reg_addr, &read_val);
		if (ret < 0) {
			hwlog_err("%s read reg fail", __func__);
			return;
		} 
		hwlog_info("%s dump reg-0x%x = 0x%x", __func__,
			haptic_dev->pa_dev_ops[PA_DEV_INIT].ops_list[idx].reg_addr, read_val);
	}
}

static int haptic_pa_init_cfg(struct pa_paptic_t *haptic_dev)
{
	int ret;

	if (!haptic_dev)
		return -EFAULT;

	// pa ic config init
	hwlog_info("%s vendor-%u", __func__, haptic_dev->vendor_id);
	if (haptic_dev->pa_dev_ops[PA_DEV_INIT].ops_list == NULL) {
		hwlog_err("%s para err", __func__);
		return -EINVAL;
	}
	ret = dev_regs_rw(haptic_dev, haptic_dev->pa_dev_ops[PA_DEV_INIT].ops_list,
		haptic_dev->pa_dev_ops[PA_DEV_INIT].regs_nums);
	return ret;
}

int haptic_i2c_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
	int ret;
	uint32_t haptic_id = 0;
	struct pa_paptic_t *haptic_dev = NULL;
	struct dsp_haptic_t *haptic_dsp = NULL;

	hwlog_info("enter");
	if (!i2c || !id) {
		hwlog_info("%s get invalid argument", __func__);
		return -EINVAL;
	}
	if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_I2C)) {
		hwlog_err("%s: i2c check functionality error\n", __func__);
		return -ENODEV;
	}
	haptic_id = pa_haptic_get_haptic_id(i2c);
	if (haptic_id >= MAX_HAPTIC_NUM) {
		hwlog_err("%s get haptic id fail", __func__);
		return -EINVAL;
	}
	haptic_dsp = get_dsp_haptic();
	if (haptic_dsp == NULL) {
		hwlog_err("%s get haptic dsp fail", __func__);
		return -EINVAL;
	}
	if (haptic_dsp->pa_haptic[haptic_id] != NULL) {
		hwlog_err("%s pa_paptic[%d] dev already exist", __func__, haptic_id);
		return -EINVAL;
	}
	haptic_dev = devm_kzalloc(&i2c->dev, sizeof(*haptic_dev), GFP_KERNEL);
	if (!haptic_dev)
		return -ENOMEM;

	haptic_dev->probe_succ = false;
	haptic_dev->dev = &i2c->dev;
	haptic_dev->i2c = i2c;
	i2c_set_clientdata(i2c, haptic_dev);
	dev_set_drvdata(&i2c->dev, haptic_dev);

	ret = pa_haptic_init(haptic_dev);
	if (ret) {
		hwlog_info("pa_haptic_init init failed");
		return ret;
	}
	haptic_dev->haptic_id = haptic_id;
	haptic_dsp->pa_haptic[haptic_id] = haptic_dev;
	haptic_dev->probe_succ = true;
	hwlog_info("probe completed successfully!");
	return 0;
}

int haptic_i2c_remove(struct i2c_client *i2c)
{
	struct pa_paptic_t *haptic = i2c_get_clientdata(i2c);

	if (!haptic)
		return -EFAULT;

	kfree(haptic->pa_dmd_info);
	hwlog_info("%s removed", __func__);
	return 0;
}

int haptic_i2c_suspend(struct device *dev)
{
	struct pa_paptic_t *haptic = dev_get_drvdata(dev);

	if (!haptic)
		return -EFAULT;

	hwlog_info(" enter");
	return 0;
}

int haptic_i2c_resume(struct device *dev __maybe_unused)
{
	return 0;
}

void haptic_i2c_shutdown(struct i2c_client *i2c)
{
}
