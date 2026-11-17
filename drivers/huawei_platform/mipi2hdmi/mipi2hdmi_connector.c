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
#include <linux/of.h>
#include <linux/wait.h>
#include <asm/irq.h>
#include <platform_include/basicplatform/linux/switch.h>
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#include <securec.h>
#include "dkmd_connector.h"
#include "dpu_conn_mgr.h"
#include "dpu_connector.h"
#include "dkmd_edid_interface.h"
#include "mipi2hdmi_connector.h"

#define DTS_GFX_MIPI2HDMI_NAME "gfx_mipi"
#define MAX_GFX_MIPI_DEV_COUNT 3
#define HPD_PLUGIN_TIMER_DEBOUNCE 100
#define HPD_PLUGOUT_TIMER_DEBOUNCE 1700
#define EDID_TIMER_DEBOUNCE 100
#define WAIT_EDID_READY_TIMEOUT 1000
#define MAX_WAIT_EDID_READY_TIMES 3
#define EDID_MFG_START 8
#define EDID_MFG_END 17
#define EDID_MFG_LEN 10
#define MFG_NAME_LEN 4
#define EDID_MFG_SHIFT_BITS 8
#define EDID_MFG_FIRST_SHIFT_BITS 10
#define EDID_MFG_SECOND_SHIFT_BITS 5
#define PLUGOUT_PLUGIN_INTERVAL 100
#define AUDIO_SWITCH_DEV_NAME_LEN 128
#define LCD_DEFAULT_XRES 640
#define LCD_DEFAULT_YRES 480
#define LCD_DEFAULT_FPS 60
#define LCD_DEFAULT_WIDTH 530
#define LCD_DEFAULT_HEIGHT 300
#define MIPI_CLK_POST_ADJUST 215
#define MIPI_MAX_TX_ESC_CLK (10 * 1000000)
#define EDID_TIMING_PIXEL_CLOCK 25175
#define EDID_TIMING_HBLANKING 160
#define EDID_TIMING_HSIZE 4
#define EDID_TIMING_HSYNC_OFFSET 16
#define EDID_TIMING_HSYNC_PULSE_WIDTH 96
#define EDID_TIMING_VBLANKING 45
#define EDID_TIMING_VSIZE 3
#define EDID_TIMING_VSYNC_OFFSET 10
#define EDID_TIMING_VSYNC_PULSE_WIDTH 2
#define PIXEL_CLOCK_MULTIPLE_HZ 1000
#define MIPI2HDMI_PORT_ID 5
#define PIXEL_CLOCK_HDMI_VERSION_2DOT0 340000000
#define DELAYED_RESUME_WORK 500
#define PIXEL_CLOCK_MAX_DIFF 1000
#define CTA_PART1_VIC_START_CODE 1
#define CTA_PART2_VIC_START_CODE 193
#define HDCP_VERSION_1DOT4 0x01
#define HDCP_VERSION_2DOT0 0x02
#define EDID_TIMING_DIVISOR 2
#define SKYWORTH_PRODUCT_CODE 0x0010
#define SKYWORTH_SERIAL_NUMBER  0x01010101
#define HOT_PANEL_ON 16
#define HOT_PANEL_OFF 17

typedef enum mipi2hdmi_edid_status {
    EDID_STATUS_NOT_READY = 0,
    EDID_STATUS_GOOD,
    EDID_STATUS_BAD,
    EDID_STATUS_BREAK
} EDID_STATUS;

enum mipi2hdmi_error_codes {
    EPOWER_ON_FAILED = 0x10001,
    EEDID_FAILED,
    EEDID_BREAK,
    EEDID_PARSE_FAILED,
    EEDID_FILTER_FAILED,
    EPREFERED_FILTER_FAILED
};

static struct platform_device *g_dkmd_mipi2hdmi_dev[MAX_GFX_MIPI_DEV_COUNT] = {0};
static struct mipi2hdmi_bridge *g_dkmd_mipi2hdmi_bridge[MAX_GFX_MIPI_DEV_COUNT] = {0};
static struct mipi2hdmi_redriver *g_dkmd_mipi2hdmi_redriver[MAX_GFX_MIPI_DEV_COUNT] = {0};

struct mipi2hdmi_private {
    struct dkmd_connector_info connector_info;
    struct dfr_info dfr_info;
    struct platform_device *pdev;
    uint32_t hpd_gpio;
    int hpd_irq;
    struct delayed_work hpd_irq_work;
    struct delayed_work delayed_resume_work;
    bool monitor_online;
    uint32_t edid_gpio;
    int edid_irq;
    struct delayed_work edid_irq_work;
    atomic_t edid_ready_atom;
    wait_queue_head_t edid_ready_waitq;
    uint8_t prev_edid[MAX_EDID_DATA_SIZE];
    uint32_t prev_edid_len;
    uint8_t edid[MAX_EDID_DATA_SIZE];
    uint32_t edid_len;
    struct edid_timing_info edid_timing;
    char audio_name[AUDIO_SWITCH_DEV_NAME_LEN];
    uint32_t user_timing_index;
    bool setting_timing;
    bool power_on;
    bool device_connected;
    bool first_int_power_on;
    bool set_hdcp_mode;
};

static inline struct mipi2hdmi_private *to_mipi2hdmi_private(struct dkmd_connector_info *info)
{
    return container_of(info, struct mipi2hdmi_private, connector_info);
}

static void mipi2hdmi_init_dsi_param(struct mipi_panel_info *mipi)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!mipi, err, "[MIPI2HDMI] mipi is null\n");

    mipi->pxl_clk_rate_div = 1;
    mipi->dsi_bit_clk_upt_support = 0;
    mipi->clk_post_adjust = MIPI_CLK_POST_ADJUST;
    mipi->lane_nums = DSI_4_LANES;
    mipi->color_mode = DSI_24BITS_1;
    mipi->dsi_version = DSI_1_1_VERSION;
    mipi->vc = 0;
    mipi->max_tx_esc_clk = MIPI_MAX_TX_ESC_CLK;
    mipi->burst_mode = DSI_BURST_SYNC_PULSES_1;
    mipi->non_continue_en = 0;
    mipi->phy_mode = DPHY_MODE;

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void mipi2hdmi_init_connector_param(struct dkmd_connector_info *pinfo)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!pinfo, err, "[MIPI2HDMI] pinfo is null\n");

    pinfo->base.xres = LCD_DEFAULT_XRES;
    pinfo->base.yres = LCD_DEFAULT_YRES;
    pinfo->base.width = LCD_DEFAULT_WIDTH;
    pinfo->base.height = LCD_DEFAULT_HEIGHT;
    pinfo->base.dsc_out_width = pinfo->base.xres;
    pinfo->base.dsc_out_height = pinfo->base.yres;
    pinfo->base.fps = LCD_DEFAULT_FPS;
    pinfo->base.fps_info_count = 1;
    pinfo->base.is_dynamic_connect = 1;
    pinfo->base.is_pluggable = 1;
    pinfo->base.id = PANEL_ID_GFX_MIPI;
    pinfo->bpp = LCD_RGB888;
    pinfo->bgr_fmt = LCD_RGB;
    pinfo->orientation = LCD_LANDSCAPE;

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static int32_t mipi2hdmi_init_default_timing(struct dkmd_connector_info *pinfo)
{
    int32_t ret = 0;
    struct dpu_connector *connector = NULL;
    struct mipi2hdmi_private *priv = NULL;
    uint32_t pixels = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    connector = get_primary_connector(pinfo);
    dpu_check_and_return(!connector, -EINVAL, err, "[MIPI2HDMI] connector is null\n");
    dpu_check_and_return(!connector->post_info[0], -EINVAL, err, "[MIPI2HDMI] connector->post_info[0] is null\n");

    mipi2hdmi_init_connector_param(pinfo);
    mipi2hdmi_init_dsi_param(&(connector->post_info[0]->mipi));
    priv->edid_timing.pixel_clock = EDID_TIMING_PIXEL_CLOCK;
    priv->edid_timing.hactive_pixels = LCD_DEFAULT_XRES;
    priv->edid_timing.hblanking = EDID_TIMING_HBLANKING;
    priv->edid_timing.hsize = EDID_TIMING_HSIZE;
    priv->edid_timing.hsync_offset = EDID_TIMING_HSYNC_OFFSET;
    priv->edid_timing.hsync_pulse_width = EDID_TIMING_HSYNC_PULSE_WIDTH;
    priv->edid_timing.vactive_pixels = LCD_DEFAULT_YRES;
    priv->edid_timing.vblanking = EDID_TIMING_VBLANKING;
    priv->edid_timing.vsize = EDID_TIMING_VSIZE;
    priv->edid_timing.vsync_offset = EDID_TIMING_VSYNC_OFFSET;
    priv->edid_timing.vsync_pulse_width = EDID_TIMING_VSYNC_PULSE_WIDTH;
    pixels = (uint32_t)(priv->edid_timing.hactive_pixels + priv->edid_timing.hblanking) *
        (priv->edid_timing.vactive_pixels + priv->edid_timing.vblanking);
    if (pixels == 0) {
        dpu_pr_err("[MIPI2HDMI] pixels is zero");
        return -EINVAL;
    }
    priv->edid_timing.fps = (uint16_t)(priv->edid_timing.pixel_clock * PIXEL_CLOCK_MULTIPLE_HZ / pixels);
    ret = connector_device_edid_timing_calculate(&priv->edid_timing, pinfo);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to calculate edid timing\n");
        return ret;
    }

    pinfo->base.edid = NULL;
    pinfo->base.edid_len = 0;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static void mipi2hdmi_base_dts_parse(struct dkmd_connector_info *pinfo, struct device_node *np)
{
    int32_t ret = 0;
    uint32_t value = 0;

    dpu_check_and_no_retval(!pinfo, err, "[MIPI2HDMI] pinfo is null\n");
    dpu_check_and_no_retval(!np, err, "[MIPI2HDMI] np is null\n");

    ret = of_property_read_u32(np, "fpga_flag", &pinfo->base.fpga_flag);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get fpga_flag failed, ret=%d\n", ret);
        pinfo->base.fpga_flag = 0;
    }
    dpu_pr_info("[MIPI2HDMI] fpga_flag=%#x\n", pinfo->base.fpga_flag);
    ret = of_property_read_u32(np, "lcd-display-type", &pinfo->base.type);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get lcd_display_type failed, ret=%d\n", ret);
        pinfo->base.type = PANEL_DUAL_MIPI_VIDEO;
    }
    pinfo->base.type |= (PANEL_EXTERNAL | PANEL_MIPI2HDMI);
    dpu_pr_info("[MIPI2HDMI] panel_type=%#x\n", pinfo->base.type);
    ret = of_property_read_u32(np, "pipe_sw_itfch_idx", &pinfo->base.pipe_sw_itfch_idx);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get pipe_sw_itfch_idx failed, ret=%d\n", ret);
        pinfo->base.pipe_sw_itfch_idx = PIPE_SW_PRE_ITFCH0;
    }
    dpu_pr_info("[MIPI2HDMI] pipe_sw_pre_itfch_idx=%#x\n", pinfo->base.pipe_sw_itfch_idx);
    ret = of_property_read_u32(np, "fake_panel_flag", &pinfo->base.fake_panel_flag);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get fake_panel_flag failed, ret=%d\n", ret);
        pinfo->base.fake_panel_flag = 0;
    }
    dpu_pr_info("[MIPI2HDMI] fake_panel_flag=%#x\n", pinfo->base.fake_panel_flag);
    ret = of_property_read_u32(np, "support_hardware_cursor", &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get support_hardware_cursor failed, ret=%d\n", ret);
    }
    pinfo->base.is_hardware_cursor_support = (ret == 0) && (value != 0);
    dpu_pr_info("[MIPI2HDMI] is_hardware_cursor_support=%u\n", pinfo->base.is_hardware_cursor_support);
}

