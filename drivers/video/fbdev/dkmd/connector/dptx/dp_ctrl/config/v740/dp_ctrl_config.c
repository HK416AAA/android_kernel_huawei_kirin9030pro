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

#include "dp_ctrl_config.h"
#include <linux/arm-smccc.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/pm.h>
#include <platform_include/see/efuse_driver.h>
#include <platform_include/display/linux/dpu_dss_dp.h>
#include <platform_include/see/bl31_smc.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#include <platform_include/cee/linux/ulsr.h>
#include <linux/clk-provider.h>
#include "soc_hsdt1_sub_harden_crg_interface.h"
#include "soc_hiu31dpedp_phy_pcs_interface.h"
#include "hidptx/hidptx_reg.h"
#include "efuse_uefi_def.h"
#include "efuse_kernel_def.h"
#include "dpu_dp_dbg.h"
#include "dpu_dp_dbg_v740.h"
#include "controller/dp_avgen_base.h"
#include "soc_spec_info.h"
#include "soc_efuse_chip_level_flag.h"
#include "soc_efuse_interface.h"
#include "hidptx_dp_core.h"
#include "hidptx_dp_avgen.h"
#include "dp_aux.h"
#include "psr_config_base.h"
#include "dkmd_connector.h"
#include "dkmd_object.h"
#include "dp_hdmi_common.h"
#include "dp_edid.h"
#include "dp_drv.h"
#include "dsc_config_base.h"
#include "dkmd_rect.h"
#include "dp_ctrl_dev.h"
#include "dp_link_training.h"
#include "dp_ctrl.h"
#include "dp_irq.h"
#include "drm_dp_helper_additions.h"
#include "dkmd_notify.h"
#include "utils/comm_utils.h"

#define POSTDIV_ARRAY_SIZE 30
#define DPC_PLL_STABLE_TIME 100
#define DPC_PLL_CONTINUE_LOCK_CNT 20

#define HDCP_BASE    (0xE802B000)
#define HDCP1_BASE   (0xE803B000)
#define HDCP2_BASE   (0xE804B000)
#define HDCP3_BASE   (0xE805B000)
#define HDCP4_BASE   (0xE8108000)
#define HDCP5_BASE   (0xE8118000)

#define EDP_LANE_CNT_1 0x1
#define EDP_LANE_CNT_2 0x3
#define EDP_LANE_CNT_4 0xf

#define DP_POS_LANE_CNT_1 0x4
#define DP_POS_LANE_CNT_2 0x5
#define DP_POS_LANE_CNT_4 0xf

#define DP_NEG_LANE_CNT_1 0x8
#define DP_NEG_LANE_CNT_2 0xa
#define DP_NEG_LANE_CNT_4 0xf

#define DACC_OFFSET (0x1E000)
#define DMD_OFFSET  (0x10000)
#define DM_INPUTDATA_ST_ADDR6 (DMD_OFFSET + 0x3200)
#define LAYER_ACTIVE 6
#define DELAY_FIX 35

int g_dptx_psr_burst_update_times = 0;
int g_dptx_psr_burst_update_flag = 0;
int g_dptx_psr_update_after_entry_flag = 0;
int g_dptx_psr_exit_after_update_flag = 0;
int g_psr2_entry_flag = 0;
int g_dptx_psr2_burst_update_flag = 0;
int g_dptx_psr2_burst_update_times = 0;
int g_dptx_psr2_update_after_entry_flag = 0;
int g_dptx_psr2_exit_after_update_flag = 0;

typedef struct {
	uint32_t pixel_clk_div_offset;
	uint32_t gt_clk_dptx_pixel_offset;
	uint32_t gt_clk_dptx_pixel_bit;
	uint32_t pixel_clk_pll_sel;
	uint32_t dpc_pll_ctrl0_offset; // DPC_PLL X(ctrl0: x = 0, 1, 2)
	uint32_t dpc_pll_ctrl1_offset; // DPC_PLL X(ctrl1: x = 0, 1, 2)
} dpc_pll_conf;

typedef struct {
	uint32_t hpd_gpio;
	uint32_t apb_clk_open_offset; // open apb clk
	uint32_t apb_clk_close_offset; // close apb clk
	uint32_t pixel_clk_open_offset; // open pixel clk
	uint32_t pixel_clk_close_offset; // close pixel clk
	uint32_t aux_clk_open_offset; // open aux clk
	uint32_t aux_clk_close_offset; // close aux clk
	uint32_t apb_open_offset;
	uint32_t apb_close_offset;
	uint32_t dpc_open_offset;
	uint32_t dpc_close_offset;

	uint8_t apb_clk_control_bit;
	uint8_t pixel_clk_control_bit;
	uint8_t aux_clk_control_bit;
	uint8_t apb_control_bit;
	uint8_t dpc_control_bit;
} dp_ctrl_conf;

/* PG level */
#ifdef NOT_SURPORT_PG
#define SOC_SPEC_LEVEL1_STR "level1"
#define SOC_SPEC_LEVEL1_CDC_STR "level1"
#define SOC_SPEC_LEVEL2_CDC_STR "level1"
#define SOC_SPEC_LITE_CDC_STR "level1"
#define SOC_SPEC_PC_STR "level1"
#define SOC_SPEC_DESKTOP_PC_STR "level1"
#define SOC_SPEC_PAD_PC_STR "level1"
#define CHIP_LEVEL_EFUSE_FLAG_USB3_PHY_START 839
#define CHIP_LEVEL_EFUSE_FLAG_EDE_START 837
#define EFUSE_PARTIALGOOD_FLAG8_START 768
#endif

