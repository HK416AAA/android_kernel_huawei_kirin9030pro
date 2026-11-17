/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
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

#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/syscore_ops.h>
#include <linux/miscdevice.h>
#include <securec.h>
#include <linux/sort.h>
#include <linux/hrtimer.h>
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif
#ifdef CONFIG_DFX_ZEROHUNG
#include <platform/trace/hooks/zerohung.h>
#endif
#ifdef CONFIG_POWER_DUBAI
#include <huawei_platform/power/dubai/dubai_wakeup_stats.h>
#endif
#include "dkmd_dp_interface.h"
#include "edp_panel_drv.h"
#include "edp_log.h"
#include "edp_sysfs/edp_sysfs_common.h"
#include "edp_ts_kit/edp_ts_kit.h"
#include "huawei_platform/ospm/echub/lid/echub_lid.h"
#include "edp_msr/edp_comp_msr.h"
#include "tcon_uart/tcon_uart.h"

#define MAX_DPTX_DEV_INDEX 6 // support six dptx max
#define EDP_IOCTL_MAGIC 'L'
#define DISPLAY_ENGINE_GET_PARAM _IOW \
	(EDP_IOCTL_MAGIC, EDP_IOCTL_DISPLAY_ENGINE_PARAM_GET, struct display_engine_param)
#define DISPLAY_ENGINE_SET_PARAM _IOW \
	(EDP_IOCTL_MAGIC, EDP_IOCTL_DISPLAY_ENGINE_PARAM_SET, struct display_engine_param)
enum {
	EDP_IOCTL_DISPLAY_ENGINE_PARAM_GET = 0x20,
	EDP_IOCTL_DISPLAY_ENGINE_PARAM_SET,
};
#define PM_STATE_SUSPEND_MEM 	(0x1)
#define PM_STATE_SUSPEND_DISK 	(0x2)
#define ESD_DELAY_MS 800
#define EDP_DEFAULT_FPS 60

static struct edp_drv_info g_edp_info;
static struct panel_refresh_statistic_rslt g_stat_rslt;
static struct edp_comp_msr_ctrl g_msr_ctrl = {0};
static struct edp_tp_safe g_edp_tp_safe = {0};
static int g_edp_pm_suspend_state = 0x0;
static bool g_esd_delay_state = true;
static struct hrtimer g_esd_hrtimer;
static struct tcon_uart g_tcon_uart = {0};

#ifdef CONFIG_HISYSEVENT
static void edp_lcd_hiview_hisysevent(const char *domain, const char *casename, int level, const char *value)
{
	struct hiview_hisysevent *event = NULL;
	int ret;

	event = hisysevent_create(domain, casename, BEHAVIOR);
	if (!event) {
		edp_err("failed to create event\n");
		return;
	}

	if (value == NULL)
		ret = hisysevent_put_integer(event, "MODULE", level);
	else
		ret = hisysevent_put_string(event, "MODULE", value);

	if (ret != 0) {
		edp_err("failed to put value to event, ret=%d\n", ret);
		goto hisysevent_end;
	}

	ret = hisysevent_write(event);
	if (ret < 0)
		edp_err("edp_lcd_hiview_hisysevent fail, %s\n", casename);

hisysevent_end:
	hisysevent_destroy(&event);
}
#endif

static int edp_notify_ts_kit_pm_type(enum lcd_kit_ts_pm_type pm_type, int sync)
{
	struct edp_ts_kit_ops *ts_ops = NULL;

	edp_info("edp notify pm_type = %d, sync = %d\n", pm_type, sync);
	ts_ops = edp_ts_kit_get_ops();
	if (!ts_ops || !ts_ops->edp_ts_power_notify) {
		edp_err("ts_ops or edp_ts_power_notify is null\n");
		return -EINVAL;
	}

	return ts_ops->edp_ts_power_notify(pm_type, sync);
}

static void edp_prepare_enable(void)
{
	if (g_edp_info.power_status == EDP_POWER_OFF || g_edp_info.power_status == EDP_POWER_NONE)
		g_edp_info.power_status = EDP_POWER_ON_SEQ;
	edp_debug("[eDP] power_status=%d\n", g_edp_info.power_status);
}

static void edp_prepare_disable(void)
{
	if (g_edp_info.power_status == EDP_POWER_ON || g_edp_info.power_status == EDP_POWER_NONE)
		g_edp_info.power_status = EDP_BKL_OFF_SEQ;
	edp_debug("[eDP] power_status=%d\n", g_edp_info.power_status);
}

bool edp_get_panel_on_state(void)
{
	return (g_edp_info.power_status == EDP_POWER_ON);
}

uint32_t get_edp_port_id(void)
{
	return g_edp_info.port_id;
}

struct edp_drv_info* get_edp_drv_info(void)
{
    return &g_edp_info;
}

uint32_t get_edp_afr_support_mode(void)
{
	return g_edp_info.afr_support;
}

int32_t get_edp_tp_support_mode(struct edp_tp_safe *tp_safe)
{
	if (tp_safe == NULL) {
		edp_err("edp_tp_safe is NULL!\n");
		return 0;
	}

	if (g_edp_tp_safe.tp_support == 0) {
        tp_safe->tp_support = false;
		edp_err("edp not tp support!\n");
		return 0;
	}

	tp_safe->tp_support = g_edp_tp_safe.tp_support;
	tp_safe->tp_safe_frame_rate = g_edp_tp_safe.tp_safe_frame_rate;
	tp_safe->tp_release_sfr_delay_time = g_edp_tp_safe.tp_release_sfr_delay_time;

	return 1;
}

int32_t edp_set_display_active_region(struct dkmd_rect_coord *region)
{
    int32_t ret = 0;
	struct edp_rect_coord display_region = { 0 };

    if (g_msr_ctrl.is_multi_screen_support == 0) {
        edp_info("[msr] multi screen region not support\n");
        return -EINVAL;
    }

	if (region == NULL) {
        edp_err("[msr] region is NULL\n");
        return -EINVAL;
    }

	display_region.left = region->left;
	display_region.top = region->top;
	display_region.right = region->right;
	display_region.bottom = region->bottom;

    if (g_msr_ctrl.set_display_active_region != NULL &&
        g_msr_ctrl.set_display_active_region(&g_msr_ctrl, &display_region) != 0) {
        edp_err("[msr] set_display_active_region failed\n");
        return -1;
    }

    return ret;
}

static void edp_msr_power_state_save(bool is_power_on)
{
	if (g_msr_ctrl.is_multi_screen_support == 0) {
        edp_info("[msr] multi screen not support\n");
        return;
    }

	if (g_msr_ctrl.preprocess == NULL ||
		g_msr_ctrl.set_display_active_region == NULL) {
		edp_err("[msr] preprocess or set_display_active_region is NULL\n");
		return;
	}

    mutex_lock(&g_msr_ctrl.msr_lock);
    edp_print_msr_ctrl_info(&g_msr_ctrl);
    g_msr_ctrl.is_power_on = is_power_on;
    edp_print_msr_ctrl_info(&g_msr_ctrl);

    if (!is_power_on) {
		edp_err("[msr] not power on\n");
		goto err_out;
    }

    if (g_msr_ctrl.preprocess(&g_msr_ctrl) != 0) {
		edp_err("[msr] preprocess failed\n");
		goto err_out;
    }

    if (g_msr_ctrl.is_msr &&
		g_msr_ctrl.set_display_active_region(&g_msr_ctrl, &g_msr_ctrl.display_region) != 0) {
        edp_err("[msr] set_display_active_region failed\n");
    }

err_out:
    mutex_unlock(&g_msr_ctrl.msr_lock);
	return;
}

