/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: security engctrl
 * Create     : 2024/4/13
 */
#include <linux/mutex.h>
#include <linux/delay.h>

#include "hicrypto_eng_ctrl.h"
#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_utils.h"
#include "hicrypto_io.h"

#include "hicrypto_dev_config.h"
#include "hicrypto_dev_data.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE
#define HICRYPTO_WAIT_IO_COMPLETED_TIME 2000000UL

enum hi_hd_crypto_state {
	HI_HD_STATE_UNINIT = 0x0,
	HI_HD_STATE_IDLE = 0x5,
	HI_HD_STATE_BUSY = 0xa,
};

enum hi_hd_crypto_state g_hd_crypto_state = HI_HD_STATE_UNINIT;

static struct mutex g_hd_state_mulock;
static struct mutex g_hd_crypto_mutex;

/**
 * @brief      : vote for engine ip on
 * @param[in]  : mid    module id
 * @param[in]  : ip_idx ip index
 * @param[in]  : onoff  ::SEC_ON is enable; other is disable
 */
int seceng_power_vote(struct hicrypto_device *hdev, unsigned int mid, unsigned int ip_idx, unsigned int onoff)
{
	int ret = err_hal(ERRCODE_UNKNOWN);

	unused(ret);
	/* check power status and doze vote */
	ret = drv_power_config(hdev, mid, ip_idx, onoff);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	if (onoff == SEC_OFF)
		hisi_reg_cfg_deinit(hdev);

	/* ip clock control */
	ret = engctrl_reg_gtclk_cfg(hdev, mid, ip_idx, onoff);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	if (onoff == SEC_ON)
		hisi_reg_cfg_init(hdev);
	return ret;
}

void hicrypto_hd_rs_init(void)
{
	mutex_init(&g_hd_crypto_mutex);
	mutex_init(&g_hd_state_mulock);
}

void hicrypto_hd_rs_deinit(void)
{
	mutex_destroy(&g_hd_crypto_mutex);
}

static void hicrypto_set_hd_crypto_state(enum hi_hd_crypto_state state)
{
	mutex_lock(&g_hd_state_mulock);
	g_hd_crypto_state = state;
	mutex_unlock(&g_hd_state_mulock);
}

/**
 * @brief      : when avaiable lock resource
 */
int osl_section_entry(struct hicrypto_device *hdev, unsigned int sid)
{
	unused(hdev);
	unused(sid);
	mutex_lock(&g_hd_crypto_mutex);
	hicrypto_set_hd_crypto_state(HI_HD_STATE_BUSY);
	return BSP_RET_OK;
}

/**
 * @brief      : release resource
 */
int osl_section_exit(struct hicrypto_device *hdev, unsigned int sid)
{
	unused(hdev);
	unused(sid);
	hicrypto_set_hd_crypto_state(HI_HD_STATE_IDLE);
	mutex_unlock(&g_hd_crypto_mutex);
	return BSP_RET_OK;
}

int hicrypto_check_hd_is_busy(void)
{
	int state = HI_HD_STATE_UNINIT;
	mutex_lock(&g_hd_state_mulock);
	state = g_hd_crypto_state;
	mutex_unlock(&g_hd_state_mulock);
	return (state == HI_HD_STATE_BUSY) ? 1 : 0;
}

int hicrypto_wait_hd_idle(void)
{
	int ret = err_api(ERRCODE_TIMEOUT);
	unsigned int i = 0;
	unsigned int max_try_cnt = 50;

	for (i = 0; i < max_try_cnt; i++) {
		if (hicrypto_check_hd_is_busy()) {
			msleep(2); /* 2: wait 2ms * 50 for hicrypto to finish all jobs */
		} else {
			ret = BSP_RET_OK;
			break;
		}
	}

	return ret;
}