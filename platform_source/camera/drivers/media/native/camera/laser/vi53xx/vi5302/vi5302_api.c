/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/time64.h>

#include "vi5302.h"
#include "vi5302_platform.h"
#include "vi5302_firmware.h"
#include "vi5302_api.h"

#define status_TOF_CONFIDENT 0
#define status_TOF_SEMI_CONFIDENT 6
#define status_TOF_NOT_CONFIDENT 7
#define status_TOF_NO_OBJECT 255

#define LOWER1		2000
#define UPPER1		2300
#define LOWER11		1210
#define UPPER11		1300
#define LOWER2		2800
#define UPPER2		3000
#define LOWER3		1900
#define UPPER3		2100

vi5302_error vi5302_chip_poweron(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;

	status = gpio_direction_output(dev->xshut_gpio, 0);
	mdelay(5);
	status = gpio_direction_output(dev->xshut_gpio, 1);
	mdelay(5);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Chip Power ON Failed status = %d\n", status);
		return VI5302_ERROR_POWER_ON;
	}

	return status;
}

vi5302_error vi5302_chip_poweroff(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;

	status = gpio_direction_output(dev->xshut_gpio, 0);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Chip Power OFF Failed status = %d\n", status);
		return VI5302_ERROR_POWER_OFF;
	}

	return status;
}

vi5302_error vi5302_wait_for_cpu_ready(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint8_t stat = 0;
	int retry = 0;

	do {
		mdelay(1);
		vi5302_read_byte(dev, REG_DEV_STAT, &stat);
	} while((retry++ < MAX_WAIT_RETRY) && (stat & 0x01));
	if (retry >= MAX_WAIT_RETRY) {
		vi5302_errmsg("CPU Busy stat = %d\n", stat);
		return VI5302_ERROR_CPU_BUSY;
	}

	return status;
}

void vi5302_read_chipversion(vi5302_dev dev)
{
	uint8_t chipid[3] = {0};
	uint32_t chipVersion = 0;

	vi5302_read_multibytes(dev, REG_CHIPID_BASE, chipid, 3);
	chipVersion = (chipid[1] << 16) + (chipid[0] << 8) + chipid[2];
	vi5302_infomsg("VI5302 ChipVersion: 0x%x\n", chipVersion);
}

static void vi5302_print_register(vi5302_dev dev)
{
	uint8_t reg_val = 0;
	int reg_addr = 0;
	int reg_cnt_per_line = 16;

	vi5302_infomsg("VI5302 reg 0x00-0x4B:\n");
	vi5302_infomsg("------------------------------------------------------------\n");
	for (reg_addr = 0; reg_addr <= 0x4B; reg_addr++) {
		vi5302_read_byte(dev, reg_addr, &reg_val);
		vi5302_infomsg("0x%02X:0x%02X ", reg_addr, reg_val);
		reg_val = 0;
		if (reg_addr % reg_cnt_per_line == reg_cnt_per_line - 1)
			vi5302_infomsg("\n");
	}
	vi5302_infomsg("\n------------------------------------------------------------\n");
}

