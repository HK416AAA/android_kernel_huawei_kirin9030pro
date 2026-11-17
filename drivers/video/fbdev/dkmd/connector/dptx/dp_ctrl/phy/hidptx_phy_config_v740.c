/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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
#include "dp_ctrl_config.h"
#include "dp_drv.h"
#include "dpu_dp_dbg.h"
#include "drm_dp_helper_additions.h"
#include <linux/platform_drivers/usb/chip_usb.h>
#include "dp_ctrl_config.h"
#include "hidptx/hidptx_reg.h"

#define txdrvatt(n)				(0x091c + (n) * 0x200)
#define txdeemphctl(n)			(0x08f0 + (n) * 0x200)

#define txhfatt(n)     (0x1024 + (n) * 0x100)
#define txhfsst_v36(n) (0x1040 + (n) * 0x100)
#define txhfvbstlsb 16
#define txhfpostlsb 25

#define RTERMK_V48_RES  0x4808
#define txhfatt_dptx(n)     (0x1010 + (n) * 0x100)
#define txhfsst_dptx(n)     (0x100c + (n) * 0x100)
#define txhfsst_hight_dptx(n)  (0x0104 + (n) * 0x10)

#define pll1_ckg_ctrl(n)		(0x02e4 + 0x08 * (n))
#define pll1_sscg_initial(n)	(0x0330 + 0x0c * (n))
#define pll1_sscg_cnt(n)		(0x0334 + 0x0c * (n))
#define pll1_sscg_cnt2(n)		(0x0338 + 0x0c * (n))

#define pll1_ckpll_div(n)        (0x4c30 + 0x20 * (n))
#define pll1_div_sel(n)          (0x4c34 + 0x20 * (n))
#define pll1_sscg_initial(n)     (0x4c38 + 0x20 * (n))
#define pll1_sscg_stepsize(n)    (0x4c40 + 0x20 * (n))
#define pll1_sscg_stepnum(n)     (0x4c3c + 0x20 * (n))

#define pll1_rate_cofe0(n)    (0x4c40 + 0x10 * (n))
#define pll1_rate_cofe1(n)    (0x4c44 + 0x10 * (n))
#define pll1_rate_cofe2(n)    (0x4c48 + 0x10 * (n))
#define pll1_test_data1    0x680c
#define lowband_en         0x0034

#define V48_POSITIVE_CTRL	0x0890
#define V48_NEGATIVE_CTRL	0x0a90
#define V48_CTRL_OFFSET	20

#define AUX_HYS_TUNE_VAL	0x2
#define AUX_CTRL_VAL		0x3

#define PMAC_PLL1_SSCG0 0x032C

#ifdef CHIP_TYPE_CSV2_CSV3
#define REG_PLL1_SSCG_EN BIT(0)
#else
#define REG_PLL1_SSCG_EN BIT(1)
#endif


#define DPTX_DP_AUX_CTRL 0x0024
/* aux disreset */
#define REG_DP_AUX_PWDNB BIT(9)
/* eye diagram */
#define AUX_RTERMSEL 0x6
#define AUX_AUX_CTRL 0x3
#define AUX_RONSELN 0x3
#define AUX_RONSELP 0x3
#define AUX_RTERMSEL_OFFSET 0
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
/* cfg phy speed rate */
#define CFG_PHY_SPEED_RATE_RBR			0x0
#define CFG_PHY_SPEED_RATE_HBR			0x1
#define CFG_PHY_SPEED_RATE_HBR2			0x2
#define CFG_PHY_SPEED_RATE_HBR3			0x3
#define CFG_PHY_SPEED_EDP_RATE_R216		0x4
#define CFG_PHY_SPEED_EDP_RATE_R243		0x5
#define CFG_PHY_SPEED_EDP_RATE_R324		0x6
#define CFG_PHY_SPEED_EDP_RATE_R432		0x7
#define CFG_PHY_SPEED_EDP_RATE_CUSTOM	0x8

/* (plug_type, lane_num) -> (phylane) mapping */
static const struct phylane_mapping g_phylane_mappings[] = {
	{ DP_PLUG_TYPE_NORMAL, 0, 3 },
	{ DP_PLUG_TYPE_NORMAL, 1, 1 },
	{ DP_PLUG_TYPE_NORMAL, 2, 0 },
	{ DP_PLUG_TYPE_NORMAL, 3, 2 },
	{ DP_PLUG_TYPE_FLIPPED, 0, 2 },
	{ DP_PLUG_TYPE_FLIPPED, 1, 0 },
	{ DP_PLUG_TYPE_FLIPPED, 2, 1 },
	{ DP_PLUG_TYPE_FLIPPED, 3, 3 },
};

