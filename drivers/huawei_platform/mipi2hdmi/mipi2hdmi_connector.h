/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#ifndef __MIPI2HDMI_CONNECTOR_H__
#define __MIPI2HDMI_CONNECTOR_H__

#define GPIO_HIGH_VOLTAGE 1
#define GPIO_LOW_VOLTAGE 0

#define MAX_EDID_DATA_SIZE 1024

enum array_index {
    ARRAY_INDEX_0 = 0,
    ARRAY_INDEX_1,
    ARRAY_INDEX_2,
    ARRAY_INDEX_3,
    ARRAY_INDEX_4,
    ARRAY_INDEX_5,
    ARRAY_INDEX_6,
    ARRAY_INDEX_7,
    ARRAY_INDEX_8,
    ARRAY_INDEX_9,
    ARRAY_INDEX_10,
    ARRAY_INDEX_11,
    ARRAY_INDEX_12,
    ARRAY_INDEX_13,
    ARRAY_INDEX_14,
    ARRAY_INDEX_15,
    ARRAY_INDEX_16,
    ARRAY_INDEX_17,
    ARRAY_INDEX_18,
    ARRAY_INDEX_19,
    ARRAY_INDEX_20,
    ARRAY_INDEX_21,
    ARRAY_INDEX_22,
    ARRAY_INDEX_23,
    ARRAY_INDEX_24,
    ARRAY_INDEX_25
};

typedef enum mipi2hdmi_proto_version {
    HDMI_PROTO_VERSION_1DOT4 = 0,
    HDMI_PROTO_VERSION_2DOT0
} MIPI2HDMI_PROTO_VERSION;

struct mipi2hdmi_video_timing {
    uint16_t hfp;
    uint16_t hsa;
    uint16_t hbp;
    uint16_t hactive;
    uint16_t htotal;
    uint16_t vfp;
    uint16_t vsa;
    uint16_t vbp;
    uint16_t vactive;
    uint16_t vtotal;
    uint8_t fps;
    uint8_t vic;
};

struct mipi2hdmi_bridge {
    uint32_t bridge_id;
    int32_t (*on_func)(struct mipi2hdmi_bridge *bridge);
    int32_t (*off_func)(struct mipi2hdmi_bridge *bridge);
    int32_t (*deassert_reset)(struct mipi2hdmi_bridge *bridge);
    int32_t (*read_edid)(struct mipi2hdmi_bridge *bridge, uint8_t *edid, size_t edid_buf_len, uint32_t *edid_len);
    int32_t (*set_display_timing)(struct mipi2hdmi_bridge *bridge, struct mipi2hdmi_video_timing *user_timing);
    int32_t (*enable_i2s)(struct mipi2hdmi_bridge *bridge);
    int32_t (*disable_i2s)(struct mipi2hdmi_bridge *bridge);
    int32_t (*set_hdcp)(struct mipi2hdmi_bridge *bridge, uint8_t mode);
};

struct mipi2hdmi_redriver {
    uint32_t redriver_id;
    int32_t (*configure_func)(struct mipi2hdmi_redriver *redriver, MIPI2HDMI_PROTO_VERSION proto_ver);
};


int32_t mipi2hdmi_register_bridge(struct mipi2hdmi_bridge *bridge);
int32_t mipi2hdmi_unregister_bridge(struct mipi2hdmi_bridge *bridge);
int32_t mipi2hdmi_register_redriver(struct mipi2hdmi_redriver *redriver);
int32_t mipi2hdmi_unregister_redriver(struct mipi2hdmi_redriver *redriver);
int32_t mipi2hdmi_check_online(struct mipi2hdmi_bridge *bridge);

#endif