#ifdef CHIP_TYPE_CSV2_CSV3
const struct product_pg_info pg_info[] = {
	{SOC_SPEC_LEVEL1_STR, {DPTX_PORT_ID_0, DPTX_PORT_ID_1, DPTX_PORT_ID_2, DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
	{SOC_SPEC_LEVEL1_CDC_STR, {DPTX_PORT_ID_2, DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
	{SOC_SPEC_LEVEL2_CDC_STR, {DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
};
#else
const struct product_pg_info pg_info[] = {
	{SOC_SPEC_LEVEL1_STR, {DPTX_PORT_ID_1, DPTX_PORT_ID_2, DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
	{SOC_SPEC_LEVEL1_CDC_STR, {DPTX_PORT_ID_1, DPTX_PORT_ID_2, DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
	{SOC_SPEC_LEVEL2_CDC_STR, {DPTX_PORT_ID_1, DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
	{SOC_SPEC_LITE_CDC_STR, {DPTX_PORT_ID_1, DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
	{SOC_SPEC_DESKTOP_PC_STR, {0}, true},
	{SOC_SPEC_PC_STR, {DPTX_PORT_ID_0, DPTX_PORT_ID_1, DPTX_PORT_ID_2, DPTX_PORT_ID_3, DPTX_PORT_ID_4, DPTX_PORT_ID_5},
		false},
	{SOC_SPEC_PAD_PC_STR, {DPTX_PORT_ID_1, DPTX_PORT_ID_4, DPTX_PORT_ID_5}, false},
};
#endif

const uint32_t port_id_sysctrl_value[6] = {0x2, 0x4, 0x6, 0x8, 0x0, 0x1};

static int dptx_ctrl_clk_enable(struct dp_ctrl *dptx)
{
	struct dp_private *dp_pri = NULL;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");

	dp_pri = to_dp_private(dptx->connector->conn_info);

	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5) { // edp/dp combo phy
		/* enable clk_dpctrl_16m */
		if (clk_prepare_enable(dptx->clk_dpctrl_16m) != 0) {
			dpu_pr_err("[DP] enable dpctrl 16m clk failed!");
			return -1;
		}
		if (dptx->port_id == DPTX_PORT_ID_4) {
			// pclk_hidif_ctrl0
			set_reg(dp_pri->sub_harden_crg_base + HSDT1_SUB_HARDEN_PEREN0_OFFSET, 0x1, 1, 8);
			// clk_aux16_hidif_ctrl0 enable
			set_reg(dp_pri->sub_harden_crg_base + HSDT1_SUB_HARDEN_PEREN0_OFFSET, 0x1, 1, 7);
		} else {
			// pclk_hidif_ctrl1
			set_reg(dp_pri->sub_harden_crg_base + HSDT1_SUB_HARDEN_PEREN0_OFFSET, 0x1, 1, 3);
			// clk_aux16_hidif_ctrl0 enable
			set_reg(dp_pri->sub_harden_crg_base + HSDT1_SUB_HARDEN_PEREN0_OFFSET, 0x1, 1, 0);
		}
	} else { /* -1 or 0~3 */
		/* enable clock */
		if (clk_prepare_enable(dptx->connector->connector_clk[CLK_DPCTRL_16M]) != 0) {
			dpu_pr_err("[DP] enable dpctrl 16m clk failed!");
			return -1;
		}

		if (clk_prepare_enable(dptx->connector->connector_clk[CLK_DPCTRL_PCLK]) != 0) {
			dpu_pr_err("[DP] enable dpctrl pclk failed!");
			return -1;
		}

		/* v740 has three pixel pll, select and control in dptx_pixel_pll_init func */
	}
	return 0;
}

static void dptx_get_sync_calib_param(struct dp_ctrl *dptx, int stream)
{
	uint32_t bpp;
	uint32_t sync_delay;
	uint32_t sync_calib_param = 0;
	uint32_t reg;
	uint32_t h_blank_new;
	uint32_t hb_threshold;
	uint32_t h_clock_div;
	uint32_t dsc_bpp;
	struct dtd *mdtd = NULL;
	struct video_params *vparams = NULL;

	vparams= &(dptx->vparams);
	mdtd = &(dptx->vparams.mdtd);

	bpp = (uint32_t)dptx_get_color_depth(dptx->vparams.bpc, dptx->vparams.pix_enc);

	/* The timing generation video timing parameters calculation formula is provided by the chip,
		and refer to the corresponding documentation for configuration. */
	sync_delay = dptx->link.lanes * 16 * 8 * 8 / (2 * bpp);
	hb_threshold = sync_delay;

	if (sync_delay + 16 >= dptx->vparams.mdtd.h_blanking / 2)
		sync_calib_param = sync_delay + 64 - dptx->vparams.mdtd.h_blanking / 2 + 32;
	else
		sync_calib_param = 96;
	if (dptx->dsc) {
		h_clock_div = (uint32_t)dptx_dsc_get_clock_div(dptx);
		dpu_pr_debug("[DP] h_clock_div: %u, bpp: %u", h_clock_div, bpp);
		dsc_bpp = vparams->dp_dsc_info.dsc_info.dsc_bpp;
		h_blank_new = (dptx->connector->ldi.h_front_porch + dptx->connector->ldi.h_pulse_width +
			dptx->connector->ldi.h_back_porch + mdtd->h_active) / h_clock_div - (mdtd->h_active * dsc_bpp / 8 / 6);
		dpu_pr_debug("[DP] h_blank_new: %u, sync_delay: %u", h_blank_new, sync_delay);

		if (hb_threshold > h_blank_new)
			sync_calib_param = hb_threshold - h_blank_new + 100;
		else
			sync_calib_param = 0;

		dpu_pr_debug("[DP] sync_calib_param %u", sync_calib_param);
	}
	sync_calib_param = sync_calib_param / 2 * 2; /* sync_calib_param has to be even */

	reg = dptx_readl(dptx, dptx_video_packet_stream(stream));
	reg = reg & (~DPTX_VIDEO_PACKET_TU_SYNC_CALIB_MASK);
	reg = reg | (sync_calib_param << DPTX_VIDEO_PACKET_TU_SYNC_CALIB_SHIFT);
	dptx_writel(dptx, dptx_video_packet_stream(stream), reg);

	dpu_pr_info("[DP] stream %d set reg sync_calib_param %u", stream, sync_calib_param);
	return;
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

static int get_dp_ctrl_conf(uint32_t port_id, dp_ctrl_conf *ctrl_conf)
{
	if (ctrl_conf == NULL) {
		dpu_pr_err("[DP] [get_dp_phy_conf] phy_conf is NULL!");
		return -1;
	}
	switch (port_id) {
	case DPTX_PORT_ID_0:
		ctrl_conf->hpd_gpio = 328;
		ctrl_conf->apb_open_offset = 0x88;
		ctrl_conf->apb_close_offset = 0x84;
		ctrl_conf->dpc_open_offset = 0x88;
		ctrl_conf->dpc_close_offset = 0x84;
		ctrl_conf->apb_clk_open_offset = 0x0;
		ctrl_conf->apb_clk_close_offset = 0x4;
		ctrl_conf->pixel_clk_open_offset = 0x30;
		ctrl_conf->pixel_clk_close_offset = 0x34;
		ctrl_conf->aux_clk_open_offset = 0x0;
		ctrl_conf->aux_clk_close_offset = 0x4;
		ctrl_conf->apb_control_bit = 15;
		ctrl_conf->dpc_control_bit = 11;
		ctrl_conf->apb_clk_control_bit = 3;
		ctrl_conf->pixel_clk_control_bit = 16;
		ctrl_conf->aux_clk_control_bit = 7;
		break;
	case DPTX_PORT_ID_1:
		ctrl_conf->hpd_gpio = 329;
		ctrl_conf->apb_open_offset = 0x88;
		ctrl_conf->apb_close_offset = 0x84;
		ctrl_conf->dpc_open_offset = 0x88;
		ctrl_conf->dpc_close_offset = 0x84;
		ctrl_conf->apb_clk_open_offset = 0x10;
		ctrl_conf->apb_clk_close_offset = 0x14;
		ctrl_conf->pixel_clk_open_offset = 0x30;
		ctrl_conf->pixel_clk_close_offset = 0x34;
		ctrl_conf->aux_clk_open_offset = 0x0;
		ctrl_conf->aux_clk_close_offset = 0x4;
		ctrl_conf->apb_control_bit = 14;
		ctrl_conf->dpc_control_bit = 10;
		ctrl_conf->apb_clk_control_bit = 26;
		ctrl_conf->pixel_clk_control_bit = 15;
		ctrl_conf->aux_clk_control_bit = 6;
		break;
	case DPTX_PORT_ID_2:
		ctrl_conf->hpd_gpio = 173;
		ctrl_conf->apb_open_offset = 0x88;
		ctrl_conf->apb_close_offset = 0x84;
		ctrl_conf->dpc_open_offset = 0x88;
		ctrl_conf->dpc_close_offset = 0x84;
		ctrl_conf->apb_clk_open_offset = 0x10;
		ctrl_conf->apb_clk_close_offset = 0x14;
		ctrl_conf->pixel_clk_open_offset = 0x30;
		ctrl_conf->pixel_clk_close_offset = 0x34;
		ctrl_conf->aux_clk_open_offset = 0x0;
		ctrl_conf->aux_clk_close_offset = 0x4;
		ctrl_conf->apb_control_bit = 13;
		ctrl_conf->dpc_control_bit = 9;
		ctrl_conf->apb_clk_control_bit = 25;
		ctrl_conf->pixel_clk_control_bit = 14;
		ctrl_conf->aux_clk_control_bit = 5;
		break;
	case DPTX_PORT_ID_3:
		ctrl_conf->hpd_gpio = 180;
		ctrl_conf->apb_open_offset = 0x88;
		ctrl_conf->apb_close_offset = 0x84;
		ctrl_conf->dpc_open_offset = 0x88;
		ctrl_conf->dpc_close_offset = 0x84;
		ctrl_conf->apb_clk_open_offset = 0x10;
		ctrl_conf->apb_clk_close_offset = 0x14;
		ctrl_conf->pixel_clk_open_offset = 0x30;
		ctrl_conf->pixel_clk_close_offset = 0x34;
		ctrl_conf->aux_clk_open_offset = 0x0;
		ctrl_conf->aux_clk_close_offset = 0x4;
		ctrl_conf->apb_control_bit = 12;
		ctrl_conf->dpc_control_bit = 8;
		ctrl_conf->apb_clk_control_bit = 24;
		ctrl_conf->pixel_clk_control_bit = 13;
		ctrl_conf->aux_clk_control_bit = 2;
		break;
	case DPTX_PORT_ID_4:
		ctrl_conf->hpd_gpio = 239;
		ctrl_conf->apb_open_offset = 0x64;
		ctrl_conf->apb_close_offset = 0x60;
		ctrl_conf->dpc_open_offset = 0x64;
		ctrl_conf->dpc_close_offset = 0x60;
		ctrl_conf->apb_clk_open_offset = 0x0;
		ctrl_conf->apb_clk_close_offset = 0x4;
		ctrl_conf->pixel_clk_open_offset = 0x10;
		ctrl_conf->pixel_clk_close_offset = 0x14;
		ctrl_conf->aux_clk_open_offset = 0x0;
		ctrl_conf->aux_clk_close_offset = 0x4;
		ctrl_conf->apb_control_bit = 0;
		ctrl_conf->dpc_control_bit = 24;
		ctrl_conf->apb_clk_control_bit = 8;
		ctrl_conf->pixel_clk_control_bit = 15;
		ctrl_conf->aux_clk_control_bit = 7;
		break;
	case DPTX_PORT_ID_5:
		ctrl_conf->hpd_gpio = 246;
		ctrl_conf->apb_open_offset = 0x64;
		ctrl_conf->apb_close_offset = 0x60;
		ctrl_conf->dpc_open_offset = 0x64;
		ctrl_conf->dpc_close_offset = 0x60;
		ctrl_conf->apb_clk_open_offset = 0x0;
		ctrl_conf->apb_clk_close_offset = 0x4;
		ctrl_conf->pixel_clk_open_offset = 0x10;
		ctrl_conf->pixel_clk_close_offset = 0x14;
		ctrl_conf->aux_clk_open_offset = 0x0;
		ctrl_conf->aux_clk_close_offset = 0x4;
		ctrl_conf->apb_control_bit = 4;
		ctrl_conf->dpc_control_bit = 16;
		ctrl_conf->apb_clk_control_bit = 3;
		ctrl_conf->pixel_clk_control_bit = 11;
		ctrl_conf->aux_clk_control_bit = 0;
		break;
	default:
		dpu_pr_err("[DP] [get_dp_ctrl_conf] error port_id %u come in!!!", port_id);
		return -1;
	}

	return 0;
}

static int get_dp_phy_conf(uint32_t port_id, dp_phy_conf *phy_conf)
{
	if (phy_conf == NULL) {
		dpu_pr_err("[DP] [get_dp_phy_conf] phy_conf is NULL!");
		return -1;
	}

	switch (port_id) {
	case DPTX_PORT_ID_0:
		phy_conf->insert_type_gpio = 41;
		phy_conf->phy_lane_mode_offset = PHY_LANE_MODE_OFFSET;
		phy_conf->phy_aux_ctrl_offset = PHY_USBDP_AUX_CTRL_OFFSET;
		phy_conf->phy_iso_en_offset = HSDT1_USBDP0_PHY_ISO_EN;
		phy_conf->apb_clk_open_offset = 0x0;
		phy_conf->aux_clk_open_offset = 0x0;
		phy_conf->apb_clk_close_offset = 0x4;
		phy_conf->aux_clk_close_offset = 0x4;
		phy_conf->apb_reset_n_open_offset = 0x64;
		phy_conf->apb_reset_n_close_offset = 0x60;
		phy_conf->por_n_open_offset = 0x7C;
		phy_conf->por_n_close_offset = 0x78;
		phy_conf->phy_reset_n_open_offset = 0x7C;
		phy_conf->phy_reset_n_close_offset = 0x78;
		phy_conf->apb_clk_control_bit = 21;
		phy_conf->apb_reset_n_control_bit = 7;
		phy_conf->por_n_control_bit = 19;
		phy_conf->aux_clk_control_bit = 24;
		phy_conf->phy_reset_n_control_bit = 21;
		break;
	case DPTX_PORT_ID_1:
		phy_conf->insert_type_gpio = 64;
		phy_conf->phy_lane_mode_offset = PHY_LANE_MODE_OFFSET;
		phy_conf->phy_aux_ctrl_offset = PHY_USBDP_AUX_CTRL_OFFSET;
		phy_conf->phy_iso_en_offset = HSDT1_USBDP1_PHY_ISO_EN;
		phy_conf->apb_clk_open_offset = 0x0;
		phy_conf->aux_clk_open_offset = 0x0;
		phy_conf->apb_clk_close_offset = 0x4;
		phy_conf->aux_clk_close_offset = 0x4;
		phy_conf->apb_reset_n_open_offset = 0x64;
		phy_conf->apb_reset_n_close_offset = 0x60;
		phy_conf->por_n_open_offset = 0x7C;
		phy_conf->por_n_close_offset = 0x78;
		phy_conf->phy_reset_n_open_offset = 0x7C;
		phy_conf->phy_reset_n_close_offset = 0x78;
		phy_conf->apb_clk_control_bit = 20;
		phy_conf->apb_reset_n_control_bit = 5;
		phy_conf->por_n_control_bit = 18;
		phy_conf->aux_clk_control_bit = 23;
		phy_conf->phy_reset_n_control_bit = 20;
		break;
	case DPTX_PORT_ID_2:
		phy_conf->insert_type_gpio = 67;
		phy_conf->phy_lane_mode_offset = PHY_LANE_MODE_OFFSET;
		phy_conf->phy_aux_ctrl_offset = PHY_USBDP_AUX_CTRL_OFFSET;
		phy_conf->phy_iso_en_offset = HSDT1_USBDP2_PHY_ISO_EN;
		phy_conf->apb_clk_open_offset = 0x20;
		phy_conf->aux_clk_open_offset = 0x20;
		phy_conf->apb_clk_close_offset = 0x24;
		phy_conf->aux_clk_close_offset = 0x4;
		phy_conf->apb_reset_n_open_offset = 0x7C;
		phy_conf->apb_reset_n_close_offset = 0x78;
		phy_conf->por_n_open_offset = 0x7C;
		phy_conf->por_n_close_offset = 0x78;
		phy_conf->phy_reset_n_open_offset = 0x7C;
		phy_conf->phy_reset_n_close_offset = 0x78;
		phy_conf->apb_clk_control_bit = 25;
		phy_conf->apb_reset_n_control_bit = 22;
		phy_conf->por_n_control_bit = 25;
		phy_conf->aux_clk_control_bit = 26;
		phy_conf->phy_reset_n_control_bit = 26;
		break;
	case DPTX_PORT_ID_3:
		phy_conf->insert_type_gpio = 15;
		phy_conf->phy_lane_mode_offset = PHY_LANE_MODE_OFFSET;
		phy_conf->phy_aux_ctrl_offset = PHY_USBDP_AUX_CTRL_OFFSET;
		phy_conf->phy_iso_en_offset = HSDT1_USBDP3_PHY_ISO_EN;
		phy_conf->apb_clk_open_offset = 0x30;
		phy_conf->aux_clk_open_offset = 0x30;
		phy_conf->apb_clk_close_offset = 0x34;
		phy_conf->aux_clk_close_offset = 0x4;
		phy_conf->apb_reset_n_open_offset = 0x88;
		phy_conf->apb_reset_n_close_offset = 0x84;
		phy_conf->por_n_open_offset = 0x88;
		phy_conf->por_n_close_offset = 0x84;
		phy_conf->phy_reset_n_open_offset = 0x88;
		phy_conf->phy_reset_n_close_offset = 0x84;
		phy_conf->apb_clk_control_bit = 9;
		phy_conf->apb_reset_n_control_bit = 0;
		phy_conf->por_n_control_bit = 3;
		phy_conf->aux_clk_control_bit = 10;
		phy_conf->phy_reset_n_control_bit = 4;
		break;
	case DPTX_PORT_ID_4:
		phy_conf->insert_type_gpio = 0;
		phy_conf->phy_lane_mode_offset = PHY_LANE_MODE_OFFSET;
		phy_conf->phy_aux_ctrl_offset = PHY_DP_AUX_CTRL_OFFSET;
		phy_conf->phy_iso_en_offset = HSDT1_EDPTX0_PHY_ISO_EN;
		phy_conf->apb_clk_open_offset = 0x0;
		phy_conf->aux_clk_open_offset = 0x0;
		phy_conf->apb_clk_close_offset = 0x4;
		phy_conf->aux_clk_close_offset = 0x4;
		phy_conf->apb_reset_n_open_offset = 0x64;
		phy_conf->apb_reset_n_close_offset = 0x60;
		phy_conf->por_n_open_offset = 0x64;
		phy_conf->por_n_close_offset = 0x60;
		phy_conf->phy_reset_n_open_offset = 0x64;
		phy_conf->phy_reset_n_close_offset = 0x60;
		phy_conf->apb_clk_control_bit = 6;
		phy_conf->apb_reset_n_control_bit = 2;
		phy_conf->por_n_control_bit = 9;
		phy_conf->aux_clk_control_bit = 5;
		phy_conf->phy_reset_n_control_bit = 10;
		break;
	case DPTX_PORT_ID_5:
		phy_conf->insert_type_gpio = 0;
		phy_conf->phy_lane_mode_offset = PHY_LANE_MODE_OFFSET;
		phy_conf->phy_aux_ctrl_offset = PHY_DP_AUX_CTRL_OFFSET;
		phy_conf->phy_iso_en_offset = HSDT1_EDPTX1_PHY_ISO_EN;
		phy_conf->apb_clk_open_offset = 0x0;
		phy_conf->aux_clk_open_offset = 0x0;
		phy_conf->apb_clk_close_offset = 0x4;
		phy_conf->aux_clk_close_offset = 0x4;
		phy_conf->apb_reset_n_open_offset = 0x64;
		phy_conf->apb_reset_n_close_offset = 0x60;
		phy_conf->por_n_open_offset = 0x64;
		phy_conf->por_n_close_offset = 0x60;
		phy_conf->phy_reset_n_open_offset = 0x64;
		phy_conf->phy_reset_n_close_offset = 0x60;
		phy_conf->apb_clk_control_bit = 2;
		phy_conf->apb_reset_n_control_bit = 3;
		phy_conf->por_n_control_bit = 7;
		phy_conf->aux_clk_control_bit = 1;
		phy_conf->phy_reset_n_control_bit = 8;
		break;
	default:
		dpu_pr_err("[DP] [get dp phy conf] error port_id %u come in!!!", port_id);
		return -1;
	}
	return 0;
}

static void dptx_combophy_set_lane_mode(struct dp_ctrl *dptx, dp_phy_conf phy_conf)
{
	int ret;
	if (dptx == NULL) {
		dpu_pr_err("[DP] dptx is null!");
		return;
	}

	if (dptx->id == MASTER_DPTX_IDX) {
		ret = gpio_request(phy_conf.insert_type_gpio, "dptx_aux_gpio");
		if (ret < 0) {
			dpu_pr_err("[DP] Request gpio-%u fail!", phy_conf.insert_type_gpio);
			return;
		}
		ret = gpio_direction_output(phy_conf.insert_type_gpio, 0);
		if (ret < 0) {
			dpu_pr_err("[DP] Set gpio-%u output fail!", phy_conf.insert_type_gpio);
			return;
		}
	}

	if (dptx->dptx_plug_type == TYPEC_ORIEN_POSITIVE) {
		gpio_set_value(phy_conf.insert_type_gpio, 0);
	} else if (dptx->dptx_plug_type == TYPEC_ORIEN_NEGATIVE) {
		gpio_set_value(phy_conf.insert_type_gpio, 1);
	} else {
		dpu_pr_err("[DP] Error insert type = %d!", dptx->dptx_plug_type);
		return;
	}

	dpu_pr_info("[DP] Set port[%d] plug type config done", dptx->port_id);
	return;
}

int dptx_combophy_set_lane_check_param(struct dp_ctrl *dptx, uint8_t lanes, dp_phy_conf *phy_conf) {
	if (dptx == NULL) {
		dpu_pr_err("[DP] dptx is null!");
		return -EINVAL;
	}
	if (lanes != 4 && lanes != 2 && lanes != 1) {
		dpu_pr_err("[DP] lanes is invalid! lanes: %hhu", lanes);
		return -EINVAL;
	}
	if (get_dp_phy_conf((uint32_t)dptx->port_id, phy_conf) != 0) {
		dpu_pr_err("[DP] [get_dp_phy_conf] error, return!");
		return -EINVAL;
	}
	return 0;
}

static void dptx_phy_set_lane_csv2(struct dp_ctrl *dptx, uint8_t lanes, uint32_t phy_lane_mode_offset)
{
	if (lanes == 4)
		set_reg(dptx->combo_phy_base + phy_lane_mode_offset, EDP_LANE_CNT_4, 4, 12);
	else if (lanes == 2)
		set_reg(dptx->combo_phy_base + phy_lane_mode_offset, EDP_LANE_CNT_2, 4, 12);
	else
		set_reg(dptx->combo_phy_base + phy_lane_mode_offset, EDP_LANE_CNT_1, 4, 12);
	return;
}

static void dptx_u4phy_set_lane_csv2(struct dp_ctrl *dptx, uint8_t lanes, uint32_t phy_lane_mode_offset)
{
	set_reg(dptx->combo_phy_base + phy_lane_mode_offset, DP_POS_LANE_CNT_4, 4, 12);
	return;
}

static void dptx_combophy_set_lane_csv2(struct dp_ctrl *dptx, uint8_t lanes)
{
	dp_phy_conf phy_conf;
	dpu_check_and_no_retval(dptx_combophy_set_lane_check_param(dptx, lanes, &phy_conf),
		err, "[DP] set_lane check param failed!");

	dpu_pr_info("[DP]combophy set lanes is %hhu", lanes);
	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5) // DPTX
		dptx_phy_set_lane_csv2(dptx, lanes, phy_conf.phy_lane_mode_offset);
	else if (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3) // U4
		dptx_u4phy_set_lane_csv2(dptx, lanes, phy_conf.phy_lane_mode_offset);
	else
		dpu_pr_err("[DP] dptx->port_id is invalid %d", dptx->port_id);

	return;
}

static void dptx_set_lane_by_plug_type(struct dp_ctrl *dptx, uint8_t lanes, dp_phy_conf phy_conf)
{
	if (dptx->connector->conn_info->base.mode == EDP_MODE || dptx->mode == TCPC_DP) {
		if (dptx->dptx_plug_type == TYPEC_ORIEN_POSITIVE) {
			if (lanes == 4)
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0xF, 4, 24);
			else if (lanes == 2)
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0xA, 4, 24);
			else
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0x8, 4, 24);
		} else {
			if (lanes == 4)
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0xF, 4, 24);
			else if (lanes == 2)
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0x5, 4, 24);
			else
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0x4, 4, 24);
		}
	} else {
		if (dptx->dptx_plug_type == TYPEC_ORIEN_POSITIVE) {
			if (lanes == 4)
				dpu_pr_err("[DP] lanes is invalid! dptx->mode: %hhu", dptx->mode);
			else if (lanes == 2)
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0xA, 4, 24);
			else
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0x8, 4, 24);
		} else {
			if (lanes == 4)
				dpu_pr_err("[DP] lanes is invalid! dptx->mode: %hhu", dptx->mode);
			else if (lanes == 2)
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0x5, 4, 24);
			else
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0x4, 4, 24);
		}
	}
}

static void dptx_combophy_set_lane(struct dp_ctrl *dptx, uint8_t lanes)
{
	dp_phy_conf phy_conf;
	dpu_check_and_no_retval(dptx_combophy_set_lane_check_param(dptx, lanes, &phy_conf),
		err, "[DP] set_lane check param failed!");

	if (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3) {
		dpu_pr_info("[DP] Port %d usb combophy is not need set lanes", dptx->port_id);
		return;
	}

	dpu_pr_info("[DP]combophy set lanes is %hhu", lanes);
	dptx_set_lane_by_plug_type(dptx, lanes, phy_conf);

	return;
}

static bool dptx_combo_phy_is_up(struct dp_ctrl *dptx)
{
	char __iomem *hsdt1_crg_base = NULL;
	struct dp_private *dp_pri = NULL;
	dp_phy_conf phy_conf;
	unsigned int val = 0;

	dpu_pr_info("[DP] dptx_combo_phy_is_up. dptx->port_id: %d\n", dptx->port_id);
	dpu_check_and_return(!dptx, false, err, "[DP] dptx is NULL!");
	if (dptx->port_id == 4 || dptx->port_id == 5) {
		dpu_pr_info("[DP] port_id not match, port_id: %d\n", dptx->port_id);
		return true;
	}

	dp_pri = to_dp_private(dptx->connector->conn_info);
	hsdt1_crg_base = dp_pri->hsdt1_crg_base;
	if (get_dp_phy_conf((uint32_t)dptx->port_id, &phy_conf) != 0) {
		dpu_pr_err("[DP] [get_dp_phy_conf] error, return!");
		return false;
	}

	val = readl(hsdt1_crg_base + phy_conf.apb_clk_open_offset + 0xC);
	dpu_pr_info("[DP] read apb_clk_control_bit %#x", val);
	dpu_check_and_return((val & BIT(phy_conf.apb_clk_control_bit)) == 0, false, info, "[DP] apb_clk_control_bit");

	val = readl(hsdt1_crg_base + phy_conf.apb_reset_n_open_offset + 0x4);
	dpu_pr_info("[DP] read apb_reset_n_control_bit %#x", val);
	dpu_check_and_return((val & BIT(phy_conf.apb_reset_n_control_bit)), false, info, "[DP] apb_reset_n_control_bit");

	val = readl(hsdt1_crg_base + phy_conf.por_n_open_offset + 0x4);
	dpu_pr_info("[DP] read por_n_control_bit %#x", val);
	dpu_check_and_return((val & BIT(phy_conf.por_n_control_bit)), false, info, "[DP] por_n_control_bit");

	val = readl(hsdt1_crg_base + phy_conf.aux_clk_open_offset + 0xC);
	dpu_pr_info("[DP] read aux_clk_control_bit %#x", val);
	dpu_check_and_return((val & BIT(phy_conf.aux_clk_control_bit)) == 0, false, info, "[DP] aux_clk_control_bit");

	val = readl(hsdt1_crg_base + phy_conf.phy_reset_n_open_offset + 0x4);
	dpu_pr_info("[DP] read phy_reset_n_control_bit %#x", val);
	dpu_check_and_return((val & BIT(phy_conf.phy_reset_n_control_bit)), false, info, "[DP] phy_reset_n_control_bit");

	dpu_pr_info("[DP] dptx_combo_phy_is_up");
	return true;
}

static void dptx_combophy_reset_reg(struct dp_ctrl *dptx, bool benable, dp_phy_conf phy_conf,
	bool is_phy_need_init, struct dp_private *dp_pri, char __iomem *hsdt1_crg_base)
{
	uint8_t org = 0;

	if (benable) { // pulg in
		if (is_phy_need_init) {
			// 0: enable phy's iso
			set_reg(dp_pri->hsdt1_sysctrl_base + phy_conf.phy_iso_en_offset, 0, 1, 0);
			// 1: enable apb clock
			set_reg(hsdt1_crg_base + phy_conf.apb_clk_open_offset, 1, 1, phy_conf.apb_clk_control_bit);
			// 2: enable aux clock
			set_reg(hsdt1_crg_base + phy_conf.aux_clk_open_offset, 1, 1, phy_conf.aux_clk_control_bit);
			// 3: open por_b
			set_reg(hsdt1_crg_base + phy_conf.por_n_open_offset, 1, 1, phy_conf.por_n_control_bit);
			// 4: open apb_reset_n
			set_reg(hsdt1_crg_base + phy_conf.apb_reset_n_open_offset, 1, 1, phy_conf.apb_reset_n_control_bit);

			dpu_pr_info("[DP] dptx_combophy_reset dptx->port_id:%d", dptx->port_id);
			if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5) {
				dpu_pr_info("[DP] set phy_lane_mode_offset DP_NORNAL_MODE, base:0x%llx", dptx->combo_phy_base);
				org = dptx->dptx_plug_type == TYPEC_ORIEN_POSITIVE ? DP_NORNAL_MODE : DP_FLIP_MODE;
				set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, org, 4, 0);
			}
			// 6: set lane
			if (dptx->dptx_combophy_set_lane)
				dptx->dptx_combophy_set_lane(dptx, dptx->max_lanes);

			// init all rate pll
			if (dptx->dptx_phy_rate_pll_init)
				dptx->dptx_phy_rate_pll_init(dptx);

			// 7: open phy_reset_n
			set_reg(hsdt1_crg_base + phy_conf.phy_reset_n_open_offset, 1, 1, phy_conf.phy_reset_n_control_bit);
		}

		if (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3) {
			// only usb/dp combo phy involved
			if (dptx->connector->conn_info->dp_board_mode == DP_BOARD_UDP)
				dptx_combophy_set_lane_mode(dptx, phy_conf);
		}
		set_reg(dptx->combo_phy_base + phy_conf.phy_lane_mode_offset, 0xFF, 8, 12);
		// 8: aux power on
		set_reg(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset, 1, 1, 9);
#ifdef CHIP_TYPE_CSV2_CSV3
		if (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3) {
			set_reg(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET1, 1, 1, 9);
			set_reg(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET2, 1, 1, 9);
			set_reg(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET3, 1, 1, 9);
		}
#endif
		dpu_pr_info("[DP] combo_phy_base set 0x0 to 1");
		// 9: phy reg set for power saving mode
		set_reg(dptx->combo_phy_base + 0x0, 1, 1, 0);
	} else {
		if (dptx_combo_phy_is_up(dptx))
			// 8: aux power off
			set_reg(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset, 0, 1, 9);
#ifdef CHIP_TYPE_CSV2_CSV3
		if (dptx_combo_phy_is_up(dptx) && (dptx->port_id == DPTX_PORT_ID_0 || dptx->port_id == DPTX_PORT_ID_1 ||
				dptx->port_id == DPTX_PORT_ID_2 || dptx->port_id == DPTX_PORT_ID_3)) {
			set_reg(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET1, 0, 1, 9);
			set_reg(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET2, 0, 1, 9);
			set_reg(dptx->combo_phy_base + PHY_AUX_CTRL_OFFSET3, 0, 1, 9);
		}
#endif
		// 5: release gpio
		gpio_free(phy_conf.insert_type_gpio);
		if (is_phy_need_init) {
			// 7: close phy_reset_n
			set_reg(hsdt1_crg_base + phy_conf.phy_reset_n_close_offset, 1, 1, phy_conf.phy_reset_n_control_bit);
			// 4: close apb_reset_n
			set_reg(hsdt1_crg_base + phy_conf.apb_reset_n_close_offset, 1, 1, phy_conf.apb_reset_n_control_bit);
			// 3: close por_b
			set_reg(hsdt1_crg_base + phy_conf.por_n_close_offset, 1, 1, phy_conf.por_n_control_bit);
			// 2: disable aux clock  0x4 5bit
			set_reg(hsdt1_crg_base + phy_conf.aux_clk_close_offset, 1, 1, phy_conf.aux_clk_control_bit);
			// 1: disable apb clock  0x4 6bit
			set_reg(hsdt1_crg_base + phy_conf.apb_clk_close_offset, 1, 1, phy_conf.apb_clk_control_bit);
			// 0: disable phy's iso
			set_reg(dp_pri->hsdt1_sysctrl_base + phy_conf.phy_iso_en_offset, 1, 1, 0); // base+offset,val:1,bw:1,bit0
		}
	}
}

static int dptx_combophy_reset(struct dp_ctrl *dptx, bool benable)
{
	struct dpu_connector *connector = NULL;
	struct dp_private *dp_pri = NULL;

	dp_phy_conf phy_conf;
	char __iomem *hsdt1_crg_base = NULL;
	bool is_phy_need_init = false;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");

	if (get_dp_phy_conf((uint32_t)dptx->port_id, &phy_conf) != 0) {
		dpu_pr_err("[DP] [get_dp_phy_conf] error, return!");
		return -EINVAL;
	}

	connector = dptx->connector;
	dp_pri = to_dp_private(connector->conn_info);

	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5) { // edp/dp combo phy
		hsdt1_crg_base = dp_pri->sub_harden_crg_base;
		is_phy_need_init = true;
	} else {
		hsdt1_crg_base = dp_pri->hsdt1_crg_base;
		is_phy_need_init = false;
	}

	dpu_pr_info("[DP] gpio_id is %u, benable = %d(true:1), port:%d",
		phy_conf.insert_type_gpio, benable, dptx->port_id);

	if (dptx->connector->conn_info->base.fpga_flag)
		return 0;

	dptx_combophy_reset_reg(dptx, benable, phy_conf, is_phy_need_init, dp_pri, hsdt1_crg_base);
	return 0;
}

