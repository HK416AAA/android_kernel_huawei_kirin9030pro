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
#include "edp_safe_fm_rate.h"

#include <linux/mutex.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/ktime.h>
#include <linux/delay.h>

#include <securec.h>
#include "edp_sysfs/edp_sysfs_common.h"
#include "edp_log.h"
#include "display_engine_interface.h"
#include "edp_drv/edp_panel_drv.h"
#include "edp_ts_kit/edp_ts_kit.h"

#define BIT(nr) ((1UL) << (nr))
#define DISPLAY_ENGINE_SAFE_FRAME_RATE  BIT(15)
#define PANEL_DP                        BIT(7) /* DisplayPort */
#define SFR_10_HZ 10
#define SFR_60_HZ 60
#define SFR_90_HZ 90
#define SFR_120_HZ 120
#define SFR_TP_RELEASE 0 /* invalid safe frame rate, not involved in decision */

/* tp safe frm rate tag with touch detected or release */
#define SAFE_FRAMERATE_TP_TOUCH_DETECTED_TAG 1
#define SAFE_FRAMERATE_TP_TOUCH_RELEASE_TAG 0
#define DEFAULT_TP_RELEASE_SAFE_FRM_DELAY_TIME 1000

struct safe_frm_rate_work {
	enum display_engine_panel_id handle_panel_id;
	struct kthread_work handle_work_detected;
	struct kthread_work handle_work_release;
	struct delayed_work tp_release_delay_work;
};

struct safe_frm_rate_work_info {
	const char *name;
	struct kthread_worker handle_worker;
	struct task_struct *handle_thread;
	struct safe_frm_rate_work handle_work[DISPLAY_ENGINE_PANEL_COUNT];
};

static struct safe_frm_rate_work_info g_sfr_work = {
	.name = "edp_safe_frame_rate_work_info",
	.handle_thread = NULL,
	.handle_work[DISPLAY_ENGINE_PANEL_INNER].handle_panel_id = DISPLAY_ENGINE_PANEL_INNER,
	.handle_work[DISPLAY_ENGINE_PANEL_OUTER].handle_panel_id = DISPLAY_ENGINE_PANEL_OUTER,
};

static struct mutex sfr_mutex;
static struct edp_tp_safe g_tp_sfr_info = {0};

/* tp safe frm rate touch detected handler */
static void tp_touch_detected_work_handler(struct kthread_work *work);
/* tp safe frm rate touch release handler */
static void safe_frm_rate_tp_release_work_handler(struct kthread_work *work);
/* tp safe frm rate touch release delay handler */
static void safe_frm_rate_tp_release_delay_work_handler(struct work_struct *work);

static unsigned int g_current_brightness_sfr_full = 60; /* full refresh mode sfr */
static unsigned int g_current_brightness_sfr_partial = 60; /* partial refresh mode sfr */
static unsigned int g_current_afr = 0;  /* current rs refresh rate */
static unsigned int g_last_final_sfr = 0; /* last sfr */
static unsigned int g_final_sfr = 0;  /* final sfr is used to send dkmd */
static unsigned int current_tp_sfr[DISPLAY_ENGINE_PANEL_COUNT] = {0}; /* current tp sfr array */

static bool g_is_sfr_use_afr = false; /* final sfr need use afr */
static bool g_force_send_sfr = false; /* need to send sfr even sfr doesn't change */
static bool g_is_sfr_init = false;
static bool is_wq_work_init[DISPLAY_ENGINE_PANEL_COUNT] = {0};
static bool is_workqueue_init = false;

static bool is_panel_id_invalid(int panel_id)
{
	if (panel_id <= DISPLAY_ENGINE_PANEL_INVALID ||	panel_id >= DISPLAY_ENGINE_PANEL_COUNT) {
		edp_err("edp_sfr panel id error %d\n", panel_id);
		return true;
	}
	return false;
}

static void safe_frm_rate_init_works(int panel_id, struct safe_frm_rate_work *sfr_work)
{
	if (!sfr_work) {
        edp_err("edp_sfr sfr_work is null\n");
        return;
    }
	if (g_tp_sfr_info.tp_support) {
		kthread_init_work(&(sfr_work->handle_work_detected), tp_touch_detected_work_handler);
		kthread_init_work(&(sfr_work->handle_work_release), safe_frm_rate_tp_release_work_handler);
		INIT_DELAYED_WORK(&(sfr_work->tp_release_delay_work), safe_frm_rate_tp_release_delay_work_handler);
		edp_info("edp_sfr tp sfr init work done\n");
	}
	return;
}

