/* SPDX-License-Identifier: GPL-2.0 */
/*
 * mipi_test.h
 * header for mipi test
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 */

#ifndef __MIPI_TEST_H__
#define __MIPI_TEST_H__
#include <linux/videodev2.h>

struct __attribute__((packed)) mipi_input_data {
	union {
		u64 args1;
		struct __attribute__((packed)) {
			u8 phy_type;
			u8 settling_time;
			u8 lpvo;
			u8 virtual_channel;
			u16 syncword;
			u8 thermal;
			u8 timeout;
		} para1;
	};
	union {
		u64 args2;
		struct __attribute__((packed)) {
			u16 frame_no;
			u8 dummy_frame;
			u16 xsize;
			u16 ysize;
			struct {
				u8 save_in_ddr : 1;
				u8 need_avrg : 1;
				u8 need_h_avrg : 1;
				u8 need_v_avrg : 1;
				u8 need_std : 1;
				u8 need_orig : 1;
				u8 resv : 2;
			};
		} para2;
	};
	union {
		u64 args3;
		struct __attribute__((packed)) {
			u8 data_type;
			u8 resv[7];
		} para3;
	};
	union {
		u64 args4;
		struct __attribute__((packed)) {
			u8 path_length;
			u8 path_start; // real max leanth is 7 + 8 + 8
		} para4;
	};
	u64 args5;
	u64 args6;
};

enum MIPI_RX_HANDLE {
	MIPI_RX_TEST = 0,
	MIPI_RX_MAX = 1,
};

enum MIPI_GPIO_INDEX {
	MIPI_GPIO_TEST_FINISH = 0,
	MIPI_GPIO_IRQ = 1,
	MIPI_GPIO_PHY0_OK = 2,
	MIPI_GPIO_PHY1_OK = 3,
	MIPI_GPIO_SOC_TEMPERATURE = 4,
	MIPI_GPIO_NUM,
};

typedef int (*mipi_handle)(void);
struct mipi_test_cfg {
	int data;
	struct mipi_input_data input_data;
};
#define MIPI_TEST_IOCTL_CFG _IOWR('V', BASE_VIDIOC_PRIVATE + 2, struct mipi_test_cfg)
enum MIPI_TEST_CMD {
	MIPI_TEST_CAMERA_READY = 1000,
	MIPI_TEST_QUERY,
	MIPI_TEST_FINISH,
	MIPI_TEST_PHY0_TEST_OK,
	MIPI_TEST_PHY1_TEST_OK,
};
#endif