static void mipi2hdmi_extend_dts_parse(struct dkmd_connector_info *pinfo, struct device_node *np)
{
    int32_t ret = 0;
    uint32_t value = 0;
    struct mipi2hdmi_private *priv = NULL;

    dpu_check_and_no_retval(!pinfo, err, "[MIPI2HDMI] pinfo is null\n");
    dpu_check_and_no_retval(!np, err, "[MIPI2HDMI] np is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    ret = of_property_read_u32(np, "lcd-ifbc-type", &pinfo->ifbc_type);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get ifbc_type failed, ret=%d\n", ret);
        pinfo->ifbc_type = IFBC_TYPE_NONE;
    }
    dpu_pr_info("[MIPI2HDMI] ifbc_type=%#x\n", pinfo->ifbc_type);
    ret = of_property_read_u32(np, "port_id", &pinfo->port_id);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get port_id failed, ret=%d\n", ret);
        pinfo->port_id = MIPI2HDMI_PORT_ID;
    }
    dpu_pr_info("[MIPI2HDMI] port_id=%#x\n", pinfo->port_id);
    ret = of_property_read_string(np, "gfx_mipi2hdmi_dev_name", &pinfo->base.name);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get gfx_mipi2hdmi_dev_name failed, ret=%d\n", ret);
        pinfo->base.name = DTS_GFX_MIPI2HDMI_NAME;
    }
    dpu_pr_info("[MIPI2HDMI] pinfo->base.name=%s\n", pinfo->base.name);

    ret = of_property_read_u32(np, "spec_timing_filter_enable", &value);
    pinfo->spec_timing_filter_enable = ((ret == 0 && value != 0) ? true : false);
    dpu_pr_info("[MIPI2HDMI] get spec_timing_filter_enable is %d", (int)pinfo->spec_timing_filter_enable);

    ret = of_property_read_u32(np, "is_enable_set_timing", &value);
    pinfo->is_enable_set_timing = (bool)((ret == 0 && value != 0) ? true : false);
    dpu_pr_info("[MIPI2HDMI] get is_enable_set_timing is %d", (int)pinfo->is_enable_set_timing);

    ret = of_property_read_u32(np, "default_target_fps", &value);
    pinfo->base.default_target_fps = (ret == 0 ? value : 60);
    dpu_pr_info("[MIPI2HDMI] get default_target_fps is %u", pinfo->base.default_target_fps);

    ret = of_property_read_u32(np, "set_hdcp_mode", &value);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] get set_hdcp_mode failed, ret=%d\n", ret);
    }
    priv->set_hdcp_mode = (ret == 0) && (value != 0);
    dpu_pr_info("[MIPI2HDMI] set_hdcp_mode=%u\n", priv->set_hdcp_mode);
}

static int32_t mipi2hdmi_display_setup(struct mipi2hdmi_private *priv)
{
    int32_t ret = 0;
    struct dkmd_connector_info *pinfo = NULL;
    struct device_node *np = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->pdev, -EINVAL, err, "[MIPI2HDMI] priv->pdev is null\n");
    np = priv->pdev->dev.of_node;
    dpu_check_and_return(!np, -EINVAL, err, "[MIPI2HDMI] np is null\n");

    pinfo = &priv->connector_info;
    ret = mipi2hdmi_init_default_timing(pinfo);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] failed to init default timing, ret=%d\n", ret);
        return ret;
    }
    mipi2hdmi_base_dts_parse(pinfo, np);
    mipi2hdmi_extend_dts_parse(pinfo, np);
    base_panel_connector_dts_parse(pinfo, np);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static struct mipi2hdmi_bridge *mipi2hdmi_get_bridge(struct mipi2hdmi_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

     if (priv->connector_info.connector_idx[0] >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] connector id is invalid\n");
        return NULL;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return g_dkmd_mipi2hdmi_bridge[priv->connector_info.connector_idx[0]];
}

static struct mipi2hdmi_redriver *mipi2hdmi_get_redriver(struct mipi2hdmi_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

     if (priv->connector_info.connector_idx[0] >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] connector id is invalid\n");
        return NULL;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return g_dkmd_mipi2hdmi_redriver[priv->connector_info.connector_idx[0]];
}

int32_t mipi2hdmi_register_bridge(struct mipi2hdmi_bridge *bridge)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    if (bridge->bridge_id >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] bridge id is invalid!\n");
        return -EINVAL;
    }
    g_dkmd_mipi2hdmi_bridge[bridge->bridge_id] = bridge;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

int32_t mipi2hdmi_unregister_bridge(struct mipi2hdmi_bridge *bridge)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    if (bridge->bridge_id >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] bridge id is invalid!\n");
        return -EINVAL;
    }
    g_dkmd_mipi2hdmi_bridge[bridge->bridge_id] = NULL;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

int32_t mipi2hdmi_register_redriver(struct mipi2hdmi_redriver *redriver)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!redriver, -EINVAL, err, "[MIPI2HDMI] redriver is null\n");

    if (redriver->redriver_id >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] redriver id is invalid!\n");
        return -EINVAL;
    }
    g_dkmd_mipi2hdmi_redriver[redriver->redriver_id] = redriver;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