vi5302_error vi5302_init_firmware(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint16_t fw_size = 0;
	uint16_t fw_send = 0;
	uint8_t val = 0;
	uint8_t reg_sys_cfg = 0;
	uint8_t buff[2] = {CMD_WRITEFW, 0x40};

	fw_size = vi5302_loadfirmware(dev);
	if (!fw_size) {
		vi5302_errmsg("Firmware Load Failed!\n");
		return VI5302_ERROR_FW_FAILURE;
	}
	vi5302_infomsg("Firmware Load begin!!!\n");
	vi5302_write_byte(dev, REG_PW_CTRL, 0x30);
	vi5302_write_byte(dev, REG_MCU_CFG, 0x36);
	vi5302_read_byte(dev, REG_SYS_CFG, &reg_sys_cfg);
	vi5302_write_byte(dev, REG_SYS_CFG, reg_sys_cfg | (0x01 << 0));
	vi5302_write_byte(dev, REG_CMD, 0x01);
	vi5302_write_byte(dev, REG_SIZE, 0x02);
	vi5302_write_byte(dev, REG_SCRATCH_PAD_BASE + 0x00, 0x00);
	vi5302_write_byte(dev, REG_SCRATCH_PAD_BASE + 0x01, 0x00);
	while (fw_size >= FW_PAGE_SIZE) {
		vi5302_write_multibytes(dev, REG_CMD, buff, 2);
		vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, vi5302_firmware + fw_send * FW_PAGE_SIZE, FW_PAGE_SIZE);
		udelay(10);
		fw_send += 1;
		fw_size -= FW_PAGE_SIZE;
	}
	if (fw_size > 0) {
		buff[1] = fw_size; 
		vi5302_write_multibytes(dev, REG_CMD, buff, 2);
		vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, vi5302_firmware + fw_send * FW_PAGE_SIZE, fw_size);
	}
	vi5302_write_byte(dev, REG_SYS_CFG, 0x0c);
	vi5302_write_byte(dev, REG_DTOP_3, 0xA0);
	vi5302_write_byte(dev, REG_DTOP_3, 0x80);
	vi5302_write_byte(dev, REG_SPECIAL_PURP1, 0x00);
	vi5302_write_byte(dev, REG_MCU_CFG, 0x16);
	vi5302_write_byte(dev, REG_MCU_CFG, 0x17); // fw start run
	vi5302_infomsg("Firmware Load end!!!\n");
	mdelay(5);
	vi5302_read_byte(dev, REG_SPECIAL_PURP1, &val);
	if (val != 0x66) {
		vi5302_errmsg("Download Firmware Failed, value = %d\n", val);
		status = VI5302_ERROR_FW_FAILURE;
	}

	return status;
}

static uint8_t vi5302_get_ma_window_data(vi5302_dev dev)
{
	uint8_t sum_ma = 0;
	uint8_t buff[3] = { 0x00, 0x08, 0x08 };
	int i = 0;
	uint8_t ma_val[8];

	vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, buff, 3);
	vi5302_write_byte(dev, REG_CMD, CMD_USER_CFG);
	mdelay(5);
	vi5302_read_multibytes(dev, REG_USER_DATA, ma_val, 8);
	for (i = 0; i < 8; i++)
		sum_ma += ((ma_val[i] & 0x0F) + ((ma_val[i] >> 4) & 0x0F));

	return sum_ma;
}

static uint8_t vi5302_set_sys_temperature_enable(vi5302_dev dev, uint8_t value)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint8_t buff[4] = { 0x01, 0x01, 0x17, value };

	vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, buff, 4);
	vi5302_write_byte(dev, REG_CMD, CMD_USER_CFG);
	mdelay(5);

	return status;
}

static void vi5302_get_sys_integral_time(vi5302_dev dev, uint32_t *integral_time)
{
	uint8_t buff[3] = { 0x00, 0x03, 0x10 };

	vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, buff, 3);
	vi5302_write_byte(dev, REG_CMD, CMD_USER_CFG);
	mdelay(5);
	vi5302_read_multibytes(dev, REG_USER_DATA, (uint8_t *)integral_time, 3);
}

static void vi5302_set_sys_delay_time(vi5302_dev dev, uint16_t delay_time)
{
	uint8_t buff[5] = { 0x01, 0x02, 0x13, delay_time & 0xFF, delay_time >> 8 };

	vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, buff, 5);	
	vi5302_write_byte(dev, REG_CMD, CMD_USER_CFG);
	mdelay(5);
}

void vi5302_set_fps(vi5302_dev dev, uint32_t fps)
{
	if (fps == 0)
		return;
	uint32_t inte_time = 0;
	uint32_t fps_time = 0;
	uint32_t delay_time = 0;
	uint16_t delay_counts = 0;
	uint32_t integral_count = 0;

	vi5302_get_sys_integral_time(dev, &integral_count);

	inte_time = integral_count  * 1463 / 10;
	fps_time = 1000000000 / fps;
	delay_time = fps_time - inte_time - 2150000 - 890000;
	delay_counts = (uint16_t)(delay_time / 100000);

	vi5302_set_sys_delay_time(dev, delay_counts);

	if (dev->enable_debug)
		vi5302_infomsg("integral_count:%u, delay_counts:%u\n", integral_count, delay_counts);
}

