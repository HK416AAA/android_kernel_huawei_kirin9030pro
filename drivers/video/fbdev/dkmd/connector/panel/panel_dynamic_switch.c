/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#include <linux/types.h>
#include <securec.h>
#include "dynamic_fake_panel_info.h"
#include "dpu_conn_mgr.h"
#include "panel_mgr.h"
#include "panel_drv.h"
#include "dsc/dsc_output_calc.h"
#include "dsc/dsc_algorithm_manager.h"
#include <platform_include/basicplatform/linux/partition/partition_ap_kernel.h>

static struct fake_panel_param panel_param_read = {0};

static void mipi_lcd_init_dsi_param(struct mipi_panel_info *mipi)
{
	mipi->hsa = panel_param_read.mipi.hsa;
	mipi->hbp = panel_param_read.mipi.hbp;
	mipi->dpi_hsize = panel_param_read.mipi.dpi_hsize;
	mipi->hline_time = panel_param_read.mipi.hline_time;
	mipi->vsa = panel_param_read.mipi.vsa;
	mipi->vbp = panel_param_read.mipi.vbp;
	mipi->vfp = panel_param_read.mipi.vfp;

	mipi->dsi_bit_clk = panel_param_read.mipi.dsi_bit_clk;
	mipi->dsi_bit_clk_upt = panel_param_read.mipi.dsi_bit_clk_upt;
	mipi->dsi_bit_clk_default = panel_param_read.mipi.dsi_bit_clk_default;

	mipi->pxl_clk_rate = panel_param_read.mipi.pxl_clk_rate;
	mipi->pxl_clk_rate_div = panel_param_read.mipi.pxl_clk_rate_div;
	mipi->dsi_bit_clk_upt_support = panel_param_read.mipi.dsi_bit_clk_upt_support;

	mipi->clk_post_adjust = panel_param_read.mipi.clk_post_adjust;
	mipi->lane_nums = panel_param_read.mipi.lane_nums;
	mipi->color_mode = panel_param_read.mipi.color_mode;

	mipi->vc = panel_param_read.mipi.vc;
	mipi->max_tx_esc_clk = panel_param_read.mipi.max_tx_esc_clk;
	mipi->burst_mode = panel_param_read.mipi.burst_mode;
	mipi->non_continue_en = panel_param_read.mipi.non_continue_en;

	mipi->phy_mode = panel_param_read.mipi.phy_mode;
	mipi->dsi_version = panel_param_read.mipi.dsi_version;

	dpu_pr_info("kernel panel mipi info hsa:%u, hbp:%u, dpi_hsize:%u, hline_time:%u, vsa:%u, vbp:%u, vfp:%u!\n",
		mipi->hsa, mipi->hbp, mipi->dpi_hsize, mipi->hline_time, mipi->vsa, mipi->vbp, mipi->vfp);
}

/* dirty region initialized value from panel spec */
static void lcd_init_dirty_region(struct panel_drv_private *priv)
{
	priv->user_pinfo.left_align = panel_param_read.dirty_region_info.left_align;
	priv->user_pinfo.right_align = panel_param_read.dirty_region_info.right_align;
	priv->user_pinfo.top_align = panel_param_read.dirty_region_info.top_align;
	priv->user_pinfo.bottom_align = panel_param_read.dirty_region_info.bottom_align;
	priv->user_pinfo.w_align = panel_param_read.dirty_region_info.w_align;
	priv->user_pinfo.h_align = panel_param_read.dirty_region_info.h_align;
	priv->user_pinfo.w_min = panel_param_read.dirty_region_info.w_min;
	priv->user_pinfo.h_min = panel_param_read.dirty_region_info.h_min;
	priv->user_pinfo.top_start = panel_param_read.dirty_region_info.top_start;
	priv->user_pinfo.bottom_start = panel_param_read.dirty_region_info.bottom_start;
}

