/*
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MM_LB_IMPROVE_YIELD_H
#define __MM_LB_IMPROVE_YIELD_H
#include <platform_include/basicplatform/linux/improve_yield.h>
#include <linux/err.h>
#include "mm_lb_priv_v550.h"
#include <securec.h>

#ifndef abs
#define abs(a) ((a) > 0 ? (a) : -(a))
#endif
#define LB_IY_NV_INFO_MAX_LENGTH 256
#define YIELD_DISABLE 0
#define YIELD_ENABLE  1

typedef enum {
	NV_FLAG,
	SH_FLAG
} flag_type;

typedef union {
	unsigned char value;
	struct {
		unsigned char reserved : 6;       /* bit[0-5] reerved */
		unsigned char nv_flag : 1;        /* bit[6] is pv flag, 1:enable 0:disable */
		unsigned char reserved1 : 1;      /* bit[7] is enabale flag, 1:enable 0:disable */
	} bits;
} improve_yield_peri_nv_t;

typedef union {
	unsigned char value;
	struct {
		unsigned char reserved  : 5; /* bit[0-4] reserved */
		unsigned char sh_flag   : 1; /* bit[5] is sh flag, 1:enable 0:disable */
		unsigned char nv_flag   : 1; /* bit[6] is pv flag, 1:enable 0:disable */
		unsigned char reserved1 : 1; /* bit[7] reserved */
	} bits;
} improve_yield_tra_nv_t;

typedef union {
	unsigned char value;
} improve_yield_lb_volt_t;

typedef union {
	unsigned char value;
	struct {
		unsigned char val : 7;           /* bit[0-6] temp val */
		unsigned char flag : 1;        /* bit[7] 0 means positive sign, 1 means negative sign */
	} bits;
} improve_yield_lb_temp_t;

typedef struct {
    improve_yield_peri_nv_t peri_nv;
    improve_yield_lb_volt_t peri_volt;
	improve_yield_lb_temp_t peri_temp;
} improve_yield_peri_info_t;

#ifdef CONFIG_MM_LB_IMPROVE_YIELD
int get_improve_yield_peri_nv_info(void);
int get_improve_yield_tra_nv_info(flag_type type);
#ifdef CONFIG_FACTORY_MODE
int lb_register_iy_nvme(char *buffer, unsigned int *length);
int set_improve_yield_peri_nv_info(int val);
int set_improve_yield_tra_nv_info(int val, flag_type type);
int set_improve_yield_lb_nv_info(int volt,int temp);
int lb_ecc_improve_yield_handle(void);
#else
static inline int lb_register_iy_nvme(char *buffer __maybe_unused, unsigned int *length __maybe_unused) {return 0;}
static inline int set_improve_yield_peri_nv_info(int val __maybe_unused) {return 0;}
static inline int set_improve_yield_tra_nv_info(int val, flag_type type __maybe_unused) {return 0;}
static inline int set_improve_yield_lb_nv_info(int volt __maybe_unused,int temp __maybe_unused) {return 0;}
static inline int lb_ecc_improve_yield_handle(void){return 0;};
#endif
#else
static inline int get_improve_yield_peri_nv_info(void) {return 0;}
static inline int get_improve_yield_tra_nv_info(flag_type type) {return 0;}
#endif

#endif