static bool dptx_convert_compare(int port_id, int port_id_sync, int flag1, int flag2)
{
	if ((port_id == flag1 && port_id_sync == flag2) ||
		(port_id == flag2 && port_id_sync == flag1)) {
		return true;
	} else {
		return false;
	}
}

static int dptx_pipe_combo_phy_wait_busy_common(struct dp_ctrl *dptx, uint32_t reg, uint32_t target)
{
	uint32_t retry_cnt = 0;
	uint32_t phyifctrl;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] null pointer");

	do {
		phyifctrl = dptx_combo_phy_readl(dptx, reg);
		if (phyifctrl == target) {
			dptx_read_phy_reg(dptx, reg, false);
			return 0;
		}
		udelay(1);
	} while (retry_cnt++ < MAX_DP_TIMEOUT_WAIT);

	dptx_read_phy_reg(dptx, reg, true);
	dpu_pr_warn("[DP] PHY BUSY timed out, read 0x%x, target: 0x%x, val: 0x%x", reg, target, phyifctrl);

	return -EBUSY;
}

static void dptx_combophy_ctrl_set(struct dp_ctrl *dptx)
{
	int retval;

#ifndef CHIP_TYPE_CSV2_CSV3
	set_reg(dptx->combo_phy_base + 0x2e0, 0x1, 1, 30);
	set_reg(dptx->combo_phy_base + 0x2e0, 0x0, 1, 30);
	set_reg(dptx->combo_phy_base + 0x3e4, 0x1, 1, 1);
	set_reg(dptx->combo_phy_base + 0x3e4, 0x0, 1, 1);
	set_reg(dptx->combo_phy_base + 0x2cc, 0x0, 8, 0);
	set_reg(dptx->combo_phy_base + 0x2cc, 0x1, 1, 17);
	set_reg(dptx->combo_phy_base + 0x2cc, 0x0, 1, 17);
	set_reg(dptx->combo_phy_base + 0x2cc, 0xFF, 8, 0);
#endif

	// 9: set PHY to reset: DPTX_CTRL, set 0xa4 to hight，open set to 0xf for opening
	set_reg(dptx->hidptx_base + DPTX_PHYIF_CTRL1, 0xf, 4, 0);

	retval = dptx_phy_wait_busy(dptx, dptx->max_lanes);
	if (retval)
		dpu_pr_err("[DP] phy release fail");

#ifndef CHIP_TYPE_CSV2_CSV3
	dptx_pipe_combo_phy_wait_busy_common(dptx, 0x3A8, 0x5);
	dptx_pipe_combo_phy_wait_busy_common(dptx, 0x3AC, 0x1);
#endif
}

