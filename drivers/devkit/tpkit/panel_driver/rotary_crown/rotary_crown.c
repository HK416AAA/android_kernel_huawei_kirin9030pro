/*
 * Rotary Crown driver
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

#include "rotary_crown.h"

#include <huawei_platform/log/log_jank.h>
#include <linux/pinctrl/pinctrl-state.h>
#include <linux/platform_device.h>
#include <linux/timer.h>
#include <linux/time.h>
#include <linux/mtd/nve_ap_kernel_interface.h>


#include "securec.h"
#ifdef CONFIG_LCD_KIT_HYBRID
#include "huawei_ts_kit_hybrid_core.h"
#endif

static struct timer_list g_crown_check_timer;
static struct work_struct g_crown_check_work;
static struct mutex g_work_lock;
/* global values */
static bool g_powerinit = false;
struct rotary_crown_data *g_rotary_crown_pdata;
static struct workqueue_struct *rotary_crown_notifier_wq = NULL;
static int rotary_crown_read_res_from_nv(uint8_t *res);
static int32_t mt3501_read_data(uint8_t reg_addr, uint8_t *buf, uint16_t buf_len);
static int32_t mt3501_write_data(uint8_t reg_addr, uint8_t *buf, uint16_t buflen);

static int mt3501_rotary_crown_chip_init(uint8_t x_res);
static int mt3501_rotary_crown_read_motion(int16_t *dx);
static int mt3501_rc_run_mode_set(bool enable);
static void mt3501_clear_interrupt(void);
static int32_t mt3501_reset_interrupt(void);
static void crown_check_reset_irq(void);
static int32_t mt3501_disable_write_protect(void);
static int32_t mt3501_enable_write_protect(void);

static int32_t hx3509_write_data(uint8_t reg_addr, uint8_t *buf, uint16_t buflen);
static int32_t hx3509_read_data(uint8_t reg_addr, uint8_t *buf, uint16_t buf_len);
static int hx3509_read_motion(int16_t *dx);
static void hx3509_clear_interrupt(void);
static int hx3509_run_mode_set(bool enable);
static int32_t hx3509_rotary_crown_chip_init(void);

#ifdef RC_FACTORY_MODE
static int mt3501_rc_calibrate_enter(void);
static int mt3501_rc_calibrate_test_exit(void);
static int mt3501_rc_nv_test_enter(void);
static int hx3509_enter_calib(void);
static int hx3509_exit_calib(void);
static int hx3509_rc_nv_test_enter(void);
#endif

static int rc_i2c_read(uint8_t *reg_addr, uint16_t reg_len, uint8_t *buf, uint16_t len)
{
	int count = 0;
	int ret;
	int msg_len;
	struct i2c_msg *msg_addr = NULL;
	struct i2c_msg xfer[ROTARY_I2C_MSG_LEN];
	if (!g_rotary_crown_pdata || !g_rotary_crown_pdata->client) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	struct i2c_client *client = g_rotary_crown_pdata->client;

	if (g_rotary_crown_pdata->is_one_byte) {
		/* Read data */
		xfer[ROTARY_I2C_MSG_INDEX0].addr = client->addr;
		xfer[ROTARY_I2C_MSG_INDEX0].flags = I2C_M_RD;
		xfer[ROTARY_I2C_MSG_INDEX0].len = len;
		xfer[ROTARY_I2C_MSG_INDEX0].buf = buf;
		do {
			ret = i2c_transfer(client->adapter, xfer,
				ROTARY_I2C_MSG_INDEX1);
			if (ret == ROTARY_I2C_MSG_INDEX1)
				return NO_ERR;

			msleep(I2C_WAIT_TIME);
		} while (++count < I2C_RW_TRIES);
	} else {
		/* register addr */
		xfer[ROTARY_I2C_MSG_INDEX0].addr = client->addr;
		xfer[ROTARY_I2C_MSG_INDEX0].flags = 0;
		xfer[ROTARY_I2C_MSG_INDEX0].len = reg_len;
		xfer[ROTARY_I2C_MSG_INDEX0].buf = reg_addr;

		/* Read data */
		xfer[ROTARY_I2C_MSG_INDEX1].addr = client->addr;
		xfer[ROTARY_I2C_MSG_INDEX1].flags = I2C_M_RD;
		xfer[ROTARY_I2C_MSG_INDEX1].len = len;
		xfer[ROTARY_I2C_MSG_INDEX1].buf = buf;

		if (reg_len > 0) {
			msg_len = ROTARY_I2C_MSG_LEN;
			msg_addr = &xfer[ROTARY_I2C_MSG_INDEX0];
		} else {
			msg_len = ROTARY_I2C_MSG_INDEX1;
			msg_addr = &xfer[ROTARY_I2C_MSG_INDEX1];
		}

		do {
			ret = i2c_transfer(client->adapter, msg_addr, msg_len);
			if (ret == msg_len)
				return NO_ERR;

			msleep(I2C_WAIT_TIME);
		} while (++count < I2C_RW_TRIES);
	}

	rc_err("%s: failed\n", __func__);
	return -EIO;
}

static int rc_i2c_write(uint8_t *buf, uint16_t length)
{
	int count = 0;
	int ret;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	do {
		ret = i2c_master_send(g_rotary_crown_pdata->client,
			(const char *) buf, length);
		if (ret == length)
			return NO_ERR;

		msleep(I2C_WAIT_TIME);
	} while (++count < I2C_RW_TRIES);

	rc_err("%s: failed", __func__);
	return -EIO;
}

static int rotary_crown_write_reg(uint8_t addr, uint8_t value)
{
	int ret;
	uint8_t cmd[ROTARY_REG_WRITE_LEN] = {0};

	// write reg
	cmd[ROTARY_I2C_MSG_INDEX0] = addr;
	cmd[ROTARY_I2C_MSG_INDEX1] = value;

	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	// soft reset do not give ack back
	if ((addr == PA_DEVICE_CONTROL) && (value == PA_CHIP_RESET)) {
		ret = i2c_master_send(g_rotary_crown_pdata->client,
			(const char *)cmd, ROTARY_REG_WRITE_LEN);
		rc_info("%s:soft reset send", __func__);
		return NO_ERR;
	}

	ret = rc_i2c_write(cmd, ROTARY_REG_WRITE_LEN);
	if (ret != NO_ERR)
		rc_err("set value(0x%02x) to reg(0x%02x) failed", value, addr);

	return ret;
}

static int rotary_crown_parse_dts(void)
{
	struct device_node *np = NULL;
	int ret;
	uint32_t value = 0;
	uint32_t nv_number = 0;

	rc_debug("%s enter\n", __func__);
	if (!g_rotary_crown_pdata || !g_rotary_crown_pdata->dev) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	np = g_rotary_crown_pdata->dev->of_node;
	g_rotary_crown_pdata->irq_gpio = of_get_named_gpio(np, "irq_gpio", 0);
	if (!gpio_is_valid(g_rotary_crown_pdata->irq_gpio)) {
		rc_err("%s:irq_gpio is not valid !\n", __func__);
		return -EINVAL;
	}

	rc_debug("%s,irq_gpio=%d\n", __func__, g_rotary_crown_pdata->irq_gpio);

	ret = of_property_read_u32(np, ROTARY_CROWN_NV_NUMBER, &nv_number);
	if (ret) {
		rc_err("get nv_number failed\n");
		return -EINVAL;
	}
	g_rotary_crown_pdata->nv_number = nv_number;
	rc_debug("%s,nv_number=%d\n", __func__, g_rotary_crown_pdata->nv_number);

	// i2c one byte or not
	ret = of_property_read_u32(np, ROTARY_I2C_TYPE, &value);
	if (ret) {
		g_rotary_crown_pdata->is_one_byte = false;
		rc_err("get is_one_btye failed\n");
	} else {
		g_rotary_crown_pdata->is_one_byte = value ? true : false;
	}
	rc_debug("%s,one byte=%d\n", __func__, g_rotary_crown_pdata->is_one_byte);

	return NO_ERR;
}

static int rotary_crown_pinctrl_init(void)
{
	int ret;

	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}

	g_rotary_crown_pdata->rc_pinctrl =
		devm_pinctrl_get(g_rotary_crown_pdata->dev);
	if (IS_ERR(g_rotary_crown_pdata->rc_pinctrl)) {
		rc_err("%s:failed to devm pinctrl get\n", __func__);
		ret = -EINVAL;
		return ret;
	}

	do {
		g_rotary_crown_pdata->pinctrl_state_active =
			pinctrl_lookup_state(g_rotary_crown_pdata->rc_pinctrl,
				PINCTRL_STATE_DEFAULT);
		if (IS_ERR(g_rotary_crown_pdata->pinctrl_state_active)) {
			rc_err("%s:failed to lookup state active\n",
				__func__);
			ret = -EINVAL;
			break;
		}

		g_rotary_crown_pdata->pinctrl_state_suspend =
			pinctrl_lookup_state(g_rotary_crown_pdata->rc_pinctrl,
				PINCTRL_STATE_IDLE);
		if (IS_ERR(g_rotary_crown_pdata->pinctrl_state_suspend)) {
			rc_err("%s:failed to lookup suspend state\n",
				__func__);
			ret = -EINVAL;
			break;
		}

		/*
		 * Pinctrl handle is optional. If pinctrl handle
		 * is found, let pins to be configured in active state.
		 * If not found continue further without error.
		 */
		ret = pinctrl_select_state(g_rotary_crown_pdata->rc_pinctrl,
			g_rotary_crown_pdata->pinctrl_state_active);
		if (ret) {
			rc_err("%s:failed to set pinctr active\n",
				__func__);
			ret = -EINVAL;
			break;
		}

		return NO_ERR;
	} while (0);

	devm_pinctrl_put(g_rotary_crown_pdata->rc_pinctrl);
	return ret;
}

static int rotary_crown_check_chip_id(void)
{
	uint8_t addr = PA_PRODUCT_ID1;
	uint8_t value = 0;
	int ret;

	rc_debug("%s:called\n", __func__);
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	g_rotary_crown_pdata->client->addr = ROTARY_I2C_ADDR_1;

	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN,
		&value, ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR) {
		g_rotary_crown_pdata->client->addr = ROTARY_I2C_ADDR_2;
		ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN,
				&value, ROTARY_REG_VALUE_LEN);
		if (ret != NO_ERR) {
			rc_err("%s: call rc_i2c_read failed", __func__);
			return ret;
		}
	}

	rc_debug("%s: chip id(0x%02x)\n", __func__, value);
	if (value == PA_DEFAULT_CHIP_ID1) {
		g_rotary_crown_pdata->chip_id = CR_PAT9126;
		return NO_ERR;
	} else if (value == MT3501_PID1) {
		g_rotary_crown_pdata->chip_id = CR_MT3501;
		return NO_ERR;
	} else if (value == HX3509_PID1) {
		g_rotary_crown_pdata->chip_id = CR_HX3509;
		return NO_ERR;
	} else {
		rc_err("%s: failed to check chip id\n", __func__);
		return -EINVAL;
	}

}

static void rotary_crown_clear_interrupt(void)
{
	int ret;
	uint8_t addr;
	uint8_t value;

	addr = PA_MOTION_STATUS;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN, &value,
		ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR)
		rc_err("%s: read motion status failed", __func__);

	addr = PA_DELTA_X_LOW;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN, &value,
		ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR)
		rc_err("%s: read low delta x failed", __func__);

	addr = PA_DELTA_Y_LOW;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN, &value,
		ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR)
		rc_err("%s: read low delta y failed", __func__);

	addr = PA_DELTA_XY_HIGH;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN, &value,
		ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR)
		rc_err("%s: read delta xy_high failed", __func__);
}

