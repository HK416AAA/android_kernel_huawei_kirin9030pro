/*
 * hwcxext_mbhc.c
 *
 * hwcxext mbhc driver
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/property.h>
#include <linux/pm_wakeirq.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/workqueue.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/input/matrix_keypad.h>
#include <sound/jack.h>

#include "hwcxext_codec_info.h"
#include "hwcxext_mbhc.h"
#include "hwcxext_log.h"

#define HWLOG_TAG hwcxext_mbhc
HWLOG_REGIST();

#define IN_FUNCTION   hwlog_info("%s function comein\n", __func__)
#define OUT_FUNCTION  hwlog_info("%s function comeout\n", __func__)
#define JACK_REAR_IN_MASK (AUDIO_JACK_MIC | AUDIO_JACK_LINEIN)
#define JACK_REAR_MASK (AUDIO_JACK_MIC | AUDIO_JACK_LINEIN | AUDIO_JACK_LINEOUT)
#define HS_LONG_BTN_PRESS_LIMIT_TIME 6000
#define HS_REPORT_TABLE_SIZE 0x08
#define HS_BTN_QUICK_PRESS_LIMIT_CNT 0x5
#define HS_WAKEUP_EVENT_MSEC 1500
#define HS_DELAYED_WORK_TIME 20
#define HS_DELAYED_WORK_LONG 100
#define CHECK_PLUG_IN_TIMES 500

struct jack_key_to_type {
	enum snd_jack_types type;
	int key;
};

enum {
	MICB_DISABLE,
	MICB_ENABLE,
};

static int hwcxext_mbhc_cancel_long_btn_work(
	struct hwcxext_mbhc_priv *priv)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(priv)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		return -EINVAL;
	}
	/* it can not use cancel_delayed_work_sync, otherwise lead deadlock */
	int ret = cancel_delayed_work(&priv->long_press_btn_work);
	hwlog_info("%s: cancel long btn work,ret=%d\n", __func__, ret);
	return ret;
}

static unsigned int hwcxext_mbhc_check_headset_in(struct hwcxext_mbhc_priv *priv, int times)
{
	IN_FUNCTION;
	unsigned int type = AUDIO_JACK_NONE;
	if ((priv == NULL) || (priv->mbhc_cb == NULL)) {
		hwlog_err("%s: priv is null\n", __func__);
		return type;
	}
	if (priv->mbhc_cb->mbhc_check_headset_in) {
		type = priv->mbhc_cb->mbhc_check_headset_in(priv, times);
		hwlog_info("%s: check headset_in = %d\n", __func__, type);
	}
	return type;
}

static unsigned int hwcxext_mbhc_get_btn_type_recognize(struct hwcxext_mbhc_priv *priv)
{
	IN_FUNCTION;
	if ((priv == NULL) || (priv->mbhc_cb == NULL)) {
		hwlog_err("%s: priv is null\n", __func__);
		return 0;
	}
	if (priv->mbhc_cb->get_btn_type_recognize) {
		unsigned int mb_status = priv->mbhc_cb->get_btn_type_recognize(priv);
		hwlog_info("%s: mb_status 0x%04x\n", __func__, mb_status);
		return mb_status;
	}
	return 0;
}

static void hwcxext_mbhc_clear_irq(struct hwcxext_mbhc_priv *priv)
{
	IN_FUNCTION;
	if ((priv == NULL) || (priv->mbhc_cb == NULL)) {
		hwlog_err("%s: priv is null\n", __func__);
		return;
	}
	if (priv->mbhc_cb->clear_irq != NULL) {
		priv->mbhc_cb->clear_irq(priv);
	}
}

static void hwcxext_mbhc_micbias_control(struct hwcxext_mbhc_priv *priv, int req)
{
	int micbias_vote_cnt;

	if ((priv == NULL) || (priv->mbhc_cb == NULL) ||
		(priv->mbhc_cb->enable_micbias == NULL) || 
		(priv->mbhc_cb->disable_micbias == NULL)) {
		hwlog_err("%s: priv is null\n", __func__);
		return;
	}
	
	mutex_lock(&priv->micbias_vote_mutex);
	micbias_vote_cnt = atomic_read(&priv->micbias_vote_cnt);
	hwlog_info("%s: req:%s, micbias_vote_cnt:%d\n",
		__func__, req == MICB_ENABLE ? "micbias enable" :
		"micbias disable", micbias_vote_cnt);
	if (req == MICB_ENABLE) {
		if (micbias_vote_cnt)
			goto mbhc_micbias_control_exit;

		hwlog_info("%s: enable micbias", __func__);
		atomic_inc(&priv->micbias_vote_cnt);
		priv->mbhc_cb->enable_micbias(priv);
	} else {
		atomic_dec(&priv->micbias_vote_cnt);
		micbias_vote_cnt = atomic_read(&priv->micbias_vote_cnt);
		hwlog_info("%s: disable micbias micbias_vote_cnt:%d",
			__func__, micbias_vote_cnt);
		if (micbias_vote_cnt < 0)
			atomic_set(&priv->micbias_vote_cnt, 0);
		priv->mbhc_cb->disable_micbias(priv);
	}

mbhc_micbias_control_exit:
	hwlog_info("%s: out, micbias_vote_cnt:%d\n", __func__,
		atomic_read(&priv->micbias_vote_cnt));
	mutex_unlock(&priv->micbias_vote_mutex);
}

