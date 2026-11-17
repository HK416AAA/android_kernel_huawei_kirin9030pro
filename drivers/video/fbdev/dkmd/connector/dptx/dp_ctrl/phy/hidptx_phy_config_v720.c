/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/kernel.h>
#include "dp_phy_config_interface.h"
#include "dp_ctrl.h"
#include "dp_drv.h"
#include "dpu_dp_dbg.h"
#include "drm_dp_helper_additions.h"
#include <linux/platform_drivers/usb/chip_usb.h>

#define pmac_pll1_rate_coef0(n) (0x4C40 + 0x10 * (n))
#define pmac_pll1_rate_coef1(n) (0x4C44 + 0x10 * (n))
#define pmac_pll1_rate_coef2(n) (0x4C48 + 0x10 * (n))

#define PMAC_PLL1_SSCG0 0x4C18
#define REG_PLL1_SSCG_EN BIT(0)

/* pre sw */
#define txdrvctrl(n) (0x2000 + 0x0400 * (n) + 0x314)
#define txeqcoeff(n) (0x2000 + 0x0400 * (n) + 0x318)

#define AUX_EYE_LEVEL 0x3
#define AUX_HYS_TUNE_VAL 0x1
#define AUX_CTRL_VAL 0x3
#define DPTX_DP_AUX_CTRL 0x20
/* aux disreset */
#define REG_DP_AUX_PWDNB BIT(9)
/* eye diagram */
#define AUX_RTERMSEL_MASK GENMASK(2, 0)
#define AUX_NEN_RTERM_MASK BIT(3)
#define REG_DP_AUX_AUX_CTRL_MASK GENMASK(7, 4)
#define AUX_CTRL_OFFSET 4
#define REG_DP_AUX_AUX_HYS_TUNE_MASK GENMASK(11, 10)
#define AUX_HYS_TUNE_OFFSET 10
#define REG_DP_AUX_RONSELN_MASK GENMASK(14, 12)
#define AUX_RONSELN_OFFSET 12
#define REG_DP_AUX_RONSELP_MASK GENMASK(18, 16)
#define AUX_RONSELP_OFFSET 16

static int dptx_mapping_phylane(uint32_t lane, int plug_type,
	uint16_t *txdrvctrl, uint16_t *txeqcoeff)
{
	uint32_t i;
	uint8_t phylane = 0;

	if (lane < 0 || lane > 3) {
		dpu_pr_err("[DP] lane number error!\n");
		return -EINVAL;
	}

	if (plug_type == DP_PLUG_TYPE_NORMAL) {
		*txdrvctrl = 0X100C + lane * 0x100;
		*txeqcoeff = 0X1010 + lane * 0x100;
	} else {
		*txdrvctrl = 0X130C - lane * 0x100;
		*txeqcoeff = 0X1310 - lane * 0x100;
	}

	return 0;
}

static int dptx_config_swing_and_preemphasis(struct dp_ctrl *dptx, uint32_t sw_level, uint32_t pe_level,
	uint16_t txdrvctrl, uint16_t txeqcoeff)
{
	uint32_t offset = 0;
	uint32_t index0, index1;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!\n");

	if (dptx->connector->conn_info->base.fpga_flag)
		return 0;

	/**
	 * @brief The index value is in line with the following rules:
	 * (sw_level, pe_level) --> (0, 0 ~ 3) --> index0=0,2,4,6 index1=1,3,5,7
	 * (sw_level, pe_level) --> (1, 0 ~ 2) --> index0=8,10,12 index1=9,11,13
	 * (sw_level, pe_level) --> (2, 0 ~ 1) --> index0=14,16 index1=15,17
	 * (sw_level, pe_level) --> (3, 0    ) --> index0=18 index1=19
	 */
	if ((sw_level > 3) || (pe_level > 3) || (pe_level > 4 - sw_level)) {
		dpu_pr_err("[DP] Don't support sw %d & ps level %d\n", sw_level, pe_level);
		return -1;
	}

	index0 = sw_level * 8 + pe_level * 2;
	index1 = sw_level * 8 + pe_level * 2 + 1;
	while (sw_level-- > 0)
		offset += sw_level * 2;
	index0 = index0 - offset;
	index1 = index1 - offset;
	outp32(dptx->combo_phy_base + txdrvctrl, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0]);
	outp32(dptx->combo_phy_base + txeqcoeff, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1]);

	dpu_pr_info("[DP] combophy_pree_swing[0][%d]: 0x%x, combophy_pree_swing[0][%d]: 0x%x \n",
		index0, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0],
		index1, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1]);

	return 0;
}

void dptx_combophy_set_preemphasis_swing(struct dp_ctrl *dptx,
	uint32_t lane, uint32_t sw_level, uint32_t pe_level)
{
	uint16_t txdrvctrl = 0;
	uint16_t txeqcoeff = 0;
	int ret;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	ret = dptx_mapping_phylane(lane, dptx->dptx_plug_type, &txdrvctrl, &txeqcoeff);
	if (ret)
		return;
	ret = dptx_config_swing_and_preemphasis(dptx, sw_level, pe_level, txdrvctrl, txeqcoeff);
	if (ret)
		return;
}