/* (plug_type, lane_num - 1) -> (phylane) mapping */
static const struct phylane_mapping g_dptxphy_lane_mappings[] = {
	{ DP_PLUG_TYPE_NORMAL, 0, 0 },
	{ DP_PLUG_TYPE_NORMAL, 1, 1 },
	{ DP_PLUG_TYPE_NORMAL, 2, 2 },
	{ DP_PLUG_TYPE_NORMAL, 3, 3 },
	{ DP_PLUG_TYPE_FLIPPED, 0, 3 },
	{ DP_PLUG_TYPE_FLIPPED, 1, 2 },
	{ DP_PLUG_TYPE_FLIPPED, 2, 1 },
	{ DP_PLUG_TYPE_FLIPPED, 3, 0 },
};

static const struct combophy_rate g_combophy_rate_mappings[] = {
	{CFG_PHY_SPEED_RATE_RBR, 0x6546061C, 0x54600000, 0xA900AB, 0x131},
	{CFG_PHY_SPEED_RATE_HBR, 0x64640618, 0x46500000, 0x8C008E, 0x131},
	{CFG_PHY_SPEED_RATE_HBR2, 0x64640615, 0x46500000, 0x8C008E, 0x131},
	{CFG_PHY_SPEED_RATE_HBR3, 0x46960610, 0x69780000, 0xD300D5, 0x131},
	{CFG_PHY_SPEED_EDP_RATE_R216, 0x47080618, 0x70800000, 0xE200E4, 0x131},
	{CFG_PHY_SPEED_EDP_RATE_R243, 0x63F40618, 0x3F480000, 0x7E0080, 0x131},
	{CFG_PHY_SPEED_EDP_RATE_R324, 0x65460618, 0x54600000, 0xA900AB, 0x131},
	{CFG_PHY_SPEED_EDP_RATE_R432, 0x47080614, 0x70800000, 0xE200E4, 0x131},
	{CFG_PHY_SPEED_EDP_RATE_CUSTOM, 0x44100610, 0x69780000, 0xD300D5, 0x131},
};

static const struct combophy_rate_csv2 g_combophy_rate_mappings_csv2[] = {
	{CFG_PHY_SPEED_RATE_RBR,  0x0, 0x0005D130, 0x2A300000, 0x02B, 0x02A, 0x262},
	{CFG_PHY_SPEED_RATE_HBR,  0x0, 0x0005D120, 0x23280000, 0x024, 0x023, 0x262},
	{CFG_PHY_SPEED_RATE_HBR2, 0x0, 0x0005D100, 0x23280000, 0x024, 0x023, 0x262},
	{CFG_PHY_SPEED_RATE_HBR3, 0x0, 0x0005D100, 0x34BC0000, 0x035, 0x034, 0x262},
	{CFG_PHY_SPEED_EDP_RATE_R216, 0x0, 0x0005D130, 0x38400000, 0x038, 0x037, 0x262},
	{CFG_PHY_SPEED_EDP_RATE_R243, 0x0, 0x0005D120, 0x1FA40000, 0x020, 0x01f, 0x262},
	{CFG_PHY_SPEED_EDP_RATE_R324, 0x0, 0x0005D120, 0x2A300000, 0x02b, 0x02a, 0x262},
	{CFG_PHY_SPEED_EDP_RATE_R432, 0x0, 0x003F6100, 0x38400000, 0x038, 0x037, 0x262},
	{CFG_PHY_SPEED_EDP_RATE_CUSTOM, 0x55, 0x003F6100, 0x411AAAAA, 0x041, 0x040, 0x262},
};

static const struct dptx_phy_rate g_dptx_phy_rate_mappings[] = {
	{CFG_PHY_SPEED_RATE_RBR,  0x2A300000, 0x4D415A62, 0x0031882A, 0x10000},
	{CFG_PHY_SPEED_RATE_HBR,  0x23280000, 0x4D412262, 0x00110823, 0x10000},
	{CFG_PHY_SPEED_RATE_HBR2, 0x23280000, 0x4D412262, 0x00100823, 0x10000},
	{CFG_PHY_SPEED_RATE_HBR3, 0x34BC0000, 0x4D41AA62, 0x00500834, 0x0},
	{CFG_PHY_SPEED_EDP_RATE_R216, 0x38400000, 0x4D41C262, 0x00118837, 0x0},
	{CFG_PHY_SPEED_EDP_RATE_R243, 0x1FA40000, 0x4D410262, 0x0011081F, 0x10000},
	{CFG_PHY_SPEED_EDP_RATE_R324, 0x2A300000, 0x4D415A62, 0x0011082A, 0x10000},
	{CFG_PHY_SPEED_EDP_RATE_R432, 0x38400000, 0x4D41C262, 0x00110837, 0x0},
};