static void hwcxext_mbhc_snd_soc_jack_report_headset(
	struct hwcxext_mbhc_priv *mbhc_data, unsigned int type)
{
	int status = 0;
	bool report = true;
	IN_FUNCTION;
	switch (type) {
	case AUDIO_JACK_NONE:
		status = 0;
		hwlog_info("%s : front jack plug out\n", __func__);
		break;
	case AUDIO_JACK_HEADSET:
		status = SND_JACK_HEADPHONE | SND_JACK_MICROPHONE;
		hwlog_info("%s : 4-pole headset plug in\n", __func__);
		break;
	case AUDIO_JACK_HEADPHONE:
		status = SND_JACK_HEADPHONE;
		hwlog_info("%s : 3-pole headphone plug in\n", __func__);
		break;
	default:
		hwlog_err("%s : error hs status:%d\n", __func__, type);
		report = false;
		break;
	}
	if (report) {
		hwlog_info("%s : snd_soc_jack_report front jack = %d\n", __func__, status);
		snd_soc_jack_report(&mbhc_data->headset_jack, status, SND_JACK_HEADSET);
	}
	OUT_FUNCTION;
}

static void hwcxext_mbhc_snd_soc_jack_report_rear(
	struct hwcxext_mbhc_priv *mbhc_data, unsigned int type)
{
	int status = 0;
	IN_FUNCTION;
	if (type & AUDIO_JACK_LINEOUT) {
		hwlog_info("%s : lineout headphone plug in\n", __func__);
		status |= SND_JACK_HEADPHONE;
	}
	if (type & AUDIO_JACK_MIC) {
		hwlog_info("%s : mic plug in\n", __func__);
		status |= SND_JACK_MICROPHONE;
	}else if (type & AUDIO_JACK_LINEIN) {
		hwlog_info("%s : linein plug in\n", __func__);
		status |= SND_JACK_LINEIN;
	}
	hwlog_info("%s : snd_soc_jack_report rear jack = %d\n", __func__, status);
	snd_soc_jack_report(&mbhc_data->rear_jack, status,
			(SND_JACK_HEADPHONE | SND_JACK_MICROPHONE | SND_JACK_LINEIN));
	OUT_FUNCTION;
}

static void hwcxext_mbhc_snd_soc_jack_report_board(
	struct hwcxext_mbhc_priv *mbhc_data, bool type)
{
	IN_FUNCTION;
	int status = type ? SND_JACK_LINEOUT : 0;
	hwlog_info("%s : snd_soc_jack_report board jack = %d\n", __func__, status);
	snd_soc_jack_report(&mbhc_data->board_jack, status, SND_JACK_LINEOUT);
	OUT_FUNCTION;
}

static void hwcxext_mbhc_snd_soc_jack_report_btn(
	struct hwcxext_mbhc_priv *mbhc_data, int status)
{
	IN_FUNCTION;
	hwlog_info("%s : snd_soc_jack_report btn jack = %d\n", __func__, status);
	snd_soc_jack_report(&mbhc_data->headset_jack, status,
		(SND_JACK_BTN_0 | SND_JACK_BTN_1 | SND_JACK_BTN_2));
	OUT_FUNCTION;
}

static void hwcxext_mbhc_switch_set_state(struct switch_dev *sdev, int state)
{
#ifdef CONFIG_SWITCH
	switch_set_state(sdev, state);
#endif
}

static void hwcxext_mbhc_plug_out_detect(struct hwcxext_mbhc_priv *mbhc_data)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		return;
	}
	mutex_lock(&mbhc_data->plug_mutex);
	hwcxext_mbhc_micbias_control(mbhc_data, MICB_DISABLE);
	mutex_lock(&mbhc_data->status_mutex);
	if (mbhc_data->btn_report != 0) {
		hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, 0);
		mbhc_data->btn_report = 0;
	}
	hwcxext_mbhc_snd_soc_jack_report_headset(mbhc_data, AUDIO_JACK_NONE);
	if (mbhc_data->item_type) {
		hwcxext_mbhc_snd_soc_jack_report_board(mbhc_data, true);
	} else {
		hwcxext_mbhc_snd_soc_jack_report_rear(mbhc_data, AUDIO_JACK_NONE);
	}
	mutex_unlock(&mbhc_data->status_mutex);
	mbhc_data->hs_status = AUDIO_JACK_NONE;
	mutex_unlock(&mbhc_data->plug_mutex);
	hwcxext_mbhc_switch_set_state(&mbhc_data->sdev, AUDIO_JACK_NONE);
}

void hwcxext_mbhc_hs_jack_off(struct hwcxext_mbhc_priv *mbhc_data)
{
	IN_FUNCTION;
	hwcxext_mbhc_plug_out_detect(mbhc_data);
	return;
}

