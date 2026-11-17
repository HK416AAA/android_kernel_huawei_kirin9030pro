/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#ifndef _VI5302_API_H_
#define _VI5302_API_H_
#include "vi5302.h"

vi5302_error vi5302_chip_poweron(vi5302_dev dev);
vi5302_error vi5302_chip_poweroff(vi5302_dev dev);
void vi5302_read_chipversion(vi5302_dev dev);
void vi5302_set_fps(vi5302_dev dev, uint32_t fps);
vi5302_error vi5302_single_measure(vi5302_dev dev);
vi5302_error vi5302_start_continuous_measure(vi5302_dev dev);
vi5302_error vi5302_stop_continuous_measure(vi5302_dev dev);
vi5302_error vi5302_get_measure_data(vi5302_dev dev);
vi5302_error vi5302_get_interrupt_state(vi5302_dev dev, uint8_t *stat);
vi5302_error vi5302_chip_init(vi5302_dev dev);
vi5302_error vi5302_start_xtalk_calibration(vi5302_dev dev);
vi5302_error vi5302_start_offset_calibration(vi5302_dev dev, uint32_t param);
vi5302_error vi5302_get_xtalk_parameter(vi5302_dev dev);
vi5302_error vi5302_config_xtalk_parameter(vi5302_dev dev);
void vi5302_read_fw_version(vi5302_dev dev);
vi5302_error vi5302_read_chipid(vi5302_dev dev);
vi5302_error vi5302_interrupt_enable(vi5302_dev dev);

#endif