static int dptx_pipe_combo_phy_wait_busy(struct dp_ctrl *dptx)
{
	uint32_t retry_cnt = 0;
	uint32_t phyifctrl;
	uint32_t mask = 0x00FF0000;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] null pointer");

	do {
		phyifctrl = dptx_combo_phy_readl(dptx, 0x188);
		if ((phyifctrl & mask) == 0) {
			dptx_read_phy_reg(dptx, 0x188, false);
			return 0;
		}
		udelay(1);
	} while (retry_cnt++ < MAX_DP_TIMEOUT_WAIT);

	dptx_read_phy_reg(dptx, 0x188, true);
	dpu_pr_warn("[DP] PHY BUSY timed out, mask = 0x%x, phyifctrl = 0x%x", mask, phyifctrl);

	return -EBUSY;
}

static void dptx_combophy_ctrl_reset(struct dp_ctrl *dptx)
{
	uint32_t phyifctrl;
	phyifctrl = dptx_readl(dptx, DPTX_PHYIF_CTRL1);
#ifndef CHIP_TYPE_CSV2_CSV3
	// reset combo phy of dp lanes
	if (dptx_combo_phy_is_up(dptx)) {
		if (dptx->mode == TCPC_DP) {
			set_reg(dptx->combo_phy_base + 0x188, 0x080, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
			set_reg(dptx->combo_phy_base + 0x188, 0x0A0, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
			set_reg(dptx->combo_phy_base + 0x188, 0x0C0, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
			set_reg(dptx->combo_phy_base + 0x188, 0x0E0, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
		} else if (dptx->dptx_plug_type == TYPEC_ORIEN_POSITIVE) {
			set_reg(dptx->combo_phy_base + 0x188, 0x0A0, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
			set_reg(dptx->combo_phy_base + 0x188, 0x0E0, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
		} else {
			set_reg(dptx->combo_phy_base + 0x188, 0x080, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
			set_reg(dptx->combo_phy_base + 0x188, 0x0C0, 8, 0);
			dptx_pipe_combo_phy_wait_busy(dptx);
		}
	}
#endif

	// set 0xa4 to low
	phyifctrl &= ~cfg_phy_lanes(DPTX_MAX_LINK_LANES);
	dptx_writel(dptx, DPTX_PHYIF_CTRL1, phyifctrl);
}

static void dptx_set_double_tx_sync(struct dp_ctrl *dptx, struct dp_private *dp_pri)
{
	uint32_t reg;
	if (dptx == NULL || dp_pri == NULL) {
		dpu_pr_err("[DP] [dptx_set_double_tx_sync]input error, return!");
		return;
	}

	if (g_dp_debug_mode_enable)
		dptx_debug_get_double_tx_sync_para(dptx);

	if (dptx->is_double_tx_sync == true) {
		dpu_pr_info("[DP] is_double_tx_sync is true, id:%d, sync_id:%d", dptx->port_id, dptx->port_id_sync);
		if (dptx_convert_compare(dptx->port_id, dptx->port_id_sync, DPTX_PORT_ID_4, DPTX_PORT_ID_5)) {
			set_reg(dptx->hidptx_base + DPTX_GCTL0, 0x1, 1, 4);
			dpu_pr_info("[DP] set double tx true, double edp");
			reg = dptx_readl(dptx, DPTX_GCTL0);
		} else {
			set_reg(dptx->hidptx_base + DPTX_GCTL0, 0x1, 1, 4);

			if (dptx_convert_compare(dptx->port_id, dptx->port_id_sync, DPTX_PORT_ID_0, DPTX_PORT_ID_1) ||
				dptx_convert_compare(dptx->port_id, dptx->port_id_sync, DPTX_PORT_ID_2, DPTX_PORT_ID_3)) {
				set_reg(dp_pri->hsdt1_sysctrl_base + 0x0314, 0x0, 2, 0);
			} else if (dptx_convert_compare(dptx->port_id, dptx->port_id_sync, DPTX_PORT_ID_0, DPTX_PORT_ID_2) ||
				dptx_convert_compare(dptx->port_id, dptx->port_id_sync, DPTX_PORT_ID_1, DPTX_PORT_ID_3)) {
				set_reg(dp_pri->hsdt1_sysctrl_base + 0x0314, 0x1, 2, 0);
			} else if (dptx_convert_compare(dptx->port_id, dptx->port_id_sync, DPTX_PORT_ID_0, DPTX_PORT_ID_3) ||
				dptx_convert_compare(dptx->port_id, dptx->port_id_sync, DPTX_PORT_ID_1, DPTX_PORT_ID_2)) {
				set_reg(dp_pri->hsdt1_sysctrl_base + 0x0314, 0x2, 2, 0);
			} else {
				dpu_pr_err("[DP] cannt find suitable double tx");
				set_reg(dp_pri->hsdt1_sysctrl_base + 0x0314, 0x0, 2, 0);
			}
			dpu_pr_info("[DP] set double tx true, double dp");
			reg = dptx_readl(dptx, DPTX_GCTL0);
		}
	}
	return;
}

static int dptx_dis_reset(struct dp_ctrl *dptx, bool benable)
{
	struct dpu_connector *connector = NULL;
	struct dp_private *dp_pri = NULL;
	int ret;
	dp_ctrl_conf ctrl_conf;
	char __iomem *hsdt1_crg_base;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");

	ret = get_dp_ctrl_conf((uint32_t)dptx->port_id, &ctrl_conf);
	if (ret != 0) {
		dpu_pr_err("[DP] [get_dp_ctrl_conf] error, return!");
		return -EINVAL;
	}
	dpu_pr_info("[DP] [get_dp_ctrl_conf] benable = %d(true:1)", benable);

	connector = dptx->connector;
	dp_pri = to_dp_private(connector->conn_info);

	if (dptx->port_id == 4 || dptx->port_id == 5)
		hsdt1_crg_base = dp_pri->sub_harden_crg_base;
	else
		hsdt1_crg_base = dp_pri->hsdt1_crg_base;

	if (benable) { // open
		dpu_pr_info("[DP] [get_dp_ctrl_conf] close apb and dpc");
		set_reg(hsdt1_crg_base + ctrl_conf.apb_close_offset, 1, 1, ctrl_conf.apb_control_bit);
		set_reg(dp_pri->hsdt1_crg_base + ctrl_conf.dpc_close_offset, 1, 1, ctrl_conf.dpc_control_bit);
		// 1: open apb

		set_reg(hsdt1_crg_base + ctrl_conf.apb_open_offset, 1, 1, ctrl_conf.apb_control_bit);
		// 2: open dpc
		set_reg(dp_pri->hsdt1_crg_base + ctrl_conf.dpc_open_offset, 1, 1, ctrl_conf.dpc_control_bit);

		// 3: open apb clk
		set_reg(hsdt1_crg_base + ctrl_conf.apb_clk_open_offset, 1, 1, ctrl_conf.apb_clk_control_bit);
		// 4: open pixel clk
		set_reg(dp_pri->hsdt1_crg_base + ctrl_conf.pixel_clk_open_offset, 1, 1, ctrl_conf.pixel_clk_control_bit);
		// 5: set HPD GPIO mode -- When there is no external PD chip
		// todo
		// 6: HPD polarity inversion configuration: DPTX CTRL
		set_reg(dptx->hidptx_base + DPTX_GCTL0, 1, 1, 9);
		// 7: open aux clk
		set_reg(hsdt1_crg_base + ctrl_conf.aux_clk_open_offset, 1, 1, ctrl_conf.aux_clk_control_bit);
		// 8: open reset
		set_reg(dptx->hidptx_base + 0x700, 0x1, 1, 8);
		set_reg(dptx->hidptx_base + 0x700, 0x1, 1, 9);

		// reset combo phy of dp lanes
		dptx_combophy_ctrl_reset(dptx);
		mdelay(1); // ms

		// 9: set 0xa4 to hight;
		dptx_combophy_ctrl_set(dptx);

		// 10: set HDCP: DPTX_CTRL set in atf
		// 11: set aux's sync num: DPTX_CTRL, eDP panel set to 1, DP panel set to 0(Default value)
		if (dptx->connector->conn_info->base.mode == EDP_MODE) {
			set_reg(dptx->hidptx_base + 0x74, 1, 1, 1);
			dpu_pr_info("[DP] dptx_dis_reset dp_mode: %d", dptx->connector->conn_info->base.mode);
		} else {
			set_reg(dptx->hidptx_base + 0x74, 0, 1, 1);
			dpu_pr_info("[DP] dptx_dis_reset dp_mode: %d", dptx->connector->conn_info->base.mode);
		}
		// 12: dual panel：DPTX_CTRL, dual-eDP set to 1, other set to 0(Default value)
		dptx_set_double_tx_sync(dptx, dp_pri);
		// 14: SDP enable
		set_reg(dptx->hidptx_base + 0x708, 0x1, 1, 11);
		// 15: Mem power on：DPTX_CTRL, 0x718 set to 0x850, 0x71C set to 0x15858
		set_reg(dptx->hidptx_base + 0x718, 0x850, 32, 0);
		set_reg(dptx->hidptx_base + 0x71C, 0x15858, 32, 0);
	} else {
		// 7: reset combo phy of dp lanes
		dptx_combophy_ctrl_reset(dptx);

		// 6. close reset
		set_reg(dptx->hidptx_base + 0x700, 0x0, 1, 8);
		set_reg(dptx->hidptx_base + 0x700, 0x0, 1, 9);

		// 5: close aux clk  0x4 5bit
		set_reg(hsdt1_crg_base + ctrl_conf.aux_clk_close_offset, 1, 1, ctrl_conf.aux_clk_control_bit);
		// 4: close pixel clk
		set_reg(dp_pri->hsdt1_crg_base + ctrl_conf.pixel_clk_close_offset, 1, 1, ctrl_conf.pixel_clk_control_bit);
		// 3: close apb clk  0x4 6bit
		set_reg(hsdt1_crg_base + ctrl_conf.apb_clk_close_offset, 1, 1, ctrl_conf.apb_clk_control_bit);
		// 2: close dpc
		set_reg(dp_pri->hsdt1_crg_base + ctrl_conf.dpc_close_offset, 1, 1, ctrl_conf.dpc_control_bit);
		// 1: close apb
		set_reg(hsdt1_crg_base + ctrl_conf.apb_close_offset, 1, 1, ctrl_conf.apb_control_bit);
	}
	return 0;
}

void enable_dptx_timing_gen(struct dp_ctrl *dptx)
{
	uint32_t val;

	if (unlikely(!dptx)) {
		dpu_pr_warn("dptx is null");
		return;
	}

	if (!dptx->dptx_enable || dptx->power_saving_mode || dptx->is_power_offing) {
		dpu_pr_warn("dptx is unconnected or off.");
		return;
	}

	dptx_writel(dptx, dptx_dp_color_bar_stream(0), 0);

	if (dptx->dptx_triger_media_transfer)
		dptx->dptx_triger_media_transfer(dptx, true);

	val = dptx_readl(dptx, DPTX_GCTL0);
	val |= DPTX_CFG_TIMING_GEN_ENABLE;
	if (dptx->mst) {
		val |= DPTX_CFG_SST1_TIMING_GEN_ENABLE;
		dptx_writel(dptx, dptx_dp_color_bar_stream(1), 0x01);
	}

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
	void_unused(dptx0);
	void_unused(dptx1);
	void_unused(np);
	return 0;
}

int32_t init_dpctrl_16m_clk(struct dp_ctrl *dptx, struct device_node *np)
{
	dptx->clk_dpctrl_16m = of_clk_get(np, 0);
	if (IS_ERR_OR_NULL(dptx->clk_dpctrl_16m)) {
		dpu_pr_err("[DP] failed to get clk_dpctrl_16m!");
		return -ENXIO;
	}
	return 0;
}

int32_t init_hsdt1_sysctrl_base(struct dp_private *priv, struct device_node *np)
{
	priv->hsdt1_sysctrl_base = of_iomap(np, REG_HSDT1_SYSCTRL_BASE);
	if (!priv->hsdt1_sysctrl_base) {
		dpu_pr_err("[DP] failed to get dp_sctrl_base!");
		return -ENXIO;
	}
	return 0;
}

int32_t init_sub_harden_crg_base(struct dp_private *priv, struct device_node *np)
{
	priv->sub_harden_crg_base = of_iomap(np, REG_SUB_HARDEN_CRG_BASE);
	if (!priv->sub_harden_crg_base) {
		dpu_pr_err("[DP] failed to get sub_harden_crg_base!");
		return -ENXIO;
	}
	return 0;
}

struct pll_cfg_param {
	uint64_t refdiv;
	uint64_t fbdiv;
	uint64_t frac;
	uint64_t postdiv1;
	uint64_t postdiv2;
	uint64_t post_div;
};

static uint64_t dp_pixel_pll_conf_param_calc(uint64_t pixel_clock_cur, struct pll_cfg_param *cfg)
{
	int i, ceil_temp;
	uint64_t pll_freq_divider, vco_freq_output;
	int freq_divider_list[POSTDIV_ARRAY_SIZE] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		12, 14, 15, 16, 18, 20, 21, 24,
		25, 28, 30, 32, 35, 36, 40, 42,
		48, 49, 56, 64
	};
	int postdiv1_list[POSTDIV_ARRAY_SIZE] = {
		1, 2, 3, 4, 5, 6, 7, 8, 3, 5, 6,
		7, 5, 8, 6, 5, 7, 8, 5, 7, 6, 8,
		7, 6, 8, 7, 8, 7, 8, 8
	};
	int postdiv2_list[POSTDIV_ARRAY_SIZE] = {
		1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 2,
		2, 3, 2, 3, 4, 3, 3, 5, 4, 5, 4,
		5, 6, 5, 6, 6, 7, 7, 8
	};

	/* Fractional PLL can not output the so small clock,
	 post_div :
	 0-> 1 division frequency
	 1-> 2 division frequency
	 ... ...
	 */
	cfg->post_div = 0;
	if (pixel_clock_cur * (uint64_t)freq_divider_list[POSTDIV_ARRAY_SIZE - 1] < VCO_MIN_FREQ_OUPUT) {
		cfg->post_div = 1;
		pixel_clock_cur *= 2; /* multiple frequency */
	}

	ceil_temp = dp_ceil(VCO_MIN_FREQ_OUPUT, pixel_clock_cur);
	if (ceil_temp < 0)
		return pixel_clock_cur;

	pll_freq_divider = (uint64_t)ceil_temp;
	dpu_pr_info("[DP] ceil_temp=%d, pixel_clock_cur:%lu, cfg->post_div:%llu", ceil_temp, pixel_clock_cur, cfg->post_div);
	for (i = 0; i < POSTDIV_ARRAY_SIZE; i++) {
		if (freq_divider_list[i] >= (int)pll_freq_divider) {
			pll_freq_divider = (uint64_t)freq_divider_list[i];
			cfg->postdiv1 = (uint64_t)postdiv1_list[i] - 1;
			cfg->postdiv2 = (uint64_t)postdiv2_list[i] - 1;
			dpu_pr_info("[DP] i:%d, pll_freq_divider:%llu, postdiv1=0x%llx, postdiv2=0x%llx",
				i, pll_freq_divider, cfg->postdiv1, cfg->postdiv2);
			break;
		}
	}

	vco_freq_output = pll_freq_divider * pixel_clock_cur;
	if (vco_freq_output == 0)
		return pixel_clock_cur;

	dpu_pr_info("[DP] vco_freq_output=%llu", vco_freq_output);

	ceil_temp = dp_ceil(800000000UL, vco_freq_output);
	if (ceil_temp < 0)
		return pixel_clock_cur;

	cfg->refdiv = 1;
	dpu_pr_info("[DP] refdiv=0x%llx", cfg->refdiv);

	cfg->fbdiv = vco_freq_output * (uint64_t)ceil_temp * cfg->refdiv / SYS_FREQ;
	dpu_pr_info("[DP] fbdiv=0x%llx", cfg->fbdiv);

	cfg->frac = ((uint64_t)ceil_temp * vco_freq_output - SYS_FREQ / \
		cfg->refdiv * cfg->fbdiv) * cfg->refdiv * 0x1000000; /* 0x1000000 is 2^24 */
	cfg->frac = (uint64_t)cfg->frac / SYS_FREQ;

	dpu_pr_info("[DP] frac=0x%llx", cfg->frac);

	return pixel_clock_cur;
}

static void dptx_dpc_pll_param_set(char __iomem *hsdt1_crg_base, struct pll_cfg_param *cfg, dpc_pll_conf *pll_conf)
{
	uint32_t dpc_pll_ctrl0, dpc_pll_ctrl1;
	uint32_t dpc_pll_ctrl0_val, dpc_pll_ctrl1_val;

	dpc_pll_ctrl0 = inp32(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset);
	dpc_pll_ctrl0 &= ~DPC_PLL_FREQ_DEVIDER_MASK;

	dpc_pll_ctrl0_val = 0x0;
	dpc_pll_ctrl0_val |= (uint32_t)((cfg->postdiv2 << 23) | (cfg->postdiv1 << 20) | \
		(cfg->fbdiv << 8) | (cfg->refdiv << 2));
	dpc_pll_ctrl0_val &= DPC_PLL_FREQ_DEVIDER_MASK;

	dpc_pll_ctrl0 |= dpc_pll_ctrl0_val;
	outp32(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset, dpc_pll_ctrl0);

	dpc_pll_ctrl1 = inp32(hsdt1_crg_base + pll_conf->dpc_pll_ctrl1_offset);
	dpc_pll_ctrl1 &= ~DPC_PLL_FRAC_MODE_MASK;

	dpu_pr_info("[DP] dptx_dpc_pll_param_set cfg->frac = %lu", cfg->frac);
	dpc_pll_ctrl1_val = 0x0;
	dpc_pll_ctrl1_val |= (uint32_t)(1 << 25 | 0 << 24 | cfg->frac);
	dpc_pll_ctrl1_val &= DPC_PLL_FRAC_MODE_MASK;

	dpc_pll_ctrl1 |= dpc_pll_ctrl1_val;
	outp32(hsdt1_crg_base + pll_conf->dpc_pll_ctrl1_offset, dpc_pll_ctrl1);
}

static int32_t dptx_pll_config(char __iomem *hsdt1_crg_base, struct pll_cfg_param *cfg, dpc_pll_conf *pll_conf)
{
	uint32_t val;
	uint32_t delay_time = 0;
	uint32_t continue_lock_cnt = 0;

	// disable gate ~ gt_clk_dpc_pll0
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl1_offset, 0x0, 1, 26);

	// disable dpc_pll0_en
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset, 0x0, 1, 0);

	// enable bypass
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset, 0x1, 1, 1);

	// select dpc_pll x, hight bits and low bits must be set sametime in once order.
	val = ((pll_conf->pixel_clk_pll_sel << 7) | (0x3 << 23));
	dpu_pr_info("[DP] dptx_pll_config pll_conf->pixel_clk_pll_sel : %u", pll_conf->pixel_clk_pll_sel);
	set_reg(hsdt1_crg_base + pll_conf->pixel_clk_div_offset, val, 32, 0);

	// config postdiv hight bits and low bits must be set sametime in once order.
	val = (uint32_t)((cfg->post_div) | (0x3f << 16));
	dpu_pr_info("[DP] dptx_pll_config cfg->post_div = %llu", cfg->post_div);
	set_reg(hsdt1_crg_base + pll_conf->pixel_clk_div_offset, val, 32, 0);

	dptx_dpc_pll_param_set(hsdt1_crg_base, cfg, pll_conf);
	udelay(1); // us

	// enable dpc_pll0_en
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset, 0x1, 1, 0);

	// enable bypass
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset, 0x1, 1, 1);

	udelay(20); // us

	// wait for dpc pll locked
	do {
		delay_time++;
		val = inp32(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset);
		if ((val & DPC_PLL_LOCK_MASK) == DPC_PLL_LOCK_MASK) {
			continue_lock_cnt++;
		} else {
			continue_lock_cnt = 0;
		}
		udelay(1);
		if (delay_time > DPC_PLL_STABLE_TIME) {
			dpu_pr_err("[DP] dpc pll lock timeout!");
			return -1;
		}
	} while (continue_lock_cnt < DPC_PLL_CONTINUE_LOCK_CNT);

	// enable dpc_pllx_en
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset, 0x1, 1, 0);

	// disable bypass
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl0_offset, 0x0, 1, 1);

	// enable gate ~ gt_clk_dpc_pllx
	set_reg(hsdt1_crg_base + pll_conf->dpc_pll_ctrl1_offset, 0x1, 1, 26);

	// enable gate ~ sc_gt_clk_pll_dpcx
	set_reg(hsdt1_crg_base + pll_conf->pixel_clk_div_offset, 0x1, 1, 6);
	set_reg(hsdt1_crg_base + pll_conf->pixel_clk_div_offset, 0x1, 1, 22);

	set_reg(hsdt1_crg_base + pll_conf->gt_clk_dptx_pixel_offset, 0x1, 1, (uint8_t)pll_conf->gt_clk_dptx_pixel_bit);

	return 0;
}

