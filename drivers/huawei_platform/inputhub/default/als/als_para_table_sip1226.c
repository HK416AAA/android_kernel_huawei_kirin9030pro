/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024. All rights reserved.
 * Description: als para table sip1226 source file
 * Author: lisheng
 * Create: 2024-01-19
 */

#include "als_para_table_sip1226.h"

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

static als_para_normal_table sip1226_als_para_diff_tp_color_table[] = {
	/* add normalization gain issued from the kernel */
	{ PSD, V3, VISI_TPLCD, SIP1226_PARA_SIZE,
		{ 1024, 120, 175, 250, 2000, 1962, 2012, 1979, 1948, 12000, 28000, 4000, 250, 0, 0, 0 }
	},
	{ PSD, V3, BOE_TPLCD_B12, SIP1226_PARA_SIZE,
		{ 1024, 118, 185, 267, 2000, 3201, 3320, 3200, 3204, 7100, 16000, 4000, 250, 0, 0, 0 }
	},
	{ PSD, V3, CSOT_TPLCD, SIP1226_PARA_SIZE,
		{ 1024, 100, 150, 210, 2000, 1152, 1168, 1203, 1249, 18158, 44535, 4000, 250, 0, 0, 0 }
	},
	{ PSD, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 1024, 100, 150, 210, 2000, 1173, 1168, 1229, 1251, 18158, 44535, 4000, 250, 0, 0, 0 }
	},
	{ TLR, V3, BOE_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 106, 165, 220, 2000, 7504, 7906, 7547, 7517, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ TLR, V3, CSOT_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 106, 170, 224, 2000, 7922, 7866, 8040, 7608, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ TLR, V3, VISI_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 121, 191, 248, 2000, 5668, 5952, 6043, 6058, 3500, 8000, 4000, 250, 0, 0, 0 }
	},
	{ TLR, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 128, 95, 150, 220, 2000, 8494, 9132, 8636, 8704, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ GAI, V3, BOE_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 106, 165, 220, 2000, 7504, 7906, 7547, 7517, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ GAI, V3, CSOT_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 106, 170, 224, 2000, 7922, 7866, 8040, 7608, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ GAI, V3, VISI_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 121, 191, 248, 2000, 5668, 5952, 6043, 6058, 3800, 1900, 4000, 250, 0, 0, 0 }
	},
	{ GAI, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 128, 95, 150, 220, 2000, 8494, 9132, 8636, 8704, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ CHZ, V3, BOE_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 110, 171, 228, 2000, 7920, 8531, 8375, 8603, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ CHZ, V3, TM_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 110, 176, 232, 2000, 7597, 8222, 8157, 8341, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	{ CHZ, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 128, 95, 150, 220, 2000, 8494, 9132, 8636, 8704, 2660, 6500, 4000, 250, 0, 0, 0 }
	},
	/* xian platfom add {ALS_GAIN, IR_GAIN, H, A, D, C(8 number lux coefs), als_target, ir_target,
		offset_max, offset_min, als_target_ratio, ir_target_ratio} */
	{ MRT, V3, TM_TPLCD, SIP1226_PARA_SIZE,
		{ 256, 256, 1030, 1650, 2330, 20000, 4678, 4636, 4772, 4661, 4682, 11352, 4000, 250, 10, 1 }
	},
	{ MRT, V3, VISI_TPLCD, SIP1226_PARA_SIZE,
		{ 256, 256, 1140, 1750, 2360, 20000, 4797, 4637, 4635, 4396, 4682, 11352, 4000, 250, 10, 1 }
	},
	{ MRT, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 256, 256, 1052, 1686, 2330, 20000, 4973, 4902, 5037, 4834, 4682, 11352, 4000, 250, 10, 1 }
	},
	{ MNT, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 128, 25, -13, 1, 1, 25, -13, 1, 1, 6, 57, 4, 9366, 2770, 4000, 250 }
	},
	{ PSN, V3, BOE_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 128, 1060, 1650, 2200, 20000, 7517, 7547, 7906, 7504, 2660, 6500, 4000, 250, 10, 1 }
	},
	{ PSN, V3, CSOT_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 128, 1060, 1700, 2240, 20000, 7608, 8040, 7866, 7922, 2660, 6500, 4000, 250, 10, 1 }
	},
	{ PSN, V3, VISI_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 128, 1210, 1910, 2480, 20000, 6058, 6043, 5952, 5668, 3500, 8000, 4000, 250, 10, 1 }
	},
	{ PSN, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 128, 128, 1060, 1700, 2240, 20000, 7608, 8040, 7866, 7922, 2660, 6500, 4000, 250, 10, 1 }
	},
	{ SUP, V3, TM_TPLCD, SIP1226_PARA_SIZE,
		{ 256, 256, 1300, 2040, 2660, 20000, 6212, 6093, 6263, 5755, 3750, 8200, 4000, 250, 10, 1 }
	},
	{ SUP, V3, BOE_TPLCD, SIP1226_PARA_SIZE,
		{ 256, 256, 1196, 1861, 2473, 20000, 8133, 8175, 8296, 8197, 2900, 6400, 4000, 250, 10, 1 }
	},
	{ SUP, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 256, 256, 1220, 1920, 2490, 20000, 5393, 5317, 5443, 5156, 3750, 8200, 4000, 250, 10, 1 }
	},
	{ KLE, V3, VISI_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 128, 1198, 1892, 2497, 20000, 12610, 12291, 12300, 11791, 18024, 4047, 4000, 250, 1, 1 }
	},
	{ KLE, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 128, 128, 1198, 1892, 2497, 20000, 12610, 12291, 12300, 11791, 18024, 4047, 4000, 250, 1, 1 }
	},
	{ SLY, V3, VISI_TPLCD, SIP1226_PARA_SIZE,
		{ 128, 128, 1198, 1892, 2497, 20000, 12610, 12291, 12300, 11791, 18024, 4047, 4000, 250, 1, 1 }
	},
	{ SLY, V3, TS_PANEL_UNKNOWN, SIP1226_PARA_SIZE,
		{ 128, 128, 1198, 1892, 2497, 20000, 12610, 12291, 12300, 11791, 18024, 4047, 4000, 250, 1, 1 }
	},
};

als_para_normal_table *als_get_sip1226_table_by_id(uint32_t id)
{
	if (id >= ARRAY_SIZE(sip1226_als_para_diff_tp_color_table))
		return NULL;
	return &(sip1226_als_para_diff_tp_color_table[id]);
}

als_para_normal_table *als_get_sip1226_first_table(void)
{
	return &(sip1226_als_para_diff_tp_color_table[0]);
}

uint32_t als_get_sip1226_table_count(void)
{
	return ARRAY_SIZE(sip1226_als_para_diff_tp_color_table);
}
