
/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef __EDP_SYSFS_COMMON_H__
#define __EDP_SYSFS_COMMON_H__
 
#define PANEL_SNCODE_LEN 9
#define HARD_WARE_LEN 9

struct edp_edid_info {
    uint32_t xres;
    uint32_t yres;
    uint32_t fps;
    char sncode[PANEL_SNCODE_LEN];
    char hardwareid[HARD_WARE_LEN];
};

struct edp_tcon_maintenance_info {
    uint16_t vendor;
    uint16_t version;
    unsigned int fps;
    unsigned int driver_lock1;
    unsigned int driver_lock2;
    unsigned int start_time;
    unsigned int mute_state;
    unsigned int demura_state;
    unsigned int dbv;
    unsigned int edprx_err_data1;
    unsigned int edprx_err_data2;
    unsigned int edprx_train_state1;
    unsigned int edprx_train_state2;
    unsigned int edprx_interrupts;
    unsigned int edprx_fps_count;
    unsigned int dpcd_psr_switch;
    unsigned int dpcd_psr_state;
    unsigned int edprx_signal_state;
};

int32_t edp_sysfs_init(struct device *dev);
int parse_edp_info(struct edp_edid_info* edid_info);

#endif /* __EDP_SYSFS_COMMON_H__ */