vi5302_error vi5302_otp_read(vi5302_dev dev, uint8_t base, uint8_t *read_buff, uint8_t len)
{
	uint8_t buff[3] = { 0x03, len, base };
	if (len > OTP_MAX_SIZE || len == 0)
		return VI5302_ERROR_OTP;

	vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, buff, 3);
	vi5302_write_byte(dev, REG_CMD, CMD_USER_CFG);
	mdelay(5);
	vi5302_read_multibytes(dev, REG_USER_DATA, read_buff, len);

	return VI5302_ERROR_NONE;
}

vi5302_error vi5302_read_chipid(vi5302_dev dev)
{
	uint16_t id = 0;
	uint8_t buff[2] = { 0 };

	vi5302_otp_read(dev, 0x25, buff, 2);
	id = (buff[1] << 8) + buff[0];

	vi5302_infomsg("chip id: 0x%x\n", id);

	return VI5302_ERROR_NONE;
}

vi5302_error vi5302_single_measure(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;

	status = vi5302_wait_for_cpu_ready(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("CPU Abnormal Single Measure!status = %d\n", status);
		return VI5302_ERROR_SINGLE_CMD;
	}

	status = vi5302_write_byte(dev, REG_CMD, CMD_SINGLE_RANGE);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Single measure Failed status = %d\n", status);
		return VI5302_ERROR_SINGLE_CMD;
	}

	return status;
}

vi5302_error vi5302_redownload_fw(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;

	status = vi5302_interrupt_enable(dev);
	if (status != VI5302_ERROR_NONE)
		return status;

	status = vi5302_init_firmware(dev);
	if (status != VI5302_ERROR_NONE)
		return status;

	status = vi5302_config_xtalk_parameter(dev);
	if (status != VI5302_ERROR_NONE)
		return status;

	vi5302_set_fps(dev, dev->fps);
	return status;
}

vi5302_error vi5302_start_continuous_measure(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint8_t stat = 0;
	vi5302_infomsg("enter vi5302_start_continuous_measure\n");

	status = vi5302_wait_for_cpu_ready(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("CPU Abnormal Continuous Measure!status = %d\n", status);
		return VI5302_ERROR_CONTINUOUS_CMD;
	}
	status = vi5302_read_byte(dev, REG_INT_STATUS, &stat); // clear soft-int before start measurement
	status = vi5302_write_byte(dev, REG_CMD, CMD_CONTINOUS_RANGE);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Continuous Measure Failed status = %d\n", status);
		return VI5302_ERROR_CONTINUOUS_CMD;
	}
	vi5302_infomsg("\n");
	mdelay(5); // Prevent stop fail when the interval between start and stop is too short
	return status;
}

vi5302_error vi5302_stop_continuous_measure(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;

	status = vi5302_write_byte(dev, REG_CMD, CMD_STOP_RANGE);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Stop Measure Failed status = %d\n", status);
		return VI5302_ERROR_STOP_CMD;
	}
	mdelay(5); // 给固件处理命令时间，防止stop不成功
	return status;
}

static int32_t vi5302_calculate_pileup_bias(uint8_t ma_sum, uint32_t peak, uint32_t noise, uint32_t integral_times)
{
	int32_t xth[] = { 0, 363, 500, 739, 1000, 1240, 1608, 1755, 1924, 2090, 2400 };
	int32_t pth[] = { 0, 5, 10, 15, 23, 28, 44, 47, 56, 66, 75 };
	int i = 0;
	int32_t bias = 0;
	int32_t peak_tmp = 0;

	if (integral_times == 0)
		return bias;

	noise /= 8;
	if (peak > noise * ma_sum)
		peak_tmp = (peak - noise * ma_sum) * 16 / integral_times;

	for (i = 0; i < sizeof(xth) / sizeof(xth[0]) - 1; i++) {
		if (peak_tmp < xth[i + 1]) {
			if (xth[i] != xth[i + 1])
				bias = (pth[i + 1] - pth[i]) * (peak_tmp - xth[i]) / (xth[i + 1] - xth[i]) + pth[i];
			return bias;
		}
	}
	if (xth[i] != xth[i - 1])
		bias = (pth[i] - pth[i - 1]) * (peak_tmp - xth[i - 1]) / (xth[i] - xth[i - 1]) + pth[i - 1];
	return bias;
}