static int rotary_crown_chip_init(uint8_t x_res)
{
	int ret;

	// switch to bank 0
	ret = rotary_crown_write_reg(PA_PAGE_BANK_CONTROL, PA_PAGE_BANK_0);
	if (ret != NO_ERR)
		return ret;

	// software reset
	ret = rotary_crown_write_reg(PA_DEVICE_CONTROL, PA_CHIP_RESET);
	if (ret != NO_ERR)
		rc_err("%s: enter software reset failed", __func__);
	msleep(ROTARY_DELAY_1_MS);

	// exit software reset
	ret = rotary_crown_write_reg(PA_DEVICE_CONTROL, PA_CHIP_EXIT_RESET);
	if (ret != NO_ERR)
		return ret;

	ret = rotary_crown_write_reg(PA_OPERATION_MODE, PA_ENTER_SLEEP1_MODE);
	if (ret != NO_ERR)
		return ret;

	// disable write protect
	ret = rotary_crown_write_reg(PA_WRITE_PROTECT, PA_DISABLE_WR_PROTECT);
	if (ret != NO_ERR)
		return ret;

	// set X-axis resolution
	ret = rotary_crown_write_reg(PA_RESOLUTION_X_CONFIG, x_res);
	if (ret != NO_ERR)
		return ret;

	// set Y-axis resolution
	ret = rotary_crown_write_reg(PA_RESOLUTION_Y_CONFIG, PA_Y_RES_VALUE);
	if (ret != NO_ERR)
		return ret;

	// set 12-bit X/Y data format
	ret = rotary_crown_write_reg(PA_DELTA_DATA_FORMAT, PA_USE_12_BIT_FMT);
	if (ret != NO_ERR)
		return ret;

	// set power saving
	ret = rotary_crown_write_reg(PA_LOW_VOL_CONFIG, PA_SET_POWER_SAVING);
	if (ret != NO_ERR)
		return ret;

	// trace performance config
	ret = rotary_crown_write_reg(PA_TRACE_PERF_CONFIG3, PA_PERF_CFG3_VAL);
	if (ret != NO_ERR)
		return ret;

	ret = rotary_crown_write_reg(PA_TRACE_PERF_CONFIG1, PA_PERF_CFG1_VAL);
	if (ret != NO_ERR)
		return ret;

	ret = rotary_crown_write_reg(PA_TRACE_PERF_CONFIG2, PA_PERF_CFG2_VAL);
	if (ret != NO_ERR)
		return ret;

	// enable write protect
	ret = rotary_crown_write_reg(PA_WRITE_PROTECT, PA_ENABLE_WR_PROTECT);
	if (ret != NO_ERR)
		return ret;

	// clear interrupt
	rotary_crown_clear_interrupt();
	return NO_ERR;
}

static irqreturn_t rotary_crown_irq_handler(int irq, void *dev_id)
{
	if (!g_rotary_crown_pdata || !dev_id) {
		rc_err("%s: parameters invalid !\n", __func__);
		return IRQ_HANDLED;
	}
	struct rotary_crown_data *rc = dev_id;

	rc_debug("%s: enter", __func__);
	if (!rc)
		return IRQ_HANDLED;

	if (!rc->is_init_ok)
		return IRQ_HANDLED;

	g_rotary_crown_pdata->irq_cnt++;

	if (g_rotary_crown_pdata->is_calib_test == true) {
		rc_info("%s: irq_cnt = %d", __func__, g_rotary_crown_pdata->irq_cnt);
		return IRQ_HANDLED;
	} else {
		disable_irq_nosync(rc->client->irq);
	}

	if (!queue_work(rotary_crown_notifier_wq, &rc->work)) {
		rc_err("%s: failed to schedule work\n", __func__);
		enable_irq(rc->client->irq);
	}

	return IRQ_HANDLED;
}

static int rotary_crown_read_motion(int16_t *dx)
{
	int ret;
	uint8_t addr;
	int16_t delta_x_low = 0;
	int16_t delta_x_high;
	int16_t delta_xy_high = 0;
	uint8_t value;

	if (dx == NULL)
		return -EINVAL;

	// read delta x low 8-bit
	addr = PA_DELTA_X_LOW;
	value = 0;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN,
		&value, ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR) {
		rc_err("%s: read low delta x failed", __func__);
		return ret;
	}
	rc_debug("%s: low delta x reg 0x%02x", __func__, value);
	delta_x_low |= value;

	// read delta y low 8-bit
	addr = PA_DELTA_Y_LOW;
	value = 0;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN,
		&value, ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR) {
		rc_err("%s: read low delta y failed", __func__);
		return ret;
	}
	rc_debug("%s: low delta y reg 0x%02x", __func__, value);

	// read delta xy high 4-bit
	addr = PA_DELTA_XY_HIGH;
	value = 0;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN,
		&value, ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR) {
		rc_err("%s: read high delta xy failed", __func__);
		return ret;
	}
	rc_debug("%s: high delta reg 0x%02x", __func__, value);
	delta_xy_high |= value;

	delta_x_high = (delta_xy_high << ROTARY_HIGH_DELTA_SHIFT)
		& ROTARY_HIGH_DELTA_MASK;
	if (delta_x_high & ROTARY_HIGH_DELTA_SIGH_MASK)
		delta_x_high |= ROTARY_HIGH_DELTA_SIGH;

	*dx = delta_x_high | delta_x_low;
	return NO_ERR;
}

static int rotary_crown_data_read(int16_t *data)
{
	int ret;
	uint8_t motion_valid = 0;
	uint8_t addr = PA_MOTION_STATUS;
	uint8_t addr_hx3509 = HX3509_INT_MOTION_STATUS;
	if (!g_rotary_crown_pdata || !data) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	if (g_rotary_crown_pdata->chip_id == CR_HX3509)
		ret = rc_i2c_read(&addr_hx3509, ROTARY_REG_ADDR_LEN,
			&motion_valid, ROTARY_REG_VALUE_LEN);
	else
		ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN,
			&motion_valid, ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR) {
		rc_err("%s: read motion status failed", __func__);
		return ret;
	}
	motion_valid &= ROTARY_MOTION_VALID_MASK;

	rc_err("%s: read motion_valid = %d", __func__, motion_valid);
	if (motion_valid) {
		if (g_rotary_crown_pdata->chip_id == CR_MT3501)
			ret = mt3501_rotary_crown_read_motion(data);
		else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
			ret = hx3509_read_motion(data);
		else
			ret = rotary_crown_read_motion(data);
		if (ret != NO_ERR) {
			rc_err("%s: read motion failed", __func__);
			return ret;
		}
	}

	return NO_ERR;
}

static void rotary_crown_data_report(struct rotary_crown_data *rc)
{
	int ret;
	uint8_t no_motion_cnt = 0;
	uint8_t valid_cnt = 0;
	int16_t rdval[ROTARY_SMOOTH_DATA_NUM] = {0};
	int16_t report_x;
	int16_t report_x_degree;
	int32_t temp_x = 0;
	uint8_t i;
	int16_t direction = -1;
	bool first_report = false;
	unsigned long start_time_us;
	unsigned long end_time_us;
	long read_times;
	struct timespec64 now = {0};
	if (!g_rotary_crown_pdata || !rc) {
		rc_err("%s: parameters invalid !\n", __func__);
		return;
	}
	while (no_motion_cnt <= ROTARY_READ_MOTION_TIMES) {
		ktime_get_real_ts64(&now);
		start_time_us = (now.tv_sec * 1000 * 1000) + (now.tv_nsec / 1000);  // Record the current timestamp(us).
		if (rc->is_suspend || rc->is_idle) {
			rc_info("%s:in suspend, break", __func__);
			break;
		}
		if (!gpio_get_value(g_rotary_crown_pdata->irq_gpio)) {
			no_motion_cnt = 0;
			ret = rotary_crown_data_read(&rdval[valid_cnt]);
			if (ret != NO_ERR) {
				rc_err("%s: read motion data failed", __func__);
				break;
			}
		} else {
			no_motion_cnt++;
			rdval[valid_cnt] = 0;
		}
		if (first_report == true) {
			// smooth data process
			for (i = 0; i < ROTARY_SMOOTH_DATA_NUM; i++)
				temp_x += rdval[i];
			report_x = temp_x / ROTARY_SMOOTH_DATA_NUM;
		} else {
			report_x = rdval[valid_cnt];
		}
		valid_cnt++;
		if (valid_cnt >= ROTARY_SMOOTH_DATA_NUM) {
			valid_cnt %= ROTARY_SMOOTH_DATA_NUM;
			first_report = true;
		}
		temp_x = 0;
		// 0/1/2/3/4 is read data index
		report_x_degree = report_x * 360 / g_rotary_crown_pdata->target_x;
		report_x_degree = report_x_degree * direction;
		rc_debug("%s: read motion data %d %d %d %d %d report_x data:%d,report_x_degree data:%d", __func__,
					rdval[0], rdval[1], rdval[2], rdval[3], rdval[4], report_x, report_x_degree);
		input_report_rel(rc->input_dev, REL_WHEEL, report_x_degree);
		ktime_get_real_ts64(&now);
		end_time_us = (now.tv_sec * 1000 * 1000) + (now.tv_nsec / 1000); // Record the current timestamp(us).
		read_times = end_time_us - start_time_us;
		if ((read_times == 0) || (start_time_us > end_time_us)) {
			usleep_range(ROTARY_DEFAULT_TIMES, ROTARY_DEFAULT_TIMES + 1);
		} else if ((read_times) >= ROTARY_SPEED) {
			// The duration exceeds the maximum.
		} else
			usleep_range(ROTARY_SPEED - read_times, ROTARY_SPEED - read_times + 1);
		
		input_sync(rc->input_dev);
	}
}

static void rotary_crown_work_func(struct work_struct *work)
{
	struct rotary_crown_data *rc = container_of(work,
		struct rotary_crown_data, work);
	if (!rc || !g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return;
	}
	if (rc->is_suspend || rc->is_idle) {
		rc_info("%s:in suspend, return", __func__);
		goto out;
	}
#ifdef CONFIG_LCD_KIT_HYBRID
	if (!hybrid_i2c_check()) {
		rc_info("%s:i2c is not at AP, exit", __func__);
		goto out;
	}
#endif
	if (rc->is_working) {
		rc_info("%s:in working, return", __func__);
		goto out;
	}
	rc->is_working = true;
	rc_info("%s: enter", __func__);
	mutex_lock(&g_work_lock);
	// report delta x
	rotary_crown_data_report(rc);
	rc->is_working = false;
	enable_irq(rc->client->irq);
	rc_info("%s:crown irq enable", __func__);
	if (!gpio_get_value(g_rotary_crown_pdata->irq_gpio)) {
		// clear interrupt
		if (g_rotary_crown_pdata->chip_id == CR_MT3501)
			mt3501_clear_interrupt();
		else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
			hx3509_clear_interrupt();
		else
			rotary_crown_clear_interrupt();
		rc_info("%s: irq abnormal clear", __func__);
	}
	mutex_unlock(&g_work_lock);
	rc_debug("%s: exit", __func__);
	return;
out:
	/* disabled in irq handler */
	enable_irq(rc->client->irq);
}

static int rotary_crown_run_mode_set(bool enable)
{
	int ret;

	rc_debug("%s: enter, enable = %d", __func__, enable);
	if (enable) {
		// exit power down mode
		ret = rotary_crown_write_reg(PA_DEVICE_CONTROL, PA_CHIP_EXIT_RESET);
		if (ret != NO_ERR) {
			rc_err("%s: exit power down mode failed, value = %d",
				__func__, PA_CHIP_EXIT_RESET);
			return ret;
		}

		ret = rotary_crown_write_reg(PA_OPERATION_MODE, PA_ENTER_SLEEP1_MODE);
		if (ret != NO_ERR) {
			rc_err("%s: set operation mode failed, value = %d",
				__func__, PA_ENTER_SLEEP1_MODE);
			return ret;
		}
	} else {
		// enter power down mode
		ret = rotary_crown_write_reg(PA_DEVICE_CONTROL, PA_CHIP_POWER_DOWN);
		if (ret != NO_ERR) {
			rc_err("%s: enter power down mode failed, value = %d",
				__func__, PA_CHIP_POWER_DOWN);
			return ret;
		}
	}

	return NO_ERR;
}