static void hwcxext_mbhc_plug_in_detect_headset(
	struct hwcxext_mbhc_priv *mbhc_data, unsigned int plug_in)
{
	IN_FUNCTION;
	if ((mbhc_data == NULL) || (mbhc_data->mbhc_cb == NULL)) {
		hwlog_err("%s: mbhc_data is null\n", __func__);
		return;
	}
	mutex_lock(&mbhc_data->plug_mutex);
	unsigned int plug = AUDIO_JACK_HEADSET;
	if (mbhc_data->mbhc_cb->set_hs_detect_restart != NULL){
		hwlog_info("%s: headset :plugin and need reapeat\n", __func__);
		mbhc_data->mbhc_cb->set_hs_detect_restart(mbhc_data);
	}

	if (mbhc_data->mbhc_cb->get_hs_type_recognize != NULL) {
		plug = mbhc_data->mbhc_cb->get_hs_type_recognize(mbhc_data);
		hwlog_info("%s: headset: get_hs_type = %d\n", __func__, plug);
	}
	if (plug == AUDIO_JACK_HEADSET) {
		hwcxext_mbhc_micbias_control(mbhc_data, MICB_ENABLE);
	}
	mutex_lock(&mbhc_data->status_mutex);
	if (mbhc_data->btn_report != 0) {
		hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, 0);
		mbhc_data->btn_report = 0;
	}
	hwcxext_mbhc_snd_soc_jack_report_headset(mbhc_data, plug);
	if (mbhc_data->item_type) {
		// 板载speaker不生效
		hwcxext_mbhc_snd_soc_jack_report_board(mbhc_data, false);
	} else {
		// 当plug为AUDIO_JACK_HEADPHONE时, 可以附带上报MIC或LINEIN
		plug |= ((plug == AUDIO_JACK_HEADPHONE) ? (plug_in & JACK_REAR_IN_MASK) : 0);
		hwcxext_mbhc_snd_soc_jack_report_rear(mbhc_data, (plug & JACK_REAR_IN_MASK));
	}
	mutex_unlock(&mbhc_data->status_mutex);
	mbhc_data->hs_status = plug;
	mutex_unlock(&mbhc_data->plug_mutex);
	hwcxext_mbhc_switch_set_state(&mbhc_data->sdev, plug);
}

static void hwcxext_mbhc_plug_in_detect_rear(
	struct hwcxext_mbhc_priv *mbhc_data, unsigned int plug)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		return;
	}
	mutex_lock(&mbhc_data->plug_mutex);
	if (mbhc_data->hs_status == AUDIO_JACK_HEADSET) {
		hwcxext_mbhc_micbias_control(mbhc_data, MICB_DISABLE);
	}
	mutex_lock(&mbhc_data->status_mutex);
	if (mbhc_data->btn_report != 0) {
		hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, 0);
		mbhc_data->btn_report = 0;
	}
	hwcxext_mbhc_snd_soc_jack_report_headset(mbhc_data, AUDIO_JACK_NONE);
	hwcxext_mbhc_snd_soc_jack_report_rear(mbhc_data, plug);
	mutex_unlock(&mbhc_data->status_mutex);
	mbhc_data->hs_status = plug;
	mutex_unlock(&mbhc_data->plug_mutex);
	hwcxext_mbhc_switch_set_state(&mbhc_data->sdev, plug);
}

static void hwcxext_mbhc_long_press_btn_work(struct work_struct *work)
{
	struct hwcxext_mbhc_priv *mbhc_data = container_of(work,
		struct hwcxext_mbhc_priv, long_press_btn_work.work);

	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is null\n", __func__);
		return;
	}

	__pm_stay_awake(mbhc_data->long_btn_wake_lock);
	IN_FUNCTION;
	if (!mbhc_data->btn_report) {
		hwlog_warn("%s: btn_report:%d is not right\n", __func__,
			mbhc_data->btn_report);
		goto long_press_btn_exit;
	}

	mutex_lock(&mbhc_data->btn_mutex);
	mutex_lock(&mbhc_data->status_mutex);
	mbhc_data->btn_report = 0;
	hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, 0);
	hwlog_info("%s: long_press_btn, report 0\n", __func__);
	mutex_unlock(&mbhc_data->status_mutex);
	mutex_unlock(&mbhc_data->btn_mutex);

long_press_btn_exit:
	__pm_relax(mbhc_data->long_btn_wake_lock);
	OUT_FUNCTION;
}

static void hwcxext_mbhc_long_press_btn_trigger(
	struct hwcxext_mbhc_priv *mbhc_data)
{
	queue_delayed_work(mbhc_data->long_press_btn_wq,
		&mbhc_data->long_press_btn_work,
		msecs_to_jiffies(HS_LONG_BTN_PRESS_LIMIT_TIME));
}