static void safe_frm_rate_init_workqueue_thread(struct safe_frm_rate_work_info *sfr_work)
{
	edp_info("edp_sfr workqueue thread init\n");
	if (!sfr_work) {
        edp_err("edp_sfr sfr_work is null\n");
        return;
    }
	if (is_workqueue_init) {
        edp_err("edp_sfr workqueue is not need init\n");
        return;
    }
	kthread_init_worker(&(sfr_work->handle_worker));
	sfr_work->handle_thread = kthread_create(kthread_worker_fn, &(sfr_work->handle_worker), sfr_work->name);
	if (!sfr_work->handle_thread) {
		edp_err("edp_sfr %s failed to create handle_thread!\n", sfr_work->name);
		return;
	}
	wake_up_process(sfr_work->handle_thread);
	is_workqueue_init = true;
	edp_info("edp_sfr workqueue thread init done\n");
	return;
}

void safe_frm_rate_work_info_workqueue_init(int panel_id)
{
    edp_info("edp_sfr workqueue init %d\n", panel_id);
    if (!g_is_sfr_init) {
        edp_info("edp_sfr is not init\n");
        return;
    }
    if (is_panel_id_invalid(panel_id)) {
        return;
    }
    if (!g_tp_sfr_info.tp_support) {
        edp_info("edp_sfr is not support tp sfr\n");
        return;
    }
    mutex_lock(&sfr_mutex);
    safe_frm_rate_init_workqueue_thread(&g_sfr_work);
    if (!is_wq_work_init[panel_id]) {
		safe_frm_rate_init_works(panel_id, &(g_sfr_work.handle_work[panel_id]));
		is_wq_work_init[panel_id] = true;
	}
    mutex_unlock(&sfr_mutex);
    edp_info("edp_sfr workqueue init done\n", panel_id);
}

/* update safe frm rate by brightness */
static void edp_upt_safe_frm_rate_by_brightness(unsigned int full_mode_sfr, unsigned int partial_mode_sfr)
{
    g_current_brightness_sfr_full = full_mode_sfr;
    g_current_brightness_sfr_partial = partial_mode_sfr;
}

/* get safe frame rate by afr */
static void edp_decision_final_sfr_by_afr(void)
{
    if (g_current_afr == 0 || g_current_brightness_sfr_full == 0) {
        edp_err("edp_sfr current_afr or sfr is illegal!\n");
        return;
    }

    /* 1.check whether the phase is common */
    if (g_current_afr % g_final_sfr != 0) {
        g_is_sfr_use_afr = true;
    }
    /* 2.sfr cannot exceed afr */
    if (g_final_sfr > g_current_afr) {
        g_is_sfr_use_afr = true;
    }

    if (g_is_sfr_use_afr) {
        g_final_sfr = g_current_afr;
        g_is_sfr_use_afr = false;
    }
    edp_debug("edp_sfr decision sfr by afr, cur_sfr[%d], afr[%d], final_sfr[%d]\n",
        g_current_brightness_sfr_full, g_current_afr, g_final_sfr);
}

/* get final safe frame rate */
static unsigned int get_final_safe_frm_rate(int panel_id)
{
    if (g_current_afr == 0) {
        edp_info("edp_sfr current_afr is not init!\n");
        return 0;
    }

    g_final_sfr = g_current_brightness_sfr_full;
    if (g_tp_sfr_info.tp_support) {
        g_final_sfr = (g_final_sfr > current_tp_sfr[panel_id]) ? g_final_sfr : current_tp_sfr[panel_id];
    }
    edp_decision_final_sfr_by_afr();
	edp_debug("edp_sfr:current_sfr_full[%u], final[%u]\n",
	    g_current_brightness_sfr_full, g_final_sfr);
	return g_final_sfr;
}

/* send final safe frm rate */
static int edp_send_safe_frm_rate(unsigned int safe_frm_rate, const struct sfr_info *info)
{
    uint32_t edp_port_id = get_edp_port_id();
    dkmd_dfr_send_safe_frm_rate(edp_port_id, PANEL_DP, safe_frm_rate, info);

    edp_info("edp_sfr:port_id[%d],safe_frm[%d], afr[%d]\n", edp_port_id, safe_frm_rate, g_current_afr);
	return EOK;
}