static int32_t vi5302_calculate_noise_bias(uint32_t noise, uint32_t integral_times)
{
	int32_t xth[] = {0,10,25,45};
	int32_t pth[] = {0,5,6,6};

	uint8_t len = 0;
	uint8_t i = 0;
	int16_t bias = 0;
	int32_t noise_cal = 0;

	len = sizeof(xth) / sizeof(xth[0]);
	if (integral_times == 0)
		return bias;

	noise_cal = 1000 * noise / 8 / integral_times;
	for (i = 0; i < len - 1; i++) {
		if (noise_cal < xth[i + 1]) {
			if (xth[i] != xth[i + 1])
				bias = (pth[i + 1] - pth[i]) * (noise_cal - xth[i]) / (xth[i + 1] - xth[i]) + pth[i];
			return bias;
		}
	}
	if (xth[i] != xth[i - 1])
		bias = (pth[i] - pth[i - 1]) * (noise_cal - xth[i - 1]) / (xth[i] - xth[i - 1]) + pth[i - 1];
	return bias;
}

static uint8_t vi5302_calculate_confidence_internal(uint8_t tof_bin, uint8_t flag, uint32_t r, uint32_t upper, uint32_t lower, int c, uint8_t threshold)
{
	uint32_t level = 0;

	if (flag == 0)
		return 0;

	if (c > 0 && tof_bin < threshold)
		level = 0;
	else if (c < 0 && tof_bin > threshold)
		level = 0;
	else
		level = c * (tof_bin - threshold) / 10;

	lower += level;
	upper += level;

	if (r > upper)
		return 100;
	else if (r < lower)
		return 0;
	else
		return 100 * (r - lower) / (upper - lower);
}

static void vi5302_calculate_confidence(uint32_t *peaks, uint8_t * tof_bins, uint32_t noise_r, uint32_t integral_times, uint32_t ma_sum, uint8_t flag, uint8_t *confidences)
{
	if (ma_sum == 0)
		return;
	uint64_t p[4] = {0};
	uint32_t r[3] = {0};
	uint32_t lower1= LOWER1;
	uint32_t upper1 = UPPER1;

	p[0] = 100 * (uint64_t)peaks[0] / ma_sum - noise_r;
	p[1] = 100 * (uint64_t)peaks[1] / ma_sum - noise_r;
	p[2] = 100 * (uint64_t)peaks[2] / ma_sum - noise_r;
	p[3] = 100 * (uint64_t)peaks[3] / ma_sum - noise_r;
	r[0] = 1000 * p[0] / p[1];
	r[1] = 1000 * p[1] / p[2];
	r[2] = 1000 * p[2] / p[3];

	if (noise_r > 18000) {
		upper1 = UPPER11;
		lower1 = LOWER11;
	}
	confidences[0] = vi5302_calculate_confidence_internal(tof_bins[0], flag & 0x1, r[0], upper1, lower1, 35, 95);
	confidences[1] = vi5302_calculate_confidence_internal(tof_bins[1], flag & 0x2, r[1], UPPER2, LOWER2, 50, 95);
	confidences[2] = vi5302_calculate_confidence_internal(tof_bins[2], flag & 0x4, r[2], UPPER3, LOWER3, 30, 90);

	if (peaks[0] < 500)
		confidences[0] = 0;
	if (peaks[1] < 500)
		confidences[1] = 0;
	if (peaks[2] < 500)
		confidences[2] = 0;

	if ((flag & 0x2) && (flag & 0x4) && (confidences[2] >= 80))
		confidences[1] = 100;
	if (confidences[1] == 100 && confidences[2] == 100)
		confidences[0] = 100;
	if (r[1] > 14000)
		confidences[0] = 100;
	if ((tof_bins[1] > tof_bins[3]) && (confidences[1] == 100))
		confidences[0] = 100;
}