static void edp_pevent_handle(struct edp_seq *pevent, bool power_status)
{
	int i;
	int ret = 0;

	for (i = 0; i < pevent->num; i++) {
		if (pevent->ctls[i].gpio_num < 0) 
		    continue;
		if (pevent->ctls[i].gpio_num == 0) {
			if (pevent->ctls[i].delayms > 0) {
				edp_info("delayms=%u\n", pevent->ctls[i].delayms);
				mdelay(pevent->ctls[i].delayms);
			}
			continue;
		}
		if (pevent->ctls[i].value != 0)
			edp_info("power on gpio=%u, value=%u\n",
				pevent->ctls[i].gpio_num, pevent->ctls[i].value);
		else
			edp_info("power off gpio=%u, value=%u\n",
				pevent->ctls[i].gpio_num, pevent->ctls[i].value);
		if (power_status) {
			ret = gpio_request(pevent->ctls[i].gpio_num, NULL);
			if (ret) {
				edp_err("gpio request fail %d\n", ret);
				return;
			}
		}
		gpio_set_value(pevent->ctls[i].gpio_num, pevent->ctls[i].value);
		if (!power_status)
			gpio_free(pevent->ctls[i].gpio_num);
		if (pevent->ctls[i].delayms > 0) {
			edp_info("delayms=%u\n", pevent->ctls[i].delayms);
			mdelay(pevent->ctls[i].delayms);
		}
	}
}

static int edp_on(void)
{
	struct edp_seq *pevent = NULL;
	int rc;
	edp_debug("+\n");
	edp_prepare_enable();

	switch (g_edp_info.power_status) {
		case EDP_POWER_ON_SEQ:
			edp_info("edp power on start\n");
			g_esd_delay_state = true;
			if (g_esd_hrtimer.state != HRTIMER_STATE_INACTIVE) {
				edp_info("g_esd_hrtimer is working , now killed!");
				hrtimer_cancel(&g_esd_hrtimer);
			}
			/**
			Use 1000 to separate the integer part and the ms part of ESD_DELAY_MS,
			use 1000000 to represent the ms part in ns, to improve precision.
			**/
			hrtimer_start(&g_esd_hrtimer, ktime_set(ESD_DELAY_MS / 1000,
				(ESD_DELAY_MS % 1000) * 1000000), HRTIMER_MODE_REL);
			rc = edp_notify_ts_kit_pm_type(TS_RESUME_DEVICE, SHORT_SYNC);
			if (rc)
				edp_err("edp notify resume type fail\n");
			if (!g_edp_info.power_on) {
				edp_err("power_on is NULL!\n");
				return -EINVAL;
			}
			pevent = g_edp_info.power_on;
			g_edp_info.power_status = EDP_BKL_ON_SEQ;
			edp_msr_power_state_save(true);
#ifdef CONFIG_HISYSEVENT
	        edp_lcd_hiview_hisysevent("LCD", "LCD_POWER_ON", 0, "edp");
#endif
			break;
		case EDP_BKL_ON_SEQ:
			edp_info("edp bkl on start\n");
			rc = edp_notify_ts_kit_pm_type(TS_AFTER_RESUME, SHORT_SYNC);
			if (rc)
				edp_err("edp notify after resume type fail\n");
			if (!g_edp_info.bkl_on) {
				edp_err("bkl_on is NULL!\n");
				return -EINVAL;
			}
			pevent = g_edp_info.bkl_on;
			g_edp_info.power_status = EDP_POWER_ON;
			break;
		default:
			edp_info("edp on mode error\n");
			return -EINVAL;
	}
	edp_pevent_handle(pevent, true);

	return 0;
}
 
static int edp_off(void)
{
	struct edp_seq *pevent = NULL;
	int rc;
	edp_debug("+\n");
	edp_prepare_disable();

	switch (g_edp_info.power_status) {
		case EDP_BKL_OFF_SEQ:
			edp_info("edp bkl off start\n");
			if (!g_edp_info.bkl_off) {
				edp_err("bkl_off is NULL!\n");
				return -EINVAL;
			}
			pevent = g_edp_info.bkl_off;
			g_edp_info.power_status = EDP_POWER_OFF_SEQ;
			rc = edp_notify_ts_kit_pm_type(TS_EARLY_SUSPEND, SHORT_SYNC);
			if (rc)
				edp_err("edp notify early suspend type fail\n");
			edp_msr_power_state_save(false);
			break;
		case EDP_POWER_OFF_SEQ:
			edp_info("edp power off start\n");
			if (!g_edp_info.power_off) {
				edp_err("power_off is NULL!\n");
				return -EINVAL;
			}
			pevent = g_edp_info.power_off;
			g_edp_info.power_status = EDP_POWER_OFF;
#ifdef CONFIG_HISYSEVENT
	        edp_lcd_hiview_hisysevent("LCD", "LCD_POWER_OFF", 0, "edp");
#endif
			rc = edp_notify_ts_kit_pm_type(TS_BEFORE_SUSPEND, SHORT_SYNC);
			if (rc)
				edp_err("edp notify before suspend type fail\n");
			rc = edp_notify_ts_kit_pm_type(TS_SUSPEND_DEVICE, SHORT_SYNC);
			if (rc)
				edp_err("edp notify suspend type fail\n");
			break;
		default:
			edp_info("edp off mode error\n");
			return -EINVAL;
	}
	edp_pevent_handle(pevent, false);

	return 0;
}

static void edp_set_backlight(int port_id, uint32_t bl_level)
{
    aux_set_backlight(port_id, bl_level);

#ifdef CONFIG_DFX_ZEROHUNG
	trace_hck_hung_wp_screen_setbl(bl_level);
#endif

	if (g_edp_info.jank_last_bl_level == 0 && bl_level != 0) {
#ifdef CONFIG_HISYSEVENT
		edp_lcd_hiview_hisysevent("LCD", "LCD_BACKLIGHT_ON", (int)bl_level, NULL);
#endif
		g_edp_info.jank_last_bl_level = bl_level;
	} else if (g_edp_info.jank_last_bl_level !=0 && bl_level == 0) {
#ifdef CONFIG_HISYSEVENT
		edp_lcd_hiview_hisysevent("LCD", "LCD_BACKLIGHT_OFF", (int)bl_level, NULL);
#endif
		g_edp_info.jank_last_bl_level = bl_level;
	}
	return;
}

static int edp_notify_sfr_info(const struct sfr_info *sfr_info)
{
	g_edp_info.current_fps = sfr_info->afr;
	return display_engine_update_frame_rate(sfr_info);
}

