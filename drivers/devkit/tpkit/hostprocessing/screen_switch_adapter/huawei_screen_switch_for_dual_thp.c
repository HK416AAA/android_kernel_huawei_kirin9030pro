/*
 * Huawei Touchscreen Driver
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "huawei_screen_switch_adapter.h"
#include "huawei_thp.h"

#if ((defined CONFIG_LCD_KIT_DRIVER) || (defined CONFIG_HW_EDP_DRIVER))
int screen_switch_to_fold_for_dual_thp(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	struct thp_core_data *cd_extra = thp_get_core_data(SUB_TOUCH_PANEL);
    struct screen_switch_adapter *mscreen_switch_adapter = get_screen_switch_adapter();

    thp_log_info("%s:called\n", __func__);
	cd->multi_screen_fold = true;
	cd_extra->multi_screen_fold = false;
	thp_power_control(cd_extra, TS_SCREEN_SWITCH, NO_SYNC_TIMEOUT);
	thp_call_back_event_switch(cd_extra);
	if (cd->suspended && cd_extra->suspended) {
		mscreen_switch_adapter->spec_ops->screenoff_fold();
		thp_log_info("%s: switch to SCREEN_FOLD\n", __func__);
		return NO_ERR;
	}
    mscreen_switch_adapter->spec_ops->screenon_fold();
	thp_log_info("%s: switch to SCREEN_FOLD\n", __func__);
    return NO_ERR;
}

int screen_switch_to_unfold_for_dual_thp(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	struct thp_core_data *cd_extra = thp_get_core_data(SUB_TOUCH_PANEL);
	struct screen_switch_adapter *mscreen_switch_adapter = get_screen_switch_adapter();

	thp_log_info("%s:called\n", __func__);
	cd->multi_screen_fold = false;
	cd_extra->multi_screen_fold = true;
	thp_power_control(cd_extra, TS_SCREEN_SWITCH, NO_SYNC_TIMEOUT);
	thp_call_back_event_switch(cd_extra);
	if (cd->suspended && cd_extra->suspended) {
		mscreen_switch_adapter->spec_ops->screenoff_unfold();
	}
	mscreen_switch_adapter->spec_ops->screenon_unfold();
    return NO_ERR;
}
#endif