void dptx_aux_disreset(struct dp_ctrl *dptx, bool enable)
{
	uint32_t reg;
	dpu_check_and_no_retval(!dptx, err, "[DP] NULL Pointer\n");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;
	if (!dptx->dptx_enable) {
		dpu_pr_warn("connector is not present!\n");
		return;
	}
	/* Enable AUX Block */
	if (g_dp_debug_mode_enable) {
		reg = (uint32_t)g_dp_aux_ctrl;
	} else {
		reg = (uint32_t)inp32(dptx->combo_phy_base + DPTX_DP_AUX_CTRL);
		if (enable)
			reg |= REG_DP_AUX_PWDNB;
		else
			reg &= ~REG_DP_AUX_PWDNB;

		reg &= ~REG_DP_AUX_RONSELN_MASK;
		reg &= ~REG_DP_AUX_RONSELP_MASK;
		reg &= ~REG_DP_AUX_AUX_HYS_TUNE_MASK;
		reg |= (AUX_HYS_TUNE_VAL << AUX_HYS_TUNE_OFFSET);
		reg &= ~REG_DP_AUX_AUX_CTRL_MASK;
		reg |= (AUX_CTRL_VAL << AUX_CTRL_OFFSET);
		reg &= ~AUX_NEN_RTERM_MASK;
		reg &= ~AUX_RTERMSEL_MASK;
	}
	dpu_pr_info("[DP] DPTX_DP_AUX_CTRL config value: 0x%x\n", reg);
	outp32(dptx->combo_phy_base + DPTX_DP_AUX_CTRL, reg);
	dpu_pr_info("[DP] DPTX_DP_AUX_CTRL get value: 0x%x\n", inp32(dptx->combo_phy_base + DPTX_DP_AUX_CTRL));
	mdelay(1);
}

void dptx_combophy_set_ssc_dis(struct dp_ctrl *dptx, bool ssc_disable)
{
	uint32_t reg;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	reg = 0x01C03FFE;
	if (!ssc_disable)
		reg |= REG_PLL1_SSCG_EN;
	else
		reg &= ~REG_PLL1_SSCG_EN;
	outp32(dptx->combo_phy_base + PMAC_PLL1_SSCG0, reg);
}

void dptx_combophy_set_rate(struct dp_ctrl *dptx, int rate)
{
	uint32_t coef0;
	uint32_t coef1;
	uint32_t coef2;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	switch (rate) {
	case DPTX_PHYIF_CTRL_RATE_RBR:
		if (g_dp_debug_mode_enable) {
			coef0 = g_rbr_pll1_rate0_coef[0];
			coef1 = g_rbr_pll1_rate0_coef[1];
			coef2 = g_rbr_pll1_rate0_coef[2];
		} else {
			coef0 = 0x2A300000;
			coef1 = 0x4E015A62;
			coef2 = 0x0011882A;
		}
		break;
	case DPTX_PHYIF_CTRL_RATE_HBR:
		if (g_dp_debug_mode_enable) {
			coef0 = g_hbr_pll1_rate1_coef[0];
			coef1 = g_hbr_pll1_rate1_coef[1];
			coef2 = g_hbr_pll1_rate1_coef[2];
		} else {
			coef0 = 0x23280000;
			coef1 = 0x4E412262;
			coef2 = 0x00110023;
		}
		break;
	case DPTX_PHYIF_CTRL_RATE_HBR2:
		if (g_dp_debug_mode_enable) {
			coef0 = g_hbr2_pll1_rate2_coef[0];
			coef1 = g_hbr2_pll1_rate2_coef[1];
			coef2 = g_hbr2_pll1_rate2_coef[2];
		} else {
			coef0 = 0x23280000;
			coef1 = 0x4E412262;
			coef2 = 0x00100023;
		}
		break;
	case DPTX_PHYIF_CTRL_RATE_HBR3:
		if (g_dp_debug_mode_enable) {
			coef0 = g_hbr3_pll1_rate3_coef[0];
			coef1 = g_hbr3_pll1_rate3_coef[1];
			coef2 = g_hbr3_pll1_rate3_coef[2];
		} else {
			coef0 = 0x34BC0000;
			coef1 = 0x4E01AA62;
			coef2 = 0x00100834;
		}
		break;
	default:
		dpu_pr_err("[DP] Invalid PHY rate %d\n", rate);
		return;
	}
	outp32(dptx->combo_phy_base + pmac_pll1_rate_coef0(rate), coef0);
	outp32(dptx->combo_phy_base + pmac_pll1_rate_coef1(rate), coef1);
	outp32(dptx->combo_phy_base + pmac_pll1_rate_coef2(rate), coef2);

	dpu_pr_info("[DP] ");
	return;
}

void dptx_phy_layer_init(struct dp_ctrl *dptx)
{
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	dptx->dptx_combophy_set_preemphasis_swing = dptx_combophy_set_preemphasis_swing;
	dptx->dptx_change_physetting_hbr2 = NULL;
	dptx->dptx_combophy_set_ssc_addtions = NULL;
	dptx->dptx_combophy_set_lanes_power = NULL;
	dptx->dptx_combophy_set_ssc_dis = dptx_combophy_set_ssc_dis;
	dptx->dptx_aux_disreset = dptx_aux_disreset;
	dptx->dptx_combophy_set_rate = dptx_combophy_set_rate;
}