#ifdef CONFIG_LCD_KIT_HYBRID
static int get_crown_irq_depth(int irq_id, unsigned int *depth)
{
	struct irq_desc *desc = irq_to_desc(irq_id);

	if (!desc) {
		rc_err("crown get irq desc err\n");
		return -EINVAL;
	}
	if (desc->status_use_accessors & IRQ_PER_CPU_DEVID) {
		rc_err("crown irq is _IRQ_PER_CPU_DEVID\n");
		return -EINVAL;
	}

	*depth = desc->depth;
	rc_info("crown get irq depth:%lu\n", *depth);

	return NO_ERR;
}

void enable_crown_irq(void)
{
	unsigned int i;
	unsigned int depth = 0;

	if (!g_rotary_crown_pdata)
		return;

	mutex_lock(&g_rotary_crown_pdata->irq_lock);
	if (g_rotary_crown_pdata->enable_irq_depth == 0) {
		mutex_unlock(&g_rotary_crown_pdata->irq_lock);
		return;
	}

	if (get_crown_irq_depth(g_rotary_crown_pdata->client->irq, &depth) != 0)
		depth = g_rotary_crown_pdata->enable_irq_depth;

	rc_info("%s depth =%d\n", __func__, depth);
	for (i = 0; i < depth; i++)
		enable_irq(g_rotary_crown_pdata->client->irq);

	g_rotary_crown_pdata->enable_irq_depth = 0;
	mutex_unlock(&g_rotary_crown_pdata->irq_lock);
}

void disable_crown_irq(void)
{
	if (!g_rotary_crown_pdata)
		return;

	mutex_lock(&g_rotary_crown_pdata->irq_lock);
	if (g_rotary_crown_pdata->enable_irq_depth > 0) {
		mutex_unlock(&g_rotary_crown_pdata->irq_lock);
		return;
	}

	disable_irq(g_rotary_crown_pdata->client->irq);
	g_rotary_crown_pdata->enable_irq_depth++;
	rc_info("%s depth =%d\n", __func__, g_rotary_crown_pdata->enable_irq_depth);
	mutex_unlock(&g_rotary_crown_pdata->irq_lock);
}

static int rotary_crown_idle(struct i2c_client *client)
{
	int ret;

	struct rotary_crown_data *rc;
	rc_info("%s: enter", __func__);
	if (!client) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	rc = i2c_get_clientdata(client);

	if (!g_rotary_crown_pdata || !rc) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}

	if (rc->is_idle) {
		rc_info("%s:already in idle, skip", __func__);
		return NO_ERR;
	}

	rc->is_suspend = false;
	rc->is_idle = true;
	del_timer(&g_crown_check_timer);  // Stop the timer
	if (!IS_ERR(rc->rc_pinctrl)) {
		ret = pinctrl_select_state(rc->rc_pinctrl, rc->pinctrl_state_suspend);
		if (ret < 0)
			rc_err("%s:failed to set idle state", __func__);
	}

	if (!gpio_get_value(g_rotary_crown_pdata->irq_gpio)) {
		// clear interrupt
		if (g_rotary_crown_pdata->chip_id == CR_MT3501)
			mt3501_clear_interrupt();
		else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
			hx3509_clear_interrupt();
		else
			rotary_crown_clear_interrupt();
		rc_info("%s: irq abnormal clear", __func__);
	}
	// disable interrupt
	disable_crown_irq();
	if (hybrid_i2c_check()) {
		rc_info("%s:i2c is at AP, set mode", __func__);
		if (g_rotary_crown_pdata->chip_id == CR_MT3501)
			ret = mt3501_rc_run_mode_set(false);
		else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
			ret = hx3509_run_mode_set(false);
		else
			ret = rotary_crown_run_mode_set(false);
		if (ret)
			rc_err("%s: enter sleep 2 mode failed", __func__);
	}

	rc_info("%s: exit\n", __func__);

	return NO_ERR;
}

static int rotary_crown_suspend(struct i2c_client *client)
{
	int ret;
	int count = 0;
	if (!client)
		return -EINVAL;

	struct rotary_crown_data *rc = i2c_get_clientdata(client);
	rc_info("%s: enter", __func__);
	if (!rc || !g_rotary_crown_pdata)
		return -EINVAL;

	if (rc->is_suspend) {
		rc_info("%s:already in suspend, skip", __func__);
		return NO_ERR;
	}

	rc->is_suspend = true;
	rc->is_idle = false;
	del_timer(&g_crown_check_timer);  // Stop the timer
	if (!IS_ERR(rc->rc_pinctrl)) {
		ret = pinctrl_select_state(rc->rc_pinctrl, rc->pinctrl_state_suspend);
		if (ret < 0)
			rc_err("%s:failed to set suspend state", __func__);
	}

	if (!gpio_get_value(g_rotary_crown_pdata->irq_gpio)) {
		// clear interrupt
		if (g_rotary_crown_pdata->chip_id == CR_MT3501)
			mt3501_clear_interrupt();
		else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
			hx3509_clear_interrupt();
		else
			rotary_crown_clear_interrupt();
		rc_info("%s: irq abnormal clear", __func__);
	}
    // disable interrupt
	disable_crown_irq();
	if (hybrid_i2c_check()) {
		rc_info("%s:i2c is at AP, set mode", __func__);
		if (g_rotary_crown_pdata->chip_id == CR_MT3501)
			ret = mt3501_rc_run_mode_set(false);
		else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
			ret = hx3509_run_mode_set(false);
		else
			ret = rotary_crown_run_mode_set(false);
		if (ret)
			rc_err("%s: enter sleep 2 mode failed", __func__);
	}

	do {
		ret = ts_hybrid_crown_power_control(false);
		if (ret == NO_ERR)
			break;
		rc_info("%s: hybrid crown power set false failed, retry = %d", __func__, count);
	} while (++count < SEND_MCU_TRIES);

	rc_info("%s: exit\n", __func__);

	return NO_ERR;
}

static int rotary_crown_resume(struct i2c_client *client)
{
	int ret;
	int count = 0;
	unsigned long expires;
	if (!client) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	struct rotary_crown_data *rc = i2c_get_clientdata(client);
	if (!g_rotary_crown_pdata || !rc) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	rc_info("%s enter", __func__);
	if (!rc->is_suspend && !rc->is_idle) {
		rc_info("%s:already in resume, skip", __func__);
		return NO_ERR;
	}

	do {
		ret = ts_hybrid_crown_power_control(true);
		if (ret == NO_ERR)
			break;
		rc_info("%s: hybrid crown power set true failed, retry = %d", __func__, count);
	} while (++count < SEND_MCU_TRIES);

	if (!hybrid_i2c_check()) {
		rc_info("%s:i2c is not at AP, exit", __func__);
		return NO_ERR;
	}

	if (!IS_ERR(rc->rc_pinctrl)) {
		ret = pinctrl_select_state(rc->rc_pinctrl,
			rc->pinctrl_state_active);
		if (ret < 0)
			rc_err("%s:failed to set active state", __func__);
	}
    // enable irq
    enable_crown_irq();
	// chip write reg
	if (g_rotary_crown_pdata->chip_id == CR_MT3501)
		ret = mt3501_rotary_crown_chip_init(g_rotary_crown_pdata->res_x_nv);
	else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
		ret = hx3509_rotary_crown_chip_init();
	else
		ret = rotary_crown_chip_init(g_rotary_crown_pdata->res_x_nv);
	if (ret)
		rc_err("%s: chip init failed", __func__);

	rc->is_suspend = false;
	rc->is_idle = false;
	if (g_rotary_crown_pdata->chip_id == CR_MT3501) {
		if (mt3501_reset_interrupt() != EC_SUCCESS) {
			rc_err("%s:mt3501_reset_interrupt failed\n", __func__);
		}
	}
	expires = jiffies + (CROWN_RESET_IRQ_TIME * HZ);  // set timer is check_time * 1s
	mod_timer(&g_crown_check_timer, expires);  // Start the timer
	rc_info("%s exit", __func__);

	return NO_ERR;
}

static int rotary_crown_hybrid_suspend(void)
{
	if (!g_rotary_crown_pdata)
		return -EFAULT;

	return rotary_crown_suspend(g_rotary_crown_pdata->client);
}

static int rotary_crown_hybrid_resume(void)
{
	if (!g_rotary_crown_pdata)
		return -EFAULT;

	return rotary_crown_resume(g_rotary_crown_pdata->client);
}

static int rotary_crown_hybrid_idle(void)
{
	if (!g_rotary_crown_pdata)
		return -EFAULT;

	return rotary_crown_idle(g_rotary_crown_pdata->client);
}

struct ts_hybrid_chip_ops ts_hybrid_crown_ops = {
	.hybrid_suspend = rotary_crown_hybrid_suspend,
	.hybrid_resume = rotary_crown_hybrid_resume,
	.hybrid_idle = rotary_crown_hybrid_idle,
};
#endif

static int rotary_crown_irq_init(void)
{
	int ret;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	// interrupt setting
	do {
		ret = gpio_request(g_rotary_crown_pdata->irq_gpio, "RC_INT_IRQ");
		if (ret < 0) {
			rc_err("Failed to request GPIO:%d, ERRNO:%d",
				(s32) g_rotary_crown_pdata->irq_gpio, ret);
			ret = -ENODEV;
			break;
		}

		ret = gpio_direction_input(g_rotary_crown_pdata->irq_gpio);
		if (ret < 0) {
			rc_err("Failed to set GPIO direction:%d, ERRNO:%d",
				(s32) g_rotary_crown_pdata->irq_gpio, ret);
			ret = -ENODEV;
			break;
		}

		g_rotary_crown_pdata->client->irq =
			gpio_to_irq(g_rotary_crown_pdata->irq_gpio);
		rc_debug("irq num:%d\n", g_rotary_crown_pdata->client->irq);
		INIT_WORK(&(g_rotary_crown_pdata->work),
			rotary_crown_work_func);
		rotary_crown_notifier_wq = alloc_workqueue("rotary_corwn_recv", WQ_HIGHPRI, 0);
		if (!rotary_crown_notifier_wq) {
			rc_err("alloc_workqueue fail\n");
			return -ENOMEM;
		}
		// IRQF_TRIGGER_NONE 0x00000000
		// IRQF_TRIGGER_RISING   0x00000001
		// IRQF_TRIGGER_FALLING  0x00000002
		// IRQF_TRIGGER_HIGH 0x00000004
		// IRQF_TRIGGER_LOW  0x00000008
		ret = request_irq(g_rotary_crown_pdata->client->irq,
			rotary_crown_irq_handler, IRQF_TRIGGER_FALLING,
			g_rotary_crown_pdata->client->name, g_rotary_crown_pdata);
		if (ret != 0) {
			destroy_workqueue(rotary_crown_notifier_wq);
			rotary_crown_notifier_wq = NULL;
			rc_err("request_irq failed");
			break;
		}
		disable_irq_nosync(g_rotary_crown_pdata->client->irq);
		rc_info("%s:crown irq disable", __func__);

		return NO_ERR;
	} while (0);

	if (gpio_is_valid(g_rotary_crown_pdata->irq_gpio))
		gpio_free(g_rotary_crown_pdata->irq_gpio);

	return ret;
}

