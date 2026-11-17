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

#include "huawei_screen_switch_seq.h"
#include "huawei_thp.h"

#if ((defined CONFIG_LCD_KIT_DRIVER) || (defined CONFIG_HW_EDP_DRIVER))
#define PM_TYPE_LIST_LEN 5
static enum lcd_kit_ts_pm_type pm_type_list[PM_TYPE_LIST_LEN] = {
	TS_RESUME_DEVICE,
	TS_AFTER_RESUME,
	TS_EARLY_SUSPEND,
	TS_BEFORE_SUSPEND,
	TS_SUSPEND_DEVICE
};

/*
 * ATTENTION : This notation need maintain immedietaly when modified
 * ---------------------------------------------------------------------
 * DUAL THP screen switch spec sequence :
 * 1. SEQ0 : screenoff screen switch need tp suspend/resume process
 * ---------------------------------------------------------------------
 * THP_TSKIT screen switch spec seqence :
 * 1. SEQ1 : LCD screen switch seq follow small screen switch product
 * 2. SEQ2 : LCD screen switch seq follow big screen switch product
 * ---------------------------------------------------------------------
 */

/* seq0 means now used for dual thp */
/* --------------------------------------------------------------------- */

int thp_multi_screenon_fold_seq0(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	struct thp_core_data *cd_extra = thp_get_core_data(SUB_TOUCH_PANEL);

    thp_log_info("%s:called\n", __func__);
	thp_suspend_thread(cd->panel_id);
	thp_switch_shb_active_panel(SUB_TOUCH_PANEL);
	thp_resume_thread(cd_extra->panel_id);
    return NO_ERR;
}

int thp_multi_screenoff_fold_seq0(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	struct thp_core_data *cd_extra = thp_get_core_data(SUB_TOUCH_PANEL);
    bool aod_ready_tmp;

    aod_ready_tmp = cd->aod_window_ready_status;
    cd_extra->not_change_aod_ready_status = true;
    thp_log_info("%s: screen off fold\n", __func__);
    cd_extra->aod_notify_tp_power_status = cd->aod_notify_tp_power_status;
    cd->quickly_screen_on_off = true;
    cd_extra->quickly_screen_on_off = true;
    thp_multi_resume(cd->panel_id);
    thp_suspend_thread(cd->panel_id);
    thp_switch_shb_active_panel(SUB_TOUCH_PANEL);
    thp_resume_thread(cd_extra->panel_id);
    thp_suspend_thread(cd_extra->panel_id);
    cd_extra->aod_window_ready_status = aod_ready_tmp ?
        aod_ready_tmp : cd_extra->aod_window_ready_status;
    cd_extra->not_change_aod_ready_status = false;
    return NO_ERR;
}

int thp_multi_screenon_unfold_seq0(void)
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	struct thp_core_data *cd_extra = thp_get_core_data(SUB_TOUCH_PANEL);

    thp_suspend_thread(cd_extra->panel_id);
	thp_switch_shb_active_panel(MAIN_TOUCH_PANEL);
	thp_resume_thread(cd->panel_id);
	thp_log_info("%s: switch to SCREEN_UNFOLD\n", __func__);
    return NO_ERR;
}

int thp_multi_screenoff_unfold_seq0(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	struct thp_core_data *cd_extra = thp_get_core_data(SUB_TOUCH_PANEL);

    thp_log_info("%s: screen off unfold\n", __func__);
	thp_multi_resume(cd_extra->panel_id);
    wait_event_interruptible_timeout(cd->screen_waitq,
        (cd->screen_waitq_flag == WAITQ_WAKEUP),
        msecs_to_jiffies(200));
    return NO_ERR;
}
/* --------------------------------------------------------------------- */

/* seq1 means now used for small screen switch product(thp+tskit) */
/* --------------------------------------------------------------------- */
int thp_multi_screenon_fold_seq1(void)
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);

    thp_suspend_thread(cd->panel_id);
	tskit_multi_resume();
	thp_log_info("%s: switch to SCREEN_FOLD\n", __func__);
    return NO_ERR;
}

int thp_multi_screenoff_fold_seq1(void)
{
    thp_log_info("%s: screen off unfold\n", __func__);
#ifdef CONFIG_HUAWEI_TS_KIT_3_0
	ts_kit_screen_status_notify(QUICKLY_SCREEN_ON_OFF);
#endif
	tskit_multi_resume();
	msleep(200);
    return NO_ERR;
}

int thp_multi_screenon_unfold_seq1(void)
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);

	tskit_multi_suspend();
	thp_resume_thread(cd->panel_id);
	thp_log_info("%s: switch to SCREEN_UNFOLD\n", __func__);
    return NO_ERR;
}

int thp_multi_screenoff_unfold_seq1(void)
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);

    thp_log_info("%s: screen off fold\n", __func__);
    cd->quickly_screen_on_off = true;
    thp_multi_resume(cd->panel_id);
    msleep(200);
    return NO_ERR;
}
/* --------------------------------------------------------------------- */