static int32_t edp_get_gpio_value(u32 gpio_num, const char *gpio_name)
{
	int32_t gpio_value;
	int32_t ret;
 
	ret = gpio_request(gpio_num, gpio_name);
	if (ret != 0) {
		edp_err("esd_detect_gpio[%u] request fail!\n", gpio_num);
		return -EINVAL;
	}
	ret = gpio_direction_input(gpio_num);
	if (ret != 0) {
		gpio_free(gpio_num);
		edp_err("esd_detect_gpio[%u] direction set fail!\n", gpio_num);
		return -EINVAL;
	}
	gpio_value = gpio_get_value(gpio_num);
	gpio_free(gpio_num);
 
	edp_info("gpio_num:%u value:%u\n", gpio_num, gpio_value);
	return gpio_value;
}

static int edp_gpio_detect_event(void)
{
	int i;
	uint32_t gpio_detect_value;

	for (i = 0; i < GPIO_CHECK_TIMES; i++) {
		gpio_detect_value = (uint32_t)edp_get_gpio_value(g_edp_info.esd.gpio_detect_num, "esd_detect_gpio");
		if (gpio_detect_value == g_edp_info.esd.gpio_normal_value)
			break;
		return -EFAULT;
	}
	return 0;
}

static int edp_esd_handle(void)
{
    if (g_edp_info.esd.enable) {
        if (g_esd_delay_state) {
			edp_info("power-on protection for ESD, delay %dms", ESD_DELAY_MS);
            msleep(ESD_DELAY_MS);
            g_esd_delay_state = false;
        }
        return edp_gpio_detect_event();
    }

    return 0;
}

static struct panel_refresh_statistic_rslt *get_refresh_statistic_data(int port_id) {
	if (port_id == g_edp_info.port_id)
		return &g_stat_rslt;
	else
		return NULL;
}

static struct dp_panel_mgr g_panel_mgr = {
    .panel_power_pre_on = edp_on,
    .panel_power_after_on = edp_on,
    .panel_power_pre_off = edp_off,
    .panel_power_after_off = edp_off,
    .panel_power_set_backlight = edp_set_backlight,
	.esd_handle = edp_esd_handle,
	.panel_get_refresh_statistic_data = get_refresh_statistic_data,
	.notify_sfr_info = edp_notify_sfr_info,
	.panel_set_display_active_region = edp_set_display_active_region,
};

struct edp_tp_safe_rate_ops g_edp_ops = {
	.send_de_event = tp_notify_display_engine,
};

static int conver2le(uint32_t *src, uint32_t *desc, int len)
{
	int i;
	uint32_t temp;

	if ((src == NULL) || (desc == NULL)) {
		edp_err("src or desc is null\n");
		return -EINVAL;
	}
	for (i = 0; i < len; i++) {
		temp = ((src[i] & 0xff) << 24);
		temp |= (((src[i] >> 8) & 0xff) << 16);
		temp |= (((src[i] >> 16) & 0xff) << 8);
		temp |= ((src[i] >> 24) & 0xff);
		desc[i] = temp;
		temp = 0;
	}
	return 0;
}

static int edp_parse_array_data(const struct device_node *np, const char *name,
	struct edp_array_data *out)
{
	int blen = 0;
	uint32_t *data = NULL;
	uint32_t *buf = NULL;

	data = (uint32_t *)of_get_property(np, name, &blen);
	if (!data) {
		edp_err("get data fail\n");
		return -EINVAL;
	}
	blen = blen / 4; // 4 means u32 divide u8
	if (blen <= 0) {
		edp_err("blen is error\n");
		return -EINVAL;
	}
	buf = kzalloc(blen * sizeof(uint32_t), GFP_KERNEL);
	if (!buf) {
		edp_err("alloc buf fail\n");
		return -ENOMEM;
	}
	if (memcpy_s(buf, blen * sizeof(uint32_t), data, blen * sizeof(uint32_t)) != EOK) {
		kfree(buf);
		buf = NULL;
		edp_err("memcpy_s data fail\n");
		return -EINVAL;
	}
	conver2le(buf, buf, blen);
	out->buf = buf;
	out->cnt = blen;
	return 0;
}

static int edp_get_prop_of_u32_array(struct device_node *np,
	const char *propname, uint32_t **value, int *num)
{
	uint32_t *array = NULL;
	int ret;
	int count = 0;

	if ((np == NULL) || (propname == NULL) || (value == NULL) ||
		(num == NULL)) {
		edp_err("invalid argument\n");
		return -EINVAL;
	}

	if (of_property_read_bool(np, propname))
		count = of_property_count_elems_of_size(np,
			propname, (int)sizeof(uint32_t));
 
	if (count == 0) {
		edp_debug("%s not existed, skip\n", propname);
		return 0;
	}

	array = kzalloc(sizeof(uint32_t) * count, GFP_KERNEL);
	if (array == NULL)
		return -ENOMEM;
 
	ret = of_property_read_u32_array(np, propname, array,
		(size_t)(long)count);
	if (ret < 0) {
		edp_err("get %s array failed\n", propname);
		ret = -EFAULT;
		goto err_out;
	}
 
	*value = array;
	*num = count;
	edp_info("edp_get_prop_of_u32_array count=%d\n", count);
	return 0;
 
err_out:
	kfree(array);
	return ret;
}

static int parse_edp_lcd_seq(struct device_node *np, const char *ctl_str, struct edp_seq **ctl_seq)
{
	struct edp_seq *seq = NULL;
	int count = 0;
	int val_num;
	int ret;
 
	edp_info("+\n");
	if ((np == NULL) || (ctl_str == NULL)) {
		edp_err("invalid argument\n");
		return -EINVAL;
	}

	if (!of_property_read_bool(np, ctl_str)) {
		edp_warn("%s not existed, skip\n", ctl_str);
		return -EINVAL;
	}

	seq = kzalloc(sizeof(*seq), GFP_KERNEL);
	if (seq == NULL)
		return -ENOMEM;

	ret = edp_get_prop_of_u32_array(np, ctl_str,
		(uint32_t **)&seq->ctls, &count);
	if ((count <= 0) || (ret < 0)) {
		edp_err("get %s failed or count is 0\n", ctl_str);
		ret = -EFAULT;
		goto err_out;
	}

	val_num = sizeof(struct edp_ctl) / sizeof(uint32_t);
	if ((count % val_num) != 0) {
		edp_err("count %d %% val_num %d != 0\n",
			count, val_num);
		ret = -EFAULT;
		goto err_out;
	}

	seq->num = (int8_t)(count / val_num);
	*ctl_seq = seq;
	edp_info("parse_edp_lcd_seq num=%d\n", seq->num);
	return 0;

err_out:
	kfree(seq);
	return ret;
}

static void edp_panel_parse_bl_info(struct device_node *np)
{
	int ret;

    ret = of_property_read_u32(np, "bl_max", &g_edp_info.bl_max);
    if (ret < 0) {
		edp_err("parse max_backlight failed\n");
		g_edp_info.bl_max = 0;
	}

    ret = of_property_read_u32(np, "bl_min", &g_edp_info.bl_min);
    if (ret < 0) {
		edp_err("parse min_backlight failed\n");
		g_edp_info.bl_min = 0;
	}

    ret = of_property_read_u32(np, "max_luminance", &g_edp_info.maxluminance);
    if (ret < 0) {
		edp_err("parse maxluminance failed\n");
		g_edp_info.maxluminance = 0;
	}

    ret = of_property_read_u32(np, "min_luminance", &g_edp_info.minluminance);
    if (ret < 0) {
		edp_err("parse min_luminance failed\n");
		g_edp_info.minluminance = 0;
	}
}