static int rotary_crown_input_init(void)
{
	int ret;

	// interrupt setting
	do {
		// pin control setting
		ret = rotary_crown_pinctrl_init();
		if (ret != NO_ERR) {
			rc_err("failed to init pin control");
			ret = -ENODEV;
			break;
		}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
		// input setting
		g_rotary_crown_pdata->input_dev = input_allocate_device();
		if (g_rotary_crown_pdata->input_dev == NULL) {
			rc_err("Can not allocate memory for input device");
			ret = -ENOMEM;
			break;
		}

		g_rotary_crown_pdata->input_dev->name =
			ROTARY_CROWN_INPUT_DEV_NAME;
		g_rotary_crown_pdata->input_dev->dev.parent =
			&(g_rotary_crown_pdata->client->dev);
		g_rotary_crown_pdata->input_dev->id.bustype = BUS_I2C;
		input_set_capability(g_rotary_crown_pdata->input_dev,
			EV_REL, REL_WHEEL);
		ret = input_register_device(g_rotary_crown_pdata->input_dev);
		if (ret < 0) {
			rc_err("Can not register input device");
			ret = -ENODEV;
			break;
		}

		return NO_ERR;
	} while (0);

	if (g_rotary_crown_pdata->input_dev) {
		input_unregister_device(g_rotary_crown_pdata->input_dev);
		input_free_device(g_rotary_crown_pdata->input_dev);
		g_rotary_crown_pdata->input_dev = NULL;
	}

	return ret;
}

static ssize_t rotary_crown_self_test_show(
	struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	int ret;

	rc_debug("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	struct device_node *np = NULL;
	np = g_rotary_crown_pdata->dev->of_node;
	g_rotary_crown_pdata->irq_gpio = of_get_named_gpio(np, "irq_gpio", 0);
	if (!gpio_is_valid(g_rotary_crown_pdata->irq_gpio)) {
		rc_err("%s:irq_gpio is not valid !\n", __func__);
		return -EINVAL;
	}
    rc_info("%s,g_rotary_crown_pdata->irq_gpio=%d \n", __func__, g_rotary_crown_pdata->irq_gpio);

#ifdef CONFIG_LCD_KIT_HYBRID
	if (!hybrid_i2c_check()) {
		rc_info("%s:i2c is not at AP, exit", __func__);
		return -EINVAL;
	}
#endif

	ret = rotary_crown_check_chip_id();
	if (ret != NO_ERR)
		ret = snprintf_s(buf, ROTARY_STR_LEN, ROTARY_STR_LEN - 1,
			"%s\n", "Fail");
	else
		ret = snprintf_s(buf, ROTARY_STR_LEN, ROTARY_STR_LEN - 1,
			"Success:%d\n", g_rotary_crown_pdata->chip_id);
	if (ret < 0)
		rc_err("%s: snprintf_s err\n", __func__);

	return ret;
}

static ssize_t rotary_crown_status_report_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	char *irq_gpio_sta = NULL;
	int offset = 0;

	rc_debug("%s: called\n", __func__);
	if (!dev || !buf) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	if (!gpio_get_value(g_rotary_crown_pdata->irq_gpio))
		irq_gpio_sta = "low";
	else
		irq_gpio_sta = "high";

	offset += snprintf_s(buf + offset, ROTARY_STR_LEN - offset,
			ROTARY_STR_LEN - offset - 1,
			"irq_gpio:%s, init_status:%u, work_status:%u, power_status:%u\n",
			irq_gpio_sta,
			g_rotary_crown_pdata->is_init_ok,
			g_rotary_crown_pdata->is_working,
			g_rotary_crown_pdata->is_suspend);
	if (offset < 0)
		rc_err("%s: snprintf_s err\n", __func__);

	return offset;
}

static int rotary_crown_read_res_from_nv(uint8_t *res)
{
	int ret;
	struct opt_nve_info_user user_info = {0};
	if (!g_rotary_crown_pdata || !res) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	if (memset_s(&user_info, sizeof(user_info), 0, sizeof(user_info)) != EOK) {
		rc_err("%s: memset error\n", __func__);
		return -EINVAL;
	}
	user_info.nv_operation = NV_READ_OPERATION;
	user_info.nv_number = g_rotary_crown_pdata->nv_number;
	user_info.valid_size = RC_RES_NV_DATA_SIZE;
	if (strncpy_s(user_info.nv_name, sizeof(user_info.nv_name), "RCCALI",
		RC_NV_NAME_LEN) != EOK)
		rc_err("%s: strncpy error\n", __func__);
	user_info.nv_name[sizeof(user_info.nv_name) - 1] = '\0';
	ret = nve_direct_access_interface(&user_info);
	if (ret) {
		rc_err("hw_nve_direct_access read error %d\n", ret);
		return -EINVAL;
	}
	*res = user_info.nv_data[0];
	rc_info("%s: 0x%02x\n", __func__, *res);
    return NO_ERR;
}

static int hx3509_crown_read_res_from_nv(uint16_t *res)
{
	int ret;
	struct opt_nve_info_user user_info = {0};
	if (!g_rotary_crown_pdata || !res) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	if (memset_s(&user_info, sizeof(user_info), 0, sizeof(user_info)) != EOK) {
		rc_err("%s: memset error\n", __func__);
		return -EINVAL;
	}
	user_info.nv_operation = NV_READ_OPERATION;
	user_info.nv_number = g_rotary_crown_pdata->nv_number;
	user_info.valid_size = RC_RES_NV_DATA_SIZE;
	if (strncpy_s(user_info.nv_name, sizeof(user_info.nv_name), "RCCALI",
		RC_NV_NAME_LEN) != EOK)
		rc_err("%s: strncpy error\n", __func__);
	user_info.nv_name[sizeof(user_info.nv_name) - 1] = '\0';
	ret = nve_direct_access_interface(&user_info);
	if (ret) {
		rc_err("hw_nve_direct_access read error %d\n", ret);
		return -EINVAL;
	}
	*res = ((user_info.nv_data[1] << HX3509_SHIFT_HIGH_BIT) | user_info.nv_data[0]);
	rc_info("%s: 0x%x\n", __func__, *res);
    return NO_ERR;
}

#ifdef RC_FACTORY_MODE
static int rotary_crown_write_res_to_nv(uint8_t res)
{
	int ret;
	struct opt_nve_info_user user_info;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	if (memset_s(&user_info, sizeof(user_info), 0, sizeof(user_info)) != EOK) {
		rc_err("%s: memset error\n", __func__);
		return -EINVAL;
	}
	user_info.nv_operation = NV_WRITE_OPERATION;
	user_info.nv_number = g_rotary_crown_pdata->nv_number;
	user_info.valid_size = RC_RES_NV_DATA_SIZE;
	if (strncpy_s(user_info.nv_name, sizeof(user_info.nv_name), "RCCALI",
		RC_NV_NAME_LEN) != EOK)
		rc_err("%s: strncpy error\n", __func__);
	user_info.nv_name[sizeof(user_info.nv_name) - 1] = '\0';
	user_info.nv_data[0] = res;
	ret =  nve_direct_access_interface(&user_info);
	if (ret) {
		rc_err("hw_nve_direct_access write error %d\n", ret);
		return -EINVAL;
	}
	rc_debug("%s: 0x%02x\n", __func__, res);
	return NO_ERR;
}

static int hx3509_crown_write_res_to_nv(uint16_t res)
{
	int ret;
	struct opt_nve_info_user user_info;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	if (memset_s(&user_info, sizeof(user_info), 0, sizeof(user_info)) != EOK) {
		rc_err("%s: memset error\n", __func__);
		return -EINVAL;
	}
	user_info.nv_operation = NV_WRITE_OPERATION;
	user_info.nv_number = g_rotary_crown_pdata->nv_number;
	user_info.valid_size = RC_RES_NV_DATA_SIZE;
	if (strncpy_s(user_info.nv_name, sizeof(user_info.nv_name), "RCCALI",
		RC_NV_NAME_LEN) != EOK)
		rc_err("%s: strncpy error\n", __func__);
	user_info.nv_name[sizeof(user_info.nv_name) - 1] = '\0';
	user_info.nv_data[0] = (uint8_t)res;
    user_info.nv_data[1] = (uint8_t)(res >> HX3509_SHIFT_HIGH_BIT);
	ret =  nve_direct_access_interface(&user_info);
	if (ret) {
		rc_err("hw_nve_direct_access write error %d\n", ret);
		return -EINVAL;
	}
	rc_debug("%s: 0x%02x\n", __func__, res);
	return NO_ERR;
}