/* get final sfr and send */
static int edp_send_final_safe_frm_rate(int panel_id, const struct sfr_info *info)
{
	int ret;
	unsigned int final_safe_frm_rate;
	final_safe_frm_rate = get_final_safe_frm_rate(panel_id);
	if (!final_safe_frm_rate) {
		edp_err("final_safe_frm_rate[%d] not valid\n", final_safe_frm_rate);
		return -EINVAL;
	}
	if (final_safe_frm_rate == g_last_final_sfr && !g_force_send_sfr) {
		edp_debug("edp_sfr:[%u] doesn't change, no need to send\n", final_safe_frm_rate);
		return EOK;
	}
	g_force_send_sfr = false;
	g_last_final_sfr = final_safe_frm_rate;
	ret = edp_send_safe_frm_rate(final_safe_frm_rate, info);
	if (ret) {
		edp_err("edp_sfr send edp_sfr fail\n");
		return -EINVAL;
	}
	return ret;
}

/* update birghtness sfr and trigger send */
static int edp_brightness_trigger_send_sfr(int panel_id, unsigned int full_mode_sfr, unsigned int partial_mode_sfr)
{
    mutex_lock(&sfr_mutex);
    edp_upt_safe_frm_rate_by_brightness(full_mode_sfr, partial_mode_sfr);
    int ret = edp_send_final_safe_frm_rate(panel_id, NULL);
    mutex_unlock(&sfr_mutex);
    return ret;
}

static int display_engine_set_param_safe_frame_rate(int panel_id,
    uint32_t safe_frame_rate, uint32_t safe_partial_frame_rate)
{
    int ret = EOK;
    if (!edp_get_panel_on_state()) {
        edp_err("panel is power off\n");
        return -EINVAL;
    }
    edp_info("edp_sfr:%d safe partial frame:%d\n", safe_frame_rate, safe_partial_frame_rate);

    ret = edp_brightness_trigger_send_sfr(panel_id, safe_frame_rate, safe_partial_frame_rate);
    return ret;
}

int display_engine_set_safe_frame_rate(struct display_engine_param* de_param)
{
    if (!de_param) {
        edp_err("de_param is null!\n");
        return -EINVAL;
    }
    if (de_param->modules & DISPLAY_ENGINE_SAFE_FRAME_RATE) {
        if (display_engine_set_param_safe_frame_rate(de_param->panel_id,
			de_param->safe_frame_rate, de_param->safe_partial_frame_rate)) {
                edp_warn("display_engine_set_safeframe failed!\n");
                return -EINVAL;
            }
    }
    return EOK;
}

/* update safe frm rate info by dkmd */
static void edp_upt_current_sfr_info(const struct sfr_info *info)
{
    if (info->info_type & INFO_TYPE_AFR_SEND) {
		g_current_afr = info->afr;
	}
	if (info->info_type & INFO_TYPE_SFR_RESEND) {
        g_force_send_sfr = true;
    }
    edp_debug("edp_sfr info_type[%d], current_afr[%d], force_send_sfr[%d]\n",
        info->info_type, g_current_afr, g_force_send_sfr);
}

/* update safe frm rate by tp */
static void edp_upt_safe_frm_rate_by_tp(int panel_id, unsigned int safe_frm_rate)
{
	if (is_panel_id_invalid(panel_id)) {
        return;
    }
	current_tp_sfr[panel_id] = safe_frm_rate;
	edp_debug("edp_sfr current_tp_sfr %u\n", safe_frm_rate);
}

static void safe_frm_rate_tp_release_work_handler(struct kthread_work *work)
{
	if (!work) {
		edp_err("edp_sfr kthread work is null\n");
		return;
	}
	struct safe_frm_rate_work *sfr_work = container_of(work, struct safe_frm_rate_work, handle_work_release);
	if (!sfr_work) {
		edp_err("edp_sfr sfr_work is null\n");
		return;
	}
	int panel_id = sfr_work->handle_panel_id;
	cancel_delayed_work_sync(&(sfr_work->tp_release_delay_work));
	schedule_delayed_work(&(sfr_work->tp_release_delay_work),
        msecs_to_jiffies(g_tp_sfr_info.tp_release_sfr_delay_time));
}