vi5302_error vi5302_get_measure_data(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint8_t ret = 0;
	uint8_t stat = 0;
	uint8_t data_buff[64];
	int16_t tof1 = 0, tof2 = 0, tof3 = 0, tof4 = 0;
	uint8_t tof_bins[4] = {0};
	uint32_t peaks[4] = {0};
	uint32_t noise = 0;
	uint32_t integral_times = 0;
	uint8_t reftof_bin = 0;
	uint8_t flag = 0;
	uint8_t confidences[3] = {0};
	uint8_t xtalk_bin = 0;
	uint32_t peak = 0;
	uint32_t noise_r = 0;
	int16_t tof = 0;
	int16_t bias = 0;
	uint8_t confidence = 0;
	int16_t correction_tof = 0;
	uint32_t c = 0;
	struct timespec64 end_ts = {0}, ts_sub = {0};
	uint32_t peakr = 0;
	int rc = 0;

	status = vi5302_read_byte(dev, REG_INT_STATUS, &stat);
	if (status == VI5302_ERROR_NONE) {
		if ((stat & 0x01) == 0x01) {
			ret = vi5302_read_multibytes(dev, REG_SCRATCH_PAD_BASE, data_buff, 64);
			if (ret != 0) {
				vi5302_errmsg("Get Range Data Failed ret = %d\n", ret);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&tof1, 2, &data_buff[0], 2); // 最高目标峰的距离
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&peaks[0], 4, &data_buff[2], 4); // 最高目标峰的信号强度
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&tof2, 2, &data_buff[6], 2); // 次高目标峰的距离
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&peaks[1], 4, &data_buff[8], 4); // 次高目标峰的信号强度
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&tof3, 2, &data_buff[12], 2); // 第三目标峰的距离
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&peaks[2], 4, &data_buff[14], 4); // 第三目标峰信号强度
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&tof4, 2, &data_buff[18], 2); // 第四目标峰的距离
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&peaks[3], 4, &data_buff[20], 4); // 第四目标峰信号强度
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			rc = memcpy_s(&noise, 4, &data_buff[24], 4); // 噪声
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			noise &= 0x00FFFFFF;
			rc = memcpy_s(&integral_times, 4, &data_buff[27], 4); // 积分次数
			if (rc != EOK) {
				vi5302_errmsg("memcpy_s ret = %d\n", rc);
				return VI5302_ERROR_GET_DATA;
			}
			integral_times &= 0x00FFFFFF;
			if (integral_times == 0) {
				vi5302_errmsg("integral_times = %u\n", integral_times);
				return VI5302_ERROR_GET_DATA;
			}
			reftof_bin = data_buff[39];
			tof_bins[0] = data_buff[40]; // 最高目标峰在直方图的横坐标位置
			tof_bins[1] = data_buff[41]; // 次高目标峰在直方图的横坐标位置
			tof_bins[2] = data_buff[42]; // 第三目标峰在直方图的横坐标位置
			flag = data_buff[44];

			noise_r = 100 * noise / 8;
			xtalk_bin = reftof_bin + dev->xtalk_config.xtalk_cal;
			if (tof_bins[1] <= (xtalk_bin + 2)) {
				peaks[1] = peaks[2];
				peaks[2] = peaks[3];
				tof2 = tof3;
				tof3 = tof4;
			}
			tof_bins[3] = xtalk_bin + 2;
			vi5302_calculate_confidence(peaks, tof_bins, noise_r, integral_times, dev->ma_sum, flag, confidences);

			if (tof_bins[0] > (xtalk_bin + 2)) {
				tof = tof1;
				confidence = confidences[0];
				peak = peaks[0];
			} else if ((100 * peaks[0] - noise_r * dev->ma_sum) / integral_times > 65) {
				tof = tof1;
				confidence = confidences[0];
				peak = peaks[0];
			} else {
				tof = tof2;
				confidence = confidences[1];
				peak = peaks[1];
			}
			bias = vi5302_calculate_pileup_bias(dev->ma_sum, peak, noise, integral_times);
			bias += vi5302_calculate_noise_bias(noise, integral_times);
			correction_tof = tof + (int16_t)bias - dev->offset_config;
			vi5302_infomsg("correction_tof(%d), tof(%d), dev->offset_config(%d), bias(%d), peak(%u), noise(%u), confidence(%u)",
				correction_tof, tof, dev->offset_config, bias, peak, noise, confidence);
			if (correction_tof > 6100)
				confidence = 0;
			if (noise > 25000 && (correction_tof > 1900 || correction_tof < -20))
				confidence = 0;
			peakr  = (peak - noise / 8 * dev->ma_sum) * 16 / integral_times;
			if (noise_r > 18000 && peakr < 1)
				confidence = 0;

			getnstimeofday64(&end_ts);
			ts_sub = timespec64_sub(end_ts, dev->start_ts);
			if (confidence >= 70) {
				if(correction_tof <= 0) {
					correction_tof = 25;
					dev->range_data.milimeter = correction_tof;
				}
				dev->range_data.status = status_TOF_CONFIDENT;
				dev->range_data.confidence = 1; // 1: confident
			} 
			else {
				correction_tof = 1500;
				dev->range_data.milimeter = correction_tof;
				dev->range_data.status = status_TOF_NO_OBJECT;
				dev->range_data.confidence = 0; // 0: not confident
			}
			dev->range_data.milimeter = correction_tof; // << 16; 最终计算的校正后距离值上报
			vi5302_infomsg("correction_tof(%d), bias(%d), peak(%u)", correction_tof, bias, peak);
			if (dev->enable_debug) {
				vi5302_infomsg("tof1:%d, tof1_bin:%d, peak1:%u, tof2:%d, tof2_bin:%d, peak2:%u, tof3_bin: %d, peak3:%u, peak4:%u, reftof_bin:%d, noise:%u, integral_times:%u,\n",
					tof1, tof_bins[0], peaks[0], tof2, tof_bins[1], peaks[1], tof_bins[2], peaks[2], peaks[3], reftof_bin, noise, integral_times);
				vi5302_infomsg("tof:%d, confidence:%d, peak:%d, ma_sum:%d, xtalk_cal:%d, xtalk_peak:%d, offset:%d, bias:%d, noise_r:%u, c:%d, xtalk_bin=%d\n",
					correction_tof, confidence, peak, dev->ma_sum, dev->xtalk_config.xtalk_cal, dev->xtalk_config.xtalk_peak, dev->offset_config, bias, noise_r, c, xtalk_bin);
			}
			dev->range_data.noise = noise;
		}
	}
	return VI5302_ERROR_NONE;
}

