/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
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

#include "dp_ctrl_config.h"
#include <linux/arm-smccc.h>
#include <linux/gpio.h>
#include <platform_include/display/linux/dpu_dss_dp.h>
#include "hidptx/hidptx_reg.h"
#include "dp_ctrl.h"
#include "controller/dp_avgen_base.h"

static int dptx_ctrl_clk_enable(struct dp_ctrl *dptx)
{
	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");

	/* enable clock */
	if (clk_prepare_enable(dptx->connector->connector_clk[CLK_DPCTRL_16M]) != 0) {
		dpu_pr_err("[DP] enable dpctrl 16m clk failed!\n");
		return -1;
	}

	if (clk_prepare_enable(dptx->connector->connector_clk[CLK_DPCTRL_PCLK]) != 0) {
		dpu_pr_err("[DP] enable dpctrl pclk failed!\n");
		return -1;
	}

	if (clk_prepare_enable(dptx->clk_dpctrl_pixel) != 0) {
		dpu_pr_err("[DP] enable dpctrl pixel clk failed!\n");
		return -1;
	}

	return 0;
}

static void dptx_get_sync_calib_param(struct dp_ctrl *dptx, int stream)
{
	int bpp;
	uint32_t sync_delay;
	uint32_t sync_calib_param = 0;
	uint32_t reg;

	bpp = dptx_get_color_depth(dptx->vparams.bpc, dptx->vparams.pix_enc);
	if (unlikely(bpp == 0)) {
		dpu_pr_err("error, bpp is 0");
		return;
	}
	sync_delay = dptx->link.lanes * 16 * 8 * 8 / (2 * bpp);

	if (sync_delay + 16 >= dptx->vparams.mdtd.h_blanking / 2) {
		sync_calib_param = sync_delay + 64 - dptx->vparams.mdtd.h_blanking / 2 + 32;
		sync_calib_param = sync_calib_param / 2 * 2; /* sync_calib_param has to be even */
	}

	reg = (uint32_t)dptx_readl(dptx, dptx_video_packet_stream(stream));
	reg = reg & (~DPTX_VIDEO_PACKET_TU_SYNC_CALIB_MASK);
	reg = reg | (sync_calib_param << DPTX_VIDEO_PACKET_TU_SYNC_CALIB_SHIFT);
	dptx_writel(dptx, dptx_video_packet_stream(stream), reg);
}

static void dptx_dsc_sample_en(struct dp_ctrl *dptx, int stream)
{
	uint32_t vsamplectrl;
	vsamplectrl = dptx_readl(dptx, dptx_video_ctrl_stream(stream));
	if (dptx->dsc)
		vsamplectrl &= ~DPTX_VIDEO_RGB_SAMPLE_EN;
	else
		vsamplectrl |= DPTX_VIDEO_RGB_SAMPLE_EN;
	dptx_writel(dptx, dptx_video_ctrl_stream(stream), vsamplectrl);
}

static void dptx_config_stream_timing(struct dp_ctrl *dptx)
{
	uint32_t reg;
	struct ldi_panel_info *ldi = NULL;
	struct dkmd_connector_info *pinfo = dptx->connector->conn_info;
	ldi = &dptx->connector->ldi;

	reg = 0;
	reg |= (pinfo->base.yres << DPTX_TIMING_GEN_VACTIVE_SHIFT);
	reg |= (ldi->v_back_porch + ldi->v_front_porch + ldi->v_pulse_width);
	dptx_writel(dptx, dptx_timing_gen_config2_stream(0), reg);
	if (dptx->mst)
		dptx_writel(dptx, dptx_timing_gen_config2_stream(1), reg);

	reg = 0;
	reg |= (ldi->v_front_porch << DPTX_TIMING_GEN_VFP_SHIFT);
	dptx_writel(dptx, dptx_timing_gen_config3_stream(0), reg);
	if (dptx->mst)
		dptx_writel(dptx, dptx_timing_gen_config3_stream(1), reg);
}