static void dsc_config_v1_2(struct dsc_calc_info *dsc)
{
	struct dsc_algorithm_manager *pt = get_dsc_algorithm_manager_instance();
	struct input_dsc_info input_dsc_info;

	dpu_pr_info("dynamic fake panel enable dsc1_2\n");

	if (!pt) {
		dpu_pr_err("pt is null!\n");
		return;
	}

	input_dsc_info.dsc_version = panel_param_read.input_dsc_info.dsc_version;
	input_dsc_info.format = panel_param_read.input_dsc_info.format;
	input_dsc_info.pic_width = panel_param_read.input_dsc_info.pic_width;
	input_dsc_info.pic_height = panel_param_read.input_dsc_info.pic_height;
	input_dsc_info.slice_width = panel_param_read.input_dsc_info.slice_width;
	input_dsc_info.slice_height = panel_param_read.input_dsc_info.slice_height;
	input_dsc_info.dsc_bpp = panel_param_read.input_dsc_info.dsc_bpp;
	input_dsc_info.dsc_bpc = panel_param_read.input_dsc_info.dsc_bpc;
	input_dsc_info.block_pred_enable = panel_param_read.input_dsc_info.block_pred_enable;
	input_dsc_info.linebuf_depth = panel_param_read.input_dsc_info.linebuf_depth;
	input_dsc_info.gen_rc_params = panel_param_read.input_dsc_info.gen_rc_params;
	pt->vesa_dsc_info_calc(&input_dsc_info, &(dsc->dsc_info), NULL);
	dsc->dsc_en = 1;
}

static void dsc_config_v1_1(struct dsc_calc_info *dsc)
{
	int ret = -1;
	dpu_pr_info("dynamic fake panel enable dsc1_1\n");
	dsc->dsc_en = 1;

	dsc->dsc_info.dsc_version_major = panel_param_read.dsc_info.dsc_version_major;
	dsc->dsc_info.dsc_version_minor = panel_param_read.dsc_info.dsc_version_minor;
	dsc->dsc_info.pic_height = panel_param_read.dsc_info.pic_height;
	dsc->dsc_info.pic_width = panel_param_read.dsc_info.pic_width;
	dsc->dsc_info.dsc_bpc = panel_param_read.dsc_info.dsc_bpc;
	dsc->dsc_info.dsc_bpp = panel_param_read.dsc_info.dsc_bpp;
	dsc->dsc_info.slice_height = panel_param_read.dsc_info.slice_height;
	dsc->dsc_info.slice_width = panel_param_read.dsc_info.slice_width;
	dsc->dsc_info.chunk_size = panel_param_read.dsc_info.chunk_size;

	dsc->dsc_info.block_pred_enable = panel_param_read.dsc_info.block_pred_enable;
	dsc->dsc_info.linebuf_depth = panel_param_read.dsc_info.linebuf_depth;

	/* INITIAL_DELAY */
	dsc->dsc_info.initial_dec_delay = panel_param_read.dsc_info.initial_dec_delay;
	dsc->dsc_info.initial_xmit_delay = panel_param_read.dsc_info.initial_xmit_delay;
	/* RC_PARAM0 */
	dsc->dsc_info.initial_scale_value = panel_param_read.dsc_info.initial_scale_value;
	dsc->dsc_info.scale_increment_interval = panel_param_read.dsc_info.scale_increment_interval;
	/* RC_PARAM1 */
	dsc->dsc_info.scale_decrement_interval = panel_param_read.dsc_info.scale_decrement_interval;
	dsc->dsc_info.first_line_bpg_offset = panel_param_read.dsc_info.first_line_bpg_offset;
	/* RC_PARAM2 */
	dsc->dsc_info.nfl_bpg_offset = panel_param_read.dsc_info.nfl_bpg_offset;
	dsc->dsc_info.slice_bpg_offset = panel_param_read.dsc_info.slice_bpg_offset;
	/* RC_PARAM3 */
	dsc->dsc_info.initial_offset = panel_param_read.dsc_info.initial_offset;
	dsc->dsc_info.final_offset = panel_param_read.dsc_info.final_offset;
	/* FLATNESS_QP_TH */
	dsc->dsc_info.flatness_min_qp = panel_param_read.dsc_info.flatness_min_qp;
	dsc->dsc_info.flatness_max_qp = panel_param_read.dsc_info.flatness_max_qp;
	/* DSC_PARAM4 */
	dsc->dsc_info.rc_edge_factor = panel_param_read.dsc_info.rc_edge_factor;
	dsc->dsc_info.rc_model_size = panel_param_read.dsc_info.rc_model_size;
	/* DSC_RC_PARAM5 */
	dsc->dsc_info.rc_tgt_offset_lo = panel_param_read.dsc_info.rc_tgt_offset_lo;
	dsc->dsc_info.rc_tgt_offset_hi = panel_param_read.dsc_info.rc_tgt_offset_hi;
	dsc->dsc_info.rc_quant_incr_limit1 = panel_param_read.dsc_info.rc_quant_incr_limit1;
	dsc->dsc_info.rc_quant_incr_limit0 = panel_param_read.dsc_info.rc_quant_incr_limit0;

	ret = memcpy_s(dsc->dsc_info.rc_buf_thresh, DSC_THRESH_LENGTH * sizeof(uint32_t),
		panel_param_read.dsc_info.rc_buf_thresh, DSC_THRESH_LENGTH * sizeof(uint32_t));
	if (ret != 0)
		dpu_pr_err("memcpy_s dsc_info.rc_buf_thresh error");

	ret = memcpy_s(dsc->dsc_info.rc_range, DSC_RC_RANGE_LENGTH * sizeof(struct rc_table_param),
		panel_param_read.dsc_info.rc_range, DSC_RC_RANGE_LENGTH * sizeof(struct rc_table_param));
	if (ret != 0)
		dpu_pr_err("memcpy_s dsc_info.rc_range error");
}