static int dptx_mapping_dptxphylane_csv2(int32_t port_id, uint32_t lane, int plug_type,
	uint16_t *txdrvctrl, uint16_t *txeqvbst, uint16_t *txeqvbst_hight)
{
	uint32_t i;
	uint8_t phylane = 0;

	for (i = 0; i < ARRAY_SIZE(g_dptxphy_lane_mappings); i++) {
		if (plug_type == g_dptxphy_lane_mappings[i].plug_type && lane == g_dptxphy_lane_mappings[i].lane) {
			phylane = (uint8_t)g_dptxphy_lane_mappings[i].phylane;
			break;
		}
	}

	if (i == ARRAY_SIZE(g_dptxphy_lane_mappings)) {
		dpu_pr_err("[DP] lane number error!\n");
		return -EINVAL;
	}

	*txdrvctrl = txhfatt_dptx(phylane);
	*txeqvbst = txhfsst_dptx(phylane);
	*txeqvbst_hight = txhfsst_hight_dptx(phylane);
	return 0;
}

static int dptx_mapping_u4phylane_csv2(int32_t port_id, uint32_t lane, int plug_type,
	uint16_t *txdrvctrl, uint16_t *txeqvbst)
{
	uint32_t i;
	uint8_t phylane = 0;

	for (i = 0; i < ARRAY_SIZE(g_phylane_mappings); i++) {
		if (plug_type == g_phylane_mappings[i].plug_type && lane == g_phylane_mappings[i].lane) {
			phylane = (uint8_t)g_phylane_mappings[i].phylane;
			break;
		}
	}

	if (i == ARRAY_SIZE(g_phylane_mappings)) {
		dpu_pr_err("[DP] lane number error!\n");
		return -EINVAL;
	}
	*txdrvctrl = txhfatt(phylane);
	*txeqvbst = txhfsst_v36(phylane);

	return 0;
}

static int dptx_mapping_phylane(uint32_t lane, int plug_type,
	uint16_t *txdrvctrl, uint16_t *txeqvbst)
{
	uint32_t i;
	uint8_t phylane = 0;

	for (i = 0; i < ARRAY_SIZE(g_phylane_mappings); i++) {
		if (plug_type == g_phylane_mappings[i].plug_type && lane == g_phylane_mappings[i].lane) {
			phylane = (uint8_t)g_phylane_mappings[i].phylane;
			break;
		}
	}

	if (i == ARRAY_SIZE(g_phylane_mappings)) {
		dpu_pr_err("[DP] lane number error!\n");
		return -EINVAL;
	}

	*txdrvctrl = txdrvatt(phylane);
	*txeqvbst = txdeemphctl(phylane);

	return 0;
}

static int dptx_get_g_debug_txeqvbst_hight_value_cnt(uint32_t sw_level, uint32_t pe_level)
{
	uint32_t index;
	uint32_t offset = 0;

	index = sw_level * 4 + pe_level;
	while (sw_level-- > 0)
		offset += sw_level;
	index = index - offset;
	return (int)index;
}