static int dptx_combophy_reset(struct dp_ctrl *dptx, bool benable)
{
	struct dpu_connector *connector = NULL;
	struct dp_private *dp_pri = NULL;
	uint32_t reg;
	int ret;
	uint32_t gpio_id = 48;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");
	connector = dptx->connector;
	dp_pri = to_dp_private(connector->conn_info);

	if (dptx->connector->conn_info->base.fpga_flag)
		return 0;

	if (benable) {
		if (dptx->id == MASTER_DPTX_IDX) {
			ret = gpio_request(gpio_id, "dptx_aux_gpio");
			if (ret < 0) {
				dpu_pr_err("[DP] Request gpio-%d fail\n", gpio_id);
				return -EINVAL;
			}
			ret = gpio_direction_output(gpio_id, 0);
			if (ret < 0) {
				dpu_pr_err("[DP] Set gpio-%d output fail\n", gpio_id);
				return -EINVAL;
			}
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 11);
			set_reg(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET, 1, 1, 6);
			set_reg(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET, 1, 1, 14);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 2);
			set_reg(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET, 1, 1, 12);
		} else {
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 10);
			set_reg(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET, 1, 1, 5);
			set_reg(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET, 1, 1, 13);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 1);
			set_reg(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET, 1, 1, 11);
		}

		if (dptx->dptx_plug_type == TYPEC_ORIEN_POSITIVE) {
			set_reg(dptx->combo_phy_base + DPTX_PHY_MODE, DP_NORNAL_MODE, 4, 0);
			gpio_set_value(gpio_id, 0);
		} else if (dptx->dptx_plug_type == TYPEC_ORIEN_NEGATIVE) {
			set_reg(dptx->combo_phy_base + DPTX_PHY_MODE, DP_FLIP_MODE, 4, 0);
			gpio_set_value(gpio_id, 1);
		} else {
			dpu_pr_err("[DP] Error insert type = %d", dptx->dptx_plug_type);
			return -EINVAL;
		}

		if (dptx->max_lanes == 4)
			set_reg(dptx->combo_phy_base + DPTX_PHY_MODE, 0xF, 4, 12);
		else if (dptx->max_lanes == 2)
			set_reg(dptx->combo_phy_base + DPTX_PHY_MODE, 0x3, 4, 12);
		else if (dptx->max_lanes == 1)
			set_reg(dptx->combo_phy_base + DPTX_PHY_MODE, 0x1, 4, 12);

		set_reg(dptx->combo_phy_base + DPTX_PHY_DP_AUX_CTRL, 1, 1, 9);
	} else {
		if (dptx->dptx_enable)
			set_reg(dptx->combo_phy_base + DPTX_PHY_DP_AUX_CTRL, 0, 1, 9);
		if (dptx->id == MASTER_DPTX_IDX) {
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 12);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 2);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 14);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 6);
			gpio_free(gpio_id);
		} else {
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 11);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 1);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 13);
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 5);
		}
	}
	return 0;
}