static ssize_t rotary_crown_calibrate_nv_store(
	struct device *dev,
	struct device_attribute *attr,
	const char *buf,
	size_t count)
{
	unsigned long val = 0;
	int ret;

	rc_info("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	ret = kstrtoul(buf, 0, &val);
	if (ret) {
		rc_err("%s: call strtoul failed :%d\n", __func__, ret);
		return -EINVAL;
	}

	rc_info("%s: val(%lu)\n", __func__, val);

    if (g_rotary_crown_pdata->chip_id == CR_HX3509) {
		if (val <= ROTARY_HX3509_MIN_RES_X || val >= ROTARY_HX3509_MAX_RES_X) {
			rc_err("%s: the CR_HX3509 calibrate is unreasonably\n", __func__);
			return -EINVAL;
		}
		ret = hx3509_crown_write_res_to_nv((uint16_t)val);
	} else if (g_rotary_crown_pdata->chip_id == CR_MT3501){
		if (val <= ROTARY_MT3501_MIN_RES_X || val >= ROTARY_MT3501_MAX_RES_X) {
			rc_err("%s: the CR_MT3501 calibrate is unreasonably\n", __func__);
			return -EINVAL;
		}
	    ret = rotary_crown_write_res_to_nv((uint8_t)val);
	} else {
		if (val <= ROTARY_MIN_RES_X || val >= ROTARY_MAX_RES_X) {
			rc_err("%s: the calibrate is unreasonably\n", __func__);
			return -EINVAL;
		}
		ret = rotary_crown_write_res_to_nv((uint8_t)val);
	}
	if (ret) {
		rc_err("%s: failed to write nv\n", __func__);
		return ret;
	}

	return count;
}

static ssize_t rotary_crown_calibrate_nv_show(
	struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	int ret;
	uint8_t res = 0;
	uint16_t resx = 0;
	int offset = 0;

	rc_debug("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
    if (g_rotary_crown_pdata->chip_id == CR_HX3509) {
		ret = hx3509_crown_read_res_from_nv(&resx);
	} else {
		ret = rotary_crown_read_res_from_nv(&res);
		resx = res;
	}
	if (ret) {
		rc_err("%s: failed to read nv\n", __func__);
		return ret;
	}
	rc_info("%s: x resoluttion(0x%x)\n", __func__, resx);
	offset += snprintf_s(buf + offset, ROTARY_STR_LEN - offset,
		ROTARY_STR_LEN - offset - 1, "%u\n", resx);
	if (offset < 0)
		rc_err("%s: snprintf_s err\n", __func__);

	return offset;
}

static ssize_t rotary_crown_irq_cnt_store(
	struct device *dev,
	struct device_attribute *attr,
	const char *buf,
	size_t count)
{
	rc_debug("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	g_rotary_crown_pdata->irq_cnt = 0;
	// clear interrupt
	if (g_rotary_crown_pdata->chip_id == CR_MT3501)
		mt3501_clear_interrupt();
	else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
	    hx3509_clear_interrupt();
	else
		rotary_crown_clear_interrupt();

	return count;
}

static ssize_t rotary_crown_irq_cnt_show(
	struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	int offset = 0;

	rc_info("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	rc_debug("%s: irq cnt %d\n", __func__, g_rotary_crown_pdata->irq_cnt);
	offset += snprintf_s(buf + offset, ROTARY_STR_LEN - offset,
		ROTARY_STR_LEN - offset - 1, "%d\n", g_rotary_crown_pdata->irq_cnt);
	if (offset < 0)
		rc_err("%s: snprintf_s err\n", __func__);
	g_rotary_crown_pdata->irq_cnt = 0;

	return offset;
}

static int rotary_crown_set_res(uint8_t res)
{
	int ret;

	rc_debug("%s:called\n", __func__);
	// disable write protect
	ret = rotary_crown_write_reg(PA_WRITE_PROTECT, PA_DISABLE_WR_PROTECT);
	if (ret != NO_ERR)
		return ret;

	// set X-axis resolution
	ret = rotary_crown_write_reg(PA_RESOLUTION_X_CONFIG, res);
	if (ret != NO_ERR)
		return ret;

	// set Y-axis resolution
	ret = rotary_crown_write_reg(PA_RESOLUTION_Y_CONFIG, PA_Y_RES_VALUE);
	if (ret != NO_ERR)
		return ret;

	// enable write protect
	ret = rotary_crown_write_reg(PA_WRITE_PROTECT, PA_ENABLE_WR_PROTECT);
	if (ret != NO_ERR)
		return ret;

	return NO_ERR;
}

static int rc_calibrate_enter(void)
{
	int ret;

	rc_debug("%s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	g_rotary_crown_pdata->is_calib_test = true;
	ret = rotary_crown_set_res(PA_X_RES_VALUE);
	if (ret) {
		rc_err("%s: set chip resolution failed", __func__);
		return ret;
	}

	// clear interrupt
	rotary_crown_clear_interrupt();

	return NO_ERR;
}

static int rc_calibrate_test_exit(void)
{
	rc_debug("%s: enter\n", __func__);
	// clear interrupt
	rotary_crown_clear_interrupt();
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	g_rotary_crown_pdata->is_calib_test = false;

	return NO_ERR;
}

static int rc_test_enter(void)
{
	int ret;
	uint8_t res = 0;
	rc_debug("%s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	g_rotary_crown_pdata->is_calib_test = true;

	// read NV
	ret = rotary_crown_read_res_from_nv(&res);
	if (ret) {
		rc_err("%s: failed to read nv\n", __func__);
		return ret;
	}
	if (res <= ROTARY_MIN_RES_X || res >= ROTARY_MAX_RES_X) {
		rc_err("RES X is unreasonably,use default nv\n");
		res = PA_X_RES_VALUE;
	}
	// write to reg
	ret = rotary_crown_set_res(res);
	if (ret) {
		rc_err("%s: set chip resolution failed", __func__);
		return ret;
	}

	// clear interrupt
	rotary_crown_clear_interrupt();

	return NO_ERR;
}

static ssize_t rotary_crown_calibrate_mode_store(
	struct device *dev,
	struct device_attribute *attr,
	const char *buf,
	size_t count)
{
	unsigned long val = 0;
	int ret;

	rc_info("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	ret = kstrtoul(buf, 0, &val);
	if (ret) {
		rc_err("%s: call strtoul failed :%d\n", __func__, ret);
		return -EINVAL;
	}

	rc_debug("%s: val(%lu)\n", __func__, val);
	if (g_rotary_crown_pdata->chip_id == CR_MT3501) {
		if (val == 0)
			ret = mt3501_rc_calibrate_enter();
		else
			ret = mt3501_rc_calibrate_test_exit();
	} else if (g_rotary_crown_pdata->chip_id == CR_HX3509) {
		if (val == 0)
			ret = hx3509_enter_calib();
		else
			ret = hx3509_exit_calib();
	} else {
		if (val == 0)
			ret = rc_calibrate_enter();
		else
			ret = rc_calibrate_test_exit();
	}
	if (ret) {
		rc_err("%s: calibrate control failed :%d\n", __func__, ret);
		return ret;
	}

	return count;
}

static ssize_t rotary_crown_test_mode_store(
	struct device *dev,
	struct device_attribute *attr,
	const char *buf,
	size_t count)
{
	unsigned long val = 0;
	int ret;

	rc_info("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	ret = kstrtoul(buf, 0, &val);
	if (ret) {
		rc_err("%s: call strtoul failed :%d\n", __func__, ret);
		return -EINVAL;
	}

	rc_debug("%s: val(%lu)\n", __func__, val);
	if (g_rotary_crown_pdata->chip_id == CR_MT3501) {
		if (val == 0)
			ret = mt3501_rc_nv_test_enter();
		else
			ret = mt3501_rc_calibrate_test_exit();
	} else if (g_rotary_crown_pdata->chip_id == CR_HX3509) {
		if (val == 0)
			ret = hx3509_rc_nv_test_enter();
		else
			ret = hx3509_exit_calib();
	} else {
		if (val == 0)
			ret = rc_test_enter();
		else
			ret = rc_calibrate_test_exit();
	}

	if (ret) {
		rc_err("%s: nv test control failed :%d\n", __func__, ret);
		return ret;
	}

	return count;
}

static ssize_t rotary_crown_delta_motion_show(
	struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	int ret;
	uint8_t addr;
	uint8_t addr_hx3509;
	uint8_t value = 0;
	int offset = 0;
	int16_t delta_x = 0;

	rc_info("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	addr = PA_MOTION_STATUS;
	addr_hx3509 = HX3509_INT_MOTION_STATUS;
	if (g_rotary_crown_pdata->chip_id == CR_HX3509)
		ret = rc_i2c_read(&addr_hx3509, ROTARY_REG_ADDR_LEN, &value,
			ROTARY_REG_VALUE_LEN);
	else
		ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN, &value,
			ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR) {
		rc_err("%s: read motion status failed", __func__);
		return ret;
	}

	if (value & ROTARY_MOTION_VALID_MASK) {
		// read delta x
		if (g_rotary_crown_pdata->chip_id == CR_MT3501)
			ret = mt3501_rotary_crown_read_motion(&delta_x);
		else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
			ret = hx3509_read_motion(&delta_x);
		else
			ret = rotary_crown_read_motion(&delta_x);
		if (ret != NO_ERR) {
			rc_err("%s: read x resolution failed", __func__);
			return ret;
		}
	}

	rc_info("%s: delta x(0x%04x)\n", __func__, delta_x);
	offset += snprintf_s(buf + offset, ROTARY_STR_LEN - offset,
		ROTARY_STR_LEN - offset - 1, "%d\n", delta_x);
	if (offset < 0)
		rc_err("%s: snprintf_s err\n", __func__);

	return offset;
}

static ssize_t rotary_crown_resolution_show(
	struct device *dev,
	struct device_attribute *attr,
	char *buf)
{
	int ret;
	uint8_t addr;
	uint8_t resx = 0;
	uint16_t res = 0;
	uint16_t res_default = PA_X_RES_VALUE;
	int offset = 0;
	uint16_t target_x;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	target_x = g_rotary_crown_pdata->target_x;

	rc_info("%s: called\n", __func__);
	if ((dev == NULL) || (buf == NULL)) {
		rc_err("%s: parameter is null\n", __func__);
		return -EINVAL;
	}

	addr = PA_RESOLUTION_X_CONFIG;
	ret = rc_i2c_read(&addr, ROTARY_REG_ADDR_LEN, &resx, ROTARY_REG_VALUE_LEN);
	if (ret != NO_ERR) {
		rc_err("%s: read x resolution failed", __func__);
		return ret;
	}
	if (g_rotary_crown_pdata->chip_id == CR_HX3509) {
		res = g_rotary_crown_pdata->cailbCoef;
		res_default = HX3509_CAILCOEF_DEFAULT;
	} else if (g_rotary_crown_pdata->chip_id == CR_MT3501) {
		res = resx;
		res_default = MT3501_RES_X_DEFAULT;
	} else {
		res = resx;
		res_default = PA_X_RES_VALUE;
	}
	offset += snprintf_s(buf + offset, ROTARY_STR_LEN - offset,
		ROTARY_STR_LEN - offset - 1, "%u,%u,%u\n", res, res_default, target_x);
	if (offset < 0)
		rc_err("%s: snprintf_s err\n", __func__);

	return offset;
}
#endif // RC_FACTORY_MODE

// device file node create
static DEVICE_ATTR(rotary_crown_self_test, 0444, rotary_crown_self_test_show, NULL);
static DEVICE_ATTR(rotary_crown_status_report, 0444, rotary_crown_status_report_show, NULL);
#ifdef RC_FACTORY_MODE
static DEVICE_ATTR(rotary_crown_calibrate_nv, 0664, rotary_crown_calibrate_nv_show,
	rotary_crown_calibrate_nv_store);
static DEVICE_ATTR(rotary_crown_irq_cnt, 0664, rotary_crown_irq_cnt_show,
	rotary_crown_irq_cnt_store);
static DEVICE_ATTR(rotary_crown_calibrate_mode, 0664, NULL,
	rotary_crown_calibrate_mode_store);
static DEVICE_ATTR(rotary_crown_test_mode, 0664, NULL,
	rotary_crown_test_mode_store);
static DEVICE_ATTR(rotary_crown_delta_motion, 0444,
	rotary_crown_delta_motion_show, NULL);
static DEVICE_ATTR(rotary_crown_resolution, 0444,
	rotary_crown_resolution_show, NULL);
#endif // RC_FACTORY_MODE

static struct attribute *rc_attributes[] = {
	&dev_attr_rotary_crown_self_test.attr,
	&dev_attr_rotary_crown_status_report.attr,
#ifdef RC_FACTORY_MODE
	&dev_attr_rotary_crown_calibrate_nv.attr,
	&dev_attr_rotary_crown_irq_cnt.attr,
	&dev_attr_rotary_crown_calibrate_mode.attr,
	&dev_attr_rotary_crown_test_mode.attr,
	&dev_attr_rotary_crown_delta_motion.attr,
	&dev_attr_rotary_crown_resolution.attr,
#endif // RC_FACTORY_MODE
	NULL
};

static struct attribute_group g_rc_attr_group = {
	.attrs = rc_attributes,
};

static int rotary_crown_remove(struct i2c_client *client)
{
	int ret;
	if (!client) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	struct rotary_crown_data *rc = i2c_get_clientdata(client);

	if (!g_rotary_crown_pdata || !rc)
		return -EFAULT;

	if (g_rotary_crown_pdata->chip_id == CR_MT3501)
		ret = mt3501_rc_run_mode_set(false);
	else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
		ret = hx3509_run_mode_set(false);
	else
		ret = rotary_crown_run_mode_set(false);
	if (ret)
		rc_err("%s: enter sleep 2 mode failed", __func__);
	mutex_destroy(&g_work_lock);
	if (!IS_ERR(g_rotary_crown_pdata->rc_pinctrl)) {
		ret = pinctrl_select_state(g_rotary_crown_pdata->rc_pinctrl,
			g_rotary_crown_pdata->pinctrl_state_suspend);
		if (ret)
			rc_err("%s:failed to set release state", __func__);
		devm_pinctrl_put(g_rotary_crown_pdata->rc_pinctrl);
	}
	g_rotary_crown_pdata->rc_pinctrl = NULL;
	i2c_set_clientdata(client, NULL);
	free_irq(client->irq, rc);
	if (rc->input_dev)
		input_unregister_device(rc->input_dev);

	if (g_rotary_crown_pdata->sys_file_ok)
		sysfs_remove_group(&client->dev.kobj, &g_rc_attr_group);

	if (g_rotary_crown_pdata != NULL) {
		devm_kfree(&client->dev, g_rotary_crown_pdata);
		g_rotary_crown_pdata = NULL;
	}

	return NO_ERR;
}

#ifdef CONFIG_LCD_KIT_HYBRID
static void rotary_crown_pm_init(void)
{
	int ret;

	if (!g_rotary_crown_pdata)
		return;
	rc_err("rotary_crown_pm_init\n");

	ret = ts_hybrid_ops_register(&ts_hybrid_crown_ops);
	if (ret)
		rc_err("Unable to register ts hybrid ops: %d\n", ret);
}
#endif

static int rotary_crown_sysfs_init(void)
{
	int ret;

	rc_debug("%s:called\n", __func__);
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	do {
		g_rotary_crown_pdata->sys_file_ok = false;
		ret = sysfs_create_group(&g_rotary_crown_pdata->dev->kobj,
			&g_rc_attr_group);
		if (ret) {
			rc_err("%s: failed to create device attr, ret=%d\n",
				__func__, ret);
			return -ENODEV;
		}

		g_rotary_crown_pdata->sys_file_ok = true;
		ret = sysfs_create_link(NULL, &g_rotary_crown_pdata->dev->kobj,
			"rotarycrown");
		if (ret < 0) {
			pr_err("%s: Failed to sysfs_create_link, %d\n",
				__func__, ret);
			return -ENODEV;
		}
	} while (0);

	return NO_ERR;
}

static int rotary_crown_read_default_nv(void)
{
	int ret;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	if (g_rotary_crown_pdata->nv_status_count < MAX_READ_NV_TIMES) {
		g_rotary_crown_pdata->nv_status_count++;
		ret = rotary_crown_read_res_from_nv(&g_rotary_crown_pdata->res_x_nv);
		if (ret)
			return ret;
	}

	rc_info("nv value is not invalid %d, chip_id = %d\n",
		g_rotary_crown_pdata->res_x_nv, g_rotary_crown_pdata->chip_id);

	if (g_rotary_crown_pdata->chip_id == CR_MT3501) {
		if (g_rotary_crown_pdata->res_x_nv <= ROTARY_MT3501_MIN_RES_X ||
			g_rotary_crown_pdata->res_x_nv >= ROTARY_MT3501_MAX_RES_X)
				g_rotary_crown_pdata->res_x_nv = MT3501_RES_X_DEFAULT;
	} else if (g_rotary_crown_pdata->chip_id == CR_PAT9126) {
		if (g_rotary_crown_pdata->res_x_nv <= ROTARY_MIN_RES_X ||
			g_rotary_crown_pdata->res_x_nv >= ROTARY_MAX_RES_X)
				g_rotary_crown_pdata->res_x_nv = PA_X_RES_VALUE;
	} else {
		if (g_rotary_crown_pdata->res_x_nv <= ROTARY_MIN_RES_X ||
			g_rotary_crown_pdata->res_x_nv >= ROTARY_MAX_RES_X)
				g_rotary_crown_pdata->res_x_nv = PA_X_RES_VALUE;
	}

	rc_info("%s: nv value is %d 0x%08x\n", __func__,
		g_rotary_crown_pdata->nv_status_count, g_rotary_crown_pdata->res_x_nv);
	return EC_SUCCESS;
}

static int rotary_crown_target_set(void)
{
	int ret;
	uint32_t target_x = 0;
	char buf[128] = { '\0' };
	struct device_node *np = NULL;

	rc_debug("%s enter\n", __func__);
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	np = g_rotary_crown_pdata->dev->of_node;
   
    if (g_rotary_crown_pdata->chip_id == CR_PAT9126)
		snprintf_s(buf, ROTARY_STR_LEN, ROTARY_STR_LEN - 1, "%s", ROTARY_CROWN_PAT9126_TARGET_X);
    else if (g_rotary_crown_pdata->chip_id == CR_MT3501)
		snprintf_s(buf, ROTARY_STR_LEN, ROTARY_STR_LEN - 1, "%s", ROTARY_CROWN_MT3501_TARGET_X);
	else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
		rc_debug("chip_id reserved CR_HX3509\n");

    if (buf[0] == '\0') {
		g_rotary_crown_pdata->target_x = ROTARY_STD_DELTA_VAL;
		rc_info("%s,err chip_id,use deafult target_x\n", __func__);
		return NO_ERR;
	}

	ret = of_property_read_u32(np, buf, &target_x);
    if (ret) {
        g_rotary_crown_pdata->target_x = ROTARY_STD_DELTA_VAL;
        rc_err("get targe_x failed\n");
    } else {
        g_rotary_crown_pdata->target_x = (uint16_t)target_x;
    }
	
    rc_info("%s,target_x=%d\n", __func__, g_rotary_crown_pdata->target_x);
	return NO_ERR;
}

static int rotary_crown_detect(void)
{
	int ret;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
#ifdef CONFIG_LCD_KIT_HYBRID
	if (!hybrid_i2c_check()) {
		rc_info("%s:i2c is not at AP, exit", __func__);
		return -1;
	}
#endif
	ret = rotary_crown_check_chip_id();
	if (ret)
		return ret;
		
	ret = rotary_crown_target_set();
	if (ret)
	    return ret;

	ret = rotary_crown_read_default_nv();
	if (ret)
		return ret;

	if (g_rotary_crown_pdata->chip_id == CR_MT3501)
		ret = mt3501_rotary_crown_chip_init(g_rotary_crown_pdata->res_x_nv);
	else if (g_rotary_crown_pdata->chip_id == CR_HX3509) {
		hx3509_crown_read_res_from_nv(&g_rotary_crown_pdata->cailbCoef);
		if (g_rotary_crown_pdata->cailbCoef <= ROTARY_HX3509_MIN_RES_X ||
			g_rotary_crown_pdata->cailbCoef >= ROTARY_HX3509_MAX_RES_X)
			g_rotary_crown_pdata->cailbCoef = HX3509_CAILCOEF_DEFAULT;
	    ret = hx3509_rotary_crown_chip_init();
	} else
		ret = rotary_crown_chip_init(g_rotary_crown_pdata->res_x_nv);
	rc_err("%s: init ret =%d\n", __func__, ret);
	if (ret)
		return ret;

#ifdef CONFIG_LCD_KIT_HYBRID
	rotary_crown_pm_init();
#endif

	enable_irq(g_rotary_crown_pdata->client->irq);
	rc_info("%s:crown irq enable", __func__);
	g_rotary_crown_pdata->is_init_ok = true;
	return NO_ERR;
}

static int mt3501_rotary_crown_read_motion(int16_t *dx)
{
	rc_debug("mt3501_rotary_crown_read_motion enter\n");
	int32_t ret;
	uint8_t delta_x_lo = 0;
	uint8_t delta_y_lo = 0;
	uint8_t delta_x_y_hi = 0;
	uint16_t delta_x;
	uint16_t delta_y;

	ret = mt3501_read_data(MT3501_X_L_REG, (uint8_t *)&delta_x_lo, sizeof(delta_x_lo));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_rotary_crown_read_motion read deltaX err\r\n");
		return EC_FAILURE;
	}
	ret = mt3501_read_data(MT3501_Y_L_REG, (uint8_t *)&delta_y_lo, sizeof(delta_y_lo));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_rotary_crown_read_motion read deltaY err\r\n");
		return EC_FAILURE;
	}
	ret = mt3501_read_data(MT3501_XY_H_REG, (uint8_t *)&delta_x_y_hi, sizeof(delta_x_y_hi));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_rotary_crown_read_motion read deltaXY err\r\n");
		return EC_FAILURE;
	}
	/* 2's complement value calc method */
	delta_x = ((uint16_t)delta_x_y_hi << MT3501_XH_SHIFT) & 0xF00;
	if (delta_x & 0x800) {
		delta_x |= 0xF000;
	}
	delta_y = ((uint16_t)delta_x_y_hi << MT3501_YH_SHIFT) & 0xF00;
	if (delta_y & 0x800) {
		delta_y |= 0xF000;
	}
	if (!dx) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	*dx  = delta_x | delta_x_lo;
	rc_debug("mt3501_rotary_crown_read_motion exit\n");

	return EC_SUCCESS;
}

static int hx3509_read_motion(int16_t *dx)
{
    int32_t ret;
    uint8_t deltaXLo = 0;
    uint8_t deltaYLo = 0;
    uint8_t deltaXHi = 0;
    uint8_t deltaYHi = 0;
    uint16_t deltaY = 0;

	if (!g_rotary_crown_pdata || !dx) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}

    ret = hx3509_read_data(HX3509_X_L_REG, (uint8_t *)&deltaXLo, sizeof(deltaXLo));
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }
    ret = hx3509_read_data(HX3509_Y_L_REG, (uint8_t *)&deltaYLo, sizeof(deltaYLo));
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }
    ret = hx3509_read_data(HX3509_X_H_REG, (uint8_t *)&deltaXHi, sizeof(deltaXHi));
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }
    ret = hx3509_read_data(HX3509_Y_H_REG, (uint8_t *)&deltaYHi, sizeof(deltaYHi));
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    deltaY = (int16_t)((deltaYHi << HX3509_SHIFT_HIGH_BIT) | deltaYLo);
	*dx = (int16_t)(deltaY * g_rotary_crown_pdata->cailbCoef / HX3509_COEF_ZOOM);
	if (g_rotary_crown_pdata->is_calib_test == true)
		rc_info("rotary read motion data dx: %d, deltaY: %d, cailbCoef: %d\n", *dx, deltaY, g_rotary_crown_pdata->cailbCoef);

    return EC_SUCCESS;
}

static int32_t mt3501_read_data(uint8_t reg_addr, uint8_t *buf, uint16_t buf_len)
{
	int32_t ret;
	if (!buf) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	ret = rc_i2c_read(&reg_addr, 1, buf, buf_len);
	if (ret != EC_SUCCESS) {
		rc_err("read date err %d %u\n", ret, reg_addr);
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}

static int hx3509_read_data(uint8_t reg_addr, uint8_t *buf, uint16_t buf_len)
{
	int32_t ret;
	if (!buf) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	ret = rc_i2c_read(&reg_addr, 1, buf, buf_len);
	if (ret != EC_SUCCESS) {
		rc_err("read date err %d %u\n", ret, reg_addr);
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}


static int32_t mt3501_rotary_crown_write_reg(uint8_t addr, uint8_t *buf)
{
	int32_t ret;
	uint8_t cmd[ROTARY_REG_WRITE_LEN] = {0};
	if (!buf) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	// write reg
	cmd[ROTARY_I2C_MSG_INDEX0] = addr;
	cmd[ROTARY_I2C_MSG_INDEX1] = *buf;

	ret = rc_i2c_write(cmd, ROTARY_REG_WRITE_LEN);
	if (ret != NO_ERR)
		rc_err("set value(0x%02x) to reg(0x%02x) failed", *buf, addr);

	return ret;
}

static int32_t mt3501_write_data(uint8_t reg_addr, uint8_t *buf, uint16_t buflen)
{
	int32_t ret;
	if (!buf) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	ret = mt3501_rotary_crown_write_reg(reg_addr, buf);
	if (ret != EC_SUCCESS) {
		rc_err("write date err %d %u\n", ret, reg_addr);
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}

static int hx3509_rotary_crown_write_reg(uint8_t addr, uint8_t *value)
{
	int ret;
	uint8_t cmd[ROTARY_REG_WRITE_LEN] = {0};
	if (!value) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	// write reg
	cmd[ROTARY_I2C_MSG_INDEX0] = addr;
	cmd[ROTARY_I2C_MSG_INDEX1] = *value;

	ret = rc_i2c_write(cmd, ROTARY_REG_WRITE_LEN);
	if (ret != NO_ERR)
		rc_err("set value(0x%02x) to reg(0x%02x) failed", *value, addr);

	return ret;
}

static int32_t hx3509_write_data(uint8_t reg_addr, uint8_t *buf, uint16_t buflen)
{
	int32_t ret;
	if (!buf) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
	ret = hx3509_rotary_crown_write_reg(reg_addr, buf);
	if (ret != EC_SUCCESS) {
		rc_err("write date err %d %u\n", ret, reg_addr);
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}

static int32_t mt3501_soft_ware_reset(void)
{
	int32_t ret;
	uint8_t reg_write = MT3501_RESET_CMD;

	ret = mt3501_write_data(MT3501_CONFIG_ADDR, &reg_write, sizeof(reg_write));
	/* delay 1ms for reset reg check */
	mdelay(1);

	return EC_SUCCESS;
}

static int32_t mt3501_disable_write_protect(void)
{
	int32_t ret;
	uint8_t reg_write = MT3501_WRITE_PROTECT_DISABLE;

	ret = mt3501_write_data(MT3501_WIRTE_PROTECT, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("disable write err\n");
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}
static int32_t mt3501_enable_write_protect(void)
{
	int32_t ret;
	uint8_t reg_write = MT3501_WRITE_PROTECT_ENABLE;

	ret = mt3501_write_data(MT3501_WIRTE_PROTECT, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("enable write err\r\n");
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}

static int32_t mt3501_reset_interrupt(void)
{
	uint8_t reg_write = 0;
	int32_t ret = 0;
	reg_write = MT3501_REG_PAGE_TWO;
	ret = mt3501_write_data(MT3501_TURN_REG_PAGE, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("%s:write data failed\n", __func__);
		return ret;
	}
	reg_write = MT3501__RESET;
	ret = mt3501_write_data(MT3501_RESET_ADDR, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("%s:write data failed\n", __func__);
		return ret;
	}
	msleep(ROTARY_RESET_DELAY);
	reg_write = MT3501_REG_PAGE_ONE;
	ret = mt3501_write_data(MT3501_TURN_REG_PAGE, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("%s:write data failed\n", __func__);
		return ret;
	}
	rc_err("mt3501_reset_interrupt ok exit\n");
	return EC_SUCCESS;
}

static void mt3501_clear_interrupt(void)
{
	int32_t ret;
	uint8_t reg_read = 0;

	ret = mt3501_read_data(MT3501_INT_MOTION_STATUS, &reg_read, sizeof(reg_read));
	if (ret != EC_SUCCESS) {
		rc_err("clear_interrupt read status err\n");
		return;
	}

	ret = mt3501_read_data(MT3501_X_L_REG, &reg_read, sizeof(reg_read));
	if (ret != EC_SUCCESS) {
		rc_err("clear_interrupt read x err\n");
		return;
	}

	ret = mt3501_read_data(MT3501_Y_L_REG, &reg_read, sizeof(reg_read));
	if (ret != EC_SUCCESS) {
		rc_err("clear_interrupt read y err\n");
		return;
	}

	ret = mt3501_read_data(MT3501_XY_H_REG, &reg_read, sizeof(reg_read));
	if (ret != EC_SUCCESS) {
		rc_err("clear_interrupt read xy err\n");
		return;
	}
	rc_err("mt3501_clear_interrupt ok exit\n");
}

static void hx3509_clear_interrupt(void)
{
    int32_t ret;
    uint8_t regRead = 0;

    ret = hx3509_read_data(HX3509_INT_MOTION_STATUS, &regRead, sizeof(uint8_t));
    if (ret != EC_SUCCESS) {
		return;
    }

    ret = hx3509_read_data(HX3509_X_L_REG, &regRead, sizeof(regRead));
    if (ret != EC_SUCCESS) {
		return;
    }

    ret = hx3509_read_data(HX3509_Y_L_REG, &regRead, sizeof(regRead));
    if (ret != EC_SUCCESS) {
		return;
    }
}

static int mt3501_init_post(uint8_t x_res)
{
	int ret;
	uint8_t index = 0;
	const mt3501_reg_info reg_init[] = {
		{0x7F, 0x5A}, {0x0E, 0x00}, {0x0B, 0x30}, {0x0A, 0xF7}, {0x7E, 0x01}, {0x19, 0x0C},
		{0x26, 0x01}, {0x7E, 0x02}, {0x28, 0x02}, {0x29, 0x00}, {0x2A, 0x00}, {0x2B, 0x08},
		{0x1C, 0x44}, {0x1F, 0x4A}, {0x20, 0x10}, {0x21, 0x10}, {0x75, 0xA0}, {0x76, 0x90},
		{0x77, 0xA0}, {0x14, 0x09}, {0x1B, 0x60}, {0x67, 0x13}, {0x2E, 0x40}, {0x30, 0x28},
		{0x3F, 0x06}, {0x53, 0x06}, {0x34, 0x56}, {0x70, 0x00}, {0x71, 0xE8}, {0x72, 0xCF},
		{0x52, 0x30}, {0x5C, 0x50}, {0x7E, 0x03}, {0x35, 0x03}, {0x30, 0x31}, {0x40, 0x65},
		{0x7E, 0x01}, {0x05, 0x18}
	};

	ret = mt3501_disable_write_protect();
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_init_post disable write protect err\n");
		return EC_FAILURE;
	}

    if (x_res == 0) {
		x_res = MT3501_RES_X_DEFAULT;
    }

	ret = mt3501_write_data(MT3501_RES_X_REG, &x_res, sizeof(x_res));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_init_post write err\n");
		return EC_FAILURE;
	}
	rc_err("mt3501_init_post write res 0x%x\n", x_res);

	for (index = 0; index < MT3501_REG_INIT_NUM; index++) {
		ret = mt3501_write_data(reg_init[index].reg_addr,
			(uint8_t *)&reg_init[index].reg_value, MT3501_REG_LEN);
		if (ret != EC_SUCCESS) {
			rc_err("mt3501_init_post write init reg err %u\r\n", index);
			return EC_FAILURE;
		}
	}
	ret = mt3501_enable_write_protect();
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_init_post enalbe write protect err\r\n");
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}


static int mt3501_rotary_crown_chip_init(uint8_t x_res)
{
	int ret;
	rc_err("rotary_crown_chip_init_mt3501\n");

	ret = mt3501_soft_ware_reset();
	if (ret != EC_SUCCESS) {
		rc_err("software reset err\n");
		return EC_FAILURE;
	}

	ret = mt3501_init_post(x_res);
	if (ret != EC_SUCCESS) {
		rc_err("InitPost err\n");
		return EC_FAILURE;
	}
	mt3501_clear_interrupt();
	rc_err("rotary_crown_chip_init_mt3501 ok exit\n");
	return EC_SUCCESS;

}

static int32_t hx3509_software_reset(void)
{
    int32_t ret;
    uint8_t regWrite = HX3509_RESET_CMD1;

    ret = hx3509_write_data(HX3509_RESET_ADDR, &regWrite, HX3509_REG_LEN);
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }
    mdelay(5);

    return EC_SUCCESS;
}

static int32_t hx3509_rotary_crown_chip_initPost(void)
{
    int32_t ret;
    uint8_t resX;
    uint8_t regWrite;
    uint32_t regCnt;
    const Hx3509RegInfo regInit[] = {
		{0x0A, 0x0e}, {0x0B, 0x00}, {0x12, 0x3f}, {0x0C, 0x15}, {0x0D, 0x00}, {0x0E, 0x40},
		{0x0F, 0x00}, {0x14, 0x72}, {0x15, 0x18}, {0x13, 0x60}, {0x1E, 0x00}, {0x17, 0x90},
		{0x1D, 0x05}, {0x19, 0x51}, {0x18, 0x7a}, {0x1A, 0xac}, {0x1B, 0x48}, {0x30, 0x0c},
		{0x3B, 0x17}, {0x20, 0x01}, {0x1F, 0x80}
    };

    regWrite = HX3509_RESET_CMD2;
    ret = hx3509_write_data(HX3509_RESET_ADDR, &regWrite, HX3509_REG_LEN);
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    regWrite = HX3509_VOLTAGE;
    ret = hx3509_write_data(HX3509_ANA_CONFIG, &regWrite, HX3509_REG_LEN);
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    mdelay(5);

    regCnt = sizeof(regInit) / sizeof(Hx3509RegInfo);
    for (uint8_t index = 0; index < regCnt; index++) {
		ret = hx3509_write_data(regInit[index].regAddr, (uint8_t *)&regInit[index].regValue, HX3509_REG_LEN);
		if (ret != EC_SUCCESS) {
			return EC_FAILURE;
		}
    }

    mdelay(5);

    regWrite = HX3509_SCAN_ENABLE;
    ret = hx3509_write_data(HX3509_OP_MODE, &regWrite, HX3509_REG_LEN);
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    mdelay(5);

    regWrite = HX3509_RESET_CMD1;
    ret = hx3509_write_data(HX3509_RESET_ADDR, &regWrite, HX3509_REG_LEN);
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    return EC_SUCCESS;
}

static int32_t hx3509_do_init(void)
{
    int32_t ret;

    ret = hx3509_software_reset();
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    ret = hx3509_rotary_crown_chip_initPost();
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    return EC_SUCCESS;
}

static int32_t hx3509_rotary_crown_chip_init(void)
{
    int32_t ret;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return -EINVAL;
	}
    ret = hx3509_do_init();
    if (ret != EC_SUCCESS) {
		return EC_FAILURE;
    }

    /* clear interrupt */
    hx3509_clear_interrupt();

    if (g_rotary_crown_pdata->cailbCoef == 0) {
		g_rotary_crown_pdata->cailbCoef = HX3509_CAILCOEF_DEFAULT;
    }
	rc_info("cailbCoef: %d\n", g_rotary_crown_pdata->cailbCoef);

    return EC_SUCCESS;
}

static int32_t mt3501_set_resolution_reg(uint8_t res_x, uint8_t res_y)
{
	int32_t ret;

	ret = mt3501_disable_write_protect();
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_set_resolution_reg disable write protect err\n");
		return EC_FAILURE;
	}

	ret = mt3501_write_data(MT3501_RES_X_REG, &res_x, sizeof(res_x));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_set_resolution_reg write resX default err\n");
		return EC_FAILURE;
	}

	ret = mt3501_write_data(MT3501_RES_Y_REG, &res_y, sizeof(res_y));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_set_resolution_reg write resY default err\n");
		return EC_FAILURE;
	}

	ret = mt3501_enable_write_protect();
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_set_resolution_reg enalbe write protect err\n");
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}