static int dptx_config_swing_and_preemphasis_csv2(struct dp_ctrl *dptx, uint32_t sw_level, uint32_t pe_level,
	uint16_t txdrvctrl, uint16_t txeqvbst, uint16_t txeqvbst_hight)
{
	uint32_t offset = 0;
	uint32_t index0, index1, index2;
	uint32_t reg;
	uint32_t i;
	uint32_t txeqvbst_hight_value;
	uint32_t tmp_sw_level = sw_level;

	/**
	 * @brief The index value is in line with the following rules:
	 * (sw_level, pe_level) --> (0, 0 ~ 3) --> index0=0,2,4,6 index1=1,3,5,7
	 * (sw_level, pe_level) --> (1, 0 ~ 2) --> index0=8,10,12 index1=9,11,13
	 * (sw_level, pe_level) --> (2, 0 ~ 1) --> index0=14,16 index1=15,17
	 * (sw_level, pe_level) --> (3, 0    ) --> index0=18 index1=19
	 */
	if ((sw_level > 3) || (pe_level > 3) || (pe_level >= 4 - sw_level)) {
		dpu_pr_info("[DP] Don't support sw %u & ps level %u", sw_level, pe_level);
		sw_level = 2;
		pe_level = 1;
	}
	tmp_sw_level = sw_level;
	index0 = sw_level * 12 + pe_level * 3;
	index1 = sw_level * 12 + pe_level * 3 + 1;
	index2 = sw_level * 12 + pe_level * 3 + 2;
	while (tmp_sw_level-- > 0)
		offset += tmp_sw_level * 3;
	index0 = index0 - offset;
	index1 = index1 - offset;
	index2 = index2 - offset;

	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5) {
		reg = (uint32_t)inp32(dptx->combo_phy_base + RTERMK_V48_RES);
		dpu_pr_info("[DP] RTERMK_V48_RES: %llx\n", reg);
		// bit 13 standby:v48 - 1, v36 - 0
		reg = BIT(13) & reg;
		// v36
		set_reg(dptx->combo_phy_base + txdrvctrl, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0], 4, 4);
		set_reg(dptx->combo_phy_base + txeqvbst, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1], 5, 17);
		set_reg(dptx->combo_phy_base + txeqvbst, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index2], 5, 26);
		// v48
		set_reg(dptx->combo_phy_base + txdrvctrl, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index0], 4, 0);
		set_reg(dptx->combo_phy_base + txeqvbst, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index1], 5, 1);
		set_reg(dptx->combo_phy_base + txeqvbst, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index2], 5, 10);

		if ((sw_level + pe_level) == 3) 
			txeqvbst_hight_value = 1;
		else
			txeqvbst_hight_value = 0;

		if (reg) {
			int cnt = dptx_get_g_debug_txeqvbst_hight_value_cnt(sw_level ,pe_level);
			if (g_dp_debug_mode_enable) {
				txeqvbst_hight_value = g_debug_txeqvbst_hight_value[cnt];
				dpu_pr_info("get g_txeqvbst_hight_value[%d]:%d", cnt, txeqvbst_hight_value);
			}
			dpu_pr_info("v48 mode, sw_level:%d, pe_level:%d", sw_level, pe_level);
			dpu_pr_info("offset:0x%x value:%d", txeqvbst_hight, txeqvbst_hight_value);
			set_reg(dptx->combo_phy_base + txeqvbst_hight, txeqvbst_hight_value, 1, 8);
		}
	} else {
		set_reg(dptx->combo_phy_base + txdrvctrl, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0], 4, 0);
		set_reg(dptx->combo_phy_base + txdrvctrl, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0], 4, 24);
		set_reg(dptx->combo_phy_base + txdrvctrl + 0x4, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0], 4, 0);
		for (i = 0; i < 3; i++) {
			set_reg(dptx->combo_phy_base + txeqvbst + 0x4 * i,
				dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1], 5, 16);
			set_reg(dptx->combo_phy_base + txeqvbst + 0x4 * i  + 0x10,
				dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1], 5, 16);
			set_reg(dptx->combo_phy_base + txeqvbst + 0x4 * i,
				dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index2], 5, 25);
			set_reg(dptx->combo_phy_base + txeqvbst + 0x4 * i  + 0x10,
				dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index2], 5, 25);
		}
	}

	dpu_pr_info("[DP] combophy pree_swing[0][%d]: 0x%x, pree_swing[0][%d]: 0x%x pree_swing[0][%d]: 0x%x\n",
		index0, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0],
		index1, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1],
		index2, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index2]);
	dpu_pr_info("[DP] combophy pree_swing[0][%d]: 0x%x, pree_swing[0][%d]: 0x%x pree_swing[0][%d]: 0x%x\n",
		index0, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index0],
		index1, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index1],
		index2, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index2]);

	return 0;
}

static int dptx_config_swing_and_preemphasis(struct dp_ctrl *dptx, uint32_t sw_level, uint32_t pe_level,
	uint16_t txdrvctrl, uint16_t txeqvbst)
{
	uint32_t offset = 0;
	uint32_t index0, index1;
	uint32_t reg;

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
	if ((sw_level > 3) || (pe_level > 3) || (pe_level >= 4 - sw_level)) {
		dpu_pr_info("[DP] Don't support sw %u & ps level %u", sw_level, pe_level);
		if (dptx->link.rate == DPTX_PHYIF_CTRL_RATE_HBR3 && sw_level == 3 && pe_level == 1) {
			sw_level = 3;
			pe_level = 0;
		} else {
			sw_level = 2;
			pe_level = 1;
		}
	}

	index0 = sw_level * 8 + pe_level * 2;
	index1 = sw_level * 8 + pe_level * 2 + 1;
	while (sw_level-- > 0)
		offset += sw_level * 2;
	index0 = index0 - offset;
	index1 = index1 - offset;
	if (dptx->dptx_plug_type == TYPEC_ORIEN_POSITIVE)
		reg = (uint32_t)inp32(dptx->combo_phy_base + V48_POSITIVE_CTRL);
	else
		reg = (uint32_t)inp32(dptx->combo_phy_base + V48_NEGATIVE_CTRL);

	reg = BIT(20) & reg;
	if (reg) {
		outp32(dptx->combo_phy_base + txdrvctrl, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index0]);
		outp32(dptx->combo_phy_base + txeqvbst, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index1]);
	} else {
		outp32(dptx->combo_phy_base + txdrvctrl, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0]);
		outp32(dptx->combo_phy_base + txeqvbst, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1]);
	}

	dpu_pr_info("[DP] combophy_pree_swing[0][%d]: 0x%x, combophy_pree_swing[0][%d]: 0x%x \n",
		index0, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index0],
		index1, dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][index1]);
	dpu_pr_info("[DP] combophy_pree_swing[1][%d]: 0x%x, combophy_pree_swing[1][%d]: 0x%x",
		index0, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index0],
		index1, dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][index1]);

	return 0;
}

