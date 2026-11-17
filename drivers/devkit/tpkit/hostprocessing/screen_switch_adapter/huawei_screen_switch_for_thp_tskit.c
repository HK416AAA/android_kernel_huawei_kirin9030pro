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

/*
 * 1. lcd_spec_seq0 : LCD scheme follow big fold product
 * 2. lcd_spec_seq1 : LCD scheme follow small fold product
 */

/* seq0 means lcd use screen switch scheme of big fold product */
#if ((defined CONFIG_LCD_KIT_DRIVER) || (defined CONFIG_HW_EDP_DRIVER))
static int thp_tskit_poweroff_screen_switch(u32 current_status)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);

    #ifdef CONFIG_HUAWEI_TS_KIT_3_0
        ts_kit_screen_status_notify(current_status);
    #endif
        if ((current_status == SCREEN_OFF_FOLD) ||
            (current_status == SCREEN_FOLDED))
            cd->multi_screen_fold = true;
        else if (current_status == SCREEN_UNFOLD)
            cd->multi_screen_fold = false;
        else
            thp_log_err("%s: invalid status: %u\n",
                __func__, current_status);
        thp_log_info("%s: power off mode, no need switch power status\n",
            __func__);
        return NO_ERR;
}

/* ------------------------------------------------------------ */
int thp_tskit_fold_for_lcd_spec_seq0()
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
    struct screen_switch_adapter *mscreen_switch_adapter = get_screen_switch_adapter();

    if ((cd->sleep_mode == TS_POWER_OFF_MODE) &&
		(cd->aod_touch_status == 0)) {
        thp_tskit_poweroff_screen_switch(SCREEN_FOLDED);
        return NO_ERR;
    }

    if(cd->ts_suspended && cd->suspended) {
        mscreen_switch_adapter->spec_ops->screenoff_fold();
        return NO_ERR;
    }

    mscreen_switch_adapter->spec_ops->screenon_fold();
    return NO_ERR;
}

int thp_tskit_unfold_for_lcd_spec_seq0()
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
    struct screen_switch_adapter *mscreen_switch_adapter = get_screen_switch_adapter();

    if ((cd->sleep_mode == TS_POWER_OFF_MODE) &&
		(cd->aod_touch_status == 0)) {
        thp_tskit_poweroff_screen_switch(SCREEN_UNFOLD);
        return NO_ERR;
    }

    if(cd->ts_suspended && cd->suspended) {
        mscreen_switch_adapter->spec_ops->screenoff_unfold();
        return NO_ERR;
    }
    mscreen_switch_adapter->spec_ops->screenon_unfold();
    return NO_ERR;
}
/* ------------------------------------------------------------ */

/* seq1 means lcd use screen switch scheme of small fold scheme */
/* ------------------------------------------------------------ */
int thp_tskit_fold_for_lcd_spec_seq1()
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
    struct screen_switch_adapter *mscreen_switch_adapter = get_screen_switch_adapter();

    thp_proc_screen_switch_cmd(TS_SCREEN_SWITCH,
        NO_SYNC_TIMEOUT, MAIN_TOUCH_PANEL);

    if (cd->ts_suspended && cd->suspended) {
        mscreen_switch_adapter->spec_ops->screenoff_fold();
        return NO_ERR;
    }
    mscreen_switch_adapter->spec_ops->screenon_fold();
    return NO_ERR;
}

int thp_tskit_unfold_for_lcd_spec_seq1()
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
    struct screen_switch_adapter *mscreen_switch_adapter = get_screen_switch_adapter();

    thp_proc_screen_switch_cmd(TS_SCREEN_SWITCH,
        SHORT_SYNC_TIMEOUT, SUB_TOUCH_PANEL);
    if (cd->ts_suspended && cd->suspended) {
        mscreen_switch_adapter->spec_ops->screenoff_unfold();
        return NO_ERR;
    }
    mscreen_switch_adapter->spec_ops->screenon_unfold();
    return NO_ERR;
}
/* ------------------------------------------------------------ */

int screen_switch_to_fold_for_thp_tskit(void)
{
    struct screen_switch_adapter *lcd_spec_adapter = get_screen_switch_adapter();

    lcd_spec_adapter->lcd_spec_ops->fold();
    return NO_ERR; 
}

int screen_switch_to_unfold_for_thp_tskit(void)
{
    struct screen_switch_adapter *lcd_spec_adapter = get_screen_switch_adapter();

    lcd_spec_adapter->lcd_spec_ops->unfold();
    return NO_ERR; 
}
#endif