static int32_t mt3501_auto_clear_motion(bool clear_status)
{
	uint32_t ret;
	uint8_t reg_write;

	reg_write = MT3501_REG_PAGE_TWO;
	ret = mt3501_write_data(MT3501_TURN_REG_PAGE, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_auto_clear_motion turn page 2 fail\r\n");
		return EC_FAILURE;
	}

	if (clear_status == true)
		reg_write = MT3501_ENABLE_CLEAR;
	else
		reg_write = MT3501_DISABLE_CLEAR;

	ret = mt3501_write_data(MT3501_AUTO_CLEAR_REG, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_auto_clear_motion dis/enable fail\r\n");
		return EC_FAILURE;
	}

	reg_write = MT3501_REG_PAGE_ONE;
	ret = mt3501_write_data(MT3501_TURN_REG_PAGE, &reg_write, sizeof(reg_write));
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_auto_clear_motion turn page 1 fail\r\n");
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}

static int mt3501_rc_run_mode_set(bool enable)
{
	int ret;
	uint8_t reg_write = 0;

	rc_debug("%s: enter, enable = %d", __func__, enable);
	if (enable) {
		reg_write = MT3501_CHIP_ENTER_SLEEP1;
		ret = mt3501_write_data(MT3501_OPERATION_MODE, &reg_write, sizeof(reg_write));
		if (ret != NO_ERR) {
			rc_err("%s: set operation mode failed, value = %d",
				__func__, PA_ENTER_SLEEP1_MODE);
			return ret;
		}
		return EC_SUCCESS;
	}

	// enter power down mode
	reg_write = MT3501_CHIP_POWER_DOWN;
	ret = mt3501_write_data(MT3501_CONFIG_ADDR, &reg_write, sizeof(reg_write));
	if (ret != NO_ERR) {
		rc_err("%s: enter power down mode failed, value = %d",
			__func__, PA_CHIP_POWER_DOWN);
		return ret;
	}

	return EC_SUCCESS;
}