static void edp_panel_parse_early_power_on_info(struct device_node *np)
{
	int len;
	int ret;

	g_edp_info.early_power_on_support = false;
	if (memset_s(g_edp_info.early_power_on_gpio_filter, EARLY_POWER_ON_FILGER_MAX, 0x0, EARLY_POWER_ON_FILGER_MAX)) {
		edp_err("memset_s failed\n");
		return;
	}
	
	if (of_property_read_bool(np, "early_power_on_support")) {
		g_edp_info.early_power_on_support = true;
		len = of_property_count_u32_elems(np, "early_power_on_gpio_filter");
		if (len <= 0 || len > EARLY_POWER_ON_FILGER_MAX) {
			edp_err("edp early_power_on_gpio_filter is invalid\n");
			return;
		}

		ret = of_property_read_u32_array(np, "early_power_on_gpio_filter", g_edp_info.early_power_on_gpio_filter, len);
		if (ret)
			edp_err("edp get early_power_on_gpio_filter failed\n");
	}
}

static void edp_panel_parse_s4_power_off_info(struct device_node *np)
{
	int ret;
	g_edp_info.s4_power_off_list.support = false;
	g_edp_info.s4_power_off_list.gpio_bkl = 0;
	g_edp_info.s4_power_off_list.gpio_vdd = 0;
	
	if (of_property_read_bool(np, "s4_power_off_support")) {
		ret = of_property_read_u32(np, "s4_power_off_gpio_bkl", &g_edp_info.s4_power_off_list.gpio_bkl);
		if (ret < 0) {
			edp_err("s4_power_off_list.gpio_bkl is not found\n");
			return;
		}
		ret = of_property_read_u32(np, "s4_power_off_gpio_vdd", &g_edp_info.s4_power_off_list.gpio_vdd);
		if (ret < 0) {
			edp_err("s4_power_off_list.gpio_vdd is not found\n");
			return;
		}
		g_edp_info.s4_power_off_list.support = true;
	}
}

static void edp_panel_parse_tp_safe_frm_rate_info(struct device_node *np)
{
	int ret = 0;

	ret = of_property_read_u32(np, "tp_support", &g_edp_tp_safe.tp_support);
	if (ret < 0) {
		edp_err("parse tp_support failed\n");
		g_edp_tp_safe.tp_support = 0;
		return;
	}

	ret = of_property_read_u32(np, "tp_release_sfr_delay_time", &g_edp_tp_safe.tp_release_sfr_delay_time);
	if (ret < 0)
		edp_err("parse tp_release_sfr_delay_time failed\n");

	ret = of_property_read_u32(np, "tp_safe_frame_rate", &g_edp_tp_safe.tp_safe_frame_rate);
	if (ret < 0)
		edp_err("parse tp_safe_frame_rate failed\n");
}

static bool edp_panel_parse_base_info(struct device_node *np)
{
	int ret;

    ret = of_property_read_u32(np, "port_id", &g_edp_info.port_id);
    if (ret < 0 || g_edp_info.port_id >= MAX_DPTX_DEV_INDEX) {
		edp_err("parse port_id failed\n");
		return false;
	}

	ret = of_property_read_u32(np, "afr_support", &g_edp_info.afr_support);
	if (ret < 0) {
		edp_err("parse afr_support failed\n");
		g_edp_info.afr_support = 0;
	}

	ret = parse_edp_lcd_seq(np, "power_on", &g_edp_info.power_on);
	if (ret < 0) {
		edp_err("parse power_on failed\n");
		g_edp_info.power_on = NULL;
	}

	ret = parse_edp_lcd_seq(np, "power_off", &g_edp_info.power_off);
	if (ret < 0) {
		edp_err("parse power_off failed\n");
		g_edp_info.power_off = NULL;
	}

	ret = parse_edp_lcd_seq(np, "bkl_on", &g_edp_info.bkl_on);
	if (ret < 0) {
		edp_err("parse power_off failed\n");
		g_edp_info.bkl_on = NULL;
	}

	ret = parse_edp_lcd_seq(np, "bkl_off", &g_edp_info.bkl_off);
	if (ret < 0) {
		edp_err("parse bkl_off failed\n");
		g_edp_info.bkl_off = NULL;
	}

	ret = of_property_read_u8(np, "adjust_htotal", &g_panel_mgr.adjust_htotal);
	if (ret < 0) {
		edp_err("pasre adjust htotal failed\n");
		g_panel_mgr.adjust_htotal = 0;
	}

	edp_panel_parse_early_power_on_info(np);
	edp_info("edp panel info: esd_support=%d, port_id = %d\n",\
		g_panel_mgr.esd_is_support, g_edp_info.port_id);
	return true;
}

static int cmp_u32(const void *a, const void *b)
{
	if (*(const uint32_t *)a < *(const uint32_t *)b)
		return 1;
	else if (*(const uint32_t *)a > *(const uint32_t *)b)
		return -1;
	else
		return 0;
}

static void sort_fps_list(void)
{
	unsigned int i;

	sort(g_panel_mgr.dfr_info.oled_info.fps_sup_seq, g_panel_mgr.dfr_info.oled_info.fps_sup_num,
		sizeof(uint32_t), cmp_u32, NULL);
	for (i = 0; i < g_panel_mgr.dfr_info.oled_info.fps_sup_num; i++)
		edp_info("g_panel_mgr.dfr_info.oled_info.fps_sup_seq[%d] is %d\n", i, g_panel_mgr.dfr_info.oled_info.fps_sup_seq[i]);
}

static void parse_ltps_safe_cmd(struct device_node *np)
{
	int i;
	int ret = 0;
	struct edp_array_data safe_freq = {0};

	ret = edp_parse_array_data(np, "safe_frame_info", &safe_freq);
	if (ret != 0) {
		edp_err("parse safe frame info fail");
		return;
	}

	g_panel_mgr.dfr_info.oled_info.ltps_info.safe_frm_rates_num = safe_freq.cnt;
	if (safe_freq.cnt > SAFE_FRM_RATE_MAX_NUM_LTPS) {
		edp_err("safe_freq.cnt is %d too big!\n", safe_freq.cnt);
		kfree(safe_freq.buf);
		return;
	}
	edp_info("safe_freq.cnt is %d!\n", safe_freq.cnt);

	for (i = 0; i < safe_freq.cnt; i++) {
		g_panel_mgr.dfr_info.oled_info.ltps_info.safe_frm_rates[i].safe_frm_rate = safe_freq.buf[i];
		edp_info("safe_freq.buf[%d] is %d!\n", i, safe_freq.buf[i]);
	}
	kfree(safe_freq.buf);
}