int32_t mipi2hdmi_unregister_redriver(struct mipi2hdmi_redriver *redriver)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!redriver, -EINVAL, err, "[MIPI2HDMI] redriver is null\n");

    if (redriver->redriver_id >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] redriver id is invalid!\n");
        return -EINVAL;
    }
    g_dkmd_mipi2hdmi_redriver[redriver->redriver_id] = NULL;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_clear_edid_info(struct mipi2hdmi_private *priv)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    ret = memset_s(priv->prev_edid, sizeof(priv->prev_edid), 0, MAX_EDID_DATA_SIZE);
    if (ret != EOK) {
        dpu_pr_err("[MIPI2HDMI] memset prev_edid failed, ret=%d\n", ret);
        return ret;
    }
    priv->prev_edid_len = 0;
    ret = memset_s(priv->edid, sizeof(priv->edid), 0, MAX_EDID_DATA_SIZE);
    if (ret != EOK) {
        dpu_pr_err("[MIPI2HDMI] memset edid failed, ret=%d\n", ret);
        return ret;
    }
    priv->edid_len = 0;
    ret = memset_s(&priv->edid_timing, sizeof(priv->edid_timing), 0, sizeof(priv->edid_timing));
    if (ret != EOK) {
        dpu_pr_err("[MIPI2HDMI] memset edid timing failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static void mipi2hdmi_set_edid_status(struct mipi2hdmi_private *priv, EDID_STATUS status)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    atomic_set(&priv->edid_ready_atom, status);
    if (status != EDID_STATUS_NOT_READY) {
        wake_up(&priv->edid_ready_waitq);
    }

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static int32_t mipi2hdmi_device_trigger(struct mipi2hdmi_private *priv, DPU_HOT_PLUG_TYPE hot_plug_type)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    switch (hot_plug_type) {
        case DPU_HOT_PLUG_IN:
            if (priv->monitor_online) {
                dpu_pr_warn("[MIPI2HDMI] monitor is online, need not to retrigger\n");
                return 0;
            }
            priv->monitor_online = true;
            dpu_pr_info("[MIPI2HDMI] monitor plugin\n");
            break;
        case DPU_HOT_PLUG_OUT:
            if (!priv->monitor_online) {
                dpu_pr_warn("[MIPI2HDMI] monitor is offline, need not to retrigger\n");
                return 0;
            }
            priv->monitor_online = false;
            mipi2hdmi_set_edid_status(priv, EDID_STATUS_BREAK);
            ret = mipi2hdmi_clear_edid_info(priv);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] Failed to clear edid info, ret=%d\n", ret);
                return ret;
            }
            dpu_pr_info("[MIPI2HDMI] monitor plugout\n");
            break;
        default:
            break;
    }
    ret = connector_device_trigger_uevent_hotplug(&priv->connector_info, hot_plug_type);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] connector device trigger failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static irqreturn_t mipi2hdmi_hpd_irq_handler(int irq, void *dev_id)
{
    int32_t hpd_value = 0;
    struct mipi2hdmi_private *priv = (struct mipi2hdmi_private *)dev_id;

    dpu_pr_info("[MIPI2HDMI] +\n");

    if (priv == NULL) {
        dpu_pr_err("[MIPI2HDMI] priv is null\n");
        return IRQ_HANDLED;
    }
    hpd_value = gpio_get_value(priv->hpd_gpio);
    dpu_pr_info("[MIPI2HDMI] hpd_irq_handler hpd_gpio: %u, hpd_value: %d\n", priv->hpd_gpio, hpd_value);
    cancel_delayed_work(&priv->hpd_irq_work);
    if (hpd_value == GPIO_LOW_VOLTAGE) {
        schedule_delayed_work(&priv->hpd_irq_work, msecs_to_jiffies(HPD_PLUGIN_TIMER_DEBOUNCE));
    } else {
        schedule_delayed_work(&priv->hpd_irq_work, msecs_to_jiffies(HPD_PLUGOUT_TIMER_DEBOUNCE));
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return IRQ_HANDLED;
}

static void mipi2hdmi_delayed_resume_work(struct work_struct *work)
{
    struct mipi2hdmi_private *priv = container_of(work, struct mipi2hdmi_private, delayed_resume_work.work);

    int32_t ret = 0;
    int32_t value = 0;
    bool cur_monitor_online = false;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    dpu_pr_info("[MIPI2HDMI] executing delayed resume work\n");

    ret = irq_set_irq_type(priv->hpd_irq, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING);
    if (ret < 0) {
        dpu_pr_warn("[MIPI2HDMI] resume, failed to set hpd irq type!\n");
    }
    enable_irq(priv->hpd_irq);

    value = gpio_get_value(priv->hpd_gpio);
    cur_monitor_online = (value == GPIO_LOW_VOLTAGE) ? true : false;
    dpu_pr_info("[MIPI2HDMI] priv->monitor_online=%d, cur_monitor_online=%d\n",
        priv->monitor_online, cur_monitor_online);
    if (!priv->monitor_online && cur_monitor_online) {
        ret = mipi2hdmi_device_trigger(priv, DPU_HOT_PLUG_IN);
        if (ret != 0) {
            dpu_pr_warn("[MIPI2HDMI] device trigger plugin failed, ret=%d\n", ret);
        }
    } else if (priv->monitor_online && !cur_monitor_online) {
        ret = mipi2hdmi_device_trigger(priv, DPU_HOT_PLUG_OUT);
        if (ret != 0) {
            dpu_pr_warn("[MIPI2HDMI] device trigger failed, ret=%d\n", ret);
        }
    }

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void mipi2hdmi_hpd_irq_work(struct work_struct *work)
{
    int hpd_value = 0;
    struct mipi2hdmi_private *priv = container_of(work,	struct mipi2hdmi_private, hpd_irq_work.work);

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    DPU_HOT_PLUG_TYPE hot_plug_type = DPU_HOT_PLUG_IN;
    hpd_value = gpio_get_value(priv->hpd_gpio);
    dpu_pr_info("[MIPI2HDMI] hpd_gpio=%u, hpd_value=%d\n", priv->hpd_gpio, hpd_value);
    if (hpd_value == GPIO_LOW_VOLTAGE) {
        hot_plug_type = DPU_HOT_PLUG_IN;
    } else if (hpd_value == GPIO_HIGH_VOLTAGE) {
        hot_plug_type = DPU_HOT_PLUG_OUT;
    } else {
        dpu_pr_err("[MIPI2HDMI] invalid gpio hpd_value.\n");
        return;
    }
    (void)mipi2hdmi_device_trigger(priv, hot_plug_type);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static int32_t mipi2hdmi_hpd_setup(struct mipi2hdmi_private *priv)
{
    int32_t ret = 0;
    struct device_node *np = NULL;
    dpu_pr_info("[MIPI2HDMI] +\n");
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->pdev, -EINVAL, err, "[MIPI2HDMI] priv->pdev is null\n");
    np = priv->pdev->dev.of_node;
    dpu_check_and_return(!np, -EINVAL, err, "[MIPI2HDMI] np is null\n");
    INIT_DELAYED_WORK(&priv->hpd_irq_work, mipi2hdmi_hpd_irq_work);
    INIT_DELAYED_WORK(&priv->delayed_resume_work, mipi2hdmi_delayed_resume_work);
    ret = of_property_read_u32(np, "hpd_gpio", &priv->hpd_gpio);
    if (ret != 0) {
        dpu_pr_info("[MIPI2HDMI] get hpd_gpio failed, ret=%d\n", ret);
        return ret;
    }
    dpu_pr_info("[MIPI2HDMI] hpd_gpio=%u\n", priv->hpd_gpio);
    if (!gpio_is_valid(priv->hpd_gpio)) {
        dpu_pr_err("[MIPI2HDMI] hpd gpio is not valid, check DTS\n");
        return -EINVAL;
    }
    ret = devm_gpio_request(&priv->pdev->dev, priv->hpd_gpio, "mipi2hdmi_hpd_gpio");
    if (ret < 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to request hpd gpio: %u, ret=%d\n", priv->hpd_gpio, ret);
        return ret;
    }
    ret = gpio_direction_input(priv->hpd_gpio);
    if (ret < 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set hpd gpio directoin, ret=%d\n", ret);
        goto err_out;
    }
    priv->hpd_irq = gpio_to_irq(priv->hpd_gpio);
    if (priv->hpd_irq < 0) {
        ret = priv->hpd_irq;
        dpu_pr_err("[MIPI2HDMI] Failed to get hpd irq, ret=%d\n", ret);
        goto err_out;
    }
    ret = request_irq(priv->hpd_irq, mipi2hdmi_hpd_irq_handler,
        IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING, "mipi2hdmi_hpd_irq", priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to request hpd interupt handler, ret=%d\n", ret);
        goto err_out;
    }
    disable_irq(priv->hpd_irq);
    dpu_pr_info("[MIPI2HDMI] -\n");
    return 0;
err_out:
    devm_gpio_free(&priv->pdev->dev, priv->hpd_gpio);
    cancel_delayed_work(&priv->hpd_irq_work);
    return ret;
}

static void mipi2hdmi_hpd_release(struct mipi2hdmi_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_no_retval(!priv->pdev, err, "[MIPI2HDMI] priv->pdev is null\n");

    free_irq(priv->hpd_irq, priv);
    devm_gpio_free(&priv->pdev->dev, priv->hpd_gpio);
    cancel_delayed_work(&priv->hpd_irq_work);
    cancel_delayed_work(&priv->delayed_resume_work);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static irqreturn_t mipi2hdmi_edid_irq_handler(int irq, void *dev_id)
{
    int32_t edid_value = 0;
    struct mipi2hdmi_private *priv = (struct mipi2hdmi_private *)dev_id;

    dpu_pr_info("[MIPI2HDMI] +\n");

    if (priv == NULL) {
        dpu_pr_err("[MIPI2HDMI] priv is null\n");
        return IRQ_HANDLED;
    }
    if (priv->first_int_power_on) {
        dpu_pr_warn("[MIPI2HDMI] Pseudo interrupt generated during power-on, ignore it\n");
        priv->first_int_power_on = false;
        return IRQ_HANDLED;
    }
    edid_value = gpio_get_value(priv->edid_gpio);
    dpu_pr_info("[MIPI2HDMI] edid_irq_handler edid_gpio: %u, edid_value: %d\n", priv->edid_gpio, edid_value);
    cancel_delayed_work(&priv->edid_irq_work);
    schedule_delayed_work(&priv->edid_irq_work, msecs_to_jiffies(EDID_TIMER_DEBOUNCE));

    dpu_pr_info("[MIPI2HDMI] -\n");

    return IRQ_HANDLED;
}

static void mipi2hdmi_edid_irq_work(struct work_struct *work)
{
    struct mipi2hdmi_private *priv = container_of(work,	struct mipi2hdmi_private, edid_irq_work.work);
    struct mipi2hdmi_bridge *bridge = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");
    bridge = mipi2hdmi_get_bridge(priv);
    dpu_check_and_no_retval(!bridge, err, "[MIPI2HDMI] bridge is null\n");

    if (!bridge->read_edid) {
        dpu_pr_err("[MIPI2HDMI] bridge read_edid is null\n");
        mipi2hdmi_set_edid_status(priv, EDID_STATUS_BAD);
        return;
    }
    priv->edid_len = 0;
    if (memset_s(priv->edid, sizeof(priv->edid), 0, MAX_EDID_DATA_SIZE) != EOK) {
        dpu_pr_warn("[MIPI2HDMI] Failed to memset the edid memory\n");
        mipi2hdmi_set_edid_status(priv, EDID_STATUS_BAD);
        return;
    }
    if (bridge->read_edid(bridge, priv->edid, sizeof(priv->edid), &priv->edid_len) != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to read the edid\n");
        mipi2hdmi_set_edid_status(priv, EDID_STATUS_BAD);
        return;
    }
    mipi2hdmi_set_edid_status(priv, EDID_STATUS_GOOD);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static int32_t mipi2hdmi_edid_setup(struct mipi2hdmi_private *priv)
{
    int32_t ret = 0;
    struct device_node *np = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->pdev, -EINVAL, err, "[MIPI2HDMI] priv->pdev is null\n");
    np = priv->pdev->dev.of_node;
    dpu_check_and_return(!np, -EINVAL, err, "[MIPI2HDMI] np is null\n");

    INIT_DELAYED_WORK(&priv->edid_irq_work, mipi2hdmi_edid_irq_work);
    init_waitqueue_head(&priv->edid_ready_waitq);
    ret = of_property_read_u32(np, "edid_gpio", &priv->edid_gpio);
    if (ret != 0) {
        dpu_pr_info("[MIPI2HDMI] get edid_gpio failed, ret=%d\n", ret);
        return ret;
    }
    dpu_pr_info("[MIPI2HDMI] edid_gpio=%u\n", priv->edid_gpio);
    if (!gpio_is_valid(priv->edid_gpio)) {
        dpu_pr_err("[MIPI2HDMI] edid gpio is not valid, check DTS\n");
        return -EINVAL;
    }
    ret = devm_gpio_request(&priv->pdev->dev, priv->edid_gpio, "mipi2hdmi_edid_gpio");
    if (ret < 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to request edid gpio: %u, ret=%d\n", priv->edid_gpio, ret);
        return ret;
    }
    ret = gpio_direction_input(priv->edid_gpio);
    if (ret < 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set edid gpio directoin, ret=%d\n", ret);
        goto err_out;
    }
    priv->edid_irq = gpio_to_irq(priv->edid_gpio);
    if (priv->edid_irq < 0) {
        ret = priv->edid_irq;
        dpu_pr_err("[MIPI2HDMI] Failed to get edid ready irq, ret=%d\n", ret);
        goto err_out;
    }
    ret = request_irq(priv->edid_irq, mipi2hdmi_edid_irq_handler,
        IRQF_TRIGGER_FALLING, "mipi2hdmi_edid_irq", priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to request edid interupt handler, ret=%d\n", ret);
        goto err_out;
    }
    disable_irq(priv->edid_irq);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;

err_out:
    devm_gpio_free(&priv->pdev->dev, priv->edid_gpio);
    cancel_delayed_work(&priv->edid_irq_work);
    return ret;
}

static void mipi2hdmi_edid_release(struct mipi2hdmi_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_no_retval(!priv->pdev, err, "[MIPI2HDMI] priv->pdev is null\n");

    free_irq(priv->edid_irq, priv);
    devm_gpio_free(&priv->pdev->dev, priv->edid_gpio);
    cancel_delayed_work(&priv->edid_irq_work);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static int32_t mipi2hdmi_wait_edid(struct mipi2hdmi_private *priv)
{
    unsigned long remain_time = 0;
    uint8_t timeout_cnt = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    enable_irq(priv->edid_irq);
    mipi2hdmi_set_edid_status(priv, EDID_STATUS_NOT_READY);
    do {
        remain_time = wait_event_timeout(priv->edid_ready_waitq,
            atomic_read(&priv->edid_ready_atom) != EDID_STATUS_NOT_READY,
            msecs_to_jiffies(WAIT_EDID_READY_TIMEOUT));
        dpu_pr_info("[MIPI2HDMI] remain_time=%u\n", remain_time);

        if (remain_time == 0) {
            dpu_pr_warn("[MIPI2HDMI] wait edid ready timeout, timeout_cnt=%d\n", timeout_cnt);
        }
    } while (remain_time == 0 && ++timeout_cnt < MAX_WAIT_EDID_READY_TIMES);
    disable_irq(priv->edid_irq);
    dpu_pr_info("[MIPI2HDMI] priv->edid_ready_atom=%d\n", atomic_read(&priv->edid_ready_atom));
    if (timeout_cnt >= MAX_WAIT_EDID_READY_TIMES || atomic_read(&priv->edid_ready_atom) == EDID_STATUS_BAD) {
        dpu_pr_err("[MIPI2HDMI] Failed to read edid!\n");
        return -EEDID_FAILED;
    } else if (atomic_read(&priv->edid_ready_atom) == EDID_STATUS_BREAK) {
        dpu_pr_err("[MIPI2HDMI] Monitor plugout\n");
        return -EEDID_BREAK;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_power_on_internal(struct dkmd_connector_info *pinfo)
{
    int32_t ret = 0;
    struct mipi2hdmi_private *priv = NULL;
    struct mipi2hdmi_bridge *bridge = NULL;
    struct mipi2hdmi_redriver *redriver = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (priv->power_on) {
        dpu_pr_warn("[MIPI2HDMI] bridge is powered on\n");
        return 0;
    }
    bridge = mipi2hdmi_get_bridge(priv);
    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    if (!bridge->on_func) {
        dpu_pr_err("[MIPI2HDMI] bridge on_func is null\n");
        return -EINVAL;
    }
    ret = bridge->on_func(bridge);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to power on, ret=%d\n", ret);
        return -EINVAL;
    }
    redriver = mipi2hdmi_get_redriver(priv);
    if (redriver != NULL) {
        dpu_pr_info("[MIPI2HDMI] configure redriver\n");
        if (!redriver->configure_func || redriver->configure_func(redriver, HDMI_PROTO_VERSION_2DOT0) != 0) {
            dpu_pr_warn("[MIPI2HDMI] Failed to configure redriver\n");
        }
    }
    if (!bridge->deassert_reset) {
        dpu_pr_err("[MIPI2HDMI] bridge deassert_reset is null\n");
        return -EINVAL;
    }
    ret = bridge->deassert_reset(bridge);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to deassert reset, ret=%d\n", ret);
        return -EINVAL;
    }
    priv->power_on = true;
    priv->first_int_power_on = true;

    switch_set_state(&pinfo->video_switch, HOT_PANEL_ON);

    dpu_pr_info("[MIPI2HDMI] power on success\n");

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static void mipi2hdmi_print_timing_info(struct edid_timing_info *timing_info_node)
{
    dpu_check_and_no_retval(!timing_info_node, err, "[MIPI2HDMI] timing_info_node is null\n");

    dpu_pr_info("[MIPI2HDMI]  hactive_pixels=%hu hblanking=%hu hsize=%hu hsync_offset=%hu \
        hsync_polarity=%hhu hsync_pulse_width=%hu \n",
        timing_info_node->hactive_pixels, timing_info_node->hblanking, timing_info_node->hsize,
        timing_info_node->hsync_offset, timing_info_node->hsync_polarity, timing_info_node->hsync_pulse_width);
    dpu_pr_info("[MIPI2HDMI] vactive_pixels=%hu vblanking=%hu vsize=%hu vsync_offset=%hu vsync_polarity=%hhu \
        vsync_pulse_width=%hu fps=%hu\n", timing_info_node->vactive_pixels, timing_info_node->vblanking,
            timing_info_node->vsize, timing_info_node->vsync_offset, timing_info_node->vsync_polarity,
            timing_info_node->vsync_pulse_width, timing_info_node->fps);
    dpu_pr_info("[MIPI2HDMI] interlaced=%hu pixel_clock=%llu input_type=%hu\n",
        timing_info_node->interlaced, timing_info_node->pixel_clock, timing_info_node->input_type);
}

static int32_t mipi2hdmi_edid_information_free(struct edid_information *edid_info)
{
    struct edid_timing_node *timing_info_node = NULL;
    struct edid_timing_node *tmp_node = NULL;
    struct ext_timing *ext_timing_node = NULL;
    struct ext_timing *tmp_ext_node = NULL;
    struct edid_audio_info *audio_info_node = NULL;
    struct edid_audio_info *tmp_audio_node = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!edid_info, -EINVAL, err, "[MIPI2HDMI] edid_info is null\n");

    list_for_each_entry_safe(timing_info_node, tmp_node, &edid_info->video.video_timing.video_timing_list, list_node) {
        if (!timing_info_node) {
            dpu_pr_err("[MIPI2HDMI] timing_info_node is null\n");
            continue;
        }
        list_del(&timing_info_node->list_node);
        kfree(timing_info_node);
    }
    list_for_each_entry_safe(ext_timing_node, tmp_ext_node, &edid_info->video.video_timing.ext_timing, list_node) {
        if (!ext_timing_node) {
            dpu_pr_err("[MIPI2HDMI] ext_timing_node is null\n");
            continue;
        }
        list_del(&ext_timing_node->list_node);
        kfree(ext_timing_node);
    }
    list_for_each_entry_safe(audio_info_node, tmp_audio_node, &edid_info->audio.spec, list_node) {
        if (!audio_info_node) {
            dpu_pr_err("[MIPI2HDMI] audio_info_node is null\n");
            continue;
        }
        list_del(&audio_info_node->list_node);
        kfree(audio_info_node);
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_timing_list_filter(struct dkmd_connector_info *pinfo,
    struct edid_timing_info *timing_list, size_t timing_list_size)
{
    int32_t ret = 0;
    uint32_t i = 0;
    uint32_t cnt = 0;
    uint16_t hactive_half = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    dpu_check_and_return(!timing_list, -EINVAL, err, "[MIPI2HDMI] timing_list is null\n");

    if (timing_list_size < sizeof(pinfo->base.timing_list)) {
        dpu_pr_err("[MIPI2HDMI] timing_list_size is invalid");
        return -EINVAL;
    }

    if (pinfo->base.timing_num > MAX_TIMING_NUM) {
        dpu_pr_warn("[MIPI2HDMI] timing_num is %u, exceeds the max value\n", pinfo->base.timing_num);
        pinfo->base.timing_num = MAX_TIMING_NUM;
    }

    for (i = 0; i < pinfo->base.timing_num; i++) {
        hactive_half = pinfo->base.timing_list[i].hactive_pixels / EDID_TIMING_DIVISOR;
        if ((hactive_half % EDID_TIMING_DIVISOR) != 0) {
            dpu_pr_warn("[MIPI2HDMI] invalid timing[%u]: [%u * %u @ %u]\n",
                i, pinfo->base.timing_list[i].hactive_pixels,
                pinfo->base.timing_list[i].vactive_pixels, pinfo->base.timing_list[i].fps);
            continue;
        }
        timing_list[cnt++] = pinfo->base.timing_list[i];
    }

    pinfo->base.timing_num = cnt;
    dpu_pr_info("[MIPI2HDMI] valid timing count: %u\n", pinfo->base.timing_num);
    ret = memcpy_s(pinfo->base.timing_list, sizeof(pinfo->base.timing_list), timing_list, timing_list_size);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] failed to copy edid timing list\n");
        return ret;
    }

    if (cnt == 0) {
        dpu_pr_err("[MIPI2HDMI] all edid timings are invalid\n");
        return -EEDID_FILTER_FAILED;
    }

    for (i = 0; i < pinfo->base.timing_num; i++) {
        dpu_pr_info("[MIPI2HDMI] valid timing[%u]: [%u * %u @ %u], pixel_clock[%llu]KHz\n", i,
            pinfo->base.timing_list[i].hactive_pixels, pinfo->base.timing_list[i].vactive_pixels,
            pinfo->base.timing_list[i].fps, pinfo->base.timing_list[i].pixel_clock);
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_edid_timing_filter(struct mipi2hdmi_private *priv)
{
    int32_t ret = 0;
    struct dkmd_connector_info *pinfo = NULL;
    struct edid_timing_info *tmp_timing_list = NULL;
    size_t timing_list_size = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    pinfo = &priv->connector_info;
    timing_list_size = sizeof(pinfo->base.timing_list);
    tmp_timing_list = kzalloc(timing_list_size, GFP_KERNEL);
    if (tmp_timing_list == NULL) {
        dpu_pr_err("[MIPI2HDMI] Failed to allocate memory\n");
        return -ENOMEM;
    }

    ret = mipi2hdmi_timing_list_filter(pinfo, tmp_timing_list, timing_list_size);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to filter timing list\n");
    }

    if (tmp_timing_list != NULL) {
        kfree(tmp_timing_list);
        tmp_timing_list = NULL;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return ret;
}

static int32_t mipi2hdmi_edid_parse(struct mipi2hdmi_private *priv, struct edid_information *edid_info)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_info, -EINVAL, err, "[MIPI2HDMI] edid_info is null\n");

    INIT_LIST_HEAD(&edid_info->video.video_timing.video_timing_list);
    INIT_LIST_HEAD(&edid_info->video.video_timing.ext_timing);
    INIT_LIST_HEAD(&edid_info->audio.spec);

    if (!edid_parse_info(priv->edid, priv->edid_len, &priv->connector_info, edid_info)) {
        dpu_pr_err("[MIPI2HDMI] Failed to parse edid data\n");
        return -EEDID_PARSE_FAILED;
    }

    priv->connector_info.base.edid = priv->edid;
    priv->connector_info.base.edid_len = priv->edid_len;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_get_prefered_timing(struct mipi2hdmi_private *priv, struct edid_timing_info *edid_timing)
{
    int32_t ret = -1;
    struct edid_timing_info *edid_timing_tmp = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_timing, -EINVAL, err, "[MIPI2HDMI] edid_timing is null\n");

    edid_timing_tmp = edid_get_preferred_timing(&priv->connector_info);
    dpu_check_and_return(!edid_timing_tmp, -EINVAL, err, "[MIPI2HDMI] edid_timing_tmp is null\n");

    ret = memcpy_s(edid_timing, sizeof(struct edid_timing_info),
        edid_timing_tmp, sizeof(struct edid_timing_info));
    if (ret != EOK) {
        dpu_pr_err("[MIPI2HDMI] Failed to copy edid timing, ret=%d\n", ret);
        return ret;
    }
    dpu_pr_info("[MIPI2HDMI] prefered hactive=%hu vactive=%hu\n",
        edid_timing->hactive_pixels, edid_timing->vactive_pixels);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static bool mipi2hdmi_timing_match(struct edid_timing_info *edid_timing, const struct dtd *dtd_timing)
{
    uint16_t width_ratio = 0;
    uint16_t height_ratio = 0;
    uint64_t pixel_clock_diff = 0;

    dpu_check_and_return(!edid_timing, false, err, "[MIPI2HDMI] edid_timing is null\n");
    dpu_check_and_return(!dtd_timing, false, err, "[MIPI2HDMI] dtd_timing is null\n");

    if (dtd_timing->h_image_size == 0 || dtd_timing->v_image_size == 0) {
        dpu_pr_warn("[MIPI2HDMI] h_image_size or v_image_size is zero\n");
        return false;
    }

    width_ratio = edid_timing->hsize / dtd_timing->h_image_size;
    height_ratio = edid_timing->vsize / dtd_timing->v_image_size;
    pixel_clock_diff =  (edid_timing->pixel_clock > dtd_timing->pixel_clock) ?
        (edid_timing->pixel_clock - dtd_timing->pixel_clock) :
        (dtd_timing->pixel_clock - edid_timing->pixel_clock);
    if (width_ratio == height_ratio &&
        edid_timing->hactive_pixels == dtd_timing->h_active &&
        edid_timing->vactive_pixels == dtd_timing->v_active &&
        edid_timing->hblanking == dtd_timing->h_blanking &&
        edid_timing->vblanking == dtd_timing->v_blanking &&
        edid_timing->hsync_offset == dtd_timing->h_sync_offset &&
        edid_timing->vsync_offset == dtd_timing->v_sync_offset &&
        edid_timing->hsync_pulse_width == dtd_timing->h_sync_pulse_width &&
        edid_timing->vsync_pulse_width == dtd_timing->v_sync_pulse_width &&
        edid_timing->hsync_polarity == dtd_timing->h_sync_polarity &&
        edid_timing->vsync_polarity == dtd_timing->v_sync_polarity &&
        pixel_clock_diff <= PIXEL_CLOCK_MAX_DIFF) {
        dpu_pr_info("[MIPI2HDMI] edid timing matches with dtd timing\n");
        return true;
    }

    return false;
}

static int32_t mipi2hdmi_get_video_id(struct edid_timing_info *edid_timing, uint8_t *vic)
{
    size_t i = 0;

    dpu_check_and_return(!edid_timing, -EINVAL, err, "[MIPI2HDMI] edid_timing is null\n");
    dpu_check_and_return(!vic, -EINVAL, err, "[MIPI2HDMI] vic is null\n");

    for (i = CTA_PART1_VIC_START_CODE; i < sizeof(cta_modes_dtd_part1) / sizeof(struct dtd); i++) {
        if (mipi2hdmi_timing_match(edid_timing, &cta_modes_dtd_part1[i])) {
            *vic = (uint8_t)(i & 0xFF);
            break;
        }
    }
    if (*vic == 0) {
        for (i = 0; i < sizeof(cta_modes_dtd_part2) / sizeof(struct dtd); i++) {
            if (mipi2hdmi_timing_match(edid_timing, &cta_modes_dtd_part2[i])) {
                *vic = (uint8_t)(i & 0xFF) + CTA_PART2_VIC_START_CODE;
                break;
            }
        }
    }

    dpu_pr_info("[MIPI2HDMI] vic=%hhu\n", *vic);

    return 0;
}

static int32_t mipi2hdmi_convert_timing(struct edid_timing_info *edid_timing,
    struct mipi2hdmi_video_timing *video_timing)
{
    dpu_check_and_return(!edid_timing, -EINVAL, err, "[MIPI2HDMI] edid_timing is null\n");
    dpu_check_and_return(!video_timing, -EINVAL, err, "[MIPI2HDMI] video_timing is null\n");

    video_timing->vtotal = edid_timing->vblanking + edid_timing->vactive_pixels;
    video_timing->vactive = edid_timing->vactive_pixels;
    video_timing->vfp = edid_timing->vsync_offset;
    video_timing->vsa = edid_timing->vsync_pulse_width;
    if (edid_timing->vblanking > edid_timing->vsync_offset &&
        (edid_timing->vblanking - edid_timing->vsync_offset) > edid_timing->vsync_pulse_width) {
        video_timing->vbp = edid_timing->vblanking - edid_timing->vsync_offset - edid_timing->vsync_pulse_width;
    } else {
        dpu_pr_err("[MIPI2HDMI] vblanking or vsync_offset or vsync_pulse_width is invalid\n");
        return -EINVAL;
    }
    video_timing->htotal = edid_timing->hblanking + edid_timing->hactive_pixels;
    video_timing->hactive = edid_timing->hactive_pixels;
    video_timing->hfp = edid_timing->hsync_offset;
    video_timing->hsa = edid_timing->hsync_pulse_width;
    if (edid_timing->hblanking > edid_timing->hsync_offset &&
        (edid_timing->hblanking - edid_timing->hsync_offset) > edid_timing->hsync_pulse_width) {
        video_timing->hbp = edid_timing->hblanking - edid_timing->hsync_offset - edid_timing->hsync_pulse_width;
    } else {
        dpu_pr_err("[MIPI2HDMI] vblanking or vsync_offset or vsync_pulse_width is invalid\n");
        return -EINVAL;
    }
    video_timing->fps = (uint8_t)(edid_timing->fps & 0x00FF);
    if (mipi2hdmi_get_video_id(edid_timing, &video_timing->vic) != 0) {
        dpu_pr_warn("[MIPI2HDMI] failed to get video id\n");
    }

    dpu_pr_info("[MIPI2HDMI] vtotal=%hu, vactive=%hu, vbp=%hu, vsa=%hu, vfp=%hu\n",
           video_timing->vtotal, video_timing->vactive, video_timing->vbp, video_timing->vsa, video_timing->vfp);
    dpu_pr_info("[MIPI2HDMI] htotal=%hu, hactive=%hu, hbp=%hu, hsa=%hu, hfp=%hu\n",
           video_timing->htotal, video_timing->hactive, video_timing->hbp, video_timing->hsa, video_timing->hfp);

    return 0;
}

static int32_t mipi2hdmi_set_redriver_params(struct mipi2hdmi_private *priv,
    struct mipi2hdmi_video_timing *video_timing)
{
    int32_t ret = 0;
    struct mipi2hdmi_redriver *redriver = NULL;
    uint32_t resolution = 0;
    MIPI2HDMI_PROTO_VERSION proto_ver = HDMI_PROTO_VERSION_1DOT4;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!video_timing, -EINVAL, err, "[MIPI2HDMI] video_timing is null\n");

    resolution = (uint32_t)video_timing->hactive * video_timing->vactive;
    if (video_timing->fps == 0) {
        dpu_pr_err("[MIPI2HDMI] fps is zero\n");
        return -EINVAL;
    }
    if (resolution >= PIXEL_CLOCK_HDMI_VERSION_2DOT0 / video_timing->fps) {
        proto_ver = HDMI_PROTO_VERSION_2DOT0;
    } else {
        proto_ver = HDMI_PROTO_VERSION_1DOT4;
    }
    dpu_pr_info("[MIPI2HDMI] proto_ver=%d\n", proto_ver);
    redriver = mipi2hdmi_get_redriver(priv);
    if (redriver != NULL) {
        dpu_pr_info("[MIPI2HDMI] configure redriver\n");
        if (!redriver->configure_func || redriver->configure_func(redriver, proto_ver) != 0) {
            dpu_pr_warn("[MIPI2HDMI] Failed to configure redriver\n");
        }
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_set_display_timing(struct mipi2hdmi_private *priv,
    struct mipi2hdmi_video_timing *video_timing)
{
    int32_t ret = 0;
    struct mipi2hdmi_bridge *bridge = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!video_timing, -EINVAL, err, "[MIPI2HDMI] video_timing is null\n");
    bridge = mipi2hdmi_get_bridge(priv);
    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    if (!bridge->set_display_timing) {
        dpu_pr_err("[MIPI2HDMI] bridge set_display_timing is null\n");
        return -EINVAL;
    }
    ret = bridge->set_display_timing(bridge, video_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] bridge set_display_timing failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_calc_phy_params(struct mipi2hdmi_private *priv, struct edid_information *edid_info)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_info, -EINVAL, err, "[MIPI2HDMI] edid_info is null\n");

    priv->connector_info.base.width = edid_info->video.video_timing.max_himage_size * 10;
    priv->connector_info.base.height = edid_info->video.video_timing.max_vimage_size * 10;
    if (priv->connector_info.base.width == 0 || priv->connector_info.base.height == 0) {
        dpu_pr_info("[MIPI2HDMI] edid height and width are 0 , set LCD_DEFAULT_WIDTH and LCD_DEFAULT_HEIGHT\n");
        priv->connector_info.base.width = LCD_DEFAULT_WIDTH;
        priv->connector_info.base.height = LCD_DEFAULT_HEIGHT;
    }

    dpu_pr_info("[MIPI2HDMI] width is %d, height is %d\n", priv->connector_info.base.width,
        priv->connector_info.base.height);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_calc_mipi_params(struct mipi2hdmi_private *priv, struct edid_timing_info *edid_timing)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_timing, -EINVAL, err, "[MIPI2HDMI] edid_timing is null\n");

    priv->connector_info.base.dsc_out_width = edid_timing->hactive_pixels;
    priv->connector_info.base.dsc_out_height = edid_timing->vactive_pixels;
    priv->connector_info.base.xres = edid_timing->hactive_pixels;
    priv->connector_info.base.yres = edid_timing->vactive_pixels;
    priv->connector_info.base.fps = edid_timing->fps;
    ret = connector_device_edid_timing_calculate(edid_timing, &priv->connector_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to calculate mipi params, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_set_device_params(struct mipi2hdmi_private *priv, struct edid_timing_info *edid_timing)
{
    int32_t ret = 0;
    struct mipi2hdmi_video_timing video_timing = {0};

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_timing, -EINVAL, err, "[MIPI2HDMI] edid_timing is null\n");

    ret = mipi2hdmi_convert_timing(edid_timing, &video_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to convert timing, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_set_redriver_params(priv, &video_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set redriver params\n");
        return ret;
    }
    ret = mipi2hdmi_set_display_timing(priv, &video_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set display timing, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_calc_mipi_params(priv, edid_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to calculate edid timing, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_update_default_timing(struct mipi2hdmi_private *priv, struct edid_information *edid_info)
{
    int32_t ret = 0;
    struct edid_timing_info edid_timing = {0};

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_info, -EINVAL, err, "[MIPI2HDMI] edid_info is null\n");

    ret = mipi2hdmi_get_prefered_timing(priv, &edid_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to get prefered timing, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_set_device_params(priv, &edid_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set device params, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_calc_phy_params(priv, edid_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to calc mipi phy params, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_get_audio_name(struct mipi2hdmi_private *priv, struct edid_information *edid_info)
{
    int32_t ret = 0;
    char mfg_name[MFG_NAME_LEN] = {0};
    uint16_t mfg_name_ori = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_info, -EINVAL, err, "[MIPI2HDMI] edid_info is null\n");

    if (edid_info->video.video_timing.monitor_descriptor[0] != '\0') {
        dpu_pr_info("[MIPI2HDMI] set monitor_descriptor: %s\n",
            edid_info->video.video_timing.monitor_descriptor);

        ret = sprintf_s(priv->audio_name, sizeof(priv->audio_name),
            "hdmi_mipi_audio,device_port=%s-0", edid_info->video.video_timing.monitor_descriptor);
    } else {
        mfg_name_ori = (uint16_t)priv->edid[EDID_MFG_START] << EDID_MFG_SHIFT_BITS |
            priv->edid[EDID_MFG_START + 1];
        mfg_name[ARRAY_INDEX_0] = 0b01000000 | ((mfg_name_ori >> EDID_MFG_FIRST_SHIFT_BITS) & 0b00011111);
        mfg_name[ARRAY_INDEX_1] = 0b01000000 | ((mfg_name_ori >> EDID_MFG_SECOND_SHIFT_BITS) & 0b00011111);
        mfg_name[ARRAY_INDEX_2] = 0b01000000 | (mfg_name_ori & 0b00011111);
        mfg_name[ARRAY_INDEX_3] = '\0';
        ret = sprintf_s(priv->audio_name, sizeof(priv->audio_name), "hdmi_mipi_audio,device_port=%s-0", mfg_name);
    }
    if (ret < 0) {
        dpu_pr_err("[MIPI2HDMI] audio_name create failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] audio_name=%s\n", priv->audio_name);
    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_check_audio(struct mipi2hdmi_private *priv, struct edid_information *edid_info)
{
    int32_t ret = 0;
    struct mipi2hdmi_bridge *bridge = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_info, -EINVAL, err, "[MIPI2HDMI] edid_info is null\n");

    ret = memset_s(priv->audio_name, sizeof(priv->audio_name), 0, AUDIO_SWITCH_DEV_NAME_LEN);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to memset audio name, ret=%d\n", ret);
        return ret;
    }
    bridge = mipi2hdmi_get_bridge(priv);
    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    if (!bridge->enable_i2s || !bridge->disable_i2s) {
        dpu_pr_err("[MIPI2HDMI] bridge enable_i2s or disable_i2s is null\n");
        return -EINVAL;
    }
    if (edid_info->audio.basic_audio == 0x01) {
        ret = bridge->enable_i2s(bridge);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] Failed to enable i2s, ret=%d\n", ret);
            return ret;
        }
        ret = mipi2hdmi_get_audio_name(priv, edid_info);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] Failed to get audio name, ret=%d\n", ret);
            return ret;
        }
    } else {
        ret = bridge->disable_i2s(bridge);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] Failed to disable i2s, ret=%d\n", ret);
            return ret;
        }
    }
    ret = update_audio_dev(&priv->connector_info, priv->audio_name);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to update audio dev, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_check_manufacture(struct mipi2hdmi_private *priv, struct edid_information *edid_info)
{
    int32_t ret = 0;
    struct mipi2hdmi_bridge *bridge = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!edid_info, -EINVAL, err, "[MIPI2HDMI] edid_info is null\n");

    if (!priv->set_hdcp_mode) {
        dpu_pr_info("[MIPI2HDMI] product does not support setting hdcp mode\n");
        return 0;
    }

    if (strcmp(edid_info->product_info.vendor_name, "SKY") != 0 ||
        edid_info->product_info.product_code != SKYWORTH_PRODUCT_CODE ||
        edid_info->product_info.serial_number != SKYWORTH_SERIAL_NUMBER) {
        return 0;
    }

    bridge = mipi2hdmi_get_bridge(priv);
    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    if (!bridge->set_hdcp) {
        dpu_pr_err("[MIPI2HDMI] bridge set_hdcp is null\n");
        return -EINVAL;
    }

    ret = bridge->set_hdcp(bridge, HDCP_VERSION_1DOT4);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set hdcp mode, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_edid_change(struct mipi2hdmi_private *priv)
{
    int32_t ret = 0;
    int32_t i = 0;
    bool edid_changed = false;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (priv->prev_edid_len > 0 && priv->edid_len > 0) {
        for (i = EDID_MFG_START; i < EDID_MFG_START + EDID_MFG_LEN; i++) {
            if (priv->edid[i] != priv->prev_edid[i]) {
                edid_changed = true;
                dpu_pr_info("[MIPI2HDMI] edid changed\n");
                break;
            }
        }
        if (edid_changed) {
            ret = connector_device_trigger_uevent_hotplug(&priv->connector_info, DPU_HOT_PLUG_OUT);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] connector device trigger plugout failed, ret=%d\n", ret);
                return ret;
            }
            msleep(PLUGOUT_PLUGIN_INTERVAL);
            ret = connector_device_trigger_uevent_hotplug(&priv->connector_info, DPU_HOT_PLUG_IN);
            if (ret != 0) {
                dpu_pr_err("[MIPI2HDMI] connector device trigger plugin failed, ret=%d\n", ret);
                return ret;
            }
        }
    }
    ret = memcpy_s(priv->prev_edid, sizeof(priv->prev_edid), priv->edid, sizeof(priv->edid));
    if (ret != EOK) {
        dpu_pr_err("[MIPI2HDMI] copy edid to prev_edid failed, ret=%d\n", ret);
        return ret;
    }
    priv->prev_edid_len = priv->edid_len;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_edid_process(struct mipi2hdmi_private *priv)
{
    int32_t ret = 0;
    struct edid_information edid_info = {0};

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    ret = mipi2hdmi_edid_change(priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to check edid change, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_edid_parse(priv, &edid_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to parse edid data, ret=%d\n", ret);
        goto err_out;
    }
    ret = mipi2hdmi_edid_timing_filter(priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to filter edid timing, ret=%d\n", ret);
        goto err_out;
    }
    ret = mipi2hdmi_update_default_timing(priv, &edid_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to update default timing, ret=%d\n", ret);
        goto err_out;
    }
    ret = mipi2hdmi_check_audio(priv, &edid_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to check audio, ret=%d\n", ret);
        goto err_out;
    }
    ret = mipi2hdmi_check_manufacture(priv, &edid_info);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to check manufacture, ret=%d\n", ret);
        goto err_out;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

err_out:
    (void)mipi2hdmi_edid_information_free(&edid_info);
    return ret;
}

static int32_t mipi2hdmi_use_default_timing(struct mipi2hdmi_private *priv)
{
    int ret = 0;
    struct edid_timing_info tmp_timing = {0};

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (memcmp(&priv->edid_timing, &tmp_timing, sizeof(struct edid_timing_info)) == 0) {
        ret = mipi2hdmi_init_default_timing(&priv->connector_info);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] Failed to init default timing, ret=%d\n", ret);
            return ret;
        }
    }
    ret = mipi2hdmi_set_device_params(priv, &priv->edid_timing);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set device params, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_power_on(struct dkmd_connector_info *pinfo)
{
    int32_t ret = 0;
    struct mipi2hdmi_private *priv = NULL;
    struct mipi2hdmi_bridge *bridge = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    bridge = mipi2hdmi_get_bridge(priv);
    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    ret = mipi2hdmi_power_on_internal(pinfo);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to power on internal, ret=%d\n", ret);
        return -EINVAL;
    }

    if (!priv->setting_timing) {
        dpu_pr_info("[MIPI2HDMI] setting timing is not ongoing, need not to set device params\n");
        return 0;
    }
    priv->setting_timing = false;

    if (priv->user_timing_index >= pinfo->base.timing_num) {
        dpu_pr_err("[MIPI2HDMI] user_timing_index is invalid, user_timing_index=%d\n", priv->user_timing_index);
        return -EINVAL;
    }

    ret = memcpy_s(&priv->edid_timing, sizeof(struct edid_timing_info),
        &pinfo->base.timing_list[priv->user_timing_index], sizeof(struct edid_timing_info));
    if (ret != EOK) {
        dpu_pr_err("[MIPI2HDMI] Failed to backup user timing, ret=%d\n", ret);
        return ret;
    }

    ret = mipi2hdmi_set_device_params(priv, &pinfo->base.timing_list[priv->user_timing_index]);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to set device params, ret=%d\n", ret);
        return ret;
    }

    if (priv->audio_name[0] != '\0') {
        if (!bridge->enable_i2s) {
            dpu_pr_err("[MIPI2HDMI] bridge enable_i2s is null\n");
            return -EINVAL;
        }
        ret = bridge->enable_i2s(bridge);
        if (ret != 0) {
            dpu_pr_err("[MIPI2HDMI] Failed to enable i2s, ret=%d\n", ret);
            return ret;
        }
    }
    dpu_pr_info("[MIPI2HDMI] -\n");
    return 0;
}

static int32_t mipi2hdmi_power_off(struct dkmd_connector_info *pinfo)
{
    int32_t ret = 0;
    struct mipi2hdmi_private *priv = NULL;
    struct mipi2hdmi_bridge *bridge = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (!priv->power_on) {
        dpu_pr_warn("[MIPI2HDMI] bridge is powered off\n");
        return 0;
    }
    priv->power_on = false;
    bridge = mipi2hdmi_get_bridge(priv);
    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");
    if (!bridge->off_func) {
        dpu_pr_err("[MIPI2HDMI] bridge off_func is null\n");
        return -EINVAL;
    }
    ret = bridge->off_func(bridge);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to power off, ret=%d\n", ret);
        return -EINVAL;
    }

    switch_set_state(&pinfo->video_switch, HOT_PANEL_OFF);

    dpu_pr_info("[MIPI2HDMI] power off success\n");

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_connect_device(struct dkmd_connector_info *pinfo)
{
    int32_t ret = 0;
    struct mipi2hdmi_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (priv->device_connected) {
        dpu_pr_info("[MIPI2HDMI] device is connected\n");
        return 0;
    }
    ret = mipi2hdmi_power_on_internal(pinfo);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to power on device, ret=%d\n", ret);
        return ret;
    }
    ret = mipi2hdmi_wait_edid(priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to wait for edid, ret=%d\n", ret);
        goto err_out;
    }
    ret = mipi2hdmi_edid_process(priv);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to process edid, ret=%d\n", ret);
        goto err_out;
    }
    priv->device_connected = true;
    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;

err_out:
    if (ret == -EEDID_BREAK) {
        /* if monitor plugout, power off device */
        (void)mipi2hdmi_power_off(pinfo);
    } else {
        /* if failed to read the edid, use default timing to present */
        (void)mipi2hdmi_use_default_timing(priv);
        priv->device_connected = true;
        dpu_pr_warn("[MIPI2HDMI] use default timing to present\n");
        return 0;
    }
    return ret;
}