static void hwcxext_mbhc_btn_handle(struct hwcxext_mbhc_priv *mbhc_data,
	int report, int status)
{
	const int report_table[HS_REPORT_TABLE_SIZE] = {
		0, SND_JACK_BTN_0, SND_JACK_BTN_1, SND_JACK_BTN_0,
		SND_JACK_BTN_2, SND_JACK_BTN_0, SND_JACK_BTN_1, SND_JACK_BTN_0,
	};
	IN_FUNCTION;

	mutex_lock(&mbhc_data->status_mutex);
	hwlog_info("%s: report is = %d\n", __func__, report);
	mbhc_data->btn_report = report_table[report & (HS_REPORT_TABLE_SIZE - 1)];
	hwlog_info("%s: btn_report is = %d\n", __func__, mbhc_data->btn_report);

	int i = 1;
	int cnt = status >> HS_REPORT_TABLE_SIZE;
	cnt = (cnt >= HS_BTN_QUICK_PRESS_LIMIT_CNT) ? HS_BTN_QUICK_PRESS_LIMIT_CNT : cnt;
	if (status & BTN_PRESS) {
		hwlog_info("%s: btn is pressed\n", __func__);
		hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, mbhc_data->btn_report);
		do {
			hwlog_info("%s: btn is pressed %d count, report count:%d\n", __func__, cnt, i);
			hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, 0);
			hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, mbhc_data->btn_report);
		} while((i++ < cnt) && ((status & BTN_RELEASED) == 0));
	}
	if (status & BTN_RELEASED) {
		hwlog_info("%s: btn is release\n", __func__);
		hwcxext_mbhc_cancel_long_btn_work(mbhc_data);
		mbhc_data->btn_report = 0;
		hwcxext_mbhc_snd_soc_jack_report_btn(mbhc_data, 0);
	} else {
		hwcxext_mbhc_long_press_btn_trigger(mbhc_data);
	}
	mutex_unlock(&mbhc_data->status_mutex);
}

static void hwcxext_mbhc_btn_work(struct hwcxext_mbhc_priv *mbhc_data)
{
	IN_FUNCTION;
	if ((IS_ERR_OR_NULL(mbhc_data))  || (IS_ERR_OR_NULL(mbhc_data->mbhc_cb))) {
		hwlog_err("%s: mbhc_data is null\n", __func__);
		return;
	}
	mutex_lock(&mbhc_data->btn_mutex);
	unsigned int mb_status = hwcxext_mbhc_get_btn_type_recognize(mbhc_data);
	hwlog_info("%s: mb_status 0x%04x\n", __func__, mb_status);
	int status = (mb_status & (BTN_PRESS | BTN_RELEASED | BTN_PRESS_CNT));
	int report = (mb_status >> 0x02);
	hwcxext_mbhc_btn_handle(mbhc_data, report, status);
	mutex_unlock(&mbhc_data->btn_mutex);
	OUT_FUNCTION;
}

/* work of headset insertion and removal recognize */
static void hwcxext_mbhc_plug_work(struct hwcxext_mbhc_priv *mbhc_data, unsigned int plug_in)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		return;
	}
	hwcxext_mbhc_cancel_long_btn_work(mbhc_data);

	hwlog_info("%s: plug_status = %d \n", __func__, plug_in);
	if (plug_in == AUDIO_JACK_NONE) {
		hwlog_info("%s: the plug_work is :plugout\n", __func__);
		// plug out headset, disable micbias.
		hwcxext_mbhc_plug_out_detect(mbhc_data);
		return;
	}
	if ((plug_in & AUDIO_JACK_HEADSET) == AUDIO_JACK_HEADSET) {
		/* when front jack plug in, if lineout is on, need to do restart too. */
		hwlog_info("%s: the plug_work is :headset plugin\n", __func__);
		/* Jack inserted, determine type */
		hwcxext_mbhc_plug_in_detect_headset(mbhc_data, plug_in);
		return;
	}
	if (mbhc_data->item_type) {
		hwlog_err("%s:notebook pc shouldn't detect rear\n", __func__);
		return;
	}
	if ((plug_in & JACK_REAR_MASK) > 0) {
		hwlog_info("%s: the plug_work is :rear plugin = %d\n", __func__, plug_in);
		hwcxext_mbhc_plug_in_detect_rear(mbhc_data, plug_in);
		return;
	}
	hwlog_err("%s: plug_in is error\n", __func__);
}