static int parse_ltpo_te_info(struct device_node *np)
{
	struct edp_array_data te_freq = {0};
	struct edp_array_data te_mask = {0};
	int i;
	int ret;

	ret = edp_parse_array_data(np, "te_freqs", &te_freq);
	if (ret != 0)
		 return -EFAULT;

	ret = edp_parse_array_data(np, "te_masks", &te_mask);
	if (ret != 0) {
		kfree(te_freq.buf);
		return -EFAULT;
	}
	edp_info("te_freq.cnt is %d, te_mask.cnt is %d!\n", te_freq.cnt, te_mask.cnt);
	if (te_freq.cnt > TE_FREQ_NUM_MAX || te_mask.cnt > TE_FREQ_NUM_MAX || te_freq.cnt != te_mask.cnt) {
		edp_err("te cnt para config error!\n");
		kfree(te_freq.buf);
		kfree(te_mask.buf);
		return -EFAULT;
	}
	g_panel_mgr.dfr_info.oled_info.ltpo_info.te_freq_num = te_freq.cnt;
	g_panel_mgr.dfr_info.oled_info.ltpo_info.te_mask_num = te_mask.cnt;
	for (i = 0; i < te_freq.cnt; i++) {
		g_panel_mgr.dfr_info.oled_info.ltpo_info.te_freqs[i] = te_freq.buf[i];
		g_panel_mgr.dfr_info.oled_info.ltpo_info.te_masks[i] = te_mask.buf[i];
		edp_info("te_freq.buf[%d] is %u!\n", i, te_freq.buf[i]);
		edp_info("te_mask.buf[%d] is %u!\n", i, te_mask.buf[i]);
	}
	kfree(te_freq.buf);
	kfree(te_mask.buf);
	return 0;
}

/* LTPO 120hz dimming seq */
static void parse_ltpo_120hz_dimming_seq(struct device_node *np)
{
	struct edp_array_data dimming_seq = {0};
	struct edp_array_data repeat_num = {0};
	int i;
	int ret;

    ret = edp_parse_array_data(np, "dimming_seq", &dimming_seq);
    if (ret != 0)
        return;
 
    ret = edp_parse_array_data(np, "repeat_num", &repeat_num);
    if (ret != 0) {
        kfree(dimming_seq.buf);
		dimming_seq.buf = NULL;
        return;
    }

    if (dimming_seq.cnt != repeat_num.cnt) {
        edp_err("dimming cnt para config error!\n");
        goto free_memory;
    }

	g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].dimming_seq_num = dimming_seq.cnt;
	for (i = 0; i < dimming_seq.cnt; i++) {
        g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX]
            .dimming_seq_list[i].frm_rate = dimming_seq.buf[i];
        g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX]
            .dimming_seq_list[i].repeat_num = repeat_num.buf[i];
        edp_info("120hz frm_rate[%d] is %u, repeat_num[%d] is %u!\n", i, dimming_seq.buf[i], i, repeat_num.buf[i]);
	}
	g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].type = DIMMING_SEQ_120HZ_INDEX;

free_memory:
    kfree(dimming_seq.buf);
	dimming_seq.buf = NULL;
    kfree(repeat_num.buf);
	repeat_num.buf = NULL;
}

/* LTPO 90hz dimming seq */
static void parse_ltpo_90hz_dimming_seq(struct device_node *np)
{
    struct edp_array_data dimming_seq = {0};
    struct edp_array_data repeat_num = {0};
    int i;
    int ret;

    ret = edp_parse_array_data(np, "90hz_dimming_seq", &dimming_seq);
    if (ret != 0)
        return;
 
    ret = edp_parse_array_data(np, "90hz_repeat_num", &repeat_num);
    if (ret != 0) {
        kfree(dimming_seq.buf);
		dimming_seq.buf = NULL;
        return;
    }
 
    if (dimming_seq.cnt != repeat_num.cnt) {
        edp_err("dimming cnt para config error!\n");
        goto free_memory;
    }

    g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX].dimming_seq_num = dimming_seq.cnt;
    for (i = 0; i < dimming_seq.cnt; i++) {
        g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX]
		    .dimming_seq_list[i].frm_rate = dimming_seq.buf[i];
        g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX]
            .dimming_seq_list[i].repeat_num = repeat_num.buf[i];
        edp_info("90hz frm_rate[%d] is %u, repeat_num[%d] is %u!\n", i, dimming_seq.buf[i], i, repeat_num.buf[i]);
    }
    g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX].type = DIMMING_SEQ_90HZ_INDEX;

free_memory:
    kfree(dimming_seq.buf);
	dimming_seq.buf = NULL;
    kfree(repeat_num.buf);
	repeat_num.buf = NULL;
}

static void parse_ltpo1_info(struct device_node *np)
{
	int ret;
 
	ret = parse_ltpo_te_info(np);
	if (ret != 0)
		return;
	parse_ltps_safe_cmd(np);
	parse_ltpo_120hz_dimming_seq(np);
	parse_ltpo_90hz_dimming_seq(np);
}

static int parse_ltps_te_info(struct device_node *np)
{
	struct edp_array_data te_freq = {0};
	int i;
	int ret;

	ret = edp_parse_array_data(np, "te_freqs", &te_freq);
	if (ret != 0)
		 return -EFAULT;

	edp_info("te_freq.cnt is %d\n", te_freq.cnt);
	if (te_freq.cnt > TE_FREQ_NUM_MAX_LTPS) {
		edp_err("te cnt para config error!\n");
		kfree(te_freq.buf);
		return -EFAULT;
	}
	g_panel_mgr.dfr_info.oled_info.ltps_info.te_freq_num = te_freq.cnt;
	for (i = 0; i < te_freq.cnt; i++) {
		g_panel_mgr.dfr_info.oled_info.ltps_info.te_freqs[i] = te_freq.buf[i];
		edp_info("te_freq.buf[%d] is %u!\n", i, te_freq.buf[i]);
	}
	kfree(te_freq.buf);
	return 0;
}

static void parse_ltps_info(struct device_node *np)
{
	int ret;

	ret = parse_ltps_te_info(np);
	if (ret != 0)
		return;
	parse_ltps_safe_cmd(np);
}

static void parse_ltpo_info(struct device_node *np)
{
	of_property_read_u32(np, "ltpo_ver", &g_panel_mgr.dfr_info.oled_info.ltpo_info.ver);
	of_property_read_u32(np, "dimming_mode", &g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_mode);
#ifdef EDP_FACTORY_MODE
	g_panel_mgr.dfr_info.dfr_mode = 0;
	g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_enable = 0;
#else
	g_panel_mgr.dfr_info.oled_info.ltpo_info.dimming_enable = 1;
#endif
	of_property_read_u32(np, "ddic_type", &g_panel_mgr.dfr_info.ddic_type);
	sort_fps_list();
	if (g_panel_mgr.dfr_info.oled_info.ltpo_info.ver == LTPO_V1)
		parse_ltpo1_info(np);
}

static void copy_fps_list_to_edp_info()
{
	int i;
	if (g_panel_mgr.dfr_info.oled_info.fps_sup_num > FPS_LEVEL_MAX) {
		edp_err("fps_sup_num error\n");
		return;
	}
	for (i = 0; i < g_panel_mgr.dfr_info.oled_info.fps_sup_num; i++)
		g_edp_info.fps_list.fps_list[i] = g_panel_mgr.dfr_info.oled_info.fps_sup_seq[i];
	g_edp_info.fps_list.fps_list_num = g_panel_mgr.dfr_info.oled_info.fps_sup_num;
}