static void tp_touch_detected_work_handler(struct kthread_work *work)
{
	int ret;
	int panel_id;

	if (!work) {
		edp_err("edp_sfr kthread work is null\n");
		return;
	}

	struct safe_frm_rate_work *sfr_work = container_of(work, struct safe_frm_rate_work, handle_work_detected);
	if (!sfr_work) {
		edp_err("edp_sfr safe sfr_work is null\n");
		return;
	}
	panel_id = sfr_work->handle_panel_id;
	cancel_delayed_work_sync(&(sfr_work->tp_release_delay_work));

	mutex_lock(&sfr_mutex);
	edp_upt_safe_frm_rate_by_tp(panel_id, g_tp_sfr_info.tp_safe_frame_rate);
	ret = edp_send_final_safe_frm_rate(panel_id, NULL);
	mutex_unlock(&sfr_mutex);

	if (ret) {
        edp_err("edp_sfr send safe frm rate fail\n");
    } else {
        edp_debug("edp_sfr send sfr success\n");
    }
}

static void safe_frm_rate_tp_release_delay_work_handler(struct work_struct *work)
{
    int ret;
    int panel_id;

    if (!work) {
        edp_err("edp_sfr work struct is null\n");
        return;
    }
    struct safe_frm_rate_work *sfr_work = container_of(work, struct safe_frm_rate_work, tp_release_delay_work.work);
    if (!sfr_work) {
        edp_err("edp_sfr work is null\n");
        return;
    }
    panel_id = sfr_work->handle_panel_id;
    if (!edp_get_panel_on_state()) {
        edp_err("edp_sfr power is off\n");
        return;
    }
    mutex_lock(&sfr_mutex);
    edp_upt_safe_frm_rate_by_tp(panel_id, SFR_TP_RELEASE);
    ret = edp_send_final_safe_frm_rate(panel_id, NULL);
    mutex_unlock(&sfr_mutex);

    if (ret) {
        edp_err("edp_sfr tp touch release send safe frm rate fail\n");
    } else {
        edp_debug("edp_sfr tp touch release send safe frm rate sucess\n");
    }
}

/* safe frame rate second decision, time delay is not allowed in this function */
int edp_safe_frame_rate_ctrl(const struct sfr_info *sfr_info)
{
    int ret;
    if (!sfr_info) {
        edp_err("edp_sfr sfr_info is null!\n");
        return -EINVAL;
    }
    if (!g_is_sfr_init) {
        edp_err("edp_sfr is not init!\n");
        return -EINVAL;
    }
    mutex_lock(&sfr_mutex);
	edp_upt_current_sfr_info(sfr_info);
	ret = edp_send_final_safe_frm_rate(DISPLAY_ENGINE_PANEL_INNER, sfr_info);
    mutex_unlock(&sfr_mutex);
	return ret;
}

static void edp_tp_sfr_info_init(void)
{
    g_tp_sfr_info.tp_safe_frame_rate = SFR_60_HZ;
    g_tp_sfr_info.tp_release_sfr_delay_time = DEFAULT_TP_RELEASE_SAFE_FRM_DELAY_TIME;
    if (get_edp_tp_support_mode(&g_tp_sfr_info) == 0) {
        edp_info("edp_sfr tp sfr is not support!\n");
    }
    edp_info("edp_sfr tp_support:%d, delay_time:%d, tp_sfr:%d\n",
        g_tp_sfr_info.tp_support, g_tp_sfr_info.tp_release_sfr_delay_time, g_tp_sfr_info.tp_safe_frame_rate);
}

int edp_safe_frame_rate_init(void)
{
    if (!g_is_sfr_init) {
        mutex_init(&sfr_mutex);
        g_is_sfr_init = true;
        edp_info("edp_sfr_init success\n");
    }
    edp_tp_sfr_info_init();
    safe_frm_rate_work_info_workqueue_init(DISPLAY_ENGINE_PANEL_INNER);
    return EOK;
}

void edp_tp_notify_de_event(int val, int panel_id)
{
	if (!g_tp_sfr_info.tp_support) {
        edp_debug("edp_sfr tp is not support, tp_notify_de invlaid\n");
        return;
    }
	if (is_panel_id_invalid(panel_id))
		return;
	if (!is_wq_work_init[panel_id] || !g_is_sfr_init) {
        edp_err("edp_sfr panle_id work is not init!\n");
        return;
    }
	if (val == SAFE_FRAMERATE_TP_TOUCH_DETECTED_TAG) {
        edp_debug("edp_sfr tp touch detected: %d\n", val);
        kthread_queue_work(&(g_sfr_work.handle_worker), &(g_sfr_work.handle_work[panel_id].handle_work_detected));
    } else if (val == SAFE_FRAMERATE_TP_TOUCH_RELEASE_TAG) {
        edp_debug("edp_sfr tp touch release: %d\n", val);
        kthread_queue_work(&(g_sfr_work.handle_worker), &(g_sfr_work.handle_work[panel_id].handle_work_release));
    }
}