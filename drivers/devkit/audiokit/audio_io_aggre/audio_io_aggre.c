/*
 * audio_io_aggre.c
 *
 * audio_io_aggre driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
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

#include "audio_io_aggre.h"

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/of_device.h>
#include <linux/slab.h>
#include <huawei_platform/log/hw_log.h>
#include <securec.h>

#define HWLOG_TAG audio_io_aggre
HWLOG_REGIST();

static struct audio_io_aggre_priv *g_audio_io_aggre_priv = NULL;
static aggre_notifier_func g_aggre_notifier_func_list[AGGRE_NOTIFIER_END][AGGRE_DEVICE_END];

int audio_io_aggre_regist_event_callback(unsigned int type, unsigned int device, aggre_notifier_func func)
{
	if (type >= AGGRE_NOTIFIER_END) {
		hwlog_err("invalid type=%u\n", type);
		return -EINVAL;
	}

	if (device >= AGGRE_DEVICE_END) {
		hwlog_err("invalid device=%u\n", device);
		return -EINVAL;
	}

	if (!func) {
		hwlog_err("nb is null\n");
		return -EINVAL;
	}

	g_aggre_notifier_func_list[type][device] = func;

	return 0;
}

void audio_io_aggre_sts_inited_vote(void)
{
#ifdef CONFIG_CONTEXTHUB_IO_DIE_STS
	int ret = 0;

	if (!g_audio_io_aggre_priv) {
		hwlog_err("%s: g_audio_io_aggre_priv is null\n", __func__);
		return;
	}

	mutex_lock(&g_audio_io_aggre_priv->vote_lock);

	if (g_audio_io_aggre_priv->vote_cnt == 0) {
		mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
		return;
	}

	ret = sts_normal_request(STS_USER_AUDIO);
	if (ret == 0)
		g_audio_io_aggre_priv->is_voted = true;

	hwlog_info("%s: ret = %d, vote_cnt = %d, vote_status = %d\n", __func__, ret,
		g_audio_io_aggre_priv->vote_cnt, g_audio_io_aggre_priv->is_voted);
	mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
#endif
}

void audio_io_aggre_vote(void)
{
#ifdef CONFIG_CONTEXTHUB_IO_DIE_STS
	int ret = 0;
	sts_sys_status_enum sts_status;

	if (!g_audio_io_aggre_priv) {
		hwlog_err("%s: g_audio_io_aggre_priv is null\n", __func__);
		return;
	}

	mutex_lock(&g_audio_io_aggre_priv->vote_lock);

	g_audio_io_aggre_priv->vote_cnt++;

	if (g_audio_io_aggre_priv->is_voted) {
		mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
		return;
	}

	sts_status = sts_get_status();
	if (sts_status != STS_ST_INITED) {
		hwlog_err("%s: sts not inited %d\n", __func__, sts_status);
		mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
		return;
	}

	ret = sts_normal_request(STS_USER_AUDIO);
	if (ret == 0)
		g_audio_io_aggre_priv->is_voted = true;

	hwlog_info("%s: ret = %d, vote_cnt = %d, vote_status = %d\n", __func__, ret,
		g_audio_io_aggre_priv->vote_cnt, g_audio_io_aggre_priv->is_voted);
	mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
#endif
}

void audio_io_aggre_unvote(void)
{
#ifdef CONFIG_CONTEXTHUB_IO_DIE_STS
	int ret = 0;
	sts_sys_status_enum sts_status;

	if (!g_audio_io_aggre_priv) {
		hwlog_err("%s: g_audio_io_aggre_priv is null\n", __func__);
		return;
	}

	mutex_lock(&g_audio_io_aggre_priv->vote_lock);

	g_audio_io_aggre_priv->vote_cnt--;

	if (g_audio_io_aggre_priv->vote_cnt > 0) {
		hwlog_info("%s: exist audio device vote\n", __func__);
		mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
		return;
	}

	sts_status = sts_get_status();
	if (sts_status != STS_ST_INITED) {
		hwlog_err("%s: sts not inited status = %d\n", __func__, sts_status);
		mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
		return;
	}
	
	ret = sts_normal_release(STS_USER_AUDIO);
	if (ret == 0) 
		g_audio_io_aggre_priv->is_voted = false;

	hwlog_info("%s: ret = %d, vote_cnt = %d, vote state = %d\n", __func__, ret,
		g_audio_io_aggre_priv->vote_cnt, g_audio_io_aggre_priv->is_voted);
	mutex_unlock(&g_audio_io_aggre_priv->vote_lock);
#endif
}

static void io_aggre_work_func(struct work_struct *work)
{
	int dev_index;
	int notifier_type;

	if (!g_audio_io_aggre_priv)
		return;

	mutex_lock(&g_audio_io_aggre_priv->sts_status_lock);
	switch (g_audio_io_aggre_priv->sts_status) {
	case STS_ST_INITED:
		notifier_type = AGGRE_NOTIFIER_INITED;
		break;
	default:
		hwlog_err("%s: unkown sts status %d\n", __func__, g_audio_io_aggre_priv->sts_status);
		mutex_unlock(&g_audio_io_aggre_priv->sts_status_lock);
		return;
	}
	mutex_unlock(&g_audio_io_aggre_priv->sts_status_lock);

	for (dev_index = AGGRE_DEVICE_BEGIN; dev_index < AGGRE_DEVICE_END; dev_index++) {
		if (!g_aggre_notifier_func_list[notifier_type][dev_index])
			g_aggre_notifier_func_list[notifier_type][dev_index]();
	}
}

static void sts_aggre_callback(sts_sys_status_enum status, sts_err_info_t *info)
{
	unused(info);

	mutex_lock(&g_audio_io_aggre_priv->sts_status_lock);
	g_audio_io_aggre_priv->sts_status = status;
	mutex_unlock(&g_audio_io_aggre_priv->sts_status_lock);

	schedule_work(&g_audio_io_aggre_priv->aggre_work);
}

static int audio_io_aggre_probe(struct platform_device *pdev)
{
	unused(pdev);
	int ret;
	struct audio_io_aggre_priv *io_aggre_priv = NULL;

	io_aggre_priv = kzalloc(sizeof(struct audio_io_aggre_priv), GFP_KERNEL);
	if (!io_aggre_priv) {
		hwlog_err("%s: kzalloc fail\n", __func__);
		return -ENOMEM;
	}

	mutex_init(&io_aggre_priv->vote_lock);
	mutex_init(&io_aggre_priv->sts_status_lock);
	INIT_WORK(&io_aggre_priv->aggre_work, io_aggre_work_func);

	g_audio_io_aggre_priv = io_aggre_priv;

#ifdef CONFIG_CONTEXTHUB_IO_DIE_STS
	ret = sts_notify_register(STS_USER_AUDIO, sts_aggre_callback);
	if (ret != 0) {
		hwlog_err("%s: sts notify regist fail\n", __func__);
		goto err_out;
	}
#endif

	hwlog_info("%s: probe init success\n", __func__);
	return 0;

err_out:
	kfree(g_audio_io_aggre_priv);
	g_audio_io_aggre_priv = NULL;
	return ret;
}

static int audio_io_aggre_remove(struct platform_device *pdev)
{
	unused(pdev);

	kfree(g_audio_io_aggre_priv);
	g_audio_io_aggre_priv = NULL;

	return 0;
}

static const struct of_device_id audio_io_aggre_match[] = {
	{ .compatible = "huawei,audio_io_aggre", },
	{},
};
MODULE_DEVICE_TABLE(of, audio_io_aggre_match);

static struct platform_driver audio_io_aggre_driver = {
	.driver = {
		.name           = "audio_io_aggre",
		.owner          = THIS_MODULE,
		.of_match_table = of_match_ptr(audio_io_aggre_match),
	},
	.probe  = audio_io_aggre_probe,
	.remove = audio_io_aggre_remove,
};

static int __init audio_io_aggre_init(void)
{
	return platform_driver_register(&audio_io_aggre_driver);
}

static void __exit audio_io_aggre_exit(void)
{
	platform_driver_unregister(&audio_io_aggre_driver);
}

fs_initcall(audio_io_aggre_init);
module_exit(audio_io_aggre_exit);

MODULE_DESCRIPTION("audio io aggre driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_LICENSE("GPL v2");