static int32_t mipi2hdmi_disconnect_device(struct dkmd_connector_info *pinfo)
{
    int32_t ret = 0;
    struct mipi2hdmi_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (!priv->device_connected) {
        dpu_pr_info("[MIPI2HDMI] device is disconnected\n");
        return 0;
    }
    priv->device_connected = false;
    ret = mipi2hdmi_power_off(pinfo);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to power off device, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_set_device_timing(struct dkmd_connector_info *pinfo, uint32_t timing_index)
{
    int32_t ret = 0;
    struct mipi2hdmi_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pinfo, -EINVAL, err, "[MIPI2HDMI] pinfo is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (timing_index >= pinfo->base.timing_num) {
        dpu_pr_err("[MIPI2HDMI] timing_index is invalid, timing_index=%u\n", timing_index);
        return -1;
    }

    priv->user_timing_index = timing_index;
    priv->setting_timing = true;

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_setup_dev_data(struct mipi2hdmi_private *priv)
{
    struct dkmd_conn_handle_data *pdata = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    dpu_check_and_return(!priv->pdev, -EINVAL, err, "[MIPI2HDMI] priv->pdev is null\n");

    pdata = devm_kzalloc(&priv->pdev->dev, sizeof(*pdata), GFP_KERNEL);
    if (!pdata) {
        dpu_pr_err("[MIPI2HDMI] alloc panel device data failed!\n");
        return -ENOMEM;
    }
    pdata->conn_info = &priv->connector_info;
    pdata->on_func = mipi2hdmi_power_on;
    pdata->off_func = mipi2hdmi_power_off;
    pdata->connect_func = mipi2hdmi_connect_device;
    pdata->disconnect_func = mipi2hdmi_disconnect_device;
    pdata->set_display_timing = mipi2hdmi_set_device_timing;
    if (platform_device_add_data(priv->pdev, pdata, sizeof(*pdata)) != 0) {
        dpu_pr_err("[MIPI2HDMI] add device data failed!\n");
        devm_kfree(&priv->pdev->dev, pdata);
        pdata = NULL;
        return -ENOMEM;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

int32_t mipi2hdmi_check_online(struct mipi2hdmi_bridge *bridge)
{
    int32_t ret = 0;
    int32_t value = 0;
    bool monitor_online = false;
    struct platform_device *pdev = NULL;
    struct mipi2hdmi_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!bridge, -EINVAL, err, "[MIPI2HDMI] bridge is null\n");

    if (bridge->bridge_id >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] bridge id is invalid!\n");
        return -EINVAL;
    }
    pdev = g_dkmd_mipi2hdmi_dev[bridge->bridge_id];
    dpu_check_and_return(!pdev, -EINVAL, err, "[MIPI2HDMI] pdev is null\n");
    priv = platform_get_drvdata(pdev);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");
    enable_irq(priv->hpd_irq);
    value = gpio_get_value(priv->hpd_gpio);
    monitor_online = (value == GPIO_LOW_VOLTAGE) ? true : false;
    if (monitor_online) {
        ret = mipi2hdmi_device_trigger(priv, DPU_HOT_PLUG_IN);
        if (ret != 0) {
            dpu_pr_warn("[MIPI2HDMI] device trigger plugin failed, ret=%d\n", ret);
            return ret;
        }
    }

    dpu_pr_info("[MIPI2HDMI] monitor online status=%d\n", monitor_online);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_base_setup(struct mipi2hdmi_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    if (mipi2hdmi_display_setup(priv)) {
        dpu_pr_err("[MIPI2HDMI] Failed to do base setup\n");
        return -EPROBE_DEFER;
    }
    if (mipi2hdmi_setup_dev_data(priv)) {
        dpu_pr_err("[MIPI2HDMI] Failed to setup dev data\n");
        return -EPROBE_DEFER;
    }
    if (mipi2hdmi_hpd_setup(priv)) {
        dpu_pr_err("[MIPI2HDMI] Failed to setup hpd\n");
        return -EPROBE_DEFER;
    }
    if (mipi2hdmi_edid_setup(priv)) {
        dpu_pr_err("[MIPI2HDMI] Failed to setup edid\n");
        goto err_out;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;

err_out:
    mipi2hdmi_hpd_release(priv);
    return -EPROBE_DEFER;
}

static void mipi2hdmi_mem_release(struct platform_device *pdev, struct mipi2hdmi_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!pdev, err, "[MIPI2HDMI] pdev is null\n");
    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    platform_set_drvdata(pdev, NULL);
    devm_kfree(&pdev->dev, priv);
    priv = NULL;

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void mipi2hdmi_save_device(struct platform_device *pdev, struct mipi2hdmi_private *priv)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_no_retval(!pdev, err, "[MIPI2HDMI] pdev is null\n");
    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    if (priv->connector_info.connector_idx[0] >= MAX_GFX_MIPI_DEV_COUNT) {
        dpu_pr_err("[MIPI2HDMI] connector id is invalid!\n");
        return;
    }
    dpu_pr_info("[MIPI2HDMI] connector id is %u\n", priv->connector_info.connector_idx[0]);
    g_dkmd_mipi2hdmi_dev[priv->connector_info.connector_idx[0]] = pdev;

    dpu_pr_info("[MIPI2HDMI] -\n");
}

static void mipi2hdmi_get_dfr_info(struct dkmd_connector_info *pinfo, struct dfr_info **out)
{
    struct mipi2hdmi_private *priv = NULL;

    dpu_check_and_no_retval(!pinfo, err, "[MIPI2HDMI] pinfo is null\n");
    dpu_check_and_no_retval(!out, err, "[MIPI2HDMI] out is null\n");
    priv = to_mipi2hdmi_private(pinfo);
    dpu_check_and_no_retval(!priv, err, "[MIPI2HDMI] priv is null\n");

    *out = &priv->dfr_info;
}

static int mipi2hdmi_probe(struct platform_device *pdev)
{
    struct mipi2hdmi_private *priv = NULL;

    dpu_check_and_return(!pdev, -EINVAL, err, "[MIPI2HDMI] pdev is null\n");

    dpu_pr_info("[MIPI2HDMI] +\n");

    if (!is_connector_manager_available()) {
        dpu_pr_err("[MIPI2HDMI] connector manager is not available\n");
        return -EPROBE_DEFER;
    }
    priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
    dpu_check_and_return(!priv, -ENOMEM, err, "[MIPI2HDMI] alloc mipi2hdmi driver private data failed!\n");
    priv->pdev = pdev;
    priv->connector_info.base.peri_device = pdev;
    priv->connector_info.get_dfr_info = mipi2hdmi_get_dfr_info;
    platform_set_drvdata(pdev, priv);
    if (mipi2hdmi_base_setup(priv) != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to do base setup\n");
        goto err_mem_free;
    }
    if (register_connector(&priv->connector_info) != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to register connector\n");
        goto err_mem_free;
    }
    if (register_switch_dev(&priv->connector_info) != 0) {
        dpu_pr_err("[MIPI2HDMI] Failed to register switch dev\n");
        goto err_connector_unregister;
    }
    mipi2hdmi_save_device(pdev, priv);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;

err_connector_unregister:
    unregister_connector(&priv->connector_info);
err_mem_free:
    mipi2hdmi_mem_release(pdev, priv);
    return -EPROBE_DEFER;
}

static int32_t mipi2hdmi_remove(struct platform_device *pdev)
{
    struct mipi2hdmi_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!pdev, -EINVAL, err, "[MIPI2HDMI] pdev is null\n");
    priv = (struct mipi2hdmi_private *)platform_get_drvdata(pdev);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

    unregister_connector(&priv->connector_info);
    unregister_switch_dev(&priv->connector_info);
    mipi2hdmi_hpd_release(priv);
    mipi2hdmi_edid_release(priv);
    mipi2hdmi_mem_release(pdev, priv);

    dpu_pr_info("[MIPI2HDMI] %s remove complete!\n", priv->connector_info.base.name);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_suspend(struct device *dev)
{
    struct mipi2hdmi_private *priv = NULL;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");
    priv = (struct mipi2hdmi_private *)dev_get_drvdata(dev);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

#ifdef CONFIG_SYS_PM_ULSR
    if (is_ulsr()) {
        dpu_pr_info("[MIPI2HDMI] ulsr suspend\n");
    }
#endif

    disable_irq(priv->hpd_irq);
    disable_irq(priv->edid_irq);

    dpu_pr_info("[MIPI2HDMI] priv->monitor_online=%d\n", priv->monitor_online);
    if (!priv->monitor_online) {
        dpu_pr_info("[MIPI2HDMI] monitor is offline, suspend is not required\n");
        return 0;
    }
    connector_device_suspend(&priv->connector_info);
    mipi2hdmi_disconnect_device(&priv->connector_info);

    dpu_pr_info("[MIPI2HDMI] %s suspend complete!\n", priv->connector_info.base.name);

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_resume(struct device *dev)
{
    int32_t ret = 0;
    struct mipi2hdmi_private *priv = NULL;
    int32_t value = 0;
    bool cur_monitor_online = false;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");
    priv = (struct mipi2hdmi_private *)dev_get_drvdata(dev);
    dpu_check_and_return(!priv, -EINVAL, err, "[MIPI2HDMI] priv is null\n");

#ifdef CONFIG_SYS_PM_ULSR
    if (is_ulsr()) {
        dpu_pr_info("[MIPI2HDMI] ulsr resume\n");
    }
#endif

    ret = irq_set_irq_type(priv->edid_irq, IRQF_TRIGGER_FALLING);
    if (ret < 0) {
        dpu_pr_warn("[MIPI2HDMI] resume, failed to set edid irq type!\n");
    }
    enable_irq(priv->edid_irq);

    cancel_delayed_work(&priv->delayed_resume_work);
    schedule_delayed_work(&priv->delayed_resume_work, msecs_to_jiffies(DELAYED_RESUME_WORK));

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_freeze(struct device *dev)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");

    ret = mipi2hdmi_suspend(dev);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] freeze failed, ret=%d\n", ret);
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static int32_t mipi2hdmi_restore(struct device *dev)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    dpu_check_and_return(!dev, -EINVAL, err, "[MIPI2HDMI] dev is null\n");

    ret = mipi2hdmi_resume(dev);
    if (ret != 0) {
        dpu_pr_warn("[MIPI2HDMI] restore failed, ret=%d\n", ret);
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static const struct dev_pm_ops mipi2hdmi_pm_ops = {
    .suspend = mipi2hdmi_suspend,
    .resume = mipi2hdmi_resume,
    .freeze = mipi2hdmi_freeze,
    .restore = mipi2hdmi_restore,
};

static const struct of_device_id mipi2hdmi_device_match_table[] = {
    {
        .compatible = "dkmd,gfx_mipi2hdmi",
        .data = NULL,
    },
    {},
};
MODULE_DEVICE_TABLE(of, mipi2hdmi_device_match_table);

static struct platform_driver mipi2hdmi_platform_driver = {
    .probe  = mipi2hdmi_probe,
    .remove = mipi2hdmi_remove,
    .driver = {
        .name  = "gfx_mipi2hdmi",
        .owner = THIS_MODULE,
        .of_match_table = of_match_ptr(mipi2hdmi_device_match_table),
        .pm = &mipi2hdmi_pm_ops,
    }
};

static int32_t __init mipi2hdmi_init(void)
{
    int32_t ret = 0;

    dpu_pr_info("[MIPI2HDMI] +\n");

    ret = platform_driver_register(&mipi2hdmi_platform_driver);
    if (ret != 0) {
        dpu_pr_err("[MIPI2HDMI] platform_driver_register failed, ret=%d\n", ret);
        return ret;
    }

    dpu_pr_info("[MIPI2HDMI] -\n");

    return 0;
}

static void __exit mipi2hdmi_exit(void)
{
    dpu_pr_info("[MIPI2HDMI] +\n");

    platform_driver_unregister(&mipi2hdmi_platform_driver);

    dpu_pr_info("[MIPI2HDMI] -\n");
}

module_init(mipi2hdmi_init);
module_exit(mipi2hdmi_exit);

MODULE_AUTHOR("Graphics Display");
MODULE_DESCRIPTION("MIPI2HDMI Module Driver");
MODULE_LICENSE("GPL");