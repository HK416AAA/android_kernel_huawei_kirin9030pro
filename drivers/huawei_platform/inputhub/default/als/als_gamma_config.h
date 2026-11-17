/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: als gamma config header file
 * Author: linjianpeng <linjianpeng1@huawei.com>
 * Create: 2020-05-25
 */

#ifndef __ALS_GAMMA_CONFIG_H__
#define __ALS_GAMMA_CONFIG_H__

#if ((defined DSS_ALSC_NOISE) || (defined DKMD_ALSC_NOISE))
#include <linux/types.h>

bool als_gamma_param_config(uint32_t tag, uint32_t mipi);
bool threshold_by_product(uint8_t phone_type, uint8_t lcd_type, int32_t tag);
#ifdef DSS_ALSC_NOISE
void als_gamma_set_alpha(uint32_t alpha);
#elif defined DKMD_ALSC_NOISE
void als_gamma_set_alpha(uint32_t alpha, uint32_t panel_id);
#endif
int als_gamma_update_with_alpha(int tag);
#endif

int choose_gamma_data(int *data_xml);
enum als_current_support_gamma {
	GAMMA_12 = 12,
	GAMMA_13,
	GAMMA_14,
	GAMMA_15,
	GAMMA_16,
	GAMMA_17,
	GAMMA_18,
	GAMMA_19,
	GAMMA_20,
	GAMMA_21,
	GAMMA_22,
	GAMMA_23,
	GAMMA_24,
};

#define R_TYPE            		0
#define G_TYPE            		1
#define B_TYPE            		2
#define GAMMA_TYPE_NUM    		3
#define MIPI_HIGHEST			4095
#define MIPI_LOWEST				0
#define G_R						0 // Gamma_R
#define G_G						1 // Gamma_G
#define G_B						2 // Gamma_B
#define GAMMA_DATA_COUNT		3
#define GAMMA_MAX_SEG_LIMIT		4
#define GAMMA_MIN_SEG_LIMIT		1
#define GAMMA_DATA_MAX_LIMIT	24
#define GAMMA_DATA_MIN_LIMIT	12
#define ARRAY_INDEX_0			0
#define ARRAY_INDEX_1			1
#define ARRAY_INDEX_2			2
#define ARRAY_INDEX_3			3
#define GAMMA_ARRAY_COUNT		4
#define GAMMA_MAX_COUNT_LIMIT	16
#define GAMMA_ARRAY_BEGIN		4

extern unsigned short g_als_manual_gamma_xml[GAMMA_MAX_COUNT_LIMIT];
#endif