static int hx3509_run_mode_set(bool enable)
{
    int32_t ret;
    uint8_t regWrite;

    ret = hx3509_read_data(HX3509_OPERATION_MODE, &regWrite, sizeof(regWrite));
    if (ret != EC_SUCCESS) {
		return ret;
    }
    if (enable) {
		regWrite = regWrite | HX3509_FROCE_RUN;
    } else {
		regWrite = regWrite & HX3509_OFF_RUN;
    }
    ret = hx3509_write_data(HX3509_OPERATION_MODE, &regWrite, sizeof(regWrite));
    if (ret != EC_SUCCESS) {
		return ret;
    }

	return EC_SUCCESS;
}


#ifdef RC_FACTORY_MODE
static int mt3501_rc_calibrate_enter(void)
{
	int ret;
	uint8_t res_x_default = MT3501_RES_X_DEFAULT;
	uint8_t res_y_default = MT3501_RES_Y_DEFAULT;
	struct rotary_crown_data *rc = NULL;

	rc_info("%s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	g_rotary_crown_pdata->is_calib_test = true;

	ret = mt3501_set_resolution_reg(res_x_default, res_y_default);
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_rc_calibrate_enter SetResolutionReg err\n");
		return EC_FAILURE;
	}

	ret = mt3501_auto_clear_motion(false);
	if (ret != EC_SUCCESS) {
		rc_err("mt3501_rc_calibrate_enter disable clear err\n");
		return EC_FAILURE;
	}

	return EC_SUCCESS;
}