/* seq1 means now used for big screen switch product(thp+tskit) */
/* --------------------------------------------------------------------- */
int thp_multi_screenon_fold_seq2(void)
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	int i;

#ifdef CONFIG_HUAWEI_TS_KIT_3_0
	/* before fold, nofity sub panel */
	ts_kit_screen_status_notify(SCREEN_FOLDED);
#endif
	if (cd->ts_suspended && cd->suspended) {
		cd->quickly_screen_on_off = true;
		thp_proc_screen_switch_cmd(TS_SCREEN_SWITCH,
			NO_SYNC_TIMEOUT, MAIN_TOUCH_PANEL);
		for (i = 0; i < PM_TYPE_LIST_LEN; i++) {
			if (pm_type_list[i] == TS_EARLY_SUSPEND)
				msleep(200); /* 200ms wait ic ready */

			thp_proc_screen_switch_cmd(pm_type_list[i],
				SHORT_SYNC_TIMEOUT, SUB_TOUCH_PANEL);
			thp_proc_screen_switch_cmd(pm_type_list[i],
				NO_SYNC_TIMEOUT, MAIN_TOUCH_PANEL);
		}
	}

	if (cd->ts_suspended && !cd->suspended)
		thp_proc_screen_switch_cmd(TS_SCREEN_SWITCH,
			NO_SYNC_TIMEOUT, MAIN_TOUCH_PANEL);
	/* finish fold, notify main panel and it will power off */
	cd->multi_screen_fold = true;
	thp_log_info("%s: switch to SCREEN_FOLDED\n", __func__);
    return NO_ERR;
}

int thp_multi_screenon_unfold_seq2(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	int i;

	/* before unfold, nofity main panel */
	cd->multi_screen_fold = false;
	thp_proc_screen_switch_cmd(TS_SCREEN_SWITCH,
		SHORT_SYNC_TIMEOUT, SUB_TOUCH_PANEL);
	if (cd->ts_suspended && cd->suspended) {
		for (i = 0; i < PM_TYPE_LIST_LEN; i++) {
			if (pm_type_list[i] == TS_EARLY_SUSPEND)
				msleep(200); /* 200ms wait ic ready */
			thp_proc_screen_switch_cmd(pm_type_list[i],
				SHORT_SYNC_TIMEOUT, SUB_TOUCH_PANEL);
		}
	}
#ifdef CONFIG_HUAWEI_TS_KIT_3_0
	/* finish unfold , notify sub panel and it will power off */
	ts_kit_screen_status_notify(SCREEN_UNFOLD);
#endif
	thp_log_info("%s: switch to SCREEN_UNFOLD\n", __func__);
    return NO_ERR;
}

int thp_multi_screenoff_fold_seq2(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	int i;

#ifdef CONFIG_HUAWEI_TS_KIT_3_0
	/* before fold, nofity sub panel */
	ts_kit_screen_status_notify(SCREEN_OFF_FOLD);
#endif
	cd->quickly_screen_on_off = true;
	thp_proc_screen_switch_cmd(TS_SCREEN_SWITCH,
		NO_SYNC_TIMEOUT, MAIN_TOUCH_PANEL);
	for (i = 0; i < PM_TYPE_LIST_LEN; i++) {
		if (pm_type_list[i] == TS_EARLY_SUSPEND)
			msleep(200); /* 200ms wait ic ready */

		thp_proc_screen_switch_cmd(pm_type_list[i],
			SHORT_SYNC_TIMEOUT, SUB_TOUCH_PANEL);
		thp_proc_screen_switch_cmd(pm_type_list[i],
			NO_SYNC_TIMEOUT, MAIN_TOUCH_PANEL);
	}
	cd->multi_screen_fold = true;
	thp_log_info("%s: switch to SCREEN_OFF_FOLD\n", __func__);
    return NO_ERR;
}

int thp_multi_screenoff_unfold_seq2(void)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	int i;

	/* before unfold, nofity main panel */
	cd->multi_screen_fold = false;
	thp_proc_screen_switch_cmd(TS_SCREEN_SWITCH,
		SHORT_SYNC_TIMEOUT, SUB_TOUCH_PANEL);
	if (cd->ts_suspended && cd->suspended) {
		for (i = 0; i < PM_TYPE_LIST_LEN; i++) {
			if (pm_type_list[i] == TS_EARLY_SUSPEND)
				msleep(200); /* 200ms wait ic ready */
			thp_proc_screen_switch_cmd(pm_type_list[i],
				SHORT_SYNC_TIMEOUT, SUB_TOUCH_PANEL);
		}
	}
#ifdef CONFIG_HUAWEI_TS_KIT_3_0
	/* finish unfold , notify sub panel and it will power off */
	ts_kit_screen_status_notify(SCREEN_UNFOLD);
#endif
	thp_log_info("%s: switch to SCREEN_UNFOLD\n", __func__);
    return NO_ERR;
}
#endif
/* --------------------------------------------------------------------- */