/* work of the irq share with hs plugin or plugout and btn press & release */
static void hwcxext_mbhc_irq_plug_btn_work(struct work_struct *work)
{
	struct hwcxext_mbhc_priv *mbhc_data = container_of(work,
		struct hwcxext_mbhc_priv, irq_plug_btn_work.work);
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		goto hwcxext_mbhc_irq_plug_btn_work_exit;
	}
	__pm_wakeup_event(mbhc_data->plug_btn_wake_lock, HS_WAKEUP_EVENT_MSEC);
	mbhc_data->irq_thread_flag = false;
	hwcxext_mbhc_clear_irq(mbhc_data);
	unsigned int plug_in = hwcxext_mbhc_check_headset_in(mbhc_data, CHECK_PLUG_IN_TIMES);
	hwlog_info("%s: hs_status = %d, plug_in status = %d \n", __func__,
		mbhc_data->hs_status, plug_in);
	if (mbhc_data->irq_thread_flag) {
		hwlog_warn("%s: irq thread double conm in.\n", __func__);
		goto hwcxext_mbhc_irq_plug_btn_work_exit;
	}
	if (plug_in == AUDIO_JACK_WAIT) {
		if (mbhc_data->hs_status != AUDIO_JACK_WAIT) {
			mbhc_data->hs_status = AUDIO_JACK_WAIT;
			hwlog_info("%s: plug_in is WAIT.\n", __func__);
			goto hwcxext_mbhc_irq_plug_btn_work_exit;
		}
		plug_in = AUDIO_JACK_HEADSET;
		hwlog_warn("%s: plug_in is double WAIT.\n", __func__);
	}
	if ((mbhc_data->hs_status == AUDIO_JACK_HEADSET) &&
		((plug_in & AUDIO_JACK_HEADSET) == AUDIO_JACK_HEADSET)) {  /* btn irq */
		hwlog_info("%s: queue btn delay work btn\n", __func__);
		hwcxext_mbhc_btn_work(mbhc_data);
		goto hwcxext_mbhc_irq_plug_btn_work_exit;
	} 
	if ((plug_in == mbhc_data->hs_status) && (plug_in != AUDIO_JACK_NONE)) {
		hwlog_warn("%s: plug_in is same.\n", __func__);
	}
	/* it is plug in or out irq */
	hwlog_info("%s: queue hs plug work plug in or out\n", __func__);
	hwcxext_mbhc_plug_work(mbhc_data, plug_in);
hwcxext_mbhc_irq_plug_btn_work_exit:
	mbhc_data->irq_work_state = false;
}

static irqreturn_t hwcxext_mbhc_plug_btn_irq_thread(int irq, void *data)
{
	struct hwcxext_mbhc_priv *mbhc_data = data;
	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		return IRQ_HANDLED;
	}
	__pm_wakeup_event(mbhc_data->plug_btn_irq_wake_lock, HS_WAKEUP_EVENT_MSEC);
	mbhc_data->irq_thread_flag = true;
	hwlog_info("%s: enter, irq = %d\n", __func__, irq);
	unsigned int tim = HS_DELAYED_WORK_LONG;
	if (mbhc_data->irq_work_state == false) {
		tim = HS_DELAYED_WORK_TIME;
		mbhc_data->irq_work_state = true;
	}
	queue_delayed_work(mbhc_data->irq_plug_btn_wq,
		&mbhc_data->irq_plug_btn_work, msecs_to_jiffies(tim));
	return IRQ_HANDLED;
}

void hwcxext_mbhc_detect_init_state(struct hwcxext_mbhc_priv *mbhc_data)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		return;
	}
	hwcxext_mbhc_clear_irq(mbhc_data);
	mbhc_data->irq_work_state = true;
	mbhc_data->hs_status = AUDIO_JACK_NONE;
	queue_delayed_work(mbhc_data->irq_plug_btn_wq,
		&mbhc_data->irq_plug_btn_work, msecs_to_jiffies(HS_DELAYED_WORK_TIME));
	OUT_FUNCTION;
}

static struct snd_soc_jack_pin g_headset_jack_pins[] = {
	{
		.pin = "Headset Mic Jack",
		.mask = SND_JACK_MICROPHONE,
	},
	{
		.pin = "Headphone Jack",
		.mask = SND_JACK_HEADPHONE,
	},
};

static struct snd_soc_jack_pin g_rear_jack_pins[] = {
	{
		.pin = "Rear Mic Jack",
		.mask = SND_JACK_MICROPHONE,
	},
	{
		.pin = "Rear HeadPhone Jack",
		.mask = SND_JACK_HEADPHONE,
	},
	{
		.pin = "LineIn Jack",
		.mask = SND_JACK_LINEIN,
	},
};

static struct snd_soc_jack_pin g_board_jack_pins[] = {
	{
		.pin = "Speaker Jack",
		.mask = SND_JACK_LINEOUT,
	},
};

static int hwcxext_mbhc_register_hs_jack_btn(
	struct hwcxext_mbhc_priv *mbhc_data)
{
	int i;
	IN_FUNCTION;
	const struct jack_key_to_type key_type[] = {
		{ SND_JACK_BTN_0, KEY_PLAYPAUSE },
		{ SND_JACK_BTN_1, KEY_VOLUMEUP },
		{ SND_JACK_BTN_2, KEY_VOLUMEDOWN },
	};

	int ret = snd_soc_card_jack_new(mbhc_data->component->card, "Headset Jack",
		SND_JACK_HEADSET, &mbhc_data->headset_jack, g_headset_jack_pins,
		ARRAY_SIZE(g_headset_jack_pins));
	if (ret) {
		hwlog_err("%s: Failed to create new headset jack\n", __func__);
		return -ENOMEM;
	}