static int dptx_dis_reset(struct dp_ctrl *dptx, bool benable)
{
	struct dpu_connector *connector = NULL;
	struct dp_private *dp_pri = NULL;
	uint32_t reg;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");
	connector = dptx->connector;
	dp_pri = to_dp_private(connector->conn_info);

	if (benable) {
		reg = inp32(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET);
		if (dptx->id == MASTER_DPTX_IDX) {
			reg |= DPTX_APB_DIS_RESET_BIT;
			reg |= DPTX_DPC_DIS_RESET_BIT;
		} else {
			reg |= DPTX1_APB_DIS_RESET_BIT;
			reg |= DPTX1_DPC_DIS_RESET_BIT;
		}
		outp32(dp_pri->hsdt1_crg_base + DPTX_APB_DIS_RESET_OFFSET, reg);

		if (dptx->connector->conn_info->base.fpga_flag == 0) {
			if (dptx->id == MASTER_DPTX_IDX) {
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 13);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 8);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 4);
				set_reg(connector->peri_crg_base, 1, 1, 7);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 6);
				// can add gpio as hpd signal if using edp
			} else {
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 12);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 7);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 3);
				set_reg(connector->peri_crg_base, 1, 1, 7);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PEREN3, 1, 1, 5);
			}
			reg = dptx_readl(dptx, DPTX_GCTL0);
			reg |= DPTX_HPD_POLARITY_SEL;
			dptx_writel(dptx, DPTX_GCTL0, reg);
		}
	} else {
		if (dptx->id == MASTER_DPTX_IDX)
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 3);
		else
			set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERRSTEN3, 1, 1, 2);

		if (dptx->connector->conn_info->base.fpga_flag == 0) {
			if (dptx->id == MASTER_DPTX_IDX) {
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 8);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 13);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 4);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 6);
			} else {
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 7);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 12);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 3);
				set_reg(dp_pri->hsdt1_crg_base + HSDT1_PERDIS3, 1, 1, 5);
			}
		}
		reg = inp32(dp_pri->hsdt1_crg_base + DPTX_APB_RESET_OFFSET);
		if (dptx->id == MASTER_DPTX_IDX)
			reg |= DPTX_APB_RESET_BIT;
		else
			reg |= DPTX1_APB_RESET_BIT;
		outp32(dp_pri->hsdt1_crg_base + DPTX_APB_RESET_OFFSET, reg);
	}
	return 0;
}

int dptx_pixel_pll_preinit(void)
{
	return 0;
}

int dptx_pixel_pll_init(struct dp_ctrl *dptx, uint64_t pixel_clock)
{
	void_unused(dptx);
	void_unused(pixel_clock);
	return 0;
}

int dptx_pixel_pll_deinit(struct dp_ctrl *dptx)
{
	void_unused(dptx);
	return 0;
}

void enable_dptx_timing_gen(struct dp_ctrl *dptx)
{
	uint32_t val;

	if (unlikely(!dptx)) {
		dpu_pr_warn("dptx is null");
		return;
	}

	dptx_writel(dptx, dptx_dp_color_bar_stream(0), 0);

	if (dptx->dptx_triger_media_transfer)
		dptx->dptx_triger_media_transfer(dptx, true);

	val = dptx_readl(dptx, DPTX_GCTL0);
	val |= DPTX_CFG_TIMING_GEN_ENABLE;
	dptx_writel(dptx, DPTX_GCTL0, val);
}

int32_t init_dp_sctrl(struct dp_private *priv, struct device_node *np)
{
	void_unused(priv);
	void_unused(np);
	return 0;
}

int32_t init_dpctrl_pixel_clk(struct dp_ctrl *dptx0, struct dp_ctrl *dptx1, struct device_node *np)
{
	if (dptx0 != NULL) {
		dptx0->clk_dpctrl_pixel = of_clk_get(np, DPTX0_PIXEL_CLOCK);
		if (IS_ERR_OR_NULL(dptx0->clk_dpctrl_pixel)) {
			dpu_pr_err("[DP] failed to get dptx0 clk_dpctrl_pixel!\n");
			return -ENXIO;
		}
	}
	/* for dual edp-tx */
	if (dptx1 != NULL) {
		dptx1->clk_dpctrl_pixel = of_clk_get(np, DPTX1_PIXEL_CLOCK);
		if (IS_ERR_OR_NULL(dptx1->clk_dpctrl_pixel)) {
			dpu_pr_err("[DP] failed to get dptx1 clk_dpctrl_pixel!\n");
			return -ENXIO;
		}
	}

	return 0;
}

int32_t init_dpctrl_16m_clk(struct dp_ctrl *dptx, struct device_node *np)
{
	void_unused(dptx);
	void_unused(np);
	return 0;
}

int32_t init_hsdt1_sysctrl_base(struct dp_private *priv, struct device_node *np)
{
	void_unused(priv);
	void_unused(np);
	return 0;
}

