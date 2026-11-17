/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine dev ops
 * Create: 2024/04/18
 */
#include <securec.h>

#include "hicrypto_dev_config.h"
#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_utils.h"
#include "hicrypto_io.h"
#include "hicrypto_macro.h"

#include "doze.h"
#include "hicrypto_regs.h"
#include "hicrypto_dev_chip.h"
#include "hicrypto_dev_data.h"
#include "hicrypto_register.h"
#include <linux/arm-smccc.h>
#include "platform_include/see/bl31_smc.h"
#define BSP_THIS_MODULE BSP_MODULE_SCE

static signed int g_ree_gtclk_counter;

#define CRYPTO_SECENG_RST_STATE_MASK 0x00000040 /* bit6 */
#define UNRST_STATE 0
#define SOC_HSDT0_XCTRL_HSDT0_QIC_SYSPDC_PWRD_ACK_OFF (0x428UL)

unsigned int drv_ree_is_rst_state(struct hicrypto_device *hdev)
{
	unused(hdev);
	return 0;
}

int drv_power_config(struct hicrypto_device *hdev, unsigned int mid, unsigned int ip_idx, unsigned int onoff)
{
	unused(ip_idx);
	unused(mid);

	if (onoff != SEC_ON)
		return BSP_RET_OK;

	if (pal_check(drv_ree_is_rst_state(hdev) != 0)) {
		pal_error("error, mspe is reset!\n");
		return err_drv(ERRCODE_SYS);
	}

	return BSP_RET_OK;
}

int engctrl_reg_do_gtclk_cfg(struct hicrypto_device *hdev, unsigned int onoff)
{
	bool b_open_clk;
	bool hsdt0_fm;
	struct arm_smccc_res res = {0};

	/* check */
	if (onoff == SEC_ON) {
		g_ree_gtclk_counter++;
		if (g_ree_gtclk_counter > 1)
			return BSP_RET_OK;
	} else {
		g_ree_gtclk_counter--;
		if (pal_check(g_ree_gtclk_counter < 0))
			g_ree_gtclk_counter = 0;
		if (g_ree_gtclk_counter > 0)
			return BSP_RET_OK;
	}

	/* config */
	if (onoff == SEC_ON) {
		vote_disable_doze(DOZE_CLIENT_MSPE_REE);
		b_open_clk = true;
		hsdt0_fm = true;
		arm_smccc_smc(FID_BL31_CRYPTO_ENGINE_REE_CLK_CTRL, 0, b_open_clk, hsdt0_fm, 0, 0, 0, 0, &res);
		if (pal_check(res.a0 != 0))
			return err_drv(ERRCODE_REQUEST);
		pal_write_u32(HISI_CFG_VALUE_EN_SCE, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_PEREN0));
	} else {
		pal_write_u32(HISI_CFG_VALUE_DIS_SCE, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_PERDIS0));
		vote_enable_doze(DOZE_CLIENT_MSPE_REE);
		b_open_clk = false;
		hsdt0_fm = false;
		arm_smccc_smc(FID_BL31_CRYPTO_ENGINE_REE_CLK_CTRL, 0, b_open_clk, hsdt0_fm, 0, 0, 0, 0, &res);
		if (pal_check(res.a0 != 0))
			return err_drv(ERRCODE_REQUEST);
	}
	return BSP_RET_OK;
}

/**
 * @brief      : config gate clock on or off
 * @param[in]  : mid    module id
 * @param[in]  : ip_idx ip index
 * @param[in]  : onoff  ::SEC_ON is module clock on; other is off
 */
int engctrl_reg_gtclk_cfg(struct hicrypto_device *hdev, unsigned int mid, unsigned int ip_idx, unsigned int onoff)
{
	int ret = err_drv(ERRCODE_UNKNOWN);

	/* on en global clk, off dis global clk */
	unused(mid);
	unused(ip_idx);

	ret = engctrl_reg_do_gtclk_cfg(hdev, onoff);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

void hisi_reg_cfg_init(struct hicrypto_device *hdev)
{
	hisi_reg_sce_rx_gid(hdev, SEC_ON);
	hisi_reg_sce_tx_gid(hdev, SEC_ON);
}

void hisi_reg_cfg_deinit(struct hicrypto_device *hdev)
{
	hisi_reg_sce_rx_gid(hdev, SEC_OFF);
	hisi_reg_sce_tx_gid(hdev, SEC_OFF);
}