	if (mbhc_data->item_type) {
		ret = snd_soc_card_jack_new(mbhc_data->component->card, "Board Jack",
			(SND_JACK_HEADPHONE | SND_JACK_MICROPHONE),
			&mbhc_data->board_jack, g_board_jack_pins,
			ARRAY_SIZE(g_board_jack_pins));
		hwlog_info("%s:is notebook pc item, new board jack\n", __func__);
	} else {
		ret = snd_soc_card_jack_new(mbhc_data->component->card, "Rear Jack",
			(SND_JACK_HEADPHONE | SND_JACK_MICROPHONE | SND_JACK_LINEIN),
			&mbhc_data->rear_jack, g_rear_jack_pins,
			ARRAY_SIZE(g_rear_jack_pins));
		hwlog_info("%s:is desktop pc item, new rear jack\n", __func__);
	}
	if (ret) {
		hwlog_err("%s: Failed to create new board jack or rear jack\n", __func__);
		return -ENOMEM;
	}
	for (i = 0; i < ARRAY_SIZE(key_type); i++) {
		ret = snd_jack_set_key(mbhc_data->headset_jack.jack,
			key_type[i].type, key_type[i].key);
		if (ret) {
			hwlog_err("%s:set code for btn%d, error num: %d", __func__, i, ret);
			return -ENOMEM;
		}
	}
	return 0;
}

static int hwcxext_mbhc_get_plug_btn_irq_gpio(
	struct hwcxext_mbhc_priv *mbhc_data)
{
	int ret;
	const char *gpio_str = "plug_btn_irq_gpio";
	IN_FUNCTION;
	mbhc_data->plug_btn_irq_gpio = -1;
	mbhc_data->plug_btn_irq_gpio = of_get_named_gpio(mbhc_data->dev->of_node, gpio_str, 0);
	if (mbhc_data->plug_btn_irq_gpio < 0) {
		hwlog_debug("%s: get_named_gpio:%s failed, %d\n", __func__,
			gpio_str, mbhc_data->plug_btn_irq_gpio);
		ret = of_property_read_u32(mbhc_data->dev->of_node, gpio_str,
			(u32 *)&(mbhc_data->plug_btn_irq_gpio));
		if (ret < 0) {
			hwlog_err("%s: read plug_btn gpio irq failed=%d\n", __func__, ret);
			return -EFAULT;
		}
	}

	if (!gpio_is_valid(mbhc_data->plug_btn_irq_gpio)) {
		hwlog_err("%s: irq_handler gpio %d invalid\n", __func__,
			mbhc_data->plug_btn_irq_gpio);
		return -EFAULT;
	}

	ret = gpio_request(mbhc_data->plug_btn_irq_gpio, "hwcxext_plug_irq");
	if (ret < 0) {
		hwlog_err("%s: gpio_request ret %d invalid\n", __func__, ret);
		return -EFAULT;
	}
	ret = gpio_direction_input(mbhc_data->plug_btn_irq_gpio);
	if (ret >= 0) {
		return 0;
	}

	hwlog_err("%s set gpio input mode error:%d\n", __func__, ret);
	gpio_free(mbhc_data->plug_btn_irq_gpio);
	mbhc_data->plug_btn_irq_gpio = -EINVAL;
	return ret;
}

static int hwcxext_mbhc_request_plug_btn_detect_irq(
	struct hwcxext_mbhc_priv *mbhc_data)
{
	int ret;
	const char *irq_flags_str = "irq_flags";
	unsigned int irqf = 0;
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc_data)) {
		hwlog_err("%s: mbhc_data is error\n", __func__);
		return -EFAULT;
	}
	ret = hwcxext_mbhc_get_plug_btn_irq_gpio(mbhc_data);
	if (ret < 0) {
		hwlog_err("%s: btn_irq_gpio failed ret= %d\n", __func__, ret);
		return ret;
	}

	mbhc_data->plug_btn_irq =
		gpio_to_irq((unsigned int)(mbhc_data->plug_btn_irq_gpio));
	hwlog_info("%s detect_irq_gpio: %d, irq: %d\n", __func__,
		mbhc_data->plug_btn_irq_gpio, mbhc_data->plug_btn_irq);

	ret = of_property_read_u32(mbhc_data->dev->of_node, irq_flags_str, &irqf);
	if (ret < 0) {
		hwlog_err("%s: irq_handler get irq_flags failed\n", __func__);
		goto request_plug_irq_err;
	}
	hwlog_info("%s irqf: %d, ret = %d\n", __func__, irqf, ret);

	ret = request_threaded_irq(mbhc_data->plug_btn_irq, NULL,
		hwcxext_mbhc_plug_btn_irq_thread,
		irqf | IRQF_ONESHOT | IRQF_NO_SUSPEND,
		"hwcxext_mbhc_plug_detect", mbhc_data);
	if (ret) {
		hwlog_err("%s: Failed to request IRQ: %d\n", __func__, ret);
		goto request_plug_irq_err;
	}
	hwlog_info("%s request_threaded_irq ret = %d\n", __func__, ret);
	return 0;

