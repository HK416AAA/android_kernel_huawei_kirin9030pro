
/*
 * echub_basp.h
 *
 * driver for echub basp
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef _LINUX_ECHUB_BASP_H
#define _LINUX_ECHUB_BASP_H
 
#include <linux/platform_device.h>

#define BATT_BRAND_NAME_LEN 4
#define BATT_OLD_CELL_BIT 19
#define BATT_OLD_PACK_BIT 20
#define BATT_NEW_CELL_BIT 5
#define BATT_NEW_PACK_BIT 6
struct echub_brand_list {
	char code;
	char name[BATT_BRAND_NAME_LEN];
};

static struct echub_brand_list batt_package_brand[] = {
    {'I', "BIT"},
    {'C', "BCY"},
    {'Y', "BYT"},
    {'G', "BGY"},
    {'B', "BBT"},
    {'D', "BDY"},
    {'A', "BAT"},
    {'K', "BKY"},
    {'N', "BNT"},
    {'H', "BHY"},
    {'S', "BST"},
    {'W', "BWY"},
    {'E', "BET"},    // Add Hopper HBT338 FCL new type
};

static struct echub_brand_list batt_cell_brand[] = {
    {'A', "CAE"},
    {'U', "CUE"},
    {'L', "CLE"},
    {'S', "CSE"},
    {'G', "CGL"},
    {'C', "CCL"},
    {'B', "CBL"},
    {'H', "CHL"},
    {'D', "CDE"},
    {'E', "CEE"},
    {'F', "CFE"},
    {'M', "CME"},
    {'P', "CPL"},
    {'W', "CWL"},
    {'Y', "CYL"},
};

struct device *echub_basp_create_group(void);
void echub_basp_remove_group(struct device *dev);
#endif