static void edp_panel_parse_fps_info(struct device_node *np) {
	int i;
	int ret;
	struct edp_array_data fps_suppend = {0};

	ret = of_property_read_u8(np, "fps_support", &g_panel_mgr.fps_support);
	if (ret < 0 || !g_panel_mgr.fps_support) {
		edp_err("not support fps\n");
		goto err_out;
	}
	ret = of_property_read_u32(np, "te_gpio", &g_panel_mgr.te_from_tcon_gpio);
	if (ret < 0 || g_panel_mgr.te_from_tcon_gpio == 0) {
		edp_err("get te_gpio failed!\n");
		goto err_out;
	}
	edp_info("get te_from_tcon_gpio = %d\n", g_panel_mgr.te_from_tcon_gpio);
	ret = of_property_read_u32(np, "dfr_mode", &g_panel_mgr.dfr_info.dfr_mode);
	if (ret < 0) {
		edp_err("dfr_mode is not found\n");
		goto err_out;
	}
	ret = of_property_read_u32(np, "oled_type", &g_panel_mgr.dfr_info.oled_info.oled_type);
	if (ret < 0) {
		edp_err("oled_type is not found\n");
		goto err_out;
	}
	g_edp_info.oled_type = g_panel_mgr.dfr_info.oled_info.oled_type;
	ret = edp_parse_array_data(np, "fps_sup_seq", &fps_suppend);
	if (ret < 0) {
		edp_err("fps_sup_seq is not found\n");
		goto err_out;
	}
	g_panel_mgr.dfr_info.oled_info.fps_sup_num = fps_suppend.cnt;
    if (fps_suppend.cnt > FPS_LEVEL_MAX) {
        edp_err("fps_suppend.cnt is out of range, cnt = %d\n", fps_suppend.cnt);
		kfree(fps_suppend.buf);
        goto err_out;
    }
	for (i = 0; i < fps_suppend.cnt && fps_suppend.buf != NULL; i++) {
		g_panel_mgr.dfr_info.oled_info.fps_sup_seq[i] = fps_suppend.buf[i];
		edp_info("fps_sup_seq[%d] = %u\n", i, fps_suppend.buf[i]);
	}
	kfree(fps_suppend.buf);

	if (g_panel_mgr.dfr_info.oled_info.oled_type == LTPS)
		parse_ltps_info(np);
	if (g_panel_mgr.dfr_info.oled_info.oled_type == LTPO)
		parse_ltpo_info(np);
	edp_info("parse fps info success!\n");
	return;

err_out:
	g_panel_mgr.fps_support = 0;
	return;
}

static void edp_panel_parse_safe_margin_info(struct device_node *np)
{
	int ret;
	ret = of_property_read_u32(np, "vactive2te_safe_margin", &g_panel_mgr.safe_margin_info.vactive2te_safe_margin);
	if (ret < 0) {
		edp_err("vactive2te_safe_margin is not found\n");
		g_panel_mgr.safe_margin_info.vactive2te_safe_margin = 0;
	}
	ret = of_property_read_u32(np, "te2te_safe_margin", &g_panel_mgr.safe_margin_info.te2te_safe_margin);
	if (ret < 0) {
		edp_err("te2te_safe_margin is not found\n");
		g_panel_mgr.safe_margin_info.te2te_safe_margin = 0;
	}
}

static bool edp_panel_parse_dirty_info(const struct device_node *np, const char *prop_name,
	int *out)
{
	unsigned int value = 0xffff; // init to 0xffff, represent - 1 with 0xffff

	if (!np || !out || !prop_name) {
		edp_err("pointer is null\n");
		return false;
	}
	if (of_property_read_u32(np, prop_name, &value)) {
		edp_info("of_property_read_u32: %s not find\n", prop_name);
		*out = -1; // read device-tree fail, use default value:-1
	}
	/* device-tree can not save -1, use 0xffff to stand for -1 */
	if (value >= 0xffff)
		*out = -1;
	else
		*out = (int)value;
	return true;
}

static bool edp_panel_parse_dirty_region_info(struct device_node *np)
{
	int ret;

    ret = of_property_read_u8(np, "dirty_region_updt_support", &g_panel_mgr.dpu_pu_cfg_info.dirty_region_updt_support);
    if (ret < 0 || !g_panel_mgr.dpu_pu_cfg_info.dirty_region_updt_support) {
		g_panel_mgr.dpu_pu_cfg_info.dirty_region_updt_support = 0;
		g_edp_info.is_part_update_support = 0;
		edp_err("dirty region not support\n");
		return false;
	}
	g_edp_info.is_part_update_support = g_panel_mgr.dpu_pu_cfg_info.dirty_region_updt_support;
    ret = of_property_read_u8(np, "psr2_support", &g_panel_mgr.dpu_pu_cfg_info.psr2_support);
    if (ret < 0 || !g_panel_mgr.dpu_pu_cfg_info.psr2_support) {
		g_panel_mgr.dpu_pu_cfg_info.psr2_support = 0;
		edp_err("psr2 not support\n");
		return false;
	}

    edp_panel_parse_dirty_info(np, "left_align", &g_panel_mgr.dpu_pu_cfg_info.left_align);
    edp_panel_parse_dirty_info(np, "right_align", &g_panel_mgr.dpu_pu_cfg_info.right_align);
    edp_panel_parse_dirty_info(np, "top_align", &g_panel_mgr.dpu_pu_cfg_info.top_align);
    edp_panel_parse_dirty_info(np, "bottom_align", &g_panel_mgr.dpu_pu_cfg_info.bottom_align);
    edp_panel_parse_dirty_info(np, "w_align", &g_panel_mgr.dpu_pu_cfg_info.w_align);
    edp_panel_parse_dirty_info(np, "h_align", &g_panel_mgr.dpu_pu_cfg_info.h_align);
    edp_panel_parse_dirty_info(np, "w_min", &g_panel_mgr.dpu_pu_cfg_info.w_min);
    edp_panel_parse_dirty_info(np, "h_min", &g_panel_mgr.dpu_pu_cfg_info.h_min);
    edp_panel_parse_dirty_info(np, "bottom_start", &g_panel_mgr.dpu_pu_cfg_info.bottom_start);
    edp_panel_parse_dirty_info(np, "top_start", &g_panel_mgr.dpu_pu_cfg_info.top_start);
    edp_panel_parse_dirty_info(np, "spr_overlap", &g_panel_mgr.dpu_pu_cfg_info.spr_overlap);
    edp_panel_parse_dirty_info(np, "te_shift_limit", &g_panel_mgr.dpu_pu_cfg_info.te_shift_limit);

	return true;
}

static void edp_panel_parse_tcon_uart_info(struct device_node *np)
{
	int ret = 0;

	ret = of_property_read_u8(np, "tcon_uart_support", &g_tcon_uart.support);
	if (ret < 0) {
		edp_info("tcon_uart_enable is not found\n");
		return;
	}

	ret = of_property_read_string(np, "tty_name", &g_tcon_uart.tty_name);
	if (ret < 0) {
		g_tcon_uart.support = false;
		edp_err("tty_name is not found\n");
		return;
	}

	ret = of_property_read_u32(np, "uart_default_baud", &g_tcon_uart.default_baud);
	if (ret < 0) {
		g_tcon_uart.support = false;
		edp_err("uart_default_baud is not found\n");
		return;
	}

	return;
}

