
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2021. All rights reserved.
 * Description: security engine control
 * Create     : 2017/12/30
 */
#ifndef __HICRYPTO_SECENG_CTRL_H__
#define __HICRYPTO_SECENG_CTRL_H__

#include "hicrypto_driver.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_utils.h"

#define seceng_ip_entry(hdev, pret, mid, ip_idx)                        \
	do {                                                            \
		unused(*(pret));                                        \
		*(pret) = seceng_power_vote(hdev, mid, ip_idx, SEC_ON); \
	} while (0)

#define seceng_ip_exit(hdev, pret, mid, ip_idx)                          \
	do {                                                             \
		unused(*(pret));                                         \
		*(pret) = seceng_power_vote(hdev, mid, ip_idx, SEC_OFF); \
	} while (0)

#define seceng_ip_run(hdev, pret, mid, ip_idx, run_func)               \
	do {                                                           \
		int __tmp_ret = err_drv(ERRCODE_UNKNOWN);              \
		seceng_ip_entry(hdev, pret, mid, ip_idx);              \
		if (*(pret) == BSP_RET_OK) {                           \
			*(pret) = run_func;                            \
			seceng_ip_exit(hdev, &__tmp_ret, mid, ip_idx); \
			if (*(pret) == BSP_RET_OK)                     \
				*(pret) = __tmp_ret;                   \
		}                                                      \
	} while (0)

#define seceng_ip_run_no_ret(hdev, mid, ip_idx, run_func)              \
	do {                                                           \
		int __tmp_ret = err_drv(ERRCODE_UNKNOWN);        \
		seceng_ip_entry(hdev, &__tmp_ret, mid, ip_idx);        \
		if (__tmp_ret == BSP_RET_OK) {                         \
			run_func;                                      \
			seceng_ip_exit(hdev, &__tmp_ret, mid, ip_idx); \
			unused(__tmp_ret);                             \
		}                                                      \
	} while (0)

#define seceng_ip_module_run(hdev, pret, ip_idx, run_func) seceng_ip_run(hdev, pret, BSP_THIS_MODULE, ip_idx, run_func)

#define seceng_ree_drv_run(hdev, pret, ip_idx, sid, run_func)               \
	do {                                                                \
		int __drv_ret;                                              \
		*(pret) = osl_section_entry(hdev, sid);                     \
		if (*(pret) == BSP_RET_OK) {                                \
			if ((hdev) != NULL) {      \
				seceng_ip_module_run(hdev, pret, ip_idx, run_func); \
			} else {     \
				*(pret) = err_drv(ERRCODE_UNKNOWN); \
			}     \
			__drv_ret = osl_section_exit(hdev, sid);            \
			if (*(pret) == BSP_RET_OK)                          \
				*(pret) = __drv_ret;                        \
		}                                                           \
	} while (0)

#define seceng_ree_drv_run_no_ret(hdev, mid, ip_idx, sid, run_func)              \
	do {                                                                     \
		int __drv_ret;                                                   \
		__drv_ret = osl_section_entry(hdev, sid);                        \
		if ((__drv_ret) != BSP_RET_OK) {                                 \
			pal_error("ret = " PAL_FMT_HEX "\n", __drv_ret);         \
		} else {                                                         \
			if ((hdev) != NULL) {      \
				seceng_ip_run_no_ret(hdev, mid, ip_idx, run_func);       \
			}      \
			__drv_ret = osl_section_exit(hdev, sid);                 \
			if ((__drv_ret) != BSP_RET_OK)                           \
				pal_error("ret = " PAL_FMT_HEX "\n", __drv_ret); \
		}                                                                \
	} while (0)

#define osl_section_lock_run(hdev, pret, sid, run_func)          \
	do {                                                     \
		int __tmp_ret;                             \
		*(pret) = osl_section_entry(hdev, sid);          \
		if (*(pret) == BSP_RET_OK) {                     \
			*(pret) = run_func;                      \
			__tmp_ret = osl_section_exit(hdev, sid); \
			if (*(pret) == BSP_RET_OK)               \
				*(pret) = __tmp_ret;             \
		}                                                \
	} while (0)

#define osl_section_lock_run_no_ret(hdev, sid, run_func)                    \
	do {                                                                \
		int __tmp_no_ret;                                     \
		osl_section_lock_run(hdev, &__tmp_no_ret, sid, run_func);   \
		if (pal_check(__tmp_no_ret != BSP_RET_OK))                  \
			pal_error("ret = " PAL_FMT_HEX "\n", __tmp_no_ret); \
	} while (0)

void hicrypto_hd_rs_init(void);

void hicrypto_hd_rs_deinit(void);

/**
 * @brief      : vote for engine ip on
 * @param[in]  : mid    module id
 * @param[in]  : ip_idx ip index
 * @param[in]  : onoff  ::SEC_ON is enable; other is disable
 */
int seceng_power_vote(struct hicrypto_device *hdev, unsigned int mid, unsigned int ip_idx, unsigned int onoff);

/**
 * @brief      : when avaiable lock resource
 */
int osl_section_entry(struct hicrypto_device *hdev, unsigned int sid);

/**
 * @brief      : release resource
 */
int osl_section_exit(struct hicrypto_device *hdev, unsigned int sid);

int hicrypto_check_hd_is_busy(void);

int hicrypto_wait_hd_idle(void);
#endif