vi5302_error vi5302_get_interrupt_state(vi5302_dev dev, uint8_t *stat)
{
	if (!stat)
		return VI5302_ERROR_IRQ_STATE;
	vi5302_error status = VI5302_ERROR_NONE;

	status = vi5302_read_byte(dev, REG_INT_STATUS, stat);
	if (status) {
		vi5302_errmsg("Get Interrupt State Failed status = %d\n", status);
		return VI5302_ERROR_IRQ_STATE;
	}

	return status;
}

vi5302_error vi5302_interrupt_enable(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;
	int loop = 0;
	uint8_t enable = 0;

	do {
		vi5302_read_byte(dev, REG_INTR_MASK, &enable);
		enable |=  0x01;
		vi5302_write_byte(dev, REG_INTR_MASK, enable);
		vi5302_read_byte(dev, REG_INTR_MASK, &enable);
		loop++;
	} while((loop < MAX_WAIT_RETRY) && (!(enable & 0x01)));
	if (loop >= MAX_WAIT_RETRY) {
		vi5302_errmsg("Enable interrupt Failed status = %d\n", status);
		return VI5302_ERROR_ENABLE_INTR;
	}

	return status;
}

vi5302_error vi5302_chip_init(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;

	vi5302_read_chipversion(dev);
	status = vi5302_wait_for_cpu_ready(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Internal CPU busy!\n");
		return status;
	}
	status = vi5302_interrupt_enable(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Clear Interrupt Mask failed!\n");
		return status;
	}
	status = vi5302_init_firmware(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Download Firmware Failed!\n");
		vi5302_print_register(dev);
		return status;
	}
	dev->ma_sum = vi5302_get_ma_window_data(dev);
	vi5302_read_fw_version(dev);

	return status;
}

