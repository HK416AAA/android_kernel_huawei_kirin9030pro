/*
 *
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
#include "mm_lb_improve_yield.h"

#ifdef CONFIG_MM_LB_IMPROVE_YIELD
#define PERI_TEMP_FACTOR 1000
#define PERI_500MV 500
#define PERI_5MV 5

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

int get_improve_yield_peri_nv_info(void)
{
	int ret;
	improve_yield_peri_nv_t peri_nv_info = {0};

#if defined(CONFIG_IMPROVE_YIELD) && defined(CONFIG_FACTORY_MODE)
	if (is_module_improve_yield_enable(MODULE_ID_PERI) == YIELD_DISABLE) {
		lb_print(LB_ERROR,"peri yield disable\n");
		return -1;
	}
#endif

	ret = get_improve_yield_nv_info(MODULE_ID_PERI, (char *)&peri_nv_info, sizeof(improve_yield_peri_nv_t));
	if(ret) {
		lb_print(LB_ERROR, "get failed,ret:%d\n",ret);
		return -1;
	}

	return peri_nv_info.bits.nv_flag;
}

int get_improve_yield_tra_nv_info(flag_type type)
{
	int ret;
	improve_yield_tra_nv_t tra_nv_info = {0};

	ret = get_improve_yield_nv_info(MODULE_ID_TRA, (char *)&tra_nv_info, sizeof(improve_yield_tra_nv_t));
	if (ret) {
		lb_print(LB_ERROR, "get failed,ret:%d\n", ret);
		return -1;
	}

	if (type == NV_FLAG) {
		return tra_nv_info.bits.nv_flag;
	} else {
		return tra_nv_info.bits.sh_flag;
	}
}
#endif

#if defined(CONFIG_MM_LB_IMPROVE_YIELD) && defined (CONFIG_FACTORY_MODE)
int lb_register_iy_nvme(char *buffer, unsigned int *length)
{
	int ret;
	int result;
	improve_yield_peri_info_t iy_peri_info;
	improve_yield_tra_nv_t    tra_info;

	if (buffer == NULL || length == NULL) {
		lb_print(LB_ERROR, "buffer or length is NULL\n");
		return -1;
	}

	if (is_module_improve_yield_enable(MODULE_ID_PERI) == YIELD_DISABLE) {
		lb_print(LB_ERROR,"peri yidld disable\n");
		return -1;
	}

	ret = get_improve_yield_nv_info(MODULE_ID_PERI, (char *)&iy_peri_info, sizeof(improve_yield_peri_info_t));
	if (ret) {
		lb_print(LB_ERROR, "get peri yield failed\n");
		return -1;
	}

	ret = get_improve_yield_nv_info(MODULE_ID_TRA, (char *)&tra_info, sizeof(improve_yield_tra_nv_t));
	if (ret) {
		lb_print(LB_ERROR, "get tra yield failed\n");
		return -1;
	}

	if (iy_peri_info.peri_nv.bits.nv_flag == 0) {
		lb_print(LB_ERROR, "peri rtb test pass, no need improve yield");
		*length = 0;
		return 0;
	}

	ret = sprintf_s(buffer, LB_IY_NV_INFO_MAX_LENGTH,
                "LB=flag:0x%x,peri_temp:0x%x,peri_volt:0x%x;",
                iy_peri_info.peri_nv.bits.nv_flag,
                iy_peri_info.peri_temp.value,
                iy_peri_info.peri_volt.value);
	if (ret == -1) {
		lb_print(LB_ERROR, "snprintf_s vdec nv info fail");
		return -1;
	}

	if (tra_info.bits.nv_flag == 0) {
		lb_print(LB_ERROR, "tra test pass, no need improve yield");
		*length = (ret > LB_IY_NV_INFO_MAX_LENGTH) ? LB_IY_NV_INFO_MAX_LENGTH : ret;
		return 0;
	}

	result = sprintf_s(buffer + ret, LB_IY_NV_INFO_MAX_LENGTH - ret,
                 "tra_flag:0x%x;", tra_info.bits.nv_flag);
	if (result == -1) {
		lb_print(LB_ERROR, "snprintf_s tra nv info fail");
		return -1;
	}

	ret += result;
	*length = (ret > LB_IY_NV_INFO_MAX_LENGTH) ? LB_IY_NV_INFO_MAX_LENGTH : ret;
	return 0;
}

int set_improve_yield_peri_nv_info(int val)
{
	int ret;
	improve_yield_peri_nv_t peri_nv_info = {0};

	if (is_module_improve_yield_enable(MODULE_ID_PERI) == YIELD_DISABLE) {
		lb_print(LB_ERROR,"peri yidld disable\n");
		return -1;
	}

	peri_nv_info.bits.nv_flag = val;

	ret = set_improve_yield_nv_info(MODULE_ID_PERI, (char *)&peri_nv_info, sizeof(improve_yield_peri_nv_t));
	if (ret) {
		lb_print(LB_ERROR, "set failed\n");
		return -1;
	}

	return 0;
}

int set_improve_yield_lb_nv_info(int volt,int temp)
{
	int ret;
	int t = temp / PERI_TEMP_FACTOR;
	improve_yield_peri_info_t peri_info = {0};

	if (is_module_improve_yield_enable(MODULE_ID_PERI) == YIELD_DISABLE) {
		lb_print(LB_ERROR,"peri yidld disable\n");
		return -1;
	}

	peri_info.peri_nv.bits.nv_flag = get_improve_yield_peri_nv_info();
	/* volt nv 1 byte, temp 1 byte */
	peri_info.peri_volt.value = (volt - PERI_500MV) / PERI_5MV;
	peri_info.peri_temp.bits.val = abs(t);
	peri_info.peri_temp.bits.flag = (t < 0) ? 1 : 0;

	ret = set_improve_yield_nv_info(MODULE_ID_PERI, (char *)&peri_info, sizeof(improve_yield_peri_info_t));
	if (ret) {
		lb_print(LB_ERROR, "set failed,ret:%d\n", ret);
		return -1;
	}

	return 0;
}

int lb_ecc_improve_yield_handle(void)
{
	int result;

	/* Check if the system has already rebooted */
	if(lbdev->improve_yield_en == 1)
		return FALSE;

	result = get_improve_yield_peri_nv_info();
	if (result == -1) {
		lb_print(LB_ERROR, "get improve yield peri nv info failed\n");
        return FALSE;
    } else if (result == 1) {
		/* when peri yield is enable and sys has been reboot, 1bit ecc still happened */
		set_improve_yield_lb_nv_info(lbdev->ecc_peri_volt,lbdev->ecc_peri_temp);
		return TRUE;
	} else {
		/* eri yield is disable */
		lbdev->improve_yield_en = 1;
		set_improve_yield_peri_nv_info(YIELD_ENABLE);
		return FALSE;
	}
}

int set_improve_yield_tra_nv_info(int val, flag_type type)
{
	int ret;
	improve_yield_tra_nv_t tra_nv_info = {0};

	if (type == NV_FLAG) {
		tra_nv_info.bits.nv_flag = val;
	} else {
		tra_nv_info.bits.sh_flag = val;
	}
	ret = set_improve_yield_nv_info(MODULE_ID_TRA, (char *)&tra_nv_info, sizeof(improve_yield_tra_nv_t));
	if (ret) {
		lb_print(LB_ERROR, "failed to set improve yield nv info\n");
		return -1;
	}

	return 0;
}
#endif