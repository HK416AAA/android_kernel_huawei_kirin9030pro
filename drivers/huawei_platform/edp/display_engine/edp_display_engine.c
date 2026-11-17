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
#include <securec.h>
#include "edp_drv/edp_panel_drv.h"
#include "edp_sysfs/edp_sysfs_common.h"
#include "edp_log.h"
#include "display_engine_info.h"
#include "display_engine_interface.h"
#include "edp_safe_fm_rate.h"

static int display_engine_panel_info_get(struct display_engine_panel_info *info)
{
	int ret = 0;
    struct edp_edid_info edid_info;
    struct edp_drv_info* display_info;

	if (!info) {
		edp_err("NULL point: panel_info\n");
		return -EINVAL;
	}
    ret = parse_edp_info(&edid_info);
	if (ret) {
		edp_err("parse edp info failed %d\n", ret);
		return -EINVAL;
	}
	info->width = edid_info.xres;
	info->height = edid_info.yres;
	if (strcpy_s(info->panel_name, PANEL_NAME_LEN - 1, edid_info.hardwareid) != EOK) {
		edp_err("strncpy failed %d\n", ret);
		return -EINVAL;
	}
	if (strcpy_s(info->sn_code, SN_CODE_LEN_MAX - 1, edid_info.sncode) != EOK) {
		edp_err("strncpy failed %d\n", ret);
		return -EINVAL;
	}
    display_info = get_edp_drv_info();
    if (!display_info) {
        edp_err("get edp_drv_info return NULL\n");
		return -EINVAL;
    }
	if (!edid_info.sncode) {
        info->sn_code_length = 0;
	} else {
        info->sn_code_length = strlen(edid_info.sncode);
	}
	info->max_backlight = display_info->bl_max;
	info->min_backlight = display_info->bl_min;
	info->max_luminance = display_info->maxluminance;
	info->min_luminance = display_info->minluminance;
	info->is_part_update_support = display_info->is_part_update_support;
	info->oled_type = display_info->oled_type;
 
#ifdef LCD_FACTORY_MODE
 	info->is_factory = true;
#else
 	info->is_factory = false;
#endif
	edp_info("res(w=%u,h=%u) bl(min=%u,max=%u) lu_bl(min=%u,max=%u) name=%s sncode=%s oled_type=%d\n",
		info->width, info->height, info->min_backlight, info->max_backlight, info->min_luminance,
		info->max_luminance, info->panel_name, info->sn_code, info->oled_type);
	return 0;
}

int display_engine_get_param(void __user *argp)
{
	size_t size = sizeof(struct display_engine_param);
	struct display_engine_param de_param;
	int ret = 0;

	if (!argp) {
		edp_err("argp is nullptr\n");
		return -EINVAL;
	}
	ret = (int)copy_from_user(&de_param, argp, size);
	if (ret) {
		edp_err("copy_from_user failed, ret:%d!\n", ret);
		return -EINVAL;
	}
	if (de_param.modules) {
		if (display_engine_panel_info_get(&de_param.panel_info)) {
			edp_warn("display_engine_panel_info_get() failed!\n");
			return -EINVAL;
		}
		ret = (int)copy_to_user(argp, &de_param, size);
		if (ret) {
			edp_err("copy_to_user failed, ret:%d!\n", ret);
			return -EINVAL;
		}
	} else {
		edp_err("de_param.modules is nullptr\n");
		return -EINVAL;
	}

	return 0;
}

int display_engine_set_param(void __user *argp)
{
    size_t size = sizeof(struct display_engine_param);
    struct display_engine_param de_param;
    int ret = EOK;

    if (!argp) {
        edp_err("argp is nullptr\n");
        return -EINVAL;
    }
    ret = (int)copy_from_user(&de_param, argp, size);
    if (ret) {
        edp_err("copy_from_user failed, ret:%d!\n", ret);
        return -EINVAL;
    }
    if (display_engine_set_safe_frame_rate(&de_param)) {
        edp_warn("display_engine_set_safe_frame_rate() failed!\n");
        return -EINVAL;
    }
    
    return 0;
}

int display_engine_update_frame_rate(const struct sfr_info *sfr_info)
{
    if (sfr_info == NULL) {
		edp_err("sfr_info is NULL!\n");
		return -EINVAL;
	}
    return edp_safe_frame_rate_ctrl(sfr_info);
}

int display_engine_init(void)
{
    int ret = edp_safe_frame_rate_init();
    return ret;
}

void tp_notify_display_engine(int val, int panel_id)
{
    edp_debug("edp_sfr tp touch event val:%d panel id: %d\n", val, panel_id);
    edp_tp_notify_de_event(val, panel_id);
}