request_plug_irq_err:
	gpio_free(mbhc_data->plug_btn_irq_gpio);
	mbhc_data->plug_btn_irq_gpio = -EINVAL;
	hwlog_err("%s:btn_detect_irq Failed \n", __func__);
	return -EFAULT;
}

static void hwcxext_mbhc_remove_workqueue(struct workqueue_struct **wq)
{
	if ((wq) && (*wq)) {
		flush_workqueue(*wq);
		destroy_workqueue(*wq);
		*wq = NULL;
	}
}

static int hwcxext_mbhc_create_singlethread_workqueue(
	struct workqueue_struct **wq, const char *name)
{
	struct workqueue_struct *req_wq = create_singlethread_workqueue(name);
	if (!req_wq) {
		hwlog_err("%s : create %s wq failed", __func__, name);
		return -ENOMEM;
	}
	*wq = req_wq;
	return 0;
}

static int hwcxext_mbhc_create_delay_work(struct hwcxext_mbhc_priv *mbhc_data)
{
	int ret;
	ret = hwcxext_mbhc_create_singlethread_workqueue(
		&(mbhc_data->irq_plug_btn_wq), "hwcxext_mbhc_plug_btn_wq");
	if (ret < 0) {
		hwlog_err("%s: create plug btn workqueue err,ret=%d\n", __func__, ret);
		return -ENOMEM;
	}
	INIT_DELAYED_WORK(&mbhc_data->irq_plug_btn_work,
		hwcxext_mbhc_irq_plug_btn_work);

	ret = hwcxext_mbhc_create_singlethread_workqueue(
		&(mbhc_data->long_press_btn_wq), "hwcxext_mbhc_long_press_btn_wq");
	if (ret < 0)
		goto hwcxext_mbhc_create_delay_work_exit;
	INIT_DELAYED_WORK(&mbhc_data->long_press_btn_work,
		hwcxext_mbhc_long_press_btn_work);
	return 0;

hwcxext_mbhc_create_delay_work_exit:
	hwlog_err("%s: create long press workqueue err,ret=%d\n", __func__, ret);
	ret = cancel_delayed_work(&mbhc_data->irq_plug_btn_work);
	hwlog_info("%s: cancel work,ret=%d\n", __func__, ret);
	hwcxext_mbhc_remove_workqueue(&mbhc_data->irq_plug_btn_wq);
	return -ENOMEM;
}

static void hwcxext_mbhc_free_plug_irq(
	struct hwcxext_mbhc_priv *mbhc_data)
{
	if (!gpio_is_valid(mbhc_data->plug_btn_irq_gpio))
		return;

	gpio_free(mbhc_data->plug_btn_irq_gpio);
	mbhc_data->plug_btn_irq_gpio = -EINVAL;
	free_irq(mbhc_data->plug_btn_irq, mbhc_data);
}

static void hwcxext_mbhc_destroy_delay_work(struct hwcxext_mbhc_priv *mbhc_data)
{
	cancel_delayed_work(&mbhc_data->irq_plug_btn_work);
	hwcxext_mbhc_remove_workqueue(&mbhc_data->irq_plug_btn_wq);

	cancel_delayed_work(&mbhc_data->long_press_btn_work);
	hwcxext_mbhc_remove_workqueue(&mbhc_data->long_press_btn_wq);
}

static int hwcxext_mbhc_register_switch_dev(
	struct hwcxext_mbhc_priv *mbhc_pri)
{
#ifdef CONFIG_SWITCH
	mbhc_pri->sdev.name = "h2w";
	int ret = switch_dev_register(&(mbhc_pri->sdev));
	if (ret < 0) {
		hwlog_err("%s: switch_dev_register failed: %d\n", __func__, ret);
		return ret;
	}
	hwlog_info("%s: switch_dev_register succ\n", __func__);
#endif
	return 0;
}

static int hwcxext_mbhc_resource_init(
	struct hwcxext_mbhc_priv *mbhc_pri)
{
	int ret;
	ret = hwcxext_mbhc_create_delay_work(mbhc_pri);
	if (ret < 0) {
		hwlog_err("%s: resource_init suss = %d\n", __func__, ret);
		return ret;
	}

	ret = hwcxext_mbhc_request_plug_btn_detect_irq(mbhc_pri);
	if (ret < 0) {
		hwlog_err("%s request plug detect irq failed\n", __func__);
		ret = -EINVAL;
		goto hwcxext_mbhc_resource_init_err1;
	}

	ret = hwcxext_mbhc_register_hs_jack_btn(mbhc_pri);
	if (ret < 0) {
		hwlog_err("%s register hs jack failed\n", __func__);
		goto hwcxext_mbhc_resource_init_err2;
	}

	ret = hwcxext_mbhc_register_switch_dev(mbhc_pri);
	if (ret < 0) {
		hwlog_err("%s hwcxext_mbhc_register_switch_dev failed\n", __func__);
		goto hwcxext_mbhc_resource_init_err2;
	}