static int hx3509_enter_calib(void)
{

	rc_info("rotary, %s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	g_rotary_crown_pdata->is_calib_test = true;

	hx3509_run_mode_set(true);

	g_rotary_crown_pdata->cailbCoef = HX3509_CAILCOEF_DEFAULT;

	return EC_SUCCESS;
}

// exit calibration
static int mt3501_rc_calibrate_test_exit(void)
{
	int32_t ret;
	struct rotary_crown_data *rc = NULL;

	rc_info("%s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	ret = mt3501_auto_clear_motion(true);
	if (ret != EC_SUCCESS) {
		rc_err("CROWN03_ExitCalib enable clear err\r\n");
		return EC_FAILURE;
	}

    g_rotary_crown_pdata->is_calib_test = false;

	return EC_SUCCESS;
}

static int hx3509_exit_calib(void)
{
	rc_info("rotary, %s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	g_rotary_crown_pdata->is_calib_test = false;
	return EC_SUCCESS;
}

// enter nv result test
static int mt3501_rc_nv_test_enter(void)
{
	int ret;
	uint8_t res = 0;

	rc_info("%s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	g_rotary_crown_pdata->is_calib_test = true;

	// read NV
	ret = rotary_crown_read_res_from_nv(&res);
	if (ret) {
		rc_err("%s: failed to read nv\n", __func__);
		return ret;
	}
	if (res <= ROTARY_MT3501_MIN_RES_X || res >= ROTARY_MT3501_MAX_RES_X) {
		rc_err("MT3501 RES X is unreasonably,use default nv\n");
		res = MT3501_RES_X_DEFAULT;
	}
	ret = mt3501_set_resolution_reg(res, MT3501_RES_Y_DEFAULT);
	if (ret) {
		rc_err("%s: set chip resolution failed", __func__);
		return ret;
	}

	// clear interrupt
	mt3501_clear_interrupt();

	return EC_SUCCESS;
}

static int hx3509_rc_nv_test_enter(void)
{
	int ret;
	uint16_t res = 0;

	rc_info("rotary, %s: enter\n", __func__);
	if (g_rotary_crown_pdata == NULL)
		return -ENOMEM;

	g_rotary_crown_pdata->is_calib_test = true;

	// read NV
	ret = hx3509_crown_read_res_from_nv(&res);
	if (ret) {
		rc_err("%s: failed to read nv\n", __func__);
		return ret;
	}
	if (res <= ROTARY_HX3509_MIN_RES_X || res >= ROTARY_HX3509_MAX_RES_X) {
		rc_err("HX3509 RES X is unreasonably,use default nv\n");	
		res = HX3509_CAILCOEF_DEFAULT;
	}
    g_rotary_crown_pdata->cailbCoef = res;
	rc_info("%s: g_rotary_crown_pdata->cailbCoef =%d\n", __func__, g_rotary_crown_pdata->cailbCoef);

	// clear interrupt
	hx3509_clear_interrupt();

	return EC_SUCCESS;
}
#endif

void mt3501_reinit(void)
{
	int ret;
	uint8_t value;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return;
	}
	if (g_rotary_crown_pdata->chip_id == CR_MT3501) {
		ret = mt3501_read_data(MT3501_RES_X_REG, &value, sizeof(value));
		if (ret != EC_SUCCESS) {
			rc_err("error\n");
			return;
		}
		rc_err("%s addr: 0x0D value: 0x%02x\n", __func__, value);
		if (value != MT3501_RES_X_DEFAULT) {
			rc_err("%s retry detect\n", __func__);
			mt3501_rotary_crown_chip_init(0x40);
		}
	}
	return;
}

static void rorary_crown_detect_and_power_control(void)
{
	int ret;
	ret = ts_hybrid_crown_power_control(true);
	rc_info("%s, at line:%d, ret=%d\n", __func__, __LINE__, ret);
	if (ret == 0)
		ret = rotary_crown_detect();
	if (ret != EC_SUCCESS) {
		g_powerinit = false;
		ts_hybrid_crown_power_control(false);
	} else {
		g_powerinit = true;
	}
	rc_info("%s, at line:%d, g_powerinit:%s, ret=%d\n", __func__, __LINE__, g_powerinit ? "true" : "false", ret);
}

static void crown_check_reset_irq(void)
{
	int ret;

	if (!g_rotary_crown_pdata->is_suspend && !g_rotary_crown_pdata->is_working &&
		!g_rotary_crown_pdata->is_calib_test && !g_rotary_crown_pdata->is_idle) {
		mutex_lock(&g_work_lock);
		ret = rotary_crown_check_chip_id();
		if (ret) {
			rc_err("%s: failed to check chip id\n", __func__);
			mutex_unlock(&g_work_lock);
			return;
		}
		if (!gpio_get_value(g_rotary_crown_pdata->irq_gpio)) {
			// clear interrupt
			if (g_rotary_crown_pdata->chip_id == CR_MT3501)
				mt3501_reset_interrupt();
			else if (g_rotary_crown_pdata->chip_id == CR_HX3509)
				hx3509_clear_interrupt();
			else
				rotary_crown_clear_interrupt();

			disable_irq(g_rotary_crown_pdata->client->irq);
			enable_irq(g_rotary_crown_pdata->client->irq);
			rc_warn("%s: irq abnormal clear", __func__);
		}
		mutex_unlock(&g_work_lock);
	}
}

static void crown_check_work_func(struct work_struct *work)
{
	uint check_time;
	unsigned long expires;
	static int check_work_times = 0;
	if (!g_rotary_crown_pdata) {
		rc_err("%s: parameters invalid !\n", __func__);
		return;
	}
 #ifdef CONFIG_LCD_KIT_HYBRID
	if (!hybrid_i2c_check())
		return;
 #endif
	if (g_powerinit == false) {
		mutex_lock(&g_work_lock);
		rorary_crown_detect_and_power_control();
		mutex_unlock(&g_work_lock);

		if (++check_work_times >= 10) {  // Maximum number of initialization retries: 10
			rc_err("%s check_work_times reach 10, stop timer\n", __func__);
			del_timer(&g_crown_check_timer);  // Stop the timer
			return;
		}
		check_time = CROWN_CHECK_TIME;
		expires = jiffies + (check_time * HZ); // set timer is check_time * 1s
	} else {
		crown_check_reset_irq();
		check_time = CROWN_RESET_IRQ_TIME;
		expires = jiffies + (check_time * HZ);  // set timer is check_time * 1s
	}
	mod_timer(&g_crown_check_timer, expires);
}

static void crown_check_timer_func(struct timer_list *timer)
{
	if (!schedule_work(&g_crown_check_work))
		rc_err("%s: failed to schedule work\n", __func__);
}

static void rotary_crown_check_timer_init(void)
{
	mutex_init(&g_work_lock);
	INIT_WORK(&g_crown_check_work, crown_check_work_func);
	timer_setup(&g_crown_check_timer, crown_check_timer_func, 0);
}

static void rotary_crown_recovery_start(void)
{
	rc_err("%s: init failed, need recovery", __func__);
	g_crown_check_timer.expires = jiffies + (CROWN_RECOVERY_TIME * HZ);
	add_timer(&g_crown_check_timer);
}

static void rotary_crown_check_start(void)
{
	rc_info("%s: init success, need check", __func__);
	g_crown_check_timer.expires = jiffies + (CROWN_CHECK_TIME * HZ);
	add_timer(&g_crown_check_timer);
}

static int rotary_crown_probe(
	struct i2c_client *client, const struct i2c_device_id *id)
{
	int ret;
	int size;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
		return -ENODEV;

	g_rotary_crown_pdata = NULL;
	size = sizeof(struct rotary_crown_data);
	g_rotary_crown_pdata = devm_kzalloc(&client->dev, size, GFP_KERNEL);
	if (!g_rotary_crown_pdata)
		return -ENOMEM;

	ret = memset_s(g_rotary_crown_pdata, size, 0, size);
	if (ret)
		goto err_free;

	i2c_set_clientdata(client, g_rotary_crown_pdata);
	g_rotary_crown_pdata->client = client;
	g_rotary_crown_pdata->dev = &client->dev;
	g_rotary_crown_pdata->enable_irq_depth = 0;
	mutex_init(&g_rotary_crown_pdata->irq_lock);

	ret = rotary_crown_parse_dts();
	if (ret)
		goto err_free;

	// irq setting
	ret = rotary_crown_irq_init();
	if (ret)
		goto err_free;

	// input and pin control setting
	ret = rotary_crown_input_init();
	if (ret)
		goto err_free;

	// sysfs node init
	ret = rotary_crown_sysfs_init();
	if (ret)
		goto err_free;

	rotary_crown_check_timer_init();
	rotary_crown_check_start();

	return NO_ERR;

err_free:
	devm_kfree(&client->dev, g_rotary_crown_pdata);
	return ret;
}

static const struct i2c_device_id rotary_crown_id[] = {
	{ROTARY_CROWN_DRV_NAME, 0},
	{}
};

static const struct of_device_id rotary_crown_match_table[] = {
	{.compatible = "pixart,pat9126ja", },
	{},
};

static struct i2c_driver rotary_crown_driver = {
	.probe      = rotary_crown_probe,
	.remove     = rotary_crown_remove,
	.id_table   = rotary_crown_id,
	.driver = {
		.name   = ROTARY_CROWN_DRV_NAME,
		.owner = THIS_MODULE,
		.of_match_table = rotary_crown_match_table,
	},
};

static int __init rotary_crown_module_init(void)
{
	rc_debug("%s: enter", __func__);
	return i2c_add_driver(&rotary_crown_driver);
}

static void __exit rotary_crown_module_exit(void)
{
	rc_debug("%s: enter", __func__);
	if (rotary_crown_notifier_wq) {
		rc_info("rotary_crown_notifier_wq is not NULL\n");
		destroy_workqueue(rotary_crown_notifier_wq);
		rotary_crown_notifier_wq = NULL;
	}
	i2c_del_driver(&rotary_crown_driver);
}

late_initcall(rotary_crown_module_init);
module_exit(rotary_crown_module_exit);
MODULE_AUTHOR("Huawei Device Company");
MODULE_DESCRIPTION("Huawei RotaryCrown Driver");
MODULE_LICENSE("GPL");