static void dptx_combophy_set_preemphasis_swing(struct dp_ctrl *dptx,
	uint32_t lane, uint32_t sw_level, uint32_t pe_level)
{
	uint16_t txdrvctrl = 0;
	uint16_t txeqvbst = 0;
	uint16_t txeqvbst_hight = 0;
	int ret;
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

#ifdef CHIP_TYPE_CSV2_CSV3
	if (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3)
		ret = dptx_mapping_u4phylane_csv2(dptx->port_id, lane, dptx->dptx_plug_type, &txdrvctrl, &txeqvbst);
	else
		ret = dptx_mapping_dptxphylane_csv2(dptx->port_id, lane,
			dptx->dptx_plug_type, &txdrvctrl, &txeqvbst, &txeqvbst_hight);
	if (ret)
		return;
	ret = dptx_config_swing_and_preemphasis_csv2(dptx, sw_level, pe_level, txdrvctrl, txeqvbst, txeqvbst_hight);
#else
	ret = dptx_mapping_phylane(lane, dptx->dptx_plug_type, &txdrvctrl, &txeqvbst);
	if (ret)
		return;
	ret = dptx_config_swing_and_preemphasis(dptx, sw_level, pe_level, txdrvctrl, txeqvbst);
#endif
	if (ret)
		return;
}

static void dptx_combophy_set_ssc_dis(struct dp_ctrl *dptx, bool ssc_disable)
{
	uint32_t reg;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");
	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	reg = 0x7FF0F0D; // v110 need update
	if (g_dp_debug_mode_enable) {
		reg = dp_debug_get_pll_value();
		dpu_pr_info("[DP] set pll: %llx\n", reg);
	}

	if (!ssc_disable) {
		// enbale ssc
		reg &= ~REG_PLL1_SSCG_EN;
		dpu_pr_info("[DP] dptx_combophy_set_ssc_dis enable ssc : %xll\n", reg);
	} else {
		// disbale ssc
		reg |= REG_PLL1_SSCG_EN;
		dpu_pr_info("[DP] dptx_combophy_set_ssc_dis disable ssc : %xll\n", reg);
	}
	outp32(dptx->combo_phy_base + PMAC_PLL1_SSCG0, reg);
}

static void dptx_combophy_set_ssc_dis_csv2(struct dp_ctrl *dptx, bool ssc_disable)
{
	uint32_t reg;
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");
	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	if (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3)
		reg = 0x00c03fff;
	else
		reg = 0x01c03ffe;

	if (g_dp_debug_mode_enable) {
		reg = dp_debug_get_pll_value();
		dpu_pr_info("[DP] set pll: %llx\n", reg);
	}

	if (!ssc_disable) {
		// enbale ssc
		reg |= REG_PLL1_SSCG_EN;
		dpu_pr_info("[DP] dptx_combophy_set_ssc_dis enable ssc : %xll\n", reg);
	} else {
		// disbale ssc
		reg &= ~REG_PLL1_SSCG_EN;
		dpu_pr_info("[DP] dptx_combophy_set_ssc_dis disable ssc : %xll\n", reg);
	}

	dpu_pr_info("[DP] combo_phy_base 0x4c18 0x4c14 !");
	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5)
		outp32(dptx->combo_phy_base + 0x4c18, reg);
	else
		outp32(dptx->combo_phy_base + 0x4c14, reg);
}

static void dptx_aux_disreset(struct dp_ctrl *dptx, bool enable)
{
	uint32_t reg;
	dp_phy_conf phy_conf;
	struct dp_private *dp_priv = NULL;

	dpu_check_and_no_retval(!dptx, err, "[DP] NULL Pointer\n");
	dpu_check_and_no_retval(dptx_combophy_set_lane_check_param(dptx, dptx->max_lanes, &phy_conf),
		err, "[DP] set_lane check param failed!");
	dp_priv = to_dp_private(dptx->connector->conn_info);
	dpu_check_and_no_retval(!dp_priv, err, "[DP] dp_priv is NULL");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	if (!dptx->dptx_combo_phy_is_up || !dptx->dptx_combo_phy_is_up(dptx))
		return;

	/* Enable AUX Block, default reg: 0x11630 */
	if (g_dp_debug_mode_enable) {
		reg = (uint32_t)dp_debug_get_aux_ctrl_param(dptx);
	} else {
		reg = (uint32_t)inp32(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset);
		dpu_pr_info("[DP] DPTX_DP_AUX_CTRL get value: 0x%x\n", reg);
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

		reg |= (AUX_RTERMSEL << AUX_RTERMSEL_OFFSET);
		reg |= (AUX_AUX_CTRL << AUX_CTRL_OFFSET);
		reg |= (AUX_RONSELN << AUX_RONSELN_OFFSET);
		reg |= (AUX_RONSELP << AUX_RONSELP_OFFSET);

		if (dp_priv->dp_aux_phy_config != 0) {
			reg = dp_priv->dp_aux_phy_config;
			dpu_pr_info("[DP] set aux phy config to 0x%x", reg);
		}
	}
	dpu_pr_info("[DP] DPTX_DP_AUX_CTRL config value: 0x%x\n", reg);
	outp32(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset, reg);
	dpu_pr_info("[DP] DPTX_DP_AUX_CTRL get value: 0x%x\n",
		inp32(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset));
	mdelay(1);
}