static void dptx_clk_pixel_setup(int port_id, dpc_pll_conf *pll_conf)
{
	switch (port_id) { // port_id range is [0,5] in v740
	case DPTX_PORT_ID_0:
		pll_conf->pixel_clk_div_offset = CLKDIV_OFFSET_DP;
		pll_conf->gt_clk_dptx_pixel_offset = 0x030;
		pll_conf->gt_clk_dptx_pixel_bit = 16;
		break;
	case DPTX_PORT_ID_1:
		pll_conf->pixel_clk_div_offset = CLKDIV_OFFSET_DP1;
		pll_conf->gt_clk_dptx_pixel_offset = 0x030;
		pll_conf->gt_clk_dptx_pixel_bit = 15;
		break;
	case DPTX_PORT_ID_2:
		pll_conf->pixel_clk_div_offset = CLKDIV_OFFSET_DP2;
		pll_conf->gt_clk_dptx_pixel_offset = 0x030;
		pll_conf->gt_clk_dptx_pixel_bit = 14;
		break;
	case DPTX_PORT_ID_3:
		pll_conf->pixel_clk_div_offset = CLKDIV_OFFSET_DP3;
		pll_conf->gt_clk_dptx_pixel_offset = 0x030;
		pll_conf->gt_clk_dptx_pixel_bit = 13;
		break;
	case DPTX_PORT_ID_4:
		pll_conf->pixel_clk_div_offset = CLKDIV_OFFSET_EDP;
		pll_conf->gt_clk_dptx_pixel_offset = 0x010;
		pll_conf->gt_clk_dptx_pixel_bit = 15;
		break;
	case DPTX_PORT_ID_5:
		pll_conf->pixel_clk_div_offset = CLKDIV_OFFSET_EDP1;
		pll_conf->gt_clk_dptx_pixel_offset = 0x010;
		pll_conf->gt_clk_dptx_pixel_bit = 11;
		break;
	default:
		dpu_pr_err("[DP] dptx clk pixel setup: invalid port_id!");
		return;
	}
	return;
}

static void dptx_clk_dpc_select(struct dp_ctrl *dptx, dpc_pll_conf *pll_conf)
{
	if (dptx == NULL) {
		dpu_pr_err("[DP] dptx is NULL!");
		return;
	}

	switch (dptx->dpc_index_selected) { // dpc num is [0,2] in v740
	case DPTX_DPC_NUM_0:
		// pll0
		pll_conf->pixel_clk_pll_sel = PLL_DPC0;
		pll_conf->dpc_pll_ctrl0_offset = DPC_PLL0_CTRL0;
		pll_conf->dpc_pll_ctrl1_offset = DPC_PLL0_CTRL1;
		break;
	case DPTX_DPC_NUM_1:
		// pll1
		pll_conf->pixel_clk_pll_sel = PLL_DPC1;
		pll_conf->dpc_pll_ctrl0_offset = DPC_PLL1_CTRL0;
		pll_conf->dpc_pll_ctrl1_offset = DPC_PLL1_CTRL1;
		break;
	case DPTX_DPC_NUM_2:
		// pll2
		pll_conf->pixel_clk_pll_sel = PLL_DPC2;
		pll_conf->dpc_pll_ctrl0_offset = DPC_PLL2_CTRL0;
		pll_conf->dpc_pll_ctrl1_offset = DPC_PLL2_CTRL1;
		break;
	default:
		dpu_pr_err("[DP] invalid dpc number!");
		return;
	}
	dpu_pr_info("[DP] dptx->dpc_index_selected = %d", dptx->dpc_index_selected);
	return;
}