static void edp_panel_parse_esd_info(struct device_node *np)
{
	int ret;

	ret = of_property_read_u8(np, "esd_support", &g_edp_info.esd.enable);
	if (ret < 0) {
		edp_err("esd_enable is not found\n");
		g_panel_mgr.esd_is_support = 0;
		return;
	}
	g_panel_mgr.esd_is_support = g_edp_info.esd.enable;
	ret = of_property_read_u32(np, "esd_detect_gpio", &g_edp_info.esd.gpio_detect_num);
	if (ret < 0) {
		edp_err("esd_detect_gpio is not found\n");
		g_panel_mgr.esd_is_support = 0;
		return;
	}
	ret = of_property_read_u32(np, "esd_gpio_value", &g_edp_info.esd.gpio_normal_value);
	if (ret < 0) {
		edp_err("esd_detect_gpio is not found\n");
		g_panel_mgr.esd_is_support = 0;
		return;
	}
	ret = of_property_read_u32(np, "esd_recovery_max_count", &g_panel_mgr.esd_info.esd_recovery_max_count);
	if (ret < 0) {
		edp_err("esd_recovery_max_count is not found, set default value\n");
		g_panel_mgr.esd_info.esd_recovery_max_count = ESD_RECOVERY_MAX_COUNT;
	}
	ret = of_property_read_u32(np, "esd_check_max_count", &g_panel_mgr.esd_info.esd_check_max_count);
	if (ret < 0) {
		edp_err("esd_check_max_count is not found, set default value\n");
		g_panel_mgr.esd_info.esd_check_max_count = ESD_CHECK_MAX_COUNT;
	}
	ret = of_property_read_u8(np, "esd_timing_ctrl", &g_panel_mgr.esd_info.esd_timing_ctrl);
	if (ret < 0) {
		edp_err("esd_timing_ctrl is not found, set default value\n");
		g_panel_mgr.esd_info.esd_timing_ctrl = 0;
	}
	ret = of_property_read_u32(np, "esd_check_time_period", &g_panel_mgr.esd_info.esd_check_time_period);
	if (ret < 0) {
		edp_err("esd_check_time_period is not found, set default value\n");
		g_panel_mgr.esd_info.esd_check_time_period = 0;
	}
	ret = of_property_read_u32(np, "esd_first_check_delay", &g_panel_mgr.esd_info.esd_first_check_delay);
	if (ret < 0) {
		edp_err("esd_first_check_delay is not found, set default value\n");
		g_panel_mgr.esd_info.esd_first_check_delay = 0;
	}
	return;
}

static void edp_panel_parse_multi_screen(struct device_node *np)
{
	int ret;

	ret = of_property_read_u32(np, "support_multi_screen", &g_msr_ctrl.is_multi_screen_support);
	if (ret != 0 || g_msr_ctrl.is_multi_screen_support != 1) {
		edp_err("not support multi screen\n");
		g_msr_ctrl.is_multi_screen_support = 0;
		return;
	}

	ret = of_property_read_u32(np, "left_multi", &g_msr_ctrl.region.left);
	edp_info("multi screen left: %u", g_msr_ctrl.region.left);
	if (ret != 0)
		edp_warn("get left_multi failed");

	ret = of_property_read_u32(np, "top_multi", &g_msr_ctrl.region.top);
	edp_info("multi screen top: %u", g_msr_ctrl.region.top);
	if (ret != 0)
		edp_warn("get top_multi failed");

	ret = of_property_read_u32(np, "right_multi", &g_msr_ctrl.region.right);
	edp_info("multi screen right: %u", g_msr_ctrl.region.right);
	if (ret != 0)
		edp_warn("get right_multi failed");

	ret = of_property_read_u32(np, "bottom_multi", &g_msr_ctrl.region.bottom);
	edp_info("multi screen bottom: %u", g_msr_ctrl.region.bottom);
	if (ret != 0)
		edp_warn("get bottom_multi failed");
}

static void edp_panel_parse_fps_scence_info(struct device_node *np)
{
	int ret;

	ret = of_property_read_u32(np, "default_fps", &g_edp_info.default_fps);
	if (ret < 0 || !g_edp_info.default_fps) {
		g_edp_info.default_fps = EDP_DEFAULT_FPS;
		edp_info("default_fps = %d\n", g_edp_info.default_fps);
	}
	copy_fps_list_to_edp_info();
}

static bool edp_panel_info_prase_dts(struct device_node *np)
{
	int ret;

	edp_info("prase edp panel info+\n");

    ret = edp_panel_parse_base_info(np);
	if (!ret) {
		edp_err("parse base edp info failed\n");
		return false;
	}
	edp_panel_parse_bl_info(np);
	edp_panel_parse_dirty_region_info(np);
	edp_panel_parse_fps_info(np);
	edp_panel_parse_fps_scence_info(np);
	edp_panel_parse_esd_info(np);
	edp_panel_parse_multi_screen(np);
	edp_panel_parse_tp_safe_frm_rate_info(np);
	edp_panel_parse_tcon_uart_info(np);
	edp_panel_parse_safe_margin_info(np);
	edp_panel_parse_s4_power_off_info(np);
	return true;
}

static int32_t register_edp_panel(struct device_node *np)
{
	int32_t ret;

	edp_info("register edp panel+\n");

    if (!edp_panel_info_prase_dts(np)) {
        edp_err("dts config is err, can not registe!!!\n");
        return -EFAULT;
    }
	ret = register_dp_panel_mgr(&g_panel_mgr, g_edp_info.port_id);
	if (ret) {
		edp_err("edp panel info register fail\n");
		return ret;
	}
	g_edp_info.power_status = EDP_POWER_NONE;
	g_edp_info.jank_last_bl_level = 0;
	edp_info("register edp panel-\n");
	return 0;
}

static int edp_syscore_suspend(void)
{
	struct edp_seq *pevent = g_edp_info.power_off;
	int i;
	int ret;

	if (!pevent) {
		edp_err("pevent is null\n");
		return -EINVAL;
	}

	if (g_edp_pm_suspend_state == PM_STATE_SUSPEND_DISK)
		return 0;
 
	for (i = 0; i < pevent->num; i++) {
		if (pevent->ctls[i].gpio_num > 0) {
			ret = gpio_request(pevent->ctls[i].gpio_num, NULL);
			if (ret) {
				edp_err("gpio request fail %d\n", ret);
				return -ret;
			}
			if (gpio_get_value(pevent->ctls[i].gpio_num) != pevent->ctls[i].value) {
				edp_info("edp sysore suspend power off gpio=%u, value=%u\n", pevent->ctls[i].gpio_num, pevent->ctls[i].value);
				gpio_set_value(pevent->ctls[i].gpio_num, pevent->ctls[i].value);
			}
			gpio_free(pevent->ctls[i].gpio_num);
		}
	}
 
	return 0;
}