int32_t init_sub_harden_crg_base(struct dp_private *priv, struct device_node *np)
{
	void_unused(priv);
	void_unused(np);
	return 0;
}

static void dp_disable_clk(struct dp_ctrl *dptx)
{
	/* disable clk */
	clk_disable_unprepare(dptx->connector->connector_clk[CLK_DPCTRL_16M]);
	clk_disable_unprepare(dptx->connector->connector_clk[CLK_DPCTRL_PCLK]);
	clk_disable_unprepare(dptx->clk_dpctrl_pixel);
}

int dp_pm_suspend(struct device *dev)
{
	void_unused(dev);
	return 0;
}

int dp_pm_resume(struct device *dev)
{
	void_unused(dev);
	return 0;
}

int dp_pm_freeze(struct device *dev)
{
	void_unused(dev);
	return 0;
}

void dp_shutdown(struct platform_device *pdev)
{
	void_unused(pdev);
}

void dptx_phy_lane_reset(struct dp_ctrl *dptx, bool mainlink_open)
{
	uint32_t phyifctrl;

	dpu_check_and_no_retval(!dptx, err, "[DP] null pointer");

	phyifctrl = dptx_readl(dptx, DPTX_PHYIF_CTRL1);

	if (mainlink_open) /* P0 mode, disreset lanes */
		phyifctrl = (uint32_t)cfg_phy_lanes(DPTX_MAX_LINK_LANES);
	else
		phyifctrl &= ~cfg_phy_lanes(DPTX_MAX_LINK_LANES);

	dptx_writel(dptx, DPTX_PHYIF_CTRL1, phyifctrl);
}

static void dptx_hdcp_enable_video_transform(struct dp_ctrl *dptx, bool enable)
{
	struct arm_smccc_res res = {0};

	if (dptx->id == MASTER_DPTX_IDX)
		arm_smccc_smc((u64)ACCESS_REGISTER_FN_MAIN_ID_HDCP,
			DSS_HDCP_DP_ENABLE, enable, (u64)ACCESS_REGISTER_FN_SUB_ID_HDCP_CTRL,
			0, 0, 0, 0, &res);
	else
		arm_smccc_smc((u64)ACCESS_REGISTER_FN_MAIN_ID_HDCP,
			DSS_HDCP_DP1_ENABLE, enable, (u64)ACCESS_REGISTER_FN_SUB_ID_HDCP_CTRL,
			0, 0, 0, 0, &res);

	dpu_pr_info("[DP] dptx->id = %d, res.a0 = %ld", dptx->id, res.a0);
	return;
}

void dp_ctrl_config_init(struct dp_ctrl *dptx)
{
	dptx->dptx_get_sync_calib_param = dptx_get_sync_calib_param;
	dptx->dptx_dsc_sample_en = dptx_dsc_sample_en;
	dptx->dptx_config_stream_timing = dptx_config_stream_timing;
	dptx->dptx_combophy_reset = dptx_combophy_reset;
	dptx->dp_dis_reset = dptx_dis_reset;
	dptx->is_all_pll_config_by_dp_soft = false;
	dptx->lane_low_power_mode = LANE_POWER_MODE_P2;
	dptx->max_tu = DPTX_MAX_TU_OF_MONITOR;
	dptx->max_hactive_low_temp = FHD_TIMING_H_ACTIVE;
	dptx->max_vactive_low_temp = FHD_TIMING_V_ACTIVE;
	dptx->dptx_ctrl_clk_enable = dptx_ctrl_clk_enable;
	dptx->dptx_hdcp_enable_video_transform = dptx_hdcp_enable_video_transform;
	dptx->dp_disable_clk = dp_disable_clk;
	dptx->dptx_phy_lane_reset = dptx_phy_lane_reset;
}

bool dp_ctrl_is_bypass_by_pg(uint32_t dp_id)
{
	void_unused(dp_id);
	return false;
}

void dp_enable_dpi_clk(char __iomem *dpu_base, bool enable)
{
	void_unused(dpu_base);
	void_unused(enable);
	return;
}