static int32_t dptx_dpc_pll_select_and_config(struct dp_ctrl *dptx, struct pll_cfg_param *cfg, dpc_pll_conf *pll_conf)
{
	struct dp_private *dp_priv = NULL;

	dpu_check_and_return(!dptx || !cfg || !pll_conf, -EINVAL, err, "[DP] dptx is NULL!");
	dp_priv = to_dp_private(dptx->connector->conn_info);
	dpu_check_and_return(!dp_priv, -EINVAL, err, "[DP] dp_priv is null pointer!");

	if (g_dp_debug_mode_enable)
		dptx_debug_get_double_tx_sync_para(dptx);

	if (dptx->is_double_tx_sync) {
		// port_id and port_id_sync all select the same pll
		dptx->dpc_index_selected = DPTX_DPC_NUM_2;
		dpu_pr_info("[DP] dptx_dpc_pll_select_and_config set same DPC");
	}

	dptx_clk_dpc_select(dptx, pll_conf);
	dptx_clk_pixel_setup(dptx->port_id, pll_conf);
	dptx_pll_config(dp_priv->hsdt1_crg_base, cfg, pll_conf);

	return 0;
}

int dptx_pixel_pll_preinit(void)
{
	// disable dpc pll register secure access, modify to non-secure for kenel to config
	configure_dss_service_security(FID_BL31_DISPLAY_HSDT_PLL_NS_CONFIG, 0, 0, 0);
	dpu_pr_info("[DP] [dptx_pixel_pll_preinit] do configure_dss_service_security");

	return 0;
}

int dptx_pixel_pll_init(struct dp_ctrl *dptx, uint64_t pixel_clock)
{
	int ret = 0;
	uint64_t pixel_clock_cur;
	struct pll_cfg_param cfg;
	dpc_pll_conf pll_conf;

	dpu_check_and_return(!dptx || !pixel_clock, -EINVAL, err, "[DP] pixel pll init: input err!");

	pixel_clock_cur = dp_pixel_pll_conf_param_calc(pixel_clock, &cfg);

	ret = dptx_dpc_pll_select_and_config(dptx, &cfg, &pll_conf);
	dpu_pr_info("[DP] pixel pll init: ori[%llu]->[%llu]", pixel_clock, pixel_clock_cur);

	return ret;
}

int dptx_pixel_pll_deinit(struct dp_ctrl *dptx)
{
	struct dp_private *dp_priv = NULL;
	uint32_t dpc_pll_ctrl0_offset, dpc_pll_ctrl1_offset;

	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] pixel pll deinit: input err!");

	dp_priv = to_dp_private(dptx->connector->conn_info);
	dpu_check_and_return(!dp_priv, -EINVAL, err, "[DP] dp_priv is null pointer!");

	dpu_pr_info("[DP] pixel pll deinit: dpc_index_selected is %d", dptx->dpc_index_selected);
	switch (dptx->dpc_index_selected) {
	case DPTX_DPC_NUM_0:
		// pll 0
		dpc_pll_ctrl0_offset = DPC_PLL0_CTRL0;
		dpc_pll_ctrl1_offset = DPC_PLL0_CTRL1;
		break;
	case DPTX_DPC_NUM_1:
		// pll 1
		dpc_pll_ctrl0_offset = DPC_PLL1_CTRL0;
		dpc_pll_ctrl1_offset = DPC_PLL1_CTRL1;
		break;
	case DPTX_DPC_NUM_2:
		// pll 2
		dpc_pll_ctrl0_offset = DPC_PLL2_CTRL0;
		dpc_pll_ctrl1_offset = DPC_PLL2_CTRL1;
		break;
	default:
		dpu_pr_err("[DP] pixel pll deinit: invalid port_id!");
		return -1;
	}

	// disable dpc_pllx_en
	set_reg(dp_priv->hsdt1_crg_base + dpc_pll_ctrl0_offset, 0x0, 1, 0);
	// enable bypass
	set_reg(dp_priv->hsdt1_crg_base + dpc_pll_ctrl0_offset, 0x1, 1, 1);
	// disable gate ~ gt_clk_dpc_pllx
	set_reg(dp_priv->hsdt1_crg_base + dpc_pll_ctrl1_offset, 0x0, 1, 26);

	return 0;
}

static void dp_disable_clk(struct dp_ctrl *dptx)
{
	/* disable clk */
	if (dptx->port_id == DPTX_PORT_ID_4 || dptx->port_id == DPTX_PORT_ID_5) {
		/* disable clk_dpctrl_16m */
		clk_disable_unprepare(dptx->clk_dpctrl_16m);
	} else { /* -1 or 0~3 */
		/* disable clock */
		clk_disable_unprepare(dptx->connector->connector_clk[CLK_DPCTRL_16M]);
		clk_disable_unprepare(dptx->connector->connector_clk[CLK_DPCTRL_PCLK]);
	}
}

int dp_pm_freeze(struct device *dev)
{
	struct dp_private *priv = NULL;
	struct dp_ctrl *dptx = NULL;
	struct dkmd_connector_info *pinfo = NULL;
	struct dpu_connector *connector = NULL;

	dpu_pr_info("[DP] enter +!\n");
	priv = (struct dp_private *)dev_get_drvdata(dev);
	if (!priv) {
		dpu_pr_err("[DP] get dp private data failed!\n");
		return 0;
	}
	dptx = &priv->dp[MASTER_DPTX_IDX];
	if (!dptx) {
		dpu_pr_err("[DP] get dp dptx failed!\n");
		return 0;
	}
	pinfo = &priv->connector_info;
	if (!pinfo) {
		dpu_pr_err("[DP] get dp pinfo failed!\n");
		return 0;
	}
	connector = get_primary_connector(pinfo);
	if (!connector) {
		dpu_pr_err("[DP] get dp connector failed!\n");
		return 0;
	}
	dpu_pr_info("[DP] reset startup flag\n");

	/* Turn off the backlight and TCON LOGO in the freeze phase of S4 wakeup. */
	if ((dpm_get_message_event() == PM_EVENT_QUIESCE) && is_primary_panel(&pinfo->base)) {
		if (dptx->dptx_aux_set_backlight_config && dptx->dptx_enable &&
			!dptx->power_saving_mode && !dptx->is_power_offing)
			dptx->dptx_aux_set_backlight_config(dptx);
		dkmd_notifier_call_chain(DKMD_EVENT_CLOSE_TCON_LOGO, NULL);
	}

	atomic_set(&(dptx->edid_reads), NEED_READ_EDID);
	dpu_pr_info("[DP] edid_reads:%d!!!", atomic_read(&dptx->edid_reads));
	return dp_pm_suspend(dev);
}

void dp_shutdown(struct platform_device *pdev)
{
	dpu_pr_info("[DP] dp_shutdown enter +!\n");
	struct dp_private *priv = platform_get_drvdata(pdev);
	struct dp_ctrl *dptx = NULL;

	if (!priv) {
		dpu_pr_err("[DP] get dp private data failed!\n");
		return;
	}
	dptx = &priv->dp[MASTER_DPTX_IDX];
    if (!dptx) {
        dpu_pr_err("[DP] get dp dptx failed!\n");
        return;
    }
	if (dptx->connector->conn_info->base.mode != EDP_MODE) {
		dpu_pr_info("[DP] the screen is not edp\n");
		return;
	}

	connector_device_suspend(&priv->connector_info);
}

int dp_pm_suspend(struct device *dev)
{
	struct dp_private *priv = NULL;
	struct dp_ctrl *dptx = NULL;

	dpu_pr_info("[DP] enter +!\n");
	priv = (struct dp_private *)dev_get_drvdata(dev);
	if (!priv) {
		dpu_pr_err("[DP] get dp private data failed!\n");
		return 0;
	}
	dptx = &priv->dp[MASTER_DPTX_IDX];
	if (!dptx) {
		dpu_pr_err("[DP] get dp dptx failed!\n");
		return 0;
	}
	connector_device_suspend(&priv->connector_info);

	if (is_ulsr()) {
		atomic_set(&(dptx->edid_reads), NEED_READ_EDID);
		dpu_pr_info("[DP] dp_pm_suspend ulsr enter");
	}

	if (dptx->connector->off_func && dptx->connector->conn_info->base.mode != EDP_MODE)
		dptx->connector->off_func(dptx->connector->conn_info);
	if (dptx->dp_info)
		dptx->dp_info->is_dprx_ready = false;

	dpu_pr_warn("[DP] exit - portid: %d!, clk cnt: %u-%u-%u\n",
		dptx->port_id, clk_get_enable_count(dptx->clk_dpctrl_16m),
		clk_get_enable_count(dptx->connector->connector_clk[CLK_DPCTRL_16M]),
		clk_get_enable_count(dptx->connector->connector_clk[CLK_DPCTRL_PCLK]));
	return 0;
}

int dp_pm_resume(struct device *dev)
{
	struct dp_private *priv = NULL;
	struct dp_ctrl *dptx = NULL;

	dpu_pr_info("[DP] enter +!\n");
	priv = (struct dp_private *)dev_get_drvdata(dev);
	if (!priv) {
		dpu_pr_err("[DP] get dp private data failed!\n");
		return 0;
	}
	dptx = &priv->dp[MASTER_DPTX_IDX];
	if (!dptx) {
		dpu_pr_err("[DP] get dp dptx failed!\n");
		return 0;
	}
	dpu_pr_info("[DP] portid:%d\n", dptx->port_id);
	if (dptx->dptx_combophy_power_saving_handler)
		dptx->dptx_combophy_power_saving_handler(dptx);
	dpu_pr_info("[DP] enter -!\n");
	return 0;
}

void dptx_phy_lane_reset(struct dp_ctrl *dptx, bool mainlink_open)
{
	dpu_check_and_no_retval(!dptx, err, "[DP] null pointer");

	if (mainlink_open) {
		// P0 mode, disreset lanes
		// set 0xa4 to hight;
		dptx_combophy_ctrl_set(dptx);
	} else {
		// reset combo phy of dp lanes
		dptx_combophy_ctrl_reset(dptx);
	}
}

static void dptx_hdcp_enable_video_transform(struct dp_ctrl *dptx, bool enable)
{
	uint32_t status;
	unsigned int opt_array[] = {
		DSS_HDCP_DP_ENABLE,
		DSS_HDCP_DP1_ENABLE,
		DSS_HDCP_DP2_ENABLE,
		DSS_HDCP_DP3_ENABLE,
		DSS_HDCP_DP4_ENABLE,
		DSS_HDCP_DP5_ENABLE
	};
	size_t array_size = sizeof(opt_array) / sizeof(opt_array[0]);

	if (dptx->port_id >= (int)array_size || dptx->port_id < 0) {
		dpu_pr_err("[DP] dptx->port_id = %d, array_size = %lu", dptx->port_id, array_size);
		return;
	}

	status = enable ? 1 : 0;
	dpu_pr_info("[DP] [port_id:%d] status:%u", dptx->port_id, status);
	configure_dss_service_security(FID_BL31_DISPLAY_HSDT_PLL_DP_CONFIG, (uint32_t)dptx->port_id, status, 0);

	return;
}

#define DSS2DPTX_SEL 0x300

static void dptx_config_stream_timing(struct dp_ctrl *dptx)
{
	uint32_t reg, idx;
	int port_id;
	struct ldi_panel_info *ldi = NULL;
	struct dkmd_connector_info *pinfo = NULL;
	struct dp_private *dp_priv = NULL;
	ldi = &dptx->connector->ldi;
	pinfo = dptx->connector->conn_info;
	
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

	dp_priv = to_dp_private(dptx->connector->conn_info);
	dpu_check_and_no_retval(!dp_priv, err, "[DP] dp_priv is null pointer!\n");
	idx = (uint32_t)dptx->post_chn;
	if (idx > MAX_DP_HDMITX_POST_CHN_INDEX || idx < MIN_DP_HDMITX_POST_CHN_INDEX) {
		dpu_pr_err("[DP] sw_post_chn_idx is error, idx = %d", idx);
		return;
	}

	dptx->connector->conn_info->sw_post_chn_idx[PRIMARY_CONNECT_CHN_IDX] = idx;
	port_id = dptx->port_id;
	dpu_pr_debug("[DP] sw_post_chn_idx is = %d, portid = %d", idx, port_id);
	if (port_id < DPTX_PORT_ID_0 ||  port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port_id is error, id = %d", port_id);
		return;
	}

	dptx_hdmitx_config_stream_timing_set_sysctrl(dp_priv->hsdt1_sysctrl_base, DSS2DPTX_SEL,
		idx - MIN_DP_HDMITX_POST_CHN_INDEX, port_id_sysctrl_value[port_id]);
	set_reg(dp_priv->hsdt1_sysctrl_base + DSS2DPTX_SEL, port_id_sysctrl_value[port_id], 4,
		(idx - MIN_DP_HDMITX_POST_CHN_INDEX) * 4);
}

static void dptx_check_underflow_status(struct dp_ctrl *dptx, struct ukmd_isr *isr_ctrl)
{
	uint32_t reg = 0;
	uint32_t max_underflow_status_count = 3;
	dpu_check_and_no_retval(!dptx, err, "[DP] NULL Pointer\n");

	reg = dptx_readl(dptx, DPTX_DFX_STATUS0);
	reg &= DPTX_VEDIO_SAMPLE_UNDERFLOW;
	if (reg != 0) {
		dpu_pr_err("[DP] DP is underflow");
		dptx->psr_params.underflow_status_count += 1;
		if (!dptx->psr_params.is_psr2_underflow_handle && dptx->psr_params.underflow_status_count >= max_underflow_status_count) {
			dpu_pr_warn("[DP] notify underflow again");
			dptx->psr_params.underflow_status_count = 0;
			dptx_underflow_pre_handle(dptx);
			ukmd_isr_notify_listener(isr_ctrl, DSI_INT_UNDER_FLOW);
		}
	} else {
		dptx->psr_params.underflow_status_count = 0;
	}
}