static void dptx_aux_disreset_csv2(struct dp_ctrl *dptx, bool enable)
{
	uint32_t reg;
	dp_phy_conf phy_conf;

	dpu_check_and_no_retval(!dptx, err, "[DP] NULL Pointer\n");
	dpu_check_and_no_retval(dptx_combophy_set_lane_check_param(dptx, dptx->max_lanes, &phy_conf),
		err, "[DP] set_lane check param failed!");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;
	if (!dptx->dptx_combo_phy_is_up || !dptx->dptx_combo_phy_is_up(dptx))
		return;
	if (!dptx->dptx_enable) {
		dpu_pr_warn("connector is not present!\n");
		return;
	}
	dpu_pr_info("[DP] +");
	if (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3) {
		reg = 0x22c36;
		if (g_dp_debug_mode_enable) {
			reg = (uint32_t)dp_debug_get_aux_ctrl_param(dptx);
		}
		if (enable)
			reg |= REG_DP_AUX_PWDNB;
		else
			reg &= ~REG_DP_AUX_PWDNB;
		outp32(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset, reg);
		outp32(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET1, reg);
		outp32(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET2, reg);
		outp32(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET3, reg);		
	} else {
		reg = 0x33803;
		if (g_dp_debug_mode_enable) {
			reg = (uint32_t)dp_debug_get_aux_ctrl_param(dptx);
		}
		if (enable)
			reg |= REG_DP_AUX_PWDNB;
		else
			reg &= ~REG_DP_AUX_PWDNB;
		outp32(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset, reg);
	}
	dpu_pr_info("[DP] DPTX_DP_AUX_CTRL get value: 0x%x\n", inp32(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset));
	mdelay(1);
}

static int dptx_get_combophy_rate_csv2(struct dp_ctrl *dptx, int rate, struct combophy_rate_csv2 *combophy_rate)
{
	uint32_t i;
	int ret = 0;

	if (g_dp_debug_mode_enable) {
		ret = dptx_debug_get_combophy_rate_param_csv2(dptx, rate, combophy_rate);
		if (ret != 0) {
			dpu_pr_err("[DP] debug get PHY rate param error, ret = %d", ret);
			return ret;
		}
		return 0;
	}
	for (i = 0; i < ARRAY_SIZE(g_combophy_rate_mappings_csv2); i++) {
		if (rate == g_combophy_rate_mappings_csv2[i].rate_type) {
			combophy_rate->ckplldiv = g_combophy_rate_mappings_csv2[i].ckplldiv;
			combophy_rate->divsel = g_combophy_rate_mappings_csv2[i].divsel;
			combophy_rate->sscginital = g_combophy_rate_mappings_csv2[i].sscginital;
			combophy_rate->sscgstepsize1 = g_combophy_rate_mappings_csv2[i].sscgstepsize1;
			combophy_rate->sscgstepsize2 = g_combophy_rate_mappings_csv2[i].sscgstepsize2;
			combophy_rate->sscgstepnum = g_combophy_rate_mappings_csv2[i].sscgstepnum;
			break;
		}
	}
	return 0;
}

static int dptx_get_dptxphy_rate_csv2(struct dp_ctrl *dptx, int rate, struct dptx_phy_rate *dptx_rate)
{
	uint32_t i;
	int ret = 0;

	if (g_dp_debug_mode_enable) {
		ret = dptx_debug_get_dptxphy_rate_param_csv2(dptx, rate, dptx_rate);
		if (ret != 0) {
			dpu_pr_err("[DP] debug get PHY rate param error, ret = %d", ret);
			return ret;
		}
		return 0;
	}
	for (i = 0; i < ARRAY_SIZE(g_dptx_phy_rate_mappings); i++) {
		if (rate == g_dptx_phy_rate_mappings[i].rate_type) {
			dptx_rate->pll1_cofe0 = g_dptx_phy_rate_mappings[i].pll1_cofe0;
			dptx_rate->pll1_cofe1 = g_dptx_phy_rate_mappings[i].pll1_cofe1;
			dptx_rate->pll1_cofe2 = g_dptx_phy_rate_mappings[i].pll1_cofe2;
			dptx_rate->test_data1 = g_dptx_phy_rate_mappings[i].test_data1;
			break;
		}
	}
	return 0;
}