static int32_t read_panelinfo_from_storage(struct panel_drv_private *priv)
{
	int ret = 0;
	struct file *fp = NULL;
	loff_t pos = 0;
	char path[PANEL_PATH_MAXLEN];

	dynamic_fake_panel_info *fake_info_from_part = NULL;
	fake_info_from_part = kzalloc(sizeof(dynamic_fake_panel_info), GFP_KERNEL);
	if (!fake_info_from_part) {
		dpu_pr_err("kzalloc dynamic_fake_panel_info fail");
		return -1;
	}

	if (sprintf_s(path, PANEL_PATH_MAXLEN, "%s%s", "/dev/block/by-name/", PANEL_PARTITION_NAME) < 0) {
		dpu_pr_err("get panel partition path fail\n");
		ret = -1;
		goto err_open;
	}

	fp = filp_open(path, O_RDONLY, 0600);
	if (IS_ERR(fp)) {
		pr_err("read filp_open part disp_panel_info failed errno = %d", IS_ERR(fp));
		ret = -1;
		goto err_open;
	}

	ret = (int)vfs_llseek(fp, 0, SEEK_SET);
	if (ret < 0) {
		pr_err("seek ops failed, ret %d", ret);
		goto err_close;
	}

	ret = kernel_read(fp, (void *)fake_info_from_part, sizeof(dynamic_fake_panel_info), &pos);
	if (ret != (int)sizeof(dynamic_fake_panel_info)) {
		pr_err("read ops failed, read ret=%d (length=%u)", ret, sizeof(dynamic_fake_panel_info));
		ret = -1;
		goto err_close;
	}
	ret = memcpy_s(&panel_param_read, sizeof(struct fake_panel_param), &fake_info_from_part->fake_panel_info,
		sizeof(struct fake_panel_param));
	if (ret != 0)
		dpu_pr_err("memcpy_s panel_param_read error");

err_close:
	filp_close(fp, NULL);
err_open:
	kfree(fake_info_from_part);
	fake_info_from_part = NULL;
	return ret;
}

