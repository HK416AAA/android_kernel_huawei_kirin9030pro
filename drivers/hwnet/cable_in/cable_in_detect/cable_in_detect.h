/*
 * Copyright (c) Huawei Technologies Co., Ltd. 1998-2019. All rights reserved.
 *
 * File name: cable_in_detect.c
 * Description: This program detect the cable_in status
 * Author: zhangjunsheng
 * Version: 1.0
 * Date:  2023/09/07
 *
 */
#ifndef _CABLE_IN_DETECT_
#define _CABLE_IN_DETECT_
#include <linux/device.h>

struct cable_in_info {
	struct device *dev;
};

#endif