static void dpu_dp_timing_isr_handle(struct dp_ctrl *dptx, struct ukmd_isr *isr_ctrl, uint32_t timing_gen_irq_status)
{
	int retval;

	dpu_check_and_no_retval(!dptx, err, "[DP] NULL Pointer\n");
	if (timing_gen_irq_status & DPTX_IRQ_VSYNC) {
		dpu_pr_debug("[DP] DPTX_IRQ_VSYNC received:port %d", dptx->port_id);
		ukmd_isr_notify_listener(isr_ctrl, DSI_INT_VSYNC);
		dptx_check_link_data_error(dptx);
	}

	if (timing_gen_irq_status & DPTX_IRQ_VACTIVE_START) {
		dpu_pr_debug("[DP] DPTX_VACTIVE_START received:port %d", dptx->port_id);
		if (!dptx->psr_params.is_psr_active)
			ukmd_isr_notify_listener(isr_ctrl, DSI_INT_VACT0_START);
		if (!dptx_is_usb_dp_panel(dptx->port_id))
				outp32(DPU_DM_LAYER_HEIGHT_ADDR(dptx->dpu_base_in_dp + DACC_OFFSET + DM_INPUTDATA_ST_ADDR6, LAYER_ACTIVE),  dptx->count_active0++);
	}

	if ((bool)(timing_gen_irq_status & DPTX_IRQ_STREAM0_UNDERFLOW) && !dptx->dptx_underflow_clear) {
		dpu_pr_warn("[DP] [DP-IRQ] DPTX_IRQ_STREAM0_UNDERFLOW port:%d", dptx->port_id);
		dptx_underflow_pre_handle(dptx);
		ukmd_isr_notify_listener(isr_ctrl, DSI_INT_UNDER_FLOW);
	}

	if (timing_gen_irq_status & DPTX_PSR_ACTIVE_SDP_INTR)
		dpu_pr_debug("[DP] TX PSR active SDP");

	if (timing_gen_irq_status & DPTX_PSR_INACTIVE_SDP_INTR)
		dpu_pr_debug("[DP] TX PSR inactive SDP");

	if (timing_gen_irq_status & DPTX_PSR_UPDATE_INTR)
		dpu_pr_debug("[DP] TX PSR update");

	if (timing_gen_irq_status & DPTX_PSR_ENTRY_INTR) {
		dptx->psr_params.is_psr_active = true;
		dptx->psr_params.psr_frame_idx = 1;
		dptx->psr_params.non_psr_frame_idx = 0;
		if (dptx->dp_present) {
			dpu_pr_info("vactive_start_flag is %u and needed to be reset when eDP PSR entry", dptx->dp_present->vactive_start_flag);
			dptx->dp_present->vactive_start_flag = 0;
		}
		if (dptx->psr_params.ml_close_require && dptx->psr_params.psr_version == DP_PSR_IS_SUPPORTED) {
			retval = dptx_psr_ml_config(dptx, LANE_POWER_MODE_P3);
			if (retval)
				dpu_pr_err("[DP] Config mainlink status P3 fail");
		}
		dpu_pr_info("[DP] TX PSR entry");
	}

	if (timing_gen_irq_status & DPTX_PSR_EXIT_INTR)
		dpu_pr_debug("[DP] TX PSR exit");
}

static void dpu_dp_intr_psr2_vactive_start(struct dp_ctrl *dptx)
{
	uint32_t reg;
	dpu_pr_debug("[DP] TX PSR2 vactive start uflag:%d, aflag:%d",
		g_dptx_psr2_burst_update_flag, g_dptx_psr2_update_after_entry_flag);

	if ((bool)g_dptx_psr2_burst_update_flag || (bool)g_dptx_psr2_update_after_entry_flag) {
		if (g_dptx_psr2_burst_update_times < 120 &&
				(31 + g_dptx_psr2_burst_update_times * 32) < 1440) {
			g_dptx_psr2_burst_update_times++;

			reg = 0; // replace of dptx->vparams.mdtd.h_active;
			reg |= (((31 + g_dptx_psr2_burst_update_times * 32) > 1440 ?
				1440 : (31 + (uint32_t)g_dptx_psr2_burst_update_times * 32)) << 16);
			dptx_writel(dptx, DPTX_SU_COO_BR, reg);

			reg = 0;
			reg &= ~DPTX_CFG_SU_COO_BR_X_MASK;
			reg &= ~DPTX_CFG_SU_COO_BR_Y_MASK;
			reg |= ((((31 + g_dptx_psr2_burst_update_times * 32) > 1440 ?
				1440 : (31 + (uint32_t)g_dptx_psr2_burst_update_times * 32)) - 15) << 16);
			dptx_writel(dptx, DPTX_SU_COO_TL, reg);

			dpu_pr_info("[DP] TX PSR2 vactive times:%d, value: %d",
				g_dptx_psr2_burst_update_times, 31 + g_dptx_psr2_burst_update_times * 32);
		} else {
			g_dptx_psr2_burst_update_flag = 0;
			g_dptx_psr2_update_after_entry_flag = 0;
			g_dptx_psr2_burst_update_times = 0;
		}
	}

	if (g_dptx_psr2_exit_after_update_flag) {
		g_dptx_psr2_exit_after_update_flag = 0;
		if (dptx->psr_params.psr2_enable != false) {
			dpu_pr_info("[DP] psr2 disable.\n");
			dptx->psr_params.psr2_enable = false;
			reg = dptx_readl(dptx, DPTX_PSR_CTRL);
			reg |= DPTX_CFG_PSR_EXIT;
			dptx_writel(dptx, DPTX_PSR_CTRL, reg);
		}
	}
}

static void dpu_dp_intr_psr_stream0_frame(struct dp_ctrl *dptx) {
	uint32_t reg;
	if (g_dptx_psr_burst_update_flag) {
		if (g_dptx_psr_burst_update_times <= 3) {
			g_dptx_psr_burst_update_times++;
			reg = dptx_readl(dptx, DPTX_PSR_CTRL);
			reg |= DPTX_CFG_PSR_UPDATE_ENABLE;
			dptx_writel(dptx, DPTX_PSR_CTRL, reg);
		} else {
			g_dptx_psr_burst_update_flag = 0;
			g_dptx_psr_burst_update_times = 0;
		}
	}

	if (g_dptx_psr_update_after_entry_flag) {
		g_dptx_psr_update_after_entry_flag = 0;
		reg = dptx_readl(dptx, DPTX_PSR_CTRL);
		reg |= DPTX_CFG_PSR_UPDATE_ENABLE;
		dptx_writel(dptx, DPTX_PSR_CTRL, reg);
	}

	if (g_dptx_psr_exit_after_update_flag) {
		g_dptx_psr_exit_after_update_flag = 0;
		reg = dptx_readl(dptx, DPTX_PSR_CTRL);
		reg |= DPTX_CFG_PSR_EXIT;
		dptx_writel(dptx, DPTX_PSR_CTRL, reg);
	}
}

static void dpu_dp_intr_handle(struct dp_ctrl *dptx, struct ukmd_isr *isr_ctrl, uint32_t intr_status)
{
	uint32_t val = 0;

	dpu_check_and_no_retval(!dptx, err, "[DP] NULL Pointer\n");
	if (intr_status & DPTX_IRQ_STREAM0_FRAME)
		dpu_pr_debug("[DP] DPTX_IRQ_STREAM0_FRAME irq received:port %d", dptx->port_id);

	if (intr_status & DPTX_SU_UPDATE)
		dpu_pr_debug("[DP] TX PSR2 SU update");

	if (intr_status & DPTX_CFG_ALPM_ENTRY) {
		dpu_pr_debug("[DP] TX PSR2 DPTX_CFG_ALPM_ENTRY");
		if (!dptx_is_usb_dp_panel(dptx->port_id)) {
			dpu_pr_debug("[DP] DPTX_SU_UPDATE, count_active1:%d", dptx->count_active1);
			outp32(DPU_DM_LAYER_MASK_Y0_ADDR(dptx->dpu_base_in_dp + DACC_OFFSET + DM_INPUTDATA_ST_ADDR6, LAYER_ACTIVE), dptx->count_active1++);
			ukmd_isr_notify_listener(isr_ctrl, DSI_INT_VACT0_END);
			dptx->alpm_entry_time = ktime_to_us(ktime_get());
			kthread_queue_work(&dptx->handle_worker, &dptx->alpm_irq_handle_work);
		}
	}

	if (intr_status & DPTX_CFG_ALPM_EXIT) {
		dpu_pr_debug("[DP] TX PSR2 DPTX_CFG_ALPM_EXIT");
		dptx_check_underflow_status(dptx, isr_ctrl);
		dptx_rgb_crc_check(dptx);
	}

	if (intr_status & DPTX_PSR2_VACTIVE_START) {
		if (dptx->psr_params.is_psr_active) {
			ukmd_isr_notify_listener(isr_ctrl, DSI_INT_VACT0_START);
			if (!dptx_is_usb_dp_panel(dptx->port_id))
				outp32(DPU_DM_LAYER_HEIGHT_ADDR(dptx->dpu_base_in_dp + DACC_OFFSET + DM_INPUTDATA_ST_ADDR6, LAYER_ACTIVE),  dptx->count_active0++);
		}
		dpu_dp_intr_psr2_vactive_start(dptx);
	}

	if (intr_status & DPTX_IRQ_STREAM0_SDP) {
		dpu_pr_debug("[DP] TX SDP send");
		val = dptx_readl(dptx, DPTX_INTR_ACPU_TIMING_GEN_ENABLE);
		val |= DPTX_IRQ_STREAM0_UNDERFLOW;
		dptx_writel(dptx, DPTX_INTR_ACPU_TIMING_GEN_ENABLE, val);
	}
}

static void dptx_init_coord(struct dp_ctrl *dptx)
{
	struct dkmd_connector_info *pinfo = NULL;

	if (unlikely(!dptx->connector) || unlikely(!dptx->connector->conn_info)) {
		dpu_pr_err("[DP] dptx connector or conn_info is NULL");
		return;
	}

	pinfo = dptx->connector->conn_info;

	if (pinfo->dirty_region_updt_support == 0)
		return;

	dptx->su_rect.top_x = 0;
	dptx->su_rect.top_y = 0;
	dptx->su_rect.bottom_x = (uint16_t)dpu_width(pinfo->base.xres);
	dptx->su_rect.bottom_y = (uint16_t)dpu_height(pinfo->base.yres);

	dptx->dptx_psr2_config_su_region(dptx);

	dpu_pr_debug("[DP] xres is %d, yres is %d", pinfo->base.xres, pinfo->base.yres);
}

static int dptx_power_handler_on(struct dp_ctrl *dptx)
{
	dptx->max_rate = (uint8_t)dptx->connector->conn_info->max_dptx_rate;
	dptx->max_rcm_rate = dptx->max_rate;
	dpu_pr_info("[DP] dp_reset_max_params rate=%u, mode = %hhu", dptx->max_rate, dptx->mode);
	switch (dptx->mode) {
	case TCPC_DP:
		dptx->max_lanes = 4;
		dpu_pr_info("[DP] dp_get_lanes_mode lanes=4");
		break;
	case TCPC_USB31_AND_DP_2LINE:
		dptx->max_lanes = 2;
		dpu_pr_info("[DP] dp_get_lanes_mode lanes=2");
		break;
	default:
		dptx->max_lanes = 4;
		dpu_pr_err("[DP] not supported tcpc_mux_ctrl_type=%hhu", dptx->mode);
		return -EINVAL;
	}

	if (dptx->dptx_combophy_reset && (dptx->dptx_combophy_reset(dptx, true) != 0)) {
		dpu_pr_err("[DP] dptx PHY init failed!\n");
		return -1;
	}

	if (dptx->dp_dis_reset)
		dptx->dp_dis_reset(dptx, true);

	if (dptx->dptx_ctrl_clk_enable(dptx) != 0) {
		dpu_pr_err("[DP] dptx ctrl clk enable failed!\n");
		return -1;
	}

	if (dptx->dptx_core_on)
		dptx->dptx_core_on(dptx);
	dpu_pr_info("[DP] Retraining when blank on!");
	if (dptx->dptx_hpd_handler && dptx->dptx_hpd_handler(dptx, true, dptx->max_lanes) != 0) {
		dpu_pr_err("[DP] dptx hpd handler failed!\n");
		dptx->dp_disable_clk(dptx);
		return -1;
	}

	if (dptx->dptx_audio_config)
		dptx->dptx_audio_config(dptx);

	dptx_init_coord(dptx);
	return 0;
}

static int dptx_power_handler_off(struct dp_ctrl *dptx)
{
	struct dkmd_connector_info *pinfo = NULL;
	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");
	pinfo = dptx->connector->conn_info;
	dpu_check_and_return(!pinfo, -EINVAL, err, "[DP] pinfo is NULL!");

	dptx_psr_params_reset(dptx);
	if (dptx->dptx_disable_default_video_stream)
		dptx->dptx_disable_default_video_stream(dptx, 0);

	if (dptx->dptx_triger_media_transfer)
		dptx->dptx_triger_media_transfer(dptx, false);

	dptx_wait_for_last_frame_finished(pinfo, DELAY_HANDLE);

	dptx_write_dpcd(dptx, DP_SET_POWER, DP_SET_POWER_D3);

	// for cdc_ace, after dp power off need reset 983.
	if (dptx->dp_info && dptx->dp_info->notify_ser_dp_unplug)
		dptx->dp_info->notify_ser_dp_unplug(dptx->port_id);

	mdelay(20);
	if (dptx->dptx_link_close_stream)
		dptx->dptx_link_close_stream(dptx);

	if (dptx->dptx_core_off)
		dptx->dptx_core_off(dptx);

	if (dptx->dp_dis_reset)
		dptx->dp_dis_reset(dptx, false);

	if (dptx->dptx_combophy_reset && (dptx->dptx_combophy_reset(dptx, false) != 0)) {
		dpu_pr_err("[DP] dptx PHY close failed!\n");
		return -1;
	}
	/* disable  clk */
	if (dptx->dp_disable_clk)
		dptx->dp_disable_clk(dptx);

	dpu_pr_info("[DP] Disable stream when blank off\n");

	return 0;
}

