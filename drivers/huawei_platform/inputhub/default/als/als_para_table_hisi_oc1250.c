
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024. All rights reserved.
 * Description: als para table tcs3410 source file
 * Author: chenjianchun 30063743
 * Create: 2024-8-19
 */

#include "als_para_table.h"

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

static hisi_oc1250_als_para_table hisi_oc1250_als_para_diff_tp_color_table[] = {
	{ HED, V3, DEFAULT_TPLCD, OTHER,
		{4, // normalized gain
		10266, -8018, 11418, -9930, 1, // screen-off para: c/r/g/b/dgf * 1000
		1,                            // dgf / ratio
		5690, -4716, 2529, -5526, 100,
		100,                        // normalized atime
		1, 20, -1000, 0, 0, 2776, 12000, 0, 0, -317, 1, 20,
		12, 11608, 6299, 4067, 2118, // ratio/(target/ration)c/r/g/b
		4000, 250,
		-1162, 4, -1100, 4, -1514, 4, 1905, 4, 0, 0, // cct matrix 1 x r/g/b/c/w
		-1264, 4, -985, 4, -932, 4, 1831, 4, 0, 0, // cct matrix 1 y r/g/b/c/w
		-1592, 4, -1365, 4, 3697, 4, 1227, 4, 0, 0, // cct matrix 1 z r/g/b/c/w
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0
		}
	},
	{ SGP, V3, BOE_TPLCD, OTHER,
		{ 1024, -31, -333, 1000, 444, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 8633, 7599, 14402, 8509, 4000, 250,
		10781, 3, 3656, 3, 21170, 4, -4606, 4, 0, 0,
		14570, 3, -16300, 4, 9830, 3, -6200, 4, 0, 0,
		-11100, 3, -25000, 4, 25950, 3, -15800, 4, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0 }
	},
	{ SGP, V3, DEFAULT_TPLCD, OTHER,
		{ 1024, 19, 1170, 7795, -366, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 10772, 9275, 18394, 12211, 4000, 250,
		11313, 3, 8044, 4, 4115, 3, -6937, 4, 0, 0,
		11581, 3, -28047, 4, 9133, 3, -8223, 4, 0, 0,
		8110, 3, -14854, 3, 27996, 3, -14406, 4, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0 }
	},
	{ SGU, V3, BOE_TPLCD_B12, OTHER,
		{ 1024, 172, -3434, 13736, -3434, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 10772, 9275, 18394, 12211, 4000, 250,
		10500, 3, 7240, 4, 3703, 3, -18500, 5, 0, 0,
		10423, 3, -25240, 4, 10047, 3, -5020, 4, 0, 0,
		7299, 3, -13369, 3, 25196, 3, -15400, 4, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0 }
	},
};

hisi_oc1250_als_para_table *als_get_hisi_oc1250_table_by_id(uint32_t id)
{
	if (id >= ARRAY_SIZE(hisi_oc1250_als_para_diff_tp_color_table))
		return NULL;
	return &(hisi_oc1250_als_para_diff_tp_color_table[id]);
}

hisi_oc1250_als_para_table *als_get_hisi_oc1250_first_table(void)
{
	return &(hisi_oc1250_als_para_diff_tp_color_table[0]);
}

uint32_t als_get_hisi_oc1250_table_count(void)
{
	return ARRAY_SIZE(hisi_oc1250_als_para_diff_tp_color_table);
}