static void edp_set_power_off_s4(void)
{
	int ret;
	ret = gpio_request(g_edp_info.s4_power_off_list.gpio_bkl, NULL);
	if (ret) {
		edp_err("gpio_bkl request fail %d\n", ret);
		return;
	}
	ret = gpio_request(g_edp_info.s4_power_off_list.gpio_vdd, NULL);
	if (ret) {
		gpio_free(g_edp_info.s4_power_off_list.gpio_bkl);
		edp_err("gpio_vdd request fail %d\n", ret);
		return;
	}
	edp_info("close gpio_bkl:%d gpio_vdd:%d", g_edp_info.s4_power_off_list.gpio_bkl,
		g_edp_info.s4_power_off_list.gpio_vdd);
	gpio_set_value(g_edp_info.s4_power_off_list.gpio_bkl, 0);
	gpio_set_value(g_edp_info.s4_power_off_list.gpio_vdd, 0);
	gpio_free(g_edp_info.s4_power_off_list.gpio_vdd);
	gpio_free(g_edp_info.s4_power_off_list.gpio_bkl);
}
 
static void edp_syscore_resume(void)
{
	struct edp_seq *pevent = g_edp_info.power_on;
	int lid_status = 0;
	int i;
	int ret;

	if (!pevent) {
		edp_err("pevent is null");
		return;
	}

	if (g_edp_pm_suspend_state == PM_STATE_SUSPEND_DISK) {
		if (g_edp_info.s4_power_off_list.support) {
			edp_set_power_off_s4();
		}
		return;
	}

    lid_status = get_lid_status();
	if (!lid_status) {
		edp_warn("lid is close, edp sysore resume don't power on\n");
	    return;
	}

#ifdef CONFIG_POWER_DUBAI
	int wakeup_gpio = dubai_get_wakeup_gpio();
	if (wakeup_gpio > 0) {
		for (i = 0; i < EARLY_POWER_ON_FILGER_MAX; i++) {
			if (wakeup_gpio == g_edp_info.early_power_on_gpio_filter[i]) {
				edp_info("edp early power on gpio_filter %d\n", wakeup_gpio);
				return;
			}
		}
	}
#endif

	for (i = 0; i < pevent->num; i++) {
		if (pevent->ctls[i].gpio_num > 0) {
			ret = gpio_request(pevent->ctls[i].gpio_num, NULL);
			if (ret) {
				edp_err("gpio request fail %d\n", ret);
				return;
			}
			if (gpio_get_value(pevent->ctls[i].gpio_num) != pevent->ctls[i].value) {
				edp_info("edp sysore resume power on gpio=%u, value=%u\n", pevent->ctls[i].gpio_num, pevent->ctls[i].value);
				gpio_set_value(pevent->ctls[i].gpio_num, pevent->ctls[i].value);
			}
			gpio_free(pevent->ctls[i].gpio_num);
		}
	}
}
 
static struct syscore_ops edp_syscore_ops = {
	.suspend = edp_syscore_suspend,
	.resume  = edp_syscore_resume,
};

static long edp_lcd_io_crtl(struct file *file, uint32_t cmd, unsigned long arg)
{
    int ret = 0;
    void __user *argp = (void __user *)(uintptr_t)arg;

    if (unlikely(!argp))
        return -EINVAL;
    switch (cmd) {
		case EDP_IOCTL_DISPLAY_ENGINE_PARAM_GET:
			ret = display_engine_get_param(argp);
			break;
        case EDP_IOCTL_DISPLAY_ENGINE_PARAM_SET:
            ret = display_engine_set_param(argp);
            break;
		default:
			edp_err("unknow cmd %u\n", cmd);
		    return -EINVAL;
	}
	return ret;
}

static enum hrtimer_restart reset_esd_delay_state(struct hrtimer *timer)
{
	edp_info("reset esd_delay_state");
	g_esd_delay_state = false;

	return HRTIMER_NORESTART;
}

static const struct file_operations edp_upater_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = &edp_lcd_io_crtl,
};

static struct miscdevice edp_panel_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "edp_panel",
    .fops = &edp_upater_fops,
};

static int edp_probe(struct platform_device *pdev)
{
    int32_t ret;

    edp_info("edp_probe+\n");
    ret = misc_register(&edp_panel_miscdev);
    if (ret != 0) {
        edp_err("[eDP]register miscdev failed, %d\n", ret);
        return ret;
    }

	ret = register_edp_panel(pdev->dev.of_node);
    if (ret < 0) {
        edp_err("register_edp_panel failed\n");
		goto err;
    }

	hrtimer_init(&g_esd_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	g_esd_hrtimer.function = reset_esd_delay_state;

	ret = edp_sysfs_init(&pdev->dev);
	if (ret < 0) {
		edp_err("edp_sysfs_init failed\n");
		goto err;
	}

	ret = edp_tp_safe_rate_ops_register(&g_edp_ops);
	if (ret < 0) {
		edp_err("edp_tp_safe_rate_ops_register failed\n");
		goto err;
	}

    ret = display_engine_init();
    if (ret != 0) {
        edp_err("display_engine_init failed\n");
		goto err;
    }

	if (g_edp_info.early_power_on_support)
		register_syscore_ops(&edp_syscore_ops);

	if (g_msr_ctrl.is_multi_screen_support == 1)
		edp_comp_msr_setup(&g_msr_ctrl);

	if (g_tcon_uart.support)
		tcon_uart_register(&g_tcon_uart);

	return 0;
err:
    misc_deregister(&edp_panel_miscdev);
	return ret;
}

static int32_t edp_remove(struct platform_device *pdev)
{
	int ret = 0;
	edp_info("edp_remove+\n");
	misc_deregister(&edp_panel_miscdev);
	ret = edp_tp_safe_rate_ops_unregister(&g_edp_ops);
	if (ret < 0) {
		edp_err("edp_tp_safe_rate_ops_unregister failed\n");
	}
	return 0;
}

static const struct of_device_id edp_device_match_table[] = {
	{
		.compatible = "huawei,edp_panel",
		.data = NULL,
	},
	{},
};
MODULE_DEVICE_TABLE(of, edp_device_match_table);

#ifdef CONFIG_PM
static int edp_pm_suspend(struct device *dev)
{
	g_edp_pm_suspend_state = PM_STATE_SUSPEND_MEM;
	return 0;
}

static int edp_pm_freeze(struct device *dev)
{
	g_edp_pm_suspend_state = PM_STATE_SUSPEND_DISK;
	return 0;
}
#endif

const struct dev_pm_ops edp_dev_pm_ops = {
#ifdef CONFIG_PM
    .suspend = edp_pm_suspend,
	.freeze = edp_pm_freeze,
#endif
};

static struct platform_driver edp_platform_driver = {
	.probe  = edp_probe,
	.remove = edp_remove,
	.driver = {
		.name  = "edp_panel",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(edp_device_match_table),
		.pm = &edp_dev_pm_ops,
	}
};

static int __init edp_register(void)
{
    edp_info("edp_register+\n");
	return platform_driver_register(&edp_platform_driver);
}

static void __exit edp_unregister(void)
{
	platform_driver_unregister(&edp_platform_driver);
}

module_init(edp_register);
module_exit(edp_unregister);

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");
