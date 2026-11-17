/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
 * Description: als para table camals source file
 * Author: chenxu c30072497
 * Create: 2025-06-05
 */

#include "als_para_table_camals.h"

#include <linux/err.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/slab.h>
#include <linux/types.h>

#include <securec.h>

#include "als_tp_color.h"
#include "contexthub_boot.h"
#include "contexthub_route.h"

static camals_als_para_table camals_als_para_diff_table[] = {
	{ OTHER, OTHER, DEFAULT_TPLCD, OTHER,
		{0, 10,  100, 1000,  10000,  20000,  30000,  40000, 50000, 65535, //10 vga_lux
		 0, 10,  100, 1000,  10000,  20000,  30000,  40000, 50000, 65535, //10 vga_lux
		 0, 10,  100, 1000,  10000,  20000,  30000,  40000, 50000, 65535, //10 als_lux 
		 0, 10,  100, 1000,  10000,  20000,  30000,  40000, 50000, 65535, //10 als_lux 
		 0, 10,  100, 1000,  10000,  20000,  30000,  40000, 50000, 65535, //10 nor_lux
		 0, 10,  100, 1000,  10000,  20000,  30000,  40000, 50000, 65535  //10 nor_lux
		}
	},
	{ MIA, V3, DEFAULT_TPLCD, OTHER,
		{0, 50, 300, 800, 1000, 1500, 10000, 20000, 40000, 40000, //10 vga_lux
		 0, 38,  90, 300,  350,  450,  2200,  4500, 65535, 65535, //10 vga_lux
		 0, 40, 100, 3000, 4000, 5000,  8000, 12000, 15000, 20000, //10 als_lux 
		 0, 29,  79, 2380, 3400, 5000, 10000, 20000, 30000, 65535, //10 als_lux 
		 0, 200, 6500, 10000, 15000, 20000, 40000, 40000, 40000, 40000, //10 nor_lux
		 0,  60, 2030,  2500,  3800,  4500, 65535, 65535, 65535, 65535  //10 nor_lux
		}
	},
	{ PSN, OTHER, DEFAULT_TPLCD, OTHER,
		{0, 50, 100, 200, 300, 500, 1000, 2000, 5000, 40000, //10 vga_lux
		 0, 50, 150, 300, 450, 700, 1300, 2400, 5500, 44000, //10 vga_lux
		 0, 50, 100, 200, 300, 500, 1000, 2000, 5000, 40000, //10 als_lux 
		 0, 50, 120, 260, 380, 600, 1000, 1800, 4500, 44000, //10 als_lux 
		 0, 50, 100, 200, 300, 500, 1000, 2000, 5000, 40000, //10 nor_lux
		 0, 50, 180, 360, 490, 640, 1000, 2000, 5000, 40000  //10 nor_lux
		}
	}
};

camals_als_para_table *als_get_camals_table_by_id(uint32_t id)
{
	if (id >= ARRAY_SIZE(camals_als_para_diff_table))
		return NULL;
	return &(camals_als_para_diff_table[id]);
}

camals_als_para_table *als_get_camals_first_table(void)
{
	return &(camals_als_para_diff_table[0]);
}

uint32_t als_get_camals_table_count(void)
{
	return ARRAY_SIZE(camals_als_para_diff_table);
}