	return 0;
hwcxext_mbhc_resource_init_err2:
	hwcxext_mbhc_free_plug_irq(mbhc_pri);
hwcxext_mbhc_resource_init_err1:
	hwcxext_mbhc_destroy_delay_work(mbhc_pri);
	hwlog_err("%s resource_init failed = %d\n", __func__, ret);
	return ret;
}

static void hwcxext_mbhc_variables_init(
	struct hwcxext_mbhc_priv *mbhc_data)
{
	atomic_set(&mbhc_data->micbias_vote_cnt, 0);
	struct hwcxext_codec_v1_priv *hwcxext_codec = NULL;
	hwcxext_codec = snd_soc_component_get_drvdata(mbhc_data->component);
	if (hwcxext_codec == NULL || hwcxext_codec->regmap_cfg == NULL) {
		hwlog_err("%s: hwcxext_codec is inavild\n", __func__);
		mbhc_data->item_type = 0;
	} else {
		mbhc_data->item_type = hwcxext_codec->regmap_cfg->item_type[0];
		hwlog_info("%s: item_type = %d\n", __func__, mbhc_data->item_type);
	}
}

static void hwcxext_mbhc_mutex_init(struct hwcxext_mbhc_priv *mbhc_data)
{
	mbhc_data->plug_btn_wake_lock = wakeup_source_register(NULL,
		"hwcxext-mbhc-plug-btn");
	mbhc_data->plug_btn_irq_wake_lock = wakeup_source_register(NULL,
		"hwcxext-mbhc-plug-btn_irq");
	mbhc_data->long_btn_wake_lock = wakeup_source_register(NULL,
		"hwcxext-mbhc-long-btn");

	mutex_init(&mbhc_data->plug_mutex);
	mutex_init(&mbhc_data->status_mutex);
	mutex_init(&mbhc_data->btn_mutex);
	mutex_init(&mbhc_data->micbias_vote_mutex);
}

static void hwcxext_mbhc_mutex_deinit(
	struct hwcxext_mbhc_priv *mbhc_data)
{
	wakeup_source_unregister(mbhc_data->plug_btn_wake_lock);
	wakeup_source_unregister(mbhc_data->plug_btn_irq_wake_lock);
	wakeup_source_unregister(mbhc_data->long_btn_wake_lock);

	mutex_destroy(&mbhc_data->plug_mutex);
	mutex_destroy(&mbhc_data->status_mutex);
	mutex_destroy(&mbhc_data->btn_mutex);
	mutex_destroy(&mbhc_data->micbias_vote_mutex);
}

int hwcxext_mbhc_init(struct device *dev,
	struct snd_soc_component *component,
	struct hwcxext_mbhc_priv **mbhc_data,
	struct hwcxext_mbhc_cb *mbhc_cb)
{
	struct hwcxext_mbhc_priv *mbhc_pri = NULL;
	IN_FUNCTION;
	if (dev == NULL || mbhc_cb == NULL || component == NULL || mbhc_data == NULL) {
		hwlog_err("%s: params is invalid\n", __func__);
		return -EINVAL;
	}

	mbhc_pri = devm_kzalloc(dev, sizeof(struct hwcxext_mbhc_priv), GFP_KERNEL);
	if (mbhc_pri == NULL) {
		hwlog_err("%s: kzalloc fail\n", __func__);
		return -ENOMEM;
	}
	mbhc_pri->mbhc_cb = mbhc_cb;
	mbhc_pri->component = component;
	mbhc_pri->dev = dev;
	*mbhc_data = mbhc_pri;

	hwcxext_mbhc_variables_init(mbhc_pri);
	hwcxext_mbhc_mutex_init(mbhc_pri);
	mbhc_pri->irq_work_state = false;
	if (hwcxext_mbhc_resource_init(mbhc_pri) != 0) {
		hwlog_err("%s: resource_init fail ret = %d\n", __func__);
		hwcxext_mbhc_mutex_deinit(mbhc_pri);
		devm_kfree(dev, mbhc_pri);
		return -EINVAL;
	}
	hwlog_info("%s: resource_init suss = %d\n", __func__);
	return 0;
}
EXPORT_SYMBOL_GPL(hwcxext_mbhc_init);

void hwcxext_mbhc_exit(struct device *dev,
	struct hwcxext_mbhc_priv *mbhc_data)
{
	IN_FUNCTION;
	if (dev == NULL || mbhc_data == NULL) {
		hwlog_err("%s: params is invalid\n", __func__);
		return;
	}
	hwcxext_mbhc_mutex_deinit(mbhc_data);

	hwcxext_mbhc_free_plug_irq(mbhc_data);
	hwcxext_mbhc_destroy_delay_work(mbhc_data);

#ifdef CONFIG_SWITCH
	switch_dev_unregister(&(mbhc_data->sdev));
#endif
	devm_kfree(dev, mbhc_data);
}
EXPORT_SYMBOL_GPL(hwcxext_mbhc_exit);

MODULE_DESCRIPTION("hwcxext mbhc");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_LICENSE("GPL v2");