void setup_dual_mipi_info(struct dkmd_connector_info *pinfo)
{
	pinfo->connector_idx[0] = panel_param_read.connector_ids[0];
	pinfo->connector_idx[1] = panel_param_read.connector_ids[1];

	pinfo->sw_post_chn_idx[0] = panel_param_read.connector_ids[0];
	pinfo->sw_post_chn_idx[1] = panel_param_read.connector_ids[1];
	pinfo->sw_post_chn_num = panel_param_read.connector_num;

	get_primary_connector(pinfo)->bind_connector = get_external_connector(pinfo);
}

static int32_t panel_of_device_setup(struct panel_drv_private *priv)
{
	struct dkmd_connector_info *pinfo = &priv->connector_info;
	struct dpu_connector *connector = NULL;

	connector = get_primary_connector(pinfo);
	if (!connector) {
		dpu_pr_err("connector_id=%u is not available!\n", pinfo->connector_idx[PRIMARY_CONNECT_CHN_IDX]);
		return -1;
	}

	dpu_pr_info("enter!\n");
	if (read_panelinfo_from_storage(priv) < 0) {
		return -1;
	}

	panel_base_of_device_setup(priv);

	if (panel_param_read.connector_num > 1) {
		setup_dual_mipi_info(pinfo);
	}

	/* 1. config base object info
	 * would be used for framebuffer setup
	 */
	pinfo->base.xres = panel_param_read.xres;
	pinfo->base.yres = panel_param_read.yres;

	pinfo->base.width = panel_param_read.width;
	pinfo->base.height = panel_param_read.height;

	pinfo->base.fps = panel_param_read.fps;

	pinfo->base.fpga_flag = panel_param_read.fpga_flag;

	pinfo->base.type = panel_param_read.type;
	pinfo->base.lcd_te_idx = panel_param_read.lcd_te_idx;

	/* 2. config connector info
	 * would be used for dsi & composer setup
	 */
	pinfo->ifbc_type = panel_param_read.ifbc_type;
	dpu_pr_info("kernel panel base info, xres:%u, yres:%u, fps:%u, fpga:%u, type:%u,\
		ifbc_type:%u!\n", pinfo->base.xres, pinfo->base.yres,
		pinfo->base.fps, pinfo->base.fpga_flag, pinfo->base.type, pinfo->ifbc_type);
	if (is_ifbc_vesa_panel(pinfo->ifbc_type)) {
		if (panel_param_read.input_dsc_info.dsc_version == FAKE_DSC_VERSION_V_1_1)
			dsc_config_v1_1(&connector->post_info[0]->dsc);
		else
			dsc_config_v1_2(&connector->post_info[0]->dsc);
	}

	mipi_lcd_init_dsi_param(&connector->post_info[0]->mipi);

	pinfo->dirty_region_updt_support = panel_param_read.dirty_region_updt_support;
	pinfo->vsync_ctrl_type = panel_param_read.vsync_ctrl_type;

	pinfo->bl_info.bl_min = panel_param_read.bl_min;
	pinfo->bl_info.bl_max = panel_param_read.bl_max;
	pinfo->bl_info.bl_default = panel_param_read.bl_default;

	/* 3. config panel private info
	 * would be used for panel setup
	 */
	priv->mipi_brightness_para_type = panel_param_read.mipi_brightness_para_type;

	/* 4. dirty region */
	if (pinfo->dirty_region_updt_support)
		lcd_init_dirty_region(priv);

	priv->vcc_enable_cmds_len = 0;
	priv->vcc_disable_cmds_len = 0;
	priv->pinctrl_normal_cmds_len = 0;
	priv->pinctrl_lowpower_cmds_len = 0;
	priv->pinctrl_init_cmds_len = 0;
	priv->pinctrl_finit_cmds_len = 0;
	priv->vcc_init_cmds_len = 0;
	priv->vcc_finit_cmds_len = 0;
	dpu_pr_info("exit!\n");
	return 0;
}

static void panel_of_device_release(struct panel_drv_private *priv)
{
	panel_base_of_device_release(priv);
	dpu_pr_info("exit!\n");
}

panel_device_match_data(dynamic_switch_fake_panel_info, DYNAMIC_FAKE_PANEL_ID, panel_of_device_setup, panel_of_device_release);

MODULE_LICENSE("GPL");