static int dptx_power_handler(struct dp_ctrl *dptx, bool ublank)
{
	int ret = 0;
	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");

	if (ublank) {
		ret = dptx_power_handler_on(dptx);
	} else {
		ret = dptx_power_handler_off(dptx);
	}
	return ret;
}

static void dptx_show_phy_status_handler(struct dp_ctrl *dptx)
{
	uint32_t reg_index = 0;
	const uint32_t phy_addr_delta = 0x800;
	const uint32_t lane_addr_delta = 0x200;
	uint32_t pcs_info[12] = {0};
	struct dp_private *dp_priv = NULL;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!");
	dp_priv = to_dp_private(dptx->connector->conn_info);
	dpu_check_and_no_retval(!dp_priv, err, "[DP] dp_priv is NULL!");

	dpu_pr_info("[DP] %d-%u, A4=0x%x, PCE0=0x%x, PS0=0x%x, PRS0=0x%x, KB=0x%x, L=0x%x, C=0x%x",
		dptx->port_id, dptx->link.lanes,
		dptx_readl(dptx, DPTX_PHYIF_CTRL1),
		inp32(SOC_HSDT1_SUB_HARDEN_CRG_PERCLKEN0_ADDR(dp_priv->sub_harden_crg_base)), /* 0x8 */
		inp32(SOC_HSDT1_SUB_HARDEN_CRG_PERSTAT0_ADDR(dp_priv->sub_harden_crg_base)), /* 0xC */
		inp32(SOC_HSDT1_SUB_HARDEN_CRG_PERRSTSTAT0_ADDR(dp_priv->sub_harden_crg_base)), /* 0x68 */
		inp32(SOC_HiU31dpedp_PHY_PCS_PLL1_KBAND_CPLT_ADDR(dptx->combo_phy_base)), /* 0x3AC */
		inp32(SOC_HiU31dpedp_PHY_PCS_PLL1_LOCK_DET_RO_ADDR(dptx->combo_phy_base)), /* 0x3A8 */
		inp32(SOC_HiU31dpedp_PHY_PCS_DFX_CRG_ADDR(dptx->combo_phy_base)) /* 0x788 */);

	switch (dptx->link.lanes) {
	case 4:
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_4_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 3, 3)); /* 0x194 */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 3, 3)); /* 0x19C */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_2_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 3, 3)); /* 0x1A0 */

		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_4_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 2, 2)); /* 0x194 */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 2, 2)); /* 0x19C */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_2_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 2, 2)); /* 0x1A0 */
	case 2:
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_4_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 1, 1)); /* 0x194 */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 1, 1)); /* 0x19C */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_2_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 1, 1)); /* 0x1A0 */
	case 1:
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_4_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 0, 0)); /* 0x194 */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 0, 0)); /* 0x19C */
		pcs_info[reg_index++] = inp32(SOC_HiU31dpedp_PHY_PCS_PMA_INTF_LANE_SIG_CTRL_STS_REG_6_2_ADDR(dptx->combo_phy_base +
			phy_addr_delta + lane_addr_delta * 0, 0)); /* 0x1A0 */
		break;
	default:
		dpu_pr_warn("[DP] Invalid number of lanes %u", dptx->link.lanes);
		break;
	}

	dpu_pr_info("[DP] %d-%u, 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x - 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x",
		dptx->port_id, dptx->link.lanes,
		pcs_info[9], pcs_info[10], pcs_info[11], pcs_info[6], pcs_info[7], pcs_info[8],
		pcs_info[3], pcs_info[4], pcs_info[5], pcs_info[0], pcs_info[1], pcs_info[2]);
}

static void dptx_combophy_power_saving_handler(struct dp_ctrl *dptx)
{
	struct dp_private *dp_pri = NULL;
	dp_ctrl_conf ctrl_conf;
	dp_phy_conf phy_conf;

	if (dptx->port_id != 4 && dptx->port_id != 5) {
		dpu_pr_info("[DP] port_id not match, port_id: %d\n", dptx->port_id);
		return;
	}
	dpu_pr_info("[DP] leak elec set. dptx->port_id: %d\n", dptx->port_id);
	dp_pri = to_dp_private(dptx->connector->conn_info);
	if (get_dp_phy_conf((uint32_t)dptx->port_id, &phy_conf) != 0) {
		dpu_pr_err("[DP] [get_dp_phy_conf] error, return!");
		return;
	}

	if (get_dp_ctrl_conf((uint32_t)dptx->port_id, &ctrl_conf) != 0) {
		dpu_pr_err("[DP] [get_dp_ctrl_conf] error, return!");
		return;
	}

	// 1: enable apb phy clock [bit6_bit2]
	set_reg(dp_pri->sub_harden_crg_base + phy_conf.apb_clk_open_offset, 1, 1, phy_conf.apb_clk_control_bit);
	// 2: enable aux clock [bit5_bit1]
	set_reg(dp_pri->sub_harden_crg_base + ctrl_conf.aux_clk_open_offset, 1, 1, phy_conf.aux_clk_control_bit);
	// 3: open apb ctrl clk [bit8_bit3]
	set_reg(dp_pri->sub_harden_crg_base + ctrl_conf.apb_clk_open_offset, 1, 1, ctrl_conf.apb_clk_control_bit);
	// 4: open apb_reset_n [bit2_bit3]
	set_reg(dp_pri->sub_harden_crg_base + phy_conf.apb_reset_n_open_offset, 1, 1, phy_conf.apb_reset_n_control_bit);
	// 5: open por_b [bit9_bit7]
	set_reg(dp_pri->sub_harden_crg_base + phy_conf.por_n_open_offset, 1, 1, phy_conf.por_n_control_bit);
	// 6: open phy_reset_n [bit10_bit8]
	set_reg(dp_pri->sub_harden_crg_base + phy_conf.phy_reset_n_open_offset, 1, 1, phy_conf.phy_reset_n_control_bit);
	// 7: aux power on
	set_reg(dptx->combo_phy_base + phy_conf.phy_aux_ctrl_offset, 1, 1, 9);
	// entree: phy reg reset
	set_reg(dptx->combo_phy_base + 0x0, 0, 1, 0);
	set_reg(dptx->combo_phy_base + 0x608, 1, 1, 0);
	set_reg(dptx->combo_phy_base + 0x648, 1, 1, 0);
	set_reg(dptx->combo_phy_base + 0x648, 1, 1, 1);
	// 2: disable aux clock  0x4 5bit&1bit
	set_reg(dp_pri->sub_harden_crg_base + ctrl_conf.aux_clk_close_offset, 1, 1, phy_conf.aux_clk_control_bit);
	// 1: disable apb clock  0x4 6bit&2bit
	set_reg(dp_pri->sub_harden_crg_base + ctrl_conf.apb_clk_close_offset, 1, 1, phy_conf.apb_clk_control_bit);
}

void dp_ctrl_config_init(struct dp_ctrl *dptx)
{
	dptx->dptx_get_sync_calib_param = dptx_get_sync_calib_param;
	dptx->dptx_dsc_sample_en = dptx_dsc_sample_en;
	dptx->dptx_config_stream_timing = dptx_config_stream_timing;
	dptx->dptx_combophy_reset = dptx_combophy_reset;
	dptx->dp_dis_reset = dptx_dis_reset;
	dptx->dptx_combo_phy_is_up = dptx_combo_phy_is_up;
	dptx->is_all_pll_config_by_dp_soft = true;
	dptx->lane_low_power_mode = LANE_LOW_POWER_MODE_V740;
	dptx->max_tu = DPTX_MAX_TU_OF_MONITOR;
	dptx->max_hactive_low_temp = FHD_TIMING_H_ACTIVE_740;
	dptx->max_vactive_low_temp = FHD_TIMING_V_ACTIVE_740;
	dptx->dptx_ctrl_clk_enable = dptx_ctrl_clk_enable;
	dptx->dptx_hdcp_enable_video_transform = dptx_hdcp_enable_video_transform;
	dptx->dp_disable_clk = dp_disable_clk;
	dptx->dptx_phy_lane_reset = dptx_phy_lane_reset;
#ifdef CHIP_TYPE_CSV2_CSV3
	dptx->dptx_combophy_set_lane = dptx_combophy_set_lane_csv2;
#else
	dptx->dptx_combophy_set_lane = dptx_combophy_set_lane;
#endif
	dptx->dptx_power_handler = dptx_power_handler;
	dptx->dpu_dp_intr_handle = dpu_dp_intr_handle;
	dptx->dptx_show_phy_status_handler = dptx_show_phy_status_handler;
	dptx->dpu_dp_timing_isr_handle = dpu_dp_timing_isr_handle;
	if (dptx->connector->conn_info->dp_leakage_protect)
		dptx->dptx_combophy_power_saving_handler = dptx_combophy_power_saving_handler;
}

static const char *dp_ctrl_get_pg_type(void)
{
	const char *soc_spec = NULL;
	struct device_node *np = of_find_compatible_node(NULL, NULL, "hisilicon, soc_spec");
	if (!np) {
		dpu_pr_err("[DP] no soc_spec dts node");
		return NULL;
	}

	if (of_property_read_string(np, "soc_spec_set", &soc_spec)) {
		dpu_pr_err("[DP] no soc_spec_set dts info");
		return NULL;
	}

	dpu_pr_debug("[DP] soc_spec_set is %s", soc_spec);

	return soc_spec;
}

static bool dp_ctrl_is_bypass_by_efuse(uint32_t port_id)
{
	uint32_t buffer;
	struct efuse_desc desc = { 0 };
	uint32_t ret;

	desc.buf = &buffer;
	desc.buf_size = (uint32_t)(sizeof(buffer) / sizeof(uint32_t));

	switch (port_id) { // usb/dp combophy：port 0~3, dp/edp combophy：port 4~5
	case DPTX_PORT_ID_0:
		desc.start_bit = CHIP_LEVEL_EFUSE_FLAG_USB3_PHY_START - EFUSE_PARTIALGOOD_FLAG8_START;
		break;
	case DPTX_PORT_ID_1:
		desc.start_bit = CHIP_LEVEL_EFUSE_FLAG_USB3_PHY_START - EFUSE_PARTIALGOOD_FLAG8_START + 1;
		break;
	case DPTX_PORT_ID_2:
		desc.start_bit = CHIP_LEVEL_EFUSE_FLAG_USB3_PHY_START - EFUSE_PARTIALGOOD_FLAG8_START + 2;
		break;
	case DPTX_PORT_ID_3:
		desc.start_bit = CHIP_LEVEL_EFUSE_FLAG_USB3_PHY_START - EFUSE_PARTIALGOOD_FLAG8_START + 3;
		break;
	case DPTX_PORT_ID_4:
		desc.start_bit = CHIP_LEVEL_EFUSE_FLAG_EDE_START - EFUSE_PARTIALGOOD_FLAG8_START;
		break;
	case DPTX_PORT_ID_5:
		desc.start_bit = CHIP_LEVEL_EFUSE_FLAG_EDE_START - EFUSE_PARTIALGOOD_FLAG8_START + 1;
		break;
	default:
		dpu_pr_err("[DP] input error port id, not support!");
		return false;
	}
	desc.bit_cnt = 1;
	desc.item_vid = EFUSE_KERNEL_PARTIALGOOD_FLAG8;

	ret = efuse_read_value_t(&desc);
	if (ret != EFUSE_OK) {
		dpu_pr_err("[DP] [%s]:error, efuse_read_value ret=0x%08X", __func__, ret);
		return false;
	}

	if ((buffer & 0x1) == 0) {
		dpu_pr_debug("[DP] efuse is invalid, so need bypass");
		return true;
	}

	dpu_pr_debug("[DP] efuse is valid, so do not need bypass");
	return false;
}

bool dp_ctrl_is_bypass_by_pg(uint32_t port_id)
{
	const char *dts_str = dp_ctrl_get_pg_type();
	uint32_t index;
	bool is_by_pass = true;
	size_t port_cnt;
	uint32_t i;

#ifdef NOT_SURPORT_PG
	return false;
#endif
	if (port_id == DPTX_PORT_ID_0 || port_id == DPTX_PORT_ID_1 ||
				port_id == DPTX_PORT_ID_2 || port_id == DPTX_PORT_ID_3)
		return false;

	if (dts_str == NULL) {
		dpu_pr_err("[DP] get pg type fail");
		return true;
	}

	dpu_pr_debug("[DP] soc spec: %s, port_id : %u", dts_str, port_id);

	for (index = 0; index < ARRAY_SIZE(pg_info); index++) {
		if(strncmp(dts_str, pg_info[index].name, strlen(pg_info[index].name)) == 0)
			break;
	}
	if (index == 0)
		return false;

	if (index >= ARRAY_SIZE(pg_info)) {
		dpu_pr_err("[DP] soc spec is unknow, so by pass");
		return true;
	}

	is_by_pass = pg_info[index].is_by_pass;
	if (is_by_pass) {
		dpu_pr_debug("[DP] soc spec is %s, so by pass", dts_str);
		return true;
	}

	port_cnt = ARRAY_SIZE(pg_info[index].support_port);
	for (i = 0; i < (uint32_t)port_cnt; i++) {
		if (port_id == pg_info[index].support_port[i]) {
			dpu_pr_debug("[DP] soc spec is %s, so do not bypass", dts_str);
			return dp_ctrl_is_bypass_by_efuse(port_id);
		}
	}

	dpu_pr_debug("[DP] port  %d is invalid, so power by pass", port_id);
	return true;
}

void dp_enable_dpi_clk(char __iomem *dpu_base, bool enable)
{
	void_unused(dpu_base);
	void_unused(enable);
	return;
}