static int dptx_get_combophy_rate(struct dp_ctrl *dptx, int rate,
	uint32_t *ckgctrl, uint32_t *sscginital, uint32_t *sscgcnt, uint32_t *sscgcnt2)
{
	uint32_t i;
	uint32_t ret = 0;

	if (g_dp_debug_mode_enable) {
		ret = dptx_debug_get_combophy_rate_param(dptx, rate,
			ckgctrl, sscginital, sscgcnt, sscgcnt2);
		if (ret != 0) {
			dpu_pr_err("[DP] debug get PHY rate param error, ret = %u", ret);
			return (int)ret;
		}
		return 0;
	}

	for (i = 0; i < ARRAY_SIZE(g_combophy_rate_mappings); i++) {
		if (rate == g_combophy_rate_mappings[i].rate_type) {
			*ckgctrl = g_combophy_rate_mappings[i].ckgctrl;
			*sscginital = g_combophy_rate_mappings[i].sscginital;
			*sscgcnt = g_combophy_rate_mappings[i].sscgcnt;
			*sscgcnt2 = g_combophy_rate_mappings[i].sscgcnt2;
			break;
		}
	}
	return 0;
}

static void dptx_dptxphy_set_rate(struct dp_ctrl *dptx, int rate)
{
	struct dptx_phy_rate dptx_rate;
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	dptx_get_dptxphy_rate_csv2(dptx, rate, &dptx_rate);

	if (g_dp_debug_mode_enable) {
		outp32(dptx->combo_phy_base + lowband_en, 0x0);
	}
	outp32(dptx->combo_phy_base + pll1_rate_cofe0(rate), dptx_rate.pll1_cofe0);
	outp32(dptx->combo_phy_base + pll1_rate_cofe1(rate), dptx_rate.pll1_cofe1);
	outp32(dptx->combo_phy_base + pll1_rate_cofe2(rate), dptx_rate.pll1_cofe2);
	outp32(dptx->combo_phy_base + pll1_test_data1, dptx_rate.test_data1);

	dpu_pr_info("[DP] rate: %d, pll1_cofe0:0x%llx, pll1_cofe1:0x%llx, pll1_cofe2:0x%llx, test_data1:0x%llx\n",
		rate, dptx_rate.pll1_cofe0, dptx_rate.pll1_cofe1, dptx_rate.pll1_cofe2, dptx_rate.test_data1);

	return;
}

static void dptx_combophy_set_rate_csv2(struct dp_ctrl *dptx, int rate)
{
	struct combophy_rate_csv2 combophy_rate;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	dptx_get_combophy_rate_csv2(dptx, rate, &combophy_rate);

	set_reg(dptx->combo_phy_base + pll1_ckpll_div(rate), combophy_rate.ckplldiv, 8, 0);
	set_reg(dptx->combo_phy_base + pll1_div_sel(rate), combophy_rate.divsel, 32, 0);
	set_reg(dptx->combo_phy_base + pll1_sscg_initial(rate), combophy_rate.sscginital, 32, 0);
	set_reg(dptx->combo_phy_base + pll1_sscg_stepsize(rate), combophy_rate.sscgstepsize1, 11, 0);
	set_reg(dptx->combo_phy_base + pll1_sscg_stepsize(rate), combophy_rate.sscgstepsize2, 11, 16);
	set_reg(dptx->combo_phy_base + pll1_sscg_stepnum(rate), combophy_rate.sscgstepnum, 11, 16);

	dpu_pr_info("[DP] rate: %d, ckpll_div:0x%llx, div_sel:0x%llx",
		rate, combophy_rate.ckplldiv, combophy_rate.divsel);
	dpu_pr_info("sscg_initial:0x%llx, sscg_stepsize1:0x%llx,sscg_stepsize2:0x%llx, sscg_stepnum:0x%llx\n",
		combophy_rate.sscginital, combophy_rate.sscgstepsize1, combophy_rate.sscgstepsize2,combophy_rate.sscgstepnum);
	return;
}

static void dptx_phy_set_rate_csv2(struct dp_ctrl *dptx, int rate)
{
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5)
		dptx_dptxphy_set_rate(dptx, rate);
	else
		dptx_combophy_set_rate_csv2(dptx, rate);
	return;
}