vi5302_error vi5302_start_xtalk_calibration(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;

	status = vi5302_wait_for_cpu_ready(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("CPU Abnormal XTALK Calibrating status = %d\n", status);
		return VI5302_ERROR_XTALK_CALIB;
	}
	vi5302_set_sys_temperature_enable(dev, 0x0);
	status = vi5302_write_byte(dev, REG_CMD, CMD_XTALK);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("XTALK Calibration Failed status = %d\n", status);
		return VI5302_ERROR_XTALK_CALIB;
	}

	return status;
}

vi5302_error vi5302_start_offset_calibration(vi5302_dev dev, uint32_t param)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint8_t stat = 0;
	uint8_t data_buff[64];
	uint32_t peak1 = 0, peak2 = 0, peak3 = 0, peak4 = 0;
	int16_t tof1 = 0, tof2 = 0;
	uint8_t tof1_bin = 0, tof2_bin = 0;
	uint32_t noise = 0;
	uint32_t integral_times = 0;
	uint8_t reftof_bin = 0;
	uint8_t xtalk_bin = 0;
	uint32_t peak = 0;
	int32_t tof = 0;
	uint32_t c = 0;
	uint32_t noise_r = 0;
	int32_t bias = 0;
	int32_t sum_tof = 0;
	int cnt = 0;

	status = vi5302_read_byte(dev, REG_INT_STATUS, &stat);
	vi5302_set_sys_temperature_enable(dev, 0x0);
	status = vi5302_start_continuous_measure(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Offset Calibtration Start Failed!\n");
		return VI5302_ERROR_OFFSET_CALIB;
	}
	while(1) {
		mdelay(35);
		status = vi5302_read_byte(dev, REG_INT_STATUS, &stat);
		if (status == VI5302_ERROR_NONE) {
			if ((stat & 0x01) == 0x01) {
				status |= vi5302_read_multibytes(dev, REG_SCRATCH_PAD_BASE, data_buff, 64);
				if (status != VI5302_ERROR_NONE) {
					vi5302_errmsg("Get Range Data Failed status = %d\n", status);
					break;
				}
				if (memcpy_s(&tof1, sizeof(int16_t), &data_buff[0], 2) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				if (memcpy_s(&peak1, sizeof(uint32_t), &data_buff[2], 4) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				if (memcpy_s(&tof2, sizeof(int16_t), &data_buff[6], 2) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				if (memcpy_s(&peak2, sizeof(uint32_t), &data_buff[8], 4) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				if (memcpy_s(&peak3, sizeof(uint32_t), &data_buff[14], 4) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				if (memcpy_s(&peak4, sizeof(uint32_t), &data_buff[20], 4) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				if (memcpy_s(&noise, sizeof(uint32_t), &data_buff[24], 4) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				noise &= 0x00FFFFFF;
				if (memcpy_s(&integral_times, sizeof(uint32_t), &data_buff[27], 4) != EOK) {
					vi5302_errmsg("memcpy failed");
					break;
				}
				integral_times &= 0x00FFFFFF;
				reftof_bin = data_buff[39];
				tof1_bin = data_buff[40];
				tof2_bin = data_buff[41];

				noise_r = 100 * noise / 8;
				xtalk_bin = reftof_bin + dev->xtalk_config.xtalk_cal;
				if (tof2_bin <= (xtalk_bin + 2)) {
					peak2 = peak3;
					peak3 = peak4;
				}
				c = noise > 30000 ? 600 : 1500;
				if (tof1_bin > (xtalk_bin + 2)) {
					tof = tof1;
					peak = peak1;
				} else if ((100 * peak1 - noise_r * dev->ma_sum) > c * (uint32_t)dev->xtalk_config.xtalk_peak * dev->ma_sum) {
					tof = tof1;
					peak = peak1;
				} else {
					tof = tof2;
					peak = peak2;
				}
				bias = vi5302_calculate_pileup_bias(dev->ma_sum, peak, noise, integral_times);
				vi5302_infomsg("tof:%d, peak:%d, bias:%d, xtalk_cal:%d, reftof_bin:%d, xtalk_bin:%d, tof1:%d, tof2:%d\n", 
					tof, peak, bias, dev->xtalk_config.xtalk_cal, reftof_bin, xtalk_bin, tof1, tof2);
				sum_tof += tof + bias;
				++cnt;
			} else {
				continue;
			}
		} else {
			vi5302_errmsg("Can't Get irq State!status = %d\n", status);
			break;
		}
		if (cnt >= 30)
			break;
	}
	status = vi5302_stop_continuous_measure(dev);
	if (status != VI5302_ERROR_NONE) {
		vi5302_errmsg("Offset Calibtration Stop Failed!\n");
		return VI5302_ERROR_OFFSET_CALIB;
	}
	vi5302_set_sys_temperature_enable(dev, 0x1);
	status = vi5302_read_byte(dev, REG_INT_STATUS, &stat);
	dev->offset_data.offset_cal = sum_tof / 30 - param;
	vi5302_infomsg("offset_cal:%d, sum_tof:%d\n", dev->offset_data.offset_cal, sum_tof);
	return status;
}

vi5302_error vi5302_get_xtalk_parameter(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint8_t val = 0;
	uint8_t cg_buf[5];

	status = vi5302_read_byte(dev, REG_SPECIAL_PURP1, &val);
	if (status == VI5302_ERROR_NONE && val == 0xaa) {
		status = vi5302_read_multibytes(dev, 0x39, cg_buf, 3);
		if (status != VI5302_ERROR_NONE) {
			vi5302_errmsg("Get XTALK parameter Failed status = %d\n", status);
			status = VI5302_ERROR_XTALK_CALIB;
		} else {
			dev->xtalk_data.xtalk_cal = *((int8_t *)(cg_buf + 0));
			dev->xtalk_data.xtalk_peak = *((uint16_t *)(cg_buf + 1));
		}
	} else {
		vi5302_errmsg("XTALK Calibration Failed status = %d, val = 0x%02x\n", status, val);
		status = VI5302_ERROR_XTALK_CALIB;
	}
	vi5302_set_sys_temperature_enable(dev, 0x1);
	return status;
}

vi5302_error vi5302_config_xtalk_parameter(vi5302_dev dev)
{
	vi5302_error status = VI5302_ERROR_NONE;
	uint8_t buff[4] = { 0x01, 0x01, 0x15, *((uint8_t *)(&dev->xtalk_config)) };

	vi5302_write_multibytes(dev, REG_SCRATCH_PAD_BASE, buff, 4);
	vi5302_write_byte(dev, REG_CMD, CMD_USER_CFG);
	mdelay(5);

	return status;
}

void vi5302_read_fw_version(vi5302_dev dev)
{
	uint8_t len = 0;
	char fw_version[20] = {0};
	
	vi5302_write_byte(dev, REG_SCRATCH_PAD_BASE, SUBCMD_READ_FW_VERSION);
	vi5302_write_byte(dev, REG_CMD, CMD_USER_CFG);
	mdelay(5);
	vi5302_read_byte(dev, REG_USER_DATA, &len);
	if (len == 0 || len >= ARRAY_SIZE(fw_version)) {
		vi5302_errmsg("fw version len error, len = %u\n", len);
		return;
	}
	vi5302_read_multibytes(dev, REG_USER_DATA + 1, fw_version, len);
	fw_version[len] = '\0';

	vi5302_infomsg("fw version: %s\n", fw_version);
}
