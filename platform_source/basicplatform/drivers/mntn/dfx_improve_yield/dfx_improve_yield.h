/* dfx_improve_yield.h
 * improve_yield functions moudle header file
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
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
#ifndef __DFX_IMPROVE_YIELD_H__
#define __DFX_IMPROVE_YIELD_H__
#include <linux/types.h>

#define YIELD_DISABLE 0
#define YIELD_ENABLE 1
#define PVFLAG_DISABLE 0
#define PVFLAG_ENABLE 1
#define YIELD_MAX_RECORD 64

#ifndef BITS
#define BITS(x)  (1 << (x))
#endif

#define EXCEP_SUBTYPE_ANY	0x5A5A // any subtype will match
struct excep_type_and_subtype {
	u32	reboot_type;
	u32	exce_subtype;
};

typedef enum {
  RTB_PV_FLAG_CLUSTER0_ECC = 0,
  RTB_PV_FLAG_CLUSTER1_ECC,
  RTB_PV_FLAG_CLUSTER2_ECC,
  RTB_PV_FLAG_GPU,
  RTB_PV_FLAG_VDEC,
  RTB_PV_FLAG_CLUSTER0_PANIC,
  RTB_PV_FLAG_CLUSTER1_PANIC,
  RTB_PV_FLAG_CLUSTER2_PANIC,
  RTB_PV_FLAG_MAX,
} PvFlagEnableType;

typedef union {
	unsigned char value;
	struct {
		unsigned char count         :  3; /* bit[0-2] panic count */
		unsigned char reserved      :  5; /* bit[3-7] reserved */
	} bits;
} improve_yield_app_panic_nv_p;
 
typedef struct {
	improve_yield_app_panic_nv_p app_panic_info;
} improve_yield_app_nv_p;
#define PRINT_FUNC_AND_LINE pr_err("%s %d\n", __func__, __LINE__)
#if defined(CONFIG_DFX_IMPROVE_YIELD) && defined(CONFIG_FACTORY_MODE)


char *get_iy_category_name(void);
bool is_soc_exc_need_improve_yield(void);
bool is_app_panic_need_improve_yield(void);
#endif
int get_iy_diaginfo(char *out_buf, size_t buf_size);
#endif