static void dptx_combophy_set_rate(struct dp_ctrl *dptx, int rate)
{
	uint32_t ckgctrl;
	uint32_t sscginital;
	uint32_t sscgcnt;
	uint32_t sscgcnt2;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	if (dptx->connector->conn_info->base.fpga_flag)
		return;

	dptx_get_combophy_rate(dptx, rate,
		&ckgctrl, &sscginital, &sscgcnt, &sscgcnt2);

	outp32(dptx->combo_phy_base + pll1_ckg_ctrl(rate), ckgctrl);
	outp32(dptx->combo_phy_base + pll1_sscg_initial(rate), sscginital);
	outp32(dptx->combo_phy_base + pll1_sscg_cnt(rate), sscgcnt);
	outp32(dptx->combo_phy_base + pll1_sscg_cnt2(rate), sscgcnt2);

	dpu_pr_info("[DP] rate: %d, ckgctrl:0x%x, sscginital:0x%x, sscgcnt:0x%x, sscgcnt2:0x%x",
		rate, ckgctrl, sscginital, sscgcnt, sscgcnt2);
	return;
}

static void dptx_u4phy_rate_pll_init(struct dp_ctrl *dptx)
{
	uint32_t i;
	uint32_t rate;
	dpu_pr_info("[DP]+");
	for (i = 0; i < ARRAY_SIZE(g_combophy_rate_mappings_csv2); i++) {
		rate = g_combophy_rate_mappings_csv2[i].rate_type;
		set_reg(dptx->combo_phy_base + pll1_ckpll_div(rate), g_combophy_rate_mappings_csv2[i].ckplldiv, 8, 0);
		set_reg(dptx->combo_phy_base + pll1_div_sel(rate), g_combophy_rate_mappings_csv2[i].divsel, 2, 4);
		set_reg(dptx->combo_phy_base + pll1_sscg_initial(rate), g_combophy_rate_mappings_csv2[i].sscginital, 32, 0);
		set_reg(dptx->combo_phy_base + pll1_sscg_stepsize(rate), g_combophy_rate_mappings_csv2[i].sscgstepsize1, 11, 0);
		set_reg(dptx->combo_phy_base + pll1_sscg_stepsize(rate), g_combophy_rate_mappings_csv2[i].sscgstepsize2, 11, 16);
		set_reg(dptx->combo_phy_base + pll1_sscg_stepnum(rate), g_combophy_rate_mappings_csv2[i].sscgstepnum, 11, 16);
	}
	return;
}

static void dptx_dptxphy_rate_pll_init(struct dp_ctrl *dptx)
{
	uint32_t i;
	uint32_t rate;
	dpu_pr_info("[DP]+");
	for (i = 0; i < ARRAY_SIZE(g_dptx_phy_rate_mappings); i++) {
		rate = g_dptx_phy_rate_mappings[i].rate_type;
		outp32(dptx->combo_phy_base + pll1_rate_cofe0(rate), g_dptx_phy_rate_mappings[i].pll1_cofe0);
		outp32(dptx->combo_phy_base + pll1_rate_cofe1(rate), g_dptx_phy_rate_mappings[i].pll1_cofe1);
		outp32(dptx->combo_phy_base + pll1_rate_cofe2(rate), g_dptx_phy_rate_mappings[i].pll1_cofe2);
		outp32(dptx->combo_phy_base + pll1_test_data1, g_dptx_phy_rate_mappings[i].test_data1);
	}
	outp32(dptx->combo_phy_base + 0x4808, 0xFFFFFFFF);
	return;
}

static void dptx_phy_rate_pll_init(struct dp_ctrl *dptx)
{
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");
	dpu_pr_info("[DP]init all rate pll+");
	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5)
		dptx_dptxphy_rate_pll_init(dptx);
	else
		dptx_u4phy_rate_pll_init(dptx);
}

void dptx_phy_layer_init(struct dp_ctrl *dptx)
{
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	dptx->dptx_combophy_set_preemphasis_swing = dptx_combophy_set_preemphasis_swing;
	dptx->dptx_change_physetting_hbr2 = NULL;
	dptx->dptx_combophy_set_ssc_addtions = NULL;
	dptx->dptx_combophy_set_lanes_power = NULL;
#ifdef CHIP_TYPE_CSV2_CSV3
	dptx->dptx_combophy_set_ssc_dis = dptx_combophy_set_ssc_dis_csv2;
	dptx->dptx_aux_disreset = dptx_aux_disreset_csv2;
	dptx->dptx_combophy_set_rate = dptx_phy_set_rate_csv2;
	dptx->dptx_phy_rate_pll_init = dptx_phy_rate_pll_init;
#else
	dptx->dptx_combophy_set_ssc_dis = dptx_combophy_set_ssc_dis;
	dptx->dptx_aux_disreset = dptx_aux_disreset;
	dptx->dptx_combophy_set_rate = dptx_combophy_set_rate;
#endif
}
